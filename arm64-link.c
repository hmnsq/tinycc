#నిర్వచితమైతే లక్ష్యం_DEFS_ONLY

#నిర్వచించు EM_TCC_లక్ష్యం EM_AARCH64

#నిర్వచించు R_దత్తాంశం_32  R_AARCH64_ABS32
#నిర్వచించు R_దత్తాంశం_PTR R_AARCH64_ABS64
#నిర్వచించు R_JMP_స్థానం R_AARCH64_JUMP_స్థానం
#నిర్వచించు R_GLOB_DAT R_AARCH64_GLOB_DAT
#నిర్వచించు R_COPY     R_AARCH64_COPY
#నిర్వచించు R_RELATIVE R_AARCH64_RELATIVE

#నిర్వచించు R_అంకె      R_AARCH64_అంకె

#నిర్వచించు ELF_ప్రారంభం_ADDR 0x00400000
#నిర్వచించు ELF_పుట_కొలత 0x10000

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
        స్థితి R_AARCH64_ABS32:
        స్థితి R_AARCH64_ABS64:
	స్థితి R_AARCH64_PREL32:
        స్థితి R_AARCH64_MOVW_UABS_G0_NC:
        స్థితి R_AARCH64_MOVW_UABS_G1_NC:
        స్థితి R_AARCH64_MOVW_UABS_G2_NC:
        స్థితి R_AARCH64_MOVW_UABS_G3:
        స్థితి R_AARCH64_ADR_PREL_PG_HI21:
        స్థితి R_AARCH64_కూడు_ABS_LO12_NC:
        స్థితి R_AARCH64_ADR_GOT_పుట:
        స్థితి R_AARCH64_LD64_GOT_LO12_NC:
        స్థితి R_AARCH64_LDST128_ABS_LO12_NC:
        స్థితి R_AARCH64_LDST64_ABS_LO12_NC:
        స్థితి R_AARCH64_LDST32_ABS_LO12_NC:
        స్థితి R_AARCH64_LDST16_ABS_LO12_NC:
        స్థితి R_AARCH64_LDST8_ABS_LO12_NC:
        స్థితి R_AARCH64_TLSLE_కూడు_TPREL_HI12:
        స్థితి R_AARCH64_TLSLE_కూడు_TPREL_LO12:
        స్థితి R_AARCH64_GLOB_DAT:
        స్థితి R_AARCH64_COPY:
            తిరిగి 0;

        స్థితి R_AARCH64_JUMP26:
        స్థితి R_AARCH64_CALL26:
        స్థితి R_AARCH64_JUMP_స్థానం:
        స్థితి R_AARCH64_CONDBR19:
        స్థితి R_AARCH64_TSTBR14:
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
	స్థితి R_AARCH64_PREL32:
        స్థితి R_AARCH64_MOVW_UABS_G0_NC:
        స్థితి R_AARCH64_MOVW_UABS_G1_NC:
        స్థితి R_AARCH64_MOVW_UABS_G2_NC:
        స్థితి R_AARCH64_MOVW_UABS_G3:
        స్థితి R_AARCH64_ADR_PREL_PG_HI21:
        స్థితి R_AARCH64_కూడు_ABS_LO12_NC:
        స్థితి R_AARCH64_LDST128_ABS_LO12_NC:
        స్థితి R_AARCH64_LDST64_ABS_LO12_NC:
        స్థితి R_AARCH64_LDST32_ABS_LO12_NC:
        స్థితి R_AARCH64_LDST16_ABS_LO12_NC:
        స్థితి R_AARCH64_LDST8_ABS_LO12_NC:
        స్థితి R_AARCH64_GLOB_DAT:
        స్థితి R_AARCH64_JUMP_స్థానం:
        స్థితి R_AARCH64_COPY:
        స్థితి R_AARCH64_CONDBR19:
        స్థితి R_AARCH64_TSTBR14:
        స్థితి R_AARCH64_TLSLE_కూడు_TPREL_HI12:
        స్థితి R_AARCH64_TLSLE_కూడు_TPREL_LO12:
            తిరిగి NO_GOTPLT_నమోదు;

        స్థితి R_AARCH64_ABS32:
        స్థితి R_AARCH64_ABS64:
        స్థితి R_AARCH64_JUMP26:
        స్థితి R_AARCH64_CALL26:
            తిరిగి AUTO_GOTPLT_నమోదు;

        స్థితి R_AARCH64_ADR_GOT_పుట:
        స్థితి R_AARCH64_LD64_GOT_LO12_NC:
            తిరిగి ALWAYS_GOTPLT_నమోదు;
    }
    తిరిగి -1;
}

#నిర్వచితమైతే NEED_BUILD_GOT
ST_FUNC గుర్తులేని create_plt_నమోదు(TCCState *s1, గుర్తులేని got_స్థానభ్రంశం, నిర్మాణం sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    గుర్తులేని plt_స్థానభ్రంశం;

    ఒకవేళ (plt->దత్తాంశం_స్థానభ్రంశం == 0) {
        section_ptr_కూడు(plt, 32);
    }
    plt_స్థానభ్రంశం = plt->దత్తాంశం_స్థానభ్రంశం;

    p = section_ptr_కూడు(plt, 16);
    write32le(p, got_స్థానభ్రంశం);
    write32le(p + 4, (uint64_t) got_స్థానభ్రంశం >> 32);
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
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr + 16;
        uint64_t off = (got >> 12) - (plt >> 12);
        ఒకవేళ ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (దీర్ఘ)off, (దీర్ఘ)got, (దీర్ఘ)plt);
        write32le(p, ARM64_STP_X_PRE | ARM64_RT(16) | ARM64_RT2(30) |
                      ARM64_RN(31) | ARM64_IMM7(-2)); // stp x16,x30,[sp,#-16]!
        write32le(p + 4, (ARM64_ADRP | ARM64_RD(16) | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
        write32le(p + 8, (ARM64_LDR_X | ARM64_RT(17) | ARM64_RN(16) | // ldr x17,[x16,#...]
			  (got & 0xff8) << 7));
        write32le(p + 12, (ARM64_కూడు_IMM | ARM64_SF(1) | ARM64_RD(16) | ARM64_RN(16) | // add x16,x16,#...
			   (got & 0xfff) << 10));
        write32le(p + 16, ARM64_BR | ARM64_RN(17)); // br x17
        write32le(p + 20, ARM64_NOP); // nop
        write32le(p + 24, ARM64_NOP); // nop
        write32le(p + 28, ARM64_NOP); // nop
        p += 32;
	got = s1->got->sh_addr;
        అయితే (p < p_చివర) {
            uint64_t pc = plt + (p - s1->plt->దత్తాంశం);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr >> 12) - (pc >> 12);
            ఒకవేళ ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (దీర్ఘ)off, (దీర్ఘ)addr, (దీర్ఘ)pc);
            write32le(p, (ARM64_ADRP | ARM64_RD(16) | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
            write32le(p + 4, (ARM64_LDR_X | ARM64_RT(17) | ARM64_RN(16) | // ldr x17,[x16,#...]
			      (addr & 0xff8) << 7));
            write32le(p + 8, (ARM64_కూడు_IMM | ARM64_SF(1) | ARM64_RD(16) | ARM64_RN(16) | // add x16,x16,#...
			      (addr & 0xfff) << 10));
            write32le(p + 12, ARM64_BR | ARM64_RN(17)); // br x17
            p += 16;
        }
    }

    ఒకవేళ (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->దత్తాంశం;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_స్థానభ్రంశం, s1->plt->sh_addr);
	}
    }
}
#అయితే_ముగింపు
#అయితే_ముగింపు

ST_FUNC శూన్య relocate(TCCState *s1, ElfW_Rel *rel, పూర్ణాంకం type, గుర్తులేని అక్షరం *ptr, addr_t addr, addr_t val)
{
    పూర్ణాంకం sym_సూచీ = ELFW(R_SYM)(rel->r_info), esym_సూచీ;
#నిర్వచితమైతే DEBUG_RELOC
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
#అయితే_ముగింపు

    ఎంపిక(type) {
        స్థితి R_AARCH64_ABS64:
            ఒకవేళ ((s1->output_type & TCC_OUTPUT_DYN)) {
                esym_సూచీ = get_sym_attr(s1, sym_సూచీ, 0)->dyn_సూచీ;
                qrel->r_స్థానభ్రంశం = rel->r_స్థానభ్రంశం;
                ఒకవేళ (esym_సూచీ) {
                    qrel->r_info = ELFW(R_INFO)(esym_సూచీ, R_AARCH64_ABS64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    ఆపు;
                } లేకపోతే {
                    qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            తిరిగి;
        స్థితి R_AARCH64_ABS32:
            ఒకవేళ (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_AARCH64_RELATIVE even for a 64bit pointer */
                qrel->r_స్థానభ్రంశం = rel->r_స్థానభ్రంశం;
                qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (పూర్ణాంకం)read32le(ptr) + val;
                qrel++;
            }
            add32le(ptr, val);
            తిరిగి;
	స్థితి R_AARCH64_PREL32:
            ఒకవేళ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_సూచీ = get_sym_attr(s1, sym_సూచీ, 0)->dyn_సూచీ;
                ఒకవేళ (esym_సూచీ) {
                    qrel->r_స్థానభ్రంశం = rel->r_స్థానభ్రంశం;
                    qrel->r_info = ELFW(R_INFO)(esym_సూచీ, R_AARCH64_PREL32);
                    /* Use sign extension! */
                    qrel->r_addend = (పూర్ణాంకం)read32le(ptr) + rel->r_addend;
                    qrel++;
                    ఆపు;
                }
            }
	    add32le(ptr, val - addr);
	    తిరిగి;
        స్థితి R_AARCH64_MOVW_UABS_G0_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val & 0xffff) << 5));
            తిరిగి;
        స్థితి R_AARCH64_MOVW_UABS_G1_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 16 & 0xffff) << 5));
            తిరిగి;
        స్థితి R_AARCH64_MOVW_UABS_G2_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 32 & 0xffff) << 5));
            తిరిగి;
        స్థితి R_AARCH64_MOVW_UABS_G3:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 48 & 0xffff) << 5));
            తిరిగి;
        స్థితి R_AARCH64_ADR_PREL_PG_HI21: {
            uint64_t off = (val >> 12) - (addr >> 12);
#నిర్వచితమైతే TCC_లక్ష్యం_PE
            /* Weak undefined symbols resolve to address 0 on PE. ADRP cannot
               encode that from the default 64-bit image base, so materialize
               zero directly and let the paired ADD handle any low addend. */
            ఒకవేళ ((off + ((uint64_t)1 << 20)) >> 21) {
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
                ఒకవేళ (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, 0xd2800000 | (read32le(ptr) & 0x1f));
                    తిరిగి;
                }
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
            }
#లేకపోతే
            ఒకవేళ ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
#అయితే_ముగింపు
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            తిరిగి;
        }
        స్థితి R_AARCH64_కూడు_ABS_LO12_NC:
        స్థితి R_AARCH64_LDST8_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xfff) << 10));
            తిరిగి;
        స్థితి R_AARCH64_LDST16_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffe) << 9));
            తిరిగి;
        స్థితి R_AARCH64_LDST32_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffc) << 8));
            తిరిగి;
        స్థితి R_AARCH64_LDST64_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff8) << 7));
            తిరిగి;
        స్థితి R_AARCH64_LDST128_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff0) << 6));
            తిరిగి;
        స్థితి R_AARCH64_CONDBR19:
            /* Conditional branch: 19-bit signed offset, bits 23:5 */
#నిర్వచితమైతే DEBUG_RELOC
     రాయి ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name);
#అయితే_ముగింపు
            ఒకవేళ (((val - addr) + ((uint64_t)1 << 20)) & ~(uint64_t)0x1ffffc)
                tcc_error_noabort("R_AARCH64_CONDBR19 relocation failed"
                          " (val=%lx, addr=%lx)", (దీర్ఘ)val, (దీర్ఘ)addr);
            write32le(ptr, ((read32le(ptr) & 0xff00001f) |
                            (((val - addr) >> 2 & 0x7ffff) << 5)));
            తిరిగి;
        స్థితి R_AARCH64_TSTBR14:
            /* Test and branch: 14-bit signed offset, bits 20:5 */
#నిర్వచితమైతే DEBUG_RELOC
     రాయి ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name);
#అయితే_ముగింపు
            ఒకవేళ (((val - addr) + ((uint64_t)1 << 15)) & ~(uint64_t)0xfffc)
                tcc_error_noabort("R_AARCH64_TSTBR14 relocation failed"
                          " (val=%lx, addr=%lx)", (దీర్ఘ)val, (దీర్ఘ)addr);
            write32le(ptr, ((read32le(ptr) & 0xfff8001f) |
                            (((val - addr) >> 2 & 0x3fff) << 5)));
            తిరిగి;
        స్థితి R_AARCH64_JUMP26:
        స్థితి R_AARCH64_CALL26:
        {
            స్థిరరాశి అక్షరం *name;
#నిర్వచితమైతే DEBUG_RELOC
	    రాయి ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
		    (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name);
#అయితే_ముగింపు
            ఒకవేళ (((val - addr) + ((uint64_t)1 << 27)) & ~(uint64_t)0xffffffc) {
#నిర్వచితమైతే TCC_లక్ష్యం_PE
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
                ఒకవేళ (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, ARM64_NOP); /* nop */
                    తిరిగి;
                }
#అయితే_ముగింపు
                name = (అక్షరం *)symtab_section->link->దత్తాంశం +
                    ((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ].st_name;
                tcc_error_noabort("R_AARCH64_(JUMP|CALL)26 relocation failed"
                          " for '%s' (val=%lx, addr=%lx)",
                          name, (దీర్ఘ)val, (దీర్ఘ)addr);
            }
            write32le(ptr, (0x14000000 |
                            (uint32_t)(type == R_AARCH64_CALL26) << 31 |
                            ((val - addr) >> 2 & 0x3ffffff)));
            తిరిగి;
        }
        స్థితి R_AARCH64_ADR_GOT_పుట: {
            uint64_t off =
                (((s1->got->sh_addr +
                   get_sym_attr(s1, sym_సూచీ, 0)->got_స్థానభ్రంశం) >> 12) - (addr >> 12));
            ఒకవేళ ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_GOT_PAGE relocation failed");
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            తిరిగి;
        }
        స్థితి R_AARCH64_LD64_GOT_LO12_NC:
            write32le(ptr,
                      ((read32le(ptr) & 0xfff803ff) |
                       ((s1->got->sh_addr +
                         get_sym_attr(s1, sym_సూచీ, 0)->got_స్థానభ్రంశం) & 0xff8) << 7));
            తిరిగి;
        స్థితి R_AARCH64_COPY:
            తిరిగి;
        స్థితి R_AARCH64_GLOB_DAT:
        స్థితి R_AARCH64_JUMP_స్థానం:
            /* They don't need addend */
#నిర్వచితమైతే DEBUG_RELOC
	    రాయి ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr,
		    val - rel->r_addend,
		    (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name);
#అయితే_ముగింపు
            write64le(ptr, val - rel->r_addend);
            తిరిగి;
        స్థితి R_AARCH64_TLSLE_కూడు_TPREL_HI12:
        స్థితి R_AARCH64_TLSLE_కూడు_TPREL_LO12: {
#ఒకవేళ TCC_లక్ష్యం_PE
            int64_t tp_స్థానభ్రంశం = val - s1->tls_ప్రారంభం;
#లేకపోతే
            /* glibc arm64: tp points to tcbhead_t (DTV), TLS data starts after it */
            int64_t tp_స్థానభ్రంశం = val - s1->tls_ప్రారంభం + 16;
#అయితే_ముగింపు
            int64_t imm;
            ఒకవేళ (type == R_AARCH64_TLSLE_కూడు_TPREL_HI12)
                imm = (tp_స్థానభ్రంశం >> 12) & 0xfff;
            లేకపోతే
                imm = tp_స్థానభ్రంశం & 0xfff;
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) | (imm << 10)));
            తిరిగి;
        }
        స్థితి R_AARCH64_RELATIVE:
#నిర్వచితమైతే TCC_లక్ష్యం_PE
            add32le(ptr, val - s1->pe_imagebase);
#అయితే_ముగింపు
            /* do nothing */
            తిరిగి;
        అప్రమేయ:
            fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (గుర్తులేని)addr, ptr, (గుర్తులేని)val);
            తిరిగి;
    }
}

#అయితే_ముగింపు /* !TARGET_DEFS_ONLY */
