#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ಗುರಿ_DEFS_ONLY

#ವ್ಯಾಖ್ಯಾನಿಸು EM_TCC_ಗುರಿ EM_AARCH64

#ವ್ಯಾಖ್ಯಾನಿಸು R_ದತ್ತಾಂಶ_32  R_AARCH64_ABS32
#ವ್ಯಾಖ್ಯಾನಿಸು R_ದತ್ತಾಂಶ_PTR R_AARCH64_ABS64
#ವ್ಯಾಖ್ಯಾನಿಸು R_JMP_ಸ್ಥಾನ R_AARCH64_JUMP_ಸ್ಥಾನ
#ವ್ಯಾಖ್ಯಾನಿಸು R_GLOB_DAT R_AARCH64_GLOB_DAT
#ವ್ಯಾಖ್ಯಾನಿಸು R_COPY     R_AARCH64_COPY
#ವ್ಯಾಖ್ಯಾನಿಸು R_RELATIVE R_AARCH64_RELATIVE

#ವ್ಯಾಖ್ಯಾನಿಸು R_ಅಂಕೆ      R_AARCH64_ಅಂಕೆ

#ವ್ಯಾಖ್ಯಾನಿಸು ELF_ಆರಂಭ_ADDR 0x00400000
#ವ್ಯಾಖ್ಯಾನಿಸು ELF_ಪುಟ_ಗಾತ್ರ 0x10000

#ವ್ಯಾಖ್ಯಾನಿಸು PCRELATIVE_DLLPLT 1
#ವ್ಯಾಖ್ಯಾನಿಸು RELOCATE_DLLPLT 1

#ಇಲ್ಲದಿದ್ದರೆ /* !TARGET_DEFS_ONLY */

#ಅನ್ತರ್ಭಾವ "tcc.h"

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_reloc (ಪೂರ್ಣಾಂಕ reloc_type)
{
    ಆಯ್ಕೆ (reloc_type) {
        ಸ್ಥಿತಿ R_AARCH64_ABS32:
        ಸ್ಥಿತಿ R_AARCH64_ABS64:
	ಸ್ಥಿತಿ R_AARCH64_PREL32:
        ಸ್ಥಿತಿ R_AARCH64_MOVW_UABS_G0_NC:
        ಸ್ಥಿತಿ R_AARCH64_MOVW_UABS_G1_NC:
        ಸ್ಥಿತಿ R_AARCH64_MOVW_UABS_G2_NC:
        ಸ್ಥಿತಿ R_AARCH64_MOVW_UABS_G3:
        ಸ್ಥಿತಿ R_AARCH64_ADR_PREL_PG_HI21:
        ಸ್ಥಿತಿ R_AARCH64_ಕೂಡಿಸು_ABS_LO12_NC:
        ಸ್ಥಿತಿ R_AARCH64_ADR_GOT_ಪುಟ:
        ಸ್ಥಿತಿ R_AARCH64_LD64_GOT_LO12_NC:
        ಸ್ಥಿತಿ R_AARCH64_LDST128_ABS_LO12_NC:
        ಸ್ಥಿತಿ R_AARCH64_LDST64_ABS_LO12_NC:
        ಸ್ಥಿತಿ R_AARCH64_LDST32_ABS_LO12_NC:
        ಸ್ಥಿತಿ R_AARCH64_LDST16_ABS_LO12_NC:
        ಸ್ಥಿತಿ R_AARCH64_LDST8_ABS_LO12_NC:
        ಸ್ಥಿತಿ R_AARCH64_TLSLE_ಕೂಡಿಸು_TPREL_HI12:
        ಸ್ಥಿತಿ R_AARCH64_TLSLE_ಕೂಡಿಸು_TPREL_LO12:
        ಸ್ಥಿತಿ R_AARCH64_GLOB_DAT:
        ಸ್ಥಿತಿ R_AARCH64_COPY:
            ಹಿಂತಿರುಗಿ 0;

        ಸ್ಥಿತಿ R_AARCH64_JUMP26:
        ಸ್ಥಿತಿ R_AARCH64_CALL26:
        ಸ್ಥಿತಿ R_AARCH64_JUMP_ಸ್ಥಾನ:
        ಸ್ಥಿತಿ R_AARCH64_CONDBR19:
        ಸ್ಥಿತಿ R_AARCH64_TSTBR14:
            ಹಿಂತಿರುಗಿ 1;
    }
    ಹಿಂತಿರುಗಿ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC ಪೂರ್ಣಾಂಕ gotplt_ನಮೂದು_type (ಪೂರ್ಣಾಂಕ reloc_type)
{
    ಆಯ್ಕೆ (reloc_type) {
	ಸ್ಥಿತಿ R_AARCH64_PREL32:
        ಸ್ಥಿತಿ R_AARCH64_MOVW_UABS_G0_NC:
        ಸ್ಥಿತಿ R_AARCH64_MOVW_UABS_G1_NC:
        ಸ್ಥಿತಿ R_AARCH64_MOVW_UABS_G2_NC:
        ಸ್ಥಿತಿ R_AARCH64_MOVW_UABS_G3:
        ಸ್ಥಿತಿ R_AARCH64_ADR_PREL_PG_HI21:
        ಸ್ಥಿತಿ R_AARCH64_ಕೂಡಿಸು_ABS_LO12_NC:
        ಸ್ಥಿತಿ R_AARCH64_LDST128_ABS_LO12_NC:
        ಸ್ಥಿತಿ R_AARCH64_LDST64_ABS_LO12_NC:
        ಸ್ಥಿತಿ R_AARCH64_LDST32_ABS_LO12_NC:
        ಸ್ಥಿತಿ R_AARCH64_LDST16_ABS_LO12_NC:
        ಸ್ಥಿತಿ R_AARCH64_LDST8_ABS_LO12_NC:
        ಸ್ಥಿತಿ R_AARCH64_GLOB_DAT:
        ಸ್ಥಿತಿ R_AARCH64_JUMP_ಸ್ಥಾನ:
        ಸ್ಥಿತಿ R_AARCH64_COPY:
        ಸ್ಥಿತಿ R_AARCH64_CONDBR19:
        ಸ್ಥಿತಿ R_AARCH64_TSTBR14:
        ಸ್ಥಿತಿ R_AARCH64_TLSLE_ಕೂಡಿಸು_TPREL_HI12:
        ಸ್ಥಿತಿ R_AARCH64_TLSLE_ಕೂಡಿಸು_TPREL_LO12:
            ಹಿಂತಿರುಗಿ NO_GOTPLT_ನಮೂದು;

        ಸ್ಥಿತಿ R_AARCH64_ABS32:
        ಸ್ಥಿತಿ R_AARCH64_ABS64:
        ಸ್ಥಿತಿ R_AARCH64_JUMP26:
        ಸ್ಥಿತಿ R_AARCH64_CALL26:
            ಹಿಂತಿರುಗಿ AUTO_GOTPLT_ನಮೂದು;

        ಸ್ಥಿತಿ R_AARCH64_ADR_GOT_ಪುಟ:
        ಸ್ಥಿತಿ R_AARCH64_LD64_GOT_LO12_NC:
            ಹಿಂತಿರುಗಿ ALWAYS_GOTPLT_ನಮೂದು;
    }
    ಹಿಂತಿರುಗಿ -1;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ NEED_BUILD_GOT
ST_FUNC ಚಿಹ್ನೆರಹಿತ create_plt_ನಮೂದು(TCCState *s1, ಚಿಹ್ನೆರಹಿತ got_ಸ್ಥಾನಾಂತರ, ರಚನೆ sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    ಚಿಹ್ನೆರಹಿತ plt_ಸ್ಥಾನಾಂತರ;

    ಆದರೆ (plt->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ == 0) {
        section_ptr_ಕೂಡಿಸು(plt, 32);
    }
    plt_ಸ್ಥಾನಾಂತರ = plt->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

    p = section_ptr_ಕೂಡಿಸು(plt, 16);
    write32le(p, got_ಸ್ಥಾನಾಂತರ);
    write32le(p + 4, (uint64_t) got_ಸ್ಥಾನಾಂತರ >> 32);
    ಹಿಂತಿರುಗಿ plt_ಸ್ಥಾನಾಂತರ;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC ಶೂನ್ಯ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_ಕೊನೆ;

    ಆದರೆ (!s1->plt)
      ಹಿಂತಿರುಗಿ;

    p = s1->plt->ದತ್ತಾಂಶ;
    p_ಕೊನೆ = p + s1->plt->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

    ಆದರೆ (p < p_ಕೊನೆ) {
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr + 16;
        uint64_t off = (got >> 12) - (plt >> 12);
        ಆದರೆ ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (ದೀರ್ಘ)off, (ದೀರ್ಘ)got, (ದೀರ್ಘ)plt);
        write32le(p, ARM64_STP_X_PRE | ARM64_RT(16) | ARM64_RT2(30) |
                      ARM64_RN(31) | ARM64_IMM7(-2)); // stp x16,x30,[sp,#-16]!
        write32le(p + 4, (ARM64_ADRP | ARM64_RD(16) | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
        write32le(p + 8, (ARM64_LDR_X | ARM64_RT(17) | ARM64_RN(16) | // ldr x17,[x16,#...]
			  (got & 0xff8) << 7));
        write32le(p + 12, (ARM64_ಕೂಡಿಸು_IMM | ARM64_SF(1) | ARM64_RD(16) | ARM64_RN(16) | // add x16,x16,#...
			   (got & 0xfff) << 10));
        write32le(p + 16, ARM64_BR | ARM64_RN(17)); // br x17
        write32le(p + 20, ARM64_NOP); // nop
        write32le(p + 24, ARM64_NOP); // nop
        write32le(p + 28, ARM64_NOP); // nop
        p += 32;
	got = s1->got->sh_addr;
        ಆಗ (p < p_ಕೊನೆ) {
            uint64_t pc = plt + (p - s1->plt->ದತ್ತಾಂಶ);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr >> 12) - (pc >> 12);
            ಆದರೆ ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (ದೀರ್ಘ)off, (ದೀರ್ಘ)addr, (ದೀರ್ಘ)pc);
            write32le(p, (ARM64_ADRP | ARM64_RD(16) | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
            write32le(p + 4, (ARM64_LDR_X | ARM64_RT(17) | ARM64_RN(16) | // ldr x17,[x16,#...]
			      (addr & 0xff8) << 7));
            write32le(p + 8, (ARM64_ಕೂಡಿಸು_IMM | ARM64_SF(1) | ARM64_RD(16) | ARM64_RN(16) | // add x16,x16,#...
			      (addr & 0xfff) << 10));
            write32le(p + 12, ARM64_BR | ARM64_RN(17)); // br x17
            p += 16;
        }
    }

    ಆದರೆ (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->ದತ್ತಾಂಶ;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_ಸ್ಥಾನಾಂತರ, s1->plt->sh_addr);
	}
    }
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

ST_FUNC ಶೂನ್ಯ relocate(TCCState *s1, ElfW_Rel *rel, ಪೂರ್ಣಾಂಕ type, ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr, addr_t addr, addr_t val)
{
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(rel->r_info), esym_ಸೂಚ್ಯಂಕ;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ DEBUG_RELOC
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
#ಆದರೆ_ಅಂತ್ಯ

    ಆಯ್ಕೆ(type) {
        ಸ್ಥಿತಿ R_AARCH64_ABS64:
            ಆದರೆ ((s1->output_type & TCC_OUTPUT_DYN)) {
                esym_ಸೂಚ್ಯಂಕ = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->dyn_ಸೂಚ್ಯಂಕ;
                qrel->r_ಸ್ಥಾನಾಂತರ = rel->r_ಸ್ಥಾನಾಂತರ;
                ಆದರೆ (esym_ಸೂಚ್ಯಂಕ) {
                    qrel->r_info = ELFW(R_INFO)(esym_ಸೂಚ್ಯಂಕ, R_AARCH64_ABS64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    ನಿಲ್ಲಿಸು;
                } ಇಲ್ಲದಿದ್ದರೆ {
                    qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_ABS32:
            ಆದರೆ (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_AARCH64_RELATIVE even for a 64bit pointer */
                qrel->r_ಸ್ಥಾನಾಂತರ = rel->r_ಸ್ಥಾನಾಂತರ;
                qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (ಪೂರ್ಣಾಂಕ)read32le(ptr) + val;
                qrel++;
            }
            add32le(ptr, val);
            ಹಿಂತಿರುಗಿ;
	ಸ್ಥಿತಿ R_AARCH64_PREL32:
            ಆದರೆ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_ಸೂಚ್ಯಂಕ = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->dyn_ಸೂಚ್ಯಂಕ;
                ಆದರೆ (esym_ಸೂಚ್ಯಂಕ) {
                    qrel->r_ಸ್ಥಾನಾಂತರ = rel->r_ಸ್ಥಾನಾಂತರ;
                    qrel->r_info = ELFW(R_INFO)(esym_ಸೂಚ್ಯಂಕ, R_AARCH64_PREL32);
                    /* Use sign extension! */
                    qrel->r_addend = (ಪೂರ್ಣಾಂಕ)read32le(ptr) + rel->r_addend;
                    qrel++;
                    ನಿಲ್ಲಿಸು;
                }
            }
	    add32le(ptr, val - addr);
	    ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_MOVW_UABS_G0_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val & 0xffff) << 5));
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_MOVW_UABS_G1_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 16 & 0xffff) << 5));
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_MOVW_UABS_G2_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 32 & 0xffff) << 5));
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_MOVW_UABS_G3:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 48 & 0xffff) << 5));
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_ADR_PREL_PG_HI21: {
            uint64_t off = (val >> 12) - (addr >> 12);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
            /* Weak undefined symbols resolve to address 0 on PE. ADRP cannot
               encode that from the default 64-bit image base, so materialize
               zero directly and let the paired ADD handle any low addend. */
            ಆದರೆ ((off + ((uint64_t)1 << 20)) >> 21) {
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
                ಆದರೆ (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, 0xd2800000 | (read32le(ptr) & 0x1f));
                    ಹಿಂತಿರುಗಿ;
                }
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
            }
#ಇಲ್ಲದಿದ್ದರೆ
            ಆದರೆ ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
#ಆದರೆ_ಅಂತ್ಯ
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            ಹಿಂತಿರುಗಿ;
        }
        ಸ್ಥಿತಿ R_AARCH64_ಕೂಡಿಸು_ABS_LO12_NC:
        ಸ್ಥಿತಿ R_AARCH64_LDST8_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xfff) << 10));
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_LDST16_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffe) << 9));
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_LDST32_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffc) << 8));
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_LDST64_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff8) << 7));
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_LDST128_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff0) << 6));
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_CONDBR19:
            /* Conditional branch: 19-bit signed offset, bits 23:5 */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ DEBUG_RELOC
     ಬರೆ ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name);
#ಆದರೆ_ಅಂತ್ಯ
            ಆದರೆ (((val - addr) + ((uint64_t)1 << 20)) & ~(uint64_t)0x1ffffc)
                tcc_error_noabort("R_AARCH64_CONDBR19 relocation failed"
                          " (val=%lx, addr=%lx)", (ದೀರ್ಘ)val, (ದೀರ್ಘ)addr);
            write32le(ptr, ((read32le(ptr) & 0xff00001f) |
                            (((val - addr) >> 2 & 0x7ffff) << 5)));
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_TSTBR14:
            /* Test and branch: 14-bit signed offset, bits 20:5 */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ DEBUG_RELOC
     ಬರೆ ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name);
#ಆದರೆ_ಅಂತ್ಯ
            ಆದರೆ (((val - addr) + ((uint64_t)1 << 15)) & ~(uint64_t)0xfffc)
                tcc_error_noabort("R_AARCH64_TSTBR14 relocation failed"
                          " (val=%lx, addr=%lx)", (ದೀರ್ಘ)val, (ದೀರ್ಘ)addr);
            write32le(ptr, ((read32le(ptr) & 0xfff8001f) |
                            (((val - addr) >> 2 & 0x3fff) << 5)));
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_JUMP26:
        ಸ್ಥಿತಿ R_AARCH64_CALL26:
        {
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ DEBUG_RELOC
	    ಬರೆ ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
		    (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name);
#ಆದರೆ_ಅಂತ್ಯ
            ಆದರೆ (((val - addr) + ((uint64_t)1 << 27)) & ~(uint64_t)0xffffffc) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
                ಆದರೆ (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, ARM64_NOP); /* nop */
                    ಹಿಂತಿರುಗಿ;
                }
#ಆದರೆ_ಅಂತ್ಯ
                name = (ಅಕ್ಷರ *)symtab_section->link->ದತ್ತಾಂಶ +
                    ((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ].st_name;
                tcc_error_noabort("R_AARCH64_(JUMP|CALL)26 relocation failed"
                          " for '%s' (val=%lx, addr=%lx)",
                          name, (ದೀರ್ಘ)val, (ದೀರ್ಘ)addr);
            }
            write32le(ptr, (0x14000000 |
                            (uint32_t)(type == R_AARCH64_CALL26) << 31 |
                            ((val - addr) >> 2 & 0x3ffffff)));
            ಹಿಂತಿರುಗಿ;
        }
        ಸ್ಥಿತಿ R_AARCH64_ADR_GOT_ಪುಟ: {
            uint64_t off =
                (((s1->got->sh_addr +
                   get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->got_ಸ್ಥಾನಾಂತರ) >> 12) - (addr >> 12));
            ಆದರೆ ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_GOT_PAGE relocation failed");
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            ಹಿಂತಿರುಗಿ;
        }
        ಸ್ಥಿತಿ R_AARCH64_LD64_GOT_LO12_NC:
            write32le(ptr,
                      ((read32le(ptr) & 0xfff803ff) |
                       ((s1->got->sh_addr +
                         get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->got_ಸ್ಥಾನಾಂತರ) & 0xff8) << 7));
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_COPY:
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_GLOB_DAT:
        ಸ್ಥಿತಿ R_AARCH64_JUMP_ಸ್ಥಾನ:
            /* They don't need addend */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ DEBUG_RELOC
	    ಬರೆ ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr,
		    val - rel->r_addend,
		    (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name);
#ಆದರೆ_ಅಂತ್ಯ
            write64le(ptr, val - rel->r_addend);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_AARCH64_TLSLE_ಕೂಡಿಸು_TPREL_HI12:
        ಸ್ಥಿತಿ R_AARCH64_TLSLE_ಕೂಡಿಸು_TPREL_LO12: {
#ಆದರೆ TCC_ಗುರಿ_PE
            int64_t tp_ಸ್ಥಾನಾಂತರ = val - s1->tls_ಆರಂಭ;
#ಇಲ್ಲದಿದ್ದರೆ
            /* glibc arm64: tp points to tcbhead_t (DTV), TLS data starts after it */
            int64_t tp_ಸ್ಥಾನಾಂತರ = val - s1->tls_ಆರಂಭ + 16;
#ಆದರೆ_ಅಂತ್ಯ
            int64_t imm;
            ಆದರೆ (type == R_AARCH64_TLSLE_ಕೂಡಿಸು_TPREL_HI12)
                imm = (tp_ಸ್ಥಾನಾಂತರ >> 12) & 0xfff;
            ಇಲ್ಲದಿದ್ದರೆ
                imm = tp_ಸ್ಥಾನಾಂತರ & 0xfff;
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) | (imm << 10)));
            ಹಿಂತಿರುಗಿ;
        }
        ಸ್ಥಿತಿ R_AARCH64_RELATIVE:
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
            add32le(ptr, val - s1->pe_imagebase);
#ಆದರೆ_ಅಂತ್ಯ
            /* do nothing */
            ಹಿಂತಿರುಗಿ;
        ಪೂರ್ವನಿಯೋಜಿತ:
            fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (ಚಿಹ್ನೆರಹಿತ)addr, ptr, (ಚಿಹ್ನೆರಹಿತ)val);
            ಹಿಂತಿರುಗಿ;
    }
}

#ಆದರೆ_ಅಂತ್ಯ /* !TARGET_DEFS_ONLY */
