#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_C60

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_C60_32
#define R_DATA_PTR  R_C60_32
#define R_JMP_SLOT  R_C60_JMP_SLOT
#define R_GLOB_DAT  R_C60_GLOB_DAT
#define R_COPY      R_C60_COPY
#define R_RELATIVE  R_C60_RELATIVE

#define R_ಅಂಕೆ       R_C60_ಅಂಕೆ

#define ELF_START_ADDR 0x00000400
#define ELF_PAGE_SIZE  0x1000

#define PCRELATIVE_DLLPLT 0
#define RELOCATE_DLLPLT 0

#ಅನ್ಯಥಾ /* !TARGET_DEFS_ONLY */

#ಅನ್ತರ್ಭಾವ "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ code_reloc (ಪೂರ್ಣಾಙ್ಕ reloc_type)
{
    ವಿಕಲ್ಪ (reloc_type) {
        ಪಕ್ಷ R_C60_32:
	ಪಕ್ಷ R_C60LO16:
	ಪಕ್ಷ R_C60HI16:
        ಪಕ್ಷ R_C60_GOT32:
        ಪಕ್ಷ R_C60_GOTOFF:
        ಪಕ್ಷ R_C60_GOTPC:
        ಪಕ್ಷ R_C60_COPY:
            ಪ್ರತ್ಯಾಗಮ 0;

        ಪಕ್ಷ R_C60_PLT32:
            ಪ್ರತ್ಯಾಗಮ 1;
    }
    ಪ್ರತ್ಯಾಗಮ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ gotplt_entry_type (ಪೂರ್ಣಾಙ್ಕ reloc_type)
{
    ವಿಕಲ್ಪ (reloc_type) {
        ಪಕ್ಷ R_C60_32:
	ಪಕ್ಷ R_C60LO16:
	ಪಕ್ಷ R_C60HI16:
        ಪಕ್ಷ R_C60_COPY:
            ಪ್ರತ್ಯಾಗಮ NO_GOTPLT_ENTRY;

        ಪಕ್ಷ R_C60_GOTOFF:
        ಪಕ್ಷ R_C60_GOTPC:
            ಪ್ರತ್ಯಾಗಮ BUILD_GOT_ONLY;

        ಪಕ್ಷ R_C60_PLT32:
        ಪಕ್ಷ R_C60_GOT32:
            ಪ್ರತ್ಯಾಗಮ ALWAYS_GOTPLT_ENTRY;
    }
    ಪ್ರತ್ಯಾಗಮ -1;
}

ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, ಸಂರಚನಾ sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC ಶೂನ್ಯ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    ಯದಿ (!s1->plt)
      ಪ್ರತ್ಯಾಗಮ;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    ಯದಿ (p < p_end) {
        /* XXX: TODO */
        ಯಾವತ್ (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC ಶೂನ್ಯ relocate(TCCState *s1, ElfW_Rel *rel, ಪೂರ್ಣಾಙ್ಕ type, unsigned ವರ್ಣ *ptr, addr_t addr, addr_t val)
{
    ವಿಕಲ್ಪ(type) {
        ಪಕ್ಷ R_C60_32:
            *(ಪೂರ್ಣಾಙ್ಕ *)ptr += val;
            ಭಙ್ಗ;
        ಪಕ್ಷ R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(ಪೂರ್ಣಾಙ್ಕ *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(ಪೂರ್ಣಾಙ್ಕ *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(ಪೂರ್ಣಾಙ್ಕ *) ptr    = (*(ಪೂರ್ಣಾಙ್ಕ *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(ಪೂರ್ಣಾಙ್ಕ *)(ptr+4) = (*(ಪೂರ್ಣಾಙ್ಕ *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            ಭಙ್ಗ;
        ಪಕ್ಷ R_C60HI16:
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (unsigned) addr, ptr, (unsigned) val);
            ಭಙ್ಗ;
    }
}

#endif /* !TARGET_DEFS_ONLY */
