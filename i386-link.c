#جے_تعریف_شدہ نشانہ_DEFS_ONLY

#تعریف_کرو EM_TCC_نشانہ EM_386

/* relocation type for 32 bit data relocation */
#تعریف_کرو R_انکڑے_32   R_386_32
#تعریف_کرو R_انکڑے_PTR  R_386_32
#تعریف_کرو R_JMP_تھاں  R_386_JMP_تھاں
#تعریف_کرو R_GLOB_DAT  R_386_GLOB_DAT
#تعریف_کرو R_COPY      R_386_COPY
#تعریف_کرو R_RELATIVE  R_386_RELATIVE

#تعریف_کرو R_عدد       R_386_عدد

#تعریف_کرو ELF_شروع_ADDR 0x08048000
#تعریف_کرو ELF_ورقہ_ناپ  0x1000

#إذا defined CONFIG_TCC_PIC
#تعریف_کرو PCRELATIVE_DLLPLT 1
#وإلا
#تعریف_کرو PCRELATIVE_DLLPLT 0
#جے_انت
#تعریف_کرو RELOCATE_DLLPLT 1

#وإلا /* !TARGET_DEFS_ONLY */

#ضمن "tcc.h"

#جے_تعریف_شدہ NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحيح کوڈ_reloc (صحيح reloc_type)
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
	حالة R_386_JMP_تھاں:
            أرجع 1;
    }
    أرجع -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC صحيح gotplt_اندراج_type (صحيح reloc_type)
{
    بدل (reloc_type) {
	حالة R_386_RELATIVE:
	حالة R_386_16:
	حالة R_386_GLOB_DAT:
	حالة R_386_JMP_تھاں:
	حالة R_386_COPY:
            أرجع NO_GOTPLT_اندراج;

        حالة R_386_32:
	    /* This relocations shouldn't normally need GOT or PLT
	       slots if it weren't for simplicity in the code generator.
	       See our caller for comments.  */
            أرجع AUTO_GOTPLT_اندراج;

	حالة R_386_PC16:
	حالة R_386_PC32:
            أرجع AUTO_GOTPLT_اندراج;

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
            أرجع ALWAYS_GOTPLT_اندراج;
    }
    أرجع -1;
}

#جے_تعریف_شدہ NEED_BUILD_GOT
ST_FUNC بنانشانی create_plt_اندراج(TCCState *s1, بنانشانی got_وتھ, بنية sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    صحيح modrm;
    بنانشانی plt_وتھ, relofs;

    /* on i386 if we build a DLL, we add a %ebx offset */
    إذا (s1->output_type & TCC_OUTPUT_DYN)
        modrm = 0xa3;
    وإلا
        modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    إذا (plt->انکڑے_وتھ == 0) {
        p = section_ptr_جوڑو(plt, 16);
        p[0] = 0xff; /* pushl got + PTR_SIZE */
        p[1] = modrm + 0x10;
        write32le(p + 2, PTR_ناپ);
        p[6] = 0xff; /* jmp *(got + PTR_SIZE * 2) */
        p[7] = modrm;
        write32le(p + 8, PTR_ناپ * 2);
    }
    plt_وتھ = plt->انکڑے_وتھ;

    /* The PLT slot refers to the relocation entry it needs via offset.
       The reloc entry is created below, so its offset is the current
       data_offset */
    relofs = s1->plt->reloc ? s1->plt->reloc->انکڑے_وتھ : 0;

    /* Jump to GOT entry where ld.so initially put the address of ip + 4 */
    p = section_ptr_جوڑو(plt, 16);
    p[0] = 0xff; /* jmp *(got + x) */
    p[1] = modrm;
    write32le(p + 2, got_وتھ);
    p[6] = 0x68; /* push $xxx */
    write32le(p + 7, relofs - حجم (ElfW_Rel));
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->انکڑے_وتھ));
    أرجع plt_وتھ;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC فراغ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_سرا;

    إذا (!s1->plt)
      أرجع;

    p = s1->plt->انکڑے;
    p_سرا = p + s1->plt->انکڑے_وتھ;

    إذا (!(s1->output_type & TCC_OUTPUT_DYN) && p < p_سرا) {
        add32le(p + 2, s1->got->sh_addr);
        add32le(p + 8, s1->got->sh_addr);
        p += 16;
        طالما (p < p_سرا) {
            add32le(p + 2, s1->got->sh_addr);
            p += 16;
        }
    }

    إذا (s1->plt->reloc) {
        ElfW_Rel *rel;
        صحيح x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->انکڑے;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_وتھ, x);
            x += 16;
        }
    }
}
#جے_انت
#جے_انت

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, بنانشانی حرف *ptr, addr_t addr, addr_t val)
{
    صحيح sym_اشاریہ, esym_اشاریہ;

    sym_اشاریہ = ELFW(R_SYM)(rel->r_info);

    بدل (type) {
        حالة R_386_32:
            إذا (s1->output_type & TCC_OUTPUT_DYN) {
                esym_اشاریہ = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
                qrel->r_وتھ = rel->r_وتھ;
                إذا (esym_اشاریہ) {
                    qrel->r_info = ELFW(R_INFO)(esym_اشاریہ, R_386_32);
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
                esym_اشاریہ = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
                إذا (esym_اشاریہ) {
                    qrel->r_وتھ = rel->r_وتھ;
                    qrel->r_info = ELFW(R_INFO)(esym_اشاریہ, R_386_PC32);
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
        حالة R_386_JMP_تھاں:
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
            add32le(ptr, get_sym_attr(s1, sym_اشاریہ, 0)->got_وتھ);
            أرجع;
        حالة R_386_16:
            إذا (s1->output_format != TCC_OUTPUT_FORMAT_ثنائی) {
            output_file:
                tcc_error_noabort("can only produce 16-bit binary files");
            }
            write16le(ptr, read16le(ptr) + val);
            أرجع;
        حالة R_386_PC16:
            إذا (s1->output_format != TCC_OUTPUT_FORMAT_ثنائی)
                اذهب output_file;
            write16le(ptr, read16le(ptr) + val - addr);
            أرجع;
        حالة R_386_RELATIVE:
#جے_تعریف_شدہ TCC_نشانہ_PE
            add32le(ptr, val - s1->pe_imagebase);
#جے_انت
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
                ساكن ثابت بنانشانی حرف expect[] = {
                    /* lea 0(,%ebx,1),%eax */
                    0x8d, 0x04, 0x1d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                ساكن ثابت بنانشانی حرف replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* sub 0,%eax */
                    0x81, 0xe8, 0x00, 0x00, 0x00, 0x00 };

                إذا (memcmp (ptr-3, expect, حجم(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    حافظہ_نقل(ptr-3, replace, حجم(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->انکڑے)[sym_اشاریہ];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_قدر - sec->sh_addr - sec->انکڑے_وتھ;
                    add32le(ptr + 5, -x);
                }
                وإلا
                    tcc_error_noabort("unexpected R_386_TLS_GD pattern");
            }
            أرجع;
        حالة R_386_TLS_LDM:
            {
                ساكن ثابت بنانشانی حرف expect[] = {
                    /* lea 0(%ebx),%eax */
                    0x8d, 0x83, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                ساكن ثابت بنانشانی حرف replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* nop */
                    0x90,
                    /* lea 0(%esi,%eiz,1),%esi */
                    0x8d, 0x74, 0x26, 0x00 };

                إذا (memcmp (ptr-2, expect, حجم(expect)) == 0) {
                    حافظہ_نقل(ptr-2, replace, حجم(replace));
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

                sym = &((ElfW(Sym) *)symtab_section->انکڑے)[sym_اشاریہ];
                sec = s1->sections[sym->st_shndx];
                x = val - sec->sh_addr - sec->انکڑے_وتھ;
                add32le(ptr, x);
            }
            أرجع;
        حالة R_386_TLS_LE:
            {
                int32_t x;
                إذا (s1->tls_سرا) {
                    x = val - s1->tls_سرا;
                } وإلا {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->انکڑے)[sym_اشاریہ];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->انکڑے_وتھ;
                }
                add32le(ptr, x);
            }
            أرجع;
        حالة R_386_NONE:
            أرجع;
        افتراضي:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (بنانشانی)addr, ptr, (بنانشانی)val);
            أرجع;
    }
}

#جے_انت /* !TARGET_DEFS_ONLY */
