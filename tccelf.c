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
#تعریف_رد DEBUG_RELOC

/********************************************************/
/* global variables */

/* elf version information */
بنية sym_نسخہ {
    حرف *lib;
    حرف *نسخہ;
    صحيح باہرلا_اشاریہ;
    صحيح prev_same_lib;
};

#تعریف_کرو nb_sym_versions     s1->nb_sym_versions
#تعریف_کرو sym_versions        s1->sym_versions
#تعریف_کرو nb_sym_منزل_نسخہ   s1->nb_sym_منزل_نسخہ
#تعریف_کرو sym_منزل_نسخہ      s1->sym_منزل_نسخہ
#تعریف_کرو dt_verneednum       s1->dt_verneednum
#تعریف_کرو versym_section      s1->versym_section
#تعریف_کرو verneed_section     s1->verneed_section

/* special flag to indicate that the section should not be linked to the other ones */
#تعریف_کرو SHF_نجی 0x80000000
/* section is dynsymtab_section */
#تعریف_کرو SHF_DYNSYM 0x40000000

#جے_تعریف_شدہ TCC_نشانہ_PE
#تعریف_کرو shf_RELRO SHF_ALLOC
ساكن ثابت حرف rdata[] = ".rdata";
#وإلا
#تعریف_کرو shf_RELRO SHF_ALLOC /* eventually made SHF_WRITE in sort_sections() */
ساكن ثابت حرف rdata[] = ".data.ro";
#جے_انت

/* ------------------------------------------------------------------------- */

ST_FUNC فراغ tccelf_new(TCCState *s)
{
    TCCState *s1 = s;

    /* no section zero */
    dynarray_جوڑو(&s->sections, &s->nb_sections, عدم);

    /* create standard sections */
    متن_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    انکڑے_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
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

    إذا (s->do_debug) {
        /* add debug sections */
        tcc_debug_new(s);
    }

#إذا TCC_EH_چوکھٹا
    إذا (s->output_format != TCC_OUTPUT_FORMAT_ELF)
        s->unwind_tables = 0;
    tcc_eh_چوکھٹا_شروع(s);
#جے_انت

#جے_تعریف_شدہ CONFIG_TCC_BCHECK
    إذا (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        /* (make ro after relocation done with GNU_RELRO) */
        bounds_section = new_section(s, ".bounds", SHT_PROGBITS, shf_RELRO);
        lbounds_section = new_section(s, ".lbounds", SHT_PROGBITS, shf_RELRO);
    }
#جے_انت

#جے_تعریف_شدہ TCC_نشانہ_PE
    /* to make sure that -ltcc1 -Wl,-e,_start will grab the startup code
       from libtcc1.a (unless _start defined) */
    إذا (s->elf_entryname)
        سیٹ_global_sym(s, s->elf_entryname, عدم, 0); /* SHN_UNDEF */
#جے_انت

#جے_بنا_تعریف ELF_OBJ_ONLY
    إذا (عدم == s->elfint && s1->output_type != TCC_OUTPUT_OBJ) {
        ثابت حرف *p = CONFIG_TCC_ELFINTERP;
#إذا defined TCC_نشانہ_ARM && defined CONFIG_TCC_ELFINTERP_ARMHF
        إذا (s->float_abi == ARM_HARD_FLOAT)
            p = CONFIG_TCC_ELFINTERP_ARMHF;
#جے_انت
#إذا defined TCC_IS_NATIVE && defined TARGETOS_BSD
        /* see commit 55cb2170cd5ce77a7d76dcaf462fad2707281605 */
        { ثابت حرف *e = getenv("LD_SO"); إذا (e) p = e; }
#جے_انت
        s->elfint = tcc_strdup(p);
    }
#جے_انت /* ndef ELF_OBJ_ONLY */
}

ST_FUNC فراغ free_section(Section *s)
{
    إذا (!s)
        أرجع;
    tcc_free(s->انکڑے);
    s->انکڑے = عدم;
    s->انکڑے_allocated = s->انکڑے_وتھ = 0;
}

ST_FUNC فراغ tccelf_delete(TCCState *s1)
{
    صحيح i;

#جے_بنا_تعریف ELF_OBJ_ONLY
    /* free symbol versions */
    لكل (i = 0; i < nb_sym_versions; i++) {
        tcc_free(sym_versions[i].نسخہ);
        tcc_free(sym_versions[i].lib);
    }
    tcc_free(sym_versions);
    tcc_free(sym_منزل_نسخہ);
#جے_انت

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
        s->sh_وتھ = s->انکڑے_وتھ;
    }
    /* disable symbol hashing during compilation */
    s = s1->symtab, s->reloc = s->hash, s->hash = عدم;
#إذا defined TCC_نشانہ_X86_64 && defined TCC_نشانہ_PE
    s1->uw_sym = 0;
    s1->uw_offs = 0;
#جے_انت
}

ساكن فراغ update_relocs(TCCState *s1, Section *s, صحيح *old_منزل_new_syms, صحيح پہلا_sym);

/* At the end of compilation, convert any UNDEF syms to global, and merge
   with previously existing symbols */
ST_FUNC فراغ tccelf_سرا_file(TCCState *s1)
{
    Section *s = s1->symtab;
    صحيح پہلا_sym, nb_syms, *tr, i;

    پہلا_sym = s->sh_وتھ / حجم (ElfSym);
    nb_syms = s->انکڑے_وتھ / حجم (ElfSym) - پہلا_sym;
    s->انکڑے_وتھ = s->sh_وتھ;
    s->link->انکڑے_وتھ = s->link->sh_وتھ;
    s->hash = s->reloc, s->reloc = عدم;
    tr = tcc_mallocz(nb_syms * حجم *tr);

    لكل (i = 0; i < nb_syms; ++i) {
        ElfSym *sym = (ElfSym*)s->انکڑے + پہلا_sym + i;
        إذا (sym->st_shndx == SHN_UNDEF) {
            صحيح sym_bind = ELFW(ST_BIND)(sym->st_info);
            صحيح sym_type = ELFW(ST_TYPE)(sym->st_info);
            إذا (sym_bind == STB_LOCAL)
                sym_bind = STB_GLOBAL;
#جے_بنا_تعریف TCC_نشانہ_PE
            إذا (sym_bind == STB_GLOBAL && s1->output_type == TCC_OUTPUT_OBJ) {
                /* undefined symbols with STT_FUNC are confusing gnu ld when
                   linking statically to STT_GNU_IFUNC.  Keep TLS typed,
                   otherwise gnu ld rejects non-TLS refs to TLS definitions. */
                إذا (sym_type != STT_TLS)
                    sym_type = STT_NOTYPE;
            }
#جے_انت
            sym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
        }
        tr[i] = سیٹ_elf_sym(s, sym->st_قدر, sym->st_ناپ, sym->st_info,
            sym->st_other, sym->st_shndx, (حرف*)s->link->انکڑے + sym->st_name);
    }
    /* now update relocations */
    update_relocs(s1, s, tr, پہلا_sym);
    tcc_free(tr);
    /* record text/data/bss output for -bench info */
    لكل (i = 0; i < 4; ++i) {
        s = s1->sections[i + 1];
        s1->کل_output[i] += s->انکڑے_وتھ - s->sh_وتھ;
    }
}

ST_FUNC Section *new_section(TCCState *s1, ثابت حرف *name, صحيح sh_type, صحيح sh_flags)
{
    Section *sec;

    sec = tcc_mallocz(حجم(Section) + لڑی_لمبائی(name));
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
        sec->sh_addralign = PTR_ناپ;
        اكسر;
    حالة SHT_STRTAB:
        sec->sh_addralign = 1;
        اكسر;
    افتراضي:
        sec->sh_addralign =  PTR_ناپ; /* gcc/pcc default alignment */
        اكسر;
    }

    إذا (sh_flags & SHF_نجی) {
        dynarray_جوڑو(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } وإلا {
        sec->sh_عدد = s1->nb_sections;
        dynarray_جوڑو(&s1->sections, &s1->nb_sections, sec);
    }

    أرجع sec;
}

ST_FUNC فراغ init_symtab(Section *s)
{
    صحيح *ptr, nb_buckets = 1;
    put_elf_str(s->link, "");
    section_ptr_جوڑو(s, حجم (ElfW(Sym)));
    ptr = section_ptr_جوڑو(s->hash, (2 + nb_buckets + 1) * حجم(صحيح));
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
ST_FUNC فراغ section_realloc(Section *sec, بنانشانی لما new_ناپ)
{
    بنانشانی لما ناپ;
    بنانشانی حرف *انکڑے;

    ناپ = sec->انکڑے_allocated;
    إذا (ناپ == 0)
        ناپ = 1;
    طالما (ناپ < new_ناپ)
        ناپ = ناپ * 2;
    انکڑے = tcc_realloc(sec->انکڑے, ناپ);
    memset(انکڑے + sec->انکڑے_allocated, 0, ناپ - sec->انکڑے_allocated);
    sec->انکڑے = انکڑے;
    sec->انکڑے_allocated = ناپ;
}

/* reserve at least 'size' bytes aligned per 'align' in section
   'sec' from current offset, and return the aligned offset */
ST_FUNC ناپ_t section_جوڑو(Section *sec, addr_t ناپ, صحيح align)
{
    ناپ_t وتھ, offset1;

    وتھ = (sec->انکڑے_وتھ + align - 1) & -align;
    offset1 = وتھ + ناپ;
    إذا (sec->sh_type != SHT_NOBITS && offset1 > sec->انکڑے_allocated)
        section_realloc(sec, offset1);
    sec->انکڑے_وتھ = offset1;
    إذا (align > sec->sh_addralign)
        sec->sh_addralign = align;
    أرجع وتھ;
}

/* reserve at least 'size' bytes in section 'sec' from
   sec->data_offset. */
ST_FUNC فراغ *section_ptr_جوڑو(Section *sec, addr_t ناپ)
{
    ناپ_t وتھ = section_جوڑو(sec, ناپ, 1);
    أرجع sec->انکڑے + وتھ;
}

#جے_بنا_تعریف ELF_OBJ_ONLY
/* reserve at least 'size' bytes from section start */
ساكن فراغ section_reserve(Section *sec, بنانشانی لما ناپ)
{
    إذا (ناپ > sec->انکڑے_allocated)
        section_realloc(sec, ناپ);
    إذا (ناپ > sec->انکڑے_وتھ)
        sec->انکڑے_وتھ = ناپ;
}
#جے_انت

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
ST_FUNC Section *لبھو_section(TCCState *s1, ثابت حرف *name)
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
    صحيح وتھ, len;
    حرف *ptr;

    len = لڑی_لمبائی(sym) + 1;
    وتھ = s->انکڑے_وتھ;
    ptr = section_ptr_جوڑو(s, len);
    memmove(ptr, sym, len);
    أرجع وتھ;
}

/* elf symbol hashing function */
ساكن ElfW(لفظ_2) elf_hash(ثابت بنانشانی حرف *name)
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
ساكن فراغ rebuild_hash(Section *s, بنانشانی صحيح nb_buckets)
{
    ElfW(Sym) *sym;
    صحيح *ptr, *hash, nb_syms, sym_اشاریہ, h;
    بنانشانی حرف *strtab;

    strtab = s->link->انکڑے;
    nb_syms = s->انکڑے_وتھ / حجم(ElfW(Sym));

    إذا (!nb_buckets)
        nb_buckets = ((صحيح*)s->hash->انکڑے)[0];

    s->hash->انکڑے_وتھ = 0;
    ptr = section_ptr_جوڑو(s->hash, (2 + nb_buckets + nb_syms) * حجم(صحيح));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    memset(hash, 0, (nb_buckets + 1) * حجم(صحيح));
    ptr += nb_buckets + 1;

    sym = (ElfW(Sym) *)s->انکڑے + 1;
    لكل(sym_اشاریہ = 1; sym_اشاریہ < nb_syms; sym_اشاریہ++) {
        إذا (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            h = elf_hash(strtab + sym->st_name) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_اشاریہ;
        } وإلا {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}

/* return the symbol number */
ST_FUNC صحيح put_elf_sym(Section *s, addr_t قدر, بنانشانی لما ناپ,
    صحيح info, صحيح other, صحيح shndx, ثابت حرف *name)
{
    صحيح name_وتھ, sym_اشاریہ;
    صحيح nbuckets, h;
    ElfW(Sym) *sym;
    Section *hs;

    sym = section_ptr_جوڑو(s, حجم(ElfW(Sym)));
    إذا (name && name[0])
        name_وتھ = put_elf_str(s->link, name);
    وإلا
        name_وتھ = 0;
    /* XXX: endianness */
    sym->st_name = name_وتھ;
    sym->st_قدر = قدر;
    sym->st_ناپ = ناپ;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
    sym_اشاریہ = sym - (ElfW(Sym) *)s->انکڑے;
    hs = s->hash;
    إذا (hs) {
        صحيح *ptr, *ادھار;
        ptr = section_ptr_جوڑو(hs, حجم(صحيح));
        ادھار = (صحيح *)hs->انکڑے;
        /* only add global or weak symbols. */
        إذا (ELFW(ST_BIND)(info) != STB_LOCAL) {
            /* add another hashing entry */
            nbuckets = ادھار[0];
            h = elf_hash((بنانشانی حرف *)s->link->انکڑے + name_وتھ) % nbuckets;
            *ptr = ادھار[2 + h];
            ادھار[2 + h] = sym_اشاریہ;
            ادھار[1]++;
            /* we resize the hash table */
            hs->nb_hashed_syms++;
            إذا (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } وإلا {
            *ptr = 0;
            ادھار[1]++;
        }
    }
    أرجع sym_اشاریہ;
}

ST_FUNC صحيح لبھو_elf_sym(Section *s, ثابت حرف *name)
{
    ElfW(Sym) *sym;
    Section *hs;
    صحيح nbuckets, sym_اشاریہ, h;
    ثابت حرف *name1;

    hs = s->hash;
    إذا (!hs)
        أرجع 0;
    nbuckets = ((صحيح *)hs->انکڑے)[0];
    h = elf_hash((بنانشانی حرف *) name) % nbuckets;
    sym_اشاریہ = ((صحيح *)hs->انکڑے)[2 + h];
    طالما (sym_اشاریہ != 0) {
        sym = &((ElfW(Sym) *)s->انکڑے)[sym_اشاریہ];
        name1 = (حرف *) s->link->انکڑے + sym->st_name;
        إذا (!strcmp(name, name1))
            أرجع sym_اشاریہ;
        sym_اشاریہ = ((صحيح *)hs->انکڑے)[2 + nbuckets + sym_اشاریہ];
    }
    أرجع 0;
}

/* return elf symbol value, signal error if 'err' is nonzero, decorate
   name if FORC */
ST_FUNC addr_t get_sym_addr(TCCState *s1, ثابت حرف *name, صحيح err, صحيح forc)
{
    صحيح sym_اشاریہ;
    ElfW(Sym) *sym;
    حرف buf[256];
    إذا (forc && s1->leading_underscore
#جے_تعریف_شدہ TCC_نشانہ_PE
        /* win32-32bit stdcall symbols always have _ already */
        && !strchr(name, '@')
#جے_انت
        ) {
        buf[0] = '_';
        pstrcpy(buf + 1, حجم(buf) - 1, name);
        name = buf;
    }
    sym_اشاریہ = لبھو_elf_sym(s1->symtab, name);
    sym = &((ElfW(Sym) *)s1->symtab->انکڑے)[sym_اشاریہ];
    إذا (!sym_اشاریہ || sym->st_shndx == SHN_UNDEF) {
        إذا (err)
            tcc_error_noabort("%s not defined", name);
        أرجع (addr_t)-1;
    }
    أرجع sym->st_قدر;
}

/* return elf symbol value */
LIBTCCAPI فراغ *tcc_get_علامت(TCCState *s, ثابت حرف *name)
{
    addr_t addr = get_sym_addr(s, name, 0, 1);
    أرجع addr == -1 ? عدم : (فراغ*)(uintptr_t)addr;
}

LIBTCCAPI صحيح tcc_جوڑو_علامت(TCCState *s1, ثابت حرف *name, ثابت فراغ *val)
{
#جے_تعریف_شدہ TCC_نشانہ_PE
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
    سیٹ_global_sym(s1, name, عدم, (addr_t)(uintptr_t)val); /* NULL: SHN_ABS */
#جے_انت
    أرجع 0;
}

/* list elf symbol names and values */
ST_FUNC فراغ list_elf_symbols(TCCState *s, فراغ *ctx,
    فراغ (*علامت_cb)(فراغ *ctx, ثابت حرف *name, ثابت فراغ *val))
{
    ElfW(Sym) *sym;
    Section *symtab;
    صحيح sym_اشاریہ, سرا_sym;
    ثابت حرف *name;
    بنانشانی حرف sym_vis, sym_bind;

    symtab = s->symtab;
    سرا_sym = symtab->انکڑے_وتھ / حجم (ElfSym);
    لكل (sym_اشاریہ = 0; sym_اشاریہ < سرا_sym; ++sym_اشاریہ) {
        sym = &((ElfW(Sym) *)symtab->انکڑے)[sym_اشاریہ];
        إذا (sym->st_قدر) {
            name = (حرف *) symtab->link->انکڑے + sym->st_name;
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            sym_vis = ELFW(ST_VISIBILITY)(sym->st_other);
            إذا (sym_bind == STB_GLOBAL && sym_vis == STV_DEFAULT)
                علامت_cb(ctx, name, (فراغ*)(uintptr_t)sym->st_قدر);
        }
    }
}

/* list elf symbol names and values */
LIBTCCAPI فراغ tcc_list_symbols(TCCState *s, فراغ *ctx,
    فراغ (*علامت_cb)(فراغ *ctx, ثابت حرف *name, ثابت فراغ *val))
{
    list_elf_symbols(s, ctx, علامت_cb);
}

#جے_بنا_تعریف ELF_OBJ_ONLY
ساكن فراغ
نسخہ_جوڑو (TCCState *s1)
{
    صحيح i;
    ElfW(Sym) *sym;
    ElfW(Verneed) *vn = عدم;
    Section *symtab;
    صحيح sym_اشاریہ, سرا_sym, nb_versions = 2, nb_entries = 0;
    ElfW(Half) *versym;
    ثابت حرف *name;

    إذا (0 == nb_sym_versions)
        أرجع;
    versym_section = new_section(s1, ".gnu.version", SHT_GNU_versym, SHF_ALLOC);
    versym_section->sh_entsize = حجم(ElfW(Half));
    versym_section->link = s1->dynsym;

    /* add needed symbols */
    symtab = s1->dynsym;
    سرا_sym = symtab->انکڑے_وتھ / حجم (ElfSym);
    versym = section_ptr_جوڑو(versym_section, سرا_sym * حجم(ElfW(Half)));
    لكل (sym_اشاریہ = 1; sym_اشاریہ < سرا_sym; ++sym_اشاریہ) {
        صحيح dllindex, verndx;
        sym = &((ElfW(Sym) *)symtab->انکڑے)[sym_اشاریہ];
        name = (حرف *) symtab->link->انکڑے + sym->st_name;
        dllindex = لبھو_elf_sym(s1->dynsymtab_section, name);
        verndx = (dllindex && dllindex < nb_sym_منزل_نسخہ)
                 ? sym_منزل_نسخہ[dllindex] : -1;
        إذا (verndx >= 0
            /* XXX: on android, clang refuses to link with a libtcc.so made by tcc
               when defined symbols have a version > 1 or when the version is '0'.
               Whereas version '1' for example for 'signal' in an exe defeats
               bcheck's signal_redir. */
            && (sym->st_shndx == SHN_UNDEF || (s1->output_type & TCC_OUTPUT_EXE))
            ) {
            إذا (!sym_versions[verndx].باہرلا_اشاریہ)
              sym_versions[verndx].باہرلا_اشاریہ = nb_versions++;
            versym[sym_اشاریہ] = sym_versions[verndx].باہرلا_اشاریہ;
        } وإلا {
            versym[sym_اشاریہ] = 1; /* (*global*) */
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
            بنية sym_نسخہ *sv = &sym_versions[i];
            صحيح n_same_libs = 0, prev;
            ناپ_t vnofs;
            ElfW(Vernaux) *vna = 0;
            إذا (sv->باہرلا_اشاریہ < 1)
              استمر;

            /* make sure that a DT_NEEDED tag is put */
            /* abitest-tcc fails on older i386-linux with "ld-linux.so.2" DT_NEEDED
               ret_int_test... Inconsistency detected by ld.so: dl-minimal.c: 148:
               realloc: Assertion `ptr == alloc_last_block' failed! */
            إذا (strcmp(sv->lib, "ld-linux.so.2"))
                tcc_جوڑو_dllref(s1, sv->lib, 0);

            vnofs = section_جوڑو(verneed_section, حجم(*vn), 1);
            vn = (ElfW(Verneed)*)(verneed_section->انکڑے + vnofs);
            vn->vn_نسخہ = 1;
            vn->vn_file = put_elf_str(verneed_section->link, sv->lib);
            vn->vn_aux = حجم (*vn);
            افعل {
                prev = sv->prev_same_lib;
                إذا (sv->باہرلا_اشاریہ > 0) {
                    vna = section_ptr_جوڑو(verneed_section, حجم(*vna));
                    vna->vna_hash = elf_hash ((ثابت بنانشانی حرف *)sv->نسخہ);
                    vna->vna_flags = 0;
                    vna->vna_other = sv->باہرلا_اشاریہ;
                    sv->باہرلا_اشاریہ = -2;
                    vna->vna_name = put_elf_str(verneed_section->link, sv->نسخہ);
                    vna->vna_اگلا = حجم (*vna);
                    //printf("LIB %d %s %s\n", vna->vna_other, sv->lib, verneed_section->link->data + vna->vna_name);
                    n_same_libs++;
                }
                إذا (prev >= 0)
                  sv = &sym_versions[prev];
            } طالما(prev >= 0);
            vna->vna_اگلا = 0;
            vn = (ElfW(Verneed)*)(verneed_section->انکڑے + vnofs);
            vn->vn_cnt = n_same_libs;
            vn->vn_اگلا = حجم(*vn) + n_same_libs * حجم(*vna);
            nb_entries++;
        }
        إذا (vn)
          vn->vn_اگلا = 0;
        verneed_section->sh_info = nb_entries;
    }
    dt_verneednum = nb_entries;
}
#جے_انت /* ndef ELF_OBJ_ONLY */

/* catch .tbss also */
ساكن صحيح IS_BSS(TCCState *s1, صحيح ndx)
{
    أرجع ndx == SHN_COMMON
     || (ndx < s1->nb_sections
         && s1->sections[ndx]->sh_type == SHT_NOBITS);
}

/* add an elf symbol : check if it is already defined and patch
   it. Return symbol index. NOTE that sh_num can be SHN_UNDEF. */
ST_FUNC صحيح سیٹ_elf_sym(Section *s, addr_t قدر, بنانشانی لما ناپ,
                       صحيح info, صحيح other, صحيح shndx, ثابت حرف *name)
{
    TCCState *s1 = s->s1;
    ElfW(Sym) *esym;
    صحيح sym_bind, sym_اشاریہ, sym_type, esym_bind;
    بنانشانی حرف sym_vis, esym_vis, new_vis;

    sym_bind = ELFW(ST_BIND)(info);
    sym_type = ELFW(ST_TYPE)(info);
    sym_vis = ELFW(ST_VISIBILITY)(other);

    إذا (sym_bind != STB_LOCAL) {
        /* we search global or weak symbols */
        sym_اشاریہ = لبھو_elf_sym(s, name);
        إذا (!sym_اشاریہ)
            اذهب do_def;
        esym = &((ElfW(Sym) *)s->انکڑے)[sym_اشاریہ];
        إذا (esym->st_قدر == قدر && esym->st_ناپ == ناپ && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            أرجع sym_اشاریہ;
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
            } وإلا إذا (sym_vis == STV_HIDDEN || sym_vis == STV_اندرونی) {
                /* ignore hidden symbols after */
            } وإلا إذا (s->sh_flags & SHF_DYNSYM) {
                /* we accept that two DLL define the same symbol */
            } وإلا إذا (!IS_BSS(s1, shndx) && IS_BSS(s1, esym->st_shndx)) {
                /* data symbol gets precedence over common/bss */
                اذهب do_patch;
            } وإلا إذا (IS_BSS(s1, shndx)) {
                /* data symbol keeps precedence over common/bss */
	    } وإلا إذا (esym->st_other & ST_ASM_سیٹ) {
		/* If the existing symbol came from an asm .set
		   we can override.  */
		اذهب do_patch;
            } وإلا {
#إذا 0
                لکھو("new_bind=%x new_shndx=%x new_vis=%x old_bind=%x old_shndx=%x old_vis=%x\n",
                       sym_bind, shndx, new_vis, esym_bind, esym->st_shndx, esym_vis);
#جے_انت
                tcc_error_noabort("link symbol '%s' defined twice", name);
            }
        } وإلا {
            esym->st_other = other;
        do_patch:
            esym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
            esym->st_shndx = shndx;
            esym->st_قدر = قدر;
            esym->st_ناپ = ناپ;
        }
    } وإلا {
    do_def:
        sym_اشاریہ = put_elf_sym(s, قدر, ناپ,
                                ELFW(ST_INFO)(sym_bind, sym_type), other,
                                shndx, name);
    }
    أرجع sym_اشاریہ;
}

/* put relocation */
ST_FUNC فراغ put_elf_reloca(Section *symtab, Section *s, بنانشانی لما وتھ,
                            صحيح type, صحيح علامت, addr_t addend)
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
        sr->sh_info = s->sh_عدد;
        s->reloc = sr;
    }
    rel = section_ptr_جوڑو(sr, حجم(ElfW_Rel));
    rel->r_وتھ = وتھ;
    rel->r_info = ELFW(R_INFO)(علامت, type);
#إذا SHT_RELX == SHT_RELA
    rel->r_addend = addend;
#جے_انت
    إذا (SHT_RELX != SHT_RELA && addend)
        tcc_error_noabort("non-zero addend on REL architecture");
}

ST_FUNC فراغ put_elf_reloc(Section *symtab, Section *s, بنانشانی لما وتھ,
                           صحيح type, صحيح علامت)
{
    put_elf_reloca(symtab, s, وتھ, type, علامت, 0);
}

ST_FUNC بنية sym_attr *get_sym_attr(TCCState *s1, صحيح اشاریہ, صحيح alloc)
{
    صحيح n;
    بنية sym_attr *tab;

    إذا (اشاریہ >= s1->nb_sym_attrs) {
        إذا (!alloc)
            أرجع s1->sym_attrs;
        /* find immediately bigger power of 2 and reallocate array */
        n = 1;
        طالما (اشاریہ >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * حجم(*s1->sym_attrs));
        s1->sym_attrs = tab;
        memset(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * حجم(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    أرجع &s1->sym_attrs[اشاریہ];
}

ساكن فراغ update_relocs(TCCState *s1, Section *s, صحيح *old_منزل_new_syms, صحيح پہلا_sym)
{
    صحيح i, type, sym_اشاریہ;
    Section *sr;
    ElfW_Rel *rel;

    لكل(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        إذا (sr->sh_type == SHT_RELX && sr->link == s) {
            for_each_elem(sr, 0, rel, ElfW_Rel) {
                sym_اشاریہ = ELFW(R_SYM)(rel->r_info);
                type = ELFW(R_TYPE)(rel->r_info);
                إذا ((sym_اشاریہ -= پہلا_sym) < 0)
                    استمر; /* zero sym_index in reloc (can happen with asm) */
                sym_اشاریہ = old_منزل_new_syms[sym_اشاریہ];
                rel->r_info = ELFW(R_INFO)(sym_اشاریہ, type);
            }
        }
    }
}

/* In an ELF file symbol table, the local symbols must appear below
   the global and weak ones. Since TCC cannot sort it while generating
   the code, we must do it after. All the relocation tables are also
   modified to take into account the symbol table sorting */
ساكن فراغ ترتیب_دیو_syms(TCCState *s1, Section *s)
{
    صحيح *old_منزل_new_syms;
    ElfW(Sym) *new_syms;
    صحيح nb_syms, i;
    ElfW(Sym) *p, *q;

    nb_syms = s->انکڑے_وتھ / حجم(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * حجم(ElfW(Sym)));
    old_منزل_new_syms = tcc_malloc(nb_syms * حجم(صحيح));

    /* first pass for local symbols */
    p = (ElfW(Sym) *)s->انکڑے;
    q = new_syms;
    لكل(i = 0; i < nb_syms; i++) {
        إذا (ELFW(ST_BIND)(p->st_info) == STB_LOCAL) {
            old_منزل_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    /* save the number of local symbols in section header */
    إذا( s->sh_ناپ )    /* this 'if' makes IDA happy */
        s->sh_info = q - new_syms;

    /* then second pass for non local symbols */
    p = (ElfW(Sym) *)s->انکڑے;
    لكل(i = 0; i < nb_syms; i++) {
        إذا (ELFW(ST_BIND)(p->st_info) != STB_LOCAL) {
            old_منزل_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }

    /* we copy the new symbols to the old */
    حافظہ_نقل(s->انکڑے, new_syms, nb_syms * حجم(ElfW(Sym)));
    tcc_free(new_syms);

    update_relocs(s1, s, old_منزل_new_syms, 0);
    tcc_free(old_منزل_new_syms);
}

#جے_بنا_تعریف ELF_OBJ_ONLY
/* See: https://flapenguin.me/elf-dt-gnu-hash */
#تعریف_کرو	ELFCLASS_بٹ (PTR_ناپ * 8)

ساكن Section *create_gnu_hash(TCCState *s1)
{
    صحيح nb_syms, i, ndef, nbuckets, symoffset, bloom_ناپ, bloom_کھسکاؤ;
    ElfW(Sym) *p;
    Section *gnu_hash;
    Section *dynsym = s1->dynsym;
    Elf32_لفظ *ptr;

    gnu_hash = new_section(s1, ".gnu.hash", SHT_GNU_HASH, SHF_ALLOC);
    gnu_hash->link = dynsym->hash->link;

    nb_syms = dynsym->انکڑے_وتھ / حجم(ElfW(Sym));

    /* count def symbols */
    ndef = 0;
    p = (ElfW(Sym) *)dynsym->انکڑے;
    لكل(i = 0; i < nb_syms; i++, p++)
        ndef += p->st_shndx != SHN_UNDEF;

    /* calculate gnu hash sizes and fill header */
    nbuckets = ndef / 4 + 1;
    symoffset = nb_syms - ndef;
    bloom_کھسکاؤ = PTR_ناپ == 8 ? 6 : 5;
    bloom_ناپ = 1; /* must be power of two */
    طالما (ndef >= bloom_ناپ * (1 << (bloom_کھسکاؤ - 3)))
	bloom_ناپ *= 2;
    ptr = section_ptr_جوڑو(gnu_hash, 4 * 4 +
				    PTR_ناپ * bloom_ناپ +
				    nbuckets * 4 +
				    ndef * 4);
    ptr[0] = nbuckets;
    ptr[1] = symoffset;
    ptr[2] = bloom_ناپ;
    ptr[3] = bloom_کھسکاؤ;
    أرجع gnu_hash;
}

ساكن Elf32_لفظ elf_gnu_hash (ثابت بنانشانی حرف *name)
{
    Elf32_لفظ h = 5381;
    بنانشانی حرف c;

    طالما ((c = *name++))
        h = h * 33 + c;
    أرجع h;
}

ساكن فراغ update_gnu_hash(TCCState *s1, Section *gnu_hash)
{
    صحيح *old_منزل_new_syms;
    ElfW(Sym) *new_syms;
    صحيح nb_syms, i, nbuckets, bloom_ناپ, bloom_کھسکاؤ;
    ElfW(Sym) *p, *q;
    Section *vs;
    Section *dynsym = s1->dynsym;
    Elf32_لفظ *ptr, *buckets, *chain, *hash;
    بنانشانی صحيح *nextbuck;
    addr_t *bloom;
    بنانشانی حرف *strtab;
    بنية { صحيح پہلا, آخری; } *buck;

    strtab = dynsym->link->انکڑے;
    nb_syms = dynsym->انکڑے_وتھ / حجم(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * حجم(ElfW(Sym)));
    old_منزل_new_syms = tcc_malloc(nb_syms * حجم(صحيح));
    hash = tcc_malloc(nb_syms * حجم(Elf32_لفظ));
    nextbuck = tcc_malloc(nb_syms * حجم(صحيح));

    /* calculate hashes and copy undefs */
    p = (ElfW(Sym) *)dynsym->انکڑے;
    q = new_syms;
    لكل(i = 0; i < nb_syms; i++, p++) {
        إذا (p->st_shndx == SHN_UNDEF) {
            old_منزل_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
	وإلا
	    hash[i] = elf_gnu_hash(strtab + p->st_name);
    }

    ptr = (Elf32_لفظ *) gnu_hash->انکڑے;
    nbuckets = ptr[0];
    bloom_ناپ = ptr[2];
    bloom_کھسکاؤ = ptr[3];
    bloom = (addr_t *) (فراغ *) &ptr[4];
    buckets = (Elf32_لفظ*) (فراغ *) &bloom[bloom_ناپ];
    chain = &buckets[nbuckets];
    buck = tcc_malloc(nbuckets * حجم(*buck));

    إذا (gnu_hash->انکڑے_وتھ != 4 * 4 +
				 PTR_ناپ * bloom_ناپ +
				 nbuckets * 4 +
				 (nb_syms - (q - new_syms)) * 4)
	tcc_error_noabort ("gnu_hash size incorrect");

    /* find buckets */
    لكل(i = 0; i < nbuckets; i++)
	buck[i].پہلا = -1;

    p = (ElfW(Sym) *)dynsym->انکڑے;
    لكل(i = 0; i < nb_syms; i++, p++)
        إذا (p->st_shndx != SHN_UNDEF) {
	    صحيح بالٹی = hash[i] % nbuckets;

	    إذا (buck[بالٹی].پہلا == -1)
		buck[بالٹی].پہلا = buck[بالٹی].آخری = i;
	    وإلا {
		nextbuck[buck[بالٹی].آخری] = i;
		buck[بالٹی].آخری = i;
	    }
	}

    /* fill buckets/chains/bloom and sort symbols */
    p = (ElfW(Sym) *)dynsym->انکڑے;
    لكل(i = 0; i < nbuckets; i++) {
	صحيح cur = buck[i].پہلا;

	إذا (cur != -1) {
	    buckets[i] = q - new_syms;
	    لكل (;;) {
                old_منزل_new_syms[cur] = q - new_syms;
                *q++ = p[cur];
	        *chain++ = hash[cur] & ~1;
		bloom[(hash[cur] / ELFCLASS_بٹ) % bloom_ناپ] |=
		    (addr_t)1 << (hash[cur] % ELFCLASS_بٹ) |
		    (addr_t)1 << ((hash[cur] >> bloom_کھسکاؤ) % ELFCLASS_بٹ);
		إذا (cur == buck[i].آخری)
		    اكسر;
		cur = nextbuck[cur];
	    }
	    chain[-1] |= 1;
	}
    }

    حافظہ_نقل(dynsym->انکڑے, new_syms, nb_syms * حجم(ElfW(Sym)));
    tcc_free(new_syms);
    tcc_free(hash);
    tcc_free(buck);
    tcc_free(nextbuck);

    update_relocs(s1, dynsym, old_منزل_new_syms, 0);

    /* modify the versions */
    vs = versym_section;
    إذا (vs) {
	ElfW(Half) *newver, *versym = (ElfW(Half) *)vs->انکڑے;

	إذا (1/*versym*/) {
            newver = tcc_malloc(nb_syms * حجم(*newver));
	    لكل (i = 0; i < nb_syms; i++)
	        newver[old_منزل_new_syms[i]] = versym[i];
	    حافظہ_نقل(vs->انکڑے, newver, nb_syms * حجم(*newver));
	    tcc_free(newver);
	}
    }

    tcc_free(old_منزل_new_syms);

    /* rebuild hash */
    ptr = (Elf32_لفظ *) dynsym->hash->انکڑے;
    rebuild_hash(dynsym, ptr[0]);
}
#جے_انت /* ELF_OBJ_ONLY */

/* relocate symbol table, resolve undefined symbols if do_resolve is
   true and output error if undefined symbol. */
ST_FUNC فراغ relocate_syms(TCCState *s1, Section *symtab, صحيح do_resolve)
{
    ElfW(Sym) *sym;
    صحيح sym_bind, sh_عدد;
    ثابت حرف *name;

    for_each_elem(symtab, 1, sym, ElfW(Sym)) {
        sh_عدد = sym->st_shndx;
        إذا (sh_عدد == SHN_UNDEF) {
            إذا (do_resolve == 2) /* relocating dynsym */
                استمر;
            name = (حرف *) s1->symtab->link->انکڑے + sym->st_name;
            /* Use ld.so to resolve symbol for us (for tcc -run) */
            إذا (do_resolve) {
#إذا defined TCC_IS_NATIVE && !defined TCC_نشانہ_PE
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
#جے_تعریف_شدہ DEBUG_RELOC
		    لکھو ("relocate_sym: %s -> 0x%lx\n", name, sym->st_قدر);
#جے_انت
                    اذهب لبھیا;
                }
#جے_انت
            /* if dynamic symbol exist, it will be used in relocate_section */
            } وإلا إذا (s1->dynsym && لبھو_elf_sym(s1->dynsym, name))
                اذهب لبھیا;
            /* XXX: _fp_hw seems to be part of the ABI, so we ignore
               it */
            إذا (!strcmp(name, "_fp_hw"))
                اذهب لبھیا;
            /* only weak symbols are accepted to be undefined. Their
               value is zero */
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            إذا (sym_bind == STB_WEAK)
                sym->st_قدر = 0;
            وإلا
                tcc_error_noabort("unresolved reference to '%s'", name);

        } وإلا إذا (sh_عدد < SHN_LORESERVE) {
            /* add section base */
            sym->st_قدر += s1->sections[sym->st_shndx]->sh_addr;
        }
    لبھیا: ;
    }
}

/* relocate a given section (CPU dependent) by applying the relocations
   in the associated relocation section */
ساكن فراغ relocate_section(TCCState *s1, Section *s, Section *sr)
{
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    صحيح type, sym_اشاریہ;
    بنانشانی حرف *ptr;
    addr_t tgt, addr;
    صحيح is_dwarf = s->sh_عدد >= s1->dwlo && s->sh_عدد < s1->dwhi;

    qrel = (ElfW_Rel *)sr->انکڑے;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
	إذا (s->انکڑے == عدم) /* bss */
	    استمر;
        ptr = s->انکڑے + rel->r_وتھ;
        sym_اشاریہ = ELFW(R_SYM)(rel->r_info);
        sym = &((ElfW(Sym) *)symtab_section->انکڑے)[sym_اشاریہ];
        type = ELFW(R_TYPE)(rel->r_info);
        tgt = sym->st_قدر;
#إذا SHT_RELX == SHT_RELA
        tgt += rel->r_addend;
#جے_انت
        إذا (is_dwarf && type == R_انکڑے_32_DW
            && sym->st_shndx >= s1->dwlo && sym->st_shndx < s1->dwhi) {
            /* dwarf section relocation to each other */
            add32le(ptr, tgt - s1->sections[sym->st_shndx]->sh_addr);
            استمر;
        }
        addr = s->sh_addr + rel->r_وتھ;
        relocate(s1, rel, type, ptr, addr, tgt);
    }

#جے_بنا_تعریف ELF_OBJ_ONLY
    /* if the relocation is allocated, we change its symbol table */
    إذا (sr->sh_flags & SHF_ALLOC) {
        sr->link = s1->dynsym;
        إذا (s1->output_type & TCC_OUTPUT_DYN) {
            ناپ_t r = (uint8_t*)qrel - sr->انکڑے;
            إذا (حجم ((Stab_Sym*)0)->n_قدر < PTR_ناپ
                && 0 == strcmp(s->name, ".stab"))
                r = 0; /* cannot apply 64bit relocation to 32bit value */
            sr->انکڑے_وتھ = sr->sh_ناپ = r;
#جے_تعریف_شدہ CONFIG_TCC_PIE
            إذا (r && (s->sh_flags & SHF_EXECINSTR))
                tcc_warning("%d relocations to %s", (بنانشانی)(r / حجم *qrel), s->name);
#جے_انت
        }
    }
#جے_انت

#جے_تعریف_شدہ TCC_نشانہ_RISCV64
    dynarray_reset(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries);
#جے_انت
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
#جے_بنا_تعریف TCC_نشانہ_MACHO
        إذا (s != s1->got
            || s1->static_link
            || s1->output_type == TCC_OUTPUT_حافظہ)
#جے_انت
        {
            relocate_section(s1, s, sr);
        }
#جے_بنا_تعریف ELF_OBJ_ONLY
        إذا (sr->sh_flags & SHF_ALLOC) {
            ElfW_Rel *rel;
            /* relocate relocation table in 'sr' */
            for_each_elem(sr, 0, rel, ElfW_Rel)
                rel->r_وتھ += s->sh_addr;
        }
#جے_انت
    }
}

#جے_بنا_تعریف ELF_OBJ_ONLY
/* count the number of dynamic relocations so that we can reserve
   their space */
ساكن صحيح prepare_dynamic_rel(TCCState *s1, Section *sr)
{
    صحيح گنتی_2 = 0;
#إذا defined(TCC_نشانہ_I386) || defined(TCC_نشانہ_X86_64) || \
    defined(TCC_نشانہ_ARM) || defined(TCC_نشانہ_ARM64) || \
    defined(TCC_نشانہ_RISCV64)
    ElfW_Rel *rel;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
        صحيح sym_اشاریہ = ELFW(R_SYM)(rel->r_info);
        صحيح type = ELFW(R_TYPE)(rel->r_info);
        بدل(type) {
#إذا defined(TCC_نشانہ_I386)
        حالة R_386_32:
            إذا (!get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ
                && ((ElfW(Sym)*)symtab_section->انکڑے + sym_اشاریہ)->st_shndx == SHN_UNDEF) {
                /* don't fixup unresolved (weak) symbols */
                rel->r_info = ELFW(R_INFO)(sym_اشاریہ, R_386_RELATIVE);
                اكسر;
            }
#وإلاإذا defined(TCC_نشانہ_X86_64)
        حالة R_X86_64_32:
        حالة R_X86_64_32S:
        حالة R_X86_64_64:
#وإلاإذا defined(TCC_نشانہ_ARM)
        حالة R_ARM_ABS32:
        حالة R_ARM_TARGET1:
#وإلاإذا defined(TCC_نشانہ_ARM64)
        حالة R_AARCH64_ABS32:
        حالة R_AARCH64_ABS64:
#وإلاإذا defined(TCC_نشانہ_RISCV64)
        حالة R_RISCV_32:
        حالة R_RISCV_64:
#جے_انت
            گنتی_2++;
            اكسر;
#إذا defined(TCC_نشانہ_I386)
        حالة R_386_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->انکڑے)[sym_اشاریہ];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    إذا (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_اشاریہ, R_386_PLT32);
	        اكسر;
	    }
	}
#وإلاإذا defined(TCC_نشانہ_X86_64)
        حالة R_X86_64_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->انکڑے)[sym_اشاریہ];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    إذا (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_اشاریہ, R_X86_64_PLT32);
	        اكسر;
	    }
	}
#وإلاإذا defined(TCC_نشانہ_ARM64)
        حالة R_AARCH64_PREL32:
#جے_انت
            إذا (s1->output_type != TCC_OUTPUT_DLL)
                اكسر;
            إذا (get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ)
                گنتی_2++;
            اكسر;
        افتراضي:
            اكسر;
        }
    }
#جے_انت
    أرجع گنتی_2;
}
#جے_انت

#جے_تعریف_شدہ NEED_BUILD_GOT
ساكن صحيح build_got(TCCState *s1)
{
    /* if no got, then create it */
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    s1->got->sh_entsize = 4;
    /* keep space for _DYNAMIC pointer and two dummy got entries */
    section_ptr_جوڑو(s1->got, 3 * PTR_ناپ);
    أرجع سیٹ_elf_sym(symtab_section, 0, 0, ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
        0, s1->got->sh_عدد, "_GLOBAL_OFFSET_TABLE_");
}

/* Create a GOT and (for function call) a PLT entry corresponding to a symbol
   in s1->symtab. When creating the dynamic symbol table entry for the GOT
   relocation, use 'size' and 'info' for the corresponding symbol metadata.
   Returns the offset of the GOT or (if any) PLT entry. */
ساكن بنية sym_attr * put_got_اندراج(TCCState *s1, صحيح dyn_reloc_type,
                                       صحيح sym_اشاریہ)
{
    صحيح need_plt_اندراج;
    ثابت حرف *name;
    ElfW(Sym) *sym;
    بنية sym_attr *attr;
    بنانشانی got_وتھ;
    حرف plt_name[200];
    صحيح len;
    Section *s_rel;

    need_plt_اندراج = (dyn_reloc_type == R_JMP_تھاں);
    attr = get_sym_attr(s1, sym_اشاریہ, 1);

    /* In case a function is both called and its address taken 2 GOT entries
       are created, one for taking the address (GOT) and the other for the PLT
       entry (PLTGOT).  */
    إذا (need_plt_اندراج ? attr->plt_وتھ : attr->got_وتھ)
        أرجع attr;

    s_rel = s1->got;
    إذا (need_plt_اندراج) {
        إذا (!s1->plt) {
            s1->plt = new_section(s1, ".plt", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
            s1->plt->sh_entsize = 4;
        }
        s_rel = s1->plt;
    }

    /* create the GOT entry */
    got_وتھ = s1->got->انکڑے_وتھ;
    section_ptr_جوڑو(s1->got, PTR_ناپ);

    /* Create the GOT relocation that will insert the address of the object or
       function of interest in the GOT entry. This is a static relocation for
       memory output (dlsym will give us the address of symbols) and dynamic
       relocation otherwise (executable and DLLs). The relocation should be
       done lazily for GOT entry with *_JUMP_SLOT relocation type (the one
       associated to a PLT entry) but is currently done at load time for an
       unknown reason. */

    sym = &((ElfW(Sym) *) symtab_section->انکڑے)[sym_اشاریہ];
    name = (حرف *) symtab_section->link->انکڑے + sym->st_name;
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
	    put_elf_reloc(s1->dynsym, s1->got, got_وتھ, R_RELATIVE,
			  sym_اشاریہ);
	} وإلا {
	    إذا (0 == attr->dyn_اشاریہ)
                attr->dyn_اشاریہ = سیٹ_elf_sym(s1->dynsym, sym->st_قدر,
                                              sym->st_ناپ, sym->st_info, 0,
                                              sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s_rel, got_وتھ, dyn_reloc_type,
			  attr->dyn_اشاریہ);
	}
    } وإلا {
        put_elf_reloc(symtab_section, s1->got, got_وتھ, dyn_reloc_type,
                      sym_اشاریہ);
    }

    إذا (need_plt_اندراج) {
        attr->plt_وتھ = create_plt_اندراج(s1, got_وتھ, attr);

        /* create a symbol 'sym@plt' for the PLT jump vector */
        len = لڑی_لمبائی(name);
        إذا (len > حجم plt_name - 5)
            len = حجم plt_name - 5;
        حافظہ_نقل(plt_name, name, len);
        strcpy(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_وتھ, 0,
            ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0, s1->plt->sh_عدد, plt_name);
    } وإلا {
        attr->got_وتھ = got_وتھ;
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
    صحيح i, type, gotplt_اندراج, reloc_type, sym_اشاریہ;
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
            gotplt_اندراج = gotplt_اندراج_type(type);
            إذا (gotplt_اندراج == -1) {
                tcc_error_noabort ("Unknown relocation type for got: %d", type);
                استمر;
            }
            sym_اشاریہ = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->انکڑے)[sym_اشاریہ];

            إذا (gotplt_اندراج == NO_GOTPLT_اندراج) {
                استمر;
            }

            /* Automatically create PLT/GOT [entry] if it is an undefined
	       reference (resolved at runtime), or the symbol is absolute,
	       probably created by tcc_add_symbol, and thus on 64-bit
	       targets might be too far from application code.  */
            إذا (gotplt_اندراج == AUTO_GOTPLT_اندراج) {
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
			dynindex = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
			esym = (ElfW(Sym) *)s1->dynsym->انکڑے + dynindex;
			إذا (dynindex
			    && (ELFW(ST_TYPE)(esym->st_info) == STT_FUNC
				|| (ELFW(ST_TYPE)(esym->st_info) == STT_NOTYPE
				    && ELFW(ST_TYPE)(sym->st_info) == STT_FUNC)))
			    اذهب jmp_تھاں;
		    }
                } وإلا إذا (sym->st_shndx == SHN_ABS) {
                    إذا (sym->st_قدر == 0) /* from tcc_add_btstub() */
                        استمر;
#جے_بنا_تعریف TCC_نشانہ_ARM
                    إذا (PTR_ناپ != 8)
                        استمر;
#جے_انت
                    /* from tcc_add_symbol(): on 64 bit platforms these
                       need to go through .got */
                } وإلا
                    استمر;
            }

#جے_تعریف_شدہ TCC_نشانہ_I386
            إذا ((type == R_386_PLT32 || type == R_386_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		إذا (pass != 0)
		    استمر;
                rel->r_info = ELFW(R_INFO)(sym_اشاریہ, R_386_PC32);
                استمر;
            }
#جے_انت
#جے_تعریف_شدہ TCC_نشانہ_X86_64
            إذا ((type == R_X86_64_PLT32 || type == R_X86_64_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		إذا (pass != 0)
		    استمر;
                rel->r_info = ELFW(R_INFO)(sym_اشاریہ, R_X86_64_PC32);
                استمر;
            }
#جے_انت
            reloc_type = کوڈ_reloc(type);
            إذا (reloc_type == -1) {
                tcc_error_noabort ("Unknown relocation type: %d", type);
                استمر;
            }

            إذا (reloc_type != 0) {
        jmp_تھاں:
	        إذا (pass != 0)
                    استمر;
                reloc_type = R_JMP_تھاں;
            } وإلا {
	        إذا (pass != 1)
                    استمر;
                reloc_type = R_GLOB_DAT;
            }

            إذا (!s1->got)
                got_sym = build_got(s1);

            إذا (gotplt_اندراج == BUILD_GOT_ONLY)
                استمر;

            attr = put_got_اندراج(s1, reloc_type, sym_اشاریہ);

            إذا (reloc_type == R_JMP_تھاں)
                rel->r_info = ELFW(R_INFO)(attr->plt_sym, type);
        }
    }
    إذا (++pass < 2)
        اذهب redo;
    /* .rel.plt refers to .got actually */
    إذا (s1->plt && s1->plt->reloc)
        s1->plt->reloc->sh_info = s1->got->sh_عدد;
    إذا (got_sym) /* set size */
        ((ElfW(Sym)*)symtab_section->انکڑے)[got_sym].st_ناپ = s1->got->انکڑے_وتھ;
}
#جے_انت /* def NEED_BUILD_GOT */

ST_FUNC صحيح سیٹ_global_sym(TCCState *s1, ثابت حرف *name, Section *sec, addr_t offs)
{
    صحيح shn = sec ? sec->sh_عدد : offs || !name ? SHN_ABS : SHN_UNDEF;
    إذا (sec && offs == -1)
        offs = sec->انکڑے_وتھ;
    أرجع سیٹ_elf_sym(symtab_section, offs, 0,
        ELFW(ST_INFO)(name ? STB_GLOBAL : STB_LOCAL, STT_NOTYPE), 0, shn, name);
}

ساكن فراغ جوڑو_init_array_مقرر_کردا(TCCState *s1, ثابت حرف *section_name)
{
    Section *s;
    addr_t سرا_وتھ;
    حرف buf[1024];
    s = have_section(s1, section_name);
    إذا (!s || !(s->sh_flags & SHF_ALLOC)) {
        سرا_وتھ = 0;
        s = متن_section;
    } وإلا {
        سرا_وتھ = s->انکڑے_وتھ;
    }
    snprintf(buf, حجم(buf), "__%s_start", section_name + 1);
    سیٹ_global_sym(s1, buf, s, 0);
    snprintf(buf, حجم(buf), "__%s_end", section_name + 1);
    سیٹ_global_sym(s1, buf, s, سرا_وتھ);
}

ST_FUNC فراغ جوڑو_array (TCCState *s1, ثابت حرف *sec, صحيح c)
{
    Section *s;
    s = لبھو_section(s1, sec);
    s->sh_flags = shf_RELRO;
    s->sh_type = sec[1] == 'i' ? SHT_INIT_ARRAY : SHT_FINI_ARRAY;
    put_elf_reloc (s1->symtab, s, s->انکڑے_وتھ, R_انکڑے_PTR, c);
    section_ptr_جوڑو(s, PTR_ناپ);
}

#جے_تعریف_شدہ CONFIG_TCC_BCHECK
ST_FUNC فراغ tcc_جوڑو_bcheck(TCCState *s1)
{
    إذا (0 == s1->do_bounds_check)
        أرجع;
    section_ptr_جوڑو(bounds_section, حجم(addr_t));
}
#جے_انت

/* set symbol to STB_LOCAL and resolve. The point is to not export it as
   a dynamic symbol to allow so's to have one each with a different value. */
ساكن فراغ سیٹ_local_sym(TCCState *s1, ثابت حرف *name, Section *s, صحيح وتھ)
{
    صحيح c = لبھو_elf_sym(s1->symtab, name);
    إذا (c) {
        ElfW(Sym) *esym = (ElfW(Sym)*)s1->symtab->انکڑے + c;
        esym->st_info = ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE);
        esym->st_قدر = وتھ;
        esym->st_shndx = s->sh_عدد;
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

#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE
ساكن فراغ put_ptr(TCCState *s1, Section *s, صحيح offs)
{
    صحيح c;
    c = سیٹ_global_sym(s1, عدم, s, offs);
    s = انکڑے_section;
    put_elf_reloc (s1->symtab, s, s->انکڑے_وتھ, R_انکڑے_PTR, c);
    section_ptr_جوڑو(s, PTR_ناپ);
}

ST_FUNC فراغ tcc_جوڑو_btstub(TCCState *s1)
{
    Section *s;
    صحيح n, o, *p;
    CString cstr;
    ثابت حرف *__rt_info = &"___rt_info"[!s1->leading_underscore];

    s = انکڑے_section;
    /* Align to PTR_SIZE */
    section_جوڑو(s, 0, PTR_ناپ);
    o = s->انکڑے_وتھ;
    /* create a struct rt_context (see tccrun.c) */
    إذا (s1->dwarf) {
        put_ptr(s1, dwarf_سطر_section, 0);
        put_ptr(s1, dwarf_سطر_section, -1);
	إذا (s1->dwarf >= 5)
            put_ptr(s1, dwarf_سطر_str_section, 0);
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
    section_ptr_جوڑو(s, 3 * PTR_ناپ);

    إذا (s1->output_type == TCC_OUTPUT_حافظہ && 0 == s1->dwarf) {
        put_ptr(s1, متن_section, 0);
    } وإلا {
        /* prog_base : local nameless symbol with offset 0 at SHN_ABS */
        put_ptr(s1, عدم, 0);
#إذا defined TCC_نشانہ_MACHO
        /* adjust for __PAGEZERO */
        إذا (s1->dwarf == 0 && s1->output_type == TCC_OUTPUT_EXE)
            write64le(انکڑے_section->انکڑے + انکڑے_section->انکڑے_وتھ - PTR_ناپ,
	              (uint64_t)1 << 32);
#جے_انت
    }
    n = 3 * PTR_ناپ;
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
    إذا (s1->do_bounds_check) {
        put_ptr(s1, bounds_section, 0);
        n -= PTR_ناپ;
    }
#جے_انت
    section_ptr_جوڑو(s, n);
    p = section_ptr_جوڑو(s, 2 * حجم (صحيح));
    p[0] = s1->rt_عدد_callers;
    p[1] = s1->dwarf;
    // if (s->data_offset - o != 10*PTR_SIZE + 2*sizeof (int)) exit(99);

    إذا (s1->output_type == TCC_OUTPUT_حافظہ) {
        سیٹ_global_sym(s1, __rt_info, s, o);
        أرجع;
    }

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern void __bt_init(),__bt_exit(),__bt_init_dll();"
        "static void *__rt_info[];"
        "__attribute__((constructor)) static void __bt_init_rt(){");
#جے_تعریف_شدہ TCC_نشانہ_PE
    إذا (s1->output_type == TCC_OUTPUT_DLL)
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
        cstr_printf(&cstr, "__bt_init_dll(%d);", s1->do_bounds_check);
#وإلا
        cstr_printf(&cstr, "__bt_init_dll(0);");
#جے_انت
#جے_انت
    cstr_printf(&cstr, "__bt_init(__rt_info,%d);}",
        s1->output_type != TCC_OUTPUT_DLL);
    /* In case dlcose is called by application */
    cstr_printf(&cstr,
        "__attribute__((destructor)) static void __bt_exit_rt(){"
        "__bt_exit(__rt_info);}");
    tcc_compile_string_no_debug(s1, cstr.انکڑے);
    cstr_free(&cstr);
    سیٹ_local_sym(s1, __rt_info, s, o);
}
#جے_انت /* def CONFIG_TCC_BACKTRACE */

ساكن فراغ tcc_tcov_جوڑو_file(TCCState *s1, ثابت حرف *filename)
{
    CString cstr;
    فراغ *ptr;
    حرف wd[1024];

    إذا (tcov_section == عدم)
        أرجع;
    section_ptr_جوڑو(tcov_section, 1);
    write32le (tcov_section->انکڑے, tcov_section->انکڑے_وتھ);

    cstr_new (&cstr);
    إذا (filename[0] == '/')
        cstr_printf (&cstr, "%s.tcov", filename);
    وإلا {
        getcwd (wd, حجم(wd));
        cstr_printf (&cstr, "%s/%s.tcov", wd, filename);
    }
    ptr = section_ptr_جوڑو(tcov_section, cstr.ناپ + 1);
    strcpy((حرف *)ptr, cstr.انکڑے);
    unlink((حرف *)ptr);
#جے_تعریف_شدہ _WIN32
    normalize_slashes((حرف *)ptr);
#جے_انت
    cstr_free (&cstr);

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern char *__tcov_data[];"
        "extern void __store_test_coverage ();"
        "__attribute__((destructor)) static void __tcov_exit() {"
        "__store_test_coverage(__tcov_data);"
        "}");
    tcc_compile_string_no_debug(s1, cstr.انکڑے);
    cstr_free(&cstr);
    سیٹ_local_sym(s1, &"___tcov_data"[!s1->leading_underscore], tcov_section, 0);
}

#جے_تعریف_شدہ TCC_نشانہ_UNIX
/* add libc crt1/crti objects */
ST_FUNC فراغ tccelf_جوڑو_crtbegin(TCCState *s1)
{
#إذا TARGETOS_OpenBSD
    إذا (s1->output_type != TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crt0.o");
    إذا (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crtbeginS.o");
    وإلا
        tcc_جوڑو_crt(s1, "crtbegin.o");
#وإلاإذا TARGETOS_FreeBSD || TARGETOS_NetBSD
    إذا (s1->output_type != TCC_OUTPUT_DLL)
#إذا TARGETOS_FreeBSD
        tcc_جوڑو_crt(s1, "crt1.o");
#وإلا
        tcc_جوڑو_crt(s1, "crt0.o");
#جے_انت
    tcc_جوڑو_crt(s1, "crti.o");
    إذا (s1->static_link)
        tcc_جوڑو_crt(s1, "crtbeginT.o");
    وإلا إذا (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crtbeginS.o");
    وإلا
        tcc_جوڑو_crt(s1, "crtbegin.o");
#وإلاإذا TARGETOS_ANDROID
    إذا (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crtbegin_so.o");
    وإلا
        tcc_جوڑو_crt(s1, "crtbegin_dynamic.o");
#وإلا
    إذا (s1->output_type != TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crt1.o");
    tcc_جوڑو_crt(s1, "crti.o");
#جے_انت
}

ST_FUNC فراغ tccelf_جوڑو_crtend(TCCState *s1)
{
#إذا TARGETOS_OpenBSD
    إذا (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crtendS.o");
    وإلا
        tcc_جوڑو_crt(s1, "crtend.o");
#وإلاإذا TARGETOS_FreeBSD || TARGETOS_NetBSD
    إذا (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crtendS.o");
    وإلا
        tcc_جوڑو_crt(s1, "crtend.o");
    tcc_جوڑو_crt(s1, "crtn.o");
#وإلاإذا TARGETOS_ANDROID
    إذا (s1->output_type == TCC_OUTPUT_DLL)
        tcc_جوڑو_crt(s1, "crtend_so.o");
    وإلا
        tcc_جوڑو_crt(s1, "crtend_android.o");
#وإلا
    tcc_جوڑو_crt(s1, "crtn.o");
#جے_انت
}
#جے_انت /* TCC_TARGET_UNIX */

#جے_بنا_تعریف TCC_نشانہ_PE
/* add tcc runtime libraries */
ST_FUNC فراغ tcc_جوڑو_runtime(TCCState *s1)
{
    s1->filetype = 0;

#جے_تعریف_شدہ CONFIG_TCC_BCHECK
    tcc_جوڑو_bcheck(s1);
#جے_انت
    tcc_جوڑو_pragma_libs(s1);

    /* add libc */
    إذا (!s1->nostdlib) {
        صحيح lpthread = s1->option_pthread;

#جے_تعریف_شدہ CONFIG_TCC_BCHECK
        إذا (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    إذا (s1->output_type == TCC_OUTPUT_حافظہ)
                tcc_جوڑو_support(s1, "bcheck_run.o");
	    وإلا
                tcc_جوڑو_support(s1, "bcheck.o");
# إذا !(TARGETOS_OpenBSD || TARGETOS_NetBSD)
            tcc_جوڑو_library(s1, "dl");
# endif
            lpthread = 1;
        }
#جے_انت
#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE
        إذا (s1->do_backtrace) {
            إذا (s1->output_type & TCC_OUTPUT_EXE)
                tcc_جوڑو_support(s1, "bt-exe.o");
            إذا (s1->output_type != TCC_OUTPUT_DLL)
                tcc_جوڑو_support(s1, "bt-log.o");
            tcc_جوڑو_btstub(s1);
            lpthread = 1;
        }
#جے_انت
        إذا (lpthread)
            tcc_جوڑو_library(s1, "pthread");
        tcc_جوڑو_library(s1, "c");
#جے_تعریف_شدہ TCC_LIBGCC
        إذا (!s1->static_link) {
            إذا (TCC_LIBGCC[0] == '/')
                tcc_جوڑو_file(s1, TCC_LIBGCC);
            وإلا
                tcc_جوڑو_dll(s1, TCC_LIBGCC, AFF_PRINT_ERROR);
        }
#جے_انت
#إذا defined TCC_نشانہ_ARM && TARGETOS_FreeBSD
        tcc_جوڑو_library(s1, "gcc_s"); // unwind code
#جے_انت
        إذا (TCC_LIBTCC1[0]) {
            tcc_جوڑو_support(s1, TCC_LIBTCC1);
            tcc_جوڑو_library(s1, "c");
        }
#جے_بنا_تعریف TCC_نشانہ_MACHO
        إذا (s1->output_type != TCC_OUTPUT_حافظہ)
            tccelf_جوڑو_crtend(s1);
#جے_انت
    }
}
#جے_انت /* ndef TCC_TARGET_PE */

/* set _etext/_edata/_end  f=0:set  f=1:when_needed  f=2,3:just_update */
ساكن فراغ سیٹ_linker_sym(TCCState *s1, ثابت حرف *name, Section *sec, صحيح f)
{
    صحيح sym_اشاریہ, esym_اشاریہ, defined;
    ElfW(Sym) *sym, *esym;
    sym_اشاریہ = لبھو_elf_sym(symtab_section, name);
    sym = (ElfW(Sym) *)symtab_section->انکڑے + sym_اشاریہ;
    esym_اشاریہ = لبھو_elf_sym(s1->dynsymtab_section, name);
    esym = (ElfW(Sym) *)s1->dynsymtab_section->انکڑے + esym_اشاریہ;
    defined = sym->st_shndx != SHN_UNDEF
        || (esym->st_shndx != SHN_UNDEF && esym->st_ناپ);
    بدل (f) {
    حالة 1: /* old symbols w/o '_' */
        إذا (!(sym_اشاریہ || esym_اشاریہ) || defined)
            اكسر;
    حالة 0:
        إذا (defined) {
            tcc_warning("linker symbol '%s' already defined", name);
            اكسر;
        }
        sym_اشاریہ = سیٹ_global_sym(s1, name, sec, -1);
        get_sym_attr(s1, sym_اشاریہ, 1)->linker_sym = 1;
        اكسر;
    افتراضي: /* update (bss only) */
        إذا (get_sym_attr(s1, sym_اشاریہ, 0)->linker_sym)
            sym->st_قدر = sec->انکڑے_وتھ;
    }
#جے_بنا_تعریف ELF_OBJ_ONLY
    إذا (name[0] == '_')
        سیٹ_linker_sym(s1, name + 1, sec, f + 1);
#جے_انت
}

/* add various standard linker symbols (must be done after the
   sections are filled (for example after allocating common
   symbols)) */
ساكن فراغ tcc_جوڑو_linker_symbols(TCCState *s1)
{
    حرف buf[1024];
    صحيح i;
    Section *s;

    سیٹ_linker_sym(s1, "_etext", متن_section, 0);
    سیٹ_linker_sym(s1, "_edata", انکڑے_section, 0);
    سیٹ_linker_sym(s1, "_end", bss_section, 0);
#إذا TARGETOS_OpenBSD
    سیٹ_global_sym(s1, "__executable_start", عدم, ELF_شروع_ADDR);
#جے_انت

#جے_تعریف_شدہ TCC_نشانہ_RISCV64
    /* XXX should be .sdata+0x800, not .data+0x800 */
    سیٹ_global_sym(s1, "__global_pointer$", انکڑے_section, 0x800);
#جے_انت
    /* horrible new standard ldscript defines */
    جوڑو_init_array_مقرر_کردا(s1, ".preinit_array");
    جوڑو_init_array_مقرر_کردا(s1, ".init_array");
    جوڑو_init_array_مقرر_کردا(s1, ".fini_array");
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
                    اذهب اگلا_sec;
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

ST_FUNC فراغ resolve_common_syms(TCCState *s1)
{
    ElfW(Sym) *sym;

    /* Allocate common symbols in BSS.  */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        إذا (sym->st_shndx == SHN_COMMON && sym->st_ناپ) {
            /* symbol alignment is in st_value for SHN_COMMONs */
	    sym->st_قدر = section_جوڑو(bss_section, sym->st_ناپ,
					sym->st_قدر);
            sym->st_shndx = bss_section->sh_عدد;
        }
    }

    /* Now assign linker provided symbols their value.  */
    إذا (s1->output_type != TCC_OUTPUT_DLL)
        tcc_جوڑو_linker_symbols(s1);
}

#جے_بنا_تعریف ELF_OBJ_ONLY
ST_FUNC فراغ fill_got_اندراج(TCCState *s1, ElfW_Rel *rel)
{
    صحيح sym_اشاریہ = ELFW(R_SYM) (rel->r_info);
    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->انکڑے)[sym_اشاریہ];
    بنية sym_attr *attr = get_sym_attr(s1, sym_اشاریہ, 0);
    بنانشانی وتھ = attr->got_وتھ;

    إذا (0 == وتھ)
        أرجع;
    section_reserve(s1->got, وتھ + PTR_ناپ);
#إذا PTR_ناپ == 8
    write64le(s1->got->انکڑے + وتھ, sym->st_قدر);
#وإلا
    write32le(s1->got->انکڑے + وتھ, sym->st_قدر);
#جے_انت
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
                    fill_got_اندراج(s1, rel);
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
	    صحيح sym_اشاریہ = ELFW(R_SYM) (rel->r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->انکڑے)[sym_اشاریہ];
	    بنية sym_attr *attr = get_sym_attr(s1, sym_اشاریہ, 0);
	    بنانشانی وتھ = attr->got_وتھ;
	    إذا (وتھ != rel->r_وتھ - s1->got->sh_addr)
	        tcc_error_noabort("fill_local_got_entries: huh?");
	    rel->r_info = ELFW(R_INFO)(0, R_RELATIVE);
#إذا SHT_RELX == SHT_RELA
	    rel->r_addend = sym->st_قدر;
#وإلا
	    /* All our REL architectures also happen to be 32bit LE.  */
	    write32le(s1->got->انکڑے + وتھ, sym->st_قدر);
#جے_انت
	}
    }
}

/* Bind symbols of executable: resolve undefined symbols from exported symbols
   in shared libraries */
ساكن فراغ bind_exe_dynsyms(TCCState *s1, صحيح is_PIE)
{
    ثابت حرف *name;
    صحيح sym_اشاریہ, اشاریہ;
    ElfW(Sym) *sym, *esym;
    صحيح type;

    /* Resolve undefined symbols from dynamic symbols. When there is a match:
       - if STT_FUNC or STT_GNU_IFUNC symbol -> add it in PLT
       - if STT_OBJECT symbol -> add it in .bss section with suitable reloc */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        إذا (sym->st_shndx == SHN_UNDEF
            /* bss symbols may be initialized in the shared library */
            || sym->st_shndx == SHN_COMMON
            || sym->st_shndx == bss_section->sh_عدد) {
            name = (حرف *) symtab_section->link->انکڑے + sym->st_name;
            sym_اشاریہ = لبھو_elf_sym(s1->dynsymtab_section, name);
            esym = &((ElfW(Sym) *)s1->dynsymtab_section->انکڑے)[sym_اشاریہ];
            إذا (sym_اشاریہ && esym->st_shndx != SHN_UNDEF) {
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
		      = put_elf_sym(s1->dynsym, 0, esym->st_ناپ,
				    ELFW(ST_INFO)(STB_GLOBAL,STT_FUNC), 0, 0,
				    name);
		    صحيح اشاریہ = sym - (ElfW(Sym) *) symtab_section->انکڑے;
		    get_sym_attr(s1, اشاریہ, 1)->dyn_اشاریہ = dynindex;
                } وإلا إذا (type == STT_OBJECT) {
                    بنانشانی لما وتھ;
                    ElfW(Sym) *dynsym;
                    إذا (sym->st_shndx == bss_section->sh_عدد) {
                        وتھ = sym->st_قدر;
                    } وإلا {
                        وتھ = bss_section->انکڑے_وتھ;
                        /* XXX: which alignment ? */
                        وتھ = (وتھ + 16 - 1) & -16;
                        bss_section->انکڑے_وتھ = وتھ + esym->st_ناپ;
                    }
                    سیٹ_elf_sym (s1->symtab, وتھ, esym->st_ناپ,
                                 esym->st_info, 0, bss_section->sh_عدد, name);
                    اشاریہ = put_elf_sym(s1->dynsym, وتھ, esym->st_ناپ,
                                        esym->st_info, 0, bss_section->sh_عدد,
                                        name);
                    /* Ensure R_COPY works for weak symbol aliases */
                    إذا (ELFW(ST_BIND)(esym->st_info) == STB_WEAK) {
                        for_each_elem(s1->dynsymtab_section, 1, dynsym, ElfW(Sym)) {
                            إذا ((dynsym->st_قدر == esym->st_قدر)
                                && (ELFW(ST_BIND)(dynsym->st_info) == STB_GLOBAL)) {
                                حرف *dynname = (حرف *) s1->dynsymtab_section->link->انکڑے
                                                + dynsym->st_name;
                                put_elf_sym(s1->dynsym, وتھ, dynsym->st_ناپ,
                                            dynsym->st_info, 0,
                                            bss_section->sh_عدد, dynname);
                                اكسر;
                            }
                        }
                    }
                    put_elf_reloc(s1->dynsym, bss_section,
                                  وتھ, R_COPY, اشاریہ);
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
    سیٹ_linker_sym(s1, "_end", bss_section, 2);
}

/* Bind symbols of libraries: export all non local symbols of executable that
   are referenced by shared libraries. The reason is that the dynamic loader
   search symbol first in executable and then in libraries. Therefore a
   reference to a symbol already defined by a library can still be resolved by
   a symbol in the executable.   With -rdynamic, export all defined symbols */
ساكن فراغ bind_libs_dynsyms(TCCState *s1)
{
    ثابت حرف *name;
    صحيح dynsym_اشاریہ;
    ElfW(Sym) *sym, *esym;

    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        name = (حرف *)symtab_section->link->انکڑے + sym->st_name;
        dynsym_اشاریہ = لبھو_elf_sym(s1->dynsymtab_section, name);
        إذا (sym->st_shndx != SHN_UNDEF) {
            إذا (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL
                && (dynsym_اشاریہ || s1->rdynamic))
                سیٹ_elf_sym(s1->dynsym, sym->st_قدر, sym->st_ناپ,
                            sym->st_info, 0, sym->st_shndx, name);
        } وإلا إذا (dynsym_اشاریہ) {
            esym = (ElfW(Sym) *)s1->dynsymtab_section->انکڑے + dynsym_اشاریہ;
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
    صحيح dynindex, اشاریہ;
    ثابت حرف *name;
    ElfW(Sym) *sym;
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        إذا (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
	    name = (حرف *) symtab_section->link->انکڑے + sym->st_name;
	    dynindex = سیٹ_elf_sym(s1->dynsym, sym->st_قدر, sym->st_ناپ,
				   sym->st_info, 0, sym->st_shndx, name);
	    اشاریہ = sym - (ElfW(Sym) *) symtab_section->انکڑے;
            get_sym_attr(s1, اشاریہ, 1)->dyn_اشاریہ = dynindex;
        }
    }
}

/* decide if an unallocated section should be output. */
ساكن صحيح سیٹ_sec_sizes(TCCState *s1)
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
                صحيح گنتی_2 = prepare_dynamic_rel(s1, s);
                إذا (گنتی_2) {
                    /* allocate the section */
                    s->sh_flags |= SHF_ALLOC;
                    s->sh_ناپ = گنتی_2 * حجم(ElfW_Rel);
                    إذا (s1->sections[s->sh_info]->sh_flags & SHF_EXECINSTR)
                        textrel += گنتی_2;
                }
            }
        } وإلا إذا ((s->sh_flags & SHF_ALLOC)
#جے_تعریف_شدہ TCC_نشانہ_ARM
                   || s->sh_type == SHT_ARM_گن
#جے_انت
                   || s1->do_debug) {
            s->sh_ناپ = s->انکڑے_وتھ;
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
        بنانشانی لما انکڑے_وتھ;
        addr_t rel_addr;
        addr_t rel_ناپ;
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
ساكن صحيح ترتیب_دیو_sections(TCCState *s1, صحيح *sec_ترتیب, بنية dyn_inf *d)
{
    Section *s;
    صحيح i, j, k, f, f0, n;
    صحيح nb_sections = s1->nb_sections;
    صحيح *sec_cls = sec_ترتیب + nb_sections;
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
            s->sh_ناپ = 0, j = 0x900;

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
            k = 0x50; /*انکڑے*/
        }
        k += j;
        /* make our standard sections come last to have _etext/_edata correct values */
        إذا (s->sh_عدد <= bss_section->sh_عدد)
            ++k;
        /* make RELRO section writable */
        إذا ((k & 0xfff0) == 0x140)
            k += 0x100, s->sh_flags |= SHF_WRITE;
        /* sort by insert */
        لكل (n = i; n > 1 && k < (f = sec_cls[n - 1]); --n)
            sec_cls[n] = f, sec_ترتیب[n] = sec_ترتیب[n - 1];
        sec_cls[n] = k, sec_ترتیب[n] = i;
    }
    sec_ترتیب[0] = 0;
    d->shnum = 1;

#تعریف_کرو SHFX_NEWPH (1 << 4)
#تعریف_کرو SHFX_RELRO (1 << 5)

    /* count PT_LOAD headers needed */
    n = f0 = 0;
    لكل (i = 1; i < nb_sections; i++) {
        s = s1->sections[sec_ترتیب[i]];
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
#جے_انت
            إذا ((k & 0xfff0) == 0x240) /* RELRO sections */
                d->relro = 1, f |= SHFX_RELRO;
            /* start new header when flags changed, but avoid zero memsz */
            إذا (f != f0 && s->sh_ناپ)
                f0 = f, ++n, f |= SHFX_NEWPH;
            إذا ((s->sh_flags & SHF_TLS) && s->sh_ناپ) {
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
        ph->p_وتھ = s->sh_وتھ;
        ph->p_vaddr = s->sh_addr;
        ph->p_filesz = s->sh_ناپ;
        ph->p_align = s->sh_addralign;
    }
    ph->p_paddr = ph->p_vaddr;
    ph->p_memsz = ph->p_filesz;
    أرجع ph;
}

ساكن ElfW(Phdr) *update_phdr(ElfW(Phdr) *ph, صحيح type, Section *s, addr_t addr, صحيح file_وتھ)
{
    إذا (ph->p_type == 0) {
        fill_phdr(ph, type, s);
    }
    ph->p_filesz = file_وتھ - ph->p_وتھ;
    ph->p_memsz = addr - ph->p_vaddr;
    أرجع ph;
}

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
ساكن صحيح layout_sections(TCCState *s1, صحيح *sec_ترتیب, بنية dyn_inf *d)
{
    Section *s;
    addr_t addr, tmp, align, s_align, ادھار;
    ElfW(Phdr) *ph = عدم, *ph2;
    صحيح i, f, n, phnum, phfill;
    صحيح file_وتھ;

    /* compute number of program headers */
    phnum = ترتیب_دیو_sections(s1, sec_ترتیب, d);
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
    إذا (eh_چوکھٹا_hdr_section)
        d->ehfr = phnum++;
    إذا (d->relro)
        d->relro = phnum++;
    d->phnum = phnum;
    d->phdr = tcc_mallocz(phnum * حجم(ElfW(Phdr)));

    file_وتھ = 0;
    إذا (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
        file_وتھ = (حجم(ElfW(Ehdr)) + phnum * حجم(ElfW(Phdr)) + 3) & -4;
        file_وتھ += d->shnum * حجم (ElfW(Shdr));
    }

    s_align = ELF_ورقہ_ناپ;
    إذا (s1->section_align)
        s_align = s1->section_align;

    addr = ELF_شروع_ADDR;
    إذا (s1->output_type & TCC_OUTPUT_DYN)
        addr = 0;

    إذا (s1->has_متن_addr) {
        addr = s1->متن_addr;
        إذا (0) {
            صحيح a_وتھ, p_وتھ;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_وتھ = (صحيح) (addr & (s_align - 1));
            p_وتھ = file_وتھ & (s_align - 1);
            إذا (a_وتھ < p_وتھ)
                a_وتھ += s_align;
            file_وتھ += (a_وتھ - p_وتھ);
        }
    }
    ادھار = addr;
    /* compute address after headers */
    addr += file_وتھ;

    n = 0;
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_ترتیب[i]];
        f = sec_ترتیب[i + s1->nb_sections];
        align = s->sh_addralign - 1;

        إذا (f == 0) { /* no alloc */
            file_وتھ = (file_وتھ + align) & ~align;
            s->sh_وتھ = file_وتھ;
            إذا (s->sh_type != SHT_NOBITS)
                file_وتھ += s->sh_ناپ;
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
        file_وتھ += (صحيح)(addr - tmp);
        s->sh_وتھ = file_وتھ;
        s->sh_addr = addr;

        //printf("%d : %08x %08x %04x %03x %s %d\n", n, (int)file_offset, (int)addr, (int)s->sh_size, s->sh_type, s->name, align + 1);
        addr += s->sh_ناپ;
        إذا (s->sh_type != SHT_NOBITS)
            file_وتھ += s->sh_ناپ;

        إذا (f & SHFX_NEWPH) {
            /* set new program header */
            ph = &d->phdr[phfill + n];
            fill_phdr(ph, PT_لدو, s);
            ph->p_align = s_align;
            إذا (f & SHF_EXECINSTR)
                ph->p_flags |= PF_X;
            إذا (n == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_وتھ = 0;
                ph->p_paddr = ph->p_vaddr = ادھار;
            }
            ++n;
        }

        إذا (ph)
            update_phdr(ph, 0, 0, addr, file_وتھ);

        إذا (f & SHFX_RELRO) {
            ph2 = update_phdr(&d->phdr[d->relro], PT_GNU_RELRO, s, addr, file_وتھ);
            ph2->p_align = 1;
        }
        إذا (f & SHF_TLS) {
            ph2 = update_phdr(&d->phdr[d->tls], PT_TLS, s, addr, file_وتھ);
            إذا (s->sh_type == SHT_NOBITS)
                addr -= s->sh_ناپ;
            /* for xxx-link.c:relocate() */
            s1->tls_شروع = ph2->p_vaddr;
            s1->tls_سرا = s1->tls_شروع + ph2->p_memsz + (-ph2->p_memsz & (ph2->p_align - 1));
        }
        إذا (s->sh_type == SHT_NOTE) {
            update_phdr(&d->phdr[d->notes], PT_NOTE, s, addr, file_وتھ);
        }
    }

    /* Fill other headers */
    إذا (d->dyna)
        fill_phdr(&d->phdr[d->dyna], PT_DYNAMIC, d->dynamic);
    إذا (d->ehfr)
        fill_phdr(&d->phdr[d->ehfr], PT_GNU_EH_چوکھٹا, eh_چوکھٹا_hdr_section);
    إذا (d->interp)
        fill_phdr(&d->phdr[1], PT_INTERP, d->interp);
    إذا (phfill) {
        ph = &d->phdr[0];
        ph->p_وتھ = حجم(ElfW(Ehdr));
        ph->p_vaddr = ادھار + ph->p_وتھ;
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
    dyn = section_ptr_جوڑو(dynamic, حجم(ElfW(Dyn)));
    dyn->d_ٹیگ = dt;
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
    put_dt(dynamic, DT_STRSZ, dyninf->dynstr->انکڑے_وتھ);
    put_dt(dynamic, DT_SYMENT, حجم(ElfW(Sym)));
#إذا PTR_ناپ == 8
    put_dt(dynamic, DT_RELA, dyninf->rel_addr);
    put_dt(dynamic, DT_RELASZ, dyninf->rel_ناپ);
    put_dt(dynamic, DT_RELAENT, حجم(ElfW_Rel));
    إذا (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->انکڑے_وتھ);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_RELA);
    }
    put_dt(dynamic, DT_RELACOUNT, 0);
#وإلا
    put_dt(dynamic, DT_REL, dyninf->rel_addr);
    put_dt(dynamic, DT_RELSZ, dyninf->rel_ناپ);
    put_dt(dynamic, DT_RELENT, حجم(ElfW_Rel));
    إذا (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->انکڑے_وتھ);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_REL);
    }
    put_dt(dynamic, DT_RELCOUNT, 0);
#جے_انت
    إذا (versym_section && verneed_section) {
	/* The dynamic linker can not handle VERSYM without VERNEED */
        put_dt(dynamic, DT_VERSYM, versym_section->sh_addr);
        put_dt(dynamic, DT_VERNEED, verneed_section->sh_addr);
        put_dt(dynamic, DT_VERNEEDNUM, dt_verneednum);
    }
    s = have_section(s1, ".preinit_array");
    إذا (s && s->انکڑے_وتھ) {
        put_dt(dynamic, DT_PREINIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_PREINIT_ARRAYSZ, s->انکڑے_وتھ);
    }
    s = have_section(s1, ".init_array");
    إذا (s && s->انکڑے_وتھ) {
        put_dt(dynamic, DT_INIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_INIT_ARRAYSZ, s->انکڑے_وتھ);
    }
    s = have_section(s1, ".fini_array");
    إذا (s && s->انکڑے_وتھ) {
        put_dt(dynamic, DT_FINI_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_FINI_ARRAYSZ, s->انکڑے_وتھ);
    }
    s = have_section(s1, ".init");
    إذا (s && s->انکڑے_وتھ) {
        put_dt(dynamic, DT_INIT, s->sh_addr);
    }
    s = have_section(s1, ".fini");
    إذا (s && s->انکڑے_وتھ) {
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
    بنانشانی لما file_وتھ = 0;
    Section *s;
    Section *relocplt = s1->plt ? s1->plt->reloc : عدم;

    /* dynamic relocation table information, for .dynamic section */
    dyninf->rel_addr = dyninf->rel_ناپ = 0;

    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
	إذا (s->sh_type == SHT_RELX && s != relocplt) {
	    إذا (dyninf->rel_ناپ == 0) {
		dyninf->rel_addr = s->sh_addr;
		file_وتھ = s->sh_وتھ;
	    }
	    وإلا {
		s->sh_addr = dyninf->rel_addr + dyninf->rel_ناپ;
		s->sh_وتھ = file_وتھ + dyninf->rel_ناپ;
	    }
	    dyninf->rel_ناپ += s->sh_ناپ;
	}
    }
}
#جے_انت /* ndef ELF_OBJ_ONLY */

/* Create an ELF file on disk.
   This function handle ELF specific layout requirements */
ساكن صحيح tcc_output_elf(TCCState *s1, FILE *f, صحيح phnum, ElfW(Phdr) *phdr)
{
    صحيح i, shnum, وتھ, ناپ, file_type;
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
#وإلاإذا defined TCC_نشانہ_ARM && defined TCC_ARM_EABI
    ehdr.e_flags = EF_ARM_EABI_VER5;
    ehdr.e_flags |= s1->float_abi == ARM_HARD_FLOAT
        ? EF_ARM_VFP_FLOAT : EF_ARM_SOFT_FLOAT;
#وإلاإذا defined TCC_نشانہ_ARM
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#وإلاإذا defined TCC_نشانہ_RISCV64
    /* XXX should be configurable */
    ehdr.e_flags = EF_RISCV_FLOAT_ABI_DOUBLE;
#جے_انت

    إذا (file_type == TCC_OUTPUT_OBJ) {
        ehdr.e_type = ET_REL;
    } وإلا {
        إذا (file_type & TCC_OUTPUT_DYN)
            ehdr.e_type = ET_DYN;
        وإلا
            ehdr.e_type = ET_EXEC;
        إذا (s1->elf_entryname)
            ehdr.e_اندراج = get_sym_addr(s1, s1->elf_entryname, 1, 0);
        وإلا
            ehdr.e_اندراج = get_sym_addr(s1, "_start", !!(file_type & TCC_OUTPUT_EXE), 0);
        إذا (ehdr.e_اندراج == (addr_t)-1)
            ehdr.e_اندراج = متن_section->sh_addr;
        إذا (s1->nb_errors)
            أرجع -1;
    }

    ترتیب_دیو_syms(s1, s1->symtab);

    ehdr.e_machine = EM_TCC_نشانہ;
    ehdr.e_نسخہ = EV_CURRENT;
    ehdr.e_shoff = (حجم(ElfW(Ehdr)) + phnum * حجم(ElfW(Phdr)) + 3) & -4;
    ehdr.e_ehsize = حجم(ElfW(Ehdr));
    ehdr.e_shentsize = حجم(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    وتھ = fwrite(&ehdr, 1, حجم(ElfW(Ehdr)), f);
    إذا (phdr)
        وتھ += fwrite(phdr, 1, phnum * حجم(ElfW(Phdr)), f);

    /* output section headers */
    طالما (وتھ < ehdr.e_shoff) {
        fputc(0, f);
        وتھ++;
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
                sh->sh_link = s->link->sh_عدد;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_وتھ = s->sh_وتھ;
            sh->sh_ناپ = s->sh_ناپ;
        }
        وتھ += fwrite(sh, 1, حجم(ElfW(Shdr)), f);
    }

    /* output sections */
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        إذا (s->sh_type != SHT_NOBITS) {
            طالما (وتھ < s->sh_وتھ) {
                fputc(0, f);
                وتھ++;
            }
            ناپ = s->sh_ناپ;
            إذا (ناپ)
                وتھ += fwrite(s->انکڑے, 1, ناپ, f);
        }
    }
    أرجع 0;
}

ساكن صحيح tcc_output_ثنائی(TCCState *s1, FILE *f)
{
    Section *s;
    صحيح i, وتھ, ناپ;

    وتھ = 0;
    لكل(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[i];
        إذا (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            طالما (وتھ < s->sh_وتھ) {
                fputc(0, f);
                وتھ++;
            }
            ناپ = s->sh_ناپ;
            fwrite(s->انکڑے, 1, ناپ, f);
            وتھ += ناپ;
        }
    }
    أرجع 0;
}

/* Write an elf, coff or "binary" file */
ساكن صحيح tcc_write_elf_file(TCCState *s1, ثابت حرف *filename, صحيح phnum,
                              ElfW(Phdr) *phdr)
{
    صحيح fd, منوال, file_type, ret;
    FILE *f;

    file_type = s1->output_type;
    إذا (file_type == TCC_OUTPUT_OBJ)
        منوال = 0666;
    وإلا
        منوال = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_ثنائی_2, منوال);
    إذا (fd < 0 || (f = fdopen(fd, "wb")) == عدم)
        أرجع tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
    إذا (s1->verbose)
        لکھو("<- %s\n", filename);
#جے_تعریف_شدہ TCC_نشانہ_COFF
    إذا (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    وإلا
#جے_انت
    إذا (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        ret = tcc_output_elf(s1, f, phnum, phdr);
    وإلا
        ret = tcc_output_ثنائی(s1, f);
    fclose(f);

    أرجع ret;
}

#جے_بنا_تعریف ELF_OBJ_ONLY
/* order sections according to sec_order, remove sections
   that we aren't going to output.  */
ساكن فراغ reorder_sections(TCCState *s1, صحيح *sec_ترتیب)
{
    صحيح i, nnew, k, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    backmap = tcc_malloc(s1->nb_sections * حجم(backmap[0]));
    لكل (i = 0, nnew = 0, snew = عدم; i < s1->nb_sections; i++) {
	k = sec_ترتیب ? sec_ترتیب[i] : i;
	s = s1->sections[k];
	إذا (!i || s->sh_name) {
	    backmap[k] = nnew;
            dynarray_جوڑو(&snew, &nnew, s);
	} وإلا {
	    backmap[k] = 0;
            /* just remember to free them later */
	    dynarray_جوڑو(&s1->priv_sections, &s1->nb_priv_sections, s);
	}
    }
    لكل (i = 1; i < nnew; i++) {
	s = snew[i];
        s->sh_عدد = i;
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

#جے_تعریف_شدہ TCC_نشانہ_ARM
ساكن فراغ create_arm_attribute_section(TCCState *s1)
{
   // Needed for DLL support.
    ساكن ثابت بنانشانی حرف arm_attr[] = {
        0x41,                            // 'A'
        0x2c, 0x00, 0x00, 0x00,          // size 0x2c
        'a', 'e', 'a', 'b', 'i', 0x00,   // "aeabi"
        0x01, 0x22, 0x00, 0x00, 0x00,    // 'File Attributes', size 0x22
        0x05, 0x36, 0x00,                // 'CPU_name', "6"
#إذا CONFIG_TCC_CPUVER >= 7
        0x06, 0x0a,                      // 'CPU_arch', 'v7'
#وإلا
        0x06, 0x06,                      // 'CPU_arch', 'v6'
#جے_انت
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
    Section *attr = new_section(s1, ".ARM.attributes", SHT_ARM_گن, 0);
    بنانشانی حرف *ptr = section_ptr_جوڑو(attr, حجم(arm_attr));
    attr->sh_addralign = 1;
    حافظہ_نقل(ptr, arm_attr, حجم(arm_attr));
    إذا (s1->float_abi != ARM_HARD_FLOAT) {
        ptr[26] = 0x00; // 'FP_arch', 'No'
        ptr[41] = 0x1e; // 'ABI_optimization_goals'
        ptr[42] = 0x06; // 'Aggressive Debug'
    }
}
#جے_انت

#جے_تعریف_شدہ TCC_نشانہ_RISCV64
ساكن فراغ create_riscv_attribute_section(TCCState *s1)
{
    ساكن ثابت بنانشانی حرف riscv_attr[] = {
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
    Section *attr = new_section(s1, ".riscv.attributes", SHT_RISCV_گن, 0);
    بنانشانی حرف *ptr = section_ptr_جوڑو(attr, حجم(riscv_attr));
    attr->sh_addralign = 1;
    حافظہ_نقل(ptr, riscv_attr, حجم(riscv_attr));
}
#جے_انت

#إذا TARGETOS_OpenBSD || TARGETOS_NetBSD || TARGETOS_FreeBSD

ساكن فراغ fill_bsd_note(Section *s, صحيح type,
			  ثابت حرف *قدر, uint32_t انکڑے)
{
    بنانشانی لما وتھ = 0;
    حرف *ptr;
    ElfW(Nhdr) *note;
    صحيح align = s->sh_addralign;

    /* check if type present */
    طالما (وتھ + حجم(ElfW(Nhdr)) < s->انکڑے_وتھ) {
        note = (ElfW(Nhdr) *) (s->انکڑے + وتھ);
	إذا (note->n_type == type)
	    أرجع;
	وتھ += (حجم(ElfW(Nhdr)) + note->n_namesz + note->n_descsz +
		  align - 1) & -align;
    }
    ptr = section_ptr_جوڑو(s, حجم(ElfW(Nhdr)) + 8 + 4);
    note = (ElfW(Nhdr) *) ptr;
    note->n_namesz = 8;
    note->n_descsz = 4;
    note->n_type = type;
    strcpy (ptr + حجم(ElfW(Nhdr)), قدر);
    حافظہ_نقل (ptr + حجم(ElfW(Nhdr)) + 8, &انکڑے, 4);
}

ساكن Section *create_bsd_note_section(TCCState *s1,
					ثابت حرف *name,
					ثابت حرف *قدر)
{
    Section *s;
    بنانشانی صحيح major = 0, minor = 0, patch = 0;

#جے_تعریف_شدہ CONFIG_OS_RELEASE
    لڑی_توں_پڑھو(CONFIG_OS_RELEASE, "%u.%u.%u", &major, &minor, &patch);
#جے_انت
#إذا TARGETOS_FreeBSD
    إذا (major < 14)
	أرجع عدم;
#جے_انت
    s = لبھو_section (s1, name);
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
#جے_انت
    أرجع s;
}
#جے_انت

ساكن فراغ alloc_sec_ناں(TCCState *s1, صحيح is_obj);

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
ساكن صحيح elf_output_file(TCCState *s1, ثابت حرف *filename)
{
    صحيح i, ret, file_type, *sec_ترتیب;
    بنية dyn_inf dyninf = {0};
    Section *interp, *dynstr, *dynamic;
    صحيح textrel, got_sym, dt_flags_1;

    file_type = s1->output_type;
    ret = -1;
    interp = dynstr = dynamic = عدم;
    sec_ترتیب = عدم;

#جے_تعریف_شدہ TCC_نشانہ_ARM
    create_arm_attribute_section (s1);
#جے_انت

#جے_تعریف_شدہ TCC_نشانہ_RISCV64
    create_riscv_attribute_section(s1);
#جے_انت

#إذا TARGETOS_OpenBSD
    dyninf.note = create_bsd_note_section (s1, ".note.openbsd.ident", "OpenBSD");
#جے_انت

#إذا TARGETOS_NetBSD
    dyninf.note = create_bsd_note_section (s1, ".note.netbsd.ident", "NetBSD");
#جے_انت

#إذا TARGETOS_FreeBSD
    dyninf.note = create_bsd_note_section (s1, ".note.tag", "FreeBSD");
#جے_انت

        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_جوڑو_runtime(s1);
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
                    اذهب the_سرا;
            }
            build_got_entries(s1, got_sym);
            إذا (file_type & TCC_OUTPUT_EXE) {
                bind_libs_dynsyms(s1);
            } وإلا {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
#إذا TCC_EH_چوکھٹا
	    /* fill with initial data */
	    tcc_eh_چوکھٹا_hdr(s1, 0);
#جے_انت
	    dyninf.gnu_hash = create_gnu_hash(s1);
        } وإلا {
            build_got_entries(s1, 0);
        }
	نسخہ_جوڑو (s1);

    textrel = سیٹ_sec_sizes(s1);

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
        dyninf.انکڑے_وتھ = dynamic->انکڑے_وتھ;
        fill_dynamic(s1, &dyninf);
        dynamic->sh_ناپ = dynamic->انکڑے_وتھ;
        dynstr->sh_ناپ = dynstr->انکڑے_وتھ;
    }

    /* create and fill .shstrtab section */
    alloc_sec_ناں(s1, 0);
    /* this array is used to reorder sections in the output file */
    sec_ترتیب = tcc_malloc(حجم(صحيح) * 2 * s1->nb_sections);
    /* compute section to program header mapping */
    layout_sections(s1, sec_ترتیب, &dyninf);

        إذا (dynamic) {
            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->انکڑے, dynamic->sh_addr);
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
            اذهب the_سرا;
        relocate_sections(s1);
        إذا (dynamic) {
	    update_reloc_sections (s1, &dyninf);
            dynamic->انکڑے_وتھ = dyninf.انکڑے_وتھ;
            fill_dynamic(s1, &dyninf);
	}
        /* Perform relocation to GOT or PLT entries */
        إذا (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        وإلا إذا (s1->got)
            fill_local_got_entries(s1);

    إذا (dyninf.gnu_hash)
        update_gnu_hash(s1, dyninf.gnu_hash);

    reorder_sections(s1, sec_ترتیب);
#إذا TCC_EH_چوکھٹا
    /* fill with final data */
    tcc_eh_چوکھٹا_hdr(s1, 1);
#جے_انت
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, dyninf.phnum, dyninf.phdr);
 the_سرا:
    tcc_free(sec_ترتیب);
    tcc_free(dyninf.phdr);
    أرجع ret;
}
#جے_انت /* ndef ELF_OBJ_ONLY */

/* Allocate strings for section names */
ساكن فراغ alloc_sec_ناں(TCCState *s1, صحيح is_obj)
{
    صحيح i;
    Section *s, *strsec;

    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        إذا (is_obj)
            s->sh_ناپ = s->انکڑے_وتھ;
	إذا (s->sh_ناپ || s == strsec || (s->sh_flags & SHF_ALLOC) || is_obj)
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_ناپ = strsec->انکڑے_وتھ;
}

/* Output an elf .o file */
ساكن صحيح elf_output_obj(TCCState *s1, ثابت حرف *filename)
{
    Section *s;
    صحيح i, ret, file_وتھ;
    /* Allocate strings for section names */
    alloc_sec_ناں(s1, 1);
    file_وتھ = (حجم (ElfW(Ehdr)) + 3) & -4;
    file_وتھ += s1->nb_sections * حجم(ElfW(Shdr));
    لكل(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        file_وتھ = (file_وتھ + 15) & -16;
        s->sh_وتھ = file_وتھ;
        إذا (s->sh_type != SHT_NOBITS)
            file_وتھ += s->sh_ناپ;
    }
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, 0, عدم);
    أرجع ret;
}

LIBTCCAPI صحيح tcc_output_file(TCCState *s, ثابت حرف *filename)
{
    s->nb_errors = 0;
    إذا (s->test_coverage)
        tcc_tcov_جوڑو_file(s, filename);
    إذا (s->output_type == TCC_OUTPUT_OBJ)
        أرجع elf_output_obj(s, filename);
#جے_تعریف_شدہ TCC_نشانہ_PE
    أرجع  pe_output_file(s, filename);
#وإلاإذا defined TCC_نشانہ_MACHO
    أرجع macho_output_file(s, filename);
#وإلا
    أرجع elf_output_file(s, filename);
#جے_انت
}

ST_FUNC ssize_t بھریا_read(صحيح fd, فراغ *buf, ناپ_t گنتی_2) {
    حرف *cbuf = buf;
    ناپ_t rnum = 0;
    طالما (1) {
        ssize_t عدد = اقرأ(fd, cbuf, گنتی_2-rnum);
        إذا (عدد < 0) أرجع عدد;
        إذا (عدد == 0) أرجع rnum;
        rnum += عدد;
        cbuf += عدد;
    }
}

ST_FUNC فراغ *لدو_انکڑے(صحيح fd, بنانشانی لما file_وتھ, بنانشانی لما ناپ)
{
    فراغ *انکڑے;

    انکڑے = tcc_malloc(ناپ);
    lseek(fd, file_وتھ, SEEK_SET);
    بھریا_read(fd, انکڑے, ناپ);
    أرجع انکڑے;
}

تعريفنوع بنية Section_ملاؤ_Info {
    Section *s;            /* corresponding existing section */
    بنانشانی لما وتھ;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} Section_ملاؤ_Info;

ST_FUNC صحيح tcc_object_type(صحيح fd, ElfW(Ehdr) *h)
{
    صحيح ناپ = بھریا_read(fd, h, حجم *h);
    إذا (ناپ == حجم *h && 0 == memcmp(h, ELFMAG, 4)) {
        إذا (h->e_type == ET_REL)
            أرجع AFF_BINTYPE_REL;
        إذا (h->e_type == ET_DYN)
            أرجع AFF_BINTYPE_DYN;
    } وإلا إذا (ناپ >= 8) {
        إذا (0 == memcmp(h, ARMAG, 8))
            أرجع AFF_BINTYPE_AR;
#جے_تعریف_شدہ TCC_نشانہ_COFF
        إذا (((بنية filehdr*)h)->f_magic == COFF_C67_MAGIC)
            أرجع AFF_BINTYPE_C67;
#جے_انت
    }
    أرجع 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC صحيح tcc_لدو_object_file(TCCState *s1,
                                صحيح fd, بنانشانی لما file_وتھ)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    بنانشانی لما ناپ, وتھ, offseti;
    صحيح i, j, nb_syms, sym_اشاریہ, ret, seencompressed;
    حرف *strsec, *strtab;
    صحيح stab_اشاریہ, stabstr_اشاریہ;
    صحيح *old_منزل_new_syms;
    حرف *sh_name, *name;
    Section_ملاؤ_Info *sm_جدول, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    lseek(fd, file_وتھ, SEEK_SET);
    إذا (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        اذهب invalid;
    /* test CPU specific stuff */
    إذا (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_نشانہ) {
invalid:
        أرجع tcc_error_noabort("invalid object file");
    }
    /* read sections */
    shdr = لدو_انکڑے(fd, file_وتھ + ehdr.e_shoff,
                     حجم(ElfW(Shdr)) * ehdr.e_shnum);
    sm_جدول = tcc_mallocz(حجم(Section_ملاؤ_Info) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = لدو_انکڑے(fd, file_وتھ + sh->sh_وتھ, sh->sh_ناپ);

    /* load symtab and strtab */
    old_منزل_new_syms = عدم;
    symtab = عدم;
    strtab = عدم;
    nb_syms = 0;
    seencompressed = 0;
    stab_اشاریہ = stabstr_اشاریہ = 0;
    ret = -1;

    لكل(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        إذا (sh->sh_type == SHT_SYMTAB) {
            إذا (symtab) {
                tcc_error_noabort("object must contain only one symtab");
                اذهب the_سرا;
            }
            nb_syms = sh->sh_ناپ / حجم(ElfW(Sym));
            symtab = لدو_انکڑے(fd, file_وتھ + sh->sh_وتھ, sh->sh_ناپ);
            sm_جدول[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = لدو_انکڑے(fd, file_وتھ + sh->sh_وتھ, sh->sh_ناپ);
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
        إذا (0 == لڑی_مقابلہ(sh_name, ".debug_", 7)
         || 0 == لڑی_مقابلہ(sh_name, ".stab", 5)) {
	    إذا (!s1->do_debug || seencompressed)
	        استمر;
#إذا !(TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD)
        } وإلا إذا (0 == لڑی_مقابلہ(sh_name, ".eh_frame", 9)) {
            إذا (عدم == eh_چوکھٹا_section)
                استمر;
#جے_انت
        } وإلا
        إذا (sh->sh_type != SHT_PROGBITS &&
            sh->sh_type != SHT_NOTE &&
            sh->sh_type != SHT_NOBITS &&
            sh->sh_type != SHT_PREINIT_ARRAY &&
            sh->sh_type != SHT_INIT_ARRAY &&
            sh->sh_type != SHT_FINI_ARRAY
#جے_تعریف_شدہ TCC_ARM_EABI
            /* Added in commit f99d3de221db23e322c6c18c8249282e27726c25
               but suppressed in 3cfaaaf1eb97d858e583412616f68f75fdad5da5
               So don't load it in order to avoid dangling references from
               (STT_SECTION) symbols. */
            // && sh->sh_type != SHT_ARM_EXIDX
#جے_انت

#إذا TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD
            && sh->sh_type != SHT_X86_64_UNWIND
#جے_انت
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
                اذهب the_سرا;
            }
            إذا (!لڑی_مقابلہ(sh_name, ".gnu.linkonce", 13)) {
                /* if a 'linkonce' section is already present, we
                   do not add it again. It is a little tricky as
                   symbols can still be defined in
                   it. */
                sm_جدول[i].link_once = 1;
                اذهب اگلا;
            }
            إذا (stab_section) {
                إذا (s == stab_section)
                    stab_اشاریہ = i;
                إذا (s == stab_section->link)
                    stabstr_اشاریہ = i;
            }
            اذهب لبھیا;
        }
        /* not found: create new section */
        s = new_section(s1, sh_name, sh->sh_type, sh->sh_flags & ~SHF_گروہ);
        /* take as much info as possible from the section. sh_link and
           sh_info will be updated later */
        s->sh_addralign = sh->sh_addralign;
        s->sh_entsize = sh->sh_entsize;
        sm_جدول[i].new_section = 1;
    لبھیا:
        ناپ = sh->sh_ناپ;
        /* align start of section */
        وتھ = section_جوڑو(s, ناپ, sh->sh_addralign);
        إذا (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        sm_جدول[i].وتھ = وتھ;
        sm_جدول[i].s = s;
        /* concatenate sections */
        إذا (sh->sh_type != SHT_NOBITS && ناپ) {
            بنانشانی حرف *ptr;
            lseek(fd, file_وتھ + sh->sh_وتھ, SEEK_SET);
            ptr = s->انکڑے + وتھ;
            بھریا_read(fd, ptr, ناپ);
        }
#إذا defined TCC_نشانہ_ARM || defined TCC_نشانہ_ARM64 || defined TCC_نشانہ_RISCV64
        /* align code sections to instruction lenght */
        /* This is needed if we compile a c file after this */
        إذا (s->sh_flags & SHF_EXECINSTR)
            section_جوڑو(s, 0, 4);
#جے_انت
    اگلا: ;
    }

    /* gr relocate stab strings */
    إذا (stab_اشاریہ && stabstr_اشاریہ) {
        Stab_Sym *a, *b;
        بنانشانی o;
        s = sm_جدول[stab_اشاریہ].s;
        a = (Stab_Sym *)(s->انکڑے + sm_جدول[stab_اشاریہ].وتھ);
        b = (Stab_Sym *)(s->انکڑے + s->انکڑے_وتھ);
        o = sm_جدول[stabstr_اشاریہ].وتھ;
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
            s->sh_info = sm_جدول[sh->sh_info].s->sh_عدد;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }

    إذا (!symtab)
        اذهب پورا;

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
                    sym_اشاریہ = لبھو_elf_sym(symtab_section, name);
                    إذا (sym_اشاریہ)
                        old_منزل_new_syms[i] = sym_اشاریہ;
                }
                استمر;
            }
            /* if no corresponding section added, no need to add symbol */
            إذا (!sm->s)
                استمر;
            /* convert section number */
            sym->st_shndx = sm->s->sh_عدد;
            /* offset value */
            sym->st_قدر += sm->وتھ;
        }
        /* add symbol */
        name = strtab + sym->st_name;
        sym_اشاریہ = سیٹ_elf_sym(symtab_section, sym->st_قدر, sym->st_ناپ,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_منزل_new_syms[i] = sym_اشاریہ;
    }

    /* third pass to patch relocation entries */
    لكل(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_جدول[i].s;
        إذا (!s)
            استمر;
        sh = &shdr[i];
        وتھ = sm_جدول[i].وتھ;
        ناپ = sh->sh_ناپ;
        بدل(s->sh_type) {
        حالة SHT_RELX:
            /* take relocation offset information */
            offseti = sm_جدول[sh->sh_info].وتھ;
	    لكل (rel = (ElfW_Rel *) s->انکڑے + (وتھ / حجم(*rel));
		 rel < (ElfW_Rel *) s->انکڑے + ((وتھ + ناپ) / حجم(*rel));
		 rel++) {
                صحيح type;
                بنانشانی sym_اشاریہ;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_اشاریہ = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                إذا (sym_اشاریہ >= nb_syms)
                    اذهب invalid_reloc;
                sym_اشاریہ = old_منزل_new_syms[sym_اشاریہ];
                /* ignore link_once in rel section. */
                إذا (!sym_اشاریہ && !sm_جدول[sh->sh_info].link_once
#جے_تعریف_شدہ TCC_نشانہ_ARM
                    && type != R_ARM_V4BX
#وإلاإذا defined TCC_نشانہ_RISCV64
                    && type != R_RISCV_ALIGN
                    && type != R_RISCV_RELAX
#جے_انت
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, (صحيح)rel->r_وتھ);
                    اذهب the_سرا;
                }
                rel->r_info = ELFW(R_INFO)(sym_اشاریہ, type);
                /* offset the relocation offset */
                rel->r_وتھ += offseti;
#جے_تعریف_شدہ TCC_نشانہ_ARM
                /* Jumps and branches from a Thumb code to a PLT entry need
                   special handling since PLT entries are ARM code.
                   Unconditional bl instructions referencing PLT entries are
                   handled by converting these instructions into blx
                   instructions. Other case of instructions referencing a PLT
                   entry require to add a Thumb stub before the PLT entry to
                   switch to ARM mode. We set bit plt_thumb_stub of the
                   attribute of a symbol to indicate such a case. */
                إذا (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_اشاریہ, 1)->plt_thumb_stub = 1;
#جے_انت
            }
            اكسر;
        افتراضي:
            اكسر;
        }
    }
 پورا:
    ret = !s1->nb_errors - 1; /* errors possibly from set_elf_sym() */
 the_سرا:
    tcc_free(symtab);
    tcc_free(strtab);
    tcc_free(old_منزل_new_syms);
    tcc_free(sm_جدول);
    tcc_free(strsec);
    tcc_free(shdr);
    أرجع ret;
}

تعريفنوع بنية Archive_سرخی {
    حرف ar_name[16];           /* name of this member */
    حرف ar_date[12];           /* file mtime */
    حرف ar_uid[6];             /* owner uid; printed as decimal */
    حرف ar_gid[6];             /* owner gid; printed as decimal */
    حرف ar_منوال[8];            /* file mode, printed as octal   */
    حرف ar_ناپ[10];           /* file size, printed as decimal */
    حرف ar_fmag[2];            /* should contain ARFMAG */
} Archive_سرخی;

#تعریف_کرو ARFMAG "`\n"

ساكن بنانشانی لما لما get_be(ثابت uint8_t *b, صحيح n)
{
    بنانشانی لما لما ret = 0;
    طالما (n)
        ret = (ret << 8) | *b++, --n;
    أرجع ret;
}

ساكن صحيح read_ar_سرخی(صحيح fd, صحيح وتھ, Archive_سرخی *hdr)
{
    حرف *p, *e;
    صحيح len;
    lseek(fd, وتھ, SEEK_SET);
    len = بھریا_read(fd, hdr, حجم(Archive_سرخی));
    إذا (len != حجم(Archive_سرخی))
        أرجع len ? -1 : 0;
    إذا (memcmp(hdr->ar_fmag, ARFMAG, حجم hdr->ar_fmag))
        أرجع -1;
    p = hdr->ar_name;
    لكل (e = p + حجم hdr->ar_name; e > p && e[-1] == ' ';)
        --e;
    *e = '\0';
    hdr->ar_ناپ[حجم hdr->ar_ناپ-1] = 0;
    أرجع len;
}

/* load only the objects which resolve undefined symbols */
ساكن صحيح tcc_لدو_alacarte(TCCState *s1, صحيح fd, صحيح ناپ, صحيح entrysize)
{
    صحيح i, bound, nsyms, sym_اشاریہ, len, ret = -1;
    بنانشانی لما لما off;
    uint8_t *انکڑے;
    ثابت حرف *ar_ناں, *p;
    ثابت uint8_t *ar_اشاریہ;
    ElfW(Sym) *sym;
    Archive_سرخی hdr;

    انکڑے = tcc_malloc(ناپ);
    إذا (بھریا_read(fd, انکڑے, ناپ) != ناپ)
        اذهب invalid;
    nsyms = get_be(انکڑے, entrysize);
    ar_اشاریہ = انکڑے + entrysize;
    ar_ناں = (حرف *) ar_اشاریہ + nsyms * entrysize;

    افعل {
        bound = 0;
        لكل (p = ar_ناں, i = 0; i < nsyms; i++, p += لڑی_لمبائی(p)+1) {
            Section *s = symtab_section;
            sym_اشاریہ = لبھو_elf_sym(s, p);
            إذا (!sym_اشاریہ)
                استمر;
            sym = &((ElfW(Sym) *)s->انکڑے)[sym_اشاریہ];
            إذا(sym->st_shndx != SHN_UNDEF)
                استمر;
            off = get_be(ar_اشاریہ + i * entrysize, entrysize);
            len = read_ar_سرخی(fd, off, &hdr);
            إذا (len <= 0 || memcmp(hdr.ar_fmag, ARFMAG, 2)) {
        invalid:
                tcc_error_noabort("invalid archive");
                اذهب the_سرا;
            }
            off += len;
            إذا (s1->verbose == 2)
                لکھو("   -> %s\n", hdr.ar_name);
            إذا (tcc_لدو_object_file(s1, fd, off) < 0)
                اذهب the_سرا;
            ++bound;
        }
    } طالما(bound);
    ret = 0;
 the_سرا:
    tcc_free(انکڑے);
    أرجع ret;
}

/* load a '.a' file */
ST_FUNC صحيح tcc_لدو_archive(TCCState *s1, صحيح fd, صحيح alacarte)
{
    Archive_سرخی hdr;
    /* char magic[8]; */
    صحيح ناپ, len;
    بنانشانی لما file_وتھ;
    ElfW(Ehdr) ehdr;

    /* skip magic which was already checked */
    /* full_read(fd, magic, sizeof(magic)); */
    file_وتھ = حجم ARMAG - 1;

    لكل(;;) {
        len = read_ar_سرخی(fd, file_وتھ, &hdr);
        إذا (len == 0)
            أرجع 0;
        إذا (len < 0)
            أرجع tcc_error_noabort("invalid archive");
        file_وتھ += len;
        ناپ = strtol(hdr.ar_ناپ, عدم, 0);
        إذا (alacarte) {
            /* coff symbol table : we handle it */
            إذا (!strcmp(hdr.ar_name, "/"))
                أرجع tcc_لدو_alacarte(s1, fd, ناپ, 4);
            إذا (!strcmp(hdr.ar_name, "/SYM64/"))
                أرجع tcc_لدو_alacarte(s1, fd, ناپ, 8);
        } وإلا إذا (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
            إذا (s1->verbose == 2)
                لکھو("   -> %s\n", hdr.ar_name);
            إذا (tcc_لدو_object_file(s1, fd, file_وتھ) < 0)
                أرجع -1;
        }
        /* align to even */
        file_وتھ = (file_وتھ + ناپ + 1) & ~1;
    }
}

#جے_بنا_تعریف ELF_OBJ_ONLY
/* Set LV[I] to the global index of sym-version (LIB,VERSION).  Maybe resizes
   LV, maybe create a new entry for (LIB,VERSION).  */
ساكن فراغ سیٹ_ver_منزل_ver(TCCState *s1, صحيح *n, صحيح **lv, صحيح i, حرف *lib, حرف *نسخہ)
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
            إذا (!strcmp(sym_versions[v].نسخہ, نسخہ))
              اكسر;
        }
        إذا (v == nb_sym_versions) {
            sym_versions = tcc_realloc (sym_versions,
                                        (v + 1) * حجم(*sym_versions));
            sym_versions[v].lib = tcc_strdup(lib);
            sym_versions[v].نسخہ = tcc_strdup(نسخہ);
            sym_versions[v].باہرلا_اشاریہ = 0;
            sym_versions[v].prev_same_lib = prev_same_lib;
            nb_sym_versions++;
        }
        (*lv)[i] = v;
    }
}

/* Associates symbol SYM_INDEX (in dynsymtab) with sym-version index
   VERNDX.  */
ساكن فراغ
سیٹ_sym_نسخہ(TCCState *s1, صحيح sym_اشاریہ, صحيح verndx)
{
    إذا (sym_اشاریہ >= nb_sym_منزل_نسخہ) {
        صحيح newelems = sym_اشاریہ ? sym_اشاریہ * 2 : 1;
        sym_منزل_نسخہ = tcc_realloc(sym_منزل_نسخہ,
                                     newelems * حجم(*sym_منزل_نسخہ));
        memset(sym_منزل_نسخہ + nb_sym_منزل_نسخہ, -1,
               (newelems - nb_sym_منزل_نسخہ) * حجم(*sym_منزل_نسخہ));
        nb_sym_منزل_نسخہ = newelems;
    }
    إذا (sym_منزل_نسخہ[sym_اشاریہ] < 0)
      sym_منزل_نسخہ[sym_اشاریہ] = verndx;
}

بنية versym_info {
    صحيح nb_versyms;
    ElfW(Verdef) *verdef;
    ElfW(Verneed) *verneed;
    ElfW(Half) *versym;
    صحيح nb_local_ver, *local_ver;
};


ساكن فراغ store_نسخہ(TCCState *s1, بنية versym_info *v, حرف *dynstr)
{
    حرف *lib, *نسخہ;
    uint32_t اگلا;
    صحيح i;

#تعریف_کرو	DEBUG_نسخہ 0

    إذا (v->versym && v->verdef) {
      ElfW(Verdef) *vdef = v->verdef;
      lib = عدم;
      افعل {
        ElfW(Verdaux) *verdaux =
	  (ElfW(Verdaux) *) (((حرف *) vdef) + vdef->vd_aux);

#إذا DEBUG_نسخہ
	لکھو ("verdef: version:%u flags:%u index:%u, hash:%u\n",
	        vdef->vd_نسخہ, vdef->vd_flags, vdef->vd_ndx,
		vdef->vd_hash);
#جے_انت
	إذا (vdef->vd_cnt) {
          نسخہ = dynstr + verdaux->vda_name;

	  إذا (lib == عدم)
	    lib = نسخہ;
	  وإلا
            سیٹ_ver_منزل_ver(s1, &v->nb_local_ver, &v->local_ver, vdef->vd_ndx,
                           lib, نسخہ);
#إذا DEBUG_نسخہ
	  لکھو ("  verdaux(%u): %s\n", vdef->vd_ndx, نسخہ);
#جے_انت
	}
        اگلا = vdef->vd_اگلا;
        vdef = (ElfW(Verdef) *) (((حرف *) vdef) + اگلا);
      } طالما (اگلا);
    }
    إذا (v->versym && v->verneed) {
      ElfW(Verneed) *vneed = v->verneed;
      افعل {
        ElfW(Vernaux) *vernaux =
	  (ElfW(Vernaux) *) (((حرف *) vneed) + vneed->vn_aux);

        lib = dynstr + vneed->vn_file;
#إذا DEBUG_نسخہ
	لکھو ("verneed: %u %s\n", vneed->vn_نسخہ, lib);
#جے_انت
	لكل (i = 0; i < vneed->vn_cnt; i++) {
	  إذا ((vernaux->vna_other & 0x8000) == 0) { /* hidden */
              نسخہ = dynstr + vernaux->vna_name;
              سیٹ_ver_منزل_ver(s1, &v->nb_local_ver, &v->local_ver, vernaux->vna_other,
                             lib, نسخہ);
#إذا DEBUG_نسخہ
	    لکھو ("  vernaux(%u): %u %u %s\n",
		    vernaux->vna_other, vernaux->vna_hash,
		    vernaux->vna_flags, نسخہ);
#جے_انت
	  }
	  vernaux = (ElfW(Vernaux) *) (((حرف *) vernaux) + vernaux->vna_اگلا);
	}
        اگلا = vneed->vn_اگلا;
        vneed = (ElfW(Verneed) *) (((حرف *) vneed) + اگلا);
      } طالما (اگلا);
    }

#إذا DEBUG_نسخہ
    لكل (i = 0; i < v->nb_local_ver; i++) {
      إذا (v->local_ver[i] > 0) {
        لکھو ("%d: lib: %s, version %s\n",
		i, sym_versions[v->local_ver[i]].lib,
                sym_versions[v->local_ver[i]].نسخہ);
      }
    }
#جے_انت
}

/* load a library / DLL
   'level = 0' means that the DLL is referenced by the user
   (so it should be added as DT_NEEDED in the generated ELF file) */
ST_FUNC صحيح tcc_لدو_dll(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    صحيح i, nb_syms, nb_dts, sym_bind, ret = -1;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;

    حرف *dynstr;
    صحيح sym_اشاریہ;
    ثابت حرف *name, *soname;
    بنية versym_info v;

    بھریا_read(fd, &ehdr, حجم(ehdr));

    /* test CPU specific stuff */
    إذا (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_نشانہ) {
        أرجع tcc_error_noabort("bad architecture");
    }

    /* read sections */
    shdr = لدو_انکڑے(fd, ehdr.e_shoff, حجم(ElfW(Shdr)) * ehdr.e_shnum);

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
            nb_dts = sh->sh_ناپ / حجم(ElfW(Dyn));
            dynamic = لدو_انکڑے(fd, sh->sh_وتھ, sh->sh_ناپ);
            اكسر;
        حالة SHT_DYNSYM:
            nb_syms = sh->sh_ناپ / حجم(ElfW(Sym));
            dynsym = لدو_انکڑے(fd, sh->sh_وتھ, sh->sh_ناپ);
            sh1 = &shdr[sh->sh_link];
            dynstr = لدو_انکڑے(fd, sh1->sh_وتھ, sh1->sh_ناپ);
            اكسر;
        حالة SHT_GNU_verdef:
	    v.verdef = لدو_انکڑے(fd, sh->sh_وتھ, sh->sh_ناپ);
	    اكسر;
        حالة SHT_GNU_verneed:
	    v.verneed = لدو_انکڑے(fd, sh->sh_وتھ, sh->sh_ناپ);
	    اكسر;
        حالة SHT_GNU_versym:
            v.nb_versyms = sh->sh_ناپ / حجم(ElfW(Half));
	    v.versym = لدو_انکڑے(fd, sh->sh_وتھ, sh->sh_ناپ);
	    اكسر;
        افتراضي:
            اكسر;
        }
    }

    إذا (!dynamic)
        اذهب the_سرا;

    /* compute the real library name */
    soname = tcc_basename(filename);
    لكل(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        إذا (dt->d_ٹیگ == DT_SONAME)
            soname = dynstr + dt->d_un.d_val;

    /* if the dll is already loaded, do not load it */
    إذا (tcc_جوڑو_dllref(s1, soname, level)->لبھیا)
        اذهب ret_success;

    إذا (v.nb_versyms != nb_syms)
        tcc_free (v.versym), v.versym = عدم;
    وإلا
        store_نسخہ(s1, &v, dynstr);

    /* add dynamic symbols in dynsym_section */
    لكل(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        إذا (sym_bind == STB_LOCAL)
            استمر;
        name = dynstr + sym->st_name;
        sym_اشاریہ = سیٹ_elf_sym(s1->dynsymtab_section, sym->st_قدر, sym->st_ناپ,
                                sym->st_info, sym->st_other, sym->st_shndx, name);
        إذا (v.versym) {
            ElfW(Half) vsym = v.versym[i];
            إذا ((vsym & 0x8000) == 0 && vsym > 0 && vsym < v.nb_local_ver)
                سیٹ_sym_نسخہ(s1, sym_اشاریہ, v.local_ver[vsym]);
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
        إذا (dt->d_ٹیگ == DT_RPATH)
            tcc_جوڑو_library_رستہ(s1, dynstr + dt->d_un.d_val);

    /* load all referenced DLLs */
    لكل(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        بدل(dt->d_ٹیگ) {
        حالة DT_NEEDED:
            name = dynstr + dt->d_un.d_val;
            إذا (tcc_جوڑو_dllref(s1, name, -1))
                استمر;
            إذا (tcc_جوڑو_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                ret = tcc_error_noabort("referenced dll '%s' not found", name);
                اذهب the_سرا;
            }
        }
    }
#جے_انت

 ret_success:
    ret = 0;
 the_سرا:
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

#تعریف_کرو LD_TOK_NAME 256
#تعریف_کرو LD_TOK_EOF  (-1)
ساكن صحيح ld_inp(TCCState *s1)
{
    صحيح c = *s1->ld_p;
    إذا (c == 0)
        أرجع CH_EOF;
    ++s1->ld_p;
    أرجع c;
}
#تعریف_کرو ld_unget(s1, ch) إذا (ch != CH_EOF) --s1->ld_p

/* return next ld script token */
ساكن صحيح ld_اگلا(TCCState *s1, حرف *name, صحيح name_ناپ)
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
            إذا ((q - name) < name_ناپ - 1) {
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

ساكن صحيح ld_جوڑو_file(TCCState *s1, ثابت حرف filename[])
{
    إذا (filename[0] == '-' && filename[1] == 'l')
        أرجع tcc_جوڑو_library(s1, filename + 2);
    إذا (CONFIG_SYSROOT[0] != '\0' || !IS_ABSPATH(filename)) {
        /* lookup via library paths */
        صحيح ret = tcc_جوڑو_dll(s1, tcc_basename(filename), 0);
        إذا (ret != FILE_NOT_لبھیا)
            أرجع ret;
    }
    أرجع tcc_جوڑو_file_اندرونی(s1, filename, AFF_PRINT_ERROR);
}

/* did static libraries add new undefined symbols? */
ساكن صحيح new_undef_sym(TCCState *s1, صحيح sym_وتھ)
{
    طالما (sym_وتھ < s1->symtab->انکڑے_وتھ) {
        ElfW(Sym) *esym = (فراغ*)(s1->symtab->انکڑے + sym_وتھ);
        إذا (esym->st_shndx == SHN_UNDEF)
            أرجع 1;
        sym_وتھ += حجم (ElfW(Sym));
    }
    أرجع 0;
}

ساكن صحيح ld_جوڑو_file_list(TCCState *s1, ثابت حرف *cmd)
{
    حرف filename[1024];
    صحيح t, c, sym_وتھ, ret = 0;
    بنانشانی حرف *pos = s1->ld_p;

repeat:
    s1->ld_p = pos;
    sym_وتھ = s1->symtab->انکڑے_وتھ;
    c = cmd[0];

    t = ld_اگلا(s1, filename, حجم(filename));
    إذا (t != '(')
        أرجع tcc_error_noabort("expected '(' after %s", cmd);
    t = ld_اگلا(s1, filename, حجم(filename));
    لكل(;;) {
        إذا (t == LD_TOK_EOF) {
            أرجع tcc_error_noabort("unexpected end of file");
        } وإلا إذا (t == ')') {
            اكسر;
        } وإلا إذا (t != LD_TOK_NAME) {
            أرجع tcc_error_noabort("unexpected token '%c'", t);
        } وإلا إذا (!strcmp(filename, "AS_NEEDED")) {
            ret |= ld_جوڑو_file_list(s1, filename);
        } وإلا إذا (c == 'I' || c == 'G' || c == 'A') {
            ret |= !!ld_جوڑو_file(s1, filename);
        }
        إذا (ret < 0)
            أرجع ret;
        t = ld_اگلا(s1, filename, حجم(filename));
        إذا (t == ',')
            t = ld_اگلا(s1, filename, حجم(filename));
    }
    إذا (c == 'G' && ret == 0 && new_undef_sym(s1, sym_وتھ))
        اذهب repeat;
    أرجع ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC صحيح tcc_لدو_ldscript(TCCState *s1, صحيح fd)
{
    حرف cmd[64];
    صحيح t, ret = 0, noscript = 1;
    بنانشانی حرف *متن_ptr, *saved_ptr;

    saved_ptr = s1->ld_p;
    s1->ld_p = متن_ptr = (فراغ*)tcc_لدو_متن(fd);
    لكل(;;) {
        t = ld_اگلا(s1, cmd, حجم(cmd));
        إذا (t == LD_TOK_EOF)
            اكسر;
        إذا (!strcmp(cmd, "INPUT") ||
            !strcmp(cmd, "GROUP")) {
            ret |= ld_جوڑو_file_list(s1, cmd);
        } وإلا إذا (!strcmp(cmd, "OUTPUT_FORMAT") ||
                   !strcmp(cmd, "TARGET")) {
            /* ignore some commands */
            ret |= ld_جوڑو_file_list(s1, cmd);
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
#جے_انت /* !ELF_OBJ_ONLY */
