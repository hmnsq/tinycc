#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ಗುರಿ_DEFS_ONLY

#ವ್ಯಾಖ್ಯಾನಿಸು EM_TCC_ಗುರಿ EM_RISCV

#ವ್ಯಾಖ್ಯಾನಿಸು R_ದತ್ತಾಂಶ_32  R_RISCV_32
#ವ್ಯಾಖ್ಯಾನಿಸು R_ದತ್ತಾಂಶ_PTR R_RISCV_64
#ವ್ಯಾಖ್ಯಾನಿಸು R_JMP_ಸ್ಥಾನ R_RISCV_JUMP_ಸ್ಥಾನ
#ವ್ಯಾಖ್ಯಾನಿಸು R_GLOB_DAT R_RISCV_64
#ವ್ಯಾಖ್ಯಾನಿಸು R_COPY     R_RISCV_COPY
#ವ್ಯಾಖ್ಯಾನಿಸು R_RELATIVE R_RISCV_RELATIVE

#ವ್ಯಾಖ್ಯಾನಿಸು R_ಅಂಕೆ      R_RISCV_ಅಂಕೆ

#ವ್ಯಾಖ್ಯಾನಿಸು ELF_ಆರಂಭ_ADDR 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು ELF_ಪುಟ_ಗಾತ್ರ 0x1000

#ವ್ಯಾಖ್ಯಾನಿಸು PCRELATIVE_DLLPLT 1
#ವ್ಯಾಖ್ಯಾನಿಸು RELOCATE_DLLPLT 1

#ಇಲ್ಲದಿದ್ದರೆ /* !TARGET_DEFS_ONLY */

//#define DEBUG_RELOC
#ಅನ್ತರ್ಭಾವ "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_reloc (ಪೂರ್ಣಾಂಕ reloc_type)
{
    ಆಯ್ಕೆ (reloc_type) {

    ಸ್ಥಿತಿ R_RISCV_BRANCH:
    ಸ್ಥಿತಿ R_RISCV_CALL:
    ಸ್ಥಿತಿ R_RISCV_JAL:
        ಹಿಂತಿರುಗಿ 1;

    ಸ್ಥಿತಿ R_RISCV_GOT_HI20:
    ಸ್ಥಿತಿ R_RISCV_PCREL_HI20:
    ಸ್ಥಿತಿ R_RISCV_PCREL_LO12_I:
    ಸ್ಥಿತಿ R_RISCV_PCREL_LO12_S:
    ಸ್ಥಿತಿ R_RISCV_32_PCREL:
    ಸ್ಥಿತಿ R_RISCV_SET6:
    ಸ್ಥಿತಿ R_RISCV_SET8:
    ಸ್ಥಿತಿ R_RISCV_SET16:
    ಸ್ಥಿತಿ R_RISCV_SUB6:
    ಸ್ಥಿತಿ R_RISCV_ADD16:
    ಸ್ಥಿತಿ R_RISCV_ADD32:
    ಸ್ಥಿತಿ R_RISCV_ADD64:
    ಸ್ಥಿತಿ R_RISCV_SUB8:
    ಸ್ಥಿತಿ R_RISCV_SUB16:
    ಸ್ಥಿತಿ R_RISCV_SUB32:
    ಸ್ಥಿತಿ R_RISCV_SUB64:
    ಸ್ಥಿತಿ R_RISCV_32:
    ಸ್ಥಿತಿ R_RISCV_64:
    ಸ್ಥಿತಿ R_RISCV_ಗಣ_ULEB128:
    ಸ್ಥಿತಿ R_RISCV_SUB_ULEB128:
    ಸ್ಥಿತಿ R_RISCV_TPREL_HI20:
    ಸ್ಥಿತಿ R_RISCV_TPREL_LO12_I:
        ಹಿಂತಿರುಗಿ 0;

    ಸ್ಥಿತಿ R_RISCV_CALL_PLT:
        ಹಿಂತಿರುಗಿ 1;
    }
    ಹಿಂತಿರುಗಿ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC ಪೂರ್ಣಾಂಕ gotplt_ನಮೂದು_type (ಪೂರ್ಣಾಂಕ reloc_type)
{
    ಆಯ್ಕೆ (reloc_type) {
    ಸ್ಥಿತಿ R_RISCV_ALIGN:
    ಸ್ಥಿತಿ R_RISCV_RELAX:
    ಸ್ಥಿತಿ R_RISCV_RVC_BRANCH:
    ಸ್ಥಿತಿ R_RISCV_RVC_JUMP:
    ಸ್ಥಿತಿ R_RISCV_JUMP_ಸ್ಥಾನ:
    ಸ್ಥಿತಿ R_RISCV_SET6:
    ಸ್ಥಿತಿ R_RISCV_SET8:
    ಸ್ಥಿತಿ R_RISCV_SET16:
    ಸ್ಥಿತಿ R_RISCV_SUB6:
    ಸ್ಥಿತಿ R_RISCV_ADD16:
    ಸ್ಥಿತಿ R_RISCV_SUB8:
    ಸ್ಥಿತಿ R_RISCV_SUB16:
    ಸ್ಥಿತಿ R_RISCV_ಗಣ_ULEB128:
    ಸ್ಥಿತಿ R_RISCV_SUB_ULEB128:
        ಹಿಂತಿರುಗಿ NO_GOTPLT_ನಮೂದು;

    ಸ್ಥಿತಿ R_RISCV_BRANCH:
    ಸ್ಥಿತಿ R_RISCV_CALL:
    ಸ್ಥಿತಿ R_RISCV_PCREL_HI20:
    ಸ್ಥಿತಿ R_RISCV_PCREL_LO12_I:
    ಸ್ಥಿತಿ R_RISCV_PCREL_LO12_S:
    ಸ್ಥಿತಿ R_RISCV_32_PCREL:
    ಸ್ಥಿತಿ R_RISCV_ADD32:
    ಸ್ಥಿತಿ R_RISCV_ADD64:
    ಸ್ಥಿತಿ R_RISCV_SUB32:
    ಸ್ಥಿತಿ R_RISCV_SUB64:
    ಸ್ಥಿತಿ R_RISCV_32:
    ಸ್ಥಿತಿ R_RISCV_64:
    ಸ್ಥಿತಿ R_RISCV_JAL:
    ಸ್ಥಿತಿ R_RISCV_CALL_PLT:
        ಹಿಂತಿರುಗಿ AUTO_GOTPLT_ನಮೂದು;

    ಸ್ಥಿತಿ R_RISCV_GOT_HI20:
        ಹಿಂತಿರುಗಿ ALWAYS_GOTPLT_ನಮೂದು;

    ಸ್ಥಿತಿ R_RISCV_TPREL_HI20:
    ಸ್ಥಿತಿ R_RISCV_TPREL_LO12_I:
        ಹಿಂತಿರುಗಿ NO_GOTPLT_ನಮೂದು;
    }
    ಹಿಂತಿರುಗಿ -1;
}

ST_FUNC ಚಿಹ್ನೆರಹಿತ create_plt_ನಮೂದು(TCCState *s1, ಚಿಹ್ನೆರಹಿತ got_ಸ್ಥಾನಾಂತರ, ರಚನೆ sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    ಚಿಹ್ನೆರಹಿತ plt_ಸ್ಥಾನಾಂತರ;

    ಆದರೆ (plt->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ == 0)
        section_ptr_ಕೂಡಿಸು(plt, 32);
    plt_ಸ್ಥಾನಾಂತರ = plt->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

    p = section_ptr_ಕೂಡಿಸು(plt, 16);
    write64le(p, got_ಸ್ಥಾನಾಂತರ);
    ಹಿಂತಿರುಗಿ plt_ಸ್ಥಾನಾಂತರ;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC ಶೂನ್ಯ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_ಕೊನೆ;

    ಆದರೆ (!s1->plt)
      ಹಿಂತಿರುಗಿ;

    p = s1->plt->ದತ್ತಾಂಶ;
    p_ಕೊನೆ = p + s1->plt->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

    ಆದರೆ (p < p_ಕೊನೆ) {
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr;
        uint64_t off = (got - plt + 0x800) >> 12;
        ಆದರೆ ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (ದೀರ್ಘ)off, (ದೀರ್ಘ)got, (ದೀರ್ಘ)plt);
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
        ಆಗ (p < p_ಕೊನೆ) {
            uint64_t pc = plt + (p - s1->plt->ದತ್ತಾಂಶ);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr - pc + 0x800) >> 12;
            ಆದರೆ ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (ದೀರ್ಘ)off, (ದೀರ್ಘ)addr, (ದೀರ್ಘ)pc);
            write32le(p, 0xe17 | (off << 12)); // auipc t3, %pcrel_hi(func@got)
            write32le(p + 4, 0x000e3e03 // ld t3, %pcrel_lo(func@got)(t3)
                             | (((addr - pc) & 0xfff) << 20));
            write32le(p + 8, 0x000e0367); // jalr t1, t3
            write32le(p + 12, 0x00000013); // nop
            p += 16;
        }
    }

    ಆದರೆ (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->ದತ್ತಾಂಶ;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_ಸ್ಥಾನಾಂತರ, s1->plt->sh_addr);
	}
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ riscv64_ದಾಖಲೆ_pcrel_hi(TCCState *s1, addr_t addr, addr_t val)
{
    ರಚನೆ pcrel_hi *entry = tcc_malloc(ಗಾತ್ರ *entry);
    entry->addr = addr;
    entry->val = val;
    dynarray_ಕೂಡಿಸು(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries, entry);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ riscv64_lookup_pcrel_hi(TCCState *s1, addr_t hi_addr, addr_t *hi_val)
{
    ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ (i = s1->nb_pcrel_hi_entries; i > 0; ) {
        ರಚನೆ pcrel_hi *entry = s1->pcrel_hi_entries[--i];
        ಆದರೆ (entry->addr == hi_addr) {
            *hi_val = entry->val;
            ಹಿಂತಿರುಗಿ 0;
        }
    }
    ಹಿಂತಿರುಗಿ tcc_error_noabort("unsupported hi/lo pcrel reloc scheme");
}

ST_FUNC ಶೂನ್ಯ relocate(TCCState *s1, ElfW_Rel *rel, ಪೂರ್ಣಾಂಕ type, ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr,
              addr_t addr, addr_t val)
{
    uint64_t off64;
    uint32_t off32;
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(rel->r_info), esym_ಸೂಚ್ಯಂಕ;
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];

    ಆಯ್ಕೆ(type) {
    ಸ್ಥಿತಿ R_RISCV_ALIGN:
    ಸ್ಥಿತಿ R_RISCV_RELAX:
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ R_RISCV_BRANCH:
        off64 = val - addr;
        ಆದರೆ ((off64 + (1 << 12)) & ~(uint64_t)0x1ffe)
          tcc_error_noabort("R_RISCV_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (ದೀರ್ಘ)val, (ದೀರ್ಘ)addr);
        off32 = off64 >> 1;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0x800) << 20)
                       | ((off32 & 0x3f0) << 21)
                       | ((off32 & 0x00f) << 8)
                       | ((off32 & 0x400) >> 3));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_JAL:
        off64 = val - addr;
        ಆದರೆ ((off64 + (1 << 21)) & ~(((uint64_t)1 << 22) - 2))
          tcc_error_noabort("R_RISCV_JAL relocation failed"
                    " (val=%lx, addr=%lx)", (ದೀರ್ಘ)val, (ದೀರ್ಘ)addr);
        off32 = off64;
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | (((off32 >> 12) &  0xff) << 12)
                       | (((off32 >> 11) &     1) << 20)
                       | (((off32 >>  1) & 0x3ff) << 21)
                       | (((off32 >> 20) &     1) << 31));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_CALL:
    ಸ್ಥಿತಿ R_RISCV_CALL_PLT:
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((val - addr + 0x800) & ~0xfff));
        write32le(ptr + 4, (read32le(ptr + 4) & 0xfffff)
                           | (((val - addr) & 0xfff) << 20));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_PCREL_HI20:
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ DEBUG_RELOC
        ಬರೆ("PCREL_HI20: val=%lx addr=%lx\n", (ದೀರ್ಘ)val, (ದೀರ್ಘ)addr);
#ಆದರೆ_ಅಂತ್ಯ
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        ಆದರೆ ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_PCREL_HI20 relocation failed: off=%lx cond=%lx sym=%s",
                    (ದೀರ್ಘ)off64, (ದೀರ್ಘ)((int64_t)(off64 + ((uint64_t)1 << 20)) >> 21),
                    symtab_section->link->ದತ್ತಾಂಶ + sym->st_name);
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_ದಾಖಲೆ_pcrel_hi(s1, addr, val);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_GOT_HI20:
        val = s1->got->sh_addr + get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->got_ಸ್ಥಾನಾಂತರ;
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        ಆದರೆ ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_GOT_HI20 relocation failed");
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_ದಾಖಲೆ_pcrel_hi(s1, addr, val);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_PCREL_LO12_I:
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ DEBUG_RELOC
        ಬರೆ("PCREL_LO12_I: val=%lx addr=%lx\n", (ದೀರ್ಘ)val, (ದೀರ್ಘ)addr);
#ಆದರೆ_ಅಂತ್ಯ
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        write32le(ptr, (read32le(ptr) & 0xfffff)
                       | (((val - addr) & 0xfff) << 20));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_PCREL_LO12_S:
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        off32 = val - addr;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0xfe0) << 20)
                       | ((off32 & 0x01f) << 7));
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ R_RISCV_RVC_BRANCH:
        off64 = (val - addr);
        ಆದರೆ ((off64 + (1 << 8)) & ~(uint64_t)0x1fe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (ದೀರ್ಘ)val, (ದೀರ್ಘ)addr);
        off32 = off64;
        write16le(ptr, (read16le(ptr) & 0xe383)
                       | (((off32 >> 5) & 1) << 2)
                       | (((off32 >> 1) & 3) << 3)
                       | (((off32 >> 6) & 3) << 5)
                       | (((off32 >> 3) & 3) << 10)
                       | (((off32 >> 8) & 1) << 12));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_RVC_JUMP:
        off64 = (val - addr);
        ಆದರೆ ((off64 + (1 << 11)) & ~(uint64_t)0xffe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (ದೀರ್ಘ)val, (ದೀರ್ಘ)addr);
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
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ R_RISCV_32:
        ಆದರೆ (s1->output_type & TCC_OUTPUT_DYN) {
            /* XXX: this logic may depend on TCC's codegen
               now TCC uses R_RISCV_RELATIVE even for a 64bit pointer */
            qrel->r_ಸ್ಥಾನಾಂತರ = rel->r_ಸ್ಥಾನಾಂತರ;
            qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
            /* Use sign extension! */
            qrel->r_addend = (ಪೂರ್ಣಾಂಕ)read32le(ptr) + val;
            qrel++;
        }
        add32le(ptr, val);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_64:
        ಆದರೆ (s1->output_type & TCC_OUTPUT_DYN) {
            esym_ಸೂಚ್ಯಂಕ = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->dyn_ಸೂಚ್ಯಂಕ;
            qrel->r_ಸ್ಥಾನಾಂತರ = rel->r_ಸ್ಥಾನಾಂತರ;
            ಆದರೆ (esym_ಸೂಚ್ಯಂಕ) {
                qrel->r_info = ELFW(R_INFO)(esym_ಸೂಚ್ಯಂಕ, R_RISCV_64);
                qrel->r_addend = rel->r_addend;
                qrel++;
                ನಿಲ್ಲಿಸು;
            } ಇಲ್ಲದಿದ್ದರೆ {
                qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
                qrel->r_addend = read64le(ptr) + val;
                qrel++;
            }
        }
    ಸ್ಥಿತಿ R_RISCV_JUMP_ಸ್ಥಾನ:
        add64le(ptr, val);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_ADD64:
        write64le(ptr, read64le(ptr) + val);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_ADD32:
        write32le(ptr, read32le(ptr) + val);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_SUB64:
        write64le(ptr, read64le(ptr) - val);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_SUB32:
        write32le(ptr, read32le(ptr) - val);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_ADD16:
        write16le(ptr, read16le(ptr) + val);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_SUB8:
        *ptr -= val;
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_SUB16:
        write16le(ptr, read16le(ptr) - val);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_SET6:
        *ptr = (*ptr & ~0x3f) | (val & 0x3f);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_SET8:
        *ptr = (*ptr & ~0xff) | (val & 0xff);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_SET16:
        write16le(ptr, val);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_SUB6:
        *ptr = (*ptr & ~0x3f) | ((*ptr - val) & 0x3f);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_32_PCREL:
        ಆದರೆ (s1->output_type & TCC_OUTPUT_DYN) {
	    /* DLL relocation */
	    esym_ಸೂಚ್ಯಂಕ = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->dyn_ಸೂಚ್ಯಂಕ;
	    ಆದರೆ (esym_ಸೂಚ್ಯಂಕ) {
                qrel->r_ಸ್ಥಾನಾಂತರ = rel->r_ಸ್ಥಾನಾಂತರ;
                qrel->r_info = ELFW(R_INFO)(esym_ಸೂಚ್ಯಂಕ, R_RISCV_32_PCREL);
                /* Use sign extension! */
                qrel->r_addend = (ಪೂರ್ಣಾಂಕ)read32le(ptr) + rel->r_addend;
                qrel++;
		ನಿಲ್ಲಿಸು;
	    }
        }
	add32le(ptr, val - addr);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_ಗಣ_ULEB128:
    ಸ್ಥಿತಿ R_RISCV_SUB_ULEB128:
	/* ignore. used in section .debug_loclists */
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_COPY:
        /* XXX */
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ R_RISCV_RELATIVE:
        /* R_RISCV_RELATIVE value is already applied in R_RISCV_32/64
           dynamic output paths, but we need this case for incoming
           RELATIVE relocations from object files. */
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ R_RISCV_TPREL_HI20:
    ಸ್ಥಿತಿ R_RISCV_TPREL_LO12_I: {
        int64_t tp_ಸ್ಥಾನಾಂತರ = val - s1->tls_ಆರಂಭ;
        ಆದರೆ (type == R_RISCV_TPREL_HI20) {
            off64 = (int64_t)(tp_ಸ್ಥಾನಾಂತರ + 0x800) >> 12;
            ಆದರೆ ((off64 + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_RISCV_TPREL_HI20 relocation failed");
            write32le(ptr, (read32le(ptr) & 0xfff)
                           | ((off64 & 0xfffff) << 12));
        } ಇಲ್ಲದಿದ್ದರೆ {
            write32le(ptr, (read32le(ptr) & 0xfffff)
                           | (((tp_ಸ್ಥಾನಾಂತರ) & 0xfff) << 20));
        }
        ಹಿಂತಿರುಗಿ;
    }

    ಪೂರ್ವನಿಯೋಜಿತ:
        fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                type, (ಚಿಹ್ನೆರಹಿತ)addr, ptr, (ಚಿಹ್ನೆರಹಿತ)val);
        ಹಿಂತಿರುಗಿ;
    }
}
#ಆದರೆ_ಅಂತ್ಯ
