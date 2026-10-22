#اگر_تعریف_شدہ ہدف_DEFS_ONLY

#تعریف_کرو EM_TCC_ہدف EM_ARM

/* relocation type for 32 bit data relocation */
#تعریف_کرو R_ڈیٹا_32   R_ARM_ABS32
#تعریف_کرو R_ڈیٹا_PTR  R_ARM_ABS32
#تعریف_کرو R_JMP_خانہ  R_ARM_JUMP_خانہ
#تعریف_کرو R_GLOB_DAT  R_ARM_GLOB_DAT
#تعریف_کرو R_COPY      R_ARM_COPY
#تعریف_کرو R_RELATIVE  R_ARM_RELATIVE

#تعریف_کرو R_عدد       R_ARM_عدد

#تعریف_کرو ELF_آغاز_ADDR 0x00010000
#تعریف_کرو ELF_صفحہ_سائز  0x10000

#تعریف_کرو PCRELATIVE_DLLPLT 1
#تعریف_کرو RELOCATE_DLLPLT 1

#ورنہ /* !TARGET_DEFS_ONLY */

#شامل "tcc.h"

#اگر_تعریف_شدہ NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحیح رمز_reloc (صحیح reloc_type)
{
    انتخاب (reloc_type) {
	حالت R_ARM_MOVT_ABS:
	حالت R_ARM_MOVW_ABS_NC:
	حالت R_ARM_THM_MOVT_ABS:
	حالت R_ARM_THM_MOVW_ABS_NC:
	حالت R_ARM_ABS32:
	حالت R_ARM_REL32:
	حالت R_ARM_GOTPC:
	حالت R_ARM_GOTOFF:
	حالت R_ARM_GOT32:
	حالت R_ARM_GOT_PREL:
	حالت R_ARM_COPY:
	حالت R_ARM_GLOB_DAT:
	حالت R_ARM_NONE:
	حالت R_ARM_TARGET1:
	حالت R_ARM_MOVT_PREL:
	حالت R_ARM_MOVW_PREL_NC:
	حالت R_ARM_TLS_LE32:
            واپس 0;

        حالت R_ARM_PC24:
        حالت R_ARM_CALL:
	حالت R_ARM_JUMP24:
	حالت R_ARM_PLT32:
	حالت R_ARM_THM_PC22:
	حالت R_ARM_THM_JUMP24:
	حالت R_ARM_PREL31:
	حالت R_ARM_V4BX:
	حالت R_ARM_JUMP_خانہ:
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
	حالت R_ARM_NONE:
	حالت R_ARM_COPY:
	حالت R_ARM_GLOB_DAT:
	حالت R_ARM_JUMP_خانہ:
	حالت R_ARM_TLS_LE32:
            واپس NO_GOTPLT_اندراج;

        حالت R_ARM_PC24:
        حالت R_ARM_CALL:
	حالت R_ARM_JUMP24:
	حالت R_ARM_PLT32:
	حالت R_ARM_THM_PC22:
	حالت R_ARM_THM_JUMP24:
	حالت R_ARM_MOVT_ABS:
	حالت R_ARM_MOVW_ABS_NC:
	حالت R_ARM_THM_MOVT_ABS:
	حالت R_ARM_THM_MOVW_ABS_NC:
	حالت R_ARM_PREL31:
	حالت R_ARM_ABS32:
	حالت R_ARM_REL32:
	حالت R_ARM_V4BX:
	حالت R_ARM_TARGET1:
	حالت R_ARM_MOVT_PREL:
	حالت R_ARM_MOVW_PREL_NC:
            واپس AUTO_GOTPLT_اندراج;

	حالت R_ARM_GOTPC:
	حالت R_ARM_GOTOFF:
            واپس BUILD_GOT_ONLY;

	حالت R_ARM_GOT32:
	حالت R_ARM_GOT_PREL:
            واپس ALWAYS_GOTPLT_اندراج;
    }
    واپس -1;
}

#اگر_تعریف_شدہ NEED_BUILD_GOT
ST_FUNC غیرعلامتی create_plt_اندراج(TCCState *s1, غیرعلامتی got_انحراف, ساخت sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    غیرعلامتی plt_انحراف;

    /* when building a DLL, GOT entry accesses must be done relative to
       start of GOT (see x86_64 example above)  */

    /* empty PLT: create PLT0 entry that push address of call site and
       jump to ld.so resolution routine (GOT + 8) */
    اگر (plt->ڈیٹا_انحراف == 0) {
        p = section_ptr_جوڑو(plt, 20);
        write32le(p,    0xe52de004); /* push {lr}         */
        write32le(p+4,  0xe59fe004); /* ldr lr, [pc, #4] */
        write32le(p+8,  0xe08fe00e); /* add lr, pc, lr    */
        write32le(p+12, 0xe5bef008); /* ldr pc, [lr, #8]! */
        /* p+16 is set in relocate_plt */
    }
    plt_انحراف = plt->ڈیٹا_انحراف;

    اگر (attr->plt_thumb_stub) {
        p = section_ptr_جوڑو(plt, 4);
        write32le(p,   0x4778); /* bx pc */
        write32le(p+2, 0x46c0); /* nop   */
    }
    p = section_ptr_جوڑو(plt, 16);
    /* save GOT offset for relocate_plt */
    write32le(p + 4, got_انحراف);
    واپس plt_انحراف;
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
        صحیح x = s1->got->sh_addr - s1->plt->sh_addr - 12;
        write32le(s1->plt->ڈیٹا + 16, x - 4);
        p += 20;
        جب (p < p_انتہا) {
	    غیرعلامتی off = x  + read32le(p + 4) + (s1->plt->ڈیٹا - p) + 4;
            اگر (read32le(p) == 0x46c04778) /* PLT Thumb stub present */
                p += 4;
            write32le(p, 0xe28fc200 | ((off >> 28) & 0xf));      // add ip, pc, #0xN0000000
            write32le(p + 4, 0xe28cc600 | ((off >> 20) & 0xff)); // add ip, pc, #0xNN00000
            write32le(p + 8, 0xe28cca00 | ((off >> 12) & 0xff)); // add ip, ip, #0xNN000
            write32le(p + 12, 0xe5bcf000 | (off & 0xfff));	 // ldr pc, [ip, #0xNNN]!
            p += 16;
        }
    }

    اگر (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->ڈیٹا;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_انحراف, s1->plt->sh_addr);
	}
    }
}
#اگر_ختم
#اگر_ختم

ST_FUNC خالی relocate(TCCState *s1, ElfW_Rel *rel, صحیح type, غیرعلامتی حرف *ptr, addr_t addr, addr_t val)
{
    ElfW(Sym) *sym;
    صحیح sym_اشاریہ, esym_اشاریہ;

    sym_اشاریہ = ELFW(R_SYM)(rel->r_info);
    sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];

    انتخاب(type) {
        حالت R_ARM_PC24:
        حالت R_ARM_CALL:
        حالت R_ARM_JUMP24:
        حالت R_ARM_PLT32:
            {
                صحیح x, is_thumb, is_call, h, blx_avail, is_bl, th_ko;
                غیرعلامتی رمز = read32le(ptr);
                x = رمز & 0x00ffffff;
#اگر_تعریف_شدہ DEBUG_RELOC
		لکھو ("reloc %d: x=0x%x val=0x%x ", type, x, val);
#اگر_ختم
                رمز &= 0xff000000;
                x <<= 2;
                اگر (x & 0x2000000)
                    x -= 0x4000000;
                blx_avail = (CONFIG_TCC_CPUVER >= 5);
                is_thumb = val & 1;
                is_bl = رمز == 0xeb000000;
                is_call = (type == R_ARM_CALL || (type == R_ARM_PC24 && is_bl));
                x += val - addr;
#اگر_تعریف_شدہ DEBUG_RELOC
		لکھو (" newx=0x%x name=%s\n", x,
			(حرف *) symtab_section->link->ڈیٹا + sym->st_name);
#اگر_ختم
                h = x & 2;
                th_ko = (x & 3) && (!blx_avail || !is_call);
                اگر (th_ko || x >= 0x2000000 || x < -0x2000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                x >>= 2;
                x &= 0xffffff;
                /* Only reached if blx is avail and it is a call */
                اگر (is_thumb) {
                    x |= h << 24;
                    رمز = 0xfa000000; /* bl -> blx */
                }
                write32le(ptr, رمز | x);
            }
            واپس;
        /* Since these relocations only concern Thumb-2 and blx instruction was
           introduced before Thumb-2, we can assume blx is available and not
           guard its use */
        حالت R_ARM_THM_PC22:
        حالت R_ARM_THM_JUMP24:
            {
                صحیح x, hi, lo, s, j1, j2, i1, i2, imm10, imm11;
                صحیح مقصد_thumb, is_call, مقصد_plt, blx_ثنائی_ہندسہ = 1 << 12;
                Section *plt;

                /* weak reference */
                اگر (sym->st_shndx == SHN_UNDEF &&
                    ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
                    واپس;

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
                اگر (x & 0x01000000)
                    x -= 0x02000000;

                /* Relocation infos */
                مقصد_thumb = val & 1;
                plt = s1->plt;
                مقصد_plt = (val >= plt->sh_addr) &&
                         (val < plt->sh_addr + plt->ڈیٹا_انحراف);
                is_call = (type == R_ARM_THM_PC22);

                اگر (!مقصد_thumb && !مقصد_plt && !is_call) {
                    صحیح اشاریہ;
                    uint8_t *p;
                    حرف *name, buf[1024];
                    Section *متن;

                    name = (حرف *) symtab_section->link->ڈیٹا + sym->st_name;
                    متن = s1->sections[sym->st_shndx];
                    /* Modify reloc to target a thumb stub to switch to ARM */
                    snprintf(buf, حجم(buf), "%s_from_thumb", name);
                    اشاریہ = put_elf_sym(symtab_section,
                                        متن->ڈیٹا_انحراف + 1,
                                        sym->st_سائز, sym->st_info, 0,
                                        sym->st_shndx, buf);
                    مقصد_thumb = 1;
                    val = متن->ڈیٹا_انحراف + 1;
                    rel->r_info = ELFW(R_INFO)(اشاریہ, type);
                    /* Create a thumb stub function to switch to ARM mode */
                    put_elf_reloc(symtab_section, متن,
                                  متن->ڈیٹا_انحراف + 4, R_ARM_JUMP24,
                                  sym_اشاریہ);
                    p = section_ptr_جوڑو(متن, 8);
                    write32le(p,   0x4778); /* bx pc */
                    write32le(p+2, 0x46c0); /* nop   */
                    write32le(p+4, 0xeafffffe); /* b $sym */
                }

                /* Compute final offset */
                x += val - addr;
                اگر (!مقصد_thumb && is_call) {
                    blx_ثنائی_ہندسہ = 0; /* bl -> blx */
                    x = (x + 3) & -4; /* Compute offset from aligned PC */
                }

                /* Check that relocation is possible
                   * offset must not be out of range
                   * if target is to be entered in arm mode:
                     - bit 1 must not set
                     - instruction must be a call (bl) or a jump to PLT */
                اگر (!مقصد_thumb || x >= 0x1000000 || x < -0x1000000)
                    اگر (مقصد_thumb || (val & 2) || (!is_call && !مقصد_plt))
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
                                 (j1 << 13) | blx_ثنائی_ہندسہ | (j2 << 11) |
                                 imm11);
            }
            واپس;
        حالت R_ARM_MOVT_ABS:
        حالت R_ARM_MOVW_ABS_NC:
            {
                صحیح x, imm4, imm12;
                اگر (type == R_ARM_MOVT_ABS)
                    val >>= 16;
                imm12 = val & 0xfff;
                imm4 = (val >> 12) & 0xf;
                x = (imm4 << 16) | imm12;
                اگر (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                ورنہ
                    add32le(ptr, x);
            }
            واپس;
        حالت R_ARM_MOVT_PREL:
        حالت R_ARM_MOVW_PREL_NC:
            {
		صحیح insn = read32le(ptr);
                صحیح addend = ((insn >> 4) & 0xf000) | (insn & 0xfff);

		addend = (addend ^ 0x8000) - 0x8000;
		val += addend - addr;
		اگر (type == R_ARM_MOVT_PREL)
		    val >>= 16;
		write32le(ptr, (insn & 0xfff0f000) |
			       ((val & 0xf000) << 4) | (val & 0xfff));
            }
            واپس;
        حالت R_ARM_THM_MOVT_ABS:
        حالت R_ARM_THM_MOVW_ABS_NC:
            {
                صحیح x, i, imm4, imm3, imm8;
                اگر (type == R_ARM_THM_MOVT_ABS)
                    val >>= 16;
                imm8 = val & 0xff;
                imm3 = (val >> 8) & 0x7;
                i = (val >> 11) & 1;
                imm4 = (val >> 12) & 0xf;
                x = (imm3 << 28) | (imm8 << 16) | (i << 10) | imm4;
                اگر (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                ورنہ
                    add32le(ptr, x);
            }
            واپس;
        حالت R_ARM_PREL31:
            {
                صحیح x;
                x = read32le(ptr) & 0x7fffffff;
                write32le(ptr, read32le(ptr) & 0x80000000);
                x = (x * 2) / 2;
                x += val - addr;
                اگر((x^(x>>1))&0x40000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                write32le(ptr, read32le(ptr) | (x & 0x7fffffff));
            }
            واپس;
        حالت R_ARM_ABS32:
        حالت R_ARM_TARGET1:
            اگر (s1->output_type & TCC_OUTPUT_DYN) {
                esym_اشاریہ = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
                qrel->r_انحراف = rel->r_انحراف;
                اگر (esym_اشاریہ) {
                    qrel->r_info = ELFW(R_INFO)(esym_اشاریہ, R_ARM_ABS32);
                    qrel++;
                    واپس;
                } ورنہ {
                    qrel->r_info = ELFW(R_INFO)(0, R_ARM_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            واپس;
        حالت R_ARM_REL32:
            add32le(ptr, val - addr);
            واپس;
        حالت R_ARM_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            واپس;
        حالت R_ARM_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            واپس;
        حالت R_ARM_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_اشاریہ, 0)->got_انحراف);
            واپس;
	حالت R_ARM_GOT_PREL:
            /* we load the pc relative got offset */
            add32le(ptr, s1->got->sh_addr +
			 get_sym_attr(s1, sym_اشاریہ, 0)->got_انحراف -
			 addr);
            واپس;
        حالت R_ARM_COPY:
            واپس;
        حالت R_ARM_V4BX:
            /* trade Thumb support for ARMv4 support */
            اگر ((0x0ffffff0 & read32le(ptr)) == 0x012FFF10)
                write32le(ptr, read32le(ptr) ^ 0xE12FFF10 ^ 0xE1A0F000); /* BX Rm -> MOV PC, Rm */
            واپس;
        حالت R_ARM_GLOB_DAT:
        حالت R_ARM_JUMP_خانہ:
            write32le(ptr, val);
            واپس;
        حالت R_ARM_NONE:
            /* Nothing to do.  Normally used to indicate a dependency
               on a certain symbol (like for exception handling under EABI).  */
            واپس;
        حالت R_ARM_RELATIVE:
#اگر_تعریف_شدہ TCC_ہدف_PE
            add32le(ptr, val - s1->pe_imagebase);
#اگر_ختم
            /* do nothing */
            واپس;
        حالت R_ARM_TLS_LE32:
            {
                int32_t x;
                اگر (s1->tls_انتہا) {
                    x = val - s1->tls_آغاز + 8;
                } ورنہ {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->ڈیٹا_انحراف + 8;
                }
                add32le(ptr, x);
            }
            واپس;
        طےشدہ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (غیرعلامتی)addr, ptr, (غیرعلامتی)val);
            واپس;
    }
}

#اگر_ختم /* !TARGET_DEFS_ONLY */
