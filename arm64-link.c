#اگر_تعریف_شدہ ہدف_DEFS_ONLY

#تعریف_کرو EM_TCC_ہدف EM_AARCH64

#تعریف_کرو R_ڈیٹا_32  R_AARCH64_ABS32
#تعریف_کرو R_ڈیٹا_PTR R_AARCH64_ABS64
#تعریف_کرو R_JMP_خانہ R_AARCH64_JUMP_خانہ
#تعریف_کرو R_GLOB_DAT R_AARCH64_GLOB_DAT
#تعریف_کرو R_COPY     R_AARCH64_COPY
#تعریف_کرو R_RELATIVE R_AARCH64_RELATIVE

#تعریف_کرو R_عدد      R_AARCH64_عدد

#تعریف_کرو ELF_آغاز_ADDR 0x00400000
#تعریف_کرو ELF_صفحہ_سائز 0x10000

#تعریف_کرو PCRELATIVE_DLLPLT 1
#تعریف_کرو RELOCATE_DLLPLT 1

#ورنہ /* !TARGET_DEFS_ONLY */

#شامل "tcc.h"

#اگر_تعریف_شدہ NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحیح رمز_reloc (صحیح reloc_type)
{
    انتخاب (reloc_type) {
        حالت R_AARCH64_ABS32:
        حالت R_AARCH64_ABS64:
	حالت R_AARCH64_PREL32:
        حالت R_AARCH64_MOVW_UABS_G0_NC:
        حالت R_AARCH64_MOVW_UABS_G1_NC:
        حالت R_AARCH64_MOVW_UABS_G2_NC:
        حالت R_AARCH64_MOVW_UABS_G3:
        حالت R_AARCH64_ADR_PREL_PG_HI21:
        حالت R_AARCH64_جوڑو_ABS_LO12_NC:
        حالت R_AARCH64_ADR_GOT_صفحہ:
        حالت R_AARCH64_LD64_GOT_LO12_NC:
        حالت R_AARCH64_LDST128_ABS_LO12_NC:
        حالت R_AARCH64_LDST64_ABS_LO12_NC:
        حالت R_AARCH64_LDST32_ABS_LO12_NC:
        حالت R_AARCH64_LDST16_ABS_LO12_NC:
        حالت R_AARCH64_LDST8_ABS_LO12_NC:
        حالت R_AARCH64_TLSLE_جوڑو_TPREL_HI12:
        حالت R_AARCH64_TLSLE_جوڑو_TPREL_LO12:
        حالت R_AARCH64_GLOB_DAT:
        حالت R_AARCH64_COPY:
            واپس 0;

        حالت R_AARCH64_JUMP26:
        حالت R_AARCH64_CALL26:
        حالت R_AARCH64_JUMP_خانہ:
        حالت R_AARCH64_CONDBR19:
        حالت R_AARCH64_TSTBR14:
            واپس 1;
    }
    واپس -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC صحیح gotplt_اندراج_type (صحیح reloc_type)
{
    انتخاب (reloc_type) {
	حالت R_AARCH64_PREL32:
        حالت R_AARCH64_MOVW_UABS_G0_NC:
        حالت R_AARCH64_MOVW_UABS_G1_NC:
        حالت R_AARCH64_MOVW_UABS_G2_NC:
        حالت R_AARCH64_MOVW_UABS_G3:
        حالت R_AARCH64_ADR_PREL_PG_HI21:
        حالت R_AARCH64_جوڑو_ABS_LO12_NC:
        حالت R_AARCH64_LDST128_ABS_LO12_NC:
        حالت R_AARCH64_LDST64_ABS_LO12_NC:
        حالت R_AARCH64_LDST32_ABS_LO12_NC:
        حالت R_AARCH64_LDST16_ABS_LO12_NC:
        حالت R_AARCH64_LDST8_ABS_LO12_NC:
        حالت R_AARCH64_GLOB_DAT:
        حالت R_AARCH64_JUMP_خانہ:
        حالت R_AARCH64_COPY:
        حالت R_AARCH64_CONDBR19:
        حالت R_AARCH64_TSTBR14:
        حالت R_AARCH64_TLSLE_جوڑو_TPREL_HI12:
        حالت R_AARCH64_TLSLE_جوڑو_TPREL_LO12:
            واپس NO_GOTPLT_اندراج;

        حالت R_AARCH64_ABS32:
        حالت R_AARCH64_ABS64:
        حالت R_AARCH64_JUMP26:
        حالت R_AARCH64_CALL26:
            واپس AUTO_GOTPLT_اندراج;

        حالت R_AARCH64_ADR_GOT_صفحہ:
        حالت R_AARCH64_LD64_GOT_LO12_NC:
            واپس ALWAYS_GOTPLT_اندراج;
    }
    واپس -1;
}

#اگر_تعریف_شدہ NEED_BUILD_GOT
ST_FUNC غیرعلامتی create_plt_اندراج(TCCState *s1, غیرعلامتی got_انحراف, ساخت sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    غیرعلامتی plt_انحراف;

    اگر (plt->ڈیٹا_انحراف == 0) {
        section_ptr_جوڑو(plt, 32);
    }
    plt_انحراف = plt->ڈیٹا_انحراف;

    p = section_ptr_جوڑو(plt, 16);
    write32le(p, got_انحراف);
    write32le(p + 4, (uint64_t) got_انحراف >> 32);
    واپس plt_انحراف;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC خالی relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_انتہا;

    اگر (!s1->plt)
      واپس;

    p = s1->plt->ڈیٹا;
    p_انتہا = p + s1->plt->ڈیٹا_انحراف;

    اگر (p < p_انتہا) {
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr + 16;
        uint64_t off = (got >> 12) - (plt >> 12);
        اگر ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (طویل)off, (طویل)got, (طویل)plt);
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
        جب (p < p_انتہا) {
            uint64_t pc = plt + (p - s1->plt->ڈیٹا);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr >> 12) - (pc >> 12);
            اگر ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (طویل)off, (طویل)addr, (طویل)pc);
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

    اگر (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->ڈیٹا;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_انحراف, s1->plt->sh_addr);
	}
    }
}
#اگر_ختم
#اگر_ختم

ST_FUNC خالی relocate(TCCState *s1, ElfW_Rel *rel, صحیح type, غیرعلامتی حرف *ptr, addr_t addr, addr_t val)
{
    صحیح sym_اشاریہ = ELFW(R_SYM)(rel->r_info), esym_اشاریہ;
#اگر_تعریف_شدہ DEBUG_RELOC
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
#اگر_ختم

    انتخاب(type) {
        حالت R_AARCH64_ABS64:
            اگر ((s1->output_type & TCC_OUTPUT_DYN)) {
                esym_اشاریہ = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
                qrel->r_انحراف = rel->r_انحراف;
                اگر (esym_اشاریہ) {
                    qrel->r_info = ELFW(R_INFO)(esym_اشاریہ, R_AARCH64_ABS64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    توڑو;
                } ورنہ {
                    qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            واپس;
        حالت R_AARCH64_ABS32:
            اگر (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_AARCH64_RELATIVE even for a 64bit pointer */
                qrel->r_انحراف = rel->r_انحراف;
                qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (صحیح)read32le(ptr) + val;
                qrel++;
            }
            add32le(ptr, val);
            واپس;
	حالت R_AARCH64_PREL32:
            اگر (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_اشاریہ = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
                اگر (esym_اشاریہ) {
                    qrel->r_انحراف = rel->r_انحراف;
                    qrel->r_info = ELFW(R_INFO)(esym_اشاریہ, R_AARCH64_PREL32);
                    /* Use sign extension! */
                    qrel->r_addend = (صحیح)read32le(ptr) + rel->r_addend;
                    qrel++;
                    توڑو;
                }
            }
	    add32le(ptr, val - addr);
	    واپس;
        حالت R_AARCH64_MOVW_UABS_G0_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val & 0xffff) << 5));
            واپس;
        حالت R_AARCH64_MOVW_UABS_G1_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 16 & 0xffff) << 5));
            واپس;
        حالت R_AARCH64_MOVW_UABS_G2_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 32 & 0xffff) << 5));
            واپس;
        حالت R_AARCH64_MOVW_UABS_G3:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 48 & 0xffff) << 5));
            واپس;
        حالت R_AARCH64_ADR_PREL_PG_HI21: {
            uint64_t off = (val >> 12) - (addr >> 12);
#اگر_تعریف_شدہ TCC_ہدف_PE
            /* Weak undefined symbols resolve to address 0 on PE. ADRP cannot
               encode that from the default 64-bit image base, so materialize
               zero directly and let the paired ADD handle any low addend. */
            اگر ((off + ((uint64_t)1 << 20)) >> 21) {
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
                اگر (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, 0xd2800000 | (read32le(ptr) & 0x1f));
                    واپس;
                }
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
            }
#ورنہ
            اگر ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
#اگر_ختم
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            واپس;
        }
        حالت R_AARCH64_جوڑو_ABS_LO12_NC:
        حالت R_AARCH64_LDST8_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xfff) << 10));
            واپس;
        حالت R_AARCH64_LDST16_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffe) << 9));
            واپس;
        حالت R_AARCH64_LDST32_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffc) << 8));
            واپس;
        حالت R_AARCH64_LDST64_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff8) << 7));
            واپس;
        حالت R_AARCH64_LDST128_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff0) << 6));
            واپس;
        حالت R_AARCH64_CONDBR19:
            /* Conditional branch: 19-bit signed offset, bits 23:5 */
#اگر_تعریف_شدہ DEBUG_RELOC
     لکھو ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (حرف *) symtab_section->link->ڈیٹا + sym->st_name);
#اگر_ختم
            اگر (((val - addr) + ((uint64_t)1 << 20)) & ~(uint64_t)0x1ffffc)
                tcc_error_noabort("R_AARCH64_CONDBR19 relocation failed"
                          " (val=%lx, addr=%lx)", (طویل)val, (طویل)addr);
            write32le(ptr, ((read32le(ptr) & 0xff00001f) |
                            (((val - addr) >> 2 & 0x7ffff) << 5)));
            واپس;
        حالت R_AARCH64_TSTBR14:
            /* Test and branch: 14-bit signed offset, bits 20:5 */
#اگر_تعریف_شدہ DEBUG_RELOC
     لکھو ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (حرف *) symtab_section->link->ڈیٹا + sym->st_name);
#اگر_ختم
            اگر (((val - addr) + ((uint64_t)1 << 15)) & ~(uint64_t)0xfffc)
                tcc_error_noabort("R_AARCH64_TSTBR14 relocation failed"
                          " (val=%lx, addr=%lx)", (طویل)val, (طویل)addr);
            write32le(ptr, ((read32le(ptr) & 0xfff8001f) |
                            (((val - addr) >> 2 & 0x3fff) << 5)));
            واپس;
        حالت R_AARCH64_JUMP26:
        حالت R_AARCH64_CALL26:
        {
            ثابت حرف *name;
#اگر_تعریف_شدہ DEBUG_RELOC
	    لکھو ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
		    (حرف *) symtab_section->link->ڈیٹا + sym->st_name);
#اگر_ختم
            اگر (((val - addr) + ((uint64_t)1 << 27)) & ~(uint64_t)0xffffffc) {
#اگر_تعریف_شدہ TCC_ہدف_PE
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
                اگر (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, ARM64_NOP); /* nop */
                    واپس;
                }
#اگر_ختم
                name = (حرف *)symtab_section->link->ڈیٹا +
                    ((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ].st_name;
                tcc_error_noabort("R_AARCH64_(JUMP|CALL)26 relocation failed"
                          " for '%s' (val=%lx, addr=%lx)",
                          name, (طویل)val, (طویل)addr);
            }
            write32le(ptr, (0x14000000 |
                            (uint32_t)(type == R_AARCH64_CALL26) << 31 |
                            ((val - addr) >> 2 & 0x3ffffff)));
            واپس;
        }
        حالت R_AARCH64_ADR_GOT_صفحہ: {
            uint64_t off =
                (((s1->got->sh_addr +
                   get_sym_attr(s1, sym_اشاریہ, 0)->got_انحراف) >> 12) - (addr >> 12));
            اگر ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_GOT_PAGE relocation failed");
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            واپس;
        }
        حالت R_AARCH64_LD64_GOT_LO12_NC:
            write32le(ptr,
                      ((read32le(ptr) & 0xfff803ff) |
                       ((s1->got->sh_addr +
                         get_sym_attr(s1, sym_اشاریہ, 0)->got_انحراف) & 0xff8) << 7));
            واپس;
        حالت R_AARCH64_COPY:
            واپس;
        حالت R_AARCH64_GLOB_DAT:
        حالت R_AARCH64_JUMP_خانہ:
            /* They don't need addend */
#اگر_تعریف_شدہ DEBUG_RELOC
	    لکھو ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr,
		    val - rel->r_addend,
		    (حرف *) symtab_section->link->ڈیٹا + sym->st_name);
#اگر_ختم
            write64le(ptr, val - rel->r_addend);
            واپس;
        حالت R_AARCH64_TLSLE_جوڑو_TPREL_HI12:
        حالت R_AARCH64_TLSLE_جوڑو_TPREL_LO12: {
#اگر TCC_ہدف_PE
            int64_t tp_انحراف = val - s1->tls_آغاز;
#ورنہ
            /* glibc arm64: tp points to tcbhead_t (DTV), TLS data starts after it */
            int64_t tp_انحراف = val - s1->tls_آغاز + 16;
#اگر_ختم
            int64_t imm;
            اگر (type == R_AARCH64_TLSLE_جوڑو_TPREL_HI12)
                imm = (tp_انحراف >> 12) & 0xfff;
            ورنہ
                imm = tp_انحراف & 0xfff;
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) | (imm << 10)));
            واپس;
        }
        حالت R_AARCH64_RELATIVE:
#اگر_تعریف_شدہ TCC_ہدف_PE
            add32le(ptr, val - s1->pe_imagebase);
#اگر_ختم
            /* do nothing */
            واپس;
        طےشدہ:
            fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (غیرعلامتی)addr, ptr, (غیرعلامتی)val);
            واپس;
    }
}

#اگر_ختم /* !TARGET_DEFS_ONLY */
