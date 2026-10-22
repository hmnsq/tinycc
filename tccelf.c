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

#ضمن "tcc.h"

/* Define this to get some debug output during relocation processing.  */
#undef DEBUG_RELOC

/********************************************************/
/* global variables */

/* elf version information */
بنية sym_version {
    حرف *lib;
    حرف *version;
    صحيح out_index;
    صحيح prev_same_lib;
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
ساكن ثابت حرف rdata[] = ".rdata";
#ܐܚܪܢܐ
#define shf_RELRO SHF_ALLOC /* eventually made SHF_WRITE in sort_sections() */
ساكن ثابت حرف rdata[] = ".data.ro";
#endif

/* ------------------------------------------------------------------------- */

ST_FUNC فراغ tccelf_new(TCCState *s)
{
    TCCState *s1 = s;

    /* no section zero */
    dynarray_add(&s->sections, &s->nb_sections, عدم);

    /* create standard sections */
    text_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    data_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    /* create ro data section (make ro after relocation done with GNU_RELRO) */
    rodata_section = new_section(s, rdata, SHT_PROGBITS, shf_RELRO);
    bss_section = new_section(s, ".bss", SHT_NOBITS, SHF_ALLOC | SHF_WRITE);
    common_section = new_section(s, ".common", SHT_NOBITS, SHF_PRIVATE);
    common_section->sh_num = SHN_COMMON;

    /* symbols are always generated for linking stage */
    symtab_section = new_symtab(s, ".symtab", SHT_SYMTAB, 0,
                                ".strtab",
                                ".hashtab", SHF_PRIVATE);

    /* private symbol table for dynamic symbols */
    s->dynsymtab_section = new_symtab(s, ".dynsymtab", SHT_SYMTAB, SHF_PRIVATE|SHF_DYNSYM,
                                      ".dynstrtab",
                                      ".dynhashtab", SHF_PRIVATE);
    get_sym_attr(s, 0, 1);

    ܐܢ (s->do_debug) {
        /* add debug sections */
        tcc_debug_new(s);
    }

#ܐܢ TCC_EH_FRAME
    ܐܢ (s->output_format != TCC_OUTPUT_FORMAT_ELF)
        s->unwind_tables = 0;
    tcc_eh_frame_start(s);
#endif

#ifdef CONFIG_TCC_BCHECK
    ܐܢ (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        /* (make ro after relocation done with GNU_RELRO) */
        bounds_section = new_section(s, ".bounds", SHT_PROGBITS, shf_RELRO);
        lbounds_section = new_section(s, ".lbounds", SHT_PROGBITS, shf_RELRO);
    }
#endif

#ifdef TCC_TARGET_PE
    /* to make sure that -ltcc1 -Wl,-e,_start will grab the startup code
       from libtcc1.a (unless _start defined) */
    ܐܢ (s->elf_entryname)
        set_global_sym(s, s->elf_entryname, عدم, 0); /* SHN_UNDEF */
#endif

#ifndef ELF_OBJ_ONLY
    ܐܢ (عدم == s->elfint && s1->output_type != TCC_OUTPUT_OBJ) {
        ثابت حرف *p = CONFIG_TCC_ELFINTERP;
#ܐܢ defined TCC_TARGET_ARM && defined CONFIG_TCC_ELFINTERP_ARMHF
        ܐܢ (s->float_abi == ARM_HARD_FLOAT)
            p = CONFIG_TCC_ELFINTERP_ARMHF;
#endif
#ܐܢ defined TCC_IS_NATIVE && defined TARGETOS_BSD
        /* see commit 55cb2170cd5ce77a7d76dcaf462fad2707281605 */
        { ثابت حرف *e = getenv("LD_SO"); ܐܢ (e) p = e; }
#endif
        s->elfint = tcc_strdup(p);
    }
#endif /* ndef ELF_OBJ_ONLY */
}

ST_FUNC فراغ free_section(Section *s)
{
    ܐܢ (!s)
        ܦܢܐ;
    tcc_free(s->data);
    s->data = عدم;
    s->data_allocated = s->data_offset = 0;
}

ST_FUNC فراغ tccelf_delete(TCCState *s1)
{
    صحيح i;

#ifndef ELF_OBJ_ONLY
    /* free symbol versions */
    لكل (i = 0; i < nb_sym_versions; i++) {
        tcc_free(sym_versions[i].version);
        tcc_free(sym_versions[i].lib);
    }
    tcc_free(sym_versions);
    tcc_free(sym_to_version);
#endif

    /* free all sections */
    لكل(i = 1; i < s1->nb_sections; i++)
        free_section(s1->sections[i]);
    dynarray_reset(&s1->sections, &s1->nb_sections);

    لكل(i = 0; i < s1->nb_priv_sections; i++)
        free_section(s1->priv_sections[i]);
    dynarray_reset(&s1->priv_sections, &s1->nb_priv_sections);

    tcc_free(s1->sym_attrs);
    symtab_section = عدم; /* for tccrun.c:rt_printline() */
}

/* save section data state */
ST_FUNC فراغ tccelf_begin_file(TCCState *s1)
{
    Section *s; صحيح i;
    لكل (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        s->sh_offset = s->data_offset;
    }
    /* disable symbol hashing during compilation */
    s = s1->symtab, s->reloc = s->hash, s->hash = عدم;
#ܐܢ defined TCC_TARGET_X86_64 && defined TCC_TARGET_PE
    s1->uw_sym = 0;
    s1->uw_offs = 0;
#endif
}

ساكن فراغ update_relocs(TCCState *s1, Section *s, صحيح *old_to_new_syms, صحيح first_sym);

/* At the end of compilation, convert any UNDEF syms to global, and merge
   with previously existing symbols */
ST_FUNC فراغ tccelf_end_file(TCCState *s1)
{
    Section *s = s1->symtab;
    صحيح first_sym, nb_syms, *tr, i;

    first_sym = s->sh_offset / حجم (ElfSym);
    nb_syms = s->data_offset / حجم (ElfSym) - first_sym;
    s->data_offset = s->sh_offset;
    s->link->data_offset = s->link->sh_offset;
    s->hash = s->reloc, s->reloc = عدم;
    tr = tcc_mallocz(nb_syms * حجم *tr);

    لكل (i = 0; i < nb_syms; ++i) {
        ElfSym *sym = (ElfSym*)s->data + first_sym + i;
        ܐܢ (sym->st_shndx == SHN_UNDEF) {
            صحيح sym_bind = ELFW(ST_BIND)(sym->st_info);
            صحيح sym_type = ELFW(ST_TYPE)(sym->st_info);
            ܐܢ (sym_bind == STB_LOCAL)
                sym_bind = STB_GLOBAL;
#ifndef TCC_TARGET_PE
            ܐܢ (sym_bind == STB_GLOBAL && s1->output_type == TCC_OUTPUT_OBJ) {
                /* undefined symbols with STT_FUNC are confusing gnu ld when
                   linking statically to STT_GNU_IFUNC.  Keep TLS typed,
                   otherwise gnu ld rejects non-TLS refs to TLS definitions. */
                ܐܢ (sym_type != STT_TLS)
                    sym_type = STT_NOTYPE;
            }
#endif
            sym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
        }
        tr[i] = set_elf_sym(s, sym->st_value, sym->st_size, sym->st_info,
            sym->st_other, sym->st_shndx, (حرف*)s->link->data + sym->st_name);
    }
    /* now update relocations */
    update_relocs(s1, s, tr, first_sym);
    tcc_free(tr);
    /* record text/data/bss output for -bench info */
    لكل (i = 0; i < 4; ++i) {
        s = s1->sections[i + 1];
        s1->total_output[i] += s->data_offset - s->sh_offset;
    }
}

ST_FUNC Section *new_section(TCCState *s1, ثابت حرف *name, صحيح sh_type, صحيح sh_flags)
{
    Section *sec;

    sec = tcc_mallocz(حجم(Section) + strlen(name));
    sec->s1 = s1;
    strcpy(sec->name, name);
    sec->sh_type = sh_type;
    sec->sh_flags = sh_flags;
    بدل(sh_type) {
    حالة SHT_GNU_versym:
        sec->sh_addralign = 2;
        اكسر;
    حالة SHT_HASH:
    حالة SHT_GNU_HASH:
    حالة SHT_REL:
    حالة SHT_RELA:
    حالة SHT_DYNSYM:
    حالة SHT_SYMTAB:
    حالة SHT_DYNAMIC:
    حالة SHT_GNU_verneed:
    حالة SHT_GNU_verdef:
        sec->sh_addralign = PTR_SIZE;
        اكسر;
    حالة SHT_STRTAB:
        sec->sh_addralign = 1;
        اكسر;
    افتراضي:
        sec->sh_addralign =  PTR_SIZE; /* gcc/pcc default alignment */
        اكسر;
    }

    ܐܢ (sh_flags & SHF_PRIVATE) {
        dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } ܐܚܪܢܐ {
        sec->sh_num = s1->nb_sections;
        dynarray_add(&s1->sections, &s1->nb_sections, sec);
    }

    ܦܢܐ sec;
}

ST_FUNC فراغ init_symtab(Section *s)
{
    صحيح *ptr, nb_buckets = 1;
    put_elf_str(s->link, "");
    section_ptr_add(s, حجم (ElfW(Sym)));
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + 1) * حجم(صحيح));
    ptr[0] = nb_buckets;
    ptr[1] = 1;
    memset(ptr + 2, 0, (nb_buckets + 1) * حجم(صحيح));
}

ST_FUNC Section *new_symtab(TCCState *s1,
                           ثابت حرف *symtab_name, صحيح sh_type, صحيح sh_flags,
                           ثابت حرف *strtab_name,
                           ثابت حرف *hash_name, صحيح hash_sh_flags)
{
    Section *symtab, *strtab, *hash;
    symtab = new_section(s1, symtab_name, sh_type, sh_flags);
    symtab->sh_entsize = حجم(ElfW(Sym));
    strtab = new_section(s1, strtab_name, SHT_STRTAB, sh_flags);
    symtab->link = strtab;
    hash = new_section(s1, hash_name, SHT_HASH, hash_sh_flags);
    hash->sh_entsize = حجم(صحيح);
    symtab->hash = hash;
    hash->link = symtab;
    init_symtab(symtab);
    ܦܢܐ symtab;
}

/* realloc section and set its content to zero */
ST_FUNC فراغ section_realloc(Section *sec, unsigned long new_size)
{
    unsigned long size;
    unsigned حرف *data;

    size = sec->data_allocated;
    ܐܢ (size == 0)
        size = 1;
    ܟܡܐ (size < new_size)
        size = size * 2;
    data = tcc_realloc(sec->data, size);
    memset(data + sec->data_allocated, 0, size - sec->data_allocated);
    sec->data = data;
    sec->data_allocated = size;
}

/* reserve at least 'size' bytes aligned per 'align' in section
   'sec' from current offset, and return the aligned offset */
ST_FUNC size_t section_add(Section *sec, addr_t size, صحيح align)
{
    size_t offset, offset1;

    offset = (sec->data_offset + align - 1) & -align;
    offset1 = offset + size;
    ܐܢ (sec->sh_type != SHT_NOBITS && offset1 > sec->data_allocated)
        section_realloc(sec, offset1);
    sec->data_offset = offset1;
    ܐܢ (align > sec->sh_addralign)
        sec->sh_addralign = align;
    ܦܢܐ offset;
}

/* reserve at least 'size' bytes in section 'sec' from
   sec->data_offset. */
ST_FUNC فراغ *section_ptr_add(Section *sec, addr_t size)
{
    size_t offset = section_add(sec, size, 1);
    ܦܢܐ sec->data + offset;
}

#ifndef ELF_OBJ_ONLY
/* reserve at least 'size' bytes from section start */
ساكن فراغ section_reserve(Section *sec, unsigned long size)
{
    ܐܢ (size > sec->data_allocated)
        section_realloc(sec, size);
    ܐܢ (size > sec->data_offset)
        sec->data_offset = size;
}
#endif

ساكن Section *have_section(TCCState *s1, ثابت حرف *name)
{
    Section *sec;
    صحيح i;
    لكل(i = 1; i < s1->nb_sections; i++) {
        sec = s1->sections[i];
        ܐܢ (!strcmp(name, sec->name))
            ܦܢܐ sec;
    }
    ܦܢܐ عدم;
}

/* return a reference to a section, and create it if it does not
   exists */
ST_FUNC Section *find_section(TCCState *s1, ثابت حرف *name)
{
    Section *sec = have_section(s1, name);
    ܐܢ (sec)
        ܦܢܐ sec;
    /* sections are created as PROGBITS */
    ܦܢܐ new_section(s1, name, SHT_PROGBITS, SHF_ALLOC);
}

/* ------------------------------------------------------------------------- */

ST_FUNC صحيح put_elf_str(Section *s, ثابت حرف *sym)
{
    صحيح offset, len;
    حرف *ptr;

    len = strlen(sym) + 1;
    offset = s->data_offset;
    ptr = section_ptr_add(s, len);
    memmove(ptr, sym, len);
    ܦܢܐ offset;
}

/* elf symbol hashing function */
ساكن ElfW(Word) elf_hash(ثابت unsigned حرف *name)
{
    ElfW(Word) h = 0, g;

    ܟܡܐ (*name) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        ܐܢ (g)
            h ^= g >> 24;
        h &= ~g;
    }
    ܦܢܐ h;
}

/* rebuild hash table of section s */
/* NOTE: we do factorize the hash table code to go faster */
ساكن فراغ rebuild_hash(Section *s, unsigned صحيح nb_buckets)
{
    ElfW(Sym) *sym;
    صحيح *ptr, *hash, nb_syms, sym_index, h;
    unsigned حرف *strtab;

    strtab = s->link->data;
    nb_syms = s->data_offset / حجم(ElfW(Sym));

    ܐܢ (!nb_buckets)
        nb_buckets = ((صحيح*)s->hash->data)[0];

    s->hash->data_offset = 0;
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + nb_syms) * حجم(صحيح));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    memset(hash, 0, (nb_buckets + 1) * حجم(صحيح));
    ptr += nb_buckets + 1;

    sym = (ElfW(Sym) *)s->data + 1;
    لكل(sym_index = 1; sym_index < nb_syms; sym_index++) {
        ܐܢ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            h = elf_hash(strtab + sym->st_name) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_index;
        } ܐܚܪܢܐ {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}

/* return the symbol number */
ST_FUNC صحيح put_elf_sym(Section *s, addr_t value, unsigned long size,
    صحيح info, صحيح other, صحيح shndx, ثابت حرف *name)
{
    صحيح name_offset, sym_index;
    صحيح nbuckets, h;
    ElfW(Sym) *sym;
    Section *hs;

    sym = section_ptr_add(s, حجم(ElfW(Sym)));
    ܐܢ (name && name[0])
        name_offset = put_elf_str(s->link, name);
    ܐܚܪܢܐ
        name_offset = 0;
    /* XXX: endianness */
    sym->st_name = name_offset;
    sym->st_value = value;
    sym->st_size = size;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
    sym_index = sym - (ElfW(Sym) *)s->data;
    hs = s->hash;
    ܐܢ (hs) {
        صحيح *ptr, *base;
        ptr = section_ptr_add(hs, حجم(صحيح));
        base = (صحيح *)hs->data;
        /* only add global or weak symbols. */
        ܐܢ (ELFW(ST_BIND)(info) != STB_LOCAL) {
            /* add another hashing entry */
            nbuckets = base[0];
            h = elf_hash((unsigned حرف *)s->link->data + name_offset) % nbuckets;
            *ptr = base[2 + h];
            base[2 + h] = sym_index;
            base[1]++;
            /* we resize the hash table */
            hs->nb_hashed_syms++;
            ܐܢ (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } ܐܚܪܢܐ {
            *ptr = 0;
            base[1]++;
        }
    }
    ܦܢܐ sym_index;
}

ST_FUNC صحيح find_elf_sym(Section *s, ثابت حرف *name)
{
    ElfW(Sym) *sym;
    Section *hs;
    صحيح nbuckets, sym_index, h;
    ثابت حرف *name1;

    hs = s->hash;
    ܐܢ (!hs)
        ܦܢܐ 0;
    nbuckets = ((صحيح *)hs->data)[0];
    h = elf_hash((unsigned حرف *) name) % nbuckets;
    sym_index = ((صحيح *)hs->data)[2 + h];
    ܟܡܐ (sym_index != 0) {
        sym = &((ElfW(Sym) *)s->data)[sym_index];
        name1 = (حرف *) s->link->data + sym->st_name;
        ܐܢ (!strcmp(name, name1))
            ܦܢܐ sym_index;
        sym_index = ((صحيح *)hs->data)[2 + nbuckets + sym_index];
    }
    ܦܢܐ 0;
}

/* return elf symbol value, signal error if 'err' is nonzero, decorate
   name if FORC */
ST_FUNC addr_t get_sym_addr(TCCState *s1, ثابت حرف *name, صحيح err, صحيح forc)
{
    صحيح sym_index;
    ElfW(Sym) *sym;
    حرف buf[256];
    ܐܢ (forc && s1->leading_underscore
#ifdef TCC_TARGET_PE
        /* win32-32bit stdcall symbols always have _ already */
        && !strchr(name, '@')
#endif
        ) {
        buf[0] = '_';
        pstrcpy(buf + 1, حجم(buf) - 1, name);
        name = buf;
    }
    sym_index = find_elf_sym(s1->symtab, name);
    sym = &((ElfW(Sym) *)s1->symtab->data)[sym_index];
    ܐܢ (!sym_index || sym->st_shndx == SHN_UNDEF) {
        ܐܢ (err)
            tcc_error_noabort("%s not defined", name);
        ܦܢܐ (addr_t)-1;
    }
    ܦܢܐ sym->st_value;
}

/* return elf symbol value */
LIBTCCAPI فراغ *tcc_get_symbol(TCCState *s, ثابت حرف *name)
{
    addr_t addr = get_sym_addr(s, name, 0, 1);
    ܦܢܐ addr == -1 ? عدم : (فراغ*)(uintptr_t)addr;
}

LIBTCCAPI صحيح tcc_add_symbol(TCCState *s1, ثابت حرف *name, ثابت فراغ *val)
{
#ifdef TCC_TARGET_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s1, 0, name, (uintptr_t)val);
#ܐܚܪܢܐ
    حرف buf[256];
    ܐܢ (s1->leading_underscore) {
        buf[0] = '_';
        pstrcpy(buf + 1, حجم(buf) - 1, name);
        name = buf;
    }
    set_global_sym(s1, name, عدم, (addr_t)(uintptr_t)val); /* NULL: SHN_ABS */
#endif
    ܦܢܐ 0;
}

/* list elf symbol names and values */
ST_FUNC فراغ list_elf_symbols(TCCState *s, فراغ *ctx,
    فراغ (*symbol_cb)(فراغ *ctx, ثابت حرف *name, ثابت فراغ *val))
{
    ElfW(Sym) *sym;
    Section *symtab;
    صحيح sym_index, end_sym;
    ثابت حرف *name;
    unsigned حرف sym_vis, sym_bind;

    symtab = s->symtab;
    end_sym = symtab->data_offset / حجم (ElfSym);
    لكل (sym_index = 0; sym_index < end_sym; ++sym_index) {
        sym = &((ElfW(Sym) *)symtab->data)[sym_index];
        ܐܢ (sym->st_value) {
            name = (حرف *) symtab->link->data + sym->st_name;
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            sym_vis = ELFW(ST_VISIBILITY)(sym->st_other);
            ܐܢ (sym_bind == STB_GLOBAL && sym_vis == STV_DEFAULT)
                symbol_cb(ctx, name, (فراغ*)(uintptr_t)sym->st_value);
        }
    }
}

/* list elf symbol names and values */
LIBTCCAPI فراغ tcc_list_symbols(TCCState *s, فراغ *ctx,
    فراغ (*symbol_cb)(فراغ *ctx, ثابت حرف *name, ثابت فراغ *val))
{
    list_elf_symbols(s, ctx, symbol_cb);
}

#ifndef ELF_OBJ_ONLY
ساكن فراغ
version_add (TCCState *s1)
{
    صحيح i;
    ElfW(Sym) *sym;
    ElfW(Verneed) *vn = عدم;
    Section *symtab;
    صحيح sym_index, end_sym, nb_versions = 2, nb_entries = 0;
    ElfW(Half) *versym;
    ثابت حرف *name;

    ܐܢ (0 == nb_sym_versions)
        ܦܢܐ;
    versym_section = new_section(s1, ".gnu.version", SHT_GNU_versym, SHF_ALLOC);
    versym_section->sh_entsize = حجم(ElfW(Half));
    versym_section->link = s1->dynsym;

    /* add needed symbols */
    symtab = s1->dynsym;
    end_sym = symtab->data_offset / حجم (ElfSym);
    versym = section_ptr_add(versym_section, end_sym * حجم(ElfW(Half)));
    لكل (sym_index = 1; sym_index < end_sym; ++sym_index) {
        صحيح dllindex, verndx;
        sym = &((ElfW(Sym) *)symtab->data)[sym_index];
        name = (حرف *) symtab->link->data + sym->st_name;
        dllindex = find_elf_sym(s1->dynsymtab_section, name);
        verndx = (dllindex && dllindex < nb_sym_to_version)
                 ? sym_to_version[dllindex] : -1;
        ܐܢ (verndx >= 0
            /* XXX: on android, clang refuses to link with a libtcc.so made by tcc
               when defined symbols have a version > 1 or when the version is '0'.
               Whereas version '1' for example for 'signal' in an exe defeats
               bcheck's signal_redir. */
            && (sym->st_shndx == SHN_UNDEF || (s1->output_type & TCC_OUTPUT_EXE))
            ) {
            ܐܢ (!sym_versions[verndx].out_index)
              sym_versions[verndx].out_index = nb_versions++;
            versym[sym_index] = sym_versions[verndx].out_index;
        } ܐܚܪܢܐ {
            versym[sym_index] = 1; /* (*global*) */
        }
        //printf("SYM %d %s\n", versym[sym_index], name);
    }
    /* generate verneed section, but not when it will be empty.  Some
       dynamic linkers look at their contents even when DTVERNEEDNUM and
       section size is zero.  */
    ܐܢ (nb_versions > 2) {
        verneed_section = new_section(s1, ".gnu.version_r",
                                      SHT_GNU_verneed, SHF_ALLOC);
        verneed_section->link = s1->dynsym->link;
        لكل (i = nb_sym_versions; i-- > 0;) {
            بنية sym_version *sv = &sym_versions[i];
            صحيح n_same_libs = 0, prev;
            size_t vnofs;
            ElfW(Vernaux) *vna = 0;
            ܐܢ (sv->out_index < 1)
              استمر;

            /* make sure that a DT_NEEDED tag is put */
            /* abitest-tcc fails on older i386-linux with "ld-linux.so.2" DT_NEEDED
               ret_int_test... Inconsistency detected by ld.so: dl-minimal.c: 148:
               realloc: Assertion `ptr == alloc_last_block' failed! */
            ܐܢ (strcmp(sv->lib, "ld-linux.so.2"))
                tcc_add_dllref(s1, sv->lib, 0);

            vnofs = section_add(verneed_section, حجم(*vn), 1);
            vn = (ElfW(Verneed)*)(verneed_section->data + vnofs);
            vn->vn_version = 1;
            vn->vn_file = put_elf_str(verneed_section->link, sv->lib);
            vn->vn_aux = حجم (*vn);
            ܥܒܕ {
                prev = sv->prev_same_lib;
                ܐܢ (sv->out_index > 0) {
                    vna = section_ptr_add(verneed_section, حجم(*vna));
                    vna->vna_hash = elf_hash ((ثابت unsigned حرف *)sv->version);
                    vna->vna_flags = 0;
                    vna->vna_other = sv->out_index;
                    sv->out_index = -2;
                    vna->vna_name = put_elf_str(verneed_section->link, sv->version);
                    vna->vna_next = حجم (*vna);
                    //printf("LIB %d %s %s\n", vna->vna_other, sv->lib, verneed_section->link->data + vna->vna_name);
                    n_same_libs++;
                }
                ܐܢ (prev >= 0)
                  sv = &sym_versions[prev];
            } ܟܡܐ(prev >= 0);
            vna->vna_next = 0;
            vn = (ElfW(Verneed)*)(verneed_section->data + vnofs);
            vn->vn_cnt = n_same_libs;
            vn->vn_next = حجم(*vn) + n_same_libs * حجم(*vna);
            nb_entries++;
        }
        ܐܢ (vn)
          vn->vn_next = 0;
        verneed_section->sh_info = nb_entries;
    }
    dt_verneednum = nb_entries;
}
#endif /* ndef ELF_OBJ_ONLY */

/* catch .tbss also */
ساكن صحيح IS_BSS(TCCState *s1, صحيح ndx)
{
    ܦܢܐ ndx == SHN_COMMON
     || (ndx < s1->nb_sections
         && s1->sections[ndx]->sh_type == SHT_NOBITS);
}

/* add an elf symbol : check if it is already defined and patch
   it. Return symbol index. NOTE that sh_num can be SHN_UNDEF. */
ST_FUNC صحيح set_elf_sym(Section *s, addr_t value, unsigned long size,
                       صحيح info, صحيح other, صحيح shndx, ثابت حرف *name)
{
    TCCState *s1 = s->s1;
    ElfW(Sym) *esym;
    صحيح sym_bind, sym_index, sym_type, esym_bind;
    unsigned حرف sym_vis, esym_vis, new_vis;

    sym_bind = ELFW(ST_BIND)(info);
    sym_type = ELFW(ST_TYPE)(info);
    sym_vis = ELFW(ST_VISIBILITY)(other);

    ܐܢ (sym_bind != STB_LOCAL) {
        /* we search global or weak symbols */
        sym_index = find_elf_sym(s, name);
        ܐܢ (!sym_index)
            اذهب do_def;
        esym = &((ElfW(Sym) *)s->data)[sym_index];
        ܐܢ (esym->st_value == value && esym->st_size == size && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            ܦܢܐ sym_index;
        ܐܢ (esym->st_shndx != SHN_UNDEF) {
            esym_bind = ELFW(ST_BIND)(esym->st_info);
            /* propagate the most constraining visibility */
            /* STV_DEFAULT(0)<STV_PROTECTED(3)<STV_HIDDEN(2)<STV_INTERNAL(1) */
            esym_vis = ELFW(ST_VISIBILITY)(esym->st_other);
            ܐܢ (esym_vis == STV_DEFAULT) {
                new_vis = sym_vis;
            } ܐܚܪܢܐ ܐܢ (sym_vis == STV_DEFAULT) {
                new_vis = esym_vis;
            } ܐܚܪܢܐ {
                new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
            }
            esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
                             | new_vis;
            ܐܢ (shndx == SHN_UNDEF) {
                /* ignore adding of undefined symbol if the
                   corresponding symbol is already defined */
            } ܐܚܪܢܐ ܐܢ (sym_bind == STB_GLOBAL && esym_bind == STB_WEAK) {
                /* global overrides weak, so patch */
                اذهب do_patch;
            } ܐܚܪܢܐ ܐܢ (sym_bind == STB_WEAK && esym_bind == STB_GLOBAL) {
                /* weak is ignored if already global */
            } ܐܚܪܢܐ ܐܢ (sym_bind == STB_WEAK && esym_bind == STB_WEAK) {
                /* keep first-found weak definition, ignore subsequents */
            } ܐܚܪܢܐ ܐܢ (sym_vis == STV_HIDDEN || sym_vis == STV_INTERNAL) {
                /* ignore hidden symbols after */
            } ܐܚܪܢܐ ܐܢ (s->sh_flags & SHF_DYNSYM) {
                /* we accept that two DLL define the same symbol */
            } ܐܚܪܢܐ ܐܢ (!IS_BSS(s1, shndx) && IS_BSS(s1, esym->st_shndx)) {
                /* data symbol gets precedence over common/bss */
                اذهب do_patch;
            } ܐܚܪܢܐ ܐܢ (IS_BSS(s1, shndx)) {
                /* data symbol keeps precedence over common/bss */
	    } ܐܚܪܢܐ ܐܢ (esym->st_other & ST_ASM_SET) {
		/* If the existing symbol came from an asm .set
		   we can override.  */
		اذهب do_patch;
            } ܐܚܪܢܐ {
#ܐܢ 0
                printf("new_bind=%x new_shndx=%x new_vis=%x old_bind=%x old_shndx=%x old_vis=%x\n",
                       sym_bind, shndx, new_vis, esym_bind, esym->st_shndx, esym_vis);
#endif
                tcc_error_noabort("link symbol '%s' defined twice", name);
            }
        } ܐܚܪܢܐ {
            esym->st_other = other;
        do_patch:
            esym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
            esym->st_shndx = shndx;
            esym->st_value = value;
            esym->st_size = size;
        }
    } ܐܚܪܢܐ {
    do_def:
        sym_index = put_elf_sym(s, value, size,
                                ELFW(ST_INFO)(sym_bind, sym_type), other,
                                shndx, name);
    }
    ܦܢܐ sym_index;
}

/* put relocation */
ST_FUNC فراغ put_elf_reloca(Section *symtab, Section *s, unsigned long offset,
                            صحيح type, صحيح symbol, addr_t addend)
{
    TCCState *s1 = s->s1;
    حرف buf[256];
    Section *sr;
    ElfW_Rel *rel;

    sr = s->reloc;
    ܐܢ (!sr) {
        /* if no relocation section, create it */
        snprintf(buf, حجم(buf), REL_SECTION_FMT, s->name);
        /* if the symtab is allocated, then we consider the relocation
           are also */
        sr = new_section(s->s1, buf, SHT_RELX, symtab->sh_flags);
        sr->sh_entsize = حجم(ElfW_Rel);
        sr->link = symtab;
        sr->sh_info = s->sh_num;
        s->reloc = sr;
    }
    rel = section_ptr_add(sr, حجم(ElfW_Rel));
    rel->r_offset = offset;
    rel->r_info = ELFW(R_INFO)(symbol, type);
#ܐܢ SHT_RELX == SHT_RELA
    rel->r_addend = addend;
#endif
    ܐܢ (SHT_RELX != SHT_RELA && addend)
        tcc_error_noabort("non-zero addend on REL architecture");
}

ST_FUNC فراغ put_elf_reloc(Section *symtab, Section *s, unsigned long offset,
                           صحيح type, صحيح symbol)
{
    put_elf_reloca(symtab, s, offset, type, symbol, 0);
}

ST_FUNC بنية sym_attr *get_sym_attr(TCCState *s1, صحيح index, صحيح alloc)
{
    صحيح n;
    بنية sym_attr *tab;

    ܐܢ (index >= s1->nb_sym_attrs) {
        ܐܢ (!alloc)
            ܦܢܐ s1->sym_attrs;
        /* find immediately bigger power of 2 and reallocate array */
        n = 1;
        ܟܡܐ (index >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * حجم(*s1->sym_attrs));
        s1->sym_attrs = tab;
        memset(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * حجم(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    ܦܢܐ &s1->sym_attrs[index];
}

ساكن فراغ update_relocs(TCCState *s1, Section *s, صحيح *old_to_new_syms, صحيح first_sym)
{
    صحيح i, type, sym_index;
    Section *sr;
    ElfW_Rel *rel;

    لكل(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        ܐܢ (sr->sh_type == SHT_RELX && sr->link == s) {
            for_each_elem(sr, 0, rel, ElfW_Rel) {
                sym_index = ELFW(R_SYM)(rel->r_info);
                type = ELFW(R_TYPE)(rel->r_info);
                ܐܢ ((sym_index -= first_sym) < 0)
                    استمر; /* zero sym_index in reloc (can happen with asm) */
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
ساكن فراغ sort_syms(TCCState *s1, Section *s)
{
    صحيح *old_to_new_syms;
    ElfW(Sym) *new_syms;
    صحيح nb_syms, i;
    ElfW(Sym) *p, *q;

    nb_syms = s->data_offset / حجم(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * حجم(ElfW(Sym)));
    old_to_new_syms = tcc_malloc(nb_syms * حجم(صحيح));

    /* first pass for local symbols */
    p = (ElfW(Sym) *)s->data;
    q = new_syms;
    لكل(i = 0; i < nb_syms; i++) {
        ܐܢ (ELFW(ST_BIND)(p->st_info) == STB_LOCAL) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    /* save the number of local symbols in section header */
    ܐܢ( s->sh_size )    /* this 'if' makes IDA happy */
        s->sh_info = q - new_syms;

    /* then second pass for non local symbols */
    p = (ElfW(Sym) *)s->data;
    لكل(i = 0; i < nb_syms; i++) {
        ܐܢ (ELFW(ST_BIND)(p->st_info) != STB_LOCAL) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }

    /* we copy the new symbols to the old */
    memcpy(s->data, new_syms, nb_syms * حجم(ElfW(Sym)));
    tcc_free(new_syms);

    update_relocs(s1, s, old_to_new_syms, 0);
    tcc_free(old_to_new_syms);
}

#ifndef ELF_OBJ_ONLY
/* See: https://flapenguin.me/elf-dt-gnu-hash */
#define	ELFCLASS_BITS (PTR_SIZE * 8)

ساكن Section *create_gnu_hash(TCCState *s1)
{
    صحيح nb_syms, i, ndef, nbuckets, symoffset, bloom_size, bloom_shift;
    ElfW(Sym) *p;
    Section *gnu_hash;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr;

    gnu_hash = new_section(s1, ".gnu.hash", SHT_GNU_HASH, SHF_ALLOC);
    gnu_hash->link = dynsym->hash->link;

    nb_syms = dynsym->data_offset / حجم(ElfW(Sym));

    /* count def symbols */
    ndef = 0;
    p = (ElfW(Sym) *)dynsym->data;
    لكل(i = 0; i < nb_syms; i++, p++)
        ndef += p->st_shndx != SHN_UNDEF;

    /* calculate gnu hash sizes and fill header */
    nbuckets = ndef / 4 + 1;
    symoffset = nb_syms - ndef;
    bloom_shift = PTR_SIZE == 8 ? 6 : 5;
    bloom_size = 1; /* must be power of two */
    ܟܡܐ (ndef >= bloom_size * (1 << (bloom_shift - 3)))
	bloom_size *= 2;
    ptr = section_ptr_add(gnu_hash, 4 * 4 +
				    PTR_SIZE * bloom_size +
				    nbuckets * 4 +
				    ndef * 4);
    ptr[0] = nbuckets;
    ptr[1] = symoffset;
    ptr[2] = bloom_size;
    ptr[3] = bloom_shift;
    ܦܢܐ gnu_hash;
}

ساكن Elf32_Word elf_gnu_hash (ثابت unsigned حرف *name)
{
    Elf32_Word h = 5381;
    unsigned حرف c;

    ܟܡܐ ((c = *name++))
        h = h * 33 + c;
    ܦܢܐ h;
}

ساكن فراغ update_gnu_hash(TCCState *s1, Section *gnu_hash)
{
    صحيح *old_to_new_syms;
    ElfW(Sym) *new_syms;
    صحيح nb_syms, i, nbuckets, bloom_size, bloom_shift;
    ElfW(Sym) *p, *q;
    Section *vs;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr, *buckets, *chain, *hash;
    unsigned صحيح *nextbuck;
    addr_t *bloom;
    unsigned حرف *strtab;
    بنية { صحيح first, last; } *buck;

    strtab = dynsym->link->data;
    nb_syms = dynsym->data_offset / حجم(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * حجم(ElfW(Sym)));
    old_to_new_syms = tcc_malloc(nb_syms * حجم(صحيح));
    hash = tcc_malloc(nb_syms * حجم(Elf32_Word));
    nextbuck = tcc_malloc(nb_syms * حجم(صحيح));

    /* calculate hashes and copy undefs */
    p = (ElfW(Sym) *)dynsym->data;
    q = new_syms;
    لكل(i = 0; i < nb_syms; i++, p++) {
        ܐܢ (p->st_shndx == SHN_UNDEF) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
	ܐܚܪܢܐ
	    hash[i] = elf_gnu_hash(strtab + p->st_name);
    }

    ptr = (Elf32_Word *) gnu_hash->data;
    nbuckets = ptr[0];
    bloom_size = ptr[2];
    bloom_shift = ptr[3];
    bloom = (addr_t *) (فراغ *) &ptr[4];
    buckets = (Elf32_Word*) (فراغ *) &bloom[bloom_size];
    chain = &buckets[nbuckets];
    buck = tcc_malloc(nbuckets * حجم(*buck));

    ܐܢ (gnu_hash->data_offset != 4 * 4 +
				 PTR_SIZE * bloom_size +
				 nbuckets * 4 +
				 (nb_syms - (q - new_syms)) * 4)
	tcc_error_noabort ("gnu_hash size incorrect");

    /* find buckets */
    لكل(i = 0; i < nbuckets; i++)
	buck[i].first = -1;

    p = (ElfW(Sym) *)dynsym->data;
    لكل(i = 0; i < nb_syms; i++, p++)
        ܐܢ (p->st_shndx != SHN_UNDEF) {
	    صحيح bucket = hash[i] % nbuckets;

	    ܐܢ (buck[bucket].first == -1)
		buck[bucket].first = buck[bucket].last = i;
	    ܐܚܪܢܐ {
		nextbuck[buck[bucket].last] = i;
		buck[bucket].last = i;
	    }
	}

    /* fill buckets/chains/bloom and sort symbols */
    p = (ElfW(Sym) *)dynsym->data;
    لكل(i = 0; i < nbuckets; i++) {
	صحيح cur = buck[i].first;

	ܐܢ (cur != -1) {
	    buckets[i] = q - new_syms;
	    لكل (;;) {
                old_to_new_syms[cur] = q - new_syms;
                *q++ = p[cur];
	        *chain++ = hash[cur] & ~1;
		bloom[(hash[cur] / ELFCLASS_BITS) % bloom_size] |=
		    (addr_t)1 << (hash[cur] % ELFCLASS_BITS) |
		    (addr_t)1 << ((hash[cur] >> bloom_shift) % ELFCLASS_BITS);
		ܐܢ (cur == buck[i].last)
		    اكسر;
		cur = nextbuck[cur];
	    }
	    chain[-1] |= 1;
	}
    }

    memcpy(dynsym->data, new_syms, nb_syms * حجم(ElfW(Sym)));
    tcc_free(new_syms);
    tcc_free(hash);
    tcc_free(buck);
    tcc_free(nextbuck);

    update_relocs(s1, dynsym, old_to_new_syms, 0);

    /* modify the versions */
    vs = versym_section;
    ܐܢ (vs) {
	ElfW(Half) *newver, *versym = (ElfW(Half) *)vs->data;

	ܐܢ (1/*versym*/) {
            newver = tcc_malloc(nb_syms * حجم(*newver));
	    لكل (i = 0; i < nb_syms; i++)
	        newver[old_to_new_syms[i]] = versym[i];
	    memcpy(vs->data, newver, nb_syms * حجم(*newver));
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
ST_FUNC فراغ relocate_syms(TCCState *s1, Section *symtab, صحيح do_resolve)
{
    ElfW(Sym) *sym;
    صحيح sym_bind, sh_num;
    ثابت حرف *name;

    for_each_elem(symtab, 1, sym, ElfW(Sym)) {
        sh_num = sym->st_shndx;
        ܐܢ (sh_num == SHN_UNDEF) {
            ܐܢ (do_resolve == 2) /* relocating dynsym */
                استمر;
            name = (حرف *) s1->symtab->link->data + sym->st_name;
            /* Use ld.so to resolve symbol for us (for tcc -run) */
            ܐܢ (do_resolve) {
#ܐܢ defined TCC_IS_NATIVE && !defined TCC_TARGET_PE
                /* dlsym() needs the undecorated name.  */
                ثابت حرف *name_ud = &name[s1->leading_underscore];
                فراغ *addr = عدم;
                ܐܢ (!s1->nostdlib)
                    addr = dlsym(RTLD_DEFAULT, name_ud);
		ܐܢ (addr == عدم) {
		    صحيح i;
		    لكل (i = 0; i < s1->nb_loaded_dlls; i++)
                        ܐܢ ((addr = dlsym(s1->loaded_dlls[i]->handle, name_ud)))
			    اكسر;
		}
                ܐܢ (addr) {
                    sym->st_value = (addr_t) addr;
#ifdef DEBUG_RELOC
		    printf ("relocate_sym: %s -> 0x%lx\n", name, sym->st_value);
#endif
                    اذهب found;
                }
#endif
            /* if dynamic symbol exist, it will be used in relocate_section */
            } ܐܚܪܢܐ ܐܢ (s1->dynsym && find_elf_sym(s1->dynsym, name))
                اذهب found;
            /* XXX: _fp_hw seems to be part of the ABI, so we ignore
               it */
            ܐܢ (!strcmp(name, "_fp_hw"))
                اذهب found;
            /* only weak symbols are accepted to be undefined. Their
               value is zero */
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            ܐܢ (sym_bind == STB_WEAK)
                sym->st_value = 0;
            ܐܚܪܢܐ
                tcc_error_noabort("unresolved reference to '%s'", name);

        } ܐܚܪܢܐ ܐܢ (sh_num < SHN_LORESERVE) {
            /* add section base */
            sym->st_value += s1->sections[sym->st_shndx]->sh_addr;
        }
    found: ;
    }
}

/* relocate a given section (CPU dependent) by applying the relocations
   in the associated relocation section */
ساكن فراغ relocate_section(TCCState *s1, Section *s, Section *sr)
{
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    صحيح type, sym_index;
    unsigned حرف *ptr;
    addr_t tgt, addr;
    صحيح is_dwarf = s->sh_num >= s1->dwlo && s->sh_num < s1->dwhi;

    qrel = (ElfW_Rel *)sr->data;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
	ܐܢ (s->data == عدم) /* bss */
	    استمر;
        ptr = s->data + rel->r_offset;
        sym_index = ELFW(R_SYM)(rel->r_info);
        sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
        type = ELFW(R_TYPE)(rel->r_info);
        tgt = sym->st_value;
#ܐܢ SHT_RELX == SHT_RELA
        tgt += rel->r_addend;
#endif
        ܐܢ (is_dwarf && type == R_DATA_32DW
            && sym->st_shndx >= s1->dwlo && sym->st_shndx < s1->dwhi) {
            /* dwarf section relocation to each other */
            add32le(ptr, tgt - s1->sections[sym->st_shndx]->sh_addr);
            استمر;
        }
        addr = s->sh_addr + rel->r_offset;
        relocate(s1, rel, type, ptr, addr, tgt);
    }

#ifndef ELF_OBJ_ONLY
    /* if the relocation is allocated, we change its symbol table */
    ܐܢ (sr->sh_flags & SHF_ALLOC) {
        sr->link = s1->dynsym;
        ܐܢ (s1->output_type & TCC_OUTPUT_DYN) {
            size_t r = (uint8_t*)qrel - sr->data;
            ܐܢ (حجم ((Stab_Sym*)0)->n_value < PTR_SIZE
                && 0 == strcmp(s->name, ".stab"))
                r = 0; /* cannot apply 64bit relocation to 32bit value */
            sr->data_offset = sr->sh_size = r;
#ifdef CONFIG_TCC_PIE
            ܐܢ (r && (s->sh_flags & SHF_EXECINSTR))
                tcc_warning("%d relocations to %s", (unsigned)(r / حجم *qrel), s->name);
#endif
        }
    }
#endif

#ifdef TCC_TARGET_RISCV64
    dynarray_reset(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries);
#endif
}

/* relocate all sections */
ST_FUNC فراغ relocate_sections(TCCState *s1)
{
    صحيح i;
    Section *s, *sr;

    لكل (i = 1; i < s1->nb_sections; ++i) {
        sr = s1->sections[i];
        ܐܢ (sr->sh_type != SHT_RELX)
            استمر;
        s = s1->sections[sr->sh_info];
#ifndef TCC_TARGET_MACHO
        ܐܢ (s != s1->got
            || s1->static_link
            || s1->output_type == TCC_OUTPUT_MEMORY)
#endif
        {
            relocate_section(s1, s, sr);
        }
#ifndef ELF_OBJ_ONLY
        ܐܢ (sr->sh_flags & SHF_ALLOC) {
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
ساكن صحيح prepare_dynamic_rel(TCCState *s1, Section *sr)
{
    صحيح count = 0;
#ܐܢ defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || \
    defined(TCC_TARGET_ARM) || defined(TCC_TARGET_ARM64) || \
    defined(TCC_TARGET_RISCV64)
    ElfW_Rel *rel;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
        صحيح sym_index = ELFW(R_SYM)(rel->r_info);
        صحيح type = ELFW(R_TYPE)(rel->r_info);
        بدل(type) {
#ܐܢ defined(TCC_TARGET_I386)
        حالة R_386_32:
            ܐܢ (!get_sym_attr(s1, sym_index, 0)->dyn_index
                && ((ElfW(Sym)*)symtab_section->data + sym_index)->st_shndx == SHN_UNDEF) {
                /* don't fixup unresolved (weak) symbols */
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_RELATIVE);
                اكسر;
            }
#وإلاإذا defined(TCC_TARGET_X86_64)
        حالة R_X86_64_32:
        حالة R_X86_64_32S:
        حالة R_X86_64_64:
#وإلاإذا defined(TCC_TARGET_ARM)
        حالة R_ARM_ABS32:
        حالة R_ARM_TARGET1:
#وإلاإذا defined(TCC_TARGET_ARM64)
        حالة R_AARCH64_ABS32:
        حالة R_AARCH64_ABS64:
#وإلاإذا defined(TCC_TARGET_RISCV64)
        حالة R_RISCV_32:
        حالة R_RISCV_64:
#endif
            count++;
            اكسر;
#ܐܢ defined(TCC_TARGET_I386)
        حالة R_386_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    ܐܢ (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_PLT32);
	        اكسر;
	    }
	}
#وإلاإذا defined(TCC_TARGET_X86_64)
        حالة R_X86_64_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    ܐܢ (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_index, R_X86_64_PLT32);
	        اكسر;
	    }
	}
#وإلاإذا defined(TCC_TARGET_ARM64)
        حالة R_AARCH64_PREL32:
#endif
            ܐܢ (s1->output_type != TCC_OUTPUT_DLL)
                اكسر;
            ܐܢ (get_sym_attr(s1, sym_index, 0)->dyn_index)
                count++;
            اكسر;
        افتراضي:
            اكسر;
        }
    }
#endif
    ܦܢܐ count;
}
#endif

#ifdef NEED_BUILD_GOT
ساكن صحيح build_got(TCCState *s1)
{
    /* if no got, then create it */
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    s1->got->sh_entsize = 4;
    /* keep space for _DYNAMIC pointer and two dummy got entries */
    section_ptr_add(s1->got, 3 * PTR_SIZE);
    ܦܢܐ set_elf_sym(symtab_section, 0, 0, ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
        0, s1->got->sh_num, "_GLOBAL_OFFSET_TABLE_");
}

/* Create a GOT and (for function call) a PLT entry corresponding to a symbol
   in s1->symtab. When creating the dynamic symbol table entry for the GOT
   relocation, use 'size' and 'info' for the corresponding symbol metadata.
   Returns the offset of the GOT or (if any) PLT entry. */
ساكن بنية sym_attr * put_got_entry(TCCState *s1, صحيح dyn_reloc_type,
                                       صحيح sym_index)
{
    صحيح need_plt_entry;
    ثابت حرف *name;
    ElfW(Sym) *sym;
    بنية sym_attr *attr;
    unsigned got_offset;
    حرف plt_name[200];
    صحيح len;
    Section *s_rel;

    need_plt_entry = (dyn_reloc_type == R_JMP_SLOT);
    attr = get_sym_attr(s1, sym_index, 1);

    /* In case a function is both called and its address taken 2 GOT entries
       are created, one for taking the address (GOT) and the other for the PLT
       entry (PLTGOT).  */
    ܐܢ (need_plt_entry ? attr->plt_offset : attr->got_offset)
        ܦܢܐ attr;

    s_rel = s1->got;
    ܐܢ (need_plt_entry) {
        ܐܢ (!s1->plt) {
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
    name = (حرف *) symtab_section->link->data + sym->st_name;
    //printf("sym %d %s\n", need_plt_entry, name);

    ܐܢ (s1->dynsym) {
	ܐܢ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
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
	} ܐܚܪܢܐ {
	    ܐܢ (0 == attr->dyn_index)
                attr->dyn_index = set_elf_sym(s1->dynsym, sym->st_value,
                                              sym->st_size, sym->st_info, 0,
                                              sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s_rel, got_offset, dyn_reloc_type,
			  attr->dyn_index);
	}
    } ܐܚܪܢܐ {
        put_elf_reloc(symtab_section, s1->got, got_offset, dyn_reloc_type,
                      sym_index);
    }

    ܐܢ (need_plt_entry) {
        attr->plt_offset = create_plt_entry(s1, got_offset, attr);

        /* create a symbol 'sym@plt' for the PLT jump vector */
        len = strlen(name);
        ܐܢ (len > حجم plt_name - 5)
            len = حجم plt_name - 5;
        memcpy(plt_name, name, len);
        strcpy(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_offset, 0,
            ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0, s1->plt->sh_num, plt_name);
    } ܐܚܪܢܐ {
        attr->got_offset = got_offset;
    }

    ܦܢܐ attr;
}

/* build GOT and PLT entries */
/* Two passes because R_JMP_SLOT should become first. Some targets
   (arm, arm64) do not allow mixing R_JMP_SLOT and R_GLOB_DAT. */
ST_FUNC فراغ build_got_entries(TCCState *s1, صحيح got_sym)
{
    Section *s;
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    صحيح i, type, gotplt_entry, reloc_type, sym_index;
    بنية sym_attr *attr;
    صحيح pass = 0;
redo:
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ܐܢ (s->sh_type != SHT_RELX)
            استمر;
        /* no need to handle got relocations */
        ܐܢ (s->link != symtab_section)
            استمر;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_entry = gotplt_entry_type(type);
            ܐܢ (gotplt_entry == -1) {
                tcc_error_noabort ("Unknown relocation type for got: %d", type);
                استمر;
            }
            sym_index = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];

            ܐܢ (gotplt_entry == NO_GOTPLT_ENTRY) {
                استمر;
            }

            /* Automatically create PLT/GOT [entry] if it is an undefined
	       reference (resolved at runtime), or the symbol is absolute,
	       probably created by tcc_add_symbol, and thus on 64-bit
	       targets might be too far from application code.  */
            ܐܢ (gotplt_entry == AUTO_GOTPLT_ENTRY) {
                ܐܢ (sym->st_shndx == SHN_UNDEF) {
                    ElfW(Sym) *esym;
		    صحيح dynindex;
                    ܐܢ (!PCRELATIVE_DLLPLT
                        && (s1->output_type & TCC_OUTPUT_DYN))
                        استمر;
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
		    ܐܢ (s1->dynsym) {
			/* dynsym isn't set for -run :-/  */
			dynindex = get_sym_attr(s1, sym_index, 0)->dyn_index;
			esym = (ElfW(Sym) *)s1->dynsym->data + dynindex;
			ܐܢ (dynindex
			    && (ELFW(ST_TYPE)(esym->st_info) == STT_FUNC
				|| (ELFW(ST_TYPE)(esym->st_info) == STT_NOTYPE
				    && ELFW(ST_TYPE)(sym->st_info) == STT_FUNC)))
			    اذهب jmp_slot;
		    }
                } ܐܚܪܢܐ ܐܢ (sym->st_shndx == SHN_ABS) {
                    ܐܢ (sym->st_value == 0) /* from tcc_add_btstub() */
                        استمر;
#ifndef TCC_TARGET_ARM
                    ܐܢ (PTR_SIZE != 8)
                        استمر;
#endif
                    /* from tcc_add_symbol(): on 64 bit platforms these
                       need to go through .got */
                } ܐܚܪܢܐ
                    استمر;
            }

#ifdef TCC_TARGET_I386
            ܐܢ ((type == R_386_PLT32 || type == R_386_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		ܐܢ (pass != 0)
		    استمر;
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_PC32);
                استمر;
            }
#endif
#ifdef TCC_TARGET_X86_64
            ܐܢ ((type == R_X86_64_PLT32 || type == R_X86_64_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		ܐܢ (pass != 0)
		    استمر;
                rel->r_info = ELFW(R_INFO)(sym_index, R_X86_64_PC32);
                استمر;
            }
#endif
            reloc_type = code_reloc(type);
            ܐܢ (reloc_type == -1) {
                tcc_error_noabort ("Unknown relocation type: %d", type);
                استمر;
            }

            ܐܢ (reloc_type != 0) {
        jmp_slot:
	        ܐܢ (pass != 0)
                    استمر;
                reloc_type = R_JMP_SLOT;
            } ܐܚܪܢܐ {
	        ܐܢ (pass != 1)
                    استمر;
                reloc_type = R_GLOB_DAT;
            }

            ܐܢ (!s1->got)
                got_sym = build_got(s1);

            ܐܢ (gotplt_entry == BUILD_GOT_ONLY)
                استمر;

            attr = put_got_entry(s1, reloc_type, sym_index);

            ܐܢ (reloc_type == R_JMP_SLOT)
                rel->r_info = ELFW(R_INFO)(attr->plt_sym, type);
        }
    }
    ܐܢ (++pass < 2)
        اذهب redo;
    /* .rel.plt refers to .got actually */
    ܐܢ (s1->plt && s1->plt->reloc)
        s1->plt->reloc->sh_info = s1->got->sh_num;
    ܐܢ (got_sym) /* set size */
        ((ElfW(Sym)*)symtab_section->data)[got_sym].st_size = s1->got->data_offset;
}
#endif /* def NEED_BUILD_GOT */

ST_FUNC صحيح set_global_sym(TCCState *s1, ثابت حرف *name, Section *sec, addr_t offs)
{
    صحيح shn = sec ? sec->sh_num : offs || !name ? SHN_ABS : SHN_UNDEF;
    ܐܢ (sec && offs == -1)
        offs = sec->data_offset;
    ܦܢܐ set_elf_sym(symtab_section, offs, 0,
        ELFW(ST_INFO)(name ? STB_GLOBAL : STB_LOCAL, STT_NOTYPE), 0, shn, name);
}

ساكن فراغ add_init_array_defines(TCCState *s1, ثابت حرف *section_name)
{
    Section *s;
    addr_t end_offset;
    حرف buf[1024];
    s = have_section(s1, section_name);
    ܐܢ (!s || !(s->sh_flags & SHF_ALLOC)) {
        end_offset = 0;
        s = text_section;
    } ܐܚܪܢܐ {
        end_offset = s->data_offset;
    }
    snprintf(buf, حجم(buf), "__%s_start", section_name + 1);
    set_global_sym(s1, buf, s, 0);
    snprintf(buf, حجم(buf), "__%s_end", section_name + 1);
    set_global_sym(s1, buf, s, end_offset);
}

ST_FUNC فراغ add_array (TCCState *s1, ثابت حرف *sec, صحيح c)
{
    Section *s;
    s = find_section(s1, sec);
    s->sh_flags = shf_RELRO;
    s->sh_type = sec[1] == 'i' ? SHT_INIT_ARRAY : SHT_FINI_ARRAY;
    put_elf_reloc (s1->symtab, s, s->data_offset, R_DATA_PTR, c);
    section_ptr_add(s, PTR_SIZE);
}

#ifdef CONFIG_TCC_BCHECK
ST_FUNC فراغ tcc_add_bcheck(TCCState *s1)
{
    ܐܢ (0 == s1->do_bounds_check)
        ܦܢܐ;
    section_ptr_add(bounds_section, حجم(addr_t));
}
#endif

/* set symbol to STB_LOCAL and resolve. The point is to not export it as
   a dynamic symbol to allow so's to have one each with a different value. */
ساكن فراغ set_local_sym(TCCState *s1, ثابت حرف *name, Section *s, صحيح offset)
{
    صحيح c = find_elf_sym(s1->symtab, name);
    ܐܢ (c) {
        ElfW(Sym) *esym = (ElfW(Sym)*)s1->symtab->data + c;
        esym->st_info = ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE);
        esym->st_value = offset;
        esym->st_shndx = s->sh_num;
    }
}

/* avoid generating debug/test_coverage code for stub functions */
ساكن فراغ tcc_compile_string_no_debug(TCCState *s, ثابت حرف *str)
{
    صحيح save_do_debug = s->do_debug;
    صحيح save_test_coverage = s->test_coverage;

    s->do_debug = 0;
    s->test_coverage = 0;
    tcc_compile_string(s, str);
    s->do_debug = save_do_debug;
    s->test_coverage = save_test_coverage;
}

#ifdef CONFIG_TCC_BACKTRACE
ساكن فراغ put_ptr(TCCState *s1, Section *s, صحيح offs)
{
    صحيح c;
    c = set_global_sym(s1, عدم, s, offs);
    s = data_section;
    put_elf_reloc (s1->symtab, s, s->data_offset, R_DATA_PTR, c);
    section_ptr_add(s, PTR_SIZE);
}

ST_FUNC فراغ tcc_add_btstub(TCCState *s1)
{
    Section *s;
    صحيح n, o, *p;
    CString cstr;
    ثابت حرف *__rt_info = &"___rt_info"[!s1->leading_underscore];

    s = data_section;
    /* Align to PTR_SIZE */
    section_add(s, 0, PTR_SIZE);
    o = s->data_offset;
    /* create a struct rt_context (see tccrun.c) */
    ܐܢ (s1->dwarf) {
        put_ptr(s1, dwarf_line_section, 0);
        put_ptr(s1, dwarf_line_section, -1);
	ܐܢ (s1->dwarf >= 5)
            put_ptr(s1, dwarf_line_str_section, 0);
	ܐܚܪܢܐ
            put_ptr(s1, dwarf_str_section, 0);
    }
    ܐܚܪܢܐ
    {
        put_ptr(s1, stab_section, 0);
        put_ptr(s1, stab_section, -1);
        put_ptr(s1, stab_section->link, 0);
    }

    /* skip esym_start/esym_end/elf_str (not loaded) */
    section_ptr_add(s, 3 * PTR_SIZE);

    ܐܢ (s1->output_type == TCC_OUTPUT_MEMORY && 0 == s1->dwarf) {
        put_ptr(s1, text_section, 0);
    } ܐܚܪܢܐ {
        /* prog_base : local nameless symbol with offset 0 at SHN_ABS */
        put_ptr(s1, عدم, 0);
#ܐܢ defined TCC_TARGET_MACHO
        /* adjust for __PAGEZERO */
        ܐܢ (s1->dwarf == 0 && s1->output_type == TCC_OUTPUT_EXE)
            write64le(data_section->data + data_section->data_offset - PTR_SIZE,
	              (uint64_t)1 << 32);
#endif
    }
    n = 3 * PTR_SIZE;
#ifdef CONFIG_TCC_BCHECK
    ܐܢ (s1->do_bounds_check) {
        put_ptr(s1, bounds_section, 0);
        n -= PTR_SIZE;
    }
#endif
    section_ptr_add(s, n);
    p = section_ptr_add(s, 2 * حجم (صحيح));
    p[0] = s1->rt_num_callers;
    p[1] = s1->dwarf;
    // if (s->data_offset - o != 10*PTR_SIZE + 2*sizeof (int)) exit(99);

    ܐܢ (s1->output_type == TCC_OUTPUT_MEMORY) {
        set_global_sym(s1, __rt_info, s, o);
        ܦܢܐ;
    }

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern void __bt_init(),__bt_exit(),__bt_init_dll();"
        "static void *__rt_info[];"
        "__attribute__((constructor)) static void __bt_init_rt(){");
#ifdef TCC_TARGET_PE
    ܐܢ (s1->output_type == TCC_OUTPUT_DLL)
#ifdef CONFIG_TCC_BCHECK
        cstr_printf(&cstr, "__bt_init_dll(%d);", s1->do_bounds_check);
#ܐܚܪܢܐ
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

ساكن فراغ tcc_tcov_add_file(TCCState *s1, ثابت حرف *filename)
{
    CString cstr;
    فراغ *ptr;
    حرف wd[1024];

    ܐܢ (tcov_section == عدم)
        ܦܢܐ;
    section_ptr_add(tcov_section, 1);
    write32le (tcov_section->data, tcov_section->data_offset);

    cstr_new (&cstr);
    ܐܢ (filename[0] == '/')
        cstr_printf (&cstr, "%s.tcov", filename);
    ܐܚܪܢܐ {
        getcwd (wd, حجم(wd));
        cstr_printf (&cstr, "%s/%s.tcov", wd, filename);
    }
    ptr = section_ptr_add(tcov_section, cstr.size + 1);
    strcpy((حرف *)ptr, cstr.data);
    unlink((حرف *)ptr);
#ifdef _WIN32
    normalize_slashes((حرف *)ptr);
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
ST_FUNC فراغ tccelf_add_crtbegin(TCCState *s1)
{
#ܐܢ TARGETOS_OpenBSD
    ܐܢ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crt0.o");
    ܐܢ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbeginS.o");
    ܐܚܪܢܐ
        tcc_add_crt(s1, "crtbegin.o");
#وإلاإذا TARGETOS_FreeBSD || TARGETOS_NetBSD
    ܐܢ (s1->output_type != TCC_OUTPUT_DLL)
#ܐܢ TARGETOS_FreeBSD
        tcc_add_crt(s1, "crt1.o");
#ܐܚܪܢܐ
        tcc_add_crt(s1, "crt0.o");
#endif
    tcc_add_crt(s1, "crti.o");
    ܐܢ (s1->static_link)
        tcc_add_crt(s1, "crtbeginT.o");
    ܐܚܪܢܐ ܐܢ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbeginS.o");
    ܐܚܪܢܐ
        tcc_add_crt(s1, "crtbegin.o");
#وإلاإذا TARGETOS_ANDROID
    ܐܢ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbegin_so.o");
    ܐܚܪܢܐ
        tcc_add_crt(s1, "crtbegin_dynamic.o");
#ܐܚܪܢܐ
    ܐܢ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crt1.o");
    tcc_add_crt(s1, "crti.o");
#endif
}

ST_FUNC فراغ tccelf_add_crtend(TCCState *s1)
{
#ܐܢ TARGETOS_OpenBSD
    ܐܢ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtendS.o");
    ܐܚܪܢܐ
        tcc_add_crt(s1, "crtend.o");
#وإلاإذا TARGETOS_FreeBSD || TARGETOS_NetBSD
    ܐܢ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtendS.o");
    ܐܚܪܢܐ
        tcc_add_crt(s1, "crtend.o");
    tcc_add_crt(s1, "crtn.o");
#وإلاإذا TARGETOS_ANDROID
    ܐܢ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtend_so.o");
    ܐܚܪܢܐ
        tcc_add_crt(s1, "crtend_android.o");
#ܐܚܪܢܐ
    tcc_add_crt(s1, "crtn.o");
#endif
}
#endif /* TCC_TARGET_UNIX */

#ifndef TCC_TARGET_PE
/* add tcc runtime libraries */
ST_FUNC فراغ tcc_add_runtime(TCCState *s1)
{
    s1->filetype = 0;

#ifdef CONFIG_TCC_BCHECK
    tcc_add_bcheck(s1);
#endif
    tcc_add_pragma_libs(s1);

    /* add libc */
    ܐܢ (!s1->nostdlib) {
        صحيح lpthread = s1->option_pthread;

#ifdef CONFIG_TCC_BCHECK
        ܐܢ (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    ܐܢ (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    ܐܚܪܢܐ
                tcc_add_support(s1, "bcheck.o");
# ܐܢ !(TARGETOS_OpenBSD || TARGETOS_NetBSD)
            tcc_add_library(s1, "dl");
# endif
            lpthread = 1;
        }
#endif
#ifdef CONFIG_TCC_BACKTRACE
        ܐܢ (s1->do_backtrace) {
            ܐܢ (s1->output_type & TCC_OUTPUT_EXE)
                tcc_add_support(s1, "bt-exe.o");
            ܐܢ (s1->output_type != TCC_OUTPUT_DLL)
                tcc_add_support(s1, "bt-log.o");
            tcc_add_btstub(s1);
            lpthread = 1;
        }
#endif
        ܐܢ (lpthread)
            tcc_add_library(s1, "pthread");
        tcc_add_library(s1, "c");
#ifdef TCC_LIBGCC
        ܐܢ (!s1->static_link) {
            ܐܢ (TCC_LIBGCC[0] == '/')
                tcc_add_file(s1, TCC_LIBGCC);
            ܐܚܪܢܐ
                tcc_add_dll(s1, TCC_LIBGCC, AFF_PRINT_ERROR);
        }
#endif
#ܐܢ defined TCC_TARGET_ARM && TARGETOS_FreeBSD
        tcc_add_library(s1, "gcc_s"); // unwind code
#endif
        ܐܢ (TCC_LIBTCC1[0]) {
            tcc_add_support(s1, TCC_LIBTCC1);
            tcc_add_library(s1, "c");
        }
#ifndef TCC_TARGET_MACHO
        ܐܢ (s1->output_type != TCC_OUTPUT_MEMORY)
            tccelf_add_crtend(s1);
#endif
    }
}
#endif /* ndef TCC_TARGET_PE */

/* set _etext/_edata/_end  f=0:set  f=1:when_needed  f=2,3:just_update */
ساكن فراغ set_linker_sym(TCCState *s1, ثابت حرف *name, Section *sec, صحيح f)
{
    صحيح sym_index, esym_index, defined;
    ElfW(Sym) *sym, *esym;
    sym_index = find_elf_sym(symtab_section, name);
    sym = (ElfW(Sym) *)symtab_section->data + sym_index;
    esym_index = find_elf_sym(s1->dynsymtab_section, name);
    esym = (ElfW(Sym) *)s1->dynsymtab_section->data + esym_index;
    defined = sym->st_shndx != SHN_UNDEF
        || (esym->st_shndx != SHN_UNDEF && esym->st_size);
    بدل (f) {
    حالة 1: /* old symbols w/o '_' */
        ܐܢ (!(sym_index || esym_index) || defined)
            اكسر;
    حالة 0:
        ܐܢ (defined) {
            tcc_warning("linker symbol '%s' already defined", name);
            اكسر;
        }
        sym_index = set_global_sym(s1, name, sec, -1);
        get_sym_attr(s1, sym_index, 1)->linker_sym = 1;
        اكسر;
    افتراضي: /* update (bss only) */
        ܐܢ (get_sym_attr(s1, sym_index, 0)->linker_sym)
            sym->st_value = sec->data_offset;
    }
#ifndef ELF_OBJ_ONLY
    ܐܢ (name[0] == '_')
        set_linker_sym(s1, name + 1, sec, f + 1);
#endif
}

/* add various standard linker symbols (must be done after the
   sections are filled (for example after allocating common
   symbols)) */
ساكن فراغ tcc_add_linker_symbols(TCCState *s1)
{
    حرف buf[1024];
    صحيح i;
    Section *s;

    set_linker_sym(s1, "_etext", text_section, 0);
    set_linker_sym(s1, "_edata", data_section, 0);
    set_linker_sym(s1, "_end", bss_section, 0);
#ܐܢ TARGETOS_OpenBSD
    set_global_sym(s1, "__executable_start", عدم, ELF_START_ADDR);
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
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ܐܢ ((s->sh_flags & SHF_ALLOC)
            && (s->sh_type == SHT_PROGBITS || s->sh_type == SHT_NOBITS
                || s->sh_type == SHT_STRTAB)) {
            /* check if section name can be expressed in C */
            ثابت حرف *p0, *p;
            p0 = s->name;
            ܐܢ (*p0 == '.')
                ++p0;
            p = p0;
            لكل(;;) {
                صحيح c = *p;
                ܐܢ (!c)
                    اكسر;
                ܐܢ (!isid(c) && !isnum(c))
                    اذهب next_sec;
                p++;
            }
            snprintf(buf, حجم(buf), "__start_%s", p0);
            set_global_sym(s1, buf, s, 0);
            snprintf(buf, حجم(buf), "__stop_%s", p0);
            set_global_sym(s1, buf, s, -1);
        }
    next_sec: ;
    }
}

ST_FUNC فراغ resolve_common_syms(TCCState *s1)
{
    ElfW(Sym) *sym;

    /* Allocate common symbols in BSS.  */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ܐܢ (sym->st_shndx == SHN_COMMON && sym->st_size) {
            /* symbol alignment is in st_value for SHN_COMMONs */
	    sym->st_value = section_add(bss_section, sym->st_size,
					sym->st_value);
            sym->st_shndx = bss_section->sh_num;
        }
    }

    /* Now assign linker provided symbols their value.  */
    ܐܢ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_linker_symbols(s1);
}

#ifndef ELF_OBJ_ONLY
ST_FUNC فراغ fill_got_entry(TCCState *s1, ElfW_Rel *rel)
{
    صحيح sym_index = ELFW(R_SYM) (rel->r_info);
    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->data)[sym_index];
    بنية sym_attr *attr = get_sym_attr(s1, sym_index, 0);
    unsigned offset = attr->got_offset;

    ܐܢ (0 == offset)
        ܦܢܐ;
    section_reserve(s1->got, offset + PTR_SIZE);
#ܐܢ PTR_SIZE == 8
    write64le(s1->got->data + offset, sym->st_value);
#ܐܚܪܢܐ
    write32le(s1->got->data + offset, sym->st_value);
#endif
}

/* Perform relocation to GOT or PLT entries */
ST_FUNC فراغ fill_got(TCCState *s1)
{
    Section *s;
    ElfW_Rel *rel;
    صحيح i;

    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ܐܢ (s->sh_type != SHT_RELX)
            استمر;
        /* no need to handle got relocations */
        ܐܢ (s->link != symtab_section)
            استمر;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            بدل (ELFW(R_TYPE) (rel->r_info)) {
                حالة R_X86_64_GOT32:
                حالة R_X86_64_GOTPCREL:
		حالة R_X86_64_GOTPCRELX:
		حالة R_X86_64_REX_GOTPCRELX:
                حالة R_X86_64_PLT32:
                    fill_got_entry(s1, rel);
                    اكسر;
            }
        }
    }
}

/* See put_got_entry for a description.  This is the second stage
   where GOT references to local defined symbols are rewritten.  */
ساكن فراغ fill_local_got_entries(TCCState *s1)
{
    ElfW_Rel *rel;
    ܐܢ (!s1->got->reloc)
        ܦܢܐ;
    for_each_elem(s1->got->reloc, 0, rel, ElfW_Rel) {
	ܐܢ (ELFW(R_TYPE)(rel->r_info) == R_RELATIVE) {
	    صحيح sym_index = ELFW(R_SYM) (rel->r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->data)[sym_index];
	    بنية sym_attr *attr = get_sym_attr(s1, sym_index, 0);
	    unsigned offset = attr->got_offset;
	    ܐܢ (offset != rel->r_offset - s1->got->sh_addr)
	        tcc_error_noabort("fill_local_got_entries: huh?");
	    rel->r_info = ELFW(R_INFO)(0, R_RELATIVE);
#ܐܢ SHT_RELX == SHT_RELA
	    rel->r_addend = sym->st_value;
#ܐܚܪܢܐ
	    /* All our REL architectures also happen to be 32bit LE.  */
	    write32le(s1->got->data + offset, sym->st_value);
#endif
	}
    }
}

/* Bind symbols of executable: resolve undefined symbols from exported symbols
   in shared libraries */
ساكن فراغ bind_exe_dynsyms(TCCState *s1, صحيح is_PIE)
{
    ثابت حرف *name;
    صحيح sym_index, index;
    ElfW(Sym) *sym, *esym;
    صحيح type;

    /* Resolve undefined symbols from dynamic symbols. When there is a match:
       - if STT_FUNC or STT_GNU_IFUNC symbol -> add it in PLT
       - if STT_OBJECT symbol -> add it in .bss section with suitable reloc */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ܐܢ (sym->st_shndx == SHN_UNDEF
            /* bss symbols may be initialized in the shared library */
            || sym->st_shndx == SHN_COMMON
            || sym->st_shndx == bss_section->sh_num) {
            name = (حرف *) symtab_section->link->data + sym->st_name;
            sym_index = find_elf_sym(s1->dynsymtab_section, name);
            esym = &((ElfW(Sym) *)s1->dynsymtab_section->data)[sym_index];
            ܐܢ (sym_index && esym->st_shndx != SHN_UNDEF) {
                ܐܢ (is_PIE)
                    استمر;
                type = ELFW(ST_TYPE)(esym->st_info);
                ܐܢ ((type == STT_FUNC) || (type == STT_GNU_IFUNC)) {
                    /* Indirect functions shall have STT_FUNC type in executable
                     * dynsym section. Indeed, a dlsym call following a lazy
                     * resolution would pick the symbol value from the
                     * executable dynsym entry which would contain the address
                     * of the function wanted by the caller of dlsym instead of
                     * the address of the function that would return that
                     * address */
                    صحيح dynindex
		      = put_elf_sym(s1->dynsym, 0, esym->st_size,
				    ELFW(ST_INFO)(STB_GLOBAL,STT_FUNC), 0, 0,
				    name);
		    صحيح index = sym - (ElfW(Sym) *) symtab_section->data;
		    get_sym_attr(s1, index, 1)->dyn_index = dynindex;
                } ܐܚܪܢܐ ܐܢ (type == STT_OBJECT) {
                    unsigned long offset;
                    ElfW(Sym) *dynsym;
                    ܐܢ (sym->st_shndx == bss_section->sh_num) {
                        offset = sym->st_value;
                    } ܐܚܪܢܐ {
                        offset = bss_section->data_offset;
                        /* XXX: which alignment ? */
                        offset = (offset + 16 - 1) & -16;
                        bss_section->data_offset = offset + esym->st_size;
                    }
                    set_elf_sym (s1->symtab, offset, esym->st_size,
                                 esym->st_info, 0, bss_section->sh_num, name);
                    index = put_elf_sym(s1->dynsym, offset, esym->st_size,
                                        esym->st_info, 0, bss_section->sh_num,
                                        name);
                    /* Ensure R_COPY works for weak symbol aliases */
                    ܐܢ (ELFW(ST_BIND)(esym->st_info) == STB_WEAK) {
                        for_each_elem(s1->dynsymtab_section, 1, dynsym, ElfW(Sym)) {
                            ܐܢ ((dynsym->st_value == esym->st_value)
                                && (ELFW(ST_BIND)(dynsym->st_info) == STB_GLOBAL)) {
                                حرف *dynname = (حرف *) s1->dynsymtab_section->link->data
                                                + dynsym->st_name;
                                put_elf_sym(s1->dynsym, offset, dynsym->st_size,
                                            dynsym->st_info, 0,
                                            bss_section->sh_num, dynname);
                                اكسر;
                            }
                        }
                    }
                    put_elf_reloc(s1->dynsym, bss_section,
                                  offset, R_COPY, index);
                }
            } ܐܚܪܢܐ ܐܢ (sym->st_shndx == SHN_UNDEF) {
                /* STB_WEAK undefined symbols are accepted */
                /* XXX: _fp_hw seems to be part of the ABI, so we ignore it */
                ܐܢ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK ||
                    !strcmp(name, "_fp_hw")) {
                } ܐܚܪܢܐ {
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
ساكن فراغ bind_libs_dynsyms(TCCState *s1)
{
    ثابت حرف *name;
    صحيح dynsym_index;
    ElfW(Sym) *sym, *esym;

    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        name = (حرف *)symtab_section->link->data + sym->st_name;
        dynsym_index = find_elf_sym(s1->dynsymtab_section, name);
        ܐܢ (sym->st_shndx != SHN_UNDEF) {
            ܐܢ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL
                && (dynsym_index || s1->rdynamic))
                set_elf_sym(s1->dynsym, sym->st_value, sym->st_size,
                            sym->st_info, 0, sym->st_shndx, name);
        } ܐܚܪܢܐ ܐܢ (dynsym_index) {
            esym = (ElfW(Sym) *)s1->dynsymtab_section->data + dynsym_index;
            ܐܢ (esym->st_shndx == SHN_UNDEF) {
                /* weak symbols can stay undefined */
                ܐܢ (ELFW(ST_BIND)(esym->st_info) != STB_WEAK)
                    tcc_warning("unresolved dynamic reference to '%s'", name);
            }
        }
    }
}

/* Export all non local symbols. This is used by shared libraries so that the
   non local symbols they define can resolve a reference in another shared
   library or in the executable. Correspondingly, it allows undefined local
   symbols to be resolved by other shared libraries or by the executable. */
ساكن فراغ export_global_syms(TCCState *s1)
{
    صحيح dynindex, index;
    ثابت حرف *name;
    ElfW(Sym) *sym;
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ܐܢ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
	    name = (حرف *) symtab_section->link->data + sym->st_name;
	    dynindex = set_elf_sym(s1->dynsym, sym->st_value, sym->st_size,
				   sym->st_info, 0, sym->st_shndx, name);
	    index = sym - (ElfW(Sym) *) symtab_section->data;
            get_sym_attr(s1, index, 1)->dyn_index = dynindex;
        }
    }
}

/* decide if an unallocated section should be output. */
ساكن صحيح set_sec_sizes(TCCState *s1)
{
    صحيح i;
    Section *s;
    صحيح textrel = 0;
    صحيح file_type = s1->output_type;

    /* Allocate strings for section names */
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ܐܢ (s->sh_type == SHT_RELX && !(s->sh_flags & SHF_ALLOC)) {
            /* when generating a DLL, we include relocations but
               we may patch them */
            ܐܢ ((file_type & TCC_OUTPUT_DYN)
                && (s1->sections[s->sh_info]->sh_flags & SHF_ALLOC)) {
                صحيح count = prepare_dynamic_rel(s1, s);
                ܐܢ (count) {
                    /* allocate the section */
                    s->sh_flags |= SHF_ALLOC;
                    s->sh_size = count * حجم(ElfW_Rel);
                    ܐܢ (s1->sections[s->sh_info]->sh_flags & SHF_EXECINSTR)
                        textrel += count;
                }
            }
        } ܐܚܪܢܐ ܐܢ ((s->sh_flags & SHF_ALLOC)
#ifdef TCC_TARGET_ARM
                   || s->sh_type == SHT_ARM_ATTRIBUTES
#endif
                   || s1->do_debug) {
            s->sh_size = s->data_offset;
        }
    }
    ܦܢܐ textrel;
}

/* various data used under elf_output_file() */
بنية dyn_inf {
    Section *dynamic;
    Section *dynstr;
    Section *interp;
    Section *note;
    Section *gnu_hash;
    بنية {
        /* Info to be copied in dynamic section */
        unsigned long data_offset;
        addr_t rel_addr;
        addr_t rel_size;
    };

    ElfW(Phdr) *phdr;
    صحيح phnum;
    صحيح shnum;
    صحيح tls;
    صحيح relro;
    صحيح notes;
    صحيح ehfr;
    صحيح dyna;
};

/* Decide the layout of sections loaded in memory. This must be done before
   program headers are filled since they contain info about the layout.
   We do the following ordering: interp, symbol tables, relocations, progbits,
   nobits */
ساكن صحيح sort_sections(TCCState *s1, صحيح *sec_order, بنية dyn_inf *d)
{
    Section *s;
    صحيح i, j, k, f, f0, n;
    صحيح nb_sections = s1->nb_sections;
    صحيح *sec_cls = sec_order + nb_sections;
    صحيح tls_align = 0; /* need common alignment for all tls sections */

    لكل (i = 1; i < nb_sections; i++) {
        s = s1->sections[i];
        ܐܢ (0 == s->sh_name) {
            j = 0x900; /* no sh_name: won't go to file */
        } ܐܚܪܢܐ ܐܢ (s->sh_flags & SHF_ALLOC) {
            j = 0x100;
            ܐܢ ((s->sh_flags & (SHF_WRITE|SHF_TLS)) == SHF_WRITE)
                j = 0x200;
        } ܐܚܪܢܐ {
            j = 0x700;
        }
        ܐܢ (j >= 0x700 && s1->output_format != TCC_OUTPUT_FORMAT_ELF)
            s->sh_size = 0, j = 0x900;

        ܐܢ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM) {
            k = 0x10;
        } ܐܚܪܢܐ ܐܢ (s->sh_type == SHT_STRTAB && strcmp(s->name, ".stabstr")) {
            k = 0x11;
            ܐܢ (i == nb_sections - 1) /* ".shstrtab" assumed to stay last */
                k = 0xff;
        } ܐܚܪܢܐ ܐܢ (s->sh_type == SHT_HASH || s->sh_type == SHT_GNU_HASH) {
            k = 0x12;
        } ܐܚܪܢܐ ܐܢ (s->sh_type == SHT_GNU_verdef
                  || s->sh_type == SHT_GNU_verneed
                  || s->sh_type == SHT_GNU_versym) {
            k = 0x13;
        } ܐܚܪܢܐ ܐܢ (s->sh_type == SHT_RELX) {
            k = 0x20;
            ܐܢ (s1->plt && s == s1->plt->reloc)
                k = 0x21;
        } ܐܚܪܢܐ ܐܢ (s->sh_flags & SHF_EXECINSTR) {
            k = 0x60;
        /* RELRO sections --> */
        } ܐܚܪܢܐ ܐܢ (s->sh_flags & SHF_TLS) {
            ܐܢ (s->sh_addralign > tls_align)
                tls_align = s->sh_addralign;
            k = 0x40 + (s->sh_type == SHT_NOBITS);
        } ܐܚܪܢܐ ܐܢ (s->sh_type == SHT_PREINIT_ARRAY) {
            k = 0x42;
        } ܐܚܪܢܐ ܐܢ (s->sh_type == SHT_INIT_ARRAY) {
            k = 0x43;
        } ܐܚܪܢܐ ܐܢ (s->sh_type == SHT_FINI_ARRAY) {
            k = 0x44;
        } ܐܚܪܢܐ ܐܢ (s->sh_type == SHT_DYNAMIC) {
            k = 0x48;
        } ܐܚܪܢܐ ܐܢ (s == s1->got) {
            k = 0x49; /* .got as RELRO needs BIND_NOW in DT_FLAGS */
        } ܐܚܪܢܐ ܐܢ (s->reloc && (s->reloc->sh_flags & SHF_ALLOC) && j == 0x100) {
            k = 0x45; /* +1 for data.ro */
        /* <-- */
        } ܐܚܪܢܐ ܐܢ (s->sh_type == SHT_NOTE) {
            k = 0x08, d->notes = 1;
        } ܐܚܪܢܐ ܐܢ (s->sh_type == SHT_NOBITS) {
            k = 0x70; /* bss */
        } ܐܚܪܢܐ ܐܢ (s == d->interp) {
            k = 0x00;
        } ܐܚܪܢܐ {
            k = 0x50; /* data */
        }
        k += j;
        /* make our standard sections come last to have _etext/_edata correct values */
        ܐܢ (s->sh_num <= bss_section->sh_num)
            ++k;
        /* make RELRO section writable */
        ܐܢ ((k & 0xfff0) == 0x140)
            k += 0x100, s->sh_flags |= SHF_WRITE;
        /* sort by insert */
        لكل (n = i; n > 1 && k < (f = sec_cls[n - 1]); --n)
            sec_cls[n] = f, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
    }
    sec_order[0] = 0;
    d->shnum = 1;

#define SHFX_NEWPH (1 << 4)
#define SHFX_RELRO (1 << 5)

    /* count PT_LOAD headers needed */
    n = f0 = 0;
    لكل (i = 1; i < nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        k = sec_cls[i];
        f = 0;
        ܐܢ (k < 0x900)
            ++d->shnum;
        ܐܢ (k < 0x700) {
            f = s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR);
#ܐܢ TARGETOS_NetBSD || TARGETOS_FreeBSD
	    /* NetBSD only supports 2 PT_LOAD sections.
	       See: https://blog.netbsd.org/tnf/entry/the_first_report_on_lld */
	    ܐܢ ((f & SHF_WRITE) == 0)
                f |= SHF_EXECINSTR;
            k = 0; /* no relro */
#endif
            ܐܢ ((k & 0xfff0) == 0x240) /* RELRO sections */
                d->relro = 1, f |= SHFX_RELRO;
            /* start new header when flags changed, but avoid zero memsz */
            ܐܢ (f != f0 && s->sh_size)
                f0 = f, ++n, f |= SHFX_NEWPH;
            ܐܢ ((s->sh_flags & SHF_TLS) && s->sh_size) {
                s->sh_addralign = tls_align;
                d->tls = 1, f |= SHF_TLS;
            }
        }
        sec_cls[i] = f;
        //printf("ph %d sec %02d : %3X %3X  %8.2X  %04X  %s\n", (f>0) * n, i, f, k, s->sh_type, (int)s->sh_size, s->name);
    }
    ܦܢܐ n;
}

ساكن ElfW(Phdr) *fill_phdr(ElfW(Phdr) *ph, صحيح type, Section *s)
{
    ph->p_type = type;
    ph->p_flags = PF_R;
    ܐܢ (s) {
        ܐܢ (s->sh_flags & SHF_WRITE)
            ph->p_flags |= PF_W;
        ph->p_offset = s->sh_offset;
        ph->p_vaddr = s->sh_addr;
        ph->p_filesz = s->sh_size;
        ph->p_align = s->sh_addralign;
    }
    ph->p_paddr = ph->p_vaddr;
    ph->p_memsz = ph->p_filesz;
    ܦܢܐ ph;
}

ساكن ElfW(Phdr) *update_phdr(ElfW(Phdr) *ph, صحيح type, Section *s, addr_t addr, صحيح file_offset)
{
    ܐܢ (ph->p_type == 0) {
        fill_phdr(ph, type, s);
    }
    ph->p_filesz = file_offset - ph->p_offset;
    ph->p_memsz = addr - ph->p_vaddr;
    ܦܢܐ ph;
}

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
ساكن صحيح layout_sections(TCCState *s1, صحيح *sec_order, بنية dyn_inf *d)
{
    Section *s;
    addr_t addr, tmp, align, s_align, base;
    ElfW(Phdr) *ph = عدم, *ph2;
    صحيح i, f, n, phnum, phfill;
    صحيح file_offset;

    /* compute number of program headers */
    phnum = sort_sections(s1, sec_order, d);
    phfill = 0; /* set to 1 to have dll's with a PT_PHDR */
    ܐܢ (d->interp)
        phfill = 2;
    phnum += phfill;
    ܐܢ (d->dynamic)
        d->dyna = phnum++;
    ܐܢ (d->notes)
        d->notes = phnum++;
    ܐܢ (d->tls)
        d->tls = phnum++;
    ܐܢ (eh_frame_hdr_section)
        d->ehfr = phnum++;
    ܐܢ (d->relro)
        d->relro = phnum++;
    d->phnum = phnum;
    d->phdr = tcc_mallocz(phnum * حجم(ElfW(Phdr)));

    file_offset = 0;
    ܐܢ (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
        file_offset = (حجم(ElfW(Ehdr)) + phnum * حجم(ElfW(Phdr)) + 3) & -4;
        file_offset += d->shnum * حجم (ElfW(Shdr));
    }

    s_align = ELF_PAGE_SIZE;
    ܐܢ (s1->section_align)
        s_align = s1->section_align;

    addr = ELF_START_ADDR;
    ܐܢ (s1->output_type & TCC_OUTPUT_DYN)
        addr = 0;

    ܐܢ (s1->has_text_addr) {
        addr = s1->text_addr;
        ܐܢ (0) {
            صحيح a_offset, p_offset;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_offset = (صحيح) (addr & (s_align - 1));
            p_offset = file_offset & (s_align - 1);
            ܐܢ (a_offset < p_offset)
                a_offset += s_align;
            file_offset += (a_offset - p_offset);
        }
    }
    base = addr;
    /* compute address after headers */
    addr += file_offset;

    n = 0;
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        f = sec_order[i + s1->nb_sections];
        align = s->sh_addralign - 1;

        ܐܢ (f == 0) { /* no alloc */
            file_offset = (file_offset + align) & ~align;
            s->sh_offset = file_offset;
            ܐܢ (s->sh_type != SHT_NOBITS)
                file_offset += s->sh_size;
            استمر;
        }

        ܐܢ ((f & SHFX_NEWPH) && n) {
            /* different rwx section flags */
            ܐܢ (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
                /* if in the middle of a page, w e duplicate the page in
                   memory so that one copy is RX and the other is RW */
                ܐܢ ((addr & (s_align - 1)) != 0)
                    addr += s_align;
            } ܐܚܪܢܐ {
                align = s_align - 1;
            }
        }

        tmp = addr;
        addr = (addr + align) & ~align;
        file_offset += (صحيح)(addr - tmp);
        s->sh_offset = file_offset;
        s->sh_addr = addr;

        //printf("%d : %08x %08x %04x %03x %s %d\n", n, (int)file_offset, (int)addr, (int)s->sh_size, s->sh_type, s->name, align + 1);
        addr += s->sh_size;
        ܐܢ (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_size;

        ܐܢ (f & SHFX_NEWPH) {
            /* set new program header */
            ph = &d->phdr[phfill + n];
            fill_phdr(ph, PT_LOAD, s);
            ph->p_align = s_align;
            ܐܢ (f & SHF_EXECINSTR)
                ph->p_flags |= PF_X;
            ܐܢ (n == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_offset = 0;
                ph->p_paddr = ph->p_vaddr = base;
            }
            ++n;
        }

        ܐܢ (ph)
            update_phdr(ph, 0, 0, addr, file_offset);

        ܐܢ (f & SHFX_RELRO) {
            ph2 = update_phdr(&d->phdr[d->relro], PT_GNU_RELRO, s, addr, file_offset);
            ph2->p_align = 1;
        }
        ܐܢ (f & SHF_TLS) {
            ph2 = update_phdr(&d->phdr[d->tls], PT_TLS, s, addr, file_offset);
            ܐܢ (s->sh_type == SHT_NOBITS)
                addr -= s->sh_size;
            /* for xxx-link.c:relocate() */
            s1->tls_start = ph2->p_vaddr;
            s1->tls_end = s1->tls_start + ph2->p_memsz + (-ph2->p_memsz & (ph2->p_align - 1));
        }
        ܐܢ (s->sh_type == SHT_NOTE) {
            update_phdr(&d->phdr[d->notes], PT_NOTE, s, addr, file_offset);
        }
    }

    /* Fill other headers */
    ܐܢ (d->dyna)
        fill_phdr(&d->phdr[d->dyna], PT_DYNAMIC, d->dynamic);
    ܐܢ (d->ehfr)
        fill_phdr(&d->phdr[d->ehfr], PT_GNU_EH_FRAME, eh_frame_hdr_section);
    ܐܢ (d->interp)
        fill_phdr(&d->phdr[1], PT_INTERP, d->interp);
    ܐܢ (phfill) {
        ph = &d->phdr[0];
        ph->p_offset = حجم(ElfW(Ehdr));
        ph->p_vaddr = base + ph->p_offset;
        ph->p_filesz = phnum * حجم(ElfW(Phdr));
        ph->p_align = 4;
        fill_phdr(ph, PT_PHDR, عدم);
    }
    ܦܢܐ 0;
}

/* put dynamic tag */
ساكن فراغ put_dt(Section *dynamic, صحيح dt, addr_t val)
{
    ElfW(Dyn) *dyn;
    dyn = section_ptr_add(dynamic, حجم(ElfW(Dyn)));
    dyn->d_tag = dt;
    dyn->d_un.d_val = val;
}

/* Fill the dynamic section with tags describing the address and size of
   sections */
ساكن فراغ fill_dynamic(TCCState *s1, بنية dyn_inf *dyninf)
{
    Section *dynamic = dyninf->dynamic;
    Section *s;

    /* put dynamic section entries */
    put_dt(dynamic, DT_HASH, s1->dynsym->hash->sh_addr);
    put_dt(dynamic, DT_GNU_HASH, dyninf->gnu_hash->sh_addr);
    put_dt(dynamic, DT_STRTAB, dyninf->dynstr->sh_addr);
    put_dt(dynamic, DT_SYMTAB, s1->dynsym->sh_addr);
    put_dt(dynamic, DT_STRSZ, dyninf->dynstr->data_offset);
    put_dt(dynamic, DT_SYMENT, حجم(ElfW(Sym)));
#ܐܢ PTR_SIZE == 8
    put_dt(dynamic, DT_RELA, dyninf->rel_addr);
    put_dt(dynamic, DT_RELASZ, dyninf->rel_size);
    put_dt(dynamic, DT_RELAENT, حجم(ElfW_Rel));
    ܐܢ (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->data_offset);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_RELA);
    }
    put_dt(dynamic, DT_RELACOUNT, 0);
#ܐܚܪܢܐ
    put_dt(dynamic, DT_REL, dyninf->rel_addr);
    put_dt(dynamic, DT_RELSZ, dyninf->rel_size);
    put_dt(dynamic, DT_RELENT, حجم(ElfW_Rel));
    ܐܢ (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->data_offset);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_REL);
    }
    put_dt(dynamic, DT_RELCOUNT, 0);
#endif
    ܐܢ (versym_section && verneed_section) {
	/* The dynamic linker can not handle VERSYM without VERNEED */
        put_dt(dynamic, DT_VERSYM, versym_section->sh_addr);
        put_dt(dynamic, DT_VERNEED, verneed_section->sh_addr);
        put_dt(dynamic, DT_VERNEEDNUM, dt_verneednum);
    }
    s = have_section(s1, ".preinit_array");
    ܐܢ (s && s->data_offset) {
        put_dt(dynamic, DT_PREINIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_PREINIT_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".init_array");
    ܐܢ (s && s->data_offset) {
        put_dt(dynamic, DT_INIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_INIT_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".fini_array");
    ܐܢ (s && s->data_offset) {
        put_dt(dynamic, DT_FINI_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_FINI_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".init");
    ܐܢ (s && s->data_offset) {
        put_dt(dynamic, DT_INIT, s->sh_addr);
    }
    s = have_section(s1, ".fini");
    ܐܢ (s && s->data_offset) {
        put_dt(dynamic, DT_FINI, s->sh_addr);
    }
    ܐܢ (s1->do_debug)
        put_dt(dynamic, DT_DEBUG, 0);
    put_dt(dynamic, DT_NULL, 0);
}

/* Remove gaps between RELX sections.
   These gaps are a result of final_sections_reloc. Here some relocs are removed.
   The gaps are then filled with 0 in tcc_output_elf. The 0 is intepreted as
   R_...NONE reloc. This does work on most targets but on OpenBSD/arm64 this
   is illegal. OpenBSD/arm64 does not support R_...NONE reloc. */
ساكن فراغ update_reloc_sections(TCCState *s1, بنية dyn_inf *dyninf)
{
    صحيح i;
    unsigned long file_offset = 0;
    Section *s;
    Section *relocplt = s1->plt ? s1->plt->reloc : عدم;

    /* dynamic relocation table information, for .dynamic section */
    dyninf->rel_addr = dyninf->rel_size = 0;

    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
	ܐܢ (s->sh_type == SHT_RELX && s != relocplt) {
	    ܐܢ (dyninf->rel_size == 0) {
		dyninf->rel_addr = s->sh_addr;
		file_offset = s->sh_offset;
	    }
	    ܐܚܪܢܐ {
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
ساكن صحيح tcc_output_elf(TCCState *s1, FILE *f, صحيح phnum, ElfW(Phdr) *phdr)
{
    صحيح i, shnum, offset, size, file_type;
    Section *s;
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) shdr, *sh;

    file_type = s1->output_type;
    shnum = s1->nb_sections;

    memset(&ehdr, 0, حجم(ehdr));
    ܐܢ (phnum > 0) {
        ehdr.e_phentsize = حجم(ElfW(Phdr));
        ehdr.e_phnum = phnum;
        ehdr.e_phoff = حجم(ElfW(Ehdr));
    }

    /* fill header */
    ehdr.e_ident[0] = ELFMAG0;
    ehdr.e_ident[1] = ELFMAG1;
    ehdr.e_ident[2] = ELFMAG2;
    ehdr.e_ident[3] = ELFMAG3;
    ehdr.e_ident[4] = ELFCLASSW;
    ehdr.e_ident[5] = ELFDATA2LSB;
    ehdr.e_ident[6] = EV_CURRENT;

#ܐܢ TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    ehdr.e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
#وإلاإذا TARGETOS_OpenBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_OPENBSD;
#وإلاإذا TARGETOS_NetBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_NETBSD;
#وإلاإذا defined TCC_TARGET_ARM && defined TCC_ARM_EABI
    ehdr.e_flags = EF_ARM_EABI_VER5;
    ehdr.e_flags |= s1->float_abi == ARM_HARD_FLOAT
        ? EF_ARM_VFP_FLOAT : EF_ARM_SOFT_FLOAT;
#وإلاإذا defined TCC_TARGET_ARM
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#وإلاإذا defined TCC_TARGET_RISCV64
    /* XXX should be configurable */
    ehdr.e_flags = EF_RISCV_FLOAT_ABI_DOUBLE;
#endif

    ܐܢ (file_type == TCC_OUTPUT_OBJ) {
        ehdr.e_type = ET_REL;
    } ܐܚܪܢܐ {
        ܐܢ (file_type & TCC_OUTPUT_DYN)
            ehdr.e_type = ET_DYN;
        ܐܚܪܢܐ
            ehdr.e_type = ET_EXEC;
        ܐܢ (s1->elf_entryname)
            ehdr.e_entry = get_sym_addr(s1, s1->elf_entryname, 1, 0);
        ܐܚܪܢܐ
            ehdr.e_entry = get_sym_addr(s1, "_start", !!(file_type & TCC_OUTPUT_EXE), 0);
        ܐܢ (ehdr.e_entry == (addr_t)-1)
            ehdr.e_entry = text_section->sh_addr;
        ܐܢ (s1->nb_errors)
            ܦܢܐ -1;
    }

    sort_syms(s1, s1->symtab);

    ehdr.e_machine = EM_TCC_TARGET;
    ehdr.e_version = EV_CURRENT;
    ehdr.e_shoff = (حجم(ElfW(Ehdr)) + phnum * حجم(ElfW(Phdr)) + 3) & -4;
    ehdr.e_ehsize = حجم(ElfW(Ehdr));
    ehdr.e_shentsize = حجم(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    offset = fwrite(&ehdr, 1, حجم(ElfW(Ehdr)), f);
    ܐܢ (phdr)
        offset += fwrite(phdr, 1, phnum * حجم(ElfW(Phdr)), f);

    /* output section headers */
    ܟܡܐ (offset < ehdr.e_shoff) {
        fputc(0, f);
        offset++;
    }

    لكل(i = 0; i < shnum; i++) {
        sh = &shdr;
        memset(sh, 0, حجم(ElfW(Shdr)));
        ܐܢ (i) {
            s = s1->sections[i];
            sh->sh_name = s->sh_name;
            sh->sh_type = s->sh_type;
            sh->sh_flags = s->sh_flags;
            sh->sh_entsize = s->sh_entsize;
            sh->sh_info = s->sh_info;
            ܐܢ (s->link)
                sh->sh_link = s->link->sh_num;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_offset = s->sh_offset;
            sh->sh_size = s->sh_size;
        }
        offset += fwrite(sh, 1, حجم(ElfW(Shdr)), f);
    }

    /* output sections */
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ܐܢ (s->sh_type != SHT_NOBITS) {
            ܟܡܐ (offset < s->sh_offset) {
                fputc(0, f);
                offset++;
            }
            size = s->sh_size;
            ܐܢ (size)
                offset += fwrite(s->data, 1, size, f);
        }
    }
    ܦܢܐ 0;
}

ساكن صحيح tcc_output_binary(TCCState *s1, FILE *f)
{
    Section *s;
    صحيح i, offset, size;

    offset = 0;
    لكل(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[i];
        ܐܢ (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            ܟܡܐ (offset < s->sh_offset) {
                fputc(0, f);
                offset++;
            }
            size = s->sh_size;
            fwrite(s->data, 1, size, f);
            offset += size;
        }
    }
    ܦܢܐ 0;
}

/* Write an elf, coff or "binary" file */
ساكن صحيح tcc_write_elf_file(TCCState *s1, ثابت حرف *filename, صحيح phnum,
                              ElfW(Phdr) *phdr)
{
    صحيح fd, mode, file_type, ret;
    FILE *f;

    file_type = s1->output_type;
    ܐܢ (file_type == TCC_OUTPUT_OBJ)
        mode = 0666;
    ܐܚܪܢܐ
        mode = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, mode);
    ܐܢ (fd < 0 || (f = fdopen(fd, "wb")) == عدم)
        ܦܢܐ tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
    ܐܢ (s1->verbose)
        printf("<- %s\n", filename);
#ifdef TCC_TARGET_COFF
    ܐܢ (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    ܐܚܪܢܐ
#endif
    ܐܢ (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        ret = tcc_output_elf(s1, f, phnum, phdr);
    ܐܚܪܢܐ
        ret = tcc_output_binary(s1, f);
    fclose(f);

    ܦܢܐ ret;
}

#ifndef ELF_OBJ_ONLY
/* order sections according to sec_order, remove sections
   that we aren't going to output.  */
ساكن فراغ reorder_sections(TCCState *s1, صحيح *sec_order)
{
    صحيح i, nnew, k, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    backmap = tcc_malloc(s1->nb_sections * حجم(backmap[0]));
    لكل (i = 0, nnew = 0, snew = عدم; i < s1->nb_sections; i++) {
	k = sec_order ? sec_order[i] : i;
	s = s1->sections[k];
	ܐܢ (!i || s->sh_name) {
	    backmap[k] = nnew;
            dynarray_add(&snew, &nnew, s);
	} ܐܚܪܢܐ {
	    backmap[k] = 0;
            /* just remember to free them later */
	    dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, s);
	}
    }
    لكل (i = 1; i < nnew; i++) {
	s = snew[i];
        s->sh_num = i;
        ܐܢ (s->sh_type == SHT_RELX)
            s->sh_info = backmap[s->sh_info];
        ܐܚܪܢܐ ܐܢ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM)
            for_each_elem(s, 1, sym, ElfW(Sym))
                ܐܢ (sym->st_shndx < s1->nb_sections)
                    sym->st_shndx = backmap[sym->st_shndx];
    }
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}

#ifdef TCC_TARGET_ARM
ساكن فراغ create_arm_attribute_section(TCCState *s1)
{
   // Needed for DLL support.
    ساكن ثابت unsigned حرف arm_attr[] = {
        0x41,                            // 'A'
        0x2c, 0x00, 0x00, 0x00,          // size 0x2c
        'a', 'e', 'a', 'b', 'i', 0x00,   // "aeabi"
        0x01, 0x22, 0x00, 0x00, 0x00,    // 'File Attributes', size 0x22
        0x05, 0x36, 0x00,                // 'CPU_name', "6"
#ܐܢ CONFIG_TCC_CPUVER >= 7
        0x06, 0x0a,                      // 'CPU_arch', 'v7'
#ܐܚܪܢܐ
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
    unsigned حرف *ptr = section_ptr_add(attr, حجم(arm_attr));
    attr->sh_addralign = 1;
    memcpy(ptr, arm_attr, حجم(arm_attr));
    ܐܢ (s1->float_abi != ARM_HARD_FLOAT) {
        ptr[26] = 0x00; // 'FP_arch', 'No'
        ptr[41] = 0x1e; // 'ABI_optimization_goals'
        ptr[42] = 0x06; // 'Aggressive Debug'
    }
}
#endif

#ifdef TCC_TARGET_RISCV64
ساكن فراغ create_riscv_attribute_section(TCCState *s1)
{
    ساكن ثابت unsigned حرف riscv_attr[] = {
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
    unsigned حرف *ptr = section_ptr_add(attr, حجم(riscv_attr));
    attr->sh_addralign = 1;
    memcpy(ptr, riscv_attr, حجم(riscv_attr));
}
#endif

#ܐܢ TARGETOS_OpenBSD || TARGETOS_NetBSD || TARGETOS_FreeBSD

ساكن فراغ fill_bsd_note(Section *s, صحيح type,
			  ثابت حرف *value, uint32_t data)
{
    unsigned long offset = 0;
    حرف *ptr;
    ElfW(Nhdr) *note;
    صحيح align = s->sh_addralign;

    /* check if type present */
    ܟܡܐ (offset + حجم(ElfW(Nhdr)) < s->data_offset) {
        note = (ElfW(Nhdr) *) (s->data + offset);
	ܐܢ (note->n_type == type)
	    ܦܢܐ;
	offset += (حجم(ElfW(Nhdr)) + note->n_namesz + note->n_descsz +
		  align - 1) & -align;
    }
    ptr = section_ptr_add(s, حجم(ElfW(Nhdr)) + 8 + 4);
    note = (ElfW(Nhdr) *) ptr;
    note->n_namesz = 8;
    note->n_descsz = 4;
    note->n_type = type;
    strcpy (ptr + حجم(ElfW(Nhdr)), value);
    memcpy (ptr + حجم(ElfW(Nhdr)) + 8, &data, 4);
}

ساكن Section *create_bsd_note_section(TCCState *s1,
					ثابت حرف *name,
					ثابت حرف *value)
{
    Section *s;
    unsigned صحيح major = 0, minor = 0, patch = 0;

#ifdef CONFIG_OS_RELEASE
    sscanf(CONFIG_OS_RELEASE, "%u.%u.%u", &major, &minor, &patch);
#endif
#ܐܢ TARGETOS_FreeBSD
    ܐܢ (major < 14)
	ܦܢܐ عدم;
#endif
    s = find_section (s1, name);
    s->sh_type = SHT_NOTE;
#ܐܢ TARGETOS_OpenBSD
    fill_bsd_note(s, ELF_NOTE_OS_GNU, value, 0);
#وإلاإذا TARGETOS_NetBSD
    fill_bsd_note(s, 1 /* NT_NETBSD_IDENT_TAG */, value,
		  major * 100000000u + (minor % 100u) * 1000000u +
		  (patch % 10000u) * 100u);
#وإلاإذا TARGETOS_FreeBSD
    fill_bsd_note(s, 1 /* NT_FREEBSD_ABI_TAG */, value,
		  major * 100000u + (minor % 100u) * 1000u);
    fill_bsd_note(s, 4 /* NT_FREEBSD_FEATURE_CTL */, value, 0);
    fill_bsd_note(s, 2 /* NT_FREEBSD_NOINIT_TAG */, value, 0);
#endif
    ܦܢܐ s;
}
#endif

ساكن فراغ alloc_sec_names(TCCState *s1, صحيح is_obj);

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
ساكن صحيح elf_output_file(TCCState *s1, ثابت حرف *filename)
{
    صحيح i, ret, file_type, *sec_order;
    بنية dyn_inf dyninf = {0};
    Section *interp, *dynstr, *dynamic;
    صحيح textrel, got_sym, dt_flags_1;

    file_type = s1->output_type;
    ret = -1;
    interp = dynstr = dynamic = عدم;
    sec_order = عدم;

#ifdef TCC_TARGET_ARM
    create_arm_attribute_section (s1);
#endif

#ifdef TCC_TARGET_RISCV64
    create_riscv_attribute_section(s1);
#endif

#ܐܢ TARGETOS_OpenBSD
    dyninf.note = create_bsd_note_section (s1, ".note.openbsd.ident", "OpenBSD");
#endif

#ܐܢ TARGETOS_NetBSD
    dyninf.note = create_bsd_note_section (s1, ".note.netbsd.ident", "NetBSD");
#endif

#ܐܢ TARGETOS_FreeBSD
    dyninf.note = create_bsd_note_section (s1, ".note.tag", "FreeBSD");
#endif

        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_add_runtime(s1);
	resolve_common_syms(s1);

        ܐܢ (!s1->static_link) {
            ܐܢ (file_type & TCC_OUTPUT_EXE) {
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
            dynamic->sh_entsize = حجم(ElfW(Dyn));

            got_sym = build_got(s1);
            ܐܢ (file_type & TCC_OUTPUT_EXE) {
                bind_exe_dynsyms(s1, file_type & TCC_OUTPUT_DYN);
                ܐܢ (s1->nb_errors)
                    اذهب the_end;
            }
            build_got_entries(s1, got_sym);
            ܐܢ (file_type & TCC_OUTPUT_EXE) {
                bind_libs_dynsyms(s1);
            } ܐܚܪܢܐ {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
#ܐܢ TCC_EH_FRAME
	    /* fill with initial data */
	    tcc_eh_frame_hdr(s1, 0);
#endif
	    dyninf.gnu_hash = create_gnu_hash(s1);
        } ܐܚܪܢܐ {
            build_got_entries(s1, 0);
        }
	version_add (s1);

    textrel = set_sec_sizes(s1);

    ܐܢ (!s1->static_link) {
        /* add a list of needed dlls */
        لكل(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            ܐܢ (dllref->level == 0)
                put_dt(dynamic, DT_NEEDED, put_elf_str(dynstr, dllref->name));
        }

        ܐܢ (s1->rpath)
            put_dt(dynamic, s1->enable_new_dtags ? DT_RUNPATH : DT_RPATH,
                   put_elf_str(dynstr, s1->rpath));

        dt_flags_1 = DF_1_NOW;
        ܐܢ (file_type & TCC_OUTPUT_DYN) {
            ܐܢ (s1->soname)
                put_dt(dynamic, DT_SONAME, put_elf_str(dynstr, s1->soname));
            /* XXX: currently, since we do not handle PIC code, we
               must relocate the readonly segments */
            ܐܢ (textrel)
                put_dt(dynamic, DT_TEXTREL, 0);
            ܐܢ (file_type & TCC_OUTPUT_EXE)
                dt_flags_1 = DF_1_NOW | DF_1_PIE;
	    ܐܢ (s1->znodelete)
		dt_flags_1 |= DF_1_NODELETE;
        }
        put_dt(dynamic, DT_FLAGS, DF_BIND_NOW);
        put_dt(dynamic, DT_FLAGS_1, dt_flags_1);
        ܐܢ (s1->symbolic)
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
    sec_order = tcc_malloc(حجم(صحيح) * 2 * s1->nb_sections);
    /* compute section to program header mapping */
    layout_sections(s1, sec_order, &dyninf);

        ܐܢ (dynamic) {
            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->data, dynamic->sh_addr);
            ܐܢ (file_type == TCC_OUTPUT_EXE
                || (RELOCATE_DLLPLT && (file_type & TCC_OUTPUT_DYN)))
                relocate_plt(s1);
            /* relocate symbols in .dynsym now that final addresses are known */
            relocate_syms(s1, s1->dynsym, 2);
        }

        /* if building executable or DLL, then relocate each section
           except the GOT which is already relocated */
        relocate_syms(s1, s1->symtab, 0);
        ܐܢ (s1->nb_errors != 0)
            اذهب the_end;
        relocate_sections(s1);
        ܐܢ (dynamic) {
	    update_reloc_sections (s1, &dyninf);
            dynamic->data_offset = dyninf.data_offset;
            fill_dynamic(s1, &dyninf);
	}
        /* Perform relocation to GOT or PLT entries */
        ܐܢ (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        ܐܚܪܢܐ ܐܢ (s1->got)
            fill_local_got_entries(s1);

    ܐܢ (dyninf.gnu_hash)
        update_gnu_hash(s1, dyninf.gnu_hash);

    reorder_sections(s1, sec_order);
#ܐܢ TCC_EH_FRAME
    /* fill with final data */
    tcc_eh_frame_hdr(s1, 1);
#endif
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, dyninf.phnum, dyninf.phdr);
 the_end:
    tcc_free(sec_order);
    tcc_free(dyninf.phdr);
    ܦܢܐ ret;
}
#endif /* ndef ELF_OBJ_ONLY */

/* Allocate strings for section names */
ساكن فراغ alloc_sec_names(TCCState *s1, صحيح is_obj)
{
    صحيح i;
    Section *s, *strsec;

    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ܐܢ (is_obj)
            s->sh_size = s->data_offset;
	ܐܢ (s->sh_size || s == strsec || (s->sh_flags & SHF_ALLOC) || is_obj)
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_size = strsec->data_offset;
}

/* Output an elf .o file */
ساكن صحيح elf_output_obj(TCCState *s1, ثابت حرف *filename)
{
    Section *s;
    صحيح i, ret, file_offset;
    /* Allocate strings for section names */
    alloc_sec_names(s1, 1);
    file_offset = (حجم (ElfW(Ehdr)) + 3) & -4;
    file_offset += s1->nb_sections * حجم(ElfW(Shdr));
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        file_offset = (file_offset + 15) & -16;
        s->sh_offset = file_offset;
        ܐܢ (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_size;
    }
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, 0, عدم);
    ܦܢܐ ret;
}

LIBTCCAPI صحيح tcc_output_file(TCCState *s, ثابت حرف *filename)
{
    s->nb_errors = 0;
    ܐܢ (s->test_coverage)
        tcc_tcov_add_file(s, filename);
    ܐܢ (s->output_type == TCC_OUTPUT_OBJ)
        ܦܢܐ elf_output_obj(s, filename);
#ifdef TCC_TARGET_PE
    ܦܢܐ  pe_output_file(s, filename);
#وإلاإذا defined TCC_TARGET_MACHO
    ܦܢܐ macho_output_file(s, filename);
#ܐܚܪܢܐ
    ܦܢܐ elf_output_file(s, filename);
#endif
}

ST_FUNC ssize_t full_read(صحيح fd, فراغ *buf, size_t count) {
    حرف *cbuf = buf;
    size_t rnum = 0;
    ܟܡܐ (1) {
        ssize_t num = اقرأ(fd, cbuf, count-rnum);
        ܐܢ (num < 0) ܦܢܐ num;
        ܐܢ (num == 0) ܦܢܐ rnum;
        rnum += num;
        cbuf += num;
    }
}

ST_FUNC فراغ *load_data(صحيح fd, unsigned long file_offset, unsigned long size)
{
    فراغ *data;

    data = tcc_malloc(size);
    lseek(fd, file_offset, SEEK_SET);
    full_read(fd, data, size);
    ܦܢܐ data;
}

تعريفنوع بنية SectionMergeInfo {
    Section *s;            /* corresponding existing section */
    unsigned long offset;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} SectionMergeInfo;

ST_FUNC صحيح tcc_object_type(صحيح fd, ElfW(Ehdr) *h)
{
    صحيح size = full_read(fd, h, حجم *h);
    ܐܢ (size == حجم *h && 0 == memcmp(h, ELFMAG, 4)) {
        ܐܢ (h->e_type == ET_REL)
            ܦܢܐ AFF_BINTYPE_REL;
        ܐܢ (h->e_type == ET_DYN)
            ܦܢܐ AFF_BINTYPE_DYN;
    } ܐܚܪܢܐ ܐܢ (size >= 8) {
        ܐܢ (0 == memcmp(h, ARMAG, 8))
            ܦܢܐ AFF_BINTYPE_AR;
#ifdef TCC_TARGET_COFF
        ܐܢ (((بنية filehdr*)h)->f_magic == COFF_C67_MAGIC)
            ܦܢܐ AFF_BINTYPE_C67;
#endif
    }
    ܦܢܐ 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC صحيح tcc_load_object_file(TCCState *s1,
                                صحيح fd, unsigned long file_offset)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    unsigned long size, offset, offseti;
    صحيح i, j, nb_syms, sym_index, ret, seencompressed;
    حرف *strsec, *strtab;
    صحيح stab_index, stabstr_index;
    صحيح *old_to_new_syms;
    حرف *sh_name, *name;
    SectionMergeInfo *sm_table, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    lseek(fd, file_offset, SEEK_SET);
    ܐܢ (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        اذهب invalid;
    /* test CPU specific stuff */
    ܐܢ (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
invalid:
        ܦܢܐ tcc_error_noabort("invalid object file");
    }
    /* read sections */
    shdr = load_data(fd, file_offset + ehdr.e_shoff,
                     حجم(ElfW(Shdr)) * ehdr.e_shnum);
    sm_table = tcc_mallocz(حجم(SectionMergeInfo) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);

    /* load symtab and strtab */
    old_to_new_syms = عدم;
    symtab = عدم;
    strtab = عدم;
    nb_syms = 0;
    seencompressed = 0;
    stab_index = stabstr_index = 0;
    ret = -1;

    لكل(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        ܐܢ (sh->sh_type == SHT_SYMTAB) {
            ܐܢ (symtab) {
                tcc_error_noabort("object must contain only one symtab");
                اذهب the_end;
            }
            nb_syms = sh->sh_size / حجم(ElfW(Sym));
            symtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
            sm_table[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
        }
	ܐܢ (sh->sh_flags & SHF_COMPRESSED)
	    seencompressed = 1;
    }

    /* now examine each section and try to merge its content with the
       ones in memory */
    لكل(i = 1; i < ehdr.e_shnum; i++) {
        /* no need to examine section name strtab */
        ܐܢ (i == ehdr.e_shstrndx)
            استمر;
        sh = &shdr[i];
	ܐܢ (sh->sh_type == SHT_RELX)
	  sh = &shdr[sh->sh_info];
        /* ignore sections types we do not handle (plus relocs to those) */
        sh_name = strsec + sh->sh_name;
        ܐܢ (0 == strncmp(sh_name, ".debug_", 7)
         || 0 == strncmp(sh_name, ".stab", 5)) {
	    ܐܢ (!s1->do_debug || seencompressed)
	        استمر;
#ܐܢ !(TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD)
        } ܐܚܪܢܐ ܐܢ (0 == strncmp(sh_name, ".eh_frame", 9)) {
            ܐܢ (عدم == eh_frame_section)
                استمر;
#endif
        } ܐܚܪܢܐ
        ܐܢ (sh->sh_type != SHT_PROGBITS &&
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

#ܐܢ TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD
            && sh->sh_type != SHT_X86_64_UNWIND
#endif
            )
            استمر;

	sh = &shdr[i];
        sh_name = strsec + sh->sh_name;
        ܐܢ (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        /* find corresponding section, if any */
        لكل(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            ܐܢ (strcmp(s->name, sh_name))
                استمر;
            ܐܢ (sh->sh_type != s->sh_type
                && strcmp (s->name, ".eh_frame")
                /* some crt1.o seem to have two ".note.GNU-stack" (SHT_NOTE & SHT_PROGBITS) */
                && strcmp (s->name, ".note.GNU-stack")
                ) {
                tcc_error_noabort("section type conflict: %s %02x <> %02x", s->name, sh->sh_type, s->sh_type);
                اذهب the_end;
            }
            ܐܢ (!strncmp(sh_name, ".gnu.linkonce", 13)) {
                /* if a 'linkonce' section is already present, we
                   do not add it again. It is a little tricky as
                   symbols can still be defined in
                   it. */
                sm_table[i].link_once = 1;
                اذهب next;
            }
            ܐܢ (stab_section) {
                ܐܢ (s == stab_section)
                    stab_index = i;
                ܐܢ (s == stab_section->link)
                    stabstr_index = i;
            }
            اذهب found;
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
        ܐܢ (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        sm_table[i].offset = offset;
        sm_table[i].s = s;
        /* concatenate sections */
        ܐܢ (sh->sh_type != SHT_NOBITS && size) {
            unsigned حرف *ptr;
            lseek(fd, file_offset + sh->sh_offset, SEEK_SET);
            ptr = s->data + offset;
            full_read(fd, ptr, size);
        }
#ܐܢ defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
        /* align code sections to instruction lenght */
        /* This is needed if we compile a c file after this */
        ܐܢ (s->sh_flags & SHF_EXECINSTR)
            section_add(s, 0, 4);
#endif
    next: ;
    }

    /* gr relocate stab strings */
    ܐܢ (stab_index && stabstr_index) {
        Stab_Sym *a, *b;
        unsigned o;
        s = sm_table[stab_index].s;
        a = (Stab_Sym *)(s->data + sm_table[stab_index].offset);
        b = (Stab_Sym *)(s->data + s->data_offset);
        o = sm_table[stabstr_index].offset;
        ܟܡܐ (a < b) {
            ܐܢ (a->n_strx)
                a->n_strx += o;
            a++;
        }
    }

    /* second short pass to update sh_link and sh_info fields of new
       sections */
    لكل(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        ܐܢ (!s || !sm_table[i].new_section)
            استمر;
        sh = &shdr[i];
        ܐܢ (sh->sh_link > 0)
            s->link = sm_table[sh->sh_link].s;
        ܐܢ (sh->sh_type == SHT_RELX) {
            s->sh_info = sm_table[sh->sh_info].s->sh_num;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }

    ܐܢ (!symtab)
        اذهب done;

    /* resolve symbols */
    old_to_new_syms = tcc_mallocz(nb_syms * حجم(صحيح));

    sym = symtab + 1;
    لكل(i = 1; i < nb_syms; i++, sym++) {
        ܐܢ (sym->st_shndx != SHN_UNDEF &&
            sym->st_shndx < SHN_LORESERVE) {
            sm = &sm_table[sym->st_shndx];
            ܐܢ (sm->link_once) {
                /* if a symbol is in a link once section, we use the
                   already defined symbol. It is very important to get
                   correct relocations */
                ܐܢ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
                    name = strtab + sym->st_name;
                    sym_index = find_elf_sym(symtab_section, name);
                    ܐܢ (sym_index)
                        old_to_new_syms[i] = sym_index;
                }
                استمر;
            }
            /* if no corresponding section added, no need to add symbol */
            ܐܢ (!sm->s)
                استمر;
            /* convert section number */
            sym->st_shndx = sm->s->sh_num;
            /* offset value */
            sym->st_value += sm->offset;
        }
        /* add symbol */
        name = strtab + sym->st_name;
        sym_index = set_elf_sym(symtab_section, sym->st_value, sym->st_size,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_to_new_syms[i] = sym_index;
    }

    /* third pass to patch relocation entries */
    لكل(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        ܐܢ (!s)
            استمر;
        sh = &shdr[i];
        offset = sm_table[i].offset;
        size = sh->sh_size;
        بدل(s->sh_type) {
        حالة SHT_RELX:
            /* take relocation offset information */
            offseti = sm_table[sh->sh_info].offset;
	    لكل (rel = (ElfW_Rel *) s->data + (offset / حجم(*rel));
		 rel < (ElfW_Rel *) s->data + ((offset + size) / حجم(*rel));
		 rel++) {
                صحيح type;
                unsigned sym_index;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_index = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                ܐܢ (sym_index >= nb_syms)
                    اذهب invalid_reloc;
                sym_index = old_to_new_syms[sym_index];
                /* ignore link_once in rel section. */
                ܐܢ (!sym_index && !sm_table[sh->sh_info].link_once
#ifdef TCC_TARGET_ARM
                    && type != R_ARM_V4BX
#وإلاإذا defined TCC_TARGET_RISCV64
                    && type != R_RISCV_ALIGN
                    && type != R_RISCV_RELAX
#endif
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, (صحيح)rel->r_offset);
                    اذهب the_end;
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
                ܐܢ (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_index, 1)->plt_thumb_stub = 1;
#endif
            }
            اكسر;
        افتراضي:
            اكسر;
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
    ܦܢܐ ret;
}

تعريفنوع بنية ArchiveHeader {
    حرف ar_name[16];           /* name of this member */
    حرف ar_date[12];           /* file mtime */
    حرف ar_uid[6];             /* owner uid; printed as decimal */
    حرف ar_gid[6];             /* owner gid; printed as decimal */
    حرف ar_mode[8];            /* file mode, printed as octal   */
    حرف ar_size[10];           /* file size, printed as decimal */
    حرف ar_fmag[2];            /* should contain ARFMAG */
} ArchiveHeader;

#define ARFMAG "`\n"

ساكن unsigned long long get_be(ثابت uint8_t *b, صحيح n)
{
    unsigned long long ret = 0;
    ܟܡܐ (n)
        ret = (ret << 8) | *b++, --n;
    ܦܢܐ ret;
}

ساكن صحيح read_ar_header(صحيح fd, صحيح offset, ArchiveHeader *hdr)
{
    حرف *p, *e;
    صحيح len;
    lseek(fd, offset, SEEK_SET);
    len = full_read(fd, hdr, حجم(ArchiveHeader));
    ܐܢ (len != حجم(ArchiveHeader))
        ܦܢܐ len ? -1 : 0;
    ܐܢ (memcmp(hdr->ar_fmag, ARFMAG, حجم hdr->ar_fmag))
        ܦܢܐ -1;
    p = hdr->ar_name;
    لكل (e = p + حجم hdr->ar_name; e > p && e[-1] == ' ';)
        --e;
    *e = '\0';
    hdr->ar_size[حجم hdr->ar_size-1] = 0;
    ܦܢܐ len;
}

/* load only the objects which resolve undefined symbols */
ساكن صحيح tcc_load_alacarte(TCCState *s1, صحيح fd, صحيح size, صحيح entrysize)
{
    صحيح i, bound, nsyms, sym_index, len, ret = -1;
    unsigned long long off;
    uint8_t *data;
    ثابت حرف *ar_names, *p;
    ثابت uint8_t *ar_index;
    ElfW(Sym) *sym;
    ArchiveHeader hdr;

    data = tcc_malloc(size);
    ܐܢ (full_read(fd, data, size) != size)
        اذهب invalid;
    nsyms = get_be(data, entrysize);
    ar_index = data + entrysize;
    ar_names = (حرف *) ar_index + nsyms * entrysize;

    ܥܒܕ {
        bound = 0;
        لكل (p = ar_names, i = 0; i < nsyms; i++, p += strlen(p)+1) {
            Section *s = symtab_section;
            sym_index = find_elf_sym(s, p);
            ܐܢ (!sym_index)
                استمر;
            sym = &((ElfW(Sym) *)s->data)[sym_index];
            ܐܢ(sym->st_shndx != SHN_UNDEF)
                استمر;
            off = get_be(ar_index + i * entrysize, entrysize);
            len = read_ar_header(fd, off, &hdr);
            ܐܢ (len <= 0 || memcmp(hdr.ar_fmag, ARFMAG, 2)) {
        invalid:
                tcc_error_noabort("invalid archive");
                اذهب the_end;
            }
            off += len;
            ܐܢ (s1->verbose == 2)
                printf("   -> %s\n", hdr.ar_name);
            ܐܢ (tcc_load_object_file(s1, fd, off) < 0)
                اذهب the_end;
            ++bound;
        }
    } ܟܡܐ(bound);
    ret = 0;
 the_end:
    tcc_free(data);
    ܦܢܐ ret;
}

/* load a '.a' file */
ST_FUNC صحيح tcc_load_archive(TCCState *s1, صحيح fd, صحيح alacarte)
{
    ArchiveHeader hdr;
    /* char magic[8]; */
    صحيح size, len;
    unsigned long file_offset;
    ElfW(Ehdr) ehdr;

    /* skip magic which was already checked */
    /* full_read(fd, magic, sizeof(magic)); */
    file_offset = حجم ARMAG - 1;

    لكل(;;) {
        len = read_ar_header(fd, file_offset, &hdr);
        ܐܢ (len == 0)
            ܦܢܐ 0;
        ܐܢ (len < 0)
            ܦܢܐ tcc_error_noabort("invalid archive");
        file_offset += len;
        size = strtol(hdr.ar_size, عدم, 0);
        ܐܢ (alacarte) {
            /* coff symbol table : we handle it */
            ܐܢ (!strcmp(hdr.ar_name, "/"))
                ܦܢܐ tcc_load_alacarte(s1, fd, size, 4);
            ܐܢ (!strcmp(hdr.ar_name, "/SYM64/"))
                ܦܢܐ tcc_load_alacarte(s1, fd, size, 8);
        } ܐܚܪܢܐ ܐܢ (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
            ܐܢ (s1->verbose == 2)
                printf("   -> %s\n", hdr.ar_name);
            ܐܢ (tcc_load_object_file(s1, fd, file_offset) < 0)
                ܦܢܐ -1;
        }
        /* align to even */
        file_offset = (file_offset + size + 1) & ~1;
    }
}

#ifndef ELF_OBJ_ONLY
/* Set LV[I] to the global index of sym-version (LIB,VERSION).  Maybe resizes
   LV, maybe create a new entry for (LIB,VERSION).  */
ساكن فراغ set_ver_to_ver(TCCState *s1, صحيح *n, صحيح **lv, صحيح i, حرف *lib, حرف *version)
{
    ܟܡܐ (i >= *n) {
        *lv = tcc_realloc(*lv, (*n + 1) * حجم(**lv));
        (*lv)[(*n)++] = -1;
    }
    ܐܢ ((*lv)[i] == -1) {
        صحيح v, prev_same_lib = -1;
        لكل (v = 0; v < nb_sym_versions; v++) {
            ܐܢ (strcmp(sym_versions[v].lib, lib))
              استمر;
            prev_same_lib = v;
            ܐܢ (!strcmp(sym_versions[v].version, version))
              اكسر;
        }
        ܐܢ (v == nb_sym_versions) {
            sym_versions = tcc_realloc (sym_versions,
                                        (v + 1) * حجم(*sym_versions));
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
ساكن فراغ
set_sym_version(TCCState *s1, صحيح sym_index, صحيح verndx)
{
    ܐܢ (sym_index >= nb_sym_to_version) {
        صحيح newelems = sym_index ? sym_index * 2 : 1;
        sym_to_version = tcc_realloc(sym_to_version,
                                     newelems * حجم(*sym_to_version));
        memset(sym_to_version + nb_sym_to_version, -1,
               (newelems - nb_sym_to_version) * حجم(*sym_to_version));
        nb_sym_to_version = newelems;
    }
    ܐܢ (sym_to_version[sym_index] < 0)
      sym_to_version[sym_index] = verndx;
}

بنية versym_info {
    صحيح nb_versyms;
    ElfW(Verdef) *verdef;
    ElfW(Verneed) *verneed;
    ElfW(Half) *versym;
    صحيح nb_local_ver, *local_ver;
};


ساكن فراغ store_version(TCCState *s1, بنية versym_info *v, حرف *dynstr)
{
    حرف *lib, *version;
    uint32_t next;
    صحيح i;

#define	DEBUG_VERSION 0

    ܐܢ (v->versym && v->verdef) {
      ElfW(Verdef) *vdef = v->verdef;
      lib = عدم;
      ܥܒܕ {
        ElfW(Verdaux) *verdaux =
	  (ElfW(Verdaux) *) (((حرف *) vdef) + vdef->vd_aux);

#ܐܢ DEBUG_VERSION
	printf ("verdef: version:%u flags:%u index:%u, hash:%u\n",
	        vdef->vd_version, vdef->vd_flags, vdef->vd_ndx,
		vdef->vd_hash);
#endif
	ܐܢ (vdef->vd_cnt) {
          version = dynstr + verdaux->vda_name;

	  ܐܢ (lib == عدم)
	    lib = version;
	  ܐܚܪܢܐ
            set_ver_to_ver(s1, &v->nb_local_ver, &v->local_ver, vdef->vd_ndx,
                           lib, version);
#ܐܢ DEBUG_VERSION
	  printf ("  verdaux(%u): %s\n", vdef->vd_ndx, version);
#endif
	}
        next = vdef->vd_next;
        vdef = (ElfW(Verdef) *) (((حرف *) vdef) + next);
      } ܟܡܐ (next);
    }
    ܐܢ (v->versym && v->verneed) {
      ElfW(Verneed) *vneed = v->verneed;
      ܥܒܕ {
        ElfW(Vernaux) *vernaux =
	  (ElfW(Vernaux) *) (((حرف *) vneed) + vneed->vn_aux);

        lib = dynstr + vneed->vn_file;
#ܐܢ DEBUG_VERSION
	printf ("verneed: %u %s\n", vneed->vn_version, lib);
#endif
	لكل (i = 0; i < vneed->vn_cnt; i++) {
	  ܐܢ ((vernaux->vna_other & 0x8000) == 0) { /* hidden */
              version = dynstr + vernaux->vna_name;
              set_ver_to_ver(s1, &v->nb_local_ver, &v->local_ver, vernaux->vna_other,
                             lib, version);
#ܐܢ DEBUG_VERSION
	    printf ("  vernaux(%u): %u %u %s\n",
		    vernaux->vna_other, vernaux->vna_hash,
		    vernaux->vna_flags, version);
#endif
	  }
	  vernaux = (ElfW(Vernaux) *) (((حرف *) vernaux) + vernaux->vna_next);
	}
        next = vneed->vn_next;
        vneed = (ElfW(Verneed) *) (((حرف *) vneed) + next);
      } ܟܡܐ (next);
    }

#ܐܢ DEBUG_VERSION
    لكل (i = 0; i < v->nb_local_ver; i++) {
      ܐܢ (v->local_ver[i] > 0) {
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
ST_FUNC صحيح tcc_load_dll(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    صحيح i, nb_syms, nb_dts, sym_bind, ret = -1;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;

    حرف *dynstr;
    صحيح sym_index;
    ثابت حرف *name, *soname;
    بنية versym_info v;

    full_read(fd, &ehdr, حجم(ehdr));

    /* test CPU specific stuff */
    ܐܢ (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
        ܦܢܐ tcc_error_noabort("bad architecture");
    }

    /* read sections */
    shdr = load_data(fd, ehdr.e_shoff, حجم(ElfW(Shdr)) * ehdr.e_shnum);

    /* load dynamic section and dynamic symbols */
    nb_syms = 0;
    nb_dts = 0;
    dynamic = عدم;
    dynsym = عدم; /* avoid warning */
    dynstr = عدم; /* avoid warning */
    memset(&v, 0, حجم v);

    لكل(i = 0, sh = shdr; i < ehdr.e_shnum; i++, sh++) {
        بدل(sh->sh_type) {
        حالة SHT_DYNAMIC:
            nb_dts = sh->sh_size / حجم(ElfW(Dyn));
            dynamic = load_data(fd, sh->sh_offset, sh->sh_size);
            اكسر;
        حالة SHT_DYNSYM:
            nb_syms = sh->sh_size / حجم(ElfW(Sym));
            dynsym = load_data(fd, sh->sh_offset, sh->sh_size);
            sh1 = &shdr[sh->sh_link];
            dynstr = load_data(fd, sh1->sh_offset, sh1->sh_size);
            اكسر;
        حالة SHT_GNU_verdef:
	    v.verdef = load_data(fd, sh->sh_offset, sh->sh_size);
	    اكسر;
        حالة SHT_GNU_verneed:
	    v.verneed = load_data(fd, sh->sh_offset, sh->sh_size);
	    اكسر;
        حالة SHT_GNU_versym:
            v.nb_versyms = sh->sh_size / حجم(ElfW(Half));
	    v.versym = load_data(fd, sh->sh_offset, sh->sh_size);
	    اكسر;
        افتراضي:
            اكسر;
        }
    }

    ܐܢ (!dynamic)
        اذهب the_end;

    /* compute the real library name */
    soname = tcc_basename(filename);
    لكل(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        ܐܢ (dt->d_tag == DT_SONAME)
            soname = dynstr + dt->d_un.d_val;

    /* if the dll is already loaded, do not load it */
    ܐܢ (tcc_add_dllref(s1, soname, level)->found)
        اذهب ret_success;

    ܐܢ (v.nb_versyms != nb_syms)
        tcc_free (v.versym), v.versym = عدم;
    ܐܚܪܢܐ
        store_version(s1, &v, dynstr);

    /* add dynamic symbols in dynsym_section */
    لكل(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        ܐܢ (sym_bind == STB_LOCAL)
            استمر;
        name = dynstr + sym->st_name;
        sym_index = set_elf_sym(s1->dynsymtab_section, sym->st_value, sym->st_size,
                                sym->st_info, sym->st_other, sym->st_shndx, name);
        ܐܢ (v.versym) {
            ElfW(Half) vsym = v.versym[i];
            ܐܢ ((vsym & 0x8000) == 0 && vsym > 0 && vsym < v.nb_local_ver)
                set_sym_version(s1, sym_index, v.local_ver[vsym]);
        }
    }

    /* do not load all referenced libraries
       (recursive loading can break linking of libraries) */
    /* following DT_NEEDED is needed for the dynamic loader (libdl.so),
       but it is no longer needed, when linking a library or a program.
       When tcc output mode is OUTPUT_MEM,
       tcc calls dlopen, which handles DT_NEEDED for us */

#ܐܢ 0
    لكل(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        ܐܢ (dt->d_tag == DT_RPATH)
            tcc_add_library_path(s1, dynstr + dt->d_un.d_val);

    /* load all referenced DLLs */
    لكل(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        بدل(dt->d_tag) {
        حالة DT_NEEDED:
            name = dynstr + dt->d_un.d_val;
            ܐܢ (tcc_add_dllref(s1, name, -1))
                استمر;
            ܐܢ (tcc_add_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                ret = tcc_error_noabort("referenced dll '%s' not found", name);
                اذهب the_end;
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
    ܦܢܐ ret;
}

#define LD_TOK_NAME 256
#define LD_TOK_EOF  (-1)
ساكن صحيح ld_inp(TCCState *s1)
{
    صحيح c = *s1->ld_p;
    ܐܢ (c == 0)
        ܦܢܐ CH_EOF;
    ++s1->ld_p;
    ܦܢܐ c;
}
#define ld_unget(s1, ch) ܐܢ (ch != CH_EOF) --s1->ld_p

/* return next ld script token */
ساكن صحيح ld_next(TCCState *s1, حرف *name, صحيح name_size)
{
    صحيح c, d, ch;
    حرف *q;

 redo:
    ch = ld_inp(s1);
    q = name, *q++ = ch;
    بدل(ch) {
    حالة ' ':
    حالة '\t':
    حالة '\f':
    حالة '\v':
    حالة '\r':
    حالة '\n':
        اذهب redo;
    حالة '/':
        ch = ld_inp(s1);
        ܐܢ (ch == '*') { /* comment */
            لكل (d = 0;; d = ch) {
                ch = ld_inp(s1);
                ܐܢ (ch == CH_EOF || (ch == '/' && d == '*'))
                    اكسر;
            }
            اذهب redo;
        } ܐܚܪܢܐ {
            اذهب parse_name;
        }
        اكسر;
    حالة '\\':
    /* case 'a' ... 'z': */
    حالة 'a':
       حالة 'b':
       حالة 'c':
       حالة 'd':
       حالة 'e':
       حالة 'f':
       حالة 'g':
       حالة 'h':
       حالة 'i':
       حالة 'j':
       حالة 'k':
       حالة 'l':
       حالة 'm':
       حالة 'n':
       حالة 'o':
       حالة 'p':
       حالة 'q':
       حالة 'r':
       حالة 's':
       حالة 't':
       حالة 'u':
       حالة 'v':
       حالة 'w':
       حالة 'x':
       حالة 'y':
       حالة 'z':
    /* case 'A' ... 'z': */
    حالة 'A':
       حالة 'B':
       حالة 'C':
       حالة 'D':
       حالة 'E':
       حالة 'F':
       حالة 'G':
       حالة 'H':
       حالة 'I':
       حالة 'J':
       حالة 'K':
       حالة 'L':
       حالة 'M':
       حالة 'N':
       حالة 'O':
       حالة 'P':
       حالة 'Q':
       حالة 'R':
       حالة 'S':
       حالة 'T':
       حالة 'U':
       حالة 'V':
       حالة 'W':
       حالة 'X':
       حالة 'Y':
       حالة 'Z':
    حالة '-':
    حالة '_':
    حالة '.':
    حالة '$':
    حالة '~':
        لكل(;;) {
            ch = ld_inp(s1);
    parse_name:
            ܐܢ (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') ||
                  strchr("/.-_+=$:\\,~", ch)))
                اكسر;
            ܐܢ ((q - name) < name_size - 1) {
                *q++ = ch;
            }
        }
        ld_unget(s1, ch);
        c = LD_TOK_NAME;
        اكسر;
    حالة CH_EOF:
        c = LD_TOK_EOF;
        اكسر;
    افتراضي:
        c = ch;
        اكسر;
    }
    *q = '\0';
    ܦܢܐ c;
}

ساكن صحيح ld_add_file(TCCState *s1, ثابت حرف filename[])
{
    ܐܢ (filename[0] == '-' && filename[1] == 'l')
        ܦܢܐ tcc_add_library(s1, filename + 2);
    ܐܢ (CONFIG_SYSROOT[0] != '\0' || !IS_ABSPATH(filename)) {
        /* lookup via library paths */
        صحيح ret = tcc_add_dll(s1, tcc_basename(filename), 0);
        ܐܢ (ret != FILE_NOT_FOUND)
            ܦܢܐ ret;
    }
    ܦܢܐ tcc_add_file_internal(s1, filename, AFF_PRINT_ERROR);
}

/* did static libraries add new undefined symbols? */
ساكن صحيح new_undef_sym(TCCState *s1, صحيح sym_offset)
{
    ܟܡܐ (sym_offset < s1->symtab->data_offset) {
        ElfW(Sym) *esym = (فراغ*)(s1->symtab->data + sym_offset);
        ܐܢ (esym->st_shndx == SHN_UNDEF)
            ܦܢܐ 1;
        sym_offset += حجم (ElfW(Sym));
    }
    ܦܢܐ 0;
}

ساكن صحيح ld_add_file_list(TCCState *s1, ثابت حرف *cmd)
{
    حرف filename[1024];
    صحيح t, c, sym_offset, ret = 0;
    unsigned حرف *pos = s1->ld_p;

repeat:
    s1->ld_p = pos;
    sym_offset = s1->symtab->data_offset;
    c = cmd[0];

    t = ld_next(s1, filename, حجم(filename));
    ܐܢ (t != '(')
        ܦܢܐ tcc_error_noabort("expected '(' after %s", cmd);
    t = ld_next(s1, filename, حجم(filename));
    لكل(;;) {
        ܐܢ (t == LD_TOK_EOF) {
            ܦܢܐ tcc_error_noabort("unexpected end of file");
        } ܐܚܪܢܐ ܐܢ (t == ')') {
            اكسر;
        } ܐܚܪܢܐ ܐܢ (t != LD_TOK_NAME) {
            ܦܢܐ tcc_error_noabort("unexpected token '%c'", t);
        } ܐܚܪܢܐ ܐܢ (!strcmp(filename, "AS_NEEDED")) {
            ret |= ld_add_file_list(s1, filename);
        } ܐܚܪܢܐ ܐܢ (c == 'I' || c == 'G' || c == 'A') {
            ret |= !!ld_add_file(s1, filename);
        }
        ܐܢ (ret < 0)
            ܦܢܐ ret;
        t = ld_next(s1, filename, حجم(filename));
        ܐܢ (t == ',')
            t = ld_next(s1, filename, حجم(filename));
    }
    ܐܢ (c == 'G' && ret == 0 && new_undef_sym(s1, sym_offset))
        اذهب repeat;
    ܦܢܐ ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC صحيح tcc_load_ldscript(TCCState *s1, صحيح fd)
{
    حرف cmd[64];
    صحيح t, ret = 0, noscript = 1;
    unsigned حرف *text_ptr, *saved_ptr;

    saved_ptr = s1->ld_p;
    s1->ld_p = text_ptr = (فراغ*)tcc_load_text(fd);
    لكل(;;) {
        t = ld_next(s1, cmd, حجم(cmd));
        ܐܢ (t == LD_TOK_EOF)
            اكسر;
        ܐܢ (!strcmp(cmd, "INPUT") ||
            !strcmp(cmd, "GROUP")) {
            ret |= ld_add_file_list(s1, cmd);
        } ܐܚܪܢܐ ܐܢ (!strcmp(cmd, "OUTPUT_FORMAT") ||
                   !strcmp(cmd, "TARGET")) {
            /* ignore some commands */
            ret |= ld_add_file_list(s1, cmd);
        } ܐܚܪܢܐ ܐܢ (noscript) {
            ret = FILE_NOT_RECOGNIZED;
        } ܐܚܪܢܐ {
            ret = tcc_error_noabort("unexpected '%s'", cmd);
        }
        ܐܢ (ret < 0)
            اكسر;
        noscript = 0;
    }
    tcc_free(text_ptr);
    s1->ld_p = saved_ptr;
    ܦܢܐ ret < 0 ? ret : -ret;
}
#endif /* !ELF_OBJ_ONLY */
