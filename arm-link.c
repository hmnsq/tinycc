#अगर_घोषित TARGET_DEFS_ONLY

#घोषणा EM_TCC_TARGET EM_ARM

/* relocation type for 32 bit data relocation */
#घोषणा R_तथ्य_32   R_ARM_ABS32
#घोषणा R_तथ्य_PTR  R_ARM_ABS32
#घोषणा R_JMP_SLOT  R_ARM_JUMP_SLOT
#घोषणा R_GLOB_DAT  R_ARM_GLOB_DAT
#घोषणा R_COPY      R_ARM_COPY
#घोषणा R_RELATIVE  R_ARM_RELATIVE

#घोषणा R_अंक       R_ARM_अंक

#घोषणा ELF_START_ADDR 0x00010000
#घोषणा ELF_PAGE_आकार  0x10000

#घोषणा PCRELATIVE_DLLPLT 1
#घोषणा RELOCATE_DLLPLT 1

#अन्यथा /* !TARGET_DEFS_ONLY */

#समावेश "tcc.h"

#अगर_घोषित NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC पूर्णांक code_reloc (पूर्णांक reloc_type)
{
    चयन (reloc_type) {
	हाल R_ARM_MOVT_ABS:
	हाल R_ARM_MOVW_ABS_NC:
	हाल R_ARM_THM_MOVT_ABS:
	हाल R_ARM_THM_MOVW_ABS_NC:
	हाल R_ARM_ABS32:
	हाल R_ARM_REL32:
	हाल R_ARM_GOTPC:
	हाल R_ARM_GOTOFF:
	हाल R_ARM_GOT32:
	हाल R_ARM_GOT_PREL:
	हाल R_ARM_COPY:
	हाल R_ARM_GLOB_DAT:
	हाल R_ARM_NONE:
	हाल R_ARM_TARGET1:
	हाल R_ARM_MOVT_PREL:
	हाल R_ARM_MOVW_PREL_NC:
	हाल R_ARM_TLS_LE32:
            वापस 0;

        हाल R_ARM_PC24:
        हाल R_ARM_CALL:
	हाल R_ARM_JUMP24:
	हाल R_ARM_PLT32:
	हाल R_ARM_THM_PC22:
	हाल R_ARM_THM_JUMP24:
	हाल R_ARM_PREL31:
	हाल R_ARM_V4BX:
	हाल R_ARM_JUMP_SLOT:
            वापस 1;
    }
    वापस -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC पूर्णांक gotplt_entry_type (पूर्णांक reloc_type)
{
    चयन (reloc_type) {
	हाल R_ARM_NONE:
	हाल R_ARM_COPY:
	हाल R_ARM_GLOB_DAT:
	हाल R_ARM_JUMP_SLOT:
	हाल R_ARM_TLS_LE32:
            वापस NO_GOTPLT_ENTRY;

        हाल R_ARM_PC24:
        हाल R_ARM_CALL:
	हाल R_ARM_JUMP24:
	हाल R_ARM_PLT32:
	हाल R_ARM_THM_PC22:
	हाल R_ARM_THM_JUMP24:
	हाल R_ARM_MOVT_ABS:
	हाल R_ARM_MOVW_ABS_NC:
	हाल R_ARM_THM_MOVT_ABS:
	हाल R_ARM_THM_MOVW_ABS_NC:
	हाल R_ARM_PREL31:
	हाल R_ARM_ABS32:
	हाल R_ARM_REL32:
	हाल R_ARM_V4BX:
	हाल R_ARM_TARGET1:
	हाल R_ARM_MOVT_PREL:
	हाल R_ARM_MOVW_PREL_NC:
            वापस AUTO_GOTPLT_ENTRY;

	हाल R_ARM_GOTPC:
	हाल R_ARM_GOTOFF:
            वापस BUILD_GOT_ONLY;

	हाल R_ARM_GOT32:
	हाल R_ARM_GOT_PREL:
            वापस ALWAYS_GOTPLT_ENTRY;
    }
    वापस -1;
}

#अगर_घोषित NEED_BUILD_GOT
ST_FUNC अचिन्हित create_plt_entry(TCCState *s1, अचिन्हित got_offset, काष्ठा sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    अचिन्हित plt_offset;

    /* when building a DLL, GOT entry accesses must be done relative to
       start of GOT (see x86_64 example above)  */

    /* empty PLT: create PLT0 entry that push address of call site and
       jump to ld.so resolution routine (GOT + 8) */
    अगर (plt->तथ्य_offset == 0) {
        p = section_ptr_add(plt, 20);
        write32le(p,    0xe52de004); /* push {lr}         */
        write32le(p+4,  0xe59fe004); /* ldr lr, [pc, #4] */
        write32le(p+8,  0xe08fe00e); /* add lr, pc, lr    */
        write32le(p+12, 0xe5bef008); /* ldr pc, [lr, #8]! */
        /* p+16 is set in relocate_plt */
    }
    plt_offset = plt->तथ्य_offset;

    अगर (attr->plt_thumb_stub) {
        p = section_ptr_add(plt, 4);
        write32le(p,   0x4778); /* bx pc */
        write32le(p+2, 0x46c0); /* nop   */
    }
    p = section_ptr_add(plt, 16);
    /* save GOT offset for relocate_plt */
    write32le(p + 4, got_offset);
    वापस plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC व्योम relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    अगर (!s1->plt)
      वापस;

    p = s1->plt->तथ्य;
    p_end = p + s1->plt->तथ्य_offset;

    अगर (p < p_end) {
        पूर्णांक x = s1->got->sh_addr - s1->plt->sh_addr - 12;
        write32le(s1->plt->तथ्य + 16, x - 4);
        p += 20;
        जबतक (p < p_end) {
	    अचिन्हित off = x  + read32le(p + 4) + (s1->plt->तथ्य - p) + 4;
            अगर (read32le(p) == 0x46c04778) /* PLT Thumb stub present */
                p += 4;
            write32le(p, 0xe28fc200 | ((off >> 28) & 0xf));      // add ip, pc, #0xN0000000
            write32le(p + 4, 0xe28cc600 | ((off >> 20) & 0xff)); // add ip, pc, #0xNN00000
            write32le(p + 8, 0xe28cca00 | ((off >> 12) & 0xff)); // add ip, ip, #0xNN000
            write32le(p + 12, 0xe5bcf000 | (off & 0xfff));	 // ldr pc, [ip, #0xNNN]!
            p += 16;
        }
    }

    अगर (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->तथ्य;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_offset, s1->plt->sh_addr);
	}
    }
}
#पूर्ण_अगर
#पूर्ण_अगर

ST_FUNC व्योम relocate(TCCState *s1, ElfW_Rel *rel, पूर्णांक type, अचिन्हित अक्षर *ptr, addr_t addr, addr_t val)
{
    ElfW(Sym) *sym;
    पूर्णांक sym_सूचकांक, esym_सूचकांक;

    sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
    sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];

    चयन(type) {
        हाल R_ARM_PC24:
        हाल R_ARM_CALL:
        हाल R_ARM_JUMP24:
        हाल R_ARM_PLT32:
            {
                पूर्णांक x, is_thumb, is_call, h, blx_avail, is_bl, th_ko;
                अचिन्हित code = read32le(ptr);
                x = code & 0x00ffffff;
#अगर_घोषित DEBUG_RELOC
		म_लिखो ("reloc %d: x=0x%x val=0x%x ", type, x, val);
#पूर्ण_अगर
                code &= 0xff000000;
                x <<= 2;
                अगर (x & 0x2000000)
                    x -= 0x4000000;
                blx_avail = (CONFIG_TCC_CPUVER >= 5);
                is_thumb = val & 1;
                is_bl = code == 0xeb000000;
                is_call = (type == R_ARM_CALL || (type == R_ARM_PC24 && is_bl));
                x += val - addr;
#अगर_घोषित DEBUG_RELOC
		म_लिखो (" newx=0x%x name=%s\n", x,
			(अक्षर *) symtab_section->link->तथ्य + sym->st_name);
#पूर्ण_अगर
                h = x & 2;
                th_ko = (x & 3) && (!blx_avail || !is_call);
                अगर (th_ko || x >= 0x2000000 || x < -0x2000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                x >>= 2;
                x &= 0xffffff;
                /* Only reached if blx is avail and it is a call */
                अगर (is_thumb) {
                    x |= h << 24;
                    code = 0xfa000000; /* bl -> blx */
                }
                write32le(ptr, code | x);
            }
            वापस;
        /* Since these relocations only concern Thumb-2 and blx instruction was
           introduced before Thumb-2, we can assume blx is available and not
           guard its use */
        हाल R_ARM_THM_PC22:
        हाल R_ARM_THM_JUMP24:
            {
                पूर्णांक x, hi, lo, s, j1, j2, i1, i2, imm10, imm11;
                पूर्णांक to_thumb, is_call, to_plt, blx_bit = 1 << 12;
                Section *plt;

                /* weak reference */
                अगर (sym->st_shndx == SHN_UNDEF &&
                    ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
                    वापस;

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
                अगर (x & 0x01000000)
                    x -= 0x02000000;

                /* Relocation infos */
                to_thumb = val & 1;
                plt = s1->plt;
                to_plt = (val >= plt->sh_addr) &&
                         (val < plt->sh_addr + plt->तथ्य_offset);
                is_call = (type == R_ARM_THM_PC22);

                अगर (!to_thumb && !to_plt && !is_call) {
                    पूर्णांक सूचकांक;
                    uint8_t *p;
                    अक्षर *name, buf[1024];
                    Section *text;

                    name = (अक्षर *) symtab_section->link->तथ्य + sym->st_name;
                    text = s1->sections[sym->st_shndx];
                    /* Modify reloc to target a thumb stub to switch to ARM */
                    snprintf(buf, माप(buf), "%s_from_thumb", name);
                    सूचकांक = put_elf_sym(symtab_section,
                                        text->तथ्य_offset + 1,
                                        sym->st_आकार, sym->st_info, 0,
                                        sym->st_shndx, buf);
                    to_thumb = 1;
                    val = text->तथ्य_offset + 1;
                    rel->r_info = ELFW(R_INFO)(सूचकांक, type);
                    /* Create a thumb stub function to switch to ARM mode */
                    put_elf_reloc(symtab_section, text,
                                  text->तथ्य_offset + 4, R_ARM_JUMP24,
                                  sym_सूचकांक);
                    p = section_ptr_add(text, 8);
                    write32le(p,   0x4778); /* bx pc */
                    write32le(p+2, 0x46c0); /* nop   */
                    write32le(p+4, 0xeafffffe); /* b $sym */
                }

                /* Compute final offset */
                x += val - addr;
                अगर (!to_thumb && is_call) {
                    blx_bit = 0; /* bl -> blx */
                    x = (x + 3) & -4; /* Compute offset from aligned PC */
                }

                /* Check that relocation is possible
                   * offset must not be out of range
                   * if target is to be entered in arm mode:
                     - bit 1 must not set
                     - instruction must be a call (bl) or a jump to PLT */
                अगर (!to_thumb || x >= 0x1000000 || x < -0x1000000)
                    अगर (to_thumb || (val & 2) || (!is_call && !to_plt))
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
                                 (j1 << 13) | blx_bit | (j2 << 11) |
                                 imm11);
            }
            वापस;
        हाल R_ARM_MOVT_ABS:
        हाल R_ARM_MOVW_ABS_NC:
            {
                पूर्णांक x, imm4, imm12;
                अगर (type == R_ARM_MOVT_ABS)
                    val >>= 16;
                imm12 = val & 0xfff;
                imm4 = (val >> 12) & 0xf;
                x = (imm4 << 16) | imm12;
                अगर (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                अन्यथा
                    add32le(ptr, x);
            }
            वापस;
        हाल R_ARM_MOVT_PREL:
        हाल R_ARM_MOVW_PREL_NC:
            {
		पूर्णांक insn = read32le(ptr);
                पूर्णांक addend = ((insn >> 4) & 0xf000) | (insn & 0xfff);

		addend = (addend ^ 0x8000) - 0x8000;
		val += addend - addr;
		अगर (type == R_ARM_MOVT_PREL)
		    val >>= 16;
		write32le(ptr, (insn & 0xfff0f000) |
			       ((val & 0xf000) << 4) | (val & 0xfff));
            }
            वापस;
        हाल R_ARM_THM_MOVT_ABS:
        हाल R_ARM_THM_MOVW_ABS_NC:
            {
                पूर्णांक x, i, imm4, imm3, imm8;
                अगर (type == R_ARM_THM_MOVT_ABS)
                    val >>= 16;
                imm8 = val & 0xff;
                imm3 = (val >> 8) & 0x7;
                i = (val >> 11) & 1;
                imm4 = (val >> 12) & 0xf;
                x = (imm3 << 28) | (imm8 << 16) | (i << 10) | imm4;
                अगर (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                अन्यथा
                    add32le(ptr, x);
            }
            वापस;
        हाल R_ARM_PREL31:
            {
                पूर्णांक x;
                x = read32le(ptr) & 0x7fffffff;
                write32le(ptr, read32le(ptr) & 0x80000000);
                x = (x * 2) / 2;
                x += val - addr;
                अगर((x^(x>>1))&0x40000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                write32le(ptr, read32le(ptr) | (x & 0x7fffffff));
            }
            वापस;
        हाल R_ARM_ABS32:
        हाल R_ARM_TARGET1:
            अगर (s1->output_type & TCC_OUTPUT_DYN) {
                esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
                qrel->r_offset = rel->r_offset;
                अगर (esym_सूचकांक) {
                    qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_ARM_ABS32);
                    qrel++;
                    वापस;
                } अन्यथा {
                    qrel->r_info = ELFW(R_INFO)(0, R_ARM_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            वापस;
        हाल R_ARM_REL32:
            add32le(ptr, val - addr);
            वापस;
        हाल R_ARM_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            वापस;
        हाल R_ARM_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            वापस;
        हाल R_ARM_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_सूचकांक, 0)->got_offset);
            वापस;
	हाल R_ARM_GOT_PREL:
            /* we load the pc relative got offset */
            add32le(ptr, s1->got->sh_addr +
			 get_sym_attr(s1, sym_सूचकांक, 0)->got_offset -
			 addr);
            वापस;
        हाल R_ARM_COPY:
            वापस;
        हाल R_ARM_V4BX:
            /* trade Thumb support for ARMv4 support */
            अगर ((0x0ffffff0 & read32le(ptr)) == 0x012FFF10)
                write32le(ptr, read32le(ptr) ^ 0xE12FFF10 ^ 0xE1A0F000); /* BX Rm -> MOV PC, Rm */
            वापस;
        हाल R_ARM_GLOB_DAT:
        हाल R_ARM_JUMP_SLOT:
            write32le(ptr, val);
            वापस;
        हाल R_ARM_NONE:
            /* Nothing to do.  Normally used to indicate a dependency
               on a certain symbol (like for exception handling under EABI).  */
            वापस;
        हाल R_ARM_RELATIVE:
#अगर_घोषित TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#पूर्ण_अगर
            /* do nothing */
            वापस;
        हाल R_ARM_TLS_LE32:
            {
                int32_t x;
                अगर (s1->tls_end) {
                    x = val - s1->tls_start + 8;
                } अन्यथा {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->तथ्य_offset + 8;
                }
                add32le(ptr, x);
            }
            वापस;
        शेष:
            ख_लिखो(मानक_त्रुटि,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (अचिन्हित)addr, ptr, (अचिन्हित)val);
            वापस;
    }
}

#पूर्ण_अगर /* !TARGET_DEFS_ONLY */
