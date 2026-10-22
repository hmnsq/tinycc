#اگر_تعریف_شدہ ہدف_DEFS_ONLY

#تعریف_کرو EM_TCC_ہدف EM_C60

/* relocation type for 32 bit data relocation */
#تعریف_کرو R_ڈیٹا_32   R_C60_32
#تعریف_کرو R_ڈیٹا_PTR  R_C60_32
#تعریف_کرو R_JMP_خانہ  R_C60_JMP_خانہ
#تعریف_کرو R_GLOB_DAT  R_C60_GLOB_DAT
#تعریف_کرو R_COPY      R_C60_COPY
#تعریف_کرو R_RELATIVE  R_C60_RELATIVE

#تعریف_کرو R_عدد       R_C60_عدد

#تعریف_کرو ELF_آغاز_ADDR 0x00000400
#تعریف_کرو ELF_صفحہ_سائز  0x1000

#تعریف_کرو PCRELATIVE_DLLPLT 0
#تعریف_کرو RELOCATE_DLLPLT 0

#ورنہ /* !TARGET_DEFS_ONLY */

#شامل "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحیح رمز_reloc (صحیح reloc_type)
{
    انتخاب (reloc_type) {
        حالت R_C60_32:
	حالت R_C60LO16:
	حالت R_C60HI16:
        حالت R_C60_GOT32:
        حالت R_C60_GOTOFF:
        حالت R_C60_GOTPC:
        حالت R_C60_COPY:
            واپس 0;

        حالت R_C60_PLT32:
            واپس 1;
    }
    واپس -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC صحیح gotplt_اندراج_type (صحیح reloc_type)
{
    انتخاب (reloc_type) {
        حالت R_C60_32:
	حالت R_C60LO16:
	حالت R_C60HI16:
        حالت R_C60_COPY:
            واپس NO_GOTPLT_اندراج;

        حالت R_C60_GOTOFF:
        حالت R_C60_GOTPC:
            واپس BUILD_GOT_ONLY;

        حالت R_C60_PLT32:
        حالت R_C60_GOT32:
            واپس ALWAYS_GOTPLT_اندراج;
    }
    واپس -1;
}

ST_FUNC غیرعلامتی create_plt_اندراج(TCCState *s1, غیرعلامتی got_انحراف, ساخت sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    واپس 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC خالی relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_انتہا;

    اگر (!s1->plt)
      واپس;

    p = s1->plt->ڈیٹا;
    p_انتہا = p + s1->plt->ڈیٹا_انحراف;

    اگر (p < p_انتہا) {
        /* XXX: TODO */
        جب (p < p_انتہا) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC خالی relocate(TCCState *s1, ElfW_Rel *rel, صحیح type, غیرعلامتی حرف *ptr, addr_t addr, addr_t val)
{
    انتخاب(type) {
        حالت R_C60_32:
            *(صحیح *)ptr += val;
            توڑو;
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
            توڑو;
        حالت R_C60HI16:
            توڑو;
        طےشدہ:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (غیرعلامتی) addr, ptr, (غیرعلامتی) val);
            توڑو;
    }
}

#اگر_ختم /* !TARGET_DEFS_ONLY */
