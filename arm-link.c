#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ਨਿਸ਼ਾਨਾ_DEFS_ONLY

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_TCC_ਨਿਸ਼ਾਨਾ EM_ARM

/* relocation type for 32 bit data relocation */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕੜੇ_32   R_ARM_ABS32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕੜੇ_PTR  R_ARM_ABS32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_JMP_ਥਾਂ  R_ARM_JUMP_ਥਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_GLOB_DAT  R_ARM_GLOB_DAT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_COPY      R_ARM_COPY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_RELATIVE  R_ARM_RELATIVE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕ       R_ARM_ਅੰਕ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_ਸ਼ੁਰੂ_ADDR 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_ਪੰਨਾ_ਮਾਪ  0x10000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCRELATIVE_DLLPLT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RELOCATE_DLLPLT 1

#ਨਹੀਂਤਾਂ /* !TARGET_DEFS_ONLY */

#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ਪੂਰਨ ਕੋਡ_reloc (ਪੂਰਨ reloc_type)
{
    ਚੋਣ (reloc_type) {
	ਹਾਲਤ R_ARM_MOVT_ABS:
	ਹਾਲਤ R_ARM_MOVW_ABS_NC:
	ਹਾਲਤ R_ARM_THM_MOVT_ABS:
	ਹਾਲਤ R_ARM_THM_MOVW_ABS_NC:
	ਹਾਲਤ R_ARM_ABS32:
	ਹਾਲਤ R_ARM_REL32:
	ਹਾਲਤ R_ARM_GOTPC:
	ਹਾਲਤ R_ARM_GOTOFF:
	ਹਾਲਤ R_ARM_GOT32:
	ਹਾਲਤ R_ARM_GOT_PREL:
	ਹਾਲਤ R_ARM_COPY:
	ਹਾਲਤ R_ARM_GLOB_DAT:
	ਹਾਲਤ R_ARM_NONE:
	ਹਾਲਤ R_ARM_TARGET1:
	ਹਾਲਤ R_ARM_MOVT_PREL:
	ਹਾਲਤ R_ARM_MOVW_PREL_NC:
	ਹਾਲਤ R_ARM_TLS_LE32:
            ਵਾਪਸ 0;

        ਹਾਲਤ R_ARM_PC24:
        ਹਾਲਤ R_ARM_CALL:
	ਹਾਲਤ R_ARM_JUMP24:
	ਹਾਲਤ R_ARM_PLT32:
	ਹਾਲਤ R_ARM_THM_PC22:
	ਹਾਲਤ R_ARM_THM_JUMP24:
	ਹਾਲਤ R_ARM_PREL31:
	ਹਾਲਤ R_ARM_V4BX:
	ਹਾਲਤ R_ARM_JUMP_ਥਾਂ:
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
	ਹਾਲਤ R_ARM_NONE:
	ਹਾਲਤ R_ARM_COPY:
	ਹਾਲਤ R_ARM_GLOB_DAT:
	ਹਾਲਤ R_ARM_JUMP_ਥਾਂ:
	ਹਾਲਤ R_ARM_TLS_LE32:
            ਵਾਪਸ NO_GOTPLT_ਇੰਦਰਾਜ;

        ਹਾਲਤ R_ARM_PC24:
        ਹਾਲਤ R_ARM_CALL:
	ਹਾਲਤ R_ARM_JUMP24:
	ਹਾਲਤ R_ARM_PLT32:
	ਹਾਲਤ R_ARM_THM_PC22:
	ਹਾਲਤ R_ARM_THM_JUMP24:
	ਹਾਲਤ R_ARM_MOVT_ABS:
	ਹਾਲਤ R_ARM_MOVW_ABS_NC:
	ਹਾਲਤ R_ARM_THM_MOVT_ABS:
	ਹਾਲਤ R_ARM_THM_MOVW_ABS_NC:
	ਹਾਲਤ R_ARM_PREL31:
	ਹਾਲਤ R_ARM_ABS32:
	ਹਾਲਤ R_ARM_REL32:
	ਹਾਲਤ R_ARM_V4BX:
	ਹਾਲਤ R_ARM_TARGET1:
	ਹਾਲਤ R_ARM_MOVT_PREL:
	ਹਾਲਤ R_ARM_MOVW_PREL_NC:
            ਵਾਪਸ AUTO_GOTPLT_ਇੰਦਰਾਜ;

	ਹਾਲਤ R_ARM_GOTPC:
	ਹਾਲਤ R_ARM_GOTOFF:
            ਵਾਪਸ BUILD_GOT_ONLY;

	ਹਾਲਤ R_ARM_GOT32:
	ਹਾਲਤ R_ARM_GOT_PREL:
            ਵਾਪਸ ALWAYS_GOTPLT_ਇੰਦਰਾਜ;
    }
    ਵਾਪਸ -1;
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ NEED_BUILD_GOT
ST_FUNC ਬਿਨਾਨਿਸ਼ਾਨੀ create_plt_ਇੰਦਰਾਜ(TCCState *s1, ਬਿਨਾਨਿਸ਼ਾਨੀ got_ਵਿੱਥ, ਬਣਤਰ sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    ਬਿਨਾਨਿਸ਼ਾਨੀ plt_ਵਿੱਥ;

    /* when building a DLL, GOT entry accesses must be done relative to
       start of GOT (see x86_64 example above)  */

    /* empty PLT: create PLT0 entry that push address of call site and
       jump to ld.so resolution routine (GOT + 8) */
    ਜੇ (plt->ਅੰਕੜੇ_ਵਿੱਥ == 0) {
        p = section_ptr_ਜੋੜੋ(plt, 20);
        write32le(p,    0xe52de004); /* push {lr}         */
        write32le(p+4,  0xe59fe004); /* ldr lr, [pc, #4] */
        write32le(p+8,  0xe08fe00e); /* add lr, pc, lr    */
        write32le(p+12, 0xe5bef008); /* ldr pc, [lr, #8]! */
        /* p+16 is set in relocate_plt */
    }
    plt_ਵਿੱਥ = plt->ਅੰਕੜੇ_ਵਿੱਥ;

    ਜੇ (attr->plt_thumb_stub) {
        p = section_ptr_ਜੋੜੋ(plt, 4);
        write32le(p,   0x4778); /* bx pc */
        write32le(p+2, 0x46c0); /* nop   */
    }
    p = section_ptr_ਜੋੜੋ(plt, 16);
    /* save GOT offset for relocate_plt */
    write32le(p + 4, got_ਵਿੱਥ);
    ਵਾਪਸ plt_ਵਿੱਥ;
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
        ਪੂਰਨ x = s1->got->sh_addr - s1->plt->sh_addr - 12;
        write32le(s1->plt->ਅੰਕੜੇ + 16, x - 4);
        p += 20;
        ਜਦੋਂ (p < p_ਸਿਰਾ) {
	    ਬਿਨਾਨਿਸ਼ਾਨੀ off = x  + read32le(p + 4) + (s1->plt->ਅੰਕੜੇ - p) + 4;
            ਜੇ (read32le(p) == 0x46c04778) /* PLT Thumb stub present */
                p += 4;
            write32le(p, 0xe28fc200 | ((off >> 28) & 0xf));      // add ip, pc, #0xN0000000
            write32le(p + 4, 0xe28cc600 | ((off >> 20) & 0xff)); // add ip, pc, #0xNN00000
            write32le(p + 8, 0xe28cca00 | ((off >> 12) & 0xff)); // add ip, ip, #0xNN000
            write32le(p + 12, 0xe5bcf000 | (off & 0xfff));	 // ldr pc, [ip, #0xNNN]!
            p += 16;
        }
    }

    ਜੇ (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->ਅੰਕੜੇ;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_ਵਿੱਥ, s1->plt->sh_addr);
	}
    }
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

ST_FUNC ਖਾਲੀ relocate(TCCState *s1, ElfW_Rel *rel, ਪੂਰਨ type, ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr, addr_t addr, addr_t val)
{
    ElfW(Sym) *sym;
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ, esym_ਸੂਚਕਾਂਕ;

    sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(rel->r_info);
    sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];

    ਚੋਣ(type) {
        ਹਾਲਤ R_ARM_PC24:
        ਹਾਲਤ R_ARM_CALL:
        ਹਾਲਤ R_ARM_JUMP24:
        ਹਾਲਤ R_ARM_PLT32:
            {
                ਪੂਰਨ x, is_thumb, is_call, h, blx_avail, is_bl, th_ko;
                ਬਿਨਾਨਿਸ਼ਾਨੀ ਕੋਡ = read32le(ptr);
                x = ਕੋਡ & 0x00ffffff;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ DEBUG_RELOC
		ਲਿਖੋ ("reloc %d: x=0x%x val=0x%x ", type, x, val);
#ਜੇ_ਅੰਤ
                ਕੋਡ &= 0xff000000;
                x <<= 2;
                ਜੇ (x & 0x2000000)
                    x -= 0x4000000;
                blx_avail = (CONFIG_TCC_CPUVER >= 5);
                is_thumb = val & 1;
                is_bl = ਕੋਡ == 0xeb000000;
                is_call = (type == R_ARM_CALL || (type == R_ARM_PC24 && is_bl));
                x += val - addr;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ DEBUG_RELOC
		ਲਿਖੋ (" newx=0x%x name=%s\n", x,
			(ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name);
#ਜੇ_ਅੰਤ
                h = x & 2;
                th_ko = (x & 3) && (!blx_avail || !is_call);
                ਜੇ (th_ko || x >= 0x2000000 || x < -0x2000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                x >>= 2;
                x &= 0xffffff;
                /* Only reached if blx is avail and it is a call */
                ਜੇ (is_thumb) {
                    x |= h << 24;
                    ਕੋਡ = 0xfa000000; /* bl -> blx */
                }
                write32le(ptr, ਕੋਡ | x);
            }
            ਵਾਪਸ;
        /* Since these relocations only concern Thumb-2 and blx instruction was
           introduced before Thumb-2, we can assume blx is available and not
           guard its use */
        ਹਾਲਤ R_ARM_THM_PC22:
        ਹਾਲਤ R_ARM_THM_JUMP24:
            {
                ਪੂਰਨ x, hi, lo, s, j1, j2, i1, i2, imm10, imm11;
                ਪੂਰਨ ਮੰਜ਼ਿਲ_thumb, is_call, ਮੰਜ਼ਿਲ_plt, blx_ਦੋਆਧਾਰੀ_ਅੰਕ = 1 << 12;
                Section *plt;

                /* weak reference */
                ਜੇ (sym->st_shndx == SHN_UNDEF &&
                    ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
                    ਵਾਪਸ;

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
                ਜੇ (x & 0x01000000)
                    x -= 0x02000000;

                /* Relocation infos */
                ਮੰਜ਼ਿਲ_thumb = val & 1;
                plt = s1->plt;
                ਮੰਜ਼ਿਲ_plt = (val >= plt->sh_addr) &&
                         (val < plt->sh_addr + plt->ਅੰਕੜੇ_ਵਿੱਥ);
                is_call = (type == R_ARM_THM_PC22);

                ਜੇ (!ਮੰਜ਼ਿਲ_thumb && !ਮੰਜ਼ਿਲ_plt && !is_call) {
                    ਪੂਰਨ ਸੂਚਕਾਂਕ;
                    uint8_t *p;
                    ਅੱਖਰ *name, buf[1024];
                    Section *ਪਾਠ;

                    name = (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name;
                    ਪਾਠ = s1->sections[sym->st_shndx];
                    /* Modify reloc to target a thumb stub to switch to ARM */
                    snprintf(buf, ਆਕਾਰ(buf), "%s_from_thumb", name);
                    ਸੂਚਕਾਂਕ = put_elf_sym(symtab_section,
                                        ਪਾਠ->ਅੰਕੜੇ_ਵਿੱਥ + 1,
                                        sym->st_ਮਾਪ, sym->st_info, 0,
                                        sym->st_shndx, buf);
                    ਮੰਜ਼ਿਲ_thumb = 1;
                    val = ਪਾਠ->ਅੰਕੜੇ_ਵਿੱਥ + 1;
                    rel->r_info = ELFW(R_INFO)(ਸੂਚਕਾਂਕ, type);
                    /* Create a thumb stub function to switch to ARM mode */
                    put_elf_reloc(symtab_section, ਪਾਠ,
                                  ਪਾਠ->ਅੰਕੜੇ_ਵਿੱਥ + 4, R_ARM_JUMP24,
                                  sym_ਸੂਚਕਾਂਕ);
                    p = section_ptr_ਜੋੜੋ(ਪਾਠ, 8);
                    write32le(p,   0x4778); /* bx pc */
                    write32le(p+2, 0x46c0); /* nop   */
                    write32le(p+4, 0xeafffffe); /* b $sym */
                }

                /* Compute final offset */
                x += val - addr;
                ਜੇ (!ਮੰਜ਼ਿਲ_thumb && is_call) {
                    blx_ਦੋਆਧਾਰੀ_ਅੰਕ = 0; /* bl -> blx */
                    x = (x + 3) & -4; /* Compute offset from aligned PC */
                }

                /* Check that relocation is possible
                   * offset must not be out of range
                   * if target is to be entered in arm mode:
                     - bit 1 must not set
                     - instruction must be a call (bl) or a jump to PLT */
                ਜੇ (!ਮੰਜ਼ਿਲ_thumb || x >= 0x1000000 || x < -0x1000000)
                    ਜੇ (ਮੰਜ਼ਿਲ_thumb || (val & 2) || (!is_call && !ਮੰਜ਼ਿਲ_plt))
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
                                 (j1 << 13) | blx_ਦੋਆਧਾਰੀ_ਅੰਕ | (j2 << 11) |
                                 imm11);
            }
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_MOVT_ABS:
        ਹਾਲਤ R_ARM_MOVW_ABS_NC:
            {
                ਪੂਰਨ x, imm4, imm12;
                ਜੇ (type == R_ARM_MOVT_ABS)
                    val >>= 16;
                imm12 = val & 0xfff;
                imm4 = (val >> 12) & 0xf;
                x = (imm4 << 16) | imm12;
                ਜੇ (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                ਨਹੀਂਤਾਂ
                    add32le(ptr, x);
            }
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_MOVT_PREL:
        ਹਾਲਤ R_ARM_MOVW_PREL_NC:
            {
		ਪੂਰਨ insn = read32le(ptr);
                ਪੂਰਨ addend = ((insn >> 4) & 0xf000) | (insn & 0xfff);

		addend = (addend ^ 0x8000) - 0x8000;
		val += addend - addr;
		ਜੇ (type == R_ARM_MOVT_PREL)
		    val >>= 16;
		write32le(ptr, (insn & 0xfff0f000) |
			       ((val & 0xf000) << 4) | (val & 0xfff));
            }
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_THM_MOVT_ABS:
        ਹਾਲਤ R_ARM_THM_MOVW_ABS_NC:
            {
                ਪੂਰਨ x, i, imm4, imm3, imm8;
                ਜੇ (type == R_ARM_THM_MOVT_ABS)
                    val >>= 16;
                imm8 = val & 0xff;
                imm3 = (val >> 8) & 0x7;
                i = (val >> 11) & 1;
                imm4 = (val >> 12) & 0xf;
                x = (imm3 << 28) | (imm8 << 16) | (i << 10) | imm4;
                ਜੇ (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                ਨਹੀਂਤਾਂ
                    add32le(ptr, x);
            }
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_PREL31:
            {
                ਪੂਰਨ x;
                x = read32le(ptr) & 0x7fffffff;
                write32le(ptr, read32le(ptr) & 0x80000000);
                x = (x * 2) / 2;
                x += val - addr;
                ਜੇ((x^(x>>1))&0x40000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                write32le(ptr, read32le(ptr) | (x & 0x7fffffff));
            }
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_ABS32:
        ਹਾਲਤ R_ARM_TARGET1:
            ਜੇ (s1->output_type & TCC_OUTPUT_DYN) {
                esym_ਸੂਚਕਾਂਕ = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->dyn_ਸੂਚਕਾਂਕ;
                qrel->r_ਵਿੱਥ = rel->r_ਵਿੱਥ;
                ਜੇ (esym_ਸੂਚਕਾਂਕ) {
                    qrel->r_info = ELFW(R_INFO)(esym_ਸੂਚਕਾਂਕ, R_ARM_ABS32);
                    qrel++;
                    ਵਾਪਸ;
                } ਨਹੀਂਤਾਂ {
                    qrel->r_info = ELFW(R_INFO)(0, R_ARM_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_REL32:
            add32le(ptr, val - addr);
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->got_ਵਿੱਥ);
            ਵਾਪਸ;
	ਹਾਲਤ R_ARM_GOT_PREL:
            /* we load the pc relative got offset */
            add32le(ptr, s1->got->sh_addr +
			 get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->got_ਵਿੱਥ -
			 addr);
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_COPY:
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_V4BX:
            /* trade Thumb support for ARMv4 support */
            ਜੇ ((0x0ffffff0 & read32le(ptr)) == 0x012FFF10)
                write32le(ptr, read32le(ptr) ^ 0xE12FFF10 ^ 0xE1A0F000); /* BX Rm -> MOV PC, Rm */
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_GLOB_DAT:
        ਹਾਲਤ R_ARM_JUMP_ਥਾਂ:
            write32le(ptr, val);
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_NONE:
            /* Nothing to do.  Normally used to indicate a dependency
               on a certain symbol (like for exception handling under EABI).  */
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_RELATIVE:
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
            add32le(ptr, val - s1->pe_imagebase);
#ਜੇ_ਅੰਤ
            /* do nothing */
            ਵਾਪਸ;
        ਹਾਲਤ R_ARM_TLS_LE32:
            {
                int32_t x;
                ਜੇ (s1->tls_ਸਿਰਾ) {
                    x = val - s1->tls_ਸ਼ੁਰੂ + 8;
                } ਨਹੀਂਤਾਂ {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->ਅੰਕੜੇ_ਵਿੱਥ + 8;
                }
                add32le(ptr, x);
            }
            ਵਾਪਸ;
        ਮੂਲ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (ਬਿਨਾਨਿਸ਼ਾਨੀ)addr, ptr, (ਬਿਨਾਨਿਸ਼ਾਨੀ)val);
            ਵਾਪਸ;
    }
}

#ਜੇ_ਅੰਤ /* !TARGET_DEFS_ONLY */
