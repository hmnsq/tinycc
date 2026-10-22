#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_RISCV

#define R_DATA_32  R_RISCV_32
#define R_DATA_PTR R_RISCV_64
#define R_JMP_SLOT R_RISCV_JUMP_SLOT
#define R_GLOB_DAT R_RISCV_64
#define R_COPY     R_RISCV_COPY
#define R_RELATIVE R_RISCV_RELATIVE

#define R_अङ्क      R_RISCV_अङ्क

#define ELF_START_ADDR 0x00010000
#define ELF_PAGE_SIZE 0x1000

#define PCRELATIVE_DLLPLT 1
#define RELOCATE_DLLPLT 1

#अन्यथा /* !TARGET_DEFS_ONLY */

//#define DEBUG_RELOC
#अन्तर्भाव "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC पूर्णाङ्क code_reloc (पूर्णाङ्क reloc_type)
{
    विकल्प (reloc_type) {

    पक्ष R_RISCV_BRANCH:
    पक्ष R_RISCV_CALL:
    पक्ष R_RISCV_JAL:
        फर्काऊ 1;

    पक्ष R_RISCV_GOT_HI20:
    पक्ष R_RISCV_PCREL_HI20:
    पक्ष R_RISCV_PCREL_LO12_I:
    पक्ष R_RISCV_PCREL_LO12_S:
    पक्ष R_RISCV_32_PCREL:
    पक्ष R_RISCV_SET6:
    पक्ष R_RISCV_SET8:
    पक्ष R_RISCV_SET16:
    पक्ष R_RISCV_SUB6:
    पक्ष R_RISCV_ADD16:
    पक्ष R_RISCV_ADD32:
    पक्ष R_RISCV_ADD64:
    पक्ष R_RISCV_SUB8:
    पक्ष R_RISCV_SUB16:
    पक्ष R_RISCV_SUB32:
    पक्ष R_RISCV_SUB64:
    पक्ष R_RISCV_32:
    पक्ष R_RISCV_64:
    पक्ष R_RISCV_SET_ULEB128:
    पक्ष R_RISCV_SUB_ULEB128:
    पक्ष R_RISCV_TPREL_HI20:
    पक्ष R_RISCV_TPREL_LO12_I:
        फर्काऊ 0;

    पक्ष R_RISCV_CALL_PLT:
        फर्काऊ 1;
    }
    फर्काऊ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC पूर्णाङ्क gotplt_entry_type (पूर्णाङ्क reloc_type)
{
    विकल्प (reloc_type) {
    पक्ष R_RISCV_ALIGN:
    पक्ष R_RISCV_RELAX:
    पक्ष R_RISCV_RVC_BRANCH:
    पक्ष R_RISCV_RVC_JUMP:
    पक्ष R_RISCV_JUMP_SLOT:
    पक्ष R_RISCV_SET6:
    पक्ष R_RISCV_SET8:
    पक्ष R_RISCV_SET16:
    पक्ष R_RISCV_SUB6:
    पक्ष R_RISCV_ADD16:
    पक्ष R_RISCV_SUB8:
    पक्ष R_RISCV_SUB16:
    पक्ष R_RISCV_SET_ULEB128:
    पक्ष R_RISCV_SUB_ULEB128:
        फर्काऊ NO_GOTPLT_ENTRY;

    पक्ष R_RISCV_BRANCH:
    पक्ष R_RISCV_CALL:
    पक्ष R_RISCV_PCREL_HI20:
    पक्ष R_RISCV_PCREL_LO12_I:
    पक्ष R_RISCV_PCREL_LO12_S:
    पक्ष R_RISCV_32_PCREL:
    पक्ष R_RISCV_ADD32:
    पक्ष R_RISCV_ADD64:
    पक्ष R_RISCV_SUB32:
    पक्ष R_RISCV_SUB64:
    पक्ष R_RISCV_32:
    पक्ष R_RISCV_64:
    पक्ष R_RISCV_JAL:
    पक्ष R_RISCV_CALL_PLT:
        फर्काऊ AUTO_GOTPLT_ENTRY;

    पक्ष R_RISCV_GOT_HI20:
        फर्काऊ ALWAYS_GOTPLT_ENTRY;

    पक्ष R_RISCV_TPREL_HI20:
    पक्ष R_RISCV_TPREL_LO12_I:
        फर्काऊ NO_GOTPLT_ENTRY;
    }
    फर्काऊ -1;
}

ST_FUNC अचिन्हित create_plt_entry(TCCState *s1, अचिन्हित got_offset, संरचना sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    अचिन्हित plt_offset;

    यदि (plt->data_offset == 0)
        section_ptr_add(plt, 32);
    plt_offset = plt->data_offset;

    p = section_ptr_add(plt, 16);
    write64le(p, got_offset);
    फर्काऊ plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC शून्य relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    यदि (!s1->plt)
      फर्काऊ;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    यदि (p < p_end) {
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr;
        uint64_t off = (got - plt + 0x800) >> 12;
        यदि ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (दीर्घ)off, (दीर्घ)got, (दीर्घ)plt);
        write32le(p, 0x397 | (off << 12)); // auipc t2, %pcrel_hi(got)
        write32le(p + 4, 0x41c30333); // sub t1, t1, t3
        write32le(p + 8, 0x0003be03   // ld t3, %pcrel_lo(got)(t2)
                         | (((got - plt) & 0xfff) << 20));
        write32le(p + 12, 0xfd430313); // addi t1, t1, -(32+12)
        write32le(p + 16, 0x00038293   // addi t0, t2, %pcrel_lo(got)
                          | (((got - plt) & 0xfff) << 20));
        write32le(p + 20, 0x00135313); // srli t1, t1, log2(16/PTRSIZE)
        write32le(p + 24, 0x0082b283); // ld t0, PTRSIZE(t0)
        write32le(p + 28, 0x000e0067); // jr t3
        p += 32;
        जबसम्म (p < p_end) {
            uint64_t pc = plt + (p - s1->plt->data);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr - pc + 0x800) >> 12;
            यदि ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (दीर्घ)off, (दीर्घ)addr, (दीर्घ)pc);
            write32le(p, 0xe17 | (off << 12)); // auipc t3, %pcrel_hi(func@got)
            write32le(p + 4, 0x000e3e03 // ld t3, %pcrel_lo(func@got)(t3)
                             | (((addr - pc) & 0xfff) << 20));
            write32le(p + 8, 0x000e0367); // jalr t1, t3
            write32le(p + 12, 0x00000013); // nop
            p += 16;
        }
    }

    यदि (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->data;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_offset, s1->plt->sh_addr);
	}
    }
}

स्थिर शून्य riscv64_record_pcrel_hi(TCCState *s1, addr_t addr, addr_t val)
{
    संरचना pcrel_hi *entry = tcc_malloc(परिमाण *entry);
    entry->addr = addr;
    entry->val = val;
    dynarray_add(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries, entry);
}

स्थिर पूर्णाङ्क riscv64_lookup_pcrel_hi(TCCState *s1, addr_t hi_addr, addr_t *hi_val)
{
    पूर्णाङ्क i;
    लागि (i = s1->nb_pcrel_hi_entries; i > 0; ) {
        संरचना pcrel_hi *entry = s1->pcrel_hi_entries[--i];
        यदि (entry->addr == hi_addr) {
            *hi_val = entry->val;
            फर्काऊ 0;
        }
    }
    फर्काऊ tcc_error_noabort("unsupported hi/lo pcrel reloc scheme");
}

ST_FUNC शून्य relocate(TCCState *s1, ElfW_Rel *rel, पूर्णाङ्क type, अचिन्हित वर्ण *ptr,
              addr_t addr, addr_t val)
{
    uint64_t off64;
    uint32_t off32;
    पूर्णाङ्क sym_index = ELFW(R_SYM)(rel->r_info), esym_index;
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];

    विकल्प(type) {
    पक्ष R_RISCV_ALIGN:
    पक्ष R_RISCV_RELAX:
        फर्काऊ;

    पक्ष R_RISCV_BRANCH:
        off64 = val - addr;
        यदि ((off64 + (1 << 12)) & ~(uint64_t)0x1ffe)
          tcc_error_noabort("R_RISCV_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (दीर्घ)val, (दीर्घ)addr);
        off32 = off64 >> 1;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0x800) << 20)
                       | ((off32 & 0x3f0) << 21)
                       | ((off32 & 0x00f) << 8)
                       | ((off32 & 0x400) >> 3));
        फर्काऊ;
    पक्ष R_RISCV_JAL:
        off64 = val - addr;
        यदि ((off64 + (1 << 21)) & ~(((uint64_t)1 << 22) - 2))
          tcc_error_noabort("R_RISCV_JAL relocation failed"
                    " (val=%lx, addr=%lx)", (दीर्घ)val, (दीर्घ)addr);
        off32 = off64;
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | (((off32 >> 12) &  0xff) << 12)
                       | (((off32 >> 11) &     1) << 20)
                       | (((off32 >>  1) & 0x3ff) << 21)
                       | (((off32 >> 20) &     1) << 31));
        फर्काऊ;
    पक्ष R_RISCV_CALL:
    पक्ष R_RISCV_CALL_PLT:
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((val - addr + 0x800) & ~0xfff));
        write32le(ptr + 4, (read32le(ptr + 4) & 0xfffff)
                           | (((val - addr) & 0xfff) << 20));
        फर्काऊ;
    पक्ष R_RISCV_PCREL_HI20:
#ifdef DEBUG_RELOC
        म_लिखो("PCREL_HI20: val=%lx addr=%lx\n", (दीर्घ)val, (दीर्घ)addr);
#endif
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        यदि ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_PCREL_HI20 relocation failed: off=%lx cond=%lx sym=%s",
                    (दीर्घ)off64, (दीर्घ)((int64_t)(off64 + ((uint64_t)1 << 20)) >> 21),
                    symtab_section->link->data + sym->st_name);
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_record_pcrel_hi(s1, addr, val);
        फर्काऊ;
    पक्ष R_RISCV_GOT_HI20:
        val = s1->got->sh_addr + get_sym_attr(s1, sym_index, 0)->got_offset;
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        यदि ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_GOT_HI20 relocation failed");
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_record_pcrel_hi(s1, addr, val);
        फर्काऊ;
    पक्ष R_RISCV_PCREL_LO12_I:
#ifdef DEBUG_RELOC
        म_लिखो("PCREL_LO12_I: val=%lx addr=%lx\n", (दीर्घ)val, (दीर्घ)addr);
#endif
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        write32le(ptr, (read32le(ptr) & 0xfffff)
                       | (((val - addr) & 0xfff) << 20));
        फर्काऊ;
    पक्ष R_RISCV_PCREL_LO12_S:
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        off32 = val - addr;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0xfe0) << 20)
                       | ((off32 & 0x01f) << 7));
        फर्काऊ;

    पक्ष R_RISCV_RVC_BRANCH:
        off64 = (val - addr);
        यदि ((off64 + (1 << 8)) & ~(uint64_t)0x1fe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (दीर्घ)val, (दीर्घ)addr);
        off32 = off64;
        write16le(ptr, (read16le(ptr) & 0xe383)
                       | (((off32 >> 5) & 1) << 2)
                       | (((off32 >> 1) & 3) << 3)
                       | (((off32 >> 6) & 3) << 5)
                       | (((off32 >> 3) & 3) << 10)
                       | (((off32 >> 8) & 1) << 12));
        फर्काऊ;
    पक्ष R_RISCV_RVC_JUMP:
        off64 = (val - addr);
        यदि ((off64 + (1 << 11)) & ~(uint64_t)0xffe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (दीर्घ)val, (दीर्घ)addr);
        off32 = off64;
        write16le(ptr, (read16le(ptr) & 0xe003)
                       | (((off32 >>  5) & 1) << 2)
                       | (((off32 >>  1) & 7) << 3)
                       | (((off32 >>  7) & 1) << 6)
                       | (((off32 >>  6) & 1) << 7)
                       | (((off32 >> 10) & 1) << 8)
                       | (((off32 >>  8) & 3) << 9)
                       | (((off32 >>  4) & 1) << 11)
                       | (((off32 >> 11) & 1) << 12));
        फर्काऊ;

    पक्ष R_RISCV_32:
        यदि (s1->output_type & TCC_OUTPUT_DYN) {
            /* XXX: this logic may depend on TCC's codegen
               now TCC uses R_RISCV_RELATIVE even for a 64bit pointer */
            qrel->r_offset = rel->r_offset;
            qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
            /* Use sign extension! */
            qrel->r_addend = (पूर्णाङ्क)read32le(ptr) + val;
            qrel++;
        }
        add32le(ptr, val);
        फर्काऊ;
    पक्ष R_RISCV_64:
        यदि (s1->output_type & TCC_OUTPUT_DYN) {
            esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
            qrel->r_offset = rel->r_offset;
            यदि (esym_index) {
                qrel->r_info = ELFW(R_INFO)(esym_index, R_RISCV_64);
                qrel->r_addend = rel->r_addend;
                qrel++;
                रोक;
            } अन्यथा {
                qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
                qrel->r_addend = read64le(ptr) + val;
                qrel++;
            }
        }
    पक्ष R_RISCV_JUMP_SLOT:
        add64le(ptr, val);
        फर्काऊ;
    पक्ष R_RISCV_ADD64:
        write64le(ptr, read64le(ptr) + val);
        फर्काऊ;
    पक्ष R_RISCV_ADD32:
        write32le(ptr, read32le(ptr) + val);
        फर्काऊ;
    पक्ष R_RISCV_SUB64:
        write64le(ptr, read64le(ptr) - val);
        फर्काऊ;
    पक्ष R_RISCV_SUB32:
        write32le(ptr, read32le(ptr) - val);
        फर्काऊ;
    पक्ष R_RISCV_ADD16:
        write16le(ptr, read16le(ptr) + val);
        फर्काऊ;
    पक्ष R_RISCV_SUB8:
        *ptr -= val;
        फर्काऊ;
    पक्ष R_RISCV_SUB16:
        write16le(ptr, read16le(ptr) - val);
        फर्काऊ;
    पक्ष R_RISCV_SET6:
        *ptr = (*ptr & ~0x3f) | (val & 0x3f);
        फर्काऊ;
    पक्ष R_RISCV_SET8:
        *ptr = (*ptr & ~0xff) | (val & 0xff);
        फर्काऊ;
    पक्ष R_RISCV_SET16:
        write16le(ptr, val);
        फर्काऊ;
    पक्ष R_RISCV_SUB6:
        *ptr = (*ptr & ~0x3f) | ((*ptr - val) & 0x3f);
        फर्काऊ;
    पक्ष R_RISCV_32_PCREL:
        यदि (s1->output_type & TCC_OUTPUT_DYN) {
	    /* DLL relocation */
	    esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
	    यदि (esym_index) {
                qrel->r_offset = rel->r_offset;
                qrel->r_info = ELFW(R_INFO)(esym_index, R_RISCV_32_PCREL);
                /* Use sign extension! */
                qrel->r_addend = (पूर्णाङ्क)read32le(ptr) + rel->r_addend;
                qrel++;
		रोक;
	    }
        }
	add32le(ptr, val - addr);
        फर्काऊ;
    पक्ष R_RISCV_SET_ULEB128:
    पक्ष R_RISCV_SUB_ULEB128:
	/* ignore. used in section .debug_loclists */
        फर्काऊ;
    पक्ष R_RISCV_COPY:
        /* XXX */
        फर्काऊ;
    पक्ष R_RISCV_RELATIVE:
        /* R_RISCV_RELATIVE value is already applied in R_RISCV_32/64
           dynamic output paths, but we need this case for incoming
           RELATIVE relocations from object files. */
        फर्काऊ;

    पक्ष R_RISCV_TPREL_HI20:
    पक्ष R_RISCV_TPREL_LO12_I: {
        int64_t tp_offset = val - s1->tls_start;
        यदि (type == R_RISCV_TPREL_HI20) {
            off64 = (int64_t)(tp_offset + 0x800) >> 12;
            यदि ((off64 + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_RISCV_TPREL_HI20 relocation failed");
            write32le(ptr, (read32le(ptr) & 0xfff)
                           | ((off64 & 0xfffff) << 12));
        } अन्यथा {
            write32le(ptr, (read32le(ptr) & 0xfffff)
                           | (((tp_offset) & 0xfff) << 20));
        }
        फर्काऊ;
    }

    स्वभाव:
        ख_लिखो(मानक_त्रुटि, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                type, (अचिन्हित)addr, ptr, (अचिन्हित)val);
        फर्काऊ;
    }
}
#endif
