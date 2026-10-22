#اگر_تعریف_شدہ ہدف_DEFS_ONLY

#تعریف_کرو EM_TCC_ہدف EM_RISCV

#تعریف_کرو R_ڈیٹا_32  R_RISCV_32
#تعریف_کرو R_ڈیٹا_PTR R_RISCV_64
#تعریف_کرو R_JMP_خانہ R_RISCV_JUMP_خانہ
#تعریف_کرو R_GLOB_DAT R_RISCV_64
#تعریف_کرو R_COPY     R_RISCV_COPY
#تعریف_کرو R_RELATIVE R_RISCV_RELATIVE

#تعریف_کرو R_عدد      R_RISCV_عدد

#تعریف_کرو ELF_آغاز_ADDR 0x00010000
#تعریف_کرو ELF_صفحہ_سائز 0x1000

#تعریف_کرو PCRELATIVE_DLLPLT 1
#تعریف_کرو RELOCATE_DLLPLT 1

#ورنہ /* !TARGET_DEFS_ONLY */

//#define DEBUG_RELOC
#شامل "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحیح رمز_reloc (صحیح reloc_type)
{
    انتخاب (reloc_type) {

    حالت R_RISCV_BRANCH:
    حالت R_RISCV_CALL:
    حالت R_RISCV_JAL:
        واپس 1;

    حالت R_RISCV_GOT_HI20:
    حالت R_RISCV_PCREL_HI20:
    حالت R_RISCV_PCREL_LO12_I:
    حالت R_RISCV_PCREL_LO12_S:
    حالت R_RISCV_32_PCREL:
    حالت R_RISCV_SET6:
    حالت R_RISCV_SET8:
    حالت R_RISCV_SET16:
    حالت R_RISCV_SUB6:
    حالت R_RISCV_ADD16:
    حالت R_RISCV_ADD32:
    حالت R_RISCV_ADD64:
    حالت R_RISCV_SUB8:
    حالت R_RISCV_SUB16:
    حالت R_RISCV_SUB32:
    حالت R_RISCV_SUB64:
    حالت R_RISCV_32:
    حالت R_RISCV_64:
    حالت R_RISCV_سیٹ_ULEB128:
    حالت R_RISCV_SUB_ULEB128:
    حالت R_RISCV_TPREL_HI20:
    حالت R_RISCV_TPREL_LO12_I:
        واپس 0;

    حالت R_RISCV_CALL_PLT:
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
    حالت R_RISCV_ALIGN:
    حالت R_RISCV_RELAX:
    حالت R_RISCV_RVC_BRANCH:
    حالت R_RISCV_RVC_JUMP:
    حالت R_RISCV_JUMP_خانہ:
    حالت R_RISCV_SET6:
    حالت R_RISCV_SET8:
    حالت R_RISCV_SET16:
    حالت R_RISCV_SUB6:
    حالت R_RISCV_ADD16:
    حالت R_RISCV_SUB8:
    حالت R_RISCV_SUB16:
    حالت R_RISCV_سیٹ_ULEB128:
    حالت R_RISCV_SUB_ULEB128:
        واپس NO_GOTPLT_اندراج;

    حالت R_RISCV_BRANCH:
    حالت R_RISCV_CALL:
    حالت R_RISCV_PCREL_HI20:
    حالت R_RISCV_PCREL_LO12_I:
    حالت R_RISCV_PCREL_LO12_S:
    حالت R_RISCV_32_PCREL:
    حالت R_RISCV_ADD32:
    حالت R_RISCV_ADD64:
    حالت R_RISCV_SUB32:
    حالت R_RISCV_SUB64:
    حالت R_RISCV_32:
    حالت R_RISCV_64:
    حالت R_RISCV_JAL:
    حالت R_RISCV_CALL_PLT:
        واپس AUTO_GOTPLT_اندراج;

    حالت R_RISCV_GOT_HI20:
        واپس ALWAYS_GOTPLT_اندراج;

    حالت R_RISCV_TPREL_HI20:
    حالت R_RISCV_TPREL_LO12_I:
        واپس NO_GOTPLT_اندراج;
    }
    واپس -1;
}

ST_FUNC غیرعلامتی create_plt_اندراج(TCCState *s1, غیرعلامتی got_انحراف, ساخت sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    غیرعلامتی plt_انحراف;

    اگر (plt->ڈیٹا_انحراف == 0)
        section_ptr_جوڑو(plt, 32);
    plt_انحراف = plt->ڈیٹا_انحراف;

    p = section_ptr_جوڑو(plt, 16);
    write64le(p, got_انحراف);
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
        uint64_t got = s1->got->sh_addr;
        uint64_t off = (got - plt + 0x800) >> 12;
        اگر ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (طویل)off, (طویل)got, (طویل)plt);
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
        جب (p < p_انتہا) {
            uint64_t pc = plt + (p - s1->plt->ڈیٹا);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr - pc + 0x800) >> 12;
            اگر ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (طویل)off, (طویل)addr, (طویل)pc);
            write32le(p, 0xe17 | (off << 12)); // auipc t3, %pcrel_hi(func@got)
            write32le(p + 4, 0x000e3e03 // ld t3, %pcrel_lo(func@got)(t3)
                             | (((addr - pc) & 0xfff) << 20));
            write32le(p + 8, 0x000e0367); // jalr t1, t3
            write32le(p + 12, 0x00000013); // nop
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

ساکن خالی riscv64_ریکارڈ_pcrel_hi(TCCState *s1, addr_t addr, addr_t val)
{
    ساخت pcrel_hi *entry = tcc_malloc(حجم *entry);
    entry->addr = addr;
    entry->val = val;
    dynarray_جوڑو(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries, entry);
}

ساکن صحیح riscv64_lookup_pcrel_hi(TCCState *s1, addr_t hi_addr, addr_t *hi_val)
{
    صحیح i;
    برائے (i = s1->nb_pcrel_hi_entries; i > 0; ) {
        ساخت pcrel_hi *entry = s1->pcrel_hi_entries[--i];
        اگر (entry->addr == hi_addr) {
            *hi_val = entry->val;
            واپس 0;
        }
    }
    واپس tcc_error_noabort("unsupported hi/lo pcrel reloc scheme");
}

ST_FUNC خالی relocate(TCCState *s1, ElfW_Rel *rel, صحیح type, غیرعلامتی حرف *ptr,
              addr_t addr, addr_t val)
{
    uint64_t off64;
    uint32_t off32;
    صحیح sym_اشاریہ = ELFW(R_SYM)(rel->r_info), esym_اشاریہ;
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];

    انتخاب(type) {
    حالت R_RISCV_ALIGN:
    حالت R_RISCV_RELAX:
        واپس;

    حالت R_RISCV_BRANCH:
        off64 = val - addr;
        اگر ((off64 + (1 << 12)) & ~(uint64_t)0x1ffe)
          tcc_error_noabort("R_RISCV_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (طویل)val, (طویل)addr);
        off32 = off64 >> 1;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0x800) << 20)
                       | ((off32 & 0x3f0) << 21)
                       | ((off32 & 0x00f) << 8)
                       | ((off32 & 0x400) >> 3));
        واپس;
    حالت R_RISCV_JAL:
        off64 = val - addr;
        اگر ((off64 + (1 << 21)) & ~(((uint64_t)1 << 22) - 2))
          tcc_error_noabort("R_RISCV_JAL relocation failed"
                    " (val=%lx, addr=%lx)", (طویل)val, (طویل)addr);
        off32 = off64;
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | (((off32 >> 12) &  0xff) << 12)
                       | (((off32 >> 11) &     1) << 20)
                       | (((off32 >>  1) & 0x3ff) << 21)
                       | (((off32 >> 20) &     1) << 31));
        واپس;
    حالت R_RISCV_CALL:
    حالت R_RISCV_CALL_PLT:
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((val - addr + 0x800) & ~0xfff));
        write32le(ptr + 4, (read32le(ptr + 4) & 0xfffff)
                           | (((val - addr) & 0xfff) << 20));
        واپس;
    حالت R_RISCV_PCREL_HI20:
#اگر_تعریف_شدہ DEBUG_RELOC
        لکھو("PCREL_HI20: val=%lx addr=%lx\n", (طویل)val, (طویل)addr);
#اگر_ختم
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        اگر ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_PCREL_HI20 relocation failed: off=%lx cond=%lx sym=%s",
                    (طویل)off64, (طویل)((int64_t)(off64 + ((uint64_t)1 << 20)) >> 21),
                    symtab_section->link->ڈیٹا + sym->st_name);
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_ریکارڈ_pcrel_hi(s1, addr, val);
        واپس;
    حالت R_RISCV_GOT_HI20:
        val = s1->got->sh_addr + get_sym_attr(s1, sym_اشاریہ, 0)->got_انحراف;
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        اگر ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_GOT_HI20 relocation failed");
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_ریکارڈ_pcrel_hi(s1, addr, val);
        واپس;
    حالت R_RISCV_PCREL_LO12_I:
#اگر_تعریف_شدہ DEBUG_RELOC
        لکھو("PCREL_LO12_I: val=%lx addr=%lx\n", (طویل)val, (طویل)addr);
#اگر_ختم
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        write32le(ptr, (read32le(ptr) & 0xfffff)
                       | (((val - addr) & 0xfff) << 20));
        واپس;
    حالت R_RISCV_PCREL_LO12_S:
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        off32 = val - addr;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0xfe0) << 20)
                       | ((off32 & 0x01f) << 7));
        واپس;

    حالت R_RISCV_RVC_BRANCH:
        off64 = (val - addr);
        اگر ((off64 + (1 << 8)) & ~(uint64_t)0x1fe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (طویل)val, (طویل)addr);
        off32 = off64;
        write16le(ptr, (read16le(ptr) & 0xe383)
                       | (((off32 >> 5) & 1) << 2)
                       | (((off32 >> 1) & 3) << 3)
                       | (((off32 >> 6) & 3) << 5)
                       | (((off32 >> 3) & 3) << 10)
                       | (((off32 >> 8) & 1) << 12));
        واپس;
    حالت R_RISCV_RVC_JUMP:
        off64 = (val - addr);
        اگر ((off64 + (1 << 11)) & ~(uint64_t)0xffe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (طویل)val, (طویل)addr);
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
        واپس;

    حالت R_RISCV_32:
        اگر (s1->output_type & TCC_OUTPUT_DYN) {
            /* XXX: this logic may depend on TCC's codegen
               now TCC uses R_RISCV_RELATIVE even for a 64bit pointer */
            qrel->r_انحراف = rel->r_انحراف;
            qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
            /* Use sign extension! */
            qrel->r_addend = (صحیح)read32le(ptr) + val;
            qrel++;
        }
        add32le(ptr, val);
        واپس;
    حالت R_RISCV_64:
        اگر (s1->output_type & TCC_OUTPUT_DYN) {
            esym_اشاریہ = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
            qrel->r_انحراف = rel->r_انحراف;
            اگر (esym_اشاریہ) {
                qrel->r_info = ELFW(R_INFO)(esym_اشاریہ, R_RISCV_64);
                qrel->r_addend = rel->r_addend;
                qrel++;
                توڑو;
            } ورنہ {
                qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
                qrel->r_addend = read64le(ptr) + val;
                qrel++;
            }
        }
    حالت R_RISCV_JUMP_خانہ:
        add64le(ptr, val);
        واپس;
    حالت R_RISCV_ADD64:
        write64le(ptr, read64le(ptr) + val);
        واپس;
    حالت R_RISCV_ADD32:
        write32le(ptr, read32le(ptr) + val);
        واپس;
    حالت R_RISCV_SUB64:
        write64le(ptr, read64le(ptr) - val);
        واپس;
    حالت R_RISCV_SUB32:
        write32le(ptr, read32le(ptr) - val);
        واپس;
    حالت R_RISCV_ADD16:
        write16le(ptr, read16le(ptr) + val);
        واپس;
    حالت R_RISCV_SUB8:
        *ptr -= val;
        واپس;
    حالت R_RISCV_SUB16:
        write16le(ptr, read16le(ptr) - val);
        واپس;
    حالت R_RISCV_SET6:
        *ptr = (*ptr & ~0x3f) | (val & 0x3f);
        واپس;
    حالت R_RISCV_SET8:
        *ptr = (*ptr & ~0xff) | (val & 0xff);
        واپس;
    حالت R_RISCV_SET16:
        write16le(ptr, val);
        واپس;
    حالت R_RISCV_SUB6:
        *ptr = (*ptr & ~0x3f) | ((*ptr - val) & 0x3f);
        واپس;
    حالت R_RISCV_32_PCREL:
        اگر (s1->output_type & TCC_OUTPUT_DYN) {
	    /* DLL relocation */
	    esym_اشاریہ = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
	    اگر (esym_اشاریہ) {
                qrel->r_انحراف = rel->r_انحراف;
                qrel->r_info = ELFW(R_INFO)(esym_اشاریہ, R_RISCV_32_PCREL);
                /* Use sign extension! */
                qrel->r_addend = (صحیح)read32le(ptr) + rel->r_addend;
                qrel++;
		توڑو;
	    }
        }
	add32le(ptr, val - addr);
        واپس;
    حالت R_RISCV_سیٹ_ULEB128:
    حالت R_RISCV_SUB_ULEB128:
	/* ignore. used in section .debug_loclists */
        واپس;
    حالت R_RISCV_COPY:
        /* XXX */
        واپس;
    حالت R_RISCV_RELATIVE:
        /* R_RISCV_RELATIVE value is already applied in R_RISCV_32/64
           dynamic output paths, but we need this case for incoming
           RELATIVE relocations from object files. */
        واپس;

    حالت R_RISCV_TPREL_HI20:
    حالت R_RISCV_TPREL_LO12_I: {
        int64_t tp_انحراف = val - s1->tls_آغاز;
        اگر (type == R_RISCV_TPREL_HI20) {
            off64 = (int64_t)(tp_انحراف + 0x800) >> 12;
            اگر ((off64 + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_RISCV_TPREL_HI20 relocation failed");
            write32le(ptr, (read32le(ptr) & 0xfff)
                           | ((off64 & 0xfffff) << 12));
        } ورنہ {
            write32le(ptr, (read32le(ptr) & 0xfffff)
                           | (((tp_انحراف) & 0xfff) << 20));
        }
        واپس;
    }

    طےشدہ:
        fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                type, (غیرعلامتی)addr, ptr, (غیرعلامتی)val);
        واپس;
    }
}
#اگر_ختم
