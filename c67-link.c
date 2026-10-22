#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_C60

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_C60_32
#define R_DATA_PTR  R_C60_32
#define R_JMP_SLOT  R_C60_JMP_SLOT
#define R_GLOB_DAT  R_C60_GLOB_DAT
#define R_COPY      R_C60_COPY
#define R_RELATIVE  R_C60_RELATIVE

#define R_അക്കം       R_C60_അക്കം

#define ELF_START_ADDR 0x00000400
#define ELF_PAGE_SIZE  0x1000

#define PCRELATIVE_DLLPLT 0
#define RELOCATE_DLLPLT 0

#അല്ലെങ്കിൽ /* !TARGET_DEFS_ONLY */

#അന്തര്ഭാവ "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC പൂർണ്ണസംഖ്യ code_reloc (പൂർണ്ണസംഖ്യ reloc_type)
{
    തിരഞ്ഞെടുപ്പ് (reloc_type) {
        അവസ്ഥ R_C60_32:
	അവസ്ഥ R_C60LO16:
	അവസ്ഥ R_C60HI16:
        അവസ്ഥ R_C60_GOT32:
        അവസ്ഥ R_C60_GOTOFF:
        അവസ്ഥ R_C60_GOTPC:
        അവസ്ഥ R_C60_COPY:
            തിരികെ 0;

        അവസ്ഥ R_C60_PLT32:
            തിരികെ 1;
    }
    തിരികെ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC പൂർണ്ണസംഖ്യ gotplt_entry_type (പൂർണ്ണസംഖ്യ reloc_type)
{
    തിരഞ്ഞെടുപ്പ് (reloc_type) {
        അവസ്ഥ R_C60_32:
	അവസ്ഥ R_C60LO16:
	അവസ്ഥ R_C60HI16:
        അവസ്ഥ R_C60_COPY:
            തിരികെ NO_GOTPLT_ENTRY;

        അവസ്ഥ R_C60_GOTOFF:
        അവസ്ഥ R_C60_GOTPC:
            തിരികെ BUILD_GOT_ONLY;

        അവസ്ഥ R_C60_PLT32:
        അവസ്ഥ R_C60_GOT32:
            തിരികെ ALWAYS_GOTPLT_ENTRY;
    }
    തിരികെ -1;
}

ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, ഘടന sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    തിരികെ 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC ശൂന്യം relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    എങ്കിൽ (!s1->plt)
      തിരികെ;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    എങ്കിൽ (p < p_end) {
        /* XXX: TODO */
        ആകുമ്പോൾ (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC ശൂന്യം relocate(TCCState *s1, ElfW_Rel *rel, പൂർണ്ണസംഖ്യ type, unsigned അക്ഷരം *ptr, addr_t addr, addr_t val)
{
    തിരഞ്ഞെടുപ്പ്(type) {
        അവസ്ഥ R_C60_32:
            *(പൂർണ്ണസംഖ്യ *)ptr += val;
            നിർത്തുക;
        അവസ്ഥ R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(പൂർണ്ണസംഖ്യ *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(പൂർണ്ണസംഖ്യ *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(പൂർണ്ണസംഖ്യ *) ptr    = (*(പൂർണ്ണസംഖ്യ *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(പൂർണ്ണസംഖ്യ *)(ptr+4) = (*(പൂർണ്ണസംഖ്യ *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            നിർത്തുക;
        അവസ്ഥ R_C60HI16:
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (unsigned) addr, ptr, (unsigned) val);
            നിർത്തുക;
    }
}

#endif /* !TARGET_DEFS_ONLY */
