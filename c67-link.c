#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_C60

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_C60_32
#define R_DATA_PTR  R_C60_32
#define R_JMP_SLOT  R_C60_JMP_SLOT
#define R_GLOB_DAT  R_C60_GLOB_DAT
#define R_COPY      R_C60_COPY
#define R_RELATIVE  R_C60_RELATIVE

#define R_अंक       R_C60_अंक

#define ELF_START_ADDR 0x00000400
#define ELF_PAGE_SIZE  0x1000

#define PCRELATIVE_DLLPLT 0
#define RELOCATE_DLLPLT 0

#अन्यथा /* !TARGET_DEFS_ONLY */

#अन्तर्भाव "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC पूर्णांक code_reloc (पूर्णांक reloc_type)
{
    निवड (reloc_type) {
        स्थिती R_C60_32:
	स्थिती R_C60LO16:
	स्थिती R_C60HI16:
        स्थिती R_C60_GOT32:
        स्थिती R_C60_GOTOFF:
        स्थिती R_C60_GOTPC:
        स्थिती R_C60_COPY:
            परत 0;

        स्थिती R_C60_PLT32:
            परत 1;
    }
    परत -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC पूर्णांक gotplt_entry_type (पूर्णांक reloc_type)
{
    निवड (reloc_type) {
        स्थिती R_C60_32:
	स्थिती R_C60LO16:
	स्थिती R_C60HI16:
        स्थिती R_C60_COPY:
            परत NO_GOTPLT_ENTRY;

        स्थिती R_C60_GOTOFF:
        स्थिती R_C60_GOTPC:
            परत BUILD_GOT_ONLY;

        स्थिती R_C60_PLT32:
        स्थिती R_C60_GOT32:
            परत ALWAYS_GOTPLT_ENTRY;
    }
    परत -1;
}

ST_FUNC अचिन्हित create_plt_entry(TCCState *s1, अचिन्हित got_offset, संरचना sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    परत 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC शून्य relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    जर (!s1->plt)
      परत;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    जर (p < p_end) {
        /* XXX: TODO */
        पर्यंत (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC शून्य relocate(TCCState *s1, ElfW_Rel *rel, पूर्णांक type, अचिन्हित अक्षर *ptr, addr_t addr, addr_t val)
{
    निवड(type) {
        स्थिती R_C60_32:
            *(पूर्णांक *)ptr += val;
            थांबा;
        स्थिती R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(पूर्णांक *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(पूर्णांक *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(पूर्णांक *) ptr    = (*(पूर्णांक *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(पूर्णांक *)(ptr+4) = (*(पूर्णांक *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            थांबा;
        स्थिती R_C60HI16:
            थांबा;
        पूर्वनिर्धारित:
            ख_लिखो(मानक_त्रुटि,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (अचिन्हित) addr, ptr, (अचिन्हित) val);
            थांबा;
    }
}

#endif /* !TARGET_DEFS_ONLY */
