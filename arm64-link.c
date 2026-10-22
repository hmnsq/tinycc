#که_تعریف_شوی موخه_DEFS_ONLY

#تعریف_کړه EM_TCC_موخه EM_AARCH64

#تعریف_کړه R_معلومات_32  R_AARCH64_ABS32
#تعریف_کړه R_معلومات_PTR R_AARCH64_ABS64
#تعریف_کړه R_JMP_خونه R_AARCH64_JUMP_خونه
#تعریف_کړه R_GLOB_DAT R_AARCH64_GLOB_DAT
#تعریف_کړه R_COPY     R_AARCH64_COPY
#تعریف_کړه R_RELATIVE R_AARCH64_RELATIVE

#تعریف_کړه R_عدد      R_AARCH64_عدد

#تعریف_کړه ELF_پیل_ADDR 0x00400000
#تعریف_کړه ELF_پاڼه_اندازه 0x10000

#تعریف_کړه PCRELATIVE_DLLPLT 1
#تعریف_کړه RELOCATE_DLLPLT 1

#وإلا /* !TARGET_DEFS_ONLY */

#ضمن "tcc.h"

#که_تعریف_شوی NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحيح کوډ_reloc (صحيح reloc_type)
{
    بدل (reloc_type) {
        حالة R_AARCH64_ABS32:
        حالة R_AARCH64_ABS64:
	حالة R_AARCH64_PREL32:
        حالة R_AARCH64_MOVW_UABS_G0_NC:
        حالة R_AARCH64_MOVW_UABS_G1_NC:
        حالة R_AARCH64_MOVW_UABS_G2_NC:
        حالة R_AARCH64_MOVW_UABS_G3:
        حالة R_AARCH64_ADR_PREL_PG_HI21:
        حالة R_AARCH64_جمع_کړه_ABS_LO12_NC:
        حالة R_AARCH64_ADR_GOT_پاڼه:
        حالة R_AARCH64_LD64_GOT_LO12_NC:
        حالة R_AARCH64_LDST128_ABS_LO12_NC:
        حالة R_AARCH64_LDST64_ABS_LO12_NC:
        حالة R_AARCH64_LDST32_ABS_LO12_NC:
        حالة R_AARCH64_LDST16_ABS_LO12_NC:
        حالة R_AARCH64_LDST8_ABS_LO12_NC:
        حالة R_AARCH64_TLSLE_جمع_کړه_TPREL_HI12:
        حالة R_AARCH64_TLSLE_جمع_کړه_TPREL_LO12:
        حالة R_AARCH64_GLOB_DAT:
        حالة R_AARCH64_COPY:
            أرجع 0;

        حالة R_AARCH64_JUMP26:
        حالة R_AARCH64_CALL26:
        حالة R_AARCH64_JUMP_خونه:
        حالة R_AARCH64_CONDBR19:
        حالة R_AARCH64_TSTBR14:
            أرجع 1;
    }
    أرجع -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC صحيح gotplt_ثبت_type (صحيح reloc_type)
{
    بدل (reloc_type) {
	حالة R_AARCH64_PREL32:
        حالة R_AARCH64_MOVW_UABS_G0_NC:
        حالة R_AARCH64_MOVW_UABS_G1_NC:
        حالة R_AARCH64_MOVW_UABS_G2_NC:
        حالة R_AARCH64_MOVW_UABS_G3:
        حالة R_AARCH64_ADR_PREL_PG_HI21:
        حالة R_AARCH64_جمع_کړه_ABS_LO12_NC:
        حالة R_AARCH64_LDST128_ABS_LO12_NC:
        حالة R_AARCH64_LDST64_ABS_LO12_NC:
        حالة R_AARCH64_LDST32_ABS_LO12_NC:
        حالة R_AARCH64_LDST16_ABS_LO12_NC:
        حالة R_AARCH64_LDST8_ABS_LO12_NC:
        حالة R_AARCH64_GLOB_DAT:
        حالة R_AARCH64_JUMP_خونه:
        حالة R_AARCH64_COPY:
        حالة R_AARCH64_CONDBR19:
        حالة R_AARCH64_TSTBR14:
        حالة R_AARCH64_TLSLE_جمع_کړه_TPREL_HI12:
        حالة R_AARCH64_TLSLE_جمع_کړه_TPREL_LO12:
            أرجع NO_GOTPLT_ثبت;

        حالة R_AARCH64_ABS32:
        حالة R_AARCH64_ABS64:
        حالة R_AARCH64_JUMP26:
        حالة R_AARCH64_CALL26:
            أرجع AUTO_GOTPLT_ثبت;

        حالة R_AARCH64_ADR_GOT_پاڼه:
        حالة R_AARCH64_LD64_GOT_LO12_NC:
            أرجع ALWAYS_GOTPLT_ثبت;
    }
    أرجع -1;
}

#که_تعریف_شوی NEED_BUILD_GOT
ST_FUNC بینښه create_plt_ثبت(TCCState *s1, بینښه got_دننه_واټن, بنية sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    بینښه plt_دننه_واټن;

    إذا (plt->معلومات_دننه_واټن == 0) {
        section_ptr_جمع_کړه(plt, 32);
    }
    plt_دننه_واټن = plt->معلومات_دننه_واټن;

    p = section_ptr_جمع_کړه(plt, 16);
    write32le(p, got_دننه_واټن);
    write32le(p + 4, (uint64_t) got_دننه_واټن >> 32);
    أرجع plt_دننه_واټن;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC فراغ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_پای_ټکی;

    إذا (!s1->plt)
      أرجع;

    p = s1->plt->معلومات;
    p_پای_ټکی = p + s1->plt->معلومات_دننه_واټن;

    إذا (p < p_پای_ټکی) {
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr + 16;
        uint64_t off = (got >> 12) - (plt >> 12);
        إذا ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (اوږد)off, (اوږد)got, (اوږد)plt);
        write32le(p, ARM64_STP_X_PRE | ARM64_RT(16) | ARM64_RT2(30) |
                      ARM64_RN(31) | ARM64_IMM7(-2)); // stp x16,x30,[sp,#-16]!
        write32le(p + 4, (ARM64_ADRP | ARM64_RD(16) | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
        write32le(p + 8, (ARM64_LDR_X | ARM64_RT(17) | ARM64_RN(16) | // ldr x17,[x16,#...]
			  (got & 0xff8) << 7));
        write32le(p + 12, (ARM64_جمع_کړه_IMM | ARM64_SF(1) | ARM64_RD(16) | ARM64_RN(16) | // add x16,x16,#...
			   (got & 0xfff) << 10));
        write32le(p + 16, ARM64_BR | ARM64_RN(17)); // br x17
        write32le(p + 20, ARM64_NOP); // nop
        write32le(p + 24, ARM64_NOP); // nop
        write32le(p + 28, ARM64_NOP); // nop
        p += 32;
	got = s1->got->sh_addr;
        طالما (p < p_پای_ټکی) {
            uint64_t pc = plt + (p - s1->plt->معلومات);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr >> 12) - (pc >> 12);
            إذا ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (اوږد)off, (اوږد)addr, (اوږد)pc);
            write32le(p, (ARM64_ADRP | ARM64_RD(16) | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
            write32le(p + 4, (ARM64_LDR_X | ARM64_RT(17) | ARM64_RN(16) | // ldr x17,[x16,#...]
			      (addr & 0xff8) << 7));
            write32le(p + 8, (ARM64_جمع_کړه_IMM | ARM64_SF(1) | ARM64_RD(16) | ARM64_RN(16) | // add x16,x16,#...
			      (addr & 0xfff) << 10));
            write32le(p + 12, ARM64_BR | ARM64_RN(17)); // br x17
            p += 16;
        }
    }

    إذا (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->معلومات;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_دننه_واټن, s1->plt->sh_addr);
	}
    }
}
#د_که_پای
#د_که_پای

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, بینښه حرف *ptr, addr_t addr, addr_t val)
{
    صحيح sym_شاخص = ELFW(R_SYM)(rel->r_info), esym_شاخص;
#که_تعریف_شوی DEBUG_RELOC
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
#د_که_پای

    بدل(type) {
        حالة R_AARCH64_ABS64:
            إذا ((s1->output_type & TCC_OUTPUT_DYN)) {
                esym_شاخص = get_sym_attr(s1, sym_شاخص, 0)->dyn_شاخص;
                qrel->r_دننه_واټن = rel->r_دننه_واټن;
                إذا (esym_شاخص) {
                    qrel->r_info = ELFW(R_INFO)(esym_شاخص, R_AARCH64_ABS64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    اكسر;
                } وإلا {
                    qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            أرجع;
        حالة R_AARCH64_ABS32:
            إذا (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_AARCH64_RELATIVE even for a 64bit pointer */
                qrel->r_دننه_واټن = rel->r_دننه_واټن;
                qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (صحيح)read32le(ptr) + val;
                qrel++;
            }
            add32le(ptr, val);
            أرجع;
	حالة R_AARCH64_PREL32:
            إذا (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_شاخص = get_sym_attr(s1, sym_شاخص, 0)->dyn_شاخص;
                إذا (esym_شاخص) {
                    qrel->r_دننه_واټن = rel->r_دننه_واټن;
                    qrel->r_info = ELFW(R_INFO)(esym_شاخص, R_AARCH64_PREL32);
                    /* Use sign extension! */
                    qrel->r_addend = (صحيح)read32le(ptr) + rel->r_addend;
                    qrel++;
                    اكسر;
                }
            }
	    add32le(ptr, val - addr);
	    أرجع;
        حالة R_AARCH64_MOVW_UABS_G0_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val & 0xffff) << 5));
            أرجع;
        حالة R_AARCH64_MOVW_UABS_G1_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 16 & 0xffff) << 5));
            أرجع;
        حالة R_AARCH64_MOVW_UABS_G2_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 32 & 0xffff) << 5));
            أرجع;
        حالة R_AARCH64_MOVW_UABS_G3:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 48 & 0xffff) << 5));
            أرجع;
        حالة R_AARCH64_ADR_PREL_PG_HI21: {
            uint64_t off = (val >> 12) - (addr >> 12);
#که_تعریف_شوی TCC_موخه_PE
            /* Weak undefined symbols resolve to address 0 on PE. ADRP cannot
               encode that from the default 64-bit image base, so materialize
               zero directly and let the paired ADD handle any low addend. */
            إذا ((off + ((uint64_t)1 << 20)) >> 21) {
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
                إذا (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, 0xd2800000 | (read32le(ptr) & 0x1f));
                    أرجع;
                }
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
            }
#وإلا
            إذا ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
#د_که_پای
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            أرجع;
        }
        حالة R_AARCH64_جمع_کړه_ABS_LO12_NC:
        حالة R_AARCH64_LDST8_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xfff) << 10));
            أرجع;
        حالة R_AARCH64_LDST16_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffe) << 9));
            أرجع;
        حالة R_AARCH64_LDST32_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffc) << 8));
            أرجع;
        حالة R_AARCH64_LDST64_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff8) << 7));
            أرجع;
        حالة R_AARCH64_LDST128_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff0) << 6));
            أرجع;
        حالة R_AARCH64_CONDBR19:
            /* Conditional branch: 19-bit signed offset, bits 23:5 */
#که_تعریف_شوی DEBUG_RELOC
     چاپ_کړه ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (حرف *) symtab_section->link->معلومات + sym->st_name);
#د_که_پای
            إذا (((val - addr) + ((uint64_t)1 << 20)) & ~(uint64_t)0x1ffffc)
                tcc_error_noabort("R_AARCH64_CONDBR19 relocation failed"
                          " (val=%lx, addr=%lx)", (اوږد)val, (اوږد)addr);
            write32le(ptr, ((read32le(ptr) & 0xff00001f) |
                            (((val - addr) >> 2 & 0x7ffff) << 5)));
            أرجع;
        حالة R_AARCH64_TSTBR14:
            /* Test and branch: 14-bit signed offset, bits 20:5 */
#که_تعریف_شوی DEBUG_RELOC
     چاپ_کړه ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (حرف *) symtab_section->link->معلومات + sym->st_name);
#د_که_پای
            إذا (((val - addr) + ((uint64_t)1 << 15)) & ~(uint64_t)0xfffc)
                tcc_error_noabort("R_AARCH64_TSTBR14 relocation failed"
                          " (val=%lx, addr=%lx)", (اوږد)val, (اوږد)addr);
            write32le(ptr, ((read32le(ptr) & 0xfff8001f) |
                            (((val - addr) >> 2 & 0x3fff) << 5)));
            أرجع;
        حالة R_AARCH64_JUMP26:
        حالة R_AARCH64_CALL26:
        {
            ثابت حرف *name;
#که_تعریف_شوی DEBUG_RELOC
	    چاپ_کړه ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
		    (حرف *) symtab_section->link->معلومات + sym->st_name);
#د_که_پای
            إذا (((val - addr) + ((uint64_t)1 << 27)) & ~(uint64_t)0xffffffc) {
#که_تعریف_شوی TCC_موخه_PE
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
                إذا (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, ARM64_NOP); /* nop */
                    أرجع;
                }
#د_که_پای
                name = (حرف *)symtab_section->link->معلومات +
                    ((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص].st_name;
                tcc_error_noabort("R_AARCH64_(JUMP|CALL)26 relocation failed"
                          " for '%s' (val=%lx, addr=%lx)",
                          name, (اوږد)val, (اوږد)addr);
            }
            write32le(ptr, (0x14000000 |
                            (uint32_t)(type == R_AARCH64_CALL26) << 31 |
                            ((val - addr) >> 2 & 0x3ffffff)));
            أرجع;
        }
        حالة R_AARCH64_ADR_GOT_پاڼه: {
            uint64_t off =
                (((s1->got->sh_addr +
                   get_sym_attr(s1, sym_شاخص, 0)->got_دننه_واټن) >> 12) - (addr >> 12));
            إذا ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_GOT_PAGE relocation failed");
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            أرجع;
        }
        حالة R_AARCH64_LD64_GOT_LO12_NC:
            write32le(ptr,
                      ((read32le(ptr) & 0xfff803ff) |
                       ((s1->got->sh_addr +
                         get_sym_attr(s1, sym_شاخص, 0)->got_دننه_واټن) & 0xff8) << 7));
            أرجع;
        حالة R_AARCH64_COPY:
            أرجع;
        حالة R_AARCH64_GLOB_DAT:
        حالة R_AARCH64_JUMP_خونه:
            /* They don't need addend */
#که_تعریف_شوی DEBUG_RELOC
	    چاپ_کړه ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr,
		    val - rel->r_addend,
		    (حرف *) symtab_section->link->معلومات + sym->st_name);
#د_که_پای
            write64le(ptr, val - rel->r_addend);
            أرجع;
        حالة R_AARCH64_TLSLE_جمع_کړه_TPREL_HI12:
        حالة R_AARCH64_TLSLE_جمع_کړه_TPREL_LO12: {
#إذا TCC_موخه_PE
            int64_t tp_دننه_واټن = val - s1->tls_پیل;
#وإلا
            /* glibc arm64: tp points to tcbhead_t (DTV), TLS data starts after it */
            int64_t tp_دننه_واټن = val - s1->tls_پیل + 16;
#د_که_پای
            int64_t imm;
            إذا (type == R_AARCH64_TLSLE_جمع_کړه_TPREL_HI12)
                imm = (tp_دننه_واټن >> 12) & 0xfff;
            وإلا
                imm = tp_دننه_واټن & 0xfff;
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) | (imm << 10)));
            أرجع;
        }
        حالة R_AARCH64_RELATIVE:
#که_تعریف_شوی TCC_موخه_PE
            add32le(ptr, val - s1->pe_imagebase);
#د_که_پای
            /* do nothing */
            أرجع;
        افتراضي:
            fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (بینښه)addr, ptr, (بینښه)val);
            أرجع;
    }
}

#د_که_پای /* !TARGET_DEFS_ONLY */
