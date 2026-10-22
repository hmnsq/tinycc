#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ಗುರಿ_DEFS_ONLY

#ವ್ಯಾಖ್ಯಾನಿಸು EM_TCC_ಗುರಿ EM_386

/* relocation type for 32 bit data relocation */
#ವ್ಯಾಖ್ಯಾನಿಸು R_ದತ್ತಾಂಶ_32   R_386_32
#ವ್ಯಾಖ್ಯಾನಿಸು R_ದತ್ತಾಂಶ_PTR  R_386_32
#ವ್ಯಾಖ್ಯಾನಿಸು R_JMP_ಸ್ಥಾನ  R_386_JMP_ಸ್ಥಾನ
#ವ್ಯಾಖ್ಯಾನಿಸು R_GLOB_DAT  R_386_GLOB_DAT
#ವ್ಯಾಖ್ಯಾನಿಸು R_COPY      R_386_COPY
#ವ್ಯಾಖ್ಯಾನಿಸು R_RELATIVE  R_386_RELATIVE

#ವ್ಯಾಖ್ಯಾನಿಸು R_ಅಂಕೆ       R_386_ಅಂಕೆ

#ವ್ಯಾಖ್ಯಾನಿಸು ELF_ಆರಂಭ_ADDR 0x08048000
#ವ್ಯಾಖ್ಯಾನಿಸು ELF_ಪುಟ_ಗಾತ್ರ  0x1000

#ಆದರೆ defined CONFIG_TCC_PIC
#ವ್ಯಾಖ್ಯಾನಿಸು PCRELATIVE_DLLPLT 1
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು PCRELATIVE_DLLPLT 0
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು RELOCATE_DLLPLT 1

#ಇಲ್ಲದಿದ್ದರೆ /* !TARGET_DEFS_ONLY */

#ಅನ್ತರ್ಭಾವ "tcc.h"

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_reloc (ಪೂರ್ಣಾಂಕ reloc_type)
{
    ಆಯ್ಕೆ (reloc_type) {
	ಸ್ಥಿತಿ R_386_RELATIVE:
	ಸ್ಥಿತಿ R_386_16:
        ಸ್ಥಿತಿ R_386_32:
	ಸ್ಥಿತಿ R_386_GOTPC:
	ಸ್ಥಿತಿ R_386_GOTOFF:
	ಸ್ಥಿತಿ R_386_GOT32:
	ಸ್ಥಿತಿ R_386_GOT32X:
	ಸ್ಥಿತಿ R_386_GLOB_DAT:
	ಸ್ಥಿತಿ R_386_COPY:
	ಸ್ಥಿತಿ R_386_TLS_GD:
	ಸ್ಥಿತಿ R_386_TLS_LDM:
	ಸ್ಥಿತಿ R_386_TLS_LDO_32:
	ಸ್ಥಿತಿ R_386_TLS_LE:
            ಹಿಂತಿರುಗಿ 0;

	ಸ್ಥಿತಿ R_386_PC16:
	ಸ್ಥಿತಿ R_386_PC32:
	ಸ್ಥಿತಿ R_386_PLT32:
	ಸ್ಥಿತಿ R_386_JMP_ಸ್ಥಾನ:
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
	ಸ್ಥಿತಿ R_386_RELATIVE:
	ಸ್ಥಿತಿ R_386_16:
	ಸ್ಥಿತಿ R_386_GLOB_DAT:
	ಸ್ಥಿತಿ R_386_JMP_ಸ್ಥಾನ:
	ಸ್ಥಿತಿ R_386_COPY:
            ಹಿಂತಿರುಗಿ NO_GOTPLT_ನಮೂದು;

        ಸ್ಥಿತಿ R_386_32:
	    /* This relocations shouldn't normally need GOT or PLT
	       slots if it weren't for simplicity in the code generator.
	       See our caller for comments.  */
            ಹಿಂತಿರುಗಿ AUTO_GOTPLT_ನಮೂದು;

	ಸ್ಥಿತಿ R_386_PC16:
	ಸ್ಥಿತಿ R_386_PC32:
            ಹಿಂತಿರುಗಿ AUTO_GOTPLT_ನಮೂದು;

	ಸ್ಥಿತಿ R_386_GOTPC:
	ಸ್ಥಿತಿ R_386_GOTOFF:
            ಹಿಂತಿರುಗಿ BUILD_GOT_ONLY;

	ಸ್ಥಿತಿ R_386_GOT32:
	ಸ್ಥಿತಿ R_386_GOT32X:
	ಸ್ಥಿತಿ R_386_PLT32:
	ಸ್ಥಿತಿ R_386_TLS_GD:
	ಸ್ಥಿತಿ R_386_TLS_LDM:
	ಸ್ಥಿತಿ R_386_TLS_LDO_32:
	ಸ್ಥಿತಿ R_386_TLS_LE:
            ಹಿಂತಿರುಗಿ ALWAYS_GOTPLT_ನಮೂದು;
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

    /* on i386 if we build a DLL, we add a %ebx offset */
    ಆದರೆ (s1->output_type & TCC_OUTPUT_DYN)
        modrm = 0xa3;
    ಇಲ್ಲದಿದ್ದರೆ
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
    write32le(p + 7, relofs - ಗಾತ್ರ (ElfW_Rel));
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

    ಆದರೆ (!(s1->output_type & TCC_OUTPUT_DYN) && p < p_ಕೊನೆ) {
        add32le(p + 2, s1->got->sh_addr);
        add32le(p + 8, s1->got->sh_addr);
        p += 16;
        ಆಗ (p < p_ಕೊನೆ) {
            add32le(p + 2, s1->got->sh_addr);
            p += 16;
        }
    }

    ಆದರೆ (s1->plt->reloc) {
        ElfW_Rel *rel;
        ಪೂರ್ಣಾಂಕ x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->ದತ್ತಾಂಶ;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_ಸ್ಥಾನಾಂತರ, x);
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
        ಸ್ಥಿತಿ R_386_32:
            ಆದರೆ (s1->output_type & TCC_OUTPUT_DYN) {
                esym_ಸೂಚ್ಯಂಕ = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->dyn_ಸೂಚ್ಯಂಕ;
                qrel->r_ಸ್ಥಾನಾಂತರ = rel->r_ಸ್ಥಾನಾಂತರ;
                ಆದರೆ (esym_ಸೂಚ್ಯಂಕ) {
                    qrel->r_info = ELFW(R_INFO)(esym_ಸೂಚ್ಯಂಕ, R_386_32);
                    qrel++;
                    ಹಿಂತಿರುಗಿ;
                } ಇಲ್ಲದಿದ್ದರೆ {
                    qrel->r_info = ELFW(R_INFO)(0, R_386_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_PC32:
            ಆದರೆ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_ಸೂಚ್ಯಂಕ = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->dyn_ಸೂಚ್ಯಂಕ;
                ಆದರೆ (esym_ಸೂಚ್ಯಂಕ) {
                    qrel->r_ಸ್ಥಾನಾಂತರ = rel->r_ಸ್ಥಾನಾಂತರ;
                    qrel->r_info = ELFW(R_INFO)(esym_ಸೂಚ್ಯಂಕ, R_386_PC32);
                    qrel++;
                    ಹಿಂತಿರುಗಿ;
                }
            }
            add32le(ptr, val - addr);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_PLT32:
            add32le(ptr, val - addr);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_GLOB_DAT:
        ಸ್ಥಿತಿ R_386_JMP_ಸ್ಥಾನ:
            write32le(ptr, val);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_GOT32:
        ಸ್ಥಿತಿ R_386_GOT32X:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->got_ಸ್ಥಾನಾಂತರ);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_16:
            ಆದರೆ (s1->output_format != TCC_OUTPUT_FORMAT_ದ್ವಿಮಾನ) {
            output_file:
                tcc_error_noabort("can only produce 16-bit binary files");
            }
            write16le(ptr, read16le(ptr) + val);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_PC16:
            ಆದರೆ (s1->output_format != TCC_OUTPUT_FORMAT_ದ್ವಿಮಾನ)
                ಹೋಗು output_file;
            write16le(ptr, read16le(ptr) + val - addr);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_RELATIVE:
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
            add32le(ptr, val - s1->pe_imagebase);
#ಆದರೆ_ಅಂತ್ಯ
            /* do nothing */
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_COPY:
            /* This relocation must copy initialized data from the library
            to the program .bss segment. Currently made like for ARM
            (to remove noise of default case). Is this true?
            */
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_TLS_GD:
            {
                ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ expect[] = {
                    /* lea 0(,%ebx,1),%eax */
                    0x8d, 0x04, 0x1d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* sub 0,%eax */
                    0x81, 0xe8, 0x00, 0x00, 0x00, 0x00 };

                ಆದರೆ (memcmp (ptr-3, expect, ಗಾತ್ರ(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    ಸ್ಮರಣೆ_ನಕಲು(ptr-3, replace, ಗಾತ್ರ(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_ಮೌಲ್ಯ - sec->sh_addr - sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
                    add32le(ptr + 5, -x);
                }
                ಇಲ್ಲದಿದ್ದರೆ
                    tcc_error_noabort("unexpected R_386_TLS_GD pattern");
            }
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_TLS_LDM:
            {
                ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ expect[] = {
                    /* lea 0(%ebx),%eax */
                    0x8d, 0x83, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* nop */
                    0x90,
                    /* lea 0(%esi,%eiz,1),%esi */
                    0x8d, 0x74, 0x26, 0x00 };

                ಆದರೆ (memcmp (ptr-2, expect, ಗಾತ್ರ(expect)) == 0) {
                    ಸ್ಮರಣೆ_ನಕಲು(ptr-2, replace, ಗಾತ್ರ(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                }
                ಇಲ್ಲದಿದ್ದರೆ
                    tcc_error_noabort("unexpected R_386_TLS_LDM pattern");
            }
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_TLS_LDO_32:
            {
                ElfW(Sym) *sym;
                Section *sec;
                int32_t x;

                sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
                sec = s1->sections[sym->st_shndx];
                x = val - sec->sh_addr - sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
                add32le(ptr, x);
            }
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_TLS_LE:
            {
                int32_t x;
                ಆದರೆ (s1->tls_ಕೊನೆ) {
                    x = val - s1->tls_ಕೊನೆ;
                } ಇಲ್ಲದಿದ್ದರೆ {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
                }
                add32le(ptr, x);
            }
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_386_NONE:
            ಹಿಂತಿರುಗಿ;
        ಪೂರ್ವನಿಯೋಜಿತ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (ಚಿಹ್ನೆರಹಿತ)addr, ptr, (ಚಿಹ್ನೆರಹಿತ)val);
            ಹಿಂತಿರುಗಿ;
    }
}

#ಆದರೆ_ಅಂತ್ಯ /* !TARGET_DEFS_ONLY */
