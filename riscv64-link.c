#अगर_घोषित TARGET_DEFS_ONLY

#घोषणा EM_TCC_TARGET EM_RISCV

#घोषणा R_तथ्य_32  R_RISCV_32
#घोषणा R_तथ्य_PTR R_RISCV_64
#घोषणा R_JMP_SLOT R_RISCV_JUMP_SLOT
#घोषणा R_GLOB_DAT R_RISCV_64
#घोषणा R_COPY     R_RISCV_COPY
#घोषणा R_RELATIVE R_RISCV_RELATIVE

#घोषणा R_अंक      R_RISCV_अंक

#घोषणा ELF_START_ADDR 0x00010000
#घोषणा ELF_PAGE_आकार 0x1000

#घोषणा PCRELATIVE_DLLPLT 1
#घोषणा RELOCATE_DLLPLT 1

#अन्यथा /* !TARGET_DEFS_ONLY */

//#define DEBUG_RELOC
#समावेश "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC पूर्णांक code_reloc (पूर्णांक reloc_type)
{
    चयन (reloc_type) {

    हाल R_RISCV_BRANCH:
    हाल R_RISCV_CALL:
    हाल R_RISCV_JAL:
        वापस 1;

    हाल R_RISCV_GOT_HI20:
    हाल R_RISCV_PCREL_HI20:
    हाल R_RISCV_PCREL_LO12_I:
    हाल R_RISCV_PCREL_LO12_S:
    हाल R_RISCV_32_PCREL:
    हाल R_RISCV_SET6:
    हाल R_RISCV_SET8:
    हाल R_RISCV_SET16:
    हाल R_RISCV_SUB6:
    हाल R_RISCV_ADD16:
    हाल R_RISCV_ADD32:
    हाल R_RISCV_ADD64:
    हाल R_RISCV_SUB8:
    हाल R_RISCV_SUB16:
    हाल R_RISCV_SUB32:
    हाल R_RISCV_SUB64:
    हाल R_RISCV_32:
    हाल R_RISCV_64:
    हाल R_RISCV_SET_ULEB128:
    हाल R_RISCV_SUB_ULEB128:
    हाल R_RISCV_TPREL_HI20:
    हाल R_RISCV_TPREL_LO12_I:
        वापस 0;

    हाल R_RISCV_CALL_PLT:
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
    हाल R_RISCV_ALIGN:
    हाल R_RISCV_RELAX:
    हाल R_RISCV_RVC_BRANCH:
    हाल R_RISCV_RVC_JUMP:
    हाल R_RISCV_JUMP_SLOT:
    हाल R_RISCV_SET6:
    हाल R_RISCV_SET8:
    हाल R_RISCV_SET16:
    हाल R_RISCV_SUB6:
    हाल R_RISCV_ADD16:
    हाल R_RISCV_SUB8:
    हाल R_RISCV_SUB16:
    हाल R_RISCV_SET_ULEB128:
    हाल R_RISCV_SUB_ULEB128:
        वापस NO_GOTPLT_ENTRY;

    हाल R_RISCV_BRANCH:
    हाल R_RISCV_CALL:
    हाल R_RISCV_PCREL_HI20:
    हाल R_RISCV_PCREL_LO12_I:
    हाल R_RISCV_PCREL_LO12_S:
    हाल R_RISCV_32_PCREL:
    हाल R_RISCV_ADD32:
    हाल R_RISCV_ADD64:
    हाल R_RISCV_SUB32:
    हाल R_RISCV_SUB64:
    हाल R_RISCV_32:
    हाल R_RISCV_64:
    हाल R_RISCV_JAL:
    हाल R_RISCV_CALL_PLT:
        वापस AUTO_GOTPLT_ENTRY;

    हाल R_RISCV_GOT_HI20:
        वापस ALWAYS_GOTPLT_ENTRY;

    हाल R_RISCV_TPREL_HI20:
    हाल R_RISCV_TPREL_LO12_I:
        वापस NO_GOTPLT_ENTRY;
    }
    वापस -1;
}

ST_FUNC अचिन्हित create_plt_entry(TCCState *s1, अचिन्हित got_offset, काष्ठा sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    अचिन्हित plt_offset;

    अगर (plt->तथ्य_offset == 0)
        section_ptr_add(plt, 32);
    plt_offset = plt->तथ्य_offset;

    p = section_ptr_add(plt, 16);
    write64le(p, got_offset);
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
        uint64_t got = s1->got->sh_addr;
        uint64_t off = (got - plt + 0x800) >> 12;
        अगर ((off + ((uint32_t)1 << 20)) >> 21)
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
        जबतक (p < p_end) {
            uint64_t pc = plt + (p - s1->plt->तथ्य);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr - pc + 0x800) >> 12;
            अगर ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (दीर्घ)off, (दीर्घ)addr, (दीर्घ)pc);
            write32le(p, 0xe17 | (off << 12)); // auipc t3, %pcrel_hi(func@got)
            write32le(p + 4, 0x000e3e03 // ld t3, %pcrel_lo(func@got)(t3)
                             | (((addr - pc) & 0xfff) << 20));
            write32le(p + 8, 0x000e0367); // jalr t1, t3
            write32le(p + 12, 0x00000013); // nop
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

अटल व्योम riscv64_record_pcrel_hi(TCCState *s1, addr_t addr, addr_t val)
{
    काष्ठा pcrel_hi *entry = tcc_malloc(माप *entry);
    entry->addr = addr;
    entry->val = val;
    dynarray_add(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries, entry);
}

अटल पूर्णांक riscv64_lookup_pcrel_hi(TCCState *s1, addr_t hi_addr, addr_t *hi_val)
{
    पूर्णांक i;
    क्रम (i = s1->nb_pcrel_hi_entries; i > 0; ) {
        काष्ठा pcrel_hi *entry = s1->pcrel_hi_entries[--i];
        अगर (entry->addr == hi_addr) {
            *hi_val = entry->val;
            वापस 0;
        }
    }
    वापस tcc_error_noabort("unsupported hi/lo pcrel reloc scheme");
}

ST_FUNC व्योम relocate(TCCState *s1, ElfW_Rel *rel, पूर्णांक type, अचिन्हित अक्षर *ptr,
              addr_t addr, addr_t val)
{
    uint64_t off64;
    uint32_t off32;
    पूर्णांक sym_सूचकांक = ELFW(R_SYM)(rel->r_info), esym_सूचकांक;
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];

    चयन(type) {
    हाल R_RISCV_ALIGN:
    हाल R_RISCV_RELAX:
        वापस;

    हाल R_RISCV_BRANCH:
        off64 = val - addr;
        अगर ((off64 + (1 << 12)) & ~(uint64_t)0x1ffe)
          tcc_error_noabort("R_RISCV_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (दीर्घ)val, (दीर्घ)addr);
        off32 = off64 >> 1;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0x800) << 20)
                       | ((off32 & 0x3f0) << 21)
                       | ((off32 & 0x00f) << 8)
                       | ((off32 & 0x400) >> 3));
        वापस;
    हाल R_RISCV_JAL:
        off64 = val - addr;
        अगर ((off64 + (1 << 21)) & ~(((uint64_t)1 << 22) - 2))
          tcc_error_noabort("R_RISCV_JAL relocation failed"
                    " (val=%lx, addr=%lx)", (दीर्घ)val, (दीर्घ)addr);
        off32 = off64;
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | (((off32 >> 12) &  0xff) << 12)
                       | (((off32 >> 11) &     1) << 20)
                       | (((off32 >>  1) & 0x3ff) << 21)
                       | (((off32 >> 20) &     1) << 31));
        वापस;
    हाल R_RISCV_CALL:
    हाल R_RISCV_CALL_PLT:
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((val - addr + 0x800) & ~0xfff));
        write32le(ptr + 4, (read32le(ptr + 4) & 0xfffff)
                           | (((val - addr) & 0xfff) << 20));
        वापस;
    हाल R_RISCV_PCREL_HI20:
#अगर_घोषित DEBUG_RELOC
        म_लिखो("PCREL_HI20: val=%lx addr=%lx\n", (दीर्घ)val, (दीर्घ)addr);
#पूर्ण_अगर
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        अगर ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_PCREL_HI20 relocation failed: off=%lx cond=%lx sym=%s",
                    (दीर्घ)off64, (दीर्घ)((int64_t)(off64 + ((uint64_t)1 << 20)) >> 21),
                    symtab_section->link->तथ्य + sym->st_name);
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_record_pcrel_hi(s1, addr, val);
        वापस;
    हाल R_RISCV_GOT_HI20:
        val = s1->got->sh_addr + get_sym_attr(s1, sym_सूचकांक, 0)->got_offset;
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        अगर ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_GOT_HI20 relocation failed");
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_record_pcrel_hi(s1, addr, val);
        वापस;
    हाल R_RISCV_PCREL_LO12_I:
#अगर_घोषित DEBUG_RELOC
        म_लिखो("PCREL_LO12_I: val=%lx addr=%lx\n", (दीर्घ)val, (दीर्घ)addr);
#पूर्ण_अगर
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        write32le(ptr, (read32le(ptr) & 0xfffff)
                       | (((val - addr) & 0xfff) << 20));
        वापस;
    हाल R_RISCV_PCREL_LO12_S:
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        off32 = val - addr;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0xfe0) << 20)
                       | ((off32 & 0x01f) << 7));
        वापस;

    हाल R_RISCV_RVC_BRANCH:
        off64 = (val - addr);
        अगर ((off64 + (1 << 8)) & ~(uint64_t)0x1fe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (दीर्घ)val, (दीर्घ)addr);
        off32 = off64;
        write16le(ptr, (read16le(ptr) & 0xe383)
                       | (((off32 >> 5) & 1) << 2)
                       | (((off32 >> 1) & 3) << 3)
                       | (((off32 >> 6) & 3) << 5)
                       | (((off32 >> 3) & 3) << 10)
                       | (((off32 >> 8) & 1) << 12));
        वापस;
    हाल R_RISCV_RVC_JUMP:
        off64 = (val - addr);
        अगर ((off64 + (1 << 11)) & ~(uint64_t)0xffe)
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
        वापस;

    हाल R_RISCV_32:
        अगर (s1->output_type & TCC_OUTPUT_DYN) {
            /* XXX: this logic may depend on TCC's codegen
               now TCC uses R_RISCV_RELATIVE even for a 64bit pointer */
            qrel->r_offset = rel->r_offset;
            qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
            /* Use sign extension! */
            qrel->r_addend = (पूर्णांक)read32le(ptr) + val;
            qrel++;
        }
        add32le(ptr, val);
        वापस;
    हाल R_RISCV_64:
        अगर (s1->output_type & TCC_OUTPUT_DYN) {
            esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
            qrel->r_offset = rel->r_offset;
            अगर (esym_सूचकांक) {
                qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_RISCV_64);
                qrel->r_addend = rel->r_addend;
                qrel++;
                अवरोध;
            } अन्यथा {
                qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
                qrel->r_addend = read64le(ptr) + val;
                qrel++;
            }
        }
    हाल R_RISCV_JUMP_SLOT:
        add64le(ptr, val);
        वापस;
    हाल R_RISCV_ADD64:
        write64le(ptr, read64le(ptr) + val);
        वापस;
    हाल R_RISCV_ADD32:
        write32le(ptr, read32le(ptr) + val);
        वापस;
    हाल R_RISCV_SUB64:
        write64le(ptr, read64le(ptr) - val);
        वापस;
    हाल R_RISCV_SUB32:
        write32le(ptr, read32le(ptr) - val);
        वापस;
    हाल R_RISCV_ADD16:
        write16le(ptr, read16le(ptr) + val);
        वापस;
    हाल R_RISCV_SUB8:
        *ptr -= val;
        वापस;
    हाल R_RISCV_SUB16:
        write16le(ptr, read16le(ptr) - val);
        वापस;
    हाल R_RISCV_SET6:
        *ptr = (*ptr & ~0x3f) | (val & 0x3f);
        वापस;
    हाल R_RISCV_SET8:
        *ptr = (*ptr & ~0xff) | (val & 0xff);
        वापस;
    हाल R_RISCV_SET16:
        write16le(ptr, val);
        वापस;
    हाल R_RISCV_SUB6:
        *ptr = (*ptr & ~0x3f) | ((*ptr - val) & 0x3f);
        वापस;
    हाल R_RISCV_32_PCREL:
        अगर (s1->output_type & TCC_OUTPUT_DYN) {
	    /* DLL relocation */
	    esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
	    अगर (esym_सूचकांक) {
                qrel->r_offset = rel->r_offset;
                qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_RISCV_32_PCREL);
                /* Use sign extension! */
                qrel->r_addend = (पूर्णांक)read32le(ptr) + rel->r_addend;
                qrel++;
		अवरोध;
	    }
        }
	add32le(ptr, val - addr);
        वापस;
    हाल R_RISCV_SET_ULEB128:
    हाल R_RISCV_SUB_ULEB128:
	/* ignore. used in section .debug_loclists */
        वापस;
    हाल R_RISCV_COPY:
        /* XXX */
        वापस;
    हाल R_RISCV_RELATIVE:
        /* R_RISCV_RELATIVE value is already applied in R_RISCV_32/64
           dynamic output paths, but we need this case for incoming
           RELATIVE relocations from object files. */
        वापस;

    हाल R_RISCV_TPREL_HI20:
    हाल R_RISCV_TPREL_LO12_I: {
        int64_t tp_offset = val - s1->tls_start;
        अगर (type == R_RISCV_TPREL_HI20) {
            off64 = (int64_t)(tp_offset + 0x800) >> 12;
            अगर ((off64 + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_RISCV_TPREL_HI20 relocation failed");
            write32le(ptr, (read32le(ptr) & 0xfff)
                           | ((off64 & 0xfffff) << 12));
        } अन्यथा {
            write32le(ptr, (read32le(ptr) & 0xfffff)
                           | (((tp_offset) & 0xfff) << 20));
        }
        वापस;
    }

    शेष:
        ख_लिखो(मानक_त्रुटि, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                type, (अचिन्हित)addr, ptr, (अचिन्हित)val);
        वापस;
    }
}
#पूर्ण_अगर
