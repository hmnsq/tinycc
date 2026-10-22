#ifdef TARGET_DEFS_ONLY

#define EM_TCC_TARGET EM_X86_64

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_X86_64_32S
#define R_DATA_PTR  R_X86_64_64
#define R_JMP_SLOT  R_X86_64_JUMP_SLOT
#define R_GLOB_DAT  R_X86_64_GLOB_DAT
#define R_COPY      R_X86_64_COPY
#define R_RELATIVE  R_X86_64_RELATIVE

#define R_અંક       R_X86_64_અંક

#define ELF_START_ADDR 0x400000
#define ELF_PAGE_SIZE  0x1000

#define PCRELATIVE_DLLPLT 1
#define RELOCATE_DLLPLT 1

#નહીંતર /* !TARGET_DEFS_ONLY */

#અન્તર્ભાવ "tcc.h"

#ifdef NEED_RELOC_TYPE
/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
ST_FUNC પૂર્ણાંક code_reloc (પૂર્ણાંક reloc_type)
{
    પસંદગી (reloc_type) {
        સ્થિતિ R_X86_64_32:
        સ્થિતિ R_X86_64_32S:
        સ્થિતિ R_X86_64_64:
        સ્થિતિ R_X86_64_GOTPC32:
        સ્થિતિ R_X86_64_GOTPC64:
        સ્થિતિ R_X86_64_GOTPCREL:
        સ્થિતિ R_X86_64_GOTPCRELX:
        સ્થિતિ R_X86_64_REX_GOTPCRELX:
        સ્થિતિ R_X86_64_GOTTPOFF:
        સ્થિતિ R_X86_64_GOT32:
        સ્થિતિ R_X86_64_GOT64:
        સ્થિતિ R_X86_64_GLOB_DAT:
        સ્થિતિ R_X86_64_COPY:
        સ્થિતિ R_X86_64_RELATIVE:
        સ્થિતિ R_X86_64_GOTOFF64:
        સ્થિતિ R_X86_64_TLSGD:
        સ્થિતિ R_X86_64_TLSLD:
        સ્થિતિ R_X86_64_DTPOFF32:
        સ્થિતિ R_X86_64_TPOFF32:
        સ્થિતિ R_X86_64_DTPOFF64:
        સ્થિતિ R_X86_64_TPOFF64:
            પાછા 0;

        સ્થિતિ R_X86_64_PC32:
        સ્થિતિ R_X86_64_PC64:
        સ્થિતિ R_X86_64_PLT32:
        સ્થિતિ R_X86_64_PLTOFF64:
        સ્થિતિ R_X86_64_JUMP_SLOT:
            પાછા 1;
    }
    પાછા -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See tcc.h for a description of the
   different values. */
ST_FUNC પૂર્ણાંક gotplt_entry_type (પૂર્ણાંક reloc_type)
{
    પસંદગી (reloc_type) {
        સ્થિતિ R_X86_64_GLOB_DAT:
        સ્થિતિ R_X86_64_JUMP_SLOT:
        સ્થિતિ R_X86_64_COPY:
        સ્થિતિ R_X86_64_RELATIVE:
            પાછા NO_GOTPLT_ENTRY;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        સ્થિતિ R_X86_64_32:
        સ્થિતિ R_X86_64_32S:
        સ્થિતિ R_X86_64_64:
        સ્થિતિ R_X86_64_PC32:
        સ્થિતિ R_X86_64_PC64:
            પાછા AUTO_GOTPLT_ENTRY;

        સ્થિતિ R_X86_64_GOTTPOFF:
            પાછા BUILD_GOT_ONLY;

        સ્થિતિ R_X86_64_GOT32:
        સ્થિતિ R_X86_64_GOT64:
        સ્થિતિ R_X86_64_GOTPC32:
        સ્થિતિ R_X86_64_GOTPC64:
        સ્થિતિ R_X86_64_GOTOFF64:
        સ્થિતિ R_X86_64_GOTPCREL:
        સ્થિતિ R_X86_64_GOTPCRELX:
        સ્થિતિ R_X86_64_TLSGD:
        સ્થિતિ R_X86_64_TLSLD:
        સ્થિતિ R_X86_64_DTPOFF32:
        સ્થિતિ R_X86_64_DTPOFF64:
        સ્થિતિ R_X86_64_REX_GOTPCRELX:
        સ્થિતિ R_X86_64_PLT32:
        સ્થિતિ R_X86_64_PLTOFF64:
            પાછા ALWAYS_GOTPLT_ENTRY;

        સ્થિતિ R_X86_64_TPOFF32:
        સ્થિતિ R_X86_64_TPOFF64:
            પાછા NO_GOTPLT_ENTRY;
    }

    પાછા -1;
}

#ifdef NEED_BUILD_GOT
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, સંરચના sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    પૂર્ણાંક modrm;
    unsigned plt_offset, relofs;

    modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    જો (plt->data_offset == 0) {
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
    write32le(p + 7, relofs / કદ (ElfW_Rel) - 1);
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->data_offset));
    પાછા plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC શૂન્ય relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;

    જો (!s1->plt)
      પાછા;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    જો (p < p_end) {
        પૂર્ણાંક x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        જ્યારે (p < p_end) {
            add32le(p + 2, x + (s1->plt->data - p));
            p += 16;
        }
    }

    જો (s1->plt->reloc) {
        ElfW_Rel *rel;
        પૂર્ણાંક x = s1->plt->sh_addr + 16 + 6;
        p = s1->got->data;
        for_each_elem(s1->plt->reloc, 0, rel, ElfW_Rel) {
            write64le(p + rel->r_offset, x);
            x += 16;
        }
    }
}
#endif
#endif

ST_FUNC શૂન્ય relocate(TCCState *s1, ElfW_Rel *rel, પૂર્ણાંક type, unsigned અક્ષર *ptr, addr_t addr, addr_t val)
{
    પૂર્ણાંક sym_index, esym_index;

    sym_index = ELFW(R_SYM)(rel->r_info);

    પસંદગી (type) {
        સ્થિતિ R_X86_64_64:
            જો (s1->output_type & TCC_OUTPUT_DYN) {
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                qrel->r_offset = rel->r_offset;
                જો (esym_index) {
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    તોડો;
                } નહીંતર {
                    qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            તોડો;
        સ્થિતિ R_X86_64_32:
        સ્થિતિ R_X86_64_32S:
            જો (s1->output_type & TCC_OUTPUT_DYN) {
                /* XXX: this logic may depend on TCC's codegen
                   now TCC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_offset = rel->r_offset;
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (પૂર્ણાંક)read32le(ptr) + val;
                qrel++;
            }
            જો ((type == R_X86_64_32 ? val != (unsigned)val : val != (પૂર્ણાંક)val)
                /* ignore relocation check for stab section */
                && (stab_section == ખાલી ||
                    addr < stab_section->sh_addr ||
                    addr >= (stab_section->sh_addr + stab_section->data_offset))) {
                tcc_error_noabort("relocation 'R_X86_64_32[S]' out of range");
            }
            add32le(ptr, val);
            તોડો;

        સ્થિતિ R_X86_64_PC32:
            જો (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                જો (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_PC32);
                    /* Use sign extension! */
                    qrel->r_addend = (પૂર્ણાંક)read32le(ptr) + rel->r_addend;
                    qrel++;
                    તોડો;
                }
            }
            જાઓ plt32pc32;

        સ્થિતિ R_X86_64_PLT32:
            /* fallthrough: val already holds the PLT slot address */

        plt32pc32:
        {
            long long diff;
            diff = (long long)val - addr;
            જો (diff < -2147483648LL || diff > 2147483647LL) {
#ifdef TCC_TARGET_PE
              /* ignore overflow with undefined weak symbols */
              જો (((ElfW(Sym)*)symtab_section->data)[sym_index].st_shndx != SHN_UNDEF)
#endif
                tcc_error_noabort("relocation '%d' out of range", type);
            }
            add32le(ptr, diff);
        }
            તોડો;

        સ્થિતિ R_X86_64_COPY:
	    તોડો;

        સ્થિતિ R_X86_64_PLTOFF64:
            add64le(ptr, val - s1->got->sh_addr + rel->r_addend);
            તોડો;

        સ્થિતિ R_X86_64_PC64:
            જો (s1->output_type == TCC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = get_sym_attr(s1, sym_index, 0)->dyn_index;
                જો (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    તોડો;
                }
            }
            add64le(ptr, val - addr);
            તોડો;

        સ્થિતિ R_X86_64_GLOB_DAT:
        સ્થિતિ R_X86_64_JUMP_SLOT:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            તોડો;
        સ્થિતિ R_X86_64_GOTPCREL:
        સ્થિતિ R_X86_64_GOTPCRELX:
        સ્થિતિ R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         get_sym_attr(s1, sym_index, 0)->got_offset - 4);
            તોડો;
        સ્થિતિ R_X86_64_GOTPC32:
            add32le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            તોડો;
        સ્થિતિ R_X86_64_GOTPC64:
            add64le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            તોડો;
        સ્થિતિ R_X86_64_GOTTPOFF:
            add32le(ptr, val - s1->got->sh_addr);
            તોડો;
        સ્થિતિ R_X86_64_GOT32:
            /* we load the got offset */
            add32le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            તોડો;
        સ્થિતિ R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, get_sym_attr(s1, sym_index, 0)->got_offset);
            તોડો;
        સ્થિતિ R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            તોડો;
        સ્થિતિ R_X86_64_TLSGD:
            {
                સ્થિર અચલ unsigned અક્ષર expect[] = {
                    /* .byte 0x66; lea 0(%rip),%rdi */
                    0x66, 0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* .word 0x6666; rex64; call __tls_get_addr@PLT */
                    0x66, 0x66, 0x48, 0xe8, 0x00, 0x00, 0x00, 0x00 };
                સ્થિર અચલ unsigned અક્ષર replace[] = {
                    /* mov %fs:0,%rax */
                    0x64, 0x48, 0x8b, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00,
                    /* lea -4(%rax),%rax */
                    0x48, 0x8d, 0x80, 0x00, 0x00, 0x00, 0x00 };

                જો (memcmp (ptr-4, expect, કદ(expect)) == 0) {
                    ElfW(Sym) *sym;
                    Section *sec;
                    int32_t x;

                    memcpy(ptr-4, replace, કદ(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                    sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    sec = s1->sections[sym->st_shndx];
                    x = sym->st_કિંમત - sec->sh_addr - sec->data_offset;
                    add32le(ptr + 8, x);
                }
                નહીંતર
                    tcc_error_noabort("unexpected R_X86_64_TLSGD pattern");
            }
            તોડો;
        સ્થિતિ R_X86_64_TLSLD:
            {
                સ્થિર અચલ unsigned અક્ષર expect[] = {
                    /* lea 0(%rip),%rdi */
                    0x48, 0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00,
                    /* call __tls_get_addr@PLT */
                    0xe8, 0x00, 0x00, 0x00, 0x00 };
                સ્થિર અચલ unsigned અક્ષર replace[] = {
                    /* data16 data16 data16 mov %fs:0,%rax */
                    0x66, 0x66, 0x66, 0x64, 0x48, 0x8b, 0x04, 0x25,
                    0x00, 0x00, 0x00, 0x00 };

                જો (memcmp (ptr-3, expect, કદ(expect)) == 0) {
                    memcpy(ptr-3, replace, કદ(replace));
                    rel[1].r_info = ELFW(R_INFO)(0, R_X86_64_NONE);
                }
                નહીંતર
                    tcc_error_noabort("unexpected R_X86_64_TLSLD pattern");
            }
            તોડો;

        સ્થિતિ R_X86_64_DTPOFF32:
        સ્થિતિ R_X86_64_TPOFF32:
        સ્થિતિ R_X86_64_DTPOFF64:
        સ્થિતિ R_X86_64_TPOFF64:
            {
                int32_t x;
                જો (s1->tls_end) {
                    x = val - s1->tls_end;
                } નહીંતર {
                    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                    Section *sec = s1->sections[sym->st_shndx];
                    x = val - sec->sh_addr - sec->data_offset;
                }
                પસંદગી (type) {
                સ્થિતિ R_X86_64_DTPOFF64:
                સ્થિતિ R_X86_64_TPOFF64:
                    add64le(ptr, x);
                    તોડો;
                મૂળભૂત:
                    add32le(ptr, x);
                    તોડો;
                }
            }
            તોડો;
        સ્થિતિ R_X86_64_NONE:
            તોડો;
        સ્થિતિ R_X86_64_RELATIVE:
#ifdef TCC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            તોડો;
        મૂળભૂત:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (unsigned)addr, ptr, (unsigned)val);
            તોડો;
    }
}

#endif /* !TARGET_DEFS_ONLY */
