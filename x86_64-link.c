#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_X86_64

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_X86_64_32S
#define R_DATA_PTR  R_X86_64_64
#define R_JMP_SLOT  R_X86_64_JUMP_SLOT
#define R_GLOB_DAT  R_X86_64_GLOB_DAT
#define R_COPY      R_X86_64_COPY
#define R_RELATIVE  R_X86_64_RELATIVE

#define R_अंक       R_X86_64_अंक

#define ELF_START_ADDR 0x400000
#define ELF_PAGE_SIZE  0x1000

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
        स्थिती R_X86_64_32:
        स्थिती R_X86_64_32S:
        स्थिती R_X86_64_64:
        स्थिती R_X86_64_GOTPC32:
        स्थिती R_X86_64_GOTPC64:
        स्थिती R_X86_64_GOTPCREL:
        स्थिती R_X86_64_GOTPCRELX:
        स्थिती R_X86_64_REX_GOTPCRELX:
        स्थिती R_X86_64_GOTTPOFF:
        स्थिती R_X86_64_GOT32:
        स्थिती R_X86_64_GOT64:
        स्थिती R_X86_64_GLOB_DAT:
        स्थिती R_X86_64_COPY:
        स्थिती R_X86_64_RELATIVE:
        स्थिती R_X86_64_GOTOFF64:
        स्थिती R_X86_64_TLSGD:
        स्थिती R_X86_64_TLSLD:
        स्थिती R_X86_64_DTPOFF32:
        स्थिती R_X86_64_TPOFF32:
        स्थिती R_X86_64_DTPOFF64:
        स्थिती R_X86_64_TPOFF64:
            परत 0;

        स्थिती R_X86_64_PC32:
        स्थिती R_X86_64_PC64:
        स्थिती R_X86_64_PLT32:
        स्थिती R_X86_64_PLTOFF64:
        स्थिती R_X86_64_JUMP_SLOT:
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
        स्थिती R_X86_64_GLOB_DAT:
        स्थिती R_X86_64_JUMP_SLOT:
        स्थिती R_X86_64_COPY:
        स्थिती R_X86_64_RELATIVE:
            परत NO_GOTPLT_ENTRY;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        स्थिती R_X86_64_32:
        स्थिती R_X86_64_32S:
        स्थिती R_X86_64_64:
        स्थिती R_X86_64_PC32:
        स्थिती R_X86_64_PC64:
            परत AUTO_GOTPLT_ENTRY;

        स्थिती R_X86_64_GOTTPOFF:
            परत BUILD_GOT_ONLY;

        स्थिती R_X86_64_GOT32:
        स्थिती R_X86_64_GOT64:
        स्थिती R_X86_64_GOTPC32:
        स्थिती R_X86_64_GOTPC64:
        स्थिती R_X86_64_GOTOFF64:
        स्थिती R_X86_64_GOTPCREL:
        स्थिती R_X86_64_GOTPCRELX:
        स्थिती R_X86_64_TLSGD:
        स्थिती R_X86_64_TLSLD:
        स्थिती R_X86_64_DTPOFF32:
        स्थिती R_X86_64_DTPOFF64:
        स्थिती R_X86_64_REX_GOTPCRELX:
        स्थिती R_X86_64_PLT32:
        स्थिती R_X86_64_PLTOFF64:
            परत ALWAYS_GOTPLT_ENTRY;

        स्थिती R_X86_64_TPOFF32:
        स्थिती R_X86_64_TPOFF64:
            परत NO_GOTPLT_ENTRY;
    }

    परत -1;
}

#ifdef NEED_BUILD_GOT
ST_FUNC अचिन्हित create_plt_entry(TCCState *s1, अचिन्हित got_offset, संरचना sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    पूर्णांक modrm;
    अचिन्हित plt_offset, relofs;

    modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    जर (plt->data_offset == 0) {
        p = section_ptr_add(plt, 16);
        p[0] = 0xff; /* pushl got + PTR_SIZE */
        p[1] = modrm + 0x10;
        write32le(p + 2, PTR_SIZE);
        p[6] = 0xff; /* jmp *(got + PTR_SIZE * 2) */
        p[7] = modrm;
        write32le(p + 8, PTR_SIZE * 2);
    }
    plt_offset = plt->data_offset;

    /* The PLT slot refers to the relocation entry it needs via offset.
       The reloc entry is created below, so its offset is the current
       data_offset */
    relofs = s1->plt->reloc ? s1->plt->reloc->data_offset : 0;

    /* Jump to GOT entry where ld.so initially put the address of ip + 4 */
    p = section_ptr_add(plt, 16);
    p[0] = 0xff; /* jmp *(got + x) */
    p[1] = modrm;
    write32le(p + 2, got_offset);
    p[6] = 0x68; /* push $xxx */
    /* On x86-64, the relocation is referred to by _index_ */
    write32le(p + 7, relofs / आकार (ElfW_Rel) - 1);
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->data_offset));
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
        पूर्णांक x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        पर्यंत (p < p_end) {
            add32le(p + 2, x + (s1->plt->data - p));
            p += 16;
        }
    }

    जर (s1->plt->reloc) {
        ElfW_Rel *rel;
        पूर्णांक x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->data;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_offset, x);
            x += 16;
        }
    }
}
#endif
#endif

ST_FUNC शून्य relocate(TCCState *s1, ElfW_Rel *rel, पूर्णांक type, अचिन्हित अक्षर *ptr, addr_t addr, addr_t val)
{
    पूर्णांक sym_index, esym_index;

    sym_index = ELFW(R_SYM)(rel->r_info);

    निवड (type) {
        स्थिती R_X86_64_64:
            जर (s1->output_type & TCC_OUTPUT_DYN) {
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                qrel->r_offset = rel->r_offset;
                जर (esym_index) {
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    थांबा;
                } अन्यथा {
                    qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            थांबा;
        स्थिती R_X86_64_32:
        स्थिती R_X86_64_32S:
            जर (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_offset = rel->r_offset;
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (पूर्णांक)read32le(ptr) + val;
                qrel++;
            }
            जर ((type == R_X86_64_32 ? val != (अचिन्हित)val : val != (पूर्णांक)val)
                /* ignore relocation check for stab section */
                && (stab_section == रिक्त ||
                    addr < stab_section->sh_addr ||
                    addr >= (stab_section->sh_addr + stab_section->data_offset))) {
                tcc_error_noabort("relocation 'R_X86_64_32[S]' out of range");
            }
            add32le(ptr, val);
            थांबा;

        स्थिती R_X86_64_PC32:
            जर (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                जर (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_PC32);
                    /* Use sign extension! */
                    qrel->r_addend = (पूर्णांक)read32le(ptr) + rel->r_addend;
                    qrel++;
                    थांबा;
                }
            }
            जा plt32pc32;

        स्थिती R_X86_64_PLT32:
            /* fallthrough: val already holds the PLT slot address */

        plt32pc32:
        {
            दीर्घ दीर्घ diff;
            diff = (दीर्घ दीर्घ)val - addr;
            जर (diff < -2147483648LL || diff > 2147483647LL) {
#ifdef TCC_TARGET_PE
              /* ignore overflow with undefined weak symbols */
              जर (((ElfW(Sym)*)symtab_section->data)[sym_index].st_shndx != SHN_UNDEF)
#endif
                tcc_error_noabort("relocation '%d' out of range", type);
            }
            add32le(ptr, diff);
        }
            थांबा;

        स्थिती R_X86_64_COPY:
	    थांबा;

        स्थिती R_X86_64_PLTOFF64:
            add64le(ptr, val - s1->got->sh_addr + rel->r_addend);
            थांबा;

        स्थिती R_X86_64_PC64:
            जर (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                जर (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    थांबा;
                }
            }
            add64le(ptr, val - addr);
            थांबा;

        स्थिती R_X86_64_GLOB_DAT:
        स्थिती R_X86_64_JUMP_SLOT:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            थांबा;
        स्थिती R_X86_64_GOTPCREL:
        स्थिती R_X86_64_GOTPCRELX:
        स्थिती R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         get_sym_attr(s1, sym_index, 0)->got_offset - 4);
            थांबा;
        स्थिती R_X86_64_GOTPC32:
            add32le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            थांबा;
        स्थिती R_X86_64_GOTPC64:
            add64le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            थांबा;
        स्थिती R_X86_64_GOTTPOFF:
            add32le(ptr, val - s1->got->sh_addr);
            थांबा;
        स्थिती R_X86_64_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            थांबा;
        स्थिती R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            थांबा;
        स्थिती R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            थांबा;
        स्थिती R_X86_64_TLSGD:
            {
                स्थिर स्थिरांक अचिन्हित अक्षर expect[] = {
                    /* .byte 0x66; lea 0(%rip),%rdi */
                    0x66, 0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* .word 0x6666; rex64; call __tls_get_addr@PLT */
                    0x66, 0x66, 0x48, 0xe8, 0x00, 0x00, 0x00, 0x00 };
                स्थिर स्थिरांक अचिन्हित अक्षर replace[] = {
                    /* mov %fs:0,%rax */
                    0x64, 0x48, 0x8b, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
                    /* lea -4(%rax),%rax */
                    0x48, 0x8d, 0x80, 0x00, 0x00, 0x00, 0x00 };

                जर (स_भेद (ptr-4, expect, आकार(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    स_नकल(ptr-4, replace, आकार(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_मूल्य - sec->sh_addr - sec->data_offset;
                    add32le(ptr + 8, x);
                }
                अन्यथा
                    tcc_error_noabort("unexpected R_X86_64_TLSGD pattern");
            }
            थांबा;
        स्थिती R_X86_64_TLSLD:
            {
                स्थिर स्थिरांक अचिन्हित अक्षर expect[] = {
                    /* lea 0(%rip),%rdi */
                    0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0x00, 0x00, 0x00, 0x00 };
                स्थिर स्थिरांक अचिन्हित अक्षर replace[] = {
                    /* data16 data16 data16 mov %fs:0,%rax */
                    0x66, 0x66, 0x66, 0x64, 0x48, 0x8b, 0x04, 0x25,
                    0x00, 0x00, 0x00, 0x00 };

                जर (स_भेद (ptr-3, expect, आकार(expect)) == 0) {
                    स_नकल(ptr-3, replace, आकार(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                }
                अन्यथा
                    tcc_error_noabort("unexpected R_X86_64_TLSLD pattern");
            }
            थांबा;

        स्थिती R_X86_64_DTPOFF32:
        स्थिती R_X86_64_TPOFF32:
        स्थिती R_X86_64_DTPOFF64:
        स्थिती R_X86_64_TPOFF64:
            {
                int32_t x;
                जर (s1->tls_end) {
                    x = val - s1->tls_end;
                } अन्यथा {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->data_offset;
                }
                निवड (type) {
                स्थिती R_X86_64_DTPOFF64:
                स्थिती R_X86_64_TPOFF64:
                    add64le(ptr, x);
                    थांबा;
                पूर्वनिर्धारित:
                    add32le(ptr, x);
                    थांबा;
                }
            }
            थांबा;
        स्थिती R_X86_64_NONE:
            थांबा;
        स्थिती R_X86_64_RELATIVE:
#ifdef TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            थांबा;
        पूर्वनिर्धारित:
            ख_लिखो(मानक_त्रुटि,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (अचिन्हित)addr, ptr, (अचिन्हित)val);
            थांबा;
    }
}

#endif /* !TARGET_DEFS_ONLY */
