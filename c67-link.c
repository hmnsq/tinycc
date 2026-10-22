#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_C60

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_C60_32
#define R_DATA_PTR  R_C60_32
#define R_JMP_SLOT  R_C60_JMP_SLOT
#define R_GLOB_DAT  R_C60_GLOB_DAT
#define R_COPY      R_C60_COPY
#define R_RELATIVE  R_C60_RELATIVE

#define R_ଅଙ୍କ       R_C60_ଅଙ୍କ

#define ELF_START_ADDR 0x00000400
#define ELF_PAGE_SIZE  0x1000

#define PCRELATIVE_DLLPLT 0
#define RELOCATE_DLLPLT 0

#ଅନ୍ୟଥା /* !TARGET_DEFS_ONLY */

#ଅନ୍ତର୍ଭାଵ "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା code_reloc (ପୂର୍ଣ୍ଣସଂଖ୍ୟା reloc_type)
{
    ବାଛ (reloc_type) {
        ସ୍ଥିତି R_C60_32:
	ସ୍ଥିତି R_C60LO16:
	ସ୍ଥିତି R_C60HI16:
        ସ୍ଥିତି R_C60_GOT32:
        ସ୍ଥିତି R_C60_GOTOFF:
        ସ୍ଥିତି R_C60_GOTPC:
        ସ୍ଥିତି R_C60_COPY:
            ଫେରନ୍ତୁ 0;

        ସ୍ଥିତି R_C60_PLT32:
            ଫେରନ୍ତୁ 1;
    }
    ଫେରନ୍ତୁ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gotplt_entry_type (ପୂର୍ଣ୍ଣସଂଖ୍ୟା reloc_type)
{
    ବାଛ (reloc_type) {
        ସ୍ଥିତି R_C60_32:
	ସ୍ଥିତି R_C60LO16:
	ସ୍ଥିତି R_C60HI16:
        ସ୍ଥିତି R_C60_COPY:
            ଫେରନ୍ତୁ NO_GOTPLT_ENTRY;

        ସ୍ଥିତି R_C60_GOTOFF:
        ସ୍ଥିତି R_C60_GOTPC:
            ଫେରନ୍ତୁ BUILD_GOT_ONLY;

        ସ୍ଥିତି R_C60_PLT32:
        ସ୍ଥିତି R_C60_GOT32:
            ଫେରନ୍ତୁ ALWAYS_GOTPLT_ENTRY;
    }
    ଫେରନ୍ତୁ -1;
}

ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, ସଂରଚନା sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    ଫେରନ୍ତୁ 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC ଶୂନ୍ୟ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    ଯଦି (!s1->plt)
      ଫେରନ୍ତୁ;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    ଯଦି (p < p_end) {
        /* XXX: TODO */
        ଯେତେବେଳେ (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC ଶୂନ୍ୟ relocate(TCCState *s1, ElfW_Rel *rel, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, unsigned ଅକ୍ଷର *ptr, addr_t addr, addr_t val)
{
    ବାଛ(type) {
        ସ୍ଥିତି R_C60_32:
            *(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)ptr += val;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *) ptr    = (*(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)(ptr+4) = (*(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            ଭାଙ୍ଗ;
        ସ୍ଥିତି R_C60HI16:
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (unsigned) addr, ptr, (unsigned) val);
            ଭାଙ୍ଗ;
    }
}

#endif /* !TARGET_DEFS_ONLY */
