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

#ಅನ್ತರ್ಭಾವ "tcc.h"

/* Define this to get some debug output during relocation processing.  */
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು DEBUG_RELOC

/********************************************************/
/* global variables */

/* elf version information */
ರಚನೆ sym_ಆವೃತ್ತಿ {
    ಅಕ್ಷರ *lib;
    ಅಕ್ಷರ *ಆವೃತ್ತಿ;
    ಪೂರ್ಣಾಂಕ ಹೊರಹೋಗು_ಸೂಚ್ಯಂಕ;
    ಪೂರ್ಣಾಂಕ prev_same_lib;
};

#ವ್ಯಾಖ್ಯಾನಿಸು nb_sym_versions     s1->nb_sym_versions
#ವ್ಯಾಖ್ಯಾನಿಸು sym_versions        s1->sym_versions
#ವ್ಯಾಖ್ಯಾನಿಸು nb_sym_ಗಮ್ಯ_ಆವೃತ್ತಿ   s1->nb_sym_ಗಮ್ಯ_ಆವೃತ್ತಿ
#ವ್ಯಾಖ್ಯಾನಿಸು sym_ಗಮ್ಯ_ಆವೃತ್ತಿ      s1->sym_ಗಮ್ಯ_ಆವೃತ್ತಿ
#ವ್ಯಾಖ್ಯಾನಿಸು dt_verneednum       s1->dt_verneednum
#ವ್ಯಾಖ್ಯಾನಿಸು versym_section      s1->versym_section
#ವ್ಯಾಖ್ಯಾನಿಸು verneed_section     s1->verneed_section

/* special flag to indicate that the section should not be linked to the other ones */
#ವ್ಯಾಖ್ಯಾನಿಸು SHF_ಖಾಸಗಿ 0x80000000
/* section is dynsymtab_section */
#ವ್ಯಾಖ್ಯಾನಿಸು SHF_DYNSYM 0x40000000

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
#ವ್ಯಾಖ್ಯಾನಿಸು shf_RELRO SHF_ALLOC
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ rdata[] = ".rdata";
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು shf_RELRO SHF_ALLOC /* eventually made SHF_WRITE in sort_sections() */
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ rdata[] = ".data.ro";
#ಆದರೆ_ಅಂತ್ಯ

/* ------------------------------------------------------------------------- */

ST_FUNC ಶೂನ್ಯ tccelf_new(TCCState *s)
{
    TCCState *s1 = s;

    /* no section zero */
    dynarray_ಕೂಡಿಸು(&s->sections, &s->nb_sections, ಖಾಲಿ);

    /* create standard sections */
    ಪಠ್ಯ_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    ದತ್ತಾಂಶ_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    /* create ro data section (make ro after relocation done with GNU_RELRO) */
    rodata_section = new_section(s, rdata, SHT_PROGBITS, shf_RELRO);
    bss_section = new_section(s, ".bss", SHT_NOBITS, SHF_ALLOC | SHF_WRITE);
    common_section = new_section(s, ".common", SHT_NOBITS, SHF_ಖಾಸಗಿ);
    common_section->sh_ಅಂಕೆ = SHN_COMMON;

    /* symbols are always generated for linking stage */
    symtab_section = new_symtab(s, ".symtab", SHT_SYMTAB, 0,
                                ".strtab",
                                ".hashtab", SHF_ಖಾಸಗಿ);

    /* private symbol table for dynamic symbols */
    s->dynsymtab_section = new_symtab(s, ".dynsymtab", SHT_SYMTAB, SHF_ಖಾಸಗಿ|SHF_DYNSYM,
                                      ".dynstrtab",
                                      ".dynhashtab", SHF_ಖಾಸಗಿ);
    get_sym_attr(s, 0, 1);

    ಆದರೆ (s->do_debug) {
        /* add debug sections */
        tcc_debug_new(s);
    }

#ಆದರೆ TCC_EH_ಚೌಕಟ್ಟು
    ಆದರೆ (s->output_format != TCC_OUTPUT_FORMAT_ELF)
        s->unwind_tables = 0;
    tcc_eh_ಚೌಕಟ್ಟು_ಆರಂಭ(s);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        /* (make ro after relocation done with GNU_RELRO) */
        bounds_section = new_section(s, ".bounds", SHT_PROGBITS, shf_RELRO);
        lbounds_section = new_section(s, ".lbounds", SHT_PROGBITS, shf_RELRO);
    }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    /* to make sure that -ltcc1 -Wl,-e,_start will grab the startup code
       from libtcc1.a (unless _start defined) */
    ಆದರೆ (s->elf_entryname)
        ಗಣ_global_sym(s, s->elf_entryname, ಖಾಲಿ, 0); /* SHN_UNDEF */
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
    ಆದರೆ (ಖಾಲಿ == s->elfint && s1->output_type != TCC_OUTPUT_OBJ) {
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p = CONFIG_TCC_ELFINTERP;
#ಆದರೆ defined TCC_ಗುರಿ_ARM && defined CONFIG_TCC_ELFINTERP_ARMHF
        ಆದರೆ (s->float_abi == ARM_HARD_FLOAT)
            p = CONFIG_TCC_ELFINTERP_ARMHF;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ defined TCC_IS_NATIVE && defined TARGETOS_BSD
        /* see commit 55cb2170cd5ce77a7d76dcaf462fad2707281605 */
        { ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *e = getenv("LD_SO"); ಆದರೆ (e) p = e; }
#ಆದರೆ_ಅಂತ್ಯ
        s->elfint = tcc_strdup(p);
    }
#ಆದರೆ_ಅಂತ್ಯ /* ndef ELF_OBJ_ONLY */
}

ST_FUNC ಶೂನ್ಯ free_section(Section *s)
{
    ಆದರೆ (!s)
        ಹಿಂತಿರುಗಿ;
    tcc_free(s->ದತ್ತಾಂಶ);
    s->ದತ್ತಾಂಶ = ಖಾಲಿ;
    s->ದತ್ತಾಂಶ_allocated = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = 0;
}

ST_FUNC ಶೂನ್ಯ tccelf_delete(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ i;

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
    /* free symbol versions */
    ಗಾಗಿ (i = 0; i < nb_sym_versions; i++) {
        tcc_free(sym_versions[i].ಆವೃತ್ತಿ);
        tcc_free(sym_versions[i].lib);
    }
    tcc_free(sym_versions);
    tcc_free(sym_ಗಮ್ಯ_ಆವೃತ್ತಿ);
#ಆದರೆ_ಅಂತ್ಯ

    /* free all sections */
    ಗಾಗಿ(i = 1; i < s1->nb_sections; i++)
        free_section(s1->sections[i]);
    dynarray_reset(&s1->sections, &s1->nb_sections);

    ಗಾಗಿ(i = 0; i < s1->nb_priv_sections; i++)
        free_section(s1->priv_sections[i]);
    dynarray_reset(&s1->priv_sections, &s1->nb_priv_sections);

    tcc_free(s1->sym_attrs);
    symtab_section = ಖಾಲಿ; /* for tccrun.c:rt_printline() */
}

/* save section data state */
ST_FUNC ಶೂನ್ಯ tccelf_begin_file(TCCState *s1)
{
    Section *s; ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        s->sh_ಸ್ಥಾನಾಂತರ = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    }
    /* disable symbol hashing during compilation */
    s = s1->symtab, s->reloc = s->hash, s->hash = ಖಾಲಿ;
#ಆದರೆ defined TCC_ಗುರಿ_X86_64 && defined TCC_ಗುರಿ_PE
    s1->uw_sym = 0;
    s1->uw_offs = 0;
#ಆದರೆ_ಅಂತ್ಯ
}

ಸ್ಥಿರ ಶೂನ್ಯ update_relocs(TCCState *s1, Section *s, ಪೂರ್ಣಾಂಕ *old_ಗಮ್ಯ_new_syms, ಪೂರ್ಣಾಂಕ ಮೊದಲ_sym);

/* At the end of compilation, convert any UNDEF syms to global, and merge
   with previously existing symbols */
ST_FUNC ಶೂನ್ಯ tccelf_ಕೊನೆ_file(TCCState *s1)
{
    Section *s = s1->symtab;
    ಪೂರ್ಣಾಂಕ ಮೊದಲ_sym, nb_syms, *tr, i;

    ಮೊದಲ_sym = s->sh_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ (ElfSym);
    nb_syms = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ (ElfSym) - ಮೊದಲ_sym;
    s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = s->sh_ಸ್ಥಾನಾಂತರ;
    s->link->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = s->link->sh_ಸ್ಥಾನಾಂತರ;
    s->hash = s->reloc, s->reloc = ಖಾಲಿ;
    tr = tcc_mallocz(nb_syms * ಗಾತ್ರ *tr);

    ಗಾಗಿ (i = 0; i < nb_syms; ++i) {
        ElfSym *sym = (ElfSym*)s->ದತ್ತಾಂಶ + ಮೊದಲ_sym + i;
        ಆದರೆ (sym->st_shndx == SHN_UNDEF) {
            ಪೂರ್ಣಾಂಕ sym_bind = ELFW(ST_BIND)(sym->st_info);
            ಪೂರ್ಣಾಂಕ sym_type = ELFW(ST_TYPE)(sym->st_info);
            ಆದರೆ (sym_bind == STB_LOCAL)
                sym_bind = STB_GLOBAL;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_PE
            ಆದರೆ (sym_bind == STB_GLOBAL && s1->output_type == TCC_OUTPUT_OBJ) {
                /* undefined symbols with STT_FUNC are confusing gnu ld when
                   linking statically to STT_GNU_IFUNC.  Keep TLS typed,
                   otherwise gnu ld rejects non-TLS refs to TLS definitions. */
                ಆದರೆ (sym_type != STT_TLS)
                    sym_type = STT_NOTYPE;
            }
#ಆದರೆ_ಅಂತ್ಯ
            sym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
        }
        tr[i] = ಗಣ_elf_sym(s, sym->st_ಮೌಲ್ಯ, sym->st_ಗಾತ್ರ, sym->st_info,
            sym->st_other, sym->st_shndx, (ಅಕ್ಷರ*)s->link->ದತ್ತಾಂಶ + sym->st_name);
    }
    /* now update relocations */
    update_relocs(s1, s, tr, ಮೊದಲ_sym);
    tcc_free(tr);
    /* record text/data/bss output for -bench info */
    ಗಾಗಿ (i = 0; i < 4; ++i) {
        s = s1->sections[i + 1];
        s1->ಒಟ್ಟು_output[i] += s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - s->sh_ಸ್ಥಾನಾಂತರ;
    }
}

ST_FUNC Section *new_section(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, ಪೂರ್ಣಾಂಕ sh_type, ಪೂರ್ಣಾಂಕ sh_flags)
{
    Section *sec;

    sec = tcc_mallocz(ಗಾತ್ರ(Section) + ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name));
    sec->s1 = s1;
    strcpy(sec->name, name);
    sec->sh_type = sh_type;
    sec->sh_flags = sh_flags;
    ಆಯ್ಕೆ(sh_type) {
    ಸ್ಥಿತಿ SHT_GNU_versym:
        sec->sh_addralign = 2;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ SHT_HASH:
    ಸ್ಥಿತಿ SHT_GNU_HASH:
    ಸ್ಥಿತಿ SHT_REL:
    ಸ್ಥಿತಿ SHT_RELA:
    ಸ್ಥಿತಿ SHT_DYNSYM:
    ಸ್ಥಿತಿ SHT_SYMTAB:
    ಸ್ಥಿತಿ SHT_DYNAMIC:
    ಸ್ಥಿತಿ SHT_GNU_verneed:
    ಸ್ಥಿತಿ SHT_GNU_verdef:
        sec->sh_addralign = PTR_ಗಾತ್ರ;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ SHT_STRTAB:
        sec->sh_addralign = 1;
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        sec->sh_addralign =  PTR_ಗಾತ್ರ; /* gcc/pcc default alignment */
        ನಿಲ್ಲಿಸು;
    }

    ಆದರೆ (sh_flags & SHF_ಖಾಸಗಿ) {
        dynarray_ಕೂಡಿಸು(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } ಇಲ್ಲದಿದ್ದರೆ {
        sec->sh_ಅಂಕೆ = s1->nb_sections;
        dynarray_ಕೂಡಿಸು(&s1->sections, &s1->nb_sections, sec);
    }

    ಹಿಂತಿರುಗಿ sec;
}

ST_FUNC ಶೂನ್ಯ init_symtab(Section *s)
{
    ಪೂರ್ಣಾಂಕ *ptr, nb_buckets = 1;
    put_elf_str(s->link, "");
    section_ptr_ಕೂಡಿಸು(s, ಗಾತ್ರ (ElfW(Sym)));
    ptr = section_ptr_ಕೂಡಿಸು(s->hash, (2 + nb_buckets + 1) * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));
    ptr[0] = nb_buckets;
    ptr[1] = 1;
    memset(ptr + 2, 0, (nb_buckets + 1) * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));
}

ST_FUNC Section *new_symtab(TCCState *s1,
                           ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *symtab_name, ಪೂರ್ಣಾಂಕ sh_type, ಪೂರ್ಣಾಂಕ sh_flags,
                           ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *strtab_name,
                           ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *hash_name, ಪೂರ್ಣಾಂಕ hash_sh_flags)
{
    Section *symtab, *strtab, *hash;
    symtab = new_section(s1, symtab_name, sh_type, sh_flags);
    symtab->sh_entsize = ಗಾತ್ರ(ElfW(Sym));
    strtab = new_section(s1, strtab_name, SHT_STRTAB, sh_flags);
    symtab->link = strtab;
    hash = new_section(s1, hash_name, SHT_HASH, hash_sh_flags);
    hash->sh_entsize = ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ);
    symtab->hash = hash;
    hash->link = symtab;
    init_symtab(symtab);
    ಹಿಂತಿರುಗಿ symtab;
}

/* realloc section and set its content to zero */
ST_FUNC ಶೂನ್ಯ section_realloc(Section *sec, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ new_ಗಾತ್ರ)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ದತ್ತಾಂಶ;

    ಗಾತ್ರ_2 = sec->ದತ್ತಾಂಶ_allocated;
    ಆದರೆ (ಗಾತ್ರ_2 == 0)
        ಗಾತ್ರ_2 = 1;
    ಆಗ (ಗಾತ್ರ_2 < new_ಗಾತ್ರ)
        ಗಾತ್ರ_2 = ಗಾತ್ರ_2 * 2;
    ದತ್ತಾಂಶ = tcc_realloc(sec->ದತ್ತಾಂಶ, ಗಾತ್ರ_2);
    memset(ದತ್ತಾಂಶ + sec->ದತ್ತಾಂಶ_allocated, 0, ಗಾತ್ರ_2 - sec->ದತ್ತಾಂಶ_allocated);
    sec->ದತ್ತಾಂಶ = ದತ್ತಾಂಶ;
    sec->ದತ್ತಾಂಶ_allocated = ಗಾತ್ರ_2;
}

/* reserve at least 'size' bytes aligned per 'align' in section
   'sec' from current offset, and return the aligned offset */
ST_FUNC ಗಾತ್ರ_t section_ಕೂಡಿಸು(Section *sec, addr_t ಗಾತ್ರ_2, ಪೂರ್ಣಾಂಕ align)
{
    ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ, offset1;

    ಸ್ಥಾನಾಂತರ = (sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ + align - 1) & -align;
    offset1 = ಸ್ಥಾನಾಂತರ + ಗಾತ್ರ_2;
    ಆದರೆ (sec->sh_type != SHT_NOBITS && offset1 > sec->ದತ್ತಾಂಶ_allocated)
        section_realloc(sec, offset1);
    sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = offset1;
    ಆದರೆ (align > sec->sh_addralign)
        sec->sh_addralign = align;
    ಹಿಂತಿರುಗಿ ಸ್ಥಾನಾಂತರ;
}

/* reserve at least 'size' bytes in section 'sec' from
   sec->data_offset. */
ST_FUNC ಶೂನ್ಯ *section_ptr_ಕೂಡಿಸು(Section *sec, addr_t ಗಾತ್ರ_2)
{
    ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ = section_ಕೂಡಿಸು(sec, ಗಾತ್ರ_2, 1);
    ಹಿಂತಿರುಗಿ sec->ದತ್ತಾಂಶ + ಸ್ಥಾನಾಂತರ;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
/* reserve at least 'size' bytes from section start */
ಸ್ಥಿರ ಶೂನ್ಯ section_reserve(Section *sec, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2)
{
    ಆದರೆ (ಗಾತ್ರ_2 > sec->ದತ್ತಾಂಶ_allocated)
        section_realloc(sec, ಗಾತ್ರ_2);
    ಆದರೆ (ಗಾತ್ರ_2 > sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ)
        sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = ಗಾತ್ರ_2;
}
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ Section *have_section(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name)
{
    Section *sec;
    ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ(i = 1; i < s1->nb_sections; i++) {
        sec = s1->sections[i];
        ಆದರೆ (!strcmp(name, sec->name))
            ಹಿಂತಿರುಗಿ sec;
    }
    ಹಿಂತಿರುಗಿ ಖಾಲಿ;
}

/* return a reference to a section, and create it if it does not
   exists */
ST_FUNC Section *ಕಂಡುಹಿಡಿ_section(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name)
{
    Section *sec = have_section(s1, name);
    ಆದರೆ (sec)
        ಹಿಂತಿರುಗಿ sec;
    /* sections are created as PROGBITS */
    ಹಿಂತಿರುಗಿ new_section(s1, name, SHT_PROGBITS, SHF_ALLOC);
}

/* ------------------------------------------------------------------------- */

ST_FUNC ಪೂರ್ಣಾಂಕ put_elf_str(Section *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *sym)
{
    ಪೂರ್ಣಾಂಕ ಸ್ಥಾನಾಂತರ, len;
    ಅಕ್ಷರ *ptr;

    len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(sym) + 1;
    ಸ್ಥಾನಾಂತರ = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    ptr = section_ptr_ಕೂಡಿಸು(s, len);
    memmove(ptr, sym, len);
    ಹಿಂತಿರುಗಿ ಸ್ಥಾನಾಂತರ;
}

/* elf symbol hashing function */
ಸ್ಥಿರ ElfW(ಶಬ್ದ_2) elf_hash(ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *name)
{
    ElfW(ಶಬ್ದ_2) h = 0, g;

    ಆಗ (*name) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        ಆದರೆ (g)
            h ^= g >> 24;
        h &= ~g;
    }
    ಹಿಂತಿರುಗಿ h;
}

/* rebuild hash table of section s */
/* NOTE: we do factorize the hash table code to go faster */
ಸ್ಥಿರ ಶೂನ್ಯ rebuild_hash(Section *s, ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ nb_buckets)
{
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಂಕ *ptr, *hash, nb_syms, sym_ಸೂಚ್ಯಂಕ, h;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *strtab;

    strtab = s->link->ದತ್ತಾಂಶ;
    nb_syms = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ(ElfW(Sym));

    ಆದರೆ (!nb_buckets)
        nb_buckets = ((ಪೂರ್ಣಾಂಕ*)s->hash->ದತ್ತಾಂಶ)[0];

    s->hash->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = 0;
    ptr = section_ptr_ಕೂಡಿಸು(s->hash, (2 + nb_buckets + nb_syms) * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    memset(hash, 0, (nb_buckets + 1) * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));
    ptr += nb_buckets + 1;

    sym = (ElfW(Sym) *)s->ದತ್ತಾಂಶ + 1;
    ಗಾಗಿ(sym_ಸೂಚ್ಯಂಕ = 1; sym_ಸೂಚ್ಯಂಕ < nb_syms; sym_ಸೂಚ್ಯಂಕ++) {
        ಆದರೆ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            h = elf_hash(strtab + sym->st_name) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_ಸೂಚ್ಯಂಕ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}

/* return the symbol number */
ST_FUNC ಪೂರ್ಣಾಂಕ put_elf_sym(Section *s, addr_t ಮೌಲ್ಯ, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2,
    ಪೂರ್ಣಾಂಕ info, ಪೂರ್ಣಾಂಕ other, ಪೂರ್ಣಾಂಕ shndx, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name)
{
    ಪೂರ್ಣಾಂಕ name_ಸ್ಥಾನಾಂತರ, sym_ಸೂಚ್ಯಂಕ;
    ಪೂರ್ಣಾಂಕ nbuckets, h;
    ElfW(Sym) *sym;
    Section *hs;

    sym = section_ptr_ಕೂಡಿಸು(s, ಗಾತ್ರ(ElfW(Sym)));
    ಆದರೆ (name && name[0])
        name_ಸ್ಥಾನಾಂತರ = put_elf_str(s->link, name);
    ಇಲ್ಲದಿದ್ದರೆ
        name_ಸ್ಥಾನಾಂತರ = 0;
    /* XXX: endianness */
    sym->st_name = name_ಸ್ಥಾನಾಂತರ;
    sym->st_ಮೌಲ್ಯ = ಮೌಲ್ಯ;
    sym->st_ಗಾತ್ರ = ಗಾತ್ರ_2;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
    sym_ಸೂಚ್ಯಂಕ = sym - (ElfW(Sym) *)s->ದತ್ತಾಂಶ;
    hs = s->hash;
    ಆದರೆ (hs) {
        ಪೂರ್ಣಾಂಕ *ptr, *ತಳ;
        ptr = section_ptr_ಕೂಡಿಸು(hs, ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));
        ತಳ = (ಪೂರ್ಣಾಂಕ *)hs->ದತ್ತಾಂಶ;
        /* only add global or weak symbols. */
        ಆದರೆ (ELFW(ST_BIND)(info) != STB_LOCAL) {
            /* add another hashing entry */
            nbuckets = ತಳ[0];
            h = elf_hash((ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *)s->link->ದತ್ತಾಂಶ + name_ಸ್ಥಾನಾಂತರ) % nbuckets;
            *ptr = ತಳ[2 + h];
            ತಳ[2 + h] = sym_ಸೂಚ್ಯಂಕ;
            ತಳ[1]++;
            /* we resize the hash table */
            hs->nb_hashed_syms++;
            ಆದರೆ (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            *ptr = 0;
            ತಳ[1]++;
        }
    }
    ಹಿಂತಿರುಗಿ sym_ಸೂಚ್ಯಂಕ;
}

ST_FUNC ಪೂರ್ಣಾಂಕ ಕಂಡುಹಿಡಿ_elf_sym(Section *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name)
{
    ElfW(Sym) *sym;
    Section *hs;
    ಪೂರ್ಣಾಂಕ nbuckets, sym_ಸೂಚ್ಯಂಕ, h;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name1;

    hs = s->hash;
    ಆದರೆ (!hs)
        ಹಿಂತಿರುಗಿ 0;
    nbuckets = ((ಪೂರ್ಣಾಂಕ *)hs->ದತ್ತಾಂಶ)[0];
    h = elf_hash((ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *) name) % nbuckets;
    sym_ಸೂಚ್ಯಂಕ = ((ಪೂರ್ಣಾಂಕ *)hs->ದತ್ತಾಂಶ)[2 + h];
    ಆಗ (sym_ಸೂಚ್ಯಂಕ != 0) {
        sym = &((ElfW(Sym) *)s->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
        name1 = (ಅಕ್ಷರ *) s->link->ದತ್ತಾಂಶ + sym->st_name;
        ಆದರೆ (!strcmp(name, name1))
            ಹಿಂತಿರುಗಿ sym_ಸೂಚ್ಯಂಕ;
        sym_ಸೂಚ್ಯಂಕ = ((ಪೂರ್ಣಾಂಕ *)hs->ದತ್ತಾಂಶ)[2 + nbuckets + sym_ಸೂಚ್ಯಂಕ];
    }
    ಹಿಂತಿರುಗಿ 0;
}

/* return elf symbol value, signal error if 'err' is nonzero, decorate
   name if FORC */
ST_FUNC addr_t get_sym_addr(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, ಪೂರ್ಣಾಂಕ err, ಪೂರ್ಣಾಂಕ forc)
{
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ;
    ElfW(Sym) *sym;
    ಅಕ್ಷರ buf[256];
    ಆದರೆ (forc && s1->leading_underscore
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        /* win32-32bit stdcall symbols always have _ already */
        && !strchr(name, '@')
#ಆದರೆ_ಅಂತ್ಯ
        ) {
        buf[0] = '_';
        pstrcpy(buf + 1, ಗಾತ್ರ(buf) - 1, name);
        name = buf;
    }
    sym_ಸೂಚ್ಯಂಕ = ಕಂಡುಹಿಡಿ_elf_sym(s1->symtab, name);
    sym = &((ElfW(Sym) *)s1->symtab->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
    ಆದರೆ (!sym_ಸೂಚ್ಯಂಕ || sym->st_shndx == SHN_UNDEF) {
        ಆದರೆ (err)
            tcc_error_noabort("%s not defined", name);
        ಹಿಂತಿರುಗಿ (addr_t)-1;
    }
    ಹಿಂತಿರುಗಿ sym->st_ಮೌಲ್ಯ;
}

/* return elf symbol value */
LIBTCCAPI ಶೂನ್ಯ *tcc_get_ಚಿಹ್ನೆ(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name)
{
    addr_t addr = get_sym_addr(s, name, 0, 1);
    ಹಿಂತಿರುಗಿ addr == -1 ? ಖಾಲಿ : (ಶೂನ್ಯ*)(uintptr_t)addr;
}

LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_ಚಿಹ್ನೆ(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *val)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s1, 0, name, (uintptr_t)val);
#ಇಲ್ಲದಿದ್ದರೆ
    ಅಕ್ಷರ buf[256];
    ಆದರೆ (s1->leading_underscore) {
        buf[0] = '_';
        pstrcpy(buf + 1, ಗಾತ್ರ(buf) - 1, name);
        name = buf;
    }
    ಗಣ_global_sym(s1, name, ಖಾಲಿ, (addr_t)(uintptr_t)val); /* NULL: SHN_ABS */
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ 0;
}

/* list elf symbol names and values */
ST_FUNC ಶೂನ್ಯ list_elf_symbols(TCCState *s, ಶೂನ್ಯ *ctx,
    ಶೂನ್ಯ (*ಚಿಹ್ನೆ_cb)(ಶೂನ್ಯ *ctx, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *val))
{
    ElfW(Sym) *sym;
    Section *symtab;
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ, ಕೊನೆ_sym;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ sym_vis, sym_bind;

    symtab = s->symtab;
    ಕೊನೆ_sym = symtab->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ (ElfSym);
    ಗಾಗಿ (sym_ಸೂಚ್ಯಂಕ = 0; sym_ಸೂಚ್ಯಂಕ < ಕೊನೆ_sym; ++sym_ಸೂಚ್ಯಂಕ) {
        sym = &((ElfW(Sym) *)symtab->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
        ಆದರೆ (sym->st_ಮೌಲ್ಯ) {
            name = (ಅಕ್ಷರ *) symtab->link->ದತ್ತಾಂಶ + sym->st_name;
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            sym_vis = ELFW(ST_VISIBILITY)(sym->st_other);
            ಆದರೆ (sym_bind == STB_GLOBAL && sym_vis == STV_DEFAULT)
                ಚಿಹ್ನೆ_cb(ctx, name, (ಶೂನ್ಯ*)(uintptr_t)sym->st_ಮೌಲ್ಯ);
        }
    }
}

/* list elf symbol names and values */
LIBTCCAPI ಶೂನ್ಯ tcc_list_symbols(TCCState *s, ಶೂನ್ಯ *ctx,
    ಶೂನ್ಯ (*ಚಿಹ್ನೆ_cb)(ಶೂನ್ಯ *ctx, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *val))
{
    list_elf_symbols(s, ctx, ಚಿಹ್ನೆ_cb);
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
ಸ್ಥಿರ ಶೂನ್ಯ
ಆವೃತ್ತಿ_ಕೂಡಿಸು (TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ i;
    ElfW(Sym) *sym;
    ElfW(Verneed) *vn = ಖಾಲಿ;
    Section *symtab;
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ, ಕೊನೆ_sym, nb_versions = 2, nb_entries = 0;
    ElfW(Half) *versym;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;

    ಆದರೆ (0 == nb_sym_versions)
        ಹಿಂತಿರುಗಿ;
    versym_section = new_section(s1, ".gnu.version", SHT_GNU_versym, SHF_ALLOC);
    versym_section->sh_entsize = ಗಾತ್ರ(ElfW(Half));
    versym_section->link = s1->dynsym;

    /* add needed symbols */
    symtab = s1->dynsym;
    ಕೊನೆ_sym = symtab->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ (ElfSym);
    versym = section_ptr_ಕೂಡಿಸು(versym_section, ಕೊನೆ_sym * ಗಾತ್ರ(ElfW(Half)));
    ಗಾಗಿ (sym_ಸೂಚ್ಯಂಕ = 1; sym_ಸೂಚ್ಯಂಕ < ಕೊನೆ_sym; ++sym_ಸೂಚ್ಯಂಕ) {
        ಪೂರ್ಣಾಂಕ dllindex, verndx;
        sym = &((ElfW(Sym) *)symtab->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
        name = (ಅಕ್ಷರ *) symtab->link->ದತ್ತಾಂಶ + sym->st_name;
        dllindex = ಕಂಡುಹಿಡಿ_elf_sym(s1->dynsymtab_section, name);
        verndx = (dllindex && dllindex < nb_sym_ಗಮ್ಯ_ಆವೃತ್ತಿ)
                 ? sym_ಗಮ್ಯ_ಆವೃತ್ತಿ[dllindex] : -1;
        ಆದರೆ (verndx >= 0
            /* XXX: on android, clang refuses to link with a libtcc.so made by tcc
               when defined symbols have a version > 1 or when the version is '0'.
               Whereas version '1' for example for 'signal' in an exe defeats
               bcheck's signal_redir. */
            && (sym->st_shndx == SHN_UNDEF || (s1->output_type & TCC_OUTPUT_EXE))
            ) {
            ಆದರೆ (!sym_versions[verndx].ಹೊರಹೋಗು_ಸೂಚ್ಯಂಕ)
              sym_versions[verndx].ಹೊರಹೋಗು_ಸೂಚ್ಯಂಕ = nb_versions++;
            versym[sym_ಸೂಚ್ಯಂಕ] = sym_versions[verndx].ಹೊರಹೋಗು_ಸೂಚ್ಯಂಕ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            versym[sym_ಸೂಚ್ಯಂಕ] = 1; /* (*global*) */
        }
        //printf("SYM %d %s\n", versym[sym_index], name);
    }
    /* generate verneed section, but not when it will be empty.  Some
       dynamic linkers look at their contents even when DTVERNEEDNUM and
       section size is zero.  */
    ಆದರೆ (nb_versions > 2) {
        verneed_section = new_section(s1, ".gnu.version_r",
                                      SHT_GNU_verneed, SHF_ALLOC);
        verneed_section->link = s1->dynsym->link;
        ಗಾಗಿ (i = nb_sym_versions; i-- > 0;) {
            ರಚನೆ sym_ಆವೃತ್ತಿ *sv = &sym_versions[i];
            ಪೂರ್ಣಾಂಕ n_same_libs = 0, prev;
            ಗಾತ್ರ_t vnofs;
            ElfW(Vernaux) *vna = 0;
            ಆದರೆ (sv->ಹೊರಹೋಗು_ಸೂಚ್ಯಂಕ < 1)
              ಮುಂದುವರಿ;

            /* make sure that a DT_NEEDED tag is put */
            /* abitest-tcc fails on older i386-linux with "ld-linux.so.2" DT_NEEDED
               ret_int_test... Inconsistency detected by ld.so: dl-minimal.c: 148:
               realloc: Assertion `ptr == alloc_last_block' failed! */
            ಆದರೆ (strcmp(sv->lib, "ld-linux.so.2"))
                tcc_ಕೂಡಿಸು_dllref(s1, sv->lib, 0);

            vnofs = section_ಕೂಡಿಸು(verneed_section, ಗಾತ್ರ(*vn), 1);
            vn = (ElfW(Verneed)*)(verneed_section->ದತ್ತಾಂಶ + vnofs);
            vn->vn_ಆವೃತ್ತಿ = 1;
            vn->vn_file = put_elf_str(verneed_section->link, sv->lib);
            vn->vn_aux = ಗಾತ್ರ (*vn);
            ಮಾಡು {
                prev = sv->prev_same_lib;
                ಆದರೆ (sv->ಹೊರಹೋಗು_ಸೂಚ್ಯಂಕ > 0) {
                    vna = section_ptr_ಕೂಡಿಸು(verneed_section, ಗಾತ್ರ(*vna));
                    vna->vna_hash = elf_hash ((ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *)sv->ಆವೃತ್ತಿ);
                    vna->vna_flags = 0;
                    vna->vna_other = sv->ಹೊರಹೋಗು_ಸೂಚ್ಯಂಕ;
                    sv->ಹೊರಹೋಗು_ಸೂಚ್ಯಂಕ = -2;
                    vna->vna_name = put_elf_str(verneed_section->link, sv->ಆವೃತ್ತಿ);
                    vna->vna_ಮುಂದಿನ = ಗಾತ್ರ (*vna);
                    //printf("LIB %d %s %s\n", vna->vna_other, sv->lib, verneed_section->link->data + vna->vna_name);
                    n_same_libs++;
                }
                ಆದರೆ (prev >= 0)
                  sv = &sym_versions[prev];
            } ಆಗ(prev >= 0);
            vna->vna_ಮುಂದಿನ = 0;
            vn = (ElfW(Verneed)*)(verneed_section->ದತ್ತಾಂಶ + vnofs);
            vn->vn_cnt = n_same_libs;
            vn->vn_ಮುಂದಿನ = ಗಾತ್ರ(*vn) + n_same_libs * ಗಾತ್ರ(*vna);
            nb_entries++;
        }
        ಆದರೆ (vn)
          vn->vn_ಮುಂದಿನ = 0;
        verneed_section->sh_info = nb_entries;
    }
    dt_verneednum = nb_entries;
}
#ಆದರೆ_ಅಂತ್ಯ /* ndef ELF_OBJ_ONLY */

/* catch .tbss also */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ IS_BSS(TCCState *s1, ಪೂರ್ಣಾಂಕ ndx)
{
    ಹಿಂತಿರುಗಿ ndx == SHN_COMMON
     || (ndx < s1->nb_sections
         && s1->sections[ndx]->sh_type == SHT_NOBITS);
}

/* add an elf symbol : check if it is already defined and patch
   it. Return symbol index. NOTE that sh_num can be SHN_UNDEF. */
ST_FUNC ಪೂರ್ಣಾಂಕ ಗಣ_elf_sym(Section *s, addr_t ಮೌಲ್ಯ, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2,
                       ಪೂರ್ಣಾಂಕ info, ಪೂರ್ಣಾಂಕ other, ಪೂರ್ಣಾಂಕ shndx, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name)
{
    TCCState *s1 = s->s1;
    ElfW(Sym) *esym;
    ಪೂರ್ಣಾಂಕ sym_bind, sym_ಸೂಚ್ಯಂಕ, sym_type, esym_bind;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ sym_vis, esym_vis, new_vis;

    sym_bind = ELFW(ST_BIND)(info);
    sym_type = ELFW(ST_TYPE)(info);
    sym_vis = ELFW(ST_VISIBILITY)(other);

    ಆದರೆ (sym_bind != STB_LOCAL) {
        /* we search global or weak symbols */
        sym_ಸೂಚ್ಯಂಕ = ಕಂಡುಹಿಡಿ_elf_sym(s, name);
        ಆದರೆ (!sym_ಸೂಚ್ಯಂಕ)
            ಹೋಗು do_def;
        esym = &((ElfW(Sym) *)s->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
        ಆದರೆ (esym->st_ಮೌಲ್ಯ == ಮೌಲ್ಯ && esym->st_ಗಾತ್ರ == ಗಾತ್ರ_2 && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            ಹಿಂತಿರುಗಿ sym_ಸೂಚ್ಯಂಕ;
        ಆದರೆ (esym->st_shndx != SHN_UNDEF) {
            esym_bind = ELFW(ST_BIND)(esym->st_info);
            /* propagate the most constraining visibility */
            /* STV_DEFAULT(0)<STV_PROTECTED(3)<STV_HIDDEN(2)<STV_INTERNAL(1) */
            esym_vis = ELFW(ST_VISIBILITY)(esym->st_other);
            ಆದರೆ (esym_vis == STV_DEFAULT) {
                new_vis = sym_vis;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sym_vis == STV_DEFAULT) {
                new_vis = esym_vis;
            } ಇಲ್ಲದಿದ್ದರೆ {
                new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
            }
            esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
                             | new_vis;
            ಆದರೆ (shndx == SHN_UNDEF) {
                /* ignore adding of undefined symbol if the
                   corresponding symbol is already defined */
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sym_bind == STB_GLOBAL && esym_bind == STB_WEAK) {
                /* global overrides weak, so patch */
                ಹೋಗು do_patch;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sym_bind == STB_WEAK && esym_bind == STB_GLOBAL) {
                /* weak is ignored if already global */
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sym_bind == STB_WEAK && esym_bind == STB_WEAK) {
                /* keep first-found weak definition, ignore subsequents */
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sym_vis == STV_HIDDEN || sym_vis == STV_ಆಂತರಿಕ) {
                /* ignore hidden symbols after */
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_flags & SHF_DYNSYM) {
                /* we accept that two DLL define the same symbol */
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!IS_BSS(s1, shndx) && IS_BSS(s1, esym->st_shndx)) {
                /* data symbol gets precedence over common/bss */
                ಹೋಗು do_patch;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (IS_BSS(s1, shndx)) {
                /* data symbol keeps precedence over common/bss */
	    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (esym->st_other & ST_ASM_ಗಣ) {
		/* If the existing symbol came from an asm .set
		   we can override.  */
		ಹೋಗು do_patch;
            } ಇಲ್ಲದಿದ್ದರೆ {
#ಆದರೆ 0
                ಬರೆ("new_bind=%x new_shndx=%x new_vis=%x old_bind=%x old_shndx=%x old_vis=%x\n",
                       sym_bind, shndx, new_vis, esym_bind, esym->st_shndx, esym_vis);
#ಆದರೆ_ಅಂತ್ಯ
                tcc_error_noabort("link symbol '%s' defined twice", name);
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            esym->st_other = other;
        do_patch:
            esym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
            esym->st_shndx = shndx;
            esym->st_ಮೌಲ್ಯ = ಮೌಲ್ಯ;
            esym->st_ಗಾತ್ರ = ಗಾತ್ರ_2;
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
    do_def:
        sym_ಸೂಚ್ಯಂಕ = put_elf_sym(s, ಮೌಲ್ಯ, ಗಾತ್ರ_2,
                                ELFW(ST_INFO)(sym_bind, sym_type), other,
                                shndx, name);
    }
    ಹಿಂತಿರುಗಿ sym_ಸೂಚ್ಯಂಕ;
}

/* put relocation */
ST_FUNC ಶೂನ್ಯ put_elf_reloca(Section *symtab, Section *s, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ,
                            ಪೂರ್ಣಾಂಕ type, ಪೂರ್ಣಾಂಕ ಚಿಹ್ನೆ, addr_t addend)
{
    TCCState *s1 = s->s1;
    ಅಕ್ಷರ buf[256];
    Section *sr;
    ElfW_Rel *rel;

    sr = s->reloc;
    ಆದರೆ (!sr) {
        /* if no relocation section, create it */
        snprintf(buf, ಗಾತ್ರ(buf), REL_SECTION_FMT, s->name);
        /* if the symtab is allocated, then we consider the relocation
           are also */
        sr = new_section(s->s1, buf, SHT_RELX, symtab->sh_flags);
        sr->sh_entsize = ಗಾತ್ರ(ElfW_Rel);
        sr->link = symtab;
        sr->sh_info = s->sh_ಅಂಕೆ;
        s->reloc = sr;
    }
    rel = section_ptr_ಕೂಡಿಸು(sr, ಗಾತ್ರ(ElfW_Rel));
    rel->r_ಸ್ಥಾನಾಂತರ = ಸ್ಥಾನಾಂತರ;
    rel->r_info = ELFW(R_INFO)(ಚಿಹ್ನೆ, type);
#ಆದರೆ SHT_RELX == SHT_RELA
    rel->r_addend = addend;
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (SHT_RELX != SHT_RELA && addend)
        tcc_error_noabort("non-zero addend on REL architecture");
}

ST_FUNC ಶೂನ್ಯ put_elf_reloc(Section *symtab, Section *s, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ,
                           ಪೂರ್ಣಾಂಕ type, ಪೂರ್ಣಾಂಕ ಚಿಹ್ನೆ)
{
    put_elf_reloca(symtab, s, ಸ್ಥಾನಾಂತರ, type, ಚಿಹ್ನೆ, 0);
}

ST_FUNC ರಚನೆ sym_attr *get_sym_attr(TCCState *s1, ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ, ಪೂರ್ಣಾಂಕ alloc)
{
    ಪೂರ್ಣಾಂಕ n;
    ರಚನೆ sym_attr *tab;

    ಆದರೆ (ಸೂಚ್ಯಂಕ >= s1->nb_sym_attrs) {
        ಆದರೆ (!alloc)
            ಹಿಂತಿರುಗಿ s1->sym_attrs;
        /* find immediately bigger power of 2 and reallocate array */
        n = 1;
        ಆಗ (ಸೂಚ್ಯಂಕ >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * ಗಾತ್ರ(*s1->sym_attrs));
        s1->sym_attrs = tab;
        memset(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * ಗಾತ್ರ(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    ಹಿಂತಿರುಗಿ &s1->sym_attrs[ಸೂಚ್ಯಂಕ];
}

ಸ್ಥಿರ ಶೂನ್ಯ update_relocs(TCCState *s1, Section *s, ಪೂರ್ಣಾಂಕ *old_ಗಮ್ಯ_new_syms, ಪೂರ್ಣಾಂಕ ಮೊದಲ_sym)
{
    ಪೂರ್ಣಾಂಕ i, type, sym_ಸೂಚ್ಯಂಕ;
    Section *sr;
    ElfW_Rel *rel;

    ಗಾಗಿ(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        ಆದರೆ (sr->sh_type == SHT_RELX && sr->link == s) {
            for_each_elem(sr, 0, rel, ElfW_Rel) {
                sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(rel->r_info);
                type = ELFW(R_TYPE)(rel->r_info);
                ಆದರೆ ((sym_ಸೂಚ್ಯಂಕ -= ಮೊದಲ_sym) < 0)
                    ಮುಂದುವರಿ; /* zero sym_index in reloc (can happen with asm) */
                sym_ಸೂಚ್ಯಂಕ = old_ಗಮ್ಯ_new_syms[sym_ಸೂಚ್ಯಂಕ];
                rel->r_info = ELFW(R_INFO)(sym_ಸೂಚ್ಯಂಕ, type);
            }
        }
    }
}

/* In an ELF file symbol table, the local symbols must appear below
   the global and weak ones. Since TCC cannot sort it while generating
   the code, we must do it after. All the relocation tables are also
   modified to take into account the symbol table sorting */
ಸ್ಥಿರ ಶೂನ್ಯ ವಿಂಗಡಿಸು_syms(TCCState *s1, Section *s)
{
    ಪೂರ್ಣಾಂಕ *old_ಗಮ್ಯ_new_syms;
    ElfW(Sym) *new_syms;
    ಪೂರ್ಣಾಂಕ nb_syms, i;
    ElfW(Sym) *p, *q;

    nb_syms = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * ಗಾತ್ರ(ElfW(Sym)));
    old_ಗಮ್ಯ_new_syms = tcc_malloc(nb_syms * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));

    /* first pass for local symbols */
    p = (ElfW(Sym) *)s->ದತ್ತಾಂಶ;
    q = new_syms;
    ಗಾಗಿ(i = 0; i < nb_syms; i++) {
        ಆದರೆ (ELFW(ST_BIND)(p->st_info) == STB_LOCAL) {
            old_ಗಮ್ಯ_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    /* save the number of local symbols in section header */
    ಆದರೆ( s->sh_ಗಾತ್ರ )    /* this 'if' makes IDA happy */
        s->sh_info = q - new_syms;

    /* then second pass for non local symbols */
    p = (ElfW(Sym) *)s->ದತ್ತಾಂಶ;
    ಗಾಗಿ(i = 0; i < nb_syms; i++) {
        ಆದರೆ (ELFW(ST_BIND)(p->st_info) != STB_LOCAL) {
            old_ಗಮ್ಯ_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }

    /* we copy the new symbols to the old */
    ಸ್ಮರಣೆ_ನಕಲು(s->ದತ್ತಾಂಶ, new_syms, nb_syms * ಗಾತ್ರ(ElfW(Sym)));
    tcc_free(new_syms);

    update_relocs(s1, s, old_ಗಮ್ಯ_new_syms, 0);
    tcc_free(old_ಗಮ್ಯ_new_syms);
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
/* See: https://flapenguin.me/elf-dt-gnu-hash */
#ವ್ಯಾಖ್ಯಾನಿಸು	ELFCLASS_ಬಿಟ್ಟುಗಳು (PTR_ಗಾತ್ರ * 8)

ಸ್ಥಿರ Section *create_gnu_hash(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ nb_syms, i, ndef, nbuckets, symoffset, bloom_ಗಾತ್ರ, bloom_ಸರಿಸು;
    ElfW(Sym) *p;
    Section *gnu_hash;
    Section *dynsym = s1->dynsym;
    Elf32_ಶಬ್ದ *ptr;

    gnu_hash = new_section(s1, ".gnu.hash", SHT_GNU_HASH, SHF_ALLOC);
    gnu_hash->link = dynsym->hash->link;

    nb_syms = dynsym->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ(ElfW(Sym));

    /* count def symbols */
    ndef = 0;
    p = (ElfW(Sym) *)dynsym->ದತ್ತಾಂಶ;
    ಗಾಗಿ(i = 0; i < nb_syms; i++, p++)
        ndef += p->st_shndx != SHN_UNDEF;

    /* calculate gnu hash sizes and fill header */
    nbuckets = ndef / 4 + 1;
    symoffset = nb_syms - ndef;
    bloom_ಸರಿಸು = PTR_ಗಾತ್ರ == 8 ? 6 : 5;
    bloom_ಗಾತ್ರ = 1; /* must be power of two */
    ಆಗ (ndef >= bloom_ಗಾತ್ರ * (1 << (bloom_ಸರಿಸು - 3)))
	bloom_ಗಾತ್ರ *= 2;
    ptr = section_ptr_ಕೂಡಿಸು(gnu_hash, 4 * 4 +
				    PTR_ಗಾತ್ರ * bloom_ಗಾತ್ರ +
				    nbuckets * 4 +
				    ndef * 4);
    ptr[0] = nbuckets;
    ptr[1] = symoffset;
    ptr[2] = bloom_ಗಾತ್ರ;
    ptr[3] = bloom_ಸರಿಸು;
    ಹಿಂತಿರುಗಿ gnu_hash;
}

ಸ್ಥಿರ Elf32_ಶಬ್ದ elf_gnu_hash (ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *name)
{
    Elf32_ಶಬ್ದ h = 5381;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ c;

    ಆಗ ((c = *name++))
        h = h * 33 + c;
    ಹಿಂತಿರುಗಿ h;
}

ಸ್ಥಿರ ಶೂನ್ಯ update_gnu_hash(TCCState *s1, Section *gnu_hash)
{
    ಪೂರ್ಣಾಂಕ *old_ಗಮ್ಯ_new_syms;
    ElfW(Sym) *new_syms;
    ಪೂರ್ಣಾಂಕ nb_syms, i, nbuckets, bloom_ಗಾತ್ರ, bloom_ಸರಿಸು;
    ElfW(Sym) *p, *q;
    Section *vs;
    Section *dynsym = s1->dynsym;
    Elf32_ಶಬ್ದ *ptr, *buckets, *chain, *hash;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *nextbuck;
    addr_t *bloom;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *strtab;
    ರಚನೆ { ಪೂರ್ಣಾಂಕ ಮೊದಲ, ಕೊನೆಯ; } *buck;

    strtab = dynsym->link->ದತ್ತಾಂಶ;
    nb_syms = dynsym->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * ಗಾತ್ರ(ElfW(Sym)));
    old_ಗಮ್ಯ_new_syms = tcc_malloc(nb_syms * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));
    hash = tcc_malloc(nb_syms * ಗಾತ್ರ(Elf32_ಶಬ್ದ));
    nextbuck = tcc_malloc(nb_syms * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));

    /* calculate hashes and copy undefs */
    p = (ElfW(Sym) *)dynsym->ದತ್ತಾಂಶ;
    q = new_syms;
    ಗಾಗಿ(i = 0; i < nb_syms; i++, p++) {
        ಆದರೆ (p->st_shndx == SHN_UNDEF) {
            old_ಗಮ್ಯ_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
	ಇಲ್ಲದಿದ್ದರೆ
	    hash[i] = elf_gnu_hash(strtab + p->st_name);
    }

    ptr = (Elf32_ಶಬ್ದ *) gnu_hash->ದತ್ತಾಂಶ;
    nbuckets = ptr[0];
    bloom_ಗಾತ್ರ = ptr[2];
    bloom_ಸರಿಸು = ptr[3];
    bloom = (addr_t *) (ಶೂನ್ಯ *) &ptr[4];
    buckets = (Elf32_ಶಬ್ದ*) (ಶೂನ್ಯ *) &bloom[bloom_ಗಾತ್ರ];
    chain = &buckets[nbuckets];
    buck = tcc_malloc(nbuckets * ಗಾತ್ರ(*buck));

    ಆದರೆ (gnu_hash->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ != 4 * 4 +
				 PTR_ಗಾತ್ರ * bloom_ಗಾತ್ರ +
				 nbuckets * 4 +
				 (nb_syms - (q - new_syms)) * 4)
	tcc_error_noabort ("gnu_hash size incorrect");

    /* find buckets */
    ಗಾಗಿ(i = 0; i < nbuckets; i++)
	buck[i].ಮೊದಲ = -1;

    p = (ElfW(Sym) *)dynsym->ದತ್ತಾಂಶ;
    ಗಾಗಿ(i = 0; i < nb_syms; i++, p++)
        ಆದರೆ (p->st_shndx != SHN_UNDEF) {
	    ಪೂರ್ಣಾಂಕ ಪಾತ್ರೆ = hash[i] % nbuckets;

	    ಆದರೆ (buck[ಪಾತ್ರೆ].ಮೊದಲ == -1)
		buck[ಪಾತ್ರೆ].ಮೊದಲ = buck[ಪಾತ್ರೆ].ಕೊನೆಯ = i;
	    ಇಲ್ಲದಿದ್ದರೆ {
		nextbuck[buck[ಪಾತ್ರೆ].ಕೊನೆಯ] = i;
		buck[ಪಾತ್ರೆ].ಕೊನೆಯ = i;
	    }
	}

    /* fill buckets/chains/bloom and sort symbols */
    p = (ElfW(Sym) *)dynsym->ದತ್ತಾಂಶ;
    ಗಾಗಿ(i = 0; i < nbuckets; i++) {
	ಪೂರ್ಣಾಂಕ cur = buck[i].ಮೊದಲ;

	ಆದರೆ (cur != -1) {
	    buckets[i] = q - new_syms;
	    ಗಾಗಿ (;;) {
                old_ಗಮ್ಯ_new_syms[cur] = q - new_syms;
                *q++ = p[cur];
	        *chain++ = hash[cur] & ~1;
		bloom[(hash[cur] / ELFCLASS_ಬಿಟ್ಟುಗಳು) % bloom_ಗಾತ್ರ] |=
		    (addr_t)1 << (hash[cur] % ELFCLASS_ಬಿಟ್ಟುಗಳು) |
		    (addr_t)1 << ((hash[cur] >> bloom_ಸರಿಸು) % ELFCLASS_ಬಿಟ್ಟುಗಳು);
		ಆದರೆ (cur == buck[i].ಕೊನೆಯ)
		    ನಿಲ್ಲಿಸು;
		cur = nextbuck[cur];
	    }
	    chain[-1] |= 1;
	}
    }

    ಸ್ಮರಣೆ_ನಕಲು(dynsym->ದತ್ತಾಂಶ, new_syms, nb_syms * ಗಾತ್ರ(ElfW(Sym)));
    tcc_free(new_syms);
    tcc_free(hash);
    tcc_free(buck);
    tcc_free(nextbuck);

    update_relocs(s1, dynsym, old_ಗಮ್ಯ_new_syms, 0);

    /* modify the versions */
    vs = versym_section;
    ಆದರೆ (vs) {
	ElfW(Half) *newver, *versym = (ElfW(Half) *)vs->ದತ್ತಾಂಶ;

	ಆದರೆ (1/*versym*/) {
            newver = tcc_malloc(nb_syms * ಗಾತ್ರ(*newver));
	    ಗಾಗಿ (i = 0; i < nb_syms; i++)
	        newver[old_ಗಮ್ಯ_new_syms[i]] = versym[i];
	    ಸ್ಮರಣೆ_ನಕಲು(vs->ದತ್ತಾಂಶ, newver, nb_syms * ಗಾತ್ರ(*newver));
	    tcc_free(newver);
	}
    }

    tcc_free(old_ಗಮ್ಯ_new_syms);

    /* rebuild hash */
    ptr = (Elf32_ಶಬ್ದ *) dynsym->hash->ದತ್ತಾಂಶ;
    rebuild_hash(dynsym, ptr[0]);
}
#ಆದರೆ_ಅಂತ್ಯ /* ELF_OBJ_ONLY */

/* relocate symbol table, resolve undefined symbols if do_resolve is
   true and output error if undefined symbol. */
ST_FUNC ಶೂನ್ಯ relocate_syms(TCCState *s1, Section *symtab, ಪೂರ್ಣಾಂಕ do_resolve)
{
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಂಕ sym_bind, sh_ಅಂಕೆ;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;

    for_each_elem(symtab, 1, sym, ElfW(Sym)) {
        sh_ಅಂಕೆ = sym->st_shndx;
        ಆದರೆ (sh_ಅಂಕೆ == SHN_UNDEF) {
            ಆದರೆ (do_resolve == 2) /* relocating dynsym */
                ಮುಂದುವರಿ;
            name = (ಅಕ್ಷರ *) s1->symtab->link->ದತ್ತಾಂಶ + sym->st_name;
            /* Use ld.so to resolve symbol for us (for tcc -run) */
            ಆದರೆ (do_resolve) {
#ಆದರೆ defined TCC_IS_NATIVE && !defined TCC_ಗುರಿ_PE
                /* dlsym() needs the undecorated name.  */
                ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name_ud = &name[s1->leading_underscore];
                ಶೂನ್ಯ *addr = ಖಾಲಿ;
                ಆದರೆ (!s1->nostdlib)
                    addr = dlsym(RTLD_DEFAULT, name_ud);
		ಆದರೆ (addr == ಖಾಲಿ) {
		    ಪೂರ್ಣಾಂಕ i;
		    ಗಾಗಿ (i = 0; i < s1->nb_loaded_dlls; i++)
                        ಆದರೆ ((addr = dlsym(s1->loaded_dlls[i]->handle, name_ud)))
			    ನಿಲ್ಲಿಸು;
		}
                ಆದರೆ (addr) {
                    sym->st_ಮೌಲ್ಯ = (addr_t) addr;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ DEBUG_RELOC
		    ಬರೆ ("relocate_sym: %s -> 0x%lx\n", name, sym->st_ಮೌಲ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ
                    ಹೋಗು ಸಿಕ್ಕಿತು;
                }
#ಆದರೆ_ಅಂತ್ಯ
            /* if dynamic symbol exist, it will be used in relocate_section */
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s1->dynsym && ಕಂಡುಹಿಡಿ_elf_sym(s1->dynsym, name))
                ಹೋಗು ಸಿಕ್ಕಿತು;
            /* XXX: _fp_hw seems to be part of the ABI, so we ignore
               it */
            ಆದರೆ (!strcmp(name, "_fp_hw"))
                ಹೋಗು ಸಿಕ್ಕಿತು;
            /* only weak symbols are accepted to be undefined. Their
               value is zero */
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            ಆದರೆ (sym_bind == STB_WEAK)
                sym->st_ಮೌಲ್ಯ = 0;
            ಇಲ್ಲದಿದ್ದರೆ
                tcc_error_noabort("unresolved reference to '%s'", name);

        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sh_ಅಂಕೆ < SHN_LORESERVE) {
            /* add section base */
            sym->st_ಮೌಲ್ಯ += s1->sections[sym->st_shndx]->sh_addr;
        }
    ಸಿಕ್ಕಿತು: ;
    }
}

/* relocate a given section (CPU dependent) by applying the relocations
   in the associated relocation section */
ಸ್ಥಿರ ಶೂನ್ಯ relocate_section(TCCState *s1, Section *s, Section *sr)
{
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಂಕ type, sym_ಸೂಚ್ಯಂಕ;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr;
    addr_t tgt, addr;
    ಪೂರ್ಣಾಂಕ is_dwarf = s->sh_ಅಂಕೆ >= s1->dwlo && s->sh_ಅಂಕೆ < s1->dwhi;

    qrel = (ElfW_Rel *)sr->ದತ್ತಾಂಶ;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
	ಆದರೆ (s->ದತ್ತಾಂಶ == ಖಾಲಿ) /* bss */
	    ಮುಂದುವರಿ;
        ptr = s->ದತ್ತಾಂಶ + rel->r_ಸ್ಥಾನಾಂತರ;
        sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(rel->r_info);
        sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
        type = ELFW(R_TYPE)(rel->r_info);
        tgt = sym->st_ಮೌಲ್ಯ;
#ಆದರೆ SHT_RELX == SHT_RELA
        tgt += rel->r_addend;
#ಆದರೆ_ಅಂತ್ಯ
        ಆದರೆ (is_dwarf && type == R_ದತ್ತಾಂಶ_32_DW
            && sym->st_shndx >= s1->dwlo && sym->st_shndx < s1->dwhi) {
            /* dwarf section relocation to each other */
            add32le(ptr, tgt - s1->sections[sym->st_shndx]->sh_addr);
            ಮುಂದುವರಿ;
        }
        addr = s->sh_addr + rel->r_ಸ್ಥಾನಾಂತರ;
        relocate(s1, rel, type, ptr, addr, tgt);
    }

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
    /* if the relocation is allocated, we change its symbol table */
    ಆದರೆ (sr->sh_flags & SHF_ALLOC) {
        sr->link = s1->dynsym;
        ಆದರೆ (s1->output_type & TCC_OUTPUT_DYN) {
            ಗಾತ್ರ_t r = (uint8_t*)qrel - sr->ದತ್ತಾಂಶ;
            ಆದರೆ (ಗಾತ್ರ ((Stab_Sym*)0)->n_ಮೌಲ್ಯ < PTR_ಗಾತ್ರ
                && 0 == strcmp(s->name, ".stab"))
                r = 0; /* cannot apply 64bit relocation to 32bit value */
            sr->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = sr->sh_ಗಾತ್ರ = r;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_PIE
            ಆದರೆ (r && (s->sh_flags & SHF_EXECINSTR))
                tcc_warning("%d relocations to %s", (ಚಿಹ್ನೆರಹಿತ)(r / ಗಾತ್ರ *qrel), s->name);
#ಆದರೆ_ಅಂತ್ಯ
        }
    }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_RISCV64
    dynarray_reset(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries);
#ಆದರೆ_ಅಂತ್ಯ
}

/* relocate all sections */
ST_FUNC ಶೂನ್ಯ relocate_sections(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ i;
    Section *s, *sr;

    ಗಾಗಿ (i = 1; i < s1->nb_sections; ++i) {
        sr = s1->sections[i];
        ಆದರೆ (sr->sh_type != SHT_RELX)
            ಮುಂದುವರಿ;
        s = s1->sections[sr->sh_info];
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_MACHO
        ಆದರೆ (s != s1->got
            || s1->static_link
            || s1->output_type == TCC_OUTPUT_ಸ್ಮರಣೆ)
#ಆದರೆ_ಅಂತ್ಯ
        {
            relocate_section(s1, s, sr);
        }
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
        ಆದರೆ (sr->sh_flags & SHF_ALLOC) {
            ElfW_Rel *rel;
            /* relocate relocation table in 'sr' */
            for_each_elem(sr, 0, rel, ElfW_Rel)
                rel->r_ಸ್ಥಾನಾಂತರ += s->sh_addr;
        }
#ಆದರೆ_ಅಂತ್ಯ
    }
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
/* count the number of dynamic relocations so that we can reserve
   their space */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ prepare_dynamic_rel(TCCState *s1, Section *sr)
{
    ಪೂರ್ಣಾಂಕ ಎಣಿಕೆ_3 = 0;
#ಆದರೆ defined(TCC_ಗುರಿ_I386) || defined(TCC_ಗುರಿ_X86_64) || \
    defined(TCC_ಗುರಿ_ARM) || defined(TCC_ಗುರಿ_ARM64) || \
    defined(TCC_ಗುರಿ_RISCV64)
    ElfW_Rel *rel;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
        ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(rel->r_info);
        ಪೂರ್ಣಾಂಕ type = ELFW(R_TYPE)(rel->r_info);
        ಆಯ್ಕೆ(type) {
#ಆದರೆ defined(TCC_ಗುರಿ_I386)
        ಸ್ಥಿತಿ R_386_32:
            ಆದರೆ (!get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->dyn_ಸೂಚ್ಯಂಕ
                && ((ElfW(Sym)*)symtab_section->ದತ್ತಾಂಶ + sym_ಸೂಚ್ಯಂಕ)->st_shndx == SHN_UNDEF) {
                /* don't fixup unresolved (weak) symbols */
                rel->r_info = ELFW(R_INFO)(sym_ಸೂಚ್ಯಂಕ, R_386_RELATIVE);
                ನಿಲ್ಲಿಸು;
            }
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_X86_64)
        ಸ್ಥಿತಿ R_X86_64_32:
        ಸ್ಥಿತಿ R_X86_64_32S:
        ಸ್ಥಿತಿ R_X86_64_64:
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_ARM)
        ಸ್ಥಿತಿ R_ARM_ABS32:
        ಸ್ಥಿತಿ R_ARM_TARGET1:
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_ARM64)
        ಸ್ಥಿತಿ R_AARCH64_ABS32:
        ಸ್ಥಿತಿ R_AARCH64_ABS64:
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_RISCV64)
        ಸ್ಥಿತಿ R_RISCV_32:
        ಸ್ಥಿತಿ R_RISCV_64:
#ಆದರೆ_ಅಂತ್ಯ
            ಎಣಿಕೆ_3++;
            ನಿಲ್ಲಿಸು;
#ಆದರೆ defined(TCC_ಗುರಿ_I386)
        ಸ್ಥಿತಿ R_386_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    ಆದರೆ (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_ಸೂಚ್ಯಂಕ, R_386_PLT32);
	        ನಿಲ್ಲಿಸು;
	    }
	}
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_X86_64)
        ಸ್ಥಿತಿ R_X86_64_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    ಆದರೆ (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_ಸೂಚ್ಯಂಕ, R_X86_64_PLT32);
	        ನಿಲ್ಲಿಸು;
	    }
	}
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_ARM64)
        ಸ್ಥಿತಿ R_AARCH64_PREL32:
#ಆದರೆ_ಅಂತ್ಯ
            ಆದರೆ (s1->output_type != TCC_OUTPUT_DLL)
                ನಿಲ್ಲಿಸು;
            ಆದರೆ (get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->dyn_ಸೂಚ್ಯಂಕ)
                ಎಣಿಕೆ_3++;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            ನಿಲ್ಲಿಸು;
        }
    }
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ ಎಣಿಕೆ_3;
}
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ NEED_BUILD_GOT
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ build_got(TCCState *s1)
{
    /* if no got, then create it */
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    s1->got->sh_entsize = 4;
    /* keep space for _DYNAMIC pointer and two dummy got entries */
    section_ptr_ಕೂಡಿಸು(s1->got, 3 * PTR_ಗಾತ್ರ);
    ಹಿಂತಿರುಗಿ ಗಣ_elf_sym(symtab_section, 0, 0, ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
        0, s1->got->sh_ಅಂಕೆ, "_GLOBAL_OFFSET_TABLE_");
}

/* Create a GOT and (for function call) a PLT entry corresponding to a symbol
   in s1->symtab. When creating the dynamic symbol table entry for the GOT
   relocation, use 'size' and 'info' for the corresponding symbol metadata.
   Returns the offset of the GOT or (if any) PLT entry. */
ಸ್ಥಿರ ರಚನೆ sym_attr * put_got_ನಮೂದು(TCCState *s1, ಪೂರ್ಣಾಂಕ dyn_reloc_type,
                                       ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ)
{
    ಪೂರ್ಣಾಂಕ need_plt_ನಮೂದು;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
    ElfW(Sym) *sym;
    ರಚನೆ sym_attr *attr;
    ಚಿಹ್ನೆರಹಿತ got_ಸ್ಥಾನಾಂತರ;
    ಅಕ್ಷರ plt_name[200];
    ಪೂರ್ಣಾಂಕ len;
    Section *s_rel;

    need_plt_ನಮೂದು = (dyn_reloc_type == R_JMP_ಸ್ಥಾನ);
    attr = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 1);

    /* In case a function is both called and its address taken 2 GOT entries
       are created, one for taking the address (GOT) and the other for the PLT
       entry (PLTGOT).  */
    ಆದರೆ (need_plt_ನಮೂದು ? attr->plt_ಸ್ಥಾನಾಂತರ : attr->got_ಸ್ಥಾನಾಂತರ)
        ಹಿಂತಿರುಗಿ attr;

    s_rel = s1->got;
    ಆದರೆ (need_plt_ನಮೂದು) {
        ಆದರೆ (!s1->plt) {
            s1->plt = new_section(s1, ".plt", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
            s1->plt->sh_entsize = 4;
        }
        s_rel = s1->plt;
    }

    /* create the GOT entry */
    got_ಸ್ಥಾನಾಂತರ = s1->got->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    section_ptr_ಕೂಡಿಸು(s1->got, PTR_ಗಾತ್ರ);

    /* Create the GOT relocation that will insert the address of the object or
       function of interest in the GOT entry. This is a static relocation for
       memory output (dlsym will give us the address of symbols) and dynamic
       relocation otherwise (executable and DLLs). The relocation should be
       done lazily for GOT entry with *_JUMP_SLOT relocation type (the one
       associated to a PLT entry) but is currently done at load time for an
       unknown reason. */

    sym = &((ElfW(Sym) *) symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
    name = (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
    //printf("sym %d %s\n", need_plt_entry, name);

    ಆದರೆ (s1->dynsym) {
	ಆದರೆ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
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
	    put_elf_reloc(s1->dynsym, s1->got, got_ಸ್ಥಾನಾಂತರ, R_RELATIVE,
			  sym_ಸೂಚ್ಯಂಕ);
	} ಇಲ್ಲದಿದ್ದರೆ {
	    ಆದರೆ (0 == attr->dyn_ಸೂಚ್ಯಂಕ)
                attr->dyn_ಸೂಚ್ಯಂಕ = ಗಣ_elf_sym(s1->dynsym, sym->st_ಮೌಲ್ಯ,
                                              sym->st_ಗಾತ್ರ, sym->st_info, 0,
                                              sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s_rel, got_ಸ್ಥಾನಾಂತರ, dyn_reloc_type,
			  attr->dyn_ಸೂಚ್ಯಂಕ);
	}
    } ಇಲ್ಲದಿದ್ದರೆ {
        put_elf_reloc(symtab_section, s1->got, got_ಸ್ಥಾನಾಂತರ, dyn_reloc_type,
                      sym_ಸೂಚ್ಯಂಕ);
    }

    ಆದರೆ (need_plt_ನಮೂದು) {
        attr->plt_ಸ್ಥಾನಾಂತರ = create_plt_ನಮೂದು(s1, got_ಸ್ಥಾನಾಂತರ, attr);

        /* create a symbol 'sym@plt' for the PLT jump vector */
        len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name);
        ಆದರೆ (len > ಗಾತ್ರ plt_name - 5)
            len = ಗಾತ್ರ plt_name - 5;
        ಸ್ಮರಣೆ_ನಕಲು(plt_name, name, len);
        strcpy(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_ಸ್ಥಾನಾಂತರ, 0,
            ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0, s1->plt->sh_ಅಂಕೆ, plt_name);
    } ಇಲ್ಲದಿದ್ದರೆ {
        attr->got_ಸ್ಥಾನಾಂತರ = got_ಸ್ಥಾನಾಂತರ;
    }

    ಹಿಂತಿರುಗಿ attr;
}

/* build GOT and PLT entries */
/* Two passes because R_JMP_SLOT should become first. Some targets
   (arm, arm64) do not allow mixing R_JMP_SLOT and R_GLOB_DAT. */
ST_FUNC ಶೂನ್ಯ build_got_entries(TCCState *s1, ಪೂರ್ಣಾಂಕ got_sym)
{
    Section *s;
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಂಕ i, type, gotplt_ನಮೂದು, reloc_type, sym_ಸೂಚ್ಯಂಕ;
    ರಚನೆ sym_attr *attr;
    ಪೂರ್ಣಾಂಕ pass = 0;
redo:
    ಗಾಗಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ಆದರೆ (s->sh_type != SHT_RELX)
            ಮುಂದುವರಿ;
        /* no need to handle got relocations */
        ಆದರೆ (s->link != symtab_section)
            ಮುಂದುವರಿ;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_ನಮೂದು = gotplt_ನಮೂದು_type(type);
            ಆದರೆ (gotplt_ನಮೂದು == -1) {
                tcc_error_noabort ("Unknown relocation type for got: %d", type);
                ಮುಂದುವರಿ;
            }
            sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];

            ಆದರೆ (gotplt_ನಮೂದು == NO_GOTPLT_ನಮೂದು) {
                ಮುಂದುವರಿ;
            }

            /* Automatically create PLT/GOT [entry] if it is an undefined
	       reference (resolved at runtime), or the symbol is absolute,
	       probably created by tcc_add_symbol, and thus on 64-bit
	       targets might be too far from application code.  */
            ಆದರೆ (gotplt_ನಮೂದು == AUTO_GOTPLT_ನಮೂದು) {
                ಆದರೆ (sym->st_shndx == SHN_UNDEF) {
                    ElfW(Sym) *esym;
		    ಪೂರ್ಣಾಂಕ dynindex;
                    ಆದರೆ (!PCRELATIVE_DLLPLT
                        && (s1->output_type & TCC_OUTPUT_DYN))
                        ಮುಂದುವರಿ;
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
		    ಆದರೆ (s1->dynsym) {
			/* dynsym isn't set for -run :-/  */
			dynindex = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->dyn_ಸೂಚ್ಯಂಕ;
			esym = (ElfW(Sym) *)s1->dynsym->ದತ್ತಾಂಶ + dynindex;
			ಆದರೆ (dynindex
			    && (ELFW(ST_TYPE)(esym->st_info) == STT_FUNC
				|| (ELFW(ST_TYPE)(esym->st_info) == STT_NOTYPE
				    && ELFW(ST_TYPE)(sym->st_info) == STT_FUNC)))
			    ಹೋಗು jmp_ಸ್ಥಾನ;
		    }
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sym->st_shndx == SHN_ABS) {
                    ಆದರೆ (sym->st_ಮೌಲ್ಯ == 0) /* from tcc_add_btstub() */
                        ಮುಂದುವರಿ;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_ARM
                    ಆದರೆ (PTR_ಗಾತ್ರ != 8)
                        ಮುಂದುವರಿ;
#ಆದರೆ_ಅಂತ್ಯ
                    /* from tcc_add_symbol(): on 64 bit platforms these
                       need to go through .got */
                } ಇಲ್ಲದಿದ್ದರೆ
                    ಮುಂದುವರಿ;
            }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_I386
            ಆದರೆ ((type == R_386_PLT32 || type == R_386_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		ಆದರೆ (pass != 0)
		    ಮುಂದುವರಿ;
                rel->r_info = ELFW(R_INFO)(sym_ಸೂಚ್ಯಂಕ, R_386_PC32);
                ಮುಂದುವರಿ;
            }
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
            ಆದರೆ ((type == R_X86_64_PLT32 || type == R_X86_64_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		ಆದರೆ (pass != 0)
		    ಮುಂದುವರಿ;
                rel->r_info = ELFW(R_INFO)(sym_ಸೂಚ್ಯಂಕ, R_X86_64_PC32);
                ಮುಂದುವರಿ;
            }
#ಆದರೆ_ಅಂತ್ಯ
            reloc_type = ಸಂಕೇತ_reloc(type);
            ಆದರೆ (reloc_type == -1) {
                tcc_error_noabort ("Unknown relocation type: %d", type);
                ಮುಂದುವರಿ;
            }

            ಆದರೆ (reloc_type != 0) {
        jmp_ಸ್ಥಾನ:
	        ಆದರೆ (pass != 0)
                    ಮುಂದುವರಿ;
                reloc_type = R_JMP_ಸ್ಥಾನ;
            } ಇಲ್ಲದಿದ್ದರೆ {
	        ಆದರೆ (pass != 1)
                    ಮುಂದುವರಿ;
                reloc_type = R_GLOB_DAT;
            }

            ಆದರೆ (!s1->got)
                got_sym = build_got(s1);

            ಆದರೆ (gotplt_ನಮೂದು == BUILD_GOT_ONLY)
                ಮುಂದುವರಿ;

            attr = put_got_ನಮೂದು(s1, reloc_type, sym_ಸೂಚ್ಯಂಕ);

            ಆದರೆ (reloc_type == R_JMP_ಸ್ಥಾನ)
                rel->r_info = ELFW(R_INFO)(attr->plt_sym, type);
        }
    }
    ಆದರೆ (++pass < 2)
        ಹೋಗು redo;
    /* .rel.plt refers to .got actually */
    ಆದರೆ (s1->plt && s1->plt->reloc)
        s1->plt->reloc->sh_info = s1->got->sh_ಅಂಕೆ;
    ಆದರೆ (got_sym) /* set size */
        ((ElfW(Sym)*)symtab_section->ದತ್ತಾಂಶ)[got_sym].st_ಗಾತ್ರ = s1->got->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
}
#ಆದರೆ_ಅಂತ್ಯ /* def NEED_BUILD_GOT */

ST_FUNC ಪೂರ್ಣಾಂಕ ಗಣ_global_sym(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, Section *sec, addr_t offs)
{
    ಪೂರ್ಣಾಂಕ shn = sec ? sec->sh_ಅಂಕೆ : offs || !name ? SHN_ABS : SHN_UNDEF;
    ಆದರೆ (sec && offs == -1)
        offs = sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    ಹಿಂತಿರುಗಿ ಗಣ_elf_sym(symtab_section, offs, 0,
        ELFW(ST_INFO)(name ? STB_GLOBAL : STB_LOCAL, STT_NOTYPE), 0, shn, name);
}

ಸ್ಥಿರ ಶೂನ್ಯ ಕೂಡಿಸು_init_array_ನಿರೂಪಿಸುತ್ತದೆ(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *section_name)
{
    Section *s;
    addr_t ಕೊನೆ_ಸ್ಥಾನಾಂತರ;
    ಅಕ್ಷರ buf[1024];
    s = have_section(s1, section_name);
    ಆದರೆ (!s || !(s->sh_flags & SHF_ALLOC)) {
        ಕೊನೆ_ಸ್ಥಾನಾಂತರ = 0;
        s = ಪಠ್ಯ_section;
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಕೊನೆ_ಸ್ಥಾನಾಂತರ = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    }
    snprintf(buf, ಗಾತ್ರ(buf), "__%s_start", section_name + 1);
    ಗಣ_global_sym(s1, buf, s, 0);
    snprintf(buf, ಗಾತ್ರ(buf), "__%s_end", section_name + 1);
    ಗಣ_global_sym(s1, buf, s, ಕೊನೆ_ಸ್ಥಾನಾಂತರ);
}

ST_FUNC ಶೂನ್ಯ ಕೂಡಿಸು_array (TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *sec, ಪೂರ್ಣಾಂಕ c)
{
    Section *s;
    s = ಕಂಡುಹಿಡಿ_section(s1, sec);
    s->sh_flags = shf_RELRO;
    s->sh_type = sec[1] == 'i' ? SHT_INIT_ARRAY : SHT_FINI_ARRAY;
    put_elf_reloc (s1->symtab, s, s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ, R_ದತ್ತಾಂಶ_PTR, c);
    section_ptr_ಕೂಡಿಸು(s, PTR_ಗಾತ್ರ);
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
ST_FUNC ಶೂನ್ಯ tcc_ಕೂಡಿಸು_bcheck(TCCState *s1)
{
    ಆದರೆ (0 == s1->do_bounds_check)
        ಹಿಂತಿರುಗಿ;
    section_ptr_ಕೂಡಿಸು(bounds_section, ಗಾತ್ರ(addr_t));
}
#ಆದರೆ_ಅಂತ್ಯ

/* set symbol to STB_LOCAL and resolve. The point is to not export it as
   a dynamic symbol to allow so's to have one each with a different value. */
ಸ್ಥಿರ ಶೂನ್ಯ ಗಣ_local_sym(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, Section *s, ಪೂರ್ಣಾಂಕ ಸ್ಥಾನಾಂತರ)
{
    ಪೂರ್ಣಾಂಕ c = ಕಂಡುಹಿಡಿ_elf_sym(s1->symtab, name);
    ಆದರೆ (c) {
        ElfW(Sym) *esym = (ElfW(Sym)*)s1->symtab->ದತ್ತಾಂಶ + c;
        esym->st_info = ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE);
        esym->st_ಮೌಲ್ಯ = ಸ್ಥಾನಾಂತರ;
        esym->st_shndx = s->sh_ಅಂಕೆ;
    }
}

/* avoid generating debug/test_coverage code for stub functions */
ಸ್ಥಿರ ಶೂನ್ಯ tcc_compile_string_no_debug(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    ಪೂರ್ಣಾಂಕ save_do_debug = s->do_debug;
    ಪೂರ್ಣಾಂಕ save_test_coverage = s->test_coverage;

    s->do_debug = 0;
    s->test_coverage = 0;
    tcc_compile_string(s, str);
    s->do_debug = save_do_debug;
    s->test_coverage = save_test_coverage;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
ಸ್ಥಿರ ಶೂನ್ಯ put_ptr(TCCState *s1, Section *s, ಪೂರ್ಣಾಂಕ offs)
{
    ಪೂರ್ಣಾಂಕ c;
    c = ಗಣ_global_sym(s1, ಖಾಲಿ, s, offs);
    s = ದತ್ತಾಂಶ_section;
    put_elf_reloc (s1->symtab, s, s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ, R_ದತ್ತಾಂಶ_PTR, c);
    section_ptr_ಕೂಡಿಸು(s, PTR_ಗಾತ್ರ);
}

ST_FUNC ಶೂನ್ಯ tcc_ಕೂಡಿಸು_btstub(TCCState *s1)
{
    Section *s;
    ಪೂರ್ಣಾಂಕ n, o, *p;
    CString cstr;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *__rt_info = &"___rt_info"[!s1->leading_underscore];

    s = ದತ್ತಾಂಶ_section;
    /* Align to PTR_SIZE */
    section_ಕೂಡಿಸು(s, 0, PTR_ಗಾತ್ರ);
    o = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    /* create a struct rt_context (see tccrun.c) */
    ಆದರೆ (s1->dwarf) {
        put_ptr(s1, dwarf_ಸಾಲು_section, 0);
        put_ptr(s1, dwarf_ಸಾಲು_section, -1);
	ಆದರೆ (s1->dwarf >= 5)
            put_ptr(s1, dwarf_ಸಾಲು_str_section, 0);
	ಇಲ್ಲದಿದ್ದರೆ
            put_ptr(s1, dwarf_str_section, 0);
    }
    ಇಲ್ಲದಿದ್ದರೆ
    {
        put_ptr(s1, stab_section, 0);
        put_ptr(s1, stab_section, -1);
        put_ptr(s1, stab_section->link, 0);
    }

    /* skip esym_start/esym_end/elf_str (not loaded) */
    section_ptr_ಕೂಡಿಸು(s, 3 * PTR_ಗಾತ್ರ);

    ಆದರೆ (s1->output_type == TCC_OUTPUT_ಸ್ಮರಣೆ && 0 == s1->dwarf) {
        put_ptr(s1, ಪಠ್ಯ_section, 0);
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* prog_base : local nameless symbol with offset 0 at SHN_ABS */
        put_ptr(s1, ಖಾಲಿ, 0);
#ಆದರೆ defined TCC_ಗುರಿ_MACHO
        /* adjust for __PAGEZERO */
        ಆದರೆ (s1->dwarf == 0 && s1->output_type == TCC_OUTPUT_EXE)
            write64le(ದತ್ತಾಂಶ_section->ದತ್ತಾಂಶ + ದತ್ತಾಂಶ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - PTR_ಗಾತ್ರ,
	              (uint64_t)1 << 32);
#ಆದರೆ_ಅಂತ್ಯ
    }
    n = 3 * PTR_ಗಾತ್ರ;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (s1->do_bounds_check) {
        put_ptr(s1, bounds_section, 0);
        n -= PTR_ಗಾತ್ರ;
    }
#ಆದರೆ_ಅಂತ್ಯ
    section_ptr_ಕೂಡಿಸು(s, n);
    p = section_ptr_ಕೂಡಿಸು(s, 2 * ಗಾತ್ರ (ಪೂರ್ಣಾಂಕ));
    p[0] = s1->rt_ಅಂಕೆ_callers;
    p[1] = s1->dwarf;
    // if (s->data_offset - o != 10*PTR_SIZE + 2*sizeof (int)) exit(99);

    ಆದರೆ (s1->output_type == TCC_OUTPUT_ಸ್ಮರಣೆ) {
        ಗಣ_global_sym(s1, __rt_info, s, o);
        ಹಿಂತಿರುಗಿ;
    }

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern void __bt_init(),__bt_exit(),__bt_init_dll();"
        "static void *__rt_info[];"
        "__attribute__((constructor)) static void __bt_init_rt(){");
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    ಆದರೆ (s1->output_type == TCC_OUTPUT_DLL)
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        cstr_printf(&cstr, "__bt_init_dll(%d);", s1->do_bounds_check);
#ಇಲ್ಲದಿದ್ದರೆ
        cstr_printf(&cstr, "__bt_init_dll(0);");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
    cstr_printf(&cstr, "__bt_init(__rt_info,%d);}",
        s1->output_type != TCC_OUTPUT_DLL);
    /* In case dlcose is called by application */
    cstr_printf(&cstr,
        "__attribute__((destructor)) static void __bt_exit_rt(){"
        "__bt_exit(__rt_info);}");
    tcc_compile_string_no_debug(s1, cstr.ದತ್ತಾಂಶ);
    cstr_free(&cstr);
    ಗಣ_local_sym(s1, __rt_info, s, o);
}
#ಆದರೆ_ಅಂತ್ಯ /* def CONFIG_TCC_BACKTRACE */

ಸ್ಥಿರ ಶೂನ್ಯ tcc_tcov_ಕೂಡಿಸು_file(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    CString cstr;
    ಶೂನ್ಯ *ptr;
    ಅಕ್ಷರ wd[1024];

    ಆದರೆ (tcov_section == ಖಾಲಿ)
        ಹಿಂತಿರುಗಿ;
    section_ptr_ಕೂಡಿಸು(tcov_section, 1);
    write32le (tcov_section->ದತ್ತಾಂಶ, tcov_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);

    cstr_new (&cstr);
    ಆದರೆ (filename[0] == '/')
        cstr_printf (&cstr, "%s.tcov", filename);
    ಇಲ್ಲದಿದ್ದರೆ {
        getcwd (wd, ಗಾತ್ರ(wd));
        cstr_printf (&cstr, "%s/%s.tcov", wd, filename);
    }
    ptr = section_ptr_ಕೂಡಿಸು(tcov_section, cstr.ಗಾತ್ರ_2 + 1);
    strcpy((ಅಕ್ಷರ *)ptr, cstr.ದತ್ತಾಂಶ);
    unlink((ಅಕ್ಷರ *)ptr);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
    normalize_slashes((ಅಕ್ಷರ *)ptr);
#ಆದರೆ_ಅಂತ್ಯ
    cstr_free (&cstr);

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern char *__tcov_data[];"
        "extern void __store_test_coverage ();"
        "__attribute__((destructor)) static void __tcov_exit() {"
        "__store_test_coverage(__tcov_data);"
        "}");
    tcc_compile_string_no_debug(s1, cstr.ದತ್ತಾಂಶ);
    cstr_free(&cstr);
    ಗಣ_local_sym(s1, &"___tcov_data"[!s1->leading_underscore], tcov_section, 0);
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_UNIX
/* add libc crt1/crti objects */
ST_FUNC ಶೂನ್ಯ tccelf_ಕೂಡಿಸು_crtbegin(TCCState *s1)
{
#ಆದರೆ TARGETOS_OpenBSD
    ಆದರೆ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_ಕೂಡಿಸು_crt(s1, "crt0.o");
    ಆದರೆ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_ಕೂಡಿಸು_crt(s1, "crtbeginS.o");
    ಇಲ್ಲದಿದ್ದರೆ
        tcc_ಕೂಡಿಸು_crt(s1, "crtbegin.o");
#ಅಥವಾಆದರೆ TARGETOS_FreeBSD || TARGETOS_NetBSD
    ಆದರೆ (s1->output_type != TCC_OUTPUT_DLL)
#ಆದರೆ TARGETOS_FreeBSD
        tcc_ಕೂಡಿಸು_crt(s1, "crt1.o");
#ಇಲ್ಲದಿದ್ದರೆ
        tcc_ಕೂಡಿಸು_crt(s1, "crt0.o");
#ಆದರೆ_ಅಂತ್ಯ
    tcc_ಕೂಡಿಸು_crt(s1, "crti.o");
    ಆದರೆ (s1->static_link)
        tcc_ಕೂಡಿಸು_crt(s1, "crtbeginT.o");
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_ಕೂಡಿಸು_crt(s1, "crtbeginS.o");
    ಇಲ್ಲದಿದ್ದರೆ
        tcc_ಕೂಡಿಸು_crt(s1, "crtbegin.o");
#ಅಥವಾಆದರೆ TARGETOS_ANDROID
    ಆದರೆ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_ಕೂಡಿಸು_crt(s1, "crtbegin_so.o");
    ಇಲ್ಲದಿದ್ದರೆ
        tcc_ಕೂಡಿಸು_crt(s1, "crtbegin_dynamic.o");
#ಇಲ್ಲದಿದ್ದರೆ
    ಆದರೆ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_ಕೂಡಿಸು_crt(s1, "crt1.o");
    tcc_ಕೂಡಿಸು_crt(s1, "crti.o");
#ಆದರೆ_ಅಂತ್ಯ
}

ST_FUNC ಶೂನ್ಯ tccelf_ಕೂಡಿಸು_crtend(TCCState *s1)
{
#ಆದರೆ TARGETOS_OpenBSD
    ಆದರೆ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_ಕೂಡಿಸು_crt(s1, "crtendS.o");
    ಇಲ್ಲದಿದ್ದರೆ
        tcc_ಕೂಡಿಸು_crt(s1, "crtend.o");
#ಅಥವಾಆದರೆ TARGETOS_FreeBSD || TARGETOS_NetBSD
    ಆದರೆ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_ಕೂಡಿಸು_crt(s1, "crtendS.o");
    ಇಲ್ಲದಿದ್ದರೆ
        tcc_ಕೂಡಿಸು_crt(s1, "crtend.o");
    tcc_ಕೂಡಿಸು_crt(s1, "crtn.o");
#ಅಥವಾಆದರೆ TARGETOS_ANDROID
    ಆದರೆ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_ಕೂಡಿಸು_crt(s1, "crtend_so.o");
    ಇಲ್ಲದಿದ್ದರೆ
        tcc_ಕೂಡಿಸು_crt(s1, "crtend_android.o");
#ಇಲ್ಲದಿದ್ದರೆ
    tcc_ಕೂಡಿಸು_crt(s1, "crtn.o");
#ಆದರೆ_ಅಂತ್ಯ
}
#ಆದರೆ_ಅಂತ್ಯ /* TCC_TARGET_UNIX */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_PE
/* add tcc runtime libraries */
ST_FUNC ಶೂನ್ಯ tcc_ಕೂಡಿಸು_runtime(TCCState *s1)
{
    s1->filetype = 0;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    tcc_ಕೂಡಿಸು_bcheck(s1);
#ಆದರೆ_ಅಂತ್ಯ
    tcc_ಕೂಡಿಸು_pragma_libs(s1);

    /* add libc */
    ಆದರೆ (!s1->nostdlib) {
        ಪೂರ್ಣಾಂಕ lpthread = s1->option_pthread;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    ಆದರೆ (s1->output_type == TCC_OUTPUT_ಸ್ಮರಣೆ)
                tcc_ಕೂಡಿಸು_support(s1, "bcheck_run.o");
	    ಇಲ್ಲದಿದ್ದರೆ
                tcc_ಕೂಡಿಸು_support(s1, "bcheck.o");
# ಆದರೆ !(TARGETOS_OpenBSD || TARGETOS_NetBSD)
            tcc_ಕೂಡಿಸು_library(s1, "dl");
# endif
            lpthread = 1;
        }
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
        ಆದರೆ (s1->do_backtrace) {
            ಆದರೆ (s1->output_type & TCC_OUTPUT_EXE)
                tcc_ಕೂಡಿಸು_support(s1, "bt-exe.o");
            ಆದರೆ (s1->output_type != TCC_OUTPUT_DLL)
                tcc_ಕೂಡಿಸು_support(s1, "bt-log.o");
            tcc_ಕೂಡಿಸು_btstub(s1);
            lpthread = 1;
        }
#ಆದರೆ_ಅಂತ್ಯ
        ಆದರೆ (lpthread)
            tcc_ಕೂಡಿಸು_library(s1, "pthread");
        tcc_ಕೂಡಿಸು_library(s1, "c");
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_LIBGCC
        ಆದರೆ (!s1->static_link) {
            ಆದರೆ (TCC_LIBGCC[0] == '/')
                tcc_ಕೂಡಿಸು_file(s1, TCC_LIBGCC);
            ಇಲ್ಲದಿದ್ದರೆ
                tcc_ಕೂಡಿಸು_dll(s1, TCC_LIBGCC, AFF_PRINT_ERROR);
        }
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ defined TCC_ಗುರಿ_ARM && TARGETOS_FreeBSD
        tcc_ಕೂಡಿಸು_library(s1, "gcc_s"); // unwind code
#ಆದರೆ_ಅಂತ್ಯ
        ಆದರೆ (TCC_LIBTCC1[0]) {
            tcc_ಕೂಡಿಸು_support(s1, TCC_LIBTCC1);
            tcc_ಕೂಡಿಸು_library(s1, "c");
        }
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_MACHO
        ಆದರೆ (s1->output_type != TCC_OUTPUT_ಸ್ಮರಣೆ)
            tccelf_ಕೂಡಿಸು_crtend(s1);
#ಆದರೆ_ಅಂತ್ಯ
    }
}
#ಆದರೆ_ಅಂತ್ಯ /* ndef TCC_TARGET_PE */

/* set _etext/_edata/_end  f=0:set  f=1:when_needed  f=2,3:just_update */
ಸ್ಥಿರ ಶೂನ್ಯ ಗಣ_linker_sym(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, Section *sec, ಪೂರ್ಣಾಂಕ f)
{
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ, esym_ಸೂಚ್ಯಂಕ, defined;
    ElfW(Sym) *sym, *esym;
    sym_ಸೂಚ್ಯಂಕ = ಕಂಡುಹಿಡಿ_elf_sym(symtab_section, name);
    sym = (ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ + sym_ಸೂಚ್ಯಂಕ;
    esym_ಸೂಚ್ಯಂಕ = ಕಂಡುಹಿಡಿ_elf_sym(s1->dynsymtab_section, name);
    esym = (ElfW(Sym) *)s1->dynsymtab_section->ದತ್ತಾಂಶ + esym_ಸೂಚ್ಯಂಕ;
    defined = sym->st_shndx != SHN_UNDEF
        || (esym->st_shndx != SHN_UNDEF && esym->st_ಗಾತ್ರ);
    ಆಯ್ಕೆ (f) {
    ಸ್ಥಿತಿ 1: /* old symbols w/o '_' */
        ಆದರೆ (!(sym_ಸೂಚ್ಯಂಕ || esym_ಸೂಚ್ಯಂಕ) || defined)
            ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 0:
        ಆದರೆ (defined) {
            tcc_warning("linker symbol '%s' already defined", name);
            ನಿಲ್ಲಿಸು;
        }
        sym_ಸೂಚ್ಯಂಕ = ಗಣ_global_sym(s1, name, sec, -1);
        get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 1)->linker_sym = 1;
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ: /* update (bss only) */
        ಆದರೆ (get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->linker_sym)
            sym->st_ಮೌಲ್ಯ = sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    }
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
    ಆದರೆ (name[0] == '_')
        ಗಣ_linker_sym(s1, name + 1, sec, f + 1);
#ಆದರೆ_ಅಂತ್ಯ
}

/* add various standard linker symbols (must be done after the
   sections are filled (for example after allocating common
   symbols)) */
ಸ್ಥಿರ ಶೂನ್ಯ tcc_ಕೂಡಿಸು_linker_symbols(TCCState *s1)
{
    ಅಕ್ಷರ buf[1024];
    ಪೂರ್ಣಾಂಕ i;
    Section *s;

    ಗಣ_linker_sym(s1, "_etext", ಪಠ್ಯ_section, 0);
    ಗಣ_linker_sym(s1, "_edata", ದತ್ತಾಂಶ_section, 0);
    ಗಣ_linker_sym(s1, "_end", bss_section, 0);
#ಆದರೆ TARGETOS_OpenBSD
    ಗಣ_global_sym(s1, "__executable_start", ಖಾಲಿ, ELF_ಆರಂಭ_ADDR);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_RISCV64
    /* XXX should be .sdata+0x800, not .data+0x800 */
    ಗಣ_global_sym(s1, "__global_pointer$", ದತ್ತಾಂಶ_section, 0x800);
#ಆದರೆ_ಅಂತ್ಯ
    /* horrible new standard ldscript defines */
    ಕೂಡಿಸು_init_array_ನಿರೂಪಿಸುತ್ತದೆ(s1, ".preinit_array");
    ಕೂಡಿಸು_init_array_ನಿರೂಪಿಸುತ್ತದೆ(s1, ".init_array");
    ಕೂಡಿಸು_init_array_ನಿರೂಪಿಸುತ್ತದೆ(s1, ".fini_array");
    /* add start and stop symbols for sections whose name can be
       expressed in C */
    ಗಾಗಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ಆದರೆ ((s->sh_flags & SHF_ALLOC)
            && (s->sh_type == SHT_PROGBITS || s->sh_type == SHT_NOBITS
                || s->sh_type == SHT_STRTAB)) {
            /* check if section name can be expressed in C */
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p0, *p;
            p0 = s->name;
            ಆದರೆ (*p0 == '.')
                ++p0;
            p = p0;
            ಗಾಗಿ(;;) {
                ಪೂರ್ಣಾಂಕ c = *p;
                ಆದರೆ (!c)
                    ನಿಲ್ಲಿಸು;
                ಆದರೆ (!isid(c) && !isnum(c))
                    ಹೋಗು ಮುಂದಿನ_sec;
                p++;
            }
            snprintf(buf, ಗಾತ್ರ(buf), "__start_%s", p0);
            ಗಣ_global_sym(s1, buf, s, 0);
            snprintf(buf, ಗಾತ್ರ(buf), "__stop_%s", p0);
            ಗಣ_global_sym(s1, buf, s, -1);
        }
    ಮುಂದಿನ_sec: ;
    }
}

ST_FUNC ಶೂನ್ಯ resolve_common_syms(TCCState *s1)
{
    ElfW(Sym) *sym;

    /* Allocate common symbols in BSS.  */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ಆದರೆ (sym->st_shndx == SHN_COMMON && sym->st_ಗಾತ್ರ) {
            /* symbol alignment is in st_value for SHN_COMMONs */
	    sym->st_ಮೌಲ್ಯ = section_ಕೂಡಿಸು(bss_section, sym->st_ಗಾತ್ರ,
					sym->st_ಮೌಲ್ಯ);
            sym->st_shndx = bss_section->sh_ಅಂಕೆ;
        }
    }

    /* Now assign linker provided symbols their value.  */
    ಆದರೆ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_ಕೂಡಿಸು_linker_symbols(s1);
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
ST_FUNC ಶೂನ್ಯ fill_got_ನಮೂದು(TCCState *s1, ElfW_Rel *rel)
{
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM) (rel->r_info);
    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
    ರಚನೆ sym_attr *attr = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0);
    ಚಿಹ್ನೆರಹಿತ ಸ್ಥಾನಾಂತರ = attr->got_ಸ್ಥಾನಾಂತರ;

    ಆದರೆ (0 == ಸ್ಥಾನಾಂತರ)
        ಹಿಂತಿರುಗಿ;
    section_reserve(s1->got, ಸ್ಥಾನಾಂತರ + PTR_ಗಾತ್ರ);
#ಆದರೆ PTR_ಗಾತ್ರ == 8
    write64le(s1->got->ದತ್ತಾಂಶ + ಸ್ಥಾನಾಂತರ, sym->st_ಮೌಲ್ಯ);
#ಇಲ್ಲದಿದ್ದರೆ
    write32le(s1->got->ದತ್ತಾಂಶ + ಸ್ಥಾನಾಂತರ, sym->st_ಮೌಲ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ
}

/* Perform relocation to GOT or PLT entries */
ST_FUNC ಶೂನ್ಯ fill_got(TCCState *s1)
{
    Section *s;
    ElfW_Rel *rel;
    ಪೂರ್ಣಾಂಕ i;

    ಗಾಗಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ಆದರೆ (s->sh_type != SHT_RELX)
            ಮುಂದುವರಿ;
        /* no need to handle got relocations */
        ಆದರೆ (s->link != symtab_section)
            ಮುಂದುವರಿ;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            ಆಯ್ಕೆ (ELFW(R_TYPE) (rel->r_info)) {
                ಸ್ಥಿತಿ R_X86_64_GOT32:
                ಸ್ಥಿತಿ R_X86_64_GOTPCREL:
		ಸ್ಥಿತಿ R_X86_64_GOTPCRELX:
		ಸ್ಥಿತಿ R_X86_64_REX_GOTPCRELX:
                ಸ್ಥಿತಿ R_X86_64_PLT32:
                    fill_got_ನಮೂದು(s1, rel);
                    ನಿಲ್ಲಿಸು;
            }
        }
    }
}

/* See put_got_entry for a description.  This is the second stage
   where GOT references to local defined symbols are rewritten.  */
ಸ್ಥಿರ ಶೂನ್ಯ fill_local_got_entries(TCCState *s1)
{
    ElfW_Rel *rel;
    ಆದರೆ (!s1->got->reloc)
        ಹಿಂತಿರುಗಿ;
    for_each_elem(s1->got->reloc, 0, rel, ElfW_Rel) {
	ಆದರೆ (ELFW(R_TYPE)(rel->r_info) == R_RELATIVE) {
	    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM) (rel->r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
	    ರಚನೆ sym_attr *attr = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0);
	    ಚಿಹ್ನೆರಹಿತ ಸ್ಥಾನಾಂತರ = attr->got_ಸ್ಥಾನಾಂತರ;
	    ಆದರೆ (ಸ್ಥಾನಾಂತರ != rel->r_ಸ್ಥಾನಾಂತರ - s1->got->sh_addr)
	        tcc_error_noabort("fill_local_got_entries: huh?");
	    rel->r_info = ELFW(R_INFO)(0, R_RELATIVE);
#ಆದರೆ SHT_RELX == SHT_RELA
	    rel->r_addend = sym->st_ಮೌಲ್ಯ;
#ಇಲ್ಲದಿದ್ದರೆ
	    /* All our REL architectures also happen to be 32bit LE.  */
	    write32le(s1->got->ದತ್ತಾಂಶ + ಸ್ಥಾನಾಂತರ, sym->st_ಮೌಲ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ
	}
    }
}

/* Bind symbols of executable: resolve undefined symbols from exported symbols
   in shared libraries */
ಸ್ಥಿರ ಶೂನ್ಯ bind_exe_dynsyms(TCCState *s1, ಪೂರ್ಣಾಂಕ is_PIE)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ, ಸೂಚ್ಯಂಕ;
    ElfW(Sym) *sym, *esym;
    ಪೂರ್ಣಾಂಕ type;

    /* Resolve undefined symbols from dynamic symbols. When there is a match:
       - if STT_FUNC or STT_GNU_IFUNC symbol -> add it in PLT
       - if STT_OBJECT symbol -> add it in .bss section with suitable reloc */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ಆದರೆ (sym->st_shndx == SHN_UNDEF
            /* bss symbols may be initialized in the shared library */
            || sym->st_shndx == SHN_COMMON
            || sym->st_shndx == bss_section->sh_ಅಂಕೆ) {
            name = (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
            sym_ಸೂಚ್ಯಂಕ = ಕಂಡುಹಿಡಿ_elf_sym(s1->dynsymtab_section, name);
            esym = &((ElfW(Sym) *)s1->dynsymtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
            ಆದರೆ (sym_ಸೂಚ್ಯಂಕ && esym->st_shndx != SHN_UNDEF) {
                ಆದರೆ (is_PIE)
                    ಮುಂದುವರಿ;
                type = ELFW(ST_TYPE)(esym->st_info);
                ಆದರೆ ((type == STT_FUNC) || (type == STT_GNU_IFUNC)) {
                    /* Indirect functions shall have STT_FUNC type in executable
                     * dynsym section. Indeed, a dlsym call following a lazy
                     * resolution would pick the symbol value from the
                     * executable dynsym entry which would contain the address
                     * of the function wanted by the caller of dlsym instead of
                     * the address of the function that would return that
                     * address */
                    ಪೂರ್ಣಾಂಕ dynindex
		      = put_elf_sym(s1->dynsym, 0, esym->st_ಗಾತ್ರ,
				    ELFW(ST_INFO)(STB_GLOBAL,STT_FUNC), 0, 0,
				    name);
		    ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ = sym - (ElfW(Sym) *) symtab_section->ದತ್ತಾಂಶ;
		    get_sym_attr(s1, ಸೂಚ್ಯಂಕ, 1)->dyn_ಸೂಚ್ಯಂಕ = dynindex;
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (type == STT_OBJECT) {
                    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ;
                    ElfW(Sym) *dynsym;
                    ಆದರೆ (sym->st_shndx == bss_section->sh_ಅಂಕೆ) {
                        ಸ್ಥಾನಾಂತರ = sym->st_ಮೌಲ್ಯ;
                    } ಇಲ್ಲದಿದ್ದರೆ {
                        ಸ್ಥಾನಾಂತರ = bss_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
                        /* XXX: which alignment ? */
                        ಸ್ಥಾನಾಂತರ = (ಸ್ಥಾನಾಂತರ + 16 - 1) & -16;
                        bss_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = ಸ್ಥಾನಾಂತರ + esym->st_ಗಾತ್ರ;
                    }
                    ಗಣ_elf_sym (s1->symtab, ಸ್ಥಾನಾಂತರ, esym->st_ಗಾತ್ರ,
                                 esym->st_info, 0, bss_section->sh_ಅಂಕೆ, name);
                    ಸೂಚ್ಯಂಕ = put_elf_sym(s1->dynsym, ಸ್ಥಾನಾಂತರ, esym->st_ಗಾತ್ರ,
                                        esym->st_info, 0, bss_section->sh_ಅಂಕೆ,
                                        name);
                    /* Ensure R_COPY works for weak symbol aliases */
                    ಆದರೆ (ELFW(ST_BIND)(esym->st_info) == STB_WEAK) {
                        for_each_elem(s1->dynsymtab_section, 1, dynsym, ElfW(Sym)) {
                            ಆದರೆ ((dynsym->st_ಮೌಲ್ಯ == esym->st_ಮೌಲ್ಯ)
                                && (ELFW(ST_BIND)(dynsym->st_info) == STB_GLOBAL)) {
                                ಅಕ್ಷರ *dynname = (ಅಕ್ಷರ *) s1->dynsymtab_section->link->ದತ್ತಾಂಶ
                                                + dynsym->st_name;
                                put_elf_sym(s1->dynsym, ಸ್ಥಾನಾಂತರ, dynsym->st_ಗಾತ್ರ,
                                            dynsym->st_info, 0,
                                            bss_section->sh_ಅಂಕೆ, dynname);
                                ನಿಲ್ಲಿಸು;
                            }
                        }
                    }
                    put_elf_reloc(s1->dynsym, bss_section,
                                  ಸ್ಥಾನಾಂತರ, R_COPY, ಸೂಚ್ಯಂಕ);
                }
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sym->st_shndx == SHN_UNDEF) {
                /* STB_WEAK undefined symbols are accepted */
                /* XXX: _fp_hw seems to be part of the ABI, so we ignore it */
                ಆದರೆ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK ||
                    !strcmp(name, "_fp_hw")) {
                } ಇಲ್ಲದಿದ್ದರೆ {
                    tcc_error_noabort("unresolved reference to '%s'", name);
                }
            }
        }
    }
    /* update _end symbol with new bss length */
    ಗಣ_linker_sym(s1, "_end", bss_section, 2);
}

/* Bind symbols of libraries: export all non local symbols of executable that
   are referenced by shared libraries. The reason is that the dynamic loader
   search symbol first in executable and then in libraries. Therefore a
   reference to a symbol already defined by a library can still be resolved by
   a symbol in the executable.   With -rdynamic, export all defined symbols */
ಸ್ಥಿರ ಶೂನ್ಯ bind_libs_dynsyms(TCCState *s1)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
    ಪೂರ್ಣಾಂಕ dynsym_ಸೂಚ್ಯಂಕ;
    ElfW(Sym) *sym, *esym;

    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        name = (ಅಕ್ಷರ *)symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
        dynsym_ಸೂಚ್ಯಂಕ = ಕಂಡುಹಿಡಿ_elf_sym(s1->dynsymtab_section, name);
        ಆದರೆ (sym->st_shndx != SHN_UNDEF) {
            ಆದರೆ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL
                && (dynsym_ಸೂಚ್ಯಂಕ || s1->rdynamic))
                ಗಣ_elf_sym(s1->dynsym, sym->st_ಮೌಲ್ಯ, sym->st_ಗಾತ್ರ,
                            sym->st_info, 0, sym->st_shndx, name);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (dynsym_ಸೂಚ್ಯಂಕ) {
            esym = (ElfW(Sym) *)s1->dynsymtab_section->ದತ್ತಾಂಶ + dynsym_ಸೂಚ್ಯಂಕ;
            ಆದರೆ (esym->st_shndx == SHN_UNDEF) {
                /* weak symbols can stay undefined */
                ಆದರೆ (ELFW(ST_BIND)(esym->st_info) != STB_WEAK)
                    tcc_warning("unresolved dynamic reference to '%s'", name);
            }
        }
    }
}

/* Export all non local symbols. This is used by shared libraries so that the
   non local symbols they define can resolve a reference in another shared
   library or in the executable. Correspondingly, it allows undefined local
   symbols to be resolved by other shared libraries or by the executable. */
ಸ್ಥಿರ ಶೂನ್ಯ export_global_syms(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ dynindex, ಸೂಚ್ಯಂಕ;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
    ElfW(Sym) *sym;
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ಆದರೆ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
	    name = (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
	    dynindex = ಗಣ_elf_sym(s1->dynsym, sym->st_ಮೌಲ್ಯ, sym->st_ಗಾತ್ರ,
				   sym->st_info, 0, sym->st_shndx, name);
	    ಸೂಚ್ಯಂಕ = sym - (ElfW(Sym) *) symtab_section->ದತ್ತಾಂಶ;
            get_sym_attr(s1, ಸೂಚ್ಯಂಕ, 1)->dyn_ಸೂಚ್ಯಂಕ = dynindex;
        }
    }
}

/* decide if an unallocated section should be output. */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಗಣ_sec_sizes(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ i;
    Section *s;
    ಪೂರ್ಣಾಂಕ textrel = 0;
    ಪೂರ್ಣಾಂಕ file_type = s1->output_type;

    /* Allocate strings for section names */
    ಗಾಗಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ಆದರೆ (s->sh_type == SHT_RELX && !(s->sh_flags & SHF_ALLOC)) {
            /* when generating a DLL, we include relocations but
               we may patch them */
            ಆದರೆ ((file_type & TCC_OUTPUT_DYN)
                && (s1->sections[s->sh_info]->sh_flags & SHF_ALLOC)) {
                ಪೂರ್ಣಾಂಕ ಎಣಿಕೆ_3 = prepare_dynamic_rel(s1, s);
                ಆದರೆ (ಎಣಿಕೆ_3) {
                    /* allocate the section */
                    s->sh_flags |= SHF_ALLOC;
                    s->sh_ಗಾತ್ರ = ಎಣಿಕೆ_3 * ಗಾತ್ರ(ElfW_Rel);
                    ಆದರೆ (s1->sections[s->sh_info]->sh_flags & SHF_EXECINSTR)
                        textrel += ಎಣಿಕೆ_3;
                }
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((s->sh_flags & SHF_ALLOC)
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
                   || s->sh_type == SHT_ARM_ಗುಣಲಕ್ಷಣಗಳು
#ಆದರೆ_ಅಂತ್ಯ
                   || s1->do_debug) {
            s->sh_ಗಾತ್ರ = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
        }
    }
    ಹಿಂತಿರುಗಿ textrel;
}

/* various data used under elf_output_file() */
ರಚನೆ dyn_inf {
    Section *dynamic;
    Section *dynstr;
    Section *interp;
    Section *note;
    Section *gnu_hash;
    ರಚನೆ {
        /* Info to be copied in dynamic section */
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
        addr_t rel_addr;
        addr_t rel_ಗಾತ್ರ;
    };

    ElfW(Phdr) *phdr;
    ಪೂರ್ಣಾಂಕ phnum;
    ಪೂರ್ಣಾಂಕ shnum;
    ಪೂರ್ಣಾಂಕ tls;
    ಪೂರ್ಣಾಂಕ relro;
    ಪೂರ್ಣಾಂಕ notes;
    ಪೂರ್ಣಾಂಕ ehfr;
    ಪೂರ್ಣಾಂಕ dyna;
};

/* Decide the layout of sections loaded in memory. This must be done before
   program headers are filled since they contain info about the layout.
   We do the following ordering: interp, symbol tables, relocations, progbits,
   nobits */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ವಿಂಗಡಿಸು_sections(TCCState *s1, ಪೂರ್ಣಾಂಕ *sec_ಕ್ರಮ, ರಚನೆ dyn_inf *d)
{
    Section *s;
    ಪೂರ್ಣಾಂಕ i, j, k, f, f0, n;
    ಪೂರ್ಣಾಂಕ nb_sections = s1->nb_sections;
    ಪೂರ್ಣಾಂಕ *sec_cls = sec_ಕ್ರಮ + nb_sections;
    ಪೂರ್ಣಾಂಕ tls_align = 0; /* need common alignment for all tls sections */

    ಗಾಗಿ (i = 1; i < nb_sections; i++) {
        s = s1->sections[i];
        ಆದರೆ (0 == s->sh_name) {
            j = 0x900; /* no sh_name: won't go to file */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_flags & SHF_ALLOC) {
            j = 0x100;
            ಆದರೆ ((s->sh_flags & (SHF_WRITE|SHF_TLS)) == SHF_WRITE)
                j = 0x200;
        } ಇಲ್ಲದಿದ್ದರೆ {
            j = 0x700;
        }
        ಆದರೆ (j >= 0x700 && s1->output_format != TCC_OUTPUT_FORMAT_ELF)
            s->sh_ಗಾತ್ರ = 0, j = 0x900;

        ಆದರೆ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM) {
            k = 0x10;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_type == SHT_STRTAB && strcmp(s->name, ".stabstr")) {
            k = 0x11;
            ಆದರೆ (i == nb_sections - 1) /* ".shstrtab" assumed to stay last */
                k = 0xff;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_type == SHT_HASH || s->sh_type == SHT_GNU_HASH) {
            k = 0x12;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_type == SHT_GNU_verdef
                  || s->sh_type == SHT_GNU_verneed
                  || s->sh_type == SHT_GNU_versym) {
            k = 0x13;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_type == SHT_RELX) {
            k = 0x20;
            ಆದರೆ (s1->plt && s == s1->plt->reloc)
                k = 0x21;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_flags & SHF_EXECINSTR) {
            k = 0x60;
        /* RELRO sections --> */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_flags & SHF_TLS) {
            ಆದರೆ (s->sh_addralign > tls_align)
                tls_align = s->sh_addralign;
            k = 0x40 + (s->sh_type == SHT_NOBITS);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_type == SHT_PREINIT_ARRAY) {
            k = 0x42;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_type == SHT_INIT_ARRAY) {
            k = 0x43;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_type == SHT_FINI_ARRAY) {
            k = 0x44;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_type == SHT_DYNAMIC) {
            k = 0x48;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == s1->got) {
            k = 0x49; /* .got as RELRO needs BIND_NOW in DT_FLAGS */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->reloc && (s->reloc->sh_flags & SHF_ALLOC) && j == 0x100) {
            k = 0x45; /* +1 for data.ro */
        /* <-- */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_type == SHT_NOTE) {
            k = 0x08, d->notes = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_type == SHT_NOBITS) {
            k = 0x70; /* bss */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == d->interp) {
            k = 0x00;
        } ಇಲ್ಲದಿದ್ದರೆ {
            k = 0x50; /*ದತ್ತಾಂಶ*/
        }
        k += j;
        /* make our standard sections come last to have _etext/_edata correct values */
        ಆದರೆ (s->sh_ಅಂಕೆ <= bss_section->sh_ಅಂಕೆ)
            ++k;
        /* make RELRO section writable */
        ಆದರೆ ((k & 0xfff0) == 0x140)
            k += 0x100, s->sh_flags |= SHF_WRITE;
        /* sort by insert */
        ಗಾಗಿ (n = i; n > 1 && k < (f = sec_cls[n - 1]); --n)
            sec_cls[n] = f, sec_ಕ್ರಮ[n] = sec_ಕ್ರಮ[n - 1];
        sec_cls[n] = k, sec_ಕ್ರಮ[n] = i;
    }
    sec_ಕ್ರಮ[0] = 0;
    d->shnum = 1;

#ವ್ಯಾಖ್ಯಾನಿಸು SHFX_NEWPH (1 << 4)
#ವ್ಯಾಖ್ಯಾನಿಸು SHFX_RELRO (1 << 5)

    /* count PT_LOAD headers needed */
    n = f0 = 0;
    ಗಾಗಿ (i = 1; i < nb_sections; i++) {
        s = s1->sections[sec_ಕ್ರಮ[i]];
        k = sec_cls[i];
        f = 0;
        ಆದರೆ (k < 0x900)
            ++d->shnum;
        ಆದರೆ (k < 0x700) {
            f = s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR);
#ಆದರೆ TARGETOS_NetBSD || TARGETOS_FreeBSD
	    /* NetBSD only supports 2 PT_LOAD sections.
	       See: https://blog.netbsd.org/tnf/entry/the_first_report_on_lld */
	    ಆದರೆ ((f & SHF_WRITE) == 0)
                f |= SHF_EXECINSTR;
            k = 0; /* no relro */
#ಆದರೆ_ಅಂತ್ಯ
            ಆದರೆ ((k & 0xfff0) == 0x240) /* RELRO sections */
                d->relro = 1, f |= SHFX_RELRO;
            /* start new header when flags changed, but avoid zero memsz */
            ಆದರೆ (f != f0 && s->sh_ಗಾತ್ರ)
                f0 = f, ++n, f |= SHFX_NEWPH;
            ಆದರೆ ((s->sh_flags & SHF_TLS) && s->sh_ಗಾತ್ರ) {
                s->sh_addralign = tls_align;
                d->tls = 1, f |= SHF_TLS;
            }
        }
        sec_cls[i] = f;
        //printf("ph %d sec %02d : %3X %3X  %8.2X  %04X  %s\n", (f>0) * n, i, f, k, s->sh_type, (int)s->sh_size, s->name);
    }
    ಹಿಂತಿರುಗಿ n;
}

ಸ್ಥಿರ ElfW(Phdr) *fill_phdr(ElfW(Phdr) *ph, ಪೂರ್ಣಾಂಕ type, Section *s)
{
    ph->p_type = type;
    ph->p_flags = PF_R;
    ಆದರೆ (s) {
        ಆದರೆ (s->sh_flags & SHF_WRITE)
            ph->p_flags |= PF_W;
        ph->p_ಸ್ಥಾನಾಂತರ = s->sh_ಸ್ಥಾನಾಂತರ;
        ph->p_vaddr = s->sh_addr;
        ph->p_filesz = s->sh_ಗಾತ್ರ;
        ph->p_align = s->sh_addralign;
    }
    ph->p_paddr = ph->p_vaddr;
    ph->p_memsz = ph->p_filesz;
    ಹಿಂತಿರುಗಿ ph;
}

ಸ್ಥಿರ ElfW(Phdr) *update_phdr(ElfW(Phdr) *ph, ಪೂರ್ಣಾಂಕ type, Section *s, addr_t addr, ಪೂರ್ಣಾಂಕ file_ಸ್ಥಾನಾಂತರ)
{
    ಆದರೆ (ph->p_type == 0) {
        fill_phdr(ph, type, s);
    }
    ph->p_filesz = file_ಸ್ಥಾನಾಂತರ - ph->p_ಸ್ಥಾನಾಂತರ;
    ph->p_memsz = addr - ph->p_vaddr;
    ಹಿಂತಿರುಗಿ ph;
}

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ layout_sections(TCCState *s1, ಪೂರ್ಣಾಂಕ *sec_ಕ್ರಮ, ರಚನೆ dyn_inf *d)
{
    Section *s;
    addr_t addr, tmp, align, s_align, ತಳ;
    ElfW(Phdr) *ph = ಖಾಲಿ, *ph2;
    ಪೂರ್ಣಾಂಕ i, f, n, phnum, phfill;
    ಪೂರ್ಣಾಂಕ file_ಸ್ಥಾನಾಂತರ;

    /* compute number of program headers */
    phnum = ವಿಂಗಡಿಸು_sections(s1, sec_ಕ್ರಮ, d);
    phfill = 0; /* set to 1 to have dll's with a PT_PHDR */
    ಆದರೆ (d->interp)
        phfill = 2;
    phnum += phfill;
    ಆದರೆ (d->dynamic)
        d->dyna = phnum++;
    ಆದರೆ (d->notes)
        d->notes = phnum++;
    ಆದರೆ (d->tls)
        d->tls = phnum++;
    ಆದರೆ (eh_ಚೌಕಟ್ಟು_hdr_section)
        d->ehfr = phnum++;
    ಆದರೆ (d->relro)
        d->relro = phnum++;
    d->phnum = phnum;
    d->phdr = tcc_mallocz(phnum * ಗಾತ್ರ(ElfW(Phdr)));

    file_ಸ್ಥಾನಾಂತರ = 0;
    ಆದರೆ (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
        file_ಸ್ಥಾನಾಂತರ = (ಗಾತ್ರ(ElfW(Ehdr)) + phnum * ಗಾತ್ರ(ElfW(Phdr)) + 3) & -4;
        file_ಸ್ಥಾನಾಂತರ += d->shnum * ಗಾತ್ರ (ElfW(Shdr));
    }

    s_align = ELF_ಪುಟ_ಗಾತ್ರ;
    ಆದರೆ (s1->section_align)
        s_align = s1->section_align;

    addr = ELF_ಆರಂಭ_ADDR;
    ಆದರೆ (s1->output_type & TCC_OUTPUT_DYN)
        addr = 0;

    ಆದರೆ (s1->has_ಪಠ್ಯ_addr) {
        addr = s1->ಪಠ್ಯ_addr;
        ಆದರೆ (0) {
            ಪೂರ್ಣಾಂಕ a_ಸ್ಥಾನಾಂತರ, p_ಸ್ಥಾನಾಂತರ;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_ಸ್ಥಾನಾಂತರ = (ಪೂರ್ಣಾಂಕ) (addr & (s_align - 1));
            p_ಸ್ಥಾನಾಂತರ = file_ಸ್ಥಾನಾಂತರ & (s_align - 1);
            ಆದರೆ (a_ಸ್ಥಾನಾಂತರ < p_ಸ್ಥಾನಾಂತರ)
                a_ಸ್ಥಾನಾಂತರ += s_align;
            file_ಸ್ಥಾನಾಂತರ += (a_ಸ್ಥಾನಾಂತರ - p_ಸ್ಥಾನಾಂತರ);
        }
    }
    ತಳ = addr;
    /* compute address after headers */
    addr += file_ಸ್ಥಾನಾಂತರ;

    n = 0;
    ಗಾಗಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_ಕ್ರಮ[i]];
        f = sec_ಕ್ರಮ[i + s1->nb_sections];
        align = s->sh_addralign - 1;

        ಆದರೆ (f == 0) { /* no alloc */
            file_ಸ್ಥಾನಾಂತರ = (file_ಸ್ಥಾನಾಂತರ + align) & ~align;
            s->sh_ಸ್ಥಾನಾಂತರ = file_ಸ್ಥಾನಾಂತರ;
            ಆದರೆ (s->sh_type != SHT_NOBITS)
                file_ಸ್ಥಾನಾಂತರ += s->sh_ಗಾತ್ರ;
            ಮುಂದುವರಿ;
        }

        ಆದರೆ ((f & SHFX_NEWPH) && n) {
            /* different rwx section flags */
            ಆದರೆ (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
                /* if in the middle of a page, w e duplicate the page in
                   memory so that one copy is RX and the other is RW */
                ಆದರೆ ((addr & (s_align - 1)) != 0)
                    addr += s_align;
            } ಇಲ್ಲದಿದ್ದರೆ {
                align = s_align - 1;
            }
        }

        tmp = addr;
        addr = (addr + align) & ~align;
        file_ಸ್ಥಾನಾಂತರ += (ಪೂರ್ಣಾಂಕ)(addr - tmp);
        s->sh_ಸ್ಥಾನಾಂತರ = file_ಸ್ಥಾನಾಂತರ;
        s->sh_addr = addr;

        //printf("%d : %08x %08x %04x %03x %s %d\n", n, (int)file_offset, (int)addr, (int)s->sh_size, s->sh_type, s->name, align + 1);
        addr += s->sh_ಗಾತ್ರ;
        ಆದರೆ (s->sh_type != SHT_NOBITS)
            file_ಸ್ಥಾನಾಂತರ += s->sh_ಗಾತ್ರ;

        ಆದರೆ (f & SHFX_NEWPH) {
            /* set new program header */
            ph = &d->phdr[phfill + n];
            fill_phdr(ph, PT_ತುಂಬು, s);
            ph->p_align = s_align;
            ಆದರೆ (f & SHF_EXECINSTR)
                ph->p_flags |= PF_X;
            ಆದರೆ (n == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_ಸ್ಥಾನಾಂತರ = 0;
                ph->p_paddr = ph->p_vaddr = ತಳ;
            }
            ++n;
        }

        ಆದರೆ (ph)
            update_phdr(ph, 0, 0, addr, file_ಸ್ಥಾನಾಂತರ);

        ಆದರೆ (f & SHFX_RELRO) {
            ph2 = update_phdr(&d->phdr[d->relro], PT_GNU_RELRO, s, addr, file_ಸ್ಥಾನಾಂತರ);
            ph2->p_align = 1;
        }
        ಆದರೆ (f & SHF_TLS) {
            ph2 = update_phdr(&d->phdr[d->tls], PT_TLS, s, addr, file_ಸ್ಥಾನಾಂತರ);
            ಆದರೆ (s->sh_type == SHT_NOBITS)
                addr -= s->sh_ಗಾತ್ರ;
            /* for xxx-link.c:relocate() */
            s1->tls_ಆರಂಭ = ph2->p_vaddr;
            s1->tls_ಕೊನೆ = s1->tls_ಆರಂಭ + ph2->p_memsz + (-ph2->p_memsz & (ph2->p_align - 1));
        }
        ಆದರೆ (s->sh_type == SHT_NOTE) {
            update_phdr(&d->phdr[d->notes], PT_NOTE, s, addr, file_ಸ್ಥಾನಾಂತರ);
        }
    }

    /* Fill other headers */
    ಆದರೆ (d->dyna)
        fill_phdr(&d->phdr[d->dyna], PT_DYNAMIC, d->dynamic);
    ಆದರೆ (d->ehfr)
        fill_phdr(&d->phdr[d->ehfr], PT_GNU_EH_ಚೌಕಟ್ಟು, eh_ಚೌಕಟ್ಟು_hdr_section);
    ಆದರೆ (d->interp)
        fill_phdr(&d->phdr[1], PT_INTERP, d->interp);
    ಆದರೆ (phfill) {
        ph = &d->phdr[0];
        ph->p_ಸ್ಥಾನಾಂತರ = ಗಾತ್ರ(ElfW(Ehdr));
        ph->p_vaddr = ತಳ + ph->p_ಸ್ಥಾನಾಂತರ;
        ph->p_filesz = phnum * ಗಾತ್ರ(ElfW(Phdr));
        ph->p_align = 4;
        fill_phdr(ph, PT_PHDR, ಖಾಲಿ);
    }
    ಹಿಂತಿರುಗಿ 0;
}

/* put dynamic tag */
ಸ್ಥಿರ ಶೂನ್ಯ put_dt(Section *dynamic, ಪೂರ್ಣಾಂಕ dt, addr_t val)
{
    ElfW(Dyn) *dyn;
    dyn = section_ptr_ಕೂಡಿಸು(dynamic, ಗಾತ್ರ(ElfW(Dyn)));
    dyn->d_ಟ್ಯಾಗ್ = dt;
    dyn->d_un.d_val = val;
}

/* Fill the dynamic section with tags describing the address and size of
   sections */
ಸ್ಥಿರ ಶೂನ್ಯ fill_dynamic(TCCState *s1, ರಚನೆ dyn_inf *dyninf)
{
    Section *dynamic = dyninf->dynamic;
    Section *s;

    /* put dynamic section entries */
    put_dt(dynamic, DT_HASH, s1->dynsym->hash->sh_addr);
    put_dt(dynamic, DT_GNU_HASH, dyninf->gnu_hash->sh_addr);
    put_dt(dynamic, DT_STRTAB, dyninf->dynstr->sh_addr);
    put_dt(dynamic, DT_SYMTAB, s1->dynsym->sh_addr);
    put_dt(dynamic, DT_STRSZ, dyninf->dynstr->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
    put_dt(dynamic, DT_SYMENT, ಗಾತ್ರ(ElfW(Sym)));
#ಆದರೆ PTR_ಗಾತ್ರ == 8
    put_dt(dynamic, DT_RELA, dyninf->rel_addr);
    put_dt(dynamic, DT_RELASZ, dyninf->rel_ಗಾತ್ರ);
    put_dt(dynamic, DT_RELAENT, ಗಾತ್ರ(ElfW_Rel));
    ಆದರೆ (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_RELA);
    }
    put_dt(dynamic, DT_RELACOUNT, 0);
#ಇಲ್ಲದಿದ್ದರೆ
    put_dt(dynamic, DT_REL, dyninf->rel_addr);
    put_dt(dynamic, DT_RELSZ, dyninf->rel_ಗಾತ್ರ);
    put_dt(dynamic, DT_RELENT, ಗಾತ್ರ(ElfW_Rel));
    ಆದರೆ (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_REL);
    }
    put_dt(dynamic, DT_RELCOUNT, 0);
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (versym_section && verneed_section) {
	/* The dynamic linker can not handle VERSYM without VERNEED */
        put_dt(dynamic, DT_VERSYM, versym_section->sh_addr);
        put_dt(dynamic, DT_VERNEED, verneed_section->sh_addr);
        put_dt(dynamic, DT_VERNEEDNUM, dt_verneednum);
    }
    s = have_section(s1, ".preinit_array");
    ಆದರೆ (s && s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        put_dt(dynamic, DT_PREINIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_PREINIT_ARRAYSZ, s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
    }
    s = have_section(s1, ".init_array");
    ಆದರೆ (s && s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        put_dt(dynamic, DT_INIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_INIT_ARRAYSZ, s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
    }
    s = have_section(s1, ".fini_array");
    ಆದರೆ (s && s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        put_dt(dynamic, DT_FINI_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_FINI_ARRAYSZ, s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
    }
    s = have_section(s1, ".init");
    ಆದರೆ (s && s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        put_dt(dynamic, DT_INIT, s->sh_addr);
    }
    s = have_section(s1, ".fini");
    ಆದರೆ (s && s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        put_dt(dynamic, DT_FINI, s->sh_addr);
    }
    ಆದರೆ (s1->do_debug)
        put_dt(dynamic, DT_DEBUG, 0);
    put_dt(dynamic, DT_NULL, 0);
}

/* Remove gaps between RELX sections.
   These gaps are a result of final_sections_reloc. Here some relocs are removed.
   The gaps are then filled with 0 in tcc_output_elf. The 0 is intepreted as
   R_...NONE reloc. This does work on most targets but on OpenBSD/arm64 this
   is illegal. OpenBSD/arm64 does not support R_...NONE reloc. */
ಸ್ಥಿರ ಶೂನ್ಯ update_reloc_sections(TCCState *s1, ರಚನೆ dyn_inf *dyninf)
{
    ಪೂರ್ಣಾಂಕ i;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ file_ಸ್ಥಾನಾಂತರ = 0;
    Section *s;
    Section *relocplt = s1->plt ? s1->plt->reloc : ಖಾಲಿ;

    /* dynamic relocation table information, for .dynamic section */
    dyninf->rel_addr = dyninf->rel_ಗಾತ್ರ = 0;

    ಗಾಗಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
	ಆದರೆ (s->sh_type == SHT_RELX && s != relocplt) {
	    ಆದರೆ (dyninf->rel_ಗಾತ್ರ == 0) {
		dyninf->rel_addr = s->sh_addr;
		file_ಸ್ಥಾನಾಂತರ = s->sh_ಸ್ಥಾನಾಂತರ;
	    }
	    ಇಲ್ಲದಿದ್ದರೆ {
		s->sh_addr = dyninf->rel_addr + dyninf->rel_ಗಾತ್ರ;
		s->sh_ಸ್ಥಾನಾಂತರ = file_ಸ್ಥಾನಾಂತರ + dyninf->rel_ಗಾತ್ರ;
	    }
	    dyninf->rel_ಗಾತ್ರ += s->sh_ಗಾತ್ರ;
	}
    }
}
#ಆದರೆ_ಅಂತ್ಯ /* ndef ELF_OBJ_ONLY */

/* Create an ELF file on disk.
   This function handle ELF specific layout requirements */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_output_elf(TCCState *s1, FILE *f, ಪೂರ್ಣಾಂಕ phnum, ElfW(Phdr) *phdr)
{
    ಪೂರ್ಣಾಂಕ i, shnum, ಸ್ಥಾನಾಂತರ, ಗಾತ್ರ_2, file_type;
    Section *s;
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) shdr, *sh;

    file_type = s1->output_type;
    shnum = s1->nb_sections;

    memset(&ehdr, 0, ಗಾತ್ರ(ehdr));
    ಆದರೆ (phnum > 0) {
        ehdr.e_phentsize = ಗಾತ್ರ(ElfW(Phdr));
        ehdr.e_phnum = phnum;
        ehdr.e_phoff = ಗಾತ್ರ(ElfW(Ehdr));
    }

    /* fill header */
    ehdr.e_ident[0] = ELFMAG0;
    ehdr.e_ident[1] = ELFMAG1;
    ehdr.e_ident[2] = ELFMAG2;
    ehdr.e_ident[3] = ELFMAG3;
    ehdr.e_ident[4] = ELFCLASSW;
    ehdr.e_ident[5] = ELFDATA2LSB;
    ehdr.e_ident[6] = EV_CURRENT;

#ಆದರೆ TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    ehdr.e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
#ಅಥವಾಆದರೆ TARGETOS_OpenBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_OPENBSD;
#ಅಥವಾಆದರೆ TARGETOS_NetBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_NETBSD;
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM && defined TCC_ARM_EABI
    ehdr.e_flags = EF_ARM_EABI_VER5;
    ehdr.e_flags |= s1->float_abi == ARM_HARD_FLOAT
        ? EF_ARM_VFP_FLOAT : EF_ARM_SOFT_FLOAT;
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_RISCV64
    /* XXX should be configurable */
    ehdr.e_flags = EF_RISCV_FLOAT_ABI_DOUBLE;
#ಆದರೆ_ಅಂತ್ಯ

    ಆದರೆ (file_type == TCC_OUTPUT_OBJ) {
        ehdr.e_type = ET_REL;
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ (file_type & TCC_OUTPUT_DYN)
            ehdr.e_type = ET_DYN;
        ಇಲ್ಲದಿದ್ದರೆ
            ehdr.e_type = ET_EXEC;
        ಆದರೆ (s1->elf_entryname)
            ehdr.e_ನಮೂದು = get_sym_addr(s1, s1->elf_entryname, 1, 0);
        ಇಲ್ಲದಿದ್ದರೆ
            ehdr.e_ನಮೂದು = get_sym_addr(s1, "_start", !!(file_type & TCC_OUTPUT_EXE), 0);
        ಆದರೆ (ehdr.e_ನಮೂದು == (addr_t)-1)
            ehdr.e_ನಮೂದು = ಪಠ್ಯ_section->sh_addr;
        ಆದರೆ (s1->nb_errors)
            ಹಿಂತಿರುಗಿ -1;
    }

    ವಿಂಗಡಿಸು_syms(s1, s1->symtab);

    ehdr.e_machine = EM_TCC_ಗುರಿ;
    ehdr.e_ಆವೃತ್ತಿ = EV_CURRENT;
    ehdr.e_shoff = (ಗಾತ್ರ(ElfW(Ehdr)) + phnum * ಗಾತ್ರ(ElfW(Phdr)) + 3) & -4;
    ehdr.e_ehsize = ಗಾತ್ರ(ElfW(Ehdr));
    ehdr.e_shentsize = ಗಾತ್ರ(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    ಸ್ಥಾನಾಂತರ = fwrite(&ehdr, 1, ಗಾತ್ರ(ElfW(Ehdr)), f);
    ಆದರೆ (phdr)
        ಸ್ಥಾನಾಂತರ += fwrite(phdr, 1, phnum * ಗಾತ್ರ(ElfW(Phdr)), f);

    /* output section headers */
    ಆಗ (ಸ್ಥಾನಾಂತರ < ehdr.e_shoff) {
        fputc(0, f);
        ಸ್ಥಾನಾಂತರ++;
    }

    ಗಾಗಿ(i = 0; i < shnum; i++) {
        sh = &shdr;
        memset(sh, 0, ಗಾತ್ರ(ElfW(Shdr)));
        ಆದರೆ (i) {
            s = s1->sections[i];
            sh->sh_name = s->sh_name;
            sh->sh_type = s->sh_type;
            sh->sh_flags = s->sh_flags;
            sh->sh_entsize = s->sh_entsize;
            sh->sh_info = s->sh_info;
            ಆದರೆ (s->link)
                sh->sh_link = s->link->sh_ಅಂಕೆ;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_ಸ್ಥಾನಾಂತರ = s->sh_ಸ್ಥಾನಾಂತರ;
            sh->sh_ಗಾತ್ರ = s->sh_ಗಾತ್ರ;
        }
        ಸ್ಥಾನಾಂತರ += fwrite(sh, 1, ಗಾತ್ರ(ElfW(Shdr)), f);
    }

    /* output sections */
    ಗಾಗಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ಆದರೆ (s->sh_type != SHT_NOBITS) {
            ಆಗ (ಸ್ಥಾನಾಂತರ < s->sh_ಸ್ಥಾನಾಂತರ) {
                fputc(0, f);
                ಸ್ಥಾನಾಂತರ++;
            }
            ಗಾತ್ರ_2 = s->sh_ಗಾತ್ರ;
            ಆದರೆ (ಗಾತ್ರ_2)
                ಸ್ಥಾನಾಂತರ += fwrite(s->ದತ್ತಾಂಶ, 1, ಗಾತ್ರ_2, f);
        }
    }
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_output_ದ್ವಿಮಾನ(TCCState *s1, FILE *f)
{
    Section *s;
    ಪೂರ್ಣಾಂಕ i, ಸ್ಥಾನಾಂತರ, ಗಾತ್ರ_2;

    ಸ್ಥಾನಾಂತರ = 0;
    ಗಾಗಿ(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[i];
        ಆದರೆ (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            ಆಗ (ಸ್ಥಾನಾಂತರ < s->sh_ಸ್ಥಾನಾಂತರ) {
                fputc(0, f);
                ಸ್ಥಾನಾಂತರ++;
            }
            ಗಾತ್ರ_2 = s->sh_ಗಾತ್ರ;
            fwrite(s->ದತ್ತಾಂಶ, 1, ಗಾತ್ರ_2, f);
            ಸ್ಥಾನಾಂತರ += ಗಾತ್ರ_2;
        }
    }
    ಹಿಂತಿರುಗಿ 0;
}

/* Write an elf, coff or "binary" file */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_write_elf_file(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ phnum,
                              ElfW(Phdr) *phdr)
{
    ಪೂರ್ಣಾಂಕ fd, ಬಹುಲಕ, file_type, ret;
    FILE *f;

    file_type = s1->output_type;
    ಆದರೆ (file_type == TCC_OUTPUT_OBJ)
        ಬಹುಲಕ = 0666;
    ಇಲ್ಲದಿದ್ದರೆ
        ಬಹುಲಕ = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_ದ್ವಿಮಾನ_2, ಬಹುಲಕ);
    ಆದರೆ (fd < 0 || (f = fdopen(fd, "wb")) == ಖಾಲಿ)
        ಹಿಂತಿರುಗಿ tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
    ಆದರೆ (s1->verbose)
        ಬರೆ("<- %s\n", filename);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_COFF
    ಆದರೆ (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        ret = tcc_output_elf(s1, f, phnum, phdr);
    ಇಲ್ಲದಿದ್ದರೆ
        ret = tcc_output_ದ್ವಿಮಾನ(s1, f);
    fclose(f);

    ಹಿಂತಿರುಗಿ ret;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
/* order sections according to sec_order, remove sections
   that we aren't going to output.  */
ಸ್ಥಿರ ಶೂನ್ಯ reorder_sections(TCCState *s1, ಪೂರ್ಣಾಂಕ *sec_ಕ್ರಮ)
{
    ಪೂರ್ಣಾಂಕ i, nnew, k, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    backmap = tcc_malloc(s1->nb_sections * ಗಾತ್ರ(backmap[0]));
    ಗಾಗಿ (i = 0, nnew = 0, snew = ಖಾಲಿ; i < s1->nb_sections; i++) {
	k = sec_ಕ್ರಮ ? sec_ಕ್ರಮ[i] : i;
	s = s1->sections[k];
	ಆದರೆ (!i || s->sh_name) {
	    backmap[k] = nnew;
            dynarray_ಕೂಡಿಸು(&snew, &nnew, s);
	} ಇಲ್ಲದಿದ್ದರೆ {
	    backmap[k] = 0;
            /* just remember to free them later */
	    dynarray_ಕೂಡಿಸು(&s1->priv_sections, &s1->nb_priv_sections, s);
	}
    }
    ಗಾಗಿ (i = 1; i < nnew; i++) {
	s = snew[i];
        s->sh_ಅಂಕೆ = i;
        ಆದರೆ (s->sh_type == SHT_RELX)
            s->sh_info = backmap[s->sh_info];
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM)
            for_each_elem(s, 1, sym, ElfW(Sym))
                ಆದರೆ (sym->st_shndx < s1->nb_sections)
                    sym->st_shndx = backmap[sym->st_shndx];
    }
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
ಸ್ಥಿರ ಶೂನ್ಯ create_arm_attribute_section(TCCState *s1)
{
   // Needed for DLL support.
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ arm_attr[] = {
        0x41,                            // 'A'
        0x2c, 0x00, 0x00, 0x00,          // size 0x2c
        'a', 'e', 'a', 'b', 'i', 0x00,   // "aeabi"
        0x01, 0x22, 0x00, 0x00, 0x00,    // 'File Attributes', size 0x22
        0x05, 0x36, 0x00,                // 'CPU_name', "6"
#ಆದರೆ CONFIG_TCC_CPUVER >= 7
        0x06, 0x0a,                      // 'CPU_arch', 'v7'
#ಇಲ್ಲದಿದ್ದರೆ
        0x06, 0x06,                      // 'CPU_arch', 'v6'
#ಆದರೆ_ಅಂತ್ಯ
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
    Section *attr = new_section(s1, ".ARM.attributes", SHT_ARM_ಗುಣಲಕ್ಷಣಗಳು, 0);
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr = section_ptr_ಕೂಡಿಸು(attr, ಗಾತ್ರ(arm_attr));
    attr->sh_addralign = 1;
    ಸ್ಮರಣೆ_ನಕಲು(ptr, arm_attr, ಗಾತ್ರ(arm_attr));
    ಆದರೆ (s1->float_abi != ARM_HARD_FLOAT) {
        ptr[26] = 0x00; // 'FP_arch', 'No'
        ptr[41] = 0x1e; // 'ABI_optimization_goals'
        ptr[42] = 0x06; // 'Aggressive Debug'
    }
}
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_RISCV64
ಸ್ಥಿರ ಶೂನ್ಯ create_riscv_attribute_section(TCCState *s1)
{
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ riscv_attr[] = {
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
    Section *attr = new_section(s1, ".riscv.attributes", SHT_RISCV_ಗುಣಲಕ್ಷಣಗಳು, 0);
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr = section_ptr_ಕೂಡಿಸು(attr, ಗಾತ್ರ(riscv_attr));
    attr->sh_addralign = 1;
    ಸ್ಮರಣೆ_ನಕಲು(ptr, riscv_attr, ಗಾತ್ರ(riscv_attr));
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ TARGETOS_OpenBSD || TARGETOS_NetBSD || TARGETOS_FreeBSD

ಸ್ಥಿರ ಶೂನ್ಯ fill_bsd_note(Section *s, ಪೂರ್ಣಾಂಕ type,
			  ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮೌಲ್ಯ, uint32_t ದತ್ತಾಂಶ)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ = 0;
    ಅಕ್ಷರ *ptr;
    ElfW(Nhdr) *note;
    ಪೂರ್ಣಾಂಕ align = s->sh_addralign;

    /* check if type present */
    ಆಗ (ಸ್ಥಾನಾಂತರ + ಗಾತ್ರ(ElfW(Nhdr)) < s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        note = (ElfW(Nhdr) *) (s->ದತ್ತಾಂಶ + ಸ್ಥಾನಾಂತರ);
	ಆದರೆ (note->n_type == type)
	    ಹಿಂತಿರುಗಿ;
	ಸ್ಥಾನಾಂತರ += (ಗಾತ್ರ(ElfW(Nhdr)) + note->n_namesz + note->n_descsz +
		  align - 1) & -align;
    }
    ptr = section_ptr_ಕೂಡಿಸು(s, ಗಾತ್ರ(ElfW(Nhdr)) + 8 + 4);
    note = (ElfW(Nhdr) *) ptr;
    note->n_namesz = 8;
    note->n_descsz = 4;
    note->n_type = type;
    strcpy (ptr + ಗಾತ್ರ(ElfW(Nhdr)), ಮೌಲ್ಯ);
    ಸ್ಮರಣೆ_ನಕಲು (ptr + ಗಾತ್ರ(ElfW(Nhdr)) + 8, &ದತ್ತಾಂಶ, 4);
}

ಸ್ಥಿರ Section *create_bsd_note_section(TCCState *s1,
					ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name,
					ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮೌಲ್ಯ)
{
    Section *s;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ major = 0, minor = 0, patch = 0;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_OS_RELEASE
    ಅಕ್ಷರಸರಣಿ_ಓದು(CONFIG_OS_RELEASE, "%u.%u.%u", &major, &minor, &patch);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ TARGETOS_FreeBSD
    ಆದರೆ (major < 14)
	ಹಿಂತಿರುಗಿ ಖಾಲಿ;
#ಆದರೆ_ಅಂತ್ಯ
    s = ಕಂಡುಹಿಡಿ_section (s1, name);
    s->sh_type = SHT_NOTE;
#ಆದರೆ TARGETOS_OpenBSD
    fill_bsd_note(s, ELF_NOTE_OS_GNU, ಮೌಲ್ಯ, 0);
#ಅಥವಾಆದರೆ TARGETOS_NetBSD
    fill_bsd_note(s, 1 /* NT_NETBSD_IDENT_TAG */, ಮೌಲ್ಯ,
		  major * 100000000u + (minor % 100u) * 1000000u +
		  (patch % 10000u) * 100u);
#ಅಥವಾಆದರೆ TARGETOS_FreeBSD
    fill_bsd_note(s, 1 /* NT_FREEBSD_ABI_TAG */, ಮೌಲ್ಯ,
		  major * 100000u + (minor % 100u) * 1000u);
    fill_bsd_note(s, 4 /* NT_FREEBSD_FEATURE_CTL */, ಮೌಲ್ಯ, 0);
    fill_bsd_note(s, 2 /* NT_FREEBSD_NOINIT_TAG */, ಮೌಲ್ಯ, 0);
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ s;
}
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಶೂನ್ಯ alloc_sec_ಹೆಸರುಗಳು(TCCState *s1, ಪೂರ್ಣಾಂಕ is_obj);

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ elf_output_file(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    ಪೂರ್ಣಾಂಕ i, ret, file_type, *sec_ಕ್ರಮ;
    ರಚನೆ dyn_inf dyninf = {0};
    Section *interp, *dynstr, *dynamic;
    ಪೂರ್ಣಾಂಕ textrel, got_sym, dt_flags_1;

    file_type = s1->output_type;
    ret = -1;
    interp = dynstr = dynamic = ಖಾಲಿ;
    sec_ಕ್ರಮ = ಖಾಲಿ;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
    create_arm_attribute_section (s1);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_RISCV64
    create_riscv_attribute_section(s1);
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ TARGETOS_OpenBSD
    dyninf.note = create_bsd_note_section (s1, ".note.openbsd.ident", "OpenBSD");
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ TARGETOS_NetBSD
    dyninf.note = create_bsd_note_section (s1, ".note.netbsd.ident", "NetBSD");
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ TARGETOS_FreeBSD
    dyninf.note = create_bsd_note_section (s1, ".note.tag", "FreeBSD");
#ಆದರೆ_ಅಂತ್ಯ

        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_ಕೂಡಿಸು_runtime(s1);
	resolve_common_syms(s1);

        ಆದರೆ (!s1->static_link) {
            ಆದರೆ (file_type & TCC_OUTPUT_EXE) {
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
            dynamic->sh_entsize = ಗಾತ್ರ(ElfW(Dyn));

            got_sym = build_got(s1);
            ಆದರೆ (file_type & TCC_OUTPUT_EXE) {
                bind_exe_dynsyms(s1, file_type & TCC_OUTPUT_DYN);
                ಆದರೆ (s1->nb_errors)
                    ಹೋಗು the_ಕೊನೆ;
            }
            build_got_entries(s1, got_sym);
            ಆದರೆ (file_type & TCC_OUTPUT_EXE) {
                bind_libs_dynsyms(s1);
            } ಇಲ್ಲದಿದ್ದರೆ {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
#ಆದರೆ TCC_EH_ಚೌಕಟ್ಟು
	    /* fill with initial data */
	    tcc_eh_ಚೌಕಟ್ಟು_hdr(s1, 0);
#ಆದರೆ_ಅಂತ್ಯ
	    dyninf.gnu_hash = create_gnu_hash(s1);
        } ಇಲ್ಲದಿದ್ದರೆ {
            build_got_entries(s1, 0);
        }
	ಆವೃತ್ತಿ_ಕೂಡಿಸು (s1);

    textrel = ಗಣ_sec_sizes(s1);

    ಆದರೆ (!s1->static_link) {
        /* add a list of needed dlls */
        ಗಾಗಿ(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            ಆದರೆ (dllref->level == 0)
                put_dt(dynamic, DT_NEEDED, put_elf_str(dynstr, dllref->name));
        }

        ಆದರೆ (s1->rpath)
            put_dt(dynamic, s1->enable_new_dtags ? DT_RUNPATH : DT_RPATH,
                   put_elf_str(dynstr, s1->rpath));

        dt_flags_1 = DF_1_NOW;
        ಆದರೆ (file_type & TCC_OUTPUT_DYN) {
            ಆದರೆ (s1->soname)
                put_dt(dynamic, DT_SONAME, put_elf_str(dynstr, s1->soname));
            /* XXX: currently, since we do not handle PIC code, we
               must relocate the readonly segments */
            ಆದರೆ (textrel)
                put_dt(dynamic, DT_TEXTREL, 0);
            ಆದರೆ (file_type & TCC_OUTPUT_EXE)
                dt_flags_1 = DF_1_NOW | DF_1_PIE;
	    ಆದರೆ (s1->znodelete)
		dt_flags_1 |= DF_1_NODELETE;
        }
        put_dt(dynamic, DT_FLAGS, DF_BIND_NOW);
        put_dt(dynamic, DT_FLAGS_1, dt_flags_1);
        ಆದರೆ (s1->symbolic)
            put_dt(dynamic, DT_SYMBOLIC, 0);

        dyninf.dynamic = dynamic;
        dyninf.dynstr = dynstr;
        /* remember offset and reserve space for 2nd call below */
        dyninf.ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = dynamic->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
        fill_dynamic(s1, &dyninf);
        dynamic->sh_ಗಾತ್ರ = dynamic->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
        dynstr->sh_ಗಾತ್ರ = dynstr->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    }

    /* create and fill .shstrtab section */
    alloc_sec_ಹೆಸರುಗಳು(s1, 0);
    /* this array is used to reorder sections in the output file */
    sec_ಕ್ರಮ = tcc_malloc(ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ) * 2 * s1->nb_sections);
    /* compute section to program header mapping */
    layout_sections(s1, sec_ಕ್ರಮ, &dyninf);

        ಆದರೆ (dynamic) {
            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->ದತ್ತಾಂಶ, dynamic->sh_addr);
            ಆದರೆ (file_type == TCC_OUTPUT_EXE
                || (RELOCATE_DLLPLT && (file_type & TCC_OUTPUT_DYN)))
                relocate_plt(s1);
            /* relocate symbols in .dynsym now that final addresses are known */
            relocate_syms(s1, s1->dynsym, 2);
        }

        /* if building executable or DLL, then relocate each section
           except the GOT which is already relocated */
        relocate_syms(s1, s1->symtab, 0);
        ಆದರೆ (s1->nb_errors != 0)
            ಹೋಗು the_ಕೊನೆ;
        relocate_sections(s1);
        ಆದರೆ (dynamic) {
	    update_reloc_sections (s1, &dyninf);
            dynamic->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = dyninf.ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
            fill_dynamic(s1, &dyninf);
	}
        /* Perform relocation to GOT or PLT entries */
        ಆದರೆ (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s1->got)
            fill_local_got_entries(s1);

    ಆದರೆ (dyninf.gnu_hash)
        update_gnu_hash(s1, dyninf.gnu_hash);

    reorder_sections(s1, sec_ಕ್ರಮ);
#ಆದರೆ TCC_EH_ಚೌಕಟ್ಟು
    /* fill with final data */
    tcc_eh_ಚೌಕಟ್ಟು_hdr(s1, 1);
#ಆದರೆ_ಅಂತ್ಯ
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, dyninf.phnum, dyninf.phdr);
 the_ಕೊನೆ:
    tcc_free(sec_ಕ್ರಮ);
    tcc_free(dyninf.phdr);
    ಹಿಂತಿರುಗಿ ret;
}
#ಆದರೆ_ಅಂತ್ಯ /* ndef ELF_OBJ_ONLY */

/* Allocate strings for section names */
ಸ್ಥಿರ ಶೂನ್ಯ alloc_sec_ಹೆಸರುಗಳು(TCCState *s1, ಪೂರ್ಣಾಂಕ is_obj)
{
    ಪೂರ್ಣಾಂಕ i;
    Section *s, *strsec;

    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");
    ಗಾಗಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ಆದರೆ (is_obj)
            s->sh_ಗಾತ್ರ = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	ಆದರೆ (s->sh_ಗಾತ್ರ || s == strsec || (s->sh_flags & SHF_ALLOC) || is_obj)
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_ಗಾತ್ರ = strsec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
}

/* Output an elf .o file */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ elf_output_obj(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    Section *s;
    ಪೂರ್ಣಾಂಕ i, ret, file_ಸ್ಥಾನಾಂತರ;
    /* Allocate strings for section names */
    alloc_sec_ಹೆಸರುಗಳು(s1, 1);
    file_ಸ್ಥಾನಾಂತರ = (ಗಾತ್ರ (ElfW(Ehdr)) + 3) & -4;
    file_ಸ್ಥಾನಾಂತರ += s1->nb_sections * ಗಾತ್ರ(ElfW(Shdr));
    ಗಾಗಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        file_ಸ್ಥಾನಾಂತರ = (file_ಸ್ಥಾನಾಂತರ + 15) & -16;
        s->sh_ಸ್ಥಾನಾಂತರ = file_ಸ್ಥಾನಾಂತರ;
        ಆದರೆ (s->sh_type != SHT_NOBITS)
            file_ಸ್ಥಾನಾಂತರ += s->sh_ಗಾತ್ರ;
    }
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, 0, ಖಾಲಿ);
    ಹಿಂತಿರುಗಿ ret;
}

LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_output_file(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    s->nb_errors = 0;
    ಆದರೆ (s->test_coverage)
        tcc_tcov_ಕೂಡಿಸು_file(s, filename);
    ಆದರೆ (s->output_type == TCC_OUTPUT_OBJ)
        ಹಿಂತಿರುಗಿ elf_output_obj(s, filename);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    ಹಿಂತಿರುಗಿ  pe_output_file(s, filename);
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_MACHO
    ಹಿಂತಿರುಗಿ macho_output_file(s, filename);
#ಇಲ್ಲದಿದ್ದರೆ
    ಹಿಂತಿರುಗಿ elf_output_file(s, filename);
#ಆದರೆ_ಅಂತ್ಯ
}

ST_FUNC ssize_t ತುಂಬಿದ_read(ಪೂರ್ಣಾಂಕ fd, ಶೂನ್ಯ *buf, ಗಾತ್ರ_t ಎಣಿಕೆ_3) {
    ಅಕ್ಷರ *cbuf = buf;
    ಗಾತ್ರ_t rnum = 0;
    ಆಗ (1) {
        ssize_t ಅಂಕೆ = ಪಠ(fd, cbuf, ಎಣಿಕೆ_3-rnum);
        ಆದರೆ (ಅಂಕೆ < 0) ಹಿಂತಿರುಗಿ ಅಂಕೆ;
        ಆದರೆ (ಅಂಕೆ == 0) ಹಿಂತಿರುಗಿ rnum;
        rnum += ಅಂಕೆ;
        cbuf += ಅಂಕೆ;
    }
}

ST_FUNC ಶೂನ್ಯ *ತುಂಬು_ದತ್ತಾಂಶ(ಪೂರ್ಣಾಂಕ fd, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ file_ಸ್ಥಾನಾಂತರ, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2)
{
    ಶೂನ್ಯ *ದತ್ತಾಂಶ;

    ದತ್ತಾಂಶ = tcc_malloc(ಗಾತ್ರ_2);
    lseek(fd, file_ಸ್ಥಾನಾಂತರ, SEEK_SET);
    ತುಂಬಿದ_read(fd, ದತ್ತಾಂಶ, ಗಾತ್ರ_2);
    ಹಿಂತಿರುಗಿ ದತ್ತಾಂಶ;
}

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ Section_ವಿಲೀನ_Info {
    Section *s;            /* corresponding existing section */
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} Section_ವಿಲೀನ_Info;

ST_FUNC ಪೂರ್ಣಾಂಕ tcc_object_type(ಪೂರ್ಣಾಂಕ fd, ElfW(Ehdr) *h)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2 = ತುಂಬಿದ_read(fd, h, ಗಾತ್ರ *h);
    ಆದರೆ (ಗಾತ್ರ_2 == ಗಾತ್ರ *h && 0 == memcmp(h, ELFMAG, 4)) {
        ಆದರೆ (h->e_type == ET_REL)
            ಹಿಂತಿರುಗಿ AFF_BINTYPE_REL;
        ಆದರೆ (h->e_type == ET_DYN)
            ಹಿಂತಿರುಗಿ AFF_BINTYPE_DYN;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಗಾತ್ರ_2 >= 8) {
        ಆದರೆ (0 == memcmp(h, ARMAG, 8))
            ಹಿಂತಿರುಗಿ AFF_BINTYPE_AR;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_COFF
        ಆದರೆ (((ರಚನೆ filehdr*)h)->f_magic == COFF_C67_MAGIC)
            ಹಿಂತಿರುಗಿ AFF_BINTYPE_C67;
#ಆದರೆ_ಅಂತ್ಯ
    }
    ಹಿಂತಿರುಗಿ 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ತುಂಬು_object_file(TCCState *s1,
                                ಪೂರ್ಣಾಂಕ fd, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ file_ಸ್ಥಾನಾಂತರ)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2, ಸ್ಥಾನಾಂತರ, offseti;
    ಪೂರ್ಣಾಂಕ i, j, nb_syms, sym_ಸೂಚ್ಯಂಕ, ret, seencompressed;
    ಅಕ್ಷರ *strsec, *strtab;
    ಪೂರ್ಣಾಂಕ stab_ಸೂಚ್ಯಂಕ, stabstr_ಸೂಚ್ಯಂಕ;
    ಪೂರ್ಣಾಂಕ *old_ಗಮ್ಯ_new_syms;
    ಅಕ್ಷರ *sh_name, *name;
    Section_ವಿಲೀನ_Info *sm_ಕೋಷ್ಟಕ, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    lseek(fd, file_ಸ್ಥಾನಾಂತರ, SEEK_SET);
    ಆದರೆ (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        ಹೋಗು invalid;
    /* test CPU specific stuff */
    ಆದರೆ (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_ಗುರಿ) {
invalid:
        ಹಿಂತಿರುಗಿ tcc_error_noabort("invalid object file");
    }
    /* read sections */
    shdr = ತುಂಬು_ದತ್ತಾಂಶ(fd, file_ಸ್ಥಾನಾಂತರ + ehdr.e_shoff,
                     ಗಾತ್ರ(ElfW(Shdr)) * ehdr.e_shnum);
    sm_ಕೋಷ್ಟಕ = tcc_mallocz(ಗಾತ್ರ(Section_ವಿಲೀನ_Info) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = ತುಂಬು_ದತ್ತಾಂಶ(fd, file_ಸ್ಥಾನಾಂತರ + sh->sh_ಸ್ಥಾನಾಂತರ, sh->sh_ಗಾತ್ರ);

    /* load symtab and strtab */
    old_ಗಮ್ಯ_new_syms = ಖಾಲಿ;
    symtab = ಖಾಲಿ;
    strtab = ಖಾಲಿ;
    nb_syms = 0;
    seencompressed = 0;
    stab_ಸೂಚ್ಯಂಕ = stabstr_ಸೂಚ್ಯಂಕ = 0;
    ret = -1;

    ಗಾಗಿ(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        ಆದರೆ (sh->sh_type == SHT_SYMTAB) {
            ಆದರೆ (symtab) {
                tcc_error_noabort("object must contain only one symtab");
                ಹೋಗು the_ಕೊನೆ;
            }
            nb_syms = sh->sh_ಗಾತ್ರ / ಗಾತ್ರ(ElfW(Sym));
            symtab = ತುಂಬು_ದತ್ತಾಂಶ(fd, file_ಸ್ಥಾನಾಂತರ + sh->sh_ಸ್ಥಾನಾಂತರ, sh->sh_ಗಾತ್ರ);
            sm_ಕೋಷ್ಟಕ[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = ತುಂಬು_ದತ್ತಾಂಶ(fd, file_ಸ್ಥಾನಾಂತರ + sh->sh_ಸ್ಥಾನಾಂತರ, sh->sh_ಗಾತ್ರ);
        }
	ಆದರೆ (sh->sh_flags & SHF_COMPRESSED)
	    seencompressed = 1;
    }

    /* now examine each section and try to merge its content with the
       ones in memory */
    ಗಾಗಿ(i = 1; i < ehdr.e_shnum; i++) {
        /* no need to examine section name strtab */
        ಆದರೆ (i == ehdr.e_shstrndx)
            ಮುಂದುವರಿ;
        sh = &shdr[i];
	ಆದರೆ (sh->sh_type == SHT_RELX)
	  sh = &shdr[sh->sh_info];
        /* ignore sections types we do not handle (plus relocs to those) */
        sh_name = strsec + sh->sh_name;
        ಆದರೆ (0 == ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(sh_name, ".debug_", 7)
         || 0 == ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(sh_name, ".stab", 5)) {
	    ಆದರೆ (!s1->do_debug || seencompressed)
	        ಮುಂದುವರಿ;
#ಆದರೆ !(TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD)
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (0 == ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(sh_name, ".eh_frame", 9)) {
            ಆದರೆ (ಖಾಲಿ == eh_ಚೌಕಟ್ಟು_section)
                ಮುಂದುವರಿ;
#ಆದರೆ_ಅಂತ್ಯ
        } ಇಲ್ಲದಿದ್ದರೆ
        ಆದರೆ (sh->sh_type != SHT_PROGBITS &&
            sh->sh_type != SHT_NOTE &&
            sh->sh_type != SHT_NOBITS &&
            sh->sh_type != SHT_PREINIT_ARRAY &&
            sh->sh_type != SHT_INIT_ARRAY &&
            sh->sh_type != SHT_FINI_ARRAY
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
            /* Added in commit f99d3de221db23e322c6c18c8249282e27726c25
               but suppressed in 3cfaaaf1eb97d858e583412616f68f75fdad5da5
               So don't load it in order to avoid dangling references from
               (STT_SECTION) symbols. */
            // && sh->sh_type != SHT_ARM_EXIDX
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD
            && sh->sh_type != SHT_X86_64_UNWIND
#ಆದರೆ_ಅಂತ್ಯ
            )
            ಮುಂದುವರಿ;

	sh = &shdr[i];
        sh_name = strsec + sh->sh_name;
        ಆದರೆ (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        /* find corresponding section, if any */
        ಗಾಗಿ(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            ಆದರೆ (strcmp(s->name, sh_name))
                ಮುಂದುವರಿ;
            ಆದರೆ (sh->sh_type != s->sh_type
                && strcmp (s->name, ".eh_frame")
                /* some crt1.o seem to have two ".note.GNU-stack" (SHT_NOTE & SHT_PROGBITS) */
                && strcmp (s->name, ".note.GNU-stack")
                ) {
                tcc_error_noabort("section type conflict: %s %02x <> %02x", s->name, sh->sh_type, s->sh_type);
                ಹೋಗು the_ಕೊನೆ;
            }
            ಆದರೆ (!ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(sh_name, ".gnu.linkonce", 13)) {
                /* if a 'linkonce' section is already present, we
                   do not add it again. It is a little tricky as
                   symbols can still be defined in
                   it. */
                sm_ಕೋಷ್ಟಕ[i].link_once = 1;
                ಹೋಗು ಮುಂದಿನ;
            }
            ಆದರೆ (stab_section) {
                ಆದರೆ (s == stab_section)
                    stab_ಸೂಚ್ಯಂಕ = i;
                ಆದರೆ (s == stab_section->link)
                    stabstr_ಸೂಚ್ಯಂಕ = i;
            }
            ಹೋಗು ಸಿಕ್ಕಿತು;
        }
        /* not found: create new section */
        s = new_section(s1, sh_name, sh->sh_type, sh->sh_flags & ~SHF_ಗುಂಪು);
        /* take as much info as possible from the section. sh_link and
           sh_info will be updated later */
        s->sh_addralign = sh->sh_addralign;
        s->sh_entsize = sh->sh_entsize;
        sm_ಕೋಷ್ಟಕ[i].new_section = 1;
    ಸಿಕ್ಕಿತು:
        ಗಾತ್ರ_2 = sh->sh_ಗಾತ್ರ;
        /* align start of section */
        ಸ್ಥಾನಾಂತರ = section_ಕೂಡಿಸು(s, ಗಾತ್ರ_2, sh->sh_addralign);
        ಆದರೆ (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        sm_ಕೋಷ್ಟಕ[i].ಸ್ಥಾನಾಂತರ = ಸ್ಥಾನಾಂತರ;
        sm_ಕೋಷ್ಟಕ[i].s = s;
        /* concatenate sections */
        ಆದರೆ (sh->sh_type != SHT_NOBITS && ಗಾತ್ರ_2) {
            ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr;
            lseek(fd, file_ಸ್ಥಾನಾಂತರ + sh->sh_ಸ್ಥಾನಾಂತರ, SEEK_SET);
            ptr = s->ದತ್ತಾಂಶ + ಸ್ಥಾನಾಂತರ;
            ತುಂಬಿದ_read(fd, ptr, ಗಾತ್ರ_2);
        }
#ಆದರೆ defined TCC_ಗುರಿ_ARM || defined TCC_ಗುರಿ_ARM64 || defined TCC_ಗುರಿ_RISCV64
        /* align code sections to instruction lenght */
        /* This is needed if we compile a c file after this */
        ಆದರೆ (s->sh_flags & SHF_EXECINSTR)
            section_ಕೂಡಿಸು(s, 0, 4);
#ಆದರೆ_ಅಂತ್ಯ
    ಮುಂದಿನ: ;
    }

    /* gr relocate stab strings */
    ಆದರೆ (stab_ಸೂಚ್ಯಂಕ && stabstr_ಸೂಚ್ಯಂಕ) {
        Stab_Sym *a, *b;
        ಚಿಹ್ನೆರಹಿತ o;
        s = sm_ಕೋಷ್ಟಕ[stab_ಸೂಚ್ಯಂಕ].s;
        a = (Stab_Sym *)(s->ದತ್ತಾಂಶ + sm_ಕೋಷ್ಟಕ[stab_ಸೂಚ್ಯಂಕ].ಸ್ಥಾನಾಂತರ);
        b = (Stab_Sym *)(s->ದತ್ತಾಂಶ + s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
        o = sm_ಕೋಷ್ಟಕ[stabstr_ಸೂಚ್ಯಂಕ].ಸ್ಥಾನಾಂತರ;
        ಆಗ (a < b) {
            ಆದರೆ (a->n_strx)
                a->n_strx += o;
            a++;
        }
    }

    /* second short pass to update sh_link and sh_info fields of new
       sections */
    ಗಾಗಿ(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_ಕೋಷ್ಟಕ[i].s;
        ಆದರೆ (!s || !sm_ಕೋಷ್ಟಕ[i].new_section)
            ಮುಂದುವರಿ;
        sh = &shdr[i];
        ಆದರೆ (sh->sh_link > 0)
            s->link = sm_ಕೋಷ್ಟಕ[sh->sh_link].s;
        ಆದರೆ (sh->sh_type == SHT_RELX) {
            s->sh_info = sm_ಕೋಷ್ಟಕ[sh->sh_info].s->sh_ಅಂಕೆ;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }

    ಆದರೆ (!symtab)
        ಹೋಗು ಮುಗಿದ;

    /* resolve symbols */
    old_ಗಮ್ಯ_new_syms = tcc_mallocz(nb_syms * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));

    sym = symtab + 1;
    ಗಾಗಿ(i = 1; i < nb_syms; i++, sym++) {
        ಆದರೆ (sym->st_shndx != SHN_UNDEF &&
            sym->st_shndx < SHN_LORESERVE) {
            sm = &sm_ಕೋಷ್ಟಕ[sym->st_shndx];
            ಆದರೆ (sm->link_once) {
                /* if a symbol is in a link once section, we use the
                   already defined symbol. It is very important to get
                   correct relocations */
                ಆದರೆ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
                    name = strtab + sym->st_name;
                    sym_ಸೂಚ್ಯಂಕ = ಕಂಡುಹಿಡಿ_elf_sym(symtab_section, name);
                    ಆದರೆ (sym_ಸೂಚ್ಯಂಕ)
                        old_ಗಮ್ಯ_new_syms[i] = sym_ಸೂಚ್ಯಂಕ;
                }
                ಮುಂದುವರಿ;
            }
            /* if no corresponding section added, no need to add symbol */
            ಆದರೆ (!sm->s)
                ಮುಂದುವರಿ;
            /* convert section number */
            sym->st_shndx = sm->s->sh_ಅಂಕೆ;
            /* offset value */
            sym->st_ಮೌಲ್ಯ += sm->ಸ್ಥಾನಾಂತರ;
        }
        /* add symbol */
        name = strtab + sym->st_name;
        sym_ಸೂಚ್ಯಂಕ = ಗಣ_elf_sym(symtab_section, sym->st_ಮೌಲ್ಯ, sym->st_ಗಾತ್ರ,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_ಗಮ್ಯ_new_syms[i] = sym_ಸೂಚ್ಯಂಕ;
    }

    /* third pass to patch relocation entries */
    ಗಾಗಿ(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_ಕೋಷ್ಟಕ[i].s;
        ಆದರೆ (!s)
            ಮುಂದುವರಿ;
        sh = &shdr[i];
        ಸ್ಥಾನಾಂತರ = sm_ಕೋಷ್ಟಕ[i].ಸ್ಥಾನಾಂತರ;
        ಗಾತ್ರ_2 = sh->sh_ಗಾತ್ರ;
        ಆಯ್ಕೆ(s->sh_type) {
        ಸ್ಥಿತಿ SHT_RELX:
            /* take relocation offset information */
            offseti = sm_ಕೋಷ್ಟಕ[sh->sh_info].ಸ್ಥಾನಾಂತರ;
	    ಗಾಗಿ (rel = (ElfW_Rel *) s->ದತ್ತಾಂಶ + (ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ(*rel));
		 rel < (ElfW_Rel *) s->ದತ್ತಾಂಶ + ((ಸ್ಥಾನಾಂತರ + ಗಾತ್ರ_2) / ಗಾತ್ರ(*rel));
		 rel++) {
                ಪೂರ್ಣಾಂಕ type;
                ಚಿಹ್ನೆರಹಿತ sym_ಸೂಚ್ಯಂಕ;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                ಆದರೆ (sym_ಸೂಚ್ಯಂಕ >= nb_syms)
                    ಹೋಗು invalid_reloc;
                sym_ಸೂಚ್ಯಂಕ = old_ಗಮ್ಯ_new_syms[sym_ಸೂಚ್ಯಂಕ];
                /* ignore link_once in rel section. */
                ಆದರೆ (!sym_ಸೂಚ್ಯಂಕ && !sm_ಕೋಷ್ಟಕ[sh->sh_info].link_once
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
                    && type != R_ARM_V4BX
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_RISCV64
                    && type != R_RISCV_ALIGN
                    && type != R_RISCV_RELAX
#ಆದರೆ_ಅಂತ್ಯ
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, (ಪೂರ್ಣಾಂಕ)rel->r_ಸ್ಥಾನಾಂತರ);
                    ಹೋಗು the_ಕೊನೆ;
                }
                rel->r_info = ELFW(R_INFO)(sym_ಸೂಚ್ಯಂಕ, type);
                /* offset the relocation offset */
                rel->r_ಸ್ಥಾನಾಂತರ += offseti;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
                /* Jumps and branches from a Thumb code to a PLT entry need
                   special handling since PLT entries are ARM code.
                   Unconditional bl instructions referencing PLT entries are
                   handled by converting these instructions into blx
                   instructions. Other case of instructions referencing a PLT
                   entry require to add a Thumb stub before the PLT entry to
                   switch to ARM mode. We set bit plt_thumb_stub of the
                   attribute of a symbol to indicate such a case. */
                ಆದರೆ (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 1)->plt_thumb_stub = 1;
#ಆದರೆ_ಅಂತ್ಯ
            }
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            ನಿಲ್ಲಿಸು;
        }
    }
 ಮುಗಿದ:
    ret = !s1->nb_errors - 1; /* errors possibly from set_elf_sym() */
 the_ಕೊನೆ:
    tcc_free(symtab);
    tcc_free(strtab);
    tcc_free(old_ಗಮ್ಯ_new_syms);
    tcc_free(sm_ಕೋಷ್ಟಕ);
    tcc_free(strsec);
    tcc_free(shdr);
    ಹಿಂತಿರುಗಿ ret;
}

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ Archive_ಶೀರ್ಷಿಕೆ {
    ಅಕ್ಷರ ar_name[16];           /* name of this member */
    ಅಕ್ಷರ ar_date[12];           /* file mtime */
    ಅಕ್ಷರ ar_uid[6];             /* owner uid; printed as decimal */
    ಅಕ್ಷರ ar_gid[6];             /* owner gid; printed as decimal */
    ಅಕ್ಷರ ar_ಬಹುಲಕ[8];            /* file mode, printed as octal   */
    ಅಕ್ಷರ ar_ಗಾತ್ರ[10];           /* file size, printed as decimal */
    ಅಕ್ಷರ ar_fmag[2];            /* should contain ARFMAG */
} Archive_ಶೀರ್ಷಿಕೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು ARFMAG "`\n"

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ get_be(ಸ್ಥಿರಾಂಕ uint8_t *b, ಪೂರ್ಣಾಂಕ n)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ret = 0;
    ಆಗ (n)
        ret = (ret << 8) | *b++, --n;
    ಹಿಂತಿರುಗಿ ret;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ read_ar_ಶೀರ್ಷಿಕೆ(ಪೂರ್ಣಾಂಕ fd, ಪೂರ್ಣಾಂಕ ಸ್ಥಾನಾಂತರ, Archive_ಶೀರ್ಷಿಕೆ *hdr)
{
    ಅಕ್ಷರ *p, *e;
    ಪೂರ್ಣಾಂಕ len;
    lseek(fd, ಸ್ಥಾನಾಂತರ, SEEK_SET);
    len = ತುಂಬಿದ_read(fd, hdr, ಗಾತ್ರ(Archive_ಶೀರ್ಷಿಕೆ));
    ಆದರೆ (len != ಗಾತ್ರ(Archive_ಶೀರ್ಷಿಕೆ))
        ಹಿಂತಿರುಗಿ len ? -1 : 0;
    ಆದರೆ (memcmp(hdr->ar_fmag, ARFMAG, ಗಾತ್ರ hdr->ar_fmag))
        ಹಿಂತಿರುಗಿ -1;
    p = hdr->ar_name;
    ಗಾಗಿ (e = p + ಗಾತ್ರ hdr->ar_name; e > p && e[-1] == ' ';)
        --e;
    *e = '\0';
    hdr->ar_ಗಾತ್ರ[ಗಾತ್ರ hdr->ar_ಗಾತ್ರ-1] = 0;
    ಹಿಂತಿರುಗಿ len;
}

/* load only the objects which resolve undefined symbols */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_ತುಂಬು_alacarte(TCCState *s1, ಪೂರ್ಣಾಂಕ fd, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, ಪೂರ್ಣಾಂಕ entrysize)
{
    ಪೂರ್ಣಾಂಕ i, bound, nsyms, sym_ಸೂಚ್ಯಂಕ, len, ret = -1;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ off;
    uint8_t *ದತ್ತಾಂಶ;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ar_ಹೆಸರುಗಳು, *p;
    ಸ್ಥಿರಾಂಕ uint8_t *ar_ಸೂಚ್ಯಂಕ;
    ElfW(Sym) *sym;
    Archive_ಶೀರ್ಷಿಕೆ hdr;

    ದತ್ತಾಂಶ = tcc_malloc(ಗಾತ್ರ_2);
    ಆದರೆ (ತುಂಬಿದ_read(fd, ದತ್ತಾಂಶ, ಗಾತ್ರ_2) != ಗಾತ್ರ_2)
        ಹೋಗು invalid;
    nsyms = get_be(ದತ್ತಾಂಶ, entrysize);
    ar_ಸೂಚ್ಯಂಕ = ದತ್ತಾಂಶ + entrysize;
    ar_ಹೆಸರುಗಳು = (ಅಕ್ಷರ *) ar_ಸೂಚ್ಯಂಕ + nsyms * entrysize;

    ಮಾಡು {
        bound = 0;
        ಗಾಗಿ (p = ar_ಹೆಸರುಗಳು, i = 0; i < nsyms; i++, p += ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(p)+1) {
            Section *s = symtab_section;
            sym_ಸೂಚ್ಯಂಕ = ಕಂಡುಹಿಡಿ_elf_sym(s, p);
            ಆದರೆ (!sym_ಸೂಚ್ಯಂಕ)
                ಮುಂದುವರಿ;
            sym = &((ElfW(Sym) *)s->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
            ಆದರೆ(sym->st_shndx != SHN_UNDEF)
                ಮುಂದುವರಿ;
            off = get_be(ar_ಸೂಚ್ಯಂಕ + i * entrysize, entrysize);
            len = read_ar_ಶೀರ್ಷಿಕೆ(fd, off, &hdr);
            ಆದರೆ (len <= 0 || memcmp(hdr.ar_fmag, ARFMAG, 2)) {
        invalid:
                tcc_error_noabort("invalid archive");
                ಹೋಗು the_ಕೊನೆ;
            }
            off += len;
            ಆದರೆ (s1->verbose == 2)
                ಬರೆ("   -> %s\n", hdr.ar_name);
            ಆದರೆ (tcc_ತುಂಬು_object_file(s1, fd, off) < 0)
                ಹೋಗು the_ಕೊನೆ;
            ++bound;
        }
    } ಆಗ(bound);
    ret = 0;
 the_ಕೊನೆ:
    tcc_free(ದತ್ತಾಂಶ);
    ಹಿಂತಿರುಗಿ ret;
}

/* load a '.a' file */
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ತುಂಬು_archive(TCCState *s1, ಪೂರ್ಣಾಂಕ fd, ಪೂರ್ಣಾಂಕ alacarte)
{
    Archive_ಶೀರ್ಷಿಕೆ hdr;
    /* char magic[8]; */
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, len;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ file_ಸ್ಥಾನಾಂತರ;
    ElfW(Ehdr) ehdr;

    /* skip magic which was already checked */
    /* full_read(fd, magic, sizeof(magic)); */
    file_ಸ್ಥಾನಾಂತರ = ಗಾತ್ರ ARMAG - 1;

    ಗಾಗಿ(;;) {
        len = read_ar_ಶೀರ್ಷಿಕೆ(fd, file_ಸ್ಥಾನಾಂತರ, &hdr);
        ಆದರೆ (len == 0)
            ಹಿಂತಿರುಗಿ 0;
        ಆದರೆ (len < 0)
            ಹಿಂತಿರುಗಿ tcc_error_noabort("invalid archive");
        file_ಸ್ಥಾನಾಂತರ += len;
        ಗಾತ್ರ_2 = strtol(hdr.ar_ಗಾತ್ರ, ಖಾಲಿ, 0);
        ಆದರೆ (alacarte) {
            /* coff symbol table : we handle it */
            ಆದರೆ (!strcmp(hdr.ar_name, "/"))
                ಹಿಂತಿರುಗಿ tcc_ತುಂಬು_alacarte(s1, fd, ಗಾತ್ರ_2, 4);
            ಆದರೆ (!strcmp(hdr.ar_name, "/SYM64/"))
                ಹಿಂತಿರುಗಿ tcc_ತುಂಬು_alacarte(s1, fd, ಗಾತ್ರ_2, 8);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
            ಆದರೆ (s1->verbose == 2)
                ಬರೆ("   -> %s\n", hdr.ar_name);
            ಆದರೆ (tcc_ತುಂಬು_object_file(s1, fd, file_ಸ್ಥಾನಾಂತರ) < 0)
                ಹಿಂತಿರುಗಿ -1;
        }
        /* align to even */
        file_ಸ್ಥಾನಾಂತರ = (file_ಸ್ಥಾನಾಂತರ + ಗಾತ್ರ_2 + 1) & ~1;
    }
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
/* Set LV[I] to the global index of sym-version (LIB,VERSION).  Maybe resizes
   LV, maybe create a new entry for (LIB,VERSION).  */
ಸ್ಥಿರ ಶೂನ್ಯ ಗಣ_ver_ಗಮ್ಯ_ver(TCCState *s1, ಪೂರ್ಣಾಂಕ *n, ಪೂರ್ಣಾಂಕ **lv, ಪೂರ್ಣಾಂಕ i, ಅಕ್ಷರ *lib, ಅಕ್ಷರ *ಆವೃತ್ತಿ)
{
    ಆಗ (i >= *n) {
        *lv = tcc_realloc(*lv, (*n + 1) * ಗಾತ್ರ(**lv));
        (*lv)[(*n)++] = -1;
    }
    ಆದರೆ ((*lv)[i] == -1) {
        ಪೂರ್ಣಾಂಕ v, prev_same_lib = -1;
        ಗಾಗಿ (v = 0; v < nb_sym_versions; v++) {
            ಆದರೆ (strcmp(sym_versions[v].lib, lib))
              ಮುಂದುವರಿ;
            prev_same_lib = v;
            ಆದರೆ (!strcmp(sym_versions[v].ಆವೃತ್ತಿ, ಆವೃತ್ತಿ))
              ನಿಲ್ಲಿಸು;
        }
        ಆದರೆ (v == nb_sym_versions) {
            sym_versions = tcc_realloc (sym_versions,
                                        (v + 1) * ಗಾತ್ರ(*sym_versions));
            sym_versions[v].lib = tcc_strdup(lib);
            sym_versions[v].ಆವೃತ್ತಿ = tcc_strdup(ಆವೃತ್ತಿ);
            sym_versions[v].ಹೊರಹೋಗು_ಸೂಚ್ಯಂಕ = 0;
            sym_versions[v].prev_same_lib = prev_same_lib;
            nb_sym_versions++;
        }
        (*lv)[i] = v;
    }
}

/* Associates symbol SYM_INDEX (in dynsymtab) with sym-version index
   VERNDX.  */
ಸ್ಥಿರ ಶೂನ್ಯ
ಗಣ_sym_ಆವೃತ್ತಿ(TCCState *s1, ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ, ಪೂರ್ಣಾಂಕ verndx)
{
    ಆದರೆ (sym_ಸೂಚ್ಯಂಕ >= nb_sym_ಗಮ್ಯ_ಆವೃತ್ತಿ) {
        ಪೂರ್ಣಾಂಕ newelems = sym_ಸೂಚ್ಯಂಕ ? sym_ಸೂಚ್ಯಂಕ * 2 : 1;
        sym_ಗಮ್ಯ_ಆವೃತ್ತಿ = tcc_realloc(sym_ಗಮ್ಯ_ಆವೃತ್ತಿ,
                                     newelems * ಗಾತ್ರ(*sym_ಗಮ್ಯ_ಆವೃತ್ತಿ));
        memset(sym_ಗಮ್ಯ_ಆವೃತ್ತಿ + nb_sym_ಗಮ್ಯ_ಆವೃತ್ತಿ, -1,
               (newelems - nb_sym_ಗಮ್ಯ_ಆವೃತ್ತಿ) * ಗಾತ್ರ(*sym_ಗಮ್ಯ_ಆವೃತ್ತಿ));
        nb_sym_ಗಮ್ಯ_ಆವೃತ್ತಿ = newelems;
    }
    ಆದರೆ (sym_ಗಮ್ಯ_ಆವೃತ್ತಿ[sym_ಸೂಚ್ಯಂಕ] < 0)
      sym_ಗಮ್ಯ_ಆವೃತ್ತಿ[sym_ಸೂಚ್ಯಂಕ] = verndx;
}

ರಚನೆ versym_info {
    ಪೂರ್ಣಾಂಕ nb_versyms;
    ElfW(Verdef) *verdef;
    ElfW(Verneed) *verneed;
    ElfW(Half) *versym;
    ಪೂರ್ಣಾಂಕ nb_local_ver, *local_ver;
};


ಸ್ಥಿರ ಶೂನ್ಯ store_ಆವೃತ್ತಿ(TCCState *s1, ರಚನೆ versym_info *v, ಅಕ್ಷರ *dynstr)
{
    ಅಕ್ಷರ *lib, *ಆವೃತ್ತಿ;
    uint32_t ಮುಂದಿನ;
    ಪೂರ್ಣಾಂಕ i;

#ವ್ಯಾಖ್ಯಾನಿಸು	DEBUG_ಆವೃತ್ತಿ 0

    ಆದರೆ (v->versym && v->verdef) {
      ElfW(Verdef) *vdef = v->verdef;
      lib = ಖಾಲಿ;
      ಮಾಡು {
        ElfW(Verdaux) *verdaux =
	  (ElfW(Verdaux) *) (((ಅಕ್ಷರ *) vdef) + vdef->vd_aux);

#ಆದರೆ DEBUG_ಆವೃತ್ತಿ
	ಬರೆ ("verdef: version:%u flags:%u index:%u, hash:%u\n",
	        vdef->vd_ಆವೃತ್ತಿ, vdef->vd_flags, vdef->vd_ndx,
		vdef->vd_hash);
#ಆದರೆ_ಅಂತ್ಯ
	ಆದರೆ (vdef->vd_cnt) {
          ಆವೃತ್ತಿ = dynstr + verdaux->vda_name;

	  ಆದರೆ (lib == ಖಾಲಿ)
	    lib = ಆವೃತ್ತಿ;
	  ಇಲ್ಲದಿದ್ದರೆ
            ಗಣ_ver_ಗಮ್ಯ_ver(s1, &v->nb_local_ver, &v->local_ver, vdef->vd_ndx,
                           lib, ಆವೃತ್ತಿ);
#ಆದರೆ DEBUG_ಆವೃತ್ತಿ
	  ಬರೆ ("  verdaux(%u): %s\n", vdef->vd_ndx, ಆವೃತ್ತಿ);
#ಆದರೆ_ಅಂತ್ಯ
	}
        ಮುಂದಿನ = vdef->vd_ಮುಂದಿನ;
        vdef = (ElfW(Verdef) *) (((ಅಕ್ಷರ *) vdef) + ಮುಂದಿನ);
      } ಆಗ (ಮುಂದಿನ);
    }
    ಆದರೆ (v->versym && v->verneed) {
      ElfW(Verneed) *vneed = v->verneed;
      ಮಾಡು {
        ElfW(Vernaux) *vernaux =
	  (ElfW(Vernaux) *) (((ಅಕ್ಷರ *) vneed) + vneed->vn_aux);

        lib = dynstr + vneed->vn_file;
#ಆದರೆ DEBUG_ಆವೃತ್ತಿ
	ಬರೆ ("verneed: %u %s\n", vneed->vn_ಆವೃತ್ತಿ, lib);
#ಆದರೆ_ಅಂತ್ಯ
	ಗಾಗಿ (i = 0; i < vneed->vn_cnt; i++) {
	  ಆದರೆ ((vernaux->vna_other & 0x8000) == 0) { /* hidden */
              ಆವೃತ್ತಿ = dynstr + vernaux->vna_name;
              ಗಣ_ver_ಗಮ್ಯ_ver(s1, &v->nb_local_ver, &v->local_ver, vernaux->vna_other,
                             lib, ಆವೃತ್ತಿ);
#ಆದರೆ DEBUG_ಆವೃತ್ತಿ
	    ಬರೆ ("  vernaux(%u): %u %u %s\n",
		    vernaux->vna_other, vernaux->vna_hash,
		    vernaux->vna_flags, ಆವೃತ್ತಿ);
#ಆದರೆ_ಅಂತ್ಯ
	  }
	  vernaux = (ElfW(Vernaux) *) (((ಅಕ್ಷರ *) vernaux) + vernaux->vna_ಮುಂದಿನ);
	}
        ಮುಂದಿನ = vneed->vn_ಮುಂದಿನ;
        vneed = (ElfW(Verneed) *) (((ಅಕ್ಷರ *) vneed) + ಮುಂದಿನ);
      } ಆಗ (ಮುಂದಿನ);
    }

#ಆದರೆ DEBUG_ಆವೃತ್ತಿ
    ಗಾಗಿ (i = 0; i < v->nb_local_ver; i++) {
      ಆದರೆ (v->local_ver[i] > 0) {
        ಬರೆ ("%d: lib: %s, version %s\n",
		i, sym_versions[v->local_ver[i]].lib,
                sym_versions[v->local_ver[i]].ಆವೃತ್ತಿ);
      }
    }
#ಆದರೆ_ಅಂತ್ಯ
}

/* load a library / DLL
   'level = 0' means that the DLL is referenced by the user
   (so it should be added as DT_NEEDED in the generated ELF file) */
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ತುಂಬು_dll(TCCState *s1, ಪೂರ್ಣಾಂಕ fd, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    ಪೂರ್ಣಾಂಕ i, nb_syms, nb_dts, sym_bind, ret = -1;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;

    ಅಕ್ಷರ *dynstr;
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, *soname;
    ರಚನೆ versym_info v;

    ತುಂಬಿದ_read(fd, &ehdr, ಗಾತ್ರ(ehdr));

    /* test CPU specific stuff */
    ಆದರೆ (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_ಗುರಿ) {
        ಹಿಂತಿರುಗಿ tcc_error_noabort("bad architecture");
    }

    /* read sections */
    shdr = ತುಂಬು_ದತ್ತಾಂಶ(fd, ehdr.e_shoff, ಗಾತ್ರ(ElfW(Shdr)) * ehdr.e_shnum);

    /* load dynamic section and dynamic symbols */
    nb_syms = 0;
    nb_dts = 0;
    dynamic = ಖಾಲಿ;
    dynsym = ಖಾಲಿ; /* avoid warning */
    dynstr = ಖಾಲಿ; /* avoid warning */
    memset(&v, 0, ಗಾತ್ರ v);

    ಗಾಗಿ(i = 0, sh = shdr; i < ehdr.e_shnum; i++, sh++) {
        ಆಯ್ಕೆ(sh->sh_type) {
        ಸ್ಥಿತಿ SHT_DYNAMIC:
            nb_dts = sh->sh_ಗಾತ್ರ / ಗಾತ್ರ(ElfW(Dyn));
            dynamic = ತುಂಬು_ದತ್ತಾಂಶ(fd, sh->sh_ಸ್ಥಾನಾಂತರ, sh->sh_ಗಾತ್ರ);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ SHT_DYNSYM:
            nb_syms = sh->sh_ಗಾತ್ರ / ಗಾತ್ರ(ElfW(Sym));
            dynsym = ತುಂಬು_ದತ್ತಾಂಶ(fd, sh->sh_ಸ್ಥಾನಾಂತರ, sh->sh_ಗಾತ್ರ);
            sh1 = &shdr[sh->sh_link];
            dynstr = ತುಂಬು_ದತ್ತಾಂಶ(fd, sh1->sh_ಸ್ಥಾನಾಂತರ, sh1->sh_ಗಾತ್ರ);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ SHT_GNU_verdef:
	    v.verdef = ತುಂಬು_ದತ್ತಾಂಶ(fd, sh->sh_ಸ್ಥಾನಾಂತರ, sh->sh_ಗಾತ್ರ);
	    ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ SHT_GNU_verneed:
	    v.verneed = ತುಂಬು_ದತ್ತಾಂಶ(fd, sh->sh_ಸ್ಥಾನಾಂತರ, sh->sh_ಗಾತ್ರ);
	    ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ SHT_GNU_versym:
            v.nb_versyms = sh->sh_ಗಾತ್ರ / ಗಾತ್ರ(ElfW(Half));
	    v.versym = ತುಂಬು_ದತ್ತಾಂಶ(fd, sh->sh_ಸ್ಥಾನಾಂತರ, sh->sh_ಗಾತ್ರ);
	    ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            ನಿಲ್ಲಿಸು;
        }
    }

    ಆದರೆ (!dynamic)
        ಹೋಗು the_ಕೊನೆ;

    /* compute the real library name */
    soname = tcc_basename(filename);
    ಗಾಗಿ(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        ಆದರೆ (dt->d_ಟ್ಯಾಗ್ == DT_SONAME)
            soname = dynstr + dt->d_un.d_val;

    /* if the dll is already loaded, do not load it */
    ಆದರೆ (tcc_ಕೂಡಿಸು_dllref(s1, soname, level)->ಸಿಕ್ಕಿತು)
        ಹೋಗು ret_success;

    ಆದರೆ (v.nb_versyms != nb_syms)
        tcc_free (v.versym), v.versym = ಖಾಲಿ;
    ಇಲ್ಲದಿದ್ದರೆ
        store_ಆವೃತ್ತಿ(s1, &v, dynstr);

    /* add dynamic symbols in dynsym_section */
    ಗಾಗಿ(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        ಆದರೆ (sym_bind == STB_LOCAL)
            ಮುಂದುವರಿ;
        name = dynstr + sym->st_name;
        sym_ಸೂಚ್ಯಂಕ = ಗಣ_elf_sym(s1->dynsymtab_section, sym->st_ಮೌಲ್ಯ, sym->st_ಗಾತ್ರ,
                                sym->st_info, sym->st_other, sym->st_shndx, name);
        ಆದರೆ (v.versym) {
            ElfW(Half) vsym = v.versym[i];
            ಆದರೆ ((vsym & 0x8000) == 0 && vsym > 0 && vsym < v.nb_local_ver)
                ಗಣ_sym_ಆವೃತ್ತಿ(s1, sym_ಸೂಚ್ಯಂಕ, v.local_ver[vsym]);
        }
    }

    /* do not load all referenced libraries
       (recursive loading can break linking of libraries) */
    /* following DT_NEEDED is needed for the dynamic loader (libdl.so),
       but it is no longer needed, when linking a library or a program.
       When tcc output mode is OUTPUT_MEM,
       tcc calls dlopen, which handles DT_NEEDED for us */

#ಆದರೆ 0
    ಗಾಗಿ(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        ಆದರೆ (dt->d_ಟ್ಯಾಗ್ == DT_RPATH)
            tcc_ಕೂಡಿಸು_library_ಮಾರ್ಗ(s1, dynstr + dt->d_un.d_val);

    /* load all referenced DLLs */
    ಗಾಗಿ(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        ಆಯ್ಕೆ(dt->d_ಟ್ಯಾಗ್) {
        ಸ್ಥಿತಿ DT_NEEDED:
            name = dynstr + dt->d_un.d_val;
            ಆದರೆ (tcc_ಕೂಡಿಸು_dllref(s1, name, -1))
                ಮುಂದುವರಿ;
            ಆದರೆ (tcc_ಕೂಡಿಸು_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                ret = tcc_error_noabort("referenced dll '%s' not found", name);
                ಹೋಗು the_ಕೊನೆ;
            }
        }
    }
#ಆದರೆ_ಅಂತ್ಯ

 ret_success:
    ret = 0;
 the_ಕೊನೆ:
    tcc_free(dynstr);
    tcc_free(dynsym);
    tcc_free(dynamic);
    tcc_free(shdr);
    tcc_free(v.local_ver);
    tcc_free(v.verdef);
    tcc_free(v.verneed);
    tcc_free(v.versym);
    ಹಿಂತಿರುಗಿ ret;
}

#ವ್ಯಾಖ್ಯಾನಿಸು LD_TOK_NAME 256
#ವ್ಯಾಖ್ಯಾನಿಸು LD_TOK_EOF  (-1)
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ld_inp(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ c = *s1->ld_p;
    ಆದರೆ (c == 0)
        ಹಿಂತಿರುಗಿ CH_EOF;
    ++s1->ld_p;
    ಹಿಂತಿರುಗಿ c;
}
#ವ್ಯಾಖ್ಯಾನಿಸು ld_unget(s1, ch) ಆದರೆ (ch != CH_EOF) --s1->ld_p

/* return next ld script token */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ld_ಮುಂದಿನ(TCCState *s1, ಅಕ್ಷರ *name, ಪೂರ್ಣಾಂಕ name_ಗಾತ್ರ)
{
    ಪೂರ್ಣಾಂಕ c, d, ch;
    ಅಕ್ಷರ *q;

 redo:
    ch = ld_inp(s1);
    q = name, *q++ = ch;
    ಆಯ್ಕೆ(ch) {
    ಸ್ಥಿತಿ ' ':
    ಸ್ಥಿತಿ '\t':
    ಸ್ಥಿತಿ '\f':
    ಸ್ಥಿತಿ '\v':
    ಸ್ಥಿತಿ '\r':
    ಸ್ಥಿತಿ '\n':
        ಹೋಗು redo;
    ಸ್ಥಿತಿ '/':
        ch = ld_inp(s1);
        ಆದರೆ (ch == '*') { /* comment */
            ಗಾಗಿ (d = 0;; d = ch) {
                ch = ld_inp(s1);
                ಆದರೆ (ch == CH_EOF || (ch == '/' && d == '*'))
                    ನಿಲ್ಲಿಸು;
            }
            ಹೋಗು redo;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಹೋಗು parse_name;
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '\\':
    /* case 'a' ... 'z': */
    ಸ್ಥಿತಿ 'a':
       ಸ್ಥಿತಿ 'b':
       ಸ್ಥಿತಿ 'c':
       ಸ್ಥಿತಿ 'd':
       ಸ್ಥಿತಿ 'e':
       ಸ್ಥಿತಿ 'f':
       ಸ್ಥಿತಿ 'g':
       ಸ್ಥಿತಿ 'h':
       ಸ್ಥಿತಿ 'i':
       ಸ್ಥಿತಿ 'j':
       ಸ್ಥಿತಿ 'k':
       ಸ್ಥಿತಿ 'l':
       ಸ್ಥಿತಿ 'm':
       ಸ್ಥಿತಿ 'n':
       ಸ್ಥಿತಿ 'o':
       ಸ್ಥಿತಿ 'p':
       ಸ್ಥಿತಿ 'q':
       ಸ್ಥಿತಿ 'r':
       ಸ್ಥಿತಿ 's':
       ಸ್ಥಿತಿ 't':
       ಸ್ಥಿತಿ 'u':
       ಸ್ಥಿತಿ 'v':
       ಸ್ಥಿತಿ 'w':
       ಸ್ಥಿತಿ 'x':
       ಸ್ಥಿತಿ 'y':
       ಸ್ಥಿತಿ 'z':
    /* case 'A' ... 'z': */
    ಸ್ಥಿತಿ 'A':
       ಸ್ಥಿತಿ 'B':
       ಸ್ಥಿತಿ 'C':
       ಸ್ಥಿತಿ 'D':
       ಸ್ಥಿತಿ 'E':
       ಸ್ಥಿತಿ 'F':
       ಸ್ಥಿತಿ 'G':
       ಸ್ಥಿತಿ 'H':
       ಸ್ಥಿತಿ 'I':
       ಸ್ಥಿತಿ 'J':
       ಸ್ಥಿತಿ 'K':
       ಸ್ಥಿತಿ 'L':
       ಸ್ಥಿತಿ 'M':
       ಸ್ಥಿತಿ 'N':
       ಸ್ಥಿತಿ 'O':
       ಸ್ಥಿತಿ 'P':
       ಸ್ಥಿತಿ 'Q':
       ಸ್ಥಿತಿ 'R':
       ಸ್ಥಿತಿ 'S':
       ಸ್ಥಿತಿ 'T':
       ಸ್ಥಿತಿ 'U':
       ಸ್ಥಿತಿ 'V':
       ಸ್ಥಿತಿ 'W':
       ಸ್ಥಿತಿ 'X':
       ಸ್ಥಿತಿ 'Y':
       ಸ್ಥಿತಿ 'Z':
    ಸ್ಥಿತಿ '-':
    ಸ್ಥಿತಿ '_':
    ಸ್ಥಿತಿ '.':
    ಸ್ಥಿತಿ '$':
    ಸ್ಥಿತಿ '~':
        ಗಾಗಿ(;;) {
            ch = ld_inp(s1);
    parse_name:
            ಆದರೆ (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') ||
                  strchr("/.-_+=$:\\,~", ch)))
                ನಿಲ್ಲಿಸು;
            ಆದರೆ ((q - name) < name_ಗಾತ್ರ - 1) {
                *q++ = ch;
            }
        }
        ld_unget(s1, ch);
        c = LD_TOK_NAME;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ CH_EOF:
        c = LD_TOK_EOF;
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        c = ch;
        ನಿಲ್ಲಿಸು;
    }
    *q = '\0';
    ಹಿಂತಿರುಗಿ c;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ld_ಕೂಡಿಸು_file(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ filename[])
{
    ಆದರೆ (filename[0] == '-' && filename[1] == 'l')
        ಹಿಂತಿರುಗಿ tcc_ಕೂಡಿಸು_library(s1, filename + 2);
    ಆದರೆ (CONFIG_SYSROOT[0] != '\0' || !IS_ABSPATH(filename)) {
        /* lookup via library paths */
        ಪೂರ್ಣಾಂಕ ret = tcc_ಕೂಡಿಸು_dll(s1, tcc_basename(filename), 0);
        ಆದರೆ (ret != FILE_NOT_ಸಿಕ್ಕಿತು)
            ಹಿಂತಿರುಗಿ ret;
    }
    ಹಿಂತಿರುಗಿ tcc_ಕೂಡಿಸು_file_ಆಂತರಿಕ(s1, filename, AFF_PRINT_ERROR);
}

/* did static libraries add new undefined symbols? */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ new_undef_sym(TCCState *s1, ಪೂರ್ಣಾಂಕ sym_ಸ್ಥಾನಾಂತರ)
{
    ಆಗ (sym_ಸ್ಥಾನಾಂತರ < s1->symtab->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        ElfW(Sym) *esym = (ಶೂನ್ಯ*)(s1->symtab->ದತ್ತಾಂಶ + sym_ಸ್ಥಾನಾಂತರ);
        ಆದರೆ (esym->st_shndx == SHN_UNDEF)
            ಹಿಂತಿರುಗಿ 1;
        sym_ಸ್ಥಾನಾಂತರ += ಗಾತ್ರ (ElfW(Sym));
    }
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ld_ಕೂಡಿಸು_file_list(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *cmd)
{
    ಅಕ್ಷರ filename[1024];
    ಪೂರ್ಣಾಂಕ t, c, sym_ಸ್ಥಾನಾಂತರ, ret = 0;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *pos = s1->ld_p;

repeat:
    s1->ld_p = pos;
    sym_ಸ್ಥಾನಾಂತರ = s1->symtab->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    c = cmd[0];

    t = ld_ಮುಂದಿನ(s1, filename, ಗಾತ್ರ(filename));
    ಆದರೆ (t != '(')
        ಹಿಂತಿರುಗಿ tcc_error_noabort("expected '(' after %s", cmd);
    t = ld_ಮುಂದಿನ(s1, filename, ಗಾತ್ರ(filename));
    ಗಾಗಿ(;;) {
        ಆದರೆ (t == LD_TOK_EOF) {
            ಹಿಂತಿರುಗಿ tcc_error_noabort("unexpected end of file");
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == ')') {
            ನಿಲ್ಲಿಸು;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t != LD_TOK_NAME) {
            ಹಿಂತಿರುಗಿ tcc_error_noabort("unexpected token '%c'", t);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(filename, "AS_NEEDED")) {
            ret |= ld_ಕೂಡಿಸು_file_list(s1, filename);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == 'I' || c == 'G' || c == 'A') {
            ret |= !!ld_ಕೂಡಿಸು_file(s1, filename);
        }
        ಆದರೆ (ret < 0)
            ಹಿಂತಿರುಗಿ ret;
        t = ld_ಮುಂದಿನ(s1, filename, ಗಾತ್ರ(filename));
        ಆದರೆ (t == ',')
            t = ld_ಮುಂದಿನ(s1, filename, ಗಾತ್ರ(filename));
    }
    ಆದರೆ (c == 'G' && ret == 0 && new_undef_sym(s1, sym_ಸ್ಥಾನಾಂತರ))
        ಹೋಗು repeat;
    ಹಿಂತಿರುಗಿ ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ತುಂಬು_ldscript(TCCState *s1, ಪೂರ್ಣಾಂಕ fd)
{
    ಅಕ್ಷರ cmd[64];
    ಪೂರ್ಣಾಂಕ t, ret = 0, noscript = 1;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ಪಠ್ಯ_ptr, *saved_ptr;

    saved_ptr = s1->ld_p;
    s1->ld_p = ಪಠ್ಯ_ptr = (ಶೂನ್ಯ*)tcc_ತುಂಬು_ಪಠ್ಯ(fd);
    ಗಾಗಿ(;;) {
        t = ld_ಮುಂದಿನ(s1, cmd, ಗಾತ್ರ(cmd));
        ಆದರೆ (t == LD_TOK_EOF)
            ನಿಲ್ಲಿಸು;
        ಆದರೆ (!strcmp(cmd, "INPUT") ||
            !strcmp(cmd, "GROUP")) {
            ret |= ld_ಕೂಡಿಸು_file_list(s1, cmd);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(cmd, "OUTPUT_FORMAT") ||
                   !strcmp(cmd, "TARGET")) {
            /* ignore some commands */
            ret |= ld_ಕೂಡಿಸು_file_list(s1, cmd);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (noscript) {
            ret = FILE_NOT_RECOGNIZED;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ret = tcc_error_noabort("unexpected '%s'", cmd);
        }
        ಆದರೆ (ret < 0)
            ನಿಲ್ಲಿಸು;
        noscript = 0;
    }
    tcc_free(ಪಠ್ಯ_ptr);
    s1->ld_p = saved_ptr;
    ಹಿಂತಿರುಗಿ ret < 0 ? ret : -ret;
}
#ಆದರೆ_ಅಂತ್ಯ /* !ELF_OBJ_ONLY */
