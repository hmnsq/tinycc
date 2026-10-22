#که_تعریف_شوی موخه_DEFS_ONLY

#تعریف_کړه EM_TCC_موخه EM_X86_64

/* relocation type for 32 bit data relocation */
#تعریف_کړه R_معلومات_32   R_X86_64_32S
#تعریف_کړه R_معلومات_PTR  R_X86_64_64
#تعریف_کړه R_JMP_خونه  R_X86_64_JUMP_خونه
#تعریف_کړه R_GLOB_DAT  R_X86_64_GLOB_DAT
#تعریف_کړه R_COPY      R_X86_64_COPY
#تعریف_کړه R_RELATIVE  R_X86_64_RELATIVE

#تعریف_کړه R_عدد       R_X86_64_عدد

#تعریف_کړه ELF_پیل_ADDR 0x400000
#تعریف_کړه ELF_پاڼه_اندازه  0x1000

#تعریف_کړه PCRELATIVE_DLLPLT 1
#تعریف_کړه RELOCATE_DLLPLT 1

#وإلا /* !TARGET_DEFS_ONLY */

#ضمن "tcc.h"

#که_تعریف_شوی NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحيح کوډ_reloc (صحيح reloc_type)
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
        حالة R_X86_64_JUMP_خونه:
            أرجع 1;
    }
    أرجع -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC صحيح gotplt_ثبت_type (صحيح reloc_type)
{
    بدل (reloc_type) {
        حالة R_X86_64_GLOB_DAT:
        حالة R_X86_64_JUMP_خونه:
        حالة R_X86_64_COPY:
        حالة R_X86_64_RELATIVE:
            أرجع NO_GOTPLT_ثبت;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        حالة R_X86_64_32:
        حالة R_X86_64_32S:
        حالة R_X86_64_64:
        حالة R_X86_64_PC32:
        حالة R_X86_64_PC64:
            أرجع AUTO_GOTPLT_ثبت;

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
            أرجع ALWAYS_GOTPLT_ثبت;

        حالة R_X86_64_TPOFF32:
        حالة R_X86_64_TPOFF64:
            أرجع NO_GOTPLT_ثبت;
    }

    أرجع -1;
}

#که_تعریف_شوی NEED_BUILD_GOT
ST_FUNC بینښه create_plt_ثبت(TCCState *s1, بینښه got_دننه_واټن, بنية sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    صحيح modrm;
    بینښه plt_دننه_واټن, relofs;

    modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    إذا (plt->معلومات_دننه_واټن == 0) {
        p = section_ptr_جمع_کړه(plt, 16);
        p[0] = 0xff; /* pushl got + PTR_SIZE */
        p[1] = modrm + 0x10;
        write32le(p + 2, PTR_اندازه);
        p[6] = 0xff; /* jmp *(got + PTR_SIZE * 2) */
        p[7] = modrm;
        write32le(p + 8, PTR_اندازه * 2);
    }
    plt_دننه_واټن = plt->معلومات_دننه_واټن;

    /* The PLT slot refers to the relocation entry it needs via offset.
       The reloc entry is created below, so its offset is the current
       data_offset */
    relofs = s1->plt->reloc ? s1->plt->reloc->معلومات_دننه_واټن : 0;

    /* Jump to GOT entry where ld.so initially put the address of ip + 4 */
    p = section_ptr_جمع_کړه(plt, 16);
    p[0] = 0xff; /* jmp *(got + x) */
    p[1] = modrm;
    write32le(p + 2, got_دننه_واټن);
    p[6] = 0x68; /* push $xxx */
    /* On x86-64, the relocation is referred to by _index_ */
    write32le(p + 7, relofs / حجم (ElfW_Rel) - 1);
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->معلومات_دننه_واټن));
    أرجع plt_دننه_واټن;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC فراغ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_پای_ټکی;

    إذا (!s1->plt)
      أرجع;

    p = s1->plt->معلومات;
    p_پای_ټکی = p + s1->plt->معلومات_دننه_واټن;

    إذا (p < p_پای_ټکی) {
        صحيح x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        طالما (p < p_پای_ټکی) {
            add32le(p + 2, x + (s1->plt->معلومات - p));
            p += 16;
        }
    }

    إذا (s1->plt->reloc) {
        ElfW_Rel *rel;
        صحيح x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->معلومات;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_دننه_واټن, x);
            x += 16;
        }
    }
}
#د_که_پای
#د_که_پای

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, بینښه حرف *ptr, addr_t addr, addr_t val)
{
    صحيح sym_شاخص, esym_شاخص;

    sym_شاخص = ELFW(R_SYM)(rel->r_info);

    بدل (type) {
        حالة R_X86_64_64:
            إذا (s1->output_type & TCC_OUTPUT_DYN) {
                esym_شاخص = get_sym_attr(s1, sym_شاخص, 0)->dyn_شاخص;
                qrel->r_دننه_واټن = rel->r_دننه_واټن;
                إذا (esym_شاخص) {
                    qrel->r_info = ELFW(R_INFO)(esym_شاخص, R_X86_64_64);
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
            إذا (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_دننه_واټن = rel->r_دننه_واټن;
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (صحيح)read32le(ptr) + val;
                qrel++;
            }
            إذا ((type == R_X86_64_32 ? val != (بینښه)val : val != (صحيح)val)
                /* ignore relocation check for stab section */
                && (stab_section == عدم ||
                    addr < stab_section->sh_addr ||
                    addr >= (stab_section->sh_addr + stab_section->معلومات_دننه_واټن))) {
                tcc_error_noabort("relocation 'R_X86_64_32[S]' out of range");
            }
            add32le(ptr, val);
            اكسر;

        حالة R_X86_64_PC32:
            إذا (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_شاخص = get_sym_attr(s1, sym_شاخص, 0)->dyn_شاخص;
                إذا (esym_شاخص) {
                    qrel->r_دننه_واټن = rel->r_دننه_واټن;
                    qrel->r_info = ELFW(R_INFO)(esym_شاخص, R_X86_64_PC32);
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
            اوږد اوږد diff;
            diff = (اوږد اوږد)val - addr;
            إذا (diff < -2147483648LL || diff > 2147483647LL) {
#که_تعریف_شوی TCC_موخه_PE
              /* ignore overflow with undefined weak symbols */
              إذا (((ElfW(Sym)*)symtab_section->معلومات)[sym_شاخص].st_shndx != SHN_UNDEF)
#د_که_پای
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
            إذا (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_شاخص = get_sym_attr(s1, sym_شاخص, 0)->dyn_شاخص;
                إذا (esym_شاخص) {
                    qrel->r_دننه_واټن = rel->r_دننه_واټن;
                    qrel->r_info = ELFW(R_INFO)(esym_شاخص, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    اكسر;
                }
            }
            add64le(ptr, val - addr);
            اكسر;

        حالة R_X86_64_GLOB_DAT:
        حالة R_X86_64_JUMP_خونه:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            اكسر;
        حالة R_X86_64_GOTPCREL:
        حالة R_X86_64_GOTPCRELX:
        حالة R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         get_sym_attr(s1, sym_شاخص, 0)->got_دننه_واټن - 4);
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
            add32le(ptr, get_sym_attr(s1, sym_شاخص, 0)->got_دننه_واټن);
            اكسر;
        حالة R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, get_sym_attr(s1, sym_شاخص, 0)->got_دننه_واټن);
            اكسر;
        حالة R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            اكسر;
        حالة R_X86_64_TLSGD:
            {
                ساكن ثابت بینښه حرف expect[] = {
                    /* .byte 0x66; lea 0(%rip),%rdi */
                    0x66, 0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* .word 0x6666; rex64; call __tls_get_addr@PLT */
                    0x66, 0x66, 0x48, 0xe8, 0x00, 0x00, 0x00, 0x00 };
                ساكن ثابت بینښه حرف replace[] = {
                    /* mov %fs:0,%rax */
                    0x64, 0x48, 0x8b, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
                    /* lea -4(%rax),%rax */
                    0x48, 0x8d, 0x80, 0x00, 0x00, 0x00, 0x00 };

                إذا (memcmp (ptr-4, expect, حجم(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    حافظه_نقل(ptr-4, replace, حجم(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_ارزښت - sec->sh_addr - sec->معلومات_دننه_واټن;
                    add32le(ptr + 8, x);
                }
                وإلا
                    tcc_error_noabort("unexpected R_X86_64_TLSGD pattern");
            }
            اكسر;
        حالة R_X86_64_TLSLD:
            {
                ساكن ثابت بینښه حرف expect[] = {
                    /* lea 0(%rip),%rdi */
                    0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0x00, 0x00, 0x00, 0x00 };
                ساكن ثابت بینښه حرف replace[] = {
                    /* data16 data16 data16 mov %fs:0,%rax */
                    0x66, 0x66, 0x66, 0x64, 0x48, 0x8b, 0x04, 0x25,
                    0x00, 0x00, 0x00, 0x00 };

                إذا (memcmp (ptr-3, expect, حجم(expect)) == 0) {
                    حافظه_نقل(ptr-3, replace, حجم(replace));
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
                إذا (s1->tls_پای_ټکی) {
                    x = val - s1->tls_پای_ټکی;
                } وإلا {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->معلومات_دننه_واټن;
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
#که_تعریف_شوی TCC_موخه_PE
            add32le(ptr, val - s1->pe_imagebase);
#د_که_پای
            /* do nothing */
            اكسر;
        افتراضي:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (بینښه)addr, ptr, (بینښه)val);
            اكسر;
    }
}

#د_که_پای /* !TARGET_DEFS_ONLY */
