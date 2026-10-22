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

#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

/* Define this to get some debug output during relocation processing.  */
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ DEBUG_RELOC

/********************************************************/
/* global variables */

/* elf version information */
ਬਣਤਰ sym_ਸੰਸਕਰਣ {
    ਅੱਖਰ *lib;
    ਅੱਖਰ *ਸੰਸਕਰਣ;
    ਪੂਰਨ ਬਾਹਰਲਾ_ਸੂਚਕਾਂਕ;
    ਪੂਰਨ prev_same_lib;
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ nb_sym_versions     s1->nb_sym_versions
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ sym_versions        s1->sym_versions
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ nb_sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ   s1->nb_sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ      s1->sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dt_verneednum       s1->dt_verneednum
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ versym_section      s1->versym_section
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ verneed_section     s1->verneed_section

/* special flag to indicate that the section should not be linked to the other ones */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHF_ਨਿੱਜੀ 0x80000000
/* section is dynsymtab_section */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHF_DYNSYM 0x40000000

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ shf_RELRO SHF_ALLOC
ਸਥਿਰ ਅਚਲ ਅੱਖਰ rdata[] = ".rdata";
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ shf_RELRO SHF_ALLOC /* eventually made SHF_WRITE in sort_sections() */
ਸਥਿਰ ਅਚਲ ਅੱਖਰ rdata[] = ".data.ro";
#ਜੇ_ਅੰਤ

/* ------------------------------------------------------------------------- */

ST_FUNC ਖਾਲੀ tccelf_new(TCCState *s)
{
    TCCState *s1 = s;

    /* no section zero */
    dynarray_ਜੋੜੋ(&s->sections, &s->nb_sections, ਨਿਰਾ);

    /* create standard sections */
    ਪਾਠ_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    ਅੰਕੜੇ_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    /* create ro data section (make ro after relocation done with GNU_RELRO) */
    rodata_section = new_section(s, rdata, SHT_PROGBITS, shf_RELRO);
    bss_section = new_section(s, ".bss", SHT_NOBITS, SHF_ALLOC | SHF_WRITE);
    common_section = new_section(s, ".common", SHT_NOBITS, SHF_ਨਿੱਜੀ);
    common_section->sh_ਅੰਕ = SHN_COMMON;

    /* symbols are always generated for linking stage */
    symtab_section = new_symtab(s, ".symtab", SHT_SYMTAB, 0,
                                ".strtab",
                                ".hashtab", SHF_ਨਿੱਜੀ);

    /* private symbol table for dynamic symbols */
    s->dynsymtab_section = new_symtab(s, ".dynsymtab", SHT_SYMTAB, SHF_ਨਿੱਜੀ|SHF_DYNSYM,
                                      ".dynstrtab",
                                      ".dynhashtab", SHF_ਨਿੱਜੀ);
    get_sym_attr(s, 0, 1);

    ਜੇ (s->do_debug) {
        /* add debug sections */
        tcc_debug_new(s);
    }

#ਜੇ TCC_EH_ਚੌਖਟਾ
    ਜੇ (s->output_format != TCC_OUTPUT_FORMAT_ELF)
        s->unwind_tables = 0;
    tcc_eh_ਚੌਖਟਾ_ਸ਼ੁਰੂ(s);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        /* (make ro after relocation done with GNU_RELRO) */
        bounds_section = new_section(s, ".bounds", SHT_PROGBITS, shf_RELRO);
        lbounds_section = new_section(s, ".lbounds", SHT_PROGBITS, shf_RELRO);
    }
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    /* to make sure that -ltcc1 -Wl,-e,_start will grab the startup code
       from libtcc1.a (unless _start defined) */
    ਜੇ (s->elf_entryname)
        ਸੈੱਟ_global_sym(s, s->elf_entryname, ਨਿਰਾ, 0); /* SHN_UNDEF */
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
    ਜੇ (ਨਿਰਾ == s->elfint && s1->output_type != TCC_OUTPUT_OBJ) {
        ਅਚਲ ਅੱਖਰ *p = CONFIG_TCC_ELFINTERP;
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM && defined CONFIG_TCC_ELFINTERP_ARMHF
        ਜੇ (s->float_abi == ARM_HARD_FLOAT)
            p = CONFIG_TCC_ELFINTERP_ARMHF;
#ਜੇ_ਅੰਤ
#ਜੇ defined TCC_IS_NATIVE && defined TARGETOS_BSD
        /* see commit 55cb2170cd5ce77a7d76dcaf462fad2707281605 */
        { ਅਚਲ ਅੱਖਰ *e = getenv("LD_SO"); ਜੇ (e) p = e; }
#ਜੇ_ਅੰਤ
        s->elfint = tcc_strdup(p);
    }
#ਜੇ_ਅੰਤ /* ndef ELF_OBJ_ONLY */
}

ST_FUNC ਖਾਲੀ free_section(Section *s)
{
    ਜੇ (!s)
        ਵਾਪਸ;
    tcc_free(s->ਅੰਕੜੇ);
    s->ਅੰਕੜੇ = ਨਿਰਾ;
    s->ਅੰਕੜੇ_allocated = s->ਅੰਕੜੇ_ਵਿੱਥ = 0;
}

ST_FUNC ਖਾਲੀ tccelf_delete(TCCState *s1)
{
    ਪੂਰਨ i;

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
    /* free symbol versions */
    ਲਈ (i = 0; i < nb_sym_versions; i++) {
        tcc_free(sym_versions[i].ਸੰਸਕਰਣ);
        tcc_free(sym_versions[i].lib);
    }
    tcc_free(sym_versions);
    tcc_free(sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ);
#ਜੇ_ਅੰਤ

    /* free all sections */
    ਲਈ(i = 1; i < s1->nb_sections; i++)
        free_section(s1->sections[i]);
    dynarray_reset(&s1->sections, &s1->nb_sections);

    ਲਈ(i = 0; i < s1->nb_priv_sections; i++)
        free_section(s1->priv_sections[i]);
    dynarray_reset(&s1->priv_sections, &s1->nb_priv_sections);

    tcc_free(s1->sym_attrs);
    symtab_section = ਨਿਰਾ; /* for tccrun.c:rt_printline() */
}

/* save section data state */
ST_FUNC ਖਾਲੀ tccelf_begin_file(TCCState *s1)
{
    Section *s; ਪੂਰਨ i;
    ਲਈ (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        s->sh_ਵਿੱਥ = s->ਅੰਕੜੇ_ਵਿੱਥ;
    }
    /* disable symbol hashing during compilation */
    s = s1->symtab, s->reloc = s->hash, s->hash = ਨਿਰਾ;
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_X86_64 && defined TCC_ਨਿਸ਼ਾਨਾ_PE
    s1->uw_sym = 0;
    s1->uw_offs = 0;
#ਜੇ_ਅੰਤ
}

ਸਥਿਰ ਖਾਲੀ update_relocs(TCCState *s1, Section *s, ਪੂਰਨ *old_ਮੰਜ਼ਿਲ_new_syms, ਪੂਰਨ ਪਹਿਲਾ_sym);

/* At the end of compilation, convert any UNDEF syms to global, and merge
   with previously existing symbols */
ST_FUNC ਖਾਲੀ tccelf_ਸਿਰਾ_file(TCCState *s1)
{
    Section *s = s1->symtab;
    ਪੂਰਨ ਪਹਿਲਾ_sym, nb_syms, *tr, i;

    ਪਹਿਲਾ_sym = s->sh_ਵਿੱਥ / ਆਕਾਰ (ElfSym);
    nb_syms = s->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ (ElfSym) - ਪਹਿਲਾ_sym;
    s->ਅੰਕੜੇ_ਵਿੱਥ = s->sh_ਵਿੱਥ;
    s->link->ਅੰਕੜੇ_ਵਿੱਥ = s->link->sh_ਵਿੱਥ;
    s->hash = s->reloc, s->reloc = ਨਿਰਾ;
    tr = tcc_mallocz(nb_syms * ਆਕਾਰ *tr);

    ਲਈ (i = 0; i < nb_syms; ++i) {
        ElfSym *sym = (ElfSym*)s->ਅੰਕੜੇ + ਪਹਿਲਾ_sym + i;
        ਜੇ (sym->st_shndx == SHN_UNDEF) {
            ਪੂਰਨ sym_bind = ELFW(ST_BIND)(sym->st_info);
            ਪੂਰਨ sym_type = ELFW(ST_TYPE)(sym->st_info);
            ਜੇ (sym_bind == STB_LOCAL)
                sym_bind = STB_GLOBAL;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
            ਜੇ (sym_bind == STB_GLOBAL && s1->output_type == TCC_OUTPUT_OBJ) {
                /* undefined symbols with STT_FUNC are confusing gnu ld when
                   linking statically to STT_GNU_IFUNC.  Keep TLS typed,
                   otherwise gnu ld rejects non-TLS refs to TLS definitions. */
                ਜੇ (sym_type != STT_TLS)
                    sym_type = STT_NOTYPE;
            }
#ਜੇ_ਅੰਤ
            sym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
        }
        tr[i] = ਸੈੱਟ_elf_sym(s, sym->st_ਮੁੱਲ, sym->st_ਮਾਪ, sym->st_info,
            sym->st_other, sym->st_shndx, (ਅੱਖਰ*)s->link->ਅੰਕੜੇ + sym->st_name);
    }
    /* now update relocations */
    update_relocs(s1, s, tr, ਪਹਿਲਾ_sym);
    tcc_free(tr);
    /* record text/data/bss output for -bench info */
    ਲਈ (i = 0; i < 4; ++i) {
        s = s1->sections[i + 1];
        s1->ਕੁੱਲ_output[i] += s->ਅੰਕੜੇ_ਵਿੱਥ - s->sh_ਵਿੱਥ;
    }
}

ST_FUNC Section *new_section(TCCState *s1, ਅਚਲ ਅੱਖਰ *name, ਪੂਰਨ sh_type, ਪੂਰਨ sh_flags)
{
    Section *sec;

    sec = tcc_mallocz(ਆਕਾਰ(Section) + ਲੜੀ_ਲੰਬਾਈ(name));
    sec->s1 = s1;
    strcpy(sec->name, name);
    sec->sh_type = sh_type;
    sec->sh_flags = sh_flags;
    ਚੋਣ(sh_type) {
    ਹਾਲਤ SHT_GNU_versym:
        sec->sh_addralign = 2;
        ਰੋਕੋ;
    ਹਾਲਤ SHT_HASH:
    ਹਾਲਤ SHT_GNU_HASH:
    ਹਾਲਤ SHT_REL:
    ਹਾਲਤ SHT_RELA:
    ਹਾਲਤ SHT_DYNSYM:
    ਹਾਲਤ SHT_SYMTAB:
    ਹਾਲਤ SHT_DYNAMIC:
    ਹਾਲਤ SHT_GNU_verneed:
    ਹਾਲਤ SHT_GNU_verdef:
        sec->sh_addralign = PTR_ਮਾਪ;
        ਰੋਕੋ;
    ਹਾਲਤ SHT_STRTAB:
        sec->sh_addralign = 1;
        ਰੋਕੋ;
    ਮੂਲ:
        sec->sh_addralign =  PTR_ਮਾਪ; /* gcc/pcc default alignment */
        ਰੋਕੋ;
    }

    ਜੇ (sh_flags & SHF_ਨਿੱਜੀ) {
        dynarray_ਜੋੜੋ(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } ਨਹੀਂਤਾਂ {
        sec->sh_ਅੰਕ = s1->nb_sections;
        dynarray_ਜੋੜੋ(&s1->sections, &s1->nb_sections, sec);
    }

    ਵਾਪਸ sec;
}

ST_FUNC ਖਾਲੀ init_symtab(Section *s)
{
    ਪੂਰਨ *ptr, nb_buckets = 1;
    put_elf_str(s->link, "");
    section_ptr_ਜੋੜੋ(s, ਆਕਾਰ (ElfW(Sym)));
    ptr = section_ptr_ਜੋੜੋ(s->hash, (2 + nb_buckets + 1) * ਆਕਾਰ(ਪੂਰਨ));
    ptr[0] = nb_buckets;
    ptr[1] = 1;
    memset(ptr + 2, 0, (nb_buckets + 1) * ਆਕਾਰ(ਪੂਰਨ));
}

ST_FUNC Section *new_symtab(TCCState *s1,
                           ਅਚਲ ਅੱਖਰ *symtab_name, ਪੂਰਨ sh_type, ਪੂਰਨ sh_flags,
                           ਅਚਲ ਅੱਖਰ *strtab_name,
                           ਅਚਲ ਅੱਖਰ *hash_name, ਪੂਰਨ hash_sh_flags)
{
    Section *symtab, *strtab, *hash;
    symtab = new_section(s1, symtab_name, sh_type, sh_flags);
    symtab->sh_entsize = ਆਕਾਰ(ElfW(Sym));
    strtab = new_section(s1, strtab_name, SHT_STRTAB, sh_flags);
    symtab->link = strtab;
    hash = new_section(s1, hash_name, SHT_HASH, hash_sh_flags);
    hash->sh_entsize = ਆਕਾਰ(ਪੂਰਨ);
    symtab->hash = hash;
    hash->link = symtab;
    init_symtab(symtab);
    ਵਾਪਸ symtab;
}

/* realloc section and set its content to zero */
ST_FUNC ਖਾਲੀ section_realloc(Section *sec, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ new_ਮਾਪ)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ਅੰਕੜੇ;

    ਮਾਪ = sec->ਅੰਕੜੇ_allocated;
    ਜੇ (ਮਾਪ == 0)
        ਮਾਪ = 1;
    ਜਦੋਂ (ਮਾਪ < new_ਮਾਪ)
        ਮਾਪ = ਮਾਪ * 2;
    ਅੰਕੜੇ = tcc_realloc(sec->ਅੰਕੜੇ, ਮਾਪ);
    memset(ਅੰਕੜੇ + sec->ਅੰਕੜੇ_allocated, 0, ਮਾਪ - sec->ਅੰਕੜੇ_allocated);
    sec->ਅੰਕੜੇ = ਅੰਕੜੇ;
    sec->ਅੰਕੜੇ_allocated = ਮਾਪ;
}

/* reserve at least 'size' bytes aligned per 'align' in section
   'sec' from current offset, and return the aligned offset */
ST_FUNC ਮਾਪ_t section_ਜੋੜੋ(Section *sec, addr_t ਮਾਪ, ਪੂਰਨ align)
{
    ਮਾਪ_t ਵਿੱਥ, offset1;

    ਵਿੱਥ = (sec->ਅੰਕੜੇ_ਵਿੱਥ + align - 1) & -align;
    offset1 = ਵਿੱਥ + ਮਾਪ;
    ਜੇ (sec->sh_type != SHT_NOBITS && offset1 > sec->ਅੰਕੜੇ_allocated)
        section_realloc(sec, offset1);
    sec->ਅੰਕੜੇ_ਵਿੱਥ = offset1;
    ਜੇ (align > sec->sh_addralign)
        sec->sh_addralign = align;
    ਵਾਪਸ ਵਿੱਥ;
}

/* reserve at least 'size' bytes in section 'sec' from
   sec->data_offset. */
ST_FUNC ਖਾਲੀ *section_ptr_ਜੋੜੋ(Section *sec, addr_t ਮਾਪ)
{
    ਮਾਪ_t ਵਿੱਥ = section_ਜੋੜੋ(sec, ਮਾਪ, 1);
    ਵਾਪਸ sec->ਅੰਕੜੇ + ਵਿੱਥ;
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
/* reserve at least 'size' bytes from section start */
ਸਥਿਰ ਖਾਲੀ section_reserve(Section *sec, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ)
{
    ਜੇ (ਮਾਪ > sec->ਅੰਕੜੇ_allocated)
        section_realloc(sec, ਮਾਪ);
    ਜੇ (ਮਾਪ > sec->ਅੰਕੜੇ_ਵਿੱਥ)
        sec->ਅੰਕੜੇ_ਵਿੱਥ = ਮਾਪ;
}
#ਜੇ_ਅੰਤ

ਸਥਿਰ Section *have_section(TCCState *s1, ਅਚਲ ਅੱਖਰ *name)
{
    Section *sec;
    ਪੂਰਨ i;
    ਲਈ(i = 1; i < s1->nb_sections; i++) {
        sec = s1->sections[i];
        ਜੇ (!strcmp(name, sec->name))
            ਵਾਪਸ sec;
    }
    ਵਾਪਸ ਨਿਰਾ;
}

/* return a reference to a section, and create it if it does not
   exists */
ST_FUNC Section *ਲੱਭੋ_section(TCCState *s1, ਅਚਲ ਅੱਖਰ *name)
{
    Section *sec = have_section(s1, name);
    ਜੇ (sec)
        ਵਾਪਸ sec;
    /* sections are created as PROGBITS */
    ਵਾਪਸ new_section(s1, name, SHT_PROGBITS, SHF_ALLOC);
}

/* ------------------------------------------------------------------------- */

ST_FUNC ਪੂਰਨ put_elf_str(Section *s, ਅਚਲ ਅੱਖਰ *sym)
{
    ਪੂਰਨ ਵਿੱਥ, len;
    ਅੱਖਰ *ptr;

    len = ਲੜੀ_ਲੰਬਾਈ(sym) + 1;
    ਵਿੱਥ = s->ਅੰਕੜੇ_ਵਿੱਥ;
    ptr = section_ptr_ਜੋੜੋ(s, len);
    memmove(ptr, sym, len);
    ਵਾਪਸ ਵਿੱਥ;
}

/* elf symbol hashing function */
ਸਥਿਰ ElfW(ਸ਼ਬਦ_2) elf_hash(ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *name)
{
    ElfW(ਸ਼ਬਦ_2) h = 0, g;

    ਜਦੋਂ (*name) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        ਜੇ (g)
            h ^= g >> 24;
        h &= ~g;
    }
    ਵਾਪਸ h;
}

/* rebuild hash table of section s */
/* NOTE: we do factorize the hash table code to go faster */
ਸਥਿਰ ਖਾਲੀ rebuild_hash(Section *s, ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ nb_buckets)
{
    ElfW(Sym) *sym;
    ਪੂਰਨ *ptr, *hash, nb_syms, sym_ਸੂਚਕਾਂਕ, h;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *strtab;

    strtab = s->link->ਅੰਕੜੇ;
    nb_syms = s->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ(ElfW(Sym));

    ਜੇ (!nb_buckets)
        nb_buckets = ((ਪੂਰਨ*)s->hash->ਅੰਕੜੇ)[0];

    s->hash->ਅੰਕੜੇ_ਵਿੱਥ = 0;
    ptr = section_ptr_ਜੋੜੋ(s->hash, (2 + nb_buckets + nb_syms) * ਆਕਾਰ(ਪੂਰਨ));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    memset(hash, 0, (nb_buckets + 1) * ਆਕਾਰ(ਪੂਰਨ));
    ptr += nb_buckets + 1;

    sym = (ElfW(Sym) *)s->ਅੰਕੜੇ + 1;
    ਲਈ(sym_ਸੂਚਕਾਂਕ = 1; sym_ਸੂਚਕਾਂਕ < nb_syms; sym_ਸੂਚਕਾਂਕ++) {
        ਜੇ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            h = elf_hash(strtab + sym->st_name) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_ਸੂਚਕਾਂਕ;
        } ਨਹੀਂਤਾਂ {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}

/* return the symbol number */
ST_FUNC ਪੂਰਨ put_elf_sym(Section *s, addr_t ਮੁੱਲ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ,
    ਪੂਰਨ info, ਪੂਰਨ other, ਪੂਰਨ shndx, ਅਚਲ ਅੱਖਰ *name)
{
    ਪੂਰਨ name_ਵਿੱਥ, sym_ਸੂਚਕਾਂਕ;
    ਪੂਰਨ nbuckets, h;
    ElfW(Sym) *sym;
    Section *hs;

    sym = section_ptr_ਜੋੜੋ(s, ਆਕਾਰ(ElfW(Sym)));
    ਜੇ (name && name[0])
        name_ਵਿੱਥ = put_elf_str(s->link, name);
    ਨਹੀਂਤਾਂ
        name_ਵਿੱਥ = 0;
    /* XXX: endianness */
    sym->st_name = name_ਵਿੱਥ;
    sym->st_ਮੁੱਲ = ਮੁੱਲ;
    sym->st_ਮਾਪ = ਮਾਪ;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
    sym_ਸੂਚਕਾਂਕ = sym - (ElfW(Sym) *)s->ਅੰਕੜੇ;
    hs = s->hash;
    ਜੇ (hs) {
        ਪੂਰਨ *ptr, *ਅਧਾਰ;
        ptr = section_ptr_ਜੋੜੋ(hs, ਆਕਾਰ(ਪੂਰਨ));
        ਅਧਾਰ = (ਪੂਰਨ *)hs->ਅੰਕੜੇ;
        /* only add global or weak symbols. */
        ਜੇ (ELFW(ST_BIND)(info) != STB_LOCAL) {
            /* add another hashing entry */
            nbuckets = ਅਧਾਰ[0];
            h = elf_hash((ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *)s->link->ਅੰਕੜੇ + name_ਵਿੱਥ) % nbuckets;
            *ptr = ਅਧਾਰ[2 + h];
            ਅਧਾਰ[2 + h] = sym_ਸੂਚਕਾਂਕ;
            ਅਧਾਰ[1]++;
            /* we resize the hash table */
            hs->nb_hashed_syms++;
            ਜੇ (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } ਨਹੀਂਤਾਂ {
            *ptr = 0;
            ਅਧਾਰ[1]++;
        }
    }
    ਵਾਪਸ sym_ਸੂਚਕਾਂਕ;
}

ST_FUNC ਪੂਰਨ ਲੱਭੋ_elf_sym(Section *s, ਅਚਲ ਅੱਖਰ *name)
{
    ElfW(Sym) *sym;
    Section *hs;
    ਪੂਰਨ nbuckets, sym_ਸੂਚਕਾਂਕ, h;
    ਅਚਲ ਅੱਖਰ *name1;

    hs = s->hash;
    ਜੇ (!hs)
        ਵਾਪਸ 0;
    nbuckets = ((ਪੂਰਨ *)hs->ਅੰਕੜੇ)[0];
    h = elf_hash((ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *) name) % nbuckets;
    sym_ਸੂਚਕਾਂਕ = ((ਪੂਰਨ *)hs->ਅੰਕੜੇ)[2 + h];
    ਜਦੋਂ (sym_ਸੂਚਕਾਂਕ != 0) {
        sym = &((ElfW(Sym) *)s->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
        name1 = (ਅੱਖਰ *) s->link->ਅੰਕੜੇ + sym->st_name;
        ਜੇ (!strcmp(name, name1))
            ਵਾਪਸ sym_ਸੂਚਕਾਂਕ;
        sym_ਸੂਚਕਾਂਕ = ((ਪੂਰਨ *)hs->ਅੰਕੜੇ)[2 + nbuckets + sym_ਸੂਚਕਾਂਕ];
    }
    ਵਾਪਸ 0;
}

/* return elf symbol value, signal error if 'err' is nonzero, decorate
   name if FORC */
ST_FUNC addr_t get_sym_addr(TCCState *s1, ਅਚਲ ਅੱਖਰ *name, ਪੂਰਨ err, ਪੂਰਨ forc)
{
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ;
    ElfW(Sym) *sym;
    ਅੱਖਰ buf[256];
    ਜੇ (forc && s1->leading_underscore
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        /* win32-32bit stdcall symbols always have _ already */
        && !strchr(name, '@')
#ਜੇ_ਅੰਤ
        ) {
        buf[0] = '_';
        pstrcpy(buf + 1, ਆਕਾਰ(buf) - 1, name);
        name = buf;
    }
    sym_ਸੂਚਕਾਂਕ = ਲੱਭੋ_elf_sym(s1->symtab, name);
    sym = &((ElfW(Sym) *)s1->symtab->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
    ਜੇ (!sym_ਸੂਚਕਾਂਕ || sym->st_shndx == SHN_UNDEF) {
        ਜੇ (err)
            tcc_error_noabort("%s not defined", name);
        ਵਾਪਸ (addr_t)-1;
    }
    ਵਾਪਸ sym->st_ਮੁੱਲ;
}

/* return elf symbol value */
LIBTCCAPI ਖਾਲੀ *tcc_get_ਚਿੰਨ੍ਹ(TCCState *s, ਅਚਲ ਅੱਖਰ *name)
{
    addr_t addr = get_sym_addr(s, name, 0, 1);
    ਵਾਪਸ addr == -1 ? ਨਿਰਾ : (ਖਾਲੀ*)(uintptr_t)addr;
}

LIBTCCAPI ਪੂਰਨ tcc_ਜੋੜੋ_ਚਿੰਨ੍ਹ(TCCState *s1, ਅਚਲ ਅੱਖਰ *name, ਅਚਲ ਖਾਲੀ *val)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s1, 0, name, (uintptr_t)val);
#ਨਹੀਂਤਾਂ
    ਅੱਖਰ buf[256];
    ਜੇ (s1->leading_underscore) {
        buf[0] = '_';
        pstrcpy(buf + 1, ਆਕਾਰ(buf) - 1, name);
        name = buf;
    }
    ਸੈੱਟ_global_sym(s1, name, ਨਿਰਾ, (addr_t)(uintptr_t)val); /* NULL: SHN_ABS */
#ਜੇ_ਅੰਤ
    ਵਾਪਸ 0;
}

/* list elf symbol names and values */
ST_FUNC ਖਾਲੀ list_elf_symbols(TCCState *s, ਖਾਲੀ *ctx,
    ਖਾਲੀ (*ਚਿੰਨ੍ਹ_cb)(ਖਾਲੀ *ctx, ਅਚਲ ਅੱਖਰ *name, ਅਚਲ ਖਾਲੀ *val))
{
    ElfW(Sym) *sym;
    Section *symtab;
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ, ਸਿਰਾ_sym;
    ਅਚਲ ਅੱਖਰ *name;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ sym_vis, sym_bind;

    symtab = s->symtab;
    ਸਿਰਾ_sym = symtab->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ (ElfSym);
    ਲਈ (sym_ਸੂਚਕਾਂਕ = 0; sym_ਸੂਚਕਾਂਕ < ਸਿਰਾ_sym; ++sym_ਸੂਚਕਾਂਕ) {
        sym = &((ElfW(Sym) *)symtab->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
        ਜੇ (sym->st_ਮੁੱਲ) {
            name = (ਅੱਖਰ *) symtab->link->ਅੰਕੜੇ + sym->st_name;
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            sym_vis = ELFW(ST_VISIBILITY)(sym->st_other);
            ਜੇ (sym_bind == STB_GLOBAL && sym_vis == STV_DEFAULT)
                ਚਿੰਨ੍ਹ_cb(ctx, name, (ਖਾਲੀ*)(uintptr_t)sym->st_ਮੁੱਲ);
        }
    }
}

/* list elf symbol names and values */
LIBTCCAPI ਖਾਲੀ tcc_list_symbols(TCCState *s, ਖਾਲੀ *ctx,
    ਖਾਲੀ (*ਚਿੰਨ੍ਹ_cb)(ਖਾਲੀ *ctx, ਅਚਲ ਅੱਖਰ *name, ਅਚਲ ਖਾਲੀ *val))
{
    list_elf_symbols(s, ctx, ਚਿੰਨ੍ਹ_cb);
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
ਸਥਿਰ ਖਾਲੀ
ਸੰਸਕਰਣ_ਜੋੜੋ (TCCState *s1)
{
    ਪੂਰਨ i;
    ElfW(Sym) *sym;
    ElfW(Verneed) *vn = ਨਿਰਾ;
    Section *symtab;
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ, ਸਿਰਾ_sym, nb_versions = 2, nb_entries = 0;
    ElfW(Half) *versym;
    ਅਚਲ ਅੱਖਰ *name;

    ਜੇ (0 == nb_sym_versions)
        ਵਾਪਸ;
    versym_section = new_section(s1, ".gnu.version", SHT_GNU_versym, SHF_ALLOC);
    versym_section->sh_entsize = ਆਕਾਰ(ElfW(Half));
    versym_section->link = s1->dynsym;

    /* add needed symbols */
    symtab = s1->dynsym;
    ਸਿਰਾ_sym = symtab->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ (ElfSym);
    versym = section_ptr_ਜੋੜੋ(versym_section, ਸਿਰਾ_sym * ਆਕਾਰ(ElfW(Half)));
    ਲਈ (sym_ਸੂਚਕਾਂਕ = 1; sym_ਸੂਚਕਾਂਕ < ਸਿਰਾ_sym; ++sym_ਸੂਚਕਾਂਕ) {
        ਪੂਰਨ dllindex, verndx;
        sym = &((ElfW(Sym) *)symtab->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
        name = (ਅੱਖਰ *) symtab->link->ਅੰਕੜੇ + sym->st_name;
        dllindex = ਲੱਭੋ_elf_sym(s1->dynsymtab_section, name);
        verndx = (dllindex && dllindex < nb_sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ)
                 ? sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ[dllindex] : -1;
        ਜੇ (verndx >= 0
            /* XXX: on android, clang refuses to link with a libtcc.so made by tcc
               when defined symbols have a version > 1 or when the version is '0'.
               Whereas version '1' for example for 'signal' in an exe defeats
               bcheck's signal_redir. */
            && (sym->st_shndx == SHN_UNDEF || (s1->output_type & TCC_OUTPUT_EXE))
            ) {
            ਜੇ (!sym_versions[verndx].ਬਾਹਰਲਾ_ਸੂਚਕਾਂਕ)
              sym_versions[verndx].ਬਾਹਰਲਾ_ਸੂਚਕਾਂਕ = nb_versions++;
            versym[sym_ਸੂਚਕਾਂਕ] = sym_versions[verndx].ਬਾਹਰਲਾ_ਸੂਚਕਾਂਕ;
        } ਨਹੀਂਤਾਂ {
            versym[sym_ਸੂਚਕਾਂਕ] = 1; /* (*global*) */
        }
        //printf("SYM %d %s\n", versym[sym_index], name);
    }
    /* generate verneed section, but not when it will be empty.  Some
       dynamic linkers look at their contents even when DTVERNEEDNUM and
       section size is zero.  */
    ਜੇ (nb_versions > 2) {
        verneed_section = new_section(s1, ".gnu.version_r",
                                      SHT_GNU_verneed, SHF_ALLOC);
        verneed_section->link = s1->dynsym->link;
        ਲਈ (i = nb_sym_versions; i-- > 0;) {
            ਬਣਤਰ sym_ਸੰਸਕਰਣ *sv = &sym_versions[i];
            ਪੂਰਨ n_same_libs = 0, prev;
            ਮਾਪ_t vnofs;
            ElfW(Vernaux) *vna = 0;
            ਜੇ (sv->ਬਾਹਰਲਾ_ਸੂਚਕਾਂਕ < 1)
              ਜਾਰੀ;

            /* make sure that a DT_NEEDED tag is put */
            /* abitest-tcc fails on older i386-linux with "ld-linux.so.2" DT_NEEDED
               ret_int_test... Inconsistency detected by ld.so: dl-minimal.c: 148:
               realloc: Assertion `ptr == alloc_last_block' failed! */
            ਜੇ (strcmp(sv->lib, "ld-linux.so.2"))
                tcc_ਜੋੜੋ_dllref(s1, sv->lib, 0);

            vnofs = section_ਜੋੜੋ(verneed_section, ਆਕਾਰ(*vn), 1);
            vn = (ElfW(Verneed)*)(verneed_section->ਅੰਕੜੇ + vnofs);
            vn->vn_ਸੰਸਕਰਣ = 1;
            vn->vn_file = put_elf_str(verneed_section->link, sv->lib);
            vn->vn_aux = ਆਕਾਰ (*vn);
            ਕਰੋ {
                prev = sv->prev_same_lib;
                ਜੇ (sv->ਬਾਹਰਲਾ_ਸੂਚਕਾਂਕ > 0) {
                    vna = section_ptr_ਜੋੜੋ(verneed_section, ਆਕਾਰ(*vna));
                    vna->vna_hash = elf_hash ((ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *)sv->ਸੰਸਕਰਣ);
                    vna->vna_flags = 0;
                    vna->vna_other = sv->ਬਾਹਰਲਾ_ਸੂਚਕਾਂਕ;
                    sv->ਬਾਹਰਲਾ_ਸੂਚਕਾਂਕ = -2;
                    vna->vna_name = put_elf_str(verneed_section->link, sv->ਸੰਸਕਰਣ);
                    vna->vna_ਅਗਲਾ = ਆਕਾਰ (*vna);
                    //printf("LIB %d %s %s\n", vna->vna_other, sv->lib, verneed_section->link->data + vna->vna_name);
                    n_same_libs++;
                }
                ਜੇ (prev >= 0)
                  sv = &sym_versions[prev];
            } ਜਦੋਂ(prev >= 0);
            vna->vna_ਅਗਲਾ = 0;
            vn = (ElfW(Verneed)*)(verneed_section->ਅੰਕੜੇ + vnofs);
            vn->vn_cnt = n_same_libs;
            vn->vn_ਅਗਲਾ = ਆਕਾਰ(*vn) + n_same_libs * ਆਕਾਰ(*vna);
            nb_entries++;
        }
        ਜੇ (vn)
          vn->vn_ਅਗਲਾ = 0;
        verneed_section->sh_info = nb_entries;
    }
    dt_verneednum = nb_entries;
}
#ਜੇ_ਅੰਤ /* ndef ELF_OBJ_ONLY */

/* catch .tbss also */
ਸਥਿਰ ਪੂਰਨ IS_BSS(TCCState *s1, ਪੂਰਨ ndx)
{
    ਵਾਪਸ ndx == SHN_COMMON
     || (ndx < s1->nb_sections
         && s1->sections[ndx]->sh_type == SHT_NOBITS);
}

/* add an elf symbol : check if it is already defined and patch
   it. Return symbol index. NOTE that sh_num can be SHN_UNDEF. */
ST_FUNC ਪੂਰਨ ਸੈੱਟ_elf_sym(Section *s, addr_t ਮੁੱਲ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ,
                       ਪੂਰਨ info, ਪੂਰਨ other, ਪੂਰਨ shndx, ਅਚਲ ਅੱਖਰ *name)
{
    TCCState *s1 = s->s1;
    ElfW(Sym) *esym;
    ਪੂਰਨ sym_bind, sym_ਸੂਚਕਾਂਕ, sym_type, esym_bind;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ sym_vis, esym_vis, new_vis;

    sym_bind = ELFW(ST_BIND)(info);
    sym_type = ELFW(ST_TYPE)(info);
    sym_vis = ELFW(ST_VISIBILITY)(other);

    ਜੇ (sym_bind != STB_LOCAL) {
        /* we search global or weak symbols */
        sym_ਸੂਚਕਾਂਕ = ਲੱਭੋ_elf_sym(s, name);
        ਜੇ (!sym_ਸੂਚਕਾਂਕ)
            ਜਾਓ do_def;
        esym = &((ElfW(Sym) *)s->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
        ਜੇ (esym->st_ਮੁੱਲ == ਮੁੱਲ && esym->st_ਮਾਪ == ਮਾਪ && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            ਵਾਪਸ sym_ਸੂਚਕਾਂਕ;
        ਜੇ (esym->st_shndx != SHN_UNDEF) {
            esym_bind = ELFW(ST_BIND)(esym->st_info);
            /* propagate the most constraining visibility */
            /* STV_DEFAULT(0)<STV_PROTECTED(3)<STV_HIDDEN(2)<STV_INTERNAL(1) */
            esym_vis = ELFW(ST_VISIBILITY)(esym->st_other);
            ਜੇ (esym_vis == STV_DEFAULT) {
                new_vis = sym_vis;
            } ਨਹੀਂਤਾਂ ਜੇ (sym_vis == STV_DEFAULT) {
                new_vis = esym_vis;
            } ਨਹੀਂਤਾਂ {
                new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
            }
            esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
                             | new_vis;
            ਜੇ (shndx == SHN_UNDEF) {
                /* ignore adding of undefined symbol if the
                   corresponding symbol is already defined */
            } ਨਹੀਂਤਾਂ ਜੇ (sym_bind == STB_GLOBAL && esym_bind == STB_WEAK) {
                /* global overrides weak, so patch */
                ਜਾਓ do_patch;
            } ਨਹੀਂਤਾਂ ਜੇ (sym_bind == STB_WEAK && esym_bind == STB_GLOBAL) {
                /* weak is ignored if already global */
            } ਨਹੀਂਤਾਂ ਜੇ (sym_bind == STB_WEAK && esym_bind == STB_WEAK) {
                /* keep first-found weak definition, ignore subsequents */
            } ਨਹੀਂਤਾਂ ਜੇ (sym_vis == STV_HIDDEN || sym_vis == STV_ਅੰਦਰੂਨੀ) {
                /* ignore hidden symbols after */
            } ਨਹੀਂਤਾਂ ਜੇ (s->sh_flags & SHF_DYNSYM) {
                /* we accept that two DLL define the same symbol */
            } ਨਹੀਂਤਾਂ ਜੇ (!IS_BSS(s1, shndx) && IS_BSS(s1, esym->st_shndx)) {
                /* data symbol gets precedence over common/bss */
                ਜਾਓ do_patch;
            } ਨਹੀਂਤਾਂ ਜੇ (IS_BSS(s1, shndx)) {
                /* data symbol keeps precedence over common/bss */
	    } ਨਹੀਂਤਾਂ ਜੇ (esym->st_other & ST_ASM_ਸੈੱਟ) {
		/* If the existing symbol came from an asm .set
		   we can override.  */
		ਜਾਓ do_patch;
            } ਨਹੀਂਤਾਂ {
#ਜੇ 0
                ਲਿਖੋ("new_bind=%x new_shndx=%x new_vis=%x old_bind=%x old_shndx=%x old_vis=%x\n",
                       sym_bind, shndx, new_vis, esym_bind, esym->st_shndx, esym_vis);
#ਜੇ_ਅੰਤ
                tcc_error_noabort("link symbol '%s' defined twice", name);
            }
        } ਨਹੀਂਤਾਂ {
            esym->st_other = other;
        do_patch:
            esym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
            esym->st_shndx = shndx;
            esym->st_ਮੁੱਲ = ਮੁੱਲ;
            esym->st_ਮਾਪ = ਮਾਪ;
        }
    } ਨਹੀਂਤਾਂ {
    do_def:
        sym_ਸੂਚਕਾਂਕ = put_elf_sym(s, ਮੁੱਲ, ਮਾਪ,
                                ELFW(ST_INFO)(sym_bind, sym_type), other,
                                shndx, name);
    }
    ਵਾਪਸ sym_ਸੂਚਕਾਂਕ;
}

/* put relocation */
ST_FUNC ਖਾਲੀ put_elf_reloca(Section *symtab, Section *s, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ,
                            ਪੂਰਨ type, ਪੂਰਨ ਚਿੰਨ੍ਹ, addr_t addend)
{
    TCCState *s1 = s->s1;
    ਅੱਖਰ buf[256];
    Section *sr;
    ElfW_Rel *rel;

    sr = s->reloc;
    ਜੇ (!sr) {
        /* if no relocation section, create it */
        snprintf(buf, ਆਕਾਰ(buf), REL_SECTION_FMT, s->name);
        /* if the symtab is allocated, then we consider the relocation
           are also */
        sr = new_section(s->s1, buf, SHT_RELX, symtab->sh_flags);
        sr->sh_entsize = ਆਕਾਰ(ElfW_Rel);
        sr->link = symtab;
        sr->sh_info = s->sh_ਅੰਕ;
        s->reloc = sr;
    }
    rel = section_ptr_ਜੋੜੋ(sr, ਆਕਾਰ(ElfW_Rel));
    rel->r_ਵਿੱਥ = ਵਿੱਥ;
    rel->r_info = ELFW(R_INFO)(ਚਿੰਨ੍ਹ, type);
#ਜੇ SHT_RELX == SHT_RELA
    rel->r_addend = addend;
#ਜੇ_ਅੰਤ
    ਜੇ (SHT_RELX != SHT_RELA && addend)
        tcc_error_noabort("non-zero addend on REL architecture");
}

ST_FUNC ਖਾਲੀ put_elf_reloc(Section *symtab, Section *s, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ,
                           ਪੂਰਨ type, ਪੂਰਨ ਚਿੰਨ੍ਹ)
{
    put_elf_reloca(symtab, s, ਵਿੱਥ, type, ਚਿੰਨ੍ਹ, 0);
}

ST_FUNC ਬਣਤਰ sym_attr *get_sym_attr(TCCState *s1, ਪੂਰਨ ਸੂਚਕਾਂਕ, ਪੂਰਨ alloc)
{
    ਪੂਰਨ n;
    ਬਣਤਰ sym_attr *tab;

    ਜੇ (ਸੂਚਕਾਂਕ >= s1->nb_sym_attrs) {
        ਜੇ (!alloc)
            ਵਾਪਸ s1->sym_attrs;
        /* find immediately bigger power of 2 and reallocate array */
        n = 1;
        ਜਦੋਂ (ਸੂਚਕਾਂਕ >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * ਆਕਾਰ(*s1->sym_attrs));
        s1->sym_attrs = tab;
        memset(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * ਆਕਾਰ(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    ਵਾਪਸ &s1->sym_attrs[ਸੂਚਕਾਂਕ];
}

ਸਥਿਰ ਖਾਲੀ update_relocs(TCCState *s1, Section *s, ਪੂਰਨ *old_ਮੰਜ਼ਿਲ_new_syms, ਪੂਰਨ ਪਹਿਲਾ_sym)
{
    ਪੂਰਨ i, type, sym_ਸੂਚਕਾਂਕ;
    Section *sr;
    ElfW_Rel *rel;

    ਲਈ(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        ਜੇ (sr->sh_type == SHT_RELX && sr->link == s) {
            for_each_elem(sr, 0, rel, ElfW_Rel) {
                sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(rel->r_info);
                type = ELFW(R_TYPE)(rel->r_info);
                ਜੇ ((sym_ਸੂਚਕਾਂਕ -= ਪਹਿਲਾ_sym) < 0)
                    ਜਾਰੀ; /* zero sym_index in reloc (can happen with asm) */
                sym_ਸੂਚਕਾਂਕ = old_ਮੰਜ਼ਿਲ_new_syms[sym_ਸੂਚਕਾਂਕ];
                rel->r_info = ELFW(R_INFO)(sym_ਸੂਚਕਾਂਕ, type);
            }
        }
    }
}

/* In an ELF file symbol table, the local symbols must appear below
   the global and weak ones. Since TCC cannot sort it while generating
   the code, we must do it after. All the relocation tables are also
   modified to take into account the symbol table sorting */
ਸਥਿਰ ਖਾਲੀ ਛਾਂਟੋ_syms(TCCState *s1, Section *s)
{
    ਪੂਰਨ *old_ਮੰਜ਼ਿਲ_new_syms;
    ElfW(Sym) *new_syms;
    ਪੂਰਨ nb_syms, i;
    ElfW(Sym) *p, *q;

    nb_syms = s->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * ਆਕਾਰ(ElfW(Sym)));
    old_ਮੰਜ਼ਿਲ_new_syms = tcc_malloc(nb_syms * ਆਕਾਰ(ਪੂਰਨ));

    /* first pass for local symbols */
    p = (ElfW(Sym) *)s->ਅੰਕੜੇ;
    q = new_syms;
    ਲਈ(i = 0; i < nb_syms; i++) {
        ਜੇ (ELFW(ST_BIND)(p->st_info) == STB_LOCAL) {
            old_ਮੰਜ਼ਿਲ_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    /* save the number of local symbols in section header */
    ਜੇ( s->sh_ਮਾਪ )    /* this 'if' makes IDA happy */
        s->sh_info = q - new_syms;

    /* then second pass for non local symbols */
    p = (ElfW(Sym) *)s->ਅੰਕੜੇ;
    ਲਈ(i = 0; i < nb_syms; i++) {
        ਜੇ (ELFW(ST_BIND)(p->st_info) != STB_LOCAL) {
            old_ਮੰਜ਼ਿਲ_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }

    /* we copy the new symbols to the old */
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(s->ਅੰਕੜੇ, new_syms, nb_syms * ਆਕਾਰ(ElfW(Sym)));
    tcc_free(new_syms);

    update_relocs(s1, s, old_ਮੰਜ਼ਿਲ_new_syms, 0);
    tcc_free(old_ਮੰਜ਼ਿਲ_new_syms);
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
/* See: https://flapenguin.me/elf-dt-gnu-hash */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	ELFCLASS_ਬਿੱਟ (PTR_ਮਾਪ * 8)

ਸਥਿਰ Section *create_gnu_hash(TCCState *s1)
{
    ਪੂਰਨ nb_syms, i, ndef, nbuckets, symoffset, bloom_ਮਾਪ, bloom_ਖਿਸਕਾਓ;
    ElfW(Sym) *p;
    Section *gnu_hash;
    Section *dynsym = s1->dynsym;
    Elf32_ਸ਼ਬਦ *ptr;

    gnu_hash = new_section(s1, ".gnu.hash", SHT_GNU_HASH, SHF_ALLOC);
    gnu_hash->link = dynsym->hash->link;

    nb_syms = dynsym->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ(ElfW(Sym));

    /* count def symbols */
    ndef = 0;
    p = (ElfW(Sym) *)dynsym->ਅੰਕੜੇ;
    ਲਈ(i = 0; i < nb_syms; i++, p++)
        ndef += p->st_shndx != SHN_UNDEF;

    /* calculate gnu hash sizes and fill header */
    nbuckets = ndef / 4 + 1;
    symoffset = nb_syms - ndef;
    bloom_ਖਿਸਕਾਓ = PTR_ਮਾਪ == 8 ? 6 : 5;
    bloom_ਮਾਪ = 1; /* must be power of two */
    ਜਦੋਂ (ndef >= bloom_ਮਾਪ * (1 << (bloom_ਖਿਸਕਾਓ - 3)))
	bloom_ਮਾਪ *= 2;
    ptr = section_ptr_ਜੋੜੋ(gnu_hash, 4 * 4 +
				    PTR_ਮਾਪ * bloom_ਮਾਪ +
				    nbuckets * 4 +
				    ndef * 4);
    ptr[0] = nbuckets;
    ptr[1] = symoffset;
    ptr[2] = bloom_ਮਾਪ;
    ptr[3] = bloom_ਖਿਸਕਾਓ;
    ਵਾਪਸ gnu_hash;
}

ਸਥਿਰ Elf32_ਸ਼ਬਦ elf_gnu_hash (ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *name)
{
    Elf32_ਸ਼ਬਦ h = 5381;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ c;

    ਜਦੋਂ ((c = *name++))
        h = h * 33 + c;
    ਵਾਪਸ h;
}

ਸਥਿਰ ਖਾਲੀ update_gnu_hash(TCCState *s1, Section *gnu_hash)
{
    ਪੂਰਨ *old_ਮੰਜ਼ਿਲ_new_syms;
    ElfW(Sym) *new_syms;
    ਪੂਰਨ nb_syms, i, nbuckets, bloom_ਮਾਪ, bloom_ਖਿਸਕਾਓ;
    ElfW(Sym) *p, *q;
    Section *vs;
    Section *dynsym = s1->dynsym;
    Elf32_ਸ਼ਬਦ *ptr, *buckets, *chain, *hash;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *nextbuck;
    addr_t *bloom;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *strtab;
    ਬਣਤਰ { ਪੂਰਨ ਪਹਿਲਾ, ਆਖਰੀ; } *buck;

    strtab = dynsym->link->ਅੰਕੜੇ;
    nb_syms = dynsym->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * ਆਕਾਰ(ElfW(Sym)));
    old_ਮੰਜ਼ਿਲ_new_syms = tcc_malloc(nb_syms * ਆਕਾਰ(ਪੂਰਨ));
    hash = tcc_malloc(nb_syms * ਆਕਾਰ(Elf32_ਸ਼ਬਦ));
    nextbuck = tcc_malloc(nb_syms * ਆਕਾਰ(ਪੂਰਨ));

    /* calculate hashes and copy undefs */
    p = (ElfW(Sym) *)dynsym->ਅੰਕੜੇ;
    q = new_syms;
    ਲਈ(i = 0; i < nb_syms; i++, p++) {
        ਜੇ (p->st_shndx == SHN_UNDEF) {
            old_ਮੰਜ਼ਿਲ_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
	ਨਹੀਂਤਾਂ
	    hash[i] = elf_gnu_hash(strtab + p->st_name);
    }

    ptr = (Elf32_ਸ਼ਬਦ *) gnu_hash->ਅੰਕੜੇ;
    nbuckets = ptr[0];
    bloom_ਮਾਪ = ptr[2];
    bloom_ਖਿਸਕਾਓ = ptr[3];
    bloom = (addr_t *) (ਖਾਲੀ *) &ptr[4];
    buckets = (Elf32_ਸ਼ਬਦ*) (ਖਾਲੀ *) &bloom[bloom_ਮਾਪ];
    chain = &buckets[nbuckets];
    buck = tcc_malloc(nbuckets * ਆਕਾਰ(*buck));

    ਜੇ (gnu_hash->ਅੰਕੜੇ_ਵਿੱਥ != 4 * 4 +
				 PTR_ਮਾਪ * bloom_ਮਾਪ +
				 nbuckets * 4 +
				 (nb_syms - (q - new_syms)) * 4)
	tcc_error_noabort ("gnu_hash size incorrect");

    /* find buckets */
    ਲਈ(i = 0; i < nbuckets; i++)
	buck[i].ਪਹਿਲਾ = -1;

    p = (ElfW(Sym) *)dynsym->ਅੰਕੜੇ;
    ਲਈ(i = 0; i < nb_syms; i++, p++)
        ਜੇ (p->st_shndx != SHN_UNDEF) {
	    ਪੂਰਨ ਬਾਲਟੀ = hash[i] % nbuckets;

	    ਜੇ (buck[ਬਾਲਟੀ].ਪਹਿਲਾ == -1)
		buck[ਬਾਲਟੀ].ਪਹਿਲਾ = buck[ਬਾਲਟੀ].ਆਖਰੀ = i;
	    ਨਹੀਂਤਾਂ {
		nextbuck[buck[ਬਾਲਟੀ].ਆਖਰੀ] = i;
		buck[ਬਾਲਟੀ].ਆਖਰੀ = i;
	    }
	}

    /* fill buckets/chains/bloom and sort symbols */
    p = (ElfW(Sym) *)dynsym->ਅੰਕੜੇ;
    ਲਈ(i = 0; i < nbuckets; i++) {
	ਪੂਰਨ cur = buck[i].ਪਹਿਲਾ;

	ਜੇ (cur != -1) {
	    buckets[i] = q - new_syms;
	    ਲਈ (;;) {
                old_ਮੰਜ਼ਿਲ_new_syms[cur] = q - new_syms;
                *q++ = p[cur];
	        *chain++ = hash[cur] & ~1;
		bloom[(hash[cur] / ELFCLASS_ਬਿੱਟ) % bloom_ਮਾਪ] |=
		    (addr_t)1 << (hash[cur] % ELFCLASS_ਬਿੱਟ) |
		    (addr_t)1 << ((hash[cur] >> bloom_ਖਿਸਕਾਓ) % ELFCLASS_ਬਿੱਟ);
		ਜੇ (cur == buck[i].ਆਖਰੀ)
		    ਰੋਕੋ;
		cur = nextbuck[cur];
	    }
	    chain[-1] |= 1;
	}
    }

    ਸਮ੍ਰਿਤੀ_ਨਕਲ(dynsym->ਅੰਕੜੇ, new_syms, nb_syms * ਆਕਾਰ(ElfW(Sym)));
    tcc_free(new_syms);
    tcc_free(hash);
    tcc_free(buck);
    tcc_free(nextbuck);

    update_relocs(s1, dynsym, old_ਮੰਜ਼ਿਲ_new_syms, 0);

    /* modify the versions */
    vs = versym_section;
    ਜੇ (vs) {
	ElfW(Half) *newver, *versym = (ElfW(Half) *)vs->ਅੰਕੜੇ;

	ਜੇ (1/*versym*/) {
            newver = tcc_malloc(nb_syms * ਆਕਾਰ(*newver));
	    ਲਈ (i = 0; i < nb_syms; i++)
	        newver[old_ਮੰਜ਼ਿਲ_new_syms[i]] = versym[i];
	    ਸਮ੍ਰਿਤੀ_ਨਕਲ(vs->ਅੰਕੜੇ, newver, nb_syms * ਆਕਾਰ(*newver));
	    tcc_free(newver);
	}
    }

    tcc_free(old_ਮੰਜ਼ਿਲ_new_syms);

    /* rebuild hash */
    ptr = (Elf32_ਸ਼ਬਦ *) dynsym->hash->ਅੰਕੜੇ;
    rebuild_hash(dynsym, ptr[0]);
}
#ਜੇ_ਅੰਤ /* ELF_OBJ_ONLY */

/* relocate symbol table, resolve undefined symbols if do_resolve is
   true and output error if undefined symbol. */
ST_FUNC ਖਾਲੀ relocate_syms(TCCState *s1, Section *symtab, ਪੂਰਨ do_resolve)
{
    ElfW(Sym) *sym;
    ਪੂਰਨ sym_bind, sh_ਅੰਕ;
    ਅਚਲ ਅੱਖਰ *name;

    for_each_elem(symtab, 1, sym, ElfW(Sym)) {
        sh_ਅੰਕ = sym->st_shndx;
        ਜੇ (sh_ਅੰਕ == SHN_UNDEF) {
            ਜੇ (do_resolve == 2) /* relocating dynsym */
                ਜਾਰੀ;
            name = (ਅੱਖਰ *) s1->symtab->link->ਅੰਕੜੇ + sym->st_name;
            /* Use ld.so to resolve symbol for us (for tcc -run) */
            ਜੇ (do_resolve) {
#ਜੇ defined TCC_IS_NATIVE && !defined TCC_ਨਿਸ਼ਾਨਾ_PE
                /* dlsym() needs the undecorated name.  */
                ਅਚਲ ਅੱਖਰ *name_ud = &name[s1->leading_underscore];
                ਖਾਲੀ *addr = ਨਿਰਾ;
                ਜੇ (!s1->nostdlib)
                    addr = dlsym(RTLD_DEFAULT, name_ud);
		ਜੇ (addr == ਨਿਰਾ) {
		    ਪੂਰਨ i;
		    ਲਈ (i = 0; i < s1->nb_loaded_dlls; i++)
                        ਜੇ ((addr = dlsym(s1->loaded_dlls[i]->handle, name_ud)))
			    ਰੋਕੋ;
		}
                ਜੇ (addr) {
                    sym->st_ਮੁੱਲ = (addr_t) addr;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ DEBUG_RELOC
		    ਲਿਖੋ ("relocate_sym: %s -> 0x%lx\n", name, sym->st_ਮੁੱਲ);
#ਜੇ_ਅੰਤ
                    ਜਾਓ ਮਿਲਿਆ;
                }
#ਜੇ_ਅੰਤ
            /* if dynamic symbol exist, it will be used in relocate_section */
            } ਨਹੀਂਤਾਂ ਜੇ (s1->dynsym && ਲੱਭੋ_elf_sym(s1->dynsym, name))
                ਜਾਓ ਮਿਲਿਆ;
            /* XXX: _fp_hw seems to be part of the ABI, so we ignore
               it */
            ਜੇ (!strcmp(name, "_fp_hw"))
                ਜਾਓ ਮਿਲਿਆ;
            /* only weak symbols are accepted to be undefined. Their
               value is zero */
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            ਜੇ (sym_bind == STB_WEAK)
                sym->st_ਮੁੱਲ = 0;
            ਨਹੀਂਤਾਂ
                tcc_error_noabort("unresolved reference to '%s'", name);

        } ਨਹੀਂਤਾਂ ਜੇ (sh_ਅੰਕ < SHN_LORESERVE) {
            /* add section base */
            sym->st_ਮੁੱਲ += s1->sections[sym->st_shndx]->sh_addr;
        }
    ਮਿਲਿਆ: ;
    }
}

/* relocate a given section (CPU dependent) by applying the relocations
   in the associated relocation section */
ਸਥਿਰ ਖਾਲੀ relocate_section(TCCState *s1, Section *s, Section *sr)
{
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    ਪੂਰਨ type, sym_ਸੂਚਕਾਂਕ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr;
    addr_t tgt, addr;
    ਪੂਰਨ is_dwarf = s->sh_ਅੰਕ >= s1->dwlo && s->sh_ਅੰਕ < s1->dwhi;

    qrel = (ElfW_Rel *)sr->ਅੰਕੜੇ;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
	ਜੇ (s->ਅੰਕੜੇ == ਨਿਰਾ) /* bss */
	    ਜਾਰੀ;
        ptr = s->ਅੰਕੜੇ + rel->r_ਵਿੱਥ;
        sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(rel->r_info);
        sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
        type = ELFW(R_TYPE)(rel->r_info);
        tgt = sym->st_ਮੁੱਲ;
#ਜੇ SHT_RELX == SHT_RELA
        tgt += rel->r_addend;
#ਜੇ_ਅੰਤ
        ਜੇ (is_dwarf && type == R_ਅੰਕੜੇ_32_DW
            && sym->st_shndx >= s1->dwlo && sym->st_shndx < s1->dwhi) {
            /* dwarf section relocation to each other */
            add32le(ptr, tgt - s1->sections[sym->st_shndx]->sh_addr);
            ਜਾਰੀ;
        }
        addr = s->sh_addr + rel->r_ਵਿੱਥ;
        relocate(s1, rel, type, ptr, addr, tgt);
    }

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
    /* if the relocation is allocated, we change its symbol table */
    ਜੇ (sr->sh_flags & SHF_ALLOC) {
        sr->link = s1->dynsym;
        ਜੇ (s1->output_type & TCC_OUTPUT_DYN) {
            ਮਾਪ_t r = (uint8_t*)qrel - sr->ਅੰਕੜੇ;
            ਜੇ (ਆਕਾਰ ((Stab_Sym*)0)->n_ਮੁੱਲ < PTR_ਮਾਪ
                && 0 == strcmp(s->name, ".stab"))
                r = 0; /* cannot apply 64bit relocation to 32bit value */
            sr->ਅੰਕੜੇ_ਵਿੱਥ = sr->sh_ਮਾਪ = r;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_PIE
            ਜੇ (r && (s->sh_flags & SHF_EXECINSTR))
                tcc_warning("%d relocations to %s", (ਬਿਨਾਨਿਸ਼ਾਨੀ)(r / ਆਕਾਰ *qrel), s->name);
#ਜੇ_ਅੰਤ
        }
    }
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    dynarray_reset(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries);
#ਜੇ_ਅੰਤ
}

/* relocate all sections */
ST_FUNC ਖਾਲੀ relocate_sections(TCCState *s1)
{
    ਪੂਰਨ i;
    Section *s, *sr;

    ਲਈ (i = 1; i < s1->nb_sections; ++i) {
        sr = s1->sections[i];
        ਜੇ (sr->sh_type != SHT_RELX)
            ਜਾਰੀ;
        s = s1->sections[sr->sh_info];
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_MACHO
        ਜੇ (s != s1->got
            || s1->static_link
            || s1->output_type == TCC_OUTPUT_ਸਮ੍ਰਿਤੀ)
#ਜੇ_ਅੰਤ
        {
            relocate_section(s1, s, sr);
        }
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
        ਜੇ (sr->sh_flags & SHF_ALLOC) {
            ElfW_Rel *rel;
            /* relocate relocation table in 'sr' */
            for_each_elem(sr, 0, rel, ElfW_Rel)
                rel->r_ਵਿੱਥ += s->sh_addr;
        }
#ਜੇ_ਅੰਤ
    }
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
/* count the number of dynamic relocations so that we can reserve
   their space */
ਸਥਿਰ ਪੂਰਨ prepare_dynamic_rel(TCCState *s1, Section *sr)
{
    ਪੂਰਨ ਗਿਣਤੀ_3 = 0;
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_I386) || defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64) || \
    defined(TCC_ਨਿਸ਼ਾਨਾ_ARM) || defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64) || \
    defined(TCC_ਨਿਸ਼ਾਨਾ_RISCV64)
    ElfW_Rel *rel;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
        ਪੂਰਨ sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(rel->r_info);
        ਪੂਰਨ type = ELFW(R_TYPE)(rel->r_info);
        ਚੋਣ(type) {
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_I386)
        ਹਾਲਤ R_386_32:
            ਜੇ (!get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->dyn_ਸੂਚਕਾਂਕ
                && ((ElfW(Sym)*)symtab_section->ਅੰਕੜੇ + sym_ਸੂਚਕਾਂਕ)->st_shndx == SHN_UNDEF) {
                /* don't fixup unresolved (weak) symbols */
                rel->r_info = ELFW(R_INFO)(sym_ਸੂਚਕਾਂਕ, R_386_RELATIVE);
                ਰੋਕੋ;
            }
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64)
        ਹਾਲਤ R_X86_64_32:
        ਹਾਲਤ R_X86_64_32S:
        ਹਾਲਤ R_X86_64_64:
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_ARM)
        ਹਾਲਤ R_ARM_ABS32:
        ਹਾਲਤ R_ARM_TARGET1:
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64)
        ਹਾਲਤ R_AARCH64_ABS32:
        ਹਾਲਤ R_AARCH64_ABS64:
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_RISCV64)
        ਹਾਲਤ R_RISCV_32:
        ਹਾਲਤ R_RISCV_64:
#ਜੇ_ਅੰਤ
            ਗਿਣਤੀ_3++;
            ਰੋਕੋ;
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_I386)
        ਹਾਲਤ R_386_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    ਜੇ (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_ਸੂਚਕਾਂਕ, R_386_PLT32);
	        ਰੋਕੋ;
	    }
	}
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64)
        ਹਾਲਤ R_X86_64_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    ਜੇ (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_ਸੂਚਕਾਂਕ, R_X86_64_PLT32);
	        ਰੋਕੋ;
	    }
	}
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64)
        ਹਾਲਤ R_AARCH64_PREL32:
#ਜੇ_ਅੰਤ
            ਜੇ (s1->output_type != TCC_OUTPUT_DLL)
                ਰੋਕੋ;
            ਜੇ (get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->dyn_ਸੂਚਕਾਂਕ)
                ਗਿਣਤੀ_3++;
            ਰੋਕੋ;
        ਮੂਲ:
            ਰੋਕੋ;
        }
    }
#ਜੇ_ਅੰਤ
    ਵਾਪਸ ਗਿਣਤੀ_3;
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ NEED_BUILD_GOT
ਸਥਿਰ ਪੂਰਨ build_got(TCCState *s1)
{
    /* if no got, then create it */
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    s1->got->sh_entsize = 4;
    /* keep space for _DYNAMIC pointer and two dummy got entries */
    section_ptr_ਜੋੜੋ(s1->got, 3 * PTR_ਮਾਪ);
    ਵਾਪਸ ਸੈੱਟ_elf_sym(symtab_section, 0, 0, ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
        0, s1->got->sh_ਅੰਕ, "_GLOBAL_OFFSET_TABLE_");
}

/* Create a GOT and (for function call) a PLT entry corresponding to a symbol
   in s1->symtab. When creating the dynamic symbol table entry for the GOT
   relocation, use 'size' and 'info' for the corresponding symbol metadata.
   Returns the offset of the GOT or (if any) PLT entry. */
ਸਥਿਰ ਬਣਤਰ sym_attr * put_got_ਇੰਦਰਾਜ(TCCState *s1, ਪੂਰਨ dyn_reloc_type,
                                       ਪੂਰਨ sym_ਸੂਚਕਾਂਕ)
{
    ਪੂਰਨ need_plt_ਇੰਦਰਾਜ;
    ਅਚਲ ਅੱਖਰ *name;
    ElfW(Sym) *sym;
    ਬਣਤਰ sym_attr *attr;
    ਬਿਨਾਨਿਸ਼ਾਨੀ got_ਵਿੱਥ;
    ਅੱਖਰ plt_name[200];
    ਪੂਰਨ len;
    Section *s_rel;

    need_plt_ਇੰਦਰਾਜ = (dyn_reloc_type == R_JMP_ਥਾਂ);
    attr = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 1);

    /* In case a function is both called and its address taken 2 GOT entries
       are created, one for taking the address (GOT) and the other for the PLT
       entry (PLTGOT).  */
    ਜੇ (need_plt_ਇੰਦਰਾਜ ? attr->plt_ਵਿੱਥ : attr->got_ਵਿੱਥ)
        ਵਾਪਸ attr;

    s_rel = s1->got;
    ਜੇ (need_plt_ਇੰਦਰਾਜ) {
        ਜੇ (!s1->plt) {
            s1->plt = new_section(s1, ".plt", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
            s1->plt->sh_entsize = 4;
        }
        s_rel = s1->plt;
    }

    /* create the GOT entry */
    got_ਵਿੱਥ = s1->got->ਅੰਕੜੇ_ਵਿੱਥ;
    section_ptr_ਜੋੜੋ(s1->got, PTR_ਮਾਪ);

    /* Create the GOT relocation that will insert the address of the object or
       function of interest in the GOT entry. This is a static relocation for
       memory output (dlsym will give us the address of symbols) and dynamic
       relocation otherwise (executable and DLLs). The relocation should be
       done lazily for GOT entry with *_JUMP_SLOT relocation type (the one
       associated to a PLT entry) but is currently done at load time for an
       unknown reason. */

    sym = &((ElfW(Sym) *) symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
    name = (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name;
    //printf("sym %d %s\n", need_plt_entry, name);

    ਜੇ (s1->dynsym) {
	ਜੇ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
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
	    put_elf_reloc(s1->dynsym, s1->got, got_ਵਿੱਥ, R_RELATIVE,
			  sym_ਸੂਚਕਾਂਕ);
	} ਨਹੀਂਤਾਂ {
	    ਜੇ (0 == attr->dyn_ਸੂਚਕਾਂਕ)
                attr->dyn_ਸੂਚਕਾਂਕ = ਸੈੱਟ_elf_sym(s1->dynsym, sym->st_ਮੁੱਲ,
                                              sym->st_ਮਾਪ, sym->st_info, 0,
                                              sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s_rel, got_ਵਿੱਥ, dyn_reloc_type,
			  attr->dyn_ਸੂਚਕਾਂਕ);
	}
    } ਨਹੀਂਤਾਂ {
        put_elf_reloc(symtab_section, s1->got, got_ਵਿੱਥ, dyn_reloc_type,
                      sym_ਸੂਚਕਾਂਕ);
    }

    ਜੇ (need_plt_ਇੰਦਰਾਜ) {
        attr->plt_ਵਿੱਥ = create_plt_ਇੰਦਰਾਜ(s1, got_ਵਿੱਥ, attr);

        /* create a symbol 'sym@plt' for the PLT jump vector */
        len = ਲੜੀ_ਲੰਬਾਈ(name);
        ਜੇ (len > ਆਕਾਰ plt_name - 5)
            len = ਆਕਾਰ plt_name - 5;
        ਸਮ੍ਰਿਤੀ_ਨਕਲ(plt_name, name, len);
        strcpy(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_ਵਿੱਥ, 0,
            ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0, s1->plt->sh_ਅੰਕ, plt_name);
    } ਨਹੀਂਤਾਂ {
        attr->got_ਵਿੱਥ = got_ਵਿੱਥ;
    }

    ਵਾਪਸ attr;
}

/* build GOT and PLT entries */
/* Two passes because R_JMP_SLOT should become first. Some targets
   (arm, arm64) do not allow mixing R_JMP_SLOT and R_GLOB_DAT. */
ST_FUNC ਖਾਲੀ build_got_entries(TCCState *s1, ਪੂਰਨ got_sym)
{
    Section *s;
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    ਪੂਰਨ i, type, gotplt_ਇੰਦਰਾਜ, reloc_type, sym_ਸੂਚਕਾਂਕ;
    ਬਣਤਰ sym_attr *attr;
    ਪੂਰਨ pass = 0;
redo:
    ਲਈ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ਜੇ (s->sh_type != SHT_RELX)
            ਜਾਰੀ;
        /* no need to handle got relocations */
        ਜੇ (s->link != symtab_section)
            ਜਾਰੀ;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_ਇੰਦਰਾਜ = gotplt_ਇੰਦਰਾਜ_type(type);
            ਜੇ (gotplt_ਇੰਦਰਾਜ == -1) {
                tcc_error_noabort ("Unknown relocation type for got: %d", type);
                ਜਾਰੀ;
            }
            sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];

            ਜੇ (gotplt_ਇੰਦਰਾਜ == NO_GOTPLT_ਇੰਦਰਾਜ) {
                ਜਾਰੀ;
            }

            /* Automatically create PLT/GOT [entry] if it is an undefined
	       reference (resolved at runtime), or the symbol is absolute,
	       probably created by tcc_add_symbol, and thus on 64-bit
	       targets might be too far from application code.  */
            ਜੇ (gotplt_ਇੰਦਰਾਜ == AUTO_GOTPLT_ਇੰਦਰਾਜ) {
                ਜੇ (sym->st_shndx == SHN_UNDEF) {
                    ElfW(Sym) *esym;
		    ਪੂਰਨ dynindex;
                    ਜੇ (!PCRELATIVE_DLLPLT
                        && (s1->output_type & TCC_OUTPUT_DYN))
                        ਜਾਰੀ;
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
		    ਜੇ (s1->dynsym) {
			/* dynsym isn't set for -run :-/  */
			dynindex = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->dyn_ਸੂਚਕਾਂਕ;
			esym = (ElfW(Sym) *)s1->dynsym->ਅੰਕੜੇ + dynindex;
			ਜੇ (dynindex
			    && (ELFW(ST_TYPE)(esym->st_info) == STT_FUNC
				|| (ELFW(ST_TYPE)(esym->st_info) == STT_NOTYPE
				    && ELFW(ST_TYPE)(sym->st_info) == STT_FUNC)))
			    ਜਾਓ jmp_ਥਾਂ;
		    }
                } ਨਹੀਂਤਾਂ ਜੇ (sym->st_shndx == SHN_ABS) {
                    ਜੇ (sym->st_ਮੁੱਲ == 0) /* from tcc_add_btstub() */
                        ਜਾਰੀ;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
                    ਜੇ (PTR_ਮਾਪ != 8)
                        ਜਾਰੀ;
#ਜੇ_ਅੰਤ
                    /* from tcc_add_symbol(): on 64 bit platforms these
                       need to go through .got */
                } ਨਹੀਂਤਾਂ
                    ਜਾਰੀ;
            }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_I386
            ਜੇ ((type == R_386_PLT32 || type == R_386_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		ਜੇ (pass != 0)
		    ਜਾਰੀ;
                rel->r_info = ELFW(R_INFO)(sym_ਸੂਚਕਾਂਕ, R_386_PC32);
                ਜਾਰੀ;
            }
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
            ਜੇ ((type == R_X86_64_PLT32 || type == R_X86_64_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		ਜੇ (pass != 0)
		    ਜਾਰੀ;
                rel->r_info = ELFW(R_INFO)(sym_ਸੂਚਕਾਂਕ, R_X86_64_PC32);
                ਜਾਰੀ;
            }
#ਜੇ_ਅੰਤ
            reloc_type = ਕੋਡ_reloc(type);
            ਜੇ (reloc_type == -1) {
                tcc_error_noabort ("Unknown relocation type: %d", type);
                ਜਾਰੀ;
            }

            ਜੇ (reloc_type != 0) {
        jmp_ਥਾਂ:
	        ਜੇ (pass != 0)
                    ਜਾਰੀ;
                reloc_type = R_JMP_ਥਾਂ;
            } ਨਹੀਂਤਾਂ {
	        ਜੇ (pass != 1)
                    ਜਾਰੀ;
                reloc_type = R_GLOB_DAT;
            }

            ਜੇ (!s1->got)
                got_sym = build_got(s1);

            ਜੇ (gotplt_ਇੰਦਰਾਜ == BUILD_GOT_ONLY)
                ਜਾਰੀ;

            attr = put_got_ਇੰਦਰਾਜ(s1, reloc_type, sym_ਸੂਚਕਾਂਕ);

            ਜੇ (reloc_type == R_JMP_ਥਾਂ)
                rel->r_info = ELFW(R_INFO)(attr->plt_sym, type);
        }
    }
    ਜੇ (++pass < 2)
        ਜਾਓ redo;
    /* .rel.plt refers to .got actually */
    ਜੇ (s1->plt && s1->plt->reloc)
        s1->plt->reloc->sh_info = s1->got->sh_ਅੰਕ;
    ਜੇ (got_sym) /* set size */
        ((ElfW(Sym)*)symtab_section->ਅੰਕੜੇ)[got_sym].st_ਮਾਪ = s1->got->ਅੰਕੜੇ_ਵਿੱਥ;
}
#ਜੇ_ਅੰਤ /* def NEED_BUILD_GOT */

ST_FUNC ਪੂਰਨ ਸੈੱਟ_global_sym(TCCState *s1, ਅਚਲ ਅੱਖਰ *name, Section *sec, addr_t offs)
{
    ਪੂਰਨ shn = sec ? sec->sh_ਅੰਕ : offs || !name ? SHN_ABS : SHN_UNDEF;
    ਜੇ (sec && offs == -1)
        offs = sec->ਅੰਕੜੇ_ਵਿੱਥ;
    ਵਾਪਸ ਸੈੱਟ_elf_sym(symtab_section, offs, 0,
        ELFW(ST_INFO)(name ? STB_GLOBAL : STB_LOCAL, STT_NOTYPE), 0, shn, name);
}

ਸਥਿਰ ਖਾਲੀ ਜੋੜੋ_init_array_ਨਿਰਧਾਰਤ_ਕਰਦਾ(TCCState *s1, ਅਚਲ ਅੱਖਰ *section_name)
{
    Section *s;
    addr_t ਸਿਰਾ_ਵਿੱਥ;
    ਅੱਖਰ buf[1024];
    s = have_section(s1, section_name);
    ਜੇ (!s || !(s->sh_flags & SHF_ALLOC)) {
        ਸਿਰਾ_ਵਿੱਥ = 0;
        s = ਪਾਠ_section;
    } ਨਹੀਂਤਾਂ {
        ਸਿਰਾ_ਵਿੱਥ = s->ਅੰਕੜੇ_ਵਿੱਥ;
    }
    snprintf(buf, ਆਕਾਰ(buf), "__%s_start", section_name + 1);
    ਸੈੱਟ_global_sym(s1, buf, s, 0);
    snprintf(buf, ਆਕਾਰ(buf), "__%s_end", section_name + 1);
    ਸੈੱਟ_global_sym(s1, buf, s, ਸਿਰਾ_ਵਿੱਥ);
}

ST_FUNC ਖਾਲੀ ਜੋੜੋ_array (TCCState *s1, ਅਚਲ ਅੱਖਰ *sec, ਪੂਰਨ c)
{
    Section *s;
    s = ਲੱਭੋ_section(s1, sec);
    s->sh_flags = shf_RELRO;
    s->sh_type = sec[1] == 'i' ? SHT_INIT_ARRAY : SHT_FINI_ARRAY;
    put_elf_reloc (s1->symtab, s, s->ਅੰਕੜੇ_ਵਿੱਥ, R_ਅੰਕੜੇ_PTR, c);
    section_ptr_ਜੋੜੋ(s, PTR_ਮਾਪ);
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
ST_FUNC ਖਾਲੀ tcc_ਜੋੜੋ_bcheck(TCCState *s1)
{
    ਜੇ (0 == s1->do_bounds_check)
        ਵਾਪਸ;
    section_ptr_ਜੋੜੋ(bounds_section, ਆਕਾਰ(addr_t));
}
#ਜੇ_ਅੰਤ

/* set symbol to STB_LOCAL and resolve. The point is to not export it as
   a dynamic symbol to allow so's to have one each with a different value. */
ਸਥਿਰ ਖਾਲੀ ਸੈੱਟ_local_sym(TCCState *s1, ਅਚਲ ਅੱਖਰ *name, Section *s, ਪੂਰਨ ਵਿੱਥ)
{
    ਪੂਰਨ c = ਲੱਭੋ_elf_sym(s1->symtab, name);
    ਜੇ (c) {
        ElfW(Sym) *esym = (ElfW(Sym)*)s1->symtab->ਅੰਕੜੇ + c;
        esym->st_info = ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE);
        esym->st_ਮੁੱਲ = ਵਿੱਥ;
        esym->st_shndx = s->sh_ਅੰਕ;
    }
}

/* avoid generating debug/test_coverage code for stub functions */
ਸਥਿਰ ਖਾਲੀ tcc_compile_string_no_debug(TCCState *s, ਅਚਲ ਅੱਖਰ *str)
{
    ਪੂਰਨ save_do_debug = s->do_debug;
    ਪੂਰਨ save_test_coverage = s->test_coverage;

    s->do_debug = 0;
    s->test_coverage = 0;
    tcc_compile_string(s, str);
    s->do_debug = save_do_debug;
    s->test_coverage = save_test_coverage;
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
ਸਥਿਰ ਖਾਲੀ put_ptr(TCCState *s1, Section *s, ਪੂਰਨ offs)
{
    ਪੂਰਨ c;
    c = ਸੈੱਟ_global_sym(s1, ਨਿਰਾ, s, offs);
    s = ਅੰਕੜੇ_section;
    put_elf_reloc (s1->symtab, s, s->ਅੰਕੜੇ_ਵਿੱਥ, R_ਅੰਕੜੇ_PTR, c);
    section_ptr_ਜੋੜੋ(s, PTR_ਮਾਪ);
}

ST_FUNC ਖਾਲੀ tcc_ਜੋੜੋ_btstub(TCCState *s1)
{
    Section *s;
    ਪੂਰਨ n, o, *p;
    CString cstr;
    ਅਚਲ ਅੱਖਰ *__rt_info = &"___rt_info"[!s1->leading_underscore];

    s = ਅੰਕੜੇ_section;
    /* Align to PTR_SIZE */
    section_ਜੋੜੋ(s, 0, PTR_ਮਾਪ);
    o = s->ਅੰਕੜੇ_ਵਿੱਥ;
    /* create a struct rt_context (see tccrun.c) */
    ਜੇ (s1->dwarf) {
        put_ptr(s1, dwarf_ਸਤਰ_section, 0);
        put_ptr(s1, dwarf_ਸਤਰ_section, -1);
	ਜੇ (s1->dwarf >= 5)
            put_ptr(s1, dwarf_ਸਤਰ_str_section, 0);
	ਨਹੀਂਤਾਂ
            put_ptr(s1, dwarf_str_section, 0);
    }
    ਨਹੀਂਤਾਂ
    {
        put_ptr(s1, stab_section, 0);
        put_ptr(s1, stab_section, -1);
        put_ptr(s1, stab_section->link, 0);
    }

    /* skip esym_start/esym_end/elf_str (not loaded) */
    section_ptr_ਜੋੜੋ(s, 3 * PTR_ਮਾਪ);

    ਜੇ (s1->output_type == TCC_OUTPUT_ਸਮ੍ਰਿਤੀ && 0 == s1->dwarf) {
        put_ptr(s1, ਪਾਠ_section, 0);
    } ਨਹੀਂਤਾਂ {
        /* prog_base : local nameless symbol with offset 0 at SHN_ABS */
        put_ptr(s1, ਨਿਰਾ, 0);
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_MACHO
        /* adjust for __PAGEZERO */
        ਜੇ (s1->dwarf == 0 && s1->output_type == TCC_OUTPUT_EXE)
            write64le(ਅੰਕੜੇ_section->ਅੰਕੜੇ + ਅੰਕੜੇ_section->ਅੰਕੜੇ_ਵਿੱਥ - PTR_ਮਾਪ,
	              (uint64_t)1 << 32);
#ਜੇ_ਅੰਤ
    }
    n = 3 * PTR_ਮਾਪ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (s1->do_bounds_check) {
        put_ptr(s1, bounds_section, 0);
        n -= PTR_ਮਾਪ;
    }
#ਜੇ_ਅੰਤ
    section_ptr_ਜੋੜੋ(s, n);
    p = section_ptr_ਜੋੜੋ(s, 2 * ਆਕਾਰ (ਪੂਰਨ));
    p[0] = s1->rt_ਅੰਕ_callers;
    p[1] = s1->dwarf;
    // if (s->data_offset - o != 10*PTR_SIZE + 2*sizeof (int)) exit(99);

    ਜੇ (s1->output_type == TCC_OUTPUT_ਸਮ੍ਰਿਤੀ) {
        ਸੈੱਟ_global_sym(s1, __rt_info, s, o);
        ਵਾਪਸ;
    }

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern void __bt_init(),__bt_exit(),__bt_init_dll();"
        "static void *__rt_info[];"
        "__attribute__((constructor)) static void __bt_init_rt(){");
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    ਜੇ (s1->output_type == TCC_OUTPUT_DLL)
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        cstr_printf(&cstr, "__bt_init_dll(%d);", s1->do_bounds_check);
#ਨਹੀਂਤਾਂ
        cstr_printf(&cstr, "__bt_init_dll(0);");
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
    cstr_printf(&cstr, "__bt_init(__rt_info,%d);}",
        s1->output_type != TCC_OUTPUT_DLL);
    /* In case dlcose is called by application */
    cstr_printf(&cstr,
        "__attribute__((destructor)) static void __bt_exit_rt(){"
        "__bt_exit(__rt_info);}");
    tcc_compile_string_no_debug(s1, cstr.ਅੰਕੜੇ);
    cstr_free(&cstr);
    ਸੈੱਟ_local_sym(s1, __rt_info, s, o);
}
#ਜੇ_ਅੰਤ /* def CONFIG_TCC_BACKTRACE */

ਸਥਿਰ ਖਾਲੀ tcc_tcov_ਜੋੜੋ_file(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename)
{
    CString cstr;
    ਖਾਲੀ *ptr;
    ਅੱਖਰ wd[1024];

    ਜੇ (tcov_section == ਨਿਰਾ)
        ਵਾਪਸ;
    section_ptr_ਜੋੜੋ(tcov_section, 1);
    write32le (tcov_section->ਅੰਕੜੇ, tcov_section->ਅੰਕੜੇ_ਵਿੱਥ);

    cstr_new (&cstr);
    ਜੇ (filename[0] == '/')
        cstr_printf (&cstr, "%s.tcov", filename);
    ਨਹੀਂਤਾਂ {
        getcwd (wd, ਆਕਾਰ(wd));
        cstr_printf (&cstr, "%s/%s.tcov", wd, filename);
    }
    ptr = section_ptr_ਜੋੜੋ(tcov_section, cstr.ਮਾਪ + 1);
    strcpy((ਅੱਖਰ *)ptr, cstr.ਅੰਕੜੇ);
    unlink((ਅੱਖਰ *)ptr);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
    normalize_slashes((ਅੱਖਰ *)ptr);
#ਜੇ_ਅੰਤ
    cstr_free (&cstr);

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern char *__tcov_data[];"
        "extern void __store_test_coverage ();"
        "__attribute__((destructor)) static void __tcov_exit() {"
        "__store_test_coverage(__tcov_data);"
        "}");
    tcc_compile_string_no_debug(s1, cstr.ਅੰਕੜੇ);
    cstr_free(&cstr);
    ਸੈੱਟ_local_sym(s1, &"___tcov_data"[!s1->leading_underscore], tcov_section, 0);
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_UNIX
/* add libc crt1/crti objects */
ST_FUNC ਖਾਲੀ tccelf_ਜੋੜੋ_crtbegin(TCCState *s1)
{
#ਜੇ TARGETOS_OpenBSD
    ਜੇ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_ਜੋੜੋ_crt(s1, "crt0.o");
    ਜੇ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_ਜੋੜੋ_crt(s1, "crtbeginS.o");
    ਨਹੀਂਤਾਂ
        tcc_ਜੋੜੋ_crt(s1, "crtbegin.o");
#ਜਾਂਜੇ TARGETOS_FreeBSD || TARGETOS_NetBSD
    ਜੇ (s1->output_type != TCC_OUTPUT_DLL)
#ਜੇ TARGETOS_FreeBSD
        tcc_ਜੋੜੋ_crt(s1, "crt1.o");
#ਨਹੀਂਤਾਂ
        tcc_ਜੋੜੋ_crt(s1, "crt0.o");
#ਜੇ_ਅੰਤ
    tcc_ਜੋੜੋ_crt(s1, "crti.o");
    ਜੇ (s1->static_link)
        tcc_ਜੋੜੋ_crt(s1, "crtbeginT.o");
    ਨਹੀਂਤਾਂ ਜੇ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_ਜੋੜੋ_crt(s1, "crtbeginS.o");
    ਨਹੀਂਤਾਂ
        tcc_ਜੋੜੋ_crt(s1, "crtbegin.o");
#ਜਾਂਜੇ TARGETOS_ANDROID
    ਜੇ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_ਜੋੜੋ_crt(s1, "crtbegin_so.o");
    ਨਹੀਂਤਾਂ
        tcc_ਜੋੜੋ_crt(s1, "crtbegin_dynamic.o");
#ਨਹੀਂਤਾਂ
    ਜੇ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_ਜੋੜੋ_crt(s1, "crt1.o");
    tcc_ਜੋੜੋ_crt(s1, "crti.o");
#ਜੇ_ਅੰਤ
}

ST_FUNC ਖਾਲੀ tccelf_ਜੋੜੋ_crtend(TCCState *s1)
{
#ਜੇ TARGETOS_OpenBSD
    ਜੇ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_ਜੋੜੋ_crt(s1, "crtendS.o");
    ਨਹੀਂਤਾਂ
        tcc_ਜੋੜੋ_crt(s1, "crtend.o");
#ਜਾਂਜੇ TARGETOS_FreeBSD || TARGETOS_NetBSD
    ਜੇ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_ਜੋੜੋ_crt(s1, "crtendS.o");
    ਨਹੀਂਤਾਂ
        tcc_ਜੋੜੋ_crt(s1, "crtend.o");
    tcc_ਜੋੜੋ_crt(s1, "crtn.o");
#ਜਾਂਜੇ TARGETOS_ANDROID
    ਜੇ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_ਜੋੜੋ_crt(s1, "crtend_so.o");
    ਨਹੀਂਤਾਂ
        tcc_ਜੋੜੋ_crt(s1, "crtend_android.o");
#ਨਹੀਂਤਾਂ
    tcc_ਜੋੜੋ_crt(s1, "crtn.o");
#ਜੇ_ਅੰਤ
}
#ਜੇ_ਅੰਤ /* TCC_TARGET_UNIX */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
/* add tcc runtime libraries */
ST_FUNC ਖਾਲੀ tcc_ਜੋੜੋ_runtime(TCCState *s1)
{
    s1->filetype = 0;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    tcc_ਜੋੜੋ_bcheck(s1);
#ਜੇ_ਅੰਤ
    tcc_ਜੋੜੋ_pragma_libs(s1);

    /* add libc */
    ਜੇ (!s1->nostdlib) {
        ਪੂਰਨ lpthread = s1->option_pthread;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    ਜੇ (s1->output_type == TCC_OUTPUT_ਸਮ੍ਰਿਤੀ)
                tcc_ਜੋੜੋ_support(s1, "bcheck_run.o");
	    ਨਹੀਂਤਾਂ
                tcc_ਜੋੜੋ_support(s1, "bcheck.o");
# ਜੇ !(TARGETOS_OpenBSD || TARGETOS_NetBSD)
            tcc_ਜੋੜੋ_library(s1, "dl");
# endif
            lpthread = 1;
        }
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
        ਜੇ (s1->do_backtrace) {
            ਜੇ (s1->output_type & TCC_OUTPUT_EXE)
                tcc_ਜੋੜੋ_support(s1, "bt-exe.o");
            ਜੇ (s1->output_type != TCC_OUTPUT_DLL)
                tcc_ਜੋੜੋ_support(s1, "bt-log.o");
            tcc_ਜੋੜੋ_btstub(s1);
            lpthread = 1;
        }
#ਜੇ_ਅੰਤ
        ਜੇ (lpthread)
            tcc_ਜੋੜੋ_library(s1, "pthread");
        tcc_ਜੋੜੋ_library(s1, "c");
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_LIBGCC
        ਜੇ (!s1->static_link) {
            ਜੇ (TCC_LIBGCC[0] == '/')
                tcc_ਜੋੜੋ_file(s1, TCC_LIBGCC);
            ਨਹੀਂਤਾਂ
                tcc_ਜੋੜੋ_dll(s1, TCC_LIBGCC, AFF_PRINT_ERROR);
        }
#ਜੇ_ਅੰਤ
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM && TARGETOS_FreeBSD
        tcc_ਜੋੜੋ_library(s1, "gcc_s"); // unwind code
#ਜੇ_ਅੰਤ
        ਜੇ (TCC_LIBTCC1[0]) {
            tcc_ਜੋੜੋ_support(s1, TCC_LIBTCC1);
            tcc_ਜੋੜੋ_library(s1, "c");
        }
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_MACHO
        ਜੇ (s1->output_type != TCC_OUTPUT_ਸਮ੍ਰਿਤੀ)
            tccelf_ਜੋੜੋ_crtend(s1);
#ਜੇ_ਅੰਤ
    }
}
#ਜੇ_ਅੰਤ /* ndef TCC_TARGET_PE */

/* set _etext/_edata/_end  f=0:set  f=1:when_needed  f=2,3:just_update */
ਸਥਿਰ ਖਾਲੀ ਸੈੱਟ_linker_sym(TCCState *s1, ਅਚਲ ਅੱਖਰ *name, Section *sec, ਪੂਰਨ f)
{
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ, esym_ਸੂਚਕਾਂਕ, defined;
    ElfW(Sym) *sym, *esym;
    sym_ਸੂਚਕਾਂਕ = ਲੱਭੋ_elf_sym(symtab_section, name);
    sym = (ElfW(Sym) *)symtab_section->ਅੰਕੜੇ + sym_ਸੂਚਕਾਂਕ;
    esym_ਸੂਚਕਾਂਕ = ਲੱਭੋ_elf_sym(s1->dynsymtab_section, name);
    esym = (ElfW(Sym) *)s1->dynsymtab_section->ਅੰਕੜੇ + esym_ਸੂਚਕਾਂਕ;
    defined = sym->st_shndx != SHN_UNDEF
        || (esym->st_shndx != SHN_UNDEF && esym->st_ਮਾਪ);
    ਚੋਣ (f) {
    ਹਾਲਤ 1: /* old symbols w/o '_' */
        ਜੇ (!(sym_ਸੂਚਕਾਂਕ || esym_ਸੂਚਕਾਂਕ) || defined)
            ਰੋਕੋ;
    ਹਾਲਤ 0:
        ਜੇ (defined) {
            tcc_warning("linker symbol '%s' already defined", name);
            ਰੋਕੋ;
        }
        sym_ਸੂਚਕਾਂਕ = ਸੈੱਟ_global_sym(s1, name, sec, -1);
        get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 1)->linker_sym = 1;
        ਰੋਕੋ;
    ਮੂਲ: /* update (bss only) */
        ਜੇ (get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->linker_sym)
            sym->st_ਮੁੱਲ = sec->ਅੰਕੜੇ_ਵਿੱਥ;
    }
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
    ਜੇ (name[0] == '_')
        ਸੈੱਟ_linker_sym(s1, name + 1, sec, f + 1);
#ਜੇ_ਅੰਤ
}

/* add various standard linker symbols (must be done after the
   sections are filled (for example after allocating common
   symbols)) */
ਸਥਿਰ ਖਾਲੀ tcc_ਜੋੜੋ_linker_symbols(TCCState *s1)
{
    ਅੱਖਰ buf[1024];
    ਪੂਰਨ i;
    Section *s;

    ਸੈੱਟ_linker_sym(s1, "_etext", ਪਾਠ_section, 0);
    ਸੈੱਟ_linker_sym(s1, "_edata", ਅੰਕੜੇ_section, 0);
    ਸੈੱਟ_linker_sym(s1, "_end", bss_section, 0);
#ਜੇ TARGETOS_OpenBSD
    ਸੈੱਟ_global_sym(s1, "__executable_start", ਨਿਰਾ, ELF_ਸ਼ੁਰੂ_ADDR);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    /* XXX should be .sdata+0x800, not .data+0x800 */
    ਸੈੱਟ_global_sym(s1, "__global_pointer$", ਅੰਕੜੇ_section, 0x800);
#ਜੇ_ਅੰਤ
    /* horrible new standard ldscript defines */
    ਜੋੜੋ_init_array_ਨਿਰਧਾਰਤ_ਕਰਦਾ(s1, ".preinit_array");
    ਜੋੜੋ_init_array_ਨਿਰਧਾਰਤ_ਕਰਦਾ(s1, ".init_array");
    ਜੋੜੋ_init_array_ਨਿਰਧਾਰਤ_ਕਰਦਾ(s1, ".fini_array");
    /* add start and stop symbols for sections whose name can be
       expressed in C */
    ਲਈ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ਜੇ ((s->sh_flags & SHF_ALLOC)
            && (s->sh_type == SHT_PROGBITS || s->sh_type == SHT_NOBITS
                || s->sh_type == SHT_STRTAB)) {
            /* check if section name can be expressed in C */
            ਅਚਲ ਅੱਖਰ *p0, *p;
            p0 = s->name;
            ਜੇ (*p0 == '.')
                ++p0;
            p = p0;
            ਲਈ(;;) {
                ਪੂਰਨ c = *p;
                ਜੇ (!c)
                    ਰੋਕੋ;
                ਜੇ (!isid(c) && !isnum(c))
                    ਜਾਓ ਅਗਲਾ_sec;
                p++;
            }
            snprintf(buf, ਆਕਾਰ(buf), "__start_%s", p0);
            ਸੈੱਟ_global_sym(s1, buf, s, 0);
            snprintf(buf, ਆਕਾਰ(buf), "__stop_%s", p0);
            ਸੈੱਟ_global_sym(s1, buf, s, -1);
        }
    ਅਗਲਾ_sec: ;
    }
}

ST_FUNC ਖਾਲੀ resolve_common_syms(TCCState *s1)
{
    ElfW(Sym) *sym;

    /* Allocate common symbols in BSS.  */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ਜੇ (sym->st_shndx == SHN_COMMON && sym->st_ਮਾਪ) {
            /* symbol alignment is in st_value for SHN_COMMONs */
	    sym->st_ਮੁੱਲ = section_ਜੋੜੋ(bss_section, sym->st_ਮਾਪ,
					sym->st_ਮੁੱਲ);
            sym->st_shndx = bss_section->sh_ਅੰਕ;
        }
    }

    /* Now assign linker provided symbols their value.  */
    ਜੇ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_ਜੋੜੋ_linker_symbols(s1);
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
ST_FUNC ਖਾਲੀ fill_got_ਇੰਦਰਾਜ(TCCState *s1, ElfW_Rel *rel)
{
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM) (rel->r_info);
    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
    ਬਣਤਰ sym_attr *attr = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0);
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਵਿੱਥ = attr->got_ਵਿੱਥ;

    ਜੇ (0 == ਵਿੱਥ)
        ਵਾਪਸ;
    section_reserve(s1->got, ਵਿੱਥ + PTR_ਮਾਪ);
#ਜੇ PTR_ਮਾਪ == 8
    write64le(s1->got->ਅੰਕੜੇ + ਵਿੱਥ, sym->st_ਮੁੱਲ);
#ਨਹੀਂਤਾਂ
    write32le(s1->got->ਅੰਕੜੇ + ਵਿੱਥ, sym->st_ਮੁੱਲ);
#ਜੇ_ਅੰਤ
}

/* Perform relocation to GOT or PLT entries */
ST_FUNC ਖਾਲੀ fill_got(TCCState *s1)
{
    Section *s;
    ElfW_Rel *rel;
    ਪੂਰਨ i;

    ਲਈ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ਜੇ (s->sh_type != SHT_RELX)
            ਜਾਰੀ;
        /* no need to handle got relocations */
        ਜੇ (s->link != symtab_section)
            ਜਾਰੀ;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            ਚੋਣ (ELFW(R_TYPE) (rel->r_info)) {
                ਹਾਲਤ R_X86_64_GOT32:
                ਹਾਲਤ R_X86_64_GOTPCREL:
		ਹਾਲਤ R_X86_64_GOTPCRELX:
		ਹਾਲਤ R_X86_64_REX_GOTPCRELX:
                ਹਾਲਤ R_X86_64_PLT32:
                    fill_got_ਇੰਦਰਾਜ(s1, rel);
                    ਰੋਕੋ;
            }
        }
    }
}

/* See put_got_entry for a description.  This is the second stage
   where GOT references to local defined symbols are rewritten.  */
ਸਥਿਰ ਖਾਲੀ fill_local_got_entries(TCCState *s1)
{
    ElfW_Rel *rel;
    ਜੇ (!s1->got->reloc)
        ਵਾਪਸ;
    for_each_elem(s1->got->reloc, 0, rel, ElfW_Rel) {
	ਜੇ (ELFW(R_TYPE)(rel->r_info) == R_RELATIVE) {
	    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM) (rel->r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
	    ਬਣਤਰ sym_attr *attr = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0);
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਵਿੱਥ = attr->got_ਵਿੱਥ;
	    ਜੇ (ਵਿੱਥ != rel->r_ਵਿੱਥ - s1->got->sh_addr)
	        tcc_error_noabort("fill_local_got_entries: huh?");
	    rel->r_info = ELFW(R_INFO)(0, R_RELATIVE);
#ਜੇ SHT_RELX == SHT_RELA
	    rel->r_addend = sym->st_ਮੁੱਲ;
#ਨਹੀਂਤਾਂ
	    /* All our REL architectures also happen to be 32bit LE.  */
	    write32le(s1->got->ਅੰਕੜੇ + ਵਿੱਥ, sym->st_ਮੁੱਲ);
#ਜੇ_ਅੰਤ
	}
    }
}

/* Bind symbols of executable: resolve undefined symbols from exported symbols
   in shared libraries */
ਸਥਿਰ ਖਾਲੀ bind_exe_dynsyms(TCCState *s1, ਪੂਰਨ is_PIE)
{
    ਅਚਲ ਅੱਖਰ *name;
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ, ਸੂਚਕਾਂਕ;
    ElfW(Sym) *sym, *esym;
    ਪੂਰਨ type;

    /* Resolve undefined symbols from dynamic symbols. When there is a match:
       - if STT_FUNC or STT_GNU_IFUNC symbol -> add it in PLT
       - if STT_OBJECT symbol -> add it in .bss section with suitable reloc */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ਜੇ (sym->st_shndx == SHN_UNDEF
            /* bss symbols may be initialized in the shared library */
            || sym->st_shndx == SHN_COMMON
            || sym->st_shndx == bss_section->sh_ਅੰਕ) {
            name = (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name;
            sym_ਸੂਚਕਾਂਕ = ਲੱਭੋ_elf_sym(s1->dynsymtab_section, name);
            esym = &((ElfW(Sym) *)s1->dynsymtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
            ਜੇ (sym_ਸੂਚਕਾਂਕ && esym->st_shndx != SHN_UNDEF) {
                ਜੇ (is_PIE)
                    ਜਾਰੀ;
                type = ELFW(ST_TYPE)(esym->st_info);
                ਜੇ ((type == STT_FUNC) || (type == STT_GNU_IFUNC)) {
                    /* Indirect functions shall have STT_FUNC type in executable
                     * dynsym section. Indeed, a dlsym call following a lazy
                     * resolution would pick the symbol value from the
                     * executable dynsym entry which would contain the address
                     * of the function wanted by the caller of dlsym instead of
                     * the address of the function that would return that
                     * address */
                    ਪੂਰਨ dynindex
		      = put_elf_sym(s1->dynsym, 0, esym->st_ਮਾਪ,
				    ELFW(ST_INFO)(STB_GLOBAL,STT_FUNC), 0, 0,
				    name);
		    ਪੂਰਨ ਸੂਚਕਾਂਕ = sym - (ElfW(Sym) *) symtab_section->ਅੰਕੜੇ;
		    get_sym_attr(s1, ਸੂਚਕਾਂਕ, 1)->dyn_ਸੂਚਕਾਂਕ = dynindex;
                } ਨਹੀਂਤਾਂ ਜੇ (type == STT_OBJECT) {
                    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ;
                    ElfW(Sym) *dynsym;
                    ਜੇ (sym->st_shndx == bss_section->sh_ਅੰਕ) {
                        ਵਿੱਥ = sym->st_ਮੁੱਲ;
                    } ਨਹੀਂਤਾਂ {
                        ਵਿੱਥ = bss_section->ਅੰਕੜੇ_ਵਿੱਥ;
                        /* XXX: which alignment ? */
                        ਵਿੱਥ = (ਵਿੱਥ + 16 - 1) & -16;
                        bss_section->ਅੰਕੜੇ_ਵਿੱਥ = ਵਿੱਥ + esym->st_ਮਾਪ;
                    }
                    ਸੈੱਟ_elf_sym (s1->symtab, ਵਿੱਥ, esym->st_ਮਾਪ,
                                 esym->st_info, 0, bss_section->sh_ਅੰਕ, name);
                    ਸੂਚਕਾਂਕ = put_elf_sym(s1->dynsym, ਵਿੱਥ, esym->st_ਮਾਪ,
                                        esym->st_info, 0, bss_section->sh_ਅੰਕ,
                                        name);
                    /* Ensure R_COPY works for weak symbol aliases */
                    ਜੇ (ELFW(ST_BIND)(esym->st_info) == STB_WEAK) {
                        for_each_elem(s1->dynsymtab_section, 1, dynsym, ElfW(Sym)) {
                            ਜੇ ((dynsym->st_ਮੁੱਲ == esym->st_ਮੁੱਲ)
                                && (ELFW(ST_BIND)(dynsym->st_info) == STB_GLOBAL)) {
                                ਅੱਖਰ *dynname = (ਅੱਖਰ *) s1->dynsymtab_section->link->ਅੰਕੜੇ
                                                + dynsym->st_name;
                                put_elf_sym(s1->dynsym, ਵਿੱਥ, dynsym->st_ਮਾਪ,
                                            dynsym->st_info, 0,
                                            bss_section->sh_ਅੰਕ, dynname);
                                ਰੋਕੋ;
                            }
                        }
                    }
                    put_elf_reloc(s1->dynsym, bss_section,
                                  ਵਿੱਥ, R_COPY, ਸੂਚਕਾਂਕ);
                }
            } ਨਹੀਂਤਾਂ ਜੇ (sym->st_shndx == SHN_UNDEF) {
                /* STB_WEAK undefined symbols are accepted */
                /* XXX: _fp_hw seems to be part of the ABI, so we ignore it */
                ਜੇ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK ||
                    !strcmp(name, "_fp_hw")) {
                } ਨਹੀਂਤਾਂ {
                    tcc_error_noabort("unresolved reference to '%s'", name);
                }
            }
        }
    }
    /* update _end symbol with new bss length */
    ਸੈੱਟ_linker_sym(s1, "_end", bss_section, 2);
}

/* Bind symbols of libraries: export all non local symbols of executable that
   are referenced by shared libraries. The reason is that the dynamic loader
   search symbol first in executable and then in libraries. Therefore a
   reference to a symbol already defined by a library can still be resolved by
   a symbol in the executable.   With -rdynamic, export all defined symbols */
ਸਥਿਰ ਖਾਲੀ bind_libs_dynsyms(TCCState *s1)
{
    ਅਚਲ ਅੱਖਰ *name;
    ਪੂਰਨ dynsym_ਸੂਚਕਾਂਕ;
    ElfW(Sym) *sym, *esym;

    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        name = (ਅੱਖਰ *)symtab_section->link->ਅੰਕੜੇ + sym->st_name;
        dynsym_ਸੂਚਕਾਂਕ = ਲੱਭੋ_elf_sym(s1->dynsymtab_section, name);
        ਜੇ (sym->st_shndx != SHN_UNDEF) {
            ਜੇ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL
                && (dynsym_ਸੂਚਕਾਂਕ || s1->rdynamic))
                ਸੈੱਟ_elf_sym(s1->dynsym, sym->st_ਮੁੱਲ, sym->st_ਮਾਪ,
                            sym->st_info, 0, sym->st_shndx, name);
        } ਨਹੀਂਤਾਂ ਜੇ (dynsym_ਸੂਚਕਾਂਕ) {
            esym = (ElfW(Sym) *)s1->dynsymtab_section->ਅੰਕੜੇ + dynsym_ਸੂਚਕਾਂਕ;
            ਜੇ (esym->st_shndx == SHN_UNDEF) {
                /* weak symbols can stay undefined */
                ਜੇ (ELFW(ST_BIND)(esym->st_info) != STB_WEAK)
                    tcc_warning("unresolved dynamic reference to '%s'", name);
            }
        }
    }
}

/* Export all non local symbols. This is used by shared libraries so that the
   non local symbols they define can resolve a reference in another shared
   library or in the executable. Correspondingly, it allows undefined local
   symbols to be resolved by other shared libraries or by the executable. */
ਸਥਿਰ ਖਾਲੀ export_global_syms(TCCState *s1)
{
    ਪੂਰਨ dynindex, ਸੂਚਕਾਂਕ;
    ਅਚਲ ਅੱਖਰ *name;
    ElfW(Sym) *sym;
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ਜੇ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
	    name = (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name;
	    dynindex = ਸੈੱਟ_elf_sym(s1->dynsym, sym->st_ਮੁੱਲ, sym->st_ਮਾਪ,
				   sym->st_info, 0, sym->st_shndx, name);
	    ਸੂਚਕਾਂਕ = sym - (ElfW(Sym) *) symtab_section->ਅੰਕੜੇ;
            get_sym_attr(s1, ਸੂਚਕਾਂਕ, 1)->dyn_ਸੂਚਕਾਂਕ = dynindex;
        }
    }
}

/* decide if an unallocated section should be output. */
ਸਥਿਰ ਪੂਰਨ ਸੈੱਟ_sec_sizes(TCCState *s1)
{
    ਪੂਰਨ i;
    Section *s;
    ਪੂਰਨ textrel = 0;
    ਪੂਰਨ file_type = s1->output_type;

    /* Allocate strings for section names */
    ਲਈ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ਜੇ (s->sh_type == SHT_RELX && !(s->sh_flags & SHF_ALLOC)) {
            /* when generating a DLL, we include relocations but
               we may patch them */
            ਜੇ ((file_type & TCC_OUTPUT_DYN)
                && (s1->sections[s->sh_info]->sh_flags & SHF_ALLOC)) {
                ਪੂਰਨ ਗਿਣਤੀ_3 = prepare_dynamic_rel(s1, s);
                ਜੇ (ਗਿਣਤੀ_3) {
                    /* allocate the section */
                    s->sh_flags |= SHF_ALLOC;
                    s->sh_ਮਾਪ = ਗਿਣਤੀ_3 * ਆਕਾਰ(ElfW_Rel);
                    ਜੇ (s1->sections[s->sh_info]->sh_flags & SHF_EXECINSTR)
                        textrel += ਗਿਣਤੀ_3;
                }
            }
        } ਨਹੀਂਤਾਂ ਜੇ ((s->sh_flags & SHF_ALLOC)
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
                   || s->sh_type == SHT_ARM_ਗੁਣ
#ਜੇ_ਅੰਤ
                   || s1->do_debug) {
            s->sh_ਮਾਪ = s->ਅੰਕੜੇ_ਵਿੱਥ;
        }
    }
    ਵਾਪਸ textrel;
}

/* various data used under elf_output_file() */
ਬਣਤਰ dyn_inf {
    Section *dynamic;
    Section *dynstr;
    Section *interp;
    Section *note;
    Section *gnu_hash;
    ਬਣਤਰ {
        /* Info to be copied in dynamic section */
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਅੰਕੜੇ_ਵਿੱਥ;
        addr_t rel_addr;
        addr_t rel_ਮਾਪ;
    };

    ElfW(Phdr) *phdr;
    ਪੂਰਨ phnum;
    ਪੂਰਨ shnum;
    ਪੂਰਨ tls;
    ਪੂਰਨ relro;
    ਪੂਰਨ notes;
    ਪੂਰਨ ehfr;
    ਪੂਰਨ dyna;
};

/* Decide the layout of sections loaded in memory. This must be done before
   program headers are filled since they contain info about the layout.
   We do the following ordering: interp, symbol tables, relocations, progbits,
   nobits */
ਸਥਿਰ ਪੂਰਨ ਛਾਂਟੋ_sections(TCCState *s1, ਪੂਰਨ *sec_ਕ੍ਰਮ, ਬਣਤਰ dyn_inf *d)
{
    Section *s;
    ਪੂਰਨ i, j, k, f, f0, n;
    ਪੂਰਨ nb_sections = s1->nb_sections;
    ਪੂਰਨ *sec_cls = sec_ਕ੍ਰਮ + nb_sections;
    ਪੂਰਨ tls_align = 0; /* need common alignment for all tls sections */

    ਲਈ (i = 1; i < nb_sections; i++) {
        s = s1->sections[i];
        ਜੇ (0 == s->sh_name) {
            j = 0x900; /* no sh_name: won't go to file */
        } ਨਹੀਂਤਾਂ ਜੇ (s->sh_flags & SHF_ALLOC) {
            j = 0x100;
            ਜੇ ((s->sh_flags & (SHF_WRITE|SHF_TLS)) == SHF_WRITE)
                j = 0x200;
        } ਨਹੀਂਤਾਂ {
            j = 0x700;
        }
        ਜੇ (j >= 0x700 && s1->output_format != TCC_OUTPUT_FORMAT_ELF)
            s->sh_ਮਾਪ = 0, j = 0x900;

        ਜੇ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM) {
            k = 0x10;
        } ਨਹੀਂਤਾਂ ਜੇ (s->sh_type == SHT_STRTAB && strcmp(s->name, ".stabstr")) {
            k = 0x11;
            ਜੇ (i == nb_sections - 1) /* ".shstrtab" assumed to stay last */
                k = 0xff;
        } ਨਹੀਂਤਾਂ ਜੇ (s->sh_type == SHT_HASH || s->sh_type == SHT_GNU_HASH) {
            k = 0x12;
        } ਨਹੀਂਤਾਂ ਜੇ (s->sh_type == SHT_GNU_verdef
                  || s->sh_type == SHT_GNU_verneed
                  || s->sh_type == SHT_GNU_versym) {
            k = 0x13;
        } ਨਹੀਂਤਾਂ ਜੇ (s->sh_type == SHT_RELX) {
            k = 0x20;
            ਜੇ (s1->plt && s == s1->plt->reloc)
                k = 0x21;
        } ਨਹੀਂਤਾਂ ਜੇ (s->sh_flags & SHF_EXECINSTR) {
            k = 0x60;
        /* RELRO sections --> */
        } ਨਹੀਂਤਾਂ ਜੇ (s->sh_flags & SHF_TLS) {
            ਜੇ (s->sh_addralign > tls_align)
                tls_align = s->sh_addralign;
            k = 0x40 + (s->sh_type == SHT_NOBITS);
        } ਨਹੀਂਤਾਂ ਜੇ (s->sh_type == SHT_PREINIT_ARRAY) {
            k = 0x42;
        } ਨਹੀਂਤਾਂ ਜੇ (s->sh_type == SHT_INIT_ARRAY) {
            k = 0x43;
        } ਨਹੀਂਤਾਂ ਜੇ (s->sh_type == SHT_FINI_ARRAY) {
            k = 0x44;
        } ਨਹੀਂਤਾਂ ਜੇ (s->sh_type == SHT_DYNAMIC) {
            k = 0x48;
        } ਨਹੀਂਤਾਂ ਜੇ (s == s1->got) {
            k = 0x49; /* .got as RELRO needs BIND_NOW in DT_FLAGS */
        } ਨਹੀਂਤਾਂ ਜੇ (s->reloc && (s->reloc->sh_flags & SHF_ALLOC) && j == 0x100) {
            k = 0x45; /* +1 for data.ro */
        /* <-- */
        } ਨਹੀਂਤਾਂ ਜੇ (s->sh_type == SHT_NOTE) {
            k = 0x08, d->notes = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (s->sh_type == SHT_NOBITS) {
            k = 0x70; /* bss */
        } ਨਹੀਂਤਾਂ ਜੇ (s == d->interp) {
            k = 0x00;
        } ਨਹੀਂਤਾਂ {
            k = 0x50; /*ਅੰਕੜੇ*/
        }
        k += j;
        /* make our standard sections come last to have _etext/_edata correct values */
        ਜੇ (s->sh_ਅੰਕ <= bss_section->sh_ਅੰਕ)
            ++k;
        /* make RELRO section writable */
        ਜੇ ((k & 0xfff0) == 0x140)
            k += 0x100, s->sh_flags |= SHF_WRITE;
        /* sort by insert */
        ਲਈ (n = i; n > 1 && k < (f = sec_cls[n - 1]); --n)
            sec_cls[n] = f, sec_ਕ੍ਰਮ[n] = sec_ਕ੍ਰਮ[n - 1];
        sec_cls[n] = k, sec_ਕ੍ਰਮ[n] = i;
    }
    sec_ਕ੍ਰਮ[0] = 0;
    d->shnum = 1;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHFX_NEWPH (1 << 4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHFX_RELRO (1 << 5)

    /* count PT_LOAD headers needed */
    n = f0 = 0;
    ਲਈ (i = 1; i < nb_sections; i++) {
        s = s1->sections[sec_ਕ੍ਰਮ[i]];
        k = sec_cls[i];
        f = 0;
        ਜੇ (k < 0x900)
            ++d->shnum;
        ਜੇ (k < 0x700) {
            f = s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR);
#ਜੇ TARGETOS_NetBSD || TARGETOS_FreeBSD
	    /* NetBSD only supports 2 PT_LOAD sections.
	       See: https://blog.netbsd.org/tnf/entry/the_first_report_on_lld */
	    ਜੇ ((f & SHF_WRITE) == 0)
                f |= SHF_EXECINSTR;
            k = 0; /* no relro */
#ਜੇ_ਅੰਤ
            ਜੇ ((k & 0xfff0) == 0x240) /* RELRO sections */
                d->relro = 1, f |= SHFX_RELRO;
            /* start new header when flags changed, but avoid zero memsz */
            ਜੇ (f != f0 && s->sh_ਮਾਪ)
                f0 = f, ++n, f |= SHFX_NEWPH;
            ਜੇ ((s->sh_flags & SHF_TLS) && s->sh_ਮਾਪ) {
                s->sh_addralign = tls_align;
                d->tls = 1, f |= SHF_TLS;
            }
        }
        sec_cls[i] = f;
        //printf("ph %d sec %02d : %3X %3X  %8.2X  %04X  %s\n", (f>0) * n, i, f, k, s->sh_type, (int)s->sh_size, s->name);
    }
    ਵਾਪਸ n;
}

ਸਥਿਰ ElfW(Phdr) *fill_phdr(ElfW(Phdr) *ph, ਪੂਰਨ type, Section *s)
{
    ph->p_type = type;
    ph->p_flags = PF_R;
    ਜੇ (s) {
        ਜੇ (s->sh_flags & SHF_WRITE)
            ph->p_flags |= PF_W;
        ph->p_ਵਿੱਥ = s->sh_ਵਿੱਥ;
        ph->p_vaddr = s->sh_addr;
        ph->p_filesz = s->sh_ਮਾਪ;
        ph->p_align = s->sh_addralign;
    }
    ph->p_paddr = ph->p_vaddr;
    ph->p_memsz = ph->p_filesz;
    ਵਾਪਸ ph;
}

ਸਥਿਰ ElfW(Phdr) *update_phdr(ElfW(Phdr) *ph, ਪੂਰਨ type, Section *s, addr_t addr, ਪੂਰਨ file_ਵਿੱਥ)
{
    ਜੇ (ph->p_type == 0) {
        fill_phdr(ph, type, s);
    }
    ph->p_filesz = file_ਵਿੱਥ - ph->p_ਵਿੱਥ;
    ph->p_memsz = addr - ph->p_vaddr;
    ਵਾਪਸ ph;
}

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
ਸਥਿਰ ਪੂਰਨ layout_sections(TCCState *s1, ਪੂਰਨ *sec_ਕ੍ਰਮ, ਬਣਤਰ dyn_inf *d)
{
    Section *s;
    addr_t addr, tmp, align, s_align, ਅਧਾਰ;
    ElfW(Phdr) *ph = ਨਿਰਾ, *ph2;
    ਪੂਰਨ i, f, n, phnum, phfill;
    ਪੂਰਨ file_ਵਿੱਥ;

    /* compute number of program headers */
    phnum = ਛਾਂਟੋ_sections(s1, sec_ਕ੍ਰਮ, d);
    phfill = 0; /* set to 1 to have dll's with a PT_PHDR */
    ਜੇ (d->interp)
        phfill = 2;
    phnum += phfill;
    ਜੇ (d->dynamic)
        d->dyna = phnum++;
    ਜੇ (d->notes)
        d->notes = phnum++;
    ਜੇ (d->tls)
        d->tls = phnum++;
    ਜੇ (eh_ਚੌਖਟਾ_hdr_section)
        d->ehfr = phnum++;
    ਜੇ (d->relro)
        d->relro = phnum++;
    d->phnum = phnum;
    d->phdr = tcc_mallocz(phnum * ਆਕਾਰ(ElfW(Phdr)));

    file_ਵਿੱਥ = 0;
    ਜੇ (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
        file_ਵਿੱਥ = (ਆਕਾਰ(ElfW(Ehdr)) + phnum * ਆਕਾਰ(ElfW(Phdr)) + 3) & -4;
        file_ਵਿੱਥ += d->shnum * ਆਕਾਰ (ElfW(Shdr));
    }

    s_align = ELF_ਪੰਨਾ_ਮਾਪ;
    ਜੇ (s1->section_align)
        s_align = s1->section_align;

    addr = ELF_ਸ਼ੁਰੂ_ADDR;
    ਜੇ (s1->output_type & TCC_OUTPUT_DYN)
        addr = 0;

    ਜੇ (s1->has_ਪਾਠ_addr) {
        addr = s1->ਪਾਠ_addr;
        ਜੇ (0) {
            ਪੂਰਨ a_ਵਿੱਥ, p_ਵਿੱਥ;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_ਵਿੱਥ = (ਪੂਰਨ) (addr & (s_align - 1));
            p_ਵਿੱਥ = file_ਵਿੱਥ & (s_align - 1);
            ਜੇ (a_ਵਿੱਥ < p_ਵਿੱਥ)
                a_ਵਿੱਥ += s_align;
            file_ਵਿੱਥ += (a_ਵਿੱਥ - p_ਵਿੱਥ);
        }
    }
    ਅਧਾਰ = addr;
    /* compute address after headers */
    addr += file_ਵਿੱਥ;

    n = 0;
    ਲਈ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_ਕ੍ਰਮ[i]];
        f = sec_ਕ੍ਰਮ[i + s1->nb_sections];
        align = s->sh_addralign - 1;

        ਜੇ (f == 0) { /* no alloc */
            file_ਵਿੱਥ = (file_ਵਿੱਥ + align) & ~align;
            s->sh_ਵਿੱਥ = file_ਵਿੱਥ;
            ਜੇ (s->sh_type != SHT_NOBITS)
                file_ਵਿੱਥ += s->sh_ਮਾਪ;
            ਜਾਰੀ;
        }

        ਜੇ ((f & SHFX_NEWPH) && n) {
            /* different rwx section flags */
            ਜੇ (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
                /* if in the middle of a page, w e duplicate the page in
                   memory so that one copy is RX and the other is RW */
                ਜੇ ((addr & (s_align - 1)) != 0)
                    addr += s_align;
            } ਨਹੀਂਤਾਂ {
                align = s_align - 1;
            }
        }

        tmp = addr;
        addr = (addr + align) & ~align;
        file_ਵਿੱਥ += (ਪੂਰਨ)(addr - tmp);
        s->sh_ਵਿੱਥ = file_ਵਿੱਥ;
        s->sh_addr = addr;

        //printf("%d : %08x %08x %04x %03x %s %d\n", n, (int)file_offset, (int)addr, (int)s->sh_size, s->sh_type, s->name, align + 1);
        addr += s->sh_ਮਾਪ;
        ਜੇ (s->sh_type != SHT_NOBITS)
            file_ਵਿੱਥ += s->sh_ਮਾਪ;

        ਜੇ (f & SHFX_NEWPH) {
            /* set new program header */
            ph = &d->phdr[phfill + n];
            fill_phdr(ph, PT_ਲੱਦੋ, s);
            ph->p_align = s_align;
            ਜੇ (f & SHF_EXECINSTR)
                ph->p_flags |= PF_X;
            ਜੇ (n == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_ਵਿੱਥ = 0;
                ph->p_paddr = ph->p_vaddr = ਅਧਾਰ;
            }
            ++n;
        }

        ਜੇ (ph)
            update_phdr(ph, 0, 0, addr, file_ਵਿੱਥ);

        ਜੇ (f & SHFX_RELRO) {
            ph2 = update_phdr(&d->phdr[d->relro], PT_GNU_RELRO, s, addr, file_ਵਿੱਥ);
            ph2->p_align = 1;
        }
        ਜੇ (f & SHF_TLS) {
            ph2 = update_phdr(&d->phdr[d->tls], PT_TLS, s, addr, file_ਵਿੱਥ);
            ਜੇ (s->sh_type == SHT_NOBITS)
                addr -= s->sh_ਮਾਪ;
            /* for xxx-link.c:relocate() */
            s1->tls_ਸ਼ੁਰੂ = ph2->p_vaddr;
            s1->tls_ਸਿਰਾ = s1->tls_ਸ਼ੁਰੂ + ph2->p_memsz + (-ph2->p_memsz & (ph2->p_align - 1));
        }
        ਜੇ (s->sh_type == SHT_NOTE) {
            update_phdr(&d->phdr[d->notes], PT_NOTE, s, addr, file_ਵਿੱਥ);
        }
    }

    /* Fill other headers */
    ਜੇ (d->dyna)
        fill_phdr(&d->phdr[d->dyna], PT_DYNAMIC, d->dynamic);
    ਜੇ (d->ehfr)
        fill_phdr(&d->phdr[d->ehfr], PT_GNU_EH_ਚੌਖਟਾ, eh_ਚੌਖਟਾ_hdr_section);
    ਜੇ (d->interp)
        fill_phdr(&d->phdr[1], PT_INTERP, d->interp);
    ਜੇ (phfill) {
        ph = &d->phdr[0];
        ph->p_ਵਿੱਥ = ਆਕਾਰ(ElfW(Ehdr));
        ph->p_vaddr = ਅਧਾਰ + ph->p_ਵਿੱਥ;
        ph->p_filesz = phnum * ਆਕਾਰ(ElfW(Phdr));
        ph->p_align = 4;
        fill_phdr(ph, PT_PHDR, ਨਿਰਾ);
    }
    ਵਾਪਸ 0;
}

/* put dynamic tag */
ਸਥਿਰ ਖਾਲੀ put_dt(Section *dynamic, ਪੂਰਨ dt, addr_t val)
{
    ElfW(Dyn) *dyn;
    dyn = section_ptr_ਜੋੜੋ(dynamic, ਆਕਾਰ(ElfW(Dyn)));
    dyn->d_ਟੈਗ = dt;
    dyn->d_un.d_val = val;
}

/* Fill the dynamic section with tags describing the address and size of
   sections */
ਸਥਿਰ ਖਾਲੀ fill_dynamic(TCCState *s1, ਬਣਤਰ dyn_inf *dyninf)
{
    Section *dynamic = dyninf->dynamic;
    Section *s;

    /* put dynamic section entries */
    put_dt(dynamic, DT_HASH, s1->dynsym->hash->sh_addr);
    put_dt(dynamic, DT_GNU_HASH, dyninf->gnu_hash->sh_addr);
    put_dt(dynamic, DT_STRTAB, dyninf->dynstr->sh_addr);
    put_dt(dynamic, DT_SYMTAB, s1->dynsym->sh_addr);
    put_dt(dynamic, DT_STRSZ, dyninf->dynstr->ਅੰਕੜੇ_ਵਿੱਥ);
    put_dt(dynamic, DT_SYMENT, ਆਕਾਰ(ElfW(Sym)));
#ਜੇ PTR_ਮਾਪ == 8
    put_dt(dynamic, DT_RELA, dyninf->rel_addr);
    put_dt(dynamic, DT_RELASZ, dyninf->rel_ਮਾਪ);
    put_dt(dynamic, DT_RELAENT, ਆਕਾਰ(ElfW_Rel));
    ਜੇ (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->ਅੰਕੜੇ_ਵਿੱਥ);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_RELA);
    }
    put_dt(dynamic, DT_RELACOUNT, 0);
#ਨਹੀਂਤਾਂ
    put_dt(dynamic, DT_REL, dyninf->rel_addr);
    put_dt(dynamic, DT_RELSZ, dyninf->rel_ਮਾਪ);
    put_dt(dynamic, DT_RELENT, ਆਕਾਰ(ElfW_Rel));
    ਜੇ (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->ਅੰਕੜੇ_ਵਿੱਥ);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_REL);
    }
    put_dt(dynamic, DT_RELCOUNT, 0);
#ਜੇ_ਅੰਤ
    ਜੇ (versym_section && verneed_section) {
	/* The dynamic linker can not handle VERSYM without VERNEED */
        put_dt(dynamic, DT_VERSYM, versym_section->sh_addr);
        put_dt(dynamic, DT_VERNEED, verneed_section->sh_addr);
        put_dt(dynamic, DT_VERNEEDNUM, dt_verneednum);
    }
    s = have_section(s1, ".preinit_array");
    ਜੇ (s && s->ਅੰਕੜੇ_ਵਿੱਥ) {
        put_dt(dynamic, DT_PREINIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_PREINIT_ARRAYSZ, s->ਅੰਕੜੇ_ਵਿੱਥ);
    }
    s = have_section(s1, ".init_array");
    ਜੇ (s && s->ਅੰਕੜੇ_ਵਿੱਥ) {
        put_dt(dynamic, DT_INIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_INIT_ARRAYSZ, s->ਅੰਕੜੇ_ਵਿੱਥ);
    }
    s = have_section(s1, ".fini_array");
    ਜੇ (s && s->ਅੰਕੜੇ_ਵਿੱਥ) {
        put_dt(dynamic, DT_FINI_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_FINI_ARRAYSZ, s->ਅੰਕੜੇ_ਵਿੱਥ);
    }
    s = have_section(s1, ".init");
    ਜੇ (s && s->ਅੰਕੜੇ_ਵਿੱਥ) {
        put_dt(dynamic, DT_INIT, s->sh_addr);
    }
    s = have_section(s1, ".fini");
    ਜੇ (s && s->ਅੰਕੜੇ_ਵਿੱਥ) {
        put_dt(dynamic, DT_FINI, s->sh_addr);
    }
    ਜੇ (s1->do_debug)
        put_dt(dynamic, DT_DEBUG, 0);
    put_dt(dynamic, DT_NULL, 0);
}

/* Remove gaps between RELX sections.
   These gaps are a result of final_sections_reloc. Here some relocs are removed.
   The gaps are then filled with 0 in tcc_output_elf. The 0 is intepreted as
   R_...NONE reloc. This does work on most targets but on OpenBSD/arm64 this
   is illegal. OpenBSD/arm64 does not support R_...NONE reloc. */
ਸਥਿਰ ਖਾਲੀ update_reloc_sections(TCCState *s1, ਬਣਤਰ dyn_inf *dyninf)
{
    ਪੂਰਨ i;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ file_ਵਿੱਥ = 0;
    Section *s;
    Section *relocplt = s1->plt ? s1->plt->reloc : ਨਿਰਾ;

    /* dynamic relocation table information, for .dynamic section */
    dyninf->rel_addr = dyninf->rel_ਮਾਪ = 0;

    ਲਈ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
	ਜੇ (s->sh_type == SHT_RELX && s != relocplt) {
	    ਜੇ (dyninf->rel_ਮਾਪ == 0) {
		dyninf->rel_addr = s->sh_addr;
		file_ਵਿੱਥ = s->sh_ਵਿੱਥ;
	    }
	    ਨਹੀਂਤਾਂ {
		s->sh_addr = dyninf->rel_addr + dyninf->rel_ਮਾਪ;
		s->sh_ਵਿੱਥ = file_ਵਿੱਥ + dyninf->rel_ਮਾਪ;
	    }
	    dyninf->rel_ਮਾਪ += s->sh_ਮਾਪ;
	}
    }
}
#ਜੇ_ਅੰਤ /* ndef ELF_OBJ_ONLY */

/* Create an ELF file on disk.
   This function handle ELF specific layout requirements */
ਸਥਿਰ ਪੂਰਨ tcc_output_elf(TCCState *s1, FILE *f, ਪੂਰਨ phnum, ElfW(Phdr) *phdr)
{
    ਪੂਰਨ i, shnum, ਵਿੱਥ, ਮਾਪ, file_type;
    Section *s;
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) shdr, *sh;

    file_type = s1->output_type;
    shnum = s1->nb_sections;

    memset(&ehdr, 0, ਆਕਾਰ(ehdr));
    ਜੇ (phnum > 0) {
        ehdr.e_phentsize = ਆਕਾਰ(ElfW(Phdr));
        ehdr.e_phnum = phnum;
        ehdr.e_phoff = ਆਕਾਰ(ElfW(Ehdr));
    }

    /* fill header */
    ehdr.e_ident[0] = ELFMAG0;
    ehdr.e_ident[1] = ELFMAG1;
    ehdr.e_ident[2] = ELFMAG2;
    ehdr.e_ident[3] = ELFMAG3;
    ehdr.e_ident[4] = ELFCLASSW;
    ehdr.e_ident[5] = ELFDATA2LSB;
    ehdr.e_ident[6] = EV_CURRENT;

#ਜੇ TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    ehdr.e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
#ਜਾਂਜੇ TARGETOS_OpenBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_OPENBSD;
#ਜਾਂਜੇ TARGETOS_NetBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_NETBSD;
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM && defined TCC_ARM_EABI
    ehdr.e_flags = EF_ARM_EABI_VER5;
    ehdr.e_flags |= s1->float_abi == ARM_HARD_FLOAT
        ? EF_ARM_VFP_FLOAT : EF_ARM_SOFT_FLOAT;
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    /* XXX should be configurable */
    ehdr.e_flags = EF_RISCV_FLOAT_ABI_DOUBLE;
#ਜੇ_ਅੰਤ

    ਜੇ (file_type == TCC_OUTPUT_OBJ) {
        ehdr.e_type = ET_REL;
    } ਨਹੀਂਤਾਂ {
        ਜੇ (file_type & TCC_OUTPUT_DYN)
            ehdr.e_type = ET_DYN;
        ਨਹੀਂਤਾਂ
            ehdr.e_type = ET_EXEC;
        ਜੇ (s1->elf_entryname)
            ehdr.e_ਇੰਦਰਾਜ = get_sym_addr(s1, s1->elf_entryname, 1, 0);
        ਨਹੀਂਤਾਂ
            ehdr.e_ਇੰਦਰਾਜ = get_sym_addr(s1, "_start", !!(file_type & TCC_OUTPUT_EXE), 0);
        ਜੇ (ehdr.e_ਇੰਦਰਾਜ == (addr_t)-1)
            ehdr.e_ਇੰਦਰਾਜ = ਪਾਠ_section->sh_addr;
        ਜੇ (s1->nb_errors)
            ਵਾਪਸ -1;
    }

    ਛਾਂਟੋ_syms(s1, s1->symtab);

    ehdr.e_machine = EM_TCC_ਨਿਸ਼ਾਨਾ;
    ehdr.e_ਸੰਸਕਰਣ = EV_CURRENT;
    ehdr.e_shoff = (ਆਕਾਰ(ElfW(Ehdr)) + phnum * ਆਕਾਰ(ElfW(Phdr)) + 3) & -4;
    ehdr.e_ehsize = ਆਕਾਰ(ElfW(Ehdr));
    ehdr.e_shentsize = ਆਕਾਰ(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    ਵਿੱਥ = fwrite(&ehdr, 1, ਆਕਾਰ(ElfW(Ehdr)), f);
    ਜੇ (phdr)
        ਵਿੱਥ += fwrite(phdr, 1, phnum * ਆਕਾਰ(ElfW(Phdr)), f);

    /* output section headers */
    ਜਦੋਂ (ਵਿੱਥ < ehdr.e_shoff) {
        fputc(0, f);
        ਵਿੱਥ++;
    }

    ਲਈ(i = 0; i < shnum; i++) {
        sh = &shdr;
        memset(sh, 0, ਆਕਾਰ(ElfW(Shdr)));
        ਜੇ (i) {
            s = s1->sections[i];
            sh->sh_name = s->sh_name;
            sh->sh_type = s->sh_type;
            sh->sh_flags = s->sh_flags;
            sh->sh_entsize = s->sh_entsize;
            sh->sh_info = s->sh_info;
            ਜੇ (s->link)
                sh->sh_link = s->link->sh_ਅੰਕ;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_ਵਿੱਥ = s->sh_ਵਿੱਥ;
            sh->sh_ਮਾਪ = s->sh_ਮਾਪ;
        }
        ਵਿੱਥ += fwrite(sh, 1, ਆਕਾਰ(ElfW(Shdr)), f);
    }

    /* output sections */
    ਲਈ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ਜੇ (s->sh_type != SHT_NOBITS) {
            ਜਦੋਂ (ਵਿੱਥ < s->sh_ਵਿੱਥ) {
                fputc(0, f);
                ਵਿੱਥ++;
            }
            ਮਾਪ = s->sh_ਮਾਪ;
            ਜੇ (ਮਾਪ)
                ਵਿੱਥ += fwrite(s->ਅੰਕੜੇ, 1, ਮਾਪ, f);
        }
    }
    ਵਾਪਸ 0;
}

ਸਥਿਰ ਪੂਰਨ tcc_output_ਦੁਆਧਾਰੀ(TCCState *s1, FILE *f)
{
    Section *s;
    ਪੂਰਨ i, ਵਿੱਥ, ਮਾਪ;

    ਵਿੱਥ = 0;
    ਲਈ(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[i];
        ਜੇ (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            ਜਦੋਂ (ਵਿੱਥ < s->sh_ਵਿੱਥ) {
                fputc(0, f);
                ਵਿੱਥ++;
            }
            ਮਾਪ = s->sh_ਮਾਪ;
            fwrite(s->ਅੰਕੜੇ, 1, ਮਾਪ, f);
            ਵਿੱਥ += ਮਾਪ;
        }
    }
    ਵਾਪਸ 0;
}

/* Write an elf, coff or "binary" file */
ਸਥਿਰ ਪੂਰਨ tcc_write_elf_file(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ phnum,
                              ElfW(Phdr) *phdr)
{
    ਪੂਰਨ fd, ਬਹੁਲਕ, file_type, ret;
    FILE *f;

    file_type = s1->output_type;
    ਜੇ (file_type == TCC_OUTPUT_OBJ)
        ਬਹੁਲਕ = 0666;
    ਨਹੀਂਤਾਂ
        ਬਹੁਲਕ = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_ਦੁਆਧਾਰੀ_2, ਬਹੁਲਕ);
    ਜੇ (fd < 0 || (f = fdopen(fd, "wb")) == ਨਿਰਾ)
        ਵਾਪਸ tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
    ਜੇ (s1->verbose)
        ਲਿਖੋ("<- %s\n", filename);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_COFF
    ਜੇ (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
    ਜੇ (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        ret = tcc_output_elf(s1, f, phnum, phdr);
    ਨਹੀਂਤਾਂ
        ret = tcc_output_ਦੁਆਧਾਰੀ(s1, f);
    fclose(f);

    ਵਾਪਸ ret;
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
/* order sections according to sec_order, remove sections
   that we aren't going to output.  */
ਸਥਿਰ ਖਾਲੀ reorder_sections(TCCState *s1, ਪੂਰਨ *sec_ਕ੍ਰਮ)
{
    ਪੂਰਨ i, nnew, k, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    backmap = tcc_malloc(s1->nb_sections * ਆਕਾਰ(backmap[0]));
    ਲਈ (i = 0, nnew = 0, snew = ਨਿਰਾ; i < s1->nb_sections; i++) {
	k = sec_ਕ੍ਰਮ ? sec_ਕ੍ਰਮ[i] : i;
	s = s1->sections[k];
	ਜੇ (!i || s->sh_name) {
	    backmap[k] = nnew;
            dynarray_ਜੋੜੋ(&snew, &nnew, s);
	} ਨਹੀਂਤਾਂ {
	    backmap[k] = 0;
            /* just remember to free them later */
	    dynarray_ਜੋੜੋ(&s1->priv_sections, &s1->nb_priv_sections, s);
	}
    }
    ਲਈ (i = 1; i < nnew; i++) {
	s = snew[i];
        s->sh_ਅੰਕ = i;
        ਜੇ (s->sh_type == SHT_RELX)
            s->sh_info = backmap[s->sh_info];
        ਨਹੀਂਤਾਂ ਜੇ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM)
            for_each_elem(s, 1, sym, ElfW(Sym))
                ਜੇ (sym->st_shndx < s1->nb_sections)
                    sym->st_shndx = backmap[sym->st_shndx];
    }
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
ਸਥਿਰ ਖਾਲੀ create_arm_attribute_section(TCCState *s1)
{
   // Needed for DLL support.
    ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ arm_attr[] = {
        0x41,                            // 'A'
        0x2c, 0x00, 0x00, 0x00,          // size 0x2c
        'a', 'e', 'a', 'b', 'i', 0x00,   // "aeabi"
        0x01, 0x22, 0x00, 0x00, 0x00,    // 'File Attributes', size 0x22
        0x05, 0x36, 0x00,                // 'CPU_name', "6"
#ਜੇ CONFIG_TCC_CPUVER >= 7
        0x06, 0x0a,                      // 'CPU_arch', 'v7'
#ਨਹੀਂਤਾਂ
        0x06, 0x06,                      // 'CPU_arch', 'v6'
#ਜੇ_ਅੰਤ
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
    Section *attr = new_section(s1, ".ARM.attributes", SHT_ARM_ਗੁਣ, 0);
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr = section_ptr_ਜੋੜੋ(attr, ਆਕਾਰ(arm_attr));
    attr->sh_addralign = 1;
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(ptr, arm_attr, ਆਕਾਰ(arm_attr));
    ਜੇ (s1->float_abi != ARM_HARD_FLOAT) {
        ptr[26] = 0x00; // 'FP_arch', 'No'
        ptr[41] = 0x1e; // 'ABI_optimization_goals'
        ptr[42] = 0x06; // 'Aggressive Debug'
    }
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_RISCV64
ਸਥਿਰ ਖਾਲੀ create_riscv_attribute_section(TCCState *s1)
{
    ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ riscv_attr[] = {
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
    Section *attr = new_section(s1, ".riscv.attributes", SHT_RISCV_ਗੁਣ, 0);
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr = section_ptr_ਜੋੜੋ(attr, ਆਕਾਰ(riscv_attr));
    attr->sh_addralign = 1;
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(ptr, riscv_attr, ਆਕਾਰ(riscv_attr));
}
#ਜੇ_ਅੰਤ

#ਜੇ TARGETOS_OpenBSD || TARGETOS_NetBSD || TARGETOS_FreeBSD

ਸਥਿਰ ਖਾਲੀ fill_bsd_note(Section *s, ਪੂਰਨ type,
			  ਅਚਲ ਅੱਖਰ *ਮੁੱਲ, uint32_t ਅੰਕੜੇ)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ = 0;
    ਅੱਖਰ *ptr;
    ElfW(Nhdr) *note;
    ਪੂਰਨ align = s->sh_addralign;

    /* check if type present */
    ਜਦੋਂ (ਵਿੱਥ + ਆਕਾਰ(ElfW(Nhdr)) < s->ਅੰਕੜੇ_ਵਿੱਥ) {
        note = (ElfW(Nhdr) *) (s->ਅੰਕੜੇ + ਵਿੱਥ);
	ਜੇ (note->n_type == type)
	    ਵਾਪਸ;
	ਵਿੱਥ += (ਆਕਾਰ(ElfW(Nhdr)) + note->n_namesz + note->n_descsz +
		  align - 1) & -align;
    }
    ptr = section_ptr_ਜੋੜੋ(s, ਆਕਾਰ(ElfW(Nhdr)) + 8 + 4);
    note = (ElfW(Nhdr) *) ptr;
    note->n_namesz = 8;
    note->n_descsz = 4;
    note->n_type = type;
    strcpy (ptr + ਆਕਾਰ(ElfW(Nhdr)), ਮੁੱਲ);
    ਸਮ੍ਰਿਤੀ_ਨਕਲ (ptr + ਆਕਾਰ(ElfW(Nhdr)) + 8, &ਅੰਕੜੇ, 4);
}

ਸਥਿਰ Section *create_bsd_note_section(TCCState *s1,
					ਅਚਲ ਅੱਖਰ *name,
					ਅਚਲ ਅੱਖਰ *ਮੁੱਲ)
{
    Section *s;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ major = 0, minor = 0, patch = 0;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_OS_RELEASE
    ਲੜੀ_ਤੋਂ_ਪੜ੍ਹੋ(CONFIG_OS_RELEASE, "%u.%u.%u", &major, &minor, &patch);
#ਜੇ_ਅੰਤ
#ਜੇ TARGETOS_FreeBSD
    ਜੇ (major < 14)
	ਵਾਪਸ ਨਿਰਾ;
#ਜੇ_ਅੰਤ
    s = ਲੱਭੋ_section (s1, name);
    s->sh_type = SHT_NOTE;
#ਜੇ TARGETOS_OpenBSD
    fill_bsd_note(s, ELF_NOTE_OS_GNU, ਮੁੱਲ, 0);
#ਜਾਂਜੇ TARGETOS_NetBSD
    fill_bsd_note(s, 1 /* NT_NETBSD_IDENT_TAG */, ਮੁੱਲ,
		  major * 100000000u + (minor % 100u) * 1000000u +
		  (patch % 10000u) * 100u);
#ਜਾਂਜੇ TARGETOS_FreeBSD
    fill_bsd_note(s, 1 /* NT_FREEBSD_ABI_TAG */, ਮੁੱਲ,
		  major * 100000u + (minor % 100u) * 1000u);
    fill_bsd_note(s, 4 /* NT_FREEBSD_FEATURE_CTL */, ਮੁੱਲ, 0);
    fill_bsd_note(s, 2 /* NT_FREEBSD_NOINIT_TAG */, ਮੁੱਲ, 0);
#ਜੇ_ਅੰਤ
    ਵਾਪਸ s;
}
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਖਾਲੀ alloc_sec_ਨਾਂ(TCCState *s1, ਪੂਰਨ is_obj);

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
ਸਥਿਰ ਪੂਰਨ elf_output_file(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename)
{
    ਪੂਰਨ i, ret, file_type, *sec_ਕ੍ਰਮ;
    ਬਣਤਰ dyn_inf dyninf = {0};
    Section *interp, *dynstr, *dynamic;
    ਪੂਰਨ textrel, got_sym, dt_flags_1;

    file_type = s1->output_type;
    ret = -1;
    interp = dynstr = dynamic = ਨਿਰਾ;
    sec_ਕ੍ਰਮ = ਨਿਰਾ;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
    create_arm_attribute_section (s1);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    create_riscv_attribute_section(s1);
#ਜੇ_ਅੰਤ

#ਜੇ TARGETOS_OpenBSD
    dyninf.note = create_bsd_note_section (s1, ".note.openbsd.ident", "OpenBSD");
#ਜੇ_ਅੰਤ

#ਜੇ TARGETOS_NetBSD
    dyninf.note = create_bsd_note_section (s1, ".note.netbsd.ident", "NetBSD");
#ਜੇ_ਅੰਤ

#ਜੇ TARGETOS_FreeBSD
    dyninf.note = create_bsd_note_section (s1, ".note.tag", "FreeBSD");
#ਜੇ_ਅੰਤ

        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_ਜੋੜੋ_runtime(s1);
	resolve_common_syms(s1);

        ਜੇ (!s1->static_link) {
            ਜੇ (file_type & TCC_OUTPUT_EXE) {
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
            dynamic->sh_entsize = ਆਕਾਰ(ElfW(Dyn));

            got_sym = build_got(s1);
            ਜੇ (file_type & TCC_OUTPUT_EXE) {
                bind_exe_dynsyms(s1, file_type & TCC_OUTPUT_DYN);
                ਜੇ (s1->nb_errors)
                    ਜਾਓ the_ਸਿਰਾ;
            }
            build_got_entries(s1, got_sym);
            ਜੇ (file_type & TCC_OUTPUT_EXE) {
                bind_libs_dynsyms(s1);
            } ਨਹੀਂਤਾਂ {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
#ਜੇ TCC_EH_ਚੌਖਟਾ
	    /* fill with initial data */
	    tcc_eh_ਚੌਖਟਾ_hdr(s1, 0);
#ਜੇ_ਅੰਤ
	    dyninf.gnu_hash = create_gnu_hash(s1);
        } ਨਹੀਂਤਾਂ {
            build_got_entries(s1, 0);
        }
	ਸੰਸਕਰਣ_ਜੋੜੋ (s1);

    textrel = ਸੈੱਟ_sec_sizes(s1);

    ਜੇ (!s1->static_link) {
        /* add a list of needed dlls */
        ਲਈ(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            ਜੇ (dllref->level == 0)
                put_dt(dynamic, DT_NEEDED, put_elf_str(dynstr, dllref->name));
        }

        ਜੇ (s1->rpath)
            put_dt(dynamic, s1->enable_new_dtags ? DT_RUNPATH : DT_RPATH,
                   put_elf_str(dynstr, s1->rpath));

        dt_flags_1 = DF_1_NOW;
        ਜੇ (file_type & TCC_OUTPUT_DYN) {
            ਜੇ (s1->soname)
                put_dt(dynamic, DT_SONAME, put_elf_str(dynstr, s1->soname));
            /* XXX: currently, since we do not handle PIC code, we
               must relocate the readonly segments */
            ਜੇ (textrel)
                put_dt(dynamic, DT_TEXTREL, 0);
            ਜੇ (file_type & TCC_OUTPUT_EXE)
                dt_flags_1 = DF_1_NOW | DF_1_PIE;
	    ਜੇ (s1->znodelete)
		dt_flags_1 |= DF_1_NODELETE;
        }
        put_dt(dynamic, DT_FLAGS, DF_BIND_NOW);
        put_dt(dynamic, DT_FLAGS_1, dt_flags_1);
        ਜੇ (s1->symbolic)
            put_dt(dynamic, DT_SYMBOLIC, 0);

        dyninf.dynamic = dynamic;
        dyninf.dynstr = dynstr;
        /* remember offset and reserve space for 2nd call below */
        dyninf.ਅੰਕੜੇ_ਵਿੱਥ = dynamic->ਅੰਕੜੇ_ਵਿੱਥ;
        fill_dynamic(s1, &dyninf);
        dynamic->sh_ਮਾਪ = dynamic->ਅੰਕੜੇ_ਵਿੱਥ;
        dynstr->sh_ਮਾਪ = dynstr->ਅੰਕੜੇ_ਵਿੱਥ;
    }

    /* create and fill .shstrtab section */
    alloc_sec_ਨਾਂ(s1, 0);
    /* this array is used to reorder sections in the output file */
    sec_ਕ੍ਰਮ = tcc_malloc(ਆਕਾਰ(ਪੂਰਨ) * 2 * s1->nb_sections);
    /* compute section to program header mapping */
    layout_sections(s1, sec_ਕ੍ਰਮ, &dyninf);

        ਜੇ (dynamic) {
            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->ਅੰਕੜੇ, dynamic->sh_addr);
            ਜੇ (file_type == TCC_OUTPUT_EXE
                || (RELOCATE_DLLPLT && (file_type & TCC_OUTPUT_DYN)))
                relocate_plt(s1);
            /* relocate symbols in .dynsym now that final addresses are known */
            relocate_syms(s1, s1->dynsym, 2);
        }

        /* if building executable or DLL, then relocate each section
           except the GOT which is already relocated */
        relocate_syms(s1, s1->symtab, 0);
        ਜੇ (s1->nb_errors != 0)
            ਜਾਓ the_ਸਿਰਾ;
        relocate_sections(s1);
        ਜੇ (dynamic) {
	    update_reloc_sections (s1, &dyninf);
            dynamic->ਅੰਕੜੇ_ਵਿੱਥ = dyninf.ਅੰਕੜੇ_ਵਿੱਥ;
            fill_dynamic(s1, &dyninf);
	}
        /* Perform relocation to GOT or PLT entries */
        ਜੇ (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        ਨਹੀਂਤਾਂ ਜੇ (s1->got)
            fill_local_got_entries(s1);

    ਜੇ (dyninf.gnu_hash)
        update_gnu_hash(s1, dyninf.gnu_hash);

    reorder_sections(s1, sec_ਕ੍ਰਮ);
#ਜੇ TCC_EH_ਚੌਖਟਾ
    /* fill with final data */
    tcc_eh_ਚੌਖਟਾ_hdr(s1, 1);
#ਜੇ_ਅੰਤ
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, dyninf.phnum, dyninf.phdr);
 the_ਸਿਰਾ:
    tcc_free(sec_ਕ੍ਰਮ);
    tcc_free(dyninf.phdr);
    ਵਾਪਸ ret;
}
#ਜੇ_ਅੰਤ /* ndef ELF_OBJ_ONLY */

/* Allocate strings for section names */
ਸਥਿਰ ਖਾਲੀ alloc_sec_ਨਾਂ(TCCState *s1, ਪੂਰਨ is_obj)
{
    ਪੂਰਨ i;
    Section *s, *strsec;

    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");
    ਲਈ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ਜੇ (is_obj)
            s->sh_ਮਾਪ = s->ਅੰਕੜੇ_ਵਿੱਥ;
	ਜੇ (s->sh_ਮਾਪ || s == strsec || (s->sh_flags & SHF_ALLOC) || is_obj)
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_ਮਾਪ = strsec->ਅੰਕੜੇ_ਵਿੱਥ;
}

/* Output an elf .o file */
ਸਥਿਰ ਪੂਰਨ elf_output_obj(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename)
{
    Section *s;
    ਪੂਰਨ i, ret, file_ਵਿੱਥ;
    /* Allocate strings for section names */
    alloc_sec_ਨਾਂ(s1, 1);
    file_ਵਿੱਥ = (ਆਕਾਰ (ElfW(Ehdr)) + 3) & -4;
    file_ਵਿੱਥ += s1->nb_sections * ਆਕਾਰ(ElfW(Shdr));
    ਲਈ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        file_ਵਿੱਥ = (file_ਵਿੱਥ + 15) & -16;
        s->sh_ਵਿੱਥ = file_ਵਿੱਥ;
        ਜੇ (s->sh_type != SHT_NOBITS)
            file_ਵਿੱਥ += s->sh_ਮਾਪ;
    }
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, 0, ਨਿਰਾ);
    ਵਾਪਸ ret;
}

LIBTCCAPI ਪੂਰਨ tcc_output_file(TCCState *s, ਅਚਲ ਅੱਖਰ *filename)
{
    s->nb_errors = 0;
    ਜੇ (s->test_coverage)
        tcc_tcov_ਜੋੜੋ_file(s, filename);
    ਜੇ (s->output_type == TCC_OUTPUT_OBJ)
        ਵਾਪਸ elf_output_obj(s, filename);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    ਵਾਪਸ  pe_output_file(s, filename);
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_MACHO
    ਵਾਪਸ macho_output_file(s, filename);
#ਨਹੀਂਤਾਂ
    ਵਾਪਸ elf_output_file(s, filename);
#ਜੇ_ਅੰਤ
}

ST_FUNC ssize_t ਭਰਿਆ_read(ਪੂਰਨ fd, ਖਾਲੀ *buf, ਮਾਪ_t ਗਿਣਤੀ_3) {
    ਅੱਖਰ *cbuf = buf;
    ਮਾਪ_t rnum = 0;
    ਜਦੋਂ (1) {
        ssize_t ਅੰਕ = ਪਠ(fd, cbuf, ਗਿਣਤੀ_3-rnum);
        ਜੇ (ਅੰਕ < 0) ਵਾਪਸ ਅੰਕ;
        ਜੇ (ਅੰਕ == 0) ਵਾਪਸ rnum;
        rnum += ਅੰਕ;
        cbuf += ਅੰਕ;
    }
}

ST_FUNC ਖਾਲੀ *ਲੱਦੋ_ਅੰਕੜੇ(ਪੂਰਨ fd, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ file_ਵਿੱਥ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ)
{
    ਖਾਲੀ *ਅੰਕੜੇ;

    ਅੰਕੜੇ = tcc_malloc(ਮਾਪ);
    lseek(fd, file_ਵਿੱਥ, SEEK_SET);
    ਭਰਿਆ_read(fd, ਅੰਕੜੇ, ਮਾਪ);
    ਵਾਪਸ ਅੰਕੜੇ;
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ Section_ਮਿਲਾਓ_Info {
    Section *s;            /* corresponding existing section */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} Section_ਮਿਲਾਓ_Info;

ST_FUNC ਪੂਰਨ tcc_object_type(ਪੂਰਨ fd, ElfW(Ehdr) *h)
{
    ਪੂਰਨ ਮਾਪ = ਭਰਿਆ_read(fd, h, ਆਕਾਰ *h);
    ਜੇ (ਮਾਪ == ਆਕਾਰ *h && 0 == memcmp(h, ELFMAG, 4)) {
        ਜੇ (h->e_type == ET_REL)
            ਵਾਪਸ AFF_BINTYPE_REL;
        ਜੇ (h->e_type == ET_DYN)
            ਵਾਪਸ AFF_BINTYPE_DYN;
    } ਨਹੀਂਤਾਂ ਜੇ (ਮਾਪ >= 8) {
        ਜੇ (0 == memcmp(h, ARMAG, 8))
            ਵਾਪਸ AFF_BINTYPE_AR;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_COFF
        ਜੇ (((ਬਣਤਰ filehdr*)h)->f_magic == COFF_C67_MAGIC)
            ਵਾਪਸ AFF_BINTYPE_C67;
#ਜੇ_ਅੰਤ
    }
    ਵਾਪਸ 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC ਪੂਰਨ tcc_ਲੱਦੋ_object_file(TCCState *s1,
                                ਪੂਰਨ fd, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ file_ਵਿੱਥ)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ, ਵਿੱਥ, offseti;
    ਪੂਰਨ i, j, nb_syms, sym_ਸੂਚਕਾਂਕ, ret, seencompressed;
    ਅੱਖਰ *strsec, *strtab;
    ਪੂਰਨ stab_ਸੂਚਕਾਂਕ, stabstr_ਸੂਚਕਾਂਕ;
    ਪੂਰਨ *old_ਮੰਜ਼ਿਲ_new_syms;
    ਅੱਖਰ *sh_name, *name;
    Section_ਮਿਲਾਓ_Info *sm_ਸਾਰਣੀ, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    lseek(fd, file_ਵਿੱਥ, SEEK_SET);
    ਜੇ (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        ਜਾਓ invalid;
    /* test CPU specific stuff */
    ਜੇ (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_ਨਿਸ਼ਾਨਾ) {
invalid:
        ਵਾਪਸ tcc_error_noabort("invalid object file");
    }
    /* read sections */
    shdr = ਲੱਦੋ_ਅੰਕੜੇ(fd, file_ਵਿੱਥ + ehdr.e_shoff,
                     ਆਕਾਰ(ElfW(Shdr)) * ehdr.e_shnum);
    sm_ਸਾਰਣੀ = tcc_mallocz(ਆਕਾਰ(Section_ਮਿਲਾਓ_Info) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = ਲੱਦੋ_ਅੰਕੜੇ(fd, file_ਵਿੱਥ + sh->sh_ਵਿੱਥ, sh->sh_ਮਾਪ);

    /* load symtab and strtab */
    old_ਮੰਜ਼ਿਲ_new_syms = ਨਿਰਾ;
    symtab = ਨਿਰਾ;
    strtab = ਨਿਰਾ;
    nb_syms = 0;
    seencompressed = 0;
    stab_ਸੂਚਕਾਂਕ = stabstr_ਸੂਚਕਾਂਕ = 0;
    ret = -1;

    ਲਈ(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        ਜੇ (sh->sh_type == SHT_SYMTAB) {
            ਜੇ (symtab) {
                tcc_error_noabort("object must contain only one symtab");
                ਜਾਓ the_ਸਿਰਾ;
            }
            nb_syms = sh->sh_ਮਾਪ / ਆਕਾਰ(ElfW(Sym));
            symtab = ਲੱਦੋ_ਅੰਕੜੇ(fd, file_ਵਿੱਥ + sh->sh_ਵਿੱਥ, sh->sh_ਮਾਪ);
            sm_ਸਾਰਣੀ[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = ਲੱਦੋ_ਅੰਕੜੇ(fd, file_ਵਿੱਥ + sh->sh_ਵਿੱਥ, sh->sh_ਮਾਪ);
        }
	ਜੇ (sh->sh_flags & SHF_COMPRESSED)
	    seencompressed = 1;
    }

    /* now examine each section and try to merge its content with the
       ones in memory */
    ਲਈ(i = 1; i < ehdr.e_shnum; i++) {
        /* no need to examine section name strtab */
        ਜੇ (i == ehdr.e_shstrndx)
            ਜਾਰੀ;
        sh = &shdr[i];
	ਜੇ (sh->sh_type == SHT_RELX)
	  sh = &shdr[sh->sh_info];
        /* ignore sections types we do not handle (plus relocs to those) */
        sh_name = strsec + sh->sh_name;
        ਜੇ (0 == ਲੜੀ_ਤੁਲਨਾ(sh_name, ".debug_", 7)
         || 0 == ਲੜੀ_ਤੁਲਨਾ(sh_name, ".stab", 5)) {
	    ਜੇ (!s1->do_debug || seencompressed)
	        ਜਾਰੀ;
#ਜੇ !(TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD)
        } ਨਹੀਂਤਾਂ ਜੇ (0 == ਲੜੀ_ਤੁਲਨਾ(sh_name, ".eh_frame", 9)) {
            ਜੇ (ਨਿਰਾ == eh_ਚੌਖਟਾ_section)
                ਜਾਰੀ;
#ਜੇ_ਅੰਤ
        } ਨਹੀਂਤਾਂ
        ਜੇ (sh->sh_type != SHT_PROGBITS &&
            sh->sh_type != SHT_NOTE &&
            sh->sh_type != SHT_NOBITS &&
            sh->sh_type != SHT_PREINIT_ARRAY &&
            sh->sh_type != SHT_INIT_ARRAY &&
            sh->sh_type != SHT_FINI_ARRAY
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
            /* Added in commit f99d3de221db23e322c6c18c8249282e27726c25
               but suppressed in 3cfaaaf1eb97d858e583412616f68f75fdad5da5
               So don't load it in order to avoid dangling references from
               (STT_SECTION) symbols. */
            // && sh->sh_type != SHT_ARM_EXIDX
#ਜੇ_ਅੰਤ

#ਜੇ TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD
            && sh->sh_type != SHT_X86_64_UNWIND
#ਜੇ_ਅੰਤ
            )
            ਜਾਰੀ;

	sh = &shdr[i];
        sh_name = strsec + sh->sh_name;
        ਜੇ (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        /* find corresponding section, if any */
        ਲਈ(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            ਜੇ (strcmp(s->name, sh_name))
                ਜਾਰੀ;
            ਜੇ (sh->sh_type != s->sh_type
                && strcmp (s->name, ".eh_frame")
                /* some crt1.o seem to have two ".note.GNU-stack" (SHT_NOTE & SHT_PROGBITS) */
                && strcmp (s->name, ".note.GNU-stack")
                ) {
                tcc_error_noabort("section type conflict: %s %02x <> %02x", s->name, sh->sh_type, s->sh_type);
                ਜਾਓ the_ਸਿਰਾ;
            }
            ਜੇ (!ਲੜੀ_ਤੁਲਨਾ(sh_name, ".gnu.linkonce", 13)) {
                /* if a 'linkonce' section is already present, we
                   do not add it again. It is a little tricky as
                   symbols can still be defined in
                   it. */
                sm_ਸਾਰਣੀ[i].link_once = 1;
                ਜਾਓ ਅਗਲਾ;
            }
            ਜੇ (stab_section) {
                ਜੇ (s == stab_section)
                    stab_ਸੂਚਕਾਂਕ = i;
                ਜੇ (s == stab_section->link)
                    stabstr_ਸੂਚਕਾਂਕ = i;
            }
            ਜਾਓ ਮਿਲਿਆ;
        }
        /* not found: create new section */
        s = new_section(s1, sh_name, sh->sh_type, sh->sh_flags & ~SHF_ਸਮੂਹ);
        /* take as much info as possible from the section. sh_link and
           sh_info will be updated later */
        s->sh_addralign = sh->sh_addralign;
        s->sh_entsize = sh->sh_entsize;
        sm_ਸਾਰਣੀ[i].new_section = 1;
    ਮਿਲਿਆ:
        ਮਾਪ = sh->sh_ਮਾਪ;
        /* align start of section */
        ਵਿੱਥ = section_ਜੋੜੋ(s, ਮਾਪ, sh->sh_addralign);
        ਜੇ (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        sm_ਸਾਰਣੀ[i].ਵਿੱਥ = ਵਿੱਥ;
        sm_ਸਾਰਣੀ[i].s = s;
        /* concatenate sections */
        ਜੇ (sh->sh_type != SHT_NOBITS && ਮਾਪ) {
            ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr;
            lseek(fd, file_ਵਿੱਥ + sh->sh_ਵਿੱਥ, SEEK_SET);
            ptr = s->ਅੰਕੜੇ + ਵਿੱਥ;
            ਭਰਿਆ_read(fd, ptr, ਮਾਪ);
        }
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM || defined TCC_ਨਿਸ਼ਾਨਾ_ARM64 || defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
        /* align code sections to instruction lenght */
        /* This is needed if we compile a c file after this */
        ਜੇ (s->sh_flags & SHF_EXECINSTR)
            section_ਜੋੜੋ(s, 0, 4);
#ਜੇ_ਅੰਤ
    ਅਗਲਾ: ;
    }

    /* gr relocate stab strings */
    ਜੇ (stab_ਸੂਚਕਾਂਕ && stabstr_ਸੂਚਕਾਂਕ) {
        Stab_Sym *a, *b;
        ਬਿਨਾਨਿਸ਼ਾਨੀ o;
        s = sm_ਸਾਰਣੀ[stab_ਸੂਚਕਾਂਕ].s;
        a = (Stab_Sym *)(s->ਅੰਕੜੇ + sm_ਸਾਰਣੀ[stab_ਸੂਚਕਾਂਕ].ਵਿੱਥ);
        b = (Stab_Sym *)(s->ਅੰਕੜੇ + s->ਅੰਕੜੇ_ਵਿੱਥ);
        o = sm_ਸਾਰਣੀ[stabstr_ਸੂਚਕਾਂਕ].ਵਿੱਥ;
        ਜਦੋਂ (a < b) {
            ਜੇ (a->n_strx)
                a->n_strx += o;
            a++;
        }
    }

    /* second short pass to update sh_link and sh_info fields of new
       sections */
    ਲਈ(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_ਸਾਰਣੀ[i].s;
        ਜੇ (!s || !sm_ਸਾਰਣੀ[i].new_section)
            ਜਾਰੀ;
        sh = &shdr[i];
        ਜੇ (sh->sh_link > 0)
            s->link = sm_ਸਾਰਣੀ[sh->sh_link].s;
        ਜੇ (sh->sh_type == SHT_RELX) {
            s->sh_info = sm_ਸਾਰਣੀ[sh->sh_info].s->sh_ਅੰਕ;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }

    ਜੇ (!symtab)
        ਜਾਓ ਪੂਰਾ;

    /* resolve symbols */
    old_ਮੰਜ਼ਿਲ_new_syms = tcc_mallocz(nb_syms * ਆਕਾਰ(ਪੂਰਨ));

    sym = symtab + 1;
    ਲਈ(i = 1; i < nb_syms; i++, sym++) {
        ਜੇ (sym->st_shndx != SHN_UNDEF &&
            sym->st_shndx < SHN_LORESERVE) {
            sm = &sm_ਸਾਰਣੀ[sym->st_shndx];
            ਜੇ (sm->link_once) {
                /* if a symbol is in a link once section, we use the
                   already defined symbol. It is very important to get
                   correct relocations */
                ਜੇ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
                    name = strtab + sym->st_name;
                    sym_ਸੂਚਕਾਂਕ = ਲੱਭੋ_elf_sym(symtab_section, name);
                    ਜੇ (sym_ਸੂਚਕਾਂਕ)
                        old_ਮੰਜ਼ਿਲ_new_syms[i] = sym_ਸੂਚਕਾਂਕ;
                }
                ਜਾਰੀ;
            }
            /* if no corresponding section added, no need to add symbol */
            ਜੇ (!sm->s)
                ਜਾਰੀ;
            /* convert section number */
            sym->st_shndx = sm->s->sh_ਅੰਕ;
            /* offset value */
            sym->st_ਮੁੱਲ += sm->ਵਿੱਥ;
        }
        /* add symbol */
        name = strtab + sym->st_name;
        sym_ਸੂਚਕਾਂਕ = ਸੈੱਟ_elf_sym(symtab_section, sym->st_ਮੁੱਲ, sym->st_ਮਾਪ,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_ਮੰਜ਼ਿਲ_new_syms[i] = sym_ਸੂਚਕਾਂਕ;
    }

    /* third pass to patch relocation entries */
    ਲਈ(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_ਸਾਰਣੀ[i].s;
        ਜੇ (!s)
            ਜਾਰੀ;
        sh = &shdr[i];
        ਵਿੱਥ = sm_ਸਾਰਣੀ[i].ਵਿੱਥ;
        ਮਾਪ = sh->sh_ਮਾਪ;
        ਚੋਣ(s->sh_type) {
        ਹਾਲਤ SHT_RELX:
            /* take relocation offset information */
            offseti = sm_ਸਾਰਣੀ[sh->sh_info].ਵਿੱਥ;
	    ਲਈ (rel = (ElfW_Rel *) s->ਅੰਕੜੇ + (ਵਿੱਥ / ਆਕਾਰ(*rel));
		 rel < (ElfW_Rel *) s->ਅੰਕੜੇ + ((ਵਿੱਥ + ਮਾਪ) / ਆਕਾਰ(*rel));
		 rel++) {
                ਪੂਰਨ type;
                ਬਿਨਾਨਿਸ਼ਾਨੀ sym_ਸੂਚਕਾਂਕ;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                ਜੇ (sym_ਸੂਚਕਾਂਕ >= nb_syms)
                    ਜਾਓ invalid_reloc;
                sym_ਸੂਚਕਾਂਕ = old_ਮੰਜ਼ਿਲ_new_syms[sym_ਸੂਚਕਾਂਕ];
                /* ignore link_once in rel section. */
                ਜੇ (!sym_ਸੂਚਕਾਂਕ && !sm_ਸਾਰਣੀ[sh->sh_info].link_once
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
                    && type != R_ARM_V4BX
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
                    && type != R_RISCV_ALIGN
                    && type != R_RISCV_RELAX
#ਜੇ_ਅੰਤ
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, (ਪੂਰਨ)rel->r_ਵਿੱਥ);
                    ਜਾਓ the_ਸਿਰਾ;
                }
                rel->r_info = ELFW(R_INFO)(sym_ਸੂਚਕਾਂਕ, type);
                /* offset the relocation offset */
                rel->r_ਵਿੱਥ += offseti;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
                /* Jumps and branches from a Thumb code to a PLT entry need
                   special handling since PLT entries are ARM code.
                   Unconditional bl instructions referencing PLT entries are
                   handled by converting these instructions into blx
                   instructions. Other case of instructions referencing a PLT
                   entry require to add a Thumb stub before the PLT entry to
                   switch to ARM mode. We set bit plt_thumb_stub of the
                   attribute of a symbol to indicate such a case. */
                ਜੇ (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 1)->plt_thumb_stub = 1;
#ਜੇ_ਅੰਤ
            }
            ਰੋਕੋ;
        ਮੂਲ:
            ਰੋਕੋ;
        }
    }
 ਪੂਰਾ:
    ret = !s1->nb_errors - 1; /* errors possibly from set_elf_sym() */
 the_ਸਿਰਾ:
    tcc_free(symtab);
    tcc_free(strtab);
    tcc_free(old_ਮੰਜ਼ਿਲ_new_syms);
    tcc_free(sm_ਸਾਰਣੀ);
    tcc_free(strsec);
    tcc_free(shdr);
    ਵਾਪਸ ret;
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ Archive_ਸਿਰਲੇਖ {
    ਅੱਖਰ ar_name[16];           /* name of this member */
    ਅੱਖਰ ar_date[12];           /* file mtime */
    ਅੱਖਰ ar_uid[6];             /* owner uid; printed as decimal */
    ਅੱਖਰ ar_gid[6];             /* owner gid; printed as decimal */
    ਅੱਖਰ ar_ਬਹੁਲਕ[8];            /* file mode, printed as octal   */
    ਅੱਖਰ ar_ਮਾਪ[10];           /* file size, printed as decimal */
    ਅੱਖਰ ar_fmag[2];            /* should contain ARFMAG */
} Archive_ਸਿਰਲੇਖ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARFMAG "`\n"

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ get_be(ਅਚਲ uint8_t *b, ਪੂਰਨ n)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ret = 0;
    ਜਦੋਂ (n)
        ret = (ret << 8) | *b++, --n;
    ਵਾਪਸ ret;
}

ਸਥਿਰ ਪੂਰਨ read_ar_ਸਿਰਲੇਖ(ਪੂਰਨ fd, ਪੂਰਨ ਵਿੱਥ, Archive_ਸਿਰਲੇਖ *hdr)
{
    ਅੱਖਰ *p, *e;
    ਪੂਰਨ len;
    lseek(fd, ਵਿੱਥ, SEEK_SET);
    len = ਭਰਿਆ_read(fd, hdr, ਆਕਾਰ(Archive_ਸਿਰਲੇਖ));
    ਜੇ (len != ਆਕਾਰ(Archive_ਸਿਰਲੇਖ))
        ਵਾਪਸ len ? -1 : 0;
    ਜੇ (memcmp(hdr->ar_fmag, ARFMAG, ਆਕਾਰ hdr->ar_fmag))
        ਵਾਪਸ -1;
    p = hdr->ar_name;
    ਲਈ (e = p + ਆਕਾਰ hdr->ar_name; e > p && e[-1] == ' ';)
        --e;
    *e = '\0';
    hdr->ar_ਮਾਪ[ਆਕਾਰ hdr->ar_ਮਾਪ-1] = 0;
    ਵਾਪਸ len;
}

/* load only the objects which resolve undefined symbols */
ਸਥਿਰ ਪੂਰਨ tcc_ਲੱਦੋ_alacarte(TCCState *s1, ਪੂਰਨ fd, ਪੂਰਨ ਮਾਪ, ਪੂਰਨ entrysize)
{
    ਪੂਰਨ i, bound, nsyms, sym_ਸੂਚਕਾਂਕ, len, ret = -1;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ off;
    uint8_t *ਅੰਕੜੇ;
    ਅਚਲ ਅੱਖਰ *ar_ਨਾਂ, *p;
    ਅਚਲ uint8_t *ar_ਸੂਚਕਾਂਕ;
    ElfW(Sym) *sym;
    Archive_ਸਿਰਲੇਖ hdr;

    ਅੰਕੜੇ = tcc_malloc(ਮਾਪ);
    ਜੇ (ਭਰਿਆ_read(fd, ਅੰਕੜੇ, ਮਾਪ) != ਮਾਪ)
        ਜਾਓ invalid;
    nsyms = get_be(ਅੰਕੜੇ, entrysize);
    ar_ਸੂਚਕਾਂਕ = ਅੰਕੜੇ + entrysize;
    ar_ਨਾਂ = (ਅੱਖਰ *) ar_ਸੂਚਕਾਂਕ + nsyms * entrysize;

    ਕਰੋ {
        bound = 0;
        ਲਈ (p = ar_ਨਾਂ, i = 0; i < nsyms; i++, p += ਲੜੀ_ਲੰਬਾਈ(p)+1) {
            Section *s = symtab_section;
            sym_ਸੂਚਕਾਂਕ = ਲੱਭੋ_elf_sym(s, p);
            ਜੇ (!sym_ਸੂਚਕਾਂਕ)
                ਜਾਰੀ;
            sym = &((ElfW(Sym) *)s->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
            ਜੇ(sym->st_shndx != SHN_UNDEF)
                ਜਾਰੀ;
            off = get_be(ar_ਸੂਚਕਾਂਕ + i * entrysize, entrysize);
            len = read_ar_ਸਿਰਲੇਖ(fd, off, &hdr);
            ਜੇ (len <= 0 || memcmp(hdr.ar_fmag, ARFMAG, 2)) {
        invalid:
                tcc_error_noabort("invalid archive");
                ਜਾਓ the_ਸਿਰਾ;
            }
            off += len;
            ਜੇ (s1->verbose == 2)
                ਲਿਖੋ("   -> %s\n", hdr.ar_name);
            ਜੇ (tcc_ਲੱਦੋ_object_file(s1, fd, off) < 0)
                ਜਾਓ the_ਸਿਰਾ;
            ++bound;
        }
    } ਜਦੋਂ(bound);
    ret = 0;
 the_ਸਿਰਾ:
    tcc_free(ਅੰਕੜੇ);
    ਵਾਪਸ ret;
}

/* load a '.a' file */
ST_FUNC ਪੂਰਨ tcc_ਲੱਦੋ_archive(TCCState *s1, ਪੂਰਨ fd, ਪੂਰਨ alacarte)
{
    Archive_ਸਿਰਲੇਖ hdr;
    /* char magic[8]; */
    ਪੂਰਨ ਮਾਪ, len;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ file_ਵਿੱਥ;
    ElfW(Ehdr) ehdr;

    /* skip magic which was already checked */
    /* full_read(fd, magic, sizeof(magic)); */
    file_ਵਿੱਥ = ਆਕਾਰ ARMAG - 1;

    ਲਈ(;;) {
        len = read_ar_ਸਿਰਲੇਖ(fd, file_ਵਿੱਥ, &hdr);
        ਜੇ (len == 0)
            ਵਾਪਸ 0;
        ਜੇ (len < 0)
            ਵਾਪਸ tcc_error_noabort("invalid archive");
        file_ਵਿੱਥ += len;
        ਮਾਪ = strtol(hdr.ar_ਮਾਪ, ਨਿਰਾ, 0);
        ਜੇ (alacarte) {
            /* coff symbol table : we handle it */
            ਜੇ (!strcmp(hdr.ar_name, "/"))
                ਵਾਪਸ tcc_ਲੱਦੋ_alacarte(s1, fd, ਮਾਪ, 4);
            ਜੇ (!strcmp(hdr.ar_name, "/SYM64/"))
                ਵਾਪਸ tcc_ਲੱਦੋ_alacarte(s1, fd, ਮਾਪ, 8);
        } ਨਹੀਂਤਾਂ ਜੇ (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
            ਜੇ (s1->verbose == 2)
                ਲਿਖੋ("   -> %s\n", hdr.ar_name);
            ਜੇ (tcc_ਲੱਦੋ_object_file(s1, fd, file_ਵਿੱਥ) < 0)
                ਵਾਪਸ -1;
        }
        /* align to even */
        file_ਵਿੱਥ = (file_ਵਿੱਥ + ਮਾਪ + 1) & ~1;
    }
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
/* Set LV[I] to the global index of sym-version (LIB,VERSION).  Maybe resizes
   LV, maybe create a new entry for (LIB,VERSION).  */
ਸਥਿਰ ਖਾਲੀ ਸੈੱਟ_ver_ਮੰਜ਼ਿਲ_ver(TCCState *s1, ਪੂਰਨ *n, ਪੂਰਨ **lv, ਪੂਰਨ i, ਅੱਖਰ *lib, ਅੱਖਰ *ਸੰਸਕਰਣ)
{
    ਜਦੋਂ (i >= *n) {
        *lv = tcc_realloc(*lv, (*n + 1) * ਆਕਾਰ(**lv));
        (*lv)[(*n)++] = -1;
    }
    ਜੇ ((*lv)[i] == -1) {
        ਪੂਰਨ v, prev_same_lib = -1;
        ਲਈ (v = 0; v < nb_sym_versions; v++) {
            ਜੇ (strcmp(sym_versions[v].lib, lib))
              ਜਾਰੀ;
            prev_same_lib = v;
            ਜੇ (!strcmp(sym_versions[v].ਸੰਸਕਰਣ, ਸੰਸਕਰਣ))
              ਰੋਕੋ;
        }
        ਜੇ (v == nb_sym_versions) {
            sym_versions = tcc_realloc (sym_versions,
                                        (v + 1) * ਆਕਾਰ(*sym_versions));
            sym_versions[v].lib = tcc_strdup(lib);
            sym_versions[v].ਸੰਸਕਰਣ = tcc_strdup(ਸੰਸਕਰਣ);
            sym_versions[v].ਬਾਹਰਲਾ_ਸੂਚਕਾਂਕ = 0;
            sym_versions[v].prev_same_lib = prev_same_lib;
            nb_sym_versions++;
        }
        (*lv)[i] = v;
    }
}

/* Associates symbol SYM_INDEX (in dynsymtab) with sym-version index
   VERNDX.  */
ਸਥਿਰ ਖਾਲੀ
ਸੈੱਟ_sym_ਸੰਸਕਰਣ(TCCState *s1, ਪੂਰਨ sym_ਸੂਚਕਾਂਕ, ਪੂਰਨ verndx)
{
    ਜੇ (sym_ਸੂਚਕਾਂਕ >= nb_sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ) {
        ਪੂਰਨ newelems = sym_ਸੂਚਕਾਂਕ ? sym_ਸੂਚਕਾਂਕ * 2 : 1;
        sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ = tcc_realloc(sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ,
                                     newelems * ਆਕਾਰ(*sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ));
        memset(sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ + nb_sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ, -1,
               (newelems - nb_sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ) * ਆਕਾਰ(*sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ));
        nb_sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ = newelems;
    }
    ਜੇ (sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ[sym_ਸੂਚਕਾਂਕ] < 0)
      sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ[sym_ਸੂਚਕਾਂਕ] = verndx;
}

ਬਣਤਰ versym_info {
    ਪੂਰਨ nb_versyms;
    ElfW(Verdef) *verdef;
    ElfW(Verneed) *verneed;
    ElfW(Half) *versym;
    ਪੂਰਨ nb_local_ver, *local_ver;
};


ਸਥਿਰ ਖਾਲੀ store_ਸੰਸਕਰਣ(TCCState *s1, ਬਣਤਰ versym_info *v, ਅੱਖਰ *dynstr)
{
    ਅੱਖਰ *lib, *ਸੰਸਕਰਣ;
    uint32_t ਅਗਲਾ;
    ਪੂਰਨ i;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DEBUG_ਸੰਸਕਰਣ 0

    ਜੇ (v->versym && v->verdef) {
      ElfW(Verdef) *vdef = v->verdef;
      lib = ਨਿਰਾ;
      ਕਰੋ {
        ElfW(Verdaux) *verdaux =
	  (ElfW(Verdaux) *) (((ਅੱਖਰ *) vdef) + vdef->vd_aux);

#ਜੇ DEBUG_ਸੰਸਕਰਣ
	ਲਿਖੋ ("verdef: version:%u flags:%u index:%u, hash:%u\n",
	        vdef->vd_ਸੰਸਕਰਣ, vdef->vd_flags, vdef->vd_ndx,
		vdef->vd_hash);
#ਜੇ_ਅੰਤ
	ਜੇ (vdef->vd_cnt) {
          ਸੰਸਕਰਣ = dynstr + verdaux->vda_name;

	  ਜੇ (lib == ਨਿਰਾ)
	    lib = ਸੰਸਕਰਣ;
	  ਨਹੀਂਤਾਂ
            ਸੈੱਟ_ver_ਮੰਜ਼ਿਲ_ver(s1, &v->nb_local_ver, &v->local_ver, vdef->vd_ndx,
                           lib, ਸੰਸਕਰਣ);
#ਜੇ DEBUG_ਸੰਸਕਰਣ
	  ਲਿਖੋ ("  verdaux(%u): %s\n", vdef->vd_ndx, ਸੰਸਕਰਣ);
#ਜੇ_ਅੰਤ
	}
        ਅਗਲਾ = vdef->vd_ਅਗਲਾ;
        vdef = (ElfW(Verdef) *) (((ਅੱਖਰ *) vdef) + ਅਗਲਾ);
      } ਜਦੋਂ (ਅਗਲਾ);
    }
    ਜੇ (v->versym && v->verneed) {
      ElfW(Verneed) *vneed = v->verneed;
      ਕਰੋ {
        ElfW(Vernaux) *vernaux =
	  (ElfW(Vernaux) *) (((ਅੱਖਰ *) vneed) + vneed->vn_aux);

        lib = dynstr + vneed->vn_file;
#ਜੇ DEBUG_ਸੰਸਕਰਣ
	ਲਿਖੋ ("verneed: %u %s\n", vneed->vn_ਸੰਸਕਰਣ, lib);
#ਜੇ_ਅੰਤ
	ਲਈ (i = 0; i < vneed->vn_cnt; i++) {
	  ਜੇ ((vernaux->vna_other & 0x8000) == 0) { /* hidden */
              ਸੰਸਕਰਣ = dynstr + vernaux->vna_name;
              ਸੈੱਟ_ver_ਮੰਜ਼ਿਲ_ver(s1, &v->nb_local_ver, &v->local_ver, vernaux->vna_other,
                             lib, ਸੰਸਕਰਣ);
#ਜੇ DEBUG_ਸੰਸਕਰਣ
	    ਲਿਖੋ ("  vernaux(%u): %u %u %s\n",
		    vernaux->vna_other, vernaux->vna_hash,
		    vernaux->vna_flags, ਸੰਸਕਰਣ);
#ਜੇ_ਅੰਤ
	  }
	  vernaux = (ElfW(Vernaux) *) (((ਅੱਖਰ *) vernaux) + vernaux->vna_ਅਗਲਾ);
	}
        ਅਗਲਾ = vneed->vn_ਅਗਲਾ;
        vneed = (ElfW(Verneed) *) (((ਅੱਖਰ *) vneed) + ਅਗਲਾ);
      } ਜਦੋਂ (ਅਗਲਾ);
    }

#ਜੇ DEBUG_ਸੰਸਕਰਣ
    ਲਈ (i = 0; i < v->nb_local_ver; i++) {
      ਜੇ (v->local_ver[i] > 0) {
        ਲਿਖੋ ("%d: lib: %s, version %s\n",
		i, sym_versions[v->local_ver[i]].lib,
                sym_versions[v->local_ver[i]].ਸੰਸਕਰਣ);
      }
    }
#ਜੇ_ਅੰਤ
}

/* load a library / DLL
   'level = 0' means that the DLL is referenced by the user
   (so it should be added as DT_NEEDED in the generated ELF file) */
ST_FUNC ਪੂਰਨ tcc_ਲੱਦੋ_dll(TCCState *s1, ਪੂਰਨ fd, ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    ਪੂਰਨ i, nb_syms, nb_dts, sym_bind, ret = -1;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;

    ਅੱਖਰ *dynstr;
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ;
    ਅਚਲ ਅੱਖਰ *name, *soname;
    ਬਣਤਰ versym_info v;

    ਭਰਿਆ_read(fd, &ehdr, ਆਕਾਰ(ehdr));

    /* test CPU specific stuff */
    ਜੇ (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_ਨਿਸ਼ਾਨਾ) {
        ਵਾਪਸ tcc_error_noabort("bad architecture");
    }

    /* read sections */
    shdr = ਲੱਦੋ_ਅੰਕੜੇ(fd, ehdr.e_shoff, ਆਕਾਰ(ElfW(Shdr)) * ehdr.e_shnum);

    /* load dynamic section and dynamic symbols */
    nb_syms = 0;
    nb_dts = 0;
    dynamic = ਨਿਰਾ;
    dynsym = ਨਿਰਾ; /* avoid warning */
    dynstr = ਨਿਰਾ; /* avoid warning */
    memset(&v, 0, ਆਕਾਰ v);

    ਲਈ(i = 0, sh = shdr; i < ehdr.e_shnum; i++, sh++) {
        ਚੋਣ(sh->sh_type) {
        ਹਾਲਤ SHT_DYNAMIC:
            nb_dts = sh->sh_ਮਾਪ / ਆਕਾਰ(ElfW(Dyn));
            dynamic = ਲੱਦੋ_ਅੰਕੜੇ(fd, sh->sh_ਵਿੱਥ, sh->sh_ਮਾਪ);
            ਰੋਕੋ;
        ਹਾਲਤ SHT_DYNSYM:
            nb_syms = sh->sh_ਮਾਪ / ਆਕਾਰ(ElfW(Sym));
            dynsym = ਲੱਦੋ_ਅੰਕੜੇ(fd, sh->sh_ਵਿੱਥ, sh->sh_ਮਾਪ);
            sh1 = &shdr[sh->sh_link];
            dynstr = ਲੱਦੋ_ਅੰਕੜੇ(fd, sh1->sh_ਵਿੱਥ, sh1->sh_ਮਾਪ);
            ਰੋਕੋ;
        ਹਾਲਤ SHT_GNU_verdef:
	    v.verdef = ਲੱਦੋ_ਅੰਕੜੇ(fd, sh->sh_ਵਿੱਥ, sh->sh_ਮਾਪ);
	    ਰੋਕੋ;
        ਹਾਲਤ SHT_GNU_verneed:
	    v.verneed = ਲੱਦੋ_ਅੰਕੜੇ(fd, sh->sh_ਵਿੱਥ, sh->sh_ਮਾਪ);
	    ਰੋਕੋ;
        ਹਾਲਤ SHT_GNU_versym:
            v.nb_versyms = sh->sh_ਮਾਪ / ਆਕਾਰ(ElfW(Half));
	    v.versym = ਲੱਦੋ_ਅੰਕੜੇ(fd, sh->sh_ਵਿੱਥ, sh->sh_ਮਾਪ);
	    ਰੋਕੋ;
        ਮੂਲ:
            ਰੋਕੋ;
        }
    }

    ਜੇ (!dynamic)
        ਜਾਓ the_ਸਿਰਾ;

    /* compute the real library name */
    soname = tcc_basename(filename);
    ਲਈ(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        ਜੇ (dt->d_ਟੈਗ == DT_SONAME)
            soname = dynstr + dt->d_un.d_val;

    /* if the dll is already loaded, do not load it */
    ਜੇ (tcc_ਜੋੜੋ_dllref(s1, soname, level)->ਮਿਲਿਆ)
        ਜਾਓ ret_success;

    ਜੇ (v.nb_versyms != nb_syms)
        tcc_free (v.versym), v.versym = ਨਿਰਾ;
    ਨਹੀਂਤਾਂ
        store_ਸੰਸਕਰਣ(s1, &v, dynstr);

    /* add dynamic symbols in dynsym_section */
    ਲਈ(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        ਜੇ (sym_bind == STB_LOCAL)
            ਜਾਰੀ;
        name = dynstr + sym->st_name;
        sym_ਸੂਚਕਾਂਕ = ਸੈੱਟ_elf_sym(s1->dynsymtab_section, sym->st_ਮੁੱਲ, sym->st_ਮਾਪ,
                                sym->st_info, sym->st_other, sym->st_shndx, name);
        ਜੇ (v.versym) {
            ElfW(Half) vsym = v.versym[i];
            ਜੇ ((vsym & 0x8000) == 0 && vsym > 0 && vsym < v.nb_local_ver)
                ਸੈੱਟ_sym_ਸੰਸਕਰਣ(s1, sym_ਸੂਚਕਾਂਕ, v.local_ver[vsym]);
        }
    }

    /* do not load all referenced libraries
       (recursive loading can break linking of libraries) */
    /* following DT_NEEDED is needed for the dynamic loader (libdl.so),
       but it is no longer needed, when linking a library or a program.
       When tcc output mode is OUTPUT_MEM,
       tcc calls dlopen, which handles DT_NEEDED for us */

#ਜੇ 0
    ਲਈ(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        ਜੇ (dt->d_ਟੈਗ == DT_RPATH)
            tcc_ਜੋੜੋ_library_ਰਸਤਾ(s1, dynstr + dt->d_un.d_val);

    /* load all referenced DLLs */
    ਲਈ(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        ਚੋਣ(dt->d_ਟੈਗ) {
        ਹਾਲਤ DT_NEEDED:
            name = dynstr + dt->d_un.d_val;
            ਜੇ (tcc_ਜੋੜੋ_dllref(s1, name, -1))
                ਜਾਰੀ;
            ਜੇ (tcc_ਜੋੜੋ_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                ret = tcc_error_noabort("referenced dll '%s' not found", name);
                ਜਾਓ the_ਸਿਰਾ;
            }
        }
    }
#ਜੇ_ਅੰਤ

 ret_success:
    ret = 0;
 the_ਸਿਰਾ:
    tcc_free(dynstr);
    tcc_free(dynsym);
    tcc_free(dynamic);
    tcc_free(shdr);
    tcc_free(v.local_ver);
    tcc_free(v.verdef);
    tcc_free(v.verneed);
    tcc_free(v.versym);
    ਵਾਪਸ ret;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LD_TOK_NAME 256
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LD_TOK_EOF  (-1)
ਸਥਿਰ ਪੂਰਨ ld_inp(TCCState *s1)
{
    ਪੂਰਨ c = *s1->ld_p;
    ਜੇ (c == 0)
        ਵਾਪਸ CH_EOF;
    ++s1->ld_p;
    ਵਾਪਸ c;
}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ld_unget(s1, ch) ਜੇ (ch != CH_EOF) --s1->ld_p

/* return next ld script token */
ਸਥਿਰ ਪੂਰਨ ld_ਅਗਲਾ(TCCState *s1, ਅੱਖਰ *name, ਪੂਰਨ name_ਮਾਪ)
{
    ਪੂਰਨ c, d, ch;
    ਅੱਖਰ *q;

 redo:
    ch = ld_inp(s1);
    q = name, *q++ = ch;
    ਚੋਣ(ch) {
    ਹਾਲਤ ' ':
    ਹਾਲਤ '\t':
    ਹਾਲਤ '\f':
    ਹਾਲਤ '\v':
    ਹਾਲਤ '\r':
    ਹਾਲਤ '\n':
        ਜਾਓ redo;
    ਹਾਲਤ '/':
        ch = ld_inp(s1);
        ਜੇ (ch == '*') { /* comment */
            ਲਈ (d = 0;; d = ch) {
                ch = ld_inp(s1);
                ਜੇ (ch == CH_EOF || (ch == '/' && d == '*'))
                    ਰੋਕੋ;
            }
            ਜਾਓ redo;
        } ਨਹੀਂਤਾਂ {
            ਜਾਓ parse_name;
        }
        ਰੋਕੋ;
    ਹਾਲਤ '\\':
    /* case 'a' ... 'z': */
    ਹਾਲਤ 'a':
       ਹਾਲਤ 'b':
       ਹਾਲਤ 'c':
       ਹਾਲਤ 'd':
       ਹਾਲਤ 'e':
       ਹਾਲਤ 'f':
       ਹਾਲਤ 'g':
       ਹਾਲਤ 'h':
       ਹਾਲਤ 'i':
       ਹਾਲਤ 'j':
       ਹਾਲਤ 'k':
       ਹਾਲਤ 'l':
       ਹਾਲਤ 'm':
       ਹਾਲਤ 'n':
       ਹਾਲਤ 'o':
       ਹਾਲਤ 'p':
       ਹਾਲਤ 'q':
       ਹਾਲਤ 'r':
       ਹਾਲਤ 's':
       ਹਾਲਤ 't':
       ਹਾਲਤ 'u':
       ਹਾਲਤ 'v':
       ਹਾਲਤ 'w':
       ਹਾਲਤ 'x':
       ਹਾਲਤ 'y':
       ਹਾਲਤ 'z':
    /* case 'A' ... 'z': */
    ਹਾਲਤ 'A':
       ਹਾਲਤ 'B':
       ਹਾਲਤ 'C':
       ਹਾਲਤ 'D':
       ਹਾਲਤ 'E':
       ਹਾਲਤ 'F':
       ਹਾਲਤ 'G':
       ਹਾਲਤ 'H':
       ਹਾਲਤ 'I':
       ਹਾਲਤ 'J':
       ਹਾਲਤ 'K':
       ਹਾਲਤ 'L':
       ਹਾਲਤ 'M':
       ਹਾਲਤ 'N':
       ਹਾਲਤ 'O':
       ਹਾਲਤ 'P':
       ਹਾਲਤ 'Q':
       ਹਾਲਤ 'R':
       ਹਾਲਤ 'S':
       ਹਾਲਤ 'T':
       ਹਾਲਤ 'U':
       ਹਾਲਤ 'V':
       ਹਾਲਤ 'W':
       ਹਾਲਤ 'X':
       ਹਾਲਤ 'Y':
       ਹਾਲਤ 'Z':
    ਹਾਲਤ '-':
    ਹਾਲਤ '_':
    ਹਾਲਤ '.':
    ਹਾਲਤ '$':
    ਹਾਲਤ '~':
        ਲਈ(;;) {
            ch = ld_inp(s1);
    parse_name:
            ਜੇ (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') ||
                  strchr("/.-_+=$:\\,~", ch)))
                ਰੋਕੋ;
            ਜੇ ((q - name) < name_ਮਾਪ - 1) {
                *q++ = ch;
            }
        }
        ld_unget(s1, ch);
        c = LD_TOK_NAME;
        ਰੋਕੋ;
    ਹਾਲਤ CH_EOF:
        c = LD_TOK_EOF;
        ਰੋਕੋ;
    ਮੂਲ:
        c = ch;
        ਰੋਕੋ;
    }
    *q = '\0';
    ਵਾਪਸ c;
}

ਸਥਿਰ ਪੂਰਨ ld_ਜੋੜੋ_file(TCCState *s1, ਅਚਲ ਅੱਖਰ filename[])
{
    ਜੇ (filename[0] == '-' && filename[1] == 'l')
        ਵਾਪਸ tcc_ਜੋੜੋ_library(s1, filename + 2);
    ਜੇ (CONFIG_SYSROOT[0] != '\0' || !IS_ABSPATH(filename)) {
        /* lookup via library paths */
        ਪੂਰਨ ret = tcc_ਜੋੜੋ_dll(s1, tcc_basename(filename), 0);
        ਜੇ (ret != FILE_NOT_ਮਿਲਿਆ)
            ਵਾਪਸ ret;
    }
    ਵਾਪਸ tcc_ਜੋੜੋ_file_ਅੰਦਰੂਨੀ(s1, filename, AFF_PRINT_ERROR);
}

/* did static libraries add new undefined symbols? */
ਸਥਿਰ ਪੂਰਨ new_undef_sym(TCCState *s1, ਪੂਰਨ sym_ਵਿੱਥ)
{
    ਜਦੋਂ (sym_ਵਿੱਥ < s1->symtab->ਅੰਕੜੇ_ਵਿੱਥ) {
        ElfW(Sym) *esym = (ਖਾਲੀ*)(s1->symtab->ਅੰਕੜੇ + sym_ਵਿੱਥ);
        ਜੇ (esym->st_shndx == SHN_UNDEF)
            ਵਾਪਸ 1;
        sym_ਵਿੱਥ += ਆਕਾਰ (ElfW(Sym));
    }
    ਵਾਪਸ 0;
}

ਸਥਿਰ ਪੂਰਨ ld_ਜੋੜੋ_file_list(TCCState *s1, ਅਚਲ ਅੱਖਰ *cmd)
{
    ਅੱਖਰ filename[1024];
    ਪੂਰਨ t, c, sym_ਵਿੱਥ, ret = 0;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *pos = s1->ld_p;

repeat:
    s1->ld_p = pos;
    sym_ਵਿੱਥ = s1->symtab->ਅੰਕੜੇ_ਵਿੱਥ;
    c = cmd[0];

    t = ld_ਅਗਲਾ(s1, filename, ਆਕਾਰ(filename));
    ਜੇ (t != '(')
        ਵਾਪਸ tcc_error_noabort("expected '(' after %s", cmd);
    t = ld_ਅਗਲਾ(s1, filename, ਆਕਾਰ(filename));
    ਲਈ(;;) {
        ਜੇ (t == LD_TOK_EOF) {
            ਵਾਪਸ tcc_error_noabort("unexpected end of file");
        } ਨਹੀਂਤਾਂ ਜੇ (t == ')') {
            ਰੋਕੋ;
        } ਨਹੀਂਤਾਂ ਜੇ (t != LD_TOK_NAME) {
            ਵਾਪਸ tcc_error_noabort("unexpected token '%c'", t);
        } ਨਹੀਂਤਾਂ ਜੇ (!strcmp(filename, "AS_NEEDED")) {
            ret |= ld_ਜੋੜੋ_file_list(s1, filename);
        } ਨਹੀਂਤਾਂ ਜੇ (c == 'I' || c == 'G' || c == 'A') {
            ret |= !!ld_ਜੋੜੋ_file(s1, filename);
        }
        ਜੇ (ret < 0)
            ਵਾਪਸ ret;
        t = ld_ਅਗਲਾ(s1, filename, ਆਕਾਰ(filename));
        ਜੇ (t == ',')
            t = ld_ਅਗਲਾ(s1, filename, ਆਕਾਰ(filename));
    }
    ਜੇ (c == 'G' && ret == 0 && new_undef_sym(s1, sym_ਵਿੱਥ))
        ਜਾਓ repeat;
    ਵਾਪਸ ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC ਪੂਰਨ tcc_ਲੱਦੋ_ldscript(TCCState *s1, ਪੂਰਨ fd)
{
    ਅੱਖਰ cmd[64];
    ਪੂਰਨ t, ret = 0, noscript = 1;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ਪਾਠ_ptr, *saved_ptr;

    saved_ptr = s1->ld_p;
    s1->ld_p = ਪਾਠ_ptr = (ਖਾਲੀ*)tcc_ਲੱਦੋ_ਪਾਠ(fd);
    ਲਈ(;;) {
        t = ld_ਅਗਲਾ(s1, cmd, ਆਕਾਰ(cmd));
        ਜੇ (t == LD_TOK_EOF)
            ਰੋਕੋ;
        ਜੇ (!strcmp(cmd, "INPUT") ||
            !strcmp(cmd, "GROUP")) {
            ret |= ld_ਜੋੜੋ_file_list(s1, cmd);
        } ਨਹੀਂਤਾਂ ਜੇ (!strcmp(cmd, "OUTPUT_FORMAT") ||
                   !strcmp(cmd, "TARGET")) {
            /* ignore some commands */
            ret |= ld_ਜੋੜੋ_file_list(s1, cmd);
        } ਨਹੀਂਤਾਂ ਜੇ (noscript) {
            ret = FILE_NOT_RECOGNIZED;
        } ਨਹੀਂਤਾਂ {
            ret = tcc_error_noabort("unexpected '%s'", cmd);
        }
        ਜੇ (ret < 0)
            ਰੋਕੋ;
        noscript = 0;
    }
    tcc_free(ਪਾਠ_ptr);
    s1->ld_p = saved_ptr;
    ਵਾਪਸ ret < 0 ? ret : -ret;
}
#ਜੇ_ਅੰਤ /* !ELF_OBJ_ONLY */
