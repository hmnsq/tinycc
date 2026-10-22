#अगर_घोषित TARGET_DEFS_ONLY

#घोषणा EM_TCC_TARGET EM_C60

/* relocation type for 32 bit data relocation */
#घोषणा R_तथ्य_32   R_C60_32
#घोषणा R_तथ्य_PTR  R_C60_32
#घोषणा R_JMP_SLOT  R_C60_JMP_SLOT
#घोषणा R_GLOB_DAT  R_C60_GLOB_DAT
#घोषणा R_COPY      R_C60_COPY
#घोषणा R_RELATIVE  R_C60_RELATIVE

#घोषणा R_अंक       R_C60_अंक

#घोषणा ELF_START_ADDR 0x00000400
#घोषणा ELF_PAGE_आकार  0x1000

#घोषणा PCRELATIVE_DLLPLT 0
#घोषणा RELOCATE_DLLPLT 0

#अन्यथा /* !TARGET_DEFS_ONLY */

#समावेश "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC पूर्णांक code_reloc (पूर्णांक reloc_type)
{
    चयन (reloc_type) {
        हाल R_C60_32:
	हाल R_C60LO16:
	हाल R_C60HI16:
        हाल R_C60_GOT32:
        हाल R_C60_GOTOFF:
        हाल R_C60_GOTPC:
        हाल R_C60_COPY:
            वापस 0;

        हाल R_C60_PLT32:
            वापस 1;
    }
    वापस -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC पूर्णांक gotplt_entry_type (पूर्णांक reloc_type)
{
    चयन (reloc_type) {
        हाल R_C60_32:
	हाल R_C60LO16:
	हाल R_C60HI16:
        हाल R_C60_COPY:
            वापस NO_GOTPLT_ENTRY;

        हाल R_C60_GOTOFF:
        हाल R_C60_GOTPC:
            वापस BUILD_GOT_ONLY;

        हाल R_C60_PLT32:
        हाल R_C60_GOT32:
            वापस ALWAYS_GOTPLT_ENTRY;
    }
    वापस -1;
}

ST_FUNC अचिन्हित create_plt_entry(TCCState *s1, अचिन्हित got_offset, काष्ठा sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    वापस 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC व्योम relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    अगर (!s1->plt)
      वापस;

    p = s1->plt->तथ्य;
    p_end = p + s1->plt->तथ्य_offset;

    अगर (p < p_end) {
        /* XXX: TODO */
        जबतक (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC व्योम relocate(TCCState *s1, ElfW_Rel *rel, पूर्णांक type, अचिन्हित अक्षर *ptr, addr_t addr, addr_t val)
{
    चयन(type) {
        हाल R_C60_32:
            *(पूर्णांक *)ptr += val;
            अवरोध;
        हाल R_C60LO16:
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
            अवरोध;
        हाल R_C60HI16:
            अवरोध;
        शेष:
            ख_लिखो(मानक_त्रुटि,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (अचिन्हित) addr, ptr, (अचिन्हित) val);
            अवरोध;
    }
}

#पूर्ण_अगर /* !TARGET_DEFS_ONLY */
