#यदि_परिभाषितम् TARGET_DEFS_ONLY

#परिभाषय EM_TCC_TARGET EM_ARM

/* relocation type for 32 bit data relocation */
#परिभाषय R_दत्त_32   R_ARM_ABS32
#परिभाषय R_दत्त_PTR  R_ARM_ABS32
#परिभाषय R_JMP_SLOT  R_ARM_JUMP_SLOT
#परिभाषय R_GLOB_DAT  R_ARM_GLOB_DAT
#परिभाषय R_COPY      R_ARM_COPY
#परिभाषय R_RELATIVE  R_ARM_RELATIVE

#परिभाषय R_अङ्कः       R_ARM_अङ्कः

#परिभाषय ELF_START_ADDR 0x00010000
#परिभाषय ELF_PAGE_आकार  0x10000

#परिभाषय PCRELATIVE_DLLPLT 1
#परिभाषय RELOCATE_DLLPLT 1

#अन्यथा /* !TARGET_DEFS_ONLY */

#अन्तर्भाव "tcc.h"

#यदि_परिभाषितम् NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC पूर्णाङ्क संहिता_reloc (पूर्णाङ्क reloc_type)
{
    विकल्प (reloc_type) {
	पक्ष R_ARM_MOVT_ABS:
	पक्ष R_ARM_MOVW_ABS_NC:
	पक्ष R_ARM_THM_MOVT_ABS:
	पक्ष R_ARM_THM_MOVW_ABS_NC:
	पक्ष R_ARM_ABS32:
	पक्ष R_ARM_REL32:
	पक्ष R_ARM_GOTPC:
	पक्ष R_ARM_GOTOFF:
	पक्ष R_ARM_GOT32:
	पक्ष R_ARM_GOT_PREL:
	पक्ष R_ARM_COPY:
	पक्ष R_ARM_GLOB_DAT:
	पक्ष R_ARM_NONE:
	पक्ष R_ARM_TARGET1:
	पक्ष R_ARM_MOVT_PREL:
	पक्ष R_ARM_MOVW_PREL_NC:
	पक्ष R_ARM_TLS_LE32:
            प्रत्यागम 0;

        पक्ष R_ARM_PC24:
        पक्ष R_ARM_CALL:
	पक्ष R_ARM_JUMP24:
	पक्ष R_ARM_PLT32:
	पक्ष R_ARM_THM_PC22:
	पक्ष R_ARM_THM_JUMP24:
	पक्ष R_ARM_PREL31:
	पक्ष R_ARM_V4BX:
	पक्ष R_ARM_JUMP_SLOT:
            प्रत्यागम 1;
    }
    प्रत्यागम -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC पूर्णाङ्क gotplt_प्रविष्टिः_type (पूर्णाङ्क reloc_type)
{
    विकल्प (reloc_type) {
	पक्ष R_ARM_NONE:
	पक्ष R_ARM_COPY:
	पक्ष R_ARM_GLOB_DAT:
	पक्ष R_ARM_JUMP_SLOT:
	पक्ष R_ARM_TLS_LE32:
            प्रत्यागम NO_GOTPLT_प्रविष्टिः;

        पक्ष R_ARM_PC24:
        पक्ष R_ARM_CALL:
	पक्ष R_ARM_JUMP24:
	पक्ष R_ARM_PLT32:
	पक्ष R_ARM_THM_PC22:
	पक्ष R_ARM_THM_JUMP24:
	पक्ष R_ARM_MOVT_ABS:
	पक्ष R_ARM_MOVW_ABS_NC:
	पक्ष R_ARM_THM_MOVT_ABS:
	पक्ष R_ARM_THM_MOVW_ABS_NC:
	पक्ष R_ARM_PREL31:
	पक्ष R_ARM_ABS32:
	पक्ष R_ARM_REL32:
	पक्ष R_ARM_V4BX:
	पक्ष R_ARM_TARGET1:
	पक्ष R_ARM_MOVT_PREL:
	पक्ष R_ARM_MOVW_PREL_NC:
            प्रत्यागम AUTO_GOTPLT_प्रविष्टिः;

	पक्ष R_ARM_GOTPC:
	पक्ष R_ARM_GOTOFF:
            प्रत्यागम BUILD_GOT_ONLY;

	पक्ष R_ARM_GOT32:
	पक्ष R_ARM_GOT_PREL:
            प्रत्यागम ALWAYS_GOTPLT_प्रविष्टिः;
    }
    प्रत्यागम -1;
}

#यदि_परिभाषितम् NEED_BUILD_GOT
ST_FUNC अचिह्नित create_plt_प्रविष्टिः(TCCState *s1, अचिह्नित got_विस्थापनम्, संरचना sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    अचिह्नित plt_विस्थापनम्;

    /* when building a DLL, GOT entry accesses must be done relative to
       start of GOT (see x86_64 example above)  */

    /* empty PLT: create PLT0 entry that push address of call site and
       jump to ld.so resolution routine (GOT + 8) */
    यदि (plt->दत्त_विस्थापनम् == 0) {
        p = section_ptr_सङ्कलय(plt, 20);
        write32le(p,    0xe52de004); /* push {lr}         */
        write32le(p+4,  0xe59fe004); /* ldr lr, [pc, #4] */
        write32le(p+8,  0xe08fe00e); /* add lr, pc, lr    */
        write32le(p+12, 0xe5bef008); /* ldr pc, [lr, #8]! */
        /* p+16 is set in relocate_plt */
    }
    plt_विस्थापनम् = plt->दत्त_विस्थापनम्;

    यदि (attr->plt_thumb_stub) {
        p = section_ptr_सङ्कलय(plt, 4);
        write32le(p,   0x4778); /* bx pc */
        write32le(p+2, 0x46c0); /* nop   */
    }
    p = section_ptr_सङ्कलय(plt, 16);
    /* save GOT offset for relocate_plt */
    write32le(p + 4, got_विस्थापनम्);
    प्रत्यागम plt_विस्थापनम्;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC शून्य relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_अन्तः;

    यदि (!s1->plt)
      प्रत्यागम;

    p = s1->plt->दत्त;
    p_अन्तः = p + s1->plt->दत्त_विस्थापनम्;

    यदि (p < p_अन्तः) {
        पूर्णाङ्क x = s1->got->sh_addr - s1->plt->sh_addr - 12;
        write32le(s1->plt->दत्त + 16, x - 4);
        p += 20;
        यावत् (p < p_अन्तः) {
	    अचिह्नित off = x  + read32le(p + 4) + (s1->plt->दत्त - p) + 4;
            यदि (read32le(p) == 0x46c04778) /* PLT Thumb stub present */
                p += 4;
            write32le(p, 0xe28fc200 | ((off >> 28) & 0xf));      // add ip, pc, #0xN0000000
            write32le(p + 4, 0xe28cc600 | ((off >> 20) & 0xff)); // add ip, pc, #0xNN00000
            write32le(p + 8, 0xe28cca00 | ((off >> 12) & 0xff)); // add ip, ip, #0xNN000
            write32le(p + 12, 0xe5bcf000 | (off & 0xfff));	 // ldr pc, [ip, #0xNNN]!
            p += 16;
        }
    }

    यदि (s1->plt->reloc) {
        ElfW_Rel *rel;
        p = s1->got->दत्त;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_विस्थापनम्, s1->plt->sh_addr);
	}
    }
}
#यदि_अन्तः
#यदि_अन्तः

ST_FUNC शून्य relocate(TCCState *s1, ElfW_Rel *rel, पूर्णाङ्क type, अचिह्नित वर्ण *ptr, addr_t addr, addr_t val)
{
    ElfW(Sym) *sym;
    पूर्णाङ्क sym_सूचकांक, esym_सूचकांक;

    sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
    sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];

    विकल्प(type) {
        पक्ष R_ARM_PC24:
        पक्ष R_ARM_CALL:
        पक्ष R_ARM_JUMP24:
        पक्ष R_ARM_PLT32:
            {
                पूर्णाङ्क x, is_thumb, is_call, h, blx_avail, is_bl, th_ko;
                अचिह्नित संहिता = read32le(ptr);
                x = संहिता & 0x00ffffff;
#यदि_परिभाषितम् DEBUG_RELOC
		प्रारूप_लिख ("reloc %d: x=0x%x val=0x%x ", type, x, val);
#यदि_अन्तः
                संहिता &= 0xff000000;
                x <<= 2;
                यदि (x & 0x2000000)
                    x -= 0x4000000;
                blx_avail = (CONFIG_TCC_CPUVER >= 5);
                is_thumb = val & 1;
                is_bl = संहिता == 0xeb000000;
                is_call = (type == R_ARM_CALL || (type == R_ARM_PC24 && is_bl));
                x += val - addr;
#यदि_परिभाषितम् DEBUG_RELOC
		प्रारूप_लिख (" newx=0x%x name=%s\n", x,
			(वर्ण *) symtab_section->link->दत्त + sym->st_name);
#यदि_अन्तः
                h = x & 2;
                th_ko = (x & 3) && (!blx_avail || !is_call);
                यदि (th_ko || x >= 0x2000000 || x < -0x2000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                x >>= 2;
                x &= 0xffffff;
                /* Only reached if blx is avail and it is a call */
                यदि (is_thumb) {
                    x |= h << 24;
                    संहिता = 0xfa000000; /* bl -> blx */
                }
                write32le(ptr, संहिता | x);
            }
            प्रत्यागम;
        /* Since these relocations only concern Thumb-2 and blx instruction was
           introduced before Thumb-2, we can assume blx is available and not
           guard its use */
        पक्ष R_ARM_THM_PC22:
        पक्ष R_ARM_THM_JUMP24:
            {
                पूर्णाङ्क x, hi, lo, s, j1, j2, i1, i2, imm10, imm11;
                पूर्णाङ्क गन्तव्यम्_thumb, is_call, गन्तव्यम्_plt, blx_bit = 1 << 12;
                Section *plt;

                /* weak reference */
                यदि (sym->st_shndx == SHN_UNDEF &&
                    ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
                    प्रत्यागम;

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
                यदि (x & 0x01000000)
                    x -= 0x02000000;

                /* Relocation infos */
                गन्तव्यम्_thumb = val & 1;
                plt = s1->plt;
                गन्तव्यम्_plt = (val >= plt->sh_addr) &&
                         (val < plt->sh_addr + plt->दत्त_विस्थापनम्);
                is_call = (type == R_ARM_THM_PC22);

                यदि (!गन्तव्यम्_thumb && !गन्तव्यम्_plt && !is_call) {
                    पूर्णाङ्क सूचकांक;
                    uint8_t *p;
                    वर्ण *name, buf[1024];
                    Section *text;

                    name = (वर्ण *) symtab_section->link->दत्त + sym->st_name;
                    text = s1->sections[sym->st_shndx];
                    /* Modify reloc to target a thumb stub to switch to ARM */
                    snprintf(buf, परिमाण(buf), "%s_from_thumb", name);
                    सूचकांक = put_elf_sym(symtab_section,
                                        text->दत्त_विस्थापनम् + 1,
                                        sym->st_आकार, sym->st_info, 0,
                                        sym->st_shndx, buf);
                    गन्तव्यम्_thumb = 1;
                    val = text->दत्त_विस्थापनम् + 1;
                    rel->r_info = ELFW(R_INFO)(सूचकांक, type);
                    /* Create a thumb stub function to switch to ARM mode */
                    put_elf_reloc(symtab_section, text,
                                  text->दत्त_विस्थापनम् + 4, R_ARM_JUMP24,
                                  sym_सूचकांक);
                    p = section_ptr_सङ्कलय(text, 8);
                    write32le(p,   0x4778); /* bx pc */
                    write32le(p+2, 0x46c0); /* nop   */
                    write32le(p+4, 0xeafffffe); /* b $sym */
                }

                /* Compute final offset */
                x += val - addr;
                यदि (!गन्तव्यम्_thumb && is_call) {
                    blx_bit = 0; /* bl -> blx */
                    x = (x + 3) & -4; /* Compute offset from aligned PC */
                }

                /* Check that relocation is possible
                   * offset must not be out of range
                   * if target is to be entered in arm mode:
                     - bit 1 must not set
                     - instruction must be a call (bl) or a jump to PLT */
                यदि (!गन्तव्यम्_thumb || x >= 0x1000000 || x < -0x1000000)
                    यदि (गन्तव्यम्_thumb || (val & 2) || (!is_call && !गन्तव्यम्_plt))
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
            प्रत्यागम;
        पक्ष R_ARM_MOVT_ABS:
        पक्ष R_ARM_MOVW_ABS_NC:
            {
                पूर्णाङ्क x, imm4, imm12;
                यदि (type == R_ARM_MOVT_ABS)
                    val >>= 16;
                imm12 = val & 0xfff;
                imm4 = (val >> 12) & 0xf;
                x = (imm4 << 16) | imm12;
                यदि (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                अन्यथा
                    add32le(ptr, x);
            }
            प्रत्यागम;
        पक्ष R_ARM_MOVT_PREL:
        पक्ष R_ARM_MOVW_PREL_NC:
            {
		पूर्णाङ्क insn = read32le(ptr);
                पूर्णाङ्क addend = ((insn >> 4) & 0xf000) | (insn & 0xfff);

		addend = (addend ^ 0x8000) - 0x8000;
		val += addend - addr;
		यदि (type == R_ARM_MOVT_PREL)
		    val >>= 16;
		write32le(ptr, (insn & 0xfff0f000) |
			       ((val & 0xf000) << 4) | (val & 0xfff));
            }
            प्रत्यागम;
        पक्ष R_ARM_THM_MOVT_ABS:
        पक्ष R_ARM_THM_MOVW_ABS_NC:
            {
                पूर्णाङ्क x, i, imm4, imm3, imm8;
                यदि (type == R_ARM_THM_MOVT_ABS)
                    val >>= 16;
                imm8 = val & 0xff;
                imm3 = (val >> 8) & 0x7;
                i = (val >> 11) & 1;
                imm4 = (val >> 12) & 0xf;
                x = (imm3 << 28) | (imm8 << 16) | (i << 10) | imm4;
                यदि (type == R_ARM_THM_MOVT_ABS)
                    write32le(ptr, read32le(ptr) | x);
                अन्यथा
                    add32le(ptr, x);
            }
            प्रत्यागम;
        पक्ष R_ARM_PREL31:
            {
                पूर्णाङ्क x;
                x = read32le(ptr) & 0x7fffffff;
                write32le(ptr, read32le(ptr) & 0x80000000);
                x = (x * 2) / 2;
                x += val - addr;
                यदि((x^(x>>1))&0x40000000)
                    tcc_error_noabort("can't relocate value at %x,%d",addr, type);
                write32le(ptr, read32le(ptr) | (x & 0x7fffffff));
            }
            प्रत्यागम;
        पक्ष R_ARM_ABS32:
        पक्ष R_ARM_TARGET1:
            यदि (s1->output_type & TCC_OUTPUT_DYN) {
                esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
                qrel->r_विस्थापनम् = rel->r_विस्थापनम्;
                यदि (esym_सूचकांक) {
                    qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_ARM_ABS32);
                    qrel++;
                    प्रत्यागम;
                } अन्यथा {
                    qrel->r_info = ELFW(R_INFO)(0, R_ARM_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            प्रत्यागम;
        पक्ष R_ARM_REL32:
            add32le(ptr, val - addr);
            प्रत्यागम;
        पक्ष R_ARM_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            प्रत्यागम;
        पक्ष R_ARM_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            प्रत्यागम;
        पक्ष R_ARM_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_सूचकांक, 0)->got_विस्थापनम्);
            प्रत्यागम;
	पक्ष R_ARM_GOT_PREL:
            /* we load the pc relative got offset */
            add32le(ptr, s1->got->sh_addr +
			 get_sym_attr(s1, sym_सूचकांक, 0)->got_विस्थापनम् -
			 addr);
            प्रत्यागम;
        पक्ष R_ARM_COPY:
            प्रत्यागम;
        पक्ष R_ARM_V4BX:
            /* trade Thumb support for ARMv4 support */
            यदि ((0x0ffffff0 & read32le(ptr)) == 0x012FFF10)
                write32le(ptr, read32le(ptr) ^ 0xE12FFF10 ^ 0xE1A0F000); /* BX Rm -> MOV PC, Rm */
            प्रत्यागम;
        पक्ष R_ARM_GLOB_DAT:
        पक्ष R_ARM_JUMP_SLOT:
            write32le(ptr, val);
            प्रत्यागम;
        पक्ष R_ARM_NONE:
            /* Nothing to do.  Normally used to indicate a dependency
               on a certain symbol (like for exception handling under EABI).  */
            प्रत्यागम;
        पक्ष R_ARM_RELATIVE:
#यदि_परिभाषितम् TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#यदि_अन्तः
            /* do nothing */
            प्रत्यागम;
        पक्ष R_ARM_TLS_LE32:
            {
                int32_t x;
                यदि (s1->tls_अन्तः) {
                    x = val - s1->tls_start + 8;
                } अन्यथा {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->दत्त_विस्थापनम् + 8;
                }
                add32le(ptr, x);
            }
            प्रत्यागम;
        स्वभाव:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (अचिह्नित)addr, ptr, (अचिह्नित)val);
            प्रत्यागम;
    }
}

#यदि_अन्तः /* !TARGET_DEFS_ONLY */
