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

#અન્તર્ભાવ "tcc.h"

/* Define this to get some debug output during relocation processing.  */
#undef DEBUG_RELOC

/********************************************************/
/* global variables */

/* elf version information */
સંરચના sym_version {
    અક્ષર *lib;
    અક્ષર *version;
    પૂર્ણાંક out_index;
    પૂર્ણાંક prev_same_lib;
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
સ્થિર અચલ અક્ષર rdata[] = ".rdata";
#નહીંતર
#define shf_RELRO SHF_ALLOC /* eventually made SHF_WRITE in sort_sections() */
સ્થિર અચલ અક્ષર rdata[] = ".data.ro";
#endif

/* ------------------------------------------------------------------------- */

ST_FUNC શૂન્ય tccelf_new(TCCState *s)
{
    TCCState *s1 = s;

    /* no section zero */
    dynarray_add(&s->sections, &s->nb_sections, ખાલી);

    /* create standard sections */
    text_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    data_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    /* create ro data section (make ro after relocation done with GNU_RELRO) */
    rodata_section = new_section(s, rdata, SHT_PROGBITS, shf_RELRO);
    bss_section = new_section(s, ".bss", SHT_NOBITS, SHF_ALLOC | SHF_WRITE);
    common_section = new_section(s, ".common", SHT_NOBITS, SHF_PRIVATE);
    common_section->sh_અંક = SHN_COMMON;

    /* symbols are always generated for linking stage */
    symtab_section = new_symtab(s, ".symtab", SHT_SYMTAB, 0,
                                ".strtab",
                                ".hashtab", SHF_PRIVATE);

    /* private symbol table for dynamic symbols */
    s->dynsymtab_section = new_symtab(s, ".dynsymtab", SHT_SYMTAB, SHF_PRIVATE|SHF_DYNSYM,
                                      ".dynstrtab",
                                      ".dynhashtab", SHF_PRIVATE);
    get_sym_attr(s, 0, 1);

    જો (s->do_debug) {
        /* add debug sections */
        tcc_debug_new(s);
    }

#જો TCC_EH_FRAME
    જો (s->output_format != TCC_OUTPUT_FORMAT_ELF)
        s->unwind_tables = 0;
    tcc_eh_frame_start(s);
#endif

#ifdef CONFIG_TCC_BCHECK
    જો (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        /* (make ro after relocation done with GNU_RELRO) */
        bounds_section = new_section(s, ".bounds", SHT_PROGBITS, shf_RELRO);
        lbounds_section = new_section(s, ".lbounds", SHT_PROGBITS, shf_RELRO);
    }
#endif

#ifdef TCC_TARGET_PE
    /* to make sure that -ltcc1 -Wl,-e,_start will grab the startup code
       from libtcc1.a (unless _start defined) */
    જો (s->elf_entryname)
        set_global_sym(s, s->elf_entryname, ખાલી, 0); /* SHN_UNDEF */
#endif

#ifndef ELF_OBJ_ONLY
    જો (ખાલી == s->elfint && s1->output_type != TCC_OUTPUT_OBJ) {
        અચલ અક્ષર *p = CONFIG_TCC_ELFINTERP;
#જો defined TCC_TARGET_ARM && defined CONFIG_TCC_ELFINTERP_ARMHF
        જો (s->float_abi == ARM_HARD_FLOAT)
            p = CONFIG_TCC_ELFINTERP_ARMHF;
#endif
#જો defined TCC_IS_NATIVE && defined TARGETOS_BSD
        /* see commit 55cb2170cd5ce77a7d76dcaf462fad2707281605 */
        { અચલ અક્ષર *e = getenv("LD_SO"); જો (e) p = e; }
#endif
        s->elfint = tcc_strdup(p);
    }
#endif /* ndef ELF_OBJ_ONLY */
}

ST_FUNC શૂન્ય free_section(Section *s)
{
    જો (!s)
        પાછા;
    tcc_free(s->data);
    s->data = ખાલી;
    s->data_allocated = s->data_offset = 0;
}

ST_FUNC શૂન્ય tccelf_delete(TCCState *s1)
{
    પૂર્ણાંક i;

#ifndef ELF_OBJ_ONLY
    /* free symbol versions */
    માટે (i = 0; i < nb_sym_versions; i++) {
        tcc_free(sym_versions[i].version);
        tcc_free(sym_versions[i].lib);
    }
    tcc_free(sym_versions);
    tcc_free(sym_to_version);
#endif

    /* free all sections */
    માટે(i = 1; i < s1->nb_sections; i++)
        free_section(s1->sections[i]);
    dynarray_reset(&s1->sections, &s1->nb_sections);

    માટે(i = 0; i < s1->nb_priv_sections; i++)
        free_section(s1->priv_sections[i]);
    dynarray_reset(&s1->priv_sections, &s1->nb_priv_sections);

    tcc_free(s1->sym_attrs);
    symtab_section = ખાલી; /* for tccrun.c:rt_printline() */
}

/* save section data state */
ST_FUNC શૂન્ય tccelf_begin_file(TCCState *s1)
{
    Section *s; પૂર્ણાંક i;
    માટે (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        s->sh_offset = s->data_offset;
    }
    /* disable symbol hashing during compilation */
    s = s1->symtab, s->reloc = s->hash, s->hash = ખાલી;
#જો defined TCC_TARGET_X86_64 && defined TCC_TARGET_PE
    s1->uw_sym = 0;
    s1->uw_offs = 0;
#endif
}

સ્થિર શૂન્ય update_relocs(TCCState *s1, Section *s, પૂર્ણાંક *old_to_new_syms, પૂર્ણાંક first_sym);

/* At the end of compilation, convert any UNDEF syms to global, and merge
   with previously existing symbols */
ST_FUNC શૂન્ય tccelf_end_file(TCCState *s1)
{
    Section *s = s1->symtab;
    પૂર્ણાંક first_sym, nb_syms, *tr, i;

    first_sym = s->sh_offset / કદ (ElfSym);
    nb_syms = s->data_offset / કદ (ElfSym) - first_sym;
    s->data_offset = s->sh_offset;
    s->link->data_offset = s->link->sh_offset;
    s->hash = s->reloc, s->reloc = ખાલી;
    tr = tcc_mallocz(nb_syms * કદ *tr);

    માટે (i = 0; i < nb_syms; ++i) {
        ElfSym *sym = (ElfSym*)s->data + first_sym + i;
        જો (sym->st_shndx == SHN_UNDEF) {
            પૂર્ણાંક sym_bind = ELFW(ST_BIND)(sym->st_info);
            પૂર્ણાંક sym_type = ELFW(ST_TYPE)(sym->st_info);
            જો (sym_bind == STB_LOCAL)
                sym_bind = STB_GLOBAL;
#ifndef TCC_TARGET_PE
            જો (sym_bind == STB_GLOBAL && s1->output_type == TCC_OUTPUT_OBJ) {
                /* undefined symbols with STT_FUNC are confusing gnu ld when
                   linking statically to STT_GNU_IFUNC.  Keep TLS typed,
                   otherwise gnu ld rejects non-TLS refs to TLS definitions. */
                જો (sym_type != STT_TLS)
                    sym_type = STT_NOTYPE;
            }
#endif
            sym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
        }
        tr[i] = set_elf_sym(s, sym->st_કિંમત, sym->st_size, sym->st_info,
            sym->st_other, sym->st_shndx, (અક્ષર*)s->link->data + sym->st_name);
    }
    /* now update relocations */
    update_relocs(s1, s, tr, first_sym);
    tcc_free(tr);
    /* record text/data/bss output for -bench info */
    માટે (i = 0; i < 4; ++i) {
        s = s1->sections[i + 1];
        s1->total_output[i] += s->data_offset - s->sh_offset;
    }
}

ST_FUNC Section *new_section(TCCState *s1, અચલ અક્ષર *name, પૂર્ણાંક sh_type, પૂર્ણાંક sh_flags)
{
    Section *sec;

    sec = tcc_mallocz(કદ(Section) + strlen(name));
    sec->s1 = s1;
    strcpy(sec->name, name);
    sec->sh_type = sh_type;
    sec->sh_flags = sh_flags;
    પસંદગી(sh_type) {
    સ્થિતિ SHT_GNU_versym:
        sec->sh_addralign = 2;
        તોડો;
    સ્થિતિ SHT_HASH:
    સ્થિતિ SHT_GNU_HASH:
    સ્થિતિ SHT_REL:
    સ્થિતિ SHT_RELA:
    સ્થિતિ SHT_DYNSYM:
    સ્થિતિ SHT_SYMTAB:
    સ્થિતિ SHT_DYNAMIC:
    સ્થિતિ SHT_GNU_verneed:
    સ્થિતિ SHT_GNU_verdef:
        sec->sh_addralign = PTR_SIZE;
        તોડો;
    સ્થિતિ SHT_STRTAB:
        sec->sh_addralign = 1;
        તોડો;
    મૂળભૂત:
        sec->sh_addralign =  PTR_SIZE; /* gcc/pcc default alignment */
        તોડો;
    }

    જો (sh_flags & SHF_PRIVATE) {
        dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } નહીંતર {
        sec->sh_અંક = s1->nb_sections;
        dynarray_add(&s1->sections, &s1->nb_sections, sec);
    }

    પાછા sec;
}

ST_FUNC શૂન્ય init_symtab(Section *s)
{
    પૂર્ણાંક *ptr, nb_buckets = 1;
    put_elf_str(s->link, "");
    section_ptr_add(s, કદ (ElfW(Sym)));
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + 1) * કદ(પૂર્ણાંક));
    ptr[0] = nb_buckets;
    ptr[1] = 1;
    memset(ptr + 2, 0, (nb_buckets + 1) * કદ(પૂર્ણાંક));
}

ST_FUNC Section *new_symtab(TCCState *s1,
                           અચલ અક્ષર *symtab_name, પૂર્ણાંક sh_type, પૂર્ણાંક sh_flags,
                           અચલ અક્ષર *strtab_name,
                           અચલ અક્ષર *hash_name, પૂર્ણાંક hash_sh_flags)
{
    Section *symtab, *strtab, *hash;
    symtab = new_section(s1, symtab_name, sh_type, sh_flags);
    symtab->sh_entsize = કદ(ElfW(Sym));
    strtab = new_section(s1, strtab_name, SHT_STRTAB, sh_flags);
    symtab->link = strtab;
    hash = new_section(s1, hash_name, SHT_HASH, hash_sh_flags);
    hash->sh_entsize = કદ(પૂર્ણાંક);
    symtab->hash = hash;
    hash->link = symtab;
    init_symtab(symtab);
    પાછા symtab;
}

/* realloc section and set its content to zero */
ST_FUNC શૂન્ય section_realloc(Section *sec, unsigned long new_size)
{
    unsigned long size;
    unsigned અક્ષર *data;

    size = sec->data_allocated;
    જો (size == 0)
        size = 1;
    જ્યારે (size < new_size)
        size = size * 2;
    data = tcc_realloc(sec->data, size);
    memset(data + sec->data_allocated, 0, size - sec->data_allocated);
    sec->data = data;
    sec->data_allocated = size;
}

/* reserve at least 'size' bytes aligned per 'align' in section
   'sec' from current offset, and return the aligned offset */
ST_FUNC size_t section_add(Section *sec, addr_t size, પૂર્ણાંક align)
{
    size_t offset, offset1;

    offset = (sec->data_offset + align - 1) & -align;
    offset1 = offset + size;
    જો (sec->sh_type != SHT_NOBITS && offset1 > sec->data_allocated)
        section_realloc(sec, offset1);
    sec->data_offset = offset1;
    જો (align > sec->sh_addralign)
        sec->sh_addralign = align;
    પાછા offset;
}

/* reserve at least 'size' bytes in section 'sec' from
   sec->data_offset. */
ST_FUNC શૂન્ય *section_ptr_add(Section *sec, addr_t size)
{
    size_t offset = section_add(sec, size, 1);
    પાછા sec->data + offset;
}

#ifndef ELF_OBJ_ONLY
/* reserve at least 'size' bytes from section start */
સ્થિર શૂન્ય section_reserve(Section *sec, unsigned long size)
{
    જો (size > sec->data_allocated)
        section_realloc(sec, size);
    જો (size > sec->data_offset)
        sec->data_offset = size;
}
#endif

સ્થિર Section *have_section(TCCState *s1, અચલ અક્ષર *name)
{
    Section *sec;
    પૂર્ણાંક i;
    માટે(i = 1; i < s1->nb_sections; i++) {
        sec = s1->sections[i];
        જો (!strcmp(name, sec->name))
            પાછા sec;
    }
    પાછા ખાલી;
}

/* return a reference to a section, and create it if it does not
   exists */
ST_FUNC Section *find_section(TCCState *s1, અચલ અક્ષર *name)
{
    Section *sec = have_section(s1, name);
    જો (sec)
        પાછા sec;
    /* sections are created as PROGBITS */
    પાછા new_section(s1, name, SHT_PROGBITS, SHF_ALLOC);
}

/* ------------------------------------------------------------------------- */

ST_FUNC પૂર્ણાંક put_elf_str(Section *s, અચલ અક્ષર *sym)
{
    પૂર્ણાંક offset, len;
    અક્ષર *ptr;

    len = strlen(sym) + 1;
    offset = s->data_offset;
    ptr = section_ptr_add(s, len);
    memmove(ptr, sym, len);
    પાછા offset;
}

/* elf symbol hashing function */
સ્થિર ElfW(Word) elf_hash(અચલ unsigned અક્ષર *name)
{
    ElfW(Word) h = 0, g;

    જ્યારે (*name) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        જો (g)
            h ^= g >> 24;
        h &= ~g;
    }
    પાછા h;
}

/* rebuild hash table of section s */
/* NOTE: we do factorize the hash table code to go faster */
સ્થિર શૂન્ય rebuild_hash(Section *s, unsigned પૂર્ણાંક nb_buckets)
{
    ElfW(Sym) *sym;
    પૂર્ણાંક *ptr, *hash, nb_syms, sym_index, h;
    unsigned અક્ષર *strtab;

    strtab = s->link->data;
    nb_syms = s->data_offset / કદ(ElfW(Sym));

    જો (!nb_buckets)
        nb_buckets = ((પૂર્ણાંક*)s->hash->data)[0];

    s->hash->data_offset = 0;
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + nb_syms) * કદ(પૂર્ણાંક));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    memset(hash, 0, (nb_buckets + 1) * કદ(પૂર્ણાંક));
    ptr += nb_buckets + 1;

    sym = (ElfW(Sym) *)s->data + 1;
    માટે(sym_index = 1; sym_index < nb_syms; sym_index++) {
        જો (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            h = elf_hash(strtab + sym->st_name) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_index;
        } નહીંતર {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}

/* return the symbol number */
ST_FUNC પૂર્ણાંક put_elf_sym(Section *s, addr_t કિંમત, unsigned long size,
    પૂર્ણાંક info, પૂર્ણાંક other, પૂર્ણાંક shndx, અચલ અક્ષર *name)
{
    પૂર્ણાંક name_offset, sym_index;
    પૂર્ણાંક nbuckets, h;
    ElfW(Sym) *sym;
    Section *hs;

    sym = section_ptr_add(s, કદ(ElfW(Sym)));
    જો (name && name[0])
        name_offset = put_elf_str(s->link, name);
    નહીંતર
        name_offset = 0;
    /* XXX: endianness */
    sym->st_name = name_offset;
    sym->st_કિંમત = કિંમત;
    sym->st_size = size;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
    sym_index = sym - (ElfW(Sym) *)s->data;
    hs = s->hash;
    જો (hs) {
        પૂર્ણાંક *ptr, *base;
        ptr = section_ptr_add(hs, કદ(પૂર્ણાંક));
        base = (પૂર્ણાંક *)hs->data;
        /* only add global or weak symbols. */
        જો (ELFW(ST_BIND)(info) != STB_LOCAL) {
            /* add another hashing entry */
            nbuckets = base[0];
            h = elf_hash((unsigned અક્ષર *)s->link->data + name_offset) % nbuckets;
            *ptr = base[2 + h];
            base[2 + h] = sym_index;
            base[1]++;
            /* we resize the hash table */
            hs->nb_hashed_syms++;
            જો (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } નહીંતર {
            *ptr = 0;
            base[1]++;
        }
    }
    પાછા sym_index;
}

ST_FUNC પૂર્ણાંક find_elf_sym(Section *s, અચલ અક્ષર *name)
{
    ElfW(Sym) *sym;
    Section *hs;
    પૂર્ણાંક nbuckets, sym_index, h;
    અચલ અક્ષર *name1;

    hs = s->hash;
    જો (!hs)
        પાછા 0;
    nbuckets = ((પૂર્ણાંક *)hs->data)[0];
    h = elf_hash((unsigned અક્ષર *) name) % nbuckets;
    sym_index = ((પૂર્ણાંક *)hs->data)[2 + h];
    જ્યારે (sym_index != 0) {
        sym = &((ElfW(Sym) *)s->data)[sym_index];
        name1 = (અક્ષર *) s->link->data + sym->st_name;
        જો (!strcmp(name, name1))
            પાછા sym_index;
        sym_index = ((પૂર્ણાંક *)hs->data)[2 + nbuckets + sym_index];
    }
    પાછા 0;
}

/* return elf symbol value, signal error if 'err' is nonzero, decorate
   name if FORC */
ST_FUNC addr_t get_sym_addr(TCCState *s1, અચલ અક્ષર *name, પૂર્ણાંક err, પૂર્ણાંક forc)
{
    પૂર્ણાંક sym_index;
    ElfW(Sym) *sym;
    અક્ષર buf[256];
    જો (forc && s1->leading_underscore
#ifdef TCC_TARGET_PE
        /* win32-32bit stdcall symbols always have _ already */
        && !strchr(name, '@')
#endif
        ) {
        buf[0] = '_';
        pstrcpy(buf + 1, કદ(buf) - 1, name);
        name = buf;
    }
    sym_index = find_elf_sym(s1->symtab, name);
    sym = &((ElfW(Sym) *)s1->symtab->data)[sym_index];
    જો (!sym_index || sym->st_shndx == SHN_UNDEF) {
        જો (err)
            tcc_error_noabort("%s not defined", name);
        પાછા (addr_t)-1;
    }
    પાછા sym->st_કિંમત;
}

/* return elf symbol value */
LIBTCCAPI શૂન્ય *tcc_get_પ્રતીક(TCCState *s, અચલ અક્ષર *name)
{
    addr_t addr = get_sym_addr(s, name, 0, 1);
    પાછા addr == -1 ? ખાલી : (શૂન્ય*)(uintptr_t)addr;
}

LIBTCCAPI પૂર્ણાંક tcc_add_પ્રતીક(TCCState *s1, અચલ અક્ષર *name, અચલ શૂન્ય *val)
{
#ifdef TCC_TARGET_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s1, 0, name, (uintptr_t)val);
#નહીંતર
    અક્ષર buf[256];
    જો (s1->leading_underscore) {
        buf[0] = '_';
        pstrcpy(buf + 1, કદ(buf) - 1, name);
        name = buf;
    }
    set_global_sym(s1, name, ખાલી, (addr_t)(uintptr_t)val); /* NULL: SHN_ABS */
#endif
    પાછા 0;
}

/* list elf symbol names and values */
ST_FUNC શૂન્ય list_elf_symbols(TCCState *s, શૂન્ય *ctx,
    શૂન્ય (*પ્રતીક_cb)(શૂન્ય *ctx, અચલ અક્ષર *name, અચલ શૂન્ય *val))
{
    ElfW(Sym) *sym;
    Section *symtab;
    પૂર્ણાંક sym_index, end_sym;
    અચલ અક્ષર *name;
    unsigned અક્ષર sym_vis, sym_bind;

    symtab = s->symtab;
    end_sym = symtab->data_offset / કદ (ElfSym);
    માટે (sym_index = 0; sym_index < end_sym; ++sym_index) {
        sym = &((ElfW(Sym) *)symtab->data)[sym_index];
        જો (sym->st_કિંમત) {
            name = (અક્ષર *) symtab->link->data + sym->st_name;
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            sym_vis = ELFW(ST_VISIBILITY)(sym->st_other);
            જો (sym_bind == STB_GLOBAL && sym_vis == STV_DEFAULT)
                પ્રતીક_cb(ctx, name, (શૂન્ય*)(uintptr_t)sym->st_કિંમત);
        }
    }
}

/* list elf symbol names and values */
LIBTCCAPI શૂન્ય tcc_list_symbols(TCCState *s, શૂન્ય *ctx,
    શૂન્ય (*પ્રતીક_cb)(શૂન્ય *ctx, અચલ અક્ષર *name, અચલ શૂન્ય *val))
{
    list_elf_symbols(s, ctx, પ્રતીક_cb);
}

#ifndef ELF_OBJ_ONLY
સ્થિર શૂન્ય
version_add (TCCState *s1)
{
    પૂર્ણાંક i;
    ElfW(Sym) *sym;
    ElfW(Verneed) *vn = ખાલી;
    Section *symtab;
    પૂર્ણાંક sym_index, end_sym, nb_versions = 2, nb_entries = 0;
    ElfW(Half) *versym;
    અચલ અક્ષર *name;

    જો (0 == nb_sym_versions)
        પાછા;
    versym_section = new_section(s1, ".gnu.version", SHT_GNU_versym, SHF_ALLOC);
    versym_section->sh_entsize = કદ(ElfW(Half));
    versym_section->link = s1->dynsym;

    /* add needed symbols */
    symtab = s1->dynsym;
    end_sym = symtab->data_offset / કદ (ElfSym);
    versym = section_ptr_add(versym_section, end_sym * કદ(ElfW(Half)));
    માટે (sym_index = 1; sym_index < end_sym; ++sym_index) {
        પૂર્ણાંક dllindex, verndx;
        sym = &((ElfW(Sym) *)symtab->data)[sym_index];
        name = (અક્ષર *) symtab->link->data + sym->st_name;
        dllindex = find_elf_sym(s1->dynsymtab_section, name);
        verndx = (dllindex && dllindex < nb_sym_to_version)
                 ? sym_to_version[dllindex] : -1;
        જો (verndx >= 0
            /* XXX: on android, clang refuses to link with a libtcc.so made by tcc
               when defined symbols have a version > 1 or when the version is '0'.
               Whereas version '1' for example for 'signal' in an exe defeats
               bcheck's signal_redir. */
            && (sym->st_shndx == SHN_UNDEF || (s1->output_type & TCC_OUTPUT_EXE))
            ) {
            જો (!sym_versions[verndx].out_index)
              sym_versions[verndx].out_index = nb_versions++;
            versym[sym_index] = sym_versions[verndx].out_index;
        } નહીંતર {
            versym[sym_index] = 1; /* (*global*) */
        }
        //printf("SYM %d %s\n", versym[sym_index], name);
    }
    /* generate verneed section, but not when it will be empty.  Some
       dynamic linkers look at their contents even when DTVERNEEDNUM and
       section size is zero.  */
    જો (nb_versions > 2) {
        verneed_section = new_section(s1, ".gnu.version_r",
                                      SHT_GNU_verneed, SHF_ALLOC);
        verneed_section->link = s1->dynsym->link;
        માટે (i = nb_sym_versions; i-- > 0;) {
            સંરચના sym_version *sv = &sym_versions[i];
            પૂર્ણાંક n_same_libs = 0, prev;
            size_t vnofs;
            ElfW(Vernaux) *vna = 0;
            જો (sv->out_index < 1)
              ચાલુ;

            /* make sure that a DT_NEEDED tag is put */
            /* abitest-tcc fails on older i386-linux with "ld-linux.so.2" DT_NEEDED
               ret_int_test... Inconsistency detected by ld.so: dl-minimal.c: 148:
               realloc: Assertion `ptr == alloc_last_block' failed! */
            જો (strcmp(sv->lib, "ld-linux.so.2"))
                tcc_add_dllref(s1, sv->lib, 0);

            vnofs = section_add(verneed_section, કદ(*vn), 1);
            vn = (ElfW(Verneed)*)(verneed_section->data + vnofs);
            vn->vn_version = 1;
            vn->vn_file = put_elf_str(verneed_section->link, sv->lib);
            vn->vn_aux = કદ (*vn);
            કરો {
                prev = sv->prev_same_lib;
                જો (sv->out_index > 0) {
                    vna = section_ptr_add(verneed_section, કદ(*vna));
                    vna->vna_hash = elf_hash ((અચલ unsigned અક્ષર *)sv->version);
                    vna->vna_flags = 0;
                    vna->vna_other = sv->out_index;
                    sv->out_index = -2;
                    vna->vna_name = put_elf_str(verneed_section->link, sv->version);
                    vna->vna_next = કદ (*vna);
                    //printf("LIB %d %s %s\n", vna->vna_other, sv->lib, verneed_section->link->data + vna->vna_name);
                    n_same_libs++;
                }
                જો (prev >= 0)
                  sv = &sym_versions[prev];
            } જ્યારે(prev >= 0);
            vna->vna_next = 0;
            vn = (ElfW(Verneed)*)(verneed_section->data + vnofs);
            vn->vn_cnt = n_same_libs;
            vn->vn_next = કદ(*vn) + n_same_libs * કદ(*vna);
            nb_entries++;
        }
        જો (vn)
          vn->vn_next = 0;
        verneed_section->sh_info = nb_entries;
    }
    dt_verneednum = nb_entries;
}
#endif /* ndef ELF_OBJ_ONLY */

/* catch .tbss also */
સ્થિર પૂર્ણાંક IS_BSS(TCCState *s1, પૂર્ણાંક ndx)
{
    પાછા ndx == SHN_COMMON
     || (ndx < s1->nb_sections
         && s1->sections[ndx]->sh_type == SHT_NOBITS);
}

/* add an elf symbol : check if it is already defined and patch
   it. Return symbol index. NOTE that sh_num can be SHN_UNDEF. */
ST_FUNC પૂર્ણાંક set_elf_sym(Section *s, addr_t કિંમત, unsigned long size,
                       પૂર્ણાંક info, પૂર્ણાંક other, પૂર્ણાંક shndx, અચલ અક્ષર *name)
{
    TCCState *s1 = s->s1;
    ElfW(Sym) *esym;
    પૂર્ણાંક sym_bind, sym_index, sym_type, esym_bind;
    unsigned અક્ષર sym_vis, esym_vis, new_vis;

    sym_bind = ELFW(ST_BIND)(info);
    sym_type = ELFW(ST_TYPE)(info);
    sym_vis = ELFW(ST_VISIBILITY)(other);

    જો (sym_bind != STB_LOCAL) {
        /* we search global or weak symbols */
        sym_index = find_elf_sym(s, name);
        જો (!sym_index)
            જાઓ do_def;
        esym = &((ElfW(Sym) *)s->data)[sym_index];
        જો (esym->st_કિંમત == કિંમત && esym->st_size == size && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            પાછા sym_index;
        જો (esym->st_shndx != SHN_UNDEF) {
            esym_bind = ELFW(ST_BIND)(esym->st_info);
            /* propagate the most constraining visibility */
            /* STV_DEFAULT(0)<STV_PROTECTED(3)<STV_HIDDEN(2)<STV_INTERNAL(1) */
            esym_vis = ELFW(ST_VISIBILITY)(esym->st_other);
            જો (esym_vis == STV_DEFAULT) {
                new_vis = sym_vis;
            } નહીંતર જો (sym_vis == STV_DEFAULT) {
                new_vis = esym_vis;
            } નહીંતર {
                new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
            }
            esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
                             | new_vis;
            જો (shndx == SHN_UNDEF) {
                /* ignore adding of undefined symbol if the
                   corresponding symbol is already defined */
            } નહીંતર જો (sym_bind == STB_GLOBAL && esym_bind == STB_WEAK) {
                /* global overrides weak, so patch */
                જાઓ do_patch;
            } નહીંતર જો (sym_bind == STB_WEAK && esym_bind == STB_GLOBAL) {
                /* weak is ignored if already global */
            } નહીંતર જો (sym_bind == STB_WEAK && esym_bind == STB_WEAK) {
                /* keep first-found weak definition, ignore subsequents */
            } નહીંતર જો (sym_vis == STV_HIDDEN || sym_vis == STV_INTERNAL) {
                /* ignore hidden symbols after */
            } નહીંતર જો (s->sh_flags & SHF_DYNSYM) {
                /* we accept that two DLL define the same symbol */
            } નહીંતર જો (!IS_BSS(s1, shndx) && IS_BSS(s1, esym->st_shndx)) {
                /* data symbol gets precedence over common/bss */
                જાઓ do_patch;
            } નહીંતર જો (IS_BSS(s1, shndx)) {
                /* data symbol keeps precedence over common/bss */
	    } નહીંતર જો (esym->st_other & ST_ASM_SET) {
		/* If the existing symbol came from an asm .set
		   we can override.  */
		જાઓ do_patch;
            } નહીંતર {
#જો 0
                printf("new_bind=%x new_shndx=%x new_vis=%x old_bind=%x old_shndx=%x old_vis=%x\n",
                       sym_bind, shndx, new_vis, esym_bind, esym->st_shndx, esym_vis);
#endif
                tcc_error_noabort("link symbol '%s' defined twice", name);
            }
        } નહીંતર {
            esym->st_other = other;
        do_patch:
            esym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
            esym->st_shndx = shndx;
            esym->st_કિંમત = કિંમત;
            esym->st_size = size;
        }
    } નહીંતર {
    do_def:
        sym_index = put_elf_sym(s, કિંમત, size,
                                ELFW(ST_INFO)(sym_bind, sym_type), other,
                                shndx, name);
    }
    પાછા sym_index;
}

/* put relocation */
ST_FUNC શૂન્ય put_elf_reloca(Section *symtab, Section *s, unsigned long offset,
                            પૂર્ણાંક type, પૂર્ણાંક પ્રતીક, addr_t addend)
{
    TCCState *s1 = s->s1;
    અક્ષર buf[256];
    Section *sr;
    ElfW_Rel *rel;

    sr = s->reloc;
    જો (!sr) {
        /* if no relocation section, create it */
        snprintf(buf, કદ(buf), REL_SECTION_FMT, s->name);
        /* if the symtab is allocated, then we consider the relocation
           are also */
        sr = new_section(s->s1, buf, SHT_RELX, symtab->sh_flags);
        sr->sh_entsize = કદ(ElfW_Rel);
        sr->link = symtab;
        sr->sh_info = s->sh_અંક;
        s->reloc = sr;
    }
    rel = section_ptr_add(sr, કદ(ElfW_Rel));
    rel->r_offset = offset;
    rel->r_info = ELFW(R_INFO)(પ્રતીક, type);
#જો SHT_RELX == SHT_RELA
    rel->r_addend = addend;
#endif
    જો (SHT_RELX != SHT_RELA && addend)
        tcc_error_noabort("non-zero addend on REL architecture");
}

ST_FUNC શૂન્ય put_elf_reloc(Section *symtab, Section *s, unsigned long offset,
                           પૂર્ણાંક type, પૂર્ણાંક પ્રતીક)
{
    put_elf_reloca(symtab, s, offset, type, પ્રતીક, 0);
}

ST_FUNC સંરચના sym_attr *get_sym_attr(TCCState *s1, પૂર્ણાંક index, પૂર્ણાંક alloc)
{
    પૂર્ણાંક n;
    સંરચના sym_attr *tab;

    જો (index >= s1->nb_sym_attrs) {
        જો (!alloc)
            પાછા s1->sym_attrs;
        /* find immediately bigger power of 2 and reallocate array */
        n = 1;
        જ્યારે (index >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * કદ(*s1->sym_attrs));
        s1->sym_attrs = tab;
        memset(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * કદ(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    પાછા &s1->sym_attrs[index];
}

સ્થિર શૂન્ય update_relocs(TCCState *s1, Section *s, પૂર્ણાંક *old_to_new_syms, પૂર્ણાંક first_sym)
{
    પૂર્ણાંક i, type, sym_index;
    Section *sr;
    ElfW_Rel *rel;

    માટે(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        જો (sr->sh_type == SHT_RELX && sr->link == s) {
            for_each_elem(sr, 0, rel, ElfW_Rel) {
                sym_index = ELFW(R_SYM)(rel->r_info);
                type = ELFW(R_TYPE)(rel->r_info);
                જો ((sym_index -= first_sym) < 0)
                    ચાલુ; /* zero sym_index in reloc (can happen with asm) */
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
સ્થિર શૂન્ય sort_syms(TCCState *s1, Section *s)
{
    પૂર્ણાંક *old_to_new_syms;
    ElfW(Sym) *new_syms;
    પૂર્ણાંક nb_syms, i;
    ElfW(Sym) *p, *q;

    nb_syms = s->data_offset / કદ(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * કદ(ElfW(Sym)));
    old_to_new_syms = tcc_malloc(nb_syms * કદ(પૂર્ણાંક));

    /* first pass for local symbols */
    p = (ElfW(Sym) *)s->data;
    q = new_syms;
    માટે(i = 0; i < nb_syms; i++) {
        જો (ELFW(ST_BIND)(p->st_info) == STB_LOCAL) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    /* save the number of local symbols in section header */
    જો( s->sh_size )    /* this 'if' makes IDA happy */
        s->sh_info = q - new_syms;

    /* then second pass for non local symbols */
    p = (ElfW(Sym) *)s->data;
    માટે(i = 0; i < nb_syms; i++) {
        જો (ELFW(ST_BIND)(p->st_info) != STB_LOCAL) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }

    /* we copy the new symbols to the old */
    memcpy(s->data, new_syms, nb_syms * કદ(ElfW(Sym)));
    tcc_free(new_syms);

    update_relocs(s1, s, old_to_new_syms, 0);
    tcc_free(old_to_new_syms);
}

#ifndef ELF_OBJ_ONLY
/* See: https://flapenguin.me/elf-dt-gnu-hash */
#define	ELFCLASS_BITS (PTR_SIZE * 8)

સ્થિર Section *create_gnu_hash(TCCState *s1)
{
    પૂર્ણાંક nb_syms, i, ndef, nbuckets, symoffset, bloom_size, bloom_shift;
    ElfW(Sym) *p;
    Section *gnu_hash;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr;

    gnu_hash = new_section(s1, ".gnu.hash", SHT_GNU_HASH, SHF_ALLOC);
    gnu_hash->link = dynsym->hash->link;

    nb_syms = dynsym->data_offset / કદ(ElfW(Sym));

    /* count def symbols */
    ndef = 0;
    p = (ElfW(Sym) *)dynsym->data;
    માટે(i = 0; i < nb_syms; i++, p++)
        ndef += p->st_shndx != SHN_UNDEF;

    /* calculate gnu hash sizes and fill header */
    nbuckets = ndef / 4 + 1;
    symoffset = nb_syms - ndef;
    bloom_shift = PTR_SIZE == 8 ? 6 : 5;
    bloom_size = 1; /* must be power of two */
    જ્યારે (ndef >= bloom_size * (1 << (bloom_shift - 3)))
	bloom_size *= 2;
    ptr = section_ptr_add(gnu_hash, 4 * 4 +
				    PTR_SIZE * bloom_size +
				    nbuckets * 4 +
				    ndef * 4);
    ptr[0] = nbuckets;
    ptr[1] = symoffset;
    ptr[2] = bloom_size;
    ptr[3] = bloom_shift;
    પાછા gnu_hash;
}

સ્થિર Elf32_Word elf_gnu_hash (અચલ unsigned અક્ષર *name)
{
    Elf32_Word h = 5381;
    unsigned અક્ષર c;

    જ્યારે ((c = *name++))
        h = h * 33 + c;
    પાછા h;
}

સ્થિર શૂન્ય update_gnu_hash(TCCState *s1, Section *gnu_hash)
{
    પૂર્ણાંક *old_to_new_syms;
    ElfW(Sym) *new_syms;
    પૂર્ણાંક nb_syms, i, nbuckets, bloom_size, bloom_shift;
    ElfW(Sym) *p, *q;
    Section *vs;
    Section *dynsym = s1->dynsym;
    Elf32_Word *ptr, *buckets, *chain, *hash;
    unsigned પૂર્ણાંક *nextbuck;
    addr_t *bloom;
    unsigned અક્ષર *strtab;
    સંરચના { પૂર્ણાંક first, last; } *buck;

    strtab = dynsym->link->data;
    nb_syms = dynsym->data_offset / કદ(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * કદ(ElfW(Sym)));
    old_to_new_syms = tcc_malloc(nb_syms * કદ(પૂર્ણાંક));
    hash = tcc_malloc(nb_syms * કદ(Elf32_Word));
    nextbuck = tcc_malloc(nb_syms * કદ(પૂર્ણાંક));

    /* calculate hashes and copy undefs */
    p = (ElfW(Sym) *)dynsym->data;
    q = new_syms;
    માટે(i = 0; i < nb_syms; i++, p++) {
        જો (p->st_shndx == SHN_UNDEF) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
	નહીંતર
	    hash[i] = elf_gnu_hash(strtab + p->st_name);
    }

    ptr = (Elf32_Word *) gnu_hash->data;
    nbuckets = ptr[0];
    bloom_size = ptr[2];
    bloom_shift = ptr[3];
    bloom = (addr_t *) (શૂન્ય *) &ptr[4];
    buckets = (Elf32_Word*) (શૂન્ય *) &bloom[bloom_size];
    chain = &buckets[nbuckets];
    buck = tcc_malloc(nbuckets * કદ(*buck));

    જો (gnu_hash->data_offset != 4 * 4 +
				 PTR_SIZE * bloom_size +
				 nbuckets * 4 +
				 (nb_syms - (q - new_syms)) * 4)
	tcc_error_noabort ("gnu_hash size incorrect");

    /* find buckets */
    માટે(i = 0; i < nbuckets; i++)
	buck[i].first = -1;

    p = (ElfW(Sym) *)dynsym->data;
    માટે(i = 0; i < nb_syms; i++, p++)
        જો (p->st_shndx != SHN_UNDEF) {
	    પૂર્ણાંક bucket = hash[i] % nbuckets;

	    જો (buck[bucket].first == -1)
		buck[bucket].first = buck[bucket].last = i;
	    નહીંતર {
		nextbuck[buck[bucket].last] = i;
		buck[bucket].last = i;
	    }
	}

    /* fill buckets/chains/bloom and sort symbols */
    p = (ElfW(Sym) *)dynsym->data;
    માટે(i = 0; i < nbuckets; i++) {
	પૂર્ણાંક cur = buck[i].first;

	જો (cur != -1) {
	    buckets[i] = q - new_syms;
	    માટે (;;) {
                old_to_new_syms[cur] = q - new_syms;
                *q++ = p[cur];
	        *chain++ = hash[cur] & ~1;
		bloom[(hash[cur] / ELFCLASS_BITS) % bloom_size] |=
		    (addr_t)1 << (hash[cur] % ELFCLASS_BITS) |
		    (addr_t)1 << ((hash[cur] >> bloom_shift) % ELFCLASS_BITS);
		જો (cur == buck[i].last)
		    તોડો;
		cur = nextbuck[cur];
	    }
	    chain[-1] |= 1;
	}
    }

    memcpy(dynsym->data, new_syms, nb_syms * કદ(ElfW(Sym)));
    tcc_free(new_syms);
    tcc_free(hash);
    tcc_free(buck);
    tcc_free(nextbuck);

    update_relocs(s1, dynsym, old_to_new_syms, 0);

    /* modify the versions */
    vs = versym_section;
    જો (vs) {
	ElfW(Half) *newver, *versym = (ElfW(Half) *)vs->data;

	જો (1/*versym*/) {
            newver = tcc_malloc(nb_syms * કદ(*newver));
	    માટે (i = 0; i < nb_syms; i++)
	        newver[old_to_new_syms[i]] = versym[i];
	    memcpy(vs->data, newver, nb_syms * કદ(*newver));
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
ST_FUNC શૂન્ય relocate_syms(TCCState *s1, Section *symtab, પૂર્ણાંક do_resolve)
{
    ElfW(Sym) *sym;
    પૂર્ણાંક sym_bind, sh_અંક;
    અચલ અક્ષર *name;

    for_each_elem(symtab, 1, sym, ElfW(Sym)) {
        sh_અંક = sym->st_shndx;
        જો (sh_અંક == SHN_UNDEF) {
            જો (do_resolve == 2) /* relocating dynsym */
                ચાલુ;
            name = (અક્ષર *) s1->symtab->link->data + sym->st_name;
            /* Use ld.so to resolve symbol for us (for tcc -run) */
            જો (do_resolve) {
#જો defined TCC_IS_NATIVE && !defined TCC_TARGET_PE
                /* dlsym() needs the undecorated name.  */
                અચલ અક્ષર *name_ud = &name[s1->leading_underscore];
                શૂન્ય *addr = ખાલી;
                જો (!s1->nostdlib)
                    addr = dlsym(RTLD_DEFAULT, name_ud);
		જો (addr == ખાલી) {
		    પૂર્ણાંક i;
		    માટે (i = 0; i < s1->nb_loaded_dlls; i++)
                        જો ((addr = dlsym(s1->loaded_dlls[i]->handle, name_ud)))
			    તોડો;
		}
                જો (addr) {
                    sym->st_કિંમત = (addr_t) addr;
#ifdef DEBUG_RELOC
		    printf ("relocate_sym: %s -> 0x%lx\n", name, sym->st_કિંમત);
#endif
                    જાઓ found;
                }
#endif
            /* if dynamic symbol exist, it will be used in relocate_section */
            } નહીંતર જો (s1->dynsym && find_elf_sym(s1->dynsym, name))
                જાઓ found;
            /* XXX: _fp_hw seems to be part of the ABI, so we ignore
               it */
            જો (!strcmp(name, "_fp_hw"))
                જાઓ found;
            /* only weak symbols are accepted to be undefined. Their
               value is zero */
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            જો (sym_bind == STB_WEAK)
                sym->st_કિંમત = 0;
            નહીંતર
                tcc_error_noabort("unresolved reference to '%s'", name);

        } નહીંતર જો (sh_અંક < SHN_LORESERVE) {
            /* add section base */
            sym->st_કિંમત += s1->sections[sym->st_shndx]->sh_addr;
        }
    found: ;
    }
}

/* relocate a given section (CPU dependent) by applying the relocations
   in the associated relocation section */
સ્થિર શૂન્ય relocate_section(TCCState *s1, Section *s, Section *sr)
{
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    પૂર્ણાંક type, sym_index;
    unsigned અક્ષર *ptr;
    addr_t tgt, addr;
    પૂર્ણાંક is_dwarf = s->sh_અંક >= s1->dwlo && s->sh_અંક < s1->dwhi;

    qrel = (ElfW_Rel *)sr->data;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
	જો (s->data == ખાલી) /* bss */
	    ચાલુ;
        ptr = s->data + rel->r_offset;
        sym_index = ELFW(R_SYM)(rel->r_info);
        sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
        type = ELFW(R_TYPE)(rel->r_info);
        tgt = sym->st_કિંમત;
#જો SHT_RELX == SHT_RELA
        tgt += rel->r_addend;
#endif
        જો (is_dwarf && type == R_DATA_32DW
            && sym->st_shndx >= s1->dwlo && sym->st_shndx < s1->dwhi) {
            /* dwarf section relocation to each other */
            add32le(ptr, tgt - s1->sections[sym->st_shndx]->sh_addr);
            ચાલુ;
        }
        addr = s->sh_addr + rel->r_offset;
        relocate(s1, rel, type, ptr, addr, tgt);
    }

#ifndef ELF_OBJ_ONLY
    /* if the relocation is allocated, we change its symbol table */
    જો (sr->sh_flags & SHF_ALLOC) {
        sr->link = s1->dynsym;
        જો (s1->output_type & TCC_OUTPUT_DYN) {
            size_t r = (uint8_t*)qrel - sr->data;
            જો (કદ ((Stab_Sym*)0)->n_કિંમત < PTR_SIZE
                && 0 == strcmp(s->name, ".stab"))
                r = 0; /* cannot apply 64bit relocation to 32bit value */
            sr->data_offset = sr->sh_size = r;
#ifdef CONFIG_TCC_PIE
            જો (r && (s->sh_flags & SHF_EXECINSTR))
                tcc_warning("%d relocations to %s", (unsigned)(r / કદ *qrel), s->name);
#endif
        }
    }
#endif

#ifdef TCC_TARGET_RISCV64
    dynarray_reset(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries);
#endif
}

/* relocate all sections */
ST_FUNC શૂન્ય relocate_sections(TCCState *s1)
{
    પૂર્ણાંક i;
    Section *s, *sr;

    માટે (i = 1; i < s1->nb_sections; ++i) {
        sr = s1->sections[i];
        જો (sr->sh_type != SHT_RELX)
            ચાલુ;
        s = s1->sections[sr->sh_info];
#ifndef TCC_TARGET_MACHO
        જો (s != s1->got
            || s1->static_link
            || s1->output_type == TCC_OUTPUT_MEMORY)
#endif
        {
            relocate_section(s1, s, sr);
        }
#ifndef ELF_OBJ_ONLY
        જો (sr->sh_flags & SHF_ALLOC) {
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
સ્થિર પૂર્ણાંક prepare_dynamic_rel(TCCState *s1, Section *sr)
{
    પૂર્ણાંક ગણતરી_2 = 0;
#જો defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || \
    defined(TCC_TARGET_ARM) || defined(TCC_TARGET_ARM64) || \
    defined(TCC_TARGET_RISCV64)
    ElfW_Rel *rel;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
        પૂર્ણાંક sym_index = ELFW(R_SYM)(rel->r_info);
        પૂર્ણાંક type = ELFW(R_TYPE)(rel->r_info);
        પસંદગી(type) {
#જો defined(TCC_TARGET_I386)
        સ્થિતિ R_386_32:
            જો (!get_sym_attr(s1, sym_index, 0)->dyn_index
                && ((ElfW(Sym)*)symtab_section->data + sym_index)->st_shndx == SHN_UNDEF) {
                /* don't fixup unresolved (weak) symbols */
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_RELATIVE);
                તોડો;
            }
#અથવાજો defined(TCC_TARGET_X86_64)
        સ્થિતિ R_X86_64_32:
        સ્થિતિ R_X86_64_32S:
        સ્થિતિ R_X86_64_64:
#અથવાજો defined(TCC_TARGET_ARM)
        સ્થિતિ R_ARM_ABS32:
        સ્થિતિ R_ARM_TARGET1:
#અથવાજો defined(TCC_TARGET_ARM64)
        સ્થિતિ R_AARCH64_ABS32:
        સ્થિતિ R_AARCH64_ABS64:
#અથવાજો defined(TCC_TARGET_RISCV64)
        સ્થિતિ R_RISCV_32:
        સ્થિતિ R_RISCV_64:
#endif
            ગણતરી_2++;
            તોડો;
#જો defined(TCC_TARGET_I386)
        સ્થિતિ R_386_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    જો (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_PLT32);
	        તોડો;
	    }
	}
#અથવાજો defined(TCC_TARGET_X86_64)
        સ્થિતિ R_X86_64_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    જો (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_index, R_X86_64_PLT32);
	        તોડો;
	    }
	}
#અથવાજો defined(TCC_TARGET_ARM64)
        સ્થિતિ R_AARCH64_PREL32:
#endif
            જો (s1->output_type != TCC_OUTPUT_DLL)
                તોડો;
            જો (get_sym_attr(s1, sym_index, 0)->dyn_index)
                ગણતરી_2++;
            તોડો;
        મૂળભૂત:
            તોડો;
        }
    }
#endif
    પાછા ગણતરી_2;
}
#endif

#ifdef NEED_BUILD_GOT
સ્થિર પૂર્ણાંક build_got(TCCState *s1)
{
    /* if no got, then create it */
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    s1->got->sh_entsize = 4;
    /* keep space for _DYNAMIC pointer and two dummy got entries */
    section_ptr_add(s1->got, 3 * PTR_SIZE);
    પાછા set_elf_sym(symtab_section, 0, 0, ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
        0, s1->got->sh_અંક, "_GLOBAL_OFFSET_TABLE_");
}

/* Create a GOT and (for function call) a PLT entry corresponding to a symbol
   in s1->symtab. When creating the dynamic symbol table entry for the GOT
   relocation, use 'size' and 'info' for the corresponding symbol metadata.
   Returns the offset of the GOT or (if any) PLT entry. */
સ્થિર સંરચના sym_attr * put_got_entry(TCCState *s1, પૂર્ણાંક dyn_reloc_type,
                                       પૂર્ણાંક sym_index)
{
    પૂર્ણાંક need_plt_entry;
    અચલ અક્ષર *name;
    ElfW(Sym) *sym;
    સંરચના sym_attr *attr;
    unsigned got_offset;
    અક્ષર plt_name[200];
    પૂર્ણાંક len;
    Section *s_rel;

    need_plt_entry = (dyn_reloc_type == R_JMP_SLOT);
    attr = get_sym_attr(s1, sym_index, 1);

    /* In case a function is both called and its address taken 2 GOT entries
       are created, one for taking the address (GOT) and the other for the PLT
       entry (PLTGOT).  */
    જો (need_plt_entry ? attr->plt_offset : attr->got_offset)
        પાછા attr;

    s_rel = s1->got;
    જો (need_plt_entry) {
        જો (!s1->plt) {
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
    name = (અક્ષર *) symtab_section->link->data + sym->st_name;
    //printf("sym %d %s\n", need_plt_entry, name);

    જો (s1->dynsym) {
	જો (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
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
	} નહીંતર {
	    જો (0 == attr->dyn_index)
                attr->dyn_index = set_elf_sym(s1->dynsym, sym->st_કિંમત,
                                              sym->st_size, sym->st_info, 0,
                                              sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s_rel, got_offset, dyn_reloc_type,
			  attr->dyn_index);
	}
    } નહીંતર {
        put_elf_reloc(symtab_section, s1->got, got_offset, dyn_reloc_type,
                      sym_index);
    }

    જો (need_plt_entry) {
        attr->plt_offset = create_plt_entry(s1, got_offset, attr);

        /* create a symbol 'sym@plt' for the PLT jump vector */
        len = strlen(name);
        જો (len > કદ plt_name - 5)
            len = કદ plt_name - 5;
        memcpy(plt_name, name, len);
        strcpy(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_offset, 0,
            ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0, s1->plt->sh_અંક, plt_name);
    } નહીંતર {
        attr->got_offset = got_offset;
    }

    પાછા attr;
}

/* build GOT and PLT entries */
/* Two passes because R_JMP_SLOT should become first. Some targets
   (arm, arm64) do not allow mixing R_JMP_SLOT and R_GLOB_DAT. */
ST_FUNC શૂન્ય build_got_entries(TCCState *s1, પૂર્ણાંક got_sym)
{
    Section *s;
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    પૂર્ણાંક i, type, gotplt_entry, reloc_type, sym_index;
    સંરચના sym_attr *attr;
    પૂર્ણાંક pass = 0;
redo:
    માટે(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        જો (s->sh_type != SHT_RELX)
            ચાલુ;
        /* no need to handle got relocations */
        જો (s->link != symtab_section)
            ચાલુ;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_entry = gotplt_entry_type(type);
            જો (gotplt_entry == -1) {
                tcc_error_noabort ("Unknown relocation type for got: %d", type);
                ચાલુ;
            }
            sym_index = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];

            જો (gotplt_entry == NO_GOTPLT_ENTRY) {
                ચાલુ;
            }

            /* Automatically create PLT/GOT [entry] if it is an undefined
	       reference (resolved at runtime), or the symbol is absolute,
	       probably created by tcc_add_symbol, and thus on 64-bit
	       targets might be too far from application code.  */
            જો (gotplt_entry == AUTO_GOTPLT_ENTRY) {
                જો (sym->st_shndx == SHN_UNDEF) {
                    ElfW(Sym) *esym;
		    પૂર્ણાંક dynindex;
                    જો (!PCRELATIVE_DLLPLT
                        && (s1->output_type & TCC_OUTPUT_DYN))
                        ચાલુ;
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
		    જો (s1->dynsym) {
			/* dynsym isn't set for -run :-/  */
			dynindex = get_sym_attr(s1, sym_index, 0)->dyn_index;
			esym = (ElfW(Sym) *)s1->dynsym->data + dynindex;
			જો (dynindex
			    && (ELFW(ST_TYPE)(esym->st_info) == STT_FUNC
				|| (ELFW(ST_TYPE)(esym->st_info) == STT_NOTYPE
				    && ELFW(ST_TYPE)(sym->st_info) == STT_FUNC)))
			    જાઓ jmp_slot;
		    }
                } નહીંતર જો (sym->st_shndx == SHN_ABS) {
                    જો (sym->st_કિંમત == 0) /* from tcc_add_btstub() */
                        ચાલુ;
#ifndef TCC_TARGET_ARM
                    જો (PTR_SIZE != 8)
                        ચાલુ;
#endif
                    /* from tcc_add_symbol(): on 64 bit platforms these
                       need to go through .got */
                } નહીંતર
                    ચાલુ;
            }

#ifdef TCC_TARGET_I386
            જો ((type == R_386_PLT32 || type == R_386_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		જો (pass != 0)
		    ચાલુ;
                rel->r_info = ELFW(R_INFO)(sym_index, R_386_PC32);
                ચાલુ;
            }
#endif
#ifdef TCC_TARGET_X86_64
            જો ((type == R_X86_64_PLT32 || type == R_X86_64_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		જો (pass != 0)
		    ચાલુ;
                rel->r_info = ELFW(R_INFO)(sym_index, R_X86_64_PC32);
                ચાલુ;
            }
#endif
            reloc_type = code_reloc(type);
            જો (reloc_type == -1) {
                tcc_error_noabort ("Unknown relocation type: %d", type);
                ચાલુ;
            }

            જો (reloc_type != 0) {
        jmp_slot:
	        જો (pass != 0)
                    ચાલુ;
                reloc_type = R_JMP_SLOT;
            } નહીંતર {
	        જો (pass != 1)
                    ચાલુ;
                reloc_type = R_GLOB_DAT;
            }

            જો (!s1->got)
                got_sym = build_got(s1);

            જો (gotplt_entry == BUILD_GOT_ONLY)
                ચાલુ;

            attr = put_got_entry(s1, reloc_type, sym_index);

            જો (reloc_type == R_JMP_SLOT)
                rel->r_info = ELFW(R_INFO)(attr->plt_sym, type);
        }
    }
    જો (++pass < 2)
        જાઓ redo;
    /* .rel.plt refers to .got actually */
    જો (s1->plt && s1->plt->reloc)
        s1->plt->reloc->sh_info = s1->got->sh_અંક;
    જો (got_sym) /* set size */
        ((ElfW(Sym)*)symtab_section->data)[got_sym].st_size = s1->got->data_offset;
}
#endif /* def NEED_BUILD_GOT */

ST_FUNC પૂર્ણાંક set_global_sym(TCCState *s1, અચલ અક્ષર *name, Section *sec, addr_t offs)
{
    પૂર્ણાંક shn = sec ? sec->sh_અંક : offs || !name ? SHN_ABS : SHN_UNDEF;
    જો (sec && offs == -1)
        offs = sec->data_offset;
    પાછા set_elf_sym(symtab_section, offs, 0,
        ELFW(ST_INFO)(name ? STB_GLOBAL : STB_LOCAL, STT_NOTYPE), 0, shn, name);
}

સ્થિર શૂન્ય add_init_array_defines(TCCState *s1, અચલ અક્ષર *section_name)
{
    Section *s;
    addr_t end_offset;
    અક્ષર buf[1024];
    s = have_section(s1, section_name);
    જો (!s || !(s->sh_flags & SHF_ALLOC)) {
        end_offset = 0;
        s = text_section;
    } નહીંતર {
        end_offset = s->data_offset;
    }
    snprintf(buf, કદ(buf), "__%s_start", section_name + 1);
    set_global_sym(s1, buf, s, 0);
    snprintf(buf, કદ(buf), "__%s_end", section_name + 1);
    set_global_sym(s1, buf, s, end_offset);
}

ST_FUNC શૂન્ય add_array (TCCState *s1, અચલ અક્ષર *sec, પૂર્ણાંક c)
{
    Section *s;
    s = find_section(s1, sec);
    s->sh_flags = shf_RELRO;
    s->sh_type = sec[1] == 'i' ? SHT_INIT_ARRAY : SHT_FINI_ARRAY;
    put_elf_reloc (s1->symtab, s, s->data_offset, R_DATA_PTR, c);
    section_ptr_add(s, PTR_SIZE);
}

#ifdef CONFIG_TCC_BCHECK
ST_FUNC શૂન્ય tcc_add_bcheck(TCCState *s1)
{
    જો (0 == s1->do_bounds_check)
        પાછા;
    section_ptr_add(bounds_section, કદ(addr_t));
}
#endif

/* set symbol to STB_LOCAL and resolve. The point is to not export it as
   a dynamic symbol to allow so's to have one each with a different value. */
સ્થિર શૂન્ય set_local_sym(TCCState *s1, અચલ અક્ષર *name, Section *s, પૂર્ણાંક offset)
{
    પૂર્ણાંક c = find_elf_sym(s1->symtab, name);
    જો (c) {
        ElfW(Sym) *esym = (ElfW(Sym)*)s1->symtab->data + c;
        esym->st_info = ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE);
        esym->st_કિંમત = offset;
        esym->st_shndx = s->sh_અંક;
    }
}

/* avoid generating debug/test_coverage code for stub functions */
સ્થિર શૂન્ય tcc_compile_string_no_debug(TCCState *s, અચલ અક્ષર *str)
{
    પૂર્ણાંક save_do_debug = s->do_debug;
    પૂર્ણાંક save_test_coverage = s->test_coverage;

    s->do_debug = 0;
    s->test_coverage = 0;
    tcc_compile_string(s, str);
    s->do_debug = save_do_debug;
    s->test_coverage = save_test_coverage;
}

#ifdef CONFIG_TCC_BACKTRACE
સ્થિર શૂન્ય put_ptr(TCCState *s1, Section *s, પૂર્ણાંક offs)
{
    પૂર્ણાંક c;
    c = set_global_sym(s1, ખાલી, s, offs);
    s = data_section;
    put_elf_reloc (s1->symtab, s, s->data_offset, R_DATA_PTR, c);
    section_ptr_add(s, PTR_SIZE);
}

ST_FUNC શૂન્ય tcc_add_btstub(TCCState *s1)
{
    Section *s;
    પૂર્ણાંક n, o, *p;
    CString cstr;
    અચલ અક્ષર *__rt_info = &"___rt_info"[!s1->leading_underscore];

    s = data_section;
    /* Align to PTR_SIZE */
    section_add(s, 0, PTR_SIZE);
    o = s->data_offset;
    /* create a struct rt_context (see tccrun.c) */
    જો (s1->dwarf) {
        put_ptr(s1, dwarf_લીટી_section, 0);
        put_ptr(s1, dwarf_લીટી_section, -1);
	જો (s1->dwarf >= 5)
            put_ptr(s1, dwarf_લીટી_str_section, 0);
	નહીંતર
            put_ptr(s1, dwarf_str_section, 0);
    }
    નહીંતર
    {
        put_ptr(s1, stab_section, 0);
        put_ptr(s1, stab_section, -1);
        put_ptr(s1, stab_section->link, 0);
    }

    /* skip esym_start/esym_end/elf_str (not loaded) */
    section_ptr_add(s, 3 * PTR_SIZE);

    જો (s1->output_type == TCC_OUTPUT_MEMORY && 0 == s1->dwarf) {
        put_ptr(s1, text_section, 0);
    } નહીંતર {
        /* prog_base : local nameless symbol with offset 0 at SHN_ABS */
        put_ptr(s1, ખાલી, 0);
#જો defined TCC_TARGET_MACHO
        /* adjust for __PAGEZERO */
        જો (s1->dwarf == 0 && s1->output_type == TCC_OUTPUT_EXE)
            write64le(data_section->data + data_section->data_offset - PTR_SIZE,
	              (uint64_t)1 << 32);
#endif
    }
    n = 3 * PTR_SIZE;
#ifdef CONFIG_TCC_BCHECK
    જો (s1->do_bounds_check) {
        put_ptr(s1, bounds_section, 0);
        n -= PTR_SIZE;
    }
#endif
    section_ptr_add(s, n);
    p = section_ptr_add(s, 2 * કદ (પૂર્ણાંક));
    p[0] = s1->rt_અંક_callers;
    p[1] = s1->dwarf;
    // if (s->data_offset - o != 10*PTR_SIZE + 2*sizeof (int)) exit(99);

    જો (s1->output_type == TCC_OUTPUT_MEMORY) {
        set_global_sym(s1, __rt_info, s, o);
        પાછા;
    }

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern void __bt_init(),__bt_exit(),__bt_init_dll();"
        "static void *__rt_info[];"
        "__attribute__((constructor)) static void __bt_init_rt(){");
#ifdef TCC_TARGET_PE
    જો (s1->output_type == TCC_OUTPUT_DLL)
#ifdef CONFIG_TCC_BCHECK
        cstr_printf(&cstr, "__bt_init_dll(%d);", s1->do_bounds_check);
#નહીંતર
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

સ્થિર શૂન્ય tcc_tcov_add_file(TCCState *s1, અચલ અક્ષર *filename)
{
    CString cstr;
    શૂન્ય *ptr;
    અક્ષર wd[1024];

    જો (tcov_section == ખાલી)
        પાછા;
    section_ptr_add(tcov_section, 1);
    write32le (tcov_section->data, tcov_section->data_offset);

    cstr_new (&cstr);
    જો (filename[0] == '/')
        cstr_printf (&cstr, "%s.tcov", filename);
    નહીંતર {
        getcwd (wd, કદ(wd));
        cstr_printf (&cstr, "%s/%s.tcov", wd, filename);
    }
    ptr = section_ptr_add(tcov_section, cstr.size + 1);
    strcpy((અક્ષર *)ptr, cstr.data);
    unlink((અક્ષર *)ptr);
#ifdef _WIN32
    normalize_slashes((અક્ષર *)ptr);
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
ST_FUNC શૂન્ય tccelf_add_crtbegin(TCCState *s1)
{
#જો TARGETOS_OpenBSD
    જો (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crt0.o");
    જો (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbeginS.o");
    નહીંતર
        tcc_add_crt(s1, "crtbegin.o");
#અથવાજો TARGETOS_FreeBSD || TARGETOS_NetBSD
    જો (s1->output_type != TCC_OUTPUT_DLL)
#જો TARGETOS_FreeBSD
        tcc_add_crt(s1, "crt1.o");
#નહીંતર
        tcc_add_crt(s1, "crt0.o");
#endif
    tcc_add_crt(s1, "crti.o");
    જો (s1->static_link)
        tcc_add_crt(s1, "crtbeginT.o");
    નહીંતર જો (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbeginS.o");
    નહીંતર
        tcc_add_crt(s1, "crtbegin.o");
#અથવાજો TARGETOS_ANDROID
    જો (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtbegin_so.o");
    નહીંતર
        tcc_add_crt(s1, "crtbegin_dynamic.o");
#નહીંતર
    જો (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crt1.o");
    tcc_add_crt(s1, "crti.o");
#endif
}

ST_FUNC શૂન્ય tccelf_add_crtend(TCCState *s1)
{
#જો TARGETOS_OpenBSD
    જો (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtendS.o");
    નહીંતર
        tcc_add_crt(s1, "crtend.o");
#અથવાજો TARGETOS_FreeBSD || TARGETOS_NetBSD
    જો (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtendS.o");
    નહીંતર
        tcc_add_crt(s1, "crtend.o");
    tcc_add_crt(s1, "crtn.o");
#અથવાજો TARGETOS_ANDROID
    જો (s1->output_type == TCC_OUTPUT_DLL)
        tcc_add_crt(s1, "crtend_so.o");
    નહીંતર
        tcc_add_crt(s1, "crtend_android.o");
#નહીંતર
    tcc_add_crt(s1, "crtn.o");
#endif
}
#endif /* TCC_TARGET_UNIX */

#ifndef TCC_TARGET_PE
/* add tcc runtime libraries */
ST_FUNC શૂન્ય tcc_add_runtime(TCCState *s1)
{
    s1->filetype = 0;

#ifdef CONFIG_TCC_BCHECK
    tcc_add_bcheck(s1);
#endif
    tcc_add_pragma_libs(s1);

    /* add libc */
    જો (!s1->nostdlib) {
        પૂર્ણાંક lpthread = s1->option_pthread;

#ifdef CONFIG_TCC_BCHECK
        જો (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    જો (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    નહીંતર
                tcc_add_support(s1, "bcheck.o");
# જો !(TARGETOS_OpenBSD || TARGETOS_NetBSD)
            tcc_add_library(s1, "dl");
# endif
            lpthread = 1;
        }
#endif
#ifdef CONFIG_TCC_BACKTRACE
        જો (s1->do_backtrace) {
            જો (s1->output_type & TCC_OUTPUT_EXE)
                tcc_add_support(s1, "bt-exe.o");
            જો (s1->output_type != TCC_OUTPUT_DLL)
                tcc_add_support(s1, "bt-log.o");
            tcc_add_btstub(s1);
            lpthread = 1;
        }
#endif
        જો (lpthread)
            tcc_add_library(s1, "pthread");
        tcc_add_library(s1, "c");
#ifdef TCC_LIBGCC
        જો (!s1->static_link) {
            જો (TCC_LIBGCC[0] == '/')
                tcc_add_file(s1, TCC_LIBGCC);
            નહીંતર
                tcc_add_dll(s1, TCC_LIBGCC, AFF_PRINT_ERROR);
        }
#endif
#જો defined TCC_TARGET_ARM && TARGETOS_FreeBSD
        tcc_add_library(s1, "gcc_s"); // unwind code
#endif
        જો (TCC_LIBTCC1[0]) {
            tcc_add_support(s1, TCC_LIBTCC1);
            tcc_add_library(s1, "c");
        }
#ifndef TCC_TARGET_MACHO
        જો (s1->output_type != TCC_OUTPUT_MEMORY)
            tccelf_add_crtend(s1);
#endif
    }
}
#endif /* ndef TCC_TARGET_PE */

/* set _etext/_edata/_end  f=0:set  f=1:when_needed  f=2,3:just_update */
સ્થિર શૂન્ય set_linker_sym(TCCState *s1, અચલ અક્ષર *name, Section *sec, પૂર્ણાંક f)
{
    પૂર્ણાંક sym_index, esym_index, defined;
    ElfW(Sym) *sym, *esym;
    sym_index = find_elf_sym(symtab_section, name);
    sym = (ElfW(Sym) *)symtab_section->data + sym_index;
    esym_index = find_elf_sym(s1->dynsymtab_section, name);
    esym = (ElfW(Sym) *)s1->dynsymtab_section->data + esym_index;
    defined = sym->st_shndx != SHN_UNDEF
        || (esym->st_shndx != SHN_UNDEF && esym->st_size);
    પસંદગી (f) {
    સ્થિતિ 1: /* old symbols w/o '_' */
        જો (!(sym_index || esym_index) || defined)
            તોડો;
    સ્થિતિ 0:
        જો (defined) {
            tcc_warning("linker symbol '%s' already defined", name);
            તોડો;
        }
        sym_index = set_global_sym(s1, name, sec, -1);
        get_sym_attr(s1, sym_index, 1)->linker_sym = 1;
        તોડો;
    મૂળભૂત: /* update (bss only) */
        જો (get_sym_attr(s1, sym_index, 0)->linker_sym)
            sym->st_કિંમત = sec->data_offset;
    }
#ifndef ELF_OBJ_ONLY
    જો (name[0] == '_')
        set_linker_sym(s1, name + 1, sec, f + 1);
#endif
}

/* add various standard linker symbols (must be done after the
   sections are filled (for example after allocating common
   symbols)) */
સ્થિર શૂન્ય tcc_add_linker_symbols(TCCState *s1)
{
    અક્ષર buf[1024];
    પૂર્ણાંક i;
    Section *s;

    set_linker_sym(s1, "_etext", text_section, 0);
    set_linker_sym(s1, "_edata", data_section, 0);
    set_linker_sym(s1, "_end", bss_section, 0);
#જો TARGETOS_OpenBSD
    set_global_sym(s1, "__executable_start", ખાલી, ELF_START_ADDR);
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
    માટે(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        જો ((s->sh_flags & SHF_ALLOC)
            && (s->sh_type == SHT_PROGBITS || s->sh_type == SHT_NOBITS
                || s->sh_type == SHT_STRTAB)) {
            /* check if section name can be expressed in C */
            અચલ અક્ષર *p0, *p;
            p0 = s->name;
            જો (*p0 == '.')
                ++p0;
            p = p0;
            માટે(;;) {
                પૂર્ણાંક c = *p;
                જો (!c)
                    તોડો;
                જો (!isid(c) && !isnum(c))
                    જાઓ next_sec;
                p++;
            }
            snprintf(buf, કદ(buf), "__start_%s", p0);
            set_global_sym(s1, buf, s, 0);
            snprintf(buf, કદ(buf), "__stop_%s", p0);
            set_global_sym(s1, buf, s, -1);
        }
    next_sec: ;
    }
}

ST_FUNC શૂન્ય resolve_common_syms(TCCState *s1)
{
    ElfW(Sym) *sym;

    /* Allocate common symbols in BSS.  */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        જો (sym->st_shndx == SHN_COMMON && sym->st_size) {
            /* symbol alignment is in st_value for SHN_COMMONs */
	    sym->st_કિંમત = section_add(bss_section, sym->st_size,
					sym->st_કિંમત);
            sym->st_shndx = bss_section->sh_અંક;
        }
    }

    /* Now assign linker provided symbols their value.  */
    જો (s1->output_type != TCC_OUTPUT_DLL)
        tcc_add_linker_symbols(s1);
}

#ifndef ELF_OBJ_ONLY
ST_FUNC શૂન્ય fill_got_entry(TCCState *s1, ElfW_Rel *rel)
{
    પૂર્ણાંક sym_index = ELFW(R_SYM) (rel->r_info);
    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->data)[sym_index];
    સંરચના sym_attr *attr = get_sym_attr(s1, sym_index, 0);
    unsigned offset = attr->got_offset;

    જો (0 == offset)
        પાછા;
    section_reserve(s1->got, offset + PTR_SIZE);
#જો PTR_SIZE == 8
    write64le(s1->got->data + offset, sym->st_કિંમત);
#નહીંતર
    write32le(s1->got->data + offset, sym->st_કિંમત);
#endif
}

/* Perform relocation to GOT or PLT entries */
ST_FUNC શૂન્ય fill_got(TCCState *s1)
{
    Section *s;
    ElfW_Rel *rel;
    પૂર્ણાંક i;

    માટે(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        જો (s->sh_type != SHT_RELX)
            ચાલુ;
        /* no need to handle got relocations */
        જો (s->link != symtab_section)
            ચાલુ;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            પસંદગી (ELFW(R_TYPE) (rel->r_info)) {
                સ્થિતિ R_X86_64_GOT32:
                સ્થિતિ R_X86_64_GOTPCREL:
		સ્થિતિ R_X86_64_GOTPCRELX:
		સ્થિતિ R_X86_64_REX_GOTPCRELX:
                સ્થિતિ R_X86_64_PLT32:
                    fill_got_entry(s1, rel);
                    તોડો;
            }
        }
    }
}

/* See put_got_entry for a description.  This is the second stage
   where GOT references to local defined symbols are rewritten.  */
સ્થિર શૂન્ય fill_local_got_entries(TCCState *s1)
{
    ElfW_Rel *rel;
    જો (!s1->got->reloc)
        પાછા;
    for_each_elem(s1->got->reloc, 0, rel, ElfW_Rel) {
	જો (ELFW(R_TYPE)(rel->r_info) == R_RELATIVE) {
	    પૂર્ણાંક sym_index = ELFW(R_SYM) (rel->r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->data)[sym_index];
	    સંરચના sym_attr *attr = get_sym_attr(s1, sym_index, 0);
	    unsigned offset = attr->got_offset;
	    જો (offset != rel->r_offset - s1->got->sh_addr)
	        tcc_error_noabort("fill_local_got_entries: huh?");
	    rel->r_info = ELFW(R_INFO)(0, R_RELATIVE);
#જો SHT_RELX == SHT_RELA
	    rel->r_addend = sym->st_કિંમત;
#નહીંતર
	    /* All our REL architectures also happen to be 32bit LE.  */
	    write32le(s1->got->data + offset, sym->st_કિંમત);
#endif
	}
    }
}

/* Bind symbols of executable: resolve undefined symbols from exported symbols
   in shared libraries */
સ્થિર શૂન્ય bind_exe_dynsyms(TCCState *s1, પૂર્ણાંક is_PIE)
{
    અચલ અક્ષર *name;
    પૂર્ણાંક sym_index, index;
    ElfW(Sym) *sym, *esym;
    પૂર્ણાંક type;

    /* Resolve undefined symbols from dynamic symbols. When there is a match:
       - if STT_FUNC or STT_GNU_IFUNC symbol -> add it in PLT
       - if STT_OBJECT symbol -> add it in .bss section with suitable reloc */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        જો (sym->st_shndx == SHN_UNDEF
            /* bss symbols may be initialized in the shared library */
            || sym->st_shndx == SHN_COMMON
            || sym->st_shndx == bss_section->sh_અંક) {
            name = (અક્ષર *) symtab_section->link->data + sym->st_name;
            sym_index = find_elf_sym(s1->dynsymtab_section, name);
            esym = &((ElfW(Sym) *)s1->dynsymtab_section->data)[sym_index];
            જો (sym_index && esym->st_shndx != SHN_UNDEF) {
                જો (is_PIE)
                    ચાલુ;
                type = ELFW(ST_TYPE)(esym->st_info);
                જો ((type == STT_FUNC) || (type == STT_GNU_IFUNC)) {
                    /* Indirect functions shall have STT_FUNC type in executable
                     * dynsym section. Indeed, a dlsym call following a lazy
                     * resolution would pick the symbol value from the
                     * executable dynsym entry which would contain the address
                     * of the function wanted by the caller of dlsym instead of
                     * the address of the function that would return that
                     * address */
                    પૂર્ણાંક dynindex
		      = put_elf_sym(s1->dynsym, 0, esym->st_size,
				    ELFW(ST_INFO)(STB_GLOBAL,STT_FUNC), 0, 0,
				    name);
		    પૂર્ણાંક index = sym - (ElfW(Sym) *) symtab_section->data;
		    get_sym_attr(s1, index, 1)->dyn_index = dynindex;
                } નહીંતર જો (type == STT_OBJECT) {
                    unsigned long offset;
                    ElfW(Sym) *dynsym;
                    જો (sym->st_shndx == bss_section->sh_અંક) {
                        offset = sym->st_કિંમત;
                    } નહીંતર {
                        offset = bss_section->data_offset;
                        /* XXX: which alignment ? */
                        offset = (offset + 16 - 1) & -16;
                        bss_section->data_offset = offset + esym->st_size;
                    }
                    set_elf_sym (s1->symtab, offset, esym->st_size,
                                 esym->st_info, 0, bss_section->sh_અંક, name);
                    index = put_elf_sym(s1->dynsym, offset, esym->st_size,
                                        esym->st_info, 0, bss_section->sh_અંક,
                                        name);
                    /* Ensure R_COPY works for weak symbol aliases */
                    જો (ELFW(ST_BIND)(esym->st_info) == STB_WEAK) {
                        for_each_elem(s1->dynsymtab_section, 1, dynsym, ElfW(Sym)) {
                            જો ((dynsym->st_કિંમત == esym->st_કિંમત)
                                && (ELFW(ST_BIND)(dynsym->st_info) == STB_GLOBAL)) {
                                અક્ષર *dynname = (અક્ષર *) s1->dynsymtab_section->link->data
                                                + dynsym->st_name;
                                put_elf_sym(s1->dynsym, offset, dynsym->st_size,
                                            dynsym->st_info, 0,
                                            bss_section->sh_અંક, dynname);
                                તોડો;
                            }
                        }
                    }
                    put_elf_reloc(s1->dynsym, bss_section,
                                  offset, R_COPY, index);
                }
            } નહીંતર જો (sym->st_shndx == SHN_UNDEF) {
                /* STB_WEAK undefined symbols are accepted */
                /* XXX: _fp_hw seems to be part of the ABI, so we ignore it */
                જો (ELFW(ST_BIND)(sym->st_info) == STB_WEAK ||
                    !strcmp(name, "_fp_hw")) {
                } નહીંતર {
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
સ્થિર શૂન્ય bind_libs_dynsyms(TCCState *s1)
{
    અચલ અક્ષર *name;
    પૂર્ણાંક dynsym_index;
    ElfW(Sym) *sym, *esym;

    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        name = (અક્ષર *)symtab_section->link->data + sym->st_name;
        dynsym_index = find_elf_sym(s1->dynsymtab_section, name);
        જો (sym->st_shndx != SHN_UNDEF) {
            જો (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL
                && (dynsym_index || s1->rdynamic))
                set_elf_sym(s1->dynsym, sym->st_કિંમત, sym->st_size,
                            sym->st_info, 0, sym->st_shndx, name);
        } નહીંતર જો (dynsym_index) {
            esym = (ElfW(Sym) *)s1->dynsymtab_section->data + dynsym_index;
            જો (esym->st_shndx == SHN_UNDEF) {
                /* weak symbols can stay undefined */
                જો (ELFW(ST_BIND)(esym->st_info) != STB_WEAK)
                    tcc_warning("unresolved dynamic reference to '%s'", name);
            }
        }
    }
}

/* Export all non local symbols. This is used by shared libraries so that the
   non local symbols they define can resolve a reference in another shared
   library or in the executable. Correspondingly, it allows undefined local
   symbols to be resolved by other shared libraries or by the executable. */
સ્થિર શૂન્ય export_global_syms(TCCState *s1)
{
    પૂર્ણાંક dynindex, index;
    અચલ અક્ષર *name;
    ElfW(Sym) *sym;
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        જો (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
	    name = (અક્ષર *) symtab_section->link->data + sym->st_name;
	    dynindex = set_elf_sym(s1->dynsym, sym->st_કિંમત, sym->st_size,
				   sym->st_info, 0, sym->st_shndx, name);
	    index = sym - (ElfW(Sym) *) symtab_section->data;
            get_sym_attr(s1, index, 1)->dyn_index = dynindex;
        }
    }
}

/* decide if an unallocated section should be output. */
સ્થિર પૂર્ણાંક set_sec_sizes(TCCState *s1)
{
    પૂર્ણાંક i;
    Section *s;
    પૂર્ણાંક textrel = 0;
    પૂર્ણાંક file_type = s1->output_type;

    /* Allocate strings for section names */
    માટે(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        જો (s->sh_type == SHT_RELX && !(s->sh_flags & SHF_ALLOC)) {
            /* when generating a DLL, we include relocations but
               we may patch them */
            જો ((file_type & TCC_OUTPUT_DYN)
                && (s1->sections[s->sh_info]->sh_flags & SHF_ALLOC)) {
                પૂર્ણાંક ગણતરી_2 = prepare_dynamic_rel(s1, s);
                જો (ગણતરી_2) {
                    /* allocate the section */
                    s->sh_flags |= SHF_ALLOC;
                    s->sh_size = ગણતરી_2 * કદ(ElfW_Rel);
                    જો (s1->sections[s->sh_info]->sh_flags & SHF_EXECINSTR)
                        textrel += ગણતરી_2;
                }
            }
        } નહીંતર જો ((s->sh_flags & SHF_ALLOC)
#ifdef TCC_TARGET_ARM
                   || s->sh_type == SHT_ARM_ATTRIBUTES
#endif
                   || s1->do_debug) {
            s->sh_size = s->data_offset;
        }
    }
    પાછા textrel;
}

/* various data used under elf_output_file() */
સંરચના dyn_inf {
    Section *dynamic;
    Section *dynstr;
    Section *interp;
    Section *note;
    Section *gnu_hash;
    સંરચના {
        /* Info to be copied in dynamic section */
        unsigned long data_offset;
        addr_t rel_addr;
        addr_t rel_size;
    };

    ElfW(Phdr) *phdr;
    પૂર્ણાંક phnum;
    પૂર્ણાંક shnum;
    પૂર્ણાંક tls;
    પૂર્ણાંક relro;
    પૂર્ણાંક notes;
    પૂર્ણાંક ehfr;
    પૂર્ણાંક dyna;
};

/* Decide the layout of sections loaded in memory. This must be done before
   program headers are filled since they contain info about the layout.
   We do the following ordering: interp, symbol tables, relocations, progbits,
   nobits */
સ્થિર પૂર્ણાંક sort_sections(TCCState *s1, પૂર્ણાંક *sec_order, સંરચના dyn_inf *d)
{
    Section *s;
    પૂર્ણાંક i, j, k, f, f0, n;
    પૂર્ણાંક nb_sections = s1->nb_sections;
    પૂર્ણાંક *sec_cls = sec_order + nb_sections;
    પૂર્ણાંક tls_align = 0; /* need common alignment for all tls sections */

    માટે (i = 1; i < nb_sections; i++) {
        s = s1->sections[i];
        જો (0 == s->sh_name) {
            j = 0x900; /* no sh_name: won't go to file */
        } નહીંતર જો (s->sh_flags & SHF_ALLOC) {
            j = 0x100;
            જો ((s->sh_flags & (SHF_WRITE|SHF_TLS)) == SHF_WRITE)
                j = 0x200;
        } નહીંતર {
            j = 0x700;
        }
        જો (j >= 0x700 && s1->output_format != TCC_OUTPUT_FORMAT_ELF)
            s->sh_size = 0, j = 0x900;

        જો (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM) {
            k = 0x10;
        } નહીંતર જો (s->sh_type == SHT_STRTAB && strcmp(s->name, ".stabstr")) {
            k = 0x11;
            જો (i == nb_sections - 1) /* ".shstrtab" assumed to stay last */
                k = 0xff;
        } નહીંતર જો (s->sh_type == SHT_HASH || s->sh_type == SHT_GNU_HASH) {
            k = 0x12;
        } નહીંતર જો (s->sh_type == SHT_GNU_verdef
                  || s->sh_type == SHT_GNU_verneed
                  || s->sh_type == SHT_GNU_versym) {
            k = 0x13;
        } નહીંતર જો (s->sh_type == SHT_RELX) {
            k = 0x20;
            જો (s1->plt && s == s1->plt->reloc)
                k = 0x21;
        } નહીંતર જો (s->sh_flags & SHF_EXECINSTR) {
            k = 0x60;
        /* RELRO sections --> */
        } નહીંતર જો (s->sh_flags & SHF_TLS) {
            જો (s->sh_addralign > tls_align)
                tls_align = s->sh_addralign;
            k = 0x40 + (s->sh_type == SHT_NOBITS);
        } નહીંતર જો (s->sh_type == SHT_PREINIT_ARRAY) {
            k = 0x42;
        } નહીંતર જો (s->sh_type == SHT_INIT_ARRAY) {
            k = 0x43;
        } નહીંતર જો (s->sh_type == SHT_FINI_ARRAY) {
            k = 0x44;
        } નહીંતર જો (s->sh_type == SHT_DYNAMIC) {
            k = 0x48;
        } નહીંતર જો (s == s1->got) {
            k = 0x49; /* .got as RELRO needs BIND_NOW in DT_FLAGS */
        } નહીંતર જો (s->reloc && (s->reloc->sh_flags & SHF_ALLOC) && j == 0x100) {
            k = 0x45; /* +1 for data.ro */
        /* <-- */
        } નહીંતર જો (s->sh_type == SHT_NOTE) {
            k = 0x08, d->notes = 1;
        } નહીંતર જો (s->sh_type == SHT_NOBITS) {
            k = 0x70; /* bss */
        } નહીંતર જો (s == d->interp) {
            k = 0x00;
        } નહીંતર {
            k = 0x50; /* data */
        }
        k += j;
        /* make our standard sections come last to have _etext/_edata correct values */
        જો (s->sh_અંક <= bss_section->sh_અંક)
            ++k;
        /* make RELRO section writable */
        જો ((k & 0xfff0) == 0x140)
            k += 0x100, s->sh_flags |= SHF_WRITE;
        /* sort by insert */
        માટે (n = i; n > 1 && k < (f = sec_cls[n - 1]); --n)
            sec_cls[n] = f, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
    }
    sec_order[0] = 0;
    d->shnum = 1;

#define SHFX_NEWPH (1 << 4)
#define SHFX_RELRO (1 << 5)

    /* count PT_LOAD headers needed */
    n = f0 = 0;
    માટે (i = 1; i < nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        k = sec_cls[i];
        f = 0;
        જો (k < 0x900)
            ++d->shnum;
        જો (k < 0x700) {
            f = s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR);
#જો TARGETOS_NetBSD || TARGETOS_FreeBSD
	    /* NetBSD only supports 2 PT_LOAD sections.
	       See: https://blog.netbsd.org/tnf/entry/the_first_report_on_lld */
	    જો ((f & SHF_WRITE) == 0)
                f |= SHF_EXECINSTR;
            k = 0; /* no relro */
#endif
            જો ((k & 0xfff0) == 0x240) /* RELRO sections */
                d->relro = 1, f |= SHFX_RELRO;
            /* start new header when flags changed, but avoid zero memsz */
            જો (f != f0 && s->sh_size)
                f0 = f, ++n, f |= SHFX_NEWPH;
            જો ((s->sh_flags & SHF_TLS) && s->sh_size) {
                s->sh_addralign = tls_align;
                d->tls = 1, f |= SHF_TLS;
            }
        }
        sec_cls[i] = f;
        //printf("ph %d sec %02d : %3X %3X  %8.2X  %04X  %s\n", (f>0) * n, i, f, k, s->sh_type, (int)s->sh_size, s->name);
    }
    પાછા n;
}

સ્થિર ElfW(Phdr) *fill_phdr(ElfW(Phdr) *ph, પૂર્ણાંક type, Section *s)
{
    ph->p_type = type;
    ph->p_flags = PF_R;
    જો (s) {
        જો (s->sh_flags & SHF_WRITE)
            ph->p_flags |= PF_W;
        ph->p_offset = s->sh_offset;
        ph->p_vaddr = s->sh_addr;
        ph->p_filesz = s->sh_size;
        ph->p_align = s->sh_addralign;
    }
    ph->p_paddr = ph->p_vaddr;
    ph->p_memsz = ph->p_filesz;
    પાછા ph;
}

સ્થિર ElfW(Phdr) *update_phdr(ElfW(Phdr) *ph, પૂર્ણાંક type, Section *s, addr_t addr, પૂર્ણાંક file_offset)
{
    જો (ph->p_type == 0) {
        fill_phdr(ph, type, s);
    }
    ph->p_filesz = file_offset - ph->p_offset;
    ph->p_memsz = addr - ph->p_vaddr;
    પાછા ph;
}

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
સ્થિર પૂર્ણાંક layout_sections(TCCState *s1, પૂર્ણાંક *sec_order, સંરચના dyn_inf *d)
{
    Section *s;
    addr_t addr, tmp, align, s_align, base;
    ElfW(Phdr) *ph = ખાલી, *ph2;
    પૂર્ણાંક i, f, n, phnum, phfill;
    પૂર્ણાંક file_offset;

    /* compute number of program headers */
    phnum = sort_sections(s1, sec_order, d);
    phfill = 0; /* set to 1 to have dll's with a PT_PHDR */
    જો (d->interp)
        phfill = 2;
    phnum += phfill;
    જો (d->dynamic)
        d->dyna = phnum++;
    જો (d->notes)
        d->notes = phnum++;
    જો (d->tls)
        d->tls = phnum++;
    જો (eh_frame_hdr_section)
        d->ehfr = phnum++;
    જો (d->relro)
        d->relro = phnum++;
    d->phnum = phnum;
    d->phdr = tcc_mallocz(phnum * કદ(ElfW(Phdr)));

    file_offset = 0;
    જો (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
        file_offset = (કદ(ElfW(Ehdr)) + phnum * કદ(ElfW(Phdr)) + 3) & -4;
        file_offset += d->shnum * કદ (ElfW(Shdr));
    }

    s_align = ELF_PAGE_SIZE;
    જો (s1->section_align)
        s_align = s1->section_align;

    addr = ELF_START_ADDR;
    જો (s1->output_type & TCC_OUTPUT_DYN)
        addr = 0;

    જો (s1->has_text_addr) {
        addr = s1->text_addr;
        જો (0) {
            પૂર્ણાંક a_offset, p_offset;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_offset = (પૂર્ણાંક) (addr & (s_align - 1));
            p_offset = file_offset & (s_align - 1);
            જો (a_offset < p_offset)
                a_offset += s_align;
            file_offset += (a_offset - p_offset);
        }
    }
    base = addr;
    /* compute address after headers */
    addr += file_offset;

    n = 0;
    માટે(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        f = sec_order[i + s1->nb_sections];
        align = s->sh_addralign - 1;

        જો (f == 0) { /* no alloc */
            file_offset = (file_offset + align) & ~align;
            s->sh_offset = file_offset;
            જો (s->sh_type != SHT_NOBITS)
                file_offset += s->sh_size;
            ચાલુ;
        }

        જો ((f & SHFX_NEWPH) && n) {
            /* different rwx section flags */
            જો (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
                /* if in the middle of a page, w e duplicate the page in
                   memory so that one copy is RX and the other is RW */
                જો ((addr & (s_align - 1)) != 0)
                    addr += s_align;
            } નહીંતર {
                align = s_align - 1;
            }
        }

        tmp = addr;
        addr = (addr + align) & ~align;
        file_offset += (પૂર્ણાંક)(addr - tmp);
        s->sh_offset = file_offset;
        s->sh_addr = addr;

        //printf("%d : %08x %08x %04x %03x %s %d\n", n, (int)file_offset, (int)addr, (int)s->sh_size, s->sh_type, s->name, align + 1);
        addr += s->sh_size;
        જો (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_size;

        જો (f & SHFX_NEWPH) {
            /* set new program header */
            ph = &d->phdr[phfill + n];
            fill_phdr(ph, PT_LOAD, s);
            ph->p_align = s_align;
            જો (f & SHF_EXECINSTR)
                ph->p_flags |= PF_X;
            જો (n == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_offset = 0;
                ph->p_paddr = ph->p_vaddr = base;
            }
            ++n;
        }

        જો (ph)
            update_phdr(ph, 0, 0, addr, file_offset);

        જો (f & SHFX_RELRO) {
            ph2 = update_phdr(&d->phdr[d->relro], PT_GNU_RELRO, s, addr, file_offset);
            ph2->p_align = 1;
        }
        જો (f & SHF_TLS) {
            ph2 = update_phdr(&d->phdr[d->tls], PT_TLS, s, addr, file_offset);
            જો (s->sh_type == SHT_NOBITS)
                addr -= s->sh_size;
            /* for xxx-link.c:relocate() */
            s1->tls_start = ph2->p_vaddr;
            s1->tls_end = s1->tls_start + ph2->p_memsz + (-ph2->p_memsz & (ph2->p_align - 1));
        }
        જો (s->sh_type == SHT_NOTE) {
            update_phdr(&d->phdr[d->notes], PT_NOTE, s, addr, file_offset);
        }
    }

    /* Fill other headers */
    જો (d->dyna)
        fill_phdr(&d->phdr[d->dyna], PT_DYNAMIC, d->dynamic);
    જો (d->ehfr)
        fill_phdr(&d->phdr[d->ehfr], PT_GNU_EH_FRAME, eh_frame_hdr_section);
    જો (d->interp)
        fill_phdr(&d->phdr[1], PT_INTERP, d->interp);
    જો (phfill) {
        ph = &d->phdr[0];
        ph->p_offset = કદ(ElfW(Ehdr));
        ph->p_vaddr = base + ph->p_offset;
        ph->p_filesz = phnum * કદ(ElfW(Phdr));
        ph->p_align = 4;
        fill_phdr(ph, PT_PHDR, ખાલી);
    }
    પાછા 0;
}

/* put dynamic tag */
સ્થિર શૂન્ય put_dt(Section *dynamic, પૂર્ણાંક dt, addr_t val)
{
    ElfW(Dyn) *dyn;
    dyn = section_ptr_add(dynamic, કદ(ElfW(Dyn)));
    dyn->d_tag = dt;
    dyn->d_un.d_val = val;
}

/* Fill the dynamic section with tags describing the address and size of
   sections */
સ્થિર શૂન્ય fill_dynamic(TCCState *s1, સંરચના dyn_inf *dyninf)
{
    Section *dynamic = dyninf->dynamic;
    Section *s;

    /* put dynamic section entries */
    put_dt(dynamic, DT_HASH, s1->dynsym->hash->sh_addr);
    put_dt(dynamic, DT_GNU_HASH, dyninf->gnu_hash->sh_addr);
    put_dt(dynamic, DT_STRTAB, dyninf->dynstr->sh_addr);
    put_dt(dynamic, DT_SYMTAB, s1->dynsym->sh_addr);
    put_dt(dynamic, DT_STRSZ, dyninf->dynstr->data_offset);
    put_dt(dynamic, DT_SYMENT, કદ(ElfW(Sym)));
#જો PTR_SIZE == 8
    put_dt(dynamic, DT_RELA, dyninf->rel_addr);
    put_dt(dynamic, DT_RELASZ, dyninf->rel_size);
    put_dt(dynamic, DT_RELAENT, કદ(ElfW_Rel));
    જો (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->data_offset);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_RELA);
    }
    put_dt(dynamic, DT_RELACOUNT, 0);
#નહીંતર
    put_dt(dynamic, DT_REL, dyninf->rel_addr);
    put_dt(dynamic, DT_RELSZ, dyninf->rel_size);
    put_dt(dynamic, DT_RELENT, કદ(ElfW_Rel));
    જો (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->data_offset);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_REL);
    }
    put_dt(dynamic, DT_RELCOUNT, 0);
#endif
    જો (versym_section && verneed_section) {
	/* The dynamic linker can not handle VERSYM without VERNEED */
        put_dt(dynamic, DT_VERSYM, versym_section->sh_addr);
        put_dt(dynamic, DT_VERNEED, verneed_section->sh_addr);
        put_dt(dynamic, DT_VERNEEDNUM, dt_verneednum);
    }
    s = have_section(s1, ".preinit_array");
    જો (s && s->data_offset) {
        put_dt(dynamic, DT_PREINIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_PREINIT_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".init_array");
    જો (s && s->data_offset) {
        put_dt(dynamic, DT_INIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_INIT_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".fini_array");
    જો (s && s->data_offset) {
        put_dt(dynamic, DT_FINI_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_FINI_ARRAYSZ, s->data_offset);
    }
    s = have_section(s1, ".init");
    જો (s && s->data_offset) {
        put_dt(dynamic, DT_INIT, s->sh_addr);
    }
    s = have_section(s1, ".fini");
    જો (s && s->data_offset) {
        put_dt(dynamic, DT_FINI, s->sh_addr);
    }
    જો (s1->do_debug)
        put_dt(dynamic, DT_DEBUG, 0);
    put_dt(dynamic, DT_NULL, 0);
}

/* Remove gaps between RELX sections.
   These gaps are a result of final_sections_reloc. Here some relocs are removed.
   The gaps are then filled with 0 in tcc_output_elf. The 0 is intepreted as
   R_...NONE reloc. This does work on most targets but on OpenBSD/arm64 this
   is illegal. OpenBSD/arm64 does not support R_...NONE reloc. */
સ્થિર શૂન્ય update_reloc_sections(TCCState *s1, સંરચના dyn_inf *dyninf)
{
    પૂર્ણાંક i;
    unsigned long file_offset = 0;
    Section *s;
    Section *relocplt = s1->plt ? s1->plt->reloc : ખાલી;

    /* dynamic relocation table information, for .dynamic section */
    dyninf->rel_addr = dyninf->rel_size = 0;

    માટે(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
	જો (s->sh_type == SHT_RELX && s != relocplt) {
	    જો (dyninf->rel_size == 0) {
		dyninf->rel_addr = s->sh_addr;
		file_offset = s->sh_offset;
	    }
	    નહીંતર {
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
સ્થિર પૂર્ણાંક tcc_output_elf(TCCState *s1, FILE *f, પૂર્ણાંક phnum, ElfW(Phdr) *phdr)
{
    પૂર્ણાંક i, shnum, offset, size, file_type;
    Section *s;
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) shdr, *sh;

    file_type = s1->output_type;
    shnum = s1->nb_sections;

    memset(&ehdr, 0, કદ(ehdr));
    જો (phnum > 0) {
        ehdr.e_phentsize = કદ(ElfW(Phdr));
        ehdr.e_phnum = phnum;
        ehdr.e_phoff = કદ(ElfW(Ehdr));
    }

    /* fill header */
    ehdr.e_ident[0] = ELFMAG0;
    ehdr.e_ident[1] = ELFMAG1;
    ehdr.e_ident[2] = ELFMAG2;
    ehdr.e_ident[3] = ELFMAG3;
    ehdr.e_ident[4] = ELFCLASSW;
    ehdr.e_ident[5] = ELFDATA2LSB;
    ehdr.e_ident[6] = EV_CURRENT;

#જો TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    ehdr.e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
#અથવાજો TARGETOS_OpenBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_OPENBSD;
#અથવાજો TARGETOS_NetBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_NETBSD;
#અથવાજો defined TCC_TARGET_ARM && defined TCC_ARM_EABI
    ehdr.e_flags = EF_ARM_EABI_VER5;
    ehdr.e_flags |= s1->float_abi == ARM_HARD_FLOAT
        ? EF_ARM_VFP_FLOAT : EF_ARM_SOFT_FLOAT;
#અથવાજો defined TCC_TARGET_ARM
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#અથવાજો defined TCC_TARGET_RISCV64
    /* XXX should be configurable */
    ehdr.e_flags = EF_RISCV_FLOAT_ABI_DOUBLE;
#endif

    જો (file_type == TCC_OUTPUT_OBJ) {
        ehdr.e_type = ET_REL;
    } નહીંતર {
        જો (file_type & TCC_OUTPUT_DYN)
            ehdr.e_type = ET_DYN;
        નહીંતર
            ehdr.e_type = ET_EXEC;
        જો (s1->elf_entryname)
            ehdr.e_entry = get_sym_addr(s1, s1->elf_entryname, 1, 0);
        નહીંતર
            ehdr.e_entry = get_sym_addr(s1, "_start", !!(file_type & TCC_OUTPUT_EXE), 0);
        જો (ehdr.e_entry == (addr_t)-1)
            ehdr.e_entry = text_section->sh_addr;
        જો (s1->nb_errors)
            પાછા -1;
    }

    sort_syms(s1, s1->symtab);

    ehdr.e_machine = EM_TCC_TARGET;
    ehdr.e_version = EV_CURRENT;
    ehdr.e_shoff = (કદ(ElfW(Ehdr)) + phnum * કદ(ElfW(Phdr)) + 3) & -4;
    ehdr.e_ehsize = કદ(ElfW(Ehdr));
    ehdr.e_shentsize = કદ(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    offset = fwrite(&ehdr, 1, કદ(ElfW(Ehdr)), f);
    જો (phdr)
        offset += fwrite(phdr, 1, phnum * કદ(ElfW(Phdr)), f);

    /* output section headers */
    જ્યારે (offset < ehdr.e_shoff) {
        fputc(0, f);
        offset++;
    }

    માટે(i = 0; i < shnum; i++) {
        sh = &shdr;
        memset(sh, 0, કદ(ElfW(Shdr)));
        જો (i) {
            s = s1->sections[i];
            sh->sh_name = s->sh_name;
            sh->sh_type = s->sh_type;
            sh->sh_flags = s->sh_flags;
            sh->sh_entsize = s->sh_entsize;
            sh->sh_info = s->sh_info;
            જો (s->link)
                sh->sh_link = s->link->sh_અંક;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_offset = s->sh_offset;
            sh->sh_size = s->sh_size;
        }
        offset += fwrite(sh, 1, કદ(ElfW(Shdr)), f);
    }

    /* output sections */
    માટે(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        જો (s->sh_type != SHT_NOBITS) {
            જ્યારે (offset < s->sh_offset) {
                fputc(0, f);
                offset++;
            }
            size = s->sh_size;
            જો (size)
                offset += fwrite(s->data, 1, size, f);
        }
    }
    પાછા 0;
}

સ્થિર પૂર્ણાંક tcc_output_દ્વિઅંકી(TCCState *s1, FILE *f)
{
    Section *s;
    પૂર્ણાંક i, offset, size;

    offset = 0;
    માટે(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[i];
        જો (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            જ્યારે (offset < s->sh_offset) {
                fputc(0, f);
                offset++;
            }
            size = s->sh_size;
            fwrite(s->data, 1, size, f);
            offset += size;
        }
    }
    પાછા 0;
}

/* Write an elf, coff or "binary" file */
સ્થિર પૂર્ણાંક tcc_write_elf_file(TCCState *s1, અચલ અક્ષર *filename, પૂર્ણાંક phnum,
                              ElfW(Phdr) *phdr)
{
    પૂર્ણાંક fd, mode, file_type, ret;
    FILE *f;

    file_type = s1->output_type;
    જો (file_type == TCC_OUTPUT_OBJ)
        mode = 0666;
    નહીંતર
        mode = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_દ્વિઅંકી_2, mode);
    જો (fd < 0 || (f = fdopen(fd, "wb")) == ખાલી)
        પાછા tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
    જો (s1->verbose)
        printf("<- %s\n", filename);
#ifdef TCC_TARGET_COFF
    જો (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    નહીંતર
#endif
    જો (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        ret = tcc_output_elf(s1, f, phnum, phdr);
    નહીંતર
        ret = tcc_output_દ્વિઅંકી(s1, f);
    fclose(f);

    પાછા ret;
}

#ifndef ELF_OBJ_ONLY
/* order sections according to sec_order, remove sections
   that we aren't going to output.  */
સ્થિર શૂન્ય reorder_sections(TCCState *s1, પૂર્ણાંક *sec_order)
{
    પૂર્ણાંક i, nnew, k, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    backmap = tcc_malloc(s1->nb_sections * કદ(backmap[0]));
    માટે (i = 0, nnew = 0, snew = ખાલી; i < s1->nb_sections; i++) {
	k = sec_order ? sec_order[i] : i;
	s = s1->sections[k];
	જો (!i || s->sh_name) {
	    backmap[k] = nnew;
            dynarray_add(&snew, &nnew, s);
	} નહીંતર {
	    backmap[k] = 0;
            /* just remember to free them later */
	    dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, s);
	}
    }
    માટે (i = 1; i < nnew; i++) {
	s = snew[i];
        s->sh_અંક = i;
        જો (s->sh_type == SHT_RELX)
            s->sh_info = backmap[s->sh_info];
        નહીંતર જો (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM)
            for_each_elem(s, 1, sym, ElfW(Sym))
                જો (sym->st_shndx < s1->nb_sections)
                    sym->st_shndx = backmap[sym->st_shndx];
    }
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}

#ifdef TCC_TARGET_ARM
સ્થિર શૂન્ય create_arm_attribute_section(TCCState *s1)
{
   // Needed for DLL support.
    સ્થિર અચલ unsigned અક્ષર arm_attr[] = {
        0x41,                            // 'A'
        0x2c, 0x00, 0x00, 0x00,          // size 0x2c
        'a', 'e', 'a', 'b', 'i', 0x00,   // "aeabi"
        0x01, 0x22, 0x00, 0x00, 0x00,    // 'File Attributes', size 0x22
        0x05, 0x36, 0x00,                // 'CPU_name', "6"
#જો CONFIG_TCC_CPUVER >= 7
        0x06, 0x0a,                      // 'CPU_arch', 'v7'
#નહીંતર
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
    unsigned અક્ષર *ptr = section_ptr_add(attr, કદ(arm_attr));
    attr->sh_addralign = 1;
    memcpy(ptr, arm_attr, કદ(arm_attr));
    જો (s1->float_abi != ARM_HARD_FLOAT) {
        ptr[26] = 0x00; // 'FP_arch', 'No'
        ptr[41] = 0x1e; // 'ABI_optimization_goals'
        ptr[42] = 0x06; // 'Aggressive Debug'
    }
}
#endif

#ifdef TCC_TARGET_RISCV64
સ્થિર શૂન્ય create_riscv_attribute_section(TCCState *s1)
{
    સ્થિર અચલ unsigned અક્ષર riscv_attr[] = {
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
    unsigned અક્ષર *ptr = section_ptr_add(attr, કદ(riscv_attr));
    attr->sh_addralign = 1;
    memcpy(ptr, riscv_attr, કદ(riscv_attr));
}
#endif

#જો TARGETOS_OpenBSD || TARGETOS_NetBSD || TARGETOS_FreeBSD

સ્થિર શૂન્ય fill_bsd_note(Section *s, પૂર્ણાંક type,
			  અચલ અક્ષર *કિંમત, uint32_t data)
{
    unsigned long offset = 0;
    અક્ષર *ptr;
    ElfW(Nhdr) *note;
    પૂર્ણાંક align = s->sh_addralign;

    /* check if type present */
    જ્યારે (offset + કદ(ElfW(Nhdr)) < s->data_offset) {
        note = (ElfW(Nhdr) *) (s->data + offset);
	જો (note->n_type == type)
	    પાછા;
	offset += (કદ(ElfW(Nhdr)) + note->n_namesz + note->n_descsz +
		  align - 1) & -align;
    }
    ptr = section_ptr_add(s, કદ(ElfW(Nhdr)) + 8 + 4);
    note = (ElfW(Nhdr) *) ptr;
    note->n_namesz = 8;
    note->n_descsz = 4;
    note->n_type = type;
    strcpy (ptr + કદ(ElfW(Nhdr)), કિંમત);
    memcpy (ptr + કદ(ElfW(Nhdr)) + 8, &data, 4);
}

સ્થિર Section *create_bsd_note_section(TCCState *s1,
					અચલ અક્ષર *name,
					અચલ અક્ષર *કિંમત)
{
    Section *s;
    unsigned પૂર્ણાંક major = 0, minor = 0, patch = 0;

#ifdef CONFIG_OS_RELEASE
    sscanf(CONFIG_OS_RELEASE, "%u.%u.%u", &major, &minor, &patch);
#endif
#જો TARGETOS_FreeBSD
    જો (major < 14)
	પાછા ખાલી;
#endif
    s = find_section (s1, name);
    s->sh_type = SHT_NOTE;
#જો TARGETOS_OpenBSD
    fill_bsd_note(s, ELF_NOTE_OS_GNU, કિંમત, 0);
#અથવાજો TARGETOS_NetBSD
    fill_bsd_note(s, 1 /* NT_NETBSD_IDENT_TAG */, કિંમત,
		  major * 100000000u + (minor % 100u) * 1000000u +
		  (patch % 10000u) * 100u);
#અથવાજો TARGETOS_FreeBSD
    fill_bsd_note(s, 1 /* NT_FREEBSD_ABI_TAG */, કિંમત,
		  major * 100000u + (minor % 100u) * 1000u);
    fill_bsd_note(s, 4 /* NT_FREEBSD_FEATURE_CTL */, કિંમત, 0);
    fill_bsd_note(s, 2 /* NT_FREEBSD_NOINIT_TAG */, કિંમત, 0);
#endif
    પાછા s;
}
#endif

સ્થિર શૂન્ય alloc_sec_names(TCCState *s1, પૂર્ણાંક is_obj);

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
સ્થિર પૂર્ણાંક elf_output_file(TCCState *s1, અચલ અક્ષર *filename)
{
    પૂર્ણાંક i, ret, file_type, *sec_order;
    સંરચના dyn_inf dyninf = {0};
    Section *interp, *dynstr, *dynamic;
    પૂર્ણાંક textrel, got_sym, dt_flags_1;

    file_type = s1->output_type;
    ret = -1;
    interp = dynstr = dynamic = ખાલી;
    sec_order = ખાલી;

#ifdef TCC_TARGET_ARM
    create_arm_attribute_section (s1);
#endif

#ifdef TCC_TARGET_RISCV64
    create_riscv_attribute_section(s1);
#endif

#જો TARGETOS_OpenBSD
    dyninf.note = create_bsd_note_section (s1, ".note.openbsd.ident", "OpenBSD");
#endif

#જો TARGETOS_NetBSD
    dyninf.note = create_bsd_note_section (s1, ".note.netbsd.ident", "NetBSD");
#endif

#જો TARGETOS_FreeBSD
    dyninf.note = create_bsd_note_section (s1, ".note.tag", "FreeBSD");
#endif

        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_add_runtime(s1);
	resolve_common_syms(s1);

        જો (!s1->static_link) {
            જો (file_type & TCC_OUTPUT_EXE) {
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
            dynamic->sh_entsize = કદ(ElfW(Dyn));

            got_sym = build_got(s1);
            જો (file_type & TCC_OUTPUT_EXE) {
                bind_exe_dynsyms(s1, file_type & TCC_OUTPUT_DYN);
                જો (s1->nb_errors)
                    જાઓ the_end;
            }
            build_got_entries(s1, got_sym);
            જો (file_type & TCC_OUTPUT_EXE) {
                bind_libs_dynsyms(s1);
            } નહીંતર {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
#જો TCC_EH_FRAME
	    /* fill with initial data */
	    tcc_eh_frame_hdr(s1, 0);
#endif
	    dyninf.gnu_hash = create_gnu_hash(s1);
        } નહીંતર {
            build_got_entries(s1, 0);
        }
	version_add (s1);

    textrel = set_sec_sizes(s1);

    જો (!s1->static_link) {
        /* add a list of needed dlls */
        માટે(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            જો (dllref->level == 0)
                put_dt(dynamic, DT_NEEDED, put_elf_str(dynstr, dllref->name));
        }

        જો (s1->rpath)
            put_dt(dynamic, s1->enable_new_dtags ? DT_RUNPATH : DT_RPATH,
                   put_elf_str(dynstr, s1->rpath));

        dt_flags_1 = DF_1_NOW;
        જો (file_type & TCC_OUTPUT_DYN) {
            જો (s1->soname)
                put_dt(dynamic, DT_SONAME, put_elf_str(dynstr, s1->soname));
            /* XXX: currently, since we do not handle PIC code, we
               must relocate the readonly segments */
            જો (textrel)
                put_dt(dynamic, DT_TEXTREL, 0);
            જો (file_type & TCC_OUTPUT_EXE)
                dt_flags_1 = DF_1_NOW | DF_1_PIE;
	    જો (s1->znodelete)
		dt_flags_1 |= DF_1_NODELETE;
        }
        put_dt(dynamic, DT_FLAGS, DF_BIND_NOW);
        put_dt(dynamic, DT_FLAGS_1, dt_flags_1);
        જો (s1->symbolic)
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
    sec_order = tcc_malloc(કદ(પૂર્ણાંક) * 2 * s1->nb_sections);
    /* compute section to program header mapping */
    layout_sections(s1, sec_order, &dyninf);

        જો (dynamic) {
            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->data, dynamic->sh_addr);
            જો (file_type == TCC_OUTPUT_EXE
                || (RELOCATE_DLLPLT && (file_type & TCC_OUTPUT_DYN)))
                relocate_plt(s1);
            /* relocate symbols in .dynsym now that final addresses are known */
            relocate_syms(s1, s1->dynsym, 2);
        }

        /* if building executable or DLL, then relocate each section
           except the GOT which is already relocated */
        relocate_syms(s1, s1->symtab, 0);
        જો (s1->nb_errors != 0)
            જાઓ the_end;
        relocate_sections(s1);
        જો (dynamic) {
	    update_reloc_sections (s1, &dyninf);
            dynamic->data_offset = dyninf.data_offset;
            fill_dynamic(s1, &dyninf);
	}
        /* Perform relocation to GOT or PLT entries */
        જો (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        નહીંતર જો (s1->got)
            fill_local_got_entries(s1);

    જો (dyninf.gnu_hash)
        update_gnu_hash(s1, dyninf.gnu_hash);

    reorder_sections(s1, sec_order);
#જો TCC_EH_FRAME
    /* fill with final data */
    tcc_eh_frame_hdr(s1, 1);
#endif
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, dyninf.phnum, dyninf.phdr);
 the_end:
    tcc_free(sec_order);
    tcc_free(dyninf.phdr);
    પાછા ret;
}
#endif /* ndef ELF_OBJ_ONLY */

/* Allocate strings for section names */
સ્થિર શૂન્ય alloc_sec_names(TCCState *s1, પૂર્ણાંક is_obj)
{
    પૂર્ણાંક i;
    Section *s, *strsec;

    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");
    માટે(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        જો (is_obj)
            s->sh_size = s->data_offset;
	જો (s->sh_size || s == strsec || (s->sh_flags & SHF_ALLOC) || is_obj)
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_size = strsec->data_offset;
}

/* Output an elf .o file */
સ્થિર પૂર્ણાંક elf_output_obj(TCCState *s1, અચલ અક્ષર *filename)
{
    Section *s;
    પૂર્ણાંક i, ret, file_offset;
    /* Allocate strings for section names */
    alloc_sec_names(s1, 1);
    file_offset = (કદ (ElfW(Ehdr)) + 3) & -4;
    file_offset += s1->nb_sections * કદ(ElfW(Shdr));
    માટે(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        file_offset = (file_offset + 15) & -16;
        s->sh_offset = file_offset;
        જો (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_size;
    }
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, 0, ખાલી);
    પાછા ret;
}

LIBTCCAPI પૂર્ણાંક tcc_output_file(TCCState *s, અચલ અક્ષર *filename)
{
    s->nb_errors = 0;
    જો (s->test_coverage)
        tcc_tcov_add_file(s, filename);
    જો (s->output_type == TCC_OUTPUT_OBJ)
        પાછા elf_output_obj(s, filename);
#ifdef TCC_TARGET_PE
    પાછા  pe_output_file(s, filename);
#અથવાજો defined TCC_TARGET_MACHO
    પાછા macho_output_file(s, filename);
#નહીંતર
    પાછા elf_output_file(s, filename);
#endif
}

ST_FUNC ssize_t full_read(પૂર્ણાંક fd, શૂન્ય *buf, size_t ગણતરી_2) {
    અક્ષર *cbuf = buf;
    size_t rnum = 0;
    જ્યારે (1) {
        ssize_t અંક = પઠ(fd, cbuf, ગણતરી_2-rnum);
        જો (અંક < 0) પાછા અંક;
        જો (અંક == 0) પાછા rnum;
        rnum += અંક;
        cbuf += અંક;
    }
}

ST_FUNC શૂન્ય *load_data(પૂર્ણાંક fd, unsigned long file_offset, unsigned long size)
{
    શૂન્ય *data;

    data = tcc_malloc(size);
    lseek(fd, file_offset, SEEK_SET);
    full_read(fd, data, size);
    પાછા data;
}

પ્રકારવ્યાખ્યા સંરચના SectionMergeInfo {
    Section *s;            /* corresponding existing section */
    unsigned long offset;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} SectionMergeInfo;

ST_FUNC પૂર્ણાંક tcc_object_type(પૂર્ણાંક fd, ElfW(Ehdr) *h)
{
    પૂર્ણાંક size = full_read(fd, h, કદ *h);
    જો (size == કદ *h && 0 == memcmp(h, ELFMAG, 4)) {
        જો (h->e_type == ET_REL)
            પાછા AFF_BINTYPE_REL;
        જો (h->e_type == ET_DYN)
            પાછા AFF_BINTYPE_DYN;
    } નહીંતર જો (size >= 8) {
        જો (0 == memcmp(h, ARMAG, 8))
            પાછા AFF_BINTYPE_AR;
#ifdef TCC_TARGET_COFF
        જો (((સંરચના filehdr*)h)->f_magic == COFF_C67_MAGIC)
            પાછા AFF_BINTYPE_C67;
#endif
    }
    પાછા 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC પૂર્ણાંક tcc_load_object_file(TCCState *s1,
                                પૂર્ણાંક fd, unsigned long file_offset)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    unsigned long size, offset, offseti;
    પૂર્ણાંક i, j, nb_syms, sym_index, ret, seencompressed;
    અક્ષર *strsec, *strtab;
    પૂર્ણાંક stab_index, stabstr_index;
    પૂર્ણાંક *old_to_new_syms;
    અક્ષર *sh_name, *name;
    SectionMergeInfo *sm_table, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    lseek(fd, file_offset, SEEK_SET);
    જો (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        જાઓ invalid;
    /* test CPU specific stuff */
    જો (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
invalid:
        પાછા tcc_error_noabort("invalid object file");
    }
    /* read sections */
    shdr = load_data(fd, file_offset + ehdr.e_shoff,
                     કદ(ElfW(Shdr)) * ehdr.e_shnum);
    sm_table = tcc_mallocz(કદ(SectionMergeInfo) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);

    /* load symtab and strtab */
    old_to_new_syms = ખાલી;
    symtab = ખાલી;
    strtab = ખાલી;
    nb_syms = 0;
    seencompressed = 0;
    stab_index = stabstr_index = 0;
    ret = -1;

    માટે(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        જો (sh->sh_type == SHT_SYMTAB) {
            જો (symtab) {
                tcc_error_noabort("object must contain only one symtab");
                જાઓ the_end;
            }
            nb_syms = sh->sh_size / કદ(ElfW(Sym));
            symtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
            sm_table[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
        }
	જો (sh->sh_flags & SHF_COMPRESSED)
	    seencompressed = 1;
    }

    /* now examine each section and try to merge its content with the
       ones in memory */
    માટે(i = 1; i < ehdr.e_shnum; i++) {
        /* no need to examine section name strtab */
        જો (i == ehdr.e_shstrndx)
            ચાલુ;
        sh = &shdr[i];
	જો (sh->sh_type == SHT_RELX)
	  sh = &shdr[sh->sh_info];
        /* ignore sections types we do not handle (plus relocs to those) */
        sh_name = strsec + sh->sh_name;
        જો (0 == strncmp(sh_name, ".debug_", 7)
         || 0 == strncmp(sh_name, ".stab", 5)) {
	    જો (!s1->do_debug || seencompressed)
	        ચાલુ;
#જો !(TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD)
        } નહીંતર જો (0 == strncmp(sh_name, ".eh_frame", 9)) {
            જો (ખાલી == eh_frame_section)
                ચાલુ;
#endif
        } નહીંતર
        જો (sh->sh_type != SHT_PROGBITS &&
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

#જો TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD
            && sh->sh_type != SHT_X86_64_UNWIND
#endif
            )
            ચાલુ;

	sh = &shdr[i];
        sh_name = strsec + sh->sh_name;
        જો (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        /* find corresponding section, if any */
        માટે(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            જો (strcmp(s->name, sh_name))
                ચાલુ;
            જો (sh->sh_type != s->sh_type
                && strcmp (s->name, ".eh_frame")
                /* some crt1.o seem to have two ".note.GNU-stack" (SHT_NOTE & SHT_PROGBITS) */
                && strcmp (s->name, ".note.GNU-stack")
                ) {
                tcc_error_noabort("section type conflict: %s %02x <> %02x", s->name, sh->sh_type, s->sh_type);
                જાઓ the_end;
            }
            જો (!strncmp(sh_name, ".gnu.linkonce", 13)) {
                /* if a 'linkonce' section is already present, we
                   do not add it again. It is a little tricky as
                   symbols can still be defined in
                   it. */
                sm_table[i].link_once = 1;
                જાઓ next;
            }
            જો (stab_section) {
                જો (s == stab_section)
                    stab_index = i;
                જો (s == stab_section->link)
                    stabstr_index = i;
            }
            જાઓ found;
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
        જો (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        sm_table[i].offset = offset;
        sm_table[i].s = s;
        /* concatenate sections */
        જો (sh->sh_type != SHT_NOBITS && size) {
            unsigned અક્ષર *ptr;
            lseek(fd, file_offset + sh->sh_offset, SEEK_SET);
            ptr = s->data + offset;
            full_read(fd, ptr, size);
        }
#જો defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
        /* align code sections to instruction lenght */
        /* This is needed if we compile a c file after this */
        જો (s->sh_flags & SHF_EXECINSTR)
            section_add(s, 0, 4);
#endif
    next: ;
    }

    /* gr relocate stab strings */
    જો (stab_index && stabstr_index) {
        Stab_Sym *a, *b;
        unsigned o;
        s = sm_table[stab_index].s;
        a = (Stab_Sym *)(s->data + sm_table[stab_index].offset);
        b = (Stab_Sym *)(s->data + s->data_offset);
        o = sm_table[stabstr_index].offset;
        જ્યારે (a < b) {
            જો (a->n_strx)
                a->n_strx += o;
            a++;
        }
    }

    /* second short pass to update sh_link and sh_info fields of new
       sections */
    માટે(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        જો (!s || !sm_table[i].new_section)
            ચાલુ;
        sh = &shdr[i];
        જો (sh->sh_link > 0)
            s->link = sm_table[sh->sh_link].s;
        જો (sh->sh_type == SHT_RELX) {
            s->sh_info = sm_table[sh->sh_info].s->sh_અંક;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }

    જો (!symtab)
        જાઓ done;

    /* resolve symbols */
    old_to_new_syms = tcc_mallocz(nb_syms * કદ(પૂર્ણાંક));

    sym = symtab + 1;
    માટે(i = 1; i < nb_syms; i++, sym++) {
        જો (sym->st_shndx != SHN_UNDEF &&
            sym->st_shndx < SHN_LORESERVE) {
            sm = &sm_table[sym->st_shndx];
            જો (sm->link_once) {
                /* if a symbol is in a link once section, we use the
                   already defined symbol. It is very important to get
                   correct relocations */
                જો (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
                    name = strtab + sym->st_name;
                    sym_index = find_elf_sym(symtab_section, name);
                    જો (sym_index)
                        old_to_new_syms[i] = sym_index;
                }
                ચાલુ;
            }
            /* if no corresponding section added, no need to add symbol */
            જો (!sm->s)
                ચાલુ;
            /* convert section number */
            sym->st_shndx = sm->s->sh_અંક;
            /* offset value */
            sym->st_કિંમત += sm->offset;
        }
        /* add symbol */
        name = strtab + sym->st_name;
        sym_index = set_elf_sym(symtab_section, sym->st_કિંમત, sym->st_size,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_to_new_syms[i] = sym_index;
    }

    /* third pass to patch relocation entries */
    માટે(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        જો (!s)
            ચાલુ;
        sh = &shdr[i];
        offset = sm_table[i].offset;
        size = sh->sh_size;
        પસંદગી(s->sh_type) {
        સ્થિતિ SHT_RELX:
            /* take relocation offset information */
            offseti = sm_table[sh->sh_info].offset;
	    માટે (rel = (ElfW_Rel *) s->data + (offset / કદ(*rel));
		 rel < (ElfW_Rel *) s->data + ((offset + size) / કદ(*rel));
		 rel++) {
                પૂર્ણાંક type;
                unsigned sym_index;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_index = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                જો (sym_index >= nb_syms)
                    જાઓ invalid_reloc;
                sym_index = old_to_new_syms[sym_index];
                /* ignore link_once in rel section. */
                જો (!sym_index && !sm_table[sh->sh_info].link_once
#ifdef TCC_TARGET_ARM
                    && type != R_ARM_V4BX
#અથવાજો defined TCC_TARGET_RISCV64
                    && type != R_RISCV_ALIGN
                    && type != R_RISCV_RELAX
#endif
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, (પૂર્ણાંક)rel->r_offset);
                    જાઓ the_end;
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
                જો (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_index, 1)->plt_thumb_stub = 1;
#endif
            }
            તોડો;
        મૂળભૂત:
            તોડો;
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
    પાછા ret;
}

પ્રકારવ્યાખ્યા સંરચના ArchiveHeader {
    અક્ષર ar_name[16];           /* name of this member */
    અક્ષર ar_date[12];           /* file mtime */
    અક્ષર ar_uid[6];             /* owner uid; printed as decimal */
    અક્ષર ar_gid[6];             /* owner gid; printed as decimal */
    અક્ષર ar_mode[8];            /* file mode, printed as octal   */
    અક્ષર ar_size[10];           /* file size, printed as decimal */
    અક્ષર ar_fmag[2];            /* should contain ARFMAG */
} ArchiveHeader;

#define ARFMAG "`\n"

સ્થિર unsigned long long get_be(અચલ uint8_t *b, પૂર્ણાંક n)
{
    unsigned long long ret = 0;
    જ્યારે (n)
        ret = (ret << 8) | *b++, --n;
    પાછા ret;
}

સ્થિર પૂર્ણાંક read_ar_header(પૂર્ણાંક fd, પૂર્ણાંક offset, ArchiveHeader *hdr)
{
    અક્ષર *p, *e;
    પૂર્ણાંક len;
    lseek(fd, offset, SEEK_SET);
    len = full_read(fd, hdr, કદ(ArchiveHeader));
    જો (len != કદ(ArchiveHeader))
        પાછા len ? -1 : 0;
    જો (memcmp(hdr->ar_fmag, ARFMAG, કદ hdr->ar_fmag))
        પાછા -1;
    p = hdr->ar_name;
    માટે (e = p + કદ hdr->ar_name; e > p && e[-1] == ' ';)
        --e;
    *e = '\0';
    hdr->ar_size[કદ hdr->ar_size-1] = 0;
    પાછા len;
}

/* load only the objects which resolve undefined symbols */
સ્થિર પૂર્ણાંક tcc_load_alacarte(TCCState *s1, પૂર્ણાંક fd, પૂર્ણાંક size, પૂર્ણાંક entrysize)
{
    પૂર્ણાંક i, bound, nsyms, sym_index, len, ret = -1;
    unsigned long long off;
    uint8_t *data;
    અચલ અક્ષર *ar_names, *p;
    અચલ uint8_t *ar_index;
    ElfW(Sym) *sym;
    ArchiveHeader hdr;

    data = tcc_malloc(size);
    જો (full_read(fd, data, size) != size)
        જાઓ invalid;
    nsyms = get_be(data, entrysize);
    ar_index = data + entrysize;
    ar_names = (અક્ષર *) ar_index + nsyms * entrysize;

    કરો {
        bound = 0;
        માટે (p = ar_names, i = 0; i < nsyms; i++, p += strlen(p)+1) {
            Section *s = symtab_section;
            sym_index = find_elf_sym(s, p);
            જો (!sym_index)
                ચાલુ;
            sym = &((ElfW(Sym) *)s->data)[sym_index];
            જો(sym->st_shndx != SHN_UNDEF)
                ચાલુ;
            off = get_be(ar_index + i * entrysize, entrysize);
            len = read_ar_header(fd, off, &hdr);
            જો (len <= 0 || memcmp(hdr.ar_fmag, ARFMAG, 2)) {
        invalid:
                tcc_error_noabort("invalid archive");
                જાઓ the_end;
            }
            off += len;
            જો (s1->verbose == 2)
                printf("   -> %s\n", hdr.ar_name);
            જો (tcc_load_object_file(s1, fd, off) < 0)
                જાઓ the_end;
            ++bound;
        }
    } જ્યારે(bound);
    ret = 0;
 the_end:
    tcc_free(data);
    પાછા ret;
}

/* load a '.a' file */
ST_FUNC પૂર્ણાંક tcc_load_archive(TCCState *s1, પૂર્ણાંક fd, પૂર્ણાંક alacarte)
{
    ArchiveHeader hdr;
    /* char magic[8]; */
    પૂર્ણાંક size, len;
    unsigned long file_offset;
    ElfW(Ehdr) ehdr;

    /* skip magic which was already checked */
    /* full_read(fd, magic, sizeof(magic)); */
    file_offset = કદ ARMAG - 1;

    માટે(;;) {
        len = read_ar_header(fd, file_offset, &hdr);
        જો (len == 0)
            પાછા 0;
        જો (len < 0)
            પાછા tcc_error_noabort("invalid archive");
        file_offset += len;
        size = strtol(hdr.ar_size, ખાલી, 0);
        જો (alacarte) {
            /* coff symbol table : we handle it */
            જો (!strcmp(hdr.ar_name, "/"))
                પાછા tcc_load_alacarte(s1, fd, size, 4);
            જો (!strcmp(hdr.ar_name, "/SYM64/"))
                પાછા tcc_load_alacarte(s1, fd, size, 8);
        } નહીંતર જો (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
            જો (s1->verbose == 2)
                printf("   -> %s\n", hdr.ar_name);
            જો (tcc_load_object_file(s1, fd, file_offset) < 0)
                પાછા -1;
        }
        /* align to even */
        file_offset = (file_offset + size + 1) & ~1;
    }
}

#ifndef ELF_OBJ_ONLY
/* Set LV[I] to the global index of sym-version (LIB,VERSION).  Maybe resizes
   LV, maybe create a new entry for (LIB,VERSION).  */
સ્થિર શૂન્ય set_ver_to_ver(TCCState *s1, પૂર્ણાંક *n, પૂર્ણાંક **lv, પૂર્ણાંક i, અક્ષર *lib, અક્ષર *version)
{
    જ્યારે (i >= *n) {
        *lv = tcc_realloc(*lv, (*n + 1) * કદ(**lv));
        (*lv)[(*n)++] = -1;
    }
    જો ((*lv)[i] == -1) {
        પૂર્ણાંક v, prev_same_lib = -1;
        માટે (v = 0; v < nb_sym_versions; v++) {
            જો (strcmp(sym_versions[v].lib, lib))
              ચાલુ;
            prev_same_lib = v;
            જો (!strcmp(sym_versions[v].version, version))
              તોડો;
        }
        જો (v == nb_sym_versions) {
            sym_versions = tcc_realloc (sym_versions,
                                        (v + 1) * કદ(*sym_versions));
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
સ્થિર શૂન્ય
set_sym_version(TCCState *s1, પૂર્ણાંક sym_index, પૂર્ણાંક verndx)
{
    જો (sym_index >= nb_sym_to_version) {
        પૂર્ણાંક newelems = sym_index ? sym_index * 2 : 1;
        sym_to_version = tcc_realloc(sym_to_version,
                                     newelems * કદ(*sym_to_version));
        memset(sym_to_version + nb_sym_to_version, -1,
               (newelems - nb_sym_to_version) * કદ(*sym_to_version));
        nb_sym_to_version = newelems;
    }
    જો (sym_to_version[sym_index] < 0)
      sym_to_version[sym_index] = verndx;
}

સંરચના versym_info {
    પૂર્ણાંક nb_versyms;
    ElfW(Verdef) *verdef;
    ElfW(Verneed) *verneed;
    ElfW(Half) *versym;
    પૂર્ણાંક nb_local_ver, *local_ver;
};


સ્થિર શૂન્ય store_version(TCCState *s1, સંરચના versym_info *v, અક્ષર *dynstr)
{
    અક્ષર *lib, *version;
    uint32_t next;
    પૂર્ણાંક i;

#define	DEBUG_VERSION 0

    જો (v->versym && v->verdef) {
      ElfW(Verdef) *vdef = v->verdef;
      lib = ખાલી;
      કરો {
        ElfW(Verdaux) *verdaux =
	  (ElfW(Verdaux) *) (((અક્ષર *) vdef) + vdef->vd_aux);

#જો DEBUG_VERSION
	printf ("verdef: version:%u flags:%u index:%u, hash:%u\n",
	        vdef->vd_version, vdef->vd_flags, vdef->vd_ndx,
		vdef->vd_hash);
#endif
	જો (vdef->vd_cnt) {
          version = dynstr + verdaux->vda_name;

	  જો (lib == ખાલી)
	    lib = version;
	  નહીંતર
            set_ver_to_ver(s1, &v->nb_local_ver, &v->local_ver, vdef->vd_ndx,
                           lib, version);
#જો DEBUG_VERSION
	  printf ("  verdaux(%u): %s\n", vdef->vd_ndx, version);
#endif
	}
        next = vdef->vd_next;
        vdef = (ElfW(Verdef) *) (((અક્ષર *) vdef) + next);
      } જ્યારે (next);
    }
    જો (v->versym && v->verneed) {
      ElfW(Verneed) *vneed = v->verneed;
      કરો {
        ElfW(Vernaux) *vernaux =
	  (ElfW(Vernaux) *) (((અક્ષર *) vneed) + vneed->vn_aux);

        lib = dynstr + vneed->vn_file;
#જો DEBUG_VERSION
	printf ("verneed: %u %s\n", vneed->vn_version, lib);
#endif
	માટે (i = 0; i < vneed->vn_cnt; i++) {
	  જો ((vernaux->vna_other & 0x8000) == 0) { /* hidden */
              version = dynstr + vernaux->vna_name;
              set_ver_to_ver(s1, &v->nb_local_ver, &v->local_ver, vernaux->vna_other,
                             lib, version);
#જો DEBUG_VERSION
	    printf ("  vernaux(%u): %u %u %s\n",
		    vernaux->vna_other, vernaux->vna_hash,
		    vernaux->vna_flags, version);
#endif
	  }
	  vernaux = (ElfW(Vernaux) *) (((અક્ષર *) vernaux) + vernaux->vna_next);
	}
        next = vneed->vn_next;
        vneed = (ElfW(Verneed) *) (((અક્ષર *) vneed) + next);
      } જ્યારે (next);
    }

#જો DEBUG_VERSION
    માટે (i = 0; i < v->nb_local_ver; i++) {
      જો (v->local_ver[i] > 0) {
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
ST_FUNC પૂર્ણાંક tcc_load_dll(TCCState *s1, પૂર્ણાંક fd, અચલ અક્ષર *filename, પૂર્ણાંક level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    પૂર્ણાંક i, nb_syms, nb_dts, sym_bind, ret = -1;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;

    અક્ષર *dynstr;
    પૂર્ણાંક sym_index;
    અચલ અક્ષર *name, *soname;
    સંરચના versym_info v;

    full_read(fd, &ehdr, કદ(ehdr));

    /* test CPU specific stuff */
    જો (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
        પાછા tcc_error_noabort("bad architecture");
    }

    /* read sections */
    shdr = load_data(fd, ehdr.e_shoff, કદ(ElfW(Shdr)) * ehdr.e_shnum);

    /* load dynamic section and dynamic symbols */
    nb_syms = 0;
    nb_dts = 0;
    dynamic = ખાલી;
    dynsym = ખાલી; /* avoid warning */
    dynstr = ખાલી; /* avoid warning */
    memset(&v, 0, કદ v);

    માટે(i = 0, sh = shdr; i < ehdr.e_shnum; i++, sh++) {
        પસંદગી(sh->sh_type) {
        સ્થિતિ SHT_DYNAMIC:
            nb_dts = sh->sh_size / કદ(ElfW(Dyn));
            dynamic = load_data(fd, sh->sh_offset, sh->sh_size);
            તોડો;
        સ્થિતિ SHT_DYNSYM:
            nb_syms = sh->sh_size / કદ(ElfW(Sym));
            dynsym = load_data(fd, sh->sh_offset, sh->sh_size);
            sh1 = &shdr[sh->sh_link];
            dynstr = load_data(fd, sh1->sh_offset, sh1->sh_size);
            તોડો;
        સ્થિતિ SHT_GNU_verdef:
	    v.verdef = load_data(fd, sh->sh_offset, sh->sh_size);
	    તોડો;
        સ્થિતિ SHT_GNU_verneed:
	    v.verneed = load_data(fd, sh->sh_offset, sh->sh_size);
	    તોડો;
        સ્થિતિ SHT_GNU_versym:
            v.nb_versyms = sh->sh_size / કદ(ElfW(Half));
	    v.versym = load_data(fd, sh->sh_offset, sh->sh_size);
	    તોડો;
        મૂળભૂત:
            તોડો;
        }
    }

    જો (!dynamic)
        જાઓ the_end;

    /* compute the real library name */
    soname = tcc_basename(filename);
    માટે(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        જો (dt->d_tag == DT_SONAME)
            soname = dynstr + dt->d_un.d_val;

    /* if the dll is already loaded, do not load it */
    જો (tcc_add_dllref(s1, soname, level)->found)
        જાઓ ret_success;

    જો (v.nb_versyms != nb_syms)
        tcc_free (v.versym), v.versym = ખાલી;
    નહીંતર
        store_version(s1, &v, dynstr);

    /* add dynamic symbols in dynsym_section */
    માટે(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        જો (sym_bind == STB_LOCAL)
            ચાલુ;
        name = dynstr + sym->st_name;
        sym_index = set_elf_sym(s1->dynsymtab_section, sym->st_કિંમત, sym->st_size,
                                sym->st_info, sym->st_other, sym->st_shndx, name);
        જો (v.versym) {
            ElfW(Half) vsym = v.versym[i];
            જો ((vsym & 0x8000) == 0 && vsym > 0 && vsym < v.nb_local_ver)
                set_sym_version(s1, sym_index, v.local_ver[vsym]);
        }
    }

    /* do not load all referenced libraries
       (recursive loading can break linking of libraries) */
    /* following DT_NEEDED is needed for the dynamic loader (libdl.so),
       but it is no longer needed, when linking a library or a program.
       When tcc output mode is OUTPUT_MEM,
       tcc calls dlopen, which handles DT_NEEDED for us */

#જો 0
    માટે(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        જો (dt->d_tag == DT_RPATH)
            tcc_add_library_path(s1, dynstr + dt->d_un.d_val);

    /* load all referenced DLLs */
    માટે(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        પસંદગી(dt->d_tag) {
        સ્થિતિ DT_NEEDED:
            name = dynstr + dt->d_un.d_val;
            જો (tcc_add_dllref(s1, name, -1))
                ચાલુ;
            જો (tcc_add_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                ret = tcc_error_noabort("referenced dll '%s' not found", name);
                જાઓ the_end;
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
    પાછા ret;
}

#define LD_TOK_NAME 256
#define LD_TOK_EOF  (-1)
સ્થિર પૂર્ણાંક ld_inp(TCCState *s1)
{
    પૂર્ણાંક c = *s1->ld_p;
    જો (c == 0)
        પાછા CH_EOF;
    ++s1->ld_p;
    પાછા c;
}
#define ld_unget(s1, ch) જો (ch != CH_EOF) --s1->ld_p

/* return next ld script token */
સ્થિર પૂર્ણાંક ld_next(TCCState *s1, અક્ષર *name, પૂર્ણાંક name_size)
{
    પૂર્ણાંક c, d, ch;
    અક્ષર *q;

 redo:
    ch = ld_inp(s1);
    q = name, *q++ = ch;
    પસંદગી(ch) {
    સ્થિતિ ' ':
    સ્થિતિ '\t':
    સ્થિતિ '\f':
    સ્થિતિ '\v':
    સ્થિતિ '\r':
    સ્થિતિ '\n':
        જાઓ redo;
    સ્થિતિ '/':
        ch = ld_inp(s1);
        જો (ch == '*') { /* comment */
            માટે (d = 0;; d = ch) {
                ch = ld_inp(s1);
                જો (ch == CH_EOF || (ch == '/' && d == '*'))
                    તોડો;
            }
            જાઓ redo;
        } નહીંતર {
            જાઓ parse_name;
        }
        તોડો;
    સ્થિતિ '\\':
    /* case 'a' ... 'z': */
    સ્થિતિ 'a':
       સ્થિતિ 'b':
       સ્થિતિ 'c':
       સ્થિતિ 'd':
       સ્થિતિ 'e':
       સ્થિતિ 'f':
       સ્થિતિ 'g':
       સ્થિતિ 'h':
       સ્થિતિ 'i':
       સ્થિતિ 'j':
       સ્થિતિ 'k':
       સ્થિતિ 'l':
       સ્થિતિ 'm':
       સ્થિતિ 'n':
       સ્થિતિ 'o':
       સ્થિતિ 'p':
       સ્થિતિ 'q':
       સ્થિતિ 'r':
       સ્થિતિ 's':
       સ્થિતિ 't':
       સ્થિતિ 'u':
       સ્થિતિ 'v':
       સ્થિતિ 'w':
       સ્થિતિ 'x':
       સ્થિતિ 'y':
       સ્થિતિ 'z':
    /* case 'A' ... 'z': */
    સ્થિતિ 'A':
       સ્થિતિ 'B':
       સ્થિતિ 'C':
       સ્થિતિ 'D':
       સ્થિતિ 'E':
       સ્થિતિ 'F':
       સ્થિતિ 'G':
       સ્થિતિ 'H':
       સ્થિતિ 'I':
       સ્થિતિ 'J':
       સ્થિતિ 'K':
       સ્થિતિ 'L':
       સ્થિતિ 'M':
       સ્થિતિ 'N':
       સ્થિતિ 'O':
       સ્થિતિ 'P':
       સ્થિતિ 'Q':
       સ્થિતિ 'R':
       સ્થિતિ 'S':
       સ્થિતિ 'T':
       સ્થિતિ 'U':
       સ્થિતિ 'V':
       સ્થિતિ 'W':
       સ્થિતિ 'X':
       સ્થિતિ 'Y':
       સ્થિતિ 'Z':
    સ્થિતિ '-':
    સ્થિતિ '_':
    સ્થિતિ '.':
    સ્થિતિ '$':
    સ્થિતિ '~':
        માટે(;;) {
            ch = ld_inp(s1);
    parse_name:
            જો (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') ||
                  strchr("/.-_+=$:\\,~", ch)))
                તોડો;
            જો ((q - name) < name_size - 1) {
                *q++ = ch;
            }
        }
        ld_unget(s1, ch);
        c = LD_TOK_NAME;
        તોડો;
    સ્થિતિ CH_EOF:
        c = LD_TOK_EOF;
        તોડો;
    મૂળભૂત:
        c = ch;
        તોડો;
    }
    *q = '\0';
    પાછા c;
}

સ્થિર પૂર્ણાંક ld_add_file(TCCState *s1, અચલ અક્ષર filename[])
{
    જો (filename[0] == '-' && filename[1] == 'l')
        પાછા tcc_add_library(s1, filename + 2);
    જો (CONFIG_SYSROOT[0] != '\0' || !IS_ABSPATH(filename)) {
        /* lookup via library paths */
        પૂર્ણાંક ret = tcc_add_dll(s1, tcc_basename(filename), 0);
        જો (ret != FILE_NOT_FOUND)
            પાછા ret;
    }
    પાછા tcc_add_file_internal(s1, filename, AFF_PRINT_ERROR);
}

/* did static libraries add new undefined symbols? */
સ્થિર પૂર્ણાંક new_undef_sym(TCCState *s1, પૂર્ણાંક sym_offset)
{
    જ્યારે (sym_offset < s1->symtab->data_offset) {
        ElfW(Sym) *esym = (શૂન્ય*)(s1->symtab->data + sym_offset);
        જો (esym->st_shndx == SHN_UNDEF)
            પાછા 1;
        sym_offset += કદ (ElfW(Sym));
    }
    પાછા 0;
}

સ્થિર પૂર્ણાંક ld_add_file_list(TCCState *s1, અચલ અક્ષર *cmd)
{
    અક્ષર filename[1024];
    પૂર્ણાંક t, c, sym_offset, ret = 0;
    unsigned અક્ષર *pos = s1->ld_p;

repeat:
    s1->ld_p = pos;
    sym_offset = s1->symtab->data_offset;
    c = cmd[0];

    t = ld_next(s1, filename, કદ(filename));
    જો (t != '(')
        પાછા tcc_error_noabort("expected '(' after %s", cmd);
    t = ld_next(s1, filename, કદ(filename));
    માટે(;;) {
        જો (t == LD_TOK_EOF) {
            પાછા tcc_error_noabort("unexpected end of file");
        } નહીંતર જો (t == ')') {
            તોડો;
        } નહીંતર જો (t != LD_TOK_NAME) {
            પાછા tcc_error_noabort("unexpected token '%c'", t);
        } નહીંતર જો (!strcmp(filename, "AS_NEEDED")) {
            ret |= ld_add_file_list(s1, filename);
        } નહીંતર જો (c == 'I' || c == 'G' || c == 'A') {
            ret |= !!ld_add_file(s1, filename);
        }
        જો (ret < 0)
            પાછા ret;
        t = ld_next(s1, filename, કદ(filename));
        જો (t == ',')
            t = ld_next(s1, filename, કદ(filename));
    }
    જો (c == 'G' && ret == 0 && new_undef_sym(s1, sym_offset))
        જાઓ repeat;
    પાછા ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC પૂર્ણાંક tcc_load_ldscript(TCCState *s1, પૂર્ણાંક fd)
{
    અક્ષર cmd[64];
    પૂર્ણાંક t, ret = 0, noscript = 1;
    unsigned અક્ષર *text_ptr, *saved_ptr;

    saved_ptr = s1->ld_p;
    s1->ld_p = text_ptr = (શૂન્ય*)tcc_load_text(fd);
    માટે(;;) {
        t = ld_next(s1, cmd, કદ(cmd));
        જો (t == LD_TOK_EOF)
            તોડો;
        જો (!strcmp(cmd, "INPUT") ||
            !strcmp(cmd, "GROUP")) {
            ret |= ld_add_file_list(s1, cmd);
        } નહીંતર જો (!strcmp(cmd, "OUTPUT_FORMAT") ||
                   !strcmp(cmd, "TARGET")) {
            /* ignore some commands */
            ret |= ld_add_file_list(s1, cmd);
        } નહીંતર જો (noscript) {
            ret = FILE_NOT_RECOGNIZED;
        } નહીંતર {
            ret = tcc_error_noabort("unexpected '%s'", cmd);
        }
        જો (ret < 0)
            તોડો;
        noscript = 0;
    }
    tcc_free(text_ptr);
    s1->ld_p = saved_ptr;
    પાછા ret < 0 ? ret : -ret;
}
#endif /* !ELF_OBJ_ONLY */
