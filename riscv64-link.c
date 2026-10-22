#నిర్వచితమైతే లక్ష్యం_DEFS_ONLY

#నిర్వచించు EM_TCC_లక్ష్యం EM_RISCV

#నిర్వచించు R_దత్తాంశం_32  R_RISCV_32
#నిర్వచించు R_దత్తాంశం_PTR R_RISCV_64
#నిర్వచించు R_JMP_స్థానం R_RISCV_JUMP_స్థానం
#నిర్వచించు R_GLOB_DAT R_RISCV_64
#నిర్వచించు R_COPY     R_RISCV_COPY
#నిర్వచించు R_RELATIVE R_RISCV_RELATIVE

#నిర్వచించు R_అంకె      R_RISCV_అంకె

#నిర్వచించు ELF_ప్రారంభం_ADDR 0x00010000
#నిర్వచించు ELF_పుట_కొలత 0x1000

#నిర్వచించు PCRELATIVE_DLLPLT 1
#నిర్వచించు RELOCATE_DLLPLT 1

#లేకపోతే /* !TARGET_DEFS_ONLY */

//#define DEBUG_RELOC
#అన్తర్భావ "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC పూర్ణాంకం సంకేతం_reloc (పూర్ణాంకం reloc_type)
{
    ఎంపిక (reloc_type) {

    స్థితి R_RISCV_BRANCH:
    స్థితి R_RISCV_CALL:
    స్థితి R_RISCV_JAL:
        తిరిగి 1;

    స్థితి R_RISCV_GOT_HI20:
    స్థితి R_RISCV_PCREL_HI20:
    స్థితి R_RISCV_PCREL_LO12_I:
    స్థితి R_RISCV_PCREL_LO12_S:
    స్థితి R_RISCV_32_PCREL:
    స్థితి R_RISCV_SET6:
    స్థితి R_RISCV_SET8:
    స్థితి R_RISCV_SET16:
    స్థితి R_RISCV_SUB6:
    స్థితి R_RISCV_ADD16:
    స్థితి R_RISCV_ADD32:
    స్థితి R_RISCV_ADD64:
    స్థితి R_RISCV_SUB8:
    స్థితి R_RISCV_SUB16:
    స్థితి R_RISCV_SUB32:
    స్థితి R_RISCV_SUB64:
    స్థితి R_RISCV_32:
    స్థితి R_RISCV_64:
    స్థితి R_RISCV_సమితి_ULEB128:
    స్థితి R_RISCV_SUB_ULEB128:
    స్థితి R_RISCV_TPREL_HI20:
    స్థితి R_RISCV_TPREL_LO12_I:
        తిరిగి 0;

    స్థితి R_RISCV_CALL_PLT:
        తిరిగి 1;
    }
    తిరిగి -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC పూర్ణాంకం gotplt_నమోదు_type (పూర్ణాంకం reloc_type)
{
    ఎంపిక (reloc_type) {
    స్థితి R_RISCV_ALIGN:
    స్థితి R_RISCV_RELAX:
    స్థితి R_RISCV_RVC_BRANCH:
    స్థితి R_RISCV_RVC_JUMP:
    స్థితి R_RISCV_JUMP_స్థానం:
    స్థితి R_RISCV_SET6:
    స్థితి R_RISCV_SET8:
    స్థితి R_RISCV_SET16:
    స్థితి R_RISCV_SUB6:
    స్థితి R_RISCV_ADD16:
    స్థితి R_RISCV_SUB8:
    స్థితి R_RISCV_SUB16:
    స్థితి R_RISCV_సమితి_ULEB128:
    స్థితి R_RISCV_SUB_ULEB128:
        తిరిగి NO_GOTPLT_నమోదు;

    స్థితి R_RISCV_BRANCH:
    స్థితి R_RISCV_CALL:
    స్థితి R_RISCV_PCREL_HI20:
    స్థితి R_RISCV_PCREL_LO12_I:
    స్థితి R_RISCV_PCREL_LO12_S:
    స్థితి R_RISCV_32_PCREL:
    స్థితి R_RISCV_ADD32:
    స్థితి R_RISCV_ADD64:
    స్థితి R_RISCV_SUB32:
    స్థితి R_RISCV_SUB64:
    స్థితి R_RISCV_32:
    స్థితి R_RISCV_64:
    స్థితి R_RISCV_JAL:
    స్థితి R_RISCV_CALL_PLT:
        తిరిగి AUTO_GOTPLT_నమోదు;

    స్థితి R_RISCV_GOT_HI20:
        తిరిగి ALWAYS_GOTPLT_నమోదు;

    స్థితి R_RISCV_TPREL_HI20:
    స్థితి R_RISCV_TPREL_LO12_I:
        తిరిగి NO_GOTPLT_నమోదు;
    }
    తిరిగి -1;
}

ST_FUNC గుర్తులేని create_plt_నమోదు(TCCState *s1, గుర్తులేని got_స్థానభ్రంశం, నిర్మాణం sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    గుర్తులేని plt_స్థానభ్రంశం;

    ఒకవేళ (plt->దత్తాంశం_స్థానభ్రంశం == 0)
        section_ptr_కూడు(plt, 32);
    plt_స్థానభ్రంశం = plt->దత్తాంశం_స్థానభ్రంశం;

    p = section_ptr_కూడు(plt, 16);
    write64le(p, got_స్థానభ్రంశం);
    తిరిగి plt_స్థానభ్రంశం;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC శూన్య relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_చివర;

    ఒకవేళ (!s1->plt)
      తిరిగి;

    p = s1->plt->దత్తాంశం;
    p_చివర = p + s1->plt->దత్తాంశం_స్థానభ్రంశం;

    ఒకవేళ (p < p_చివర) {
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr;
        uint64_t off = (got - plt + 0x800) >> 12;
        ఒకవేళ ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (దీర్ఘ)off, (దీర్ఘ)got, (దీర్ఘ)plt);
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
        అయితే (p < p_చివర) {
            uint64_t pc = plt + (p - s1->plt->దత్తాంశం);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr - pc + 0x800) >> 12;
            ఒకవేళ ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (దీర్ఘ)off, (దీర్ఘ)addr, (దీర్ఘ)pc);
            write32le(p, 0xe17 | (off << 12)); // auipc t3, %pcrel_hi(func@got)
            write32le(p + 4, 0x000e3e03 // ld t3, %pcrel_lo(func@got)(t3)
                             | (((addr - pc) & 0xfff) << 20));
            write32le(p + 8, 0x000e0367); // jalr t1, t3
            write32le(p + 12, 0x00000013); // nop
            p += 16;
        }
    }

    ఒకవేళ (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->దత్తాంశం;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_స్థానభ్రంశం, s1->plt->sh_addr);
	}
    }
}

స్థిర శూన్య riscv64_రికార్డు_pcrel_hi(TCCState *s1, addr_t addr, addr_t val)
{
    నిర్మాణం pcrel_hi *entry = tcc_malloc(పరిమాణం *entry);
    entry->addr = addr;
    entry->val = val;
    dynarray_కూడు(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries, entry);
}

స్థిర పూర్ణాంకం riscv64_lookup_pcrel_hi(TCCState *s1, addr_t hi_addr, addr_t *hi_val)
{
    పూర్ణాంకం i;
    కొరకు (i = s1->nb_pcrel_hi_entries; i > 0; ) {
        నిర్మాణం pcrel_hi *entry = s1->pcrel_hi_entries[--i];
        ఒకవేళ (entry->addr == hi_addr) {
            *hi_val = entry->val;
            తిరిగి 0;
        }
    }
    తిరిగి tcc_error_noabort("unsupported hi/lo pcrel reloc scheme");
}

ST_FUNC శూన్య relocate(TCCState *s1, ElfW_Rel *rel, పూర్ణాంకం type, గుర్తులేని అక్షరం *ptr,
              addr_t addr, addr_t val)
{
    uint64_t off64;
    uint32_t off32;
    పూర్ణాంకం sym_సూచీ = ELFW(R_SYM)(rel->r_info), esym_సూచీ;
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];

    ఎంపిక(type) {
    స్థితి R_RISCV_ALIGN:
    స్థితి R_RISCV_RELAX:
        తిరిగి;

    స్థితి R_RISCV_BRANCH:
        off64 = val - addr;
        ఒకవేళ ((off64 + (1 << 12)) & ~(uint64_t)0x1ffe)
          tcc_error_noabort("R_RISCV_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (దీర్ఘ)val, (దీర్ఘ)addr);
        off32 = off64 >> 1;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0x800) << 20)
                       | ((off32 & 0x3f0) << 21)
                       | ((off32 & 0x00f) << 8)
                       | ((off32 & 0x400) >> 3));
        తిరిగి;
    స్థితి R_RISCV_JAL:
        off64 = val - addr;
        ఒకవేళ ((off64 + (1 << 21)) & ~(((uint64_t)1 << 22) - 2))
          tcc_error_noabort("R_RISCV_JAL relocation failed"
                    " (val=%lx, addr=%lx)", (దీర్ఘ)val, (దీర్ఘ)addr);
        off32 = off64;
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | (((off32 >> 12) &  0xff) << 12)
                       | (((off32 >> 11) &     1) << 20)
                       | (((off32 >>  1) & 0x3ff) << 21)
                       | (((off32 >> 20) &     1) << 31));
        తిరిగి;
    స్థితి R_RISCV_CALL:
    స్థితి R_RISCV_CALL_PLT:
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((val - addr + 0x800) & ~0xfff));
        write32le(ptr + 4, (read32le(ptr + 4) & 0xfffff)
                           | (((val - addr) & 0xfff) << 20));
        తిరిగి;
    స్థితి R_RISCV_PCREL_HI20:
#నిర్వచితమైతే DEBUG_RELOC
        రాయి("PCREL_HI20: val=%lx addr=%lx\n", (దీర్ఘ)val, (దీర్ఘ)addr);
#అయితే_ముగింపు
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        ఒకవేళ ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_PCREL_HI20 relocation failed: off=%lx cond=%lx sym=%s",
                    (దీర్ఘ)off64, (దీర్ఘ)((int64_t)(off64 + ((uint64_t)1 << 20)) >> 21),
                    symtab_section->link->దత్తాంశం + sym->st_name);
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_రికార్డు_pcrel_hi(s1, addr, val);
        తిరిగి;
    స్థితి R_RISCV_GOT_HI20:
        val = s1->got->sh_addr + get_sym_attr(s1, sym_సూచీ, 0)->got_స్థానభ్రంశం;
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        ఒకవేళ ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_GOT_HI20 relocation failed");
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_రికార్డు_pcrel_hi(s1, addr, val);
        తిరిగి;
    స్థితి R_RISCV_PCREL_LO12_I:
#నిర్వచితమైతే DEBUG_RELOC
        రాయి("PCREL_LO12_I: val=%lx addr=%lx\n", (దీర్ఘ)val, (దీర్ఘ)addr);
#అయితే_ముగింపు
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        write32le(ptr, (read32le(ptr) & 0xfffff)
                       | (((val - addr) & 0xfff) << 20));
        తిరిగి;
    స్థితి R_RISCV_PCREL_LO12_S:
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        off32 = val - addr;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0xfe0) << 20)
                       | ((off32 & 0x01f) << 7));
        తిరిగి;

    స్థితి R_RISCV_RVC_BRANCH:
        off64 = (val - addr);
        ఒకవేళ ((off64 + (1 << 8)) & ~(uint64_t)0x1fe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (దీర్ఘ)val, (దీర్ఘ)addr);
        off32 = off64;
        write16le(ptr, (read16le(ptr) & 0xe383)
                       | (((off32 >> 5) & 1) << 2)
                       | (((off32 >> 1) & 3) << 3)
                       | (((off32 >> 6) & 3) << 5)
                       | (((off32 >> 3) & 3) << 10)
                       | (((off32 >> 8) & 1) << 12));
        తిరిగి;
    స్థితి R_RISCV_RVC_JUMP:
        off64 = (val - addr);
        ఒకవేళ ((off64 + (1 << 11)) & ~(uint64_t)0xffe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (దీర్ఘ)val, (దీర్ఘ)addr);
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
        తిరిగి;

    స్థితి R_RISCV_32:
        ఒకవేళ (s1->output_type & TCC_OUTPUT_DYN) {
            /* XXX: this logic may depend on TCC's codegen
               now TCC uses R_RISCV_RELATIVE even for a 64bit pointer */
            qrel->r_స్థానభ్రంశం = rel->r_స్థానభ్రంశం;
            qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
            /* Use sign extension! */
            qrel->r_addend = (పూర్ణాంకం)read32le(ptr) + val;
            qrel++;
        }
        add32le(ptr, val);
        తిరిగి;
    స్థితి R_RISCV_64:
        ఒకవేళ (s1->output_type & TCC_OUTPUT_DYN) {
            esym_సూచీ = get_sym_attr(s1, sym_సూచీ, 0)->dyn_సూచీ;
            qrel->r_స్థానభ్రంశం = rel->r_స్థానభ్రంశం;
            ఒకవేళ (esym_సూచీ) {
                qrel->r_info = ELFW(R_INFO)(esym_సూచీ, R_RISCV_64);
                qrel->r_addend = rel->r_addend;
                qrel++;
                ఆపు;
            } లేకపోతే {
                qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
                qrel->r_addend = read64le(ptr) + val;
                qrel++;
            }
        }
    స్థితి R_RISCV_JUMP_స్థానం:
        add64le(ptr, val);
        తిరిగి;
    స్థితి R_RISCV_ADD64:
        write64le(ptr, read64le(ptr) + val);
        తిరిగి;
    స్థితి R_RISCV_ADD32:
        write32le(ptr, read32le(ptr) + val);
        తిరిగి;
    స్థితి R_RISCV_SUB64:
        write64le(ptr, read64le(ptr) - val);
        తిరిగి;
    స్థితి R_RISCV_SUB32:
        write32le(ptr, read32le(ptr) - val);
        తిరిగి;
    స్థితి R_RISCV_ADD16:
        write16le(ptr, read16le(ptr) + val);
        తిరిగి;
    స్థితి R_RISCV_SUB8:
        *ptr -= val;
        తిరిగి;
    స్థితి R_RISCV_SUB16:
        write16le(ptr, read16le(ptr) - val);
        తిరిగి;
    స్థితి R_RISCV_SET6:
        *ptr = (*ptr & ~0x3f) | (val & 0x3f);
        తిరిగి;
    స్థితి R_RISCV_SET8:
        *ptr = (*ptr & ~0xff) | (val & 0xff);
        తిరిగి;
    స్థితి R_RISCV_SET16:
        write16le(ptr, val);
        తిరిగి;
    స్థితి R_RISCV_SUB6:
        *ptr = (*ptr & ~0x3f) | ((*ptr - val) & 0x3f);
        తిరిగి;
    స్థితి R_RISCV_32_PCREL:
        ఒకవేళ (s1->output_type & TCC_OUTPUT_DYN) {
	    /* DLL relocation */
	    esym_సూచీ = get_sym_attr(s1, sym_సూచీ, 0)->dyn_సూచీ;
	    ఒకవేళ (esym_సూచీ) {
                qrel->r_స్థానభ్రంశం = rel->r_స్థానభ్రంశం;
                qrel->r_info = ELFW(R_INFO)(esym_సూచీ, R_RISCV_32_PCREL);
                /* Use sign extension! */
                qrel->r_addend = (పూర్ణాంకం)read32le(ptr) + rel->r_addend;
                qrel++;
		ఆపు;
	    }
        }
	add32le(ptr, val - addr);
        తిరిగి;
    స్థితి R_RISCV_సమితి_ULEB128:
    స్థితి R_RISCV_SUB_ULEB128:
	/* ignore. used in section .debug_loclists */
        తిరిగి;
    స్థితి R_RISCV_COPY:
        /* XXX */
        తిరిగి;
    స్థితి R_RISCV_RELATIVE:
        /* R_RISCV_RELATIVE value is already applied in R_RISCV_32/64
           dynamic output paths, but we need this case for incoming
           RELATIVE relocations from object files. */
        తిరిగి;

    స్థితి R_RISCV_TPREL_HI20:
    స్థితి R_RISCV_TPREL_LO12_I: {
        int64_t tp_స్థానభ్రంశం = val - s1->tls_ప్రారంభం;
        ఒకవేళ (type == R_RISCV_TPREL_HI20) {
            off64 = (int64_t)(tp_స్థానభ్రంశం + 0x800) >> 12;
            ఒకవేళ ((off64 + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_RISCV_TPREL_HI20 relocation failed");
            write32le(ptr, (read32le(ptr) & 0xfff)
                           | ((off64 & 0xfffff) << 12));
        } లేకపోతే {
            write32le(ptr, (read32le(ptr) & 0xfffff)
                           | (((tp_స్థానభ్రంశం) & 0xfff) << 20));
        }
        తిరిగి;
    }

    అప్రమేయ:
        fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                type, (గుర్తులేని)addr, ptr, (గుర్తులేని)val);
        తిరిగి;
    }
}
#అయితే_ముగింపు
