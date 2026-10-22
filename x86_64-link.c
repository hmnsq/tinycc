#अगर_घोषित TARGET_DEFS_ONLY

#घोषणा EM_TCC_TARGET EM_X86_64

/* relocation type for 32 bit data relocation */
#घोषणा R_तथ्य_32   R_X86_64_32S
#घोषणा R_तथ्य_PTR  R_X86_64_64
#घोषणा R_JMP_SLOT  R_X86_64_JUMP_SLOT
#घोषणा R_GLOB_DAT  R_X86_64_GLOB_DAT
#घोषणा R_COPY      R_X86_64_COPY
#घोषणा R_RELATIVE  R_X86_64_RELATIVE

#घोषणा R_अंक       R_X86_64_अंक

#घोषणा ELF_START_ADDR 0x400000
#घोषणा ELF_PAGE_आकार  0x1000

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
        हाल R_X86_64_32:
        हाल R_X86_64_32S:
        हाल R_X86_64_64:
        हाल R_X86_64_GOTPC32:
        हाल R_X86_64_GOTPC64:
        हाल R_X86_64_GOTPCREL:
        हाल R_X86_64_GOTPCRELX:
        हाल R_X86_64_REX_GOTPCRELX:
        हाल R_X86_64_GOTTPOFF:
        हाल R_X86_64_GOT32:
        हाल R_X86_64_GOT64:
        हाल R_X86_64_GLOB_DAT:
        हाल R_X86_64_COPY:
        हाल R_X86_64_RELATIVE:
        हाल R_X86_64_GOTOFF64:
        हाल R_X86_64_TLSGD:
        हाल R_X86_64_TLSLD:
        हाल R_X86_64_DTPOFF32:
        हाल R_X86_64_TPOFF32:
        हाल R_X86_64_DTPOFF64:
        हाल R_X86_64_TPOFF64:
            वापस 0;

        हाल R_X86_64_PC32:
        हाल R_X86_64_PC64:
        हाल R_X86_64_PLT32:
        हाल R_X86_64_PLTOFF64:
        हाल R_X86_64_JUMP_SLOT:
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
        हाल R_X86_64_GLOB_DAT:
        हाल R_X86_64_JUMP_SLOT:
        हाल R_X86_64_COPY:
        हाल R_X86_64_RELATIVE:
            वापस NO_GOTPLT_ENTRY;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        हाल R_X86_64_32:
        हाल R_X86_64_32S:
        हाल R_X86_64_64:
        हाल R_X86_64_PC32:
        हाल R_X86_64_PC64:
            वापस AUTO_GOTPLT_ENTRY;

        हाल R_X86_64_GOTTPOFF:
            वापस BUILD_GOT_ONLY;

        हाल R_X86_64_GOT32:
        हाल R_X86_64_GOT64:
        हाल R_X86_64_GOTPC32:
        हाल R_X86_64_GOTPC64:
        हाल R_X86_64_GOTOFF64:
        हाल R_X86_64_GOTPCREL:
        हाल R_X86_64_GOTPCRELX:
        हाल R_X86_64_TLSGD:
        हाल R_X86_64_TLSLD:
        हाल R_X86_64_DTPOFF32:
        हाल R_X86_64_DTPOFF64:
        हाल R_X86_64_REX_GOTPCRELX:
        हाल R_X86_64_PLT32:
        हाल R_X86_64_PLTOFF64:
            वापस ALWAYS_GOTPLT_ENTRY;

        हाल R_X86_64_TPOFF32:
        हाल R_X86_64_TPOFF64:
            वापस NO_GOTPLT_ENTRY;
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
    /* On x86-64, the relocation is referred to by _index_ */
    write32le(p + 7, relofs / माप (ElfW_Rel) - 1);
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

    अगर (p < p_end) {
        पूर्णांक x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        जबतक (p < p_end) {
            add32le(p + 2, x + (s1->plt->तथ्य - p));
            p += 16;
        }
    }

    अगर (s1->plt->reloc) {
        ElfW_Rel *rel;
        पूर्णांक x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->तथ्य;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_offset, x);
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
        हाल R_X86_64_64:
            अगर (s1->output_type & TCC_OUTPUT_DYN) {
                esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
                qrel->r_offset = rel->r_offset;
                अगर (esym_सूचकांक) {
                    qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_X86_64_64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    अवरोध;
                } अन्यथा {
                    qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            अवरोध;
        हाल R_X86_64_32:
        हाल R_X86_64_32S:
            अगर (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_offset = rel->r_offset;
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (पूर्णांक)read32le(ptr) + val;
                qrel++;
            }
            अगर ((type == R_X86_64_32 ? val != (अचिन्हित)val : val != (पूर्णांक)val)
                /* ignore relocation check for stab section */
                && (stab_section == शून्य ||
                    addr < stab_section->sh_addr ||
                    addr >= (stab_section->sh_addr + stab_section->तथ्य_offset))) {
                tcc_error_noabort("relocation 'R_X86_64_32[S]' out of range");
            }
            add32le(ptr, val);
            अवरोध;

        हाल R_X86_64_PC32:
            अगर (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
                अगर (esym_सूचकांक) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_X86_64_PC32);
                    /* Use sign extension! */
                    qrel->r_addend = (पूर्णांक)read32le(ptr) + rel->r_addend;
                    qrel++;
                    अवरोध;
                }
            }
            जाओ plt32pc32;

        हाल R_X86_64_PLT32:
            /* fallthrough: val already holds the PLT slot address */

        plt32pc32:
        {
            दीर्घ दीर्घ diff;
            diff = (दीर्घ दीर्घ)val - addr;
            अगर (diff < -2147483648LL || diff > 2147483647LL) {
#अगर_घोषित TCC_TARGET_PE
              /* ignore overflow with undefined weak symbols */
              अगर (((ElfW(Sym)*)symtab_section->तथ्य)[sym_सूचकांक].st_shndx != SHN_UNDEF)
#पूर्ण_अगर
                tcc_error_noabort("relocation '%d' out of range", type);
            }
            add32le(ptr, diff);
        }
            अवरोध;

        हाल R_X86_64_COPY:
	    अवरोध;

        हाल R_X86_64_PLTOFF64:
            add64le(ptr, val - s1->got->sh_addr + rel->r_addend);
            अवरोध;

        हाल R_X86_64_PC64:
            अगर (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_सूचकांक = get_sym_attr(s1, sym_सूचकांक, 0)->dyn_सूचकांक;
                अगर (esym_सूचकांक) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_सूचकांक, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    अवरोध;
                }
            }
            add64le(ptr, val - addr);
            अवरोध;

        हाल R_X86_64_GLOB_DAT:
        हाल R_X86_64_JUMP_SLOT:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            अवरोध;
        हाल R_X86_64_GOTPCREL:
        हाल R_X86_64_GOTPCRELX:
        हाल R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         get_sym_attr(s1, sym_सूचकांक, 0)->got_offset - 4);
            अवरोध;
        हाल R_X86_64_GOTPC32:
            add32le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            अवरोध;
        हाल R_X86_64_GOTPC64:
            add64le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            अवरोध;
        हाल R_X86_64_GOTTPOFF:
            add32le(ptr, val - s1->got->sh_addr);
            अवरोध;
        हाल R_X86_64_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_सूचकांक, 0)->got_offset);
            अवरोध;
        हाल R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, get_sym_attr(s1, sym_सूचकांक, 0)->got_offset);
            अवरोध;
        हाल R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            अवरोध;
        हाल R_X86_64_TLSGD:
            {
                अटल स्थिर अचिन्हित अक्षर expect[] = {
                    /* .byte 0x66; lea 0(%rip),%rdi */
                    0x66, 0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* .word 0x6666; rex64; call __tls_get_addr@PLT */
                    0x66, 0x66, 0x48, 0xe8, 0x00, 0x00, 0x00, 0x00 };
                अटल स्थिर अचिन्हित अक्षर replace[] = {
                    /* mov %fs:0,%rax */
                    0x64, 0x48, 0x8b, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
                    /* lea -4(%rax),%rax */
                    0x48, 0x8d, 0x80, 0x00, 0x00, 0x00, 0x00 };

                अगर (स_भेद (ptr-4, expect, माप(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    स_नकल(ptr-4, replace, माप(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_मूल्य - sec->sh_addr - sec->तथ्य_offset;
                    add32le(ptr + 8, x);
                }
                अन्यथा
                    tcc_error_noabort("unexpected R_X86_64_TLSGD pattern");
            }
            अवरोध;
        हाल R_X86_64_TLSLD:
            {
                अटल स्थिर अचिन्हित अक्षर expect[] = {
                    /* lea 0(%rip),%rdi */
                    0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0x00, 0x00, 0x00, 0x00 };
                अटल स्थिर अचिन्हित अक्षर replace[] = {
                    /* data16 data16 data16 mov %fs:0,%rax */
                    0x66, 0x66, 0x66, 0x64, 0x48, 0x8b, 0x04, 0x25,
                    0x00, 0x00, 0x00, 0x00 };

                अगर (स_भेद (ptr-3, expect, माप(expect)) == 0) {
                    स_नकल(ptr-3, replace, माप(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                }
                अन्यथा
                    tcc_error_noabort("unexpected R_X86_64_TLSLD pattern");
            }
            अवरोध;

        हाल R_X86_64_DTPOFF32:
        हाल R_X86_64_TPOFF32:
        हाल R_X86_64_DTPOFF64:
        हाल R_X86_64_TPOFF64:
            {
                int32_t x;
                अगर (s1->tls_end) {
                    x = val - s1->tls_end;
                } अन्यथा {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->तथ्य_offset;
                }
                चयन (type) {
                हाल R_X86_64_DTPOFF64:
                हाल R_X86_64_TPOFF64:
                    add64le(ptr, x);
                    अवरोध;
                शेष:
                    add32le(ptr, x);
                    अवरोध;
                }
            }
            अवरोध;
        हाल R_X86_64_NONE:
            अवरोध;
        हाल R_X86_64_RELATIVE:
#अगर_घोषित TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#पूर्ण_अगर
            /* do nothing */
            अवरोध;
        शेष:
            ख_लिखो(मानक_त्रुटि,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (अचिन्हित)addr, ptr, (अचिन्हित)val);
            अवरोध;
    }
}

#पूर्ण_अगर /* !TARGET_DEFS_ONLY */
