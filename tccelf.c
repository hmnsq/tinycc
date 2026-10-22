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
#undef DEBUG_RELOC

/********************************************************/
/* global variables */

/* elf version information */
संरचना sym_version {
    अक्षर *lib;
    अक्षर *version;
    पूर्णांक out_index;
    पूर्णांक prev_same_lib;
};

#define nb_sym_versions     s1->nb_sym_versions
#define sym_versions        s1->sym_versions
#define nb_sym_to_version   s1->nb_sym_to_version
#define sym_to_version      s1->sym_to_version
#define dt_verneednum       s1->dt_verneednum
#define versym_section      s1->versym_section
#define verneed_section     s1->verneed_section

/* special flag to indicate that the section should not be linked to the other ones */
#define SHF_PRIVATE 0x80000000
/* section is dynsymtab_section */
#define SHF_DYNSYM 0x40000000

#ifdef TCC_TARGET_PE
#define shf_RELRO SHF_ALLOC
स्थिर स्थिरांक अक्षर rdata[] = ".rdata";
#अन्यथा
#define shf_RELRO SHF_ALLOC /* eventually made SHF_WRITE in sort_sections() */
स्थिर स्थिरांक अक्षर rdata[] = ".data.ro";
#endif

/* ------------------------------------------------------------------------- */

ST_FUNC शून्य tccelf_new(TCCState *s)
{
    TCCState *s1 = s;

    /* no section zero */
    dynarray_add(&s->sections, &s->nb_sections, रिक्त);

    /* create standard sections */
    text_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    data_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    /* create ro data section (make ro after relocation done with GNU_RELRO) */
    rodata_section = new_section(s, rdata, SHT_PROGBITS, shf_RELRO);
    bss_section = new_section(s, ".bss", SHT_NOBITS, SHF_ALLOC | SHF_WRITE);
    common_section = new_section(s, ".common", SHT_NOBITS, SHF_PRIVATE);
    common_section->sh_अंक = SHN_COMMON;

    /* symbols are always generated for linking stage */
    symtab_section = new_symtab(s, ".symtab", SHT_SYMTAB, 0,
                                ".strtab",
                                ".hashtab", SHF_PRIVATE);

    /* private symbol table for dynamic symbols */
    s->dynsymtab_section = new_symtab(s, ".dynsymtab", SHT_SYMTAB, SHF_PRIVATE|SHF_DYNSYM,
                                      ".dynstrtab",
                                      ".dynhashtab", SHF_PRIVATE);
    get_sym_attr(s, 0, 1);

    जर (s->do_debug) {
        /* add debug sections */
        tcc_debug_new(s);
    }

#जर TCC_EH_FRAME
    जर (s->output_format != TCC_OUTPUT_FORMAT_ELF)
        s->unwind_tables = 0;
    tcc_eh_frame_start(s);
#endif

#ifdef CONFIG_TCC_BCHECK
    जर (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        /* (make ro after relocation done with GNU_RELRO) */
        bounds_section = new_section(s, ".bounds", SHT_PROGBITS, shf_RELRO);
        lbounds_section = new_section(s, ".lbounds", SHT_PROGBITS, shf_RELRO);
    }
#endif

#ifdef TCC_TARGET_PE
    /* to make sure that -ltcc1 -Wl,-e,_start will grab the startup code
       from libtcc1.a (unless _start defined) */
    जर (s->elf_entryname)
        set_global_sym(s, s->elf_entryname, रिक्त, 0); /* SHN_UNDEF */
#endif

#ifndef ELF_OBJ_ONLY
    जर (रिक्त == s->elfint && s1->output_type != TCC_OUTPUT_OBJ) {
        स्थिरांक अक्षर *p = CONFIG_TCC_ELFINTERP;
#जर defined TCC_TARGET_ARM && defined CONFIG_TCC_ELFINTERP_ARMHF
        जर (s->float_abi == ARM_HARD_FLOAT)
            p = CONFIG_TCC_ELFINTERP_ARMHF;
#endif
#जर defined TCC_IS_NATIVE && defined TARGETOS_BSD
        /* see commit 55cb2170cd5ce77a7d76dcaf462fad2707281605 */
        { स्थिरांक अक्षर *e = दो_पर्या("LD_SO"); जर (e) p = e; }
#endif
        s->elfint = tcc_strdup(p);
    }
#endif /* ndef ELF_OBJ_ONLY */
}

ST_FUNC शून्य free_section(Section *s)
{
    जर (!s)
        परत;
    tcc_free(s->data);
    s->data = रिक्त;
    s->data_allocated = s->data_offset = 0;
}

ST_FUNC शून्य tccelf_delete(TCCState *s1)
{
    पूर्णांक i;

#ifndef ELF_OBJ_ONLY
    /* free symbol versions */
    साठी (i = 0; i < nb_sym_versions; i++) {
        tcc_free(sym_versions[i].version);
        tcc_free(sym_versions[i].lib);
    }
    tcc_free(sym_versions);
    tcc_free(sym_to_version);
#endif

    /* free all sections */
    साठी(i = 1; i < s1->nb_sections; i++)
        free_section(s1->sections[i]);
    dynarray_reset(&s1->sections, &s1->nb_sections);

    साठी(i = 0; i < s1->nb_priv_sections; i++)
        free_section(s1->priv_sections[i]);
    dynarray_reset(&s1->priv_sections, &s1->nb_priv_sections);

    tcc_free(s1->sym_attrs);
    symtab_section = रिक्त; /* for tccrun.c:rt_printline() */
}

/* save section data state */
ST_FUNC शून्य tccelf_begin_file(TCCState *s1)
{
    Section *s; पूर्णांक i;
    साठी (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        s->sh_offset = s->data_offset;
    }
    /* disable symbol hashing during compilation */
    s = s1->symtab, s->reloc = s->hash, s->hash = रिक्त;
#जर defined TCC_TARGET_X86_64 && defined TCC_TARGET_PE
    s1->uw_sym = 0;
    s1->uw_offs = 0;
#endif
}

स्थिर शून्य update_relocs(TCCState *s1, Section *s, पूर्णांक *old_to_new_syms, पूर्णांक first_sym);

/* At the end of compilation, convert any UNDEF syms to global, and merge
   with previously existing symbols */
ST_FUNC शून्य tccelf_end_file(TCCState *s1)
{
    Section *s = s1->symtab;
    पूर्णांक first_sym, nb_syms, *tr, i;

    first_sym = s->sh_offset / आकार (ElfSym);
    nb_syms = s->data_offset / आकार (ElfSym) - first_sym;
    s->data_offset = s->sh_offset;
    s->link->data_offset = s->link->sh_offset;
    s->hash = s->reloc, s->reloc = रिक्त;
    tr = tcc_mallocz(nb_syms * आकार *tr);

    साठी (i = 0; i < nb_syms; ++i) {
        ElfSym *sym = (ElfSym*)s->data + first_sym + i;
        जर (sym->st_shndx == SHN_UNDEF) {
            पूर्णांक sym_bind = ELFW(ST_BIND)(sym->st_info);
            पूर्णांक sym_type = ELFW(ST_TYPE)(sym->st_info);
            जर (sym_bind == STB_LOCAL)
                sym_bind = STB_GLOBAL;
#ifndef TCC_TARGET_PE
            जर (sym_bind == STB_GLOBAL && s1->output_type == TCC_OUTPUT_OBJ) {
                /* undefined symbols with STT_FUNC are confusing gnu ld when
                   linking statically to STT_GNU_IFUNC.  Keep TLS typed,
                   otherwise gnu ld rejects non-TLS refs to TLS definitions. */
                जर (sym_type != STT_TLS)
                    sym_type = STT_NOTYPE;
            }
#endif
            sym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
        }
        tr[i] = set_elf_sym(s, sym->st_मूल्य, sym->st_size, sym->st_info,
            sym->st_other, sym->st_shndx, (अक्षर*)s->link->data + sym->st_name);
    }
    /* now update relocations */
    update_relocs(s1, s, tr, first_sym);
    tcc_free(tr);
    /* record text/data/bss output for -bench info */
    साठी (i = 0; i < 4; ++i) {
        s = s1->sections[i + 1];
        s1->total_output[i] += s->data_offset - s->sh_offset;
    }
}

ST_FUNC Section *new_section(TCCState *s1, स्थिरांक अक्षर *name, पूर्णांक sh_type, पूर्णांक sh_flags)
{
    Section *sec;

    sec = tcc_mallocz(आकार(Section) + म_माप(name));
    sec->s1 = s1;
    म_नकल(sec->name, name);
    sec->sh_type = sh_type;
    sec->sh_flags = sh_flags;
    निवड(sh_type) {
    स्थिती SHT_GNU_versym:
        sec->sh_addralign = 2;
        थांबा;
    स्थिती SHT_HASH:
    स्थिती SHT_GNU_HASH:
    स्थिती SHT_REL:
    स्थिती SHT_RELA:
    स्थिती SHT_DYNSYM:
    स्थिती SHT_SYMTAB:
    स्थिती SHT_DYNAMIC:
    स्थिती SHT_GNU_verneed:
    स्थिती SHT_GNU_verdef:
        sec->sh_addralign = PTR_SIZE;
        थांबा;
    स्थिती SHT_STRTAB:
        sec->sh_addralign = 1;
        थांबा;
    पूर्वनिर्धारित:
        sec->sh_addralign =  PTR_SIZE; /* gcc/pcc default alignment */
        थांबा;
    }

    जर (sh_flags & SHF_PRIVATE) {
        dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } अन्यथा {
        sec->sh_अंक = s1->nb_sections;
        dynarray_add(&s1->sections, &s1->nb_sections, sec);
    }

    परत sec;
}

ST_FUNC शून्य init_symtab(Section *s)
{
    पूर्णांक *ptr, nb_buckets = 1;
    put_elf_str(s->link, "");
    section_ptr_add(s, आकार (ElfW(Sym)));
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + 1) * आकार(पूर्णांक));
    ptr[0] = nb_buckets;
    ptr[1] = 1;
    स_रखो(ptr + 2, 0, (nb_buckets + 1) * आकार(पूर्णांक));
}

ST_FUNC Section *new_symtab(TCCState *s1,
                           स्थिरांक अक्षर *symtab_name, पूर्णांक sh_type, पूर्णांक sh_flags,
                           स्थिरांक अक्षर *strtab_name,
                           स्थिरांक अक्षर *hash_name, पूर्णांक hash_sh_flags)
{
    Section *symtab, *strtab, *hash;
    symtab = new_section(s1, symtab_name, sh_type, sh_flags);
    symtab->sh_entsize = आकार(ElfW(Sym));
    strtab = new_section(s1, strtab_name, SHT_STRTAB, sh_flags);
    symtab->link = strtab;
    hash = new_section(s1, hash_name, SHT_HASH, hash_sh_flags);
    hash->sh_entsize = आकार(पूर्णांक);
    symtab->hash = hash;
    hash->link = symtab;
    init_symtab(symtab);
    परत symtab;
}

/* realloc section and set its content to zero */
ST_FUNC शून्य section_realloc(Section *sec, अचिन्हित दीर्घ new_size)
{
    अचिन्हित दीर्घ size;
    अचिन्हित अक्षर *data;

    size = sec->data_allocated;
    जर (size == 0)
        size = 1;
    पर्यंत (size < new_size)
        size = size * 2;
    data = tcc_realloc(sec->data, size);
    स_रखो(data + sec->data_allocated, 0, size - sec->data_allocated);
    sec->data = data;
    sec->data_allocated = size;
}

/* reserve at least 'size' bytes aligned per 'align' in section
   'sec' from current offset, and return the aligned offset */
ST_FUNC माप_प्रकार section_add(Section *sec, addr_t size, पूर्णांक align)
{
    माप_प्रकार offset, offset1;

    offset = (sec->data_offset + align - 1) & -align;
    offset1 = offset + size;
    जर (sec->sh_type != SHT_NOBITS && offset1 > sec->data_allocated)
        section_realloc(sec, offset1);
    sec->data_offset = offset1;
    जर (align > sec->sh_addralign)
        sec->sh_addralign = align;
    परत offset;
}

/* reserve at least 'size' bytes in section 'sec' from
   sec->data_offset. */
ST_FUNC शून्य *section_ptr_add(Section *sec, addr_t size)
{
    माप_प्रकार offset = section_add(sec, size, 1);
    परत sec->data + offset;
}

#ifndef ELF_OBJ_ONLY
/* reserve at least 'size' bytes from section start */
स्थिर शून्य section_reserve(Section *sec, अचिन्हित दीर्घ size)
{
    जर (size > sec->data_allocated)
        section_realloc(sec, size);
    जर (size > sec->data_offset)
        sec->data_offset = size;
}
#endif

स्थिर Section *have_section(TCCState *s1, स्थिरांक अक्षर *name)
{
    Section *sec;
    पूर्णांक i;
    साठी(i = 1; i < s1->nb_sections; i++) {
        sec = s1->sections[i];
        जर (!म_भेद(name, sec->name))
            परत sec;
    }
    परत रिक्त;
}

/* return a reference to a section, and create it if it does not
   exists */
ST_FUNC Section *find_section(TCCState *s1, स्थिरांक अक्षर *name)
{
    Section *sec = have_section(s1, name);
    जर (sec)
        परत sec;
    /* sections are created as PROGBITS */
    परत new_section(s1, name, SHT_PROGBITS, SHF_ALLOC);
}

/* ------------------------------------------------------------------------- */

ST_FUNC पूर्णांक put_elf_str(Section *s, स्थिरांक अक्षर *sym)
{
    पूर्णांक offset, len;
    अक्षर *ptr;

    len = म_माप(sym) + 1;
    offset = s->data_offset;
    ptr = section_ptr_add(s, len);
    स_हटाओ(ptr, sym, len);
    परत offset;
}

/* elf symbol hashing function */
स्थिर ElfW(Word) elf_hash(स्थिरांक अचिन्हित अक्षर *name)
{
    ElfW(Word) h = 0, g;

    पर्यंत (*name) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        जर (g)
            h ^= g >> 24;
        h &= ~g;
    }
    परत h;
}

/* rebuild hash table of section s */
/* NOTE: we do factorize the hash table code to go faster */
स्थिर शून्य rebuild_hash(Section *s, अचिन्हित पूर्णांक nb_buckets)
{
    ElfW(Sym) *sym;
    पूर्णांक *ptr, *hash, nb_syms, sym_index, h;
    अचिन्हित अक्षर *strtab;

    strtab = s->link->data;
    nb_syms = s->data_offset / आकार(ElfW(Sym));

    जर (!nb_buckets)
        nb_buckets = ((पूर्णांक*)s->hash->data)[0];

    s->hash->data_offset = 0;
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + nb_syms) * आकार(पूर्णांक));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    स_रखो(hash, 0, (nb_buckets + 1) * आकार(पूर्णांक));
    ptr += nb_buckets + 1;

    sym = (ElfW(Sym) *)s->data + 1;
    साठी(sym_index = 1; sym_index < nb_syms; sym_index++) {
        जर (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            h = elf_hash(strtab + sym->st_name) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_index;
        } अन्यथा {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}

/* return the symbol number */
ST_FUNC पूर्णांक put_elf_sym(Section *s, addr_t मूल्य, अचिन्हित दीर्घ size,
    पूर्णांक info, पूर्णांक other, पूर्णांक shndx, स्थिरांक अक्षर *name)
{
    पूर्णांक name_offset, sym_index;
    पूर्णांक nbuckets, h;
    ElfW(Sym) *sym;
    Section *hs;

    sym = section_ptr_add(s, आकार(ElfW(Sym)));
    जर (name && name[0])
        name_offset = put_elf_str(s->link, name);
    अन्यथा
        name_offset = 0;
    /* XXX: endianness */
    sym->st_name = name_offset;
    sym->st_मूल्य = मूल्य;
    sym->st_size = size;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
    sym_index = sym - (ElfW(Sym) *)s->data;
    hs = s->hash;
    जर (hs) {
        पूर्णांक *ptr, *base;
        ptr = section_ptr_add(hs, आकार(पूर्णांक));
        base = (पूर्णांक *)hs->data;
        /* only add global or weak symbols. */
        जर (ELFW(ST_BIND)(info) != STB_LOCAL) {
            /* add another hashing entry */
            nbuckets = base[0];
            h = elf_hash((अचिन्हित अक्षर *)s->link->data + name_offset) % nbuckets;
            *ptr = base[2 + h];
            base[2 + h] = sym_index;
            base[1]++;
            /* we resize the hash table */
            hs->nb_hashed_syms++;
            जर (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } अन्यथा {
            *ptr = 0;
            base[1]++;
        }
    }
    परत sym_index;
}

ST_FUNC पूर्णांक find_elf_sym(Section *s, स्थिरांक अक्षर *name)
{
    ElfW(Sym) *sym;
    Section *hs;
    पूर्णांक nbuckets, sym_index, h;
    स्थिरांक अक्षर *name1;

    hs = s->hash;
    जर (!hs)
        परत 0;
    nbuckets = ((पूर्णांक *)hs->data)[0];
    h = elf_hash((अचिन्हित अक्षर *) name) % nbuckets;
    sym_index = ((पूर्णांक *)hs->data)[2 + h];
    पर्यंत (sym_index != 0) {
        sym = &((ElfW(Sym) *)s->data)[sym_index];
        name1 = (अक्षर *) s->link->data + sym->st_name;
        जर (!म_भेद(name, name1))
            परत sym_index;
        sym_index = ((पूर्णांक *)hs->data)[2 + nbuckets + sym_index];
    }
    परत 0;
}

/* return elf symbol value, signal error if 'err' is nonzero, decorate
   name if FORC */
ST_FUNC addr_t get_sym_addr(TCCState *s1, स्थिरांक अक्षर *name, पूर्णांक err, पूर्णांक forc)
{
    पूर्णांक sym_index;
    ElfW(Sym) *sym;
    अक्षर buf[256];
    जर (forc && s1->leading_underscore
#ifdef TCC_TARGET_PE
        /* win32-32bit stdcall symbols always have _ already */
        && !म_अक्षर(name, '@')
#endif
        ) {
        buf[0] = '_';
        pstrcpy(buf + 1, आकार(buf) - 1, name);
        name = buf;
    }
    sym_index = find_elf_sym(s1->symtab, name);
    sym = &((ElfW(Sym) *)s1->symtab->data)[sym_index];
    जर (!sym_index || sym->st_shndx == SHN_UNDEF) {
        जर (err)
            tcc_error_noabort("%s not defined", name);
        परत (addr_t)-1;
    }
    परत sym->st_मूल्य;
}

/* return elf symbol value */
LIBTCCAPI शून्य *tcc_get_चिन्ह(TCCState *s, स्थिरांक अक्षर *name)
{
    addr_t addr = get_sym_addr(s, name, 0, 1);
    परत addr == -1 ? रिक्त : (शून्य*)(uintptr_t)addr;
}

LIBTCCAPI पूर्णांक tcc_add_चिन्ह(TCCState *s1, स्थिरांक अक्षर *name, स्थिरांक शून्य *val)
{
#ifdef TCC_TARGET_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s1, 0, name, (uintptr_t)val);
#अन्यथा
    अक्षर buf[256];
    जर (s1->leading_underscore) {
        buf[0] = '_';
        pstrcpy(buf + 1, आकार(buf) - 1, name);
        name = buf;
    }
    set_global_sym(s1, name, रिक्त, (addr_t)(uintptr_t)val); /* NULL: SHN_ABS */
#endif
    परत 0;
}

/* list elf symbol names and values */
ST_FUNC शून्य list_elf_symbols(TCCState *s, शून्य *ctx,
    शून्य (*चिन्ह_cb)(शून्य *ctx, स्थिरांक अक्षर *name, स्थिरांक शून्य *val))
{
    ElfW(Sym) *sym;
    Section *symtab;
    पूर्णांक sym_index, end_sym;
    स्थिरांक अक्षर *name;
    अचिन्हित अक्षर sym_vis, sym_bind;

    symtab = s->symtab;
    end_sym = symtab->data_offset / आकार (ElfSym);
    साठी (sym_index = 0; sym_index < end_sym; ++sym_index) {
        sym = &((ElfW(Sym) *)symtab->data)[sym_index];
        जर (sym->st_मूल्य) {
            name = (अक्षर *) symtab->link->data + sym->st_name;
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            sym_vis = ELFW(ST_VISIBILITY)(sym->st_other);
            जर (sym_bind == STB_GLOBAL && sym_vis == STV_DEFAULT)
                चिन्ह_cb(ctx, name, (शून्य*)(uintptr_t)sym->st_मूल्य);
        }
    }
}

/* list elf symbol names and values */
LIBTCCAPI शून्य tcc_list_symbols(TCCState *s, शून्य *ctx,
    शून्य (*चिन्ह_cb)(शून्य *ctx, स्थिरांक अक्षर *name, स्थिरांक शून्य *val))
{
    list_elf_symbols(s, ctx, चिन्ह_cb);
}

#ifndef ELF_OBJ_ONLY
स्थिर शून्य
version_add (TCCState *s1)
{
    पूर्णांक i;
    ElfW(Sym) *sym;
    ElfW(Verneed) *vn = रिक्त;
    Section *symtab;
    पूर्णांक sym_index, end_sym, nb_versions = 2, nb_entries = 0;
    ElfW(Half) *versym;
    स्थिरांक अक्षर *name;

    जर (0 == nb_sym_versions)
        परत;
    versym_section = new_section(s1, ".gnu.version", SHT_GNU_versym, SHF_ALLOC);
    versym_section->sh_entsize = आकार(ElfW(Half));
    versym_section->link = s1->dynsym;

    /* add needed symbols */
    symtab = s1->dynsym;
    end_sym = symtab->data_offset / आकार (ElfSym);
    versym = section_ptr_add(versym_section, end_sym * आकार(ElfW(Half)));
    साठी (sym_index = 1; sym_index < end_sym; ++sym_index) {
        पूर्णांक dllindex, verndx;
        sym = &((ElfW(Sym) *)symtab->data)[sym_index];
        name = (अक्षर *) symtab->link->data + sym->st_name;
        dllindex = find_elf_sym(s1->dynsymtab_section, name);
        verndx = (dllindex && dllindex < nb_sym_to_version)
                 ? sym_to_version[dllindex] : -1;
        जर (verndx >= 0
            /* XXX: on android, clang refuses to link with a libtcc.so made by tcc
               when defined symbols have a version > 1 or when the version is '0'.
               Whereas version '1' for example for 'signal' in an exe defeats
               bcheck's signal_redir. */
            && (sym->st_shndx == SHN_UNDEF || (s1->output_type & TCC_OUTPUT_EXE))
            ) {
            जर (!sym_versions[verndx].out_index)
              sym_versions[verndx].out_index = nb_versions++;
            versym[sym_index] = sym_versions[verndx].out_index;
        } अन्यथा {
            versym[sym_index] = 1; /* (*global*) */
        }
        //printf("SYM %d %s\n", versym[sym_index], name);
    }
    /* generate verneed section, but not when it will be empty.  Some
       dynamic linkers look at their contents even when DTVERNEEDNUM and
       section size is zero.  */
    जर (nb_versions > 2) {
        verneed_section = new_section(s1, ".gnu.version_r",
                                      SHT_GNU_verneed, SHF_ALLOC);
        verneed_section->link = s1->dynsym->link;
        साठी (i = nb_sym_versions; i-- > 0;) {
            संरचना sym_version *sv = &sym_versions[i];
            पूर्णांक n_same_libs = 0, prev;
            माप_प्रकार vnofs;
            ElfW(Vernaux) *vna = 0;
            जर (sv->out_index < 1)
              सुरूठेवा;

            /* make sure that a DT_NEEDED tag is put */
            /* abitest-tcc fails on older i386-linux with "ld-linux.so.2" DT_NEEDED
               ret_int_test... Inconsistency detected by ld.so: dl-minimal.c: 148:
               realloc: Assertion `ptr == alloc_last_block' failed! */
            जर (म_भेद(sv->lib, "ld-linux.so.2"))
                tcc_add_dllref(s1, sv->lib, 0);

            vnofs = section_add(verneed_section, आकार(*vn), 1);
            vn = (ElfW(Verneed)*)(verneed_section->data + vnofs);
            vn->vn_version = 1;
            vn->vn_file = put_elf_str(verneed_section->link, sv->lib);
            vn->vn_aux = आकार (*vn);
            करा {
                prev = sv->prev_same_lib;
                जर (sv->out_index > 0) {
                    vna = section_ptr_add(verneed_section, आकार(*vna));
                    vna->vna_hash = elf_hash ((स्थिरांक अचिन्हित अक्षर *)sv->version);
                    vna->vna_flags = 0;
                    vna->vna_other = sv->out_index;
                    sv->out_index = -2;
                    vna->vna_name = put_elf_str(verneed_section->link, sv->version);
                    vna->vna_next = आकार (*vna);
                    //printf("LIB %d %s %s\n", vna->vna_other, sv->lib, verneed_section->link->data + vna->vna_name);
                    n_same_libs++;
                }
                जर (prev >= 0)
                  sv = &sym_versions[prev];
            } पर्यंत(prev >= 0);
            vna->vna_next = 0;
            vn = (ElfW(Verneed)*)(verneed_section->data + vnofs);
            vn->vn_cnt = n_same_libs;
            vn->vn_next = आकार(*vn) + n_same_libs * आकार(*vna);
            nb_entries++;
        }
        जर (vn)
          vn->vn_next = 0;
        verneed_section->sh_info = nb_entries;
    }
    dt_verneednum = nb_entries;
}
#endif /* ndef ELF_OBJ_ONLY */

/* catch .tbss also */
स्थिर पूर्णांक IS_BSS(TCCState *s1, पूर्णांक ndx)
{
    परत ndx == SHN_COMMON
     || (ndx < s1->nb_sections
         && s1->sections[ndx]->sh_type == SHT_NOBITS);
}

/* add an elf symbol : check if it is already defined and patch
   it. Return symbol index. NOTE that sh_num can be SHN_UNDEF. */
ST_FUNC पूर्णांक set_elf_sym(Section *s, addr_t मूल्य, अचिन्हित दीर्घ size,
                       पूर्णांक info, पूर्णांक other, पूर्णांक shndx, स्थिरांक अक्षर *name)
{
    TCCState *s1 = s->s1;
    ElfW(Sym) *esym;
    पूर्णांक sym_bind, sym_index, sym_type, esym_bind;
    अचिन्हित अक्षर sym_vis, esym_vis, new_vis;

    sym_bind = ELFW(ST_BIND)(info);
    sym_type = ELFW(ST_TYPE)(info);
    sym_vis = ELFW(ST_VISIBILITY)(other);

    जर (sym_bind != STB_LOCAL) {
        /* we search global or weak symbols */
        sym_index = find_elf_sym(s, name);
        जर (!sym_index)
            जा do_def;
        esym = &((ElfW(Sym) *)s->data)[sym_index];
        जर (esym->st_मूल्य == मूल्य && esym->st_size == size && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            परत sym_index;
        जर (esym->st_shndx != SHN_UNDEF) {
            esym_bind = ELFW(ST_BIND)(esym->st_info);
            /* propagate the most constraining visibility */
            /* STV_DEFAULT(0)<STV_PROTECTED(3)<STV_HIDDEN(2)<STV_INTERNAL(1) */
            esym_vis = ELFW(ST_VISIBILITY)(esym->st_other);
            जर (esym_vis == STV_DEFAULT) {
                new_vis = sym_vis;
            } अन्यथा जर (sym_vis == STV_DEFAULT) {
                new_vis = esym_vis;
            } अन्यथा {
                new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
            }
            esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
                             | new_vis;
            जर (shndx == SHN_UNDEF) {
                /* ignore adding of undefined symbol if the
                   corresponding symbol is already defined */
            } अन्यथा जर (sym_bind == STB_GLOBAL && esym_bind == STB_WEAK) {
                /* global overrides weak, so patch */
                जा do_patch;
            } अन्यथा जर (sym_bind == STB_WEAK && esym_bind == STB_GLOBAL) {
                /* weak is ignored if already global */
            } अन्यथा जर (sym_bind == STB_WEAK && esym_bind == STB_WEAK) {
                /* keep first-found weak definition, ignore subsequents */
            } अन्यथा जर (sym_vis == STV_HIDDEN || sym_vis == STV_INTERNAL) {
                /* ignore hidden symbols after */
            } अन्यथा जर (s->sh_flags & SHF_DYNSYM) {
                /* we accept that two DLL define the same symbol */
            } अन्यथा जर (!IS_BSS(s1, shndx) && IS_BSS(s1, esym->st_shndx)) {
                /* data symbol gets precedence over common/bss */
                जा do_patch;
            } अन्यथा जर (IS_BSS(s1, shndx)) {
                /* data symbol keeps precedence over common/bss */
	    } अन्यथा जर (esym->st_other & ST_ASM_SET) {
		/* If the existing symbol came from an asm .set
		   we can override.  */
		जा do_patch;
            } अन्यथा {
#जर 0
                म_लिखो("new_bind=%x new_shndx=%x new_vis=%x old_bind=%x old_shndx=%x old_vis=%x\n",
                       sym_bind, shndx, new_vis, esym_bind, esym->st_shndx, esym_vis);
#endif
                tcc_error_noabort("link symbol '%s' defined twice", name);
            }
        } अन्यथा {
            esym->st_other = other;
        do_patch:
            esym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
            esym->st_shndx = shndx;
            esym->st_मूल्य = मूल्य;
            esym->st_size = size;
        }
    } अन्यथा {
    do_def:
        sym_index = put_elf_sym(s, मूल्य, size,
                                ELFW(ST_INFO)(sym_bind, sym_type), other,
                                shndx, name);
    }
    परत sym_index;
}

/* put relocation */
ST_FUNC शून्य put_elf_reloca(Section *symtab, Section *s, अचिन्हित दीर्घ offset,
                            पूर्णांक type, पूर्णांक चिन्ह, addr_t addend)
{
    TCCState *s1 = s->s1;
    अक्षर buf[256];
    Section *sr;
    ElfW_Rel *rel;

    sr = s->reloc;
    जर (!sr) {
        /* if no relocation section, create it */
        snprintf(buf, आकार(buf), REL_SECTION_FMT, s->name);
        /* if the symtab is allocated, then we consider the relocation
           are also */
        sr = new_section(s->s1, buf, SHT_RELX, symtab->sh_flags);
        sr->sh_entsize = आकार(ElfW_Rel);
        sr->link = symtab;
        sr->sh_info = s->sh_अंक;
        s->reloc = sr;
    }
    rel = section_ptr_add(sr, आकार(ElfW_Rel));
    rel->r_offset = offset;
    rel->r_info = ELFW(R_INFO)(चिन्ह, type);
#जर SHT_RELX == SHT_RELA
    rel->r_addend = addend;
#endif
    जर (SHT_RELX != SHT_RELA && addend)
        tcc_error_noabort("non-zero addend on REL architecture");
}

ST_FUNC शून्य put_elf_reloc(Section *symtab, Section *s, अचिन्हित दीर्घ offset,
                           पूर्णांक type, पूर्णांक चिन्ह)
{
    put_elf_reloca(symtab, s, offset, type, चिन्ह, 0);
}

ST_FUNC संरचना sym_attr *get_sym_attr(TCCState *s1, पूर्णांक index, पूर्णांक alloc)
{
    पूर्णांक n;
    संरचना sym_attr *tab;

    जर (index >= s1->nb_sym_attrs) {
        जर (!alloc)
            परत s1->sym_attrs;
        /* find immediately bigger power of 2 and reallocate array */
        n = 1;
        पर्यंत (index >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * आकार(*s1->sym_attrs));
        s1->sym_attrs = tab;
        स_रखो(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * आकार(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    परत &s1->sym_attrs[index];
}

स्थिर शून्य update_relocs(TCCState *s1, Section *s, पूर्णांक *old_to_new_syms, पूर्णांक first_sym)
{
    पूर्णांक i, type, sym_index;
    Section *sr;
    ElfW_Rel *rel;

    साठी(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        जर (sr->sh_type == SHT_RELX && sr->link == s) {
            for_each_elem(sr, 0, rel, ElfW_Rel) {
                sym_index = ELFW(R_SYM)(rel->r_info);
                type = ELFW(R_TYPE)(rel->r_info);
                जर ((sym_index -= first_sym) < 0)
                    सुरूठेवा; /* zero sym_index in reloc (can happen with asm) */
                sym_index = old_to_new_syms[sym_index];
                rel->r_info = ELFW(R_INFO)(sym_index, type);
            }
        }
    }
}

/* In an ELF file symbol table, the local symbols must appear below
   the global and weak ones. Since TCC cannot sort it while generating
   the code, we must do it after. All the relocation tables are also
   modified to take into account the symbol table sorting */
स्थिर शून्य sort_syms(TCCState *s1, Section *s)
{
    पूर्णांक *old_to_new_syms;
    ElfW(Sym) *new_syms;
    पूर्णांक nb_syms, i;
    ElfW(Sym) *p, *q;

    nb_syms = s->data_offset / आकार(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * आकार(ElfW(Sym)));
    old_to_new_syms = tcc_malloc(nb_syms * आकार(पूर्णांक));

    /* first pass for local symbols */
    p = (ElfW(Sym) *)s->data;
    q = new_syms;
    साठी(i = 0; i < nb_syms; i++) {
        जर (ELFW(ST_BIND)(p->st_info) == STB_LOCAL) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    /* save the number of local symbols in section header */
    जर( s->sh_size )    /* this 'if' makes IDA happy */
        s->sh_info = q - new_syms;

    /* then second pass for non local symbols */
    p = (ElfW(Sym) *)s->data;
    साठी(i = 0; i < nb_syms; i++) {
        जर (ELFW(ST_BIND)(p->st_info) != STB_LOCAL) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }

    /* we copy the new symbols to the old */
    स_नकल(s->data, new_syms, nb_syms * आकार(ElfW(Sym)));
    tcc_free(new_syms);

    update_relocs(s1, s, old_to_new_syms, 0);
    tcc_free(old_to_new_syms);
}

#ifndef ELF_OBJ_ONLY
/* See: https://flapenguin.me/elf-dt-gnu-hash */
#define	ELFCLASS_BITS (PTR_SIZE * 8)

स्थिर Section *create_gnu_hash(TCCState *s1)
{
    पूर्णांक nb_syms, i, ndef, nbuckets, symoffset, bloom_size, bloom_shift;
    ElfW(Sym) *p;
    Section *gnu_hash;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr;

    gnu_hash = new_section(s1, ".gnu.hash", SHT_GNU_HASH, SHF_ALLOC);
    gnu_hash->link = dynsym->hash->link;

    nb_syms = dynsym->data_offset / आकार(ElfW(Sym));

    /* count def symbols */
    ndef = 0;
    p = (ElfW(Sym) *)dynsym->data;
    साठी(i = 0; i < nb_syms; i++, p++)
        ndef += p->st_shndx != SHN_UNDEF;

    /* calculate gnu hash sizes and fill header */
    nbuckets = ndef / 4 + 1;
    symoffset = nb_syms - ndef;
    bloom_shift = PTR_SIZE == 8 ? 6 : 5;
    bloom_size = 1; /* must be power of two */
    पर्यंत (ndef >= bloom_size * (1 << (bloom_shift - 3)))
	bloom_size *= 2;
    ptr = section_ptr_add(gnu_hash, 4 * 4 +
				    PTR_SIZE * bloom_size +
				    nbuckets * 4 +
				    ndef * 4);
    ptr[0] = nbuckets;
    ptr[1] = symoffset;
    ptr[2] = bloom_size;
    ptr[3] = bloom_shift;
    परत gnu_hash;
}

स्थिर Elf32_Word elf_gnu_hash (स्थिरांक अचिन्हित अक्षर *name)
{
    Elf32_Word h = 5381;
    अचिन्हित अक्षर c;

    पर्यंत ((c = *name++))
        h = h * 33 + c;
    परत h;
}

स्थिर शून्य update_gnu_hash(TCCState *s1, Section *gnu_hash)
{
    पूर्णांक *old_to_new_syms;
    ElfW(Sym) *new_syms;
    पूर्णांक nb_syms, i, nbuckets, bloom_size, bloom_shift;
    ElfW(Sym) *p, *q;
    Section *vs;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr, *buckets, *chain, *hash;
    अचिन्हित पूर्णांक *nextbuck;
    addr_t *bloom;
    अचिन्हित अक्षर *strtab;
    संरचना { पूर्णांक first, last; } *buck;

    strtab = dynsym->link->data;
    nb_syms = dynsym->data_offset / आकार(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * आकार(ElfW(Sym)));
    old_to_new_syms = tcc_malloc(nb_syms * आकार(पूर्णांक));
    hash = tcc_malloc(nb_syms * आकार(Elf32_Word));
    nextbuck = tcc_malloc(nb_syms * आकार(पूर्णांक));

    /* calculate hashes and copy undefs */
    p = (ElfW(Sym) *)dynsym->data;
    q = new_syms;
    साठी(i = 0; i < nb_syms; i++, p++) {
        जर (p->st_shndx == SHN_UNDEF) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
	अन्यथा
	    hash[i] = elf_gnu_hash(strtab + p->st_name);
    }

    ptr = (Elf32_Word *) gnu_hash->data;
    nbuckets = ptr[0];
    bloom_size = ptr[2];
    bloom_shift = ptr[3];
    bloom = (addr_t *) (शून्य *) &ptr[4];
    buckets = (Elf32_Word*) (शून्य *) &bloom[bloom_size];
    chain = &buckets[nbuckets];
    buck = tcc_malloc(nbuckets * आकार(*buck));

    जर (gnu_hash->data_offset != 4 * 4 +
				 PTR_SIZE * bloom_size +
				 nbuckets * 4 +
				 (nb_syms - (q - new_syms)) * 4)
	tcc_error_noabort ("gnu_hash size incorrect");

    /* find buckets */
    साठी(i = 0; i < nbuckets; i++)
	buck[i].first = -1;

    p = (ElfW(Sym) *)dynsym->data;
    साठी(i = 0; i < nb_syms; i++, p++)
        जर (p->st_shndx != SHN_UNDEF) {
	    पूर्णांक bucket = hash[i] % nbuckets;

	    जर (buck[bucket].first == -1)
		buck[bucket].first = buck[bucket].last = i;
	    अन्यथा {
		nextbuck[buck[bucket].last] = i;
		buck[bucket].last = i;
	    }
	}

    /* fill buckets/chains/bloom and sort symbols */
    p = (ElfW(Sym) *)dynsym->data;
    साठी(i = 0; i < nbuckets; i++) {
	पूर्णांक cur = buck[i].first;

	जर (cur != -1) {
	    buckets[i] = q - new_syms;
	    साठी (;;) {
                old_to_new_syms[cur] = q - new_syms;
                *q++ = p[cur];
	        *chain++ = hash[cur] & ~1;
		bloom[(hash[cur] / ELFCLASS_BITS) % bloom_size] |=
		    (addr_t)1 << (hash[cur] % ELFCLASS_BITS) |
		    (addr_t)1 << ((hash[cur] >> bloom_shift) % ELFCLASS_BITS);
		जर (cur == buck[i].last)
		    थांबा;
		cur = nextbuck[cur];
	    }
	    chain[-1] |= 1;
	}
    }

    स_नकल(dynsym->data, new_syms, nb_syms * आकार(ElfW(Sym)));
    tcc_free(new_syms);
    tcc_free(hash);
    tcc_free(buck);
    tcc_free(nextbuck);

    update_relocs(s1, dynsym, old_to_new_syms, 0);

    /* modify the versions */
    vs = versym_section;
    जर (vs) {
	ElfW(Half) *newver, *versym = (ElfW(Half) *)vs->data;

	जर (1/*versym*/) {
            newver = tcc_malloc(nb_syms * आकार(*newver));
	    साठी (i = 0; i < nb_syms; i++)
	        newver[old_to_new_syms[i]] = versym[i];
	    स_नकल(vs->data, newver, nb_syms * आकार(*newver));
	    tcc_free(newver);
	}
    }

    tcc_free(old_to_new_syms);

    /* rebuild hash */
    ptr = (Elf32_Word *) dynsym->hash->data;
    rebuild_hash(dynsym, ptr[0]);
}
#endif /* ELF_OBJ_ONLY */

/* relocate symbol table, resolve undefined symbols if do_resolve is
   true and output error if undefined symbol. */
ST_FUNC शून्य relocate_syms(TCCState *s1, Section *symtab, पूर्णांक do_resolve)
{
    ElfW(Sym) *sym;
    पूर्णांक sym_bind, sh_अंक;
    स्थिरांक अक्षर *name;

    for_each_elem(symtab, 1, sym, ElfW(Sym)) {
        sh_अंक = sym->st_shndx;
        जर (sh_अंक == SHN_UNDEF) {
            जर (do_resolve == 2) /* relocating dynsym */
                सुरूठेवा;
            name = (अक्षर *) s1->symtab->link->data + sym->st_name;
            /* Use ld.so to resolve symbol for us (for tcc -run) */
            जर (do_resolve) {
#जर defined TCC_IS_NATIVE && !defined TCC_TARGET_PE
                /* dlsym() needs the undecorated name.  */
                स्थिरांक अक्षर *name_ud = &name[s1->leading_underscore];
                शून्य *addr = रिक्त;
                जर (!s1->nostdlib)
                    addr = dlsym(RTLD_DEFAULT, name_ud);
		जर (addr == रिक्त) {
		    पूर्णांक i;
		    साठी (i = 0; i < s1->nb_loaded_dlls; i++)
                        जर ((addr = dlsym(s1->loaded_dlls[i]->handle, name_ud)))
			    थांबा;
		}
                जर (addr) {
                    sym->st_मूल्य = (addr_t) addr;
#ifdef DEBUG_RELOC
		    म_लिखो ("relocate_sym: %s -> 0x%lx\n", name, sym->st_मूल्य);
#endif
                    जा found;
                }
#endif
            /* if dynamic symbol exist, it will be used in relocate_section */
            } अन्यथा जर (s1->dynsym && find_elf_sym(s1->dynsym, name))
                जा found;
            /* XXX: _fp_hw seems to be part of the ABI, so we ignore
               it */
            जर (!म_भेद(name, "_fp_hw"))
                जा found;
            /* only weak symbols are accepted to be undefined. Their
               value is zero */
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            जर (sym_bind == STB_WEAK)
                sym->st_मूल्य = 0;
            अन्यथा
                tcc_error_noabort("unresolved reference to '%s'", name);

        } अन्यथा जर (sh_अंक < SHN_LORESERVE) {
            /* add section base */
            sym->st_मूल्य += s1->sections[sym->st_shndx]->sh_addr;
        }
    found: ;
    }
}

/* relocate a given section (CPU dependent) by applying the relocations
   in the associated relocation section */
स्थिर शून्य relocate_section(TCCState *s1, Section *s, Section *sr)
{
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    पूर्णांक type, sym_index;
    अचिन्हित अक्षर *ptr;
    addr_t tgt, addr;
    पूर्णांक is_dwarf = s->sh_अंक >= s1->dwlo && s->sh_अंक < s1->dwhi;

    qrel = (ElfW_Rel *)sr->data;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
	जर (s->data == रिक्त) /* bss */
	    सुरूठेवा;
        ptr = s->data + rel->r_offset;
        sym_index = ELFW(R_SYM)(rel->r_info);
        sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
        type = ELFW(R_TYPE)(rel->r_info);
        tgt = sym->st_मूल्य;
#जर SHT_RELX == SHT_RELA
        tgt += rel->r_addend;
#endif
        जर (is_dwarf && type == R_DATA_32DW
            && sym->st_shndx >= s1->dwlo && sym->st_shndx < s1->dwhi) {
            /* dwarf section relocation to each other */
            add32le(ptr, tgt - s1->sections[sym->st_shndx]->sh_addr);
            सुरूठेवा;
        }
        addr = s->sh_addr + rel->r_offset;
        relocate(s1, rel, type, ptr, addr, tgt);
    }

#ifndef ELF_OBJ_ONLY
    /* if the relocation is allocated, we change its symbol table */
    जर (sr->sh_flags & SHF_ALLOC) {
        sr->link = s1->dynsym;
        जर (s1->output_type & TCC_OUTPUT_DYN) {
            माप_प्रकार r = (uint8_t*)qrel - sr->data;
            जर (आकार ((Stab_Sym*)0)->n_मूल्य < PTR_SIZE
                && 0 == म_भेद(s->name, ".stab"))
                r = 0; /* cannot apply 64bit relocation to 32bit value */
            sr->data_offset = sr->sh_size = r;
#ifdef CONFIG_TCC_PIE
            जर (r && (s->sh_flags & SHF_EXECINSTR))
                tcc_warning("%d relocations to %s", (अचिन्हित)(r / आकार *qrel), s->name);
#endif
        }
    }
#endif

#ifdef TCC_TARGET_RISCV64
    dynarray_reset(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries);
#endif
}

/* relocate all sections */
ST_FUNC शून्य relocate_sections(TCCState *s1)
{
    पूर्णांक i;
    Section *s, *sr;

    साठी (i = 1; i < s1->nb_sections; ++i) {
        sr = s1->sections[i];
        जर (sr->sh_type != SHT_RELX)
            सुरूठेवा;
        s = s1->sections[sr->sh_info];
#ifndef TCC_TARGET_MACHO
        जर (s != s1->got
            || s1->static_link
            || s1->output_type == TCC_OUTPUT_MEMORY)
#endif
        {
            relocate_section(s1, s, sr);
        }
#ifndef ELF_OBJ_ONLY
        जर (sr->sh_flags & SHF_ALLOC) {
            ElfW_Rel *rel;
            /* relocate relocation table in 'sr' */
            for_each_elem(sr, 0, rel, ElfW_Rel)
                rel->r_offset += s->sh_addr;
        }
#endif
    }
}

#ifndef ELF_OBJ_ONLY
/* count the number of dynamic relocations so that we can reserve
   their space */
स्थिर पूर्णांक prepare_dynamic_rel(TCCState *s1, Section *sr)
{
    पूर्णांक मोजणी_2 = 0;
#जर defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || \
    defined(TCC_TARGET_ARM) || defined(TCC_TARGET_ARM64) || \
    defined(TCC_TARGET_RISCV64)
    ElfW_Rel *rel;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
        पूर्णांक sym_index = ELFW(R_SYM)(rel->r_info);
        पूर्णांक type = ELFW(R_TYPE)(rel->r_info);
        निवड(type) {
#जर defined(TCC_TARGET_I386)
        स्थिती R_386_32:
            जर (!get_sym_attr(s1, sym_index, 0)->dyn_index
                && ((ElfW(Sym)*)symtab_section->data + sym_index)->st_shndx == SHN_UNDEF) {
                /* don't fixup unresolved (weak) symbols */
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_RELATIVE);
                थांबा;
            }
#किंवाजर defined(TCC_TARGET_X86_64)
        स्थिती R_X86_64_32:
        स्थिती R_X86_64_32S:
        स्थिती R_X86_64_64:
#किंवाजर defined(TCC_TARGET_ARM)
        स्थिती R_ARM_ABS32:
        स्थिती R_ARM_TARGET1:
#किंवाजर defined(TCC_TARGET_ARM64)
        स्थिती R_AARCH64_ABS32:
        स्थिती R_AARCH64_ABS64:
#किंवाजर defined(TCC_TARGET_RISCV64)
        स्थिती R_RISCV_32:
        स्थिती R_RISCV_64:
#endif
            मोजणी_2++;
            थांबा;
#जर defined(TCC_TARGET_I386)
        स्थिती R_386_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    जर (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_PLT32);
	        थांबा;
	    }
	}
#किंवाजर defined(TCC_TARGET_X86_64)
        स्थिती R_X86_64_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    जर (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_index, R_X86_64_PLT32);
	        थांबा;
	    }
	}
#किंवाजर defined(TCC_TARGET_ARM64)
        स्थिती R_AARCH64_PREL32:
#endif
            जर (s1->output_type != TCC_OUTPUT_DLL)
                थांबा;
            जर (get_sym_attr(s1, sym_index, 0)->dyn_index)
                मोजणी_2++;
            थांबा;
        पूर्वनिर्धारित:
            थांबा;
        }
    }
#endif
    परत मोजणी_2;
}
#endif

#ifdef NEED_BUILD_GOT
स्थिर पूर्णांक build_got(TCCState *s1)
{
    /* if no got, then create it */
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    s1->got->sh_entsize = 4;
    /* keep space for _DYNAMIC pointer and two dummy got entries */
    section_ptr_add(s1->got, 3 * PTR_SIZE);
    परत set_elf_sym(symtab_section, 0, 0, ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
        0, s1->got->sh_अंक, "_GLOBAL_OFFSET_TABLE_");
}

/* Create a GOT and (for function call) a PLT entry corresponding to a symbol
   in s1->symtab. When creating the dynamic symbol table entry for the GOT
   relocation, use 'size' and 'info' for the corresponding symbol metadata.
   Returns the offset of the GOT or (if any) PLT entry. */
स्थिर संरचना sym_attr * put_got_entry(TCCState *s1, पूर्णांक dyn_reloc_type,
                                       पूर्णांक sym_index)
{
    पूर्णांक need_plt_entry;
    स्थिरांक अक्षर *name;
    ElfW(Sym) *sym;
    संरचना sym_attr *attr;
    अचिन्हित got_offset;
    अक्षर plt_name[200];
    पूर्णांक len;
    Section *s_rel;

    need_plt_entry = (dyn_reloc_type == R_JMP_SLOT);
    attr = get_sym_attr(s1, sym_index, 1);

    /* In case a function is both called and its address taken 2 GOT entries
       are created, one for taking the address (GOT) and the other for the PLT
       entry (PLTGOT).  */
    जर (need_plt_entry ? attr->plt_offset : attr->got_offset)
        परत attr;

    s_rel = s1->got;
    जर (need_plt_entry) {
        जर (!s1->plt) {
            s1->plt = new_section(s1, ".plt", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
            s1->plt->sh_entsize = 4;
        }
        s_rel = s1->plt;
    }

    /* create the GOT entry */
    got_offset = s1->got->data_offset;
    section_ptr_add(s1->got, PTR_SIZE);

    /* Create the GOT relocation that will insert the address of the object or
       function of interest in the GOT entry. This is a static relocation for
       memory output (dlsym will give us the address of symbols) and dynamic
       relocation otherwise (executable and DLLs). The relocation should be
       done lazily for GOT entry with *_JUMP_SLOT relocation type (the one
       associated to a PLT entry) but is currently done at load time for an
       unknown reason. */

    sym = &((ElfW(Sym) *) symtab_section->data)[sym_index];
    name = (अक्षर *) symtab_section->link->data + sym->st_name;
    //printf("sym %d %s\n", need_plt_entry, name);

    जर (s1->dynsym) {
	जर (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
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
	    put_elf_reloc(s1->dynsym, s1->got, got_offset, R_RELATIVE,
			  sym_index);
	} अन्यथा {
	    जर (0 == attr->dyn_index)
                attr->dyn_index = set_elf_sym(s1->dynsym, sym->st_मूल्य,
                                              sym->st_size, sym->st_info, 0,
                                              sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s_rel, got_offset, dyn_reloc_type,
			  attr->dyn_index);
	}
    } अन्यथा {
        put_elf_reloc(symtab_section, s1->got, got_offset, dyn_reloc_type,
                      sym_index);
    }

    जर (need_plt_entry) {
        attr->plt_offset = create_plt_entry(s1, got_offset, attr);

        /* create a symbol 'sym@plt' for the PLT jump vector */
        len = म_माप(name);
        जर (len > आकार plt_name - 5)
            len = आकार plt_name - 5;
        स_नकल(plt_name, name, len);
        म_नकल(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_offset, 0,
            ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0, s1->plt->sh_अंक, plt_name);
    } अन्यथा {
        attr->got_offset = got_offset;
    }

    परत attr;
}

/* build GOT and PLT entries */
/* Two passes because R_JMP_SLOT should become first. Some targets
   (arm, arm64) do not allow mixing R_JMP_SLOT and R_GLOB_DAT. */
ST_FUNC शून्य build_got_entries(TCCState *s1, पूर्णांक got_sym)
{
    Section *s;
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    पूर्णांक i, type, gotplt_entry, reloc_type, sym_index;
    संरचना sym_attr *attr;
    पूर्णांक pass = 0;
redo:
    साठी(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        जर (s->sh_type != SHT_RELX)
            सुरूठेवा;
        /* no need to handle got relocations */
        जर (s->link != symtab_section)
            सुरूठेवा;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_entry = gotplt_entry_type(type);
            जर (gotplt_entry == -1) {
                tcc_error_noabort ("Unknown relocation type for got: %d", type);
                सुरूठेवा;
            }
            sym_index = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];

            जर (gotplt_entry == NO_GOTPLT_ENTRY) {
                सुरूठेवा;
            }

            /* Automatically create PLT/GOT [entry] if it is an undefined
	       reference (resolved at runtime), or the symbol is absolute,
	       probably created by tcc_add_symbol, and thus on 64-bit
	       targets might be too far from application code.  */
            जर (gotplt_entry == AUTO_GOTPLT_ENTRY) {
                जर (sym->st_shndx == SHN_UNDEF) {
                    ElfW(Sym) *esym;
		    पूर्णांक dynindex;
                    जर (!PCRELATIVE_DLLPLT
                        && (s1->output_type & TCC_OUTPUT_DYN))
                        सुरूठेवा;
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
		    जर (s1->dynsym) {
			/* dynsym isn't set for -run :-/  */
			dynindex = get_sym_attr(s1, sym_index, 0)->dyn_index;
			esym = (ElfW(Sym) *)s1->dynsym->data + dynindex;
			जर (dynindex
			    && (ELFW(ST_TYPE)(esym->st_info) == STT_FUNC
				|| (ELFW(ST_TYPE)(esym->st_info) == STT_NOTYPE
				    && ELFW(ST_TYPE)(sym->st_info) == STT_FUNC)))
			    जा jmp_slot;
		    }
                } अन्यथा जर (sym->st_shndx == SHN_ABS) {
                    जर (sym->st_मूल्य == 0) /* from tcc_add_btstub() */
                        सुरूठेवा;
#ifndef TCC_TARGET_ARM
                    जर (PTR_SIZE != 8)
                        सुरूठेवा;
#endif
                    /* from tcc_add_symbol(): on 64 bit platforms these
                       need to go through .got */
                } अन्यथा
                    सुरूठेवा;
            }

#ifdef TCC_TARGET_I386
            जर ((type == R_386_PLT32 || type == R_386_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		जर (pass != 0)
		    सुरूठेवा;
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_PC32);
                सुरूठेवा;
            }
#endif
#ifdef TCC_TARGET_X86_64
            जर ((type == R_X86_64_PLT32 || type == R_X86_64_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		जर (pass != 0)
		    सुरूठेवा;
                rel->r_info = ELFW(R_INFO)(sym_index, R_X86_64_PC32);
                सुरूठेवा;
            }
#endif
            reloc_type = code_reloc(type);
            जर (reloc_type == -1) {
                tcc_error_noabort ("Unknown relocation type: %d", type);
                सुरूठेवा;
            }

            जर (reloc_type != 0) {
        jmp_slot:
	        जर (pass != 0)
                    सुरूठेवा;
                reloc_type = R_JMP_SLOT;
            } अन्यथा {
	        जर (pass != 1)
                    सुरूठेवा;
                reloc_type = R_GLOB_DAT;
            }

            जर (!s1->got)
                got_sym = build_got(s1);

            जर (gotplt_entry == BUILD_GOT_ONLY)
                सुरूठेवा;

            attr = put_got_entry(s1, reloc_type, sym_index);

            जर (reloc_type == R_JMP_SLOT)
                rel->r_info = ELFW(R_INFO)(attr->plt_sym, type);
        }
    }
    जर (++pass < 2)
        जा redo;
    /* .rel.plt refers to .got actually */
    जर (s1->plt && s1->plt->reloc)
        s1->plt->reloc->sh_info = s1->got->sh_अंक;
    जर (got_sym) /* set size */
        ((ElfW(Sym)*)symtab_section->data)[got_sym].st_size = s1->got->data_offset;
}
#endif /* def NEED_BUILD_GOT */

ST_FUNC पूर्णांक set_global_sym(TCCState *s1, स्थिरांक अक्षर *name, Section *sec, addr_t offs)
{
    पूर्णांक shn = sec ? sec->sh_अंक : offs || !name ? SHN_ABS : SHN_UNDEF;
    जर (sec && offs == -1)
        offs = sec->data_offset;
    परत set_elf_sym(symtab_section, offs, 0,
        ELFW(ST_INFO)(name ? STB_GLOBAL : STB_LOCAL, STT_NOTYPE), 0, shn, name);
}

स्थिर शून्य add_init_array_defines(TCCState *s1, स्थिरांक अक्षर *section_name)
{
    Section *s;
    addr_t end_offset;
    अक्षर buf[1024];
    s = have_section(s1, section_name);
    जर (!s || !(s->sh_flags & SHF_ALLOC)) {
        end_offset = 0;
        s = text_section;
    } अन्यथा {
        end_offset = s->data_offset;
    }
    snprintf(buf, आकार(buf), "__%s_start", section_name + 1);
    set_global_sym(s1, buf, s, 0);
    snprintf(buf, आकार(buf), "__%s_end", section_name + 1);
    set_global_sym(s1, buf, s, end_offset);
}

ST_FUNC शून्य add_array (TCCState *s1, स्थिरांक अक्षर *sec, पूर्णांक c)
{
    Section *s;
    s = find_section(s1, sec);
    s->sh_flags = shf_RELRO;
    s->sh_type = sec[1] == 'i' ? SHT_INIT_ARRAY : SHT_FINI_ARRAY;
    put_elf_reloc (s1->symtab, s, s->data_offset, R_DATA_PTR, c);
    section_ptr_add(s, PTR_SIZE);
}

#ifdef CONFIG_TCC_BCHECK
ST_FUNC शून्य tcc_add_bcheck(TCCState *s1)
{
    जर (0 == s1->do_bounds_check)
        परत;
    section_ptr_add(bounds_section, आकार(addr_t));
}
#endif

/* set symbol to STB_LOCAL and resolve. The point is to not export it as
   a dynamic symbol to allow so's to have one each with a different value. */
स्थिर शून्य set_local_sym(TCCState *s1, स्थिरांक अक्षर *name, Section *s, पूर्णांक offset)
{
    पूर्णांक c = find_elf_sym(s1->symtab, name);
    जर (c) {
        ElfW(Sym) *esym = (ElfW(Sym)*)s1->symtab->data + c;
        esym->st_info = ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE);
        esym->st_मूल्य = offset;
        esym->st_shndx = s->sh_अंक;
    }
}

/* avoid generating debug/test_coverage code for stub functions */
स्थिर शून्य tcc_compile_string_no_debug(TCCState *s, स्थिरांक अक्षर *str)
{
    पूर्णांक save_do_debug = s->do_debug;
    पूर्णांक save_test_coverage = s->test_coverage;

    s->do_debug = 0;
    s->test_coverage = 0;
    tcc_compile_string(s, str);
    s->do_debug = save_do_debug;
    s->test_coverage = save_test_coverage;
}

#ifdef CONFIG_TCC_BACKTRACE
स्थिर शून्य put_ptr(TCCState *s1, Section *s, पूर्णांक offs)
{
    पूर्णांक c;
    c = set_global_sym(s1, रिक्त, s, offs);
    s = data_section;
    put_elf_reloc (s1->symtab, s, s->data_offset, R_DATA_PTR, c);
    section_ptr_add(s, PTR_SIZE);
}

ST_FUNC शून्य tcc_add_btstub(TCCState *s1)
{
    Section *s;
    पूर्णांक n, o, *p;
    CString cstr;
    स्थिरांक अक्षर *__rt_info = &"___rt_info"[!s1->leading_underscore];

    s = data_section;
    /* Align to PTR_SIZE */
    section_add(s, 0, PTR_SIZE);
    o = s->data_offset;
    /* create a struct rt_context (see tccrun.c) */
    जर (s1->dwarf) {
        put_ptr(s1, dwarf_ओळ_section, 0);
        put_ptr(s1, dwarf_ओळ_section, -1);
	जर (s1->dwarf >= 5)
            put_ptr(s1, dwarf_ओळ_str_section, 0);
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
    section_ptr_add(s, 3 * PTR_SIZE);

    जर (s1->output_type == TCC_OUTPUT_MEMORY && 0 == s1->dwarf) {
        put_ptr(s1, text_section, 0);
    } अन्यथा {
        /* prog_base : local nameless symbol with offset 0 at SHN_ABS */
        put_ptr(s1, रिक्त, 0);
#जर defined TCC_TARGET_MACHO
        /* adjust for __PAGEZERO */
        जर (s1->dwarf == 0 && s1->output_type == TCC_OUTPUT_EXE)
            write64le(data_section->data + data_section->data_offset - PTR_SIZE,
	              (uint64_t)1 << 32);
#endif
    }
    n = 3 * PTR_SIZE;
#ifdef CONFIG_TCC_BCHECK
    जर (s1->do_bounds_check) {
        put_ptr(s1, bounds_section, 0);
        n -= PTR_SIZE;
    }
#endif
    section_ptr_add(s, n);
    p = section_ptr_add(s, 2 * आकार (पूर्णांक));
    p[0] = s1->rt_अंक_callers;
    p[1] = s1->dwarf;
    // if (s->data_offset - o != 10*PTR_SIZE + 2*sizeof (int)) exit(99);

    जर (s1->output_type == TCC_OUTPUT_MEMORY) {
        set_global_sym(s1, __rt_info, s, o);
        परत;
    }

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern void __bt_init(),__bt_exit(),__bt_init_dll();"
        "static void *__rt_info[];"
        "__attribute__((constructor)) static void __bt_init_rt(){");
#ifdef TCC_TARGET_PE
    जर (s1->output_type == TCC_OUTPUT_DLL)
#ifdef CONFIG_TCC_BCHECK
        cstr_printf(&cstr, "__bt_init_dll(%d);", s1->do_bounds_check);
#अन्यथा
        cstr_printf(&cstr, "__bt_init_dll(0);");
#endif
#endif
    cstr_printf(&cstr, "__bt_init(__rt_info,%d);}",
        s1->output_type != TCC_OUTPUT_DLL);
    /* In case dlcose is called by application */
    cstr_printf(&cstr,
        "__attribute__((destructor)) static void __bt_exit_rt(){"
        "__bt_exit(__rt_info);}");
    tcc_compile_string_no_debug(s1, cstr.data);
    cstr_free(&cstr);
    set_local_sym(s1, __rt_info, s, o);
}
#endif /* def CONFIG_TCC_BACKTRACE */

स्थिर शून्य tcc_tcov_add_file(TCCState *s1, स्थिरांक अक्षर *filename)
{
    CString cstr;
    शून्य *ptr;
    अक्षर wd[1024];

    जर (tcov_section == रिक्त)
        परत;
    section_ptr_add(tcov_section, 1);
    write32le (tcov_section->data, tcov_section->data_offset);

    cstr_new (&cstr);
    जर (filename[0] == '/')
        cstr_printf (&cstr, "%s.tcov", filename);
    अन्यथा {
        getcwd (wd, आकार(wd));
        cstr_printf (&cstr, "%s/%s.tcov", wd, filename);
    }
    ptr = section_ptr_add(tcov_section, cstr.size + 1);
    म_नकल((अक्षर *)ptr, cstr.data);
    unlink((अक्षर *)ptr);
#ifdef _WIN32
    normalize_slashes((अक्षर *)ptr);
#endif
    cstr_free (&cstr);

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern char *__tcov_data[];"
        "extern void __store_test_coverage ();"
        "__attribute__((destructor)) static void __tcov_exit() {"
        "__store_test_coverage(__tcov_data);"
        "}");
    tcc_compile_string_no_debug(s1, cstr.data);
    cstr_free(&cstr);
    set_local_sym(s1, &"___tcov_data"[!s1->leading_underscore], tcov_section, 0);
}

#ifdef TCC_TARGET_UNIX
/* add libc crt1/crti objects */
ST_FUNC शून्य tccelf_add_crtbegin(TCCState *s1)
{
#जर TARGETOS_OpenBSD
    जर (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crt0.o");
    जर (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbeginS.o");
    अन्यथा
        tcc_add_crt(s1, "crtbegin.o");
#किंवाजर TARGETOS_FreeBSD || TARGETOS_NetBSD
    जर (s1->output_type != TCC_OUTPUT_DLL)
#जर TARGETOS_FreeBSD
        tcc_add_crt(s1, "crt1.o");
#अन्यथा
        tcc_add_crt(s1, "crt0.o");
#endif
    tcc_add_crt(s1, "crti.o");
    जर (s1->static_link)
        tcc_add_crt(s1, "crtbeginT.o");
    अन्यथा जर (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbeginS.o");
    अन्यथा
        tcc_add_crt(s1, "crtbegin.o");
#किंवाजर TARGETOS_ANDROID
    जर (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbegin_so.o");
    अन्यथा
        tcc_add_crt(s1, "crtbegin_dynamic.o");
#अन्यथा
    जर (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crt1.o");
    tcc_add_crt(s1, "crti.o");
#endif
}

ST_FUNC शून्य tccelf_add_crtend(TCCState *s1)
{
#जर TARGETOS_OpenBSD
    जर (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtendS.o");
    अन्यथा
        tcc_add_crt(s1, "crtend.o");
#किंवाजर TARGETOS_FreeBSD || TARGETOS_NetBSD
    जर (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtendS.o");
    अन्यथा
        tcc_add_crt(s1, "crtend.o");
    tcc_add_crt(s1, "crtn.o");
#किंवाजर TARGETOS_ANDROID
    जर (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtend_so.o");
    अन्यथा
        tcc_add_crt(s1, "crtend_android.o");
#अन्यथा
    tcc_add_crt(s1, "crtn.o");
#endif
}
#endif /* TCC_TARGET_UNIX */

#ifndef TCC_TARGET_PE
/* add tcc runtime libraries */
ST_FUNC शून्य tcc_add_runtime(TCCState *s1)
{
    s1->filetype = 0;

#ifdef CONFIG_TCC_BCHECK
    tcc_add_bcheck(s1);
#endif
    tcc_add_pragma_libs(s1);

    /* add libc */
    जर (!s1->nostdlib) {
        पूर्णांक lpthread = s1->option_pthread;

#ifdef CONFIG_TCC_BCHECK
        जर (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    जर (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    अन्यथा
                tcc_add_support(s1, "bcheck.o");
# जर !(TARGETOS_OpenBSD || TARGETOS_NetBSD)
            tcc_add_library(s1, "dl");
# endif
            lpthread = 1;
        }
#endif
#ifdef CONFIG_TCC_BACKTRACE
        जर (s1->do_backtrace) {
            जर (s1->output_type & TCC_OUTPUT_EXE)
                tcc_add_support(s1, "bt-exe.o");
            जर (s1->output_type != TCC_OUTPUT_DLL)
                tcc_add_support(s1, "bt-log.o");
            tcc_add_btstub(s1);
            lpthread = 1;
        }
#endif
        जर (lpthread)
            tcc_add_library(s1, "pthread");
        tcc_add_library(s1, "c");
#ifdef TCC_LIBGCC
        जर (!s1->static_link) {
            जर (TCC_LIBGCC[0] == '/')
                tcc_add_file(s1, TCC_LIBGCC);
            अन्यथा
                tcc_add_dll(s1, TCC_LIBGCC, AFF_PRINT_ERROR);
        }
#endif
#जर defined TCC_TARGET_ARM && TARGETOS_FreeBSD
        tcc_add_library(s1, "gcc_s"); // unwind code
#endif
        जर (TCC_LIBTCC1[0]) {
            tcc_add_support(s1, TCC_LIBTCC1);
            tcc_add_library(s1, "c");
        }
#ifndef TCC_TARGET_MACHO
        जर (s1->output_type != TCC_OUTPUT_MEMORY)
            tccelf_add_crtend(s1);
#endif
    }
}
#endif /* ndef TCC_TARGET_PE */

/* set _etext/_edata/_end  f=0:set  f=1:when_needed  f=2,3:just_update */
स्थिर शून्य set_linker_sym(TCCState *s1, स्थिरांक अक्षर *name, Section *sec, पूर्णांक f)
{
    पूर्णांक sym_index, esym_index, defined;
    ElfW(Sym) *sym, *esym;
    sym_index = find_elf_sym(symtab_section, name);
    sym = (ElfW(Sym) *)symtab_section->data + sym_index;
    esym_index = find_elf_sym(s1->dynsymtab_section, name);
    esym = (ElfW(Sym) *)s1->dynsymtab_section->data + esym_index;
    defined = sym->st_shndx != SHN_UNDEF
        || (esym->st_shndx != SHN_UNDEF && esym->st_size);
    निवड (f) {
    स्थिती 1: /* old symbols w/o '_' */
        जर (!(sym_index || esym_index) || defined)
            थांबा;
    स्थिती 0:
        जर (defined) {
            tcc_warning("linker symbol '%s' already defined", name);
            थांबा;
        }
        sym_index = set_global_sym(s1, name, sec, -1);
        get_sym_attr(s1, sym_index, 1)->linker_sym = 1;
        थांबा;
    पूर्वनिर्धारित: /* update (bss only) */
        जर (get_sym_attr(s1, sym_index, 0)->linker_sym)
            sym->st_मूल्य = sec->data_offset;
    }
#ifndef ELF_OBJ_ONLY
    जर (name[0] == '_')
        set_linker_sym(s1, name + 1, sec, f + 1);
#endif
}

/* add various standard linker symbols (must be done after the
   sections are filled (for example after allocating common
   symbols)) */
स्थिर शून्य tcc_add_linker_symbols(TCCState *s1)
{
    अक्षर buf[1024];
    पूर्णांक i;
    Section *s;

    set_linker_sym(s1, "_etext", text_section, 0);
    set_linker_sym(s1, "_edata", data_section, 0);
    set_linker_sym(s1, "_end", bss_section, 0);
#जर TARGETOS_OpenBSD
    set_global_sym(s1, "__executable_start", रिक्त, ELF_START_ADDR);
#endif

#ifdef TCC_TARGET_RISCV64
    /* XXX should be .sdata+0x800, not .data+0x800 */
    set_global_sym(s1, "__global_pointer$", data_section, 0x800);
#endif
    /* horrible new standard ldscript defines */
    add_init_array_defines(s1, ".preinit_array");
    add_init_array_defines(s1, ".init_array");
    add_init_array_defines(s1, ".fini_array");
    /* add start and stop symbols for sections whose name can be
       expressed in C */
    साठी(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        जर ((s->sh_flags & SHF_ALLOC)
            && (s->sh_type == SHT_PROGBITS || s->sh_type == SHT_NOBITS
                || s->sh_type == SHT_STRTAB)) {
            /* check if section name can be expressed in C */
            स्थिरांक अक्षर *p0, *p;
            p0 = s->name;
            जर (*p0 == '.')
                ++p0;
            p = p0;
            साठी(;;) {
                पूर्णांक c = *p;
                जर (!c)
                    थांबा;
                जर (!isid(c) && !isnum(c))
                    जा next_sec;
                p++;
            }
            snprintf(buf, आकार(buf), "__start_%s", p0);
            set_global_sym(s1, buf, s, 0);
            snprintf(buf, आकार(buf), "__stop_%s", p0);
            set_global_sym(s1, buf, s, -1);
        }
    next_sec: ;
    }
}

ST_FUNC शून्य resolve_common_syms(TCCState *s1)
{
    ElfW(Sym) *sym;

    /* Allocate common symbols in BSS.  */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        जर (sym->st_shndx == SHN_COMMON && sym->st_size) {
            /* symbol alignment is in st_value for SHN_COMMONs */
	    sym->st_मूल्य = section_add(bss_section, sym->st_size,
					sym->st_मूल्य);
            sym->st_shndx = bss_section->sh_अंक;
        }
    }

    /* Now assign linker provided symbols their value.  */
    जर (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_linker_symbols(s1);
}

#ifndef ELF_OBJ_ONLY
ST_FUNC शून्य fill_got_entry(TCCState *s1, ElfW_Rel *rel)
{
    पूर्णांक sym_index = ELFW(R_SYM) (rel->r_info);
    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->data)[sym_index];
    संरचना sym_attr *attr = get_sym_attr(s1, sym_index, 0);
    अचिन्हित offset = attr->got_offset;

    जर (0 == offset)
        परत;
    section_reserve(s1->got, offset + PTR_SIZE);
#जर PTR_SIZE == 8
    write64le(s1->got->data + offset, sym->st_मूल्य);
#अन्यथा
    write32le(s1->got->data + offset, sym->st_मूल्य);
#endif
}

/* Perform relocation to GOT or PLT entries */
ST_FUNC शून्य fill_got(TCCState *s1)
{
    Section *s;
    ElfW_Rel *rel;
    पूर्णांक i;

    साठी(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        जर (s->sh_type != SHT_RELX)
            सुरूठेवा;
        /* no need to handle got relocations */
        जर (s->link != symtab_section)
            सुरूठेवा;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            निवड (ELFW(R_TYPE) (rel->r_info)) {
                स्थिती R_X86_64_GOT32:
                स्थिती R_X86_64_GOTPCREL:
		स्थिती R_X86_64_GOTPCRELX:
		स्थिती R_X86_64_REX_GOTPCRELX:
                स्थिती R_X86_64_PLT32:
                    fill_got_entry(s1, rel);
                    थांबा;
            }
        }
    }
}

/* See put_got_entry for a description.  This is the second stage
   where GOT references to local defined symbols are rewritten.  */
स्थिर शून्य fill_local_got_entries(TCCState *s1)
{
    ElfW_Rel *rel;
    जर (!s1->got->reloc)
        परत;
    for_each_elem(s1->got->reloc, 0, rel, ElfW_Rel) {
	जर (ELFW(R_TYPE)(rel->r_info) == R_RELATIVE) {
	    पूर्णांक sym_index = ELFW(R_SYM) (rel->r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->data)[sym_index];
	    संरचना sym_attr *attr = get_sym_attr(s1, sym_index, 0);
	    अचिन्हित offset = attr->got_offset;
	    जर (offset != rel->r_offset - s1->got->sh_addr)
	        tcc_error_noabort("fill_local_got_entries: huh?");
	    rel->r_info = ELFW(R_INFO)(0, R_RELATIVE);
#जर SHT_RELX == SHT_RELA
	    rel->r_addend = sym->st_मूल्य;
#अन्यथा
	    /* All our REL architectures also happen to be 32bit LE.  */
	    write32le(s1->got->data + offset, sym->st_मूल्य);
#endif
	}
    }
}

/* Bind symbols of executable: resolve undefined symbols from exported symbols
   in shared libraries */
स्थिर शून्य bind_exe_dynsyms(TCCState *s1, पूर्णांक is_PIE)
{
    स्थिरांक अक्षर *name;
    पूर्णांक sym_index, index;
    ElfW(Sym) *sym, *esym;
    पूर्णांक type;

    /* Resolve undefined symbols from dynamic symbols. When there is a match:
       - if STT_FUNC or STT_GNU_IFUNC symbol -> add it in PLT
       - if STT_OBJECT symbol -> add it in .bss section with suitable reloc */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        जर (sym->st_shndx == SHN_UNDEF
            /* bss symbols may be initialized in the shared library */
            || sym->st_shndx == SHN_COMMON
            || sym->st_shndx == bss_section->sh_अंक) {
            name = (अक्षर *) symtab_section->link->data + sym->st_name;
            sym_index = find_elf_sym(s1->dynsymtab_section, name);
            esym = &((ElfW(Sym) *)s1->dynsymtab_section->data)[sym_index];
            जर (sym_index && esym->st_shndx != SHN_UNDEF) {
                जर (is_PIE)
                    सुरूठेवा;
                type = ELFW(ST_TYPE)(esym->st_info);
                जर ((type == STT_FUNC) || (type == STT_GNU_IFUNC)) {
                    /* Indirect functions shall have STT_FUNC type in executable
                     * dynsym section. Indeed, a dlsym call following a lazy
                     * resolution would pick the symbol value from the
                     * executable dynsym entry which would contain the address
                     * of the function wanted by the caller of dlsym instead of
                     * the address of the function that would return that
                     * address */
                    पूर्णांक dynindex
		      = put_elf_sym(s1->dynsym, 0, esym->st_size,
				    ELFW(ST_INFO)(STB_GLOBAL,STT_FUNC), 0, 0,
				    name);
		    पूर्णांक index = sym - (ElfW(Sym) *) symtab_section->data;
		    get_sym_attr(s1, index, 1)->dyn_index = dynindex;
                } अन्यथा जर (type == STT_OBJECT) {
                    अचिन्हित दीर्घ offset;
                    ElfW(Sym) *dynsym;
                    जर (sym->st_shndx == bss_section->sh_अंक) {
                        offset = sym->st_मूल्य;
                    } अन्यथा {
                        offset = bss_section->data_offset;
                        /* XXX: which alignment ? */
                        offset = (offset + 16 - 1) & -16;
                        bss_section->data_offset = offset + esym->st_size;
                    }
                    set_elf_sym (s1->symtab, offset, esym->st_size,
                                 esym->st_info, 0, bss_section->sh_अंक, name);
                    index = put_elf_sym(s1->dynsym, offset, esym->st_size,
                                        esym->st_info, 0, bss_section->sh_अंक,
                                        name);
                    /* Ensure R_COPY works for weak symbol aliases */
                    जर (ELFW(ST_BIND)(esym->st_info) == STB_WEAK) {
                        for_each_elem(s1->dynsymtab_section, 1, dynsym, ElfW(Sym)) {
                            जर ((dynsym->st_मूल्य == esym->st_मूल्य)
                                && (ELFW(ST_BIND)(dynsym->st_info) == STB_GLOBAL)) {
                                अक्षर *dynname = (अक्षर *) s1->dynsymtab_section->link->data
                                                + dynsym->st_name;
                                put_elf_sym(s1->dynsym, offset, dynsym->st_size,
                                            dynsym->st_info, 0,
                                            bss_section->sh_अंक, dynname);
                                थांबा;
                            }
                        }
                    }
                    put_elf_reloc(s1->dynsym, bss_section,
                                  offset, R_COPY, index);
                }
            } अन्यथा जर (sym->st_shndx == SHN_UNDEF) {
                /* STB_WEAK undefined symbols are accepted */
                /* XXX: _fp_hw seems to be part of the ABI, so we ignore it */
                जर (ELFW(ST_BIND)(sym->st_info) == STB_WEAK ||
                    !म_भेद(name, "_fp_hw")) {
                } अन्यथा {
                    tcc_error_noabort("unresolved reference to '%s'", name);
                }
            }
        }
    }
    /* update _end symbol with new bss length */
    set_linker_sym(s1, "_end", bss_section, 2);
}

/* Bind symbols of libraries: export all non local symbols of executable that
   are referenced by shared libraries. The reason is that the dynamic loader
   search symbol first in executable and then in libraries. Therefore a
   reference to a symbol already defined by a library can still be resolved by
   a symbol in the executable.   With -rdynamic, export all defined symbols */
स्थिर शून्य bind_libs_dynsyms(TCCState *s1)
{
    स्थिरांक अक्षर *name;
    पूर्णांक dynsym_index;
    ElfW(Sym) *sym, *esym;

    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        name = (अक्षर *)symtab_section->link->data + sym->st_name;
        dynsym_index = find_elf_sym(s1->dynsymtab_section, name);
        जर (sym->st_shndx != SHN_UNDEF) {
            जर (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL
                && (dynsym_index || s1->rdynamic))
                set_elf_sym(s1->dynsym, sym->st_मूल्य, sym->st_size,
                            sym->st_info, 0, sym->st_shndx, name);
        } अन्यथा जर (dynsym_index) {
            esym = (ElfW(Sym) *)s1->dynsymtab_section->data + dynsym_index;
            जर (esym->st_shndx == SHN_UNDEF) {
                /* weak symbols can stay undefined */
                जर (ELFW(ST_BIND)(esym->st_info) != STB_WEAK)
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
    पूर्णांक dynindex, index;
    स्थिरांक अक्षर *name;
    ElfW(Sym) *sym;
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        जर (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
	    name = (अक्षर *) symtab_section->link->data + sym->st_name;
	    dynindex = set_elf_sym(s1->dynsym, sym->st_मूल्य, sym->st_size,
				   sym->st_info, 0, sym->st_shndx, name);
	    index = sym - (ElfW(Sym) *) symtab_section->data;
            get_sym_attr(s1, index, 1)->dyn_index = dynindex;
        }
    }
}

/* decide if an unallocated section should be output. */
स्थिर पूर्णांक set_sec_sizes(TCCState *s1)
{
    पूर्णांक i;
    Section *s;
    पूर्णांक textrel = 0;
    पूर्णांक file_type = s1->output_type;

    /* Allocate strings for section names */
    साठी(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        जर (s->sh_type == SHT_RELX && !(s->sh_flags & SHF_ALLOC)) {
            /* when generating a DLL, we include relocations but
               we may patch them */
            जर ((file_type & TCC_OUTPUT_DYN)
                && (s1->sections[s->sh_info]->sh_flags & SHF_ALLOC)) {
                पूर्णांक मोजणी_2 = prepare_dynamic_rel(s1, s);
                जर (मोजणी_2) {
                    /* allocate the section */
                    s->sh_flags |= SHF_ALLOC;
                    s->sh_size = मोजणी_2 * आकार(ElfW_Rel);
                    जर (s1->sections[s->sh_info]->sh_flags & SHF_EXECINSTR)
                        textrel += मोजणी_2;
                }
            }
        } अन्यथा जर ((s->sh_flags & SHF_ALLOC)
#ifdef TCC_TARGET_ARM
                   || s->sh_type == SHT_ARM_ATTRIBUTES
#endif
                   || s1->do_debug) {
            s->sh_size = s->data_offset;
        }
    }
    परत textrel;
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
        अचिन्हित दीर्घ data_offset;
        addr_t rel_addr;
        addr_t rel_size;
    };

    ElfW(Phdr) *phdr;
    पूर्णांक phnum;
    पूर्णांक shnum;
    पूर्णांक tls;
    पूर्णांक relro;
    पूर्णांक notes;
    पूर्णांक ehfr;
    पूर्णांक dyna;
};

/* Decide the layout of sections loaded in memory. This must be done before
   program headers are filled since they contain info about the layout.
   We do the following ordering: interp, symbol tables, relocations, progbits,
   nobits */
स्थिर पूर्णांक sort_sections(TCCState *s1, पूर्णांक *sec_order, संरचना dyn_inf *d)
{
    Section *s;
    पूर्णांक i, j, k, f, f0, n;
    पूर्णांक nb_sections = s1->nb_sections;
    पूर्णांक *sec_cls = sec_order + nb_sections;
    पूर्णांक tls_align = 0; /* need common alignment for all tls sections */

    साठी (i = 1; i < nb_sections; i++) {
        s = s1->sections[i];
        जर (0 == s->sh_name) {
            j = 0x900; /* no sh_name: won't go to file */
        } अन्यथा जर (s->sh_flags & SHF_ALLOC) {
            j = 0x100;
            जर ((s->sh_flags & (SHF_WRITE|SHF_TLS)) == SHF_WRITE)
                j = 0x200;
        } अन्यथा {
            j = 0x700;
        }
        जर (j >= 0x700 && s1->output_format != TCC_OUTPUT_FORMAT_ELF)
            s->sh_size = 0, j = 0x900;

        जर (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM) {
            k = 0x10;
        } अन्यथा जर (s->sh_type == SHT_STRTAB && म_भेद(s->name, ".stabstr")) {
            k = 0x11;
            जर (i == nb_sections - 1) /* ".shstrtab" assumed to stay last */
                k = 0xff;
        } अन्यथा जर (s->sh_type == SHT_HASH || s->sh_type == SHT_GNU_HASH) {
            k = 0x12;
        } अन्यथा जर (s->sh_type == SHT_GNU_verdef
                  || s->sh_type == SHT_GNU_verneed
                  || s->sh_type == SHT_GNU_versym) {
            k = 0x13;
        } अन्यथा जर (s->sh_type == SHT_RELX) {
            k = 0x20;
            जर (s1->plt && s == s1->plt->reloc)
                k = 0x21;
        } अन्यथा जर (s->sh_flags & SHF_EXECINSTR) {
            k = 0x60;
        /* RELRO sections --> */
        } अन्यथा जर (s->sh_flags & SHF_TLS) {
            जर (s->sh_addralign > tls_align)
                tls_align = s->sh_addralign;
            k = 0x40 + (s->sh_type == SHT_NOBITS);
        } अन्यथा जर (s->sh_type == SHT_PREINIT_ARRAY) {
            k = 0x42;
        } अन्यथा जर (s->sh_type == SHT_INIT_ARRAY) {
            k = 0x43;
        } अन्यथा जर (s->sh_type == SHT_FINI_ARRAY) {
            k = 0x44;
        } अन्यथा जर (s->sh_type == SHT_DYNAMIC) {
            k = 0x48;
        } अन्यथा जर (s == s1->got) {
            k = 0x49; /* .got as RELRO needs BIND_NOW in DT_FLAGS */
        } अन्यथा जर (s->reloc && (s->reloc->sh_flags & SHF_ALLOC) && j == 0x100) {
            k = 0x45; /* +1 for data.ro */
        /* <-- */
        } अन्यथा जर (s->sh_type == SHT_NOTE) {
            k = 0x08, d->notes = 1;
        } अन्यथा जर (s->sh_type == SHT_NOBITS) {
            k = 0x70; /* bss */
        } अन्यथा जर (s == d->interp) {
            k = 0x00;
        } अन्यथा {
            k = 0x50; /* data */
        }
        k += j;
        /* make our standard sections come last to have _etext/_edata correct values */
        जर (s->sh_अंक <= bss_section->sh_अंक)
            ++k;
        /* make RELRO section writable */
        जर ((k & 0xfff0) == 0x140)
            k += 0x100, s->sh_flags |= SHF_WRITE;
        /* sort by insert */
        साठी (n = i; n > 1 && k < (f = sec_cls[n - 1]); --n)
            sec_cls[n] = f, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
    }
    sec_order[0] = 0;
    d->shnum = 1;

#define SHFX_NEWPH (1 << 4)
#define SHFX_RELRO (1 << 5)

    /* count PT_LOAD headers needed */
    n = f0 = 0;
    साठी (i = 1; i < nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        k = sec_cls[i];
        f = 0;
        जर (k < 0x900)
            ++d->shnum;
        जर (k < 0x700) {
            f = s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR);
#जर TARGETOS_NetBSD || TARGETOS_FreeBSD
	    /* NetBSD only supports 2 PT_LOAD sections.
	       See: https://blog.netbsd.org/tnf/entry/the_first_report_on_lld */
	    जर ((f & SHF_WRITE) == 0)
                f |= SHF_EXECINSTR;
            k = 0; /* no relro */
#endif
            जर ((k & 0xfff0) == 0x240) /* RELRO sections */
                d->relro = 1, f |= SHFX_RELRO;
            /* start new header when flags changed, but avoid zero memsz */
            जर (f != f0 && s->sh_size)
                f0 = f, ++n, f |= SHFX_NEWPH;
            जर ((s->sh_flags & SHF_TLS) && s->sh_size) {
                s->sh_addralign = tls_align;
                d->tls = 1, f |= SHF_TLS;
            }
        }
        sec_cls[i] = f;
        //printf("ph %d sec %02d : %3X %3X  %8.2X  %04X  %s\n", (f>0) * n, i, f, k, s->sh_type, (int)s->sh_size, s->name);
    }
    परत n;
}

स्थिर ElfW(Phdr) *fill_phdr(ElfW(Phdr) *ph, पूर्णांक type, Section *s)
{
    ph->p_type = type;
    ph->p_flags = PF_R;
    जर (s) {
        जर (s->sh_flags & SHF_WRITE)
            ph->p_flags |= PF_W;
        ph->p_offset = s->sh_offset;
        ph->p_vaddr = s->sh_addr;
        ph->p_filesz = s->sh_size;
        ph->p_align = s->sh_addralign;
    }
    ph->p_paddr = ph->p_vaddr;
    ph->p_memsz = ph->p_filesz;
    परत ph;
}

स्थिर ElfW(Phdr) *update_phdr(ElfW(Phdr) *ph, पूर्णांक type, Section *s, addr_t addr, पूर्णांक file_offset)
{
    जर (ph->p_type == 0) {
        fill_phdr(ph, type, s);
    }
    ph->p_filesz = file_offset - ph->p_offset;
    ph->p_memsz = addr - ph->p_vaddr;
    परत ph;
}

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
स्थिर पूर्णांक layout_sections(TCCState *s1, पूर्णांक *sec_order, संरचना dyn_inf *d)
{
    Section *s;
    addr_t addr, tmp, align, s_align, base;
    ElfW(Phdr) *ph = रिक्त, *ph2;
    पूर्णांक i, f, n, phnum, phfill;
    पूर्णांक file_offset;

    /* compute number of program headers */
    phnum = sort_sections(s1, sec_order, d);
    phfill = 0; /* set to 1 to have dll's with a PT_PHDR */
    जर (d->interp)
        phfill = 2;
    phnum += phfill;
    जर (d->dynamic)
        d->dyna = phnum++;
    जर (d->notes)
        d->notes = phnum++;
    जर (d->tls)
        d->tls = phnum++;
    जर (eh_frame_hdr_section)
        d->ehfr = phnum++;
    जर (d->relro)
        d->relro = phnum++;
    d->phnum = phnum;
    d->phdr = tcc_mallocz(phnum * आकार(ElfW(Phdr)));

    file_offset = 0;
    जर (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
        file_offset = (आकार(ElfW(Ehdr)) + phnum * आकार(ElfW(Phdr)) + 3) & -4;
        file_offset += d->shnum * आकार (ElfW(Shdr));
    }

    s_align = ELF_PAGE_SIZE;
    जर (s1->section_align)
        s_align = s1->section_align;

    addr = ELF_START_ADDR;
    जर (s1->output_type & TCC_OUTPUT_DYN)
        addr = 0;

    जर (s1->has_text_addr) {
        addr = s1->text_addr;
        जर (0) {
            पूर्णांक a_offset, p_offset;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_offset = (पूर्णांक) (addr & (s_align - 1));
            p_offset = file_offset & (s_align - 1);
            जर (a_offset < p_offset)
                a_offset += s_align;
            file_offset += (a_offset - p_offset);
        }
    }
    base = addr;
    /* compute address after headers */
    addr += file_offset;

    n = 0;
    साठी(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        f = sec_order[i + s1->nb_sections];
        align = s->sh_addralign - 1;

        जर (f == 0) { /* no alloc */
            file_offset = (file_offset + align) & ~align;
            s->sh_offset = file_offset;
            जर (s->sh_type != SHT_NOBITS)
                file_offset += s->sh_size;
            सुरूठेवा;
        }

        जर ((f & SHFX_NEWPH) && n) {
            /* different rwx section flags */
            जर (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
                /* if in the middle of a page, w e duplicate the page in
                   memory so that one copy is RX and the other is RW */
                जर ((addr & (s_align - 1)) != 0)
                    addr += s_align;
            } अन्यथा {
                align = s_align - 1;
            }
        }

        tmp = addr;
        addr = (addr + align) & ~align;
        file_offset += (पूर्णांक)(addr - tmp);
        s->sh_offset = file_offset;
        s->sh_addr = addr;

        //printf("%d : %08x %08x %04x %03x %s %d\n", n, (int)file_offset, (int)addr, (int)s->sh_size, s->sh_type, s->name, align + 1);
        addr += s->sh_size;
        जर (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_size;

        जर (f & SHFX_NEWPH) {
            /* set new program header */
            ph = &d->phdr[phfill + n];
            fill_phdr(ph, PT_LOAD, s);
            ph->p_align = s_align;
            जर (f & SHF_EXECINSTR)
                ph->p_flags |= PF_X;
            जर (n == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_offset = 0;
                ph->p_paddr = ph->p_vaddr = base;
            }
            ++n;
        }

        जर (ph)
            update_phdr(ph, 0, 0, addr, file_offset);

        जर (f & SHFX_RELRO) {
            ph2 = update_phdr(&d->phdr[d->relro], PT_GNU_RELRO, s, addr, file_offset);
            ph2->p_align = 1;
        }
        जर (f & SHF_TLS) {
            ph2 = update_phdr(&d->phdr[d->tls], PT_TLS, s, addr, file_offset);
            जर (s->sh_type == SHT_NOBITS)
                addr -= s->sh_size;
            /* for xxx-link.c:relocate() */
            s1->tls_start = ph2->p_vaddr;
            s1->tls_end = s1->tls_start + ph2->p_memsz + (-ph2->p_memsz & (ph2->p_align - 1));
        }
        जर (s->sh_type == SHT_NOTE) {
            update_phdr(&d->phdr[d->notes], PT_NOTE, s, addr, file_offset);
        }
    }

    /* Fill other headers */
    जर (d->dyna)
        fill_phdr(&d->phdr[d->dyna], PT_DYNAMIC, d->dynamic);
    जर (d->ehfr)
        fill_phdr(&d->phdr[d->ehfr], PT_GNU_EH_FRAME, eh_frame_hdr_section);
    जर (d->interp)
        fill_phdr(&d->phdr[1], PT_INTERP, d->interp);
    जर (phfill) {
        ph = &d->phdr[0];
        ph->p_offset = आकार(ElfW(Ehdr));
        ph->p_vaddr = base + ph->p_offset;
        ph->p_filesz = phnum * आकार(ElfW(Phdr));
        ph->p_align = 4;
        fill_phdr(ph, PT_PHDR, रिक्त);
    }
    परत 0;
}

/* put dynamic tag */
स्थिर शून्य put_dt(Section *dynamic, पूर्णांक dt, addr_t val)
{
    ElfW(Dyn) *dyn;
    dyn = section_ptr_add(dynamic, आकार(ElfW(Dyn)));
    dyn->d_tag = dt;
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
    put_dt(dynamic, DT_STRSZ, dyninf->dynstr->data_offset);
    put_dt(dynamic, DT_SYMENT, आकार(ElfW(Sym)));
#जर PTR_SIZE == 8
    put_dt(dynamic, DT_RELA, dyninf->rel_addr);
    put_dt(dynamic, DT_RELASZ, dyninf->rel_size);
    put_dt(dynamic, DT_RELAENT, आकार(ElfW_Rel));
    जर (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->data_offset);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_RELA);
    }
    put_dt(dynamic, DT_RELACOUNT, 0);
#अन्यथा
    put_dt(dynamic, DT_REL, dyninf->rel_addr);
    put_dt(dynamic, DT_RELSZ, dyninf->rel_size);
    put_dt(dynamic, DT_RELENT, आकार(ElfW_Rel));
    जर (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->data_offset);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_REL);
    }
    put_dt(dynamic, DT_RELCOUNT, 0);
#endif
    जर (versym_section && verneed_section) {
	/* The dynamic linker can not handle VERSYM without VERNEED */
        put_dt(dynamic, DT_VERSYM, versym_section->sh_addr);
        put_dt(dynamic, DT_VERNEED, verneed_section->sh_addr);
        put_dt(dynamic, DT_VERNEEDNUM, dt_verneednum);
    }
    s = have_section(s1, ".preinit_array");
    जर (s && s->data_offset) {
        put_dt(dynamic, DT_PREINIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_PREINIT_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".init_array");
    जर (s && s->data_offset) {
        put_dt(dynamic, DT_INIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_INIT_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".fini_array");
    जर (s && s->data_offset) {
        put_dt(dynamic, DT_FINI_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_FINI_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".init");
    जर (s && s->data_offset) {
        put_dt(dynamic, DT_INIT, s->sh_addr);
    }
    s = have_section(s1, ".fini");
    जर (s && s->data_offset) {
        put_dt(dynamic, DT_FINI, s->sh_addr);
    }
    जर (s1->do_debug)
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
    पूर्णांक i;
    अचिन्हित दीर्घ file_offset = 0;
    Section *s;
    Section *relocplt = s1->plt ? s1->plt->reloc : रिक्त;

    /* dynamic relocation table information, for .dynamic section */
    dyninf->rel_addr = dyninf->rel_size = 0;

    साठी(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
	जर (s->sh_type == SHT_RELX && s != relocplt) {
	    जर (dyninf->rel_size == 0) {
		dyninf->rel_addr = s->sh_addr;
		file_offset = s->sh_offset;
	    }
	    अन्यथा {
		s->sh_addr = dyninf->rel_addr + dyninf->rel_size;
		s->sh_offset = file_offset + dyninf->rel_size;
	    }
	    dyninf->rel_size += s->sh_size;
	}
    }
}
#endif /* ndef ELF_OBJ_ONLY */

/* Create an ELF file on disk.
   This function handle ELF specific layout requirements */
स्थिर पूर्णांक tcc_output_elf(TCCState *s1, खाता *f, पूर्णांक phnum, ElfW(Phdr) *phdr)
{
    पूर्णांक i, shnum, offset, size, file_type;
    Section *s;
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) shdr, *sh;

    file_type = s1->output_type;
    shnum = s1->nb_sections;

    स_रखो(&ehdr, 0, आकार(ehdr));
    जर (phnum > 0) {
        ehdr.e_phentsize = आकार(ElfW(Phdr));
        ehdr.e_phnum = phnum;
        ehdr.e_phoff = आकार(ElfW(Ehdr));
    }

    /* fill header */
    ehdr.e_ident[0] = ELFMAG0;
    ehdr.e_ident[1] = ELFMAG1;
    ehdr.e_ident[2] = ELFMAG2;
    ehdr.e_ident[3] = ELFMAG3;
    ehdr.e_ident[4] = ELFCLASSW;
    ehdr.e_ident[5] = ELFDATA2LSB;
    ehdr.e_ident[6] = EV_CURRENT;

#जर TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    ehdr.e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
#किंवाजर TARGETOS_OpenBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_OPENBSD;
#किंवाजर TARGETOS_NetBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_NETBSD;
#किंवाजर defined TCC_TARGET_ARM && defined TCC_ARM_EABI
    ehdr.e_flags = EF_ARM_EABI_VER5;
    ehdr.e_flags |= s1->float_abi == ARM_HARD_FLOAT
        ? EF_ARM_VFP_FLOAT : EF_ARM_SOFT_FLOAT;
#किंवाजर defined TCC_TARGET_ARM
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#किंवाजर defined TCC_TARGET_RISCV64
    /* XXX should be configurable */
    ehdr.e_flags = EF_RISCV_FLOAT_ABI_DOUBLE;
#endif

    जर (file_type == TCC_OUTPUT_OBJ) {
        ehdr.e_type = ET_REL;
    } अन्यथा {
        जर (file_type & TCC_OUTPUT_DYN)
            ehdr.e_type = ET_DYN;
        अन्यथा
            ehdr.e_type = ET_EXEC;
        जर (s1->elf_entryname)
            ehdr.e_entry = get_sym_addr(s1, s1->elf_entryname, 1, 0);
        अन्यथा
            ehdr.e_entry = get_sym_addr(s1, "_start", !!(file_type & TCC_OUTPUT_EXE), 0);
        जर (ehdr.e_entry == (addr_t)-1)
            ehdr.e_entry = text_section->sh_addr;
        जर (s1->nb_errors)
            परत -1;
    }

    sort_syms(s1, s1->symtab);

    ehdr.e_machine = EM_TCC_TARGET;
    ehdr.e_version = EV_CURRENT;
    ehdr.e_shoff = (आकार(ElfW(Ehdr)) + phnum * आकार(ElfW(Phdr)) + 3) & -4;
    ehdr.e_ehsize = आकार(ElfW(Ehdr));
    ehdr.e_shentsize = आकार(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    offset = ख_डालो(&ehdr, 1, आकार(ElfW(Ehdr)), f);
    जर (phdr)
        offset += ख_डालो(phdr, 1, phnum * आकार(ElfW(Phdr)), f);

    /* output section headers */
    पर्यंत (offset < ehdr.e_shoff) {
        ख_अक्षर_दो(0, f);
        offset++;
    }

    साठी(i = 0; i < shnum; i++) {
        sh = &shdr;
        स_रखो(sh, 0, आकार(ElfW(Shdr)));
        जर (i) {
            s = s1->sections[i];
            sh->sh_name = s->sh_name;
            sh->sh_type = s->sh_type;
            sh->sh_flags = s->sh_flags;
            sh->sh_entsize = s->sh_entsize;
            sh->sh_info = s->sh_info;
            जर (s->link)
                sh->sh_link = s->link->sh_अंक;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_offset = s->sh_offset;
            sh->sh_size = s->sh_size;
        }
        offset += ख_डालो(sh, 1, आकार(ElfW(Shdr)), f);
    }

    /* output sections */
    साठी(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        जर (s->sh_type != SHT_NOBITS) {
            पर्यंत (offset < s->sh_offset) {
                ख_अक्षर_दो(0, f);
                offset++;
            }
            size = s->sh_size;
            जर (size)
                offset += ख_डालो(s->data, 1, size, f);
        }
    }
    परत 0;
}

स्थिर पूर्णांक tcc_output_द्विमान(TCCState *s1, खाता *f)
{
    Section *s;
    पूर्णांक i, offset, size;

    offset = 0;
    साठी(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[i];
        जर (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            पर्यंत (offset < s->sh_offset) {
                ख_अक्षर_दो(0, f);
                offset++;
            }
            size = s->sh_size;
            ख_डालो(s->data, 1, size, f);
            offset += size;
        }
    }
    परत 0;
}

/* Write an elf, coff or "binary" file */
स्थिर पूर्णांक tcc_write_elf_file(TCCState *s1, स्थिरांक अक्षर *filename, पूर्णांक phnum,
                              ElfW(Phdr) *phdr)
{
    पूर्णांक fd, mode, file_type, ret;
    खाता *f;

    file_type = s1->output_type;
    जर (file_type == TCC_OUTPUT_OBJ)
        mode = 0666;
    अन्यथा
        mode = 0777;
    unlink(filename);
    fd = खोलो(filename, O_WRONLY | O_CREAT | O_TRUNC | O_द्विमान_2, mode);
    जर (fd < 0 || (f = fdopen(fd, "wb")) == रिक्त)
        परत tcc_error_noabort("could not write '%s: %s'", filename, म_त्रुटि(त्रुटि_सं));
    जर (s1->verbose)
        म_लिखो("<- %s\n", filename);
#ifdef TCC_TARGET_COFF
    जर (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    अन्यथा
#endif
    जर (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        ret = tcc_output_elf(s1, f, phnum, phdr);
    अन्यथा
        ret = tcc_output_द्विमान(s1, f);
    ख_बंद(f);

    परत ret;
}

#ifndef ELF_OBJ_ONLY
/* order sections according to sec_order, remove sections
   that we aren't going to output.  */
स्थिर शून्य reorder_sections(TCCState *s1, पूर्णांक *sec_order)
{
    पूर्णांक i, nnew, k, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    backmap = tcc_malloc(s1->nb_sections * आकार(backmap[0]));
    साठी (i = 0, nnew = 0, snew = रिक्त; i < s1->nb_sections; i++) {
	k = sec_order ? sec_order[i] : i;
	s = s1->sections[k];
	जर (!i || s->sh_name) {
	    backmap[k] = nnew;
            dynarray_add(&snew, &nnew, s);
	} अन्यथा {
	    backmap[k] = 0;
            /* just remember to free them later */
	    dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, s);
	}
    }
    साठी (i = 1; i < nnew; i++) {
	s = snew[i];
        s->sh_अंक = i;
        जर (s->sh_type == SHT_RELX)
            s->sh_info = backmap[s->sh_info];
        अन्यथा जर (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM)
            for_each_elem(s, 1, sym, ElfW(Sym))
                जर (sym->st_shndx < s1->nb_sections)
                    sym->st_shndx = backmap[sym->st_shndx];
    }
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}

#ifdef TCC_TARGET_ARM
स्थिर शून्य create_arm_attribute_section(TCCState *s1)
{
   // Needed for DLL support.
    स्थिर स्थिरांक अचिन्हित अक्षर arm_attr[] = {
        0x41,                            // 'A'
        0x2c, 0x00, 0x00, 0x00,          // size 0x2c
        'a', 'e', 'a', 'b', 'i', 0x00,   // "aeabi"
        0x01, 0x22, 0x00, 0x00, 0x00,    // 'File Attributes', size 0x22
        0x05, 0x36, 0x00,                // 'CPU_name', "6"
#जर CONFIG_TCC_CPUVER >= 7
        0x06, 0x0a,                      // 'CPU_arch', 'v7'
#अन्यथा
        0x06, 0x06,                      // 'CPU_arch', 'v6'
#endif
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
    Section *attr = new_section(s1, ".ARM.attributes", SHT_ARM_ATTRIBUTES, 0);
    अचिन्हित अक्षर *ptr = section_ptr_add(attr, आकार(arm_attr));
    attr->sh_addralign = 1;
    स_नकल(ptr, arm_attr, आकार(arm_attr));
    जर (s1->float_abi != ARM_HARD_FLOAT) {
        ptr[26] = 0x00; // 'FP_arch', 'No'
        ptr[41] = 0x1e; // 'ABI_optimization_goals'
        ptr[42] = 0x06; // 'Aggressive Debug'
    }
}
#endif

#ifdef TCC_TARGET_RISCV64
स्थिर शून्य create_riscv_attribute_section(TCCState *s1)
{
    स्थिर स्थिरांक अचिन्हित अक्षर riscv_attr[] = {
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
    Section *attr = new_section(s1, ".riscv.attributes", SHT_RISCV_ATTRIBUTES, 0);
    अचिन्हित अक्षर *ptr = section_ptr_add(attr, आकार(riscv_attr));
    attr->sh_addralign = 1;
    स_नकल(ptr, riscv_attr, आकार(riscv_attr));
}
#endif

#जर TARGETOS_OpenBSD || TARGETOS_NetBSD || TARGETOS_FreeBSD

स्थिर शून्य fill_bsd_note(Section *s, पूर्णांक type,
			  स्थिरांक अक्षर *मूल्य, uint32_t data)
{
    अचिन्हित दीर्घ offset = 0;
    अक्षर *ptr;
    ElfW(Nhdr) *note;
    पूर्णांक align = s->sh_addralign;

    /* check if type present */
    पर्यंत (offset + आकार(ElfW(Nhdr)) < s->data_offset) {
        note = (ElfW(Nhdr) *) (s->data + offset);
	जर (note->n_type == type)
	    परत;
	offset += (आकार(ElfW(Nhdr)) + note->n_namesz + note->n_descsz +
		  align - 1) & -align;
    }
    ptr = section_ptr_add(s, आकार(ElfW(Nhdr)) + 8 + 4);
    note = (ElfW(Nhdr) *) ptr;
    note->n_namesz = 8;
    note->n_descsz = 4;
    note->n_type = type;
    म_नकल (ptr + आकार(ElfW(Nhdr)), मूल्य);
    स_नकल (ptr + आकार(ElfW(Nhdr)) + 8, &data, 4);
}

स्थिर Section *create_bsd_note_section(TCCState *s1,
					स्थिरांक अक्षर *name,
					स्थिरांक अक्षर *मूल्य)
{
    Section *s;
    अचिन्हित पूर्णांक major = 0, minor = 0, patch = 0;

#ifdef CONFIG_OS_RELEASE
    माला_पूछो(CONFIG_OS_RELEASE, "%u.%u.%u", &major, &minor, &patch);
#endif
#जर TARGETOS_FreeBSD
    जर (major < 14)
	परत रिक्त;
#endif
    s = find_section (s1, name);
    s->sh_type = SHT_NOTE;
#जर TARGETOS_OpenBSD
    fill_bsd_note(s, ELF_NOTE_OS_GNU, मूल्य, 0);
#किंवाजर TARGETOS_NetBSD
    fill_bsd_note(s, 1 /* NT_NETBSD_IDENT_TAG */, मूल्य,
		  major * 100000000u + (minor % 100u) * 1000000u +
		  (patch % 10000u) * 100u);
#किंवाजर TARGETOS_FreeBSD
    fill_bsd_note(s, 1 /* NT_FREEBSD_ABI_TAG */, मूल्य,
		  major * 100000u + (minor % 100u) * 1000u);
    fill_bsd_note(s, 4 /* NT_FREEBSD_FEATURE_CTL */, मूल्य, 0);
    fill_bsd_note(s, 2 /* NT_FREEBSD_NOINIT_TAG */, मूल्य, 0);
#endif
    परत s;
}
#endif

स्थिर शून्य alloc_sec_names(TCCState *s1, पूर्णांक is_obj);

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
स्थिर पूर्णांक elf_output_file(TCCState *s1, स्थिरांक अक्षर *filename)
{
    पूर्णांक i, ret, file_type, *sec_order;
    संरचना dyn_inf dyninf = {0};
    Section *interp, *dynstr, *dynamic;
    पूर्णांक textrel, got_sym, dt_flags_1;

    file_type = s1->output_type;
    ret = -1;
    interp = dynstr = dynamic = रिक्त;
    sec_order = रिक्त;

#ifdef TCC_TARGET_ARM
    create_arm_attribute_section (s1);
#endif

#ifdef TCC_TARGET_RISCV64
    create_riscv_attribute_section(s1);
#endif

#जर TARGETOS_OpenBSD
    dyninf.note = create_bsd_note_section (s1, ".note.openbsd.ident", "OpenBSD");
#endif

#जर TARGETOS_NetBSD
    dyninf.note = create_bsd_note_section (s1, ".note.netbsd.ident", "NetBSD");
#endif

#जर TARGETOS_FreeBSD
    dyninf.note = create_bsd_note_section (s1, ".note.tag", "FreeBSD");
#endif

        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_add_runtime(s1);
	resolve_common_syms(s1);

        जर (!s1->static_link) {
            जर (file_type & TCC_OUTPUT_EXE) {
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
            dynamic->sh_entsize = आकार(ElfW(Dyn));

            got_sym = build_got(s1);
            जर (file_type & TCC_OUTPUT_EXE) {
                bind_exe_dynsyms(s1, file_type & TCC_OUTPUT_DYN);
                जर (s1->nb_errors)
                    जा the_end;
            }
            build_got_entries(s1, got_sym);
            जर (file_type & TCC_OUTPUT_EXE) {
                bind_libs_dynsyms(s1);
            } अन्यथा {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
#जर TCC_EH_FRAME
	    /* fill with initial data */
	    tcc_eh_frame_hdr(s1, 0);
#endif
	    dyninf.gnu_hash = create_gnu_hash(s1);
        } अन्यथा {
            build_got_entries(s1, 0);
        }
	version_add (s1);

    textrel = set_sec_sizes(s1);

    जर (!s1->static_link) {
        /* add a list of needed dlls */
        साठी(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            जर (dllref->level == 0)
                put_dt(dynamic, DT_NEEDED, put_elf_str(dynstr, dllref->name));
        }

        जर (s1->rpath)
            put_dt(dynamic, s1->enable_new_dtags ? DT_RUNPATH : DT_RPATH,
                   put_elf_str(dynstr, s1->rpath));

        dt_flags_1 = DF_1_NOW;
        जर (file_type & TCC_OUTPUT_DYN) {
            जर (s1->soname)
                put_dt(dynamic, DT_SONAME, put_elf_str(dynstr, s1->soname));
            /* XXX: currently, since we do not handle PIC code, we
               must relocate the readonly segments */
            जर (textrel)
                put_dt(dynamic, DT_TEXTREL, 0);
            जर (file_type & TCC_OUTPUT_EXE)
                dt_flags_1 = DF_1_NOW | DF_1_PIE;
	    जर (s1->znodelete)
		dt_flags_1 |= DF_1_NODELETE;
        }
        put_dt(dynamic, DT_FLAGS, DF_BIND_NOW);
        put_dt(dynamic, DT_FLAGS_1, dt_flags_1);
        जर (s1->symbolic)
            put_dt(dynamic, DT_SYMBOLIC, 0);

        dyninf.dynamic = dynamic;
        dyninf.dynstr = dynstr;
        /* remember offset and reserve space for 2nd call below */
        dyninf.data_offset = dynamic->data_offset;
        fill_dynamic(s1, &dyninf);
        dynamic->sh_size = dynamic->data_offset;
        dynstr->sh_size = dynstr->data_offset;
    }

    /* create and fill .shstrtab section */
    alloc_sec_names(s1, 0);
    /* this array is used to reorder sections in the output file */
    sec_order = tcc_malloc(आकार(पूर्णांक) * 2 * s1->nb_sections);
    /* compute section to program header mapping */
    layout_sections(s1, sec_order, &dyninf);

        जर (dynamic) {
            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->data, dynamic->sh_addr);
            जर (file_type == TCC_OUTPUT_EXE
                || (RELOCATE_DLLPLT && (file_type & TCC_OUTPUT_DYN)))
                relocate_plt(s1);
            /* relocate symbols in .dynsym now that final addresses are known */
            relocate_syms(s1, s1->dynsym, 2);
        }

        /* if building executable or DLL, then relocate each section
           except the GOT which is already relocated */
        relocate_syms(s1, s1->symtab, 0);
        जर (s1->nb_errors != 0)
            जा the_end;
        relocate_sections(s1);
        जर (dynamic) {
	    update_reloc_sections (s1, &dyninf);
            dynamic->data_offset = dyninf.data_offset;
            fill_dynamic(s1, &dyninf);
	}
        /* Perform relocation to GOT or PLT entries */
        जर (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        अन्यथा जर (s1->got)
            fill_local_got_entries(s1);

    जर (dyninf.gnu_hash)
        update_gnu_hash(s1, dyninf.gnu_hash);

    reorder_sections(s1, sec_order);
#जर TCC_EH_FRAME
    /* fill with final data */
    tcc_eh_frame_hdr(s1, 1);
#endif
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, dyninf.phnum, dyninf.phdr);
 the_end:
    tcc_free(sec_order);
    tcc_free(dyninf.phdr);
    परत ret;
}
#endif /* ndef ELF_OBJ_ONLY */

/* Allocate strings for section names */
स्थिर शून्य alloc_sec_names(TCCState *s1, पूर्णांक is_obj)
{
    पूर्णांक i;
    Section *s, *strsec;

    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");
    साठी(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        जर (is_obj)
            s->sh_size = s->data_offset;
	जर (s->sh_size || s == strsec || (s->sh_flags & SHF_ALLOC) || is_obj)
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_size = strsec->data_offset;
}

/* Output an elf .o file */
स्थिर पूर्णांक elf_output_obj(TCCState *s1, स्थिरांक अक्षर *filename)
{
    Section *s;
    पूर्णांक i, ret, file_offset;
    /* Allocate strings for section names */
    alloc_sec_names(s1, 1);
    file_offset = (आकार (ElfW(Ehdr)) + 3) & -4;
    file_offset += s1->nb_sections * आकार(ElfW(Shdr));
    साठी(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        file_offset = (file_offset + 15) & -16;
        s->sh_offset = file_offset;
        जर (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_size;
    }
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, 0, रिक्त);
    परत ret;
}

LIBTCCAPI पूर्णांक tcc_output_file(TCCState *s, स्थिरांक अक्षर *filename)
{
    s->nb_errors = 0;
    जर (s->test_coverage)
        tcc_tcov_add_file(s, filename);
    जर (s->output_type == TCC_OUTPUT_OBJ)
        परत elf_output_obj(s, filename);
#ifdef TCC_TARGET_PE
    परत  pe_output_file(s, filename);
#किंवाजर defined TCC_TARGET_MACHO
    परत macho_output_file(s, filename);
#अन्यथा
    परत elf_output_file(s, filename);
#endif
}

ST_FUNC ssize_t full_read(पूर्णांक fd, शून्य *buf, माप_प्रकार मोजणी_2) {
    अक्षर *cbuf = buf;
    माप_प्रकार rnum = 0;
    पर्यंत (1) {
        ssize_t अंक = पठ(fd, cbuf, मोजणी_2-rnum);
        जर (अंक < 0) परत अंक;
        जर (अंक == 0) परत rnum;
        rnum += अंक;
        cbuf += अंक;
    }
}

ST_FUNC शून्य *load_data(पूर्णांक fd, अचिन्हित दीर्घ file_offset, अचिन्हित दीर्घ size)
{
    शून्य *data;

    data = tcc_malloc(size);
    lseek(fd, file_offset, शुरू_से);
    full_read(fd, data, size);
    परत data;
}

प्रकारव्याख्या संरचना SectionMergeInfo {
    Section *s;            /* corresponding existing section */
    अचिन्हित दीर्घ offset;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} SectionMergeInfo;

ST_FUNC पूर्णांक tcc_object_type(पूर्णांक fd, ElfW(Ehdr) *h)
{
    पूर्णांक size = full_read(fd, h, आकार *h);
    जर (size == आकार *h && 0 == स_भेद(h, ELFMAG, 4)) {
        जर (h->e_type == ET_REL)
            परत AFF_BINTYPE_REL;
        जर (h->e_type == ET_DYN)
            परत AFF_BINTYPE_DYN;
    } अन्यथा जर (size >= 8) {
        जर (0 == स_भेद(h, ARMAG, 8))
            परत AFF_BINTYPE_AR;
#ifdef TCC_TARGET_COFF
        जर (((संरचना filehdr*)h)->f_magic == COFF_C67_MAGIC)
            परत AFF_BINTYPE_C67;
#endif
    }
    परत 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC पूर्णांक tcc_load_object_file(TCCState *s1,
                                पूर्णांक fd, अचिन्हित दीर्घ file_offset)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    अचिन्हित दीर्घ size, offset, offseti;
    पूर्णांक i, j, nb_syms, sym_index, ret, seencompressed;
    अक्षर *strsec, *strtab;
    पूर्णांक stab_index, stabstr_index;
    पूर्णांक *old_to_new_syms;
    अक्षर *sh_name, *name;
    SectionMergeInfo *sm_table, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    lseek(fd, file_offset, शुरू_से);
    जर (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        जा invalid;
    /* test CPU specific stuff */
    जर (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
invalid:
        परत tcc_error_noabort("invalid object file");
    }
    /* read sections */
    shdr = load_data(fd, file_offset + ehdr.e_shoff,
                     आकार(ElfW(Shdr)) * ehdr.e_shnum);
    sm_table = tcc_mallocz(आकार(SectionMergeInfo) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);

    /* load symtab and strtab */
    old_to_new_syms = रिक्त;
    symtab = रिक्त;
    strtab = रिक्त;
    nb_syms = 0;
    seencompressed = 0;
    stab_index = stabstr_index = 0;
    ret = -1;

    साठी(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        जर (sh->sh_type == SHT_SYMTAB) {
            जर (symtab) {
                tcc_error_noabort("object must contain only one symtab");
                जा the_end;
            }
            nb_syms = sh->sh_size / आकार(ElfW(Sym));
            symtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
            sm_table[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
        }
	जर (sh->sh_flags & SHF_COMPRESSED)
	    seencompressed = 1;
    }

    /* now examine each section and try to merge its content with the
       ones in memory */
    साठी(i = 1; i < ehdr.e_shnum; i++) {
        /* no need to examine section name strtab */
        जर (i == ehdr.e_shstrndx)
            सुरूठेवा;
        sh = &shdr[i];
	जर (sh->sh_type == SHT_RELX)
	  sh = &shdr[sh->sh_info];
        /* ignore sections types we do not handle (plus relocs to those) */
        sh_name = strsec + sh->sh_name;
        जर (0 == म_भेदन(sh_name, ".debug_", 7)
         || 0 == म_भेदन(sh_name, ".stab", 5)) {
	    जर (!s1->do_debug || seencompressed)
	        सुरूठेवा;
#जर !(TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD)
        } अन्यथा जर (0 == म_भेदन(sh_name, ".eh_frame", 9)) {
            जर (रिक्त == eh_frame_section)
                सुरूठेवा;
#endif
        } अन्यथा
        जर (sh->sh_type != SHT_PROGBITS &&
            sh->sh_type != SHT_NOTE &&
            sh->sh_type != SHT_NOBITS &&
            sh->sh_type != SHT_PREINIT_ARRAY &&
            sh->sh_type != SHT_INIT_ARRAY &&
            sh->sh_type != SHT_FINI_ARRAY
#ifdef TCC_ARM_EABI
            /* Added in commit f99d3de221db23e322c6c18c8249282e27726c25
               but suppressed in 3cfaaaf1eb97d858e583412616f68f75fdad5da5
               So don't load it in order to avoid dangling references from
               (STT_SECTION) symbols. */
            // && sh->sh_type != SHT_ARM_EXIDX
#endif

#जर TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD
            && sh->sh_type != SHT_X86_64_UNWIND
#endif
            )
            सुरूठेवा;

	sh = &shdr[i];
        sh_name = strsec + sh->sh_name;
        जर (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        /* find corresponding section, if any */
        साठी(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            जर (म_भेद(s->name, sh_name))
                सुरूठेवा;
            जर (sh->sh_type != s->sh_type
                && म_भेद (s->name, ".eh_frame")
                /* some crt1.o seem to have two ".note.GNU-stack" (SHT_NOTE & SHT_PROGBITS) */
                && म_भेद (s->name, ".note.GNU-stack")
                ) {
                tcc_error_noabort("section type conflict: %s %02x <> %02x", s->name, sh->sh_type, s->sh_type);
                जा the_end;
            }
            जर (!म_भेदन(sh_name, ".gnu.linkonce", 13)) {
                /* if a 'linkonce' section is already present, we
                   do not add it again. It is a little tricky as
                   symbols can still be defined in
                   it. */
                sm_table[i].link_once = 1;
                जा next;
            }
            जर (stab_section) {
                जर (s == stab_section)
                    stab_index = i;
                जर (s == stab_section->link)
                    stabstr_index = i;
            }
            जा found;
        }
        /* not found: create new section */
        s = new_section(s1, sh_name, sh->sh_type, sh->sh_flags & ~SHF_GROUP);
        /* take as much info as possible from the section. sh_link and
           sh_info will be updated later */
        s->sh_addralign = sh->sh_addralign;
        s->sh_entsize = sh->sh_entsize;
        sm_table[i].new_section = 1;
    found:
        size = sh->sh_size;
        /* align start of section */
        offset = section_add(s, size, sh->sh_addralign);
        जर (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        sm_table[i].offset = offset;
        sm_table[i].s = s;
        /* concatenate sections */
        जर (sh->sh_type != SHT_NOBITS && size) {
            अचिन्हित अक्षर *ptr;
            lseek(fd, file_offset + sh->sh_offset, शुरू_से);
            ptr = s->data + offset;
            full_read(fd, ptr, size);
        }
#जर defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
        /* align code sections to instruction lenght */
        /* This is needed if we compile a c file after this */
        जर (s->sh_flags & SHF_EXECINSTR)
            section_add(s, 0, 4);
#endif
    next: ;
    }

    /* gr relocate stab strings */
    जर (stab_index && stabstr_index) {
        Stab_Sym *a, *b;
        अचिन्हित o;
        s = sm_table[stab_index].s;
        a = (Stab_Sym *)(s->data + sm_table[stab_index].offset);
        b = (Stab_Sym *)(s->data + s->data_offset);
        o = sm_table[stabstr_index].offset;
        पर्यंत (a < b) {
            जर (a->n_strx)
                a->n_strx += o;
            a++;
        }
    }

    /* second short pass to update sh_link and sh_info fields of new
       sections */
    साठी(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        जर (!s || !sm_table[i].new_section)
            सुरूठेवा;
        sh = &shdr[i];
        जर (sh->sh_link > 0)
            s->link = sm_table[sh->sh_link].s;
        जर (sh->sh_type == SHT_RELX) {
            s->sh_info = sm_table[sh->sh_info].s->sh_अंक;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }

    जर (!symtab)
        जा done;

    /* resolve symbols */
    old_to_new_syms = tcc_mallocz(nb_syms * आकार(पूर्णांक));

    sym = symtab + 1;
    साठी(i = 1; i < nb_syms; i++, sym++) {
        जर (sym->st_shndx != SHN_UNDEF &&
            sym->st_shndx < SHN_LORESERVE) {
            sm = &sm_table[sym->st_shndx];
            जर (sm->link_once) {
                /* if a symbol is in a link once section, we use the
                   already defined symbol. It is very important to get
                   correct relocations */
                जर (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
                    name = strtab + sym->st_name;
                    sym_index = find_elf_sym(symtab_section, name);
                    जर (sym_index)
                        old_to_new_syms[i] = sym_index;
                }
                सुरूठेवा;
            }
            /* if no corresponding section added, no need to add symbol */
            जर (!sm->s)
                सुरूठेवा;
            /* convert section number */
            sym->st_shndx = sm->s->sh_अंक;
            /* offset value */
            sym->st_मूल्य += sm->offset;
        }
        /* add symbol */
        name = strtab + sym->st_name;
        sym_index = set_elf_sym(symtab_section, sym->st_मूल्य, sym->st_size,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_to_new_syms[i] = sym_index;
    }

    /* third pass to patch relocation entries */
    साठी(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        जर (!s)
            सुरूठेवा;
        sh = &shdr[i];
        offset = sm_table[i].offset;
        size = sh->sh_size;
        निवड(s->sh_type) {
        स्थिती SHT_RELX:
            /* take relocation offset information */
            offseti = sm_table[sh->sh_info].offset;
	    साठी (rel = (ElfW_Rel *) s->data + (offset / आकार(*rel));
		 rel < (ElfW_Rel *) s->data + ((offset + size) / आकार(*rel));
		 rel++) {
                पूर्णांक type;
                अचिन्हित sym_index;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_index = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                जर (sym_index >= nb_syms)
                    जा invalid_reloc;
                sym_index = old_to_new_syms[sym_index];
                /* ignore link_once in rel section. */
                जर (!sym_index && !sm_table[sh->sh_info].link_once
#ifdef TCC_TARGET_ARM
                    && type != R_ARM_V4BX
#किंवाजर defined TCC_TARGET_RISCV64
                    && type != R_RISCV_ALIGN
                    && type != R_RISCV_RELAX
#endif
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, (पूर्णांक)rel->r_offset);
                    जा the_end;
                }
                rel->r_info = ELFW(R_INFO)(sym_index, type);
                /* offset the relocation offset */
                rel->r_offset += offseti;
#ifdef TCC_TARGET_ARM
                /* Jumps and branches from a Thumb code to a PLT entry need
                   special handling since PLT entries are ARM code.
                   Unconditional bl instructions referencing PLT entries are
                   handled by converting these instructions into blx
                   instructions. Other case of instructions referencing a PLT
                   entry require to add a Thumb stub before the PLT entry to
                   switch to ARM mode. We set bit plt_thumb_stub of the
                   attribute of a symbol to indicate such a case. */
                जर (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_index, 1)->plt_thumb_stub = 1;
#endif
            }
            थांबा;
        पूर्वनिर्धारित:
            थांबा;
        }
    }
 done:
    ret = !s1->nb_errors - 1; /* errors possibly from set_elf_sym() */
 the_end:
    tcc_free(symtab);
    tcc_free(strtab);
    tcc_free(old_to_new_syms);
    tcc_free(sm_table);
    tcc_free(strsec);
    tcc_free(shdr);
    परत ret;
}

प्रकारव्याख्या संरचना ArchiveHeader {
    अक्षर ar_name[16];           /* name of this member */
    अक्षर ar_date[12];           /* file mtime */
    अक्षर ar_uid[6];             /* owner uid; printed as decimal */
    अक्षर ar_gid[6];             /* owner gid; printed as decimal */
    अक्षर ar_mode[8];            /* file mode, printed as octal   */
    अक्षर ar_size[10];           /* file size, printed as decimal */
    अक्षर ar_fmag[2];            /* should contain ARFMAG */
} ArchiveHeader;

#define ARFMAG "`\n"

स्थिर अचिन्हित दीर्घ दीर्घ get_be(स्थिरांक uint8_t *b, पूर्णांक n)
{
    अचिन्हित दीर्घ दीर्घ ret = 0;
    पर्यंत (n)
        ret = (ret << 8) | *b++, --n;
    परत ret;
}

स्थिर पूर्णांक read_ar_header(पूर्णांक fd, पूर्णांक offset, ArchiveHeader *hdr)
{
    अक्षर *p, *e;
    पूर्णांक len;
    lseek(fd, offset, शुरू_से);
    len = full_read(fd, hdr, आकार(ArchiveHeader));
    जर (len != आकार(ArchiveHeader))
        परत len ? -1 : 0;
    जर (स_भेद(hdr->ar_fmag, ARFMAG, आकार hdr->ar_fmag))
        परत -1;
    p = hdr->ar_name;
    साठी (e = p + आकार hdr->ar_name; e > p && e[-1] == ' ';)
        --e;
    *e = '\0';
    hdr->ar_size[आकार hdr->ar_size-1] = 0;
    परत len;
}

/* load only the objects which resolve undefined symbols */
स्थिर पूर्णांक tcc_load_alacarte(TCCState *s1, पूर्णांक fd, पूर्णांक size, पूर्णांक entrysize)
{
    पूर्णांक i, bound, nsyms, sym_index, len, ret = -1;
    अचिन्हित दीर्घ दीर्घ off;
    uint8_t *data;
    स्थिरांक अक्षर *ar_names, *p;
    स्थिरांक uint8_t *ar_index;
    ElfW(Sym) *sym;
    ArchiveHeader hdr;

    data = tcc_malloc(size);
    जर (full_read(fd, data, size) != size)
        जा invalid;
    nsyms = get_be(data, entrysize);
    ar_index = data + entrysize;
    ar_names = (अक्षर *) ar_index + nsyms * entrysize;

    करा {
        bound = 0;
        साठी (p = ar_names, i = 0; i < nsyms; i++, p += म_माप(p)+1) {
            Section *s = symtab_section;
            sym_index = find_elf_sym(s, p);
            जर (!sym_index)
                सुरूठेवा;
            sym = &((ElfW(Sym) *)s->data)[sym_index];
            जर(sym->st_shndx != SHN_UNDEF)
                सुरूठेवा;
            off = get_be(ar_index + i * entrysize, entrysize);
            len = read_ar_header(fd, off, &hdr);
            जर (len <= 0 || स_भेद(hdr.ar_fmag, ARFMAG, 2)) {
        invalid:
                tcc_error_noabort("invalid archive");
                जा the_end;
            }
            off += len;
            जर (s1->verbose == 2)
                म_लिखो("   -> %s\n", hdr.ar_name);
            जर (tcc_load_object_file(s1, fd, off) < 0)
                जा the_end;
            ++bound;
        }
    } पर्यंत(bound);
    ret = 0;
 the_end:
    tcc_free(data);
    परत ret;
}

/* load a '.a' file */
ST_FUNC पूर्णांक tcc_load_archive(TCCState *s1, पूर्णांक fd, पूर्णांक alacarte)
{
    ArchiveHeader hdr;
    /* char magic[8]; */
    पूर्णांक size, len;
    अचिन्हित दीर्घ file_offset;
    ElfW(Ehdr) ehdr;

    /* skip magic which was already checked */
    /* full_read(fd, magic, sizeof(magic)); */
    file_offset = आकार ARMAG - 1;

    साठी(;;) {
        len = read_ar_header(fd, file_offset, &hdr);
        जर (len == 0)
            परत 0;
        जर (len < 0)
            परत tcc_error_noabort("invalid archive");
        file_offset += len;
        size = म_से_दीर्घ(hdr.ar_size, रिक्त, 0);
        जर (alacarte) {
            /* coff symbol table : we handle it */
            जर (!म_भेद(hdr.ar_name, "/"))
                परत tcc_load_alacarte(s1, fd, size, 4);
            जर (!म_भेद(hdr.ar_name, "/SYM64/"))
                परत tcc_load_alacarte(s1, fd, size, 8);
        } अन्यथा जर (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
            जर (s1->verbose == 2)
                म_लिखो("   -> %s\n", hdr.ar_name);
            जर (tcc_load_object_file(s1, fd, file_offset) < 0)
                परत -1;
        }
        /* align to even */
        file_offset = (file_offset + size + 1) & ~1;
    }
}

#ifndef ELF_OBJ_ONLY
/* Set LV[I] to the global index of sym-version (LIB,VERSION).  Maybe resizes
   LV, maybe create a new entry for (LIB,VERSION).  */
स्थिर शून्य set_ver_to_ver(TCCState *s1, पूर्णांक *n, पूर्णांक **lv, पूर्णांक i, अक्षर *lib, अक्षर *version)
{
    पर्यंत (i >= *n) {
        *lv = tcc_realloc(*lv, (*n + 1) * आकार(**lv));
        (*lv)[(*n)++] = -1;
    }
    जर ((*lv)[i] == -1) {
        पूर्णांक v, prev_same_lib = -1;
        साठी (v = 0; v < nb_sym_versions; v++) {
            जर (म_भेद(sym_versions[v].lib, lib))
              सुरूठेवा;
            prev_same_lib = v;
            जर (!म_भेद(sym_versions[v].version, version))
              थांबा;
        }
        जर (v == nb_sym_versions) {
            sym_versions = tcc_realloc (sym_versions,
                                        (v + 1) * आकार(*sym_versions));
            sym_versions[v].lib = tcc_strdup(lib);
            sym_versions[v].version = tcc_strdup(version);
            sym_versions[v].out_index = 0;
            sym_versions[v].prev_same_lib = prev_same_lib;
            nb_sym_versions++;
        }
        (*lv)[i] = v;
    }
}

/* Associates symbol SYM_INDEX (in dynsymtab) with sym-version index
   VERNDX.  */
स्थिर शून्य
set_sym_version(TCCState *s1, पूर्णांक sym_index, पूर्णांक verndx)
{
    जर (sym_index >= nb_sym_to_version) {
        पूर्णांक newelems = sym_index ? sym_index * 2 : 1;
        sym_to_version = tcc_realloc(sym_to_version,
                                     newelems * आकार(*sym_to_version));
        स_रखो(sym_to_version + nb_sym_to_version, -1,
               (newelems - nb_sym_to_version) * आकार(*sym_to_version));
        nb_sym_to_version = newelems;
    }
    जर (sym_to_version[sym_index] < 0)
      sym_to_version[sym_index] = verndx;
}

संरचना versym_info {
    पूर्णांक nb_versyms;
    ElfW(Verdef) *verdef;
    ElfW(Verneed) *verneed;
    ElfW(Half) *versym;
    पूर्णांक nb_local_ver, *local_ver;
};


स्थिर शून्य store_version(TCCState *s1, संरचना versym_info *v, अक्षर *dynstr)
{
    अक्षर *lib, *version;
    uint32_t next;
    पूर्णांक i;

#define	DEBUG_VERSION 0

    जर (v->versym && v->verdef) {
      ElfW(Verdef) *vdef = v->verdef;
      lib = रिक्त;
      करा {
        ElfW(Verdaux) *verdaux =
	  (ElfW(Verdaux) *) (((अक्षर *) vdef) + vdef->vd_aux);

#जर DEBUG_VERSION
	म_लिखो ("verdef: version:%u flags:%u index:%u, hash:%u\n",
	        vdef->vd_version, vdef->vd_flags, vdef->vd_ndx,
		vdef->vd_hash);
#endif
	जर (vdef->vd_cnt) {
          version = dynstr + verdaux->vda_name;

	  जर (lib == रिक्त)
	    lib = version;
	  अन्यथा
            set_ver_to_ver(s1, &v->nb_local_ver, &v->local_ver, vdef->vd_ndx,
                           lib, version);
#जर DEBUG_VERSION
	  म_लिखो ("  verdaux(%u): %s\n", vdef->vd_ndx, version);
#endif
	}
        next = vdef->vd_next;
        vdef = (ElfW(Verdef) *) (((अक्षर *) vdef) + next);
      } पर्यंत (next);
    }
    जर (v->versym && v->verneed) {
      ElfW(Verneed) *vneed = v->verneed;
      करा {
        ElfW(Vernaux) *vernaux =
	  (ElfW(Vernaux) *) (((अक्षर *) vneed) + vneed->vn_aux);

        lib = dynstr + vneed->vn_file;
#जर DEBUG_VERSION
	म_लिखो ("verneed: %u %s\n", vneed->vn_version, lib);
#endif
	साठी (i = 0; i < vneed->vn_cnt; i++) {
	  जर ((vernaux->vna_other & 0x8000) == 0) { /* hidden */
              version = dynstr + vernaux->vna_name;
              set_ver_to_ver(s1, &v->nb_local_ver, &v->local_ver, vernaux->vna_other,
                             lib, version);
#जर DEBUG_VERSION
	    म_लिखो ("  vernaux(%u): %u %u %s\n",
		    vernaux->vna_other, vernaux->vna_hash,
		    vernaux->vna_flags, version);
#endif
	  }
	  vernaux = (ElfW(Vernaux) *) (((अक्षर *) vernaux) + vernaux->vna_next);
	}
        next = vneed->vn_next;
        vneed = (ElfW(Verneed) *) (((अक्षर *) vneed) + next);
      } पर्यंत (next);
    }

#जर DEBUG_VERSION
    साठी (i = 0; i < v->nb_local_ver; i++) {
      जर (v->local_ver[i] > 0) {
        म_लिखो ("%d: lib: %s, version %s\n",
		i, sym_versions[v->local_ver[i]].lib,
                sym_versions[v->local_ver[i]].version);
      }
    }
#endif
}

/* load a library / DLL
   'level = 0' means that the DLL is referenced by the user
   (so it should be added as DT_NEEDED in the generated ELF file) */
ST_FUNC पूर्णांक tcc_load_dll(TCCState *s1, पूर्णांक fd, स्थिरांक अक्षर *filename, पूर्णांक level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    पूर्णांक i, nb_syms, nb_dts, sym_bind, ret = -1;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;

    अक्षर *dynstr;
    पूर्णांक sym_index;
    स्थिरांक अक्षर *name, *soname;
    संरचना versym_info v;

    full_read(fd, &ehdr, आकार(ehdr));

    /* test CPU specific stuff */
    जर (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
        परत tcc_error_noabort("bad architecture");
    }

    /* read sections */
    shdr = load_data(fd, ehdr.e_shoff, आकार(ElfW(Shdr)) * ehdr.e_shnum);

    /* load dynamic section and dynamic symbols */
    nb_syms = 0;
    nb_dts = 0;
    dynamic = रिक्त;
    dynsym = रिक्त; /* avoid warning */
    dynstr = रिक्त; /* avoid warning */
    स_रखो(&v, 0, आकार v);

    साठी(i = 0, sh = shdr; i < ehdr.e_shnum; i++, sh++) {
        निवड(sh->sh_type) {
        स्थिती SHT_DYNAMIC:
            nb_dts = sh->sh_size / आकार(ElfW(Dyn));
            dynamic = load_data(fd, sh->sh_offset, sh->sh_size);
            थांबा;
        स्थिती SHT_DYNSYM:
            nb_syms = sh->sh_size / आकार(ElfW(Sym));
            dynsym = load_data(fd, sh->sh_offset, sh->sh_size);
            sh1 = &shdr[sh->sh_link];
            dynstr = load_data(fd, sh1->sh_offset, sh1->sh_size);
            थांबा;
        स्थिती SHT_GNU_verdef:
	    v.verdef = load_data(fd, sh->sh_offset, sh->sh_size);
	    थांबा;
        स्थिती SHT_GNU_verneed:
	    v.verneed = load_data(fd, sh->sh_offset, sh->sh_size);
	    थांबा;
        स्थिती SHT_GNU_versym:
            v.nb_versyms = sh->sh_size / आकार(ElfW(Half));
	    v.versym = load_data(fd, sh->sh_offset, sh->sh_size);
	    थांबा;
        पूर्वनिर्धारित:
            थांबा;
        }
    }

    जर (!dynamic)
        जा the_end;

    /* compute the real library name */
    soname = tcc_basename(filename);
    साठी(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        जर (dt->d_tag == DT_SONAME)
            soname = dynstr + dt->d_un.d_val;

    /* if the dll is already loaded, do not load it */
    जर (tcc_add_dllref(s1, soname, level)->found)
        जा ret_success;

    जर (v.nb_versyms != nb_syms)
        tcc_free (v.versym), v.versym = रिक्त;
    अन्यथा
        store_version(s1, &v, dynstr);

    /* add dynamic symbols in dynsym_section */
    साठी(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        जर (sym_bind == STB_LOCAL)
            सुरूठेवा;
        name = dynstr + sym->st_name;
        sym_index = set_elf_sym(s1->dynsymtab_section, sym->st_मूल्य, sym->st_size,
                                sym->st_info, sym->st_other, sym->st_shndx, name);
        जर (v.versym) {
            ElfW(Half) vsym = v.versym[i];
            जर ((vsym & 0x8000) == 0 && vsym > 0 && vsym < v.nb_local_ver)
                set_sym_version(s1, sym_index, v.local_ver[vsym]);
        }
    }

    /* do not load all referenced libraries
       (recursive loading can break linking of libraries) */
    /* following DT_NEEDED is needed for the dynamic loader (libdl.so),
       but it is no longer needed, when linking a library or a program.
       When tcc output mode is OUTPUT_MEM,
       tcc calls dlopen, which handles DT_NEEDED for us */

#जर 0
    साठी(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        जर (dt->d_tag == DT_RPATH)
            tcc_add_library_path(s1, dynstr + dt->d_un.d_val);

    /* load all referenced DLLs */
    साठी(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        निवड(dt->d_tag) {
        स्थिती DT_NEEDED:
            name = dynstr + dt->d_un.d_val;
            जर (tcc_add_dllref(s1, name, -1))
                सुरूठेवा;
            जर (tcc_add_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                ret = tcc_error_noabort("referenced dll '%s' not found", name);
                जा the_end;
            }
        }
    }
#endif

 ret_success:
    ret = 0;
 the_end:
    tcc_free(dynstr);
    tcc_free(dynsym);
    tcc_free(dynamic);
    tcc_free(shdr);
    tcc_free(v.local_ver);
    tcc_free(v.verdef);
    tcc_free(v.verneed);
    tcc_free(v.versym);
    परत ret;
}

#define LD_TOK_NAME 256
#define LD_TOK_EOF  (-1)
स्थिर पूर्णांक ld_inp(TCCState *s1)
{
    पूर्णांक c = *s1->ld_p;
    जर (c == 0)
        परत CH_EOF;
    ++s1->ld_p;
    परत c;
}
#define ld_unget(s1, ch) जर (ch != CH_EOF) --s1->ld_p

/* return next ld script token */
स्थिर पूर्णांक ld_next(TCCState *s1, अक्षर *name, पूर्णांक name_size)
{
    पूर्णांक c, d, ch;
    अक्षर *q;

 redo:
    ch = ld_inp(s1);
    q = name, *q++ = ch;
    निवड(ch) {
    स्थिती ' ':
    स्थिती '\t':
    स्थिती '\f':
    स्थिती '\v':
    स्थिती '\r':
    स्थिती '\n':
        जा redo;
    स्थिती '/':
        ch = ld_inp(s1);
        जर (ch == '*') { /* comment */
            साठी (d = 0;; d = ch) {
                ch = ld_inp(s1);
                जर (ch == CH_EOF || (ch == '/' && d == '*'))
                    थांबा;
            }
            जा redo;
        } अन्यथा {
            जा parse_name;
        }
        थांबा;
    स्थिती '\\':
    /* case 'a' ... 'z': */
    स्थिती 'a':
       स्थिती 'b':
       स्थिती 'c':
       स्थिती 'd':
       स्थिती 'e':
       स्थिती 'f':
       स्थिती 'g':
       स्थिती 'h':
       स्थिती 'i':
       स्थिती 'j':
       स्थिती 'k':
       स्थिती 'l':
       स्थिती 'm':
       स्थिती 'n':
       स्थिती 'o':
       स्थिती 'p':
       स्थिती 'q':
       स्थिती 'r':
       स्थिती 's':
       स्थिती 't':
       स्थिती 'u':
       स्थिती 'v':
       स्थिती 'w':
       स्थिती 'x':
       स्थिती 'y':
       स्थिती 'z':
    /* case 'A' ... 'z': */
    स्थिती 'A':
       स्थिती 'B':
       स्थिती 'C':
       स्थिती 'D':
       स्थिती 'E':
       स्थिती 'F':
       स्थिती 'G':
       स्थिती 'H':
       स्थिती 'I':
       स्थिती 'J':
       स्थिती 'K':
       स्थिती 'L':
       स्थिती 'M':
       स्थिती 'N':
       स्थिती 'O':
       स्थिती 'P':
       स्थिती 'Q':
       स्थिती 'R':
       स्थिती 'S':
       स्थिती 'T':
       स्थिती 'U':
       स्थिती 'V':
       स्थिती 'W':
       स्थिती 'X':
       स्थिती 'Y':
       स्थिती 'Z':
    स्थिती '-':
    स्थिती '_':
    स्थिती '.':
    स्थिती '$':
    स्थिती '~':
        साठी(;;) {
            ch = ld_inp(s1);
    parse_name:
            जर (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') ||
                  म_अक्षर("/.-_+=$:\\,~", ch)))
                थांबा;
            जर ((q - name) < name_size - 1) {
                *q++ = ch;
            }
        }
        ld_unget(s1, ch);
        c = LD_TOK_NAME;
        थांबा;
    स्थिती CH_EOF:
        c = LD_TOK_EOF;
        थांबा;
    पूर्वनिर्धारित:
        c = ch;
        थांबा;
    }
    *q = '\0';
    परत c;
}

स्थिर पूर्णांक ld_add_file(TCCState *s1, स्थिरांक अक्षर filename[])
{
    जर (filename[0] == '-' && filename[1] == 'l')
        परत tcc_add_library(s1, filename + 2);
    जर (CONFIG_SYSROOT[0] != '\0' || !IS_ABSPATH(filename)) {
        /* lookup via library paths */
        पूर्णांक ret = tcc_add_dll(s1, tcc_basename(filename), 0);
        जर (ret != FILE_NOT_FOUND)
            परत ret;
    }
    परत tcc_add_file_internal(s1, filename, AFF_PRINT_ERROR);
}

/* did static libraries add new undefined symbols? */
स्थिर पूर्णांक new_undef_sym(TCCState *s1, पूर्णांक sym_offset)
{
    पर्यंत (sym_offset < s1->symtab->data_offset) {
        ElfW(Sym) *esym = (शून्य*)(s1->symtab->data + sym_offset);
        जर (esym->st_shndx == SHN_UNDEF)
            परत 1;
        sym_offset += आकार (ElfW(Sym));
    }
    परत 0;
}

स्थिर पूर्णांक ld_add_file_list(TCCState *s1, स्थिरांक अक्षर *cmd)
{
    अक्षर filename[1024];
    पूर्णांक t, c, sym_offset, ret = 0;
    अचिन्हित अक्षर *pos = s1->ld_p;

repeat:
    s1->ld_p = pos;
    sym_offset = s1->symtab->data_offset;
    c = cmd[0];

    t = ld_next(s1, filename, आकार(filename));
    जर (t != '(')
        परत tcc_error_noabort("expected '(' after %s", cmd);
    t = ld_next(s1, filename, आकार(filename));
    साठी(;;) {
        जर (t == LD_TOK_EOF) {
            परत tcc_error_noabort("unexpected end of file");
        } अन्यथा जर (t == ')') {
            थांबा;
        } अन्यथा जर (t != LD_TOK_NAME) {
            परत tcc_error_noabort("unexpected token '%c'", t);
        } अन्यथा जर (!म_भेद(filename, "AS_NEEDED")) {
            ret |= ld_add_file_list(s1, filename);
        } अन्यथा जर (c == 'I' || c == 'G' || c == 'A') {
            ret |= !!ld_add_file(s1, filename);
        }
        जर (ret < 0)
            परत ret;
        t = ld_next(s1, filename, आकार(filename));
        जर (t == ',')
            t = ld_next(s1, filename, आकार(filename));
    }
    जर (c == 'G' && ret == 0 && new_undef_sym(s1, sym_offset))
        जा repeat;
    परत ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC पूर्णांक tcc_load_ldscript(TCCState *s1, पूर्णांक fd)
{
    अक्षर cmd[64];
    पूर्णांक t, ret = 0, noscript = 1;
    अचिन्हित अक्षर *text_ptr, *saved_ptr;

    saved_ptr = s1->ld_p;
    s1->ld_p = text_ptr = (शून्य*)tcc_load_text(fd);
    साठी(;;) {
        t = ld_next(s1, cmd, आकार(cmd));
        जर (t == LD_TOK_EOF)
            थांबा;
        जर (!म_भेद(cmd, "INPUT") ||
            !म_भेद(cmd, "GROUP")) {
            ret |= ld_add_file_list(s1, cmd);
        } अन्यथा जर (!म_भेद(cmd, "OUTPUT_FORMAT") ||
                   !म_भेद(cmd, "TARGET")) {
            /* ignore some commands */
            ret |= ld_add_file_list(s1, cmd);
        } अन्यथा जर (noscript) {
            ret = FILE_NOT_RECOGNIZED;
        } अन्यथा {
            ret = tcc_error_noabort("unexpected '%s'", cmd);
        }
        जर (ret < 0)
            थांबा;
        noscript = 0;
    }
    tcc_free(text_ptr);
    s1->ld_p = saved_ptr;
    परत ret < 0 ? ret : -ret;
}
#endif /* !ELF_OBJ_ONLY */
