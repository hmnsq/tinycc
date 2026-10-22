#यदि_परिभाषितम् TARGET_DEFS_ONLY

#परिभाषय EM_TCC_TARGET EM_C60

/* relocation type for 32 bit data relocation */
#परिभाषय R_दत्त_32   R_C60_32
#परिभाषय R_दत्त_PTR  R_C60_32
#परिभाषय R_JMP_SLOT  R_C60_JMP_SLOT
#परिभाषय R_GLOB_DAT  R_C60_GLOB_DAT
#परिभाषय R_COPY      R_C60_COPY
#परिभाषय R_RELATIVE  R_C60_RELATIVE

#परिभाषय R_अङ्कः       R_C60_अङ्कः

#परिभाषय ELF_START_ADDR 0x00000400
#परिभाषय ELF_PAGE_आकार  0x1000

#परिभाषय PCRELATIVE_DLLPLT 0
#परिभाषय RELOCATE_DLLPLT 0

#अन्यथा /* !TARGET_DEFS_ONLY */

#अन्तर्भाव "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC पूर्णाङ्क संहिता_reloc (पूर्णाङ्क reloc_type)
{
    विकल्प (reloc_type) {
        पक्ष R_C60_32:
	पक्ष R_C60LO16:
	पक्ष R_C60HI16:
        पक्ष R_C60_GOT32:
        पक्ष R_C60_GOTOFF:
        पक्ष R_C60_GOTPC:
        पक्ष R_C60_COPY:
            प्रत्यागम 0;

        पक्ष R_C60_PLT32:
            प्रत्यागम 1;
    }
    प्रत्यागम -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC पूर्णाङ्क gotplt_प्रविष्टिः_type (पूर्णाङ्क reloc_type)
{
    विकल्प (reloc_type) {
        पक्ष R_C60_32:
	पक्ष R_C60LO16:
	पक्ष R_C60HI16:
        पक्ष R_C60_COPY:
            प्रत्यागम NO_GOTPLT_प्रविष्टिः;

        पक्ष R_C60_GOTOFF:
        पक्ष R_C60_GOTPC:
            प्रत्यागम BUILD_GOT_ONLY;

        पक्ष R_C60_PLT32:
        पक्ष R_C60_GOT32:
            प्रत्यागम ALWAYS_GOTPLT_प्रविष्टिः;
    }
    प्रत्यागम -1;
}

ST_FUNC अचिह्नित create_plt_प्रविष्टिः(TCCState *s1, अचिह्नित got_विस्थापनम्, संरचना sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    प्रत्यागम 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC शून्य relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_अन्तः;

    यदि (!s1->plt)
      प्रत्यागम;

    p = s1->plt->दत्त;
    p_अन्तः = p + s1->plt->दत्त_विस्थापनम्;

    यदि (p < p_अन्तः) {
        /* XXX: TODO */
        यावत् (p < p_अन्तः) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC शून्य relocate(TCCState *s1, ElfW_Rel *rel, पूर्णाङ्क type, अचिह्नित वर्ण *ptr, addr_t addr, addr_t val)
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
                    type, (अचिह्नित) addr, ptr, (अचिह्नित) val);
            भङ्ग;
    }
}

#यदि_अन्तः /* !TARGET_DEFS_ONLY */
