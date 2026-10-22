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

#มิฉะนั้น /* !TARGET_DEFS_ONLY */

#include "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC จำนวนเต็ม code_reloc (จำนวนเต็ม reloc_type)
{
    switch (reloc_type) {
        pak_sa R_C60_32:
	pak_sa R_C60LO16:
	pak_sa R_C60HI16:
        pak_sa R_C60_GOT32:
        pak_sa R_C60_GOTOFF:
        pak_sa R_C60_GOTPC:
        pak_sa R_C60_COPY:
            คืน 0;

        pak_sa R_C60_PLT32:
            คืน 1;
    }
    คืน -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC จำนวนเต็ม gotplt_entry_type (จำนวนเต็ม reloc_type)
{
    switch (reloc_type) {
        pak_sa R_C60_32:
	pak_sa R_C60LO16:
	pak_sa R_C60HI16:
        pak_sa R_C60_COPY:
            คืน NO_GOTPLT_ENTRY;

        pak_sa R_C60_GOTOFF:
        pak_sa R_C60_GOTPC:
            คืน BUILD_GOT_ONLY;

        pak_sa R_C60_PLT32:
        pak_sa R_C60_GOT32:
            คืน ALWAYS_GOTPLT_ENTRY;
    }
    คืน -1;
}

ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, sa_nracanaa sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    คืน 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC void relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    ถ้า (!s1->plt)
      คืน;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    ถ้า (p < p_end) {
        /* XXX: TODO */
        ขณะ (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC void relocate(TCCState *s1, ElfW_Rel *rel, จำนวนเต็ม type, unsigned var_na *ptr, addr_t addr, addr_t val)
{
    switch(type) {
        pak_sa R_C60_32:
            *(จำนวนเต็ม *)ptr += val;
            bha_nga;
        pak_sa R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(จำนวนเต็ม *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(จำนวนเต็ม *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(จำนวนเต็ม *) ptr    = (*(จำนวนเต็ม *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(จำนวนเต็ม *)(ptr+4) = (*(จำนวนเต็ม *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            bha_nga;
        pak_sa R_C60HI16:
            bha_nga;
        default:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (unsigned) addr, ptr, (unsigned) val);
            bha_nga;
    }
}

#endif /* !TARGET_DEFS_ONLY */
