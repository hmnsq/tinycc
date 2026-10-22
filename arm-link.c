#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_ARM

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_ARM_ABS32
#define R_DATA_PTR  R_ARM_ABS32
#define R_JMP_SLOT  R_ARM_JUMP_SLOT
#define R_GLOB_DAT  R_ARM_GLOB_DAT
#define R_COPY      R_ARM_COPY
#define R_RELATIVE  R_ARM_RELATIVE

#define R_अंक       R_ARM_अंक

#define ELF_START_ADDR 0x00010000
#define ELF_PAGE_SIZE  0x10000

#define PCRELATIVE_DLLPLT 1
#define RELOCATE_DLLPLT 1

#अन्यथा /* !TARGET_DEFS_ONLY */

#अन्तर्भाव "tcc.h"

#ifdef NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC पूर्णांक code_reloc (पूर्णांक reloc_type)
{
    निवड (reloc_type) {
	स्थिती R_ARM_MOVT_ABS:
	स्थिती R_ARM_MOVW_ABS_NC:
	स्थिती R_ARM_THM_MOVT_ABS:
	स्थिती R_ARM_THM_MOVW_ABS_NC:
	स्थिती R_ARM_ABS32:
	स्थिती R_ARM_REL32:
	स्थिती R_ARM_GOTPC:
	स्थिती R_ARM_GOTOFF:
	स्थिती R_ARM_GOT32:
	स्थिती R_ARM_GOT_PREL:
	स्थिती R_ARM_COPY:
	स्थिती R_ARM_GLOB_DAT:
	स्थिती R_ARM_NONE:
	स्थिती R_ARM_TARGET1:
	स्थिती R_ARM_MOVT_PREL:
	स्थिती R_ARM_MOVW_PREL_NC:
	स्थिती R_ARM_TLS_LE32:
            परत 0;

        स्थिती R_ARM_PC24:
        स्थिती R_ARM_CALL:
	स्थिती R_ARM_JUMP24:
	स्थिती R_ARM_PLT32:
	स्थिती R_ARM_THM_PC22:
	स्थिती R_ARM_THM_JUMP24:
	स्थिती R_ARM_PREL31:
	स्थिती R_ARM_V4BX:
	स्थिती R_ARM_JUMP_SLOT:
            परत 1;
    }
    परत -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC पूर्णांक gotplt_entry_type (पूर्णांक reloc_type)
{
    निवड (reloc_type) {
	स्थिती R_ARM_NONE:
	स्थिती R_ARM_COPY:
	स्थिती R_ARM_GLOB_DAT:
	स्थिती R_ARM_JUMP_SLOT:
	स्थिती R_ARM_TLS_LE32:
            परत NO_GOTPLT_ENTRY;

        स्थिती R_ARM_PC24:
        स्थिती R_ARM_CALL:
	स्थिती R_ARM_JUMP24:
	स्थिती R_ARM_PLT32:
	स्थिती R_ARM_THM_PC22:
	स्थिती R_ARM_THM_JUMP24:
	स्थिती R_ARM_MOVT_ABS:
	स्थिती R_ARM_MOVW_ABS_NC:
	स्थिती R_ARM_THM_MOVT_ABS:
	स्थिती R_ARM_THM_MOVW_ABS_NC:
	स्थिती R_ARM_PREL31:
	स्थिती R_ARM_ABS32:
	स्थिती R_ARM_REL32:
	स्थिती R_ARM_V4BX:
	स्थिती R_ARM_TARGET1:
	स्थिती R_ARM_MOVT_PREL:
	स्थिती R_ARM_MOVW_PREL_NC:
            परत AUTO_GOTPLT_ENTRY;

	स्थिती R_ARM_GOTPC:
	स्थिती R_ARM_GOTOFF:
            परत BUILD_GOT_ONLY;

	स्थिती R_ARM_GOT32:
	स्थिती R_ARM_GOT_PREL:
            परत ALWAYS_GOTPLT_ENTRY;
    }
    परत -1;
}

#ifdef NEED_BUILD_GOT
ST_FUNC अचिन्हित create_plt_entry(TCCState *s1, अचिन्हित got_offset, संरचना sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    अचिन्हित plt_offset;

    /* when building a DLL, GOT entry accesses must be done relative to
       start of GOT (see x86_64 example above)  */

    /* empty PLT: create PLT0 entry that push address of call site and
       jump to ld.so resolution routine (GOT + 8) */
    जर (plt->data_offset == 0) {
        p = section_ptr_add(plt, 20);
        write32le(p,    0xe52de004); /* push {lr}         */
        write32le(p+4,  0xe59fe004); /* ldr lr, [pc, #4] */
        write32le(p+8,  0xe08fe00e); /* add lr, pc, lr    */
        write32le(p+12, 0xe5bef008); /* ldr pc, [lr, #8]! */
        /* p+16 is set in relocate_plt */
    }
    plt_offset = plt->data_offset;

    जर (attr->plt_thumb_stub) {
        p = section_ptr_add(plt, 4);
        write32le(p,   0x4778); /* bx pc */
        write32le(p+2, 0x46c0); /* nop   */
    }
    p = section_ptr_add(plt, 16);
    /* save GOT offset for relocate_plt */
    write32le(p + 4, got_offset);
    परत plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC शून्य relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    जर (!s1->plt)
      परत;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    जर (p < p_end) {
        पूर्णांक x = s1->got->sh_addr - s1->plt->sh_addr - 12;
        write32le(s1->plt->data + 16, x - 4);
        p += 20;
        पर्यंत (p < p_end) {
	    अचिन्हित off = x  + read32le(p + 4) + (s1->plt->data - p) + 4;
            जर (read32le(p) == 0x46c04778) /* PLT Thumb stub present */
                p += 4;
            write32le(p, 0xe28fc200 | ((off >> 28) & 0xf));      // add ip, pc, #0xN0000000
            write32le(p + 4, 0xe28cc600 | ((off >> 20) & 0xff)); // add ip, pc, #0xNN00000
            write32le(p + 8, 0xe28cca00 | ((off >> 12) & 0xff)); // add ip, ip, #0xNN000
            write32le(p + 12, 0xe5bcf000 | (off & 0xfff));	 // ldr pc, [ip, #0xNNN]!
            p += 16;
        }
    }

    जर (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->data;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_offset, s1->plt->sh_addr);
	}
    }
}
#endif
#endif

ST_FUNC शून्य relocate(TCCState *s1, ElfW_Rel *rel, पूर्णांक type, अचिन्हित अक्षर *ptr, addr_t addr, addr_t val)
{
    ElfW(Sym) *sym;
    पूर्णांक sym_index, esym_index;

    sym_index = ELFW(R_SYM)(rel->r_info);
    sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];

    निवड(type) {
        स्थिती R_ARM_PC24:
        स्थिती R_ARM_CALL:
        स्थिती R_ARM_JUMP24:
        स्थिती R_ARM_PLT32:
            {
                पूर्णांक x, is_thumb, is_call, h, blx_avail, is_bl, th_ko;
                अचिन्हित code = read32le(ptr);
                x = code & 0x00ffffff;
#ifdef DEBUG_RELOC
		म_लिखो ("reloc %d: x=0x%x val=0x%x ", type, x, val);
#endif
                code &= 0xff000000;
                x <<= 2;
                जर (x & 0x2000000)
                    x -= 0x4000000;
                blx_avail = (CONFIG_TCC_CPUVER >= 5);
                is_thumb = val & 1;
                is_bl = code == 0xeb000000;
                is_call = (type == R_ARM_CALL || (type == R_ARM_PC24 && is_bl));
                x += val - addr;
#ifdef DEBUG_RELOC
		म_लिखो (" newx=0x%x name=%s\n", x,
			(अक्षर *) symtab_section->link->data + sym->st_name);
#endif
                h = x & 2;
                th_ko = (x & 3) && (!blx_avail || !is_call);
                जर (th_ko || x >= 0x2000000 || x < -0x2000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                x >>= 2;
                x &= 0xffffff;
                /* Only reached if blx is avail and it is a call */
                जर (is_thumb) {
                    x |= h << 24;
                    code = 0xfa000000; /* bl -> blx */
                }
                write32le(ptr, code | x);
            }
            परत;
        /* Since these relocations only concern Thumb-2 and blx instruction was
           introduced before Thumb-2, we can assume blx is available and not
           guard its use */
        स्थिती R_ARM_THM_PC22:
        स्थिती R_ARM_THM_JUMP24:
            {
                पूर्णांक x, hi, lo, s, j1, j2, i1, i2, imm10, imm11;
                पूर्णांक to_thumb, is_call, to_plt, blx_bit = 1 << 12;
                Section *plt;

                /* weak reference */
                जर (sym->st_shndx == SHN_UNDEF &&
                    ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
                    परत;

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
                जर (x & 0x01000000)
                    x -= 0x02000000;

                /* Relocation infos */
                to_thumb = val & 1;
                plt = s1->plt;
                to_plt = (val >= plt->sh_addr) &&
                         (val < plt->sh_addr + plt->data_offset);
                is_call = (type == R_ARM_THM_PC22);

                जर (!to_thumb && !to_plt && !is_call) {
                    पूर्णांक index;
                    uint8_t *p;
                    अक्षर *name, buf[1024];
                    Section *text;

                    name = (अक्षर *) symtab_section->link->data + sym->st_name;
                    text = s1->sections[sym->st_shndx];
                    /* Modify reloc to target a thumb stub to switch to ARM */
                    snprintf(buf, आकार(buf), "%s_from_thumb", name);
                    index = put_elf_sym(symtab_section,
                                        text->data_offset + 1,
                                        sym->st_size, sym->st_info, 0,
                                        sym->st_shndx, buf);
                    to_thumb = 1;
                    val = text->data_offset + 1;
                    rel->r_info = ELFW(R_INFO)(index, type);
                    /* Create a thumb stub function to switch to ARM mode */
                    put_elf_reloc(symtab_section, text,
                                  text->data_offset + 4, R_ARM_JUMP24,
                                  sym_index);
                    p = section_ptr_add(text, 8);
                    write32le(p,   0x4778); /* bx pc */
                    write32le(p+2, 0x46c0); /* nop   */
                    write32le(p+4, 0xeafffffe); /* b $sym */
                }

                /* Compute final offset */
                x += val - addr;
                जर (!to_thumb && is_call) {
                    blx_bit = 0; /* bl -> blx */
                    x = (x + 3) & -4; /* Compute offset from aligned PC */
                }

                /* Check that relocation is possible
                   * offset must not be out of range
                   * if target is to be entered in arm mode:
                     - bit 1 must not set
                     - instruction must be a call (bl) or a jump to PLT */
                जर (!to_thumb || x >= 0x1000000 || x < -0x1000000)
                    जर (to_thumb || (val & 2) || (!is_call && !to_plt))
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
            परत;
        स्थिती R_ARM_MOVT_ABS:
        स्थिती R_ARM_MOVW_ABS_NC:
            {
                पूर्णांक x, imm4, imm12;
                जर (type == R_ARM_MOVT_ABS)
                    val >>= 16;
                imm12 = val & 0xfff;
                imm4 = (val >> 12) & 0xf;
                x = (imm4 << 16) | imm12;
                जर (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                अन्यथा
                    add32le(ptr, x);
            }
            परत;
        स्थिती R_ARM_MOVT_PREL:
        स्थिती R_ARM_MOVW_PREL_NC:
            {
		पूर्णांक insn = read32le(ptr);
                पूर्णांक addend = ((insn >> 4) & 0xf000) | (insn & 0xfff);

		addend = (addend ^ 0x8000) - 0x8000;
		val += addend - addr;
		जर (type == R_ARM_MOVT_PREL)
		    val >>= 16;
		write32le(ptr, (insn & 0xfff0f000) |
			       ((val & 0xf000) << 4) | (val & 0xfff));
            }
            परत;
        स्थिती R_ARM_THM_MOVT_ABS:
        स्थिती R_ARM_THM_MOVW_ABS_NC:
            {
                पूर्णांक x, i, imm4, imm3, imm8;
                जर (type == R_ARM_THM_MOVT_ABS)
                    val >>= 16;
                imm8 = val & 0xff;
                imm3 = (val >> 8) & 0x7;
                i = (val >> 11) & 1;
                imm4 = (val >> 12) & 0xf;
                x = (imm3 << 28) | (imm8 << 16) | (i << 10) | imm4;
                जर (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                अन्यथा
                    add32le(ptr, x);
            }
            परत;
        स्थिती R_ARM_PREL31:
            {
                पूर्णांक x;
                x = read32le(ptr) & 0x7fffffff;
                write32le(ptr, read32le(ptr) & 0x80000000);
                x = (x * 2) / 2;
                x += val - addr;
                जर((x^(x>>1))&0x40000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                write32le(ptr, read32le(ptr) | (x & 0x7fffffff));
            }
            परत;
        स्थिती R_ARM_ABS32:
        स्थिती R_ARM_TARGET1:
            जर (s1->output_type & TCC_OUTPUT_DYN) {
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                qrel->r_offset = rel->r_offset;
                जर (esym_index) {
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_ARM_ABS32);
                    qrel++;
                    परत;
                } अन्यथा {
                    qrel->r_info = ELFW(R_INFO)(0, R_ARM_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            परत;
        स्थिती R_ARM_REL32:
            add32le(ptr, val - addr);
            परत;
        स्थिती R_ARM_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            परत;
        स्थिती R_ARM_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            परत;
        स्थिती R_ARM_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            परत;
	स्थिती R_ARM_GOT_PREL:
            /* we load the pc relative got offset */
            add32le(ptr, s1->got->sh_addr +
			 get_sym_attr(s1, sym_index, 0)->got_offset -
			 addr);
            परत;
        स्थिती R_ARM_COPY:
            परत;
        स्थिती R_ARM_V4BX:
            /* trade Thumb support for ARMv4 support */
            जर ((0x0ffffff0 & read32le(ptr)) == 0x012FFF10)
                write32le(ptr, read32le(ptr) ^ 0xE12FFF10 ^ 0xE1A0F000); /* BX Rm -> MOV PC, Rm */
            परत;
        स्थिती R_ARM_GLOB_DAT:
        स्थिती R_ARM_JUMP_SLOT:
            write32le(ptr, val);
            परत;
        स्थिती R_ARM_NONE:
            /* Nothing to do.  Normally used to indicate a dependency
               on a certain symbol (like for exception handling under EABI).  */
            परत;
        स्थिती R_ARM_RELATIVE:
#ifdef TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            परत;
        स्थिती R_ARM_TLS_LE32:
            {
                int32_t x;
                जर (s1->tls_end) {
                    x = val - s1->tls_start + 8;
                } अन्यथा {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->data_offset + 8;
                }
                add32le(ptr, x);
            }
            परत;
        पूर्वनिर्धारित:
            ख_लिखो(मानक_त्रुटि,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (अचिन्हित)addr, ptr, (अचिन्हित)val);
            परत;
    }
}

#endif /* !TARGET_DEFS_ONLY */
