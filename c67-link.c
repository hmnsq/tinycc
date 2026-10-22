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

#инако /* !TARGET_DEFS_ONLY */

#include "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC цео code_reloc (цео reloc_type)
{
    switch (reloc_type) {
        case R_C60_32:
	case R_C60LO16:
	case R_C60HI16:
        case R_C60_GOT32:
        case R_C60_GOTOFF:
        case R_C60_GOTPC:
        case R_C60_COPY:
            врати 0;

        case R_C60_PLT32:
            врати 1;
    }
    врати -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC цео gotplt_entry_type (цео reloc_type)
{
    switch (reloc_type) {
        case R_C60_32:
	case R_C60LO16:
	case R_C60HI16:
        case R_C60_COPY:
            врати NO_GOTPLT_ENTRY;

        case R_C60_GOTOFF:
        case R_C60_GOTPC:
            врати BUILD_GOT_ONLY;

        case R_C60_PLT32:
        case R_C60_GOT32:
            врати ALWAYS_GOTPLT_ENTRY;
    }
    врати -1;
}

ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, struct sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    врати 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC void relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    ако (!s1->plt)
      врати;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    ако (p < p_end) {
        /* XXX: TODO */
        док (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC void relocate(TCCState *s1, ElfW_Rel *rel, цео type, unsigned char *ptr, addr_t addr, addr_t val)
{
    switch(type) {
        case R_C60_32:
            *(цео *)ptr += val;
            break;
        case R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(цео *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(цео *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(цео *) ptr    = (*(цео *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(цео *)(ptr+4) = (*(цео *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            break;
        case R_C60HI16:
            break;
        default:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (unsigned) addr, ptr, (unsigned) val);
            break;
    }
}

#endif /* !TARGET_DEFS_ONLY */
