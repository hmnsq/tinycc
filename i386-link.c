#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_386

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_386_32
#define R_DATA_PTR  R_386_32
#define R_JMP_SLOT  R_386_JMP_SLOT
#define R_GLOB_DAT  R_386_GLOB_DAT
#define R_COPY      R_386_COPY
#define R_RELATIVE  R_386_RELATIVE

#define R_ଅଙ୍କ       R_386_ଅଙ୍କ

#define ELF_START_ADDR 0x08048000
#define ELF_PAGE_SIZE  0x1000

#ଯଦି defined CONFIG_TCC_PIC
#define PCRELATIVE_DLLPLT 1
#ଅନ୍ୟଥା
#define PCRELATIVE_DLLPLT 0
#endif
#define RELOCATE_DLLPLT 1

#ଅନ୍ୟଥା /* !TARGET_DEFS_ONLY */

#ଅନ୍ତର୍ଭାଵ "tcc.h"

#ifdef NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା code_reloc (ପୂର୍ଣ୍ଣସଂଖ୍ୟା reloc_type)
{
    ବାଛ (reloc_type) {
	ସ୍ଥିତି R_386_RELATIVE:
	ସ୍ଥିତି R_386_16:
        ସ୍ଥିତି R_386_32:
	ସ୍ଥିତି R_386_GOTPC:
	ସ୍ଥିତି R_386_GOTOFF:
	ସ୍ଥିତି R_386_GOT32:
	ସ୍ଥିତି R_386_GOT32X:
	ସ୍ଥିତି R_386_GLOB_DAT:
	ସ୍ଥିତି R_386_COPY:
	ସ୍ଥିତି R_386_TLS_GD:
	ସ୍ଥିତି R_386_TLS_LDM:
	ସ୍ଥିତି R_386_TLS_LDO_32:
	ସ୍ଥିତି R_386_TLS_LE:
            ଫେରନ୍ତୁ 0;

	ସ୍ଥିତି R_386_PC16:
	ସ୍ଥିତି R_386_PC32:
	ସ୍ଥିତି R_386_PLT32:
	ସ୍ଥିତି R_386_JMP_SLOT:
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
	ସ୍ଥିତି R_386_RELATIVE:
	ସ୍ଥିତି R_386_16:
	ସ୍ଥିତି R_386_GLOB_DAT:
	ସ୍ଥିତି R_386_JMP_SLOT:
	ସ୍ଥିତି R_386_COPY:
            ଫେରନ୍ତୁ NO_GOTPLT_ENTRY;

        ସ୍ଥିତି R_386_32:
	    /* This relocations shouldn't normally need GOT or PLT
	       slots if it weren't for simplicity in the code generator.
	       See our caller for comments.  */
            ଫେରନ୍ତୁ AUTO_GOTPLT_ENTRY;

	ସ୍ଥିତି R_386_PC16:
	ସ୍ଥିତି R_386_PC32:
            ଫେରନ୍ତୁ AUTO_GOTPLT_ENTRY;

	ସ୍ଥିତି R_386_GOTPC:
	ସ୍ଥିତି R_386_GOTOFF:
            ଫେରନ୍ତୁ BUILD_GOT_ONLY;

	ସ୍ଥିତି R_386_GOT32:
	ସ୍ଥିତି R_386_GOT32X:
	ସ୍ଥିତି R_386_PLT32:
	ସ୍ଥିତି R_386_TLS_GD:
	ସ୍ଥିତି R_386_TLS_LDM:
	ସ୍ଥିତି R_386_TLS_LDO_32:
	ସ୍ଥିତି R_386_TLS_LE:
            ଫେରନ୍ତୁ ALWAYS_GOTPLT_ENTRY;
    }
    ଫେରନ୍ତୁ -1;
}

#ifdef NEED_BUILD_GOT
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, ସଂରଚନା sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା modrm;
    unsigned plt_offset, relofs;

    /* on i386 if we build a DLL, we add a %ebx offset */
    ଯଦି (s1->output_type & TCC_OUTPUT_DYN)
        modrm = 0xa3;
    ଅନ୍ୟଥା
        modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    ଯଦି (plt->data_offset == 0) {
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
    write32le(p + 7, relofs - ଆକାର (ElfW_Rel));
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->data_offset));
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

    ଯଦି (!(s1->output_type & TCC_OUTPUT_DYN) && p < p_end) {
        add32le(p + 2, s1->got->sh_addr);
        add32le(p + 8, s1->got->sh_addr);
        p += 16;
        ଯେତେବେଳେ (p < p_end) {
            add32le(p + 2, s1->got->sh_addr);
            p += 16;
        }
    }

    ଯଦି (s1->plt->reloc) {
        ElfW_Rel *rel;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->data;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_offset, x);
            x += 16;
        }
    }
}
#endif
#endif

ST_FUNC ଶୂନ୍ୟ relocate(TCCState *s1, ElfW_Rel *rel, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, unsigned ଅକ୍ଷର *ptr, addr_t addr, addr_t val)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_index, esym_index;

    sym_index = ELFW(R_SYM)(rel->r_info);

    ବାଛ (type) {
        ସ୍ଥିତି R_386_32:
            ଯଦି (s1->output_type & TCC_OUTPUT_DYN) {
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                qrel->r_offset = rel->r_offset;
                ଯଦି (esym_index) {
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_386_32);
                    qrel++;
                    ଫେରନ୍ତୁ;
                } ଅନ୍ୟଥା {
                    qrel->r_info = ELFW(R_INFO)(0, R_386_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_PC32:
            ଯଦି (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                ଯଦି (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_386_PC32);
                    qrel++;
                    ଫେରନ୍ତୁ;
                }
            }
            add32le(ptr, val - addr);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_PLT32:
            add32le(ptr, val - addr);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_GLOB_DAT:
        ସ୍ଥିତି R_386_JMP_SLOT:
            write32le(ptr, val);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_GOT32:
        ସ୍ଥିତି R_386_GOT32X:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_16:
            ଯଦି (s1->output_format != TCC_OUTPUT_FORMAT_ଦ୍ୱିମିକ) {
            output_file:
                tcc_error_noabort("can only produce 16-bit binary files");
            }
            write16le(ptr, read16le(ptr) + val);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_PC16:
            ଯଦି (s1->output_format != TCC_OUTPUT_FORMAT_ଦ୍ୱିମିକ)
                ଯାଅ output_file;
            write16le(ptr, read16le(ptr) + val - addr);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_RELATIVE:
#ifdef TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_COPY:
            /* This relocation must copy initialized data from the library
            to the program .bss segment. Currently made like for ARM
            (to remove noise of default case). Is this true?
            */
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_TLS_GD:
            {
                ସ୍ଥିର ଅଚଳ unsigned ଅକ୍ଷର expect[] = {
                    /* lea 0(,%ebx,1),%eax */
                    0x8d, 0x04, 0x1d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                ସ୍ଥିର ଅଚଳ unsigned ଅକ୍ଷର replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* sub 0,%eax */
                    0x81, 0xe8, 0x00, 0x00, 0x00, 0x00 };

                ଯଦି (memcmp (ptr-3, expect, ଆକାର(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    memcpy(ptr-3, replace, ଆକାର(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_ମୂଲ୍ୟ - sec->sh_addr - sec->data_offset;
                    add32le(ptr + 5, -x);
                }
                ଅନ୍ୟଥା
                    tcc_error_noabort("unexpected R_386_TLS_GD pattern");
            }
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_TLS_LDM:
            {
                ସ୍ଥିର ଅଚଳ unsigned ଅକ୍ଷର expect[] = {
                    /* lea 0(%ebx),%eax */
                    0x8d, 0x83, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                ସ୍ଥିର ଅଚଳ unsigned ଅକ୍ଷର replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* nop */
                    0x90,
                    /* lea 0(%esi,%eiz,1),%esi */
                    0x8d, 0x74, 0x26, 0x00 };

                ଯଦି (memcmp (ptr-2, expect, ଆକାର(expect)) == 0) {
                    memcpy(ptr-2, replace, ଆକାର(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                }
                ଅନ୍ୟଥା
                    tcc_error_noabort("unexpected R_386_TLS_LDM pattern");
            }
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_TLS_LDO_32:
            {
                ElfW(Sym) *sym;
                Section *sec;
                int32_t x;

                sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                sec = s1->sections[sym->st_shndx];
                x = val - sec->sh_addr - sec->data_offset;
                add32le(ptr, x);
            }
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_TLS_LE:
            {
                int32_t x;
                ଯଦି (s1->tls_end) {
                    x = val - s1->tls_end;
                } ଅନ୍ୟଥା {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->data_offset;
                }
                add32le(ptr, x);
            }
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି R_386_NONE:
            ଫେରନ୍ତୁ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (unsigned)addr, ptr, (unsigned)val);
            ଫେରନ୍ତୁ;
    }
}

#endif /* !TARGET_DEFS_ONLY */
