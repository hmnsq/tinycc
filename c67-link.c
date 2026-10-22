#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_C60

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_C60_32
#define R_DATA_PTR  R_C60_32
#define R_JMP_SLOT  R_C60_JMP_SLOT
#define R_GLOB_DAT  R_C60_GLOB_DAT
#define R_COPY      R_C60_COPY
#define R_RELATIVE  R_C60_RELATIVE

#define R_NUM       R_C60_NUM

#define ELF_START_ADDR 0x00000400
#define ELF_PAGE_SIZE  0x1000

#define PCRELATIVE_DLLPLT 0
#define RELOCATE_DLLPLT 0

#وإلا /* !TARGET_DEFS_ONLY */

#ضمن "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحيح code_reloc (صحيح reloc_type)
{
    بدل (reloc_type) {
        حالة R_C60_32:
	حالة R_C60LO16:
	حالة R_C60HI16:
        حالة R_C60_GOT32:
        حالة R_C60_GOTOFF:
        حالة R_C60_GOTPC:
        حالة R_C60_COPY:
            أرجع 0;

        حالة R_C60_PLT32:
            أرجع 1;
    }
    أرجع -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC صحيح gotplt_entry_type (صحيح reloc_type)
{
    بدل (reloc_type) {
        حالة R_C60_32:
	حالة R_C60LO16:
	حالة R_C60HI16:
        حالة R_C60_COPY:
            أرجع NO_GOTPLT_ENTRY;

        حالة R_C60_GOTOFF:
        حالة R_C60_GOTPC:
            أرجع BUILD_GOT_ONLY;

        حالة R_C60_PLT32:
        حالة R_C60_GOT32:
            أرجع ALWAYS_GOTPLT_ENTRY;
    }
    أرجع -1;
}

ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, بنية sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    أرجع 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC فراغ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    𐡄𐡍 (!s1->plt)
      أرجع;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    𐡄𐡍 (p < p_end) {
        /* XXX: TODO */
        طالما (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, unsigned حرف *ptr, addr_t addr, addr_t val)
{
    بدل(type) {
        حالة R_C60_32:
            *(صحيح *)ptr += val;
            اكسر;
        حالة R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(صحيح *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(صحيح *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(صحيح *) ptr    = (*(صحيح *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(صحيح *)(ptr+4) = (*(صحيح *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            اكسر;
        حالة R_C60HI16:
            اكسر;
        افتراضي:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (unsigned) addr, ptr, (unsigned) val);
            اكسر;
    }
}

#endif /* !TARGET_DEFS_ONLY */
