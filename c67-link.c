#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_C60

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_C60_32
#define R_DATA_PTR  R_C60_32
#define R_JMP_SLOT  R_C60_JMP_SLOT
#define R_GLOB_DAT  R_C60_GLOB_DAT
#define R_COPY      R_C60_COPY
#define R_RELATIVE  R_C60_RELATIVE

#define R_இலக்கம்       R_C60_இலக்கம்

#define ELF_START_ADDR 0x00000400
#define ELF_PAGE_SIZE  0x1000

#define PCRELATIVE_DLLPLT 0
#define RELOCATE_DLLPLT 0

#இல்லையெனில் /* !TARGET_DEFS_ONLY */

#அந்தர்பாவ "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC முழு code_reloc (முழு reloc_type)
{
    தேர்வு (reloc_type) {
        நிலை R_C60_32:
	நிலை R_C60LO16:
	நிலை R_C60HI16:
        நிலை R_C60_GOT32:
        நிலை R_C60_GOTOFF:
        நிலை R_C60_GOTPC:
        நிலை R_C60_COPY:
            திரும்பு 0;

        நிலை R_C60_PLT32:
            திரும்பு 1;
    }
    திரும்பு -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC முழு gotplt_entry_type (முழு reloc_type)
{
    தேர்வு (reloc_type) {
        நிலை R_C60_32:
	நிலை R_C60LO16:
	நிலை R_C60HI16:
        நிலை R_C60_COPY:
            திரும்பு NO_GOTPLT_ENTRY;

        நிலை R_C60_GOTOFF:
        நிலை R_C60_GOTPC:
            திரும்பு BUILD_GOT_ONLY;

        நிலை R_C60_PLT32:
        நிலை R_C60_GOT32:
            திரும்பு ALWAYS_GOTPLT_ENTRY;
    }
    திரும்பு -1;
}

ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, கட்டமைப்பு sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    திரும்பு 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC வெறுமை relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    எனில் (!s1->plt)
      திரும்பு;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    எனில் (p < p_end) {
        /* XXX: TODO */
        போது (p < p_end) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC வெறுமை relocate(TCCState *s1, ElfW_Rel *rel, முழு type, unsigned எழுத்து *ptr, addr_t addr, addr_t val)
{
    தேர்வு(type) {
        நிலை R_C60_32:
            *(முழு *)ptr += val;
            நிறுத்து;
        நிலை R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(முழு *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(முழு *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(முழு *) ptr    = (*(முழு *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(முழு *)(ptr+4) = (*(முழு *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            நிறுத்து;
        நிலை R_C60HI16:
            நிறுத்து;
        இயல்பு:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (unsigned) addr, ptr, (unsigned) val);
            நிறுத்து;
    }
}

#endif /* !TARGET_DEFS_ONLY */
