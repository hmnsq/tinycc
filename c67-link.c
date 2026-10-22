#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_C60

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_C60_32
#define R_DATA_PTR  R_C60_32
#define R_JMP_SLOT  R_C60_JMP_SLOT
#define R_GLOB_DAT  R_C60_GLOB_DAT
#define R_COPY      R_C60_COPY
#define R_RELATIVE  R_C60_RELATIVE

#define R_અંક       R_C60_અંક

#define ELF_START_ADDR 0x00000400
#define ELF_PAGE_SIZE  0x1000

#define PCRELATIVE_DLLPLT 0
#define RELOCATE_DLLPLT 0

#નહીંતર /* !TARGET_DEFS_ONLY */

#અન્તર્ભાવ "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC પૂર્ણાંક code_reloc (પૂર્ણાંક reloc_type)
{
    પસંદગી (reloc_type) {
        સ્થિતિ R_C60_32:
	સ્થિતિ R_C60LO16:
	સ્થિતિ R_C60HI16:
        સ્થિતિ R_C60_GOT32:
        સ્થિતિ R_C60_GOTOFF:
        સ્થિતિ R_C60_GOTPC:
        સ્થિતિ R_C60_COPY:
            પાછા 0;

        સ્થિતિ R_C60_PLT32:
            પાછા 1;
    }
    પાછા -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC પૂર્ણાંક gotplt_entry_type (પૂર્ણાંક reloc_type)
{
    પસંદગી (reloc_type) {
        સ્થિતિ R_C60_32:
	સ્થિતિ R_C60LO16:
	સ્થિતિ R_C60HI16:
        સ્થિતિ R_C60_COPY:
            પાછા NO_GOTPLT_ENTRY;

        સ્થિતિ R_C60_GOTOFF:
        સ્થિતિ R_C60_GOTPC:
            પાછા BUILD_GOT_ONLY;

        સ્થિતિ R_C60_PLT32:
        સ્થિતિ R_C60_GOT32:
            પાછા ALWAYS_GOTPLT_ENTRY;
    }
    પાછા -1;
}

ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, સંરચના sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    પાછા 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC શૂન્ય relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    જો (!s1->plt)
      પાછા;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    જો (p < p_end) {
        /* XXX: TODO */
        જ્યારે (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC શૂન્ય relocate(TCCState *s1, ElfW_Rel *rel, પૂર્ણાંક type, unsigned અક્ષર *ptr, addr_t addr, addr_t val)
{
    પસંદગી(type) {
        સ્થિતિ R_C60_32:
            *(પૂર્ણાંક *)ptr += val;
            તોડો;
        સ્થિતિ R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(પૂર્ણાંક *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(પૂર્ણાંક *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(પૂર્ણાંક *) ptr    = (*(પૂર્ણાંક *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(પૂર્ણાંક *)(ptr+4) = (*(પૂર્ણાંક *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            તોડો;
        સ્થિતિ R_C60HI16:
            તોડો;
        મૂળભૂત:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (unsigned) addr, ptr, (unsigned) val);
            તોડો;
    }
}

#endif /* !TARGET_DEFS_ONLY */
