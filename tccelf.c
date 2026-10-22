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

#അന്തര്ഭാവ "tcc.h"

/* Define this to get some debug output during relocation processing.  */
#undef DEBUG_RELOC

/********************************************************/
/* global variables */

/* elf version information */
ഘടന sym_version {
    അക്ഷരം *lib;
    അക്ഷരം *version;
    പൂർണ്ണസംഖ്യ out_index;
    പൂർണ്ണസംഖ്യ prev_same_lib;
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
സ്ഥിതം സ്ഥിരം അക്ഷരം rdata[] = ".rdata";
#അല്ലെങ്കിൽ
#define shf_RELRO SHF_ALLOC /* eventually made SHF_WRITE in sort_sections() */
സ്ഥിതം സ്ഥിരം അക്ഷരം rdata[] = ".data.ro";
#endif

/* ------------------------------------------------------------------------- */

ST_FUNC ശൂന്യം tccelf_new(TCCState *s)
{
    TCCState *s1 = s;

    /* no section zero */
    dynarray_add(&s->sections, &s->nb_sections, ശൂന്യ);

    /* create standard sections */
    text_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    data_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    /* create ro data section (make ro after relocation done with GNU_RELRO) */
    rodata_section = new_section(s, rdata, SHT_PROGBITS, shf_RELRO);
    bss_section = new_section(s, ".bss", SHT_NOBITS, SHF_ALLOC | SHF_WRITE);
    common_section = new_section(s, ".common", SHT_NOBITS, SHF_PRIVATE);
    common_section->sh_അക്കം = SHN_COMMON;

    /* symbols are always generated for linking stage */
    symtab_section = new_symtab(s, ".symtab", SHT_SYMTAB, 0,
                                ".strtab",
                                ".hashtab", SHF_PRIVATE);

    /* private symbol table for dynamic symbols */
    s->dynsymtab_section = new_symtab(s, ".dynsymtab", SHT_SYMTAB, SHF_PRIVATE|SHF_DYNSYM,
                                      ".dynstrtab",
                                      ".dynhashtab", SHF_PRIVATE);
    get_sym_attr(s, 0, 1);

    എങ്കിൽ (s->do_debug) {
        /* add debug sections */
        tcc_debug_new(s);
    }

#എങ്കിൽ TCC_EH_FRAME
    എങ്കിൽ (s->output_format != TCC_OUTPUT_FORMAT_ELF)
        s->unwind_tables = 0;
    tcc_eh_frame_start(s);
#endif

#ifdef CONFIG_TCC_BCHECK
    എങ്കിൽ (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        /* (make ro after relocation done with GNU_RELRO) */
        bounds_section = new_section(s, ".bounds", SHT_PROGBITS, shf_RELRO);
        lbounds_section = new_section(s, ".lbounds", SHT_PROGBITS, shf_RELRO);
    }
#endif

#ifdef TCC_TARGET_PE
    /* to make sure that -ltcc1 -Wl,-e,_start will grab the startup code
       from libtcc1.a (unless _start defined) */
    എങ്കിൽ (s->elf_entryname)
        set_global_sym(s, s->elf_entryname, ശൂന്യ, 0); /* SHN_UNDEF */
#endif

#ifndef ELF_OBJ_ONLY
    എങ്കിൽ (ശൂന്യ == s->elfint && s1->output_type != TCC_OUTPUT_OBJ) {
        സ്ഥിരം അക്ഷരം *p = CONFIG_TCC_ELFINTERP;
#എങ്കിൽ defined TCC_TARGET_ARM && defined CONFIG_TCC_ELFINTERP_ARMHF
        എങ്കിൽ (s->float_abi == ARM_HARD_FLOAT)
            p = CONFIG_TCC_ELFINTERP_ARMHF;
#endif
#എങ്കിൽ defined TCC_IS_NATIVE && defined TARGETOS_BSD
        /* see commit 55cb2170cd5ce77a7d76dcaf462fad2707281605 */
        { സ്ഥിരം അക്ഷരം *e = getenv("LD_SO"); എങ്കിൽ (e) p = e; }
#endif
        s->elfint = tcc_strdup(p);
    }
#endif /* ndef ELF_OBJ_ONLY */
}

ST_FUNC ശൂന്യം free_section(Section *s)
{
    എങ്കിൽ (!s)
        തിരികെ;
    tcc_free(s->data);
    s->data = ശൂന്യ;
    s->data_allocated = s->data_offset = 0;
}

ST_FUNC ശൂന്യം tccelf_delete(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ i;

#ifndef ELF_OBJ_ONLY
    /* free symbol versions */
    വേണ്ടി (i = 0; i < nb_sym_versions; i++) {
        tcc_free(sym_versions[i].version);
        tcc_free(sym_versions[i].lib);
    }
    tcc_free(sym_versions);
    tcc_free(sym_to_version);
#endif

    /* free all sections */
    വേണ്ടി(i = 1; i < s1->nb_sections; i++)
        free_section(s1->sections[i]);
    dynarray_reset(&s1->sections, &s1->nb_sections);

    വേണ്ടി(i = 0; i < s1->nb_priv_sections; i++)
        free_section(s1->priv_sections[i]);
    dynarray_reset(&s1->priv_sections, &s1->nb_priv_sections);

    tcc_free(s1->sym_attrs);
    symtab_section = ശൂന്യ; /* for tccrun.c:rt_printline() */
}

/* save section data state */
ST_FUNC ശൂന്യം tccelf_begin_file(TCCState *s1)
{
    Section *s; പൂർണ്ണസംഖ്യ i;
    വേണ്ടി (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        s->sh_offset = s->data_offset;
    }
    /* disable symbol hashing during compilation */
    s = s1->symtab, s->reloc = s->hash, s->hash = ശൂന്യ;
#എങ്കിൽ defined TCC_TARGET_X86_64 && defined TCC_TARGET_PE
    s1->uw_sym = 0;
    s1->uw_offs = 0;
#endif
}

സ്ഥിതം ശൂന്യം update_relocs(TCCState *s1, Section *s, പൂർണ്ണസംഖ്യ *old_to_new_syms, പൂർണ്ണസംഖ്യ first_sym);

/* At the end of compilation, convert any UNDEF syms to global, and merge
   with previously existing symbols */
ST_FUNC ശൂന്യം tccelf_end_file(TCCState *s1)
{
    Section *s = s1->symtab;
    പൂർണ്ണസംഖ്യ first_sym, nb_syms, *tr, i;

    first_sym = s->sh_offset / വലുപ്പം (ElfSym);
    nb_syms = s->data_offset / വലുപ്പം (ElfSym) - first_sym;
    s->data_offset = s->sh_offset;
    s->link->data_offset = s->link->sh_offset;
    s->hash = s->reloc, s->reloc = ശൂന്യ;
    tr = tcc_mallocz(nb_syms * വലുപ്പം *tr);

    വേണ്ടി (i = 0; i < nb_syms; ++i) {
        ElfSym *sym = (ElfSym*)s->data + first_sym + i;
        എങ്കിൽ (sym->st_shndx == SHN_UNDEF) {
            പൂർണ്ണസംഖ്യ sym_bind = ELFW(ST_BIND)(sym->st_info);
            പൂർണ്ണസംഖ്യ sym_type = ELFW(ST_TYPE)(sym->st_info);
            എങ്കിൽ (sym_bind == STB_LOCAL)
                sym_bind = STB_GLOBAL;
#ifndef TCC_TARGET_PE
            എങ്കിൽ (sym_bind == STB_GLOBAL && s1->output_type == TCC_OUTPUT_OBJ) {
                /* undefined symbols with STT_FUNC are confusing gnu ld when
                   linking statically to STT_GNU_IFUNC.  Keep TLS typed,
                   otherwise gnu ld rejects non-TLS refs to TLS definitions. */
                എങ്കിൽ (sym_type != STT_TLS)
                    sym_type = STT_NOTYPE;
            }
#endif
            sym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
        }
        tr[i] = set_elf_sym(s, sym->st_മൂല്യം, sym->st_size, sym->st_info,
            sym->st_other, sym->st_shndx, (അക്ഷരം*)s->link->data + sym->st_name);
    }
    /* now update relocations */
    update_relocs(s1, s, tr, first_sym);
    tcc_free(tr);
    /* record text/data/bss output for -bench info */
    വേണ്ടി (i = 0; i < 4; ++i) {
        s = s1->sections[i + 1];
        s1->total_output[i] += s->data_offset - s->sh_offset;
    }
}

ST_FUNC Section *new_section(TCCState *s1, സ്ഥിരം അക്ഷരം *name, പൂർണ്ണസംഖ്യ sh_type, പൂർണ്ണസംഖ്യ sh_flags)
{
    Section *sec;

    sec = tcc_mallocz(വലുപ്പം(Section) + strlen(name));
    sec->s1 = s1;
    strcpy(sec->name, name);
    sec->sh_type = sh_type;
    sec->sh_flags = sh_flags;
    തിരഞ്ഞെടുപ്പ്(sh_type) {
    അവസ്ഥ SHT_GNU_versym:
        sec->sh_addralign = 2;
        നിർത്തുക;
    അവസ്ഥ SHT_HASH:
    അവസ്ഥ SHT_GNU_HASH:
    അവസ്ഥ SHT_REL:
    അവസ്ഥ SHT_RELA:
    അവസ്ഥ SHT_DYNSYM:
    അവസ്ഥ SHT_SYMTAB:
    അവസ്ഥ SHT_DYNAMIC:
    അവസ്ഥ SHT_GNU_verneed:
    അവസ്ഥ SHT_GNU_verdef:
        sec->sh_addralign = PTR_SIZE;
        നിർത്തുക;
    അവസ്ഥ SHT_STRTAB:
        sec->sh_addralign = 1;
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        sec->sh_addralign =  PTR_SIZE; /* gcc/pcc default alignment */
        നിർത്തുക;
    }

    എങ്കിൽ (sh_flags & SHF_PRIVATE) {
        dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } അല്ലെങ്കിൽ {
        sec->sh_അക്കം = s1->nb_sections;
        dynarray_add(&s1->sections, &s1->nb_sections, sec);
    }

    തിരികെ sec;
}

ST_FUNC ശൂന്യം init_symtab(Section *s)
{
    പൂർണ്ണസംഖ്യ *ptr, nb_buckets = 1;
    put_elf_str(s->link, "");
    section_ptr_add(s, വലുപ്പം (ElfW(Sym)));
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + 1) * വലുപ്പം(പൂർണ്ണസംഖ്യ));
    ptr[0] = nb_buckets;
    ptr[1] = 1;
    memset(ptr + 2, 0, (nb_buckets + 1) * വലുപ്പം(പൂർണ്ണസംഖ്യ));
}

ST_FUNC Section *new_symtab(TCCState *s1,
                           സ്ഥിരം അക്ഷരം *symtab_name, പൂർണ്ണസംഖ്യ sh_type, പൂർണ്ണസംഖ്യ sh_flags,
                           സ്ഥിരം അക്ഷരം *strtab_name,
                           സ്ഥിരം അക്ഷരം *hash_name, പൂർണ്ണസംഖ്യ hash_sh_flags)
{
    Section *symtab, *strtab, *hash;
    symtab = new_section(s1, symtab_name, sh_type, sh_flags);
    symtab->sh_entsize = വലുപ്പം(ElfW(Sym));
    strtab = new_section(s1, strtab_name, SHT_STRTAB, sh_flags);
    symtab->link = strtab;
    hash = new_section(s1, hash_name, SHT_HASH, hash_sh_flags);
    hash->sh_entsize = വലുപ്പം(പൂർണ്ണസംഖ്യ);
    symtab->hash = hash;
    hash->link = symtab;
    init_symtab(symtab);
    തിരികെ symtab;
}

/* realloc section and set its content to zero */
ST_FUNC ശൂന്യം section_realloc(Section *sec, unsigned long new_size)
{
    unsigned long size;
    unsigned അക്ഷരം *data;

    size = sec->data_allocated;
    എങ്കിൽ (size == 0)
        size = 1;
    ആകുമ്പോൾ (size < new_size)
        size = size * 2;
    data = tcc_realloc(sec->data, size);
    memset(data + sec->data_allocated, 0, size - sec->data_allocated);
    sec->data = data;
    sec->data_allocated = size;
}

/* reserve at least 'size' bytes aligned per 'align' in section
   'sec' from current offset, and return the aligned offset */
ST_FUNC size_t section_add(Section *sec, addr_t size, പൂർണ്ണസംഖ്യ align)
{
    size_t offset, offset1;

    offset = (sec->data_offset + align - 1) & -align;
    offset1 = offset + size;
    എങ്കിൽ (sec->sh_type != SHT_NOBITS && offset1 > sec->data_allocated)
        section_realloc(sec, offset1);
    sec->data_offset = offset1;
    എങ്കിൽ (align > sec->sh_addralign)
        sec->sh_addralign = align;
    തിരികെ offset;
}

/* reserve at least 'size' bytes in section 'sec' from
   sec->data_offset. */
ST_FUNC ശൂന്യം *section_ptr_add(Section *sec, addr_t size)
{
    size_t offset = section_add(sec, size, 1);
    തിരികെ sec->data + offset;
}

#ifndef ELF_OBJ_ONLY
/* reserve at least 'size' bytes from section start */
സ്ഥിതം ശൂന്യം section_reserve(Section *sec, unsigned long size)
{
    എങ്കിൽ (size > sec->data_allocated)
        section_realloc(sec, size);
    എങ്കിൽ (size > sec->data_offset)
        sec->data_offset = size;
}
#endif

സ്ഥിതം Section *have_section(TCCState *s1, സ്ഥിരം അക്ഷരം *name)
{
    Section *sec;
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി(i = 1; i < s1->nb_sections; i++) {
        sec = s1->sections[i];
        എങ്കിൽ (!strcmp(name, sec->name))
            തിരികെ sec;
    }
    തിരികെ ശൂന്യ;
}

/* return a reference to a section, and create it if it does not
   exists */
ST_FUNC Section *find_section(TCCState *s1, സ്ഥിരം അക്ഷരം *name)
{
    Section *sec = have_section(s1, name);
    എങ്കിൽ (sec)
        തിരികെ sec;
    /* sections are created as PROGBITS */
    തിരികെ new_section(s1, name, SHT_PROGBITS, SHF_ALLOC);
}

/* ------------------------------------------------------------------------- */

ST_FUNC പൂർണ്ണസംഖ്യ put_elf_str(Section *s, സ്ഥിരം അക്ഷരം *sym)
{
    പൂർണ്ണസംഖ്യ offset, len;
    അക്ഷരം *ptr;

    len = strlen(sym) + 1;
    offset = s->data_offset;
    ptr = section_ptr_add(s, len);
    memmove(ptr, sym, len);
    തിരികെ offset;
}

/* elf symbol hashing function */
സ്ഥിതം ElfW(Word) elf_hash(സ്ഥിരം unsigned അക്ഷരം *name)
{
    ElfW(Word) h = 0, g;

    ആകുമ്പോൾ (*name) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        എങ്കിൽ (g)
            h ^= g >> 24;
        h &= ~g;
    }
    തിരികെ h;
}

/* rebuild hash table of section s */
/* NOTE: we do factorize the hash table code to go faster */
സ്ഥിതം ശൂന്യം rebuild_hash(Section *s, unsigned പൂർണ്ണസംഖ്യ nb_buckets)
{
    ElfW(Sym) *sym;
    പൂർണ്ണസംഖ്യ *ptr, *hash, nb_syms, sym_index, h;
    unsigned അക്ഷരം *strtab;

    strtab = s->link->data;
    nb_syms = s->data_offset / വലുപ്പം(ElfW(Sym));

    എങ്കിൽ (!nb_buckets)
        nb_buckets = ((പൂർണ്ണസംഖ്യ*)s->hash->data)[0];

    s->hash->data_offset = 0;
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + nb_syms) * വലുപ്പം(പൂർണ്ണസംഖ്യ));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    memset(hash, 0, (nb_buckets + 1) * വലുപ്പം(പൂർണ്ണസംഖ്യ));
    ptr += nb_buckets + 1;

    sym = (ElfW(Sym) *)s->data + 1;
    വേണ്ടി(sym_index = 1; sym_index < nb_syms; sym_index++) {
        എങ്കിൽ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            h = elf_hash(strtab + sym->st_name) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_index;
        } അല്ലെങ്കിൽ {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}

/* return the symbol number */
ST_FUNC പൂർണ്ണസംഖ്യ put_elf_sym(Section *s, addr_t മൂല്യം, unsigned long size,
    പൂർണ്ണസംഖ്യ info, പൂർണ്ണസംഖ്യ other, പൂർണ്ണസംഖ്യ shndx, സ്ഥിരം അക്ഷരം *name)
{
    പൂർണ്ണസംഖ്യ name_offset, sym_index;
    പൂർണ്ണസംഖ്യ nbuckets, h;
    ElfW(Sym) *sym;
    Section *hs;

    sym = section_ptr_add(s, വലുപ്പം(ElfW(Sym)));
    എങ്കിൽ (name && name[0])
        name_offset = put_elf_str(s->link, name);
    അല്ലെങ്കിൽ
        name_offset = 0;
    /* XXX: endianness */
    sym->st_name = name_offset;
    sym->st_മൂല്യം = മൂല്യം;
    sym->st_size = size;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
    sym_index = sym - (ElfW(Sym) *)s->data;
    hs = s->hash;
    എങ്കിൽ (hs) {
        പൂർണ്ണസംഖ്യ *ptr, *base;
        ptr = section_ptr_add(hs, വലുപ്പം(പൂർണ്ണസംഖ്യ));
        base = (പൂർണ്ണസംഖ്യ *)hs->data;
        /* only add global or weak symbols. */
        എങ്കിൽ (ELFW(ST_BIND)(info) != STB_LOCAL) {
            /* add another hashing entry */
            nbuckets = base[0];
            h = elf_hash((unsigned അക്ഷരം *)s->link->data + name_offset) % nbuckets;
            *ptr = base[2 + h];
            base[2 + h] = sym_index;
            base[1]++;
            /* we resize the hash table */
            hs->nb_hashed_syms++;
            എങ്കിൽ (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } അല്ലെങ്കിൽ {
            *ptr = 0;
            base[1]++;
        }
    }
    തിരികെ sym_index;
}

ST_FUNC പൂർണ്ണസംഖ്യ find_elf_sym(Section *s, സ്ഥിരം അക്ഷരം *name)
{
    ElfW(Sym) *sym;
    Section *hs;
    പൂർണ്ണസംഖ്യ nbuckets, sym_index, h;
    സ്ഥിരം അക്ഷരം *name1;

    hs = s->hash;
    എങ്കിൽ (!hs)
        തിരികെ 0;
    nbuckets = ((പൂർണ്ണസംഖ്യ *)hs->data)[0];
    h = elf_hash((unsigned അക്ഷരം *) name) % nbuckets;
    sym_index = ((പൂർണ്ണസംഖ്യ *)hs->data)[2 + h];
    ആകുമ്പോൾ (sym_index != 0) {
        sym = &((ElfW(Sym) *)s->data)[sym_index];
        name1 = (അക്ഷരം *) s->link->data + sym->st_name;
        എങ്കിൽ (!strcmp(name, name1))
            തിരികെ sym_index;
        sym_index = ((പൂർണ്ണസംഖ്യ *)hs->data)[2 + nbuckets + sym_index];
    }
    തിരികെ 0;
}

/* return elf symbol value, signal error if 'err' is nonzero, decorate
   name if FORC */
ST_FUNC addr_t get_sym_addr(TCCState *s1, സ്ഥിരം അക്ഷരം *name, പൂർണ്ണസംഖ്യ err, പൂർണ്ണസംഖ്യ forc)
{
    പൂർണ്ണസംഖ്യ sym_index;
    ElfW(Sym) *sym;
    അക്ഷരം buf[256];
    എങ്കിൽ (forc && s1->leading_underscore
#ifdef TCC_TARGET_PE
        /* win32-32bit stdcall symbols always have _ already */
        && !strchr(name, '@')
#endif
        ) {
        buf[0] = '_';
        pstrcpy(buf + 1, വലുപ്പം(buf) - 1, name);
        name = buf;
    }
    sym_index = find_elf_sym(s1->symtab, name);
    sym = &((ElfW(Sym) *)s1->symtab->data)[sym_index];
    എങ്കിൽ (!sym_index || sym->st_shndx == SHN_UNDEF) {
        എങ്കിൽ (err)
            tcc_error_noabort("%s not defined", name);
        തിരികെ (addr_t)-1;
    }
    തിരികെ sym->st_മൂല്യം;
}

/* return elf symbol value */
LIBTCCAPI ശൂന്യം *tcc_get_ചിഹ്നം(TCCState *s, സ്ഥിരം അക്ഷരം *name)
{
    addr_t addr = get_sym_addr(s, name, 0, 1);
    തിരികെ addr == -1 ? ശൂന്യ : (ശൂന്യം*)(uintptr_t)addr;
}

LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_add_ചിഹ്നം(TCCState *s1, സ്ഥിരം അക്ഷരം *name, സ്ഥിരം ശൂന്യം *val)
{
#ifdef TCC_TARGET_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s1, 0, name, (uintptr_t)val);
#അല്ലെങ്കിൽ
    അക്ഷരം buf[256];
    എങ്കിൽ (s1->leading_underscore) {
        buf[0] = '_';
        pstrcpy(buf + 1, വലുപ്പം(buf) - 1, name);
        name = buf;
    }
    set_global_sym(s1, name, ശൂന്യ, (addr_t)(uintptr_t)val); /* NULL: SHN_ABS */
#endif
    തിരികെ 0;
}

/* list elf symbol names and values */
ST_FUNC ശൂന്യം list_elf_symbols(TCCState *s, ശൂന്യം *ctx,
    ശൂന്യം (*ചിഹ്നം_cb)(ശൂന്യം *ctx, സ്ഥിരം അക്ഷരം *name, സ്ഥിരം ശൂന്യം *val))
{
    ElfW(Sym) *sym;
    Section *symtab;
    പൂർണ്ണസംഖ്യ sym_index, end_sym;
    സ്ഥിരം അക്ഷരം *name;
    unsigned അക്ഷരം sym_vis, sym_bind;

    symtab = s->symtab;
    end_sym = symtab->data_offset / വലുപ്പം (ElfSym);
    വേണ്ടി (sym_index = 0; sym_index < end_sym; ++sym_index) {
        sym = &((ElfW(Sym) *)symtab->data)[sym_index];
        എങ്കിൽ (sym->st_മൂല്യം) {
            name = (അക്ഷരം *) symtab->link->data + sym->st_name;
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            sym_vis = ELFW(ST_VISIBILITY)(sym->st_other);
            എങ്കിൽ (sym_bind == STB_GLOBAL && sym_vis == STV_DEFAULT)
                ചിഹ്നം_cb(ctx, name, (ശൂന്യം*)(uintptr_t)sym->st_മൂല്യം);
        }
    }
}

/* list elf symbol names and values */
LIBTCCAPI ശൂന്യം tcc_list_symbols(TCCState *s, ശൂന്യം *ctx,
    ശൂന്യം (*ചിഹ്നം_cb)(ശൂന്യം *ctx, സ്ഥിരം അക്ഷരം *name, സ്ഥിരം ശൂന്യം *val))
{
    list_elf_symbols(s, ctx, ചിഹ്നം_cb);
}

#ifndef ELF_OBJ_ONLY
സ്ഥിതം ശൂന്യം
version_add (TCCState *s1)
{
    പൂർണ്ണസംഖ്യ i;
    ElfW(Sym) *sym;
    ElfW(Verneed) *vn = ശൂന്യ;
    Section *symtab;
    പൂർണ്ണസംഖ്യ sym_index, end_sym, nb_versions = 2, nb_entries = 0;
    ElfW(Half) *versym;
    സ്ഥിരം അക്ഷരം *name;

    എങ്കിൽ (0 == nb_sym_versions)
        തിരികെ;
    versym_section = new_section(s1, ".gnu.version", SHT_GNU_versym, SHF_ALLOC);
    versym_section->sh_entsize = വലുപ്പം(ElfW(Half));
    versym_section->link = s1->dynsym;

    /* add needed symbols */
    symtab = s1->dynsym;
    end_sym = symtab->data_offset / വലുപ്പം (ElfSym);
    versym = section_ptr_add(versym_section, end_sym * വലുപ്പം(ElfW(Half)));
    വേണ്ടി (sym_index = 1; sym_index < end_sym; ++sym_index) {
        പൂർണ്ണസംഖ്യ dllindex, verndx;
        sym = &((ElfW(Sym) *)symtab->data)[sym_index];
        name = (അക്ഷരം *) symtab->link->data + sym->st_name;
        dllindex = find_elf_sym(s1->dynsymtab_section, name);
        verndx = (dllindex && dllindex < nb_sym_to_version)
                 ? sym_to_version[dllindex] : -1;
        എങ്കിൽ (verndx >= 0
            /* XXX: on android, clang refuses to link with a libtcc.so made by tcc
               when defined symbols have a version > 1 or when the version is '0'.
               Whereas version '1' for example for 'signal' in an exe defeats
               bcheck's signal_redir. */
            && (sym->st_shndx == SHN_UNDEF || (s1->output_type & TCC_OUTPUT_EXE))
            ) {
            എങ്കിൽ (!sym_versions[verndx].out_index)
              sym_versions[verndx].out_index = nb_versions++;
            versym[sym_index] = sym_versions[verndx].out_index;
        } അല്ലെങ്കിൽ {
            versym[sym_index] = 1; /* (*global*) */
        }
        //printf("SYM %d %s\n", versym[sym_index], name);
    }
    /* generate verneed section, but not when it will be empty.  Some
       dynamic linkers look at their contents even when DTVERNEEDNUM and
       section size is zero.  */
    എങ്കിൽ (nb_versions > 2) {
        verneed_section = new_section(s1, ".gnu.version_r",
                                      SHT_GNU_verneed, SHF_ALLOC);
        verneed_section->link = s1->dynsym->link;
        വേണ്ടി (i = nb_sym_versions; i-- > 0;) {
            ഘടന sym_version *sv = &sym_versions[i];
            പൂർണ്ണസംഖ്യ n_same_libs = 0, prev;
            size_t vnofs;
            ElfW(Vernaux) *vna = 0;
            എങ്കിൽ (sv->out_index < 1)
              തുടരുക;

            /* make sure that a DT_NEEDED tag is put */
            /* abitest-tcc fails on older i386-linux with "ld-linux.so.2" DT_NEEDED
               ret_int_test... Inconsistency detected by ld.so: dl-minimal.c: 148:
               realloc: Assertion `ptr == alloc_last_block' failed! */
            എങ്കിൽ (strcmp(sv->lib, "ld-linux.so.2"))
                tcc_add_dllref(s1, sv->lib, 0);

            vnofs = section_add(verneed_section, വലുപ്പം(*vn), 1);
            vn = (ElfW(Verneed)*)(verneed_section->data + vnofs);
            vn->vn_version = 1;
            vn->vn_file = put_elf_str(verneed_section->link, sv->lib);
            vn->vn_aux = വലുപ്പം (*vn);
            ചെയ്യുക {
                prev = sv->prev_same_lib;
                എങ്കിൽ (sv->out_index > 0) {
                    vna = section_ptr_add(verneed_section, വലുപ്പം(*vna));
                    vna->vna_hash = elf_hash ((സ്ഥിരം unsigned അക്ഷരം *)sv->version);
                    vna->vna_flags = 0;
                    vna->vna_other = sv->out_index;
                    sv->out_index = -2;
                    vna->vna_name = put_elf_str(verneed_section->link, sv->version);
                    vna->vna_next = വലുപ്പം (*vna);
                    //printf("LIB %d %s %s\n", vna->vna_other, sv->lib, verneed_section->link->data + vna->vna_name);
                    n_same_libs++;
                }
                എങ്കിൽ (prev >= 0)
                  sv = &sym_versions[prev];
            } ആകുമ്പോൾ(prev >= 0);
            vna->vna_next = 0;
            vn = (ElfW(Verneed)*)(verneed_section->data + vnofs);
            vn->vn_cnt = n_same_libs;
            vn->vn_next = വലുപ്പം(*vn) + n_same_libs * വലുപ്പം(*vna);
            nb_entries++;
        }
        എങ്കിൽ (vn)
          vn->vn_next = 0;
        verneed_section->sh_info = nb_entries;
    }
    dt_verneednum = nb_entries;
}
#endif /* ndef ELF_OBJ_ONLY */

/* catch .tbss also */
സ്ഥിതം പൂർണ്ണസംഖ്യ IS_BSS(TCCState *s1, പൂർണ്ണസംഖ്യ ndx)
{
    തിരികെ ndx == SHN_COMMON
     || (ndx < s1->nb_sections
         && s1->sections[ndx]->sh_type == SHT_NOBITS);
}

/* add an elf symbol : check if it is already defined and patch
   it. Return symbol index. NOTE that sh_num can be SHN_UNDEF. */
ST_FUNC പൂർണ്ണസംഖ്യ set_elf_sym(Section *s, addr_t മൂല്യം, unsigned long size,
                       പൂർണ്ണസംഖ്യ info, പൂർണ്ണസംഖ്യ other, പൂർണ്ണസംഖ്യ shndx, സ്ഥിരം അക്ഷരം *name)
{
    TCCState *s1 = s->s1;
    ElfW(Sym) *esym;
    പൂർണ്ണസംഖ്യ sym_bind, sym_index, sym_type, esym_bind;
    unsigned അക്ഷരം sym_vis, esym_vis, new_vis;

    sym_bind = ELFW(ST_BIND)(info);
    sym_type = ELFW(ST_TYPE)(info);
    sym_vis = ELFW(ST_VISIBILITY)(other);

    എങ്കിൽ (sym_bind != STB_LOCAL) {
        /* we search global or weak symbols */
        sym_index = find_elf_sym(s, name);
        എങ്കിൽ (!sym_index)
            പോകുക do_def;
        esym = &((ElfW(Sym) *)s->data)[sym_index];
        എങ്കിൽ (esym->st_മൂല്യം == മൂല്യം && esym->st_size == size && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            തിരികെ sym_index;
        എങ്കിൽ (esym->st_shndx != SHN_UNDEF) {
            esym_bind = ELFW(ST_BIND)(esym->st_info);
            /* propagate the most constraining visibility */
            /* STV_DEFAULT(0)<STV_PROTECTED(3)<STV_HIDDEN(2)<STV_INTERNAL(1) */
            esym_vis = ELFW(ST_VISIBILITY)(esym->st_other);
            എങ്കിൽ (esym_vis == STV_DEFAULT) {
                new_vis = sym_vis;
            } അല്ലെങ്കിൽ എങ്കിൽ (sym_vis == STV_DEFAULT) {
                new_vis = esym_vis;
            } അല്ലെങ്കിൽ {
                new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
            }
            esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
                             | new_vis;
            എങ്കിൽ (shndx == SHN_UNDEF) {
                /* ignore adding of undefined symbol if the
                   corresponding symbol is already defined */
            } അല്ലെങ്കിൽ എങ്കിൽ (sym_bind == STB_GLOBAL && esym_bind == STB_WEAK) {
                /* global overrides weak, so patch */
                പോകുക do_patch;
            } അല്ലെങ്കിൽ എങ്കിൽ (sym_bind == STB_WEAK && esym_bind == STB_GLOBAL) {
                /* weak is ignored if already global */
            } അല്ലെങ്കിൽ എങ്കിൽ (sym_bind == STB_WEAK && esym_bind == STB_WEAK) {
                /* keep first-found weak definition, ignore subsequents */
            } അല്ലെങ്കിൽ എങ്കിൽ (sym_vis == STV_HIDDEN || sym_vis == STV_INTERNAL) {
                /* ignore hidden symbols after */
            } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_flags & SHF_DYNSYM) {
                /* we accept that two DLL define the same symbol */
            } അല്ലെങ്കിൽ എങ്കിൽ (!IS_BSS(s1, shndx) && IS_BSS(s1, esym->st_shndx)) {
                /* data symbol gets precedence over common/bss */
                പോകുക do_patch;
            } അല്ലെങ്കിൽ എങ്കിൽ (IS_BSS(s1, shndx)) {
                /* data symbol keeps precedence over common/bss */
	    } അല്ലെങ്കിൽ എങ്കിൽ (esym->st_other & ST_ASM_SET) {
		/* If the existing symbol came from an asm .set
		   we can override.  */
		പോകുക do_patch;
            } അല്ലെങ്കിൽ {
#എങ്കിൽ 0
                printf("new_bind=%x new_shndx=%x new_vis=%x old_bind=%x old_shndx=%x old_vis=%x\n",
                       sym_bind, shndx, new_vis, esym_bind, esym->st_shndx, esym_vis);
#endif
                tcc_error_noabort("link symbol '%s' defined twice", name);
            }
        } അല്ലെങ്കിൽ {
            esym->st_other = other;
        do_patch:
            esym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
            esym->st_shndx = shndx;
            esym->st_മൂല്യം = മൂല്യം;
            esym->st_size = size;
        }
    } അല്ലെങ്കിൽ {
    do_def:
        sym_index = put_elf_sym(s, മൂല്യം, size,
                                ELFW(ST_INFO)(sym_bind, sym_type), other,
                                shndx, name);
    }
    തിരികെ sym_index;
}

/* put relocation */
ST_FUNC ശൂന്യം put_elf_reloca(Section *symtab, Section *s, unsigned long offset,
                            പൂർണ്ണസംഖ്യ type, പൂർണ്ണസംഖ്യ ചിഹ്നം, addr_t addend)
{
    TCCState *s1 = s->s1;
    അക്ഷരം buf[256];
    Section *sr;
    ElfW_Rel *rel;

    sr = s->reloc;
    എങ്കിൽ (!sr) {
        /* if no relocation section, create it */
        snprintf(buf, വലുപ്പം(buf), REL_SECTION_FMT, s->name);
        /* if the symtab is allocated, then we consider the relocation
           are also */
        sr = new_section(s->s1, buf, SHT_RELX, symtab->sh_flags);
        sr->sh_entsize = വലുപ്പം(ElfW_Rel);
        sr->link = symtab;
        sr->sh_info = s->sh_അക്കം;
        s->reloc = sr;
    }
    rel = section_ptr_add(sr, വലുപ്പം(ElfW_Rel));
    rel->r_offset = offset;
    rel->r_info = ELFW(R_INFO)(ചിഹ്നം, type);
#എങ്കിൽ SHT_RELX == SHT_RELA
    rel->r_addend = addend;
#endif
    എങ്കിൽ (SHT_RELX != SHT_RELA && addend)
        tcc_error_noabort("non-zero addend on REL architecture");
}

ST_FUNC ശൂന്യം put_elf_reloc(Section *symtab, Section *s, unsigned long offset,
                           പൂർണ്ണസംഖ്യ type, പൂർണ്ണസംഖ്യ ചിഹ്നം)
{
    put_elf_reloca(symtab, s, offset, type, ചിഹ്നം, 0);
}

ST_FUNC ഘടന sym_attr *get_sym_attr(TCCState *s1, പൂർണ്ണസംഖ്യ index, പൂർണ്ണസംഖ്യ alloc)
{
    പൂർണ്ണസംഖ്യ n;
    ഘടന sym_attr *tab;

    എങ്കിൽ (index >= s1->nb_sym_attrs) {
        എങ്കിൽ (!alloc)
            തിരികെ s1->sym_attrs;
        /* find immediately bigger power of 2 and reallocate array */
        n = 1;
        ആകുമ്പോൾ (index >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * വലുപ്പം(*s1->sym_attrs));
        s1->sym_attrs = tab;
        memset(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * വലുപ്പം(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    തിരികെ &s1->sym_attrs[index];
}

സ്ഥിതം ശൂന്യം update_relocs(TCCState *s1, Section *s, പൂർണ്ണസംഖ്യ *old_to_new_syms, പൂർണ്ണസംഖ്യ first_sym)
{
    പൂർണ്ണസംഖ്യ i, type, sym_index;
    Section *sr;
    ElfW_Rel *rel;

    വേണ്ടി(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        എങ്കിൽ (sr->sh_type == SHT_RELX && sr->link == s) {
            for_each_elem(sr, 0, rel, ElfW_Rel) {
                sym_index = ELFW(R_SYM)(rel->r_info);
                type = ELFW(R_TYPE)(rel->r_info);
                എങ്കിൽ ((sym_index -= first_sym) < 0)
                    തുടരുക; /* zero sym_index in reloc (can happen with asm) */
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
സ്ഥിതം ശൂന്യം sort_syms(TCCState *s1, Section *s)
{
    പൂർണ്ണസംഖ്യ *old_to_new_syms;
    ElfW(Sym) *new_syms;
    പൂർണ്ണസംഖ്യ nb_syms, i;
    ElfW(Sym) *p, *q;

    nb_syms = s->data_offset / വലുപ്പം(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * വലുപ്പം(ElfW(Sym)));
    old_to_new_syms = tcc_malloc(nb_syms * വലുപ്പം(പൂർണ്ണസംഖ്യ));

    /* first pass for local symbols */
    p = (ElfW(Sym) *)s->data;
    q = new_syms;
    വേണ്ടി(i = 0; i < nb_syms; i++) {
        എങ്കിൽ (ELFW(ST_BIND)(p->st_info) == STB_LOCAL) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    /* save the number of local symbols in section header */
    എങ്കിൽ( s->sh_size )    /* this 'if' makes IDA happy */
        s->sh_info = q - new_syms;

    /* then second pass for non local symbols */
    p = (ElfW(Sym) *)s->data;
    വേണ്ടി(i = 0; i < nb_syms; i++) {
        എങ്കിൽ (ELFW(ST_BIND)(p->st_info) != STB_LOCAL) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }

    /* we copy the new symbols to the old */
    memcpy(s->data, new_syms, nb_syms * വലുപ്പം(ElfW(Sym)));
    tcc_free(new_syms);

    update_relocs(s1, s, old_to_new_syms, 0);
    tcc_free(old_to_new_syms);
}

#ifndef ELF_OBJ_ONLY
/* See: https://flapenguin.me/elf-dt-gnu-hash */
#define	ELFCLASS_BITS (PTR_SIZE * 8)

സ്ഥിതം Section *create_gnu_hash(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ nb_syms, i, ndef, nbuckets, symoffset, bloom_size, bloom_shift;
    ElfW(Sym) *p;
    Section *gnu_hash;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr;

    gnu_hash = new_section(s1, ".gnu.hash", SHT_GNU_HASH, SHF_ALLOC);
    gnu_hash->link = dynsym->hash->link;

    nb_syms = dynsym->data_offset / വലുപ്പം(ElfW(Sym));

    /* count def symbols */
    ndef = 0;
    p = (ElfW(Sym) *)dynsym->data;
    വേണ്ടി(i = 0; i < nb_syms; i++, p++)
        ndef += p->st_shndx != SHN_UNDEF;

    /* calculate gnu hash sizes and fill header */
    nbuckets = ndef / 4 + 1;
    symoffset = nb_syms - ndef;
    bloom_shift = PTR_SIZE == 8 ? 6 : 5;
    bloom_size = 1; /* must be power of two */
    ആകുമ്പോൾ (ndef >= bloom_size * (1 << (bloom_shift - 3)))
	bloom_size *= 2;
    ptr = section_ptr_add(gnu_hash, 4 * 4 +
				    PTR_SIZE * bloom_size +
				    nbuckets * 4 +
				    ndef * 4);
    ptr[0] = nbuckets;
    ptr[1] = symoffset;
    ptr[2] = bloom_size;
    ptr[3] = bloom_shift;
    തിരികെ gnu_hash;
}

സ്ഥിതം Elf32_Word elf_gnu_hash (സ്ഥിരം unsigned അക്ഷരം *name)
{
    Elf32_Word h = 5381;
    unsigned അക്ഷരം c;

    ആകുമ്പോൾ ((c = *name++))
        h = h * 33 + c;
    തിരികെ h;
}

സ്ഥിതം ശൂന്യം update_gnu_hash(TCCState *s1, Section *gnu_hash)
{
    പൂർണ്ണസംഖ്യ *old_to_new_syms;
    ElfW(Sym) *new_syms;
    പൂർണ്ണസംഖ്യ nb_syms, i, nbuckets, bloom_size, bloom_shift;
    ElfW(Sym) *p, *q;
    Section *vs;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr, *buckets, *chain, *hash;
    unsigned പൂർണ്ണസംഖ്യ *nextbuck;
    addr_t *bloom;
    unsigned അക്ഷരം *strtab;
    ഘടന { പൂർണ്ണസംഖ്യ first, last; } *buck;

    strtab = dynsym->link->data;
    nb_syms = dynsym->data_offset / വലുപ്പം(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * വലുപ്പം(ElfW(Sym)));
    old_to_new_syms = tcc_malloc(nb_syms * വലുപ്പം(പൂർണ്ണസംഖ്യ));
    hash = tcc_malloc(nb_syms * വലുപ്പം(Elf32_Word));
    nextbuck = tcc_malloc(nb_syms * വലുപ്പം(പൂർണ്ണസംഖ്യ));

    /* calculate hashes and copy undefs */
    p = (ElfW(Sym) *)dynsym->data;
    q = new_syms;
    വേണ്ടി(i = 0; i < nb_syms; i++, p++) {
        എങ്കിൽ (p->st_shndx == SHN_UNDEF) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
	അല്ലെങ്കിൽ
	    hash[i] = elf_gnu_hash(strtab + p->st_name);
    }

    ptr = (Elf32_Word *) gnu_hash->data;
    nbuckets = ptr[0];
    bloom_size = ptr[2];
    bloom_shift = ptr[3];
    bloom = (addr_t *) (ശൂന്യം *) &ptr[4];
    buckets = (Elf32_Word*) (ശൂന്യം *) &bloom[bloom_size];
    chain = &buckets[nbuckets];
    buck = tcc_malloc(nbuckets * വലുപ്പം(*buck));

    എങ്കിൽ (gnu_hash->data_offset != 4 * 4 +
				 PTR_SIZE * bloom_size +
				 nbuckets * 4 +
				 (nb_syms - (q - new_syms)) * 4)
	tcc_error_noabort ("gnu_hash size incorrect");

    /* find buckets */
    വേണ്ടി(i = 0; i < nbuckets; i++)
	buck[i].first = -1;

    p = (ElfW(Sym) *)dynsym->data;
    വേണ്ടി(i = 0; i < nb_syms; i++, p++)
        എങ്കിൽ (p->st_shndx != SHN_UNDEF) {
	    പൂർണ്ണസംഖ്യ bucket = hash[i] % nbuckets;

	    എങ്കിൽ (buck[bucket].first == -1)
		buck[bucket].first = buck[bucket].last = i;
	    അല്ലെങ്കിൽ {
		nextbuck[buck[bucket].last] = i;
		buck[bucket].last = i;
	    }
	}

    /* fill buckets/chains/bloom and sort symbols */
    p = (ElfW(Sym) *)dynsym->data;
    വേണ്ടി(i = 0; i < nbuckets; i++) {
	പൂർണ്ണസംഖ്യ cur = buck[i].first;

	എങ്കിൽ (cur != -1) {
	    buckets[i] = q - new_syms;
	    വേണ്ടി (;;) {
                old_to_new_syms[cur] = q - new_syms;
                *q++ = p[cur];
	        *chain++ = hash[cur] & ~1;
		bloom[(hash[cur] / ELFCLASS_BITS) % bloom_size] |=
		    (addr_t)1 << (hash[cur] % ELFCLASS_BITS) |
		    (addr_t)1 << ((hash[cur] >> bloom_shift) % ELFCLASS_BITS);
		എങ്കിൽ (cur == buck[i].last)
		    നിർത്തുക;
		cur = nextbuck[cur];
	    }
	    chain[-1] |= 1;
	}
    }

    memcpy(dynsym->data, new_syms, nb_syms * വലുപ്പം(ElfW(Sym)));
    tcc_free(new_syms);
    tcc_free(hash);
    tcc_free(buck);
    tcc_free(nextbuck);

    update_relocs(s1, dynsym, old_to_new_syms, 0);

    /* modify the versions */
    vs = versym_section;
    എങ്കിൽ (vs) {
	ElfW(Half) *newver, *versym = (ElfW(Half) *)vs->data;

	എങ്കിൽ (1/*versym*/) {
            newver = tcc_malloc(nb_syms * വലുപ്പം(*newver));
	    വേണ്ടി (i = 0; i < nb_syms; i++)
	        newver[old_to_new_syms[i]] = versym[i];
	    memcpy(vs->data, newver, nb_syms * വലുപ്പം(*newver));
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
ST_FUNC ശൂന്യം relocate_syms(TCCState *s1, Section *symtab, പൂർണ്ണസംഖ്യ do_resolve)
{
    ElfW(Sym) *sym;
    പൂർണ്ണസംഖ്യ sym_bind, sh_അക്കം;
    സ്ഥിരം അക്ഷരം *name;

    for_each_elem(symtab, 1, sym, ElfW(Sym)) {
        sh_അക്കം = sym->st_shndx;
        എങ്കിൽ (sh_അക്കം == SHN_UNDEF) {
            എങ്കിൽ (do_resolve == 2) /* relocating dynsym */
                തുടരുക;
            name = (അക്ഷരം *) s1->symtab->link->data + sym->st_name;
            /* Use ld.so to resolve symbol for us (for tcc -run) */
            എങ്കിൽ (do_resolve) {
#എങ്കിൽ defined TCC_IS_NATIVE && !defined TCC_TARGET_PE
                /* dlsym() needs the undecorated name.  */
                സ്ഥിരം അക്ഷരം *name_ud = &name[s1->leading_underscore];
                ശൂന്യം *addr = ശൂന്യ;
                എങ്കിൽ (!s1->nostdlib)
                    addr = dlsym(RTLD_DEFAULT, name_ud);
		എങ്കിൽ (addr == ശൂന്യ) {
		    പൂർണ്ണസംഖ്യ i;
		    വേണ്ടി (i = 0; i < s1->nb_loaded_dlls; i++)
                        എങ്കിൽ ((addr = dlsym(s1->loaded_dlls[i]->handle, name_ud)))
			    നിർത്തുക;
		}
                എങ്കിൽ (addr) {
                    sym->st_മൂല്യം = (addr_t) addr;
#ifdef DEBUG_RELOC
		    printf ("relocate_sym: %s -> 0x%lx\n", name, sym->st_മൂല്യം);
#endif
                    പോകുക found;
                }
#endif
            /* if dynamic symbol exist, it will be used in relocate_section */
            } അല്ലെങ്കിൽ എങ്കിൽ (s1->dynsym && find_elf_sym(s1->dynsym, name))
                പോകുക found;
            /* XXX: _fp_hw seems to be part of the ABI, so we ignore
               it */
            എങ്കിൽ (!strcmp(name, "_fp_hw"))
                പോകുക found;
            /* only weak symbols are accepted to be undefined. Their
               value is zero */
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            എങ്കിൽ (sym_bind == STB_WEAK)
                sym->st_മൂല്യം = 0;
            അല്ലെങ്കിൽ
                tcc_error_noabort("unresolved reference to '%s'", name);

        } അല്ലെങ്കിൽ എങ്കിൽ (sh_അക്കം < SHN_LORESERVE) {
            /* add section base */
            sym->st_മൂല്യം += s1->sections[sym->st_shndx]->sh_addr;
        }
    found: ;
    }
}

/* relocate a given section (CPU dependent) by applying the relocations
   in the associated relocation section */
സ്ഥിതം ശൂന്യം relocate_section(TCCState *s1, Section *s, Section *sr)
{
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    പൂർണ്ണസംഖ്യ type, sym_index;
    unsigned അക്ഷരം *ptr;
    addr_t tgt, addr;
    പൂർണ്ണസംഖ്യ is_dwarf = s->sh_അക്കം >= s1->dwlo && s->sh_അക്കം < s1->dwhi;

    qrel = (ElfW_Rel *)sr->data;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
	എങ്കിൽ (s->data == ശൂന്യ) /* bss */
	    തുടരുക;
        ptr = s->data + rel->r_offset;
        sym_index = ELFW(R_SYM)(rel->r_info);
        sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
        type = ELFW(R_TYPE)(rel->r_info);
        tgt = sym->st_മൂല്യം;
#എങ്കിൽ SHT_RELX == SHT_RELA
        tgt += rel->r_addend;
#endif
        എങ്കിൽ (is_dwarf && type == R_DATA_32DW
            && sym->st_shndx >= s1->dwlo && sym->st_shndx < s1->dwhi) {
            /* dwarf section relocation to each other */
            add32le(ptr, tgt - s1->sections[sym->st_shndx]->sh_addr);
            തുടരുക;
        }
        addr = s->sh_addr + rel->r_offset;
        relocate(s1, rel, type, ptr, addr, tgt);
    }

#ifndef ELF_OBJ_ONLY
    /* if the relocation is allocated, we change its symbol table */
    എങ്കിൽ (sr->sh_flags & SHF_ALLOC) {
        sr->link = s1->dynsym;
        എങ്കിൽ (s1->output_type & TCC_OUTPUT_DYN) {
            size_t r = (uint8_t*)qrel - sr->data;
            എങ്കിൽ (വലുപ്പം ((Stab_Sym*)0)->n_മൂല്യം < PTR_SIZE
                && 0 == strcmp(s->name, ".stab"))
                r = 0; /* cannot apply 64bit relocation to 32bit value */
            sr->data_offset = sr->sh_size = r;
#ifdef CONFIG_TCC_PIE
            എങ്കിൽ (r && (s->sh_flags & SHF_EXECINSTR))
                tcc_warning("%d relocations to %s", (unsigned)(r / വലുപ്പം *qrel), s->name);
#endif
        }
    }
#endif

#ifdef TCC_TARGET_RISCV64
    dynarray_reset(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries);
#endif
}

/* relocate all sections */
ST_FUNC ശൂന്യം relocate_sections(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ i;
    Section *s, *sr;

    വേണ്ടി (i = 1; i < s1->nb_sections; ++i) {
        sr = s1->sections[i];
        എങ്കിൽ (sr->sh_type != SHT_RELX)
            തുടരുക;
        s = s1->sections[sr->sh_info];
#ifndef TCC_TARGET_MACHO
        എങ്കിൽ (s != s1->got
            || s1->static_link
            || s1->output_type == TCC_OUTPUT_MEMORY)
#endif
        {
            relocate_section(s1, s, sr);
        }
#ifndef ELF_OBJ_ONLY
        എങ്കിൽ (sr->sh_flags & SHF_ALLOC) {
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
സ്ഥിതം പൂർണ്ണസംഖ്യ prepare_dynamic_rel(TCCState *s1, Section *sr)
{
    പൂർണ്ണസംഖ്യ എണ്ണം_2 = 0;
#എങ്കിൽ defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || \
    defined(TCC_TARGET_ARM) || defined(TCC_TARGET_ARM64) || \
    defined(TCC_TARGET_RISCV64)
    ElfW_Rel *rel;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
        പൂർണ്ണസംഖ്യ sym_index = ELFW(R_SYM)(rel->r_info);
        പൂർണ്ണസംഖ്യ type = ELFW(R_TYPE)(rel->r_info);
        തിരഞ്ഞെടുപ്പ്(type) {
#എങ്കിൽ defined(TCC_TARGET_I386)
        അവസ്ഥ R_386_32:
            എങ്കിൽ (!get_sym_attr(s1, sym_index, 0)->dyn_index
                && ((ElfW(Sym)*)symtab_section->data + sym_index)->st_shndx == SHN_UNDEF) {
                /* don't fixup unresolved (weak) symbols */
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_RELATIVE);
                നിർത്തുക;
            }
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_X86_64)
        അവസ്ഥ R_X86_64_32:
        അവസ്ഥ R_X86_64_32S:
        അവസ്ഥ R_X86_64_64:
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_ARM)
        അവസ്ഥ R_ARM_ABS32:
        അവസ്ഥ R_ARM_TARGET1:
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_ARM64)
        അവസ്ഥ R_AARCH64_ABS32:
        അവസ്ഥ R_AARCH64_ABS64:
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_RISCV64)
        അവസ്ഥ R_RISCV_32:
        അവസ്ഥ R_RISCV_64:
#endif
            എണ്ണം_2++;
            നിർത്തുക;
#എങ്കിൽ defined(TCC_TARGET_I386)
        അവസ്ഥ R_386_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    എങ്കിൽ (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_PLT32);
	        നിർത്തുക;
	    }
	}
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_X86_64)
        അവസ്ഥ R_X86_64_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    എങ്കിൽ (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_index, R_X86_64_PLT32);
	        നിർത്തുക;
	    }
	}
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_ARM64)
        അവസ്ഥ R_AARCH64_PREL32:
#endif
            എങ്കിൽ (s1->output_type != TCC_OUTPUT_DLL)
                നിർത്തുക;
            എങ്കിൽ (get_sym_attr(s1, sym_index, 0)->dyn_index)
                എണ്ണം_2++;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            നിർത്തുക;
        }
    }
#endif
    തിരികെ എണ്ണം_2;
}
#endif

#ifdef NEED_BUILD_GOT
സ്ഥിതം പൂർണ്ണസംഖ്യ build_got(TCCState *s1)
{
    /* if no got, then create it */
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    s1->got->sh_entsize = 4;
    /* keep space for _DYNAMIC pointer and two dummy got entries */
    section_ptr_add(s1->got, 3 * PTR_SIZE);
    തിരികെ set_elf_sym(symtab_section, 0, 0, ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
        0, s1->got->sh_അക്കം, "_GLOBAL_OFFSET_TABLE_");
}

/* Create a GOT and (for function call) a PLT entry corresponding to a symbol
   in s1->symtab. When creating the dynamic symbol table entry for the GOT
   relocation, use 'size' and 'info' for the corresponding symbol metadata.
   Returns the offset of the GOT or (if any) PLT entry. */
സ്ഥിതം ഘടന sym_attr * put_got_entry(TCCState *s1, പൂർണ്ണസംഖ്യ dyn_reloc_type,
                                       പൂർണ്ണസംഖ്യ sym_index)
{
    പൂർണ്ണസംഖ്യ need_plt_entry;
    സ്ഥിരം അക്ഷരം *name;
    ElfW(Sym) *sym;
    ഘടന sym_attr *attr;
    unsigned got_offset;
    അക്ഷരം plt_name[200];
    പൂർണ്ണസംഖ്യ len;
    Section *s_rel;

    need_plt_entry = (dyn_reloc_type == R_JMP_SLOT);
    attr = get_sym_attr(s1, sym_index, 1);

    /* In case a function is both called and its address taken 2 GOT entries
       are created, one for taking the address (GOT) and the other for the PLT
       entry (PLTGOT).  */
    എങ്കിൽ (need_plt_entry ? attr->plt_offset : attr->got_offset)
        തിരികെ attr;

    s_rel = s1->got;
    എങ്കിൽ (need_plt_entry) {
        എങ്കിൽ (!s1->plt) {
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
    name = (അക്ഷരം *) symtab_section->link->data + sym->st_name;
    //printf("sym %d %s\n", need_plt_entry, name);

    എങ്കിൽ (s1->dynsym) {
	എങ്കിൽ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
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
	} അല്ലെങ്കിൽ {
	    എങ്കിൽ (0 == attr->dyn_index)
                attr->dyn_index = set_elf_sym(s1->dynsym, sym->st_മൂല്യം,
                                              sym->st_size, sym->st_info, 0,
                                              sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s_rel, got_offset, dyn_reloc_type,
			  attr->dyn_index);
	}
    } അല്ലെങ്കിൽ {
        put_elf_reloc(symtab_section, s1->got, got_offset, dyn_reloc_type,
                      sym_index);
    }

    എങ്കിൽ (need_plt_entry) {
        attr->plt_offset = create_plt_entry(s1, got_offset, attr);

        /* create a symbol 'sym@plt' for the PLT jump vector */
        len = strlen(name);
        എങ്കിൽ (len > വലുപ്പം plt_name - 5)
            len = വലുപ്പം plt_name - 5;
        memcpy(plt_name, name, len);
        strcpy(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_offset, 0,
            ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0, s1->plt->sh_അക്കം, plt_name);
    } അല്ലെങ്കിൽ {
        attr->got_offset = got_offset;
    }

    തിരികെ attr;
}

/* build GOT and PLT entries */
/* Two passes because R_JMP_SLOT should become first. Some targets
   (arm, arm64) do not allow mixing R_JMP_SLOT and R_GLOB_DAT. */
ST_FUNC ശൂന്യം build_got_entries(TCCState *s1, പൂർണ്ണസംഖ്യ got_sym)
{
    Section *s;
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    പൂർണ്ണസംഖ്യ i, type, gotplt_entry, reloc_type, sym_index;
    ഘടന sym_attr *attr;
    പൂർണ്ണസംഖ്യ pass = 0;
redo:
    വേണ്ടി(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        എങ്കിൽ (s->sh_type != SHT_RELX)
            തുടരുക;
        /* no need to handle got relocations */
        എങ്കിൽ (s->link != symtab_section)
            തുടരുക;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_entry = gotplt_entry_type(type);
            എങ്കിൽ (gotplt_entry == -1) {
                tcc_error_noabort ("Unknown relocation type for got: %d", type);
                തുടരുക;
            }
            sym_index = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];

            എങ്കിൽ (gotplt_entry == NO_GOTPLT_ENTRY) {
                തുടരുക;
            }

            /* Automatically create PLT/GOT [entry] if it is an undefined
	       reference (resolved at runtime), or the symbol is absolute,
	       probably created by tcc_add_symbol, and thus on 64-bit
	       targets might be too far from application code.  */
            എങ്കിൽ (gotplt_entry == AUTO_GOTPLT_ENTRY) {
                എങ്കിൽ (sym->st_shndx == SHN_UNDEF) {
                    ElfW(Sym) *esym;
		    പൂർണ്ണസംഖ്യ dynindex;
                    എങ്കിൽ (!PCRELATIVE_DLLPLT
                        && (s1->output_type & TCC_OUTPUT_DYN))
                        തുടരുക;
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
		    എങ്കിൽ (s1->dynsym) {
			/* dynsym isn't set for -run :-/  */
			dynindex = get_sym_attr(s1, sym_index, 0)->dyn_index;
			esym = (ElfW(Sym) *)s1->dynsym->data + dynindex;
			എങ്കിൽ (dynindex
			    && (ELFW(ST_TYPE)(esym->st_info) == STT_FUNC
				|| (ELFW(ST_TYPE)(esym->st_info) == STT_NOTYPE
				    && ELFW(ST_TYPE)(sym->st_info) == STT_FUNC)))
			    പോകുക jmp_slot;
		    }
                } അല്ലെങ്കിൽ എങ്കിൽ (sym->st_shndx == SHN_ABS) {
                    എങ്കിൽ (sym->st_മൂല്യം == 0) /* from tcc_add_btstub() */
                        തുടരുക;
#ifndef TCC_TARGET_ARM
                    എങ്കിൽ (PTR_SIZE != 8)
                        തുടരുക;
#endif
                    /* from tcc_add_symbol(): on 64 bit platforms these
                       need to go through .got */
                } അല്ലെങ്കിൽ
                    തുടരുക;
            }

#ifdef TCC_TARGET_I386
            എങ്കിൽ ((type == R_386_PLT32 || type == R_386_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		എങ്കിൽ (pass != 0)
		    തുടരുക;
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_PC32);
                തുടരുക;
            }
#endif
#ifdef TCC_TARGET_X86_64
            എങ്കിൽ ((type == R_X86_64_PLT32 || type == R_X86_64_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		എങ്കിൽ (pass != 0)
		    തുടരുക;
                rel->r_info = ELFW(R_INFO)(sym_index, R_X86_64_PC32);
                തുടരുക;
            }
#endif
            reloc_type = code_reloc(type);
            എങ്കിൽ (reloc_type == -1) {
                tcc_error_noabort ("Unknown relocation type: %d", type);
                തുടരുക;
            }

            എങ്കിൽ (reloc_type != 0) {
        jmp_slot:
	        എങ്കിൽ (pass != 0)
                    തുടരുക;
                reloc_type = R_JMP_SLOT;
            } അല്ലെങ്കിൽ {
	        എങ്കിൽ (pass != 1)
                    തുടരുക;
                reloc_type = R_GLOB_DAT;
            }

            എങ്കിൽ (!s1->got)
                got_sym = build_got(s1);

            എങ്കിൽ (gotplt_entry == BUILD_GOT_ONLY)
                തുടരുക;

            attr = put_got_entry(s1, reloc_type, sym_index);

            എങ്കിൽ (reloc_type == R_JMP_SLOT)
                rel->r_info = ELFW(R_INFO)(attr->plt_sym, type);
        }
    }
    എങ്കിൽ (++pass < 2)
        പോകുക redo;
    /* .rel.plt refers to .got actually */
    എങ്കിൽ (s1->plt && s1->plt->reloc)
        s1->plt->reloc->sh_info = s1->got->sh_അക്കം;
    എങ്കിൽ (got_sym) /* set size */
        ((ElfW(Sym)*)symtab_section->data)[got_sym].st_size = s1->got->data_offset;
}
#endif /* def NEED_BUILD_GOT */

ST_FUNC പൂർണ്ണസംഖ്യ set_global_sym(TCCState *s1, സ്ഥിരം അക്ഷരം *name, Section *sec, addr_t offs)
{
    പൂർണ്ണസംഖ്യ shn = sec ? sec->sh_അക്കം : offs || !name ? SHN_ABS : SHN_UNDEF;
    എങ്കിൽ (sec && offs == -1)
        offs = sec->data_offset;
    തിരികെ set_elf_sym(symtab_section, offs, 0,
        ELFW(ST_INFO)(name ? STB_GLOBAL : STB_LOCAL, STT_NOTYPE), 0, shn, name);
}

സ്ഥിതം ശൂന്യം add_init_array_defines(TCCState *s1, സ്ഥിരം അക്ഷരം *section_name)
{
    Section *s;
    addr_t end_offset;
    അക്ഷരം buf[1024];
    s = have_section(s1, section_name);
    എങ്കിൽ (!s || !(s->sh_flags & SHF_ALLOC)) {
        end_offset = 0;
        s = text_section;
    } അല്ലെങ്കിൽ {
        end_offset = s->data_offset;
    }
    snprintf(buf, വലുപ്പം(buf), "__%s_start", section_name + 1);
    set_global_sym(s1, buf, s, 0);
    snprintf(buf, വലുപ്പം(buf), "__%s_end", section_name + 1);
    set_global_sym(s1, buf, s, end_offset);
}

ST_FUNC ശൂന്യം add_array (TCCState *s1, സ്ഥിരം അക്ഷരം *sec, പൂർണ്ണസംഖ്യ c)
{
    Section *s;
    s = find_section(s1, sec);
    s->sh_flags = shf_RELRO;
    s->sh_type = sec[1] == 'i' ? SHT_INIT_ARRAY : SHT_FINI_ARRAY;
    put_elf_reloc (s1->symtab, s, s->data_offset, R_DATA_PTR, c);
    section_ptr_add(s, PTR_SIZE);
}

#ifdef CONFIG_TCC_BCHECK
ST_FUNC ശൂന്യം tcc_add_bcheck(TCCState *s1)
{
    എങ്കിൽ (0 == s1->do_bounds_check)
        തിരികെ;
    section_ptr_add(bounds_section, വലുപ്പം(addr_t));
}
#endif

/* set symbol to STB_LOCAL and resolve. The point is to not export it as
   a dynamic symbol to allow so's to have one each with a different value. */
സ്ഥിതം ശൂന്യം set_local_sym(TCCState *s1, സ്ഥിരം അക്ഷരം *name, Section *s, പൂർണ്ണസംഖ്യ offset)
{
    പൂർണ്ണസംഖ്യ c = find_elf_sym(s1->symtab, name);
    എങ്കിൽ (c) {
        ElfW(Sym) *esym = (ElfW(Sym)*)s1->symtab->data + c;
        esym->st_info = ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE);
        esym->st_മൂല്യം = offset;
        esym->st_shndx = s->sh_അക്കം;
    }
}

/* avoid generating debug/test_coverage code for stub functions */
സ്ഥിതം ശൂന്യം tcc_compile_string_no_debug(TCCState *s, സ്ഥിരം അക്ഷരം *str)
{
    പൂർണ്ണസംഖ്യ save_do_debug = s->do_debug;
    പൂർണ്ണസംഖ്യ save_test_coverage = s->test_coverage;

    s->do_debug = 0;
    s->test_coverage = 0;
    tcc_compile_string(s, str);
    s->do_debug = save_do_debug;
    s->test_coverage = save_test_coverage;
}

#ifdef CONFIG_TCC_BACKTRACE
സ്ഥിതം ശൂന്യം put_ptr(TCCState *s1, Section *s, പൂർണ്ണസംഖ്യ offs)
{
    പൂർണ്ണസംഖ്യ c;
    c = set_global_sym(s1, ശൂന്യ, s, offs);
    s = data_section;
    put_elf_reloc (s1->symtab, s, s->data_offset, R_DATA_PTR, c);
    section_ptr_add(s, PTR_SIZE);
}

ST_FUNC ശൂന്യം tcc_add_btstub(TCCState *s1)
{
    Section *s;
    പൂർണ്ണസംഖ്യ n, o, *p;
    CString cstr;
    സ്ഥിരം അക്ഷരം *__rt_info = &"___rt_info"[!s1->leading_underscore];

    s = data_section;
    /* Align to PTR_SIZE */
    section_add(s, 0, PTR_SIZE);
    o = s->data_offset;
    /* create a struct rt_context (see tccrun.c) */
    എങ്കിൽ (s1->dwarf) {
        put_ptr(s1, dwarf_വരി_section, 0);
        put_ptr(s1, dwarf_വരി_section, -1);
	എങ്കിൽ (s1->dwarf >= 5)
            put_ptr(s1, dwarf_വരി_str_section, 0);
	അല്ലെങ്കിൽ
            put_ptr(s1, dwarf_str_section, 0);
    }
    അല്ലെങ്കിൽ
    {
        put_ptr(s1, stab_section, 0);
        put_ptr(s1, stab_section, -1);
        put_ptr(s1, stab_section->link, 0);
    }

    /* skip esym_start/esym_end/elf_str (not loaded) */
    section_ptr_add(s, 3 * PTR_SIZE);

    എങ്കിൽ (s1->output_type == TCC_OUTPUT_MEMORY && 0 == s1->dwarf) {
        put_ptr(s1, text_section, 0);
    } അല്ലെങ്കിൽ {
        /* prog_base : local nameless symbol with offset 0 at SHN_ABS */
        put_ptr(s1, ശൂന്യ, 0);
#എങ്കിൽ defined TCC_TARGET_MACHO
        /* adjust for __PAGEZERO */
        എങ്കിൽ (s1->dwarf == 0 && s1->output_type == TCC_OUTPUT_EXE)
            write64le(data_section->data + data_section->data_offset - PTR_SIZE,
	              (uint64_t)1 << 32);
#endif
    }
    n = 3 * PTR_SIZE;
#ifdef CONFIG_TCC_BCHECK
    എങ്കിൽ (s1->do_bounds_check) {
        put_ptr(s1, bounds_section, 0);
        n -= PTR_SIZE;
    }
#endif
    section_ptr_add(s, n);
    p = section_ptr_add(s, 2 * വലുപ്പം (പൂർണ്ണസംഖ്യ));
    p[0] = s1->rt_അക്കം_callers;
    p[1] = s1->dwarf;
    // if (s->data_offset - o != 10*PTR_SIZE + 2*sizeof (int)) exit(99);

    എങ്കിൽ (s1->output_type == TCC_OUTPUT_MEMORY) {
        set_global_sym(s1, __rt_info, s, o);
        തിരികെ;
    }

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern void __bt_init(),__bt_exit(),__bt_init_dll();"
        "static void *__rt_info[];"
        "__attribute__((constructor)) static void __bt_init_rt(){");
#ifdef TCC_TARGET_PE
    എങ്കിൽ (s1->output_type == TCC_OUTPUT_DLL)
#ifdef CONFIG_TCC_BCHECK
        cstr_printf(&cstr, "__bt_init_dll(%d);", s1->do_bounds_check);
#അല്ലെങ്കിൽ
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

സ്ഥിതം ശൂന്യം tcc_tcov_add_file(TCCState *s1, സ്ഥിരം അക്ഷരം *filename)
{
    CString cstr;
    ശൂന്യം *ptr;
    അക്ഷരം wd[1024];

    എങ്കിൽ (tcov_section == ശൂന്യ)
        തിരികെ;
    section_ptr_add(tcov_section, 1);
    write32le (tcov_section->data, tcov_section->data_offset);

    cstr_new (&cstr);
    എങ്കിൽ (filename[0] == '/')
        cstr_printf (&cstr, "%s.tcov", filename);
    അല്ലെങ്കിൽ {
        getcwd (wd, വലുപ്പം(wd));
        cstr_printf (&cstr, "%s/%s.tcov", wd, filename);
    }
    ptr = section_ptr_add(tcov_section, cstr.size + 1);
    strcpy((അക്ഷരം *)ptr, cstr.data);
    unlink((അക്ഷരം *)ptr);
#ifdef _WIN32
    normalize_slashes((അക്ഷരം *)ptr);
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
ST_FUNC ശൂന്യം tccelf_add_crtbegin(TCCState *s1)
{
#എങ്കിൽ TARGETOS_OpenBSD
    എങ്കിൽ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crt0.o");
    എങ്കിൽ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbeginS.o");
    അല്ലെങ്കിൽ
        tcc_add_crt(s1, "crtbegin.o");
#അല്ലെങ്കിലെങ്കിൽ TARGETOS_FreeBSD || TARGETOS_NetBSD
    എങ്കിൽ (s1->output_type != TCC_OUTPUT_DLL)
#എങ്കിൽ TARGETOS_FreeBSD
        tcc_add_crt(s1, "crt1.o");
#അല്ലെങ്കിൽ
        tcc_add_crt(s1, "crt0.o");
#endif
    tcc_add_crt(s1, "crti.o");
    എങ്കിൽ (s1->static_link)
        tcc_add_crt(s1, "crtbeginT.o");
    അല്ലെങ്കിൽ എങ്കിൽ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbeginS.o");
    അല്ലെങ്കിൽ
        tcc_add_crt(s1, "crtbegin.o");
#അല്ലെങ്കിലെങ്കിൽ TARGETOS_ANDROID
    എങ്കിൽ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbegin_so.o");
    അല്ലെങ്കിൽ
        tcc_add_crt(s1, "crtbegin_dynamic.o");
#അല്ലെങ്കിൽ
    എങ്കിൽ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crt1.o");
    tcc_add_crt(s1, "crti.o");
#endif
}

ST_FUNC ശൂന്യം tccelf_add_crtend(TCCState *s1)
{
#എങ്കിൽ TARGETOS_OpenBSD
    എങ്കിൽ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtendS.o");
    അല്ലെങ്കിൽ
        tcc_add_crt(s1, "crtend.o");
#അല്ലെങ്കിലെങ്കിൽ TARGETOS_FreeBSD || TARGETOS_NetBSD
    എങ്കിൽ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtendS.o");
    അല്ലെങ്കിൽ
        tcc_add_crt(s1, "crtend.o");
    tcc_add_crt(s1, "crtn.o");
#അല്ലെങ്കിലെങ്കിൽ TARGETOS_ANDROID
    എങ്കിൽ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtend_so.o");
    അല്ലെങ്കിൽ
        tcc_add_crt(s1, "crtend_android.o");
#അല്ലെങ്കിൽ
    tcc_add_crt(s1, "crtn.o");
#endif
}
#endif /* TCC_TARGET_UNIX */

#ifndef TCC_TARGET_PE
/* add tcc runtime libraries */
ST_FUNC ശൂന്യം tcc_add_runtime(TCCState *s1)
{
    s1->filetype = 0;

#ifdef CONFIG_TCC_BCHECK
    tcc_add_bcheck(s1);
#endif
    tcc_add_pragma_libs(s1);

    /* add libc */
    എങ്കിൽ (!s1->nostdlib) {
        പൂർണ്ണസംഖ്യ lpthread = s1->option_pthread;

#ifdef CONFIG_TCC_BCHECK
        എങ്കിൽ (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    എങ്കിൽ (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    അല്ലെങ്കിൽ
                tcc_add_support(s1, "bcheck.o");
# എങ്കിൽ !(TARGETOS_OpenBSD || TARGETOS_NetBSD)
            tcc_add_library(s1, "dl");
# endif
            lpthread = 1;
        }
#endif
#ifdef CONFIG_TCC_BACKTRACE
        എങ്കിൽ (s1->do_backtrace) {
            എങ്കിൽ (s1->output_type & TCC_OUTPUT_EXE)
                tcc_add_support(s1, "bt-exe.o");
            എങ്കിൽ (s1->output_type != TCC_OUTPUT_DLL)
                tcc_add_support(s1, "bt-log.o");
            tcc_add_btstub(s1);
            lpthread = 1;
        }
#endif
        എങ്കിൽ (lpthread)
            tcc_add_library(s1, "pthread");
        tcc_add_library(s1, "c");
#ifdef TCC_LIBGCC
        എങ്കിൽ (!s1->static_link) {
            എങ്കിൽ (TCC_LIBGCC[0] == '/')
                tcc_add_file(s1, TCC_LIBGCC);
            അല്ലെങ്കിൽ
                tcc_add_dll(s1, TCC_LIBGCC, AFF_PRINT_ERROR);
        }
#endif
#എങ്കിൽ defined TCC_TARGET_ARM && TARGETOS_FreeBSD
        tcc_add_library(s1, "gcc_s"); // unwind code
#endif
        എങ്കിൽ (TCC_LIBTCC1[0]) {
            tcc_add_support(s1, TCC_LIBTCC1);
            tcc_add_library(s1, "c");
        }
#ifndef TCC_TARGET_MACHO
        എങ്കിൽ (s1->output_type != TCC_OUTPUT_MEMORY)
            tccelf_add_crtend(s1);
#endif
    }
}
#endif /* ndef TCC_TARGET_PE */

/* set _etext/_edata/_end  f=0:set  f=1:when_needed  f=2,3:just_update */
സ്ഥിതം ശൂന്യം set_linker_sym(TCCState *s1, സ്ഥിരം അക്ഷരം *name, Section *sec, പൂർണ്ണസംഖ്യ f)
{
    പൂർണ്ണസംഖ്യ sym_index, esym_index, defined;
    ElfW(Sym) *sym, *esym;
    sym_index = find_elf_sym(symtab_section, name);
    sym = (ElfW(Sym) *)symtab_section->data + sym_index;
    esym_index = find_elf_sym(s1->dynsymtab_section, name);
    esym = (ElfW(Sym) *)s1->dynsymtab_section->data + esym_index;
    defined = sym->st_shndx != SHN_UNDEF
        || (esym->st_shndx != SHN_UNDEF && esym->st_size);
    തിരഞ്ഞെടുപ്പ് (f) {
    അവസ്ഥ 1: /* old symbols w/o '_' */
        എങ്കിൽ (!(sym_index || esym_index) || defined)
            നിർത്തുക;
    അവസ്ഥ 0:
        എങ്കിൽ (defined) {
            tcc_warning("linker symbol '%s' already defined", name);
            നിർത്തുക;
        }
        sym_index = set_global_sym(s1, name, sec, -1);
        get_sym_attr(s1, sym_index, 1)->linker_sym = 1;
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി: /* update (bss only) */
        എങ്കിൽ (get_sym_attr(s1, sym_index, 0)->linker_sym)
            sym->st_മൂല്യം = sec->data_offset;
    }
#ifndef ELF_OBJ_ONLY
    എങ്കിൽ (name[0] == '_')
        set_linker_sym(s1, name + 1, sec, f + 1);
#endif
}

/* add various standard linker symbols (must be done after the
   sections are filled (for example after allocating common
   symbols)) */
സ്ഥിതം ശൂന്യം tcc_add_linker_symbols(TCCState *s1)
{
    അക്ഷരം buf[1024];
    പൂർണ്ണസംഖ്യ i;
    Section *s;

    set_linker_sym(s1, "_etext", text_section, 0);
    set_linker_sym(s1, "_edata", data_section, 0);
    set_linker_sym(s1, "_end", bss_section, 0);
#എങ്കിൽ TARGETOS_OpenBSD
    set_global_sym(s1, "__executable_start", ശൂന്യ, ELF_START_ADDR);
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
    വേണ്ടി(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        എങ്കിൽ ((s->sh_flags & SHF_ALLOC)
            && (s->sh_type == SHT_PROGBITS || s->sh_type == SHT_NOBITS
                || s->sh_type == SHT_STRTAB)) {
            /* check if section name can be expressed in C */
            സ്ഥിരം അക്ഷരം *p0, *p;
            p0 = s->name;
            എങ്കിൽ (*p0 == '.')
                ++p0;
            p = p0;
            വേണ്ടി(;;) {
                പൂർണ്ണസംഖ്യ c = *p;
                എങ്കിൽ (!c)
                    നിർത്തുക;
                എങ്കിൽ (!isid(c) && !isnum(c))
                    പോകുക next_sec;
                p++;
            }
            snprintf(buf, വലുപ്പം(buf), "__start_%s", p0);
            set_global_sym(s1, buf, s, 0);
            snprintf(buf, വലുപ്പം(buf), "__stop_%s", p0);
            set_global_sym(s1, buf, s, -1);
        }
    next_sec: ;
    }
}

ST_FUNC ശൂന്യം resolve_common_syms(TCCState *s1)
{
    ElfW(Sym) *sym;

    /* Allocate common symbols in BSS.  */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        എങ്കിൽ (sym->st_shndx == SHN_COMMON && sym->st_size) {
            /* symbol alignment is in st_value for SHN_COMMONs */
	    sym->st_മൂല്യം = section_add(bss_section, sym->st_size,
					sym->st_മൂല്യം);
            sym->st_shndx = bss_section->sh_അക്കം;
        }
    }

    /* Now assign linker provided symbols their value.  */
    എങ്കിൽ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_linker_symbols(s1);
}

#ifndef ELF_OBJ_ONLY
ST_FUNC ശൂന്യം fill_got_entry(TCCState *s1, ElfW_Rel *rel)
{
    പൂർണ്ണസംഖ്യ sym_index = ELFW(R_SYM) (rel->r_info);
    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->data)[sym_index];
    ഘടന sym_attr *attr = get_sym_attr(s1, sym_index, 0);
    unsigned offset = attr->got_offset;

    എങ്കിൽ (0 == offset)
        തിരികെ;
    section_reserve(s1->got, offset + PTR_SIZE);
#എങ്കിൽ PTR_SIZE == 8
    write64le(s1->got->data + offset, sym->st_മൂല്യം);
#അല്ലെങ്കിൽ
    write32le(s1->got->data + offset, sym->st_മൂല്യം);
#endif
}

/* Perform relocation to GOT or PLT entries */
ST_FUNC ശൂന്യം fill_got(TCCState *s1)
{
    Section *s;
    ElfW_Rel *rel;
    പൂർണ്ണസംഖ്യ i;

    വേണ്ടി(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        എങ്കിൽ (s->sh_type != SHT_RELX)
            തുടരുക;
        /* no need to handle got relocations */
        എങ്കിൽ (s->link != symtab_section)
            തുടരുക;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            തിരഞ്ഞെടുപ്പ് (ELFW(R_TYPE) (rel->r_info)) {
                അവസ്ഥ R_X86_64_GOT32:
                അവസ്ഥ R_X86_64_GOTPCREL:
		അവസ്ഥ R_X86_64_GOTPCRELX:
		അവസ്ഥ R_X86_64_REX_GOTPCRELX:
                അവസ്ഥ R_X86_64_PLT32:
                    fill_got_entry(s1, rel);
                    നിർത്തുക;
            }
        }
    }
}

/* See put_got_entry for a description.  This is the second stage
   where GOT references to local defined symbols are rewritten.  */
സ്ഥിതം ശൂന്യം fill_local_got_entries(TCCState *s1)
{
    ElfW_Rel *rel;
    എങ്കിൽ (!s1->got->reloc)
        തിരികെ;
    for_each_elem(s1->got->reloc, 0, rel, ElfW_Rel) {
	എങ്കിൽ (ELFW(R_TYPE)(rel->r_info) == R_RELATIVE) {
	    പൂർണ്ണസംഖ്യ sym_index = ELFW(R_SYM) (rel->r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->data)[sym_index];
	    ഘടന sym_attr *attr = get_sym_attr(s1, sym_index, 0);
	    unsigned offset = attr->got_offset;
	    എങ്കിൽ (offset != rel->r_offset - s1->got->sh_addr)
	        tcc_error_noabort("fill_local_got_entries: huh?");
	    rel->r_info = ELFW(R_INFO)(0, R_RELATIVE);
#എങ്കിൽ SHT_RELX == SHT_RELA
	    rel->r_addend = sym->st_മൂല്യം;
#അല്ലെങ്കിൽ
	    /* All our REL architectures also happen to be 32bit LE.  */
	    write32le(s1->got->data + offset, sym->st_മൂല്യം);
#endif
	}
    }
}

/* Bind symbols of executable: resolve undefined symbols from exported symbols
   in shared libraries */
സ്ഥിതം ശൂന്യം bind_exe_dynsyms(TCCState *s1, പൂർണ്ണസംഖ്യ is_PIE)
{
    സ്ഥിരം അക്ഷരം *name;
    പൂർണ്ണസംഖ്യ sym_index, index;
    ElfW(Sym) *sym, *esym;
    പൂർണ്ണസംഖ്യ type;

    /* Resolve undefined symbols from dynamic symbols. When there is a match:
       - if STT_FUNC or STT_GNU_IFUNC symbol -> add it in PLT
       - if STT_OBJECT symbol -> add it in .bss section with suitable reloc */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        എങ്കിൽ (sym->st_shndx == SHN_UNDEF
            /* bss symbols may be initialized in the shared library */
            || sym->st_shndx == SHN_COMMON
            || sym->st_shndx == bss_section->sh_അക്കം) {
            name = (അക്ഷരം *) symtab_section->link->data + sym->st_name;
            sym_index = find_elf_sym(s1->dynsymtab_section, name);
            esym = &((ElfW(Sym) *)s1->dynsymtab_section->data)[sym_index];
            എങ്കിൽ (sym_index && esym->st_shndx != SHN_UNDEF) {
                എങ്കിൽ (is_PIE)
                    തുടരുക;
                type = ELFW(ST_TYPE)(esym->st_info);
                എങ്കിൽ ((type == STT_FUNC) || (type == STT_GNU_IFUNC)) {
                    /* Indirect functions shall have STT_FUNC type in executable
                     * dynsym section. Indeed, a dlsym call following a lazy
                     * resolution would pick the symbol value from the
                     * executable dynsym entry which would contain the address
                     * of the function wanted by the caller of dlsym instead of
                     * the address of the function that would return that
                     * address */
                    പൂർണ്ണസംഖ്യ dynindex
		      = put_elf_sym(s1->dynsym, 0, esym->st_size,
				    ELFW(ST_INFO)(STB_GLOBAL,STT_FUNC), 0, 0,
				    name);
		    പൂർണ്ണസംഖ്യ index = sym - (ElfW(Sym) *) symtab_section->data;
		    get_sym_attr(s1, index, 1)->dyn_index = dynindex;
                } അല്ലെങ്കിൽ എങ്കിൽ (type == STT_OBJECT) {
                    unsigned long offset;
                    ElfW(Sym) *dynsym;
                    എങ്കിൽ (sym->st_shndx == bss_section->sh_അക്കം) {
                        offset = sym->st_മൂല്യം;
                    } അല്ലെങ്കിൽ {
                        offset = bss_section->data_offset;
                        /* XXX: which alignment ? */
                        offset = (offset + 16 - 1) & -16;
                        bss_section->data_offset = offset + esym->st_size;
                    }
                    set_elf_sym (s1->symtab, offset, esym->st_size,
                                 esym->st_info, 0, bss_section->sh_അക്കം, name);
                    index = put_elf_sym(s1->dynsym, offset, esym->st_size,
                                        esym->st_info, 0, bss_section->sh_അക്കം,
                                        name);
                    /* Ensure R_COPY works for weak symbol aliases */
                    എങ്കിൽ (ELFW(ST_BIND)(esym->st_info) == STB_WEAK) {
                        for_each_elem(s1->dynsymtab_section, 1, dynsym, ElfW(Sym)) {
                            എങ്കിൽ ((dynsym->st_മൂല്യം == esym->st_മൂല്യം)
                                && (ELFW(ST_BIND)(dynsym->st_info) == STB_GLOBAL)) {
                                അക്ഷരം *dynname = (അക്ഷരം *) s1->dynsymtab_section->link->data
                                                + dynsym->st_name;
                                put_elf_sym(s1->dynsym, offset, dynsym->st_size,
                                            dynsym->st_info, 0,
                                            bss_section->sh_അക്കം, dynname);
                                നിർത്തുക;
                            }
                        }
                    }
                    put_elf_reloc(s1->dynsym, bss_section,
                                  offset, R_COPY, index);
                }
            } അല്ലെങ്കിൽ എങ്കിൽ (sym->st_shndx == SHN_UNDEF) {
                /* STB_WEAK undefined symbols are accepted */
                /* XXX: _fp_hw seems to be part of the ABI, so we ignore it */
                എങ്കിൽ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK ||
                    !strcmp(name, "_fp_hw")) {
                } അല്ലെങ്കിൽ {
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
സ്ഥിതം ശൂന്യം bind_libs_dynsyms(TCCState *s1)
{
    സ്ഥിരം അക്ഷരം *name;
    പൂർണ്ണസംഖ്യ dynsym_index;
    ElfW(Sym) *sym, *esym;

    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        name = (അക്ഷരം *)symtab_section->link->data + sym->st_name;
        dynsym_index = find_elf_sym(s1->dynsymtab_section, name);
        എങ്കിൽ (sym->st_shndx != SHN_UNDEF) {
            എങ്കിൽ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL
                && (dynsym_index || s1->rdynamic))
                set_elf_sym(s1->dynsym, sym->st_മൂല്യം, sym->st_size,
                            sym->st_info, 0, sym->st_shndx, name);
        } അല്ലെങ്കിൽ എങ്കിൽ (dynsym_index) {
            esym = (ElfW(Sym) *)s1->dynsymtab_section->data + dynsym_index;
            എങ്കിൽ (esym->st_shndx == SHN_UNDEF) {
                /* weak symbols can stay undefined */
                എങ്കിൽ (ELFW(ST_BIND)(esym->st_info) != STB_WEAK)
                    tcc_warning("unresolved dynamic reference to '%s'", name);
            }
        }
    }
}

/* Export all non local symbols. This is used by shared libraries so that the
   non local symbols they define can resolve a reference in another shared
   library or in the executable. Correspondingly, it allows undefined local
   symbols to be resolved by other shared libraries or by the executable. */
സ്ഥിതം ശൂന്യം export_global_syms(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ dynindex, index;
    സ്ഥിരം അക്ഷരം *name;
    ElfW(Sym) *sym;
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        എങ്കിൽ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
	    name = (അക്ഷരം *) symtab_section->link->data + sym->st_name;
	    dynindex = set_elf_sym(s1->dynsym, sym->st_മൂല്യം, sym->st_size,
				   sym->st_info, 0, sym->st_shndx, name);
	    index = sym - (ElfW(Sym) *) symtab_section->data;
            get_sym_attr(s1, index, 1)->dyn_index = dynindex;
        }
    }
}

/* decide if an unallocated section should be output. */
സ്ഥിതം പൂർണ്ണസംഖ്യ set_sec_sizes(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ i;
    Section *s;
    പൂർണ്ണസംഖ്യ textrel = 0;
    പൂർണ്ണസംഖ്യ file_type = s1->output_type;

    /* Allocate strings for section names */
    വേണ്ടി(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        എങ്കിൽ (s->sh_type == SHT_RELX && !(s->sh_flags & SHF_ALLOC)) {
            /* when generating a DLL, we include relocations but
               we may patch them */
            എങ്കിൽ ((file_type & TCC_OUTPUT_DYN)
                && (s1->sections[s->sh_info]->sh_flags & SHF_ALLOC)) {
                പൂർണ്ണസംഖ്യ എണ്ണം_2 = prepare_dynamic_rel(s1, s);
                എങ്കിൽ (എണ്ണം_2) {
                    /* allocate the section */
                    s->sh_flags |= SHF_ALLOC;
                    s->sh_size = എണ്ണം_2 * വലുപ്പം(ElfW_Rel);
                    എങ്കിൽ (s1->sections[s->sh_info]->sh_flags & SHF_EXECINSTR)
                        textrel += എണ്ണം_2;
                }
            }
        } അല്ലെങ്കിൽ എങ്കിൽ ((s->sh_flags & SHF_ALLOC)
#ifdef TCC_TARGET_ARM
                   || s->sh_type == SHT_ARM_ATTRIBUTES
#endif
                   || s1->do_debug) {
            s->sh_size = s->data_offset;
        }
    }
    തിരികെ textrel;
}

/* various data used under elf_output_file() */
ഘടന dyn_inf {
    Section *dynamic;
    Section *dynstr;
    Section *interp;
    Section *note;
    Section *gnu_hash;
    ഘടന {
        /* Info to be copied in dynamic section */
        unsigned long data_offset;
        addr_t rel_addr;
        addr_t rel_size;
    };

    ElfW(Phdr) *phdr;
    പൂർണ്ണസംഖ്യ phnum;
    പൂർണ്ണസംഖ്യ shnum;
    പൂർണ്ണസംഖ്യ tls;
    പൂർണ്ണസംഖ്യ relro;
    പൂർണ്ണസംഖ്യ notes;
    പൂർണ്ണസംഖ്യ ehfr;
    പൂർണ്ണസംഖ്യ dyna;
};

/* Decide the layout of sections loaded in memory. This must be done before
   program headers are filled since they contain info about the layout.
   We do the following ordering: interp, symbol tables, relocations, progbits,
   nobits */
സ്ഥിതം പൂർണ്ണസംഖ്യ sort_sections(TCCState *s1, പൂർണ്ണസംഖ്യ *sec_order, ഘടന dyn_inf *d)
{
    Section *s;
    പൂർണ്ണസംഖ്യ i, j, k, f, f0, n;
    പൂർണ്ണസംഖ്യ nb_sections = s1->nb_sections;
    പൂർണ്ണസംഖ്യ *sec_cls = sec_order + nb_sections;
    പൂർണ്ണസംഖ്യ tls_align = 0; /* need common alignment for all tls sections */

    വേണ്ടി (i = 1; i < nb_sections; i++) {
        s = s1->sections[i];
        എങ്കിൽ (0 == s->sh_name) {
            j = 0x900; /* no sh_name: won't go to file */
        } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_flags & SHF_ALLOC) {
            j = 0x100;
            എങ്കിൽ ((s->sh_flags & (SHF_WRITE|SHF_TLS)) == SHF_WRITE)
                j = 0x200;
        } അല്ലെങ്കിൽ {
            j = 0x700;
        }
        എങ്കിൽ (j >= 0x700 && s1->output_format != TCC_OUTPUT_FORMAT_ELF)
            s->sh_size = 0, j = 0x900;

        എങ്കിൽ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM) {
            k = 0x10;
        } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_type == SHT_STRTAB && strcmp(s->name, ".stabstr")) {
            k = 0x11;
            എങ്കിൽ (i == nb_sections - 1) /* ".shstrtab" assumed to stay last */
                k = 0xff;
        } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_type == SHT_HASH || s->sh_type == SHT_GNU_HASH) {
            k = 0x12;
        } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_type == SHT_GNU_verdef
                  || s->sh_type == SHT_GNU_verneed
                  || s->sh_type == SHT_GNU_versym) {
            k = 0x13;
        } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_type == SHT_RELX) {
            k = 0x20;
            എങ്കിൽ (s1->plt && s == s1->plt->reloc)
                k = 0x21;
        } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_flags & SHF_EXECINSTR) {
            k = 0x60;
        /* RELRO sections --> */
        } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_flags & SHF_TLS) {
            എങ്കിൽ (s->sh_addralign > tls_align)
                tls_align = s->sh_addralign;
            k = 0x40 + (s->sh_type == SHT_NOBITS);
        } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_type == SHT_PREINIT_ARRAY) {
            k = 0x42;
        } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_type == SHT_INIT_ARRAY) {
            k = 0x43;
        } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_type == SHT_FINI_ARRAY) {
            k = 0x44;
        } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_type == SHT_DYNAMIC) {
            k = 0x48;
        } അല്ലെങ്കിൽ എങ്കിൽ (s == s1->got) {
            k = 0x49; /* .got as RELRO needs BIND_NOW in DT_FLAGS */
        } അല്ലെങ്കിൽ എങ്കിൽ (s->reloc && (s->reloc->sh_flags & SHF_ALLOC) && j == 0x100) {
            k = 0x45; /* +1 for data.ro */
        /* <-- */
        } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_type == SHT_NOTE) {
            k = 0x08, d->notes = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_type == SHT_NOBITS) {
            k = 0x70; /* bss */
        } അല്ലെങ്കിൽ എങ്കിൽ (s == d->interp) {
            k = 0x00;
        } അല്ലെങ്കിൽ {
            k = 0x50; /* data */
        }
        k += j;
        /* make our standard sections come last to have _etext/_edata correct values */
        എങ്കിൽ (s->sh_അക്കം <= bss_section->sh_അക്കം)
            ++k;
        /* make RELRO section writable */
        എങ്കിൽ ((k & 0xfff0) == 0x140)
            k += 0x100, s->sh_flags |= SHF_WRITE;
        /* sort by insert */
        വേണ്ടി (n = i; n > 1 && k < (f = sec_cls[n - 1]); --n)
            sec_cls[n] = f, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
    }
    sec_order[0] = 0;
    d->shnum = 1;

#define SHFX_NEWPH (1 << 4)
#define SHFX_RELRO (1 << 5)

    /* count PT_LOAD headers needed */
    n = f0 = 0;
    വേണ്ടി (i = 1; i < nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        k = sec_cls[i];
        f = 0;
        എങ്കിൽ (k < 0x900)
            ++d->shnum;
        എങ്കിൽ (k < 0x700) {
            f = s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR);
#എങ്കിൽ TARGETOS_NetBSD || TARGETOS_FreeBSD
	    /* NetBSD only supports 2 PT_LOAD sections.
	       See: https://blog.netbsd.org/tnf/entry/the_first_report_on_lld */
	    എങ്കിൽ ((f & SHF_WRITE) == 0)
                f |= SHF_EXECINSTR;
            k = 0; /* no relro */
#endif
            എങ്കിൽ ((k & 0xfff0) == 0x240) /* RELRO sections */
                d->relro = 1, f |= SHFX_RELRO;
            /* start new header when flags changed, but avoid zero memsz */
            എങ്കിൽ (f != f0 && s->sh_size)
                f0 = f, ++n, f |= SHFX_NEWPH;
            എങ്കിൽ ((s->sh_flags & SHF_TLS) && s->sh_size) {
                s->sh_addralign = tls_align;
                d->tls = 1, f |= SHF_TLS;
            }
        }
        sec_cls[i] = f;
        //printf("ph %d sec %02d : %3X %3X  %8.2X  %04X  %s\n", (f>0) * n, i, f, k, s->sh_type, (int)s->sh_size, s->name);
    }
    തിരികെ n;
}

സ്ഥിതം ElfW(Phdr) *fill_phdr(ElfW(Phdr) *ph, പൂർണ്ണസംഖ്യ type, Section *s)
{
    ph->p_type = type;
    ph->p_flags = PF_R;
    എങ്കിൽ (s) {
        എങ്കിൽ (s->sh_flags & SHF_WRITE)
            ph->p_flags |= PF_W;
        ph->p_offset = s->sh_offset;
        ph->p_vaddr = s->sh_addr;
        ph->p_filesz = s->sh_size;
        ph->p_align = s->sh_addralign;
    }
    ph->p_paddr = ph->p_vaddr;
    ph->p_memsz = ph->p_filesz;
    തിരികെ ph;
}

സ്ഥിതം ElfW(Phdr) *update_phdr(ElfW(Phdr) *ph, പൂർണ്ണസംഖ്യ type, Section *s, addr_t addr, പൂർണ്ണസംഖ്യ file_offset)
{
    എങ്കിൽ (ph->p_type == 0) {
        fill_phdr(ph, type, s);
    }
    ph->p_filesz = file_offset - ph->p_offset;
    ph->p_memsz = addr - ph->p_vaddr;
    തിരികെ ph;
}

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
സ്ഥിതം പൂർണ്ണസംഖ്യ layout_sections(TCCState *s1, പൂർണ്ണസംഖ്യ *sec_order, ഘടന dyn_inf *d)
{
    Section *s;
    addr_t addr, tmp, align, s_align, base;
    ElfW(Phdr) *ph = ശൂന്യ, *ph2;
    പൂർണ്ണസംഖ്യ i, f, n, phnum, phfill;
    പൂർണ്ണസംഖ്യ file_offset;

    /* compute number of program headers */
    phnum = sort_sections(s1, sec_order, d);
    phfill = 0; /* set to 1 to have dll's with a PT_PHDR */
    എങ്കിൽ (d->interp)
        phfill = 2;
    phnum += phfill;
    എങ്കിൽ (d->dynamic)
        d->dyna = phnum++;
    എങ്കിൽ (d->notes)
        d->notes = phnum++;
    എങ്കിൽ (d->tls)
        d->tls = phnum++;
    എങ്കിൽ (eh_frame_hdr_section)
        d->ehfr = phnum++;
    എങ്കിൽ (d->relro)
        d->relro = phnum++;
    d->phnum = phnum;
    d->phdr = tcc_mallocz(phnum * വലുപ്പം(ElfW(Phdr)));

    file_offset = 0;
    എങ്കിൽ (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
        file_offset = (വലുപ്പം(ElfW(Ehdr)) + phnum * വലുപ്പം(ElfW(Phdr)) + 3) & -4;
        file_offset += d->shnum * വലുപ്പം (ElfW(Shdr));
    }

    s_align = ELF_PAGE_SIZE;
    എങ്കിൽ (s1->section_align)
        s_align = s1->section_align;

    addr = ELF_START_ADDR;
    എങ്കിൽ (s1->output_type & TCC_OUTPUT_DYN)
        addr = 0;

    എങ്കിൽ (s1->has_text_addr) {
        addr = s1->text_addr;
        എങ്കിൽ (0) {
            പൂർണ്ണസംഖ്യ a_offset, p_offset;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_offset = (പൂർണ്ണസംഖ്യ) (addr & (s_align - 1));
            p_offset = file_offset & (s_align - 1);
            എങ്കിൽ (a_offset < p_offset)
                a_offset += s_align;
            file_offset += (a_offset - p_offset);
        }
    }
    base = addr;
    /* compute address after headers */
    addr += file_offset;

    n = 0;
    വേണ്ടി(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        f = sec_order[i + s1->nb_sections];
        align = s->sh_addralign - 1;

        എങ്കിൽ (f == 0) { /* no alloc */
            file_offset = (file_offset + align) & ~align;
            s->sh_offset = file_offset;
            എങ്കിൽ (s->sh_type != SHT_NOBITS)
                file_offset += s->sh_size;
            തുടരുക;
        }

        എങ്കിൽ ((f & SHFX_NEWPH) && n) {
            /* different rwx section flags */
            എങ്കിൽ (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
                /* if in the middle of a page, w e duplicate the page in
                   memory so that one copy is RX and the other is RW */
                എങ്കിൽ ((addr & (s_align - 1)) != 0)
                    addr += s_align;
            } അല്ലെങ്കിൽ {
                align = s_align - 1;
            }
        }

        tmp = addr;
        addr = (addr + align) & ~align;
        file_offset += (പൂർണ്ണസംഖ്യ)(addr - tmp);
        s->sh_offset = file_offset;
        s->sh_addr = addr;

        //printf("%d : %08x %08x %04x %03x %s %d\n", n, (int)file_offset, (int)addr, (int)s->sh_size, s->sh_type, s->name, align + 1);
        addr += s->sh_size;
        എങ്കിൽ (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_size;

        എങ്കിൽ (f & SHFX_NEWPH) {
            /* set new program header */
            ph = &d->phdr[phfill + n];
            fill_phdr(ph, PT_LOAD, s);
            ph->p_align = s_align;
            എങ്കിൽ (f & SHF_EXECINSTR)
                ph->p_flags |= PF_X;
            എങ്കിൽ (n == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_offset = 0;
                ph->p_paddr = ph->p_vaddr = base;
            }
            ++n;
        }

        എങ്കിൽ (ph)
            update_phdr(ph, 0, 0, addr, file_offset);

        എങ്കിൽ (f & SHFX_RELRO) {
            ph2 = update_phdr(&d->phdr[d->relro], PT_GNU_RELRO, s, addr, file_offset);
            ph2->p_align = 1;
        }
        എങ്കിൽ (f & SHF_TLS) {
            ph2 = update_phdr(&d->phdr[d->tls], PT_TLS, s, addr, file_offset);
            എങ്കിൽ (s->sh_type == SHT_NOBITS)
                addr -= s->sh_size;
            /* for xxx-link.c:relocate() */
            s1->tls_start = ph2->p_vaddr;
            s1->tls_end = s1->tls_start + ph2->p_memsz + (-ph2->p_memsz & (ph2->p_align - 1));
        }
        എങ്കിൽ (s->sh_type == SHT_NOTE) {
            update_phdr(&d->phdr[d->notes], PT_NOTE, s, addr, file_offset);
        }
    }

    /* Fill other headers */
    എങ്കിൽ (d->dyna)
        fill_phdr(&d->phdr[d->dyna], PT_DYNAMIC, d->dynamic);
    എങ്കിൽ (d->ehfr)
        fill_phdr(&d->phdr[d->ehfr], PT_GNU_EH_FRAME, eh_frame_hdr_section);
    എങ്കിൽ (d->interp)
        fill_phdr(&d->phdr[1], PT_INTERP, d->interp);
    എങ്കിൽ (phfill) {
        ph = &d->phdr[0];
        ph->p_offset = വലുപ്പം(ElfW(Ehdr));
        ph->p_vaddr = base + ph->p_offset;
        ph->p_filesz = phnum * വലുപ്പം(ElfW(Phdr));
        ph->p_align = 4;
        fill_phdr(ph, PT_PHDR, ശൂന്യ);
    }
    തിരികെ 0;
}

/* put dynamic tag */
സ്ഥിതം ശൂന്യം put_dt(Section *dynamic, പൂർണ്ണസംഖ്യ dt, addr_t val)
{
    ElfW(Dyn) *dyn;
    dyn = section_ptr_add(dynamic, വലുപ്പം(ElfW(Dyn)));
    dyn->d_tag = dt;
    dyn->d_un.d_val = val;
}

/* Fill the dynamic section with tags describing the address and size of
   sections */
സ്ഥിതം ശൂന്യം fill_dynamic(TCCState *s1, ഘടന dyn_inf *dyninf)
{
    Section *dynamic = dyninf->dynamic;
    Section *s;

    /* put dynamic section entries */
    put_dt(dynamic, DT_HASH, s1->dynsym->hash->sh_addr);
    put_dt(dynamic, DT_GNU_HASH, dyninf->gnu_hash->sh_addr);
    put_dt(dynamic, DT_STRTAB, dyninf->dynstr->sh_addr);
    put_dt(dynamic, DT_SYMTAB, s1->dynsym->sh_addr);
    put_dt(dynamic, DT_STRSZ, dyninf->dynstr->data_offset);
    put_dt(dynamic, DT_SYMENT, വലുപ്പം(ElfW(Sym)));
#എങ്കിൽ PTR_SIZE == 8
    put_dt(dynamic, DT_RELA, dyninf->rel_addr);
    put_dt(dynamic, DT_RELASZ, dyninf->rel_size);
    put_dt(dynamic, DT_RELAENT, വലുപ്പം(ElfW_Rel));
    എങ്കിൽ (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->data_offset);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_RELA);
    }
    put_dt(dynamic, DT_RELACOUNT, 0);
#അല്ലെങ്കിൽ
    put_dt(dynamic, DT_REL, dyninf->rel_addr);
    put_dt(dynamic, DT_RELSZ, dyninf->rel_size);
    put_dt(dynamic, DT_RELENT, വലുപ്പം(ElfW_Rel));
    എങ്കിൽ (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->data_offset);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_REL);
    }
    put_dt(dynamic, DT_RELCOUNT, 0);
#endif
    എങ്കിൽ (versym_section && verneed_section) {
	/* The dynamic linker can not handle VERSYM without VERNEED */
        put_dt(dynamic, DT_VERSYM, versym_section->sh_addr);
        put_dt(dynamic, DT_VERNEED, verneed_section->sh_addr);
        put_dt(dynamic, DT_VERNEEDNUM, dt_verneednum);
    }
    s = have_section(s1, ".preinit_array");
    എങ്കിൽ (s && s->data_offset) {
        put_dt(dynamic, DT_PREINIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_PREINIT_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".init_array");
    എങ്കിൽ (s && s->data_offset) {
        put_dt(dynamic, DT_INIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_INIT_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".fini_array");
    എങ്കിൽ (s && s->data_offset) {
        put_dt(dynamic, DT_FINI_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_FINI_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".init");
    എങ്കിൽ (s && s->data_offset) {
        put_dt(dynamic, DT_INIT, s->sh_addr);
    }
    s = have_section(s1, ".fini");
    എങ്കിൽ (s && s->data_offset) {
        put_dt(dynamic, DT_FINI, s->sh_addr);
    }
    എങ്കിൽ (s1->do_debug)
        put_dt(dynamic, DT_DEBUG, 0);
    put_dt(dynamic, DT_NULL, 0);
}

/* Remove gaps between RELX sections.
   These gaps are a result of final_sections_reloc. Here some relocs are removed.
   The gaps are then filled with 0 in tcc_output_elf. The 0 is intepreted as
   R_...NONE reloc. This does work on most targets but on OpenBSD/arm64 this
   is illegal. OpenBSD/arm64 does not support R_...NONE reloc. */
സ്ഥിതം ശൂന്യം update_reloc_sections(TCCState *s1, ഘടന dyn_inf *dyninf)
{
    പൂർണ്ണസംഖ്യ i;
    unsigned long file_offset = 0;
    Section *s;
    Section *relocplt = s1->plt ? s1->plt->reloc : ശൂന്യ;

    /* dynamic relocation table information, for .dynamic section */
    dyninf->rel_addr = dyninf->rel_size = 0;

    വേണ്ടി(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
	എങ്കിൽ (s->sh_type == SHT_RELX && s != relocplt) {
	    എങ്കിൽ (dyninf->rel_size == 0) {
		dyninf->rel_addr = s->sh_addr;
		file_offset = s->sh_offset;
	    }
	    അല്ലെങ്കിൽ {
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
സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_output_elf(TCCState *s1, FILE *f, പൂർണ്ണസംഖ്യ phnum, ElfW(Phdr) *phdr)
{
    പൂർണ്ണസംഖ്യ i, shnum, offset, size, file_type;
    Section *s;
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) shdr, *sh;

    file_type = s1->output_type;
    shnum = s1->nb_sections;

    memset(&ehdr, 0, വലുപ്പം(ehdr));
    എങ്കിൽ (phnum > 0) {
        ehdr.e_phentsize = വലുപ്പം(ElfW(Phdr));
        ehdr.e_phnum = phnum;
        ehdr.e_phoff = വലുപ്പം(ElfW(Ehdr));
    }

    /* fill header */
    ehdr.e_ident[0] = ELFMAG0;
    ehdr.e_ident[1] = ELFMAG1;
    ehdr.e_ident[2] = ELFMAG2;
    ehdr.e_ident[3] = ELFMAG3;
    ehdr.e_ident[4] = ELFCLASSW;
    ehdr.e_ident[5] = ELFDATA2LSB;
    ehdr.e_ident[6] = EV_CURRENT;

#എങ്കിൽ TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    ehdr.e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
#അല്ലെങ്കിലെങ്കിൽ TARGETOS_OpenBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_OPENBSD;
#അല്ലെങ്കിലെങ്കിൽ TARGETOS_NetBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_NETBSD;
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM && defined TCC_ARM_EABI
    ehdr.e_flags = EF_ARM_EABI_VER5;
    ehdr.e_flags |= s1->float_abi == ARM_HARD_FLOAT
        ? EF_ARM_VFP_FLOAT : EF_ARM_SOFT_FLOAT;
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_RISCV64
    /* XXX should be configurable */
    ehdr.e_flags = EF_RISCV_FLOAT_ABI_DOUBLE;
#endif

    എങ്കിൽ (file_type == TCC_OUTPUT_OBJ) {
        ehdr.e_type = ET_REL;
    } അല്ലെങ്കിൽ {
        എങ്കിൽ (file_type & TCC_OUTPUT_DYN)
            ehdr.e_type = ET_DYN;
        അല്ലെങ്കിൽ
            ehdr.e_type = ET_EXEC;
        എങ്കിൽ (s1->elf_entryname)
            ehdr.e_entry = get_sym_addr(s1, s1->elf_entryname, 1, 0);
        അല്ലെങ്കിൽ
            ehdr.e_entry = get_sym_addr(s1, "_start", !!(file_type & TCC_OUTPUT_EXE), 0);
        എങ്കിൽ (ehdr.e_entry == (addr_t)-1)
            ehdr.e_entry = text_section->sh_addr;
        എങ്കിൽ (s1->nb_errors)
            തിരികെ -1;
    }

    sort_syms(s1, s1->symtab);

    ehdr.e_machine = EM_TCC_TARGET;
    ehdr.e_version = EV_CURRENT;
    ehdr.e_shoff = (വലുപ്പം(ElfW(Ehdr)) + phnum * വലുപ്പം(ElfW(Phdr)) + 3) & -4;
    ehdr.e_ehsize = വലുപ്പം(ElfW(Ehdr));
    ehdr.e_shentsize = വലുപ്പം(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    offset = fwrite(&ehdr, 1, വലുപ്പം(ElfW(Ehdr)), f);
    എങ്കിൽ (phdr)
        offset += fwrite(phdr, 1, phnum * വലുപ്പം(ElfW(Phdr)), f);

    /* output section headers */
    ആകുമ്പോൾ (offset < ehdr.e_shoff) {
        fputc(0, f);
        offset++;
    }

    വേണ്ടി(i = 0; i < shnum; i++) {
        sh = &shdr;
        memset(sh, 0, വലുപ്പം(ElfW(Shdr)));
        എങ്കിൽ (i) {
            s = s1->sections[i];
            sh->sh_name = s->sh_name;
            sh->sh_type = s->sh_type;
            sh->sh_flags = s->sh_flags;
            sh->sh_entsize = s->sh_entsize;
            sh->sh_info = s->sh_info;
            എങ്കിൽ (s->link)
                sh->sh_link = s->link->sh_അക്കം;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_offset = s->sh_offset;
            sh->sh_size = s->sh_size;
        }
        offset += fwrite(sh, 1, വലുപ്പം(ElfW(Shdr)), f);
    }

    /* output sections */
    വേണ്ടി(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        എങ്കിൽ (s->sh_type != SHT_NOBITS) {
            ആകുമ്പോൾ (offset < s->sh_offset) {
                fputc(0, f);
                offset++;
            }
            size = s->sh_size;
            എങ്കിൽ (size)
                offset += fwrite(s->data, 1, size, f);
        }
    }
    തിരികെ 0;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_output_ദ്വിമാന(TCCState *s1, FILE *f)
{
    Section *s;
    പൂർണ്ണസംഖ്യ i, offset, size;

    offset = 0;
    വേണ്ടി(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[i];
        എങ്കിൽ (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            ആകുമ്പോൾ (offset < s->sh_offset) {
                fputc(0, f);
                offset++;
            }
            size = s->sh_size;
            fwrite(s->data, 1, size, f);
            offset += size;
        }
    }
    തിരികെ 0;
}

/* Write an elf, coff or "binary" file */
സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_write_elf_file(TCCState *s1, സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ phnum,
                              ElfW(Phdr) *phdr)
{
    പൂർണ്ണസംഖ്യ fd, mode, file_type, ret;
    FILE *f;

    file_type = s1->output_type;
    എങ്കിൽ (file_type == TCC_OUTPUT_OBJ)
        mode = 0666;
    അല്ലെങ്കിൽ
        mode = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_ദ്വിമാന_2, mode);
    എങ്കിൽ (fd < 0 || (f = fdopen(fd, "wb")) == ശൂന്യ)
        തിരികെ tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
    എങ്കിൽ (s1->verbose)
        printf("<- %s\n", filename);
#ifdef TCC_TARGET_COFF
    എങ്കിൽ (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    അല്ലെങ്കിൽ
#endif
    എങ്കിൽ (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        ret = tcc_output_elf(s1, f, phnum, phdr);
    അല്ലെങ്കിൽ
        ret = tcc_output_ദ്വിമാന(s1, f);
    fclose(f);

    തിരികെ ret;
}

#ifndef ELF_OBJ_ONLY
/* order sections according to sec_order, remove sections
   that we aren't going to output.  */
സ്ഥിതം ശൂന്യം reorder_sections(TCCState *s1, പൂർണ്ണസംഖ്യ *sec_order)
{
    പൂർണ്ണസംഖ്യ i, nnew, k, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    backmap = tcc_malloc(s1->nb_sections * വലുപ്പം(backmap[0]));
    വേണ്ടി (i = 0, nnew = 0, snew = ശൂന്യ; i < s1->nb_sections; i++) {
	k = sec_order ? sec_order[i] : i;
	s = s1->sections[k];
	എങ്കിൽ (!i || s->sh_name) {
	    backmap[k] = nnew;
            dynarray_add(&snew, &nnew, s);
	} അല്ലെങ്കിൽ {
	    backmap[k] = 0;
            /* just remember to free them later */
	    dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, s);
	}
    }
    വേണ്ടി (i = 1; i < nnew; i++) {
	s = snew[i];
        s->sh_അക്കം = i;
        എങ്കിൽ (s->sh_type == SHT_RELX)
            s->sh_info = backmap[s->sh_info];
        അല്ലെങ്കിൽ എങ്കിൽ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM)
            for_each_elem(s, 1, sym, ElfW(Sym))
                എങ്കിൽ (sym->st_shndx < s1->nb_sections)
                    sym->st_shndx = backmap[sym->st_shndx];
    }
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}

#ifdef TCC_TARGET_ARM
സ്ഥിതം ശൂന്യം create_arm_attribute_section(TCCState *s1)
{
   // Needed for DLL support.
    സ്ഥിതം സ്ഥിരം unsigned അക്ഷരം arm_attr[] = {
        0x41,                            // 'A'
        0x2c, 0x00, 0x00, 0x00,          // size 0x2c
        'a', 'e', 'a', 'b', 'i', 0x00,   // "aeabi"
        0x01, 0x22, 0x00, 0x00, 0x00,    // 'File Attributes', size 0x22
        0x05, 0x36, 0x00,                // 'CPU_name', "6"
#എങ്കിൽ CONFIG_TCC_CPUVER >= 7
        0x06, 0x0a,                      // 'CPU_arch', 'v7'
#അല്ലെങ്കിൽ
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
    unsigned അക്ഷരം *ptr = section_ptr_add(attr, വലുപ്പം(arm_attr));
    attr->sh_addralign = 1;
    memcpy(ptr, arm_attr, വലുപ്പം(arm_attr));
    എങ്കിൽ (s1->float_abi != ARM_HARD_FLOAT) {
        ptr[26] = 0x00; // 'FP_arch', 'No'
        ptr[41] = 0x1e; // 'ABI_optimization_goals'
        ptr[42] = 0x06; // 'Aggressive Debug'
    }
}
#endif

#ifdef TCC_TARGET_RISCV64
സ്ഥിതം ശൂന്യം create_riscv_attribute_section(TCCState *s1)
{
    സ്ഥിതം സ്ഥിരം unsigned അക്ഷരം riscv_attr[] = {
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
    unsigned അക്ഷരം *ptr = section_ptr_add(attr, വലുപ്പം(riscv_attr));
    attr->sh_addralign = 1;
    memcpy(ptr, riscv_attr, വലുപ്പം(riscv_attr));
}
#endif

#എങ്കിൽ TARGETOS_OpenBSD || TARGETOS_NetBSD || TARGETOS_FreeBSD

സ്ഥിതം ശൂന്യം fill_bsd_note(Section *s, പൂർണ്ണസംഖ്യ type,
			  സ്ഥിരം അക്ഷരം *മൂല്യം, uint32_t data)
{
    unsigned long offset = 0;
    അക്ഷരം *ptr;
    ElfW(Nhdr) *note;
    പൂർണ്ണസംഖ്യ align = s->sh_addralign;

    /* check if type present */
    ആകുമ്പോൾ (offset + വലുപ്പം(ElfW(Nhdr)) < s->data_offset) {
        note = (ElfW(Nhdr) *) (s->data + offset);
	എങ്കിൽ (note->n_type == type)
	    തിരികെ;
	offset += (വലുപ്പം(ElfW(Nhdr)) + note->n_namesz + note->n_descsz +
		  align - 1) & -align;
    }
    ptr = section_ptr_add(s, വലുപ്പം(ElfW(Nhdr)) + 8 + 4);
    note = (ElfW(Nhdr) *) ptr;
    note->n_namesz = 8;
    note->n_descsz = 4;
    note->n_type = type;
    strcpy (ptr + വലുപ്പം(ElfW(Nhdr)), മൂല്യം);
    memcpy (ptr + വലുപ്പം(ElfW(Nhdr)) + 8, &data, 4);
}

സ്ഥിതം Section *create_bsd_note_section(TCCState *s1,
					സ്ഥിരം അക്ഷരം *name,
					സ്ഥിരം അക്ഷരം *മൂല്യം)
{
    Section *s;
    unsigned പൂർണ്ണസംഖ്യ major = 0, minor = 0, patch = 0;

#ifdef CONFIG_OS_RELEASE
    sscanf(CONFIG_OS_RELEASE, "%u.%u.%u", &major, &minor, &patch);
#endif
#എങ്കിൽ TARGETOS_FreeBSD
    എങ്കിൽ (major < 14)
	തിരികെ ശൂന്യ;
#endif
    s = find_section (s1, name);
    s->sh_type = SHT_NOTE;
#എങ്കിൽ TARGETOS_OpenBSD
    fill_bsd_note(s, ELF_NOTE_OS_GNU, മൂല്യം, 0);
#അല്ലെങ്കിലെങ്കിൽ TARGETOS_NetBSD
    fill_bsd_note(s, 1 /* NT_NETBSD_IDENT_TAG */, മൂല്യം,
		  major * 100000000u + (minor % 100u) * 1000000u +
		  (patch % 10000u) * 100u);
#അല്ലെങ്കിലെങ്കിൽ TARGETOS_FreeBSD
    fill_bsd_note(s, 1 /* NT_FREEBSD_ABI_TAG */, മൂല്യം,
		  major * 100000u + (minor % 100u) * 1000u);
    fill_bsd_note(s, 4 /* NT_FREEBSD_FEATURE_CTL */, മൂല്യം, 0);
    fill_bsd_note(s, 2 /* NT_FREEBSD_NOINIT_TAG */, മൂല്യം, 0);
#endif
    തിരികെ s;
}
#endif

സ്ഥിതം ശൂന്യം alloc_sec_names(TCCState *s1, പൂർണ്ണസംഖ്യ is_obj);

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
സ്ഥിതം പൂർണ്ണസംഖ്യ elf_output_file(TCCState *s1, സ്ഥിരം അക്ഷരം *filename)
{
    പൂർണ്ണസംഖ്യ i, ret, file_type, *sec_order;
    ഘടന dyn_inf dyninf = {0};
    Section *interp, *dynstr, *dynamic;
    പൂർണ്ണസംഖ്യ textrel, got_sym, dt_flags_1;

    file_type = s1->output_type;
    ret = -1;
    interp = dynstr = dynamic = ശൂന്യ;
    sec_order = ശൂന്യ;

#ifdef TCC_TARGET_ARM
    create_arm_attribute_section (s1);
#endif

#ifdef TCC_TARGET_RISCV64
    create_riscv_attribute_section(s1);
#endif

#എങ്കിൽ TARGETOS_OpenBSD
    dyninf.note = create_bsd_note_section (s1, ".note.openbsd.ident", "OpenBSD");
#endif

#എങ്കിൽ TARGETOS_NetBSD
    dyninf.note = create_bsd_note_section (s1, ".note.netbsd.ident", "NetBSD");
#endif

#എങ്കിൽ TARGETOS_FreeBSD
    dyninf.note = create_bsd_note_section (s1, ".note.tag", "FreeBSD");
#endif

        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_add_runtime(s1);
	resolve_common_syms(s1);

        എങ്കിൽ (!s1->static_link) {
            എങ്കിൽ (file_type & TCC_OUTPUT_EXE) {
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
            dynamic->sh_entsize = വലുപ്പം(ElfW(Dyn));

            got_sym = build_got(s1);
            എങ്കിൽ (file_type & TCC_OUTPUT_EXE) {
                bind_exe_dynsyms(s1, file_type & TCC_OUTPUT_DYN);
                എങ്കിൽ (s1->nb_errors)
                    പോകുക the_end;
            }
            build_got_entries(s1, got_sym);
            എങ്കിൽ (file_type & TCC_OUTPUT_EXE) {
                bind_libs_dynsyms(s1);
            } അല്ലെങ്കിൽ {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
#എങ്കിൽ TCC_EH_FRAME
	    /* fill with initial data */
	    tcc_eh_frame_hdr(s1, 0);
#endif
	    dyninf.gnu_hash = create_gnu_hash(s1);
        } അല്ലെങ്കിൽ {
            build_got_entries(s1, 0);
        }
	version_add (s1);

    textrel = set_sec_sizes(s1);

    എങ്കിൽ (!s1->static_link) {
        /* add a list of needed dlls */
        വേണ്ടി(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            എങ്കിൽ (dllref->level == 0)
                put_dt(dynamic, DT_NEEDED, put_elf_str(dynstr, dllref->name));
        }

        എങ്കിൽ (s1->rpath)
            put_dt(dynamic, s1->enable_new_dtags ? DT_RUNPATH : DT_RPATH,
                   put_elf_str(dynstr, s1->rpath));

        dt_flags_1 = DF_1_NOW;
        എങ്കിൽ (file_type & TCC_OUTPUT_DYN) {
            എങ്കിൽ (s1->soname)
                put_dt(dynamic, DT_SONAME, put_elf_str(dynstr, s1->soname));
            /* XXX: currently, since we do not handle PIC code, we
               must relocate the readonly segments */
            എങ്കിൽ (textrel)
                put_dt(dynamic, DT_TEXTREL, 0);
            എങ്കിൽ (file_type & TCC_OUTPUT_EXE)
                dt_flags_1 = DF_1_NOW | DF_1_PIE;
	    എങ്കിൽ (s1->znodelete)
		dt_flags_1 |= DF_1_NODELETE;
        }
        put_dt(dynamic, DT_FLAGS, DF_BIND_NOW);
        put_dt(dynamic, DT_FLAGS_1, dt_flags_1);
        എങ്കിൽ (s1->symbolic)
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
    sec_order = tcc_malloc(വലുപ്പം(പൂർണ്ണസംഖ്യ) * 2 * s1->nb_sections);
    /* compute section to program header mapping */
    layout_sections(s1, sec_order, &dyninf);

        എങ്കിൽ (dynamic) {
            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->data, dynamic->sh_addr);
            എങ്കിൽ (file_type == TCC_OUTPUT_EXE
                || (RELOCATE_DLLPLT && (file_type & TCC_OUTPUT_DYN)))
                relocate_plt(s1);
            /* relocate symbols in .dynsym now that final addresses are known */
            relocate_syms(s1, s1->dynsym, 2);
        }

        /* if building executable or DLL, then relocate each section
           except the GOT which is already relocated */
        relocate_syms(s1, s1->symtab, 0);
        എങ്കിൽ (s1->nb_errors != 0)
            പോകുക the_end;
        relocate_sections(s1);
        എങ്കിൽ (dynamic) {
	    update_reloc_sections (s1, &dyninf);
            dynamic->data_offset = dyninf.data_offset;
            fill_dynamic(s1, &dyninf);
	}
        /* Perform relocation to GOT or PLT entries */
        എങ്കിൽ (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        അല്ലെങ്കിൽ എങ്കിൽ (s1->got)
            fill_local_got_entries(s1);

    എങ്കിൽ (dyninf.gnu_hash)
        update_gnu_hash(s1, dyninf.gnu_hash);

    reorder_sections(s1, sec_order);
#എങ്കിൽ TCC_EH_FRAME
    /* fill with final data */
    tcc_eh_frame_hdr(s1, 1);
#endif
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, dyninf.phnum, dyninf.phdr);
 the_end:
    tcc_free(sec_order);
    tcc_free(dyninf.phdr);
    തിരികെ ret;
}
#endif /* ndef ELF_OBJ_ONLY */

/* Allocate strings for section names */
സ്ഥിതം ശൂന്യം alloc_sec_names(TCCState *s1, പൂർണ്ണസംഖ്യ is_obj)
{
    പൂർണ്ണസംഖ്യ i;
    Section *s, *strsec;

    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");
    വേണ്ടി(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        എങ്കിൽ (is_obj)
            s->sh_size = s->data_offset;
	എങ്കിൽ (s->sh_size || s == strsec || (s->sh_flags & SHF_ALLOC) || is_obj)
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_size = strsec->data_offset;
}

/* Output an elf .o file */
സ്ഥിതം പൂർണ്ണസംഖ്യ elf_output_obj(TCCState *s1, സ്ഥിരം അക്ഷരം *filename)
{
    Section *s;
    പൂർണ്ണസംഖ്യ i, ret, file_offset;
    /* Allocate strings for section names */
    alloc_sec_names(s1, 1);
    file_offset = (വലുപ്പം (ElfW(Ehdr)) + 3) & -4;
    file_offset += s1->nb_sections * വലുപ്പം(ElfW(Shdr));
    വേണ്ടി(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        file_offset = (file_offset + 15) & -16;
        s->sh_offset = file_offset;
        എങ്കിൽ (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_size;
    }
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, 0, ശൂന്യ);
    തിരികെ ret;
}

LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_output_file(TCCState *s, സ്ഥിരം അക്ഷരം *filename)
{
    s->nb_errors = 0;
    എങ്കിൽ (s->test_coverage)
        tcc_tcov_add_file(s, filename);
    എങ്കിൽ (s->output_type == TCC_OUTPUT_OBJ)
        തിരികെ elf_output_obj(s, filename);
#ifdef TCC_TARGET_PE
    തിരികെ  pe_output_file(s, filename);
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_MACHO
    തിരികെ macho_output_file(s, filename);
#അല്ലെങ്കിൽ
    തിരികെ elf_output_file(s, filename);
#endif
}

ST_FUNC ssize_t full_read(പൂർണ്ണസംഖ്യ fd, ശൂന്യം *buf, size_t എണ്ണം_2) {
    അക്ഷരം *cbuf = buf;
    size_t rnum = 0;
    ആകുമ്പോൾ (1) {
        ssize_t അക്കം = പഠ(fd, cbuf, എണ്ണം_2-rnum);
        എങ്കിൽ (അക്കം < 0) തിരികെ അക്കം;
        എങ്കിൽ (അക്കം == 0) തിരികെ rnum;
        rnum += അക്കം;
        cbuf += അക്കം;
    }
}

ST_FUNC ശൂന്യം *load_data(പൂർണ്ണസംഖ്യ fd, unsigned long file_offset, unsigned long size)
{
    ശൂന്യം *data;

    data = tcc_malloc(size);
    lseek(fd, file_offset, SEEK_SET);
    full_read(fd, data, size);
    തിരികെ data;
}

തരനിർവചനം ഘടന SectionMergeInfo {
    Section *s;            /* corresponding existing section */
    unsigned long offset;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} SectionMergeInfo;

ST_FUNC പൂർണ്ണസംഖ്യ tcc_object_type(പൂർണ്ണസംഖ്യ fd, ElfW(Ehdr) *h)
{
    പൂർണ്ണസംഖ്യ size = full_read(fd, h, വലുപ്പം *h);
    എങ്കിൽ (size == വലുപ്പം *h && 0 == memcmp(h, ELFMAG, 4)) {
        എങ്കിൽ (h->e_type == ET_REL)
            തിരികെ AFF_BINTYPE_REL;
        എങ്കിൽ (h->e_type == ET_DYN)
            തിരികെ AFF_BINTYPE_DYN;
    } അല്ലെങ്കിൽ എങ്കിൽ (size >= 8) {
        എങ്കിൽ (0 == memcmp(h, ARMAG, 8))
            തിരികെ AFF_BINTYPE_AR;
#ifdef TCC_TARGET_COFF
        എങ്കിൽ (((ഘടന filehdr*)h)->f_magic == COFF_C67_MAGIC)
            തിരികെ AFF_BINTYPE_C67;
#endif
    }
    തിരികെ 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC പൂർണ്ണസംഖ്യ tcc_load_object_file(TCCState *s1,
                                പൂർണ്ണസംഖ്യ fd, unsigned long file_offset)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    unsigned long size, offset, offseti;
    പൂർണ്ണസംഖ്യ i, j, nb_syms, sym_index, ret, seencompressed;
    അക്ഷരം *strsec, *strtab;
    പൂർണ്ണസംഖ്യ stab_index, stabstr_index;
    പൂർണ്ണസംഖ്യ *old_to_new_syms;
    അക്ഷരം *sh_name, *name;
    SectionMergeInfo *sm_table, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    lseek(fd, file_offset, SEEK_SET);
    എങ്കിൽ (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        പോകുക invalid;
    /* test CPU specific stuff */
    എങ്കിൽ (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
invalid:
        തിരികെ tcc_error_noabort("invalid object file");
    }
    /* read sections */
    shdr = load_data(fd, file_offset + ehdr.e_shoff,
                     വലുപ്പം(ElfW(Shdr)) * ehdr.e_shnum);
    sm_table = tcc_mallocz(വലുപ്പം(SectionMergeInfo) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);

    /* load symtab and strtab */
    old_to_new_syms = ശൂന്യ;
    symtab = ശൂന്യ;
    strtab = ശൂന്യ;
    nb_syms = 0;
    seencompressed = 0;
    stab_index = stabstr_index = 0;
    ret = -1;

    വേണ്ടി(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        എങ്കിൽ (sh->sh_type == SHT_SYMTAB) {
            എങ്കിൽ (symtab) {
                tcc_error_noabort("object must contain only one symtab");
                പോകുക the_end;
            }
            nb_syms = sh->sh_size / വലുപ്പം(ElfW(Sym));
            symtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
            sm_table[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
        }
	എങ്കിൽ (sh->sh_flags & SHF_COMPRESSED)
	    seencompressed = 1;
    }

    /* now examine each section and try to merge its content with the
       ones in memory */
    വേണ്ടി(i = 1; i < ehdr.e_shnum; i++) {
        /* no need to examine section name strtab */
        എങ്കിൽ (i == ehdr.e_shstrndx)
            തുടരുക;
        sh = &shdr[i];
	എങ്കിൽ (sh->sh_type == SHT_RELX)
	  sh = &shdr[sh->sh_info];
        /* ignore sections types we do not handle (plus relocs to those) */
        sh_name = strsec + sh->sh_name;
        എങ്കിൽ (0 == strncmp(sh_name, ".debug_", 7)
         || 0 == strncmp(sh_name, ".stab", 5)) {
	    എങ്കിൽ (!s1->do_debug || seencompressed)
	        തുടരുക;
#എങ്കിൽ !(TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD)
        } അല്ലെങ്കിൽ എങ്കിൽ (0 == strncmp(sh_name, ".eh_frame", 9)) {
            എങ്കിൽ (ശൂന്യ == eh_frame_section)
                തുടരുക;
#endif
        } അല്ലെങ്കിൽ
        എങ്കിൽ (sh->sh_type != SHT_PROGBITS &&
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

#എങ്കിൽ TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD
            && sh->sh_type != SHT_X86_64_UNWIND
#endif
            )
            തുടരുക;

	sh = &shdr[i];
        sh_name = strsec + sh->sh_name;
        എങ്കിൽ (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        /* find corresponding section, if any */
        വേണ്ടി(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            എങ്കിൽ (strcmp(s->name, sh_name))
                തുടരുക;
            എങ്കിൽ (sh->sh_type != s->sh_type
                && strcmp (s->name, ".eh_frame")
                /* some crt1.o seem to have two ".note.GNU-stack" (SHT_NOTE & SHT_PROGBITS) */
                && strcmp (s->name, ".note.GNU-stack")
                ) {
                tcc_error_noabort("section type conflict: %s %02x <> %02x", s->name, sh->sh_type, s->sh_type);
                പോകുക the_end;
            }
            എങ്കിൽ (!strncmp(sh_name, ".gnu.linkonce", 13)) {
                /* if a 'linkonce' section is already present, we
                   do not add it again. It is a little tricky as
                   symbols can still be defined in
                   it. */
                sm_table[i].link_once = 1;
                പോകുക next;
            }
            എങ്കിൽ (stab_section) {
                എങ്കിൽ (s == stab_section)
                    stab_index = i;
                എങ്കിൽ (s == stab_section->link)
                    stabstr_index = i;
            }
            പോകുക found;
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
        എങ്കിൽ (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        sm_table[i].offset = offset;
        sm_table[i].s = s;
        /* concatenate sections */
        എങ്കിൽ (sh->sh_type != SHT_NOBITS && size) {
            unsigned അക്ഷരം *ptr;
            lseek(fd, file_offset + sh->sh_offset, SEEK_SET);
            ptr = s->data + offset;
            full_read(fd, ptr, size);
        }
#എങ്കിൽ defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
        /* align code sections to instruction lenght */
        /* This is needed if we compile a c file after this */
        എങ്കിൽ (s->sh_flags & SHF_EXECINSTR)
            section_add(s, 0, 4);
#endif
    next: ;
    }

    /* gr relocate stab strings */
    എങ്കിൽ (stab_index && stabstr_index) {
        Stab_Sym *a, *b;
        unsigned o;
        s = sm_table[stab_index].s;
        a = (Stab_Sym *)(s->data + sm_table[stab_index].offset);
        b = (Stab_Sym *)(s->data + s->data_offset);
        o = sm_table[stabstr_index].offset;
        ആകുമ്പോൾ (a < b) {
            എങ്കിൽ (a->n_strx)
                a->n_strx += o;
            a++;
        }
    }

    /* second short pass to update sh_link and sh_info fields of new
       sections */
    വേണ്ടി(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        എങ്കിൽ (!s || !sm_table[i].new_section)
            തുടരുക;
        sh = &shdr[i];
        എങ്കിൽ (sh->sh_link > 0)
            s->link = sm_table[sh->sh_link].s;
        എങ്കിൽ (sh->sh_type == SHT_RELX) {
            s->sh_info = sm_table[sh->sh_info].s->sh_അക്കം;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }

    എങ്കിൽ (!symtab)
        പോകുക done;

    /* resolve symbols */
    old_to_new_syms = tcc_mallocz(nb_syms * വലുപ്പം(പൂർണ്ണസംഖ്യ));

    sym = symtab + 1;
    വേണ്ടി(i = 1; i < nb_syms; i++, sym++) {
        എങ്കിൽ (sym->st_shndx != SHN_UNDEF &&
            sym->st_shndx < SHN_LORESERVE) {
            sm = &sm_table[sym->st_shndx];
            എങ്കിൽ (sm->link_once) {
                /* if a symbol is in a link once section, we use the
                   already defined symbol. It is very important to get
                   correct relocations */
                എങ്കിൽ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
                    name = strtab + sym->st_name;
                    sym_index = find_elf_sym(symtab_section, name);
                    എങ്കിൽ (sym_index)
                        old_to_new_syms[i] = sym_index;
                }
                തുടരുക;
            }
            /* if no corresponding section added, no need to add symbol */
            എങ്കിൽ (!sm->s)
                തുടരുക;
            /* convert section number */
            sym->st_shndx = sm->s->sh_അക്കം;
            /* offset value */
            sym->st_മൂല്യം += sm->offset;
        }
        /* add symbol */
        name = strtab + sym->st_name;
        sym_index = set_elf_sym(symtab_section, sym->st_മൂല്യം, sym->st_size,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_to_new_syms[i] = sym_index;
    }

    /* third pass to patch relocation entries */
    വേണ്ടി(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        എങ്കിൽ (!s)
            തുടരുക;
        sh = &shdr[i];
        offset = sm_table[i].offset;
        size = sh->sh_size;
        തിരഞ്ഞെടുപ്പ്(s->sh_type) {
        അവസ്ഥ SHT_RELX:
            /* take relocation offset information */
            offseti = sm_table[sh->sh_info].offset;
	    വേണ്ടി (rel = (ElfW_Rel *) s->data + (offset / വലുപ്പം(*rel));
		 rel < (ElfW_Rel *) s->data + ((offset + size) / വലുപ്പം(*rel));
		 rel++) {
                പൂർണ്ണസംഖ്യ type;
                unsigned sym_index;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_index = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                എങ്കിൽ (sym_index >= nb_syms)
                    പോകുക invalid_reloc;
                sym_index = old_to_new_syms[sym_index];
                /* ignore link_once in rel section. */
                എങ്കിൽ (!sym_index && !sm_table[sh->sh_info].link_once
#ifdef TCC_TARGET_ARM
                    && type != R_ARM_V4BX
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_RISCV64
                    && type != R_RISCV_ALIGN
                    && type != R_RISCV_RELAX
#endif
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, (പൂർണ്ണസംഖ്യ)rel->r_offset);
                    പോകുക the_end;
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
                എങ്കിൽ (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_index, 1)->plt_thumb_stub = 1;
#endif
            }
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            നിർത്തുക;
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
    തിരികെ ret;
}

തരനിർവചനം ഘടന ArchiveHeader {
    അക്ഷരം ar_name[16];           /* name of this member */
    അക്ഷരം ar_date[12];           /* file mtime */
    അക്ഷരം ar_uid[6];             /* owner uid; printed as decimal */
    അക്ഷരം ar_gid[6];             /* owner gid; printed as decimal */
    അക്ഷരം ar_mode[8];            /* file mode, printed as octal   */
    അക്ഷരം ar_size[10];           /* file size, printed as decimal */
    അക്ഷരം ar_fmag[2];            /* should contain ARFMAG */
} ArchiveHeader;

#define ARFMAG "`\n"

സ്ഥിതം unsigned long long get_be(സ്ഥിരം uint8_t *b, പൂർണ്ണസംഖ്യ n)
{
    unsigned long long ret = 0;
    ആകുമ്പോൾ (n)
        ret = (ret << 8) | *b++, --n;
    തിരികെ ret;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ read_ar_header(പൂർണ്ണസംഖ്യ fd, പൂർണ്ണസംഖ്യ offset, ArchiveHeader *hdr)
{
    അക്ഷരം *p, *e;
    പൂർണ്ണസംഖ്യ len;
    lseek(fd, offset, SEEK_SET);
    len = full_read(fd, hdr, വലുപ്പം(ArchiveHeader));
    എങ്കിൽ (len != വലുപ്പം(ArchiveHeader))
        തിരികെ len ? -1 : 0;
    എങ്കിൽ (memcmp(hdr->ar_fmag, ARFMAG, വലുപ്പം hdr->ar_fmag))
        തിരികെ -1;
    p = hdr->ar_name;
    വേണ്ടി (e = p + വലുപ്പം hdr->ar_name; e > p && e[-1] == ' ';)
        --e;
    *e = '\0';
    hdr->ar_size[വലുപ്പം hdr->ar_size-1] = 0;
    തിരികെ len;
}

/* load only the objects which resolve undefined symbols */
സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_load_alacarte(TCCState *s1, പൂർണ്ണസംഖ്യ fd, പൂർണ്ണസംഖ്യ size, പൂർണ്ണസംഖ്യ entrysize)
{
    പൂർണ്ണസംഖ്യ i, bound, nsyms, sym_index, len, ret = -1;
    unsigned long long off;
    uint8_t *data;
    സ്ഥിരം അക്ഷരം *ar_names, *p;
    സ്ഥിരം uint8_t *ar_index;
    ElfW(Sym) *sym;
    ArchiveHeader hdr;

    data = tcc_malloc(size);
    എങ്കിൽ (full_read(fd, data, size) != size)
        പോകുക invalid;
    nsyms = get_be(data, entrysize);
    ar_index = data + entrysize;
    ar_names = (അക്ഷരം *) ar_index + nsyms * entrysize;

    ചെയ്യുക {
        bound = 0;
        വേണ്ടി (p = ar_names, i = 0; i < nsyms; i++, p += strlen(p)+1) {
            Section *s = symtab_section;
            sym_index = find_elf_sym(s, p);
            എങ്കിൽ (!sym_index)
                തുടരുക;
            sym = &((ElfW(Sym) *)s->data)[sym_index];
            എങ്കിൽ(sym->st_shndx != SHN_UNDEF)
                തുടരുക;
            off = get_be(ar_index + i * entrysize, entrysize);
            len = read_ar_header(fd, off, &hdr);
            എങ്കിൽ (len <= 0 || memcmp(hdr.ar_fmag, ARFMAG, 2)) {
        invalid:
                tcc_error_noabort("invalid archive");
                പോകുക the_end;
            }
            off += len;
            എങ്കിൽ (s1->verbose == 2)
                printf("   -> %s\n", hdr.ar_name);
            എങ്കിൽ (tcc_load_object_file(s1, fd, off) < 0)
                പോകുക the_end;
            ++bound;
        }
    } ആകുമ്പോൾ(bound);
    ret = 0;
 the_end:
    tcc_free(data);
    തിരികെ ret;
}

/* load a '.a' file */
ST_FUNC പൂർണ്ണസംഖ്യ tcc_load_archive(TCCState *s1, പൂർണ്ണസംഖ്യ fd, പൂർണ്ണസംഖ്യ alacarte)
{
    ArchiveHeader hdr;
    /* char magic[8]; */
    പൂർണ്ണസംഖ്യ size, len;
    unsigned long file_offset;
    ElfW(Ehdr) ehdr;

    /* skip magic which was already checked */
    /* full_read(fd, magic, sizeof(magic)); */
    file_offset = വലുപ്പം ARMAG - 1;

    വേണ്ടി(;;) {
        len = read_ar_header(fd, file_offset, &hdr);
        എങ്കിൽ (len == 0)
            തിരികെ 0;
        എങ്കിൽ (len < 0)
            തിരികെ tcc_error_noabort("invalid archive");
        file_offset += len;
        size = strtol(hdr.ar_size, ശൂന്യ, 0);
        എങ്കിൽ (alacarte) {
            /* coff symbol table : we handle it */
            എങ്കിൽ (!strcmp(hdr.ar_name, "/"))
                തിരികെ tcc_load_alacarte(s1, fd, size, 4);
            എങ്കിൽ (!strcmp(hdr.ar_name, "/SYM64/"))
                തിരികെ tcc_load_alacarte(s1, fd, size, 8);
        } അല്ലെങ്കിൽ എങ്കിൽ (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
            എങ്കിൽ (s1->verbose == 2)
                printf("   -> %s\n", hdr.ar_name);
            എങ്കിൽ (tcc_load_object_file(s1, fd, file_offset) < 0)
                തിരികെ -1;
        }
        /* align to even */
        file_offset = (file_offset + size + 1) & ~1;
    }
}

#ifndef ELF_OBJ_ONLY
/* Set LV[I] to the global index of sym-version (LIB,VERSION).  Maybe resizes
   LV, maybe create a new entry for (LIB,VERSION).  */
സ്ഥിതം ശൂന്യം set_ver_to_ver(TCCState *s1, പൂർണ്ണസംഖ്യ *n, പൂർണ്ണസംഖ്യ **lv, പൂർണ്ണസംഖ്യ i, അക്ഷരം *lib, അക്ഷരം *version)
{
    ആകുമ്പോൾ (i >= *n) {
        *lv = tcc_realloc(*lv, (*n + 1) * വലുപ്പം(**lv));
        (*lv)[(*n)++] = -1;
    }
    എങ്കിൽ ((*lv)[i] == -1) {
        പൂർണ്ണസംഖ്യ v, prev_same_lib = -1;
        വേണ്ടി (v = 0; v < nb_sym_versions; v++) {
            എങ്കിൽ (strcmp(sym_versions[v].lib, lib))
              തുടരുക;
            prev_same_lib = v;
            എങ്കിൽ (!strcmp(sym_versions[v].version, version))
              നിർത്തുക;
        }
        എങ്കിൽ (v == nb_sym_versions) {
            sym_versions = tcc_realloc (sym_versions,
                                        (v + 1) * വലുപ്പം(*sym_versions));
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
സ്ഥിതം ശൂന്യം
set_sym_version(TCCState *s1, പൂർണ്ണസംഖ്യ sym_index, പൂർണ്ണസംഖ്യ verndx)
{
    എങ്കിൽ (sym_index >= nb_sym_to_version) {
        പൂർണ്ണസംഖ്യ newelems = sym_index ? sym_index * 2 : 1;
        sym_to_version = tcc_realloc(sym_to_version,
                                     newelems * വലുപ്പം(*sym_to_version));
        memset(sym_to_version + nb_sym_to_version, -1,
               (newelems - nb_sym_to_version) * വലുപ്പം(*sym_to_version));
        nb_sym_to_version = newelems;
    }
    എങ്കിൽ (sym_to_version[sym_index] < 0)
      sym_to_version[sym_index] = verndx;
}

ഘടന versym_info {
    പൂർണ്ണസംഖ്യ nb_versyms;
    ElfW(Verdef) *verdef;
    ElfW(Verneed) *verneed;
    ElfW(Half) *versym;
    പൂർണ്ണസംഖ്യ nb_local_ver, *local_ver;
};


സ്ഥിതം ശൂന്യം store_version(TCCState *s1, ഘടന versym_info *v, അക്ഷരം *dynstr)
{
    അക്ഷരം *lib, *version;
    uint32_t next;
    പൂർണ്ണസംഖ്യ i;

#define	DEBUG_VERSION 0

    എങ്കിൽ (v->versym && v->verdef) {
      ElfW(Verdef) *vdef = v->verdef;
      lib = ശൂന്യ;
      ചെയ്യുക {
        ElfW(Verdaux) *verdaux =
	  (ElfW(Verdaux) *) (((അക്ഷരം *) vdef) + vdef->vd_aux);

#എങ്കിൽ DEBUG_VERSION
	printf ("verdef: version:%u flags:%u index:%u, hash:%u\n",
	        vdef->vd_version, vdef->vd_flags, vdef->vd_ndx,
		vdef->vd_hash);
#endif
	എങ്കിൽ (vdef->vd_cnt) {
          version = dynstr + verdaux->vda_name;

	  എങ്കിൽ (lib == ശൂന്യ)
	    lib = version;
	  അല്ലെങ്കിൽ
            set_ver_to_ver(s1, &v->nb_local_ver, &v->local_ver, vdef->vd_ndx,
                           lib, version);
#എങ്കിൽ DEBUG_VERSION
	  printf ("  verdaux(%u): %s\n", vdef->vd_ndx, version);
#endif
	}
        next = vdef->vd_next;
        vdef = (ElfW(Verdef) *) (((അക്ഷരം *) vdef) + next);
      } ആകുമ്പോൾ (next);
    }
    എങ്കിൽ (v->versym && v->verneed) {
      ElfW(Verneed) *vneed = v->verneed;
      ചെയ്യുക {
        ElfW(Vernaux) *vernaux =
	  (ElfW(Vernaux) *) (((അക്ഷരം *) vneed) + vneed->vn_aux);

        lib = dynstr + vneed->vn_file;
#എങ്കിൽ DEBUG_VERSION
	printf ("verneed: %u %s\n", vneed->vn_version, lib);
#endif
	വേണ്ടി (i = 0; i < vneed->vn_cnt; i++) {
	  എങ്കിൽ ((vernaux->vna_other & 0x8000) == 0) { /* hidden */
              version = dynstr + vernaux->vna_name;
              set_ver_to_ver(s1, &v->nb_local_ver, &v->local_ver, vernaux->vna_other,
                             lib, version);
#എങ്കിൽ DEBUG_VERSION
	    printf ("  vernaux(%u): %u %u %s\n",
		    vernaux->vna_other, vernaux->vna_hash,
		    vernaux->vna_flags, version);
#endif
	  }
	  vernaux = (ElfW(Vernaux) *) (((അക്ഷരം *) vernaux) + vernaux->vna_next);
	}
        next = vneed->vn_next;
        vneed = (ElfW(Verneed) *) (((അക്ഷരം *) vneed) + next);
      } ആകുമ്പോൾ (next);
    }

#എങ്കിൽ DEBUG_VERSION
    വേണ്ടി (i = 0; i < v->nb_local_ver; i++) {
      എങ്കിൽ (v->local_ver[i] > 0) {
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
ST_FUNC പൂർണ്ണസംഖ്യ tcc_load_dll(TCCState *s1, പൂർണ്ണസംഖ്യ fd, സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    പൂർണ്ണസംഖ്യ i, nb_syms, nb_dts, sym_bind, ret = -1;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;

    അക്ഷരം *dynstr;
    പൂർണ്ണസംഖ്യ sym_index;
    സ്ഥിരം അക്ഷരം *name, *soname;
    ഘടന versym_info v;

    full_read(fd, &ehdr, വലുപ്പം(ehdr));

    /* test CPU specific stuff */
    എങ്കിൽ (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
        തിരികെ tcc_error_noabort("bad architecture");
    }

    /* read sections */
    shdr = load_data(fd, ehdr.e_shoff, വലുപ്പം(ElfW(Shdr)) * ehdr.e_shnum);

    /* load dynamic section and dynamic symbols */
    nb_syms = 0;
    nb_dts = 0;
    dynamic = ശൂന്യ;
    dynsym = ശൂന്യ; /* avoid warning */
    dynstr = ശൂന്യ; /* avoid warning */
    memset(&v, 0, വലുപ്പം v);

    വേണ്ടി(i = 0, sh = shdr; i < ehdr.e_shnum; i++, sh++) {
        തിരഞ്ഞെടുപ്പ്(sh->sh_type) {
        അവസ്ഥ SHT_DYNAMIC:
            nb_dts = sh->sh_size / വലുപ്പം(ElfW(Dyn));
            dynamic = load_data(fd, sh->sh_offset, sh->sh_size);
            നിർത്തുക;
        അവസ്ഥ SHT_DYNSYM:
            nb_syms = sh->sh_size / വലുപ്പം(ElfW(Sym));
            dynsym = load_data(fd, sh->sh_offset, sh->sh_size);
            sh1 = &shdr[sh->sh_link];
            dynstr = load_data(fd, sh1->sh_offset, sh1->sh_size);
            നിർത്തുക;
        അവസ്ഥ SHT_GNU_verdef:
	    v.verdef = load_data(fd, sh->sh_offset, sh->sh_size);
	    നിർത്തുക;
        അവസ്ഥ SHT_GNU_verneed:
	    v.verneed = load_data(fd, sh->sh_offset, sh->sh_size);
	    നിർത്തുക;
        അവസ്ഥ SHT_GNU_versym:
            v.nb_versyms = sh->sh_size / വലുപ്പം(ElfW(Half));
	    v.versym = load_data(fd, sh->sh_offset, sh->sh_size);
	    നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            നിർത്തുക;
        }
    }

    എങ്കിൽ (!dynamic)
        പോകുക the_end;

    /* compute the real library name */
    soname = tcc_basename(filename);
    വേണ്ടി(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        എങ്കിൽ (dt->d_tag == DT_SONAME)
            soname = dynstr + dt->d_un.d_val;

    /* if the dll is already loaded, do not load it */
    എങ്കിൽ (tcc_add_dllref(s1, soname, level)->found)
        പോകുക ret_success;

    എങ്കിൽ (v.nb_versyms != nb_syms)
        tcc_free (v.versym), v.versym = ശൂന്യ;
    അല്ലെങ്കിൽ
        store_version(s1, &v, dynstr);

    /* add dynamic symbols in dynsym_section */
    വേണ്ടി(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        എങ്കിൽ (sym_bind == STB_LOCAL)
            തുടരുക;
        name = dynstr + sym->st_name;
        sym_index = set_elf_sym(s1->dynsymtab_section, sym->st_മൂല്യം, sym->st_size,
                                sym->st_info, sym->st_other, sym->st_shndx, name);
        എങ്കിൽ (v.versym) {
            ElfW(Half) vsym = v.versym[i];
            എങ്കിൽ ((vsym & 0x8000) == 0 && vsym > 0 && vsym < v.nb_local_ver)
                set_sym_version(s1, sym_index, v.local_ver[vsym]);
        }
    }

    /* do not load all referenced libraries
       (recursive loading can break linking of libraries) */
    /* following DT_NEEDED is needed for the dynamic loader (libdl.so),
       but it is no longer needed, when linking a library or a program.
       When tcc output mode is OUTPUT_MEM,
       tcc calls dlopen, which handles DT_NEEDED for us */

#എങ്കിൽ 0
    വേണ്ടി(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        എങ്കിൽ (dt->d_tag == DT_RPATH)
            tcc_add_library_path(s1, dynstr + dt->d_un.d_val);

    /* load all referenced DLLs */
    വേണ്ടി(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        തിരഞ്ഞെടുപ്പ്(dt->d_tag) {
        അവസ്ഥ DT_NEEDED:
            name = dynstr + dt->d_un.d_val;
            എങ്കിൽ (tcc_add_dllref(s1, name, -1))
                തുടരുക;
            എങ്കിൽ (tcc_add_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                ret = tcc_error_noabort("referenced dll '%s' not found", name);
                പോകുക the_end;
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
    തിരികെ ret;
}

#define LD_TOK_NAME 256
#define LD_TOK_EOF  (-1)
സ്ഥിതം പൂർണ്ണസംഖ്യ ld_inp(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ c = *s1->ld_p;
    എങ്കിൽ (c == 0)
        തിരികെ CH_EOF;
    ++s1->ld_p;
    തിരികെ c;
}
#define ld_unget(s1, ch) എങ്കിൽ (ch != CH_EOF) --s1->ld_p

/* return next ld script token */
സ്ഥിതം പൂർണ്ണസംഖ്യ ld_next(TCCState *s1, അക്ഷരം *name, പൂർണ്ണസംഖ്യ name_size)
{
    പൂർണ്ണസംഖ്യ c, d, ch;
    അക്ഷരം *q;

 redo:
    ch = ld_inp(s1);
    q = name, *q++ = ch;
    തിരഞ്ഞെടുപ്പ്(ch) {
    അവസ്ഥ ' ':
    അവസ്ഥ '\t':
    അവസ്ഥ '\f':
    അവസ്ഥ '\v':
    അവസ്ഥ '\r':
    അവസ്ഥ '\n':
        പോകുക redo;
    അവസ്ഥ '/':
        ch = ld_inp(s1);
        എങ്കിൽ (ch == '*') { /* comment */
            വേണ്ടി (d = 0;; d = ch) {
                ch = ld_inp(s1);
                എങ്കിൽ (ch == CH_EOF || (ch == '/' && d == '*'))
                    നിർത്തുക;
            }
            പോകുക redo;
        } അല്ലെങ്കിൽ {
            പോകുക parse_name;
        }
        നിർത്തുക;
    അവസ്ഥ '\\':
    /* case 'a' ... 'z': */
    അവസ്ഥ 'a':
       അവസ്ഥ 'b':
       അവസ്ഥ 'c':
       അവസ്ഥ 'd':
       അവസ്ഥ 'e':
       അവസ്ഥ 'f':
       അവസ്ഥ 'g':
       അവസ്ഥ 'h':
       അവസ്ഥ 'i':
       അവസ്ഥ 'j':
       അവസ്ഥ 'k':
       അവസ്ഥ 'l':
       അവസ്ഥ 'm':
       അവസ്ഥ 'n':
       അവസ്ഥ 'o':
       അവസ്ഥ 'p':
       അവസ്ഥ 'q':
       അവസ്ഥ 'r':
       അവസ്ഥ 's':
       അവസ്ഥ 't':
       അവസ്ഥ 'u':
       അവസ്ഥ 'v':
       അവസ്ഥ 'w':
       അവസ്ഥ 'x':
       അവസ്ഥ 'y':
       അവസ്ഥ 'z':
    /* case 'A' ... 'z': */
    അവസ്ഥ 'A':
       അവസ്ഥ 'B':
       അവസ്ഥ 'C':
       അവസ്ഥ 'D':
       അവസ്ഥ 'E':
       അവസ്ഥ 'F':
       അവസ്ഥ 'G':
       അവസ്ഥ 'H':
       അവസ്ഥ 'I':
       അവസ്ഥ 'J':
       അവസ്ഥ 'K':
       അവസ്ഥ 'L':
       അവസ്ഥ 'M':
       അവസ്ഥ 'N':
       അവസ്ഥ 'O':
       അവസ്ഥ 'P':
       അവസ്ഥ 'Q':
       അവസ്ഥ 'R':
       അവസ്ഥ 'S':
       അവസ്ഥ 'T':
       അവസ്ഥ 'U':
       അവസ്ഥ 'V':
       അവസ്ഥ 'W':
       അവസ്ഥ 'X':
       അവസ്ഥ 'Y':
       അവസ്ഥ 'Z':
    അവസ്ഥ '-':
    അവസ്ഥ '_':
    അവസ്ഥ '.':
    അവസ്ഥ '$':
    അവസ്ഥ '~':
        വേണ്ടി(;;) {
            ch = ld_inp(s1);
    parse_name:
            എങ്കിൽ (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') ||
                  strchr("/.-_+=$:\\,~", ch)))
                നിർത്തുക;
            എങ്കിൽ ((q - name) < name_size - 1) {
                *q++ = ch;
            }
        }
        ld_unget(s1, ch);
        c = LD_TOK_NAME;
        നിർത്തുക;
    അവസ്ഥ CH_EOF:
        c = LD_TOK_EOF;
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        c = ch;
        നിർത്തുക;
    }
    *q = '\0';
    തിരികെ c;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ ld_add_file(TCCState *s1, സ്ഥിരം അക്ഷരം filename[])
{
    എങ്കിൽ (filename[0] == '-' && filename[1] == 'l')
        തിരികെ tcc_add_library(s1, filename + 2);
    എങ്കിൽ (CONFIG_SYSROOT[0] != '\0' || !IS_ABSPATH(filename)) {
        /* lookup via library paths */
        പൂർണ്ണസംഖ്യ ret = tcc_add_dll(s1, tcc_basename(filename), 0);
        എങ്കിൽ (ret != FILE_NOT_FOUND)
            തിരികെ ret;
    }
    തിരികെ tcc_add_file_internal(s1, filename, AFF_PRINT_ERROR);
}

/* did static libraries add new undefined symbols? */
സ്ഥിതം പൂർണ്ണസംഖ്യ new_undef_sym(TCCState *s1, പൂർണ്ണസംഖ്യ sym_offset)
{
    ആകുമ്പോൾ (sym_offset < s1->symtab->data_offset) {
        ElfW(Sym) *esym = (ശൂന്യം*)(s1->symtab->data + sym_offset);
        എങ്കിൽ (esym->st_shndx == SHN_UNDEF)
            തിരികെ 1;
        sym_offset += വലുപ്പം (ElfW(Sym));
    }
    തിരികെ 0;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ ld_add_file_list(TCCState *s1, സ്ഥിരം അക്ഷരം *cmd)
{
    അക്ഷരം filename[1024];
    പൂർണ്ണസംഖ്യ t, c, sym_offset, ret = 0;
    unsigned അക്ഷരം *pos = s1->ld_p;

repeat:
    s1->ld_p = pos;
    sym_offset = s1->symtab->data_offset;
    c = cmd[0];

    t = ld_next(s1, filename, വലുപ്പം(filename));
    എങ്കിൽ (t != '(')
        തിരികെ tcc_error_noabort("expected '(' after %s", cmd);
    t = ld_next(s1, filename, വലുപ്പം(filename));
    വേണ്ടി(;;) {
        എങ്കിൽ (t == LD_TOK_EOF) {
            തിരികെ tcc_error_noabort("unexpected end of file");
        } അല്ലെങ്കിൽ എങ്കിൽ (t == ')') {
            നിർത്തുക;
        } അല്ലെങ്കിൽ എങ്കിൽ (t != LD_TOK_NAME) {
            തിരികെ tcc_error_noabort("unexpected token '%c'", t);
        } അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(filename, "AS_NEEDED")) {
            ret |= ld_add_file_list(s1, filename);
        } അല്ലെങ്കിൽ എങ്കിൽ (c == 'I' || c == 'G' || c == 'A') {
            ret |= !!ld_add_file(s1, filename);
        }
        എങ്കിൽ (ret < 0)
            തിരികെ ret;
        t = ld_next(s1, filename, വലുപ്പം(filename));
        എങ്കിൽ (t == ',')
            t = ld_next(s1, filename, വലുപ്പം(filename));
    }
    എങ്കിൽ (c == 'G' && ret == 0 && new_undef_sym(s1, sym_offset))
        പോകുക repeat;
    തിരികെ ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC പൂർണ്ണസംഖ്യ tcc_load_ldscript(TCCState *s1, പൂർണ്ണസംഖ്യ fd)
{
    അക്ഷരം cmd[64];
    പൂർണ്ണസംഖ്യ t, ret = 0, noscript = 1;
    unsigned അക്ഷരം *text_ptr, *saved_ptr;

    saved_ptr = s1->ld_p;
    s1->ld_p = text_ptr = (ശൂന്യം*)tcc_load_text(fd);
    വേണ്ടി(;;) {
        t = ld_next(s1, cmd, വലുപ്പം(cmd));
        എങ്കിൽ (t == LD_TOK_EOF)
            നിർത്തുക;
        എങ്കിൽ (!strcmp(cmd, "INPUT") ||
            !strcmp(cmd, "GROUP")) {
            ret |= ld_add_file_list(s1, cmd);
        } അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(cmd, "OUTPUT_FORMAT") ||
                   !strcmp(cmd, "TARGET")) {
            /* ignore some commands */
            ret |= ld_add_file_list(s1, cmd);
        } അല്ലെങ്കിൽ എങ്കിൽ (noscript) {
            ret = FILE_NOT_RECOGNIZED;
        } അല്ലെങ്കിൽ {
            ret = tcc_error_noabort("unexpected '%s'", cmd);
        }
        എങ്കിൽ (ret < 0)
            നിർത്തുക;
        noscript = 0;
    }
    tcc_free(text_ptr);
    s1->ld_p = saved_ptr;
    തിരികെ ret < 0 ? ret : -ret;
}
#endif /* !ELF_OBJ_ONLY */
