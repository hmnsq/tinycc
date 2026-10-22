#اگر_تعریف_شدہ ہدف_DEFS_ONLY

#تعریف_کرو EM_TCC_ہدف EM_X86_64

/* relocation type for 32 bit data relocation */
#تعریف_کرو R_ڈیٹا_32   R_X86_64_32S
#تعریف_کرو R_ڈیٹا_PTR  R_X86_64_64
#تعریف_کرو R_JMP_خانہ  R_X86_64_JUMP_خانہ
#تعریف_کرو R_GLOB_DAT  R_X86_64_GLOB_DAT
#تعریف_کرو R_COPY      R_X86_64_COPY
#تعریف_کرو R_RELATIVE  R_X86_64_RELATIVE

#تعریف_کرو R_عدد       R_X86_64_عدد

#تعریف_کرو ELF_آغاز_ADDR 0x400000
#تعریف_کرو ELF_صفحہ_سائز  0x1000

#تعریف_کرو PCRELATIVE_DLLPLT 1
#تعریف_کرو RELOCATE_DLLPLT 1

#ورنہ /* !TARGET_DEFS_ONLY */

#شامل "tcc.h"

#اگر_تعریف_شدہ NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC صحیح رمز_reloc (صحیح reloc_type)
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
            واپس 0;

        حالت R_X86_64_PC32:
        حالت R_X86_64_PC64:
        حالت R_X86_64_PLT32:
        حالت R_X86_64_PLTOFF64:
        حالت R_X86_64_JUMP_خانہ:
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
        حالت R_X86_64_GLOB_DAT:
        حالت R_X86_64_JUMP_خانہ:
        حالت R_X86_64_COPY:
        حالت R_X86_64_RELATIVE:
            واپس NO_GOTPLT_اندراج;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        حالت R_X86_64_32:
        حالت R_X86_64_32S:
        حالت R_X86_64_64:
        حالت R_X86_64_PC32:
        حالت R_X86_64_PC64:
            واپس AUTO_GOTPLT_اندراج;

        حالت R_X86_64_GOTTPOFF:
            واپس BUILD_GOT_ONLY;

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
            واپس ALWAYS_GOTPLT_اندراج;

        حالت R_X86_64_TPOFF32:
        حالت R_X86_64_TPOFF64:
            واپس NO_GOTPLT_اندراج;
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
    /* On x86-64, the relocation is referred to by _index_ */
    write32le(p + 7, relofs / حجم (ElfW_Rel) - 1);
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

    اگر (p < p_انتہا) {
        صحیح x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        جب (p < p_انتہا) {
            add32le(p + 2, x + (s1->plt->ڈیٹا - p));
            p += 16;
        }
    }

    اگر (s1->plt->reloc) {
        ElfW_Rel *rel;
        صحیح x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->ڈیٹا;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_انحراف, x);
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
        حالت R_X86_64_64:
            اگر (s1->output_type & TCC_OUTPUT_DYN) {
                esym_اشاریہ = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
                qrel->r_انحراف = rel->r_انحراف;
                اگر (esym_اشاریہ) {
                    qrel->r_info = ELFW(R_INFO)(esym_اشاریہ, R_X86_64_64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    توڑو;
                } ورنہ {
                    qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            توڑو;
        حالت R_X86_64_32:
        حالت R_X86_64_32S:
            اگر (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_انحراف = rel->r_انحراف;
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (صحیح)read32le(ptr) + val;
                qrel++;
            }
            اگر ((type == R_X86_64_32 ? val != (غیرعلامتی)val : val != (صحیح)val)
                /* ignore relocation check for stab section */
                && (stab_section == تہی ||
                    addr < stab_section->sh_addr ||
                    addr >= (stab_section->sh_addr + stab_section->ڈیٹا_انحراف))) {
                tcc_error_noabort("relocation 'R_X86_64_32[S]' out of range");
            }
            add32le(ptr, val);
            توڑو;

        حالت R_X86_64_PC32:
            اگر (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_اشاریہ = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
                اگر (esym_اشاریہ) {
                    qrel->r_انحراف = rel->r_انحراف;
                    qrel->r_info = ELFW(R_INFO)(esym_اشاریہ, R_X86_64_PC32);
                    /* Use sign extension! */
                    qrel->r_addend = (صحیح)read32le(ptr) + rel->r_addend;
                    qrel++;
                    توڑو;
                }
            }
            جاؤ plt32pc32;

        حالت R_X86_64_PLT32:
            /* fallthrough: val already holds the PLT slot address */

        plt32pc32:
        {
            طویل طویل diff;
            diff = (طویل طویل)val - addr;
            اگر (diff < -2147483648LL || diff > 2147483647LL) {
#اگر_تعریف_شدہ TCC_ہدف_PE
              /* ignore overflow with undefined weak symbols */
              اگر (((ElfW(Sym)*)symtab_section->ڈیٹا)[sym_اشاریہ].st_shndx != SHN_UNDEF)
#اگر_ختم
                tcc_error_noabort("relocation '%d' out of range", type);
            }
            add32le(ptr, diff);
        }
            توڑو;

        حالت R_X86_64_COPY:
	    توڑو;

        حالت R_X86_64_PLTOFF64:
            add64le(ptr, val - s1->got->sh_addr + rel->r_addend);
            توڑو;

        حالت R_X86_64_PC64:
            اگر (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_اشاریہ = get_sym_attr(s1, sym_اشاریہ, 0)->dyn_اشاریہ;
                اگر (esym_اشاریہ) {
                    qrel->r_انحراف = rel->r_انحراف;
                    qrel->r_info = ELFW(R_INFO)(esym_اشاریہ, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    توڑو;
                }
            }
            add64le(ptr, val - addr);
            توڑو;

        حالت R_X86_64_GLOB_DAT:
        حالت R_X86_64_JUMP_خانہ:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            توڑو;
        حالت R_X86_64_GOTPCREL:
        حالت R_X86_64_GOTPCRELX:
        حالت R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         get_sym_attr(s1, sym_اشاریہ, 0)->got_انحراف - 4);
            توڑو;
        حالت R_X86_64_GOTPC32:
            add32le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            توڑو;
        حالت R_X86_64_GOTPC64:
            add64le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            توڑو;
        حالت R_X86_64_GOTTPOFF:
            add32le(ptr, val - s1->got->sh_addr);
            توڑو;
        حالت R_X86_64_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_اشاریہ, 0)->got_انحراف);
            توڑو;
        حالت R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, get_sym_attr(s1, sym_اشاریہ, 0)->got_انحراف);
            توڑو;
        حالت R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            توڑو;
        حالت R_X86_64_TLSGD:
            {
                ساکن ثابت غیرعلامتی حرف expect[] = {
                    /* .byte 0x66; lea 0(%rip),%rdi */
                    0x66, 0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* .word 0x6666; rex64; call __tls_get_addr@PLT */
                    0x66, 0x66, 0x48, 0xe8, 0x00, 0x00, 0x00, 0x00 };
                ساکن ثابت غیرعلامتی حرف replace[] = {
                    /* mov %fs:0,%rax */
                    0x64, 0x48, 0x8b, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
                    /* lea -4(%rax),%rax */
                    0x48, 0x8d, 0x80, 0x00, 0x00, 0x00, 0x00 };

                اگر (memcmp (ptr-4, expect, حجم(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    حافظہ_نقل(ptr-4, replace, حجم(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_قدر - sec->sh_addr - sec->ڈیٹا_انحراف;
                    add32le(ptr + 8, x);
                }
                ورنہ
                    tcc_error_noabort("unexpected R_X86_64_TLSGD pattern");
            }
            توڑو;
        حالت R_X86_64_TLSLD:
            {
                ساکن ثابت غیرعلامتی حرف expect[] = {
                    /* lea 0(%rip),%rdi */
                    0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0x00, 0x00, 0x00, 0x00 };
                ساکن ثابت غیرعلامتی حرف replace[] = {
                    /* data16 data16 data16 mov %fs:0,%rax */
                    0x66, 0x66, 0x66, 0x64, 0x48, 0x8b, 0x04, 0x25,
                    0x00, 0x00, 0x00, 0x00 };

                اگر (memcmp (ptr-3, expect, حجم(expect)) == 0) {
                    حافظہ_نقل(ptr-3, replace, حجم(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                }
                ورنہ
                    tcc_error_noabort("unexpected R_X86_64_TLSLD pattern");
            }
            توڑو;

        حالت R_X86_64_DTPOFF32:
        حالت R_X86_64_TPOFF32:
        حالت R_X86_64_DTPOFF64:
        حالت R_X86_64_TPOFF64:
            {
                int32_t x;
                اگر (s1->tls_انتہا) {
                    x = val - s1->tls_انتہا;
                } ورنہ {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->ڈیٹا_انحراف;
                }
                انتخاب (type) {
                حالت R_X86_64_DTPOFF64:
                حالت R_X86_64_TPOFF64:
                    add64le(ptr, x);
                    توڑو;
                طےشدہ:
                    add32le(ptr, x);
                    توڑو;
                }
            }
            توڑو;
        حالت R_X86_64_NONE:
            توڑو;
        حالت R_X86_64_RELATIVE:
#اگر_تعریف_شدہ TCC_ہدف_PE
            add32le(ptr, val - s1->pe_imagebase);
#اگر_ختم
            /* do nothing */
            توڑو;
        طےشدہ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (غیرعلامتی)addr, ptr, (غیرعلامتی)val);
            توڑو;
    }
}

#اگر_ختم /* !TARGET_DEFS_ONLY */
