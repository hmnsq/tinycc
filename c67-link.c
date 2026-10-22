#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ਨਿਸ਼ਾਨਾ_DEFS_ONLY

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_TCC_ਨਿਸ਼ਾਨਾ EM_C60

/* relocation type for 32 bit data relocation */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕੜੇ_32   R_C60_32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕੜੇ_PTR  R_C60_32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_JMP_ਥਾਂ  R_C60_JMP_ਥਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_GLOB_DAT  R_C60_GLOB_DAT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_COPY      R_C60_COPY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_RELATIVE  R_C60_RELATIVE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕ       R_C60_ਅੰਕ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_ਸ਼ੁਰੂ_ADDR 0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_ਪੰਨਾ_ਮਾਪ  0x1000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCRELATIVE_DLLPLT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RELOCATE_DLLPLT 0

#ਨਹੀਂਤਾਂ /* !TARGET_DEFS_ONLY */

#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ਪੂਰਨ ਕੋਡ_reloc (ਪੂਰਨ reloc_type)
{
    ਚੋਣ (reloc_type) {
        ਹਾਲਤ R_C60_32:
	ਹਾਲਤ R_C60LO16:
	ਹਾਲਤ R_C60HI16:
        ਹਾਲਤ R_C60_GOT32:
        ਹਾਲਤ R_C60_GOTOFF:
        ਹਾਲਤ R_C60_GOTPC:
        ਹਾਲਤ R_C60_COPY:
            ਵਾਪਸ 0;

        ਹਾਲਤ R_C60_PLT32:
            ਵਾਪਸ 1;
    }
    ਵਾਪਸ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC ਪੂਰਨ gotplt_ਇੰਦਰਾਜ_type (ਪੂਰਨ reloc_type)
{
    ਚੋਣ (reloc_type) {
        ਹਾਲਤ R_C60_32:
	ਹਾਲਤ R_C60LO16:
	ਹਾਲਤ R_C60HI16:
        ਹਾਲਤ R_C60_COPY:
            ਵਾਪਸ NO_GOTPLT_ਇੰਦਰਾਜ;

        ਹਾਲਤ R_C60_GOTOFF:
        ਹਾਲਤ R_C60_GOTPC:
            ਵਾਪਸ BUILD_GOT_ONLY;

        ਹਾਲਤ R_C60_PLT32:
        ਹਾਲਤ R_C60_GOT32:
            ਵਾਪਸ ALWAYS_GOTPLT_ਇੰਦਰਾਜ;
    }
    ਵਾਪਸ -1;
}

ST_FUNC ਬਿਨਾਨਿਸ਼ਾਨੀ create_plt_ਇੰਦਰਾਜ(TCCState *s1, ਬਿਨਾਨਿਸ਼ਾਨੀ got_ਵਿੱਥ, ਬਣਤਰ sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    ਵਾਪਸ 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC ਖਾਲੀ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_ਸਿਰਾ;

    ਜੇ (!s1->plt)
      ਵਾਪਸ;

    p = s1->plt->ਅੰਕੜੇ;
    p_ਸਿਰਾ = p + s1->plt->ਅੰਕੜੇ_ਵਿੱਥ;

    ਜੇ (p < p_ਸਿਰਾ) {
        /* XXX: TODO */
        ਜਦੋਂ (p < p_ਸਿਰਾ) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC ਖਾਲੀ relocate(TCCState *s1, ElfW_Rel *rel, ਪੂਰਨ type, ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr, addr_t addr, addr_t val)
{
    ਚੋਣ(type) {
        ਹਾਲਤ R_C60_32:
            *(ਪੂਰਨ *)ptr += val;
            ਰੋਕੋ;
        ਹਾਲਤ R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(ਪੂਰਨ *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(ਪੂਰਨ *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(ਪੂਰਨ *) ptr    = (*(ਪੂਰਨ *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(ਪੂਰਨ *)(ptr+4) = (*(ਪੂਰਨ *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            ਰੋਕੋ;
        ਹਾਲਤ R_C60HI16:
            ਰੋਕੋ;
        ਮੂਲ:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (ਬਿਨਾਨਿਸ਼ਾਨੀ) addr, ptr, (ਬਿਨਾਨਿਸ਼ਾਨੀ) val);
            ਰੋਕੋ;
    }
}

#ਜੇ_ਅੰਤ /* !TARGET_DEFS_ONLY */
