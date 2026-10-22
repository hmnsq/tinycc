#که_تعریف_شوی موخه_DEFS_ONLY

#تعریف_کړه EM_TCC_موخه EM_RISCV

#تعریف_کړه R_معلومات_32  R_RISCV_32
#تعریف_کړه R_معلومات_PTR R_RISCV_64
#تعریف_کړه R_JMP_خونه R_RISCV_JUMP_خونه
#تعریف_کړه R_GLOB_DAT R_RISCV_64
#تعریف_کړه R_COPY     R_RISCV_COPY
#تعریف_کړه R_RELATIVE R_RISCV_RELATIVE

#تعریف_کړه R_عدد      R_RISCV_عدد

#تعریف_کړه ELF_پیل_ADDR 0x00010000
#تعریف_کړه ELF_پاڼه_اندازه 0x1000

#تعریف_کړه PCRELATIVE_DLLPLT 1
#تعریف_کړه RELOCATE_DLLPLT 1

#وإلا /* !TARGET_DEFS_ONLY */

//#define DEBUG_RELOC
#ضمن "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحيح کوډ_reloc (صحيح reloc_type)
{
    بدل (reloc_type) {

    حالة R_RISCV_BRANCH:
    حالة R_RISCV_CALL:
    حالة R_RISCV_JAL:
        أرجع 1;

    حالة R_RISCV_GOT_HI20:
    حالة R_RISCV_PCREL_HI20:
    حالة R_RISCV_PCREL_LO12_I:
    حالة R_RISCV_PCREL_LO12_S:
    حالة R_RISCV_32_PCREL:
    حالة R_RISCV_SET6:
    حالة R_RISCV_SET8:
    حالة R_RISCV_SET16:
    حالة R_RISCV_SUB6:
    حالة R_RISCV_ADD16:
    حالة R_RISCV_ADD32:
    حالة R_RISCV_ADD64:
    حالة R_RISCV_SUB8:
    حالة R_RISCV_SUB16:
    حالة R_RISCV_SUB32:
    حالة R_RISCV_SUB64:
    حالة R_RISCV_32:
    حالة R_RISCV_64:
    حالة R_RISCV_سېټ_ULEB128:
    حالة R_RISCV_SUB_ULEB128:
    حالة R_RISCV_TPREL_HI20:
    حالة R_RISCV_TPREL_LO12_I:
        أرجع 0;

    حالة R_RISCV_CALL_PLT:
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
    حالة R_RISCV_ALIGN:
    حالة R_RISCV_RELAX:
    حالة R_RISCV_RVC_BRANCH:
    حالة R_RISCV_RVC_JUMP:
    حالة R_RISCV_JUMP_خونه:
    حالة R_RISCV_SET6:
    حالة R_RISCV_SET8:
    حالة R_RISCV_SET16:
    حالة R_RISCV_SUB6:
    حالة R_RISCV_ADD16:
    حالة R_RISCV_SUB8:
    حالة R_RISCV_SUB16:
    حالة R_RISCV_سېټ_ULEB128:
    حالة R_RISCV_SUB_ULEB128:
        أرجع NO_GOTPLT_ثبت;

    حالة R_RISCV_BRANCH:
    حالة R_RISCV_CALL:
    حالة R_RISCV_PCREL_HI20:
    حالة R_RISCV_PCREL_LO12_I:
    حالة R_RISCV_PCREL_LO12_S:
    حالة R_RISCV_32_PCREL:
    حالة R_RISCV_ADD32:
    حالة R_RISCV_ADD64:
    حالة R_RISCV_SUB32:
    حالة R_RISCV_SUB64:
    حالة R_RISCV_32:
    حالة R_RISCV_64:
    حالة R_RISCV_JAL:
    حالة R_RISCV_CALL_PLT:
        أرجع AUTO_GOTPLT_ثبت;

    حالة R_RISCV_GOT_HI20:
        أرجع ALWAYS_GOTPLT_ثبت;

    حالة R_RISCV_TPREL_HI20:
    حالة R_RISCV_TPREL_LO12_I:
        أرجع NO_GOTPLT_ثبت;
    }
    أرجع -1;
}

ST_FUNC بینښه create_plt_ثبت(TCCState *s1, بینښه got_دننه_واټن, بنية sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    بینښه plt_دننه_واټن;

    إذا (plt->معلومات_دننه_واټن == 0)
        section_ptr_جمع_کړه(plt, 32);
    plt_دننه_واټن = plt->معلومات_دننه_واټن;

    p = section_ptr_جمع_کړه(plt, 16);
    write64le(p, got_دننه_واټن);
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
        uint64_t got = s1->got->sh_addr;
        uint64_t off = (got - plt + 0x800) >> 12;
        إذا ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (اوږد)off, (اوږد)got, (اوږد)plt);
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
        طالما (p < p_پای_ټکی) {
            uint64_t pc = plt + (p - s1->plt->معلومات);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr - pc + 0x800) >> 12;
            إذا ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (اوږد)off, (اوږد)addr, (اوږد)pc);
            write32le(p, 0xe17 | (off << 12)); // auipc t3, %pcrel_hi(func@got)
            write32le(p + 4, 0x000e3e03 // ld t3, %pcrel_lo(func@got)(t3)
                             | (((addr - pc) & 0xfff) << 20));
            write32le(p + 8, 0x000e0367); // jalr t1, t3
            write32le(p + 12, 0x00000013); // nop
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

ساكن فراغ riscv64_ریکارډ_pcrel_hi(TCCState *s1, addr_t addr, addr_t val)
{
    بنية pcrel_hi *entry = tcc_malloc(حجم *entry);
    entry->addr = addr;
    entry->val = val;
    dynarray_جمع_کړه(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries, entry);
}

ساكن صحيح riscv64_lookup_pcrel_hi(TCCState *s1, addr_t hi_addr, addr_t *hi_val)
{
    صحيح i;
    لكل (i = s1->nb_pcrel_hi_entries; i > 0; ) {
        بنية pcrel_hi *entry = s1->pcrel_hi_entries[--i];
        إذا (entry->addr == hi_addr) {
            *hi_val = entry->val;
            أرجع 0;
        }
    }
    أرجع tcc_error_noabort("unsupported hi/lo pcrel reloc scheme");
}

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, بینښه حرف *ptr,
              addr_t addr, addr_t val)
{
    uint64_t off64;
    uint32_t off32;
    صحيح sym_شاخص = ELFW(R_SYM)(rel->r_info), esym_شاخص;
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];

    بدل(type) {
    حالة R_RISCV_ALIGN:
    حالة R_RISCV_RELAX:
        أرجع;

    حالة R_RISCV_BRANCH:
        off64 = val - addr;
        إذا ((off64 + (1 << 12)) & ~(uint64_t)0x1ffe)
          tcc_error_noabort("R_RISCV_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (اوږد)val, (اوږد)addr);
        off32 = off64 >> 1;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0x800) << 20)
                       | ((off32 & 0x3f0) << 21)
                       | ((off32 & 0x00f) << 8)
                       | ((off32 & 0x400) >> 3));
        أرجع;
    حالة R_RISCV_JAL:
        off64 = val - addr;
        إذا ((off64 + (1 << 21)) & ~(((uint64_t)1 << 22) - 2))
          tcc_error_noabort("R_RISCV_JAL relocation failed"
                    " (val=%lx, addr=%lx)", (اوږد)val, (اوږد)addr);
        off32 = off64;
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | (((off32 >> 12) &  0xff) << 12)
                       | (((off32 >> 11) &     1) << 20)
                       | (((off32 >>  1) & 0x3ff) << 21)
                       | (((off32 >> 20) &     1) << 31));
        أرجع;
    حالة R_RISCV_CALL:
    حالة R_RISCV_CALL_PLT:
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((val - addr + 0x800) & ~0xfff));
        write32le(ptr + 4, (read32le(ptr + 4) & 0xfffff)
                           | (((val - addr) & 0xfff) << 20));
        أرجع;
    حالة R_RISCV_PCREL_HI20:
#که_تعریف_شوی DEBUG_RELOC
        چاپ_کړه("PCREL_HI20: val=%lx addr=%lx\n", (اوږد)val, (اوږد)addr);
#د_که_پای
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        إذا ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_PCREL_HI20 relocation failed: off=%lx cond=%lx sym=%s",
                    (اوږد)off64, (اوږد)((int64_t)(off64 + ((uint64_t)1 << 20)) >> 21),
                    symtab_section->link->معلومات + sym->st_name);
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_ریکارډ_pcrel_hi(s1, addr, val);
        أرجع;
    حالة R_RISCV_GOT_HI20:
        val = s1->got->sh_addr + get_sym_attr(s1, sym_شاخص, 0)->got_دننه_واټن;
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        إذا ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_GOT_HI20 relocation failed");
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_ریکارډ_pcrel_hi(s1, addr, val);
        أرجع;
    حالة R_RISCV_PCREL_LO12_I:
#که_تعریف_شوی DEBUG_RELOC
        چاپ_کړه("PCREL_LO12_I: val=%lx addr=%lx\n", (اوږد)val, (اوږد)addr);
#د_که_پای
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        write32le(ptr, (read32le(ptr) & 0xfffff)
                       | (((val - addr) & 0xfff) << 20));
        أرجع;
    حالة R_RISCV_PCREL_LO12_S:
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        off32 = val - addr;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0xfe0) << 20)
                       | ((off32 & 0x01f) << 7));
        أرجع;

    حالة R_RISCV_RVC_BRANCH:
        off64 = (val - addr);
        إذا ((off64 + (1 << 8)) & ~(uint64_t)0x1fe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (اوږد)val, (اوږد)addr);
        off32 = off64;
        write16le(ptr, (read16le(ptr) & 0xe383)
                       | (((off32 >> 5) & 1) << 2)
                       | (((off32 >> 1) & 3) << 3)
                       | (((off32 >> 6) & 3) << 5)
                       | (((off32 >> 3) & 3) << 10)
                       | (((off32 >> 8) & 1) << 12));
        أرجع;
    حالة R_RISCV_RVC_JUMP:
        off64 = (val - addr);
        إذا ((off64 + (1 << 11)) & ~(uint64_t)0xffe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (اوږد)val, (اوږد)addr);
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
        أرجع;

    حالة R_RISCV_32:
        إذا (s1->output_type & TCC_OUTPUT_DYN) {
            /* XXX: this logic may depend on TCC's codegen
               now TCC uses R_RISCV_RELATIVE even for a 64bit pointer */
            qrel->r_دننه_واټن = rel->r_دننه_واټن;
            qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
            /* Use sign extension! */
            qrel->r_addend = (صحيح)read32le(ptr) + val;
            qrel++;
        }
        add32le(ptr, val);
        أرجع;
    حالة R_RISCV_64:
        إذا (s1->output_type & TCC_OUTPUT_DYN) {
            esym_شاخص = get_sym_attr(s1, sym_شاخص, 0)->dyn_شاخص;
            qrel->r_دننه_واټن = rel->r_دننه_واټن;
            إذا (esym_شاخص) {
                qrel->r_info = ELFW(R_INFO)(esym_شاخص, R_RISCV_64);
                qrel->r_addend = rel->r_addend;
                qrel++;
                اكسر;
            } وإلا {
                qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
                qrel->r_addend = read64le(ptr) + val;
                qrel++;
            }
        }
    حالة R_RISCV_JUMP_خونه:
        add64le(ptr, val);
        أرجع;
    حالة R_RISCV_ADD64:
        write64le(ptr, read64le(ptr) + val);
        أرجع;
    حالة R_RISCV_ADD32:
        write32le(ptr, read32le(ptr) + val);
        أرجع;
    حالة R_RISCV_SUB64:
        write64le(ptr, read64le(ptr) - val);
        أرجع;
    حالة R_RISCV_SUB32:
        write32le(ptr, read32le(ptr) - val);
        أرجع;
    حالة R_RISCV_ADD16:
        write16le(ptr, read16le(ptr) + val);
        أرجع;
    حالة R_RISCV_SUB8:
        *ptr -= val;
        أرجع;
    حالة R_RISCV_SUB16:
        write16le(ptr, read16le(ptr) - val);
        أرجع;
    حالة R_RISCV_SET6:
        *ptr = (*ptr & ~0x3f) | (val & 0x3f);
        أرجع;
    حالة R_RISCV_SET8:
        *ptr = (*ptr & ~0xff) | (val & 0xff);
        أرجع;
    حالة R_RISCV_SET16:
        write16le(ptr, val);
        أرجع;
    حالة R_RISCV_SUB6:
        *ptr = (*ptr & ~0x3f) | ((*ptr - val) & 0x3f);
        أرجع;
    حالة R_RISCV_32_PCREL:
        إذا (s1->output_type & TCC_OUTPUT_DYN) {
	    /* DLL relocation */
	    esym_شاخص = get_sym_attr(s1, sym_شاخص, 0)->dyn_شاخص;
	    إذا (esym_شاخص) {
                qrel->r_دننه_واټن = rel->r_دننه_واټن;
                qrel->r_info = ELFW(R_INFO)(esym_شاخص, R_RISCV_32_PCREL);
                /* Use sign extension! */
                qrel->r_addend = (صحيح)read32le(ptr) + rel->r_addend;
                qrel++;
		اكسر;
	    }
        }
	add32le(ptr, val - addr);
        أرجع;
    حالة R_RISCV_سېټ_ULEB128:
    حالة R_RISCV_SUB_ULEB128:
	/* ignore. used in section .debug_loclists */
        أرجع;
    حالة R_RISCV_COPY:
        /* XXX */
        أرجع;
    حالة R_RISCV_RELATIVE:
        /* R_RISCV_RELATIVE value is already applied in R_RISCV_32/64
           dynamic output paths, but we need this case for incoming
           RELATIVE relocations from object files. */
        أرجع;

    حالة R_RISCV_TPREL_HI20:
    حالة R_RISCV_TPREL_LO12_I: {
        int64_t tp_دننه_واټن = val - s1->tls_پیل;
        إذا (type == R_RISCV_TPREL_HI20) {
            off64 = (int64_t)(tp_دننه_واټن + 0x800) >> 12;
            إذا ((off64 + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_RISCV_TPREL_HI20 relocation failed");
            write32le(ptr, (read32le(ptr) & 0xfff)
                           | ((off64 & 0xfffff) << 12));
        } وإلا {
            write32le(ptr, (read32le(ptr) & 0xfffff)
                           | (((tp_دننه_واټن) & 0xfff) << 20));
        }
        أرجع;
    }

    افتراضي:
        fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                type, (بینښه)addr, ptr, (بینښه)val);
        أرجع;
    }
}
#د_که_پای
