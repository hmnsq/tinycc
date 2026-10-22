#جے_تعریف_شدہ نشانہ_DEFS_ONLY

#تعریف_کرو EM_TCC_نشانہ EM_AARCH64

#تعریف_کرو R_انکڑے_32  R_AARCH64_ABS32
#تعریف_کرو R_انکڑے_PTR R_AARCH64_ABS64
#تعریف_کرو R_JMP_تھاں R_AARCH64_JUMP_تھاں
#تعریف_کرو R_GLOB_DAT R_AARCH64_GLOB_DAT
#تعریف_کرو R_COPY     R_AARCH64_COPY
#تعریف_کرو R_RELATIVE R_AARCH64_RELATIVE

#تعریف_کرو R_عدد      R_AARCH64_عدد

#تعریف_کرو ELF_شروع_ADDR 0x00400000
#تعریف_کرو ELF_ورقہ_ناپ 0x10000

#تعریف_کرو PCRELATIVE_DLLPLT 1
#تعریف_کرو RELOCATE_DLLPLT 1

#وإلا /* !TARGET_DEFS_ONLY */

#ضمن "tcc.h"

#جے_تعریف_شدہ NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحيح کوڈ_reloc (صحيح reloc_type)
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
        حالة R_AARCH64_جوڑو_ABS_LO12_NC:
        حالة R_AARCH64_ADR_GOT_ورقہ:
        حالة R_AARCH64_LD64_GOT_LO12_NC:
        حالة R_AARCH64_LDST128_ABS_LO12_NC:
        حالة R_AARCH64_LDST64_ABS_LO12_NC:
        حالة R_AARCH64_LDST32_ABS_LO12_NC:
        حالة R_AARCH64_LDST16_ABS_LO12_NC:
        حالة R_AARCH64_LDST8_ABS_LO12_NC:
        حالة R_AARCH64_TLSLE_جوڑو_TPREL_HI12:
        حالة R_AARCH64_TLSLE_جوڑو_TPREL_LO12:
        حالة R_AARCH64_GLOB_DAT:
        حالة R_AARCH64_COPY:
            أرجع 0;

        حالة R_AARCH64_JUMP26:
        حالة R_AARCH64_CALL26:
        حالة R_AARCH64_JUMP_تھاں:
        حالة R_AARCH64_CONDBR19:
        حالة R_AARCH64_TSTBR14:
            أرجع 1;
    }
    أرجع -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC صحيح gotplt_اندراج_type (صحيح reloc_type)
{
    بدل (reloc_type) {
	حالة R_AARCH64_PREL32:
        حالة R_AARCH64_MOVW_UABS_G0_NC:
        حالة R_AARCH64_MOVW_UABS_G1_NC:
        حالة R_AARCH64_MOVW_UABS_G2_NC:
        حالة R_AARCH64_MOVW_UABS_G3:
        حالة R_AARCH64_ADR_PREL_PG_HI21:
        حالة R_AARCH64_جوڑو_ABS_LO12_NC:
        حالة R_AARCH64_LDST128_ABS_LO12_NC:
        حالة R_AARCH64_LDST64_ABS_LO12_NC:
        حالة R_AARCH64_LDST32_ABS_LO12_NC:
        حالة R_AARCH64_LDST16_ABS_LO12_NC:
        حالة R_AARCH64_LDST8_ABS_LO12_NC:
        حالة R_AARCH64_GLOB_DAT:
        حالة R_AARCH64_JUMP_تھاں:
        حالة R_AARCH64_COPY:
        حالة R_AARCH64_CONDBR19:
        حالة R_AARCH64_TSTBR14:
        حالة R_AARCH64_TLSLE_جوڑو_TPREL_HI12:
        حالة R_AARCH64_TLSLE_جوڑو_TPREL_LO12:
            أرجع NO_GOTPLT_اندراج;

        حالة R_AARCH64_ABS32:
        حالة R_AARCH64_ABS64:
        حالة R_AARCH64_JUMP26:
        حالة R_AARCH64_CALL26:
            أرجع AUTO_GOTPLT_اندراج;

        حالة R_AARCH64_ADR_GOT_ورقہ:
        حالة R_AARCH64_LD64_GOT_LO12_NC:
            أرجع ALWAYS_GOTPLT_اندراج;
    }
    أرجع -1;
}

#جے_تعریف_شدہ NEED_BUILD_GOT
ST_FUNC بنانشانی create_plt_اندراج(TCCState *s1, بنانشانی got_وتھ, بنية sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    بنانشانی plt_وتھ;

    إذا (plt->انکڑے_وتھ == 0) {
        section_ptr_جوڑو(plt, 32);
    }
    plt_وتھ = plt->انکڑے_وتھ;

    p = section_ptr_جوڑو(plt, 16);
    write32le(p, got_وتھ);
    write32le(p + 4, (uint64_t) got_وتھ >> 32);
    أرجع plt_وتھ;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC فراغ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_سرا;

    إذا (!s1->plt)
      أرجع;

    p = s1->plt->انکڑے;
    p_سرا = p + s1->plt->انکڑے_وتھ;

    إذا (p < p_سرا) {
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr + 16;
        uint64_t off = (got >> 12) - (plt >> 12);
        إذا ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (لما)off, (لما)got, (لما)plt);
        write32le(p, ARM64_STP_X_PRE | ARM64_RT(16) | ARM64_RT2(30) |
                      ARM64_RN(31) | ARM64_IMM7(-2)); // stp x16,x30,[sp,#-16]!
        write32le(p + 4, (ARM64_ADRP | ARM64_RD(16) | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
        write32le(p + 8, (ARM64_LDR_X | ARM64_RT(17) | ARM64_RN(16) | // ldr x17,[x16,#...]
			  (got & 0xff8) << 7));
        write32le(p + 12, (ARM64_جوڑو_IMM | ARM64_SF(1) | ARM64_RD(16) | ARM64_RN(16) | // add x16,x16,#...
			   (got & 0xfff) << 10));
        write32le(p + 16, ARM64_BR | ARM64_RN(17)); // br x17
        write32le(p + 20, ARM64_NOP); // nop
        write32le(p + 24, ARM64_NOP); // nop
        write32le(p + 28, ARM64_NOP); // nop
        p += 32;
	got = s1->got->sh_addr;
        طالما (p < p_سرا) {
            uint64_t pc = plt + (p - s1->plt->انکڑے);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr >> 12) - (pc >> 12);
            إذا ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (لما)off, (لما)addr, (لما)pc);
            write32le(p, (ARM64_ADRP | ARM64_RD(16) | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
            write32le(p + 4, (ARM64_LDR_X | ARM64_RT(17) | ARM64_RN(16) | // ldr x17,[x16,#...]
			      (addr & 0xff8) << 7));
            write32le(p + 8, (ARM64_جوڑو_IMM | ARM64_SF(1) | ARM64_RD(16) | ARM64_RN(16) | // add x16,x16,#...
			      (addr & 0xfff) << 10));
            write32le(p + 12, ARM64_BR | ARM64_RN(17)); // br x17
            p += 16;
        }
    }

    إذا (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->انکڑے;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_وتھ, s1->plt->sh_addr);
	}
    }
}
#جے_انت
#جے_انت

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, بنانشانی حرف *ptr, addr_t addr, addr_t val)
{
    صحيح sym_اشاریہ = ELFW(R_SYM)(rel->r_info), esym_اشاریہ;
#جے_تعریف_شدہ DEBUG_RELOC
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->انکڑے)[sym_اشاریہ];
#جے_انت

    بدل(type) {
        حالة R_AARCH64_ABS64:
            إذا ((s1->output_type & TCC_OUTPUT_DYN)) {
                esym_اشاریہ = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
                qrel->r_وتھ = rel->r_وتھ;
                إذا (esym_اشاریہ) {
                    qrel->r_info = ELFW(R_INFO)(esym_اشاریہ, R_AARCH64_ABS64);
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
                qrel->r_وتھ = rel->r_وتھ;
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
                esym_اشاریہ = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
                إذا (esym_اشاریہ) {
                    qrel->r_وتھ = rel->r_وتھ;
                    qrel->r_info = ELFW(R_INFO)(esym_اشاریہ, R_AARCH64_PREL32);
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
#جے_تعریف_شدہ TCC_نشانہ_PE
            /* Weak undefined symbols resolve to address 0 on PE. ADRP cannot
               encode that from the default 64-bit image base, so materialize
               zero directly and let the paired ADD handle any low addend. */
            إذا ((off + ((uint64_t)1 << 20)) >> 21) {
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->انکڑے)[sym_اشاریہ];
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
#جے_انت
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            أرجع;
        }
        حالة R_AARCH64_جوڑو_ABS_LO12_NC:
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
#جے_تعریف_شدہ DEBUG_RELOC
     لکھو ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (حرف *) symtab_section->link->انکڑے + sym->st_name);
#جے_انت
            إذا (((val - addr) + ((uint64_t)1 << 20)) & ~(uint64_t)0x1ffffc)
                tcc_error_noabort("R_AARCH64_CONDBR19 relocation failed"
                          " (val=%lx, addr=%lx)", (لما)val, (لما)addr);
            write32le(ptr, ((read32le(ptr) & 0xff00001f) |
                            (((val - addr) >> 2 & 0x7ffff) << 5)));
            أرجع;
        حالة R_AARCH64_TSTBR14:
            /* Test and branch: 14-bit signed offset, bits 20:5 */
#جے_تعریف_شدہ DEBUG_RELOC
     لکھو ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (حرف *) symtab_section->link->انکڑے + sym->st_name);
#جے_انت
            إذا (((val - addr) + ((uint64_t)1 << 15)) & ~(uint64_t)0xfffc)
                tcc_error_noabort("R_AARCH64_TSTBR14 relocation failed"
                          " (val=%lx, addr=%lx)", (لما)val, (لما)addr);
            write32le(ptr, ((read32le(ptr) & 0xfff8001f) |
                            (((val - addr) >> 2 & 0x3fff) << 5)));
            أرجع;
        حالة R_AARCH64_JUMP26:
        حالة R_AARCH64_CALL26:
        {
            ثابت حرف *name;
#جے_تعریف_شدہ DEBUG_RELOC
	    لکھو ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
		    (حرف *) symtab_section->link->انکڑے + sym->st_name);
#جے_انت
            إذا (((val - addr) + ((uint64_t)1 << 27)) & ~(uint64_t)0xffffffc) {
#جے_تعریف_شدہ TCC_نشانہ_PE
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->انکڑے)[sym_اشاریہ];
                إذا (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, ARM64_NOP); /* nop */
                    أرجع;
                }
#جے_انت
                name = (حرف *)symtab_section->link->انکڑے +
                    ((ElfW(Sym) *)symtab_section->انکڑے)[sym_اشاریہ].st_name;
                tcc_error_noabort("R_AARCH64_(JUMP|CALL)26 relocation failed"
                          " for '%s' (val=%lx, addr=%lx)",
                          name, (لما)val, (لما)addr);
            }
            write32le(ptr, (0x14000000 |
                            (uint32_t)(type == R_AARCH64_CALL26) << 31 |
                            ((val - addr) >> 2 & 0x3ffffff)));
            أرجع;
        }
        حالة R_AARCH64_ADR_GOT_ورقہ: {
            uint64_t off =
                (((s1->got->sh_addr +
                   get_sym_attr(s1, sym_اشاریہ, 0)->got_وتھ) >> 12) - (addr >> 12));
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
                         get_sym_attr(s1, sym_اشاریہ, 0)->got_وتھ) & 0xff8) << 7));
            أرجع;
        حالة R_AARCH64_COPY:
            أرجع;
        حالة R_AARCH64_GLOB_DAT:
        حالة R_AARCH64_JUMP_تھاں:
            /* They don't need addend */
#جے_تعریف_شدہ DEBUG_RELOC
	    لکھو ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr,
		    val - rel->r_addend,
		    (حرف *) symtab_section->link->انکڑے + sym->st_name);
#جے_انت
            write64le(ptr, val - rel->r_addend);
            أرجع;
        حالة R_AARCH64_TLSLE_جوڑو_TPREL_HI12:
        حالة R_AARCH64_TLSLE_جوڑو_TPREL_LO12: {
#إذا TCC_نشانہ_PE
            int64_t tp_وتھ = val - s1->tls_شروع;
#وإلا
            /* glibc arm64: tp points to tcbhead_t (DTV), TLS data starts after it */
            int64_t tp_وتھ = val - s1->tls_شروع + 16;
#جے_انت
            int64_t imm;
            إذا (type == R_AARCH64_TLSLE_جوڑو_TPREL_HI12)
                imm = (tp_وتھ >> 12) & 0xfff;
            وإلا
                imm = tp_وتھ & 0xfff;
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) | (imm << 10)));
            أرجع;
        }
        حالة R_AARCH64_RELATIVE:
#جے_تعریف_شدہ TCC_نشانہ_PE
            add32le(ptr, val - s1->pe_imagebase);
#جے_انت
            /* do nothing */
            أرجع;
        افتراضي:
            fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (بنانشانی)addr, ptr, (بنانشانی)val);
            أرجع;
    }
}

#جے_انت /* !TARGET_DEFS_ONLY */
