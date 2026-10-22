#यदि_परिभाषितम् TARGET_DEFS_ONLY

#परिभाषय EM_TCC_TARGET EM_RISCV

#परिभाषय R_दत्त_32  R_RISCV_32
#परिभाषय R_दत्त_PTR R_RISCV_64
#परिभाषय R_JMP_SLOT R_RISCV_JUMP_SLOT
#परिभाषय R_GLOB_DAT R_RISCV_64
#परिभाषय R_COPY     R_RISCV_COPY
#परिभाषय R_RELATIVE R_RISCV_RELATIVE

#परिभाषय R_अङ्कः      R_RISCV_अङ्कः

#परिभाषय ELF_START_ADDR 0x00010000
#परिभाषय ELF_PAGE_आकार 0x1000

#परिभाषय PCRELATIVE_DLLPLT 1
#परिभाषय RELOCATE_DLLPLT 1

#अन्यथा /* !TARGET_DEFS_ONLY */

//#define DEBUG_RELOC
#अन्तर्भाव "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC पूर्णाङ्क संहिता_reloc (पूर्णाङ्क reloc_type)
{
    विकल्प (reloc_type) {

    पक्ष R_RISCV_BRANCH:
    पक्ष R_RISCV_CALL:
    पक्ष R_RISCV_JAL:
        प्रत्यागम 1;

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
    पक्ष R_RISCV_समुच्चयः_ULEB128:
    पक्ष R_RISCV_SUB_ULEB128:
    पक्ष R_RISCV_TPREL_HI20:
    पक्ष R_RISCV_TPREL_LO12_I:
        प्रत्यागम 0;

    पक्ष R_RISCV_CALL_PLT:
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
    पक्ष R_RISCV_समुच्चयः_ULEB128:
    पक्ष R_RISCV_SUB_ULEB128:
        प्रत्यागम NO_GOTPLT_प्रविष्टिः;

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
        प्रत्यागम AUTO_GOTPLT_प्रविष्टिः;

    पक्ष R_RISCV_GOT_HI20:
        प्रत्यागम ALWAYS_GOTPLT_प्रविष्टिः;

    पक्ष R_RISCV_TPREL_HI20:
    पक्ष R_RISCV_TPREL_LO12_I:
        प्रत्यागम NO_GOTPLT_प्रविष्टिः;
    }
    प्रत्यागम -1;
}

ST_FUNC अचिह्नित create_plt_प्रविष्टिः(TCCState *s1, अचिह्नित got_विस्थापनम्, संरचना sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    अचिह्नित plt_विस्थापनम्;

    यदि (plt->दत्त_विस्थापनम् == 0)
        section_ptr_सङ्कलय(plt, 32);
    plt_विस्थापनम् = plt->दत्त_विस्थापनम्;

    p = section_ptr_सङ्कलय(plt, 16);
    write64le(p, got_विस्थापनम्);
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
        यावत् (p < p_अन्तः) {
            uint64_t pc = plt + (p - s1->plt->दत्त);
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
        p = s1->got->दत्त;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_विस्थापनम्, s1->plt->sh_addr);
	}
    }
}

स्थिर शून्य riscv64_लेखः_pcrel_hi(TCCState *s1, addr_t addr, addr_t val)
{
    संरचना pcrel_hi *entry = tcc_malloc(परिमाण *entry);
    entry->addr = addr;
    entry->val = val;
    dynarray_सङ्कलय(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries, entry);
}

स्थिर पूर्णाङ्क riscv64_lookup_pcrel_hi(TCCState *s1, addr_t hi_addr, addr_t *hi_val)
{
    पूर्णाङ्क i;
    प्रति (i = s1->nb_pcrel_hi_entries; i > 0; ) {
        संरचना pcrel_hi *entry = s1->pcrel_hi_entries[--i];
        यदि (entry->addr == hi_addr) {
            *hi_val = entry->val;
            प्रत्यागम 0;
        }
    }
    प्रत्यागम tcc_error_noabort("unsupported hi/lo pcrel reloc scheme");
}

ST_FUNC शून्य relocate(TCCState *s1, ElfW_Rel *rel, पूर्णाङ्क type, अचिह्नित वर्ण *ptr,
              addr_t addr, addr_t val)
{
    uint64_t off64;
    uint32_t off32;
    पूर्णाङ्क sym_सूचकांक = ELFW(R_SYM)(rel->r_info), esym_सूचकांक;
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];

    विकल्प(type) {
    पक्ष R_RISCV_ALIGN:
    पक्ष R_RISCV_RELAX:
        प्रत्यागम;

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
        प्रत्यागम;
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
        प्रत्यागम;
    पक्ष R_RISCV_CALL:
    पक्ष R_RISCV_CALL_PLT:
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((val - addr + 0x800) & ~0xfff));
        write32le(ptr + 4, (read32le(ptr + 4) & 0xfffff)
                           | (((val - addr) & 0xfff) << 20));
        प्रत्यागम;
    पक्ष R_RISCV_PCREL_HI20:
#यदि_परिभाषितम् DEBUG_RELOC
        प्रारूप_लिख("PCREL_HI20: val=%lx addr=%lx\n", (दीर्घ)val, (दीर्घ)addr);
#यदि_अन्तः
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        यदि ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_PCREL_HI20 relocation failed: off=%lx cond=%lx sym=%s",
                    (दीर्घ)off64, (दीर्घ)((int64_t)(off64 + ((uint64_t)1 << 20)) >> 21),
                    symtab_section->link->दत्त + sym->st_name);
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_लेखः_pcrel_hi(s1, addr, val);
        प्रत्यागम;
    पक्ष R_RISCV_GOT_HI20:
        val = s1->got->sh_addr + get_sym_attr(s1, sym_सूचकांक, 0)->got_विस्थापनम्;
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        यदि ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_GOT_HI20 relocation failed");
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_लेखः_pcrel_hi(s1, addr, val);
        प्रत्यागम;
    पक्ष R_RISCV_PCREL_LO12_I:
#यदि_परिभाषितम् DEBUG_RELOC
        प्रारूप_लिख("PCREL_LO12_I: val=%lx addr=%lx\n", (दीर्घ)val, (दीर्घ)addr);
#यदि_अन्तः
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        write32le(ptr, (read32le(ptr) & 0xfffff)
                       | (((val - addr) & 0xfff) << 20));
        प्रत्यागम;
    पक्ष R_RISCV_PCREL_LO12_S:
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        off32 = val - addr;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0xfe0) << 20)
                       | ((off32 & 0x01f) << 7));
        प्रत्यागम;

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
        प्रत्यागम;
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
        प्रत्यागम;

    पक्ष R_RISCV_32:
        यदि (s1->output_type & TCC_OUTPUT_DYN) {
            /* XXX: this logic may depend on TCC's codegen
               now TCC uses R_RISCV_RELATIVE even for a 64bit pointer */
            qrel->r_विस्थापनम् = rel->r_विस्थापनम्;
            qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
            /* Use sign extension! */
            qrel->r_addend = (पूर्णाङ्क)read32le(ptr) + val;
            qrel++;
        }
        add32le(ptr, val);
        प्रत्यागम;
    पक्ष R_RISCV_64:
        यदि (s1->output_type & TCC_OUTPUT_DYN) {
            esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
            qrel->r_विस्थापनम् = rel->r_विस्थापनम्;
            यदि (esym_सूचकांक) {
                qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_RISCV_64);
                qrel->r_addend = rel->r_addend;
                qrel++;
                भङ्ग;
            } अन्यथा {
                qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
                qrel->r_addend = read64le(ptr) + val;
                qrel++;
            }
        }
    पक्ष R_RISCV_JUMP_SLOT:
        add64le(ptr, val);
        प्रत्यागम;
    पक्ष R_RISCV_ADD64:
        write64le(ptr, read64le(ptr) + val);
        प्रत्यागम;
    पक्ष R_RISCV_ADD32:
        write32le(ptr, read32le(ptr) + val);
        प्रत्यागम;
    पक्ष R_RISCV_SUB64:
        write64le(ptr, read64le(ptr) - val);
        प्रत्यागम;
    पक्ष R_RISCV_SUB32:
        write32le(ptr, read32le(ptr) - val);
        प्रत्यागम;
    पक्ष R_RISCV_ADD16:
        write16le(ptr, read16le(ptr) + val);
        प्रत्यागम;
    पक्ष R_RISCV_SUB8:
        *ptr -= val;
        प्रत्यागम;
    पक्ष R_RISCV_SUB16:
        write16le(ptr, read16le(ptr) - val);
        प्रत्यागम;
    पक्ष R_RISCV_SET6:
        *ptr = (*ptr & ~0x3f) | (val & 0x3f);
        प्रत्यागम;
    पक्ष R_RISCV_SET8:
        *ptr = (*ptr & ~0xff) | (val & 0xff);
        प्रत्यागम;
    पक्ष R_RISCV_SET16:
        write16le(ptr, val);
        प्रत्यागम;
    पक्ष R_RISCV_SUB6:
        *ptr = (*ptr & ~0x3f) | ((*ptr - val) & 0x3f);
        प्रत्यागम;
    पक्ष R_RISCV_32_PCREL:
        यदि (s1->output_type & TCC_OUTPUT_DYN) {
	    /* DLL relocation */
	    esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
	    यदि (esym_सूचकांक) {
                qrel->r_विस्थापनम् = rel->r_विस्थापनम्;
                qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_RISCV_32_PCREL);
                /* Use sign extension! */
                qrel->r_addend = (पूर्णाङ्क)read32le(ptr) + rel->r_addend;
                qrel++;
		भङ्ग;
	    }
        }
	add32le(ptr, val - addr);
        प्रत्यागम;
    पक्ष R_RISCV_समुच्चयः_ULEB128:
    पक्ष R_RISCV_SUB_ULEB128:
	/* ignore. used in section .debug_loclists */
        प्रत्यागम;
    पक्ष R_RISCV_COPY:
        /* XXX */
        प्रत्यागम;
    पक्ष R_RISCV_RELATIVE:
        /* R_RISCV_RELATIVE value is already applied in R_RISCV_32/64
           dynamic output paths, but we need this case for incoming
           RELATIVE relocations from object files. */
        प्रत्यागम;

    पक्ष R_RISCV_TPREL_HI20:
    पक्ष R_RISCV_TPREL_LO12_I: {
        int64_t tp_विस्थापनम् = val - s1->tls_start;
        यदि (type == R_RISCV_TPREL_HI20) {
            off64 = (int64_t)(tp_विस्थापनम् + 0x800) >> 12;
            यदि ((off64 + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_RISCV_TPREL_HI20 relocation failed");
            write32le(ptr, (read32le(ptr) & 0xfff)
                           | ((off64 & 0xfffff) << 12));
        } अन्यथा {
            write32le(ptr, (read32le(ptr) & 0xfffff)
                           | (((tp_विस्थापनम्) & 0xfff) << 20));
        }
        प्रत्यागम;
    }

    स्वभाव:
        fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                type, (अचिह्नित)addr, ptr, (अचिह्नित)val);
        प्रत्यागम;
    }
}
#यदि_अन्तः
