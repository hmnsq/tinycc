#अगर_घोषित TARGET_DEFS_ONLY

#घोषणा EM_TCC_TARGET EM_AARCH64

#घोषणा R_तथ्य_32  R_AARCH64_ABS32
#घोषणा R_तथ्य_PTR R_AARCH64_ABS64
#घोषणा R_JMP_SLOT R_AARCH64_JUMP_SLOT
#घोषणा R_GLOB_DAT R_AARCH64_GLOB_DAT
#घोषणा R_COPY     R_AARCH64_COPY
#घोषणा R_RELATIVE R_AARCH64_RELATIVE

#घोषणा R_अंक      R_AARCH64_अंक

#घोषणा ELF_START_ADDR 0x00400000
#घोषणा ELF_PAGE_आकार 0x10000

#घोषणा PCRELATIVE_DLLPLT 1
#घोषणा RELOCATE_DLLPLT 1

#अन्यथा /* !TARGET_DEFS_ONLY */

#समावेश "tcc.h"

#अगर_घोषित NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC पूर्णांक code_reloc (पूर्णांक reloc_type)
{
    चयन (reloc_type) {
        हाल R_AARCH64_ABS32:
        हाल R_AARCH64_ABS64:
	हाल R_AARCH64_PREL32:
        हाल R_AARCH64_MOVW_UABS_G0_NC:
        हाल R_AARCH64_MOVW_UABS_G1_NC:
        हाल R_AARCH64_MOVW_UABS_G2_NC:
        हाल R_AARCH64_MOVW_UABS_G3:
        हाल R_AARCH64_ADR_PREL_PG_HI21:
        हाल R_AARCH64_ADD_ABS_LO12_NC:
        हाल R_AARCH64_ADR_GOT_PAGE:
        हाल R_AARCH64_LD64_GOT_LO12_NC:
        हाल R_AARCH64_LDST128_ABS_LO12_NC:
        हाल R_AARCH64_LDST64_ABS_LO12_NC:
        हाल R_AARCH64_LDST32_ABS_LO12_NC:
        हाल R_AARCH64_LDST16_ABS_LO12_NC:
        हाल R_AARCH64_LDST8_ABS_LO12_NC:
        हाल R_AARCH64_TLSLE_ADD_TPREL_HI12:
        हाल R_AARCH64_TLSLE_ADD_TPREL_LO12:
        हाल R_AARCH64_GLOB_DAT:
        हाल R_AARCH64_COPY:
            वापस 0;

        हाल R_AARCH64_JUMP26:
        हाल R_AARCH64_CALL26:
        हाल R_AARCH64_JUMP_SLOT:
        हाल R_AARCH64_CONDBR19:
        हाल R_AARCH64_TSTBR14:
            वापस 1;
    }
    वापस -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC पूर्णांक gotplt_entry_type (पूर्णांक reloc_type)
{
    चयन (reloc_type) {
	हाल R_AARCH64_PREL32:
        हाल R_AARCH64_MOVW_UABS_G0_NC:
        हाल R_AARCH64_MOVW_UABS_G1_NC:
        हाल R_AARCH64_MOVW_UABS_G2_NC:
        हाल R_AARCH64_MOVW_UABS_G3:
        हाल R_AARCH64_ADR_PREL_PG_HI21:
        हाल R_AARCH64_ADD_ABS_LO12_NC:
        हाल R_AARCH64_LDST128_ABS_LO12_NC:
        हाल R_AARCH64_LDST64_ABS_LO12_NC:
        हाल R_AARCH64_LDST32_ABS_LO12_NC:
        हाल R_AARCH64_LDST16_ABS_LO12_NC:
        हाल R_AARCH64_LDST8_ABS_LO12_NC:
        हाल R_AARCH64_GLOB_DAT:
        हाल R_AARCH64_JUMP_SLOT:
        हाल R_AARCH64_COPY:
        हाल R_AARCH64_CONDBR19:
        हाल R_AARCH64_TSTBR14:
        हाल R_AARCH64_TLSLE_ADD_TPREL_HI12:
        हाल R_AARCH64_TLSLE_ADD_TPREL_LO12:
            वापस NO_GOTPLT_ENTRY;

        हाल R_AARCH64_ABS32:
        हाल R_AARCH64_ABS64:
        हाल R_AARCH64_JUMP26:
        हाल R_AARCH64_CALL26:
            वापस AUTO_GOTPLT_ENTRY;

        हाल R_AARCH64_ADR_GOT_PAGE:
        हाल R_AARCH64_LD64_GOT_LO12_NC:
            वापस ALWAYS_GOTPLT_ENTRY;
    }
    वापस -1;
}

#अगर_घोषित NEED_BUILD_GOT
ST_FUNC अचिन्हित create_plt_entry(TCCState *s1, अचिन्हित got_offset, काष्ठा sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    अचिन्हित plt_offset;

    अगर (plt->तथ्य_offset == 0) {
        section_ptr_add(plt, 32);
    }
    plt_offset = plt->तथ्य_offset;

    p = section_ptr_add(plt, 16);
    write32le(p, got_offset);
    write32le(p + 4, (uint64_t) got_offset >> 32);
    वापस plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC व्योम relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    अगर (!s1->plt)
      वापस;

    p = s1->plt->तथ्य;
    p_end = p + s1->plt->तथ्य_offset;

    अगर (p < p_end) {
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr + 16;
        uint64_t off = (got >> 12) - (plt >> 12);
        अगर ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (दीर्घ)off, (दीर्घ)got, (दीर्घ)plt);
        write32le(p, ARM64_STP_X_PRE | ARM64_RT(16) | ARM64_RT2(30) |
                      ARM64_RN(31) | ARM64_IMM7(-2)); // stp x16,x30,[sp,#-16]!
        write32le(p + 4, (ARM64_ADRP | ARM64_RD(16) | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
        write32le(p + 8, (ARM64_LDR_X | ARM64_RT(17) | ARM64_RN(16) | // ldr x17,[x16,#...]
			  (got & 0xff8) << 7));
        write32le(p + 12, (ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RD(16) | ARM64_RN(16) | // add x16,x16,#...
			   (got & 0xfff) << 10));
        write32le(p + 16, ARM64_BR | ARM64_RN(17)); // br x17
        write32le(p + 20, ARM64_NOP); // nop
        write32le(p + 24, ARM64_NOP); // nop
        write32le(p + 28, ARM64_NOP); // nop
        p += 32;
	got = s1->got->sh_addr;
        जबतक (p < p_end) {
            uint64_t pc = plt + (p - s1->plt->तथ्य);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr >> 12) - (pc >> 12);
            अगर ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (दीर्घ)off, (दीर्घ)addr, (दीर्घ)pc);
            write32le(p, (ARM64_ADRP | ARM64_RD(16) | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
            write32le(p + 4, (ARM64_LDR_X | ARM64_RT(17) | ARM64_RN(16) | // ldr x17,[x16,#...]
			      (addr & 0xff8) << 7));
            write32le(p + 8, (ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RD(16) | ARM64_RN(16) | // add x16,x16,#...
			      (addr & 0xfff) << 10));
            write32le(p + 12, ARM64_BR | ARM64_RN(17)); // br x17
            p += 16;
        }
    }

    अगर (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->तथ्य;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_offset, s1->plt->sh_addr);
	}
    }
}
#पूर्ण_अगर
#पूर्ण_अगर

ST_FUNC व्योम relocate(TCCState *s1, ElfW_Rel *rel, पूर्णांक type, अचिन्हित अक्षर *ptr, addr_t addr, addr_t val)
{
    पूर्णांक sym_सूचकांक = ELFW(R_SYM)(rel->r_info), esym_सूचकांक;
#अगर_घोषित DEBUG_RELOC
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
#पूर्ण_अगर

    चयन(type) {
        हाल R_AARCH64_ABS64:
            अगर ((s1->output_type & TCC_OUTPUT_DYN)) {
                esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
                qrel->r_offset = rel->r_offset;
                अगर (esym_सूचकांक) {
                    qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_AARCH64_ABS64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    अवरोध;
                } अन्यथा {
                    qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            वापस;
        हाल R_AARCH64_ABS32:
            अगर (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_AARCH64_RELATIVE even for a 64bit pointer */
                qrel->r_offset = rel->r_offset;
                qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (पूर्णांक)read32le(ptr) + val;
                qrel++;
            }
            add32le(ptr, val);
            वापस;
	हाल R_AARCH64_PREL32:
            अगर (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
                अगर (esym_सूचकांक) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_AARCH64_PREL32);
                    /* Use sign extension! */
                    qrel->r_addend = (पूर्णांक)read32le(ptr) + rel->r_addend;
                    qrel++;
                    अवरोध;
                }
            }
	    add32le(ptr, val - addr);
	    वापस;
        हाल R_AARCH64_MOVW_UABS_G0_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val & 0xffff) << 5));
            वापस;
        हाल R_AARCH64_MOVW_UABS_G1_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 16 & 0xffff) << 5));
            वापस;
        हाल R_AARCH64_MOVW_UABS_G2_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 32 & 0xffff) << 5));
            वापस;
        हाल R_AARCH64_MOVW_UABS_G3:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 48 & 0xffff) << 5));
            वापस;
        हाल R_AARCH64_ADR_PREL_PG_HI21: {
            uint64_t off = (val >> 12) - (addr >> 12);
#अगर_घोषित TCC_TARGET_PE
            /* Weak undefined symbols resolve to address 0 on PE. ADRP cannot
               encode that from the default 64-bit image base, so materialize
               zero directly and let the paired ADD handle any low addend. */
            अगर ((off + ((uint64_t)1 << 20)) >> 21) {
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
                अगर (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, 0xd2800000 | (read32le(ptr) & 0x1f));
                    वापस;
                }
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
            }
#अन्यथा
            अगर ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
#पूर्ण_अगर
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            वापस;
        }
        हाल R_AARCH64_ADD_ABS_LO12_NC:
        हाल R_AARCH64_LDST8_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xfff) << 10));
            वापस;
        हाल R_AARCH64_LDST16_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffe) << 9));
            वापस;
        हाल R_AARCH64_LDST32_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffc) << 8));
            वापस;
        हाल R_AARCH64_LDST64_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff8) << 7));
            वापस;
        हाल R_AARCH64_LDST128_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff0) << 6));
            वापस;
        हाल R_AARCH64_CONDBR19:
            /* Conditional branch: 19-bit signed offset, bits 23:5 */
#अगर_घोषित DEBUG_RELOC
     म_लिखो ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (अक्षर *) symtab_section->link->तथ्य + sym->st_name);
#पूर्ण_अगर
            अगर (((val - addr) + ((uint64_t)1 << 20)) & ~(uint64_t)0x1ffffc)
                tcc_error_noabort("R_AARCH64_CONDBR19 relocation failed"
                          " (val=%lx, addr=%lx)", (दीर्घ)val, (दीर्घ)addr);
            write32le(ptr, ((read32le(ptr) & 0xff00001f) |
                            (((val - addr) >> 2 & 0x7ffff) << 5)));
            वापस;
        हाल R_AARCH64_TSTBR14:
            /* Test and branch: 14-bit signed offset, bits 20:5 */
#अगर_घोषित DEBUG_RELOC
     म_लिखो ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (अक्षर *) symtab_section->link->तथ्य + sym->st_name);
#पूर्ण_अगर
            अगर (((val - addr) + ((uint64_t)1 << 15)) & ~(uint64_t)0xfffc)
                tcc_error_noabort("R_AARCH64_TSTBR14 relocation failed"
                          " (val=%lx, addr=%lx)", (दीर्घ)val, (दीर्घ)addr);
            write32le(ptr, ((read32le(ptr) & 0xfff8001f) |
                            (((val - addr) >> 2 & 0x3fff) << 5)));
            वापस;
        हाल R_AARCH64_JUMP26:
        हाल R_AARCH64_CALL26:
        {
            स्थिर अक्षर *name;
#अगर_घोषित DEBUG_RELOC
	    म_लिखो ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
		    (अक्षर *) symtab_section->link->तथ्य + sym->st_name);
#पूर्ण_अगर
            अगर (((val - addr) + ((uint64_t)1 << 27)) & ~(uint64_t)0xffffffc) {
#अगर_घोषित TCC_TARGET_PE
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
                अगर (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, ARM64_NOP); /* nop */
                    वापस;
                }
#पूर्ण_अगर
                name = (अक्षर *)symtab_section->link->तथ्य +
                    ((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक].st_name;
                tcc_error_noabort("R_AARCH64_(JUMP|CALL)26 relocation failed"
                          " for '%s' (val=%lx, addr=%lx)",
                          name, (दीर्घ)val, (दीर्घ)addr);
            }
            write32le(ptr, (0x14000000 |
                            (uint32_t)(type == R_AARCH64_CALL26) << 31 |
                            ((val - addr) >> 2 & 0x3ffffff)));
            वापस;
        }
        हाल R_AARCH64_ADR_GOT_PAGE: {
            uint64_t off =
                (((s1->got->sh_addr +
                   get_sym_attr(s1, sym_सूचकांक, 0)->got_offset) >> 12) - (addr >> 12));
            अगर ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_GOT_PAGE relocation failed");
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            वापस;
        }
        हाल R_AARCH64_LD64_GOT_LO12_NC:
            write32le(ptr,
                      ((read32le(ptr) & 0xfff803ff) |
                       ((s1->got->sh_addr +
                         get_sym_attr(s1, sym_सूचकांक, 0)->got_offset) & 0xff8) << 7));
            वापस;
        हाल R_AARCH64_COPY:
            वापस;
        हाल R_AARCH64_GLOB_DAT:
        हाल R_AARCH64_JUMP_SLOT:
            /* They don't need addend */
#अगर_घोषित DEBUG_RELOC
	    म_लिखो ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr,
		    val - rel->r_addend,
		    (अक्षर *) symtab_section->link->तथ्य + sym->st_name);
#पूर्ण_अगर
            write64le(ptr, val - rel->r_addend);
            वापस;
        हाल R_AARCH64_TLSLE_ADD_TPREL_HI12:
        हाल R_AARCH64_TLSLE_ADD_TPREL_LO12: {
#अगर TCC_TARGET_PE
            int64_t tp_offset = val - s1->tls_start;
#अन्यथा
            /* glibc arm64: tp points to tcbhead_t (DTV), TLS data starts after it */
            int64_t tp_offset = val - s1->tls_start + 16;
#पूर्ण_अगर
            int64_t imm;
            अगर (type == R_AARCH64_TLSLE_ADD_TPREL_HI12)
                imm = (tp_offset >> 12) & 0xfff;
            अन्यथा
                imm = tp_offset & 0xfff;
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) | (imm << 10)));
            वापस;
        }
        हाल R_AARCH64_RELATIVE:
#अगर_घोषित TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#पूर्ण_अगर
            /* do nothing */
            वापस;
        शेष:
            ख_लिखो(मानक_त्रुटि, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (अचिन्हित)addr, ptr, (अचिन्हित)val);
            वापस;
    }
}

#पूर्ण_अगर /* !TARGET_DEFS_ONLY */
