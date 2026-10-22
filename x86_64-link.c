#నిర్వచితమైతే లక్ష్యం_DEFS_ONLY

#నిర్వచించు EM_TCC_లక్ష్యం EM_X86_64

/* relocation type for 32 bit data relocation */
#నిర్వచించు R_దత్తాంశం_32   R_X86_64_32S
#నిర్వచించు R_దత్తాంశం_PTR  R_X86_64_64
#నిర్వచించు R_JMP_స్థానం  R_X86_64_JUMP_స్థానం
#నిర్వచించు R_GLOB_DAT  R_X86_64_GLOB_DAT
#నిర్వచించు R_COPY      R_X86_64_COPY
#నిర్వచించు R_RELATIVE  R_X86_64_RELATIVE

#నిర్వచించు R_అంకె       R_X86_64_అంకె

#నిర్వచించు ELF_ప్రారంభం_ADDR 0x400000
#నిర్వచించు ELF_పుట_కొలత  0x1000

#నిర్వచించు PCRELATIVE_DLLPLT 1
#నిర్వచించు RELOCATE_DLLPLT 1

#లేకపోతే /* !TARGET_DEFS_ONLY */

#అన్తర్భావ "tcc.h"

#నిర్వచితమైతే NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC పూర్ణాంకం సంకేతం_reloc (పూర్ణాంకం reloc_type)
{
    ఎంపిక (reloc_type) {
        స్థితి R_X86_64_32:
        స్థితి R_X86_64_32S:
        స్థితి R_X86_64_64:
        స్థితి R_X86_64_GOTPC32:
        స్థితి R_X86_64_GOTPC64:
        స్థితి R_X86_64_GOTPCREL:
        స్థితి R_X86_64_GOTPCRELX:
        స్థితి R_X86_64_REX_GOTPCRELX:
        స్థితి R_X86_64_GOTTPOFF:
        స్థితి R_X86_64_GOT32:
        స్థితి R_X86_64_GOT64:
        స్థితి R_X86_64_GLOB_DAT:
        స్థితి R_X86_64_COPY:
        స్థితి R_X86_64_RELATIVE:
        స్థితి R_X86_64_GOTOFF64:
        స్థితి R_X86_64_TLSGD:
        స్థితి R_X86_64_TLSLD:
        స్థితి R_X86_64_DTPOFF32:
        స్థితి R_X86_64_TPOFF32:
        స్థితి R_X86_64_DTPOFF64:
        స్థితి R_X86_64_TPOFF64:
            తిరిగి 0;

        స్థితి R_X86_64_PC32:
        స్థితి R_X86_64_PC64:
        స్థితి R_X86_64_PLT32:
        స్థితి R_X86_64_PLTOFF64:
        స్థితి R_X86_64_JUMP_స్థానం:
            తిరిగి 1;
    }
    తిరిగి -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC పూర్ణాంకం gotplt_నమోదు_type (పూర్ణాంకం reloc_type)
{
    ఎంపిక (reloc_type) {
        స్థితి R_X86_64_GLOB_DAT:
        స్థితి R_X86_64_JUMP_స్థానం:
        స్థితి R_X86_64_COPY:
        స్థితి R_X86_64_RELATIVE:
            తిరిగి NO_GOTPLT_నమోదు;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        స్థితి R_X86_64_32:
        స్థితి R_X86_64_32S:
        స్థితి R_X86_64_64:
        స్థితి R_X86_64_PC32:
        స్థితి R_X86_64_PC64:
            తిరిగి AUTO_GOTPLT_నమోదు;

        స్థితి R_X86_64_GOTTPOFF:
            తిరిగి BUILD_GOT_ONLY;

        స్థితి R_X86_64_GOT32:
        స్థితి R_X86_64_GOT64:
        స్థితి R_X86_64_GOTPC32:
        స్థితి R_X86_64_GOTPC64:
        స్థితి R_X86_64_GOTOFF64:
        స్థితి R_X86_64_GOTPCREL:
        స్థితి R_X86_64_GOTPCRELX:
        స్థితి R_X86_64_TLSGD:
        స్థితి R_X86_64_TLSLD:
        స్థితి R_X86_64_DTPOFF32:
        స్థితి R_X86_64_DTPOFF64:
        స్థితి R_X86_64_REX_GOTPCRELX:
        స్థితి R_X86_64_PLT32:
        స్థితి R_X86_64_PLTOFF64:
            తిరిగి ALWAYS_GOTPLT_నమోదు;

        స్థితి R_X86_64_TPOFF32:
        స్థితి R_X86_64_TPOFF64:
            తిరిగి NO_GOTPLT_నమోదు;
    }

    తిరిగి -1;
}

#నిర్వచితమైతే NEED_BUILD_GOT
ST_FUNC గుర్తులేని create_plt_నమోదు(TCCState *s1, గుర్తులేని got_స్థానభ్రంశం, నిర్మాణం sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    పూర్ణాంకం modrm;
    గుర్తులేని plt_స్థానభ్రంశం, relofs;

    modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    ఒకవేళ (plt->దత్తాంశం_స్థానభ్రంశం == 0) {
        p = section_ptr_కూడు(plt, 16);
        p[0] = 0xff; /* pushl got + PTR_SIZE */
        p[1] = modrm + 0x10;
        write32le(p + 2, PTR_కొలత);
        p[6] = 0xff; /* jmp *(got + PTR_SIZE * 2) */
        p[7] = modrm;
        write32le(p + 8, PTR_కొలత * 2);
    }
    plt_స్థానభ్రంశం = plt->దత్తాంశం_స్థానభ్రంశం;

    /* The PLT slot refers to the relocation entry it needs via offset.
       The reloc entry is created below, so its offset is the current
       data_offset */
    relofs = s1->plt->reloc ? s1->plt->reloc->దత్తాంశం_స్థానభ్రంశం : 0;

    /* Jump to GOT entry where ld.so initially put the address of ip + 4 */
    p = section_ptr_కూడు(plt, 16);
    p[0] = 0xff; /* jmp *(got + x) */
    p[1] = modrm;
    write32le(p + 2, got_స్థానభ్రంశం);
    p[6] = 0x68; /* push $xxx */
    /* On x86-64, the relocation is referred to by _index_ */
    write32le(p + 7, relofs / పరిమాణం (ElfW_Rel) - 1);
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->దత్తాంశం_స్థానభ్రంశం));
    తిరిగి plt_స్థానభ్రంశం;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC శూన్య relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_చివర;

    ఒకవేళ (!s1->plt)
      తిరిగి;

    p = s1->plt->దత్తాంశం;
    p_చివర = p + s1->plt->దత్తాంశం_స్థానభ్రంశం;

    ఒకవేళ (p < p_చివర) {
        పూర్ణాంకం x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        అయితే (p < p_చివర) {
            add32le(p + 2, x + (s1->plt->దత్తాంశం - p));
            p += 16;
        }
    }

    ఒకవేళ (s1->plt->reloc) {
        ElfW_Rel *rel;
        పూర్ణాంకం x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->దత్తాంశం;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_స్థానభ్రంశం, x);
            x += 16;
        }
    }
}
#అయితే_ముగింపు
#అయితే_ముగింపు

ST_FUNC శూన్య relocate(TCCState *s1, ElfW_Rel *rel, పూర్ణాంకం type, గుర్తులేని అక్షరం *ptr, addr_t addr, addr_t val)
{
    పూర్ణాంకం sym_సూచీ, esym_సూచీ;

    sym_సూచీ = ELFW(R_SYM)(rel->r_info);

    ఎంపిక (type) {
        స్థితి R_X86_64_64:
            ఒకవేళ (s1->output_type & TCC_OUTPUT_DYN) {
                esym_సూచీ = get_sym_attr(s1, sym_సూచీ, 0)->dyn_సూచీ;
                qrel->r_స్థానభ్రంశం = rel->r_స్థానభ్రంశం;
                ఒకవేళ (esym_సూచీ) {
                    qrel->r_info = ELFW(R_INFO)(esym_సూచీ, R_X86_64_64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    ఆపు;
                } లేకపోతే {
                    qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            ఆపు;
        స్థితి R_X86_64_32:
        స్థితి R_X86_64_32S:
            ఒకవేళ (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_స్థానభ్రంశం = rel->r_స్థానభ్రంశం;
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (పూర్ణాంకం)read32le(ptr) + val;
                qrel++;
            }
            ఒకవేళ ((type == R_X86_64_32 ? val != (గుర్తులేని)val : val != (పూర్ణాంకం)val)
                /* ignore relocation check for stab section */
                && (stab_section == ఖాళీ ||
                    addr < stab_section->sh_addr ||
                    addr >= (stab_section->sh_addr + stab_section->దత్తాంశం_స్థానభ్రంశం))) {
                tcc_error_noabort("relocation 'R_X86_64_32[S]' out of range");
            }
            add32le(ptr, val);
            ఆపు;

        స్థితి R_X86_64_PC32:
            ఒకవేళ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_సూచీ = get_sym_attr(s1, sym_సూచీ, 0)->dyn_సూచీ;
                ఒకవేళ (esym_సూచీ) {
                    qrel->r_స్థానభ్రంశం = rel->r_స్థానభ్రంశం;
                    qrel->r_info = ELFW(R_INFO)(esym_సూచీ, R_X86_64_PC32);
                    /* Use sign extension! */
                    qrel->r_addend = (పూర్ణాంకం)read32le(ptr) + rel->r_addend;
                    qrel++;
                    ఆపు;
                }
            }
            వెళ్ళు plt32pc32;

        స్థితి R_X86_64_PLT32:
            /* fallthrough: val already holds the PLT slot address */

        plt32pc32:
        {
            దీర్ఘ దీర్ఘ diff;
            diff = (దీర్ఘ దీర్ఘ)val - addr;
            ఒకవేళ (diff < -2147483648LL || diff > 2147483647LL) {
#నిర్వచితమైతే TCC_లక్ష్యం_PE
              /* ignore overflow with undefined weak symbols */
              ఒకవేళ (((ElfW(Sym)*)symtab_section->దత్తాంశం)[sym_సూచీ].st_shndx != SHN_UNDEF)
#అయితే_ముగింపు
                tcc_error_noabort("relocation '%d' out of range", type);
            }
            add32le(ptr, diff);
        }
            ఆపు;

        స్థితి R_X86_64_COPY:
	    ఆపు;

        స్థితి R_X86_64_PLTOFF64:
            add64le(ptr, val - s1->got->sh_addr + rel->r_addend);
            ఆపు;

        స్థితి R_X86_64_PC64:
            ఒకవేళ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_సూచీ = get_sym_attr(s1, sym_సూచీ, 0)->dyn_సూచీ;
                ఒకవేళ (esym_సూచీ) {
                    qrel->r_స్థానభ్రంశం = rel->r_స్థానభ్రంశం;
                    qrel->r_info = ELFW(R_INFO)(esym_సూచీ, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    ఆపు;
                }
            }
            add64le(ptr, val - addr);
            ఆపు;

        స్థితి R_X86_64_GLOB_DAT:
        స్థితి R_X86_64_JUMP_స్థానం:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            ఆపు;
        స్థితి R_X86_64_GOTPCREL:
        స్థితి R_X86_64_GOTPCRELX:
        స్థితి R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         get_sym_attr(s1, sym_సూచీ, 0)->got_స్థానభ్రంశం - 4);
            ఆపు;
        స్థితి R_X86_64_GOTPC32:
            add32le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            ఆపు;
        స్థితి R_X86_64_GOTPC64:
            add64le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            ఆపు;
        స్థితి R_X86_64_GOTTPOFF:
            add32le(ptr, val - s1->got->sh_addr);
            ఆపు;
        స్థితి R_X86_64_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_సూచీ, 0)->got_స్థానభ్రంశం);
            ఆపు;
        స్థితి R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, get_sym_attr(s1, sym_సూచీ, 0)->got_స్థానభ్రంశం);
            ఆపు;
        స్థితి R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            ఆపు;
        స్థితి R_X86_64_TLSGD:
            {
                స్థిర స్థిరరాశి గుర్తులేని అక్షరం expect[] = {
                    /* .byte 0x66; lea 0(%rip),%rdi */
                    0x66, 0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* .word 0x6666; rex64; call __tls_get_addr@PLT */
                    0x66, 0x66, 0x48, 0xe8, 0x00, 0x00, 0x00, 0x00 };
                స్థిర స్థిరరాశి గుర్తులేని అక్షరం replace[] = {
                    /* mov %fs:0,%rax */
                    0x64, 0x48, 0x8b, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
                    /* lea -4(%rax),%rax */
                    0x48, 0x8d, 0x80, 0x00, 0x00, 0x00, 0x00 };

                ఒకవేళ (memcmp (ptr-4, expect, పరిమాణం(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    జ్ఞాపకం_నకలు(ptr-4, replace, పరిమాణం(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_విలువ - sec->sh_addr - sec->దత్తాంశం_స్థానభ్రంశం;
                    add32le(ptr + 8, x);
                }
                లేకపోతే
                    tcc_error_noabort("unexpected R_X86_64_TLSGD pattern");
            }
            ఆపు;
        స్థితి R_X86_64_TLSLD:
            {
                స్థిర స్థిరరాశి గుర్తులేని అక్షరం expect[] = {
                    /* lea 0(%rip),%rdi */
                    0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0x00, 0x00, 0x00, 0x00 };
                స్థిర స్థిరరాశి గుర్తులేని అక్షరం replace[] = {
                    /* data16 data16 data16 mov %fs:0,%rax */
                    0x66, 0x66, 0x66, 0x64, 0x48, 0x8b, 0x04, 0x25,
                    0x00, 0x00, 0x00, 0x00 };

                ఒకవేళ (memcmp (ptr-3, expect, పరిమాణం(expect)) == 0) {
                    జ్ఞాపకం_నకలు(ptr-3, replace, పరిమాణం(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                }
                లేకపోతే
                    tcc_error_noabort("unexpected R_X86_64_TLSLD pattern");
            }
            ఆపు;

        స్థితి R_X86_64_DTPOFF32:
        స్థితి R_X86_64_TPOFF32:
        స్థితి R_X86_64_DTPOFF64:
        స్థితి R_X86_64_TPOFF64:
            {
                int32_t x;
                ఒకవేళ (s1->tls_చివర) {
                    x = val - s1->tls_చివర;
                } లేకపోతే {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->దత్తాంశం_స్థానభ్రంశం;
                }
                ఎంపిక (type) {
                స్థితి R_X86_64_DTPOFF64:
                స్థితి R_X86_64_TPOFF64:
                    add64le(ptr, x);
                    ఆపు;
                అప్రమేయ:
                    add32le(ptr, x);
                    ఆపు;
                }
            }
            ఆపు;
        స్థితి R_X86_64_NONE:
            ఆపు;
        స్థితి R_X86_64_RELATIVE:
#నిర్వచితమైతే TCC_లక్ష్యం_PE
            add32le(ptr, val - s1->pe_imagebase);
#అయితే_ముగింపు
            /* do nothing */
            ఆపు;
        అప్రమేయ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (గుర్తులేని)addr, ptr, (గుర్తులేని)val);
            ఆపు;
    }
}

#అయితే_ముగింపు /* !TARGET_DEFS_ONLY */
