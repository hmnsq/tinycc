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

#অন্তর্ভাব "tcc.h"

/* Define this to get some debug output during relocation processing.  */
#undef DEBUG_RELOC

/********************************************************/
/* global variables */

/* elf version information */
সংরচনা sym_version {
    বর্ণ *lib;
    বর্ণ *version;
    পূর্ণাঙ্ক out_index;
    পূর্ণাঙ্ক prev_same_lib;
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
স্থির ধ্রুব বর্ণ rdata[] = ".rdata";
#অন্যথা
#define shf_RELRO SHF_ALLOC /* eventually made SHF_WRITE in sort_sections() */
স্থির ধ্রুব বর্ণ rdata[] = ".data.ro";
#endif

/* ------------------------------------------------------------------------- */

ST_FUNC শূন্য tccelf_new(TCCState *s)
{
    TCCState *s1 = s;

    /* no section zero */
    dynarray_add(&s->sections, &s->nb_sections, রিক্ত);

    /* create standard sections */
    text_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    data_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    /* create ro data section (make ro after relocation done with GNU_RELRO) */
    rodata_section = new_section(s, rdata, SHT_PROGBITS, shf_RELRO);
    bss_section = new_section(s, ".bss", SHT_NOBITS, SHF_ALLOC | SHF_WRITE);
    common_section = new_section(s, ".common", SHT_NOBITS, SHF_PRIVATE);
    common_section->sh_অঙ্ক = SHN_COMMON;

    /* symbols are always generated for linking stage */
    symtab_section = new_symtab(s, ".symtab", SHT_SYMTAB, 0,
                                ".strtab",
                                ".hashtab", SHF_PRIVATE);

    /* private symbol table for dynamic symbols */
    s->dynsymtab_section = new_symtab(s, ".dynsymtab", SHT_SYMTAB, SHF_PRIVATE|SHF_DYNSYM,
                                      ".dynstrtab",
                                      ".dynhashtab", SHF_PRIVATE);
    get_sym_attr(s, 0, 1);

    যদি (s->do_debug) {
        /* add debug sections */
        tcc_debug_new(s);
    }

#যদি TCC_EH_FRAME
    যদি (s->output_format != TCC_OUTPUT_FORMAT_ELF)
        s->unwind_tables = 0;
    tcc_eh_frame_start(s);
#endif

#ifdef CONFIG_TCC_BCHECK
    যদি (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        /* (make ro after relocation done with GNU_RELRO) */
        bounds_section = new_section(s, ".bounds", SHT_PROGBITS, shf_RELRO);
        lbounds_section = new_section(s, ".lbounds", SHT_PROGBITS, shf_RELRO);
    }
#endif

#ifdef TCC_TARGET_PE
    /* to make sure that -ltcc1 -Wl,-e,_start will grab the startup code
       from libtcc1.a (unless _start defined) */
    যদি (s->elf_entryname)
        set_global_sym(s, s->elf_entryname, রিক্ত, 0); /* SHN_UNDEF */
#endif

#ifndef ELF_OBJ_ONLY
    যদি (রিক্ত == s->elfint && s1->output_type != TCC_OUTPUT_OBJ) {
        ধ্রুব বর্ণ *p = CONFIG_TCC_ELFINTERP;
#যদি defined TCC_TARGET_ARM && defined CONFIG_TCC_ELFINTERP_ARMHF
        যদি (s->float_abi == ARM_HARD_FLOAT)
            p = CONFIG_TCC_ELFINTERP_ARMHF;
#endif
#যদি defined TCC_IS_NATIVE && defined TARGETOS_BSD
        /* see commit 55cb2170cd5ce77a7d76dcaf462fad2707281605 */
        { ধ্রুব বর্ণ *e = getenv("LD_SO"); যদি (e) p = e; }
#endif
        s->elfint = tcc_strdup(p);
    }
#endif /* ndef ELF_OBJ_ONLY */
}

ST_FUNC শূন্য free_section(Section *s)
{
    যদি (!s)
        প্রত্যাগম;
    tcc_free(s->data);
    s->data = রিক্ত;
    s->data_allocated = s->data_offset = 0;
}

ST_FUNC শূন্য tccelf_delete(TCCState *s1)
{
    পূর্ণাঙ্ক i;

#ifndef ELF_OBJ_ONLY
    /* free symbol versions */
    প্রতি (i = 0; i < nb_sym_versions; i++) {
        tcc_free(sym_versions[i].version);
        tcc_free(sym_versions[i].lib);
    }
    tcc_free(sym_versions);
    tcc_free(sym_to_version);
#endif

    /* free all sections */
    প্রতি(i = 1; i < s1->nb_sections; i++)
        free_section(s1->sections[i]);
    dynarray_reset(&s1->sections, &s1->nb_sections);

    প্রতি(i = 0; i < s1->nb_priv_sections; i++)
        free_section(s1->priv_sections[i]);
    dynarray_reset(&s1->priv_sections, &s1->nb_priv_sections);

    tcc_free(s1->sym_attrs);
    symtab_section = রিক্ত; /* for tccrun.c:rt_printline() */
}

/* save section data state */
ST_FUNC শূন্য tccelf_begin_file(TCCState *s1)
{
    Section *s; পূর্ণাঙ্ক i;
    প্রতি (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        s->sh_offset = s->data_offset;
    }
    /* disable symbol hashing during compilation */
    s = s1->symtab, s->reloc = s->hash, s->hash = রিক্ত;
#যদি defined TCC_TARGET_X86_64 && defined TCC_TARGET_PE
    s1->uw_sym = 0;
    s1->uw_offs = 0;
#endif
}

স্থির শূন্য update_relocs(TCCState *s1, Section *s, পূর্ণাঙ্ক *old_to_new_syms, পূর্ণাঙ্ক first_sym);

/* At the end of compilation, convert any UNDEF syms to global, and merge
   with previously existing symbols */
ST_FUNC শূন্য tccelf_end_file(TCCState *s1)
{
    Section *s = s1->symtab;
    পূর্ণাঙ্ক first_sym, nb_syms, *tr, i;

    first_sym = s->sh_offset / পরিমাণ (ElfSym);
    nb_syms = s->data_offset / পরিমাণ (ElfSym) - first_sym;
    s->data_offset = s->sh_offset;
    s->link->data_offset = s->link->sh_offset;
    s->hash = s->reloc, s->reloc = রিক্ত;
    tr = tcc_mallocz(nb_syms * পরিমাণ *tr);

    প্রতি (i = 0; i < nb_syms; ++i) {
        ElfSym *sym = (ElfSym*)s->data + first_sym + i;
        যদি (sym->st_shndx == SHN_UNDEF) {
            পূর্ণাঙ্ক sym_bind = ELFW(ST_BIND)(sym->st_info);
            পূর্ণাঙ্ক sym_type = ELFW(ST_TYPE)(sym->st_info);
            যদি (sym_bind == STB_LOCAL)
                sym_bind = STB_GLOBAL;
#ifndef TCC_TARGET_PE
            যদি (sym_bind == STB_GLOBAL && s1->output_type == TCC_OUTPUT_OBJ) {
                /* undefined symbols with STT_FUNC are confusing gnu ld when
                   linking statically to STT_GNU_IFUNC.  Keep TLS typed,
                   otherwise gnu ld rejects non-TLS refs to TLS definitions. */
                যদি (sym_type != STT_TLS)
                    sym_type = STT_NOTYPE;
            }
#endif
            sym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
        }
        tr[i] = set_elf_sym(s, sym->st_মান, sym->st_size, sym->st_info,
            sym->st_other, sym->st_shndx, (বর্ণ*)s->link->data + sym->st_name);
    }
    /* now update relocations */
    update_relocs(s1, s, tr, first_sym);
    tcc_free(tr);
    /* record text/data/bss output for -bench info */
    প্রতি (i = 0; i < 4; ++i) {
        s = s1->sections[i + 1];
        s1->total_output[i] += s->data_offset - s->sh_offset;
    }
}

ST_FUNC Section *new_section(TCCState *s1, ধ্রুব বর্ণ *name, পূর্ণাঙ্ক sh_type, পূর্ণাঙ্ক sh_flags)
{
    Section *sec;

    sec = tcc_mallocz(পরিমাণ(Section) + strlen(name));
    sec->s1 = s1;
    strcpy(sec->name, name);
    sec->sh_type = sh_type;
    sec->sh_flags = sh_flags;
    বিকল্প(sh_type) {
    পক্ষ SHT_GNU_versym:
        sec->sh_addralign = 2;
        ভঙ্গ;
    পক্ষ SHT_HASH:
    পক্ষ SHT_GNU_HASH:
    পক্ষ SHT_REL:
    পক্ষ SHT_RELA:
    পক্ষ SHT_DYNSYM:
    পক্ষ SHT_SYMTAB:
    পক্ষ SHT_DYNAMIC:
    পক্ষ SHT_GNU_verneed:
    পক্ষ SHT_GNU_verdef:
        sec->sh_addralign = PTR_SIZE;
        ভঙ্গ;
    পক্ষ SHT_STRTAB:
        sec->sh_addralign = 1;
        ভঙ্গ;
    স্বভাব:
        sec->sh_addralign =  PTR_SIZE; /* gcc/pcc default alignment */
        ভঙ্গ;
    }

    যদি (sh_flags & SHF_PRIVATE) {
        dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } অন্যথা {
        sec->sh_অঙ্ক = s1->nb_sections;
        dynarray_add(&s1->sections, &s1->nb_sections, sec);
    }

    প্রত্যাগম sec;
}

ST_FUNC শূন্য init_symtab(Section *s)
{
    পূর্ণাঙ্ক *ptr, nb_buckets = 1;
    put_elf_str(s->link, "");
    section_ptr_add(s, পরিমাণ (ElfW(Sym)));
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + 1) * পরিমাণ(পূর্ণাঙ্ক));
    ptr[0] = nb_buckets;
    ptr[1] = 1;
    memset(ptr + 2, 0, (nb_buckets + 1) * পরিমাণ(পূর্ণাঙ্ক));
}

ST_FUNC Section *new_symtab(TCCState *s1,
                           ধ্রুব বর্ণ *symtab_name, পূর্ণাঙ্ক sh_type, পূর্ণাঙ্ক sh_flags,
                           ধ্রুব বর্ণ *strtab_name,
                           ধ্রুব বর্ণ *hash_name, পূর্ণাঙ্ক hash_sh_flags)
{
    Section *symtab, *strtab, *hash;
    symtab = new_section(s1, symtab_name, sh_type, sh_flags);
    symtab->sh_entsize = পরিমাণ(ElfW(Sym));
    strtab = new_section(s1, strtab_name, SHT_STRTAB, sh_flags);
    symtab->link = strtab;
    hash = new_section(s1, hash_name, SHT_HASH, hash_sh_flags);
    hash->sh_entsize = পরিমাণ(পূর্ণাঙ্ক);
    symtab->hash = hash;
    hash->link = symtab;
    init_symtab(symtab);
    প্রত্যাগম symtab;
}

/* realloc section and set its content to zero */
ST_FUNC শূন্য section_realloc(Section *sec, unsigned long new_size)
{
    unsigned long size;
    unsigned বর্ণ *data;

    size = sec->data_allocated;
    যদি (size == 0)
        size = 1;
    যাবত্ (size < new_size)
        size = size * 2;
    data = tcc_realloc(sec->data, size);
    memset(data + sec->data_allocated, 0, size - sec->data_allocated);
    sec->data = data;
    sec->data_allocated = size;
}

/* reserve at least 'size' bytes aligned per 'align' in section
   'sec' from current offset, and return the aligned offset */
ST_FUNC size_t section_add(Section *sec, addr_t size, পূর্ণাঙ্ক align)
{
    size_t offset, offset1;

    offset = (sec->data_offset + align - 1) & -align;
    offset1 = offset + size;
    যদি (sec->sh_type != SHT_NOBITS && offset1 > sec->data_allocated)
        section_realloc(sec, offset1);
    sec->data_offset = offset1;
    যদি (align > sec->sh_addralign)
        sec->sh_addralign = align;
    প্রত্যাগম offset;
}

/* reserve at least 'size' bytes in section 'sec' from
   sec->data_offset. */
ST_FUNC শূন্য *section_ptr_add(Section *sec, addr_t size)
{
    size_t offset = section_add(sec, size, 1);
    প্রত্যাগম sec->data + offset;
}

#ifndef ELF_OBJ_ONLY
/* reserve at least 'size' bytes from section start */
স্থির শূন্য section_reserve(Section *sec, unsigned long size)
{
    যদি (size > sec->data_allocated)
        section_realloc(sec, size);
    যদি (size > sec->data_offset)
        sec->data_offset = size;
}
#endif

স্থির Section *have_section(TCCState *s1, ধ্রুব বর্ণ *name)
{
    Section *sec;
    পূর্ণাঙ্ক i;
    প্রতি(i = 1; i < s1->nb_sections; i++) {
        sec = s1->sections[i];
        যদি (!strcmp(name, sec->name))
            প্রত্যাগম sec;
    }
    প্রত্যাগম রিক্ত;
}

/* return a reference to a section, and create it if it does not
   exists */
ST_FUNC Section *find_section(TCCState *s1, ধ্রুব বর্ণ *name)
{
    Section *sec = have_section(s1, name);
    যদি (sec)
        প্রত্যাগম sec;
    /* sections are created as PROGBITS */
    প্রত্যাগম new_section(s1, name, SHT_PROGBITS, SHF_ALLOC);
}

/* ------------------------------------------------------------------------- */

ST_FUNC পূর্ণাঙ্ক put_elf_str(Section *s, ধ্রুব বর্ণ *sym)
{
    পূর্ণাঙ্ক offset, len;
    বর্ণ *ptr;

    len = strlen(sym) + 1;
    offset = s->data_offset;
    ptr = section_ptr_add(s, len);
    memmove(ptr, sym, len);
    প্রত্যাগম offset;
}

/* elf symbol hashing function */
স্থির ElfW(Word) elf_hash(ধ্রুব unsigned বর্ণ *name)
{
    ElfW(Word) h = 0, g;

    যাবত্ (*name) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        যদি (g)
            h ^= g >> 24;
        h &= ~g;
    }
    প্রত্যাগম h;
}

/* rebuild hash table of section s */
/* NOTE: we do factorize the hash table code to go faster */
স্থির শূন্য rebuild_hash(Section *s, unsigned পূর্ণাঙ্ক nb_buckets)
{
    ElfW(Sym) *sym;
    পূর্ণাঙ্ক *ptr, *hash, nb_syms, sym_index, h;
    unsigned বর্ণ *strtab;

    strtab = s->link->data;
    nb_syms = s->data_offset / পরিমাণ(ElfW(Sym));

    যদি (!nb_buckets)
        nb_buckets = ((পূর্ণাঙ্ক*)s->hash->data)[0];

    s->hash->data_offset = 0;
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + nb_syms) * পরিমাণ(পূর্ণাঙ্ক));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    memset(hash, 0, (nb_buckets + 1) * পরিমাণ(পূর্ণাঙ্ক));
    ptr += nb_buckets + 1;

    sym = (ElfW(Sym) *)s->data + 1;
    প্রতি(sym_index = 1; sym_index < nb_syms; sym_index++) {
        যদি (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            h = elf_hash(strtab + sym->st_name) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_index;
        } অন্যথা {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}

/* return the symbol number */
ST_FUNC পূর্ণাঙ্ক put_elf_sym(Section *s, addr_t মান, unsigned long size,
    পূর্ণাঙ্ক info, পূর্ণাঙ্ক other, পূর্ণাঙ্ক shndx, ধ্রুব বর্ণ *name)
{
    পূর্ণাঙ্ক name_offset, sym_index;
    পূর্ণাঙ্ক nbuckets, h;
    ElfW(Sym) *sym;
    Section *hs;

    sym = section_ptr_add(s, পরিমাণ(ElfW(Sym)));
    যদি (name && name[0])
        name_offset = put_elf_str(s->link, name);
    অন্যথা
        name_offset = 0;
    /* XXX: endianness */
    sym->st_name = name_offset;
    sym->st_মান = মান;
    sym->st_size = size;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
    sym_index = sym - (ElfW(Sym) *)s->data;
    hs = s->hash;
    যদি (hs) {
        পূর্ণাঙ্ক *ptr, *base;
        ptr = section_ptr_add(hs, পরিমাণ(পূর্ণাঙ্ক));
        base = (পূর্ণাঙ্ক *)hs->data;
        /* only add global or weak symbols. */
        যদি (ELFW(ST_BIND)(info) != STB_LOCAL) {
            /* add another hashing entry */
            nbuckets = base[0];
            h = elf_hash((unsigned বর্ণ *)s->link->data + name_offset) % nbuckets;
            *ptr = base[2 + h];
            base[2 + h] = sym_index;
            base[1]++;
            /* we resize the hash table */
            hs->nb_hashed_syms++;
            যদি (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } অন্যথা {
            *ptr = 0;
            base[1]++;
        }
    }
    প্রত্যাগম sym_index;
}

ST_FUNC পূর্ণাঙ্ক find_elf_sym(Section *s, ধ্রুব বর্ণ *name)
{
    ElfW(Sym) *sym;
    Section *hs;
    পূর্ণাঙ্ক nbuckets, sym_index, h;
    ধ্রুব বর্ণ *name1;

    hs = s->hash;
    যদি (!hs)
        প্রত্যাগম 0;
    nbuckets = ((পূর্ণাঙ্ক *)hs->data)[0];
    h = elf_hash((unsigned বর্ণ *) name) % nbuckets;
    sym_index = ((পূর্ণাঙ্ক *)hs->data)[2 + h];
    যাবত্ (sym_index != 0) {
        sym = &((ElfW(Sym) *)s->data)[sym_index];
        name1 = (বর্ণ *) s->link->data + sym->st_name;
        যদি (!strcmp(name, name1))
            প্রত্যাগম sym_index;
        sym_index = ((পূর্ণাঙ্ক *)hs->data)[2 + nbuckets + sym_index];
    }
    প্রত্যাগম 0;
}

/* return elf symbol value, signal error if 'err' is nonzero, decorate
   name if FORC */
ST_FUNC addr_t get_sym_addr(TCCState *s1, ধ্রুব বর্ণ *name, পূর্ণাঙ্ক err, পূর্ণাঙ্ক forc)
{
    পূর্ণাঙ্ক sym_index;
    ElfW(Sym) *sym;
    বর্ণ buf[256];
    যদি (forc && s1->leading_underscore
#ifdef TCC_TARGET_PE
        /* win32-32bit stdcall symbols always have _ already */
        && !strchr(name, '@')
#endif
        ) {
        buf[0] = '_';
        pstrcpy(buf + 1, পরিমাণ(buf) - 1, name);
        name = buf;
    }
    sym_index = find_elf_sym(s1->symtab, name);
    sym = &((ElfW(Sym) *)s1->symtab->data)[sym_index];
    যদি (!sym_index || sym->st_shndx == SHN_UNDEF) {
        যদি (err)
            tcc_error_noabort("%s not defined", name);
        প্রত্যাগম (addr_t)-1;
    }
    প্রত্যাগম sym->st_মান;
}

/* return elf symbol value */
LIBTCCAPI শূন্য *tcc_get_প্রতীক(TCCState *s, ধ্রুব বর্ণ *name)
{
    addr_t addr = get_sym_addr(s, name, 0, 1);
    প্রত্যাগম addr == -1 ? রিক্ত : (শূন্য*)(uintptr_t)addr;
}

LIBTCCAPI পূর্ণাঙ্ক tcc_add_প্রতীক(TCCState *s1, ধ্রুব বর্ণ *name, ধ্রুব শূন্য *val)
{
#ifdef TCC_TARGET_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s1, 0, name, (uintptr_t)val);
#অন্যথা
    বর্ণ buf[256];
    যদি (s1->leading_underscore) {
        buf[0] = '_';
        pstrcpy(buf + 1, পরিমাণ(buf) - 1, name);
        name = buf;
    }
    set_global_sym(s1, name, রিক্ত, (addr_t)(uintptr_t)val); /* NULL: SHN_ABS */
#endif
    প্রত্যাগম 0;
}

/* list elf symbol names and values */
ST_FUNC শূন্য list_elf_symbols(TCCState *s, শূন্য *ctx,
    শূন্য (*প্রতীক_cb)(শূন্য *ctx, ধ্রুব বর্ণ *name, ধ্রুব শূন্য *val))
{
    ElfW(Sym) *sym;
    Section *symtab;
    পূর্ণাঙ্ক sym_index, end_sym;
    ধ্রুব বর্ণ *name;
    unsigned বর্ণ sym_vis, sym_bind;

    symtab = s->symtab;
    end_sym = symtab->data_offset / পরিমাণ (ElfSym);
    প্রতি (sym_index = 0; sym_index < end_sym; ++sym_index) {
        sym = &((ElfW(Sym) *)symtab->data)[sym_index];
        যদি (sym->st_মান) {
            name = (বর্ণ *) symtab->link->data + sym->st_name;
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            sym_vis = ELFW(ST_VISIBILITY)(sym->st_other);
            যদি (sym_bind == STB_GLOBAL && sym_vis == STV_DEFAULT)
                প্রতীক_cb(ctx, name, (শূন্য*)(uintptr_t)sym->st_মান);
        }
    }
}

/* list elf symbol names and values */
LIBTCCAPI শূন্য tcc_list_symbols(TCCState *s, শূন্য *ctx,
    শূন্য (*প্রতীক_cb)(শূন্য *ctx, ধ্রুব বর্ণ *name, ধ্রুব শূন্য *val))
{
    list_elf_symbols(s, ctx, প্রতীক_cb);
}

#ifndef ELF_OBJ_ONLY
স্থির শূন্য
version_add (TCCState *s1)
{
    পূর্ণাঙ্ক i;
    ElfW(Sym) *sym;
    ElfW(Verneed) *vn = রিক্ত;
    Section *symtab;
    পূর্ণাঙ্ক sym_index, end_sym, nb_versions = 2, nb_entries = 0;
    ElfW(Half) *versym;
    ধ্রুব বর্ণ *name;

    যদি (0 == nb_sym_versions)
        প্রত্যাগম;
    versym_section = new_section(s1, ".gnu.version", SHT_GNU_versym, SHF_ALLOC);
    versym_section->sh_entsize = পরিমাণ(ElfW(Half));
    versym_section->link = s1->dynsym;

    /* add needed symbols */
    symtab = s1->dynsym;
    end_sym = symtab->data_offset / পরিমাণ (ElfSym);
    versym = section_ptr_add(versym_section, end_sym * পরিমাণ(ElfW(Half)));
    প্রতি (sym_index = 1; sym_index < end_sym; ++sym_index) {
        পূর্ণাঙ্ক dllindex, verndx;
        sym = &((ElfW(Sym) *)symtab->data)[sym_index];
        name = (বর্ণ *) symtab->link->data + sym->st_name;
        dllindex = find_elf_sym(s1->dynsymtab_section, name);
        verndx = (dllindex && dllindex < nb_sym_to_version)
                 ? sym_to_version[dllindex] : -1;
        যদি (verndx >= 0
            /* XXX: on android, clang refuses to link with a libtcc.so made by tcc
               when defined symbols have a version > 1 or when the version is '0'.
               Whereas version '1' for example for 'signal' in an exe defeats
               bcheck's signal_redir. */
            && (sym->st_shndx == SHN_UNDEF || (s1->output_type & TCC_OUTPUT_EXE))
            ) {
            যদি (!sym_versions[verndx].out_index)
              sym_versions[verndx].out_index = nb_versions++;
            versym[sym_index] = sym_versions[verndx].out_index;
        } অন্যথা {
            versym[sym_index] = 1; /* (*global*) */
        }
        //printf("SYM %d %s\n", versym[sym_index], name);
    }
    /* generate verneed section, but not when it will be empty.  Some
       dynamic linkers look at their contents even when DTVERNEEDNUM and
       section size is zero.  */
    যদি (nb_versions > 2) {
        verneed_section = new_section(s1, ".gnu.version_r",
                                      SHT_GNU_verneed, SHF_ALLOC);
        verneed_section->link = s1->dynsym->link;
        প্রতি (i = nb_sym_versions; i-- > 0;) {
            সংরচনা sym_version *sv = &sym_versions[i];
            পূর্ণাঙ্ক n_same_libs = 0, prev;
            size_t vnofs;
            ElfW(Vernaux) *vna = 0;
            যদি (sv->out_index < 1)
              অনুবর্ত;

            /* make sure that a DT_NEEDED tag is put */
            /* abitest-tcc fails on older i386-linux with "ld-linux.so.2" DT_NEEDED
               ret_int_test... Inconsistency detected by ld.so: dl-minimal.c: 148:
               realloc: Assertion `ptr == alloc_last_block' failed! */
            যদি (strcmp(sv->lib, "ld-linux.so.2"))
                tcc_add_dllref(s1, sv->lib, 0);

            vnofs = section_add(verneed_section, পরিমাণ(*vn), 1);
            vn = (ElfW(Verneed)*)(verneed_section->data + vnofs);
            vn->vn_version = 1;
            vn->vn_file = put_elf_str(verneed_section->link, sv->lib);
            vn->vn_aux = পরিমাণ (*vn);
            কুরু {
                prev = sv->prev_same_lib;
                যদি (sv->out_index > 0) {
                    vna = section_ptr_add(verneed_section, পরিমাণ(*vna));
                    vna->vna_hash = elf_hash ((ধ্রুব unsigned বর্ণ *)sv->version);
                    vna->vna_flags = 0;
                    vna->vna_other = sv->out_index;
                    sv->out_index = -2;
                    vna->vna_name = put_elf_str(verneed_section->link, sv->version);
                    vna->vna_next = পরিমাণ (*vna);
                    //printf("LIB %d %s %s\n", vna->vna_other, sv->lib, verneed_section->link->data + vna->vna_name);
                    n_same_libs++;
                }
                যদি (prev >= 0)
                  sv = &sym_versions[prev];
            } যাবত্(prev >= 0);
            vna->vna_next = 0;
            vn = (ElfW(Verneed)*)(verneed_section->data + vnofs);
            vn->vn_cnt = n_same_libs;
            vn->vn_next = পরিমাণ(*vn) + n_same_libs * পরিমাণ(*vna);
            nb_entries++;
        }
        যদি (vn)
          vn->vn_next = 0;
        verneed_section->sh_info = nb_entries;
    }
    dt_verneednum = nb_entries;
}
#endif /* ndef ELF_OBJ_ONLY */

/* catch .tbss also */
স্থির পূর্ণাঙ্ক IS_BSS(TCCState *s1, পূর্ণাঙ্ক ndx)
{
    প্রত্যাগম ndx == SHN_COMMON
     || (ndx < s1->nb_sections
         && s1->sections[ndx]->sh_type == SHT_NOBITS);
}

/* add an elf symbol : check if it is already defined and patch
   it. Return symbol index. NOTE that sh_num can be SHN_UNDEF. */
ST_FUNC পূর্ণাঙ্ক set_elf_sym(Section *s, addr_t মান, unsigned long size,
                       পূর্ণাঙ্ক info, পূর্ণাঙ্ক other, পূর্ণাঙ্ক shndx, ধ্রুব বর্ণ *name)
{
    TCCState *s1 = s->s1;
    ElfW(Sym) *esym;
    পূর্ণাঙ্ক sym_bind, sym_index, sym_type, esym_bind;
    unsigned বর্ণ sym_vis, esym_vis, new_vis;

    sym_bind = ELFW(ST_BIND)(info);
    sym_type = ELFW(ST_TYPE)(info);
    sym_vis = ELFW(ST_VISIBILITY)(other);

    যদি (sym_bind != STB_LOCAL) {
        /* we search global or weak symbols */
        sym_index = find_elf_sym(s, name);
        যদি (!sym_index)
            গচ্ছ do_def;
        esym = &((ElfW(Sym) *)s->data)[sym_index];
        যদি (esym->st_মান == মান && esym->st_size == size && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            প্রত্যাগম sym_index;
        যদি (esym->st_shndx != SHN_UNDEF) {
            esym_bind = ELFW(ST_BIND)(esym->st_info);
            /* propagate the most constraining visibility */
            /* STV_DEFAULT(0)<STV_PROTECTED(3)<STV_HIDDEN(2)<STV_INTERNAL(1) */
            esym_vis = ELFW(ST_VISIBILITY)(esym->st_other);
            যদি (esym_vis == STV_DEFAULT) {
                new_vis = sym_vis;
            } অন্যথা যদি (sym_vis == STV_DEFAULT) {
                new_vis = esym_vis;
            } অন্যথা {
                new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
            }
            esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
                             | new_vis;
            যদি (shndx == SHN_UNDEF) {
                /* ignore adding of undefined symbol if the
                   corresponding symbol is already defined */
            } অন্যথা যদি (sym_bind == STB_GLOBAL && esym_bind == STB_WEAK) {
                /* global overrides weak, so patch */
                গচ্ছ do_patch;
            } অন্যথা যদি (sym_bind == STB_WEAK && esym_bind == STB_GLOBAL) {
                /* weak is ignored if already global */
            } অন্যথা যদি (sym_bind == STB_WEAK && esym_bind == STB_WEAK) {
                /* keep first-found weak definition, ignore subsequents */
            } অন্যথা যদি (sym_vis == STV_HIDDEN || sym_vis == STV_INTERNAL) {
                /* ignore hidden symbols after */
            } অন্যথা যদি (s->sh_flags & SHF_DYNSYM) {
                /* we accept that two DLL define the same symbol */
            } অন্যথা যদি (!IS_BSS(s1, shndx) && IS_BSS(s1, esym->st_shndx)) {
                /* data symbol gets precedence over common/bss */
                গচ্ছ do_patch;
            } অন্যথা যদি (IS_BSS(s1, shndx)) {
                /* data symbol keeps precedence over common/bss */
	    } অন্যথা যদি (esym->st_other & ST_ASM_SET) {
		/* If the existing symbol came from an asm .set
		   we can override.  */
		গচ্ছ do_patch;
            } অন্যথা {
#যদি 0
                printf("new_bind=%x new_shndx=%x new_vis=%x old_bind=%x old_shndx=%x old_vis=%x\n",
                       sym_bind, shndx, new_vis, esym_bind, esym->st_shndx, esym_vis);
#endif
                tcc_error_noabort("link symbol '%s' defined twice", name);
            }
        } অন্যথা {
            esym->st_other = other;
        do_patch:
            esym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
            esym->st_shndx = shndx;
            esym->st_মান = মান;
            esym->st_size = size;
        }
    } অন্যথা {
    do_def:
        sym_index = put_elf_sym(s, মান, size,
                                ELFW(ST_INFO)(sym_bind, sym_type), other,
                                shndx, name);
    }
    প্রত্যাগম sym_index;
}

/* put relocation */
ST_FUNC শূন্য put_elf_reloca(Section *symtab, Section *s, unsigned long offset,
                            পূর্ণাঙ্ক type, পূর্ণাঙ্ক প্রতীক, addr_t addend)
{
    TCCState *s1 = s->s1;
    বর্ণ buf[256];
    Section *sr;
    ElfW_Rel *rel;

    sr = s->reloc;
    যদি (!sr) {
        /* if no relocation section, create it */
        snprintf(buf, পরিমাণ(buf), REL_SECTION_FMT, s->name);
        /* if the symtab is allocated, then we consider the relocation
           are also */
        sr = new_section(s->s1, buf, SHT_RELX, symtab->sh_flags);
        sr->sh_entsize = পরিমাণ(ElfW_Rel);
        sr->link = symtab;
        sr->sh_info = s->sh_অঙ্ক;
        s->reloc = sr;
    }
    rel = section_ptr_add(sr, পরিমাণ(ElfW_Rel));
    rel->r_offset = offset;
    rel->r_info = ELFW(R_INFO)(প্রতীক, type);
#যদি SHT_RELX == SHT_RELA
    rel->r_addend = addend;
#endif
    যদি (SHT_RELX != SHT_RELA && addend)
        tcc_error_noabort("non-zero addend on REL architecture");
}

ST_FUNC শূন্য put_elf_reloc(Section *symtab, Section *s, unsigned long offset,
                           পূর্ণাঙ্ক type, পূর্ণাঙ্ক প্রতীক)
{
    put_elf_reloca(symtab, s, offset, type, প্রতীক, 0);
}

ST_FUNC সংরচনা sym_attr *get_sym_attr(TCCState *s1, পূর্ণাঙ্ক index, পূর্ণাঙ্ক alloc)
{
    পূর্ণাঙ্ক n;
    সংরচনা sym_attr *tab;

    যদি (index >= s1->nb_sym_attrs) {
        যদি (!alloc)
            প্রত্যাগম s1->sym_attrs;
        /* find immediately bigger power of 2 and reallocate array */
        n = 1;
        যাবত্ (index >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * পরিমাণ(*s1->sym_attrs));
        s1->sym_attrs = tab;
        memset(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * পরিমাণ(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    প্রত্যাগম &s1->sym_attrs[index];
}

স্থির শূন্য update_relocs(TCCState *s1, Section *s, পূর্ণাঙ্ক *old_to_new_syms, পূর্ণাঙ্ক first_sym)
{
    পূর্ণাঙ্ক i, type, sym_index;
    Section *sr;
    ElfW_Rel *rel;

    প্রতি(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        যদি (sr->sh_type == SHT_RELX && sr->link == s) {
            for_each_elem(sr, 0, rel, ElfW_Rel) {
                sym_index = ELFW(R_SYM)(rel->r_info);
                type = ELFW(R_TYPE)(rel->r_info);
                যদি ((sym_index -= first_sym) < 0)
                    অনুবর্ত; /* zero sym_index in reloc (can happen with asm) */
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
স্থির শূন্য sort_syms(TCCState *s1, Section *s)
{
    পূর্ণাঙ্ক *old_to_new_syms;
    ElfW(Sym) *new_syms;
    পূর্ণাঙ্ক nb_syms, i;
    ElfW(Sym) *p, *q;

    nb_syms = s->data_offset / পরিমাণ(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * পরিমাণ(ElfW(Sym)));
    old_to_new_syms = tcc_malloc(nb_syms * পরিমাণ(পূর্ণাঙ্ক));

    /* first pass for local symbols */
    p = (ElfW(Sym) *)s->data;
    q = new_syms;
    প্রতি(i = 0; i < nb_syms; i++) {
        যদি (ELFW(ST_BIND)(p->st_info) == STB_LOCAL) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    /* save the number of local symbols in section header */
    যদি( s->sh_size )    /* this 'if' makes IDA happy */
        s->sh_info = q - new_syms;

    /* then second pass for non local symbols */
    p = (ElfW(Sym) *)s->data;
    প্রতি(i = 0; i < nb_syms; i++) {
        যদি (ELFW(ST_BIND)(p->st_info) != STB_LOCAL) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }

    /* we copy the new symbols to the old */
    memcpy(s->data, new_syms, nb_syms * পরিমাণ(ElfW(Sym)));
    tcc_free(new_syms);

    update_relocs(s1, s, old_to_new_syms, 0);
    tcc_free(old_to_new_syms);
}

#ifndef ELF_OBJ_ONLY
/* See: https://flapenguin.me/elf-dt-gnu-hash */
#define	ELFCLASS_BITS (PTR_SIZE * 8)

স্থির Section *create_gnu_hash(TCCState *s1)
{
    পূর্ণাঙ্ক nb_syms, i, ndef, nbuckets, symoffset, bloom_size, bloom_shift;
    ElfW(Sym) *p;
    Section *gnu_hash;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr;

    gnu_hash = new_section(s1, ".gnu.hash", SHT_GNU_HASH, SHF_ALLOC);
    gnu_hash->link = dynsym->hash->link;

    nb_syms = dynsym->data_offset / পরিমাণ(ElfW(Sym));

    /* count def symbols */
    ndef = 0;
    p = (ElfW(Sym) *)dynsym->data;
    প্রতি(i = 0; i < nb_syms; i++, p++)
        ndef += p->st_shndx != SHN_UNDEF;

    /* calculate gnu hash sizes and fill header */
    nbuckets = ndef / 4 + 1;
    symoffset = nb_syms - ndef;
    bloom_shift = PTR_SIZE == 8 ? 6 : 5;
    bloom_size = 1; /* must be power of two */
    যাবত্ (ndef >= bloom_size * (1 << (bloom_shift - 3)))
	bloom_size *= 2;
    ptr = section_ptr_add(gnu_hash, 4 * 4 +
				    PTR_SIZE * bloom_size +
				    nbuckets * 4 +
				    ndef * 4);
    ptr[0] = nbuckets;
    ptr[1] = symoffset;
    ptr[2] = bloom_size;
    ptr[3] = bloom_shift;
    প্রত্যাগম gnu_hash;
}

স্থির Elf32_Word elf_gnu_hash (ধ্রুব unsigned বর্ণ *name)
{
    Elf32_Word h = 5381;
    unsigned বর্ণ c;

    যাবত্ ((c = *name++))
        h = h * 33 + c;
    প্রত্যাগম h;
}

স্থির শূন্য update_gnu_hash(TCCState *s1, Section *gnu_hash)
{
    পূর্ণাঙ্ক *old_to_new_syms;
    ElfW(Sym) *new_syms;
    পূর্ণাঙ্ক nb_syms, i, nbuckets, bloom_size, bloom_shift;
    ElfW(Sym) *p, *q;
    Section *vs;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr, *buckets, *chain, *hash;
    unsigned পূর্ণাঙ্ক *nextbuck;
    addr_t *bloom;
    unsigned বর্ণ *strtab;
    সংরচনা { পূর্ণাঙ্ক first, last; } *buck;

    strtab = dynsym->link->data;
    nb_syms = dynsym->data_offset / পরিমাণ(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * পরিমাণ(ElfW(Sym)));
    old_to_new_syms = tcc_malloc(nb_syms * পরিমাণ(পূর্ণাঙ্ক));
    hash = tcc_malloc(nb_syms * পরিমাণ(Elf32_Word));
    nextbuck = tcc_malloc(nb_syms * পরিমাণ(পূর্ণাঙ্ক));

    /* calculate hashes and copy undefs */
    p = (ElfW(Sym) *)dynsym->data;
    q = new_syms;
    প্রতি(i = 0; i < nb_syms; i++, p++) {
        যদি (p->st_shndx == SHN_UNDEF) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
	অন্যথা
	    hash[i] = elf_gnu_hash(strtab + p->st_name);
    }

    ptr = (Elf32_Word *) gnu_hash->data;
    nbuckets = ptr[0];
    bloom_size = ptr[2];
    bloom_shift = ptr[3];
    bloom = (addr_t *) (শূন্য *) &ptr[4];
    buckets = (Elf32_Word*) (শূন্য *) &bloom[bloom_size];
    chain = &buckets[nbuckets];
    buck = tcc_malloc(nbuckets * পরিমাণ(*buck));

    যদি (gnu_hash->data_offset != 4 * 4 +
				 PTR_SIZE * bloom_size +
				 nbuckets * 4 +
				 (nb_syms - (q - new_syms)) * 4)
	tcc_error_noabort ("gnu_hash size incorrect");

    /* find buckets */
    প্রতি(i = 0; i < nbuckets; i++)
	buck[i].first = -1;

    p = (ElfW(Sym) *)dynsym->data;
    প্রতি(i = 0; i < nb_syms; i++, p++)
        যদি (p->st_shndx != SHN_UNDEF) {
	    পূর্ণাঙ্ক bucket = hash[i] % nbuckets;

	    যদি (buck[bucket].first == -1)
		buck[bucket].first = buck[bucket].last = i;
	    অন্যথা {
		nextbuck[buck[bucket].last] = i;
		buck[bucket].last = i;
	    }
	}

    /* fill buckets/chains/bloom and sort symbols */
    p = (ElfW(Sym) *)dynsym->data;
    প্রতি(i = 0; i < nbuckets; i++) {
	পূর্ণাঙ্ক cur = buck[i].first;

	যদি (cur != -1) {
	    buckets[i] = q - new_syms;
	    প্রতি (;;) {
                old_to_new_syms[cur] = q - new_syms;
                *q++ = p[cur];
	        *chain++ = hash[cur] & ~1;
		bloom[(hash[cur] / ELFCLASS_BITS) % bloom_size] |=
		    (addr_t)1 << (hash[cur] % ELFCLASS_BITS) |
		    (addr_t)1 << ((hash[cur] >> bloom_shift) % ELFCLASS_BITS);
		যদি (cur == buck[i].last)
		    ভঙ্গ;
		cur = nextbuck[cur];
	    }
	    chain[-1] |= 1;
	}
    }

    memcpy(dynsym->data, new_syms, nb_syms * পরিমাণ(ElfW(Sym)));
    tcc_free(new_syms);
    tcc_free(hash);
    tcc_free(buck);
    tcc_free(nextbuck);

    update_relocs(s1, dynsym, old_to_new_syms, 0);

    /* modify the versions */
    vs = versym_section;
    যদি (vs) {
	ElfW(Half) *newver, *versym = (ElfW(Half) *)vs->data;

	যদি (1/*versym*/) {
            newver = tcc_malloc(nb_syms * পরিমাণ(*newver));
	    প্রতি (i = 0; i < nb_syms; i++)
	        newver[old_to_new_syms[i]] = versym[i];
	    memcpy(vs->data, newver, nb_syms * পরিমাণ(*newver));
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
ST_FUNC শূন্য relocate_syms(TCCState *s1, Section *symtab, পূর্ণাঙ্ক do_resolve)
{
    ElfW(Sym) *sym;
    পূর্ণাঙ্ক sym_bind, sh_অঙ্ক;
    ধ্রুব বর্ণ *name;

    for_each_elem(symtab, 1, sym, ElfW(Sym)) {
        sh_অঙ্ক = sym->st_shndx;
        যদি (sh_অঙ্ক == SHN_UNDEF) {
            যদি (do_resolve == 2) /* relocating dynsym */
                অনুবর্ত;
            name = (বর্ণ *) s1->symtab->link->data + sym->st_name;
            /* Use ld.so to resolve symbol for us (for tcc -run) */
            যদি (do_resolve) {
#যদি defined TCC_IS_NATIVE && !defined TCC_TARGET_PE
                /* dlsym() needs the undecorated name.  */
                ধ্রুব বর্ণ *name_ud = &name[s1->leading_underscore];
                শূন্য *addr = রিক্ত;
                যদি (!s1->nostdlib)
                    addr = dlsym(RTLD_DEFAULT, name_ud);
		যদি (addr == রিক্ত) {
		    পূর্ণাঙ্ক i;
		    প্রতি (i = 0; i < s1->nb_loaded_dlls; i++)
                        যদি ((addr = dlsym(s1->loaded_dlls[i]->handle, name_ud)))
			    ভঙ্গ;
		}
                যদি (addr) {
                    sym->st_মান = (addr_t) addr;
#ifdef DEBUG_RELOC
		    printf ("relocate_sym: %s -> 0x%lx\n", name, sym->st_মান);
#endif
                    গচ্ছ found;
                }
#endif
            /* if dynamic symbol exist, it will be used in relocate_section */
            } অন্যথা যদি (s1->dynsym && find_elf_sym(s1->dynsym, name))
                গচ্ছ found;
            /* XXX: _fp_hw seems to be part of the ABI, so we ignore
               it */
            যদি (!strcmp(name, "_fp_hw"))
                গচ্ছ found;
            /* only weak symbols are accepted to be undefined. Their
               value is zero */
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            যদি (sym_bind == STB_WEAK)
                sym->st_মান = 0;
            অন্যথা
                tcc_error_noabort("unresolved reference to '%s'", name);

        } অন্যথা যদি (sh_অঙ্ক < SHN_LORESERVE) {
            /* add section base */
            sym->st_মান += s1->sections[sym->st_shndx]->sh_addr;
        }
    found: ;
    }
}

/* relocate a given section (CPU dependent) by applying the relocations
   in the associated relocation section */
স্থির শূন্য relocate_section(TCCState *s1, Section *s, Section *sr)
{
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    পূর্ণাঙ্ক type, sym_index;
    unsigned বর্ণ *ptr;
    addr_t tgt, addr;
    পূর্ণাঙ্ক is_dwarf = s->sh_অঙ্ক >= s1->dwlo && s->sh_অঙ্ক < s1->dwhi;

    qrel = (ElfW_Rel *)sr->data;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
	যদি (s->data == রিক্ত) /* bss */
	    অনুবর্ত;
        ptr = s->data + rel->r_offset;
        sym_index = ELFW(R_SYM)(rel->r_info);
        sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
        type = ELFW(R_TYPE)(rel->r_info);
        tgt = sym->st_মান;
#যদি SHT_RELX == SHT_RELA
        tgt += rel->r_addend;
#endif
        যদি (is_dwarf && type == R_DATA_32DW
            && sym->st_shndx >= s1->dwlo && sym->st_shndx < s1->dwhi) {
            /* dwarf section relocation to each other */
            add32le(ptr, tgt - s1->sections[sym->st_shndx]->sh_addr);
            অনুবর্ত;
        }
        addr = s->sh_addr + rel->r_offset;
        relocate(s1, rel, type, ptr, addr, tgt);
    }

#ifndef ELF_OBJ_ONLY
    /* if the relocation is allocated, we change its symbol table */
    যদি (sr->sh_flags & SHF_ALLOC) {
        sr->link = s1->dynsym;
        যদি (s1->output_type & TCC_OUTPUT_DYN) {
            size_t r = (uint8_t*)qrel - sr->data;
            যদি (পরিমাণ ((Stab_Sym*)0)->n_মান < PTR_SIZE
                && 0 == strcmp(s->name, ".stab"))
                r = 0; /* cannot apply 64bit relocation to 32bit value */
            sr->data_offset = sr->sh_size = r;
#ifdef CONFIG_TCC_PIE
            যদি (r && (s->sh_flags & SHF_EXECINSTR))
                tcc_warning("%d relocations to %s", (unsigned)(r / পরিমাণ *qrel), s->name);
#endif
        }
    }
#endif

#ifdef TCC_TARGET_RISCV64
    dynarray_reset(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries);
#endif
}

/* relocate all sections */
ST_FUNC শূন্য relocate_sections(TCCState *s1)
{
    পূর্ণাঙ্ক i;
    Section *s, *sr;

    প্রতি (i = 1; i < s1->nb_sections; ++i) {
        sr = s1->sections[i];
        যদি (sr->sh_type != SHT_RELX)
            অনুবর্ত;
        s = s1->sections[sr->sh_info];
#ifndef TCC_TARGET_MACHO
        যদি (s != s1->got
            || s1->static_link
            || s1->output_type == TCC_OUTPUT_MEMORY)
#endif
        {
            relocate_section(s1, s, sr);
        }
#ifndef ELF_OBJ_ONLY
        যদি (sr->sh_flags & SHF_ALLOC) {
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
স্থির পূর্ণাঙ্ক prepare_dynamic_rel(TCCState *s1, Section *sr)
{
    পূর্ণাঙ্ক গুনতি_2 = 0;
#যদি defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || \
    defined(TCC_TARGET_ARM) || defined(TCC_TARGET_ARM64) || \
    defined(TCC_TARGET_RISCV64)
    ElfW_Rel *rel;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
        পূর্ণাঙ্ক sym_index = ELFW(R_SYM)(rel->r_info);
        পূর্ণাঙ্ক type = ELFW(R_TYPE)(rel->r_info);
        বিকল্প(type) {
#যদি defined(TCC_TARGET_I386)
        পক্ষ R_386_32:
            যদি (!get_sym_attr(s1, sym_index, 0)->dyn_index
                && ((ElfW(Sym)*)symtab_section->data + sym_index)->st_shndx == SHN_UNDEF) {
                /* don't fixup unresolved (weak) symbols */
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_RELATIVE);
                ভঙ্গ;
            }
#নোচেদ্যদি defined(TCC_TARGET_X86_64)
        পক্ষ R_X86_64_32:
        পক্ষ R_X86_64_32S:
        পক্ষ R_X86_64_64:
#নোচেদ্যদি defined(TCC_TARGET_ARM)
        পক্ষ R_ARM_ABS32:
        পক্ষ R_ARM_TARGET1:
#নোচেদ্যদি defined(TCC_TARGET_ARM64)
        পক্ষ R_AARCH64_ABS32:
        পক্ষ R_AARCH64_ABS64:
#নোচেদ্যদি defined(TCC_TARGET_RISCV64)
        পক্ষ R_RISCV_32:
        পক্ষ R_RISCV_64:
#endif
            গুনতি_2++;
            ভঙ্গ;
#যদি defined(TCC_TARGET_I386)
        পক্ষ R_386_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    যদি (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_PLT32);
	        ভঙ্গ;
	    }
	}
#নোচেদ্যদি defined(TCC_TARGET_X86_64)
        পক্ষ R_X86_64_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    যদি (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_index, R_X86_64_PLT32);
	        ভঙ্গ;
	    }
	}
#নোচেদ্যদি defined(TCC_TARGET_ARM64)
        পক্ষ R_AARCH64_PREL32:
#endif
            যদি (s1->output_type != TCC_OUTPUT_DLL)
                ভঙ্গ;
            যদি (get_sym_attr(s1, sym_index, 0)->dyn_index)
                গুনতি_2++;
            ভঙ্গ;
        স্বভাব:
            ভঙ্গ;
        }
    }
#endif
    প্রত্যাগম গুনতি_2;
}
#endif

#ifdef NEED_BUILD_GOT
স্থির পূর্ণাঙ্ক build_got(TCCState *s1)
{
    /* if no got, then create it */
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    s1->got->sh_entsize = 4;
    /* keep space for _DYNAMIC pointer and two dummy got entries */
    section_ptr_add(s1->got, 3 * PTR_SIZE);
    প্রত্যাগম set_elf_sym(symtab_section, 0, 0, ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
        0, s1->got->sh_অঙ্ক, "_GLOBAL_OFFSET_TABLE_");
}

/* Create a GOT and (for function call) a PLT entry corresponding to a symbol
   in s1->symtab. When creating the dynamic symbol table entry for the GOT
   relocation, use 'size' and 'info' for the corresponding symbol metadata.
   Returns the offset of the GOT or (if any) PLT entry. */
স্থির সংরচনা sym_attr * put_got_entry(TCCState *s1, পূর্ণাঙ্ক dyn_reloc_type,
                                       পূর্ণাঙ্ক sym_index)
{
    পূর্ণাঙ্ক need_plt_entry;
    ধ্রুব বর্ণ *name;
    ElfW(Sym) *sym;
    সংরচনা sym_attr *attr;
    unsigned got_offset;
    বর্ণ plt_name[200];
    পূর্ণাঙ্ক len;
    Section *s_rel;

    need_plt_entry = (dyn_reloc_type == R_JMP_SLOT);
    attr = get_sym_attr(s1, sym_index, 1);

    /* In case a function is both called and its address taken 2 GOT entries
       are created, one for taking the address (GOT) and the other for the PLT
       entry (PLTGOT).  */
    যদি (need_plt_entry ? attr->plt_offset : attr->got_offset)
        প্রত্যাগম attr;

    s_rel = s1->got;
    যদি (need_plt_entry) {
        যদি (!s1->plt) {
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
    name = (বর্ণ *) symtab_section->link->data + sym->st_name;
    //printf("sym %d %s\n", need_plt_entry, name);

    যদি (s1->dynsym) {
	যদি (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
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
	} অন্যথা {
	    যদি (0 == attr->dyn_index)
                attr->dyn_index = set_elf_sym(s1->dynsym, sym->st_মান,
                                              sym->st_size, sym->st_info, 0,
                                              sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s_rel, got_offset, dyn_reloc_type,
			  attr->dyn_index);
	}
    } অন্যথা {
        put_elf_reloc(symtab_section, s1->got, got_offset, dyn_reloc_type,
                      sym_index);
    }

    যদি (need_plt_entry) {
        attr->plt_offset = create_plt_entry(s1, got_offset, attr);

        /* create a symbol 'sym@plt' for the PLT jump vector */
        len = strlen(name);
        যদি (len > পরিমাণ plt_name - 5)
            len = পরিমাণ plt_name - 5;
        memcpy(plt_name, name, len);
        strcpy(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_offset, 0,
            ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0, s1->plt->sh_অঙ্ক, plt_name);
    } অন্যথা {
        attr->got_offset = got_offset;
    }

    প্রত্যাগম attr;
}

/* build GOT and PLT entries */
/* Two passes because R_JMP_SLOT should become first. Some targets
   (arm, arm64) do not allow mixing R_JMP_SLOT and R_GLOB_DAT. */
ST_FUNC শূন্য build_got_entries(TCCState *s1, পূর্ণাঙ্ক got_sym)
{
    Section *s;
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    পূর্ণাঙ্ক i, type, gotplt_entry, reloc_type, sym_index;
    সংরচনা sym_attr *attr;
    পূর্ণাঙ্ক pass = 0;
redo:
    প্রতি(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        যদি (s->sh_type != SHT_RELX)
            অনুবর্ত;
        /* no need to handle got relocations */
        যদি (s->link != symtab_section)
            অনুবর্ত;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_entry = gotplt_entry_type(type);
            যদি (gotplt_entry == -1) {
                tcc_error_noabort ("Unknown relocation type for got: %d", type);
                অনুবর্ত;
            }
            sym_index = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];

            যদি (gotplt_entry == NO_GOTPLT_ENTRY) {
                অনুবর্ত;
            }

            /* Automatically create PLT/GOT [entry] if it is an undefined
	       reference (resolved at runtime), or the symbol is absolute,
	       probably created by tcc_add_symbol, and thus on 64-bit
	       targets might be too far from application code.  */
            যদি (gotplt_entry == AUTO_GOTPLT_ENTRY) {
                যদি (sym->st_shndx == SHN_UNDEF) {
                    ElfW(Sym) *esym;
		    পূর্ণাঙ্ক dynindex;
                    যদি (!PCRELATIVE_DLLPLT
                        && (s1->output_type & TCC_OUTPUT_DYN))
                        অনুবর্ত;
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
		    যদি (s1->dynsym) {
			/* dynsym isn't set for -run :-/  */
			dynindex = get_sym_attr(s1, sym_index, 0)->dyn_index;
			esym = (ElfW(Sym) *)s1->dynsym->data + dynindex;
			যদি (dynindex
			    && (ELFW(ST_TYPE)(esym->st_info) == STT_FUNC
				|| (ELFW(ST_TYPE)(esym->st_info) == STT_NOTYPE
				    && ELFW(ST_TYPE)(sym->st_info) == STT_FUNC)))
			    গচ্ছ jmp_slot;
		    }
                } অন্যথা যদি (sym->st_shndx == SHN_ABS) {
                    যদি (sym->st_মান == 0) /* from tcc_add_btstub() */
                        অনুবর্ত;
#ifndef TCC_TARGET_ARM
                    যদি (PTR_SIZE != 8)
                        অনুবর্ত;
#endif
                    /* from tcc_add_symbol(): on 64 bit platforms these
                       need to go through .got */
                } অন্যথা
                    অনুবর্ত;
            }

#ifdef TCC_TARGET_I386
            যদি ((type == R_386_PLT32 || type == R_386_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		যদি (pass != 0)
		    অনুবর্ত;
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_PC32);
                অনুবর্ত;
            }
#endif
#ifdef TCC_TARGET_X86_64
            যদি ((type == R_X86_64_PLT32 || type == R_X86_64_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		যদি (pass != 0)
		    অনুবর্ত;
                rel->r_info = ELFW(R_INFO)(sym_index, R_X86_64_PC32);
                অনুবর্ত;
            }
#endif
            reloc_type = code_reloc(type);
            যদি (reloc_type == -1) {
                tcc_error_noabort ("Unknown relocation type: %d", type);
                অনুবর্ত;
            }

            যদি (reloc_type != 0) {
        jmp_slot:
	        যদি (pass != 0)
                    অনুবর্ত;
                reloc_type = R_JMP_SLOT;
            } অন্যথা {
	        যদি (pass != 1)
                    অনুবর্ত;
                reloc_type = R_GLOB_DAT;
            }

            যদি (!s1->got)
                got_sym = build_got(s1);

            যদি (gotplt_entry == BUILD_GOT_ONLY)
                অনুবর্ত;

            attr = put_got_entry(s1, reloc_type, sym_index);

            যদি (reloc_type == R_JMP_SLOT)
                rel->r_info = ELFW(R_INFO)(attr->plt_sym, type);
        }
    }
    যদি (++pass < 2)
        গচ্ছ redo;
    /* .rel.plt refers to .got actually */
    যদি (s1->plt && s1->plt->reloc)
        s1->plt->reloc->sh_info = s1->got->sh_অঙ্ক;
    যদি (got_sym) /* set size */
        ((ElfW(Sym)*)symtab_section->data)[got_sym].st_size = s1->got->data_offset;
}
#endif /* def NEED_BUILD_GOT */

ST_FUNC পূর্ণাঙ্ক set_global_sym(TCCState *s1, ধ্রুব বর্ণ *name, Section *sec, addr_t offs)
{
    পূর্ণাঙ্ক shn = sec ? sec->sh_অঙ্ক : offs || !name ? SHN_ABS : SHN_UNDEF;
    যদি (sec && offs == -1)
        offs = sec->data_offset;
    প্রত্যাগম set_elf_sym(symtab_section, offs, 0,
        ELFW(ST_INFO)(name ? STB_GLOBAL : STB_LOCAL, STT_NOTYPE), 0, shn, name);
}

স্থির শূন্য add_init_array_defines(TCCState *s1, ধ্রুব বর্ণ *section_name)
{
    Section *s;
    addr_t end_offset;
    বর্ণ buf[1024];
    s = have_section(s1, section_name);
    যদি (!s || !(s->sh_flags & SHF_ALLOC)) {
        end_offset = 0;
        s = text_section;
    } অন্যথা {
        end_offset = s->data_offset;
    }
    snprintf(buf, পরিমাণ(buf), "__%s_start", section_name + 1);
    set_global_sym(s1, buf, s, 0);
    snprintf(buf, পরিমাণ(buf), "__%s_end", section_name + 1);
    set_global_sym(s1, buf, s, end_offset);
}

ST_FUNC শূন্য add_array (TCCState *s1, ধ্রুব বর্ণ *sec, পূর্ণাঙ্ক c)
{
    Section *s;
    s = find_section(s1, sec);
    s->sh_flags = shf_RELRO;
    s->sh_type = sec[1] == 'i' ? SHT_INIT_ARRAY : SHT_FINI_ARRAY;
    put_elf_reloc (s1->symtab, s, s->data_offset, R_DATA_PTR, c);
    section_ptr_add(s, PTR_SIZE);
}

#ifdef CONFIG_TCC_BCHECK
ST_FUNC শূন্য tcc_add_bcheck(TCCState *s1)
{
    যদি (0 == s1->do_bounds_check)
        প্রত্যাগম;
    section_ptr_add(bounds_section, পরিমাণ(addr_t));
}
#endif

/* set symbol to STB_LOCAL and resolve. The point is to not export it as
   a dynamic symbol to allow so's to have one each with a different value. */
স্থির শূন্য set_local_sym(TCCState *s1, ধ্রুব বর্ণ *name, Section *s, পূর্ণাঙ্ক offset)
{
    পূর্ণাঙ্ক c = find_elf_sym(s1->symtab, name);
    যদি (c) {
        ElfW(Sym) *esym = (ElfW(Sym)*)s1->symtab->data + c;
        esym->st_info = ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE);
        esym->st_মান = offset;
        esym->st_shndx = s->sh_অঙ্ক;
    }
}

/* avoid generating debug/test_coverage code for stub functions */
স্থির শূন্য tcc_compile_string_no_debug(TCCState *s, ধ্রুব বর্ণ *str)
{
    পূর্ণাঙ্ক save_do_debug = s->do_debug;
    পূর্ণাঙ্ক save_test_coverage = s->test_coverage;

    s->do_debug = 0;
    s->test_coverage = 0;
    tcc_compile_string(s, str);
    s->do_debug = save_do_debug;
    s->test_coverage = save_test_coverage;
}

#ifdef CONFIG_TCC_BACKTRACE
স্থির শূন্য put_ptr(TCCState *s1, Section *s, পূর্ণাঙ্ক offs)
{
    পূর্ণাঙ্ক c;
    c = set_global_sym(s1, রিক্ত, s, offs);
    s = data_section;
    put_elf_reloc (s1->symtab, s, s->data_offset, R_DATA_PTR, c);
    section_ptr_add(s, PTR_SIZE);
}

ST_FUNC শূন্য tcc_add_btstub(TCCState *s1)
{
    Section *s;
    পূর্ণাঙ্ক n, o, *p;
    CString cstr;
    ধ্রুব বর্ণ *__rt_info = &"___rt_info"[!s1->leading_underscore];

    s = data_section;
    /* Align to PTR_SIZE */
    section_add(s, 0, PTR_SIZE);
    o = s->data_offset;
    /* create a struct rt_context (see tccrun.c) */
    যদি (s1->dwarf) {
        put_ptr(s1, dwarf_সারি_section, 0);
        put_ptr(s1, dwarf_সারি_section, -1);
	যদি (s1->dwarf >= 5)
            put_ptr(s1, dwarf_সারি_str_section, 0);
	অন্যথা
            put_ptr(s1, dwarf_str_section, 0);
    }
    অন্যথা
    {
        put_ptr(s1, stab_section, 0);
        put_ptr(s1, stab_section, -1);
        put_ptr(s1, stab_section->link, 0);
    }

    /* skip esym_start/esym_end/elf_str (not loaded) */
    section_ptr_add(s, 3 * PTR_SIZE);

    যদি (s1->output_type == TCC_OUTPUT_MEMORY && 0 == s1->dwarf) {
        put_ptr(s1, text_section, 0);
    } অন্যথা {
        /* prog_base : local nameless symbol with offset 0 at SHN_ABS */
        put_ptr(s1, রিক্ত, 0);
#যদি defined TCC_TARGET_MACHO
        /* adjust for __PAGEZERO */
        যদি (s1->dwarf == 0 && s1->output_type == TCC_OUTPUT_EXE)
            write64le(data_section->data + data_section->data_offset - PTR_SIZE,
	              (uint64_t)1 << 32);
#endif
    }
    n = 3 * PTR_SIZE;
#ifdef CONFIG_TCC_BCHECK
    যদি (s1->do_bounds_check) {
        put_ptr(s1, bounds_section, 0);
        n -= PTR_SIZE;
    }
#endif
    section_ptr_add(s, n);
    p = section_ptr_add(s, 2 * পরিমাণ (পূর্ণাঙ্ক));
    p[0] = s1->rt_অঙ্ক_callers;
    p[1] = s1->dwarf;
    // if (s->data_offset - o != 10*PTR_SIZE + 2*sizeof (int)) exit(99);

    যদি (s1->output_type == TCC_OUTPUT_MEMORY) {
        set_global_sym(s1, __rt_info, s, o);
        প্রত্যাগম;
    }

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern void __bt_init(),__bt_exit(),__bt_init_dll();"
        "static void *__rt_info[];"
        "__attribute__((constructor)) static void __bt_init_rt(){");
#ifdef TCC_TARGET_PE
    যদি (s1->output_type == TCC_OUTPUT_DLL)
#ifdef CONFIG_TCC_BCHECK
        cstr_printf(&cstr, "__bt_init_dll(%d);", s1->do_bounds_check);
#অন্যথা
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

স্থির শূন্য tcc_tcov_add_file(TCCState *s1, ধ্রুব বর্ণ *filename)
{
    CString cstr;
    শূন্য *ptr;
    বর্ণ wd[1024];

    যদি (tcov_section == রিক্ত)
        প্রত্যাগম;
    section_ptr_add(tcov_section, 1);
    write32le (tcov_section->data, tcov_section->data_offset);

    cstr_new (&cstr);
    যদি (filename[0] == '/')
        cstr_printf (&cstr, "%s.tcov", filename);
    অন্যথা {
        getcwd (wd, পরিমাণ(wd));
        cstr_printf (&cstr, "%s/%s.tcov", wd, filename);
    }
    ptr = section_ptr_add(tcov_section, cstr.size + 1);
    strcpy((বর্ণ *)ptr, cstr.data);
    unlink((বর্ণ *)ptr);
#ifdef _WIN32
    normalize_slashes((বর্ণ *)ptr);
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
ST_FUNC শূন্য tccelf_add_crtbegin(TCCState *s1)
{
#যদি TARGETOS_OpenBSD
    যদি (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crt0.o");
    যদি (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbeginS.o");
    অন্যথা
        tcc_add_crt(s1, "crtbegin.o");
#নোচেদ্যদি TARGETOS_FreeBSD || TARGETOS_NetBSD
    যদি (s1->output_type != TCC_OUTPUT_DLL)
#যদি TARGETOS_FreeBSD
        tcc_add_crt(s1, "crt1.o");
#অন্যথা
        tcc_add_crt(s1, "crt0.o");
#endif
    tcc_add_crt(s1, "crti.o");
    যদি (s1->static_link)
        tcc_add_crt(s1, "crtbeginT.o");
    অন্যথা যদি (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbeginS.o");
    অন্যথা
        tcc_add_crt(s1, "crtbegin.o");
#নোচেদ্যদি TARGETOS_ANDROID
    যদি (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbegin_so.o");
    অন্যথা
        tcc_add_crt(s1, "crtbegin_dynamic.o");
#অন্যথা
    যদি (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crt1.o");
    tcc_add_crt(s1, "crti.o");
#endif
}

ST_FUNC শূন্য tccelf_add_crtend(TCCState *s1)
{
#যদি TARGETOS_OpenBSD
    যদি (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtendS.o");
    অন্যথা
        tcc_add_crt(s1, "crtend.o");
#নোচেদ্যদি TARGETOS_FreeBSD || TARGETOS_NetBSD
    যদি (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtendS.o");
    অন্যথা
        tcc_add_crt(s1, "crtend.o");
    tcc_add_crt(s1, "crtn.o");
#নোচেদ্যদি TARGETOS_ANDROID
    যদি (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtend_so.o");
    অন্যথা
        tcc_add_crt(s1, "crtend_android.o");
#অন্যথা
    tcc_add_crt(s1, "crtn.o");
#endif
}
#endif /* TCC_TARGET_UNIX */

#ifndef TCC_TARGET_PE
/* add tcc runtime libraries */
ST_FUNC শূন্য tcc_add_runtime(TCCState *s1)
{
    s1->filetype = 0;

#ifdef CONFIG_TCC_BCHECK
    tcc_add_bcheck(s1);
#endif
    tcc_add_pragma_libs(s1);

    /* add libc */
    যদি (!s1->nostdlib) {
        পূর্ণাঙ্ক lpthread = s1->option_pthread;

#ifdef CONFIG_TCC_BCHECK
        যদি (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    যদি (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    অন্যথা
                tcc_add_support(s1, "bcheck.o");
# যদি !(TARGETOS_OpenBSD || TARGETOS_NetBSD)
            tcc_add_library(s1, "dl");
# endif
            lpthread = 1;
        }
#endif
#ifdef CONFIG_TCC_BACKTRACE
        যদি (s1->do_backtrace) {
            যদি (s1->output_type & TCC_OUTPUT_EXE)
                tcc_add_support(s1, "bt-exe.o");
            যদি (s1->output_type != TCC_OUTPUT_DLL)
                tcc_add_support(s1, "bt-log.o");
            tcc_add_btstub(s1);
            lpthread = 1;
        }
#endif
        যদি (lpthread)
            tcc_add_library(s1, "pthread");
        tcc_add_library(s1, "c");
#ifdef TCC_LIBGCC
        যদি (!s1->static_link) {
            যদি (TCC_LIBGCC[0] == '/')
                tcc_add_file(s1, TCC_LIBGCC);
            অন্যথা
                tcc_add_dll(s1, TCC_LIBGCC, AFF_PRINT_ERROR);
        }
#endif
#যদি defined TCC_TARGET_ARM && TARGETOS_FreeBSD
        tcc_add_library(s1, "gcc_s"); // unwind code
#endif
        যদি (TCC_LIBTCC1[0]) {
            tcc_add_support(s1, TCC_LIBTCC1);
            tcc_add_library(s1, "c");
        }
#ifndef TCC_TARGET_MACHO
        যদি (s1->output_type != TCC_OUTPUT_MEMORY)
            tccelf_add_crtend(s1);
#endif
    }
}
#endif /* ndef TCC_TARGET_PE */

/* set _etext/_edata/_end  f=0:set  f=1:when_needed  f=2,3:just_update */
স্থির শূন্য set_linker_sym(TCCState *s1, ধ্রুব বর্ণ *name, Section *sec, পূর্ণাঙ্ক f)
{
    পূর্ণাঙ্ক sym_index, esym_index, defined;
    ElfW(Sym) *sym, *esym;
    sym_index = find_elf_sym(symtab_section, name);
    sym = (ElfW(Sym) *)symtab_section->data + sym_index;
    esym_index = find_elf_sym(s1->dynsymtab_section, name);
    esym = (ElfW(Sym) *)s1->dynsymtab_section->data + esym_index;
    defined = sym->st_shndx != SHN_UNDEF
        || (esym->st_shndx != SHN_UNDEF && esym->st_size);
    বিকল্প (f) {
    পক্ষ 1: /* old symbols w/o '_' */
        যদি (!(sym_index || esym_index) || defined)
            ভঙ্গ;
    পক্ষ 0:
        যদি (defined) {
            tcc_warning("linker symbol '%s' already defined", name);
            ভঙ্গ;
        }
        sym_index = set_global_sym(s1, name, sec, -1);
        get_sym_attr(s1, sym_index, 1)->linker_sym = 1;
        ভঙ্গ;
    স্বভাব: /* update (bss only) */
        যদি (get_sym_attr(s1, sym_index, 0)->linker_sym)
            sym->st_মান = sec->data_offset;
    }
#ifndef ELF_OBJ_ONLY
    যদি (name[0] == '_')
        set_linker_sym(s1, name + 1, sec, f + 1);
#endif
}

/* add various standard linker symbols (must be done after the
   sections are filled (for example after allocating common
   symbols)) */
স্থির শূন্য tcc_add_linker_symbols(TCCState *s1)
{
    বর্ণ buf[1024];
    পূর্ণাঙ্ক i;
    Section *s;

    set_linker_sym(s1, "_etext", text_section, 0);
    set_linker_sym(s1, "_edata", data_section, 0);
    set_linker_sym(s1, "_end", bss_section, 0);
#যদি TARGETOS_OpenBSD
    set_global_sym(s1, "__executable_start", রিক্ত, ELF_START_ADDR);
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
    প্রতি(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        যদি ((s->sh_flags & SHF_ALLOC)
            && (s->sh_type == SHT_PROGBITS || s->sh_type == SHT_NOBITS
                || s->sh_type == SHT_STRTAB)) {
            /* check if section name can be expressed in C */
            ধ্রুব বর্ণ *p0, *p;
            p0 = s->name;
            যদি (*p0 == '.')
                ++p0;
            p = p0;
            প্রতি(;;) {
                পূর্ণাঙ্ক c = *p;
                যদি (!c)
                    ভঙ্গ;
                যদি (!isid(c) && !isnum(c))
                    গচ্ছ next_sec;
                p++;
            }
            snprintf(buf, পরিমাণ(buf), "__start_%s", p0);
            set_global_sym(s1, buf, s, 0);
            snprintf(buf, পরিমাণ(buf), "__stop_%s", p0);
            set_global_sym(s1, buf, s, -1);
        }
    next_sec: ;
    }
}

ST_FUNC শূন্য resolve_common_syms(TCCState *s1)
{
    ElfW(Sym) *sym;

    /* Allocate common symbols in BSS.  */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        যদি (sym->st_shndx == SHN_COMMON && sym->st_size) {
            /* symbol alignment is in st_value for SHN_COMMONs */
	    sym->st_মান = section_add(bss_section, sym->st_size,
					sym->st_মান);
            sym->st_shndx = bss_section->sh_অঙ্ক;
        }
    }

    /* Now assign linker provided symbols their value.  */
    যদি (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_linker_symbols(s1);
}

#ifndef ELF_OBJ_ONLY
ST_FUNC শূন্য fill_got_entry(TCCState *s1, ElfW_Rel *rel)
{
    পূর্ণাঙ্ক sym_index = ELFW(R_SYM) (rel->r_info);
    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->data)[sym_index];
    সংরচনা sym_attr *attr = get_sym_attr(s1, sym_index, 0);
    unsigned offset = attr->got_offset;

    যদি (0 == offset)
        প্রত্যাগম;
    section_reserve(s1->got, offset + PTR_SIZE);
#যদি PTR_SIZE == 8
    write64le(s1->got->data + offset, sym->st_মান);
#অন্যথা
    write32le(s1->got->data + offset, sym->st_মান);
#endif
}

/* Perform relocation to GOT or PLT entries */
ST_FUNC শূন্য fill_got(TCCState *s1)
{
    Section *s;
    ElfW_Rel *rel;
    পূর্ণাঙ্ক i;

    প্রতি(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        যদি (s->sh_type != SHT_RELX)
            অনুবর্ত;
        /* no need to handle got relocations */
        যদি (s->link != symtab_section)
            অনুবর্ত;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            বিকল্প (ELFW(R_TYPE) (rel->r_info)) {
                পক্ষ R_X86_64_GOT32:
                পক্ষ R_X86_64_GOTPCREL:
		পক্ষ R_X86_64_GOTPCRELX:
		পক্ষ R_X86_64_REX_GOTPCRELX:
                পক্ষ R_X86_64_PLT32:
                    fill_got_entry(s1, rel);
                    ভঙ্গ;
            }
        }
    }
}

/* See put_got_entry for a description.  This is the second stage
   where GOT references to local defined symbols are rewritten.  */
স্থির শূন্য fill_local_got_entries(TCCState *s1)
{
    ElfW_Rel *rel;
    যদি (!s1->got->reloc)
        প্রত্যাগম;
    for_each_elem(s1->got->reloc, 0, rel, ElfW_Rel) {
	যদি (ELFW(R_TYPE)(rel->r_info) == R_RELATIVE) {
	    পূর্ণাঙ্ক sym_index = ELFW(R_SYM) (rel->r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->data)[sym_index];
	    সংরচনা sym_attr *attr = get_sym_attr(s1, sym_index, 0);
	    unsigned offset = attr->got_offset;
	    যদি (offset != rel->r_offset - s1->got->sh_addr)
	        tcc_error_noabort("fill_local_got_entries: huh?");
	    rel->r_info = ELFW(R_INFO)(0, R_RELATIVE);
#যদি SHT_RELX == SHT_RELA
	    rel->r_addend = sym->st_মান;
#অন্যথা
	    /* All our REL architectures also happen to be 32bit LE.  */
	    write32le(s1->got->data + offset, sym->st_মান);
#endif
	}
    }
}

/* Bind symbols of executable: resolve undefined symbols from exported symbols
   in shared libraries */
স্থির শূন্য bind_exe_dynsyms(TCCState *s1, পূর্ণাঙ্ক is_PIE)
{
    ধ্রুব বর্ণ *name;
    পূর্ণাঙ্ক sym_index, index;
    ElfW(Sym) *sym, *esym;
    পূর্ণাঙ্ক type;

    /* Resolve undefined symbols from dynamic symbols. When there is a match:
       - if STT_FUNC or STT_GNU_IFUNC symbol -> add it in PLT
       - if STT_OBJECT symbol -> add it in .bss section with suitable reloc */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        যদি (sym->st_shndx == SHN_UNDEF
            /* bss symbols may be initialized in the shared library */
            || sym->st_shndx == SHN_COMMON
            || sym->st_shndx == bss_section->sh_অঙ্ক) {
            name = (বর্ণ *) symtab_section->link->data + sym->st_name;
            sym_index = find_elf_sym(s1->dynsymtab_section, name);
            esym = &((ElfW(Sym) *)s1->dynsymtab_section->data)[sym_index];
            যদি (sym_index && esym->st_shndx != SHN_UNDEF) {
                যদি (is_PIE)
                    অনুবর্ত;
                type = ELFW(ST_TYPE)(esym->st_info);
                যদি ((type == STT_FUNC) || (type == STT_GNU_IFUNC)) {
                    /* Indirect functions shall have STT_FUNC type in executable
                     * dynsym section. Indeed, a dlsym call following a lazy
                     * resolution would pick the symbol value from the
                     * executable dynsym entry which would contain the address
                     * of the function wanted by the caller of dlsym instead of
                     * the address of the function that would return that
                     * address */
                    পূর্ণাঙ্ক dynindex
		      = put_elf_sym(s1->dynsym, 0, esym->st_size,
				    ELFW(ST_INFO)(STB_GLOBAL,STT_FUNC), 0, 0,
				    name);
		    পূর্ণাঙ্ক index = sym - (ElfW(Sym) *) symtab_section->data;
		    get_sym_attr(s1, index, 1)->dyn_index = dynindex;
                } অন্যথা যদি (type == STT_OBJECT) {
                    unsigned long offset;
                    ElfW(Sym) *dynsym;
                    যদি (sym->st_shndx == bss_section->sh_অঙ্ক) {
                        offset = sym->st_মান;
                    } অন্যথা {
                        offset = bss_section->data_offset;
                        /* XXX: which alignment ? */
                        offset = (offset + 16 - 1) & -16;
                        bss_section->data_offset = offset + esym->st_size;
                    }
                    set_elf_sym (s1->symtab, offset, esym->st_size,
                                 esym->st_info, 0, bss_section->sh_অঙ্ক, name);
                    index = put_elf_sym(s1->dynsym, offset, esym->st_size,
                                        esym->st_info, 0, bss_section->sh_অঙ্ক,
                                        name);
                    /* Ensure R_COPY works for weak symbol aliases */
                    যদি (ELFW(ST_BIND)(esym->st_info) == STB_WEAK) {
                        for_each_elem(s1->dynsymtab_section, 1, dynsym, ElfW(Sym)) {
                            যদি ((dynsym->st_মান == esym->st_মান)
                                && (ELFW(ST_BIND)(dynsym->st_info) == STB_GLOBAL)) {
                                বর্ণ *dynname = (বর্ণ *) s1->dynsymtab_section->link->data
                                                + dynsym->st_name;
                                put_elf_sym(s1->dynsym, offset, dynsym->st_size,
                                            dynsym->st_info, 0,
                                            bss_section->sh_অঙ্ক, dynname);
                                ভঙ্গ;
                            }
                        }
                    }
                    put_elf_reloc(s1->dynsym, bss_section,
                                  offset, R_COPY, index);
                }
            } অন্যথা যদি (sym->st_shndx == SHN_UNDEF) {
                /* STB_WEAK undefined symbols are accepted */
                /* XXX: _fp_hw seems to be part of the ABI, so we ignore it */
                যদি (ELFW(ST_BIND)(sym->st_info) == STB_WEAK ||
                    !strcmp(name, "_fp_hw")) {
                } অন্যথা {
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
স্থির শূন্য bind_libs_dynsyms(TCCState *s1)
{
    ধ্রুব বর্ণ *name;
    পূর্ণাঙ্ক dynsym_index;
    ElfW(Sym) *sym, *esym;

    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        name = (বর্ণ *)symtab_section->link->data + sym->st_name;
        dynsym_index = find_elf_sym(s1->dynsymtab_section, name);
        যদি (sym->st_shndx != SHN_UNDEF) {
            যদি (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL
                && (dynsym_index || s1->rdynamic))
                set_elf_sym(s1->dynsym, sym->st_মান, sym->st_size,
                            sym->st_info, 0, sym->st_shndx, name);
        } অন্যথা যদি (dynsym_index) {
            esym = (ElfW(Sym) *)s1->dynsymtab_section->data + dynsym_index;
            যদি (esym->st_shndx == SHN_UNDEF) {
                /* weak symbols can stay undefined */
                যদি (ELFW(ST_BIND)(esym->st_info) != STB_WEAK)
                    tcc_warning("unresolved dynamic reference to '%s'", name);
            }
        }
    }
}

/* Export all non local symbols. This is used by shared libraries so that the
   non local symbols they define can resolve a reference in another shared
   library or in the executable. Correspondingly, it allows undefined local
   symbols to be resolved by other shared libraries or by the executable. */
স্থির শূন্য export_global_syms(TCCState *s1)
{
    পূর্ণাঙ্ক dynindex, index;
    ধ্রুব বর্ণ *name;
    ElfW(Sym) *sym;
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        যদি (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
	    name = (বর্ণ *) symtab_section->link->data + sym->st_name;
	    dynindex = set_elf_sym(s1->dynsym, sym->st_মান, sym->st_size,
				   sym->st_info, 0, sym->st_shndx, name);
	    index = sym - (ElfW(Sym) *) symtab_section->data;
            get_sym_attr(s1, index, 1)->dyn_index = dynindex;
        }
    }
}

/* decide if an unallocated section should be output. */
স্থির পূর্ণাঙ্ক set_sec_sizes(TCCState *s1)
{
    পূর্ণাঙ্ক i;
    Section *s;
    পূর্ণাঙ্ক textrel = 0;
    পূর্ণাঙ্ক file_type = s1->output_type;

    /* Allocate strings for section names */
    প্রতি(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        যদি (s->sh_type == SHT_RELX && !(s->sh_flags & SHF_ALLOC)) {
            /* when generating a DLL, we include relocations but
               we may patch them */
            যদি ((file_type & TCC_OUTPUT_DYN)
                && (s1->sections[s->sh_info]->sh_flags & SHF_ALLOC)) {
                পূর্ণাঙ্ক গুনতি_2 = prepare_dynamic_rel(s1, s);
                যদি (গুনতি_2) {
                    /* allocate the section */
                    s->sh_flags |= SHF_ALLOC;
                    s->sh_size = গুনতি_2 * পরিমাণ(ElfW_Rel);
                    যদি (s1->sections[s->sh_info]->sh_flags & SHF_EXECINSTR)
                        textrel += গুনতি_2;
                }
            }
        } অন্যথা যদি ((s->sh_flags & SHF_ALLOC)
#ifdef TCC_TARGET_ARM
                   || s->sh_type == SHT_ARM_ATTRIBUTES
#endif
                   || s1->do_debug) {
            s->sh_size = s->data_offset;
        }
    }
    প্রত্যাগম textrel;
}

/* various data used under elf_output_file() */
সংরচনা dyn_inf {
    Section *dynamic;
    Section *dynstr;
    Section *interp;
    Section *note;
    Section *gnu_hash;
    সংরচনা {
        /* Info to be copied in dynamic section */
        unsigned long data_offset;
        addr_t rel_addr;
        addr_t rel_size;
    };

    ElfW(Phdr) *phdr;
    পূর্ণাঙ্ক phnum;
    পূর্ণাঙ্ক shnum;
    পূর্ণাঙ্ক tls;
    পূর্ণাঙ্ক relro;
    পূর্ণাঙ্ক notes;
    পূর্ণাঙ্ক ehfr;
    পূর্ণাঙ্ক dyna;
};

/* Decide the layout of sections loaded in memory. This must be done before
   program headers are filled since they contain info about the layout.
   We do the following ordering: interp, symbol tables, relocations, progbits,
   nobits */
স্থির পূর্ণাঙ্ক sort_sections(TCCState *s1, পূর্ণাঙ্ক *sec_order, সংরচনা dyn_inf *d)
{
    Section *s;
    পূর্ণাঙ্ক i, j, k, f, f0, n;
    পূর্ণাঙ্ক nb_sections = s1->nb_sections;
    পূর্ণাঙ্ক *sec_cls = sec_order + nb_sections;
    পূর্ণাঙ্ক tls_align = 0; /* need common alignment for all tls sections */

    প্রতি (i = 1; i < nb_sections; i++) {
        s = s1->sections[i];
        যদি (0 == s->sh_name) {
            j = 0x900; /* no sh_name: won't go to file */
        } অন্যথা যদি (s->sh_flags & SHF_ALLOC) {
            j = 0x100;
            যদি ((s->sh_flags & (SHF_WRITE|SHF_TLS)) == SHF_WRITE)
                j = 0x200;
        } অন্যথা {
            j = 0x700;
        }
        যদি (j >= 0x700 && s1->output_format != TCC_OUTPUT_FORMAT_ELF)
            s->sh_size = 0, j = 0x900;

        যদি (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM) {
            k = 0x10;
        } অন্যথা যদি (s->sh_type == SHT_STRTAB && strcmp(s->name, ".stabstr")) {
            k = 0x11;
            যদি (i == nb_sections - 1) /* ".shstrtab" assumed to stay last */
                k = 0xff;
        } অন্যথা যদি (s->sh_type == SHT_HASH || s->sh_type == SHT_GNU_HASH) {
            k = 0x12;
        } অন্যথা যদি (s->sh_type == SHT_GNU_verdef
                  || s->sh_type == SHT_GNU_verneed
                  || s->sh_type == SHT_GNU_versym) {
            k = 0x13;
        } অন্যথা যদি (s->sh_type == SHT_RELX) {
            k = 0x20;
            যদি (s1->plt && s == s1->plt->reloc)
                k = 0x21;
        } অন্যথা যদি (s->sh_flags & SHF_EXECINSTR) {
            k = 0x60;
        /* RELRO sections --> */
        } অন্যথা যদি (s->sh_flags & SHF_TLS) {
            যদি (s->sh_addralign > tls_align)
                tls_align = s->sh_addralign;
            k = 0x40 + (s->sh_type == SHT_NOBITS);
        } অন্যথা যদি (s->sh_type == SHT_PREINIT_ARRAY) {
            k = 0x42;
        } অন্যথা যদি (s->sh_type == SHT_INIT_ARRAY) {
            k = 0x43;
        } অন্যথা যদি (s->sh_type == SHT_FINI_ARRAY) {
            k = 0x44;
        } অন্যথা যদি (s->sh_type == SHT_DYNAMIC) {
            k = 0x48;
        } অন্যথা যদি (s == s1->got) {
            k = 0x49; /* .got as RELRO needs BIND_NOW in DT_FLAGS */
        } অন্যথা যদি (s->reloc && (s->reloc->sh_flags & SHF_ALLOC) && j == 0x100) {
            k = 0x45; /* +1 for data.ro */
        /* <-- */
        } অন্যথা যদি (s->sh_type == SHT_NOTE) {
            k = 0x08, d->notes = 1;
        } অন্যথা যদি (s->sh_type == SHT_NOBITS) {
            k = 0x70; /* bss */
        } অন্যথা যদি (s == d->interp) {
            k = 0x00;
        } অন্যথা {
            k = 0x50; /* data */
        }
        k += j;
        /* make our standard sections come last to have _etext/_edata correct values */
        যদি (s->sh_অঙ্ক <= bss_section->sh_অঙ্ক)
            ++k;
        /* make RELRO section writable */
        যদি ((k & 0xfff0) == 0x140)
            k += 0x100, s->sh_flags |= SHF_WRITE;
        /* sort by insert */
        প্রতি (n = i; n > 1 && k < (f = sec_cls[n - 1]); --n)
            sec_cls[n] = f, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
    }
    sec_order[0] = 0;
    d->shnum = 1;

#define SHFX_NEWPH (1 << 4)
#define SHFX_RELRO (1 << 5)

    /* count PT_LOAD headers needed */
    n = f0 = 0;
    প্রতি (i = 1; i < nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        k = sec_cls[i];
        f = 0;
        যদি (k < 0x900)
            ++d->shnum;
        যদি (k < 0x700) {
            f = s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR);
#যদি TARGETOS_NetBSD || TARGETOS_FreeBSD
	    /* NetBSD only supports 2 PT_LOAD sections.
	       See: https://blog.netbsd.org/tnf/entry/the_first_report_on_lld */
	    যদি ((f & SHF_WRITE) == 0)
                f |= SHF_EXECINSTR;
            k = 0; /* no relro */
#endif
            যদি ((k & 0xfff0) == 0x240) /* RELRO sections */
                d->relro = 1, f |= SHFX_RELRO;
            /* start new header when flags changed, but avoid zero memsz */
            যদি (f != f0 && s->sh_size)
                f0 = f, ++n, f |= SHFX_NEWPH;
            যদি ((s->sh_flags & SHF_TLS) && s->sh_size) {
                s->sh_addralign = tls_align;
                d->tls = 1, f |= SHF_TLS;
            }
        }
        sec_cls[i] = f;
        //printf("ph %d sec %02d : %3X %3X  %8.2X  %04X  %s\n", (f>0) * n, i, f, k, s->sh_type, (int)s->sh_size, s->name);
    }
    প্রত্যাগম n;
}

স্থির ElfW(Phdr) *fill_phdr(ElfW(Phdr) *ph, পূর্ণাঙ্ক type, Section *s)
{
    ph->p_type = type;
    ph->p_flags = PF_R;
    যদি (s) {
        যদি (s->sh_flags & SHF_WRITE)
            ph->p_flags |= PF_W;
        ph->p_offset = s->sh_offset;
        ph->p_vaddr = s->sh_addr;
        ph->p_filesz = s->sh_size;
        ph->p_align = s->sh_addralign;
    }
    ph->p_paddr = ph->p_vaddr;
    ph->p_memsz = ph->p_filesz;
    প্রত্যাগম ph;
}

স্থির ElfW(Phdr) *update_phdr(ElfW(Phdr) *ph, পূর্ণাঙ্ক type, Section *s, addr_t addr, পূর্ণাঙ্ক file_offset)
{
    যদি (ph->p_type == 0) {
        fill_phdr(ph, type, s);
    }
    ph->p_filesz = file_offset - ph->p_offset;
    ph->p_memsz = addr - ph->p_vaddr;
    প্রত্যাগম ph;
}

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
স্থির পূর্ণাঙ্ক layout_sections(TCCState *s1, পূর্ণাঙ্ক *sec_order, সংরচনা dyn_inf *d)
{
    Section *s;
    addr_t addr, tmp, align, s_align, base;
    ElfW(Phdr) *ph = রিক্ত, *ph2;
    পূর্ণাঙ্ক i, f, n, phnum, phfill;
    পূর্ণাঙ্ক file_offset;

    /* compute number of program headers */
    phnum = sort_sections(s1, sec_order, d);
    phfill = 0; /* set to 1 to have dll's with a PT_PHDR */
    যদি (d->interp)
        phfill = 2;
    phnum += phfill;
    যদি (d->dynamic)
        d->dyna = phnum++;
    যদি (d->notes)
        d->notes = phnum++;
    যদি (d->tls)
        d->tls = phnum++;
    যদি (eh_frame_hdr_section)
        d->ehfr = phnum++;
    যদি (d->relro)
        d->relro = phnum++;
    d->phnum = phnum;
    d->phdr = tcc_mallocz(phnum * পরিমাণ(ElfW(Phdr)));

    file_offset = 0;
    যদি (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
        file_offset = (পরিমাণ(ElfW(Ehdr)) + phnum * পরিমাণ(ElfW(Phdr)) + 3) & -4;
        file_offset += d->shnum * পরিমাণ (ElfW(Shdr));
    }

    s_align = ELF_PAGE_SIZE;
    যদি (s1->section_align)
        s_align = s1->section_align;

    addr = ELF_START_ADDR;
    যদি (s1->output_type & TCC_OUTPUT_DYN)
        addr = 0;

    যদি (s1->has_text_addr) {
        addr = s1->text_addr;
        যদি (0) {
            পূর্ণাঙ্ক a_offset, p_offset;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_offset = (পূর্ণাঙ্ক) (addr & (s_align - 1));
            p_offset = file_offset & (s_align - 1);
            যদি (a_offset < p_offset)
                a_offset += s_align;
            file_offset += (a_offset - p_offset);
        }
    }
    base = addr;
    /* compute address after headers */
    addr += file_offset;

    n = 0;
    প্রতি(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        f = sec_order[i + s1->nb_sections];
        align = s->sh_addralign - 1;

        যদি (f == 0) { /* no alloc */
            file_offset = (file_offset + align) & ~align;
            s->sh_offset = file_offset;
            যদি (s->sh_type != SHT_NOBITS)
                file_offset += s->sh_size;
            অনুবর্ত;
        }

        যদি ((f & SHFX_NEWPH) && n) {
            /* different rwx section flags */
            যদি (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
                /* if in the middle of a page, w e duplicate the page in
                   memory so that one copy is RX and the other is RW */
                যদি ((addr & (s_align - 1)) != 0)
                    addr += s_align;
            } অন্যথা {
                align = s_align - 1;
            }
        }

        tmp = addr;
        addr = (addr + align) & ~align;
        file_offset += (পূর্ণাঙ্ক)(addr - tmp);
        s->sh_offset = file_offset;
        s->sh_addr = addr;

        //printf("%d : %08x %08x %04x %03x %s %d\n", n, (int)file_offset, (int)addr, (int)s->sh_size, s->sh_type, s->name, align + 1);
        addr += s->sh_size;
        যদি (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_size;

        যদি (f & SHFX_NEWPH) {
            /* set new program header */
            ph = &d->phdr[phfill + n];
            fill_phdr(ph, PT_LOAD, s);
            ph->p_align = s_align;
            যদি (f & SHF_EXECINSTR)
                ph->p_flags |= PF_X;
            যদি (n == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_offset = 0;
                ph->p_paddr = ph->p_vaddr = base;
            }
            ++n;
        }

        যদি (ph)
            update_phdr(ph, 0, 0, addr, file_offset);

        যদি (f & SHFX_RELRO) {
            ph2 = update_phdr(&d->phdr[d->relro], PT_GNU_RELRO, s, addr, file_offset);
            ph2->p_align = 1;
        }
        যদি (f & SHF_TLS) {
            ph2 = update_phdr(&d->phdr[d->tls], PT_TLS, s, addr, file_offset);
            যদি (s->sh_type == SHT_NOBITS)
                addr -= s->sh_size;
            /* for xxx-link.c:relocate() */
            s1->tls_start = ph2->p_vaddr;
            s1->tls_end = s1->tls_start + ph2->p_memsz + (-ph2->p_memsz & (ph2->p_align - 1));
        }
        যদি (s->sh_type == SHT_NOTE) {
            update_phdr(&d->phdr[d->notes], PT_NOTE, s, addr, file_offset);
        }
    }

    /* Fill other headers */
    যদি (d->dyna)
        fill_phdr(&d->phdr[d->dyna], PT_DYNAMIC, d->dynamic);
    যদি (d->ehfr)
        fill_phdr(&d->phdr[d->ehfr], PT_GNU_EH_FRAME, eh_frame_hdr_section);
    যদি (d->interp)
        fill_phdr(&d->phdr[1], PT_INTERP, d->interp);
    যদি (phfill) {
        ph = &d->phdr[0];
        ph->p_offset = পরিমাণ(ElfW(Ehdr));
        ph->p_vaddr = base + ph->p_offset;
        ph->p_filesz = phnum * পরিমাণ(ElfW(Phdr));
        ph->p_align = 4;
        fill_phdr(ph, PT_PHDR, রিক্ত);
    }
    প্রত্যাগম 0;
}

/* put dynamic tag */
স্থির শূন্য put_dt(Section *dynamic, পূর্ণাঙ্ক dt, addr_t val)
{
    ElfW(Dyn) *dyn;
    dyn = section_ptr_add(dynamic, পরিমাণ(ElfW(Dyn)));
    dyn->d_tag = dt;
    dyn->d_un.d_val = val;
}

/* Fill the dynamic section with tags describing the address and size of
   sections */
স্থির শূন্য fill_dynamic(TCCState *s1, সংরচনা dyn_inf *dyninf)
{
    Section *dynamic = dyninf->dynamic;
    Section *s;

    /* put dynamic section entries */
    put_dt(dynamic, DT_HASH, s1->dynsym->hash->sh_addr);
    put_dt(dynamic, DT_GNU_HASH, dyninf->gnu_hash->sh_addr);
    put_dt(dynamic, DT_STRTAB, dyninf->dynstr->sh_addr);
    put_dt(dynamic, DT_SYMTAB, s1->dynsym->sh_addr);
    put_dt(dynamic, DT_STRSZ, dyninf->dynstr->data_offset);
    put_dt(dynamic, DT_SYMENT, পরিমাণ(ElfW(Sym)));
#যদি PTR_SIZE == 8
    put_dt(dynamic, DT_RELA, dyninf->rel_addr);
    put_dt(dynamic, DT_RELASZ, dyninf->rel_size);
    put_dt(dynamic, DT_RELAENT, পরিমাণ(ElfW_Rel));
    যদি (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->data_offset);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_RELA);
    }
    put_dt(dynamic, DT_RELACOUNT, 0);
#অন্যথা
    put_dt(dynamic, DT_REL, dyninf->rel_addr);
    put_dt(dynamic, DT_RELSZ, dyninf->rel_size);
    put_dt(dynamic, DT_RELENT, পরিমাণ(ElfW_Rel));
    যদি (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->data_offset);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_REL);
    }
    put_dt(dynamic, DT_RELCOUNT, 0);
#endif
    যদি (versym_section && verneed_section) {
	/* The dynamic linker can not handle VERSYM without VERNEED */
        put_dt(dynamic, DT_VERSYM, versym_section->sh_addr);
        put_dt(dynamic, DT_VERNEED, verneed_section->sh_addr);
        put_dt(dynamic, DT_VERNEEDNUM, dt_verneednum);
    }
    s = have_section(s1, ".preinit_array");
    যদি (s && s->data_offset) {
        put_dt(dynamic, DT_PREINIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_PREINIT_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".init_array");
    যদি (s && s->data_offset) {
        put_dt(dynamic, DT_INIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_INIT_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".fini_array");
    যদি (s && s->data_offset) {
        put_dt(dynamic, DT_FINI_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_FINI_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".init");
    যদি (s && s->data_offset) {
        put_dt(dynamic, DT_INIT, s->sh_addr);
    }
    s = have_section(s1, ".fini");
    যদি (s && s->data_offset) {
        put_dt(dynamic, DT_FINI, s->sh_addr);
    }
    যদি (s1->do_debug)
        put_dt(dynamic, DT_DEBUG, 0);
    put_dt(dynamic, DT_NULL, 0);
}

/* Remove gaps between RELX sections.
   These gaps are a result of final_sections_reloc. Here some relocs are removed.
   The gaps are then filled with 0 in tcc_output_elf. The 0 is intepreted as
   R_...NONE reloc. This does work on most targets but on OpenBSD/arm64 this
   is illegal. OpenBSD/arm64 does not support R_...NONE reloc. */
স্থির শূন্য update_reloc_sections(TCCState *s1, সংরচনা dyn_inf *dyninf)
{
    পূর্ণাঙ্ক i;
    unsigned long file_offset = 0;
    Section *s;
    Section *relocplt = s1->plt ? s1->plt->reloc : রিক্ত;

    /* dynamic relocation table information, for .dynamic section */
    dyninf->rel_addr = dyninf->rel_size = 0;

    প্রতি(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
	যদি (s->sh_type == SHT_RELX && s != relocplt) {
	    যদি (dyninf->rel_size == 0) {
		dyninf->rel_addr = s->sh_addr;
		file_offset = s->sh_offset;
	    }
	    অন্যথা {
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
স্থির পূর্ণাঙ্ক tcc_output_elf(TCCState *s1, FILE *f, পূর্ণাঙ্ক phnum, ElfW(Phdr) *phdr)
{
    পূর্ণাঙ্ক i, shnum, offset, size, file_type;
    Section *s;
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) shdr, *sh;

    file_type = s1->output_type;
    shnum = s1->nb_sections;

    memset(&ehdr, 0, পরিমাণ(ehdr));
    যদি (phnum > 0) {
        ehdr.e_phentsize = পরিমাণ(ElfW(Phdr));
        ehdr.e_phnum = phnum;
        ehdr.e_phoff = পরিমাণ(ElfW(Ehdr));
    }

    /* fill header */
    ehdr.e_ident[0] = ELFMAG0;
    ehdr.e_ident[1] = ELFMAG1;
    ehdr.e_ident[2] = ELFMAG2;
    ehdr.e_ident[3] = ELFMAG3;
    ehdr.e_ident[4] = ELFCLASSW;
    ehdr.e_ident[5] = ELFDATA2LSB;
    ehdr.e_ident[6] = EV_CURRENT;

#যদি TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    ehdr.e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
#নোচেদ্যদি TARGETOS_OpenBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_OPENBSD;
#নোচেদ্যদি TARGETOS_NetBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_NETBSD;
#নোচেদ্যদি defined TCC_TARGET_ARM && defined TCC_ARM_EABI
    ehdr.e_flags = EF_ARM_EABI_VER5;
    ehdr.e_flags |= s1->float_abi == ARM_HARD_FLOAT
        ? EF_ARM_VFP_FLOAT : EF_ARM_SOFT_FLOAT;
#নোচেদ্যদি defined TCC_TARGET_ARM
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#নোচেদ্যদি defined TCC_TARGET_RISCV64
    /* XXX should be configurable */
    ehdr.e_flags = EF_RISCV_FLOAT_ABI_DOUBLE;
#endif

    যদি (file_type == TCC_OUTPUT_OBJ) {
        ehdr.e_type = ET_REL;
    } অন্যথা {
        যদি (file_type & TCC_OUTPUT_DYN)
            ehdr.e_type = ET_DYN;
        অন্যথা
            ehdr.e_type = ET_EXEC;
        যদি (s1->elf_entryname)
            ehdr.e_entry = get_sym_addr(s1, s1->elf_entryname, 1, 0);
        অন্যথা
            ehdr.e_entry = get_sym_addr(s1, "_start", !!(file_type & TCC_OUTPUT_EXE), 0);
        যদি (ehdr.e_entry == (addr_t)-1)
            ehdr.e_entry = text_section->sh_addr;
        যদি (s1->nb_errors)
            প্রত্যাগম -1;
    }

    sort_syms(s1, s1->symtab);

    ehdr.e_machine = EM_TCC_TARGET;
    ehdr.e_version = EV_CURRENT;
    ehdr.e_shoff = (পরিমাণ(ElfW(Ehdr)) + phnum * পরিমাণ(ElfW(Phdr)) + 3) & -4;
    ehdr.e_ehsize = পরিমাণ(ElfW(Ehdr));
    ehdr.e_shentsize = পরিমাণ(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    offset = fwrite(&ehdr, 1, পরিমাণ(ElfW(Ehdr)), f);
    যদি (phdr)
        offset += fwrite(phdr, 1, phnum * পরিমাণ(ElfW(Phdr)), f);

    /* output section headers */
    যাবত্ (offset < ehdr.e_shoff) {
        fputc(0, f);
        offset++;
    }

    প্রতি(i = 0; i < shnum; i++) {
        sh = &shdr;
        memset(sh, 0, পরিমাণ(ElfW(Shdr)));
        যদি (i) {
            s = s1->sections[i];
            sh->sh_name = s->sh_name;
            sh->sh_type = s->sh_type;
            sh->sh_flags = s->sh_flags;
            sh->sh_entsize = s->sh_entsize;
            sh->sh_info = s->sh_info;
            যদি (s->link)
                sh->sh_link = s->link->sh_অঙ্ক;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_offset = s->sh_offset;
            sh->sh_size = s->sh_size;
        }
        offset += fwrite(sh, 1, পরিমাণ(ElfW(Shdr)), f);
    }

    /* output sections */
    প্রতি(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        যদি (s->sh_type != SHT_NOBITS) {
            যাবত্ (offset < s->sh_offset) {
                fputc(0, f);
                offset++;
            }
            size = s->sh_size;
            যদি (size)
                offset += fwrite(s->data, 1, size, f);
        }
    }
    প্রত্যাগম 0;
}

স্থির পূর্ণাঙ্ক tcc_output_দ্বিমিক(TCCState *s1, FILE *f)
{
    Section *s;
    পূর্ণাঙ্ক i, offset, size;

    offset = 0;
    প্রতি(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[i];
        যদি (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            যাবত্ (offset < s->sh_offset) {
                fputc(0, f);
                offset++;
            }
            size = s->sh_size;
            fwrite(s->data, 1, size, f);
            offset += size;
        }
    }
    প্রত্যাগম 0;
}

/* Write an elf, coff or "binary" file */
স্থির পূর্ণাঙ্ক tcc_write_elf_file(TCCState *s1, ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক phnum,
                              ElfW(Phdr) *phdr)
{
    পূর্ণাঙ্ক fd, mode, file_type, ret;
    FILE *f;

    file_type = s1->output_type;
    যদি (file_type == TCC_OUTPUT_OBJ)
        mode = 0666;
    অন্যথা
        mode = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_দ্বিমিক_2, mode);
    যদি (fd < 0 || (f = fdopen(fd, "wb")) == রিক্ত)
        প্রত্যাগম tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
    যদি (s1->verbose)
        printf("<- %s\n", filename);
#ifdef TCC_TARGET_COFF
    যদি (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    অন্যথা
#endif
    যদি (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        ret = tcc_output_elf(s1, f, phnum, phdr);
    অন্যথা
        ret = tcc_output_দ্বিমিক(s1, f);
    fclose(f);

    প্রত্যাগম ret;
}

#ifndef ELF_OBJ_ONLY
/* order sections according to sec_order, remove sections
   that we aren't going to output.  */
স্থির শূন্য reorder_sections(TCCState *s1, পূর্ণাঙ্ক *sec_order)
{
    পূর্ণাঙ্ক i, nnew, k, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    backmap = tcc_malloc(s1->nb_sections * পরিমাণ(backmap[0]));
    প্রতি (i = 0, nnew = 0, snew = রিক্ত; i < s1->nb_sections; i++) {
	k = sec_order ? sec_order[i] : i;
	s = s1->sections[k];
	যদি (!i || s->sh_name) {
	    backmap[k] = nnew;
            dynarray_add(&snew, &nnew, s);
	} অন্যথা {
	    backmap[k] = 0;
            /* just remember to free them later */
	    dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, s);
	}
    }
    প্রতি (i = 1; i < nnew; i++) {
	s = snew[i];
        s->sh_অঙ্ক = i;
        যদি (s->sh_type == SHT_RELX)
            s->sh_info = backmap[s->sh_info];
        অন্যথা যদি (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM)
            for_each_elem(s, 1, sym, ElfW(Sym))
                যদি (sym->st_shndx < s1->nb_sections)
                    sym->st_shndx = backmap[sym->st_shndx];
    }
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}

#ifdef TCC_TARGET_ARM
স্থির শূন্য create_arm_attribute_section(TCCState *s1)
{
   // Needed for DLL support.
    স্থির ধ্রুব unsigned বর্ণ arm_attr[] = {
        0x41,                            // 'A'
        0x2c, 0x00, 0x00, 0x00,          // size 0x2c
        'a', 'e', 'a', 'b', 'i', 0x00,   // "aeabi"
        0x01, 0x22, 0x00, 0x00, 0x00,    // 'File Attributes', size 0x22
        0x05, 0x36, 0x00,                // 'CPU_name', "6"
#যদি CONFIG_TCC_CPUVER >= 7
        0x06, 0x0a,                      // 'CPU_arch', 'v7'
#অন্যথা
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
    unsigned বর্ণ *ptr = section_ptr_add(attr, পরিমাণ(arm_attr));
    attr->sh_addralign = 1;
    memcpy(ptr, arm_attr, পরিমাণ(arm_attr));
    যদি (s1->float_abi != ARM_HARD_FLOAT) {
        ptr[26] = 0x00; // 'FP_arch', 'No'
        ptr[41] = 0x1e; // 'ABI_optimization_goals'
        ptr[42] = 0x06; // 'Aggressive Debug'
    }
}
#endif

#ifdef TCC_TARGET_RISCV64
স্থির শূন্য create_riscv_attribute_section(TCCState *s1)
{
    স্থির ধ্রুব unsigned বর্ণ riscv_attr[] = {
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
    unsigned বর্ণ *ptr = section_ptr_add(attr, পরিমাণ(riscv_attr));
    attr->sh_addralign = 1;
    memcpy(ptr, riscv_attr, পরিমাণ(riscv_attr));
}
#endif

#যদি TARGETOS_OpenBSD || TARGETOS_NetBSD || TARGETOS_FreeBSD

স্থির শূন্য fill_bsd_note(Section *s, পূর্ণাঙ্ক type,
			  ধ্রুব বর্ণ *মান, uint32_t data)
{
    unsigned long offset = 0;
    বর্ণ *ptr;
    ElfW(Nhdr) *note;
    পূর্ণাঙ্ক align = s->sh_addralign;

    /* check if type present */
    যাবত্ (offset + পরিমাণ(ElfW(Nhdr)) < s->data_offset) {
        note = (ElfW(Nhdr) *) (s->data + offset);
	যদি (note->n_type == type)
	    প্রত্যাগম;
	offset += (পরিমাণ(ElfW(Nhdr)) + note->n_namesz + note->n_descsz +
		  align - 1) & -align;
    }
    ptr = section_ptr_add(s, পরিমাণ(ElfW(Nhdr)) + 8 + 4);
    note = (ElfW(Nhdr) *) ptr;
    note->n_namesz = 8;
    note->n_descsz = 4;
    note->n_type = type;
    strcpy (ptr + পরিমাণ(ElfW(Nhdr)), মান);
    memcpy (ptr + পরিমাণ(ElfW(Nhdr)) + 8, &data, 4);
}

স্থির Section *create_bsd_note_section(TCCState *s1,
					ধ্রুব বর্ণ *name,
					ধ্রুব বর্ণ *মান)
{
    Section *s;
    unsigned পূর্ণাঙ্ক major = 0, minor = 0, patch = 0;

#ifdef CONFIG_OS_RELEASE
    sscanf(CONFIG_OS_RELEASE, "%u.%u.%u", &major, &minor, &patch);
#endif
#যদি TARGETOS_FreeBSD
    যদি (major < 14)
	প্রত্যাগম রিক্ত;
#endif
    s = find_section (s1, name);
    s->sh_type = SHT_NOTE;
#যদি TARGETOS_OpenBSD
    fill_bsd_note(s, ELF_NOTE_OS_GNU, মান, 0);
#নোচেদ্যদি TARGETOS_NetBSD
    fill_bsd_note(s, 1 /* NT_NETBSD_IDENT_TAG */, মান,
		  major * 100000000u + (minor % 100u) * 1000000u +
		  (patch % 10000u) * 100u);
#নোচেদ্যদি TARGETOS_FreeBSD
    fill_bsd_note(s, 1 /* NT_FREEBSD_ABI_TAG */, মান,
		  major * 100000u + (minor % 100u) * 1000u);
    fill_bsd_note(s, 4 /* NT_FREEBSD_FEATURE_CTL */, মান, 0);
    fill_bsd_note(s, 2 /* NT_FREEBSD_NOINIT_TAG */, মান, 0);
#endif
    প্রত্যাগম s;
}
#endif

স্থির শূন্য alloc_sec_names(TCCState *s1, পূর্ণাঙ্ক is_obj);

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
স্থির পূর্ণাঙ্ক elf_output_file(TCCState *s1, ধ্রুব বর্ণ *filename)
{
    পূর্ণাঙ্ক i, ret, file_type, *sec_order;
    সংরচনা dyn_inf dyninf = {0};
    Section *interp, *dynstr, *dynamic;
    পূর্ণাঙ্ক textrel, got_sym, dt_flags_1;

    file_type = s1->output_type;
    ret = -1;
    interp = dynstr = dynamic = রিক্ত;
    sec_order = রিক্ত;

#ifdef TCC_TARGET_ARM
    create_arm_attribute_section (s1);
#endif

#ifdef TCC_TARGET_RISCV64
    create_riscv_attribute_section(s1);
#endif

#যদি TARGETOS_OpenBSD
    dyninf.note = create_bsd_note_section (s1, ".note.openbsd.ident", "OpenBSD");
#endif

#যদি TARGETOS_NetBSD
    dyninf.note = create_bsd_note_section (s1, ".note.netbsd.ident", "NetBSD");
#endif

#যদি TARGETOS_FreeBSD
    dyninf.note = create_bsd_note_section (s1, ".note.tag", "FreeBSD");
#endif

        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_add_runtime(s1);
	resolve_common_syms(s1);

        যদি (!s1->static_link) {
            যদি (file_type & TCC_OUTPUT_EXE) {
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
            dynamic->sh_entsize = পরিমাণ(ElfW(Dyn));

            got_sym = build_got(s1);
            যদি (file_type & TCC_OUTPUT_EXE) {
                bind_exe_dynsyms(s1, file_type & TCC_OUTPUT_DYN);
                যদি (s1->nb_errors)
                    গচ্ছ the_end;
            }
            build_got_entries(s1, got_sym);
            যদি (file_type & TCC_OUTPUT_EXE) {
                bind_libs_dynsyms(s1);
            } অন্যথা {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
#যদি TCC_EH_FRAME
	    /* fill with initial data */
	    tcc_eh_frame_hdr(s1, 0);
#endif
	    dyninf.gnu_hash = create_gnu_hash(s1);
        } অন্যথা {
            build_got_entries(s1, 0);
        }
	version_add (s1);

    textrel = set_sec_sizes(s1);

    যদি (!s1->static_link) {
        /* add a list of needed dlls */
        প্রতি(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            যদি (dllref->level == 0)
                put_dt(dynamic, DT_NEEDED, put_elf_str(dynstr, dllref->name));
        }

        যদি (s1->rpath)
            put_dt(dynamic, s1->enable_new_dtags ? DT_RUNPATH : DT_RPATH,
                   put_elf_str(dynstr, s1->rpath));

        dt_flags_1 = DF_1_NOW;
        যদি (file_type & TCC_OUTPUT_DYN) {
            যদি (s1->soname)
                put_dt(dynamic, DT_SONAME, put_elf_str(dynstr, s1->soname));
            /* XXX: currently, since we do not handle PIC code, we
               must relocate the readonly segments */
            যদি (textrel)
                put_dt(dynamic, DT_TEXTREL, 0);
            যদি (file_type & TCC_OUTPUT_EXE)
                dt_flags_1 = DF_1_NOW | DF_1_PIE;
	    যদি (s1->znodelete)
		dt_flags_1 |= DF_1_NODELETE;
        }
        put_dt(dynamic, DT_FLAGS, DF_BIND_NOW);
        put_dt(dynamic, DT_FLAGS_1, dt_flags_1);
        যদি (s1->symbolic)
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
    sec_order = tcc_malloc(পরিমাণ(পূর্ণাঙ্ক) * 2 * s1->nb_sections);
    /* compute section to program header mapping */
    layout_sections(s1, sec_order, &dyninf);

        যদি (dynamic) {
            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->data, dynamic->sh_addr);
            যদি (file_type == TCC_OUTPUT_EXE
                || (RELOCATE_DLLPLT && (file_type & TCC_OUTPUT_DYN)))
                relocate_plt(s1);
            /* relocate symbols in .dynsym now that final addresses are known */
            relocate_syms(s1, s1->dynsym, 2);
        }

        /* if building executable or DLL, then relocate each section
           except the GOT which is already relocated */
        relocate_syms(s1, s1->symtab, 0);
        যদি (s1->nb_errors != 0)
            গচ্ছ the_end;
        relocate_sections(s1);
        যদি (dynamic) {
	    update_reloc_sections (s1, &dyninf);
            dynamic->data_offset = dyninf.data_offset;
            fill_dynamic(s1, &dyninf);
	}
        /* Perform relocation to GOT or PLT entries */
        যদি (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        অন্যথা যদি (s1->got)
            fill_local_got_entries(s1);

    যদি (dyninf.gnu_hash)
        update_gnu_hash(s1, dyninf.gnu_hash);

    reorder_sections(s1, sec_order);
#যদি TCC_EH_FRAME
    /* fill with final data */
    tcc_eh_frame_hdr(s1, 1);
#endif
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, dyninf.phnum, dyninf.phdr);
 the_end:
    tcc_free(sec_order);
    tcc_free(dyninf.phdr);
    প্রত্যাগম ret;
}
#endif /* ndef ELF_OBJ_ONLY */

/* Allocate strings for section names */
স্থির শূন্য alloc_sec_names(TCCState *s1, পূর্ণাঙ্ক is_obj)
{
    পূর্ণাঙ্ক i;
    Section *s, *strsec;

    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");
    প্রতি(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        যদি (is_obj)
            s->sh_size = s->data_offset;
	যদি (s->sh_size || s == strsec || (s->sh_flags & SHF_ALLOC) || is_obj)
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_size = strsec->data_offset;
}

/* Output an elf .o file */
স্থির পূর্ণাঙ্ক elf_output_obj(TCCState *s1, ধ্রুব বর্ণ *filename)
{
    Section *s;
    পূর্ণাঙ্ক i, ret, file_offset;
    /* Allocate strings for section names */
    alloc_sec_names(s1, 1);
    file_offset = (পরিমাণ (ElfW(Ehdr)) + 3) & -4;
    file_offset += s1->nb_sections * পরিমাণ(ElfW(Shdr));
    প্রতি(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        file_offset = (file_offset + 15) & -16;
        s->sh_offset = file_offset;
        যদি (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_size;
    }
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, 0, রিক্ত);
    প্রত্যাগম ret;
}

LIBTCCAPI পূর্ণাঙ্ক tcc_output_file(TCCState *s, ধ্রুব বর্ণ *filename)
{
    s->nb_errors = 0;
    যদি (s->test_coverage)
        tcc_tcov_add_file(s, filename);
    যদি (s->output_type == TCC_OUTPUT_OBJ)
        প্রত্যাগম elf_output_obj(s, filename);
#ifdef TCC_TARGET_PE
    প্রত্যাগম  pe_output_file(s, filename);
#নোচেদ্যদি defined TCC_TARGET_MACHO
    প্রত্যাগম macho_output_file(s, filename);
#অন্যথা
    প্রত্যাগম elf_output_file(s, filename);
#endif
}

ST_FUNC ssize_t full_read(পূর্ণাঙ্ক fd, শূন্য *buf, size_t গুনতি_2) {
    বর্ণ *cbuf = buf;
    size_t rnum = 0;
    যাবত্ (1) {
        ssize_t অঙ্ক = পঠ(fd, cbuf, গুনতি_2-rnum);
        যদি (অঙ্ক < 0) প্রত্যাগম অঙ্ক;
        যদি (অঙ্ক == 0) প্রত্যাগম rnum;
        rnum += অঙ্ক;
        cbuf += অঙ্ক;
    }
}

ST_FUNC শূন্য *load_data(পূর্ণাঙ্ক fd, unsigned long file_offset, unsigned long size)
{
    শূন্য *data;

    data = tcc_malloc(size);
    lseek(fd, file_offset, SEEK_SET);
    full_read(fd, data, size);
    প্রত্যাগম data;
}

প্রকারনির্দেশ সংরচনা SectionMergeInfo {
    Section *s;            /* corresponding existing section */
    unsigned long offset;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} SectionMergeInfo;

ST_FUNC পূর্ণাঙ্ক tcc_object_type(পূর্ণাঙ্ক fd, ElfW(Ehdr) *h)
{
    পূর্ণাঙ্ক size = full_read(fd, h, পরিমাণ *h);
    যদি (size == পরিমাণ *h && 0 == memcmp(h, ELFMAG, 4)) {
        যদি (h->e_type == ET_REL)
            প্রত্যাগম AFF_BINTYPE_REL;
        যদি (h->e_type == ET_DYN)
            প্রত্যাগম AFF_BINTYPE_DYN;
    } অন্যথা যদি (size >= 8) {
        যদি (0 == memcmp(h, ARMAG, 8))
            প্রত্যাগম AFF_BINTYPE_AR;
#ifdef TCC_TARGET_COFF
        যদি (((সংরচনা filehdr*)h)->f_magic == COFF_C67_MAGIC)
            প্রত্যাগম AFF_BINTYPE_C67;
#endif
    }
    প্রত্যাগম 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC পূর্ণাঙ্ক tcc_load_object_file(TCCState *s1,
                                পূর্ণাঙ্ক fd, unsigned long file_offset)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    unsigned long size, offset, offseti;
    পূর্ণাঙ্ক i, j, nb_syms, sym_index, ret, seencompressed;
    বর্ণ *strsec, *strtab;
    পূর্ণাঙ্ক stab_index, stabstr_index;
    পূর্ণাঙ্ক *old_to_new_syms;
    বর্ণ *sh_name, *name;
    SectionMergeInfo *sm_table, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    lseek(fd, file_offset, SEEK_SET);
    যদি (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        গচ্ছ invalid;
    /* test CPU specific stuff */
    যদি (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
invalid:
        প্রত্যাগম tcc_error_noabort("invalid object file");
    }
    /* read sections */
    shdr = load_data(fd, file_offset + ehdr.e_shoff,
                     পরিমাণ(ElfW(Shdr)) * ehdr.e_shnum);
    sm_table = tcc_mallocz(পরিমাণ(SectionMergeInfo) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);

    /* load symtab and strtab */
    old_to_new_syms = রিক্ত;
    symtab = রিক্ত;
    strtab = রিক্ত;
    nb_syms = 0;
    seencompressed = 0;
    stab_index = stabstr_index = 0;
    ret = -1;

    প্রতি(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        যদি (sh->sh_type == SHT_SYMTAB) {
            যদি (symtab) {
                tcc_error_noabort("object must contain only one symtab");
                গচ্ছ the_end;
            }
            nb_syms = sh->sh_size / পরিমাণ(ElfW(Sym));
            symtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
            sm_table[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
        }
	যদি (sh->sh_flags & SHF_COMPRESSED)
	    seencompressed = 1;
    }

    /* now examine each section and try to merge its content with the
       ones in memory */
    প্রতি(i = 1; i < ehdr.e_shnum; i++) {
        /* no need to examine section name strtab */
        যদি (i == ehdr.e_shstrndx)
            অনুবর্ত;
        sh = &shdr[i];
	যদি (sh->sh_type == SHT_RELX)
	  sh = &shdr[sh->sh_info];
        /* ignore sections types we do not handle (plus relocs to those) */
        sh_name = strsec + sh->sh_name;
        যদি (0 == strncmp(sh_name, ".debug_", 7)
         || 0 == strncmp(sh_name, ".stab", 5)) {
	    যদি (!s1->do_debug || seencompressed)
	        অনুবর্ত;
#যদি !(TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD)
        } অন্যথা যদি (0 == strncmp(sh_name, ".eh_frame", 9)) {
            যদি (রিক্ত == eh_frame_section)
                অনুবর্ত;
#endif
        } অন্যথা
        যদি (sh->sh_type != SHT_PROGBITS &&
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

#যদি TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD
            && sh->sh_type != SHT_X86_64_UNWIND
#endif
            )
            অনুবর্ত;

	sh = &shdr[i];
        sh_name = strsec + sh->sh_name;
        যদি (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        /* find corresponding section, if any */
        প্রতি(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            যদি (strcmp(s->name, sh_name))
                অনুবর্ত;
            যদি (sh->sh_type != s->sh_type
                && strcmp (s->name, ".eh_frame")
                /* some crt1.o seem to have two ".note.GNU-stack" (SHT_NOTE & SHT_PROGBITS) */
                && strcmp (s->name, ".note.GNU-stack")
                ) {
                tcc_error_noabort("section type conflict: %s %02x <> %02x", s->name, sh->sh_type, s->sh_type);
                গচ্ছ the_end;
            }
            যদি (!strncmp(sh_name, ".gnu.linkonce", 13)) {
                /* if a 'linkonce' section is already present, we
                   do not add it again. It is a little tricky as
                   symbols can still be defined in
                   it. */
                sm_table[i].link_once = 1;
                গচ্ছ next;
            }
            যদি (stab_section) {
                যদি (s == stab_section)
                    stab_index = i;
                যদি (s == stab_section->link)
                    stabstr_index = i;
            }
            গচ্ছ found;
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
        যদি (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        sm_table[i].offset = offset;
        sm_table[i].s = s;
        /* concatenate sections */
        যদি (sh->sh_type != SHT_NOBITS && size) {
            unsigned বর্ণ *ptr;
            lseek(fd, file_offset + sh->sh_offset, SEEK_SET);
            ptr = s->data + offset;
            full_read(fd, ptr, size);
        }
#যদি defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
        /* align code sections to instruction lenght */
        /* This is needed if we compile a c file after this */
        যদি (s->sh_flags & SHF_EXECINSTR)
            section_add(s, 0, 4);
#endif
    next: ;
    }

    /* gr relocate stab strings */
    যদি (stab_index && stabstr_index) {
        Stab_Sym *a, *b;
        unsigned o;
        s = sm_table[stab_index].s;
        a = (Stab_Sym *)(s->data + sm_table[stab_index].offset);
        b = (Stab_Sym *)(s->data + s->data_offset);
        o = sm_table[stabstr_index].offset;
        যাবত্ (a < b) {
            যদি (a->n_strx)
                a->n_strx += o;
            a++;
        }
    }

    /* second short pass to update sh_link and sh_info fields of new
       sections */
    প্রতি(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        যদি (!s || !sm_table[i].new_section)
            অনুবর্ত;
        sh = &shdr[i];
        যদি (sh->sh_link > 0)
            s->link = sm_table[sh->sh_link].s;
        যদি (sh->sh_type == SHT_RELX) {
            s->sh_info = sm_table[sh->sh_info].s->sh_অঙ্ক;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }

    যদি (!symtab)
        গচ্ছ done;

    /* resolve symbols */
    old_to_new_syms = tcc_mallocz(nb_syms * পরিমাণ(পূর্ণাঙ্ক));

    sym = symtab + 1;
    প্রতি(i = 1; i < nb_syms; i++, sym++) {
        যদি (sym->st_shndx != SHN_UNDEF &&
            sym->st_shndx < SHN_LORESERVE) {
            sm = &sm_table[sym->st_shndx];
            যদি (sm->link_once) {
                /* if a symbol is in a link once section, we use the
                   already defined symbol. It is very important to get
                   correct relocations */
                যদি (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
                    name = strtab + sym->st_name;
                    sym_index = find_elf_sym(symtab_section, name);
                    যদি (sym_index)
                        old_to_new_syms[i] = sym_index;
                }
                অনুবর্ত;
            }
            /* if no corresponding section added, no need to add symbol */
            যদি (!sm->s)
                অনুবর্ত;
            /* convert section number */
            sym->st_shndx = sm->s->sh_অঙ্ক;
            /* offset value */
            sym->st_মান += sm->offset;
        }
        /* add symbol */
        name = strtab + sym->st_name;
        sym_index = set_elf_sym(symtab_section, sym->st_মান, sym->st_size,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_to_new_syms[i] = sym_index;
    }

    /* third pass to patch relocation entries */
    প্রতি(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        যদি (!s)
            অনুবর্ত;
        sh = &shdr[i];
        offset = sm_table[i].offset;
        size = sh->sh_size;
        বিকল্প(s->sh_type) {
        পক্ষ SHT_RELX:
            /* take relocation offset information */
            offseti = sm_table[sh->sh_info].offset;
	    প্রতি (rel = (ElfW_Rel *) s->data + (offset / পরিমাণ(*rel));
		 rel < (ElfW_Rel *) s->data + ((offset + size) / পরিমাণ(*rel));
		 rel++) {
                পূর্ণাঙ্ক type;
                unsigned sym_index;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_index = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                যদি (sym_index >= nb_syms)
                    গচ্ছ invalid_reloc;
                sym_index = old_to_new_syms[sym_index];
                /* ignore link_once in rel section. */
                যদি (!sym_index && !sm_table[sh->sh_info].link_once
#ifdef TCC_TARGET_ARM
                    && type != R_ARM_V4BX
#নোচেদ্যদি defined TCC_TARGET_RISCV64
                    && type != R_RISCV_ALIGN
                    && type != R_RISCV_RELAX
#endif
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, (পূর্ণাঙ্ক)rel->r_offset);
                    গচ্ছ the_end;
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
                যদি (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_index, 1)->plt_thumb_stub = 1;
#endif
            }
            ভঙ্গ;
        স্বভাব:
            ভঙ্গ;
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
    প্রত্যাগম ret;
}

প্রকারনির্দেশ সংরচনা ArchiveHeader {
    বর্ণ ar_name[16];           /* name of this member */
    বর্ণ ar_date[12];           /* file mtime */
    বর্ণ ar_uid[6];             /* owner uid; printed as decimal */
    বর্ণ ar_gid[6];             /* owner gid; printed as decimal */
    বর্ণ ar_mode[8];            /* file mode, printed as octal   */
    বর্ণ ar_size[10];           /* file size, printed as decimal */
    বর্ণ ar_fmag[2];            /* should contain ARFMAG */
} ArchiveHeader;

#define ARFMAG "`\n"

স্থির unsigned long long get_be(ধ্রুব uint8_t *b, পূর্ণাঙ্ক n)
{
    unsigned long long ret = 0;
    যাবত্ (n)
        ret = (ret << 8) | *b++, --n;
    প্রত্যাগম ret;
}

স্থির পূর্ণাঙ্ক read_ar_header(পূর্ণাঙ্ক fd, পূর্ণাঙ্ক offset, ArchiveHeader *hdr)
{
    বর্ণ *p, *e;
    পূর্ণাঙ্ক len;
    lseek(fd, offset, SEEK_SET);
    len = full_read(fd, hdr, পরিমাণ(ArchiveHeader));
    যদি (len != পরিমাণ(ArchiveHeader))
        প্রত্যাগম len ? -1 : 0;
    যদি (memcmp(hdr->ar_fmag, ARFMAG, পরিমাণ hdr->ar_fmag))
        প্রত্যাগম -1;
    p = hdr->ar_name;
    প্রতি (e = p + পরিমাণ hdr->ar_name; e > p && e[-1] == ' ';)
        --e;
    *e = '\0';
    hdr->ar_size[পরিমাণ hdr->ar_size-1] = 0;
    প্রত্যাগম len;
}

/* load only the objects which resolve undefined symbols */
স্থির পূর্ণাঙ্ক tcc_load_alacarte(TCCState *s1, পূর্ণাঙ্ক fd, পূর্ণাঙ্ক size, পূর্ণাঙ্ক entrysize)
{
    পূর্ণাঙ্ক i, bound, nsyms, sym_index, len, ret = -1;
    unsigned long long off;
    uint8_t *data;
    ধ্রুব বর্ণ *ar_names, *p;
    ধ্রুব uint8_t *ar_index;
    ElfW(Sym) *sym;
    ArchiveHeader hdr;

    data = tcc_malloc(size);
    যদি (full_read(fd, data, size) != size)
        গচ্ছ invalid;
    nsyms = get_be(data, entrysize);
    ar_index = data + entrysize;
    ar_names = (বর্ণ *) ar_index + nsyms * entrysize;

    কুরু {
        bound = 0;
        প্রতি (p = ar_names, i = 0; i < nsyms; i++, p += strlen(p)+1) {
            Section *s = symtab_section;
            sym_index = find_elf_sym(s, p);
            যদি (!sym_index)
                অনুবর্ত;
            sym = &((ElfW(Sym) *)s->data)[sym_index];
            যদি(sym->st_shndx != SHN_UNDEF)
                অনুবর্ত;
            off = get_be(ar_index + i * entrysize, entrysize);
            len = read_ar_header(fd, off, &hdr);
            যদি (len <= 0 || memcmp(hdr.ar_fmag, ARFMAG, 2)) {
        invalid:
                tcc_error_noabort("invalid archive");
                গচ্ছ the_end;
            }
            off += len;
            যদি (s1->verbose == 2)
                printf("   -> %s\n", hdr.ar_name);
            যদি (tcc_load_object_file(s1, fd, off) < 0)
                গচ্ছ the_end;
            ++bound;
        }
    } যাবত্(bound);
    ret = 0;
 the_end:
    tcc_free(data);
    প্রত্যাগম ret;
}

/* load a '.a' file */
ST_FUNC পূর্ণাঙ্ক tcc_load_archive(TCCState *s1, পূর্ণাঙ্ক fd, পূর্ণাঙ্ক alacarte)
{
    ArchiveHeader hdr;
    /* char magic[8]; */
    পূর্ণাঙ্ক size, len;
    unsigned long file_offset;
    ElfW(Ehdr) ehdr;

    /* skip magic which was already checked */
    /* full_read(fd, magic, sizeof(magic)); */
    file_offset = পরিমাণ ARMAG - 1;

    প্রতি(;;) {
        len = read_ar_header(fd, file_offset, &hdr);
        যদি (len == 0)
            প্রত্যাগম 0;
        যদি (len < 0)
            প্রত্যাগম tcc_error_noabort("invalid archive");
        file_offset += len;
        size = strtol(hdr.ar_size, রিক্ত, 0);
        যদি (alacarte) {
            /* coff symbol table : we handle it */
            যদি (!strcmp(hdr.ar_name, "/"))
                প্রত্যাগম tcc_load_alacarte(s1, fd, size, 4);
            যদি (!strcmp(hdr.ar_name, "/SYM64/"))
                প্রত্যাগম tcc_load_alacarte(s1, fd, size, 8);
        } অন্যথা যদি (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
            যদি (s1->verbose == 2)
                printf("   -> %s\n", hdr.ar_name);
            যদি (tcc_load_object_file(s1, fd, file_offset) < 0)
                প্রত্যাগম -1;
        }
        /* align to even */
        file_offset = (file_offset + size + 1) & ~1;
    }
}

#ifndef ELF_OBJ_ONLY
/* Set LV[I] to the global index of sym-version (LIB,VERSION).  Maybe resizes
   LV, maybe create a new entry for (LIB,VERSION).  */
স্থির শূন্য set_ver_to_ver(TCCState *s1, পূর্ণাঙ্ক *n, পূর্ণাঙ্ক **lv, পূর্ণাঙ্ক i, বর্ণ *lib, বর্ণ *version)
{
    যাবত্ (i >= *n) {
        *lv = tcc_realloc(*lv, (*n + 1) * পরিমাণ(**lv));
        (*lv)[(*n)++] = -1;
    }
    যদি ((*lv)[i] == -1) {
        পূর্ণাঙ্ক v, prev_same_lib = -1;
        প্রতি (v = 0; v < nb_sym_versions; v++) {
            যদি (strcmp(sym_versions[v].lib, lib))
              অনুবর্ত;
            prev_same_lib = v;
            যদি (!strcmp(sym_versions[v].version, version))
              ভঙ্গ;
        }
        যদি (v == nb_sym_versions) {
            sym_versions = tcc_realloc (sym_versions,
                                        (v + 1) * পরিমাণ(*sym_versions));
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
স্থির শূন্য
set_sym_version(TCCState *s1, পূর্ণাঙ্ক sym_index, পূর্ণাঙ্ক verndx)
{
    যদি (sym_index >= nb_sym_to_version) {
        পূর্ণাঙ্ক newelems = sym_index ? sym_index * 2 : 1;
        sym_to_version = tcc_realloc(sym_to_version,
                                     newelems * পরিমাণ(*sym_to_version));
        memset(sym_to_version + nb_sym_to_version, -1,
               (newelems - nb_sym_to_version) * পরিমাণ(*sym_to_version));
        nb_sym_to_version = newelems;
    }
    যদি (sym_to_version[sym_index] < 0)
      sym_to_version[sym_index] = verndx;
}

সংরচনা versym_info {
    পূর্ণাঙ্ক nb_versyms;
    ElfW(Verdef) *verdef;
    ElfW(Verneed) *verneed;
    ElfW(Half) *versym;
    পূর্ণাঙ্ক nb_local_ver, *local_ver;
};


স্থির শূন্য store_version(TCCState *s1, সংরচনা versym_info *v, বর্ণ *dynstr)
{
    বর্ণ *lib, *version;
    uint32_t next;
    পূর্ণাঙ্ক i;

#define	DEBUG_VERSION 0

    যদি (v->versym && v->verdef) {
      ElfW(Verdef) *vdef = v->verdef;
      lib = রিক্ত;
      কুরু {
        ElfW(Verdaux) *verdaux =
	  (ElfW(Verdaux) *) (((বর্ণ *) vdef) + vdef->vd_aux);

#যদি DEBUG_VERSION
	printf ("verdef: version:%u flags:%u index:%u, hash:%u\n",
	        vdef->vd_version, vdef->vd_flags, vdef->vd_ndx,
		vdef->vd_hash);
#endif
	যদি (vdef->vd_cnt) {
          version = dynstr + verdaux->vda_name;

	  যদি (lib == রিক্ত)
	    lib = version;
	  অন্যথা
            set_ver_to_ver(s1, &v->nb_local_ver, &v->local_ver, vdef->vd_ndx,
                           lib, version);
#যদি DEBUG_VERSION
	  printf ("  verdaux(%u): %s\n", vdef->vd_ndx, version);
#endif
	}
        next = vdef->vd_next;
        vdef = (ElfW(Verdef) *) (((বর্ণ *) vdef) + next);
      } যাবত্ (next);
    }
    যদি (v->versym && v->verneed) {
      ElfW(Verneed) *vneed = v->verneed;
      কুরু {
        ElfW(Vernaux) *vernaux =
	  (ElfW(Vernaux) *) (((বর্ণ *) vneed) + vneed->vn_aux);

        lib = dynstr + vneed->vn_file;
#যদি DEBUG_VERSION
	printf ("verneed: %u %s\n", vneed->vn_version, lib);
#endif
	প্রতি (i = 0; i < vneed->vn_cnt; i++) {
	  যদি ((vernaux->vna_other & 0x8000) == 0) { /* hidden */
              version = dynstr + vernaux->vna_name;
              set_ver_to_ver(s1, &v->nb_local_ver, &v->local_ver, vernaux->vna_other,
                             lib, version);
#যদি DEBUG_VERSION
	    printf ("  vernaux(%u): %u %u %s\n",
		    vernaux->vna_other, vernaux->vna_hash,
		    vernaux->vna_flags, version);
#endif
	  }
	  vernaux = (ElfW(Vernaux) *) (((বর্ণ *) vernaux) + vernaux->vna_next);
	}
        next = vneed->vn_next;
        vneed = (ElfW(Verneed) *) (((বর্ণ *) vneed) + next);
      } যাবত্ (next);
    }

#যদি DEBUG_VERSION
    প্রতি (i = 0; i < v->nb_local_ver; i++) {
      যদি (v->local_ver[i] > 0) {
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
ST_FUNC পূর্ণাঙ্ক tcc_load_dll(TCCState *s1, পূর্ণাঙ্ক fd, ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    পূর্ণাঙ্ক i, nb_syms, nb_dts, sym_bind, ret = -1;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;

    বর্ণ *dynstr;
    পূর্ণাঙ্ক sym_index;
    ধ্রুব বর্ণ *name, *soname;
    সংরচনা versym_info v;

    full_read(fd, &ehdr, পরিমাণ(ehdr));

    /* test CPU specific stuff */
    যদি (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
        প্রত্যাগম tcc_error_noabort("bad architecture");
    }

    /* read sections */
    shdr = load_data(fd, ehdr.e_shoff, পরিমাণ(ElfW(Shdr)) * ehdr.e_shnum);

    /* load dynamic section and dynamic symbols */
    nb_syms = 0;
    nb_dts = 0;
    dynamic = রিক্ত;
    dynsym = রিক্ত; /* avoid warning */
    dynstr = রিক্ত; /* avoid warning */
    memset(&v, 0, পরিমাণ v);

    প্রতি(i = 0, sh = shdr; i < ehdr.e_shnum; i++, sh++) {
        বিকল্প(sh->sh_type) {
        পক্ষ SHT_DYNAMIC:
            nb_dts = sh->sh_size / পরিমাণ(ElfW(Dyn));
            dynamic = load_data(fd, sh->sh_offset, sh->sh_size);
            ভঙ্গ;
        পক্ষ SHT_DYNSYM:
            nb_syms = sh->sh_size / পরিমাণ(ElfW(Sym));
            dynsym = load_data(fd, sh->sh_offset, sh->sh_size);
            sh1 = &shdr[sh->sh_link];
            dynstr = load_data(fd, sh1->sh_offset, sh1->sh_size);
            ভঙ্গ;
        পক্ষ SHT_GNU_verdef:
	    v.verdef = load_data(fd, sh->sh_offset, sh->sh_size);
	    ভঙ্গ;
        পক্ষ SHT_GNU_verneed:
	    v.verneed = load_data(fd, sh->sh_offset, sh->sh_size);
	    ভঙ্গ;
        পক্ষ SHT_GNU_versym:
            v.nb_versyms = sh->sh_size / পরিমাণ(ElfW(Half));
	    v.versym = load_data(fd, sh->sh_offset, sh->sh_size);
	    ভঙ্গ;
        স্বভাব:
            ভঙ্গ;
        }
    }

    যদি (!dynamic)
        গচ্ছ the_end;

    /* compute the real library name */
    soname = tcc_basename(filename);
    প্রতি(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        যদি (dt->d_tag == DT_SONAME)
            soname = dynstr + dt->d_un.d_val;

    /* if the dll is already loaded, do not load it */
    যদি (tcc_add_dllref(s1, soname, level)->found)
        গচ্ছ ret_success;

    যদি (v.nb_versyms != nb_syms)
        tcc_free (v.versym), v.versym = রিক্ত;
    অন্যথা
        store_version(s1, &v, dynstr);

    /* add dynamic symbols in dynsym_section */
    প্রতি(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        যদি (sym_bind == STB_LOCAL)
            অনুবর্ত;
        name = dynstr + sym->st_name;
        sym_index = set_elf_sym(s1->dynsymtab_section, sym->st_মান, sym->st_size,
                                sym->st_info, sym->st_other, sym->st_shndx, name);
        যদি (v.versym) {
            ElfW(Half) vsym = v.versym[i];
            যদি ((vsym & 0x8000) == 0 && vsym > 0 && vsym < v.nb_local_ver)
                set_sym_version(s1, sym_index, v.local_ver[vsym]);
        }
    }

    /* do not load all referenced libraries
       (recursive loading can break linking of libraries) */
    /* following DT_NEEDED is needed for the dynamic loader (libdl.so),
       but it is no longer needed, when linking a library or a program.
       When tcc output mode is OUTPUT_MEM,
       tcc calls dlopen, which handles DT_NEEDED for us */

#যদি 0
    প্রতি(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        যদি (dt->d_tag == DT_RPATH)
            tcc_add_library_path(s1, dynstr + dt->d_un.d_val);

    /* load all referenced DLLs */
    প্রতি(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        বিকল্প(dt->d_tag) {
        পক্ষ DT_NEEDED:
            name = dynstr + dt->d_un.d_val;
            যদি (tcc_add_dllref(s1, name, -1))
                অনুবর্ত;
            যদি (tcc_add_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                ret = tcc_error_noabort("referenced dll '%s' not found", name);
                গচ্ছ the_end;
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
    প্রত্যাগম ret;
}

#define LD_TOK_NAME 256
#define LD_TOK_EOF  (-1)
স্থির পূর্ণাঙ্ক ld_inp(TCCState *s1)
{
    পূর্ণাঙ্ক c = *s1->ld_p;
    যদি (c == 0)
        প্রত্যাগম CH_EOF;
    ++s1->ld_p;
    প্রত্যাগম c;
}
#define ld_unget(s1, ch) যদি (ch != CH_EOF) --s1->ld_p

/* return next ld script token */
স্থির পূর্ণাঙ্ক ld_next(TCCState *s1, বর্ণ *name, পূর্ণাঙ্ক name_size)
{
    পূর্ণাঙ্ক c, d, ch;
    বর্ণ *q;

 redo:
    ch = ld_inp(s1);
    q = name, *q++ = ch;
    বিকল্প(ch) {
    পক্ষ ' ':
    পক্ষ '\t':
    পক্ষ '\f':
    পক্ষ '\v':
    পক্ষ '\r':
    পক্ষ '\n':
        গচ্ছ redo;
    পক্ষ '/':
        ch = ld_inp(s1);
        যদি (ch == '*') { /* comment */
            প্রতি (d = 0;; d = ch) {
                ch = ld_inp(s1);
                যদি (ch == CH_EOF || (ch == '/' && d == '*'))
                    ভঙ্গ;
            }
            গচ্ছ redo;
        } অন্যথা {
            গচ্ছ parse_name;
        }
        ভঙ্গ;
    পক্ষ '\\':
    /* case 'a' ... 'z': */
    পক্ষ 'a':
       পক্ষ 'b':
       পক্ষ 'c':
       পক্ষ 'd':
       পক্ষ 'e':
       পক্ষ 'f':
       পক্ষ 'g':
       পক্ষ 'h':
       পক্ষ 'i':
       পক্ষ 'j':
       পক্ষ 'k':
       পক্ষ 'l':
       পক্ষ 'm':
       পক্ষ 'n':
       পক্ষ 'o':
       পক্ষ 'p':
       পক্ষ 'q':
       পক্ষ 'r':
       পক্ষ 's':
       পক্ষ 't':
       পক্ষ 'u':
       পক্ষ 'v':
       পক্ষ 'w':
       পক্ষ 'x':
       পক্ষ 'y':
       পক্ষ 'z':
    /* case 'A' ... 'z': */
    পক্ষ 'A':
       পক্ষ 'B':
       পক্ষ 'C':
       পক্ষ 'D':
       পক্ষ 'E':
       পক্ষ 'F':
       পক্ষ 'G':
       পক্ষ 'H':
       পক্ষ 'I':
       পক্ষ 'J':
       পক্ষ 'K':
       পক্ষ 'L':
       পক্ষ 'M':
       পক্ষ 'N':
       পক্ষ 'O':
       পক্ষ 'P':
       পক্ষ 'Q':
       পক্ষ 'R':
       পক্ষ 'S':
       পক্ষ 'T':
       পক্ষ 'U':
       পক্ষ 'V':
       পক্ষ 'W':
       পক্ষ 'X':
       পক্ষ 'Y':
       পক্ষ 'Z':
    পক্ষ '-':
    পক্ষ '_':
    পক্ষ '.':
    পক্ষ '$':
    পক্ষ '~':
        প্রতি(;;) {
            ch = ld_inp(s1);
    parse_name:
            যদি (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') ||
                  strchr("/.-_+=$:\\,~", ch)))
                ভঙ্গ;
            যদি ((q - name) < name_size - 1) {
                *q++ = ch;
            }
        }
        ld_unget(s1, ch);
        c = LD_TOK_NAME;
        ভঙ্গ;
    পক্ষ CH_EOF:
        c = LD_TOK_EOF;
        ভঙ্গ;
    স্বভাব:
        c = ch;
        ভঙ্গ;
    }
    *q = '\0';
    প্রত্যাগম c;
}

স্থির পূর্ণাঙ্ক ld_add_file(TCCState *s1, ধ্রুব বর্ণ filename[])
{
    যদি (filename[0] == '-' && filename[1] == 'l')
        প্রত্যাগম tcc_add_library(s1, filename + 2);
    যদি (CONFIG_SYSROOT[0] != '\0' || !IS_ABSPATH(filename)) {
        /* lookup via library paths */
        পূর্ণাঙ্ক ret = tcc_add_dll(s1, tcc_basename(filename), 0);
        যদি (ret != FILE_NOT_FOUND)
            প্রত্যাগম ret;
    }
    প্রত্যাগম tcc_add_file_internal(s1, filename, AFF_PRINT_ERROR);
}

/* did static libraries add new undefined symbols? */
স্থির পূর্ণাঙ্ক new_undef_sym(TCCState *s1, পূর্ণাঙ্ক sym_offset)
{
    যাবত্ (sym_offset < s1->symtab->data_offset) {
        ElfW(Sym) *esym = (শূন্য*)(s1->symtab->data + sym_offset);
        যদি (esym->st_shndx == SHN_UNDEF)
            প্রত্যাগম 1;
        sym_offset += পরিমাণ (ElfW(Sym));
    }
    প্রত্যাগম 0;
}

স্থির পূর্ণাঙ্ক ld_add_file_list(TCCState *s1, ধ্রুব বর্ণ *cmd)
{
    বর্ণ filename[1024];
    পূর্ণাঙ্ক t, c, sym_offset, ret = 0;
    unsigned বর্ণ *pos = s1->ld_p;

repeat:
    s1->ld_p = pos;
    sym_offset = s1->symtab->data_offset;
    c = cmd[0];

    t = ld_next(s1, filename, পরিমাণ(filename));
    যদি (t != '(')
        প্রত্যাগম tcc_error_noabort("expected '(' after %s", cmd);
    t = ld_next(s1, filename, পরিমাণ(filename));
    প্রতি(;;) {
        যদি (t == LD_TOK_EOF) {
            প্রত্যাগম tcc_error_noabort("unexpected end of file");
        } অন্যথা যদি (t == ')') {
            ভঙ্গ;
        } অন্যথা যদি (t != LD_TOK_NAME) {
            প্রত্যাগম tcc_error_noabort("unexpected token '%c'", t);
        } অন্যথা যদি (!strcmp(filename, "AS_NEEDED")) {
            ret |= ld_add_file_list(s1, filename);
        } অন্যথা যদি (c == 'I' || c == 'G' || c == 'A') {
            ret |= !!ld_add_file(s1, filename);
        }
        যদি (ret < 0)
            প্রত্যাগম ret;
        t = ld_next(s1, filename, পরিমাণ(filename));
        যদি (t == ',')
            t = ld_next(s1, filename, পরিমাণ(filename));
    }
    যদি (c == 'G' && ret == 0 && new_undef_sym(s1, sym_offset))
        গচ্ছ repeat;
    প্রত্যাগম ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC পূর্ণাঙ্ক tcc_load_ldscript(TCCState *s1, পূর্ণাঙ্ক fd)
{
    বর্ণ cmd[64];
    পূর্ণাঙ্ক t, ret = 0, noscript = 1;
    unsigned বর্ণ *text_ptr, *saved_ptr;

    saved_ptr = s1->ld_p;
    s1->ld_p = text_ptr = (শূন্য*)tcc_load_text(fd);
    প্রতি(;;) {
        t = ld_next(s1, cmd, পরিমাণ(cmd));
        যদি (t == LD_TOK_EOF)
            ভঙ্গ;
        যদি (!strcmp(cmd, "INPUT") ||
            !strcmp(cmd, "GROUP")) {
            ret |= ld_add_file_list(s1, cmd);
        } অন্যথা যদি (!strcmp(cmd, "OUTPUT_FORMAT") ||
                   !strcmp(cmd, "TARGET")) {
            /* ignore some commands */
            ret |= ld_add_file_list(s1, cmd);
        } অন্যথা যদি (noscript) {
            ret = FILE_NOT_RECOGNIZED;
        } অন্যথা {
            ret = tcc_error_noabort("unexpected '%s'", cmd);
        }
        যদি (ret < 0)
            ভঙ্গ;
        noscript = 0;
    }
    tcc_free(text_ptr);
    s1->ld_p = saved_ptr;
    প্রত্যাগম ret < 0 ? ret : -ret;
}
#endif /* !ELF_OBJ_ONLY */
