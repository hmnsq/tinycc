#यदि_परिभाषितम् TARGET_DEFS_ONLY

#परिभाषय EM_TCC_TARGET EM_AARCH64

#परिभाषय R_दत्त_32  R_AARCH64_ABS32
#परिभाषय R_दत्त_PTR R_AARCH64_ABS64
#परिभाषय R_JMP_SLOT R_AARCH64_JUMP_SLOT
#परिभाषय R_GLOB_DAT R_AARCH64_GLOB_DAT
#परिभाषय R_COPY     R_AARCH64_COPY
#परिभाषय R_RELATIVE R_AARCH64_RELATIVE

#परिभाषय R_अङ्कः      R_AARCH64_अङ्कः

#परिभाषय ELF_START_ADDR 0x00400000
#परिभाषय ELF_PAGE_आकार 0x10000

#परिभाषय PCRELATIVE_DLLPLT 1
#परिभाषय RELOCATE_DLLPLT 1

#अन्यथा /* !TARGET_DEFS_ONLY */

#अन्तर्भाव "tcc.h"

#यदि_परिभाषितम् NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC पूर्णाङ्क संहिता_reloc (पूर्णाङ्क reloc_type)
{
    विकल्प (reloc_type) {
        पक्ष R_AARCH64_ABS32:
        पक्ष R_AARCH64_ABS64:
	पक्ष R_AARCH64_PREL32:
        पक्ष R_AARCH64_MOVW_UABS_G0_NC:
        पक्ष R_AARCH64_MOVW_UABS_G1_NC:
        पक्ष R_AARCH64_MOVW_UABS_G2_NC:
        पक्ष R_AARCH64_MOVW_UABS_G3:
        पक्ष R_AARCH64_ADR_PREL_PG_HI21:
        पक्ष R_AARCH64_सङ्कलय_ABS_LO12_NC:
        पक्ष R_AARCH64_ADR_GOT_PAGE:
        पक्ष R_AARCH64_LD64_GOT_LO12_NC:
        पक्ष R_AARCH64_LDST128_ABS_LO12_NC:
        पक्ष R_AARCH64_LDST64_ABS_LO12_NC:
        पक्ष R_AARCH64_LDST32_ABS_LO12_NC:
        पक्ष R_AARCH64_LDST16_ABS_LO12_NC:
        पक्ष R_AARCH64_LDST8_ABS_LO12_NC:
        पक्ष R_AARCH64_TLSLE_सङ्कलय_TPREL_HI12:
        पक्ष R_AARCH64_TLSLE_सङ्कलय_TPREL_LO12:
        पक्ष R_AARCH64_GLOB_DAT:
        पक्ष R_AARCH64_COPY:
            प्रत्यागम 0;

        पक्ष R_AARCH64_JUMP26:
        पक्ष R_AARCH64_CALL26:
        पक्ष R_AARCH64_JUMP_SLOT:
        पक्ष R_AARCH64_CONDBR19:
        पक्ष R_AARCH64_TSTBR14:
            प्रत्यागम 1;
    }
    प्रत्यागम -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC पूर्णाङ्क gotplt_प्रविष्टिः_type (पूर्णाङ्क reloc_type)
{
    विकल्प (reloc_type) {
	पक्ष R_AARCH64_PREL32:
        पक्ष R_AARCH64_MOVW_UABS_G0_NC:
        पक्ष R_AARCH64_MOVW_UABS_G1_NC:
        पक्ष R_AARCH64_MOVW_UABS_G2_NC:
        पक्ष R_AARCH64_MOVW_UABS_G3:
        पक्ष R_AARCH64_ADR_PREL_PG_HI21:
        पक्ष R_AARCH64_सङ्कलय_ABS_LO12_NC:
        पक्ष R_AARCH64_LDST128_ABS_LO12_NC:
        पक्ष R_AARCH64_LDST64_ABS_LO12_NC:
        पक्ष R_AARCH64_LDST32_ABS_LO12_NC:
        पक्ष R_AARCH64_LDST16_ABS_LO12_NC:
        पक्ष R_AARCH64_LDST8_ABS_LO12_NC:
        पक्ष R_AARCH64_GLOB_DAT:
        पक्ष R_AARCH64_JUMP_SLOT:
        पक्ष R_AARCH64_COPY:
        पक्ष R_AARCH64_CONDBR19:
        पक्ष R_AARCH64_TSTBR14:
        पक्ष R_AARCH64_TLSLE_सङ्कलय_TPREL_HI12:
        पक्ष R_AARCH64_TLSLE_सङ्कलय_TPREL_LO12:
            प्रत्यागम NO_GOTPLT_प्रविष्टिः;

        पक्ष R_AARCH64_ABS32:
        पक्ष R_AARCH64_ABS64:
        पक्ष R_AARCH64_JUMP26:
        पक्ष R_AARCH64_CALL26:
            प्रत्यागम AUTO_GOTPLT_प्रविष्टिः;

        पक्ष R_AARCH64_ADR_GOT_PAGE:
        पक्ष R_AARCH64_LD64_GOT_LO12_NC:
            प्रत्यागम ALWAYS_GOTPLT_प्रविष्टिः;
    }
    प्रत्यागम -1;
}

#यदि_परिभाषितम् NEED_BUILD_GOT
ST_FUNC अचिह्नित create_plt_प्रविष्टिः(TCCState *s1, अचिह्नित got_विस्थापनम्, संरचना sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    अचिह्नित plt_विस्थापनम्;

    यदि (plt->दत्त_विस्थापनम् == 0) {
        section_ptr_सङ्कलय(plt, 32);
    }
    plt_विस्थापनम् = plt->दत्त_विस्थापनम्;

    p = section_ptr_सङ्कलय(plt, 16);
    write32le(p, got_विस्थापनम्);
    write32le(p + 4, (uint64_t) got_विस्थापनम् >> 32);
    प्रत्यागम plt_विस्थापनम्;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC शून्य relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_अन्तः;

    यदि (!s1->plt)
      प्रत्यागम;

    p = s1->plt->दत्त;
    p_अन्तः = p + s1->plt->दत्त_विस्थापनम्;

    यदि (p < p_अन्तः) {
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr + 16;
        uint64_t off = (got >> 12) - (plt >> 12);
        यदि ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (दीर्घ)off, (दीर्घ)got, (दीर्घ)plt);
        write32le(p, ARM64_STP_X_PRE | ARM64_RT(16) | ARM64_RT2(30) |
                      ARM64_RN(31) | ARM64_IMM7(-2)); // stp x16,x30,[sp,#-16]!
        write32le(p + 4, (ARM64_ADRP | ARM64_RD(16) | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
        write32le(p + 8, (ARM64_LDR_X | ARM64_RT(17) | ARM64_RN(16) | // ldr x17,[x16,#...]
			  (got & 0xff8) << 7));
        write32le(p + 12, (ARM64_सङ्कलय_IMM | ARM64_SF(1) | ARM64_RD(16) | ARM64_RN(16) | // add x16,x16,#...
			   (got & 0xfff) << 10));
        write32le(p + 16, ARM64_BR | ARM64_RN(17)); // br x17
        write32le(p + 20, ARM64_NOP); // nop
        write32le(p + 24, ARM64_NOP); // nop
        write32le(p + 28, ARM64_NOP); // nop
        p += 32;
	got = s1->got->sh_addr;
        यावत् (p < p_अन्तः) {
            uint64_t pc = plt + (p - s1->plt->दत्त);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr >> 12) - (pc >> 12);
            यदि ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (दीर्घ)off, (दीर्घ)addr, (दीर्घ)pc);
            write32le(p, (ARM64_ADRP | ARM64_RD(16) | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
            write32le(p + 4, (ARM64_LDR_X | ARM64_RT(17) | ARM64_RN(16) | // ldr x17,[x16,#...]
			      (addr & 0xff8) << 7));
            write32le(p + 8, (ARM64_सङ्कलय_IMM | ARM64_SF(1) | ARM64_RD(16) | ARM64_RN(16) | // add x16,x16,#...
			      (addr & 0xfff) << 10));
            write32le(p + 12, ARM64_BR | ARM64_RN(17)); // br x17
            p += 16;
        }
    }

    यदि (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->दत्त;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_विस्थापनम्, s1->plt->sh_addr);
	}
    }
}
#यदि_अन्तः
#यदि_अन्तः

ST_FUNC शून्य relocate(TCCState *s1, ElfW_Rel *rel, पूर्णाङ्क type, अचिह्नित वर्ण *ptr, addr_t addr, addr_t val)
{
    पूर्णाङ्क sym_सूचकांक = ELFW(R_SYM)(rel->r_info), esym_सूचकांक;
#यदि_परिभाषितम् DEBUG_RELOC
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
#यदि_अन्तः

    विकल्प(type) {
        पक्ष R_AARCH64_ABS64:
            यदि ((s1->output_type & TCC_OUTPUT_DYN)) {
                esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
                qrel->r_विस्थापनम् = rel->r_विस्थापनम्;
                यदि (esym_सूचकांक) {
                    qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_AARCH64_ABS64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    भङ्ग;
                } अन्यथा {
                    qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            प्रत्यागम;
        पक्ष R_AARCH64_ABS32:
            यदि (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_AARCH64_RELATIVE even for a 64bit pointer */
                qrel->r_विस्थापनम् = rel->r_विस्थापनम्;
                qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (पूर्णाङ्क)read32le(ptr) + val;
                qrel++;
            }
            add32le(ptr, val);
            प्रत्यागम;
	पक्ष R_AARCH64_PREL32:
            यदि (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
                यदि (esym_सूचकांक) {
                    qrel->r_विस्थापनम् = rel->r_विस्थापनम्;
                    qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_AARCH64_PREL32);
                    /* Use sign extension! */
                    qrel->r_addend = (पूर्णाङ्क)read32le(ptr) + rel->r_addend;
                    qrel++;
                    भङ्ग;
                }
            }
	    add32le(ptr, val - addr);
	    प्रत्यागम;
        पक्ष R_AARCH64_MOVW_UABS_G0_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val & 0xffff) << 5));
            प्रत्यागम;
        पक्ष R_AARCH64_MOVW_UABS_G1_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 16 & 0xffff) << 5));
            प्रत्यागम;
        पक्ष R_AARCH64_MOVW_UABS_G2_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 32 & 0xffff) << 5));
            प्रत्यागम;
        पक्ष R_AARCH64_MOVW_UABS_G3:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 48 & 0xffff) << 5));
            प्रत्यागम;
        पक्ष R_AARCH64_ADR_PREL_PG_HI21: {
            uint64_t off = (val >> 12) - (addr >> 12);
#यदि_परिभाषितम् TCC_TARGET_PE
            /* Weak undefined symbols resolve to address 0 on PE. ADRP cannot
               encode that from the default 64-bit image base, so materialize
               zero directly and let the paired ADD handle any low addend. */
            यदि ((off + ((uint64_t)1 << 20)) >> 21) {
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
                यदि (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, 0xd2800000 | (read32le(ptr) & 0x1f));
                    प्रत्यागम;
                }
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
            }
#अन्यथा
            यदि ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
#यदि_अन्तः
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            प्रत्यागम;
        }
        पक्ष R_AARCH64_सङ्कलय_ABS_LO12_NC:
        पक्ष R_AARCH64_LDST8_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xfff) << 10));
            प्रत्यागम;
        पक्ष R_AARCH64_LDST16_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffe) << 9));
            प्रत्यागम;
        पक्ष R_AARCH64_LDST32_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffc) << 8));
            प्रत्यागम;
        पक्ष R_AARCH64_LDST64_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff8) << 7));
            प्रत्यागम;
        पक्ष R_AARCH64_LDST128_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff0) << 6));
            प्रत्यागम;
        पक्ष R_AARCH64_CONDBR19:
            /* Conditional branch: 19-bit signed offset, bits 23:5 */
#यदि_परिभाषितम् DEBUG_RELOC
     प्रारूप_लिख ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (वर्ण *) symtab_section->link->दत्त + sym->st_name);
#यदि_अन्तः
            यदि (((val - addr) + ((uint64_t)1 << 20)) & ~(uint64_t)0x1ffffc)
                tcc_error_noabort("R_AARCH64_CONDBR19 relocation failed"
                          " (val=%lx, addr=%lx)", (दीर्घ)val, (दीर्घ)addr);
            write32le(ptr, ((read32le(ptr) & 0xff00001f) |
                            (((val - addr) >> 2 & 0x7ffff) << 5)));
            प्रत्यागम;
        पक्ष R_AARCH64_TSTBR14:
            /* Test and branch: 14-bit signed offset, bits 20:5 */
#यदि_परिभाषितम् DEBUG_RELOC
     प्रारूप_लिख ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (वर्ण *) symtab_section->link->दत्त + sym->st_name);
#यदि_अन्तः
            यदि (((val - addr) + ((uint64_t)1 << 15)) & ~(uint64_t)0xfffc)
                tcc_error_noabort("R_AARCH64_TSTBR14 relocation failed"
                          " (val=%lx, addr=%lx)", (दीर्घ)val, (दीर्घ)addr);
            write32le(ptr, ((read32le(ptr) & 0xfff8001f) |
                            (((val - addr) >> 2 & 0x3fff) << 5)));
            प्रत्यागम;
        पक्ष R_AARCH64_JUMP26:
        पक्ष R_AARCH64_CALL26:
        {
            ध्रुव वर्ण *name;
#यदि_परिभाषितम् DEBUG_RELOC
	    प्रारूप_लिख ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
		    (वर्ण *) symtab_section->link->दत्त + sym->st_name);
#यदि_अन्तः
            यदि (((val - addr) + ((uint64_t)1 << 27)) & ~(uint64_t)0xffffffc) {
#यदि_परिभाषितम् TCC_TARGET_PE
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
                यदि (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, ARM64_NOP); /* nop */
                    प्रत्यागम;
                }
#यदि_अन्तः
                name = (वर्ण *)symtab_section->link->दत्त +
                    ((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक].st_name;
                tcc_error_noabort("R_AARCH64_(JUMP|CALL)26 relocation failed"
                          " for '%s' (val=%lx, addr=%lx)",
                          name, (दीर्घ)val, (दीर्घ)addr);
            }
            write32le(ptr, (0x14000000 |
                            (uint32_t)(type == R_AARCH64_CALL26) << 31 |
                            ((val - addr) >> 2 & 0x3ffffff)));
            प्रत्यागम;
        }
        पक्ष R_AARCH64_ADR_GOT_PAGE: {
            uint64_t off =
                (((s1->got->sh_addr +
                   get_sym_attr(s1, sym_सूचकांक, 0)->got_विस्थापनम्) >> 12) - (addr >> 12));
            यदि ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_GOT_PAGE relocation failed");
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            प्रत्यागम;
        }
        पक्ष R_AARCH64_LD64_GOT_LO12_NC:
            write32le(ptr,
                      ((read32le(ptr) & 0xfff803ff) |
                       ((s1->got->sh_addr +
                         get_sym_attr(s1, sym_सूचकांक, 0)->got_विस्थापनम्) & 0xff8) << 7));
            प्रत्यागम;
        पक्ष R_AARCH64_COPY:
            प्रत्यागम;
        पक्ष R_AARCH64_GLOB_DAT:
        पक्ष R_AARCH64_JUMP_SLOT:
            /* They don't need addend */
#यदि_परिभाषितम् DEBUG_RELOC
	    प्रारूप_लिख ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr,
		    val - rel->r_addend,
		    (वर्ण *) symtab_section->link->दत्त + sym->st_name);
#यदि_अन्तः
            write64le(ptr, val - rel->r_addend);
            प्रत्यागम;
        पक्ष R_AARCH64_TLSLE_सङ्कलय_TPREL_HI12:
        पक्ष R_AARCH64_TLSLE_सङ्कलय_TPREL_LO12: {
#यदि TCC_TARGET_PE
            int64_t tp_विस्थापनम् = val - s1->tls_start;
#अन्यथा
            /* glibc arm64: tp points to tcbhead_t (DTV), TLS data starts after it */
            int64_t tp_विस्थापनम् = val - s1->tls_start + 16;
#यदि_अन्तः
            int64_t imm;
            यदि (type == R_AARCH64_TLSLE_सङ्कलय_TPREL_HI12)
                imm = (tp_विस्थापनम् >> 12) & 0xfff;
            अन्यथा
                imm = tp_विस्थापनम् & 0xfff;
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) | (imm << 10)));
            प्रत्यागम;
        }
        पक्ष R_AARCH64_RELATIVE:
#यदि_परिभाषितम् TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#यदि_अन्तः
            /* do nothing */
            प्रत्यागम;
        स्वभाव:
            fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (अचिह्नित)addr, ptr, (अचिह्नित)val);
            प्रत्यागम;
    }
}

#यदि_अन्तः /* !TARGET_DEFS_ONLY */
