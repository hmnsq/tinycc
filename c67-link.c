#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ಗುರಿ_DEFS_ONLY

#ವ್ಯಾಖ್ಯಾನಿಸು EM_TCC_ಗುರಿ EM_C60

/* relocation type for 32 bit data relocation */
#ವ್ಯಾಖ್ಯಾನಿಸು R_ದತ್ತಾಂಶ_32   R_C60_32
#ವ್ಯಾಖ್ಯಾನಿಸು R_ದತ್ತಾಂಶ_PTR  R_C60_32
#ವ್ಯಾಖ್ಯಾನಿಸು R_JMP_ಸ್ಥಾನ  R_C60_JMP_ಸ್ಥಾನ
#ವ್ಯಾಖ್ಯಾನಿಸು R_GLOB_DAT  R_C60_GLOB_DAT
#ವ್ಯಾಖ್ಯಾನಿಸು R_COPY      R_C60_COPY
#ವ್ಯಾಖ್ಯಾನಿಸು R_RELATIVE  R_C60_RELATIVE

#ವ್ಯಾಖ್ಯಾನಿಸು R_ಅಂಕೆ       R_C60_ಅಂಕೆ

#ವ್ಯಾಖ್ಯಾನಿಸು ELF_ಆರಂಭ_ADDR 0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು ELF_ಪುಟ_ಗಾತ್ರ  0x1000

#ವ್ಯಾಖ್ಯಾನಿಸು PCRELATIVE_DLLPLT 0
#ವ್ಯಾಖ್ಯಾನಿಸು RELOCATE_DLLPLT 0

#ಇಲ್ಲದಿದ್ದರೆ /* !TARGET_DEFS_ONLY */

#ಅನ್ತರ್ಭಾವ "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_reloc (ಪೂರ್ಣಾಂಕ reloc_type)
{
    ಆಯ್ಕೆ (reloc_type) {
        ಸ್ಥಿತಿ R_C60_32:
	ಸ್ಥಿತಿ R_C60LO16:
	ಸ್ಥಿತಿ R_C60HI16:
        ಸ್ಥಿತಿ R_C60_GOT32:
        ಸ್ಥಿತಿ R_C60_GOTOFF:
        ಸ್ಥಿತಿ R_C60_GOTPC:
        ಸ್ಥಿತಿ R_C60_COPY:
            ಹಿಂತಿರುಗಿ 0;

        ಸ್ಥಿತಿ R_C60_PLT32:
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
        ಸ್ಥಿತಿ R_C60_32:
	ಸ್ಥಿತಿ R_C60LO16:
	ಸ್ಥಿತಿ R_C60HI16:
        ಸ್ಥಿತಿ R_C60_COPY:
            ಹಿಂತಿರುಗಿ NO_GOTPLT_ನಮೂದು;

        ಸ್ಥಿತಿ R_C60_GOTOFF:
        ಸ್ಥಿತಿ R_C60_GOTPC:
            ಹಿಂತಿರುಗಿ BUILD_GOT_ONLY;

        ಸ್ಥಿತಿ R_C60_PLT32:
        ಸ್ಥಿತಿ R_C60_GOT32:
            ಹಿಂತಿರುಗಿ ALWAYS_GOTPLT_ನಮೂದು;
    }
    ಹಿಂತಿರುಗಿ -1;
}

ST_FUNC ಚಿಹ್ನೆರಹಿತ create_plt_ನಮೂದು(TCCState *s1, ಚಿಹ್ನೆರಹಿತ got_ಸ್ಥಾನಾಂತರ, ರಚನೆ sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    ಹಿಂತಿರುಗಿ 0;
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
        /* XXX: TODO */
        ಆಗ (p < p_ಕೊನೆ) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC ಶೂನ್ಯ relocate(TCCState *s1, ElfW_Rel *rel, ಪೂರ್ಣಾಂಕ type, ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr, addr_t addr, addr_t val)
{
    ಆಯ್ಕೆ(type) {
        ಸ್ಥಿತಿ R_C60_32:
            *(ಪೂರ್ಣಾಂಕ *)ptr += val;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(ಪೂರ್ಣಾಂಕ *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(ಪೂರ್ಣಾಂಕ *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(ಪೂರ್ಣಾಂಕ *) ptr    = (*(ಪೂರ್ಣಾಂಕ *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(ಪೂರ್ಣಾಂಕ *)(ptr+4) = (*(ಪೂರ್ಣಾಂಕ *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ R_C60HI16:
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (ಚಿಹ್ನೆರಹಿತ) addr, ptr, (ಚಿಹ್ನೆರಹಿತ) val);
            ನಿಲ್ಲಿಸು;
    }
}

#ಆದರೆ_ಅಂತ್ಯ /* !TARGET_DEFS_ONLY */
