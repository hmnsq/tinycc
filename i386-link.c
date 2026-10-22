#که_تعریف_شوی موخه_DEFS_ONLY

#تعریف_کړه EM_TCC_موخه EM_386

/* relocation type for 32 bit data relocation */
#تعریف_کړه R_معلومات_32   R_386_32
#تعریف_کړه R_معلومات_PTR  R_386_32
#تعریف_کړه R_JMP_خونه  R_386_JMP_خونه
#تعریف_کړه R_GLOB_DAT  R_386_GLOB_DAT
#تعریف_کړه R_COPY      R_386_COPY
#تعریف_کړه R_RELATIVE  R_386_RELATIVE

#تعریف_کړه R_عدد       R_386_عدد

#تعریف_کړه ELF_پیل_ADDR 0x08048000
#تعریف_کړه ELF_پاڼه_اندازه  0x1000

#إذا defined CONFIG_TCC_PIC
#تعریف_کړه PCRELATIVE_DLLPLT 1
#وإلا
#تعریف_کړه PCRELATIVE_DLLPLT 0
#د_که_پای
#تعریف_کړه RELOCATE_DLLPLT 1

#وإلا /* !TARGET_DEFS_ONLY */

#ضمن "tcc.h"

#که_تعریف_شوی NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحيح کوډ_reloc (صحيح reloc_type)
{
    بدل (reloc_type) {
	حالة R_386_RELATIVE:
	حالة R_386_16:
        حالة R_386_32:
	حالة R_386_GOTPC:
	حالة R_386_GOTOFF:
	حالة R_386_GOT32:
	حالة R_386_GOT32X:
	حالة R_386_GLOB_DAT:
	حالة R_386_COPY:
	حالة R_386_TLS_GD:
	حالة R_386_TLS_LDM:
	حالة R_386_TLS_LDO_32:
	حالة R_386_TLS_LE:
            أرجع 0;

	حالة R_386_PC16:
	حالة R_386_PC32:
	حالة R_386_PLT32:
	حالة R_386_JMP_خونه:
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
	حالة R_386_RELATIVE:
	حالة R_386_16:
	حالة R_386_GLOB_DAT:
	حالة R_386_JMP_خونه:
	حالة R_386_COPY:
            أرجع NO_GOTPLT_ثبت;

        حالة R_386_32:
	    /* This relocations shouldn't normally need GOT or PLT
	       slots if it weren't for simplicity in the code generator.
	       See our caller for comments.  */
            أرجع AUTO_GOTPLT_ثبت;

	حالة R_386_PC16:
	حالة R_386_PC32:
            أرجع AUTO_GOTPLT_ثبت;

	حالة R_386_GOTPC:
	حالة R_386_GOTOFF:
            أرجع BUILD_GOT_ONLY;

	حالة R_386_GOT32:
	حالة R_386_GOT32X:
	حالة R_386_PLT32:
	حالة R_386_TLS_GD:
	حالة R_386_TLS_LDM:
	حالة R_386_TLS_LDO_32:
	حالة R_386_TLS_LE:
            أرجع ALWAYS_GOTPLT_ثبت;
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

    /* on i386 if we build a DLL, we add a %ebx offset */
    إذا (s1->output_type & TCC_OUTPUT_DYN)
        modrm = 0xa3;
    وإلا
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
    write32le(p + 7, relofs - حجم (ElfW_Rel));
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

    إذا (!(s1->output_type & TCC_OUTPUT_DYN) && p < p_پای_ټکی) {
        add32le(p + 2, s1->got->sh_addr);
        add32le(p + 8, s1->got->sh_addr);
        p += 16;
        طالما (p < p_پای_ټکی) {
            add32le(p + 2, s1->got->sh_addr);
            p += 16;
        }
    }

    إذا (s1->plt->reloc) {
        ElfW_Rel *rel;
        صحيح x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->معلومات;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_دننه_واټن, x);
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
        حالة R_386_32:
            إذا (s1->output_type & TCC_OUTPUT_DYN) {
                esym_شاخص = get_sym_attr(s1, sym_شاخص, 0)->dyn_شاخص;
                qrel->r_دننه_واټن = rel->r_دننه_واټن;
                إذا (esym_شاخص) {
                    qrel->r_info = ELFW(R_INFO)(esym_شاخص, R_386_32);
                    qrel++;
                    أرجع;
                } وإلا {
                    qrel->r_info = ELFW(R_INFO)(0, R_386_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            أرجع;
        حالة R_386_PC32:
            إذا (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_شاخص = get_sym_attr(s1, sym_شاخص, 0)->dyn_شاخص;
                إذا (esym_شاخص) {
                    qrel->r_دننه_واټن = rel->r_دننه_واټن;
                    qrel->r_info = ELFW(R_INFO)(esym_شاخص, R_386_PC32);
                    qrel++;
                    أرجع;
                }
            }
            add32le(ptr, val - addr);
            أرجع;
        حالة R_386_PLT32:
            add32le(ptr, val - addr);
            أرجع;
        حالة R_386_GLOB_DAT:
        حالة R_386_JMP_خونه:
            write32le(ptr, val);
            أرجع;
        حالة R_386_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            أرجع;
        حالة R_386_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            أرجع;
        حالة R_386_GOT32:
        حالة R_386_GOT32X:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_شاخص, 0)->got_دننه_واټن);
            أرجع;
        حالة R_386_16:
            إذا (s1->output_format != TCC_OUTPUT_FORMAT_دوګونی) {
            output_file:
                tcc_error_noabort("can only produce 16-bit binary files");
            }
            write16le(ptr, read16le(ptr) + val);
            أرجع;
        حالة R_386_PC16:
            إذا (s1->output_format != TCC_OUTPUT_FORMAT_دوګونی)
                اذهب output_file;
            write16le(ptr, read16le(ptr) + val - addr);
            أرجع;
        حالة R_386_RELATIVE:
#که_تعریف_شوی TCC_موخه_PE
            add32le(ptr, val - s1->pe_imagebase);
#د_که_پای
            /* do nothing */
            أرجع;
        حالة R_386_COPY:
            /* This relocation must copy initialized data from the library
            to the program .bss segment. Currently made like for ARM
            (to remove noise of default case). Is this true?
            */
            أرجع;
        حالة R_386_TLS_GD:
            {
                ساكن ثابت بینښه حرف expect[] = {
                    /* lea 0(,%ebx,1),%eax */
                    0x8d, 0x04, 0x1d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                ساكن ثابت بینښه حرف replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* sub 0,%eax */
                    0x81, 0xe8, 0x00, 0x00, 0x00, 0x00 };

                إذا (memcmp (ptr-3, expect, حجم(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    حافظه_نقل(ptr-3, replace, حجم(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_ارزښت - sec->sh_addr - sec->معلومات_دننه_واټن;
                    add32le(ptr + 5, -x);
                }
                وإلا
                    tcc_error_noabort("unexpected R_386_TLS_GD pattern");
            }
            أرجع;
        حالة R_386_TLS_LDM:
            {
                ساكن ثابت بینښه حرف expect[] = {
                    /* lea 0(%ebx),%eax */
                    0x8d, 0x83, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                ساكن ثابت بینښه حرف replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* nop */
                    0x90,
                    /* lea 0(%esi,%eiz,1),%esi */
                    0x8d, 0x74, 0x26, 0x00 };

                إذا (memcmp (ptr-2, expect, حجم(expect)) == 0) {
                    حافظه_نقل(ptr-2, replace, حجم(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                }
                وإلا
                    tcc_error_noabort("unexpected R_386_TLS_LDM pattern");
            }
            أرجع;
        حالة R_386_TLS_LDO_32:
            {
                ElfW(Sym) *sym;
                Section *sec;
                int32_t x;

                sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
                sec = s1->sections[sym->st_shndx];
                x = val - sec->sh_addr - sec->معلومات_دننه_واټن;
                add32le(ptr, x);
            }
            أرجع;
        حالة R_386_TLS_LE:
            {
                int32_t x;
                إذا (s1->tls_پای_ټکی) {
                    x = val - s1->tls_پای_ټکی;
                } وإلا {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->معلومات_دننه_واټن;
                }
                add32le(ptr, x);
            }
            أرجع;
        حالة R_386_NONE:
            أرجع;
        افتراضي:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (بینښه)addr, ptr, (بینښه)val);
            أرجع;
    }
}

#د_که_پای /* !TARGET_DEFS_ONLY */
