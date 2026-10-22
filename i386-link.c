#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_386

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_386_32
#define R_DATA_PTR  R_386_32
#define R_JMP_SLOT  R_386_JMP_SLOT
#define R_GLOB_DAT  R_386_GLOB_DAT
#define R_COPY      R_386_COPY
#define R_RELATIVE  R_386_RELATIVE

#define R_NUM       R_386_NUM

#define ELF_START_ADDR 0x08048000
#define ELF_PAGE_SIZE  0x1000

#만약 defined CONFIG_TCC_PIC
#define PCRELATIVE_DLLPLT 1
#아니면
#define PCRELATIVE_DLLPLT 0
#endif
#define RELOCATE_DLLPLT 1

#아니면 /* !TARGET_DEFS_ONLY */

#include "tcc.h"

#ifdef NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC 정수 code_reloc (정수 reloc_type)
{
    switch (reloc_type) {
	case R_386_RELATIVE:
	case R_386_16:
        case R_386_32:
	case R_386_GOTPC:
	case R_386_GOTOFF:
	case R_386_GOT32:
	case R_386_GOT32X:
	case R_386_GLOB_DAT:
	case R_386_COPY:
	case R_386_TLS_GD:
	case R_386_TLS_LDM:
	case R_386_TLS_LDO_32:
	case R_386_TLS_LE:
            반환 0;

	case R_386_PC16:
	case R_386_PC32:
	case R_386_PLT32:
	case R_386_JMP_SLOT:
            반환 1;
    }
    반환 -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC 정수 gotplt_entry_type (정수 reloc_type)
{
    switch (reloc_type) {
	case R_386_RELATIVE:
	case R_386_16:
	case R_386_GLOB_DAT:
	case R_386_JMP_SLOT:
	case R_386_COPY:
            반환 NO_GOTPLT_ENTRY;

        case R_386_32:
	    /* This relocations shouldn't normally need GOT or PLT
	       slots if it weren't for simplicity in the code generator.
	       See our caller for comments.  */
            반환 AUTO_GOTPLT_ENTRY;

	case R_386_PC16:
	case R_386_PC32:
            반환 AUTO_GOTPLT_ENTRY;

	case R_386_GOTPC:
	case R_386_GOTOFF:
            반환 BUILD_GOT_ONLY;

	case R_386_GOT32:
	case R_386_GOT32X:
	case R_386_PLT32:
	case R_386_TLS_GD:
	case R_386_TLS_LDM:
	case R_386_TLS_LDO_32:
	case R_386_TLS_LE:
            반환 ALWAYS_GOTPLT_ENTRY;
    }
    반환 -1;
}

#ifdef NEED_BUILD_GOT
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, struct sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    정수 modrm;
    unsigned plt_offset, relofs;

    /* on i386 if we build a DLL, we add a %ebx offset */
    만약 (s1->output_type & TCC_OUTPUT_DYN)
        modrm = 0xa3;
    아니면
        modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    만약 (plt->data_offset == 0) {
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
    write32le(p + 7, relofs - sizeof (ElfW_Rel));
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->data_offset));
    반환 plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC void relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    만약 (!s1->plt)
      반환;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    만약 (!(s1->output_type & TCC_OUTPUT_DYN) && p < p_end) {
        add32le(p + 2, s1->got->sh_addr);
        add32le(p + 8, s1->got->sh_addr);
        p += 16;
        동안 (p < p_end) {
            add32le(p + 2, s1->got->sh_addr);
            p += 16;
        }
    }

    만약 (s1->plt->reloc) {
        ElfW_Rel *rel;
        정수 x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->data;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_offset, x);
            x += 16;
        }
    }
}
#endif
#endif

ST_FUNC void relocate(TCCState *s1, ElfW_Rel *rel, 정수 type, unsigned char *ptr, addr_t addr, addr_t val)
{
    정수 sym_index, esym_index;

    sym_index = ELFW(R_SYM)(rel->r_info);

    switch (type) {
        case R_386_32:
            만약 (s1->output_type & TCC_OUTPUT_DYN) {
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                qrel->r_offset = rel->r_offset;
                만약 (esym_index) {
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_386_32);
                    qrel++;
                    반환;
                } 아니면 {
                    qrel->r_info = ELFW(R_INFO)(0, R_386_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            반환;
        case R_386_PC32:
            만약 (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                만약 (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_386_PC32);
                    qrel++;
                    반환;
                }
            }
            add32le(ptr, val - addr);
            반환;
        case R_386_PLT32:
            add32le(ptr, val - addr);
            반환;
        case R_386_GLOB_DAT:
        case R_386_JMP_SLOT:
            write32le(ptr, val);
            반환;
        case R_386_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            반환;
        case R_386_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            반환;
        case R_386_GOT32:
        case R_386_GOT32X:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            반환;
        case R_386_16:
            만약 (s1->output_format != TCC_OUTPUT_FORMAT_BINARY) {
            output_file:
                tcc_error_noabort("can only produce 16-bit binary files");
            }
            write16le(ptr, read16le(ptr) + val);
            반환;
        case R_386_PC16:
            만약 (s1->output_format != TCC_OUTPUT_FORMAT_BINARY)
                goto output_file;
            write16le(ptr, read16le(ptr) + val - addr);
            반환;
        case R_386_RELATIVE:
#ifdef TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            반환;
        case R_386_COPY:
            /* This relocation must copy initialized data from the library
            to the program .bss segment. Currently made like for ARM
            (to remove noise of default case). Is this true?
            */
            반환;
        case R_386_TLS_GD:
            {
                static const unsigned char expect[] = {
                    /* lea 0(,%ebx,1),%eax */
                    0x8d, 0x04, 0x1d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                static const unsigned char replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* sub 0,%eax */
                    0x81, 0xe8, 0x00, 0x00, 0x00, 0x00 };

                만약 (memcmp (ptr-3, expect, sizeof(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    memcpy(ptr-3, replace, sizeof(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_value - sec->sh_addr - sec->data_offset;
                    add32le(ptr + 5, -x);
                }
                아니면
                    tcc_error_noabort("unexpected R_386_TLS_GD pattern");
            }
            반환;
        case R_386_TLS_LDM:
            {
                static const unsigned char expect[] = {
                    /* lea 0(%ebx),%eax */
                    0x8d, 0x83, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                static const unsigned char replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* nop */
                    0x90,
                    /* lea 0(%esi,%eiz,1),%esi */
                    0x8d, 0x74, 0x26, 0x00 };

                만약 (memcmp (ptr-2, expect, sizeof(expect)) == 0) {
                    memcpy(ptr-2, replace, sizeof(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                }
                아니면
                    tcc_error_noabort("unexpected R_386_TLS_LDM pattern");
            }
            반환;
        case R_386_TLS_LDO_32:
            {
                ElfW(Sym) *sym;
                Section *sec;
                int32_t x;

                sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                sec = s1->sections[sym->st_shndx];
                x = val - sec->sh_addr - sec->data_offset;
                add32le(ptr, x);
            }
            반환;
        case R_386_TLS_LE:
            {
                int32_t x;
                만약 (s1->tls_end) {
                    x = val - s1->tls_end;
                } 아니면 {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->data_offset;
                }
                add32le(ptr, x);
            }
            반환;
        case R_386_NONE:
            반환;
        default:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (unsigned)addr, ptr, (unsigned)val);
            반환;
    }
}

#endif /* !TARGET_DEFS_ONLY */
