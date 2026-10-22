#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_X86_64

/* relocation type for 32 bit data relocation */
#define R_তথ্য_32   R_X86_64_32S
#define R_তথ্য_PTR  R_X86_64_64
#define R_JMP_SLOT  R_X86_64_JUMP_SLOT
#define R_GLOB_DAT  R_X86_64_GLOB_DAT
#define R_COPY      R_X86_64_COPY
#define R_RELATIVE  R_X86_64_RELATIVE

#define R_অঙ্ক       R_X86_64_অঙ্ক

#define ELF_START_ADDR 0x400000
#define ELF_PAGE_আকার  0x1000

#define PCRELATIVE_DLLPLT 1
#define RELOCATE_DLLPLT 1

#অন্যথা /* !TARGET_DEFS_ONLY */

#অন্তর্ভাব "tcc.h"

#ifdef NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC পূর্ণসংখ্যা code_reloc (পূর্ণসংখ্যা reloc_type)
{
    নির্বাচন (reloc_type) {
        ক্ষেত্র R_X86_64_32:
        ক্ষেত্র R_X86_64_32S:
        ক্ষেত্র R_X86_64_64:
        ক্ষেত্র R_X86_64_GOTPC32:
        ক্ষেত্র R_X86_64_GOTPC64:
        ক্ষেত্র R_X86_64_GOTPCREL:
        ক্ষেত্র R_X86_64_GOTPCRELX:
        ক্ষেত্র R_X86_64_REX_GOTPCRELX:
        ক্ষেত্র R_X86_64_GOTTPOFF:
        ক্ষেত্র R_X86_64_GOT32:
        ক্ষেত্র R_X86_64_GOT64:
        ক্ষেত্র R_X86_64_GLOB_DAT:
        ক্ষেত্র R_X86_64_COPY:
        ক্ষেত্র R_X86_64_RELATIVE:
        ক্ষেত্র R_X86_64_GOTOFF64:
        ক্ষেত্র R_X86_64_TLSGD:
        ক্ষেত্র R_X86_64_TLSLD:
        ক্ষেত্র R_X86_64_DTPOFF32:
        ক্ষেত্র R_X86_64_TPOFF32:
        ক্ষেত্র R_X86_64_DTPOFF64:
        ক্ষেত্র R_X86_64_TPOFF64:
            ফেরত 0;

        ক্ষেত্র R_X86_64_PC32:
        ক্ষেত্র R_X86_64_PC64:
        ক্ষেত্র R_X86_64_PLT32:
        ক্ষেত্র R_X86_64_PLTOFF64:
        ক্ষেত্র R_X86_64_JUMP_SLOT:
            ফেরত 1;
    }
    ফেরত -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC পূর্ণসংখ্যা gotplt_entry_type (পূর্ণসংখ্যা reloc_type)
{
    নির্বাচন (reloc_type) {
        ক্ষেত্র R_X86_64_GLOB_DAT:
        ক্ষেত্র R_X86_64_JUMP_SLOT:
        ক্ষেত্র R_X86_64_COPY:
        ক্ষেত্র R_X86_64_RELATIVE:
            ফেরত NO_GOTPLT_ENTRY;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        ক্ষেত্র R_X86_64_32:
        ক্ষেত্র R_X86_64_32S:
        ক্ষেত্র R_X86_64_64:
        ক্ষেত্র R_X86_64_PC32:
        ক্ষেত্র R_X86_64_PC64:
            ফেরত AUTO_GOTPLT_ENTRY;

        ক্ষেত্র R_X86_64_GOTTPOFF:
            ফেরত BUILD_GOT_ONLY;

        ক্ষেত্র R_X86_64_GOT32:
        ক্ষেত্র R_X86_64_GOT64:
        ক্ষেত্র R_X86_64_GOTPC32:
        ক্ষেত্র R_X86_64_GOTPC64:
        ক্ষেত্র R_X86_64_GOTOFF64:
        ক্ষেত্র R_X86_64_GOTPCREL:
        ক্ষেত্র R_X86_64_GOTPCRELX:
        ক্ষেত্র R_X86_64_TLSGD:
        ক্ষেত্র R_X86_64_TLSLD:
        ক্ষেত্র R_X86_64_DTPOFF32:
        ক্ষেত্র R_X86_64_DTPOFF64:
        ক্ষেত্র R_X86_64_REX_GOTPCRELX:
        ক্ষেত্র R_X86_64_PLT32:
        ক্ষেত্র R_X86_64_PLTOFF64:
            ফেরত ALWAYS_GOTPLT_ENTRY;

        ক্ষেত্র R_X86_64_TPOFF32:
        ক্ষেত্র R_X86_64_TPOFF64:
            ফেরত NO_GOTPLT_ENTRY;
    }

    ফেরত -1;
}

#ifdef NEED_BUILD_GOT
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, কাঠামো sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    পূর্ণসংখ্যা modrm;
    unsigned plt_offset, relofs;

    modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    যদি (plt->তথ্য_offset == 0) {
        p = section_ptr_add(plt, 16);
        p[0] = 0xff; /* pushl got + PTR_SIZE */
        p[1] = modrm + 0x10;
        write32le(p + 2, PTR_আকার);
        p[6] = 0xff; /* jmp *(got + PTR_SIZE * 2) */
        p[7] = modrm;
        write32le(p + 8, PTR_আকার * 2);
    }
    plt_offset = plt->তথ্য_offset;

    /* The PLT slot refers to the relocation entry it needs via offset.
       The reloc entry is created below, so its offset is the current
       data_offset */
    relofs = s1->plt->reloc ? s1->plt->reloc->তথ্য_offset : 0;

    /* Jump to GOT entry where ld.so initially put the address of ip + 4 */
    p = section_ptr_add(plt, 16);
    p[0] = 0xff; /* jmp *(got + x) */
    p[1] = modrm;
    write32le(p + 2, got_offset);
    p[6] = 0x68; /* push $xxx */
    /* On x86-64, the relocation is referred to by _index_ */
    write32le(p + 7, relofs / আকার (ElfW_Rel) - 1);
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->তথ্য_offset));
    ফেরত plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC শূন্য relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    যদি (!s1->plt)
      ফেরত;

    p = s1->plt->তথ্য;
    p_end = p + s1->plt->তথ্য_offset;

    যদি (p < p_end) {
        পূর্ণসংখ্যা x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        যখন (p < p_end) {
            add32le(p + 2, x + (s1->plt->তথ্য - p));
            p += 16;
        }
    }

    যদি (s1->plt->reloc) {
        ElfW_Rel *rel;
        পূর্ণসংখ্যা x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->তথ্য;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_offset, x);
            x += 16;
        }
    }
}
#endif
#endif

ST_FUNC শূন্য relocate(TCCState *s1, ElfW_Rel *rel, পূর্ণসংখ্যা type, unsigned অক্ষর *ptr, addr_t addr, addr_t val)
{
    পূর্ণসংখ্যা sym_সূচক, esym_সূচক;

    sym_সূচক = ELFW(R_SYM)(rel->r_info);

    নির্বাচন (type) {
        ক্ষেত্র R_X86_64_64:
            যদি (s1->output_type & TCC_OUTPUT_DYN) {
                esym_সূচক = get_sym_attr(s1, sym_সূচক, 0)->dyn_সূচক;
                qrel->r_offset = rel->r_offset;
                যদি (esym_সূচক) {
                    qrel->r_info = ELFW(R_INFO)(esym_সূচক, R_X86_64_64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    বিরতি;
                } অন্যথা {
                    qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            বিরতি;
        ক্ষেত্র R_X86_64_32:
        ক্ষেত্র R_X86_64_32S:
            যদি (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_offset = rel->r_offset;
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (পূর্ণসংখ্যা)read32le(ptr) + val;
                qrel++;
            }
            যদি ((type == R_X86_64_32 ? val != (unsigned)val : val != (পূর্ণসংখ্যা)val)
                /* ignore relocation check for stab section */
                && (stab_section == ফাঁকা ||
                    addr < stab_section->sh_addr ||
                    addr >= (stab_section->sh_addr + stab_section->তথ্য_offset))) {
                tcc_error_noabort("relocation 'R_X86_64_32[S]' out of range");
            }
            add32le(ptr, val);
            বিরতি;

        ক্ষেত্র R_X86_64_PC32:
            যদি (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_সূচক = get_sym_attr(s1, sym_সূচক, 0)->dyn_সূচক;
                যদি (esym_সূচক) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_সূচক, R_X86_64_PC32);
                    /* Use sign extension! */
                    qrel->r_addend = (পূর্ণসংখ্যা)read32le(ptr) + rel->r_addend;
                    qrel++;
                    বিরতি;
                }
            }
            যাও plt32pc32;

        ক্ষেত্র R_X86_64_PLT32:
            /* fallthrough: val already holds the PLT slot address */

        plt32pc32:
        {
            long long diff;
            diff = (long long)val - addr;
            যদি (diff < -2147483648LL || diff > 2147483647LL) {
#ifdef TCC_TARGET_PE
              /* ignore overflow with undefined weak symbols */
              যদি (((ElfW(Sym)*)symtab_section->তথ্য)[sym_সূচক].st_shndx != SHN_UNDEF)
#endif
                tcc_error_noabort("relocation '%d' out of range", type);
            }
            add32le(ptr, diff);
        }
            বিরতি;

        ক্ষেত্র R_X86_64_COPY:
	    বিরতি;

        ক্ষেত্র R_X86_64_PLTOFF64:
            add64le(ptr, val - s1->got->sh_addr + rel->r_addend);
            বিরতি;

        ক্ষেত্র R_X86_64_PC64:
            যদি (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_সূচক = get_sym_attr(s1, sym_সূচক, 0)->dyn_সূচক;
                যদি (esym_সূচক) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_সূচক, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    বিরতি;
                }
            }
            add64le(ptr, val - addr);
            বিরতি;

        ক্ষেত্র R_X86_64_GLOB_DAT:
        ক্ষেত্র R_X86_64_JUMP_SLOT:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            বিরতি;
        ক্ষেত্র R_X86_64_GOTPCREL:
        ক্ষেত্র R_X86_64_GOTPCRELX:
        ক্ষেত্র R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         get_sym_attr(s1, sym_সূচক, 0)->got_offset - 4);
            বিরতি;
        ক্ষেত্র R_X86_64_GOTPC32:
            add32le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            বিরতি;
        ক্ষেত্র R_X86_64_GOTPC64:
            add64le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            বিরতি;
        ক্ষেত্র R_X86_64_GOTTPOFF:
            add32le(ptr, val - s1->got->sh_addr);
            বিরতি;
        ক্ষেত্র R_X86_64_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_সূচক, 0)->got_offset);
            বিরতি;
        ক্ষেত্র R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, get_sym_attr(s1, sym_সূচক, 0)->got_offset);
            বিরতি;
        ক্ষেত্র R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            বিরতি;
        ক্ষেত্র R_X86_64_TLSGD:
            {
                স্থির ধ্রুবক unsigned অক্ষর expect[] = {
                    /* .byte 0x66; lea 0(%rip),%rdi */
                    0x66, 0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* .word 0x6666; rex64; call __tls_get_addr@PLT */
                    0x66, 0x66, 0x48, 0xe8, 0x00, 0x00, 0x00, 0x00 };
                স্থির ধ্রুবক unsigned অক্ষর replace[] = {
                    /* mov %fs:0,%rax */
                    0x64, 0x48, 0x8b, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
                    /* lea -4(%rax),%rax */
                    0x48, 0x8d, 0x80, 0x00, 0x00, 0x00, 0x00 };

                যদি (memcmp (ptr-4, expect, আকার(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    memcpy(ptr-4, replace, আকার(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->তথ্য)[sym_সূচক];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_মান - sec->sh_addr - sec->তথ্য_offset;
                    add32le(ptr + 8, x);
                }
                অন্যথা
                    tcc_error_noabort("unexpected R_X86_64_TLSGD pattern");
            }
            বিরতি;
        ক্ষেত্র R_X86_64_TLSLD:
            {
                স্থির ধ্রুবক unsigned অক্ষর expect[] = {
                    /* lea 0(%rip),%rdi */
                    0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0x00, 0x00, 0x00, 0x00 };
                স্থির ধ্রুবক unsigned অক্ষর replace[] = {
                    /* data16 data16 data16 mov %fs:0,%rax */
                    0x66, 0x66, 0x66, 0x64, 0x48, 0x8b, 0x04, 0x25,
                    0x00, 0x00, 0x00, 0x00 };

                যদি (memcmp (ptr-3, expect, আকার(expect)) == 0) {
                    memcpy(ptr-3, replace, আকার(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                }
                অন্যথা
                    tcc_error_noabort("unexpected R_X86_64_TLSLD pattern");
            }
            বিরতি;

        ক্ষেত্র R_X86_64_DTPOFF32:
        ক্ষেত্র R_X86_64_TPOFF32:
        ক্ষেত্র R_X86_64_DTPOFF64:
        ক্ষেত্র R_X86_64_TPOFF64:
            {
                int32_t x;
                যদি (s1->tls_end) {
                    x = val - s1->tls_end;
                } অন্যথা {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->তথ্য)[sym_সূচক];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->তথ্য_offset;
                }
                নির্বাচন (type) {
                ক্ষেত্র R_X86_64_DTPOFF64:
                ক্ষেত্র R_X86_64_TPOFF64:
                    add64le(ptr, x);
                    বিরতি;
                পূর্বনির্ধারিত:
                    add32le(ptr, x);
                    বিরতি;
                }
            }
            বিরতি;
        ক্ষেত্র R_X86_64_NONE:
            বিরতি;
        ক্ষেত্র R_X86_64_RELATIVE:
#ifdef TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            বিরতি;
        পূর্বনির্ধারিত:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (unsigned)addr, ptr, (unsigned)val);
            বিরতি;
    }
}

#endif /* !TARGET_DEFS_ONLY */
