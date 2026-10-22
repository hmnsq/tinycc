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

#అన్తర్భావ "tcc.h"

/* Define this to get some debug output during relocation processing.  */
#నిర్వచనం_రద్దు DEBUG_RELOC

/********************************************************/
/* global variables */

/* elf version information */
నిర్మాణం sym_సంస్కరణ {
    అక్షరం *lib;
    అక్షరం *సంస్కరణ;
    పూర్ణాంకం బహిర్గతం_సూచీ;
    పూర్ణాంకం prev_same_lib;
};

#నిర్వచించు nb_sym_versions     s1->nb_sym_versions
#నిర్వచించు sym_versions        s1->sym_versions
#నిర్వచించు nb_sym_గమ్యం_సంస్కరణ   s1->nb_sym_గమ్యం_సంస్కరణ
#నిర్వచించు sym_గమ్యం_సంస్కరణ      s1->sym_గమ్యం_సంస్కరణ
#నిర్వచించు dt_verneednum       s1->dt_verneednum
#నిర్వచించు versym_section      s1->versym_section
#నిర్వచించు verneed_section     s1->verneed_section

/* special flag to indicate that the section should not be linked to the other ones */
#నిర్వచించు SHF_వ్యక్తిగత 0x80000000
/* section is dynsymtab_section */
#నిర్వచించు SHF_DYNSYM 0x40000000

#నిర్వచితమైతే TCC_లక్ష్యం_PE
#నిర్వచించు shf_RELRO SHF_ALLOC
స్థిర స్థిరరాశి అక్షరం rdata[] = ".rdata";
#లేకపోతే
#నిర్వచించు shf_RELRO SHF_ALLOC /* eventually made SHF_WRITE in sort_sections() */
స్థిర స్థిరరాశి అక్షరం rdata[] = ".data.ro";
#అయితే_ముగింపు

/* ------------------------------------------------------------------------- */

ST_FUNC శూన్య tccelf_new(TCCState *s)
{
    TCCState *s1 = s;

    /* no section zero */
    dynarray_కూడు(&s->sections, &s->nb_sections, ఖాళీ);

    /* create standard sections */
    పాఠ్యం_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    దత్తాంశం_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    /* create ro data section (make ro after relocation done with GNU_RELRO) */
    rodata_section = new_section(s, rdata, SHT_PROGBITS, shf_RELRO);
    bss_section = new_section(s, ".bss", SHT_NOBITS, SHF_ALLOC | SHF_WRITE);
    common_section = new_section(s, ".common", SHT_NOBITS, SHF_వ్యక్తిగత);
    common_section->sh_అంకె = SHN_COMMON;

    /* symbols are always generated for linking stage */
    symtab_section = new_symtab(s, ".symtab", SHT_SYMTAB, 0,
                                ".strtab",
                                ".hashtab", SHF_వ్యక్తిగత);

    /* private symbol table for dynamic symbols */
    s->dynsymtab_section = new_symtab(s, ".dynsymtab", SHT_SYMTAB, SHF_వ్యక్తిగత|SHF_DYNSYM,
                                      ".dynstrtab",
                                      ".dynhashtab", SHF_వ్యక్తిగత);
    get_sym_attr(s, 0, 1);

    ఒకవేళ (s->do_debug) {
        /* add debug sections */
        tcc_debug_new(s);
    }

#ఒకవేళ TCC_EH_చట్రం
    ఒకవేళ (s->output_format != TCC_OUTPUT_FORMAT_ELF)
        s->unwind_tables = 0;
    tcc_eh_చట్రం_ప్రారంభం(s);
#అయితే_ముగింపు

#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        /* (make ro after relocation done with GNU_RELRO) */
        bounds_section = new_section(s, ".bounds", SHT_PROGBITS, shf_RELRO);
        lbounds_section = new_section(s, ".lbounds", SHT_PROGBITS, shf_RELRO);
    }
#అయితే_ముగింపు

#నిర్వచితమైతే TCC_లక్ష్యం_PE
    /* to make sure that -ltcc1 -Wl,-e,_start will grab the startup code
       from libtcc1.a (unless _start defined) */
    ఒకవేళ (s->elf_entryname)
        సమితి_global_sym(s, s->elf_entryname, ఖాళీ, 0); /* SHN_UNDEF */
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
    ఒకవేళ (ఖాళీ == s->elfint && s1->output_type != TCC_OUTPUT_OBJ) {
        స్థిరరాశి అక్షరం *p = CONFIG_TCC_ELFINTERP;
#ఒకవేళ defined TCC_లక్ష్యం_ARM && defined CONFIG_TCC_ELFINTERP_ARMHF
        ఒకవేళ (s->float_abi == ARM_HARD_FLOAT)
            p = CONFIG_TCC_ELFINTERP_ARMHF;
#అయితే_ముగింపు
#ఒకవేళ defined TCC_IS_NATIVE && defined TARGETOS_BSD
        /* see commit 55cb2170cd5ce77a7d76dcaf462fad2707281605 */
        { స్థిరరాశి అక్షరం *e = getenv("LD_SO"); ఒకవేళ (e) p = e; }
#అయితే_ముగింపు
        s->elfint = tcc_strdup(p);
    }
#అయితే_ముగింపు /* ndef ELF_OBJ_ONLY */
}

ST_FUNC శూన్య free_section(Section *s)
{
    ఒకవేళ (!s)
        తిరిగి;
    tcc_free(s->దత్తాంశం);
    s->దత్తాంశం = ఖాళీ;
    s->దత్తాంశం_allocated = s->దత్తాంశం_స్థానభ్రంశం = 0;
}

ST_FUNC శూన్య tccelf_delete(TCCState *s1)
{
    పూర్ణాంకం i;

#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
    /* free symbol versions */
    కొరకు (i = 0; i < nb_sym_versions; i++) {
        tcc_free(sym_versions[i].సంస్కరణ);
        tcc_free(sym_versions[i].lib);
    }
    tcc_free(sym_versions);
    tcc_free(sym_గమ్యం_సంస్కరణ);
#అయితే_ముగింపు

    /* free all sections */
    కొరకు(i = 1; i < s1->nb_sections; i++)
        free_section(s1->sections[i]);
    dynarray_reset(&s1->sections, &s1->nb_sections);

    కొరకు(i = 0; i < s1->nb_priv_sections; i++)
        free_section(s1->priv_sections[i]);
    dynarray_reset(&s1->priv_sections, &s1->nb_priv_sections);

    tcc_free(s1->sym_attrs);
    symtab_section = ఖాళీ; /* for tccrun.c:rt_printline() */
}

/* save section data state */
ST_FUNC శూన్య tccelf_begin_file(TCCState *s1)
{
    Section *s; పూర్ణాంకం i;
    కొరకు (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        s->sh_స్థానభ్రంశం = s->దత్తాంశం_స్థానభ్రంశం;
    }
    /* disable symbol hashing during compilation */
    s = s1->symtab, s->reloc = s->hash, s->hash = ఖాళీ;
#ఒకవేళ defined TCC_లక్ష్యం_X86_64 && defined TCC_లక్ష్యం_PE
    s1->uw_sym = 0;
    s1->uw_offs = 0;
#అయితే_ముగింపు
}

స్థిర శూన్య update_relocs(TCCState *s1, Section *s, పూర్ణాంకం *old_గమ్యం_new_syms, పూర్ణాంకం మొదటి_sym);

/* At the end of compilation, convert any UNDEF syms to global, and merge
   with previously existing symbols */
ST_FUNC శూన్య tccelf_చివర_file(TCCState *s1)
{
    Section *s = s1->symtab;
    పూర్ణాంకం మొదటి_sym, nb_syms, *tr, i;

    మొదటి_sym = s->sh_స్థానభ్రంశం / పరిమాణం (ElfSym);
    nb_syms = s->దత్తాంశం_స్థానభ్రంశం / పరిమాణం (ElfSym) - మొదటి_sym;
    s->దత్తాంశం_స్థానభ్రంశం = s->sh_స్థానభ్రంశం;
    s->link->దత్తాంశం_స్థానభ్రంశం = s->link->sh_స్థానభ్రంశం;
    s->hash = s->reloc, s->reloc = ఖాళీ;
    tr = tcc_mallocz(nb_syms * పరిమాణం *tr);

    కొరకు (i = 0; i < nb_syms; ++i) {
        ElfSym *sym = (ElfSym*)s->దత్తాంశం + మొదటి_sym + i;
        ఒకవేళ (sym->st_shndx == SHN_UNDEF) {
            పూర్ణాంకం sym_bind = ELFW(ST_BIND)(sym->st_info);
            పూర్ణాంకం sym_type = ELFW(ST_TYPE)(sym->st_info);
            ఒకవేళ (sym_bind == STB_LOCAL)
                sym_bind = STB_GLOBAL;
#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_PE
            ఒకవేళ (sym_bind == STB_GLOBAL && s1->output_type == TCC_OUTPUT_OBJ) {
                /* undefined symbols with STT_FUNC are confusing gnu ld when
                   linking statically to STT_GNU_IFUNC.  Keep TLS typed,
                   otherwise gnu ld rejects non-TLS refs to TLS definitions. */
                ఒకవేళ (sym_type != STT_TLS)
                    sym_type = STT_NOTYPE;
            }
#అయితే_ముగింపు
            sym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
        }
        tr[i] = సమితి_elf_sym(s, sym->st_విలువ, sym->st_కొలత, sym->st_info,
            sym->st_other, sym->st_shndx, (అక్షరం*)s->link->దత్తాంశం + sym->st_name);
    }
    /* now update relocations */
    update_relocs(s1, s, tr, మొదటి_sym);
    tcc_free(tr);
    /* record text/data/bss output for -bench info */
    కొరకు (i = 0; i < 4; ++i) {
        s = s1->sections[i + 1];
        s1->మొత్తం_output[i] += s->దత్తాంశం_స్థానభ్రంశం - s->sh_స్థానభ్రంశం;
    }
}

ST_FUNC Section *new_section(TCCState *s1, స్థిరరాశి అక్షరం *name, పూర్ణాంకం sh_type, పూర్ణాంకం sh_flags)
{
    Section *sec;

    sec = tcc_mallocz(పరిమాణం(Section) + అక్షరశ్రేణి_పొడవు(name));
    sec->s1 = s1;
    strcpy(sec->name, name);
    sec->sh_type = sh_type;
    sec->sh_flags = sh_flags;
    ఎంపిక(sh_type) {
    స్థితి SHT_GNU_versym:
        sec->sh_addralign = 2;
        ఆపు;
    స్థితి SHT_HASH:
    స్థితి SHT_GNU_HASH:
    స్థితి SHT_REL:
    స్థితి SHT_RELA:
    స్థితి SHT_DYNSYM:
    స్థితి SHT_SYMTAB:
    స్థితి SHT_DYNAMIC:
    స్థితి SHT_GNU_verneed:
    స్థితి SHT_GNU_verdef:
        sec->sh_addralign = PTR_కొలత;
        ఆపు;
    స్థితి SHT_STRTAB:
        sec->sh_addralign = 1;
        ఆపు;
    అప్రమేయ:
        sec->sh_addralign =  PTR_కొలత; /* gcc/pcc default alignment */
        ఆపు;
    }

    ఒకవేళ (sh_flags & SHF_వ్యక్తిగత) {
        dynarray_కూడు(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } లేకపోతే {
        sec->sh_అంకె = s1->nb_sections;
        dynarray_కూడు(&s1->sections, &s1->nb_sections, sec);
    }

    తిరిగి sec;
}

ST_FUNC శూన్య init_symtab(Section *s)
{
    పూర్ణాంకం *ptr, nb_buckets = 1;
    put_elf_str(s->link, "");
    section_ptr_కూడు(s, పరిమాణం (ElfW(Sym)));
    ptr = section_ptr_కూడు(s->hash, (2 + nb_buckets + 1) * పరిమాణం(పూర్ణాంకం));
    ptr[0] = nb_buckets;
    ptr[1] = 1;
    memset(ptr + 2, 0, (nb_buckets + 1) * పరిమాణం(పూర్ణాంకం));
}

ST_FUNC Section *new_symtab(TCCState *s1,
                           స్థిరరాశి అక్షరం *symtab_name, పూర్ణాంకం sh_type, పూర్ణాంకం sh_flags,
                           స్థిరరాశి అక్షరం *strtab_name,
                           స్థిరరాశి అక్షరం *hash_name, పూర్ణాంకం hash_sh_flags)
{
    Section *symtab, *strtab, *hash;
    symtab = new_section(s1, symtab_name, sh_type, sh_flags);
    symtab->sh_entsize = పరిమాణం(ElfW(Sym));
    strtab = new_section(s1, strtab_name, SHT_STRTAB, sh_flags);
    symtab->link = strtab;
    hash = new_section(s1, hash_name, SHT_HASH, hash_sh_flags);
    hash->sh_entsize = పరిమాణం(పూర్ణాంకం);
    symtab->hash = hash;
    hash->link = symtab;
    init_symtab(symtab);
    తిరిగి symtab;
}

/* realloc section and set its content to zero */
ST_FUNC శూన్య section_realloc(Section *sec, గుర్తులేని దీర్ఘ new_కొలత)
{
    గుర్తులేని దీర్ఘ కొలత;
    గుర్తులేని అక్షరం *దత్తాంశం;

    కొలత = sec->దత్తాంశం_allocated;
    ఒకవేళ (కొలత == 0)
        కొలత = 1;
    అయితే (కొలత < new_కొలత)
        కొలత = కొలత * 2;
    దత్తాంశం = tcc_realloc(sec->దత్తాంశం, కొలత);
    memset(దత్తాంశం + sec->దత్తాంశం_allocated, 0, కొలత - sec->దత్తాంశం_allocated);
    sec->దత్తాంశం = దత్తాంశం;
    sec->దత్తాంశం_allocated = కొలత;
}

/* reserve at least 'size' bytes aligned per 'align' in section
   'sec' from current offset, and return the aligned offset */
ST_FUNC కొలత_t section_కూడు(Section *sec, addr_t కొలత, పూర్ణాంకం align)
{
    కొలత_t స్థానభ్రంశం, offset1;

    స్థానభ్రంశం = (sec->దత్తాంశం_స్థానభ్రంశం + align - 1) & -align;
    offset1 = స్థానభ్రంశం + కొలత;
    ఒకవేళ (sec->sh_type != SHT_NOBITS && offset1 > sec->దత్తాంశం_allocated)
        section_realloc(sec, offset1);
    sec->దత్తాంశం_స్థానభ్రంశం = offset1;
    ఒకవేళ (align > sec->sh_addralign)
        sec->sh_addralign = align;
    తిరిగి స్థానభ్రంశం;
}

/* reserve at least 'size' bytes in section 'sec' from
   sec->data_offset. */
ST_FUNC శూన్య *section_ptr_కూడు(Section *sec, addr_t కొలత)
{
    కొలత_t స్థానభ్రంశం = section_కూడు(sec, కొలత, 1);
    తిరిగి sec->దత్తాంశం + స్థానభ్రంశం;
}

#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
/* reserve at least 'size' bytes from section start */
స్థిర శూన్య section_reserve(Section *sec, గుర్తులేని దీర్ఘ కొలత)
{
    ఒకవేళ (కొలత > sec->దత్తాంశం_allocated)
        section_realloc(sec, కొలత);
    ఒకవేళ (కొలత > sec->దత్తాంశం_స్థానభ్రంశం)
        sec->దత్తాంశం_స్థానభ్రంశం = కొలత;
}
#అయితే_ముగింపు

స్థిర Section *have_section(TCCState *s1, స్థిరరాశి అక్షరం *name)
{
    Section *sec;
    పూర్ణాంకం i;
    కొరకు(i = 1; i < s1->nb_sections; i++) {
        sec = s1->sections[i];
        ఒకవేళ (!strcmp(name, sec->name))
            తిరిగి sec;
    }
    తిరిగి ఖాళీ;
}

/* return a reference to a section, and create it if it does not
   exists */
ST_FUNC Section *కనుగొను_section(TCCState *s1, స్థిరరాశి అక్షరం *name)
{
    Section *sec = have_section(s1, name);
    ఒకవేళ (sec)
        తిరిగి sec;
    /* sections are created as PROGBITS */
    తిరిగి new_section(s1, name, SHT_PROGBITS, SHF_ALLOC);
}

/* ------------------------------------------------------------------------- */

ST_FUNC పూర్ణాంకం put_elf_str(Section *s, స్థిరరాశి అక్షరం *sym)
{
    పూర్ణాంకం స్థానభ్రంశం, len;
    అక్షరం *ptr;

    len = అక్షరశ్రేణి_పొడవు(sym) + 1;
    స్థానభ్రంశం = s->దత్తాంశం_స్థానభ్రంశం;
    ptr = section_ptr_కూడు(s, len);
    memmove(ptr, sym, len);
    తిరిగి స్థానభ్రంశం;
}

/* elf symbol hashing function */
స్థిర ElfW(మాట_2) elf_hash(స్థిరరాశి గుర్తులేని అక్షరం *name)
{
    ElfW(మాట_2) h = 0, g;

    అయితే (*name) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        ఒకవేళ (g)
            h ^= g >> 24;
        h &= ~g;
    }
    తిరిగి h;
}

/* rebuild hash table of section s */
/* NOTE: we do factorize the hash table code to go faster */
స్థిర శూన్య rebuild_hash(Section *s, గుర్తులేని పూర్ణాంకం nb_buckets)
{
    ElfW(Sym) *sym;
    పూర్ణాంకం *ptr, *hash, nb_syms, sym_సూచీ, h;
    గుర్తులేని అక్షరం *strtab;

    strtab = s->link->దత్తాంశం;
    nb_syms = s->దత్తాంశం_స్థానభ్రంశం / పరిమాణం(ElfW(Sym));

    ఒకవేళ (!nb_buckets)
        nb_buckets = ((పూర్ణాంకం*)s->hash->దత్తాంశం)[0];

    s->hash->దత్తాంశం_స్థానభ్రంశం = 0;
    ptr = section_ptr_కూడు(s->hash, (2 + nb_buckets + nb_syms) * పరిమాణం(పూర్ణాంకం));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    memset(hash, 0, (nb_buckets + 1) * పరిమాణం(పూర్ణాంకం));
    ptr += nb_buckets + 1;

    sym = (ElfW(Sym) *)s->దత్తాంశం + 1;
    కొరకు(sym_సూచీ = 1; sym_సూచీ < nb_syms; sym_సూచీ++) {
        ఒకవేళ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            h = elf_hash(strtab + sym->st_name) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_సూచీ;
        } లేకపోతే {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}

/* return the symbol number */
ST_FUNC పూర్ణాంకం put_elf_sym(Section *s, addr_t విలువ, గుర్తులేని దీర్ఘ కొలత,
    పూర్ణాంకం info, పూర్ణాంకం other, పూర్ణాంకం shndx, స్థిరరాశి అక్షరం *name)
{
    పూర్ణాంకం name_స్థానభ్రంశం, sym_సూచీ;
    పూర్ణాంకం nbuckets, h;
    ElfW(Sym) *sym;
    Section *hs;

    sym = section_ptr_కూడు(s, పరిమాణం(ElfW(Sym)));
    ఒకవేళ (name && name[0])
        name_స్థానభ్రంశం = put_elf_str(s->link, name);
    లేకపోతే
        name_స్థానభ్రంశం = 0;
    /* XXX: endianness */
    sym->st_name = name_స్థానభ్రంశం;
    sym->st_విలువ = విలువ;
    sym->st_కొలత = కొలత;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
    sym_సూచీ = sym - (ElfW(Sym) *)s->దత్తాంశం;
    hs = s->hash;
    ఒకవేళ (hs) {
        పూర్ణాంకం *ptr, *పునాది;
        ptr = section_ptr_కూడు(hs, పరిమాణం(పూర్ణాంకం));
        పునాది = (పూర్ణాంకం *)hs->దత్తాంశం;
        /* only add global or weak symbols. */
        ఒకవేళ (ELFW(ST_BIND)(info) != STB_LOCAL) {
            /* add another hashing entry */
            nbuckets = పునాది[0];
            h = elf_hash((గుర్తులేని అక్షరం *)s->link->దత్తాంశం + name_స్థానభ్రంశం) % nbuckets;
            *ptr = పునాది[2 + h];
            పునాది[2 + h] = sym_సూచీ;
            పునాది[1]++;
            /* we resize the hash table */
            hs->nb_hashed_syms++;
            ఒకవేళ (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } లేకపోతే {
            *ptr = 0;
            పునాది[1]++;
        }
    }
    తిరిగి sym_సూచీ;
}

ST_FUNC పూర్ణాంకం కనుగొను_elf_sym(Section *s, స్థిరరాశి అక్షరం *name)
{
    ElfW(Sym) *sym;
    Section *hs;
    పూర్ణాంకం nbuckets, sym_సూచీ, h;
    స్థిరరాశి అక్షరం *name1;

    hs = s->hash;
    ఒకవేళ (!hs)
        తిరిగి 0;
    nbuckets = ((పూర్ణాంకం *)hs->దత్తాంశం)[0];
    h = elf_hash((గుర్తులేని అక్షరం *) name) % nbuckets;
    sym_సూచీ = ((పూర్ణాంకం *)hs->దత్తాంశం)[2 + h];
    అయితే (sym_సూచీ != 0) {
        sym = &((ElfW(Sym) *)s->దత్తాంశం)[sym_సూచీ];
        name1 = (అక్షరం *) s->link->దత్తాంశం + sym->st_name;
        ఒకవేళ (!strcmp(name, name1))
            తిరిగి sym_సూచీ;
        sym_సూచీ = ((పూర్ణాంకం *)hs->దత్తాంశం)[2 + nbuckets + sym_సూచీ];
    }
    తిరిగి 0;
}

/* return elf symbol value, signal error if 'err' is nonzero, decorate
   name if FORC */
ST_FUNC addr_t get_sym_addr(TCCState *s1, స్థిరరాశి అక్షరం *name, పూర్ణాంకం err, పూర్ణాంకం forc)
{
    పూర్ణాంకం sym_సూచీ;
    ElfW(Sym) *sym;
    అక్షరం buf[256];
    ఒకవేళ (forc && s1->leading_underscore
#నిర్వచితమైతే TCC_లక్ష్యం_PE
        /* win32-32bit stdcall symbols always have _ already */
        && !strchr(name, '@')
#అయితే_ముగింపు
        ) {
        buf[0] = '_';
        pstrcpy(buf + 1, పరిమాణం(buf) - 1, name);
        name = buf;
    }
    sym_సూచీ = కనుగొను_elf_sym(s1->symtab, name);
    sym = &((ElfW(Sym) *)s1->symtab->దత్తాంశం)[sym_సూచీ];
    ఒకవేళ (!sym_సూచీ || sym->st_shndx == SHN_UNDEF) {
        ఒకవేళ (err)
            tcc_error_noabort("%s not defined", name);
        తిరిగి (addr_t)-1;
    }
    తిరిగి sym->st_విలువ;
}

/* return elf symbol value */
LIBTCCAPI శూన్య *tcc_get_చిహ్నం(TCCState *s, స్థిరరాశి అక్షరం *name)
{
    addr_t addr = get_sym_addr(s, name, 0, 1);
    తిరిగి addr == -1 ? ఖాళీ : (శూన్య*)(uintptr_t)addr;
}

LIBTCCAPI పూర్ణాంకం tcc_కూడు_చిహ్నం(TCCState *s1, స్థిరరాశి అక్షరం *name, స్థిరరాశి శూన్య *val)
{
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s1, 0, name, (uintptr_t)val);
#లేకపోతే
    అక్షరం buf[256];
    ఒకవేళ (s1->leading_underscore) {
        buf[0] = '_';
        pstrcpy(buf + 1, పరిమాణం(buf) - 1, name);
        name = buf;
    }
    సమితి_global_sym(s1, name, ఖాళీ, (addr_t)(uintptr_t)val); /* NULL: SHN_ABS */
#అయితే_ముగింపు
    తిరిగి 0;
}

/* list elf symbol names and values */
ST_FUNC శూన్య list_elf_symbols(TCCState *s, శూన్య *ctx,
    శూన్య (*చిహ్నం_cb)(శూన్య *ctx, స్థిరరాశి అక్షరం *name, స్థిరరాశి శూన్య *val))
{
    ElfW(Sym) *sym;
    Section *symtab;
    పూర్ణాంకం sym_సూచీ, చివర_sym;
    స్థిరరాశి అక్షరం *name;
    గుర్తులేని అక్షరం sym_vis, sym_bind;

    symtab = s->symtab;
    చివర_sym = symtab->దత్తాంశం_స్థానభ్రంశం / పరిమాణం (ElfSym);
    కొరకు (sym_సూచీ = 0; sym_సూచీ < చివర_sym; ++sym_సూచీ) {
        sym = &((ElfW(Sym) *)symtab->దత్తాంశం)[sym_సూచీ];
        ఒకవేళ (sym->st_విలువ) {
            name = (అక్షరం *) symtab->link->దత్తాంశం + sym->st_name;
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            sym_vis = ELFW(ST_VISIBILITY)(sym->st_other);
            ఒకవేళ (sym_bind == STB_GLOBAL && sym_vis == STV_DEFAULT)
                చిహ్నం_cb(ctx, name, (శూన్య*)(uintptr_t)sym->st_విలువ);
        }
    }
}

/* list elf symbol names and values */
LIBTCCAPI శూన్య tcc_list_symbols(TCCState *s, శూన్య *ctx,
    శూన్య (*చిహ్నం_cb)(శూన్య *ctx, స్థిరరాశి అక్షరం *name, స్థిరరాశి శూన్య *val))
{
    list_elf_symbols(s, ctx, చిహ్నం_cb);
}

#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
స్థిర శూన్య
సంస్కరణ_కూడు (TCCState *s1)
{
    పూర్ణాంకం i;
    ElfW(Sym) *sym;
    ElfW(Verneed) *vn = ఖాళీ;
    Section *symtab;
    పూర్ణాంకం sym_సూచీ, చివర_sym, nb_versions = 2, nb_entries = 0;
    ElfW(Half) *versym;
    స్థిరరాశి అక్షరం *name;

    ఒకవేళ (0 == nb_sym_versions)
        తిరిగి;
    versym_section = new_section(s1, ".gnu.version", SHT_GNU_versym, SHF_ALLOC);
    versym_section->sh_entsize = పరిమాణం(ElfW(Half));
    versym_section->link = s1->dynsym;

    /* add needed symbols */
    symtab = s1->dynsym;
    చివర_sym = symtab->దత్తాంశం_స్థానభ్రంశం / పరిమాణం (ElfSym);
    versym = section_ptr_కూడు(versym_section, చివర_sym * పరిమాణం(ElfW(Half)));
    కొరకు (sym_సూచీ = 1; sym_సూచీ < చివర_sym; ++sym_సూచీ) {
        పూర్ణాంకం dllindex, verndx;
        sym = &((ElfW(Sym) *)symtab->దత్తాంశం)[sym_సూచీ];
        name = (అక్షరం *) symtab->link->దత్తాంశం + sym->st_name;
        dllindex = కనుగొను_elf_sym(s1->dynsymtab_section, name);
        verndx = (dllindex && dllindex < nb_sym_గమ్యం_సంస్కరణ)
                 ? sym_గమ్యం_సంస్కరణ[dllindex] : -1;
        ఒకవేళ (verndx >= 0
            /* XXX: on android, clang refuses to link with a libtcc.so made by tcc
               when defined symbols have a version > 1 or when the version is '0'.
               Whereas version '1' for example for 'signal' in an exe defeats
               bcheck's signal_redir. */
            && (sym->st_shndx == SHN_UNDEF || (s1->output_type & TCC_OUTPUT_EXE))
            ) {
            ఒకవేళ (!sym_versions[verndx].బహిర్గతం_సూచీ)
              sym_versions[verndx].బహిర్గతం_సూచీ = nb_versions++;
            versym[sym_సూచీ] = sym_versions[verndx].బహిర్గతం_సూచీ;
        } లేకపోతే {
            versym[sym_సూచీ] = 1; /* (*global*) */
        }
        //printf("SYM %d %s\n", versym[sym_index], name);
    }
    /* generate verneed section, but not when it will be empty.  Some
       dynamic linkers look at their contents even when DTVERNEEDNUM and
       section size is zero.  */
    ఒకవేళ (nb_versions > 2) {
        verneed_section = new_section(s1, ".gnu.version_r",
                                      SHT_GNU_verneed, SHF_ALLOC);
        verneed_section->link = s1->dynsym->link;
        కొరకు (i = nb_sym_versions; i-- > 0;) {
            నిర్మాణం sym_సంస్కరణ *sv = &sym_versions[i];
            పూర్ణాంకం n_same_libs = 0, prev;
            కొలత_t vnofs;
            ElfW(Vernaux) *vna = 0;
            ఒకవేళ (sv->బహిర్గతం_సూచీ < 1)
              కొనసాగు;

            /* make sure that a DT_NEEDED tag is put */
            /* abitest-tcc fails on older i386-linux with "ld-linux.so.2" DT_NEEDED
               ret_int_test... Inconsistency detected by ld.so: dl-minimal.c: 148:
               realloc: Assertion `ptr == alloc_last_block' failed! */
            ఒకవేళ (strcmp(sv->lib, "ld-linux.so.2"))
                tcc_కూడు_dllref(s1, sv->lib, 0);

            vnofs = section_కూడు(verneed_section, పరిమాణం(*vn), 1);
            vn = (ElfW(Verneed)*)(verneed_section->దత్తాంశం + vnofs);
            vn->vn_సంస్కరణ = 1;
            vn->vn_file = put_elf_str(verneed_section->link, sv->lib);
            vn->vn_aux = పరిమాణం (*vn);
            చేయి {
                prev = sv->prev_same_lib;
                ఒకవేళ (sv->బహిర్గతం_సూచీ > 0) {
                    vna = section_ptr_కూడు(verneed_section, పరిమాణం(*vna));
                    vna->vna_hash = elf_hash ((స్థిరరాశి గుర్తులేని అక్షరం *)sv->సంస్కరణ);
                    vna->vna_flags = 0;
                    vna->vna_other = sv->బహిర్గతం_సూచీ;
                    sv->బహిర్గతం_సూచీ = -2;
                    vna->vna_name = put_elf_str(verneed_section->link, sv->సంస్కరణ);
                    vna->vna_తదుపరి = పరిమాణం (*vna);
                    //printf("LIB %d %s %s\n", vna->vna_other, sv->lib, verneed_section->link->data + vna->vna_name);
                    n_same_libs++;
                }
                ఒకవేళ (prev >= 0)
                  sv = &sym_versions[prev];
            } అయితే(prev >= 0);
            vna->vna_తదుపరి = 0;
            vn = (ElfW(Verneed)*)(verneed_section->దత్తాంశం + vnofs);
            vn->vn_cnt = n_same_libs;
            vn->vn_తదుపరి = పరిమాణం(*vn) + n_same_libs * పరిమాణం(*vna);
            nb_entries++;
        }
        ఒకవేళ (vn)
          vn->vn_తదుపరి = 0;
        verneed_section->sh_info = nb_entries;
    }
    dt_verneednum = nb_entries;
}
#అయితే_ముగింపు /* ndef ELF_OBJ_ONLY */

/* catch .tbss also */
స్థిర పూర్ణాంకం IS_BSS(TCCState *s1, పూర్ణాంకం ndx)
{
    తిరిగి ndx == SHN_COMMON
     || (ndx < s1->nb_sections
         && s1->sections[ndx]->sh_type == SHT_NOBITS);
}

/* add an elf symbol : check if it is already defined and patch
   it. Return symbol index. NOTE that sh_num can be SHN_UNDEF. */
ST_FUNC పూర్ణాంకం సమితి_elf_sym(Section *s, addr_t విలువ, గుర్తులేని దీర్ఘ కొలత,
                       పూర్ణాంకం info, పూర్ణాంకం other, పూర్ణాంకం shndx, స్థిరరాశి అక్షరం *name)
{
    TCCState *s1 = s->s1;
    ElfW(Sym) *esym;
    పూర్ణాంకం sym_bind, sym_సూచీ, sym_type, esym_bind;
    గుర్తులేని అక్షరం sym_vis, esym_vis, new_vis;

    sym_bind = ELFW(ST_BIND)(info);
    sym_type = ELFW(ST_TYPE)(info);
    sym_vis = ELFW(ST_VISIBILITY)(other);

    ఒకవేళ (sym_bind != STB_LOCAL) {
        /* we search global or weak symbols */
        sym_సూచీ = కనుగొను_elf_sym(s, name);
        ఒకవేళ (!sym_సూచీ)
            వెళ్ళు do_def;
        esym = &((ElfW(Sym) *)s->దత్తాంశం)[sym_సూచీ];
        ఒకవేళ (esym->st_విలువ == విలువ && esym->st_కొలత == కొలత && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            తిరిగి sym_సూచీ;
        ఒకవేళ (esym->st_shndx != SHN_UNDEF) {
            esym_bind = ELFW(ST_BIND)(esym->st_info);
            /* propagate the most constraining visibility */
            /* STV_DEFAULT(0)<STV_PROTECTED(3)<STV_HIDDEN(2)<STV_INTERNAL(1) */
            esym_vis = ELFW(ST_VISIBILITY)(esym->st_other);
            ఒకవేళ (esym_vis == STV_DEFAULT) {
                new_vis = sym_vis;
            } లేకపోతే ఒకవేళ (sym_vis == STV_DEFAULT) {
                new_vis = esym_vis;
            } లేకపోతే {
                new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
            }
            esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
                             | new_vis;
            ఒకవేళ (shndx == SHN_UNDEF) {
                /* ignore adding of undefined symbol if the
                   corresponding symbol is already defined */
            } లేకపోతే ఒకవేళ (sym_bind == STB_GLOBAL && esym_bind == STB_WEAK) {
                /* global overrides weak, so patch */
                వెళ్ళు do_patch;
            } లేకపోతే ఒకవేళ (sym_bind == STB_WEAK && esym_bind == STB_GLOBAL) {
                /* weak is ignored if already global */
            } లేకపోతే ఒకవేళ (sym_bind == STB_WEAK && esym_bind == STB_WEAK) {
                /* keep first-found weak definition, ignore subsequents */
            } లేకపోతే ఒకవేళ (sym_vis == STV_HIDDEN || sym_vis == STV_అంతర్గత) {
                /* ignore hidden symbols after */
            } లేకపోతే ఒకవేళ (s->sh_flags & SHF_DYNSYM) {
                /* we accept that two DLL define the same symbol */
            } లేకపోతే ఒకవేళ (!IS_BSS(s1, shndx) && IS_BSS(s1, esym->st_shndx)) {
                /* data symbol gets precedence over common/bss */
                వెళ్ళు do_patch;
            } లేకపోతే ఒకవేళ (IS_BSS(s1, shndx)) {
                /* data symbol keeps precedence over common/bss */
	    } లేకపోతే ఒకవేళ (esym->st_other & ST_ASM_సమితి) {
		/* If the existing symbol came from an asm .set
		   we can override.  */
		వెళ్ళు do_patch;
            } లేకపోతే {
#ఒకవేళ 0
                రాయి("new_bind=%x new_shndx=%x new_vis=%x old_bind=%x old_shndx=%x old_vis=%x\n",
                       sym_bind, shndx, new_vis, esym_bind, esym->st_shndx, esym_vis);
#అయితే_ముగింపు
                tcc_error_noabort("link symbol '%s' defined twice", name);
            }
        } లేకపోతే {
            esym->st_other = other;
        do_patch:
            esym->st_info = ELFW(ST_INFO)(sym_bind, sym_type);
            esym->st_shndx = shndx;
            esym->st_విలువ = విలువ;
            esym->st_కొలత = కొలత;
        }
    } లేకపోతే {
    do_def:
        sym_సూచీ = put_elf_sym(s, విలువ, కొలత,
                                ELFW(ST_INFO)(sym_bind, sym_type), other,
                                shndx, name);
    }
    తిరిగి sym_సూచీ;
}

/* put relocation */
ST_FUNC శూన్య put_elf_reloca(Section *symtab, Section *s, గుర్తులేని దీర్ఘ స్థానభ్రంశం,
                            పూర్ణాంకం type, పూర్ణాంకం చిహ్నం, addr_t addend)
{
    TCCState *s1 = s->s1;
    అక్షరం buf[256];
    Section *sr;
    ElfW_Rel *rel;

    sr = s->reloc;
    ఒకవేళ (!sr) {
        /* if no relocation section, create it */
        snprintf(buf, పరిమాణం(buf), REL_SECTION_FMT, s->name);
        /* if the symtab is allocated, then we consider the relocation
           are also */
        sr = new_section(s->s1, buf, SHT_RELX, symtab->sh_flags);
        sr->sh_entsize = పరిమాణం(ElfW_Rel);
        sr->link = symtab;
        sr->sh_info = s->sh_అంకె;
        s->reloc = sr;
    }
    rel = section_ptr_కూడు(sr, పరిమాణం(ElfW_Rel));
    rel->r_స్థానభ్రంశం = స్థానభ్రంశం;
    rel->r_info = ELFW(R_INFO)(చిహ్నం, type);
#ఒకవేళ SHT_RELX == SHT_RELA
    rel->r_addend = addend;
#అయితే_ముగింపు
    ఒకవేళ (SHT_RELX != SHT_RELA && addend)
        tcc_error_noabort("non-zero addend on REL architecture");
}

ST_FUNC శూన్య put_elf_reloc(Section *symtab, Section *s, గుర్తులేని దీర్ఘ స్థానభ్రంశం,
                           పూర్ణాంకం type, పూర్ణాంకం చిహ్నం)
{
    put_elf_reloca(symtab, s, స్థానభ్రంశం, type, చిహ్నం, 0);
}

ST_FUNC నిర్మాణం sym_attr *get_sym_attr(TCCState *s1, పూర్ణాంకం సూచీ, పూర్ణాంకం alloc)
{
    పూర్ణాంకం n;
    నిర్మాణం sym_attr *tab;

    ఒకవేళ (సూచీ >= s1->nb_sym_attrs) {
        ఒకవేళ (!alloc)
            తిరిగి s1->sym_attrs;
        /* find immediately bigger power of 2 and reallocate array */
        n = 1;
        అయితే (సూచీ >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * పరిమాణం(*s1->sym_attrs));
        s1->sym_attrs = tab;
        memset(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * పరిమాణం(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    తిరిగి &s1->sym_attrs[సూచీ];
}

స్థిర శూన్య update_relocs(TCCState *s1, Section *s, పూర్ణాంకం *old_గమ్యం_new_syms, పూర్ణాంకం మొదటి_sym)
{
    పూర్ణాంకం i, type, sym_సూచీ;
    Section *sr;
    ElfW_Rel *rel;

    కొరకు(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        ఒకవేళ (sr->sh_type == SHT_RELX && sr->link == s) {
            for_each_elem(sr, 0, rel, ElfW_Rel) {
                sym_సూచీ = ELFW(R_SYM)(rel->r_info);
                type = ELFW(R_TYPE)(rel->r_info);
                ఒకవేళ ((sym_సూచీ -= మొదటి_sym) < 0)
                    కొనసాగు; /* zero sym_index in reloc (can happen with asm) */
                sym_సూచీ = old_గమ్యం_new_syms[sym_సూచీ];
                rel->r_info = ELFW(R_INFO)(sym_సూచీ, type);
            }
        }
    }
}

/* In an ELF file symbol table, the local symbols must appear below
   the global and weak ones. Since TCC cannot sort it while generating
   the code, we must do it after. All the relocation tables are also
   modified to take into account the symbol table sorting */
స్థిర శూన్య క్రమీకరించు_syms(TCCState *s1, Section *s)
{
    పూర్ణాంకం *old_గమ్యం_new_syms;
    ElfW(Sym) *new_syms;
    పూర్ణాంకం nb_syms, i;
    ElfW(Sym) *p, *q;

    nb_syms = s->దత్తాంశం_స్థానభ్రంశం / పరిమాణం(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * పరిమాణం(ElfW(Sym)));
    old_గమ్యం_new_syms = tcc_malloc(nb_syms * పరిమాణం(పూర్ణాంకం));

    /* first pass for local symbols */
    p = (ElfW(Sym) *)s->దత్తాంశం;
    q = new_syms;
    కొరకు(i = 0; i < nb_syms; i++) {
        ఒకవేళ (ELFW(ST_BIND)(p->st_info) == STB_LOCAL) {
            old_గమ్యం_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    /* save the number of local symbols in section header */
    ఒకవేళ( s->sh_కొలత )    /* this 'if' makes IDA happy */
        s->sh_info = q - new_syms;

    /* then second pass for non local symbols */
    p = (ElfW(Sym) *)s->దత్తాంశం;
    కొరకు(i = 0; i < nb_syms; i++) {
        ఒకవేళ (ELFW(ST_BIND)(p->st_info) != STB_LOCAL) {
            old_గమ్యం_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }

    /* we copy the new symbols to the old */
    జ్ఞాపకం_నకలు(s->దత్తాంశం, new_syms, nb_syms * పరిమాణం(ElfW(Sym)));
    tcc_free(new_syms);

    update_relocs(s1, s, old_గమ్యం_new_syms, 0);
    tcc_free(old_గమ్యం_new_syms);
}

#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
/* See: https://flapenguin.me/elf-dt-gnu-hash */
#నిర్వచించు	ELFCLASS_బిట్లు (PTR_కొలత * 8)

స్థిర Section *create_gnu_hash(TCCState *s1)
{
    పూర్ణాంకం nb_syms, i, ndef, nbuckets, symoffset, bloom_కొలత, bloom_జరుపు;
    ElfW(Sym) *p;
    Section *gnu_hash;
    Section *dynsym = s1->dynsym;
    Elf32_మాట *ptr;

    gnu_hash = new_section(s1, ".gnu.hash", SHT_GNU_HASH, SHF_ALLOC);
    gnu_hash->link = dynsym->hash->link;

    nb_syms = dynsym->దత్తాంశం_స్థానభ్రంశం / పరిమాణం(ElfW(Sym));

    /* count def symbols */
    ndef = 0;
    p = (ElfW(Sym) *)dynsym->దత్తాంశం;
    కొరకు(i = 0; i < nb_syms; i++, p++)
        ndef += p->st_shndx != SHN_UNDEF;

    /* calculate gnu hash sizes and fill header */
    nbuckets = ndef / 4 + 1;
    symoffset = nb_syms - ndef;
    bloom_జరుపు = PTR_కొలత == 8 ? 6 : 5;
    bloom_కొలత = 1; /* must be power of two */
    అయితే (ndef >= bloom_కొలత * (1 << (bloom_జరుపు - 3)))
	bloom_కొలత *= 2;
    ptr = section_ptr_కూడు(gnu_hash, 4 * 4 +
				    PTR_కొలత * bloom_కొలత +
				    nbuckets * 4 +
				    ndef * 4);
    ptr[0] = nbuckets;
    ptr[1] = symoffset;
    ptr[2] = bloom_కొలత;
    ptr[3] = bloom_జరుపు;
    తిరిగి gnu_hash;
}

స్థిర Elf32_మాట elf_gnu_hash (స్థిరరాశి గుర్తులేని అక్షరం *name)
{
    Elf32_మాట h = 5381;
    గుర్తులేని అక్షరం c;

    అయితే ((c = *name++))
        h = h * 33 + c;
    తిరిగి h;
}

స్థిర శూన్య update_gnu_hash(TCCState *s1, Section *gnu_hash)
{
    పూర్ణాంకం *old_గమ్యం_new_syms;
    ElfW(Sym) *new_syms;
    పూర్ణాంకం nb_syms, i, nbuckets, bloom_కొలత, bloom_జరుపు;
    ElfW(Sym) *p, *q;
    Section *vs;
    Section *dynsym = s1->dynsym;
    Elf32_మాట *ptr, *buckets, *chain, *hash;
    గుర్తులేని పూర్ణాంకం *nextbuck;
    addr_t *bloom;
    గుర్తులేని అక్షరం *strtab;
    నిర్మాణం { పూర్ణాంకం మొదటి, చివరి; } *buck;

    strtab = dynsym->link->దత్తాంశం;
    nb_syms = dynsym->దత్తాంశం_స్థానభ్రంశం / పరిమాణం(ElfW(Sym));
    new_syms = tcc_malloc(nb_syms * పరిమాణం(ElfW(Sym)));
    old_గమ్యం_new_syms = tcc_malloc(nb_syms * పరిమాణం(పూర్ణాంకం));
    hash = tcc_malloc(nb_syms * పరిమాణం(Elf32_మాట));
    nextbuck = tcc_malloc(nb_syms * పరిమాణం(పూర్ణాంకం));

    /* calculate hashes and copy undefs */
    p = (ElfW(Sym) *)dynsym->దత్తాంశం;
    q = new_syms;
    కొరకు(i = 0; i < nb_syms; i++, p++) {
        ఒకవేళ (p->st_shndx == SHN_UNDEF) {
            old_గమ్యం_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
	లేకపోతే
	    hash[i] = elf_gnu_hash(strtab + p->st_name);
    }

    ptr = (Elf32_మాట *) gnu_hash->దత్తాంశం;
    nbuckets = ptr[0];
    bloom_కొలత = ptr[2];
    bloom_జరుపు = ptr[3];
    bloom = (addr_t *) (శూన్య *) &ptr[4];
    buckets = (Elf32_మాట*) (శూన్య *) &bloom[bloom_కొలత];
    chain = &buckets[nbuckets];
    buck = tcc_malloc(nbuckets * పరిమాణం(*buck));

    ఒకవేళ (gnu_hash->దత్తాంశం_స్థానభ్రంశం != 4 * 4 +
				 PTR_కొలత * bloom_కొలత +
				 nbuckets * 4 +
				 (nb_syms - (q - new_syms)) * 4)
	tcc_error_noabort ("gnu_hash size incorrect");

    /* find buckets */
    కొరకు(i = 0; i < nbuckets; i++)
	buck[i].మొదటి = -1;

    p = (ElfW(Sym) *)dynsym->దత్తాంశం;
    కొరకు(i = 0; i < nb_syms; i++, p++)
        ఒకవేళ (p->st_shndx != SHN_UNDEF) {
	    పూర్ణాంకం పాత్ర = hash[i] % nbuckets;

	    ఒకవేళ (buck[పాత్ర].మొదటి == -1)
		buck[పాత్ర].మొదటి = buck[పాత్ర].చివరి = i;
	    లేకపోతే {
		nextbuck[buck[పాత్ర].చివరి] = i;
		buck[పాత్ర].చివరి = i;
	    }
	}

    /* fill buckets/chains/bloom and sort symbols */
    p = (ElfW(Sym) *)dynsym->దత్తాంశం;
    కొరకు(i = 0; i < nbuckets; i++) {
	పూర్ణాంకం cur = buck[i].మొదటి;

	ఒకవేళ (cur != -1) {
	    buckets[i] = q - new_syms;
	    కొరకు (;;) {
                old_గమ్యం_new_syms[cur] = q - new_syms;
                *q++ = p[cur];
	        *chain++ = hash[cur] & ~1;
		bloom[(hash[cur] / ELFCLASS_బిట్లు) % bloom_కొలత] |=
		    (addr_t)1 << (hash[cur] % ELFCLASS_బిట్లు) |
		    (addr_t)1 << ((hash[cur] >> bloom_జరుపు) % ELFCLASS_బిట్లు);
		ఒకవేళ (cur == buck[i].చివరి)
		    ఆపు;
		cur = nextbuck[cur];
	    }
	    chain[-1] |= 1;
	}
    }

    జ్ఞాపకం_నకలు(dynsym->దత్తాంశం, new_syms, nb_syms * పరిమాణం(ElfW(Sym)));
    tcc_free(new_syms);
    tcc_free(hash);
    tcc_free(buck);
    tcc_free(nextbuck);

    update_relocs(s1, dynsym, old_గమ్యం_new_syms, 0);

    /* modify the versions */
    vs = versym_section;
    ఒకవేళ (vs) {
	ElfW(Half) *newver, *versym = (ElfW(Half) *)vs->దత్తాంశం;

	ఒకవేళ (1/*versym*/) {
            newver = tcc_malloc(nb_syms * పరిమాణం(*newver));
	    కొరకు (i = 0; i < nb_syms; i++)
	        newver[old_గమ్యం_new_syms[i]] = versym[i];
	    జ్ఞాపకం_నకలు(vs->దత్తాంశం, newver, nb_syms * పరిమాణం(*newver));
	    tcc_free(newver);
	}
    }

    tcc_free(old_గమ్యం_new_syms);

    /* rebuild hash */
    ptr = (Elf32_మాట *) dynsym->hash->దత్తాంశం;
    rebuild_hash(dynsym, ptr[0]);
}
#అయితే_ముగింపు /* ELF_OBJ_ONLY */

/* relocate symbol table, resolve undefined symbols if do_resolve is
   true and output error if undefined symbol. */
ST_FUNC శూన్య relocate_syms(TCCState *s1, Section *symtab, పూర్ణాంకం do_resolve)
{
    ElfW(Sym) *sym;
    పూర్ణాంకం sym_bind, sh_అంకె;
    స్థిరరాశి అక్షరం *name;

    for_each_elem(symtab, 1, sym, ElfW(Sym)) {
        sh_అంకె = sym->st_shndx;
        ఒకవేళ (sh_అంకె == SHN_UNDEF) {
            ఒకవేళ (do_resolve == 2) /* relocating dynsym */
                కొనసాగు;
            name = (అక్షరం *) s1->symtab->link->దత్తాంశం + sym->st_name;
            /* Use ld.so to resolve symbol for us (for tcc -run) */
            ఒకవేళ (do_resolve) {
#ఒకవేళ defined TCC_IS_NATIVE && !defined TCC_లక్ష్యం_PE
                /* dlsym() needs the undecorated name.  */
                స్థిరరాశి అక్షరం *name_ud = &name[s1->leading_underscore];
                శూన్య *addr = ఖాళీ;
                ఒకవేళ (!s1->nostdlib)
                    addr = dlsym(RTLD_DEFAULT, name_ud);
		ఒకవేళ (addr == ఖాళీ) {
		    పూర్ణాంకం i;
		    కొరకు (i = 0; i < s1->nb_loaded_dlls; i++)
                        ఒకవేళ ((addr = dlsym(s1->loaded_dlls[i]->handle, name_ud)))
			    ఆపు;
		}
                ఒకవేళ (addr) {
                    sym->st_విలువ = (addr_t) addr;
#నిర్వచితమైతే DEBUG_RELOC
		    రాయి ("relocate_sym: %s -> 0x%lx\n", name, sym->st_విలువ);
#అయితే_ముగింపు
                    వెళ్ళు దొరికింది;
                }
#అయితే_ముగింపు
            /* if dynamic symbol exist, it will be used in relocate_section */
            } లేకపోతే ఒకవేళ (s1->dynsym && కనుగొను_elf_sym(s1->dynsym, name))
                వెళ్ళు దొరికింది;
            /* XXX: _fp_hw seems to be part of the ABI, so we ignore
               it */
            ఒకవేళ (!strcmp(name, "_fp_hw"))
                వెళ్ళు దొరికింది;
            /* only weak symbols are accepted to be undefined. Their
               value is zero */
            sym_bind = ELFW(ST_BIND)(sym->st_info);
            ఒకవేళ (sym_bind == STB_WEAK)
                sym->st_విలువ = 0;
            లేకపోతే
                tcc_error_noabort("unresolved reference to '%s'", name);

        } లేకపోతే ఒకవేళ (sh_అంకె < SHN_LORESERVE) {
            /* add section base */
            sym->st_విలువ += s1->sections[sym->st_shndx]->sh_addr;
        }
    దొరికింది: ;
    }
}

/* relocate a given section (CPU dependent) by applying the relocations
   in the associated relocation section */
స్థిర శూన్య relocate_section(TCCState *s1, Section *s, Section *sr)
{
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    పూర్ణాంకం type, sym_సూచీ;
    గుర్తులేని అక్షరం *ptr;
    addr_t tgt, addr;
    పూర్ణాంకం is_dwarf = s->sh_అంకె >= s1->dwlo && s->sh_అంకె < s1->dwhi;

    qrel = (ElfW_Rel *)sr->దత్తాంశం;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
	ఒకవేళ (s->దత్తాంశం == ఖాళీ) /* bss */
	    కొనసాగు;
        ptr = s->దత్తాంశం + rel->r_స్థానభ్రంశం;
        sym_సూచీ = ELFW(R_SYM)(rel->r_info);
        sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
        type = ELFW(R_TYPE)(rel->r_info);
        tgt = sym->st_విలువ;
#ఒకవేళ SHT_RELX == SHT_RELA
        tgt += rel->r_addend;
#అయితే_ముగింపు
        ఒకవేళ (is_dwarf && type == R_దత్తాంశం_32_DW
            && sym->st_shndx >= s1->dwlo && sym->st_shndx < s1->dwhi) {
            /* dwarf section relocation to each other */
            add32le(ptr, tgt - s1->sections[sym->st_shndx]->sh_addr);
            కొనసాగు;
        }
        addr = s->sh_addr + rel->r_స్థానభ్రంశం;
        relocate(s1, rel, type, ptr, addr, tgt);
    }

#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
    /* if the relocation is allocated, we change its symbol table */
    ఒకవేళ (sr->sh_flags & SHF_ALLOC) {
        sr->link = s1->dynsym;
        ఒకవేళ (s1->output_type & TCC_OUTPUT_DYN) {
            కొలత_t r = (uint8_t*)qrel - sr->దత్తాంశం;
            ఒకవేళ (పరిమాణం ((Stab_Sym*)0)->n_విలువ < PTR_కొలత
                && 0 == strcmp(s->name, ".stab"))
                r = 0; /* cannot apply 64bit relocation to 32bit value */
            sr->దత్తాంశం_స్థానభ్రంశం = sr->sh_కొలత = r;
#నిర్వచితమైతే CONFIG_TCC_PIE
            ఒకవేళ (r && (s->sh_flags & SHF_EXECINSTR))
                tcc_warning("%d relocations to %s", (గుర్తులేని)(r / పరిమాణం *qrel), s->name);
#అయితే_ముగింపు
        }
    }
#అయితే_ముగింపు

#నిర్వచితమైతే TCC_లక్ష్యం_RISCV64
    dynarray_reset(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries);
#అయితే_ముగింపు
}

/* relocate all sections */
ST_FUNC శూన్య relocate_sections(TCCState *s1)
{
    పూర్ణాంకం i;
    Section *s, *sr;

    కొరకు (i = 1; i < s1->nb_sections; ++i) {
        sr = s1->sections[i];
        ఒకవేళ (sr->sh_type != SHT_RELX)
            కొనసాగు;
        s = s1->sections[sr->sh_info];
#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_MACHO
        ఒకవేళ (s != s1->got
            || s1->static_link
            || s1->output_type == TCC_OUTPUT_జ్ఞాపకం)
#అయితే_ముగింపు
        {
            relocate_section(s1, s, sr);
        }
#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
        ఒకవేళ (sr->sh_flags & SHF_ALLOC) {
            ElfW_Rel *rel;
            /* relocate relocation table in 'sr' */
            for_each_elem(sr, 0, rel, ElfW_Rel)
                rel->r_స్థానభ్రంశం += s->sh_addr;
        }
#అయితే_ముగింపు
    }
}

#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
/* count the number of dynamic relocations so that we can reserve
   their space */
స్థిర పూర్ణాంకం prepare_dynamic_rel(TCCState *s1, Section *sr)
{
    పూర్ణాంకం లెక్క_2 = 0;
#ఒకవేళ defined(TCC_లక్ష్యం_I386) || defined(TCC_లక్ష్యం_X86_64) || \
    defined(TCC_లక్ష్యం_ARM) || defined(TCC_లక్ష్యం_ARM64) || \
    defined(TCC_లక్ష్యం_RISCV64)
    ElfW_Rel *rel;
    for_each_elem(sr, 0, rel, ElfW_Rel) {
        పూర్ణాంకం sym_సూచీ = ELFW(R_SYM)(rel->r_info);
        పూర్ణాంకం type = ELFW(R_TYPE)(rel->r_info);
        ఎంపిక(type) {
#ఒకవేళ defined(TCC_లక్ష్యం_I386)
        స్థితి R_386_32:
            ఒకవేళ (!get_sym_attr(s1, sym_సూచీ, 0)->dyn_సూచీ
                && ((ElfW(Sym)*)symtab_section->దత్తాంశం + sym_సూచీ)->st_shndx == SHN_UNDEF) {
                /* don't fixup unresolved (weak) symbols */
                rel->r_info = ELFW(R_INFO)(sym_సూచీ, R_386_RELATIVE);
                ఆపు;
            }
#లేదావేళ defined(TCC_లక్ష్యం_X86_64)
        స్థితి R_X86_64_32:
        స్థితి R_X86_64_32S:
        స్థితి R_X86_64_64:
#లేదావేళ defined(TCC_లక్ష్యం_ARM)
        స్థితి R_ARM_ABS32:
        స్థితి R_ARM_TARGET1:
#లేదావేళ defined(TCC_లక్ష్యం_ARM64)
        స్థితి R_AARCH64_ABS32:
        స్థితి R_AARCH64_ABS64:
#లేదావేళ defined(TCC_లక్ష్యం_RISCV64)
        స్థితి R_RISCV_32:
        స్థితి R_RISCV_64:
#అయితే_ముగింపు
            లెక్క_2++;
            ఆపు;
#ఒకవేళ defined(TCC_లక్ష్యం_I386)
        స్థితి R_386_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    ఒకవేళ (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_సూచీ, R_386_PLT32);
	        ఆపు;
	    }
	}
#లేదావేళ defined(TCC_లక్ష్యం_X86_64)
        స్థితి R_X86_64_PC32:
	{
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
            /* Hidden defined symbols can and must be resolved locally.
               We're misusing a PLT32 reloc for this, as that's always
               resolved to its address even in shared libs.  */
	    ఒకవేళ (sym->st_shndx != SHN_UNDEF &&
		ELFW(ST_VISIBILITY)(sym->st_other) == STV_HIDDEN) {
                rel->r_info = ELFW(R_INFO)(sym_సూచీ, R_X86_64_PLT32);
	        ఆపు;
	    }
	}
#లేదావేళ defined(TCC_లక్ష్యం_ARM64)
        స్థితి R_AARCH64_PREL32:
#అయితే_ముగింపు
            ఒకవేళ (s1->output_type != TCC_OUTPUT_DLL)
                ఆపు;
            ఒకవేళ (get_sym_attr(s1, sym_సూచీ, 0)->dyn_సూచీ)
                లెక్క_2++;
            ఆపు;
        అప్రమేయ:
            ఆపు;
        }
    }
#అయితే_ముగింపు
    తిరిగి లెక్క_2;
}
#అయితే_ముగింపు

#నిర్వచితమైతే NEED_BUILD_GOT
స్థిర పూర్ణాంకం build_got(TCCState *s1)
{
    /* if no got, then create it */
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    s1->got->sh_entsize = 4;
    /* keep space for _DYNAMIC pointer and two dummy got entries */
    section_ptr_కూడు(s1->got, 3 * PTR_కొలత);
    తిరిగి సమితి_elf_sym(symtab_section, 0, 0, ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
        0, s1->got->sh_అంకె, "_GLOBAL_OFFSET_TABLE_");
}

/* Create a GOT and (for function call) a PLT entry corresponding to a symbol
   in s1->symtab. When creating the dynamic symbol table entry for the GOT
   relocation, use 'size' and 'info' for the corresponding symbol metadata.
   Returns the offset of the GOT or (if any) PLT entry. */
స్థిర నిర్మాణం sym_attr * put_got_నమోదు(TCCState *s1, పూర్ణాంకం dyn_reloc_type,
                                       పూర్ణాంకం sym_సూచీ)
{
    పూర్ణాంకం need_plt_నమోదు;
    స్థిరరాశి అక్షరం *name;
    ElfW(Sym) *sym;
    నిర్మాణం sym_attr *attr;
    గుర్తులేని got_స్థానభ్రంశం;
    అక్షరం plt_name[200];
    పూర్ణాంకం len;
    Section *s_rel;

    need_plt_నమోదు = (dyn_reloc_type == R_JMP_స్థానం);
    attr = get_sym_attr(s1, sym_సూచీ, 1);

    /* In case a function is both called and its address taken 2 GOT entries
       are created, one for taking the address (GOT) and the other for the PLT
       entry (PLTGOT).  */
    ఒకవేళ (need_plt_నమోదు ? attr->plt_స్థానభ్రంశం : attr->got_స్థానభ్రంశం)
        తిరిగి attr;

    s_rel = s1->got;
    ఒకవేళ (need_plt_నమోదు) {
        ఒకవేళ (!s1->plt) {
            s1->plt = new_section(s1, ".plt", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
            s1->plt->sh_entsize = 4;
        }
        s_rel = s1->plt;
    }

    /* create the GOT entry */
    got_స్థానభ్రంశం = s1->got->దత్తాంశం_స్థానభ్రంశం;
    section_ptr_కూడు(s1->got, PTR_కొలత);

    /* Create the GOT relocation that will insert the address of the object or
       function of interest in the GOT entry. This is a static relocation for
       memory output (dlsym will give us the address of symbols) and dynamic
       relocation otherwise (executable and DLLs). The relocation should be
       done lazily for GOT entry with *_JUMP_SLOT relocation type (the one
       associated to a PLT entry) but is currently done at load time for an
       unknown reason. */

    sym = &((ElfW(Sym) *) symtab_section->దత్తాంశం)[sym_సూచీ];
    name = (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name;
    //printf("sym %d %s\n", need_plt_entry, name);

    ఒకవేళ (s1->dynsym) {
	ఒకవేళ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
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
	    put_elf_reloc(s1->dynsym, s1->got, got_స్థానభ్రంశం, R_RELATIVE,
			  sym_సూచీ);
	} లేకపోతే {
	    ఒకవేళ (0 == attr->dyn_సూచీ)
                attr->dyn_సూచీ = సమితి_elf_sym(s1->dynsym, sym->st_విలువ,
                                              sym->st_కొలత, sym->st_info, 0,
                                              sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s_rel, got_స్థానభ్రంశం, dyn_reloc_type,
			  attr->dyn_సూచీ);
	}
    } లేకపోతే {
        put_elf_reloc(symtab_section, s1->got, got_స్థానభ్రంశం, dyn_reloc_type,
                      sym_సూచీ);
    }

    ఒకవేళ (need_plt_నమోదు) {
        attr->plt_స్థానభ్రంశం = create_plt_నమోదు(s1, got_స్థానభ్రంశం, attr);

        /* create a symbol 'sym@plt' for the PLT jump vector */
        len = అక్షరశ్రేణి_పొడవు(name);
        ఒకవేళ (len > పరిమాణం plt_name - 5)
            len = పరిమాణం plt_name - 5;
        జ్ఞాపకం_నకలు(plt_name, name, len);
        strcpy(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_స్థానభ్రంశం, 0,
            ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0, s1->plt->sh_అంకె, plt_name);
    } లేకపోతే {
        attr->got_స్థానభ్రంశం = got_స్థానభ్రంశం;
    }

    తిరిగి attr;
}

/* build GOT and PLT entries */
/* Two passes because R_JMP_SLOT should become first. Some targets
   (arm, arm64) do not allow mixing R_JMP_SLOT and R_GLOB_DAT. */
ST_FUNC శూన్య build_got_entries(TCCState *s1, పూర్ణాంకం got_sym)
{
    Section *s;
    ElfW_Rel *rel;
    ElfW(Sym) *sym;
    పూర్ణాంకం i, type, gotplt_నమోదు, reloc_type, sym_సూచీ;
    నిర్మాణం sym_attr *attr;
    పూర్ణాంకం pass = 0;
redo:
    కొరకు(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ఒకవేళ (s->sh_type != SHT_RELX)
            కొనసాగు;
        /* no need to handle got relocations */
        ఒకవేళ (s->link != symtab_section)
            కొనసాగు;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_నమోదు = gotplt_నమోదు_type(type);
            ఒకవేళ (gotplt_నమోదు == -1) {
                tcc_error_noabort ("Unknown relocation type for got: %d", type);
                కొనసాగు;
            }
            sym_సూచీ = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];

            ఒకవేళ (gotplt_నమోదు == NO_GOTPLT_నమోదు) {
                కొనసాగు;
            }

            /* Automatically create PLT/GOT [entry] if it is an undefined
	       reference (resolved at runtime), or the symbol is absolute,
	       probably created by tcc_add_symbol, and thus on 64-bit
	       targets might be too far from application code.  */
            ఒకవేళ (gotplt_నమోదు == AUTO_GOTPLT_నమోదు) {
                ఒకవేళ (sym->st_shndx == SHN_UNDEF) {
                    ElfW(Sym) *esym;
		    పూర్ణాంకం dynindex;
                    ఒకవేళ (!PCRELATIVE_DLLPLT
                        && (s1->output_type & TCC_OUTPUT_DYN))
                        కొనసాగు;
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
		    ఒకవేళ (s1->dynsym) {
			/* dynsym isn't set for -run :-/  */
			dynindex = get_sym_attr(s1, sym_సూచీ, 0)->dyn_సూచీ;
			esym = (ElfW(Sym) *)s1->dynsym->దత్తాంశం + dynindex;
			ఒకవేళ (dynindex
			    && (ELFW(ST_TYPE)(esym->st_info) == STT_FUNC
				|| (ELFW(ST_TYPE)(esym->st_info) == STT_NOTYPE
				    && ELFW(ST_TYPE)(sym->st_info) == STT_FUNC)))
			    వెళ్ళు jmp_స్థానం;
		    }
                } లేకపోతే ఒకవేళ (sym->st_shndx == SHN_ABS) {
                    ఒకవేళ (sym->st_విలువ == 0) /* from tcc_add_btstub() */
                        కొనసాగు;
#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_ARM
                    ఒకవేళ (PTR_కొలత != 8)
                        కొనసాగు;
#అయితే_ముగింపు
                    /* from tcc_add_symbol(): on 64 bit platforms these
                       need to go through .got */
                } లేకపోతే
                    కొనసాగు;
            }

#నిర్వచితమైతే TCC_లక్ష్యం_I386
            ఒకవేళ ((type == R_386_PLT32 || type == R_386_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		ఒకవేళ (pass != 0)
		    కొనసాగు;
                rel->r_info = ELFW(R_INFO)(sym_సూచీ, R_386_PC32);
                కొనసాగు;
            }
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
            ఒకవేళ ((type == R_X86_64_PLT32 || type == R_X86_64_PC32) &&
		sym->st_shndx != SHN_UNDEF &&
                (ELFW(ST_VISIBILITY)(sym->st_other) != STV_DEFAULT ||
		 ELFW(ST_BIND)(sym->st_info) == STB_LOCAL ||
		 s1->output_type & TCC_OUTPUT_EXE)) {
		ఒకవేళ (pass != 0)
		    కొనసాగు;
                rel->r_info = ELFW(R_INFO)(sym_సూచీ, R_X86_64_PC32);
                కొనసాగు;
            }
#అయితే_ముగింపు
            reloc_type = సంకేతం_reloc(type);
            ఒకవేళ (reloc_type == -1) {
                tcc_error_noabort ("Unknown relocation type: %d", type);
                కొనసాగు;
            }

            ఒకవేళ (reloc_type != 0) {
        jmp_స్థానం:
	        ఒకవేళ (pass != 0)
                    కొనసాగు;
                reloc_type = R_JMP_స్థానం;
            } లేకపోతే {
	        ఒకవేళ (pass != 1)
                    కొనసాగు;
                reloc_type = R_GLOB_DAT;
            }

            ఒకవేళ (!s1->got)
                got_sym = build_got(s1);

            ఒకవేళ (gotplt_నమోదు == BUILD_GOT_ONLY)
                కొనసాగు;

            attr = put_got_నమోదు(s1, reloc_type, sym_సూచీ);

            ఒకవేళ (reloc_type == R_JMP_స్థానం)
                rel->r_info = ELFW(R_INFO)(attr->plt_sym, type);
        }
    }
    ఒకవేళ (++pass < 2)
        వెళ్ళు redo;
    /* .rel.plt refers to .got actually */
    ఒకవేళ (s1->plt && s1->plt->reloc)
        s1->plt->reloc->sh_info = s1->got->sh_అంకె;
    ఒకవేళ (got_sym) /* set size */
        ((ElfW(Sym)*)symtab_section->దత్తాంశం)[got_sym].st_కొలత = s1->got->దత్తాంశం_స్థానభ్రంశం;
}
#అయితే_ముగింపు /* def NEED_BUILD_GOT */

ST_FUNC పూర్ణాంకం సమితి_global_sym(TCCState *s1, స్థిరరాశి అక్షరం *name, Section *sec, addr_t offs)
{
    పూర్ణాంకం shn = sec ? sec->sh_అంకె : offs || !name ? SHN_ABS : SHN_UNDEF;
    ఒకవేళ (sec && offs == -1)
        offs = sec->దత్తాంశం_స్థానభ్రంశం;
    తిరిగి సమితి_elf_sym(symtab_section, offs, 0,
        ELFW(ST_INFO)(name ? STB_GLOBAL : STB_LOCAL, STT_NOTYPE), 0, shn, name);
}

స్థిర శూన్య కూడు_init_array_నిర్వచిస్తుంది(TCCState *s1, స్థిరరాశి అక్షరం *section_name)
{
    Section *s;
    addr_t చివర_స్థానభ్రంశం;
    అక్షరం buf[1024];
    s = have_section(s1, section_name);
    ఒకవేళ (!s || !(s->sh_flags & SHF_ALLOC)) {
        చివర_స్థానభ్రంశం = 0;
        s = పాఠ్యం_section;
    } లేకపోతే {
        చివర_స్థానభ్రంశం = s->దత్తాంశం_స్థానభ్రంశం;
    }
    snprintf(buf, పరిమాణం(buf), "__%s_start", section_name + 1);
    సమితి_global_sym(s1, buf, s, 0);
    snprintf(buf, పరిమాణం(buf), "__%s_end", section_name + 1);
    సమితి_global_sym(s1, buf, s, చివర_స్థానభ్రంశం);
}

ST_FUNC శూన్య కూడు_array (TCCState *s1, స్థిరరాశి అక్షరం *sec, పూర్ణాంకం c)
{
    Section *s;
    s = కనుగొను_section(s1, sec);
    s->sh_flags = shf_RELRO;
    s->sh_type = sec[1] == 'i' ? SHT_INIT_ARRAY : SHT_FINI_ARRAY;
    put_elf_reloc (s1->symtab, s, s->దత్తాంశం_స్థానభ్రంశం, R_దత్తాంశం_PTR, c);
    section_ptr_కూడు(s, PTR_కొలత);
}

#నిర్వచితమైతే CONFIG_TCC_BCHECK
ST_FUNC శూన్య tcc_కూడు_bcheck(TCCState *s1)
{
    ఒకవేళ (0 == s1->do_bounds_check)
        తిరిగి;
    section_ptr_కూడు(bounds_section, పరిమాణం(addr_t));
}
#అయితే_ముగింపు

/* set symbol to STB_LOCAL and resolve. The point is to not export it as
   a dynamic symbol to allow so's to have one each with a different value. */
స్థిర శూన్య సమితి_local_sym(TCCState *s1, స్థిరరాశి అక్షరం *name, Section *s, పూర్ణాంకం స్థానభ్రంశం)
{
    పూర్ణాంకం c = కనుగొను_elf_sym(s1->symtab, name);
    ఒకవేళ (c) {
        ElfW(Sym) *esym = (ElfW(Sym)*)s1->symtab->దత్తాంశం + c;
        esym->st_info = ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE);
        esym->st_విలువ = స్థానభ్రంశం;
        esym->st_shndx = s->sh_అంకె;
    }
}

/* avoid generating debug/test_coverage code for stub functions */
స్థిర శూన్య tcc_compile_string_no_debug(TCCState *s, స్థిరరాశి అక్షరం *str)
{
    పూర్ణాంకం save_do_debug = s->do_debug;
    పూర్ణాంకం save_test_coverage = s->test_coverage;

    s->do_debug = 0;
    s->test_coverage = 0;
    tcc_compile_string(s, str);
    s->do_debug = save_do_debug;
    s->test_coverage = save_test_coverage;
}

#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
స్థిర శూన్య put_ptr(TCCState *s1, Section *s, పూర్ణాంకం offs)
{
    పూర్ణాంకం c;
    c = సమితి_global_sym(s1, ఖాళీ, s, offs);
    s = దత్తాంశం_section;
    put_elf_reloc (s1->symtab, s, s->దత్తాంశం_స్థానభ్రంశం, R_దత్తాంశం_PTR, c);
    section_ptr_కూడు(s, PTR_కొలత);
}

ST_FUNC శూన్య tcc_కూడు_btstub(TCCState *s1)
{
    Section *s;
    పూర్ణాంకం n, o, *p;
    CString cstr;
    స్థిరరాశి అక్షరం *__rt_info = &"___rt_info"[!s1->leading_underscore];

    s = దత్తాంశం_section;
    /* Align to PTR_SIZE */
    section_కూడు(s, 0, PTR_కొలత);
    o = s->దత్తాంశం_స్థానభ్రంశం;
    /* create a struct rt_context (see tccrun.c) */
    ఒకవేళ (s1->dwarf) {
        put_ptr(s1, dwarf_పంక్తి_section, 0);
        put_ptr(s1, dwarf_పంక్తి_section, -1);
	ఒకవేళ (s1->dwarf >= 5)
            put_ptr(s1, dwarf_పంక్తి_str_section, 0);
	లేకపోతే
            put_ptr(s1, dwarf_str_section, 0);
    }
    లేకపోతే
    {
        put_ptr(s1, stab_section, 0);
        put_ptr(s1, stab_section, -1);
        put_ptr(s1, stab_section->link, 0);
    }

    /* skip esym_start/esym_end/elf_str (not loaded) */
    section_ptr_కూడు(s, 3 * PTR_కొలత);

    ఒకవేళ (s1->output_type == TCC_OUTPUT_జ్ఞాపకం && 0 == s1->dwarf) {
        put_ptr(s1, పాఠ్యం_section, 0);
    } లేకపోతే {
        /* prog_base : local nameless symbol with offset 0 at SHN_ABS */
        put_ptr(s1, ఖాళీ, 0);
#ఒకవేళ defined TCC_లక్ష్యం_MACHO
        /* adjust for __PAGEZERO */
        ఒకవేళ (s1->dwarf == 0 && s1->output_type == TCC_OUTPUT_EXE)
            write64le(దత్తాంశం_section->దత్తాంశం + దత్తాంశం_section->దత్తాంశం_స్థానభ్రంశం - PTR_కొలత,
	              (uint64_t)1 << 32);
#అయితే_ముగింపు
    }
    n = 3 * PTR_కొలత;
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (s1->do_bounds_check) {
        put_ptr(s1, bounds_section, 0);
        n -= PTR_కొలత;
    }
#అయితే_ముగింపు
    section_ptr_కూడు(s, n);
    p = section_ptr_కూడు(s, 2 * పరిమాణం (పూర్ణాంకం));
    p[0] = s1->rt_అంకె_callers;
    p[1] = s1->dwarf;
    // if (s->data_offset - o != 10*PTR_SIZE + 2*sizeof (int)) exit(99);

    ఒకవేళ (s1->output_type == TCC_OUTPUT_జ్ఞాపకం) {
        సమితి_global_sym(s1, __rt_info, s, o);
        తిరిగి;
    }

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern void __bt_init(),__bt_exit(),__bt_init_dll();"
        "static void *__rt_info[];"
        "__attribute__((constructor)) static void __bt_init_rt(){");
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    ఒకవేళ (s1->output_type == TCC_OUTPUT_DLL)
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        cstr_printf(&cstr, "__bt_init_dll(%d);", s1->do_bounds_check);
#లేకపోతే
        cstr_printf(&cstr, "__bt_init_dll(0);");
#అయితే_ముగింపు
#అయితే_ముగింపు
    cstr_printf(&cstr, "__bt_init(__rt_info,%d);}",
        s1->output_type != TCC_OUTPUT_DLL);
    /* In case dlcose is called by application */
    cstr_printf(&cstr,
        "__attribute__((destructor)) static void __bt_exit_rt(){"
        "__bt_exit(__rt_info);}");
    tcc_compile_string_no_debug(s1, cstr.దత్తాంశం);
    cstr_free(&cstr);
    సమితి_local_sym(s1, __rt_info, s, o);
}
#అయితే_ముగింపు /* def CONFIG_TCC_BACKTRACE */

స్థిర శూన్య tcc_tcov_కూడు_file(TCCState *s1, స్థిరరాశి అక్షరం *filename)
{
    CString cstr;
    శూన్య *ptr;
    అక్షరం wd[1024];

    ఒకవేళ (tcov_section == ఖాళీ)
        తిరిగి;
    section_ptr_కూడు(tcov_section, 1);
    write32le (tcov_section->దత్తాంశం, tcov_section->దత్తాంశం_స్థానభ్రంశం);

    cstr_new (&cstr);
    ఒకవేళ (filename[0] == '/')
        cstr_printf (&cstr, "%s.tcov", filename);
    లేకపోతే {
        getcwd (wd, పరిమాణం(wd));
        cstr_printf (&cstr, "%s/%s.tcov", wd, filename);
    }
    ptr = section_ptr_కూడు(tcov_section, cstr.కొలత + 1);
    strcpy((అక్షరం *)ptr, cstr.దత్తాంశం);
    unlink((అక్షరం *)ptr);
#నిర్వచితమైతే _WIN32
    normalize_slashes((అక్షరం *)ptr);
#అయితే_ముగింపు
    cstr_free (&cstr);

    cstr_new(&cstr);
    cstr_printf(&cstr,
        "extern char *__tcov_data[];"
        "extern void __store_test_coverage ();"
        "__attribute__((destructor)) static void __tcov_exit() {"
        "__store_test_coverage(__tcov_data);"
        "}");
    tcc_compile_string_no_debug(s1, cstr.దత్తాంశం);
    cstr_free(&cstr);
    సమితి_local_sym(s1, &"___tcov_data"[!s1->leading_underscore], tcov_section, 0);
}

#నిర్వచితమైతే TCC_లక్ష్యం_UNIX
/* add libc crt1/crti objects */
ST_FUNC శూన్య tccelf_కూడు_crtbegin(TCCState *s1)
{
#ఒకవేళ TARGETOS_OpenBSD
    ఒకవేళ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_కూడు_crt(s1, "crt0.o");
    ఒకవేళ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_కూడు_crt(s1, "crtbeginS.o");
    లేకపోతే
        tcc_కూడు_crt(s1, "crtbegin.o");
#లేదావేళ TARGETOS_FreeBSD || TARGETOS_NetBSD
    ఒకవేళ (s1->output_type != TCC_OUTPUT_DLL)
#ఒకవేళ TARGETOS_FreeBSD
        tcc_కూడు_crt(s1, "crt1.o");
#లేకపోతే
        tcc_కూడు_crt(s1, "crt0.o");
#అయితే_ముగింపు
    tcc_కూడు_crt(s1, "crti.o");
    ఒకవేళ (s1->static_link)
        tcc_కూడు_crt(s1, "crtbeginT.o");
    లేకపోతే ఒకవేళ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_కూడు_crt(s1, "crtbeginS.o");
    లేకపోతే
        tcc_కూడు_crt(s1, "crtbegin.o");
#లేదావేళ TARGETOS_ANDROID
    ఒకవేళ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_కూడు_crt(s1, "crtbegin_so.o");
    లేకపోతే
        tcc_కూడు_crt(s1, "crtbegin_dynamic.o");
#లేకపోతే
    ఒకవేళ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_కూడు_crt(s1, "crt1.o");
    tcc_కూడు_crt(s1, "crti.o");
#అయితే_ముగింపు
}

ST_FUNC శూన్య tccelf_కూడు_crtend(TCCState *s1)
{
#ఒకవేళ TARGETOS_OpenBSD
    ఒకవేళ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_కూడు_crt(s1, "crtendS.o");
    లేకపోతే
        tcc_కూడు_crt(s1, "crtend.o");
#లేదావేళ TARGETOS_FreeBSD || TARGETOS_NetBSD
    ఒకవేళ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_కూడు_crt(s1, "crtendS.o");
    లేకపోతే
        tcc_కూడు_crt(s1, "crtend.o");
    tcc_కూడు_crt(s1, "crtn.o");
#లేదావేళ TARGETOS_ANDROID
    ఒకవేళ (s1->output_type == TCC_OUTPUT_DLL)
        tcc_కూడు_crt(s1, "crtend_so.o");
    లేకపోతే
        tcc_కూడు_crt(s1, "crtend_android.o");
#లేకపోతే
    tcc_కూడు_crt(s1, "crtn.o");
#అయితే_ముగింపు
}
#అయితే_ముగింపు /* TCC_TARGET_UNIX */

#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_PE
/* add tcc runtime libraries */
ST_FUNC శూన్య tcc_కూడు_runtime(TCCState *s1)
{
    s1->filetype = 0;

#నిర్వచితమైతే CONFIG_TCC_BCHECK
    tcc_కూడు_bcheck(s1);
#అయితే_ముగింపు
    tcc_కూడు_pragma_libs(s1);

    /* add libc */
    ఒకవేళ (!s1->nostdlib) {
        పూర్ణాంకం lpthread = s1->option_pthread;

#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    ఒకవేళ (s1->output_type == TCC_OUTPUT_జ్ఞాపకం)
                tcc_కూడు_support(s1, "bcheck_run.o");
	    లేకపోతే
                tcc_కూడు_support(s1, "bcheck.o");
# ఒకవేళ !(TARGETOS_OpenBSD || TARGETOS_NetBSD)
            tcc_కూడు_library(s1, "dl");
# endif
            lpthread = 1;
        }
#అయితే_ముగింపు
#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
        ఒకవేళ (s1->do_backtrace) {
            ఒకవేళ (s1->output_type & TCC_OUTPUT_EXE)
                tcc_కూడు_support(s1, "bt-exe.o");
            ఒకవేళ (s1->output_type != TCC_OUTPUT_DLL)
                tcc_కూడు_support(s1, "bt-log.o");
            tcc_కూడు_btstub(s1);
            lpthread = 1;
        }
#అయితే_ముగింపు
        ఒకవేళ (lpthread)
            tcc_కూడు_library(s1, "pthread");
        tcc_కూడు_library(s1, "c");
#నిర్వచితమైతే TCC_LIBGCC
        ఒకవేళ (!s1->static_link) {
            ఒకవేళ (TCC_LIBGCC[0] == '/')
                tcc_కూడు_file(s1, TCC_LIBGCC);
            లేకపోతే
                tcc_కూడు_dll(s1, TCC_LIBGCC, AFF_PRINT_ERROR);
        }
#అయితే_ముగింపు
#ఒకవేళ defined TCC_లక్ష్యం_ARM && TARGETOS_FreeBSD
        tcc_కూడు_library(s1, "gcc_s"); // unwind code
#అయితే_ముగింపు
        ఒకవేళ (TCC_LIBTCC1[0]) {
            tcc_కూడు_support(s1, TCC_LIBTCC1);
            tcc_కూడు_library(s1, "c");
        }
#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_MACHO
        ఒకవేళ (s1->output_type != TCC_OUTPUT_జ్ఞాపకం)
            tccelf_కూడు_crtend(s1);
#అయితే_ముగింపు
    }
}
#అయితే_ముగింపు /* ndef TCC_TARGET_PE */

/* set _etext/_edata/_end  f=0:set  f=1:when_needed  f=2,3:just_update */
స్థిర శూన్య సమితి_linker_sym(TCCState *s1, స్థిరరాశి అక్షరం *name, Section *sec, పూర్ణాంకం f)
{
    పూర్ణాంకం sym_సూచీ, esym_సూచీ, defined;
    ElfW(Sym) *sym, *esym;
    sym_సూచీ = కనుగొను_elf_sym(symtab_section, name);
    sym = (ElfW(Sym) *)symtab_section->దత్తాంశం + sym_సూచీ;
    esym_సూచీ = కనుగొను_elf_sym(s1->dynsymtab_section, name);
    esym = (ElfW(Sym) *)s1->dynsymtab_section->దత్తాంశం + esym_సూచీ;
    defined = sym->st_shndx != SHN_UNDEF
        || (esym->st_shndx != SHN_UNDEF && esym->st_కొలత);
    ఎంపిక (f) {
    స్థితి 1: /* old symbols w/o '_' */
        ఒకవేళ (!(sym_సూచీ || esym_సూచీ) || defined)
            ఆపు;
    స్థితి 0:
        ఒకవేళ (defined) {
            tcc_warning("linker symbol '%s' already defined", name);
            ఆపు;
        }
        sym_సూచీ = సమితి_global_sym(s1, name, sec, -1);
        get_sym_attr(s1, sym_సూచీ, 1)->linker_sym = 1;
        ఆపు;
    అప్రమేయ: /* update (bss only) */
        ఒకవేళ (get_sym_attr(s1, sym_సూచీ, 0)->linker_sym)
            sym->st_విలువ = sec->దత్తాంశం_స్థానభ్రంశం;
    }
#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
    ఒకవేళ (name[0] == '_')
        సమితి_linker_sym(s1, name + 1, sec, f + 1);
#అయితే_ముగింపు
}

/* add various standard linker symbols (must be done after the
   sections are filled (for example after allocating common
   symbols)) */
స్థిర శూన్య tcc_కూడు_linker_symbols(TCCState *s1)
{
    అక్షరం buf[1024];
    పూర్ణాంకం i;
    Section *s;

    సమితి_linker_sym(s1, "_etext", పాఠ్యం_section, 0);
    సమితి_linker_sym(s1, "_edata", దత్తాంశం_section, 0);
    సమితి_linker_sym(s1, "_end", bss_section, 0);
#ఒకవేళ TARGETOS_OpenBSD
    సమితి_global_sym(s1, "__executable_start", ఖాళీ, ELF_ప్రారంభం_ADDR);
#అయితే_ముగింపు

#నిర్వచితమైతే TCC_లక్ష్యం_RISCV64
    /* XXX should be .sdata+0x800, not .data+0x800 */
    సమితి_global_sym(s1, "__global_pointer$", దత్తాంశం_section, 0x800);
#అయితే_ముగింపు
    /* horrible new standard ldscript defines */
    కూడు_init_array_నిర్వచిస్తుంది(s1, ".preinit_array");
    కూడు_init_array_నిర్వచిస్తుంది(s1, ".init_array");
    కూడు_init_array_నిర్వచిస్తుంది(s1, ".fini_array");
    /* add start and stop symbols for sections whose name can be
       expressed in C */
    కొరకు(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ఒకవేళ ((s->sh_flags & SHF_ALLOC)
            && (s->sh_type == SHT_PROGBITS || s->sh_type == SHT_NOBITS
                || s->sh_type == SHT_STRTAB)) {
            /* check if section name can be expressed in C */
            స్థిరరాశి అక్షరం *p0, *p;
            p0 = s->name;
            ఒకవేళ (*p0 == '.')
                ++p0;
            p = p0;
            కొరకు(;;) {
                పూర్ణాంకం c = *p;
                ఒకవేళ (!c)
                    ఆపు;
                ఒకవేళ (!isid(c) && !isnum(c))
                    వెళ్ళు తదుపరి_sec;
                p++;
            }
            snprintf(buf, పరిమాణం(buf), "__start_%s", p0);
            సమితి_global_sym(s1, buf, s, 0);
            snprintf(buf, పరిమాణం(buf), "__stop_%s", p0);
            సమితి_global_sym(s1, buf, s, -1);
        }
    తదుపరి_sec: ;
    }
}

ST_FUNC శూన్య resolve_common_syms(TCCState *s1)
{
    ElfW(Sym) *sym;

    /* Allocate common symbols in BSS.  */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ఒకవేళ (sym->st_shndx == SHN_COMMON && sym->st_కొలత) {
            /* symbol alignment is in st_value for SHN_COMMONs */
	    sym->st_విలువ = section_కూడు(bss_section, sym->st_కొలత,
					sym->st_విలువ);
            sym->st_shndx = bss_section->sh_అంకె;
        }
    }

    /* Now assign linker provided symbols their value.  */
    ఒకవేళ (s1->output_type != TCC_OUTPUT_DLL)
        tcc_కూడు_linker_symbols(s1);
}

#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
ST_FUNC శూన్య fill_got_నమోదు(TCCState *s1, ElfW_Rel *rel)
{
    పూర్ణాంకం sym_సూచీ = ELFW(R_SYM) (rel->r_info);
    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->దత్తాంశం)[sym_సూచీ];
    నిర్మాణం sym_attr *attr = get_sym_attr(s1, sym_సూచీ, 0);
    గుర్తులేని స్థానభ్రంశం = attr->got_స్థానభ్రంశం;

    ఒకవేళ (0 == స్థానభ్రంశం)
        తిరిగి;
    section_reserve(s1->got, స్థానభ్రంశం + PTR_కొలత);
#ఒకవేళ PTR_కొలత == 8
    write64le(s1->got->దత్తాంశం + స్థానభ్రంశం, sym->st_విలువ);
#లేకపోతే
    write32le(s1->got->దత్తాంశం + స్థానభ్రంశం, sym->st_విలువ);
#అయితే_ముగింపు
}

/* Perform relocation to GOT or PLT entries */
ST_FUNC శూన్య fill_got(TCCState *s1)
{
    Section *s;
    ElfW_Rel *rel;
    పూర్ణాంకం i;

    కొరకు(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ఒకవేళ (s->sh_type != SHT_RELX)
            కొనసాగు;
        /* no need to handle got relocations */
        ఒకవేళ (s->link != symtab_section)
            కొనసాగు;
        for_each_elem(s, 0, rel, ElfW_Rel) {
            ఎంపిక (ELFW(R_TYPE) (rel->r_info)) {
                స్థితి R_X86_64_GOT32:
                స్థితి R_X86_64_GOTPCREL:
		స్థితి R_X86_64_GOTPCRELX:
		స్థితి R_X86_64_REX_GOTPCRELX:
                స్థితి R_X86_64_PLT32:
                    fill_got_నమోదు(s1, rel);
                    ఆపు;
            }
        }
    }
}

/* See put_got_entry for a description.  This is the second stage
   where GOT references to local defined symbols are rewritten.  */
స్థిర శూన్య fill_local_got_entries(TCCState *s1)
{
    ElfW_Rel *rel;
    ఒకవేళ (!s1->got->reloc)
        తిరిగి;
    for_each_elem(s1->got->reloc, 0, rel, ElfW_Rel) {
	ఒకవేళ (ELFW(R_TYPE)(rel->r_info) == R_RELATIVE) {
	    పూర్ణాంకం sym_సూచీ = ELFW(R_SYM) (rel->r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *) symtab_section->దత్తాంశం)[sym_సూచీ];
	    నిర్మాణం sym_attr *attr = get_sym_attr(s1, sym_సూచీ, 0);
	    గుర్తులేని స్థానభ్రంశం = attr->got_స్థానభ్రంశం;
	    ఒకవేళ (స్థానభ్రంశం != rel->r_స్థానభ్రంశం - s1->got->sh_addr)
	        tcc_error_noabort("fill_local_got_entries: huh?");
	    rel->r_info = ELFW(R_INFO)(0, R_RELATIVE);
#ఒకవేళ SHT_RELX == SHT_RELA
	    rel->r_addend = sym->st_విలువ;
#లేకపోతే
	    /* All our REL architectures also happen to be 32bit LE.  */
	    write32le(s1->got->దత్తాంశం + స్థానభ్రంశం, sym->st_విలువ);
#అయితే_ముగింపు
	}
    }
}

/* Bind symbols of executable: resolve undefined symbols from exported symbols
   in shared libraries */
స్థిర శూన్య bind_exe_dynsyms(TCCState *s1, పూర్ణాంకం is_PIE)
{
    స్థిరరాశి అక్షరం *name;
    పూర్ణాంకం sym_సూచీ, సూచీ;
    ElfW(Sym) *sym, *esym;
    పూర్ణాంకం type;

    /* Resolve undefined symbols from dynamic symbols. When there is a match:
       - if STT_FUNC or STT_GNU_IFUNC symbol -> add it in PLT
       - if STT_OBJECT symbol -> add it in .bss section with suitable reloc */
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ఒకవేళ (sym->st_shndx == SHN_UNDEF
            /* bss symbols may be initialized in the shared library */
            || sym->st_shndx == SHN_COMMON
            || sym->st_shndx == bss_section->sh_అంకె) {
            name = (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name;
            sym_సూచీ = కనుగొను_elf_sym(s1->dynsymtab_section, name);
            esym = &((ElfW(Sym) *)s1->dynsymtab_section->దత్తాంశం)[sym_సూచీ];
            ఒకవేళ (sym_సూచీ && esym->st_shndx != SHN_UNDEF) {
                ఒకవేళ (is_PIE)
                    కొనసాగు;
                type = ELFW(ST_TYPE)(esym->st_info);
                ఒకవేళ ((type == STT_FUNC) || (type == STT_GNU_IFUNC)) {
                    /* Indirect functions shall have STT_FUNC type in executable
                     * dynsym section. Indeed, a dlsym call following a lazy
                     * resolution would pick the symbol value from the
                     * executable dynsym entry which would contain the address
                     * of the function wanted by the caller of dlsym instead of
                     * the address of the function that would return that
                     * address */
                    పూర్ణాంకం dynindex
		      = put_elf_sym(s1->dynsym, 0, esym->st_కొలత,
				    ELFW(ST_INFO)(STB_GLOBAL,STT_FUNC), 0, 0,
				    name);
		    పూర్ణాంకం సూచీ = sym - (ElfW(Sym) *) symtab_section->దత్తాంశం;
		    get_sym_attr(s1, సూచీ, 1)->dyn_సూచీ = dynindex;
                } లేకపోతే ఒకవేళ (type == STT_OBJECT) {
                    గుర్తులేని దీర్ఘ స్థానభ్రంశం;
                    ElfW(Sym) *dynsym;
                    ఒకవేళ (sym->st_shndx == bss_section->sh_అంకె) {
                        స్థానభ్రంశం = sym->st_విలువ;
                    } లేకపోతే {
                        స్థానభ్రంశం = bss_section->దత్తాంశం_స్థానభ్రంశం;
                        /* XXX: which alignment ? */
                        స్థానభ్రంశం = (స్థానభ్రంశం + 16 - 1) & -16;
                        bss_section->దత్తాంశం_స్థానభ్రంశం = స్థానభ్రంశం + esym->st_కొలత;
                    }
                    సమితి_elf_sym (s1->symtab, స్థానభ్రంశం, esym->st_కొలత,
                                 esym->st_info, 0, bss_section->sh_అంకె, name);
                    సూచీ = put_elf_sym(s1->dynsym, స్థానభ్రంశం, esym->st_కొలత,
                                        esym->st_info, 0, bss_section->sh_అంకె,
                                        name);
                    /* Ensure R_COPY works for weak symbol aliases */
                    ఒకవేళ (ELFW(ST_BIND)(esym->st_info) == STB_WEAK) {
                        for_each_elem(s1->dynsymtab_section, 1, dynsym, ElfW(Sym)) {
                            ఒకవేళ ((dynsym->st_విలువ == esym->st_విలువ)
                                && (ELFW(ST_BIND)(dynsym->st_info) == STB_GLOBAL)) {
                                అక్షరం *dynname = (అక్షరం *) s1->dynsymtab_section->link->దత్తాంశం
                                                + dynsym->st_name;
                                put_elf_sym(s1->dynsym, స్థానభ్రంశం, dynsym->st_కొలత,
                                            dynsym->st_info, 0,
                                            bss_section->sh_అంకె, dynname);
                                ఆపు;
                            }
                        }
                    }
                    put_elf_reloc(s1->dynsym, bss_section,
                                  స్థానభ్రంశం, R_COPY, సూచీ);
                }
            } లేకపోతే ఒకవేళ (sym->st_shndx == SHN_UNDEF) {
                /* STB_WEAK undefined symbols are accepted */
                /* XXX: _fp_hw seems to be part of the ABI, so we ignore it */
                ఒకవేళ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK ||
                    !strcmp(name, "_fp_hw")) {
                } లేకపోతే {
                    tcc_error_noabort("unresolved reference to '%s'", name);
                }
            }
        }
    }
    /* update _end symbol with new bss length */
    సమితి_linker_sym(s1, "_end", bss_section, 2);
}

/* Bind symbols of libraries: export all non local symbols of executable that
   are referenced by shared libraries. The reason is that the dynamic loader
   search symbol first in executable and then in libraries. Therefore a
   reference to a symbol already defined by a library can still be resolved by
   a symbol in the executable.   With -rdynamic, export all defined symbols */
స్థిర శూన్య bind_libs_dynsyms(TCCState *s1)
{
    స్థిరరాశి అక్షరం *name;
    పూర్ణాంకం dynsym_సూచీ;
    ElfW(Sym) *sym, *esym;

    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        name = (అక్షరం *)symtab_section->link->దత్తాంశం + sym->st_name;
        dynsym_సూచీ = కనుగొను_elf_sym(s1->dynsymtab_section, name);
        ఒకవేళ (sym->st_shndx != SHN_UNDEF) {
            ఒకవేళ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL
                && (dynsym_సూచీ || s1->rdynamic))
                సమితి_elf_sym(s1->dynsym, sym->st_విలువ, sym->st_కొలత,
                            sym->st_info, 0, sym->st_shndx, name);
        } లేకపోతే ఒకవేళ (dynsym_సూచీ) {
            esym = (ElfW(Sym) *)s1->dynsymtab_section->దత్తాంశం + dynsym_సూచీ;
            ఒకవేళ (esym->st_shndx == SHN_UNDEF) {
                /* weak symbols can stay undefined */
                ఒకవేళ (ELFW(ST_BIND)(esym->st_info) != STB_WEAK)
                    tcc_warning("unresolved dynamic reference to '%s'", name);
            }
        }
    }
}

/* Export all non local symbols. This is used by shared libraries so that the
   non local symbols they define can resolve a reference in another shared
   library or in the executable. Correspondingly, it allows undefined local
   symbols to be resolved by other shared libraries or by the executable. */
స్థిర శూన్య export_global_syms(TCCState *s1)
{
    పూర్ణాంకం dynindex, సూచీ;
    స్థిరరాశి అక్షరం *name;
    ElfW(Sym) *sym;
    for_each_elem(symtab_section, 1, sym, ElfW(Sym)) {
        ఒకవేళ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
	    name = (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name;
	    dynindex = సమితి_elf_sym(s1->dynsym, sym->st_విలువ, sym->st_కొలత,
				   sym->st_info, 0, sym->st_shndx, name);
	    సూచీ = sym - (ElfW(Sym) *) symtab_section->దత్తాంశం;
            get_sym_attr(s1, సూచీ, 1)->dyn_సూచీ = dynindex;
        }
    }
}

/* decide if an unallocated section should be output. */
స్థిర పూర్ణాంకం సమితి_sec_sizes(TCCState *s1)
{
    పూర్ణాంకం i;
    Section *s;
    పూర్ణాంకం textrel = 0;
    పూర్ణాంకం file_type = s1->output_type;

    /* Allocate strings for section names */
    కొరకు(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ఒకవేళ (s->sh_type == SHT_RELX && !(s->sh_flags & SHF_ALLOC)) {
            /* when generating a DLL, we include relocations but
               we may patch them */
            ఒకవేళ ((file_type & TCC_OUTPUT_DYN)
                && (s1->sections[s->sh_info]->sh_flags & SHF_ALLOC)) {
                పూర్ణాంకం లెక్క_2 = prepare_dynamic_rel(s1, s);
                ఒకవేళ (లెక్క_2) {
                    /* allocate the section */
                    s->sh_flags |= SHF_ALLOC;
                    s->sh_కొలత = లెక్క_2 * పరిమాణం(ElfW_Rel);
                    ఒకవేళ (s1->sections[s->sh_info]->sh_flags & SHF_EXECINSTR)
                        textrel += లెక్క_2;
                }
            }
        } లేకపోతే ఒకవేళ ((s->sh_flags & SHF_ALLOC)
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
                   || s->sh_type == SHT_ARM_లక్షణాలు
#అయితే_ముగింపు
                   || s1->do_debug) {
            s->sh_కొలత = s->దత్తాంశం_స్థానభ్రంశం;
        }
    }
    తిరిగి textrel;
}

/* various data used under elf_output_file() */
నిర్మాణం dyn_inf {
    Section *dynamic;
    Section *dynstr;
    Section *interp;
    Section *note;
    Section *gnu_hash;
    నిర్మాణం {
        /* Info to be copied in dynamic section */
        గుర్తులేని దీర్ఘ దత్తాంశం_స్థానభ్రంశం;
        addr_t rel_addr;
        addr_t rel_కొలత;
    };

    ElfW(Phdr) *phdr;
    పూర్ణాంకం phnum;
    పూర్ణాంకం shnum;
    పూర్ణాంకం tls;
    పూర్ణాంకం relro;
    పూర్ణాంకం notes;
    పూర్ణాంకం ehfr;
    పూర్ణాంకం dyna;
};

/* Decide the layout of sections loaded in memory. This must be done before
   program headers are filled since they contain info about the layout.
   We do the following ordering: interp, symbol tables, relocations, progbits,
   nobits */
స్థిర పూర్ణాంకం క్రమీకరించు_sections(TCCState *s1, పూర్ణాంకం *sec_క్రమం, నిర్మాణం dyn_inf *d)
{
    Section *s;
    పూర్ణాంకం i, j, k, f, f0, n;
    పూర్ణాంకం nb_sections = s1->nb_sections;
    పూర్ణాంకం *sec_cls = sec_క్రమం + nb_sections;
    పూర్ణాంకం tls_align = 0; /* need common alignment for all tls sections */

    కొరకు (i = 1; i < nb_sections; i++) {
        s = s1->sections[i];
        ఒకవేళ (0 == s->sh_name) {
            j = 0x900; /* no sh_name: won't go to file */
        } లేకపోతే ఒకవేళ (s->sh_flags & SHF_ALLOC) {
            j = 0x100;
            ఒకవేళ ((s->sh_flags & (SHF_WRITE|SHF_TLS)) == SHF_WRITE)
                j = 0x200;
        } లేకపోతే {
            j = 0x700;
        }
        ఒకవేళ (j >= 0x700 && s1->output_format != TCC_OUTPUT_FORMAT_ELF)
            s->sh_కొలత = 0, j = 0x900;

        ఒకవేళ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM) {
            k = 0x10;
        } లేకపోతే ఒకవేళ (s->sh_type == SHT_STRTAB && strcmp(s->name, ".stabstr")) {
            k = 0x11;
            ఒకవేళ (i == nb_sections - 1) /* ".shstrtab" assumed to stay last */
                k = 0xff;
        } లేకపోతే ఒకవేళ (s->sh_type == SHT_HASH || s->sh_type == SHT_GNU_HASH) {
            k = 0x12;
        } లేకపోతే ఒకవేళ (s->sh_type == SHT_GNU_verdef
                  || s->sh_type == SHT_GNU_verneed
                  || s->sh_type == SHT_GNU_versym) {
            k = 0x13;
        } లేకపోతే ఒకవేళ (s->sh_type == SHT_RELX) {
            k = 0x20;
            ఒకవేళ (s1->plt && s == s1->plt->reloc)
                k = 0x21;
        } లేకపోతే ఒకవేళ (s->sh_flags & SHF_EXECINSTR) {
            k = 0x60;
        /* RELRO sections --> */
        } లేకపోతే ఒకవేళ (s->sh_flags & SHF_TLS) {
            ఒకవేళ (s->sh_addralign > tls_align)
                tls_align = s->sh_addralign;
            k = 0x40 + (s->sh_type == SHT_NOBITS);
        } లేకపోతే ఒకవేళ (s->sh_type == SHT_PREINIT_ARRAY) {
            k = 0x42;
        } లేకపోతే ఒకవేళ (s->sh_type == SHT_INIT_ARRAY) {
            k = 0x43;
        } లేకపోతే ఒకవేళ (s->sh_type == SHT_FINI_ARRAY) {
            k = 0x44;
        } లేకపోతే ఒకవేళ (s->sh_type == SHT_DYNAMIC) {
            k = 0x48;
        } లేకపోతే ఒకవేళ (s == s1->got) {
            k = 0x49; /* .got as RELRO needs BIND_NOW in DT_FLAGS */
        } లేకపోతే ఒకవేళ (s->reloc && (s->reloc->sh_flags & SHF_ALLOC) && j == 0x100) {
            k = 0x45; /* +1 for data.ro */
        /* <-- */
        } లేకపోతే ఒకవేళ (s->sh_type == SHT_NOTE) {
            k = 0x08, d->notes = 1;
        } లేకపోతే ఒకవేళ (s->sh_type == SHT_NOBITS) {
            k = 0x70; /* bss */
        } లేకపోతే ఒకవేళ (s == d->interp) {
            k = 0x00;
        } లేకపోతే {
            k = 0x50; /*దత్తాంశం*/
        }
        k += j;
        /* make our standard sections come last to have _etext/_edata correct values */
        ఒకవేళ (s->sh_అంకె <= bss_section->sh_అంకె)
            ++k;
        /* make RELRO section writable */
        ఒకవేళ ((k & 0xfff0) == 0x140)
            k += 0x100, s->sh_flags |= SHF_WRITE;
        /* sort by insert */
        కొరకు (n = i; n > 1 && k < (f = sec_cls[n - 1]); --n)
            sec_cls[n] = f, sec_క్రమం[n] = sec_క్రమం[n - 1];
        sec_cls[n] = k, sec_క్రమం[n] = i;
    }
    sec_క్రమం[0] = 0;
    d->shnum = 1;

#నిర్వచించు SHFX_NEWPH (1 << 4)
#నిర్వచించు SHFX_RELRO (1 << 5)

    /* count PT_LOAD headers needed */
    n = f0 = 0;
    కొరకు (i = 1; i < nb_sections; i++) {
        s = s1->sections[sec_క్రమం[i]];
        k = sec_cls[i];
        f = 0;
        ఒకవేళ (k < 0x900)
            ++d->shnum;
        ఒకవేళ (k < 0x700) {
            f = s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR);
#ఒకవేళ TARGETOS_NetBSD || TARGETOS_FreeBSD
	    /* NetBSD only supports 2 PT_LOAD sections.
	       See: https://blog.netbsd.org/tnf/entry/the_first_report_on_lld */
	    ఒకవేళ ((f & SHF_WRITE) == 0)
                f |= SHF_EXECINSTR;
            k = 0; /* no relro */
#అయితే_ముగింపు
            ఒకవేళ ((k & 0xfff0) == 0x240) /* RELRO sections */
                d->relro = 1, f |= SHFX_RELRO;
            /* start new header when flags changed, but avoid zero memsz */
            ఒకవేళ (f != f0 && s->sh_కొలత)
                f0 = f, ++n, f |= SHFX_NEWPH;
            ఒకవేళ ((s->sh_flags & SHF_TLS) && s->sh_కొలత) {
                s->sh_addralign = tls_align;
                d->tls = 1, f |= SHF_TLS;
            }
        }
        sec_cls[i] = f;
        //printf("ph %d sec %02d : %3X %3X  %8.2X  %04X  %s\n", (f>0) * n, i, f, k, s->sh_type, (int)s->sh_size, s->name);
    }
    తిరిగి n;
}

స్థిర ElfW(Phdr) *fill_phdr(ElfW(Phdr) *ph, పూర్ణాంకం type, Section *s)
{
    ph->p_type = type;
    ph->p_flags = PF_R;
    ఒకవేళ (s) {
        ఒకవేళ (s->sh_flags & SHF_WRITE)
            ph->p_flags |= PF_W;
        ph->p_స్థానభ్రంశం = s->sh_స్థానభ్రంశం;
        ph->p_vaddr = s->sh_addr;
        ph->p_filesz = s->sh_కొలత;
        ph->p_align = s->sh_addralign;
    }
    ph->p_paddr = ph->p_vaddr;
    ph->p_memsz = ph->p_filesz;
    తిరిగి ph;
}

స్థిర ElfW(Phdr) *update_phdr(ElfW(Phdr) *ph, పూర్ణాంకం type, Section *s, addr_t addr, పూర్ణాంకం file_స్థానభ్రంశం)
{
    ఒకవేళ (ph->p_type == 0) {
        fill_phdr(ph, type, s);
    }
    ph->p_filesz = file_స్థానభ్రంశం - ph->p_స్థానభ్రంశం;
    ph->p_memsz = addr - ph->p_vaddr;
    తిరిగి ph;
}

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
స్థిర పూర్ణాంకం layout_sections(TCCState *s1, పూర్ణాంకం *sec_క్రమం, నిర్మాణం dyn_inf *d)
{
    Section *s;
    addr_t addr, tmp, align, s_align, పునాది;
    ElfW(Phdr) *ph = ఖాళీ, *ph2;
    పూర్ణాంకం i, f, n, phnum, phfill;
    పూర్ణాంకం file_స్థానభ్రంశం;

    /* compute number of program headers */
    phnum = క్రమీకరించు_sections(s1, sec_క్రమం, d);
    phfill = 0; /* set to 1 to have dll's with a PT_PHDR */
    ఒకవేళ (d->interp)
        phfill = 2;
    phnum += phfill;
    ఒకవేళ (d->dynamic)
        d->dyna = phnum++;
    ఒకవేళ (d->notes)
        d->notes = phnum++;
    ఒకవేళ (d->tls)
        d->tls = phnum++;
    ఒకవేళ (eh_చట్రం_hdr_section)
        d->ehfr = phnum++;
    ఒకవేళ (d->relro)
        d->relro = phnum++;
    d->phnum = phnum;
    d->phdr = tcc_mallocz(phnum * పరిమాణం(ElfW(Phdr)));

    file_స్థానభ్రంశం = 0;
    ఒకవేళ (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
        file_స్థానభ్రంశం = (పరిమాణం(ElfW(Ehdr)) + phnum * పరిమాణం(ElfW(Phdr)) + 3) & -4;
        file_స్థానభ్రంశం += d->shnum * పరిమాణం (ElfW(Shdr));
    }

    s_align = ELF_పుట_కొలత;
    ఒకవేళ (s1->section_align)
        s_align = s1->section_align;

    addr = ELF_ప్రారంభం_ADDR;
    ఒకవేళ (s1->output_type & TCC_OUTPUT_DYN)
        addr = 0;

    ఒకవేళ (s1->has_పాఠ్యం_addr) {
        addr = s1->పాఠ్యం_addr;
        ఒకవేళ (0) {
            పూర్ణాంకం a_స్థానభ్రంశం, p_స్థానభ్రంశం;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_స్థానభ్రంశం = (పూర్ణాంకం) (addr & (s_align - 1));
            p_స్థానభ్రంశం = file_స్థానభ్రంశం & (s_align - 1);
            ఒకవేళ (a_స్థానభ్రంశం < p_స్థానభ్రంశం)
                a_స్థానభ్రంశం += s_align;
            file_స్థానభ్రంశం += (a_స్థానభ్రంశం - p_స్థానభ్రంశం);
        }
    }
    పునాది = addr;
    /* compute address after headers */
    addr += file_స్థానభ్రంశం;

    n = 0;
    కొరకు(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_క్రమం[i]];
        f = sec_క్రమం[i + s1->nb_sections];
        align = s->sh_addralign - 1;

        ఒకవేళ (f == 0) { /* no alloc */
            file_స్థానభ్రంశం = (file_స్థానభ్రంశం + align) & ~align;
            s->sh_స్థానభ్రంశం = file_స్థానభ్రంశం;
            ఒకవేళ (s->sh_type != SHT_NOBITS)
                file_స్థానభ్రంశం += s->sh_కొలత;
            కొనసాగు;
        }

        ఒకవేళ ((f & SHFX_NEWPH) && n) {
            /* different rwx section flags */
            ఒకవేళ (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
                /* if in the middle of a page, w e duplicate the page in
                   memory so that one copy is RX and the other is RW */
                ఒకవేళ ((addr & (s_align - 1)) != 0)
                    addr += s_align;
            } లేకపోతే {
                align = s_align - 1;
            }
        }

        tmp = addr;
        addr = (addr + align) & ~align;
        file_స్థానభ్రంశం += (పూర్ణాంకం)(addr - tmp);
        s->sh_స్థానభ్రంశం = file_స్థానభ్రంశం;
        s->sh_addr = addr;

        //printf("%d : %08x %08x %04x %03x %s %d\n", n, (int)file_offset, (int)addr, (int)s->sh_size, s->sh_type, s->name, align + 1);
        addr += s->sh_కొలత;
        ఒకవేళ (s->sh_type != SHT_NOBITS)
            file_స్థానభ్రంశం += s->sh_కొలత;

        ఒకవేళ (f & SHFX_NEWPH) {
            /* set new program header */
            ph = &d->phdr[phfill + n];
            fill_phdr(ph, PT_ఎక్కించు, s);
            ph->p_align = s_align;
            ఒకవేళ (f & SHF_EXECINSTR)
                ph->p_flags |= PF_X;
            ఒకవేళ (n == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_స్థానభ్రంశం = 0;
                ph->p_paddr = ph->p_vaddr = పునాది;
            }
            ++n;
        }

        ఒకవేళ (ph)
            update_phdr(ph, 0, 0, addr, file_స్థానభ్రంశం);

        ఒకవేళ (f & SHFX_RELRO) {
            ph2 = update_phdr(&d->phdr[d->relro], PT_GNU_RELRO, s, addr, file_స్థానభ్రంశం);
            ph2->p_align = 1;
        }
        ఒకవేళ (f & SHF_TLS) {
            ph2 = update_phdr(&d->phdr[d->tls], PT_TLS, s, addr, file_స్థానభ్రంశం);
            ఒకవేళ (s->sh_type == SHT_NOBITS)
                addr -= s->sh_కొలత;
            /* for xxx-link.c:relocate() */
            s1->tls_ప్రారంభం = ph2->p_vaddr;
            s1->tls_చివర = s1->tls_ప్రారంభం + ph2->p_memsz + (-ph2->p_memsz & (ph2->p_align - 1));
        }
        ఒకవేళ (s->sh_type == SHT_NOTE) {
            update_phdr(&d->phdr[d->notes], PT_NOTE, s, addr, file_స్థానభ్రంశం);
        }
    }

    /* Fill other headers */
    ఒకవేళ (d->dyna)
        fill_phdr(&d->phdr[d->dyna], PT_DYNAMIC, d->dynamic);
    ఒకవేళ (d->ehfr)
        fill_phdr(&d->phdr[d->ehfr], PT_GNU_EH_చట్రం, eh_చట్రం_hdr_section);
    ఒకవేళ (d->interp)
        fill_phdr(&d->phdr[1], PT_INTERP, d->interp);
    ఒకవేళ (phfill) {
        ph = &d->phdr[0];
        ph->p_స్థానభ్రంశం = పరిమాణం(ElfW(Ehdr));
        ph->p_vaddr = పునాది + ph->p_స్థానభ్రంశం;
        ph->p_filesz = phnum * పరిమాణం(ElfW(Phdr));
        ph->p_align = 4;
        fill_phdr(ph, PT_PHDR, ఖాళీ);
    }
    తిరిగి 0;
}

/* put dynamic tag */
స్థిర శూన్య put_dt(Section *dynamic, పూర్ణాంకం dt, addr_t val)
{
    ElfW(Dyn) *dyn;
    dyn = section_ptr_కూడు(dynamic, పరిమాణం(ElfW(Dyn)));
    dyn->d_ట్యాగ్ = dt;
    dyn->d_un.d_val = val;
}

/* Fill the dynamic section with tags describing the address and size of
   sections */
స్థిర శూన్య fill_dynamic(TCCState *s1, నిర్మాణం dyn_inf *dyninf)
{
    Section *dynamic = dyninf->dynamic;
    Section *s;

    /* put dynamic section entries */
    put_dt(dynamic, DT_HASH, s1->dynsym->hash->sh_addr);
    put_dt(dynamic, DT_GNU_HASH, dyninf->gnu_hash->sh_addr);
    put_dt(dynamic, DT_STRTAB, dyninf->dynstr->sh_addr);
    put_dt(dynamic, DT_SYMTAB, s1->dynsym->sh_addr);
    put_dt(dynamic, DT_STRSZ, dyninf->dynstr->దత్తాంశం_స్థానభ్రంశం);
    put_dt(dynamic, DT_SYMENT, పరిమాణం(ElfW(Sym)));
#ఒకవేళ PTR_కొలత == 8
    put_dt(dynamic, DT_RELA, dyninf->rel_addr);
    put_dt(dynamic, DT_RELASZ, dyninf->rel_కొలత);
    put_dt(dynamic, DT_RELAENT, పరిమాణం(ElfW_Rel));
    ఒకవేళ (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->దత్తాంశం_స్థానభ్రంశం);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_RELA);
    }
    put_dt(dynamic, DT_RELACOUNT, 0);
#లేకపోతే
    put_dt(dynamic, DT_REL, dyninf->rel_addr);
    put_dt(dynamic, DT_RELSZ, dyninf->rel_కొలత);
    put_dt(dynamic, DT_RELENT, పరిమాణం(ElfW_Rel));
    ఒకవేళ (s1->plt && s1->plt->reloc) {
        put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
        put_dt(dynamic, DT_PLTRELSZ, s1->plt->reloc->దత్తాంశం_స్థానభ్రంశం);
        put_dt(dynamic, DT_JMPREL, s1->plt->reloc->sh_addr);
        put_dt(dynamic, DT_PLTREL, DT_REL);
    }
    put_dt(dynamic, DT_RELCOUNT, 0);
#అయితే_ముగింపు
    ఒకవేళ (versym_section && verneed_section) {
	/* The dynamic linker can not handle VERSYM without VERNEED */
        put_dt(dynamic, DT_VERSYM, versym_section->sh_addr);
        put_dt(dynamic, DT_VERNEED, verneed_section->sh_addr);
        put_dt(dynamic, DT_VERNEEDNUM, dt_verneednum);
    }
    s = have_section(s1, ".preinit_array");
    ఒకవేళ (s && s->దత్తాంశం_స్థానభ్రంశం) {
        put_dt(dynamic, DT_PREINIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_PREINIT_ARRAYSZ, s->దత్తాంశం_స్థానభ్రంశం);
    }
    s = have_section(s1, ".init_array");
    ఒకవేళ (s && s->దత్తాంశం_స్థానభ్రంశం) {
        put_dt(dynamic, DT_INIT_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_INIT_ARRAYSZ, s->దత్తాంశం_స్థానభ్రంశం);
    }
    s = have_section(s1, ".fini_array");
    ఒకవేళ (s && s->దత్తాంశం_స్థానభ్రంశం) {
        put_dt(dynamic, DT_FINI_ARRAY, s->sh_addr);
        put_dt(dynamic, DT_FINI_ARRAYSZ, s->దత్తాంశం_స్థానభ్రంశం);
    }
    s = have_section(s1, ".init");
    ఒకవేళ (s && s->దత్తాంశం_స్థానభ్రంశం) {
        put_dt(dynamic, DT_INIT, s->sh_addr);
    }
    s = have_section(s1, ".fini");
    ఒకవేళ (s && s->దత్తాంశం_స్థానభ్రంశం) {
        put_dt(dynamic, DT_FINI, s->sh_addr);
    }
    ఒకవేళ (s1->do_debug)
        put_dt(dynamic, DT_DEBUG, 0);
    put_dt(dynamic, DT_NULL, 0);
}

/* Remove gaps between RELX sections.
   These gaps are a result of final_sections_reloc. Here some relocs are removed.
   The gaps are then filled with 0 in tcc_output_elf. The 0 is intepreted as
   R_...NONE reloc. This does work on most targets but on OpenBSD/arm64 this
   is illegal. OpenBSD/arm64 does not support R_...NONE reloc. */
స్థిర శూన్య update_reloc_sections(TCCState *s1, నిర్మాణం dyn_inf *dyninf)
{
    పూర్ణాంకం i;
    గుర్తులేని దీర్ఘ file_స్థానభ్రంశం = 0;
    Section *s;
    Section *relocplt = s1->plt ? s1->plt->reloc : ఖాళీ;

    /* dynamic relocation table information, for .dynamic section */
    dyninf->rel_addr = dyninf->rel_కొలత = 0;

    కొరకు(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
	ఒకవేళ (s->sh_type == SHT_RELX && s != relocplt) {
	    ఒకవేళ (dyninf->rel_కొలత == 0) {
		dyninf->rel_addr = s->sh_addr;
		file_స్థానభ్రంశం = s->sh_స్థానభ్రంశం;
	    }
	    లేకపోతే {
		s->sh_addr = dyninf->rel_addr + dyninf->rel_కొలత;
		s->sh_స్థానభ్రంశం = file_స్థానభ్రంశం + dyninf->rel_కొలత;
	    }
	    dyninf->rel_కొలత += s->sh_కొలత;
	}
    }
}
#అయితే_ముగింపు /* ndef ELF_OBJ_ONLY */

/* Create an ELF file on disk.
   This function handle ELF specific layout requirements */
స్థిర పూర్ణాంకం tcc_output_elf(TCCState *s1, FILE *f, పూర్ణాంకం phnum, ElfW(Phdr) *phdr)
{
    పూర్ణాంకం i, shnum, స్థానభ్రంశం, కొలత, file_type;
    Section *s;
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) shdr, *sh;

    file_type = s1->output_type;
    shnum = s1->nb_sections;

    memset(&ehdr, 0, పరిమాణం(ehdr));
    ఒకవేళ (phnum > 0) {
        ehdr.e_phentsize = పరిమాణం(ElfW(Phdr));
        ehdr.e_phnum = phnum;
        ehdr.e_phoff = పరిమాణం(ElfW(Ehdr));
    }

    /* fill header */
    ehdr.e_ident[0] = ELFMAG0;
    ehdr.e_ident[1] = ELFMAG1;
    ehdr.e_ident[2] = ELFMAG2;
    ehdr.e_ident[3] = ELFMAG3;
    ehdr.e_ident[4] = ELFCLASSW;
    ehdr.e_ident[5] = ELFDATA2LSB;
    ehdr.e_ident[6] = EV_CURRENT;

#ఒకవేళ TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    ehdr.e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
#లేదావేళ TARGETOS_OpenBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_OPENBSD;
#లేదావేళ TARGETOS_NetBSD
    ehdr.e_ident[EI_OSABI] = ELFOSABI_NETBSD;
#లేదావేళ defined TCC_లక్ష్యం_ARM && defined TCC_ARM_EABI
    ehdr.e_flags = EF_ARM_EABI_VER5;
    ehdr.e_flags |= s1->float_abi == ARM_HARD_FLOAT
        ? EF_ARM_VFP_FLOAT : EF_ARM_SOFT_FLOAT;
#లేదావేళ defined TCC_లక్ష్యం_ARM
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#లేదావేళ defined TCC_లక్ష్యం_RISCV64
    /* XXX should be configurable */
    ehdr.e_flags = EF_RISCV_FLOAT_ABI_DOUBLE;
#అయితే_ముగింపు

    ఒకవేళ (file_type == TCC_OUTPUT_OBJ) {
        ehdr.e_type = ET_REL;
    } లేకపోతే {
        ఒకవేళ (file_type & TCC_OUTPUT_DYN)
            ehdr.e_type = ET_DYN;
        లేకపోతే
            ehdr.e_type = ET_EXEC;
        ఒకవేళ (s1->elf_entryname)
            ehdr.e_నమోదు = get_sym_addr(s1, s1->elf_entryname, 1, 0);
        లేకపోతే
            ehdr.e_నమోదు = get_sym_addr(s1, "_start", !!(file_type & TCC_OUTPUT_EXE), 0);
        ఒకవేళ (ehdr.e_నమోదు == (addr_t)-1)
            ehdr.e_నమోదు = పాఠ్యం_section->sh_addr;
        ఒకవేళ (s1->nb_errors)
            తిరిగి -1;
    }

    క్రమీకరించు_syms(s1, s1->symtab);

    ehdr.e_machine = EM_TCC_లక్ష్యం;
    ehdr.e_సంస్కరణ = EV_CURRENT;
    ehdr.e_shoff = (పరిమాణం(ElfW(Ehdr)) + phnum * పరిమాణం(ElfW(Phdr)) + 3) & -4;
    ehdr.e_ehsize = పరిమాణం(ElfW(Ehdr));
    ehdr.e_shentsize = పరిమాణం(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    స్థానభ్రంశం = fwrite(&ehdr, 1, పరిమాణం(ElfW(Ehdr)), f);
    ఒకవేళ (phdr)
        స్థానభ్రంశం += fwrite(phdr, 1, phnum * పరిమాణం(ElfW(Phdr)), f);

    /* output section headers */
    అయితే (స్థానభ్రంశం < ehdr.e_shoff) {
        fputc(0, f);
        స్థానభ్రంశం++;
    }

    కొరకు(i = 0; i < shnum; i++) {
        sh = &shdr;
        memset(sh, 0, పరిమాణం(ElfW(Shdr)));
        ఒకవేళ (i) {
            s = s1->sections[i];
            sh->sh_name = s->sh_name;
            sh->sh_type = s->sh_type;
            sh->sh_flags = s->sh_flags;
            sh->sh_entsize = s->sh_entsize;
            sh->sh_info = s->sh_info;
            ఒకవేళ (s->link)
                sh->sh_link = s->link->sh_అంకె;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_స్థానభ్రంశం = s->sh_స్థానభ్రంశం;
            sh->sh_కొలత = s->sh_కొలత;
        }
        స్థానభ్రంశం += fwrite(sh, 1, పరిమాణం(ElfW(Shdr)), f);
    }

    /* output sections */
    కొరకు(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ఒకవేళ (s->sh_type != SHT_NOBITS) {
            అయితే (స్థానభ్రంశం < s->sh_స్థానభ్రంశం) {
                fputc(0, f);
                స్థానభ్రంశం++;
            }
            కొలత = s->sh_కొలత;
            ఒకవేళ (కొలత)
                స్థానభ్రంశం += fwrite(s->దత్తాంశం, 1, కొలత, f);
        }
    }
    తిరిగి 0;
}

స్థిర పూర్ణాంకం tcc_output_ద్విమాన(TCCState *s1, FILE *f)
{
    Section *s;
    పూర్ణాంకం i, స్థానభ్రంశం, కొలత;

    స్థానభ్రంశం = 0;
    కొరకు(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[i];
        ఒకవేళ (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            అయితే (స్థానభ్రంశం < s->sh_స్థానభ్రంశం) {
                fputc(0, f);
                స్థానభ్రంశం++;
            }
            కొలత = s->sh_కొలత;
            fwrite(s->దత్తాంశం, 1, కొలత, f);
            స్థానభ్రంశం += కొలత;
        }
    }
    తిరిగి 0;
}

/* Write an elf, coff or "binary" file */
స్థిర పూర్ణాంకం tcc_write_elf_file(TCCState *s1, స్థిరరాశి అక్షరం *filename, పూర్ణాంకం phnum,
                              ElfW(Phdr) *phdr)
{
    పూర్ణాంకం fd, బహుళకం, file_type, ret;
    FILE *f;

    file_type = s1->output_type;
    ఒకవేళ (file_type == TCC_OUTPUT_OBJ)
        బహుళకం = 0666;
    లేకపోతే
        బహుళకం = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_ద్విమాన_2, బహుళకం);
    ఒకవేళ (fd < 0 || (f = fdopen(fd, "wb")) == ఖాళీ)
        తిరిగి tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
    ఒకవేళ (s1->verbose)
        రాయి("<- %s\n", filename);
#నిర్వచితమైతే TCC_లక్ష్యం_COFF
    ఒకవేళ (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    లేకపోతే
#అయితే_ముగింపు
    ఒకవేళ (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        ret = tcc_output_elf(s1, f, phnum, phdr);
    లేకపోతే
        ret = tcc_output_ద్విమాన(s1, f);
    fclose(f);

    తిరిగి ret;
}

#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
/* order sections according to sec_order, remove sections
   that we aren't going to output.  */
స్థిర శూన్య reorder_sections(TCCState *s1, పూర్ణాంకం *sec_క్రమం)
{
    పూర్ణాంకం i, nnew, k, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    backmap = tcc_malloc(s1->nb_sections * పరిమాణం(backmap[0]));
    కొరకు (i = 0, nnew = 0, snew = ఖాళీ; i < s1->nb_sections; i++) {
	k = sec_క్రమం ? sec_క్రమం[i] : i;
	s = s1->sections[k];
	ఒకవేళ (!i || s->sh_name) {
	    backmap[k] = nnew;
            dynarray_కూడు(&snew, &nnew, s);
	} లేకపోతే {
	    backmap[k] = 0;
            /* just remember to free them later */
	    dynarray_కూడు(&s1->priv_sections, &s1->nb_priv_sections, s);
	}
    }
    కొరకు (i = 1; i < nnew; i++) {
	s = snew[i];
        s->sh_అంకె = i;
        ఒకవేళ (s->sh_type == SHT_RELX)
            s->sh_info = backmap[s->sh_info];
        లేకపోతే ఒకవేళ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_DYNSYM)
            for_each_elem(s, 1, sym, ElfW(Sym))
                ఒకవేళ (sym->st_shndx < s1->nb_sections)
                    sym->st_shndx = backmap[sym->st_shndx];
    }
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}

#నిర్వచితమైతే TCC_లక్ష్యం_ARM
స్థిర శూన్య create_arm_attribute_section(TCCState *s1)
{
   // Needed for DLL support.
    స్థిర స్థిరరాశి గుర్తులేని అక్షరం arm_attr[] = {
        0x41,                            // 'A'
        0x2c, 0x00, 0x00, 0x00,          // size 0x2c
        'a', 'e', 'a', 'b', 'i', 0x00,   // "aeabi"
        0x01, 0x22, 0x00, 0x00, 0x00,    // 'File Attributes', size 0x22
        0x05, 0x36, 0x00,                // 'CPU_name', "6"
#ఒకవేళ CONFIG_TCC_CPUVER >= 7
        0x06, 0x0a,                      // 'CPU_arch', 'v7'
#లేకపోతే
        0x06, 0x06,                      // 'CPU_arch', 'v6'
#అయితే_ముగింపు
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
    Section *attr = new_section(s1, ".ARM.attributes", SHT_ARM_లక్షణాలు, 0);
    గుర్తులేని అక్షరం *ptr = section_ptr_కూడు(attr, పరిమాణం(arm_attr));
    attr->sh_addralign = 1;
    జ్ఞాపకం_నకలు(ptr, arm_attr, పరిమాణం(arm_attr));
    ఒకవేళ (s1->float_abi != ARM_HARD_FLOAT) {
        ptr[26] = 0x00; // 'FP_arch', 'No'
        ptr[41] = 0x1e; // 'ABI_optimization_goals'
        ptr[42] = 0x06; // 'Aggressive Debug'
    }
}
#అయితే_ముగింపు

#నిర్వచితమైతే TCC_లక్ష్యం_RISCV64
స్థిర శూన్య create_riscv_attribute_section(TCCState *s1)
{
    స్థిర స్థిరరాశి గుర్తులేని అక్షరం riscv_attr[] = {
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
    Section *attr = new_section(s1, ".riscv.attributes", SHT_RISCV_లక్షణాలు, 0);
    గుర్తులేని అక్షరం *ptr = section_ptr_కూడు(attr, పరిమాణం(riscv_attr));
    attr->sh_addralign = 1;
    జ్ఞాపకం_నకలు(ptr, riscv_attr, పరిమాణం(riscv_attr));
}
#అయితే_ముగింపు

#ఒకవేళ TARGETOS_OpenBSD || TARGETOS_NetBSD || TARGETOS_FreeBSD

స్థిర శూన్య fill_bsd_note(Section *s, పూర్ణాంకం type,
			  స్థిరరాశి అక్షరం *విలువ, uint32_t దత్తాంశం)
{
    గుర్తులేని దీర్ఘ స్థానభ్రంశం = 0;
    అక్షరం *ptr;
    ElfW(Nhdr) *note;
    పూర్ణాంకం align = s->sh_addralign;

    /* check if type present */
    అయితే (స్థానభ్రంశం + పరిమాణం(ElfW(Nhdr)) < s->దత్తాంశం_స్థానభ్రంశం) {
        note = (ElfW(Nhdr) *) (s->దత్తాంశం + స్థానభ్రంశం);
	ఒకవేళ (note->n_type == type)
	    తిరిగి;
	స్థానభ్రంశం += (పరిమాణం(ElfW(Nhdr)) + note->n_namesz + note->n_descsz +
		  align - 1) & -align;
    }
    ptr = section_ptr_కూడు(s, పరిమాణం(ElfW(Nhdr)) + 8 + 4);
    note = (ElfW(Nhdr) *) ptr;
    note->n_namesz = 8;
    note->n_descsz = 4;
    note->n_type = type;
    strcpy (ptr + పరిమాణం(ElfW(Nhdr)), విలువ);
    జ్ఞాపకం_నకలు (ptr + పరిమాణం(ElfW(Nhdr)) + 8, &దత్తాంశం, 4);
}

స్థిర Section *create_bsd_note_section(TCCState *s1,
					స్థిరరాశి అక్షరం *name,
					స్థిరరాశి అక్షరం *విలువ)
{
    Section *s;
    గుర్తులేని పూర్ణాంకం major = 0, minor = 0, patch = 0;

#నిర్వచితమైతే CONFIG_OS_RELEASE
    అక్షరశ్రేణి_చదువు(CONFIG_OS_RELEASE, "%u.%u.%u", &major, &minor, &patch);
#అయితే_ముగింపు
#ఒకవేళ TARGETOS_FreeBSD
    ఒకవేళ (major < 14)
	తిరిగి ఖాళీ;
#అయితే_ముగింపు
    s = కనుగొను_section (s1, name);
    s->sh_type = SHT_NOTE;
#ఒకవేళ TARGETOS_OpenBSD
    fill_bsd_note(s, ELF_NOTE_OS_GNU, విలువ, 0);
#లేదావేళ TARGETOS_NetBSD
    fill_bsd_note(s, 1 /* NT_NETBSD_IDENT_TAG */, విలువ,
		  major * 100000000u + (minor % 100u) * 1000000u +
		  (patch % 10000u) * 100u);
#లేదావేళ TARGETOS_FreeBSD
    fill_bsd_note(s, 1 /* NT_FREEBSD_ABI_TAG */, విలువ,
		  major * 100000u + (minor % 100u) * 1000u);
    fill_bsd_note(s, 4 /* NT_FREEBSD_FEATURE_CTL */, విలువ, 0);
    fill_bsd_note(s, 2 /* NT_FREEBSD_NOINIT_TAG */, విలువ, 0);
#అయితే_ముగింపు
    తిరిగి s;
}
#అయితే_ముగింపు

స్థిర శూన్య alloc_sec_పేర్లు(TCCState *s1, పూర్ణాంకం is_obj);

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
స్థిర పూర్ణాంకం elf_output_file(TCCState *s1, స్థిరరాశి అక్షరం *filename)
{
    పూర్ణాంకం i, ret, file_type, *sec_క్రమం;
    నిర్మాణం dyn_inf dyninf = {0};
    Section *interp, *dynstr, *dynamic;
    పూర్ణాంకం textrel, got_sym, dt_flags_1;

    file_type = s1->output_type;
    ret = -1;
    interp = dynstr = dynamic = ఖాళీ;
    sec_క్రమం = ఖాళీ;

#నిర్వచితమైతే TCC_లక్ష్యం_ARM
    create_arm_attribute_section (s1);
#అయితే_ముగింపు

#నిర్వచితమైతే TCC_లక్ష్యం_RISCV64
    create_riscv_attribute_section(s1);
#అయితే_ముగింపు

#ఒకవేళ TARGETOS_OpenBSD
    dyninf.note = create_bsd_note_section (s1, ".note.openbsd.ident", "OpenBSD");
#అయితే_ముగింపు

#ఒకవేళ TARGETOS_NetBSD
    dyninf.note = create_bsd_note_section (s1, ".note.netbsd.ident", "NetBSD");
#అయితే_ముగింపు

#ఒకవేళ TARGETOS_FreeBSD
    dyninf.note = create_bsd_note_section (s1, ".note.tag", "FreeBSD");
#అయితే_ముగింపు

        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_కూడు_runtime(s1);
	resolve_common_syms(s1);

        ఒకవేళ (!s1->static_link) {
            ఒకవేళ (file_type & TCC_OUTPUT_EXE) {
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
            dynamic->sh_entsize = పరిమాణం(ElfW(Dyn));

            got_sym = build_got(s1);
            ఒకవేళ (file_type & TCC_OUTPUT_EXE) {
                bind_exe_dynsyms(s1, file_type & TCC_OUTPUT_DYN);
                ఒకవేళ (s1->nb_errors)
                    వెళ్ళు the_చివర;
            }
            build_got_entries(s1, got_sym);
            ఒకవేళ (file_type & TCC_OUTPUT_EXE) {
                bind_libs_dynsyms(s1);
            } లేకపోతే {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
#ఒకవేళ TCC_EH_చట్రం
	    /* fill with initial data */
	    tcc_eh_చట్రం_hdr(s1, 0);
#అయితే_ముగింపు
	    dyninf.gnu_hash = create_gnu_hash(s1);
        } లేకపోతే {
            build_got_entries(s1, 0);
        }
	సంస్కరణ_కూడు (s1);

    textrel = సమితి_sec_sizes(s1);

    ఒకవేళ (!s1->static_link) {
        /* add a list of needed dlls */
        కొరకు(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            ఒకవేళ (dllref->level == 0)
                put_dt(dynamic, DT_NEEDED, put_elf_str(dynstr, dllref->name));
        }

        ఒకవేళ (s1->rpath)
            put_dt(dynamic, s1->enable_new_dtags ? DT_RUNPATH : DT_RPATH,
                   put_elf_str(dynstr, s1->rpath));

        dt_flags_1 = DF_1_NOW;
        ఒకవేళ (file_type & TCC_OUTPUT_DYN) {
            ఒకవేళ (s1->soname)
                put_dt(dynamic, DT_SONAME, put_elf_str(dynstr, s1->soname));
            /* XXX: currently, since we do not handle PIC code, we
               must relocate the readonly segments */
            ఒకవేళ (textrel)
                put_dt(dynamic, DT_TEXTREL, 0);
            ఒకవేళ (file_type & TCC_OUTPUT_EXE)
                dt_flags_1 = DF_1_NOW | DF_1_PIE;
	    ఒకవేళ (s1->znodelete)
		dt_flags_1 |= DF_1_NODELETE;
        }
        put_dt(dynamic, DT_FLAGS, DF_BIND_NOW);
        put_dt(dynamic, DT_FLAGS_1, dt_flags_1);
        ఒకవేళ (s1->symbolic)
            put_dt(dynamic, DT_SYMBOLIC, 0);

        dyninf.dynamic = dynamic;
        dyninf.dynstr = dynstr;
        /* remember offset and reserve space for 2nd call below */
        dyninf.దత్తాంశం_స్థానభ్రంశం = dynamic->దత్తాంశం_స్థానభ్రంశం;
        fill_dynamic(s1, &dyninf);
        dynamic->sh_కొలత = dynamic->దత్తాంశం_స్థానభ్రంశం;
        dynstr->sh_కొలత = dynstr->దత్తాంశం_స్థానభ్రంశం;
    }

    /* create and fill .shstrtab section */
    alloc_sec_పేర్లు(s1, 0);
    /* this array is used to reorder sections in the output file */
    sec_క్రమం = tcc_malloc(పరిమాణం(పూర్ణాంకం) * 2 * s1->nb_sections);
    /* compute section to program header mapping */
    layout_sections(s1, sec_క్రమం, &dyninf);

        ఒకవేళ (dynamic) {
            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->దత్తాంశం, dynamic->sh_addr);
            ఒకవేళ (file_type == TCC_OUTPUT_EXE
                || (RELOCATE_DLLPLT && (file_type & TCC_OUTPUT_DYN)))
                relocate_plt(s1);
            /* relocate symbols in .dynsym now that final addresses are known */
            relocate_syms(s1, s1->dynsym, 2);
        }

        /* if building executable or DLL, then relocate each section
           except the GOT which is already relocated */
        relocate_syms(s1, s1->symtab, 0);
        ఒకవేళ (s1->nb_errors != 0)
            వెళ్ళు the_చివర;
        relocate_sections(s1);
        ఒకవేళ (dynamic) {
	    update_reloc_sections (s1, &dyninf);
            dynamic->దత్తాంశం_స్థానభ్రంశం = dyninf.దత్తాంశం_స్థానభ్రంశం;
            fill_dynamic(s1, &dyninf);
	}
        /* Perform relocation to GOT or PLT entries */
        ఒకవేళ (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        లేకపోతే ఒకవేళ (s1->got)
            fill_local_got_entries(s1);

    ఒకవేళ (dyninf.gnu_hash)
        update_gnu_hash(s1, dyninf.gnu_hash);

    reorder_sections(s1, sec_క్రమం);
#ఒకవేళ TCC_EH_చట్రం
    /* fill with final data */
    tcc_eh_చట్రం_hdr(s1, 1);
#అయితే_ముగింపు
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, dyninf.phnum, dyninf.phdr);
 the_చివర:
    tcc_free(sec_క్రమం);
    tcc_free(dyninf.phdr);
    తిరిగి ret;
}
#అయితే_ముగింపు /* ndef ELF_OBJ_ONLY */

/* Allocate strings for section names */
స్థిర శూన్య alloc_sec_పేర్లు(TCCState *s1, పూర్ణాంకం is_obj)
{
    పూర్ణాంకం i;
    Section *s, *strsec;

    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");
    కొరకు(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ఒకవేళ (is_obj)
            s->sh_కొలత = s->దత్తాంశం_స్థానభ్రంశం;
	ఒకవేళ (s->sh_కొలత || s == strsec || (s->sh_flags & SHF_ALLOC) || is_obj)
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_కొలత = strsec->దత్తాంశం_స్థానభ్రంశం;
}

/* Output an elf .o file */
స్థిర పూర్ణాంకం elf_output_obj(TCCState *s1, స్థిరరాశి అక్షరం *filename)
{
    Section *s;
    పూర్ణాంకం i, ret, file_స్థానభ్రంశం;
    /* Allocate strings for section names */
    alloc_sec_పేర్లు(s1, 1);
    file_స్థానభ్రంశం = (పరిమాణం (ElfW(Ehdr)) + 3) & -4;
    file_స్థానభ్రంశం += s1->nb_sections * పరిమాణం(ElfW(Shdr));
    కొరకు(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        file_స్థానభ్రంశం = (file_స్థానభ్రంశం + 15) & -16;
        s->sh_స్థానభ్రంశం = file_స్థానభ్రంశం;
        ఒకవేళ (s->sh_type != SHT_NOBITS)
            file_స్థానభ్రంశం += s->sh_కొలత;
    }
    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, 0, ఖాళీ);
    తిరిగి ret;
}

LIBTCCAPI పూర్ణాంకం tcc_output_file(TCCState *s, స్థిరరాశి అక్షరం *filename)
{
    s->nb_errors = 0;
    ఒకవేళ (s->test_coverage)
        tcc_tcov_కూడు_file(s, filename);
    ఒకవేళ (s->output_type == TCC_OUTPUT_OBJ)
        తిరిగి elf_output_obj(s, filename);
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    తిరిగి  pe_output_file(s, filename);
#లేదావేళ defined TCC_లక్ష్యం_MACHO
    తిరిగి macho_output_file(s, filename);
#లేకపోతే
    తిరిగి elf_output_file(s, filename);
#అయితే_ముగింపు
}

ST_FUNC ssize_t నిండిన_read(పూర్ణాంకం fd, శూన్య *buf, కొలత_t లెక్క_2) {
    అక్షరం *cbuf = buf;
    కొలత_t rnum = 0;
    అయితే (1) {
        ssize_t అంకె = పఠ(fd, cbuf, లెక్క_2-rnum);
        ఒకవేళ (అంకె < 0) తిరిగి అంకె;
        ఒకవేళ (అంకె == 0) తిరిగి rnum;
        rnum += అంకె;
        cbuf += అంకె;
    }
}

ST_FUNC శూన్య *ఎక్కించు_దత్తాంశం(పూర్ణాంకం fd, గుర్తులేని దీర్ఘ file_స్థానభ్రంశం, గుర్తులేని దీర్ఘ కొలత)
{
    శూన్య *దత్తాంశం;

    దత్తాంశం = tcc_malloc(కొలత);
    lseek(fd, file_స్థానభ్రంశం, SEEK_SET);
    నిండిన_read(fd, దత్తాంశం, కొలత);
    తిరిగి దత్తాంశం;
}

రకనిర్వచనం నిర్మాణం Section_విలీనం_Info {
    Section *s;            /* corresponding existing section */
    గుర్తులేని దీర్ఘ స్థానభ్రంశం;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} Section_విలీనం_Info;

ST_FUNC పూర్ణాంకం tcc_object_type(పూర్ణాంకం fd, ElfW(Ehdr) *h)
{
    పూర్ణాంకం కొలత = నిండిన_read(fd, h, పరిమాణం *h);
    ఒకవేళ (కొలత == పరిమాణం *h && 0 == memcmp(h, ELFMAG, 4)) {
        ఒకవేళ (h->e_type == ET_REL)
            తిరిగి AFF_BINTYPE_REL;
        ఒకవేళ (h->e_type == ET_DYN)
            తిరిగి AFF_BINTYPE_DYN;
    } లేకపోతే ఒకవేళ (కొలత >= 8) {
        ఒకవేళ (0 == memcmp(h, ARMAG, 8))
            తిరిగి AFF_BINTYPE_AR;
#నిర్వచితమైతే TCC_లక్ష్యం_COFF
        ఒకవేళ (((నిర్మాణం filehdr*)h)->f_magic == COFF_C67_MAGIC)
            తిరిగి AFF_BINTYPE_C67;
#అయితే_ముగింపు
    }
    తిరిగి 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC పూర్ణాంకం tcc_ఎక్కించు_object_file(TCCState *s1,
                                పూర్ణాంకం fd, గుర్తులేని దీర్ఘ file_స్థానభ్రంశం)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    గుర్తులేని దీర్ఘ కొలత, స్థానభ్రంశం, offseti;
    పూర్ణాంకం i, j, nb_syms, sym_సూచీ, ret, seencompressed;
    అక్షరం *strsec, *strtab;
    పూర్ణాంకం stab_సూచీ, stabstr_సూచీ;
    పూర్ణాంకం *old_గమ్యం_new_syms;
    అక్షరం *sh_name, *name;
    Section_విలీనం_Info *sm_పట్టిక, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    lseek(fd, file_స్థానభ్రంశం, SEEK_SET);
    ఒకవేళ (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        వెళ్ళు invalid;
    /* test CPU specific stuff */
    ఒకవేళ (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_లక్ష్యం) {
invalid:
        తిరిగి tcc_error_noabort("invalid object file");
    }
    /* read sections */
    shdr = ఎక్కించు_దత్తాంశం(fd, file_స్థానభ్రంశం + ehdr.e_shoff,
                     పరిమాణం(ElfW(Shdr)) * ehdr.e_shnum);
    sm_పట్టిక = tcc_mallocz(పరిమాణం(Section_విలీనం_Info) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = ఎక్కించు_దత్తాంశం(fd, file_స్థానభ్రంశం + sh->sh_స్థానభ్రంశం, sh->sh_కొలత);

    /* load symtab and strtab */
    old_గమ్యం_new_syms = ఖాళీ;
    symtab = ఖాళీ;
    strtab = ఖాళీ;
    nb_syms = 0;
    seencompressed = 0;
    stab_సూచీ = stabstr_సూచీ = 0;
    ret = -1;

    కొరకు(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        ఒకవేళ (sh->sh_type == SHT_SYMTAB) {
            ఒకవేళ (symtab) {
                tcc_error_noabort("object must contain only one symtab");
                వెళ్ళు the_చివర;
            }
            nb_syms = sh->sh_కొలత / పరిమాణం(ElfW(Sym));
            symtab = ఎక్కించు_దత్తాంశం(fd, file_స్థానభ్రంశం + sh->sh_స్థానభ్రంశం, sh->sh_కొలత);
            sm_పట్టిక[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = ఎక్కించు_దత్తాంశం(fd, file_స్థానభ్రంశం + sh->sh_స్థానభ్రంశం, sh->sh_కొలత);
        }
	ఒకవేళ (sh->sh_flags & SHF_COMPRESSED)
	    seencompressed = 1;
    }

    /* now examine each section and try to merge its content with the
       ones in memory */
    కొరకు(i = 1; i < ehdr.e_shnum; i++) {
        /* no need to examine section name strtab */
        ఒకవేళ (i == ehdr.e_shstrndx)
            కొనసాగు;
        sh = &shdr[i];
	ఒకవేళ (sh->sh_type == SHT_RELX)
	  sh = &shdr[sh->sh_info];
        /* ignore sections types we do not handle (plus relocs to those) */
        sh_name = strsec + sh->sh_name;
        ఒకవేళ (0 == అక్షరశ్రేణి_పోలిక(sh_name, ".debug_", 7)
         || 0 == అక్షరశ్రేణి_పోలిక(sh_name, ".stab", 5)) {
	    ఒకవేళ (!s1->do_debug || seencompressed)
	        కొనసాగు;
#ఒకవేళ !(TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD)
        } లేకపోతే ఒకవేళ (0 == అక్షరశ్రేణి_పోలిక(sh_name, ".eh_frame", 9)) {
            ఒకవేళ (ఖాళీ == eh_చట్రం_section)
                కొనసాగు;
#అయితే_ముగింపు
        } లేకపోతే
        ఒకవేళ (sh->sh_type != SHT_PROGBITS &&
            sh->sh_type != SHT_NOTE &&
            sh->sh_type != SHT_NOBITS &&
            sh->sh_type != SHT_PREINIT_ARRAY &&
            sh->sh_type != SHT_INIT_ARRAY &&
            sh->sh_type != SHT_FINI_ARRAY
#నిర్వచితమైతే TCC_ARM_EABI
            /* Added in commit f99d3de221db23e322c6c18c8249282e27726c25
               but suppressed in 3cfaaaf1eb97d858e583412616f68f75fdad5da5
               So don't load it in order to avoid dangling references from
               (STT_SECTION) symbols. */
            // && sh->sh_type != SHT_ARM_EXIDX
#అయితే_ముగింపు

#ఒకవేళ TARGETOS_OpenBSD || TARGETOS_FreeBSD || TARGETOS_NetBSD
            && sh->sh_type != SHT_X86_64_UNWIND
#అయితే_ముగింపు
            )
            కొనసాగు;

	sh = &shdr[i];
        sh_name = strsec + sh->sh_name;
        ఒకవేళ (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        /* find corresponding section, if any */
        కొరకు(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            ఒకవేళ (strcmp(s->name, sh_name))
                కొనసాగు;
            ఒకవేళ (sh->sh_type != s->sh_type
                && strcmp (s->name, ".eh_frame")
                /* some crt1.o seem to have two ".note.GNU-stack" (SHT_NOTE & SHT_PROGBITS) */
                && strcmp (s->name, ".note.GNU-stack")
                ) {
                tcc_error_noabort("section type conflict: %s %02x <> %02x", s->name, sh->sh_type, s->sh_type);
                వెళ్ళు the_చివర;
            }
            ఒకవేళ (!అక్షరశ్రేణి_పోలిక(sh_name, ".gnu.linkonce", 13)) {
                /* if a 'linkonce' section is already present, we
                   do not add it again. It is a little tricky as
                   symbols can still be defined in
                   it. */
                sm_పట్టిక[i].link_once = 1;
                వెళ్ళు తదుపరి;
            }
            ఒకవేళ (stab_section) {
                ఒకవేళ (s == stab_section)
                    stab_సూచీ = i;
                ఒకవేళ (s == stab_section->link)
                    stabstr_సూచీ = i;
            }
            వెళ్ళు దొరికింది;
        }
        /* not found: create new section */
        s = new_section(s1, sh_name, sh->sh_type, sh->sh_flags & ~SHF_సమూహం);
        /* take as much info as possible from the section. sh_link and
           sh_info will be updated later */
        s->sh_addralign = sh->sh_addralign;
        s->sh_entsize = sh->sh_entsize;
        sm_పట్టిక[i].new_section = 1;
    దొరికింది:
        కొలత = sh->sh_కొలత;
        /* align start of section */
        స్థానభ్రంశం = section_కూడు(s, కొలత, sh->sh_addralign);
        ఒకవేళ (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        sm_పట్టిక[i].స్థానభ్రంశం = స్థానభ్రంశం;
        sm_పట్టిక[i].s = s;
        /* concatenate sections */
        ఒకవేళ (sh->sh_type != SHT_NOBITS && కొలత) {
            గుర్తులేని అక్షరం *ptr;
            lseek(fd, file_స్థానభ్రంశం + sh->sh_స్థానభ్రంశం, SEEK_SET);
            ptr = s->దత్తాంశం + స్థానభ్రంశం;
            నిండిన_read(fd, ptr, కొలత);
        }
#ఒకవేళ defined TCC_లక్ష్యం_ARM || defined TCC_లక్ష్యం_ARM64 || defined TCC_లక్ష్యం_RISCV64
        /* align code sections to instruction lenght */
        /* This is needed if we compile a c file after this */
        ఒకవేళ (s->sh_flags & SHF_EXECINSTR)
            section_కూడు(s, 0, 4);
#అయితే_ముగింపు
    తదుపరి: ;
    }

    /* gr relocate stab strings */
    ఒకవేళ (stab_సూచీ && stabstr_సూచీ) {
        Stab_Sym *a, *b;
        గుర్తులేని o;
        s = sm_పట్టిక[stab_సూచీ].s;
        a = (Stab_Sym *)(s->దత్తాంశం + sm_పట్టిక[stab_సూచీ].స్థానభ్రంశం);
        b = (Stab_Sym *)(s->దత్తాంశం + s->దత్తాంశం_స్థానభ్రంశం);
        o = sm_పట్టిక[stabstr_సూచీ].స్థానభ్రంశం;
        అయితే (a < b) {
            ఒకవేళ (a->n_strx)
                a->n_strx += o;
            a++;
        }
    }

    /* second short pass to update sh_link and sh_info fields of new
       sections */
    కొరకు(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_పట్టిక[i].s;
        ఒకవేళ (!s || !sm_పట్టిక[i].new_section)
            కొనసాగు;
        sh = &shdr[i];
        ఒకవేళ (sh->sh_link > 0)
            s->link = sm_పట్టిక[sh->sh_link].s;
        ఒకవేళ (sh->sh_type == SHT_RELX) {
            s->sh_info = sm_పట్టిక[sh->sh_info].s->sh_అంకె;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }

    ఒకవేళ (!symtab)
        వెళ్ళు పూర్తి;

    /* resolve symbols */
    old_గమ్యం_new_syms = tcc_mallocz(nb_syms * పరిమాణం(పూర్ణాంకం));

    sym = symtab + 1;
    కొరకు(i = 1; i < nb_syms; i++, sym++) {
        ఒకవేళ (sym->st_shndx != SHN_UNDEF &&
            sym->st_shndx < SHN_LORESERVE) {
            sm = &sm_పట్టిక[sym->st_shndx];
            ఒకవేళ (sm->link_once) {
                /* if a symbol is in a link once section, we use the
                   already defined symbol. It is very important to get
                   correct relocations */
                ఒకవేళ (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
                    name = strtab + sym->st_name;
                    sym_సూచీ = కనుగొను_elf_sym(symtab_section, name);
                    ఒకవేళ (sym_సూచీ)
                        old_గమ్యం_new_syms[i] = sym_సూచీ;
                }
                కొనసాగు;
            }
            /* if no corresponding section added, no need to add symbol */
            ఒకవేళ (!sm->s)
                కొనసాగు;
            /* convert section number */
            sym->st_shndx = sm->s->sh_అంకె;
            /* offset value */
            sym->st_విలువ += sm->స్థానభ్రంశం;
        }
        /* add symbol */
        name = strtab + sym->st_name;
        sym_సూచీ = సమితి_elf_sym(symtab_section, sym->st_విలువ, sym->st_కొలత,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_గమ్యం_new_syms[i] = sym_సూచీ;
    }

    /* third pass to patch relocation entries */
    కొరకు(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_పట్టిక[i].s;
        ఒకవేళ (!s)
            కొనసాగు;
        sh = &shdr[i];
        స్థానభ్రంశం = sm_పట్టిక[i].స్థానభ్రంశం;
        కొలత = sh->sh_కొలత;
        ఎంపిక(s->sh_type) {
        స్థితి SHT_RELX:
            /* take relocation offset information */
            offseti = sm_పట్టిక[sh->sh_info].స్థానభ్రంశం;
	    కొరకు (rel = (ElfW_Rel *) s->దత్తాంశం + (స్థానభ్రంశం / పరిమాణం(*rel));
		 rel < (ElfW_Rel *) s->దత్తాంశం + ((స్థానభ్రంశం + కొలత) / పరిమాణం(*rel));
		 rel++) {
                పూర్ణాంకం type;
                గుర్తులేని sym_సూచీ;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_సూచీ = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                ఒకవేళ (sym_సూచీ >= nb_syms)
                    వెళ్ళు invalid_reloc;
                sym_సూచీ = old_గమ్యం_new_syms[sym_సూచీ];
                /* ignore link_once in rel section. */
                ఒకవేళ (!sym_సూచీ && !sm_పట్టిక[sh->sh_info].link_once
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
                    && type != R_ARM_V4BX
#లేదావేళ defined TCC_లక్ష్యం_RISCV64
                    && type != R_RISCV_ALIGN
                    && type != R_RISCV_RELAX
#అయితే_ముగింపు
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, (పూర్ణాంకం)rel->r_స్థానభ్రంశం);
                    వెళ్ళు the_చివర;
                }
                rel->r_info = ELFW(R_INFO)(sym_సూచీ, type);
                /* offset the relocation offset */
                rel->r_స్థానభ్రంశం += offseti;
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
                /* Jumps and branches from a Thumb code to a PLT entry need
                   special handling since PLT entries are ARM code.
                   Unconditional bl instructions referencing PLT entries are
                   handled by converting these instructions into blx
                   instructions. Other case of instructions referencing a PLT
                   entry require to add a Thumb stub before the PLT entry to
                   switch to ARM mode. We set bit plt_thumb_stub of the
                   attribute of a symbol to indicate such a case. */
                ఒకవేళ (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_సూచీ, 1)->plt_thumb_stub = 1;
#అయితే_ముగింపు
            }
            ఆపు;
        అప్రమేయ:
            ఆపు;
        }
    }
 పూర్తి:
    ret = !s1->nb_errors - 1; /* errors possibly from set_elf_sym() */
 the_చివర:
    tcc_free(symtab);
    tcc_free(strtab);
    tcc_free(old_గమ్యం_new_syms);
    tcc_free(sm_పట్టిక);
    tcc_free(strsec);
    tcc_free(shdr);
    తిరిగి ret;
}

రకనిర్వచనం నిర్మాణం Archive_శీర్షిక {
    అక్షరం ar_name[16];           /* name of this member */
    అక్షరం ar_date[12];           /* file mtime */
    అక్షరం ar_uid[6];             /* owner uid; printed as decimal */
    అక్షరం ar_gid[6];             /* owner gid; printed as decimal */
    అక్షరం ar_బహుళకం[8];            /* file mode, printed as octal   */
    అక్షరం ar_కొలత[10];           /* file size, printed as decimal */
    అక్షరం ar_fmag[2];            /* should contain ARFMAG */
} Archive_శీర్షిక;

#నిర్వచించు ARFMAG "`\n"

స్థిర గుర్తులేని దీర్ఘ దీర్ఘ get_be(స్థిరరాశి uint8_t *b, పూర్ణాంకం n)
{
    గుర్తులేని దీర్ఘ దీర్ఘ ret = 0;
    అయితే (n)
        ret = (ret << 8) | *b++, --n;
    తిరిగి ret;
}

స్థిర పూర్ణాంకం read_ar_శీర్షిక(పూర్ణాంకం fd, పూర్ణాంకం స్థానభ్రంశం, Archive_శీర్షిక *hdr)
{
    అక్షరం *p, *e;
    పూర్ణాంకం len;
    lseek(fd, స్థానభ్రంశం, SEEK_SET);
    len = నిండిన_read(fd, hdr, పరిమాణం(Archive_శీర్షిక));
    ఒకవేళ (len != పరిమాణం(Archive_శీర్షిక))
        తిరిగి len ? -1 : 0;
    ఒకవేళ (memcmp(hdr->ar_fmag, ARFMAG, పరిమాణం hdr->ar_fmag))
        తిరిగి -1;
    p = hdr->ar_name;
    కొరకు (e = p + పరిమాణం hdr->ar_name; e > p && e[-1] == ' ';)
        --e;
    *e = '\0';
    hdr->ar_కొలత[పరిమాణం hdr->ar_కొలత-1] = 0;
    తిరిగి len;
}

/* load only the objects which resolve undefined symbols */
స్థిర పూర్ణాంకం tcc_ఎక్కించు_alacarte(TCCState *s1, పూర్ణాంకం fd, పూర్ణాంకం కొలత, పూర్ణాంకం entrysize)
{
    పూర్ణాంకం i, bound, nsyms, sym_సూచీ, len, ret = -1;
    గుర్తులేని దీర్ఘ దీర్ఘ off;
    uint8_t *దత్తాంశం;
    స్థిరరాశి అక్షరం *ar_పేర్లు, *p;
    స్థిరరాశి uint8_t *ar_సూచీ;
    ElfW(Sym) *sym;
    Archive_శీర్షిక hdr;

    దత్తాంశం = tcc_malloc(కొలత);
    ఒకవేళ (నిండిన_read(fd, దత్తాంశం, కొలత) != కొలత)
        వెళ్ళు invalid;
    nsyms = get_be(దత్తాంశం, entrysize);
    ar_సూచీ = దత్తాంశం + entrysize;
    ar_పేర్లు = (అక్షరం *) ar_సూచీ + nsyms * entrysize;

    చేయి {
        bound = 0;
        కొరకు (p = ar_పేర్లు, i = 0; i < nsyms; i++, p += అక్షరశ్రేణి_పొడవు(p)+1) {
            Section *s = symtab_section;
            sym_సూచీ = కనుగొను_elf_sym(s, p);
            ఒకవేళ (!sym_సూచీ)
                కొనసాగు;
            sym = &((ElfW(Sym) *)s->దత్తాంశం)[sym_సూచీ];
            ఒకవేళ(sym->st_shndx != SHN_UNDEF)
                కొనసాగు;
            off = get_be(ar_సూచీ + i * entrysize, entrysize);
            len = read_ar_శీర్షిక(fd, off, &hdr);
            ఒకవేళ (len <= 0 || memcmp(hdr.ar_fmag, ARFMAG, 2)) {
        invalid:
                tcc_error_noabort("invalid archive");
                వెళ్ళు the_చివర;
            }
            off += len;
            ఒకవేళ (s1->verbose == 2)
                రాయి("   -> %s\n", hdr.ar_name);
            ఒకవేళ (tcc_ఎక్కించు_object_file(s1, fd, off) < 0)
                వెళ్ళు the_చివర;
            ++bound;
        }
    } అయితే(bound);
    ret = 0;
 the_చివర:
    tcc_free(దత్తాంశం);
    తిరిగి ret;
}

/* load a '.a' file */
ST_FUNC పూర్ణాంకం tcc_ఎక్కించు_archive(TCCState *s1, పూర్ణాంకం fd, పూర్ణాంకం alacarte)
{
    Archive_శీర్షిక hdr;
    /* char magic[8]; */
    పూర్ణాంకం కొలత, len;
    గుర్తులేని దీర్ఘ file_స్థానభ్రంశం;
    ElfW(Ehdr) ehdr;

    /* skip magic which was already checked */
    /* full_read(fd, magic, sizeof(magic)); */
    file_స్థానభ్రంశం = పరిమాణం ARMAG - 1;

    కొరకు(;;) {
        len = read_ar_శీర్షిక(fd, file_స్థానభ్రంశం, &hdr);
        ఒకవేళ (len == 0)
            తిరిగి 0;
        ఒకవేళ (len < 0)
            తిరిగి tcc_error_noabort("invalid archive");
        file_స్థానభ్రంశం += len;
        కొలత = strtol(hdr.ar_కొలత, ఖాళీ, 0);
        ఒకవేళ (alacarte) {
            /* coff symbol table : we handle it */
            ఒకవేళ (!strcmp(hdr.ar_name, "/"))
                తిరిగి tcc_ఎక్కించు_alacarte(s1, fd, కొలత, 4);
            ఒకవేళ (!strcmp(hdr.ar_name, "/SYM64/"))
                తిరిగి tcc_ఎక్కించు_alacarte(s1, fd, కొలత, 8);
        } లేకపోతే ఒకవేళ (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
            ఒకవేళ (s1->verbose == 2)
                రాయి("   -> %s\n", hdr.ar_name);
            ఒకవేళ (tcc_ఎక్కించు_object_file(s1, fd, file_స్థానభ్రంశం) < 0)
                తిరిగి -1;
        }
        /* align to even */
        file_స్థానభ్రంశం = (file_స్థానభ్రంశం + కొలత + 1) & ~1;
    }
}

#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
/* Set LV[I] to the global index of sym-version (LIB,VERSION).  Maybe resizes
   LV, maybe create a new entry for (LIB,VERSION).  */
స్థిర శూన్య సమితి_ver_గమ్యం_ver(TCCState *s1, పూర్ణాంకం *n, పూర్ణాంకం **lv, పూర్ణాంకం i, అక్షరం *lib, అక్షరం *సంస్కరణ)
{
    అయితే (i >= *n) {
        *lv = tcc_realloc(*lv, (*n + 1) * పరిమాణం(**lv));
        (*lv)[(*n)++] = -1;
    }
    ఒకవేళ ((*lv)[i] == -1) {
        పూర్ణాంకం v, prev_same_lib = -1;
        కొరకు (v = 0; v < nb_sym_versions; v++) {
            ఒకవేళ (strcmp(sym_versions[v].lib, lib))
              కొనసాగు;
            prev_same_lib = v;
            ఒకవేళ (!strcmp(sym_versions[v].సంస్కరణ, సంస్కరణ))
              ఆపు;
        }
        ఒకవేళ (v == nb_sym_versions) {
            sym_versions = tcc_realloc (sym_versions,
                                        (v + 1) * పరిమాణం(*sym_versions));
            sym_versions[v].lib = tcc_strdup(lib);
            sym_versions[v].సంస్కరణ = tcc_strdup(సంస్కరణ);
            sym_versions[v].బహిర్గతం_సూచీ = 0;
            sym_versions[v].prev_same_lib = prev_same_lib;
            nb_sym_versions++;
        }
        (*lv)[i] = v;
    }
}

/* Associates symbol SYM_INDEX (in dynsymtab) with sym-version index
   VERNDX.  */
స్థిర శూన్య
సమితి_sym_సంస్కరణ(TCCState *s1, పూర్ణాంకం sym_సూచీ, పూర్ణాంకం verndx)
{
    ఒకవేళ (sym_సూచీ >= nb_sym_గమ్యం_సంస్కరణ) {
        పూర్ణాంకం newelems = sym_సూచీ ? sym_సూచీ * 2 : 1;
        sym_గమ్యం_సంస్కరణ = tcc_realloc(sym_గమ్యం_సంస్కరణ,
                                     newelems * పరిమాణం(*sym_గమ్యం_సంస్కరణ));
        memset(sym_గమ్యం_సంస్కరణ + nb_sym_గమ్యం_సంస్కరణ, -1,
               (newelems - nb_sym_గమ్యం_సంస్కరణ) * పరిమాణం(*sym_గమ్యం_సంస్కరణ));
        nb_sym_గమ్యం_సంస్కరణ = newelems;
    }
    ఒకవేళ (sym_గమ్యం_సంస్కరణ[sym_సూచీ] < 0)
      sym_గమ్యం_సంస్కరణ[sym_సూచీ] = verndx;
}

నిర్మాణం versym_info {
    పూర్ణాంకం nb_versyms;
    ElfW(Verdef) *verdef;
    ElfW(Verneed) *verneed;
    ElfW(Half) *versym;
    పూర్ణాంకం nb_local_ver, *local_ver;
};


స్థిర శూన్య store_సంస్కరణ(TCCState *s1, నిర్మాణం versym_info *v, అక్షరం *dynstr)
{
    అక్షరం *lib, *సంస్కరణ;
    uint32_t తదుపరి;
    పూర్ణాంకం i;

#నిర్వచించు	DEBUG_సంస్కరణ 0

    ఒకవేళ (v->versym && v->verdef) {
      ElfW(Verdef) *vdef = v->verdef;
      lib = ఖాళీ;
      చేయి {
        ElfW(Verdaux) *verdaux =
	  (ElfW(Verdaux) *) (((అక్షరం *) vdef) + vdef->vd_aux);

#ఒకవేళ DEBUG_సంస్కరణ
	రాయి ("verdef: version:%u flags:%u index:%u, hash:%u\n",
	        vdef->vd_సంస్కరణ, vdef->vd_flags, vdef->vd_ndx,
		vdef->vd_hash);
#అయితే_ముగింపు
	ఒకవేళ (vdef->vd_cnt) {
          సంస్కరణ = dynstr + verdaux->vda_name;

	  ఒకవేళ (lib == ఖాళీ)
	    lib = సంస్కరణ;
	  లేకపోతే
            సమితి_ver_గమ్యం_ver(s1, &v->nb_local_ver, &v->local_ver, vdef->vd_ndx,
                           lib, సంస్కరణ);
#ఒకవేళ DEBUG_సంస్కరణ
	  రాయి ("  verdaux(%u): %s\n", vdef->vd_ndx, సంస్కరణ);
#అయితే_ముగింపు
	}
        తదుపరి = vdef->vd_తదుపరి;
        vdef = (ElfW(Verdef) *) (((అక్షరం *) vdef) + తదుపరి);
      } అయితే (తదుపరి);
    }
    ఒకవేళ (v->versym && v->verneed) {
      ElfW(Verneed) *vneed = v->verneed;
      చేయి {
        ElfW(Vernaux) *vernaux =
	  (ElfW(Vernaux) *) (((అక్షరం *) vneed) + vneed->vn_aux);

        lib = dynstr + vneed->vn_file;
#ఒకవేళ DEBUG_సంస్కరణ
	రాయి ("verneed: %u %s\n", vneed->vn_సంస్కరణ, lib);
#అయితే_ముగింపు
	కొరకు (i = 0; i < vneed->vn_cnt; i++) {
	  ఒకవేళ ((vernaux->vna_other & 0x8000) == 0) { /* hidden */
              సంస్కరణ = dynstr + vernaux->vna_name;
              సమితి_ver_గమ్యం_ver(s1, &v->nb_local_ver, &v->local_ver, vernaux->vna_other,
                             lib, సంస్కరణ);
#ఒకవేళ DEBUG_సంస్కరణ
	    రాయి ("  vernaux(%u): %u %u %s\n",
		    vernaux->vna_other, vernaux->vna_hash,
		    vernaux->vna_flags, సంస్కరణ);
#అయితే_ముగింపు
	  }
	  vernaux = (ElfW(Vernaux) *) (((అక్షరం *) vernaux) + vernaux->vna_తదుపరి);
	}
        తదుపరి = vneed->vn_తదుపరి;
        vneed = (ElfW(Verneed) *) (((అక్షరం *) vneed) + తదుపరి);
      } అయితే (తదుపరి);
    }

#ఒకవేళ DEBUG_సంస్కరణ
    కొరకు (i = 0; i < v->nb_local_ver; i++) {
      ఒకవేళ (v->local_ver[i] > 0) {
        రాయి ("%d: lib: %s, version %s\n",
		i, sym_versions[v->local_ver[i]].lib,
                sym_versions[v->local_ver[i]].సంస్కరణ);
      }
    }
#అయితే_ముగింపు
}

/* load a library / DLL
   'level = 0' means that the DLL is referenced by the user
   (so it should be added as DT_NEEDED in the generated ELF file) */
ST_FUNC పూర్ణాంకం tcc_ఎక్కించు_dll(TCCState *s1, పూర్ణాంకం fd, స్థిరరాశి అక్షరం *filename, పూర్ణాంకం level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    పూర్ణాంకం i, nb_syms, nb_dts, sym_bind, ret = -1;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;

    అక్షరం *dynstr;
    పూర్ణాంకం sym_సూచీ;
    స్థిరరాశి అక్షరం *name, *soname;
    నిర్మాణం versym_info v;

    నిండిన_read(fd, &ehdr, పరిమాణం(ehdr));

    /* test CPU specific stuff */
    ఒకవేళ (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_లక్ష్యం) {
        తిరిగి tcc_error_noabort("bad architecture");
    }

    /* read sections */
    shdr = ఎక్కించు_దత్తాంశం(fd, ehdr.e_shoff, పరిమాణం(ElfW(Shdr)) * ehdr.e_shnum);

    /* load dynamic section and dynamic symbols */
    nb_syms = 0;
    nb_dts = 0;
    dynamic = ఖాళీ;
    dynsym = ఖాళీ; /* avoid warning */
    dynstr = ఖాళీ; /* avoid warning */
    memset(&v, 0, పరిమాణం v);

    కొరకు(i = 0, sh = shdr; i < ehdr.e_shnum; i++, sh++) {
        ఎంపిక(sh->sh_type) {
        స్థితి SHT_DYNAMIC:
            nb_dts = sh->sh_కొలత / పరిమాణం(ElfW(Dyn));
            dynamic = ఎక్కించు_దత్తాంశం(fd, sh->sh_స్థానభ్రంశం, sh->sh_కొలత);
            ఆపు;
        స్థితి SHT_DYNSYM:
            nb_syms = sh->sh_కొలత / పరిమాణం(ElfW(Sym));
            dynsym = ఎక్కించు_దత్తాంశం(fd, sh->sh_స్థానభ్రంశం, sh->sh_కొలత);
            sh1 = &shdr[sh->sh_link];
            dynstr = ఎక్కించు_దత్తాంశం(fd, sh1->sh_స్థానభ్రంశం, sh1->sh_కొలత);
            ఆపు;
        స్థితి SHT_GNU_verdef:
	    v.verdef = ఎక్కించు_దత్తాంశం(fd, sh->sh_స్థానభ్రంశం, sh->sh_కొలత);
	    ఆపు;
        స్థితి SHT_GNU_verneed:
	    v.verneed = ఎక్కించు_దత్తాంశం(fd, sh->sh_స్థానభ్రంశం, sh->sh_కొలత);
	    ఆపు;
        స్థితి SHT_GNU_versym:
            v.nb_versyms = sh->sh_కొలత / పరిమాణం(ElfW(Half));
	    v.versym = ఎక్కించు_దత్తాంశం(fd, sh->sh_స్థానభ్రంశం, sh->sh_కొలత);
	    ఆపు;
        అప్రమేయ:
            ఆపు;
        }
    }

    ఒకవేళ (!dynamic)
        వెళ్ళు the_చివర;

    /* compute the real library name */
    soname = tcc_basename(filename);
    కొరకు(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        ఒకవేళ (dt->d_ట్యాగ్ == DT_SONAME)
            soname = dynstr + dt->d_un.d_val;

    /* if the dll is already loaded, do not load it */
    ఒకవేళ (tcc_కూడు_dllref(s1, soname, level)->దొరికింది)
        వెళ్ళు ret_success;

    ఒకవేళ (v.nb_versyms != nb_syms)
        tcc_free (v.versym), v.versym = ఖాళీ;
    లేకపోతే
        store_సంస్కరణ(s1, &v, dynstr);

    /* add dynamic symbols in dynsym_section */
    కొరకు(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        ఒకవేళ (sym_bind == STB_LOCAL)
            కొనసాగు;
        name = dynstr + sym->st_name;
        sym_సూచీ = సమితి_elf_sym(s1->dynsymtab_section, sym->st_విలువ, sym->st_కొలత,
                                sym->st_info, sym->st_other, sym->st_shndx, name);
        ఒకవేళ (v.versym) {
            ElfW(Half) vsym = v.versym[i];
            ఒకవేళ ((vsym & 0x8000) == 0 && vsym > 0 && vsym < v.nb_local_ver)
                సమితి_sym_సంస్కరణ(s1, sym_సూచీ, v.local_ver[vsym]);
        }
    }

    /* do not load all referenced libraries
       (recursive loading can break linking of libraries) */
    /* following DT_NEEDED is needed for the dynamic loader (libdl.so),
       but it is no longer needed, when linking a library or a program.
       When tcc output mode is OUTPUT_MEM,
       tcc calls dlopen, which handles DT_NEEDED for us */

#ఒకవేళ 0
    కొరకు(i = 0, dt = dynamic; i < nb_dts; i++, dt++)
        ఒకవేళ (dt->d_ట్యాగ్ == DT_RPATH)
            tcc_కూడు_library_మార్గం(s1, dynstr + dt->d_un.d_val);

    /* load all referenced DLLs */
    కొరకు(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        ఎంపిక(dt->d_ట్యాగ్) {
        స్థితి DT_NEEDED:
            name = dynstr + dt->d_un.d_val;
            ఒకవేళ (tcc_కూడు_dllref(s1, name, -1))
                కొనసాగు;
            ఒకవేళ (tcc_కూడు_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                ret = tcc_error_noabort("referenced dll '%s' not found", name);
                వెళ్ళు the_చివర;
            }
        }
    }
#అయితే_ముగింపు

 ret_success:
    ret = 0;
 the_చివర:
    tcc_free(dynstr);
    tcc_free(dynsym);
    tcc_free(dynamic);
    tcc_free(shdr);
    tcc_free(v.local_ver);
    tcc_free(v.verdef);
    tcc_free(v.verneed);
    tcc_free(v.versym);
    తిరిగి ret;
}

#నిర్వచించు LD_TOK_NAME 256
#నిర్వచించు LD_TOK_EOF  (-1)
స్థిర పూర్ణాంకం ld_inp(TCCState *s1)
{
    పూర్ణాంకం c = *s1->ld_p;
    ఒకవేళ (c == 0)
        తిరిగి CH_EOF;
    ++s1->ld_p;
    తిరిగి c;
}
#నిర్వచించు ld_unget(s1, ch) ఒకవేళ (ch != CH_EOF) --s1->ld_p

/* return next ld script token */
స్థిర పూర్ణాంకం ld_తదుపరి(TCCState *s1, అక్షరం *name, పూర్ణాంకం name_కొలత)
{
    పూర్ణాంకం c, d, ch;
    అక్షరం *q;

 redo:
    ch = ld_inp(s1);
    q = name, *q++ = ch;
    ఎంపిక(ch) {
    స్థితి ' ':
    స్థితి '\t':
    స్థితి '\f':
    స్థితి '\v':
    స్థితి '\r':
    స్థితి '\n':
        వెళ్ళు redo;
    స్థితి '/':
        ch = ld_inp(s1);
        ఒకవేళ (ch == '*') { /* comment */
            కొరకు (d = 0;; d = ch) {
                ch = ld_inp(s1);
                ఒకవేళ (ch == CH_EOF || (ch == '/' && d == '*'))
                    ఆపు;
            }
            వెళ్ళు redo;
        } లేకపోతే {
            వెళ్ళు parse_name;
        }
        ఆపు;
    స్థితి '\\':
    /* case 'a' ... 'z': */
    స్థితి 'a':
       స్థితి 'b':
       స్థితి 'c':
       స్థితి 'd':
       స్థితి 'e':
       స్థితి 'f':
       స్థితి 'g':
       స్థితి 'h':
       స్థితి 'i':
       స్థితి 'j':
       స్థితి 'k':
       స్థితి 'l':
       స్థితి 'm':
       స్థితి 'n':
       స్థితి 'o':
       స్థితి 'p':
       స్థితి 'q':
       స్థితి 'r':
       స్థితి 's':
       స్థితి 't':
       స్థితి 'u':
       స్థితి 'v':
       స్థితి 'w':
       స్థితి 'x':
       స్థితి 'y':
       స్థితి 'z':
    /* case 'A' ... 'z': */
    స్థితి 'A':
       స్థితి 'B':
       స్థితి 'C':
       స్థితి 'D':
       స్థితి 'E':
       స్థితి 'F':
       స్థితి 'G':
       స్థితి 'H':
       స్థితి 'I':
       స్థితి 'J':
       స్థితి 'K':
       స్థితి 'L':
       స్థితి 'M':
       స్థితి 'N':
       స్థితి 'O':
       స్థితి 'P':
       స్థితి 'Q':
       స్థితి 'R':
       స్థితి 'S':
       స్థితి 'T':
       స్థితి 'U':
       స్థితి 'V':
       స్థితి 'W':
       స్థితి 'X':
       స్థితి 'Y':
       స్థితి 'Z':
    స్థితి '-':
    స్థితి '_':
    స్థితి '.':
    స్థితి '$':
    స్థితి '~':
        కొరకు(;;) {
            ch = ld_inp(s1);
    parse_name:
            ఒకవేళ (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') ||
                  strchr("/.-_+=$:\\,~", ch)))
                ఆపు;
            ఒకవేళ ((q - name) < name_కొలత - 1) {
                *q++ = ch;
            }
        }
        ld_unget(s1, ch);
        c = LD_TOK_NAME;
        ఆపు;
    స్థితి CH_EOF:
        c = LD_TOK_EOF;
        ఆపు;
    అప్రమేయ:
        c = ch;
        ఆపు;
    }
    *q = '\0';
    తిరిగి c;
}

స్థిర పూర్ణాంకం ld_కూడు_file(TCCState *s1, స్థిరరాశి అక్షరం filename[])
{
    ఒకవేళ (filename[0] == '-' && filename[1] == 'l')
        తిరిగి tcc_కూడు_library(s1, filename + 2);
    ఒకవేళ (CONFIG_SYSROOT[0] != '\0' || !IS_ABSPATH(filename)) {
        /* lookup via library paths */
        పూర్ణాంకం ret = tcc_కూడు_dll(s1, tcc_basename(filename), 0);
        ఒకవేళ (ret != FILE_NOT_దొరికింది)
            తిరిగి ret;
    }
    తిరిగి tcc_కూడు_file_అంతర్గత(s1, filename, AFF_PRINT_ERROR);
}

/* did static libraries add new undefined symbols? */
స్థిర పూర్ణాంకం new_undef_sym(TCCState *s1, పూర్ణాంకం sym_స్థానభ్రంశం)
{
    అయితే (sym_స్థానభ్రంశం < s1->symtab->దత్తాంశం_స్థానభ్రంశం) {
        ElfW(Sym) *esym = (శూన్య*)(s1->symtab->దత్తాంశం + sym_స్థానభ్రంశం);
        ఒకవేళ (esym->st_shndx == SHN_UNDEF)
            తిరిగి 1;
        sym_స్థానభ్రంశం += పరిమాణం (ElfW(Sym));
    }
    తిరిగి 0;
}

స్థిర పూర్ణాంకం ld_కూడు_file_list(TCCState *s1, స్థిరరాశి అక్షరం *cmd)
{
    అక్షరం filename[1024];
    పూర్ణాంకం t, c, sym_స్థానభ్రంశం, ret = 0;
    గుర్తులేని అక్షరం *pos = s1->ld_p;

repeat:
    s1->ld_p = pos;
    sym_స్థానభ్రంశం = s1->symtab->దత్తాంశం_స్థానభ్రంశం;
    c = cmd[0];

    t = ld_తదుపరి(s1, filename, పరిమాణం(filename));
    ఒకవేళ (t != '(')
        తిరిగి tcc_error_noabort("expected '(' after %s", cmd);
    t = ld_తదుపరి(s1, filename, పరిమాణం(filename));
    కొరకు(;;) {
        ఒకవేళ (t == LD_TOK_EOF) {
            తిరిగి tcc_error_noabort("unexpected end of file");
        } లేకపోతే ఒకవేళ (t == ')') {
            ఆపు;
        } లేకపోతే ఒకవేళ (t != LD_TOK_NAME) {
            తిరిగి tcc_error_noabort("unexpected token '%c'", t);
        } లేకపోతే ఒకవేళ (!strcmp(filename, "AS_NEEDED")) {
            ret |= ld_కూడు_file_list(s1, filename);
        } లేకపోతే ఒకవేళ (c == 'I' || c == 'G' || c == 'A') {
            ret |= !!ld_కూడు_file(s1, filename);
        }
        ఒకవేళ (ret < 0)
            తిరిగి ret;
        t = ld_తదుపరి(s1, filename, పరిమాణం(filename));
        ఒకవేళ (t == ',')
            t = ld_తదుపరి(s1, filename, పరిమాణం(filename));
    }
    ఒకవేళ (c == 'G' && ret == 0 && new_undef_sym(s1, sym_స్థానభ్రంశం))
        వెళ్ళు repeat;
    తిరిగి ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC పూర్ణాంకం tcc_ఎక్కించు_ldscript(TCCState *s1, పూర్ణాంకం fd)
{
    అక్షరం cmd[64];
    పూర్ణాంకం t, ret = 0, noscript = 1;
    గుర్తులేని అక్షరం *పాఠ్యం_ptr, *saved_ptr;

    saved_ptr = s1->ld_p;
    s1->ld_p = పాఠ్యం_ptr = (శూన్య*)tcc_ఎక్కించు_పాఠ్యం(fd);
    కొరకు(;;) {
        t = ld_తదుపరి(s1, cmd, పరిమాణం(cmd));
        ఒకవేళ (t == LD_TOK_EOF)
            ఆపు;
        ఒకవేళ (!strcmp(cmd, "INPUT") ||
            !strcmp(cmd, "GROUP")) {
            ret |= ld_కూడు_file_list(s1, cmd);
        } లేకపోతే ఒకవేళ (!strcmp(cmd, "OUTPUT_FORMAT") ||
                   !strcmp(cmd, "TARGET")) {
            /* ignore some commands */
            ret |= ld_కూడు_file_list(s1, cmd);
        } లేకపోతే ఒకవేళ (noscript) {
            ret = FILE_NOT_RECOGNIZED;
        } లేకపోతే {
            ret = tcc_error_noabort("unexpected '%s'", cmd);
        }
        ఒకవేళ (ret < 0)
            ఆపు;
        noscript = 0;
    }
    tcc_free(పాఠ్యం_ptr);
    s1->ld_p = saved_ptr;
    తిరిగి ret < 0 ? ret : -ret;
}
#అయితే_ముగింపు /* !ELF_OBJ_ONLY */
