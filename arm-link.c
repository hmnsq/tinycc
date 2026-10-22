#که_تعریف_شوی موخه_DEFS_ONLY

#تعریف_کړه EM_TCC_موخه EM_ARM

/* relocation type for 32 bit data relocation */
#تعریف_کړه R_معلومات_32   R_ARM_ABS32
#تعریف_کړه R_معلومات_PTR  R_ARM_ABS32
#تعریف_کړه R_JMP_خونه  R_ARM_JUMP_خونه
#تعریف_کړه R_GLOB_DAT  R_ARM_GLOB_DAT
#تعریف_کړه R_COPY      R_ARM_COPY
#تعریف_کړه R_RELATIVE  R_ARM_RELATIVE

#تعریف_کړه R_عدد       R_ARM_عدد

#تعریف_کړه ELF_پیل_ADDR 0x00010000
#تعریف_کړه ELF_پاڼه_اندازه  0x10000

#تعریف_کړه PCRELATIVE_DLLPLT 1
#تعریف_کړه RELOCATE_DLLPLT 1

#وإلا /* !TARGET_DEFS_ONLY */

#ضمن "tcc.h"

#که_تعریف_شوی NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحيح کوډ_reloc (صحيح reloc_type)
{
    بدل (reloc_type) {
	حالة R_ARM_MOVT_ABS:
	حالة R_ARM_MOVW_ABS_NC:
	حالة R_ARM_THM_MOVT_ABS:
	حالة R_ARM_THM_MOVW_ABS_NC:
	حالة R_ARM_ABS32:
	حالة R_ARM_REL32:
	حالة R_ARM_GOTPC:
	حالة R_ARM_GOTOFF:
	حالة R_ARM_GOT32:
	حالة R_ARM_GOT_PREL:
	حالة R_ARM_COPY:
	حالة R_ARM_GLOB_DAT:
	حالة R_ARM_NONE:
	حالة R_ARM_TARGET1:
	حالة R_ARM_MOVT_PREL:
	حالة R_ARM_MOVW_PREL_NC:
	حالة R_ARM_TLS_LE32:
            أرجع 0;

        حالة R_ARM_PC24:
        حالة R_ARM_CALL:
	حالة R_ARM_JUMP24:
	حالة R_ARM_PLT32:
	حالة R_ARM_THM_PC22:
	حالة R_ARM_THM_JUMP24:
	حالة R_ARM_PREL31:
	حالة R_ARM_V4BX:
	حالة R_ARM_JUMP_خونه:
            أرجع 1;
    }
    أرجع -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC صحيح gotplt_ثبت_type (صحيح reloc_type)
{
    بدل (reloc_type) {
	حالة R_ARM_NONE:
	حالة R_ARM_COPY:
	حالة R_ARM_GLOB_DAT:
	حالة R_ARM_JUMP_خونه:
	حالة R_ARM_TLS_LE32:
            أرجع NO_GOTPLT_ثبت;

        حالة R_ARM_PC24:
        حالة R_ARM_CALL:
	حالة R_ARM_JUMP24:
	حالة R_ARM_PLT32:
	حالة R_ARM_THM_PC22:
	حالة R_ARM_THM_JUMP24:
	حالة R_ARM_MOVT_ABS:
	حالة R_ARM_MOVW_ABS_NC:
	حالة R_ARM_THM_MOVT_ABS:
	حالة R_ARM_THM_MOVW_ABS_NC:
	حالة R_ARM_PREL31:
	حالة R_ARM_ABS32:
	حالة R_ARM_REL32:
	حالة R_ARM_V4BX:
	حالة R_ARM_TARGET1:
	حالة R_ARM_MOVT_PREL:
	حالة R_ARM_MOVW_PREL_NC:
            أرجع AUTO_GOTPLT_ثبت;

	حالة R_ARM_GOTPC:
	حالة R_ARM_GOTOFF:
            أرجع BUILD_GOT_ONLY;

	حالة R_ARM_GOT32:
	حالة R_ARM_GOT_PREL:
            أرجع ALWAYS_GOTPLT_ثبت;
    }
    أرجع -1;
}

#که_تعریف_شوی NEED_BUILD_GOT
ST_FUNC بینښه create_plt_ثبت(TCCState *s1, بینښه got_دننه_واټن, بنية sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    بینښه plt_دننه_واټن;

    /* when building a DLL, GOT entry accesses must be done relative to
       start of GOT (see x86_64 example above)  */

    /* empty PLT: create PLT0 entry that push address of call site and
       jump to ld.so resolution routine (GOT + 8) */
    إذا (plt->معلومات_دننه_واټن == 0) {
        p = section_ptr_جمع_کړه(plt, 20);
        write32le(p,    0xe52de004); /* push {lr}         */
        write32le(p+4,  0xe59fe004); /* ldr lr, [pc, #4] */
        write32le(p+8,  0xe08fe00e); /* add lr, pc, lr    */
        write32le(p+12, 0xe5bef008); /* ldr pc, [lr, #8]! */
        /* p+16 is set in relocate_plt */
    }
    plt_دننه_واټن = plt->معلومات_دننه_واټن;

    إذا (attr->plt_thumb_stub) {
        p = section_ptr_جمع_کړه(plt, 4);
        write32le(p,   0x4778); /* bx pc */
        write32le(p+2, 0x46c0); /* nop   */
    }
    p = section_ptr_جمع_کړه(plt, 16);
    /* save GOT offset for relocate_plt */
    write32le(p + 4, got_دننه_واټن);
    أرجع plt_دننه_واټن;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC فراغ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_پای_ټکی;

    إذا (!s1->plt)
      أرجع;

    p = s1->plt->معلومات;
    p_پای_ټکی = p + s1->plt->معلومات_دننه_واټن;

    إذا (p < p_پای_ټکی) {
        صحيح x = s1->got->sh_addr - s1->plt->sh_addr - 12;
        write32le(s1->plt->معلومات + 16, x - 4);
        p += 20;
        طالما (p < p_پای_ټکی) {
	    بینښه off = x  + read32le(p + 4) + (s1->plt->معلومات - p) + 4;
            إذا (read32le(p) == 0x46c04778) /* PLT Thumb stub present */
                p += 4;
            write32le(p, 0xe28fc200 | ((off >> 28) & 0xf));      // add ip, pc, #0xN0000000
            write32le(p + 4, 0xe28cc600 | ((off >> 20) & 0xff)); // add ip, pc, #0xNN00000
            write32le(p + 8, 0xe28cca00 | ((off >> 12) & 0xff)); // add ip, ip, #0xNN000
            write32le(p + 12, 0xe5bcf000 | (off & 0xfff));	 // ldr pc, [ip, #0xNNN]!
            p += 16;
        }
    }

    إذا (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->معلومات;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_دننه_واټن, s1->plt->sh_addr);
	}
    }
}
#د_که_پای
#د_که_پای

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, بینښه حرف *ptr, addr_t addr, addr_t val)
{
    ElfW(Sym) *sym;
    صحيح sym_شاخص, esym_شاخص;

    sym_شاخص = ELFW(R_SYM)(rel->r_info);
    sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];

    بدل(type) {
        حالة R_ARM_PC24:
        حالة R_ARM_CALL:
        حالة R_ARM_JUMP24:
        حالة R_ARM_PLT32:
            {
                صحيح x, is_thumb, is_call, h, blx_avail, is_bl, th_ko;
                بینښه کوډ = read32le(ptr);
                x = کوډ & 0x00ffffff;
#که_تعریف_شوی DEBUG_RELOC
		چاپ_کړه ("reloc %d: x=0x%x val=0x%x ", type, x, val);
#د_که_پای
                کوډ &= 0xff000000;
                x <<= 2;
                إذا (x & 0x2000000)
                    x -= 0x4000000;
                blx_avail = (CONFIG_TCC_CPUVER >= 5);
                is_thumb = val & 1;
                is_bl = کوډ == 0xeb000000;
                is_call = (type == R_ARM_CALL || (type == R_ARM_PC24 && is_bl));
                x += val - addr;
#که_تعریف_شوی DEBUG_RELOC
		چاپ_کړه (" newx=0x%x name=%s\n", x,
			(حرف *) symtab_section->link->معلومات + sym->st_name);
#د_که_پای
                h = x & 2;
                th_ko = (x & 3) && (!blx_avail || !is_call);
                إذا (th_ko || x >= 0x2000000 || x < -0x2000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                x >>= 2;
                x &= 0xffffff;
                /* Only reached if blx is avail and it is a call */
                إذا (is_thumb) {
                    x |= h << 24;
                    کوډ = 0xfa000000; /* bl -> blx */
                }
                write32le(ptr, کوډ | x);
            }
            أرجع;
        /* Since these relocations only concern Thumb-2 and blx instruction was
           introduced before Thumb-2, we can assume blx is available and not
           guard its use */
        حالة R_ARM_THM_PC22:
        حالة R_ARM_THM_JUMP24:
            {
                صحيح x, hi, lo, s, j1, j2, i1, i2, imm10, imm11;
                صحيح منزل_thumb, is_call, منزل_plt, blx_بټ = 1 << 12;
                Section *plt;

                /* weak reference */
                إذا (sym->st_shndx == SHN_UNDEF &&
                    ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
                    أرجع;

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
                إذا (x & 0x01000000)
                    x -= 0x02000000;

                /* Relocation infos */
                منزل_thumb = val & 1;
                plt = s1->plt;
                منزل_plt = (val >= plt->sh_addr) &&
                         (val < plt->sh_addr + plt->معلومات_دننه_واټن);
                is_call = (type == R_ARM_THM_PC22);

                إذا (!منزل_thumb && !منزل_plt && !is_call) {
                    صحيح شاخص;
                    uint8_t *p;
                    حرف *name, buf[1024];
                    Section *متن;

                    name = (حرف *) symtab_section->link->معلومات + sym->st_name;
                    متن = s1->sections[sym->st_shndx];
                    /* Modify reloc to target a thumb stub to switch to ARM */
                    snprintf(buf, حجم(buf), "%s_from_thumb", name);
                    شاخص = put_elf_sym(symtab_section,
                                        متن->معلومات_دننه_واټن + 1,
                                        sym->st_اندازه, sym->st_info, 0,
                                        sym->st_shndx, buf);
                    منزل_thumb = 1;
                    val = متن->معلومات_دننه_واټن + 1;
                    rel->r_info = ELFW(R_INFO)(شاخص, type);
                    /* Create a thumb stub function to switch to ARM mode */
                    put_elf_reloc(symtab_section, متن,
                                  متن->معلومات_دننه_واټن + 4, R_ARM_JUMP24,
                                  sym_شاخص);
                    p = section_ptr_جمع_کړه(متن, 8);
                    write32le(p,   0x4778); /* bx pc */
                    write32le(p+2, 0x46c0); /* nop   */
                    write32le(p+4, 0xeafffffe); /* b $sym */
                }

                /* Compute final offset */
                x += val - addr;
                إذا (!منزل_thumb && is_call) {
                    blx_بټ = 0; /* bl -> blx */
                    x = (x + 3) & -4; /* Compute offset from aligned PC */
                }

                /* Check that relocation is possible
                   * offset must not be out of range
                   * if target is to be entered in arm mode:
                     - bit 1 must not set
                     - instruction must be a call (bl) or a jump to PLT */
                إذا (!منزل_thumb || x >= 0x1000000 || x < -0x1000000)
                    إذا (منزل_thumb || (val & 2) || (!is_call && !منزل_plt))
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
                                 (j1 << 13) | blx_بټ | (j2 << 11) |
                                 imm11);
            }
            أرجع;
        حالة R_ARM_MOVT_ABS:
        حالة R_ARM_MOVW_ABS_NC:
            {
                صحيح x, imm4, imm12;
                إذا (type == R_ARM_MOVT_ABS)
                    val >>= 16;
                imm12 = val & 0xfff;
                imm4 = (val >> 12) & 0xf;
                x = (imm4 << 16) | imm12;
                إذا (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                وإلا
                    add32le(ptr, x);
            }
            أرجع;
        حالة R_ARM_MOVT_PREL:
        حالة R_ARM_MOVW_PREL_NC:
            {
		صحيح insn = read32le(ptr);
                صحيح addend = ((insn >> 4) & 0xf000) | (insn & 0xfff);

		addend = (addend ^ 0x8000) - 0x8000;
		val += addend - addr;
		إذا (type == R_ARM_MOVT_PREL)
		    val >>= 16;
		write32le(ptr, (insn & 0xfff0f000) |
			       ((val & 0xf000) << 4) | (val & 0xfff));
            }
            أرجع;
        حالة R_ARM_THM_MOVT_ABS:
        حالة R_ARM_THM_MOVW_ABS_NC:
            {
                صحيح x, i, imm4, imm3, imm8;
                إذا (type == R_ARM_THM_MOVT_ABS)
                    val >>= 16;
                imm8 = val & 0xff;
                imm3 = (val >> 8) & 0x7;
                i = (val >> 11) & 1;
                imm4 = (val >> 12) & 0xf;
                x = (imm3 << 28) | (imm8 << 16) | (i << 10) | imm4;
                إذا (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                وإلا
                    add32le(ptr, x);
            }
            أرجع;
        حالة R_ARM_PREL31:
            {
                صحيح x;
                x = read32le(ptr) & 0x7fffffff;
                write32le(ptr, read32le(ptr) & 0x80000000);
                x = (x * 2) / 2;
                x += val - addr;
                إذا((x^(x>>1))&0x40000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                write32le(ptr, read32le(ptr) | (x & 0x7fffffff));
            }
            أرجع;
        حالة R_ARM_ABS32:
        حالة R_ARM_TARGET1:
            إذا (s1->output_type & TCC_OUTPUT_DYN) {
                esym_شاخص = get_sym_attr(s1, sym_شاخص, 0)->dyn_شاخص;
                qrel->r_دننه_واټن = rel->r_دننه_واټن;
                إذا (esym_شاخص) {
                    qrel->r_info = ELFW(R_INFO)(esym_شاخص, R_ARM_ABS32);
                    qrel++;
                    أرجع;
                } وإلا {
                    qrel->r_info = ELFW(R_INFO)(0, R_ARM_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            أرجع;
        حالة R_ARM_REL32:
            add32le(ptr, val - addr);
            أرجع;
        حالة R_ARM_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            أرجع;
        حالة R_ARM_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            أرجع;
        حالة R_ARM_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_شاخص, 0)->got_دننه_واټن);
            أرجع;
	حالة R_ARM_GOT_PREL:
            /* we load the pc relative got offset */
            add32le(ptr, s1->got->sh_addr +
			 get_sym_attr(s1, sym_شاخص, 0)->got_دننه_واټن -
			 addr);
            أرجع;
        حالة R_ARM_COPY:
            أرجع;
        حالة R_ARM_V4BX:
            /* trade Thumb support for ARMv4 support */
            إذا ((0x0ffffff0 & read32le(ptr)) == 0x012FFF10)
                write32le(ptr, read32le(ptr) ^ 0xE12FFF10 ^ 0xE1A0F000); /* BX Rm -> MOV PC, Rm */
            أرجع;
        حالة R_ARM_GLOB_DAT:
        حالة R_ARM_JUMP_خونه:
            write32le(ptr, val);
            أرجع;
        حالة R_ARM_NONE:
            /* Nothing to do.  Normally used to indicate a dependency
               on a certain symbol (like for exception handling under EABI).  */
            أرجع;
        حالة R_ARM_RELATIVE:
#که_تعریف_شوی TCC_موخه_PE
            add32le(ptr, val - s1->pe_imagebase);
#د_که_پای
            /* do nothing */
            أرجع;
        حالة R_ARM_TLS_LE32:
            {
                int32_t x;
                إذا (s1->tls_پای_ټکی) {
                    x = val - s1->tls_پیل + 8;
                } وإلا {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->معلومات_دننه_واټن + 8;
                }
                add32le(ptr, x);
            }
            أرجع;
        افتراضي:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (بینښه)addr, ptr, (بینښه)val);
            أرجع;
    }
}

#د_که_پای /* !TARGET_DEFS_ONLY */
