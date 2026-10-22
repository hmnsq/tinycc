#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_AARCH64

#define R_DATA_32  R_AARCH64_ABS32
#define R_DATA_PTR R_AARCH64_ABS64
#define R_JMP_SLOT R_AARCH64_JUMP_SLOT
#define R_GLOB_DAT R_AARCH64_GLOB_DAT
#define R_COPY     R_AARCH64_COPY
#define R_RELATIVE R_AARCH64_RELATIVE

#define R_অঙ্ক      R_AARCH64_অঙ্ক

#define ELF_START_ADDR 0x00400000
#define ELF_PAGE_SIZE 0x10000

#define PCRELATIVE_DLLPLT 1
#define RELOCATE_DLLPLT 1

#অন্যথা /* !TARGET_DEFS_ONLY */

#অন্তর্ভাব "tcc.h"

#ifdef NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC পূর্ণাঙ্ক code_reloc (পূর্ণাঙ্ক reloc_type)
{
    বিকল্প (reloc_type) {
        পক্ষ R_AARCH64_ABS32:
        পক্ষ R_AARCH64_ABS64:
	পক্ষ R_AARCH64_PREL32:
        পক্ষ R_AARCH64_MOVW_UABS_G0_NC:
        পক্ষ R_AARCH64_MOVW_UABS_G1_NC:
        পক্ষ R_AARCH64_MOVW_UABS_G2_NC:
        পক্ষ R_AARCH64_MOVW_UABS_G3:
        পক্ষ R_AARCH64_ADR_PREL_PG_HI21:
        পক্ষ R_AARCH64_ADD_ABS_LO12_NC:
        পক্ষ R_AARCH64_ADR_GOT_PAGE:
        পক্ষ R_AARCH64_LD64_GOT_LO12_NC:
        পক্ষ R_AARCH64_LDST128_ABS_LO12_NC:
        পক্ষ R_AARCH64_LDST64_ABS_LO12_NC:
        পক্ষ R_AARCH64_LDST32_ABS_LO12_NC:
        পক্ষ R_AARCH64_LDST16_ABS_LO12_NC:
        পক্ষ R_AARCH64_LDST8_ABS_LO12_NC:
        পক্ষ R_AARCH64_TLSLE_ADD_TPREL_HI12:
        পক্ষ R_AARCH64_TLSLE_ADD_TPREL_LO12:
        পক্ষ R_AARCH64_GLOB_DAT:
        পক্ষ R_AARCH64_COPY:
            প্রত্যাগম 0;

        পক্ষ R_AARCH64_JUMP26:
        পক্ষ R_AARCH64_CALL26:
        পক্ষ R_AARCH64_JUMP_SLOT:
        পক্ষ R_AARCH64_CONDBR19:
        পক্ষ R_AARCH64_TSTBR14:
            প্রত্যাগম 1;
    }
    প্রত্যাগম -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC পূর্ণাঙ্ক gotplt_entry_type (পূর্ণাঙ্ক reloc_type)
{
    বিকল্প (reloc_type) {
	পক্ষ R_AARCH64_PREL32:
        পক্ষ R_AARCH64_MOVW_UABS_G0_NC:
        পক্ষ R_AARCH64_MOVW_UABS_G1_NC:
        পক্ষ R_AARCH64_MOVW_UABS_G2_NC:
        পক্ষ R_AARCH64_MOVW_UABS_G3:
        পক্ষ R_AARCH64_ADR_PREL_PG_HI21:
        পক্ষ R_AARCH64_ADD_ABS_LO12_NC:
        পক্ষ R_AARCH64_LDST128_ABS_LO12_NC:
        পক্ষ R_AARCH64_LDST64_ABS_LO12_NC:
        পক্ষ R_AARCH64_LDST32_ABS_LO12_NC:
        পক্ষ R_AARCH64_LDST16_ABS_LO12_NC:
        পক্ষ R_AARCH64_LDST8_ABS_LO12_NC:
        পক্ষ R_AARCH64_GLOB_DAT:
        পক্ষ R_AARCH64_JUMP_SLOT:
        পক্ষ R_AARCH64_COPY:
        পক্ষ R_AARCH64_CONDBR19:
        পক্ষ R_AARCH64_TSTBR14:
        পক্ষ R_AARCH64_TLSLE_ADD_TPREL_HI12:
        পক্ষ R_AARCH64_TLSLE_ADD_TPREL_LO12:
            প্রত্যাগম NO_GOTPLT_ENTRY;

        পক্ষ R_AARCH64_ABS32:
        পক্ষ R_AARCH64_ABS64:
        পক্ষ R_AARCH64_JUMP26:
        পক্ষ R_AARCH64_CALL26:
            প্রত্যাগম AUTO_GOTPLT_ENTRY;

        পক্ষ R_AARCH64_ADR_GOT_PAGE:
        পক্ষ R_AARCH64_LD64_GOT_LO12_NC:
            প্রত্যাগম ALWAYS_GOTPLT_ENTRY;
    }
    প্রত্যাগম -1;
}

#ifdef NEED_BUILD_GOT
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, সংরচনা sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    unsigned plt_offset;

    যদি (plt->data_offset == 0) {
        section_ptr_add(plt, 32);
    }
    plt_offset = plt->data_offset;

    p = section_ptr_add(plt, 16);
    write32le(p, got_offset);
    write32le(p + 4, (uint64_t) got_offset >> 32);
    প্রত্যাগম plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC শূন্য relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    যদি (!s1->plt)
      প্রত্যাগম;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    যদি (p < p_end) {
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr + 16;
        uint64_t off = (got >> 12) - (plt >> 12);
        যদি ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (long)off, (long)got, (long)plt);
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
        যাবত্ (p < p_end) {
            uint64_t pc = plt + (p - s1->plt->data);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr >> 12) - (pc >> 12);
            যদি ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (long)off, (long)addr, (long)pc);
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

    যদি (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->data;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_offset, s1->plt->sh_addr);
	}
    }
}
#endif
#endif

ST_FUNC শূন্য relocate(TCCState *s1, ElfW_Rel *rel, পূর্ণাঙ্ক type, unsigned বর্ণ *ptr, addr_t addr, addr_t val)
{
    পূর্ণাঙ্ক sym_index = ELFW(R_SYM)(rel->r_info), esym_index;
#ifdef DEBUG_RELOC
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
#endif

    বিকল্প(type) {
        পক্ষ R_AARCH64_ABS64:
            যদি ((s1->output_type & TCC_OUTPUT_DYN)) {
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                qrel->r_offset = rel->r_offset;
                যদি (esym_index) {
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_AARCH64_ABS64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    ভঙ্গ;
                } অন্যথা {
                    qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            প্রত্যাগম;
        পক্ষ R_AARCH64_ABS32:
            যদি (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_AARCH64_RELATIVE even for a 64bit pointer */
                qrel->r_offset = rel->r_offset;
                qrel->r_info = ELFW(R_INFO)(0, R_AARCH64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (পূর্ণাঙ্ক)read32le(ptr) + val;
                qrel++;
            }
            add32le(ptr, val);
            প্রত্যাগম;
	পক্ষ R_AARCH64_PREL32:
            যদি (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                যদি (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_AARCH64_PREL32);
                    /* Use sign extension! */
                    qrel->r_addend = (পূর্ণাঙ্ক)read32le(ptr) + rel->r_addend;
                    qrel++;
                    ভঙ্গ;
                }
            }
	    add32le(ptr, val - addr);
	    প্রত্যাগম;
        পক্ষ R_AARCH64_MOVW_UABS_G0_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val & 0xffff) << 5));
            প্রত্যাগম;
        পক্ষ R_AARCH64_MOVW_UABS_G1_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 16 & 0xffff) << 5));
            প্রত্যাগম;
        পক্ষ R_AARCH64_MOVW_UABS_G2_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 32 & 0xffff) << 5));
            প্রত্যাগম;
        পক্ষ R_AARCH64_MOVW_UABS_G3:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 48 & 0xffff) << 5));
            প্রত্যাগম;
        পক্ষ R_AARCH64_ADR_PREL_PG_HI21: {
            uint64_t off = (val >> 12) - (addr >> 12);
#ifdef TCC_TARGET_PE
            /* Weak undefined symbols resolve to address 0 on PE. ADRP cannot
               encode that from the default 64-bit image base, so materialize
               zero directly and let the paired ADD handle any low addend. */
            যদি ((off + ((uint64_t)1 << 20)) >> 21) {
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                যদি (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, 0xd2800000 | (read32le(ptr) & 0x1f));
                    প্রত্যাগম;
                }
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
            }
#অন্যথা
            যদি ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
#endif
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            প্রত্যাগম;
        }
        পক্ষ R_AARCH64_ADD_ABS_LO12_NC:
        পক্ষ R_AARCH64_LDST8_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xfff) << 10));
            প্রত্যাগম;
        পক্ষ R_AARCH64_LDST16_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffe) << 9));
            প্রত্যাগম;
        পক্ষ R_AARCH64_LDST32_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xffc) << 8));
            প্রত্যাগম;
        পক্ষ R_AARCH64_LDST64_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff8) << 7));
            প্রত্যাগম;
        পক্ষ R_AARCH64_LDST128_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xff0) << 6));
            প্রত্যাগম;
        পক্ষ R_AARCH64_CONDBR19:
            /* Conditional branch: 19-bit signed offset, bits 23:5 */
#ifdef DEBUG_RELOC
     printf ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (বর্ণ *) symtab_section->link->data + sym->st_name);
#endif
            যদি (((val - addr) + ((uint64_t)1 << 20)) & ~(uint64_t)0x1ffffc)
                tcc_error_noabort("R_AARCH64_CONDBR19 relocation failed"
                          " (val=%lx, addr=%lx)", (long)val, (long)addr);
            write32le(ptr, ((read32le(ptr) & 0xff00001f) |
                            (((val - addr) >> 2 & 0x7ffff) << 5)));
            প্রত্যাগম;
        পক্ষ R_AARCH64_TSTBR14:
            /* Test and branch: 14-bit signed offset, bits 20:5 */
#ifdef DEBUG_RELOC
     printf ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
      (বর্ণ *) symtab_section->link->data + sym->st_name);
#endif
            যদি (((val - addr) + ((uint64_t)1 << 15)) & ~(uint64_t)0xfffc)
                tcc_error_noabort("R_AARCH64_TSTBR14 relocation failed"
                          " (val=%lx, addr=%lx)", (long)val, (long)addr);
            write32le(ptr, ((read32le(ptr) & 0xfff8001f) |
                            (((val - addr) >> 2 & 0x3fff) << 5)));
            প্রত্যাগম;
        পক্ষ R_AARCH64_JUMP26:
        পক্ষ R_AARCH64_CALL26:
        {
            ধ্রুব বর্ণ *name;
#ifdef DEBUG_RELOC
	    printf ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
		    (বর্ণ *) symtab_section->link->data + sym->st_name);
#endif
            যদি (((val - addr) + ((uint64_t)1 << 27)) & ~(uint64_t)0xffffffc) {
#ifdef TCC_TARGET_PE
                ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                যদি (sym->st_shndx == SHN_UNDEF
                    && ELFW(ST_BIND)(sym->st_info) == STB_WEAK) {
                    write32le(ptr, ARM64_NOP); /* nop */
                    প্রত্যাগম;
                }
#endif
                name = (বর্ণ *)symtab_section->link->data +
                    ((ElfW(Sym) *)symtab_section->data)[sym_index].st_name;
                tcc_error_noabort("R_AARCH64_(JUMP|CALL)26 relocation failed"
                          " for '%s' (val=%lx, addr=%lx)",
                          name, (long)val, (long)addr);
            }
            write32le(ptr, (0x14000000 |
                            (uint32_t)(type == R_AARCH64_CALL26) << 31 |
                            ((val - addr) >> 2 & 0x3ffffff)));
            প্রত্যাগম;
        }
        পক্ষ R_AARCH64_ADR_GOT_PAGE: {
            uint64_t off =
                (((s1->got->sh_addr +
                   get_sym_attr(s1, sym_index, 0)->got_offset) >> 12) - (addr >> 12));
            যদি ((off + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_AARCH64_ADR_GOT_PAGE relocation failed");
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            প্রত্যাগম;
        }
        পক্ষ R_AARCH64_LD64_GOT_LO12_NC:
            write32le(ptr,
                      ((read32le(ptr) & 0xfff803ff) |
                       ((s1->got->sh_addr +
                         get_sym_attr(s1, sym_index, 0)->got_offset) & 0xff8) << 7));
            প্রত্যাগম;
        পক্ষ R_AARCH64_COPY:
            প্রত্যাগম;
        পক্ষ R_AARCH64_GLOB_DAT:
        পক্ষ R_AARCH64_JUMP_SLOT:
            /* They don't need addend */
#ifdef DEBUG_RELOC
	    printf ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr,
		    val - rel->r_addend,
		    (বর্ণ *) symtab_section->link->data + sym->st_name);
#endif
            write64le(ptr, val - rel->r_addend);
            প্রত্যাগম;
        পক্ষ R_AARCH64_TLSLE_ADD_TPREL_HI12:
        পক্ষ R_AARCH64_TLSLE_ADD_TPREL_LO12: {
#যদি TCC_TARGET_PE
            int64_t tp_offset = val - s1->tls_start;
#অন্যথা
            /* glibc arm64: tp points to tcbhead_t (DTV), TLS data starts after it */
            int64_t tp_offset = val - s1->tls_start + 16;
#endif
            int64_t imm;
            যদি (type == R_AARCH64_TLSLE_ADD_TPREL_HI12)
                imm = (tp_offset >> 12) & 0xfff;
            অন্যথা
                imm = tp_offset & 0xfff;
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) | (imm << 10)));
            প্রত্যাগম;
        }
        পক্ষ R_AARCH64_RELATIVE:
#ifdef TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            প্রত্যাগম;
        স্বভাব:
            fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (unsigned)addr, ptr, (unsigned)val);
            প্রত্যাগম;
    }
}

#endif /* !TARGET_DEFS_ONLY */
