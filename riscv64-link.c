#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ਨਿਸ਼ਾਨਾ_DEFS_ONLY

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_TCC_ਨਿਸ਼ਾਨਾ EM_RISCV

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕੜੇ_32  R_RISCV_32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕੜੇ_PTR R_RISCV_64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_JMP_ਥਾਂ R_RISCV_JUMP_ਥਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_GLOB_DAT R_RISCV_64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_COPY     R_RISCV_COPY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_RELATIVE R_RISCV_RELATIVE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕ      R_RISCV_ਅੰਕ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_ਸ਼ੁਰੂ_ADDR 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_ਪੰਨਾ_ਮਾਪ 0x1000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCRELATIVE_DLLPLT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RELOCATE_DLLPLT 1

#ਨਹੀਂਤਾਂ /* !TARGET_DEFS_ONLY */

//#define DEBUG_RELOC
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ਪੂਰਨ ਕੋਡ_reloc (ਪੂਰਨ reloc_type)
{
    ਚੋਣ (reloc_type) {

    ਹਾਲਤ R_RISCV_BRANCH:
    ਹਾਲਤ R_RISCV_CALL:
    ਹਾਲਤ R_RISCV_JAL:
        ਵਾਪਸ 1;

    ਹਾਲਤ R_RISCV_GOT_HI20:
    ਹਾਲਤ R_RISCV_PCREL_HI20:
    ਹਾਲਤ R_RISCV_PCREL_LO12_I:
    ਹਾਲਤ R_RISCV_PCREL_LO12_S:
    ਹਾਲਤ R_RISCV_32_PCREL:
    ਹਾਲਤ R_RISCV_SET6:
    ਹਾਲਤ R_RISCV_SET8:
    ਹਾਲਤ R_RISCV_SET16:
    ਹਾਲਤ R_RISCV_SUB6:
    ਹਾਲਤ R_RISCV_ADD16:
    ਹਾਲਤ R_RISCV_ADD32:
    ਹਾਲਤ R_RISCV_ADD64:
    ਹਾਲਤ R_RISCV_SUB8:
    ਹਾਲਤ R_RISCV_SUB16:
    ਹਾਲਤ R_RISCV_SUB32:
    ਹਾਲਤ R_RISCV_SUB64:
    ਹਾਲਤ R_RISCV_32:
    ਹਾਲਤ R_RISCV_64:
    ਹਾਲਤ R_RISCV_ਸੈੱਟ_ULEB128:
    ਹਾਲਤ R_RISCV_SUB_ULEB128:
    ਹਾਲਤ R_RISCV_TPREL_HI20:
    ਹਾਲਤ R_RISCV_TPREL_LO12_I:
        ਵਾਪਸ 0;

    ਹਾਲਤ R_RISCV_CALL_PLT:
        ਵਾਪਸ 1;
    }
    ਵਾਪਸ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC ਪੂਰਨ gotplt_ਇੰਦਰਾਜ_type (ਪੂਰਨ reloc_type)
{
    ਚੋਣ (reloc_type) {
    ਹਾਲਤ R_RISCV_ALIGN:
    ਹਾਲਤ R_RISCV_RELAX:
    ਹਾਲਤ R_RISCV_RVC_BRANCH:
    ਹਾਲਤ R_RISCV_RVC_JUMP:
    ਹਾਲਤ R_RISCV_JUMP_ਥਾਂ:
    ਹਾਲਤ R_RISCV_SET6:
    ਹਾਲਤ R_RISCV_SET8:
    ਹਾਲਤ R_RISCV_SET16:
    ਹਾਲਤ R_RISCV_SUB6:
    ਹਾਲਤ R_RISCV_ADD16:
    ਹਾਲਤ R_RISCV_SUB8:
    ਹਾਲਤ R_RISCV_SUB16:
    ਹਾਲਤ R_RISCV_ਸੈੱਟ_ULEB128:
    ਹਾਲਤ R_RISCV_SUB_ULEB128:
        ਵਾਪਸ NO_GOTPLT_ਇੰਦਰਾਜ;

    ਹਾਲਤ R_RISCV_BRANCH:
    ਹਾਲਤ R_RISCV_CALL:
    ਹਾਲਤ R_RISCV_PCREL_HI20:
    ਹਾਲਤ R_RISCV_PCREL_LO12_I:
    ਹਾਲਤ R_RISCV_PCREL_LO12_S:
    ਹਾਲਤ R_RISCV_32_PCREL:
    ਹਾਲਤ R_RISCV_ADD32:
    ਹਾਲਤ R_RISCV_ADD64:
    ਹਾਲਤ R_RISCV_SUB32:
    ਹਾਲਤ R_RISCV_SUB64:
    ਹਾਲਤ R_RISCV_32:
    ਹਾਲਤ R_RISCV_64:
    ਹਾਲਤ R_RISCV_JAL:
    ਹਾਲਤ R_RISCV_CALL_PLT:
        ਵਾਪਸ AUTO_GOTPLT_ਇੰਦਰਾਜ;

    ਹਾਲਤ R_RISCV_GOT_HI20:
        ਵਾਪਸ ALWAYS_GOTPLT_ਇੰਦਰਾਜ;

    ਹਾਲਤ R_RISCV_TPREL_HI20:
    ਹਾਲਤ R_RISCV_TPREL_LO12_I:
        ਵਾਪਸ NO_GOTPLT_ਇੰਦਰਾਜ;
    }
    ਵਾਪਸ -1;
}

ST_FUNC ਬਿਨਾਨਿਸ਼ਾਨੀ create_plt_ਇੰਦਰਾਜ(TCCState *s1, ਬਿਨਾਨਿਸ਼ਾਨੀ got_ਵਿੱਥ, ਬਣਤਰ sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    ਬਿਨਾਨਿਸ਼ਾਨੀ plt_ਵਿੱਥ;

    ਜੇ (plt->ਅੰਕੜੇ_ਵਿੱਥ == 0)
        section_ptr_ਜੋੜੋ(plt, 32);
    plt_ਵਿੱਥ = plt->ਅੰਕੜੇ_ਵਿੱਥ;

    p = section_ptr_ਜੋੜੋ(plt, 16);
    write64le(p, got_ਵਿੱਥ);
    ਵਾਪਸ plt_ਵਿੱਥ;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC ਖਾਲੀ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_ਸਿਰਾ;

    ਜੇ (!s1->plt)
      ਵਾਪਸ;

    p = s1->plt->ਅੰਕੜੇ;
    p_ਸਿਰਾ = p + s1->plt->ਅੰਕੜੇ_ਵਿੱਥ;

    ਜੇ (p < p_ਸਿਰਾ) {
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr;
        uint64_t off = (got - plt + 0x800) >> 12;
        ਜੇ ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (ਲੰਮਾ)off, (ਲੰਮਾ)got, (ਲੰਮਾ)plt);
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
        ਜਦੋਂ (p < p_ਸਿਰਾ) {
            uint64_t pc = plt + (p - s1->plt->ਅੰਕੜੇ);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr - pc + 0x800) >> 12;
            ਜੇ ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (ਲੰਮਾ)off, (ਲੰਮਾ)addr, (ਲੰਮਾ)pc);
            write32le(p, 0xe17 | (off << 12)); // auipc t3, %pcrel_hi(func@got)
            write32le(p + 4, 0x000e3e03 // ld t3, %pcrel_lo(func@got)(t3)
                             | (((addr - pc) & 0xfff) << 20));
            write32le(p + 8, 0x000e0367); // jalr t1, t3
            write32le(p + 12, 0x00000013); // nop
            p += 16;
        }
    }

    ਜੇ (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->ਅੰਕੜੇ;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_ਵਿੱਥ, s1->plt->sh_addr);
	}
    }
}

ਸਥਿਰ ਖਾਲੀ riscv64_ਰਿਕਾਰਡ_pcrel_hi(TCCState *s1, addr_t addr, addr_t val)
{
    ਬਣਤਰ pcrel_hi *entry = tcc_malloc(ਆਕਾਰ *entry);
    entry->addr = addr;
    entry->val = val;
    dynarray_ਜੋੜੋ(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries, entry);
}

ਸਥਿਰ ਪੂਰਨ riscv64_lookup_pcrel_hi(TCCState *s1, addr_t hi_addr, addr_t *hi_val)
{
    ਪੂਰਨ i;
    ਲਈ (i = s1->nb_pcrel_hi_entries; i > 0; ) {
        ਬਣਤਰ pcrel_hi *entry = s1->pcrel_hi_entries[--i];
        ਜੇ (entry->addr == hi_addr) {
            *hi_val = entry->val;
            ਵਾਪਸ 0;
        }
    }
    ਵਾਪਸ tcc_error_noabort("unsupported hi/lo pcrel reloc scheme");
}

ST_FUNC ਖਾਲੀ relocate(TCCState *s1, ElfW_Rel *rel, ਪੂਰਨ type, ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr,
              addr_t addr, addr_t val)
{
    uint64_t off64;
    uint32_t off32;
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(rel->r_info), esym_ਸੂਚਕਾਂਕ;
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];

    ਚੋਣ(type) {
    ਹਾਲਤ R_RISCV_ALIGN:
    ਹਾਲਤ R_RISCV_RELAX:
        ਵਾਪਸ;

    ਹਾਲਤ R_RISCV_BRANCH:
        off64 = val - addr;
        ਜੇ ((off64 + (1 << 12)) & ~(uint64_t)0x1ffe)
          tcc_error_noabort("R_RISCV_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (ਲੰਮਾ)val, (ਲੰਮਾ)addr);
        off32 = off64 >> 1;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0x800) << 20)
                       | ((off32 & 0x3f0) << 21)
                       | ((off32 & 0x00f) << 8)
                       | ((off32 & 0x400) >> 3));
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_JAL:
        off64 = val - addr;
        ਜੇ ((off64 + (1 << 21)) & ~(((uint64_t)1 << 22) - 2))
          tcc_error_noabort("R_RISCV_JAL relocation failed"
                    " (val=%lx, addr=%lx)", (ਲੰਮਾ)val, (ਲੰਮਾ)addr);
        off32 = off64;
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | (((off32 >> 12) &  0xff) << 12)
                       | (((off32 >> 11) &     1) << 20)
                       | (((off32 >>  1) & 0x3ff) << 21)
                       | (((off32 >> 20) &     1) << 31));
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_CALL:
    ਹਾਲਤ R_RISCV_CALL_PLT:
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((val - addr + 0x800) & ~0xfff));
        write32le(ptr + 4, (read32le(ptr + 4) & 0xfffff)
                           | (((val - addr) & 0xfff) << 20));
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_PCREL_HI20:
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ DEBUG_RELOC
        ਲਿਖੋ("PCREL_HI20: val=%lx addr=%lx\n", (ਲੰਮਾ)val, (ਲੰਮਾ)addr);
#ਜੇ_ਅੰਤ
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        ਜੇ ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_PCREL_HI20 relocation failed: off=%lx cond=%lx sym=%s",
                    (ਲੰਮਾ)off64, (ਲੰਮਾ)((int64_t)(off64 + ((uint64_t)1 << 20)) >> 21),
                    symtab_section->link->ਅੰਕੜੇ + sym->st_name);
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_ਰਿਕਾਰਡ_pcrel_hi(s1, addr, val);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_GOT_HI20:
        val = s1->got->sh_addr + get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->got_ਵਿੱਥ;
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        ਜੇ ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_GOT_HI20 relocation failed");
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_ਰਿਕਾਰਡ_pcrel_hi(s1, addr, val);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_PCREL_LO12_I:
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ DEBUG_RELOC
        ਲਿਖੋ("PCREL_LO12_I: val=%lx addr=%lx\n", (ਲੰਮਾ)val, (ਲੰਮਾ)addr);
#ਜੇ_ਅੰਤ
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        write32le(ptr, (read32le(ptr) & 0xfffff)
                       | (((val - addr) & 0xfff) << 20));
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_PCREL_LO12_S:
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        off32 = val - addr;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0xfe0) << 20)
                       | ((off32 & 0x01f) << 7));
        ਵਾਪਸ;

    ਹਾਲਤ R_RISCV_RVC_BRANCH:
        off64 = (val - addr);
        ਜੇ ((off64 + (1 << 8)) & ~(uint64_t)0x1fe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (ਲੰਮਾ)val, (ਲੰਮਾ)addr);
        off32 = off64;
        write16le(ptr, (read16le(ptr) & 0xe383)
                       | (((off32 >> 5) & 1) << 2)
                       | (((off32 >> 1) & 3) << 3)
                       | (((off32 >> 6) & 3) << 5)
                       | (((off32 >> 3) & 3) << 10)
                       | (((off32 >> 8) & 1) << 12));
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_RVC_JUMP:
        off64 = (val - addr);
        ਜੇ ((off64 + (1 << 11)) & ~(uint64_t)0xffe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (ਲੰਮਾ)val, (ਲੰਮਾ)addr);
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
        ਵਾਪਸ;

    ਹਾਲਤ R_RISCV_32:
        ਜੇ (s1->output_type & TCC_OUTPUT_DYN) {
            /* XXX: this logic may depend on TCC's codegen
               now TCC uses R_RISCV_RELATIVE even for a 64bit pointer */
            qrel->r_ਵਿੱਥ = rel->r_ਵਿੱਥ;
            qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
            /* Use sign extension! */
            qrel->r_addend = (ਪੂਰਨ)read32le(ptr) + val;
            qrel++;
        }
        add32le(ptr, val);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_64:
        ਜੇ (s1->output_type & TCC_OUTPUT_DYN) {
            esym_ਸੂਚਕਾਂਕ = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->dyn_ਸੂਚਕਾਂਕ;
            qrel->r_ਵਿੱਥ = rel->r_ਵਿੱਥ;
            ਜੇ (esym_ਸੂਚਕਾਂਕ) {
                qrel->r_info = ELFW(R_INFO)(esym_ਸੂਚਕਾਂਕ, R_RISCV_64);
                qrel->r_addend = rel->r_addend;
                qrel++;
                ਰੋਕੋ;
            } ਨਹੀਂਤਾਂ {
                qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
                qrel->r_addend = read64le(ptr) + val;
                qrel++;
            }
        }
    ਹਾਲਤ R_RISCV_JUMP_ਥਾਂ:
        add64le(ptr, val);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_ADD64:
        write64le(ptr, read64le(ptr) + val);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_ADD32:
        write32le(ptr, read32le(ptr) + val);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_SUB64:
        write64le(ptr, read64le(ptr) - val);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_SUB32:
        write32le(ptr, read32le(ptr) - val);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_ADD16:
        write16le(ptr, read16le(ptr) + val);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_SUB8:
        *ptr -= val;
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_SUB16:
        write16le(ptr, read16le(ptr) - val);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_SET6:
        *ptr = (*ptr & ~0x3f) | (val & 0x3f);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_SET8:
        *ptr = (*ptr & ~0xff) | (val & 0xff);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_SET16:
        write16le(ptr, val);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_SUB6:
        *ptr = (*ptr & ~0x3f) | ((*ptr - val) & 0x3f);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_32_PCREL:
        ਜੇ (s1->output_type & TCC_OUTPUT_DYN) {
	    /* DLL relocation */
	    esym_ਸੂਚਕਾਂਕ = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->dyn_ਸੂਚਕਾਂਕ;
	    ਜੇ (esym_ਸੂਚਕਾਂਕ) {
                qrel->r_ਵਿੱਥ = rel->r_ਵਿੱਥ;
                qrel->r_info = ELFW(R_INFO)(esym_ਸੂਚਕਾਂਕ, R_RISCV_32_PCREL);
                /* Use sign extension! */
                qrel->r_addend = (ਪੂਰਨ)read32le(ptr) + rel->r_addend;
                qrel++;
		ਰੋਕੋ;
	    }
        }
	add32le(ptr, val - addr);
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_ਸੈੱਟ_ULEB128:
    ਹਾਲਤ R_RISCV_SUB_ULEB128:
	/* ignore. used in section .debug_loclists */
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_COPY:
        /* XXX */
        ਵਾਪਸ;
    ਹਾਲਤ R_RISCV_RELATIVE:
        /* R_RISCV_RELATIVE value is already applied in R_RISCV_32/64
           dynamic output paths, but we need this case for incoming
           RELATIVE relocations from object files. */
        ਵਾਪਸ;

    ਹਾਲਤ R_RISCV_TPREL_HI20:
    ਹਾਲਤ R_RISCV_TPREL_LO12_I: {
        int64_t tp_ਵਿੱਥ = val - s1->tls_ਸ਼ੁਰੂ;
        ਜੇ (type == R_RISCV_TPREL_HI20) {
            off64 = (int64_t)(tp_ਵਿੱਥ + 0x800) >> 12;
            ਜੇ ((off64 + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_RISCV_TPREL_HI20 relocation failed");
            write32le(ptr, (read32le(ptr) & 0xfff)
                           | ((off64 & 0xfffff) << 12));
        } ਨਹੀਂਤਾਂ {
            write32le(ptr, (read32le(ptr) & 0xfffff)
                           | (((tp_ਵਿੱਥ) & 0xfff) << 20));
        }
        ਵਾਪਸ;
    }

    ਮੂਲ:
        fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                type, (ਬਿਨਾਨਿਸ਼ਾਨੀ)addr, ptr, (ਬਿਨਾਨਿਸ਼ਾਨੀ)val);
        ਵਾਪਸ;
    }
}
#ਜੇ_ਅੰਤ
