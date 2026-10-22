#اگر_تعریف_شده هدف_DEFS_ONLY

#تعریف_کن EM_TCC_هدف EM_C60

/* relocation type for 32 bit data relocation */
#تعریف_کن R_داده_32   R_C60_32
#تعریف_کن R_داده_PTR  R_C60_32
#تعریف_کن R_JMP_جایگاه  R_C60_JMP_جایگاه
#تعریف_کن R_GLOB_DAT  R_C60_GLOB_DAT
#تعریف_کن R_COPY      R_C60_COPY
#تعریف_کن R_RELATIVE  R_C60_RELATIVE

#تعریف_کن R_رقم       R_C60_رقم

#تعریف_کن ELF_شروع_ADDR 0x00000400
#تعریف_کن ELF_صفحه_اندازه  0x1000

#تعریف_کن PCRELATIVE_DLLPLT 0
#تعریف_کن RELOCATE_DLLPLT 0

#وإلا /* !TARGET_DEFS_ONLY */

#ضمن "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحيح کد_reloc (صحيح reloc_type)
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
ST_FUNC صحيح gotplt_مدخل_type (صحيح reloc_type)
{
    بدل (reloc_type) {
        حالة R_C60_32:
	حالة R_C60LO16:
	حالة R_C60HI16:
        حالة R_C60_COPY:
            أرجع NO_GOTPLT_مدخل;

        حالة R_C60_GOTOFF:
        حالة R_C60_GOTPC:
            أرجع BUILD_GOT_ONLY;

        حالة R_C60_PLT32:
        حالة R_C60_GOT32:
            أرجع ALWAYS_GOTPLT_مدخل;
    }
    أرجع -1;
}

ST_FUNC بیعلامت create_plt_مدخل(TCCState *s1, بیعلامت got_جابه_جایی, بنية sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    أرجع 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC فراغ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_انتها;

    إذا (!s1->plt)
      أرجع;

    p = s1->plt->داده;
    p_انتها = p + s1->plt->داده_جابه_جایی;

    إذا (p < p_انتها) {
        /* XXX: TODO */
        طالما (p < p_انتها) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, بیعلامت حرف *ptr, addr_t addr, addr_t val)
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
                    type, (بیعلامت) addr, ptr, (بیعلامت) val);
            اكسر;
    }
}

#پایان_اگر /* !TARGET_DEFS_ONLY */
