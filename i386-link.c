#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ਨਿਸ਼ਾਨਾ_DEFS_ONLY

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_TCC_ਨਿਸ਼ਾਨਾ EM_386

/* relocation type for 32 bit data relocation */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕੜੇ_32   R_386_32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕੜੇ_PTR  R_386_32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_JMP_ਥਾਂ  R_386_JMP_ਥਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_GLOB_DAT  R_386_GLOB_DAT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_COPY      R_386_COPY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_RELATIVE  R_386_RELATIVE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕ       R_386_ਅੰਕ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_ਸ਼ੁਰੂ_ADDR 0x08048000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_ਪੰਨਾ_ਮਾਪ  0x1000

#ਜੇ defined CONFIG_TCC_PIC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCRELATIVE_DLLPLT 1
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCRELATIVE_DLLPLT 0
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RELOCATE_DLLPLT 1

#ਨਹੀਂਤਾਂ /* !TARGET_DEFS_ONLY */

#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ਪੂਰਨ ਕੋਡ_reloc (ਪੂਰਨ reloc_type)
{
    ਚੋਣ (reloc_type) {
	ਹਾਲਤ R_386_RELATIVE:
	ਹਾਲਤ R_386_16:
        ਹਾਲਤ R_386_32:
	ਹਾਲਤ R_386_GOTPC:
	ਹਾਲਤ R_386_GOTOFF:
	ਹਾਲਤ R_386_GOT32:
	ਹਾਲਤ R_386_GOT32X:
	ਹਾਲਤ R_386_GLOB_DAT:
	ਹਾਲਤ R_386_COPY:
	ਹਾਲਤ R_386_TLS_GD:
	ਹਾਲਤ R_386_TLS_LDM:
	ਹਾਲਤ R_386_TLS_LDO_32:
	ਹਾਲਤ R_386_TLS_LE:
            ਵਾਪਸ 0;

	ਹਾਲਤ R_386_PC16:
	ਹਾਲਤ R_386_PC32:
	ਹਾਲਤ R_386_PLT32:
	ਹਾਲਤ R_386_JMP_ਥਾਂ:
            ਵਾਪਸ 1;
    }
    ਵਾਪਸ -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC ਪੂਰਨ gotplt_ਇੰਦਰਾਜ_type (ਪੂਰਨ reloc_type)
{
    ਚੋਣ (reloc_type) {
	ਹਾਲਤ R_386_RELATIVE:
	ਹਾਲਤ R_386_16:
	ਹਾਲਤ R_386_GLOB_DAT:
	ਹਾਲਤ R_386_JMP_ਥਾਂ:
	ਹਾਲਤ R_386_COPY:
            ਵਾਪਸ NO_GOTPLT_ਇੰਦਰਾਜ;

        ਹਾਲਤ R_386_32:
	    /* This relocations shouldn't normally need GOT or PLT
	       slots if it weren't for simplicity in the code generator.
	       See our caller for comments.  */
            ਵਾਪਸ AUTO_GOTPLT_ਇੰਦਰਾਜ;

	ਹਾਲਤ R_386_PC16:
	ਹਾਲਤ R_386_PC32:
            ਵਾਪਸ AUTO_GOTPLT_ਇੰਦਰਾਜ;

	ਹਾਲਤ R_386_GOTPC:
	ਹਾਲਤ R_386_GOTOFF:
            ਵਾਪਸ BUILD_GOT_ONLY;

	ਹਾਲਤ R_386_GOT32:
	ਹਾਲਤ R_386_GOT32X:
	ਹਾਲਤ R_386_PLT32:
	ਹਾਲਤ R_386_TLS_GD:
	ਹਾਲਤ R_386_TLS_LDM:
	ਹਾਲਤ R_386_TLS_LDO_32:
	ਹਾਲਤ R_386_TLS_LE:
            ਵਾਪਸ ALWAYS_GOTPLT_ਇੰਦਰਾਜ;
    }
    ਵਾਪਸ -1;
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ NEED_BUILD_GOT
ST_FUNC ਬਿਨਾਨਿਸ਼ਾਨੀ create_plt_ਇੰਦਰਾਜ(TCCState *s1, ਬਿਨਾਨਿਸ਼ਾਨੀ got_ਵਿੱਥ, ਬਣਤਰ sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    ਪੂਰਨ modrm;
    ਬਿਨਾਨਿਸ਼ਾਨੀ plt_ਵਿੱਥ, relofs;

    /* on i386 if we build a DLL, we add a %ebx offset */
    ਜੇ (s1->output_type & TCC_OUTPUT_DYN)
        modrm = 0xa3;
    ਨਹੀਂਤਾਂ
        modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    ਜੇ (plt->ਅੰਕੜੇ_ਵਿੱਥ == 0) {
        p = section_ptr_ਜੋੜੋ(plt, 16);
        p[0] = 0xff; /* pushl got + PTR_SIZE */
        p[1] = modrm + 0x10;
        write32le(p + 2, PTR_ਮਾਪ);
        p[6] = 0xff; /* jmp *(got + PTR_SIZE * 2) */
        p[7] = modrm;
        write32le(p + 8, PTR_ਮਾਪ * 2);
    }
    plt_ਵਿੱਥ = plt->ਅੰਕੜੇ_ਵਿੱਥ;

    /* The PLT slot refers to the relocation entry it needs via offset.
       The reloc entry is created below, so its offset is the current
       data_offset */
    relofs = s1->plt->reloc ? s1->plt->reloc->ਅੰਕੜੇ_ਵਿੱਥ : 0;

    /* Jump to GOT entry where ld.so initially put the address of ip + 4 */
    p = section_ptr_ਜੋੜੋ(plt, 16);
    p[0] = 0xff; /* jmp *(got + x) */
    p[1] = modrm;
    write32le(p + 2, got_ਵਿੱਥ);
    p[6] = 0x68; /* push $xxx */
    write32le(p + 7, relofs - ਆਕਾਰ (ElfW_Rel));
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->ਅੰਕੜੇ_ਵਿੱਥ));
    ਵਾਪਸ plt_ਵਿੱਥ;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC ਖਾਲੀ relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_ਸਿਰਾ;

    ਜੇ (!s1->plt)
      ਵਾਪਸ;

    p = s1->plt->ਅੰਕੜੇ;
    p_ਸਿਰਾ = p + s1->plt->ਅੰਕੜੇ_ਵਿੱਥ;

    ਜੇ (!(s1->output_type & TCC_OUTPUT_DYN) && p < p_ਸਿਰਾ) {
        add32le(p + 2, s1->got->sh_addr);
        add32le(p + 8, s1->got->sh_addr);
        p += 16;
        ਜਦੋਂ (p < p_ਸਿਰਾ) {
            add32le(p + 2, s1->got->sh_addr);
            p += 16;
        }
    }

    ਜੇ (s1->plt->reloc) {
        ElfW_Rel *rel;
        ਪੂਰਨ x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->ਅੰਕੜੇ;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write32le(p + rel->r_ਵਿੱਥ, x);
            x += 16;
        }
    }
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

ST_FUNC ਖਾਲੀ relocate(TCCState *s1, ElfW_Rel *rel, ਪੂਰਨ type, ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr, addr_t addr, addr_t val)
{
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ, esym_ਸੂਚਕਾਂਕ;

    sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(rel->r_info);

    ਚੋਣ (type) {
        ਹਾਲਤ R_386_32:
            ਜੇ (s1->output_type & TCC_OUTPUT_DYN) {
                esym_ਸੂਚਕਾਂਕ = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->dyn_ਸੂਚਕਾਂਕ;
                qrel->r_ਵਿੱਥ = rel->r_ਵਿੱਥ;
                ਜੇ (esym_ਸੂਚਕਾਂਕ) {
                    qrel->r_info = ELFW(R_INFO)(esym_ਸੂਚਕਾਂਕ, R_386_32);
                    qrel++;
                    ਵਾਪਸ;
                } ਨਹੀਂਤਾਂ {
                    qrel->r_info = ELFW(R_INFO)(0, R_386_RELATIVE);
                    qrel++;
                }
            }
            add32le(ptr, val);
            ਵਾਪਸ;
        ਹਾਲਤ R_386_PC32:
            ਜੇ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_ਸੂਚਕਾਂਕ = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->dyn_ਸੂਚਕਾਂਕ;
                ਜੇ (esym_ਸੂਚਕਾਂਕ) {
                    qrel->r_ਵਿੱਥ = rel->r_ਵਿੱਥ;
                    qrel->r_info = ELFW(R_INFO)(esym_ਸੂਚਕਾਂਕ, R_386_PC32);
                    qrel++;
                    ਵਾਪਸ;
                }
            }
            add32le(ptr, val - addr);
            ਵਾਪਸ;
        ਹਾਲਤ R_386_PLT32:
            add32le(ptr, val - addr);
            ਵਾਪਸ;
        ਹਾਲਤ R_386_GLOB_DAT:
        ਹਾਲਤ R_386_JMP_ਥਾਂ:
            write32le(ptr, val);
            ਵਾਪਸ;
        ਹਾਲਤ R_386_GOTPC:
            add32le(ptr, s1->got->sh_addr - addr);
            ਵਾਪਸ;
        ਹਾਲਤ R_386_GOTOFF:
            add32le(ptr, val - s1->got->sh_addr);
            ਵਾਪਸ;
        ਹਾਲਤ R_386_GOT32:
        ਹਾਲਤ R_386_GOT32X:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->got_ਵਿੱਥ);
            ਵਾਪਸ;
        ਹਾਲਤ R_386_16:
            ਜੇ (s1->output_format != TCC_OUTPUT_FORMAT_ਦੁਆਧਾਰੀ) {
            output_file:
                tcc_error_noabort("can only produce 16-bit binary files");
            }
            write16le(ptr, read16le(ptr) + val);
            ਵਾਪਸ;
        ਹਾਲਤ R_386_PC16:
            ਜੇ (s1->output_format != TCC_OUTPUT_FORMAT_ਦੁਆਧਾਰੀ)
                ਜਾਓ output_file;
            write16le(ptr, read16le(ptr) + val - addr);
            ਵਾਪਸ;
        ਹਾਲਤ R_386_RELATIVE:
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
            add32le(ptr, val - s1->pe_imagebase);
#ਜੇ_ਅੰਤ
            /* do nothing */
            ਵਾਪਸ;
        ਹਾਲਤ R_386_COPY:
            /* This relocation must copy initialized data from the library
            to the program .bss segment. Currently made like for ARM
            (to remove noise of default case). Is this true?
            */
            ਵਾਪਸ;
        ਹਾਲਤ R_386_TLS_GD:
            {
                ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ expect[] = {
                    /* lea 0(,%ebx,1),%eax */
                    0x8d, 0x04, 0x1d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* sub 0,%eax */
                    0x81, 0xe8, 0x00, 0x00, 0x00, 0x00 };

                ਜੇ (memcmp (ptr-3, expect, ਆਕਾਰ(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    ਸਮ੍ਰਿਤੀ_ਨਕਲ(ptr-3, replace, ਆਕਾਰ(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_ਮੁੱਲ - sec->sh_addr - sec->ਅੰਕੜੇ_ਵਿੱਥ;
                    add32le(ptr + 5, -x);
                }
                ਨਹੀਂਤਾਂ
                    tcc_error_noabort("unexpected R_386_TLS_GD pattern");
            }
            ਵਾਪਸ;
        ਹਾਲਤ R_386_TLS_LDM:
            {
                ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ expect[] = {
                    /* lea 0(%ebx),%eax */
                    0x8d, 0x83, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0xfc, 0xff, 0xff, 0xff };
                ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ replace[] = {
                    /* mov %gs:0,%eax */
                    0x65, 0xa1, 0x00, 0x00, 0x00, 0x00,
                    /* nop */
                    0x90,
                    /* lea 0(%esi,%eiz,1),%esi */
                    0x8d, 0x74, 0x26, 0x00 };

                ਜੇ (memcmp (ptr-2, expect, ਆਕਾਰ(expect)) == 0) {
                    ਸਮ੍ਰਿਤੀ_ਨਕਲ(ptr-2, replace, ਆਕਾਰ(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_386_NONE);
                }
                ਨਹੀਂਤਾਂ
                    tcc_error_noabort("unexpected R_386_TLS_LDM pattern");
            }
            ਵਾਪਸ;
        ਹਾਲਤ R_386_TLS_LDO_32:
            {
                ElfW(Sym) *sym;
                Section *sec;
                int32_t x;

                sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
                sec = s1->sections[sym->st_shndx];
                x = val - sec->sh_addr - sec->ਅੰਕੜੇ_ਵਿੱਥ;
                add32le(ptr, x);
            }
            ਵਾਪਸ;
        ਹਾਲਤ R_386_TLS_LE:
            {
                int32_t x;
                ਜੇ (s1->tls_ਸਿਰਾ) {
                    x = val - s1->tls_ਸਿਰਾ;
                } ਨਹੀਂਤਾਂ {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->ਅੰਕੜੇ_ਵਿੱਥ;
                }
                add32le(ptr, x);
            }
            ਵਾਪਸ;
        ਹਾਲਤ R_386_NONE:
            ਵਾਪਸ;
        ਮੂਲ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (ਬਿਨਾਨਿਸ਼ਾਨੀ)addr, ptr, (ਬਿਨਾਨਿਸ਼ਾਨੀ)val);
            ਵਾਪਸ;
    }
}

#ਜੇ_ਅੰਤ /* !TARGET_DEFS_ONLY */
