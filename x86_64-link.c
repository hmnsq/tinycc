#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_X86_64

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_X86_64_32S
#define R_DATA_PTR  R_X86_64_64
#define R_JMP_SLOT  R_X86_64_JUMP_SLOT
#define R_GLOB_DAT  R_X86_64_GLOB_DAT
#define R_COPY      R_X86_64_COPY
#define R_RELATIVE  R_X86_64_RELATIVE

#define R_NUM       R_X86_64_NUM

#define ELF_START_ADDR 0x400000
#define ELF_PAGE_SIZE  0x1000

#define PCRELATIVE_DLLPLT 1
#define RELOCATE_DLLPLT 1

#وإلا /* !TARGET_DEFS_ONLY */

#ضمن "tcc.h"

#ifdef NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحيح code_reloc (صحيح reloc_type)
{
    بدل (reloc_type) {
        حالة R_X86_64_32:
        حالة R_X86_64_32S:
        حالة R_X86_64_64:
        حالة R_X86_64_GOTPC32:
        حالة R_X86_64_GOTPC64:
        حالة R_X86_64_GOTPCREL:
        حالة R_X86_64_GOTPCRELX:
        حالة R_X86_64_REX_GOTPCRELX:
        حالة R_X86_64_GOTTPOFF:
        حالة R_X86_64_GOT32:
        حالة R_X86_64_GOT64:
        حالة R_X86_64_GLOB_DAT:
        حالة R_X86_64_COPY:
        حالة R_X86_64_RELATIVE:
        حالة R_X86_64_GOTOFF64:
        حالة R_X86_64_TLSGD:
        حالة R_X86_64_TLSLD:
        حالة R_X86_64_DTPOFF32:
        حالة R_X86_64_TPOFF32:
        حالة R_X86_64_DTPOFF64:
        حالة R_X86_64_TPOFF64:
            أرجع 0;

        حالة R_X86_64_PC32:
        حالة R_X86_64_PC64:
        حالة R_X86_64_PLT32:
        حالة R_X86_64_PLTOFF64:
        حالة R_X86_64_JUMP_SLOT:
            أرجع 1;
    }
    أرجع -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC صحيح gotplt_entry_type (صحيح reloc_type)
{
    بدل (reloc_type) {
        حالة R_X86_64_GLOB_DAT:
        حالة R_X86_64_JUMP_SLOT:
        حالة R_X86_64_COPY:
        حالة R_X86_64_RELATIVE:
            أرجع NO_GOTPLT_ENTRY;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        حالة R_X86_64_32:
        حالة R_X86_64_32S:
        حالة R_X86_64_64:
        حالة R_X86_64_PC32:
        حالة R_X86_64_PC64:
            أرجع AUTO_GOTPLT_ENTRY;

        حالة R_X86_64_GOTTPOFF:
            أرجع BUILD_GOT_ONLY;

        حالة R_X86_64_GOT32:
        حالة R_X86_64_GOT64:
        حالة R_X86_64_GOTPC32:
        حالة R_X86_64_GOTPC64:
        حالة R_X86_64_GOTOFF64:
        حالة R_X86_64_GOTPCREL:
        حالة R_X86_64_GOTPCRELX:
        حالة R_X86_64_TLSGD:
        حالة R_X86_64_TLSLD:
        حالة R_X86_64_DTPOFF32:
        حالة R_X86_64_DTPOFF64:
        حالة R_X86_64_REX_GOTPCRELX:
        حالة R_X86_64_PLT32:
        حالة R_X86_64_PLTOFF64:
            أرجع ALWAYS_GOTPLT_ENTRY;

        حالة R_X86_64_TPOFF32:
        حالة R_X86_64_TPOFF64:
            أرجع NO_GOTPLT_ENTRY;
    }

    أرجع -1;
}

#ifdef NEED_BUILD_GOT
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, بنية sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    صحيح modrm;
    unsigned plt_offset, relofs;

    modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    𐤀𐤌 (plt->data_offset == 0) {
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
    write32le(p + 7, relofs / حجم (ElfW_Rel) - 1);
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->data_offset));
    أرجع plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC فراغ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    𐤀𐤌 (!s1->plt)
      أرجع;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    𐤀𐤌 (p < p_end) {
        صحيح x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        طالما (p < p_end) {
            add32le(p + 2, x + (s1->plt->data - p));
            p += 16;
        }
    }

    𐤀𐤌 (s1->plt->reloc) {
        ElfW_Rel *rel;
        صحيح x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->data;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_offset, x);
            x += 16;
        }
    }
}
#endif
#endif

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, unsigned حرف *ptr, addr_t addr, addr_t val)
{
    صحيح sym_index, esym_index;

    sym_index = ELFW(R_SYM)(rel->r_info);

    بدل (type) {
        حالة R_X86_64_64:
            𐤀𐤌 (s1->output_type & TCC_OUTPUT_DYN) {
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                qrel->r_offset = rel->r_offset;
                𐤀𐤌 (esym_index) {
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    اكسر;
                } وإلا {
                    qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            اكسر;
        حالة R_X86_64_32:
        حالة R_X86_64_32S:
            𐤀𐤌 (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_offset = rel->r_offset;
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (صحيح)read32le(ptr) + val;
                qrel++;
            }
            𐤀𐤌 ((type == R_X86_64_32 ? val != (unsigned)val : val != (صحيح)val)
                /* ignore relocation check for stab section */
                && (stab_section == عدم ||
                    addr < stab_section->sh_addr ||
                    addr >= (stab_section->sh_addr + stab_section->data_offset))) {
                tcc_error_noabort("relocation 'R_X86_64_32[S]' out of range");
            }
            add32le(ptr, val);
            اكسر;

        حالة R_X86_64_PC32:
            𐤀𐤌 (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                𐤀𐤌 (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_PC32);
                    /* Use sign extension! */
                    qrel->r_addend = (صحيح)read32le(ptr) + rel->r_addend;
                    qrel++;
                    اكسر;
                }
            }
            اذهب plt32pc32;

        حالة R_X86_64_PLT32:
            /* fallthrough: val already holds the PLT slot address */

        plt32pc32:
        {
            long long diff;
            diff = (long long)val - addr;
            𐤀𐤌 (diff < -2147483648LL || diff > 2147483647LL) {
#ifdef TCC_TARGET_PE
              /* ignore overflow with undefined weak symbols */
              𐤀𐤌 (((ElfW(Sym)*)symtab_section->data)[sym_index].st_shndx != SHN_UNDEF)
#endif
                tcc_error_noabort("relocation '%d' out of range", type);
            }
            add32le(ptr, diff);
        }
            اكسر;

        حالة R_X86_64_COPY:
	    اكسر;

        حالة R_X86_64_PLTOFF64:
            add64le(ptr, val - s1->got->sh_addr + rel->r_addend);
            اكسر;

        حالة R_X86_64_PC64:
            𐤀𐤌 (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                𐤀𐤌 (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    اكسر;
                }
            }
            add64le(ptr, val - addr);
            اكسر;

        حالة R_X86_64_GLOB_DAT:
        حالة R_X86_64_JUMP_SLOT:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            اكسر;
        حالة R_X86_64_GOTPCREL:
        حالة R_X86_64_GOTPCRELX:
        حالة R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         get_sym_attr(s1, sym_index, 0)->got_offset - 4);
            اكسر;
        حالة R_X86_64_GOTPC32:
            add32le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            اكسر;
        حالة R_X86_64_GOTPC64:
            add64le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            اكسر;
        حالة R_X86_64_GOTTPOFF:
            add32le(ptr, val - s1->got->sh_addr);
            اكسر;
        حالة R_X86_64_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            اكسر;
        حالة R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            اكسر;
        حالة R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            اكسر;
        حالة R_X86_64_TLSGD:
            {
                ساكن ثابت unsigned حرف expect[] = {
                    /* .byte 0x66; lea 0(%rip),%rdi */
                    0x66, 0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* .word 0x6666; rex64; call __tls_get_addr@PLT */
                    0x66, 0x66, 0x48, 0xe8, 0x00, 0x00, 0x00, 0x00 };
                ساكن ثابت unsigned حرف replace[] = {
                    /* mov %fs:0,%rax */
                    0x64, 0x48, 0x8b, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
                    /* lea -4(%rax),%rax */
                    0x48, 0x8d, 0x80, 0x00, 0x00, 0x00, 0x00 };

                𐤀𐤌 (memcmp (ptr-4, expect, حجم(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    memcpy(ptr-4, replace, حجم(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_value - sec->sh_addr - sec->data_offset;
                    add32le(ptr + 8, x);
                }
                وإلا
                    tcc_error_noabort("unexpected R_X86_64_TLSGD pattern");
            }
            اكسر;
        حالة R_X86_64_TLSLD:
            {
                ساكن ثابت unsigned حرف expect[] = {
                    /* lea 0(%rip),%rdi */
                    0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0x00, 0x00, 0x00, 0x00 };
                ساكن ثابت unsigned حرف replace[] = {
                    /* data16 data16 data16 mov %fs:0,%rax */
                    0x66, 0x66, 0x66, 0x64, 0x48, 0x8b, 0x04, 0x25,
                    0x00, 0x00, 0x00, 0x00 };

                𐤀𐤌 (memcmp (ptr-3, expect, حجم(expect)) == 0) {
                    memcpy(ptr-3, replace, حجم(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                }
                وإلا
                    tcc_error_noabort("unexpected R_X86_64_TLSLD pattern");
            }
            اكسر;

        حالة R_X86_64_DTPOFF32:
        حالة R_X86_64_TPOFF32:
        حالة R_X86_64_DTPOFF64:
        حالة R_X86_64_TPOFF64:
            {
                int32_t x;
                𐤀𐤌 (s1->tls_end) {
                    x = val - s1->tls_end;
                } وإلا {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->data_offset;
                }
                بدل (type) {
                حالة R_X86_64_DTPOFF64:
                حالة R_X86_64_TPOFF64:
                    add64le(ptr, x);
                    اكسر;
                افتراضي:
                    add32le(ptr, x);
                    اكسر;
                }
            }
            اكسر;
        حالة R_X86_64_NONE:
            اكسر;
        حالة R_X86_64_RELATIVE:
#ifdef TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            اكسر;
        افتراضي:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (unsigned)addr, ptr, (unsigned)val);
            اكسر;
    }
}

#endif /* !TARGET_DEFS_ONLY */
