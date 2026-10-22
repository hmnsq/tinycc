#నిర్వచితమైతే లక్ష్యం_DEFS_ONLY

#నిర్వచించు EM_TCC_లక్ష్యం EM_386

/* relocation type for 32 bit data relocation */
#నిర్వచించు R_దత్తాంశం_32   R_386_32
#నిర్వచించు R_దత్తాంశం_PTR  R_386_32
#నిర్వచించు R_JMP_స్థానం  R_386_JMP_స్థానం
#నిర్వచించు R_GLOB_DAT  R_386_GLOB_DAT
#నిర్వచించు R_COPY      R_386_COPY
#నిర్వచించు R_RELATIVE  R_386_RELATIVE

#నిర్వచించు R_అంకె       R_386_అంకె

#నిర్వచించు ELF_ప్రారంభం_ADDR 0x08048000
#నిర్వచించు ELF_పుట_కొలత  0x1000

#ఒకవేళ defined CONFIG_TCC_PIC
#నిర్వచించు PCRELATIVE_DLLPLT 1
#లేకపోతే
#నిర్వచించు PCRELATIVE_DLLPLT 0
#అయితే_ముగింపు
#నిర్వచించు RELOCATE_DLLPLT 1

#లేకపోతే /* !TARGET_DEFS_ONLY */

#అన్తర్భావ "tcc.h"

#నిర్వచితమైతే NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC పూర్ణాంకం సంకేతం_reloc (పూర్ణాంకం reloc_type)
{
    ఎంపిక (reloc_type) {
	స్థితి R_386_RELATIVE:
	స్థితి R_386_16:
        స్థితి R_386_32:
	స్థితి R_386_GOTPC:
	స్థితి R_386_GOTOFF:
	స్థితి R_386_GOT32:
	స్థితి R_386_GOT32X:
	స్థితి R_386_GLOB_DAT:
	స్థితి R_386_COPY:
	స్థితి R_386_TLS_GD:
	స్థితి R_386_TLS_LDM:
	స్థితి R_386_TLS_LDO_32:
	స్థితి R_386_TLS_LE:
            తిరిగి 0;

	స్థితి R_386_PC16:
	స్థితి R_386_PC32:
	స్థితి R_386_PLT32:
	స్థితి R_386_JMP_స్థానం:
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
	స్థితి R_386_RELATIVE:
	స్థితి R_386_16:
	స్థితి R_386_GLOB_DAT:
	స్థితి R_386_JMP_స్థానం:
	స్థితి R_386_COPY:
            తిరిగి NO_GOTPLT_నమోదు;

        స్థితి R_386_32:
	    /* This relocations shouldn't normally need GOT or PLT
	       slots if it weren't for simplicity in the code generator.
	       See our caller for comments.  */
            తిరిగి AUTO_GOTPLT_నమోదు;

	స్థితి R_386_PC16:
	స్థితి R_386_PC32:
            తిరిగి AUTO_GOTPLT_నమోదు;

	స్థితి R_386_GOTPC:
	స్థితి R_386_GOTOFF:
            తిరిగి BUILD_GOT_ONLY;

	స్థితి R_386_GOT32:
	స్థితి R_386_GOT32X:
	స్థితి R_386_PLT32:
	స్థితి R_386_TLS_GD:
	స్థితి R_386_TLS_LDM:
	స్థితి R_386_TLS_LDO_32:
	స్థితి R_386_TLS_LE:
            తిరిగి ALWAYS_GOTPLT_నమోదు;
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

    /* on i386 if we build a DLL, we add a %ebx offset */
    ఒకవేళ (s1->output_type & TCC_OUTPUT_DYN)
        modrm = 0xa3;
    లేకపోతే
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
    write32le(p + 7, relofs - పరిమాణం (ElfW_Rel));
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

    ఒకవేళ (!(s1->output_type & TCC_OUTPUT_DYN) && p < p_చివర) {
        add32le(p + 2, s1->got->sh_addr);
        add32le(p + 8, s1->got->sh_addr);
        p += 16;
        అయితే (p < p_చివర) {
            add32le(p + 2, s1->got->sh_addr);
            p += 16;
        }
    }

    ఒకవేళ (s1->plt->reloc) {
        ElfW_Rel *rel;
        పూర్ణాంకం x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->దత్తాంశం;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_స్థానభ్రంశం, x);
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
        స్థితి R_386_32:
            ఒకవేళ (s1->output_type & TCC_OUTPUT_DYN) {
                esym_సూచీ = get_sym_attr(s1, sym_సూచీ, 0)->dyn_సూచీ;
                qrel->r_స్థానభ్రంశం = rel->r_స్థానభ్రంశం;
                ఒకవేళ (esym_సూచీ) {
                    qrel->r_info = ELFW(R_INFO)(esym_సూచీ, R_386_32);
                    qrel++;
                    తిరిగి;
                } లేకపోతే {
                    qrel->r_info = ELFW(R_INFO)(0, R_386_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            తిరిగి;
        స్థితి R_386_PC32:
            ఒకవేళ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_సూచీ = get_sym_attr(s1, sym_సూచీ, 0)->dyn_సూచీ;
                ఒకవేళ (esym_సూచీ) {
                    qrel->r_స్థానభ్రంశం = rel->r_స్థానభ్రంశం;
                    qrel->r_info = ELFW(R_INFO)(esym_సూచీ, R_386_PC32);
                    qrel++;
                    తిరిగి;
                }
            }
            add32le(ptr, val - addr);
            తిరిగి;
        స్థితి R_386_PLT32:
            add32le(ptr, val - addr);
            తిరిగి;
        స్థితి R_386_GLOB_DAT:
        స్థితి R_386_JMP_స్థానం:
            write32le(ptr, val);
            తిరిగి;
        స్థితి R_386_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            తిరిగి;
        స్థితి R_386_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            తిరిగి;
        స్థితి R_386_GOT32:
        స్థితి R_386_GOT32X:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_సూచీ, 0)->got_స్థానభ్రంశం);
            తిరిగి;
        స్థితి R_386_16:
            ఒకవేళ (s1->output_format != TCC_OUTPUT_FORMAT_ద్విమాన) {
            output_file:
                tcc_error_noabort("can only produce 16-bit binary files");
            }
            write16le(ptr, read16le(ptr) + val);
            తిరిగి;
        స్థితి R_386_PC16:
            ఒకవేళ (s1->output_format != TCC_OUTPUT_FORMAT_ద్విమాన)
                వెళ్ళు output_file;
            write16le(ptr, read16le(ptr) + val - addr);
            తిరిగి;
        స్థితి R_386_RELATIVE:
#నిర్వచితమైతే TCC_లక్ష్యం_PE
            add32le(ptr, val - s1->pe_imagebase);
#అయితే_ముగింపు
            /* do nothing */
            తిరిగి;
        స్థితి R_386_COPY:
            /* This relocation must copy initialized data from the library
            to the program .bss segment. Currently made like for ARM
            (to remove noise of default case). Is this true?
            */
            తిరిగి;
        స్థితి R_386_TLS_GD:
            {
                స్థిర స్థిరరాశి గుర్తులేని అక్షరం expect[] = {
                    /* lea 0(,%ebx,1),%eax */
                    0x8d, 0x04, 0x1d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                స్థిర స్థిరరాశి గుర్తులేని అక్షరం replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* sub 0,%eax */
                    0x81, 0xe8, 0x00, 0x00, 0x00, 0x00 };

                ఒకవేళ (memcmp (ptr-3, expect, పరిమాణం(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    జ్ఞాపకం_నకలు(ptr-3, replace, పరిమాణం(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_విలువ - sec->sh_addr - sec->దత్తాంశం_స్థానభ్రంశం;
                    add32le(ptr + 5, -x);
                }
                లేకపోతే
                    tcc_error_noabort("unexpected R_386_TLS_GD pattern");
            }
            తిరిగి;
        స్థితి R_386_TLS_LDM:
            {
                స్థిర స్థిరరాశి గుర్తులేని అక్షరం expect[] = {
                    /* lea 0(%ebx),%eax */
                    0x8d, 0x83, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                స్థిర స్థిరరాశి గుర్తులేని అక్షరం replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* nop */
                    0x90,
                    /* lea 0(%esi,%eiz,1),%esi */
                    0x8d, 0x74, 0x26, 0x00 };

                ఒకవేళ (memcmp (ptr-2, expect, పరిమాణం(expect)) == 0) {
                    జ్ఞాపకం_నకలు(ptr-2, replace, పరిమాణం(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                }
                లేకపోతే
                    tcc_error_noabort("unexpected R_386_TLS_LDM pattern");
            }
            తిరిగి;
        స్థితి R_386_TLS_LDO_32:
            {
                ElfW(Sym) *sym;
                Section *sec;
                int32_t x;

                sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
                sec = s1->sections[sym->st_shndx];
                x = val - sec->sh_addr - sec->దత్తాంశం_స్థానభ్రంశం;
                add32le(ptr, x);
            }
            తిరిగి;
        స్థితి R_386_TLS_LE:
            {
                int32_t x;
                ఒకవేళ (s1->tls_చివర) {
                    x = val - s1->tls_చివర;
                } లేకపోతే {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->దత్తాంశం_స్థానభ్రంశం;
                }
                add32le(ptr, x);
            }
            తిరిగి;
        స్థితి R_386_NONE:
            తిరిగి;
        అప్రమేయ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (గుర్తులేని)addr, ptr, (గుర్తులేని)val);
            తిరిగి;
    }
}

#అయితే_ముగింపు /* !TARGET_DEFS_ONLY */
