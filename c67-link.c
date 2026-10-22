#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_C60

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_C60_32
#define R_DATA_PTR  R_C60_32
#define R_JMP_SLOT  R_C60_JMP_SLOT
#define R_GLOB_DAT  R_C60_GLOB_DAT
#define R_COPY      R_C60_COPY
#define R_RELATIVE  R_C60_RELATIVE

#define R_অঙ্ক       R_C60_অঙ্ক

#define ELF_START_ADDR 0x00000400
#define ELF_PAGE_SIZE  0x1000

#define PCRELATIVE_DLLPLT 0
#define RELOCATE_DLLPLT 0

#অন্যথা /* !TARGET_DEFS_ONLY */

#অন্তর্ভাব "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC পূর্ণাঙ্ক code_reloc (পূর্ণাঙ্ক reloc_type)
{
    বিকল্প (reloc_type) {
        পক্ষ R_C60_32:
	পক্ষ R_C60LO16:
	পক্ষ R_C60HI16:
        পক্ষ R_C60_GOT32:
        পক্ষ R_C60_GOTOFF:
        পক্ষ R_C60_GOTPC:
        পক্ষ R_C60_COPY:
            প্রত্যাগম 0;

        পক্ষ R_C60_PLT32:
            প্রত্যাগম 1;
    }
    প্রত্যাগম -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC পূর্ণাঙ্ক gotplt_entry_type (পূর্ণাঙ্ক reloc_type)
{
    বিকল্প (reloc_type) {
        পক্ষ R_C60_32:
	পক্ষ R_C60LO16:
	পক্ষ R_C60HI16:
        পক্ষ R_C60_COPY:
            প্রত্যাগম NO_GOTPLT_ENTRY;

        পক্ষ R_C60_GOTOFF:
        পক্ষ R_C60_GOTPC:
            প্রত্যাগম BUILD_GOT_ONLY;

        পক্ষ R_C60_PLT32:
        পক্ষ R_C60_GOT32:
            প্রত্যাগম ALWAYS_GOTPLT_ENTRY;
    }
    প্রত্যাগম -1;
}

ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, সংরচনা sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    প্রত্যাগম 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC শূন্য relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    যদি (!s1->plt)
      প্রত্যাগম;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    যদি (p < p_end) {
        /* XXX: TODO */
        যাবত্ (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC শূন্য relocate(TCCState *s1, ElfW_Rel *rel, পূর্ণাঙ্ক type, unsigned বর্ণ *ptr, addr_t addr, addr_t val)
{
    বিকল্প(type) {
        পক্ষ R_C60_32:
            *(পূর্ণাঙ্ক *)ptr += val;
            ভঙ্গ;
        পক্ষ R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(পূর্ণাঙ্ক *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(পূর্ণাঙ্ক *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(পূর্ণাঙ্ক *) ptr    = (*(পূর্ণাঙ্ক *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(পূর্ণাঙ্ক *)(ptr+4) = (*(পূর্ণাঙ্ক *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            ভঙ্গ;
        পক্ষ R_C60HI16:
            ভঙ্গ;
        স্বভাব:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (unsigned) addr, ptr, (unsigned) val);
            ভঙ্গ;
    }
}

#endif /* !TARGET_DEFS_ONLY */
