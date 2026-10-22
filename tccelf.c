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
#وصف_رد DEBUG_RELOC

/********************************************************/
/* global variables */

/* elf version information */
بنية sym_نسخو {
    حرف *lib;
    حرف *نسخو;
    صحيح ٻاهريون_اشاريو;
    صحيح prev_same_lib;
};

#وصف_ڪريو nb_sym_versions     s1->nb_sym_versions
#وصف_ڪريو sym_versions        s1->sym_versions
#وصف_ڪريو nb_sym_منزل_نسخو   s1->nb_sym_منزل_نسخو
#وصف_ڪريو sym_منزل_نسخو      s1->sym_منزل_نسخو
#وصف_ڪريو dt_verneednum       s1->dt_verneednum
#وصف_ڪريو versym_section      s1->versym_section
#وصف_ڪريو verneed_section     s1->verneed_section

/* special flag to indicate that the section should not be linked to the other ones */
#وصف_ڪريو SHF_ذاتي 0x80000000
/* section is dynsymtab_section */
#وصف_ڪريو SHF_DYNSYM 0x40000000

#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
#وصف_ڪريو shf_RELRO SHF_ALLOC
ساكن ثابت حرف rdata[] = ".rdata";
#وإلا
#وصف_ڪريو shf_RELRO SHF_ALLOC /* eventually made SHF_WRITE in sort_sections() */
ساكن ثابت حرف rdata[] = ".data.ro";
#جيڪڏهن_پورو

/* ------------------------------------------------------------------------- */

ST_FUNC فراغ tccelf_new(TCCState *s)
{
    TCCState *s1 = s;

    /* no section zero */
    dynarray_جوڙيو(&s->sections, &s->nb_sections, عدم);

    /* create standard sections */
    متن_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    معلومات_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    /* create ro data section (make ro after relocation done with GNU_RELRO) */
    rodata_section = new_section(s, rdata, SHT_PROGBITS, shf_RELRO);
    bss_section = new_section(s, ".bss", SHT_NOBITS, SHF_ALLOC | SHF_WRITE);
    common_section = new_section(s, ".common", SHT_NOBITS, SHF_ذاتي);
    common_section->sh_انگ = SHN_COMMON;

    /* symbols are always generated for linking stage */
    symtab_section = new_symtab(s, ".symtab", SHT_SYMTAB, 0,
                                ".strtab",
                                ".hashtab", SHF_ذاتي);

    /* private symbol table for dynamic symbols */
    s->dynsymtab_section = new_symtab(s, ".dynsymtab", SHT_SYMTAB, SHF_ذاتي|SHF_DYNSYM,
                                      ".dynstrtab",
                                      ".dynhashtab", SHF_ذاتي);
    get_sym_attr(s, 0, 1);

    إذا (s->do_debug) {
        /* add debug sections */
        tcc_debug_new(s);
    }

#إذا TCC_EH_چوکٺو
    إذا (s->output_format != TCC_OUTPUT_FORMAT_ELF)
        s->unwind_tables = 0;
    tcc_eh_چوکٺو_شروعات(s);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
    إذا (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        /* (make ro after relocation done with GNU_RELRO) */
        bounds_section = new_section(s, ".bounds", SHT_PROGBITS, shf_RELRO);
        lbounds_section = new_section(s, ".lbounds", SHT_PROGBITS, shf_RELRO);
    }
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
    /* to make sure that -ltcc1 -Wl,-e,_start will grab the startup code
       from libtcc1.a (unless _start defined) */
    إذا (s->elf_entryname)
        سيٽ_global_sym(s, s->elf_entryname, عدم, 0); /* SHN_UNDEF */
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
    إذا (عدم == s->elfint && s1->output_type != TCC_OUTPUT_OBJ) {
        ثابت حرف *p = CONFIG_TCC_ELFINTERP;
#إذا defined TCC_هدف_ARM && defined CONFIG_TCC_ELFINTERP_ARMHF
        إذا (s->float_abi == ARM_HARD_FLOAT)
            p = CONFIG_TCC_ELFINTERP_ARMHF;
#جيڪڏهن_پورو
#إذا defined TCC_IS_NATIVE && defined TARGETOS_BSD
        /* see commit 55cb2170cd5ce77a7d76dcaf462fad2707281605 */
        { ثابت حرف *e = getenv("LD_SO"); إذا (e) p = e; }
#جيڪڏهن_پورو
        s->elfint = tcc_strdup(p);
    }
#جيڪڏهن_پورو /* ndef ELF_OBJ_ONLY */
}

ST_FUNC فراغ free_section(Section *s)
{
    إذا (!s)
        أرجع;
    tcc_free(s->معلومات);
    s->معلومات = عدم;
    s->معلومات_allocated = s->معلومات_وٿي = 0;
}

ST_FUNC فراغ tccelf_delete(TCCState *s1)
{
    صحيح i;

#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
    /* free symbol versions */
    لكل (i = 0; i < nb_sym_versions; i++) {
        tcc_free(sym_versions[i].نسخو);
        tcc_free(sym_versions[i].lib);
    }
    tcc_free(sym_versions);
    tcc_free(sym_منزل_نسخو);
#جيڪڏهن_پورو

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
        s->sh_وٿي = s->معلومات_وٿي;
    }
    /* disable symbol hashing during compilation */
    s = s1->symtab, s->reloc = s->hash, s->hash = عدم;
#إذا defined TCC_هدف_X86_64 && defined TCC_هدف_PE
    s1->uw_sym = 0;
    s1->uw_offs = 0;
#جيڪڏهن_پورو
}

ساكن فراغ update_relocs(TCCState *s1, Section *s, صحيح *old_منزل_new_syms, صحيح پهريون_sym);

/* At the end of compilation, convert any UNDEF syms to global, and merge
   with previously existing symbols */
ST_FUNC فراغ tccelf_پڇاڙي_file(TCCState *s1)
{
    Section *s = s1->symtab;
    صحيح پهريون_sym, nb_syms, *tr, i;

    پهريون_sym = s->sh_وٿي / حجم (ElfSym);
    nb_syms = s->معلومات_وٿي / حجم (ElfSym) - پهريون_sym;
    s->معلومات_وٿي = s->sh_وٿي;
    s->link->معلومات_وٿي = s->link->sh_وٿي;
    s->hash = s->reloc, s->reloc = عدم;
    tr = tcc_mallocz(nb_syms * حجم *tr);

    لكل (i = 0; i < nb_syms; ++i) {
        ElfSym *sym = (ElfSym*)s->معلومات + پهريون_sym + i;
        إذا (sym->st_shndx == SHN_UNDEF) {
            صحيح sym_bind = ELFW(ST_BIND)(sym->st_info);
            صحيح sym_type = ELFW(ST_TYPE)(sym->st_info);
            إذا (sym_bind == STB_LOCAL)
                sym_bind = STB_GLOBAL;
#جيڪڏهن_وصف_نه_ٿيل TCC_هدف_PE
            إذا (sym_bind == STB_GLOBAL && s1->output_type == TCC_OUTPUT_OBJ) {
                /* undefined symbols with STT_FUNC are confusing gnu ld when
                   linking statically to STT_GNU_IFUNC.  Keep TLS typed,
                   otherwise gnu ld rejects non-TLS refs to TLS definitions. */
                إذا (sym_type != STT_TLS)
                    sym_type = STT_NOTYPE;
            }
#جيڪڏهن_پورو
            sym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
        }
        tr[i] = سيٽ_elf_sym(s, sym->st_قدر, sym->st_سائيز, sym->st_info,
            sym->st_other, sym->st_shndx, (حرف*)s->link->معلومات + sym->st_name);
    }
    /* now update relocations */
    update_relocs(s1, s, tr, پهريون_sym);
    tcc_free(tr);
    /* record text/data/bss output for -bench info */
    لكل (i = 0; i < 4; ++i) {
        s = s1->sections[i + 1];
        s1->ڪل_output[i] += s->معلومات_وٿي - s->sh_وٿي;
    }
}

ST_FUNC Section *new_section(TCCState *s1, ثابت حرف *name, صحيح sh_type, صحيح sh_flags)
{
    Section *sec;

    sec = tcc_mallocz(حجم(Section) + لڙي_ڊيگهه(name));
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
        sec->sh_addralign = PTR_سائيز;
        اكسر;
    حالة SHT_STRTAB:
        sec->sh_addralign = 1;
        اكسر;
    افتراضي:
        sec->sh_addralign =  PTR_سائيز; /* gcc/pcc default alignment */
        اكسر;
    }

    إذا (sh_flags & SHF_ذاتي) {
        dynarray_جوڙيو(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } وإلا {
        sec->sh_انگ = s1->nb_sections;
        dynarray_جوڙيو(&s1->sections, &s1->nb_sections, sec);
    }

    أرجع sec;
}

ST_FUNC فراغ init_symtab(Section *s)
{
    صحيح *ptr, nb_buckets = 1;
    put_elf_str(s->link, "");
    section_ptr_جوڙيو(s, حجم (ElfW(Sym)));
    ptr = section_ptr_جوڙيو(s->hash, (2 + nb_buckets + 1) * حجم(صحيح));
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
    أرجع symtab;
}

/* realloc section and set its content to zero */
ST_FUNC فراغ section_realloc(Section *sec, بنانشان ڊگهو new_سائيز)
{
    بنانشان ڊگهو سائيز;
    بنانشان حرف *معلومات;

    سائيز = sec->معلومات_allocated;
    إذا (سائيز == 0)
        سائيز = 1;
    طالما (سائيز < new_سائيز)
        سائيز = سائيز * 2;
    معلومات = tcc_realloc(sec->معلومات, سائيز);
    memset(معلومات + sec->معلومات_allocated, 0, سائيز - sec->معلومات_allocated);
    sec->معلومات = معلومات;
    sec->معلومات_allocated = سائيز;
}

/* reserve at least 'size' bytes aligned per 'align' in section
   'sec' from current offset, and return the aligned offset */
ST_FUNC سائيز_t section_جوڙيو(Section *sec, addr_t سائيز, صحيح align)
{
    سائيز_t وٿي, offset1;

    وٿي = (sec->معلومات_وٿي + align - 1) & -align;
    offset1 = وٿي + سائيز;
    إذا (sec->sh_type != SHT_NOBITS && offset1 > sec->معلومات_allocated)
        section_realloc(sec, offset1);
    sec->معلومات_وٿي = offset1;
    إذا (align > sec->sh_addralign)
        sec->sh_addralign = align;
    أرجع وٿي;
}

/* reserve at least 'size' bytes in section 'sec' from
   sec->data_offset. */
ST_FUNC فراغ *section_ptr_جوڙيو(Section *sec, addr_t سائيز)
{
    سائيز_t وٿي = section_جوڙيو(sec, سائيز, 1);
    أرجع sec->معلومات + وٿي;
}

#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
/* reserve at least 'size' bytes from section start */
ساكن فراغ section_reserve(Section *sec, بنانشان ڊگهو سائيز)
{
    إذا (سائيز > sec->معلومات_allocated)
        section_realloc(sec, سائيز);
    إذا (سائيز > sec->معلومات_وٿي)
        sec->معلومات_وٿي = سائيز;
}
#جيڪڏهن_پورو

ساكن Section *have_section(TCCState *s1, ثابت حرف *name)
{
    Section *sec;
    صحيح i;
    لكل(i = 1; i < s1->nb_sections; i++) {
        sec = s1->sections[i];
        إذا (!strcmp(name, sec->name))
            أرجع sec;
    }
    أرجع عدم;
}

/* return a reference to a section, and create it if it does not
   exists */
ST_FUNC Section *ڳوليو_section(TCCState *s1, ثابت حرف *name)
{
    Section *sec = have_section(s1, name);
    إذا (sec)
        أرجع sec;
    /* sections are created as PROGBITS */
    أرجع new_section(s1, name, SHT_PROGBITS, SHF_ALLOC);
}

/* ------------------------------------------------------------------------- */

ST_FUNC صحيح put_elf_str(Section *s, ثابت حرف *sym)
{
    صحيح وٿي, len;
    حرف *ptr;

    len = لڙي_ڊيگهه(sym) + 1;
    وٿي = s->معلومات_وٿي;
    ptr = section_ptr_جوڙيو(s, len);
    memmove(ptr, sym, len);
    أرجع وٿي;
}

/* elf symbol hashing function */
ساكن ElfW(لفظ_2) elf_hash(ثابت بنانشان حرف *name)
{
    ElfW(لفظ_2) h = 0, g;

    طالما (*name) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        إذا (g)
            h ^= g >> 24;
        h &= ~g;
    }
    أرجع h;
}

/* rebuild hash table of section s */
/* NOTE: we do factorize the hash table code to go faster */
ساكن فراغ rebuild_hash(Section *s, بنانشان صحيح nb_buckets)
{
    ElfW(Sym) *sym;
    صحيح *ptr, *hash, nb_syms, sym_اشاريو, h;
    بنانشان حرف *strtab;

    strtab = s->link->معلومات;
    nb_syms = s->معلومات_وٿي / حجم(ElfW(Sym));

    إذا (!nb_buckets)
        nb_buckets = ((صحيح*)s->hash->معلومات)[0];

    s->hash->معلومات_وٿي = 0;
    ptr = section_ptr_جوڙيو(s->hash, (2 + nb_buckets + nb_syms) * حجم(صحيح));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    memset(hash, 0, (nb_buckets + 1) * حجم(صحيح));
    ptr += nb_buckets + 1;

    sym = (ElfW(Sym) *)s->معلومات + 1;
    لكل(sym_اشاريو = 1; sym_اشاريو < nb_syms; sym_اشاريو++) {
        إذا (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            h = elf_hash(strtab + sym->st_name) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_اشاريو;
        } وإلا {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}

/* return the symbol number */
ST_FUNC صحيح put_elf_sym(Section *s, addr_t قدر, بنانشان ڊگهو سائيز,
    صحيح info, صحيح other, صحيح shndx, ثابت حرف *name)
{
    صحيح name_وٿي, sym_اشاريو;
    صحيح nbuckets, h;
    ElfW(Sym) *sym;
    Section *hs;

    sym = section_ptr_جوڙيو(s, حجم(ElfW(Sym)));
    إذا (name && name[0])
        name_وٿي = put_elf_str(s->link, name);
    وإلا
        name_وٿي = 0;
    /* XXX: endianness */
    sym->st_name = name_وٿي;
    sym->st_قدر = قدر;
    sym->st_سائيز = سائيز;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
    sym_اشاريو = sym - (ElfW(Sym) *)s->معلومات;
    hs = s->hash;
    إذا (hs) {
        صحيح *ptr, *بنياد;
        ptr = section_ptr_جوڙيو(hs, حجم(صحيح));
        بنياد = (صحيح *)hs->معلومات;
        /* only add global or weak symbols. */
        إذا (ELFW(ST_BIND)(info) != STB_LOCAL) {
            /* add another hashing entry */
            nbuckets = بنياد[0];
            h = elf_hash((بنانشان حرف *)s->link->معلومات + name_وٿي) % nbuckets;
            *ptr = بنياد[2 + h];
            بنياد[2 + h] = sym_اشاريو;
            بنياد[1]++;
            /* we resize the hash table */
            hs->nb_hashed_syms++;
            إذا (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } وإلا {
            *ptr = 0;
            بنياد[1]++;
        }
    }
    أرجع sym_اشاريو;
}

ST_FUNC صحيح ڳوليو_elf_sym(Section *s, ثابت حرف *name)
{
    ElfW(Sym) *sym;
    Section *hs;
    صحيح nbuckets, sym_اشاريو, h;
    ثابت حرف *name1;

    hs = s->hash;
    إذا (!hs)
        أرجع 0;
    nbuckets = ((صحيح *)hs->معلومات)[0];
    h = elf_hash((بنانشان حرف *) name) % nbuckets;
    sym_اشاريو = ((صحيح *)hs->معلومات)[2 + h];
    طالما (sym_اشاريو != 0) {
        sym = &((ElfW(Sym) *)s->معلومات)[sym_اشاريو];
        name1 = (حرف *) s->link->معلومات + sym->st_name;
        إذا (!strcmp(name, name1))
            أرجع sym_اشاريو;
        sym_اشاريو = ((صحيح *)hs->معلومات)[2 + nbuckets + sym_اشاريو];
    }
    أرجع 0;
}

/* return elf symbol value, signal error if 'err' is nonzero, decorate
   name if FORC */
ST_FUNC addr_t get_sym_addr(TCCState *s1, ثابت حرف *name, صحيح err, صحيح forc)
{
    صحيح sym_اشاريو;
    ElfW(Sym) *sym;
    حرف buf[256];
    إذا (forc && s1->leading_underscore
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
        /* win32-32bit stdcall symbols always have _ already */
        && !strchr(name, '@')
#جيڪڏهن_پورو
        ) {
        buf[0] = '_';
        pstrcpy(buf + 1, حجم(buf) - 1, name);
        name = buf;
    }
    sym_اشاريو = ڳوليو_elf_sym(s1->symtab, name);
    sym = &((ElfW(Sym) *)s1->symtab->معلومات)[sym_اشاريو];
    إذا (!sym_اشاريو || sym->st_shndx == SHN_UNDEF) {
        إذا (err)
            tcc_error_noabort("%s not defined", name);
        أرجع (addr_t)-1;
    }
    أرجع sym->st_قدر;
}

/* return elf symbol value */
LIBTCCAPI فراغ *tcc_get_نشان(TCCState *s, ثابت حرف *name)
{
    addr_t addr = get_sym_addr(s, name, 0, 1);
    أرجع addr == -1 ? عدم : (فراغ*)(uintptr_t)addr;
}

LIBTCCAPI صحيح tcc_جوڙيو_نشان(TCCState *s1, ثابت حرف *name, ثابت فراغ *val)
{
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s1, 0, name, (uintptr_t)val);
#وإلا
    حرف buf[256];
    إذا (s1->leading_underscore) {
        buf[0] = '_';
        pstrcpy(buf + 1, حجم(buf) - 1, name);
        name = buf;
    }
    سيٽ_global_sym(s1, name, عدم, (addr_t)(uintptr_t)val); /* NULL: SHN_ABS */
#جيڪڏهن_پورو
    أرجع 0;
}

/* list elf symbol names and values */
ST_FUNC فراغ list_elf_symbols(TCCState *s, فراغ *ctx,
    فراغ (*نشان_cb)(فراغ *ctx, ثابت حرف *name, ثابت فراغ *val))
{
    ElfW(Sym) *sym;
    Section *symtab;
    صحيح sym_اشاريو, پڇاڙي_sym;
    ثابت حرف *name;
    بنانشان حرف sym_vis, sym_bind;

    symtab = s->symtab;
    پڇاڙي_sym = symtab->معلومات_وٿي / حجم (ElfSym);
    لكل (sym_اشاريو = 0; sym_اشاريو < پڇاڙي_sym; ++sym_اشاريو) {
        sym = &((ElfW(Sym) *)symtab->معلومات)[sym_اشاريو];
        إذا (sym->st_قدر) {
            name = (حرف *) symtab->link->معلومات + sym->st_name;
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            sym_vis = ELFW(ST_VISIBILITY)(sym->st_other);
            إذا (sym_bind == STB_GLOBAL && sym_vis == STV_DEFAULT)
                نشان_cb(ctx, name, (فراغ*)(uintptr_t)sym->st_قدر);
        }
    }
}

/* list elf symbol names and values */
LIBTCCAPI فراغ tcc_list_symbols(TCCState *s, فراغ *ctx,
    فراغ (*نشان_cb)(فراغ *ctx, ثابت حرف *name, ثابت فراغ *val))
{
    list_elf_symbols(s, ctx, نشان_cb);
}

#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
ساكن فراغ
نسخو_جوڙيو (TCCState *s1)
{
    صحيح i;
    ElfW(Sym) *sym;
    ElfW(Verneed) *vn = عدم;
    Section *symtab;
    صحيح sym_اشاريو, پڇاڙي_sym, nb_versions = 2, nb_entries = 0;
    ElfW(Half) *versym;
    ثابت حرف *name;

    إذا (0 == nb_sym_versions)
        أرجع;
    versym_section = new_section(s1, ".gnu.version", SHT_GNU_versym, SHF_ALLOC);
    versym_section->sh_entsize = حجم(ElfW(Half));
    versym_section->link = s1->dynsym;

    /* add needed symbols */
    symtab = s1->dynsym;
    پڇاڙي_sym = symtab->معلومات_وٿي / حجم (ElfSym);
    versym = section_ptr_جوڙيو(versym_section, پڇاڙي_sym * حجم(ElfW(Half)));
    لكل (sym_اشاريو = 1; sym_اشاريو < پڇاڙي_sym; ++sym_اشاريو) {
        صحيح dllindex, verndx;
        sym = &((ElfW(Sym) *)symtab->معلومات)[sym_اشاريو];
        name = (حرف *) symtab->link->معلومات + sym->st_name;
        dllindex = ڳوليو_elf_sym(s1->dynsymtab_section, name);
        verndx = (dllindex && dllindex < nb_sym_منزل_نسخو)
                 ? sym_منزل_نسخو[dllindex] : -1;
        إذا (verndx >= 0
            /* XXX: on android, clang refuses to link with a libtcc.so made by tcc
               when defined symbols have a version > 1 or when the version is '0'.
               Whereas version '1' for example for 'signal' in an exe defeats
               bcheck's signal_redir. */
            && (sym->st_shndx == SHN_UNDEF || (s1->output_type & TCC_OUTPUT_EXE))
            ) {
            إذا (!sym_versions[verndx].ٻاهريون_اشاريو)
              sym_versions[verndx].ٻاهريون_اشاريو = nb_versions++;
            versym[sym_اشاريو] = sym_versions[verndx].ٻاهريون_اشاريو;
        } وإلا {
            versym[sym_اشاريو] = 1; /* (*global*) */
        }
        //printf("SYM %d %s\n", versym[sym_index], name);
    }
    /* generate verneed section, but not when it will be empty.  Some
       dynamic linkers look at their contents even when DTVERNEEDNUM and
       section size is zero.  */
    إذا (nb_versions > 2) {
        verneed_section = new_section(s1, ".gnu.version_r",
                                      SHT_GNU_verneed, SHF_ALLOC);
        verneed_section->link = s1->dynsym->link;
        لكل (i = nb_sym_versions; i-- > 0;) {
            بنية sym_نسخو *sv = &sym_versions[i];
            صحيح n_same_libs = 0, prev;
            سائيز_t vnofs;
            ElfW(Vernaux) *vna = 0;
            إذا (sv->ٻاهريون_اشاريو < 1)
              استمر;

            /* make sure that a DT_NEEDED tag is put */
            /* abitest-tcc fails on older i386-linux with "ld-linux.so.2" DT_NEEDED
               ret_int_test... Inconsistency detected by ld.so: dl-minimal.c: 148:
               realloc: Assertion `ptr == alloc_last_block' failed! */
            إذا (strcmp(sv->lib, "ld-linux.so.2"))
                tcc_جوڙيو_dllref(s1, sv->lib, 0);

            vnofs = section_جوڙيو(verneed_section, حجم(*vn), 1);
            vn = (ElfW(Verneed)*)(verneed_section->معلومات + vnofs);
            vn->vn_نسخو = 1;
            vn->vn_file = put_elf_str(verneed_section->link, sv->lib);
            vn->vn_aux = حجم (*vn);
            افعل {
                prev = sv->prev_same_lib;
                إذا (sv->ٻاهريون_اشاريو > 0) {
                    vna = section_ptr_جوڙيو(verneed_section, حجم(*vna));
                    vna->vna_hash = elf_hash ((ثابت بنانشان حرف *)sv->نسخو);
                    vna->vna_flags = 0;
                    vna->vna_other = sv->ٻاهريون_اشاريو;
                    sv->ٻاهريون_اشاريو = -2;
                    vna->vna_name = put_elf_str(verneed_section->link, sv->نسخو);
                    vna->vna_ايندڙ = حجم (*vna);
                    //printf("LIB %d %s %s\n", vna->vna_other, sv->lib, verneed_section->link->data + vna->vna_name);
                    n_same_libs++;
                }
                إذا (prev >= 0)
                  sv = &sym_versions[prev];
            } طالما(prev >= 0);
            vna->vna_ايندڙ = 0;
            vn = (ElfW(Verneed)*)(verneed_section->معلومات + vnofs);
            vn->vn_cnt = n_same_libs;
            vn->vn_ايندڙ = حجم(*vn) + n_same_libs * حجم(*vna);
            nb_entries++;
        }
        إذا (vn)
          vn->vn_ايندڙ = 0;
        verneed_section->sh_info = nb_entries;
    }
    dt_verneednum = nb_entries;
}
#جيڪڏهن_پورو /* ndef ELF_OBJ_ONLY */

/* catch .tbss also */
ساكن صحيح IS_BSS(TCCState *s1, صحيح ndx)
{
    أرجع ndx == SHN_COMMON
     || (ndx < s1->nb_sections
         && s1->sections[ndx]->sh_type == SHT_NOBITS);
}

/* add an elf symbol : check if it is already defined and patch
   it. Return symbol index. NOTE that sh_num can be SHN_UNDEF. */
ST_FUNC صحيح سيٽ_elf_sym(Section *s, addr_t قدر, بنانشان ڊگهو سائيز,
                       صحيح info, صحيح other, صحيح shndx, ثابت حرف *name)
{
    TCCState *s1 = s->s1;
    ElfW(Sym) *esym;
    صحيح sym_bind, sym_اشاريو, sym_type, esym_bind;
    بنانشان حرف sym_vis, esym_vis, new_vis;

    sym_bind = ELFW(ST_BIND)(info);
    sym_type = ELFW(ST_TYPE)(info);
    sym_vis = ELFW(ST_VISIBILITY)(other);

    إذا (sym_bind != STB_LOCAL) {
        /* we search global or weak symbols */
        sym_اشاريو = ڳوليو_elf_sym(s, name);
        إذا (!sym_اشاريو)
            اذهب do_def;
        esym = &((ElfW(Sym) *)s->معلومات)[sym_اشاريو];
        إذا (esym->st_قدر == قدر && esym->st_سائيز == سائيز && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            أرجع sym_اشاريو;
        إذا (esym->st_shndx != SHN_UNDEF) {
            esym_bind = ELFW(ST_BIND)(esym->st_info);
            /* propagate the most constraining visibility */
            /* STV_DEFAULT(0)<STV_PROTECTED(3)<STV_HIDDEN(2)<STV_INTERNAL(1) */
            esym_vis = ELFW(ST_VISIBILITY)(esym->st_other);
            إذا (esym_vis == STV_DEFAULT) {
                new_vis = sym_vis;
            } وإلا إذا (sym_vis == STV_DEFAULT) {
                new_vis = esym_vis;
            } وإلا {
                new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
            }
            esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
                             | new_vis;
            إذا (shndx == SHN_UNDEF) {
                /* ignore adding of undefined symbol if the
                   corresponding symbol is already defined */
            } وإلا إذا (sym_bind == STB_GLOBAL && esym_bind == STB_WEAK) {
                /* global overrides weak, so patch */
                اذهب do_patch;
            } وإلا إذا (sym_bind == STB_WEAK && esym_bind == STB_GLOBAL) {
                /* weak is ignored if already global */
            } وإلا إذا (sym_bind == STB_WEAK && esym_bind == STB_WEAK) {
                /* keep first-found weak definition, ignore subsequents */
            } وإلا إذا (sym_vis == STV_HIDDEN || sym_vis == STV_اندروني) {
                /* ignore hidden symbols after */
            } وإلا إذا (s->sh_flags & SHF_DYNSYM) {
                /* we accept that two DLL define the same symbol */
            } وإلا إذا (!IS_BSS(s1, shndx) && IS_BSS(s1, esym->st_shndx)) {
                /* data symbol gets precedence over common/bss */
                اذهب do_patch;
            } وإلا إذا (IS_BSS(s1, shndx)) {
                /* data symbol keeps precedence over common/bss */
	    } وإلا إذا (esym->st_other & ST_ASM_سيٽ) {
		/* If the existing symbol came from an asm .set
		   we can override.  */
		اذهب do_patch;
            } وإلا {
#إذا 0
                لکو("new_bind=%x new_shndx=%x new_vis=%x old_bind=%x old_shndx=%x old_vis=%x\n",
                       sym_bind, shndx, new_vis, esym_bind, esym->st_shndx, esym_vis);
#جيڪڏهن_پورو
                tcc_error_noabort("link symbol '%s' defined twice", name);
            }
        } وإلا {
            esym->st_other = other;
        do_patch:
            esym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
            esym->st_shndx = shndx;
            esym->st_قدر = قدر;
            esym->st_سائيز = سائيز;
        }
    } وإلا {
    do_def:
        sym_اشاريو = put_elf_sym(s, قدر, سائيز,
                                ELFW(ST_INFO)(sym_bind, sym_type), other,
                                shndx, name);
    }
    أرجع sym_اشاريو;
}

/* put relocation */
ST_FUNC فراغ put_elf_reloca(Section *symtab, Section *s, بنانشان ڊگهو وٿي,
                            صحيح type, صحيح نشان, addr_t addend)
{
    TCCState *s1 = s->s1;
    حرف buf[256];
    Section *sr;
    ElfW_Rel *rel;

    sr = s->reloc;
    إذا (!sr) {
        /* if no relocation section, create it */
        snprintf(buf, حجم(buf), REL_SECTION_FMT, s->name);
        /* if the symtab is allocated, then we consider the relocation
           are also */
        sr = new_section(s->s1, buf, SHT_RELX, symtab->sh_flags);
        sr->sh_entsize = حجم(ElfW_Rel);
        sr->link = symtab;
        sr->sh_info = s->sh_انگ;
        s->reloc = sr;
    }
    rel = section_ptr_جوڙيو(sr, حجم(ElfW_Rel));
    rel->r_وٿي = وٿي;
    rel->r_info = ELFW(R_INFO)(نشان, type);
#إذا SHT_RELX == SHT_RELA
    rel->r_addend = addend;
#جيڪڏهن_پورو
    إذا (SHT_RELX != SHT_RELA && addend)
        tcc_error_noabort("non-zero addend on REL architecture");
}

ST_FUNC فراغ put_elf_reloc(Section *symtab, Section *s, بنانشان ڊگهو وٿي,
                           صحيح type, صحيح نشان)
{
    put_elf_reloca(symtab, s, وٿي, type, نشان, 0);
}

ST_FUNC بنية sym_attr *get_sym_attr(TCCState *s1, صحيح اشاريو, صحيح alloc)
{
    صحيح n;
    بنية sym_attr *tab;

    إذا (اشاريو >= s1->nb_sym_attrs) {
        إذا (!alloc)
            أرجع s1->sym_attrs;
        /* find immediately bigger power of 2 and reallocate array */
        n = 1;
        طالما (اشاريو >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * حجم(*s1->sym_attrs));
        s1->sym_attrs = tab;
        memset(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * حجم(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    أرجع &s1->sym_attrs[اشاريو];
}

ساكن فراغ update_relocs(TCCState *s1, Section *s, صحيح *old_منزل_new_syms, صحيح پهريون_sym)
{
    صحيح i, type, sym_اشاريو;
    Section *sr;
    ElfW_Rel *rel;

    لكل(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        إذا (sr->sh_type == SHT_RELX && sr->link == s) {
            for_each_elem(sr, 0, rel, ElfW_Rel) {
                sym_اشاريو = ELFW(R_SYM)(rel->r_info);
                type = ELFW(R_TYPE)(rel->r_info);
                إذا ((sym_اشاريو -= پهريون_sym) < 0)
                    استمر; /* zero sym_index in reloc (can happen with asm) */
                sym_اشاريو = old_منزل_new_syms[sym_اشاريو];
                rel->r_info = ELFW(R_INFO)(sym_اشاريو, type);
            }
        }
    }
}

/* In an ELF file symbol table, the local symbols must appear below
   the global and weak ones. Since TCC cannot sort it while generating
   the code, we must do it after. All the relocation tables are also
   modified to take into account the symbol table sorting */
ساكن فراغ ترتيب_ڏيو_syms(TCCState *s1, Section *s)
{
    صحيح *old_منزل_new_syms;
    ElfW(Sym) *new_syms;
    صحيح nb_syms, i;
    ElfW(Sym) *p, *q;

    nb_syms = s->معلومات_وٿي / حجم(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * حجم(ElfW(Sym)));
    old_منزل_new_syms = tcc_malloc(nb_syms * حجم(صحيح));

    /* first pass for local symbols */
    p = (ElfW(Sym) *)s->معلومات;
    q = new_syms;
    لكل(i = 0; i < nb_syms; i++) {
        إذا (ELFW(ST_BIND)(p->st_info) == STB_LOCAL) {
            old_منزل_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    /* save the number of local symbols in section header */
    إذا( s->sh_سائيز )    /* this 'if' makes IDA happy */
        s->sh_info = q - new_syms;

    /* then second pass for non local symbols */
    p = (ElfW(Sym) *)s->معلومات;
    لكل(i = 0; i < nb_syms; i++) {
        إذا (ELFW(ST_BIND)(p->st_info) != STB_LOCAL) {
            old_منزل_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }

    /* we copy the new symbols to the old */
    يادگيري_نقل(s->معلومات, new_syms, nb_syms * حجم(ElfW(Sym)));
    tcc_free(new_syms);

    update_relocs(s1, s, old_منزل_new_syms, 0);
    tcc_free(old_منزل_new_syms);
}

#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
/* See: https://flapenguin.me/elf-dt-gnu-hash */
#وصف_ڪريو	ELFCLASS_بٽ (PTR_سائيز * 8)

ساكن Section *create_gnu_hash(TCCState *s1)
{
    صحيح nb_syms, i, ndef, nbuckets, symoffset, bloom_سائيز, bloom_سرڪايو;
    ElfW(Sym) *p;
    Section *gnu_hash;
    Section *dynsym = s1->dynsym;
    Elf32_لفظ *ptr;

    gnu_hash = new_section(s1, ".gnu.hash", SHT_GNU_HASH, SHF_ALLOC);
    gnu_hash->link = dynsym->hash->link;

    nb_syms = dynsym->معلومات_وٿي / حجم(ElfW(Sym));

    /* count def symbols */
    ndef = 0;
    p = (ElfW(Sym) *)dynsym->معلومات;
    لكل(i = 0; i < nb_syms; i++, p++)
        ndef += p->st_shndx != SHN_UNDEF;

    /* calculate gnu hash sizes and fill header */
    nbuckets = ndef / 4 + 1;
    symoffset = nb_syms - ndef;
    bloom_سرڪايو = PTR_سائيز == 8 ? 6 : 5;
    bloom_سائيز = 1; /* must be power of two */
    طالما (ndef >= bloom_سائيز * (1 << (bloom_سرڪايو - 3)))
	bloom_سائيز *= 2;
    ptr = section_ptr_جوڙيو(gnu_hash, 4 * 4 +
				    PTR_سائيز * bloom_سائيز +
				    nbuckets * 4 +
				    ndef * 4);
    ptr[0] = nbuckets;
    ptr[1] = symoffset;
    ptr[2] = bloom_سائيز;
    ptr[3] = bloom_سرڪايو;
    أرجع gnu_hash;
}

ساكن Elf32_لفظ elf_gnu_hash (ثابت بنانشان حرف *name)
{
    Elf32_لفظ h = 5381;
    بنانشان حرف c;

    طالما ((c = *name++))
        h = h * 33 + c;
    أرجع h;
}

ساكن فراغ update_gnu_hash(TCCState *s1, Section *gnu_hash)
{
    صحيح *old_منزل_new_syms;
    ElfW(Sym) *new_syms;
    صحيح nb_syms, i, nbuckets, bloom_سائيز, bloom_سرڪايو;
    ElfW(Sym) *p, *q;
    Section *vs;
    Section *dynsym = s1->dynsym;
    Elf32_لفظ *ptr, *buckets, *chain, *hash;
    بنانشان صحيح *nextbuck;
    addr_t *bloom;
    بنانشان حرف *strtab;
    بنية { صحيح پهريون, آخري; } *buck;

    strtab = dynsym->link->معلومات;
    nb_syms = dynsym->معلومات_وٿي / حجم(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * حجم(ElfW(Sym)));
    old_منزل_new_syms = tcc_malloc(nb_syms * حجم(صحيح));
    hash = tcc_malloc(nb_syms * حجم(Elf32_لفظ));
    nextbuck = tcc_malloc(nb_syms * حجم(صحيح));

    /* calculate hashes and copy undefs */
    p = (ElfW(Sym) *)dynsym->معلومات;
    q = new_syms;
    لكل(i = 0; i < nb_syms; i++, p++) {
        إذا (p->st_shndx == SHN_UNDEF) {
            old_منزل_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
	وإلا
	    hash[i] = elf_gnu_hash(strtab + p->st_name);
    }

    ptr = (Elf32_لفظ *) gnu_hash->معلومات;
    nbuckets = ptr[0];
    bloom_سائيز = ptr[2];
    bloom_سرڪايو = ptr[3];
    bloom = (addr_t *) (فراغ *) &ptr[4];
    buckets = (Elf32_لفظ*) (فراغ *) &bloom[bloom_سائيز];
    chain = &buckets[nbuckets];
    buck = tcc_malloc(nbuckets * حجم(*buck));

    إذا (gnu_hash->معلومات_وٿي != 4 * 4 +
				 PTR_سائيز * bloom_سائيز +
				 nbuckets * 4 +
				 (nb_syms - (q - new_syms)) * 4)
	tcc_error_noabort ("gnu_hash size incorrect");

    /* find buckets */
    لكل(i = 0; i < nbuckets; i++)
	buck[i].پهريون = -1;

    p = (ElfW(Sym) *)dynsym->معلومات;
    لكل(i = 0; i < nb_syms; i++, p++)
        إذا (p->st_shndx != SHN_UNDEF) {
	    صحيح ٻالٽي = hash[i] % nbuckets;

	    إذا (buck[ٻالٽي].پهريون == -1)
		buck[ٻالٽي].پهريون = buck[ٻالٽي].آخري = i;
	    وإلا {
		nextbuck[buck[ٻالٽي].آخري] = i;
		buck[ٻالٽي].آخري = i;
	    }
	}

    /* fill buckets/chains/bloom and sort symbols */
    p = (ElfW(Sym) *)dynsym->معلومات;
    لكل(i = 0; i < nbuckets; i++) {
	صحيح cur = buck[i].پهريون;

	إذا (cur != -1) {
	    buckets[i] = q - new_syms;
	    لكل (;;) {
                old_منزل_new_syms[cur] = q - new_syms;
                *q++ = p[cur];
	        *chain++ = hash[cur] & ~1;
		bloom[(hash[cur] / ELFCLASS_بٽ) % bloom_سائيز] |=
		    (addr_t)1 << (hash[cur] % ELFCLASS_بٽ) |
		    (addr_t)1 << ((hash[cur] >> bloom_سرڪايو) % ELFCLASS_بٽ);
		إذا (cur == buck[i].آخري)
		    اكسر;
		cur = nextbuck[cur];
	    }
	    chain[-1] |= 1;
	}
    }

    يادگيري_نقل(dynsym->معلومات, new_syms, nb_syms * حجم(ElfW(Sym)));
    tcc_free(new_syms);
    tcc_free(hash);
    tcc_free(buck);
    tcc_free(nextbuck);

    update_relocs(s1, dynsym, old_منزل_new_syms, 0);

    /* modify the versions */
    vs = versym_section;
    إذا (vs) {
	ElfW(Half) *newver, *versym = (ElfW(Half) *)vs->معلومات;

	إذا (1/*versym*/) {
            newver = tcc_malloc(nb_syms * حجم(*newver));
	    لكل (i = 0; i < nb_syms; i++)
	        newver[old_منزل_new_syms[i]] = versym[i];
	    يادگيري_نقل(vs->معلومات, newver, nb_syms * حجم(*newver));
	    tcc_free(newver);
	}
    }

    tcc_free(old_منزل_new_syms);

    /* rebuild hash */
    ptr = (Elf32_لفظ *) dynsym->hash->معلومات;
    rebuild_hash(dynsym, ptr[0]);
}
#جيڪڏهن_پورو /* ELF_OBJ_ONLY */

/* relocate symbol table, resolve undefined symbols if do_resolve is
   true and output error if undefined symbol. */
ST_FUNC فراغ relocate_syms(TCCState *s1, Section *symtab, صحيح do_resolve)
{
    ElfW(Sym) *sym;
    صحيح sym_bind, sh_انگ;
    ثابت حرف *name;

    for_each_elem(symtab, 1, sym, ElfW(Sym)) {
        sh_انگ = sym->st_shndx;
        إذا (sh_انگ == SHN_UNDEF) {
            إذا (do_resolve == 2) /* relocating dynsym */
                استمر;
            name = (حرف *) s1->symtab->link->معلومات + sym->st_name;
            /* Use ld.so to resolve symbol for us (for tcc -run) */
            إذا (do_resolve) {
#إذا defined TCC_IS_NATIVE && !defined TCC_هدف_PE
                /* dlsym() needs the undecorated name.  */
                ثابت حرف *name_ud = &name[s1->leading_underscore];
                فراغ *addr = عدم;
                إذا (!s1->nostdlib)
                    addr = dlsym(RTLD_DEFAULT, name_ud);
		إذا (addr == عدم) {
		    صحيح i;
		    لكل (i = 0; i < s1->nb_loaded_dlls; i++)
                        إذا ((addr = dlsym(s1->loaded_dlls[i]->handle, name_ud)))
			    اكسر;
		}
                إذا (addr) {
                    sym->st_قدر = (addr_t) addr;
#جيڪڏهن_وصف_ٿيل DEBUG_RELOC
		    لکو ("relocate_sym: %s -> 0x%lx\n", name, sym->st_قدر);
#جيڪڏهن_پورو
                    اذهب مليو;
                }
#جيڪڏهن_پورو
            /* if dynamic symbol exist, it will be used in relocate_section */
            } وإلا إذا (s1->dynsym && ڳوليو_elf_sym(s1->dynsym, name))
                اذهب مليو;
            /* XXX: _fp_hw seems to be part of the ABI, so we ignore
               it */
            إذا (!strcmp(name, "_fp_hw"))
                اذهب مليو;
            /* only weak symbols are accepted to be undefined. Their
               value is zero */
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            إذا (sym_bind == STB_WEAK)
                sym->st_قدر = 0;
            وإلا
                tcc_error_noabort("unresolved reference to '%s'", name);

        } وإلا إذا (sh_انگ < SHN_LORESERVE) {
            /* add section base */
            sym->st_قدر += s1->sections[sym->st_shndx]->sh_addr;
        }
    مليو: ;
    }
}

/* relocate a given section (CPU dependent) by applying the relocations
   in the associated relocation section */
ساكن فراغ relocate_section(TCCState *s1, Section *s, Section *sr)
{
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    صحيح type, sym_اشاريو;
    بنانشان حرف *ptr;
    addr_t tgt, addr;
    صحيح is_dwarf = s->sh_انگ >= s1->dwlo && s->sh_انگ < s1->dwhi;

    qrel = (ElfW_Rel *)sr->معلومات;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
	إذا (s->معلومات == عدم) /* bss */
	    استمر;
        ptr = s->معلومات + rel->r_وٿي;
        sym_اشاريو = ELFW(R_SYM)(rel->r_info);
        sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_اشاريو];
        type = ELFW(R_TYPE)(rel->r_info);
        tgt = sym->st_قدر;
#إذا SHT_RELX == SHT_RELA
        tgt += rel->r_addend;
#جيڪڏهن_پورو
        إذا (is_dwarf && type == R_معلومات_32_DW
            && sym->st_shndx >= s1->dwlo && sym->st_shndx < s1->dwhi) {
            /* dwarf section relocation to each other */
            add32le(ptr, tgt - s1->sections[sym->st_shndx]->sh_addr);
            استمر;
        }
        addr = s->sh_addr + rel->r_وٿي;
        relocate(s1, rel, type, ptr, addr, tgt);
    }

#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
    /* if the relocation is allocated, we change its symbol table */
    إذا (sr->sh_flags & SHF_ALLOC) {
        sr->link = s1->dynsym;
        إذا (s1->output_type & TCC_OUTPUT_DYN) {
            سائيز_t r = (uint8_t*)qrel - sr->معلومات;
            إذا (حجم ((Stab_Sym*)0)->n_قدر < PTR_سائيز
                && 0 == strcmp(s->name, ".stab"))
                r = 0; /* cannot apply 64bit relocation to 32bit value */
            sr->معلومات_وٿي = sr->sh_سائيز = r;
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_PIE
            إذا (r && (s->sh_flags & SHF_EXECINSTR))
                tcc_warning("%d relocations to %s", (بنانشان)(r / حجم *qrel), s->name);
#جيڪڏهن_پورو
        }
    }
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل TCC_هدف_RISCV64
    dynarray_reset(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries);
#جيڪڏهن_پورو
}

/* relocate all sections */
ST_FUNC فراغ relocate_sections(TCCState *s1)
{
    صحيح i;
    Section *s, *sr;

    لكل (i = 1; i < s1->nb_sections; ++i) {
        sr = s1->sections[i];
        إذا (sr->sh_type != SHT_RELX)
            استمر;
        s = s1->sections[sr->sh_info];
#جيڪڏهن_وصف_نه_ٿيل TCC_هدف_MACHO
        إذا (s != s1->got
            || s1->static_link
            || s1->output_type == TCC_OUTPUT_يادگيري)
#جيڪڏهن_پورو
        {
            relocate_section(s1, s, sr);
        }
#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
        إذا (sr->sh_flags & SHF_ALLOC) {
            ElfW_Rel *rel;
            /* relocate relocation table in 'sr' */
            for_each_elem(sr, 0, rel, ElfW_Rel)
                rel->r_وٿي += s->sh_addr;
        }
#جيڪڏهن_پورو
    }
}

#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
/* count the number of dynamic relocations so that we can reserve
   their space */
ساكن صحيح prepare_dynamic_rel(TCCState *s1, Section *sr)
{
    صحيح ڳڻپ_2 = 0;
#إذا defined(TCC_هدف_I386) || defined(TCC_هدف_X86_64) || \
    defined(TCC_هدف_ARM) || defined(TCC_هدف_ARM64) || \
    defined(TCC_هدف_RISCV64)
    ElfW_Rel *rel;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
        صحيح sym_اشاريو = ELFW(R_SYM)(rel->r_info);
        صحيح type = ELFW(R_TYPE)(rel->r_info);
        بدل(type) {
#إذا defined(TCC_هدف_I386)
        حالة R_386_32:
            إذا (!get_sym_attr(s1, sym_اشاريو, 0)->dyn_اشاريو
                && ((ElfW(Sym)*)symtab_section->معلومات + sym_اشاريو)->st_shndx == SHN_UNDEF) {
                /* don't fixup unresolved (weak) symbols */
                rel->r_info = ELFW(R_INFO)(sym_اشاريو, R_386_RELATIVE);
                اكسر;
            }
#وإلاإذا defined(TCC_هدف_X86_64)
        حالة R_X86_64_32:
        حالة R_X86_64_32S:
        حالة R_X86_64_64:
#وإلاإذا defined(TCC_هدف_ARM)
        حالة R_ARM_ABS32:
        حالة R_ARM_TARGET1:
#وإلاإذا defined(TCC_هدف_ARM64)
        حالة R_AARCH64_ABS32:
        حالة R_AARCH64_ABS64:
#وإلاإذا defined(TCC_هدف_RISCV64)
        حالة R_RISCV_32:
        حالة R_RISCV_64:
#جيڪڏهن_پورو
            ڳڻپ_2++;
            اكسر;
#إذا defined(TCC_هدف_I386)
        حالة R_386_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_اشاريو];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    إذا (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_اشاريو, R_386_PLT32);
	        اكسر;
	    }
	}
#وإلاإذا defined(TCC_هدف_X86_64)
        حالة R_X86_64_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_اشاريو];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    إذا (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_اشاريو, R_X86_64_PLT32);
	        اكسر;
	    }
	}
#وإلاإذا defined(TCC_هدف_ARM64)
        حالة R_AARCH64_PREL32:
#جيڪڏهن_پورو
            إذا (s1->output_type != TCC_OUTPUT_DLL)
                اكسر;
            إذا (get_sym_attr(s1, sym_اشاريو, 0)->dyn_اشاريو)
                ڳڻپ_2++;
            اكسر;
        افتراضي:
            اكسر;
        }
    }
#جيڪڏهن_پورو
    أرجع ڳڻپ_2;
}
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل NEED_BUILD_GOT
ساكن صحيح build_got(TCCState *s1)
{
    /* if no got, then create it */
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    s1->got->sh_entsize = 4;
    /* keep space for _DYNAMIC pointer and two dummy got entries */
    section_ptr_جوڙيو(s1->got, 3 * PTR_سائيز);
    أرجع سيٽ_elf_sym(symtab_section, 0, 0, ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
        0, s1->got->sh_انگ, "_GLOBAL_OFFSET_TABLE_");
}

/* Create a GOT and (for function call) a PLT entry corresponding to a symbol
   in s1->symtab. When creating the dynamic symbol table entry for the GOT
   relocation, use 'size' and 'info' for the corresponding symbol metadata.
   Returns the offset of the GOT or (if any) PLT entry. */
ساكن بنية sym_attr * put_got_داخلا(TCCState *s1, صحيح dyn_reloc_type,
                                       صحيح sym_اشاريو)
{
    صحيح need_plt_داخلا;
    ثابت حرف *name;
    ElfW(Sym) *sym;
    بنية sym_attr *attr;
    بنانشان got_وٿي;
    حرف plt_name[200];
    صحيح len;
    Section *s_rel;

    need_plt_داخلا = (dyn_reloc_type == R_JMP_جڳهه);
    attr = get_sym_attr(s1, sym_اشاريو, 1);

    /* In case a function is both called and its address taken 2 GOT entries
       are created, one for taking the address (GOT) and the other for the PLT
       entry (PLTGOT).  */
    إذا (need_plt_داخلا ? attr->plt_وٿي : attr->got_وٿي)
        أرجع attr;

    s_rel = s1->got;
    إذا (need_plt_داخلا) {
        إذا (!s1->plt) {
            s1->plt = new_section(s1, ".plt", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
            s1->plt->sh_entsize = 4;
        }
        s_rel = s1->plt;
    }

    /* create the GOT entry */
    got_وٿي = s1->got->معلومات_وٿي;
    section_ptr_جوڙيو(s1->got, PTR_سائيز);

    /* Create the GOT relocation that will insert the address of the object or
       function of interest in the GOT entry. This is a static relocation for
       memory output (dlsym will give us the address of symbols) and dynamic
       relocation otherwise (executable and DLLs). The relocation should be
       done lazily for GOT entry with *_JUMP_SLOT relocation type (the one
       associated to a PLT entry) but is currently done at load time for an
       unknown reason. */

    sym = &((ElfW(Sym) *) symtab_section->معلومات)[sym_اشاريو];
    name = (حرف *) symtab_section->link->معلومات + sym->st_name;
    //printf("sym %d %s\n", need_plt_entry, name);

    إذا (s1->dynsym) {
	إذا (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
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
	    put_elf_reloc(s1->dynsym, s1->got, got_وٿي, R_RELATIVE,
			  sym_اشاريو);
	} وإلا {
	    إذا (0 == attr->dyn_اشاريو)
                attr->dyn_اشاريو = سيٽ_elf_sym(s1->dynsym, sym->st_قدر,
                                              sym->st_سائيز, sym->st_info, 0,
                                              sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s_rel, got_وٿي, dyn_reloc_type,
			  attr->dyn_اشاريو);
	}
    } وإلا {
        put_elf_reloc(symtab_section, s1->got, got_وٿي, dyn_reloc_type,
                      sym_اشاريو);
    }

    إذا (need_plt_داخلا) {
        attr->plt_وٿي = create_plt_داخلا(s1, got_وٿي, attr);

        /* create a symbol 'sym@plt' for the PLT jump vector */
        len = لڙي_ڊيگهه(name);
        إذا (len > حجم plt_name - 5)
            len = حجم plt_name - 5;
        يادگيري_نقل(plt_name, name, len);
        strcpy(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_وٿي, 0,
            ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0, s1->plt->sh_انگ, plt_name);
    } وإلا {
        attr->got_وٿي = got_وٿي;
    }

    أرجع attr;
}

/* build GOT and PLT entries */
/* Two passes because R_JMP_SLOT should become first. Some targets
   (arm, arm64) do not allow mixing R_JMP_SLOT and R_GLOB_DAT. */
ST_FUNC فراغ build_got_entries(TCCState *s1, صحيح got_sym)
{
    Section *s;
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    صحيح i, type, gotplt_داخلا, reloc_type, sym_اشاريو;
    بنية sym_attr *attr;
    صحيح pass = 0;
redo:
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        إذا (s->sh_type != SHT_RELX)
            استمر;
        /* no need to handle got relocations */
        إذا (s->link != symtab_section)
            استمر;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_داخلا = gotplt_داخلا_type(type);
            إذا (gotplt_داخلا == -1) {
                tcc_error_noabort ("Unknown relocation type for got: %d", type);
                استمر;
            }
            sym_اشاريو = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_اشاريو];

            إذا (gotplt_داخلا == NO_GOTPLT_داخلا) {
                استمر;
            }

            /* Automatically create PLT/GOT [entry] if it is an undefined
	       reference (resolved at runtime), or the symbol is absolute,
	       probably created by tcc_add_symbol, and thus on 64-bit
	       targets might be too far from application code.  */
            إذا (gotplt_داخلا == AUTO_GOTPLT_داخلا) {
                إذا (sym->st_shndx == SHN_UNDEF) {
                    ElfW(Sym) *esym;
		    صحيح dynindex;
                    إذا (!PCRELATIVE_DLLPLT
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
		    إذا (s1->dynsym) {
			/* dynsym isn't set for -run :-/  */
			dynindex = get_sym_attr(s1, sym_اشاريو, 0)->dyn_اشاريو;
			esym = (ElfW(Sym) *)s1->dynsym->معلومات + dynindex;
			إذا (dynindex
			    && (ELFW(ST_TYPE)(esym->st_info) == STT_FUNC
				|| (ELFW(ST_TYPE)(esym->st_info) == STT_NOTYPE
				    && ELFW(ST_TYPE)(sym->st_info) == STT_FUNC)))
			    اذهب jmp_جڳهه;
		    }
                } وإلا إذا (sym->st_shndx == SHN_ABS) {
                    إذا (sym->st_قدر == 0) /* from tcc_add_btstub() */
                        استمر;
#جيڪڏهن_وصف_نه_ٿيل TCC_هدف_ARM
                    إذا (PTR_سائيز != 8)
                        استمر;
#جيڪڏهن_پورو
                    /* from tcc_add_symbol(): on 64 bit platforms these
                       need to go through .got */
                } وإلا
                    استمر;
            }

#جيڪڏهن_وصف_ٿيل TCC_هدف_I386
            إذا ((type == R_386_PLT32 || type == R_386_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		إذا (pass != 0)
		    استمر;
                rel->r_info = ELFW(R_INFO)(sym_اشاريو, R_386_PC32);
                استمر;
            }
#جيڪڏهن_پورو
#جيڪڏهن_وصف_ٿيل TCC_هدف_X86_64
            إذا ((type == R_X86_64_PLT32 || type == R_X86_64_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		إذا (pass != 0)
		    استمر;
                rel->r_info = ELFW(R_INFO)(sym_اشاريو, R_X86_64_PC32);
                استمر;
            }
#جيڪڏهن_پورو
            reloc_type = ڪوڊ_reloc(type);
            إذا (reloc_type == -1) {
                tcc_error_noabort ("Unknown relocation type: %d", type);
                استمر;
            }

            إذا (reloc_type != 0) {
        jmp_جڳهه:
	        إذا (pass != 0)
                    استمر;
                reloc_type = R_JMP_جڳهه;
            } وإلا {
	        إذا (pass != 1)
                    استمر;
                reloc_type = R_GLOB_DAT;
            }

            إذا (!s1->got)
                got_sym = build_got(s1);

            إذا (gotplt_داخلا == BUILD_GOT_ONLY)
                استمر;

            attr = put_got_داخلا(s1, reloc_type, sym_اشاريو);

            إذا (reloc_type == R_JMP_جڳهه)
                rel->r_info = ELFW(R_INFO)(attr->plt_sym, type);
        }
    }
    إذا (++pass < 2)
        اذهب redo;
    /* .rel.plt refers to .got actually */
    إذا (s1->plt && s1->plt->reloc)
        s1->plt->reloc->sh_info = s1->got->sh_انگ;
    إذا (got_sym) /* set size */
        ((ElfW(Sym)*)symtab_section->معلومات)[got_sym].st_سائيز = s1->got->معلومات_وٿي;
}
#جيڪڏهن_پورو /* def NEED_BUILD_GOT */

ST_FUNC صحيح سيٽ_global_sym(TCCState *s1, ثابت حرف *name, Section *sec, addr_t offs)
{
    صحيح shn = sec ? sec->sh_انگ : offs || !name ? SHN_ABS : SHN_UNDEF;
    إذا (sec && offs == -1)
        offs = sec->معلومات_وٿي;
    أرجع سيٽ_elf_sym(symtab_section, offs, 0,
        ELFW(ST_INFO)(name ? STB_GLOBAL : STB_LOCAL, STT_NOTYPE), 0, shn, name);
}

ساكن فراغ جوڙيو_init_array_مقرر_ڪري(TCCState *s1, ثابت حرف *section_name)
{
    Section *s;
    addr_t پڇاڙي_وٿي;
    حرف buf[1024];
    s = have_section(s1, section_name);
    إذا (!s || !(s->sh_flags & SHF_ALLOC)) {
        پڇاڙي_وٿي = 0;
        s = متن_section;
    } وإلا {
        پڇاڙي_وٿي = s->معلومات_وٿي;
    }
    snprintf(buf, حجم(buf), "__%s_start", section_name + 1);
    سيٽ_global_sym(s1, buf, s, 0);
    snprintf(buf, حجم(buf), "__%s_end", section_name + 1);
    سيٽ_global_sym(s1, buf, s, پڇاڙي_وٿي);
}

ST_FUNC فراغ جوڙيو_array (TCCState *s1, ثابت حرف *sec, صحيح c)
{
    Section *s;
    s = ڳوليو_section(s1, sec);
    s->sh_flags = shf_RELRO;
    s->sh_type = sec[1] == 'i' ? SHT_INIT_ARRAY : SHT_FINI_ARRAY;
    put_elf_reloc (s1->symtab, s, s->معلومات_وٿي, R_معلومات_PTR, c);
    section_ptr_جوڙيو(s, PTR_سائيز);
}

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
ST_FUNC فراغ tcc_جوڙيو_bcheck(TCCState *s1)
{
    إذا (0 == s1->do_bounds_check)
        أرجع;
    section_ptr_جوڙيو(bounds_section, حجم(addr_t));
}
#جيڪڏهن_پورو

/* set symbol to STB_LOCAL and resolve. The point is to not export it as
   a dynamic symbol to allow so's to have one each with a different value. */
ساكن فراغ سيٽ_local_sym(TCCState *s1, ثابت حرف *name, Section *s, صحيح وٿي)
{
    صحيح c = ڳوليو_elf_sym(s1->symtab, name);
    إذا (c) {
        ElfW(Sym) *esym = (ElfW(Sym)*)s1->symtab->معلومات + c;
        esym->st_info = ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE);
        esym->st_قدر = وٿي;
        esym->st_shndx = s->sh_انگ;
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

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BACKTRACE
ساكن فراغ put_ptr(TCCState *s1, Section *s, صحيح offs)
{
    صحيح c;
    c = سيٽ_global_sym(s1, عدم, s, offs);
    s = معلومات_section;
    put_elf_reloc (s1->symtab, s, s->معلومات_وٿي, R_معلومات_PTR, c);
    section_ptr_جوڙيو(s, PTR_سائيز);
}

ST_FUNC فراغ tcc_جوڙيو_btstub(TCCState *s1)
{
    Section *s;
    صحيح n, o, *p;
    CString cstr;
    ثابت حرف *__rt_info = &"___rt_info"[!s1->leading_underscore];

    s = معلومات_section;
    /* Align to PTR_SIZE */
    section_جوڙيو(s, 0, PTR_سائيز);
    o = s->معلومات_وٿي;
    /* create a struct rt_context (see tccrun.c) */
    إذا (s1->dwarf) {
        put_ptr(s1, dwarf_سٽ_section, 0);
        put_ptr(s1, dwarf_سٽ_section, -1);
	إذا (s1->dwarf >= 5)
            put_ptr(s1, dwarf_سٽ_str_section, 0);
	وإلا
            put_ptr(s1, dwarf_str_section, 0);
    }
    وإلا
    {
        put_ptr(s1, stab_section, 0);
        put_ptr(s1, stab_section, -1);
        put_ptr(s1, stab_section->link, 0);
    }

    /* skip esym_start/esym_end/elf_str (not loaded) */
    section_ptr_جوڙيو(s, 3 * PTR_سائيز);

    إذا (s1->output_type == TCC_OUTPUT_يادگيري && 0 == s1->dwarf) {
        put_ptr(s1, متن_section, 0);
    } وإلا {
        /* prog_base : local nameless symbol with offset 0 at SHN_ABS */
        put_ptr(s1, عدم, 0);
#إذا defined TCC_هدف_MACHO
        /* adjust for __PAGEZERO */
        إذا (s1->dwarf == 0 && s1->output_type == TCC_OUTPUT_EXE)
            write64le(معلومات_section->معلومات + معلومات_section->معلومات_وٿي - PTR_سائيز,
	              (uint64_t)1 << 32);
#جيڪڏهن_پورو
    }
    n = 3 * PTR_سائيز;
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
    إذا (s1->do_bounds_check) {
        put_ptr(s1, bounds_section, 0);
        n -= PTR_سائيز;
    }
#جيڪڏهن_پورو
    section_ptr_جوڙيو(s, n);
    p = section_ptr_جوڙيو(s, 2 * حجم (صحيح));
    p[0] = s1->rt_انگ_callers;
    p[1] = s1->dwarf;
    // if (s->data_offset - o != 10*PTR_SIZE + 2*sizeof (int)) exit(99);

    إذا (s1->output_type == TCC_OUTPUT_يادگيري) {
        سيٽ_global_sym(s1, __rt_info, s, o);
        أرجع;
    }

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern void __bt_init(),__bt_exit(),__bt_init_dll();"
        "static void *__rt_info[];"
        "__attribute__((constructor)) static void __bt_init_rt(){");
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
    إذا (s1->output_type == TCC_OUTPUT_DLL)
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
        cstr_printf(&cstr, "__bt_init_dll(%d);", s1->do_bounds_check);
#وإلا
        cstr_printf(&cstr, "__bt_init_dll(0);");
#جيڪڏهن_پورو
#جيڪڏهن_پورو
    cstr_printf(&cstr, "__bt_init(__rt_info,%d);}",
        s1->output_type != TCC_OUTPUT_DLL);
    /* In case dlcose is called by application */
    cstr_printf(&cstr,
        "__attribute__((destructor)) static void __bt_exit_rt(){"
        "__bt_exit(__rt_info);}");
    tcc_compile_string_no_debug(s1, cstr.معلومات);
    cstr_free(&cstr);
    سيٽ_local_sym(s1, __rt_info, s, o);
}
#جيڪڏهن_پورو /* def CONFIG_TCC_BACKTRACE */

ساكن فراغ tcc_tcov_جوڙيو_file(TCCState *s1, ثابت حرف *filename)
{
    CString cstr;
    فراغ *ptr;
    حرف wd[1024];

    إذا (tcov_section == عدم)
        أرجع;
    section_ptr_جوڙيو(tcov_section, 1);
    write32le (tcov_section->معلومات, tcov_section->معلومات_وٿي);

    cstr_new (&cstr);
    إذا (filename[0] == '/')
        cstr_printf (&cstr, "%s.tcov", filename);
    وإلا {
        getcwd (wd, حجم(wd));
        cstr_printf (&cstr, "%s/%s.tcov", wd, filename);
    }
    ptr = section_ptr_جوڙيو(tcov_section, cstr.سائيز + 1);
    strcpy((حرف *)ptr, cstr.معلومات);
    unlink((حرف *)ptr);
#جيڪڏهن_وصف_ٿيل _WIN32
    normalize_slashes((حرف *)ptr);
#جيڪڏهن_پورو
    cstr_free (&cstr);

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern char *__tcov_data[];"
        "extern void __store_test_coverage ();"
        "__attribute__((destructor)) static void __tcov_exit() {"
        "__store_test_coverage(__tcov_data);"
        "}");
    tcc_compile_string_no_debug(s1, cstr.معلومات);
    cstr_free(&cstr);
    سيٽ_local_sym(s1, &"___tcov_data"[!s1->leading_underscore], tcov_section, 0);
}

#جيڪڏهن_وصف_ٿيل TCC_هدف_UNIX
/* add libc crt1/crti objects */
ST_FUNC فراغ tccelf_جوڙيو_crtbegin(TCCState *s1)
{
#إذا TARGETOS_OpenBSD
    إذا (s1->output_type != TCC_OUTPUT_DLL)
        tcc_جوڙيو_crt(s1, "crt0.o");
    إذا (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڙيو_crt(s1, "crtbeginS.o");
    وإلا
        tcc_جوڙيو_crt(s1, "crtbegin.o");
#وإلاإذا TARGETOS_FreeBSD || TARGETOS_NetBSD
    إذا (s1->output_type != TCC_OUTPUT_DLL)
#إذا TARGETOS_FreeBSD
        tcc_جوڙيو_crt(s1, "crt1.o");
#وإلا
        tcc_جوڙيو_crt(s1, "crt0.o");
#جيڪڏهن_پورو
    tcc_جوڙيو_crt(s1, "crti.o");
    إذا (s1->static_link)
        tcc_جوڙيو_crt(s1, "crtbeginT.o");
    وإلا إذا (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڙيو_crt(s1, "crtbeginS.o");
    وإلا
        tcc_جوڙيو_crt(s1, "crtbegin.o");
#وإلاإذا TARGETOS_ANDROID
    إذا (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڙيو_crt(s1, "crtbegin_so.o");
    وإلا
        tcc_جوڙيو_crt(s1, "crtbegin_dynamic.o");
#وإلا
    إذا (s1->output_type != TCC_OUTPUT_DLL)
        tcc_جوڙيو_crt(s1, "crt1.o");
    tcc_جوڙيو_crt(s1, "crti.o");
#جيڪڏهن_پورو
}

ST_FUNC فراغ tccelf_جوڙيو_crtend(TCCState *s1)
{
#إذا TARGETOS_OpenBSD
    إذا (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڙيو_crt(s1, "crtendS.o");
    وإلا
        tcc_جوڙيو_crt(s1, "crtend.o");
#وإلاإذا TARGETOS_FreeBSD || TARGETOS_NetBSD
    إذا (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڙيو_crt(s1, "crtendS.o");
    وإلا
        tcc_جوڙيو_crt(s1, "crtend.o");
    tcc_جوڙيو_crt(s1, "crtn.o");
#وإلاإذا TARGETOS_ANDROID
    إذا (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڙيو_crt(s1, "crtend_so.o");
    وإلا
        tcc_جوڙيو_crt(s1, "crtend_android.o");
#وإلا
    tcc_جوڙيو_crt(s1, "crtn.o");
#جيڪڏهن_پورو
}
#جيڪڏهن_پورو /* TCC_TARGET_UNIX */

#جيڪڏهن_وصف_نه_ٿيل TCC_هدف_PE
/* add tcc runtime libraries */
ST_FUNC فراغ tcc_جوڙيو_runtime(TCCState *s1)
{
    s1->filetype = 0;

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
    tcc_جوڙيو_bcheck(s1);
#جيڪڏهن_پورو
    tcc_جوڙيو_pragma_libs(s1);

    /* add libc */
    إذا (!s1->nostdlib) {
        صحيح lpthread = s1->option_pthread;

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
        إذا (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    إذا (s1->output_type == TCC_OUTPUT_يادگيري)
                tcc_جوڙيو_support(s1, "bcheck_run.o");
	    وإلا
                tcc_جوڙيو_support(s1, "bcheck.o");
# إذا !(TARGETOS_OpenBSD || TARGETOS_NetBSD)
            tcc_جوڙيو_library(s1, "dl");
# endif
            lpthread = 1;
        }
#جيڪڏهن_پورو
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BACKTRACE
        إذا (s1->do_backtrace) {
            إذا (s1->output_type & TCC_OUTPUT_EXE)
                tcc_جوڙيو_support(s1, "bt-exe.o");
            إذا (s1->output_type != TCC_OUTPUT_DLL)
                tcc_جوڙيو_support(s1, "bt-log.o");
            tcc_جوڙيو_btstub(s1);
            lpthread = 1;
        }
#جيڪڏهن_پورو
        إذا (lpthread)
            tcc_جوڙيو_library(s1, "pthread");
        tcc_جوڙيو_library(s1, "c");
#جيڪڏهن_وصف_ٿيل TCC_LIBGCC
        إذا (!s1->static_link) {
            إذا (TCC_LIBGCC[0] == '/')
                tcc_جوڙيو_file(s1, TCC_LIBGCC);
            وإلا
                tcc_جوڙيو_dll(s1, TCC_LIBGCC, AFF_PRINT_ERROR);
        }
#جيڪڏهن_پورو
#إذا defined TCC_هدف_ARM && TARGETOS_FreeBSD
        tcc_جوڙيو_library(s1, "gcc_s"); // unwind code
#جيڪڏهن_پورو
        إذا (TCC_LIBTCC1[0]) {
            tcc_جوڙيو_support(s1, TCC_LIBTCC1);
            tcc_جوڙيو_library(s1, "c");
        }
#جيڪڏهن_وصف_نه_ٿيل TCC_هدف_MACHO
        إذا (s1->output_type != TCC_OUTPUT_يادگيري)
            tccelf_جوڙيو_crtend(s1);
#جيڪڏهن_پورو
    }
}
#جيڪڏهن_پورو /* ndef TCC_TARGET_PE */

/* set _etext/_edata/_end  f=0:set  f=1:when_needed  f=2,3:just_update */
ساكن فراغ سيٽ_linker_sym(TCCState *s1, ثابت حرف *name, Section *sec, صحيح f)
{
    صحيح sym_اشاريو, esym_اشاريو, defined;
    ElfW(Sym) *sym, *esym;
    sym_اشاريو = ڳوليو_elf_sym(symtab_section, name);
    sym = (ElfW(Sym) *)symtab_section->معلومات + sym_اشاريو;
    esym_اشاريو = ڳوليو_elf_sym(s1->dynsymtab_section, name);
    esym = (ElfW(Sym) *)s1->dynsymtab_section->معلومات + esym_اشاريو;
    defined = sym->st_shndx != SHN_UNDEF
        || (esym->st_shndx != SHN_UNDEF && esym->st_سائيز);
    بدل (f) {
    حالة 1: /* old symbols w/o '_' */
        إذا (!(sym_اشاريو || esym_اشاريو) || defined)
            اكسر;
    حالة 0:
        إذا (defined) {
            tcc_warning("linker symbol '%s' already defined", name);
            اكسر;
        }
        sym_اشاريو = سيٽ_global_sym(s1, name, sec, -1);
        get_sym_attr(s1, sym_اشاريو, 1)->linker_sym = 1;
        اكسر;
    افتراضي: /* update (bss only) */
        إذا (get_sym_attr(s1, sym_اشاريو, 0)->linker_sym)
            sym->st_قدر = sec->معلومات_وٿي;
    }
#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
    إذا (name[0] == '_')
        سيٽ_linker_sym(s1, name + 1, sec, f + 1);
#جيڪڏهن_پورو
}

/* add various standard linker symbols (must be done after the
   sections are filled (for example after allocating common
   symbols)) */
ساكن فراغ tcc_جوڙيو_linker_symbols(TCCState *s1)
{
    حرف buf[1024];
    صحيح i;
    Section *s;

    سيٽ_linker_sym(s1, "_etext", متن_section, 0);
    سيٽ_linker_sym(s1, "_edata", معلومات_section, 0);
    سيٽ_linker_sym(s1, "_end", bss_section, 0);
#إذا TARGETOS_OpenBSD
    سيٽ_global_sym(s1, "__executable_start", عدم, ELF_شروعات_ADDR);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل TCC_هدف_RISCV64
    /* XXX should be .sdata+0x800, not .data+0x800 */
    سيٽ_global_sym(s1, "__global_pointer$", معلومات_section, 0x800);
#جيڪڏهن_پورو
    /* horrible new standard ldscript defines */
    جوڙيو_init_array_مقرر_ڪري(s1, ".preinit_array");
    جوڙيو_init_array_مقرر_ڪري(s1, ".init_array");
    جوڙيو_init_array_مقرر_ڪري(s1, ".fini_array");
    /* add start and stop symbols for sections whose name can be
       expressed in C */
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        إذا ((s->sh_flags & SHF_ALLOC)
            && (s->sh_type == SHT_PROGBITS || s->sh_type == SHT_NOBITS
                || s->sh_type == SHT_STRTAB)) {
            /* check if section name can be expressed in C */
            ثابت حرف *p0, *p;
            p0 = s->name;
            إذا (*p0 == '.')
                ++p0;
            p = p0;
            لكل(;;) {
                صحيح c = *p;
                إذا (!c)
                    اكسر;
                إذا (!isid(c) && !isnum(c))
                    اذهب ايندڙ_sec;
                p++;
            }
            snprintf(buf, حجم(buf), "__start_%s", p0);
            سيٽ_global_sym(s1, buf, s, 0);
            snprintf(buf, حجم(buf), "__stop_%s", p0);
            سيٽ_global_sym(s1, buf, s, -1);
        }
    ايندڙ_sec: ;
    }
}

ST_FUNC فراغ resolve_common_syms(TCCState *s1)
{
    ElfW(Sym) *sym;

    /* Allocate common symbols in BSS.  */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        إذا (sym->st_shndx == SHN_COMMON && sym->st_سائيز) {
            /* symbol alignment is in st_value for SHN_COMMONs */
	    sym->st_قدر = section_جوڙيو(bss_section, sym->st_سائيز,
					sym->st_قدر);
            sym->st_shndx = bss_section->sh_انگ;
        }
    }

    /* Now assign linker provided symbols their value.  */
    إذا (s1->output_type != TCC_OUTPUT_DLL)
        tcc_جوڙيو_linker_symbols(s1);
}

#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
ST_FUNC فراغ fill_got_داخلا(TCCState *s1, ElfW_Rel *rel)
{
    صحيح sym_اشاريو = ELFW(R_SYM) (rel->r_info);
    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->معلومات)[sym_اشاريو];
    بنية sym_attr *attr = get_sym_attr(s1, sym_اشاريو, 0);
    بنانشان وٿي = attr->got_وٿي;

    إذا (0 == وٿي)
        أرجع;
    section_reserve(s1->got, وٿي + PTR_سائيز);
#إذا PTR_سائيز == 8
    write64le(s1->got->معلومات + وٿي, sym->st_قدر);
#وإلا
    write32le(s1->got->معلومات + وٿي, sym->st_قدر);
#جيڪڏهن_پورو
}

/* Perform relocation to GOT or PLT entries */
ST_FUNC فراغ fill_got(TCCState *s1)
{
    Section *s;
    ElfW_Rel *rel;
    صحيح i;

    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        إذا (s->sh_type != SHT_RELX)
            استمر;
        /* no need to handle got relocations */
        إذا (s->link != symtab_section)
            استمر;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            بدل (ELFW(R_TYPE) (rel->r_info)) {
                حالة R_X86_64_GOT32:
                حالة R_X86_64_GOTPCREL:
		حالة R_X86_64_GOTPCRELX:
		حالة R_X86_64_REX_GOTPCRELX:
                حالة R_X86_64_PLT32:
                    fill_got_داخلا(s1, rel);
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
    إذا (!s1->got->reloc)
        أرجع;
    for_each_elem(s1->got->reloc, 0, rel, ElfW_Rel) {
	إذا (ELFW(R_TYPE)(rel->r_info) == R_RELATIVE) {
	    صحيح sym_اشاريو = ELFW(R_SYM) (rel->r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->معلومات)[sym_اشاريو];
	    بنية sym_attr *attr = get_sym_attr(s1, sym_اشاريو, 0);
	    بنانشان وٿي = attr->got_وٿي;
	    إذا (وٿي != rel->r_وٿي - s1->got->sh_addr)
	        tcc_error_noabort("fill_local_got_entries: huh?");
	    rel->r_info = ELFW(R_INFO)(0, R_RELATIVE);
#إذا SHT_RELX == SHT_RELA
	    rel->r_addend = sym->st_قدر;
#وإلا
	    /* All our REL architectures also happen to be 32bit LE.  */
	    write32le(s1->got->معلومات + وٿي, sym->st_قدر);
#جيڪڏهن_پورو
	}
    }
}

/* Bind symbols of executable: resolve undefined symbols from exported symbols
   in shared libraries */
ساكن فراغ bind_exe_dynsyms(TCCState *s1, صحيح is_PIE)
{
    ثابت حرف *name;
    صحيح sym_اشاريو, اشاريو;
    ElfW(Sym) *sym, *esym;
    صحيح type;

    /* Resolve undefined symbols from dynamic symbols. When there is a match:
       - if STT_FUNC or STT_GNU_IFUNC symbol -> add it in PLT
       - if STT_OBJECT symbol -> add it in .bss section with suitable reloc */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        إذا (sym->st_shndx == SHN_UNDEF
            /* bss symbols may be initialized in the shared library */
            || sym->st_shndx == SHN_COMMON
            || sym->st_shndx == bss_section->sh_انگ) {
            name = (حرف *) symtab_section->link->معلومات + sym->st_name;
            sym_اشاريو = ڳوليو_elf_sym(s1->dynsymtab_section, name);
            esym = &((ElfW(Sym) *)s1->dynsymtab_section->معلومات)[sym_اشاريو];
            إذا (sym_اشاريو && esym->st_shndx != SHN_UNDEF) {
                إذا (is_PIE)
                    استمر;
                type = ELFW(ST_TYPE)(esym->st_info);
                إذا ((type == STT_FUNC) || (type == STT_GNU_IFUNC)) {
                    /* Indirect functions shall have STT_FUNC type in executable
                     * dynsym section. Indeed, a dlsym call following a lazy
                     * resolution would pick the symbol value from the
                     * executable dynsym entry which would contain the address
                     * of the function wanted by the caller of dlsym instead of
                     * the address of the function that would return that
                     * address */
                    صحيح dynindex
		      = put_elf_sym(s1->dynsym, 0, esym->st_سائيز,
				    ELFW(ST_INFO)(STB_GLOBAL,STT_FUNC), 0, 0,
				    name);
		    صحيح اشاريو = sym - (ElfW(Sym) *) symtab_section->معلومات;
		    get_sym_attr(s1, اشاريو, 1)->dyn_اشاريو = dynindex;
                } وإلا إذا (type == STT_OBJECT) {
                    بنانشان ڊگهو وٿي;
                    ElfW(Sym) *dynsym;
                    إذا (sym->st_shndx == bss_section->sh_انگ) {
                        وٿي = sym->st_قدر;
                    } وإلا {
                        وٿي = bss_section->معلومات_وٿي;
                        /* XXX: which alignment ? */
                        وٿي = (وٿي + 16 - 1) & -16;
                        bss_section->معلومات_وٿي = وٿي + esym->st_سائيز;
                    }
                    سيٽ_elf_sym (s1->symtab, وٿي, esym->st_سائيز,
                                 esym->st_info, 0, bss_section->sh_انگ, name);
                    اشاريو = put_elf_sym(s1->dynsym, وٿي, esym->st_سائيز,
                                        esym->st_info, 0, bss_section->sh_انگ,
                                        name);
                    /* Ensure R_COPY works for weak symbol aliases */
                    إذا (ELFW(ST_BIND)(esym->st_info) == STB_WEAK) {
                        for_each_elem(s1->dynsymtab_section, 1, dynsym, ElfW(Sym)) {
                            إذا ((dynsym->st_قدر == esym->st_قدر)
                                && (ELFW(ST_BIND)(dynsym->st_info) == STB_GLOBAL)) {
                                حرف *dynname = (حرف *) s1->dynsymtab_section->link->معلومات
                                                + dynsym->st_name;
                                put_elf_sym(s1->dynsym, وٿي, dynsym->st_سائيز,
                                            dynsym->st_info, 0,
                                            bss_section->sh_انگ, dynname);
                                اكسر;
                            }
                        }
                    }
                    put_elf_reloc(s1->dynsym, bss_section,
                                  وٿي, R_COPY, اشاريو);
                }
            } وإلا إذا (sym->st_shndx == SHN_UNDEF) {
                /* STB_WEAK undefined symbols are accepted */
                /* XXX: _fp_hw seems to be part of the ABI, so we ignore it */
                إذا (ELFW(ST_BIND)(sym->st_info) == STB_WEAK ||
                    !strcmp(name, "_fp_hw")) {
                } وإلا {
                    tcc_error_noabort("unresolved reference to '%s'", name);
                }
            }
        }
    }
    /* update _end symbol with new bss length */
    سيٽ_linker_sym(s1, "_end", bss_section, 2);
}

/* Bind symbols of libraries: export all non local symbols of executable that
   are referenced by shared libraries. The reason is that the dynamic loader
   search symbol first in executable and then in libraries. Therefore a
   reference to a symbol already defined by a library can still be resolved by
   a symbol in the executable.   With -rdynamic, export all defined symbols */
ساكن فراغ bind_libs_dynsyms(TCCState *s1)
{
    ثابت حرف *name;
    صحيح dynsym_اشاريو;
    ElfW(Sym) *sym, *esym;

    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        name = (حرف *)symtab_section->link->معلومات + sym->st_name;
        dynsym_اشاريو = ڳوليو_elf_sym(s1->dynsymtab_section, name);
        إذا (sym->st_shndx != SHN_UNDEF) {
            إذا (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL
                && (dynsym_اشاريو || s1->rdynamic))
                سيٽ_elf_sym(s1->dynsym, sym->st_قدر, sym->st_سائيز,
                            sym->st_info, 0, sym->st_shndx, name);
        } وإلا إذا (dynsym_اشاريو) {
            esym = (ElfW(Sym) *)s1->dynsymtab_section->معلومات + dynsym_اشاريو;
            إذا (esym->st_shndx == SHN_UNDEF) {
                /* weak symbols can stay undefined */
                إذا (ELFW(ST_BIND)(esym->st_info) != STB_WEAK)
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
    صحيح dynindex, اشاريو;
    ثابت حرف *name;
    ElfW(Sym) *sym;
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        إذا (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
	    name = (حرف *) symtab_section->link->معلومات + sym->st_name;
	    dynindex = سيٽ_elf_sym(s1->dynsym, sym->st_قدر, sym->st_سائيز,
				   sym->st_info, 0, sym->st_shndx, name);
	    اشاريو = sym - (ElfW(Sym) *) symtab_section->معلومات;
            get_sym_attr(s1, اشاريو, 1)->dyn_اشاريو = dynindex;
        }
    }
}

/* decide if an unallocated section should be output. */
ساكن صحيح سيٽ_sec_sizes(TCCState *s1)
{
    صحيح i;
    Section *s;
    صحيح textrel = 0;
    صحيح file_type = s1->output_type;

    /* Allocate strings for section names */
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        إذا (s->sh_type == SHT_RELX && !(s->sh_flags & SHF_ALLOC)) {
            /* when generating a DLL, we include relocations but
               we may patch them */
            إذا ((file_type & TCC_OUTPUT_DYN)
                && (s1->sections[s->sh_info]->sh_flags & SHF_ALLOC)) {
                صحيح ڳڻپ_2 = prepare_dynamic_rel(s1, s);
                إذا (ڳڻپ_2) {
                    /* allocate the section */
                    s->sh_flags |= SHF_ALLOC;
                    s->sh_سائيز = ڳڻپ_2 * حجم(ElfW_Rel);
                    إذا (s1->sections[s->sh_info]->sh_flags & SHF_EXECINSTR)
                        textrel += ڳڻپ_2;
                }
            }
        } وإلا إذا ((s->sh_flags & SHF_ALLOC)
#جيڪڏهن_وصف_ٿيل TCC_هدف_ARM
                   || s->sh_type == SHT_ARM_خاصيتون
#جيڪڏهن_پورو
                   || s1->do_debug) {
            s->sh_سائيز = s->معلومات_وٿي;
        }
    }
    أرجع textrel;
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
        بنانشان ڊگهو معلومات_وٿي;
        addr_t rel_addr;
        addr_t rel_سائيز;
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
ساكن صحيح ترتيب_ڏيو_sections(TCCState *s1, صحيح *sec_ترتيب, بنية dyn_inf *d)
{
    Section *s;
    صحيح i, j, k, f, f0, n;
    صحيح nb_sections = s1->nb_sections;
    صحيح *sec_cls = sec_ترتيب + nb_sections;
    صحيح tls_align = 0; /* need common alignment for all tls sections */

    لكل (i = 1; i < nb_sections; i++) {
        s = s1->sections[i];
        إذا (0 == s->sh_name) {
            j = 0x900; /* no sh_name: won't go to file */
        } وإلا إذا (s->sh_flags & SHF_ALLOC) {
            j = 0x100;
            إذا ((s->sh_flags & (SHF_WRITE|SHF_TLS)) == SHF_WRITE)
                j = 0x200;
        } وإلا {
            j = 0x700;
        }
        إذا (j >= 0x700 && s1->output_format != TCC_OUTPUT_FORMAT_ELF)
            s->sh_سائيز = 0, j = 0x900;

        إذا (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM) {
            k = 0x10;
        } وإلا إذا (s->sh_type == SHT_STRTAB && strcmp(s->name, ".stabstr")) {
            k = 0x11;
            إذا (i == nb_sections - 1) /* ".shstrtab" assumed to stay last */
                k = 0xff;
        } وإلا إذا (s->sh_type == SHT_HASH || s->sh_type == SHT_GNU_HASH) {
            k = 0x12;
        } وإلا إذا (s->sh_type == SHT_GNU_verdef
                  || s->sh_type == SHT_GNU_verneed
                  || s->sh_type == SHT_GNU_versym) {
            k = 0x13;
        } وإلا إذا (s->sh_type == SHT_RELX) {
            k = 0x20;
            إذا (s1->plt && s == s1->plt->reloc)
                k = 0x21;
        } وإلا إذا (s->sh_flags & SHF_EXECINSTR) {
            k = 0x60;
        /* RELRO sections --> */
        } وإلا إذا (s->sh_flags & SHF_TLS) {
            إذا (s->sh_addralign > tls_align)
                tls_align = s->sh_addralign;
            k = 0x40 + (s->sh_type == SHT_NOBITS);
        } وإلا إذا (s->sh_type == SHT_PREINIT_ARRAY) {
            k = 0x42;
        } وإلا إذا (s->sh_type == SHT_INIT_ARRAY) {
            k = 0x43;
        } وإلا إذا (s->sh_type == SHT_FINI_ARRAY) {
            k = 0x44;
        } وإلا إذا (s->sh_type == SHT_DYNAMIC) {
            k = 0x48;
        } وإلا إذا (s == s1->got) {
            k = 0x49; /* .got as RELRO needs BIND_NOW in DT_FLAGS */
        } وإلا إذا (s->reloc && (s->reloc->sh_flags & SHF_ALLOC) && j == 0x100) {
            k = 0x45; /* +1 for data.ro */
        /* <-- */
        } وإلا إذا (s->sh_type == SHT_NOTE) {
            k = 0x08, d->notes = 1;
        } وإلا إذا (s->sh_type == SHT_NOBITS) {
            k = 0x70; /* bss */
        } وإلا إذا (s == d->interp) {
            k = 0x00;
        } وإلا {
            k = 0x50; /*معلومات*/
        }
        k += j;
        /* make our standard sections come last to have _etext/_edata correct values */
        إذا (s->sh_انگ <= bss_section->sh_انگ)
            ++k;
        /* make RELRO section writable */
        إذا ((k & 0xfff0) == 0x140)
            k += 0x100, s->sh_flags |= SHF_WRITE;
        /* sort by insert */
        لكل (n = i; n > 1 && k < (f = sec_cls[n - 1]); --n)
            sec_cls[n] = f, sec_ترتيب[n] = sec_ترتيب[n - 1];
        sec_cls[n] = k, sec_ترتيب[n] = i;
    }
    sec_ترتيب[0] = 0;
    d->shnum = 1;

#وصف_ڪريو SHFX_NEWPH (1 << 4)
#وصف_ڪريو SHFX_RELRO (1 << 5)

    /* count PT_LOAD headers needed */
    n = f0 = 0;
    لكل (i = 1; i < nb_sections; i++) {
        s = s1->sections[sec_ترتيب[i]];
        k = sec_cls[i];
        f = 0;
        إذا (k < 0x900)
            ++d->shnum;
        إذا (k < 0x700) {
            f = s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR);
#إذا TARGETOS_NetBSD || TARGETOS_FreeBSD
	    /* NetBSD only supports 2 PT_LOAD sections.
	       See: https://blog.netbsd.org/tnf/entry/the_first_report_on_lld */
	    إذا ((f & SHF_WRITE) == 0)
                f |= SHF_EXECINSTR;
            k = 0; /* no relro */
#جيڪڏهن_پورو
            إذا ((k & 0xfff0) == 0x240) /* RELRO sections */
                d->relro = 1, f |= SHFX_RELRO;
            /* start new header when flags changed, but avoid zero memsz */
            إذا (f != f0 && s->sh_سائيز)
                f0 = f, ++n, f |= SHFX_NEWPH;
            إذا ((s->sh_flags & SHF_TLS) && s->sh_سائيز) {
                s->sh_addralign = tls_align;
                d->tls = 1, f |= SHF_TLS;
            }
        }
        sec_cls[i] = f;
        //printf("ph %d sec %02d : %3X %3X  %8.2X  %04X  %s\n", (f>0) * n, i, f, k, s->sh_type, (int)s->sh_size, s->name);
    }
    أرجع n;
}

ساكن ElfW(Phdr) *fill_phdr(ElfW(Phdr) *ph, صحيح type, Section *s)
{
    ph->p_type = type;
    ph->p_flags = PF_R;
    إذا (s) {
        إذا (s->sh_flags & SHF_WRITE)
            ph->p_flags |= PF_W;
        ph->p_وٿي = s->sh_وٿي;
        ph->p_vaddr = s->sh_addr;
        ph->p_filesz = s->sh_سائيز;
        ph->p_align = s->sh_addralign;
    }
    ph->p_paddr = ph->p_vaddr;
    ph->p_memsz = ph->p_filesz;
    أرجع ph;
}

ساكن ElfW(Phdr) *update_phdr(ElfW(Phdr) *ph, صحيح type, Section *s, addr_t addr, صحيح file_وٿي)
{
    إذا (ph->p_type == 0) {
        fill_phdr(ph, type, s);
    }
    ph->p_filesz = file_وٿي - ph->p_وٿي;
    ph->p_memsz = addr - ph->p_vaddr;
    أرجع ph;
}

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
ساكن صحيح layout_sections(TCCState *s1, صحيح *sec_ترتيب, بنية dyn_inf *d)
{
    Section *s;
    addr_t addr, tmp, align, s_align, بنياد;
    ElfW(Phdr) *ph = عدم, *ph2;
    صحيح i, f, n, phnum, phfill;
    صحيح file_وٿي;

    /* compute number of program headers */
    phnum = ترتيب_ڏيو_sections(s1, sec_ترتيب, d);
    phfill = 0; /* set to 1 to have dll's with a PT_PHDR */
    إذا (d->interp)
        phfill = 2;
    phnum += phfill;
    إذا (d->dynamic)
        d->dyna = phnum++;
    إذا (d->notes)
        d->notes = phnum++;
    إذا (d->tls)
        d->tls = phnum++;
    إذا (eh_چوکٺو_hdr_section)
        d->ehfr = phnum++;
    إذا (d->relro)
        d->relro = phnum++;
    d->phnum = phnum;
    d->phdr = tcc_mallocz(phnum * حجم(ElfW(Phdr)));

    file_وٿي = 0;
    إذا (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
        file_وٿي = (حجم(ElfW(Ehdr)) + phnum * حجم(ElfW(Phdr)) + 3) & -4;
        file_وٿي += d->shnum * حجم (ElfW(Shdr));
    }

    s_align = ELF_صفحو_سائيز;
    إذا (s1->section_align)
        s_align = s1->section_align;

    addr = ELF_شروعات_ADDR;
    إذا (s1->output_type & TCC_OUTPUT_DYN)
        addr = 0;

    إذا (s1->has_متن_addr) {
        addr = s1->متن_addr;
        إذا (0) {
            صحيح a_وٿي, p_وٿي;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_وٿي = (صحيح) (addr & (s_align - 1));
            p_وٿي = file_وٿي & (s_align - 1);
            إذا (a_وٿي < p_وٿي)
                a_وٿي += s_align;
            file_وٿي += (a_وٿي - p_وٿي);
        }
    }
    بنياد = addr;
    /* compute address after headers */
    addr += file_وٿي;

    n = 0;
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_ترتيب[i]];
        f = sec_ترتيب[i + s1->nb_sections];
        align = s->sh_addralign - 1;

        إذا (f == 0) { /* no alloc */
            file_وٿي = (file_وٿي + align) & ~align;
            s->sh_وٿي = file_وٿي;
            إذا (s->sh_type != SHT_NOBITS)
                file_وٿي += s->sh_سائيز;
            استمر;
        }

        إذا ((f & SHFX_NEWPH) && n) {
            /* different rwx section flags */
            إذا (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
                /* if in the middle of a page, w e duplicate the page in
                   memory so that one copy is RX and the other is RW */
                إذا ((addr & (s_align - 1)) != 0)
                    addr += s_align;
            } وإلا {
                align = s_align - 1;
            }
        }

        tmp = addr;
        addr = (addr + align) & ~align;
        file_وٿي += (صحيح)(addr - tmp);
        s->sh_وٿي = file_وٿي;
        s->sh_addr = addr;

        //printf("%d : %08x %08x %04x %03x %s %d\n", n, (int)file_offset, (int)addr, (int)s->sh_size, s->sh_type, s->name, align + 1);
        addr += s->sh_سائيز;
        إذا (s->sh_type != SHT_NOBITS)
            file_وٿي += s->sh_سائيز;

        إذا (f & SHFX_NEWPH) {
            /* set new program header */
            ph = &d->phdr[phfill + n];
            fill_phdr(ph, PT_ڀريو, s);
            ph->p_align = s_align;
            إذا (f & SHF_EXECINSTR)
                ph->p_flags |= PF_X;
            إذا (n == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_وٿي = 0;
                ph->p_paddr = ph->p_vaddr = بنياد;
            }
            ++n;
        }

        إذا (ph)
            update_phdr(ph, 0, 0, addr, file_وٿي);

        إذا (f & SHFX_RELRO) {
            ph2 = update_phdr(&d->phdr[d->relro], PT_GNU_RELRO, s, addr, file_وٿي);
            ph2->p_align = 1;
        }
        إذا (f & SHF_TLS) {
            ph2 = update_phdr(&d->phdr[d->tls], PT_TLS, s, addr, file_وٿي);
            إذا (s->sh_type == SHT_NOBITS)
                addr -= s->sh_سائيز;
            /* for xxx-link.c:relocate() */
            s1->tls_شروعات = ph2->p_vaddr;
            s1->tls_پڇاڙي = s1->tls_شروعات + ph2->p_memsz + (-ph2->p_memsz & (ph2->p_align - 1));
        }
        إذا (s->sh_type == SHT_NOTE) {
            update_phdr(&d->phdr[d->notes], PT_NOTE, s, addr, file_وٿي);
        }
    }

    /* Fill other headers */
    إذا (d->dyna)
        fill_phdr(&d->phdr[d->dyna], PT_DYNAMIC, d->dynamic);
    إذا (d->ehfr)
        fill_phdr(&d->phdr[d->ehfr], PT_GNU_EH_چوکٺو, eh_چوکٺو_hdr_section);
    إذا (d->interp)
        fill_phdr(&d->phdr[1], PT_INTERP, d->interp);
    إذا (phfill) {
        ph = &d->phdr[0];
        ph->p_وٿي = حجم(ElfW(Ehdr));
        ph->p_vaddr = بنياد + ph->p_وٿي;
        ph->p_filesz = phnum * حجم(ElfW(Phdr));
        ph->p_align = 4;
        fill_phdr(ph, PT_PHDR, عدم);
    }
    أرجع 0;
}

/* put dynamic tag */
ساكن فراغ put_dt(Section *dynamic, صحيح dt, addr_t val)
{
    ElfW(Dyn) *dyn;
    dyn = section_ptr_جوڙيو(dynamic, حجم(ElfW(Dyn)));
    dyn->d_ٽيگ = dt;
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
    put_dt(dynamic, DT_STRSZ, dyninf->dynstr->معلومات_وٿي);
    put_dt(dynamic, DT_SYMENT, حجم(ElfW(Sym)));
#إذا PTR_سائيز == 8
    put_dt(dynamic, DT_RELA, dyninf->rel_addr);
    put_dt(dynamic, DT_RELASZ, dyninf->rel_سائيز);
    put_dt(dynamic, DT_RELAENT, حجم(ElfW_Rel));
    إذا (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->معلومات_وٿي);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_RELA);
    }
    put_dt(dynamic, DT_RELACOUNT, 0);
#وإلا
    put_dt(dynamic, DT_REL, dyninf->rel_addr);
    put_dt(dynamic, DT_RELSZ, dyninf->rel_سائيز);
    put_dt(dynamic, DT_RELENT, حجم(ElfW_Rel));
    إذا (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->معلومات_وٿي);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_REL);
    }
    put_dt(dynamic, DT_RELCOUNT, 0);
#جيڪڏهن_پورو
    إذا (versym_section && verneed_section) {
	/* The dynamic linker can not handle VERSYM without VERNEED */
        put_dt(dynamic, DT_VERSYM, versym_section->sh_addr);
        put_dt(dynamic, DT_VERNEED, verneed_section->sh_addr);
        put_dt(dynamic, DT_VERNEEDNUM, dt_verneednum);
    }
    s = have_section(s1, ".preinit_array");
    إذا (s && s->معلومات_وٿي) {
        put_dt(dynamic, DT_PREINIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_PREINIT_ARRAYSZ, s->معلومات_وٿي);
    }
    s = have_section(s1, ".init_array");
    إذا (s && s->معلومات_وٿي) {
        put_dt(dynamic, DT_INIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_INIT_ARRAYSZ, s->معلومات_وٿي);
    }
    s = have_section(s1, ".fini_array");
    إذا (s && s->معلومات_وٿي) {
        put_dt(dynamic, DT_FINI_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_FINI_ARRAYSZ, s->معلومات_وٿي);
    }
    s = have_section(s1, ".init");
    إذا (s && s->معلومات_وٿي) {
        put_dt(dynamic, DT_INIT, s->sh_addr);
    }
    s = have_section(s1, ".fini");
    إذا (s && s->معلومات_وٿي) {
        put_dt(dynamic, DT_FINI, s->sh_addr);
    }
    إذا (s1->do_debug)
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
    بنانشان ڊگهو file_وٿي = 0;
    Section *s;
    Section *relocplt = s1->plt ? s1->plt->reloc : عدم;

    /* dynamic relocation table information, for .dynamic section */
    dyninf->rel_addr = dyninf->rel_سائيز = 0;

    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
	إذا (s->sh_type == SHT_RELX && s != relocplt) {
	    إذا (dyninf->rel_سائيز == 0) {
		dyninf->rel_addr = s->sh_addr;
		file_وٿي = s->sh_وٿي;
	    }
	    وإلا {
		s->sh_addr = dyninf->rel_addr + dyninf->rel_سائيز;
		s->sh_وٿي = file_وٿي + dyninf->rel_سائيز;
	    }
	    dyninf->rel_سائيز += s->sh_سائيز;
	}
    }
}
#جيڪڏهن_پورو /* ndef ELF_OBJ_ONLY */

/* Create an ELF file on disk.
   This function handle ELF specific layout requirements */
ساكن صحيح tcc_output_elf(TCCState *s1, FILE *f, صحيح phnum, ElfW(Phdr) *phdr)
{
    صحيح i, shnum, وٿي, سائيز, file_type;
    Section *s;
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) shdr, *sh;

    file_type = s1->output_type;
    shnum = s1->nb_sections;

    memset(&ehdr, 0, حجم(ehdr));
    إذا (phnum > 0) {
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

#إذا TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    ehdr.e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
#وإلاإذا TARGETOS_OpenBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_OPENBSD;
#وإلاإذا TARGETOS_NetBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_NETBSD;
#وإلاإذا defined TCC_هدف_ARM && defined TCC_ARM_EABI
    ehdr.e_flags = EF_ARM_EABI_VER5;
    ehdr.e_flags |= s1->float_abi == ARM_HARD_FLOAT
        ? EF_ARM_VFP_FLOAT : EF_ARM_SOFT_FLOAT;
#وإلاإذا defined TCC_هدف_ARM
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#وإلاإذا defined TCC_هدف_RISCV64
    /* XXX should be configurable */
    ehdr.e_flags = EF_RISCV_FLOAT_ABI_DOUBLE;
#جيڪڏهن_پورو

    إذا (file_type == TCC_OUTPUT_OBJ) {
        ehdr.e_type = ET_REL;
    } وإلا {
        إذا (file_type & TCC_OUTPUT_DYN)
            ehdr.e_type = ET_DYN;
        وإلا
            ehdr.e_type = ET_EXEC;
        إذا (s1->elf_entryname)
            ehdr.e_داخلا = get_sym_addr(s1, s1->elf_entryname, 1, 0);
        وإلا
            ehdr.e_داخلا = get_sym_addr(s1, "_start", !!(file_type & TCC_OUTPUT_EXE), 0);
        إذا (ehdr.e_داخلا == (addr_t)-1)
            ehdr.e_داخلا = متن_section->sh_addr;
        إذا (s1->nb_errors)
            أرجع -1;
    }

    ترتيب_ڏيو_syms(s1, s1->symtab);

    ehdr.e_machine = EM_TCC_هدف;
    ehdr.e_نسخو = EV_CURRENT;
    ehdr.e_shoff = (حجم(ElfW(Ehdr)) + phnum * حجم(ElfW(Phdr)) + 3) & -4;
    ehdr.e_ehsize = حجم(ElfW(Ehdr));
    ehdr.e_shentsize = حجم(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    وٿي = fwrite(&ehdr, 1, حجم(ElfW(Ehdr)), f);
    إذا (phdr)
        وٿي += fwrite(phdr, 1, phnum * حجم(ElfW(Phdr)), f);

    /* output section headers */
    طالما (وٿي < ehdr.e_shoff) {
        fputc(0, f);
        وٿي++;
    }

    لكل(i = 0; i < shnum; i++) {
        sh = &shdr;
        memset(sh, 0, حجم(ElfW(Shdr)));
        إذا (i) {
            s = s1->sections[i];
            sh->sh_name = s->sh_name;
            sh->sh_type = s->sh_type;
            sh->sh_flags = s->sh_flags;
            sh->sh_entsize = s->sh_entsize;
            sh->sh_info = s->sh_info;
            إذا (s->link)
                sh->sh_link = s->link->sh_انگ;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_وٿي = s->sh_وٿي;
            sh->sh_سائيز = s->sh_سائيز;
        }
        وٿي += fwrite(sh, 1, حجم(ElfW(Shdr)), f);
    }

    /* output sections */
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        إذا (s->sh_type != SHT_NOBITS) {
            طالما (وٿي < s->sh_وٿي) {
                fputc(0, f);
                وٿي++;
            }
            سائيز = s->sh_سائيز;
            إذا (سائيز)
                وٿي += fwrite(s->معلومات, 1, سائيز, f);
        }
    }
    أرجع 0;
}

ساكن صحيح tcc_output_ٻٽو(TCCState *s1, FILE *f)
{
    Section *s;
    صحيح i, وٿي, سائيز;

    وٿي = 0;
    لكل(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[i];
        إذا (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            طالما (وٿي < s->sh_وٿي) {
                fputc(0, f);
                وٿي++;
            }
            سائيز = s->sh_سائيز;
            fwrite(s->معلومات, 1, سائيز, f);
            وٿي += سائيز;
        }
    }
    أرجع 0;
}

/* Write an elf, coff or "binary" file */
ساكن صحيح tcc_write_elf_file(TCCState *s1, ثابت حرف *filename, صحيح phnum,
                              ElfW(Phdr) *phdr)
{
    صحيح fd, گهڻائي, file_type, ret;
    FILE *f;

    file_type = s1->output_type;
    إذا (file_type == TCC_OUTPUT_OBJ)
        گهڻائي = 0666;
    وإلا
        گهڻائي = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_ٻٽو_2, گهڻائي);
    إذا (fd < 0 || (f = fdopen(fd, "wb")) == عدم)
        أرجع tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
    إذا (s1->verbose)
        لکو("<- %s\n", filename);
#جيڪڏهن_وصف_ٿيل TCC_هدف_COFF
    إذا (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    وإلا
#جيڪڏهن_پورو
    إذا (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        ret = tcc_output_elf(s1, f, phnum, phdr);
    وإلا
        ret = tcc_output_ٻٽو(s1, f);
    fclose(f);

    أرجع ret;
}

#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
/* order sections according to sec_order, remove sections
   that we aren't going to output.  */
ساكن فراغ reorder_sections(TCCState *s1, صحيح *sec_ترتيب)
{
    صحيح i, nnew, k, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    backmap = tcc_malloc(s1->nb_sections * حجم(backmap[0]));
    لكل (i = 0, nnew = 0, snew = عدم; i < s1->nb_sections; i++) {
	k = sec_ترتيب ? sec_ترتيب[i] : i;
	s = s1->sections[k];
	إذا (!i || s->sh_name) {
	    backmap[k] = nnew;
            dynarray_جوڙيو(&snew, &nnew, s);
	} وإلا {
	    backmap[k] = 0;
            /* just remember to free them later */
	    dynarray_جوڙيو(&s1->priv_sections, &s1->nb_priv_sections, s);
	}
    }
    لكل (i = 1; i < nnew; i++) {
	s = snew[i];
        s->sh_انگ = i;
        إذا (s->sh_type == SHT_RELX)
            s->sh_info = backmap[s->sh_info];
        وإلا إذا (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM)
            for_each_elem(s, 1, sym, ElfW(Sym))
                إذا (sym->st_shndx < s1->nb_sections)
                    sym->st_shndx = backmap[sym->st_shndx];
    }
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}

#جيڪڏهن_وصف_ٿيل TCC_هدف_ARM
ساكن فراغ create_arm_attribute_section(TCCState *s1)
{
   // Needed for DLL support.
    ساكن ثابت بنانشان حرف arm_attr[] = {
        0x41,                            // 'A'
        0x2c, 0x00, 0x00, 0x00,          // size 0x2c
        'a', 'e', 'a', 'b', 'i', 0x00,   // "aeabi"
        0x01, 0x22, 0x00, 0x00, 0x00,    // 'File Attributes', size 0x22
        0x05, 0x36, 0x00,                // 'CPU_name', "6"
#إذا CONFIG_TCC_CPUVER >= 7
        0x06, 0x0a,                      // 'CPU_arch', 'v7'
#وإلا
        0x06, 0x06,                      // 'CPU_arch', 'v6'
#جيڪڏهن_پورو
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
    Section *attr = new_section(s1, ".ARM.attributes", SHT_ARM_خاصيتون, 0);
    بنانشان حرف *ptr = section_ptr_جوڙيو(attr, حجم(arm_attr));
    attr->sh_addralign = 1;
    يادگيري_نقل(ptr, arm_attr, حجم(arm_attr));
    إذا (s1->float_abi != ARM_HARD_FLOAT) {
        ptr[26] = 0x00; // 'FP_arch', 'No'
        ptr[41] = 0x1e; // 'ABI_optimization_goals'
        ptr[42] = 0x06; // 'Aggressive Debug'
    }
}
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل TCC_هدف_RISCV64
ساكن فراغ create_riscv_attribute_section(TCCState *s1)
{
    ساكن ثابت بنانشان حرف riscv_attr[] = {
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
    Section *attr = new_section(s1, ".riscv.attributes", SHT_RISCV_خاصيتون, 0);
    بنانشان حرف *ptr = section_ptr_جوڙيو(attr, حجم(riscv_attr));
    attr->sh_addralign = 1;
    يادگيري_نقل(ptr, riscv_attr, حجم(riscv_attr));
}
#جيڪڏهن_پورو

#إذا TARGETOS_OpenBSD || TARGETOS_NetBSD || TARGETOS_FreeBSD

ساكن فراغ fill_bsd_note(Section *s, صحيح type,
			  ثابت حرف *قدر, uint32_t معلومات)
{
    بنانشان ڊگهو وٿي = 0;
    حرف *ptr;
    ElfW(Nhdr) *note;
    صحيح align = s->sh_addralign;

    /* check if type present */
    طالما (وٿي + حجم(ElfW(Nhdr)) < s->معلومات_وٿي) {
        note = (ElfW(Nhdr) *) (s->معلومات + وٿي);
	إذا (note->n_type == type)
	    أرجع;
	وٿي += (حجم(ElfW(Nhdr)) + note->n_namesz + note->n_descsz +
		  align - 1) & -align;
    }
    ptr = section_ptr_جوڙيو(s, حجم(ElfW(Nhdr)) + 8 + 4);
    note = (ElfW(Nhdr) *) ptr;
    note->n_namesz = 8;
    note->n_descsz = 4;
    note->n_type = type;
    strcpy (ptr + حجم(ElfW(Nhdr)), قدر);
    يادگيري_نقل (ptr + حجم(ElfW(Nhdr)) + 8, &معلومات, 4);
}

ساكن Section *create_bsd_note_section(TCCState *s1,
					ثابت حرف *name,
					ثابت حرف *قدر)
{
    Section *s;
    بنانشان صحيح major = 0, minor = 0, patch = 0;

#جيڪڏهن_وصف_ٿيل CONFIG_OS_RELEASE
    لڙي_مان_پڙهو(CONFIG_OS_RELEASE, "%u.%u.%u", &major, &minor, &patch);
#جيڪڏهن_پورو
#إذا TARGETOS_FreeBSD
    إذا (major < 14)
	أرجع عدم;
#جيڪڏهن_پورو
    s = ڳوليو_section (s1, name);
    s->sh_type = SHT_NOTE;
#إذا TARGETOS_OpenBSD
    fill_bsd_note(s, ELF_NOTE_OS_GNU, قدر, 0);
#وإلاإذا TARGETOS_NetBSD
    fill_bsd_note(s, 1 /* NT_NETBSD_IDENT_TAG */, قدر,
		  major * 100000000u + (minor % 100u) * 1000000u +
		  (patch % 10000u) * 100u);
#وإلاإذا TARGETOS_FreeBSD
    fill_bsd_note(s, 1 /* NT_FREEBSD_ABI_TAG */, قدر,
		  major * 100000u + (minor % 100u) * 1000u);
    fill_bsd_note(s, 4 /* NT_FREEBSD_FEATURE_CTL */, قدر, 0);
    fill_bsd_note(s, 2 /* NT_FREEBSD_NOINIT_TAG */, قدر, 0);
#جيڪڏهن_پورو
    أرجع s;
}
#جيڪڏهن_پورو

ساكن فراغ alloc_sec_نالا(TCCState *s1, صحيح is_obj);

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
ساكن صحيح elf_output_file(TCCState *s1, ثابت حرف *filename)
{
    صحيح i, ret, file_type, *sec_ترتيب;
    بنية dyn_inf dyninf = {0};
    Section *interp, *dynstr, *dynamic;
    صحيح textrel, got_sym, dt_flags_1;

    file_type = s1->output_type;
    ret = -1;
    interp = dynstr = dynamic = عدم;
    sec_ترتيب = عدم;

#جيڪڏهن_وصف_ٿيل TCC_هدف_ARM
    create_arm_attribute_section (s1);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل TCC_هدف_RISCV64
    create_riscv_attribute_section(s1);
#جيڪڏهن_پورو

#إذا TARGETOS_OpenBSD
    dyninf.note = create_bsd_note_section (s1, ".note.openbsd.ident", "OpenBSD");
#جيڪڏهن_پورو

#إذا TARGETOS_NetBSD
    dyninf.note = create_bsd_note_section (s1, ".note.netbsd.ident", "NetBSD");
#جيڪڏهن_پورو

#إذا TARGETOS_FreeBSD
    dyninf.note = create_bsd_note_section (s1, ".note.tag", "FreeBSD");
#جيڪڏهن_پورو

        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_جوڙيو_runtime(s1);
	resolve_common_syms(s1);

        إذا (!s1->static_link) {
            إذا (file_type & TCC_OUTPUT_EXE) {
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
            إذا (file_type & TCC_OUTPUT_EXE) {
                bind_exe_dynsyms(s1, file_type & TCC_OUTPUT_DYN);
                إذا (s1->nb_errors)
                    اذهب the_پڇاڙي;
            }
            build_got_entries(s1, got_sym);
            إذا (file_type & TCC_OUTPUT_EXE) {
                bind_libs_dynsyms(s1);
            } وإلا {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
#إذا TCC_EH_چوکٺو
	    /* fill with initial data */
	    tcc_eh_چوکٺو_hdr(s1, 0);
#جيڪڏهن_پورو
	    dyninf.gnu_hash = create_gnu_hash(s1);
        } وإلا {
            build_got_entries(s1, 0);
        }
	نسخو_جوڙيو (s1);

    textrel = سيٽ_sec_sizes(s1);

    إذا (!s1->static_link) {
        /* add a list of needed dlls */
        لكل(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            إذا (dllref->level == 0)
                put_dt(dynamic, DT_NEEDED, put_elf_str(dynstr, dllref->name));
        }

        إذا (s1->rpath)
            put_dt(dynamic, s1->enable_new_dtags ? DT_RUNPATH : DT_RPATH,
                   put_elf_str(dynstr, s1->rpath));

        dt_flags_1 = DF_1_NOW;
        إذا (file_type & TCC_OUTPUT_DYN) {
            إذا (s1->soname)
                put_dt(dynamic, DT_SONAME, put_elf_str(dynstr, s1->soname));
            /* XXX: currently, since we do not handle PIC code, we
               must relocate the readonly segments */
            إذا (textrel)
                put_dt(dynamic, DT_TEXTREL, 0);
            إذا (file_type & TCC_OUTPUT_EXE)
                dt_flags_1 = DF_1_NOW | DF_1_PIE;
	    إذا (s1->znodelete)
		dt_flags_1 |= DF_1_NODELETE;
        }
        put_dt(dynamic, DT_FLAGS, DF_BIND_NOW);
        put_dt(dynamic, DT_FLAGS_1, dt_flags_1);
        إذا (s1->symbolic)
            put_dt(dynamic, DT_SYMBOLIC, 0);

        dyninf.dynamic = dynamic;
        dyninf.dynstr = dynstr;
        /* remember offset and reserve space for 2nd call below */
        dyninf.معلومات_وٿي = dynamic->معلومات_وٿي;
        fill_dynamic(s1, &dyninf);
        dynamic->sh_سائيز = dynamic->معلومات_وٿي;
        dynstr->sh_سائيز = dynstr->معلومات_وٿي;
    }

    /* create and fill .shstrtab section */
    alloc_sec_نالا(s1, 0);
    /* this array is used to reorder sections in the output file */
    sec_ترتيب = tcc_malloc(حجم(صحيح) * 2 * s1->nb_sections);
    /* compute section to program header mapping */
    layout_sections(s1, sec_ترتيب, &dyninf);

        إذا (dynamic) {
            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->معلومات, dynamic->sh_addr);
            إذا (file_type == TCC_OUTPUT_EXE
                || (RELOCATE_DLLPLT && (file_type & TCC_OUTPUT_DYN)))
                relocate_plt(s1);
            /* relocate symbols in .dynsym now that final addresses are known */
            relocate_syms(s1, s1->dynsym, 2);
        }

        /* if building executable or DLL, then relocate each section
           except the GOT which is already relocated */
        relocate_syms(s1, s1->symtab, 0);
        إذا (s1->nb_errors != 0)
            اذهب the_پڇاڙي;
        relocate_sections(s1);
        إذا (dynamic) {
	    update_reloc_sections (s1, &dyninf);
            dynamic->معلومات_وٿي = dyninf.معلومات_وٿي;
            fill_dynamic(s1, &dyninf);
	}
        /* Perform relocation to GOT or PLT entries */
        إذا (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        وإلا إذا (s1->got)
            fill_local_got_entries(s1);

    إذا (dyninf.gnu_hash)
        update_gnu_hash(s1, dyninf.gnu_hash);

    reorder_sections(s1, sec_ترتيب);
#إذا TCC_EH_چوکٺو
    /* fill with final data */
    tcc_eh_چوکٺو_hdr(s1, 1);
#جيڪڏهن_پورو
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, dyninf.phnum, dyninf.phdr);
 the_پڇاڙي:
    tcc_free(sec_ترتيب);
    tcc_free(dyninf.phdr);
    أرجع ret;
}
#جيڪڏهن_پورو /* ndef ELF_OBJ_ONLY */

/* Allocate strings for section names */
ساكن فراغ alloc_sec_نالا(TCCState *s1, صحيح is_obj)
{
    صحيح i;
    Section *s, *strsec;

    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        إذا (is_obj)
            s->sh_سائيز = s->معلومات_وٿي;
	إذا (s->sh_سائيز || s == strsec || (s->sh_flags & SHF_ALLOC) || is_obj)
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_سائيز = strsec->معلومات_وٿي;
}

/* Output an elf .o file */
ساكن صحيح elf_output_obj(TCCState *s1, ثابت حرف *filename)
{
    Section *s;
    صحيح i, ret, file_وٿي;
    /* Allocate strings for section names */
    alloc_sec_نالا(s1, 1);
    file_وٿي = (حجم (ElfW(Ehdr)) + 3) & -4;
    file_وٿي += s1->nb_sections * حجم(ElfW(Shdr));
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        file_وٿي = (file_وٿي + 15) & -16;
        s->sh_وٿي = file_وٿي;
        إذا (s->sh_type != SHT_NOBITS)
            file_وٿي += s->sh_سائيز;
    }
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, 0, عدم);
    أرجع ret;
}

LIBTCCAPI صحيح tcc_output_file(TCCState *s, ثابت حرف *filename)
{
    s->nb_errors = 0;
    إذا (s->test_coverage)
        tcc_tcov_جوڙيو_file(s, filename);
    إذا (s->output_type == TCC_OUTPUT_OBJ)
        أرجع elf_output_obj(s, filename);
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
    أرجع  pe_output_file(s, filename);
#وإلاإذا defined TCC_هدف_MACHO
    أرجع macho_output_file(s, filename);
#وإلا
    أرجع elf_output_file(s, filename);
#جيڪڏهن_پورو
}

ST_FUNC ssize_t ڀريل_read(صحيح fd, فراغ *buf, سائيز_t ڳڻپ_2) {
    حرف *cbuf = buf;
    سائيز_t rnum = 0;
    طالما (1) {
        ssize_t انگ = اقرأ(fd, cbuf, ڳڻپ_2-rnum);
        إذا (انگ < 0) أرجع انگ;
        إذا (انگ == 0) أرجع rnum;
        rnum += انگ;
        cbuf += انگ;
    }
}

ST_FUNC فراغ *ڀريو_معلومات(صحيح fd, بنانشان ڊگهو file_وٿي, بنانشان ڊگهو سائيز)
{
    فراغ *معلومات;

    معلومات = tcc_malloc(سائيز);
    lseek(fd, file_وٿي, SEEK_SET);
    ڀريل_read(fd, معلومات, سائيز);
    أرجع معلومات;
}

تعريفنوع بنية Section_ملايو_Info {
    Section *s;            /* corresponding existing section */
    بنانشان ڊگهو وٿي;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} Section_ملايو_Info;

ST_FUNC صحيح tcc_object_type(صحيح fd, ElfW(Ehdr) *h)
{
    صحيح سائيز = ڀريل_read(fd, h, حجم *h);
    إذا (سائيز == حجم *h && 0 == memcmp(h, ELFMAG, 4)) {
        إذا (h->e_type == ET_REL)
            أرجع AFF_BINTYPE_REL;
        إذا (h->e_type == ET_DYN)
            أرجع AFF_BINTYPE_DYN;
    } وإلا إذا (سائيز >= 8) {
        إذا (0 == memcmp(h, ARMAG, 8))
            أرجع AFF_BINTYPE_AR;
#جيڪڏهن_وصف_ٿيل TCC_هدف_COFF
        إذا (((بنية filehdr*)h)->f_magic == COFF_C67_MAGIC)
            أرجع AFF_BINTYPE_C67;
#جيڪڏهن_پورو
    }
    أرجع 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC صحيح tcc_ڀريو_object_file(TCCState *s1,
                                صحيح fd, بنانشان ڊگهو file_وٿي)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    بنانشان ڊگهو سائيز, وٿي, offseti;
    صحيح i, j, nb_syms, sym_اشاريو, ret, seencompressed;
    حرف *strsec, *strtab;
    صحيح stab_اشاريو, stabstr_اشاريو;
    صحيح *old_منزل_new_syms;
    حرف *sh_name, *name;
    Section_ملايو_Info *sm_جدول, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    lseek(fd, file_وٿي, SEEK_SET);
    إذا (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        اذهب invalid;
    /* test CPU specific stuff */
    إذا (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_هدف) {
invalid:
        أرجع tcc_error_noabort("invalid object file");
    }
    /* read sections */
    shdr = ڀريو_معلومات(fd, file_وٿي + ehdr.e_shoff,
                     حجم(ElfW(Shdr)) * ehdr.e_shnum);
    sm_جدول = tcc_mallocz(حجم(Section_ملايو_Info) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = ڀريو_معلومات(fd, file_وٿي + sh->sh_وٿي, sh->sh_سائيز);

    /* load symtab and strtab */
    old_منزل_new_syms = عدم;
    symtab = عدم;
    strtab = عدم;
    nb_syms = 0;
    seencompressed = 0;
    stab_اشاريو = stabstr_اشاريو = 0;
    ret = -1;

    لكل(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        إذا (sh->sh_type == SHT_SYMTAB) {
            إذا (symtab) {
                tcc_error_noabort("object must contain only one symtab");
                اذهب the_پڇاڙي;
            }
            nb_syms = sh->sh_سائيز / حجم(ElfW(Sym));
            symtab = ڀريو_معلومات(fd, file_وٿي + sh->sh_وٿي, sh->sh_سائيز);
            sm_جدول[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = ڀريو_معلومات(fd, file_وٿي + sh->sh_وٿي, sh->sh_سائيز);
        }
	إذا (sh->sh_flags & SHF_COMPRESSED)
	    seencompressed = 1;
    }

    /* now examine each section and try to merge its content with the
       ones in memory */
    لكل(i = 1; i < ehdr.e_shnum; i++) {
        /* no need to examine section name strtab */
        إذا (i == ehdr.e_shstrndx)
            استمر;
        sh = &shdr[i];
	إذا (sh->sh_type == SHT_RELX)
	  sh = &shdr[sh->sh_info];
        /* ignore sections types we do not handle (plus relocs to those) */
        sh_name = strsec + sh->sh_name;
        إذا (0 == لڙي_ڀيٽ(sh_name, ".debug_", 7)
         || 0 == لڙي_ڀيٽ(sh_name, ".stab", 5)) {
	    إذا (!s1->do_debug || seencompressed)
	        استمر;
#إذا !(TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD)
        } وإلا إذا (0 == لڙي_ڀيٽ(sh_name, ".eh_frame", 9)) {
            إذا (عدم == eh_چوکٺو_section)
                استمر;
#جيڪڏهن_پورو
        } وإلا
        إذا (sh->sh_type != SHT_PROGBITS &&
            sh->sh_type != SHT_NOTE &&
            sh->sh_type != SHT_NOBITS &&
            sh->sh_type != SHT_PREINIT_ARRAY &&
            sh->sh_type != SHT_INIT_ARRAY &&
            sh->sh_type != SHT_FINI_ARRAY
#جيڪڏهن_وصف_ٿيل TCC_ARM_EABI
            /* Added in commit f99d3de221db23e322c6c18c8249282e27726c25
               but suppressed in 3cfaaaf1eb97d858e583412616f68f75fdad5da5
               So don't load it in order to avoid dangling references from
               (STT_SECTION) symbols. */
            // && sh->sh_type != SHT_ARM_EXIDX
#جيڪڏهن_پورو

#إذا TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD
            && sh->sh_type != SHT_X86_64_UNWIND
#جيڪڏهن_پورو
            )
            استمر;

	sh = &shdr[i];
        sh_name = strsec + sh->sh_name;
        إذا (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        /* find corresponding section, if any */
        لكل(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            إذا (strcmp(s->name, sh_name))
                استمر;
            إذا (sh->sh_type != s->sh_type
                && strcmp (s->name, ".eh_frame")
                /* some crt1.o seem to have two ".note.GNU-stack" (SHT_NOTE & SHT_PROGBITS) */
                && strcmp (s->name, ".note.GNU-stack")
                ) {
                tcc_error_noabort("section type conflict: %s %02x <> %02x", s->name, sh->sh_type, s->sh_type);
                اذهب the_پڇاڙي;
            }
            إذا (!لڙي_ڀيٽ(sh_name, ".gnu.linkonce", 13)) {
                /* if a 'linkonce' section is already present, we
                   do not add it again. It is a little tricky as
                   symbols can still be defined in
                   it. */
                sm_جدول[i].link_once = 1;
                اذهب ايندڙ;
            }
            إذا (stab_section) {
                إذا (s == stab_section)
                    stab_اشاريو = i;
                إذا (s == stab_section->link)
                    stabstr_اشاريو = i;
            }
            اذهب مليو;
        }
        /* not found: create new section */
        s = new_section(s1, sh_name, sh->sh_type, sh->sh_flags & ~SHF_گروهه);
        /* take as much info as possible from the section. sh_link and
           sh_info will be updated later */
        s->sh_addralign = sh->sh_addralign;
        s->sh_entsize = sh->sh_entsize;
        sm_جدول[i].new_section = 1;
    مليو:
        سائيز = sh->sh_سائيز;
        /* align start of section */
        وٿي = section_جوڙيو(s, سائيز, sh->sh_addralign);
        إذا (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        sm_جدول[i].وٿي = وٿي;
        sm_جدول[i].s = s;
        /* concatenate sections */
        إذا (sh->sh_type != SHT_NOBITS && سائيز) {
            بنانشان حرف *ptr;
            lseek(fd, file_وٿي + sh->sh_وٿي, SEEK_SET);
            ptr = s->معلومات + وٿي;
            ڀريل_read(fd, ptr, سائيز);
        }
#إذا defined TCC_هدف_ARM || defined TCC_هدف_ARM64 || defined TCC_هدف_RISCV64
        /* align code sections to instruction lenght */
        /* This is needed if we compile a c file after this */
        إذا (s->sh_flags & SHF_EXECINSTR)
            section_جوڙيو(s, 0, 4);
#جيڪڏهن_پورو
    ايندڙ: ;
    }

    /* gr relocate stab strings */
    إذا (stab_اشاريو && stabstr_اشاريو) {
        Stab_Sym *a, *b;
        بنانشان o;
        s = sm_جدول[stab_اشاريو].s;
        a = (Stab_Sym *)(s->معلومات + sm_جدول[stab_اشاريو].وٿي);
        b = (Stab_Sym *)(s->معلومات + s->معلومات_وٿي);
        o = sm_جدول[stabstr_اشاريو].وٿي;
        طالما (a < b) {
            إذا (a->n_strx)
                a->n_strx += o;
            a++;
        }
    }

    /* second short pass to update sh_link and sh_info fields of new
       sections */
    لكل(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_جدول[i].s;
        إذا (!s || !sm_جدول[i].new_section)
            استمر;
        sh = &shdr[i];
        إذا (sh->sh_link > 0)
            s->link = sm_جدول[sh->sh_link].s;
        إذا (sh->sh_type == SHT_RELX) {
            s->sh_info = sm_جدول[sh->sh_info].s->sh_انگ;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }

    إذا (!symtab)
        اذهب پورو;

    /* resolve symbols */
    old_منزل_new_syms = tcc_mallocz(nb_syms * حجم(صحيح));

    sym = symtab + 1;
    لكل(i = 1; i < nb_syms; i++, sym++) {
        إذا (sym->st_shndx != SHN_UNDEF &&
            sym->st_shndx < SHN_LORESERVE) {
            sm = &sm_جدول[sym->st_shndx];
            إذا (sm->link_once) {
                /* if a symbol is in a link once section, we use the
                   already defined symbol. It is very important to get
                   correct relocations */
                إذا (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
                    name = strtab + sym->st_name;
                    sym_اشاريو = ڳوليو_elf_sym(symtab_section, name);
                    إذا (sym_اشاريو)
                        old_منزل_new_syms[i] = sym_اشاريو;
                }
                استمر;
            }
            /* if no corresponding section added, no need to add symbol */
            إذا (!sm->s)
                استمر;
            /* convert section number */
            sym->st_shndx = sm->s->sh_انگ;
            /* offset value */
            sym->st_قدر += sm->وٿي;
        }
        /* add symbol */
        name = strtab + sym->st_name;
        sym_اشاريو = سيٽ_elf_sym(symtab_section, sym->st_قدر, sym->st_سائيز,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_منزل_new_syms[i] = sym_اشاريو;
    }

    /* third pass to patch relocation entries */
    لكل(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_جدول[i].s;
        إذا (!s)
            استمر;
        sh = &shdr[i];
        وٿي = sm_جدول[i].وٿي;
        سائيز = sh->sh_سائيز;
        بدل(s->sh_type) {
        حالة SHT_RELX:
            /* take relocation offset information */
            offseti = sm_جدول[sh->sh_info].وٿي;
	    لكل (rel = (ElfW_Rel *) s->معلومات + (وٿي / حجم(*rel));
		 rel < (ElfW_Rel *) s->معلومات + ((وٿي + سائيز) / حجم(*rel));
		 rel++) {
                صحيح type;
                بنانشان sym_اشاريو;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_اشاريو = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                إذا (sym_اشاريو >= nb_syms)
                    اذهب invalid_reloc;
                sym_اشاريو = old_منزل_new_syms[sym_اشاريو];
                /* ignore link_once in rel section. */
                إذا (!sym_اشاريو && !sm_جدول[sh->sh_info].link_once
#جيڪڏهن_وصف_ٿيل TCC_هدف_ARM
                    && type != R_ARM_V4BX
#وإلاإذا defined TCC_هدف_RISCV64
                    && type != R_RISCV_ALIGN
                    && type != R_RISCV_RELAX
#جيڪڏهن_پورو
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, (صحيح)rel->r_وٿي);
                    اذهب the_پڇاڙي;
                }
                rel->r_info = ELFW(R_INFO)(sym_اشاريو, type);
                /* offset the relocation offset */
                rel->r_وٿي += offseti;
#جيڪڏهن_وصف_ٿيل TCC_هدف_ARM
                /* Jumps and branches from a Thumb code to a PLT entry need
                   special handling since PLT entries are ARM code.
                   Unconditional bl instructions referencing PLT entries are
                   handled by converting these instructions into blx
                   instructions. Other case of instructions referencing a PLT
                   entry require to add a Thumb stub before the PLT entry to
                   switch to ARM mode. We set bit plt_thumb_stub of the
                   attribute of a symbol to indicate such a case. */
                إذا (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_اشاريو, 1)->plt_thumb_stub = 1;
#جيڪڏهن_پورو
            }
            اكسر;
        افتراضي:
            اكسر;
        }
    }
 پورو:
    ret = !s1->nb_errors - 1; /* errors possibly from set_elf_sym() */
 the_پڇاڙي:
    tcc_free(symtab);
    tcc_free(strtab);
    tcc_free(old_منزل_new_syms);
    tcc_free(sm_جدول);
    tcc_free(strsec);
    tcc_free(shdr);
    أرجع ret;
}

تعريفنوع بنية Archive_سرو {
    حرف ar_name[16];           /* name of this member */
    حرف ar_date[12];           /* file mtime */
    حرف ar_uid[6];             /* owner uid; printed as decimal */
    حرف ar_gid[6];             /* owner gid; printed as decimal */
    حرف ar_گهڻائي[8];            /* file mode, printed as octal   */
    حرف ar_سائيز[10];           /* file size, printed as decimal */
    حرف ar_fmag[2];            /* should contain ARFMAG */
} Archive_سرو;

#وصف_ڪريو ARFMAG "`\n"

ساكن بنانشان ڊگهو ڊگهو get_be(ثابت uint8_t *b, صحيح n)
{
    بنانشان ڊگهو ڊگهو ret = 0;
    طالما (n)
        ret = (ret << 8) | *b++, --n;
    أرجع ret;
}

ساكن صحيح read_ar_سرو(صحيح fd, صحيح وٿي, Archive_سرو *hdr)
{
    حرف *p, *e;
    صحيح len;
    lseek(fd, وٿي, SEEK_SET);
    len = ڀريل_read(fd, hdr, حجم(Archive_سرو));
    إذا (len != حجم(Archive_سرو))
        أرجع len ? -1 : 0;
    إذا (memcmp(hdr->ar_fmag, ARFMAG, حجم hdr->ar_fmag))
        أرجع -1;
    p = hdr->ar_name;
    لكل (e = p + حجم hdr->ar_name; e > p && e[-1] == ' ';)
        --e;
    *e = '\0';
    hdr->ar_سائيز[حجم hdr->ar_سائيز-1] = 0;
    أرجع len;
}

/* load only the objects which resolve undefined symbols */
ساكن صحيح tcc_ڀريو_alacarte(TCCState *s1, صحيح fd, صحيح سائيز, صحيح entrysize)
{
    صحيح i, bound, nsyms, sym_اشاريو, len, ret = -1;
    بنانشان ڊگهو ڊگهو off;
    uint8_t *معلومات;
    ثابت حرف *ar_نالا, *p;
    ثابت uint8_t *ar_اشاريو;
    ElfW(Sym) *sym;
    Archive_سرو hdr;

    معلومات = tcc_malloc(سائيز);
    إذا (ڀريل_read(fd, معلومات, سائيز) != سائيز)
        اذهب invalid;
    nsyms = get_be(معلومات, entrysize);
    ar_اشاريو = معلومات + entrysize;
    ar_نالا = (حرف *) ar_اشاريو + nsyms * entrysize;

    افعل {
        bound = 0;
        لكل (p = ar_نالا, i = 0; i < nsyms; i++, p += لڙي_ڊيگهه(p)+1) {
            Section *s = symtab_section;
            sym_اشاريو = ڳوليو_elf_sym(s, p);
            إذا (!sym_اشاريو)
                استمر;
            sym = &((ElfW(Sym) *)s->معلومات)[sym_اشاريو];
            إذا(sym->st_shndx != SHN_UNDEF)
                استمر;
            off = get_be(ar_اشاريو + i * entrysize, entrysize);
            len = read_ar_سرو(fd, off, &hdr);
            إذا (len <= 0 || memcmp(hdr.ar_fmag, ARFMAG, 2)) {
        invalid:
                tcc_error_noabort("invalid archive");
                اذهب the_پڇاڙي;
            }
            off += len;
            إذا (s1->verbose == 2)
                لکو("   -> %s\n", hdr.ar_name);
            إذا (tcc_ڀريو_object_file(s1, fd, off) < 0)
                اذهب the_پڇاڙي;
            ++bound;
        }
    } طالما(bound);
    ret = 0;
 the_پڇاڙي:
    tcc_free(معلومات);
    أرجع ret;
}

/* load a '.a' file */
ST_FUNC صحيح tcc_ڀريو_archive(TCCState *s1, صحيح fd, صحيح alacarte)
{
    Archive_سرو hdr;
    /* char magic[8]; */
    صحيح سائيز, len;
    بنانشان ڊگهو file_وٿي;
    ElfW(Ehdr) ehdr;

    /* skip magic which was already checked */
    /* full_read(fd, magic, sizeof(magic)); */
    file_وٿي = حجم ARMAG - 1;

    لكل(;;) {
        len = read_ar_سرو(fd, file_وٿي, &hdr);
        إذا (len == 0)
            أرجع 0;
        إذا (len < 0)
            أرجع tcc_error_noabort("invalid archive");
        file_وٿي += len;
        سائيز = strtol(hdr.ar_سائيز, عدم, 0);
        إذا (alacarte) {
            /* coff symbol table : we handle it */
            إذا (!strcmp(hdr.ar_name, "/"))
                أرجع tcc_ڀريو_alacarte(s1, fd, سائيز, 4);
            إذا (!strcmp(hdr.ar_name, "/SYM64/"))
                أرجع tcc_ڀريو_alacarte(s1, fd, سائيز, 8);
        } وإلا إذا (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
            إذا (s1->verbose == 2)
                لکو("   -> %s\n", hdr.ar_name);
            إذا (tcc_ڀريو_object_file(s1, fd, file_وٿي) < 0)
                أرجع -1;
        }
        /* align to even */
        file_وٿي = (file_وٿي + سائيز + 1) & ~1;
    }
}

#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
/* Set LV[I] to the global index of sym-version (LIB,VERSION).  Maybe resizes
   LV, maybe create a new entry for (LIB,VERSION).  */
ساكن فراغ سيٽ_ver_منزل_ver(TCCState *s1, صحيح *n, صحيح **lv, صحيح i, حرف *lib, حرف *نسخو)
{
    طالما (i >= *n) {
        *lv = tcc_realloc(*lv, (*n + 1) * حجم(**lv));
        (*lv)[(*n)++] = -1;
    }
    إذا ((*lv)[i] == -1) {
        صحيح v, prev_same_lib = -1;
        لكل (v = 0; v < nb_sym_versions; v++) {
            إذا (strcmp(sym_versions[v].lib, lib))
              استمر;
            prev_same_lib = v;
            إذا (!strcmp(sym_versions[v].نسخو, نسخو))
              اكسر;
        }
        إذا (v == nb_sym_versions) {
            sym_versions = tcc_realloc (sym_versions,
                                        (v + 1) * حجم(*sym_versions));
            sym_versions[v].lib = tcc_strdup(lib);
            sym_versions[v].نسخو = tcc_strdup(نسخو);
            sym_versions[v].ٻاهريون_اشاريو = 0;
            sym_versions[v].prev_same_lib = prev_same_lib;
            nb_sym_versions++;
        }
        (*lv)[i] = v;
    }
}

/* Associates symbol SYM_INDEX (in dynsymtab) with sym-version index
   VERNDX.  */
ساكن فراغ
سيٽ_sym_نسخو(TCCState *s1, صحيح sym_اشاريو, صحيح verndx)
{
    إذا (sym_اشاريو >= nb_sym_منزل_نسخو) {
        صحيح newelems = sym_اشاريو ? sym_اشاريو * 2 : 1;
        sym_منزل_نسخو = tcc_realloc(sym_منزل_نسخو,
                                     newelems * حجم(*sym_منزل_نسخو));
        memset(sym_منزل_نسخو + nb_sym_منزل_نسخو, -1,
               (newelems - nb_sym_منزل_نسخو) * حجم(*sym_منزل_نسخو));
        nb_sym_منزل_نسخو = newelems;
    }
    إذا (sym_منزل_نسخو[sym_اشاريو] < 0)
      sym_منزل_نسخو[sym_اشاريو] = verndx;
}

بنية versym_info {
    صحيح nb_versyms;
    ElfW(Verdef) *verdef;
    ElfW(Verneed) *verneed;
    ElfW(Half) *versym;
    صحيح nb_local_ver, *local_ver;
};


ساكن فراغ store_نسخو(TCCState *s1, بنية versym_info *v, حرف *dynstr)
{
    حرف *lib, *نسخو;
    uint32_t ايندڙ;
    صحيح i;

#وصف_ڪريو	DEBUG_نسخو 0

    إذا (v->versym && v->verdef) {
      ElfW(Verdef) *vdef = v->verdef;
      lib = عدم;
      افعل {
        ElfW(Verdaux) *verdaux =
	  (ElfW(Verdaux) *) (((حرف *) vdef) + vdef->vd_aux);

#إذا DEBUG_نسخو
	لکو ("verdef: version:%u flags:%u index:%u, hash:%u\n",
	        vdef->vd_نسخو, vdef->vd_flags, vdef->vd_ndx,
		vdef->vd_hash);
#جيڪڏهن_پورو
	إذا (vdef->vd_cnt) {
          نسخو = dynstr + verdaux->vda_name;

	  إذا (lib == عدم)
	    lib = نسخو;
	  وإلا
            سيٽ_ver_منزل_ver(s1, &v->nb_local_ver, &v->local_ver, vdef->vd_ndx,
                           lib, نسخو);
#إذا DEBUG_نسخو
	  لکو ("  verdaux(%u): %s\n", vdef->vd_ndx, نسخو);
#جيڪڏهن_پورو
	}
        ايندڙ = vdef->vd_ايندڙ;
        vdef = (ElfW(Verdef) *) (((حرف *) vdef) + ايندڙ);
      } طالما (ايندڙ);
    }
    إذا (v->versym && v->verneed) {
      ElfW(Verneed) *vneed = v->verneed;
      افعل {
        ElfW(Vernaux) *vernaux =
	  (ElfW(Vernaux) *) (((حرف *) vneed) + vneed->vn_aux);

        lib = dynstr + vneed->vn_file;
#إذا DEBUG_نسخو
	لکو ("verneed: %u %s\n", vneed->vn_نسخو, lib);
#جيڪڏهن_پورو
	لكل (i = 0; i < vneed->vn_cnt; i++) {
	  إذا ((vernaux->vna_other & 0x8000) == 0) { /* hidden */
              نسخو = dynstr + vernaux->vna_name;
              سيٽ_ver_منزل_ver(s1, &v->nb_local_ver, &v->local_ver, vernaux->vna_other,
                             lib, نسخو);
#إذا DEBUG_نسخو
	    لکو ("  vernaux(%u): %u %u %s\n",
		    vernaux->vna_other, vernaux->vna_hash,
		    vernaux->vna_flags, نسخو);
#جيڪڏهن_پورو
	  }
	  vernaux = (ElfW(Vernaux) *) (((حرف *) vernaux) + vernaux->vna_ايندڙ);
	}
        ايندڙ = vneed->vn_ايندڙ;
        vneed = (ElfW(Verneed) *) (((حرف *) vneed) + ايندڙ);
      } طالما (ايندڙ);
    }

#إذا DEBUG_نسخو
    لكل (i = 0; i < v->nb_local_ver; i++) {
      إذا (v->local_ver[i] > 0) {
        لکو ("%d: lib: %s, version %s\n",
		i, sym_versions[v->local_ver[i]].lib,
                sym_versions[v->local_ver[i]].نسخو);
      }
    }
#جيڪڏهن_پورو
}

/* load a library / DLL
   'level = 0' means that the DLL is referenced by the user
   (so it should be added as DT_NEEDED in the generated ELF file) */
ST_FUNC صحيح tcc_ڀريو_dll(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    صحيح i, nb_syms, nb_dts, sym_bind, ret = -1;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;

    حرف *dynstr;
    صحيح sym_اشاريو;
    ثابت حرف *name, *soname;
    بنية versym_info v;

    ڀريل_read(fd, &ehdr, حجم(ehdr));

    /* test CPU specific stuff */
    إذا (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_هدف) {
        أرجع tcc_error_noabort("bad architecture");
    }

    /* read sections */
    shdr = ڀريو_معلومات(fd, ehdr.e_shoff, حجم(ElfW(Shdr)) * ehdr.e_shnum);

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
            nb_dts = sh->sh_سائيز / حجم(ElfW(Dyn));
            dynamic = ڀريو_معلومات(fd, sh->sh_وٿي, sh->sh_سائيز);
            اكسر;
        حالة SHT_DYNSYM:
            nb_syms = sh->sh_سائيز / حجم(ElfW(Sym));
            dynsym = ڀريو_معلومات(fd, sh->sh_وٿي, sh->sh_سائيز);
            sh1 = &shdr[sh->sh_link];
            dynstr = ڀريو_معلومات(fd, sh1->sh_وٿي, sh1->sh_سائيز);
            اكسر;
        حالة SHT_GNU_verdef:
	    v.verdef = ڀريو_معلومات(fd, sh->sh_وٿي, sh->sh_سائيز);
	    اكسر;
        حالة SHT_GNU_verneed:
	    v.verneed = ڀريو_معلومات(fd, sh->sh_وٿي, sh->sh_سائيز);
	    اكسر;
        حالة SHT_GNU_versym:
            v.nb_versyms = sh->sh_سائيز / حجم(ElfW(Half));
	    v.versym = ڀريو_معلومات(fd, sh->sh_وٿي, sh->sh_سائيز);
	    اكسر;
        افتراضي:
            اكسر;
        }
    }

    إذا (!dynamic)
        اذهب the_پڇاڙي;

    /* compute the real library name */
    soname = tcc_basename(filename);
    لكل(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        إذا (dt->d_ٽيگ == DT_SONAME)
            soname = dynstr + dt->d_un.d_val;

    /* if the dll is already loaded, do not load it */
    إذا (tcc_جوڙيو_dllref(s1, soname, level)->مليو)
        اذهب ret_success;

    إذا (v.nb_versyms != nb_syms)
        tcc_free (v.versym), v.versym = عدم;
    وإلا
        store_نسخو(s1, &v, dynstr);

    /* add dynamic symbols in dynsym_section */
    لكل(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        إذا (sym_bind == STB_LOCAL)
            استمر;
        name = dynstr + sym->st_name;
        sym_اشاريو = سيٽ_elf_sym(s1->dynsymtab_section, sym->st_قدر, sym->st_سائيز,
                                sym->st_info, sym->st_other, sym->st_shndx, name);
        إذا (v.versym) {
            ElfW(Half) vsym = v.versym[i];
            إذا ((vsym & 0x8000) == 0 && vsym > 0 && vsym < v.nb_local_ver)
                سيٽ_sym_نسخو(s1, sym_اشاريو, v.local_ver[vsym]);
        }
    }

    /* do not load all referenced libraries
       (recursive loading can break linking of libraries) */
    /* following DT_NEEDED is needed for the dynamic loader (libdl.so),
       but it is no longer needed, when linking a library or a program.
       When tcc output mode is OUTPUT_MEM,
       tcc calls dlopen, which handles DT_NEEDED for us */

#إذا 0
    لكل(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        إذا (dt->d_ٽيگ == DT_RPATH)
            tcc_جوڙيو_library_رستو(s1, dynstr + dt->d_un.d_val);

    /* load all referenced DLLs */
    لكل(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        بدل(dt->d_ٽيگ) {
        حالة DT_NEEDED:
            name = dynstr + dt->d_un.d_val;
            إذا (tcc_جوڙيو_dllref(s1, name, -1))
                استمر;
            إذا (tcc_جوڙيو_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                ret = tcc_error_noabort("referenced dll '%s' not found", name);
                اذهب the_پڇاڙي;
            }
        }
    }
#جيڪڏهن_پورو

 ret_success:
    ret = 0;
 the_پڇاڙي:
    tcc_free(dynstr);
    tcc_free(dynsym);
    tcc_free(dynamic);
    tcc_free(shdr);
    tcc_free(v.local_ver);
    tcc_free(v.verdef);
    tcc_free(v.verneed);
    tcc_free(v.versym);
    أرجع ret;
}

#وصف_ڪريو LD_TOK_NAME 256
#وصف_ڪريو LD_TOK_EOF  (-1)
ساكن صحيح ld_inp(TCCState *s1)
{
    صحيح c = *s1->ld_p;
    إذا (c == 0)
        أرجع CH_EOF;
    ++s1->ld_p;
    أرجع c;
}
#وصف_ڪريو ld_unget(s1, ch) إذا (ch != CH_EOF) --s1->ld_p

/* return next ld script token */
ساكن صحيح ld_ايندڙ(TCCState *s1, حرف *name, صحيح name_سائيز)
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
        إذا (ch == '*') { /* comment */
            لكل (d = 0;; d = ch) {
                ch = ld_inp(s1);
                إذا (ch == CH_EOF || (ch == '/' && d == '*'))
                    اكسر;
            }
            اذهب redo;
        } وإلا {
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
            إذا (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') ||
                  strchr("/.-_+=$:\\,~", ch)))
                اكسر;
            إذا ((q - name) < name_سائيز - 1) {
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
    أرجع c;
}

ساكن صحيح ld_جوڙيو_file(TCCState *s1, ثابت حرف filename[])
{
    إذا (filename[0] == '-' && filename[1] == 'l')
        أرجع tcc_جوڙيو_library(s1, filename + 2);
    إذا (CONFIG_SYSROOT[0] != '\0' || !IS_ABSPATH(filename)) {
        /* lookup via library paths */
        صحيح ret = tcc_جوڙيو_dll(s1, tcc_basename(filename), 0);
        إذا (ret != FILE_NOT_مليو)
            أرجع ret;
    }
    أرجع tcc_جوڙيو_file_اندروني(s1, filename, AFF_PRINT_ERROR);
}

/* did static libraries add new undefined symbols? */
ساكن صحيح new_undef_sym(TCCState *s1, صحيح sym_وٿي)
{
    طالما (sym_وٿي < s1->symtab->معلومات_وٿي) {
        ElfW(Sym) *esym = (فراغ*)(s1->symtab->معلومات + sym_وٿي);
        إذا (esym->st_shndx == SHN_UNDEF)
            أرجع 1;
        sym_وٿي += حجم (ElfW(Sym));
    }
    أرجع 0;
}

ساكن صحيح ld_جوڙيو_file_list(TCCState *s1, ثابت حرف *cmd)
{
    حرف filename[1024];
    صحيح t, c, sym_وٿي, ret = 0;
    بنانشان حرف *pos = s1->ld_p;

repeat:
    s1->ld_p = pos;
    sym_وٿي = s1->symtab->معلومات_وٿي;
    c = cmd[0];

    t = ld_ايندڙ(s1, filename, حجم(filename));
    إذا (t != '(')
        أرجع tcc_error_noabort("expected '(' after %s", cmd);
    t = ld_ايندڙ(s1, filename, حجم(filename));
    لكل(;;) {
        إذا (t == LD_TOK_EOF) {
            أرجع tcc_error_noabort("unexpected end of file");
        } وإلا إذا (t == ')') {
            اكسر;
        } وإلا إذا (t != LD_TOK_NAME) {
            أرجع tcc_error_noabort("unexpected token '%c'", t);
        } وإلا إذا (!strcmp(filename, "AS_NEEDED")) {
            ret |= ld_جوڙيو_file_list(s1, filename);
        } وإلا إذا (c == 'I' || c == 'G' || c == 'A') {
            ret |= !!ld_جوڙيو_file(s1, filename);
        }
        إذا (ret < 0)
            أرجع ret;
        t = ld_ايندڙ(s1, filename, حجم(filename));
        إذا (t == ',')
            t = ld_ايندڙ(s1, filename, حجم(filename));
    }
    إذا (c == 'G' && ret == 0 && new_undef_sym(s1, sym_وٿي))
        اذهب repeat;
    أرجع ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC صحيح tcc_ڀريو_ldscript(TCCState *s1, صحيح fd)
{
    حرف cmd[64];
    صحيح t, ret = 0, noscript = 1;
    بنانشان حرف *متن_ptr, *saved_ptr;

    saved_ptr = s1->ld_p;
    s1->ld_p = متن_ptr = (فراغ*)tcc_ڀريو_متن(fd);
    لكل(;;) {
        t = ld_ايندڙ(s1, cmd, حجم(cmd));
        إذا (t == LD_TOK_EOF)
            اكسر;
        إذا (!strcmp(cmd, "INPUT") ||
            !strcmp(cmd, "GROUP")) {
            ret |= ld_جوڙيو_file_list(s1, cmd);
        } وإلا إذا (!strcmp(cmd, "OUTPUT_FORMAT") ||
                   !strcmp(cmd, "TARGET")) {
            /* ignore some commands */
            ret |= ld_جوڙيو_file_list(s1, cmd);
        } وإلا إذا (noscript) {
            ret = FILE_NOT_RECOGNIZED;
        } وإلا {
            ret = tcc_error_noabort("unexpected '%s'", cmd);
        }
        إذا (ret < 0)
            اكسر;
        noscript = 0;
    }
    tcc_free(متن_ptr);
    s1->ld_p = saved_ptr;
    أرجع ret < 0 ? ret : -ret;
}
#جيڪڏهن_پورو /* !ELF_OBJ_ONLY */
