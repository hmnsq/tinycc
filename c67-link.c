#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_C60

/* relocation type for 32 bit data relocation */
#define R_তথ্য_32   R_C60_32
#define R_তথ্য_PTR  R_C60_32
#define R_JMP_SLOT  R_C60_JMP_SLOT
#define R_GLOB_DAT  R_C60_GLOB_DAT
#define R_COPY      R_C60_COPY
#define R_RELATIVE  R_C60_RELATIVE

#define R_অঙ্ক       R_C60_অঙ্ক

#define ELF_START_ADDR 0x00000400
#define ELF_PAGE_আকার  0x1000

#define PCRELATIVE_DLLPLT 0
#define RELOCATE_DLLPLT 0

#অন্যথা /* !TARGET_DEFS_ONLY */

#অন্তর্ভাব "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC পূর্ণসংখ্যা code_reloc (পূর্ণসংখ্যা reloc_type)
{
    নির্বাচন (reloc_type) {
        ক্ষেত্র R_C60_32:
	ক্ষেত্র R_C60LO16:
	ক্ষেত্র R_C60HI16:
        ক্ষেত্র R_C60_GOT32:
        ক্ষেত্র R_C60_GOTOFF:
        ক্ষেত্র R_C60_GOTPC:
        ক্ষেত্র R_C60_COPY:
            ফেরত 0;

        ক্ষেত্র R_C60_PLT32:
            ফেরত 1;
    }
    ফেরত -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC পূর্ণসংখ্যা gotplt_entry_type (পূর্ণসংখ্যা reloc_type)
{
    নির্বাচন (reloc_type) {
        ক্ষেত্র R_C60_32:
	ক্ষেত্র R_C60LO16:
	ক্ষেত্র R_C60HI16:
        ক্ষেত্র R_C60_COPY:
            ফেরত NO_GOTPLT_ENTRY;

        ক্ষেত্র R_C60_GOTOFF:
        ক্ষেত্র R_C60_GOTPC:
            ফেরত BUILD_GOT_ONLY;

        ক্ষেত্র R_C60_PLT32:
        ক্ষেত্র R_C60_GOT32:
            ফেরত ALWAYS_GOTPLT_ENTRY;
    }
    ফেরত -1;
}

ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, কাঠামো sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    ফেরত 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC শূন্য relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    যদি (!s1->plt)
      ফেরত;

    p = s1->plt->তথ্য;
    p_end = p + s1->plt->তথ্য_offset;

    যদি (p < p_end) {
        /* XXX: TODO */
        যখন (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC শূন্য relocate(TCCState *s1, ElfW_Rel *rel, পূর্ণসংখ্যা type, unsigned অক্ষর *ptr, addr_t addr, addr_t val)
{
    নির্বাচন(type) {
        ক্ষেত্র R_C60_32:
            *(পূর্ণসংখ্যা *)ptr += val;
            বিরতি;
        ক্ষেত্র R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(পূর্ণসংখ্যা *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(পূর্ণসংখ্যা *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(পূর্ণসংখ্যা *) ptr    = (*(পূর্ণসংখ্যা *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(পূর্ণসংখ্যা *)(ptr+4) = (*(পূর্ণসংখ্যা *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            বিরতি;
        ক্ষেত্র R_C60HI16:
            বিরতি;
        পূর্বনির্ধারিত:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (unsigned) addr, ptr, (unsigned) val);
            বিরতি;
    }
}

#endif /* !TARGET_DEFS_ONLY */
