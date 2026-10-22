#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ಗುರಿ_DEFS_ONLY

#ವ್ಯಾಖ್ಯಾನಿಸು EM_TCC_ಗುರಿ EM_ARM

/* relocation type for 32 bit data relocation */
#ವ್ಯಾಖ್ಯಾನಿಸು R_ದತ್ತಾಂಶ_32   R_ARM_ABS32
#ವ್ಯಾಖ್ಯಾನಿಸು R_ದತ್ತಾಂಶ_PTR  R_ARM_ABS32
#ವ್ಯಾಖ್ಯಾನಿಸು R_JMP_ಸ್ಥಾನ  R_ARM_JUMP_ಸ್ಥಾನ
#ವ್ಯಾಖ್ಯಾನಿಸು R_GLOB_DAT  R_ARM_GLOB_DAT
#ವ್ಯಾಖ್ಯಾನಿಸು R_COPY      R_ARM_COPY
#ವ್ಯಾಖ್ಯಾನಿಸು R_RELATIVE  R_ARM_RELATIVE

#ವ್ಯಾಖ್ಯಾನಿಸು R_ಅಂಕೆ       R_ARM_ಅಂಕೆ

#ವ್ಯಾಖ್ಯಾನಿಸು ELF_ಆರಂಭ_ADDR 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು ELF_ಪುಟ_ಗಾತ್ರ  0x10000

#ವ್ಯಾಖ್ಯಾನಿಸು PCRELATIVE_DLLPLT 1
#ವ್ಯಾಖ್ಯಾನಿಸು RELOCATE_DLLPLT 1

#ಇಲ್ಲದಿದ್ದರೆ /* !TARGET_DEFS_ONLY */

#ಅನ್ತರ್ಭಾವ "tcc.h"

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_reloc (ಪೂರ್ಣಾಂಕ reloc_type)
{
    ಆಯ್ಕೆ (reloc_type) {
	ಸ್ಥಿತಿ R_ARM_MOVT_ABS:
	ಸ್ಥಿತಿ R_ARM_MOVW_ABS_NC:
	ಸ್ಥಿತಿ R_ARM_THM_MOVT_ABS:
	ಸ್ಥಿತಿ R_ARM_THM_MOVW_ABS_NC:
	ಸ್ಥಿತಿ R_ARM_ABS32:
	ಸ್ಥಿತಿ R_ARM_REL32:
	ಸ್ಥಿತಿ R_ARM_GOTPC:
	ಸ್ಥಿತಿ R_ARM_GOTOFF:
	ಸ್ಥಿತಿ R_ARM_GOT32:
	ಸ್ಥಿತಿ R_ARM_GOT_PREL:
	ಸ್ಥಿತಿ R_ARM_COPY:
	ಸ್ಥಿತಿ R_ARM_GLOB_DAT:
	ಸ್ಥಿತಿ R_ARM_NONE:
	ಸ್ಥಿತಿ R_ARM_TARGET1:
	ಸ್ಥಿತಿ R_ARM_MOVT_PREL:
	ಸ್ಥಿತಿ R_ARM_MOVW_PREL_NC:
	ಸ್ಥಿತಿ R_ARM_TLS_LE32:
            ಹಿಂತಿರುಗಿ 0;

        ಸ್ಥಿತಿ R_ARM_PC24:
        ಸ್ಥಿತಿ R_ARM_CALL:
	ಸ್ಥಿತಿ R_ARM_JUMP24:
	ಸ್ಥಿತಿ R_ARM_PLT32:
	ಸ್ಥಿತಿ R_ARM_THM_PC22:
	ಸ್ಥಿತಿ R_ARM_THM_JUMP24:
	ಸ್ಥಿತಿ R_ARM_PREL31:
	ಸ್ಥಿತಿ R_ARM_V4BX:
	ಸ್ಥಿತಿ R_ARM_JUMP_ಸ್ಥಾನ:
            ಹಿಂತಿರುಗಿ 1;
    }
    ಹಿಂತಿರುಗಿ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC ಪೂರ್ಣಾಂಕ gotplt_ನಮೂದು_type (ಪೂರ್ಣಾಂಕ reloc_type)
{
    ಆಯ್ಕೆ (reloc_type) {
	ಸ್ಥಿತಿ R_ARM_NONE:
	ಸ್ಥಿತಿ R_ARM_COPY:
	ಸ್ಥಿತಿ R_ARM_GLOB_DAT:
	ಸ್ಥಿತಿ R_ARM_JUMP_ಸ್ಥಾನ:
	ಸ್ಥಿತಿ R_ARM_TLS_LE32:
            ಹಿಂತಿರುಗಿ NO_GOTPLT_ನಮೂದು;

        ಸ್ಥಿತಿ R_ARM_PC24:
        ಸ್ಥಿತಿ R_ARM_CALL:
	ಸ್ಥಿತಿ R_ARM_JUMP24:
	ಸ್ಥಿತಿ R_ARM_PLT32:
	ಸ್ಥಿತಿ R_ARM_THM_PC22:
	ಸ್ಥಿತಿ R_ARM_THM_JUMP24:
	ಸ್ಥಿತಿ R_ARM_MOVT_ABS:
	ಸ್ಥಿತಿ R_ARM_MOVW_ABS_NC:
	ಸ್ಥಿತಿ R_ARM_THM_MOVT_ABS:
	ಸ್ಥಿತಿ R_ARM_THM_MOVW_ABS_NC:
	ಸ್ಥಿತಿ R_ARM_PREL31:
	ಸ್ಥಿತಿ R_ARM_ABS32:
	ಸ್ಥಿತಿ R_ARM_REL32:
	ಸ್ಥಿತಿ R_ARM_V4BX:
	ಸ್ಥಿತಿ R_ARM_TARGET1:
	ಸ್ಥಿತಿ R_ARM_MOVT_PREL:
	ಸ್ಥಿತಿ R_ARM_MOVW_PREL_NC:
            ಹಿಂತಿರುಗಿ AUTO_GOTPLT_ನಮೂದು;

	ಸ್ಥಿತಿ R_ARM_GOTPC:
	ಸ್ಥಿತಿ R_ARM_GOTOFF:
            ಹಿಂತಿರುಗಿ BUILD_GOT_ONLY;

	ಸ್ಥಿತಿ R_ARM_GOT32:
	ಸ್ಥಿತಿ R_ARM_GOT_PREL:
            ಹಿಂತಿರುಗಿ ALWAYS_GOTPLT_ನಮೂದು;
    }
    ಹಿಂತಿರುಗಿ -1;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ NEED_BUILD_GOT
ST_FUNC ಚಿಹ್ನೆರಹಿತ create_plt_ನಮೂದು(TCCState *s1, ಚಿಹ್ನೆರಹಿತ got_ಸ್ಥಾನಾಂತರ, ರಚನೆ sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    ಚಿಹ್ನೆರಹಿತ plt_ಸ್ಥಾನಾಂತರ;

    /* when building a DLL, GOT entry accesses must be done relative to
       start of GOT (see x86_64 example above)  */

    /* empty PLT: create PLT0 entry that push address of call site and
       jump to ld.so resolution routine (GOT + 8) */
    ಆದರೆ (plt->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ == 0) {
        p = section_ptr_ಕೂಡಿಸು(plt, 20);
        write32le(p,    0xe52de004); /* push {lr}         */
        write32le(p+4,  0xe59fe004); /* ldr lr, [pc, #4] */
        write32le(p+8,  0xe08fe00e); /* add lr, pc, lr    */
        write32le(p+12, 0xe5bef008); /* ldr pc, [lr, #8]! */
        /* p+16 is set in relocate_plt */
    }
    plt_ಸ್ಥಾನಾಂತರ = plt->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

    ಆದರೆ (attr->plt_thumb_stub) {
        p = section_ptr_ಕೂಡಿಸು(plt, 4);
        write32le(p,   0x4778); /* bx pc */
        write32le(p+2, 0x46c0); /* nop   */
    }
    p = section_ptr_ಕೂಡಿಸು(plt, 16);
    /* save GOT offset for relocate_plt */
    write32le(p + 4, got_ಸ್ಥಾನಾಂತರ);
    ಹಿಂತಿರುಗಿ plt_ಸ್ಥಾನಾಂತರ;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC ಶೂನ್ಯ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_ಕೊನೆ;

    ಆದರೆ (!s1->plt)
      ಹಿಂತಿರುಗಿ;

    p = s1->plt->ದತ್ತಾಂಶ;
    p_ಕೊನೆ = p + s1->plt->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

    ಆದರೆ (p < p_ಕೊನೆ) {
        ಪೂರ್ಣಾಂಕ x = s1->got->sh_addr - s1->plt->sh_addr - 12;
        write32le(s1->plt->ದತ್ತಾಂಶ + 16, x - 4);
        p += 20;
        ಆಗ (p < p_ಕೊನೆ) {
	    ಚಿಹ್ನೆರಹಿತ off = x  + read32le(p + 4) + (s1->plt->ದತ್ತಾಂಶ - p) + 4;
            ಆದರೆ (read32le(p) == 0x46c04778) /* PLT Thumb stub present */
                p += 4;
            write32le(p, 0xe28fc200 | ((off >> 28) & 0xf));      // add ip, pc, #0xN0000000
            write32le(p + 4, 0xe28cc600 | ((off >> 20) & 0xff)); // add ip, pc, #0xNN00000
            write32le(p + 8, 0xe28cca00 | ((off >> 12) & 0xff)); // add ip, ip, #0xNN000
            write32le(p + 12, 0xe5bcf000 | (off & 0xfff));	 // ldr pc, [ip, #0xNNN]!
            p += 16;
        }
    }

    ಆದರೆ (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->ದತ್ತಾಂಶ;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_ಸ್ಥಾನಾಂತರ, s1->plt->sh_addr);
	}
    }
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

ST_FUNC ಶೂನ್ಯ relocate(TCCState *s1, ElfW_Rel *rel, ಪೂರ್ಣಾಂಕ type, ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr, addr_t addr, addr_t val)
{
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ, esym_ಸೂಚ್ಯಂಕ;

    sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(rel->r_info);
    sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];

    ಆಯ್ಕೆ(type) {
        ಸ್ಥಿತಿ R_ARM_PC24:
        ಸ್ಥಿತಿ R_ARM_CALL:
        ಸ್ಥಿತಿ R_ARM_JUMP24:
        ಸ್ಥಿತಿ R_ARM_PLT32:
            {
                ಪೂರ್ಣಾಂಕ x, is_thumb, is_call, h, blx_avail, is_bl, th_ko;
                ಚಿಹ್ನೆರಹಿತ ಸಂಕೇತ_2 = read32le(ptr);
                x = ಸಂಕೇತ_2 & 0x00ffffff;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ DEBUG_RELOC
		ಬರೆ ("reloc %d: x=0x%x val=0x%x ", type, x, val);
#ಆದರೆ_ಅಂತ್ಯ
                ಸಂಕೇತ_2 &= 0xff000000;
                x <<= 2;
                ಆದರೆ (x & 0x2000000)
                    x -= 0x4000000;
                blx_avail = (CONFIG_TCC_CPUVER >= 5);
                is_thumb = val & 1;
                is_bl = ಸಂಕೇತ_2 == 0xeb000000;
                is_call = (type == R_ARM_CALL || (type == R_ARM_PC24 && is_bl));
                x += val - addr;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ DEBUG_RELOC
		ಬರೆ (" newx=0x%x name=%s\n", x,
			(ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name);
#ಆದರೆ_ಅಂತ್ಯ
                h = x & 2;
                th_ko = (x & 3) && (!blx_avail || !is_call);
                ಆದರೆ (th_ko || x >= 0x2000000 || x < -0x2000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                x >>= 2;
                x &= 0xffffff;
                /* Only reached if blx is avail and it is a call */
                ಆದರೆ (is_thumb) {
                    x |= h << 24;
                    ಸಂಕೇತ_2 = 0xfa000000; /* bl -> blx */
                }
                write32le(ptr, ಸಂಕೇತ_2 | x);
            }
            ಹಿಂತಿರುಗಿ;
        /* Since these relocations only concern Thumb-2 and blx instruction was
           introduced before Thumb-2, we can assume blx is available and not
           guard its use */
        ಸ್ಥಿತಿ R_ARM_THM_PC22:
        ಸ್ಥಿತಿ R_ARM_THM_JUMP24:
            {
                ಪೂರ್ಣಾಂಕ x, hi, lo, s, j1, j2, i1, i2, imm10, imm11;
                ಪೂರ್ಣಾಂಕ ಗಮ್ಯ_thumb, is_call, ಗಮ್ಯ_plt, blx_ಬಿಟ್ = 1 << 12;
                Section *plt;

                /* weak reference */
                ಆದರೆ (sym->st_shndx == SHN_UNDEF &&
                    ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
                    ಹಿಂತಿರುಗಿ;

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
                ಆದರೆ (x & 0x01000000)
                    x -= 0x02000000;

                /* Relocation infos */
                ಗಮ್ಯ_thumb = val & 1;
                plt = s1->plt;
                ಗಮ್ಯ_plt = (val >= plt->sh_addr) &&
                         (val < plt->sh_addr + plt->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
                is_call = (type == R_ARM_THM_PC22);

                ಆದರೆ (!ಗಮ್ಯ_thumb && !ಗಮ್ಯ_plt && !is_call) {
                    ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ;
                    uint8_t *p;
                    ಅಕ್ಷರ *name, buf[1024];
                    Section *ಪಠ್ಯ;

                    name = (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
                    ಪಠ್ಯ = s1->sections[sym->st_shndx];
                    /* Modify reloc to target a thumb stub to switch to ARM */
                    snprintf(buf, ಗಾತ್ರ(buf), "%s_from_thumb", name);
                    ಸೂಚ್ಯಂಕ = put_elf_sym(symtab_section,
                                        ಪಠ್ಯ->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ + 1,
                                        sym->st_ಗಾತ್ರ, sym->st_info, 0,
                                        sym->st_shndx, buf);
                    ಗಮ್ಯ_thumb = 1;
                    val = ಪಠ್ಯ->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ + 1;
                    rel->r_info = ELFW(R_INFO)(ಸೂಚ್ಯಂಕ, type);
                    /* Create a thumb stub function to switch to ARM mode */
                    put_elf_reloc(symtab_section, ಪಠ್ಯ,
                                  ಪಠ್ಯ->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ + 4, R_ARM_JUMP24,
                                  sym_ಸೂಚ್ಯಂಕ);
                    p = section_ptr_ಕೂಡಿಸು(ಪಠ್ಯ, 8);
                    write32le(p,   0x4778); /* bx pc */
                    write32le(p+2, 0x46c0); /* nop   */
                    write32le(p+4, 0xeafffffe); /* b $sym */
                }

                /* Compute final offset */
                x += val - addr;
                ಆದರೆ (!ಗಮ್ಯ_thumb && is_call) {
                    blx_ಬಿಟ್ = 0; /* bl -> blx */
                    x = (x + 3) & -4; /* Compute offset from aligned PC */
                }

                /* Check that relocation is possible
                   * offset must not be out of range
                   * if target is to be entered in arm mode:
                     - bit 1 must not set
                     - instruction must be a call (bl) or a jump to PLT */
                ಆದರೆ (!ಗಮ್ಯ_thumb || x >= 0x1000000 || x < -0x1000000)
                    ಆದರೆ (ಗಮ್ಯ_thumb || (val & 2) || (!is_call && !ಗಮ್ಯ_plt))
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
                                 (j1 << 13) | blx_ಬಿಟ್ | (j2 << 11) |
                                 imm11);
            }
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_MOVT_ABS:
        ಸ್ಥಿತಿ R_ARM_MOVW_ABS_NC:
            {
                ಪೂರ್ಣಾಂಕ x, imm4, imm12;
                ಆದರೆ (type == R_ARM_MOVT_ABS)
                    val >>= 16;
                imm12 = val & 0xfff;
                imm4 = (val >> 12) & 0xf;
                x = (imm4 << 16) | imm12;
                ಆದರೆ (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                ಇಲ್ಲದಿದ್ದರೆ
                    add32le(ptr, x);
            }
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_MOVT_PREL:
        ಸ್ಥಿತಿ R_ARM_MOVW_PREL_NC:
            {
		ಪೂರ್ಣಾಂಕ insn = read32le(ptr);
                ಪೂರ್ಣಾಂಕ addend = ((insn >> 4) & 0xf000) | (insn & 0xfff);

		addend = (addend ^ 0x8000) - 0x8000;
		val += addend - addr;
		ಆದರೆ (type == R_ARM_MOVT_PREL)
		    val >>= 16;
		write32le(ptr, (insn & 0xfff0f000) |
			       ((val & 0xf000) << 4) | (val & 0xfff));
            }
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_THM_MOVT_ABS:
        ಸ್ಥಿತಿ R_ARM_THM_MOVW_ABS_NC:
            {
                ಪೂರ್ಣಾಂಕ x, i, imm4, imm3, imm8;
                ಆದರೆ (type == R_ARM_THM_MOVT_ABS)
                    val >>= 16;
                imm8 = val & 0xff;
                imm3 = (val >> 8) & 0x7;
                i = (val >> 11) & 1;
                imm4 = (val >> 12) & 0xf;
                x = (imm3 << 28) | (imm8 << 16) | (i << 10) | imm4;
                ಆದರೆ (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                ಇಲ್ಲದಿದ್ದರೆ
                    add32le(ptr, x);
            }
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_PREL31:
            {
                ಪೂರ್ಣಾಂಕ x;
                x = read32le(ptr) & 0x7fffffff;
                write32le(ptr, read32le(ptr) & 0x80000000);
                x = (x * 2) / 2;
                x += val - addr;
                ಆದರೆ((x^(x>>1))&0x40000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                write32le(ptr, read32le(ptr) | (x & 0x7fffffff));
            }
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_ABS32:
        ಸ್ಥಿತಿ R_ARM_TARGET1:
            ಆದರೆ (s1->output_type & TCC_OUTPUT_DYN) {
                esym_ಸೂಚ್ಯಂಕ = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->dyn_ಸೂಚ್ಯಂಕ;
                qrel->r_ಸ್ಥಾನಾಂತರ = rel->r_ಸ್ಥಾನಾಂತರ;
                ಆದರೆ (esym_ಸೂಚ್ಯಂಕ) {
                    qrel->r_info = ELFW(R_INFO)(esym_ಸೂಚ್ಯಂಕ, R_ARM_ABS32);
                    qrel++;
                    ಹಿಂತಿರುಗಿ;
                } ಇಲ್ಲದಿದ್ದರೆ {
                    qrel->r_info = ELFW(R_INFO)(0, R_ARM_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_REL32:
            add32le(ptr, val - addr);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->got_ಸ್ಥಾನಾಂತರ);
            ಹಿಂತಿರುಗಿ;
	ಸ್ಥಿತಿ R_ARM_GOT_PREL:
            /* we load the pc relative got offset */
            add32le(ptr, s1->got->sh_addr +
			 get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 0)->got_ಸ್ಥಾನಾಂತರ -
			 addr);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_COPY:
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_V4BX:
            /* trade Thumb support for ARMv4 support */
            ಆದರೆ ((0x0ffffff0 & read32le(ptr)) == 0x012FFF10)
                write32le(ptr, read32le(ptr) ^ 0xE12FFF10 ^ 0xE1A0F000); /* BX Rm -> MOV PC, Rm */
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_GLOB_DAT:
        ಸ್ಥಿತಿ R_ARM_JUMP_ಸ್ಥಾನ:
            write32le(ptr, val);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_NONE:
            /* Nothing to do.  Normally used to indicate a dependency
               on a certain symbol (like for exception handling under EABI).  */
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_RELATIVE:
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
            add32le(ptr, val - s1->pe_imagebase);
#ಆದರೆ_ಅಂತ್ಯ
            /* do nothing */
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ R_ARM_TLS_LE32:
            {
                int32_t x;
                ಆದರೆ (s1->tls_ಕೊನೆ) {
                    x = val - s1->tls_ಆರಂಭ + 8;
                } ಇಲ್ಲದಿದ್ದರೆ {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ + 8;
                }
                add32le(ptr, x);
            }
            ಹಿಂತಿರುಗಿ;
        ಪೂರ್ವನಿಯೋಜಿತ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (ಚಿಹ್ನೆರಹಿತ)addr, ptr, (ಚಿಹ್ನೆರಹಿತ)val);
            ಹಿಂತಿರುಗಿ;
    }
}

#ಆದರೆ_ಅಂತ್ಯ /* !TARGET_DEFS_ONLY */
