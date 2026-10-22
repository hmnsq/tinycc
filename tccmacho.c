/*
 * Mach-O file handling for TCC
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#অন্তর্ভাব "tcc.h"

/* In order to make life easy for us we are generating Mach-O files which
   don't make use of some modern features, but which aren't entirely classic
   either in that they do use some modern features.  We're also only
   generating 64bit Mach-O files, and only native endian at that.

   In particular we're generating executables that don't make use of
   DYLD_INFO for dynamic linking info, as that requires us building a
   trie of exported names.  We're simply using classic symbol tables which
   are still supported by modern dyld.

   But we do use LC_MAIN, which is a "modern" feature in order to not have
   to setup our own crt code.  We're not using lazy linking, so even function
   calls are resolved at startup.  */

#যদি !defined TCC_TARGET_X86_64 && !defined TCC_TARGET_ARM64
#error Platform not supported
#endif

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#undef _tcc_error

#define DEBUG_MACHO 0
#define dprintf যদি (DEBUG_MACHO) printf

#define MH_EXECUTE              (0x2)
#define MH_DYLDLINK             (0x4)
#define MH_DYLIB                (0x6)
#define MH_PIE                  (0x200000)

#define CPU_SUBTYPE_LIB64       (0x80000000)
#define CPU_SUBTYPE_X86_ALL     (3)
#define CPU_SUBTYPE_ARM64_ALL   (0)

#define CPU_ARCH_ABI64          (0x01000000)

#define CPU_TYPE_X86            (7)
#define CPU_TYPE_X86_64         (CPU_TYPE_X86 | CPU_ARCH_ABI64)
#define CPU_TYPE_ARM            (12)
#define CPU_TYPE_ARM64          (CPU_TYPE_ARM | CPU_ARCH_ABI64)

কাঠামো fat_header {
    uint32_t        magic;          /* FAT_MAGIC or FAT_MAGIC_64 */
    uint32_t        nfat_arch;      /* number of structs that follow */
};

কাঠামো fat_arch {
    পূর্ণসংখ্যা             cputype;        /* cpu specifier (int) */
    পূর্ণসংখ্যা             cpusubtype;     /* machine specifier (int) */
    uint32_t        offset;         /* file offset to this object file */
    uint32_t        আকার_2;           /* size of this object file */
    uint32_t        align;          /* alignment as a power of 2 */
};

#define FAT_MAGIC       0xcafebabe
#define FAT_CIGAM       0xbebafeca
#define FAT_MAGIC_64    0xcafebabf
#define FAT_CIGAM_64    0xbfbafeca

কাঠামো mach_header {
    uint32_t        magic;          /* mach magic number identifier */
    পূর্ণসংখ্যা             cputype;        /* cpu specifier */
    পূর্ণসংখ্যা             cpusubtype;     /* machine specifier */
    uint32_t        filetype;       /* type of file */
    uint32_t        ncmds;          /* number of load commands */
    uint32_t        sizeofcmds;     /* the size of all the load commands */
    uint32_t        flags;          /* flags */
};

কাঠামো mach_header_64 {
    কাঠামো mach_header  mh;
    uint32_t            reserved;       /* reserved, pad to 64bit */
};

/* Constant for the magic field of the mach_header (32-bit architectures) */
#define MH_MAGIC        0xfeedface      /* the mach magic number */
#define MH_CIGAM        0xcefaedfe      /* NXSwapInt(MH_MAGIC) */
#define MH_MAGIC_64     0xfeedfacf      /* the 64-bit mach magic number */
#define MH_CIGAM_64     0xcffaedfe      /* NXSwapInt(MH_MAGIC_64) */

কাঠামো load_command {
    uint32_t        cmd;            /* type of load command */
    uint32_t        cmdsize;        /* total size of command in bytes */
};

#define LC_REQ_DYLD 0x80000000
#define LC_SYMTAB        0x2
#define LC_DYSYMTAB      0xb
#define LC_LOAD_DYLIB    0xc
#define LC_ID_DYLIB      0xd
#define LC_LOAD_DYLINKER 0xe
#define LC_SEGMENT_64    0x19
#define LC_RPATH (0x1c | LC_REQ_DYLD)
#define LC_REEXPORT_DYLIB (0x1f | LC_REQ_DYLD)
#define LC_DYLD_INFO_ONLY (0x22|LC_REQ_DYLD)
#define LC_MAIN (0x28|LC_REQ_DYLD)
#define LC_SOURCE_VERSION 0x2A
#define LC_BUILD_VERSION 0x32
#define LC_DYLD_EXPORTS_TRIE (0x33 | LC_REQ_DYLD)
#define LC_DYLD_CHAINED_FIXUPS (0x34 | LC_REQ_DYLD)

#define SG_READ_ONLY    0x10 /* This segment is made read-only after fixups */

প্রকারলেখ পূর্ণসংখ্যা vm_prot_t;

কাঠামো segment_command_64 { /* for 64-bit architectures */
    uint32_t        cmd;            /* LC_SEGMENT_64 */
    uint32_t        cmdsize;        /* includes sizeof section_64 structs */
    অক্ষর            segname[16];    /* segment name */
    uint64_t        vmaddr;         /* memory address of this segment */
    uint64_t        vmsize;         /* memory size of this segment */
    uint64_t        fileoff;        /* file offset of this segment */
    uint64_t        filesize;       /* amount to map from the file */
    vm_prot_t       maxprot;        /* maximum VM protection */
    vm_prot_t       initprot;       /* initial VM protection */
    uint32_t        nsects;         /* number of sections in segment */
    uint32_t        flags;          /* flags */
};

কাঠামো section_64 { /* for 64-bit architectures */
    অক্ষর            sectname[16];   /* name of this section */
    অক্ষর            segname[16];    /* segment this section goes in */
    uint64_t        addr;           /* memory address of this section */
    uint64_t        আকার_2;           /* size in bytes of this section */
    uint32_t        offset;         /* file offset of this section */
    uint32_t        align;          /* section alignment (power of 2) */
    uint32_t        reloff;         /* file offset of relocation entries */
    uint32_t        nreloc;         /* number of relocation entries */
    uint32_t        flags;          /* flags (section type and attributes)*/
    uint32_t        reserved1;      /* reserved (for offset or index) */
    uint32_t        reserved2;      /* reserved (for count or sizeof) */
    uint32_t        reserved3;      /* reserved */
};

গণনা {
    DYLD_CHAINED_IMPORT          = 1,
};

কাঠামো dyld_chained_fixups_header {
    uint32_t    fixups_version; ///< 0
    uint32_t    starts_offset;  ///< Offset of dyld_chained_starts_in_image.
    uint32_t    imports_offset; ///< Offset of imports table in chain_data.
    uint32_t    symbols_offset; ///< Offset of symbol strings in chain_data.
    uint32_t    imports_গুনতি;  ///< Number of imported symbol names.
    uint32_t    imports_format; ///< DYLD_CHAINED_IMPORT*
    uint32_t    symbols_format; ///< 0 => uncompressed, 1 => zlib compressed
};

কাঠামো dyld_chained_starts_in_image
{
    uint32_t    seg_গুনতি;
    uint32_t    seg_info_offset[1];  // each entry is offset into this struct for that segment
    // followed by pool of dyld_chain_starts_in_segment data
};

গণনা {
    DYLD_CHAINED_PTR_64                     =  2,    // target is vmaddr
    DYLD_CHAINED_PTR_64_OFFSET              =  6,    // target is vm offset
};

গণনা {
    DYLD_CHAINED_PTR_START_NONE   = 0xFFFF, // used in page_start[] to denote a page with no fixups
};

#define SEG_PAGE_আকার 16384

কাঠামো dyld_chained_starts_in_segment
{
    uint32_t    আকার_2;               // size of this (amount kernel needs to copy)
    uint16_t    page_আকার;          // 0x1000 or 0x4000
    uint16_t    pointer_format;     // DYLD_CHAINED_PTR_*
    uint64_t    segment_offset;     // offset in memory to start of segment
    uint32_t    max_valid_pointer;  // for 32-bit OS, any value beyond this is not a pointer
    uint16_t    page_গুনতি;         // how many pages are in array
    uint16_t    page_start[1];      // each entry is offset in each page of first element in chain
                                    // or DYLD_CHAINED_PTR_START_NONE if no fixups on page
};

গণনা BindSpecialDylib {
  BIND_SPECIAL_DYLIB_FLAT_LOOKUP = -2,
};

কাঠামো dyld_chained_import
{
    uint32_t    lib_ordinal :  8,
                weak_import :  1,
                name_offset : 23;
};

কাঠামো dyld_chained_ptr_64_rebase
{
    uint64_t    target    : 36,    // vmaddr, 64GB max image size
                high8     :  8,    // top 8 bits set to this after slide added
                reserved  :  7,    // all zeros
                পরবর্তী      : 12,    // 4-byte stride
                bind      :  1;    // == 0
};

কাঠামো dyld_chained_ptr_64_bind
{
    uint64_t    ordinal   : 24,
                addend    :  8,   // 0 thru 255
                reserved  : 19,   // all zeros
                পরবর্তী      : 12,   // 4-byte stride
                bind      :  1;   // == 1
};

#define S_REGULAR                       0x0
#define S_ZEROFILL                      0x1
#define S_NON_LAZY_প্রতীক_POINTERS      0x6
#define S_LAZY_প্রতীক_POINTERS          0x7
#define S_প্রতীক_STUBS                  0x8
#define S_MOD_INIT_FUNC_POINTERS        0x9
#define S_MOD_TERM_FUNC_POINTERS        0xa

#define S_ATTR_PURE_INSTRUCTIONS        0x80000000
#define S_ATTR_SOME_INSTRUCTIONS        0x00000400
#define S_ATTR_DEBUG             	0x02000000


প্রকারলেখ uint32_t lc_str;

কাঠামো dylib_command {
    uint32_t cmd;                   /* LC_ID_DYLIB, LC_LOAD_{,WEAK_}DYLIB,
                                       LC_REEXPORT_DYLIB */
    uint32_t cmdsize;               /* includes pathname string */
    lc_str   name;                  /* library's path name */
    uint32_t timestamp;             /* library's build time stamp */
    uint32_t current_version;       /* library's current version number */
    uint32_t compatibility_version; /* library's compatibility vers number*/
};

কাঠামো rpath_command {
    uint32_t     cmd;           /* LC_RPATH */
    uint32_t     cmdsize;       /* includes string */
    lc_str       path;          /* path to add to run path */
};

কাঠামো dylinker_command {
    uint32_t        cmd;            /* LC_ID_DYLINKER, LC_LOAD_DYLINKER or
                                       LC_DYLD_ENVIRONMENT */
    uint32_t        cmdsize;        /* includes pathname string */
    lc_str          name;           /* dynamic linker's path name */
};

কাঠামো linkedit_তথ্য_command {
    uint32_t    cmd;            /* LC_CODE_SIGNATURE, LC_SEGMENT_SPLIT_INFO,
                                   LC_FUNCTION_STARTS, LC_DATA_IN_CODE,
                                   LC_DYLIB_CODE_SIGN_DRS,
                                   LC_LINKER_OPTIMIZATION_HINT,
                                   LC_DYLD_EXPORTS_TRIE, or
                                   LC_DYLD_CHAINED_FIXUPS. */
    uint32_t    cmdsize;        /* sizeof(struct linkedit_data_command) */
    uint32_t    dataoff;        /* file offset of data in __LINKEDIT segment */
    uint32_t    datasize;       /* file size of data in __LINKEDIT segment  */
};

#define PLATFORM_MACOS 1

কাঠামো build_version_command {
    uint32_t    cmd;            /* LC_BUILD_VERSION */
    uint32_t    cmdsize;        /* sizeof(struct build_version_command) plus */
                                /* ntools * sizeof(struct build_tool_version) */
    uint32_t    platform;       /* platform */
    uint32_t    minos;          /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    sdk;            /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    ntools;         /* number of tool entries following this */
};

কাঠামো source_version_command {
    uint32_t  cmd;      /* LC_SOURCE_VERSION */
    uint32_t  cmdsize;  /* 16 */
    uint64_t  version;  /* A.B.C.D.E packed as a24.b10.c10.d10.e10 */
};

কাঠামো symtab_command {
    uint32_t        cmd;            /* LC_SYMTAB */
    uint32_t        cmdsize;        /* sizeof(struct symtab_command) */
    uint32_t        symoff;         /* symbol table offset */
    uint32_t        nsyms;          /* number of symbol table entries */
    uint32_t        stroff;         /* string table offset */
    uint32_t        strsize;        /* string table size in bytes */
};

কাঠামো dysymtab_command {
    uint32_t cmd;       /* LC_DYSYMTAB */
    uint32_t cmdsize;   /* sizeof(struct dysymtab_command) */

    uint32_t ilocalsym; /* index to local symbols */
    uint32_t nlocalsym; /* number of local symbols */

    uint32_t iextdefsym;/* index to externally defined symbols */
    uint32_t nextdefsym;/* number of externally defined symbols */

    uint32_t iundefsym; /* index to undefined symbols */
    uint32_t nundefsym; /* number of undefined symbols */

    uint32_t tocoff;    /* file offset to table of contents */
    uint32_t ntoc;      /* number of entries in table of contents */

    uint32_t modtaboff; /* file offset to module table */
    uint32_t nmodtab;   /* number of module table entries */

    uint32_t extrefsymoff;  /* offset to referenced symbol table */
    uint32_t nextrefsyms;   /* number of referenced symbol table entries */

    uint32_t indirectsymoff;/* file offset to the indirect symbol table */
    uint32_t nindirectsyms; /* number of indirect symbol table entries */

    uint32_t extreloff; /* offset to external relocation entries */
    uint32_t nextrel;   /* number of external relocation entries */
    uint32_t locreloff; /* offset to local relocation entries */
    uint32_t nlocrel;   /* number of local relocation entries */
};

#define BIND_OPCODE_DONE                                        0x00
#define BIND_OPCODE_SET_DYLIB_SPECIAL_IMM                       0x30
#define BIND_OPCODE_SET_প্রতীক_TRAILING_FLAGS_IMM               0x40
#define BIND_OPCODE_SET_TYPE_IMM                                0x50
#define BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB                 0x70
#define BIND_OPCODE_DO_BIND                                     0x90

#define BIND_প্রতীক_FLAGS_WEAK_IMPORT                           0x1

#define BIND_TYPE_POINTER                                       1
#define BIND_SPECIAL_DYLIB_FLAT_LOOKUP                          -2

#define REBASE_OPCODE_DONE                                      0x00
#define REBASE_OPCODE_SET_TYPE_IMM                              0x10
#define REBASE_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB               0x20
#define REBASE_OPCODE_DO_REBASE_IMM_TIMES                       0x50

#define REBASE_TYPE_POINTER                                     1

#define EXPORT_প্রতীক_FLAGS_KIND_REGULAR                        0x00
#define EXPORT_প্রতীক_FLAGS_KIND_ABSOLUTE                       0x02
#define EXPORT_প্রতীক_FLAGS_WEAK_DEFINITION                     0x04

কাঠামো dyld_info_command {
    uint32_t cmd;             /* LC_DYLD_INFO or LC_DYLD_INFO_ONLY */
    uint32_t cmdsize;         /* sizeof(struct dyld_info_command) */
    uint32_t rebase_off;      /* file offset to rebase info  */
    uint32_t rebase_আকার;     /* size of rebase info   */
    uint32_t bind_off;        /* file offset to binding info   */
    uint32_t bind_আকার;       /* size of binding info  */
    uint32_t weak_bind_off;   /* file offset to weak binding info   */
    uint32_t weak_bind_আকার;  /* size of weak binding info  */
    uint32_t lazy_bind_off;   /* file offset to lazy binding info */
    uint32_t lazy_bind_আকার;  /* size of lazy binding infs */
    uint32_t export_off;      /* file offset to lazy binding info */
    uint32_t export_আকার;     /* size of lazy binding infs */
};

#define INDIRECT_প্রতীক_LOCAL   0x80000000

কাঠামো entry_point_command {
    uint32_t  cmd;      /* LC_MAIN only used in MH_EXECUTE filetypes */
    uint32_t  cmdsize;  /* 24 */
    uint64_t  entryoff; /* file (__TEXT) offset of main() */
    uint64_t  stacksize;/* if not zero, initial stack size */
};

গণনা skind {
    sk_unknown = 0,
    sk_discard,
    sk_text,
    sk_stubs,
    sk_stub_helper,
    sk_ro_তথ্য,
    sk_uw_info,
    sk_nl_ptr,  // non-lazy pointers, aka GOT
    sk_debug_info,
    sk_debug_abbrev,
    sk_debug_সারি,
    sk_debug_aranges,
    sk_debug_str,
    sk_debug_সারি_str,
    sk_stab,
    sk_stab_str,
    sk_la_ptr,  // lazy pointers
    sk_init,
    sk_fini,
    sk_rw_তথ্য,
    sk_bss,
    sk_linkedit,
    sk_last
};

কাঠামো nlist_64 {
    uint32_t  n_strx;      /* index into the string table */
    uint8_t n_type;        /* type flag, see below */
    uint8_t n_sect;        /* section number or NO_SECT */
    uint16_t n_desc;       /* see <mach-o/stab.h> */
    uint64_t n_মান;      /* value of this symbol (or stab offset) */
};

#define N_UNDF  0x0
#define N_ABS   0x2
#define N_EXT   0x1
#define N_SECT  0xe

#define N_WEAK_REF      0x0040
#define N_WEAK_DEF      0x0080

কাঠামো macho {
    কাঠামো mach_header_64 mh;
    পূর্ণসংখ্যা *seg2lc, nseg;
    কাঠামো load_command **lc;
    কাঠামো entry_point_command *ep;
    পূর্ণসংখ্যা nlc;
    কাঠামো {
        Section *s;
        পূর্ণসংখ্যা machosect;
    } sk_to_sect[sk_last];
    পূর্ণসংখ্যা *elfsectomacho;
    পূর্ণসংখ্যা *e2msym;
    Section *symtab, *strtab, *indirsyms, *stubs, *exports;
    uint32_t ilocal, iextdef, iundef;
    পূর্ণসংখ্যা stubsym, n_got, nr_plt;
    পূর্ণসংখ্যা segment[sk_last];
#ifdef CONFIG_NEW_MACHO
    Section *chained_fixups;
    পূর্ণসংখ্যা n_bind;
    পূর্ণসংখ্যা n_bind_rebase;
    কাঠামো bind_rebase {
	পূর্ণসংখ্যা section;
	পূর্ণসংখ্যা bind;
	ElfW_Rel rel;
    } *bind_rebase;
#অন্যথা
    Section *rebase, *binding, *weak_binding, *lazy_binding;
    Section *stub_helper, *la_প্রতীক_ptr;
    কাঠামো dyld_info_command *dyldinfo;
    পূর্ণসংখ্যা helpsym, lasym, dyld_private, dyld_stub_binder;
    পূর্ণসংখ্যা n_lazy_bind;    
    কাঠামো s_lazy_bind {
        পূর্ণসংখ্যা section;
        পূর্ণসংখ্যা bind_offset;
        পূর্ণসংখ্যা la_প্রতীক_offset;
        ElfW_Rel rel;
    } *s_lazy_bind;
    পূর্ণসংখ্যা n_rebase;    
    কাঠামো s_rebase {
        পূর্ণসংখ্যা section;
        ElfW_Rel rel;
    } *s_rebase;
    পূর্ণসংখ্যা n_bind; 
    কাঠামো bind {
        পূর্ণসংখ্যা section;
        ElfW_Rel rel;
    } *bind;
#endif
};

#define SHT_LINKEDIT (SHT_LOOS + 42)
#define SHN_FROMDLL  (SHN_LOOS + 2)  /* Symbol is undefined, comes from a DLL */

স্থির শূন্য * add_lc(কাঠামো macho *mo, uint32_t cmd, uint32_t cmdsize)
{
    কাঠামো load_command *lc = tcc_mallocz(cmdsize);
    lc->cmd = cmd;
    lc->cmdsize = cmdsize;
    mo->lc = tcc_realloc(mo->lc, আকার(mo->lc[0]) * (mo->nlc + 1));
    mo->lc[mo->nlc++] = lc;
    ফেরত lc;
}

স্থির কাঠামো segment_command_64 * add_segment(কাঠামো macho *mo, ধ্রুবক অক্ষর *name)
{
    কাঠামো segment_command_64 *sc = add_lc(mo, LC_SEGMENT_64, আকার(*sc));
    strncpy(sc->segname, name, 16);
    mo->seg2lc = tcc_realloc(mo->seg2lc, আকার(*mo->seg2lc) * (mo->nseg + 1));
    mo->seg2lc[mo->nseg++] = mo->nlc - 1;
    ফেরত sc;
}

স্থির কাঠামো segment_command_64 * get_segment(কাঠামো macho *mo, পূর্ণসংখ্যা i)
{
    ফেরত (কাঠামো segment_command_64 *) (mo->lc[mo->seg2lc[i]]);
}

স্থির পূর্ণসংখ্যা add_section(কাঠামো macho *mo, কাঠামো segment_command_64 **_seg, ধ্রুবক অক্ষর *name)
{
    কাঠামো segment_command_64 *seg = *_seg;
    পূর্ণসংখ্যা ret = seg->nsects;
    কাঠামো section_64 *sec;
    seg->nsects++;
    seg->cmdsize += আকার(*sec);
    seg = tcc_realloc(seg, আকার(*seg) + seg->nsects * আকার(*sec));
    sec = (কাঠামো section_64*)((অক্ষর*)seg + আকার(*seg)) + ret;
    memset(sec, 0, আকার(*sec));
    strncpy(sec->sectname, name, 16);
    strncpy(sec->segname, seg->segname, 16);
    *_seg = seg;
    ফেরত ret;
}

স্থির কাঠামো section_64 *get_section(কাঠামো segment_command_64 *seg, পূর্ণসংখ্যা i)
{
    ফেরত (কাঠামো section_64*)((অক্ষর*)seg + আকার(*seg)) + i;
}

স্থির শূন্য * add_dylib(কাঠামো macho *mo, অক্ষর *name)
{
    কাঠামো dylib_command *lc;
    পূর্ণসংখ্যা sz = (আকার(*lc) + strlen(name) + 1 + 7) & -8;
    lc = add_lc(mo, LC_LOAD_DYLIB, sz);
    lc->name = আকার(*lc);
    strcpy((অক্ষর*)lc + lc->name, name);
    lc->timestamp = 2;
    lc->current_version = 1 << 16;
    lc->compatibility_version = 1 << 16;
    ফেরত lc;
}

স্থির পূর্ণসংখ্যা uleb128_আকার (unsigned long long মান)
{
    পূর্ণসংখ্যা আকার_2 =  0;

    করো {
        মান >>= 7;
        আকার_2++;
    } যখন (মান != 0);
    ফেরত আকার_2;
}

স্থির শূন্য write_uleb128(Section *section, uint64_t মান)
{
    করো {
        unsigned অক্ষর byte = মান & 0x7f;
	uint8_t *ptr = section_ptr_add(section, 1);

        মান >>= 7;
        *ptr = byte | (মান ? 0x80 : 0);
    } যখন (মান != 0);
}

স্থির শূন্য tcc_macho_add_destructor(TCCState *s1)
{
    পূর্ণসংখ্যা init_sym, mh_execute_header, at_exit_sym;
    Section *s;
    ElfW_Rel *rel;
    uint8_t *ptr;

    mh_execute_header = put_elf_sym(s1->symtab, -4096, 0,
				    ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				    text_section->sh_অঙ্ক, "__mh_execute_header");
    s = find_section(s1, ".fini_array");
    যদি (s->তথ্য_offset == 0)
        ফেরত; 
    init_sym = put_elf_sym(s1->symtab, text_section->তথ্য_offset, 0,
                           ELFW(ST_INFO)(STB_LOCAL, STT_FUNC), 0,
                           text_section->sh_অঙ্ক, "___GLOBAL_init_65535");
    at_exit_sym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0,
                              SHN_UNDEF, "___cxa_atexit");
#ifdef TCC_TARGET_X86_64
    ptr = section_ptr_add(text_section, 4);
    ptr[0] = 0x55;  // pushq   %rbp
    ptr[1] = 0x48;  // movq    %rsp, %rbp
    ptr[2] = 0x89;
    ptr[3] = 0xe5;
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        পূর্ণসংখ্যা sym_সূচক = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_add(text_section, 26);
        ptr[0] = 0x48;  // lea destructor(%rip),%rax
        ptr[1] = 0x8d;
        ptr[2] = 0x05;
        put_elf_reloca(s1->symtab, text_section, 
		       text_section->তথ্য_offset - 23,
		       R_X86_64_PC32, sym_সূচক, -4);
        ptr[7] = 0x48;  // mov %rax,%rdi
        ptr[8] = 0x89;
        ptr[9] = 0xc7;
	ptr[10] = 0x31; // xorl %ecx, %ecx
	ptr[11] = 0xc9;
	ptr[12] = 0x89; // movl %ecx, %esi
	ptr[13] = 0xce;
        ptr[14] = 0x48;  // lea mh_execute_header(%rip),%rdx
        ptr[15] = 0x8d;
        ptr[16] = 0x15;
        put_elf_reloca(s1->symtab, text_section,
		       text_section->তথ্য_offset - 9,
		       R_X86_64_PC32, mh_execute_header, -4);
	ptr[21] = 0xe8; // call __cxa_atexit
        put_elf_reloca(s1->symtab, text_section,
		       text_section->তথ্য_offset - 4,
		       R_X86_64_PLT32, at_exit_sym, -4);
    }
    ptr = section_ptr_add(text_section, 2);
    ptr[0] = 0x5d;  // pop   %rbp
    ptr[1] = 0xc3;  // ret
#নতুবা_যদি defined TCC_TARGET_ARM64
    ptr = section_ptr_add(text_section, 8);
    write32le(ptr, 0xa9bf7bfd);     // stp     x29, x30, [sp, #-16]!
    write32le(ptr + 4, 0x910003fd); // mov     x29, sp
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        পূর্ণসংখ্যা sym_সূচক = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_add(text_section, 24);
        put_elf_reloc(s1->symtab, text_section, 
		      text_section->তথ্য_offset - 24,
		      R_AARCH64_ADR_PREL_PG_HI21, sym_সূচক);
        write32le(ptr, 0x90000000);      // adrp x0, destructor@page
        put_elf_reloc(s1->symtab, text_section,
		      text_section->তথ্য_offset - 20,
		      R_AARCH64_LDST8_ABS_LO12_NC, sym_সূচক);
        write32le(ptr + 4, 0x91000000);  // add x0,x0,destructor@pageoff
        write32le(ptr + 8, 0xd2800001);  // mov x1, #0
        put_elf_reloc(s1->symtab, text_section, 
		      text_section->তথ্য_offset - 12,
		      R_AARCH64_ADR_PREL_PG_HI21, mh_execute_header);
        write32le(ptr + 12, 0x90000002);      // adrp x2, mh_execute_header@page
        put_elf_reloc(s1->symtab, text_section,
		      text_section->তথ্য_offset - 8,
		      R_AARCH64_LDST8_ABS_LO12_NC, mh_execute_header);
        write32le(ptr + 16, 0x91000042);  // add x2,x2,mh_execute_header@pageoff
        put_elf_reloc(s1->symtab, text_section,
		      text_section->তথ্য_offset - 4,
		      R_AARCH64_CALL26, at_exit_sym);
	write32le(ptr + 20, 0x94000000); // bl __cxa_atexit
    }
    ptr = section_ptr_add(text_section, 8);
    write32le(ptr, 0xa8c17bfd);     // ldp     x29, x30, [sp], #16
    write32le(ptr + 4, 0xd65f03c0); // ret
#endif
    s->reloc->তথ্য_offset = s->তথ্য_offset = 0;
    s->sh_flags &= ~SHF_ALLOC;
    add_array (s1, ".init_array", init_sym);
}

#ifdef CONFIG_NEW_MACHO
স্থির শূন্য bind_rebase_add(কাঠামো macho *mo, পূর্ণসংখ্যা bind, পূর্ণসংখ্যা sh_info,
			    ElfW_Rel *rel, কাঠামো sym_attr *attr)
{
    mo->bind_rebase = tcc_realloc(mo->bind_rebase, (mo->n_bind_rebase + 1) *
		                  আকার(কাঠামো bind_rebase));
    mo->bind_rebase[mo->n_bind_rebase].section = sh_info;
    mo->bind_rebase[mo->n_bind_rebase].bind = bind;
    mo->bind_rebase[mo->n_bind_rebase].rel = *rel;
    যদি (attr)
        mo->bind_rebase[mo->n_bind_rebase].rel.r_offset = attr->got_offset;
    mo->n_bind_rebase++;
    mo->n_bind += bind;
}

স্থির শূন্য check_relocs(TCCState *s1, কাঠামো macho *mo)
{
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    পূর্ণসংখ্যা i, j, type, gotplt_entry, sym_সূচক, for_code;
    uint32_t *pi, *goti;
    কাঠামো sym_attr *attr;

    goti = ফাঁকা;
    mo->nr_plt = mo->n_got = 0;
    জন্য (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        যদি (s->sh_type != SHT_RELX ||
	    !strncmp(s1->sections[s->sh_info]->name, ".debug_", 7))
            চালু;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_entry = gotplt_entry_type(type);
            for_code = code_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_সূচক = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->তথ্য)[sym_সূচক];
            যদি (sym->st_shndx == SHN_UNDEF
                || gotplt_entry == ALWAYS_GOTPLT_ENTRY) {
                attr = get_sym_attr(s1, sym_সূচক, 1);
                যদি (!attr->dyn_সূচক) {
                    attr->got_offset = s1->got->তথ্য_offset;
                    attr->plt_offset = -1;
                    attr->dyn_সূচক = 1; /* used as flag */
                    section_ptr_add(s1->got, PTR_আকার);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_offset,
                                  R_JMP_SLOT, sym_সূচক);
	 	    goti = tcc_realloc(goti, (mo->n_got + 1) * আকার(*goti));
                    যদি (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        যদি (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (অক্ষর *) symtab_section->link->তথ্য + sym->st_name);
			goti[mo->n_got++] = INDIRECT_প্রতীক_LOCAL;
                    } অন্যথা {
                        goti[mo->n_got++] = mo->e2msym[sym_সূচক];
                        যদি (sym->st_shndx == SHN_UNDEF
#ifdef TCC_TARGET_X86_64
                            && type == R_X86_64_GOTPCREL
#নতুবা_যদি defined TCC_TARGET_ARM64
                            && type == R_AARCH64_ADR_GOT_PAGE
#endif
                            ) {
			    attr->plt_offset = -mo->n_bind_rebase - 2;
			    bind_rebase_add(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
			    s1->got->reloc->তথ্য_offset -= আকার (ElfW_Rel);
			}
		        যদি (for_code && sym->st_shndx == SHN_UNDEF)
			    s1->got->reloc->তথ্য_offset -= আকার (ElfW_Rel);
		    }
                }
                যদি (for_code && sym->st_shndx == SHN_UNDEF) {
		    যদি ((পূর্ণসংখ্যা)attr->plt_offset < -1) {
			/* remove above bind and replace with plt */
			mo->bind_rebase[-attr->plt_offset - 2].bind = 2;
			attr->plt_offset = -1;
		    }
                    যদি (attr->plt_offset == -1) {
                        uint8_t *jmp;

                        attr->plt_offset = mo->stubs->তথ্য_offset;
#ifdef TCC_TARGET_X86_64
                        যদি (type != R_X86_64_PLT32)
                             চালু;
                        jmp = section_ptr_add(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *ofs(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_offset + 2,
                                      R_X86_64_GOTPCREL, sym_সূচক);
#নতুবা_যদি defined TCC_TARGET_ARM64
                        যদি (type != R_AARCH64_CALL26)
                             চালু;
                        jmp = section_ptr_add(mo->stubs, 12);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_offset,
                                      R_AARCH64_ADR_GOT_PAGE, sym_সূচক);
                        write32le(jmp, // adrp x16, #sym
                                  0x90000010);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_offset + 4,
                                      R_AARCH64_LD64_GOT_LO12_NC, sym_সূচক);
                        write32le(jmp + 4, // ld x16,[x16, #sym]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);
#endif
			bind_rebase_add(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
                        pi = section_ptr_add(mo->indirsyms, আকার(*pi));
                        *pi = mo->e2msym[sym_সূচক];
                        mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_offset;
                }
            }
	    যদি (type == R_তথ্য_PTR || type == R_JMP_SLOT)
		bind_rebase_add(mo, sym->st_shndx == SHN_UNDEF ? 1 : 0,
				s->sh_info, &save_rel, ফাঁকা);
        }
    }
    /* remove deleted binds */
    জন্য (i = 0, j = 0; i < mo->n_bind_rebase; i++)
	যদি (mo->bind_rebase[i].bind == 2)
	    mo->n_bind--;
	অন্যথা
	    mo->bind_rebase[j++] = mo->bind_rebase[i];
    mo->n_bind_rebase = j;
    pi = section_ptr_add(mo->indirsyms, mo->n_got * আকার(*pi));
    memcpy(pi, goti, mo->n_got * আকার(*pi));
    tcc_free(goti);
}

#অন্যথা

স্থির শূন্য check_relocs(TCCState *s1, কাঠামো macho *mo)
{
    uint8_t *jmp;
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    পূর্ণসংখ্যা i, type, gotplt_entry, sym_সূচক, for_code;
    পূর্ণসংখ্যা bind_offset, la_প্রতীক_offset;
    uint32_t *pi, *goti;
    কাঠামো sym_attr *attr;

#ifdef TCC_TARGET_X86_64
    jmp = section_ptr_add(mo->stub_helper, 16);
    jmp[0] = 0x4c;  /* leaq _dyld_private(%rip), %r11 */
    jmp[1] = 0x8d;
    jmp[2] = 0x1d;
    put_elf_reloca(s1->symtab, mo->stub_helper, 3,
		   R_X86_64_PC32, mo->dyld_private, -4);
    jmp[7] = 0x41;  /* pushq %r11 */
    jmp[8] = 0x53;
    jmp[9] = 0xff;  /* jmpq    *dyld_stub_binder@GOT(%rip) */
    jmp[10] = 0x25;
    put_elf_reloca(s1->symtab, mo->stub_helper, 11,
		   R_X86_64_GOTPCREL, mo->dyld_stub_binder, -4);
    jmp[15] = 0x90; /* nop */
#নতুবা_যদি defined TCC_TARGET_ARM64
    jmp = section_ptr_add(mo->stub_helper, 24);
    put_elf_reloc(s1->symtab, mo->stub_helper, 0,
		  R_AARCH64_ADR_PREL_PG_HI21, mo->dyld_private);
    write32le(jmp, 0x90000011); // adrp x17, _dyld_private@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 4,
		  R_AARCH64_LDST64_ABS_LO12_NC, mo->dyld_private);
    write32le(jmp + 4, 0x91000231); // add x17,x17,_dyld_private@pageoff
    write32le(jmp + 8, 0xa9bf47f0); // stp x16/x17, [sp, #-16]!
    put_elf_reloc(s1->symtab, mo->stub_helper, 12,
		  R_AARCH64_ADR_GOT_PAGE, mo->dyld_stub_binder);
    write32le(jmp + 12, 0x90000010); // adrp x16, dyld_stub_binder@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 16,
		  R_AARCH64_LD64_GOT_LO12_NC, mo->dyld_stub_binder);
    write32le(jmp + 16, 0xf9400210); // ldr x16,[x16,dyld_stub_binder@pageoff]
    write32le(jmp + 20, 0xd61f0200); // br x16
#endif
    
    goti = ফাঁকা;
    mo->nr_plt = mo->n_got = 0;
    জন্য (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        যদি (s->sh_type != SHT_RELX ||
	    !strncmp(s1->sections[s->sh_info]->name, ".debug_", 7))
            চালু;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_entry = gotplt_entry_type(type);
            for_code = code_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_সূচক = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->তথ্য)[sym_সূচক];
            যদি (sym->st_shndx == SHN_UNDEF
                || gotplt_entry == ALWAYS_GOTPLT_ENTRY) {
                attr = get_sym_attr(s1, sym_সূচক, 1);
                যদি (!attr->dyn_সূচক) {
                    attr->got_offset = s1->got->তথ্য_offset;
                    attr->plt_offset = -1;
                    attr->dyn_সূচক = 1; /* used as flag */
		    section_ptr_add(s1->got, PTR_আকার);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_offset,
                                  R_JMP_SLOT, sym_সূচক);
		    goti = tcc_realloc(goti, (mo->n_got + 1) * আকার(*goti));
                    যদি (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        যদি (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (অক্ষর *) symtab_section->link->তথ্য + sym->st_name);
			goti[mo->n_got++] = INDIRECT_প্রতীক_LOCAL;
                    } অন্যথা {
			goti[mo->n_got++] = mo->e2msym[sym_সূচক];
			যদি (sym->st_shndx == SHN_UNDEF
#ifdef TCC_TARGET_X86_64
			    && type == R_X86_64_GOTPCREL
#নতুবা_যদি defined TCC_TARGET_ARM64
			    && type == R_AARCH64_ADR_GOT_PAGE
#endif
			    ) {
			    mo->bind =
			        tcc_realloc(mo->bind,
					    (mo->n_bind + 1) *
					    আকার(কাঠামো bind));
			    mo->bind[mo->n_bind].section = s1->got->reloc->sh_info;
			    mo->bind[mo->n_bind].rel = save_rel;
                            mo->bind[mo->n_bind].rel.r_offset = attr->got_offset;
			    mo->n_bind++;
			    s1->got->reloc->তথ্য_offset -= আকার (ElfW_Rel);
			}
		    }
                }
                যদি (for_code && sym->st_shndx == SHN_UNDEF) {
                    যদি (attr->plt_offset == -1) {
                        attr->plt_offset = mo->stubs->তথ্য_offset;
#ifdef TCC_TARGET_X86_64
			যদি (type != R_X86_64_PLT32)
			     চালু;
			/* __stubs */
                        jmp = section_ptr_add(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *__la_symbol_ptr(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->তথ্য_offset - 4,
                                       R_X86_64_PC32, mo->lasym,
				       mo->la_প্রতীক_ptr->তথ্য_offset - 4);

			/* __stub_helper */
			bind_offset = mo->stub_helper->তথ্য_offset + 1;
                        jmp = section_ptr_add(mo->stub_helper, 10);
                        jmp[0] = 0x68;  /* pushq $bind_offset */
                        jmp[5] = 0xe9;  /* jmpq __stub_helper */
                        write32le(jmp + 6, -mo->stub_helper->তথ্য_offset);

			/* __la_symbol_ptr */
			la_প্রতীক_offset = mo->la_প্রতীক_ptr->তথ্য_offset;
                        put_elf_reloca(s1->symtab, mo->la_প্রতীক_ptr,
				       mo->la_প্রতীক_ptr->তথ্য_offset,
				       R_তথ্য_PTR, mo->helpsym,
				       mo->stub_helper->তথ্য_offset - 10);
			section_ptr_add(mo->la_প্রতীক_ptr, PTR_আকার);
#নতুবা_যদি defined TCC_TARGET_ARM64
			যদি (type != R_AARCH64_CALL26)
			     চালু;
			/* __stubs */
                        jmp = section_ptr_add(mo->stubs, 12);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->তথ্য_offset - 12,
                                       R_AARCH64_ADR_PREL_PG_HI21, mo->lasym,
				       mo->la_প্রতীক_ptr->তথ্য_offset);
                        write32le(jmp, // adrp x16, __la_symbol_ptr@page
                                  0x90000010);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->তথ্য_offset - 8,
                                       R_AARCH64_LDST64_ABS_LO12_NC, mo->lasym,
				       mo->la_প্রতীক_ptr->তথ্য_offset);
                        write32le(jmp + 4, // ldr x16,[x16, __la_symbol_ptr@pageoff]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);

			/* __stub_helper */
			bind_offset = mo->stub_helper->তথ্য_offset + 8;
                        jmp = section_ptr_add(mo->stub_helper, 12);
                        write32le(jmp + 0, // ldr  w16, l0
                                  0x18000050);
                        write32le(jmp + 4, // b stubHelperHeader
                                  0x14000000 +
				  ((-(mo->stub_helper->তথ্য_offset - 8) / 4) &
				   0x3ffffff));
                        write32le(jmp + 8, 0); // l0: .long bind_offset

			/* __la_symbol_ptr */
			la_প্রতীক_offset = mo->la_প্রতীক_ptr->তথ্য_offset;
                        put_elf_reloca(s1->symtab, mo->la_প্রতীক_ptr,
				       mo->la_প্রতীক_ptr->তথ্য_offset,
				       R_তথ্য_PTR, mo->helpsym,
				       mo->stub_helper->তথ্য_offset - 12);
			section_ptr_add(mo->la_প্রতীক_ptr, PTR_আকার);
#endif
                        mo->s_lazy_bind =
                            tcc_realloc(mo->s_lazy_bind, (mo->n_lazy_bind + 1) *
                                        আকার(কাঠামো s_lazy_bind));
                        mo->s_lazy_bind[mo->n_lazy_bind].section =
                            mo->stub_helper->reloc->sh_info;
                        mo->s_lazy_bind[mo->n_lazy_bind].bind_offset =
			    bind_offset;
                        mo->s_lazy_bind[mo->n_lazy_bind].la_প্রতীক_offset =
			    la_প্রতীক_offset;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel = save_rel;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel.r_offset =
                            attr->plt_offset;
                        mo->n_lazy_bind++;
			pi = section_ptr_add(mo->indirsyms, আকার(*pi));
			*pi = mo->e2msym[sym_সূচক];
			mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_offset;
                }
            }
            যদি (type == R_তথ্য_PTR || type == R_JMP_SLOT) {
		যদি (sym->st_shndx == SHN_UNDEF) {
		    mo->bind = tcc_realloc(mo->bind,
					   (mo->n_bind + 1) *
					   আকার(কাঠামো bind));
		    mo->bind[mo->n_bind].section = s->sh_info;
		    mo->bind[mo->n_bind].rel = save_rel;
		    mo->n_bind++;
		}
		অন্যথা {
                    mo->s_rebase =
                        tcc_realloc(mo->s_rebase, (mo->n_rebase + 1) *
				    আকার(কাঠামো s_rebase));
                    mo->s_rebase[mo->n_rebase].section = s->sh_info;
                    mo->s_rebase[mo->n_rebase].rel = save_rel;
                    mo->n_rebase++;
		}
	    }
        }
    }
    pi = section_ptr_add(mo->indirsyms, mo->n_got * আকার(*pi));
    memcpy(pi, goti, mo->n_got * আকার(*pi));
    pi = section_ptr_add(mo->indirsyms, mo->nr_plt * আকার(*pi));
    memcpy(pi, mo->indirsyms->তথ্য, mo->nr_plt * আকার(*pi));
    tcc_free(goti);
}
#endif

স্থির পূর্ণসংখ্যা check_symbols(TCCState *s1, কাঠামো macho *mo)
{
    পূর্ণসংখ্যা sym_সূচক, sym_end;
    পূর্ণসংখ্যা ret = 0;

    mo->ilocal = mo->iextdef = mo->iundef = -1;
    sym_end = symtab_section->তথ্য_offset / আকার(ElfW(Sym));
    জন্য (sym_সূচক = 1; sym_সূচক < sym_end; ++sym_সূচক) {
        পূর্ণসংখ্যা elf_সূচক = ((কাঠামো nlist_64 *)mo->symtab->তথ্য + sym_সূচক - 1)->n_মান;
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->তথ্য + elf_সূচক;
        ধ্রুবক অক্ষর *name = (অক্ষর*)symtab_section->link->তথ্য + sym->st_name;
        unsigned type = ELFW(ST_TYPE)(sym->st_info);
        unsigned bind = ELFW(ST_BIND)(sym->st_info);
        unsigned vis  = ELFW(ST_VISIBILITY)(sym->st_other);

        dprintf("%4d (%4d): %09lx %4d %4d %4d %3d %s\n",
                sym_সূচক, elf_সূচক, (long)sym->st_মান,
                type, bind, vis, sym->st_shndx, name);
        যদি (bind == STB_LOCAL) {
            যদি (mo->ilocal == -1)
              mo->ilocal = sym_সূচক - 1;
            যদি (mo->iextdef != -1 || mo->iundef != -1)
              tcc_error("local syms after global ones");
        } অন্যথা যদি (sym->st_shndx != SHN_UNDEF) {
            যদি (mo->iextdef == -1)
              mo->iextdef = sym_সূচক - 1;
            যদি (mo->iundef != -1)
              tcc_error("external defined symbol after undefined");
        } অন্যথা যদি (sym->st_shndx == SHN_UNDEF) {
            যদি (mo->iundef == -1)
              mo->iundef = sym_সূচক - 1;
            যদি (ELFW(ST_BIND)(sym->st_info) == STB_WEAK
		|| s1->output_type != TCC_OUTPUT_EXE
                || find_elf_sym(s1->dynsymtab_section, name)) {
                /* Mark the symbol as coming from a dylib so that
                   relocate_syms doesn't complain.  Normally bind_exe_dynsyms
                   would do this check, and place the symbol into dynsym
                   which is checked by relocate_syms.  But Mach-O doesn't use
                   bind_exe_dynsyms.  */
                sym->st_shndx = SHN_FROMDLL;
                চালু;
            }
            tcc_error_noabort("unresolved reference to '%s'", name);
            ret = -1;
        }
    }
    ফেরত ret;
}

স্থির শূন্য convert_প্রতীক(TCCState *s1, কাঠামো macho *mo, কাঠামো nlist_64 *pn)
{
    কাঠামো nlist_64 n = *pn;
    ElfSym *sym = (ElfW(Sym) *)symtab_section->তথ্য + pn->n_মান;
    ধ্রুবক অক্ষর *name = (অক্ষর*)symtab_section->link->তথ্য + sym->st_name;
    নির্বাচন(ELFW(ST_TYPE)(sym->st_info)) {
    ক্ষেত্র STT_NOTYPE:
    ক্ষেত্র STT_OBJECT:
    ক্ষেত্র STT_FUNC:
    ক্ষেত্র STT_TLS:
    ক্ষেত্র STT_SECTION:
        n.n_type = N_SECT;
        বিরতি;
    ক্ষেত্র STT_FILE:
        n.n_type = N_ABS;
        বিরতি;
    পূর্বনির্ধারিত:
        tcc_error("unhandled ELF symbol type %d %s",
                  ELFW(ST_TYPE)(sym->st_info), name);
    }
    যদি (sym->st_shndx == SHN_UNDEF)
      tcc_error("should have been rewritten to SHN_FROMDLL: %s", name);
    অন্যথা যদি (sym->st_shndx == SHN_FROMDLL)
      n.n_type = N_UNDF, n.n_sect = 0;
    অন্যথা যদি (sym->st_shndx == SHN_ABS)
      n.n_type = N_ABS, n.n_sect = 0;
    অন্যথা যদি (sym->st_shndx >= SHN_LORESERVE)
      tcc_error("unhandled ELF symbol section %d %s", sym->st_shndx, name);
    অন্যথা যদি (!mo->elfsectomacho[sym->st_shndx]) {
      যদি (strncmp(s1->sections[sym->st_shndx]->name, ".debug_", 7))
        tcc_error("ELF section %d(%s) not mapped into Mach-O for symbol %s",
                  sym->st_shndx, s1->sections[sym->st_shndx]->name, name);
    }
    অন্যথা
      n.n_sect = mo->elfsectomacho[sym->st_shndx];
    যদি (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL)
      n.n_type |=  N_EXT;
    অন্যথা যদি (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
      n.n_desc |= N_WEAK_REF | (n.n_type != N_UNDF ? N_WEAK_DEF : 0);
    n.n_strx = pn->n_strx;
    n.n_মান = sym->st_মান;
    *pn = n;
}

স্থির শূন্য convert_symbols(TCCState *s1, কাঠামো macho *mo)
{
    কাঠামো nlist_64 *pn;
    for_each_elem(mo->symtab, 0, pn, কাঠামো nlist_64)
        convert_প্রতীক(s1, mo, pn);
}

স্থির পূর্ণসংখ্যা machosymcmp(ধ্রুবক শূন্য *_a, ধ্রুবক শূন্য *_b, শূন্য *arg)
{
    TCCState *s1 = arg;
    পূর্ণসংখ্যা ea = ((কাঠামো nlist_64 *)_a)->n_মান;
    পূর্ণসংখ্যা eb = ((কাঠামো nlist_64 *)_b)->n_মান;
    ElfSym *sa = (ElfSym *)symtab_section->তথ্য + ea;
    ElfSym *sb = (ElfSym *)symtab_section->তথ্য + eb;
    পূর্ণসংখ্যা r;
    /* locals, then defined externals, then undefined externals, the
       last two sections also by name, otherwise stable sort */
    r = (ELFW(ST_BIND)(sb->st_info) == STB_LOCAL)
        - (ELFW(ST_BIND)(sa->st_info) == STB_LOCAL);
    যদি (r)
      ফেরত r;
    r = (sa->st_shndx == SHN_UNDEF) - (sb->st_shndx == SHN_UNDEF);
    যদি (r)
      ফেরত r;
    যদি (ELFW(ST_BIND)(sa->st_info) != STB_LOCAL) {
        ধ্রুবক অক্ষর * na = (অক্ষর*)symtab_section->link->তথ্য + sa->st_name;
        ধ্রুবক অক্ষর * nb = (অক্ষর*)symtab_section->link->তথ্য + sb->st_name;
        r = strcmp(na, nb);
        যদি (r)
          ফেরত r;
    }
    ফেরত ea - eb;
}

/* cannot use qsort because code has to be reentrant */
স্থির শূন্য tcc_qsort (শূন্য  *base, আকার_t nel, আকার_t width,
                       পূর্ণসংখ্যা (*comp)(ধ্রুবক শূন্য *, ধ্রুবক শূন্য *, শূন্য *), শূন্য *arg)
{
    আকার_t wnel, gap, wgap, i, j, k;
    অক্ষর *a, *b, tmp;

    wnel = width * nel;
    জন্য (gap = 0; ++gap < nel;)
        gap *= 3;
    যখন ( gap /= 3 ) {
        wgap = width * gap;
        জন্য (i = wgap; i < wnel; i += width) {
            জন্য (j = i - wgap; ;j -= wgap) {
                a = j + (অক্ষর *)base;
                b = a + wgap;
                যদি ( (*comp)(a, b, arg) <= 0 )
                    বিরতি;
                k = width;
                করো {
                    tmp = *a;
                    *a++ = *b;
                    *b++ = tmp;
                } যখন ( --k );
                যদি (j < wgap)
                    বিরতি;
            }
        }
    }
}

স্থির শূন্য create_symtab(TCCState *s1, কাঠামো macho *mo)
{
    পূর্ণসংখ্যা sym_সূচক, sym_end;
    কাঠামো nlist_64 *pn;

    /* Stub creation belongs to check_relocs, but we need to create
       the symbol now, so its included in the sorting.  */
    mo->stubs = new_section(s1, "__stubs", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->stubsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stubs->sh_অঙ্ক, ".__stubs");
#ifdef CONFIG_NEW_MACHO
    mo->chained_fixups = new_section(s1, "CHAINED_FIXUPS",
				     SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#অন্যথা
    mo->stub_helper = new_section(s1, "__stub_helper", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    mo->la_প্রতীক_ptr = new_section(s1, "__la_symbol_ptr", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->helpsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stub_helper->sh_অঙ্ক, ".__stub_helper");
    mo->lasym = put_elf_sym(s1->symtab, 0, 0,
                            ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                            mo->la_প্রতীক_ptr->sh_অঙ্ক, ".__la_symbol_ptr");
    section_ptr_add(তথ্য_section, -তথ্য_section->তথ্য_offset & (PTR_আকার - 1));
    mo->dyld_private = put_elf_sym(s1->symtab, তথ্য_section->তথ্য_offset, PTR_আকার,
                                   ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT), 0,
                                   তথ্য_section->sh_অঙ্ক, ".__dyld_private");
    section_ptr_add(তথ্য_section, PTR_আকার);
    mo->dyld_stub_binder = put_elf_sym(s1->symtab, 0, 0,
                		       ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				       SHN_UNDEF, "dyld_stub_binder");
    mo->rebase = new_section(s1, "REBASE", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->binding = new_section(s1, "BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->weak_binding = new_section(s1, "WEAK_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->lazy_binding = new_section(s1, "LAZY_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#endif
    mo->exports = new_section(s1, "EXPORT", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->indirsyms = new_section(s1, "LEINDIR", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);

    mo->symtab = new_section(s1, "LESYMTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->strtab = new_section(s1, "LESTRTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    put_elf_str(mo->strtab, " "); /* Mach-O starts strtab with a space */
    sym_end = symtab_section->তথ্য_offset / আকার(ElfW(Sym));
    pn = section_ptr_add(mo->symtab, আকার(*pn) * (sym_end - 1));
    জন্য (sym_সূচক = 1; sym_সূচক < sym_end; ++sym_সূচক) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->তথ্য + sym_সূচক;
        ধ্রুবক অক্ষর *name = (অক্ষর*)symtab_section->link->তথ্য + sym->st_name;
        pn[sym_সূচক - 1].n_strx = put_elf_str(mo->strtab, name);
        pn[sym_সূচক - 1].n_মান = sym_সূচক;
    }
    section_ptr_add(mo->strtab, -mo->strtab->তথ্য_offset & (PTR_আকার - 1));
    tcc_qsort(pn, sym_end - 1, আকার(*pn), machosymcmp, s1);
    mo->e2msym = tcc_malloc(sym_end * আকার(*mo->e2msym));
    mo->e2msym[0] = -1;
    জন্য (sym_সূচক = 1; sym_সূচক < sym_end; ++sym_সূচক) {
        mo->e2msym[pn[sym_সূচক - 1].n_মান] = sym_সূচক - 1;
    }
}

ধ্রুবক কাঠামো {
    পূর্ণসংখ্যা seg_initial;
    uint32_t flags;
    ধ্রুবক অক্ষর *name;
} skinfo[sk_last] = {
    /*[sk_unknown] =*/        { 0 },
    /*[sk_discard] =*/        { 0 },
    /*[sk_text] =*/           { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS, "__text" },
    /*[sk_stubs] =*/          { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS | S_প্রতীক_STUBS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stubs" },
    /*[sk_stub_helper] =*/    { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stub_helper" },
    /*[sk_ro_data] =*/        { 2, S_REGULAR, "__rodata" },
    /*[sk_uw_info] =*/        { 0 },
    /*[sk_nl_ptr] =*/         { 2, S_NON_LAZY_প্রতীক_POINTERS, "__got" },
    /*[sk_debug_info] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_info" },
    /*[sk_debug_abbrev] =*/   { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_abbrev" },
    /*[sk_debug_line] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line" },
    /*[sk_debug_aranges] =*/  { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_aranges" },
    /*[sk_debug_str] =*/      { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_str" },
    /*[sk_debug_line_str] =*/ { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line_str" },
    /*[sk_stab] =*/           { 4, S_REGULAR, "__stab" },
    /*[sk_stab_str] =*/       { 4, S_REGULAR, "__stab_str" },
    /*[sk_la_ptr] =*/         { 4, S_LAZY_প্রতীক_POINTERS, "__la_symbol_ptr" },
    /*[sk_init] =*/           { 4, S_MOD_INIT_FUNC_POINTERS, "__mod_init_func" },
    /*[sk_fini] =*/           { 4, S_MOD_TERM_FUNC_POINTERS, "__mod_term_func" },
    /*[sk_rw_data] =*/        { 4, S_REGULAR, "__data" },
    /*[sk_bss] =*/            { 4, S_ZEROFILL, "__bss" },
    /*[sk_linkedit] =*/       { 5, S_REGULAR, ফাঁকা },
};

#define	START	((uint64_t)1 << 32)

ধ্রুবক কাঠামো {
    পূর্ণসংখ্যা used;
    ধ্রুবক অক্ষর *name;
    uint64_t vmaddr;
    uint64_t vmsize;
    vm_prot_t maxprot;
    vm_prot_t initprot;
    uint32_t flags;
} all_segment[] = {
    { 1, "__PAGEZERO",       0, START, 0, 0,            0 },
    { 0, "__TEXT",       START,     0, 5, 5,            0 },
    { 0, "__DATA_CONST",    -1,     0, 3, 3, SG_READ_ONLY },
    { 0, "__DWARF",         -1,     0, 7, 3,            0 },
    { 0, "__DATA",          -1,     0, 3, 3,            0 },
    { 1, "__LINKEDIT",      -1,     0, 1, 1,            0 },
};

#define	N_SEGMENT	(আকার(all_segment)/আকার(all_segment[0]))

#ifdef CONFIG_NEW_MACHO
স্থির শূন্য calc_fixup_আকার(TCCState *s1, কাঠামো macho *mo)
{
    পূর্ণসংখ্যা i, আকার_2;

    আকার_2 = (আকার(কাঠামো dyld_chained_fixups_header) + 7) & -8;
    আকার_2 += (আকার(কাঠামো dyld_chained_starts_in_image) + (mo->nseg - 1) * আকার(uint32_t) + 7) & -8;
    জন্য (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	পূর্ণসংখ্যা page_গুনতি = (get_segment(mo, i)->vmsize + SEG_PAGE_আকার - 1) / SEG_PAGE_আকার;
	আকার_2 += (আকার(কাঠামো dyld_chained_starts_in_segment) + (page_গুনতি - 1) * আকার(uint16_t) + 7) & -8;
    }
    আকার_2 += mo->n_bind * আকার (কাঠামো dyld_chained_import) + 1;
    জন্য (i = 0; i < mo->n_bind_rebase; i++) {
	যদি (mo->bind_rebase[i].bind) {
	    পূর্ণসংখ্যা sym_সূচক = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->তথ্য)[sym_সূচক];
	    ধ্রুবক অক্ষর *name = (অক্ষর *) symtab_section->link->তথ্য + sym->st_name;
	    আকার_2 += strlen(name) + 1;
	}
    }
    আকার_2 = (আকার_2 + 7) & -8;
    section_ptr_add(mo->chained_fixups, আকার_2);
}

#অন্যথা

স্থির শূন্য set_segment_and_offset(TCCState *s1, কাঠামো macho *mo, addr_t addr,
				   uint8_t *ptr, পূর্ণসংখ্যা opcode,
				   Section *sec, addr_t offset)
{
    পূর্ণসংখ্যা i;
    কাঠামো segment_command_64 *seg = ফাঁকা;

    জন্য (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	seg = get_segment(mo, i);
	যদি (addr >= seg->vmaddr && addr < (seg->vmaddr + seg->vmsize))
	    বিরতি;
    }
    *ptr = opcode | i;
    write_uleb128(sec, offset - seg->vmaddr);
}

স্থির শূন্য bind_rebase(TCCState *s1, কাঠামো macho *mo)
{
    পূর্ণসংখ্যা i;
    uint8_t *ptr;
    ElfW(Sym) *sym;
    ধ্রুবক অক্ষর *name;

    জন্য (i = 0; i < mo->n_lazy_bind; i++) {
	পূর্ণসংখ্যা sym_সূচক = ELFW(R_SYM)(mo->s_lazy_bind[i].rel.r_info);

	sym = &((ElfW(Sym) *)symtab_section->তথ্য)[sym_সূচক];
	name = (অক্ষর *) symtab_section->link->তথ্য + sym->st_name;
	write32le(mo->stub_helper->তথ্য +
		  mo->s_lazy_bind[i].bind_offset,
		  mo->lazy_binding->তথ্য_offset);
	ptr = section_ptr_add(mo->lazy_binding, 1);
	set_segment_and_offset(s1, mo, mo->la_প্রতীক_ptr->sh_addr, ptr,
			       BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB,
			       mo->lazy_binding,
			       mo->s_lazy_bind[i].la_প্রতীক_offset +
			       mo->la_প্রতীক_ptr->sh_addr);
	ptr = section_ptr_add(mo->lazy_binding, 5 + strlen(name));
	*ptr++ = BIND_OPCODE_SET_DYLIB_SPECIAL_IMM |
		 (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
	*ptr++ = BIND_OPCODE_SET_প্রতীক_TRAILING_FLAGS_IMM | 0;
	strcpy((অক্ষর *)ptr, name);
	ptr += strlen(name) + 1;
	*ptr++ = BIND_OPCODE_DO_BIND;
	*ptr = BIND_OPCODE_DONE;
    }
    জন্য (i = 0; i < mo->n_rebase; i++) {
	Section *s = s1->sections[mo->s_rebase[i].section];

	ptr = section_ptr_add(mo->rebase, 2);
	*ptr++ = REBASE_OPCODE_SET_TYPE_IMM | REBASE_TYPE_POINTER;
	set_segment_and_offset(s1, mo, s->sh_addr, ptr,
			       REBASE_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB,
			       mo->rebase,
			       mo->s_rebase[i].rel.r_offset +
			       s->sh_addr);
	ptr = section_ptr_add(mo->rebase, 1);
	*ptr = REBASE_OPCODE_DO_REBASE_IMM_TIMES | 1;
    }
    জন্য (i = 0; i < mo->n_bind; i++) {
	পূর্ণসংখ্যা sym_সূচক = ELFW(R_SYM)(mo->bind[i].rel.r_info);
	Section *s = s1->sections[mo->bind[i].section];
	Section *binding;

	sym = &((ElfW(Sym) *)symtab_section->তথ্য)[sym_সূচক];
	name = (অক্ষর *) symtab_section->link->তথ্য + sym->st_name;
	binding = ELFW(ST_BIND)(sym->st_info) == STB_WEAK
	    ? mo->weak_binding : mo->binding;
        ptr = section_ptr_add(binding, 4 + (binding == mo->binding) +
			     	       strlen(name));
	যদি (binding == mo->binding)
            *ptr++ = BIND_OPCODE_SET_DYLIB_SPECIAL_IMM |
	             (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
        *ptr++ = BIND_OPCODE_SET_প্রতীক_TRAILING_FLAGS_IMM |
		 (binding == mo->weak_binding
		  ? BIND_প্রতীক_FLAGS_WEAK_IMPORT : 0);
        strcpy((অক্ষর *)ptr, name);
        ptr += strlen(name) + 1;
        *ptr++ = BIND_OPCODE_SET_TYPE_IMM | BIND_TYPE_POINTER;
	set_segment_and_offset(s1, mo, s->sh_addr, ptr,
			       BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB,
			       binding,
			       mo->bind[i].rel.r_offset + s->sh_addr);
        ptr = section_ptr_add(binding, 1);
        *ptr++ = BIND_OPCODE_DO_BIND;
    }
    যদি (mo->rebase->তথ্য_offset) {
        ptr = section_ptr_add(mo->rebase, 1);
        *ptr = REBASE_OPCODE_DONE;
    }
    যদি (mo->binding->তথ্য_offset) {
        ptr = section_ptr_add(mo->binding, 1);
        *ptr = BIND_OPCODE_DONE;
    }
    যদি (mo->weak_binding->তথ্য_offset) {
        ptr = section_ptr_add(mo->weak_binding, 1);
        *ptr = BIND_OPCODE_DONE;
    }
    tcc_free(mo->s_lazy_bind);
    tcc_free(mo->s_rebase);
    tcc_free(mo->bind);
}
#endif

কাঠামো trie_info {
    ধ্রুবক অক্ষর *name;
    পূর্ণসংখ্যা flag;
    addr_t addr;
    পূর্ণসংখ্যা str_আকার;
    পূর্ণসংখ্যা term_আকার;
};

কাঠামো trie_গ্রন্থি {
    পূর্ণসংখ্যা start;
    পূর্ণসংখ্যা end;
    পূর্ণসংখ্যা সূচক_start;
    পূর্ণসংখ্যা সূচক_end;
    পূর্ণসংখ্যা n_child;
    কাঠামো trie_গ্রন্থি *child;
};

কাঠামো trie_seq {
    পূর্ণসংখ্যা n_child;
    কাঠামো trie_গ্রন্থি *গ্রন্থি;
    পূর্ণসংখ্যা offset;
    পূর্ণসংখ্যা nest_offset;
};

স্থির শূন্য create_trie(কাঠামো trie_গ্রন্থি *গ্রন্থি,
                        পূর্ণসংখ্যা from, পূর্ণসংখ্যা to, পূর্ণসংখ্যা সূচক_start,
                        পূর্ণসংখ্যা n_trie, কাঠামো trie_info *trie)
{
    পূর্ণসংখ্যা i;
    পূর্ণসংখ্যা start, end, সূচক_end;
    অক্ষর cur;
    কাঠামো trie_গ্রন্থি *child;

    জন্য (i = from; i < to; i = end) {
        cur = trie[i].name[সূচক_start];
        start = i++;
        জন্য (; i < to; i++)
            যদি (cur != trie[i].name[সূচক_start])
                বিরতি;
        end = i;
        যদি (start == end - 1 ||
            (trie[start].name[সূচক_start] &&
             trie[start].name[সূচক_start + 1] == 0))
            সূচক_end = trie[start].str_আকার - 1;
        অন্যথা {
            সূচক_end = সূচক_start + 1;
            জন্য (;;) {
                cur = trie[start].name[সূচক_end];
                জন্য (i = start + 1; i < end; i++)
                    যদি (cur != trie[i].name[সূচক_end])
                        বিরতি;
                যদি (trie[start].name[সূচক_end] &&
                    trie[start].name[সূচক_end + 1] == 0) {
                    end = start + 1;
                    সূচক_end = trie[start].str_আকার - 1;
                    বিরতি;
                }
                যদি (i != end)
                    বিরতি;
                সূচক_end++;
            }
        }
        গ্রন্থি->child = tcc_realloc(গ্রন্থি->child,
                                  (গ্রন্থি->n_child + 1) *
                                  আকার(কাঠামো trie_গ্রন্থি));
        child = &গ্রন্থি->child[গ্রন্থি->n_child];
        child->start = start;
        child->end = end;
        child->সূচক_start = সূচক_start;
        child->সূচক_end = সূচক_end;
        child->n_child = 0;
        child->child = ফাঁকা;
        গ্রন্থি->n_child++;
        যদি (start != end - 1)
            create_trie(child, start, end, সূচক_end, n_trie, trie);
    }
}

স্থির পূর্ণসংখ্যা create_seq(পূর্ণসংখ্যা *offset, পূর্ণসংখ্যা *n_seq, কাঠামো trie_seq **seq,
                        কাঠামো trie_গ্রন্থি *গ্রন্থি,
                        পূর্ণসংখ্যা n_trie, কাঠামো trie_info *trie)
{
    পূর্ণসংখ্যা i, nest_offset, last_seq = *n_seq, retval = *offset;
    কাঠামো trie_seq *p_seq;
    কাঠামো trie_গ্রন্থি *p_nest;

    জন্য (i = 0; i < গ্রন্থি->n_child; i++) {
        p_nest = &গ্রন্থি->child[i];
        *seq = tcc_realloc(*seq, (*n_seq + 1) * আকার(কাঠামো trie_seq));
        p_seq = &(*seq)[(*n_seq)++];
        p_seq->n_child = i == 0 ? গ্রন্থি->n_child : -1;
        p_seq->গ্রন্থি = p_nest;
        p_seq->offset = *offset;
        p_seq->nest_offset = 0;
        *offset += (i == 0 ? 1 + 1 : 0) +
                   p_nest->সূচক_end - p_nest->সূচক_start + 1 + 3;
    }
    জন্য (i = 0; i < গ্রন্থি->n_child; i++) {
        nest_offset =
            create_seq(offset, n_seq, seq, &গ্রন্থি->child[i], n_trie, trie);
        p_seq = &(*seq)[last_seq + i];
        p_seq->nest_offset = nest_offset;
    }
    ফেরত retval;
}

স্থির শূন্য গ্রন্থি_free(কাঠামো trie_গ্রন্থি *গ্রন্থি)
{
    পূর্ণসংখ্যা i;

    জন্য (i = 0; i < গ্রন্থি->n_child; i++)
	গ্রন্থি_free(&গ্রন্থি->child[i]);
    tcc_free(গ্রন্থি->child);
}

স্থির পূর্ণসংখ্যা triecmp(ধ্রুবক শূন্য *_a, ধ্রুবক শূন্য *_b, শূন্য *arg)
{
    কাঠামো trie_info *a = (কাঠামো trie_info *) _a;
    কাঠামো trie_info *b = (কাঠামো trie_info *) _b;
    পূর্ণসংখ্যা len_a = strlen(a->name);
    পূর্ণসংখ্যা len_b = strlen(b->name);

    /* strange sorting needed. Name 'xx' should be after 'xx1' */
    যদি (!strncmp(a->name, b->name, len_a < len_b ? len_a : len_b))
	ফেরত len_a < len_b ? 1 : (len_a > len_b ? -1 : 0);
    ফেরত strcmp(a->name, b->name);
}

স্থির শূন্য export_trie(TCCState *s1, কাঠামো macho *mo)
{
    পূর্ণসংখ্যা i, আকার_2, offset = 0, save_offset;
    uint8_t *ptr;
    পূর্ণসংখ্যা sym_সূচক;
    পূর্ণসংখ্যা sym_end = symtab_section->তথ্য_offset / আকার(ElfW(Sym));
    পূর্ণসংখ্যা n_trie = 0, n_seq = 0;
    কাঠামো trie_info *trie = ফাঁকা, *p_trie;
    কাঠামো trie_গ্রন্থি গ্রন্থি, *p_গ্রন্থি;
    কাঠামো trie_seq *seq = ফাঁকা;
    addr_t vm_addr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;

    জন্য (sym_সূচক = 1; sym_সূচক < sym_end; ++sym_সূচক) {
	ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->তথ্য + sym_সূচক;
	ধ্রুবক অক্ষর *name = (অক্ষর*)symtab_section->link->তথ্য + sym->st_name;

	যদি (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE &&
            (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL ||
	     ELFW(ST_BIND)(sym->st_info) == STB_WEAK)) {
	    পূর্ণসংখ্যা flag = EXPORT_প্রতীক_FLAGS_KIND_REGULAR;
	    addr_t addr =
		sym->st_মান + s1->sections[sym->st_shndx]->sh_addr - vm_addr;

	    যদি (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
		flag |= EXPORT_প্রতীক_FLAGS_WEAK_DEFINITION;
	    dprintf ("%s %d %llx\n", name, flag, (long long)addr + vm_addr);
	    trie = tcc_realloc(trie, (n_trie + 1) * আকার(কাঠামো trie_info));
	    trie[n_trie].name = name;
	    trie[n_trie].flag = flag;
	    trie[n_trie].addr = addr;
	    trie[n_trie].str_আকার = strlen(name) + 1;
	    trie[n_trie].term_আকার = uleb128_আকার(flag) + uleb128_আকার(addr);
	    n_trie++;
	}
    }
    যদি (n_trie) {
        tcc_qsort(trie, n_trie, আকার(কাঠামো trie_info), triecmp, ফাঁকা);
	memset(&গ্রন্থি, 0, আকার(গ্রন্থি));
        create_trie(&গ্রন্থি, 0, n_trie, 0, n_trie, trie);
	create_seq(&offset, &n_seq, &seq, &গ্রন্থি, n_trie, trie);
        save_offset = offset;
        জন্য (i = 0; i < n_seq; i++) {
            p_গ্রন্থি = seq[i].গ্রন্থি;
            যদি (p_গ্রন্থি->n_child == 0) {
                p_trie = &trie[p_গ্রন্থি->start];
                seq[i].nest_offset = offset;
                offset += 1 + p_trie->term_আকার + 1;
            }
        }
        জন্য (i = 0; i < n_seq; i++) {
            p_গ্রন্থি = seq[i].গ্রন্থি;
            p_trie = &trie[p_গ্রন্থি->start];
            যদি (seq[i].n_child >= 0) {
                section_ptr_add(mo->exports,
				seq[i].offset - mo->exports->তথ্য_offset);
                ptr = section_ptr_add(mo->exports, 2);
                *ptr++ = 0;
                *ptr = seq[i].n_child;
            }
            আকার_2 = p_গ্রন্থি->সূচক_end - p_গ্রন্থি->সূচক_start;
            ptr = section_ptr_add(mo->exports, আকার_2 + 1);
            memcpy(ptr, &p_trie->name[p_গ্রন্থি->সূচক_start], আকার_2);
            ptr[আকার_2] = 0;
            write_uleb128(mo->exports, seq[i].nest_offset);
        }
        section_ptr_add(mo->exports, save_offset - mo->exports->তথ্য_offset);
        জন্য (i = 0; i < n_seq; i++) {
            p_গ্রন্থি = seq[i].গ্রন্থি;
            যদি (p_গ্রন্থি->n_child == 0) {
                p_trie = &trie[p_গ্রন্থি->start];
                write_uleb128(mo->exports, p_trie->term_আকার);
                write_uleb128(mo->exports, p_trie->flag);
                write_uleb128(mo->exports, p_trie->addr);
                ptr = section_ptr_add(mo->exports, 1);
                *ptr = 0;
            }
        }
        section_ptr_add(mo->exports, -mo->exports->তথ্য_offset & 7);
	গ্রন্থি_free(&গ্রন্থি);
        tcc_free(seq);
    }
    tcc_free(trie);
}

স্থির শূন্য collect_sections(TCCState *s1, কাঠামো macho *mo, ধ্রুবক অক্ষর *filename)
{
    পূর্ণসংখ্যা i, sk, numsec;
    পূর্ণসংখ্যা used_segment[N_SEGMENT];
    uint64_t curaddr, fileofs;
    Section *s;
    কাঠামো segment_command_64 *seg;
    কাঠামো dylib_command *dylib;
#ifdef CONFIG_NEW_MACHO
    কাঠামো linkedit_তথ্য_command *chained_fixups_lc;
    কাঠামো linkedit_তথ্য_command *export_trie_lc;
#endif
    কাঠামো build_version_command *dyldbv;
    কাঠামো source_version_command *dyldsv;
    কাঠামো rpath_command *rpath;
    কাঠামো dylinker_command *dyldlc;
    কাঠামো symtab_command *symlc;
    কাঠামো dysymtab_command *dysymlc;
    অক্ষর *str;

    জন্য (i = 0; i < N_SEGMENT; i++)
	used_segment[i] = all_segment[i].used;

    memset (mo->sk_to_sect, 0, আকার(mo->sk_to_sect));
    জন্য (i = s1->nb_sections; i-- > 1;) {
        পূর্ণসংখ্যা type, flags;
        s = s1->sections[i];
        type = s->sh_type;
        flags = s->sh_flags;
        sk = sk_unknown;
	/* debug sections have sometimes no SHF_ALLOC */
        যদি ((flags & SHF_ALLOC) || !strncmp(s->name, ".debug_", 7)) {
            নির্বাচন (type) {
            পূর্বনির্ধারিত:           sk = sk_unknown; বিরতি;
            ক্ষেত্র SHT_INIT_ARRAY: sk = sk_init; বিরতি;
            ক্ষেত্র SHT_FINI_ARRAY: sk = sk_fini; বিরতি;
            ক্ষেত্র SHT_NOBITS:   sk = sk_bss; বিরতি;
            ক্ষেত্র SHT_SYMTAB:   sk = sk_discard; বিরতি;
            ক্ষেত্র SHT_STRTAB:
		যদি (s == stabstr_section)
		  sk = sk_stab_str;
		অন্যথা
		  sk = sk_discard;
		বিরতি;
            ক্ষেত্র SHT_RELX:     sk = sk_discard; বিরতি;
            ক্ষেত্র SHT_LINKEDIT: sk = sk_linkedit; বিরতি;
            ক্ষেত্র SHT_PROGBITS:
                যদি (s == mo->stubs)
                  sk = sk_stubs;
#ifndef CONFIG_NEW_MACHO
                অন্যথা যদি (s == mo->stub_helper)
                  sk = sk_stub_helper;
                অন্যথা যদি (s == mo->la_প্রতীক_ptr)
                  sk = sk_la_ptr;
#endif
                অন্যথা যদি (s == rodata_section)
                  sk = sk_ro_তথ্য;
                অন্যথা যদি (s == s1->got)
                  sk = sk_nl_ptr;
                অন্যথা যদি (s == stab_section)
                  sk = sk_stab;
                অন্যথা যদি (s == dwarf_info_section)
                  sk = sk_debug_info;
                অন্যথা যদি (s == dwarf_abbrev_section)
                  sk = sk_debug_abbrev;
                অন্যথা যদি (s == dwarf_সারি_section)
                  sk = sk_debug_সারি;
                অন্যথা যদি (s == dwarf_aranges_section)
                  sk = sk_debug_aranges;
                অন্যথা যদি (s == dwarf_str_section)
                  sk = sk_debug_str;
                অন্যথা যদি (s == dwarf_সারি_str_section)
                  sk = sk_debug_সারি_str;
                অন্যথা যদি (flags & SHF_EXECINSTR)
                  sk = sk_text;
                অন্যথা যদি (flags & SHF_WRITE)
                  sk = sk_rw_তথ্য;
                অন্যথা
                  sk = sk_ro_তথ্য;
                বিরতি;
            }
        } অন্যথা
          sk = sk_discard;
        s->পূর্ব = mo->sk_to_sect[sk].s;
        mo->sk_to_sect[sk].s = s;
	used_segment[skinfo[sk].seg_initial] = 1;
    }

    যদি (s1->output_type != TCC_OUTPUT_EXE)
	used_segment[0] = 0;

    জন্য (i = 0; i < N_SEGMENT; i++)
	যদি (used_segment[i]) {
	    seg = add_segment(mo, all_segment[i].name);
	    যদি (i == 1 && s1->output_type != TCC_OUTPUT_EXE)
	        seg->vmaddr = 0;
	    অন্যথা
	        seg->vmaddr = all_segment[i].vmaddr;
	    seg->vmsize = all_segment[i].vmsize;
	    seg->maxprot = all_segment[i].maxprot;
	    seg->initprot = all_segment[i].initprot;
	    seg->flags = all_segment[i].flags;
            জন্য (sk = sk_unknown; sk < sk_last; sk++)
		যদি (skinfo[sk].seg_initial == i)
	            mo->segment[sk] = mo->nseg - 1;
	}

    যদি (s1->output_type != TCC_OUTPUT_EXE) {
	ধ্রুবক অক্ষর *name = s1->install_name ? s1->install_name : filename;
        i = (আকার(*dylib) + strlen(name) + 1 + 7) &-8;
        dylib = add_lc(mo, LC_ID_DYLIB, i);
	dylib->name = আকার(*dylib);
	dylib->timestamp = 1;
	dylib->current_version =
	    s1->current_version ? s1->current_version : 1 << 16;
	dylib->compatibility_version =
	    s1->compatibility_version ? s1->compatibility_version : 1 << 16;
        str = (অক্ষর*)dylib + dylib->name;
        strcpy(str, name);
    }

#ifdef CONFIG_NEW_MACHO
    chained_fixups_lc = add_lc(mo, LC_DYLD_CHAINED_FIXUPS,
			       আকার(কাঠামো linkedit_তথ্য_command));
    export_trie_lc = add_lc(mo, LC_DYLD_EXPORTS_TRIE,
			    আকার(কাঠামো linkedit_তথ্য_command));
#অন্যথা
    mo->dyldinfo = add_lc(mo, LC_DYLD_INFO_ONLY, আকার(*mo->dyldinfo));
#endif

    symlc = add_lc(mo, LC_SYMTAB, আকার(*symlc));
    dysymlc = add_lc(mo, LC_DYSYMTAB, আকার(*dysymlc));

    যদি (s1->output_type == TCC_OUTPUT_EXE) {
        i = (আকার(*dyldlc) + strlen("/usr/lib/dyld") + 1 + 7) &-8;
        dyldlc = add_lc(mo, LC_LOAD_DYLINKER, i);
        dyldlc->name = আকার(*dyldlc);
        str = (অক্ষর*)dyldlc + dyldlc->name;
        strcpy(str, "/usr/lib/dyld");
    }

    dyldbv = add_lc(mo, LC_BUILD_VERSION, আকার(*dyldbv));
    dyldbv->platform = PLATFORM_MACOS;
    dyldbv->minos = (10 << 16) + (6 << 8);
    dyldbv->sdk = (10 << 16) + (6 << 8);
    dyldbv->ntools = 0;

    dyldsv = add_lc(mo, LC_SOURCE_VERSION, আকার(*dyldsv));
    dyldsv->version = 0;

    যদি (s1->output_type == TCC_OUTPUT_EXE) {
        mo->ep = add_lc(mo, LC_MAIN, আকার(*mo->ep));
        mo->ep->entryoff = 4096;
    }

    জন্য(i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *dllref = s1->loaded_dlls[i];
        যদি (dllref->level == 0)
          add_dylib(mo, dllref->name);
    }

    যদি (s1->rpath) {
	অক্ষর *path = s1->rpath, *end;
	করো {
	    end = strchr(path, ':');
	    যদি (!end)
		end = strchr(path, 0);
            i = (আকার(*rpath) + (end - path) + 1 + 7) &-8;
            rpath = add_lc(mo, LC_RPATH, i);
            rpath->path = আকার(*rpath);
            str = (অক্ষর*)rpath + rpath->path;
            memcpy(str, path, end - path);
	    str[end - path] = 0;
	    path = end + 1;
	} যখন (*end);
    }

    fileofs = 4096;  /* leave space for mach-o headers */
    curaddr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;
    curaddr += 4096;
    seg = ফাঁকা;
    numsec = 0;
    mo->elfsectomacho = tcc_mallocz(আকার(*mo->elfsectomacho) * s1->nb_sections);
    জন্য (sk = sk_unknown; sk < sk_last; sk++) {
        কাঠামো section_64 *sec = ফাঁকা;
        যদি (seg) {
            seg->vmsize = curaddr - seg->vmaddr;
            seg->filesize = fileofs - seg->fileoff;
        }
#ifdef CONFIG_NEW_MACHO
	যদি (sk == sk_linkedit) {
	    calc_fixup_আকার(s1, mo);
	    export_trie(s1, mo);
	}
#অন্যথা
	যদি (sk == sk_linkedit) {
	    bind_rebase(s1, mo);
	    export_trie(s1, mo);
	}
#endif
        যদি (skinfo[sk].seg_initial &&
	    (s1->output_type != TCC_OUTPUT_EXE || mo->segment[sk]) &&
	    mo->sk_to_sect[sk].s) {
            uint64_t al = 0;
            পূর্ণসংখ্যা si;
            seg = get_segment(mo, mo->segment[sk]);
            যদি (skinfo[sk].name) {
                si = add_section(mo, &seg, skinfo[sk].name);
                numsec++;
                mo->lc[mo->seg2lc[mo->segment[sk]]] = (কাঠামো load_command*)seg;
                mo->sk_to_sect[sk].machosect = si;
                sec = get_section(seg, si);
                sec->flags = skinfo[sk].flags;
		যদি (sk == sk_stubs)
#ifdef TCC_TARGET_X86_64
	    	    sec->reserved2 = 6;
#নতুবা_যদি defined TCC_TARGET_ARM64
	    	    sec->reserved2 = 12;
#endif
		যদি (sk == sk_nl_ptr)
	    	    sec->reserved1 = mo->nr_plt;
#ifndef CONFIG_NEW_MACHO
		যদি (sk == sk_la_ptr)
	    	    sec->reserved1 = mo->nr_plt + mo->n_got;
#endif
            }
            যদি (seg->vmaddr == -1) {
                curaddr = (curaddr + SEG_PAGE_আকার - 1) & -SEG_PAGE_আকার;
                seg->vmaddr = curaddr;
                fileofs = (fileofs + SEG_PAGE_আকার - 1) & -SEG_PAGE_আকার;
                seg->fileoff = fileofs;
            }

            জন্য (s = mo->sk_to_sect[sk].s; s; s = s->পূর্ব) {
                পূর্ণসংখ্যা a = exact_log2p1(s->sh_addralign);
                যদি (a && al < (a - 1))
                  al = a - 1;
                s->sh_আকার = s->তথ্য_offset;
            }
            যদি (sec)
              sec->align = al;
            al = 1ULL << al;
            যদি (al > 4096)
              tcc_warning("alignment > 4096"), sec->align = 12, al = 4096;
            curaddr = (curaddr + al - 1) & -al;
            fileofs = (fileofs + al - 1) & -al;
            যদি (sec) {
                sec->addr = curaddr;
                sec->offset = fileofs;
            }
            জন্য (s = mo->sk_to_sect[sk].s; s; s = s->পূর্ব) {
                al = s->sh_addralign;
                curaddr = (curaddr + al - 1) & -al;
                dprintf("%s: curaddr now 0x%lx\n", s->name, (long)curaddr);
                s->sh_addr = curaddr;
                curaddr += s->sh_আকার;
                যদি (s->sh_type != SHT_NOBITS) {
                    fileofs = (fileofs + al - 1) & -al;
                    s->sh_offset = fileofs;
                    fileofs += s->sh_আকার;
                    dprintf("%s: fileofs now %ld\n", s->name, (long)fileofs);
                }
                যদি (sec)
                  mo->elfsectomacho[s->sh_অঙ্ক] = numsec;
            }
            যদি (sec)
              sec->আকার_2 = curaddr - sec->addr;
        }
        যদি (DEBUG_MACHO)
          জন্য (s = mo->sk_to_sect[sk].s; s; s = s->পূর্ব) {
              পূর্ণসংখ্যা type = s->sh_type;
              পূর্ণসংখ্যা flags = s->sh_flags;
              printf("%d section %-16s %-10s %09lx %04x %02d %s,%s,%s\n",
                     sk,
                     s->name,
                     type == SHT_PROGBITS ? "progbits" :
                     type == SHT_NOBITS ? "nobits" :
                     type == SHT_SYMTAB ? "symtab" :
                     type == SHT_STRTAB ? "strtab" :
                     type == SHT_INIT_ARRAY ? "init" :
                     type == SHT_FINI_ARRAY ? "fini" :
                     type == SHT_RELX ? "rel" : "???",
                     (long)s->sh_addr,
                     (unsigned)s->তথ্য_offset,
                     s->sh_addralign,
                     flags & SHF_ALLOC ? "alloc" : "",
                     flags & SHF_WRITE ? "write" : "",
                     flags & SHF_EXECINSTR ? "exec" : ""
                    );
          }
    }
    যদি (seg) {
        seg->vmsize = curaddr - seg->vmaddr;
        seg->filesize = fileofs - seg->fileoff;
    }

    /* Fill symtab info */
    symlc->symoff = mo->symtab->sh_offset;
    symlc->nsyms = mo->symtab->তথ্য_offset / আকার(কাঠামো nlist_64);
    symlc->stroff = mo->strtab->sh_offset;
    symlc->strsize = mo->strtab->তথ্য_offset;

    dysymlc->iundefsym = mo->iundef == -1 ? symlc->nsyms : mo->iundef;
    dysymlc->iextdefsym = mo->iextdef == -1 ? dysymlc->iundefsym : mo->iextdef;
    dysymlc->ilocalsym = mo->ilocal == -1 ? dysymlc->iextdefsym : mo->ilocal;
    dysymlc->nlocalsym = dysymlc->iextdefsym - dysymlc->ilocalsym;
    dysymlc->nextdefsym = dysymlc->iundefsym - dysymlc->iextdefsym;
    dysymlc->nundefsym = symlc->nsyms - dysymlc->iundefsym;
    dysymlc->indirectsymoff = mo->indirsyms->sh_offset;
    dysymlc->nindirectsyms = mo->indirsyms->তথ্য_offset / আকার(uint32_t);

#ifdef CONFIG_NEW_MACHO
    যদি (mo->chained_fixups->তথ্য_offset) {
        chained_fixups_lc->dataoff = mo->chained_fixups->sh_offset;
        chained_fixups_lc->datasize = mo->chained_fixups->তথ্য_offset;
    }
    যদি (mo->exports->তথ্য_offset) {
        export_trie_lc->dataoff = mo->exports->sh_offset;
        export_trie_lc->datasize = mo->exports->তথ্য_offset;
    }
#অন্যথা
    যদি (mo->rebase->তথ্য_offset) {
        mo->dyldinfo->rebase_off = mo->rebase->sh_offset;
        mo->dyldinfo->rebase_আকার = mo->rebase->তথ্য_offset;
    }
    যদি (mo->binding->তথ্য_offset) {
        mo->dyldinfo->bind_off = mo->binding->sh_offset;
        mo->dyldinfo->bind_আকার = mo->binding->তথ্য_offset;
    }
    যদি (mo->weak_binding->তথ্য_offset) {
        mo->dyldinfo->weak_bind_off = mo->weak_binding->sh_offset;
        mo->dyldinfo->weak_bind_আকার = mo->weak_binding->তথ্য_offset;
    }
    যদি (mo->lazy_binding->তথ্য_offset) {
        mo->dyldinfo->lazy_bind_off = mo->lazy_binding->sh_offset;
        mo->dyldinfo->lazy_bind_আকার = mo->lazy_binding->তথ্য_offset;
    }
    যদি (mo->exports->তথ্য_offset) {
        mo->dyldinfo->export_off = mo->exports->sh_offset;
        mo->dyldinfo->export_আকার = mo->exports->তথ্য_offset;
    }
#endif
}

স্থির শূন্য macho_write(TCCState *s1, কাঠামো macho *mo, FILE *fp)
{
    পূর্ণসংখ্যা i, sk;
    uint64_t fileofs = 0;
    Section *s;
    mo->mh.mh.magic = MH_MAGIC_64;
#ifdef TCC_TARGET_X86_64
    mo->mh.mh.cputype = CPU_TYPE_X86_64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_LIB64 | CPU_SUBTYPE_X86_ALL;
#নতুবা_যদি defined TCC_TARGET_ARM64
    mo->mh.mh.cputype = CPU_TYPE_ARM64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_ARM64_ALL;
#endif
    যদি (s1->output_type == TCC_OUTPUT_EXE) {
        mo->mh.mh.filetype = MH_EXECUTE;
        mo->mh.mh.flags = MH_DYLDLINK | MH_PIE;
    }
    অন্যথা {
        mo->mh.mh.filetype = MH_DYLIB;
        mo->mh.mh.flags = MH_DYLDLINK;
    }
    mo->mh.mh.ncmds = mo->nlc;
    mo->mh.mh.sizeofcmds = 0;
    জন্য (i = 0; i < mo->nlc; i++)
      mo->mh.mh.sizeofcmds += mo->lc[i]->cmdsize;

    fwrite(&mo->mh, 1, আকার(mo->mh), fp);
    fileofs += আকার(mo->mh);
    জন্য (i = 0; i < mo->nlc; i++) {
        fwrite(mo->lc[i], 1, mo->lc[i]->cmdsize, fp);
        fileofs += mo->lc[i]->cmdsize;
    }

    জন্য (sk = sk_unknown; sk < sk_last; sk++) {
        //struct segment_command_64 *seg;
        যদি (skinfo[sk].seg_initial == 0 ||
	    (s1->output_type == TCC_OUTPUT_EXE && !mo->segment[sk]) ||
	    !mo->sk_to_sect[sk].s)
          চালু;
        /*seg =*/ get_segment(mo, mo->segment[sk]);
        জন্য (s = mo->sk_to_sect[sk].s; s; s = s->পূর্ব) {
            যদি (s->sh_type != SHT_NOBITS) {
                যখন (fileofs < s->sh_offset)
                  fputc(0, fp), fileofs++;
                যদি (s->sh_আকার) {
                    fwrite(s->তথ্য, 1, s->sh_আকার, fp);
                    fileofs += s->sh_আকার;
                }
            }
        }
    }
}

#ifdef CONFIG_NEW_MACHO
স্থির পূর্ণসংখ্যা bind_rebase_cmp(ধ্রুবক শূন্য *_a, ধ্রুবক শূন্য *_b, শূন্য *arg)
{
    TCCState *s1 = arg;
    কাঠামো bind_rebase *a = (কাঠামো bind_rebase *) _a;
    কাঠামো bind_rebase *b = (কাঠামো bind_rebase *) _b;
    addr_t aa = s1->sections[a->section]->sh_addr + a->rel.r_offset;
    addr_t ab = s1->sections[b->section]->sh_addr + b->rel.r_offset;

    ফেরত aa > ab ? 1 : aa < ab ? -1 : 0;
}

ST_FUNC শূন্য bind_rebase_import(TCCState *s1, কাঠামো macho *mo)
{
    পূর্ণসংখ্যা i, j, k, bind_সূচক, আকার_2, page_গুনতি, sym_সূচক;
    ধ্রুবক অক্ষর *name;
    ElfW(Sym) *sym;
    unsigned অক্ষর *তথ্য = mo->chained_fixups->তথ্য;
    কাঠামো segment_command_64 *seg;
    কাঠামো dyld_chained_fixups_header *header;
    কাঠামো dyld_chained_starts_in_image *image;
    কাঠামো dyld_chained_starts_in_segment *segment;
    কাঠামো dyld_chained_import *import;

    tcc_qsort(mo->bind_rebase, mo->n_bind_rebase, আকার(কাঠামো bind_rebase),
	      bind_rebase_cmp, s1);
    জন্য (i = 0; i < mo->n_bind_rebase - 1; i++)
	যদি (mo->bind_rebase[i].section == mo->bind_rebase[i + 1].section &&
	    mo->bind_rebase[i].rel.r_offset == mo->bind_rebase[i + 1].rel.r_offset) {
	    sym_সূচক = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
            sym = &((ElfW(Sym) *)symtab_section->তথ্য)[sym_সূচক];
	    name = (অক্ষর *) symtab_section->link->তথ্য + sym->st_name;
	    tcc_error("Overlap %s/%s %s:%s",
		      mo->bind_rebase[i].bind ? "bind" : "rebase",
		      mo->bind_rebase[i + 1].bind ? "bind" : "rebase",
		      s1->sections[mo->bind_rebase[i].section]->name, name);
	}
    header = (কাঠামো dyld_chained_fixups_header *) তথ্য;
    তথ্য += (আকার(কাঠামো dyld_chained_fixups_header) + 7) & -8;
    header->starts_offset = তথ্য - mo->chained_fixups->তথ্য;
    header->imports_গুনতি = mo->n_bind;
    header->imports_format = DYLD_CHAINED_IMPORT;
    header->symbols_format = 0;
    আকার_2 = আকার(কাঠামো dyld_chained_starts_in_image) +
	   (mo->nseg - 1) * আকার(uint32_t);
    image = (কাঠামো dyld_chained_starts_in_image *) তথ্য;
    তথ্য += (আকার_2 + 7) & -8;
    image->seg_গুনতি = mo->nseg;
    জন্য (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
        image->seg_info_offset[i] = (তথ্য - mo->chained_fixups->তথ্য) -
				    header->starts_offset;
	seg = get_segment(mo, i);
	page_গুনতি = (seg->vmsize + SEG_PAGE_আকার - 1) / SEG_PAGE_আকার;
	আকার_2 = আকার(কাঠামো dyld_chained_starts_in_segment) +
		      (page_গুনতি - 1) * আকার(uint16_t);
        segment = (কাঠামো dyld_chained_starts_in_segment *) তথ্য;
        তথ্য += (আকার_2 + 7) & -8;
        segment->আকার_2 = আকার_2;
        segment->page_আকার = SEG_PAGE_আকার;
#যদি 1
#define	PTR_64_OFFSET 0
#define	PTR_64_MASK   0x7FFFFFFFFFFULL
        segment->pointer_format = DYLD_CHAINED_PTR_64;
#অন্যথা
#define	PTR_64_OFFSET 0x100000000ULL
#define	PTR_64_MASK   0xFFFFFFFFFFFFFFULL
        segment->pointer_format = DYLD_CHAINED_PTR_64_OFFSET;
#endif
        segment->segment_offset = seg->fileoff;
        segment->max_valid_pointer = 0;
        segment->page_গুনতি = page_গুনতি;
	// add bind/rebase
	bind_সূচক = 0;
	k = 0;
	জন্য (j = 0; j < page_গুনতি; j++) {
	    addr_t start = seg->vmaddr + j * SEG_PAGE_আকার;
	    addr_t end = start + SEG_PAGE_আকার;
	    শূন্য *last = ফাঁকা;
	    addr_t last_o = 0;
	    addr_t cur_o, cur;
	    কাঠামো dyld_chained_ptr_64_rebase *rebase;
	    কাঠামো dyld_chained_ptr_64_bind *bind;

	    segment->page_start[j] = DYLD_CHAINED_PTR_START_NONE;
	    জন্য (; k < mo->n_bind_rebase; k++) {
	        Section *s = s1->sections[mo->bind_rebase[k].section];
		addr_t r_offset = mo->bind_rebase[k].rel.r_offset;
		addr_t addr = s->sh_addr + r_offset;

		যদি ((addr & 3) ||
		    (addr & (SEG_PAGE_আকার - 1)) > SEG_PAGE_আকার - PTR_আকার)
		    tcc_error("Illegal rel_offset %s %lld",
			      s->name, (long long)r_offset);
		যদি (addr >= end)
		    বিরতি;
		যদি (addr >= start) {
		    cur_o = addr - start;
	            যদি (mo->bind_rebase[k].bind) {
		        যদি (segment->page_start[j] == DYLD_CHAINED_PTR_START_NONE)
			    segment->page_start[j] = cur_o;
		        অন্যথা {
			    bind = (কাঠামো dyld_chained_ptr_64_bind *) last;
			    bind->পরবর্তী = (cur_o - last_o) / 4;
		        }
		        bind = (কাঠামো dyld_chained_ptr_64_bind *)
				    (s->তথ্য + r_offset);
		        last = bind;
		        last_o = cur_o;
		        bind->ordinal = bind_সূচক;
		        bind->addend = 0;
		        bind->reserved = 0;
		        bind->পরবর্তী = 0;
		        bind->bind = 1;
		    }
		    অন্যথা {
		        যদি (segment->page_start[j] == DYLD_CHAINED_PTR_START_NONE)
			    segment->page_start[j] = cur_o;
		        অন্যথা {
			    rebase = (কাঠামো dyld_chained_ptr_64_rebase *) last;
			    rebase->পরবর্তী = (cur_o - last_o) / 4;
		        }
		        rebase = (কাঠামো dyld_chained_ptr_64_rebase *)
				    (s->তথ্য + r_offset);
		        last = rebase;
		        last_o = cur_o;
		        cur = (*(uint64_t *) (s->তথ্য + r_offset)) -
			      PTR_64_OFFSET;
		        rebase->target = cur & PTR_64_MASK;
		        rebase->high8 = cur >> (64 - 8);
			যদি (cur != ((uint64_t)rebase->high8 << (64 - 8)) + rebase->target)
			    tcc_error("rebase error");
		        rebase->reserved = 0;
		        rebase->পরবর্তী = 0;
		        rebase->bind = 0;
		    }
		}
		bind_সূচক += mo->bind_rebase[k].bind;
	    }
	}
    }
    // add imports
    header->imports_offset = তথ্য - mo->chained_fixups->তথ্য;
    import = (কাঠামো dyld_chained_import *) তথ্য;
    তথ্য += mo->n_bind * আকার (কাঠামো dyld_chained_import);
    header->symbols_offset = তথ্য - mo->chained_fixups->তথ্য;
    তথ্য++;
    জন্য (i = 0, bind_সূচক = 0; i < mo->n_bind_rebase; i++) {
	যদি (mo->bind_rebase[i].bind) {
	    import[bind_সূচক].lib_ordinal =
		BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xffu;
	    import[bind_সূচক].name_offset =
		(তথ্য - mo->chained_fixups->তথ্য) - header->symbols_offset;
	    sym_সূচক = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    sym = &((ElfW(Sym) *)symtab_section->তথ্য)[sym_সূচক];
	    import[bind_সূচক].weak_import =
		ELFW(ST_BIND)(sym->st_info) == STB_WEAK;
	    name = (অক্ষর *) symtab_section->link->তথ্য + sym->st_name;
            strcpy((অক্ষর *) তথ্য, name);
	    তথ্য += strlen(name) + 1;
	    bind_সূচক++;
	}
    }
    tcc_free(mo->bind_rebase);
}
#endif

ST_FUNC পূর্ণসংখ্যা macho_output_file(TCCState *s1, ধ্রুবক অক্ষর *filename)
{
    পূর্ণসংখ্যা fd, mode, file_type;
    FILE *fp;
    পূর্ণসংখ্যা i, ret = -1;
    কাঠামো macho mo;

    (শূন্য)memset(&mo, 0, আকার(mo));

    file_type = s1->output_type;
    যদি (file_type == TCC_OUTPUT_OBJ)
        mode = 0666;
    অন্যথা
        mode = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_দ্বিমিক_2, mode);
    যদি (fd < 0 || (fp = fdopen(fd, "wb")) == ফাঁকা) {
        tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
        ফেরত -1;
    }
    tcc_add_runtime(s1);
    tcc_macho_add_destructor(s1);
    resolve_common_syms(s1);
    create_symtab(s1, &mo);
    check_relocs(s1, &mo);
    ret = check_symbols(s1, &mo);
    যদি (!ret) {
	পূর্ণসংখ্যা save_output = s1->output_type;

        collect_sections(s1, &mo, filename);
        relocate_syms(s1, s1->symtab, 0);
	যদি (s1->output_type == TCC_OUTPUT_EXE)
            mo.ep->entryoff = get_sym_addr(s1, "main", 1, 1)
                            -     get_segment(&mo, 1)->vmaddr;
        যদি (s1->nb_errors)
          যাও do_ret;
	// Macho uses bind/rebase instead of dynsym
	s1->output_type = TCC_OUTPUT_EXE;
        relocate_sections(s1);
	s1->output_type = save_output;
#ifdef CONFIG_NEW_MACHO
	bind_rebase_import(s1, &mo);
#endif
        convert_symbols(s1, &mo);
        যদি (s1->verbose)
            printf("<- %s\n", filename);
        macho_write(s1, &mo, fp);
    }

 do_ret:
    জন্য (i = 0; i < mo.nlc; i++)
      tcc_free(mo.lc[i]);
    tcc_free(mo.seg2lc);
    tcc_free(mo.lc);
    tcc_free(mo.elfsectomacho);
    tcc_free(mo.e2msym);

    fclose(fp);
#ifdef CONFIG_CODESIGN
    যদি (!ret) {
	অক্ষর command[1024];
	পূর্ণসংখ্যা retval;

	snprintf(command, আকার(command), "codesign -f -s - %s", filename);
	retval = system (command);
	যদি (retval == -1 || !(WIFEXITED(retval) && WEXITSTATUS(retval) == 0))
	    tcc_error ("command failed '%s'", command);
    }
#endif
    ফেরত ret;
}

স্থির uint32_t macho_swap32(uint32_t x)
{
  ফেরত (x >> 24) | (x << 24) | ((x >> 8) & 0xff00) | ((x & 0xff00) << 8);
}
#define SWAP(x) (swap ? macho_swap32(x) : (x))
#define tbd_parse_movepast(s) \
    (pos = (pos = strstr(pos, s)) ? pos + strlen(s) : ফাঁকা)
#define tbd_parse_movetoany(cs) (pos = strpbrk(pos, cs))
#define tbd_parse_skipws যখন (*pos && (*pos==' '||*pos=='\n')) ++pos
#define tbd_parse_tramplequote যদি(*pos=='\''||*pos=='"') tbd_parse_trample
#define tbd_parse_tramplespace যদি(*pos==' ') tbd_parse_trample
#define tbd_parse_trample *pos++=0

#ifdef TCC_IS_NATIVE
/* Looks for the active developer SDK set by xcode-select (or the default
   one set during installation.) */
ST_FUNC শূন্য tcc_add_macos_sdkpath(TCCState* s)
{
    অক্ষর *sdkroot = ফাঁকা, *pos = ফাঁকা;
    শূন্য* xcs = dlopen("libxcselect.dylib", RTLD_GLOBAL | RTLD_LAZY);
    CString path;
    পূর্ণসংখ্যা (*f)(unsigned পূর্ণসংখ্যা, অক্ষর**) = dlsym(xcs, "xcselect_host_sdk_path");
    cstr_new(&path);
    যদি (f) f(1, &sdkroot);
    যদি (sdkroot)
        pos = strstr(sdkroot,"SDKs/MacOSX");
    যদি (pos)
        cstr_printf(&path, "%.*s.sdk/usr/lib", (পূর্ণসংখ্যা)(pos - sdkroot + 11), sdkroot);
    /* must use free from libc directly */
#pragma ঠেলো_macro("free")
#undef মুক্ত
    মুক্ত(sdkroot);
#pragma বের_করো_macro("free")
    যদি (path.আকার_2)
        tcc_add_library_path(s, (অক্ষর*)path.তথ্য);
    অন্যথা
        tcc_add_library_path(s,
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib"
            ":" "/Applications/Xcode.app/Developer/SDKs/MacOSX.sdk/usr/lib"
            );
    cstr_free(&path);
}

ST_FUNC অক্ষর* macho_tbd_soname(পূর্ণসংখ্যা fd) {
    অক্ষর *soname, *তথ্য, *pos;
    অক্ষর *ret = 0;
    pos = তথ্য = tcc_load_text(fd);
    যদি (!tbd_parse_movepast("install-name: ")) যাও the_end;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    যদি (!tbd_parse_movetoany("\n \"'")) যাও the_end;
    tbd_parse_trample;
    ret = tcc_strdup(soname);
the_end:
    tcc_free(তথ্য);
    ফেরত ret;
}
#endif /* TCC_IS_NATIVE */

ST_FUNC পূর্ণসংখ্যা macho_load_tbd(TCCState* s1, পূর্ণসংখ্যা fd, ধ্রুবক অক্ষর* filename, পূর্ণসংখ্যা lev)
{
    অক্ষর *soname, *তথ্য, *pos;
    পূর্ণসংখ্যা ret = -1;

    pos = তথ্য = tcc_load_text(fd);
    যদি (!tbd_parse_movepast("install-name: ")) যাও the_end;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    যদি (!tbd_parse_movetoany("\n \"'")) যাও the_end;
    tbd_parse_trample;
    ret = 0;
    যদি (tcc_add_dllref(s1, soname, lev)->found)
        যাও the_end;
    যখন(pos) {
        অক্ষর* sym = ফাঁকা;
        পূর্ণসংখ্যা cont = 1;
        যদি (!tbd_parse_movepast("symbols: ")) বিরতি;
        যদি (!tbd_parse_movepast("[")) বিরতি;
        যখন (cont) {
            tbd_parse_skipws;
            tbd_parse_tramplequote;
            sym = pos;
            যদি (!tbd_parse_movetoany(",] \"'")) বিরতি;
            tbd_parse_tramplequote;
            tbd_parse_tramplespace;
            tbd_parse_skipws;
            যদি (*pos==0||*pos==']') cont=0;
            tbd_parse_trample;
            set_elf_sym(s1->dynsymtab_section, 0, 0,
                ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0, SHN_UNDEF, sym);
        }
    }

the_end:
    tcc_free(তথ্য);
    ফেরত ret;
}

ST_FUNC পূর্ণসংখ্যা macho_load_dll(TCCState * s1, পূর্ণসংখ্যা fd, ধ্রুবক অক্ষর* filename, পূর্ণসংখ্যা lev)
{
    unsigned অক্ষর buf[আকার(কাঠামো mach_header_64)];
    শূন্য *buf2;
    uint32_t machofs = 0;
    কাঠামো fat_header fh;
    কাঠামো mach_header mh;
    কাঠামো load_command *lc;
    পূর্ণসংখ্যা i, swap = 0;
    ধ্রুবক অক্ষর *soname = filename;
    কাঠামো nlist_64 *symtab = 0;
    uint32_t nsyms = 0;
    অক্ষর *strtab = 0;
    uint32_t strsize = 0;
    uint32_t iextdef = 0;
    uint32_t nextdef = 0;

  again:
    যদি (full_read(fd, buf, আকার(buf)) != আকার(buf))
      ফেরত -1;
    memcpy(&fh, buf, আকার(fh));
    যদি (fh.magic == FAT_MAGIC || fh.magic == FAT_CIGAM) {
        কাঠামো fat_arch *fa = load_তথ্য(fd, আকার(fh),
                                        fh.nfat_arch * আকার(*fa));
        swap = fh.magic == FAT_CIGAM;
        জন্য (i = 0; i < SWAP(fh.nfat_arch); i++)
#ifdef TCC_TARGET_X86_64
          যদি (SWAP(fa[i].cputype) == CPU_TYPE_X86_64
              && SWAP(fa[i].cpusubtype) == CPU_SUBTYPE_X86_ALL)
#নতুবা_যদি defined TCC_TARGET_ARM64
          যদি (SWAP(fa[i].cputype) == CPU_TYPE_ARM64
              && SWAP(fa[i].cpusubtype) == CPU_SUBTYPE_ARM64_ALL)
#endif
            বিরতি;
        যদি (i == SWAP(fh.nfat_arch)) {
            tcc_free(fa);
            ফেরত -1;
        }
        machofs = SWAP(fa[i].offset);
        tcc_free(fa);
        lseek(fd, machofs, SEEK_SET);
        যাও again;
    } অন্যথা যদি (fh.magic == FAT_MAGIC_64 || fh.magic == FAT_CIGAM_64) {
        tcc_warning("%s: Mach-O fat 64bit files of type 0x%x not handled",
                    filename, fh.magic);
        ফেরত -1;
    }

    memcpy(&mh, buf, আকার(mh));
    যদি (mh.magic != MH_MAGIC_64)
      ফেরত -1;
    dprintf("found Mach-O at %d\n", machofs);
    buf2 = load_তথ্য(fd, machofs + আকার(কাঠামো mach_header_64), mh.sizeofcmds);
    জন্য (i = 0, lc = buf2; i < mh.ncmds; i++) {
        dprintf("lc %2d: 0x%08x\n", i, lc->cmd);
        নির্বাচন (lc->cmd) {
        ক্ষেত্র LC_SYMTAB:
        {
            কাঠামো symtab_command *sc = (কাঠামো symtab_command*)lc;
            nsyms = sc->nsyms;
            symtab = load_তথ্য(fd, machofs + sc->symoff, nsyms * আকার(*symtab));
            strsize = sc->strsize;
            strtab = load_তথ্য(fd, machofs + sc->stroff, strsize);
            বিরতি;
        }
        ক্ষেত্র LC_ID_DYLIB:
        {
            কাঠামো dylib_command *dc = (কাঠামো dylib_command*)lc;
            soname = (অক্ষর*)lc + dc->name;
            dprintf(" ID_DYLIB %d 0x%x 0x%x %s\n",
                    dc->timestamp, dc->current_version,
                    dc->compatibility_version, soname);
            বিরতি;
        }
        ক্ষেত্র LC_REEXPORT_DYLIB:
        {
            কাঠামো dylib_command *dc = (কাঠামো dylib_command*)lc;
            অক্ষর *name = (অক্ষর*)lc + dc->name;
            পূর্ণসংখ্যা subfd = open(name, O_RDONLY | O_দ্বিমিক_2);
            dprintf(" REEXPORT %s\n", name);
            যদি (subfd < 0)
              tcc_warning("can't open %s (reexported from %s)", name, filename);
            অন্যথা {
                /* Hopefully the REEXPORTs never form a cycle, we don't check
                   for that!  */
                macho_load_dll(s1, subfd, name, lev + 1);
                close(subfd);
            }
            বিরতি;
        }
        ক্ষেত্র LC_DYSYMTAB:
        {
            কাঠামো dysymtab_command *dc = (কাঠামো dysymtab_command*)lc;
            iextdef = dc->iextdefsym;
            nextdef = dc->nextdefsym;
            বিরতি;
        }
        }
        lc = (কাঠামো load_command*) ((অক্ষর*)lc + lc->cmdsize);
    }

    যদি (tcc_add_dllref(s1, soname, lev)->found)
        যাও the_end;

    যদি (!nsyms || !nextdef)
      tcc_warning("%s doesn't export any symbols?", filename);

    //dprintf("symbols (all):\n");
    dprintf("symbols (exported):\n");
    dprintf("    n: typ sec   desc              value name\n");
    //for (i = 0; i < nsyms; i++) {
    জন্য (i = iextdef; i < iextdef + nextdef; i++) {
        কাঠামো nlist_64 *sym = symtab + i;
        dprintf("%5d: %3d %3d 0x%04x 0x%016lx %s\n",
                i, sym->n_type, sym->n_sect, sym->n_desc, (long)sym->n_মান,
                strtab + sym->n_strx);
        set_elf_sym(s1->dynsymtab_section, 0, 0,
                    ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
                    0, SHN_UNDEF, strtab + sym->n_strx);
    }

  the_end:
    tcc_free(strtab);
    tcc_free(symtab);
    tcc_free(buf2);
    ফেরত 0;
}
