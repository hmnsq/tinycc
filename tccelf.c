/*
 *  ELF file handling for TCC
 *
 *  Copyright (c) 2001-2004 Fabrice Bellard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#अन्तर्भाव "tcc.h"

/* Define this to get some debug output during relocation processing.  */
#अपरिभाषय DEBUG_RELOC

/********************************************************/
/* global variables */

/* elf version information */
संरचना sym_संस्करणम् {
    वर्ण *lib;
    वर्ण *संस्करणम्;
    पूर्णाङ्क बहिर्गमनम्_सूचकांक;
    पूर्णाङ्क पूर्व_same_lib;
};

#परिभाषय nb_sym_versions     s1->nb_sym_versions
#परिभाषय sym_versions        s1->sym_versions
#परिभाषय nb_sym_गन्तव्यम्_संस्करणम्   s1->nb_sym_गन्तव्यम्_संस्करणम्
#परिभाषय sym_गन्तव्यम्_संस्करणम्      s1->sym_गन्तव्यम्_संस्करणम्
#परिभाषय dt_verneednum       s1->dt_verneednum
#परिभाषय versym_section      s1->versym_section
#परिभाषय verneed_section     s1->verneed_section

/* special flag to indicate that the section should not be linked to the other ones */
#परिभाषय SHF_वैयक्तिकम् 0x80000000
/* section is dynsymtab_section */
#परिभाषय SHF_DYNSYM 0x40000000

#यदि_परिभाषितम् TCC_TARGET_PE
#परिभाषय shf_RELRO SHF_ALLOC
स्थिर ध्रुव वर्ण rdata[] = ".rdata";
#अन्यथा
#परिभाषय shf_RELRO SHF_ALLOC /* eventually made SHF_WRITE in sort_sections() */
स्थिर ध्रुव वर्ण rdata[] = ".data.ro";
#यदि_अन्तः

/* ------------------------------------------------------------------------- */

ST_FUNC शून्य tccelf_new(TCCState *s)
{
    TCCState *s1 = s;

    /* no section zero */
    dynarray_सङ्कलय(&s->sections, &s->nb_sections, रिक्त);

    /* create standard sections */
    text_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    दत्त_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    /* create ro data section (make ro after relocation done with GNU_RELRO) */
    rodata_section = new_section(s, rdata, SHT_PROGBITS, shf_RELRO);
    bss_section = new_section(s, ".bss", SHT_NOBITS, SHF_ALLOC | SHF_WRITE);
    common_section = new_section(s, ".common", SHT_NOBITS, SHF_वैयक्तिकम्);
    common_section->sh_अङ्कः = SHN_COMMON;

    /* symbols are always generated for linking stage */
    symtab_section = new_symtab(s, ".symtab", SHT_SYMTAB, 0,
                                ".strtab",
                                ".hashtab", SHF_वैयक्तिकम्);

    /* private symbol table for dynamic symbols */
    s->dynsymtab_section = new_symtab(s, ".dynsymtab", SHT_SYMTAB, SHF_वैयक्तिकम्|SHF_DYNSYM,
                                      ".dynstrtab",
                                      ".dynhashtab", SHF_वैयक्तिकम्);
    get_sym_attr(s, 0, 1);

    यदि (s->do_debug) {
        /* add debug sections */
        tcc_debug_new(s);
    }

#यदि TCC_EH_FRAME
    यदि (s->output_format != TCC_OUTPUT_FORMAT_ELF)
        s->unwind_tables = 0;
    tcc_eh_frame_start(s);
#यदि_अन्तः

#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    यदि (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        /* (make ro after relocation done with GNU_RELRO) */
        bounds_section = new_section(s, ".bounds", SHT_PROGBITS, shf_RELRO);
        lbounds_section = new_section(s, ".lbounds", SHT_PROGBITS, shf_RELRO);
    }
#यदि_अन्तः

#यदि_परिभाषितम् TCC_TARGET_PE
    /* to make sure that -ltcc1 -Wl,-e,_start will grab the startup code
       from libtcc1.a (unless _start defined) */
    यदि (s->elf_entryname)
        समुच्चयः_global_sym(s, s->elf_entryname, रिक्त, 0); /* SHN_UNDEF */
#यदि_अन्तः

#यदि_अपरिभाषितम् ELF_OBJ_ONLY
    यदि (रिक्त == s->elfint && s1->output_type != TCC_OUTPUT_OBJ) {
        ध्रुव वर्ण *p = CONFIG_TCC_ELFINTERP;
#यदि defined TCC_TARGET_ARM && defined CONFIG_TCC_ELFINTERP_ARMHF
        यदि (s->float_abi == ARM_HARD_FLOAT)
            p = CONFIG_TCC_ELFINTERP_ARMHF;
#यदि_अन्तः
#यदि defined TCC_IS_NATIVE && defined TARGETOS_BSD
        /* see commit 55cb2170cd5ce77a7d76dcaf462fad2707281605 */
        { ध्रुव वर्ण *e = getenv("LD_SO"); यदि (e) p = e; }
#यदि_अन्तः
        s->elfint = tcc_strdup(p);
    }
#यदि_अन्तः /* ndef ELF_OBJ_ONLY */
}

ST_FUNC शून्य free_section(Section *s)
{
    यदि (!s)
        प्रत्यागम;
    tcc_free(s->दत्त);
    s->दत्त = रिक्त;
    s->दत्त_allocated = s->दत्त_विस्थापनम् = 0;
}

ST_FUNC शून्य tccelf_delete(TCCState *s1)
{
    पूर्णाङ्क i;

#यदि_अपरिभाषितम् ELF_OBJ_ONLY
    /* free symbol versions */
    प्रति (i = 0; i < nb_sym_versions; i++) {
        tcc_free(sym_versions[i].संस्करणम्);
        tcc_free(sym_versions[i].lib);
    }
    tcc_free(sym_versions);
    tcc_free(sym_गन्तव्यम्_संस्करणम्);
#यदि_अन्तः

    /* free all sections */
    प्रति(i = 1; i < s1->nb_sections; i++)
        free_section(s1->sections[i]);
    dynarray_reset(&s1->sections, &s1->nb_sections);

    प्रति(i = 0; i < s1->nb_priv_sections; i++)
        free_section(s1->priv_sections[i]);
    dynarray_reset(&s1->priv_sections, &s1->nb_priv_sections);

    tcc_free(s1->sym_attrs);
    symtab_section = रिक्त; /* for tccrun.c:rt_printline() */
}

/* save section data state */
ST_FUNC शून्य tccelf_begin_file(TCCState *s1)
{
    Section *s; पूर्णाङ्क i;
    प्रति (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        s->sh_विस्थापनम् = s->दत्त_विस्थापनम्;
    }
    /* disable symbol hashing during compilation */
    s = s1->symtab, s->reloc = s->hash, s->hash = रिक्त;
#यदि defined TCC_TARGET_X86_64 && defined TCC_TARGET_PE
    s1->uw_sym = 0;
    s1->uw_offs = 0;
#यदि_अन्तः
}

स्थिर शून्य update_relocs(TCCState *s1, Section *s, पूर्णाङ्क *old_गन्तव्यम्_new_syms, पूर्णाङ्क first_sym);

/* At the end of compilation, convert any UNDEF syms to global, and merge
   with previously existing symbols */
ST_FUNC शून्य tccelf_अन्तः_file(TCCState *s1)
{
    Section *s = s1->symtab;
    पूर्णाङ्क first_sym, nb_syms, *tr, i;

    first_sym = s->sh_विस्थापनम् / परिमाण (ElfSym);
    nb_syms = s->दत्त_विस्थापनम् / परिमाण (ElfSym) - first_sym;
    s->दत्त_विस्थापनम् = s->sh_विस्थापनम्;
    s->link->दत्त_विस्थापनम् = s->link->sh_विस्थापनम्;
    s->hash = s->reloc, s->reloc = रिक्त;
    tr = tcc_mallocz(nb_syms * परिमाण *tr);

    प्रति (i = 0; i < nb_syms; ++i) {
        ElfSym *sym = (ElfSym*)s->दत्त + first_sym + i;
        यदि (sym->st_shndx == SHN_UNDEF) {
            पूर्णाङ्क sym_bind = ELFW(ST_BIND)(sym->st_info);
            पूर्णाङ्क sym_type = ELFW(ST_TYPE)(sym->st_info);
            यदि (sym_bind == STB_LOCAL)
                sym_bind = STB_GLOBAL;
#यदि_अपरिभाषितम् TCC_TARGET_PE
            यदि (sym_bind == STB_GLOBAL && s1->output_type == TCC_OUTPUT_OBJ) {
                /* undefined symbols with STT_FUNC are confusing gnu ld when
                   linking statically to STT_GNU_IFUNC.  Keep TLS typed,
                   otherwise gnu ld rejects non-TLS refs to TLS definitions. */
                यदि (sym_type != STT_TLS)
                    sym_type = STT_NOTYPE;
            }
#यदि_अन्तः
            sym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
        }
        tr[i] = समुच्चयः_elf_sym(s, sym->st_मानम्, sym->st_आकार, sym->st_info,
            sym->st_other, sym->st_shndx, (वर्ण*)s->link->दत्त + sym->st_name);
    }
    /* now update relocations */
    update_relocs(s1, s, tr, first_sym);
    tcc_free(tr);
    /* record text/data/bss output for -bench info */
    प्रति (i = 0; i < 4; ++i) {
        s = s1->sections[i + 1];
        s1->योग_output[i] += s->दत्त_विस्थापनम् - s->sh_विस्थापनम्;
    }
}

ST_FUNC Section *new_section(TCCState *s1, ध्रुव वर्ण *name, पूर्णाङ्क sh_type, पूर्णाङ्क sh_flags)
{
    Section *sec;

    sec = tcc_mallocz(परिमाण(Section) + वाक्यदैर्घ्यम्(name));
    sec->s1 = s1;
    वाक्यं_प्रतिलिख(sec->name, name);
    sec->sh_type = sh_type;
    sec->sh_flags = sh_flags;
    विकल्प(sh_type) {
    पक्ष SHT_GNU_versym:
        sec->sh_addralign = 2;
        भङ्ग;
    पक्ष SHT_HASH:
    पक्ष SHT_GNU_HASH:
    पक्ष SHT_REL:
    पक्ष SHT_RELA:
    पक्ष SHT_DYNSYM:
    पक्ष SHT_SYMTAB:
    पक्ष SHT_DYNAMIC:
    पक्ष SHT_GNU_verneed:
    पक्ष SHT_GNU_verdef:
        sec->sh_addralign = PTR_आकार;
        भङ्ग;
    पक्ष SHT_STRTAB:
        sec->sh_addralign = 1;
        भङ्ग;
    स्वभाव:
        sec->sh_addralign =  PTR_आकार; /* gcc/pcc default alignment */
        भङ्ग;
    }

    यदि (sh_flags & SHF_वैयक्तिकम्) {
        dynarray_सङ्कलय(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } अन्यथा {
        sec->sh_अङ्कः = s1->nb_sections;
        dynarray_सङ्कलय(&s1->sections, &s1->nb_sections, sec);
    }

    प्रत्यागम sec;
}

ST_FUNC शून्य init_symtab(Section *s)
{
    पूर्णाङ्क *ptr, nb_buckets = 1;
    put_elf_str(s->link, "");
    section_ptr_सङ्कलय(s, परिमाण (ElfW(Sym)));
    ptr = section_ptr_सङ्कलय(s->hash, (2 + nb_buckets + 1) * परिमाण(पूर्णाङ्क));
    ptr[0] = nb_buckets;
    ptr[1] = 1;
    स्मृतिं_पूरय(ptr + 2, 0, (nb_buckets + 1) * परिमाण(पूर्णाङ्क));
}

ST_FUNC Section *new_symtab(TCCState *s1,
                           ध्रुव वर्ण *symtab_name, पूर्णाङ्क sh_type, पूर्णाङ्क sh_flags,
                           ध्रुव वर्ण *strtab_name,
                           ध्रुव वर्ण *hash_name, पूर्णाङ्क hash_sh_flags)
{
    Section *symtab, *strtab, *hash;
    symtab = new_section(s1, symtab_name, sh_type, sh_flags);
    symtab->sh_entsize = परिमाण(ElfW(Sym));
    strtab = new_section(s1, strtab_name, SHT_STRTAB, sh_flags);
    symtab->link = strtab;
    hash = new_section(s1, hash_name, SHT_HASH, hash_sh_flags);
    hash->sh_entsize = परिमाण(पूर्णाङ्क);
    symtab->hash = hash;
    hash->link = symtab;
    init_symtab(symtab);
    प्रत्यागम symtab;
}

/* realloc section and set its content to zero */
ST_FUNC शून्य section_realloc(Section *sec, अचिह्नित दीर्घ new_आकार)
{
    अचिह्नित दीर्घ आकार;
    अचिह्नित वर्ण *दत्त;

    आकार = sec->दत्त_allocated;
    यदि (आकार == 0)
        आकार = 1;
    यावत् (आकार < new_आकार)
        आकार = आकार * 2;
    दत्त = tcc_realloc(sec->दत्त, आकार);
    स्मृतिं_पूरय(दत्त + sec->दत्त_allocated, 0, आकार - sec->दत्त_allocated);
    sec->दत्त = दत्त;
    sec->दत्त_allocated = आकार;
}

/* reserve at least 'size' bytes aligned per 'align' in section
   'sec' from current offset, and return the aligned offset */
ST_FUNC आकार_t section_सङ्कलय(Section *sec, addr_t आकार, पूर्णाङ्क align)
{
    आकार_t विस्थापनम्, offset1;

    विस्थापनम् = (sec->दत्त_विस्थापनम् + align - 1) & -align;
    offset1 = विस्थापनम् + आकार;
    यदि (sec->sh_type != SHT_NOBITS && offset1 > sec->दत्त_allocated)
        section_realloc(sec, offset1);
    sec->दत्त_विस्थापनम् = offset1;
    यदि (align > sec->sh_addralign)
        sec->sh_addralign = align;
    प्रत्यागम विस्थापनम्;
}

/* reserve at least 'size' bytes in section 'sec' from
   sec->data_offset. */
ST_FUNC शून्य *section_ptr_सङ्कलय(Section *sec, addr_t आकार)
{
    आकार_t विस्थापनम् = section_सङ्कलय(sec, आकार, 1);
    प्रत्यागम sec->दत्त + विस्थापनम्;
}

#यदि_अपरिभाषितम् ELF_OBJ_ONLY
/* reserve at least 'size' bytes from section start */
स्थिर शून्य section_reserve(Section *sec, अचिह्नित दीर्घ आकार)
{
    यदि (आकार > sec->दत्त_allocated)
        section_realloc(sec, आकार);
    यदि (आकार > sec->दत्त_विस्थापनम्)
        sec->दत्त_विस्थापनम् = आकार;
}
#यदि_अन्तः

स्थिर Section *have_section(TCCState *s1, ध्रुव वर्ण *name)
{
    Section *sec;
    पूर्णाङ्क i;
    प्रति(i = 1; i < s1->nb_sections; i++) {
        sec = s1->sections[i];
        यदि (!वाक्यं_तुलय(name, sec->name))
            प्रत्यागम sec;
    }
    प्रत्यागम रिक्त;
}

/* return a reference to a section, and create it if it does not
   exists */
ST_FUNC Section *find_section(TCCState *s1, ध्रुव वर्ण *name)
{
    Section *sec = have_section(s1, name);
    यदि (sec)
        प्रत्यागम sec;
    /* sections are created as PROGBITS */
    प्रत्यागम new_section(s1, name, SHT_PROGBITS, SHF_ALLOC);
}

/* ------------------------------------------------------------------------- */

ST_FUNC पूर्णाङ्क put_elf_str(Section *s, ध्रुव वर्ण *sym)
{
    पूर्णाङ्क विस्थापनम्, len;
    वर्ण *ptr;

    len = वाक्यदैर्घ्यम्(sym) + 1;
    विस्थापनम् = s->दत्त_विस्थापनम्;
    ptr = section_ptr_सङ्कलय(s, len);
    memmove(ptr, sym, len);
    प्रत्यागम विस्थापनम्;
}

/* elf symbol hashing function */
स्थिर ElfW(Word) elf_hash(ध्रुव अचिह्नित वर्ण *name)
{
    ElfW(Word) h = 0, g;

    यावत् (*name) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        यदि (g)
            h ^= g >> 24;
        h &= ~g;
    }
    प्रत्यागम h;
}

/* rebuild hash table of section s */
/* NOTE: we do factorize the hash table code to go faster */
स्थिर शून्य rebuild_hash(Section *s, अचिह्नित पूर्णाङ्क nb_buckets)
{
    ElfW(Sym) *sym;
    पूर्णाङ्क *ptr, *hash, nb_syms, sym_सूचकांक, h;
    अचिह्नित वर्ण *strtab;

    strtab = s->link->दत्त;
    nb_syms = s->दत्त_विस्थापनम् / परिमाण(ElfW(Sym));

    यदि (!nb_buckets)
        nb_buckets = ((पूर्णाङ्क*)s->hash->दत्त)[0];

    s->hash->दत्त_विस्थापनम् = 0;
    ptr = section_ptr_सङ्कलय(s->hash, (2 + nb_buckets + nb_syms) * परिमाण(पूर्णाङ्क));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    स्मृतिं_पूरय(hash, 0, (nb_buckets + 1) * परिमाण(पूर्णाङ्क));
    ptr += nb_buckets + 1;

    sym = (ElfW(Sym) *)s->दत्त + 1;
    प्रति(sym_सूचकांक = 1; sym_सूचकांक < nb_syms; sym_सूचकांक++) {
        यदि (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            h = elf_hash(strtab + sym->st_name) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_सूचकांक;
        } अन्यथा {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}

/* return the symbol number */
ST_FUNC पूर्णाङ्क put_elf_sym(Section *s, addr_t मानम्, अचिह्नित दीर्घ आकार,
    पूर्णाङ्क info, पूर्णाङ्क other, पूर्णाङ्क shndx, ध्रुव वर्ण *name)
{
    पूर्णाङ्क name_विस्थापनम्, sym_सूचकांक;
    पूर्णाङ्क nbuckets, h;
    ElfW(Sym) *sym;
    Section *hs;

    sym = section_ptr_सङ्कलय(s, परिमाण(ElfW(Sym)));
    यदि (name && name[0])
        name_विस्थापनम् = put_elf_str(s->link, name);
    अन्यथा
        name_विस्थापनम् = 0;
    /* XXX: endianness */
    sym->st_name = name_विस्थापनम्;
    sym->st_मानम् = मानम्;
    sym->st_आकार = आकार;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
    sym_सूचकांक = sym - (ElfW(Sym) *)s->दत्त;
    hs = s->hash;
    यदि (hs) {
        पूर्णाङ्क *ptr, *आधारः;
        ptr = section_ptr_सङ्कलय(hs, परिमाण(पूर्णाङ्क));
        आधारः = (पूर्णाङ्क *)hs->दत्त;
        /* only add global or weak symbols. */
        यदि (ELFW(ST_BIND)(info) != STB_LOCAL) {
            /* add another hashing entry */
            nbuckets = आधारः[0];
            h = elf_hash((अचिह्नित वर्ण *)s->link->दत्त + name_विस्थापनम्) % nbuckets;
            *ptr = आधारः[2 + h];
            आधारः[2 + h] = sym_सूचकांक;
            आधारः[1]++;
            /* we resize the hash table */
            hs->nb_hashed_syms++;
            यदि (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } अन्यथा {
            *ptr = 0;
            आधारः[1]++;
        }
    }
    प्रत्यागम sym_सूचकांक;
}

ST_FUNC पूर्णाङ्क find_elf_sym(Section *s, ध्रुव वर्ण *name)
{
    ElfW(Sym) *sym;
    Section *hs;
    पूर्णाङ्क nbuckets, sym_सूचकांक, h;
    ध्रुव वर्ण *name1;

    hs = s->hash;
    यदि (!hs)
        प्रत्यागम 0;
    nbuckets = ((पूर्णाङ्क *)hs->दत्त)[0];
    h = elf_hash((अचिह्नित वर्ण *) name) % nbuckets;
    sym_सूचकांक = ((पूर्णाङ्क *)hs->दत्त)[2 + h];
    यावत् (sym_सूचकांक != 0) {
        sym = &((ElfW(Sym) *)s->दत्त)[sym_सूचकांक];
        name1 = (वर्ण *) s->link->दत्त + sym->st_name;
        यदि (!वाक्यं_तुलय(name, name1))
            प्रत्यागम sym_सूचकांक;
        sym_सूचकांक = ((पूर्णाङ्क *)hs->दत्त)[2 + nbuckets + sym_सूचकांक];
    }
    प्रत्यागम 0;
}

/* return elf symbol value, signal error if 'err' is nonzero, decorate
   name if FORC */
ST_FUNC addr_t get_sym_addr(TCCState *s1, ध्रुव वर्ण *name, पूर्णाङ्क err, पूर्णाङ्क forc)
{
    पूर्णाङ्क sym_सूचकांक;
    ElfW(Sym) *sym;
    वर्ण buf[256];
    यदि (forc && s1->leading_underscore
#यदि_परिभाषितम् TCC_TARGET_PE
        /* win32-32bit stdcall symbols always have _ already */
        && !strchr(name, '@')
#यदि_अन्तः
        ) {
        buf[0] = '_';
        pstrcpy(buf + 1, परिमाण(buf) - 1, name);
        name = buf;
    }
    sym_सूचकांक = find_elf_sym(s1->symtab, name);
    sym = &((ElfW(Sym) *)s1->symtab->दत्त)[sym_सूचकांक];
    यदि (!sym_सूचकांक || sym->st_shndx == SHN_UNDEF) {
        यदि (err)
            tcc_error_noabort("%s not defined", name);
        प्रत्यागम (addr_t)-1;
    }
    प्रत्यागम sym->st_मानम्;
}

/* return elf symbol value */
LIBTCCAPI शून्य *tcc_get_चिह्नम्(TCCState *s, ध्रुव वर्ण *name)
{
    addr_t addr = get_sym_addr(s, name, 0, 1);
    प्रत्यागम addr == -1 ? रिक्त : (शून्य*)(uintptr_t)addr;
}

LIBTCCAPI पूर्णाङ्क tcc_सङ्कलय_चिह्नम्(TCCState *s1, ध्रुव वर्ण *name, ध्रुव शून्य *val)
{
#यदि_परिभाषितम् TCC_TARGET_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s1, 0, name, (uintptr_t)val);
#अन्यथा
    वर्ण buf[256];
    यदि (s1->leading_underscore) {
        buf[0] = '_';
        pstrcpy(buf + 1, परिमाण(buf) - 1, name);
        name = buf;
    }
    समुच्चयः_global_sym(s1, name, रिक्त, (addr_t)(uintptr_t)val); /* NULL: SHN_ABS */
#यदि_अन्तः
    प्रत्यागम 0;
}

/* list elf symbol names and values */
ST_FUNC शून्य list_elf_symbols(TCCState *s, शून्य *ctx,
    शून्य (*चिह्नम्_cb)(शून्य *ctx, ध्रुव वर्ण *name, ध्रुव शून्य *val))
{
    ElfW(Sym) *sym;
    Section *symtab;
    पूर्णाङ्क sym_सूचकांक, अन्तः_sym;
    ध्रुव वर्ण *name;
    अचिह्नित वर्ण sym_vis, sym_bind;

    symtab = s->symtab;
    अन्तः_sym = symtab->दत्त_विस्थापनम् / परिमाण (ElfSym);
    प्रति (sym_सूचकांक = 0; sym_सूचकांक < अन्तः_sym; ++sym_सूचकांक) {
        sym = &((ElfW(Sym) *)symtab->दत्त)[sym_सूचकांक];
        यदि (sym->st_मानम्) {
            name = (वर्ण *) symtab->link->दत्त + sym->st_name;
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            sym_vis = ELFW(ST_VISIBILITY)(sym->st_other);
            यदि (sym_bind == STB_GLOBAL && sym_vis == STV_DEFAULT)
                चिह्नम्_cb(ctx, name, (शून्य*)(uintptr_t)sym->st_मानम्);
        }
    }
}

/* list elf symbol names and values */
LIBTCCAPI शून्य tcc_list_symbols(TCCState *s, शून्य *ctx,
    शून्य (*चिह्नम्_cb)(शून्य *ctx, ध्रुव वर्ण *name, ध्रुव शून्य *val))
{
    list_elf_symbols(s, ctx, चिह्नम्_cb);
}

#यदि_अपरिभाषितम् ELF_OBJ_ONLY
स्थिर शून्य
संस्करणम्_सङ्कलय (TCCState *s1)
{
    पूर्णाङ्क i;
    ElfW(Sym) *sym;
    ElfW(Verneed) *vn = रिक्त;
    Section *symtab;
    पूर्णाङ्क sym_सूचकांक, अन्तः_sym, nb_versions = 2, nb_entries = 0;
    ElfW(Half) *versym;
    ध्रुव वर्ण *name;

    यदि (0 == nb_sym_versions)
        प्रत्यागम;
    versym_section = new_section(s1, ".gnu.version", SHT_GNU_versym, SHF_ALLOC);
    versym_section->sh_entsize = परिमाण(ElfW(Half));
    versym_section->link = s1->dynsym;

    /* add needed symbols */
    symtab = s1->dynsym;
    अन्तः_sym = symtab->दत्त_विस्थापनम् / परिमाण (ElfSym);
    versym = section_ptr_सङ्कलय(versym_section, अन्तः_sym * परिमाण(ElfW(Half)));
    प्रति (sym_सूचकांक = 1; sym_सूचकांक < अन्तः_sym; ++sym_सूचकांक) {
        पूर्णाङ्क dllindex, verndx;
        sym = &((ElfW(Sym) *)symtab->दत्त)[sym_सूचकांक];
        name = (वर्ण *) symtab->link->दत्त + sym->st_name;
        dllindex = find_elf_sym(s1->dynsymtab_section, name);
        verndx = (dllindex && dllindex < nb_sym_गन्तव्यम्_संस्करणम्)
                 ? sym_गन्तव्यम्_संस्करणम्[dllindex] : -1;
        यदि (verndx >= 0
            /* XXX: on android, clang refuses to link with a libtcc.so made by tcc
               when defined symbols have a version > 1 or when the version is '0'.
               Whereas version '1' for example for 'signal' in an exe defeats
               bcheck's signal_redir. */
            && (sym->st_shndx == SHN_UNDEF || (s1->output_type & TCC_OUTPUT_EXE))
            ) {
            यदि (!sym_versions[verndx].बहिर्गमनम्_सूचकांक)
              sym_versions[verndx].बहिर्गमनम्_सूचकांक = nb_versions++;
            versym[sym_सूचकांक] = sym_versions[verndx].बहिर्गमनम्_सूचकांक;
        } अन्यथा {
            versym[sym_सूचकांक] = 1; /* (*global*) */
        }
        //printf("SYM %d %s\n", versym[sym_index], name);
    }
    /* generate verneed section, but not when it will be empty.  Some
       dynamic linkers look at their contents even when DTVERNEEDNUM and
       section size is zero.  */
    यदि (nb_versions > 2) {
        verneed_section = new_section(s1, ".gnu.version_r",
                                      SHT_GNU_verneed, SHF_ALLOC);
        verneed_section->link = s1->dynsym->link;
        प्रति (i = nb_sym_versions; i-- > 0;) {
            संरचना sym_संस्करणम् *sv = &sym_versions[i];
            पूर्णाङ्क n_same_libs = 0, पूर्व;
            आकार_t vnofs;
            ElfW(Vernaux) *vna = 0;
            यदि (sv->बहिर्गमनम्_सूचकांक < 1)
              अनुवर्त;

            /* make sure that a DT_NEEDED tag is put */
            /* abitest-tcc fails on older i386-linux with "ld-linux.so.2" DT_NEEDED
               ret_int_test... Inconsistency detected by ld.so: dl-minimal.c: 148:
               realloc: Assertion `ptr == alloc_last_block' failed! */
            यदि (वाक्यं_तुलय(sv->lib, "ld-linux.so.2"))
                tcc_सङ्कलय_dllref(s1, sv->lib, 0);

            vnofs = section_सङ्कलय(verneed_section, परिमाण(*vn), 1);
            vn = (ElfW(Verneed)*)(verneed_section->दत्त + vnofs);
            vn->vn_संस्करणम् = 1;
            vn->vn_file = put_elf_str(verneed_section->link, sv->lib);
            vn->vn_aux = परिमाण (*vn);
            कुरु {
                पूर्व = sv->पूर्व_same_lib;
                यदि (sv->बहिर्गमनम्_सूचकांक > 0) {
                    vna = section_ptr_सङ्कलय(verneed_section, परिमाण(*vna));
                    vna->vna_hash = elf_hash ((ध्रुव अचिह्नित वर्ण *)sv->संस्करणम्);
                    vna->vna_flags = 0;
                    vna->vna_other = sv->बहिर्गमनम्_सूचकांक;
                    sv->बहिर्गमनम्_सूचकांक = -2;
                    vna->vna_name = put_elf_str(verneed_section->link, sv->संस्करणम्);
                    vna->vna_अग्र = परिमाण (*vna);
                    //printf("LIB %d %s %s\n", vna->vna_other, sv->lib, verneed_section->link->data + vna->vna_name);
                    n_same_libs++;
                }
                यदि (पूर्व >= 0)
                  sv = &sym_versions[पूर्व];
            } यावत्(पूर्व >= 0);
            vna->vna_अग्र = 0;
            vn = (ElfW(Verneed)*)(verneed_section->दत्त + vnofs);
            vn->vn_cnt = n_same_libs;
            vn->vn_अग्र = परिमाण(*vn) + n_same_libs * परिमाण(*vna);
            nb_entries++;
        }
        यदि (vn)
          vn->vn_अग्र = 0;
        verneed_section->sh_info = nb_entries;
    }
    dt_verneednum = nb_entries;
}
#यदि_अन्तः /* ndef ELF_OBJ_ONLY */

/* catch .tbss also */
स्थिर पूर्णाङ्क IS_BSS(TCCState *s1, पूर्णाङ्क ndx)
{
    प्रत्यागम ndx == SHN_COMMON
     || (ndx < s1->nb_sections
         && s1->sections[ndx]->sh_type == SHT_NOBITS);
}

/* add an elf symbol : check if it is already defined and patch
   it. Return symbol index. NOTE that sh_num can be SHN_UNDEF. */
ST_FUNC पूर्णाङ्क समुच्चयः_elf_sym(Section *s, addr_t मानम्, अचिह्नित दीर्घ आकार,
                       पूर्णाङ्क info, पूर्णाङ्क other, पूर्णाङ्क shndx, ध्रुव वर्ण *name)
{
    TCCState *s1 = s->s1;
    ElfW(Sym) *esym;
    पूर्णाङ्क sym_bind, sym_सूचकांक, sym_type, esym_bind;
    अचिह्नित वर्ण sym_vis, esym_vis, new_vis;

    sym_bind = ELFW(ST_BIND)(info);
    sym_type = ELFW(ST_TYPE)(info);
    sym_vis = ELFW(ST_VISIBILITY)(other);

    यदि (sym_bind != STB_LOCAL) {
        /* we search global or weak symbols */
        sym_सूचकांक = find_elf_sym(s, name);
        यदि (!sym_सूचकांक)
            गच्छ do_def;
        esym = &((ElfW(Sym) *)s->दत्त)[sym_सूचकांक];
        यदि (esym->st_मानम् == मानम् && esym->st_आकार == आकार && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            प्रत्यागम sym_सूचकांक;
        यदि (esym->st_shndx != SHN_UNDEF) {
            esym_bind = ELFW(ST_BIND)(esym->st_info);
            /* propagate the most constraining visibility */
            /* STV_DEFAULT(0)<STV_PROTECTED(3)<STV_HIDDEN(2)<STV_INTERNAL(1) */
            esym_vis = ELFW(ST_VISIBILITY)(esym->st_other);
            यदि (esym_vis == STV_DEFAULT) {
                new_vis = sym_vis;
            } अन्यथा यदि (sym_vis == STV_DEFAULT) {
                new_vis = esym_vis;
            } अन्यथा {
                new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
            }
            esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
                             | new_vis;
            यदि (shndx == SHN_UNDEF) {
                /* ignore adding of undefined symbol if the
                   corresponding symbol is already defined */
            } अन्यथा यदि (sym_bind == STB_GLOBAL && esym_bind == STB_WEAK) {
                /* global overrides weak, so patch */
                गच्छ do_patch;
            } अन्यथा यदि (sym_bind == STB_WEAK && esym_bind == STB_GLOBAL) {
                /* weak is ignored if already global */
            } अन्यथा यदि (sym_bind == STB_WEAK && esym_bind == STB_WEAK) {
                /* keep first-found weak definition, ignore subsequents */
            } अन्यथा यदि (sym_vis == STV_HIDDEN || sym_vis == STV_आन्तरिकम्) {
                /* ignore hidden symbols after */
            } अन्यथा यदि (s->sh_flags & SHF_DYNSYM) {
                /* we accept that two DLL define the same symbol */
            } अन्यथा यदि (!IS_BSS(s1, shndx) && IS_BSS(s1, esym->st_shndx)) {
                /* data symbol gets precedence over common/bss */
                गच्छ do_patch;
            } अन्यथा यदि (IS_BSS(s1, shndx)) {
                /* data symbol keeps precedence over common/bss */
	    } अन्यथा यदि (esym->st_other & ST_ASM_समुच्चयः) {
		/* If the existing symbol came from an asm .set
		   we can override.  */
		गच्छ do_patch;
            } अन्यथा {
#यदि 0
                प्रारूप_लिख("new_bind=%x new_shndx=%x new_vis=%x old_bind=%x old_shndx=%x old_vis=%x\n",
                       sym_bind, shndx, new_vis, esym_bind, esym->st_shndx, esym_vis);
#यदि_अन्तः
                tcc_error_noabort("link symbol '%s' defined twice", name);
            }
        } अन्यथा {
            esym->st_other = other;
        do_patch:
            esym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
            esym->st_shndx = shndx;
            esym->st_मानम् = मानम्;
            esym->st_आकार = आकार;
        }
    } अन्यथा {
    do_def:
        sym_सूचकांक = put_elf_sym(s, मानम्, आकार,
                                ELFW(ST_INFO)(sym_bind, sym_type), other,
                                shndx, name);
    }
    प्रत्यागम sym_सूचकांक;
}

/* put relocation */
ST_FUNC शून्य put_elf_reloca(Section *symtab, Section *s, अचिह्नित दीर्घ विस्थापनम्,
                            पूर्णाङ्क type, पूर्णाङ्क चिह्नम्, addr_t addend)
{
    TCCState *s1 = s->s1;
    वर्ण buf[256];
    Section *sr;
    ElfW_Rel *rel;

    sr = s->reloc;
    यदि (!sr) {
        /* if no relocation section, create it */
        snprintf(buf, परिमाण(buf), REL_SECTION_FMT, s->name);
        /* if the symtab is allocated, then we consider the relocation
           are also */
        sr = new_section(s->s1, buf, SHT_RELX, symtab->sh_flags);
        sr->sh_entsize = परिमाण(ElfW_Rel);
        sr->link = symtab;
        sr->sh_info = s->sh_अङ्कः;
        s->reloc = sr;
    }
    rel = section_ptr_सङ्कलय(sr, परिमाण(ElfW_Rel));
    rel->r_विस्थापनम् = विस्थापनम्;
    rel->r_info = ELFW(R_INFO)(चिह्नम्, type);
#यदि SHT_RELX == SHT_RELA
    rel->r_addend = addend;
#यदि_अन्तः
    यदि (SHT_RELX != SHT_RELA && addend)
        tcc_error_noabort("non-zero addend on REL architecture");
}

ST_FUNC शून्य put_elf_reloc(Section *symtab, Section *s, अचिह्नित दीर्घ विस्थापनम्,
                           पूर्णाङ्क type, पूर्णाङ्क चिह्नम्)
{
    put_elf_reloca(symtab, s, विस्थापनम्, type, चिह्नम्, 0);
}

ST_FUNC संरचना sym_attr *get_sym_attr(TCCState *s1, पूर्णाङ्क सूचकांक, पूर्णाङ्क alloc)
{
    पूर्णाङ्क n;
    संरचना sym_attr *tab;

    यदि (सूचकांक >= s1->nb_sym_attrs) {
        यदि (!alloc)
            प्रत्यागम s1->sym_attrs;
        /* find immediately bigger power of 2 and reallocate array */
        n = 1;
        यावत् (सूचकांक >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * परिमाण(*s1->sym_attrs));
        s1->sym_attrs = tab;
        स्मृतिं_पूरय(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * परिमाण(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    प्रत्यागम &s1->sym_attrs[सूचकांक];
}

स्थिर शून्य update_relocs(TCCState *s1, Section *s, पूर्णाङ्क *old_गन्तव्यम्_new_syms, पूर्णाङ्क first_sym)
{
    पूर्णाङ्क i, type, sym_सूचकांक;
    Section *sr;
    ElfW_Rel *rel;

    प्रति(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        यदि (sr->sh_type == SHT_RELX && sr->link == s) {
            for_each_elem(sr, 0, rel, ElfW_Rel) {
                sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
                type = ELFW(R_TYPE)(rel->r_info);
                यदि ((sym_सूचकांक -= first_sym) < 0)
                    अनुवर्त; /* zero sym_index in reloc (can happen with asm) */
                sym_सूचकांक = old_गन्तव्यम्_new_syms[sym_सूचकांक];
                rel->r_info = ELFW(R_INFO)(sym_सूचकांक, type);
            }
        }
    }
}

/* In an ELF file symbol table, the local symbols must appear below
   the global and weak ones. Since TCC cannot sort it while generating
   the code, we must do it after. All the relocation tables are also
   modified to take into account the symbol table sorting */
स्थिर शून्य क्रमय_syms(TCCState *s1, Section *s)
{
    पूर्णाङ्क *old_गन्तव्यम्_new_syms;
    ElfW(Sym) *new_syms;
    पूर्णाङ्क nb_syms, i;
    ElfW(Sym) *p, *q;

    nb_syms = s->दत्त_विस्थापनम् / परिमाण(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * परिमाण(ElfW(Sym)));
    old_गन्तव्यम्_new_syms = tcc_malloc(nb_syms * परिमाण(पूर्णाङ्क));

    /* first pass for local symbols */
    p = (ElfW(Sym) *)s->दत्त;
    q = new_syms;
    प्रति(i = 0; i < nb_syms; i++) {
        यदि (ELFW(ST_BIND)(p->st_info) == STB_LOCAL) {
            old_गन्तव्यम्_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    /* save the number of local symbols in section header */
    यदि( s->sh_आकार )    /* this 'if' makes IDA happy */
        s->sh_info = q - new_syms;

    /* then second pass for non local symbols */
    p = (ElfW(Sym) *)s->दत्त;
    प्रति(i = 0; i < nb_syms; i++) {
        यदि (ELFW(ST_BIND)(p->st_info) != STB_LOCAL) {
            old_गन्तव्यम्_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }

    /* we copy the new symbols to the old */
    स्मृतिं_प्रतिलिख(s->दत्त, new_syms, nb_syms * परिमाण(ElfW(Sym)));
    tcc_free(new_syms);

    update_relocs(s1, s, old_गन्तव्यम्_new_syms, 0);
    tcc_free(old_गन्तव्यम्_new_syms);
}

#यदि_अपरिभाषितम् ELF_OBJ_ONLY
/* See: https://flapenguin.me/elf-dt-gnu-hash */
#परिभाषय	ELFCLASS_द्वयङ्काः (PTR_आकार * 8)

स्थिर Section *create_gnu_hash(TCCState *s1)
{
    पूर्णाङ्क nb_syms, i, ndef, nbuckets, symoffset, bloom_आकार, bloom_सरणम्;
    ElfW(Sym) *p;
    Section *gnu_hash;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr;

    gnu_hash = new_section(s1, ".gnu.hash", SHT_GNU_HASH, SHF_ALLOC);
    gnu_hash->link = dynsym->hash->link;

    nb_syms = dynsym->दत्त_विस्थापनम् / परिमाण(ElfW(Sym));

    /* count def symbols */
    ndef = 0;
    p = (ElfW(Sym) *)dynsym->दत्त;
    प्रति(i = 0; i < nb_syms; i++, p++)
        ndef += p->st_shndx != SHN_UNDEF;

    /* calculate gnu hash sizes and fill header */
    nbuckets = ndef / 4 + 1;
    symoffset = nb_syms - ndef;
    bloom_सरणम् = PTR_आकार == 8 ? 6 : 5;
    bloom_आकार = 1; /* must be power of two */
    यावत् (ndef >= bloom_आकार * (1 << (bloom_सरणम् - 3)))
	bloom_आकार *= 2;
    ptr = section_ptr_सङ्कलय(gnu_hash, 4 * 4 +
				    PTR_आकार * bloom_आकार +
				    nbuckets * 4 +
				    ndef * 4);
    ptr[0] = nbuckets;
    ptr[1] = symoffset;
    ptr[2] = bloom_आकार;
    ptr[3] = bloom_सरणम्;
    प्रत्यागम gnu_hash;
}

स्थिर Elf32_Word elf_gnu_hash (ध्रुव अचिह्नित वर्ण *name)
{
    Elf32_Word h = 5381;
    अचिह्नित वर्ण c;

    यावत् ((c = *name++))
        h = h * 33 + c;
    प्रत्यागम h;
}

स्थिर शून्य update_gnu_hash(TCCState *s1, Section *gnu_hash)
{
    पूर्णाङ्क *old_गन्तव्यम्_new_syms;
    ElfW(Sym) *new_syms;
    पूर्णाङ्क nb_syms, i, nbuckets, bloom_आकार, bloom_सरणम्;
    ElfW(Sym) *p, *q;
    Section *vs;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr, *buckets, *chain, *hash;
    अचिह्नित पूर्णाङ्क *nextbuck;
    addr_t *bloom;
    अचिह्नित वर्ण *strtab;
    संरचना { पूर्णाङ्क first, चरमः; } *buck;

    strtab = dynsym->link->दत्त;
    nb_syms = dynsym->दत्त_विस्थापनम् / परिमाण(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * परिमाण(ElfW(Sym)));
    old_गन्तव्यम्_new_syms = tcc_malloc(nb_syms * परिमाण(पूर्णाङ्क));
    hash = tcc_malloc(nb_syms * परिमाण(Elf32_Word));
    nextbuck = tcc_malloc(nb_syms * परिमाण(पूर्णाङ्क));

    /* calculate hashes and copy undefs */
    p = (ElfW(Sym) *)dynsym->दत्त;
    q = new_syms;
    प्रति(i = 0; i < nb_syms; i++, p++) {
        यदि (p->st_shndx == SHN_UNDEF) {
            old_गन्तव्यम्_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
	अन्यथा
	    hash[i] = elf_gnu_hash(strtab + p->st_name);
    }

    ptr = (Elf32_Word *) gnu_hash->दत्त;
    nbuckets = ptr[0];
    bloom_आकार = ptr[2];
    bloom_सरणम् = ptr[3];
    bloom = (addr_t *) (शून्य *) &ptr[4];
    buckets = (Elf32_Word*) (शून्य *) &bloom[bloom_आकार];
    chain = &buckets[nbuckets];
    buck = tcc_malloc(nbuckets * परिमाण(*buck));

    यदि (gnu_hash->दत्त_विस्थापनम् != 4 * 4 +
				 PTR_आकार * bloom_आकार +
				 nbuckets * 4 +
				 (nb_syms - (q - new_syms)) * 4)
	tcc_error_noabort ("gnu_hash size incorrect");

    /* find buckets */
    प्रति(i = 0; i < nbuckets; i++)
	buck[i].first = -1;

    p = (ElfW(Sym) *)dynsym->दत्त;
    प्रति(i = 0; i < nb_syms; i++, p++)
        यदि (p->st_shndx != SHN_UNDEF) {
	    पूर्णाङ्क bucket = hash[i] % nbuckets;

	    यदि (buck[bucket].first == -1)
		buck[bucket].first = buck[bucket].चरमः = i;
	    अन्यथा {
		nextbuck[buck[bucket].चरमः] = i;
		buck[bucket].चरमः = i;
	    }
	}

    /* fill buckets/chains/bloom and sort symbols */
    p = (ElfW(Sym) *)dynsym->दत्त;
    प्रति(i = 0; i < nbuckets; i++) {
	पूर्णाङ्क cur = buck[i].first;

	यदि (cur != -1) {
	    buckets[i] = q - new_syms;
	    प्रति (;;) {
                old_गन्तव्यम्_new_syms[cur] = q - new_syms;
                *q++ = p[cur];
	        *chain++ = hash[cur] & ~1;
		bloom[(hash[cur] / ELFCLASS_द्वयङ्काः) % bloom_आकार] |=
		    (addr_t)1 << (hash[cur] % ELFCLASS_द्वयङ्काः) |
		    (addr_t)1 << ((hash[cur] >> bloom_सरणम्) % ELFCLASS_द्वयङ्काः);
		यदि (cur == buck[i].चरमः)
		    भङ्ग;
		cur = nextbuck[cur];
	    }
	    chain[-1] |= 1;
	}
    }

    स्मृतिं_प्रतिलिख(dynsym->दत्त, new_syms, nb_syms * परिमाण(ElfW(Sym)));
    tcc_free(new_syms);
    tcc_free(hash);
    tcc_free(buck);
    tcc_free(nextbuck);

    update_relocs(s1, dynsym, old_गन्तव्यम्_new_syms, 0);

    /* modify the versions */
    vs = versym_section;
    यदि (vs) {
	ElfW(Half) *newver, *versym = (ElfW(Half) *)vs->दत्त;

	यदि (1/*versym*/) {
            newver = tcc_malloc(nb_syms * परिमाण(*newver));
	    प्रति (i = 0; i < nb_syms; i++)
	        newver[old_गन्तव्यम्_new_syms[i]] = versym[i];
	    स्मृतिं_प्रतिलिख(vs->दत्त, newver, nb_syms * परिमाण(*newver));
	    tcc_free(newver);
	}
    }

    tcc_free(old_गन्तव्यम्_new_syms);

    /* rebuild hash */
    ptr = (Elf32_Word *) dynsym->hash->दत्त;
    rebuild_hash(dynsym, ptr[0]);
}
#यदि_अन्तः /* ELF_OBJ_ONLY */

/* relocate symbol table, resolve undefined symbols if do_resolve is
   true and output error if undefined symbol. */
ST_FUNC शून्य relocate_syms(TCCState *s1, Section *symtab, पूर्णाङ्क do_resolve)
{
    ElfW(Sym) *sym;
    पूर्णाङ्क sym_bind, sh_अङ्कः;
    ध्रुव वर्ण *name;

    for_each_elem(symtab, 1, sym, ElfW(Sym)) {
        sh_अङ्कः = sym->st_shndx;
        यदि (sh_अङ्कः == SHN_UNDEF) {
            यदि (do_resolve == 2) /* relocating dynsym */
                अनुवर्त;
            name = (वर्ण *) s1->symtab->link->दत्त + sym->st_name;
            /* Use ld.so to resolve symbol for us (for tcc -run) */
            यदि (do_resolve) {
#यदि defined TCC_IS_NATIVE && !defined TCC_TARGET_PE
                /* dlsym() needs the undecorated name.  */
                ध्रुव वर्ण *name_ud = &name[s1->leading_underscore];
                शून्य *addr = रिक्त;
                यदि (!s1->nostdlib)
                    addr = dlsym(RTLD_DEFAULT, name_ud);
		यदि (addr == रिक्त) {
		    पूर्णाङ्क i;
		    प्रति (i = 0; i < s1->nb_loaded_dlls; i++)
                        यदि ((addr = dlsym(s1->loaded_dlls[i]->handle, name_ud)))
			    भङ्ग;
		}
                यदि (addr) {
                    sym->st_मानम् = (addr_t) addr;
#यदि_परिभाषितम् DEBUG_RELOC
		    प्रारूप_लिख ("relocate_sym: %s -> 0x%lx\n", name, sym->st_मानम्);
#यदि_अन्तः
                    गच्छ प्राप्तम्;
                }
#यदि_अन्तः
            /* if dynamic symbol exist, it will be used in relocate_section */
            } अन्यथा यदि (s1->dynsym && find_elf_sym(s1->dynsym, name))
                गच्छ प्राप्तम्;
            /* XXX: _fp_hw seems to be part of the ABI, so we ignore
               it */
            यदि (!वाक्यं_तुलय(name, "_fp_hw"))
                गच्छ प्राप्तम्;
            /* only weak symbols are accepted to be undefined. Their
               value is zero */
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            यदि (sym_bind == STB_WEAK)
                sym->st_मानम् = 0;
            अन्यथा
                tcc_error_noabort("unresolved reference to '%s'", name);

        } अन्यथा यदि (sh_अङ्कः < SHN_LORESERVE) {
            /* add section base */
            sym->st_मानम् += s1->sections[sym->st_shndx]->sh_addr;
        }
    प्राप्तम्: ;
    }
}

/* relocate a given section (CPU dependent) by applying the relocations
   in the associated relocation section */
स्थिर शून्य relocate_section(TCCState *s1, Section *s, Section *sr)
{
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    पूर्णाङ्क type, sym_सूचकांक;
    अचिह्नित वर्ण *ptr;
    addr_t tgt, addr;
    पूर्णाङ्क is_dwarf = s->sh_अङ्कः >= s1->dwlo && s->sh_अङ्कः < s1->dwhi;

    qrel = (ElfW_Rel *)sr->दत्त;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
	यदि (s->दत्त == रिक्त) /* bss */
	    अनुवर्त;
        ptr = s->दत्त + rel->r_विस्थापनम्;
        sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
        sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
        type = ELFW(R_TYPE)(rel->r_info);
        tgt = sym->st_मानम्;
#यदि SHT_RELX == SHT_RELA
        tgt += rel->r_addend;
#यदि_अन्तः
        यदि (is_dwarf && type == R_दत्त_32_DW
            && sym->st_shndx >= s1->dwlo && sym->st_shndx < s1->dwhi) {
            /* dwarf section relocation to each other */
            add32le(ptr, tgt - s1->sections[sym->st_shndx]->sh_addr);
            अनुवर्त;
        }
        addr = s->sh_addr + rel->r_विस्थापनम्;
        relocate(s1, rel, type, ptr, addr, tgt);
    }

#यदि_अपरिभाषितम् ELF_OBJ_ONLY
    /* if the relocation is allocated, we change its symbol table */
    यदि (sr->sh_flags & SHF_ALLOC) {
        sr->link = s1->dynsym;
        यदि (s1->output_type & TCC_OUTPUT_DYN) {
            आकार_t r = (uint8_t*)qrel - sr->दत्त;
            यदि (परिमाण ((Stab_Sym*)0)->n_मानम् < PTR_आकार
                && 0 == वाक्यं_तुलय(s->name, ".stab"))
                r = 0; /* cannot apply 64bit relocation to 32bit value */
            sr->दत्त_विस्थापनम् = sr->sh_आकार = r;
#यदि_परिभाषितम् CONFIG_TCC_PIE
            यदि (r && (s->sh_flags & SHF_EXECINSTR))
                tcc_warning("%d relocations to %s", (अचिह्नित)(r / परिमाण *qrel), s->name);
#यदि_अन्तः
        }
    }
#यदि_अन्तः

#यदि_परिभाषितम् TCC_TARGET_RISCV64
    dynarray_reset(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries);
#यदि_अन्तः
}

/* relocate all sections */
ST_FUNC शून्य relocate_sections(TCCState *s1)
{
    पूर्णाङ्क i;
    Section *s, *sr;

    प्रति (i = 1; i < s1->nb_sections; ++i) {
        sr = s1->sections[i];
        यदि (sr->sh_type != SHT_RELX)
            अनुवर्त;
        s = s1->sections[sr->sh_info];
#यदि_अपरिभाषितम् TCC_TARGET_MACHO
        यदि (s != s1->got
            || s1->static_link
            || s1->output_type == TCC_OUTPUT_स्मृतिः)
#यदि_अन्तः
        {
            relocate_section(s1, s, sr);
        }
#यदि_अपरिभाषितम् ELF_OBJ_ONLY
        यदि (sr->sh_flags & SHF_ALLOC) {
            ElfW_Rel *rel;
            /* relocate relocation table in 'sr' */
            for_each_elem(sr, 0, rel, ElfW_Rel)
                rel->r_विस्थापनम् += s->sh_addr;
        }
#यदि_अन्तः
    }
}

#यदि_अपरिभाषितम् ELF_OBJ_ONLY
/* count the number of dynamic relocations so that we can reserve
   their space */
स्थिर पूर्णाङ्क prepare_dynamic_rel(TCCState *s1, Section *sr)
{
    पूर्णाङ्क गणनम्_2 = 0;
#यदि defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || \
    defined(TCC_TARGET_ARM) || defined(TCC_TARGET_ARM64) || \
    defined(TCC_TARGET_RISCV64)
    ElfW_Rel *rel;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
        पूर्णाङ्क sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
        पूर्णाङ्क type = ELFW(R_TYPE)(rel->r_info);
        विकल्प(type) {
#यदि defined(TCC_TARGET_I386)
        पक्ष R_386_32:
            यदि (!get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक
                && ((ElfW(Sym)*)symtab_section->दत्त + sym_सूचकांक)->st_shndx == SHN_UNDEF) {
                /* don't fixup unresolved (weak) symbols */
                rel->r_info = ELFW(R_INFO)(sym_सूचकांक, R_386_RELATIVE);
                भङ्ग;
            }
#नोचेद्यदि defined(TCC_TARGET_X86_64)
        पक्ष R_X86_64_32:
        पक्ष R_X86_64_32S:
        पक्ष R_X86_64_64:
#नोचेद्यदि defined(TCC_TARGET_ARM)
        पक्ष R_ARM_ABS32:
        पक्ष R_ARM_TARGET1:
#नोचेद्यदि defined(TCC_TARGET_ARM64)
        पक्ष R_AARCH64_ABS32:
        पक्ष R_AARCH64_ABS64:
#नोचेद्यदि defined(TCC_TARGET_RISCV64)
        पक्ष R_RISCV_32:
        पक्ष R_RISCV_64:
#यदि_अन्तः
            गणनम्_2++;
            भङ्ग;
#यदि defined(TCC_TARGET_I386)
        पक्ष R_386_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    यदि (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_सूचकांक, R_386_PLT32);
	        भङ्ग;
	    }
	}
#नोचेद्यदि defined(TCC_TARGET_X86_64)
        पक्ष R_X86_64_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    यदि (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_सूचकांक, R_X86_64_PLT32);
	        भङ्ग;
	    }
	}
#नोचेद्यदि defined(TCC_TARGET_ARM64)
        पक्ष R_AARCH64_PREL32:
#यदि_अन्तः
            यदि (s1->output_type != TCC_OUTPUT_DLL)
                भङ्ग;
            यदि (get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक)
                गणनम्_2++;
            भङ्ग;
        स्वभाव:
            भङ्ग;
        }
    }
#यदि_अन्तः
    प्रत्यागम गणनम्_2;
}
#यदि_अन्तः

#यदि_परिभाषितम् NEED_BUILD_GOT
स्थिर पूर्णाङ्क build_got(TCCState *s1)
{
    /* if no got, then create it */
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    s1->got->sh_entsize = 4;
    /* keep space for _DYNAMIC pointer and two dummy got entries */
    section_ptr_सङ्कलय(s1->got, 3 * PTR_आकार);
    प्रत्यागम समुच्चयः_elf_sym(symtab_section, 0, 0, ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
        0, s1->got->sh_अङ्कः, "_GLOBAL_OFFSET_TABLE_");
}

/* Create a GOT and (for function call) a PLT entry corresponding to a symbol
   in s1->symtab. When creating the dynamic symbol table entry for the GOT
   relocation, use 'size' and 'info' for the corresponding symbol metadata.
   Returns the offset of the GOT or (if any) PLT entry. */
स्थिर संरचना sym_attr * put_got_प्रविष्टिः(TCCState *s1, पूर्णाङ्क dyn_reloc_type,
                                       पूर्णाङ्क sym_सूचकांक)
{
    पूर्णाङ्क need_plt_प्रविष्टिः;
    ध्रुव वर्ण *name;
    ElfW(Sym) *sym;
    संरचना sym_attr *attr;
    अचिह्नित got_विस्थापनम्;
    वर्ण plt_name[200];
    पूर्णाङ्क len;
    Section *s_rel;

    need_plt_प्रविष्टिः = (dyn_reloc_type == R_JMP_SLOT);
    attr = get_sym_attr(s1, sym_सूचकांक, 1);

    /* In case a function is both called and its address taken 2 GOT entries
       are created, one for taking the address (GOT) and the other for the PLT
       entry (PLTGOT).  */
    यदि (need_plt_प्रविष्टिः ? attr->plt_विस्थापनम् : attr->got_विस्थापनम्)
        प्रत्यागम attr;

    s_rel = s1->got;
    यदि (need_plt_प्रविष्टिः) {
        यदि (!s1->plt) {
            s1->plt = new_section(s1, ".plt", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
            s1->plt->sh_entsize = 4;
        }
        s_rel = s1->plt;
    }

    /* create the GOT entry */
    got_विस्थापनम् = s1->got->दत्त_विस्थापनम्;
    section_ptr_सङ्कलय(s1->got, PTR_आकार);

    /* Create the GOT relocation that will insert the address of the object or
       function of interest in the GOT entry. This is a static relocation for
       memory output (dlsym will give us the address of symbols) and dynamic
       relocation otherwise (executable and DLLs). The relocation should be
       done lazily for GOT entry with *_JUMP_SLOT relocation type (the one
       associated to a PLT entry) but is currently done at load time for an
       unknown reason. */

    sym = &((ElfW(Sym) *) symtab_section->दत्त)[sym_सूचकांक];
    name = (वर्ण *) symtab_section->link->दत्त + sym->st_name;
    //printf("sym %d %s\n", need_plt_entry, name);

    यदि (s1->dynsym) {
	यदि (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
	    /* Hack alarm.  We don't want to emit dynamic symbols
	       and symbol based relocs for STB_LOCAL symbols, but rather
	       want to resolve them directly.  At this point the symbol
	       values aren't final yet, so we must defer this.  We will later
	       have to create a RELATIVE reloc anyway, so we misuse the
	       relocation slot to smuggle the symbol reference until
	       fill_local_got_entries.  Not that the sym_index is
	       relative to symtab_section, not s1->dynsym!  Nevertheless
	       we use s1->dyn_sym so that if this is the first call
	       that got->reloc is correctly created.  Also note that
	       RELATIVE relocs are not normally created for the .got,
	       so the types serves as a marker for later (and is retained
	       also for the final output, which is okay because then the
	       got is just normal data).  */
	    put_elf_reloc(s1->dynsym, s1->got, got_विस्थापनम्, R_RELATIVE,
			  sym_सूचकांक);
	} अन्यथा {
	    यदि (0 == attr->dyn_सूचकांक)
                attr->dyn_सूचकांक = समुच्चयः_elf_sym(s1->dynsym, sym->st_मानम्,
                                              sym->st_आकार, sym->st_info, 0,
                                              sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s_rel, got_विस्थापनम्, dyn_reloc_type,
			  attr->dyn_सूचकांक);
	}
    } अन्यथा {
        put_elf_reloc(symtab_section, s1->got, got_विस्थापनम्, dyn_reloc_type,
                      sym_सूचकांक);
    }

    यदि (need_plt_प्रविष्टिः) {
        attr->plt_विस्थापनम् = create_plt_प्रविष्टिः(s1, got_विस्थापनम्, attr);

        /* create a symbol 'sym@plt' for the PLT jump vector */
        len = वाक्यदैर्घ्यम्(name);
        यदि (len > परिमाण plt_name - 5)
            len = परिमाण plt_name - 5;
        स्मृतिं_प्रतिलिख(plt_name, name, len);
        वाक्यं_प्रतिलिख(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_विस्थापनम्, 0,
            ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0, s1->plt->sh_अङ्कः, plt_name);
    } अन्यथा {
        attr->got_विस्थापनम् = got_विस्थापनम्;
    }

    प्रत्यागम attr;
}

/* build GOT and PLT entries */
/* Two passes because R_JMP_SLOT should become first. Some targets
   (arm, arm64) do not allow mixing R_JMP_SLOT and R_GLOB_DAT. */
ST_FUNC शून्य build_got_entries(TCCState *s1, पूर्णाङ्क got_sym)
{
    Section *s;
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    पूर्णाङ्क i, type, gotplt_प्रविष्टिः, reloc_type, sym_सूचकांक;
    संरचना sym_attr *attr;
    पूर्णाङ्क pass = 0;
redo:
    प्रति(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        यदि (s->sh_type != SHT_RELX)
            अनुवर्त;
        /* no need to handle got relocations */
        यदि (s->link != symtab_section)
            अनुवर्त;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_प्रविष्टिः = gotplt_प्रविष्टिः_type(type);
            यदि (gotplt_प्रविष्टिः == -1) {
                tcc_error_noabort ("Unknown relocation type for got: %d", type);
                अनुवर्त;
            }
            sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];

            यदि (gotplt_प्रविष्टिः == NO_GOTPLT_प्रविष्टिः) {
                अनुवर्त;
            }

            /* Automatically create PLT/GOT [entry] if it is an undefined
	       reference (resolved at runtime), or the symbol is absolute,
	       probably created by tcc_add_symbol, and thus on 64-bit
	       targets might be too far from application code.  */
            यदि (gotplt_प्रविष्टिः == AUTO_GOTPLT_प्रविष्टिः) {
                यदि (sym->st_shndx == SHN_UNDEF) {
                    ElfW(Sym) *esym;
		    पूर्णाङ्क dynindex;
                    यदि (!PCRELATIVE_DLLPLT
                        && (s1->output_type & TCC_OUTPUT_DYN))
                        अनुवर्त;
		    /* Relocations for UNDEF symbols would normally need
		       to be transferred into the executable or shared object.
		       If that were done AUTO_GOTPLT_ENTRY wouldn't exist.
		       But TCC doesn't do that (at least for exes), so we
		       need to resolve all such relocs locally.  And that
		       means PLT slots for functions in DLLs and COPY relocs for
		       data symbols.  COPY relocs were generated in
		       bind_exe_dynsyms (and the symbol adjusted to be defined),
		       and for functions we were generated a dynamic symbol
		       of function type.  */
		    यदि (s1->dynsym) {
			/* dynsym isn't set for -run :-/  */
			dynindex = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
			esym = (ElfW(Sym) *)s1->dynsym->दत्त + dynindex;
			यदि (dynindex
			    && (ELFW(ST_TYPE)(esym->st_info) == STT_FUNC
				|| (ELFW(ST_TYPE)(esym->st_info) == STT_NOTYPE
				    && ELFW(ST_TYPE)(sym->st_info) == STT_FUNC)))
			    गच्छ jmp_slot;
		    }
                } अन्यथा यदि (sym->st_shndx == SHN_ABS) {
                    यदि (sym->st_मानम् == 0) /* from tcc_add_btstub() */
                        अनुवर्त;
#यदि_अपरिभाषितम् TCC_TARGET_ARM
                    यदि (PTR_आकार != 8)
                        अनुवर्त;
#यदि_अन्तः
                    /* from tcc_add_symbol(): on 64 bit platforms these
                       need to go through .got */
                } अन्यथा
                    अनुवर्त;
            }

#यदि_परिभाषितम् TCC_TARGET_I386
            यदि ((type == R_386_PLT32 || type == R_386_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		यदि (pass != 0)
		    अनुवर्त;
                rel->r_info = ELFW(R_INFO)(sym_सूचकांक, R_386_PC32);
                अनुवर्त;
            }
#यदि_अन्तः
#यदि_परिभाषितम् TCC_TARGET_X86_64
            यदि ((type == R_X86_64_PLT32 || type == R_X86_64_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		यदि (pass != 0)
		    अनुवर्त;
                rel->r_info = ELFW(R_INFO)(sym_सूचकांक, R_X86_64_PC32);
                अनुवर्त;
            }
#यदि_अन्तः
            reloc_type = संहिता_reloc(type);
            यदि (reloc_type == -1) {
                tcc_error_noabort ("Unknown relocation type: %d", type);
                अनुवर्त;
            }

            यदि (reloc_type != 0) {
        jmp_slot:
	        यदि (pass != 0)
                    अनुवर्त;
                reloc_type = R_JMP_SLOT;
            } अन्यथा {
	        यदि (pass != 1)
                    अनुवर्त;
                reloc_type = R_GLOB_DAT;
            }

            यदि (!s1->got)
                got_sym = build_got(s1);

            यदि (gotplt_प्रविष्टिः == BUILD_GOT_ONLY)
                अनुवर्त;

            attr = put_got_प्रविष्टिः(s1, reloc_type, sym_सूचकांक);

            यदि (reloc_type == R_JMP_SLOT)
                rel->r_info = ELFW(R_INFO)(attr->plt_sym, type);
        }
    }
    यदि (++pass < 2)
        गच्छ redo;
    /* .rel.plt refers to .got actually */
    यदि (s1->plt && s1->plt->reloc)
        s1->plt->reloc->sh_info = s1->got->sh_अङ्कः;
    यदि (got_sym) /* set size */
        ((ElfW(Sym)*)symtab_section->दत्त)[got_sym].st_आकार = s1->got->दत्त_विस्थापनम्;
}
#यदि_अन्तः /* def NEED_BUILD_GOT */

ST_FUNC पूर्णाङ्क समुच्चयः_global_sym(TCCState *s1, ध्रुव वर्ण *name, Section *sec, addr_t offs)
{
    पूर्णाङ्क shn = sec ? sec->sh_अङ्कः : offs || !name ? SHN_ABS : SHN_UNDEF;
    यदि (sec && offs == -1)
        offs = sec->दत्त_विस्थापनम्;
    प्रत्यागम समुच्चयः_elf_sym(symtab_section, offs, 0,
        ELFW(ST_INFO)(name ? STB_GLOBAL : STB_LOCAL, STT_NOTYPE), 0, shn, name);
}

स्थिर शून्य सङ्कलय_init_array_परिभाषते(TCCState *s1, ध्रुव वर्ण *section_name)
{
    Section *s;
    addr_t अन्तः_विस्थापनम्;
    वर्ण buf[1024];
    s = have_section(s1, section_name);
    यदि (!s || !(s->sh_flags & SHF_ALLOC)) {
        अन्तः_विस्थापनम् = 0;
        s = text_section;
    } अन्यथा {
        अन्तः_विस्थापनम् = s->दत्त_विस्थापनम्;
    }
    snprintf(buf, परिमाण(buf), "__%s_start", section_name + 1);
    समुच्चयः_global_sym(s1, buf, s, 0);
    snprintf(buf, परिमाण(buf), "__%s_end", section_name + 1);
    समुच्चयः_global_sym(s1, buf, s, अन्तः_विस्थापनम्);
}

ST_FUNC शून्य सङ्कलय_array (TCCState *s1, ध्रुव वर्ण *sec, पूर्णाङ्क c)
{
    Section *s;
    s = find_section(s1, sec);
    s->sh_flags = shf_RELRO;
    s->sh_type = sec[1] == 'i' ? SHT_INIT_ARRAY : SHT_FINI_ARRAY;
    put_elf_reloc (s1->symtab, s, s->दत्त_विस्थापनम्, R_दत्त_PTR, c);
    section_ptr_सङ्कलय(s, PTR_आकार);
}

#यदि_परिभाषितम् CONFIG_TCC_BCHECK
ST_FUNC शून्य tcc_सङ्कलय_bcheck(TCCState *s1)
{
    यदि (0 == s1->do_bounds_check)
        प्रत्यागम;
    section_ptr_सङ्कलय(bounds_section, परिमाण(addr_t));
}
#यदि_अन्तः

/* set symbol to STB_LOCAL and resolve. The point is to not export it as
   a dynamic symbol to allow so's to have one each with a different value. */
स्थिर शून्य समुच्चयः_local_sym(TCCState *s1, ध्रुव वर्ण *name, Section *s, पूर्णाङ्क विस्थापनम्)
{
    पूर्णाङ्क c = find_elf_sym(s1->symtab, name);
    यदि (c) {
        ElfW(Sym) *esym = (ElfW(Sym)*)s1->symtab->दत्त + c;
        esym->st_info = ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE);
        esym->st_मानम् = विस्थापनम्;
        esym->st_shndx = s->sh_अङ्कः;
    }
}

/* avoid generating debug/test_coverage code for stub functions */
स्थिर शून्य tcc_compile_string_no_debug(TCCState *s, ध्रुव वर्ण *str)
{
    पूर्णाङ्क save_do_debug = s->do_debug;
    पूर्णाङ्क save_test_coverage = s->test_coverage;

    s->do_debug = 0;
    s->test_coverage = 0;
    tcc_compile_string(s, str);
    s->do_debug = save_do_debug;
    s->test_coverage = save_test_coverage;
}

#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
स्थिर शून्य put_ptr(TCCState *s1, Section *s, पूर्णाङ्क offs)
{
    पूर्णाङ्क c;
    c = समुच्चयः_global_sym(s1, रिक्त, s, offs);
    s = दत्त_section;
    put_elf_reloc (s1->symtab, s, s->दत्त_विस्थापनम्, R_दत्त_PTR, c);
    section_ptr_सङ्कलय(s, PTR_आकार);
}

ST_FUNC शून्य tcc_सङ्कलय_btstub(TCCState *s1)
{
    Section *s;
    पूर्णाङ्क n, o, *p;
    CString cstr;
    ध्रुव वर्ण *__rt_info = &"___rt_info"[!s1->leading_underscore];

    s = दत्त_section;
    /* Align to PTR_SIZE */
    section_सङ्कलय(s, 0, PTR_आकार);
    o = s->दत्त_विस्थापनम्;
    /* create a struct rt_context (see tccrun.c) */
    यदि (s1->dwarf) {
        put_ptr(s1, dwarf_पङ्क्तिः_section, 0);
        put_ptr(s1, dwarf_पङ्क्तिः_section, -1);
	यदि (s1->dwarf >= 5)
            put_ptr(s1, dwarf_पङ्क्तिः_str_section, 0);
	अन्यथा
            put_ptr(s1, dwarf_str_section, 0);
    }
    अन्यथा
    {
        put_ptr(s1, stab_section, 0);
        put_ptr(s1, stab_section, -1);
        put_ptr(s1, stab_section->link, 0);
    }

    /* skip esym_start/esym_end/elf_str (not loaded) */
    section_ptr_सङ्कलय(s, 3 * PTR_आकार);

    यदि (s1->output_type == TCC_OUTPUT_स्मृतिः && 0 == s1->dwarf) {
        put_ptr(s1, text_section, 0);
    } अन्यथा {
        /* prog_base : local nameless symbol with offset 0 at SHN_ABS */
        put_ptr(s1, रिक्त, 0);
#यदि defined TCC_TARGET_MACHO
        /* adjust for __PAGEZERO */
        यदि (s1->dwarf == 0 && s1->output_type == TCC_OUTPUT_EXE)
            write64le(दत्त_section->दत्त + दत्त_section->दत्त_विस्थापनम् - PTR_आकार,
	              (uint64_t)1 << 32);
#यदि_अन्तः
    }
    n = 3 * PTR_आकार;
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    यदि (s1->do_bounds_check) {
        put_ptr(s1, bounds_section, 0);
        n -= PTR_आकार;
    }
#यदि_अन्तः
    section_ptr_सङ्कलय(s, n);
    p = section_ptr_सङ्कलय(s, 2 * परिमाण (पूर्णाङ्क));
    p[0] = s1->rt_अङ्कः_callers;
    p[1] = s1->dwarf;
    // if (s->data_offset - o != 10*PTR_SIZE + 2*sizeof (int)) exit(99);

    यदि (s1->output_type == TCC_OUTPUT_स्मृतिः) {
        समुच्चयः_global_sym(s1, __rt_info, s, o);
        प्रत्यागम;
    }

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern void __bt_init(),__bt_exit(),__bt_init_dll();"
        "static void *__rt_info[];"
        "__attribute__((constructor)) static void __bt_init_rt(){");
#यदि_परिभाषितम् TCC_TARGET_PE
    यदि (s1->output_type == TCC_OUTPUT_DLL)
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
        cstr_printf(&cstr, "__bt_init_dll(%d);", s1->do_bounds_check);
#अन्यथा
        cstr_printf(&cstr, "__bt_init_dll(0);");
#यदि_अन्तः
#यदि_अन्तः
    cstr_printf(&cstr, "__bt_init(__rt_info,%d);}",
        s1->output_type != TCC_OUTPUT_DLL);
    /* In case dlcose is called by application */
    cstr_printf(&cstr,
        "__attribute__((destructor)) static void __bt_exit_rt(){"
        "__bt_exit(__rt_info);}");
    tcc_compile_string_no_debug(s1, cstr.दत्त);
    cstr_free(&cstr);
    समुच्चयः_local_sym(s1, __rt_info, s, o);
}
#यदि_अन्तः /* def CONFIG_TCC_BACKTRACE */

स्थिर शून्य tcc_tcov_सङ्कलय_file(TCCState *s1, ध्रुव वर्ण *filename)
{
    CString cstr;
    शून्य *ptr;
    वर्ण wd[1024];

    यदि (tcov_section == रिक्त)
        प्रत्यागम;
    section_ptr_सङ्कलय(tcov_section, 1);
    write32le (tcov_section->दत्त, tcov_section->दत्त_विस्थापनम्);

    cstr_new (&cstr);
    यदि (filename[0] == '/')
        cstr_printf (&cstr, "%s.tcov", filename);
    अन्यथा {
        getcwd (wd, परिमाण(wd));
        cstr_printf (&cstr, "%s/%s.tcov", wd, filename);
    }
    ptr = section_ptr_सङ्कलय(tcov_section, cstr.आकार + 1);
    वाक्यं_प्रतिलिख((वर्ण *)ptr, cstr.दत्त);
    unlink((वर्ण *)ptr);
#यदि_परिभाषितम् _WIN32
    normalize_slashes((वर्ण *)ptr);
#यदि_अन्तः
    cstr_free (&cstr);

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern char *__tcov_data[];"
        "extern void __store_test_coverage ();"
        "__attribute__((destructor)) static void __tcov_exit() {"
        "__store_test_coverage(__tcov_data);"
        "}");
    tcc_compile_string_no_debug(s1, cstr.दत्त);
    cstr_free(&cstr);
    समुच्चयः_local_sym(s1, &"___tcov_data"[!s1->leading_underscore], tcov_section, 0);
}

#यदि_परिभाषितम् TCC_TARGET_UNIX
/* add libc crt1/crti objects */
ST_FUNC शून्य tccelf_सङ्कलय_crtbegin(TCCState *s1)
{
#यदि TARGETOS_OpenBSD
    यदि (s1->output_type != TCC_OUTPUT_DLL)
        tcc_सङ्कलय_crt(s1, "crt0.o");
    यदि (s1->output_type == TCC_OUTPUT_DLL)
        tcc_सङ्कलय_crt(s1, "crtbeginS.o");
    अन्यथा
        tcc_सङ्कलय_crt(s1, "crtbegin.o");
#नोचेद्यदि TARGETOS_FreeBSD || TARGETOS_NetBSD
    यदि (s1->output_type != TCC_OUTPUT_DLL)
#यदि TARGETOS_FreeBSD
        tcc_सङ्कलय_crt(s1, "crt1.o");
#अन्यथा
        tcc_सङ्कलय_crt(s1, "crt0.o");
#यदि_अन्तः
    tcc_सङ्कलय_crt(s1, "crti.o");
    यदि (s1->static_link)
        tcc_सङ्कलय_crt(s1, "crtbeginT.o");
    अन्यथा यदि (s1->output_type == TCC_OUTPUT_DLL)
        tcc_सङ्कलय_crt(s1, "crtbeginS.o");
    अन्यथा
        tcc_सङ्कलय_crt(s1, "crtbegin.o");
#नोचेद्यदि TARGETOS_ANDROID
    यदि (s1->output_type == TCC_OUTPUT_DLL)
        tcc_सङ्कलय_crt(s1, "crtbegin_so.o");
    अन्यथा
        tcc_सङ्कलय_crt(s1, "crtbegin_dynamic.o");
#अन्यथा
    यदि (s1->output_type != TCC_OUTPUT_DLL)
        tcc_सङ्कलय_crt(s1, "crt1.o");
    tcc_सङ्कलय_crt(s1, "crti.o");
#यदि_अन्तः
}

ST_FUNC शून्य tccelf_सङ्कलय_crtend(TCCState *s1)
{
#यदि TARGETOS_OpenBSD
    यदि (s1->output_type == TCC_OUTPUT_DLL)
        tcc_सङ्कलय_crt(s1, "crtendS.o");
    अन्यथा
        tcc_सङ्कलय_crt(s1, "crtend.o");
#नोचेद्यदि TARGETOS_FreeBSD || TARGETOS_NetBSD
    यदि (s1->output_type == TCC_OUTPUT_DLL)
        tcc_सङ्कलय_crt(s1, "crtendS.o");
    अन्यथा
        tcc_सङ्कलय_crt(s1, "crtend.o");
    tcc_सङ्कलय_crt(s1, "crtn.o");
#नोचेद्यदि TARGETOS_ANDROID
    यदि (s1->output_type == TCC_OUTPUT_DLL)
        tcc_सङ्कलय_crt(s1, "crtend_so.o");
    अन्यथा
        tcc_सङ्कलय_crt(s1, "crtend_android.o");
#अन्यथा
    tcc_सङ्कलय_crt(s1, "crtn.o");
#यदि_अन्तः
}
#यदि_अन्तः /* TCC_TARGET_UNIX */

#यदि_अपरिभाषितम् TCC_TARGET_PE
/* add tcc runtime libraries */
ST_FUNC शून्य tcc_सङ्कलय_runtime(TCCState *s1)
{
    s1->filetype = 0;

#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    tcc_सङ्कलय_bcheck(s1);
#यदि_अन्तः
    tcc_सङ्कलय_pragma_libs(s1);

    /* add libc */
    यदि (!s1->nostdlib) {
        पूर्णाङ्क lpthread = s1->option_pthread;

#यदि_परिभाषितम् CONFIG_TCC_BCHECK
        यदि (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    यदि (s1->output_type == TCC_OUTPUT_स्मृतिः)
                tcc_सङ्कलय_support(s1, "bcheck_run.o");
	    अन्यथा
                tcc_सङ्कलय_support(s1, "bcheck.o");
# यदि !(TARGETOS_OpenBSD || TARGETOS_NetBSD)
            tcc_सङ्कलय_library(s1, "dl");
# endif
            lpthread = 1;
        }
#यदि_अन्तः
#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
        यदि (s1->do_backtrace) {
            यदि (s1->output_type & TCC_OUTPUT_EXE)
                tcc_सङ्कलय_support(s1, "bt-exe.o");
            यदि (s1->output_type != TCC_OUTPUT_DLL)
                tcc_सङ्कलय_support(s1, "bt-log.o");
            tcc_सङ्कलय_btstub(s1);
            lpthread = 1;
        }
#यदि_अन्तः
        यदि (lpthread)
            tcc_सङ्कलय_library(s1, "pthread");
        tcc_सङ्कलय_library(s1, "c");
#यदि_परिभाषितम् TCC_LIBGCC
        यदि (!s1->static_link) {
            यदि (TCC_LIBGCC[0] == '/')
                tcc_सङ्कलय_file(s1, TCC_LIBGCC);
            अन्यथा
                tcc_सङ्कलय_dll(s1, TCC_LIBGCC, AFF_PRINT_ERROR);
        }
#यदि_अन्तः
#यदि defined TCC_TARGET_ARM && TARGETOS_FreeBSD
        tcc_सङ्कलय_library(s1, "gcc_s"); // unwind code
#यदि_अन्तः
        यदि (TCC_LIBTCC1[0]) {
            tcc_सङ्कलय_support(s1, TCC_LIBTCC1);
            tcc_सङ्कलय_library(s1, "c");
        }
#यदि_अपरिभाषितम् TCC_TARGET_MACHO
        यदि (s1->output_type != TCC_OUTPUT_स्मृतिः)
            tccelf_सङ्कलय_crtend(s1);
#यदि_अन्तः
    }
}
#यदि_अन्तः /* ndef TCC_TARGET_PE */

/* set _etext/_edata/_end  f=0:set  f=1:when_needed  f=2,3:just_update */
स्थिर शून्य समुच्चयः_linker_sym(TCCState *s1, ध्रुव वर्ण *name, Section *sec, पूर्णाङ्क f)
{
    पूर्णाङ्क sym_सूचकांक, esym_सूचकांक, defined;
    ElfW(Sym) *sym, *esym;
    sym_सूचकांक = find_elf_sym(symtab_section, name);
    sym = (ElfW(Sym) *)symtab_section->दत्त + sym_सूचकांक;
    esym_सूचकांक = find_elf_sym(s1->dynsymtab_section, name);
    esym = (ElfW(Sym) *)s1->dynsymtab_section->दत्त + esym_सूचकांक;
    defined = sym->st_shndx != SHN_UNDEF
        || (esym->st_shndx != SHN_UNDEF && esym->st_आकार);
    विकल्प (f) {
    पक्ष 1: /* old symbols w/o '_' */
        यदि (!(sym_सूचकांक || esym_सूचकांक) || defined)
            भङ्ग;
    पक्ष 0:
        यदि (defined) {
            tcc_warning("linker symbol '%s' already defined", name);
            भङ्ग;
        }
        sym_सूचकांक = समुच्चयः_global_sym(s1, name, sec, -1);
        get_sym_attr(s1, sym_सूचकांक, 1)->linker_sym = 1;
        भङ्ग;
    स्वभाव: /* update (bss only) */
        यदि (get_sym_attr(s1, sym_सूचकांक, 0)->linker_sym)
            sym->st_मानम् = sec->दत्त_विस्थापनम्;
    }
#यदि_अपरिभाषितम् ELF_OBJ_ONLY
    यदि (name[0] == '_')
        समुच्चयः_linker_sym(s1, name + 1, sec, f + 1);
#यदि_अन्तः
}

/* add various standard linker symbols (must be done after the
   sections are filled (for example after allocating common
   symbols)) */
स्थिर शून्य tcc_सङ्कलय_linker_symbols(TCCState *s1)
{
    वर्ण buf[1024];
    पूर्णाङ्क i;
    Section *s;

    समुच्चयः_linker_sym(s1, "_etext", text_section, 0);
    समुच्चयः_linker_sym(s1, "_edata", दत्त_section, 0);
    समुच्चयः_linker_sym(s1, "_end", bss_section, 0);
#यदि TARGETOS_OpenBSD
    समुच्चयः_global_sym(s1, "__executable_start", रिक्त, ELF_START_ADDR);
#यदि_अन्तः

#यदि_परिभाषितम् TCC_TARGET_RISCV64
    /* XXX should be .sdata+0x800, not .data+0x800 */
    समुच्चयः_global_sym(s1, "__global_pointer$", दत्त_section, 0x800);
#यदि_अन्तः
    /* horrible new standard ldscript defines */
    सङ्कलय_init_array_परिभाषते(s1, ".preinit_array");
    सङ्कलय_init_array_परिभाषते(s1, ".init_array");
    सङ्कलय_init_array_परिभाषते(s1, ".fini_array");
    /* add start and stop symbols for sections whose name can be
       expressed in C */
    प्रति(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        यदि ((s->sh_flags & SHF_ALLOC)
            && (s->sh_type == SHT_PROGBITS || s->sh_type == SHT_NOBITS
                || s->sh_type == SHT_STRTAB)) {
            /* check if section name can be expressed in C */
            ध्रुव वर्ण *p0, *p;
            p0 = s->name;
            यदि (*p0 == '.')
                ++p0;
            p = p0;
            प्रति(;;) {
                पूर्णाङ्क c = *p;
                यदि (!c)
                    भङ्ग;
                यदि (!isid(c) && !isnum(c))
                    गच्छ अग्र_sec;
                p++;
            }
            snprintf(buf, परिमाण(buf), "__start_%s", p0);
            समुच्चयः_global_sym(s1, buf, s, 0);
            snprintf(buf, परिमाण(buf), "__stop_%s", p0);
            समुच्चयः_global_sym(s1, buf, s, -1);
        }
    अग्र_sec: ;
    }
}

ST_FUNC शून्य resolve_common_syms(TCCState *s1)
{
    ElfW(Sym) *sym;

    /* Allocate common symbols in BSS.  */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        यदि (sym->st_shndx == SHN_COMMON && sym->st_आकार) {
            /* symbol alignment is in st_value for SHN_COMMONs */
	    sym->st_मानम् = section_सङ्कलय(bss_section, sym->st_आकार,
					sym->st_मानम्);
            sym->st_shndx = bss_section->sh_अङ्कः;
        }
    }

    /* Now assign linker provided symbols their value.  */
    यदि (s1->output_type != TCC_OUTPUT_DLL)
        tcc_सङ्कलय_linker_symbols(s1);
}

#यदि_अपरिभाषितम् ELF_OBJ_ONLY
ST_FUNC शून्य fill_got_प्रविष्टिः(TCCState *s1, ElfW_Rel *rel)
{
    पूर्णाङ्क sym_सूचकांक = ELFW(R_SYM) (rel->r_info);
    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->दत्त)[sym_सूचकांक];
    संरचना sym_attr *attr = get_sym_attr(s1, sym_सूचकांक, 0);
    अचिह्नित विस्थापनम् = attr->got_विस्थापनम्;

    यदि (0 == विस्थापनम्)
        प्रत्यागम;
    section_reserve(s1->got, विस्थापनम् + PTR_आकार);
#यदि PTR_आकार == 8
    write64le(s1->got->दत्त + विस्थापनम्, sym->st_मानम्);
#अन्यथा
    write32le(s1->got->दत्त + विस्थापनम्, sym->st_मानम्);
#यदि_अन्तः
}

/* Perform relocation to GOT or PLT entries */
ST_FUNC शून्य fill_got(TCCState *s1)
{
    Section *s;
    ElfW_Rel *rel;
    पूर्णाङ्क i;

    प्रति(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        यदि (s->sh_type != SHT_RELX)
            अनुवर्त;
        /* no need to handle got relocations */
        यदि (s->link != symtab_section)
            अनुवर्त;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            विकल्प (ELFW(R_TYPE) (rel->r_info)) {
                पक्ष R_X86_64_GOT32:
                पक्ष R_X86_64_GOTPCREL:
		पक्ष R_X86_64_GOTPCRELX:
		पक्ष R_X86_64_REX_GOTPCRELX:
                पक्ष R_X86_64_PLT32:
                    fill_got_प्रविष्टिः(s1, rel);
                    भङ्ग;
            }
        }
    }
}

/* See put_got_entry for a description.  This is the second stage
   where GOT references to local defined symbols are rewritten.  */
स्थिर शून्य fill_local_got_entries(TCCState *s1)
{
    ElfW_Rel *rel;
    यदि (!s1->got->reloc)
        प्रत्यागम;
    for_each_elem(s1->got->reloc, 0, rel, ElfW_Rel) {
	यदि (ELFW(R_TYPE)(rel->r_info) == R_RELATIVE) {
	    पूर्णाङ्क sym_सूचकांक = ELFW(R_SYM) (rel->r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->दत्त)[sym_सूचकांक];
	    संरचना sym_attr *attr = get_sym_attr(s1, sym_सूचकांक, 0);
	    अचिह्नित विस्थापनम् = attr->got_विस्थापनम्;
	    यदि (विस्थापनम् != rel->r_विस्थापनम् - s1->got->sh_addr)
	        tcc_error_noabort("fill_local_got_entries: huh?");
	    rel->r_info = ELFW(R_INFO)(0, R_RELATIVE);
#यदि SHT_RELX == SHT_RELA
	    rel->r_addend = sym->st_मानम्;
#अन्यथा
	    /* All our REL architectures also happen to be 32bit LE.  */
	    write32le(s1->got->दत्त + विस्थापनम्, sym->st_मानम्);
#यदि_अन्तः
	}
    }
}

/* Bind symbols of executable: resolve undefined symbols from exported symbols
   in shared libraries */
स्थिर शून्य bind_exe_dynsyms(TCCState *s1, पूर्णाङ्क is_PIE)
{
    ध्रुव वर्ण *name;
    पूर्णाङ्क sym_सूचकांक, सूचकांक;
    ElfW(Sym) *sym, *esym;
    पूर्णाङ्क type;

    /* Resolve undefined symbols from dynamic symbols. When there is a match:
       - if STT_FUNC or STT_GNU_IFUNC symbol -> add it in PLT
       - if STT_OBJECT symbol -> add it in .bss section with suitable reloc */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        यदि (sym->st_shndx == SHN_UNDEF
            /* bss symbols may be initialized in the shared library */
            || sym->st_shndx == SHN_COMMON
            || sym->st_shndx == bss_section->sh_अङ्कः) {
            name = (वर्ण *) symtab_section->link->दत्त + sym->st_name;
            sym_सूचकांक = find_elf_sym(s1->dynsymtab_section, name);
            esym = &((ElfW(Sym) *)s1->dynsymtab_section->दत्त)[sym_सूचकांक];
            यदि (sym_सूचकांक && esym->st_shndx != SHN_UNDEF) {
                यदि (is_PIE)
                    अनुवर्त;
                type = ELFW(ST_TYPE)(esym->st_info);
                यदि ((type == STT_FUNC) || (type == STT_GNU_IFUNC)) {
                    /* Indirect functions shall have STT_FUNC type in executable
                     * dynsym section. Indeed, a dlsym call following a lazy
                     * resolution would pick the symbol value from the
                     * executable dynsym entry which would contain the address
                     * of the function wanted by the caller of dlsym instead of
                     * the address of the function that would return that
                     * address */
                    पूर्णाङ्क dynindex
		      = put_elf_sym(s1->dynsym, 0, esym->st_आकार,
				    ELFW(ST_INFO)(STB_GLOBAL,STT_FUNC), 0, 0,
				    name);
		    पूर्णाङ्क सूचकांक = sym - (ElfW(Sym) *) symtab_section->दत्त;
		    get_sym_attr(s1, सूचकांक, 1)->dyn_सूचकांक = dynindex;
                } अन्यथा यदि (type == STT_OBJECT) {
                    अचिह्नित दीर्घ विस्थापनम्;
                    ElfW(Sym) *dynsym;
                    यदि (sym->st_shndx == bss_section->sh_अङ्कः) {
                        विस्थापनम् = sym->st_मानम्;
                    } अन्यथा {
                        विस्थापनम् = bss_section->दत्त_विस्थापनम्;
                        /* XXX: which alignment ? */
                        विस्थापनम् = (विस्थापनम् + 16 - 1) & -16;
                        bss_section->दत्त_विस्थापनम् = विस्थापनम् + esym->st_आकार;
                    }
                    समुच्चयः_elf_sym (s1->symtab, विस्थापनम्, esym->st_आकार,
                                 esym->st_info, 0, bss_section->sh_अङ्कः, name);
                    सूचकांक = put_elf_sym(s1->dynsym, विस्थापनम्, esym->st_आकार,
                                        esym->st_info, 0, bss_section->sh_अङ्कः,
                                        name);
                    /* Ensure R_COPY works for weak symbol aliases */
                    यदि (ELFW(ST_BIND)(esym->st_info) == STB_WEAK) {
                        for_each_elem(s1->dynsymtab_section, 1, dynsym, ElfW(Sym)) {
                            यदि ((dynsym->st_मानम् == esym->st_मानम्)
                                && (ELFW(ST_BIND)(dynsym->st_info) == STB_GLOBAL)) {
                                वर्ण *dynname = (वर्ण *) s1->dynsymtab_section->link->दत्त
                                                + dynsym->st_name;
                                put_elf_sym(s1->dynsym, विस्थापनम्, dynsym->st_आकार,
                                            dynsym->st_info, 0,
                                            bss_section->sh_अङ्कः, dynname);
                                भङ्ग;
                            }
                        }
                    }
                    put_elf_reloc(s1->dynsym, bss_section,
                                  विस्थापनम्, R_COPY, सूचकांक);
                }
            } अन्यथा यदि (sym->st_shndx == SHN_UNDEF) {
                /* STB_WEAK undefined symbols are accepted */
                /* XXX: _fp_hw seems to be part of the ABI, so we ignore it */
                यदि (ELFW(ST_BIND)(sym->st_info) == STB_WEAK ||
                    !वाक्यं_तुलय(name, "_fp_hw")) {
                } अन्यथा {
                    tcc_error_noabort("unresolved reference to '%s'", name);
                }
            }
        }
    }
    /* update _end symbol with new bss length */
    समुच्चयः_linker_sym(s1, "_end", bss_section, 2);
}

/* Bind symbols of libraries: export all non local symbols of executable that
   are referenced by shared libraries. The reason is that the dynamic loader
   search symbol first in executable and then in libraries. Therefore a
   reference to a symbol already defined by a library can still be resolved by
   a symbol in the executable.   With -rdynamic, export all defined symbols */
स्थिर शून्य bind_libs_dynsyms(TCCState *s1)
{
    ध्रुव वर्ण *name;
    पूर्णाङ्क dynsym_सूचकांक;
    ElfW(Sym) *sym, *esym;

    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        name = (वर्ण *)symtab_section->link->दत्त + sym->st_name;
        dynsym_सूचकांक = find_elf_sym(s1->dynsymtab_section, name);
        यदि (sym->st_shndx != SHN_UNDEF) {
            यदि (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL
                && (dynsym_सूचकांक || s1->rdynamic))
                समुच्चयः_elf_sym(s1->dynsym, sym->st_मानम्, sym->st_आकार,
                            sym->st_info, 0, sym->st_shndx, name);
        } अन्यथा यदि (dynsym_सूचकांक) {
            esym = (ElfW(Sym) *)s1->dynsymtab_section->दत्त + dynsym_सूचकांक;
            यदि (esym->st_shndx == SHN_UNDEF) {
                /* weak symbols can stay undefined */
                यदि (ELFW(ST_BIND)(esym->st_info) != STB_WEAK)
                    tcc_warning("unresolved dynamic reference to '%s'", name);
            }
        }
    }
}

/* Export all non local symbols. This is used by shared libraries so that the
   non local symbols they define can resolve a reference in another shared
   library or in the executable. Correspondingly, it allows undefined local
   symbols to be resolved by other shared libraries or by the executable. */
स्थिर शून्य export_global_syms(TCCState *s1)
{
    पूर्णाङ्क dynindex, सूचकांक;
    ध्रुव वर्ण *name;
    ElfW(Sym) *sym;
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        यदि (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
	    name = (वर्ण *) symtab_section->link->दत्त + sym->st_name;
	    dynindex = समुच्चयः_elf_sym(s1->dynsym, sym->st_मानम्, sym->st_आकार,
				   sym->st_info, 0, sym->st_shndx, name);
	    सूचकांक = sym - (ElfW(Sym) *) symtab_section->दत्त;
            get_sym_attr(s1, सूचकांक, 1)->dyn_सूचकांक = dynindex;
        }
    }
}

/* decide if an unallocated section should be output. */
स्थिर पूर्णाङ्क समुच्चयः_sec_sizes(TCCState *s1)
{
    पूर्णाङ्क i;
    Section *s;
    पूर्णाङ्क textrel = 0;
    पूर्णाङ्क file_type = s1->output_type;

    /* Allocate strings for section names */
    प्रति(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        यदि (s->sh_type == SHT_RELX && !(s->sh_flags & SHF_ALLOC)) {
            /* when generating a DLL, we include relocations but
               we may patch them */
            यदि ((file_type & TCC_OUTPUT_DYN)
                && (s1->sections[s->sh_info]->sh_flags & SHF_ALLOC)) {
                पूर्णाङ्क गणनम्_2 = prepare_dynamic_rel(s1, s);
                यदि (गणनम्_2) {
                    /* allocate the section */
                    s->sh_flags |= SHF_ALLOC;
                    s->sh_आकार = गणनम्_2 * परिमाण(ElfW_Rel);
                    यदि (s1->sections[s->sh_info]->sh_flags & SHF_EXECINSTR)
                        textrel += गणनम्_2;
                }
            }
        } अन्यथा यदि ((s->sh_flags & SHF_ALLOC)
#यदि_परिभाषितम् TCC_TARGET_ARM
                   || s->sh_type == SHT_ARM_गुणाः
#यदि_अन्तः
                   || s1->do_debug) {
            s->sh_आकार = s->दत्त_विस्थापनम्;
        }
    }
    प्रत्यागम textrel;
}

/* various data used under elf_output_file() */
संरचना dyn_inf {
    Section *dynamic;
    Section *dynstr;
    Section *interp;
    Section *note;
    Section *gnu_hash;
    संरचना {
        /* Info to be copied in dynamic section */
        अचिह्नित दीर्घ दत्त_विस्थापनम्;
        addr_t rel_addr;
        addr_t rel_आकार;
    };

    ElfW(Phdr) *phdr;
    पूर्णाङ्क phnum;
    पूर्णाङ्क shnum;
    पूर्णाङ्क tls;
    पूर्णाङ्क relro;
    पूर्णाङ्क notes;
    पूर्णाङ्क ehfr;
    पूर्णाङ्क dyna;
};

/* Decide the layout of sections loaded in memory. This must be done before
   program headers are filled since they contain info about the layout.
   We do the following ordering: interp, symbol tables, relocations, progbits,
   nobits */
स्थिर पूर्णाङ्क क्रमय_sections(TCCState *s1, पूर्णाङ्क *sec_क्रमः, संरचना dyn_inf *d)
{
    Section *s;
    पूर्णाङ्क i, j, k, f, f0, n;
    पूर्णाङ्क nb_sections = s1->nb_sections;
    पूर्णाङ्क *sec_cls = sec_क्रमः + nb_sections;
    पूर्णाङ्क tls_align = 0; /* need common alignment for all tls sections */

    प्रति (i = 1; i < nb_sections; i++) {
        s = s1->sections[i];
        यदि (0 == s->sh_name) {
            j = 0x900; /* no sh_name: won't go to file */
        } अन्यथा यदि (s->sh_flags & SHF_ALLOC) {
            j = 0x100;
            यदि ((s->sh_flags & (SHF_WRITE|SHF_TLS)) == SHF_WRITE)
                j = 0x200;
        } अन्यथा {
            j = 0x700;
        }
        यदि (j >= 0x700 && s1->output_format != TCC_OUTPUT_FORMAT_ELF)
            s->sh_आकार = 0, j = 0x900;

        यदि (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM) {
            k = 0x10;
        } अन्यथा यदि (s->sh_type == SHT_STRTAB && वाक्यं_तुलय(s->name, ".stabstr")) {
            k = 0x11;
            यदि (i == nb_sections - 1) /* ".shstrtab" assumed to stay last */
                k = 0xff;
        } अन्यथा यदि (s->sh_type == SHT_HASH || s->sh_type == SHT_GNU_HASH) {
            k = 0x12;
        } अन्यथा यदि (s->sh_type == SHT_GNU_verdef
                  || s->sh_type == SHT_GNU_verneed
                  || s->sh_type == SHT_GNU_versym) {
            k = 0x13;
        } अन्यथा यदि (s->sh_type == SHT_RELX) {
            k = 0x20;
            यदि (s1->plt && s == s1->plt->reloc)
                k = 0x21;
        } अन्यथा यदि (s->sh_flags & SHF_EXECINSTR) {
            k = 0x60;
        /* RELRO sections --> */
        } अन्यथा यदि (s->sh_flags & SHF_TLS) {
            यदि (s->sh_addralign > tls_align)
                tls_align = s->sh_addralign;
            k = 0x40 + (s->sh_type == SHT_NOBITS);
        } अन्यथा यदि (s->sh_type == SHT_PREINIT_ARRAY) {
            k = 0x42;
        } अन्यथा यदि (s->sh_type == SHT_INIT_ARRAY) {
            k = 0x43;
        } अन्यथा यदि (s->sh_type == SHT_FINI_ARRAY) {
            k = 0x44;
        } अन्यथा यदि (s->sh_type == SHT_DYNAMIC) {
            k = 0x48;
        } अन्यथा यदि (s == s1->got) {
            k = 0x49; /* .got as RELRO needs BIND_NOW in DT_FLAGS */
        } अन्यथा यदि (s->reloc && (s->reloc->sh_flags & SHF_ALLOC) && j == 0x100) {
            k = 0x45; /* +1 for data.ro */
        /* <-- */
        } अन्यथा यदि (s->sh_type == SHT_NOTE) {
            k = 0x08, d->notes = 1;
        } अन्यथा यदि (s->sh_type == SHT_NOBITS) {
            k = 0x70; /* bss */
        } अन्यथा यदि (s == d->interp) {
            k = 0x00;
        } अन्यथा {
            k = 0x50; /*दत्त*/
        }
        k += j;
        /* make our standard sections come last to have _etext/_edata correct values */
        यदि (s->sh_अङ्कः <= bss_section->sh_अङ्कः)
            ++k;
        /* make RELRO section writable */
        यदि ((k & 0xfff0) == 0x140)
            k += 0x100, s->sh_flags |= SHF_WRITE;
        /* sort by insert */
        प्रति (n = i; n > 1 && k < (f = sec_cls[n - 1]); --n)
            sec_cls[n] = f, sec_क्रमः[n] = sec_क्रमः[n - 1];
        sec_cls[n] = k, sec_क्रमः[n] = i;
    }
    sec_क्रमः[0] = 0;
    d->shnum = 1;

#परिभाषय SHFX_NEWPH (1 << 4)
#परिभाषय SHFX_RELRO (1 << 5)

    /* count PT_LOAD headers needed */
    n = f0 = 0;
    प्रति (i = 1; i < nb_sections; i++) {
        s = s1->sections[sec_क्रमः[i]];
        k = sec_cls[i];
        f = 0;
        यदि (k < 0x900)
            ++d->shnum;
        यदि (k < 0x700) {
            f = s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR);
#यदि TARGETOS_NetBSD || TARGETOS_FreeBSD
	    /* NetBSD only supports 2 PT_LOAD sections.
	       See: https://blog.netbsd.org/tnf/entry/the_first_report_on_lld */
	    यदि ((f & SHF_WRITE) == 0)
                f |= SHF_EXECINSTR;
            k = 0; /* no relro */
#यदि_अन्तः
            यदि ((k & 0xfff0) == 0x240) /* RELRO sections */
                d->relro = 1, f |= SHFX_RELRO;
            /* start new header when flags changed, but avoid zero memsz */
            यदि (f != f0 && s->sh_आकार)
                f0 = f, ++n, f |= SHFX_NEWPH;
            यदि ((s->sh_flags & SHF_TLS) && s->sh_आकार) {
                s->sh_addralign = tls_align;
                d->tls = 1, f |= SHF_TLS;
            }
        }
        sec_cls[i] = f;
        //printf("ph %d sec %02d : %3X %3X  %8.2X  %04X  %s\n", (f>0) * n, i, f, k, s->sh_type, (int)s->sh_size, s->name);
    }
    प्रत्यागम n;
}

स्थिर ElfW(Phdr) *fill_phdr(ElfW(Phdr) *ph, पूर्णाङ्क type, Section *s)
{
    ph->p_type = type;
    ph->p_flags = PF_R;
    यदि (s) {
        यदि (s->sh_flags & SHF_WRITE)
            ph->p_flags |= PF_W;
        ph->p_विस्थापनम् = s->sh_विस्थापनम्;
        ph->p_vaddr = s->sh_addr;
        ph->p_filesz = s->sh_आकार;
        ph->p_align = s->sh_addralign;
    }
    ph->p_paddr = ph->p_vaddr;
    ph->p_memsz = ph->p_filesz;
    प्रत्यागम ph;
}

स्थिर ElfW(Phdr) *update_phdr(ElfW(Phdr) *ph, पूर्णाङ्क type, Section *s, addr_t addr, पूर्णाङ्क file_विस्थापनम्)
{
    यदि (ph->p_type == 0) {
        fill_phdr(ph, type, s);
    }
    ph->p_filesz = file_विस्थापनम् - ph->p_विस्थापनम्;
    ph->p_memsz = addr - ph->p_vaddr;
    प्रत्यागम ph;
}

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
स्थिर पूर्णाङ्क layout_sections(TCCState *s1, पूर्णाङ्क *sec_क्रमः, संरचना dyn_inf *d)
{
    Section *s;
    addr_t addr, tmp, align, s_align, आधारः;
    ElfW(Phdr) *ph = रिक्त, *ph2;
    पूर्णाङ्क i, f, n, phnum, phfill;
    पूर्णाङ्क file_विस्थापनम्;

    /* compute number of program headers */
    phnum = क्रमय_sections(s1, sec_क्रमः, d);
    phfill = 0; /* set to 1 to have dll's with a PT_PHDR */
    यदि (d->interp)
        phfill = 2;
    phnum += phfill;
    यदि (d->dynamic)
        d->dyna = phnum++;
    यदि (d->notes)
        d->notes = phnum++;
    यदि (d->tls)
        d->tls = phnum++;
    यदि (eh_frame_hdr_section)
        d->ehfr = phnum++;
    यदि (d->relro)
        d->relro = phnum++;
    d->phnum = phnum;
    d->phdr = tcc_mallocz(phnum * परिमाण(ElfW(Phdr)));

    file_विस्थापनम् = 0;
    यदि (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
        file_विस्थापनम् = (परिमाण(ElfW(Ehdr)) + phnum * परिमाण(ElfW(Phdr)) + 3) & -4;
        file_विस्थापनम् += d->shnum * परिमाण (ElfW(Shdr));
    }

    s_align = ELF_PAGE_आकार;
    यदि (s1->section_align)
        s_align = s1->section_align;

    addr = ELF_START_ADDR;
    यदि (s1->output_type & TCC_OUTPUT_DYN)
        addr = 0;

    यदि (s1->has_text_addr) {
        addr = s1->text_addr;
        यदि (0) {
            पूर्णाङ्क a_विस्थापनम्, p_विस्थापनम्;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_विस्थापनम् = (पूर्णाङ्क) (addr & (s_align - 1));
            p_विस्थापनम् = file_विस्थापनम् & (s_align - 1);
            यदि (a_विस्थापनम् < p_विस्थापनम्)
                a_विस्थापनम् += s_align;
            file_विस्थापनम् += (a_विस्थापनम् - p_विस्थापनम्);
        }
    }
    आधारः = addr;
    /* compute address after headers */
    addr += file_विस्थापनम्;

    n = 0;
    प्रति(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_क्रमः[i]];
        f = sec_क्रमः[i + s1->nb_sections];
        align = s->sh_addralign - 1;

        यदि (f == 0) { /* no alloc */
            file_विस्थापनम् = (file_विस्थापनम् + align) & ~align;
            s->sh_विस्थापनम् = file_विस्थापनम्;
            यदि (s->sh_type != SHT_NOBITS)
                file_विस्थापनम् += s->sh_आकार;
            अनुवर्त;
        }

        यदि ((f & SHFX_NEWPH) && n) {
            /* different rwx section flags */
            यदि (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
                /* if in the middle of a page, w e duplicate the page in
                   memory so that one copy is RX and the other is RW */
                यदि ((addr & (s_align - 1)) != 0)
                    addr += s_align;
            } अन्यथा {
                align = s_align - 1;
            }
        }

        tmp = addr;
        addr = (addr + align) & ~align;
        file_विस्थापनम् += (पूर्णाङ्क)(addr - tmp);
        s->sh_विस्थापनम् = file_विस्थापनम्;
        s->sh_addr = addr;

        //printf("%d : %08x %08x %04x %03x %s %d\n", n, (int)file_offset, (int)addr, (int)s->sh_size, s->sh_type, s->name, align + 1);
        addr += s->sh_आकार;
        यदि (s->sh_type != SHT_NOBITS)
            file_विस्थापनम् += s->sh_आकार;

        यदि (f & SHFX_NEWPH) {
            /* set new program header */
            ph = &d->phdr[phfill + n];
            fill_phdr(ph, PT_आरोपय, s);
            ph->p_align = s_align;
            यदि (f & SHF_EXECINSTR)
                ph->p_flags |= PF_X;
            यदि (n == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_विस्थापनम् = 0;
                ph->p_paddr = ph->p_vaddr = आधारः;
            }
            ++n;
        }

        यदि (ph)
            update_phdr(ph, 0, 0, addr, file_विस्थापनम्);

        यदि (f & SHFX_RELRO) {
            ph2 = update_phdr(&d->phdr[d->relro], PT_GNU_RELRO, s, addr, file_विस्थापनम्);
            ph2->p_align = 1;
        }
        यदि (f & SHF_TLS) {
            ph2 = update_phdr(&d->phdr[d->tls], PT_TLS, s, addr, file_विस्थापनम्);
            यदि (s->sh_type == SHT_NOBITS)
                addr -= s->sh_आकार;
            /* for xxx-link.c:relocate() */
            s1->tls_start = ph2->p_vaddr;
            s1->tls_अन्तः = s1->tls_start + ph2->p_memsz + (-ph2->p_memsz & (ph2->p_align - 1));
        }
        यदि (s->sh_type == SHT_NOTE) {
            update_phdr(&d->phdr[d->notes], PT_NOTE, s, addr, file_विस्थापनम्);
        }
    }

    /* Fill other headers */
    यदि (d->dyna)
        fill_phdr(&d->phdr[d->dyna], PT_DYNAMIC, d->dynamic);
    यदि (d->ehfr)
        fill_phdr(&d->phdr[d->ehfr], PT_GNU_EH_FRAME, eh_frame_hdr_section);
    यदि (d->interp)
        fill_phdr(&d->phdr[1], PT_INTERP, d->interp);
    यदि (phfill) {
        ph = &d->phdr[0];
        ph->p_विस्थापनम् = परिमाण(ElfW(Ehdr));
        ph->p_vaddr = आधारः + ph->p_विस्थापनम्;
        ph->p_filesz = phnum * परिमाण(ElfW(Phdr));
        ph->p_align = 4;
        fill_phdr(ph, PT_PHDR, रिक्त);
    }
    प्रत्यागम 0;
}

/* put dynamic tag */
स्थिर शून्य put_dt(Section *dynamic, पूर्णाङ्क dt, addr_t val)
{
    ElfW(Dyn) *dyn;
    dyn = section_ptr_सङ्कलय(dynamic, परिमाण(ElfW(Dyn)));
    dyn->d_चिह्नकम् = dt;
    dyn->d_un.d_val = val;
}

/* Fill the dynamic section with tags describing the address and size of
   sections */
स्थिर शून्य fill_dynamic(TCCState *s1, संरचना dyn_inf *dyninf)
{
    Section *dynamic = dyninf->dynamic;
    Section *s;

    /* put dynamic section entries */
    put_dt(dynamic, DT_HASH, s1->dynsym->hash->sh_addr);
    put_dt(dynamic, DT_GNU_HASH, dyninf->gnu_hash->sh_addr);
    put_dt(dynamic, DT_STRTAB, dyninf->dynstr->sh_addr);
    put_dt(dynamic, DT_SYMTAB, s1->dynsym->sh_addr);
    put_dt(dynamic, DT_STRSZ, dyninf->dynstr->दत्त_विस्थापनम्);
    put_dt(dynamic, DT_SYMENT, परिमाण(ElfW(Sym)));
#यदि PTR_आकार == 8
    put_dt(dynamic, DT_RELA, dyninf->rel_addr);
    put_dt(dynamic, DT_RELASZ, dyninf->rel_आकार);
    put_dt(dynamic, DT_RELAENT, परिमाण(ElfW_Rel));
    यदि (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->दत्त_विस्थापनम्);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_RELA);
    }
    put_dt(dynamic, DT_RELACOUNT, 0);
#अन्यथा
    put_dt(dynamic, DT_REL, dyninf->rel_addr);
    put_dt(dynamic, DT_RELSZ, dyninf->rel_आकार);
    put_dt(dynamic, DT_RELENT, परिमाण(ElfW_Rel));
    यदि (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->दत्त_विस्थापनम्);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_REL);
    }
    put_dt(dynamic, DT_RELCOUNT, 0);
#यदि_अन्तः
    यदि (versym_section && verneed_section) {
	/* The dynamic linker can not handle VERSYM without VERNEED */
        put_dt(dynamic, DT_VERSYM, versym_section->sh_addr);
        put_dt(dynamic, DT_VERNEED, verneed_section->sh_addr);
        put_dt(dynamic, DT_VERNEEDNUM, dt_verneednum);
    }
    s = have_section(s1, ".preinit_array");
    यदि (s && s->दत्त_विस्थापनम्) {
        put_dt(dynamic, DT_PREINIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_PREINIT_ARRAYSZ, s->दत्त_विस्थापनम्);
    }
    s = have_section(s1, ".init_array");
    यदि (s && s->दत्त_विस्थापनम्) {
        put_dt(dynamic, DT_INIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_INIT_ARRAYSZ, s->दत्त_विस्थापनम्);
    }
    s = have_section(s1, ".fini_array");
    यदि (s && s->दत्त_विस्थापनम्) {
        put_dt(dynamic, DT_FINI_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_FINI_ARRAYSZ, s->दत्त_विस्थापनम्);
    }
    s = have_section(s1, ".init");
    यदि (s && s->दत्त_विस्थापनम्) {
        put_dt(dynamic, DT_INIT, s->sh_addr);
    }
    s = have_section(s1, ".fini");
    यदि (s && s->दत्त_विस्थापनम्) {
        put_dt(dynamic, DT_FINI, s->sh_addr);
    }
    यदि (s1->do_debug)
        put_dt(dynamic, DT_DEBUG, 0);
    put_dt(dynamic, DT_NULL, 0);
}

/* Remove gaps between RELX sections.
   These gaps are a result of final_sections_reloc. Here some relocs are removed.
   The gaps are then filled with 0 in tcc_output_elf. The 0 is intepreted as
   R_...NONE reloc. This does work on most targets but on OpenBSD/arm64 this
   is illegal. OpenBSD/arm64 does not support R_...NONE reloc. */
स्थिर शून्य update_reloc_sections(TCCState *s1, संरचना dyn_inf *dyninf)
{
    पूर्णाङ्क i;
    अचिह्नित दीर्घ file_विस्थापनम् = 0;
    Section *s;
    Section *relocplt = s1->plt ? s1->plt->reloc : रिक्त;

    /* dynamic relocation table information, for .dynamic section */
    dyninf->rel_addr = dyninf->rel_आकार = 0;

    प्रति(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
	यदि (s->sh_type == SHT_RELX && s != relocplt) {
	    यदि (dyninf->rel_आकार == 0) {
		dyninf->rel_addr = s->sh_addr;
		file_विस्थापनम् = s->sh_विस्थापनम्;
	    }
	    अन्यथा {
		s->sh_addr = dyninf->rel_addr + dyninf->rel_आकार;
		s->sh_विस्थापनम् = file_विस्थापनम् + dyninf->rel_आकार;
	    }
	    dyninf->rel_आकार += s->sh_आकार;
	}
    }
}
#यदि_अन्तः /* ndef ELF_OBJ_ONLY */

/* Create an ELF file on disk.
   This function handle ELF specific layout requirements */
स्थिर पूर्णाङ्क tcc_output_elf(TCCState *s1, FILE *f, पूर्णाङ्क phnum, ElfW(Phdr) *phdr)
{
    पूर्णाङ्क i, shnum, विस्थापनम्, आकार, file_type;
    Section *s;
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) shdr, *sh;

    file_type = s1->output_type;
    shnum = s1->nb_sections;

    स्मृतिं_पूरय(&ehdr, 0, परिमाण(ehdr));
    यदि (phnum > 0) {
        ehdr.e_phentsize = परिमाण(ElfW(Phdr));
        ehdr.e_phnum = phnum;
        ehdr.e_phoff = परिमाण(ElfW(Ehdr));
    }

    /* fill header */
    ehdr.e_ident[0] = ELFMAG0;
    ehdr.e_ident[1] = ELFMAG1;
    ehdr.e_ident[2] = ELFMAG2;
    ehdr.e_ident[3] = ELFMAG3;
    ehdr.e_ident[4] = ELFCLASSW;
    ehdr.e_ident[5] = ELFDATA2LSB;
    ehdr.e_ident[6] = EV_CURRENT;

#यदि TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    ehdr.e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
#नोचेद्यदि TARGETOS_OpenBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_OPENBSD;
#नोचेद्यदि TARGETOS_NetBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_NETBSD;
#नोचेद्यदि defined TCC_TARGET_ARM && defined TCC_ARM_EABI
    ehdr.e_flags = EF_ARM_EABI_VER5;
    ehdr.e_flags |= s1->float_abi == ARM_HARD_FLOAT
        ? EF_ARM_VFP_FLOAT : EF_ARM_SOFT_FLOAT;
#नोचेद्यदि defined TCC_TARGET_ARM
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#नोचेद्यदि defined TCC_TARGET_RISCV64
    /* XXX should be configurable */
    ehdr.e_flags = EF_RISCV_FLOAT_ABI_DOUBLE;
#यदि_अन्तः

    यदि (file_type == TCC_OUTPUT_OBJ) {
        ehdr.e_type = ET_REL;
    } अन्यथा {
        यदि (file_type & TCC_OUTPUT_DYN)
            ehdr.e_type = ET_DYN;
        अन्यथा
            ehdr.e_type = ET_EXEC;
        यदि (s1->elf_entryname)
            ehdr.e_प्रविष्टिः = get_sym_addr(s1, s1->elf_entryname, 1, 0);
        अन्यथा
            ehdr.e_प्रविष्टिः = get_sym_addr(s1, "_start", !!(file_type & TCC_OUTPUT_EXE), 0);
        यदि (ehdr.e_प्रविष्टिः == (addr_t)-1)
            ehdr.e_प्रविष्टिः = text_section->sh_addr;
        यदि (s1->nb_errors)
            प्रत्यागम -1;
    }

    क्रमय_syms(s1, s1->symtab);

    ehdr.e_machine = EM_TCC_TARGET;
    ehdr.e_संस्करणम् = EV_CURRENT;
    ehdr.e_shoff = (परिमाण(ElfW(Ehdr)) + phnum * परिमाण(ElfW(Phdr)) + 3) & -4;
    ehdr.e_ehsize = परिमाण(ElfW(Ehdr));
    ehdr.e_shentsize = परिमाण(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    विस्थापनम् = fwrite(&ehdr, 1, परिमाण(ElfW(Ehdr)), f);
    यदि (phdr)
        विस्थापनम् += fwrite(phdr, 1, phnum * परिमाण(ElfW(Phdr)), f);

    /* output section headers */
    यावत् (विस्थापनम् < ehdr.e_shoff) {
        fputc(0, f);
        विस्थापनम्++;
    }

    प्रति(i = 0; i < shnum; i++) {
        sh = &shdr;
        स्मृतिं_पूरय(sh, 0, परिमाण(ElfW(Shdr)));
        यदि (i) {
            s = s1->sections[i];
            sh->sh_name = s->sh_name;
            sh->sh_type = s->sh_type;
            sh->sh_flags = s->sh_flags;
            sh->sh_entsize = s->sh_entsize;
            sh->sh_info = s->sh_info;
            यदि (s->link)
                sh->sh_link = s->link->sh_अङ्कः;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_विस्थापनम् = s->sh_विस्थापनम्;
            sh->sh_आकार = s->sh_आकार;
        }
        विस्थापनम् += fwrite(sh, 1, परिमाण(ElfW(Shdr)), f);
    }

    /* output sections */
    प्रति(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        यदि (s->sh_type != SHT_NOBITS) {
            यावत् (विस्थापनम् < s->sh_विस्थापनम्) {
                fputc(0, f);
                विस्थापनम्++;
            }
            आकार = s->sh_आकार;
            यदि (आकार)
                विस्थापनम् += fwrite(s->दत्त, 1, आकार, f);
        }
    }
    प्रत्यागम 0;
}

स्थिर पूर्णाङ्क tcc_output_द्विमान(TCCState *s1, FILE *f)
{
    Section *s;
    पूर्णाङ्क i, विस्थापनम्, आकार;

    विस्थापनम् = 0;
    प्रति(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[i];
        यदि (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            यावत् (विस्थापनम् < s->sh_विस्थापनम्) {
                fputc(0, f);
                विस्थापनम्++;
            }
            आकार = s->sh_आकार;
            fwrite(s->दत्त, 1, आकार, f);
            विस्थापनम् += आकार;
        }
    }
    प्रत्यागम 0;
}

/* Write an elf, coff or "binary" file */
स्थिर पूर्णाङ्क tcc_write_elf_file(TCCState *s1, ध्रुव वर्ण *filename, पूर्णाङ्क phnum,
                              ElfW(Phdr) *phdr)
{
    पूर्णाङ्क fd, बहुलकम्, file_type, ret;
    FILE *f;

    file_type = s1->output_type;
    यदि (file_type == TCC_OUTPUT_OBJ)
        बहुलकम् = 0666;
    अन्यथा
        बहुलकम् = 0777;
    unlink(filename);
    fd = उद्घाटय(filename, O_WRONLY | O_CREAT | O_TRUNC | O_द्विमान_2, बहुलकम्);
    यदि (fd < 0 || (f = fdopen(fd, "wb")) == रिक्त)
        प्रत्यागम tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
    यदि (s1->verbose)
        प्रारूप_लिख("<- %s\n", filename);
#यदि_परिभाषितम् TCC_TARGET_COFF
    यदि (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    अन्यथा
#यदि_अन्तः
    यदि (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        ret = tcc_output_elf(s1, f, phnum, phdr);
    अन्यथा
        ret = tcc_output_द्विमान(s1, f);
    fclose(f);

    प्रत्यागम ret;
}

#यदि_अपरिभाषितम् ELF_OBJ_ONLY
/* order sections according to sec_order, remove sections
   that we aren't going to output.  */
स्थिर शून्य reorder_sections(TCCState *s1, पूर्णाङ्क *sec_क्रमः)
{
    पूर्णाङ्क i, nnew, k, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    backmap = tcc_malloc(s1->nb_sections * परिमाण(backmap[0]));
    प्रति (i = 0, nnew = 0, snew = रिक्त; i < s1->nb_sections; i++) {
	k = sec_क्रमः ? sec_क्रमः[i] : i;
	s = s1->sections[k];
	यदि (!i || s->sh_name) {
	    backmap[k] = nnew;
            dynarray_सङ्कलय(&snew, &nnew, s);
	} अन्यथा {
	    backmap[k] = 0;
            /* just remember to free them later */
	    dynarray_सङ्कलय(&s1->priv_sections, &s1->nb_priv_sections, s);
	}
    }
    प्रति (i = 1; i < nnew; i++) {
	s = snew[i];
        s->sh_अङ्कः = i;
        यदि (s->sh_type == SHT_RELX)
            s->sh_info = backmap[s->sh_info];
        अन्यथा यदि (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM)
            for_each_elem(s, 1, sym, ElfW(Sym))
                यदि (sym->st_shndx < s1->nb_sections)
                    sym->st_shndx = backmap[sym->st_shndx];
    }
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}

#यदि_परिभाषितम् TCC_TARGET_ARM
स्थिर शून्य create_arm_attribute_section(TCCState *s1)
{
   // Needed for DLL support.
    स्थिर ध्रुव अचिह्नित वर्ण arm_attr[] = {
        0x41,                            // 'A'
        0x2c, 0x00, 0x00, 0x00,          // size 0x2c
        'a', 'e', 'a', 'b', 'i', 0x00,   // "aeabi"
        0x01, 0x22, 0x00, 0x00, 0x00,    // 'File Attributes', size 0x22
        0x05, 0x36, 0x00,                // 'CPU_name', "6"
#यदि CONFIG_TCC_CPUVER >= 7
        0x06, 0x0a,                      // 'CPU_arch', 'v7'
#अन्यथा
        0x06, 0x06,                      // 'CPU_arch', 'v6'
#यदि_अन्तः
        0x08, 0x01,                      // 'ARM_ISA_use', 'Yes'
        0x09, 0x01,                      // 'THUMB_ISA_use', 'Thumb-1'
        0x0a, 0x02,                      // 'FP_arch', 'VFPv2'
        0x12, 0x04,                      // 'ABI_PCS_wchar_t', 4
        0x14, 0x01,                      // 'ABI_FP_denormal', 'Needed'
        0x15, 0x01,                      // 'ABI_FP_exceptions', 'Needed'
        0x17, 0x03,                      // 'ABI_FP_number_model', 'IEEE 754'
        0x18, 0x01,                      // 'ABI_align_needed', '8-byte'
        0x19, 0x01,                      // 'ABI_align_preserved', '8-byte, except leaf SP'
        0x1a, 0x02,                      // 'ABI_enum_size', 'int'
        0x1c, 0x01,                      // 'ABI_VFP_args', 'VFP registers'
        0x22, 0x01                       // 'CPU_unaligned_access', 'v6'
    };
    Section *attr = new_section(s1, ".ARM.attributes", SHT_ARM_गुणाः, 0);
    अचिह्नित वर्ण *ptr = section_ptr_सङ्कलय(attr, परिमाण(arm_attr));
    attr->sh_addralign = 1;
    स्मृतिं_प्रतिलिख(ptr, arm_attr, परिमाण(arm_attr));
    यदि (s1->float_abi != ARM_HARD_FLOAT) {
        ptr[26] = 0x00; // 'FP_arch', 'No'
        ptr[41] = 0x1e; // 'ABI_optimization_goals'
        ptr[42] = 0x06; // 'Aggressive Debug'
    }
}
#यदि_अन्तः

#यदि_परिभाषितम् TCC_TARGET_RISCV64
स्थिर शून्य create_riscv_attribute_section(TCCState *s1)
{
    स्थिर ध्रुव अचिह्नित वर्ण riscv_attr[] = {
        0x41,                           /* 'A' */
        0x49, 0x00, 0x00, 0x00,         /* total_len = 73 */
        'r', 'i', 's', 'c', 'v', 0x00,  /* "riscv\0" */
        0x3a, 0x00, 0x00, 0x00,         /* file_len = 58 */
        0x05,                           /* Tag_RISCV_arch */
        0x35, 0x00, 0x00, 0x00,         /* isa_len = 53 */
        'r','v','6','4','i','2','p','1','_','m','2','p','0','_',
        'a','2','p','1','_','f','2','p','2','_','d','2','p','2','_',
        'c','2','p','0','_','z','i','c','s','r','2','p','0','_',
        'z','i','f','e','n','c','e','i','2','p','0', 0x00,
    };
    Section *attr = new_section(s1, ".riscv.attributes", SHT_RISCV_गुणाः, 0);
    अचिह्नित वर्ण *ptr = section_ptr_सङ्कलय(attr, परिमाण(riscv_attr));
    attr->sh_addralign = 1;
    स्मृतिं_प्रतिलिख(ptr, riscv_attr, परिमाण(riscv_attr));
}
#यदि_अन्तः

#यदि TARGETOS_OpenBSD || TARGETOS_NetBSD || TARGETOS_FreeBSD

स्थिर शून्य fill_bsd_note(Section *s, पूर्णाङ्क type,
			  ध्रुव वर्ण *मानम्, uint32_t दत्त)
{
    अचिह्नित दीर्घ विस्थापनम् = 0;
    वर्ण *ptr;
    ElfW(Nhdr) *note;
    पूर्णाङ्क align = s->sh_addralign;

    /* check if type present */
    यावत् (विस्थापनम् + परिमाण(ElfW(Nhdr)) < s->दत्त_विस्थापनम्) {
        note = (ElfW(Nhdr) *) (s->दत्त + विस्थापनम्);
	यदि (note->n_type == type)
	    प्रत्यागम;
	विस्थापनम् += (परिमाण(ElfW(Nhdr)) + note->n_namesz + note->n_descsz +
		  align - 1) & -align;
    }
    ptr = section_ptr_सङ्कलय(s, परिमाण(ElfW(Nhdr)) + 8 + 4);
    note = (ElfW(Nhdr) *) ptr;
    note->n_namesz = 8;
    note->n_descsz = 4;
    note->n_type = type;
    वाक्यं_प्रतिलिख (ptr + परिमाण(ElfW(Nhdr)), मानम्);
    स्मृतिं_प्रतिलिख (ptr + परिमाण(ElfW(Nhdr)) + 8, &दत्त, 4);
}

स्थिर Section *create_bsd_note_section(TCCState *s1,
					ध्रुव वर्ण *name,
					ध्रुव वर्ण *मानम्)
{
    Section *s;
    अचिह्नित पूर्णाङ्क major = 0, minor = 0, patch = 0;

#यदि_परिभाषितम् CONFIG_OS_RELEASE
    वाक्यात्_पठ(CONFIG_OS_RELEASE, "%u.%u.%u", &major, &minor, &patch);
#यदि_अन्तः
#यदि TARGETOS_FreeBSD
    यदि (major < 14)
	प्रत्यागम रिक्त;
#यदि_अन्तः
    s = find_section (s1, name);
    s->sh_type = SHT_NOTE;
#यदि TARGETOS_OpenBSD
    fill_bsd_note(s, ELF_NOTE_OS_GNU, मानम्, 0);
#नोचेद्यदि TARGETOS_NetBSD
    fill_bsd_note(s, 1 /* NT_NETBSD_IDENT_TAG */, मानम्,
		  major * 100000000u + (minor % 100u) * 1000000u +
		  (patch % 10000u) * 100u);
#नोचेद्यदि TARGETOS_FreeBSD
    fill_bsd_note(s, 1 /* NT_FREEBSD_ABI_TAG */, मानम्,
		  major * 100000u + (minor % 100u) * 1000u);
    fill_bsd_note(s, 4 /* NT_FREEBSD_FEATURE_CTL */, मानम्, 0);
    fill_bsd_note(s, 2 /* NT_FREEBSD_NOINIT_TAG */, मानम्, 0);
#यदि_अन्तः
    प्रत्यागम s;
}
#यदि_अन्तः

स्थिर शून्य alloc_sec_नामानि(TCCState *s1, पूर्णाङ्क is_obj);

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
स्थिर पूर्णाङ्क elf_output_file(TCCState *s1, ध्रुव वर्ण *filename)
{
    पूर्णाङ्क i, ret, file_type, *sec_क्रमः;
    संरचना dyn_inf dyninf = {0};
    Section *interp, *dynstr, *dynamic;
    पूर्णाङ्क textrel, got_sym, dt_flags_1;

    file_type = s1->output_type;
    ret = -1;
    interp = dynstr = dynamic = रिक्त;
    sec_क्रमः = रिक्त;

#यदि_परिभाषितम् TCC_TARGET_ARM
    create_arm_attribute_section (s1);
#यदि_अन्तः

#यदि_परिभाषितम् TCC_TARGET_RISCV64
    create_riscv_attribute_section(s1);
#यदि_अन्तः

#यदि TARGETOS_OpenBSD
    dyninf.note = create_bsd_note_section (s1, ".note.openbsd.ident", "OpenBSD");
#यदि_अन्तः

#यदि TARGETOS_NetBSD
    dyninf.note = create_bsd_note_section (s1, ".note.netbsd.ident", "NetBSD");
#यदि_अन्तः

#यदि TARGETOS_FreeBSD
    dyninf.note = create_bsd_note_section (s1, ".note.tag", "FreeBSD");
#यदि_अन्तः

        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_सङ्कलय_runtime(s1);
	resolve_common_syms(s1);

        यदि (!s1->static_link) {
            यदि (file_type & TCC_OUTPUT_EXE) {
                /* add interpreter section only if executable */
                interp = new_section(s1, ".interp", SHT_PROGBITS, SHF_ALLOC);
                interp->sh_addralign = 1;
                put_elf_str(interp, s1->elfint);
                dyninf.interp = interp;
            }

            /* add dynamic symbol table */
            s1->dynsym = new_symtab(s1, ".dynsym", SHT_DYNSYM, SHF_ALLOC,
                                    ".dynstr",
                                    ".hash", SHF_ALLOC);
	    /* Number of local symbols (readelf complains if not set) */
	    s1->dynsym->sh_info = 1;
            dynstr = s1->dynsym->link;
            /* add dynamic section */
            dynamic = new_section(s1, ".dynamic", SHT_DYNAMIC,
                                  SHF_ALLOC | SHF_WRITE);
            dynamic->link = dynstr;
            dynamic->sh_entsize = परिमाण(ElfW(Dyn));

            got_sym = build_got(s1);
            यदि (file_type & TCC_OUTPUT_EXE) {
                bind_exe_dynsyms(s1, file_type & TCC_OUTPUT_DYN);
                यदि (s1->nb_errors)
                    गच्छ the_अन्तः;
            }
            build_got_entries(s1, got_sym);
            यदि (file_type & TCC_OUTPUT_EXE) {
                bind_libs_dynsyms(s1);
            } अन्यथा {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
#यदि TCC_EH_FRAME
	    /* fill with initial data */
	    tcc_eh_frame_hdr(s1, 0);
#यदि_अन्तः
	    dyninf.gnu_hash = create_gnu_hash(s1);
        } अन्यथा {
            build_got_entries(s1, 0);
        }
	संस्करणम्_सङ्कलय (s1);

    textrel = समुच्चयः_sec_sizes(s1);

    यदि (!s1->static_link) {
        /* add a list of needed dlls */
        प्रति(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            यदि (dllref->level == 0)
                put_dt(dynamic, DT_NEEDED, put_elf_str(dynstr, dllref->name));
        }

        यदि (s1->rpath)
            put_dt(dynamic, s1->enable_new_dtags ? DT_RUNPATH : DT_RPATH,
                   put_elf_str(dynstr, s1->rpath));

        dt_flags_1 = DF_1_NOW;
        यदि (file_type & TCC_OUTPUT_DYN) {
            यदि (s1->soname)
                put_dt(dynamic, DT_SONAME, put_elf_str(dynstr, s1->soname));
            /* XXX: currently, since we do not handle PIC code, we
               must relocate the readonly segments */
            यदि (textrel)
                put_dt(dynamic, DT_TEXTREL, 0);
            यदि (file_type & TCC_OUTPUT_EXE)
                dt_flags_1 = DF_1_NOW | DF_1_PIE;
	    यदि (s1->znodelete)
		dt_flags_1 |= DF_1_NODELETE;
        }
        put_dt(dynamic, DT_FLAGS, DF_BIND_NOW);
        put_dt(dynamic, DT_FLAGS_1, dt_flags_1);
        यदि (s1->symbolic)
            put_dt(dynamic, DT_SYMBOLIC, 0);

        dyninf.dynamic = dynamic;
        dyninf.dynstr = dynstr;
        /* remember offset and reserve space for 2nd call below */
        dyninf.दत्त_विस्थापनम् = dynamic->दत्त_विस्थापनम्;
        fill_dynamic(s1, &dyninf);
        dynamic->sh_आकार = dynamic->दत्त_विस्थापनम्;
        dynstr->sh_आकार = dynstr->दत्त_विस्थापनम्;
    }

    /* create and fill .shstrtab section */
    alloc_sec_नामानि(s1, 0);
    /* this array is used to reorder sections in the output file */
    sec_क्रमः = tcc_malloc(परिमाण(पूर्णाङ्क) * 2 * s1->nb_sections);
    /* compute section to program header mapping */
    layout_sections(s1, sec_क्रमः, &dyninf);

        यदि (dynamic) {
            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->दत्त, dynamic->sh_addr);
            यदि (file_type == TCC_OUTPUT_EXE
                || (RELOCATE_DLLPLT && (file_type & TCC_OUTPUT_DYN)))
                relocate_plt(s1);
            /* relocate symbols in .dynsym now that final addresses are known */
            relocate_syms(s1, s1->dynsym, 2);
        }

        /* if building executable or DLL, then relocate each section
           except the GOT which is already relocated */
        relocate_syms(s1, s1->symtab, 0);
        यदि (s1->nb_errors != 0)
            गच्छ the_अन्तः;
        relocate_sections(s1);
        यदि (dynamic) {
	    update_reloc_sections (s1, &dyninf);
            dynamic->दत्त_विस्थापनम् = dyninf.दत्त_विस्थापनम्;
            fill_dynamic(s1, &dyninf);
	}
        /* Perform relocation to GOT or PLT entries */
        यदि (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        अन्यथा यदि (s1->got)
            fill_local_got_entries(s1);

    यदि (dyninf.gnu_hash)
        update_gnu_hash(s1, dyninf.gnu_hash);

    reorder_sections(s1, sec_क्रमः);
#यदि TCC_EH_FRAME
    /* fill with final data */
    tcc_eh_frame_hdr(s1, 1);
#यदि_अन्तः
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, dyninf.phnum, dyninf.phdr);
 the_अन्तः:
    tcc_free(sec_क्रमः);
    tcc_free(dyninf.phdr);
    प्रत्यागम ret;
}
#यदि_अन्तः /* ndef ELF_OBJ_ONLY */

/* Allocate strings for section names */
स्थिर शून्य alloc_sec_नामानि(TCCState *s1, पूर्णाङ्क is_obj)
{
    पूर्णाङ्क i;
    Section *s, *strsec;

    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");
    प्रति(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        यदि (is_obj)
            s->sh_आकार = s->दत्त_विस्थापनम्;
	यदि (s->sh_आकार || s == strsec || (s->sh_flags & SHF_ALLOC) || is_obj)
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_आकार = strsec->दत्त_विस्थापनम्;
}

/* Output an elf .o file */
स्थिर पूर्णाङ्क elf_output_obj(TCCState *s1, ध्रुव वर्ण *filename)
{
    Section *s;
    पूर्णाङ्क i, ret, file_विस्थापनम्;
    /* Allocate strings for section names */
    alloc_sec_नामानि(s1, 1);
    file_विस्थापनम् = (परिमाण (ElfW(Ehdr)) + 3) & -4;
    file_विस्थापनम् += s1->nb_sections * परिमाण(ElfW(Shdr));
    प्रति(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        file_विस्थापनम् = (file_विस्थापनम् + 15) & -16;
        s->sh_विस्थापनम् = file_विस्थापनम्;
        यदि (s->sh_type != SHT_NOBITS)
            file_विस्थापनम् += s->sh_आकार;
    }
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, 0, रिक्त);
    प्रत्यागम ret;
}

LIBTCCAPI पूर्णाङ्क tcc_output_file(TCCState *s, ध्रुव वर्ण *filename)
{
    s->nb_errors = 0;
    यदि (s->test_coverage)
        tcc_tcov_सङ्कलय_file(s, filename);
    यदि (s->output_type == TCC_OUTPUT_OBJ)
        प्रत्यागम elf_output_obj(s, filename);
#यदि_परिभाषितम् TCC_TARGET_PE
    प्रत्यागम  pe_output_file(s, filename);
#नोचेद्यदि defined TCC_TARGET_MACHO
    प्रत्यागम macho_output_file(s, filename);
#अन्यथा
    प्रत्यागम elf_output_file(s, filename);
#यदि_अन्तः
}

ST_FUNC ssize_t पूर्णम्_read(पूर्णाङ्क fd, शून्य *buf, आकार_t गणनम्_2) {
    वर्ण *cbuf = buf;
    आकार_t rnum = 0;
    यावत् (1) {
        ssize_t अङ्कः = पठ(fd, cbuf, गणनम्_2-rnum);
        यदि (अङ्कः < 0) प्रत्यागम अङ्कः;
        यदि (अङ्कः == 0) प्रत्यागम rnum;
        rnum += अङ्कः;
        cbuf += अङ्कः;
    }
}

ST_FUNC शून्य *आरोपय_दत्त(पूर्णाङ्क fd, अचिह्नित दीर्घ file_विस्थापनम्, अचिह्नित दीर्घ आकार)
{
    शून्य *दत्त;

    दत्त = tcc_malloc(आकार);
    lseek(fd, file_विस्थापनम्, SEEK_SET);
    पूर्णम्_read(fd, दत्त, आकार);
    प्रत्यागम दत्त;
}

प्रकारनिर्देश संरचना SectionMergeInfo {
    Section *s;            /* corresponding existing section */
    अचिह्नित दीर्घ विस्थापनम्;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} SectionMergeInfo;

ST_FUNC पूर्णाङ्क tcc_object_type(पूर्णाङ्क fd, ElfW(Ehdr) *h)
{
    पूर्णाङ्क आकार = पूर्णम्_read(fd, h, परिमाण *h);
    यदि (आकार == परिमाण *h && 0 == memcmp(h, ELFMAG, 4)) {
        यदि (h->e_type == ET_REL)
            प्रत्यागम AFF_BINTYPE_REL;
        यदि (h->e_type == ET_DYN)
            प्रत्यागम AFF_BINTYPE_DYN;
    } अन्यथा यदि (आकार >= 8) {
        यदि (0 == memcmp(h, ARMAG, 8))
            प्रत्यागम AFF_BINTYPE_AR;
#यदि_परिभाषितम् TCC_TARGET_COFF
        यदि (((संरचना filehdr*)h)->f_magic == COFF_C67_MAGIC)
            प्रत्यागम AFF_BINTYPE_C67;
#यदि_अन्तः
    }
    प्रत्यागम 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC पूर्णाङ्क tcc_आरोपय_object_file(TCCState *s1,
                                पूर्णाङ्क fd, अचिह्नित दीर्घ file_विस्थापनम्)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    अचिह्नित दीर्घ आकार, विस्थापनम्, offseti;
    पूर्णाङ्क i, j, nb_syms, sym_सूचकांक, ret, seencompressed;
    वर्ण *strsec, *strtab;
    पूर्णाङ्क stab_सूचकांक, stabstr_सूचकांक;
    पूर्णाङ्क *old_गन्तव्यम्_new_syms;
    वर्ण *sh_name, *name;
    SectionMergeInfo *sm_सारणी, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    lseek(fd, file_विस्थापनम्, SEEK_SET);
    यदि (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        गच्छ invalid;
    /* test CPU specific stuff */
    यदि (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
invalid:
        प्रत्यागम tcc_error_noabort("invalid object file");
    }
    /* read sections */
    shdr = आरोपय_दत्त(fd, file_विस्थापनम् + ehdr.e_shoff,
                     परिमाण(ElfW(Shdr)) * ehdr.e_shnum);
    sm_सारणी = tcc_mallocz(परिमाण(SectionMergeInfo) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = आरोपय_दत्त(fd, file_विस्थापनम् + sh->sh_विस्थापनम्, sh->sh_आकार);

    /* load symtab and strtab */
    old_गन्तव्यम्_new_syms = रिक्त;
    symtab = रिक्त;
    strtab = रिक्त;
    nb_syms = 0;
    seencompressed = 0;
    stab_सूचकांक = stabstr_सूचकांक = 0;
    ret = -1;

    प्रति(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        यदि (sh->sh_type == SHT_SYMTAB) {
            यदि (symtab) {
                tcc_error_noabort("object must contain only one symtab");
                गच्छ the_अन्तः;
            }
            nb_syms = sh->sh_आकार / परिमाण(ElfW(Sym));
            symtab = आरोपय_दत्त(fd, file_विस्थापनम् + sh->sh_विस्थापनम्, sh->sh_आकार);
            sm_सारणी[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = आरोपय_दत्त(fd, file_विस्थापनम् + sh->sh_विस्थापनम्, sh->sh_आकार);
        }
	यदि (sh->sh_flags & SHF_COMPRESSED)
	    seencompressed = 1;
    }

    /* now examine each section and try to merge its content with the
       ones in memory */
    प्रति(i = 1; i < ehdr.e_shnum; i++) {
        /* no need to examine section name strtab */
        यदि (i == ehdr.e_shstrndx)
            अनुवर्त;
        sh = &shdr[i];
	यदि (sh->sh_type == SHT_RELX)
	  sh = &shdr[sh->sh_info];
        /* ignore sections types we do not handle (plus relocs to those) */
        sh_name = strsec + sh->sh_name;
        यदि (0 == वाक्ये_तुलय(sh_name, ".debug_", 7)
         || 0 == वाक्ये_तुलय(sh_name, ".stab", 5)) {
	    यदि (!s1->do_debug || seencompressed)
	        अनुवर्त;
#यदि !(TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD)
        } अन्यथा यदि (0 == वाक्ये_तुलय(sh_name, ".eh_frame", 9)) {
            यदि (रिक्त == eh_frame_section)
                अनुवर्त;
#यदि_अन्तः
        } अन्यथा
        यदि (sh->sh_type != SHT_PROGBITS &&
            sh->sh_type != SHT_NOTE &&
            sh->sh_type != SHT_NOBITS &&
            sh->sh_type != SHT_PREINIT_ARRAY &&
            sh->sh_type != SHT_INIT_ARRAY &&
            sh->sh_type != SHT_FINI_ARRAY
#यदि_परिभाषितम् TCC_ARM_EABI
            /* Added in commit f99d3de221db23e322c6c18c8249282e27726c25
               but suppressed in 3cfaaaf1eb97d858e583412616f68f75fdad5da5
               So don't load it in order to avoid dangling references from
               (STT_SECTION) symbols. */
            // && sh->sh_type != SHT_ARM_EXIDX
#यदि_अन्तः

#यदि TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD
            && sh->sh_type != SHT_X86_64_UNWIND
#यदि_अन्तः
            )
            अनुवर्त;

	sh = &shdr[i];
        sh_name = strsec + sh->sh_name;
        यदि (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        /* find corresponding section, if any */
        प्रति(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            यदि (वाक्यं_तुलय(s->name, sh_name))
                अनुवर्त;
            यदि (sh->sh_type != s->sh_type
                && वाक्यं_तुलय (s->name, ".eh_frame")
                /* some crt1.o seem to have two ".note.GNU-stack" (SHT_NOTE & SHT_PROGBITS) */
                && वाक्यं_तुलय (s->name, ".note.GNU-stack")
                ) {
                tcc_error_noabort("section type conflict: %s %02x <> %02x", s->name, sh->sh_type, s->sh_type);
                गच्छ the_अन्तः;
            }
            यदि (!वाक्ये_तुलय(sh_name, ".gnu.linkonce", 13)) {
                /* if a 'linkonce' section is already present, we
                   do not add it again. It is a little tricky as
                   symbols can still be defined in
                   it. */
                sm_सारणी[i].link_once = 1;
                गच्छ अग्र;
            }
            यदि (stab_section) {
                यदि (s == stab_section)
                    stab_सूचकांक = i;
                यदि (s == stab_section->link)
                    stabstr_सूचकांक = i;
            }
            गच्छ प्राप्तम्;
        }
        /* not found: create new section */
        s = new_section(s1, sh_name, sh->sh_type, sh->sh_flags & ~SHF_गणः);
        /* take as much info as possible from the section. sh_link and
           sh_info will be updated later */
        s->sh_addralign = sh->sh_addralign;
        s->sh_entsize = sh->sh_entsize;
        sm_सारणी[i].new_section = 1;
    प्राप्तम्:
        आकार = sh->sh_आकार;
        /* align start of section */
        विस्थापनम् = section_सङ्कलय(s, आकार, sh->sh_addralign);
        यदि (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        sm_सारणी[i].विस्थापनम् = विस्थापनम्;
        sm_सारणी[i].s = s;
        /* concatenate sections */
        यदि (sh->sh_type != SHT_NOBITS && आकार) {
            अचिह्नित वर्ण *ptr;
            lseek(fd, file_विस्थापनम् + sh->sh_विस्थापनम्, SEEK_SET);
            ptr = s->दत्त + विस्थापनम्;
            पूर्णम्_read(fd, ptr, आकार);
        }
#यदि defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
        /* align code sections to instruction lenght */
        /* This is needed if we compile a c file after this */
        यदि (s->sh_flags & SHF_EXECINSTR)
            section_सङ्कलय(s, 0, 4);
#यदि_अन्तः
    अग्र: ;
    }

    /* gr relocate stab strings */
    यदि (stab_सूचकांक && stabstr_सूचकांक) {
        Stab_Sym *a, *b;
        अचिह्नित o;
        s = sm_सारणी[stab_सूचकांक].s;
        a = (Stab_Sym *)(s->दत्त + sm_सारणी[stab_सूचकांक].विस्थापनम्);
        b = (Stab_Sym *)(s->दत्त + s->दत्त_विस्थापनम्);
        o = sm_सारणी[stabstr_सूचकांक].विस्थापनम्;
        यावत् (a < b) {
            यदि (a->n_strx)
                a->n_strx += o;
            a++;
        }
    }

    /* second short pass to update sh_link and sh_info fields of new
       sections */
    प्रति(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_सारणी[i].s;
        यदि (!s || !sm_सारणी[i].new_section)
            अनुवर्त;
        sh = &shdr[i];
        यदि (sh->sh_link > 0)
            s->link = sm_सारणी[sh->sh_link].s;
        यदि (sh->sh_type == SHT_RELX) {
            s->sh_info = sm_सारणी[sh->sh_info].s->sh_अङ्कः;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }

    यदि (!symtab)
        गच्छ समाप्तम्;

    /* resolve symbols */
    old_गन्तव्यम्_new_syms = tcc_mallocz(nb_syms * परिमाण(पूर्णाङ्क));

    sym = symtab + 1;
    प्रति(i = 1; i < nb_syms; i++, sym++) {
        यदि (sym->st_shndx != SHN_UNDEF &&
            sym->st_shndx < SHN_LORESERVE) {
            sm = &sm_सारणी[sym->st_shndx];
            यदि (sm->link_once) {
                /* if a symbol is in a link once section, we use the
                   already defined symbol. It is very important to get
                   correct relocations */
                यदि (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
                    name = strtab + sym->st_name;
                    sym_सूचकांक = find_elf_sym(symtab_section, name);
                    यदि (sym_सूचकांक)
                        old_गन्तव्यम्_new_syms[i] = sym_सूचकांक;
                }
                अनुवर्त;
            }
            /* if no corresponding section added, no need to add symbol */
            यदि (!sm->s)
                अनुवर्त;
            /* convert section number */
            sym->st_shndx = sm->s->sh_अङ्कः;
            /* offset value */
            sym->st_मानम् += sm->विस्थापनम्;
        }
        /* add symbol */
        name = strtab + sym->st_name;
        sym_सूचकांक = समुच्चयः_elf_sym(symtab_section, sym->st_मानम्, sym->st_आकार,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_गन्तव्यम्_new_syms[i] = sym_सूचकांक;
    }

    /* third pass to patch relocation entries */
    प्रति(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_सारणी[i].s;
        यदि (!s)
            अनुवर्त;
        sh = &shdr[i];
        विस्थापनम् = sm_सारणी[i].विस्थापनम्;
        आकार = sh->sh_आकार;
        विकल्प(s->sh_type) {
        पक्ष SHT_RELX:
            /* take relocation offset information */
            offseti = sm_सारणी[sh->sh_info].विस्थापनम्;
	    प्रति (rel = (ElfW_Rel *) s->दत्त + (विस्थापनम् / परिमाण(*rel));
		 rel < (ElfW_Rel *) s->दत्त + ((विस्थापनम् + आकार) / परिमाण(*rel));
		 rel++) {
                पूर्णाङ्क type;
                अचिह्नित sym_सूचकांक;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                यदि (sym_सूचकांक >= nb_syms)
                    गच्छ invalid_reloc;
                sym_सूचकांक = old_गन्तव्यम्_new_syms[sym_सूचकांक];
                /* ignore link_once in rel section. */
                यदि (!sym_सूचकांक && !sm_सारणी[sh->sh_info].link_once
#यदि_परिभाषितम् TCC_TARGET_ARM
                    && type != R_ARM_V4BX
#नोचेद्यदि defined TCC_TARGET_RISCV64
                    && type != R_RISCV_ALIGN
                    && type != R_RISCV_RELAX
#यदि_अन्तः
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, (पूर्णाङ्क)rel->r_विस्थापनम्);
                    गच्छ the_अन्तः;
                }
                rel->r_info = ELFW(R_INFO)(sym_सूचकांक, type);
                /* offset the relocation offset */
                rel->r_विस्थापनम् += offseti;
#यदि_परिभाषितम् TCC_TARGET_ARM
                /* Jumps and branches from a Thumb code to a PLT entry need
                   special handling since PLT entries are ARM code.
                   Unconditional bl instructions referencing PLT entries are
                   handled by converting these instructions into blx
                   instructions. Other case of instructions referencing a PLT
                   entry require to add a Thumb stub before the PLT entry to
                   switch to ARM mode. We set bit plt_thumb_stub of the
                   attribute of a symbol to indicate such a case. */
                यदि (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_सूचकांक, 1)->plt_thumb_stub = 1;
#यदि_अन्तः
            }
            भङ्ग;
        स्वभाव:
            भङ्ग;
        }
    }
 समाप्तम्:
    ret = !s1->nb_errors - 1; /* errors possibly from set_elf_sym() */
 the_अन्तः:
    tcc_free(symtab);
    tcc_free(strtab);
    tcc_free(old_गन्तव्यम्_new_syms);
    tcc_free(sm_सारणी);
    tcc_free(strsec);
    tcc_free(shdr);
    प्रत्यागम ret;
}

प्रकारनिर्देश संरचना Archive_शीर्षकम् {
    वर्ण ar_name[16];           /* name of this member */
    वर्ण ar_date[12];           /* file mtime */
    वर्ण ar_uid[6];             /* owner uid; printed as decimal */
    वर्ण ar_gid[6];             /* owner gid; printed as decimal */
    वर्ण ar_बहुलकम्[8];            /* file mode, printed as octal   */
    वर्ण ar_आकार[10];           /* file size, printed as decimal */
    वर्ण ar_fmag[2];            /* should contain ARFMAG */
} Archive_शीर्षकम्;

#परिभाषय ARFMAG "`\n"

स्थिर अचिह्नित दीर्घ दीर्घ get_be(ध्रुव uint8_t *b, पूर्णाङ्क n)
{
    अचिह्नित दीर्घ दीर्घ ret = 0;
    यावत् (n)
        ret = (ret << 8) | *b++, --n;
    प्रत्यागम ret;
}

स्थिर पूर्णाङ्क read_ar_शीर्षकम्(पूर्णाङ्क fd, पूर्णाङ्क विस्थापनम्, Archive_शीर्षकम् *hdr)
{
    वर्ण *p, *e;
    पूर्णाङ्क len;
    lseek(fd, विस्थापनम्, SEEK_SET);
    len = पूर्णम्_read(fd, hdr, परिमाण(Archive_शीर्षकम्));
    यदि (len != परिमाण(Archive_शीर्षकम्))
        प्रत्यागम len ? -1 : 0;
    यदि (memcmp(hdr->ar_fmag, ARFMAG, परिमाण hdr->ar_fmag))
        प्रत्यागम -1;
    p = hdr->ar_name;
    प्रति (e = p + परिमाण hdr->ar_name; e > p && e[-1] == ' ';)
        --e;
    *e = '\0';
    hdr->ar_आकार[परिमाण hdr->ar_आकार-1] = 0;
    प्रत्यागम len;
}

/* load only the objects which resolve undefined symbols */
स्थिर पूर्णाङ्क tcc_आरोपय_alacarte(TCCState *s1, पूर्णाङ्क fd, पूर्णाङ्क आकार, पूर्णाङ्क entrysize)
{
    पूर्णाङ्क i, bound, nsyms, sym_सूचकांक, len, ret = -1;
    अचिह्नित दीर्घ दीर्घ off;
    uint8_t *दत्त;
    ध्रुव वर्ण *ar_नामानि, *p;
    ध्रुव uint8_t *ar_सूचकांक;
    ElfW(Sym) *sym;
    Archive_शीर्षकम् hdr;

    दत्त = tcc_malloc(आकार);
    यदि (पूर्णम्_read(fd, दत्त, आकार) != आकार)
        गच्छ invalid;
    nsyms = get_be(दत्त, entrysize);
    ar_सूचकांक = दत्त + entrysize;
    ar_नामानि = (वर्ण *) ar_सूचकांक + nsyms * entrysize;

    कुरु {
        bound = 0;
        प्रति (p = ar_नामानि, i = 0; i < nsyms; i++, p += वाक्यदैर्घ्यम्(p)+1) {
            Section *s = symtab_section;
            sym_सूचकांक = find_elf_sym(s, p);
            यदि (!sym_सूचकांक)
                अनुवर्त;
            sym = &((ElfW(Sym) *)s->दत्त)[sym_सूचकांक];
            यदि(sym->st_shndx != SHN_UNDEF)
                अनुवर्त;
            off = get_be(ar_सूचकांक + i * entrysize, entrysize);
            len = read_ar_शीर्षकम्(fd, off, &hdr);
            यदि (len <= 0 || memcmp(hdr.ar_fmag, ARFMAG, 2)) {
        invalid:
                tcc_error_noabort("invalid archive");
                गच्छ the_अन्तः;
            }
            off += len;
            यदि (s1->verbose == 2)
                प्रारूप_लिख("   -> %s\n", hdr.ar_name);
            यदि (tcc_आरोपय_object_file(s1, fd, off) < 0)
                गच्छ the_अन्तः;
            ++bound;
        }
    } यावत्(bound);
    ret = 0;
 the_अन्तः:
    tcc_free(दत्त);
    प्रत्यागम ret;
}

/* load a '.a' file */
ST_FUNC पूर्णाङ्क tcc_आरोपय_archive(TCCState *s1, पूर्णाङ्क fd, पूर्णाङ्क alacarte)
{
    Archive_शीर्षकम् hdr;
    /* char magic[8]; */
    पूर्णाङ्क आकार, len;
    अचिह्नित दीर्घ file_विस्थापनम्;
    ElfW(Ehdr) ehdr;

    /* skip magic which was already checked */
    /* full_read(fd, magic, sizeof(magic)); */
    file_विस्थापनम् = परिमाण ARMAG - 1;

    प्रति(;;) {
        len = read_ar_शीर्षकम्(fd, file_विस्थापनम्, &hdr);
        यदि (len == 0)
            प्रत्यागम 0;
        यदि (len < 0)
            प्रत्यागम tcc_error_noabort("invalid archive");
        file_विस्थापनम् += len;
        आकार = strtol(hdr.ar_आकार, रिक्त, 0);
        यदि (alacarte) {
            /* coff symbol table : we handle it */
            यदि (!वाक्यं_तुलय(hdr.ar_name, "/"))
                प्रत्यागम tcc_आरोपय_alacarte(s1, fd, आकार, 4);
            यदि (!वाक्यं_तुलय(hdr.ar_name, "/SYM64/"))
                प्रत्यागम tcc_आरोपय_alacarte(s1, fd, आकार, 8);
        } अन्यथा यदि (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
            यदि (s1->verbose == 2)
                प्रारूप_लिख("   -> %s\n", hdr.ar_name);
            यदि (tcc_आरोपय_object_file(s1, fd, file_विस्थापनम्) < 0)
                प्रत्यागम -1;
        }
        /* align to even */
        file_विस्थापनम् = (file_विस्थापनम् + आकार + 1) & ~1;
    }
}

#यदि_अपरिभाषितम् ELF_OBJ_ONLY
/* Set LV[I] to the global index of sym-version (LIB,VERSION).  Maybe resizes
   LV, maybe create a new entry for (LIB,VERSION).  */
स्थिर शून्य समुच्चयः_ver_गन्तव्यम्_ver(TCCState *s1, पूर्णाङ्क *n, पूर्णाङ्क **lv, पूर्णाङ्क i, वर्ण *lib, वर्ण *संस्करणम्)
{
    यावत् (i >= *n) {
        *lv = tcc_realloc(*lv, (*n + 1) * परिमाण(**lv));
        (*lv)[(*n)++] = -1;
    }
    यदि ((*lv)[i] == -1) {
        पूर्णाङ्क v, पूर्व_same_lib = -1;
        प्रति (v = 0; v < nb_sym_versions; v++) {
            यदि (वाक्यं_तुलय(sym_versions[v].lib, lib))
              अनुवर्त;
            पूर्व_same_lib = v;
            यदि (!वाक्यं_तुलय(sym_versions[v].संस्करणम्, संस्करणम्))
              भङ्ग;
        }
        यदि (v == nb_sym_versions) {
            sym_versions = tcc_realloc (sym_versions,
                                        (v + 1) * परिमाण(*sym_versions));
            sym_versions[v].lib = tcc_strdup(lib);
            sym_versions[v].संस्करणम् = tcc_strdup(संस्करणम्);
            sym_versions[v].बहिर्गमनम्_सूचकांक = 0;
            sym_versions[v].पूर्व_same_lib = पूर्व_same_lib;
            nb_sym_versions++;
        }
        (*lv)[i] = v;
    }
}

/* Associates symbol SYM_INDEX (in dynsymtab) with sym-version index
   VERNDX.  */
स्थिर शून्य
समुच्चयः_sym_संस्करणम्(TCCState *s1, पूर्णाङ्क sym_सूचकांक, पूर्णाङ्क verndx)
{
    यदि (sym_सूचकांक >= nb_sym_गन्तव्यम्_संस्करणम्) {
        पूर्णाङ्क newelems = sym_सूचकांक ? sym_सूचकांक * 2 : 1;
        sym_गन्तव्यम्_संस्करणम् = tcc_realloc(sym_गन्तव्यम्_संस्करणम्,
                                     newelems * परिमाण(*sym_गन्तव्यम्_संस्करणम्));
        स्मृतिं_पूरय(sym_गन्तव्यम्_संस्करणम् + nb_sym_गन्तव्यम्_संस्करणम्, -1,
               (newelems - nb_sym_गन्तव्यम्_संस्करणम्) * परिमाण(*sym_गन्तव्यम्_संस्करणम्));
        nb_sym_गन्तव्यम्_संस्करणम् = newelems;
    }
    यदि (sym_गन्तव्यम्_संस्करणम्[sym_सूचकांक] < 0)
      sym_गन्तव्यम्_संस्करणम्[sym_सूचकांक] = verndx;
}

संरचना versym_info {
    पूर्णाङ्क nb_versyms;
    ElfW(Verdef) *verdef;
    ElfW(Verneed) *verneed;
    ElfW(Half) *versym;
    पूर्णाङ्क nb_local_ver, *local_ver;
};


स्थिर शून्य store_संस्करणम्(TCCState *s1, संरचना versym_info *v, वर्ण *dynstr)
{
    वर्ण *lib, *संस्करणम्;
    uint32_t अग्र;
    पूर्णाङ्क i;

#परिभाषय	DEBUG_संस्करणम् 0

    यदि (v->versym && v->verdef) {
      ElfW(Verdef) *vdef = v->verdef;
      lib = रिक्त;
      कुरु {
        ElfW(Verdaux) *verdaux =
	  (ElfW(Verdaux) *) (((वर्ण *) vdef) + vdef->vd_aux);

#यदि DEBUG_संस्करणम्
	प्रारूप_लिख ("verdef: version:%u flags:%u index:%u, hash:%u\n",
	        vdef->vd_संस्करणम्, vdef->vd_flags, vdef->vd_ndx,
		vdef->vd_hash);
#यदि_अन्तः
	यदि (vdef->vd_cnt) {
          संस्करणम् = dynstr + verdaux->vda_name;

	  यदि (lib == रिक्त)
	    lib = संस्करणम्;
	  अन्यथा
            समुच्चयः_ver_गन्तव्यम्_ver(s1, &v->nb_local_ver, &v->local_ver, vdef->vd_ndx,
                           lib, संस्करणम्);
#यदि DEBUG_संस्करणम्
	  प्रारूप_लिख ("  verdaux(%u): %s\n", vdef->vd_ndx, संस्करणम्);
#यदि_अन्तः
	}
        अग्र = vdef->vd_अग्र;
        vdef = (ElfW(Verdef) *) (((वर्ण *) vdef) + अग्र);
      } यावत् (अग्र);
    }
    यदि (v->versym && v->verneed) {
      ElfW(Verneed) *vneed = v->verneed;
      कुरु {
        ElfW(Vernaux) *vernaux =
	  (ElfW(Vernaux) *) (((वर्ण *) vneed) + vneed->vn_aux);

        lib = dynstr + vneed->vn_file;
#यदि DEBUG_संस्करणम्
	प्रारूप_लिख ("verneed: %u %s\n", vneed->vn_संस्करणम्, lib);
#यदि_अन्तः
	प्रति (i = 0; i < vneed->vn_cnt; i++) {
	  यदि ((vernaux->vna_other & 0x8000) == 0) { /* hidden */
              संस्करणम् = dynstr + vernaux->vna_name;
              समुच्चयः_ver_गन्तव्यम्_ver(s1, &v->nb_local_ver, &v->local_ver, vernaux->vna_other,
                             lib, संस्करणम्);
#यदि DEBUG_संस्करणम्
	    प्रारूप_लिख ("  vernaux(%u): %u %u %s\n",
		    vernaux->vna_other, vernaux->vna_hash,
		    vernaux->vna_flags, संस्करणम्);
#यदि_अन्तः
	  }
	  vernaux = (ElfW(Vernaux) *) (((वर्ण *) vernaux) + vernaux->vna_अग्र);
	}
        अग्र = vneed->vn_अग्र;
        vneed = (ElfW(Verneed) *) (((वर्ण *) vneed) + अग्र);
      } यावत् (अग्र);
    }

#यदि DEBUG_संस्करणम्
    प्रति (i = 0; i < v->nb_local_ver; i++) {
      यदि (v->local_ver[i] > 0) {
        प्रारूप_लिख ("%d: lib: %s, version %s\n",
		i, sym_versions[v->local_ver[i]].lib,
                sym_versions[v->local_ver[i]].संस्करणम्);
      }
    }
#यदि_अन्तः
}

/* load a library / DLL
   'level = 0' means that the DLL is referenced by the user
   (so it should be added as DT_NEEDED in the generated ELF file) */
ST_FUNC पूर्णाङ्क tcc_आरोपय_dll(TCCState *s1, पूर्णाङ्क fd, ध्रुव वर्ण *filename, पूर्णाङ्क level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    पूर्णाङ्क i, nb_syms, nb_dts, sym_bind, ret = -1;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;

    वर्ण *dynstr;
    पूर्णाङ्क sym_सूचकांक;
    ध्रुव वर्ण *name, *soname;
    संरचना versym_info v;

    पूर्णम्_read(fd, &ehdr, परिमाण(ehdr));

    /* test CPU specific stuff */
    यदि (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
        प्रत्यागम tcc_error_noabort("bad architecture");
    }

    /* read sections */
    shdr = आरोपय_दत्त(fd, ehdr.e_shoff, परिमाण(ElfW(Shdr)) * ehdr.e_shnum);

    /* load dynamic section and dynamic symbols */
    nb_syms = 0;
    nb_dts = 0;
    dynamic = रिक्त;
    dynsym = रिक्त; /* avoid warning */
    dynstr = रिक्त; /* avoid warning */
    स्मृतिं_पूरय(&v, 0, परिमाण v);

    प्रति(i = 0, sh = shdr; i < ehdr.e_shnum; i++, sh++) {
        विकल्प(sh->sh_type) {
        पक्ष SHT_DYNAMIC:
            nb_dts = sh->sh_आकार / परिमाण(ElfW(Dyn));
            dynamic = आरोपय_दत्त(fd, sh->sh_विस्थापनम्, sh->sh_आकार);
            भङ्ग;
        पक्ष SHT_DYNSYM:
            nb_syms = sh->sh_आकार / परिमाण(ElfW(Sym));
            dynsym = आरोपय_दत्त(fd, sh->sh_विस्थापनम्, sh->sh_आकार);
            sh1 = &shdr[sh->sh_link];
            dynstr = आरोपय_दत्त(fd, sh1->sh_विस्थापनम्, sh1->sh_आकार);
            भङ्ग;
        पक्ष SHT_GNU_verdef:
	    v.verdef = आरोपय_दत्त(fd, sh->sh_विस्थापनम्, sh->sh_आकार);
	    भङ्ग;
        पक्ष SHT_GNU_verneed:
	    v.verneed = आरोपय_दत्त(fd, sh->sh_विस्थापनम्, sh->sh_आकार);
	    भङ्ग;
        पक्ष SHT_GNU_versym:
            v.nb_versyms = sh->sh_आकार / परिमाण(ElfW(Half));
	    v.versym = आरोपय_दत्त(fd, sh->sh_विस्थापनम्, sh->sh_आकार);
	    भङ्ग;
        स्वभाव:
            भङ्ग;
        }
    }

    यदि (!dynamic)
        गच्छ the_अन्तः;

    /* compute the real library name */
    soname = tcc_basename(filename);
    प्रति(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        यदि (dt->d_चिह्नकम् == DT_SONAME)
            soname = dynstr + dt->d_un.d_val;

    /* if the dll is already loaded, do not load it */
    यदि (tcc_सङ्कलय_dllref(s1, soname, level)->प्राप्तम्)
        गच्छ ret_success;

    यदि (v.nb_versyms != nb_syms)
        tcc_free (v.versym), v.versym = रिक्त;
    अन्यथा
        store_संस्करणम्(s1, &v, dynstr);

    /* add dynamic symbols in dynsym_section */
    प्रति(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        यदि (sym_bind == STB_LOCAL)
            अनुवर्त;
        name = dynstr + sym->st_name;
        sym_सूचकांक = समुच्चयः_elf_sym(s1->dynsymtab_section, sym->st_मानम्, sym->st_आकार,
                                sym->st_info, sym->st_other, sym->st_shndx, name);
        यदि (v.versym) {
            ElfW(Half) vsym = v.versym[i];
            यदि ((vsym & 0x8000) == 0 && vsym > 0 && vsym < v.nb_local_ver)
                समुच्चयः_sym_संस्करणम्(s1, sym_सूचकांक, v.local_ver[vsym]);
        }
    }

    /* do not load all referenced libraries
       (recursive loading can break linking of libraries) */
    /* following DT_NEEDED is needed for the dynamic loader (libdl.so),
       but it is no longer needed, when linking a library or a program.
       When tcc output mode is OUTPUT_MEM,
       tcc calls dlopen, which handles DT_NEEDED for us */

#यदि 0
    प्रति(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        यदि (dt->d_चिह्नकम् == DT_RPATH)
            tcc_सङ्कलय_library_मार्गः(s1, dynstr + dt->d_un.d_val);

    /* load all referenced DLLs */
    प्रति(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        विकल्प(dt->d_चिह्नकम्) {
        पक्ष DT_NEEDED:
            name = dynstr + dt->d_un.d_val;
            यदि (tcc_सङ्कलय_dllref(s1, name, -1))
                अनुवर्त;
            यदि (tcc_सङ्कलय_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                ret = tcc_error_noabort("referenced dll '%s' not found", name);
                गच्छ the_अन्तः;
            }
        }
    }
#यदि_अन्तः

 ret_success:
    ret = 0;
 the_अन्तः:
    tcc_free(dynstr);
    tcc_free(dynsym);
    tcc_free(dynamic);
    tcc_free(shdr);
    tcc_free(v.local_ver);
    tcc_free(v.verdef);
    tcc_free(v.verneed);
    tcc_free(v.versym);
    प्रत्यागम ret;
}

#परिभाषय LD_TOK_NAME 256
#परिभाषय LD_TOK_EOF  (-1)
स्थिर पूर्णाङ्क ld_inp(TCCState *s1)
{
    पूर्णाङ्क c = *s1->ld_p;
    यदि (c == 0)
        प्रत्यागम CH_EOF;
    ++s1->ld_p;
    प्रत्यागम c;
}
#परिभाषय ld_unget(s1, ch) यदि (ch != CH_EOF) --s1->ld_p

/* return next ld script token */
स्थिर पूर्णाङ्क ld_अग्र(TCCState *s1, वर्ण *name, पूर्णाङ्क name_आकार)
{
    पूर्णाङ्क c, d, ch;
    वर्ण *q;

 redo:
    ch = ld_inp(s1);
    q = name, *q++ = ch;
    विकल्प(ch) {
    पक्ष ' ':
    पक्ष '\t':
    पक्ष '\f':
    पक्ष '\v':
    पक्ष '\r':
    पक्ष '\n':
        गच्छ redo;
    पक्ष '/':
        ch = ld_inp(s1);
        यदि (ch == '*') { /* comment */
            प्रति (d = 0;; d = ch) {
                ch = ld_inp(s1);
                यदि (ch == CH_EOF || (ch == '/' && d == '*'))
                    भङ्ग;
            }
            गच्छ redo;
        } अन्यथा {
            गच्छ parse_name;
        }
        भङ्ग;
    पक्ष '\\':
    /* case 'a' ... 'z': */
    पक्ष 'a':
       पक्ष 'b':
       पक्ष 'c':
       पक्ष 'd':
       पक्ष 'e':
       पक्ष 'f':
       पक्ष 'g':
       पक्ष 'h':
       पक्ष 'i':
       पक्ष 'j':
       पक्ष 'k':
       पक्ष 'l':
       पक्ष 'm':
       पक्ष 'n':
       पक्ष 'o':
       पक्ष 'p':
       पक्ष 'q':
       पक्ष 'r':
       पक्ष 's':
       पक्ष 't':
       पक्ष 'u':
       पक्ष 'v':
       पक्ष 'w':
       पक्ष 'x':
       पक्ष 'y':
       पक्ष 'z':
    /* case 'A' ... 'z': */
    पक्ष 'A':
       पक्ष 'B':
       पक्ष 'C':
       पक्ष 'D':
       पक्ष 'E':
       पक्ष 'F':
       पक्ष 'G':
       पक्ष 'H':
       पक्ष 'I':
       पक्ष 'J':
       पक्ष 'K':
       पक्ष 'L':
       पक्ष 'M':
       पक्ष 'N':
       पक्ष 'O':
       पक्ष 'P':
       पक्ष 'Q':
       पक्ष 'R':
       पक्ष 'S':
       पक्ष 'T':
       पक्ष 'U':
       पक्ष 'V':
       पक्ष 'W':
       पक्ष 'X':
       पक्ष 'Y':
       पक्ष 'Z':
    पक्ष '-':
    पक्ष '_':
    पक्ष '.':
    पक्ष '$':
    पक्ष '~':
        प्रति(;;) {
            ch = ld_inp(s1);
    parse_name:
            यदि (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') ||
                  strchr("/.-_+=$:\\,~", ch)))
                भङ्ग;
            यदि ((q - name) < name_आकार - 1) {
                *q++ = ch;
            }
        }
        ld_unget(s1, ch);
        c = LD_TOK_NAME;
        भङ्ग;
    पक्ष CH_EOF:
        c = LD_TOK_EOF;
        भङ्ग;
    स्वभाव:
        c = ch;
        भङ्ग;
    }
    *q = '\0';
    प्रत्यागम c;
}

स्थिर पूर्णाङ्क ld_सङ्कलय_file(TCCState *s1, ध्रुव वर्ण filename[])
{
    यदि (filename[0] == '-' && filename[1] == 'l')
        प्रत्यागम tcc_सङ्कलय_library(s1, filename + 2);
    यदि (CONFIG_SYSROOT[0] != '\0' || !IS_ABSPATH(filename)) {
        /* lookup via library paths */
        पूर्णाङ्क ret = tcc_सङ्कलय_dll(s1, tcc_basename(filename), 0);
        यदि (ret != FILE_NOT_प्राप्तम्)
            प्रत्यागम ret;
    }
    प्रत्यागम tcc_सङ्कलय_file_आन्तरिकम्(s1, filename, AFF_PRINT_ERROR);
}

/* did static libraries add new undefined symbols? */
स्थिर पूर्णाङ्क new_undef_sym(TCCState *s1, पूर्णाङ्क sym_विस्थापनम्)
{
    यावत् (sym_विस्थापनम् < s1->symtab->दत्त_विस्थापनम्) {
        ElfW(Sym) *esym = (शून्य*)(s1->symtab->दत्त + sym_विस्थापनम्);
        यदि (esym->st_shndx == SHN_UNDEF)
            प्रत्यागम 1;
        sym_विस्थापनम् += परिमाण (ElfW(Sym));
    }
    प्रत्यागम 0;
}

स्थिर पूर्णाङ्क ld_सङ्कलय_file_list(TCCState *s1, ध्रुव वर्ण *cmd)
{
    वर्ण filename[1024];
    पूर्णाङ्क t, c, sym_विस्थापनम्, ret = 0;
    अचिह्नित वर्ण *pos = s1->ld_p;

repeat:
    s1->ld_p = pos;
    sym_विस्थापनम् = s1->symtab->दत्त_विस्थापनम्;
    c = cmd[0];

    t = ld_अग्र(s1, filename, परिमाण(filename));
    यदि (t != '(')
        प्रत्यागम tcc_error_noabort("expected '(' after %s", cmd);
    t = ld_अग्र(s1, filename, परिमाण(filename));
    प्रति(;;) {
        यदि (t == LD_TOK_EOF) {
            प्रत्यागम tcc_error_noabort("unexpected end of file");
        } अन्यथा यदि (t == ')') {
            भङ्ग;
        } अन्यथा यदि (t != LD_TOK_NAME) {
            प्रत्यागम tcc_error_noabort("unexpected token '%c'", t);
        } अन्यथा यदि (!वाक्यं_तुलय(filename, "AS_NEEDED")) {
            ret |= ld_सङ्कलय_file_list(s1, filename);
        } अन्यथा यदि (c == 'I' || c == 'G' || c == 'A') {
            ret |= !!ld_सङ्कलय_file(s1, filename);
        }
        यदि (ret < 0)
            प्रत्यागम ret;
        t = ld_अग्र(s1, filename, परिमाण(filename));
        यदि (t == ',')
            t = ld_अग्र(s1, filename, परिमाण(filename));
    }
    यदि (c == 'G' && ret == 0 && new_undef_sym(s1, sym_विस्थापनम्))
        गच्छ repeat;
    प्रत्यागम ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC पूर्णाङ्क tcc_आरोपय_ldscript(TCCState *s1, पूर्णाङ्क fd)
{
    वर्ण cmd[64];
    पूर्णाङ्क t, ret = 0, noscript = 1;
    अचिह्नित वर्ण *text_ptr, *saved_ptr;

    saved_ptr = s1->ld_p;
    s1->ld_p = text_ptr = (शून्य*)tcc_आरोपय_text(fd);
    प्रति(;;) {
        t = ld_अग्र(s1, cmd, परिमाण(cmd));
        यदि (t == LD_TOK_EOF)
            भङ्ग;
        यदि (!वाक्यं_तुलय(cmd, "INPUT") ||
            !वाक्यं_तुलय(cmd, "GROUP")) {
            ret |= ld_सङ्कलय_file_list(s1, cmd);
        } अन्यथा यदि (!वाक्यं_तुलय(cmd, "OUTPUT_FORMAT") ||
                   !वाक्यं_तुलय(cmd, "TARGET")) {
            /* ignore some commands */
            ret |= ld_सङ्कलय_file_list(s1, cmd);
        } अन्यथा यदि (noscript) {
            ret = FILE_NOT_RECOGNIZED;
        } अन्यथा {
            ret = tcc_error_noabort("unexpected '%s'", cmd);
        }
        यदि (ret < 0)
            भङ्ग;
        noscript = 0;
    }
    tcc_free(text_ptr);
    s1->ld_p = saved_ptr;
    प्रत्यागम ret < 0 ? ret : -ret;
}
#यदि_अन्तः /* !ELF_OBJ_ONLY */
