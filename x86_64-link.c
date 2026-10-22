#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_X86_64

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_X86_64_32S
#define R_DATA_PTR  R_X86_64_64
#define R_JMP_SLOT  R_X86_64_JUMP_SLOT
#define R_GLOB_DAT  R_X86_64_GLOB_DAT
#define R_COPY      R_X86_64_COPY
#define R_RELATIVE  R_X86_64_RELATIVE

#define R_ଅଙ୍କ       R_X86_64_ଅଙ୍କ

#define ELF_START_ADDR 0x400000
#define ELF_PAGE_SIZE  0x1000

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
        ସ୍ଥିତି R_X86_64_32:
        ସ୍ଥିତି R_X86_64_32S:
        ସ୍ଥିତି R_X86_64_64:
        ସ୍ଥିତି R_X86_64_GOTPC32:
        ସ୍ଥିତି R_X86_64_GOTPC64:
        ସ୍ଥିତି R_X86_64_GOTPCREL:
        ସ୍ଥିତି R_X86_64_GOTPCRELX:
        ସ୍ଥିତି R_X86_64_REX_GOTPCRELX:
        ସ୍ଥିତି R_X86_64_GOTTPOFF:
        ସ୍ଥିତି R_X86_64_GOT32:
        ସ୍ଥିତି R_X86_64_GOT64:
        ସ୍ଥିତି R_X86_64_GLOB_DAT:
        ସ୍ଥିତି R_X86_64_COPY:
        ସ୍ଥିତି R_X86_64_RELATIVE:
        ସ୍ଥିତି R_X86_64_GOTOFF64:
        ସ୍ଥିତି R_X86_64_TLSGD:
        ସ୍ଥିତି R_X86_64_TLSLD:
        ସ୍ଥିତି R_X86_64_DTPOFF32:
        ସ୍ଥିତି R_X86_64_TPOFF32:
        ସ୍ଥିତି R_X86_64_DTPOFF64:
        ସ୍ଥିତି R_X86_64_TPOFF64:
            ଫେରନ୍ତୁ 0;

        ସ୍ଥିତି R_X86_64_PC32:
        ସ୍ଥିତି R_X86_64_PC64:
        ସ୍ଥିତି R_X86_64_PLT32:
        ସ୍ଥିତି R_X86_64_PLTOFF64:
        ସ୍ଥିତି R_X86_64_JUMP_SLOT:
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
        ସ୍ଥିତି R_X86_64_GLOB_DAT:
        ସ୍ଥିତି R_X86_64_JUMP_SLOT:
        ସ୍ଥିତି R_X86_64_COPY:
        ସ୍ଥିତି R_X86_64_RELATIVE:
            ଫେରନ୍ତୁ NO_GOTPLT_ENTRY;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        ସ୍ଥିତି R_X86_64_32:
        ସ୍ଥିତି R_X86_64_32S:
        ସ୍ଥିତି R_X86_64_64:
        ସ୍ଥିତି R_X86_64_PC32:
        ସ୍ଥିତି R_X86_64_PC64:
            ଫେରନ୍ତୁ AUTO_GOTPLT_ENTRY;

        ସ୍ଥିତି R_X86_64_GOTTPOFF:
            ଫେରନ୍ତୁ BUILD_GOT_ONLY;

        ସ୍ଥିତି R_X86_64_GOT32:
        ସ୍ଥିତି R_X86_64_GOT64:
        ସ୍ଥିତି R_X86_64_GOTPC32:
        ସ୍ଥିତି R_X86_64_GOTPC64:
        ସ୍ଥିତି R_X86_64_GOTOFF64:
        ସ୍ଥିତି R_X86_64_GOTPCREL:
        ସ୍ଥିତି R_X86_64_GOTPCRELX:
        ସ୍ଥିତି R_X86_64_TLSGD:
        ସ୍ଥିତି R_X86_64_TLSLD:
        ସ୍ଥିତି R_X86_64_DTPOFF32:
        ସ୍ଥିତି R_X86_64_DTPOFF64:
        ସ୍ଥିତି R_X86_64_REX_GOTPCRELX:
        ସ୍ଥିତି R_X86_64_PLT32:
        ସ୍ଥିତି R_X86_64_PLTOFF64:
            ଫେରନ୍ତୁ ALWAYS_GOTPLT_ENTRY;

        ସ୍ଥିତି R_X86_64_TPOFF32:
        ସ୍ଥିତି R_X86_64_TPOFF64:
            ଫେରନ୍ତୁ NO_GOTPLT_ENTRY;
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
    /* On x86-64, the relocation is referred to by _index_ */
    write32le(p + 7, relofs / ଆକାର (ElfW_Rel) - 1);
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

    ଯଦି (p < p_end) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        ଯେତେବେଳେ (p < p_end) {
            add32le(p + 2, x + (s1->plt->data - p));
            p += 16;
        }
    }

    ଯଦି (s1->plt->reloc) {
        ElfW_Rel *rel;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->data;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_offset, x);
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
        ସ୍ଥିତି R_X86_64_64:
            ଯଦି (s1->output_type & TCC_OUTPUT_DYN) {
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                qrel->r_offset = rel->r_offset;
                ଯଦି (esym_index) {
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    ଭାଙ୍ଗ;
                } ଅନ୍ୟଥା {
                    qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି R_X86_64_32:
        ସ୍ଥିତି R_X86_64_32S:
            ଯଦି (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_offset = rel->r_offset;
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)read32le(ptr) + val;
                qrel++;
            }
            ଯଦି ((type == R_X86_64_32 ? val != (unsigned)val : val != (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)val)
                /* ignore relocation check for stab section */
                && (stab_section == ଖାଲି ||
                    addr < stab_section->sh_addr ||
                    addr >= (stab_section->sh_addr + stab_section->data_offset))) {
                tcc_error_noabort("relocation 'R_X86_64_32[S]' out of range");
            }
            add32le(ptr, val);
            ଭାଙ୍ଗ;

        ସ୍ଥିତି R_X86_64_PC32:
            ଯଦି (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                ଯଦି (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_PC32);
                    /* Use sign extension! */
                    qrel->r_addend = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)read32le(ptr) + rel->r_addend;
                    qrel++;
                    ଭାଙ୍ଗ;
                }
            }
            ଯାଅ plt32pc32;

        ସ୍ଥିତି R_X86_64_PLT32:
            /* fallthrough: val already holds the PLT slot address */

        plt32pc32:
        {
            long long diff;
            diff = (long long)val - addr;
            ଯଦି (diff < -2147483648LL || diff > 2147483647LL) {
#ifdef TCC_TARGET_PE
              /* ignore overflow with undefined weak symbols */
              ଯଦି (((ElfW(Sym)*)symtab_section->data)[sym_index].st_shndx != SHN_UNDEF)
#endif
                tcc_error_noabort("relocation '%d' out of range", type);
            }
            add32le(ptr, diff);
        }
            ଭାଙ୍ଗ;

        ସ୍ଥିତି R_X86_64_COPY:
	    ଭାଙ୍ଗ;

        ସ୍ଥିତି R_X86_64_PLTOFF64:
            add64le(ptr, val - s1->got->sh_addr + rel->r_addend);
            ଭାଙ୍ଗ;

        ସ୍ଥିତି R_X86_64_PC64:
            ଯଦି (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                ଯଦି (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    ଭାଙ୍ଗ;
                }
            }
            add64le(ptr, val - addr);
            ଭାଙ୍ଗ;

        ସ୍ଥିତି R_X86_64_GLOB_DAT:
        ସ୍ଥିତି R_X86_64_JUMP_SLOT:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି R_X86_64_GOTPCREL:
        ସ୍ଥିତି R_X86_64_GOTPCRELX:
        ସ୍ଥିତି R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         get_sym_attr(s1, sym_index, 0)->got_offset - 4);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି R_X86_64_GOTPC32:
            add32le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି R_X86_64_GOTPC64:
            add64le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି R_X86_64_GOTTPOFF:
            add32le(ptr, val - s1->got->sh_addr);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି R_X86_64_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି R_X86_64_TLSGD:
            {
                ସ୍ଥିର ଅଚଳ unsigned ଅକ୍ଷର expect[] = {
                    /* .byte 0x66; lea 0(%rip),%rdi */
                    0x66, 0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* .word 0x6666; rex64; call __tls_get_addr@PLT */
                    0x66, 0x66, 0x48, 0xe8, 0x00, 0x00, 0x00, 0x00 };
                ସ୍ଥିର ଅଚଳ unsigned ଅକ୍ଷର replace[] = {
                    /* mov %fs:0,%rax */
                    0x64, 0x48, 0x8b, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
                    /* lea -4(%rax),%rax */
                    0x48, 0x8d, 0x80, 0x00, 0x00, 0x00, 0x00 };

                ଯଦି (memcmp (ptr-4, expect, ଆକାର(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    memcpy(ptr-4, replace, ଆକାର(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_ମୂଲ୍ୟ - sec->sh_addr - sec->data_offset;
                    add32le(ptr + 8, x);
                }
                ଅନ୍ୟଥା
                    tcc_error_noabort("unexpected R_X86_64_TLSGD pattern");
            }
            ଭାଙ୍ଗ;
        ସ୍ଥିତି R_X86_64_TLSLD:
            {
                ସ୍ଥିର ଅଚଳ unsigned ଅକ୍ଷର expect[] = {
                    /* lea 0(%rip),%rdi */
                    0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0x00, 0x00, 0x00, 0x00 };
                ସ୍ଥିର ଅଚଳ unsigned ଅକ୍ଷର replace[] = {
                    /* data16 data16 data16 mov %fs:0,%rax */
                    0x66, 0x66, 0x66, 0x64, 0x48, 0x8b, 0x04, 0x25,
                    0x00, 0x00, 0x00, 0x00 };

                ଯଦି (memcmp (ptr-3, expect, ଆକାର(expect)) == 0) {
                    memcpy(ptr-3, replace, ଆକାର(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                }
                ଅନ୍ୟଥା
                    tcc_error_noabort("unexpected R_X86_64_TLSLD pattern");
            }
            ଭାଙ୍ଗ;

        ସ୍ଥିତି R_X86_64_DTPOFF32:
        ସ୍ଥିତି R_X86_64_TPOFF32:
        ସ୍ଥିତି R_X86_64_DTPOFF64:
        ସ୍ଥିତି R_X86_64_TPOFF64:
            {
                int32_t x;
                ଯଦି (s1->tls_end) {
                    x = val - s1->tls_end;
                } ଅନ୍ୟଥା {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->data_offset;
                }
                ବାଛ (type) {
                ସ୍ଥିତି R_X86_64_DTPOFF64:
                ସ୍ଥିତି R_X86_64_TPOFF64:
                    add64le(ptr, x);
                    ଭାଙ୍ଗ;
                ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
                    add32le(ptr, x);
                    ଭାଙ୍ଗ;
                }
            }
            ଭାଙ୍ଗ;
        ସ୍ଥିତି R_X86_64_NONE:
            ଭାଙ୍ଗ;
        ସ୍ଥିତି R_X86_64_RELATIVE:
#ifdef TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (unsigned)addr, ptr, (unsigned)val);
            ଭାଙ୍ଗ;
    }
}

#endif /* !TARGET_DEFS_ONLY */
