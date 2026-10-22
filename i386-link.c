#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_386

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_386_32
#define R_DATA_PTR  R_386_32
#define R_JMP_SLOT  R_386_JMP_SLOT
#define R_GLOB_DAT  R_386_GLOB_DAT
#define R_COPY      R_386_COPY
#define R_RELATIVE  R_386_RELATIVE

#define R_അക്കം       R_386_അക്കം

#define ELF_START_ADDR 0x08048000
#define ELF_PAGE_SIZE  0x1000

#എങ്കിൽ defined CONFIG_TCC_PIC
#define PCRELATIVE_DLLPLT 1
#അല്ലെങ്കിൽ
#define PCRELATIVE_DLLPLT 0
#endif
#define RELOCATE_DLLPLT 1

#അല്ലെങ്കിൽ /* !TARGET_DEFS_ONLY */

#അന്തര്ഭാവ "tcc.h"

#ifdef NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC പൂർണ്ണസംഖ്യ code_reloc (പൂർണ്ണസംഖ്യ reloc_type)
{
    തിരഞ്ഞെടുപ്പ് (reloc_type) {
	അവസ്ഥ R_386_RELATIVE:
	അവസ്ഥ R_386_16:
        അവസ്ഥ R_386_32:
	അവസ്ഥ R_386_GOTPC:
	അവസ്ഥ R_386_GOTOFF:
	അവസ്ഥ R_386_GOT32:
	അവസ്ഥ R_386_GOT32X:
	അവസ്ഥ R_386_GLOB_DAT:
	അവസ്ഥ R_386_COPY:
	അവസ്ഥ R_386_TLS_GD:
	അവസ്ഥ R_386_TLS_LDM:
	അവസ്ഥ R_386_TLS_LDO_32:
	അവസ്ഥ R_386_TLS_LE:
            തിരികെ 0;

	അവസ്ഥ R_386_PC16:
	അവസ്ഥ R_386_PC32:
	അവസ്ഥ R_386_PLT32:
	അവസ്ഥ R_386_JMP_SLOT:
            തിരികെ 1;
    }
    തിരികെ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC പൂർണ്ണസംഖ്യ gotplt_entry_type (പൂർണ്ണസംഖ്യ reloc_type)
{
    തിരഞ്ഞെടുപ്പ് (reloc_type) {
	അവസ്ഥ R_386_RELATIVE:
	അവസ്ഥ R_386_16:
	അവസ്ഥ R_386_GLOB_DAT:
	അവസ്ഥ R_386_JMP_SLOT:
	അവസ്ഥ R_386_COPY:
            തിരികെ NO_GOTPLT_ENTRY;

        അവസ്ഥ R_386_32:
	    /* This relocations shouldn't normally need GOT or PLT
	       slots if it weren't for simplicity in the code generator.
	       See our caller for comments.  */
            തിരികെ AUTO_GOTPLT_ENTRY;

	അവസ്ഥ R_386_PC16:
	അവസ്ഥ R_386_PC32:
            തിരികെ AUTO_GOTPLT_ENTRY;

	അവസ്ഥ R_386_GOTPC:
	അവസ്ഥ R_386_GOTOFF:
            തിരികെ BUILD_GOT_ONLY;

	അവസ്ഥ R_386_GOT32:
	അവസ്ഥ R_386_GOT32X:
	അവസ്ഥ R_386_PLT32:
	അവസ്ഥ R_386_TLS_GD:
	അവസ്ഥ R_386_TLS_LDM:
	അവസ്ഥ R_386_TLS_LDO_32:
	അവസ്ഥ R_386_TLS_LE:
            തിരികെ ALWAYS_GOTPLT_ENTRY;
    }
    തിരികെ -1;
}

#ifdef NEED_BUILD_GOT
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, ഘടന sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    പൂർണ്ണസംഖ്യ modrm;
    unsigned plt_offset, relofs;

    /* on i386 if we build a DLL, we add a %ebx offset */
    എങ്കിൽ (s1->output_type & TCC_OUTPUT_DYN)
        modrm = 0xa3;
    അല്ലെങ്കിൽ
        modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    എങ്കിൽ (plt->data_offset == 0) {
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
    write32le(p + 7, relofs - വലുപ്പം (ElfW_Rel));
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->data_offset));
    തിരികെ plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC ശൂന്യം relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    എങ്കിൽ (!s1->plt)
      തിരികെ;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    എങ്കിൽ (!(s1->output_type & TCC_OUTPUT_DYN) && p < p_end) {
        add32le(p + 2, s1->got->sh_addr);
        add32le(p + 8, s1->got->sh_addr);
        p += 16;
        ആകുമ്പോൾ (p < p_end) {
            add32le(p + 2, s1->got->sh_addr);
            p += 16;
        }
    }

    എങ്കിൽ (s1->plt->reloc) {
        ElfW_Rel *rel;
        പൂർണ്ണസംഖ്യ x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->data;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_offset, x);
            x += 16;
        }
    }
}
#endif
#endif

ST_FUNC ശൂന്യം relocate(TCCState *s1, ElfW_Rel *rel, പൂർണ്ണസംഖ്യ type, unsigned അക്ഷരം *ptr, addr_t addr, addr_t val)
{
    പൂർണ്ണസംഖ്യ sym_index, esym_index;

    sym_index = ELFW(R_SYM)(rel->r_info);

    തിരഞ്ഞെടുപ്പ് (type) {
        അവസ്ഥ R_386_32:
            എങ്കിൽ (s1->output_type & TCC_OUTPUT_DYN) {
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                qrel->r_offset = rel->r_offset;
                എങ്കിൽ (esym_index) {
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_386_32);
                    qrel++;
                    തിരികെ;
                } അല്ലെങ്കിൽ {
                    qrel->r_info = ELFW(R_INFO)(0, R_386_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            തിരികെ;
        അവസ്ഥ R_386_PC32:
            എങ്കിൽ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                എങ്കിൽ (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_386_PC32);
                    qrel++;
                    തിരികെ;
                }
            }
            add32le(ptr, val - addr);
            തിരികെ;
        അവസ്ഥ R_386_PLT32:
            add32le(ptr, val - addr);
            തിരികെ;
        അവസ്ഥ R_386_GLOB_DAT:
        അവസ്ഥ R_386_JMP_SLOT:
            write32le(ptr, val);
            തിരികെ;
        അവസ്ഥ R_386_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            തിരികെ;
        അവസ്ഥ R_386_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            തിരികെ;
        അവസ്ഥ R_386_GOT32:
        അവസ്ഥ R_386_GOT32X:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            തിരികെ;
        അവസ്ഥ R_386_16:
            എങ്കിൽ (s1->output_format != TCC_OUTPUT_FORMAT_ദ്വിമാന) {
            output_file:
                tcc_error_noabort("can only produce 16-bit binary files");
            }
            write16le(ptr, read16le(ptr) + val);
            തിരികെ;
        അവസ്ഥ R_386_PC16:
            എങ്കിൽ (s1->output_format != TCC_OUTPUT_FORMAT_ദ്വിമാന)
                പോകുക output_file;
            write16le(ptr, read16le(ptr) + val - addr);
            തിരികെ;
        അവസ്ഥ R_386_RELATIVE:
#ifdef TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            തിരികെ;
        അവസ്ഥ R_386_COPY:
            /* This relocation must copy initialized data from the library
            to the program .bss segment. Currently made like for ARM
            (to remove noise of default case). Is this true?
            */
            തിരികെ;
        അവസ്ഥ R_386_TLS_GD:
            {
                സ്ഥിതം സ്ഥിരം unsigned അക്ഷരം expect[] = {
                    /* lea 0(,%ebx,1),%eax */
                    0x8d, 0x04, 0x1d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                സ്ഥിതം സ്ഥിരം unsigned അക്ഷരം replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* sub 0,%eax */
                    0x81, 0xe8, 0x00, 0x00, 0x00, 0x00 };

                എങ്കിൽ (memcmp (ptr-3, expect, വലുപ്പം(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    memcpy(ptr-3, replace, വലുപ്പം(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_മൂല്യം - sec->sh_addr - sec->data_offset;
                    add32le(ptr + 5, -x);
                }
                അല്ലെങ്കിൽ
                    tcc_error_noabort("unexpected R_386_TLS_GD pattern");
            }
            തിരികെ;
        അവസ്ഥ R_386_TLS_LDM:
            {
                സ്ഥിതം സ്ഥിരം unsigned അക്ഷരം expect[] = {
                    /* lea 0(%ebx),%eax */
                    0x8d, 0x83, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                സ്ഥിതം സ്ഥിരം unsigned അക്ഷരം replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* nop */
                    0x90,
                    /* lea 0(%esi,%eiz,1),%esi */
                    0x8d, 0x74, 0x26, 0x00 };

                എങ്കിൽ (memcmp (ptr-2, expect, വലുപ്പം(expect)) == 0) {
                    memcpy(ptr-2, replace, വലുപ്പം(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                }
                അല്ലെങ്കിൽ
                    tcc_error_noabort("unexpected R_386_TLS_LDM pattern");
            }
            തിരികെ;
        അവസ്ഥ R_386_TLS_LDO_32:
            {
                ElfW(Sym) *sym;
                Section *sec;
                int32_t x;

                sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                sec = s1->sections[sym->st_shndx];
                x = val - sec->sh_addr - sec->data_offset;
                add32le(ptr, x);
            }
            തിരികെ;
        അവസ്ഥ R_386_TLS_LE:
            {
                int32_t x;
                എങ്കിൽ (s1->tls_end) {
                    x = val - s1->tls_end;
                } അല്ലെങ്കിൽ {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->data_offset;
                }
                add32le(ptr, x);
            }
            തിരികെ;
        അവസ്ഥ R_386_NONE:
            തിരികെ;
        സ്ഥിരസ്ഥിതി:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (unsigned)addr, ptr, (unsigned)val);
            തിരികെ;
    }
}

#endif /* !TARGET_DEFS_ONLY */
