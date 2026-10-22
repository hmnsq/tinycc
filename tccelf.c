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

#समावेश "tcc.h"

/* Define this to get some debug output during relocation processing.  */
#अघोषित DEBUG_RELOC

/********************************************************/
/* global variables */

/* elf version information */
काष्ठा sym_version {
    अक्षर *lib;
    अक्षर *version;
    पूर्णांक out_सूचकांक;
    पूर्णांक पूर्व_same_lib;
};

#घोषणा nb_sym_versions     s1->nb_sym_versions
#घोषणा sym_versions        s1->sym_versions
#घोषणा nb_sym_to_version   s1->nb_sym_to_version
#घोषणा sym_to_version      s1->sym_to_version
#घोषणा dt_verneednum       s1->dt_verneednum
#घोषणा versym_section      s1->versym_section
#घोषणा verneed_section     s1->verneed_section

/* special flag to indicate that the section should not be linked to the other ones */
#घोषणा SHF_PRIVATE 0x80000000
/* section is dynsymtab_section */
#घोषणा SHF_DYNSYM 0x40000000

#अगर_घोषित TCC_TARGET_PE
#घोषणा shf_RELRO SHF_ALLOC
अटल स्थिर अक्षर rdata[] = ".rdata";
#अन्यथा
#घोषणा shf_RELRO SHF_ALLOC /* eventually made SHF_WRITE in sort_sections() */
अटल स्थिर अक्षर rdata[] = ".data.ro";
#पूर्ण_अगर

/* ------------------------------------------------------------------------- */

ST_FUNC व्योम tccelf_new(TCCState *s)
{
    TCCState *s1 = s;

    /* no section zero */
    dynarray_add(&s->sections, &s->nb_sections, शून्य);

    /* create standard sections */
    text_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    तथ्य_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
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

    अगर (s->do_debug) {
        /* add debug sections */
        tcc_debug_new(s);
    }

#अगर TCC_EH_FRAME
    अगर (s->output_format != TCC_OUTPUT_FORMAT_ELF)
        s->unwind_tables = 0;
    tcc_eh_frame_start(s);
#पूर्ण_अगर

#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        /* (make ro after relocation done with GNU_RELRO) */
        bounds_section = new_section(s, ".bounds", SHT_PROGBITS, shf_RELRO);
        lbounds_section = new_section(s, ".lbounds", SHT_PROGBITS, shf_RELRO);
    }
#पूर्ण_अगर

#अगर_घोषित TCC_TARGET_PE
    /* to make sure that -ltcc1 -Wl,-e,_start will grab the startup code
       from libtcc1.a (unless _start defined) */
    अगर (s->elf_entryname)
        set_global_sym(s, s->elf_entryname, शून्य, 0); /* SHN_UNDEF */
#पूर्ण_अगर

#अगर_अघोषित ELF_OBJ_ONLY
    अगर (शून्य == s->elfint && s1->output_type != TCC_OUTPUT_OBJ) {
        स्थिर अक्षर *p = CONFIG_TCC_ELFINTERP;
#अगर defined TCC_TARGET_ARM && defined CONFIG_TCC_ELFINTERP_ARMHF
        अगर (s->float_abi == ARM_HARD_FLOAT)
            p = CONFIG_TCC_ELFINTERP_ARMHF;
#पूर्ण_अगर
#अगर defined TCC_IS_NATIVE && defined TARGETOS_BSD
        /* see commit 55cb2170cd5ce77a7d76dcaf462fad2707281605 */
        { स्थिर अक्षर *e = दो_पर्या("LD_SO"); अगर (e) p = e; }
#पूर्ण_अगर
        s->elfint = tcc_strdup(p);
    }
#पूर्ण_अगर /* ndef ELF_OBJ_ONLY */
}

ST_FUNC व्योम free_section(Section *s)
{
    अगर (!s)
        वापस;
    tcc_free(s->तथ्य);
    s->तथ्य = शून्य;
    s->तथ्य_allocated = s->तथ्य_offset = 0;
}

ST_FUNC व्योम tccelf_delete(TCCState *s1)
{
    पूर्णांक i;

#अगर_अघोषित ELF_OBJ_ONLY
    /* free symbol versions */
    क्रम (i = 0; i < nb_sym_versions; i++) {
        tcc_free(sym_versions[i].version);
        tcc_free(sym_versions[i].lib);
    }
    tcc_free(sym_versions);
    tcc_free(sym_to_version);
#पूर्ण_अगर

    /* free all sections */
    क्रम(i = 1; i < s1->nb_sections; i++)
        free_section(s1->sections[i]);
    dynarray_reset(&s1->sections, &s1->nb_sections);

    क्रम(i = 0; i < s1->nb_priv_sections; i++)
        free_section(s1->priv_sections[i]);
    dynarray_reset(&s1->priv_sections, &s1->nb_priv_sections);

    tcc_free(s1->sym_attrs);
    symtab_section = शून्य; /* for tccrun.c:rt_printline() */
}

/* save section data state */
ST_FUNC व्योम tccelf_begin_file(TCCState *s1)
{
    Section *s; पूर्णांक i;
    क्रम (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        s->sh_offset = s->तथ्य_offset;
    }
    /* disable symbol hashing during compilation */
    s = s1->symtab, s->reloc = s->hash, s->hash = शून्य;
#अगर defined TCC_TARGET_X86_64 && defined TCC_TARGET_PE
    s1->uw_sym = 0;
    s1->uw_offs = 0;
#पूर्ण_अगर
}

अटल व्योम update_relocs(TCCState *s1, Section *s, पूर्णांक *old_to_new_syms, पूर्णांक first_sym);

/* At the end of compilation, convert any UNDEF syms to global, and merge
   with previously existing symbols */
ST_FUNC व्योम tccelf_end_file(TCCState *s1)
{
    Section *s = s1->symtab;
    पूर्णांक first_sym, nb_syms, *tr, i;

    first_sym = s->sh_offset / माप (ElfSym);
    nb_syms = s->तथ्य_offset / माप (ElfSym) - first_sym;
    s->तथ्य_offset = s->sh_offset;
    s->link->तथ्य_offset = s->link->sh_offset;
    s->hash = s->reloc, s->reloc = शून्य;
    tr = tcc_mallocz(nb_syms * माप *tr);

    क्रम (i = 0; i < nb_syms; ++i) {
        ElfSym *sym = (ElfSym*)s->तथ्य + first_sym + i;
        अगर (sym->st_shndx == SHN_UNDEF) {
            पूर्णांक sym_bind = ELFW(ST_BIND)(sym->st_info);
            पूर्णांक sym_type = ELFW(ST_TYPE)(sym->st_info);
            अगर (sym_bind == STB_LOCAL)
                sym_bind = STB_GLOBAL;
#अगर_अघोषित TCC_TARGET_PE
            अगर (sym_bind == STB_GLOBAL && s1->output_type == TCC_OUTPUT_OBJ) {
                /* undefined symbols with STT_FUNC are confusing gnu ld when
                   linking statically to STT_GNU_IFUNC.  Keep TLS typed,
                   otherwise gnu ld rejects non-TLS refs to TLS definitions. */
                अगर (sym_type != STT_TLS)
                    sym_type = STT_NOTYPE;
            }
#पूर्ण_अगर
            sym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
        }
        tr[i] = set_elf_sym(s, sym->st_मूल्य, sym->st_आकार, sym->st_info,
            sym->st_other, sym->st_shndx, (अक्षर*)s->link->तथ्य + sym->st_name);
    }
    /* now update relocations */
    update_relocs(s1, s, tr, first_sym);
    tcc_free(tr);
    /* record text/data/bss output for -bench info */
    क्रम (i = 0; i < 4; ++i) {
        s = s1->sections[i + 1];
        s1->योग_output[i] += s->तथ्य_offset - s->sh_offset;
    }
}

ST_FUNC Section *new_section(TCCState *s1, स्थिर अक्षर *name, पूर्णांक sh_type, पूर्णांक sh_flags)
{
    Section *sec;

    sec = tcc_mallocz(माप(Section) + म_माप(name));
    sec->s1 = s1;
    म_नकल(sec->name, name);
    sec->sh_type = sh_type;
    sec->sh_flags = sh_flags;
    चयन(sh_type) {
    हाल SHT_GNU_versym:
        sec->sh_addralign = 2;
        अवरोध;
    हाल SHT_HASH:
    हाल SHT_GNU_HASH:
    हाल SHT_REL:
    हाल SHT_RELA:
    हाल SHT_DYNSYM:
    हाल SHT_SYMTAB:
    हाल SHT_DYNAMIC:
    हाल SHT_GNU_verneed:
    हाल SHT_GNU_verdef:
        sec->sh_addralign = PTR_आकार;
        अवरोध;
    हाल SHT_STRTAB:
        sec->sh_addralign = 1;
        अवरोध;
    शेष:
        sec->sh_addralign =  PTR_आकार; /* gcc/pcc default alignment */
        अवरोध;
    }

    अगर (sh_flags & SHF_PRIVATE) {
        dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } अन्यथा {
        sec->sh_अंक = s1->nb_sections;
        dynarray_add(&s1->sections, &s1->nb_sections, sec);
    }

    वापस sec;
}

ST_FUNC व्योम init_symtab(Section *s)
{
    पूर्णांक *ptr, nb_buckets = 1;
    put_elf_str(s->link, "");
    section_ptr_add(s, माप (ElfW(Sym)));
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + 1) * माप(पूर्णांक));
    ptr[0] = nb_buckets;
    ptr[1] = 1;
    स_रखो(ptr + 2, 0, (nb_buckets + 1) * माप(पूर्णांक));
}

ST_FUNC Section *new_symtab(TCCState *s1,
                           स्थिर अक्षर *symtab_name, पूर्णांक sh_type, पूर्णांक sh_flags,
                           स्थिर अक्षर *strtab_name,
                           स्थिर अक्षर *hash_name, पूर्णांक hash_sh_flags)
{
    Section *symtab, *strtab, *hash;
    symtab = new_section(s1, symtab_name, sh_type, sh_flags);
    symtab->sh_entsize = माप(ElfW(Sym));
    strtab = new_section(s1, strtab_name, SHT_STRTAB, sh_flags);
    symtab->link = strtab;
    hash = new_section(s1, hash_name, SHT_HASH, hash_sh_flags);
    hash->sh_entsize = माप(पूर्णांक);
    symtab->hash = hash;
    hash->link = symtab;
    init_symtab(symtab);
    वापस symtab;
}

/* realloc section and set its content to zero */
ST_FUNC व्योम section_realloc(Section *sec, अचिन्हित दीर्घ new_आकार)
{
    अचिन्हित दीर्घ आकार;
    अचिन्हित अक्षर *तथ्य;

    आकार = sec->तथ्य_allocated;
    अगर (आकार == 0)
        आकार = 1;
    जबतक (आकार < new_आकार)
        आकार = आकार * 2;
    तथ्य = tcc_realloc(sec->तथ्य, आकार);
    स_रखो(तथ्य + sec->तथ्य_allocated, 0, आकार - sec->तथ्य_allocated);
    sec->तथ्य = तथ्य;
    sec->तथ्य_allocated = आकार;
}

/* reserve at least 'size' bytes aligned per 'align' in section
   'sec' from current offset, and return the aligned offset */
ST_FUNC माप_प्रकार section_add(Section *sec, addr_t आकार, पूर्णांक align)
{
    माप_प्रकार offset, offset1;

    offset = (sec->तथ्य_offset + align - 1) & -align;
    offset1 = offset + आकार;
    अगर (sec->sh_type != SHT_NOBITS && offset1 > sec->तथ्य_allocated)
        section_realloc(sec, offset1);
    sec->तथ्य_offset = offset1;
    अगर (align > sec->sh_addralign)
        sec->sh_addralign = align;
    वापस offset;
}

/* reserve at least 'size' bytes in section 'sec' from
   sec->data_offset. */
ST_FUNC व्योम *section_ptr_add(Section *sec, addr_t आकार)
{
    माप_प्रकार offset = section_add(sec, आकार, 1);
    वापस sec->तथ्य + offset;
}

#अगर_अघोषित ELF_OBJ_ONLY
/* reserve at least 'size' bytes from section start */
अटल व्योम section_reserve(Section *sec, अचिन्हित दीर्घ आकार)
{
    अगर (आकार > sec->तथ्य_allocated)
        section_realloc(sec, आकार);
    अगर (आकार > sec->तथ्य_offset)
        sec->तथ्य_offset = आकार;
}
#पूर्ण_अगर

अटल Section *have_section(TCCState *s1, स्थिर अक्षर *name)
{
    Section *sec;
    पूर्णांक i;
    क्रम(i = 1; i < s1->nb_sections; i++) {
        sec = s1->sections[i];
        अगर (!म_भेद(name, sec->name))
            वापस sec;
    }
    वापस शून्य;
}

/* return a reference to a section, and create it if it does not
   exists */
ST_FUNC Section *find_section(TCCState *s1, स्थिर अक्षर *name)
{
    Section *sec = have_section(s1, name);
    अगर (sec)
        वापस sec;
    /* sections are created as PROGBITS */
    वापस new_section(s1, name, SHT_PROGBITS, SHF_ALLOC);
}

/* ------------------------------------------------------------------------- */

ST_FUNC पूर्णांक put_elf_str(Section *s, स्थिर अक्षर *sym)
{
    पूर्णांक offset, len;
    अक्षर *ptr;

    len = म_माप(sym) + 1;
    offset = s->तथ्य_offset;
    ptr = section_ptr_add(s, len);
    स_हटाओ(ptr, sym, len);
    वापस offset;
}

/* elf symbol hashing function */
अटल ElfW(Word) elf_hash(स्थिर अचिन्हित अक्षर *name)
{
    ElfW(Word) h = 0, g;

    जबतक (*name) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        अगर (g)
            h ^= g >> 24;
        h &= ~g;
    }
    वापस h;
}

/* rebuild hash table of section s */
/* NOTE: we do factorize the hash table code to go faster */
अटल व्योम rebuild_hash(Section *s, अचिन्हित पूर्णांक nb_buckets)
{
    ElfW(Sym) *sym;
    पूर्णांक *ptr, *hash, nb_syms, sym_सूचकांक, h;
    अचिन्हित अक्षर *strtab;

    strtab = s->link->तथ्य;
    nb_syms = s->तथ्य_offset / माप(ElfW(Sym));

    अगर (!nb_buckets)
        nb_buckets = ((पूर्णांक*)s->hash->तथ्य)[0];

    s->hash->तथ्य_offset = 0;
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + nb_syms) * माप(पूर्णांक));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    स_रखो(hash, 0, (nb_buckets + 1) * माप(पूर्णांक));
    ptr += nb_buckets + 1;

    sym = (ElfW(Sym) *)s->तथ्य + 1;
    क्रम(sym_सूचकांक = 1; sym_सूचकांक < nb_syms; sym_सूचकांक++) {
        अगर (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
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
ST_FUNC पूर्णांक put_elf_sym(Section *s, addr_t मूल्य, अचिन्हित दीर्घ आकार,
    पूर्णांक info, पूर्णांक other, पूर्णांक shndx, स्थिर अक्षर *name)
{
    पूर्णांक name_offset, sym_सूचकांक;
    पूर्णांक nbuckets, h;
    ElfW(Sym) *sym;
    Section *hs;

    sym = section_ptr_add(s, माप(ElfW(Sym)));
    अगर (name && name[0])
        name_offset = put_elf_str(s->link, name);
    अन्यथा
        name_offset = 0;
    /* XXX: endianness */
    sym->st_name = name_offset;
    sym->st_मूल्य = मूल्य;
    sym->st_आकार = आकार;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
    sym_सूचकांक = sym - (ElfW(Sym) *)s->तथ्य;
    hs = s->hash;
    अगर (hs) {
        पूर्णांक *ptr, *base;
        ptr = section_ptr_add(hs, माप(पूर्णांक));
        base = (पूर्णांक *)hs->तथ्य;
        /* only add global or weak symbols. */
        अगर (ELFW(ST_BIND)(info) != STB_LOCAL) {
            /* add another hashing entry */
            nbuckets = base[0];
            h = elf_hash((अचिन्हित अक्षर *)s->link->तथ्य + name_offset) % nbuckets;
            *ptr = base[2 + h];
            base[2 + h] = sym_सूचकांक;
            base[1]++;
            /* we resize the hash table */
            hs->nb_hashed_syms++;
            अगर (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } अन्यथा {
            *ptr = 0;
            base[1]++;
        }
    }
    वापस sym_सूचकांक;
}

ST_FUNC पूर्णांक find_elf_sym(Section *s, स्थिर अक्षर *name)
{
    ElfW(Sym) *sym;
    Section *hs;
    पूर्णांक nbuckets, sym_सूचकांक, h;
    स्थिर अक्षर *name1;

    hs = s->hash;
    अगर (!hs)
        वापस 0;
    nbuckets = ((पूर्णांक *)hs->तथ्य)[0];
    h = elf_hash((अचिन्हित अक्षर *) name) % nbuckets;
    sym_सूचकांक = ((पूर्णांक *)hs->तथ्य)[2 + h];
    जबतक (sym_सूचकांक != 0) {
        sym = &((ElfW(Sym) *)s->तथ्य)[sym_सूचकांक];
        name1 = (अक्षर *) s->link->तथ्य + sym->st_name;
        अगर (!म_भेद(name, name1))
            वापस sym_सूचकांक;
        sym_सूचकांक = ((पूर्णांक *)hs->तथ्य)[2 + nbuckets + sym_सूचकांक];
    }
    वापस 0;
}

/* return elf symbol value, signal error if 'err' is nonzero, decorate
   name if FORC */
ST_FUNC addr_t get_sym_addr(TCCState *s1, स्थिर अक्षर *name, पूर्णांक err, पूर्णांक forc)
{
    पूर्णांक sym_सूचकांक;
    ElfW(Sym) *sym;
    अक्षर buf[256];
    अगर (forc && s1->leading_underscore
#अगर_घोषित TCC_TARGET_PE
        /* win32-32bit stdcall symbols always have _ already */
        && !म_अक्षर(name, '@')
#पूर्ण_अगर
        ) {
        buf[0] = '_';
        pstrcpy(buf + 1, माप(buf) - 1, name);
        name = buf;
    }
    sym_सूचकांक = find_elf_sym(s1->symtab, name);
    sym = &((ElfW(Sym) *)s1->symtab->तथ्य)[sym_सूचकांक];
    अगर (!sym_सूचकांक || sym->st_shndx == SHN_UNDEF) {
        अगर (err)
            tcc_error_noabort("%s not defined", name);
        वापस (addr_t)-1;
    }
    वापस sym->st_मूल्य;
}

/* return elf symbol value */
LIBTCCAPI व्योम *tcc_get_प्रतीक(TCCState *s, स्थिर अक्षर *name)
{
    addr_t addr = get_sym_addr(s, name, 0, 1);
    वापस addr == -1 ? शून्य : (व्योम*)(uintptr_t)addr;
}

LIBTCCAPI पूर्णांक tcc_add_प्रतीक(TCCState *s1, स्थिर अक्षर *name, स्थिर व्योम *val)
{
#अगर_घोषित TCC_TARGET_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s1, 0, name, (uintptr_t)val);
#अन्यथा
    अक्षर buf[256];
    अगर (s1->leading_underscore) {
        buf[0] = '_';
        pstrcpy(buf + 1, माप(buf) - 1, name);
        name = buf;
    }
    set_global_sym(s1, name, शून्य, (addr_t)(uintptr_t)val); /* NULL: SHN_ABS */
#पूर्ण_अगर
    वापस 0;
}

/* list elf symbol names and values */
ST_FUNC व्योम list_elf_symbols(TCCState *s, व्योम *ctx,
    व्योम (*प्रतीक_cb)(व्योम *ctx, स्थिर अक्षर *name, स्थिर व्योम *val))
{
    ElfW(Sym) *sym;
    Section *symtab;
    पूर्णांक sym_सूचकांक, end_sym;
    स्थिर अक्षर *name;
    अचिन्हित अक्षर sym_vis, sym_bind;

    symtab = s->symtab;
    end_sym = symtab->तथ्य_offset / माप (ElfSym);
    क्रम (sym_सूचकांक = 0; sym_सूचकांक < end_sym; ++sym_सूचकांक) {
        sym = &((ElfW(Sym) *)symtab->तथ्य)[sym_सूचकांक];
        अगर (sym->st_मूल्य) {
            name = (अक्षर *) symtab->link->तथ्य + sym->st_name;
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            sym_vis = ELFW(ST_VISIBILITY)(sym->st_other);
            अगर (sym_bind == STB_GLOBAL && sym_vis == STV_DEFAULT)
                प्रतीक_cb(ctx, name, (व्योम*)(uintptr_t)sym->st_मूल्य);
        }
    }
}

/* list elf symbol names and values */
LIBTCCAPI व्योम tcc_list_symbols(TCCState *s, व्योम *ctx,
    व्योम (*प्रतीक_cb)(व्योम *ctx, स्थिर अक्षर *name, स्थिर व्योम *val))
{
    list_elf_symbols(s, ctx, प्रतीक_cb);
}

#अगर_अघोषित ELF_OBJ_ONLY
अटल व्योम
version_add (TCCState *s1)
{
    पूर्णांक i;
    ElfW(Sym) *sym;
    ElfW(Verneed) *vn = शून्य;
    Section *symtab;
    पूर्णांक sym_सूचकांक, end_sym, nb_versions = 2, nb_entries = 0;
    ElfW(Half) *versym;
    स्थिर अक्षर *name;

    अगर (0 == nb_sym_versions)
        वापस;
    versym_section = new_section(s1, ".gnu.version", SHT_GNU_versym, SHF_ALLOC);
    versym_section->sh_entsize = माप(ElfW(Half));
    versym_section->link = s1->dynsym;

    /* add needed symbols */
    symtab = s1->dynsym;
    end_sym = symtab->तथ्य_offset / माप (ElfSym);
    versym = section_ptr_add(versym_section, end_sym * माप(ElfW(Half)));
    क्रम (sym_सूचकांक = 1; sym_सूचकांक < end_sym; ++sym_सूचकांक) {
        पूर्णांक dllindex, verndx;
        sym = &((ElfW(Sym) *)symtab->तथ्य)[sym_सूचकांक];
        name = (अक्षर *) symtab->link->तथ्य + sym->st_name;
        dllindex = find_elf_sym(s1->dynsymtab_section, name);
        verndx = (dllindex && dllindex < nb_sym_to_version)
                 ? sym_to_version[dllindex] : -1;
        अगर (verndx >= 0
            /* XXX: on android, clang refuses to link with a libtcc.so made by tcc
               when defined symbols have a version > 1 or when the version is '0'.
               Whereas version '1' for example for 'signal' in an exe defeats
               bcheck's signal_redir. */
            && (sym->st_shndx == SHN_UNDEF || (s1->output_type & TCC_OUTPUT_EXE))
            ) {
            अगर (!sym_versions[verndx].out_सूचकांक)
              sym_versions[verndx].out_सूचकांक = nb_versions++;
            versym[sym_सूचकांक] = sym_versions[verndx].out_सूचकांक;
        } अन्यथा {
            versym[sym_सूचकांक] = 1; /* (*global*) */
        }
        //printf("SYM %d %s\n", versym[sym_index], name);
    }
    /* generate verneed section, but not when it will be empty.  Some
       dynamic linkers look at their contents even when DTVERNEEDNUM and
       section size is zero.  */
    अगर (nb_versions > 2) {
        verneed_section = new_section(s1, ".gnu.version_r",
                                      SHT_GNU_verneed, SHF_ALLOC);
        verneed_section->link = s1->dynsym->link;
        क्रम (i = nb_sym_versions; i-- > 0;) {
            काष्ठा sym_version *sv = &sym_versions[i];
            पूर्णांक n_same_libs = 0, पूर्व;
            माप_प्रकार vnofs;
            ElfW(Vernaux) *vna = 0;
            अगर (sv->out_सूचकांक < 1)
              जारी;

            /* make sure that a DT_NEEDED tag is put */
            /* abitest-tcc fails on older i386-linux with "ld-linux.so.2" DT_NEEDED
               ret_int_test... Inconsistency detected by ld.so: dl-minimal.c: 148:
               realloc: Assertion `ptr == alloc_last_block' failed! */
            अगर (म_भेद(sv->lib, "ld-linux.so.2"))
                tcc_add_dllref(s1, sv->lib, 0);

            vnofs = section_add(verneed_section, माप(*vn), 1);
            vn = (ElfW(Verneed)*)(verneed_section->तथ्य + vnofs);
            vn->vn_version = 1;
            vn->vn_file = put_elf_str(verneed_section->link, sv->lib);
            vn->vn_aux = माप (*vn);
            करो {
                पूर्व = sv->पूर्व_same_lib;
                अगर (sv->out_सूचकांक > 0) {
                    vna = section_ptr_add(verneed_section, माप(*vna));
                    vna->vna_hash = elf_hash ((स्थिर अचिन्हित अक्षर *)sv->version);
                    vna->vna_flags = 0;
                    vna->vna_other = sv->out_सूचकांक;
                    sv->out_सूचकांक = -2;
                    vna->vna_name = put_elf_str(verneed_section->link, sv->version);
                    vna->vna_अग्र = माप (*vna);
                    //printf("LIB %d %s %s\n", vna->vna_other, sv->lib, verneed_section->link->data + vna->vna_name);
                    n_same_libs++;
                }
                अगर (पूर्व >= 0)
                  sv = &sym_versions[पूर्व];
            } जबतक(पूर्व >= 0);
            vna->vna_अग्र = 0;
            vn = (ElfW(Verneed)*)(verneed_section->तथ्य + vnofs);
            vn->vn_cnt = n_same_libs;
            vn->vn_अग्र = माप(*vn) + n_same_libs * माप(*vna);
            nb_entries++;
        }
        अगर (vn)
          vn->vn_अग्र = 0;
        verneed_section->sh_info = nb_entries;
    }
    dt_verneednum = nb_entries;
}
#पूर्ण_अगर /* ndef ELF_OBJ_ONLY */

/* catch .tbss also */
अटल पूर्णांक IS_BSS(TCCState *s1, पूर्णांक ndx)
{
    वापस ndx == SHN_COMMON
     || (ndx < s1->nb_sections
         && s1->sections[ndx]->sh_type == SHT_NOBITS);
}

/* add an elf symbol : check if it is already defined and patch
   it. Return symbol index. NOTE that sh_num can be SHN_UNDEF. */
ST_FUNC पूर्णांक set_elf_sym(Section *s, addr_t मूल्य, अचिन्हित दीर्घ आकार,
                       पूर्णांक info, पूर्णांक other, पूर्णांक shndx, स्थिर अक्षर *name)
{
    TCCState *s1 = s->s1;
    ElfW(Sym) *esym;
    पूर्णांक sym_bind, sym_सूचकांक, sym_type, esym_bind;
    अचिन्हित अक्षर sym_vis, esym_vis, new_vis;

    sym_bind = ELFW(ST_BIND)(info);
    sym_type = ELFW(ST_TYPE)(info);
    sym_vis = ELFW(ST_VISIBILITY)(other);

    अगर (sym_bind != STB_LOCAL) {
        /* we search global or weak symbols */
        sym_सूचकांक = find_elf_sym(s, name);
        अगर (!sym_सूचकांक)
            जाओ do_def;
        esym = &((ElfW(Sym) *)s->तथ्य)[sym_सूचकांक];
        अगर (esym->st_मूल्य == मूल्य && esym->st_आकार == आकार && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            वापस sym_सूचकांक;
        अगर (esym->st_shndx != SHN_UNDEF) {
            esym_bind = ELFW(ST_BIND)(esym->st_info);
            /* propagate the most constraining visibility */
            /* STV_DEFAULT(0)<STV_PROTECTED(3)<STV_HIDDEN(2)<STV_INTERNAL(1) */
            esym_vis = ELFW(ST_VISIBILITY)(esym->st_other);
            अगर (esym_vis == STV_DEFAULT) {
                new_vis = sym_vis;
            } अन्यथा अगर (sym_vis == STV_DEFAULT) {
                new_vis = esym_vis;
            } अन्यथा {
                new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
            }
            esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
                             | new_vis;
            अगर (shndx == SHN_UNDEF) {
                /* ignore adding of undefined symbol if the
                   corresponding symbol is already defined */
            } अन्यथा अगर (sym_bind == STB_GLOBAL && esym_bind == STB_WEAK) {
                /* global overrides weak, so patch */
                जाओ do_patch;
            } अन्यथा अगर (sym_bind == STB_WEAK && esym_bind == STB_GLOBAL) {
                /* weak is ignored if already global */
            } अन्यथा अगर (sym_bind == STB_WEAK && esym_bind == STB_WEAK) {
                /* keep first-found weak definition, ignore subsequents */
            } अन्यथा अगर (sym_vis == STV_HIDDEN || sym_vis == STV_INTERNAL) {
                /* ignore hidden symbols after */
            } अन्यथा अगर (s->sh_flags & SHF_DYNSYM) {
                /* we accept that two DLL define the same symbol */
            } अन्यथा अगर (!IS_BSS(s1, shndx) && IS_BSS(s1, esym->st_shndx)) {
                /* data symbol gets precedence over common/bss */
                जाओ do_patch;
            } अन्यथा अगर (IS_BSS(s1, shndx)) {
                /* data symbol keeps precedence over common/bss */
	    } अन्यथा अगर (esym->st_other & ST_ASM_SET) {
		/* If the existing symbol came from an asm .set
		   we can override.  */
		जाओ do_patch;
            } अन्यथा {
#अगर 0
                म_लिखो("new_bind=%x new_shndx=%x new_vis=%x old_bind=%x old_shndx=%x old_vis=%x\n",
                       sym_bind, shndx, new_vis, esym_bind, esym->st_shndx, esym_vis);
#पूर्ण_अगर
                tcc_error_noabort("link symbol '%s' defined twice", name);
            }
        } अन्यथा {
            esym->st_other = other;
        do_patch:
            esym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
            esym->st_shndx = shndx;
            esym->st_मूल्य = मूल्य;
            esym->st_आकार = आकार;
        }
    } अन्यथा {
    do_def:
        sym_सूचकांक = put_elf_sym(s, मूल्य, आकार,
                                ELFW(ST_INFO)(sym_bind, sym_type), other,
                                shndx, name);
    }
    वापस sym_सूचकांक;
}

/* put relocation */
ST_FUNC व्योम put_elf_reloca(Section *symtab, Section *s, अचिन्हित दीर्घ offset,
                            पूर्णांक type, पूर्णांक प्रतीक, addr_t addend)
{
    TCCState *s1 = s->s1;
    अक्षर buf[256];
    Section *sr;
    ElfW_Rel *rel;

    sr = s->reloc;
    अगर (!sr) {
        /* if no relocation section, create it */
        snprintf(buf, माप(buf), REL_SECTION_FMT, s->name);
        /* if the symtab is allocated, then we consider the relocation
           are also */
        sr = new_section(s->s1, buf, SHT_RELX, symtab->sh_flags);
        sr->sh_entsize = माप(ElfW_Rel);
        sr->link = symtab;
        sr->sh_info = s->sh_अंक;
        s->reloc = sr;
    }
    rel = section_ptr_add(sr, माप(ElfW_Rel));
    rel->r_offset = offset;
    rel->r_info = ELFW(R_INFO)(प्रतीक, type);
#अगर SHT_RELX == SHT_RELA
    rel->r_addend = addend;
#पूर्ण_अगर
    अगर (SHT_RELX != SHT_RELA && addend)
        tcc_error_noabort("non-zero addend on REL architecture");
}

ST_FUNC व्योम put_elf_reloc(Section *symtab, Section *s, अचिन्हित दीर्घ offset,
                           पूर्णांक type, पूर्णांक प्रतीक)
{
    put_elf_reloca(symtab, s, offset, type, प्रतीक, 0);
}

ST_FUNC काष्ठा sym_attr *get_sym_attr(TCCState *s1, पूर्णांक सूचकांक, पूर्णांक alloc)
{
    पूर्णांक n;
    काष्ठा sym_attr *tab;

    अगर (सूचकांक >= s1->nb_sym_attrs) {
        अगर (!alloc)
            वापस s1->sym_attrs;
        /* find immediately bigger power of 2 and reallocate array */
        n = 1;
        जबतक (सूचकांक >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * माप(*s1->sym_attrs));
        s1->sym_attrs = tab;
        स_रखो(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * माप(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    वापस &s1->sym_attrs[सूचकांक];
}

अटल व्योम update_relocs(TCCState *s1, Section *s, पूर्णांक *old_to_new_syms, पूर्णांक first_sym)
{
    पूर्णांक i, type, sym_सूचकांक;
    Section *sr;
    ElfW_Rel *rel;

    क्रम(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        अगर (sr->sh_type == SHT_RELX && sr->link == s) {
            for_each_elem(sr, 0, rel, ElfW_Rel) {
                sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
                type = ELFW(R_TYPE)(rel->r_info);
                अगर ((sym_सूचकांक -= first_sym) < 0)
                    जारी; /* zero sym_index in reloc (can happen with asm) */
                sym_सूचकांक = old_to_new_syms[sym_सूचकांक];
                rel->r_info = ELFW(R_INFO)(sym_सूचकांक, type);
            }
        }
    }
}

/* In an ELF file symbol table, the local symbols must appear below
   the global and weak ones. Since TCC cannot sort it while generating
   the code, we must do it after. All the relocation tables are also
   modified to take into account the symbol table sorting */
अटल व्योम sort_syms(TCCState *s1, Section *s)
{
    पूर्णांक *old_to_new_syms;
    ElfW(Sym) *new_syms;
    पूर्णांक nb_syms, i;
    ElfW(Sym) *p, *q;

    nb_syms = s->तथ्य_offset / माप(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * माप(ElfW(Sym)));
    old_to_new_syms = tcc_malloc(nb_syms * माप(पूर्णांक));

    /* first pass for local symbols */
    p = (ElfW(Sym) *)s->तथ्य;
    q = new_syms;
    क्रम(i = 0; i < nb_syms; i++) {
        अगर (ELFW(ST_BIND)(p->st_info) == STB_LOCAL) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    /* save the number of local symbols in section header */
    अगर( s->sh_आकार )    /* this 'if' makes IDA happy */
        s->sh_info = q - new_syms;

    /* then second pass for non local symbols */
    p = (ElfW(Sym) *)s->तथ्य;
    क्रम(i = 0; i < nb_syms; i++) {
        अगर (ELFW(ST_BIND)(p->st_info) != STB_LOCAL) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }

    /* we copy the new symbols to the old */
    स_नकल(s->तथ्य, new_syms, nb_syms * माप(ElfW(Sym)));
    tcc_free(new_syms);

    update_relocs(s1, s, old_to_new_syms, 0);
    tcc_free(old_to_new_syms);
}

#अगर_अघोषित ELF_OBJ_ONLY
/* See: https://flapenguin.me/elf-dt-gnu-hash */
#घोषणा	ELFCLASS_BITS (PTR_आकार * 8)

अटल Section *create_gnu_hash(TCCState *s1)
{
    पूर्णांक nb_syms, i, ndef, nbuckets, symoffset, bloom_आकार, bloom_shift;
    ElfW(Sym) *p;
    Section *gnu_hash;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr;

    gnu_hash = new_section(s1, ".gnu.hash", SHT_GNU_HASH, SHF_ALLOC);
    gnu_hash->link = dynsym->hash->link;

    nb_syms = dynsym->तथ्य_offset / माप(ElfW(Sym));

    /* count def symbols */
    ndef = 0;
    p = (ElfW(Sym) *)dynsym->तथ्य;
    क्रम(i = 0; i < nb_syms; i++, p++)
        ndef += p->st_shndx != SHN_UNDEF;

    /* calculate gnu hash sizes and fill header */
    nbuckets = ndef / 4 + 1;
    symoffset = nb_syms - ndef;
    bloom_shift = PTR_आकार == 8 ? 6 : 5;
    bloom_आकार = 1; /* must be power of two */
    जबतक (ndef >= bloom_आकार * (1 << (bloom_shift - 3)))
	bloom_आकार *= 2;
    ptr = section_ptr_add(gnu_hash, 4 * 4 +
				    PTR_आकार * bloom_आकार +
				    nbuckets * 4 +
				    ndef * 4);
    ptr[0] = nbuckets;
    ptr[1] = symoffset;
    ptr[2] = bloom_आकार;
    ptr[3] = bloom_shift;
    वापस gnu_hash;
}

अटल Elf32_Word elf_gnu_hash (स्थिर अचिन्हित अक्षर *name)
{
    Elf32_Word h = 5381;
    अचिन्हित अक्षर c;

    जबतक ((c = *name++))
        h = h * 33 + c;
    वापस h;
}

अटल व्योम update_gnu_hash(TCCState *s1, Section *gnu_hash)
{
    पूर्णांक *old_to_new_syms;
    ElfW(Sym) *new_syms;
    पूर्णांक nb_syms, i, nbuckets, bloom_आकार, bloom_shift;
    ElfW(Sym) *p, *q;
    Section *vs;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr, *buckets, *chain, *hash;
    अचिन्हित पूर्णांक *nextbuck;
    addr_t *bloom;
    अचिन्हित अक्षर *strtab;
    काष्ठा { पूर्णांक first, last; } *buck;

    strtab = dynsym->link->तथ्य;
    nb_syms = dynsym->तथ्य_offset / माप(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * माप(ElfW(Sym)));
    old_to_new_syms = tcc_malloc(nb_syms * माप(पूर्णांक));
    hash = tcc_malloc(nb_syms * माप(Elf32_Word));
    nextbuck = tcc_malloc(nb_syms * माप(पूर्णांक));

    /* calculate hashes and copy undefs */
    p = (ElfW(Sym) *)dynsym->तथ्य;
    q = new_syms;
    क्रम(i = 0; i < nb_syms; i++, p++) {
        अगर (p->st_shndx == SHN_UNDEF) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
	अन्यथा
	    hash[i] = elf_gnu_hash(strtab + p->st_name);
    }

    ptr = (Elf32_Word *) gnu_hash->तथ्य;
    nbuckets = ptr[0];
    bloom_आकार = ptr[2];
    bloom_shift = ptr[3];
    bloom = (addr_t *) (व्योम *) &ptr[4];
    buckets = (Elf32_Word*) (व्योम *) &bloom[bloom_आकार];
    chain = &buckets[nbuckets];
    buck = tcc_malloc(nbuckets * माप(*buck));

    अगर (gnu_hash->तथ्य_offset != 4 * 4 +
				 PTR_आकार * bloom_आकार +
				 nbuckets * 4 +
				 (nb_syms - (q - new_syms)) * 4)
	tcc_error_noabort ("gnu_hash size incorrect");

    /* find buckets */
    क्रम(i = 0; i < nbuckets; i++)
	buck[i].first = -1;

    p = (ElfW(Sym) *)dynsym->तथ्य;
    क्रम(i = 0; i < nb_syms; i++, p++)
        अगर (p->st_shndx != SHN_UNDEF) {
	    पूर्णांक bucket = hash[i] % nbuckets;

	    अगर (buck[bucket].first == -1)
		buck[bucket].first = buck[bucket].last = i;
	    अन्यथा {
		nextbuck[buck[bucket].last] = i;
		buck[bucket].last = i;
	    }
	}

    /* fill buckets/chains/bloom and sort symbols */
    p = (ElfW(Sym) *)dynsym->तथ्य;
    क्रम(i = 0; i < nbuckets; i++) {
	पूर्णांक cur = buck[i].first;

	अगर (cur != -1) {
	    buckets[i] = q - new_syms;
	    क्रम (;;) {
                old_to_new_syms[cur] = q - new_syms;
                *q++ = p[cur];
	        *chain++ = hash[cur] & ~1;
		bloom[(hash[cur] / ELFCLASS_BITS) % bloom_आकार] |=
		    (addr_t)1 << (hash[cur] % ELFCLASS_BITS) |
		    (addr_t)1 << ((hash[cur] >> bloom_shift) % ELFCLASS_BITS);
		अगर (cur == buck[i].last)
		    अवरोध;
		cur = nextbuck[cur];
	    }
	    chain[-1] |= 1;
	}
    }

    स_नकल(dynsym->तथ्य, new_syms, nb_syms * माप(ElfW(Sym)));
    tcc_free(new_syms);
    tcc_free(hash);
    tcc_free(buck);
    tcc_free(nextbuck);

    update_relocs(s1, dynsym, old_to_new_syms, 0);

    /* modify the versions */
    vs = versym_section;
    अगर (vs) {
	ElfW(Half) *newver, *versym = (ElfW(Half) *)vs->तथ्य;

	अगर (1/*versym*/) {
            newver = tcc_malloc(nb_syms * माप(*newver));
	    क्रम (i = 0; i < nb_syms; i++)
	        newver[old_to_new_syms[i]] = versym[i];
	    स_नकल(vs->तथ्य, newver, nb_syms * माप(*newver));
	    tcc_free(newver);
	}
    }

    tcc_free(old_to_new_syms);

    /* rebuild hash */
    ptr = (Elf32_Word *) dynsym->hash->तथ्य;
    rebuild_hash(dynsym, ptr[0]);
}
#पूर्ण_अगर /* ELF_OBJ_ONLY */

/* relocate symbol table, resolve undefined symbols if do_resolve is
   true and output error if undefined symbol. */
ST_FUNC व्योम relocate_syms(TCCState *s1, Section *symtab, पूर्णांक do_resolve)
{
    ElfW(Sym) *sym;
    पूर्णांक sym_bind, sh_अंक;
    स्थिर अक्षर *name;

    for_each_elem(symtab, 1, sym, ElfW(Sym)) {
        sh_अंक = sym->st_shndx;
        अगर (sh_अंक == SHN_UNDEF) {
            अगर (do_resolve == 2) /* relocating dynsym */
                जारी;
            name = (अक्षर *) s1->symtab->link->तथ्य + sym->st_name;
            /* Use ld.so to resolve symbol for us (for tcc -run) */
            अगर (do_resolve) {
#अगर defined TCC_IS_NATIVE && !defined TCC_TARGET_PE
                /* dlsym() needs the undecorated name.  */
                स्थिर अक्षर *name_ud = &name[s1->leading_underscore];
                व्योम *addr = शून्य;
                अगर (!s1->nostdlib)
                    addr = dlsym(RTLD_DEFAULT, name_ud);
		अगर (addr == शून्य) {
		    पूर्णांक i;
		    क्रम (i = 0; i < s1->nb_loaded_dlls; i++)
                        अगर ((addr = dlsym(s1->loaded_dlls[i]->handle, name_ud)))
			    अवरोध;
		}
                अगर (addr) {
                    sym->st_मूल्य = (addr_t) addr;
#अगर_घोषित DEBUG_RELOC
		    म_लिखो ("relocate_sym: %s -> 0x%lx\n", name, sym->st_मूल्य);
#पूर्ण_अगर
                    जाओ found;
                }
#पूर्ण_अगर
            /* if dynamic symbol exist, it will be used in relocate_section */
            } अन्यथा अगर (s1->dynsym && find_elf_sym(s1->dynsym, name))
                जाओ found;
            /* XXX: _fp_hw seems to be part of the ABI, so we ignore
               it */
            अगर (!म_भेद(name, "_fp_hw"))
                जाओ found;
            /* only weak symbols are accepted to be undefined. Their
               value is zero */
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            अगर (sym_bind == STB_WEAK)
                sym->st_मूल्य = 0;
            अन्यथा
                tcc_error_noabort("unresolved reference to '%s'", name);

        } अन्यथा अगर (sh_अंक < SHN_LORESERVE) {
            /* add section base */
            sym->st_मूल्य += s1->sections[sym->st_shndx]->sh_addr;
        }
    found: ;
    }
}

/* relocate a given section (CPU dependent) by applying the relocations
   in the associated relocation section */
अटल व्योम relocate_section(TCCState *s1, Section *s, Section *sr)
{
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    पूर्णांक type, sym_सूचकांक;
    अचिन्हित अक्षर *ptr;
    addr_t tgt, addr;
    पूर्णांक is_dwarf = s->sh_अंक >= s1->dwlo && s->sh_अंक < s1->dwhi;

    qrel = (ElfW_Rel *)sr->तथ्य;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
	अगर (s->तथ्य == शून्य) /* bss */
	    जारी;
        ptr = s->तथ्य + rel->r_offset;
        sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
        sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
        type = ELFW(R_TYPE)(rel->r_info);
        tgt = sym->st_मूल्य;
#अगर SHT_RELX == SHT_RELA
        tgt += rel->r_addend;
#पूर्ण_अगर
        अगर (is_dwarf && type == R_तथ्य_32_DW
            && sym->st_shndx >= s1->dwlo && sym->st_shndx < s1->dwhi) {
            /* dwarf section relocation to each other */
            add32le(ptr, tgt - s1->sections[sym->st_shndx]->sh_addr);
            जारी;
        }
        addr = s->sh_addr + rel->r_offset;
        relocate(s1, rel, type, ptr, addr, tgt);
    }

#अगर_अघोषित ELF_OBJ_ONLY
    /* if the relocation is allocated, we change its symbol table */
    अगर (sr->sh_flags & SHF_ALLOC) {
        sr->link = s1->dynsym;
        अगर (s1->output_type & TCC_OUTPUT_DYN) {
            माप_प्रकार r = (uint8_t*)qrel - sr->तथ्य;
            अगर (माप ((Stab_Sym*)0)->n_मूल्य < PTR_आकार
                && 0 == म_भेद(s->name, ".stab"))
                r = 0; /* cannot apply 64bit relocation to 32bit value */
            sr->तथ्य_offset = sr->sh_आकार = r;
#अगर_घोषित CONFIG_TCC_PIE
            अगर (r && (s->sh_flags & SHF_EXECINSTR))
                tcc_warning("%d relocations to %s", (अचिन्हित)(r / माप *qrel), s->name);
#पूर्ण_अगर
        }
    }
#पूर्ण_अगर

#अगर_घोषित TCC_TARGET_RISCV64
    dynarray_reset(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries);
#पूर्ण_अगर
}

/* relocate all sections */
ST_FUNC व्योम relocate_sections(TCCState *s1)
{
    पूर्णांक i;
    Section *s, *sr;

    क्रम (i = 1; i < s1->nb_sections; ++i) {
        sr = s1->sections[i];
        अगर (sr->sh_type != SHT_RELX)
            जारी;
        s = s1->sections[sr->sh_info];
#अगर_अघोषित TCC_TARGET_MACHO
        अगर (s != s1->got
            || s1->static_link
            || s1->output_type == TCC_OUTPUT_MEMORY)
#पूर्ण_अगर
        {
            relocate_section(s1, s, sr);
        }
#अगर_अघोषित ELF_OBJ_ONLY
        अगर (sr->sh_flags & SHF_ALLOC) {
            ElfW_Rel *rel;
            /* relocate relocation table in 'sr' */
            for_each_elem(sr, 0, rel, ElfW_Rel)
                rel->r_offset += s->sh_addr;
        }
#पूर्ण_अगर
    }
}

#अगर_अघोषित ELF_OBJ_ONLY
/* count the number of dynamic relocations so that we can reserve
   their space */
अटल पूर्णांक prepare_dynamic_rel(TCCState *s1, Section *sr)
{
    पूर्णांक गिनती_2 = 0;
#अगर defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || \
    defined(TCC_TARGET_ARM) || defined(TCC_TARGET_ARM64) || \
    defined(TCC_TARGET_RISCV64)
    ElfW_Rel *rel;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
        पूर्णांक sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
        पूर्णांक type = ELFW(R_TYPE)(rel->r_info);
        चयन(type) {
#अगर defined(TCC_TARGET_I386)
        हाल R_386_32:
            अगर (!get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक
                && ((ElfW(Sym)*)symtab_section->तथ्य + sym_सूचकांक)->st_shndx == SHN_UNDEF) {
                /* don't fixup unresolved (weak) symbols */
                rel->r_info = ELFW(R_INFO)(sym_सूचकांक, R_386_RELATIVE);
                अवरोध;
            }
#या_अगर defined(TCC_TARGET_X86_64)
        हाल R_X86_64_32:
        हाल R_X86_64_32S:
        हाल R_X86_64_64:
#या_अगर defined(TCC_TARGET_ARM)
        हाल R_ARM_ABS32:
        हाल R_ARM_TARGET1:
#या_अगर defined(TCC_TARGET_ARM64)
        हाल R_AARCH64_ABS32:
        हाल R_AARCH64_ABS64:
#या_अगर defined(TCC_TARGET_RISCV64)
        हाल R_RISCV_32:
        हाल R_RISCV_64:
#पूर्ण_अगर
            गिनती_2++;
            अवरोध;
#अगर defined(TCC_TARGET_I386)
        हाल R_386_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    अगर (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_सूचकांक, R_386_PLT32);
	        अवरोध;
	    }
	}
#या_अगर defined(TCC_TARGET_X86_64)
        हाल R_X86_64_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    अगर (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_सूचकांक, R_X86_64_PLT32);
	        अवरोध;
	    }
	}
#या_अगर defined(TCC_TARGET_ARM64)
        हाल R_AARCH64_PREL32:
#पूर्ण_अगर
            अगर (s1->output_type != TCC_OUTPUT_DLL)
                अवरोध;
            अगर (get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक)
                गिनती_2++;
            अवरोध;
        शेष:
            अवरोध;
        }
    }
#पूर्ण_अगर
    वापस गिनती_2;
}
#पूर्ण_अगर

#अगर_घोषित NEED_BUILD_GOT
अटल पूर्णांक build_got(TCCState *s1)
{
    /* if no got, then create it */
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    s1->got->sh_entsize = 4;
    /* keep space for _DYNAMIC pointer and two dummy got entries */
    section_ptr_add(s1->got, 3 * PTR_आकार);
    वापस set_elf_sym(symtab_section, 0, 0, ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
        0, s1->got->sh_अंक, "_GLOBAL_OFFSET_TABLE_");
}

/* Create a GOT and (for function call) a PLT entry corresponding to a symbol
   in s1->symtab. When creating the dynamic symbol table entry for the GOT
   relocation, use 'size' and 'info' for the corresponding symbol metadata.
   Returns the offset of the GOT or (if any) PLT entry. */
अटल काष्ठा sym_attr * put_got_entry(TCCState *s1, पूर्णांक dyn_reloc_type,
                                       पूर्णांक sym_सूचकांक)
{
    पूर्णांक need_plt_entry;
    स्थिर अक्षर *name;
    ElfW(Sym) *sym;
    काष्ठा sym_attr *attr;
    अचिन्हित got_offset;
    अक्षर plt_name[200];
    पूर्णांक len;
    Section *s_rel;

    need_plt_entry = (dyn_reloc_type == R_JMP_SLOT);
    attr = get_sym_attr(s1, sym_सूचकांक, 1);

    /* In case a function is both called and its address taken 2 GOT entries
       are created, one for taking the address (GOT) and the other for the PLT
       entry (PLTGOT).  */
    अगर (need_plt_entry ? attr->plt_offset : attr->got_offset)
        वापस attr;

    s_rel = s1->got;
    अगर (need_plt_entry) {
        अगर (!s1->plt) {
            s1->plt = new_section(s1, ".plt", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
            s1->plt->sh_entsize = 4;
        }
        s_rel = s1->plt;
    }

    /* create the GOT entry */
    got_offset = s1->got->तथ्य_offset;
    section_ptr_add(s1->got, PTR_आकार);

    /* Create the GOT relocation that will insert the address of the object or
       function of interest in the GOT entry. This is a static relocation for
       memory output (dlsym will give us the address of symbols) and dynamic
       relocation otherwise (executable and DLLs). The relocation should be
       done lazily for GOT entry with *_JUMP_SLOT relocation type (the one
       associated to a PLT entry) but is currently done at load time for an
       unknown reason. */

    sym = &((ElfW(Sym) *) symtab_section->तथ्य)[sym_सूचकांक];
    name = (अक्षर *) symtab_section->link->तथ्य + sym->st_name;
    //printf("sym %d %s\n", need_plt_entry, name);

    अगर (s1->dynsym) {
	अगर (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
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
			  sym_सूचकांक);
	} अन्यथा {
	    अगर (0 == attr->dyn_सूचकांक)
                attr->dyn_सूचकांक = set_elf_sym(s1->dynsym, sym->st_मूल्य,
                                              sym->st_आकार, sym->st_info, 0,
                                              sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s_rel, got_offset, dyn_reloc_type,
			  attr->dyn_सूचकांक);
	}
    } अन्यथा {
        put_elf_reloc(symtab_section, s1->got, got_offset, dyn_reloc_type,
                      sym_सूचकांक);
    }

    अगर (need_plt_entry) {
        attr->plt_offset = create_plt_entry(s1, got_offset, attr);

        /* create a symbol 'sym@plt' for the PLT jump vector */
        len = म_माप(name);
        अगर (len > माप plt_name - 5)
            len = माप plt_name - 5;
        स_नकल(plt_name, name, len);
        म_नकल(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_offset, 0,
            ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0, s1->plt->sh_अंक, plt_name);
    } अन्यथा {
        attr->got_offset = got_offset;
    }

    वापस attr;
}

/* build GOT and PLT entries */
/* Two passes because R_JMP_SLOT should become first. Some targets
   (arm, arm64) do not allow mixing R_JMP_SLOT and R_GLOB_DAT. */
ST_FUNC व्योम build_got_entries(TCCState *s1, पूर्णांक got_sym)
{
    Section *s;
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    पूर्णांक i, type, gotplt_entry, reloc_type, sym_सूचकांक;
    काष्ठा sym_attr *attr;
    पूर्णांक pass = 0;
redo:
    क्रम(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        अगर (s->sh_type != SHT_RELX)
            जारी;
        /* no need to handle got relocations */
        अगर (s->link != symtab_section)
            जारी;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_entry = gotplt_entry_type(type);
            अगर (gotplt_entry == -1) {
                tcc_error_noabort ("Unknown relocation type for got: %d", type);
                जारी;
            }
            sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];

            अगर (gotplt_entry == NO_GOTPLT_ENTRY) {
                जारी;
            }

            /* Automatically create PLT/GOT [entry] if it is an undefined
	       reference (resolved at runtime), or the symbol is absolute,
	       probably created by tcc_add_symbol, and thus on 64-bit
	       targets might be too far from application code.  */
            अगर (gotplt_entry == AUTO_GOTPLT_ENTRY) {
                अगर (sym->st_shndx == SHN_UNDEF) {
                    ElfW(Sym) *esym;
		    पूर्णांक dynindex;
                    अगर (!PCRELATIVE_DLLPLT
                        && (s1->output_type & TCC_OUTPUT_DYN))
                        जारी;
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
		    अगर (s1->dynsym) {
			/* dynsym isn't set for -run :-/  */
			dynindex = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
			esym = (ElfW(Sym) *)s1->dynsym->तथ्य + dynindex;
			अगर (dynindex
			    && (ELFW(ST_TYPE)(esym->st_info) == STT_FUNC
				|| (ELFW(ST_TYPE)(esym->st_info) == STT_NOTYPE
				    && ELFW(ST_TYPE)(sym->st_info) == STT_FUNC)))
			    जाओ jmp_slot;
		    }
                } अन्यथा अगर (sym->st_shndx == SHN_ABS) {
                    अगर (sym->st_मूल्य == 0) /* from tcc_add_btstub() */
                        जारी;
#अगर_अघोषित TCC_TARGET_ARM
                    अगर (PTR_आकार != 8)
                        जारी;
#पूर्ण_अगर
                    /* from tcc_add_symbol(): on 64 bit platforms these
                       need to go through .got */
                } अन्यथा
                    जारी;
            }

#अगर_घोषित TCC_TARGET_I386
            अगर ((type == R_386_PLT32 || type == R_386_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		अगर (pass != 0)
		    जारी;
                rel->r_info = ELFW(R_INFO)(sym_सूचकांक, R_386_PC32);
                जारी;
            }
#पूर्ण_अगर
#अगर_घोषित TCC_TARGET_X86_64
            अगर ((type == R_X86_64_PLT32 || type == R_X86_64_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		अगर (pass != 0)
		    जारी;
                rel->r_info = ELFW(R_INFO)(sym_सूचकांक, R_X86_64_PC32);
                जारी;
            }
#पूर्ण_अगर
            reloc_type = code_reloc(type);
            अगर (reloc_type == -1) {
                tcc_error_noabort ("Unknown relocation type: %d", type);
                जारी;
            }

            अगर (reloc_type != 0) {
        jmp_slot:
	        अगर (pass != 0)
                    जारी;
                reloc_type = R_JMP_SLOT;
            } अन्यथा {
	        अगर (pass != 1)
                    जारी;
                reloc_type = R_GLOB_DAT;
            }

            अगर (!s1->got)
                got_sym = build_got(s1);

            अगर (gotplt_entry == BUILD_GOT_ONLY)
                जारी;

            attr = put_got_entry(s1, reloc_type, sym_सूचकांक);

            अगर (reloc_type == R_JMP_SLOT)
                rel->r_info = ELFW(R_INFO)(attr->plt_sym, type);
        }
    }
    अगर (++pass < 2)
        जाओ redo;
    /* .rel.plt refers to .got actually */
    अगर (s1->plt && s1->plt->reloc)
        s1->plt->reloc->sh_info = s1->got->sh_अंक;
    अगर (got_sym) /* set size */
        ((ElfW(Sym)*)symtab_section->तथ्य)[got_sym].st_आकार = s1->got->तथ्य_offset;
}
#पूर्ण_अगर /* def NEED_BUILD_GOT */

ST_FUNC पूर्णांक set_global_sym(TCCState *s1, स्थिर अक्षर *name, Section *sec, addr_t offs)
{
    पूर्णांक shn = sec ? sec->sh_अंक : offs || !name ? SHN_ABS : SHN_UNDEF;
    अगर (sec && offs == -1)
        offs = sec->तथ्य_offset;
    वापस set_elf_sym(symtab_section, offs, 0,
        ELFW(ST_INFO)(name ? STB_GLOBAL : STB_LOCAL, STT_NOTYPE), 0, shn, name);
}

अटल व्योम add_init_array_defines(TCCState *s1, स्थिर अक्षर *section_name)
{
    Section *s;
    addr_t end_offset;
    अक्षर buf[1024];
    s = have_section(s1, section_name);
    अगर (!s || !(s->sh_flags & SHF_ALLOC)) {
        end_offset = 0;
        s = text_section;
    } अन्यथा {
        end_offset = s->तथ्य_offset;
    }
    snprintf(buf, माप(buf), "__%s_start", section_name + 1);
    set_global_sym(s1, buf, s, 0);
    snprintf(buf, माप(buf), "__%s_end", section_name + 1);
    set_global_sym(s1, buf, s, end_offset);
}

ST_FUNC व्योम add_array (TCCState *s1, स्थिर अक्षर *sec, पूर्णांक c)
{
    Section *s;
    s = find_section(s1, sec);
    s->sh_flags = shf_RELRO;
    s->sh_type = sec[1] == 'i' ? SHT_INIT_ARRAY : SHT_FINI_ARRAY;
    put_elf_reloc (s1->symtab, s, s->तथ्य_offset, R_तथ्य_PTR, c);
    section_ptr_add(s, PTR_आकार);
}

#अगर_घोषित CONFIG_TCC_BCHECK
ST_FUNC व्योम tcc_add_bcheck(TCCState *s1)
{
    अगर (0 == s1->do_bounds_check)
        वापस;
    section_ptr_add(bounds_section, माप(addr_t));
}
#पूर्ण_अगर

/* set symbol to STB_LOCAL and resolve. The point is to not export it as
   a dynamic symbol to allow so's to have one each with a different value. */
अटल व्योम set_local_sym(TCCState *s1, स्थिर अक्षर *name, Section *s, पूर्णांक offset)
{
    पूर्णांक c = find_elf_sym(s1->symtab, name);
    अगर (c) {
        ElfW(Sym) *esym = (ElfW(Sym)*)s1->symtab->तथ्य + c;
        esym->st_info = ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE);
        esym->st_मूल्य = offset;
        esym->st_shndx = s->sh_अंक;
    }
}

/* avoid generating debug/test_coverage code for stub functions */
अटल व्योम tcc_compile_string_no_debug(TCCState *s, स्थिर अक्षर *str)
{
    पूर्णांक save_do_debug = s->do_debug;
    पूर्णांक save_test_coverage = s->test_coverage;

    s->do_debug = 0;
    s->test_coverage = 0;
    tcc_compile_string(s, str);
    s->do_debug = save_do_debug;
    s->test_coverage = save_test_coverage;
}

#अगर_घोषित CONFIG_TCC_BACKTRACE
अटल व्योम put_ptr(TCCState *s1, Section *s, पूर्णांक offs)
{
    पूर्णांक c;
    c = set_global_sym(s1, शून्य, s, offs);
    s = तथ्य_section;
    put_elf_reloc (s1->symtab, s, s->तथ्य_offset, R_तथ्य_PTR, c);
    section_ptr_add(s, PTR_आकार);
}

ST_FUNC व्योम tcc_add_btstub(TCCState *s1)
{
    Section *s;
    पूर्णांक n, o, *p;
    CString cstr;
    स्थिर अक्षर *__rt_info = &"___rt_info"[!s1->leading_underscore];

    s = तथ्य_section;
    /* Align to PTR_SIZE */
    section_add(s, 0, PTR_आकार);
    o = s->तथ्य_offset;
    /* create a struct rt_context (see tccrun.c) */
    अगर (s1->dwarf) {
        put_ptr(s1, dwarf_पंक्ति_section, 0);
        put_ptr(s1, dwarf_पंक्ति_section, -1);
	अगर (s1->dwarf >= 5)
            put_ptr(s1, dwarf_पंक्ति_str_section, 0);
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
    section_ptr_add(s, 3 * PTR_आकार);

    अगर (s1->output_type == TCC_OUTPUT_MEMORY && 0 == s1->dwarf) {
        put_ptr(s1, text_section, 0);
    } अन्यथा {
        /* prog_base : local nameless symbol with offset 0 at SHN_ABS */
        put_ptr(s1, शून्य, 0);
#अगर defined TCC_TARGET_MACHO
        /* adjust for __PAGEZERO */
        अगर (s1->dwarf == 0 && s1->output_type == TCC_OUTPUT_EXE)
            write64le(तथ्य_section->तथ्य + तथ्य_section->तथ्य_offset - PTR_आकार,
	              (uint64_t)1 << 32);
#पूर्ण_अगर
    }
    n = 3 * PTR_आकार;
#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (s1->do_bounds_check) {
        put_ptr(s1, bounds_section, 0);
        n -= PTR_आकार;
    }
#पूर्ण_अगर
    section_ptr_add(s, n);
    p = section_ptr_add(s, 2 * माप (पूर्णांक));
    p[0] = s1->rt_अंक_callers;
    p[1] = s1->dwarf;
    // if (s->data_offset - o != 10*PTR_SIZE + 2*sizeof (int)) exit(99);

    अगर (s1->output_type == TCC_OUTPUT_MEMORY) {
        set_global_sym(s1, __rt_info, s, o);
        वापस;
    }

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern void __bt_init(),__bt_exit(),__bt_init_dll();"
        "static void *__rt_info[];"
        "__attribute__((constructor)) static void __bt_init_rt(){");
#अगर_घोषित TCC_TARGET_PE
    अगर (s1->output_type == TCC_OUTPUT_DLL)
#अगर_घोषित CONFIG_TCC_BCHECK
        cstr_printf(&cstr, "__bt_init_dll(%d);", s1->do_bounds_check);
#अन्यथा
        cstr_printf(&cstr, "__bt_init_dll(0);");
#पूर्ण_अगर
#पूर्ण_अगर
    cstr_printf(&cstr, "__bt_init(__rt_info,%d);}",
        s1->output_type != TCC_OUTPUT_DLL);
    /* In case dlcose is called by application */
    cstr_printf(&cstr,
        "__attribute__((destructor)) static void __bt_exit_rt(){"
        "__bt_exit(__rt_info);}");
    tcc_compile_string_no_debug(s1, cstr.तथ्य);
    cstr_free(&cstr);
    set_local_sym(s1, __rt_info, s, o);
}
#पूर्ण_अगर /* def CONFIG_TCC_BACKTRACE */

अटल व्योम tcc_tcov_add_file(TCCState *s1, स्थिर अक्षर *filename)
{
    CString cstr;
    व्योम *ptr;
    अक्षर wd[1024];

    अगर (tcov_section == शून्य)
        वापस;
    section_ptr_add(tcov_section, 1);
    write32le (tcov_section->तथ्य, tcov_section->तथ्य_offset);

    cstr_new (&cstr);
    अगर (filename[0] == '/')
        cstr_printf (&cstr, "%s.tcov", filename);
    अन्यथा {
        getcwd (wd, माप(wd));
        cstr_printf (&cstr, "%s/%s.tcov", wd, filename);
    }
    ptr = section_ptr_add(tcov_section, cstr.आकार + 1);
    म_नकल((अक्षर *)ptr, cstr.तथ्य);
    unlink((अक्षर *)ptr);
#अगर_घोषित _WIN32
    normalize_slashes((अक्षर *)ptr);
#पूर्ण_अगर
    cstr_free (&cstr);

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern char *__tcov_data[];"
        "extern void __store_test_coverage ();"
        "__attribute__((destructor)) static void __tcov_exit() {"
        "__store_test_coverage(__tcov_data);"
        "}");
    tcc_compile_string_no_debug(s1, cstr.तथ्य);
    cstr_free(&cstr);
    set_local_sym(s1, &"___tcov_data"[!s1->leading_underscore], tcov_section, 0);
}

#अगर_घोषित TCC_TARGET_UNIX
/* add libc crt1/crti objects */
ST_FUNC व्योम tccelf_add_crtbegin(TCCState *s1)
{
#अगर TARGETOS_OpenBSD
    अगर (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crt0.o");
    अगर (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbeginS.o");
    अन्यथा
        tcc_add_crt(s1, "crtbegin.o");
#या_अगर TARGETOS_FreeBSD || TARGETOS_NetBSD
    अगर (s1->output_type != TCC_OUTPUT_DLL)
#अगर TARGETOS_FreeBSD
        tcc_add_crt(s1, "crt1.o");
#अन्यथा
        tcc_add_crt(s1, "crt0.o");
#पूर्ण_अगर
    tcc_add_crt(s1, "crti.o");
    अगर (s1->static_link)
        tcc_add_crt(s1, "crtbeginT.o");
    अन्यथा अगर (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbeginS.o");
    अन्यथा
        tcc_add_crt(s1, "crtbegin.o");
#या_अगर TARGETOS_ANDROID
    अगर (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbegin_so.o");
    अन्यथा
        tcc_add_crt(s1, "crtbegin_dynamic.o");
#अन्यथा
    अगर (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crt1.o");
    tcc_add_crt(s1, "crti.o");
#पूर्ण_अगर
}

ST_FUNC व्योम tccelf_add_crtend(TCCState *s1)
{
#अगर TARGETOS_OpenBSD
    अगर (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtendS.o");
    अन्यथा
        tcc_add_crt(s1, "crtend.o");
#या_अगर TARGETOS_FreeBSD || TARGETOS_NetBSD
    अगर (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtendS.o");
    अन्यथा
        tcc_add_crt(s1, "crtend.o");
    tcc_add_crt(s1, "crtn.o");
#या_अगर TARGETOS_ANDROID
    अगर (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtend_so.o");
    अन्यथा
        tcc_add_crt(s1, "crtend_android.o");
#अन्यथा
    tcc_add_crt(s1, "crtn.o");
#पूर्ण_अगर
}
#पूर्ण_अगर /* TCC_TARGET_UNIX */

#अगर_अघोषित TCC_TARGET_PE
/* add tcc runtime libraries */
ST_FUNC व्योम tcc_add_runtime(TCCState *s1)
{
    s1->filetype = 0;

#अगर_घोषित CONFIG_TCC_BCHECK
    tcc_add_bcheck(s1);
#पूर्ण_अगर
    tcc_add_pragma_libs(s1);

    /* add libc */
    अगर (!s1->nostdlib) {
        पूर्णांक lpthread = s1->option_pthread;

#अगर_घोषित CONFIG_TCC_BCHECK
        अगर (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    अगर (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    अन्यथा
                tcc_add_support(s1, "bcheck.o");
# अगर !(TARGETOS_OpenBSD || TARGETOS_NetBSD)
            tcc_add_library(s1, "dl");
# endif
            lpthread = 1;
        }
#पूर्ण_अगर
#अगर_घोषित CONFIG_TCC_BACKTRACE
        अगर (s1->do_backtrace) {
            अगर (s1->output_type & TCC_OUTPUT_EXE)
                tcc_add_support(s1, "bt-exe.o");
            अगर (s1->output_type != TCC_OUTPUT_DLL)
                tcc_add_support(s1, "bt-log.o");
            tcc_add_btstub(s1);
            lpthread = 1;
        }
#पूर्ण_अगर
        अगर (lpthread)
            tcc_add_library(s1, "pthread");
        tcc_add_library(s1, "c");
#अगर_घोषित TCC_LIBGCC
        अगर (!s1->static_link) {
            अगर (TCC_LIBGCC[0] == '/')
                tcc_add_file(s1, TCC_LIBGCC);
            अन्यथा
                tcc_add_dll(s1, TCC_LIBGCC, AFF_PRINT_ERROR);
        }
#पूर्ण_अगर
#अगर defined TCC_TARGET_ARM && TARGETOS_FreeBSD
        tcc_add_library(s1, "gcc_s"); // unwind code
#पूर्ण_अगर
        अगर (TCC_LIBTCC1[0]) {
            tcc_add_support(s1, TCC_LIBTCC1);
            tcc_add_library(s1, "c");
        }
#अगर_अघोषित TCC_TARGET_MACHO
        अगर (s1->output_type != TCC_OUTPUT_MEMORY)
            tccelf_add_crtend(s1);
#पूर्ण_अगर
    }
}
#पूर्ण_अगर /* ndef TCC_TARGET_PE */

/* set _etext/_edata/_end  f=0:set  f=1:when_needed  f=2,3:just_update */
अटल व्योम set_linker_sym(TCCState *s1, स्थिर अक्षर *name, Section *sec, पूर्णांक f)
{
    पूर्णांक sym_सूचकांक, esym_सूचकांक, defined;
    ElfW(Sym) *sym, *esym;
    sym_सूचकांक = find_elf_sym(symtab_section, name);
    sym = (ElfW(Sym) *)symtab_section->तथ्य + sym_सूचकांक;
    esym_सूचकांक = find_elf_sym(s1->dynsymtab_section, name);
    esym = (ElfW(Sym) *)s1->dynsymtab_section->तथ्य + esym_सूचकांक;
    defined = sym->st_shndx != SHN_UNDEF
        || (esym->st_shndx != SHN_UNDEF && esym->st_आकार);
    चयन (f) {
    हाल 1: /* old symbols w/o '_' */
        अगर (!(sym_सूचकांक || esym_सूचकांक) || defined)
            अवरोध;
    हाल 0:
        अगर (defined) {
            tcc_warning("linker symbol '%s' already defined", name);
            अवरोध;
        }
        sym_सूचकांक = set_global_sym(s1, name, sec, -1);
        get_sym_attr(s1, sym_सूचकांक, 1)->linker_sym = 1;
        अवरोध;
    शेष: /* update (bss only) */
        अगर (get_sym_attr(s1, sym_सूचकांक, 0)->linker_sym)
            sym->st_मूल्य = sec->तथ्य_offset;
    }
#अगर_अघोषित ELF_OBJ_ONLY
    अगर (name[0] == '_')
        set_linker_sym(s1, name + 1, sec, f + 1);
#पूर्ण_अगर
}

/* add various standard linker symbols (must be done after the
   sections are filled (for example after allocating common
   symbols)) */
अटल व्योम tcc_add_linker_symbols(TCCState *s1)
{
    अक्षर buf[1024];
    पूर्णांक i;
    Section *s;

    set_linker_sym(s1, "_etext", text_section, 0);
    set_linker_sym(s1, "_edata", तथ्य_section, 0);
    set_linker_sym(s1, "_end", bss_section, 0);
#अगर TARGETOS_OpenBSD
    set_global_sym(s1, "__executable_start", शून्य, ELF_START_ADDR);
#पूर्ण_अगर

#अगर_घोषित TCC_TARGET_RISCV64
    /* XXX should be .sdata+0x800, not .data+0x800 */
    set_global_sym(s1, "__global_pointer$", तथ्य_section, 0x800);
#पूर्ण_अगर
    /* horrible new standard ldscript defines */
    add_init_array_defines(s1, ".preinit_array");
    add_init_array_defines(s1, ".init_array");
    add_init_array_defines(s1, ".fini_array");
    /* add start and stop symbols for sections whose name can be
       expressed in C */
    क्रम(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        अगर ((s->sh_flags & SHF_ALLOC)
            && (s->sh_type == SHT_PROGBITS || s->sh_type == SHT_NOBITS
                || s->sh_type == SHT_STRTAB)) {
            /* check if section name can be expressed in C */
            स्थिर अक्षर *p0, *p;
            p0 = s->name;
            अगर (*p0 == '.')
                ++p0;
            p = p0;
            क्रम(;;) {
                पूर्णांक c = *p;
                अगर (!c)
                    अवरोध;
                अगर (!isid(c) && !isnum(c))
                    जाओ अग्र_sec;
                p++;
            }
            snprintf(buf, माप(buf), "__start_%s", p0);
            set_global_sym(s1, buf, s, 0);
            snprintf(buf, माप(buf), "__stop_%s", p0);
            set_global_sym(s1, buf, s, -1);
        }
    अग्र_sec: ;
    }
}

ST_FUNC व्योम resolve_common_syms(TCCState *s1)
{
    ElfW(Sym) *sym;

    /* Allocate common symbols in BSS.  */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        अगर (sym->st_shndx == SHN_COMMON && sym->st_आकार) {
            /* symbol alignment is in st_value for SHN_COMMONs */
	    sym->st_मूल्य = section_add(bss_section, sym->st_आकार,
					sym->st_मूल्य);
            sym->st_shndx = bss_section->sh_अंक;
        }
    }

    /* Now assign linker provided symbols their value.  */
    अगर (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_linker_symbols(s1);
}

#अगर_अघोषित ELF_OBJ_ONLY
ST_FUNC व्योम fill_got_entry(TCCState *s1, ElfW_Rel *rel)
{
    पूर्णांक sym_सूचकांक = ELFW(R_SYM) (rel->r_info);
    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->तथ्य)[sym_सूचकांक];
    काष्ठा sym_attr *attr = get_sym_attr(s1, sym_सूचकांक, 0);
    अचिन्हित offset = attr->got_offset;

    अगर (0 == offset)
        वापस;
    section_reserve(s1->got, offset + PTR_आकार);
#अगर PTR_आकार == 8
    write64le(s1->got->तथ्य + offset, sym->st_मूल्य);
#अन्यथा
    write32le(s1->got->तथ्य + offset, sym->st_मूल्य);
#पूर्ण_अगर
}

/* Perform relocation to GOT or PLT entries */
ST_FUNC व्योम fill_got(TCCState *s1)
{
    Section *s;
    ElfW_Rel *rel;
    पूर्णांक i;

    क्रम(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        अगर (s->sh_type != SHT_RELX)
            जारी;
        /* no need to handle got relocations */
        अगर (s->link != symtab_section)
            जारी;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            चयन (ELFW(R_TYPE) (rel->r_info)) {
                हाल R_X86_64_GOT32:
                हाल R_X86_64_GOTPCREL:
		हाल R_X86_64_GOTPCRELX:
		हाल R_X86_64_REX_GOTPCRELX:
                हाल R_X86_64_PLT32:
                    fill_got_entry(s1, rel);
                    अवरोध;
            }
        }
    }
}

/* See put_got_entry for a description.  This is the second stage
   where GOT references to local defined symbols are rewritten.  */
अटल व्योम fill_local_got_entries(TCCState *s1)
{
    ElfW_Rel *rel;
    अगर (!s1->got->reloc)
        वापस;
    for_each_elem(s1->got->reloc, 0, rel, ElfW_Rel) {
	अगर (ELFW(R_TYPE)(rel->r_info) == R_RELATIVE) {
	    पूर्णांक sym_सूचकांक = ELFW(R_SYM) (rel->r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->तथ्य)[sym_सूचकांक];
	    काष्ठा sym_attr *attr = get_sym_attr(s1, sym_सूचकांक, 0);
	    अचिन्हित offset = attr->got_offset;
	    अगर (offset != rel->r_offset - s1->got->sh_addr)
	        tcc_error_noabort("fill_local_got_entries: huh?");
	    rel->r_info = ELFW(R_INFO)(0, R_RELATIVE);
#अगर SHT_RELX == SHT_RELA
	    rel->r_addend = sym->st_मूल्य;
#अन्यथा
	    /* All our REL architectures also happen to be 32bit LE.  */
	    write32le(s1->got->तथ्य + offset, sym->st_मूल्य);
#पूर्ण_अगर
	}
    }
}

/* Bind symbols of executable: resolve undefined symbols from exported symbols
   in shared libraries */
अटल व्योम bind_exe_dynsyms(TCCState *s1, पूर्णांक is_PIE)
{
    स्थिर अक्षर *name;
    पूर्णांक sym_सूचकांक, सूचकांक;
    ElfW(Sym) *sym, *esym;
    पूर्णांक type;

    /* Resolve undefined symbols from dynamic symbols. When there is a match:
       - if STT_FUNC or STT_GNU_IFUNC symbol -> add it in PLT
       - if STT_OBJECT symbol -> add it in .bss section with suitable reloc */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        अगर (sym->st_shndx == SHN_UNDEF
            /* bss symbols may be initialized in the shared library */
            || sym->st_shndx == SHN_COMMON
            || sym->st_shndx == bss_section->sh_अंक) {
            name = (अक्षर *) symtab_section->link->तथ्य + sym->st_name;
            sym_सूचकांक = find_elf_sym(s1->dynsymtab_section, name);
            esym = &((ElfW(Sym) *)s1->dynsymtab_section->तथ्य)[sym_सूचकांक];
            अगर (sym_सूचकांक && esym->st_shndx != SHN_UNDEF) {
                अगर (is_PIE)
                    जारी;
                type = ELFW(ST_TYPE)(esym->st_info);
                अगर ((type == STT_FUNC) || (type == STT_GNU_IFUNC)) {
                    /* Indirect functions shall have STT_FUNC type in executable
                     * dynsym section. Indeed, a dlsym call following a lazy
                     * resolution would pick the symbol value from the
                     * executable dynsym entry which would contain the address
                     * of the function wanted by the caller of dlsym instead of
                     * the address of the function that would return that
                     * address */
                    पूर्णांक dynindex
		      = put_elf_sym(s1->dynsym, 0, esym->st_आकार,
				    ELFW(ST_INFO)(STB_GLOBAL,STT_FUNC), 0, 0,
				    name);
		    पूर्णांक सूचकांक = sym - (ElfW(Sym) *) symtab_section->तथ्य;
		    get_sym_attr(s1, सूचकांक, 1)->dyn_सूचकांक = dynindex;
                } अन्यथा अगर (type == STT_OBJECT) {
                    अचिन्हित दीर्घ offset;
                    ElfW(Sym) *dynsym;
                    अगर (sym->st_shndx == bss_section->sh_अंक) {
                        offset = sym->st_मूल्य;
                    } अन्यथा {
                        offset = bss_section->तथ्य_offset;
                        /* XXX: which alignment ? */
                        offset = (offset + 16 - 1) & -16;
                        bss_section->तथ्य_offset = offset + esym->st_आकार;
                    }
                    set_elf_sym (s1->symtab, offset, esym->st_आकार,
                                 esym->st_info, 0, bss_section->sh_अंक, name);
                    सूचकांक = put_elf_sym(s1->dynsym, offset, esym->st_आकार,
                                        esym->st_info, 0, bss_section->sh_अंक,
                                        name);
                    /* Ensure R_COPY works for weak symbol aliases */
                    अगर (ELFW(ST_BIND)(esym->st_info) == STB_WEAK) {
                        for_each_elem(s1->dynsymtab_section, 1, dynsym, ElfW(Sym)) {
                            अगर ((dynsym->st_मूल्य == esym->st_मूल्य)
                                && (ELFW(ST_BIND)(dynsym->st_info) == STB_GLOBAL)) {
                                अक्षर *dynname = (अक्षर *) s1->dynsymtab_section->link->तथ्य
                                                + dynsym->st_name;
                                put_elf_sym(s1->dynsym, offset, dynsym->st_आकार,
                                            dynsym->st_info, 0,
                                            bss_section->sh_अंक, dynname);
                                अवरोध;
                            }
                        }
                    }
                    put_elf_reloc(s1->dynsym, bss_section,
                                  offset, R_COPY, सूचकांक);
                }
            } अन्यथा अगर (sym->st_shndx == SHN_UNDEF) {
                /* STB_WEAK undefined symbols are accepted */
                /* XXX: _fp_hw seems to be part of the ABI, so we ignore it */
                अगर (ELFW(ST_BIND)(sym->st_info) == STB_WEAK ||
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
अटल व्योम bind_libs_dynsyms(TCCState *s1)
{
    स्थिर अक्षर *name;
    पूर्णांक dynsym_सूचकांक;
    ElfW(Sym) *sym, *esym;

    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        name = (अक्षर *)symtab_section->link->तथ्य + sym->st_name;
        dynsym_सूचकांक = find_elf_sym(s1->dynsymtab_section, name);
        अगर (sym->st_shndx != SHN_UNDEF) {
            अगर (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL
                && (dynsym_सूचकांक || s1->rdynamic))
                set_elf_sym(s1->dynsym, sym->st_मूल्य, sym->st_आकार,
                            sym->st_info, 0, sym->st_shndx, name);
        } अन्यथा अगर (dynsym_सूचकांक) {
            esym = (ElfW(Sym) *)s1->dynsymtab_section->तथ्य + dynsym_सूचकांक;
            अगर (esym->st_shndx == SHN_UNDEF) {
                /* weak symbols can stay undefined */
                अगर (ELFW(ST_BIND)(esym->st_info) != STB_WEAK)
                    tcc_warning("unresolved dynamic reference to '%s'", name);
            }
        }
    }
}

/* Export all non local symbols. This is used by shared libraries so that the
   non local symbols they define can resolve a reference in another shared
   library or in the executable. Correspondingly, it allows undefined local
   symbols to be resolved by other shared libraries or by the executable. */
अटल व्योम export_global_syms(TCCState *s1)
{
    पूर्णांक dynindex, सूचकांक;
    स्थिर अक्षर *name;
    ElfW(Sym) *sym;
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        अगर (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
	    name = (अक्षर *) symtab_section->link->तथ्य + sym->st_name;
	    dynindex = set_elf_sym(s1->dynsym, sym->st_मूल्य, sym->st_आकार,
				   sym->st_info, 0, sym->st_shndx, name);
	    सूचकांक = sym - (ElfW(Sym) *) symtab_section->तथ्य;
            get_sym_attr(s1, सूचकांक, 1)->dyn_सूचकांक = dynindex;
        }
    }
}

/* decide if an unallocated section should be output. */
अटल पूर्णांक set_sec_sizes(TCCState *s1)
{
    पूर्णांक i;
    Section *s;
    पूर्णांक textrel = 0;
    पूर्णांक file_type = s1->output_type;

    /* Allocate strings for section names */
    क्रम(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        अगर (s->sh_type == SHT_RELX && !(s->sh_flags & SHF_ALLOC)) {
            /* when generating a DLL, we include relocations but
               we may patch them */
            अगर ((file_type & TCC_OUTPUT_DYN)
                && (s1->sections[s->sh_info]->sh_flags & SHF_ALLOC)) {
                पूर्णांक गिनती_2 = prepare_dynamic_rel(s1, s);
                अगर (गिनती_2) {
                    /* allocate the section */
                    s->sh_flags |= SHF_ALLOC;
                    s->sh_आकार = गिनती_2 * माप(ElfW_Rel);
                    अगर (s1->sections[s->sh_info]->sh_flags & SHF_EXECINSTR)
                        textrel += गिनती_2;
                }
            }
        } अन्यथा अगर ((s->sh_flags & SHF_ALLOC)
#अगर_घोषित TCC_TARGET_ARM
                   || s->sh_type == SHT_ARM_ATTRIBUTES
#पूर्ण_अगर
                   || s1->do_debug) {
            s->sh_आकार = s->तथ्य_offset;
        }
    }
    वापस textrel;
}

/* various data used under elf_output_file() */
काष्ठा dyn_inf {
    Section *dynamic;
    Section *dynstr;
    Section *interp;
    Section *note;
    Section *gnu_hash;
    काष्ठा {
        /* Info to be copied in dynamic section */
        अचिन्हित दीर्घ तथ्य_offset;
        addr_t rel_addr;
        addr_t rel_आकार;
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
अटल पूर्णांक sort_sections(TCCState *s1, पूर्णांक *sec_order, काष्ठा dyn_inf *d)
{
    Section *s;
    पूर्णांक i, j, k, f, f0, n;
    पूर्णांक nb_sections = s1->nb_sections;
    पूर्णांक *sec_cls = sec_order + nb_sections;
    पूर्णांक tls_align = 0; /* need common alignment for all tls sections */

    क्रम (i = 1; i < nb_sections; i++) {
        s = s1->sections[i];
        अगर (0 == s->sh_name) {
            j = 0x900; /* no sh_name: won't go to file */
        } अन्यथा अगर (s->sh_flags & SHF_ALLOC) {
            j = 0x100;
            अगर ((s->sh_flags & (SHF_WRITE|SHF_TLS)) == SHF_WRITE)
                j = 0x200;
        } अन्यथा {
            j = 0x700;
        }
        अगर (j >= 0x700 && s1->output_format != TCC_OUTPUT_FORMAT_ELF)
            s->sh_आकार = 0, j = 0x900;

        अगर (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM) {
            k = 0x10;
        } अन्यथा अगर (s->sh_type == SHT_STRTAB && म_भेद(s->name, ".stabstr")) {
            k = 0x11;
            अगर (i == nb_sections - 1) /* ".shstrtab" assumed to stay last */
                k = 0xff;
        } अन्यथा अगर (s->sh_type == SHT_HASH || s->sh_type == SHT_GNU_HASH) {
            k = 0x12;
        } अन्यथा अगर (s->sh_type == SHT_GNU_verdef
                  || s->sh_type == SHT_GNU_verneed
                  || s->sh_type == SHT_GNU_versym) {
            k = 0x13;
        } अन्यथा अगर (s->sh_type == SHT_RELX) {
            k = 0x20;
            अगर (s1->plt && s == s1->plt->reloc)
                k = 0x21;
        } अन्यथा अगर (s->sh_flags & SHF_EXECINSTR) {
            k = 0x60;
        /* RELRO sections --> */
        } अन्यथा अगर (s->sh_flags & SHF_TLS) {
            अगर (s->sh_addralign > tls_align)
                tls_align = s->sh_addralign;
            k = 0x40 + (s->sh_type == SHT_NOBITS);
        } अन्यथा अगर (s->sh_type == SHT_PREINIT_ARRAY) {
            k = 0x42;
        } अन्यथा अगर (s->sh_type == SHT_INIT_ARRAY) {
            k = 0x43;
        } अन्यथा अगर (s->sh_type == SHT_FINI_ARRAY) {
            k = 0x44;
        } अन्यथा अगर (s->sh_type == SHT_DYNAMIC) {
            k = 0x48;
        } अन्यथा अगर (s == s1->got) {
            k = 0x49; /* .got as RELRO needs BIND_NOW in DT_FLAGS */
        } अन्यथा अगर (s->reloc && (s->reloc->sh_flags & SHF_ALLOC) && j == 0x100) {
            k = 0x45; /* +1 for data.ro */
        /* <-- */
        } अन्यथा अगर (s->sh_type == SHT_NOTE) {
            k = 0x08, d->notes = 1;
        } अन्यथा अगर (s->sh_type == SHT_NOBITS) {
            k = 0x70; /* bss */
        } अन्यथा अगर (s == d->interp) {
            k = 0x00;
        } अन्यथा {
            k = 0x50; /*तथ्य*/
        }
        k += j;
        /* make our standard sections come last to have _etext/_edata correct values */
        अगर (s->sh_अंक <= bss_section->sh_अंक)
            ++k;
        /* make RELRO section writable */
        अगर ((k & 0xfff0) == 0x140)
            k += 0x100, s->sh_flags |= SHF_WRITE;
        /* sort by insert */
        क्रम (n = i; n > 1 && k < (f = sec_cls[n - 1]); --n)
            sec_cls[n] = f, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
    }
    sec_order[0] = 0;
    d->shnum = 1;

#घोषणा SHFX_NEWPH (1 << 4)
#घोषणा SHFX_RELRO (1 << 5)

    /* count PT_LOAD headers needed */
    n = f0 = 0;
    क्रम (i = 1; i < nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        k = sec_cls[i];
        f = 0;
        अगर (k < 0x900)
            ++d->shnum;
        अगर (k < 0x700) {
            f = s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR);
#अगर TARGETOS_NetBSD || TARGETOS_FreeBSD
	    /* NetBSD only supports 2 PT_LOAD sections.
	       See: https://blog.netbsd.org/tnf/entry/the_first_report_on_lld */
	    अगर ((f & SHF_WRITE) == 0)
                f |= SHF_EXECINSTR;
            k = 0; /* no relro */
#पूर्ण_अगर
            अगर ((k & 0xfff0) == 0x240) /* RELRO sections */
                d->relro = 1, f |= SHFX_RELRO;
            /* start new header when flags changed, but avoid zero memsz */
            अगर (f != f0 && s->sh_आकार)
                f0 = f, ++n, f |= SHFX_NEWPH;
            अगर ((s->sh_flags & SHF_TLS) && s->sh_आकार) {
                s->sh_addralign = tls_align;
                d->tls = 1, f |= SHF_TLS;
            }
        }
        sec_cls[i] = f;
        //printf("ph %d sec %02d : %3X %3X  %8.2X  %04X  %s\n", (f>0) * n, i, f, k, s->sh_type, (int)s->sh_size, s->name);
    }
    वापस n;
}

अटल ElfW(Phdr) *fill_phdr(ElfW(Phdr) *ph, पूर्णांक type, Section *s)
{
    ph->p_type = type;
    ph->p_flags = PF_R;
    अगर (s) {
        अगर (s->sh_flags & SHF_WRITE)
            ph->p_flags |= PF_W;
        ph->p_offset = s->sh_offset;
        ph->p_vaddr = s->sh_addr;
        ph->p_filesz = s->sh_आकार;
        ph->p_align = s->sh_addralign;
    }
    ph->p_paddr = ph->p_vaddr;
    ph->p_memsz = ph->p_filesz;
    वापस ph;
}

अटल ElfW(Phdr) *update_phdr(ElfW(Phdr) *ph, पूर्णांक type, Section *s, addr_t addr, पूर्णांक file_offset)
{
    अगर (ph->p_type == 0) {
        fill_phdr(ph, type, s);
    }
    ph->p_filesz = file_offset - ph->p_offset;
    ph->p_memsz = addr - ph->p_vaddr;
    वापस ph;
}

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
अटल पूर्णांक layout_sections(TCCState *s1, पूर्णांक *sec_order, काष्ठा dyn_inf *d)
{
    Section *s;
    addr_t addr, tmp, align, s_align, base;
    ElfW(Phdr) *ph = शून्य, *ph2;
    पूर्णांक i, f, n, phnum, phfill;
    पूर्णांक file_offset;

    /* compute number of program headers */
    phnum = sort_sections(s1, sec_order, d);
    phfill = 0; /* set to 1 to have dll's with a PT_PHDR */
    अगर (d->interp)
        phfill = 2;
    phnum += phfill;
    अगर (d->dynamic)
        d->dyna = phnum++;
    अगर (d->notes)
        d->notes = phnum++;
    अगर (d->tls)
        d->tls = phnum++;
    अगर (eh_frame_hdr_section)
        d->ehfr = phnum++;
    अगर (d->relro)
        d->relro = phnum++;
    d->phnum = phnum;
    d->phdr = tcc_mallocz(phnum * माप(ElfW(Phdr)));

    file_offset = 0;
    अगर (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
        file_offset = (माप(ElfW(Ehdr)) + phnum * माप(ElfW(Phdr)) + 3) & -4;
        file_offset += d->shnum * माप (ElfW(Shdr));
    }

    s_align = ELF_PAGE_आकार;
    अगर (s1->section_align)
        s_align = s1->section_align;

    addr = ELF_START_ADDR;
    अगर (s1->output_type & TCC_OUTPUT_DYN)
        addr = 0;

    अगर (s1->has_text_addr) {
        addr = s1->text_addr;
        अगर (0) {
            पूर्णांक a_offset, p_offset;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_offset = (पूर्णांक) (addr & (s_align - 1));
            p_offset = file_offset & (s_align - 1);
            अगर (a_offset < p_offset)
                a_offset += s_align;
            file_offset += (a_offset - p_offset);
        }
    }
    base = addr;
    /* compute address after headers */
    addr += file_offset;

    n = 0;
    क्रम(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        f = sec_order[i + s1->nb_sections];
        align = s->sh_addralign - 1;

        अगर (f == 0) { /* no alloc */
            file_offset = (file_offset + align) & ~align;
            s->sh_offset = file_offset;
            अगर (s->sh_type != SHT_NOBITS)
                file_offset += s->sh_आकार;
            जारी;
        }

        अगर ((f & SHFX_NEWPH) && n) {
            /* different rwx section flags */
            अगर (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
                /* if in the middle of a page, w e duplicate the page in
                   memory so that one copy is RX and the other is RW */
                अगर ((addr & (s_align - 1)) != 0)
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
        addr += s->sh_आकार;
        अगर (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_आकार;

        अगर (f & SHFX_NEWPH) {
            /* set new program header */
            ph = &d->phdr[phfill + n];
            fill_phdr(ph, PT_LOAD, s);
            ph->p_align = s_align;
            अगर (f & SHF_EXECINSTR)
                ph->p_flags |= PF_X;
            अगर (n == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_offset = 0;
                ph->p_paddr = ph->p_vaddr = base;
            }
            ++n;
        }

        अगर (ph)
            update_phdr(ph, 0, 0, addr, file_offset);

        अगर (f & SHFX_RELRO) {
            ph2 = update_phdr(&d->phdr[d->relro], PT_GNU_RELRO, s, addr, file_offset);
            ph2->p_align = 1;
        }
        अगर (f & SHF_TLS) {
            ph2 = update_phdr(&d->phdr[d->tls], PT_TLS, s, addr, file_offset);
            अगर (s->sh_type == SHT_NOBITS)
                addr -= s->sh_आकार;
            /* for xxx-link.c:relocate() */
            s1->tls_start = ph2->p_vaddr;
            s1->tls_end = s1->tls_start + ph2->p_memsz + (-ph2->p_memsz & (ph2->p_align - 1));
        }
        अगर (s->sh_type == SHT_NOTE) {
            update_phdr(&d->phdr[d->notes], PT_NOTE, s, addr, file_offset);
        }
    }

    /* Fill other headers */
    अगर (d->dyna)
        fill_phdr(&d->phdr[d->dyna], PT_DYNAMIC, d->dynamic);
    अगर (d->ehfr)
        fill_phdr(&d->phdr[d->ehfr], PT_GNU_EH_FRAME, eh_frame_hdr_section);
    अगर (d->interp)
        fill_phdr(&d->phdr[1], PT_INTERP, d->interp);
    अगर (phfill) {
        ph = &d->phdr[0];
        ph->p_offset = माप(ElfW(Ehdr));
        ph->p_vaddr = base + ph->p_offset;
        ph->p_filesz = phnum * माप(ElfW(Phdr));
        ph->p_align = 4;
        fill_phdr(ph, PT_PHDR, शून्य);
    }
    वापस 0;
}

/* put dynamic tag */
अटल व्योम put_dt(Section *dynamic, पूर्णांक dt, addr_t val)
{
    ElfW(Dyn) *dyn;
    dyn = section_ptr_add(dynamic, माप(ElfW(Dyn)));
    dyn->d_tag = dt;
    dyn->d_un.d_val = val;
}

/* Fill the dynamic section with tags describing the address and size of
   sections */
अटल व्योम fill_dynamic(TCCState *s1, काष्ठा dyn_inf *dyninf)
{
    Section *dynamic = dyninf->dynamic;
    Section *s;

    /* put dynamic section entries */
    put_dt(dynamic, DT_HASH, s1->dynsym->hash->sh_addr);
    put_dt(dynamic, DT_GNU_HASH, dyninf->gnu_hash->sh_addr);
    put_dt(dynamic, DT_STRTAB, dyninf->dynstr->sh_addr);
    put_dt(dynamic, DT_SYMTAB, s1->dynsym->sh_addr);
    put_dt(dynamic, DT_STRSZ, dyninf->dynstr->तथ्य_offset);
    put_dt(dynamic, DT_SYMENT, माप(ElfW(Sym)));
#अगर PTR_आकार == 8
    put_dt(dynamic, DT_RELA, dyninf->rel_addr);
    put_dt(dynamic, DT_RELASZ, dyninf->rel_आकार);
    put_dt(dynamic, DT_RELAENT, माप(ElfW_Rel));
    अगर (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->तथ्य_offset);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_RELA);
    }
    put_dt(dynamic, DT_RELACOUNT, 0);
#अन्यथा
    put_dt(dynamic, DT_REL, dyninf->rel_addr);
    put_dt(dynamic, DT_RELSZ, dyninf->rel_आकार);
    put_dt(dynamic, DT_RELENT, माप(ElfW_Rel));
    अगर (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->तथ्य_offset);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_REL);
    }
    put_dt(dynamic, DT_RELCOUNT, 0);
#पूर्ण_अगर
    अगर (versym_section && verneed_section) {
	/* The dynamic linker can not handle VERSYM without VERNEED */
        put_dt(dynamic, DT_VERSYM, versym_section->sh_addr);
        put_dt(dynamic, DT_VERNEED, verneed_section->sh_addr);
        put_dt(dynamic, DT_VERNEEDNUM, dt_verneednum);
    }
    s = have_section(s1, ".preinit_array");
    अगर (s && s->तथ्य_offset) {
        put_dt(dynamic, DT_PREINIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_PREINIT_ARRAYSZ, s->तथ्य_offset);
    }
    s = have_section(s1, ".init_array");
    अगर (s && s->तथ्य_offset) {
        put_dt(dynamic, DT_INIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_INIT_ARRAYSZ, s->तथ्य_offset);
    }
    s = have_section(s1, ".fini_array");
    अगर (s && s->तथ्य_offset) {
        put_dt(dynamic, DT_FINI_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_FINI_ARRAYSZ, s->तथ्य_offset);
    }
    s = have_section(s1, ".init");
    अगर (s && s->तथ्य_offset) {
        put_dt(dynamic, DT_INIT, s->sh_addr);
    }
    s = have_section(s1, ".fini");
    अगर (s && s->तथ्य_offset) {
        put_dt(dynamic, DT_FINI, s->sh_addr);
    }
    अगर (s1->do_debug)
        put_dt(dynamic, DT_DEBUG, 0);
    put_dt(dynamic, DT_NULL, 0);
}

/* Remove gaps between RELX sections.
   These gaps are a result of final_sections_reloc. Here some relocs are removed.
   The gaps are then filled with 0 in tcc_output_elf. The 0 is intepreted as
   R_...NONE reloc. This does work on most targets but on OpenBSD/arm64 this
   is illegal. OpenBSD/arm64 does not support R_...NONE reloc. */
अटल व्योम update_reloc_sections(TCCState *s1, काष्ठा dyn_inf *dyninf)
{
    पूर्णांक i;
    अचिन्हित दीर्घ file_offset = 0;
    Section *s;
    Section *relocplt = s1->plt ? s1->plt->reloc : शून्य;

    /* dynamic relocation table information, for .dynamic section */
    dyninf->rel_addr = dyninf->rel_आकार = 0;

    क्रम(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
	अगर (s->sh_type == SHT_RELX && s != relocplt) {
	    अगर (dyninf->rel_आकार == 0) {
		dyninf->rel_addr = s->sh_addr;
		file_offset = s->sh_offset;
	    }
	    अन्यथा {
		s->sh_addr = dyninf->rel_addr + dyninf->rel_आकार;
		s->sh_offset = file_offset + dyninf->rel_आकार;
	    }
	    dyninf->rel_आकार += s->sh_आकार;
	}
    }
}
#पूर्ण_अगर /* ndef ELF_OBJ_ONLY */

/* Create an ELF file on disk.
   This function handle ELF specific layout requirements */
अटल पूर्णांक tcc_output_elf(TCCState *s1, खाता *f, पूर्णांक phnum, ElfW(Phdr) *phdr)
{
    पूर्णांक i, shnum, offset, आकार, file_type;
    Section *s;
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) shdr, *sh;

    file_type = s1->output_type;
    shnum = s1->nb_sections;

    स_रखो(&ehdr, 0, माप(ehdr));
    अगर (phnum > 0) {
        ehdr.e_phentsize = माप(ElfW(Phdr));
        ehdr.e_phnum = phnum;
        ehdr.e_phoff = माप(ElfW(Ehdr));
    }

    /* fill header */
    ehdr.e_ident[0] = ELFMAG0;
    ehdr.e_ident[1] = ELFMAG1;
    ehdr.e_ident[2] = ELFMAG2;
    ehdr.e_ident[3] = ELFMAG3;
    ehdr.e_ident[4] = ELFCLASSW;
    ehdr.e_ident[5] = ELFDATA2LSB;
    ehdr.e_ident[6] = EV_CURRENT;

#अगर TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    ehdr.e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
#या_अगर TARGETOS_OpenBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_OPENBSD;
#या_अगर TARGETOS_NetBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_NETBSD;
#या_अगर defined TCC_TARGET_ARM && defined TCC_ARM_EABI
    ehdr.e_flags = EF_ARM_EABI_VER5;
    ehdr.e_flags |= s1->float_abi == ARM_HARD_FLOAT
        ? EF_ARM_VFP_FLOAT : EF_ARM_SOFT_FLOAT;
#या_अगर defined TCC_TARGET_ARM
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#या_अगर defined TCC_TARGET_RISCV64
    /* XXX should be configurable */
    ehdr.e_flags = EF_RISCV_FLOAT_ABI_DOUBLE;
#पूर्ण_अगर

    अगर (file_type == TCC_OUTPUT_OBJ) {
        ehdr.e_type = ET_REL;
    } अन्यथा {
        अगर (file_type & TCC_OUTPUT_DYN)
            ehdr.e_type = ET_DYN;
        अन्यथा
            ehdr.e_type = ET_EXEC;
        अगर (s1->elf_entryname)
            ehdr.e_entry = get_sym_addr(s1, s1->elf_entryname, 1, 0);
        अन्यथा
            ehdr.e_entry = get_sym_addr(s1, "_start", !!(file_type & TCC_OUTPUT_EXE), 0);
        अगर (ehdr.e_entry == (addr_t)-1)
            ehdr.e_entry = text_section->sh_addr;
        अगर (s1->nb_errors)
            वापस -1;
    }

    sort_syms(s1, s1->symtab);

    ehdr.e_machine = EM_TCC_TARGET;
    ehdr.e_version = EV_CURRENT;
    ehdr.e_shoff = (माप(ElfW(Ehdr)) + phnum * माप(ElfW(Phdr)) + 3) & -4;
    ehdr.e_ehsize = माप(ElfW(Ehdr));
    ehdr.e_shentsize = माप(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    offset = ख_डालो(&ehdr, 1, माप(ElfW(Ehdr)), f);
    अगर (phdr)
        offset += ख_डालो(phdr, 1, phnum * माप(ElfW(Phdr)), f);

    /* output section headers */
    जबतक (offset < ehdr.e_shoff) {
        ख_अक्षर_दो(0, f);
        offset++;
    }

    क्रम(i = 0; i < shnum; i++) {
        sh = &shdr;
        स_रखो(sh, 0, माप(ElfW(Shdr)));
        अगर (i) {
            s = s1->sections[i];
            sh->sh_name = s->sh_name;
            sh->sh_type = s->sh_type;
            sh->sh_flags = s->sh_flags;
            sh->sh_entsize = s->sh_entsize;
            sh->sh_info = s->sh_info;
            अगर (s->link)
                sh->sh_link = s->link->sh_अंक;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_offset = s->sh_offset;
            sh->sh_आकार = s->sh_आकार;
        }
        offset += ख_डालो(sh, 1, माप(ElfW(Shdr)), f);
    }

    /* output sections */
    क्रम(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        अगर (s->sh_type != SHT_NOBITS) {
            जबतक (offset < s->sh_offset) {
                ख_अक्षर_दो(0, f);
                offset++;
            }
            आकार = s->sh_आकार;
            अगर (आकार)
                offset += ख_डालो(s->तथ्य, 1, आकार, f);
        }
    }
    वापस 0;
}

अटल पूर्णांक tcc_output_द्विआधारी(TCCState *s1, खाता *f)
{
    Section *s;
    पूर्णांक i, offset, आकार;

    offset = 0;
    क्रम(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[i];
        अगर (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            जबतक (offset < s->sh_offset) {
                ख_अक्षर_दो(0, f);
                offset++;
            }
            आकार = s->sh_आकार;
            ख_डालो(s->तथ्य, 1, आकार, f);
            offset += आकार;
        }
    }
    वापस 0;
}

/* Write an elf, coff or "binary" file */
अटल पूर्णांक tcc_write_elf_file(TCCState *s1, स्थिर अक्षर *filename, पूर्णांक phnum,
                              ElfW(Phdr) *phdr)
{
    पूर्णांक fd, mode, file_type, ret;
    खाता *f;

    file_type = s1->output_type;
    अगर (file_type == TCC_OUTPUT_OBJ)
        mode = 0666;
    अन्यथा
        mode = 0777;
    unlink(filename);
    fd = खोलो(filename, O_WRONLY | O_CREAT | O_TRUNC | O_द्विआधारी_2, mode);
    अगर (fd < 0 || (f = fdopen(fd, "wb")) == शून्य)
        वापस tcc_error_noabort("could not write '%s: %s'", filename, म_त्रुटि(त्रुटि_सं));
    अगर (s1->verbose)
        म_लिखो("<- %s\n", filename);
#अगर_घोषित TCC_TARGET_COFF
    अगर (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    अन्यथा
#पूर्ण_अगर
    अगर (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        ret = tcc_output_elf(s1, f, phnum, phdr);
    अन्यथा
        ret = tcc_output_द्विआधारी(s1, f);
    ख_बंद(f);

    वापस ret;
}

#अगर_अघोषित ELF_OBJ_ONLY
/* order sections according to sec_order, remove sections
   that we aren't going to output.  */
अटल व्योम reorder_sections(TCCState *s1, पूर्णांक *sec_order)
{
    पूर्णांक i, nnew, k, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    backmap = tcc_malloc(s1->nb_sections * माप(backmap[0]));
    क्रम (i = 0, nnew = 0, snew = शून्य; i < s1->nb_sections; i++) {
	k = sec_order ? sec_order[i] : i;
	s = s1->sections[k];
	अगर (!i || s->sh_name) {
	    backmap[k] = nnew;
            dynarray_add(&snew, &nnew, s);
	} अन्यथा {
	    backmap[k] = 0;
            /* just remember to free them later */
	    dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, s);
	}
    }
    क्रम (i = 1; i < nnew; i++) {
	s = snew[i];
        s->sh_अंक = i;
        अगर (s->sh_type == SHT_RELX)
            s->sh_info = backmap[s->sh_info];
        अन्यथा अगर (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM)
            for_each_elem(s, 1, sym, ElfW(Sym))
                अगर (sym->st_shndx < s1->nb_sections)
                    sym->st_shndx = backmap[sym->st_shndx];
    }
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}

#अगर_घोषित TCC_TARGET_ARM
अटल व्योम create_arm_attribute_section(TCCState *s1)
{
   // Needed for DLL support.
    अटल स्थिर अचिन्हित अक्षर arm_attr[] = {
        0x41,                            // 'A'
        0x2c, 0x00, 0x00, 0x00,          // size 0x2c
        'a', 'e', 'a', 'b', 'i', 0x00,   // "aeabi"
        0x01, 0x22, 0x00, 0x00, 0x00,    // 'File Attributes', size 0x22
        0x05, 0x36, 0x00,                // 'CPU_name', "6"
#अगर CONFIG_TCC_CPUVER >= 7
        0x06, 0x0a,                      // 'CPU_arch', 'v7'
#अन्यथा
        0x06, 0x06,                      // 'CPU_arch', 'v6'
#पूर्ण_अगर
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
    अचिन्हित अक्षर *ptr = section_ptr_add(attr, माप(arm_attr));
    attr->sh_addralign = 1;
    स_नकल(ptr, arm_attr, माप(arm_attr));
    अगर (s1->float_abi != ARM_HARD_FLOAT) {
        ptr[26] = 0x00; // 'FP_arch', 'No'
        ptr[41] = 0x1e; // 'ABI_optimization_goals'
        ptr[42] = 0x06; // 'Aggressive Debug'
    }
}
#पूर्ण_अगर

#अगर_घोषित TCC_TARGET_RISCV64
अटल व्योम create_riscv_attribute_section(TCCState *s1)
{
    अटल स्थिर अचिन्हित अक्षर riscv_attr[] = {
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
    अचिन्हित अक्षर *ptr = section_ptr_add(attr, माप(riscv_attr));
    attr->sh_addralign = 1;
    स_नकल(ptr, riscv_attr, माप(riscv_attr));
}
#पूर्ण_अगर

#अगर TARGETOS_OpenBSD || TARGETOS_NetBSD || TARGETOS_FreeBSD

अटल व्योम fill_bsd_note(Section *s, पूर्णांक type,
			  स्थिर अक्षर *मूल्य, uint32_t तथ्य)
{
    अचिन्हित दीर्घ offset = 0;
    अक्षर *ptr;
    ElfW(Nhdr) *note;
    पूर्णांक align = s->sh_addralign;

    /* check if type present */
    जबतक (offset + माप(ElfW(Nhdr)) < s->तथ्य_offset) {
        note = (ElfW(Nhdr) *) (s->तथ्य + offset);
	अगर (note->n_type == type)
	    वापस;
	offset += (माप(ElfW(Nhdr)) + note->n_namesz + note->n_descsz +
		  align - 1) & -align;
    }
    ptr = section_ptr_add(s, माप(ElfW(Nhdr)) + 8 + 4);
    note = (ElfW(Nhdr) *) ptr;
    note->n_namesz = 8;
    note->n_descsz = 4;
    note->n_type = type;
    म_नकल (ptr + माप(ElfW(Nhdr)), मूल्य);
    स_नकल (ptr + माप(ElfW(Nhdr)) + 8, &तथ्य, 4);
}

अटल Section *create_bsd_note_section(TCCState *s1,
					स्थिर अक्षर *name,
					स्थिर अक्षर *मूल्य)
{
    Section *s;
    अचिन्हित पूर्णांक major = 0, minor = 0, patch = 0;

#अगर_घोषित CONFIG_OS_RELEASE
    माला_पूछो(CONFIG_OS_RELEASE, "%u.%u.%u", &major, &minor, &patch);
#पूर्ण_अगर
#अगर TARGETOS_FreeBSD
    अगर (major < 14)
	वापस शून्य;
#पूर्ण_अगर
    s = find_section (s1, name);
    s->sh_type = SHT_NOTE;
#अगर TARGETOS_OpenBSD
    fill_bsd_note(s, ELF_NOTE_OS_GNU, मूल्य, 0);
#या_अगर TARGETOS_NetBSD
    fill_bsd_note(s, 1 /* NT_NETBSD_IDENT_TAG */, मूल्य,
		  major * 100000000u + (minor % 100u) * 1000000u +
		  (patch % 10000u) * 100u);
#या_अगर TARGETOS_FreeBSD
    fill_bsd_note(s, 1 /* NT_FREEBSD_ABI_TAG */, मूल्य,
		  major * 100000u + (minor % 100u) * 1000u);
    fill_bsd_note(s, 4 /* NT_FREEBSD_FEATURE_CTL */, मूल्य, 0);
    fill_bsd_note(s, 2 /* NT_FREEBSD_NOINIT_TAG */, मूल्य, 0);
#पूर्ण_अगर
    वापस s;
}
#पूर्ण_अगर

अटल व्योम alloc_sec_names(TCCState *s1, पूर्णांक is_obj);

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
अटल पूर्णांक elf_output_file(TCCState *s1, स्थिर अक्षर *filename)
{
    पूर्णांक i, ret, file_type, *sec_order;
    काष्ठा dyn_inf dyninf = {0};
    Section *interp, *dynstr, *dynamic;
    पूर्णांक textrel, got_sym, dt_flags_1;

    file_type = s1->output_type;
    ret = -1;
    interp = dynstr = dynamic = शून्य;
    sec_order = शून्य;

#अगर_घोषित TCC_TARGET_ARM
    create_arm_attribute_section (s1);
#पूर्ण_अगर

#अगर_घोषित TCC_TARGET_RISCV64
    create_riscv_attribute_section(s1);
#पूर्ण_अगर

#अगर TARGETOS_OpenBSD
    dyninf.note = create_bsd_note_section (s1, ".note.openbsd.ident", "OpenBSD");
#पूर्ण_अगर

#अगर TARGETOS_NetBSD
    dyninf.note = create_bsd_note_section (s1, ".note.netbsd.ident", "NetBSD");
#पूर्ण_अगर

#अगर TARGETOS_FreeBSD
    dyninf.note = create_bsd_note_section (s1, ".note.tag", "FreeBSD");
#पूर्ण_अगर

        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_add_runtime(s1);
	resolve_common_syms(s1);

        अगर (!s1->static_link) {
            अगर (file_type & TCC_OUTPUT_EXE) {
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
            dynamic->sh_entsize = माप(ElfW(Dyn));

            got_sym = build_got(s1);
            अगर (file_type & TCC_OUTPUT_EXE) {
                bind_exe_dynsyms(s1, file_type & TCC_OUTPUT_DYN);
                अगर (s1->nb_errors)
                    जाओ the_end;
            }
            build_got_entries(s1, got_sym);
            अगर (file_type & TCC_OUTPUT_EXE) {
                bind_libs_dynsyms(s1);
            } अन्यथा {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
#अगर TCC_EH_FRAME
	    /* fill with initial data */
	    tcc_eh_frame_hdr(s1, 0);
#पूर्ण_अगर
	    dyninf.gnu_hash = create_gnu_hash(s1);
        } अन्यथा {
            build_got_entries(s1, 0);
        }
	version_add (s1);

    textrel = set_sec_sizes(s1);

    अगर (!s1->static_link) {
        /* add a list of needed dlls */
        क्रम(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            अगर (dllref->level == 0)
                put_dt(dynamic, DT_NEEDED, put_elf_str(dynstr, dllref->name));
        }

        अगर (s1->rpath)
            put_dt(dynamic, s1->enable_new_dtags ? DT_RUNPATH : DT_RPATH,
                   put_elf_str(dynstr, s1->rpath));

        dt_flags_1 = DF_1_NOW;
        अगर (file_type & TCC_OUTPUT_DYN) {
            अगर (s1->soname)
                put_dt(dynamic, DT_SONAME, put_elf_str(dynstr, s1->soname));
            /* XXX: currently, since we do not handle PIC code, we
               must relocate the readonly segments */
            अगर (textrel)
                put_dt(dynamic, DT_TEXTREL, 0);
            अगर (file_type & TCC_OUTPUT_EXE)
                dt_flags_1 = DF_1_NOW | DF_1_PIE;
	    अगर (s1->znodelete)
		dt_flags_1 |= DF_1_NODELETE;
        }
        put_dt(dynamic, DT_FLAGS, DF_BIND_NOW);
        put_dt(dynamic, DT_FLAGS_1, dt_flags_1);
        अगर (s1->symbolic)
            put_dt(dynamic, DT_SYMBOLIC, 0);

        dyninf.dynamic = dynamic;
        dyninf.dynstr = dynstr;
        /* remember offset and reserve space for 2nd call below */
        dyninf.तथ्य_offset = dynamic->तथ्य_offset;
        fill_dynamic(s1, &dyninf);
        dynamic->sh_आकार = dynamic->तथ्य_offset;
        dynstr->sh_आकार = dynstr->तथ्य_offset;
    }

    /* create and fill .shstrtab section */
    alloc_sec_names(s1, 0);
    /* this array is used to reorder sections in the output file */
    sec_order = tcc_malloc(माप(पूर्णांक) * 2 * s1->nb_sections);
    /* compute section to program header mapping */
    layout_sections(s1, sec_order, &dyninf);

        अगर (dynamic) {
            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->तथ्य, dynamic->sh_addr);
            अगर (file_type == TCC_OUTPUT_EXE
                || (RELOCATE_DLLPLT && (file_type & TCC_OUTPUT_DYN)))
                relocate_plt(s1);
            /* relocate symbols in .dynsym now that final addresses are known */
            relocate_syms(s1, s1->dynsym, 2);
        }

        /* if building executable or DLL, then relocate each section
           except the GOT which is already relocated */
        relocate_syms(s1, s1->symtab, 0);
        अगर (s1->nb_errors != 0)
            जाओ the_end;
        relocate_sections(s1);
        अगर (dynamic) {
	    update_reloc_sections (s1, &dyninf);
            dynamic->तथ्य_offset = dyninf.तथ्य_offset;
            fill_dynamic(s1, &dyninf);
	}
        /* Perform relocation to GOT or PLT entries */
        अगर (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        अन्यथा अगर (s1->got)
            fill_local_got_entries(s1);

    अगर (dyninf.gnu_hash)
        update_gnu_hash(s1, dyninf.gnu_hash);

    reorder_sections(s1, sec_order);
#अगर TCC_EH_FRAME
    /* fill with final data */
    tcc_eh_frame_hdr(s1, 1);
#पूर्ण_अगर
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, dyninf.phnum, dyninf.phdr);
 the_end:
    tcc_free(sec_order);
    tcc_free(dyninf.phdr);
    वापस ret;
}
#पूर्ण_अगर /* ndef ELF_OBJ_ONLY */

/* Allocate strings for section names */
अटल व्योम alloc_sec_names(TCCState *s1, पूर्णांक is_obj)
{
    पूर्णांक i;
    Section *s, *strsec;

    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");
    क्रम(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        अगर (is_obj)
            s->sh_आकार = s->तथ्य_offset;
	अगर (s->sh_आकार || s == strsec || (s->sh_flags & SHF_ALLOC) || is_obj)
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_आकार = strsec->तथ्य_offset;
}

/* Output an elf .o file */
अटल पूर्णांक elf_output_obj(TCCState *s1, स्थिर अक्षर *filename)
{
    Section *s;
    पूर्णांक i, ret, file_offset;
    /* Allocate strings for section names */
    alloc_sec_names(s1, 1);
    file_offset = (माप (ElfW(Ehdr)) + 3) & -4;
    file_offset += s1->nb_sections * माप(ElfW(Shdr));
    क्रम(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        file_offset = (file_offset + 15) & -16;
        s->sh_offset = file_offset;
        अगर (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_आकार;
    }
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, 0, शून्य);
    वापस ret;
}

LIBTCCAPI पूर्णांक tcc_output_file(TCCState *s, स्थिर अक्षर *filename)
{
    s->nb_errors = 0;
    अगर (s->test_coverage)
        tcc_tcov_add_file(s, filename);
    अगर (s->output_type == TCC_OUTPUT_OBJ)
        वापस elf_output_obj(s, filename);
#अगर_घोषित TCC_TARGET_PE
    वापस  pe_output_file(s, filename);
#या_अगर defined TCC_TARGET_MACHO
    वापस macho_output_file(s, filename);
#अन्यथा
    वापस elf_output_file(s, filename);
#पूर्ण_अगर
}

ST_FUNC ssize_t full_read(पूर्णांक fd, व्योम *buf, माप_प्रकार गिनती_2) {
    अक्षर *cbuf = buf;
    माप_प्रकार rnum = 0;
    जबतक (1) {
        ssize_t अंक = पढ़ो(fd, cbuf, गिनती_2-rnum);
        अगर (अंक < 0) वापस अंक;
        अगर (अंक == 0) वापस rnum;
        rnum += अंक;
        cbuf += अंक;
    }
}

ST_FUNC व्योम *load_तथ्य(पूर्णांक fd, अचिन्हित दीर्घ file_offset, अचिन्हित दीर्घ आकार)
{
    व्योम *तथ्य;

    तथ्य = tcc_malloc(आकार);
    lseek(fd, file_offset, शुरू_से);
    full_read(fd, तथ्य, आकार);
    वापस तथ्य;
}

प्रकार काष्ठा SectionMergeInfo {
    Section *s;            /* corresponding existing section */
    अचिन्हित दीर्घ offset;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} SectionMergeInfo;

ST_FUNC पूर्णांक tcc_object_type(पूर्णांक fd, ElfW(Ehdr) *h)
{
    पूर्णांक आकार = full_read(fd, h, माप *h);
    अगर (आकार == माप *h && 0 == स_भेद(h, ELFMAG, 4)) {
        अगर (h->e_type == ET_REL)
            वापस AFF_BINTYPE_REL;
        अगर (h->e_type == ET_DYN)
            वापस AFF_BINTYPE_DYN;
    } अन्यथा अगर (आकार >= 8) {
        अगर (0 == स_भेद(h, ARMAG, 8))
            वापस AFF_BINTYPE_AR;
#अगर_घोषित TCC_TARGET_COFF
        अगर (((काष्ठा filehdr*)h)->f_magic == COFF_C67_MAGIC)
            वापस AFF_BINTYPE_C67;
#पूर्ण_अगर
    }
    वापस 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC पूर्णांक tcc_load_object_file(TCCState *s1,
                                पूर्णांक fd, अचिन्हित दीर्घ file_offset)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    अचिन्हित दीर्घ आकार, offset, offseti;
    पूर्णांक i, j, nb_syms, sym_सूचकांक, ret, seencompressed;
    अक्षर *strsec, *strtab;
    पूर्णांक stab_सूचकांक, stabstr_सूचकांक;
    पूर्णांक *old_to_new_syms;
    अक्षर *sh_name, *name;
    SectionMergeInfo *sm_table, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    lseek(fd, file_offset, शुरू_से);
    अगर (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        जाओ invalid;
    /* test CPU specific stuff */
    अगर (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
invalid:
        वापस tcc_error_noabort("invalid object file");
    }
    /* read sections */
    shdr = load_तथ्य(fd, file_offset + ehdr.e_shoff,
                     माप(ElfW(Shdr)) * ehdr.e_shnum);
    sm_table = tcc_mallocz(माप(SectionMergeInfo) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = load_तथ्य(fd, file_offset + sh->sh_offset, sh->sh_आकार);

    /* load symtab and strtab */
    old_to_new_syms = शून्य;
    symtab = शून्य;
    strtab = शून्य;
    nb_syms = 0;
    seencompressed = 0;
    stab_सूचकांक = stabstr_सूचकांक = 0;
    ret = -1;

    क्रम(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        अगर (sh->sh_type == SHT_SYMTAB) {
            अगर (symtab) {
                tcc_error_noabort("object must contain only one symtab");
                जाओ the_end;
            }
            nb_syms = sh->sh_आकार / माप(ElfW(Sym));
            symtab = load_तथ्य(fd, file_offset + sh->sh_offset, sh->sh_आकार);
            sm_table[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = load_तथ्य(fd, file_offset + sh->sh_offset, sh->sh_आकार);
        }
	अगर (sh->sh_flags & SHF_COMPRESSED)
	    seencompressed = 1;
    }

    /* now examine each section and try to merge its content with the
       ones in memory */
    क्रम(i = 1; i < ehdr.e_shnum; i++) {
        /* no need to examine section name strtab */
        अगर (i == ehdr.e_shstrndx)
            जारी;
        sh = &shdr[i];
	अगर (sh->sh_type == SHT_RELX)
	  sh = &shdr[sh->sh_info];
        /* ignore sections types we do not handle (plus relocs to those) */
        sh_name = strsec + sh->sh_name;
        अगर (0 == म_भेदन(sh_name, ".debug_", 7)
         || 0 == म_भेदन(sh_name, ".stab", 5)) {
	    अगर (!s1->do_debug || seencompressed)
	        जारी;
#अगर !(TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD)
        } अन्यथा अगर (0 == म_भेदन(sh_name, ".eh_frame", 9)) {
            अगर (शून्य == eh_frame_section)
                जारी;
#पूर्ण_अगर
        } अन्यथा
        अगर (sh->sh_type != SHT_PROGBITS &&
            sh->sh_type != SHT_NOTE &&
            sh->sh_type != SHT_NOBITS &&
            sh->sh_type != SHT_PREINIT_ARRAY &&
            sh->sh_type != SHT_INIT_ARRAY &&
            sh->sh_type != SHT_FINI_ARRAY
#अगर_घोषित TCC_ARM_EABI
            /* Added in commit f99d3de221db23e322c6c18c8249282e27726c25
               but suppressed in 3cfaaaf1eb97d858e583412616f68f75fdad5da5
               So don't load it in order to avoid dangling references from
               (STT_SECTION) symbols. */
            // && sh->sh_type != SHT_ARM_EXIDX
#पूर्ण_अगर

#अगर TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD
            && sh->sh_type != SHT_X86_64_UNWIND
#पूर्ण_अगर
            )
            जारी;

	sh = &shdr[i];
        sh_name = strsec + sh->sh_name;
        अगर (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        /* find corresponding section, if any */
        क्रम(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            अगर (म_भेद(s->name, sh_name))
                जारी;
            अगर (sh->sh_type != s->sh_type
                && म_भेद (s->name, ".eh_frame")
                /* some crt1.o seem to have two ".note.GNU-stack" (SHT_NOTE & SHT_PROGBITS) */
                && म_भेद (s->name, ".note.GNU-stack")
                ) {
                tcc_error_noabort("section type conflict: %s %02x <> %02x", s->name, sh->sh_type, s->sh_type);
                जाओ the_end;
            }
            अगर (!म_भेदन(sh_name, ".gnu.linkonce", 13)) {
                /* if a 'linkonce' section is already present, we
                   do not add it again. It is a little tricky as
                   symbols can still be defined in
                   it. */
                sm_table[i].link_once = 1;
                जाओ अग्र;
            }
            अगर (stab_section) {
                अगर (s == stab_section)
                    stab_सूचकांक = i;
                अगर (s == stab_section->link)
                    stabstr_सूचकांक = i;
            }
            जाओ found;
        }
        /* not found: create new section */
        s = new_section(s1, sh_name, sh->sh_type, sh->sh_flags & ~SHF_GROUP);
        /* take as much info as possible from the section. sh_link and
           sh_info will be updated later */
        s->sh_addralign = sh->sh_addralign;
        s->sh_entsize = sh->sh_entsize;
        sm_table[i].new_section = 1;
    found:
        आकार = sh->sh_आकार;
        /* align start of section */
        offset = section_add(s, आकार, sh->sh_addralign);
        अगर (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        sm_table[i].offset = offset;
        sm_table[i].s = s;
        /* concatenate sections */
        अगर (sh->sh_type != SHT_NOBITS && आकार) {
            अचिन्हित अक्षर *ptr;
            lseek(fd, file_offset + sh->sh_offset, शुरू_से);
            ptr = s->तथ्य + offset;
            full_read(fd, ptr, आकार);
        }
#अगर defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
        /* align code sections to instruction lenght */
        /* This is needed if we compile a c file after this */
        अगर (s->sh_flags & SHF_EXECINSTR)
            section_add(s, 0, 4);
#पूर्ण_अगर
    अग्र: ;
    }

    /* gr relocate stab strings */
    अगर (stab_सूचकांक && stabstr_सूचकांक) {
        Stab_Sym *a, *b;
        अचिन्हित o;
        s = sm_table[stab_सूचकांक].s;
        a = (Stab_Sym *)(s->तथ्य + sm_table[stab_सूचकांक].offset);
        b = (Stab_Sym *)(s->तथ्य + s->तथ्य_offset);
        o = sm_table[stabstr_सूचकांक].offset;
        जबतक (a < b) {
            अगर (a->n_strx)
                a->n_strx += o;
            a++;
        }
    }

    /* second short pass to update sh_link and sh_info fields of new
       sections */
    क्रम(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        अगर (!s || !sm_table[i].new_section)
            जारी;
        sh = &shdr[i];
        अगर (sh->sh_link > 0)
            s->link = sm_table[sh->sh_link].s;
        अगर (sh->sh_type == SHT_RELX) {
            s->sh_info = sm_table[sh->sh_info].s->sh_अंक;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }

    अगर (!symtab)
        जाओ done;

    /* resolve symbols */
    old_to_new_syms = tcc_mallocz(nb_syms * माप(पूर्णांक));

    sym = symtab + 1;
    क्रम(i = 1; i < nb_syms; i++, sym++) {
        अगर (sym->st_shndx != SHN_UNDEF &&
            sym->st_shndx < SHN_LORESERVE) {
            sm = &sm_table[sym->st_shndx];
            अगर (sm->link_once) {
                /* if a symbol is in a link once section, we use the
                   already defined symbol. It is very important to get
                   correct relocations */
                अगर (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
                    name = strtab + sym->st_name;
                    sym_सूचकांक = find_elf_sym(symtab_section, name);
                    अगर (sym_सूचकांक)
                        old_to_new_syms[i] = sym_सूचकांक;
                }
                जारी;
            }
            /* if no corresponding section added, no need to add symbol */
            अगर (!sm->s)
                जारी;
            /* convert section number */
            sym->st_shndx = sm->s->sh_अंक;
            /* offset value */
            sym->st_मूल्य += sm->offset;
        }
        /* add symbol */
        name = strtab + sym->st_name;
        sym_सूचकांक = set_elf_sym(symtab_section, sym->st_मूल्य, sym->st_आकार,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_to_new_syms[i] = sym_सूचकांक;
    }

    /* third pass to patch relocation entries */
    क्रम(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        अगर (!s)
            जारी;
        sh = &shdr[i];
        offset = sm_table[i].offset;
        आकार = sh->sh_आकार;
        चयन(s->sh_type) {
        हाल SHT_RELX:
            /* take relocation offset information */
            offseti = sm_table[sh->sh_info].offset;
	    क्रम (rel = (ElfW_Rel *) s->तथ्य + (offset / माप(*rel));
		 rel < (ElfW_Rel *) s->तथ्य + ((offset + आकार) / माप(*rel));
		 rel++) {
                पूर्णांक type;
                अचिन्हित sym_सूचकांक;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                अगर (sym_सूचकांक >= nb_syms)
                    जाओ invalid_reloc;
                sym_सूचकांक = old_to_new_syms[sym_सूचकांक];
                /* ignore link_once in rel section. */
                अगर (!sym_सूचकांक && !sm_table[sh->sh_info].link_once
#अगर_घोषित TCC_TARGET_ARM
                    && type != R_ARM_V4BX
#या_अगर defined TCC_TARGET_RISCV64
                    && type != R_RISCV_ALIGN
                    && type != R_RISCV_RELAX
#पूर्ण_अगर
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, (पूर्णांक)rel->r_offset);
                    जाओ the_end;
                }
                rel->r_info = ELFW(R_INFO)(sym_सूचकांक, type);
                /* offset the relocation offset */
                rel->r_offset += offseti;
#अगर_घोषित TCC_TARGET_ARM
                /* Jumps and branches from a Thumb code to a PLT entry need
                   special handling since PLT entries are ARM code.
                   Unconditional bl instructions referencing PLT entries are
                   handled by converting these instructions into blx
                   instructions. Other case of instructions referencing a PLT
                   entry require to add a Thumb stub before the PLT entry to
                   switch to ARM mode. We set bit plt_thumb_stub of the
                   attribute of a symbol to indicate such a case. */
                अगर (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_सूचकांक, 1)->plt_thumb_stub = 1;
#पूर्ण_अगर
            }
            अवरोध;
        शेष:
            अवरोध;
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
    वापस ret;
}

प्रकार काष्ठा ArchiveHeader {
    अक्षर ar_name[16];           /* name of this member */
    अक्षर ar_date[12];           /* file mtime */
    अक्षर ar_uid[6];             /* owner uid; printed as decimal */
    अक्षर ar_gid[6];             /* owner gid; printed as decimal */
    अक्षर ar_mode[8];            /* file mode, printed as octal   */
    अक्षर ar_आकार[10];           /* file size, printed as decimal */
    अक्षर ar_fmag[2];            /* should contain ARFMAG */
} ArchiveHeader;

#घोषणा ARFMAG "`\n"

अटल अचिन्हित दीर्घ दीर्घ get_be(स्थिर uint8_t *b, पूर्णांक n)
{
    अचिन्हित दीर्घ दीर्घ ret = 0;
    जबतक (n)
        ret = (ret << 8) | *b++, --n;
    वापस ret;
}

अटल पूर्णांक read_ar_header(पूर्णांक fd, पूर्णांक offset, ArchiveHeader *hdr)
{
    अक्षर *p, *e;
    पूर्णांक len;
    lseek(fd, offset, शुरू_से);
    len = full_read(fd, hdr, माप(ArchiveHeader));
    अगर (len != माप(ArchiveHeader))
        वापस len ? -1 : 0;
    अगर (स_भेद(hdr->ar_fmag, ARFMAG, माप hdr->ar_fmag))
        वापस -1;
    p = hdr->ar_name;
    क्रम (e = p + माप hdr->ar_name; e > p && e[-1] == ' ';)
        --e;
    *e = '\0';
    hdr->ar_आकार[माप hdr->ar_आकार-1] = 0;
    वापस len;
}

/* load only the objects which resolve undefined symbols */
अटल पूर्णांक tcc_load_alacarte(TCCState *s1, पूर्णांक fd, पूर्णांक आकार, पूर्णांक entrysize)
{
    पूर्णांक i, bound, nsyms, sym_सूचकांक, len, ret = -1;
    अचिन्हित दीर्घ दीर्घ off;
    uint8_t *तथ्य;
    स्थिर अक्षर *ar_names, *p;
    स्थिर uint8_t *ar_सूचकांक;
    ElfW(Sym) *sym;
    ArchiveHeader hdr;

    तथ्य = tcc_malloc(आकार);
    अगर (full_read(fd, तथ्य, आकार) != आकार)
        जाओ invalid;
    nsyms = get_be(तथ्य, entrysize);
    ar_सूचकांक = तथ्य + entrysize;
    ar_names = (अक्षर *) ar_सूचकांक + nsyms * entrysize;

    करो {
        bound = 0;
        क्रम (p = ar_names, i = 0; i < nsyms; i++, p += म_माप(p)+1) {
            Section *s = symtab_section;
            sym_सूचकांक = find_elf_sym(s, p);
            अगर (!sym_सूचकांक)
                जारी;
            sym = &((ElfW(Sym) *)s->तथ्य)[sym_सूचकांक];
            अगर(sym->st_shndx != SHN_UNDEF)
                जारी;
            off = get_be(ar_सूचकांक + i * entrysize, entrysize);
            len = read_ar_header(fd, off, &hdr);
            अगर (len <= 0 || स_भेद(hdr.ar_fmag, ARFMAG, 2)) {
        invalid:
                tcc_error_noabort("invalid archive");
                जाओ the_end;
            }
            off += len;
            अगर (s1->verbose == 2)
                म_लिखो("   -> %s\n", hdr.ar_name);
            अगर (tcc_load_object_file(s1, fd, off) < 0)
                जाओ the_end;
            ++bound;
        }
    } जबतक(bound);
    ret = 0;
 the_end:
    tcc_free(तथ्य);
    वापस ret;
}

/* load a '.a' file */
ST_FUNC पूर्णांक tcc_load_archive(TCCState *s1, पूर्णांक fd, पूर्णांक alacarte)
{
    ArchiveHeader hdr;
    /* char magic[8]; */
    पूर्णांक आकार, len;
    अचिन्हित दीर्घ file_offset;
    ElfW(Ehdr) ehdr;

    /* skip magic which was already checked */
    /* full_read(fd, magic, sizeof(magic)); */
    file_offset = माप ARMAG - 1;

    क्रम(;;) {
        len = read_ar_header(fd, file_offset, &hdr);
        अगर (len == 0)
            वापस 0;
        अगर (len < 0)
            वापस tcc_error_noabort("invalid archive");
        file_offset += len;
        आकार = म_से_दीर्घ(hdr.ar_आकार, शून्य, 0);
        अगर (alacarte) {
            /* coff symbol table : we handle it */
            अगर (!म_भेद(hdr.ar_name, "/"))
                वापस tcc_load_alacarte(s1, fd, आकार, 4);
            अगर (!म_भेद(hdr.ar_name, "/SYM64/"))
                वापस tcc_load_alacarte(s1, fd, आकार, 8);
        } अन्यथा अगर (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
            अगर (s1->verbose == 2)
                म_लिखो("   -> %s\n", hdr.ar_name);
            अगर (tcc_load_object_file(s1, fd, file_offset) < 0)
                वापस -1;
        }
        /* align to even */
        file_offset = (file_offset + आकार + 1) & ~1;
    }
}

#अगर_अघोषित ELF_OBJ_ONLY
/* Set LV[I] to the global index of sym-version (LIB,VERSION).  Maybe resizes
   LV, maybe create a new entry for (LIB,VERSION).  */
अटल व्योम set_ver_to_ver(TCCState *s1, पूर्णांक *n, पूर्णांक **lv, पूर्णांक i, अक्षर *lib, अक्षर *version)
{
    जबतक (i >= *n) {
        *lv = tcc_realloc(*lv, (*n + 1) * माप(**lv));
        (*lv)[(*n)++] = -1;
    }
    अगर ((*lv)[i] == -1) {
        पूर्णांक v, पूर्व_same_lib = -1;
        क्रम (v = 0; v < nb_sym_versions; v++) {
            अगर (म_भेद(sym_versions[v].lib, lib))
              जारी;
            पूर्व_same_lib = v;
            अगर (!म_भेद(sym_versions[v].version, version))
              अवरोध;
        }
        अगर (v == nb_sym_versions) {
            sym_versions = tcc_realloc (sym_versions,
                                        (v + 1) * माप(*sym_versions));
            sym_versions[v].lib = tcc_strdup(lib);
            sym_versions[v].version = tcc_strdup(version);
            sym_versions[v].out_सूचकांक = 0;
            sym_versions[v].पूर्व_same_lib = पूर्व_same_lib;
            nb_sym_versions++;
        }
        (*lv)[i] = v;
    }
}

/* Associates symbol SYM_INDEX (in dynsymtab) with sym-version index
   VERNDX.  */
अटल व्योम
set_sym_version(TCCState *s1, पूर्णांक sym_सूचकांक, पूर्णांक verndx)
{
    अगर (sym_सूचकांक >= nb_sym_to_version) {
        पूर्णांक newelems = sym_सूचकांक ? sym_सूचकांक * 2 : 1;
        sym_to_version = tcc_realloc(sym_to_version,
                                     newelems * माप(*sym_to_version));
        स_रखो(sym_to_version + nb_sym_to_version, -1,
               (newelems - nb_sym_to_version) * माप(*sym_to_version));
        nb_sym_to_version = newelems;
    }
    अगर (sym_to_version[sym_सूचकांक] < 0)
      sym_to_version[sym_सूचकांक] = verndx;
}

काष्ठा versym_info {
    पूर्णांक nb_versyms;
    ElfW(Verdef) *verdef;
    ElfW(Verneed) *verneed;
    ElfW(Half) *versym;
    पूर्णांक nb_local_ver, *local_ver;
};


अटल व्योम store_version(TCCState *s1, काष्ठा versym_info *v, अक्षर *dynstr)
{
    अक्षर *lib, *version;
    uint32_t अग्र;
    पूर्णांक i;

#घोषणा	DEBUG_VERSION 0

    अगर (v->versym && v->verdef) {
      ElfW(Verdef) *vdef = v->verdef;
      lib = शून्य;
      करो {
        ElfW(Verdaux) *verdaux =
	  (ElfW(Verdaux) *) (((अक्षर *) vdef) + vdef->vd_aux);

#अगर DEBUG_VERSION
	म_लिखो ("verdef: version:%u flags:%u index:%u, hash:%u\n",
	        vdef->vd_version, vdef->vd_flags, vdef->vd_ndx,
		vdef->vd_hash);
#पूर्ण_अगर
	अगर (vdef->vd_cnt) {
          version = dynstr + verdaux->vda_name;

	  अगर (lib == शून्य)
	    lib = version;
	  अन्यथा
            set_ver_to_ver(s1, &v->nb_local_ver, &v->local_ver, vdef->vd_ndx,
                           lib, version);
#अगर DEBUG_VERSION
	  म_लिखो ("  verdaux(%u): %s\n", vdef->vd_ndx, version);
#पूर्ण_अगर
	}
        अग्र = vdef->vd_अग्र;
        vdef = (ElfW(Verdef) *) (((अक्षर *) vdef) + अग्र);
      } जबतक (अग्र);
    }
    अगर (v->versym && v->verneed) {
      ElfW(Verneed) *vneed = v->verneed;
      करो {
        ElfW(Vernaux) *vernaux =
	  (ElfW(Vernaux) *) (((अक्षर *) vneed) + vneed->vn_aux);

        lib = dynstr + vneed->vn_file;
#अगर DEBUG_VERSION
	म_लिखो ("verneed: %u %s\n", vneed->vn_version, lib);
#पूर्ण_अगर
	क्रम (i = 0; i < vneed->vn_cnt; i++) {
	  अगर ((vernaux->vna_other & 0x8000) == 0) { /* hidden */
              version = dynstr + vernaux->vna_name;
              set_ver_to_ver(s1, &v->nb_local_ver, &v->local_ver, vernaux->vna_other,
                             lib, version);
#अगर DEBUG_VERSION
	    म_लिखो ("  vernaux(%u): %u %u %s\n",
		    vernaux->vna_other, vernaux->vna_hash,
		    vernaux->vna_flags, version);
#पूर्ण_अगर
	  }
	  vernaux = (ElfW(Vernaux) *) (((अक्षर *) vernaux) + vernaux->vna_अग्र);
	}
        अग्र = vneed->vn_अग्र;
        vneed = (ElfW(Verneed) *) (((अक्षर *) vneed) + अग्र);
      } जबतक (अग्र);
    }

#अगर DEBUG_VERSION
    क्रम (i = 0; i < v->nb_local_ver; i++) {
      अगर (v->local_ver[i] > 0) {
        म_लिखो ("%d: lib: %s, version %s\n",
		i, sym_versions[v->local_ver[i]].lib,
                sym_versions[v->local_ver[i]].version);
      }
    }
#पूर्ण_अगर
}

/* load a library / DLL
   'level = 0' means that the DLL is referenced by the user
   (so it should be added as DT_NEEDED in the generated ELF file) */
ST_FUNC पूर्णांक tcc_load_dll(TCCState *s1, पूर्णांक fd, स्थिर अक्षर *filename, पूर्णांक level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    पूर्णांक i, nb_syms, nb_dts, sym_bind, ret = -1;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;

    अक्षर *dynstr;
    पूर्णांक sym_सूचकांक;
    स्थिर अक्षर *name, *soname;
    काष्ठा versym_info v;

    full_read(fd, &ehdr, माप(ehdr));

    /* test CPU specific stuff */
    अगर (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
        वापस tcc_error_noabort("bad architecture");
    }

    /* read sections */
    shdr = load_तथ्य(fd, ehdr.e_shoff, माप(ElfW(Shdr)) * ehdr.e_shnum);

    /* load dynamic section and dynamic symbols */
    nb_syms = 0;
    nb_dts = 0;
    dynamic = शून्य;
    dynsym = शून्य; /* avoid warning */
    dynstr = शून्य; /* avoid warning */
    स_रखो(&v, 0, माप v);

    क्रम(i = 0, sh = shdr; i < ehdr.e_shnum; i++, sh++) {
        चयन(sh->sh_type) {
        हाल SHT_DYNAMIC:
            nb_dts = sh->sh_आकार / माप(ElfW(Dyn));
            dynamic = load_तथ्य(fd, sh->sh_offset, sh->sh_आकार);
            अवरोध;
        हाल SHT_DYNSYM:
            nb_syms = sh->sh_आकार / माप(ElfW(Sym));
            dynsym = load_तथ्य(fd, sh->sh_offset, sh->sh_आकार);
            sh1 = &shdr[sh->sh_link];
            dynstr = load_तथ्य(fd, sh1->sh_offset, sh1->sh_आकार);
            अवरोध;
        हाल SHT_GNU_verdef:
	    v.verdef = load_तथ्य(fd, sh->sh_offset, sh->sh_आकार);
	    अवरोध;
        हाल SHT_GNU_verneed:
	    v.verneed = load_तथ्य(fd, sh->sh_offset, sh->sh_आकार);
	    अवरोध;
        हाल SHT_GNU_versym:
            v.nb_versyms = sh->sh_आकार / माप(ElfW(Half));
	    v.versym = load_तथ्य(fd, sh->sh_offset, sh->sh_आकार);
	    अवरोध;
        शेष:
            अवरोध;
        }
    }

    अगर (!dynamic)
        जाओ the_end;

    /* compute the real library name */
    soname = tcc_basename(filename);
    क्रम(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        अगर (dt->d_tag == DT_SONAME)
            soname = dynstr + dt->d_un.d_val;

    /* if the dll is already loaded, do not load it */
    अगर (tcc_add_dllref(s1, soname, level)->found)
        जाओ ret_success;

    अगर (v.nb_versyms != nb_syms)
        tcc_free (v.versym), v.versym = शून्य;
    अन्यथा
        store_version(s1, &v, dynstr);

    /* add dynamic symbols in dynsym_section */
    क्रम(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        अगर (sym_bind == STB_LOCAL)
            जारी;
        name = dynstr + sym->st_name;
        sym_सूचकांक = set_elf_sym(s1->dynsymtab_section, sym->st_मूल्य, sym->st_आकार,
                                sym->st_info, sym->st_other, sym->st_shndx, name);
        अगर (v.versym) {
            ElfW(Half) vsym = v.versym[i];
            अगर ((vsym & 0x8000) == 0 && vsym > 0 && vsym < v.nb_local_ver)
                set_sym_version(s1, sym_सूचकांक, v.local_ver[vsym]);
        }
    }

    /* do not load all referenced libraries
       (recursive loading can break linking of libraries) */
    /* following DT_NEEDED is needed for the dynamic loader (libdl.so),
       but it is no longer needed, when linking a library or a program.
       When tcc output mode is OUTPUT_MEM,
       tcc calls dlopen, which handles DT_NEEDED for us */

#अगर 0
    क्रम(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        अगर (dt->d_tag == DT_RPATH)
            tcc_add_library_path(s1, dynstr + dt->d_un.d_val);

    /* load all referenced DLLs */
    क्रम(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        चयन(dt->d_tag) {
        हाल DT_NEEDED:
            name = dynstr + dt->d_un.d_val;
            अगर (tcc_add_dllref(s1, name, -1))
                जारी;
            अगर (tcc_add_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                ret = tcc_error_noabort("referenced dll '%s' not found", name);
                जाओ the_end;
            }
        }
    }
#पूर्ण_अगर

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
    वापस ret;
}

#घोषणा LD_TOK_NAME 256
#घोषणा LD_TOK_EOF  (-1)
अटल पूर्णांक ld_inp(TCCState *s1)
{
    पूर्णांक c = *s1->ld_p;
    अगर (c == 0)
        वापस CH_EOF;
    ++s1->ld_p;
    वापस c;
}
#घोषणा ld_unget(s1, ch) अगर (ch != CH_EOF) --s1->ld_p

/* return next ld script token */
अटल पूर्णांक ld_अग्र(TCCState *s1, अक्षर *name, पूर्णांक name_आकार)
{
    पूर्णांक c, d, ch;
    अक्षर *q;

 redo:
    ch = ld_inp(s1);
    q = name, *q++ = ch;
    चयन(ch) {
    हाल ' ':
    हाल '\t':
    हाल '\f':
    हाल '\v':
    हाल '\r':
    हाल '\n':
        जाओ redo;
    हाल '/':
        ch = ld_inp(s1);
        अगर (ch == '*') { /* comment */
            क्रम (d = 0;; d = ch) {
                ch = ld_inp(s1);
                अगर (ch == CH_EOF || (ch == '/' && d == '*'))
                    अवरोध;
            }
            जाओ redo;
        } अन्यथा {
            जाओ parse_name;
        }
        अवरोध;
    हाल '\\':
    /* case 'a' ... 'z': */
    हाल 'a':
       हाल 'b':
       हाल 'c':
       हाल 'd':
       हाल 'e':
       हाल 'f':
       हाल 'g':
       हाल 'h':
       हाल 'i':
       हाल 'j':
       हाल 'k':
       हाल 'l':
       हाल 'm':
       हाल 'n':
       हाल 'o':
       हाल 'p':
       हाल 'q':
       हाल 'r':
       हाल 's':
       हाल 't':
       हाल 'u':
       हाल 'v':
       हाल 'w':
       हाल 'x':
       हाल 'y':
       हाल 'z':
    /* case 'A' ... 'z': */
    हाल 'A':
       हाल 'B':
       हाल 'C':
       हाल 'D':
       हाल 'E':
       हाल 'F':
       हाल 'G':
       हाल 'H':
       हाल 'I':
       हाल 'J':
       हाल 'K':
       हाल 'L':
       हाल 'M':
       हाल 'N':
       हाल 'O':
       हाल 'P':
       हाल 'Q':
       हाल 'R':
       हाल 'S':
       हाल 'T':
       हाल 'U':
       हाल 'V':
       हाल 'W':
       हाल 'X':
       हाल 'Y':
       हाल 'Z':
    हाल '-':
    हाल '_':
    हाल '.':
    हाल '$':
    हाल '~':
        क्रम(;;) {
            ch = ld_inp(s1);
    parse_name:
            अगर (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') ||
                  म_अक्षर("/.-_+=$:\\,~", ch)))
                अवरोध;
            अगर ((q - name) < name_आकार - 1) {
                *q++ = ch;
            }
        }
        ld_unget(s1, ch);
        c = LD_TOK_NAME;
        अवरोध;
    हाल CH_EOF:
        c = LD_TOK_EOF;
        अवरोध;
    शेष:
        c = ch;
        अवरोध;
    }
    *q = '\0';
    वापस c;
}

अटल पूर्णांक ld_add_file(TCCState *s1, स्थिर अक्षर filename[])
{
    अगर (filename[0] == '-' && filename[1] == 'l')
        वापस tcc_add_library(s1, filename + 2);
    अगर (CONFIG_SYSROOT[0] != '\0' || !IS_ABSPATH(filename)) {
        /* lookup via library paths */
        पूर्णांक ret = tcc_add_dll(s1, tcc_basename(filename), 0);
        अगर (ret != FILE_NOT_FOUND)
            वापस ret;
    }
    वापस tcc_add_file_internal(s1, filename, AFF_PRINT_ERROR);
}

/* did static libraries add new undefined symbols? */
अटल पूर्णांक new_undef_sym(TCCState *s1, पूर्णांक sym_offset)
{
    जबतक (sym_offset < s1->symtab->तथ्य_offset) {
        ElfW(Sym) *esym = (व्योम*)(s1->symtab->तथ्य + sym_offset);
        अगर (esym->st_shndx == SHN_UNDEF)
            वापस 1;
        sym_offset += माप (ElfW(Sym));
    }
    वापस 0;
}

अटल पूर्णांक ld_add_file_list(TCCState *s1, स्थिर अक्षर *cmd)
{
    अक्षर filename[1024];
    पूर्णांक t, c, sym_offset, ret = 0;
    अचिन्हित अक्षर *pos = s1->ld_p;

repeat:
    s1->ld_p = pos;
    sym_offset = s1->symtab->तथ्य_offset;
    c = cmd[0];

    t = ld_अग्र(s1, filename, माप(filename));
    अगर (t != '(')
        वापस tcc_error_noabort("expected '(' after %s", cmd);
    t = ld_अग्र(s1, filename, माप(filename));
    क्रम(;;) {
        अगर (t == LD_TOK_EOF) {
            वापस tcc_error_noabort("unexpected end of file");
        } अन्यथा अगर (t == ')') {
            अवरोध;
        } अन्यथा अगर (t != LD_TOK_NAME) {
            वापस tcc_error_noabort("unexpected token '%c'", t);
        } अन्यथा अगर (!म_भेद(filename, "AS_NEEDED")) {
            ret |= ld_add_file_list(s1, filename);
        } अन्यथा अगर (c == 'I' || c == 'G' || c == 'A') {
            ret |= !!ld_add_file(s1, filename);
        }
        अगर (ret < 0)
            वापस ret;
        t = ld_अग्र(s1, filename, माप(filename));
        अगर (t == ',')
            t = ld_अग्र(s1, filename, माप(filename));
    }
    अगर (c == 'G' && ret == 0 && new_undef_sym(s1, sym_offset))
        जाओ repeat;
    वापस ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC पूर्णांक tcc_load_ldscript(TCCState *s1, पूर्णांक fd)
{
    अक्षर cmd[64];
    पूर्णांक t, ret = 0, noscript = 1;
    अचिन्हित अक्षर *text_ptr, *saved_ptr;

    saved_ptr = s1->ld_p;
    s1->ld_p = text_ptr = (व्योम*)tcc_load_text(fd);
    क्रम(;;) {
        t = ld_अग्र(s1, cmd, माप(cmd));
        अगर (t == LD_TOK_EOF)
            अवरोध;
        अगर (!म_भेद(cmd, "INPUT") ||
            !म_भेद(cmd, "GROUP")) {
            ret |= ld_add_file_list(s1, cmd);
        } अन्यथा अगर (!म_भेद(cmd, "OUTPUT_FORMAT") ||
                   !म_भेद(cmd, "TARGET")) {
            /* ignore some commands */
            ret |= ld_add_file_list(s1, cmd);
        } अन्यथा अगर (noscript) {
            ret = FILE_NOT_RECOGNIZED;
        } अन्यथा {
            ret = tcc_error_noabort("unexpected '%s'", cmd);
        }
        अगर (ret < 0)
            अवरोध;
        noscript = 0;
    }
    tcc_free(text_ptr);
    s1->ld_p = saved_ptr;
    वापस ret < 0 ? ret : -ret;
}
#पूर्ण_अगर /* !ELF_OBJ_ONLY */
