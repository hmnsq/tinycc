#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_C60

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_C60_32
#define R_DATA_PTR  R_C60_32
#define R_JMP_SLOT  R_C60_JMP_SLOT
#define R_GLOB_DAT  R_C60_GLOB_DAT
#define R_COPY      R_C60_COPY
#define R_RELATIVE  R_C60_RELATIVE

#define R_अङ्कः       R_C60_अङ्कः

#define ELF_START_ADDR 0x00000400
#define ELF_PAGE_SIZE  0x1000

#define PCRELATIVE_DLLPLT 0
#define RELOCATE_DLLPLT 0

#अञ्ञथा /* !TARGET_DEFS_ONLY */

#अन्तर्भाव "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC पूर्णाङ्क code_reloc (पूर्णाङ्क reloc_type)
{
    विकल्प (reloc_type) {
        पक्ष R_C60_32:
	पक्ष R_C60LO16:
	पक्ष R_C60HI16:
        पक्ष R_C60_GOT32:
        पक्ष R_C60_GOTOFF:
        पक्ष R_C60_GOTPC:
        पक्ष R_C60_COPY:
            पटिनिवत्त 0;

        पक्ष R_C60_PLT32:
            पटिनिवत्त 1;
    }
    पटिनिवत्त -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC पूर्णाङ्क gotplt_entry_type (पूर्णाङ्क reloc_type)
{
    विकल्प (reloc_type) {
        पक्ष R_C60_32:
	पक्ष R_C60LO16:
	पक्ष R_C60HI16:
        पक्ष R_C60_COPY:
            पटिनिवत्त NO_GOTPLT_ENTRY;

        पक्ष R_C60_GOTOFF:
        पक्ष R_C60_GOTPC:
            पटिनिवत्त BUILD_GOT_ONLY;

        पक्ष R_C60_PLT32:
        पक्ष R_C60_GOT32:
            पटिनिवत्त ALWAYS_GOTPLT_ENTRY;
    }
    पटिनिवत्त -1;
}

ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, संरचना sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    पटिनिवत्त 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC शून्य relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    सचे (!s1->plt)
      पटिनिवत्त;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    सचे (p < p_end) {
        /* XXX: TODO */
        याव (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC शून्य relocate(TCCState *s1, ElfW_Rel *rel, पूर्णाङ्क type, unsigned वर्ण *ptr, addr_t addr, addr_t val)
{
    विकल्प(type) {
        पक्ष R_C60_32:
            *(पूर्णाङ्क *)ptr += val;
            भङ्ग;
        पक्ष R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(पूर्णाङ्क *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(पूर्णाङ्क *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(पूर्णाङ्क *) ptr    = (*(पूर्णाङ्क *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(पूर्णाङ्क *)(ptr+4) = (*(पूर्णाङ्क *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            भङ्ग;
        पक्ष R_C60HI16:
            भङ्ग;
        स्वभाव:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (unsigned) addr, ptr, (unsigned) val);
            भङ्ग;
    }
}

#endif /* !TARGET_DEFS_ONLY */
