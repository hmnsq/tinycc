#నిర్వచితమైతే లక్ష్యం_DEFS_ONLY

#నిర్వచించు EM_TCC_లక్ష్యం EM_ARM

/* relocation type for 32 bit data relocation */
#నిర్వచించు R_దత్తాంశం_32   R_ARM_ABS32
#నిర్వచించు R_దత్తాంశం_PTR  R_ARM_ABS32
#నిర్వచించు R_JMP_స్థానం  R_ARM_JUMP_స్థానం
#నిర్వచించు R_GLOB_DAT  R_ARM_GLOB_DAT
#నిర్వచించు R_COPY      R_ARM_COPY
#నిర్వచించు R_RELATIVE  R_ARM_RELATIVE

#నిర్వచించు R_అంకె       R_ARM_అంకె

#నిర్వచించు ELF_ప్రారంభం_ADDR 0x00010000
#నిర్వచించు ELF_పుట_కొలత  0x10000

#నిర్వచించు PCRELATIVE_DLLPLT 1
#నిర్వచించు RELOCATE_DLLPLT 1

#లేకపోతే /* !TARGET_DEFS_ONLY */

#అన్తర్భావ "tcc.h"

#నిర్వచితమైతే NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC పూర్ణాంకం సంకేతం_reloc (పూర్ణాంకం reloc_type)
{
    ఎంపిక (reloc_type) {
	స్థితి R_ARM_MOVT_ABS:
	స్థితి R_ARM_MOVW_ABS_NC:
	స్థితి R_ARM_THM_MOVT_ABS:
	స్థితి R_ARM_THM_MOVW_ABS_NC:
	స్థితి R_ARM_ABS32:
	స్థితి R_ARM_REL32:
	స్థితి R_ARM_GOTPC:
	స్థితి R_ARM_GOTOFF:
	స్థితి R_ARM_GOT32:
	స్థితి R_ARM_GOT_PREL:
	స్థితి R_ARM_COPY:
	స్థితి R_ARM_GLOB_DAT:
	స్థితి R_ARM_NONE:
	స్థితి R_ARM_TARGET1:
	స్థితి R_ARM_MOVT_PREL:
	స్థితి R_ARM_MOVW_PREL_NC:
	స్థితి R_ARM_TLS_LE32:
            తిరిగి 0;

        స్థితి R_ARM_PC24:
        స్థితి R_ARM_CALL:
	స్థితి R_ARM_JUMP24:
	స్థితి R_ARM_PLT32:
	స్థితి R_ARM_THM_PC22:
	స్థితి R_ARM_THM_JUMP24:
	స్థితి R_ARM_PREL31:
	స్థితి R_ARM_V4BX:
	స్థితి R_ARM_JUMP_స్థానం:
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
	స్థితి R_ARM_NONE:
	స్థితి R_ARM_COPY:
	స్థితి R_ARM_GLOB_DAT:
	స్థితి R_ARM_JUMP_స్థానం:
	స్థితి R_ARM_TLS_LE32:
            తిరిగి NO_GOTPLT_నమోదు;

        స్థితి R_ARM_PC24:
        స్థితి R_ARM_CALL:
	స్థితి R_ARM_JUMP24:
	స్థితి R_ARM_PLT32:
	స్థితి R_ARM_THM_PC22:
	స్థితి R_ARM_THM_JUMP24:
	స్థితి R_ARM_MOVT_ABS:
	స్థితి R_ARM_MOVW_ABS_NC:
	స్థితి R_ARM_THM_MOVT_ABS:
	స్థితి R_ARM_THM_MOVW_ABS_NC:
	స్థితి R_ARM_PREL31:
	స్థితి R_ARM_ABS32:
	స్థితి R_ARM_REL32:
	స్థితి R_ARM_V4BX:
	స్థితి R_ARM_TARGET1:
	స్థితి R_ARM_MOVT_PREL:
	స్థితి R_ARM_MOVW_PREL_NC:
            తిరిగి AUTO_GOTPLT_నమోదు;

	స్థితి R_ARM_GOTPC:
	స్థితి R_ARM_GOTOFF:
            తిరిగి BUILD_GOT_ONLY;

	స్థితి R_ARM_GOT32:
	స్థితి R_ARM_GOT_PREL:
            తిరిగి ALWAYS_GOTPLT_నమోదు;
    }
    తిరిగి -1;
}

#నిర్వచితమైతే NEED_BUILD_GOT
ST_FUNC గుర్తులేని create_plt_నమోదు(TCCState *s1, గుర్తులేని got_స్థానభ్రంశం, నిర్మాణం sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    గుర్తులేని plt_స్థానభ్రంశం;

    /* when building a DLL, GOT entry accesses must be done relative to
       start of GOT (see x86_64 example above)  */

    /* empty PLT: create PLT0 entry that push address of call site and
       jump to ld.so resolution routine (GOT + 8) */
    ఒకవేళ (plt->దత్తాంశం_స్థానభ్రంశం == 0) {
        p = section_ptr_కూడు(plt, 20);
        write32le(p,    0xe52de004); /* push {lr}         */
        write32le(p+4,  0xe59fe004); /* ldr lr, [pc, #4] */
        write32le(p+8,  0xe08fe00e); /* add lr, pc, lr    */
        write32le(p+12, 0xe5bef008); /* ldr pc, [lr, #8]! */
        /* p+16 is set in relocate_plt */
    }
    plt_స్థానభ్రంశం = plt->దత్తాంశం_స్థానభ్రంశం;

    ఒకవేళ (attr->plt_thumb_stub) {
        p = section_ptr_కూడు(plt, 4);
        write32le(p,   0x4778); /* bx pc */
        write32le(p+2, 0x46c0); /* nop   */
    }
    p = section_ptr_కూడు(plt, 16);
    /* save GOT offset for relocate_plt */
    write32le(p + 4, got_స్థానభ్రంశం);
    తిరిగి plt_స్థానభ్రంశం;
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
        పూర్ణాంకం x = s1->got->sh_addr - s1->plt->sh_addr - 12;
        write32le(s1->plt->దత్తాంశం + 16, x - 4);
        p += 20;
        అయితే (p < p_చివర) {
	    గుర్తులేని off = x  + read32le(p + 4) + (s1->plt->దత్తాంశం - p) + 4;
            ఒకవేళ (read32le(p) == 0x46c04778) /* PLT Thumb stub present */
                p += 4;
            write32le(p, 0xe28fc200 | ((off >> 28) & 0xf));      // add ip, pc, #0xN0000000
            write32le(p + 4, 0xe28cc600 | ((off >> 20) & 0xff)); // add ip, pc, #0xNN00000
            write32le(p + 8, 0xe28cca00 | ((off >> 12) & 0xff)); // add ip, ip, #0xNN000
            write32le(p + 12, 0xe5bcf000 | (off & 0xfff));	 // ldr pc, [ip, #0xNNN]!
            p += 16;
        }
    }

    ఒకవేళ (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->దత్తాంశం;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_స్థానభ్రంశం, s1->plt->sh_addr);
	}
    }
}
#అయితే_ముగింపు
#అయితే_ముగింపు

ST_FUNC శూన్య relocate(TCCState *s1, ElfW_Rel *rel, పూర్ణాంకం type, గుర్తులేని అక్షరం *ptr, addr_t addr, addr_t val)
{
    ElfW(Sym) *sym;
    పూర్ణాంకం sym_సూచీ, esym_సూచీ;

    sym_సూచీ = ELFW(R_SYM)(rel->r_info);
    sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];

    ఎంపిక(type) {
        స్థితి R_ARM_PC24:
        స్థితి R_ARM_CALL:
        స్థితి R_ARM_JUMP24:
        స్థితి R_ARM_PLT32:
            {
                పూర్ణాంకం x, is_thumb, is_call, h, blx_avail, is_bl, th_ko;
                గుర్తులేని సంకేతం_2 = read32le(ptr);
                x = సంకేతం_2 & 0x00ffffff;
#నిర్వచితమైతే DEBUG_RELOC
		రాయి ("reloc %d: x=0x%x val=0x%x ", type, x, val);
#అయితే_ముగింపు
                సంకేతం_2 &= 0xff000000;
                x <<= 2;
                ఒకవేళ (x & 0x2000000)
                    x -= 0x4000000;
                blx_avail = (CONFIG_TCC_CPUVER >= 5);
                is_thumb = val & 1;
                is_bl = సంకేతం_2 == 0xeb000000;
                is_call = (type == R_ARM_CALL || (type == R_ARM_PC24 && is_bl));
                x += val - addr;
#నిర్వచితమైతే DEBUG_RELOC
		రాయి (" newx=0x%x name=%s\n", x,
			(అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name);
#అయితే_ముగింపు
                h = x & 2;
                th_ko = (x & 3) && (!blx_avail || !is_call);
                ఒకవేళ (th_ko || x >= 0x2000000 || x < -0x2000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                x >>= 2;
                x &= 0xffffff;
                /* Only reached if blx is avail and it is a call */
                ఒకవేళ (is_thumb) {
                    x |= h << 24;
                    సంకేతం_2 = 0xfa000000; /* bl -> blx */
                }
                write32le(ptr, సంకేతం_2 | x);
            }
            తిరిగి;
        /* Since these relocations only concern Thumb-2 and blx instruction was
           introduced before Thumb-2, we can assume blx is available and not
           guard its use */
        స్థితి R_ARM_THM_PC22:
        స్థితి R_ARM_THM_JUMP24:
            {
                పూర్ణాంకం x, hi, lo, s, j1, j2, i1, i2, imm10, imm11;
                పూర్ణాంకం గమ్యం_thumb, is_call, గమ్యం_plt, blx_బిట్టు = 1 << 12;
                Section *plt;

                /* weak reference */
                ఒకవేళ (sym->st_shndx == SHN_UNDEF &&
                    ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
                    తిరిగి;

                /* Get initial offset */
                hi = read16le(ptr);
                lo = read16le(ptr+2);
                s = (hi >> 10) & 1;
                j1 = (lo >> 13) & 1;
                j2 = (lo >> 11) & 1;
                i1 = (j1 ^ s) ^ 1;
                i2 = (j2 ^ s) ^ 1;
                imm10 = hi & 0x3ff;
                imm11 = lo & 0x7ff;
                x = (s << 24) | (i1 << 23) | (i2 << 22) |
                    (imm10 << 12) | (imm11 << 1);
                ఒకవేళ (x & 0x01000000)
                    x -= 0x02000000;

                /* Relocation infos */
                గమ్యం_thumb = val & 1;
                plt = s1->plt;
                గమ్యం_plt = (val >= plt->sh_addr) &&
                         (val < plt->sh_addr + plt->దత్తాంశం_స్థానభ్రంశం);
                is_call = (type == R_ARM_THM_PC22);

                ఒకవేళ (!గమ్యం_thumb && !గమ్యం_plt && !is_call) {
                    పూర్ణాంకం సూచీ;
                    uint8_t *p;
                    అక్షరం *name, buf[1024];
                    Section *పాఠ్యం;

                    name = (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name;
                    పాఠ్యం = s1->sections[sym->st_shndx];
                    /* Modify reloc to target a thumb stub to switch to ARM */
                    snprintf(buf, పరిమాణం(buf), "%s_from_thumb", name);
                    సూచీ = put_elf_sym(symtab_section,
                                        పాఠ్యం->దత్తాంశం_స్థానభ్రంశం + 1,
                                        sym->st_కొలత, sym->st_info, 0,
                                        sym->st_shndx, buf);
                    గమ్యం_thumb = 1;
                    val = పాఠ్యం->దత్తాంశం_స్థానభ్రంశం + 1;
                    rel->r_info = ELFW(R_INFO)(సూచీ, type);
                    /* Create a thumb stub function to switch to ARM mode */
                    put_elf_reloc(symtab_section, పాఠ్యం,
                                  పాఠ్యం->దత్తాంశం_స్థానభ్రంశం + 4, R_ARM_JUMP24,
                                  sym_సూచీ);
                    p = section_ptr_కూడు(పాఠ్యం, 8);
                    write32le(p,   0x4778); /* bx pc */
                    write32le(p+2, 0x46c0); /* nop   */
                    write32le(p+4, 0xeafffffe); /* b $sym */
                }

                /* Compute final offset */
                x += val - addr;
                ఒకవేళ (!గమ్యం_thumb && is_call) {
                    blx_బిట్టు = 0; /* bl -> blx */
                    x = (x + 3) & -4; /* Compute offset from aligned PC */
                }

                /* Check that relocation is possible
                   * offset must not be out of range
                   * if target is to be entered in arm mode:
                     - bit 1 must not set
                     - instruction must be a call (bl) or a jump to PLT */
                ఒకవేళ (!గమ్యం_thumb || x >= 0x1000000 || x < -0x1000000)
                    ఒకవేళ (గమ్యం_thumb || (val & 2) || (!is_call && !గమ్యం_plt))
                        tcc_error_noabort("can't relocate value at %x,%d",addr, type);

                /* Compute and store final offset */
                s = (x >> 24) & 1;
                i1 = (x >> 23) & 1;
                i2 = (x >> 22) & 1;
                j1 = s ^ (i1 ^ 1);
                j2 = s ^ (i2 ^ 1);
                imm10 = (x >> 12) & 0x3ff;
                imm11 = (x >> 1) & 0x7ff;
                write16le(ptr, (hi & 0xf800) |
                               (s << 10) | imm10);
                write16le(ptr+2, (lo & 0xc000) |
                                 (j1 << 13) | blx_బిట్టు | (j2 << 11) |
                                 imm11);
            }
            తిరిగి;
        స్థితి R_ARM_MOVT_ABS:
        స్థితి R_ARM_MOVW_ABS_NC:
            {
                పూర్ణాంకం x, imm4, imm12;
                ఒకవేళ (type == R_ARM_MOVT_ABS)
                    val >>= 16;
                imm12 = val & 0xfff;
                imm4 = (val >> 12) & 0xf;
                x = (imm4 << 16) | imm12;
                ఒకవేళ (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                లేకపోతే
                    add32le(ptr, x);
            }
            తిరిగి;
        స్థితి R_ARM_MOVT_PREL:
        స్థితి R_ARM_MOVW_PREL_NC:
            {
		పూర్ణాంకం insn = read32le(ptr);
                పూర్ణాంకం addend = ((insn >> 4) & 0xf000) | (insn & 0xfff);

		addend = (addend ^ 0x8000) - 0x8000;
		val += addend - addr;
		ఒకవేళ (type == R_ARM_MOVT_PREL)
		    val >>= 16;
		write32le(ptr, (insn & 0xfff0f000) |
			       ((val & 0xf000) << 4) | (val & 0xfff));
            }
            తిరిగి;
        స్థితి R_ARM_THM_MOVT_ABS:
        స్థితి R_ARM_THM_MOVW_ABS_NC:
            {
                పూర్ణాంకం x, i, imm4, imm3, imm8;
                ఒకవేళ (type == R_ARM_THM_MOVT_ABS)
                    val >>= 16;
                imm8 = val & 0xff;
                imm3 = (val >> 8) & 0x7;
                i = (val >> 11) & 1;
                imm4 = (val >> 12) & 0xf;
                x = (imm3 << 28) | (imm8 << 16) | (i << 10) | imm4;
                ఒకవేళ (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                లేకపోతే
                    add32le(ptr, x);
            }
            తిరిగి;
        స్థితి R_ARM_PREL31:
            {
                పూర్ణాంకం x;
                x = read32le(ptr) & 0x7fffffff;
                write32le(ptr, read32le(ptr) & 0x80000000);
                x = (x * 2) / 2;
                x += val - addr;
                ఒకవేళ((x^(x>>1))&0x40000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                write32le(ptr, read32le(ptr) | (x & 0x7fffffff));
            }
            తిరిగి;
        స్థితి R_ARM_ABS32:
        స్థితి R_ARM_TARGET1:
            ఒకవేళ (s1->output_type & TCC_OUTPUT_DYN) {
                esym_సూచీ = get_sym_attr(s1, sym_సూచీ, 0)->dyn_సూచీ;
                qrel->r_స్థానభ్రంశం = rel->r_స్థానభ్రంశం;
                ఒకవేళ (esym_సూచీ) {
                    qrel->r_info = ELFW(R_INFO)(esym_సూచీ, R_ARM_ABS32);
                    qrel++;
                    తిరిగి;
                } లేకపోతే {
                    qrel->r_info = ELFW(R_INFO)(0, R_ARM_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            తిరిగి;
        స్థితి R_ARM_REL32:
            add32le(ptr, val - addr);
            తిరిగి;
        స్థితి R_ARM_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            తిరిగి;
        స్థితి R_ARM_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            తిరిగి;
        స్థితి R_ARM_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_సూచీ, 0)->got_స్థానభ్రంశం);
            తిరిగి;
	స్థితి R_ARM_GOT_PREL:
            /* we load the pc relative got offset */
            add32le(ptr, s1->got->sh_addr +
			 get_sym_attr(s1, sym_సూచీ, 0)->got_స్థానభ్రంశం -
			 addr);
            తిరిగి;
        స్థితి R_ARM_COPY:
            తిరిగి;
        స్థితి R_ARM_V4BX:
            /* trade Thumb support for ARMv4 support */
            ఒకవేళ ((0x0ffffff0 & read32le(ptr)) == 0x012FFF10)
                write32le(ptr, read32le(ptr) ^ 0xE12FFF10 ^ 0xE1A0F000); /* BX Rm -> MOV PC, Rm */
            తిరిగి;
        స్థితి R_ARM_GLOB_DAT:
        స్థితి R_ARM_JUMP_స్థానం:
            write32le(ptr, val);
            తిరిగి;
        స్థితి R_ARM_NONE:
            /* Nothing to do.  Normally used to indicate a dependency
               on a certain symbol (like for exception handling under EABI).  */
            తిరిగి;
        స్థితి R_ARM_RELATIVE:
#నిర్వచితమైతే TCC_లక్ష్యం_PE
            add32le(ptr, val - s1->pe_imagebase);
#అయితే_ముగింపు
            /* do nothing */
            తిరిగి;
        స్థితి R_ARM_TLS_LE32:
            {
                int32_t x;
                ఒకవేళ (s1->tls_చివర) {
                    x = val - s1->tls_ప్రారంభం + 8;
                } లేకపోతే {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->దత్తాంశం_స్థానభ్రంశం + 8;
                }
                add32le(ptr, x);
            }
            తిరిగి;
        అప్రమేయ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (గుర్తులేని)addr, ptr, (గుర్తులేని)val);
            తిరిగి;
    }
}

#అయితే_ముగింపు /* !TARGET_DEFS_ONLY */
