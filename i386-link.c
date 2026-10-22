#اگر_تعریف_شدہ ہدف_DEFS_ONLY

#تعریف_کرو EM_TCC_ہدف EM_386

/* relocation type for 32 bit data relocation */
#تعریف_کرو R_ڈیٹا_32   R_386_32
#تعریف_کرو R_ڈیٹا_PTR  R_386_32
#تعریف_کرو R_JMP_خانہ  R_386_JMP_خانہ
#تعریف_کرو R_GLOB_DAT  R_386_GLOB_DAT
#تعریف_کرو R_COPY      R_386_COPY
#تعریف_کرو R_RELATIVE  R_386_RELATIVE

#تعریف_کرو R_عدد       R_386_عدد

#تعریف_کرو ELF_آغاز_ADDR 0x08048000
#تعریف_کرو ELF_صفحہ_سائز  0x1000

#اگر defined CONFIG_TCC_PIC
#تعریف_کرو PCRELATIVE_DLLPLT 1
#ورنہ
#تعریف_کرو PCRELATIVE_DLLPLT 0
#اگر_ختم
#تعریف_کرو RELOCATE_DLLPLT 1

#ورنہ /* !TARGET_DEFS_ONLY */

#شامل "tcc.h"

#اگر_تعریف_شدہ NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحیح رمز_reloc (صحیح reloc_type)
{
    انتخاب (reloc_type) {
	حالت R_386_RELATIVE:
	حالت R_386_16:
        حالت R_386_32:
	حالت R_386_GOTPC:
	حالت R_386_GOTOFF:
	حالت R_386_GOT32:
	حالت R_386_GOT32X:
	حالت R_386_GLOB_DAT:
	حالت R_386_COPY:
	حالت R_386_TLS_GD:
	حالت R_386_TLS_LDM:
	حالت R_386_TLS_LDO_32:
	حالت R_386_TLS_LE:
            واپس 0;

	حالت R_386_PC16:
	حالت R_386_PC32:
	حالت R_386_PLT32:
	حالت R_386_JMP_خانہ:
            واپس 1;
    }
    واپس -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC صحیح gotplt_اندراج_type (صحیح reloc_type)
{
    انتخاب (reloc_type) {
	حالت R_386_RELATIVE:
	حالت R_386_16:
	حالت R_386_GLOB_DAT:
	حالت R_386_JMP_خانہ:
	حالت R_386_COPY:
            واپس NO_GOTPLT_اندراج;

        حالت R_386_32:
	    /* This relocations shouldn't normally need GOT or PLT
	       slots if it weren't for simplicity in the code generator.
	       See our caller for comments.  */
            واپس AUTO_GOTPLT_اندراج;

	حالت R_386_PC16:
	حالت R_386_PC32:
            واپس AUTO_GOTPLT_اندراج;

	حالت R_386_GOTPC:
	حالت R_386_GOTOFF:
            واپس BUILD_GOT_ONLY;

	حالت R_386_GOT32:
	حالت R_386_GOT32X:
	حالت R_386_PLT32:
	حالت R_386_TLS_GD:
	حالت R_386_TLS_LDM:
	حالت R_386_TLS_LDO_32:
	حالت R_386_TLS_LE:
            واپس ALWAYS_GOTPLT_اندراج;
    }
    واپس -1;
}

#اگر_تعریف_شدہ NEED_BUILD_GOT
ST_FUNC غیرعلامتی create_plt_اندراج(TCCState *s1, غیرعلامتی got_انحراف, ساخت sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    صحیح modrm;
    غیرعلامتی plt_انحراف, relofs;

    /* on i386 if we build a DLL, we add a %ebx offset */
    اگر (s1->output_type & TCC_OUTPUT_DYN)
        modrm = 0xa3;
    ورنہ
        modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    اگر (plt->ڈیٹا_انحراف == 0) {
        p = section_ptr_جوڑو(plt, 16);
        p[0] = 0xff; /* pushl got + PTR_SIZE */
        p[1] = modrm + 0x10;
        write32le(p + 2, PTR_سائز);
        p[6] = 0xff; /* jmp *(got + PTR_SIZE * 2) */
        p[7] = modrm;
        write32le(p + 8, PTR_سائز * 2);
    }
    plt_انحراف = plt->ڈیٹا_انحراف;

    /* The PLT slot refers to the relocation entry it needs via offset.
       The reloc entry is created below, so its offset is the current
       data_offset */
    relofs = s1->plt->reloc ? s1->plt->reloc->ڈیٹا_انحراف : 0;

    /* Jump to GOT entry where ld.so initially put the address of ip + 4 */
    p = section_ptr_جوڑو(plt, 16);
    p[0] = 0xff; /* jmp *(got + x) */
    p[1] = modrm;
    write32le(p + 2, got_انحراف);
    p[6] = 0x68; /* push $xxx */
    write32le(p + 7, relofs - حجم (ElfW_Rel));
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->ڈیٹا_انحراف));
    واپس plt_انحراف;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC خالی relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_انتہا;

    اگر (!s1->plt)
      واپس;

    p = s1->plt->ڈیٹا;
    p_انتہا = p + s1->plt->ڈیٹا_انحراف;

    اگر (!(s1->output_type & TCC_OUTPUT_DYN) && p < p_انتہا) {
        add32le(p + 2, s1->got->sh_addr);
        add32le(p + 8, s1->got->sh_addr);
        p += 16;
        جب (p < p_انتہا) {
            add32le(p + 2, s1->got->sh_addr);
            p += 16;
        }
    }

    اگر (s1->plt->reloc) {
        ElfW_Rel *rel;
        صحیح x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->ڈیٹا;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_انحراف, x);
            x += 16;
        }
    }
}
#اگر_ختم
#اگر_ختم

ST_FUNC خالی relocate(TCCState *s1, ElfW_Rel *rel, صحیح type, غیرعلامتی حرف *ptr, addr_t addr, addr_t val)
{
    صحیح sym_اشاریہ, esym_اشاریہ;

    sym_اشاریہ = ELFW(R_SYM)(rel->r_info);

    انتخاب (type) {
        حالت R_386_32:
            اگر (s1->output_type & TCC_OUTPUT_DYN) {
                esym_اشاریہ = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
                qrel->r_انحراف = rel->r_انحراف;
                اگر (esym_اشاریہ) {
                    qrel->r_info = ELFW(R_INFO)(esym_اشاریہ, R_386_32);
                    qrel++;
                    واپس;
                } ورنہ {
                    qrel->r_info = ELFW(R_INFO)(0, R_386_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            واپس;
        حالت R_386_PC32:
            اگر (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_اشاریہ = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
                اگر (esym_اشاریہ) {
                    qrel->r_انحراف = rel->r_انحراف;
                    qrel->r_info = ELFW(R_INFO)(esym_اشاریہ, R_386_PC32);
                    qrel++;
                    واپس;
                }
            }
            add32le(ptr, val - addr);
            واپس;
        حالت R_386_PLT32:
            add32le(ptr, val - addr);
            واپس;
        حالت R_386_GLOB_DAT:
        حالت R_386_JMP_خانہ:
            write32le(ptr, val);
            واپس;
        حالت R_386_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            واپس;
        حالت R_386_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            واپس;
        حالت R_386_GOT32:
        حالت R_386_GOT32X:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_اشاریہ, 0)->got_انحراف);
            واپس;
        حالت R_386_16:
            اگر (s1->output_format != TCC_OUTPUT_FORMAT_ثنائی) {
            output_file:
                tcc_error_noabort("can only produce 16-bit binary files");
            }
            write16le(ptr, read16le(ptr) + val);
            واپس;
        حالت R_386_PC16:
            اگر (s1->output_format != TCC_OUTPUT_FORMAT_ثنائی)
                جاؤ output_file;
            write16le(ptr, read16le(ptr) + val - addr);
            واپس;
        حالت R_386_RELATIVE:
#اگر_تعریف_شدہ TCC_ہدف_PE
            add32le(ptr, val - s1->pe_imagebase);
#اگر_ختم
            /* do nothing */
            واپس;
        حالت R_386_COPY:
            /* This relocation must copy initialized data from the library
            to the program .bss segment. Currently made like for ARM
            (to remove noise of default case). Is this true?
            */
            واپس;
        حالت R_386_TLS_GD:
            {
                ساکن ثابت غیرعلامتی حرف expect[] = {
                    /* lea 0(,%ebx,1),%eax */
                    0x8d, 0x04, 0x1d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                ساکن ثابت غیرعلامتی حرف replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* sub 0,%eax */
                    0x81, 0xe8, 0x00, 0x00, 0x00, 0x00 };

                اگر (memcmp (ptr-3, expect, حجم(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    حافظہ_نقل(ptr-3, replace, حجم(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_قدر - sec->sh_addr - sec->ڈیٹا_انحراف;
                    add32le(ptr + 5, -x);
                }
                ورنہ
                    tcc_error_noabort("unexpected R_386_TLS_GD pattern");
            }
            واپس;
        حالت R_386_TLS_LDM:
            {
                ساکن ثابت غیرعلامتی حرف expect[] = {
                    /* lea 0(%ebx),%eax */
                    0x8d, 0x83, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                ساکن ثابت غیرعلامتی حرف replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* nop */
                    0x90,
                    /* lea 0(%esi,%eiz,1),%esi */
                    0x8d, 0x74, 0x26, 0x00 };

                اگر (memcmp (ptr-2, expect, حجم(expect)) == 0) {
                    حافظہ_نقل(ptr-2, replace, حجم(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                }
                ورنہ
                    tcc_error_noabort("unexpected R_386_TLS_LDM pattern");
            }
            واپس;
        حالت R_386_TLS_LDO_32:
            {
                ElfW(Sym) *sym;
                Section *sec;
                int32_t x;

                sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
                sec = s1->sections[sym->st_shndx];
                x = val - sec->sh_addr - sec->ڈیٹا_انحراف;
                add32le(ptr, x);
            }
            واپس;
        حالت R_386_TLS_LE:
            {
                int32_t x;
                اگر (s1->tls_انتہا) {
                    x = val - s1->tls_انتہا;
                } ورنہ {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->ڈیٹا_انحراف;
                }
                add32le(ptr, x);
            }
            واپس;
        حالت R_386_NONE:
            واپس;
        طےشدہ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (غیرعلامتی)addr, ptr, (غیرعلامتی)val);
            واپس;
    }
}

#اگر_ختم /* !TARGET_DEFS_ONLY */
