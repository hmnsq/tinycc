#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ਨਿਸ਼ਾਨਾ_DEFS_ONLY

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_TCC_ਨਿਸ਼ਾਨਾ EM_AARCH64

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕੜੇ_32  R_AARCH64_ABS32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕੜੇ_PTR R_AARCH64_ABS64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_JMP_ਥਾਂ R_AARCH64_JUMP_ਥਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_GLOB_DAT R_AARCH64_GLOB_DAT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_COPY     R_AARCH64_COPY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_RELATIVE R_AARCH64_RELATIVE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕ      R_AARCH64_ਅੰਕ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_ਸ਼ੁਰੂ_ADDR 0x00400000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_ਪੰਨਾ_ਮਾਪ 0x10000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCRELATIVE_DLLPLT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RELOCATE_DLLPLT 1

#ਨਹੀਂਤਾਂ /* !TARGET_DEFS_ONLY */

#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ਪੂਰਨ ਕੋਡ_reloc (ਪੂਰਨ reloc_type)
{
    ਚੋਣ (reloc_type) {
        ਹਾਲਤ R_AARCH64_ABS32:
        ਹਾਲਤ R_AARCH64_ABS64:
	ਹਾਲਤ R_AARCH64_PREL32:
        ਹਾਲਤ R_AARCH64_MOVW_UABS_G0_NC:
        ਹਾਲਤ R_AARCH64_MOVW_UABS_G1_NC:
        ਹਾਲਤ R_AARCH64_MOVW_UABS_G2_NC:
        ਹਾਲਤ R_AARCH64_MOVW_UABS_G3:
        ਹਾਲਤ R_AARCH64_ADR_PREL_PG_HI21:
        ਹਾਲਤ R_AARCH64_ਜੋੜੋ_ABS_LO12_NC:
        ਹਾਲਤ R_AARCH64_ADR_GOT_ਪੰਨਾ:
        ਹਾਲਤ R_AARCH64_LD64_GOT_LO12_NC:
        ਹਾਲਤ R_AARCH64_LDST128_ABS_LO12_NC:
        ਹਾਲਤ R_AARCH64_LDST64_ABS_LO12_NC:
        ਹਾਲਤ R_AARCH64_LDST32_ABS_LO12_NC:
        ਹਾਲਤ R_AARCH64_LDST16_ABS_LO12_NC:
        ਹਾਲਤ R_AARCH64_LDST8_ABS_LO12_NC:
        ਹਾਲਤ R_AARCH64_TLSLE_ਜੋੜੋ_TPREL_HI12:
        ਹਾਲਤ R_AARCH64_TLSLE_ਜੋੜੋ_TPREL_LO12:
        ਹਾਲਤ R_AARCH64_GLOB_DAT:
        ਹਾਲਤ R_AARCH64_COPY:
            ਵਾਪਸ 0;

        ਹਾਲਤ R_AARCH64_JUMP26:
        ਹਾਲਤ R_AARCH64_CALL26:
        ਹਾਲਤ R_AARCH64_JUMP_ਥਾਂ:
        ਹਾਲਤ R_AARCH64_CONDBR19:
        ਹਾਲਤ R_AARCH64_TSTBR14:
            ਵਾਪਸ 1;
    }
    ਵਾਪਸ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC ਪੂਰਨ gotplt_ਇੰਦਰਾਜ_type (ਪੂਰਨ reloc_type)
{
    ਚੋਣ (reloc_type) {
	ਹਾਲਤ R_AARCH64_PREL32:
        ਹਾਲਤ R_AARCH64_MOVW_UABS_G0_NC:
        ਹਾਲਤ R_AARCH64_MOVW_UABS_G1_NC:
        ਹਾਲਤ R_AARCH64_MOVW_UABS_G2_NC:
        ਹਾਲਤ R_AARCH64_MOVW_UABS_G3:
        ਹਾਲਤ R_AARCH64_ADR_PREL_PG_HI21:
        ਹਾਲਤ R_AARCH64_ਜੋੜੋ_ABS_LO12_NC:
        ਹਾਲਤ R_AARCH64_LDST128_ABS_LO12_NC:
        ਹਾਲਤ R_AARCH64_LDST64_ABS_LO12_NC:
        ਹਾਲਤ R_AARCH64_LDST32_ABS_LO12_NC:
        ਹਾਲਤ R_AARCH64_LDST16_ABS_LO12_NC:
        ਹਾਲਤ R_AARCH64_LDST8_ABS_LO12_NC:
        ਹਾਲਤ R_AARCH64_GLOB_DAT:
        ਹਾਲਤ R_AARCH64_JUMP_ਥਾਂ:
        ਹਾਲਤ R_AARCH64_COPY:
        ਹਾਲਤ R_AARCH64_CONDBR19:
        ਹਾਲਤ R_AARCH64_TSTBR14:
        ਹਾਲਤ R_AARCH64_TLSLE_ਜੋੜੋ_TPREL_HI12:
        ਹਾਲਤ R_AARCH64_TLSLE_ਜੋੜੋ_TPREL_LO12:
            ਵਾਪਸ NO_GOTPLT_ਇੰਦਰਾਜ;

        ਹਾਲਤ R_AARCH64_ABS32:
        ਹਾਲਤ R_AARCH64_ABS64:
        ਹਾਲਤ R_AARCH64_JUMP26:
        ਹਾਲਤ R_AARCH64_CALL26:
            ਵਾਪਸ AUTO_GOTPLT_ਇੰਦਰਾਜ;

        ਹਾਲਤ R_AARCH64_ADR_GOT_ਪੰਨਾ:
        ਹਾਲਤ R_AARCH64_LD64_GOT_LO12_NC:
            ਵਾਪਸ ALWAYS_GOTPLT_ਇੰਦਰਾਜ;
    }
    ਵਾਪਸ -1;
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ NEED_BUILD_GOT
ST_FUNC ਬਿਨਾਨਿਸ਼ਾਨੀ create_plt_ਇੰਦਰਾਜ(TCCState *s1, ਬਿਨਾਨਿਸ਼ਾਨੀ got_ਵਿੱਥ, ਬਣਤਰ sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    ਬਿਨਾਨਿਸ਼ਾਨੀ plt_ਵਿੱਥ;

    ਜੇ (plt->ਅੰਕੜੇ_ਵਿੱਥ == 0) {
        section_ptr_ਜੋੜੋ(plt, 32);
    }
    plt_ਵਿੱਥ = plt->ਅੰਕੜੇ_ਵਿੱਥ;

    p = section_ptr_ਜੋੜੋ(plt, 16);
    write32le(p, got_ਵਿੱਥ);
    write32le(p + 4, (uint64_t) got_ਵਿੱਥ >> 32);
    ਵਾਪਸ plt_ਵਿੱਥ;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC ਖਾਲੀ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_ਸਿਰਾ;

    ਜੇ (!s1->plt)
      ਵਾਪਸ;

    p = s1->plt->ਅੰਕੜੇ;
    p_ਸਿਰਾ = p + s1->plt->ਅੰਕੜੇ_ਵਿੱਥ;

    ਜੇ (p < p_ਸਿਰਾ) {
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr + 16;
        uint64_t off = (got >> 12) - (plt >> 12);
        ਜੇ ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (ਲੰਮਾ)off, (ਲੰਮਾ)got, (ਲੰਮਾ)plt);
        write32le(p, ARM64_STP_X_PRE | ARM64_RT(16) | ARM64_RT2(30) |
                      ARM64_RN(31) | ARM64_IMM7(-2)); // stp x16,x30,[sp,#-16]!
        write32le(p + 4, (ARM64_ADRP | ARM64_RD(16) | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
        write32le(p + 8, (ARM64_LDR_X | ARM64_RT(17) | ARM64_RN(16) | // ldr x17,[x16,#...]
			  (got & 0xff8) << 7));
        write32le(p + 12, (ARM64_ਜੋੜੋ_IMM | ARM64_SF(1) | ARM64_RD(16) | ARM64_RN(16) | // add x16,x16,#...
			   (got & 0xfff) << 10));
        write32le(p + 16, ARM64_BR | ARM64_RN(17)); // br x17
        write32le(p + 20, ARM64_NOP); // nop
        write32le(p + 24, ARM64_NOP); // nop
        write32le(p + 28, ARM64_NOP); // nop
        p += 32;
	got = s1->got->sh_addr;
        ਜਦੋਂ (p < p_ਸਿਰਾ) {
            uint64_t pc = plt + (p - s1->plt->ਅੰਕੜੇ);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr >> 12) - (pc >> 12);
            ਜੇ ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (ਲੰਮਾ)off, (ਲੰਮਾ)addr, (ਲੰਮਾ)pc);
            write32le(p, (ARM64_ADRP | ARM64_RD(16) | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
            write32le(p + 4, (ARM64_LDR_X | ARM64_RT(17) | ARM64_RN(16) | // ldr x17,[x16,#...]
			      (addr & 0xff8) << 7));
            write32le(p + 8, (ARM64_ਜੋੜੋ_IMM | ARM64_SF(1) | ARM64_RD(16) | ARM64_RN(16) | // add x16,x16,#...
			      (addr & 0xfff) << 10));
            write32le(p + 12, ARM64_BR | ARM64_RN(17)); // br x17
            p += 16;
        }
    }

    ਜੇ (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->ਅੰਕੜੇ;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_ਵਿੱਥ, s1->plt->sh_addr);
	}
    }
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

ST_FUNC ਖਾਲੀ relocate(TCCState *s1, ElfW_Rel *rel, ਪੂਰਨ type, ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr, addr_t addr, addr_t val)
{
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(rel->r_info), esym_ਸੂਚਕਾਂਕ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ DEBUG_RELOC
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
#ਜੇ_ਅੰਤ

    ਚੋਣ(type) {
        ਹਾਲਤ R_AARCH64_ABS64:
            ਜੇ ((s1->output_type & TCC_OUTPUT_DYN)) {
                esym_ਸੂਚਕਾਂਕ = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->dyn_ਸੂਚਕਾਂਕ;
                qrel->r_ਵਿੱਥ = rel->r_ਵਿੱਥ;
                ਜੇ (esym_ਸੂਚਕਾਂਕ) {
                    qrel->r_info = ELFW(R_INFO)(esym_ਸੂਚਕਾਂਕ, R_AARCH64_ABS64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    ਰੋਕੋ;
                } ਨਹੀਂਤਾਂ {
                    qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_ABS32:
            ਜੇ (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_AARCH64_RELATIVE even for a 64bit pointer */
                qrel->r_ਵਿੱਥ = rel->r_ਵਿੱਥ;
                qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (ਪੂਰਨ)read32le(ptr) + val;
                qrel++;
            }
            add32le(ptr, val);
            ਵਾਪਸ;
	ਹਾਲਤ R_AARCH64_PREL32:
            ਜੇ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_ਸੂਚਕਾਂਕ = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->dyn_ਸੂਚਕਾਂਕ;
                ਜੇ (esym_ਸੂਚਕਾਂਕ) {
                    qrel->r_ਵਿੱਥ = rel->r_ਵਿੱਥ;
                    qrel->r_info = ELFW(R_INFO)(esym_ਸੂਚਕਾਂਕ, R_AARCH64_PREL32);
                    /* Use sign extension! */
                    qrel->r_addend = (ਪੂਰਨ)read32le(ptr) + rel->r_addend;
                    qrel++;
                    ਰੋਕੋ;
                }
            }
	    add32le(ptr, val - addr);
	    ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_MOVW_UABS_G0_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val & 0xffff) << 5));
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_MOVW_UABS_G1_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 16 & 0xffff) << 5));
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_MOVW_UABS_G2_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 32 & 0xffff) << 5));
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_MOVW_UABS_G3:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 48 & 0xffff) << 5));
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_ADR_PREL_PG_HI21: {
            uint64_t off = (val >> 12) - (addr >> 12);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
            /* Weak undefined symbols resolve to address 0 on PE. ADRP cannot
               encode that from the default 64-bit image base, so materialize
               zero directly and let the paired ADD handle any low addend. */
            ਜੇ ((off + ((uint64_t)1 << 20)) >> 21) {
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
                ਜੇ (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, 0xd2800000 | (read32le(ptr) & 0x1f));
                    ਵਾਪਸ;
                }
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
            }
#ਨਹੀਂਤਾਂ
            ਜੇ ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
#ਜੇ_ਅੰਤ
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            ਵਾਪਸ;
        }
        ਹਾਲਤ R_AARCH64_ਜੋੜੋ_ABS_LO12_NC:
        ਹਾਲਤ R_AARCH64_LDST8_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xfff) << 10));
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_LDST16_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffe) << 9));
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_LDST32_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffc) << 8));
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_LDST64_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff8) << 7));
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_LDST128_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff0) << 6));
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_CONDBR19:
            /* Conditional branch: 19-bit signed offset, bits 23:5 */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ DEBUG_RELOC
     ਲਿਖੋ ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name);
#ਜੇ_ਅੰਤ
            ਜੇ (((val - addr) + ((uint64_t)1 << 20)) & ~(uint64_t)0x1ffffc)
                tcc_error_noabort("R_AARCH64_CONDBR19 relocation failed"
                          " (val=%lx, addr=%lx)", (ਲੰਮਾ)val, (ਲੰਮਾ)addr);
            write32le(ptr, ((read32le(ptr) & 0xff00001f) |
                            (((val - addr) >> 2 & 0x7ffff) << 5)));
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_TSTBR14:
            /* Test and branch: 14-bit signed offset, bits 20:5 */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ DEBUG_RELOC
     ਲਿਖੋ ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name);
#ਜੇ_ਅੰਤ
            ਜੇ (((val - addr) + ((uint64_t)1 << 15)) & ~(uint64_t)0xfffc)
                tcc_error_noabort("R_AARCH64_TSTBR14 relocation failed"
                          " (val=%lx, addr=%lx)", (ਲੰਮਾ)val, (ਲੰਮਾ)addr);
            write32le(ptr, ((read32le(ptr) & 0xfff8001f) |
                            (((val - addr) >> 2 & 0x3fff) << 5)));
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_JUMP26:
        ਹਾਲਤ R_AARCH64_CALL26:
        {
            ਅਚਲ ਅੱਖਰ *name;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ DEBUG_RELOC
	    ਲਿਖੋ ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
		    (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name);
#ਜੇ_ਅੰਤ
            ਜੇ (((val - addr) + ((uint64_t)1 << 27)) & ~(uint64_t)0xffffffc) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
                ਜੇ (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, ARM64_NOP); /* nop */
                    ਵਾਪਸ;
                }
#ਜੇ_ਅੰਤ
                name = (ਅੱਖਰ *)symtab_section->link->ਅੰਕੜੇ +
                    ((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ].st_name;
                tcc_error_noabort("R_AARCH64_(JUMP|CALL)26 relocation failed"
                          " for '%s' (val=%lx, addr=%lx)",
                          name, (ਲੰਮਾ)val, (ਲੰਮਾ)addr);
            }
            write32le(ptr, (0x14000000 |
                            (uint32_t)(type == R_AARCH64_CALL26) << 31 |
                            ((val - addr) >> 2 & 0x3ffffff)));
            ਵਾਪਸ;
        }
        ਹਾਲਤ R_AARCH64_ADR_GOT_ਪੰਨਾ: {
            uint64_t off =
                (((s1->got->sh_addr +
                   get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->got_ਵਿੱਥ) >> 12) - (addr >> 12));
            ਜੇ ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_GOT_PAGE relocation failed");
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            ਵਾਪਸ;
        }
        ਹਾਲਤ R_AARCH64_LD64_GOT_LO12_NC:
            write32le(ptr,
                      ((read32le(ptr) & 0xfff803ff) |
                       ((s1->got->sh_addr +
                         get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->got_ਵਿੱਥ) & 0xff8) << 7));
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_COPY:
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_GLOB_DAT:
        ਹਾਲਤ R_AARCH64_JUMP_ਥਾਂ:
            /* They don't need addend */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ DEBUG_RELOC
	    ਲਿਖੋ ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr,
		    val - rel->r_addend,
		    (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name);
#ਜੇ_ਅੰਤ
            write64le(ptr, val - rel->r_addend);
            ਵਾਪਸ;
        ਹਾਲਤ R_AARCH64_TLSLE_ਜੋੜੋ_TPREL_HI12:
        ਹਾਲਤ R_AARCH64_TLSLE_ਜੋੜੋ_TPREL_LO12: {
#ਜੇ TCC_ਨਿਸ਼ਾਨਾ_PE
            int64_t tp_ਵਿੱਥ = val - s1->tls_ਸ਼ੁਰੂ;
#ਨਹੀਂਤਾਂ
            /* glibc arm64: tp points to tcbhead_t (DTV), TLS data starts after it */
            int64_t tp_ਵਿੱਥ = val - s1->tls_ਸ਼ੁਰੂ + 16;
#ਜੇ_ਅੰਤ
            int64_t imm;
            ਜੇ (type == R_AARCH64_TLSLE_ਜੋੜੋ_TPREL_HI12)
                imm = (tp_ਵਿੱਥ >> 12) & 0xfff;
            ਨਹੀਂਤਾਂ
                imm = tp_ਵਿੱਥ & 0xfff;
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) | (imm << 10)));
            ਵਾਪਸ;
        }
        ਹਾਲਤ R_AARCH64_RELATIVE:
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
            add32le(ptr, val - s1->pe_imagebase);
#ਜੇ_ਅੰਤ
            /* do nothing */
            ਵਾਪਸ;
        ਮੂਲ:
            fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (ਬਿਨਾਨਿਸ਼ਾਨੀ)addr, ptr, (ਬਿਨਾਨਿਸ਼ਾਨੀ)val);
            ਵਾਪਸ;
    }
}

#ਜੇ_ਅੰਤ /* !TARGET_DEFS_ONLY */
