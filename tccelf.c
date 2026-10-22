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
#undef DEBUG_RELOC

/********************************************************/
/* global variables */

/* elf version information */
ಸಂರಚನಾ sym_version {
    ವರ್ಣ *lib;
    ವರ್ಣ *version;
    ಪೂರ್ಣಾಙ್ಕ out_index;
    ಪೂರ್ಣಾಙ್ಕ prev_same_lib;
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
ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ rdata[] = ".rdata";
#ಅನ್ಯಥಾ
#define shf_RELRO SHF_ALLOC /* eventually made SHF_WRITE in sort_sections() */
ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ rdata[] = ".data.ro";
#endif

/* ------------------------------------------------------------------------- */

ST_FUNC ಶೂನ್ಯ tccelf_new(TCCState *s)
{
    TCCState *s1 = s;

    /* no section zero */
    dynarray_add(&s->sections, &s->nb_sections, ರಿಕ್ತ);

    /* create standard sections */
    text_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    data_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    /* create ro data section (make ro after relocation done with GNU_RELRO) */
    rodata_section = new_section(s, rdata, SHT_PROGBITS, shf_RELRO);
    bss_section = new_section(s, ".bss", SHT_NOBITS, SHF_ALLOC | SHF_WRITE);
    common_section = new_section(s, ".common", SHT_NOBITS, SHF_PRIVATE);
    common_section->sh_ಅಂಕೆ = SHN_COMMON;

    /* symbols are always generated for linking stage */
    symtab_section = new_symtab(s, ".symtab", SHT_SYMTAB, 0,
                                ".strtab",
                                ".hashtab", SHF_PRIVATE);

    /* private symbol table for dynamic symbols */
    s->dynsymtab_section = new_symtab(s, ".dynsymtab", SHT_SYMTAB, SHF_PRIVATE|SHF_DYNSYM,
                                      ".dynstrtab",
                                      ".dynhashtab", SHF_PRIVATE);
    get_sym_attr(s, 0, 1);

    ಯದಿ (s->do_debug) {
        /* add debug sections */
        tcc_debug_new(s);
    }

#ಯದಿ TCC_EH_FRAME
    ಯದಿ (s->output_format != TCC_OUTPUT_FORMAT_ELF)
        s->unwind_tables = 0;
    tcc_eh_frame_start(s);
#endif

#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        /* (make ro after relocation done with GNU_RELRO) */
        bounds_section = new_section(s, ".bounds", SHT_PROGBITS, shf_RELRO);
        lbounds_section = new_section(s, ".lbounds", SHT_PROGBITS, shf_RELRO);
    }
#endif

#ifdef TCC_TARGET_PE
    /* to make sure that -ltcc1 -Wl,-e,_start will grab the startup code
       from libtcc1.a (unless _start defined) */
    ಯದಿ (s->elf_entryname)
        set_global_sym(s, s->elf_entryname, ರಿಕ್ತ, 0); /* SHN_UNDEF */
#endif

#ifndef ELF_OBJ_ONLY
    ಯದಿ (ರಿಕ್ತ == s->elfint && s1->output_type != TCC_OUTPUT_OBJ) {
        ಧ್ರುವ ವರ್ಣ *p = CONFIG_TCC_ELFINTERP;
#ಯದಿ defined TCC_TARGET_ARM && defined CONFIG_TCC_ELFINTERP_ARMHF
        ಯದಿ (s->float_abi == ARM_HARD_FLOAT)
            p = CONFIG_TCC_ELFINTERP_ARMHF;
#endif
#ಯದಿ defined TCC_IS_NATIVE && defined TARGETOS_BSD
        /* see commit 55cb2170cd5ce77a7d76dcaf462fad2707281605 */
        { ಧ್ರುವ ವರ್ಣ *e = getenv("LD_SO"); ಯದಿ (e) p = e; }
#endif
        s->elfint = tcc_strdup(p);
    }
#endif /* ndef ELF_OBJ_ONLY */
}

ST_FUNC ಶೂನ್ಯ free_section(Section *s)
{
    ಯದಿ (!s)
        ಪ್ರತ್ಯಾಗಮ;
    tcc_free(s->data);
    s->data = ರಿಕ್ತ;
    s->data_allocated = s->data_offset = 0;
}

ST_FUNC ಶೂನ್ಯ tccelf_delete(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ i;

#ifndef ELF_OBJ_ONLY
    /* free symbol versions */
    ಪ್ರತಿ (i = 0; i < nb_sym_versions; i++) {
        tcc_free(sym_versions[i].version);
        tcc_free(sym_versions[i].lib);
    }
    tcc_free(sym_versions);
    tcc_free(sym_to_version);
#endif

    /* free all sections */
    ಪ್ರತಿ(i = 1; i < s1->nb_sections; i++)
        free_section(s1->sections[i]);
    dynarray_reset(&s1->sections, &s1->nb_sections);

    ಪ್ರತಿ(i = 0; i < s1->nb_priv_sections; i++)
        free_section(s1->priv_sections[i]);
    dynarray_reset(&s1->priv_sections, &s1->nb_priv_sections);

    tcc_free(s1->sym_attrs);
    symtab_section = ರಿಕ್ತ; /* for tccrun.c:rt_printline() */
}

/* save section data state */
ST_FUNC ಶೂನ್ಯ tccelf_begin_file(TCCState *s1)
{
    Section *s; ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        s->sh_offset = s->data_offset;
    }
    /* disable symbol hashing during compilation */
    s = s1->symtab, s->reloc = s->hash, s->hash = ರಿಕ್ತ;
#ಯದಿ defined TCC_TARGET_X86_64 && defined TCC_TARGET_PE
    s1->uw_sym = 0;
    s1->uw_offs = 0;
#endif
}

ಸ್ಥಿರ ಶೂನ್ಯ update_relocs(TCCState *s1, Section *s, ಪೂರ್ಣಾಙ್ಕ *old_to_new_syms, ಪೂರ್ಣಾಙ್ಕ first_sym);

/* At the end of compilation, convert any UNDEF syms to global, and merge
   with previously existing symbols */
ST_FUNC ಶೂನ್ಯ tccelf_end_file(TCCState *s1)
{
    Section *s = s1->symtab;
    ಪೂರ್ಣಾಙ್ಕ first_sym, nb_syms, *tr, i;

    first_sym = s->sh_offset / ಪರಿಮಾಣ (ElfSym);
    nb_syms = s->data_offset / ಪರಿಮಾಣ (ElfSym) - first_sym;
    s->data_offset = s->sh_offset;
    s->link->data_offset = s->link->sh_offset;
    s->hash = s->reloc, s->reloc = ರಿಕ್ತ;
    tr = tcc_mallocz(nb_syms * ಪರಿಮಾಣ *tr);

    ಪ್ರತಿ (i = 0; i < nb_syms; ++i) {
        ElfSym *sym = (ElfSym*)s->data + first_sym + i;
        ಯದಿ (sym->st_shndx == SHN_UNDEF) {
            ಪೂರ್ಣಾಙ್ಕ sym_bind = ELFW(ST_BIND)(sym->st_info);
            ಪೂರ್ಣಾಙ್ಕ sym_type = ELFW(ST_TYPE)(sym->st_info);
            ಯದಿ (sym_bind == STB_LOCAL)
                sym_bind = STB_GLOBAL;
#ifndef TCC_TARGET_PE
            ಯದಿ (sym_bind == STB_GLOBAL && s1->output_type == TCC_OUTPUT_OBJ) {
                /* undefined symbols with STT_FUNC are confusing gnu ld when
                   linking statically to STT_GNU_IFUNC.  Keep TLS typed,
                   otherwise gnu ld rejects non-TLS refs to TLS definitions. */
                ಯದಿ (sym_type != STT_TLS)
                    sym_type = STT_NOTYPE;
            }
#endif
            sym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
        }
        tr[i] = set_elf_sym(s, sym->st_ಮೌಲ್ಯ, sym->st_size, sym->st_info,
            sym->st_other, sym->st_shndx, (ವರ್ಣ*)s->link->data + sym->st_name);
    }
    /* now update relocations */
    update_relocs(s1, s, tr, first_sym);
    tcc_free(tr);
    /* record text/data/bss output for -bench info */
    ಪ್ರತಿ (i = 0; i < 4; ++i) {
        s = s1->sections[i + 1];
        s1->total_output[i] += s->data_offset - s->sh_offset;
    }
}

ST_FUNC Section *new_section(TCCState *s1, ಧ್ರುವ ವರ್ಣ *name, ಪೂರ್ಣಾಙ್ಕ sh_type, ಪೂರ್ಣಾಙ್ಕ sh_flags)
{
    Section *sec;

    sec = tcc_mallocz(ಪರಿಮಾಣ(Section) + strlen(name));
    sec->s1 = s1;
    strcpy(sec->name, name);
    sec->sh_type = sh_type;
    sec->sh_flags = sh_flags;
    ವಿಕಲ್ಪ(sh_type) {
    ಪಕ್ಷ SHT_GNU_versym:
        sec->sh_addralign = 2;
        ಭಙ್ಗ;
    ಪಕ್ಷ SHT_HASH:
    ಪಕ್ಷ SHT_GNU_HASH:
    ಪಕ್ಷ SHT_REL:
    ಪಕ್ಷ SHT_RELA:
    ಪಕ್ಷ SHT_DYNSYM:
    ಪಕ್ಷ SHT_SYMTAB:
    ಪಕ್ಷ SHT_DYNAMIC:
    ಪಕ್ಷ SHT_GNU_verneed:
    ಪಕ್ಷ SHT_GNU_verdef:
        sec->sh_addralign = PTR_SIZE;
        ಭಙ್ಗ;
    ಪಕ್ಷ SHT_STRTAB:
        sec->sh_addralign = 1;
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        sec->sh_addralign =  PTR_SIZE; /* gcc/pcc default alignment */
        ಭಙ್ಗ;
    }

    ಯದಿ (sh_flags & SHF_PRIVATE) {
        dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } ಅನ್ಯಥಾ {
        sec->sh_ಅಂಕೆ = s1->nb_sections;
        dynarray_add(&s1->sections, &s1->nb_sections, sec);
    }

    ಪ್ರತ್ಯಾಗಮ sec;
}

ST_FUNC ಶೂನ್ಯ init_symtab(Section *s)
{
    ಪೂರ್ಣಾಙ್ಕ *ptr, nb_buckets = 1;
    put_elf_str(s->link, "");
    section_ptr_add(s, ಪರಿಮಾಣ (ElfW(Sym)));
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + 1) * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
    ptr[0] = nb_buckets;
    ptr[1] = 1;
    memset(ptr + 2, 0, (nb_buckets + 1) * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
}

ST_FUNC Section *new_symtab(TCCState *s1,
                           ಧ್ರುವ ವರ್ಣ *symtab_name, ಪೂರ್ಣಾಙ್ಕ sh_type, ಪೂರ್ಣಾಙ್ಕ sh_flags,
                           ಧ್ರುವ ವರ್ಣ *strtab_name,
                           ಧ್ರುವ ವರ್ಣ *hash_name, ಪೂರ್ಣಾಙ್ಕ hash_sh_flags)
{
    Section *symtab, *strtab, *hash;
    symtab = new_section(s1, symtab_name, sh_type, sh_flags);
    symtab->sh_entsize = ಪರಿಮಾಣ(ElfW(Sym));
    strtab = new_section(s1, strtab_name, SHT_STRTAB, sh_flags);
    symtab->link = strtab;
    hash = new_section(s1, hash_name, SHT_HASH, hash_sh_flags);
    hash->sh_entsize = ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ);
    symtab->hash = hash;
    hash->link = symtab;
    init_symtab(symtab);
    ಪ್ರತ್ಯಾಗಮ symtab;
}

/* realloc section and set its content to zero */
ST_FUNC ಶೂನ್ಯ section_realloc(Section *sec, unsigned long new_size)
{
    unsigned long size;
    unsigned ವರ್ಣ *data;

    size = sec->data_allocated;
    ಯದಿ (size == 0)
        size = 1;
    ಯಾವತ್ (size < new_size)
        size = size * 2;
    data = tcc_realloc(sec->data, size);
    memset(data + sec->data_allocated, 0, size - sec->data_allocated);
    sec->data = data;
    sec->data_allocated = size;
}

/* reserve at least 'size' bytes aligned per 'align' in section
   'sec' from current offset, and return the aligned offset */
ST_FUNC size_t section_add(Section *sec, addr_t size, ಪೂರ್ಣಾಙ್ಕ align)
{
    size_t offset, offset1;

    offset = (sec->data_offset + align - 1) & -align;
    offset1 = offset + size;
    ಯದಿ (sec->sh_type != SHT_NOBITS && offset1 > sec->data_allocated)
        section_realloc(sec, offset1);
    sec->data_offset = offset1;
    ಯದಿ (align > sec->sh_addralign)
        sec->sh_addralign = align;
    ಪ್ರತ್ಯಾಗಮ offset;
}

/* reserve at least 'size' bytes in section 'sec' from
   sec->data_offset. */
ST_FUNC ಶೂನ್ಯ *section_ptr_add(Section *sec, addr_t size)
{
    size_t offset = section_add(sec, size, 1);
    ಪ್ರತ್ಯಾಗಮ sec->data + offset;
}

#ifndef ELF_OBJ_ONLY
/* reserve at least 'size' bytes from section start */
ಸ್ಥಿರ ಶೂನ್ಯ section_reserve(Section *sec, unsigned long size)
{
    ಯದಿ (size > sec->data_allocated)
        section_realloc(sec, size);
    ಯದಿ (size > sec->data_offset)
        sec->data_offset = size;
}
#endif

ಸ್ಥಿರ Section *have_section(TCCState *s1, ಧ್ರುವ ವರ್ಣ *name)
{
    Section *sec;
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ(i = 1; i < s1->nb_sections; i++) {
        sec = s1->sections[i];
        ಯದಿ (!strcmp(name, sec->name))
            ಪ್ರತ್ಯಾಗಮ sec;
    }
    ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
}

/* return a reference to a section, and create it if it does not
   exists */
ST_FUNC Section *find_section(TCCState *s1, ಧ್ರುವ ವರ್ಣ *name)
{
    Section *sec = have_section(s1, name);
    ಯದಿ (sec)
        ಪ್ರತ್ಯಾಗಮ sec;
    /* sections are created as PROGBITS */
    ಪ್ರತ್ಯಾಗಮ new_section(s1, name, SHT_PROGBITS, SHF_ALLOC);
}

/* ------------------------------------------------------------------------- */

ST_FUNC ಪೂರ್ಣಾಙ್ಕ put_elf_str(Section *s, ಧ್ರುವ ವರ್ಣ *sym)
{
    ಪೂರ್ಣಾಙ್ಕ offset, len;
    ವರ್ಣ *ptr;

    len = strlen(sym) + 1;
    offset = s->data_offset;
    ptr = section_ptr_add(s, len);
    memmove(ptr, sym, len);
    ಪ್ರತ್ಯಾಗಮ offset;
}

/* elf symbol hashing function */
ಸ್ಥಿರ ElfW(Word) elf_hash(ಧ್ರುವ unsigned ವರ್ಣ *name)
{
    ElfW(Word) h = 0, g;

    ಯಾವತ್ (*name) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        ಯದಿ (g)
            h ^= g >> 24;
        h &= ~g;
    }
    ಪ್ರತ್ಯಾಗಮ h;
}

/* rebuild hash table of section s */
/* NOTE: we do factorize the hash table code to go faster */
ಸ್ಥಿರ ಶೂನ್ಯ rebuild_hash(Section *s, unsigned ಪೂರ್ಣಾಙ್ಕ nb_buckets)
{
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಙ್ಕ *ptr, *hash, nb_syms, sym_index, h;
    unsigned ವರ್ಣ *strtab;

    strtab = s->link->data;
    nb_syms = s->data_offset / ಪರಿಮಾಣ(ElfW(Sym));

    ಯದಿ (!nb_buckets)
        nb_buckets = ((ಪೂರ್ಣಾಙ್ಕ*)s->hash->data)[0];

    s->hash->data_offset = 0;
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + nb_syms) * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    memset(hash, 0, (nb_buckets + 1) * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
    ptr += nb_buckets + 1;

    sym = (ElfW(Sym) *)s->data + 1;
    ಪ್ರತಿ(sym_index = 1; sym_index < nb_syms; sym_index++) {
        ಯದಿ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            h = elf_hash(strtab + sym->st_name) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_index;
        } ಅನ್ಯಥಾ {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}

/* return the symbol number */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ put_elf_sym(Section *s, addr_t ಮೌಲ್ಯ, unsigned long size,
    ಪೂರ್ಣಾಙ್ಕ info, ಪೂರ್ಣಾಙ್ಕ other, ಪೂರ್ಣಾಙ್ಕ shndx, ಧ್ರುವ ವರ್ಣ *name)
{
    ಪೂರ್ಣಾಙ್ಕ name_offset, sym_index;
    ಪೂರ್ಣಾಙ್ಕ nbuckets, h;
    ElfW(Sym) *sym;
    Section *hs;

    sym = section_ptr_add(s, ಪರಿಮಾಣ(ElfW(Sym)));
    ಯದಿ (name && name[0])
        name_offset = put_elf_str(s->link, name);
    ಅನ್ಯಥಾ
        name_offset = 0;
    /* XXX: endianness */
    sym->st_name = name_offset;
    sym->st_ಮೌಲ್ಯ = ಮೌಲ್ಯ;
    sym->st_size = size;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
    sym_index = sym - (ElfW(Sym) *)s->data;
    hs = s->hash;
    ಯದಿ (hs) {
        ಪೂರ್ಣಾಙ್ಕ *ptr, *base;
        ptr = section_ptr_add(hs, ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
        base = (ಪೂರ್ಣಾಙ್ಕ *)hs->data;
        /* only add global or weak symbols. */
        ಯದಿ (ELFW(ST_BIND)(info) != STB_LOCAL) {
            /* add another hashing entry */
            nbuckets = base[0];
            h = elf_hash((unsigned ವರ್ಣ *)s->link->data + name_offset) % nbuckets;
            *ptr = base[2 + h];
            base[2 + h] = sym_index;
            base[1]++;
            /* we resize the hash table */
            hs->nb_hashed_syms++;
            ಯದಿ (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } ಅನ್ಯಥಾ {
            *ptr = 0;
            base[1]++;
        }
    }
    ಪ್ರತ್ಯಾಗಮ sym_index;
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ find_elf_sym(Section *s, ಧ್ರುವ ವರ್ಣ *name)
{
    ElfW(Sym) *sym;
    Section *hs;
    ಪೂರ್ಣಾಙ್ಕ nbuckets, sym_index, h;
    ಧ್ರುವ ವರ್ಣ *name1;

    hs = s->hash;
    ಯದಿ (!hs)
        ಪ್ರತ್ಯಾಗಮ 0;
    nbuckets = ((ಪೂರ್ಣಾಙ್ಕ *)hs->data)[0];
    h = elf_hash((unsigned ವರ್ಣ *) name) % nbuckets;
    sym_index = ((ಪೂರ್ಣಾಙ್ಕ *)hs->data)[2 + h];
    ಯಾವತ್ (sym_index != 0) {
        sym = &((ElfW(Sym) *)s->data)[sym_index];
        name1 = (ವರ್ಣ *) s->link->data + sym->st_name;
        ಯದಿ (!strcmp(name, name1))
            ಪ್ರತ್ಯಾಗಮ sym_index;
        sym_index = ((ಪೂರ್ಣಾಙ್ಕ *)hs->data)[2 + nbuckets + sym_index];
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* return elf symbol value, signal error if 'err' is nonzero, decorate
   name if FORC */
ST_FUNC addr_t get_sym_addr(TCCState *s1, ಧ್ರುವ ವರ್ಣ *name, ಪೂರ್ಣಾಙ್ಕ err, ಪೂರ್ಣಾಙ್ಕ forc)
{
    ಪೂರ್ಣಾಙ್ಕ sym_index;
    ElfW(Sym) *sym;
    ವರ್ಣ buf[256];
    ಯದಿ (forc && s1->leading_underscore
#ifdef TCC_TARGET_PE
        /* win32-32bit stdcall symbols always have _ already */
        && !strchr(name, '@')
#endif
        ) {
        buf[0] = '_';
        pstrcpy(buf + 1, ಪರಿಮಾಣ(buf) - 1, name);
        name = buf;
    }
    sym_index = find_elf_sym(s1->symtab, name);
    sym = &((ElfW(Sym) *)s1->symtab->data)[sym_index];
    ಯದಿ (!sym_index || sym->st_shndx == SHN_UNDEF) {
        ಯದಿ (err)
            tcc_error_noabort("%s not defined", name);
        ಪ್ರತ್ಯಾಗಮ (addr_t)-1;
    }
    ಪ್ರತ್ಯಾಗಮ sym->st_ಮೌಲ್ಯ;
}

/* return elf symbol value */
LIBTCCAPI ಶೂನ್ಯ *tcc_get_ಚಿಹ್ನೆ(TCCState *s, ಧ್ರುವ ವರ್ಣ *name)
{
    addr_t addr = get_sym_addr(s, name, 0, 1);
    ಪ್ರತ್ಯಾಗಮ addr == -1 ? ರಿಕ್ತ : (ಶೂನ್ಯ*)(uintptr_t)addr;
}

LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_add_ಚಿಹ್ನೆ(TCCState *s1, ಧ್ರುವ ವರ್ಣ *name, ಧ್ರುವ ಶೂನ್ಯ *val)
{
#ifdef TCC_TARGET_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s1, 0, name, (uintptr_t)val);
#ಅನ್ಯಥಾ
    ವರ್ಣ buf[256];
    ಯದಿ (s1->leading_underscore) {
        buf[0] = '_';
        pstrcpy(buf + 1, ಪರಿಮಾಣ(buf) - 1, name);
        name = buf;
    }
    set_global_sym(s1, name, ರಿಕ್ತ, (addr_t)(uintptr_t)val); /* NULL: SHN_ABS */
#endif
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* list elf symbol names and values */
ST_FUNC ಶೂನ್ಯ list_elf_symbols(TCCState *s, ಶೂನ್ಯ *ctx,
    ಶೂನ್ಯ (*ಚಿಹ್ನೆ_cb)(ಶೂನ್ಯ *ctx, ಧ್ರುವ ವರ್ಣ *name, ಧ್ರುವ ಶೂನ್ಯ *val))
{
    ElfW(Sym) *sym;
    Section *symtab;
    ಪೂರ್ಣಾಙ್ಕ sym_index, end_sym;
    ಧ್ರುವ ವರ್ಣ *name;
    unsigned ವರ್ಣ sym_vis, sym_bind;

    symtab = s->symtab;
    end_sym = symtab->data_offset / ಪರಿಮಾಣ (ElfSym);
    ಪ್ರತಿ (sym_index = 0; sym_index < end_sym; ++sym_index) {
        sym = &((ElfW(Sym) *)symtab->data)[sym_index];
        ಯದಿ (sym->st_ಮೌಲ್ಯ) {
            name = (ವರ್ಣ *) symtab->link->data + sym->st_name;
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            sym_vis = ELFW(ST_VISIBILITY)(sym->st_other);
            ಯದಿ (sym_bind == STB_GLOBAL && sym_vis == STV_DEFAULT)
                ಚಿಹ್ನೆ_cb(ctx, name, (ಶೂನ್ಯ*)(uintptr_t)sym->st_ಮೌಲ್ಯ);
        }
    }
}

/* list elf symbol names and values */
LIBTCCAPI ಶೂನ್ಯ tcc_list_symbols(TCCState *s, ಶೂನ್ಯ *ctx,
    ಶೂನ್ಯ (*ಚಿಹ್ನೆ_cb)(ಶೂನ್ಯ *ctx, ಧ್ರುವ ವರ್ಣ *name, ಧ್ರುವ ಶೂನ್ಯ *val))
{
    list_elf_symbols(s, ctx, ಚಿಹ್ನೆ_cb);
}

#ifndef ELF_OBJ_ONLY
ಸ್ಥಿರ ಶೂನ್ಯ
version_add (TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ElfW(Sym) *sym;
    ElfW(Verneed) *vn = ರಿಕ್ತ;
    Section *symtab;
    ಪೂರ್ಣಾಙ್ಕ sym_index, end_sym, nb_versions = 2, nb_entries = 0;
    ElfW(Half) *versym;
    ಧ್ರುವ ವರ್ಣ *name;

    ಯದಿ (0 == nb_sym_versions)
        ಪ್ರತ್ಯಾಗಮ;
    versym_section = new_section(s1, ".gnu.version", SHT_GNU_versym, SHF_ALLOC);
    versym_section->sh_entsize = ಪರಿಮಾಣ(ElfW(Half));
    versym_section->link = s1->dynsym;

    /* add needed symbols */
    symtab = s1->dynsym;
    end_sym = symtab->data_offset / ಪರಿಮಾಣ (ElfSym);
    versym = section_ptr_add(versym_section, end_sym * ಪರಿಮಾಣ(ElfW(Half)));
    ಪ್ರತಿ (sym_index = 1; sym_index < end_sym; ++sym_index) {
        ಪೂರ್ಣಾಙ್ಕ dllindex, verndx;
        sym = &((ElfW(Sym) *)symtab->data)[sym_index];
        name = (ವರ್ಣ *) symtab->link->data + sym->st_name;
        dllindex = find_elf_sym(s1->dynsymtab_section, name);
        verndx = (dllindex && dllindex < nb_sym_to_version)
                 ? sym_to_version[dllindex] : -1;
        ಯದಿ (verndx >= 0
            /* XXX: on android, clang refuses to link with a libtcc.so made by tcc
               when defined symbols have a version > 1 or when the version is '0'.
               Whereas version '1' for example for 'signal' in an exe defeats
               bcheck's signal_redir. */
            && (sym->st_shndx == SHN_UNDEF || (s1->output_type & TCC_OUTPUT_EXE))
            ) {
            ಯದಿ (!sym_versions[verndx].out_index)
              sym_versions[verndx].out_index = nb_versions++;
            versym[sym_index] = sym_versions[verndx].out_index;
        } ಅನ್ಯಥಾ {
            versym[sym_index] = 1; /* (*global*) */
        }
        //printf("SYM %d %s\n", versym[sym_index], name);
    }
    /* generate verneed section, but not when it will be empty.  Some
       dynamic linkers look at their contents even when DTVERNEEDNUM and
       section size is zero.  */
    ಯದಿ (nb_versions > 2) {
        verneed_section = new_section(s1, ".gnu.version_r",
                                      SHT_GNU_verneed, SHF_ALLOC);
        verneed_section->link = s1->dynsym->link;
        ಪ್ರತಿ (i = nb_sym_versions; i-- > 0;) {
            ಸಂರಚನಾ sym_version *sv = &sym_versions[i];
            ಪೂರ್ಣಾಙ್ಕ n_same_libs = 0, prev;
            size_t vnofs;
            ElfW(Vernaux) *vna = 0;
            ಯದಿ (sv->out_index < 1)
              ಅನುವರ್ತ;

            /* make sure that a DT_NEEDED tag is put */
            /* abitest-tcc fails on older i386-linux with "ld-linux.so.2" DT_NEEDED
               ret_int_test... Inconsistency detected by ld.so: dl-minimal.c: 148:
               realloc: Assertion `ptr == alloc_last_block' failed! */
            ಯದಿ (strcmp(sv->lib, "ld-linux.so.2"))
                tcc_add_dllref(s1, sv->lib, 0);

            vnofs = section_add(verneed_section, ಪರಿಮಾಣ(*vn), 1);
            vn = (ElfW(Verneed)*)(verneed_section->data + vnofs);
            vn->vn_version = 1;
            vn->vn_file = put_elf_str(verneed_section->link, sv->lib);
            vn->vn_aux = ಪರಿಮಾಣ (*vn);
            ಕುರು {
                prev = sv->prev_same_lib;
                ಯದಿ (sv->out_index > 0) {
                    vna = section_ptr_add(verneed_section, ಪರಿಮಾಣ(*vna));
                    vna->vna_hash = elf_hash ((ಧ್ರುವ unsigned ವರ್ಣ *)sv->version);
                    vna->vna_flags = 0;
                    vna->vna_other = sv->out_index;
                    sv->out_index = -2;
                    vna->vna_name = put_elf_str(verneed_section->link, sv->version);
                    vna->vna_next = ಪರಿಮಾಣ (*vna);
                    //printf("LIB %d %s %s\n", vna->vna_other, sv->lib, verneed_section->link->data + vna->vna_name);
                    n_same_libs++;
                }
                ಯದಿ (prev >= 0)
                  sv = &sym_versions[prev];
            } ಯಾವತ್(prev >= 0);
            vna->vna_next = 0;
            vn = (ElfW(Verneed)*)(verneed_section->data + vnofs);
            vn->vn_cnt = n_same_libs;
            vn->vn_next = ಪರಿಮಾಣ(*vn) + n_same_libs * ಪರಿಮಾಣ(*vna);
            nb_entries++;
        }
        ಯದಿ (vn)
          vn->vn_next = 0;
        verneed_section->sh_info = nb_entries;
    }
    dt_verneednum = nb_entries;
}
#endif /* ndef ELF_OBJ_ONLY */

/* catch .tbss also */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ IS_BSS(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ ndx)
{
    ಪ್ರತ್ಯಾಗಮ ndx == SHN_COMMON
     || (ndx < s1->nb_sections
         && s1->sections[ndx]->sh_type == SHT_NOBITS);
}

/* add an elf symbol : check if it is already defined and patch
   it. Return symbol index. NOTE that sh_num can be SHN_UNDEF. */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ set_elf_sym(Section *s, addr_t ಮೌಲ್ಯ, unsigned long size,
                       ಪೂರ್ಣಾಙ್ಕ info, ಪೂರ್ಣಾಙ್ಕ other, ಪೂರ್ಣಾಙ್ಕ shndx, ಧ್ರುವ ವರ್ಣ *name)
{
    TCCState *s1 = s->s1;
    ElfW(Sym) *esym;
    ಪೂರ್ಣಾಙ್ಕ sym_bind, sym_index, sym_type, esym_bind;
    unsigned ವರ್ಣ sym_vis, esym_vis, new_vis;

    sym_bind = ELFW(ST_BIND)(info);
    sym_type = ELFW(ST_TYPE)(info);
    sym_vis = ELFW(ST_VISIBILITY)(other);

    ಯದಿ (sym_bind != STB_LOCAL) {
        /* we search global or weak symbols */
        sym_index = find_elf_sym(s, name);
        ಯದಿ (!sym_index)
            ಗಚ್ಛ do_def;
        esym = &((ElfW(Sym) *)s->data)[sym_index];
        ಯದಿ (esym->st_ಮೌಲ್ಯ == ಮೌಲ್ಯ && esym->st_size == size && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            ಪ್ರತ್ಯಾಗಮ sym_index;
        ಯದಿ (esym->st_shndx != SHN_UNDEF) {
            esym_bind = ELFW(ST_BIND)(esym->st_info);
            /* propagate the most constraining visibility */
            /* STV_DEFAULT(0)<STV_PROTECTED(3)<STV_HIDDEN(2)<STV_INTERNAL(1) */
            esym_vis = ELFW(ST_VISIBILITY)(esym->st_other);
            ಯದಿ (esym_vis == STV_DEFAULT) {
                new_vis = sym_vis;
            } ಅನ್ಯಥಾ ಯದಿ (sym_vis == STV_DEFAULT) {
                new_vis = esym_vis;
            } ಅನ್ಯಥಾ {
                new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
            }
            esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
                             | new_vis;
            ಯದಿ (shndx == SHN_UNDEF) {
                /* ignore adding of undefined symbol if the
                   corresponding symbol is already defined */
            } ಅನ್ಯಥಾ ಯದಿ (sym_bind == STB_GLOBAL && esym_bind == STB_WEAK) {
                /* global overrides weak, so patch */
                ಗಚ್ಛ do_patch;
            } ಅನ್ಯಥಾ ಯದಿ (sym_bind == STB_WEAK && esym_bind == STB_GLOBAL) {
                /* weak is ignored if already global */
            } ಅನ್ಯಥಾ ಯದಿ (sym_bind == STB_WEAK && esym_bind == STB_WEAK) {
                /* keep first-found weak definition, ignore subsequents */
            } ಅನ್ಯಥಾ ಯದಿ (sym_vis == STV_HIDDEN || sym_vis == STV_INTERNAL) {
                /* ignore hidden symbols after */
            } ಅನ್ಯಥಾ ಯದಿ (s->sh_flags & SHF_DYNSYM) {
                /* we accept that two DLL define the same symbol */
            } ಅನ್ಯಥಾ ಯದಿ (!IS_BSS(s1, shndx) && IS_BSS(s1, esym->st_shndx)) {
                /* data symbol gets precedence over common/bss */
                ಗಚ್ಛ do_patch;
            } ಅನ್ಯಥಾ ಯದಿ (IS_BSS(s1, shndx)) {
                /* data symbol keeps precedence over common/bss */
	    } ಅನ್ಯಥಾ ಯದಿ (esym->st_other & ST_ASM_SET) {
		/* If the existing symbol came from an asm .set
		   we can override.  */
		ಗಚ್ಛ do_patch;
            } ಅನ್ಯಥಾ {
#ಯದಿ 0
                printf("new_bind=%x new_shndx=%x new_vis=%x old_bind=%x old_shndx=%x old_vis=%x\n",
                       sym_bind, shndx, new_vis, esym_bind, esym->st_shndx, esym_vis);
#endif
                tcc_error_noabort("link symbol '%s' defined twice", name);
            }
        } ಅನ್ಯಥಾ {
            esym->st_other = other;
        do_patch:
            esym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
            esym->st_shndx = shndx;
            esym->st_ಮೌಲ್ಯ = ಮೌಲ್ಯ;
            esym->st_size = size;
        }
    } ಅನ್ಯಥಾ {
    do_def:
        sym_index = put_elf_sym(s, ಮೌಲ್ಯ, size,
                                ELFW(ST_INFO)(sym_bind, sym_type), other,
                                shndx, name);
    }
    ಪ್ರತ್ಯಾಗಮ sym_index;
}

/* put relocation */
ST_FUNC ಶೂನ್ಯ put_elf_reloca(Section *symtab, Section *s, unsigned long offset,
                            ಪೂರ್ಣಾಙ್ಕ type, ಪೂರ್ಣಾಙ್ಕ ಚಿಹ್ನೆ, addr_t addend)
{
    TCCState *s1 = s->s1;
    ವರ್ಣ buf[256];
    Section *sr;
    ElfW_Rel *rel;

    sr = s->reloc;
    ಯದಿ (!sr) {
        /* if no relocation section, create it */
        snprintf(buf, ಪರಿಮಾಣ(buf), REL_SECTION_FMT, s->name);
        /* if the symtab is allocated, then we consider the relocation
           are also */
        sr = new_section(s->s1, buf, SHT_RELX, symtab->sh_flags);
        sr->sh_entsize = ಪರಿಮಾಣ(ElfW_Rel);
        sr->link = symtab;
        sr->sh_info = s->sh_ಅಂಕೆ;
        s->reloc = sr;
    }
    rel = section_ptr_add(sr, ಪರಿಮಾಣ(ElfW_Rel));
    rel->r_offset = offset;
    rel->r_info = ELFW(R_INFO)(ಚಿಹ್ನೆ, type);
#ಯದಿ SHT_RELX == SHT_RELA
    rel->r_addend = addend;
#endif
    ಯದಿ (SHT_RELX != SHT_RELA && addend)
        tcc_error_noabort("non-zero addend on REL architecture");
}

ST_FUNC ಶೂನ್ಯ put_elf_reloc(Section *symtab, Section *s, unsigned long offset,
                           ಪೂರ್ಣಾಙ್ಕ type, ಪೂರ್ಣಾಙ್ಕ ಚಿಹ್ನೆ)
{
    put_elf_reloca(symtab, s, offset, type, ಚಿಹ್ನೆ, 0);
}

ST_FUNC ಸಂರಚನಾ sym_attr *get_sym_attr(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ index, ಪೂರ್ಣಾಙ್ಕ alloc)
{
    ಪೂರ್ಣಾಙ್ಕ n;
    ಸಂರಚನಾ sym_attr *tab;

    ಯದಿ (index >= s1->nb_sym_attrs) {
        ಯದಿ (!alloc)
            ಪ್ರತ್ಯಾಗಮ s1->sym_attrs;
        /* find immediately bigger power of 2 and reallocate array */
        n = 1;
        ಯಾವತ್ (index >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * ಪರಿಮಾಣ(*s1->sym_attrs));
        s1->sym_attrs = tab;
        memset(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * ಪರಿಮಾಣ(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    ಪ್ರತ್ಯಾಗಮ &s1->sym_attrs[index];
}

ಸ್ಥಿರ ಶೂನ್ಯ update_relocs(TCCState *s1, Section *s, ಪೂರ್ಣಾಙ್ಕ *old_to_new_syms, ಪೂರ್ಣಾಙ್ಕ first_sym)
{
    ಪೂರ್ಣಾಙ್ಕ i, type, sym_index;
    Section *sr;
    ElfW_Rel *rel;

    ಪ್ರತಿ(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        ಯದಿ (sr->sh_type == SHT_RELX && sr->link == s) {
            for_each_elem(sr, 0, rel, ElfW_Rel) {
                sym_index = ELFW(R_SYM)(rel->r_info);
                type = ELFW(R_TYPE)(rel->r_info);
                ಯದಿ ((sym_index -= first_sym) < 0)
                    ಅನುವರ್ತ; /* zero sym_index in reloc (can happen with asm) */
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
ಸ್ಥಿರ ಶೂನ್ಯ sort_syms(TCCState *s1, Section *s)
{
    ಪೂರ್ಣಾಙ್ಕ *old_to_new_syms;
    ElfW(Sym) *new_syms;
    ಪೂರ್ಣಾಙ್ಕ nb_syms, i;
    ElfW(Sym) *p, *q;

    nb_syms = s->data_offset / ಪರಿಮಾಣ(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * ಪರಿಮಾಣ(ElfW(Sym)));
    old_to_new_syms = tcc_malloc(nb_syms * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));

    /* first pass for local symbols */
    p = (ElfW(Sym) *)s->data;
    q = new_syms;
    ಪ್ರತಿ(i = 0; i < nb_syms; i++) {
        ಯದಿ (ELFW(ST_BIND)(p->st_info) == STB_LOCAL) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    /* save the number of local symbols in section header */
    ಯದಿ( s->sh_size )    /* this 'if' makes IDA happy */
        s->sh_info = q - new_syms;

    /* then second pass for non local symbols */
    p = (ElfW(Sym) *)s->data;
    ಪ್ರತಿ(i = 0; i < nb_syms; i++) {
        ಯದಿ (ELFW(ST_BIND)(p->st_info) != STB_LOCAL) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }

    /* we copy the new symbols to the old */
    memcpy(s->data, new_syms, nb_syms * ಪರಿಮಾಣ(ElfW(Sym)));
    tcc_free(new_syms);

    update_relocs(s1, s, old_to_new_syms, 0);
    tcc_free(old_to_new_syms);
}

#ifndef ELF_OBJ_ONLY
/* See: https://flapenguin.me/elf-dt-gnu-hash */
#define	ELFCLASS_BITS (PTR_SIZE * 8)

ಸ್ಥಿರ Section *create_gnu_hash(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ nb_syms, i, ndef, nbuckets, symoffset, bloom_size, bloom_shift;
    ElfW(Sym) *p;
    Section *gnu_hash;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr;

    gnu_hash = new_section(s1, ".gnu.hash", SHT_GNU_HASH, SHF_ALLOC);
    gnu_hash->link = dynsym->hash->link;

    nb_syms = dynsym->data_offset / ಪರಿಮಾಣ(ElfW(Sym));

    /* count def symbols */
    ndef = 0;
    p = (ElfW(Sym) *)dynsym->data;
    ಪ್ರತಿ(i = 0; i < nb_syms; i++, p++)
        ndef += p->st_shndx != SHN_UNDEF;

    /* calculate gnu hash sizes and fill header */
    nbuckets = ndef / 4 + 1;
    symoffset = nb_syms - ndef;
    bloom_shift = PTR_SIZE == 8 ? 6 : 5;
    bloom_size = 1; /* must be power of two */
    ಯಾವತ್ (ndef >= bloom_size * (1 << (bloom_shift - 3)))
	bloom_size *= 2;
    ptr = section_ptr_add(gnu_hash, 4 * 4 +
				    PTR_SIZE * bloom_size +
				    nbuckets * 4 +
				    ndef * 4);
    ptr[0] = nbuckets;
    ptr[1] = symoffset;
    ptr[2] = bloom_size;
    ptr[3] = bloom_shift;
    ಪ್ರತ್ಯಾಗಮ gnu_hash;
}

ಸ್ಥಿರ Elf32_Word elf_gnu_hash (ಧ್ರುವ unsigned ವರ್ಣ *name)
{
    Elf32_Word h = 5381;
    unsigned ವರ್ಣ c;

    ಯಾವತ್ ((c = *name++))
        h = h * 33 + c;
    ಪ್ರತ್ಯಾಗಮ h;
}

ಸ್ಥಿರ ಶೂನ್ಯ update_gnu_hash(TCCState *s1, Section *gnu_hash)
{
    ಪೂರ್ಣಾಙ್ಕ *old_to_new_syms;
    ElfW(Sym) *new_syms;
    ಪೂರ್ಣಾಙ್ಕ nb_syms, i, nbuckets, bloom_size, bloom_shift;
    ElfW(Sym) *p, *q;
    Section *vs;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr, *buckets, *chain, *hash;
    unsigned ಪೂರ್ಣಾಙ್ಕ *nextbuck;
    addr_t *bloom;
    unsigned ವರ್ಣ *strtab;
    ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ first, last; } *buck;

    strtab = dynsym->link->data;
    nb_syms = dynsym->data_offset / ಪರಿಮಾಣ(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * ಪರಿಮಾಣ(ElfW(Sym)));
    old_to_new_syms = tcc_malloc(nb_syms * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
    hash = tcc_malloc(nb_syms * ಪರಿಮಾಣ(Elf32_Word));
    nextbuck = tcc_malloc(nb_syms * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));

    /* calculate hashes and copy undefs */
    p = (ElfW(Sym) *)dynsym->data;
    q = new_syms;
    ಪ್ರತಿ(i = 0; i < nb_syms; i++, p++) {
        ಯದಿ (p->st_shndx == SHN_UNDEF) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
	ಅನ್ಯಥಾ
	    hash[i] = elf_gnu_hash(strtab + p->st_name);
    }

    ptr = (Elf32_Word *) gnu_hash->data;
    nbuckets = ptr[0];
    bloom_size = ptr[2];
    bloom_shift = ptr[3];
    bloom = (addr_t *) (ಶೂನ್ಯ *) &ptr[4];
    buckets = (Elf32_Word*) (ಶೂನ್ಯ *) &bloom[bloom_size];
    chain = &buckets[nbuckets];
    buck = tcc_malloc(nbuckets * ಪರಿಮಾಣ(*buck));

    ಯದಿ (gnu_hash->data_offset != 4 * 4 +
				 PTR_SIZE * bloom_size +
				 nbuckets * 4 +
				 (nb_syms - (q - new_syms)) * 4)
	tcc_error_noabort ("gnu_hash size incorrect");

    /* find buckets */
    ಪ್ರತಿ(i = 0; i < nbuckets; i++)
	buck[i].first = -1;

    p = (ElfW(Sym) *)dynsym->data;
    ಪ್ರತಿ(i = 0; i < nb_syms; i++, p++)
        ಯದಿ (p->st_shndx != SHN_UNDEF) {
	    ಪೂರ್ಣಾಙ್ಕ bucket = hash[i] % nbuckets;

	    ಯದಿ (buck[bucket].first == -1)
		buck[bucket].first = buck[bucket].last = i;
	    ಅನ್ಯಥಾ {
		nextbuck[buck[bucket].last] = i;
		buck[bucket].last = i;
	    }
	}

    /* fill buckets/chains/bloom and sort symbols */
    p = (ElfW(Sym) *)dynsym->data;
    ಪ್ರತಿ(i = 0; i < nbuckets; i++) {
	ಪೂರ್ಣಾಙ್ಕ cur = buck[i].first;

	ಯದಿ (cur != -1) {
	    buckets[i] = q - new_syms;
	    ಪ್ರತಿ (;;) {
                old_to_new_syms[cur] = q - new_syms;
                *q++ = p[cur];
	        *chain++ = hash[cur] & ~1;
		bloom[(hash[cur] / ELFCLASS_BITS) % bloom_size] |=
		    (addr_t)1 << (hash[cur] % ELFCLASS_BITS) |
		    (addr_t)1 << ((hash[cur] >> bloom_shift) % ELFCLASS_BITS);
		ಯದಿ (cur == buck[i].last)
		    ಭಙ್ಗ;
		cur = nextbuck[cur];
	    }
	    chain[-1] |= 1;
	}
    }

    memcpy(dynsym->data, new_syms, nb_syms * ಪರಿಮಾಣ(ElfW(Sym)));
    tcc_free(new_syms);
    tcc_free(hash);
    tcc_free(buck);
    tcc_free(nextbuck);

    update_relocs(s1, dynsym, old_to_new_syms, 0);

    /* modify the versions */
    vs = versym_section;
    ಯದಿ (vs) {
	ElfW(Half) *newver, *versym = (ElfW(Half) *)vs->data;

	ಯದಿ (1/*versym*/) {
            newver = tcc_malloc(nb_syms * ಪರಿಮಾಣ(*newver));
	    ಪ್ರತಿ (i = 0; i < nb_syms; i++)
	        newver[old_to_new_syms[i]] = versym[i];
	    memcpy(vs->data, newver, nb_syms * ಪರಿಮಾಣ(*newver));
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
ST_FUNC ಶೂನ್ಯ relocate_syms(TCCState *s1, Section *symtab, ಪೂರ್ಣಾಙ್ಕ do_resolve)
{
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಙ್ಕ sym_bind, sh_ಅಂಕೆ;
    ಧ್ರುವ ವರ್ಣ *name;

    for_each_elem(symtab, 1, sym, ElfW(Sym)) {
        sh_ಅಂಕೆ = sym->st_shndx;
        ಯದಿ (sh_ಅಂಕೆ == SHN_UNDEF) {
            ಯದಿ (do_resolve == 2) /* relocating dynsym */
                ಅನುವರ್ತ;
            name = (ವರ್ಣ *) s1->symtab->link->data + sym->st_name;
            /* Use ld.so to resolve symbol for us (for tcc -run) */
            ಯದಿ (do_resolve) {
#ಯದಿ defined TCC_IS_NATIVE && !defined TCC_TARGET_PE
                /* dlsym() needs the undecorated name.  */
                ಧ್ರುವ ವರ್ಣ *name_ud = &name[s1->leading_underscore];
                ಶೂನ್ಯ *addr = ರಿಕ್ತ;
                ಯದಿ (!s1->nostdlib)
                    addr = dlsym(RTLD_DEFAULT, name_ud);
		ಯದಿ (addr == ರಿಕ್ತ) {
		    ಪೂರ್ಣಾಙ್ಕ i;
		    ಪ್ರತಿ (i = 0; i < s1->nb_loaded_dlls; i++)
                        ಯದಿ ((addr = dlsym(s1->loaded_dlls[i]->handle, name_ud)))
			    ಭಙ್ಗ;
		}
                ಯದಿ (addr) {
                    sym->st_ಮೌಲ್ಯ = (addr_t) addr;
#ifdef DEBUG_RELOC
		    printf ("relocate_sym: %s -> 0x%lx\n", name, sym->st_ಮೌಲ್ಯ);
#endif
                    ಗಚ್ಛ found;
                }
#endif
            /* if dynamic symbol exist, it will be used in relocate_section */
            } ಅನ್ಯಥಾ ಯದಿ (s1->dynsym && find_elf_sym(s1->dynsym, name))
                ಗಚ್ಛ found;
            /* XXX: _fp_hw seems to be part of the ABI, so we ignore
               it */
            ಯದಿ (!strcmp(name, "_fp_hw"))
                ಗಚ್ಛ found;
            /* only weak symbols are accepted to be undefined. Their
               value is zero */
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            ಯದಿ (sym_bind == STB_WEAK)
                sym->st_ಮೌಲ್ಯ = 0;
            ಅನ್ಯಥಾ
                tcc_error_noabort("unresolved reference to '%s'", name);

        } ಅನ್ಯಥಾ ಯದಿ (sh_ಅಂಕೆ < SHN_LORESERVE) {
            /* add section base */
            sym->st_ಮೌಲ್ಯ += s1->sections[sym->st_shndx]->sh_addr;
        }
    found: ;
    }
}

/* relocate a given section (CPU dependent) by applying the relocations
   in the associated relocation section */
ಸ್ಥಿರ ಶೂನ್ಯ relocate_section(TCCState *s1, Section *s, Section *sr)
{
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಙ್ಕ type, sym_index;
    unsigned ವರ್ಣ *ptr;
    addr_t tgt, addr;
    ಪೂರ್ಣಾಙ್ಕ is_dwarf = s->sh_ಅಂಕೆ >= s1->dwlo && s->sh_ಅಂಕೆ < s1->dwhi;

    qrel = (ElfW_Rel *)sr->data;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
	ಯದಿ (s->data == ರಿಕ್ತ) /* bss */
	    ಅನುವರ್ತ;
        ptr = s->data + rel->r_offset;
        sym_index = ELFW(R_SYM)(rel->r_info);
        sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
        type = ELFW(R_TYPE)(rel->r_info);
        tgt = sym->st_ಮೌಲ್ಯ;
#ಯದಿ SHT_RELX == SHT_RELA
        tgt += rel->r_addend;
#endif
        ಯದಿ (is_dwarf && type == R_DATA_32DW
            && sym->st_shndx >= s1->dwlo && sym->st_shndx < s1->dwhi) {
            /* dwarf section relocation to each other */
            add32le(ptr, tgt - s1->sections[sym->st_shndx]->sh_addr);
            ಅನುವರ್ತ;
        }
        addr = s->sh_addr + rel->r_offset;
        relocate(s1, rel, type, ptr, addr, tgt);
    }

#ifndef ELF_OBJ_ONLY
    /* if the relocation is allocated, we change its symbol table */
    ಯದಿ (sr->sh_flags & SHF_ALLOC) {
        sr->link = s1->dynsym;
        ಯದಿ (s1->output_type & TCC_OUTPUT_DYN) {
            size_t r = (uint8_t*)qrel - sr->data;
            ಯದಿ (ಪರಿಮಾಣ ((Stab_Sym*)0)->n_ಮೌಲ್ಯ < PTR_SIZE
                && 0 == strcmp(s->name, ".stab"))
                r = 0; /* cannot apply 64bit relocation to 32bit value */
            sr->data_offset = sr->sh_size = r;
#ifdef CONFIG_TCC_PIE
            ಯದಿ (r && (s->sh_flags & SHF_EXECINSTR))
                tcc_warning("%d relocations to %s", (unsigned)(r / ಪರಿಮಾಣ *qrel), s->name);
#endif
        }
    }
#endif

#ifdef TCC_TARGET_RISCV64
    dynarray_reset(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries);
#endif
}

/* relocate all sections */
ST_FUNC ಶೂನ್ಯ relocate_sections(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    Section *s, *sr;

    ಪ್ರತಿ (i = 1; i < s1->nb_sections; ++i) {
        sr = s1->sections[i];
        ಯದಿ (sr->sh_type != SHT_RELX)
            ಅನುವರ್ತ;
        s = s1->sections[sr->sh_info];
#ifndef TCC_TARGET_MACHO
        ಯದಿ (s != s1->got
            || s1->static_link
            || s1->output_type == TCC_OUTPUT_MEMORY)
#endif
        {
            relocate_section(s1, s, sr);
        }
#ifndef ELF_OBJ_ONLY
        ಯದಿ (sr->sh_flags & SHF_ALLOC) {
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
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ prepare_dynamic_rel(TCCState *s1, Section *sr)
{
    ಪೂರ್ಣಾಙ್ಕ ಎಣಿಕೆ_2 = 0;
#ಯದಿ defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || \
    defined(TCC_TARGET_ARM) || defined(TCC_TARGET_ARM64) || \
    defined(TCC_TARGET_RISCV64)
    ElfW_Rel *rel;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
        ಪೂರ್ಣಾಙ್ಕ sym_index = ELFW(R_SYM)(rel->r_info);
        ಪೂರ್ಣಾಙ್ಕ type = ELFW(R_TYPE)(rel->r_info);
        ವಿಕಲ್ಪ(type) {
#ಯದಿ defined(TCC_TARGET_I386)
        ಪಕ್ಷ R_386_32:
            ಯದಿ (!get_sym_attr(s1, sym_index, 0)->dyn_index
                && ((ElfW(Sym)*)symtab_section->data + sym_index)->st_shndx == SHN_UNDEF) {
                /* don't fixup unresolved (weak) symbols */
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_RELATIVE);
                ಭಙ್ಗ;
            }
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_X86_64)
        ಪಕ್ಷ R_X86_64_32:
        ಪಕ್ಷ R_X86_64_32S:
        ಪಕ್ಷ R_X86_64_64:
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_ARM)
        ಪಕ್ಷ R_ARM_ABS32:
        ಪಕ್ಷ R_ARM_TARGET1:
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_ARM64)
        ಪಕ್ಷ R_AARCH64_ABS32:
        ಪಕ್ಷ R_AARCH64_ABS64:
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_RISCV64)
        ಪಕ್ಷ R_RISCV_32:
        ಪಕ್ಷ R_RISCV_64:
#endif
            ಎಣಿಕೆ_2++;
            ಭಙ್ಗ;
#ಯದಿ defined(TCC_TARGET_I386)
        ಪಕ್ಷ R_386_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    ಯದಿ (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_PLT32);
	        ಭಙ್ಗ;
	    }
	}
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_X86_64)
        ಪಕ್ಷ R_X86_64_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    ಯದಿ (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_index, R_X86_64_PLT32);
	        ಭಙ್ಗ;
	    }
	}
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_ARM64)
        ಪಕ್ಷ R_AARCH64_PREL32:
#endif
            ಯದಿ (s1->output_type != TCC_OUTPUT_DLL)
                ಭಙ್ಗ;
            ಯದಿ (get_sym_attr(s1, sym_index, 0)->dyn_index)
                ಎಣಿಕೆ_2++;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            ಭಙ್ಗ;
        }
    }
#endif
    ಪ್ರತ್ಯಾಗಮ ಎಣಿಕೆ_2;
}
#endif

#ifdef NEED_BUILD_GOT
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ build_got(TCCState *s1)
{
    /* if no got, then create it */
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    s1->got->sh_entsize = 4;
    /* keep space for _DYNAMIC pointer and two dummy got entries */
    section_ptr_add(s1->got, 3 * PTR_SIZE);
    ಪ್ರತ್ಯಾಗಮ set_elf_sym(symtab_section, 0, 0, ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
        0, s1->got->sh_ಅಂಕೆ, "_GLOBAL_OFFSET_TABLE_");
}

/* Create a GOT and (for function call) a PLT entry corresponding to a symbol
   in s1->symtab. When creating the dynamic symbol table entry for the GOT
   relocation, use 'size' and 'info' for the corresponding symbol metadata.
   Returns the offset of the GOT or (if any) PLT entry. */
ಸ್ಥಿರ ಸಂರಚನಾ sym_attr * put_got_entry(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ dyn_reloc_type,
                                       ಪೂರ್ಣಾಙ್ಕ sym_index)
{
    ಪೂರ್ಣಾಙ್ಕ need_plt_entry;
    ಧ್ರುವ ವರ್ಣ *name;
    ElfW(Sym) *sym;
    ಸಂರಚನಾ sym_attr *attr;
    unsigned got_offset;
    ವರ್ಣ plt_name[200];
    ಪೂರ್ಣಾಙ್ಕ len;
    Section *s_rel;

    need_plt_entry = (dyn_reloc_type == R_JMP_SLOT);
    attr = get_sym_attr(s1, sym_index, 1);

    /* In case a function is both called and its address taken 2 GOT entries
       are created, one for taking the address (GOT) and the other for the PLT
       entry (PLTGOT).  */
    ಯದಿ (need_plt_entry ? attr->plt_offset : attr->got_offset)
        ಪ್ರತ್ಯಾಗಮ attr;

    s_rel = s1->got;
    ಯದಿ (need_plt_entry) {
        ಯದಿ (!s1->plt) {
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
    name = (ವರ್ಣ *) symtab_section->link->data + sym->st_name;
    //printf("sym %d %s\n", need_plt_entry, name);

    ಯದಿ (s1->dynsym) {
	ಯದಿ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
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
	} ಅನ್ಯಥಾ {
	    ಯದಿ (0 == attr->dyn_index)
                attr->dyn_index = set_elf_sym(s1->dynsym, sym->st_ಮೌಲ್ಯ,
                                              sym->st_size, sym->st_info, 0,
                                              sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s_rel, got_offset, dyn_reloc_type,
			  attr->dyn_index);
	}
    } ಅನ್ಯಥಾ {
        put_elf_reloc(symtab_section, s1->got, got_offset, dyn_reloc_type,
                      sym_index);
    }

    ಯದಿ (need_plt_entry) {
        attr->plt_offset = create_plt_entry(s1, got_offset, attr);

        /* create a symbol 'sym@plt' for the PLT jump vector */
        len = strlen(name);
        ಯದಿ (len > ಪರಿಮಾಣ plt_name - 5)
            len = ಪರಿಮಾಣ plt_name - 5;
        memcpy(plt_name, name, len);
        strcpy(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_offset, 0,
            ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0, s1->plt->sh_ಅಂಕೆ, plt_name);
    } ಅನ್ಯಥಾ {
        attr->got_offset = got_offset;
    }

    ಪ್ರತ್ಯಾಗಮ attr;
}

/* build GOT and PLT entries */
/* Two passes because R_JMP_SLOT should become first. Some targets
   (arm, arm64) do not allow mixing R_JMP_SLOT and R_GLOB_DAT. */
ST_FUNC ಶೂನ್ಯ build_got_entries(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ got_sym)
{
    Section *s;
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಙ್ಕ i, type, gotplt_entry, reloc_type, sym_index;
    ಸಂರಚನಾ sym_attr *attr;
    ಪೂರ್ಣಾಙ್ಕ pass = 0;
redo:
    ಪ್ರತಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ಯದಿ (s->sh_type != SHT_RELX)
            ಅನುವರ್ತ;
        /* no need to handle got relocations */
        ಯದಿ (s->link != symtab_section)
            ಅನುವರ್ತ;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_entry = gotplt_entry_type(type);
            ಯದಿ (gotplt_entry == -1) {
                tcc_error_noabort ("Unknown relocation type for got: %d", type);
                ಅನುವರ್ತ;
            }
            sym_index = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];

            ಯದಿ (gotplt_entry == NO_GOTPLT_ENTRY) {
                ಅನುವರ್ತ;
            }

            /* Automatically create PLT/GOT [entry] if it is an undefined
	       reference (resolved at runtime), or the symbol is absolute,
	       probably created by tcc_add_symbol, and thus on 64-bit
	       targets might be too far from application code.  */
            ಯದಿ (gotplt_entry == AUTO_GOTPLT_ENTRY) {
                ಯದಿ (sym->st_shndx == SHN_UNDEF) {
                    ElfW(Sym) *esym;
		    ಪೂರ್ಣಾಙ್ಕ dynindex;
                    ಯದಿ (!PCRELATIVE_DLLPLT
                        && (s1->output_type & TCC_OUTPUT_DYN))
                        ಅನುವರ್ತ;
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
		    ಯದಿ (s1->dynsym) {
			/* dynsym isn't set for -run :-/  */
			dynindex = get_sym_attr(s1, sym_index, 0)->dyn_index;
			esym = (ElfW(Sym) *)s1->dynsym->data + dynindex;
			ಯದಿ (dynindex
			    && (ELFW(ST_TYPE)(esym->st_info) == STT_FUNC
				|| (ELFW(ST_TYPE)(esym->st_info) == STT_NOTYPE
				    && ELFW(ST_TYPE)(sym->st_info) == STT_FUNC)))
			    ಗಚ್ಛ jmp_slot;
		    }
                } ಅನ್ಯಥಾ ಯದಿ (sym->st_shndx == SHN_ABS) {
                    ಯದಿ (sym->st_ಮೌಲ್ಯ == 0) /* from tcc_add_btstub() */
                        ಅನುವರ್ತ;
#ifndef TCC_TARGET_ARM
                    ಯದಿ (PTR_SIZE != 8)
                        ಅನುವರ್ತ;
#endif
                    /* from tcc_add_symbol(): on 64 bit platforms these
                       need to go through .got */
                } ಅನ್ಯಥಾ
                    ಅನುವರ್ತ;
            }

#ifdef TCC_TARGET_I386
            ಯದಿ ((type == R_386_PLT32 || type == R_386_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		ಯದಿ (pass != 0)
		    ಅನುವರ್ತ;
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_PC32);
                ಅನುವರ್ತ;
            }
#endif
#ifdef TCC_TARGET_X86_64
            ಯದಿ ((type == R_X86_64_PLT32 || type == R_X86_64_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		ಯದಿ (pass != 0)
		    ಅನುವರ್ತ;
                rel->r_info = ELFW(R_INFO)(sym_index, R_X86_64_PC32);
                ಅನುವರ್ತ;
            }
#endif
            reloc_type = code_reloc(type);
            ಯದಿ (reloc_type == -1) {
                tcc_error_noabort ("Unknown relocation type: %d", type);
                ಅನುವರ್ತ;
            }

            ಯದಿ (reloc_type != 0) {
        jmp_slot:
	        ಯದಿ (pass != 0)
                    ಅನುವರ್ತ;
                reloc_type = R_JMP_SLOT;
            } ಅನ್ಯಥಾ {
	        ಯದಿ (pass != 1)
                    ಅನುವರ್ತ;
                reloc_type = R_GLOB_DAT;
            }

            ಯದಿ (!s1->got)
                got_sym = build_got(s1);

            ಯದಿ (gotplt_entry == BUILD_GOT_ONLY)
                ಅನುವರ್ತ;

            attr = put_got_entry(s1, reloc_type, sym_index);

            ಯದಿ (reloc_type == R_JMP_SLOT)
                rel->r_info = ELFW(R_INFO)(attr->plt_sym, type);
        }
    }
    ಯದಿ (++pass < 2)
        ಗಚ್ಛ redo;
    /* .rel.plt refers to .got actually */
    ಯದಿ (s1->plt && s1->plt->reloc)
        s1->plt->reloc->sh_info = s1->got->sh_ಅಂಕೆ;
    ಯದಿ (got_sym) /* set size */
        ((ElfW(Sym)*)symtab_section->data)[got_sym].st_size = s1->got->data_offset;
}
#endif /* def NEED_BUILD_GOT */

ST_FUNC ಪೂರ್ಣಾಙ್ಕ set_global_sym(TCCState *s1, ಧ್ರುವ ವರ್ಣ *name, Section *sec, addr_t offs)
{
    ಪೂರ್ಣಾಙ್ಕ shn = sec ? sec->sh_ಅಂಕೆ : offs || !name ? SHN_ABS : SHN_UNDEF;
    ಯದಿ (sec && offs == -1)
        offs = sec->data_offset;
    ಪ್ರತ್ಯಾಗಮ set_elf_sym(symtab_section, offs, 0,
        ELFW(ST_INFO)(name ? STB_GLOBAL : STB_LOCAL, STT_NOTYPE), 0, shn, name);
}

ಸ್ಥಿರ ಶೂನ್ಯ add_init_array_defines(TCCState *s1, ಧ್ರುವ ವರ್ಣ *section_name)
{
    Section *s;
    addr_t end_offset;
    ವರ್ಣ buf[1024];
    s = have_section(s1, section_name);
    ಯದಿ (!s || !(s->sh_flags & SHF_ALLOC)) {
        end_offset = 0;
        s = text_section;
    } ಅನ್ಯಥಾ {
        end_offset = s->data_offset;
    }
    snprintf(buf, ಪರಿಮಾಣ(buf), "__%s_start", section_name + 1);
    set_global_sym(s1, buf, s, 0);
    snprintf(buf, ಪರಿಮಾಣ(buf), "__%s_end", section_name + 1);
    set_global_sym(s1, buf, s, end_offset);
}

ST_FUNC ಶೂನ್ಯ add_array (TCCState *s1, ಧ್ರುವ ವರ್ಣ *sec, ಪೂರ್ಣಾಙ್ಕ c)
{
    Section *s;
    s = find_section(s1, sec);
    s->sh_flags = shf_RELRO;
    s->sh_type = sec[1] == 'i' ? SHT_INIT_ARRAY : SHT_FINI_ARRAY;
    put_elf_reloc (s1->symtab, s, s->data_offset, R_DATA_PTR, c);
    section_ptr_add(s, PTR_SIZE);
}

#ifdef CONFIG_TCC_BCHECK
ST_FUNC ಶೂನ್ಯ tcc_add_bcheck(TCCState *s1)
{
    ಯದಿ (0 == s1->do_bounds_check)
        ಪ್ರತ್ಯಾಗಮ;
    section_ptr_add(bounds_section, ಪರಿಮಾಣ(addr_t));
}
#endif

/* set symbol to STB_LOCAL and resolve. The point is to not export it as
   a dynamic symbol to allow so's to have one each with a different value. */
ಸ್ಥಿರ ಶೂನ್ಯ set_local_sym(TCCState *s1, ಧ್ರುವ ವರ್ಣ *name, Section *s, ಪೂರ್ಣಾಙ್ಕ offset)
{
    ಪೂರ್ಣಾಙ್ಕ c = find_elf_sym(s1->symtab, name);
    ಯದಿ (c) {
        ElfW(Sym) *esym = (ElfW(Sym)*)s1->symtab->data + c;
        esym->st_info = ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE);
        esym->st_ಮೌಲ್ಯ = offset;
        esym->st_shndx = s->sh_ಅಂಕೆ;
    }
}

/* avoid generating debug/test_coverage code for stub functions */
ಸ್ಥಿರ ಶೂನ್ಯ tcc_compile_string_no_debug(TCCState *s, ಧ್ರುವ ವರ್ಣ *str)
{
    ಪೂರ್ಣಾಙ್ಕ save_do_debug = s->do_debug;
    ಪೂರ್ಣಾಙ್ಕ save_test_coverage = s->test_coverage;

    s->do_debug = 0;
    s->test_coverage = 0;
    tcc_compile_string(s, str);
    s->do_debug = save_do_debug;
    s->test_coverage = save_test_coverage;
}

#ifdef CONFIG_TCC_BACKTRACE
ಸ್ಥಿರ ಶೂನ್ಯ put_ptr(TCCState *s1, Section *s, ಪೂರ್ಣಾಙ್ಕ offs)
{
    ಪೂರ್ಣಾಙ್ಕ c;
    c = set_global_sym(s1, ರಿಕ್ತ, s, offs);
    s = data_section;
    put_elf_reloc (s1->symtab, s, s->data_offset, R_DATA_PTR, c);
    section_ptr_add(s, PTR_SIZE);
}

ST_FUNC ಶೂನ್ಯ tcc_add_btstub(TCCState *s1)
{
    Section *s;
    ಪೂರ್ಣಾಙ್ಕ n, o, *p;
    CString cstr;
    ಧ್ರುವ ವರ್ಣ *__rt_info = &"___rt_info"[!s1->leading_underscore];

    s = data_section;
    /* Align to PTR_SIZE */
    section_add(s, 0, PTR_SIZE);
    o = s->data_offset;
    /* create a struct rt_context (see tccrun.c) */
    ಯದಿ (s1->dwarf) {
        put_ptr(s1, dwarf_ಸಾಲು_section, 0);
        put_ptr(s1, dwarf_ಸಾಲು_section, -1);
	ಯದಿ (s1->dwarf >= 5)
            put_ptr(s1, dwarf_ಸಾಲು_str_section, 0);
	ಅನ್ಯಥಾ
            put_ptr(s1, dwarf_str_section, 0);
    }
    ಅನ್ಯಥಾ
    {
        put_ptr(s1, stab_section, 0);
        put_ptr(s1, stab_section, -1);
        put_ptr(s1, stab_section->link, 0);
    }

    /* skip esym_start/esym_end/elf_str (not loaded) */
    section_ptr_add(s, 3 * PTR_SIZE);

    ಯದಿ (s1->output_type == TCC_OUTPUT_MEMORY && 0 == s1->dwarf) {
        put_ptr(s1, text_section, 0);
    } ಅನ್ಯಥಾ {
        /* prog_base : local nameless symbol with offset 0 at SHN_ABS */
        put_ptr(s1, ರಿಕ್ತ, 0);
#ಯದಿ defined TCC_TARGET_MACHO
        /* adjust for __PAGEZERO */
        ಯದಿ (s1->dwarf == 0 && s1->output_type == TCC_OUTPUT_EXE)
            write64le(data_section->data + data_section->data_offset - PTR_SIZE,
	              (uint64_t)1 << 32);
#endif
    }
    n = 3 * PTR_SIZE;
#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (s1->do_bounds_check) {
        put_ptr(s1, bounds_section, 0);
        n -= PTR_SIZE;
    }
#endif
    section_ptr_add(s, n);
    p = section_ptr_add(s, 2 * ಪರಿಮಾಣ (ಪೂರ್ಣಾಙ್ಕ));
    p[0] = s1->rt_ಅಂಕೆ_callers;
    p[1] = s1->dwarf;
    // if (s->data_offset - o != 10*PTR_SIZE + 2*sizeof (int)) exit(99);

    ಯದಿ (s1->output_type == TCC_OUTPUT_MEMORY) {
        set_global_sym(s1, __rt_info, s, o);
        ಪ್ರತ್ಯಾಗಮ;
    }

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern void __bt_init(),__bt_exit(),__bt_init_dll();"
        "static void *__rt_info[];"
        "__attribute__((constructor)) static void __bt_init_rt(){");
#ifdef TCC_TARGET_PE
    ಯದಿ (s1->output_type == TCC_OUTPUT_DLL)
#ifdef CONFIG_TCC_BCHECK
        cstr_printf(&cstr, "__bt_init_dll(%d);", s1->do_bounds_check);
#ಅನ್ಯಥಾ
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

ಸ್ಥಿರ ಶೂನ್ಯ tcc_tcov_add_file(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename)
{
    CString cstr;
    ಶೂನ್ಯ *ptr;
    ವರ್ಣ wd[1024];

    ಯದಿ (tcov_section == ರಿಕ್ತ)
        ಪ್ರತ್ಯಾಗಮ;
    section_ptr_add(tcov_section, 1);
    write32le (tcov_section->data, tcov_section->data_offset);

    cstr_new (&cstr);
    ಯದಿ (filename[0] == '/')
        cstr_printf (&cstr, "%s.tcov", filename);
    ಅನ್ಯಥಾ {
        getcwd (wd, ಪರಿಮಾಣ(wd));
        cstr_printf (&cstr, "%s/%s.tcov", wd, filename);
    }
    ptr = section_ptr_add(tcov_section, cstr.size + 1);
    strcpy((ವರ್ಣ *)ptr, cstr.data);
    unlink((ವರ್ಣ *)ptr);
#ifdef _WIN32
    normalize_slashes((ವರ್ಣ *)ptr);
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
ST_FUNC ಶೂನ್ಯ tccelf_add_crtbegin(TCCState *s1)
{
#ಯದಿ TARGETOS_OpenBSD
    ಯದಿ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crt0.o");
    ಯದಿ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbeginS.o");
    ಅನ್ಯಥಾ
        tcc_add_crt(s1, "crtbegin.o");
#ನೋಚೇದ್ಯದಿ TARGETOS_FreeBSD || TARGETOS_NetBSD
    ಯದಿ (s1->output_type != TCC_OUTPUT_DLL)
#ಯದಿ TARGETOS_FreeBSD
        tcc_add_crt(s1, "crt1.o");
#ಅನ್ಯಥಾ
        tcc_add_crt(s1, "crt0.o");
#endif
    tcc_add_crt(s1, "crti.o");
    ಯದಿ (s1->static_link)
        tcc_add_crt(s1, "crtbeginT.o");
    ಅನ್ಯಥಾ ಯದಿ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbeginS.o");
    ಅನ್ಯಥಾ
        tcc_add_crt(s1, "crtbegin.o");
#ನೋಚೇದ್ಯದಿ TARGETOS_ANDROID
    ಯದಿ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbegin_so.o");
    ಅನ್ಯಥಾ
        tcc_add_crt(s1, "crtbegin_dynamic.o");
#ಅನ್ಯಥಾ
    ಯದಿ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crt1.o");
    tcc_add_crt(s1, "crti.o");
#endif
}

ST_FUNC ಶೂನ್ಯ tccelf_add_crtend(TCCState *s1)
{
#ಯದಿ TARGETOS_OpenBSD
    ಯದಿ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtendS.o");
    ಅನ್ಯಥಾ
        tcc_add_crt(s1, "crtend.o");
#ನೋಚೇದ್ಯದಿ TARGETOS_FreeBSD || TARGETOS_NetBSD
    ಯದಿ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtendS.o");
    ಅನ್ಯಥಾ
        tcc_add_crt(s1, "crtend.o");
    tcc_add_crt(s1, "crtn.o");
#ನೋಚೇದ್ಯದಿ TARGETOS_ANDROID
    ಯದಿ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtend_so.o");
    ಅನ್ಯಥಾ
        tcc_add_crt(s1, "crtend_android.o");
#ಅನ್ಯಥಾ
    tcc_add_crt(s1, "crtn.o");
#endif
}
#endif /* TCC_TARGET_UNIX */

#ifndef TCC_TARGET_PE
/* add tcc runtime libraries */
ST_FUNC ಶೂನ್ಯ tcc_add_runtime(TCCState *s1)
{
    s1->filetype = 0;

#ifdef CONFIG_TCC_BCHECK
    tcc_add_bcheck(s1);
#endif
    tcc_add_pragma_libs(s1);

    /* add libc */
    ಯದಿ (!s1->nostdlib) {
        ಪೂರ್ಣಾಙ್ಕ lpthread = s1->option_pthread;

#ifdef CONFIG_TCC_BCHECK
        ಯದಿ (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    ಯದಿ (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    ಅನ್ಯಥಾ
                tcc_add_support(s1, "bcheck.o");
# ಯದಿ !(TARGETOS_OpenBSD || TARGETOS_NetBSD)
            tcc_add_library(s1, "dl");
# endif
            lpthread = 1;
        }
#endif
#ifdef CONFIG_TCC_BACKTRACE
        ಯದಿ (s1->do_backtrace) {
            ಯದಿ (s1->output_type & TCC_OUTPUT_EXE)
                tcc_add_support(s1, "bt-exe.o");
            ಯದಿ (s1->output_type != TCC_OUTPUT_DLL)
                tcc_add_support(s1, "bt-log.o");
            tcc_add_btstub(s1);
            lpthread = 1;
        }
#endif
        ಯದಿ (lpthread)
            tcc_add_library(s1, "pthread");
        tcc_add_library(s1, "c");
#ifdef TCC_LIBGCC
        ಯದಿ (!s1->static_link) {
            ಯದಿ (TCC_LIBGCC[0] == '/')
                tcc_add_file(s1, TCC_LIBGCC);
            ಅನ್ಯಥಾ
                tcc_add_dll(s1, TCC_LIBGCC, AFF_PRINT_ERROR);
        }
#endif
#ಯದಿ defined TCC_TARGET_ARM && TARGETOS_FreeBSD
        tcc_add_library(s1, "gcc_s"); // unwind code
#endif
        ಯದಿ (TCC_LIBTCC1[0]) {
            tcc_add_support(s1, TCC_LIBTCC1);
            tcc_add_library(s1, "c");
        }
#ifndef TCC_TARGET_MACHO
        ಯದಿ (s1->output_type != TCC_OUTPUT_MEMORY)
            tccelf_add_crtend(s1);
#endif
    }
}
#endif /* ndef TCC_TARGET_PE */

/* set _etext/_edata/_end  f=0:set  f=1:when_needed  f=2,3:just_update */
ಸ್ಥಿರ ಶೂನ್ಯ set_linker_sym(TCCState *s1, ಧ್ರುವ ವರ್ಣ *name, Section *sec, ಪೂರ್ಣಾಙ್ಕ f)
{
    ಪೂರ್ಣಾಙ್ಕ sym_index, esym_index, defined;
    ElfW(Sym) *sym, *esym;
    sym_index = find_elf_sym(symtab_section, name);
    sym = (ElfW(Sym) *)symtab_section->data + sym_index;
    esym_index = find_elf_sym(s1->dynsymtab_section, name);
    esym = (ElfW(Sym) *)s1->dynsymtab_section->data + esym_index;
    defined = sym->st_shndx != SHN_UNDEF
        || (esym->st_shndx != SHN_UNDEF && esym->st_size);
    ವಿಕಲ್ಪ (f) {
    ಪಕ್ಷ 1: /* old symbols w/o '_' */
        ಯದಿ (!(sym_index || esym_index) || defined)
            ಭಙ್ಗ;
    ಪಕ್ಷ 0:
        ಯದಿ (defined) {
            tcc_warning("linker symbol '%s' already defined", name);
            ಭಙ್ಗ;
        }
        sym_index = set_global_sym(s1, name, sec, -1);
        get_sym_attr(s1, sym_index, 1)->linker_sym = 1;
        ಭಙ್ಗ;
    ಸ್ವಭಾವ: /* update (bss only) */
        ಯದಿ (get_sym_attr(s1, sym_index, 0)->linker_sym)
            sym->st_ಮೌಲ್ಯ = sec->data_offset;
    }
#ifndef ELF_OBJ_ONLY
    ಯದಿ (name[0] == '_')
        set_linker_sym(s1, name + 1, sec, f + 1);
#endif
}

/* add various standard linker symbols (must be done after the
   sections are filled (for example after allocating common
   symbols)) */
ಸ್ಥಿರ ಶೂನ್ಯ tcc_add_linker_symbols(TCCState *s1)
{
    ವರ್ಣ buf[1024];
    ಪೂರ್ಣಾಙ್ಕ i;
    Section *s;

    set_linker_sym(s1, "_etext", text_section, 0);
    set_linker_sym(s1, "_edata", data_section, 0);
    set_linker_sym(s1, "_end", bss_section, 0);
#ಯದಿ TARGETOS_OpenBSD
    set_global_sym(s1, "__executable_start", ರಿಕ್ತ, ELF_START_ADDR);
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
    ಪ್ರತಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ಯದಿ ((s->sh_flags & SHF_ALLOC)
            && (s->sh_type == SHT_PROGBITS || s->sh_type == SHT_NOBITS
                || s->sh_type == SHT_STRTAB)) {
            /* check if section name can be expressed in C */
            ಧ್ರುವ ವರ್ಣ *p0, *p;
            p0 = s->name;
            ಯದಿ (*p0 == '.')
                ++p0;
            p = p0;
            ಪ್ರತಿ(;;) {
                ಪೂರ್ಣಾಙ್ಕ c = *p;
                ಯದಿ (!c)
                    ಭಙ್ಗ;
                ಯದಿ (!isid(c) && !isnum(c))
                    ಗಚ್ಛ next_sec;
                p++;
            }
            snprintf(buf, ಪರಿಮಾಣ(buf), "__start_%s", p0);
            set_global_sym(s1, buf, s, 0);
            snprintf(buf, ಪರಿಮಾಣ(buf), "__stop_%s", p0);
            set_global_sym(s1, buf, s, -1);
        }
    next_sec: ;
    }
}

ST_FUNC ಶೂನ್ಯ resolve_common_syms(TCCState *s1)
{
    ElfW(Sym) *sym;

    /* Allocate common symbols in BSS.  */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ಯದಿ (sym->st_shndx == SHN_COMMON && sym->st_size) {
            /* symbol alignment is in st_value for SHN_COMMONs */
	    sym->st_ಮೌಲ್ಯ = section_add(bss_section, sym->st_size,
					sym->st_ಮೌಲ್ಯ);
            sym->st_shndx = bss_section->sh_ಅಂಕೆ;
        }
    }

    /* Now assign linker provided symbols their value.  */
    ಯದಿ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_linker_symbols(s1);
}

#ifndef ELF_OBJ_ONLY
ST_FUNC ಶೂನ್ಯ fill_got_entry(TCCState *s1, ElfW_Rel *rel)
{
    ಪೂರ್ಣಾಙ್ಕ sym_index = ELFW(R_SYM) (rel->r_info);
    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->data)[sym_index];
    ಸಂರಚನಾ sym_attr *attr = get_sym_attr(s1, sym_index, 0);
    unsigned offset = attr->got_offset;

    ಯದಿ (0 == offset)
        ಪ್ರತ್ಯಾಗಮ;
    section_reserve(s1->got, offset + PTR_SIZE);
#ಯದಿ PTR_SIZE == 8
    write64le(s1->got->data + offset, sym->st_ಮೌಲ್ಯ);
#ಅನ್ಯಥಾ
    write32le(s1->got->data + offset, sym->st_ಮೌಲ್ಯ);
#endif
}

/* Perform relocation to GOT or PLT entries */
ST_FUNC ಶೂನ್ಯ fill_got(TCCState *s1)
{
    Section *s;
    ElfW_Rel *rel;
    ಪೂರ್ಣಾಙ್ಕ i;

    ಪ್ರತಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ಯದಿ (s->sh_type != SHT_RELX)
            ಅನುವರ್ತ;
        /* no need to handle got relocations */
        ಯದಿ (s->link != symtab_section)
            ಅನುವರ್ತ;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            ವಿಕಲ್ಪ (ELFW(R_TYPE) (rel->r_info)) {
                ಪಕ್ಷ R_X86_64_GOT32:
                ಪಕ್ಷ R_X86_64_GOTPCREL:
		ಪಕ್ಷ R_X86_64_GOTPCRELX:
		ಪಕ್ಷ R_X86_64_REX_GOTPCRELX:
                ಪಕ್ಷ R_X86_64_PLT32:
                    fill_got_entry(s1, rel);
                    ಭಙ್ಗ;
            }
        }
    }
}

/* See put_got_entry for a description.  This is the second stage
   where GOT references to local defined symbols are rewritten.  */
ಸ್ಥಿರ ಶೂನ್ಯ fill_local_got_entries(TCCState *s1)
{
    ElfW_Rel *rel;
    ಯದಿ (!s1->got->reloc)
        ಪ್ರತ್ಯಾಗಮ;
    for_each_elem(s1->got->reloc, 0, rel, ElfW_Rel) {
	ಯದಿ (ELFW(R_TYPE)(rel->r_info) == R_RELATIVE) {
	    ಪೂರ್ಣಾಙ್ಕ sym_index = ELFW(R_SYM) (rel->r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->data)[sym_index];
	    ಸಂರಚನಾ sym_attr *attr = get_sym_attr(s1, sym_index, 0);
	    unsigned offset = attr->got_offset;
	    ಯದಿ (offset != rel->r_offset - s1->got->sh_addr)
	        tcc_error_noabort("fill_local_got_entries: huh?");
	    rel->r_info = ELFW(R_INFO)(0, R_RELATIVE);
#ಯದಿ SHT_RELX == SHT_RELA
	    rel->r_addend = sym->st_ಮೌಲ್ಯ;
#ಅನ್ಯಥಾ
	    /* All our REL architectures also happen to be 32bit LE.  */
	    write32le(s1->got->data + offset, sym->st_ಮೌಲ್ಯ);
#endif
	}
    }
}

/* Bind symbols of executable: resolve undefined symbols from exported symbols
   in shared libraries */
ಸ್ಥಿರ ಶೂನ್ಯ bind_exe_dynsyms(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ is_PIE)
{
    ಧ್ರುವ ವರ್ಣ *name;
    ಪೂರ್ಣಾಙ್ಕ sym_index, index;
    ElfW(Sym) *sym, *esym;
    ಪೂರ್ಣಾಙ್ಕ type;

    /* Resolve undefined symbols from dynamic symbols. When there is a match:
       - if STT_FUNC or STT_GNU_IFUNC symbol -> add it in PLT
       - if STT_OBJECT symbol -> add it in .bss section with suitable reloc */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ಯದಿ (sym->st_shndx == SHN_UNDEF
            /* bss symbols may be initialized in the shared library */
            || sym->st_shndx == SHN_COMMON
            || sym->st_shndx == bss_section->sh_ಅಂಕೆ) {
            name = (ವರ್ಣ *) symtab_section->link->data + sym->st_name;
            sym_index = find_elf_sym(s1->dynsymtab_section, name);
            esym = &((ElfW(Sym) *)s1->dynsymtab_section->data)[sym_index];
            ಯದಿ (sym_index && esym->st_shndx != SHN_UNDEF) {
                ಯದಿ (is_PIE)
                    ಅನುವರ್ತ;
                type = ELFW(ST_TYPE)(esym->st_info);
                ಯದಿ ((type == STT_FUNC) || (type == STT_GNU_IFUNC)) {
                    /* Indirect functions shall have STT_FUNC type in executable
                     * dynsym section. Indeed, a dlsym call following a lazy
                     * resolution would pick the symbol value from the
                     * executable dynsym entry which would contain the address
                     * of the function wanted by the caller of dlsym instead of
                     * the address of the function that would return that
                     * address */
                    ಪೂರ್ಣಾಙ್ಕ dynindex
		      = put_elf_sym(s1->dynsym, 0, esym->st_size,
				    ELFW(ST_INFO)(STB_GLOBAL,STT_FUNC), 0, 0,
				    name);
		    ಪೂರ್ಣಾಙ್ಕ index = sym - (ElfW(Sym) *) symtab_section->data;
		    get_sym_attr(s1, index, 1)->dyn_index = dynindex;
                } ಅನ್ಯಥಾ ಯದಿ (type == STT_OBJECT) {
                    unsigned long offset;
                    ElfW(Sym) *dynsym;
                    ಯದಿ (sym->st_shndx == bss_section->sh_ಅಂಕೆ) {
                        offset = sym->st_ಮೌಲ್ಯ;
                    } ಅನ್ಯಥಾ {
                        offset = bss_section->data_offset;
                        /* XXX: which alignment ? */
                        offset = (offset + 16 - 1) & -16;
                        bss_section->data_offset = offset + esym->st_size;
                    }
                    set_elf_sym (s1->symtab, offset, esym->st_size,
                                 esym->st_info, 0, bss_section->sh_ಅಂಕೆ, name);
                    index = put_elf_sym(s1->dynsym, offset, esym->st_size,
                                        esym->st_info, 0, bss_section->sh_ಅಂಕೆ,
                                        name);
                    /* Ensure R_COPY works for weak symbol aliases */
                    ಯದಿ (ELFW(ST_BIND)(esym->st_info) == STB_WEAK) {
                        for_each_elem(s1->dynsymtab_section, 1, dynsym, ElfW(Sym)) {
                            ಯದಿ ((dynsym->st_ಮೌಲ್ಯ == esym->st_ಮೌಲ್ಯ)
                                && (ELFW(ST_BIND)(dynsym->st_info) == STB_GLOBAL)) {
                                ವರ್ಣ *dynname = (ವರ್ಣ *) s1->dynsymtab_section->link->data
                                                + dynsym->st_name;
                                put_elf_sym(s1->dynsym, offset, dynsym->st_size,
                                            dynsym->st_info, 0,
                                            bss_section->sh_ಅಂಕೆ, dynname);
                                ಭಙ್ಗ;
                            }
                        }
                    }
                    put_elf_reloc(s1->dynsym, bss_section,
                                  offset, R_COPY, index);
                }
            } ಅನ್ಯಥಾ ಯದಿ (sym->st_shndx == SHN_UNDEF) {
                /* STB_WEAK undefined symbols are accepted */
                /* XXX: _fp_hw seems to be part of the ABI, so we ignore it */
                ಯದಿ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK ||
                    !strcmp(name, "_fp_hw")) {
                } ಅನ್ಯಥಾ {
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
ಸ್ಥಿರ ಶೂನ್ಯ bind_libs_dynsyms(TCCState *s1)
{
    ಧ್ರುವ ವರ್ಣ *name;
    ಪೂರ್ಣಾಙ್ಕ dynsym_index;
    ElfW(Sym) *sym, *esym;

    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        name = (ವರ್ಣ *)symtab_section->link->data + sym->st_name;
        dynsym_index = find_elf_sym(s1->dynsymtab_section, name);
        ಯದಿ (sym->st_shndx != SHN_UNDEF) {
            ಯದಿ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL
                && (dynsym_index || s1->rdynamic))
                set_elf_sym(s1->dynsym, sym->st_ಮೌಲ್ಯ, sym->st_size,
                            sym->st_info, 0, sym->st_shndx, name);
        } ಅನ್ಯಥಾ ಯದಿ (dynsym_index) {
            esym = (ElfW(Sym) *)s1->dynsymtab_section->data + dynsym_index;
            ಯದಿ (esym->st_shndx == SHN_UNDEF) {
                /* weak symbols can stay undefined */
                ಯದಿ (ELFW(ST_BIND)(esym->st_info) != STB_WEAK)
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
    ಪೂರ್ಣಾಙ್ಕ dynindex, index;
    ಧ್ರುವ ವರ್ಣ *name;
    ElfW(Sym) *sym;
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ಯದಿ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
	    name = (ವರ್ಣ *) symtab_section->link->data + sym->st_name;
	    dynindex = set_elf_sym(s1->dynsym, sym->st_ಮೌಲ್ಯ, sym->st_size,
				   sym->st_info, 0, sym->st_shndx, name);
	    index = sym - (ElfW(Sym) *) symtab_section->data;
            get_sym_attr(s1, index, 1)->dyn_index = dynindex;
        }
    }
}

/* decide if an unallocated section should be output. */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ set_sec_sizes(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    Section *s;
    ಪೂರ್ಣಾಙ್ಕ textrel = 0;
    ಪೂರ್ಣಾಙ್ಕ file_type = s1->output_type;

    /* Allocate strings for section names */
    ಪ್ರತಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ಯದಿ (s->sh_type == SHT_RELX && !(s->sh_flags & SHF_ALLOC)) {
            /* when generating a DLL, we include relocations but
               we may patch them */
            ಯದಿ ((file_type & TCC_OUTPUT_DYN)
                && (s1->sections[s->sh_info]->sh_flags & SHF_ALLOC)) {
                ಪೂರ್ಣಾಙ್ಕ ಎಣಿಕೆ_2 = prepare_dynamic_rel(s1, s);
                ಯದಿ (ಎಣಿಕೆ_2) {
                    /* allocate the section */
                    s->sh_flags |= SHF_ALLOC;
                    s->sh_size = ಎಣಿಕೆ_2 * ಪರಿಮಾಣ(ElfW_Rel);
                    ಯದಿ (s1->sections[s->sh_info]->sh_flags & SHF_EXECINSTR)
                        textrel += ಎಣಿಕೆ_2;
                }
            }
        } ಅನ್ಯಥಾ ಯದಿ ((s->sh_flags & SHF_ALLOC)
#ifdef TCC_TARGET_ARM
                   || s->sh_type == SHT_ARM_ATTRIBUTES
#endif
                   || s1->do_debug) {
            s->sh_size = s->data_offset;
        }
    }
    ಪ್ರತ್ಯಾಗಮ textrel;
}

/* various data used under elf_output_file() */
ಸಂರಚನಾ dyn_inf {
    Section *dynamic;
    Section *dynstr;
    Section *interp;
    Section *note;
    Section *gnu_hash;
    ಸಂರಚನಾ {
        /* Info to be copied in dynamic section */
        unsigned long data_offset;
        addr_t rel_addr;
        addr_t rel_size;
    };

    ElfW(Phdr) *phdr;
    ಪೂರ್ಣಾಙ್ಕ phnum;
    ಪೂರ್ಣಾಙ್ಕ shnum;
    ಪೂರ್ಣಾಙ್ಕ tls;
    ಪೂರ್ಣಾಙ್ಕ relro;
    ಪೂರ್ಣಾಙ್ಕ notes;
    ಪೂರ್ಣಾಙ್ಕ ehfr;
    ಪೂರ್ಣಾಙ್ಕ dyna;
};

/* Decide the layout of sections loaded in memory. This must be done before
   program headers are filled since they contain info about the layout.
   We do the following ordering: interp, symbol tables, relocations, progbits,
   nobits */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ sort_sections(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ *sec_order, ಸಂರಚನಾ dyn_inf *d)
{
    Section *s;
    ಪೂರ್ಣಾಙ್ಕ i, j, k, f, f0, n;
    ಪೂರ್ಣಾಙ್ಕ nb_sections = s1->nb_sections;
    ಪೂರ್ಣಾಙ್ಕ *sec_cls = sec_order + nb_sections;
    ಪೂರ್ಣಾಙ್ಕ tls_align = 0; /* need common alignment for all tls sections */

    ಪ್ರತಿ (i = 1; i < nb_sections; i++) {
        s = s1->sections[i];
        ಯದಿ (0 == s->sh_name) {
            j = 0x900; /* no sh_name: won't go to file */
        } ಅನ್ಯಥಾ ಯದಿ (s->sh_flags & SHF_ALLOC) {
            j = 0x100;
            ಯದಿ ((s->sh_flags & (SHF_WRITE|SHF_TLS)) == SHF_WRITE)
                j = 0x200;
        } ಅನ್ಯಥಾ {
            j = 0x700;
        }
        ಯದಿ (j >= 0x700 && s1->output_format != TCC_OUTPUT_FORMAT_ELF)
            s->sh_size = 0, j = 0x900;

        ಯದಿ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM) {
            k = 0x10;
        } ಅನ್ಯಥಾ ಯದಿ (s->sh_type == SHT_STRTAB && strcmp(s->name, ".stabstr")) {
            k = 0x11;
            ಯದಿ (i == nb_sections - 1) /* ".shstrtab" assumed to stay last */
                k = 0xff;
        } ಅನ್ಯಥಾ ಯದಿ (s->sh_type == SHT_HASH || s->sh_type == SHT_GNU_HASH) {
            k = 0x12;
        } ಅನ್ಯಥಾ ಯದಿ (s->sh_type == SHT_GNU_verdef
                  || s->sh_type == SHT_GNU_verneed
                  || s->sh_type == SHT_GNU_versym) {
            k = 0x13;
        } ಅನ್ಯಥಾ ಯದಿ (s->sh_type == SHT_RELX) {
            k = 0x20;
            ಯದಿ (s1->plt && s == s1->plt->reloc)
                k = 0x21;
        } ಅನ್ಯಥಾ ಯದಿ (s->sh_flags & SHF_EXECINSTR) {
            k = 0x60;
        /* RELRO sections --> */
        } ಅನ್ಯಥಾ ಯದಿ (s->sh_flags & SHF_TLS) {
            ಯದಿ (s->sh_addralign > tls_align)
                tls_align = s->sh_addralign;
            k = 0x40 + (s->sh_type == SHT_NOBITS);
        } ಅನ್ಯಥಾ ಯದಿ (s->sh_type == SHT_PREINIT_ARRAY) {
            k = 0x42;
        } ಅನ್ಯಥಾ ಯದಿ (s->sh_type == SHT_INIT_ARRAY) {
            k = 0x43;
        } ಅನ್ಯಥಾ ಯದಿ (s->sh_type == SHT_FINI_ARRAY) {
            k = 0x44;
        } ಅನ್ಯಥಾ ಯದಿ (s->sh_type == SHT_DYNAMIC) {
            k = 0x48;
        } ಅನ್ಯಥಾ ಯದಿ (s == s1->got) {
            k = 0x49; /* .got as RELRO needs BIND_NOW in DT_FLAGS */
        } ಅನ್ಯಥಾ ಯದಿ (s->reloc && (s->reloc->sh_flags & SHF_ALLOC) && j == 0x100) {
            k = 0x45; /* +1 for data.ro */
        /* <-- */
        } ಅನ್ಯಥಾ ಯದಿ (s->sh_type == SHT_NOTE) {
            k = 0x08, d->notes = 1;
        } ಅನ್ಯಥಾ ಯದಿ (s->sh_type == SHT_NOBITS) {
            k = 0x70; /* bss */
        } ಅನ್ಯಥಾ ಯದಿ (s == d->interp) {
            k = 0x00;
        } ಅನ್ಯಥಾ {
            k = 0x50; /* data */
        }
        k += j;
        /* make our standard sections come last to have _etext/_edata correct values */
        ಯದಿ (s->sh_ಅಂಕೆ <= bss_section->sh_ಅಂಕೆ)
            ++k;
        /* make RELRO section writable */
        ಯದಿ ((k & 0xfff0) == 0x140)
            k += 0x100, s->sh_flags |= SHF_WRITE;
        /* sort by insert */
        ಪ್ರತಿ (n = i; n > 1 && k < (f = sec_cls[n - 1]); --n)
            sec_cls[n] = f, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
    }
    sec_order[0] = 0;
    d->shnum = 1;

#define SHFX_NEWPH (1 << 4)
#define SHFX_RELRO (1 << 5)

    /* count PT_LOAD headers needed */
    n = f0 = 0;
    ಪ್ರತಿ (i = 1; i < nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        k = sec_cls[i];
        f = 0;
        ಯದಿ (k < 0x900)
            ++d->shnum;
        ಯದಿ (k < 0x700) {
            f = s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR);
#ಯದಿ TARGETOS_NetBSD || TARGETOS_FreeBSD
	    /* NetBSD only supports 2 PT_LOAD sections.
	       See: https://blog.netbsd.org/tnf/entry/the_first_report_on_lld */
	    ಯದಿ ((f & SHF_WRITE) == 0)
                f |= SHF_EXECINSTR;
            k = 0; /* no relro */
#endif
            ಯದಿ ((k & 0xfff0) == 0x240) /* RELRO sections */
                d->relro = 1, f |= SHFX_RELRO;
            /* start new header when flags changed, but avoid zero memsz */
            ಯದಿ (f != f0 && s->sh_size)
                f0 = f, ++n, f |= SHFX_NEWPH;
            ಯದಿ ((s->sh_flags & SHF_TLS) && s->sh_size) {
                s->sh_addralign = tls_align;
                d->tls = 1, f |= SHF_TLS;
            }
        }
        sec_cls[i] = f;
        //printf("ph %d sec %02d : %3X %3X  %8.2X  %04X  %s\n", (f>0) * n, i, f, k, s->sh_type, (int)s->sh_size, s->name);
    }
    ಪ್ರತ್ಯಾಗಮ n;
}

ಸ್ಥಿರ ElfW(Phdr) *fill_phdr(ElfW(Phdr) *ph, ಪೂರ್ಣಾಙ್ಕ type, Section *s)
{
    ph->p_type = type;
    ph->p_flags = PF_R;
    ಯದಿ (s) {
        ಯದಿ (s->sh_flags & SHF_WRITE)
            ph->p_flags |= PF_W;
        ph->p_offset = s->sh_offset;
        ph->p_vaddr = s->sh_addr;
        ph->p_filesz = s->sh_size;
        ph->p_align = s->sh_addralign;
    }
    ph->p_paddr = ph->p_vaddr;
    ph->p_memsz = ph->p_filesz;
    ಪ್ರತ್ಯಾಗಮ ph;
}

ಸ್ಥಿರ ElfW(Phdr) *update_phdr(ElfW(Phdr) *ph, ಪೂರ್ಣಾಙ್ಕ type, Section *s, addr_t addr, ಪೂರ್ಣಾಙ್ಕ file_offset)
{
    ಯದಿ (ph->p_type == 0) {
        fill_phdr(ph, type, s);
    }
    ph->p_filesz = file_offset - ph->p_offset;
    ph->p_memsz = addr - ph->p_vaddr;
    ಪ್ರತ್ಯಾಗಮ ph;
}

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ layout_sections(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ *sec_order, ಸಂರಚನಾ dyn_inf *d)
{
    Section *s;
    addr_t addr, tmp, align, s_align, base;
    ElfW(Phdr) *ph = ರಿಕ್ತ, *ph2;
    ಪೂರ್ಣಾಙ್ಕ i, f, n, phnum, phfill;
    ಪೂರ್ಣಾಙ್ಕ file_offset;

    /* compute number of program headers */
    phnum = sort_sections(s1, sec_order, d);
    phfill = 0; /* set to 1 to have dll's with a PT_PHDR */
    ಯದಿ (d->interp)
        phfill = 2;
    phnum += phfill;
    ಯದಿ (d->dynamic)
        d->dyna = phnum++;
    ಯದಿ (d->notes)
        d->notes = phnum++;
    ಯದಿ (d->tls)
        d->tls = phnum++;
    ಯದಿ (eh_frame_hdr_section)
        d->ehfr = phnum++;
    ಯದಿ (d->relro)
        d->relro = phnum++;
    d->phnum = phnum;
    d->phdr = tcc_mallocz(phnum * ಪರಿಮಾಣ(ElfW(Phdr)));

    file_offset = 0;
    ಯದಿ (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
        file_offset = (ಪರಿಮಾಣ(ElfW(Ehdr)) + phnum * ಪರಿಮಾಣ(ElfW(Phdr)) + 3) & -4;
        file_offset += d->shnum * ಪರಿಮಾಣ (ElfW(Shdr));
    }

    s_align = ELF_PAGE_SIZE;
    ಯದಿ (s1->section_align)
        s_align = s1->section_align;

    addr = ELF_START_ADDR;
    ಯದಿ (s1->output_type & TCC_OUTPUT_DYN)
        addr = 0;

    ಯದಿ (s1->has_text_addr) {
        addr = s1->text_addr;
        ಯದಿ (0) {
            ಪೂರ್ಣಾಙ್ಕ a_offset, p_offset;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_offset = (ಪೂರ್ಣಾಙ್ಕ) (addr & (s_align - 1));
            p_offset = file_offset & (s_align - 1);
            ಯದಿ (a_offset < p_offset)
                a_offset += s_align;
            file_offset += (a_offset - p_offset);
        }
    }
    base = addr;
    /* compute address after headers */
    addr += file_offset;

    n = 0;
    ಪ್ರತಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        f = sec_order[i + s1->nb_sections];
        align = s->sh_addralign - 1;

        ಯದಿ (f == 0) { /* no alloc */
            file_offset = (file_offset + align) & ~align;
            s->sh_offset = file_offset;
            ಯದಿ (s->sh_type != SHT_NOBITS)
                file_offset += s->sh_size;
            ಅನುವರ್ತ;
        }

        ಯದಿ ((f & SHFX_NEWPH) && n) {
            /* different rwx section flags */
            ಯದಿ (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
                /* if in the middle of a page, w e duplicate the page in
                   memory so that one copy is RX and the other is RW */
                ಯದಿ ((addr & (s_align - 1)) != 0)
                    addr += s_align;
            } ಅನ್ಯಥಾ {
                align = s_align - 1;
            }
        }

        tmp = addr;
        addr = (addr + align) & ~align;
        file_offset += (ಪೂರ್ಣಾಙ್ಕ)(addr - tmp);
        s->sh_offset = file_offset;
        s->sh_addr = addr;

        //printf("%d : %08x %08x %04x %03x %s %d\n", n, (int)file_offset, (int)addr, (int)s->sh_size, s->sh_type, s->name, align + 1);
        addr += s->sh_size;
        ಯದಿ (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_size;

        ಯದಿ (f & SHFX_NEWPH) {
            /* set new program header */
            ph = &d->phdr[phfill + n];
            fill_phdr(ph, PT_LOAD, s);
            ph->p_align = s_align;
            ಯದಿ (f & SHF_EXECINSTR)
                ph->p_flags |= PF_X;
            ಯದಿ (n == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_offset = 0;
                ph->p_paddr = ph->p_vaddr = base;
            }
            ++n;
        }

        ಯದಿ (ph)
            update_phdr(ph, 0, 0, addr, file_offset);

        ಯದಿ (f & SHFX_RELRO) {
            ph2 = update_phdr(&d->phdr[d->relro], PT_GNU_RELRO, s, addr, file_offset);
            ph2->p_align = 1;
        }
        ಯದಿ (f & SHF_TLS) {
            ph2 = update_phdr(&d->phdr[d->tls], PT_TLS, s, addr, file_offset);
            ಯದಿ (s->sh_type == SHT_NOBITS)
                addr -= s->sh_size;
            /* for xxx-link.c:relocate() */
            s1->tls_start = ph2->p_vaddr;
            s1->tls_end = s1->tls_start + ph2->p_memsz + (-ph2->p_memsz & (ph2->p_align - 1));
        }
        ಯದಿ (s->sh_type == SHT_NOTE) {
            update_phdr(&d->phdr[d->notes], PT_NOTE, s, addr, file_offset);
        }
    }

    /* Fill other headers */
    ಯದಿ (d->dyna)
        fill_phdr(&d->phdr[d->dyna], PT_DYNAMIC, d->dynamic);
    ಯದಿ (d->ehfr)
        fill_phdr(&d->phdr[d->ehfr], PT_GNU_EH_FRAME, eh_frame_hdr_section);
    ಯದಿ (d->interp)
        fill_phdr(&d->phdr[1], PT_INTERP, d->interp);
    ಯದಿ (phfill) {
        ph = &d->phdr[0];
        ph->p_offset = ಪರಿಮಾಣ(ElfW(Ehdr));
        ph->p_vaddr = base + ph->p_offset;
        ph->p_filesz = phnum * ಪರಿಮಾಣ(ElfW(Phdr));
        ph->p_align = 4;
        fill_phdr(ph, PT_PHDR, ರಿಕ್ತ);
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* put dynamic tag */
ಸ್ಥಿರ ಶೂನ್ಯ put_dt(Section *dynamic, ಪೂರ್ಣಾಙ್ಕ dt, addr_t val)
{
    ElfW(Dyn) *dyn;
    dyn = section_ptr_add(dynamic, ಪರಿಮಾಣ(ElfW(Dyn)));
    dyn->d_tag = dt;
    dyn->d_un.d_val = val;
}

/* Fill the dynamic section with tags describing the address and size of
   sections */
ಸ್ಥಿರ ಶೂನ್ಯ fill_dynamic(TCCState *s1, ಸಂರಚನಾ dyn_inf *dyninf)
{
    Section *dynamic = dyninf->dynamic;
    Section *s;

    /* put dynamic section entries */
    put_dt(dynamic, DT_HASH, s1->dynsym->hash->sh_addr);
    put_dt(dynamic, DT_GNU_HASH, dyninf->gnu_hash->sh_addr);
    put_dt(dynamic, DT_STRTAB, dyninf->dynstr->sh_addr);
    put_dt(dynamic, DT_SYMTAB, s1->dynsym->sh_addr);
    put_dt(dynamic, DT_STRSZ, dyninf->dynstr->data_offset);
    put_dt(dynamic, DT_SYMENT, ಪರಿಮಾಣ(ElfW(Sym)));
#ಯದಿ PTR_SIZE == 8
    put_dt(dynamic, DT_RELA, dyninf->rel_addr);
    put_dt(dynamic, DT_RELASZ, dyninf->rel_size);
    put_dt(dynamic, DT_RELAENT, ಪರಿಮಾಣ(ElfW_Rel));
    ಯದಿ (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->data_offset);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_RELA);
    }
    put_dt(dynamic, DT_RELACOUNT, 0);
#ಅನ್ಯಥಾ
    put_dt(dynamic, DT_REL, dyninf->rel_addr);
    put_dt(dynamic, DT_RELSZ, dyninf->rel_size);
    put_dt(dynamic, DT_RELENT, ಪರಿಮಾಣ(ElfW_Rel));
    ಯದಿ (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->data_offset);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_REL);
    }
    put_dt(dynamic, DT_RELCOUNT, 0);
#endif
    ಯದಿ (versym_section && verneed_section) {
	/* The dynamic linker can not handle VERSYM without VERNEED */
        put_dt(dynamic, DT_VERSYM, versym_section->sh_addr);
        put_dt(dynamic, DT_VERNEED, verneed_section->sh_addr);
        put_dt(dynamic, DT_VERNEEDNUM, dt_verneednum);
    }
    s = have_section(s1, ".preinit_array");
    ಯದಿ (s && s->data_offset) {
        put_dt(dynamic, DT_PREINIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_PREINIT_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".init_array");
    ಯದಿ (s && s->data_offset) {
        put_dt(dynamic, DT_INIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_INIT_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".fini_array");
    ಯದಿ (s && s->data_offset) {
        put_dt(dynamic, DT_FINI_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_FINI_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".init");
    ಯದಿ (s && s->data_offset) {
        put_dt(dynamic, DT_INIT, s->sh_addr);
    }
    s = have_section(s1, ".fini");
    ಯದಿ (s && s->data_offset) {
        put_dt(dynamic, DT_FINI, s->sh_addr);
    }
    ಯದಿ (s1->do_debug)
        put_dt(dynamic, DT_DEBUG, 0);
    put_dt(dynamic, DT_NULL, 0);
}

/* Remove gaps between RELX sections.
   These gaps are a result of final_sections_reloc. Here some relocs are removed.
   The gaps are then filled with 0 in tcc_output_elf. The 0 is intepreted as
   R_...NONE reloc. This does work on most targets but on OpenBSD/arm64 this
   is illegal. OpenBSD/arm64 does not support R_...NONE reloc. */
ಸ್ಥಿರ ಶೂನ್ಯ update_reloc_sections(TCCState *s1, ಸಂರಚನಾ dyn_inf *dyninf)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    unsigned long file_offset = 0;
    Section *s;
    Section *relocplt = s1->plt ? s1->plt->reloc : ರಿಕ್ತ;

    /* dynamic relocation table information, for .dynamic section */
    dyninf->rel_addr = dyninf->rel_size = 0;

    ಪ್ರತಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
	ಯದಿ (s->sh_type == SHT_RELX && s != relocplt) {
	    ಯದಿ (dyninf->rel_size == 0) {
		dyninf->rel_addr = s->sh_addr;
		file_offset = s->sh_offset;
	    }
	    ಅನ್ಯಥಾ {
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
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_output_elf(TCCState *s1, FILE *f, ಪೂರ್ಣಾಙ್ಕ phnum, ElfW(Phdr) *phdr)
{
    ಪೂರ್ಣಾಙ್ಕ i, shnum, offset, size, file_type;
    Section *s;
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) shdr, *sh;

    file_type = s1->output_type;
    shnum = s1->nb_sections;

    memset(&ehdr, 0, ಪರಿಮಾಣ(ehdr));
    ಯದಿ (phnum > 0) {
        ehdr.e_phentsize = ಪರಿಮಾಣ(ElfW(Phdr));
        ehdr.e_phnum = phnum;
        ehdr.e_phoff = ಪರಿಮಾಣ(ElfW(Ehdr));
    }

    /* fill header */
    ehdr.e_ident[0] = ELFMAG0;
    ehdr.e_ident[1] = ELFMAG1;
    ehdr.e_ident[2] = ELFMAG2;
    ehdr.e_ident[3] = ELFMAG3;
    ehdr.e_ident[4] = ELFCLASSW;
    ehdr.e_ident[5] = ELFDATA2LSB;
    ehdr.e_ident[6] = EV_CURRENT;

#ಯದಿ TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    ehdr.e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
#ನೋಚೇದ್ಯದಿ TARGETOS_OpenBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_OPENBSD;
#ನೋಚೇದ್ಯದಿ TARGETOS_NetBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_NETBSD;
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM && defined TCC_ARM_EABI
    ehdr.e_flags = EF_ARM_EABI_VER5;
    ehdr.e_flags |= s1->float_abi == ARM_HARD_FLOAT
        ? EF_ARM_VFP_FLOAT : EF_ARM_SOFT_FLOAT;
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_RISCV64
    /* XXX should be configurable */
    ehdr.e_flags = EF_RISCV_FLOAT_ABI_DOUBLE;
#endif

    ಯದಿ (file_type == TCC_OUTPUT_OBJ) {
        ehdr.e_type = ET_REL;
    } ಅನ್ಯಥಾ {
        ಯದಿ (file_type & TCC_OUTPUT_DYN)
            ehdr.e_type = ET_DYN;
        ಅನ್ಯಥಾ
            ehdr.e_type = ET_EXEC;
        ಯದಿ (s1->elf_entryname)
            ehdr.e_entry = get_sym_addr(s1, s1->elf_entryname, 1, 0);
        ಅನ್ಯಥಾ
            ehdr.e_entry = get_sym_addr(s1, "_start", !!(file_type & TCC_OUTPUT_EXE), 0);
        ಯದಿ (ehdr.e_entry == (addr_t)-1)
            ehdr.e_entry = text_section->sh_addr;
        ಯದಿ (s1->nb_errors)
            ಪ್ರತ್ಯಾಗಮ -1;
    }

    sort_syms(s1, s1->symtab);

    ehdr.e_machine = EM_TCC_TARGET;
    ehdr.e_version = EV_CURRENT;
    ehdr.e_shoff = (ಪರಿಮಾಣ(ElfW(Ehdr)) + phnum * ಪರಿಮಾಣ(ElfW(Phdr)) + 3) & -4;
    ehdr.e_ehsize = ಪರಿಮಾಣ(ElfW(Ehdr));
    ehdr.e_shentsize = ಪರಿಮಾಣ(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    offset = fwrite(&ehdr, 1, ಪರಿಮಾಣ(ElfW(Ehdr)), f);
    ಯದಿ (phdr)
        offset += fwrite(phdr, 1, phnum * ಪರಿಮಾಣ(ElfW(Phdr)), f);

    /* output section headers */
    ಯಾವತ್ (offset < ehdr.e_shoff) {
        fputc(0, f);
        offset++;
    }

    ಪ್ರತಿ(i = 0; i < shnum; i++) {
        sh = &shdr;
        memset(sh, 0, ಪರಿಮಾಣ(ElfW(Shdr)));
        ಯದಿ (i) {
            s = s1->sections[i];
            sh->sh_name = s->sh_name;
            sh->sh_type = s->sh_type;
            sh->sh_flags = s->sh_flags;
            sh->sh_entsize = s->sh_entsize;
            sh->sh_info = s->sh_info;
            ಯದಿ (s->link)
                sh->sh_link = s->link->sh_ಅಂಕೆ;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_offset = s->sh_offset;
            sh->sh_size = s->sh_size;
        }
        offset += fwrite(sh, 1, ಪರಿಮಾಣ(ElfW(Shdr)), f);
    }

    /* output sections */
    ಪ್ರತಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ಯದಿ (s->sh_type != SHT_NOBITS) {
            ಯಾವತ್ (offset < s->sh_offset) {
                fputc(0, f);
                offset++;
            }
            size = s->sh_size;
            ಯದಿ (size)
                offset += fwrite(s->data, 1, size, f);
        }
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_output_ದ್ವಿಮಾನ(TCCState *s1, FILE *f)
{
    Section *s;
    ಪೂರ್ಣಾಙ್ಕ i, offset, size;

    offset = 0;
    ಪ್ರತಿ(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[i];
        ಯದಿ (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            ಯಾವತ್ (offset < s->sh_offset) {
                fputc(0, f);
                offset++;
            }
            size = s->sh_size;
            fwrite(s->data, 1, size, f);
            offset += size;
        }
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* Write an elf, coff or "binary" file */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_write_elf_file(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ phnum,
                              ElfW(Phdr) *phdr)
{
    ಪೂರ್ಣಾಙ್ಕ fd, mode, file_type, ret;
    FILE *f;

    file_type = s1->output_type;
    ಯದಿ (file_type == TCC_OUTPUT_OBJ)
        mode = 0666;
    ಅನ್ಯಥಾ
        mode = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_ದ್ವಿಮಾನ_2, mode);
    ಯದಿ (fd < 0 || (f = fdopen(fd, "wb")) == ರಿಕ್ತ)
        ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
    ಯದಿ (s1->verbose)
        printf("<- %s\n", filename);
#ifdef TCC_TARGET_COFF
    ಯದಿ (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    ಅನ್ಯಥಾ
#endif
    ಯದಿ (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        ret = tcc_output_elf(s1, f, phnum, phdr);
    ಅನ್ಯಥಾ
        ret = tcc_output_ದ್ವಿಮಾನ(s1, f);
    fclose(f);

    ಪ್ರತ್ಯಾಗಮ ret;
}

#ifndef ELF_OBJ_ONLY
/* order sections according to sec_order, remove sections
   that we aren't going to output.  */
ಸ್ಥಿರ ಶೂನ್ಯ reorder_sections(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ *sec_order)
{
    ಪೂರ್ಣಾಙ್ಕ i, nnew, k, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    backmap = tcc_malloc(s1->nb_sections * ಪರಿಮಾಣ(backmap[0]));
    ಪ್ರತಿ (i = 0, nnew = 0, snew = ರಿಕ್ತ; i < s1->nb_sections; i++) {
	k = sec_order ? sec_order[i] : i;
	s = s1->sections[k];
	ಯದಿ (!i || s->sh_name) {
	    backmap[k] = nnew;
            dynarray_add(&snew, &nnew, s);
	} ಅನ್ಯಥಾ {
	    backmap[k] = 0;
            /* just remember to free them later */
	    dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, s);
	}
    }
    ಪ್ರತಿ (i = 1; i < nnew; i++) {
	s = snew[i];
        s->sh_ಅಂಕೆ = i;
        ಯದಿ (s->sh_type == SHT_RELX)
            s->sh_info = backmap[s->sh_info];
        ಅನ್ಯಥಾ ಯದಿ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM)
            for_each_elem(s, 1, sym, ElfW(Sym))
                ಯದಿ (sym->st_shndx < s1->nb_sections)
                    sym->st_shndx = backmap[sym->st_shndx];
    }
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}

#ifdef TCC_TARGET_ARM
ಸ್ಥಿರ ಶೂನ್ಯ create_arm_attribute_section(TCCState *s1)
{
   // Needed for DLL support.
    ಸ್ಥಿರ ಧ್ರುವ unsigned ವರ್ಣ arm_attr[] = {
        0x41,                            // 'A'
        0x2c, 0x00, 0x00, 0x00,          // size 0x2c
        'a', 'e', 'a', 'b', 'i', 0x00,   // "aeabi"
        0x01, 0x22, 0x00, 0x00, 0x00,    // 'File Attributes', size 0x22
        0x05, 0x36, 0x00,                // 'CPU_name', "6"
#ಯದಿ CONFIG_TCC_CPUVER >= 7
        0x06, 0x0a,                      // 'CPU_arch', 'v7'
#ಅನ್ಯಥಾ
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
    unsigned ವರ್ಣ *ptr = section_ptr_add(attr, ಪರಿಮಾಣ(arm_attr));
    attr->sh_addralign = 1;
    memcpy(ptr, arm_attr, ಪರಿಮಾಣ(arm_attr));
    ಯದಿ (s1->float_abi != ARM_HARD_FLOAT) {
        ptr[26] = 0x00; // 'FP_arch', 'No'
        ptr[41] = 0x1e; // 'ABI_optimization_goals'
        ptr[42] = 0x06; // 'Aggressive Debug'
    }
}
#endif

#ifdef TCC_TARGET_RISCV64
ಸ್ಥಿರ ಶೂನ್ಯ create_riscv_attribute_section(TCCState *s1)
{
    ಸ್ಥಿರ ಧ್ರುವ unsigned ವರ್ಣ riscv_attr[] = {
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
    unsigned ವರ್ಣ *ptr = section_ptr_add(attr, ಪರಿಮಾಣ(riscv_attr));
    attr->sh_addralign = 1;
    memcpy(ptr, riscv_attr, ಪರಿಮಾಣ(riscv_attr));
}
#endif

#ಯದಿ TARGETOS_OpenBSD || TARGETOS_NetBSD || TARGETOS_FreeBSD

ಸ್ಥಿರ ಶೂನ್ಯ fill_bsd_note(Section *s, ಪೂರ್ಣಾಙ್ಕ type,
			  ಧ್ರುವ ವರ್ಣ *ಮೌಲ್ಯ, uint32_t data)
{
    unsigned long offset = 0;
    ವರ್ಣ *ptr;
    ElfW(Nhdr) *note;
    ಪೂರ್ಣಾಙ್ಕ align = s->sh_addralign;

    /* check if type present */
    ಯಾವತ್ (offset + ಪರಿಮಾಣ(ElfW(Nhdr)) < s->data_offset) {
        note = (ElfW(Nhdr) *) (s->data + offset);
	ಯದಿ (note->n_type == type)
	    ಪ್ರತ್ಯಾಗಮ;
	offset += (ಪರಿಮಾಣ(ElfW(Nhdr)) + note->n_namesz + note->n_descsz +
		  align - 1) & -align;
    }
    ptr = section_ptr_add(s, ಪರಿಮಾಣ(ElfW(Nhdr)) + 8 + 4);
    note = (ElfW(Nhdr) *) ptr;
    note->n_namesz = 8;
    note->n_descsz = 4;
    note->n_type = type;
    strcpy (ptr + ಪರಿಮಾಣ(ElfW(Nhdr)), ಮೌಲ್ಯ);
    memcpy (ptr + ಪರಿಮಾಣ(ElfW(Nhdr)) + 8, &data, 4);
}

ಸ್ಥಿರ Section *create_bsd_note_section(TCCState *s1,
					ಧ್ರುವ ವರ್ಣ *name,
					ಧ್ರುವ ವರ್ಣ *ಮೌಲ್ಯ)
{
    Section *s;
    unsigned ಪೂರ್ಣಾಙ್ಕ major = 0, minor = 0, patch = 0;

#ifdef CONFIG_OS_RELEASE
    sscanf(CONFIG_OS_RELEASE, "%u.%u.%u", &major, &minor, &patch);
#endif
#ಯದಿ TARGETOS_FreeBSD
    ಯದಿ (major < 14)
	ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
#endif
    s = find_section (s1, name);
    s->sh_type = SHT_NOTE;
#ಯದಿ TARGETOS_OpenBSD
    fill_bsd_note(s, ELF_NOTE_OS_GNU, ಮೌಲ್ಯ, 0);
#ನೋಚೇದ್ಯದಿ TARGETOS_NetBSD
    fill_bsd_note(s, 1 /* NT_NETBSD_IDENT_TAG */, ಮೌಲ್ಯ,
		  major * 100000000u + (minor % 100u) * 1000000u +
		  (patch % 10000u) * 100u);
#ನೋಚೇದ್ಯದಿ TARGETOS_FreeBSD
    fill_bsd_note(s, 1 /* NT_FREEBSD_ABI_TAG */, ಮೌಲ್ಯ,
		  major * 100000u + (minor % 100u) * 1000u);
    fill_bsd_note(s, 4 /* NT_FREEBSD_FEATURE_CTL */, ಮೌಲ್ಯ, 0);
    fill_bsd_note(s, 2 /* NT_FREEBSD_NOINIT_TAG */, ಮೌಲ್ಯ, 0);
#endif
    ಪ್ರತ್ಯಾಗಮ s;
}
#endif

ಸ್ಥಿರ ಶೂನ್ಯ alloc_sec_names(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ is_obj);

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ elf_output_file(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename)
{
    ಪೂರ್ಣಾಙ್ಕ i, ret, file_type, *sec_order;
    ಸಂರಚನಾ dyn_inf dyninf = {0};
    Section *interp, *dynstr, *dynamic;
    ಪೂರ್ಣಾಙ್ಕ textrel, got_sym, dt_flags_1;

    file_type = s1->output_type;
    ret = -1;
    interp = dynstr = dynamic = ರಿಕ್ತ;
    sec_order = ರಿಕ್ತ;

#ifdef TCC_TARGET_ARM
    create_arm_attribute_section (s1);
#endif

#ifdef TCC_TARGET_RISCV64
    create_riscv_attribute_section(s1);
#endif

#ಯದಿ TARGETOS_OpenBSD
    dyninf.note = create_bsd_note_section (s1, ".note.openbsd.ident", "OpenBSD");
#endif

#ಯದಿ TARGETOS_NetBSD
    dyninf.note = create_bsd_note_section (s1, ".note.netbsd.ident", "NetBSD");
#endif

#ಯದಿ TARGETOS_FreeBSD
    dyninf.note = create_bsd_note_section (s1, ".note.tag", "FreeBSD");
#endif

        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_add_runtime(s1);
	resolve_common_syms(s1);

        ಯದಿ (!s1->static_link) {
            ಯದಿ (file_type & TCC_OUTPUT_EXE) {
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
            dynamic->sh_entsize = ಪರಿಮಾಣ(ElfW(Dyn));

            got_sym = build_got(s1);
            ಯದಿ (file_type & TCC_OUTPUT_EXE) {
                bind_exe_dynsyms(s1, file_type & TCC_OUTPUT_DYN);
                ಯದಿ (s1->nb_errors)
                    ಗಚ್ಛ the_end;
            }
            build_got_entries(s1, got_sym);
            ಯದಿ (file_type & TCC_OUTPUT_EXE) {
                bind_libs_dynsyms(s1);
            } ಅನ್ಯಥಾ {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
#ಯದಿ TCC_EH_FRAME
	    /* fill with initial data */
	    tcc_eh_frame_hdr(s1, 0);
#endif
	    dyninf.gnu_hash = create_gnu_hash(s1);
        } ಅನ್ಯಥಾ {
            build_got_entries(s1, 0);
        }
	version_add (s1);

    textrel = set_sec_sizes(s1);

    ಯದಿ (!s1->static_link) {
        /* add a list of needed dlls */
        ಪ್ರತಿ(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            ಯದಿ (dllref->level == 0)
                put_dt(dynamic, DT_NEEDED, put_elf_str(dynstr, dllref->name));
        }

        ಯದಿ (s1->rpath)
            put_dt(dynamic, s1->enable_new_dtags ? DT_RUNPATH : DT_RPATH,
                   put_elf_str(dynstr, s1->rpath));

        dt_flags_1 = DF_1_NOW;
        ಯದಿ (file_type & TCC_OUTPUT_DYN) {
            ಯದಿ (s1->soname)
                put_dt(dynamic, DT_SONAME, put_elf_str(dynstr, s1->soname));
            /* XXX: currently, since we do not handle PIC code, we
               must relocate the readonly segments */
            ಯದಿ (textrel)
                put_dt(dynamic, DT_TEXTREL, 0);
            ಯದಿ (file_type & TCC_OUTPUT_EXE)
                dt_flags_1 = DF_1_NOW | DF_1_PIE;
	    ಯದಿ (s1->znodelete)
		dt_flags_1 |= DF_1_NODELETE;
        }
        put_dt(dynamic, DT_FLAGS, DF_BIND_NOW);
        put_dt(dynamic, DT_FLAGS_1, dt_flags_1);
        ಯದಿ (s1->symbolic)
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
    sec_order = tcc_malloc(ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ) * 2 * s1->nb_sections);
    /* compute section to program header mapping */
    layout_sections(s1, sec_order, &dyninf);

        ಯದಿ (dynamic) {
            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->data, dynamic->sh_addr);
            ಯದಿ (file_type == TCC_OUTPUT_EXE
                || (RELOCATE_DLLPLT && (file_type & TCC_OUTPUT_DYN)))
                relocate_plt(s1);
            /* relocate symbols in .dynsym now that final addresses are known */
            relocate_syms(s1, s1->dynsym, 2);
        }

        /* if building executable or DLL, then relocate each section
           except the GOT which is already relocated */
        relocate_syms(s1, s1->symtab, 0);
        ಯದಿ (s1->nb_errors != 0)
            ಗಚ್ಛ the_end;
        relocate_sections(s1);
        ಯದಿ (dynamic) {
	    update_reloc_sections (s1, &dyninf);
            dynamic->data_offset = dyninf.data_offset;
            fill_dynamic(s1, &dyninf);
	}
        /* Perform relocation to GOT or PLT entries */
        ಯದಿ (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        ಅನ್ಯಥಾ ಯದಿ (s1->got)
            fill_local_got_entries(s1);

    ಯದಿ (dyninf.gnu_hash)
        update_gnu_hash(s1, dyninf.gnu_hash);

    reorder_sections(s1, sec_order);
#ಯದಿ TCC_EH_FRAME
    /* fill with final data */
    tcc_eh_frame_hdr(s1, 1);
#endif
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, dyninf.phnum, dyninf.phdr);
 the_end:
    tcc_free(sec_order);
    tcc_free(dyninf.phdr);
    ಪ್ರತ್ಯಾಗಮ ret;
}
#endif /* ndef ELF_OBJ_ONLY */

/* Allocate strings for section names */
ಸ್ಥಿರ ಶೂನ್ಯ alloc_sec_names(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ is_obj)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    Section *s, *strsec;

    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");
    ಪ್ರತಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ಯದಿ (is_obj)
            s->sh_size = s->data_offset;
	ಯದಿ (s->sh_size || s == strsec || (s->sh_flags & SHF_ALLOC) || is_obj)
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_size = strsec->data_offset;
}

/* Output an elf .o file */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ elf_output_obj(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename)
{
    Section *s;
    ಪೂರ್ಣಾಙ್ಕ i, ret, file_offset;
    /* Allocate strings for section names */
    alloc_sec_names(s1, 1);
    file_offset = (ಪರಿಮಾಣ (ElfW(Ehdr)) + 3) & -4;
    file_offset += s1->nb_sections * ಪರಿಮಾಣ(ElfW(Shdr));
    ಪ್ರತಿ(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        file_offset = (file_offset + 15) & -16;
        s->sh_offset = file_offset;
        ಯದಿ (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_size;
    }
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, 0, ರಿಕ್ತ);
    ಪ್ರತ್ಯಾಗಮ ret;
}

LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_output_file(TCCState *s, ಧ್ರುವ ವರ್ಣ *filename)
{
    s->nb_errors = 0;
    ಯದಿ (s->test_coverage)
        tcc_tcov_add_file(s, filename);
    ಯದಿ (s->output_type == TCC_OUTPUT_OBJ)
        ಪ್ರತ್ಯಾಗಮ elf_output_obj(s, filename);
#ifdef TCC_TARGET_PE
    ಪ್ರತ್ಯಾಗಮ  pe_output_file(s, filename);
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_MACHO
    ಪ್ರತ್ಯಾಗಮ macho_output_file(s, filename);
#ಅನ್ಯಥಾ
    ಪ್ರತ್ಯಾಗಮ elf_output_file(s, filename);
#endif
}

ST_FUNC ssize_t full_read(ಪೂರ್ಣಾಙ್ಕ fd, ಶೂನ್ಯ *buf, size_t ಎಣಿಕೆ_2) {
    ವರ್ಣ *cbuf = buf;
    size_t rnum = 0;
    ಯಾವತ್ (1) {
        ssize_t ಅಂಕೆ = ಪಠ(fd, cbuf, ಎಣಿಕೆ_2-rnum);
        ಯದಿ (ಅಂಕೆ < 0) ಪ್ರತ್ಯಾಗಮ ಅಂಕೆ;
        ಯದಿ (ಅಂಕೆ == 0) ಪ್ರತ್ಯಾಗಮ rnum;
        rnum += ಅಂಕೆ;
        cbuf += ಅಂಕೆ;
    }
}

ST_FUNC ಶೂನ್ಯ *load_data(ಪೂರ್ಣಾಙ್ಕ fd, unsigned long file_offset, unsigned long size)
{
    ಶೂನ್ಯ *data;

    data = tcc_malloc(size);
    lseek(fd, file_offset, SEEK_SET);
    full_read(fd, data, size);
    ಪ್ರತ್ಯಾಗಮ data;
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ SectionMergeInfo {
    Section *s;            /* corresponding existing section */
    unsigned long offset;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} SectionMergeInfo;

ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_object_type(ಪೂರ್ಣಾಙ್ಕ fd, ElfW(Ehdr) *h)
{
    ಪೂರ್ಣಾಙ್ಕ size = full_read(fd, h, ಪರಿಮಾಣ *h);
    ಯದಿ (size == ಪರಿಮಾಣ *h && 0 == memcmp(h, ELFMAG, 4)) {
        ಯದಿ (h->e_type == ET_REL)
            ಪ್ರತ್ಯಾಗಮ AFF_BINTYPE_REL;
        ಯದಿ (h->e_type == ET_DYN)
            ಪ್ರತ್ಯಾಗಮ AFF_BINTYPE_DYN;
    } ಅನ್ಯಥಾ ಯದಿ (size >= 8) {
        ಯದಿ (0 == memcmp(h, ARMAG, 8))
            ಪ್ರತ್ಯಾಗಮ AFF_BINTYPE_AR;
#ifdef TCC_TARGET_COFF
        ಯದಿ (((ಸಂರಚನಾ filehdr*)h)->f_magic == COFF_C67_MAGIC)
            ಪ್ರತ್ಯಾಗಮ AFF_BINTYPE_C67;
#endif
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_load_object_file(TCCState *s1,
                                ಪೂರ್ಣಾಙ್ಕ fd, unsigned long file_offset)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    unsigned long size, offset, offseti;
    ಪೂರ್ಣಾಙ್ಕ i, j, nb_syms, sym_index, ret, seencompressed;
    ವರ್ಣ *strsec, *strtab;
    ಪೂರ್ಣಾಙ್ಕ stab_index, stabstr_index;
    ಪೂರ್ಣಾಙ್ಕ *old_to_new_syms;
    ವರ್ಣ *sh_name, *name;
    SectionMergeInfo *sm_table, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    lseek(fd, file_offset, SEEK_SET);
    ಯದಿ (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        ಗಚ್ಛ invalid;
    /* test CPU specific stuff */
    ಯದಿ (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
invalid:
        ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("invalid object file");
    }
    /* read sections */
    shdr = load_data(fd, file_offset + ehdr.e_shoff,
                     ಪರಿಮಾಣ(ElfW(Shdr)) * ehdr.e_shnum);
    sm_table = tcc_mallocz(ಪರಿಮಾಣ(SectionMergeInfo) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);

    /* load symtab and strtab */
    old_to_new_syms = ರಿಕ್ತ;
    symtab = ರಿಕ್ತ;
    strtab = ರಿಕ್ತ;
    nb_syms = 0;
    seencompressed = 0;
    stab_index = stabstr_index = 0;
    ret = -1;

    ಪ್ರತಿ(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        ಯದಿ (sh->sh_type == SHT_SYMTAB) {
            ಯದಿ (symtab) {
                tcc_error_noabort("object must contain only one symtab");
                ಗಚ್ಛ the_end;
            }
            nb_syms = sh->sh_size / ಪರಿಮಾಣ(ElfW(Sym));
            symtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
            sm_table[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
        }
	ಯದಿ (sh->sh_flags & SHF_COMPRESSED)
	    seencompressed = 1;
    }

    /* now examine each section and try to merge its content with the
       ones in memory */
    ಪ್ರತಿ(i = 1; i < ehdr.e_shnum; i++) {
        /* no need to examine section name strtab */
        ಯದಿ (i == ehdr.e_shstrndx)
            ಅನುವರ್ತ;
        sh = &shdr[i];
	ಯದಿ (sh->sh_type == SHT_RELX)
	  sh = &shdr[sh->sh_info];
        /* ignore sections types we do not handle (plus relocs to those) */
        sh_name = strsec + sh->sh_name;
        ಯದಿ (0 == strncmp(sh_name, ".debug_", 7)
         || 0 == strncmp(sh_name, ".stab", 5)) {
	    ಯದಿ (!s1->do_debug || seencompressed)
	        ಅನುವರ್ತ;
#ಯದಿ !(TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD)
        } ಅನ್ಯಥಾ ಯದಿ (0 == strncmp(sh_name, ".eh_frame", 9)) {
            ಯದಿ (ರಿಕ್ತ == eh_frame_section)
                ಅನುವರ್ತ;
#endif
        } ಅನ್ಯಥಾ
        ಯದಿ (sh->sh_type != SHT_PROGBITS &&
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

#ಯದಿ TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD
            && sh->sh_type != SHT_X86_64_UNWIND
#endif
            )
            ಅನುವರ್ತ;

	sh = &shdr[i];
        sh_name = strsec + sh->sh_name;
        ಯದಿ (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        /* find corresponding section, if any */
        ಪ್ರತಿ(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            ಯದಿ (strcmp(s->name, sh_name))
                ಅನುವರ್ತ;
            ಯದಿ (sh->sh_type != s->sh_type
                && strcmp (s->name, ".eh_frame")
                /* some crt1.o seem to have two ".note.GNU-stack" (SHT_NOTE & SHT_PROGBITS) */
                && strcmp (s->name, ".note.GNU-stack")
                ) {
                tcc_error_noabort("section type conflict: %s %02x <> %02x", s->name, sh->sh_type, s->sh_type);
                ಗಚ್ಛ the_end;
            }
            ಯದಿ (!strncmp(sh_name, ".gnu.linkonce", 13)) {
                /* if a 'linkonce' section is already present, we
                   do not add it again. It is a little tricky as
                   symbols can still be defined in
                   it. */
                sm_table[i].link_once = 1;
                ಗಚ್ಛ next;
            }
            ಯದಿ (stab_section) {
                ಯದಿ (s == stab_section)
                    stab_index = i;
                ಯದಿ (s == stab_section->link)
                    stabstr_index = i;
            }
            ಗಚ್ಛ found;
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
        ಯದಿ (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        sm_table[i].offset = offset;
        sm_table[i].s = s;
        /* concatenate sections */
        ಯದಿ (sh->sh_type != SHT_NOBITS && size) {
            unsigned ವರ್ಣ *ptr;
            lseek(fd, file_offset + sh->sh_offset, SEEK_SET);
            ptr = s->data + offset;
            full_read(fd, ptr, size);
        }
#ಯದಿ defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
        /* align code sections to instruction lenght */
        /* This is needed if we compile a c file after this */
        ಯದಿ (s->sh_flags & SHF_EXECINSTR)
            section_add(s, 0, 4);
#endif
    next: ;
    }

    /* gr relocate stab strings */
    ಯದಿ (stab_index && stabstr_index) {
        Stab_Sym *a, *b;
        unsigned o;
        s = sm_table[stab_index].s;
        a = (Stab_Sym *)(s->data + sm_table[stab_index].offset);
        b = (Stab_Sym *)(s->data + s->data_offset);
        o = sm_table[stabstr_index].offset;
        ಯಾವತ್ (a < b) {
            ಯದಿ (a->n_strx)
                a->n_strx += o;
            a++;
        }
    }

    /* second short pass to update sh_link and sh_info fields of new
       sections */
    ಪ್ರತಿ(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        ಯದಿ (!s || !sm_table[i].new_section)
            ಅನುವರ್ತ;
        sh = &shdr[i];
        ಯದಿ (sh->sh_link > 0)
            s->link = sm_table[sh->sh_link].s;
        ಯದಿ (sh->sh_type == SHT_RELX) {
            s->sh_info = sm_table[sh->sh_info].s->sh_ಅಂಕೆ;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }

    ಯದಿ (!symtab)
        ಗಚ್ಛ done;

    /* resolve symbols */
    old_to_new_syms = tcc_mallocz(nb_syms * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));

    sym = symtab + 1;
    ಪ್ರತಿ(i = 1; i < nb_syms; i++, sym++) {
        ಯದಿ (sym->st_shndx != SHN_UNDEF &&
            sym->st_shndx < SHN_LORESERVE) {
            sm = &sm_table[sym->st_shndx];
            ಯದಿ (sm->link_once) {
                /* if a symbol is in a link once section, we use the
                   already defined symbol. It is very important to get
                   correct relocations */
                ಯದಿ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
                    name = strtab + sym->st_name;
                    sym_index = find_elf_sym(symtab_section, name);
                    ಯದಿ (sym_index)
                        old_to_new_syms[i] = sym_index;
                }
                ಅನುವರ್ತ;
            }
            /* if no corresponding section added, no need to add symbol */
            ಯದಿ (!sm->s)
                ಅನುವರ್ತ;
            /* convert section number */
            sym->st_shndx = sm->s->sh_ಅಂಕೆ;
            /* offset value */
            sym->st_ಮೌಲ್ಯ += sm->offset;
        }
        /* add symbol */
        name = strtab + sym->st_name;
        sym_index = set_elf_sym(symtab_section, sym->st_ಮೌಲ್ಯ, sym->st_size,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_to_new_syms[i] = sym_index;
    }

    /* third pass to patch relocation entries */
    ಪ್ರತಿ(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        ಯದಿ (!s)
            ಅನುವರ್ತ;
        sh = &shdr[i];
        offset = sm_table[i].offset;
        size = sh->sh_size;
        ವಿಕಲ್ಪ(s->sh_type) {
        ಪಕ್ಷ SHT_RELX:
            /* take relocation offset information */
            offseti = sm_table[sh->sh_info].offset;
	    ಪ್ರತಿ (rel = (ElfW_Rel *) s->data + (offset / ಪರಿಮಾಣ(*rel));
		 rel < (ElfW_Rel *) s->data + ((offset + size) / ಪರಿಮಾಣ(*rel));
		 rel++) {
                ಪೂರ್ಣಾಙ್ಕ type;
                unsigned sym_index;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_index = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                ಯದಿ (sym_index >= nb_syms)
                    ಗಚ್ಛ invalid_reloc;
                sym_index = old_to_new_syms[sym_index];
                /* ignore link_once in rel section. */
                ಯದಿ (!sym_index && !sm_table[sh->sh_info].link_once
#ifdef TCC_TARGET_ARM
                    && type != R_ARM_V4BX
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_RISCV64
                    && type != R_RISCV_ALIGN
                    && type != R_RISCV_RELAX
#endif
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, (ಪೂರ್ಣಾಙ್ಕ)rel->r_offset);
                    ಗಚ್ಛ the_end;
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
                ಯದಿ (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_index, 1)->plt_thumb_stub = 1;
#endif
            }
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            ಭಙ್ಗ;
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
    ಪ್ರತ್ಯಾಗಮ ret;
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ ArchiveHeader {
    ವರ್ಣ ar_name[16];           /* name of this member */
    ವರ್ಣ ar_date[12];           /* file mtime */
    ವರ್ಣ ar_uid[6];             /* owner uid; printed as decimal */
    ವರ್ಣ ar_gid[6];             /* owner gid; printed as decimal */
    ವರ್ಣ ar_mode[8];            /* file mode, printed as octal   */
    ವರ್ಣ ar_size[10];           /* file size, printed as decimal */
    ವರ್ಣ ar_fmag[2];            /* should contain ARFMAG */
} ArchiveHeader;

#define ARFMAG "`\n"

ಸ್ಥಿರ unsigned long long get_be(ಧ್ರುವ uint8_t *b, ಪೂರ್ಣಾಙ್ಕ n)
{
    unsigned long long ret = 0;
    ಯಾವತ್ (n)
        ret = (ret << 8) | *b++, --n;
    ಪ್ರತ್ಯಾಗಮ ret;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ read_ar_header(ಪೂರ್ಣಾಙ್ಕ fd, ಪೂರ್ಣಾಙ್ಕ offset, ArchiveHeader *hdr)
{
    ವರ್ಣ *p, *e;
    ಪೂರ್ಣಾಙ್ಕ len;
    lseek(fd, offset, SEEK_SET);
    len = full_read(fd, hdr, ಪರಿಮಾಣ(ArchiveHeader));
    ಯದಿ (len != ಪರಿಮಾಣ(ArchiveHeader))
        ಪ್ರತ್ಯಾಗಮ len ? -1 : 0;
    ಯದಿ (memcmp(hdr->ar_fmag, ARFMAG, ಪರಿಮಾಣ hdr->ar_fmag))
        ಪ್ರತ್ಯಾಗಮ -1;
    p = hdr->ar_name;
    ಪ್ರತಿ (e = p + ಪರಿಮಾಣ hdr->ar_name; e > p && e[-1] == ' ';)
        --e;
    *e = '\0';
    hdr->ar_size[ಪರಿಮಾಣ hdr->ar_size-1] = 0;
    ಪ್ರತ್ಯಾಗಮ len;
}

/* load only the objects which resolve undefined symbols */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_load_alacarte(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd, ಪೂರ್ಣಾಙ್ಕ size, ಪೂರ್ಣಾಙ್ಕ entrysize)
{
    ಪೂರ್ಣಾಙ್ಕ i, bound, nsyms, sym_index, len, ret = -1;
    unsigned long long off;
    uint8_t *data;
    ಧ್ರುವ ವರ್ಣ *ar_names, *p;
    ಧ್ರುವ uint8_t *ar_index;
    ElfW(Sym) *sym;
    ArchiveHeader hdr;

    data = tcc_malloc(size);
    ಯದಿ (full_read(fd, data, size) != size)
        ಗಚ್ಛ invalid;
    nsyms = get_be(data, entrysize);
    ar_index = data + entrysize;
    ar_names = (ವರ್ಣ *) ar_index + nsyms * entrysize;

    ಕುರು {
        bound = 0;
        ಪ್ರತಿ (p = ar_names, i = 0; i < nsyms; i++, p += strlen(p)+1) {
            Section *s = symtab_section;
            sym_index = find_elf_sym(s, p);
            ಯದಿ (!sym_index)
                ಅನುವರ್ತ;
            sym = &((ElfW(Sym) *)s->data)[sym_index];
            ಯದಿ(sym->st_shndx != SHN_UNDEF)
                ಅನುವರ್ತ;
            off = get_be(ar_index + i * entrysize, entrysize);
            len = read_ar_header(fd, off, &hdr);
            ಯದಿ (len <= 0 || memcmp(hdr.ar_fmag, ARFMAG, 2)) {
        invalid:
                tcc_error_noabort("invalid archive");
                ಗಚ್ಛ the_end;
            }
            off += len;
            ಯದಿ (s1->verbose == 2)
                printf("   -> %s\n", hdr.ar_name);
            ಯದಿ (tcc_load_object_file(s1, fd, off) < 0)
                ಗಚ್ಛ the_end;
            ++bound;
        }
    } ಯಾವತ್(bound);
    ret = 0;
 the_end:
    tcc_free(data);
    ಪ್ರತ್ಯಾಗಮ ret;
}

/* load a '.a' file */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_load_archive(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd, ಪೂರ್ಣಾಙ್ಕ alacarte)
{
    ArchiveHeader hdr;
    /* char magic[8]; */
    ಪೂರ್ಣಾಙ್ಕ size, len;
    unsigned long file_offset;
    ElfW(Ehdr) ehdr;

    /* skip magic which was already checked */
    /* full_read(fd, magic, sizeof(magic)); */
    file_offset = ಪರಿಮಾಣ ARMAG - 1;

    ಪ್ರತಿ(;;) {
        len = read_ar_header(fd, file_offset, &hdr);
        ಯದಿ (len == 0)
            ಪ್ರತ್ಯಾಗಮ 0;
        ಯದಿ (len < 0)
            ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("invalid archive");
        file_offset += len;
        size = strtol(hdr.ar_size, ರಿಕ್ತ, 0);
        ಯದಿ (alacarte) {
            /* coff symbol table : we handle it */
            ಯದಿ (!strcmp(hdr.ar_name, "/"))
                ಪ್ರತ್ಯಾಗಮ tcc_load_alacarte(s1, fd, size, 4);
            ಯದಿ (!strcmp(hdr.ar_name, "/SYM64/"))
                ಪ್ರತ್ಯಾಗಮ tcc_load_alacarte(s1, fd, size, 8);
        } ಅನ್ಯಥಾ ಯದಿ (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
            ಯದಿ (s1->verbose == 2)
                printf("   -> %s\n", hdr.ar_name);
            ಯದಿ (tcc_load_object_file(s1, fd, file_offset) < 0)
                ಪ್ರತ್ಯಾಗಮ -1;
        }
        /* align to even */
        file_offset = (file_offset + size + 1) & ~1;
    }
}

#ifndef ELF_OBJ_ONLY
/* Set LV[I] to the global index of sym-version (LIB,VERSION).  Maybe resizes
   LV, maybe create a new entry for (LIB,VERSION).  */
ಸ್ಥಿರ ಶೂನ್ಯ set_ver_to_ver(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ *n, ಪೂರ್ಣಾಙ್ಕ **lv, ಪೂರ್ಣಾಙ್ಕ i, ವರ್ಣ *lib, ವರ್ಣ *version)
{
    ಯಾವತ್ (i >= *n) {
        *lv = tcc_realloc(*lv, (*n + 1) * ಪರಿಮಾಣ(**lv));
        (*lv)[(*n)++] = -1;
    }
    ಯದಿ ((*lv)[i] == -1) {
        ಪೂರ್ಣಾಙ್ಕ v, prev_same_lib = -1;
        ಪ್ರತಿ (v = 0; v < nb_sym_versions; v++) {
            ಯದಿ (strcmp(sym_versions[v].lib, lib))
              ಅನುವರ್ತ;
            prev_same_lib = v;
            ಯದಿ (!strcmp(sym_versions[v].version, version))
              ಭಙ್ಗ;
        }
        ಯದಿ (v == nb_sym_versions) {
            sym_versions = tcc_realloc (sym_versions,
                                        (v + 1) * ಪರಿಮಾಣ(*sym_versions));
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
ಸ್ಥಿರ ಶೂನ್ಯ
set_sym_version(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ sym_index, ಪೂರ್ಣಾಙ್ಕ verndx)
{
    ಯದಿ (sym_index >= nb_sym_to_version) {
        ಪೂರ್ಣಾಙ್ಕ newelems = sym_index ? sym_index * 2 : 1;
        sym_to_version = tcc_realloc(sym_to_version,
                                     newelems * ಪರಿಮಾಣ(*sym_to_version));
        memset(sym_to_version + nb_sym_to_version, -1,
               (newelems - nb_sym_to_version) * ಪರಿಮಾಣ(*sym_to_version));
        nb_sym_to_version = newelems;
    }
    ಯದಿ (sym_to_version[sym_index] < 0)
      sym_to_version[sym_index] = verndx;
}

ಸಂರಚನಾ versym_info {
    ಪೂರ್ಣಾಙ್ಕ nb_versyms;
    ElfW(Verdef) *verdef;
    ElfW(Verneed) *verneed;
    ElfW(Half) *versym;
    ಪೂರ್ಣಾಙ್ಕ nb_local_ver, *local_ver;
};


ಸ್ಥಿರ ಶೂನ್ಯ store_version(TCCState *s1, ಸಂರಚನಾ versym_info *v, ವರ್ಣ *dynstr)
{
    ವರ್ಣ *lib, *version;
    uint32_t next;
    ಪೂರ್ಣಾಙ್ಕ i;

#define	DEBUG_VERSION 0

    ಯದಿ (v->versym && v->verdef) {
      ElfW(Verdef) *vdef = v->verdef;
      lib = ರಿಕ್ತ;
      ಕುರು {
        ElfW(Verdaux) *verdaux =
	  (ElfW(Verdaux) *) (((ವರ್ಣ *) vdef) + vdef->vd_aux);

#ಯದಿ DEBUG_VERSION
	printf ("verdef: version:%u flags:%u index:%u, hash:%u\n",
	        vdef->vd_version, vdef->vd_flags, vdef->vd_ndx,
		vdef->vd_hash);
#endif
	ಯದಿ (vdef->vd_cnt) {
          version = dynstr + verdaux->vda_name;

	  ಯದಿ (lib == ರಿಕ್ತ)
	    lib = version;
	  ಅನ್ಯಥಾ
            set_ver_to_ver(s1, &v->nb_local_ver, &v->local_ver, vdef->vd_ndx,
                           lib, version);
#ಯದಿ DEBUG_VERSION
	  printf ("  verdaux(%u): %s\n", vdef->vd_ndx, version);
#endif
	}
        next = vdef->vd_next;
        vdef = (ElfW(Verdef) *) (((ವರ್ಣ *) vdef) + next);
      } ಯಾವತ್ (next);
    }
    ಯದಿ (v->versym && v->verneed) {
      ElfW(Verneed) *vneed = v->verneed;
      ಕುರು {
        ElfW(Vernaux) *vernaux =
	  (ElfW(Vernaux) *) (((ವರ್ಣ *) vneed) + vneed->vn_aux);

        lib = dynstr + vneed->vn_file;
#ಯದಿ DEBUG_VERSION
	printf ("verneed: %u %s\n", vneed->vn_version, lib);
#endif
	ಪ್ರತಿ (i = 0; i < vneed->vn_cnt; i++) {
	  ಯದಿ ((vernaux->vna_other & 0x8000) == 0) { /* hidden */
              version = dynstr + vernaux->vna_name;
              set_ver_to_ver(s1, &v->nb_local_ver, &v->local_ver, vernaux->vna_other,
                             lib, version);
#ಯದಿ DEBUG_VERSION
	    printf ("  vernaux(%u): %u %u %s\n",
		    vernaux->vna_other, vernaux->vna_hash,
		    vernaux->vna_flags, version);
#endif
	  }
	  vernaux = (ElfW(Vernaux) *) (((ವರ್ಣ *) vernaux) + vernaux->vna_next);
	}
        next = vneed->vn_next;
        vneed = (ElfW(Verneed) *) (((ವರ್ಣ *) vneed) + next);
      } ಯಾವತ್ (next);
    }

#ಯದಿ DEBUG_VERSION
    ಪ್ರತಿ (i = 0; i < v->nb_local_ver; i++) {
      ಯದಿ (v->local_ver[i] > 0) {
        printf ("%d: lib: %s, version %s\n",
		i, sym_versions[v->local_ver[i]].lib,
                sym_versions[v->local_ver[i]].version);
      }
    }
#endif
}

/* load a library / DLL
   'level = 0' means that the DLL is referenced by the user
   (so it should be added as DT_NEEDED in the generated ELF file) */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_load_dll(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd, ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    ಪೂರ್ಣಾಙ್ಕ i, nb_syms, nb_dts, sym_bind, ret = -1;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;

    ವರ್ಣ *dynstr;
    ಪೂರ್ಣಾಙ್ಕ sym_index;
    ಧ್ರುವ ವರ್ಣ *name, *soname;
    ಸಂರಚನಾ versym_info v;

    full_read(fd, &ehdr, ಪರಿಮಾಣ(ehdr));

    /* test CPU specific stuff */
    ಯದಿ (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
        ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("bad architecture");
    }

    /* read sections */
    shdr = load_data(fd, ehdr.e_shoff, ಪರಿಮಾಣ(ElfW(Shdr)) * ehdr.e_shnum);

    /* load dynamic section and dynamic symbols */
    nb_syms = 0;
    nb_dts = 0;
    dynamic = ರಿಕ್ತ;
    dynsym = ರಿಕ್ತ; /* avoid warning */
    dynstr = ರಿಕ್ತ; /* avoid warning */
    memset(&v, 0, ಪರಿಮಾಣ v);

    ಪ್ರತಿ(i = 0, sh = shdr; i < ehdr.e_shnum; i++, sh++) {
        ವಿಕಲ್ಪ(sh->sh_type) {
        ಪಕ್ಷ SHT_DYNAMIC:
            nb_dts = sh->sh_size / ಪರಿಮಾಣ(ElfW(Dyn));
            dynamic = load_data(fd, sh->sh_offset, sh->sh_size);
            ಭಙ್ಗ;
        ಪಕ್ಷ SHT_DYNSYM:
            nb_syms = sh->sh_size / ಪರಿಮಾಣ(ElfW(Sym));
            dynsym = load_data(fd, sh->sh_offset, sh->sh_size);
            sh1 = &shdr[sh->sh_link];
            dynstr = load_data(fd, sh1->sh_offset, sh1->sh_size);
            ಭಙ್ಗ;
        ಪಕ್ಷ SHT_GNU_verdef:
	    v.verdef = load_data(fd, sh->sh_offset, sh->sh_size);
	    ಭಙ್ಗ;
        ಪಕ್ಷ SHT_GNU_verneed:
	    v.verneed = load_data(fd, sh->sh_offset, sh->sh_size);
	    ಭಙ್ಗ;
        ಪಕ್ಷ SHT_GNU_versym:
            v.nb_versyms = sh->sh_size / ಪರಿಮಾಣ(ElfW(Half));
	    v.versym = load_data(fd, sh->sh_offset, sh->sh_size);
	    ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            ಭಙ್ಗ;
        }
    }

    ಯದಿ (!dynamic)
        ಗಚ್ಛ the_end;

    /* compute the real library name */
    soname = tcc_basename(filename);
    ಪ್ರತಿ(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        ಯದಿ (dt->d_tag == DT_SONAME)
            soname = dynstr + dt->d_un.d_val;

    /* if the dll is already loaded, do not load it */
    ಯದಿ (tcc_add_dllref(s1, soname, level)->found)
        ಗಚ್ಛ ret_success;

    ಯದಿ (v.nb_versyms != nb_syms)
        tcc_free (v.versym), v.versym = ರಿಕ್ತ;
    ಅನ್ಯಥಾ
        store_version(s1, &v, dynstr);

    /* add dynamic symbols in dynsym_section */
    ಪ್ರತಿ(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        ಯದಿ (sym_bind == STB_LOCAL)
            ಅನುವರ್ತ;
        name = dynstr + sym->st_name;
        sym_index = set_elf_sym(s1->dynsymtab_section, sym->st_ಮೌಲ್ಯ, sym->st_size,
                                sym->st_info, sym->st_other, sym->st_shndx, name);
        ಯದಿ (v.versym) {
            ElfW(Half) vsym = v.versym[i];
            ಯದಿ ((vsym & 0x8000) == 0 && vsym > 0 && vsym < v.nb_local_ver)
                set_sym_version(s1, sym_index, v.local_ver[vsym]);
        }
    }

    /* do not load all referenced libraries
       (recursive loading can break linking of libraries) */
    /* following DT_NEEDED is needed for the dynamic loader (libdl.so),
       but it is no longer needed, when linking a library or a program.
       When tcc output mode is OUTPUT_MEM,
       tcc calls dlopen, which handles DT_NEEDED for us */

#ಯದಿ 0
    ಪ್ರತಿ(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        ಯದಿ (dt->d_tag == DT_RPATH)
            tcc_add_library_path(s1, dynstr + dt->d_un.d_val);

    /* load all referenced DLLs */
    ಪ್ರತಿ(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        ವಿಕಲ್ಪ(dt->d_tag) {
        ಪಕ್ಷ DT_NEEDED:
            name = dynstr + dt->d_un.d_val;
            ಯದಿ (tcc_add_dllref(s1, name, -1))
                ಅನುವರ್ತ;
            ಯದಿ (tcc_add_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                ret = tcc_error_noabort("referenced dll '%s' not found", name);
                ಗಚ್ಛ the_end;
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
    ಪ್ರತ್ಯಾಗಮ ret;
}

#define LD_TOK_NAME 256
#define LD_TOK_EOF  (-1)
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ld_inp(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ c = *s1->ld_p;
    ಯದಿ (c == 0)
        ಪ್ರತ್ಯಾಗಮ CH_EOF;
    ++s1->ld_p;
    ಪ್ರತ್ಯಾಗಮ c;
}
#define ld_unget(s1, ch) ಯದಿ (ch != CH_EOF) --s1->ld_p

/* return next ld script token */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ld_next(TCCState *s1, ವರ್ಣ *name, ಪೂರ್ಣಾಙ್ಕ name_size)
{
    ಪೂರ್ಣಾಙ್ಕ c, d, ch;
    ವರ್ಣ *q;

 redo:
    ch = ld_inp(s1);
    q = name, *q++ = ch;
    ವಿಕಲ್ಪ(ch) {
    ಪಕ್ಷ ' ':
    ಪಕ್ಷ '\t':
    ಪಕ್ಷ '\f':
    ಪಕ್ಷ '\v':
    ಪಕ್ಷ '\r':
    ಪಕ್ಷ '\n':
        ಗಚ್ಛ redo;
    ಪಕ್ಷ '/':
        ch = ld_inp(s1);
        ಯದಿ (ch == '*') { /* comment */
            ಪ್ರತಿ (d = 0;; d = ch) {
                ch = ld_inp(s1);
                ಯದಿ (ch == CH_EOF || (ch == '/' && d == '*'))
                    ಭಙ್ಗ;
            }
            ಗಚ್ಛ redo;
        } ಅನ್ಯಥಾ {
            ಗಚ್ಛ parse_name;
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ '\\':
    /* case 'a' ... 'z': */
    ಪಕ್ಷ 'a':
       ಪಕ್ಷ 'b':
       ಪಕ್ಷ 'c':
       ಪಕ್ಷ 'd':
       ಪಕ್ಷ 'e':
       ಪಕ್ಷ 'f':
       ಪಕ್ಷ 'g':
       ಪಕ್ಷ 'h':
       ಪಕ್ಷ 'i':
       ಪಕ್ಷ 'j':
       ಪಕ್ಷ 'k':
       ಪಕ್ಷ 'l':
       ಪಕ್ಷ 'm':
       ಪಕ್ಷ 'n':
       ಪಕ್ಷ 'o':
       ಪಕ್ಷ 'p':
       ಪಕ್ಷ 'q':
       ಪಕ್ಷ 'r':
       ಪಕ್ಷ 's':
       ಪಕ್ಷ 't':
       ಪಕ್ಷ 'u':
       ಪಕ್ಷ 'v':
       ಪಕ್ಷ 'w':
       ಪಕ್ಷ 'x':
       ಪಕ್ಷ 'y':
       ಪಕ್ಷ 'z':
    /* case 'A' ... 'z': */
    ಪಕ್ಷ 'A':
       ಪಕ್ಷ 'B':
       ಪಕ್ಷ 'C':
       ಪಕ್ಷ 'D':
       ಪಕ್ಷ 'E':
       ಪಕ್ಷ 'F':
       ಪಕ್ಷ 'G':
       ಪಕ್ಷ 'H':
       ಪಕ್ಷ 'I':
       ಪಕ್ಷ 'J':
       ಪಕ್ಷ 'K':
       ಪಕ್ಷ 'L':
       ಪಕ್ಷ 'M':
       ಪಕ್ಷ 'N':
       ಪಕ್ಷ 'O':
       ಪಕ್ಷ 'P':
       ಪಕ್ಷ 'Q':
       ಪಕ್ಷ 'R':
       ಪಕ್ಷ 'S':
       ಪಕ್ಷ 'T':
       ಪಕ್ಷ 'U':
       ಪಕ್ಷ 'V':
       ಪಕ್ಷ 'W':
       ಪಕ್ಷ 'X':
       ಪಕ್ಷ 'Y':
       ಪಕ್ಷ 'Z':
    ಪಕ್ಷ '-':
    ಪಕ್ಷ '_':
    ಪಕ್ಷ '.':
    ಪಕ್ಷ '$':
    ಪಕ್ಷ '~':
        ಪ್ರತಿ(;;) {
            ch = ld_inp(s1);
    parse_name:
            ಯದಿ (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') ||
                  strchr("/.-_+=$:\\,~", ch)))
                ಭಙ್ಗ;
            ಯದಿ ((q - name) < name_size - 1) {
                *q++ = ch;
            }
        }
        ld_unget(s1, ch);
        c = LD_TOK_NAME;
        ಭಙ್ಗ;
    ಪಕ್ಷ CH_EOF:
        c = LD_TOK_EOF;
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        c = ch;
        ಭಙ್ಗ;
    }
    *q = '\0';
    ಪ್ರತ್ಯಾಗಮ c;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ld_add_file(TCCState *s1, ಧ್ರುವ ವರ್ಣ filename[])
{
    ಯದಿ (filename[0] == '-' && filename[1] == 'l')
        ಪ್ರತ್ಯಾಗಮ tcc_add_library(s1, filename + 2);
    ಯದಿ (CONFIG_SYSROOT[0] != '\0' || !IS_ABSPATH(filename)) {
        /* lookup via library paths */
        ಪೂರ್ಣಾಙ್ಕ ret = tcc_add_dll(s1, tcc_basename(filename), 0);
        ಯದಿ (ret != FILE_NOT_FOUND)
            ಪ್ರತ್ಯಾಗಮ ret;
    }
    ಪ್ರತ್ಯಾಗಮ tcc_add_file_internal(s1, filename, AFF_PRINT_ERROR);
}

/* did static libraries add new undefined symbols? */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ new_undef_sym(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ sym_offset)
{
    ಯಾವತ್ (sym_offset < s1->symtab->data_offset) {
        ElfW(Sym) *esym = (ಶೂನ್ಯ*)(s1->symtab->data + sym_offset);
        ಯದಿ (esym->st_shndx == SHN_UNDEF)
            ಪ್ರತ್ಯಾಗಮ 1;
        sym_offset += ಪರಿಮಾಣ (ElfW(Sym));
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ld_add_file_list(TCCState *s1, ಧ್ರುವ ವರ್ಣ *cmd)
{
    ವರ್ಣ filename[1024];
    ಪೂರ್ಣಾಙ್ಕ t, c, sym_offset, ret = 0;
    unsigned ವರ್ಣ *pos = s1->ld_p;

repeat:
    s1->ld_p = pos;
    sym_offset = s1->symtab->data_offset;
    c = cmd[0];

    t = ld_next(s1, filename, ಪರಿಮಾಣ(filename));
    ಯದಿ (t != '(')
        ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("expected '(' after %s", cmd);
    t = ld_next(s1, filename, ಪರಿಮಾಣ(filename));
    ಪ್ರತಿ(;;) {
        ಯದಿ (t == LD_TOK_EOF) {
            ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("unexpected end of file");
        } ಅನ್ಯಥಾ ಯದಿ (t == ')') {
            ಭಙ್ಗ;
        } ಅನ್ಯಥಾ ಯದಿ (t != LD_TOK_NAME) {
            ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("unexpected token '%c'", t);
        } ಅನ್ಯಥಾ ಯದಿ (!strcmp(filename, "AS_NEEDED")) {
            ret |= ld_add_file_list(s1, filename);
        } ಅನ್ಯಥಾ ಯದಿ (c == 'I' || c == 'G' || c == 'A') {
            ret |= !!ld_add_file(s1, filename);
        }
        ಯದಿ (ret < 0)
            ಪ್ರತ್ಯಾಗಮ ret;
        t = ld_next(s1, filename, ಪರಿಮಾಣ(filename));
        ಯದಿ (t == ',')
            t = ld_next(s1, filename, ಪರಿಮಾಣ(filename));
    }
    ಯದಿ (c == 'G' && ret == 0 && new_undef_sym(s1, sym_offset))
        ಗಚ್ಛ repeat;
    ಪ್ರತ್ಯಾಗಮ ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_load_ldscript(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd)
{
    ವರ್ಣ cmd[64];
    ಪೂರ್ಣಾಙ್ಕ t, ret = 0, noscript = 1;
    unsigned ವರ್ಣ *text_ptr, *saved_ptr;

    saved_ptr = s1->ld_p;
    s1->ld_p = text_ptr = (ಶೂನ್ಯ*)tcc_load_text(fd);
    ಪ್ರತಿ(;;) {
        t = ld_next(s1, cmd, ಪರಿಮಾಣ(cmd));
        ಯದಿ (t == LD_TOK_EOF)
            ಭಙ್ಗ;
        ಯದಿ (!strcmp(cmd, "INPUT") ||
            !strcmp(cmd, "GROUP")) {
            ret |= ld_add_file_list(s1, cmd);
        } ಅನ್ಯಥಾ ಯದಿ (!strcmp(cmd, "OUTPUT_FORMAT") ||
                   !strcmp(cmd, "TARGET")) {
            /* ignore some commands */
            ret |= ld_add_file_list(s1, cmd);
        } ಅನ್ಯಥಾ ಯದಿ (noscript) {
            ret = FILE_NOT_RECOGNIZED;
        } ಅನ್ಯಥಾ {
            ret = tcc_error_noabort("unexpected '%s'", cmd);
        }
        ಯದಿ (ret < 0)
            ಭಙ್ಗ;
        noscript = 0;
    }
    tcc_free(text_ptr);
    s1->ld_p = saved_ptr;
    ಪ್ರತ್ಯಾಗಮ ret < 0 ? ret : -ret;
}
#endif /* !ELF_OBJ_ONLY */
