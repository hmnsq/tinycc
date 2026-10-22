#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ಗುರಿ_DEFS_ONLY

#ವ್ಯಾಖ್ಯಾನಿಸು EM_TCC_ಗುರಿ EM_X86_64

/* relocation type for 32 bit data relocation */
#ವ್ಯಾಖ್ಯಾನಿಸು R_ದತ್ತಾಂಶ_32   R_X86_64_32S
#ವ್ಯಾಖ್ಯಾನಿಸು R_ದತ್ತಾಂಶ_PTR  R_X86_64_64
#ವ್ಯಾಖ್ಯಾನಿಸು R_JMP_ಸ್ಥಾನ  R_X86_64_JUMP_ಸ್ಥಾನ
#ವ್ಯಾಖ್ಯಾನಿಸು R_GLOB_DAT  R_X86_64_GLOB_DAT
#ವ್ಯಾಖ್ಯಾನಿಸು R_COPY      R_X86_64_COPY
#ವ್ಯಾಖ್ಯಾನಿಸು R_RELATIVE  R_X86_64_RELATIVE

#ವ್ಯಾಖ್ಯಾನಿಸು R_ಅಂಕೆ       R_X86_64_ಅಂಕೆ

#ವ್ಯಾಖ್ಯಾನಿಸು ELF_ಆರಂಭ_ADDR 0x400000
#ವ್ಯಾಖ್ಯಾನಿಸು ELF_ಪುಟ_ಗಾತ್ರ  0x1000

#ವ್ಯಾಖ್ಯಾನಿಸು PCRELATIVE_DLLPLT 1
#ವ್ಯಾಖ್ಯಾನಿಸು RELOCATE_DLLPLT 1

#ಇಲ್ಲದಿದ್ದರೆ /* !TARGET_DEFS_ONLY */

#ಅನ್ತರ್ಭಾವ "tcc.h"

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_reloc (ಪೂರ್ಣಾಂಕ reloc_type)
{
    ಆಯ್ಕೆ (reloc_type) {
        ಸ್ಥಿತಿ R_X86_64_32:
        ಸ್ಥಿತಿ R_X86_64_32S:
        ಸ್ಥಿತಿ R_X86_64_64:
        ಸ್ಥಿತಿ R_X86_64_GOTPC32:
        ಸ್ಥಿತಿ R_X86_64_GOTPC64:
        ಸ್ಥಿತಿ R_X86_64_GOTPCREL:
        ಸ್ಥಿತಿ R_X86_64_GOTPCRELX:
        ಸ್ಥಿತಿ R_X86_64_REX_GOTPCRELX:
        ಸ್ಥಿತಿ R_X86_64_GOTTPOFF:
        ಸ್ಥಿತಿ R_X86_64_GOT32:
        ಸ್ಥಿತಿ R_X86_64_GOT64:
        ಸ್ಥಿತಿ R_X86_64_GLOB_DAT:
        ಸ್ಥಿತಿ R_X86_64_COPY:
        ಸ್ಥಿತಿ R_X86_64_RELATIVE:
        ಸ್ಥಿತಿ R_X86_64_GOTOFF64:
        ಸ್ಥಿತಿ R_X86_64_TLSGD:
        ಸ್ಥಿತಿ R_X86_64_TLSLD:
        ಸ್ಥಿತಿ R_X86_64_DTPOFF32:
        ಸ್ಥಿತಿ R_X86_64_TPOFF32:
        ಸ್ಥಿತಿ R_X86_64_DTPOFF64:
        ಸ್ಥಿತಿ R_X86_64_TPOFF64:
            ಹಿಂತಿರುಗಿ 0;

        ಸ್ಥಿತಿ R_X86_64_PC32:
        ಸ್ಥಿತಿ R_X86_64_PC64:
        ಸ್ಥಿತಿ R_X86_64_PLT32:
        ಸ್ಥಿತಿ R_X86_64_PLTOFF64:
        ಸ್ಥಿತಿ R_X86_64_JUMP_ಸ್ಥಾನ:
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
        ಸ್ಥಿತಿ R_X86_64_GLOB_DAT:
        ಸ್ಥಿತಿ R_X86_64_JUMP_ಸ್ಥಾನ:
        ಸ್ಥಿತಿ R_X86_64_COPY:
        ಸ್ಥಿತಿ R_X86_64_RELATIVE:
            ಹಿಂತಿರುಗಿ NO_GOTPLT_ನಮೂದು;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        ಸ್ಥಿತಿ R_X86_64_32:
        ಸ್ಥಿತಿ R_X86_64_32S:
        ಸ್ಥಿತಿ R_X86_64_64:
        ಸ್ಥಿತಿ R_X86_64_PC32:
        ಸ್ಥಿತಿ R_X86_64_PC64:
            ಹಿಂತಿರುಗಿ AUTO_GOTPLT_ನಮೂದು;

        ಸ್ಥಿತಿ R_X86_64_GOTTPOFF:
            ಹಿಂತಿರುಗಿ BUILD_GOT_ONLY;

        ಸ್ಥಿತಿ R_X86_64_GOT32:
        ಸ್ಥಿತಿ R_X86_64_GOT64:
        ಸ್ಥಿತಿ R_X86_64_GOTPC32:
        ಸ್ಥಿತಿ R_X86_64_GOTPC64:
        ಸ್ಥಿತಿ R_X86_64_GOTOFF64:
        ಸ್ಥಿತಿ R_X86_64_GOTPCREL:
        ಸ್ಥಿತಿ R_X86_64_GOTPCRELX:
        ಸ್ಥಿತಿ R_X86_64_TLSGD:
        ಸ್ಥಿತಿ R_X86_64_TLSLD:
        ಸ್ಥಿತಿ R_X86_64_DTPOFF32:
        ಸ್ಥಿತಿ R_X86_64_DTPOFF64:
        ಸ್ಥಿತಿ R_X86_64_REX_GOTPCRELX:
        ಸ್ಥಿತಿ R_X86_64_PLT32:
        ಸ್ಥಿತಿ R_X86_64_PLTOFF64:
            ಹಿಂತಿರುಗಿ ALWAYS_GOTPLT_ನಮೂದು;

        ಸ್ಥಿತಿ R_X86_64_TPOFF32:
        ಸ್ಥಿತಿ R_X86_64_TPOFF64:
            ಹಿಂತಿರುಗಿ NO_GOTPLT_ನಮೂದು;
    }

    ಹಿಂತಿರುಗಿ -1;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ NEED_BUILD_GOT
ST_FUNC ಚಿಹ್ನೆರಹಿತ create_plt_ನಮೂದು(TCCState *s1, ಚಿಹ್ನೆರಹಿತ got_ಸ್ಥಾನಾಂತರ, ರಚನೆ sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    ಪೂರ್ಣಾಂಕ modrm;
    ಚಿಹ್ನೆರಹಿತ plt_ಸ್ಥಾನಾಂತರ, relofs;

    modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    ಆದರೆ (plt->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ == 0) {
        p = section_ptr_ಕೂಡಿಸು(plt, 16);
        p[0] = 0xff; /* pushl got + PTR_SIZE */
        p[1] = modrm + 0x10;
        write32le(p + 2, PTR_ಗಾತ್ರ);
        p[6] = 0xff; /* jmp *(got + PTR_SIZE * 2) */
        p[7] = modrm;
        write32le(p + 8, PTR_ಗಾತ್ರ * 2);
    }
    plt_ಸ್ಥಾನಾಂತರ = plt->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

    /* The PLT slot refers to the relocation entry it needs via offset.
       The reloc entry is created below, so its offset is the current
       data_offset */
    relofs = s1->plt->reloc ? s1->plt->reloc->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ : 0;

    /* Jump to GOT entry where ld.so initially put the address of ip + 4 */
    p = section_ptr_ಕೂಡಿಸು(plt, 16);
    p[0] = 0xff; /* jmp *(got + x) */
    p[1] = modrm;
    write32le(p + 2, got_ಸ್ಥಾನಾಂತರ);
    p[6] = 0x68; /* push $xxx */
    /* On x86-64, the relocation is referred to by _index_ */
    write32le(p + 7, relofs / ಗಾತ್ರ (ElfW_Rel) - 1);
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ));
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
        ಪೂರ್ಣಾಂಕ x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        ಆಗ (p < p_ಕೊನೆ) {
            add32le(p + 2, x + (s1->plt->ದತ್ತಾಂಶ - p));
            p += 16;
        }
    }

    ಆದರೆ (s1->plt->reloc) {
        ElfW_Rel *rel;
        ಪೂರ್ಣಾಂಕ x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->ದತ್ತಾಂಶ;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_ಸ್ಥಾನಾಂತರ, x);
            x += 16;
        }
    }
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

ST_FUNC ಶೂನ್ಯ relocate(TCCState *s1, ElfW_Rel *rel, ಪೂರ್ಣಾಂಕ type, ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr, addr_t addr, addr_t val)
{
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ, esym_ಸೂಚ್ಯಂಕ;

    sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(rel->r_info);

    ಆಯ್ಕೆ (type) {
        ಸ್ಥಿತಿ R_X86_64_64:
            ಆದರೆ (s1->output_type & TCC_OUTPUT_DYN) {
                esym_ಸೂಚ್ಯಂಕ = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->dyn_ಸೂಚ್ಯಂಕ;
                qrel->r_ಸ್ಥಾನಾಂತರ = rel->r_ಸ್ಥಾನಾಂತರ;
                ಆದರೆ (esym_ಸೂಚ್ಯಂಕ) {
                    qrel->r_info = ELFW(R_INFO)(esym_ಸೂಚ್ಯಂಕ, R_X86_64_64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    ನಿಲ್ಲಿಸು;
                } ಇಲ್ಲದಿದ್ದರೆ {
                    qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ R_X86_64_32:
        ಸ್ಥಿತಿ R_X86_64_32S:
            ಆದರೆ (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_ಸ್ಥಾನಾಂತರ = rel->r_ಸ್ಥಾನಾಂತರ;
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (ಪೂರ್ಣಾಂಕ)read32le(ptr) + val;
                qrel++;
            }
            ಆದರೆ ((type == R_X86_64_32 ? val != (ಚಿಹ್ನೆರಹಿತ)val : val != (ಪೂರ್ಣಾಂಕ)val)
                /* ignore relocation check for stab section */
                && (stab_section == ಖಾಲಿ ||
                    addr < stab_section->sh_addr ||
                    addr >= (stab_section->sh_addr + stab_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ))) {
                tcc_error_noabort("relocation 'R_X86_64_32[S]' out of range");
            }
            add32le(ptr, val);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ R_X86_64_PC32:
            ಆದರೆ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_ಸೂಚ್ಯಂಕ = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->dyn_ಸೂಚ್ಯಂಕ;
                ಆದರೆ (esym_ಸೂಚ್ಯಂಕ) {
                    qrel->r_ಸ್ಥಾನಾಂತರ = rel->r_ಸ್ಥಾನಾಂತರ;
                    qrel->r_info = ELFW(R_INFO)(esym_ಸೂಚ್ಯಂಕ, R_X86_64_PC32);
                    /* Use sign extension! */
                    qrel->r_addend = (ಪೂರ್ಣಾಂಕ)read32le(ptr) + rel->r_addend;
                    qrel++;
                    ನಿಲ್ಲಿಸು;
                }
            }
            ಹೋಗು plt32pc32;

        ಸ್ಥಿತಿ R_X86_64_PLT32:
            /* fallthrough: val already holds the PLT slot address */

        plt32pc32:
        {
            ದೀರ್ಘ ದೀರ್ಘ diff;
            diff = (ದೀರ್ಘ ದೀರ್ಘ)val - addr;
            ಆದರೆ (diff < -2147483648LL || diff > 2147483647LL) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
              /* ignore overflow with undefined weak symbols */
              ಆದರೆ (((ElfW(Sym)*)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ].st_shndx != SHN_UNDEF)
#ಆದರೆ_ಅಂತ್ಯ
                tcc_error_noabort("relocation '%d' out of range", type);
            }
            add32le(ptr, diff);
        }
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ R_X86_64_COPY:
	    ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ R_X86_64_PLTOFF64:
            add64le(ptr, val - s1->got->sh_addr + rel->r_addend);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ R_X86_64_PC64:
            ಆದರೆ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_ಸೂಚ್ಯಂಕ = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->dyn_ಸೂಚ್ಯಂಕ;
                ಆದರೆ (esym_ಸೂಚ್ಯಂಕ) {
                    qrel->r_ಸ್ಥಾನಾಂತರ = rel->r_ಸ್ಥಾನಾಂತರ;
                    qrel->r_info = ELFW(R_INFO)(esym_ಸೂಚ್ಯಂಕ, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    ನಿಲ್ಲಿಸು;
                }
            }
            add64le(ptr, val - addr);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ R_X86_64_GLOB_DAT:
        ಸ್ಥಿತಿ R_X86_64_JUMP_ಸ್ಥಾನ:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ R_X86_64_GOTPCREL:
        ಸ್ಥಿತಿ R_X86_64_GOTPCRELX:
        ಸ್ಥಿತಿ R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->got_ಸ್ಥಾನಾಂತರ - 4);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ R_X86_64_GOTPC32:
            add32le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ R_X86_64_GOTPC64:
            add64le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ R_X86_64_GOTTPOFF:
            add32le(ptr, val - s1->got->sh_addr);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ R_X86_64_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->got_ಸ್ಥಾನಾಂತರ);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->got_ಸ್ಥಾನಾಂತರ);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ R_X86_64_TLSGD:
            {
                ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ expect[] = {
                    /* .byte 0x66; lea 0(%rip),%rdi */
                    0x66, 0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* .word 0x6666; rex64; call __tls_get_addr@PLT */
                    0x66, 0x66, 0x48, 0xe8, 0x00, 0x00, 0x00, 0x00 };
                ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ replace[] = {
                    /* mov %fs:0,%rax */
                    0x64, 0x48, 0x8b, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
                    /* lea -4(%rax),%rax */
                    0x48, 0x8d, 0x80, 0x00, 0x00, 0x00, 0x00 };

                ಆದರೆ (memcmp (ptr-4, expect, ಗಾತ್ರ(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    ಸ್ಮರಣೆ_ನಕಲು(ptr-4, replace, ಗಾತ್ರ(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_ಮೌಲ್ಯ - sec->sh_addr - sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
                    add32le(ptr + 8, x);
                }
                ಇಲ್ಲದಿದ್ದರೆ
                    tcc_error_noabort("unexpected R_X86_64_TLSGD pattern");
            }
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ R_X86_64_TLSLD:
            {
                ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ expect[] = {
                    /* lea 0(%rip),%rdi */
                    0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0x00, 0x00, 0x00, 0x00 };
                ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ replace[] = {
                    /* data16 data16 data16 mov %fs:0,%rax */
                    0x66, 0x66, 0x66, 0x64, 0x48, 0x8b, 0x04, 0x25,
                    0x00, 0x00, 0x00, 0x00 };

                ಆದರೆ (memcmp (ptr-3, expect, ಗಾತ್ರ(expect)) == 0) {
                    ಸ್ಮರಣೆ_ನಕಲು(ptr-3, replace, ಗಾತ್ರ(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                }
                ಇಲ್ಲದಿದ್ದರೆ
                    tcc_error_noabort("unexpected R_X86_64_TLSLD pattern");
            }
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ R_X86_64_DTPOFF32:
        ಸ್ಥಿತಿ R_X86_64_TPOFF32:
        ಸ್ಥಿತಿ R_X86_64_DTPOFF64:
        ಸ್ಥಿತಿ R_X86_64_TPOFF64:
            {
                int32_t x;
                ಆದರೆ (s1->tls_ಕೊನೆ) {
                    x = val - s1->tls_ಕೊನೆ;
                } ಇಲ್ಲದಿದ್ದರೆ {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
                }
                ಆಯ್ಕೆ (type) {
                ಸ್ಥಿತಿ R_X86_64_DTPOFF64:
                ಸ್ಥಿತಿ R_X86_64_TPOFF64:
                    add64le(ptr, x);
                    ನಿಲ್ಲಿಸು;
                ಪೂರ್ವನಿಯೋಜಿತ:
                    add32le(ptr, x);
                    ನಿಲ್ಲಿಸು;
                }
            }
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ R_X86_64_NONE:
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ R_X86_64_RELATIVE:
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
            add32le(ptr, val - s1->pe_imagebase);
#ಆದರೆ_ಅಂತ್ಯ
            /* do nothing */
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (ಚಿಹ್ನೆರಹಿತ)addr, ptr, (ಚಿಹ್ನೆರಹಿತ)val);
            ನಿಲ್ಲಿಸು;
    }
}

#ಆದರೆ_ಅಂತ್ಯ /* !TARGET_DEFS_ONLY */
