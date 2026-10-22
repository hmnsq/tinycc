#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_RISCV

#define R_DATA_32  R_RISCV_32
#define R_DATA_PTR R_RISCV_64
#define R_JMP_SLOT R_RISCV_JUMP_SLOT
#define R_GLOB_DAT R_RISCV_64
#define R_COPY     R_RISCV_COPY
#define R_RELATIVE R_RISCV_RELATIVE

#define R_NUM      R_RISCV_NUM

#define ELF_START_ADDR 0x00010000
#define ELF_PAGE_SIZE 0x1000

#define PCRELATIVE_DLLPLT 1
#define RELOCATE_DLLPLT 1

#ᮜᮤᮚ /* !TARGET_DEFS_ONLY */

//#define DEBUG_RELOC
#include "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC puur_naa_nka code_reloc (puur_naa_nka reloc_type)
{
    switch (reloc_type) {

    pak_sa R_RISCV_BRANCH:
    pak_sa R_RISCV_CALL:
    pak_sa R_RISCV_JAL:
        ᮝᮜᮤ 1;

    pak_sa R_RISCV_GOT_HI20:
    pak_sa R_RISCV_PCREL_HI20:
    pak_sa R_RISCV_PCREL_LO12_I:
    pak_sa R_RISCV_PCREL_LO12_S:
    pak_sa R_RISCV_32_PCREL:
    pak_sa R_RISCV_SET6:
    pak_sa R_RISCV_SET8:
    pak_sa R_RISCV_SET16:
    pak_sa R_RISCV_SUB6:
    pak_sa R_RISCV_ADD16:
    pak_sa R_RISCV_ADD32:
    pak_sa R_RISCV_ADD64:
    pak_sa R_RISCV_SUB8:
    pak_sa R_RISCV_SUB16:
    pak_sa R_RISCV_SUB32:
    pak_sa R_RISCV_SUB64:
    pak_sa R_RISCV_32:
    pak_sa R_RISCV_64:
    pak_sa R_RISCV_SET_ULEB128:
    pak_sa R_RISCV_SUB_ULEB128:
    pak_sa R_RISCV_TPREL_HI20:
    pak_sa R_RISCV_TPREL_LO12_I:
        ᮝᮜᮤ 0;

    pak_sa R_RISCV_CALL_PLT:
        ᮝᮜᮤ 1;
    }
    ᮝᮜᮤ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC puur_naa_nka gotplt_entry_type (puur_naa_nka reloc_type)
{
    switch (reloc_type) {
    pak_sa R_RISCV_ALIGN:
    pak_sa R_RISCV_RELAX:
    pak_sa R_RISCV_RVC_BRANCH:
    pak_sa R_RISCV_RVC_JUMP:
    pak_sa R_RISCV_JUMP_SLOT:
    pak_sa R_RISCV_SET6:
    pak_sa R_RISCV_SET8:
    pak_sa R_RISCV_SET16:
    pak_sa R_RISCV_SUB6:
    pak_sa R_RISCV_ADD16:
    pak_sa R_RISCV_SUB8:
    pak_sa R_RISCV_SUB16:
    pak_sa R_RISCV_SET_ULEB128:
    pak_sa R_RISCV_SUB_ULEB128:
        ᮝᮜᮤ NO_GOTPLT_ENTRY;

    pak_sa R_RISCV_BRANCH:
    pak_sa R_RISCV_CALL:
    pak_sa R_RISCV_PCREL_HI20:
    pak_sa R_RISCV_PCREL_LO12_I:
    pak_sa R_RISCV_PCREL_LO12_S:
    pak_sa R_RISCV_32_PCREL:
    pak_sa R_RISCV_ADD32:
    pak_sa R_RISCV_ADD64:
    pak_sa R_RISCV_SUB32:
    pak_sa R_RISCV_SUB64:
    pak_sa R_RISCV_32:
    pak_sa R_RISCV_64:
    pak_sa R_RISCV_JAL:
    pak_sa R_RISCV_CALL_PLT:
        ᮝᮜᮤ AUTO_GOTPLT_ENTRY;

    pak_sa R_RISCV_GOT_HI20:
        ᮝᮜᮤ ALWAYS_GOTPLT_ENTRY;

    pak_sa R_RISCV_TPREL_HI20:
    pak_sa R_RISCV_TPREL_LO12_I:
        ᮝᮜᮤ NO_GOTPLT_ENTRY;
    }
    ᮝᮜᮤ -1;
}

ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, sa_nracanaa sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    unsigned plt_offset;

    ᮚᮦᮔ᮪ (plt->data_offset == 0)
        section_ptr_add(plt, 32);
    plt_offset = plt->data_offset;

    p = section_ptr_add(plt, 16);
    write64le(p, got_offset);
    ᮝᮜᮤ plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC void relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    ᮚᮦᮔ᮪ (!s1->plt)
      ᮝᮜᮤ;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    ᮚᮦᮔ᮪ (p < p_end) {
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr;
        uint64_t off = (got - plt + 0x800) >> 12;
        ᮚᮦᮔ᮪ ((off + ((uint32_t)1 << 20)) >> 21)
            tcc_error_noabort("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", (long)off, (long)got, (long)plt);
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
        ᮞᮨᮓᮨᮜ (p < p_end) {
            uint64_t pc = plt + (p - s1->plt->data);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr - pc + 0x800) >> 12;
            ᮚᮦᮔ᮪ ((off + ((uint32_t)1 << 20)) >> 21)
                tcc_error_noabort("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", (long)off, (long)addr, (long)pc);
            write32le(p, 0xe17 | (off << 12)); // auipc t3, %pcrel_hi(func@got)
            write32le(p + 4, 0x000e3e03 // ld t3, %pcrel_lo(func@got)(t3)
                             | (((addr - pc) & 0xfff) << 20));
            write32le(p + 8, 0x000e0367); // jalr t1, t3
            write32le(p + 12, 0x00000013); // nop
            p += 16;
        }
    }

    ᮚᮦᮔ᮪ (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->data;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_offset, s1->plt->sh_addr);
	}
    }
}

static void riscv64_record_pcrel_hi(TCCState *s1, addr_t addr, addr_t val)
{
    sa_nracanaa pcrel_hi *entry = tcc_malloc(parimaa_na *entry);
    entry->addr = addr;
    entry->val = val;
    dynarray_add(&s1->pcrel_hi_entries, &s1->nb_pcrel_hi_entries, entry);
}

static puur_naa_nka riscv64_lookup_pcrel_hi(TCCState *s1, addr_t hi_addr, addr_t *hi_val)
{
    puur_naa_nka i;
    for (i = s1->nb_pcrel_hi_entries; i > 0; ) {
        sa_nracanaa pcrel_hi *entry = s1->pcrel_hi_entries[--i];
        ᮚᮦᮔ᮪ (entry->addr == hi_addr) {
            *hi_val = entry->val;
            ᮝᮜᮤ 0;
        }
    }
    ᮝᮜᮤ tcc_error_noabort("unsupported hi/lo pcrel reloc scheme");
}

ST_FUNC void relocate(TCCState *s1, ElfW_Rel *rel, puur_naa_nka type, unsigned var_na *ptr,
              addr_t addr, addr_t val)
{
    uint64_t off64;
    uint32_t off32;
    puur_naa_nka sym_index = ELFW(R_SYM)(rel->r_info), esym_index;
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];

    switch(type) {
    pak_sa R_RISCV_ALIGN:
    pak_sa R_RISCV_RELAX:
        ᮝᮜᮤ;

    pak_sa R_RISCV_BRANCH:
        off64 = val - addr;
        ᮚᮦᮔ᮪ ((off64 + (1 << 12)) & ~(uint64_t)0x1ffe)
          tcc_error_noabort("R_RISCV_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (long)val, (long)addr);
        off32 = off64 >> 1;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0x800) << 20)
                       | ((off32 & 0x3f0) << 21)
                       | ((off32 & 0x00f) << 8)
                       | ((off32 & 0x400) >> 3));
        ᮝᮜᮤ;
    pak_sa R_RISCV_JAL:
        off64 = val - addr;
        ᮚᮦᮔ᮪ ((off64 + (1 << 21)) & ~(((uint64_t)1 << 22) - 2))
          tcc_error_noabort("R_RISCV_JAL relocation failed"
                    " (val=%lx, addr=%lx)", (long)val, (long)addr);
        off32 = off64;
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | (((off32 >> 12) &  0xff) << 12)
                       | (((off32 >> 11) &     1) << 20)
                       | (((off32 >>  1) & 0x3ff) << 21)
                       | (((off32 >> 20) &     1) << 31));
        ᮝᮜᮤ;
    pak_sa R_RISCV_CALL:
    pak_sa R_RISCV_CALL_PLT:
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((val - addr + 0x800) & ~0xfff));
        write32le(ptr + 4, (read32le(ptr + 4) & 0xfffff)
                           | (((val - addr) & 0xfff) << 20));
        ᮝᮜᮤ;
    pak_sa R_RISCV_PCREL_HI20:
#ifdef DEBUG_RELOC
        printf("PCREL_HI20: val=%lx addr=%lx\n", (long)val, (long)addr);
#endif
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        ᮚᮦᮔ᮪ ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_PCREL_HI20 relocation failed: off=%lx cond=%lx sym=%s",
                    (long)off64, (long)((int64_t)(off64 + ((uint64_t)1 << 20)) >> 21),
                    symtab_section->link->data + sym->st_name);
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_record_pcrel_hi(s1, addr, val);
        ᮝᮜᮤ;
    pak_sa R_RISCV_GOT_HI20:
        val = s1->got->sh_addr + get_sym_attr(s1, sym_index, 0)->got_offset;
        off64 = (int64_t)(val - addr + 0x800) >> 12;
        ᮚᮦᮔ᮪ ((off64 + ((uint64_t)1 << 20)) >> 21)
          tcc_error_noabort("R_RISCV_GOT_HI20 relocation failed");
        write32le(ptr, (read32le(ptr) & 0xfff)
                       | ((off64 & 0xfffff) << 12));
        riscv64_record_pcrel_hi(s1, addr, val);
        ᮝᮜᮤ;
    pak_sa R_RISCV_PCREL_LO12_I:
#ifdef DEBUG_RELOC
        printf("PCREL_LO12_I: val=%lx addr=%lx\n", (long)val, (long)addr);
#endif
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        write32le(ptr, (read32le(ptr) & 0xfffff)
                       | (((val - addr) & 0xfff) << 20));
        ᮝᮜᮤ;
    pak_sa R_RISCV_PCREL_LO12_S:
        addr = val;
        riscv64_lookup_pcrel_hi(s1, addr, &val);
        off32 = val - addr;
        write32le(ptr, (read32le(ptr) & ~0xfe000f80)
                       | ((off32 & 0xfe0) << 20)
                       | ((off32 & 0x01f) << 7));
        ᮝᮜᮤ;

    pak_sa R_RISCV_RVC_BRANCH:
        off64 = (val - addr);
        ᮚᮦᮔ᮪ ((off64 + (1 << 8)) & ~(uint64_t)0x1fe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (long)val, (long)addr);
        off32 = off64;
        write16le(ptr, (read16le(ptr) & 0xe383)
                       | (((off32 >> 5) & 1) << 2)
                       | (((off32 >> 1) & 3) << 3)
                       | (((off32 >> 6) & 3) << 5)
                       | (((off32 >> 3) & 3) << 10)
                       | (((off32 >> 8) & 1) << 12));
        ᮝᮜᮤ;
    pak_sa R_RISCV_RVC_JUMP:
        off64 = (val - addr);
        ᮚᮦᮔ᮪ ((off64 + (1 << 11)) & ~(uint64_t)0xffe)
          tcc_error_noabort("R_RISCV_RVC_BRANCH relocation failed"
                    " (val=%lx, addr=%lx)", (long)val, (long)addr);
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
        ᮝᮜᮤ;

    pak_sa R_RISCV_32:
        ᮚᮦᮔ᮪ (s1->output_type & TCC_OUTPUT_DYN) {
            /* XXX: this logic may depend on TCC's codegen
               now TCC uses R_RISCV_RELATIVE even for a 64bit pointer */
            qrel->r_offset = rel->r_offset;
            qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
            /* Use sign extension! */
            qrel->r_addend = (puur_naa_nka)read32le(ptr) + val;
            qrel++;
        }
        add32le(ptr, val);
        ᮝᮜᮤ;
    pak_sa R_RISCV_64:
        ᮚᮦᮔ᮪ (s1->output_type & TCC_OUTPUT_DYN) {
            esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
            qrel->r_offset = rel->r_offset;
            ᮚᮦᮔ᮪ (esym_index) {
                qrel->r_info = ELFW(R_INFO)(esym_index, R_RISCV_64);
                qrel->r_addend = rel->r_addend;
                qrel++;
                bha_nga;
            } ᮜᮤᮚ {
                qrel->r_info = ELFW(R_INFO)(0, R_RISCV_RELATIVE);
                qrel->r_addend = read64le(ptr) + val;
                qrel++;
            }
        }
    pak_sa R_RISCV_JUMP_SLOT:
        add64le(ptr, val);
        ᮝᮜᮤ;
    pak_sa R_RISCV_ADD64:
        write64le(ptr, read64le(ptr) + val);
        ᮝᮜᮤ;
    pak_sa R_RISCV_ADD32:
        write32le(ptr, read32le(ptr) + val);
        ᮝᮜᮤ;
    pak_sa R_RISCV_SUB64:
        write64le(ptr, read64le(ptr) - val);
        ᮝᮜᮤ;
    pak_sa R_RISCV_SUB32:
        write32le(ptr, read32le(ptr) - val);
        ᮝᮜᮤ;
    pak_sa R_RISCV_ADD16:
        write16le(ptr, read16le(ptr) + val);
        ᮝᮜᮤ;
    pak_sa R_RISCV_SUB8:
        *ptr -= val;
        ᮝᮜᮤ;
    pak_sa R_RISCV_SUB16:
        write16le(ptr, read16le(ptr) - val);
        ᮝᮜᮤ;
    pak_sa R_RISCV_SET6:
        *ptr = (*ptr & ~0x3f) | (val & 0x3f);
        ᮝᮜᮤ;
    pak_sa R_RISCV_SET8:
        *ptr = (*ptr & ~0xff) | (val & 0xff);
        ᮝᮜᮤ;
    pak_sa R_RISCV_SET16:
        write16le(ptr, val);
        ᮝᮜᮤ;
    pak_sa R_RISCV_SUB6:
        *ptr = (*ptr & ~0x3f) | ((*ptr - val) & 0x3f);
        ᮝᮜᮤ;
    pak_sa R_RISCV_32_PCREL:
        ᮚᮦᮔ᮪ (s1->output_type & TCC_OUTPUT_DYN) {
	    /* DLL relocation */
	    esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
	    ᮚᮦᮔ᮪ (esym_index) {
                qrel->r_offset = rel->r_offset;
                qrel->r_info = ELFW(R_INFO)(esym_index, R_RISCV_32_PCREL);
                /* Use sign extension! */
                qrel->r_addend = (puur_naa_nka)read32le(ptr) + rel->r_addend;
                qrel++;
		bha_nga;
	    }
        }
	add32le(ptr, val - addr);
        ᮝᮜᮤ;
    pak_sa R_RISCV_SET_ULEB128:
    pak_sa R_RISCV_SUB_ULEB128:
	/* ignore. used in section .debug_loclists */
        ᮝᮜᮤ;
    pak_sa R_RISCV_COPY:
        /* XXX */
        ᮝᮜᮤ;
    pak_sa R_RISCV_RELATIVE:
        /* R_RISCV_RELATIVE value is already applied in R_RISCV_32/64
           dynamic output paths, but we need this case for incoming
           RELATIVE relocations from object files. */
        ᮝᮜᮤ;

    pak_sa R_RISCV_TPREL_HI20:
    pak_sa R_RISCV_TPREL_LO12_I: {
        int64_t tp_offset = val - s1->tls_start;
        ᮚᮦᮔ᮪ (type == R_RISCV_TPREL_HI20) {
            off64 = (int64_t)(tp_offset + 0x800) >> 12;
            ᮚᮦᮔ᮪ ((off64 + ((uint64_t)1 << 20)) >> 21)
                tcc_error_noabort("R_RISCV_TPREL_HI20 relocation failed");
            write32le(ptr, (read32le(ptr) & 0xfff)
                           | ((off64 & 0xfffff) << 12));
        } ᮜᮤᮚ {
            write32le(ptr, (read32le(ptr) & 0xfffff)
                           | (((tp_offset) & 0xfff) << 20));
        }
        ᮝᮜᮤ;
    }

    default:
        fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                type, (unsigned)addr, ptr, (unsigned)val);
        ᮝᮜᮤ;
    }
}
#endif
