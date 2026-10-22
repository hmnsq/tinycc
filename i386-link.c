#अगर_घोषित TARGET_DEFS_ONLY

#घोषणा EM_TCC_TARGET EM_386

/* relocation type for 32 bit data relocation */
#घोषणा R_तथ्य_32   R_386_32
#घोषणा R_तथ्य_PTR  R_386_32
#घोषणा R_JMP_SLOT  R_386_JMP_SLOT
#घोषणा R_GLOB_DAT  R_386_GLOB_DAT
#घोषणा R_COPY      R_386_COPY
#घोषणा R_RELATIVE  R_386_RELATIVE

#घोषणा R_अंक       R_386_अंक

#घोषणा ELF_START_ADDR 0x08048000
#घोषणा ELF_PAGE_आकार  0x1000

#अगर defined CONFIG_TCC_PIC
#घोषणा PCRELATIVE_DLLPLT 1
#अन्यथा
#घोषणा PCRELATIVE_DLLPLT 0
#पूर्ण_अगर
#घोषणा RELOCATE_DLLPLT 1

#अन्यथा /* !TARGET_DEFS_ONLY */

#समावेश "tcc.h"

#अगर_घोषित NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC पूर्णांक code_reloc (पूर्णांक reloc_type)
{
    चयन (reloc_type) {
	हाल R_386_RELATIVE:
	हाल R_386_16:
        हाल R_386_32:
	हाल R_386_GOTPC:
	हाल R_386_GOTOFF:
	हाल R_386_GOT32:
	हाल R_386_GOT32X:
	हाल R_386_GLOB_DAT:
	हाल R_386_COPY:
	हाल R_386_TLS_GD:
	हाल R_386_TLS_LDM:
	हाल R_386_TLS_LDO_32:
	हाल R_386_TLS_LE:
            वापस 0;

	हाल R_386_PC16:
	हाल R_386_PC32:
	हाल R_386_PLT32:
	हाल R_386_JMP_SLOT:
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
	हाल R_386_RELATIVE:
	हाल R_386_16:
	हाल R_386_GLOB_DAT:
	हाल R_386_JMP_SLOT:
	हाल R_386_COPY:
            वापस NO_GOTPLT_ENTRY;

        हाल R_386_32:
	    /* This relocations shouldn't normally need GOT or PLT
	       slots if it weren't for simplicity in the code generator.
	       See our caller for comments.  */
            वापस AUTO_GOTPLT_ENTRY;

	हाल R_386_PC16:
	हाल R_386_PC32:
            वापस AUTO_GOTPLT_ENTRY;

	हाल R_386_GOTPC:
	हाल R_386_GOTOFF:
            वापस BUILD_GOT_ONLY;

	हाल R_386_GOT32:
	हाल R_386_GOT32X:
	हाल R_386_PLT32:
	हाल R_386_TLS_GD:
	हाल R_386_TLS_LDM:
	हाल R_386_TLS_LDO_32:
	हाल R_386_TLS_LE:
            वापस ALWAYS_GOTPLT_ENTRY;
    }
    वापस -1;
}

#अगर_घोषित NEED_BUILD_GOT
ST_FUNC अचिन्हित create_plt_entry(TCCState *s1, अचिन्हित got_offset, काष्ठा sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    पूर्णांक modrm;
    अचिन्हित plt_offset, relofs;

    /* on i386 if we build a DLL, we add a %ebx offset */
    अगर (s1->output_type & TCC_OUTPUT_DYN)
        modrm = 0xa3;
    अन्यथा
        modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    अगर (plt->तथ्य_offset == 0) {
        p = section_ptr_add(plt, 16);
        p[0] = 0xff; /* pushl got + PTR_SIZE */
        p[1] = modrm + 0x10;
        write32le(p + 2, PTR_आकार);
        p[6] = 0xff; /* jmp *(got + PTR_SIZE * 2) */
        p[7] = modrm;
        write32le(p + 8, PTR_आकार * 2);
    }
    plt_offset = plt->तथ्य_offset;

    /* The PLT slot refers to the relocation entry it needs via offset.
       The reloc entry is created below, so its offset is the current
       data_offset */
    relofs = s1->plt->reloc ? s1->plt->reloc->तथ्य_offset : 0;

    /* Jump to GOT entry where ld.so initially put the address of ip + 4 */
    p = section_ptr_add(plt, 16);
    p[0] = 0xff; /* jmp *(got + x) */
    p[1] = modrm;
    write32le(p + 2, got_offset);
    p[6] = 0x68; /* push $xxx */
    write32le(p + 7, relofs - माप (ElfW_Rel));
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->तथ्य_offset));
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

    अगर (!(s1->output_type & TCC_OUTPUT_DYN) && p < p_end) {
        add32le(p + 2, s1->got->sh_addr);
        add32le(p + 8, s1->got->sh_addr);
        p += 16;
        जबतक (p < p_end) {
            add32le(p + 2, s1->got->sh_addr);
            p += 16;
        }
    }

    अगर (s1->plt->reloc) {
        ElfW_Rel *rel;
        पूर्णांक x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->तथ्य;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_offset, x);
            x += 16;
        }
    }
}
#पूर्ण_अगर
#पूर्ण_अगर

ST_FUNC व्योम relocate(TCCState *s1, ElfW_Rel *rel, पूर्णांक type, अचिन्हित अक्षर *ptr, addr_t addr, addr_t val)
{
    पूर्णांक sym_सूचकांक, esym_सूचकांक;

    sym_सूचकांक = ELFW(R_SYM)(rel->r_info);

    चयन (type) {
        हाल R_386_32:
            अगर (s1->output_type & TCC_OUTPUT_DYN) {
                esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
                qrel->r_offset = rel->r_offset;
                अगर (esym_सूचकांक) {
                    qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_386_32);
                    qrel++;
                    वापस;
                } अन्यथा {
                    qrel->r_info = ELFW(R_INFO)(0, R_386_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            वापस;
        हाल R_386_PC32:
            अगर (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
                अगर (esym_सूचकांक) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_386_PC32);
                    qrel++;
                    वापस;
                }
            }
            add32le(ptr, val - addr);
            वापस;
        हाल R_386_PLT32:
            add32le(ptr, val - addr);
            वापस;
        हाल R_386_GLOB_DAT:
        हाल R_386_JMP_SLOT:
            write32le(ptr, val);
            वापस;
        हाल R_386_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            वापस;
        हाल R_386_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            वापस;
        हाल R_386_GOT32:
        हाल R_386_GOT32X:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_सूचकांक, 0)->got_offset);
            वापस;
        हाल R_386_16:
            अगर (s1->output_format != TCC_OUTPUT_FORMAT_द्विआधारी) {
            output_file:
                tcc_error_noabort("can only produce 16-bit binary files");
            }
            write16le(ptr, read16le(ptr) + val);
            वापस;
        हाल R_386_PC16:
            अगर (s1->output_format != TCC_OUTPUT_FORMAT_द्विआधारी)
                जाओ output_file;
            write16le(ptr, read16le(ptr) + val - addr);
            वापस;
        हाल R_386_RELATIVE:
#अगर_घोषित TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#पूर्ण_अगर
            /* do nothing */
            वापस;
        हाल R_386_COPY:
            /* This relocation must copy initialized data from the library
            to the program .bss segment. Currently made like for ARM
            (to remove noise of default case). Is this true?
            */
            वापस;
        हाल R_386_TLS_GD:
            {
                अटल स्थिर अचिन्हित अक्षर expect[] = {
                    /* lea 0(,%ebx,1),%eax */
                    0x8d, 0x04, 0x1d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                अटल स्थिर अचिन्हित अक्षर replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* sub 0,%eax */
                    0x81, 0xe8, 0x00, 0x00, 0x00, 0x00 };

                अगर (स_भेद (ptr-3, expect, माप(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    स_नकल(ptr-3, replace, माप(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_मूल्य - sec->sh_addr - sec->तथ्य_offset;
                    add32le(ptr + 5, -x);
                }
                अन्यथा
                    tcc_error_noabort("unexpected R_386_TLS_GD pattern");
            }
            वापस;
        हाल R_386_TLS_LDM:
            {
                अटल स्थिर अचिन्हित अक्षर expect[] = {
                    /* lea 0(%ebx),%eax */
                    0x8d, 0x83, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                अटल स्थिर अचिन्हित अक्षर replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* nop */
                    0x90,
                    /* lea 0(%esi,%eiz,1),%esi */
                    0x8d, 0x74, 0x26, 0x00 };

                अगर (स_भेद (ptr-2, expect, माप(expect)) == 0) {
                    स_नकल(ptr-2, replace, माप(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                }
                अन्यथा
                    tcc_error_noabort("unexpected R_386_TLS_LDM pattern");
            }
            वापस;
        हाल R_386_TLS_LDO_32:
            {
                ElfW(Sym) *sym;
                Section *sec;
                int32_t x;

                sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
                sec = s1->sections[sym->st_shndx];
                x = val - sec->sh_addr - sec->तथ्य_offset;
                add32le(ptr, x);
            }
            वापस;
        हाल R_386_TLS_LE:
            {
                int32_t x;
                अगर (s1->tls_end) {
                    x = val - s1->tls_end;
                } अन्यथा {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->तथ्य_offset;
                }
                add32le(ptr, x);
            }
            वापस;
        हाल R_386_NONE:
            वापस;
        शेष:
            ख_लिखो(मानक_त्रुटि,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (अचिन्हित)addr, ptr, (अचिन्हित)val);
            वापस;
    }
}

#पूर्ण_अगर /* !TARGET_DEFS_ONLY */
