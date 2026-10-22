#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_X86_64

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_X86_64_32S
#define R_DATA_PTR  R_X86_64_64
#define R_JMP_SLOT  R_X86_64_JUMP_SLOT
#define R_GLOB_DAT  R_X86_64_GLOB_DAT
#define R_COPY      R_X86_64_COPY
#define R_RELATIVE  R_X86_64_RELATIVE

#define R_رقم       R_X86_64_رقم

#define ELF_START_ADDR 0x400000
#define ELF_PAGE_SIZE  0x1000

#define PCRELATIVE_DLLPLT 1
#define RELOCATE_DLLPLT 1

#وگرنه /* !TARGET_DEFS_ONLY */

#شامل "tcc.h"

#ifdef NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحیح code_reloc (صحیح reloc_type)
{
    انتخاب (reloc_type) {
        حالت R_X86_64_32:
        حالت R_X86_64_32S:
        حالت R_X86_64_64:
        حالت R_X86_64_GOTPC32:
        حالت R_X86_64_GOTPC64:
        حالت R_X86_64_GOTPCREL:
        حالت R_X86_64_GOTPCRELX:
        حالت R_X86_64_REX_GOTPCRELX:
        حالت R_X86_64_GOTTPOFF:
        حالت R_X86_64_GOT32:
        حالت R_X86_64_GOT64:
        حالت R_X86_64_GLOB_DAT:
        حالت R_X86_64_COPY:
        حالت R_X86_64_RELATIVE:
        حالت R_X86_64_GOTOFF64:
        حالت R_X86_64_TLSGD:
        حالت R_X86_64_TLSLD:
        حالت R_X86_64_DTPOFF32:
        حالت R_X86_64_TPOFF32:
        حالت R_X86_64_DTPOFF64:
        حالت R_X86_64_TPOFF64:
            بازگشت 0;

        حالت R_X86_64_PC32:
        حالت R_X86_64_PC64:
        حالت R_X86_64_PLT32:
        حالت R_X86_64_PLTOFF64:
        حالت R_X86_64_JUMP_SLOT:
            بازگشت 1;
    }
    بازگشت -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC صحیح gotplt_entry_type (صحیح reloc_type)
{
    انتخاب (reloc_type) {
        حالت R_X86_64_GLOB_DAT:
        حالت R_X86_64_JUMP_SLOT:
        حالت R_X86_64_COPY:
        حالت R_X86_64_RELATIVE:
            بازگشت NO_GOTPLT_ENTRY;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        حالت R_X86_64_32:
        حالت R_X86_64_32S:
        حالت R_X86_64_64:
        حالت R_X86_64_PC32:
        حالت R_X86_64_PC64:
            بازگشت AUTO_GOTPLT_ENTRY;

        حالت R_X86_64_GOTTPOFF:
            بازگشت BUILD_GOT_ONLY;

        حالت R_X86_64_GOT32:
        حالت R_X86_64_GOT64:
        حالت R_X86_64_GOTPC32:
        حالت R_X86_64_GOTPC64:
        حالت R_X86_64_GOTOFF64:
        حالت R_X86_64_GOTPCREL:
        حالت R_X86_64_GOTPCRELX:
        حالت R_X86_64_TLSGD:
        حالت R_X86_64_TLSLD:
        حالت R_X86_64_DTPOFF32:
        حالت R_X86_64_DTPOFF64:
        حالت R_X86_64_REX_GOTPCRELX:
        حالت R_X86_64_PLT32:
        حالت R_X86_64_PLTOFF64:
            بازگشت ALWAYS_GOTPLT_ENTRY;

        حالت R_X86_64_TPOFF32:
        حالت R_X86_64_TPOFF64:
            بازگشت NO_GOTPLT_ENTRY;
    }

    بازگشت -1;
}

#ifdef NEED_BUILD_GOT
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, ساختار sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    صحیح modrm;
    unsigned plt_offset, relofs;

    modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    اگر (plt->data_offset == 0) {
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
    write32le(p + 7, relofs / اندازه (ElfW_Rel) - 1);
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->data_offset));
    بازگشت plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC تهی relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    اگر (!s1->plt)
      بازگشت;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    اگر (p < p_end) {
        صحیح x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        وقتی (p < p_end) {
            add32le(p + 2, x + (s1->plt->data - p));
            p += 16;
        }
    }

    اگر (s1->plt->reloc) {
        ElfW_Rel *rel;
        صحیح x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->data;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_offset, x);
            x += 16;
        }
    }
}
#endif
#endif

ST_FUNC تهی relocate(TCCState *s1, ElfW_Rel *rel, صحیح type, unsigned نویسه *ptr, addr_t addr, addr_t val)
{
    صحیح sym_index, esym_index;

    sym_index = ELFW(R_SYM)(rel->r_info);

    انتخاب (type) {
        حالت R_X86_64_64:
            اگر (s1->output_type & TCC_OUTPUT_DYN) {
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                qrel->r_offset = rel->r_offset;
                اگر (esym_index) {
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    بشکن;
                } وگرنه {
                    qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            بشکن;
        حالت R_X86_64_32:
        حالت R_X86_64_32S:
            اگر (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_offset = rel->r_offset;
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (صحیح)read32le(ptr) + val;
                qrel++;
            }
            اگر ((type == R_X86_64_32 ? val != (unsigned)val : val != (صحیح)val)
                /* ignore relocation check for stab section */
                && (stab_section == پوچ ||
                    addr < stab_section->sh_addr ||
                    addr >= (stab_section->sh_addr + stab_section->data_offset))) {
                tcc_error_noabort("relocation 'R_X86_64_32[S]' out of range");
            }
            add32le(ptr, val);
            بشکن;

        حالت R_X86_64_PC32:
            اگر (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                اگر (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_PC32);
                    /* Use sign extension! */
                    qrel->r_addend = (صحیح)read32le(ptr) + rel->r_addend;
                    qrel++;
                    بشکن;
                }
            }
            برو plt32pc32;

        حالت R_X86_64_PLT32:
            /* fallthrough: val already holds the PLT slot address */

        plt32pc32:
        {
            long long diff;
            diff = (long long)val - addr;
            اگر (diff < -2147483648LL || diff > 2147483647LL) {
#ifdef TCC_TARGET_PE
              /* ignore overflow with undefined weak symbols */
              اگر (((ElfW(Sym)*)symtab_section->data)[sym_index].st_shndx != SHN_UNDEF)
#endif
                tcc_error_noabort("relocation '%d' out of range", type);
            }
            add32le(ptr, diff);
        }
            بشکن;

        حالت R_X86_64_COPY:
	    بشکن;

        حالت R_X86_64_PLTOFF64:
            add64le(ptr, val - s1->got->sh_addr + rel->r_addend);
            بشکن;

        حالت R_X86_64_PC64:
            اگر (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                اگر (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    بشکن;
                }
            }
            add64le(ptr, val - addr);
            بشکن;

        حالت R_X86_64_GLOB_DAT:
        حالت R_X86_64_JUMP_SLOT:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            بشکن;
        حالت R_X86_64_GOTPCREL:
        حالت R_X86_64_GOTPCRELX:
        حالت R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         get_sym_attr(s1, sym_index, 0)->got_offset - 4);
            بشکن;
        حالت R_X86_64_GOTPC32:
            add32le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            بشکن;
        حالت R_X86_64_GOTPC64:
            add64le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            بشکن;
        حالت R_X86_64_GOTTPOFF:
            add32le(ptr, val - s1->got->sh_addr);
            بشکن;
        حالت R_X86_64_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            بشکن;
        حالت R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            بشکن;
        حالت R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            بشکن;
        حالت R_X86_64_TLSGD:
            {
                ایستا ثابت unsigned نویسه expect[] = {
                    /* .byte 0x66; lea 0(%rip),%rdi */
                    0x66, 0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* .word 0x6666; rex64; call __tls_get_addr@PLT */
                    0x66, 0x66, 0x48, 0xe8, 0x00, 0x00, 0x00, 0x00 };
                ایستا ثابت unsigned نویسه replace[] = {
                    /* mov %fs:0,%rax */
                    0x64, 0x48, 0x8b, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
                    /* lea -4(%rax),%rax */
                    0x48, 0x8d, 0x80, 0x00, 0x00, 0x00, 0x00 };

                اگر (memcmp (ptr-4, expect, اندازه(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    memcpy(ptr-4, replace, اندازه(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_مقدار - sec->sh_addr - sec->data_offset;
                    add32le(ptr + 8, x);
                }
                وگرنه
                    tcc_error_noabort("unexpected R_X86_64_TLSGD pattern");
            }
            بشکن;
        حالت R_X86_64_TLSLD:
            {
                ایستا ثابت unsigned نویسه expect[] = {
                    /* lea 0(%rip),%rdi */
                    0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0x00, 0x00, 0x00, 0x00 };
                ایستا ثابت unsigned نویسه replace[] = {
                    /* data16 data16 data16 mov %fs:0,%rax */
                    0x66, 0x66, 0x66, 0x64, 0x48, 0x8b, 0x04, 0x25,
                    0x00, 0x00, 0x00, 0x00 };

                اگر (memcmp (ptr-3, expect, اندازه(expect)) == 0) {
                    memcpy(ptr-3, replace, اندازه(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                }
                وگرنه
                    tcc_error_noabort("unexpected R_X86_64_TLSLD pattern");
            }
            بشکن;

        حالت R_X86_64_DTPOFF32:
        حالت R_X86_64_TPOFF32:
        حالت R_X86_64_DTPOFF64:
        حالت R_X86_64_TPOFF64:
            {
                int32_t x;
                اگر (s1->tls_end) {
                    x = val - s1->tls_end;
                } وگرنه {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->data_offset;
                }
                انتخاب (type) {
                حالت R_X86_64_DTPOFF64:
                حالت R_X86_64_TPOFF64:
                    add64le(ptr, x);
                    بشکن;
                پیشفرض:
                    add32le(ptr, x);
                    بشکن;
                }
            }
            بشکن;
        حالت R_X86_64_NONE:
            بشکن;
        حالت R_X86_64_RELATIVE:
#ifdef TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            بشکن;
        پیشفرض:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (unsigned)addr, ptr, (unsigned)val);
            بشکن;
    }
}

#endif /* !TARGET_DEFS_ONLY */
