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

#شامل "tcc.h"

/* Define this to get some debug output during relocation processing.  */
#تعریف_منسوخ DEBUG_RELOC

/********************************************************/
/* global variables */

/* elf version information */
ساخت sym_نسخہ {
    حرف *lib;
    حرف *نسخہ;
    صحیح برآمد_اشاریہ;
    صحیح پچھلا_same_lib;
};

#تعریف_کرو nb_sym_versions     s1->nb_sym_versions
#تعریف_کرو sym_versions        s1->sym_versions
#تعریف_کرو nb_sym_مقصد_نسخہ   s1->nb_sym_مقصد_نسخہ
#تعریف_کرو sym_مقصد_نسخہ      s1->sym_مقصد_نسخہ
#تعریف_کرو dt_verneednum       s1->dt_verneednum
#تعریف_کرو versym_section      s1->versym_section
#تعریف_کرو verneed_section     s1->verneed_section

/* special flag to indicate that the section should not be linked to the other ones */
#تعریف_کرو SHF_نجی 0x80000000
/* section is dynsymtab_section */
#تعریف_کرو SHF_DYNSYM 0x40000000

#اگر_تعریف_شدہ TCC_ہدف_PE
#تعریف_کرو shf_RELRO SHF_ALLOC
ساکن ثابت حرف rdata[] = ".rdata";
#ورنہ
#تعریف_کرو shf_RELRO SHF_ALLOC /* eventually made SHF_WRITE in sort_sections() */
ساکن ثابت حرف rdata[] = ".data.ro";
#اگر_ختم

/* ------------------------------------------------------------------------- */

ST_FUNC خالی tccelf_new(TCCState *s)
{
    TCCState *s1 = s;

    /* no section zero */
    dynarray_جوڑو(&s->sections, &s->nb_sections, تہی);

    /* create standard sections */
    متن_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    ڈیٹا_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    /* create ro data section (make ro after relocation done with GNU_RELRO) */
    rodata_section = new_section(s, rdata, SHT_PROGBITS, shf_RELRO);
    bss_section = new_section(s, ".bss", SHT_NOBITS, SHF_ALLOC | SHF_WRITE);
    common_section = new_section(s, ".common", SHT_NOBITS, SHF_نجی);
    common_section->sh_عدد = SHN_COMMON;

    /* symbols are always generated for linking stage */
    symtab_section = new_symtab(s, ".symtab", SHT_SYMTAB, 0,
                                ".strtab",
                                ".hashtab", SHF_نجی);

    /* private symbol table for dynamic symbols */
    s->dynsymtab_section = new_symtab(s, ".dynsymtab", SHT_SYMTAB, SHF_نجی|SHF_DYNSYM,
                                      ".dynstrtab",
                                      ".dynhashtab", SHF_نجی);
    get_sym_attr(s, 0, 1);

    اگر (s->do_debug) {
        /* add debug sections */
        tcc_debug_new(s);
    }

#اگر TCC_EH_چوکھٹا
    اگر (s->output_format != TCC_OUTPUT_FORMAT_ELF)
        s->unwind_tables = 0;
    tcc_eh_چوکھٹا_آغاز(s);
#اگر_ختم

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        /* (make ro after relocation done with GNU_RELRO) */
        bounds_section = new_section(s, ".bounds", SHT_PROGBITS, shf_RELRO);
        lbounds_section = new_section(s, ".lbounds", SHT_PROGBITS, shf_RELRO);
    }
#اگر_ختم

#اگر_تعریف_شدہ TCC_ہدف_PE
    /* to make sure that -ltcc1 -Wl,-e,_start will grab the startup code
       from libtcc1.a (unless _start defined) */
    اگر (s->elf_entryname)
        سیٹ_global_sym(s, s->elf_entryname, تہی, 0); /* SHN_UNDEF */
#اگر_ختم

#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
    اگر (تہی == s->elfint && s1->output_type != TCC_OUTPUT_OBJ) {
        ثابت حرف *p = CONFIG_TCC_ELFINTERP;
#اگر defined TCC_ہدف_ARM && defined CONFIG_TCC_ELFINTERP_ARMHF
        اگر (s->float_abi == ARM_HARD_FLOAT)
            p = CONFIG_TCC_ELFINTERP_ARMHF;
#اگر_ختم
#اگر defined TCC_IS_NATIVE && defined TARGETOS_BSD
        /* see commit 55cb2170cd5ce77a7d76dcaf462fad2707281605 */
        { ثابت حرف *e = getenv("LD_SO"); اگر (e) p = e; }
#اگر_ختم
        s->elfint = tcc_strdup(p);
    }
#اگر_ختم /* ndef ELF_OBJ_ONLY */
}

ST_FUNC خالی free_section(Section *s)
{
    اگر (!s)
        واپس;
    tcc_free(s->ڈیٹا);
    s->ڈیٹا = تہی;
    s->ڈیٹا_allocated = s->ڈیٹا_انحراف = 0;
}

ST_FUNC خالی tccelf_delete(TCCState *s1)
{
    صحیح i;

#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
    /* free symbol versions */
    برائے (i = 0; i < nb_sym_versions; i++) {
        tcc_free(sym_versions[i].نسخہ);
        tcc_free(sym_versions[i].lib);
    }
    tcc_free(sym_versions);
    tcc_free(sym_مقصد_نسخہ);
#اگر_ختم

    /* free all sections */
    برائے(i = 1; i < s1->nb_sections; i++)
        free_section(s1->sections[i]);
    dynarray_reset(&s1->sections, &s1->nb_sections);

    برائے(i = 0; i < s1->nb_priv_sections; i++)
        free_section(s1->priv_sections[i]);
    dynarray_reset(&s1->priv_sections, &s1->nb_priv_sections);

    tcc_free(s1->sym_attrs);
    symtab_section = تہی; /* for tccrun.c:rt_printline() */
}

/* save section data state */
ST_FUNC خالی tccelf_begin_file(TCCState *s1)
{
    Section *s; صحیح i;
    برائے (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        s->sh_انحراف = s->ڈیٹا_انحراف;
    }
    /* disable symbol hashing during compilation */
    s = s1->symtab, s->reloc = s->hash, s->hash = تہی;
#اگر defined TCC_ہدف_X86_64 && defined TCC_ہدف_PE
    s1->uw_sym = 0;
    s1->uw_offs = 0;
#اگر_ختم
}

ساکن خالی update_relocs(TCCState *s1, Section *s, صحیح *old_مقصد_new_syms, صحیح پہلا_sym);

/* At the end of compilation, convert any UNDEF syms to global, and merge
   with previously existing symbols */
ST_FUNC خالی tccelf_انتہا_file(TCCState *s1)
{
    Section *s = s1->symtab;
    صحیح پہلا_sym, nb_syms, *tr, i;

    پہلا_sym = s->sh_انحراف / حجم (ElfSym);
    nb_syms = s->ڈیٹا_انحراف / حجم (ElfSym) - پہلا_sym;
    s->ڈیٹا_انحراف = s->sh_انحراف;
    s->link->ڈیٹا_انحراف = s->link->sh_انحراف;
    s->hash = s->reloc, s->reloc = تہی;
    tr = tcc_mallocz(nb_syms * حجم *tr);

    برائے (i = 0; i < nb_syms; ++i) {
        ElfSym *sym = (ElfSym*)s->ڈیٹا + پہلا_sym + i;
        اگر (sym->st_shndx == SHN_UNDEF) {
            صحیح sym_bind = ELFW(ST_BIND)(sym->st_info);
            صحیح sym_type = ELFW(ST_TYPE)(sym->st_info);
            اگر (sym_bind == STB_LOCAL)
                sym_bind = STB_GLOBAL;
#اگر_غیر_تعریف_شدہ TCC_ہدف_PE
            اگر (sym_bind == STB_GLOBAL && s1->output_type == TCC_OUTPUT_OBJ) {
                /* undefined symbols with STT_FUNC are confusing gnu ld when
                   linking statically to STT_GNU_IFUNC.  Keep TLS typed,
                   otherwise gnu ld rejects non-TLS refs to TLS definitions. */
                اگر (sym_type != STT_TLS)
                    sym_type = STT_NOTYPE;
            }
#اگر_ختم
            sym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
        }
        tr[i] = سیٹ_elf_sym(s, sym->st_قدر, sym->st_سائز, sym->st_info,
            sym->st_other, sym->st_shndx, (حرف*)s->link->ڈیٹا + sym->st_name);
    }
    /* now update relocations */
    update_relocs(s1, s, tr, پہلا_sym);
    tcc_free(tr);
    /* record text/data/bss output for -bench info */
    برائے (i = 0; i < 4; ++i) {
        s = s1->sections[i + 1];
        s1->کل_output[i] += s->ڈیٹا_انحراف - s->sh_انحراف;
    }
}

ST_FUNC Section *new_section(TCCState *s1, ثابت حرف *name, صحیح sh_type, صحیح sh_flags)
{
    Section *sec;

    sec = tcc_mallocz(حجم(Section) + لڑی_لمبائی(name));
    sec->s1 = s1;
    strcpy(sec->name, name);
    sec->sh_type = sh_type;
    sec->sh_flags = sh_flags;
    انتخاب(sh_type) {
    حالت SHT_GNU_versym:
        sec->sh_addralign = 2;
        توڑو;
    حالت SHT_HASH:
    حالت SHT_GNU_HASH:
    حالت SHT_REL:
    حالت SHT_RELA:
    حالت SHT_DYNSYM:
    حالت SHT_SYMTAB:
    حالت SHT_DYNAMIC:
    حالت SHT_GNU_verneed:
    حالت SHT_GNU_verdef:
        sec->sh_addralign = PTR_سائز;
        توڑو;
    حالت SHT_STRTAB:
        sec->sh_addralign = 1;
        توڑو;
    طےشدہ:
        sec->sh_addralign =  PTR_سائز; /* gcc/pcc default alignment */
        توڑو;
    }

    اگر (sh_flags & SHF_نجی) {
        dynarray_جوڑو(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } ورنہ {
        sec->sh_عدد = s1->nb_sections;
        dynarray_جوڑو(&s1->sections, &s1->nb_sections, sec);
    }

    واپس sec;
}

ST_FUNC خالی init_symtab(Section *s)
{
    صحیح *ptr, nb_buckets = 1;
    put_elf_str(s->link, "");
    section_ptr_جوڑو(s, حجم (ElfW(Sym)));
    ptr = section_ptr_جوڑو(s->hash, (2 + nb_buckets + 1) * حجم(صحیح));
    ptr[0] = nb_buckets;
    ptr[1] = 1;
    memset(ptr + 2, 0, (nb_buckets + 1) * حجم(صحیح));
}

ST_FUNC Section *new_symtab(TCCState *s1,
                           ثابت حرف *symtab_name, صحیح sh_type, صحیح sh_flags,
                           ثابت حرف *strtab_name,
                           ثابت حرف *hash_name, صحیح hash_sh_flags)
{
    Section *symtab, *strtab, *hash;
    symtab = new_section(s1, symtab_name, sh_type, sh_flags);
    symtab->sh_entsize = حجم(ElfW(Sym));
    strtab = new_section(s1, strtab_name, SHT_STRTAB, sh_flags);
    symtab->link = strtab;
    hash = new_section(s1, hash_name, SHT_HASH, hash_sh_flags);
    hash->sh_entsize = حجم(صحیح);
    symtab->hash = hash;
    hash->link = symtab;
    init_symtab(symtab);
    واپس symtab;
}

/* realloc section and set its content to zero */
ST_FUNC خالی section_realloc(Section *sec, غیرعلامتی طویل new_سائز)
{
    غیرعلامتی طویل سائز;
    غیرعلامتی حرف *ڈیٹا;

    سائز = sec->ڈیٹا_allocated;
    اگر (سائز == 0)
        سائز = 1;
    جب (سائز < new_سائز)
        سائز = سائز * 2;
    ڈیٹا = tcc_realloc(sec->ڈیٹا, سائز);
    memset(ڈیٹا + sec->ڈیٹا_allocated, 0, سائز - sec->ڈیٹا_allocated);
    sec->ڈیٹا = ڈیٹا;
    sec->ڈیٹا_allocated = سائز;
}

/* reserve at least 'size' bytes aligned per 'align' in section
   'sec' from current offset, and return the aligned offset */
ST_FUNC سائز_t section_جوڑو(Section *sec, addr_t سائز, صحیح align)
{
    سائز_t انحراف, offset1;

    انحراف = (sec->ڈیٹا_انحراف + align - 1) & -align;
    offset1 = انحراف + سائز;
    اگر (sec->sh_type != SHT_NOBITS && offset1 > sec->ڈیٹا_allocated)
        section_realloc(sec, offset1);
    sec->ڈیٹا_انحراف = offset1;
    اگر (align > sec->sh_addralign)
        sec->sh_addralign = align;
    واپس انحراف;
}

/* reserve at least 'size' bytes in section 'sec' from
   sec->data_offset. */
ST_FUNC خالی *section_ptr_جوڑو(Section *sec, addr_t سائز)
{
    سائز_t انحراف = section_جوڑو(sec, سائز, 1);
    واپس sec->ڈیٹا + انحراف;
}

#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
/* reserve at least 'size' bytes from section start */
ساکن خالی section_reserve(Section *sec, غیرعلامتی طویل سائز)
{
    اگر (سائز > sec->ڈیٹا_allocated)
        section_realloc(sec, سائز);
    اگر (سائز > sec->ڈیٹا_انحراف)
        sec->ڈیٹا_انحراف = سائز;
}
#اگر_ختم

ساکن Section *have_section(TCCState *s1, ثابت حرف *name)
{
    Section *sec;
    صحیح i;
    برائے(i = 1; i < s1->nb_sections; i++) {
        sec = s1->sections[i];
        اگر (!strcmp(name, sec->name))
            واپس sec;
    }
    واپس تہی;
}

/* return a reference to a section, and create it if it does not
   exists */
ST_FUNC Section *ڈھونڈو_section(TCCState *s1, ثابت حرف *name)
{
    Section *sec = have_section(s1, name);
    اگر (sec)
        واپس sec;
    /* sections are created as PROGBITS */
    واپس new_section(s1, name, SHT_PROGBITS, SHF_ALLOC);
}

/* ------------------------------------------------------------------------- */

ST_FUNC صحیح put_elf_str(Section *s, ثابت حرف *sym)
{
    صحیح انحراف, len;
    حرف *ptr;

    len = لڑی_لمبائی(sym) + 1;
    انحراف = s->ڈیٹا_انحراف;
    ptr = section_ptr_جوڑو(s, len);
    memmove(ptr, sym, len);
    واپس انحراف;
}

/* elf symbol hashing function */
ساکن ElfW(لفظ_2) elf_hash(ثابت غیرعلامتی حرف *name)
{
    ElfW(لفظ_2) h = 0, g;

    جب (*name) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        اگر (g)
            h ^= g >> 24;
        h &= ~g;
    }
    واپس h;
}

/* rebuild hash table of section s */
/* NOTE: we do factorize the hash table code to go faster */
ساکن خالی rebuild_hash(Section *s, غیرعلامتی صحیح nb_buckets)
{
    ElfW(Sym) *sym;
    صحیح *ptr, *hash, nb_syms, sym_اشاریہ, h;
    غیرعلامتی حرف *strtab;

    strtab = s->link->ڈیٹا;
    nb_syms = s->ڈیٹا_انحراف / حجم(ElfW(Sym));

    اگر (!nb_buckets)
        nb_buckets = ((صحیح*)s->hash->ڈیٹا)[0];

    s->hash->ڈیٹا_انحراف = 0;
    ptr = section_ptr_جوڑو(s->hash, (2 + nb_buckets + nb_syms) * حجم(صحیح));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    memset(hash, 0, (nb_buckets + 1) * حجم(صحیح));
    ptr += nb_buckets + 1;

    sym = (ElfW(Sym) *)s->ڈیٹا + 1;
    برائے(sym_اشاریہ = 1; sym_اشاریہ < nb_syms; sym_اشاریہ++) {
        اگر (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            h = elf_hash(strtab + sym->st_name) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_اشاریہ;
        } ورنہ {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}

/* return the symbol number */
ST_FUNC صحیح put_elf_sym(Section *s, addr_t قدر, غیرعلامتی طویل سائز,
    صحیح info, صحیح other, صحیح shndx, ثابت حرف *name)
{
    صحیح name_انحراف, sym_اشاریہ;
    صحیح nbuckets, h;
    ElfW(Sym) *sym;
    Section *hs;

    sym = section_ptr_جوڑو(s, حجم(ElfW(Sym)));
    اگر (name && name[0])
        name_انحراف = put_elf_str(s->link, name);
    ورنہ
        name_انحراف = 0;
    /* XXX: endianness */
    sym->st_name = name_انحراف;
    sym->st_قدر = قدر;
    sym->st_سائز = سائز;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
    sym_اشاریہ = sym - (ElfW(Sym) *)s->ڈیٹا;
    hs = s->hash;
    اگر (hs) {
        صحیح *ptr, *بنیاد;
        ptr = section_ptr_جوڑو(hs, حجم(صحیح));
        بنیاد = (صحیح *)hs->ڈیٹا;
        /* only add global or weak symbols. */
        اگر (ELFW(ST_BIND)(info) != STB_LOCAL) {
            /* add another hashing entry */
            nbuckets = بنیاد[0];
            h = elf_hash((غیرعلامتی حرف *)s->link->ڈیٹا + name_انحراف) % nbuckets;
            *ptr = بنیاد[2 + h];
            بنیاد[2 + h] = sym_اشاریہ;
            بنیاد[1]++;
            /* we resize the hash table */
            hs->nb_hashed_syms++;
            اگر (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } ورنہ {
            *ptr = 0;
            بنیاد[1]++;
        }
    }
    واپس sym_اشاریہ;
}

ST_FUNC صحیح ڈھونڈو_elf_sym(Section *s, ثابت حرف *name)
{
    ElfW(Sym) *sym;
    Section *hs;
    صحیح nbuckets, sym_اشاریہ, h;
    ثابت حرف *name1;

    hs = s->hash;
    اگر (!hs)
        واپس 0;
    nbuckets = ((صحیح *)hs->ڈیٹا)[0];
    h = elf_hash((غیرعلامتی حرف *) name) % nbuckets;
    sym_اشاریہ = ((صحیح *)hs->ڈیٹا)[2 + h];
    جب (sym_اشاریہ != 0) {
        sym = &((ElfW(Sym) *)s->ڈیٹا)[sym_اشاریہ];
        name1 = (حرف *) s->link->ڈیٹا + sym->st_name;
        اگر (!strcmp(name, name1))
            واپس sym_اشاریہ;
        sym_اشاریہ = ((صحیح *)hs->ڈیٹا)[2 + nbuckets + sym_اشاریہ];
    }
    واپس 0;
}

/* return elf symbol value, signal error if 'err' is nonzero, decorate
   name if FORC */
ST_FUNC addr_t get_sym_addr(TCCState *s1, ثابت حرف *name, صحیح err, صحیح forc)
{
    صحیح sym_اشاریہ;
    ElfW(Sym) *sym;
    حرف buf[256];
    اگر (forc && s1->leading_underscore
#اگر_تعریف_شدہ TCC_ہدف_PE
        /* win32-32bit stdcall symbols always have _ already */
        && !strchr(name, '@')
#اگر_ختم
        ) {
        buf[0] = '_';
        pstrcpy(buf + 1, حجم(buf) - 1, name);
        name = buf;
    }
    sym_اشاریہ = ڈھونڈو_elf_sym(s1->symtab, name);
    sym = &((ElfW(Sym) *)s1->symtab->ڈیٹا)[sym_اشاریہ];
    اگر (!sym_اشاریہ || sym->st_shndx == SHN_UNDEF) {
        اگر (err)
            tcc_error_noabort("%s not defined", name);
        واپس (addr_t)-1;
    }
    واپس sym->st_قدر;
}

/* return elf symbol value */
LIBTCCAPI خالی *tcc_get_علامت(TCCState *s, ثابت حرف *name)
{
    addr_t addr = get_sym_addr(s, name, 0, 1);
    واپس addr == -1 ? تہی : (خالی*)(uintptr_t)addr;
}

LIBTCCAPI صحیح tcc_جوڑو_علامت(TCCState *s1, ثابت حرف *name, ثابت خالی *val)
{
#اگر_تعریف_شدہ TCC_ہدف_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s1, 0, name, (uintptr_t)val);
#ورنہ
    حرف buf[256];
    اگر (s1->leading_underscore) {
        buf[0] = '_';
        pstrcpy(buf + 1, حجم(buf) - 1, name);
        name = buf;
    }
    سیٹ_global_sym(s1, name, تہی, (addr_t)(uintptr_t)val); /* NULL: SHN_ABS */
#اگر_ختم
    واپس 0;
}

/* list elf symbol names and values */
ST_FUNC خالی list_elf_symbols(TCCState *s, خالی *ctx,
    خالی (*علامت_cb)(خالی *ctx, ثابت حرف *name, ثابت خالی *val))
{
    ElfW(Sym) *sym;
    Section *symtab;
    صحیح sym_اشاریہ, انتہا_sym;
    ثابت حرف *name;
    غیرعلامتی حرف sym_vis, sym_bind;

    symtab = s->symtab;
    انتہا_sym = symtab->ڈیٹا_انحراف / حجم (ElfSym);
    برائے (sym_اشاریہ = 0; sym_اشاریہ < انتہا_sym; ++sym_اشاریہ) {
        sym = &((ElfW(Sym) *)symtab->ڈیٹا)[sym_اشاریہ];
        اگر (sym->st_قدر) {
            name = (حرف *) symtab->link->ڈیٹا + sym->st_name;
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            sym_vis = ELFW(ST_VISIBILITY)(sym->st_other);
            اگر (sym_bind == STB_GLOBAL && sym_vis == STV_DEFAULT)
                علامت_cb(ctx, name, (خالی*)(uintptr_t)sym->st_قدر);
        }
    }
}

/* list elf symbol names and values */
LIBTCCAPI خالی tcc_list_symbols(TCCState *s, خالی *ctx,
    خالی (*علامت_cb)(خالی *ctx, ثابت حرف *name, ثابت خالی *val))
{
    list_elf_symbols(s, ctx, علامت_cb);
}

#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
ساکن خالی
نسخہ_جوڑو (TCCState *s1)
{
    صحیح i;
    ElfW(Sym) *sym;
    ElfW(Verneed) *vn = تہی;
    Section *symtab;
    صحیح sym_اشاریہ, انتہا_sym, nb_versions = 2, nb_entries = 0;
    ElfW(Half) *versym;
    ثابت حرف *name;

    اگر (0 == nb_sym_versions)
        واپس;
    versym_section = new_section(s1, ".gnu.version", SHT_GNU_versym, SHF_ALLOC);
    versym_section->sh_entsize = حجم(ElfW(Half));
    versym_section->link = s1->dynsym;

    /* add needed symbols */
    symtab = s1->dynsym;
    انتہا_sym = symtab->ڈیٹا_انحراف / حجم (ElfSym);
    versym = section_ptr_جوڑو(versym_section, انتہا_sym * حجم(ElfW(Half)));
    برائے (sym_اشاریہ = 1; sym_اشاریہ < انتہا_sym; ++sym_اشاریہ) {
        صحیح dllindex, verndx;
        sym = &((ElfW(Sym) *)symtab->ڈیٹا)[sym_اشاریہ];
        name = (حرف *) symtab->link->ڈیٹا + sym->st_name;
        dllindex = ڈھونڈو_elf_sym(s1->dynsymtab_section, name);
        verndx = (dllindex && dllindex < nb_sym_مقصد_نسخہ)
                 ? sym_مقصد_نسخہ[dllindex] : -1;
        اگر (verndx >= 0
            /* XXX: on android, clang refuses to link with a libtcc.so made by tcc
               when defined symbols have a version > 1 or when the version is '0'.
               Whereas version '1' for example for 'signal' in an exe defeats
               bcheck's signal_redir. */
            && (sym->st_shndx == SHN_UNDEF || (s1->output_type & TCC_OUTPUT_EXE))
            ) {
            اگر (!sym_versions[verndx].برآمد_اشاریہ)
              sym_versions[verndx].برآمد_اشاریہ = nb_versions++;
            versym[sym_اشاریہ] = sym_versions[verndx].برآمد_اشاریہ;
        } ورنہ {
            versym[sym_اشاریہ] = 1; /* (*global*) */
        }
        //printf("SYM %d %s\n", versym[sym_index], name);
    }
    /* generate verneed section, but not when it will be empty.  Some
       dynamic linkers look at their contents even when DTVERNEEDNUM and
       section size is zero.  */
    اگر (nb_versions > 2) {
        verneed_section = new_section(s1, ".gnu.version_r",
                                      SHT_GNU_verneed, SHF_ALLOC);
        verneed_section->link = s1->dynsym->link;
        برائے (i = nb_sym_versions; i-- > 0;) {
            ساخت sym_نسخہ *sv = &sym_versions[i];
            صحیح n_same_libs = 0, پچھلا;
            سائز_t vnofs;
            ElfW(Vernaux) *vna = 0;
            اگر (sv->برآمد_اشاریہ < 1)
              جاری;

            /* make sure that a DT_NEEDED tag is put */
            /* abitest-tcc fails on older i386-linux with "ld-linux.so.2" DT_NEEDED
               ret_int_test... Inconsistency detected by ld.so: dl-minimal.c: 148:
               realloc: Assertion `ptr == alloc_last_block' failed! */
            اگر (strcmp(sv->lib, "ld-linux.so.2"))
                tcc_جوڑو_dllref(s1, sv->lib, 0);

            vnofs = section_جوڑو(verneed_section, حجم(*vn), 1);
            vn = (ElfW(Verneed)*)(verneed_section->ڈیٹا + vnofs);
            vn->vn_نسخہ = 1;
            vn->vn_file = put_elf_str(verneed_section->link, sv->lib);
            vn->vn_aux = حجم (*vn);
            کرو {
                پچھلا = sv->پچھلا_same_lib;
                اگر (sv->برآمد_اشاریہ > 0) {
                    vna = section_ptr_جوڑو(verneed_section, حجم(*vna));
                    vna->vna_hash = elf_hash ((ثابت غیرعلامتی حرف *)sv->نسخہ);
                    vna->vna_flags = 0;
                    vna->vna_other = sv->برآمد_اشاریہ;
                    sv->برآمد_اشاریہ = -2;
                    vna->vna_name = put_elf_str(verneed_section->link, sv->نسخہ);
                    vna->vna_اگلا = حجم (*vna);
                    //printf("LIB %d %s %s\n", vna->vna_other, sv->lib, verneed_section->link->data + vna->vna_name);
                    n_same_libs++;
                }
                اگر (پچھلا >= 0)
                  sv = &sym_versions[پچھلا];
            } جب(پچھلا >= 0);
            vna->vna_اگلا = 0;
            vn = (ElfW(Verneed)*)(verneed_section->ڈیٹا + vnofs);
            vn->vn_cnt = n_same_libs;
            vn->vn_اگلا = حجم(*vn) + n_same_libs * حجم(*vna);
            nb_entries++;
        }
        اگر (vn)
          vn->vn_اگلا = 0;
        verneed_section->sh_info = nb_entries;
    }
    dt_verneednum = nb_entries;
}
#اگر_ختم /* ndef ELF_OBJ_ONLY */

/* catch .tbss also */
ساکن صحیح IS_BSS(TCCState *s1, صحیح ndx)
{
    واپس ndx == SHN_COMMON
     || (ndx < s1->nb_sections
         && s1->sections[ndx]->sh_type == SHT_NOBITS);
}

/* add an elf symbol : check if it is already defined and patch
   it. Return symbol index. NOTE that sh_num can be SHN_UNDEF. */
ST_FUNC صحیح سیٹ_elf_sym(Section *s, addr_t قدر, غیرعلامتی طویل سائز,
                       صحیح info, صحیح other, صحیح shndx, ثابت حرف *name)
{
    TCCState *s1 = s->s1;
    ElfW(Sym) *esym;
    صحیح sym_bind, sym_اشاریہ, sym_type, esym_bind;
    غیرعلامتی حرف sym_vis, esym_vis, new_vis;

    sym_bind = ELFW(ST_BIND)(info);
    sym_type = ELFW(ST_TYPE)(info);
    sym_vis = ELFW(ST_VISIBILITY)(other);

    اگر (sym_bind != STB_LOCAL) {
        /* we search global or weak symbols */
        sym_اشاریہ = ڈھونڈو_elf_sym(s, name);
        اگر (!sym_اشاریہ)
            جاؤ do_def;
        esym = &((ElfW(Sym) *)s->ڈیٹا)[sym_اشاریہ];
        اگر (esym->st_قدر == قدر && esym->st_سائز == سائز && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            واپس sym_اشاریہ;
        اگر (esym->st_shndx != SHN_UNDEF) {
            esym_bind = ELFW(ST_BIND)(esym->st_info);
            /* propagate the most constraining visibility */
            /* STV_DEFAULT(0)<STV_PROTECTED(3)<STV_HIDDEN(2)<STV_INTERNAL(1) */
            esym_vis = ELFW(ST_VISIBILITY)(esym->st_other);
            اگر (esym_vis == STV_DEFAULT) {
                new_vis = sym_vis;
            } ورنہ اگر (sym_vis == STV_DEFAULT) {
                new_vis = esym_vis;
            } ورنہ {
                new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
            }
            esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
                             | new_vis;
            اگر (shndx == SHN_UNDEF) {
                /* ignore adding of undefined symbol if the
                   corresponding symbol is already defined */
            } ورنہ اگر (sym_bind == STB_GLOBAL && esym_bind == STB_WEAK) {
                /* global overrides weak, so patch */
                جاؤ do_patch;
            } ورنہ اگر (sym_bind == STB_WEAK && esym_bind == STB_GLOBAL) {
                /* weak is ignored if already global */
            } ورنہ اگر (sym_bind == STB_WEAK && esym_bind == STB_WEAK) {
                /* keep first-found weak definition, ignore subsequents */
            } ورنہ اگر (sym_vis == STV_HIDDEN || sym_vis == STV_اندرونی) {
                /* ignore hidden symbols after */
            } ورنہ اگر (s->sh_flags & SHF_DYNSYM) {
                /* we accept that two DLL define the same symbol */
            } ورنہ اگر (!IS_BSS(s1, shndx) && IS_BSS(s1, esym->st_shndx)) {
                /* data symbol gets precedence over common/bss */
                جاؤ do_patch;
            } ورنہ اگر (IS_BSS(s1, shndx)) {
                /* data symbol keeps precedence over common/bss */
	    } ورنہ اگر (esym->st_other & ST_ASM_سیٹ) {
		/* If the existing symbol came from an asm .set
		   we can override.  */
		جاؤ do_patch;
            } ورنہ {
#اگر 0
                لکھو("new_bind=%x new_shndx=%x new_vis=%x old_bind=%x old_shndx=%x old_vis=%x\n",
                       sym_bind, shndx, new_vis, esym_bind, esym->st_shndx, esym_vis);
#اگر_ختم
                tcc_error_noabort("link symbol '%s' defined twice", name);
            }
        } ورنہ {
            esym->st_other = other;
        do_patch:
            esym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
            esym->st_shndx = shndx;
            esym->st_قدر = قدر;
            esym->st_سائز = سائز;
        }
    } ورنہ {
    do_def:
        sym_اشاریہ = put_elf_sym(s, قدر, سائز,
                                ELFW(ST_INFO)(sym_bind, sym_type), other,
                                shndx, name);
    }
    واپس sym_اشاریہ;
}

/* put relocation */
ST_FUNC خالی put_elf_reloca(Section *symtab, Section *s, غیرعلامتی طویل انحراف,
                            صحیح type, صحیح علامت, addr_t addend)
{
    TCCState *s1 = s->s1;
    حرف buf[256];
    Section *sr;
    ElfW_Rel *rel;

    sr = s->reloc;
    اگر (!sr) {
        /* if no relocation section, create it */
        snprintf(buf, حجم(buf), REL_SECTION_FMT, s->name);
        /* if the symtab is allocated, then we consider the relocation
           are also */
        sr = new_section(s->s1, buf, SHT_RELX, symtab->sh_flags);
        sr->sh_entsize = حجم(ElfW_Rel);
        sr->link = symtab;
        sr->sh_info = s->sh_عدد;
        s->reloc = sr;
    }
    rel = section_ptr_جوڑو(sr, حجم(ElfW_Rel));
    rel->r_انحراف = انحراف;
    rel->r_info = ELFW(R_INFO)(علامت, type);
#اگر SHT_RELX == SHT_RELA
    rel->r_addend = addend;
#اگر_ختم
    اگر (SHT_RELX != SHT_RELA && addend)
        tcc_error_noabort("non-zero addend on REL architecture");
}

ST_FUNC خالی put_elf_reloc(Section *symtab, Section *s, غیرعلامتی طویل انحراف,
                           صحیح type, صحیح علامت)
{
    put_elf_reloca(symtab, s, انحراف, type, علامت, 0);
}

ST_FUNC ساخت sym_attr *get_sym_attr(TCCState *s1, صحیح اشاریہ, صحیح alloc)
{
    صحیح n;
    ساخت sym_attr *tab;

    اگر (اشاریہ >= s1->nb_sym_attrs) {
        اگر (!alloc)
            واپس s1->sym_attrs;
        /* find immediately bigger power of 2 and reallocate array */
        n = 1;
        جب (اشاریہ >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * حجم(*s1->sym_attrs));
        s1->sym_attrs = tab;
        memset(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * حجم(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    واپس &s1->sym_attrs[اشاریہ];
}

ساکن خالی update_relocs(TCCState *s1, Section *s, صحیح *old_مقصد_new_syms, صحیح پہلا_sym)
{
    صحیح i, type, sym_اشاریہ;
    Section *sr;
    ElfW_Rel *rel;

    برائے(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        اگر (sr->sh_type == SHT_RELX && sr->link == s) {
            for_each_elem(sr, 0, rel, ElfW_Rel) {
                sym_اشاریہ = ELFW(R_SYM)(rel->r_info);
                type = ELFW(R_TYPE)(rel->r_info);
                اگر ((sym_اشاریہ -= پہلا_sym) < 0)
                    جاری; /* zero sym_index in reloc (can happen with asm) */
                sym_اشاریہ = old_مقصد_new_syms[sym_اشاریہ];
                rel->r_info = ELFW(R_INFO)(sym_اشاریہ, type);
            }
        }
    }
}

/* In an ELF file symbol table, the local symbols must appear below
   the global and weak ones. Since TCC cannot sort it while generating
   the code, we must do it after. All the relocation tables are also
   modified to take into account the symbol table sorting */
ساکن خالی ترتیب_دو_syms(TCCState *s1, Section *s)
{
    صحیح *old_مقصد_new_syms;
    ElfW(Sym) *new_syms;
    صحیح nb_syms, i;
    ElfW(Sym) *p, *q;

    nb_syms = s->ڈیٹا_انحراف / حجم(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * حجم(ElfW(Sym)));
    old_مقصد_new_syms = tcc_malloc(nb_syms * حجم(صحیح));

    /* first pass for local symbols */
    p = (ElfW(Sym) *)s->ڈیٹا;
    q = new_syms;
    برائے(i = 0; i < nb_syms; i++) {
        اگر (ELFW(ST_BIND)(p->st_info) == STB_LOCAL) {
            old_مقصد_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    /* save the number of local symbols in section header */
    اگر( s->sh_سائز )    /* this 'if' makes IDA happy */
        s->sh_info = q - new_syms;

    /* then second pass for non local symbols */
    p = (ElfW(Sym) *)s->ڈیٹا;
    برائے(i = 0; i < nb_syms; i++) {
        اگر (ELFW(ST_BIND)(p->st_info) != STB_LOCAL) {
            old_مقصد_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }

    /* we copy the new symbols to the old */
    حافظہ_نقل(s->ڈیٹا, new_syms, nb_syms * حجم(ElfW(Sym)));
    tcc_free(new_syms);

    update_relocs(s1, s, old_مقصد_new_syms, 0);
    tcc_free(old_مقصد_new_syms);
}

#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
/* See: https://flapenguin.me/elf-dt-gnu-hash */
#تعریف_کرو	ELFCLASS_بٹ (PTR_سائز * 8)

ساکن Section *create_gnu_hash(TCCState *s1)
{
    صحیح nb_syms, i, ndef, nbuckets, symoffset, bloom_سائز, bloom_سرکاؤ;
    ElfW(Sym) *p;
    Section *gnu_hash;
    Section *dynsym = s1->dynsym;
    Elf32_لفظ *ptr;

    gnu_hash = new_section(s1, ".gnu.hash", SHT_GNU_HASH, SHF_ALLOC);
    gnu_hash->link = dynsym->hash->link;

    nb_syms = dynsym->ڈیٹا_انحراف / حجم(ElfW(Sym));

    /* count def symbols */
    ndef = 0;
    p = (ElfW(Sym) *)dynsym->ڈیٹا;
    برائے(i = 0; i < nb_syms; i++, p++)
        ndef += p->st_shndx != SHN_UNDEF;

    /* calculate gnu hash sizes and fill header */
    nbuckets = ndef / 4 + 1;
    symoffset = nb_syms - ndef;
    bloom_سرکاؤ = PTR_سائز == 8 ? 6 : 5;
    bloom_سائز = 1; /* must be power of two */
    جب (ndef >= bloom_سائز * (1 << (bloom_سرکاؤ - 3)))
	bloom_سائز *= 2;
    ptr = section_ptr_جوڑو(gnu_hash, 4 * 4 +
				    PTR_سائز * bloom_سائز +
				    nbuckets * 4 +
				    ndef * 4);
    ptr[0] = nbuckets;
    ptr[1] = symoffset;
    ptr[2] = bloom_سائز;
    ptr[3] = bloom_سرکاؤ;
    واپس gnu_hash;
}

ساکن Elf32_لفظ elf_gnu_hash (ثابت غیرعلامتی حرف *name)
{
    Elf32_لفظ h = 5381;
    غیرعلامتی حرف c;

    جب ((c = *name++))
        h = h * 33 + c;
    واپس h;
}

ساکن خالی update_gnu_hash(TCCState *s1, Section *gnu_hash)
{
    صحیح *old_مقصد_new_syms;
    ElfW(Sym) *new_syms;
    صحیح nb_syms, i, nbuckets, bloom_سائز, bloom_سرکاؤ;
    ElfW(Sym) *p, *q;
    Section *vs;
    Section *dynsym = s1->dynsym;
    Elf32_لفظ *ptr, *buckets, *chain, *hash;
    غیرعلامتی صحیح *nextbuck;
    addr_t *bloom;
    غیرعلامتی حرف *strtab;
    ساخت { صحیح پہلا, آخری; } *buck;

    strtab = dynsym->link->ڈیٹا;
    nb_syms = dynsym->ڈیٹا_انحراف / حجم(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * حجم(ElfW(Sym)));
    old_مقصد_new_syms = tcc_malloc(nb_syms * حجم(صحیح));
    hash = tcc_malloc(nb_syms * حجم(Elf32_لفظ));
    nextbuck = tcc_malloc(nb_syms * حجم(صحیح));

    /* calculate hashes and copy undefs */
    p = (ElfW(Sym) *)dynsym->ڈیٹا;
    q = new_syms;
    برائے(i = 0; i < nb_syms; i++, p++) {
        اگر (p->st_shndx == SHN_UNDEF) {
            old_مقصد_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
	ورنہ
	    hash[i] = elf_gnu_hash(strtab + p->st_name);
    }

    ptr = (Elf32_لفظ *) gnu_hash->ڈیٹا;
    nbuckets = ptr[0];
    bloom_سائز = ptr[2];
    bloom_سرکاؤ = ptr[3];
    bloom = (addr_t *) (خالی *) &ptr[4];
    buckets = (Elf32_لفظ*) (خالی *) &bloom[bloom_سائز];
    chain = &buckets[nbuckets];
    buck = tcc_malloc(nbuckets * حجم(*buck));

    اگر (gnu_hash->ڈیٹا_انحراف != 4 * 4 +
				 PTR_سائز * bloom_سائز +
				 nbuckets * 4 +
				 (nb_syms - (q - new_syms)) * 4)
	tcc_error_noabort ("gnu_hash size incorrect");

    /* find buckets */
    برائے(i = 0; i < nbuckets; i++)
	buck[i].پہلا = -1;

    p = (ElfW(Sym) *)dynsym->ڈیٹا;
    برائے(i = 0; i < nb_syms; i++, p++)
        اگر (p->st_shndx != SHN_UNDEF) {
	    صحیح بالٹی = hash[i] % nbuckets;

	    اگر (buck[بالٹی].پہلا == -1)
		buck[بالٹی].پہلا = buck[بالٹی].آخری = i;
	    ورنہ {
		nextbuck[buck[بالٹی].آخری] = i;
		buck[بالٹی].آخری = i;
	    }
	}

    /* fill buckets/chains/bloom and sort symbols */
    p = (ElfW(Sym) *)dynsym->ڈیٹا;
    برائے(i = 0; i < nbuckets; i++) {
	صحیح cur = buck[i].پہلا;

	اگر (cur != -1) {
	    buckets[i] = q - new_syms;
	    برائے (;;) {
                old_مقصد_new_syms[cur] = q - new_syms;
                *q++ = p[cur];
	        *chain++ = hash[cur] & ~1;
		bloom[(hash[cur] / ELFCLASS_بٹ) % bloom_سائز] |=
		    (addr_t)1 << (hash[cur] % ELFCLASS_بٹ) |
		    (addr_t)1 << ((hash[cur] >> bloom_سرکاؤ) % ELFCLASS_بٹ);
		اگر (cur == buck[i].آخری)
		    توڑو;
		cur = nextbuck[cur];
	    }
	    chain[-1] |= 1;
	}
    }

    حافظہ_نقل(dynsym->ڈیٹا, new_syms, nb_syms * حجم(ElfW(Sym)));
    tcc_free(new_syms);
    tcc_free(hash);
    tcc_free(buck);
    tcc_free(nextbuck);

    update_relocs(s1, dynsym, old_مقصد_new_syms, 0);

    /* modify the versions */
    vs = versym_section;
    اگر (vs) {
	ElfW(Half) *newver, *versym = (ElfW(Half) *)vs->ڈیٹا;

	اگر (1/*versym*/) {
            newver = tcc_malloc(nb_syms * حجم(*newver));
	    برائے (i = 0; i < nb_syms; i++)
	        newver[old_مقصد_new_syms[i]] = versym[i];
	    حافظہ_نقل(vs->ڈیٹا, newver, nb_syms * حجم(*newver));
	    tcc_free(newver);
	}
    }

    tcc_free(old_مقصد_new_syms);

    /* rebuild hash */
    ptr = (Elf32_لفظ *) dynsym->hash->ڈیٹا;
    rebuild_hash(dynsym, ptr[0]);
}
#اگر_ختم /* ELF_OBJ_ONLY */

/* relocate symbol table, resolve undefined symbols if do_resolve is
   true and output error if undefined symbol. */
ST_FUNC خالی relocate_syms(TCCState *s1, Section *symtab, صحیح do_resolve)
{
    ElfW(Sym) *sym;
    صحیح sym_bind, sh_عدد;
    ثابت حرف *name;

    for_each_elem(symtab, 1, sym, ElfW(Sym)) {
        sh_عدد = sym->st_shndx;
        اگر (sh_عدد == SHN_UNDEF) {
            اگر (do_resolve == 2) /* relocating dynsym */
                جاری;
            name = (حرف *) s1->symtab->link->ڈیٹا + sym->st_name;
            /* Use ld.so to resolve symbol for us (for tcc -run) */
            اگر (do_resolve) {
#اگر defined TCC_IS_NATIVE && !defined TCC_ہدف_PE
                /* dlsym() needs the undecorated name.  */
                ثابت حرف *name_ud = &name[s1->leading_underscore];
                خالی *addr = تہی;
                اگر (!s1->nostdlib)
                    addr = dlsym(RTLD_DEFAULT, name_ud);
		اگر (addr == تہی) {
		    صحیح i;
		    برائے (i = 0; i < s1->nb_loaded_dlls; i++)
                        اگر ((addr = dlsym(s1->loaded_dlls[i]->handle, name_ud)))
			    توڑو;
		}
                اگر (addr) {
                    sym->st_قدر = (addr_t) addr;
#اگر_تعریف_شدہ DEBUG_RELOC
		    لکھو ("relocate_sym: %s -> 0x%lx\n", name, sym->st_قدر);
#اگر_ختم
                    جاؤ ملا;
                }
#اگر_ختم
            /* if dynamic symbol exist, it will be used in relocate_section */
            } ورنہ اگر (s1->dynsym && ڈھونڈو_elf_sym(s1->dynsym, name))
                جاؤ ملا;
            /* XXX: _fp_hw seems to be part of the ABI, so we ignore
               it */
            اگر (!strcmp(name, "_fp_hw"))
                جاؤ ملا;
            /* only weak symbols are accepted to be undefined. Their
               value is zero */
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            اگر (sym_bind == STB_WEAK)
                sym->st_قدر = 0;
            ورنہ
                tcc_error_noabort("unresolved reference to '%s'", name);

        } ورنہ اگر (sh_عدد < SHN_LORESERVE) {
            /* add section base */
            sym->st_قدر += s1->sections[sym->st_shndx]->sh_addr;
        }
    ملا: ;
    }
}

/* relocate a given section (CPU dependent) by applying the relocations
   in the associated relocation section */
ساکن خالی relocate_section(TCCState *s1, Section *s, Section *sr)
{
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    صحیح type, sym_اشاریہ;
    غیرعلامتی حرف *ptr;
    addr_t tgt, addr;
    صحیح is_dwarf = s->sh_عدد >= s1->dwlo && s->sh_عدد < s1->dwhi;

    qrel = (ElfW_Rel *)sr->ڈیٹا;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
	اگر (s->ڈیٹا == تہی) /* bss */
	    جاری;
        ptr = s->ڈیٹا + rel->r_انحراف;
        sym_اشاریہ = ELFW(R_SYM)(rel->r_info);
        sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
        type = ELFW(R_TYPE)(rel->r_info);
        tgt = sym->st_قدر;
#اگر SHT_RELX == SHT_RELA
        tgt += rel->r_addend;
#اگر_ختم
        اگر (is_dwarf && type == R_ڈیٹا_32_DW
            && sym->st_shndx >= s1->dwlo && sym->st_shndx < s1->dwhi) {
            /* dwarf section relocation to each other */
            add32le(ptr, tgt - s1->sections[sym->st_shndx]->sh_addr);
            جاری;
        }
        addr = s->sh_addr + rel->r_انحراف;
        relocate(s1, rel, type, ptr, addr, tgt);
    }

#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
    /* if the relocation is allocated, we change its symbol table */
    اگر (sr->sh_flags & SHF_ALLOC) {
        sr->link = s1->dynsym;
        اگر (s1->output_type & TCC_OUTPUT_DYN) {
            سائز_t r = (uint8_t*)qrel - sr->ڈیٹا;
            اگر (حجم ((Stab_Sym*)0)->n_قدر < PTR_سائز
                && 0 == strcmp(s->name, ".stab"))
                r = 0; /* cannot apply 64bit relocation to 32bit value */
            sr->ڈیٹا_انحراف = sr->sh_سائز = r;
#اگر_تعریف_شدہ CONFIG_TCC_PIE
            اگر (r && (s->sh_flags & SHF_EXECINSTR))
                tcc_warning("%d relocations to %s", (غیرعلامتی)(r / حجم *qrel), s->name);
#اگر_ختم
        }
    }
#اگر_ختم

#اگر_تعریف_شدہ TCC_ہدف_RISCV64
    dynarray_reset(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries);
#اگر_ختم
}

/* relocate all sections */
ST_FUNC خالی relocate_sections(TCCState *s1)
{
    صحیح i;
    Section *s, *sr;

    برائے (i = 1; i < s1->nb_sections; ++i) {
        sr = s1->sections[i];
        اگر (sr->sh_type != SHT_RELX)
            جاری;
        s = s1->sections[sr->sh_info];
#اگر_غیر_تعریف_شدہ TCC_ہدف_MACHO
        اگر (s != s1->got
            || s1->static_link
            || s1->output_type == TCC_OUTPUT_حافظہ)
#اگر_ختم
        {
            relocate_section(s1, s, sr);
        }
#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
        اگر (sr->sh_flags & SHF_ALLOC) {
            ElfW_Rel *rel;
            /* relocate relocation table in 'sr' */
            for_each_elem(sr, 0, rel, ElfW_Rel)
                rel->r_انحراف += s->sh_addr;
        }
#اگر_ختم
    }
}

#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
/* count the number of dynamic relocations so that we can reserve
   their space */
ساکن صحیح prepare_dynamic_rel(TCCState *s1, Section *sr)
{
    صحیح گنتی_2 = 0;
#اگر defined(TCC_ہدف_I386) || defined(TCC_ہدف_X86_64) || \
    defined(TCC_ہدف_ARM) || defined(TCC_ہدف_ARM64) || \
    defined(TCC_ہدف_RISCV64)
    ElfW_Rel *rel;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
        صحیح sym_اشاریہ = ELFW(R_SYM)(rel->r_info);
        صحیح type = ELFW(R_TYPE)(rel->r_info);
        انتخاب(type) {
#اگر defined(TCC_ہدف_I386)
        حالت R_386_32:
            اگر (!get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ
                && ((ElfW(Sym)*)symtab_section->ڈیٹا + sym_اشاریہ)->st_shndx == SHN_UNDEF) {
                /* don't fixup unresolved (weak) symbols */
                rel->r_info = ELFW(R_INFO)(sym_اشاریہ, R_386_RELATIVE);
                توڑو;
            }
#وگرنہ_اگر defined(TCC_ہدف_X86_64)
        حالت R_X86_64_32:
        حالت R_X86_64_32S:
        حالت R_X86_64_64:
#وگرنہ_اگر defined(TCC_ہدف_ARM)
        حالت R_ARM_ABS32:
        حالت R_ARM_TARGET1:
#وگرنہ_اگر defined(TCC_ہدف_ARM64)
        حالت R_AARCH64_ABS32:
        حالت R_AARCH64_ABS64:
#وگرنہ_اگر defined(TCC_ہدف_RISCV64)
        حالت R_RISCV_32:
        حالت R_RISCV_64:
#اگر_ختم
            گنتی_2++;
            توڑو;
#اگر defined(TCC_ہدف_I386)
        حالت R_386_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    اگر (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_اشاریہ, R_386_PLT32);
	        توڑو;
	    }
	}
#وگرنہ_اگر defined(TCC_ہدف_X86_64)
        حالت R_X86_64_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    اگر (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_اشاریہ, R_X86_64_PLT32);
	        توڑو;
	    }
	}
#وگرنہ_اگر defined(TCC_ہدف_ARM64)
        حالت R_AARCH64_PREL32:
#اگر_ختم
            اگر (s1->output_type != TCC_OUTPUT_DLL)
                توڑو;
            اگر (get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ)
                گنتی_2++;
            توڑو;
        طےشدہ:
            توڑو;
        }
    }
#اگر_ختم
    واپس گنتی_2;
}
#اگر_ختم

#اگر_تعریف_شدہ NEED_BUILD_GOT
ساکن صحیح build_got(TCCState *s1)
{
    /* if no got, then create it */
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    s1->got->sh_entsize = 4;
    /* keep space for _DYNAMIC pointer and two dummy got entries */
    section_ptr_جوڑو(s1->got, 3 * PTR_سائز);
    واپس سیٹ_elf_sym(symtab_section, 0, 0, ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
        0, s1->got->sh_عدد, "_GLOBAL_OFFSET_TABLE_");
}

/* Create a GOT and (for function call) a PLT entry corresponding to a symbol
   in s1->symtab. When creating the dynamic symbol table entry for the GOT
   relocation, use 'size' and 'info' for the corresponding symbol metadata.
   Returns the offset of the GOT or (if any) PLT entry. */
ساکن ساخت sym_attr * put_got_اندراج(TCCState *s1, صحیح dyn_reloc_type,
                                       صحیح sym_اشاریہ)
{
    صحیح need_plt_اندراج;
    ثابت حرف *name;
    ElfW(Sym) *sym;
    ساخت sym_attr *attr;
    غیرعلامتی got_انحراف;
    حرف plt_name[200];
    صحیح len;
    Section *s_rel;

    need_plt_اندراج = (dyn_reloc_type == R_JMP_خانہ);
    attr = get_sym_attr(s1, sym_اشاریہ, 1);

    /* In case a function is both called and its address taken 2 GOT entries
       are created, one for taking the address (GOT) and the other for the PLT
       entry (PLTGOT).  */
    اگر (need_plt_اندراج ? attr->plt_انحراف : attr->got_انحراف)
        واپس attr;

    s_rel = s1->got;
    اگر (need_plt_اندراج) {
        اگر (!s1->plt) {
            s1->plt = new_section(s1, ".plt", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
            s1->plt->sh_entsize = 4;
        }
        s_rel = s1->plt;
    }

    /* create the GOT entry */
    got_انحراف = s1->got->ڈیٹا_انحراف;
    section_ptr_جوڑو(s1->got, PTR_سائز);

    /* Create the GOT relocation that will insert the address of the object or
       function of interest in the GOT entry. This is a static relocation for
       memory output (dlsym will give us the address of symbols) and dynamic
       relocation otherwise (executable and DLLs). The relocation should be
       done lazily for GOT entry with *_JUMP_SLOT relocation type (the one
       associated to a PLT entry) but is currently done at load time for an
       unknown reason. */

    sym = &((ElfW(Sym) *) symtab_section->ڈیٹا)[sym_اشاریہ];
    name = (حرف *) symtab_section->link->ڈیٹا + sym->st_name;
    //printf("sym %d %s\n", need_plt_entry, name);

    اگر (s1->dynsym) {
	اگر (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
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
	    put_elf_reloc(s1->dynsym, s1->got, got_انحراف, R_RELATIVE,
			  sym_اشاریہ);
	} ورنہ {
	    اگر (0 == attr->dyn_اشاریہ)
                attr->dyn_اشاریہ = سیٹ_elf_sym(s1->dynsym, sym->st_قدر,
                                              sym->st_سائز, sym->st_info, 0,
                                              sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s_rel, got_انحراف, dyn_reloc_type,
			  attr->dyn_اشاریہ);
	}
    } ورنہ {
        put_elf_reloc(symtab_section, s1->got, got_انحراف, dyn_reloc_type,
                      sym_اشاریہ);
    }

    اگر (need_plt_اندراج) {
        attr->plt_انحراف = create_plt_اندراج(s1, got_انحراف, attr);

        /* create a symbol 'sym@plt' for the PLT jump vector */
        len = لڑی_لمبائی(name);
        اگر (len > حجم plt_name - 5)
            len = حجم plt_name - 5;
        حافظہ_نقل(plt_name, name, len);
        strcpy(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_انحراف, 0,
            ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0, s1->plt->sh_عدد, plt_name);
    } ورنہ {
        attr->got_انحراف = got_انحراف;
    }

    واپس attr;
}

/* build GOT and PLT entries */
/* Two passes because R_JMP_SLOT should become first. Some targets
   (arm, arm64) do not allow mixing R_JMP_SLOT and R_GLOB_DAT. */
ST_FUNC خالی build_got_entries(TCCState *s1, صحیح got_sym)
{
    Section *s;
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    صحیح i, type, gotplt_اندراج, reloc_type, sym_اشاریہ;
    ساخت sym_attr *attr;
    صحیح pass = 0;
redo:
    برائے(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        اگر (s->sh_type != SHT_RELX)
            جاری;
        /* no need to handle got relocations */
        اگر (s->link != symtab_section)
            جاری;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_اندراج = gotplt_اندراج_type(type);
            اگر (gotplt_اندراج == -1) {
                tcc_error_noabort ("Unknown relocation type for got: %d", type);
                جاری;
            }
            sym_اشاریہ = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];

            اگر (gotplt_اندراج == NO_GOTPLT_اندراج) {
                جاری;
            }

            /* Automatically create PLT/GOT [entry] if it is an undefined
	       reference (resolved at runtime), or the symbol is absolute,
	       probably created by tcc_add_symbol, and thus on 64-bit
	       targets might be too far from application code.  */
            اگر (gotplt_اندراج == AUTO_GOTPLT_اندراج) {
                اگر (sym->st_shndx == SHN_UNDEF) {
                    ElfW(Sym) *esym;
		    صحیح dynindex;
                    اگر (!PCRELATIVE_DLLPLT
                        && (s1->output_type & TCC_OUTPUT_DYN))
                        جاری;
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
		    اگر (s1->dynsym) {
			/* dynsym isn't set for -run :-/  */
			dynindex = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
			esym = (ElfW(Sym) *)s1->dynsym->ڈیٹا + dynindex;
			اگر (dynindex
			    && (ELFW(ST_TYPE)(esym->st_info) == STT_FUNC
				|| (ELFW(ST_TYPE)(esym->st_info) == STT_NOTYPE
				    && ELFW(ST_TYPE)(sym->st_info) == STT_FUNC)))
			    جاؤ jmp_خانہ;
		    }
                } ورنہ اگر (sym->st_shndx == SHN_ABS) {
                    اگر (sym->st_قدر == 0) /* from tcc_add_btstub() */
                        جاری;
#اگر_غیر_تعریف_شدہ TCC_ہدف_ARM
                    اگر (PTR_سائز != 8)
                        جاری;
#اگر_ختم
                    /* from tcc_add_symbol(): on 64 bit platforms these
                       need to go through .got */
                } ورنہ
                    جاری;
            }

#اگر_تعریف_شدہ TCC_ہدف_I386
            اگر ((type == R_386_PLT32 || type == R_386_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		اگر (pass != 0)
		    جاری;
                rel->r_info = ELFW(R_INFO)(sym_اشاریہ, R_386_PC32);
                جاری;
            }
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_X86_64
            اگر ((type == R_X86_64_PLT32 || type == R_X86_64_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		اگر (pass != 0)
		    جاری;
                rel->r_info = ELFW(R_INFO)(sym_اشاریہ, R_X86_64_PC32);
                جاری;
            }
#اگر_ختم
            reloc_type = رمز_reloc(type);
            اگر (reloc_type == -1) {
                tcc_error_noabort ("Unknown relocation type: %d", type);
                جاری;
            }

            اگر (reloc_type != 0) {
        jmp_خانہ:
	        اگر (pass != 0)
                    جاری;
                reloc_type = R_JMP_خانہ;
            } ورنہ {
	        اگر (pass != 1)
                    جاری;
                reloc_type = R_GLOB_DAT;
            }

            اگر (!s1->got)
                got_sym = build_got(s1);

            اگر (gotplt_اندراج == BUILD_GOT_ONLY)
                جاری;

            attr = put_got_اندراج(s1, reloc_type, sym_اشاریہ);

            اگر (reloc_type == R_JMP_خانہ)
                rel->r_info = ELFW(R_INFO)(attr->plt_sym, type);
        }
    }
    اگر (++pass < 2)
        جاؤ redo;
    /* .rel.plt refers to .got actually */
    اگر (s1->plt && s1->plt->reloc)
        s1->plt->reloc->sh_info = s1->got->sh_عدد;
    اگر (got_sym) /* set size */
        ((ElfW(Sym)*)symtab_section->ڈیٹا)[got_sym].st_سائز = s1->got->ڈیٹا_انحراف;
}
#اگر_ختم /* def NEED_BUILD_GOT */

ST_FUNC صحیح سیٹ_global_sym(TCCState *s1, ثابت حرف *name, Section *sec, addr_t offs)
{
    صحیح shn = sec ? sec->sh_عدد : offs || !name ? SHN_ABS : SHN_UNDEF;
    اگر (sec && offs == -1)
        offs = sec->ڈیٹا_انحراف;
    واپس سیٹ_elf_sym(symtab_section, offs, 0,
        ELFW(ST_INFO)(name ? STB_GLOBAL : STB_LOCAL, STT_NOTYPE), 0, shn, name);
}

ساکن خالی جوڑو_init_array_متعین_کرتا(TCCState *s1, ثابت حرف *section_name)
{
    Section *s;
    addr_t انتہا_انحراف;
    حرف buf[1024];
    s = have_section(s1, section_name);
    اگر (!s || !(s->sh_flags & SHF_ALLOC)) {
        انتہا_انحراف = 0;
        s = متن_section;
    } ورنہ {
        انتہا_انحراف = s->ڈیٹا_انحراف;
    }
    snprintf(buf, حجم(buf), "__%s_start", section_name + 1);
    سیٹ_global_sym(s1, buf, s, 0);
    snprintf(buf, حجم(buf), "__%s_end", section_name + 1);
    سیٹ_global_sym(s1, buf, s, انتہا_انحراف);
}

ST_FUNC خالی جوڑو_array (TCCState *s1, ثابت حرف *sec, صحیح c)
{
    Section *s;
    s = ڈھونڈو_section(s1, sec);
    s->sh_flags = shf_RELRO;
    s->sh_type = sec[1] == 'i' ? SHT_INIT_ARRAY : SHT_FINI_ARRAY;
    put_elf_reloc (s1->symtab, s, s->ڈیٹا_انحراف, R_ڈیٹا_PTR, c);
    section_ptr_جوڑو(s, PTR_سائز);
}

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
ST_FUNC خالی tcc_جوڑو_bcheck(TCCState *s1)
{
    اگر (0 == s1->do_bounds_check)
        واپس;
    section_ptr_جوڑو(bounds_section, حجم(addr_t));
}
#اگر_ختم

/* set symbol to STB_LOCAL and resolve. The point is to not export it as
   a dynamic symbol to allow so's to have one each with a different value. */
ساکن خالی سیٹ_local_sym(TCCState *s1, ثابت حرف *name, Section *s, صحیح انحراف)
{
    صحیح c = ڈھونڈو_elf_sym(s1->symtab, name);
    اگر (c) {
        ElfW(Sym) *esym = (ElfW(Sym)*)s1->symtab->ڈیٹا + c;
        esym->st_info = ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE);
        esym->st_قدر = انحراف;
        esym->st_shndx = s->sh_عدد;
    }
}

/* avoid generating debug/test_coverage code for stub functions */
ساکن خالی tcc_compile_string_no_debug(TCCState *s, ثابت حرف *str)
{
    صحیح save_do_debug = s->do_debug;
    صحیح save_test_coverage = s->test_coverage;

    s->do_debug = 0;
    s->test_coverage = 0;
    tcc_compile_string(s, str);
    s->do_debug = save_do_debug;
    s->test_coverage = save_test_coverage;
}

#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
ساکن خالی put_ptr(TCCState *s1, Section *s, صحیح offs)
{
    صحیح c;
    c = سیٹ_global_sym(s1, تہی, s, offs);
    s = ڈیٹا_section;
    put_elf_reloc (s1->symtab, s, s->ڈیٹا_انحراف, R_ڈیٹا_PTR, c);
    section_ptr_جوڑو(s, PTR_سائز);
}

ST_FUNC خالی tcc_جوڑو_btstub(TCCState *s1)
{
    Section *s;
    صحیح n, o, *p;
    CString cstr;
    ثابت حرف *__rt_info = &"___rt_info"[!s1->leading_underscore];

    s = ڈیٹا_section;
    /* Align to PTR_SIZE */
    section_جوڑو(s, 0, PTR_سائز);
    o = s->ڈیٹا_انحراف;
    /* create a struct rt_context (see tccrun.c) */
    اگر (s1->dwarf) {
        put_ptr(s1, dwarf_سطر_section, 0);
        put_ptr(s1, dwarf_سطر_section, -1);
	اگر (s1->dwarf >= 5)
            put_ptr(s1, dwarf_سطر_str_section, 0);
	ورنہ
            put_ptr(s1, dwarf_str_section, 0);
    }
    ورنہ
    {
        put_ptr(s1, stab_section, 0);
        put_ptr(s1, stab_section, -1);
        put_ptr(s1, stab_section->link, 0);
    }

    /* skip esym_start/esym_end/elf_str (not loaded) */
    section_ptr_جوڑو(s, 3 * PTR_سائز);

    اگر (s1->output_type == TCC_OUTPUT_حافظہ && 0 == s1->dwarf) {
        put_ptr(s1, متن_section, 0);
    } ورنہ {
        /* prog_base : local nameless symbol with offset 0 at SHN_ABS */
        put_ptr(s1, تہی, 0);
#اگر defined TCC_ہدف_MACHO
        /* adjust for __PAGEZERO */
        اگر (s1->dwarf == 0 && s1->output_type == TCC_OUTPUT_EXE)
            write64le(ڈیٹا_section->ڈیٹا + ڈیٹا_section->ڈیٹا_انحراف - PTR_سائز,
	              (uint64_t)1 << 32);
#اگر_ختم
    }
    n = 3 * PTR_سائز;
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (s1->do_bounds_check) {
        put_ptr(s1, bounds_section, 0);
        n -= PTR_سائز;
    }
#اگر_ختم
    section_ptr_جوڑو(s, n);
    p = section_ptr_جوڑو(s, 2 * حجم (صحیح));
    p[0] = s1->rt_عدد_callers;
    p[1] = s1->dwarf;
    // if (s->data_offset - o != 10*PTR_SIZE + 2*sizeof (int)) exit(99);

    اگر (s1->output_type == TCC_OUTPUT_حافظہ) {
        سیٹ_global_sym(s1, __rt_info, s, o);
        واپس;
    }

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern void __bt_init(),__bt_exit(),__bt_init_dll();"
        "static void *__rt_info[];"
        "__attribute__((constructor)) static void __bt_init_rt(){");
#اگر_تعریف_شدہ TCC_ہدف_PE
    اگر (s1->output_type == TCC_OUTPUT_DLL)
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        cstr_printf(&cstr, "__bt_init_dll(%d);", s1->do_bounds_check);
#ورنہ
        cstr_printf(&cstr, "__bt_init_dll(0);");
#اگر_ختم
#اگر_ختم
    cstr_printf(&cstr, "__bt_init(__rt_info,%d);}",
        s1->output_type != TCC_OUTPUT_DLL);
    /* In case dlcose is called by application */
    cstr_printf(&cstr,
        "__attribute__((destructor)) static void __bt_exit_rt(){"
        "__bt_exit(__rt_info);}");
    tcc_compile_string_no_debug(s1, cstr.ڈیٹا);
    cstr_free(&cstr);
    سیٹ_local_sym(s1, __rt_info, s, o);
}
#اگر_ختم /* def CONFIG_TCC_BACKTRACE */

ساکن خالی tcc_tcov_جوڑو_file(TCCState *s1, ثابت حرف *filename)
{
    CString cstr;
    خالی *ptr;
    حرف wd[1024];

    اگر (tcov_section == تہی)
        واپس;
    section_ptr_جوڑو(tcov_section, 1);
    write32le (tcov_section->ڈیٹا, tcov_section->ڈیٹا_انحراف);

    cstr_new (&cstr);
    اگر (filename[0] == '/')
        cstr_printf (&cstr, "%s.tcov", filename);
    ورنہ {
        getcwd (wd, حجم(wd));
        cstr_printf (&cstr, "%s/%s.tcov", wd, filename);
    }
    ptr = section_ptr_جوڑو(tcov_section, cstr.سائز + 1);
    strcpy((حرف *)ptr, cstr.ڈیٹا);
    unlink((حرف *)ptr);
#اگر_تعریف_شدہ _WIN32
    normalize_slashes((حرف *)ptr);
#اگر_ختم
    cstr_free (&cstr);

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern char *__tcov_data[];"
        "extern void __store_test_coverage ();"
        "__attribute__((destructor)) static void __tcov_exit() {"
        "__store_test_coverage(__tcov_data);"
        "}");
    tcc_compile_string_no_debug(s1, cstr.ڈیٹا);
    cstr_free(&cstr);
    سیٹ_local_sym(s1, &"___tcov_data"[!s1->leading_underscore], tcov_section, 0);
}

#اگر_تعریف_شدہ TCC_ہدف_UNIX
/* add libc crt1/crti objects */
ST_FUNC خالی tccelf_جوڑو_crtbegin(TCCState *s1)
{
#اگر TARGETOS_OpenBSD
    اگر (s1->output_type != TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crt0.o");
    اگر (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crtbeginS.o");
    ورنہ
        tcc_جوڑو_crt(s1, "crtbegin.o");
#وگرنہ_اگر TARGETOS_FreeBSD || TARGETOS_NetBSD
    اگر (s1->output_type != TCC_OUTPUT_DLL)
#اگر TARGETOS_FreeBSD
        tcc_جوڑو_crt(s1, "crt1.o");
#ورنہ
        tcc_جوڑو_crt(s1, "crt0.o");
#اگر_ختم
    tcc_جوڑو_crt(s1, "crti.o");
    اگر (s1->static_link)
        tcc_جوڑو_crt(s1, "crtbeginT.o");
    ورنہ اگر (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crtbeginS.o");
    ورنہ
        tcc_جوڑو_crt(s1, "crtbegin.o");
#وگرنہ_اگر TARGETOS_ANDROID
    اگر (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crtbegin_so.o");
    ورنہ
        tcc_جوڑو_crt(s1, "crtbegin_dynamic.o");
#ورنہ
    اگر (s1->output_type != TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crt1.o");
    tcc_جوڑو_crt(s1, "crti.o");
#اگر_ختم
}

ST_FUNC خالی tccelf_جوڑو_crtend(TCCState *s1)
{
#اگر TARGETOS_OpenBSD
    اگر (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crtendS.o");
    ورنہ
        tcc_جوڑو_crt(s1, "crtend.o");
#وگرنہ_اگر TARGETOS_FreeBSD || TARGETOS_NetBSD
    اگر (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crtendS.o");
    ورنہ
        tcc_جوڑو_crt(s1, "crtend.o");
    tcc_جوڑو_crt(s1, "crtn.o");
#وگرنہ_اگر TARGETOS_ANDROID
    اگر (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crtend_so.o");
    ورنہ
        tcc_جوڑو_crt(s1, "crtend_android.o");
#ورنہ
    tcc_جوڑو_crt(s1, "crtn.o");
#اگر_ختم
}
#اگر_ختم /* TCC_TARGET_UNIX */

#اگر_غیر_تعریف_شدہ TCC_ہدف_PE
/* add tcc runtime libraries */
ST_FUNC خالی tcc_جوڑو_runtime(TCCState *s1)
{
    s1->filetype = 0;

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    tcc_جوڑو_bcheck(s1);
#اگر_ختم
    tcc_جوڑو_pragma_libs(s1);

    /* add libc */
    اگر (!s1->nostdlib) {
        صحیح lpthread = s1->option_pthread;

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    اگر (s1->output_type == TCC_OUTPUT_حافظہ)
                tcc_جوڑو_support(s1, "bcheck_run.o");
	    ورنہ
                tcc_جوڑو_support(s1, "bcheck.o");
# اگر !(TARGETOS_OpenBSD || TARGETOS_NetBSD)
            tcc_جوڑو_library(s1, "dl");
# endif
            lpthread = 1;
        }
#اگر_ختم
#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
        اگر (s1->do_backtrace) {
            اگر (s1->output_type & TCC_OUTPUT_EXE)
                tcc_جوڑو_support(s1, "bt-exe.o");
            اگر (s1->output_type != TCC_OUTPUT_DLL)
                tcc_جوڑو_support(s1, "bt-log.o");
            tcc_جوڑو_btstub(s1);
            lpthread = 1;
        }
#اگر_ختم
        اگر (lpthread)
            tcc_جوڑو_library(s1, "pthread");
        tcc_جوڑو_library(s1, "c");
#اگر_تعریف_شدہ TCC_LIBGCC
        اگر (!s1->static_link) {
            اگر (TCC_LIBGCC[0] == '/')
                tcc_جوڑو_file(s1, TCC_LIBGCC);
            ورنہ
                tcc_جوڑو_dll(s1, TCC_LIBGCC, AFF_PRINT_ERROR);
        }
#اگر_ختم
#اگر defined TCC_ہدف_ARM && TARGETOS_FreeBSD
        tcc_جوڑو_library(s1, "gcc_s"); // unwind code
#اگر_ختم
        اگر (TCC_LIBTCC1[0]) {
            tcc_جوڑو_support(s1, TCC_LIBTCC1);
            tcc_جوڑو_library(s1, "c");
        }
#اگر_غیر_تعریف_شدہ TCC_ہدف_MACHO
        اگر (s1->output_type != TCC_OUTPUT_حافظہ)
            tccelf_جوڑو_crtend(s1);
#اگر_ختم
    }
}
#اگر_ختم /* ndef TCC_TARGET_PE */

/* set _etext/_edata/_end  f=0:set  f=1:when_needed  f=2,3:just_update */
ساکن خالی سیٹ_linker_sym(TCCState *s1, ثابت حرف *name, Section *sec, صحیح f)
{
    صحیح sym_اشاریہ, esym_اشاریہ, defined;
    ElfW(Sym) *sym, *esym;
    sym_اشاریہ = ڈھونڈو_elf_sym(symtab_section, name);
    sym = (ElfW(Sym) *)symtab_section->ڈیٹا + sym_اشاریہ;
    esym_اشاریہ = ڈھونڈو_elf_sym(s1->dynsymtab_section, name);
    esym = (ElfW(Sym) *)s1->dynsymtab_section->ڈیٹا + esym_اشاریہ;
    defined = sym->st_shndx != SHN_UNDEF
        || (esym->st_shndx != SHN_UNDEF && esym->st_سائز);
    انتخاب (f) {
    حالت 1: /* old symbols w/o '_' */
        اگر (!(sym_اشاریہ || esym_اشاریہ) || defined)
            توڑو;
    حالت 0:
        اگر (defined) {
            tcc_warning("linker symbol '%s' already defined", name);
            توڑو;
        }
        sym_اشاریہ = سیٹ_global_sym(s1, name, sec, -1);
        get_sym_attr(s1, sym_اشاریہ, 1)->linker_sym = 1;
        توڑو;
    طےشدہ: /* update (bss only) */
        اگر (get_sym_attr(s1, sym_اشاریہ, 0)->linker_sym)
            sym->st_قدر = sec->ڈیٹا_انحراف;
    }
#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
    اگر (name[0] == '_')
        سیٹ_linker_sym(s1, name + 1, sec, f + 1);
#اگر_ختم
}

/* add various standard linker symbols (must be done after the
   sections are filled (for example after allocating common
   symbols)) */
ساکن خالی tcc_جوڑو_linker_symbols(TCCState *s1)
{
    حرف buf[1024];
    صحیح i;
    Section *s;

    سیٹ_linker_sym(s1, "_etext", متن_section, 0);
    سیٹ_linker_sym(s1, "_edata", ڈیٹا_section, 0);
    سیٹ_linker_sym(s1, "_end", bss_section, 0);
#اگر TARGETOS_OpenBSD
    سیٹ_global_sym(s1, "__executable_start", تہی, ELF_آغاز_ADDR);
#اگر_ختم

#اگر_تعریف_شدہ TCC_ہدف_RISCV64
    /* XXX should be .sdata+0x800, not .data+0x800 */
    سیٹ_global_sym(s1, "__global_pointer$", ڈیٹا_section, 0x800);
#اگر_ختم
    /* horrible new standard ldscript defines */
    جوڑو_init_array_متعین_کرتا(s1, ".preinit_array");
    جوڑو_init_array_متعین_کرتا(s1, ".init_array");
    جوڑو_init_array_متعین_کرتا(s1, ".fini_array");
    /* add start and stop symbols for sections whose name can be
       expressed in C */
    برائے(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        اگر ((s->sh_flags & SHF_ALLOC)
            && (s->sh_type == SHT_PROGBITS || s->sh_type == SHT_NOBITS
                || s->sh_type == SHT_STRTAB)) {
            /* check if section name can be expressed in C */
            ثابت حرف *p0, *p;
            p0 = s->name;
            اگر (*p0 == '.')
                ++p0;
            p = p0;
            برائے(;;) {
                صحیح c = *p;
                اگر (!c)
                    توڑو;
                اگر (!isid(c) && !isnum(c))
                    جاؤ اگلا_sec;
                p++;
            }
            snprintf(buf, حجم(buf), "__start_%s", p0);
            سیٹ_global_sym(s1, buf, s, 0);
            snprintf(buf, حجم(buf), "__stop_%s", p0);
            سیٹ_global_sym(s1, buf, s, -1);
        }
    اگلا_sec: ;
    }
}

ST_FUNC خالی resolve_common_syms(TCCState *s1)
{
    ElfW(Sym) *sym;

    /* Allocate common symbols in BSS.  */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        اگر (sym->st_shndx == SHN_COMMON && sym->st_سائز) {
            /* symbol alignment is in st_value for SHN_COMMONs */
	    sym->st_قدر = section_جوڑو(bss_section, sym->st_سائز,
					sym->st_قدر);
            sym->st_shndx = bss_section->sh_عدد;
        }
    }

    /* Now assign linker provided symbols their value.  */
    اگر (s1->output_type != TCC_OUTPUT_DLL)
        tcc_جوڑو_linker_symbols(s1);
}

#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
ST_FUNC خالی fill_got_اندراج(TCCState *s1, ElfW_Rel *rel)
{
    صحیح sym_اشاریہ = ELFW(R_SYM) (rel->r_info);
    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->ڈیٹا)[sym_اشاریہ];
    ساخت sym_attr *attr = get_sym_attr(s1, sym_اشاریہ, 0);
    غیرعلامتی انحراف = attr->got_انحراف;

    اگر (0 == انحراف)
        واپس;
    section_reserve(s1->got, انحراف + PTR_سائز);
#اگر PTR_سائز == 8
    write64le(s1->got->ڈیٹا + انحراف, sym->st_قدر);
#ورنہ
    write32le(s1->got->ڈیٹا + انحراف, sym->st_قدر);
#اگر_ختم
}

/* Perform relocation to GOT or PLT entries */
ST_FUNC خالی fill_got(TCCState *s1)
{
    Section *s;
    ElfW_Rel *rel;
    صحیح i;

    برائے(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        اگر (s->sh_type != SHT_RELX)
            جاری;
        /* no need to handle got relocations */
        اگر (s->link != symtab_section)
            جاری;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            انتخاب (ELFW(R_TYPE) (rel->r_info)) {
                حالت R_X86_64_GOT32:
                حالت R_X86_64_GOTPCREL:
		حالت R_X86_64_GOTPCRELX:
		حالت R_X86_64_REX_GOTPCRELX:
                حالت R_X86_64_PLT32:
                    fill_got_اندراج(s1, rel);
                    توڑو;
            }
        }
    }
}

/* See put_got_entry for a description.  This is the second stage
   where GOT references to local defined symbols are rewritten.  */
ساکن خالی fill_local_got_entries(TCCState *s1)
{
    ElfW_Rel *rel;
    اگر (!s1->got->reloc)
        واپس;
    for_each_elem(s1->got->reloc, 0, rel, ElfW_Rel) {
	اگر (ELFW(R_TYPE)(rel->r_info) == R_RELATIVE) {
	    صحیح sym_اشاریہ = ELFW(R_SYM) (rel->r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->ڈیٹا)[sym_اشاریہ];
	    ساخت sym_attr *attr = get_sym_attr(s1, sym_اشاریہ, 0);
	    غیرعلامتی انحراف = attr->got_انحراف;
	    اگر (انحراف != rel->r_انحراف - s1->got->sh_addr)
	        tcc_error_noabort("fill_local_got_entries: huh?");
	    rel->r_info = ELFW(R_INFO)(0, R_RELATIVE);
#اگر SHT_RELX == SHT_RELA
	    rel->r_addend = sym->st_قدر;
#ورنہ
	    /* All our REL architectures also happen to be 32bit LE.  */
	    write32le(s1->got->ڈیٹا + انحراف, sym->st_قدر);
#اگر_ختم
	}
    }
}

/* Bind symbols of executable: resolve undefined symbols from exported symbols
   in shared libraries */
ساکن خالی bind_exe_dynsyms(TCCState *s1, صحیح is_PIE)
{
    ثابت حرف *name;
    صحیح sym_اشاریہ, اشاریہ;
    ElfW(Sym) *sym, *esym;
    صحیح type;

    /* Resolve undefined symbols from dynamic symbols. When there is a match:
       - if STT_FUNC or STT_GNU_IFUNC symbol -> add it in PLT
       - if STT_OBJECT symbol -> add it in .bss section with suitable reloc */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        اگر (sym->st_shndx == SHN_UNDEF
            /* bss symbols may be initialized in the shared library */
            || sym->st_shndx == SHN_COMMON
            || sym->st_shndx == bss_section->sh_عدد) {
            name = (حرف *) symtab_section->link->ڈیٹا + sym->st_name;
            sym_اشاریہ = ڈھونڈو_elf_sym(s1->dynsymtab_section, name);
            esym = &((ElfW(Sym) *)s1->dynsymtab_section->ڈیٹا)[sym_اشاریہ];
            اگر (sym_اشاریہ && esym->st_shndx != SHN_UNDEF) {
                اگر (is_PIE)
                    جاری;
                type = ELFW(ST_TYPE)(esym->st_info);
                اگر ((type == STT_FUNC) || (type == STT_GNU_IFUNC)) {
                    /* Indirect functions shall have STT_FUNC type in executable
                     * dynsym section. Indeed, a dlsym call following a lazy
                     * resolution would pick the symbol value from the
                     * executable dynsym entry which would contain the address
                     * of the function wanted by the caller of dlsym instead of
                     * the address of the function that would return that
                     * address */
                    صحیح dynindex
		      = put_elf_sym(s1->dynsym, 0, esym->st_سائز,
				    ELFW(ST_INFO)(STB_GLOBAL,STT_FUNC), 0, 0,
				    name);
		    صحیح اشاریہ = sym - (ElfW(Sym) *) symtab_section->ڈیٹا;
		    get_sym_attr(s1, اشاریہ, 1)->dyn_اشاریہ = dynindex;
                } ورنہ اگر (type == STT_OBJECT) {
                    غیرعلامتی طویل انحراف;
                    ElfW(Sym) *dynsym;
                    اگر (sym->st_shndx == bss_section->sh_عدد) {
                        انحراف = sym->st_قدر;
                    } ورنہ {
                        انحراف = bss_section->ڈیٹا_انحراف;
                        /* XXX: which alignment ? */
                        انحراف = (انحراف + 16 - 1) & -16;
                        bss_section->ڈیٹا_انحراف = انحراف + esym->st_سائز;
                    }
                    سیٹ_elf_sym (s1->symtab, انحراف, esym->st_سائز,
                                 esym->st_info, 0, bss_section->sh_عدد, name);
                    اشاریہ = put_elf_sym(s1->dynsym, انحراف, esym->st_سائز,
                                        esym->st_info, 0, bss_section->sh_عدد,
                                        name);
                    /* Ensure R_COPY works for weak symbol aliases */
                    اگر (ELFW(ST_BIND)(esym->st_info) == STB_WEAK) {
                        for_each_elem(s1->dynsymtab_section, 1, dynsym, ElfW(Sym)) {
                            اگر ((dynsym->st_قدر == esym->st_قدر)
                                && (ELFW(ST_BIND)(dynsym->st_info) == STB_GLOBAL)) {
                                حرف *dynname = (حرف *) s1->dynsymtab_section->link->ڈیٹا
                                                + dynsym->st_name;
                                put_elf_sym(s1->dynsym, انحراف, dynsym->st_سائز,
                                            dynsym->st_info, 0,
                                            bss_section->sh_عدد, dynname);
                                توڑو;
                            }
                        }
                    }
                    put_elf_reloc(s1->dynsym, bss_section,
                                  انحراف, R_COPY, اشاریہ);
                }
            } ورنہ اگر (sym->st_shndx == SHN_UNDEF) {
                /* STB_WEAK undefined symbols are accepted */
                /* XXX: _fp_hw seems to be part of the ABI, so we ignore it */
                اگر (ELFW(ST_BIND)(sym->st_info) == STB_WEAK ||
                    !strcmp(name, "_fp_hw")) {
                } ورنہ {
                    tcc_error_noabort("unresolved reference to '%s'", name);
                }
            }
        }
    }
    /* update _end symbol with new bss length */
    سیٹ_linker_sym(s1, "_end", bss_section, 2);
}

/* Bind symbols of libraries: export all non local symbols of executable that
   are referenced by shared libraries. The reason is that the dynamic loader
   search symbol first in executable and then in libraries. Therefore a
   reference to a symbol already defined by a library can still be resolved by
   a symbol in the executable.   With -rdynamic, export all defined symbols */
ساکن خالی bind_libs_dynsyms(TCCState *s1)
{
    ثابت حرف *name;
    صحیح dynsym_اشاریہ;
    ElfW(Sym) *sym, *esym;

    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        name = (حرف *)symtab_section->link->ڈیٹا + sym->st_name;
        dynsym_اشاریہ = ڈھونڈو_elf_sym(s1->dynsymtab_section, name);
        اگر (sym->st_shndx != SHN_UNDEF) {
            اگر (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL
                && (dynsym_اشاریہ || s1->rdynamic))
                سیٹ_elf_sym(s1->dynsym, sym->st_قدر, sym->st_سائز,
                            sym->st_info, 0, sym->st_shndx, name);
        } ورنہ اگر (dynsym_اشاریہ) {
            esym = (ElfW(Sym) *)s1->dynsymtab_section->ڈیٹا + dynsym_اشاریہ;
            اگر (esym->st_shndx == SHN_UNDEF) {
                /* weak symbols can stay undefined */
                اگر (ELFW(ST_BIND)(esym->st_info) != STB_WEAK)
                    tcc_warning("unresolved dynamic reference to '%s'", name);
            }
        }
    }
}

/* Export all non local symbols. This is used by shared libraries so that the
   non local symbols they define can resolve a reference in another shared
   library or in the executable. Correspondingly, it allows undefined local
   symbols to be resolved by other shared libraries or by the executable. */
ساکن خالی export_global_syms(TCCState *s1)
{
    صحیح dynindex, اشاریہ;
    ثابت حرف *name;
    ElfW(Sym) *sym;
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        اگر (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
	    name = (حرف *) symtab_section->link->ڈیٹا + sym->st_name;
	    dynindex = سیٹ_elf_sym(s1->dynsym, sym->st_قدر, sym->st_سائز,
				   sym->st_info, 0, sym->st_shndx, name);
	    اشاریہ = sym - (ElfW(Sym) *) symtab_section->ڈیٹا;
            get_sym_attr(s1, اشاریہ, 1)->dyn_اشاریہ = dynindex;
        }
    }
}

/* decide if an unallocated section should be output. */
ساکن صحیح سیٹ_sec_sizes(TCCState *s1)
{
    صحیح i;
    Section *s;
    صحیح textrel = 0;
    صحیح file_type = s1->output_type;

    /* Allocate strings for section names */
    برائے(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        اگر (s->sh_type == SHT_RELX && !(s->sh_flags & SHF_ALLOC)) {
            /* when generating a DLL, we include relocations but
               we may patch them */
            اگر ((file_type & TCC_OUTPUT_DYN)
                && (s1->sections[s->sh_info]->sh_flags & SHF_ALLOC)) {
                صحیح گنتی_2 = prepare_dynamic_rel(s1, s);
                اگر (گنتی_2) {
                    /* allocate the section */
                    s->sh_flags |= SHF_ALLOC;
                    s->sh_سائز = گنتی_2 * حجم(ElfW_Rel);
                    اگر (s1->sections[s->sh_info]->sh_flags & SHF_EXECINSTR)
                        textrel += گنتی_2;
                }
            }
        } ورنہ اگر ((s->sh_flags & SHF_ALLOC)
#اگر_تعریف_شدہ TCC_ہدف_ARM
                   || s->sh_type == SHT_ARM_اوصاف
#اگر_ختم
                   || s1->do_debug) {
            s->sh_سائز = s->ڈیٹا_انحراف;
        }
    }
    واپس textrel;
}

/* various data used under elf_output_file() */
ساخت dyn_inf {
    Section *dynamic;
    Section *dynstr;
    Section *interp;
    Section *note;
    Section *gnu_hash;
    ساخت {
        /* Info to be copied in dynamic section */
        غیرعلامتی طویل ڈیٹا_انحراف;
        addr_t rel_addr;
        addr_t rel_سائز;
    };

    ElfW(Phdr) *phdr;
    صحیح phnum;
    صحیح shnum;
    صحیح tls;
    صحیح relro;
    صحیح notes;
    صحیح ehfr;
    صحیح dyna;
};

/* Decide the layout of sections loaded in memory. This must be done before
   program headers are filled since they contain info about the layout.
   We do the following ordering: interp, symbol tables, relocations, progbits,
   nobits */
ساکن صحیح ترتیب_دو_sections(TCCState *s1, صحیح *sec_ترتیب, ساخت dyn_inf *d)
{
    Section *s;
    صحیح i, j, k, f, f0, n;
    صحیح nb_sections = s1->nb_sections;
    صحیح *sec_cls = sec_ترتیب + nb_sections;
    صحیح tls_align = 0; /* need common alignment for all tls sections */

    برائے (i = 1; i < nb_sections; i++) {
        s = s1->sections[i];
        اگر (0 == s->sh_name) {
            j = 0x900; /* no sh_name: won't go to file */
        } ورنہ اگر (s->sh_flags & SHF_ALLOC) {
            j = 0x100;
            اگر ((s->sh_flags & (SHF_WRITE|SHF_TLS)) == SHF_WRITE)
                j = 0x200;
        } ورنہ {
            j = 0x700;
        }
        اگر (j >= 0x700 && s1->output_format != TCC_OUTPUT_FORMAT_ELF)
            s->sh_سائز = 0, j = 0x900;

        اگر (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM) {
            k = 0x10;
        } ورنہ اگر (s->sh_type == SHT_STRTAB && strcmp(s->name, ".stabstr")) {
            k = 0x11;
            اگر (i == nb_sections - 1) /* ".shstrtab" assumed to stay last */
                k = 0xff;
        } ورنہ اگر (s->sh_type == SHT_HASH || s->sh_type == SHT_GNU_HASH) {
            k = 0x12;
        } ورنہ اگر (s->sh_type == SHT_GNU_verdef
                  || s->sh_type == SHT_GNU_verneed
                  || s->sh_type == SHT_GNU_versym) {
            k = 0x13;
        } ورنہ اگر (s->sh_type == SHT_RELX) {
            k = 0x20;
            اگر (s1->plt && s == s1->plt->reloc)
                k = 0x21;
        } ورنہ اگر (s->sh_flags & SHF_EXECINSTR) {
            k = 0x60;
        /* RELRO sections --> */
        } ورنہ اگر (s->sh_flags & SHF_TLS) {
            اگر (s->sh_addralign > tls_align)
                tls_align = s->sh_addralign;
            k = 0x40 + (s->sh_type == SHT_NOBITS);
        } ورنہ اگر (s->sh_type == SHT_PREINIT_ARRAY) {
            k = 0x42;
        } ورنہ اگر (s->sh_type == SHT_INIT_ARRAY) {
            k = 0x43;
        } ورنہ اگر (s->sh_type == SHT_FINI_ARRAY) {
            k = 0x44;
        } ورنہ اگر (s->sh_type == SHT_DYNAMIC) {
            k = 0x48;
        } ورنہ اگر (s == s1->got) {
            k = 0x49; /* .got as RELRO needs BIND_NOW in DT_FLAGS */
        } ورنہ اگر (s->reloc && (s->reloc->sh_flags & SHF_ALLOC) && j == 0x100) {
            k = 0x45; /* +1 for data.ro */
        /* <-- */
        } ورنہ اگر (s->sh_type == SHT_NOTE) {
            k = 0x08, d->notes = 1;
        } ورنہ اگر (s->sh_type == SHT_NOBITS) {
            k = 0x70; /* bss */
        } ورنہ اگر (s == d->interp) {
            k = 0x00;
        } ورنہ {
            k = 0x50; /*ڈیٹا*/
        }
        k += j;
        /* make our standard sections come last to have _etext/_edata correct values */
        اگر (s->sh_عدد <= bss_section->sh_عدد)
            ++k;
        /* make RELRO section writable */
        اگر ((k & 0xfff0) == 0x140)
            k += 0x100, s->sh_flags |= SHF_WRITE;
        /* sort by insert */
        برائے (n = i; n > 1 && k < (f = sec_cls[n - 1]); --n)
            sec_cls[n] = f, sec_ترتیب[n] = sec_ترتیب[n - 1];
        sec_cls[n] = k, sec_ترتیب[n] = i;
    }
    sec_ترتیب[0] = 0;
    d->shnum = 1;

#تعریف_کرو SHFX_NEWPH (1 << 4)
#تعریف_کرو SHFX_RELRO (1 << 5)

    /* count PT_LOAD headers needed */
    n = f0 = 0;
    برائے (i = 1; i < nb_sections; i++) {
        s = s1->sections[sec_ترتیب[i]];
        k = sec_cls[i];
        f = 0;
        اگر (k < 0x900)
            ++d->shnum;
        اگر (k < 0x700) {
            f = s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR);
#اگر TARGETOS_NetBSD || TARGETOS_FreeBSD
	    /* NetBSD only supports 2 PT_LOAD sections.
	       See: https://blog.netbsd.org/tnf/entry/the_first_report_on_lld */
	    اگر ((f & SHF_WRITE) == 0)
                f |= SHF_EXECINSTR;
            k = 0; /* no relro */
#اگر_ختم
            اگر ((k & 0xfff0) == 0x240) /* RELRO sections */
                d->relro = 1, f |= SHFX_RELRO;
            /* start new header when flags changed, but avoid zero memsz */
            اگر (f != f0 && s->sh_سائز)
                f0 = f, ++n, f |= SHFX_NEWPH;
            اگر ((s->sh_flags & SHF_TLS) && s->sh_سائز) {
                s->sh_addralign = tls_align;
                d->tls = 1, f |= SHF_TLS;
            }
        }
        sec_cls[i] = f;
        //printf("ph %d sec %02d : %3X %3X  %8.2X  %04X  %s\n", (f>0) * n, i, f, k, s->sh_type, (int)s->sh_size, s->name);
    }
    واپس n;
}

ساکن ElfW(Phdr) *fill_phdr(ElfW(Phdr) *ph, صحیح type, Section *s)
{
    ph->p_type = type;
    ph->p_flags = PF_R;
    اگر (s) {
        اگر (s->sh_flags & SHF_WRITE)
            ph->p_flags |= PF_W;
        ph->p_انحراف = s->sh_انحراف;
        ph->p_vaddr = s->sh_addr;
        ph->p_filesz = s->sh_سائز;
        ph->p_align = s->sh_addralign;
    }
    ph->p_paddr = ph->p_vaddr;
    ph->p_memsz = ph->p_filesz;
    واپس ph;
}

ساکن ElfW(Phdr) *update_phdr(ElfW(Phdr) *ph, صحیح type, Section *s, addr_t addr, صحیح file_انحراف)
{
    اگر (ph->p_type == 0) {
        fill_phdr(ph, type, s);
    }
    ph->p_filesz = file_انحراف - ph->p_انحراف;
    ph->p_memsz = addr - ph->p_vaddr;
    واپس ph;
}

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
ساکن صحیح layout_sections(TCCState *s1, صحیح *sec_ترتیب, ساخت dyn_inf *d)
{
    Section *s;
    addr_t addr, tmp, align, s_align, بنیاد;
    ElfW(Phdr) *ph = تہی, *ph2;
    صحیح i, f, n, phnum, phfill;
    صحیح file_انحراف;

    /* compute number of program headers */
    phnum = ترتیب_دو_sections(s1, sec_ترتیب, d);
    phfill = 0; /* set to 1 to have dll's with a PT_PHDR */
    اگر (d->interp)
        phfill = 2;
    phnum += phfill;
    اگر (d->dynamic)
        d->dyna = phnum++;
    اگر (d->notes)
        d->notes = phnum++;
    اگر (d->tls)
        d->tls = phnum++;
    اگر (eh_چوکھٹا_hdr_section)
        d->ehfr = phnum++;
    اگر (d->relro)
        d->relro = phnum++;
    d->phnum = phnum;
    d->phdr = tcc_mallocz(phnum * حجم(ElfW(Phdr)));

    file_انحراف = 0;
    اگر (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
        file_انحراف = (حجم(ElfW(Ehdr)) + phnum * حجم(ElfW(Phdr)) + 3) & -4;
        file_انحراف += d->shnum * حجم (ElfW(Shdr));
    }

    s_align = ELF_صفحہ_سائز;
    اگر (s1->section_align)
        s_align = s1->section_align;

    addr = ELF_آغاز_ADDR;
    اگر (s1->output_type & TCC_OUTPUT_DYN)
        addr = 0;

    اگر (s1->has_متن_addr) {
        addr = s1->متن_addr;
        اگر (0) {
            صحیح a_انحراف, p_انحراف;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_انحراف = (صحیح) (addr & (s_align - 1));
            p_انحراف = file_انحراف & (s_align - 1);
            اگر (a_انحراف < p_انحراف)
                a_انحراف += s_align;
            file_انحراف += (a_انحراف - p_انحراف);
        }
    }
    بنیاد = addr;
    /* compute address after headers */
    addr += file_انحراف;

    n = 0;
    برائے(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_ترتیب[i]];
        f = sec_ترتیب[i + s1->nb_sections];
        align = s->sh_addralign - 1;

        اگر (f == 0) { /* no alloc */
            file_انحراف = (file_انحراف + align) & ~align;
            s->sh_انحراف = file_انحراف;
            اگر (s->sh_type != SHT_NOBITS)
                file_انحراف += s->sh_سائز;
            جاری;
        }

        اگر ((f & SHFX_NEWPH) && n) {
            /* different rwx section flags */
            اگر (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
                /* if in the middle of a page, w e duplicate the page in
                   memory so that one copy is RX and the other is RW */
                اگر ((addr & (s_align - 1)) != 0)
                    addr += s_align;
            } ورنہ {
                align = s_align - 1;
            }
        }

        tmp = addr;
        addr = (addr + align) & ~align;
        file_انحراف += (صحیح)(addr - tmp);
        s->sh_انحراف = file_انحراف;
        s->sh_addr = addr;

        //printf("%d : %08x %08x %04x %03x %s %d\n", n, (int)file_offset, (int)addr, (int)s->sh_size, s->sh_type, s->name, align + 1);
        addr += s->sh_سائز;
        اگر (s->sh_type != SHT_NOBITS)
            file_انحراف += s->sh_سائز;

        اگر (f & SHFX_NEWPH) {
            /* set new program header */
            ph = &d->phdr[phfill + n];
            fill_phdr(ph, PT_بھرو, s);
            ph->p_align = s_align;
            اگر (f & SHF_EXECINSTR)
                ph->p_flags |= PF_X;
            اگر (n == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_انحراف = 0;
                ph->p_paddr = ph->p_vaddr = بنیاد;
            }
            ++n;
        }

        اگر (ph)
            update_phdr(ph, 0, 0, addr, file_انحراف);

        اگر (f & SHFX_RELRO) {
            ph2 = update_phdr(&d->phdr[d->relro], PT_GNU_RELRO, s, addr, file_انحراف);
            ph2->p_align = 1;
        }
        اگر (f & SHF_TLS) {
            ph2 = update_phdr(&d->phdr[d->tls], PT_TLS, s, addr, file_انحراف);
            اگر (s->sh_type == SHT_NOBITS)
                addr -= s->sh_سائز;
            /* for xxx-link.c:relocate() */
            s1->tls_آغاز = ph2->p_vaddr;
            s1->tls_انتہا = s1->tls_آغاز + ph2->p_memsz + (-ph2->p_memsz & (ph2->p_align - 1));
        }
        اگر (s->sh_type == SHT_NOTE) {
            update_phdr(&d->phdr[d->notes], PT_NOTE, s, addr, file_انحراف);
        }
    }

    /* Fill other headers */
    اگر (d->dyna)
        fill_phdr(&d->phdr[d->dyna], PT_DYNAMIC, d->dynamic);
    اگر (d->ehfr)
        fill_phdr(&d->phdr[d->ehfr], PT_GNU_EH_چوکھٹا, eh_چوکھٹا_hdr_section);
    اگر (d->interp)
        fill_phdr(&d->phdr[1], PT_INTERP, d->interp);
    اگر (phfill) {
        ph = &d->phdr[0];
        ph->p_انحراف = حجم(ElfW(Ehdr));
        ph->p_vaddr = بنیاد + ph->p_انحراف;
        ph->p_filesz = phnum * حجم(ElfW(Phdr));
        ph->p_align = 4;
        fill_phdr(ph, PT_PHDR, تہی);
    }
    واپس 0;
}

/* put dynamic tag */
ساکن خالی put_dt(Section *dynamic, صحیح dt, addr_t val)
{
    ElfW(Dyn) *dyn;
    dyn = section_ptr_جوڑو(dynamic, حجم(ElfW(Dyn)));
    dyn->d_لیبل = dt;
    dyn->d_un.d_val = val;
}

/* Fill the dynamic section with tags describing the address and size of
   sections */
ساکن خالی fill_dynamic(TCCState *s1, ساخت dyn_inf *dyninf)
{
    Section *dynamic = dyninf->dynamic;
    Section *s;

    /* put dynamic section entries */
    put_dt(dynamic, DT_HASH, s1->dynsym->hash->sh_addr);
    put_dt(dynamic, DT_GNU_HASH, dyninf->gnu_hash->sh_addr);
    put_dt(dynamic, DT_STRTAB, dyninf->dynstr->sh_addr);
    put_dt(dynamic, DT_SYMTAB, s1->dynsym->sh_addr);
    put_dt(dynamic, DT_STRSZ, dyninf->dynstr->ڈیٹا_انحراف);
    put_dt(dynamic, DT_SYMENT, حجم(ElfW(Sym)));
#اگر PTR_سائز == 8
    put_dt(dynamic, DT_RELA, dyninf->rel_addr);
    put_dt(dynamic, DT_RELASZ, dyninf->rel_سائز);
    put_dt(dynamic, DT_RELAENT, حجم(ElfW_Rel));
    اگر (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->ڈیٹا_انحراف);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_RELA);
    }
    put_dt(dynamic, DT_RELACOUNT, 0);
#ورنہ
    put_dt(dynamic, DT_REL, dyninf->rel_addr);
    put_dt(dynamic, DT_RELSZ, dyninf->rel_سائز);
    put_dt(dynamic, DT_RELENT, حجم(ElfW_Rel));
    اگر (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->ڈیٹا_انحراف);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_REL);
    }
    put_dt(dynamic, DT_RELCOUNT, 0);
#اگر_ختم
    اگر (versym_section && verneed_section) {
	/* The dynamic linker can not handle VERSYM without VERNEED */
        put_dt(dynamic, DT_VERSYM, versym_section->sh_addr);
        put_dt(dynamic, DT_VERNEED, verneed_section->sh_addr);
        put_dt(dynamic, DT_VERNEEDNUM, dt_verneednum);
    }
    s = have_section(s1, ".preinit_array");
    اگر (s && s->ڈیٹا_انحراف) {
        put_dt(dynamic, DT_PREINIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_PREINIT_ARRAYSZ, s->ڈیٹا_انحراف);
    }
    s = have_section(s1, ".init_array");
    اگر (s && s->ڈیٹا_انحراف) {
        put_dt(dynamic, DT_INIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_INIT_ARRAYSZ, s->ڈیٹا_انحراف);
    }
    s = have_section(s1, ".fini_array");
    اگر (s && s->ڈیٹا_انحراف) {
        put_dt(dynamic, DT_FINI_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_FINI_ARRAYSZ, s->ڈیٹا_انحراف);
    }
    s = have_section(s1, ".init");
    اگر (s && s->ڈیٹا_انحراف) {
        put_dt(dynamic, DT_INIT, s->sh_addr);
    }
    s = have_section(s1, ".fini");
    اگر (s && s->ڈیٹا_انحراف) {
        put_dt(dynamic, DT_FINI, s->sh_addr);
    }
    اگر (s1->do_debug)
        put_dt(dynamic, DT_DEBUG, 0);
    put_dt(dynamic, DT_NULL, 0);
}

/* Remove gaps between RELX sections.
   These gaps are a result of final_sections_reloc. Here some relocs are removed.
   The gaps are then filled with 0 in tcc_output_elf. The 0 is intepreted as
   R_...NONE reloc. This does work on most targets but on OpenBSD/arm64 this
   is illegal. OpenBSD/arm64 does not support R_...NONE reloc. */
ساکن خالی update_reloc_sections(TCCState *s1, ساخت dyn_inf *dyninf)
{
    صحیح i;
    غیرعلامتی طویل file_انحراف = 0;
    Section *s;
    Section *relocplt = s1->plt ? s1->plt->reloc : تہی;

    /* dynamic relocation table information, for .dynamic section */
    dyninf->rel_addr = dyninf->rel_سائز = 0;

    برائے(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
	اگر (s->sh_type == SHT_RELX && s != relocplt) {
	    اگر (dyninf->rel_سائز == 0) {
		dyninf->rel_addr = s->sh_addr;
		file_انحراف = s->sh_انحراف;
	    }
	    ورنہ {
		s->sh_addr = dyninf->rel_addr + dyninf->rel_سائز;
		s->sh_انحراف = file_انحراف + dyninf->rel_سائز;
	    }
	    dyninf->rel_سائز += s->sh_سائز;
	}
    }
}
#اگر_ختم /* ndef ELF_OBJ_ONLY */

/* Create an ELF file on disk.
   This function handle ELF specific layout requirements */
ساکن صحیح tcc_output_elf(TCCState *s1, FILE *f, صحیح phnum, ElfW(Phdr) *phdr)
{
    صحیح i, shnum, انحراف, سائز, file_type;
    Section *s;
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) shdr, *sh;

    file_type = s1->output_type;
    shnum = s1->nb_sections;

    memset(&ehdr, 0, حجم(ehdr));
    اگر (phnum > 0) {
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

#اگر TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    ehdr.e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
#وگرنہ_اگر TARGETOS_OpenBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_OPENBSD;
#وگرنہ_اگر TARGETOS_NetBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_NETBSD;
#وگرنہ_اگر defined TCC_ہدف_ARM && defined TCC_ARM_EABI
    ehdr.e_flags = EF_ARM_EABI_VER5;
    ehdr.e_flags |= s1->float_abi == ARM_HARD_FLOAT
        ? EF_ARM_VFP_FLOAT : EF_ARM_SOFT_FLOAT;
#وگرنہ_اگر defined TCC_ہدف_ARM
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#وگرنہ_اگر defined TCC_ہدف_RISCV64
    /* XXX should be configurable */
    ehdr.e_flags = EF_RISCV_FLOAT_ABI_DOUBLE;
#اگر_ختم

    اگر (file_type == TCC_OUTPUT_OBJ) {
        ehdr.e_type = ET_REL;
    } ورنہ {
        اگر (file_type & TCC_OUTPUT_DYN)
            ehdr.e_type = ET_DYN;
        ورنہ
            ehdr.e_type = ET_EXEC;
        اگر (s1->elf_entryname)
            ehdr.e_اندراج = get_sym_addr(s1, s1->elf_entryname, 1, 0);
        ورنہ
            ehdr.e_اندراج = get_sym_addr(s1, "_start", !!(file_type & TCC_OUTPUT_EXE), 0);
        اگر (ehdr.e_اندراج == (addr_t)-1)
            ehdr.e_اندراج = متن_section->sh_addr;
        اگر (s1->nb_errors)
            واپس -1;
    }

    ترتیب_دو_syms(s1, s1->symtab);

    ehdr.e_machine = EM_TCC_ہدف;
    ehdr.e_نسخہ = EV_CURRENT;
    ehdr.e_shoff = (حجم(ElfW(Ehdr)) + phnum * حجم(ElfW(Phdr)) + 3) & -4;
    ehdr.e_ehsize = حجم(ElfW(Ehdr));
    ehdr.e_shentsize = حجم(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    انحراف = fwrite(&ehdr, 1, حجم(ElfW(Ehdr)), f);
    اگر (phdr)
        انحراف += fwrite(phdr, 1, phnum * حجم(ElfW(Phdr)), f);

    /* output section headers */
    جب (انحراف < ehdr.e_shoff) {
        fputc(0, f);
        انحراف++;
    }

    برائے(i = 0; i < shnum; i++) {
        sh = &shdr;
        memset(sh, 0, حجم(ElfW(Shdr)));
        اگر (i) {
            s = s1->sections[i];
            sh->sh_name = s->sh_name;
            sh->sh_type = s->sh_type;
            sh->sh_flags = s->sh_flags;
            sh->sh_entsize = s->sh_entsize;
            sh->sh_info = s->sh_info;
            اگر (s->link)
                sh->sh_link = s->link->sh_عدد;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_انحراف = s->sh_انحراف;
            sh->sh_سائز = s->sh_سائز;
        }
        انحراف += fwrite(sh, 1, حجم(ElfW(Shdr)), f);
    }

    /* output sections */
    برائے(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        اگر (s->sh_type != SHT_NOBITS) {
            جب (انحراف < s->sh_انحراف) {
                fputc(0, f);
                انحراف++;
            }
            سائز = s->sh_سائز;
            اگر (سائز)
                انحراف += fwrite(s->ڈیٹا, 1, سائز, f);
        }
    }
    واپس 0;
}

ساکن صحیح tcc_output_ثنائی(TCCState *s1, FILE *f)
{
    Section *s;
    صحیح i, انحراف, سائز;

    انحراف = 0;
    برائے(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[i];
        اگر (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            جب (انحراف < s->sh_انحراف) {
                fputc(0, f);
                انحراف++;
            }
            سائز = s->sh_سائز;
            fwrite(s->ڈیٹا, 1, سائز, f);
            انحراف += سائز;
        }
    }
    واپس 0;
}

/* Write an elf, coff or "binary" file */
ساکن صحیح tcc_write_elf_file(TCCState *s1, ثابت حرف *filename, صحیح phnum,
                              ElfW(Phdr) *phdr)
{
    صحیح fd, منوال, file_type, ret;
    FILE *f;

    file_type = s1->output_type;
    اگر (file_type == TCC_OUTPUT_OBJ)
        منوال = 0666;
    ورنہ
        منوال = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_ثنائی_2, منوال);
    اگر (fd < 0 || (f = fdopen(fd, "wb")) == تہی)
        واپس tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
    اگر (s1->verbose)
        لکھو("<- %s\n", filename);
#اگر_تعریف_شدہ TCC_ہدف_COFF
    اگر (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    ورنہ
#اگر_ختم
    اگر (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        ret = tcc_output_elf(s1, f, phnum, phdr);
    ورنہ
        ret = tcc_output_ثنائی(s1, f);
    fclose(f);

    واپس ret;
}

#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
/* order sections according to sec_order, remove sections
   that we aren't going to output.  */
ساکن خالی reorder_sections(TCCState *s1, صحیح *sec_ترتیب)
{
    صحیح i, nnew, k, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    backmap = tcc_malloc(s1->nb_sections * حجم(backmap[0]));
    برائے (i = 0, nnew = 0, snew = تہی; i < s1->nb_sections; i++) {
	k = sec_ترتیب ? sec_ترتیب[i] : i;
	s = s1->sections[k];
	اگر (!i || s->sh_name) {
	    backmap[k] = nnew;
            dynarray_جوڑو(&snew, &nnew, s);
	} ورنہ {
	    backmap[k] = 0;
            /* just remember to free them later */
	    dynarray_جوڑو(&s1->priv_sections, &s1->nb_priv_sections, s);
	}
    }
    برائے (i = 1; i < nnew; i++) {
	s = snew[i];
        s->sh_عدد = i;
        اگر (s->sh_type == SHT_RELX)
            s->sh_info = backmap[s->sh_info];
        ورنہ اگر (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM)
            for_each_elem(s, 1, sym, ElfW(Sym))
                اگر (sym->st_shndx < s1->nb_sections)
                    sym->st_shndx = backmap[sym->st_shndx];
    }
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}

#اگر_تعریف_شدہ TCC_ہدف_ARM
ساکن خالی create_arm_attribute_section(TCCState *s1)
{
   // Needed for DLL support.
    ساکن ثابت غیرعلامتی حرف arm_attr[] = {
        0x41,                            // 'A'
        0x2c, 0x00, 0x00, 0x00,          // size 0x2c
        'a', 'e', 'a', 'b', 'i', 0x00,   // "aeabi"
        0x01, 0x22, 0x00, 0x00, 0x00,    // 'File Attributes', size 0x22
        0x05, 0x36, 0x00,                // 'CPU_name', "6"
#اگر CONFIG_TCC_CPUVER >= 7
        0x06, 0x0a,                      // 'CPU_arch', 'v7'
#ورنہ
        0x06, 0x06,                      // 'CPU_arch', 'v6'
#اگر_ختم
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
    Section *attr = new_section(s1, ".ARM.attributes", SHT_ARM_اوصاف, 0);
    غیرعلامتی حرف *ptr = section_ptr_جوڑو(attr, حجم(arm_attr));
    attr->sh_addralign = 1;
    حافظہ_نقل(ptr, arm_attr, حجم(arm_attr));
    اگر (s1->float_abi != ARM_HARD_FLOAT) {
        ptr[26] = 0x00; // 'FP_arch', 'No'
        ptr[41] = 0x1e; // 'ABI_optimization_goals'
        ptr[42] = 0x06; // 'Aggressive Debug'
    }
}
#اگر_ختم

#اگر_تعریف_شدہ TCC_ہدف_RISCV64
ساکن خالی create_riscv_attribute_section(TCCState *s1)
{
    ساکن ثابت غیرعلامتی حرف riscv_attr[] = {
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
    Section *attr = new_section(s1, ".riscv.attributes", SHT_RISCV_اوصاف, 0);
    غیرعلامتی حرف *ptr = section_ptr_جوڑو(attr, حجم(riscv_attr));
    attr->sh_addralign = 1;
    حافظہ_نقل(ptr, riscv_attr, حجم(riscv_attr));
}
#اگر_ختم

#اگر TARGETOS_OpenBSD || TARGETOS_NetBSD || TARGETOS_FreeBSD

ساکن خالی fill_bsd_note(Section *s, صحیح type,
			  ثابت حرف *قدر, uint32_t ڈیٹا)
{
    غیرعلامتی طویل انحراف = 0;
    حرف *ptr;
    ElfW(Nhdr) *note;
    صحیح align = s->sh_addralign;

    /* check if type present */
    جب (انحراف + حجم(ElfW(Nhdr)) < s->ڈیٹا_انحراف) {
        note = (ElfW(Nhdr) *) (s->ڈیٹا + انحراف);
	اگر (note->n_type == type)
	    واپس;
	انحراف += (حجم(ElfW(Nhdr)) + note->n_namesz + note->n_descsz +
		  align - 1) & -align;
    }
    ptr = section_ptr_جوڑو(s, حجم(ElfW(Nhdr)) + 8 + 4);
    note = (ElfW(Nhdr) *) ptr;
    note->n_namesz = 8;
    note->n_descsz = 4;
    note->n_type = type;
    strcpy (ptr + حجم(ElfW(Nhdr)), قدر);
    حافظہ_نقل (ptr + حجم(ElfW(Nhdr)) + 8, &ڈیٹا, 4);
}

ساکن Section *create_bsd_note_section(TCCState *s1,
					ثابت حرف *name,
					ثابت حرف *قدر)
{
    Section *s;
    غیرعلامتی صحیح major = 0, minor = 0, patch = 0;

#اگر_تعریف_شدہ CONFIG_OS_RELEASE
    لڑی_سے_پڑھو(CONFIG_OS_RELEASE, "%u.%u.%u", &major, &minor, &patch);
#اگر_ختم
#اگر TARGETOS_FreeBSD
    اگر (major < 14)
	واپس تہی;
#اگر_ختم
    s = ڈھونڈو_section (s1, name);
    s->sh_type = SHT_NOTE;
#اگر TARGETOS_OpenBSD
    fill_bsd_note(s, ELF_NOTE_OS_GNU, قدر, 0);
#وگرنہ_اگر TARGETOS_NetBSD
    fill_bsd_note(s, 1 /* NT_NETBSD_IDENT_TAG */, قدر,
		  major * 100000000u + (minor % 100u) * 1000000u +
		  (patch % 10000u) * 100u);
#وگرنہ_اگر TARGETOS_FreeBSD
    fill_bsd_note(s, 1 /* NT_FREEBSD_ABI_TAG */, قدر,
		  major * 100000u + (minor % 100u) * 1000u);
    fill_bsd_note(s, 4 /* NT_FREEBSD_FEATURE_CTL */, قدر, 0);
    fill_bsd_note(s, 2 /* NT_FREEBSD_NOINIT_TAG */, قدر, 0);
#اگر_ختم
    واپس s;
}
#اگر_ختم

ساکن خالی alloc_sec_نام(TCCState *s1, صحیح is_obj);

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
ساکن صحیح elf_output_file(TCCState *s1, ثابت حرف *filename)
{
    صحیح i, ret, file_type, *sec_ترتیب;
    ساخت dyn_inf dyninf = {0};
    Section *interp, *dynstr, *dynamic;
    صحیح textrel, got_sym, dt_flags_1;

    file_type = s1->output_type;
    ret = -1;
    interp = dynstr = dynamic = تہی;
    sec_ترتیب = تہی;

#اگر_تعریف_شدہ TCC_ہدف_ARM
    create_arm_attribute_section (s1);
#اگر_ختم

#اگر_تعریف_شدہ TCC_ہدف_RISCV64
    create_riscv_attribute_section(s1);
#اگر_ختم

#اگر TARGETOS_OpenBSD
    dyninf.note = create_bsd_note_section (s1, ".note.openbsd.ident", "OpenBSD");
#اگر_ختم

#اگر TARGETOS_NetBSD
    dyninf.note = create_bsd_note_section (s1, ".note.netbsd.ident", "NetBSD");
#اگر_ختم

#اگر TARGETOS_FreeBSD
    dyninf.note = create_bsd_note_section (s1, ".note.tag", "FreeBSD");
#اگر_ختم

        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_جوڑو_runtime(s1);
	resolve_common_syms(s1);

        اگر (!s1->static_link) {
            اگر (file_type & TCC_OUTPUT_EXE) {
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
            اگر (file_type & TCC_OUTPUT_EXE) {
                bind_exe_dynsyms(s1, file_type & TCC_OUTPUT_DYN);
                اگر (s1->nb_errors)
                    جاؤ the_انتہا;
            }
            build_got_entries(s1, got_sym);
            اگر (file_type & TCC_OUTPUT_EXE) {
                bind_libs_dynsyms(s1);
            } ورنہ {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
#اگر TCC_EH_چوکھٹا
	    /* fill with initial data */
	    tcc_eh_چوکھٹا_hdr(s1, 0);
#اگر_ختم
	    dyninf.gnu_hash = create_gnu_hash(s1);
        } ورنہ {
            build_got_entries(s1, 0);
        }
	نسخہ_جوڑو (s1);

    textrel = سیٹ_sec_sizes(s1);

    اگر (!s1->static_link) {
        /* add a list of needed dlls */
        برائے(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            اگر (dllref->level == 0)
                put_dt(dynamic, DT_NEEDED, put_elf_str(dynstr, dllref->name));
        }

        اگر (s1->rpath)
            put_dt(dynamic, s1->enable_new_dtags ? DT_RUNPATH : DT_RPATH,
                   put_elf_str(dynstr, s1->rpath));

        dt_flags_1 = DF_1_NOW;
        اگر (file_type & TCC_OUTPUT_DYN) {
            اگر (s1->soname)
                put_dt(dynamic, DT_SONAME, put_elf_str(dynstr, s1->soname));
            /* XXX: currently, since we do not handle PIC code, we
               must relocate the readonly segments */
            اگر (textrel)
                put_dt(dynamic, DT_TEXTREL, 0);
            اگر (file_type & TCC_OUTPUT_EXE)
                dt_flags_1 = DF_1_NOW | DF_1_PIE;
	    اگر (s1->znodelete)
		dt_flags_1 |= DF_1_NODELETE;
        }
        put_dt(dynamic, DT_FLAGS, DF_BIND_NOW);
        put_dt(dynamic, DT_FLAGS_1, dt_flags_1);
        اگر (s1->symbolic)
            put_dt(dynamic, DT_SYMBOLIC, 0);

        dyninf.dynamic = dynamic;
        dyninf.dynstr = dynstr;
        /* remember offset and reserve space for 2nd call below */
        dyninf.ڈیٹا_انحراف = dynamic->ڈیٹا_انحراف;
        fill_dynamic(s1, &dyninf);
        dynamic->sh_سائز = dynamic->ڈیٹا_انحراف;
        dynstr->sh_سائز = dynstr->ڈیٹا_انحراف;
    }

    /* create and fill .shstrtab section */
    alloc_sec_نام(s1, 0);
    /* this array is used to reorder sections in the output file */
    sec_ترتیب = tcc_malloc(حجم(صحیح) * 2 * s1->nb_sections);
    /* compute section to program header mapping */
    layout_sections(s1, sec_ترتیب, &dyninf);

        اگر (dynamic) {
            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->ڈیٹا, dynamic->sh_addr);
            اگر (file_type == TCC_OUTPUT_EXE
                || (RELOCATE_DLLPLT && (file_type & TCC_OUTPUT_DYN)))
                relocate_plt(s1);
            /* relocate symbols in .dynsym now that final addresses are known */
            relocate_syms(s1, s1->dynsym, 2);
        }

        /* if building executable or DLL, then relocate each section
           except the GOT which is already relocated */
        relocate_syms(s1, s1->symtab, 0);
        اگر (s1->nb_errors != 0)
            جاؤ the_انتہا;
        relocate_sections(s1);
        اگر (dynamic) {
	    update_reloc_sections (s1, &dyninf);
            dynamic->ڈیٹا_انحراف = dyninf.ڈیٹا_انحراف;
            fill_dynamic(s1, &dyninf);
	}
        /* Perform relocation to GOT or PLT entries */
        اگر (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        ورنہ اگر (s1->got)
            fill_local_got_entries(s1);

    اگر (dyninf.gnu_hash)
        update_gnu_hash(s1, dyninf.gnu_hash);

    reorder_sections(s1, sec_ترتیب);
#اگر TCC_EH_چوکھٹا
    /* fill with final data */
    tcc_eh_چوکھٹا_hdr(s1, 1);
#اگر_ختم
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, dyninf.phnum, dyninf.phdr);
 the_انتہا:
    tcc_free(sec_ترتیب);
    tcc_free(dyninf.phdr);
    واپس ret;
}
#اگر_ختم /* ndef ELF_OBJ_ONLY */

/* Allocate strings for section names */
ساکن خالی alloc_sec_نام(TCCState *s1, صحیح is_obj)
{
    صحیح i;
    Section *s, *strsec;

    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");
    برائے(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        اگر (is_obj)
            s->sh_سائز = s->ڈیٹا_انحراف;
	اگر (s->sh_سائز || s == strsec || (s->sh_flags & SHF_ALLOC) || is_obj)
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_سائز = strsec->ڈیٹا_انحراف;
}

/* Output an elf .o file */
ساکن صحیح elf_output_obj(TCCState *s1, ثابت حرف *filename)
{
    Section *s;
    صحیح i, ret, file_انحراف;
    /* Allocate strings for section names */
    alloc_sec_نام(s1, 1);
    file_انحراف = (حجم (ElfW(Ehdr)) + 3) & -4;
    file_انحراف += s1->nb_sections * حجم(ElfW(Shdr));
    برائے(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        file_انحراف = (file_انحراف + 15) & -16;
        s->sh_انحراف = file_انحراف;
        اگر (s->sh_type != SHT_NOBITS)
            file_انحراف += s->sh_سائز;
    }
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, 0, تہی);
    واپس ret;
}

LIBTCCAPI صحیح tcc_output_file(TCCState *s, ثابت حرف *filename)
{
    s->nb_errors = 0;
    اگر (s->test_coverage)
        tcc_tcov_جوڑو_file(s, filename);
    اگر (s->output_type == TCC_OUTPUT_OBJ)
        واپس elf_output_obj(s, filename);
#اگر_تعریف_شدہ TCC_ہدف_PE
    واپس  pe_output_file(s, filename);
#وگرنہ_اگر defined TCC_ہدف_MACHO
    واپس macho_output_file(s, filename);
#ورنہ
    واپس elf_output_file(s, filename);
#اگر_ختم
}

ST_FUNC ssize_t بھرا_read(صحیح fd, خالی *buf, سائز_t گنتی_2) {
    حرف *cbuf = buf;
    سائز_t rnum = 0;
    جب (1) {
        ssize_t عدد = اقرأ(fd, cbuf, گنتی_2-rnum);
        اگر (عدد < 0) واپس عدد;
        اگر (عدد == 0) واپس rnum;
        rnum += عدد;
        cbuf += عدد;
    }
}

ST_FUNC خالی *بھرو_ڈیٹا(صحیح fd, غیرعلامتی طویل file_انحراف, غیرعلامتی طویل سائز)
{
    خالی *ڈیٹا;

    ڈیٹا = tcc_malloc(سائز);
    lseek(fd, file_انحراف, SEEK_SET);
    بھرا_read(fd, ڈیٹا, سائز);
    واپس ڈیٹا;
}

قسمتعریف ساخت Section_ملاؤ_Info {
    Section *s;            /* corresponding existing section */
    غیرعلامتی طویل انحراف;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} Section_ملاؤ_Info;

ST_FUNC صحیح tcc_object_type(صحیح fd, ElfW(Ehdr) *h)
{
    صحیح سائز = بھرا_read(fd, h, حجم *h);
    اگر (سائز == حجم *h && 0 == memcmp(h, ELFMAG, 4)) {
        اگر (h->e_type == ET_REL)
            واپس AFF_BINTYPE_REL;
        اگر (h->e_type == ET_DYN)
            واپس AFF_BINTYPE_DYN;
    } ورنہ اگر (سائز >= 8) {
        اگر (0 == memcmp(h, ARMAG, 8))
            واپس AFF_BINTYPE_AR;
#اگر_تعریف_شدہ TCC_ہدف_COFF
        اگر (((ساخت filehdr*)h)->f_magic == COFF_C67_MAGIC)
            واپس AFF_BINTYPE_C67;
#اگر_ختم
    }
    واپس 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC صحیح tcc_بھرو_object_file(TCCState *s1,
                                صحیح fd, غیرعلامتی طویل file_انحراف)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    غیرعلامتی طویل سائز, انحراف, offseti;
    صحیح i, j, nb_syms, sym_اشاریہ, ret, seencompressed;
    حرف *strsec, *strtab;
    صحیح stab_اشاریہ, stabstr_اشاریہ;
    صحیح *old_مقصد_new_syms;
    حرف *sh_name, *name;
    Section_ملاؤ_Info *sm_جدول, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    lseek(fd, file_انحراف, SEEK_SET);
    اگر (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        جاؤ invalid;
    /* test CPU specific stuff */
    اگر (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_ہدف) {
invalid:
        واپس tcc_error_noabort("invalid object file");
    }
    /* read sections */
    shdr = بھرو_ڈیٹا(fd, file_انحراف + ehdr.e_shoff,
                     حجم(ElfW(Shdr)) * ehdr.e_shnum);
    sm_جدول = tcc_mallocz(حجم(Section_ملاؤ_Info) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = بھرو_ڈیٹا(fd, file_انحراف + sh->sh_انحراف, sh->sh_سائز);

    /* load symtab and strtab */
    old_مقصد_new_syms = تہی;
    symtab = تہی;
    strtab = تہی;
    nb_syms = 0;
    seencompressed = 0;
    stab_اشاریہ = stabstr_اشاریہ = 0;
    ret = -1;

    برائے(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        اگر (sh->sh_type == SHT_SYMTAB) {
            اگر (symtab) {
                tcc_error_noabort("object must contain only one symtab");
                جاؤ the_انتہا;
            }
            nb_syms = sh->sh_سائز / حجم(ElfW(Sym));
            symtab = بھرو_ڈیٹا(fd, file_انحراف + sh->sh_انحراف, sh->sh_سائز);
            sm_جدول[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = بھرو_ڈیٹا(fd, file_انحراف + sh->sh_انحراف, sh->sh_سائز);
        }
	اگر (sh->sh_flags & SHF_COMPRESSED)
	    seencompressed = 1;
    }

    /* now examine each section and try to merge its content with the
       ones in memory */
    برائے(i = 1; i < ehdr.e_shnum; i++) {
        /* no need to examine section name strtab */
        اگر (i == ehdr.e_shstrndx)
            جاری;
        sh = &shdr[i];
	اگر (sh->sh_type == SHT_RELX)
	  sh = &shdr[sh->sh_info];
        /* ignore sections types we do not handle (plus relocs to those) */
        sh_name = strsec + sh->sh_name;
        اگر (0 == لڑی_موازنہ(sh_name, ".debug_", 7)
         || 0 == لڑی_موازنہ(sh_name, ".stab", 5)) {
	    اگر (!s1->do_debug || seencompressed)
	        جاری;
#اگر !(TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD)
        } ورنہ اگر (0 == لڑی_موازنہ(sh_name, ".eh_frame", 9)) {
            اگر (تہی == eh_چوکھٹا_section)
                جاری;
#اگر_ختم
        } ورنہ
        اگر (sh->sh_type != SHT_PROGBITS &&
            sh->sh_type != SHT_NOTE &&
            sh->sh_type != SHT_NOBITS &&
            sh->sh_type != SHT_PREINIT_ARRAY &&
            sh->sh_type != SHT_INIT_ARRAY &&
            sh->sh_type != SHT_FINI_ARRAY
#اگر_تعریف_شدہ TCC_ARM_EABI
            /* Added in commit f99d3de221db23e322c6c18c8249282e27726c25
               but suppressed in 3cfaaaf1eb97d858e583412616f68f75fdad5da5
               So don't load it in order to avoid dangling references from
               (STT_SECTION) symbols. */
            // && sh->sh_type != SHT_ARM_EXIDX
#اگر_ختم

#اگر TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD
            && sh->sh_type != SHT_X86_64_UNWIND
#اگر_ختم
            )
            جاری;

	sh = &shdr[i];
        sh_name = strsec + sh->sh_name;
        اگر (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        /* find corresponding section, if any */
        برائے(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            اگر (strcmp(s->name, sh_name))
                جاری;
            اگر (sh->sh_type != s->sh_type
                && strcmp (s->name, ".eh_frame")
                /* some crt1.o seem to have two ".note.GNU-stack" (SHT_NOTE & SHT_PROGBITS) */
                && strcmp (s->name, ".note.GNU-stack")
                ) {
                tcc_error_noabort("section type conflict: %s %02x <> %02x", s->name, sh->sh_type, s->sh_type);
                جاؤ the_انتہا;
            }
            اگر (!لڑی_موازنہ(sh_name, ".gnu.linkonce", 13)) {
                /* if a 'linkonce' section is already present, we
                   do not add it again. It is a little tricky as
                   symbols can still be defined in
                   it. */
                sm_جدول[i].link_once = 1;
                جاؤ اگلا;
            }
            اگر (stab_section) {
                اگر (s == stab_section)
                    stab_اشاریہ = i;
                اگر (s == stab_section->link)
                    stabstr_اشاریہ = i;
            }
            جاؤ ملا;
        }
        /* not found: create new section */
        s = new_section(s1, sh_name, sh->sh_type, sh->sh_flags & ~SHF_گروہ);
        /* take as much info as possible from the section. sh_link and
           sh_info will be updated later */
        s->sh_addralign = sh->sh_addralign;
        s->sh_entsize = sh->sh_entsize;
        sm_جدول[i].new_section = 1;
    ملا:
        سائز = sh->sh_سائز;
        /* align start of section */
        انحراف = section_جوڑو(s, سائز, sh->sh_addralign);
        اگر (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        sm_جدول[i].انحراف = انحراف;
        sm_جدول[i].s = s;
        /* concatenate sections */
        اگر (sh->sh_type != SHT_NOBITS && سائز) {
            غیرعلامتی حرف *ptr;
            lseek(fd, file_انحراف + sh->sh_انحراف, SEEK_SET);
            ptr = s->ڈیٹا + انحراف;
            بھرا_read(fd, ptr, سائز);
        }
#اگر defined TCC_ہدف_ARM || defined TCC_ہدف_ARM64 || defined TCC_ہدف_RISCV64
        /* align code sections to instruction lenght */
        /* This is needed if we compile a c file after this */
        اگر (s->sh_flags & SHF_EXECINSTR)
            section_جوڑو(s, 0, 4);
#اگر_ختم
    اگلا: ;
    }

    /* gr relocate stab strings */
    اگر (stab_اشاریہ && stabstr_اشاریہ) {
        Stab_Sym *a, *b;
        غیرعلامتی o;
        s = sm_جدول[stab_اشاریہ].s;
        a = (Stab_Sym *)(s->ڈیٹا + sm_جدول[stab_اشاریہ].انحراف);
        b = (Stab_Sym *)(s->ڈیٹا + s->ڈیٹا_انحراف);
        o = sm_جدول[stabstr_اشاریہ].انحراف;
        جب (a < b) {
            اگر (a->n_strx)
                a->n_strx += o;
            a++;
        }
    }

    /* second short pass to update sh_link and sh_info fields of new
       sections */
    برائے(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_جدول[i].s;
        اگر (!s || !sm_جدول[i].new_section)
            جاری;
        sh = &shdr[i];
        اگر (sh->sh_link > 0)
            s->link = sm_جدول[sh->sh_link].s;
        اگر (sh->sh_type == SHT_RELX) {
            s->sh_info = sm_جدول[sh->sh_info].s->sh_عدد;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }

    اگر (!symtab)
        جاؤ مکمل;

    /* resolve symbols */
    old_مقصد_new_syms = tcc_mallocz(nb_syms * حجم(صحیح));

    sym = symtab + 1;
    برائے(i = 1; i < nb_syms; i++, sym++) {
        اگر (sym->st_shndx != SHN_UNDEF &&
            sym->st_shndx < SHN_LORESERVE) {
            sm = &sm_جدول[sym->st_shndx];
            اگر (sm->link_once) {
                /* if a symbol is in a link once section, we use the
                   already defined symbol. It is very important to get
                   correct relocations */
                اگر (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
                    name = strtab + sym->st_name;
                    sym_اشاریہ = ڈھونڈو_elf_sym(symtab_section, name);
                    اگر (sym_اشاریہ)
                        old_مقصد_new_syms[i] = sym_اشاریہ;
                }
                جاری;
            }
            /* if no corresponding section added, no need to add symbol */
            اگر (!sm->s)
                جاری;
            /* convert section number */
            sym->st_shndx = sm->s->sh_عدد;
            /* offset value */
            sym->st_قدر += sm->انحراف;
        }
        /* add symbol */
        name = strtab + sym->st_name;
        sym_اشاریہ = سیٹ_elf_sym(symtab_section, sym->st_قدر, sym->st_سائز,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_مقصد_new_syms[i] = sym_اشاریہ;
    }

    /* third pass to patch relocation entries */
    برائے(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_جدول[i].s;
        اگر (!s)
            جاری;
        sh = &shdr[i];
        انحراف = sm_جدول[i].انحراف;
        سائز = sh->sh_سائز;
        انتخاب(s->sh_type) {
        حالت SHT_RELX:
            /* take relocation offset information */
            offseti = sm_جدول[sh->sh_info].انحراف;
	    برائے (rel = (ElfW_Rel *) s->ڈیٹا + (انحراف / حجم(*rel));
		 rel < (ElfW_Rel *) s->ڈیٹا + ((انحراف + سائز) / حجم(*rel));
		 rel++) {
                صحیح type;
                غیرعلامتی sym_اشاریہ;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_اشاریہ = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                اگر (sym_اشاریہ >= nb_syms)
                    جاؤ invalid_reloc;
                sym_اشاریہ = old_مقصد_new_syms[sym_اشاریہ];
                /* ignore link_once in rel section. */
                اگر (!sym_اشاریہ && !sm_جدول[sh->sh_info].link_once
#اگر_تعریف_شدہ TCC_ہدف_ARM
                    && type != R_ARM_V4BX
#وگرنہ_اگر defined TCC_ہدف_RISCV64
                    && type != R_RISCV_ALIGN
                    && type != R_RISCV_RELAX
#اگر_ختم
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, (صحیح)rel->r_انحراف);
                    جاؤ the_انتہا;
                }
                rel->r_info = ELFW(R_INFO)(sym_اشاریہ, type);
                /* offset the relocation offset */
                rel->r_انحراف += offseti;
#اگر_تعریف_شدہ TCC_ہدف_ARM
                /* Jumps and branches from a Thumb code to a PLT entry need
                   special handling since PLT entries are ARM code.
                   Unconditional bl instructions referencing PLT entries are
                   handled by converting these instructions into blx
                   instructions. Other case of instructions referencing a PLT
                   entry require to add a Thumb stub before the PLT entry to
                   switch to ARM mode. We set bit plt_thumb_stub of the
                   attribute of a symbol to indicate such a case. */
                اگر (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_اشاریہ, 1)->plt_thumb_stub = 1;
#اگر_ختم
            }
            توڑو;
        طےشدہ:
            توڑو;
        }
    }
 مکمل:
    ret = !s1->nb_errors - 1; /* errors possibly from set_elf_sym() */
 the_انتہا:
    tcc_free(symtab);
    tcc_free(strtab);
    tcc_free(old_مقصد_new_syms);
    tcc_free(sm_جدول);
    tcc_free(strsec);
    tcc_free(shdr);
    واپس ret;
}

قسمتعریف ساخت Archive_سرخی {
    حرف ar_name[16];           /* name of this member */
    حرف ar_date[12];           /* file mtime */
    حرف ar_uid[6];             /* owner uid; printed as decimal */
    حرف ar_gid[6];             /* owner gid; printed as decimal */
    حرف ar_منوال[8];            /* file mode, printed as octal   */
    حرف ar_سائز[10];           /* file size, printed as decimal */
    حرف ar_fmag[2];            /* should contain ARFMAG */
} Archive_سرخی;

#تعریف_کرو ARFMAG "`\n"

ساکن غیرعلامتی طویل طویل get_be(ثابت uint8_t *b, صحیح n)
{
    غیرعلامتی طویل طویل ret = 0;
    جب (n)
        ret = (ret << 8) | *b++, --n;
    واپس ret;
}

ساکن صحیح read_ar_سرخی(صحیح fd, صحیح انحراف, Archive_سرخی *hdr)
{
    حرف *p, *e;
    صحیح len;
    lseek(fd, انحراف, SEEK_SET);
    len = بھرا_read(fd, hdr, حجم(Archive_سرخی));
    اگر (len != حجم(Archive_سرخی))
        واپس len ? -1 : 0;
    اگر (memcmp(hdr->ar_fmag, ARFMAG, حجم hdr->ar_fmag))
        واپس -1;
    p = hdr->ar_name;
    برائے (e = p + حجم hdr->ar_name; e > p && e[-1] == ' ';)
        --e;
    *e = '\0';
    hdr->ar_سائز[حجم hdr->ar_سائز-1] = 0;
    واپس len;
}

/* load only the objects which resolve undefined symbols */
ساکن صحیح tcc_بھرو_alacarte(TCCState *s1, صحیح fd, صحیح سائز, صحیح entrysize)
{
    صحیح i, bound, nsyms, sym_اشاریہ, len, ret = -1;
    غیرعلامتی طویل طویل off;
    uint8_t *ڈیٹا;
    ثابت حرف *ar_نام, *p;
    ثابت uint8_t *ar_اشاریہ;
    ElfW(Sym) *sym;
    Archive_سرخی hdr;

    ڈیٹا = tcc_malloc(سائز);
    اگر (بھرا_read(fd, ڈیٹا, سائز) != سائز)
        جاؤ invalid;
    nsyms = get_be(ڈیٹا, entrysize);
    ar_اشاریہ = ڈیٹا + entrysize;
    ar_نام = (حرف *) ar_اشاریہ + nsyms * entrysize;

    کرو {
        bound = 0;
        برائے (p = ar_نام, i = 0; i < nsyms; i++, p += لڑی_لمبائی(p)+1) {
            Section *s = symtab_section;
            sym_اشاریہ = ڈھونڈو_elf_sym(s, p);
            اگر (!sym_اشاریہ)
                جاری;
            sym = &((ElfW(Sym) *)s->ڈیٹا)[sym_اشاریہ];
            اگر(sym->st_shndx != SHN_UNDEF)
                جاری;
            off = get_be(ar_اشاریہ + i * entrysize, entrysize);
            len = read_ar_سرخی(fd, off, &hdr);
            اگر (len <= 0 || memcmp(hdr.ar_fmag, ARFMAG, 2)) {
        invalid:
                tcc_error_noabort("invalid archive");
                جاؤ the_انتہا;
            }
            off += len;
            اگر (s1->verbose == 2)
                لکھو("   -> %s\n", hdr.ar_name);
            اگر (tcc_بھرو_object_file(s1, fd, off) < 0)
                جاؤ the_انتہا;
            ++bound;
        }
    } جب(bound);
    ret = 0;
 the_انتہا:
    tcc_free(ڈیٹا);
    واپس ret;
}

/* load a '.a' file */
ST_FUNC صحیح tcc_بھرو_archive(TCCState *s1, صحیح fd, صحیح alacarte)
{
    Archive_سرخی hdr;
    /* char magic[8]; */
    صحیح سائز, len;
    غیرعلامتی طویل file_انحراف;
    ElfW(Ehdr) ehdr;

    /* skip magic which was already checked */
    /* full_read(fd, magic, sizeof(magic)); */
    file_انحراف = حجم ARMAG - 1;

    برائے(;;) {
        len = read_ar_سرخی(fd, file_انحراف, &hdr);
        اگر (len == 0)
            واپس 0;
        اگر (len < 0)
            واپس tcc_error_noabort("invalid archive");
        file_انحراف += len;
        سائز = strtol(hdr.ar_سائز, تہی, 0);
        اگر (alacarte) {
            /* coff symbol table : we handle it */
            اگر (!strcmp(hdr.ar_name, "/"))
                واپس tcc_بھرو_alacarte(s1, fd, سائز, 4);
            اگر (!strcmp(hdr.ar_name, "/SYM64/"))
                واپس tcc_بھرو_alacarte(s1, fd, سائز, 8);
        } ورنہ اگر (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
            اگر (s1->verbose == 2)
                لکھو("   -> %s\n", hdr.ar_name);
            اگر (tcc_بھرو_object_file(s1, fd, file_انحراف) < 0)
                واپس -1;
        }
        /* align to even */
        file_انحراف = (file_انحراف + سائز + 1) & ~1;
    }
}

#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
/* Set LV[I] to the global index of sym-version (LIB,VERSION).  Maybe resizes
   LV, maybe create a new entry for (LIB,VERSION).  */
ساکن خالی سیٹ_ver_مقصد_ver(TCCState *s1, صحیح *n, صحیح **lv, صحیح i, حرف *lib, حرف *نسخہ)
{
    جب (i >= *n) {
        *lv = tcc_realloc(*lv, (*n + 1) * حجم(**lv));
        (*lv)[(*n)++] = -1;
    }
    اگر ((*lv)[i] == -1) {
        صحیح v, پچھلا_same_lib = -1;
        برائے (v = 0; v < nb_sym_versions; v++) {
            اگر (strcmp(sym_versions[v].lib, lib))
              جاری;
            پچھلا_same_lib = v;
            اگر (!strcmp(sym_versions[v].نسخہ, نسخہ))
              توڑو;
        }
        اگر (v == nb_sym_versions) {
            sym_versions = tcc_realloc (sym_versions,
                                        (v + 1) * حجم(*sym_versions));
            sym_versions[v].lib = tcc_strdup(lib);
            sym_versions[v].نسخہ = tcc_strdup(نسخہ);
            sym_versions[v].برآمد_اشاریہ = 0;
            sym_versions[v].پچھلا_same_lib = پچھلا_same_lib;
            nb_sym_versions++;
        }
        (*lv)[i] = v;
    }
}

/* Associates symbol SYM_INDEX (in dynsymtab) with sym-version index
   VERNDX.  */
ساکن خالی
سیٹ_sym_نسخہ(TCCState *s1, صحیح sym_اشاریہ, صحیح verndx)
{
    اگر (sym_اشاریہ >= nb_sym_مقصد_نسخہ) {
        صحیح newelems = sym_اشاریہ ? sym_اشاریہ * 2 : 1;
        sym_مقصد_نسخہ = tcc_realloc(sym_مقصد_نسخہ,
                                     newelems * حجم(*sym_مقصد_نسخہ));
        memset(sym_مقصد_نسخہ + nb_sym_مقصد_نسخہ, -1,
               (newelems - nb_sym_مقصد_نسخہ) * حجم(*sym_مقصد_نسخہ));
        nb_sym_مقصد_نسخہ = newelems;
    }
    اگر (sym_مقصد_نسخہ[sym_اشاریہ] < 0)
      sym_مقصد_نسخہ[sym_اشاریہ] = verndx;
}

ساخت versym_info {
    صحیح nb_versyms;
    ElfW(Verdef) *verdef;
    ElfW(Verneed) *verneed;
    ElfW(Half) *versym;
    صحیح nb_local_ver, *local_ver;
};


ساکن خالی store_نسخہ(TCCState *s1, ساخت versym_info *v, حرف *dynstr)
{
    حرف *lib, *نسخہ;
    uint32_t اگلا;
    صحیح i;

#تعریف_کرو	DEBUG_نسخہ 0

    اگر (v->versym && v->verdef) {
      ElfW(Verdef) *vdef = v->verdef;
      lib = تہی;
      کرو {
        ElfW(Verdaux) *verdaux =
	  (ElfW(Verdaux) *) (((حرف *) vdef) + vdef->vd_aux);

#اگر DEBUG_نسخہ
	لکھو ("verdef: version:%u flags:%u index:%u, hash:%u\n",
	        vdef->vd_نسخہ, vdef->vd_flags, vdef->vd_ndx,
		vdef->vd_hash);
#اگر_ختم
	اگر (vdef->vd_cnt) {
          نسخہ = dynstr + verdaux->vda_name;

	  اگر (lib == تہی)
	    lib = نسخہ;
	  ورنہ
            سیٹ_ver_مقصد_ver(s1, &v->nb_local_ver, &v->local_ver, vdef->vd_ndx,
                           lib, نسخہ);
#اگر DEBUG_نسخہ
	  لکھو ("  verdaux(%u): %s\n", vdef->vd_ndx, نسخہ);
#اگر_ختم
	}
        اگلا = vdef->vd_اگلا;
        vdef = (ElfW(Verdef) *) (((حرف *) vdef) + اگلا);
      } جب (اگلا);
    }
    اگر (v->versym && v->verneed) {
      ElfW(Verneed) *vneed = v->verneed;
      کرو {
        ElfW(Vernaux) *vernaux =
	  (ElfW(Vernaux) *) (((حرف *) vneed) + vneed->vn_aux);

        lib = dynstr + vneed->vn_file;
#اگر DEBUG_نسخہ
	لکھو ("verneed: %u %s\n", vneed->vn_نسخہ, lib);
#اگر_ختم
	برائے (i = 0; i < vneed->vn_cnt; i++) {
	  اگر ((vernaux->vna_other & 0x8000) == 0) { /* hidden */
              نسخہ = dynstr + vernaux->vna_name;
              سیٹ_ver_مقصد_ver(s1, &v->nb_local_ver, &v->local_ver, vernaux->vna_other,
                             lib, نسخہ);
#اگر DEBUG_نسخہ
	    لکھو ("  vernaux(%u): %u %u %s\n",
		    vernaux->vna_other, vernaux->vna_hash,
		    vernaux->vna_flags, نسخہ);
#اگر_ختم
	  }
	  vernaux = (ElfW(Vernaux) *) (((حرف *) vernaux) + vernaux->vna_اگلا);
	}
        اگلا = vneed->vn_اگلا;
        vneed = (ElfW(Verneed) *) (((حرف *) vneed) + اگلا);
      } جب (اگلا);
    }

#اگر DEBUG_نسخہ
    برائے (i = 0; i < v->nb_local_ver; i++) {
      اگر (v->local_ver[i] > 0) {
        لکھو ("%d: lib: %s, version %s\n",
		i, sym_versions[v->local_ver[i]].lib,
                sym_versions[v->local_ver[i]].نسخہ);
      }
    }
#اگر_ختم
}

/* load a library / DLL
   'level = 0' means that the DLL is referenced by the user
   (so it should be added as DT_NEEDED in the generated ELF file) */
ST_FUNC صحیح tcc_بھرو_dll(TCCState *s1, صحیح fd, ثابت حرف *filename, صحیح level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    صحیح i, nb_syms, nb_dts, sym_bind, ret = -1;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;

    حرف *dynstr;
    صحیح sym_اشاریہ;
    ثابت حرف *name, *soname;
    ساخت versym_info v;

    بھرا_read(fd, &ehdr, حجم(ehdr));

    /* test CPU specific stuff */
    اگر (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_ہدف) {
        واپس tcc_error_noabort("bad architecture");
    }

    /* read sections */
    shdr = بھرو_ڈیٹا(fd, ehdr.e_shoff, حجم(ElfW(Shdr)) * ehdr.e_shnum);

    /* load dynamic section and dynamic symbols */
    nb_syms = 0;
    nb_dts = 0;
    dynamic = تہی;
    dynsym = تہی; /* avoid warning */
    dynstr = تہی; /* avoid warning */
    memset(&v, 0, حجم v);

    برائے(i = 0, sh = shdr; i < ehdr.e_shnum; i++, sh++) {
        انتخاب(sh->sh_type) {
        حالت SHT_DYNAMIC:
            nb_dts = sh->sh_سائز / حجم(ElfW(Dyn));
            dynamic = بھرو_ڈیٹا(fd, sh->sh_انحراف, sh->sh_سائز);
            توڑو;
        حالت SHT_DYNSYM:
            nb_syms = sh->sh_سائز / حجم(ElfW(Sym));
            dynsym = بھرو_ڈیٹا(fd, sh->sh_انحراف, sh->sh_سائز);
            sh1 = &shdr[sh->sh_link];
            dynstr = بھرو_ڈیٹا(fd, sh1->sh_انحراف, sh1->sh_سائز);
            توڑو;
        حالت SHT_GNU_verdef:
	    v.verdef = بھرو_ڈیٹا(fd, sh->sh_انحراف, sh->sh_سائز);
	    توڑو;
        حالت SHT_GNU_verneed:
	    v.verneed = بھرو_ڈیٹا(fd, sh->sh_انحراف, sh->sh_سائز);
	    توڑو;
        حالت SHT_GNU_versym:
            v.nb_versyms = sh->sh_سائز / حجم(ElfW(Half));
	    v.versym = بھرو_ڈیٹا(fd, sh->sh_انحراف, sh->sh_سائز);
	    توڑو;
        طےشدہ:
            توڑو;
        }
    }

    اگر (!dynamic)
        جاؤ the_انتہا;

    /* compute the real library name */
    soname = tcc_basename(filename);
    برائے(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        اگر (dt->d_لیبل == DT_SONAME)
            soname = dynstr + dt->d_un.d_val;

    /* if the dll is already loaded, do not load it */
    اگر (tcc_جوڑو_dllref(s1, soname, level)->ملا)
        جاؤ ret_success;

    اگر (v.nb_versyms != nb_syms)
        tcc_free (v.versym), v.versym = تہی;
    ورنہ
        store_نسخہ(s1, &v, dynstr);

    /* add dynamic symbols in dynsym_section */
    برائے(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        اگر (sym_bind == STB_LOCAL)
            جاری;
        name = dynstr + sym->st_name;
        sym_اشاریہ = سیٹ_elf_sym(s1->dynsymtab_section, sym->st_قدر, sym->st_سائز,
                                sym->st_info, sym->st_other, sym->st_shndx, name);
        اگر (v.versym) {
            ElfW(Half) vsym = v.versym[i];
            اگر ((vsym & 0x8000) == 0 && vsym > 0 && vsym < v.nb_local_ver)
                سیٹ_sym_نسخہ(s1, sym_اشاریہ, v.local_ver[vsym]);
        }
    }

    /* do not load all referenced libraries
       (recursive loading can break linking of libraries) */
    /* following DT_NEEDED is needed for the dynamic loader (libdl.so),
       but it is no longer needed, when linking a library or a program.
       When tcc output mode is OUTPUT_MEM,
       tcc calls dlopen, which handles DT_NEEDED for us */

#اگر 0
    برائے(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        اگر (dt->d_لیبل == DT_RPATH)
            tcc_جوڑو_library_راستہ(s1, dynstr + dt->d_un.d_val);

    /* load all referenced DLLs */
    برائے(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        انتخاب(dt->d_لیبل) {
        حالت DT_NEEDED:
            name = dynstr + dt->d_un.d_val;
            اگر (tcc_جوڑو_dllref(s1, name, -1))
                جاری;
            اگر (tcc_جوڑو_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                ret = tcc_error_noabort("referenced dll '%s' not found", name);
                جاؤ the_انتہا;
            }
        }
    }
#اگر_ختم

 ret_success:
    ret = 0;
 the_انتہا:
    tcc_free(dynstr);
    tcc_free(dynsym);
    tcc_free(dynamic);
    tcc_free(shdr);
    tcc_free(v.local_ver);
    tcc_free(v.verdef);
    tcc_free(v.verneed);
    tcc_free(v.versym);
    واپس ret;
}

#تعریف_کرو LD_TOK_NAME 256
#تعریف_کرو LD_TOK_EOF  (-1)
ساکن صحیح ld_inp(TCCState *s1)
{
    صحیح c = *s1->ld_p;
    اگر (c == 0)
        واپس CH_EOF;
    ++s1->ld_p;
    واپس c;
}
#تعریف_کرو ld_unget(s1, ch) اگر (ch != CH_EOF) --s1->ld_p

/* return next ld script token */
ساکن صحیح ld_اگلا(TCCState *s1, حرف *name, صحیح name_سائز)
{
    صحیح c, d, ch;
    حرف *q;

 redo:
    ch = ld_inp(s1);
    q = name, *q++ = ch;
    انتخاب(ch) {
    حالت ' ':
    حالت '\t':
    حالت '\f':
    حالت '\v':
    حالت '\r':
    حالت '\n':
        جاؤ redo;
    حالت '/':
        ch = ld_inp(s1);
        اگر (ch == '*') { /* comment */
            برائے (d = 0;; d = ch) {
                ch = ld_inp(s1);
                اگر (ch == CH_EOF || (ch == '/' && d == '*'))
                    توڑو;
            }
            جاؤ redo;
        } ورنہ {
            جاؤ parse_name;
        }
        توڑو;
    حالت '\\':
    /* case 'a' ... 'z': */
    حالت 'a':
       حالت 'b':
       حالت 'c':
       حالت 'd':
       حالت 'e':
       حالت 'f':
       حالت 'g':
       حالت 'h':
       حالت 'i':
       حالت 'j':
       حالت 'k':
       حالت 'l':
       حالت 'm':
       حالت 'n':
       حالت 'o':
       حالت 'p':
       حالت 'q':
       حالت 'r':
       حالت 's':
       حالت 't':
       حالت 'u':
       حالت 'v':
       حالت 'w':
       حالت 'x':
       حالت 'y':
       حالت 'z':
    /* case 'A' ... 'z': */
    حالت 'A':
       حالت 'B':
       حالت 'C':
       حالت 'D':
       حالت 'E':
       حالت 'F':
       حالت 'G':
       حالت 'H':
       حالت 'I':
       حالت 'J':
       حالت 'K':
       حالت 'L':
       حالت 'M':
       حالت 'N':
       حالت 'O':
       حالت 'P':
       حالت 'Q':
       حالت 'R':
       حالت 'S':
       حالت 'T':
       حالت 'U':
       حالت 'V':
       حالت 'W':
       حالت 'X':
       حالت 'Y':
       حالت 'Z':
    حالت '-':
    حالت '_':
    حالت '.':
    حالت '$':
    حالت '~':
        برائے(;;) {
            ch = ld_inp(s1);
    parse_name:
            اگر (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') ||
                  strchr("/.-_+=$:\\,~", ch)))
                توڑو;
            اگر ((q - name) < name_سائز - 1) {
                *q++ = ch;
            }
        }
        ld_unget(s1, ch);
        c = LD_TOK_NAME;
        توڑو;
    حالت CH_EOF:
        c = LD_TOK_EOF;
        توڑو;
    طےشدہ:
        c = ch;
        توڑو;
    }
    *q = '\0';
    واپس c;
}

ساکن صحیح ld_جوڑو_file(TCCState *s1, ثابت حرف filename[])
{
    اگر (filename[0] == '-' && filename[1] == 'l')
        واپس tcc_جوڑو_library(s1, filename + 2);
    اگر (CONFIG_SYSROOT[0] != '\0' || !IS_ABSPATH(filename)) {
        /* lookup via library paths */
        صحیح ret = tcc_جوڑو_dll(s1, tcc_basename(filename), 0);
        اگر (ret != FILE_NOT_ملا)
            واپس ret;
    }
    واپس tcc_جوڑو_file_اندرونی(s1, filename, AFF_PRINT_ERROR);
}

/* did static libraries add new undefined symbols? */
ساکن صحیح new_undef_sym(TCCState *s1, صحیح sym_انحراف)
{
    جب (sym_انحراف < s1->symtab->ڈیٹا_انحراف) {
        ElfW(Sym) *esym = (خالی*)(s1->symtab->ڈیٹا + sym_انحراف);
        اگر (esym->st_shndx == SHN_UNDEF)
            واپس 1;
        sym_انحراف += حجم (ElfW(Sym));
    }
    واپس 0;
}

ساکن صحیح ld_جوڑو_file_list(TCCState *s1, ثابت حرف *cmd)
{
    حرف filename[1024];
    صحیح t, c, sym_انحراف, ret = 0;
    غیرعلامتی حرف *pos = s1->ld_p;

repeat:
    s1->ld_p = pos;
    sym_انحراف = s1->symtab->ڈیٹا_انحراف;
    c = cmd[0];

    t = ld_اگلا(s1, filename, حجم(filename));
    اگر (t != '(')
        واپس tcc_error_noabort("expected '(' after %s", cmd);
    t = ld_اگلا(s1, filename, حجم(filename));
    برائے(;;) {
        اگر (t == LD_TOK_EOF) {
            واپس tcc_error_noabort("unexpected end of file");
        } ورنہ اگر (t == ')') {
            توڑو;
        } ورنہ اگر (t != LD_TOK_NAME) {
            واپس tcc_error_noabort("unexpected token '%c'", t);
        } ورنہ اگر (!strcmp(filename, "AS_NEEDED")) {
            ret |= ld_جوڑو_file_list(s1, filename);
        } ورنہ اگر (c == 'I' || c == 'G' || c == 'A') {
            ret |= !!ld_جوڑو_file(s1, filename);
        }
        اگر (ret < 0)
            واپس ret;
        t = ld_اگلا(s1, filename, حجم(filename));
        اگر (t == ',')
            t = ld_اگلا(s1, filename, حجم(filename));
    }
    اگر (c == 'G' && ret == 0 && new_undef_sym(s1, sym_انحراف))
        جاؤ repeat;
    واپس ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC صحیح tcc_بھرو_ldscript(TCCState *s1, صحیح fd)
{
    حرف cmd[64];
    صحیح t, ret = 0, noscript = 1;
    غیرعلامتی حرف *متن_ptr, *saved_ptr;

    saved_ptr = s1->ld_p;
    s1->ld_p = متن_ptr = (خالی*)tcc_بھرو_متن(fd);
    برائے(;;) {
        t = ld_اگلا(s1, cmd, حجم(cmd));
        اگر (t == LD_TOK_EOF)
            توڑو;
        اگر (!strcmp(cmd, "INPUT") ||
            !strcmp(cmd, "GROUP")) {
            ret |= ld_جوڑو_file_list(s1, cmd);
        } ورنہ اگر (!strcmp(cmd, "OUTPUT_FORMAT") ||
                   !strcmp(cmd, "TARGET")) {
            /* ignore some commands */
            ret |= ld_جوڑو_file_list(s1, cmd);
        } ورنہ اگر (noscript) {
            ret = FILE_NOT_RECOGNIZED;
        } ورنہ {
            ret = tcc_error_noabort("unexpected '%s'", cmd);
        }
        اگر (ret < 0)
            توڑو;
        noscript = 0;
    }
    tcc_free(متن_ptr);
    s1->ld_p = saved_ptr;
    واپس ret < 0 ? ret : -ret;
}
#اگر_ختم /* !ELF_OBJ_ONLY */
