#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ਨਿਸ਼ਾਨਾ_DEFS_ONLY

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_TCC_ਨਿਸ਼ਾਨਾ EM_X86_64

/* relocation type for 32 bit data relocation */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕੜੇ_32   R_X86_64_32S
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕੜੇ_PTR  R_X86_64_64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_JMP_ਥਾਂ  R_X86_64_JUMP_ਥਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_GLOB_DAT  R_X86_64_GLOB_DAT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_COPY      R_X86_64_COPY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_RELATIVE  R_X86_64_RELATIVE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ਅੰਕ       R_X86_64_ਅੰਕ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_ਸ਼ੁਰੂ_ADDR 0x400000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_ਪੰਨਾ_ਮਾਪ  0x1000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCRELATIVE_DLLPLT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RELOCATE_DLLPLT 1

#ਨਹੀਂਤਾਂ /* !TARGET_DEFS_ONLY */

#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC ਪੂਰਨ ਕੋਡ_reloc (ਪੂਰਨ reloc_type)
{
    ਚੋਣ (reloc_type) {
        ਹਾਲਤ R_X86_64_32:
        ਹਾਲਤ R_X86_64_32S:
        ਹਾਲਤ R_X86_64_64:
        ਹਾਲਤ R_X86_64_GOTPC32:
        ਹਾਲਤ R_X86_64_GOTPC64:
        ਹਾਲਤ R_X86_64_GOTPCREL:
        ਹਾਲਤ R_X86_64_GOTPCRELX:
        ਹਾਲਤ R_X86_64_REX_GOTPCRELX:
        ਹਾਲਤ R_X86_64_GOTTPOFF:
        ਹਾਲਤ R_X86_64_GOT32:
        ਹਾਲਤ R_X86_64_GOT64:
        ਹਾਲਤ R_X86_64_GLOB_DAT:
        ਹਾਲਤ R_X86_64_COPY:
        ਹਾਲਤ R_X86_64_RELATIVE:
        ਹਾਲਤ R_X86_64_GOTOFF64:
        ਹਾਲਤ R_X86_64_TLSGD:
        ਹਾਲਤ R_X86_64_TLSLD:
        ਹਾਲਤ R_X86_64_DTPOFF32:
        ਹਾਲਤ R_X86_64_TPOFF32:
        ਹਾਲਤ R_X86_64_DTPOFF64:
        ਹਾਲਤ R_X86_64_TPOFF64:
            ਵਾਪਸ 0;

        ਹਾਲਤ R_X86_64_PC32:
        ਹਾਲਤ R_X86_64_PC64:
        ਹਾਲਤ R_X86_64_PLT32:
        ਹਾਲਤ R_X86_64_PLTOFF64:
        ਹਾਲਤ R_X86_64_JUMP_ਥਾਂ:
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
        ਹਾਲਤ R_X86_64_GLOB_DAT:
        ਹਾਲਤ R_X86_64_JUMP_ਥਾਂ:
        ਹਾਲਤ R_X86_64_COPY:
        ਹਾਲਤ R_X86_64_RELATIVE:
            ਵਾਪਸ NO_GOTPLT_ਇੰਦਰਾਜ;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        ਹਾਲਤ R_X86_64_32:
        ਹਾਲਤ R_X86_64_32S:
        ਹਾਲਤ R_X86_64_64:
        ਹਾਲਤ R_X86_64_PC32:
        ਹਾਲਤ R_X86_64_PC64:
            ਵਾਪਸ AUTO_GOTPLT_ਇੰਦਰਾਜ;

        ਹਾਲਤ R_X86_64_GOTTPOFF:
            ਵਾਪਸ BUILD_GOT_ONLY;

        ਹਾਲਤ R_X86_64_GOT32:
        ਹਾਲਤ R_X86_64_GOT64:
        ਹਾਲਤ R_X86_64_GOTPC32:
        ਹਾਲਤ R_X86_64_GOTPC64:
        ਹਾਲਤ R_X86_64_GOTOFF64:
        ਹਾਲਤ R_X86_64_GOTPCREL:
        ਹਾਲਤ R_X86_64_GOTPCRELX:
        ਹਾਲਤ R_X86_64_TLSGD:
        ਹਾਲਤ R_X86_64_TLSLD:
        ਹਾਲਤ R_X86_64_DTPOFF32:
        ਹਾਲਤ R_X86_64_DTPOFF64:
        ਹਾਲਤ R_X86_64_REX_GOTPCRELX:
        ਹਾਲਤ R_X86_64_PLT32:
        ਹਾਲਤ R_X86_64_PLTOFF64:
            ਵਾਪਸ ALWAYS_GOTPLT_ਇੰਦਰਾਜ;

        ਹਾਲਤ R_X86_64_TPOFF32:
        ਹਾਲਤ R_X86_64_TPOFF64:
            ਵਾਪਸ NO_GOTPLT_ਇੰਦਰਾਜ;
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
    /* On x86-64, the relocation is referred to by _index_ */
    write32le(p + 7, relofs / ਆਕਾਰ (ElfW_Rel) - 1);
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

    ਜੇ (p < p_ਸਿਰਾ) {
        ਪੂਰਨ x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        ਜਦੋਂ (p < p_ਸਿਰਾ) {
            add32le(p + 2, x + (s1->plt->ਅੰਕੜੇ - p));
            p += 16;
        }
    }

    ਜੇ (s1->plt->reloc) {
        ElfW_Rel *rel;
        ਪੂਰਨ x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->ਅੰਕੜੇ;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_ਵਿੱਥ, x);
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
        ਹਾਲਤ R_X86_64_64:
            ਜੇ (s1->output_type & TCC_OUTPUT_DYN) {
                esym_ਸੂਚਕਾਂਕ = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->dyn_ਸੂਚਕਾਂਕ;
                qrel->r_ਵਿੱਥ = rel->r_ਵਿੱਥ;
                ਜੇ (esym_ਸੂਚਕਾਂਕ) {
                    qrel->r_info = ELFW(R_INFO)(esym_ਸੂਚਕਾਂਕ, R_X86_64_64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    ਰੋਕੋ;
                } ਨਹੀਂਤਾਂ {
                    qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            ਰੋਕੋ;
        ਹਾਲਤ R_X86_64_32:
        ਹਾਲਤ R_X86_64_32S:
            ਜੇ (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_ਵਿੱਥ = rel->r_ਵਿੱਥ;
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (ਪੂਰਨ)read32le(ptr) + val;
                qrel++;
            }
            ਜੇ ((type == R_X86_64_32 ? val != (ਬਿਨਾਨਿਸ਼ਾਨੀ)val : val != (ਪੂਰਨ)val)
                /* ignore relocation check for stab section */
                && (stab_section == ਨਿਰਾ ||
                    addr < stab_section->sh_addr ||
                    addr >= (stab_section->sh_addr + stab_section->ਅੰਕੜੇ_ਵਿੱਥ))) {
                tcc_error_noabort("relocation 'R_X86_64_32[S]' out of range");
            }
            add32le(ptr, val);
            ਰੋਕੋ;

        ਹਾਲਤ R_X86_64_PC32:
            ਜੇ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_ਸੂਚਕਾਂਕ = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->dyn_ਸੂਚਕਾਂਕ;
                ਜੇ (esym_ਸੂਚਕਾਂਕ) {
                    qrel->r_ਵਿੱਥ = rel->r_ਵਿੱਥ;
                    qrel->r_info = ELFW(R_INFO)(esym_ਸੂਚਕਾਂਕ, R_X86_64_PC32);
                    /* Use sign extension! */
                    qrel->r_addend = (ਪੂਰਨ)read32le(ptr) + rel->r_addend;
                    qrel++;
                    ਰੋਕੋ;
                }
            }
            ਜਾਓ plt32pc32;

        ਹਾਲਤ R_X86_64_PLT32:
            /* fallthrough: val already holds the PLT slot address */

        plt32pc32:
        {
            ਲੰਮਾ ਲੰਮਾ diff;
            diff = (ਲੰਮਾ ਲੰਮਾ)val - addr;
            ਜੇ (diff < -2147483648LL || diff > 2147483647LL) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
              /* ignore overflow with undefined weak symbols */
              ਜੇ (((ElfW(Sym)*)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ].st_shndx != SHN_UNDEF)
#ਜੇ_ਅੰਤ
                tcc_error_noabort("relocation '%d' out of range", type);
            }
            add32le(ptr, diff);
        }
            ਰੋਕੋ;

        ਹਾਲਤ R_X86_64_COPY:
	    ਰੋਕੋ;

        ਹਾਲਤ R_X86_64_PLTOFF64:
            add64le(ptr, val - s1->got->sh_addr + rel->r_addend);
            ਰੋਕੋ;

        ਹਾਲਤ R_X86_64_PC64:
            ਜੇ (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_ਸੂਚਕਾਂਕ = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->dyn_ਸੂਚਕਾਂਕ;
                ਜੇ (esym_ਸੂਚਕਾਂਕ) {
                    qrel->r_ਵਿੱਥ = rel->r_ਵਿੱਥ;
                    qrel->r_info = ELFW(R_INFO)(esym_ਸੂਚਕਾਂਕ, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    ਰੋਕੋ;
                }
            }
            add64le(ptr, val - addr);
            ਰੋਕੋ;

        ਹਾਲਤ R_X86_64_GLOB_DAT:
        ਹਾਲਤ R_X86_64_JUMP_ਥਾਂ:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            ਰੋਕੋ;
        ਹਾਲਤ R_X86_64_GOTPCREL:
        ਹਾਲਤ R_X86_64_GOTPCRELX:
        ਹਾਲਤ R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->got_ਵਿੱਥ - 4);
            ਰੋਕੋ;
        ਹਾਲਤ R_X86_64_GOTPC32:
            add32le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            ਰੋਕੋ;
        ਹਾਲਤ R_X86_64_GOTPC64:
            add64le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            ਰੋਕੋ;
        ਹਾਲਤ R_X86_64_GOTTPOFF:
            add32le(ptr, val - s1->got->sh_addr);
            ਰੋਕੋ;
        ਹਾਲਤ R_X86_64_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->got_ਵਿੱਥ);
            ਰੋਕੋ;
        ਹਾਲਤ R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 0)->got_ਵਿੱਥ);
            ਰੋਕੋ;
        ਹਾਲਤ R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            ਰੋਕੋ;
        ਹਾਲਤ R_X86_64_TLSGD:
            {
                ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ expect[] = {
                    /* .byte 0x66; lea 0(%rip),%rdi */
                    0x66, 0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* .word 0x6666; rex64; call __tls_get_addr@PLT */
                    0x66, 0x66, 0x48, 0xe8, 0x00, 0x00, 0x00, 0x00 };
                ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ replace[] = {
                    /* mov %fs:0,%rax */
                    0x64, 0x48, 0x8b, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
                    /* lea -4(%rax),%rax */
                    0x48, 0x8d, 0x80, 0x00, 0x00, 0x00, 0x00 };

                ਜੇ (memcmp (ptr-4, expect, ਆਕਾਰ(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    ਸਮ੍ਰਿਤੀ_ਨਕਲ(ptr-4, replace, ਆਕਾਰ(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_ਮੁੱਲ - sec->sh_addr - sec->ਅੰਕੜੇ_ਵਿੱਥ;
                    add32le(ptr + 8, x);
                }
                ਨਹੀਂਤਾਂ
                    tcc_error_noabort("unexpected R_X86_64_TLSGD pattern");
            }
            ਰੋਕੋ;
        ਹਾਲਤ R_X86_64_TLSLD:
            {
                ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ expect[] = {
                    /* lea 0(%rip),%rdi */
                    0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0x00, 0x00, 0x00, 0x00 };
                ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ replace[] = {
                    /* data16 data16 data16 mov %fs:0,%rax */
                    0x66, 0x66, 0x66, 0x64, 0x48, 0x8b, 0x04, 0x25,
                    0x00, 0x00, 0x00, 0x00 };

                ਜੇ (memcmp (ptr-3, expect, ਆਕਾਰ(expect)) == 0) {
                    ਸਮ੍ਰਿਤੀ_ਨਕਲ(ptr-3, replace, ਆਕਾਰ(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                }
                ਨਹੀਂਤਾਂ
                    tcc_error_noabort("unexpected R_X86_64_TLSLD pattern");
            }
            ਰੋਕੋ;

        ਹਾਲਤ R_X86_64_DTPOFF32:
        ਹਾਲਤ R_X86_64_TPOFF32:
        ਹਾਲਤ R_X86_64_DTPOFF64:
        ਹਾਲਤ R_X86_64_TPOFF64:
            {
                int32_t x;
                ਜੇ (s1->tls_ਸਿਰਾ) {
                    x = val - s1->tls_ਸਿਰਾ;
                } ਨਹੀਂਤਾਂ {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->ਅੰਕੜੇ_ਵਿੱਥ;
                }
                ਚੋਣ (type) {
                ਹਾਲਤ R_X86_64_DTPOFF64:
                ਹਾਲਤ R_X86_64_TPOFF64:
                    add64le(ptr, x);
                    ਰੋਕੋ;
                ਮੂਲ:
                    add32le(ptr, x);
                    ਰੋਕੋ;
                }
            }
            ਰੋਕੋ;
        ਹਾਲਤ R_X86_64_NONE:
            ਰੋਕੋ;
        ਹਾਲਤ R_X86_64_RELATIVE:
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
            add32le(ptr, val - s1->pe_imagebase);
#ਜੇ_ਅੰਤ
            /* do nothing */
            ਰੋਕੋ;
        ਮੂਲ:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (ਬਿਨਾਨਿਸ਼ਾਨੀ)addr, ptr, (ਬਿਨਾਨਿਸ਼ਾਨੀ)val);
            ਰੋਕੋ;
    }
}

#ਜੇ_ਅੰਤ /* !TARGET_DEFS_ONLY */
