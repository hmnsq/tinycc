#నిర్వచితమైతే లక్ష్యం_DEFS_ONLY

#నిర్వచించు EM_TCC_లక్ష్యం EM_C60

/* relocation type for 32 bit data relocation */
#నిర్వచించు R_దత్తాంశం_32   R_C60_32
#నిర్వచించు R_దత్తాంశం_PTR  R_C60_32
#నిర్వచించు R_JMP_స్థానం  R_C60_JMP_స్థానం
#నిర్వచించు R_GLOB_DAT  R_C60_GLOB_DAT
#నిర్వచించు R_COPY      R_C60_COPY
#నిర్వచించు R_RELATIVE  R_C60_RELATIVE

#నిర్వచించు R_అంకె       R_C60_అంకె

#నిర్వచించు ELF_ప్రారంభం_ADDR 0x00000400
#నిర్వచించు ELF_పుట_కొలత  0x1000

#నిర్వచించు PCRELATIVE_DLLPLT 0
#నిర్వచించు RELOCATE_DLLPLT 0

#లేకపోతే /* !TARGET_DEFS_ONLY */

#అన్తర్భావ "tcc.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC పూర్ణాంకం సంకేతం_reloc (పూర్ణాంకం reloc_type)
{
    ఎంపిక (reloc_type) {
        స్థితి R_C60_32:
	స్థితి R_C60LO16:
	స్థితి R_C60HI16:
        స్థితి R_C60_GOT32:
        స్థితి R_C60_GOTOFF:
        స్థితి R_C60_GOTPC:
        స్థితి R_C60_COPY:
            తిరిగి 0;

        స్థితి R_C60_PLT32:
            తిరిగి 1;
    }
    తిరిగి -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC పూర్ణాంకం gotplt_నమోదు_type (పూర్ణాంకం reloc_type)
{
    ఎంపిక (reloc_type) {
        స్థితి R_C60_32:
	స్థితి R_C60LO16:
	స్థితి R_C60HI16:
        స్థితి R_C60_COPY:
            తిరిగి NO_GOTPLT_నమోదు;

        స్థితి R_C60_GOTOFF:
        స్థితి R_C60_GOTPC:
            తిరిగి BUILD_GOT_ONLY;

        స్థితి R_C60_PLT32:
        స్థితి R_C60_GOT32:
            తిరిగి ALWAYS_GOTPLT_నమోదు;
    }
    తిరిగి -1;
}

ST_FUNC గుర్తులేని create_plt_నమోదు(TCCState *s1, గుర్తులేని got_స్థానభ్రంశం, నిర్మాణం sym_attr *attr)
{
    tcc_error_noabort("C67 got not implemented");
    తిరిగి 0;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC శూన్య relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_చివర;

    ఒకవేళ (!s1->plt)
      తిరిగి;

    p = s1->plt->దత్తాంశం;
    p_చివర = p + s1->plt->దత్తాంశం_స్థానభ్రంశం;

    ఒకవేళ (p < p_చివర) {
        /* XXX: TODO */
        అయితే (p < p_చివర) {
            /* XXX: TODO */
        }
   }
}

ST_FUNC శూన్య relocate(TCCState *s1, ElfW_Rel *rel, పూర్ణాంకం type, గుర్తులేని అక్షరం *ptr, addr_t addr, addr_t val)
{
    ఎంపిక(type) {
        స్థితి R_C60_32:
            *(పూర్ణాంకం *)ptr += val;
            ఆపు;
        స్థితి R_C60LO16:
            {
                uint32_t orig;

                /* put the low 16 bits of the absolute address add to what is
                   already there */
                orig  =   ((*(పూర్ణాంకం *)(ptr  )) >> 7) & 0xffff;
                orig |=  (((*(పూర్ణాంకం *)(ptr+4)) >> 7) & 0xffff) << 16;

                /* patch both at once - assumes always in pairs Low - High */
                *(పూర్ణాంకం *) ptr    = (*(పూర్ణాంకం *) ptr    & (~(0xffff << 7)) ) |
                                   (((val+orig)      & 0xffff) << 7);
                *(పూర్ణాంకం *)(ptr+4) = (*(పూర్ణాంకం *)(ptr+4) & (~(0xffff << 7)) ) |
                                  ((((val+orig)>>16) & 0xffff) << 7);
            }
            ఆపు;
        స్థితి R_C60HI16:
            ఆపు;
        అప్రమేయ:
            fprintf(stderr,"FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (గుర్తులేని) addr, ptr, (గుర్తులేని) val);
            ఆపు;
    }
}

#అయితే_ముగింపు /* !TARGET_DEFS_ONLY */
