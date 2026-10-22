#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_X86_64

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_X86_64_32S
#define R_DATA_PTR  R_X86_64_64
#define R_JMP_SLOT  R_X86_64_JUMP_SLOT
#define R_GLOB_DAT  R_X86_64_GLOB_DAT
#define R_COPY      R_X86_64_COPY
#define R_RELATIVE  R_X86_64_RELATIVE

#define R_NUM       R_X86_64_NUM

#define ELF_START_ADDR 0x400000
#define ELF_PAGE_SIZE  0x1000

#define PCRELATIVE_DLLPLT 1
#define RELOCATE_DLLPLT 1

#ᨀᨘᨁ /* !TARGET_DEFS_ONLY */

#include "tcc.h"

#ifdef NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC puur_naa_nka code_reloc (puur_naa_nka reloc_type)
{
    switch (reloc_type) {
        pak_sa R_X86_64_32:
        pak_sa R_X86_64_32S:
        pak_sa R_X86_64_64:
        pak_sa R_X86_64_GOTPC32:
        pak_sa R_X86_64_GOTPC64:
        pak_sa R_X86_64_GOTPCREL:
        pak_sa R_X86_64_GOTPCRELX:
        pak_sa R_X86_64_REX_GOTPCRELX:
        pak_sa R_X86_64_GOTTPOFF:
        pak_sa R_X86_64_GOT32:
        pak_sa R_X86_64_GOT64:
        pak_sa R_X86_64_GLOB_DAT:
        pak_sa R_X86_64_COPY:
        pak_sa R_X86_64_RELATIVE:
        pak_sa R_X86_64_GOTOFF64:
        pak_sa R_X86_64_TLSGD:
        pak_sa R_X86_64_TLSLD:
        pak_sa R_X86_64_DTPOFF32:
        pak_sa R_X86_64_TPOFF32:
        pak_sa R_X86_64_DTPOFF64:
        pak_sa R_X86_64_TPOFF64:
            ᨀᨘᨒ 0;

        pak_sa R_X86_64_PC32:
        pak_sa R_X86_64_PC64:
        pak_sa R_X86_64_PLT32:
        pak_sa R_X86_64_PLTOFF64:
        pak_sa R_X86_64_JUMP_SLOT:
            ᨀᨘᨒ 1;
    }
    ᨀᨘᨒ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC puur_naa_nka gotplt_entry_type (puur_naa_nka reloc_type)
{
    switch (reloc_type) {
        pak_sa R_X86_64_GLOB_DAT:
        pak_sa R_X86_64_JUMP_SLOT:
        pak_sa R_X86_64_COPY:
        pak_sa R_X86_64_RELATIVE:
            ᨀᨘᨒ NO_GOTPLT_ENTRY;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        pak_sa R_X86_64_32:
        pak_sa R_X86_64_32S:
        pak_sa R_X86_64_64:
        pak_sa R_X86_64_PC32:
        pak_sa R_X86_64_PC64:
            ᨀᨘᨒ AUTO_GOTPLT_ENTRY;

        pak_sa R_X86_64_GOTTPOFF:
            ᨀᨘᨒ BUILD_GOT_ONLY;

        pak_sa R_X86_64_GOT32:
        pak_sa R_X86_64_GOT64:
        pak_sa R_X86_64_GOTPC32:
        pak_sa R_X86_64_GOTPC64:
        pak_sa R_X86_64_GOTOFF64:
        pak_sa R_X86_64_GOTPCREL:
        pak_sa R_X86_64_GOTPCRELX:
        pak_sa R_X86_64_TLSGD:
        pak_sa R_X86_64_TLSLD:
        pak_sa R_X86_64_DTPOFF32:
        pak_sa R_X86_64_DTPOFF64:
        pak_sa R_X86_64_REX_GOTPCRELX:
        pak_sa R_X86_64_PLT32:
        pak_sa R_X86_64_PLTOFF64:
            ᨀᨘᨒ ALWAYS_GOTPLT_ENTRY;

        pak_sa R_X86_64_TPOFF32:
        pak_sa R_X86_64_TPOFF64:
            ᨀᨘᨒ NO_GOTPLT_ENTRY;
    }

    ᨀᨘᨒ -1;
}

#ifdef NEED_BUILD_GOT
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, sa_nracanaa sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    puur_naa_nka modrm;
    unsigned plt_offset, relofs;

    modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    ᨀᨘ (plt->data_offset == 0) {
        p = section_ptr_add(plt, 16);
        p[0] = 0xff; /* pushl got + PTR_SIZE */
        p[1] = modrm + 0x10;
        write32le(p + 2, PTR_SIZE);
        p[6] = 0xff; /* jmp *(got + PTR_SIZE * 2) */
        p[7] = modrm;
        write32le(p + 8, PTR_SIZE * 2);
    }
    plt_offset = plt->data_offset;

    /* The PLT slot refers to the relocation entry it needs via offset.
       The reloc entry is created below, so its offset is the current
       data_offset */
    relofs = s1->plt->reloc ? s1->plt->reloc->data_offset : 0;

    /* Jump to GOT entry where ld.so initially put the address of ip + 4 */
    p = section_ptr_add(plt, 16);
    p[0] = 0xff; /* jmp *(got + x) */
    p[1] = modrm;
    write32le(p + 2, got_offset);
    p[6] = 0x68; /* push $xxx */
    /* On x86-64, the relocation is referred to by _index_ */
    write32le(p + 7, relofs / parimaa_na (ElfW_Rel) - 1);
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->data_offset));
    ᨀᨘᨒ plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC void relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    ᨀᨘ (!s1->plt)
      ᨀᨘᨒ;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    ᨀᨘ (p < p_end) {
        puur_naa_nka x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        ᨀᨛ (p < p_end) {
            add32le(p + 2, x + (s1->plt->data - p));
            p += 16;
        }
    }

    ᨀᨘ (s1->plt->reloc) {
        ElfW_Rel *rel;
        puur_naa_nka x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->data;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_offset, x);
            x += 16;
        }
    }
}
#endif
#endif

ST_FUNC void relocate(TCCState *s1, ElfW_Rel *rel, puur_naa_nka type, unsigned var_na *ptr, addr_t addr, addr_t val)
{
    puur_naa_nka sym_index, esym_index;

    sym_index = ELFW(R_SYM)(rel->r_info);

    switch (type) {
        pak_sa R_X86_64_64:
            ᨀᨘ (s1->output_type & TCC_OUTPUT_DYN) {
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                qrel->r_offset = rel->r_offset;
                ᨀᨘ (esym_index) {
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    bha_nga;
                } ᨀᨘᨁ {
                    qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            bha_nga;
        pak_sa R_X86_64_32:
        pak_sa R_X86_64_32S:
            ᨀᨘ (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_offset = rel->r_offset;
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (puur_naa_nka)read32le(ptr) + val;
                qrel++;
            }
            ᨀᨘ ((type == R_X86_64_32 ? val != (unsigned)val : val != (puur_naa_nka)val)
                /* ignore relocation check for stab section */
                && (stab_section == NULL ||
                    addr < stab_section->sh_addr ||
                    addr >= (stab_section->sh_addr + stab_section->data_offset))) {
                tcc_error_noabort("relocation 'R_X86_64_32[S]' out of range");
            }
            add32le(ptr, val);
            bha_nga;

        pak_sa R_X86_64_PC32:
            ᨀᨘ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                ᨀᨘ (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_PC32);
                    /* Use sign extension! */
                    qrel->r_addend = (puur_naa_nka)read32le(ptr) + rel->r_addend;
                    qrel++;
                    bha_nga;
                }
            }
            goto plt32pc32;

        pak_sa R_X86_64_PLT32:
            /* fallthrough: val already holds the PLT slot address */

        plt32pc32:
        {
            long long diff;
            diff = (long long)val - addr;
            ᨀᨘ (diff < -2147483648LL || diff > 2147483647LL) {
#ifdef TCC_TARGET_PE
              /* ignore overflow with undefined weak symbols */
              ᨀᨘ (((ElfW(Sym)*)symtab_section->data)[sym_index].st_shndx != SHN_UNDEF)
#endif
                tcc_error_noabort("relocation '%d' out of range", type);
            }
            add32le(ptr, diff);
        }
            bha_nga;

        pak_sa R_X86_64_COPY:
	    bha_nga;

        pak_sa R_X86_64_PLTOFF64:
            add64le(ptr, val - s1->got->sh_addr + rel->r_addend);
            bha_nga;

        pak_sa R_X86_64_PC64:
            ᨀᨘ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                ᨀᨘ (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    bha_nga;
                }
            }
            add64le(ptr, val - addr);
            bha_nga;

        pak_sa R_X86_64_GLOB_DAT:
        pak_sa R_X86_64_JUMP_SLOT:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            bha_nga;
        pak_sa R_X86_64_GOTPCREL:
        pak_sa R_X86_64_GOTPCRELX:
        pak_sa R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         get_sym_attr(s1, sym_index, 0)->got_offset - 4);
            bha_nga;
        pak_sa R_X86_64_GOTPC32:
            add32le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            bha_nga;
        pak_sa R_X86_64_GOTPC64:
            add64le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            bha_nga;
        pak_sa R_X86_64_GOTTPOFF:
            add32le(ptr, val - s1->got->sh_addr);
            bha_nga;
        pak_sa R_X86_64_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            bha_nga;
        pak_sa R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            bha_nga;
        pak_sa R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            bha_nga;
        pak_sa R_X86_64_TLSGD:
            {
                static const unsigned var_na expect[] = {
                    /* .byte 0x66; lea 0(%rip),%rdi */
                    0x66, 0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* .word 0x6666; rex64; call __tls_get_addr@PLT */
                    0x66, 0x66, 0x48, 0xe8, 0x00, 0x00, 0x00, 0x00 };
                static const unsigned var_na replace[] = {
                    /* mov %fs:0,%rax */
                    0x64, 0x48, 0x8b, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
                    /* lea -4(%rax),%rax */
                    0x48, 0x8d, 0x80, 0x00, 0x00, 0x00, 0x00 };

                ᨀᨘ (memcmp (ptr-4, expect, parimaa_na(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    memcpy(ptr-4, replace, parimaa_na(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_value - sec->sh_addr - sec->data_offset;
                    add32le(ptr + 8, x);
                }
                ᨀᨘᨁ
                    tcc_error_noabort("unexpected R_X86_64_TLSGD pattern");
            }
            bha_nga;
        pak_sa R_X86_64_TLSLD:
            {
                static const unsigned var_na expect[] = {
                    /* lea 0(%rip),%rdi */
                    0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0x00, 0x00, 0x00, 0x00 };
                static const unsigned var_na replace[] = {
                    /* data16 data16 data16 mov %fs:0,%rax */
                    0x66, 0x66, 0x66, 0x64, 0x48, 0x8b, 0x04, 0x25,
                    0x00, 0x00, 0x00, 0x00 };

                ᨀᨘ (memcmp (ptr-3, expect, parimaa_na(expect)) == 0) {
                    memcpy(ptr-3, replace, parimaa_na(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                }
                ᨀᨘᨁ
                    tcc_error_noabort("unexpected R_X86_64_TLSLD pattern");
            }
            bha_nga;

        pak_sa R_X86_64_DTPOFF32:
        pak_sa R_X86_64_TPOFF32:
        pak_sa R_X86_64_DTPOFF64:
        pak_sa R_X86_64_TPOFF64:
            {
                int32_t x;
                ᨀᨘ (s1->tls_end) {
                    x = val - s1->tls_end;
                } ᨀᨘᨁ {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->data_offset;
                }
                switch (type) {
                pak_sa R_X86_64_DTPOFF64:
                pak_sa R_X86_64_TPOFF64:
                    add64le(ptr, x);
                    bha_nga;
                default:
                    add32le(ptr, x);
                    bha_nga;
                }
            }
            bha_nga;
        pak_sa R_X86_64_NONE:
            bha_nga;
        pak_sa R_X86_64_RELATIVE:
#ifdef TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            bha_nga;
        default:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (unsigned)addr, ptr, (unsigned)val);
            bha_nga;
    }
}

#endif /* !TARGET_DEFS_ONLY */
