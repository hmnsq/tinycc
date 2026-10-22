#यदि_परिभाषितम् TARGET_DEFS_ONLY

#परिभाषय EM_TCC_TARGET EM_X86_64

/* relocation type for 32 bit data relocation */
#परिभाषय R_दत्त_32   R_X86_64_32S
#परिभाषय R_दत्त_PTR  R_X86_64_64
#परिभाषय R_JMP_SLOT  R_X86_64_JUMP_SLOT
#परिभाषय R_GLOB_DAT  R_X86_64_GLOB_DAT
#परिभाषय R_COPY      R_X86_64_COPY
#परिभाषय R_RELATIVE  R_X86_64_RELATIVE

#परिभाषय R_अङ्कः       R_X86_64_अङ्कः

#परिभाषय ELF_START_ADDR 0x400000
#परिभाषय ELF_PAGE_आकार  0x1000

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
        पक्ष R_X86_64_32:
        पक्ष R_X86_64_32S:
        पक्ष R_X86_64_64:
        पक्ष R_X86_64_GOTPC32:
        पक्ष R_X86_64_GOTPC64:
        पक्ष R_X86_64_GOTPCREL:
        पक्ष R_X86_64_GOTPCRELX:
        पक्ष R_X86_64_REX_GOTPCRELX:
        पक्ष R_X86_64_GOTTPOFF:
        पक्ष R_X86_64_GOT32:
        पक्ष R_X86_64_GOT64:
        पक्ष R_X86_64_GLOB_DAT:
        पक्ष R_X86_64_COPY:
        पक्ष R_X86_64_RELATIVE:
        पक्ष R_X86_64_GOTOFF64:
        पक्ष R_X86_64_TLSGD:
        पक्ष R_X86_64_TLSLD:
        पक्ष R_X86_64_DTPOFF32:
        पक्ष R_X86_64_TPOFF32:
        पक्ष R_X86_64_DTPOFF64:
        पक्ष R_X86_64_TPOFF64:
            प्रत्यागम 0;

        पक्ष R_X86_64_PC32:
        पक्ष R_X86_64_PC64:
        पक्ष R_X86_64_PLT32:
        पक्ष R_X86_64_PLTOFF64:
        पक्ष R_X86_64_JUMP_SLOT:
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
        पक्ष R_X86_64_GLOB_DAT:
        पक्ष R_X86_64_JUMP_SLOT:
        पक्ष R_X86_64_COPY:
        पक्ष R_X86_64_RELATIVE:
            प्रत्यागम NO_GOTPLT_प्रविष्टिः;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        पक्ष R_X86_64_32:
        पक्ष R_X86_64_32S:
        पक्ष R_X86_64_64:
        पक्ष R_X86_64_PC32:
        पक्ष R_X86_64_PC64:
            प्रत्यागम AUTO_GOTPLT_प्रविष्टिः;

        पक्ष R_X86_64_GOTTPOFF:
            प्रत्यागम BUILD_GOT_ONLY;

        पक्ष R_X86_64_GOT32:
        पक्ष R_X86_64_GOT64:
        पक्ष R_X86_64_GOTPC32:
        पक्ष R_X86_64_GOTPC64:
        पक्ष R_X86_64_GOTOFF64:
        पक्ष R_X86_64_GOTPCREL:
        पक्ष R_X86_64_GOTPCRELX:
        पक्ष R_X86_64_TLSGD:
        पक्ष R_X86_64_TLSLD:
        पक्ष R_X86_64_DTPOFF32:
        पक्ष R_X86_64_DTPOFF64:
        पक्ष R_X86_64_REX_GOTPCRELX:
        पक्ष R_X86_64_PLT32:
        पक्ष R_X86_64_PLTOFF64:
            प्रत्यागम ALWAYS_GOTPLT_प्रविष्टिः;

        पक्ष R_X86_64_TPOFF32:
        पक्ष R_X86_64_TPOFF64:
            प्रत्यागम NO_GOTPLT_प्रविष्टिः;
    }

    प्रत्यागम -1;
}

#यदि_परिभाषितम् NEED_BUILD_GOT
ST_FUNC अचिह्नित create_plt_प्रविष्टिः(TCCState *s1, अचिह्नित got_विस्थापनम्, संरचना sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    पूर्णाङ्क modrm;
    अचिह्नित plt_विस्थापनम्, relofs;

    modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    यदि (plt->दत्त_विस्थापनम् == 0) {
        p = section_ptr_सङ्कलय(plt, 16);
        p[0] = 0xff; /* pushl got + PTR_SIZE */
        p[1] = modrm + 0x10;
        write32le(p + 2, PTR_आकार);
        p[6] = 0xff; /* jmp *(got + PTR_SIZE * 2) */
        p[7] = modrm;
        write32le(p + 8, PTR_आकार * 2);
    }
    plt_विस्थापनम् = plt->दत्त_विस्थापनम्;

    /* The PLT slot refers to the relocation entry it needs via offset.
       The reloc entry is created below, so its offset is the current
       data_offset */
    relofs = s1->plt->reloc ? s1->plt->reloc->दत्त_विस्थापनम् : 0;

    /* Jump to GOT entry where ld.so initially put the address of ip + 4 */
    p = section_ptr_सङ्कलय(plt, 16);
    p[0] = 0xff; /* jmp *(got + x) */
    p[1] = modrm;
    write32le(p + 2, got_विस्थापनम्);
    p[6] = 0x68; /* push $xxx */
    /* On x86-64, the relocation is referred to by _index_ */
    write32le(p + 7, relofs / परिमाण (ElfW_Rel) - 1);
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->दत्त_विस्थापनम्));
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
        पूर्णाङ्क x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        यावत् (p < p_अन्तः) {
            add32le(p + 2, x + (s1->plt->दत्त - p));
            p += 16;
        }
    }

    यदि (s1->plt->reloc) {
        ElfW_Rel *rel;
        पूर्णाङ्क x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->दत्त;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_विस्थापनम्, x);
            x += 16;
        }
    }
}
#यदि_अन्तः
#यदि_अन्तः

ST_FUNC शून्य relocate(TCCState *s1, ElfW_Rel *rel, पूर्णाङ्क type, अचिह्नित वर्ण *ptr, addr_t addr, addr_t val)
{
    पूर्णाङ्क sym_सूचकांक, esym_सूचकांक;

    sym_सूचकांक = ELFW(R_SYM)(rel->r_info);

    विकल्प (type) {
        पक्ष R_X86_64_64:
            यदि (s1->output_type & TCC_OUTPUT_DYN) {
                esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
                qrel->r_विस्थापनम् = rel->r_विस्थापनम्;
                यदि (esym_सूचकांक) {
                    qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_X86_64_64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    भङ्ग;
                } अन्यथा {
                    qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            भङ्ग;
        पक्ष R_X86_64_32:
        पक्ष R_X86_64_32S:
            यदि (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_विस्थापनम् = rel->r_विस्थापनम्;
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (पूर्णाङ्क)read32le(ptr) + val;
                qrel++;
            }
            यदि ((type == R_X86_64_32 ? val != (अचिह्नित)val : val != (पूर्णाङ्क)val)
                /* ignore relocation check for stab section */
                && (stab_section == रिक्त ||
                    addr < stab_section->sh_addr ||
                    addr >= (stab_section->sh_addr + stab_section->दत्त_विस्थापनम्))) {
                tcc_error_noabort("relocation 'R_X86_64_32[S]' out of range");
            }
            add32le(ptr, val);
            भङ्ग;

        पक्ष R_X86_64_PC32:
            यदि (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
                यदि (esym_सूचकांक) {
                    qrel->r_विस्थापनम् = rel->r_विस्थापनम्;
                    qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_X86_64_PC32);
                    /* Use sign extension! */
                    qrel->r_addend = (पूर्णाङ्क)read32le(ptr) + rel->r_addend;
                    qrel++;
                    भङ्ग;
                }
            }
            गच्छ plt32pc32;

        पक्ष R_X86_64_PLT32:
            /* fallthrough: val already holds the PLT slot address */

        plt32pc32:
        {
            दीर्घ दीर्घ diff;
            diff = (दीर्घ दीर्घ)val - addr;
            यदि (diff < -2147483648LL || diff > 2147483647LL) {
#यदि_परिभाषितम् TCC_TARGET_PE
              /* ignore overflow with undefined weak symbols */
              यदि (((ElfW(Sym)*)symtab_section->दत्त)[sym_सूचकांक].st_shndx != SHN_UNDEF)
#यदि_अन्तः
                tcc_error_noabort("relocation '%d' out of range", type);
            }
            add32le(ptr, diff);
        }
            भङ्ग;

        पक्ष R_X86_64_COPY:
	    भङ्ग;

        पक्ष R_X86_64_PLTOFF64:
            add64le(ptr, val - s1->got->sh_addr + rel->r_addend);
            भङ्ग;

        पक्ष R_X86_64_PC64:
            यदि (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
                यदि (esym_सूचकांक) {
                    qrel->r_विस्थापनम् = rel->r_विस्थापनम्;
                    qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    भङ्ग;
                }
            }
            add64le(ptr, val - addr);
            भङ्ग;

        पक्ष R_X86_64_GLOB_DAT:
        पक्ष R_X86_64_JUMP_SLOT:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            भङ्ग;
        पक्ष R_X86_64_GOTPCREL:
        पक्ष R_X86_64_GOTPCRELX:
        पक्ष R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         get_sym_attr(s1, sym_सूचकांक, 0)->got_विस्थापनम् - 4);
            भङ्ग;
        पक्ष R_X86_64_GOTPC32:
            add32le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            भङ्ग;
        पक्ष R_X86_64_GOTPC64:
            add64le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            भङ्ग;
        पक्ष R_X86_64_GOTTPOFF:
            add32le(ptr, val - s1->got->sh_addr);
            भङ्ग;
        पक्ष R_X86_64_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_सूचकांक, 0)->got_विस्थापनम्);
            भङ्ग;
        पक्ष R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, get_sym_attr(s1, sym_सूचकांक, 0)->got_विस्थापनम्);
            भङ्ग;
        पक्ष R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            भङ्ग;
        पक्ष R_X86_64_TLSGD:
            {
                स्थिर ध्रुव अचिह्नित वर्ण expect[] = {
                    /* .byte 0x66; lea 0(%rip),%rdi */
                    0x66, 0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* .word 0x6666; rex64; call __tls_get_addr@PLT */
                    0x66, 0x66, 0x48, 0xe8, 0x00, 0x00, 0x00, 0x00 };
                स्थिर ध्रुव अचिह्नित वर्ण replace[] = {
                    /* mov %fs:0,%rax */
                    0x64, 0x48, 0x8b, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
                    /* lea -4(%rax),%rax */
                    0x48, 0x8d, 0x80, 0x00, 0x00, 0x00, 0x00 };

                यदि (memcmp (ptr-4, expect, परिमाण(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    स्मृतिं_प्रतिलिख(ptr-4, replace, परिमाण(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_मानम् - sec->sh_addr - sec->दत्त_विस्थापनम्;
                    add32le(ptr + 8, x);
                }
                अन्यथा
                    tcc_error_noabort("unexpected R_X86_64_TLSGD pattern");
            }
            भङ्ग;
        पक्ष R_X86_64_TLSLD:
            {
                स्थिर ध्रुव अचिह्नित वर्ण expect[] = {
                    /* lea 0(%rip),%rdi */
                    0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0x00, 0x00, 0x00, 0x00 };
                स्थिर ध्रुव अचिह्नित वर्ण replace[] = {
                    /* data16 data16 data16 mov %fs:0,%rax */
                    0x66, 0x66, 0x66, 0x64, 0x48, 0x8b, 0x04, 0x25,
                    0x00, 0x00, 0x00, 0x00 };

                यदि (memcmp (ptr-3, expect, परिमाण(expect)) == 0) {
                    स्मृतिं_प्रतिलिख(ptr-3, replace, परिमाण(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                }
                अन्यथा
                    tcc_error_noabort("unexpected R_X86_64_TLSLD pattern");
            }
            भङ्ग;

        पक्ष R_X86_64_DTPOFF32:
        पक्ष R_X86_64_TPOFF32:
        पक्ष R_X86_64_DTPOFF64:
        पक्ष R_X86_64_TPOFF64:
            {
                int32_t x;
                यदि (s1->tls_अन्तः) {
                    x = val - s1->tls_अन्तः;
                } अन्यथा {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->दत्त_विस्थापनम्;
                }
                विकल्प (type) {
                पक्ष R_X86_64_DTPOFF64:
                पक्ष R_X86_64_TPOFF64:
                    add64le(ptr, x);
                    भङ्ग;
                स्वभाव:
                    add32le(ptr, x);
                    भङ्ग;
                }
            }
            भङ्ग;
        पक्ष R_X86_64_NONE:
            भङ्ग;
        पक्ष R_X86_64_RELATIVE:
#यदि_परिभाषितम् TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#यदि_अन्तः
            /* do nothing */
            भङ्ग;
        स्वभाव:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (अचिह्नित)addr, ptr, (अचिह्नित)val);
            भङ्ग;
    }
}

#यदि_अन्तः /* !TARGET_DEFS_ONLY */
