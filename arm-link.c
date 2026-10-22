#جيڪڏهن_وصف_ٿيل هدف_DEFS_ONLY

#وصف_ڪريو EM_TCC_هدف EM_ARM

/* relocation type for 32 bit data relocation */
#وصف_ڪريو R_معلومات_32   R_ARM_ABS32
#وصف_ڪريو R_معلومات_PTR  R_ARM_ABS32
#وصف_ڪريو R_JMP_جڳهه  R_ARM_JUMP_جڳهه
#وصف_ڪريو R_GLOB_DAT  R_ARM_GLOB_DAT
#وصف_ڪريو R_COPY      R_ARM_COPY
#وصف_ڪريو R_RELATIVE  R_ARM_RELATIVE

#وصف_ڪريو R_انگ       R_ARM_انگ

#وصف_ڪريو ELF_شروعات_ADDR 0x00010000
#وصف_ڪريو ELF_صفحو_سائيز  0x10000

#وصف_ڪريو PCRELATIVE_DLLPLT 1
#وصف_ڪريو RELOCATE_DLLPLT 1

#وإلا /* !TARGET_DEFS_ONLY */

#ضمن "tcc.h"

#جيڪڏهن_وصف_ٿيل NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحيح ڪوڊ_reloc (صحيح reloc_type)
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
	حالة R_ARM_JUMP_جڳهه:
            أرجع 1;
    }
    أرجع -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC صحيح gotplt_داخلا_type (صحيح reloc_type)
{
    بدل (reloc_type) {
	حالة R_ARM_NONE:
	حالة R_ARM_COPY:
	حالة R_ARM_GLOB_DAT:
	حالة R_ARM_JUMP_جڳهه:
	حالة R_ARM_TLS_LE32:
            أرجع NO_GOTPLT_داخلا;

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
            أرجع AUTO_GOTPLT_داخلا;

	حالة R_ARM_GOTPC:
	حالة R_ARM_GOTOFF:
            أرجع BUILD_GOT_ONLY;

	حالة R_ARM_GOT32:
	حالة R_ARM_GOT_PREL:
            أرجع ALWAYS_GOTPLT_داخلا;
    }
    أرجع -1;
}

#جيڪڏهن_وصف_ٿيل NEED_BUILD_GOT
ST_FUNC بنانشان create_plt_داخلا(TCCState *s1, بنانشان got_وٿي, بنية sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    بنانشان plt_وٿي;

    /* when building a DLL, GOT entry accesses must be done relative to
       start of GOT (see x86_64 example above)  */

    /* empty PLT: create PLT0 entry that push address of call site and
       jump to ld.so resolution routine (GOT + 8) */
    إذا (plt->معلومات_وٿي == 0) {
        p = section_ptr_جوڙيو(plt, 20);
        write32le(p,    0xe52de004); /* push {lr}         */
        write32le(p+4,  0xe59fe004); /* ldr lr, [pc, #4] */
        write32le(p+8,  0xe08fe00e); /* add lr, pc, lr    */
        write32le(p+12, 0xe5bef008); /* ldr pc, [lr, #8]! */
        /* p+16 is set in relocate_plt */
    }
    plt_وٿي = plt->معلومات_وٿي;

    إذا (attr->plt_thumb_stub) {
        p = section_ptr_جوڙيو(plt, 4);
        write32le(p,   0x4778); /* bx pc */
        write32le(p+2, 0x46c0); /* nop   */
    }
    p = section_ptr_جوڙيو(plt, 16);
    /* save GOT offset for relocate_plt */
    write32le(p + 4, got_وٿي);
    أرجع plt_وٿي;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC فراغ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_پڇاڙي;

    إذا (!s1->plt)
      أرجع;

    p = s1->plt->معلومات;
    p_پڇاڙي = p + s1->plt->معلومات_وٿي;

    إذا (p < p_پڇاڙي) {
        صحيح x = s1->got->sh_addr - s1->plt->sh_addr - 12;
        write32le(s1->plt->معلومات + 16, x - 4);
        p += 20;
        طالما (p < p_پڇاڙي) {
	    بنانشان off = x  + read32le(p + 4) + (s1->plt->معلومات - p) + 4;
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
            write32le(p + rel->r_وٿي, s1->plt->sh_addr);
	}
    }
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, بنانشان حرف *ptr, addr_t addr, addr_t val)
{
    ElfW(Sym) *sym;
    صحيح sym_اشاريو, esym_اشاريو;

    sym_اشاريو = ELFW(R_SYM)(rel->r_info);
    sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_اشاريو];

    بدل(type) {
        حالة R_ARM_PC24:
        حالة R_ARM_CALL:
        حالة R_ARM_JUMP24:
        حالة R_ARM_PLT32:
            {
                صحيح x, is_thumb, is_call, h, blx_avail, is_bl, th_ko;
                بنانشان ڪوڊ = read32le(ptr);
                x = ڪوڊ & 0x00ffffff;
#جيڪڏهن_وصف_ٿيل DEBUG_RELOC
		لکو ("reloc %d: x=0x%x val=0x%x ", type, x, val);
#جيڪڏهن_پورو
                ڪوڊ &= 0xff000000;
                x <<= 2;
                إذا (x & 0x2000000)
                    x -= 0x4000000;
                blx_avail = (CONFIG_TCC_CPUVER >= 5);
                is_thumb = val & 1;
                is_bl = ڪوڊ == 0xeb000000;
                is_call = (type == R_ARM_CALL || (type == R_ARM_PC24 && is_bl));
                x += val - addr;
#جيڪڏهن_وصف_ٿيل DEBUG_RELOC
		لکو (" newx=0x%x name=%s\n", x,
			(حرف *) symtab_section->link->معلومات + sym->st_name);
#جيڪڏهن_پورو
                h = x & 2;
                th_ko = (x & 3) && (!blx_avail || !is_call);
                إذا (th_ko || x >= 0x2000000 || x < -0x2000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                x >>= 2;
                x &= 0xffffff;
                /* Only reached if blx is avail and it is a call */
                إذا (is_thumb) {
                    x |= h << 24;
                    ڪوڊ = 0xfa000000; /* bl -> blx */
                }
                write32le(ptr, ڪوڊ | x);
            }
            أرجع;
        /* Since these relocations only concern Thumb-2 and blx instruction was
           introduced before Thumb-2, we can assume blx is available and not
           guard its use */
        حالة R_ARM_THM_PC22:
        حالة R_ARM_THM_JUMP24:
            {
                صحيح x, hi, lo, s, j1, j2, i1, i2, imm10, imm11;
                صحيح منزل_thumb, is_call, منزل_plt, blx_ٻٽو_انگ = 1 << 12;
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
                         (val < plt->sh_addr + plt->معلومات_وٿي);
                is_call = (type == R_ARM_THM_PC22);

                إذا (!منزل_thumb && !منزل_plt && !is_call) {
                    صحيح اشاريو;
                    uint8_t *p;
                    حرف *name, buf[1024];
                    Section *متن;

                    name = (حرف *) symtab_section->link->معلومات + sym->st_name;
                    متن = s1->sections[sym->st_shndx];
                    /* Modify reloc to target a thumb stub to switch to ARM */
                    snprintf(buf, حجم(buf), "%s_from_thumb", name);
                    اشاريو = put_elf_sym(symtab_section,
                                        متن->معلومات_وٿي + 1,
                                        sym->st_سائيز, sym->st_info, 0,
                                        sym->st_shndx, buf);
                    منزل_thumb = 1;
                    val = متن->معلومات_وٿي + 1;
                    rel->r_info = ELFW(R_INFO)(اشاريو, type);
                    /* Create a thumb stub function to switch to ARM mode */
                    put_elf_reloc(symtab_section, متن,
                                  متن->معلومات_وٿي + 4, R_ARM_JUMP24,
                                  sym_اشاريو);
                    p = section_ptr_جوڙيو(متن, 8);
                    write32le(p,   0x4778); /* bx pc */
                    write32le(p+2, 0x46c0); /* nop   */
                    write32le(p+4, 0xeafffffe); /* b $sym */
                }

                /* Compute final offset */
                x += val - addr;
                إذا (!منزل_thumb && is_call) {
                    blx_ٻٽو_انگ = 0; /* bl -> blx */
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
                                 (j1 << 13) | blx_ٻٽو_انگ | (j2 << 11) |
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
                esym_اشاريو = get_sym_attr(s1, sym_اشاريو, 0)->dyn_اشاريو;
                qrel->r_وٿي = rel->r_وٿي;
                إذا (esym_اشاريو) {
                    qrel->r_info = ELFW(R_INFO)(esym_اشاريو, R_ARM_ABS32);
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
            add32le(ptr, get_sym_attr(s1, sym_اشاريو, 0)->got_وٿي);
            أرجع;
	حالة R_ARM_GOT_PREL:
            /* we load the pc relative got offset */
            add32le(ptr, s1->got->sh_addr +
			 get_sym_attr(s1, sym_اشاريو, 0)->got_وٿي -
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
        حالة R_ARM_JUMP_جڳهه:
            write32le(ptr, val);
            أرجع;
        حالة R_ARM_NONE:
            /* Nothing to do.  Normally used to indicate a dependency
               on a certain symbol (like for exception handling under EABI).  */
            أرجع;
        حالة R_ARM_RELATIVE:
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
            add32le(ptr, val - s1->pe_imagebase);
#جيڪڏهن_پورو
            /* do nothing */
            أرجع;
        حالة R_ARM_TLS_LE32:
            {
                int32_t x;
                إذا (s1->tls_پڇاڙي) {
                    x = val - s1->tls_شروعات + 8;
                } وإلا {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_اشاريو];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->معلومات_وٿي + 8;
                }
                add32le(ptr, x);
            }
            أرجع;
        افتراضي:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (بنانشان)addr, ptr, (بنانشان)val);
            أرجع;
    }
}

#جيڪڏهن_پورو /* !TARGET_DEFS_ONLY */
