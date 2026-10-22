#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_C60

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_C60_32
#define R_DATA_PTR  R_C60_32
#define R_JMP_SLOT  R_C60_JMP_SLOT
#define R_GLOB_DAT  R_C60_GLOB_DAT
#define R_COPY      R_C60_COPY
#define R_RELATIVE  R_C60_RELATIVE

#define R_رقم       R_C60_رقم

#define ELF_START_ADDR 0x00000400
#define ELF_PAGE_SIZE  0x1000

#define PCRELATIVE_DLLPLT 0
#define RELOCATE_DLLPLT 0

#وگرنه /* !TARGET_DEFS_ONLY */

#شامل "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحیح code_reloc (صحیح reloc_type)
{
    انتخاب (reloc_type) {
        حالت R_C60_32:
	حالت R_C60LO16:
	حالت R_C60HI16:
        حالت R_C60_GOT32:
        حالت R_C60_GOTOFF:
        حالت R_C60_GOTPC:
        حالت R_C60_COPY:
            بازگشت 0;

        حالت R_C60_PLT32:
            بازگشت 1;
    }
    بازگشت -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC صحیح gotplt_entry_type (صحیح reloc_type)
{
    انتخاب (reloc_type) {
        حالت R_C60_32:
	حالت R_C60LO16:
	حالت R_C60HI16:
        حالت R_C60_COPY:
            بازگشت NO_GOTPLT_ENTRY;

        حالت R_C60_GOTOFF:
        حالت R_C60_GOTPC:
            بازگشت BUILD_GOT_ONLY;

        حالت R_C60_PLT32:
        حالت R_C60_GOT32:
            بازگشت ALWAYS_GOTPLT_ENTRY;
    }
    بازگشت -1;
}

ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, ساختار sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    بازگشت 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC تهی relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    اگر (!s1->plt)
      بازگشت;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    اگر (p < p_end) {
        /* XXX: TODO */
        وقتی (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC تهی relocate(TCCState *s1, ElfW_Rel *rel, صحیح type, unsigned نویسه *ptr, addr_t addr, addr_t val)
{
    انتخاب(type) {
        حالت R_C60_32:
            *(صحیح *)ptr += val;
            بشکن;
        حالت R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(صحیح *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(صحیح *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(صحیح *) ptr    = (*(صحیح *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(صحیح *)(ptr+4) = (*(صحیح *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            بشکن;
        حالت R_C60HI16:
            بشکن;
        پیشفرض:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (unsigned) addr, ptr, (unsigned) val);
            بشکن;
    }
}

#endif /* !TARGET_DEFS_ONLY */
