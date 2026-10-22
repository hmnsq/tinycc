#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_ARM

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_ARM_ABS32
#define R_DATA_PTR  R_ARM_ABS32
#define R_JMP_SLOT  R_ARM_JUMP_SLOT
#define R_GLOB_DAT  R_ARM_GLOB_DAT
#define R_COPY      R_ARM_COPY
#define R_RELATIVE  R_ARM_RELATIVE

#define R_ଅଙ୍କ       R_ARM_ଅଙ୍କ

#define ELF_START_ADDR 0x00010000
#define ELF_PAGE_SIZE  0x10000

#define PCRELATIVE_DLLPLT 1
#define RELOCATE_DLLPLT 1

#ଅନ୍ୟଥା /* !TARGET_DEFS_ONLY */

#ଅନ୍ତର୍ଭାଵ "tcc.h"

#ifdef NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା code_reloc (ପୂର୍ଣ୍ଣସଂଖ୍ୟା reloc_type)
{
    ବାଛ (reloc_type) {
	ସ୍ଥିତି R_ARM_MOVT_ABS:
	ସ୍ଥିତି R_ARM_MOVW_ABS_NC:
	ସ୍ଥିତି R_ARM_THM_MOVT_ABS:
	ସ୍ଥିତି R_ARM_THM_MOVW_ABS_NC:
	ସ୍ଥିତି R_ARM_ABS32:
	ସ୍ଥିତି R_ARM_REL32:
	ସ୍ଥିତି R_ARM_GOTPC:
	ସ୍ଥିତି R_ARM_GOTOFF:
	ସ୍ଥିତି R_ARM_GOT32:
	ସ୍ଥିତି R_ARM_GOT_PREL:
	ସ୍ଥିତି R_ARM_COPY:
	ସ୍ଥିତି R_ARM_GLOB_DAT:
	ସ୍ଥିତି R_ARM_NONE:
	ସ୍ଥିତି R_ARM_TARGET1:
	ସ୍ଥିତି R_ARM_MOVT_PREL:
	ସ୍ଥିତି R_ARM_MOVW_PREL_NC:
	ସ୍ଥିତି R_ARM_TLS_LE32:
            ଫେରନ୍ତୁ 0;

        ସ୍ଥିତି R_ARM_PC24:
        ସ୍ଥିତି R_ARM_CALL:
	ସ୍ଥିତି R_ARM_JUMP24:
	ସ୍ଥିତି R_ARM_PLT32:
	ସ୍ଥିତି R_ARM_THM_PC22:
	ସ୍ଥିତି R_ARM_THM_JUMP24:
	ସ୍ଥିତି R_ARM_PREL31:
	ସ୍ଥିତି R_ARM_V4BX:
	ସ୍ଥିତି R_ARM_JUMP_SLOT:
            ଫେରନ୍ତୁ 1;
    }
    ଫେରନ୍ତୁ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gotplt_entry_type (ପୂର୍ଣ୍ଣସଂଖ୍ୟା reloc_type)
{
    ବାଛ (reloc_type) {
	ସ୍ଥିତି R_ARM_NONE:
	ସ୍ଥିତି R_ARM_COPY:
	ସ୍ଥିତି R_ARM_GLOB_DAT:
	ସ୍ଥିତି R_ARM_JUMP_SLOT:
	ସ୍ଥିତି R_ARM_TLS_LE32:
            ଫେରନ୍ତୁ NO_GOTPLT_ENTRY;

        ସ୍ଥିତି R_ARM_PC24:
        ସ୍ଥିତି R_ARM_CALL:
	ସ୍ଥିତି R_ARM_JUMP24:
	ସ୍ଥିତି R_ARM_PLT32:
	ସ୍ଥିତି R_ARM_THM_PC22:
	ସ୍ଥିତି R_ARM_THM_JUMP24:
	ସ୍ଥିତି R_ARM_MOVT_ABS:
	ସ୍ଥିତି R_ARM_MOVW_ABS_NC:
	ସ୍ଥିତି R_ARM_THM_MOVT_ABS:
	ସ୍ଥିତି R_ARM_THM_MOVW_ABS_NC:
	ସ୍ଥିତି R_ARM_PREL31:
	ସ୍ଥିତି R_ARM_ABS32:
	ସ୍ଥିତି R_ARM_REL32:
	ସ୍ଥିତି R_ARM_V4BX:
	ସ୍ଥିତି R_ARM_TARGET1:
	ସ୍ଥିତି R_ARM_MOVT_PREL:
	ସ୍ଥିତି R_ARM_MOVW_PREL_NC:
            ଫେରନ୍ତୁ AUTO_GOTPLT_ENTRY;

	ସ୍ଥିତି R_ARM_GOTPC:
	ସ୍ଥିତି R_ARM_GOTOFF:
            ଫେରନ୍ତୁ BUILD_GOT_ONLY;

	ସ୍ଥିତି R_ARM_GOT32:
	ସ୍ଥିତି R_ARM_GOT_PREL:
            ଫେରନ୍ତୁ ALWAYS_GOTPLT_ENTRY;
    }
    ଫେରନ୍ତୁ -1;
}

#ifdef NEED_BUILD_GOT
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, ସଂରଚନା sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    unsigned plt_offset;

    /* when building a DLL, GOT entry accesses must be done relative to
       start of GOT (see x86_64 example above)  */

    /* empty PLT: create PLT0 entry that push address of call site and
       jump to ld.so resolution routine (GOT + 8) */
    ଯଦି (plt->data_offset == 0) {
        p = section_ptr_add(plt, 20);
        write32le(p,    0xe52de004); /* push {lr}         */
        write32le(p+4,  0xe59fe004); /* ldr lr, [pc, #4] */
        write32le(p+8,  0xe08fe00e); /* add lr, pc, lr    */
        write32le(p+12, 0xe5bef008); /* ldr pc, [lr, #8]! */
        /* p+16 is set in relocate_plt */
    }
    plt_offset = plt->data_offset;

    ଯଦି (attr->plt_thumb_stub) {
        p = section_ptr_add(plt, 4);
        write32le(p,   0x4778); /* bx pc */
        write32le(p+2, 0x46c0); /* nop   */
    }
    p = section_ptr_add(plt, 16);
    /* save GOT offset for relocate_plt */
    write32le(p + 4, got_offset);
    ଫେରନ୍ତୁ plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC ଶୂନ୍ୟ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    ଯଦି (!s1->plt)
      ଫେରନ୍ତୁ;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    ଯଦି (p < p_end) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = s1->got->sh_addr - s1->plt->sh_addr - 12;
        write32le(s1->plt->data + 16, x - 4);
        p += 20;
        ଯେତେବେଳେ (p < p_end) {
	    unsigned off = x  + read32le(p + 4) + (s1->plt->data - p) + 4;
            ଯଦି (read32le(p) == 0x46c04778) /* PLT Thumb stub present */
                p += 4;
            write32le(p, 0xe28fc200 | ((off >> 28) & 0xf));      // add ip, pc, #0xN0000000
            write32le(p + 4, 0xe28cc600 | ((off >> 20) & 0xff)); // add ip, pc, #0xNN00000
            write32le(p + 8, 0xe28cca00 | ((off >> 12) & 0xff)); // add ip, ip, #0xNN000
            write32le(p + 12, 0xe5bcf000 | (off & 0xfff));	 // ldr pc, [ip, #0xNNN]!
            p += 16;
        }
    }

    ଯଦି (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->data;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_offset, s1->plt->sh_addr);
	}
    }
}
#endif
#endif

ST_FUNC ଶୂନ୍ୟ relocate(TCCState *s1, ElfW_Rel *rel, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, unsigned ଅକ୍ଷର *ptr, addr_t addr, addr_t val)
{
    ElfW(Sym) *sym;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_index, esym_index;

    sym_index = ELFW(R_SYM)(rel->r_info);
    sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];

    ବାଛ(type) {
        ସ୍ଥିତି R_ARM_PC24:
        ସ୍ଥିତି R_ARM_CALL:
        ସ୍ଥିତି R_ARM_JUMP24:
        ସ୍ଥିତି R_ARM_PLT32:
            {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା x, is_thumb, is_call, h, blx_avail, is_bl, th_ko;
                unsigned code = read32le(ptr);
                x = code & 0x00ffffff;
#ifdef DEBUG_RELOC
		printf ("reloc %d: x=0x%x val=0x%x ", type, x, val);
#endif
                code &= 0xff000000;
                x <<= 2;
                ଯଦି (x & 0x2000000)
                    x -= 0x4000000;
                blx_avail = (CONFIG_TCC_CPUVER >= 5);
                is_thumb = val & 1;
                is_bl = code == 0xeb000000;
                is_call = (type == R_ARM_CALL || (type == R_ARM_PC24 && is_bl));
                x += val - addr;
#ifdef DEBUG_RELOC
		printf (" newx=0x%x name=%s\n", x,
			(ଅକ୍ଷର *) symtab_section->link->data + sym->st_name);
#endif
                h = x & 2;
                th_ko = (x & 3) && (!blx_avail || !is_call);
                ଯଦି (th_ko || x >= 0x2000000 || x < -0x2000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                x >>= 2;
                x &= 0xffffff;
                /* Only reached if blx is avail and it is a call */
                ଯଦି (is_thumb) {
                    x |= h << 24;
                    code = 0xfa000000; /* bl -> blx */
                }
                write32le(ptr, code | x);
            }
            ଫେରନ୍ତୁ;
        /* Since these relocations only concern Thumb-2 and blx instruction was
           introduced before Thumb-2, we can assume blx is available and not
           guard its use */
        ସ୍ଥିତି R_ARM_THM_PC22:
        ସ୍ଥିତି R_ARM_THM_JUMP24:
            {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା x, hi, lo, s, j1, j2, i1, i2, imm10, imm11;
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା to_thumb, is_call, to_plt, blx_bit = 1 << 12;
                Section *plt;

                /* weak reference */
                ଯଦି (sym->st_shndx == SHN_UNDEF &&
                    ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
                    ଫେରନ୍ତୁ;

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
                ଯଦି (x & 0x01000000)
                    x -= 0x02000000;

                /* Relocation infos */
                to_thumb = val & 1;
                plt = s1->plt;
                to_plt = (val >= plt->sh_addr) &&
                         (val < plt->sh_addr + plt->data_offset);
                is_call = (type == R_ARM_THM_PC22);

                ଯଦି (!to_thumb && !to_plt && !is_call) {
                    ପୂର୍ଣ୍ଣସଂଖ୍ୟା index;
                    uint8_t *p;
                    ଅକ୍ଷର *name, buf[1024];
                    Section *text;

                    name = (ଅକ୍ଷର *) symtab_section->link->data + sym->st_name;
                    text = s1->sections[sym->st_shndx];
                    /* Modify reloc to target a thumb stub to switch to ARM */
                    snprintf(buf, ଆକାର(buf), "%s_from_thumb", name);
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
                ଯଦି (!to_thumb && is_call) {
                    blx_bit = 0; /* bl -> blx */
                    x = (x + 3) & -4; /* Compute offset from aligned PC */
                }

                /* Check that relocation is possible
                   * offset must not be out of range
                   * if target is to be entered in arm mode:
                     - bit 1 must not set
                     - instruction must be a call (bl) or a jump to PLT */
                ଯଦି (!to_thumb || x >= 0x1000000 || x < -0x1000000)
                    ଯଦି (to_thumb || (val & 2) || (!is_call && !to_plt))
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
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_MOVT_ABS:
        ସ୍ଥିତି R_ARM_MOVW_ABS_NC:
            {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା x, imm4, imm12;
                ଯଦି (type == R_ARM_MOVT_ABS)
                    val >>= 16;
                imm12 = val & 0xfff;
                imm4 = (val >> 12) & 0xf;
                x = (imm4 << 16) | imm12;
                ଯଦି (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                ଅନ୍ୟଥା
                    add32le(ptr, x);
            }
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_MOVT_PREL:
        ସ୍ଥିତି R_ARM_MOVW_PREL_NC:
            {
		ପୂର୍ଣ୍ଣସଂଖ୍ୟା insn = read32le(ptr);
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା addend = ((insn >> 4) & 0xf000) | (insn & 0xfff);

		addend = (addend ^ 0x8000) - 0x8000;
		val += addend - addr;
		ଯଦି (type == R_ARM_MOVT_PREL)
		    val >>= 16;
		write32le(ptr, (insn & 0xfff0f000) |
			       ((val & 0xf000) << 4) | (val & 0xfff));
            }
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_THM_MOVT_ABS:
        ସ୍ଥିତି R_ARM_THM_MOVW_ABS_NC:
            {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା x, i, imm4, imm3, imm8;
                ଯଦି (type == R_ARM_THM_MOVT_ABS)
                    val >>= 16;
                imm8 = val & 0xff;
                imm3 = (val >> 8) & 0x7;
                i = (val >> 11) & 1;
                imm4 = (val >> 12) & 0xf;
                x = (imm3 << 28) | (imm8 << 16) | (i << 10) | imm4;
                ଯଦି (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                ଅନ୍ୟଥା
                    add32le(ptr, x);
            }
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_PREL31:
            {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା x;
                x = read32le(ptr) & 0x7fffffff;
                write32le(ptr, read32le(ptr) & 0x80000000);
                x = (x * 2) / 2;
                x += val - addr;
                ଯଦି((x^(x>>1))&0x40000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                write32le(ptr, read32le(ptr) | (x & 0x7fffffff));
            }
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_ABS32:
        ସ୍ଥିତି R_ARM_TARGET1:
            ଯଦି (s1->output_type & TCC_OUTPUT_DYN) {
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                qrel->r_offset = rel->r_offset;
                ଯଦି (esym_index) {
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_ARM_ABS32);
                    qrel++;
                    ଫେରନ୍ତୁ;
                } ଅନ୍ୟଥା {
                    qrel->r_info = ELFW(R_INFO)(0, R_ARM_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_REL32:
            add32le(ptr, val - addr);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            ଫେରନ୍ତୁ;
	ସ୍ଥିତି R_ARM_GOT_PREL:
            /* we load the pc relative got offset */
            add32le(ptr, s1->got->sh_addr +
			 get_sym_attr(s1, sym_index, 0)->got_offset -
			 addr);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_COPY:
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_V4BX:
            /* trade Thumb support for ARMv4 support */
            ଯଦି ((0x0ffffff0 & read32le(ptr)) == 0x012FFF10)
                write32le(ptr, read32le(ptr) ^ 0xE12FFF10 ^ 0xE1A0F000); /* BX Rm -> MOV PC, Rm */
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_GLOB_DAT:
        ସ୍ଥିତି R_ARM_JUMP_SLOT:
            write32le(ptr, val);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_NONE:
            /* Nothing to do.  Normally used to indicate a dependency
               on a certain symbol (like for exception handling under EABI).  */
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_RELATIVE:
#ifdef TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_ARM_TLS_LE32:
            {
                int32_t x;
                ଯଦି (s1->tls_end) {
                    x = val - s1->tls_start + 8;
                } ଅନ୍ୟଥା {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->data_offset + 8;
                }
                add32le(ptr, x);
            }
            ଫେରନ୍ତୁ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (unsigned)addr, ptr, (unsigned)val);
            ଫେରନ୍ତୁ;
    }
}

#endif /* !TARGET_DEFS_ONLY */
