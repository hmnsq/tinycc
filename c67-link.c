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

#ᮜᮤᮚ /* !TARGET_DEFS_ONLY */

#include "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC puur_naa_nka code_reloc (puur_naa_nka reloc_type)
{
    switch (reloc_type) {
        pak_sa R_C60_32:
	pak_sa R_C60LO16:
	pak_sa R_C60HI16:
        pak_sa R_C60_GOT32:
        pak_sa R_C60_GOTOFF:
        pak_sa R_C60_GOTPC:
        pak_sa R_C60_COPY:
            ᮝᮜᮤ 0;

        pak_sa R_C60_PLT32:
            ᮝᮜᮤ 1;
    }
    ᮝᮜᮤ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC puur_naa_nka gotplt_entry_type (puur_naa_nka reloc_type)
{
    switch (reloc_type) {
        pak_sa R_C60_32:
	pak_sa R_C60LO16:
	pak_sa R_C60HI16:
        pak_sa R_C60_COPY:
            ᮝᮜᮤ NO_GOTPLT_ENTRY;

        pak_sa R_C60_GOTOFF:
        pak_sa R_C60_GOTPC:
            ᮝᮜᮤ BUILD_GOT_ONLY;

        pak_sa R_C60_PLT32:
        pak_sa R_C60_GOT32:
            ᮝᮜᮤ ALWAYS_GOTPLT_ENTRY;
    }
    ᮝᮜᮤ -1;
}

ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, sa_nracanaa sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    ᮝᮜᮤ 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC void relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    ᮚᮦᮔ᮪ (!s1->plt)
      ᮝᮜᮤ;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    ᮚᮦᮔ᮪ (p < p_end) {
        /* XXX: TODO */
        ᮞᮨᮓᮨᮜ (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC void relocate(TCCState *s1, ElfW_Rel *rel, puur_naa_nka type, unsigned var_na *ptr, addr_t addr, addr_t val)
{
    switch(type) {
        pak_sa R_C60_32:
            *(puur_naa_nka *)ptr += val;
            bha_nga;
        pak_sa R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(puur_naa_nka *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(puur_naa_nka *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(puur_naa_nka *) ptr    = (*(puur_naa_nka *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(puur_naa_nka *)(ptr+4) = (*(puur_naa_nka *)(ptr+4) & (~(0xffff << 7)) ) |
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
