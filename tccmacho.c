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
#അന്തര്ഭാവ "tcc.h"

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

#എങ്കിൽ !defined TCC_TARGET_X86_64 && !defined TCC_TARGET_ARM64
#error Platform not supported
#endif

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#undef _tcc_error

#define DEBUG_MACHO 0
#define dprintf എങ്കിൽ (DEBUG_MACHO) printf

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

ഘടന fat_header {
    uint32_t        magic;          /* FAT_MAGIC or FAT_MAGIC_64 */
    uint32_t        nfat_arch;      /* number of structs that follow */
};

ഘടന fat_arch {
    പൂർണ്ണസംഖ്യ             cputype;        /* cpu specifier (int) */
    പൂർണ്ണസംഖ്യ             cpusubtype;     /* machine specifier (int) */
    uint32_t        offset;         /* file offset to this object file */
    uint32_t        size;           /* size of this object file */
    uint32_t        align;          /* alignment as a power of 2 */
};

#define FAT_MAGIC       0xcafebabe
#define FAT_CIGAM       0xbebafeca
#define FAT_MAGIC_64    0xcafebabf
#define FAT_CIGAM_64    0xbfbafeca

ഘടന mach_header {
    uint32_t        magic;          /* mach magic number identifier */
    പൂർണ്ണസംഖ്യ             cputype;        /* cpu specifier */
    പൂർണ്ണസംഖ്യ             cpusubtype;     /* machine specifier */
    uint32_t        filetype;       /* type of file */
    uint32_t        ncmds;          /* number of load commands */
    uint32_t        sizeofcmds;     /* the size of all the load commands */
    uint32_t        flags;          /* flags */
};

ഘടന mach_header_64 {
    ഘടന mach_header  mh;
    uint32_t            reserved;       /* reserved, pad to 64bit */
};

/* Constant for the magic field of the mach_header (32-bit architectures) */
#define MH_MAGIC        0xfeedface      /* the mach magic number */
#define MH_CIGAM        0xcefaedfe      /* NXSwapInt(MH_MAGIC) */
#define MH_MAGIC_64     0xfeedfacf      /* the 64-bit mach magic number */
#define MH_CIGAM_64     0xcffaedfe      /* NXSwapInt(MH_MAGIC_64) */

ഘടന load_command {
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

തരനിർവചനം പൂർണ്ണസംഖ്യ vm_prot_t;

ഘടന segment_command_64 { /* for 64-bit architectures */
    uint32_t        cmd;            /* LC_SEGMENT_64 */
    uint32_t        cmdsize;        /* includes sizeof section_64 structs */
    അക്ഷരം            segname[16];    /* segment name */
    uint64_t        vmaddr;         /* memory address of this segment */
    uint64_t        vmsize;         /* memory size of this segment */
    uint64_t        fileoff;        /* file offset of this segment */
    uint64_t        filesize;       /* amount to map from the file */
    vm_prot_t       maxprot;        /* maximum VM protection */
    vm_prot_t       initprot;       /* initial VM protection */
    uint32_t        nsects;         /* number of sections in segment */
    uint32_t        flags;          /* flags */
};

ഘടന section_64 { /* for 64-bit architectures */
    അക്ഷരം            sectname[16];   /* name of this section */
    അക്ഷരം            segname[16];    /* segment this section goes in */
    uint64_t        addr;           /* memory address of this section */
    uint64_t        size;           /* size in bytes of this section */
    uint32_t        offset;         /* file offset of this section */
    uint32_t        align;          /* section alignment (power of 2) */
    uint32_t        reloff;         /* file offset of relocation entries */
    uint32_t        nreloc;         /* number of relocation entries */
    uint32_t        flags;          /* flags (section type and attributes)*/
    uint32_t        reserved1;      /* reserved (for offset or index) */
    uint32_t        reserved2;      /* reserved (for count or sizeof) */
    uint32_t        reserved3;      /* reserved */
};

എണ്ണൽ {
    DYLD_CHAINED_IMPORT          = 1,
};

ഘടന dyld_chained_fixups_header {
    uint32_t    fixups_version; ///< 0
    uint32_t    starts_offset;  ///< Offset of dyld_chained_starts_in_image.
    uint32_t    imports_offset; ///< Offset of imports table in chain_data.
    uint32_t    symbols_offset; ///< Offset of symbol strings in chain_data.
    uint32_t    imports_എണ്ണം;  ///< Number of imported symbol names.
    uint32_t    imports_format; ///< DYLD_CHAINED_IMPORT*
    uint32_t    symbols_format; ///< 0 => uncompressed, 1 => zlib compressed
};

ഘടന dyld_chained_starts_in_image
{
    uint32_t    seg_എണ്ണം;
    uint32_t    seg_info_offset[1];  // each entry is offset into this struct for that segment
    // followed by pool of dyld_chain_starts_in_segment data
};

എണ്ണൽ {
    DYLD_CHAINED_PTR_64                     =  2,    // target is vmaddr
    DYLD_CHAINED_PTR_64_OFFSET              =  6,    // target is vm offset
};

എണ്ണൽ {
    DYLD_CHAINED_PTR_START_NONE   = 0xFFFF, // used in page_start[] to denote a page with no fixups
};

#define SEG_PAGE_SIZE 16384

ഘടന dyld_chained_starts_in_segment
{
    uint32_t    size;               // size of this (amount kernel needs to copy)
    uint16_t    page_size;          // 0x1000 or 0x4000
    uint16_t    pointer_format;     // DYLD_CHAINED_PTR_*
    uint64_t    segment_offset;     // offset in memory to start of segment
    uint32_t    max_valid_pointer;  // for 32-bit OS, any value beyond this is not a pointer
    uint16_t    page_എണ്ണം;         // how many pages are in array
    uint16_t    page_start[1];      // each entry is offset in each page of first element in chain
                                    // or DYLD_CHAINED_PTR_START_NONE if no fixups on page
};

എണ്ണൽ BindSpecialDylib {
  BIND_SPECIAL_DYLIB_FLAT_LOOKUP = -2,
};

ഘടന dyld_chained_import
{
    uint32_t    lib_ordinal :  8,
                weak_import :  1,
                name_offset : 23;
};

ഘടന dyld_chained_ptr_64_rebase
{
    uint64_t    target    : 36,    // vmaddr, 64GB max image size
                high8     :  8,    // top 8 bits set to this after slide added
                reserved  :  7,    // all zeros
                next      : 12,    // 4-byte stride
                bind      :  1;    // == 0
};

ഘടന dyld_chained_ptr_64_bind
{
    uint64_t    ordinal   : 24,
                addend    :  8,   // 0 thru 255
                reserved  : 19,   // all zeros
                next      : 12,   // 4-byte stride
                bind      :  1;   // == 1
};

#define S_REGULAR                       0x0
#define S_ZEROFILL                      0x1
#define S_NON_LAZY_ചിഹ്നം_POINTERS      0x6
#define S_LAZY_ചിഹ്നം_POINTERS          0x7
#define S_ചിഹ്നം_STUBS                  0x8
#define S_MOD_INIT_FUNC_POINTERS        0x9
#define S_MOD_TERM_FUNC_POINTERS        0xa

#define S_ATTR_PURE_INSTRUCTIONS        0x80000000
#define S_ATTR_SOME_INSTRUCTIONS        0x00000400
#define S_ATTR_DEBUG             	0x02000000


തരനിർവചനം uint32_t lc_str;

ഘടന dylib_command {
    uint32_t cmd;                   /* LC_ID_DYLIB, LC_LOAD_{,WEAK_}DYLIB,
                                       LC_REEXPORT_DYLIB */
    uint32_t cmdsize;               /* includes pathname string */
    lc_str   name;                  /* library's path name */
    uint32_t timestamp;             /* library's build time stamp */
    uint32_t current_version;       /* library's current version number */
    uint32_t compatibility_version; /* library's compatibility vers number*/
};

ഘടന rpath_command {
    uint32_t     cmd;           /* LC_RPATH */
    uint32_t     cmdsize;       /* includes string */
    lc_str       path;          /* path to add to run path */
};

ഘടന dylinker_command {
    uint32_t        cmd;            /* LC_ID_DYLINKER, LC_LOAD_DYLINKER or
                                       LC_DYLD_ENVIRONMENT */
    uint32_t        cmdsize;        /* includes pathname string */
    lc_str          name;           /* dynamic linker's path name */
};

ഘടന linkedit_data_command {
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

ഘടന build_version_command {
    uint32_t    cmd;            /* LC_BUILD_VERSION */
    uint32_t    cmdsize;        /* sizeof(struct build_version_command) plus */
                                /* ntools * sizeof(struct build_tool_version) */
    uint32_t    platform;       /* platform */
    uint32_t    minos;          /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    sdk;            /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    ntools;         /* number of tool entries following this */
};

ഘടന source_version_command {
    uint32_t  cmd;      /* LC_SOURCE_VERSION */
    uint32_t  cmdsize;  /* 16 */
    uint64_t  version;  /* A.B.C.D.E packed as a24.b10.c10.d10.e10 */
};

ഘടന symtab_command {
    uint32_t        cmd;            /* LC_SYMTAB */
    uint32_t        cmdsize;        /* sizeof(struct symtab_command) */
    uint32_t        symoff;         /* symbol table offset */
    uint32_t        nsyms;          /* number of symbol table entries */
    uint32_t        stroff;         /* string table offset */
    uint32_t        strsize;        /* string table size in bytes */
};

ഘടന dysymtab_command {
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
#define BIND_OPCODE_SET_ചിഹ്നം_TRAILING_FLAGS_IMM               0x40
#define BIND_OPCODE_SET_TYPE_IMM                                0x50
#define BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB                 0x70
#define BIND_OPCODE_DO_BIND                                     0x90

#define BIND_ചിഹ്നം_FLAGS_WEAK_IMPORT                           0x1

#define BIND_TYPE_POINTER                                       1
#define BIND_SPECIAL_DYLIB_FLAT_LOOKUP                          -2

#define REBASE_OPCODE_DONE                                      0x00
#define REBASE_OPCODE_SET_TYPE_IMM                              0x10
#define REBASE_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB               0x20
#define REBASE_OPCODE_DO_REBASE_IMM_TIMES                       0x50

#define REBASE_TYPE_POINTER                                     1

#define EXPORT_ചിഹ്നം_FLAGS_KIND_REGULAR                        0x00
#define EXPORT_ചിഹ്നം_FLAGS_KIND_ABSOLUTE                       0x02
#define EXPORT_ചിഹ്നം_FLAGS_WEAK_DEFINITION                     0x04

ഘടന dyld_info_command {
    uint32_t cmd;             /* LC_DYLD_INFO or LC_DYLD_INFO_ONLY */
    uint32_t cmdsize;         /* sizeof(struct dyld_info_command) */
    uint32_t rebase_off;      /* file offset to rebase info  */
    uint32_t rebase_size;     /* size of rebase info   */
    uint32_t bind_off;        /* file offset to binding info   */
    uint32_t bind_size;       /* size of binding info  */
    uint32_t weak_bind_off;   /* file offset to weak binding info   */
    uint32_t weak_bind_size;  /* size of weak binding info  */
    uint32_t lazy_bind_off;   /* file offset to lazy binding info */
    uint32_t lazy_bind_size;  /* size of lazy binding infs */
    uint32_t export_off;      /* file offset to lazy binding info */
    uint32_t export_size;     /* size of lazy binding infs */
};

#define INDIRECT_ചിഹ്നം_LOCAL   0x80000000

ഘടന entry_point_command {
    uint32_t  cmd;      /* LC_MAIN only used in MH_EXECUTE filetypes */
    uint32_t  cmdsize;  /* 24 */
    uint64_t  entryoff; /* file (__TEXT) offset of main() */
    uint64_t  stacksize;/* if not zero, initial stack size */
};

എണ്ണൽ skind {
    sk_unknown = 0,
    sk_discard,
    sk_text,
    sk_stubs,
    sk_stub_helper,
    sk_ro_data,
    sk_uw_info,
    sk_nl_ptr,  // non-lazy pointers, aka GOT
    sk_debug_info,
    sk_debug_abbrev,
    sk_debug_വരി,
    sk_debug_aranges,
    sk_debug_str,
    sk_debug_വരി_str,
    sk_stab,
    sk_stab_str,
    sk_la_ptr,  // lazy pointers
    sk_init,
    sk_fini,
    sk_rw_data,
    sk_bss,
    sk_linkedit,
    sk_last
};

ഘടന nlist_64 {
    uint32_t  n_strx;      /* index into the string table */
    uint8_t n_type;        /* type flag, see below */
    uint8_t n_sect;        /* section number or NO_SECT */
    uint16_t n_desc;       /* see <mach-o/stab.h> */
    uint64_t n_മൂല്യം;      /* value of this symbol (or stab offset) */
};

#define N_UNDF  0x0
#define N_ABS   0x2
#define N_EXT   0x1
#define N_SECT  0xe

#define N_WEAK_REF      0x0040
#define N_WEAK_DEF      0x0080

ഘടന macho {
    ഘടന mach_header_64 mh;
    പൂർണ്ണസംഖ്യ *seg2lc, nseg;
    ഘടന load_command **lc;
    ഘടന entry_point_command *ep;
    പൂർണ്ണസംഖ്യ nlc;
    ഘടന {
        Section *s;
        പൂർണ്ണസംഖ്യ machosect;
    } sk_to_sect[sk_last];
    പൂർണ്ണസംഖ്യ *elfsectomacho;
    പൂർണ്ണസംഖ്യ *e2msym;
    Section *symtab, *strtab, *indirsyms, *stubs, *exports;
    uint32_t ilocal, iextdef, iundef;
    പൂർണ്ണസംഖ്യ stubsym, n_got, nr_plt;
    പൂർണ്ണസംഖ്യ segment[sk_last];
#ifdef CONFIG_NEW_MACHO
    Section *chained_fixups;
    പൂർണ്ണസംഖ്യ n_bind;
    പൂർണ്ണസംഖ്യ n_bind_rebase;
    ഘടന bind_rebase {
	പൂർണ്ണസംഖ്യ section;
	പൂർണ്ണസംഖ്യ bind;
	ElfW_Rel rel;
    } *bind_rebase;
#അല്ലെങ്കിൽ
    Section *rebase, *binding, *weak_binding, *lazy_binding;
    Section *stub_helper, *la_ചിഹ്നം_ptr;
    ഘടന dyld_info_command *dyldinfo;
    പൂർണ്ണസംഖ്യ helpsym, lasym, dyld_private, dyld_stub_binder;
    പൂർണ്ണസംഖ്യ n_lazy_bind;    
    ഘടന s_lazy_bind {
        പൂർണ്ണസംഖ്യ section;
        പൂർണ്ണസംഖ്യ bind_offset;
        പൂർണ്ണസംഖ്യ la_ചിഹ്നം_offset;
        ElfW_Rel rel;
    } *s_lazy_bind;
    പൂർണ്ണസംഖ്യ n_rebase;    
    ഘടന s_rebase {
        പൂർണ്ണസംഖ്യ section;
        ElfW_Rel rel;
    } *s_rebase;
    പൂർണ്ണസംഖ്യ n_bind; 
    ഘടന bind {
        പൂർണ്ണസംഖ്യ section;
        ElfW_Rel rel;
    } *bind;
#endif
};

#define SHT_LINKEDIT (SHT_LOOS + 42)
#define SHN_FROMDLL  (SHN_LOOS + 2)  /* Symbol is undefined, comes from a DLL */

സ്ഥിതം ശൂന്യം * add_lc(ഘടന macho *mo, uint32_t cmd, uint32_t cmdsize)
{
    ഘടന load_command *lc = tcc_mallocz(cmdsize);
    lc->cmd = cmd;
    lc->cmdsize = cmdsize;
    mo->lc = tcc_realloc(mo->lc, വലുപ്പം(mo->lc[0]) * (mo->nlc + 1));
    mo->lc[mo->nlc++] = lc;
    തിരികെ lc;
}

സ്ഥിതം ഘടന segment_command_64 * add_segment(ഘടന macho *mo, സ്ഥിരം അക്ഷരം *name)
{
    ഘടന segment_command_64 *sc = add_lc(mo, LC_SEGMENT_64, വലുപ്പം(*sc));
    strncpy(sc->segname, name, 16);
    mo->seg2lc = tcc_realloc(mo->seg2lc, വലുപ്പം(*mo->seg2lc) * (mo->nseg + 1));
    mo->seg2lc[mo->nseg++] = mo->nlc - 1;
    തിരികെ sc;
}

സ്ഥിതം ഘടന segment_command_64 * get_segment(ഘടന macho *mo, പൂർണ്ണസംഖ്യ i)
{
    തിരികെ (ഘടന segment_command_64 *) (mo->lc[mo->seg2lc[i]]);
}

സ്ഥിതം പൂർണ്ണസംഖ്യ add_section(ഘടന macho *mo, ഘടന segment_command_64 **_seg, സ്ഥിരം അക്ഷരം *name)
{
    ഘടന segment_command_64 *seg = *_seg;
    പൂർണ്ണസംഖ്യ ret = seg->nsects;
    ഘടന section_64 *sec;
    seg->nsects++;
    seg->cmdsize += വലുപ്പം(*sec);
    seg = tcc_realloc(seg, വലുപ്പം(*seg) + seg->nsects * വലുപ്പം(*sec));
    sec = (ഘടന section_64*)((അക്ഷരം*)seg + വലുപ്പം(*seg)) + ret;
    memset(sec, 0, വലുപ്പം(*sec));
    strncpy(sec->sectname, name, 16);
    strncpy(sec->segname, seg->segname, 16);
    *_seg = seg;
    തിരികെ ret;
}

സ്ഥിതം ഘടന section_64 *get_section(ഘടന segment_command_64 *seg, പൂർണ്ണസംഖ്യ i)
{
    തിരികെ (ഘടന section_64*)((അക്ഷരം*)seg + വലുപ്പം(*seg)) + i;
}

സ്ഥിതം ശൂന്യം * add_dylib(ഘടന macho *mo, അക്ഷരം *name)
{
    ഘടന dylib_command *lc;
    പൂർണ്ണസംഖ്യ sz = (വലുപ്പം(*lc) + strlen(name) + 1 + 7) & -8;
    lc = add_lc(mo, LC_LOAD_DYLIB, sz);
    lc->name = വലുപ്പം(*lc);
    strcpy((അക്ഷരം*)lc + lc->name, name);
    lc->timestamp = 2;
    lc->current_version = 1 << 16;
    lc->compatibility_version = 1 << 16;
    തിരികെ lc;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ uleb128_size (unsigned long long മൂല്യം)
{
    പൂർണ്ണസംഖ്യ size =  0;

    ചെയ്യുക {
        മൂല്യം >>= 7;
        size++;
    } ആകുമ്പോൾ (മൂല്യം != 0);
    തിരികെ size;
}

സ്ഥിതം ശൂന്യം write_uleb128(Section *section, uint64_t മൂല്യം)
{
    ചെയ്യുക {
        unsigned അക്ഷരം byte = മൂല്യം & 0x7f;
	uint8_t *ptr = section_ptr_add(section, 1);

        മൂല്യം >>= 7;
        *ptr = byte | (മൂല്യം ? 0x80 : 0);
    } ആകുമ്പോൾ (മൂല്യം != 0);
}

സ്ഥിതം ശൂന്യം tcc_macho_add_destructor(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ init_sym, mh_execute_header, at_exit_sym;
    Section *s;
    ElfW_Rel *rel;
    uint8_t *ptr;

    mh_execute_header = put_elf_sym(s1->symtab, -4096, 0,
				    ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				    text_section->sh_അക്കം, "__mh_execute_header");
    s = find_section(s1, ".fini_array");
    എങ്കിൽ (s->data_offset == 0)
        തിരികെ; 
    init_sym = put_elf_sym(s1->symtab, text_section->data_offset, 0,
                           ELFW(ST_INFO)(STB_LOCAL, STT_FUNC), 0,
                           text_section->sh_അക്കം, "___GLOBAL_init_65535");
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
        പൂർണ്ണസംഖ്യ sym_index = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_add(text_section, 26);
        ptr[0] = 0x48;  // lea destructor(%rip),%rax
        ptr[1] = 0x8d;
        ptr[2] = 0x05;
        put_elf_reloca(s1->symtab, text_section, 
		       text_section->data_offset - 23,
		       R_X86_64_PC32, sym_index, -4);
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
		       text_section->data_offset - 9,
		       R_X86_64_PC32, mh_execute_header, -4);
	ptr[21] = 0xe8; // call __cxa_atexit
        put_elf_reloca(s1->symtab, text_section,
		       text_section->data_offset - 4,
		       R_X86_64_PLT32, at_exit_sym, -4);
    }
    ptr = section_ptr_add(text_section, 2);
    ptr[0] = 0x5d;  // pop   %rbp
    ptr[1] = 0xc3;  // ret
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
    ptr = section_ptr_add(text_section, 8);
    write32le(ptr, 0xa9bf7bfd);     // stp     x29, x30, [sp, #-16]!
    write32le(ptr + 4, 0x910003fd); // mov     x29, sp
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        പൂർണ്ണസംഖ്യ sym_index = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_add(text_section, 24);
        put_elf_reloc(s1->symtab, text_section, 
		      text_section->data_offset - 24,
		      R_AARCH64_ADR_PREL_PG_HI21, sym_index);
        write32le(ptr, 0x90000000);      // adrp x0, destructor@page
        put_elf_reloc(s1->symtab, text_section,
		      text_section->data_offset - 20,
		      R_AARCH64_LDST8_ABS_LO12_NC, sym_index);
        write32le(ptr + 4, 0x91000000);  // add x0,x0,destructor@pageoff
        write32le(ptr + 8, 0xd2800001);  // mov x1, #0
        put_elf_reloc(s1->symtab, text_section, 
		      text_section->data_offset - 12,
		      R_AARCH64_ADR_PREL_PG_HI21, mh_execute_header);
        write32le(ptr + 12, 0x90000002);      // adrp x2, mh_execute_header@page
        put_elf_reloc(s1->symtab, text_section,
		      text_section->data_offset - 8,
		      R_AARCH64_LDST8_ABS_LO12_NC, mh_execute_header);
        write32le(ptr + 16, 0x91000042);  // add x2,x2,mh_execute_header@pageoff
        put_elf_reloc(s1->symtab, text_section,
		      text_section->data_offset - 4,
		      R_AARCH64_CALL26, at_exit_sym);
	write32le(ptr + 20, 0x94000000); // bl __cxa_atexit
    }
    ptr = section_ptr_add(text_section, 8);
    write32le(ptr, 0xa8c17bfd);     // ldp     x29, x30, [sp], #16
    write32le(ptr + 4, 0xd65f03c0); // ret
#endif
    s->reloc->data_offset = s->data_offset = 0;
    s->sh_flags &= ~SHF_ALLOC;
    add_array (s1, ".init_array", init_sym);
}

#ifdef CONFIG_NEW_MACHO
സ്ഥിതം ശൂന്യം bind_rebase_add(ഘടന macho *mo, പൂർണ്ണസംഖ്യ bind, പൂർണ്ണസംഖ്യ sh_info,
			    ElfW_Rel *rel, ഘടന sym_attr *attr)
{
    mo->bind_rebase = tcc_realloc(mo->bind_rebase, (mo->n_bind_rebase + 1) *
		                  വലുപ്പം(ഘടന bind_rebase));
    mo->bind_rebase[mo->n_bind_rebase].section = sh_info;
    mo->bind_rebase[mo->n_bind_rebase].bind = bind;
    mo->bind_rebase[mo->n_bind_rebase].rel = *rel;
    എങ്കിൽ (attr)
        mo->bind_rebase[mo->n_bind_rebase].rel.r_offset = attr->got_offset;
    mo->n_bind_rebase++;
    mo->n_bind += bind;
}

സ്ഥിതം ശൂന്യം check_relocs(TCCState *s1, ഘടന macho *mo)
{
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    പൂർണ്ണസംഖ്യ i, j, type, gotplt_entry, sym_index, for_code;
    uint32_t *pi, *goti;
    ഘടന sym_attr *attr;

    goti = ശൂന്യ;
    mo->nr_plt = mo->n_got = 0;
    വേണ്ടി (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        എങ്കിൽ (s->sh_type != SHT_RELX ||
	    !strncmp(s1->sections[s->sh_info]->name, ".debug_", 7))
            തുടരുക;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_entry = gotplt_entry_type(type);
            for_code = code_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_index = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
            എങ്കിൽ (sym->st_shndx == SHN_UNDEF
                || gotplt_entry == ALWAYS_GOTPLT_ENTRY) {
                attr = get_sym_attr(s1, sym_index, 1);
                എങ്കിൽ (!attr->dyn_index) {
                    attr->got_offset = s1->got->data_offset;
                    attr->plt_offset = -1;
                    attr->dyn_index = 1; /* used as flag */
                    section_ptr_add(s1->got, PTR_SIZE);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_offset,
                                  R_JMP_SLOT, sym_index);
	 	    goti = tcc_realloc(goti, (mo->n_got + 1) * വലുപ്പം(*goti));
                    എങ്കിൽ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        എങ്കിൽ (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (അക്ഷരം *) symtab_section->link->data + sym->st_name);
			goti[mo->n_got++] = INDIRECT_ചിഹ്നം_LOCAL;
                    } അല്ലെങ്കിൽ {
                        goti[mo->n_got++] = mo->e2msym[sym_index];
                        എങ്കിൽ (sym->st_shndx == SHN_UNDEF
#ifdef TCC_TARGET_X86_64
                            && type == R_X86_64_GOTPCREL
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
                            && type == R_AARCH64_ADR_GOT_PAGE
#endif
                            ) {
			    attr->plt_offset = -mo->n_bind_rebase - 2;
			    bind_rebase_add(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
			    s1->got->reloc->data_offset -= വലുപ്പം (ElfW_Rel);
			}
		        എങ്കിൽ (for_code && sym->st_shndx == SHN_UNDEF)
			    s1->got->reloc->data_offset -= വലുപ്പം (ElfW_Rel);
		    }
                }
                എങ്കിൽ (for_code && sym->st_shndx == SHN_UNDEF) {
		    എങ്കിൽ ((പൂർണ്ണസംഖ്യ)attr->plt_offset < -1) {
			/* remove above bind and replace with plt */
			mo->bind_rebase[-attr->plt_offset - 2].bind = 2;
			attr->plt_offset = -1;
		    }
                    എങ്കിൽ (attr->plt_offset == -1) {
                        uint8_t *jmp;

                        attr->plt_offset = mo->stubs->data_offset;
#ifdef TCC_TARGET_X86_64
                        എങ്കിൽ (type != R_X86_64_PLT32)
                             തുടരുക;
                        jmp = section_ptr_add(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *ofs(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_offset + 2,
                                      R_X86_64_GOTPCREL, sym_index);
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
                        എങ്കിൽ (type != R_AARCH64_CALL26)
                             തുടരുക;
                        jmp = section_ptr_add(mo->stubs, 12);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_offset,
                                      R_AARCH64_ADR_GOT_PAGE, sym_index);
                        write32le(jmp, // adrp x16, #sym
                                  0x90000010);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_offset + 4,
                                      R_AARCH64_LD64_GOT_LO12_NC, sym_index);
                        write32le(jmp + 4, // ld x16,[x16, #sym]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);
#endif
			bind_rebase_add(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
                        pi = section_ptr_add(mo->indirsyms, വലുപ്പം(*pi));
                        *pi = mo->e2msym[sym_index];
                        mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_offset;
                }
            }
	    എങ്കിൽ (type == R_DATA_PTR || type == R_JMP_SLOT)
		bind_rebase_add(mo, sym->st_shndx == SHN_UNDEF ? 1 : 0,
				s->sh_info, &save_rel, ശൂന്യ);
        }
    }
    /* remove deleted binds */
    വേണ്ടി (i = 0, j = 0; i < mo->n_bind_rebase; i++)
	എങ്കിൽ (mo->bind_rebase[i].bind == 2)
	    mo->n_bind--;
	അല്ലെങ്കിൽ
	    mo->bind_rebase[j++] = mo->bind_rebase[i];
    mo->n_bind_rebase = j;
    pi = section_ptr_add(mo->indirsyms, mo->n_got * വലുപ്പം(*pi));
    memcpy(pi, goti, mo->n_got * വലുപ്പം(*pi));
    tcc_free(goti);
}

#അല്ലെങ്കിൽ

സ്ഥിതം ശൂന്യം check_relocs(TCCState *s1, ഘടന macho *mo)
{
    uint8_t *jmp;
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    പൂർണ്ണസംഖ്യ i, type, gotplt_entry, sym_index, for_code;
    പൂർണ്ണസംഖ്യ bind_offset, la_ചിഹ്നം_offset;
    uint32_t *pi, *goti;
    ഘടന sym_attr *attr;

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
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
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
    
    goti = ശൂന്യ;
    mo->nr_plt = mo->n_got = 0;
    വേണ്ടി (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        എങ്കിൽ (s->sh_type != SHT_RELX ||
	    !strncmp(s1->sections[s->sh_info]->name, ".debug_", 7))
            തുടരുക;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_entry = gotplt_entry_type(type);
            for_code = code_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_index = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
            എങ്കിൽ (sym->st_shndx == SHN_UNDEF
                || gotplt_entry == ALWAYS_GOTPLT_ENTRY) {
                attr = get_sym_attr(s1, sym_index, 1);
                എങ്കിൽ (!attr->dyn_index) {
                    attr->got_offset = s1->got->data_offset;
                    attr->plt_offset = -1;
                    attr->dyn_index = 1; /* used as flag */
		    section_ptr_add(s1->got, PTR_SIZE);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_offset,
                                  R_JMP_SLOT, sym_index);
		    goti = tcc_realloc(goti, (mo->n_got + 1) * വലുപ്പം(*goti));
                    എങ്കിൽ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        എങ്കിൽ (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (അക്ഷരം *) symtab_section->link->data + sym->st_name);
			goti[mo->n_got++] = INDIRECT_ചിഹ്നം_LOCAL;
                    } അല്ലെങ്കിൽ {
			goti[mo->n_got++] = mo->e2msym[sym_index];
			എങ്കിൽ (sym->st_shndx == SHN_UNDEF
#ifdef TCC_TARGET_X86_64
			    && type == R_X86_64_GOTPCREL
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
			    && type == R_AARCH64_ADR_GOT_PAGE
#endif
			    ) {
			    mo->bind =
			        tcc_realloc(mo->bind,
					    (mo->n_bind + 1) *
					    വലുപ്പം(ഘടന bind));
			    mo->bind[mo->n_bind].section = s1->got->reloc->sh_info;
			    mo->bind[mo->n_bind].rel = save_rel;
                            mo->bind[mo->n_bind].rel.r_offset = attr->got_offset;
			    mo->n_bind++;
			    s1->got->reloc->data_offset -= വലുപ്പം (ElfW_Rel);
			}
		    }
                }
                എങ്കിൽ (for_code && sym->st_shndx == SHN_UNDEF) {
                    എങ്കിൽ (attr->plt_offset == -1) {
                        attr->plt_offset = mo->stubs->data_offset;
#ifdef TCC_TARGET_X86_64
			എങ്കിൽ (type != R_X86_64_PLT32)
			     തുടരുക;
			/* __stubs */
                        jmp = section_ptr_add(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *__la_symbol_ptr(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->data_offset - 4,
                                       R_X86_64_PC32, mo->lasym,
				       mo->la_ചിഹ്നം_ptr->data_offset - 4);

			/* __stub_helper */
			bind_offset = mo->stub_helper->data_offset + 1;
                        jmp = section_ptr_add(mo->stub_helper, 10);
                        jmp[0] = 0x68;  /* pushq $bind_offset */
                        jmp[5] = 0xe9;  /* jmpq __stub_helper */
                        write32le(jmp + 6, -mo->stub_helper->data_offset);

			/* __la_symbol_ptr */
			la_ചിഹ്നം_offset = mo->la_ചിഹ്നം_ptr->data_offset;
                        put_elf_reloca(s1->symtab, mo->la_ചിഹ്നം_ptr,
				       mo->la_ചിഹ്നം_ptr->data_offset,
				       R_DATA_PTR, mo->helpsym,
				       mo->stub_helper->data_offset - 10);
			section_ptr_add(mo->la_ചിഹ്നം_ptr, PTR_SIZE);
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
			എങ്കിൽ (type != R_AARCH64_CALL26)
			     തുടരുക;
			/* __stubs */
                        jmp = section_ptr_add(mo->stubs, 12);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->data_offset - 12,
                                       R_AARCH64_ADR_PREL_PG_HI21, mo->lasym,
				       mo->la_ചിഹ്നം_ptr->data_offset);
                        write32le(jmp, // adrp x16, __la_symbol_ptr@page
                                  0x90000010);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->data_offset - 8,
                                       R_AARCH64_LDST64_ABS_LO12_NC, mo->lasym,
				       mo->la_ചിഹ്നം_ptr->data_offset);
                        write32le(jmp + 4, // ldr x16,[x16, __la_symbol_ptr@pageoff]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);

			/* __stub_helper */
			bind_offset = mo->stub_helper->data_offset + 8;
                        jmp = section_ptr_add(mo->stub_helper, 12);
                        write32le(jmp + 0, // ldr  w16, l0
                                  0x18000050);
                        write32le(jmp + 4, // b stubHelperHeader
                                  0x14000000 +
				  ((-(mo->stub_helper->data_offset - 8) / 4) &
				   0x3ffffff));
                        write32le(jmp + 8, 0); // l0: .long bind_offset

			/* __la_symbol_ptr */
			la_ചിഹ്നം_offset = mo->la_ചിഹ്നം_ptr->data_offset;
                        put_elf_reloca(s1->symtab, mo->la_ചിഹ്നം_ptr,
				       mo->la_ചിഹ്നം_ptr->data_offset,
				       R_DATA_PTR, mo->helpsym,
				       mo->stub_helper->data_offset - 12);
			section_ptr_add(mo->la_ചിഹ്നം_ptr, PTR_SIZE);
#endif
                        mo->s_lazy_bind =
                            tcc_realloc(mo->s_lazy_bind, (mo->n_lazy_bind + 1) *
                                        വലുപ്പം(ഘടന s_lazy_bind));
                        mo->s_lazy_bind[mo->n_lazy_bind].section =
                            mo->stub_helper->reloc->sh_info;
                        mo->s_lazy_bind[mo->n_lazy_bind].bind_offset =
			    bind_offset;
                        mo->s_lazy_bind[mo->n_lazy_bind].la_ചിഹ്നം_offset =
			    la_ചിഹ്നം_offset;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel = save_rel;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel.r_offset =
                            attr->plt_offset;
                        mo->n_lazy_bind++;
			pi = section_ptr_add(mo->indirsyms, വലുപ്പം(*pi));
			*pi = mo->e2msym[sym_index];
			mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_offset;
                }
            }
            എങ്കിൽ (type == R_DATA_PTR || type == R_JMP_SLOT) {
		എങ്കിൽ (sym->st_shndx == SHN_UNDEF) {
		    mo->bind = tcc_realloc(mo->bind,
					   (mo->n_bind + 1) *
					   വലുപ്പം(ഘടന bind));
		    mo->bind[mo->n_bind].section = s->sh_info;
		    mo->bind[mo->n_bind].rel = save_rel;
		    mo->n_bind++;
		}
		അല്ലെങ്കിൽ {
                    mo->s_rebase =
                        tcc_realloc(mo->s_rebase, (mo->n_rebase + 1) *
				    വലുപ്പം(ഘടന s_rebase));
                    mo->s_rebase[mo->n_rebase].section = s->sh_info;
                    mo->s_rebase[mo->n_rebase].rel = save_rel;
                    mo->n_rebase++;
		}
	    }
        }
    }
    pi = section_ptr_add(mo->indirsyms, mo->n_got * വലുപ്പം(*pi));
    memcpy(pi, goti, mo->n_got * വലുപ്പം(*pi));
    pi = section_ptr_add(mo->indirsyms, mo->nr_plt * വലുപ്പം(*pi));
    memcpy(pi, mo->indirsyms->data, mo->nr_plt * വലുപ്പം(*pi));
    tcc_free(goti);
}
#endif

സ്ഥിതം പൂർണ്ണസംഖ്യ check_symbols(TCCState *s1, ഘടന macho *mo)
{
    പൂർണ്ണസംഖ്യ sym_index, sym_end;
    പൂർണ്ണസംഖ്യ ret = 0;

    mo->ilocal = mo->iextdef = mo->iundef = -1;
    sym_end = symtab_section->data_offset / വലുപ്പം(ElfW(Sym));
    വേണ്ടി (sym_index = 1; sym_index < sym_end; ++sym_index) {
        പൂർണ്ണസംഖ്യ elf_index = ((ഘടന nlist_64 *)mo->symtab->data + sym_index - 1)->n_മൂല്യം;
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + elf_index;
        സ്ഥിരം അക്ഷരം *name = (അക്ഷരം*)symtab_section->link->data + sym->st_name;
        unsigned type = ELFW(ST_TYPE)(sym->st_info);
        unsigned bind = ELFW(ST_BIND)(sym->st_info);
        unsigned vis  = ELFW(ST_VISIBILITY)(sym->st_other);

        dprintf("%4d (%4d): %09lx %4d %4d %4d %3d %s\n",
                sym_index, elf_index, (long)sym->st_മൂല്യം,
                type, bind, vis, sym->st_shndx, name);
        എങ്കിൽ (bind == STB_LOCAL) {
            എങ്കിൽ (mo->ilocal == -1)
              mo->ilocal = sym_index - 1;
            എങ്കിൽ (mo->iextdef != -1 || mo->iundef != -1)
              tcc_error("local syms after global ones");
        } അല്ലെങ്കിൽ എങ്കിൽ (sym->st_shndx != SHN_UNDEF) {
            എങ്കിൽ (mo->iextdef == -1)
              mo->iextdef = sym_index - 1;
            എങ്കിൽ (mo->iundef != -1)
              tcc_error("external defined symbol after undefined");
        } അല്ലെങ്കിൽ എങ്കിൽ (sym->st_shndx == SHN_UNDEF) {
            എങ്കിൽ (mo->iundef == -1)
              mo->iundef = sym_index - 1;
            എങ്കിൽ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK
		|| s1->output_type != TCC_OUTPUT_EXE
                || find_elf_sym(s1->dynsymtab_section, name)) {
                /* Mark the symbol as coming from a dylib so that
                   relocate_syms doesn't complain.  Normally bind_exe_dynsyms
                   would do this check, and place the symbol into dynsym
                   which is checked by relocate_syms.  But Mach-O doesn't use
                   bind_exe_dynsyms.  */
                sym->st_shndx = SHN_FROMDLL;
                തുടരുക;
            }
            tcc_error_noabort("unresolved reference to '%s'", name);
            ret = -1;
        }
    }
    തിരികെ ret;
}

സ്ഥിതം ശൂന്യം convert_ചിഹ്നം(TCCState *s1, ഘടന macho *mo, ഘടന nlist_64 *pn)
{
    ഘടന nlist_64 n = *pn;
    ElfSym *sym = (ElfW(Sym) *)symtab_section->data + pn->n_മൂല്യം;
    സ്ഥിരം അക്ഷരം *name = (അക്ഷരം*)symtab_section->link->data + sym->st_name;
    തിരഞ്ഞെടുപ്പ്(ELFW(ST_TYPE)(sym->st_info)) {
    അവസ്ഥ STT_NOTYPE:
    അവസ്ഥ STT_OBJECT:
    അവസ്ഥ STT_FUNC:
    അവസ്ഥ STT_TLS:
    അവസ്ഥ STT_SECTION:
        n.n_type = N_SECT;
        നിർത്തുക;
    അവസ്ഥ STT_FILE:
        n.n_type = N_ABS;
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        tcc_error("unhandled ELF symbol type %d %s",
                  ELFW(ST_TYPE)(sym->st_info), name);
    }
    എങ്കിൽ (sym->st_shndx == SHN_UNDEF)
      tcc_error("should have been rewritten to SHN_FROMDLL: %s", name);
    അല്ലെങ്കിൽ എങ്കിൽ (sym->st_shndx == SHN_FROMDLL)
      n.n_type = N_UNDF, n.n_sect = 0;
    അല്ലെങ്കിൽ എങ്കിൽ (sym->st_shndx == SHN_ABS)
      n.n_type = N_ABS, n.n_sect = 0;
    അല്ലെങ്കിൽ എങ്കിൽ (sym->st_shndx >= SHN_LORESERVE)
      tcc_error("unhandled ELF symbol section %d %s", sym->st_shndx, name);
    അല്ലെങ്കിൽ എങ്കിൽ (!mo->elfsectomacho[sym->st_shndx]) {
      എങ്കിൽ (strncmp(s1->sections[sym->st_shndx]->name, ".debug_", 7))
        tcc_error("ELF section %d(%s) not mapped into Mach-O for symbol %s",
                  sym->st_shndx, s1->sections[sym->st_shndx]->name, name);
    }
    അല്ലെങ്കിൽ
      n.n_sect = mo->elfsectomacho[sym->st_shndx];
    എങ്കിൽ (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL)
      n.n_type |=  N_EXT;
    അല്ലെങ്കിൽ എങ്കിൽ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
      n.n_desc |= N_WEAK_REF | (n.n_type != N_UNDF ? N_WEAK_DEF : 0);
    n.n_strx = pn->n_strx;
    n.n_മൂല്യം = sym->st_മൂല്യം;
    *pn = n;
}

സ്ഥിതം ശൂന്യം convert_symbols(TCCState *s1, ഘടന macho *mo)
{
    ഘടന nlist_64 *pn;
    for_each_elem(mo->symtab, 0, pn, ഘടന nlist_64)
        convert_ചിഹ്നം(s1, mo, pn);
}

സ്ഥിതം പൂർണ്ണസംഖ്യ machosymcmp(സ്ഥിരം ശൂന്യം *_a, സ്ഥിരം ശൂന്യം *_b, ശൂന്യം *arg)
{
    TCCState *s1 = arg;
    പൂർണ്ണസംഖ്യ ea = ((ഘടന nlist_64 *)_a)->n_മൂല്യം;
    പൂർണ്ണസംഖ്യ eb = ((ഘടന nlist_64 *)_b)->n_മൂല്യം;
    ElfSym *sa = (ElfSym *)symtab_section->data + ea;
    ElfSym *sb = (ElfSym *)symtab_section->data + eb;
    പൂർണ്ണസംഖ്യ r;
    /* locals, then defined externals, then undefined externals, the
       last two sections also by name, otherwise stable sort */
    r = (ELFW(ST_BIND)(sb->st_info) == STB_LOCAL)
        - (ELFW(ST_BIND)(sa->st_info) == STB_LOCAL);
    എങ്കിൽ (r)
      തിരികെ r;
    r = (sa->st_shndx == SHN_UNDEF) - (sb->st_shndx == SHN_UNDEF);
    എങ്കിൽ (r)
      തിരികെ r;
    എങ്കിൽ (ELFW(ST_BIND)(sa->st_info) != STB_LOCAL) {
        സ്ഥിരം അക്ഷരം * na = (അക്ഷരം*)symtab_section->link->data + sa->st_name;
        സ്ഥിരം അക്ഷരം * nb = (അക്ഷരം*)symtab_section->link->data + sb->st_name;
        r = strcmp(na, nb);
        എങ്കിൽ (r)
          തിരികെ r;
    }
    തിരികെ ea - eb;
}

/* cannot use qsort because code has to be reentrant */
സ്ഥിതം ശൂന്യം tcc_qsort (ശൂന്യം  *base, size_t nel, size_t width,
                       പൂർണ്ണസംഖ്യ (*comp)(സ്ഥിരം ശൂന്യം *, സ്ഥിരം ശൂന്യം *, ശൂന്യം *), ശൂന്യം *arg)
{
    size_t wnel, gap, wgap, i, j, k;
    അക്ഷരം *a, *b, tmp;

    wnel = width * nel;
    വേണ്ടി (gap = 0; ++gap < nel;)
        gap *= 3;
    ആകുമ്പോൾ ( gap /= 3 ) {
        wgap = width * gap;
        വേണ്ടി (i = wgap; i < wnel; i += width) {
            വേണ്ടി (j = i - wgap; ;j -= wgap) {
                a = j + (അക്ഷരം *)base;
                b = a + wgap;
                എങ്കിൽ ( (*comp)(a, b, arg) <= 0 )
                    നിർത്തുക;
                k = width;
                ചെയ്യുക {
                    tmp = *a;
                    *a++ = *b;
                    *b++ = tmp;
                } ആകുമ്പോൾ ( --k );
                എങ്കിൽ (j < wgap)
                    നിർത്തുക;
            }
        }
    }
}

സ്ഥിതം ശൂന്യം create_symtab(TCCState *s1, ഘടന macho *mo)
{
    പൂർണ്ണസംഖ്യ sym_index, sym_end;
    ഘടന nlist_64 *pn;

    /* Stub creation belongs to check_relocs, but we need to create
       the symbol now, so its included in the sorting.  */
    mo->stubs = new_section(s1, "__stubs", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->stubsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stubs->sh_അക്കം, ".__stubs");
#ifdef CONFIG_NEW_MACHO
    mo->chained_fixups = new_section(s1, "CHAINED_FIXUPS",
				     SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#അല്ലെങ്കിൽ
    mo->stub_helper = new_section(s1, "__stub_helper", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    mo->la_ചിഹ്നം_ptr = new_section(s1, "__la_symbol_ptr", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->helpsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stub_helper->sh_അക്കം, ".__stub_helper");
    mo->lasym = put_elf_sym(s1->symtab, 0, 0,
                            ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                            mo->la_ചിഹ്നം_ptr->sh_അക്കം, ".__la_symbol_ptr");
    section_ptr_add(data_section, -data_section->data_offset & (PTR_SIZE - 1));
    mo->dyld_private = put_elf_sym(s1->symtab, data_section->data_offset, PTR_SIZE,
                                   ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT), 0,
                                   data_section->sh_അക്കം, ".__dyld_private");
    section_ptr_add(data_section, PTR_SIZE);
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
    sym_end = symtab_section->data_offset / വലുപ്പം(ElfW(Sym));
    pn = section_ptr_add(mo->symtab, വലുപ്പം(*pn) * (sym_end - 1));
    വേണ്ടി (sym_index = 1; sym_index < sym_end; ++sym_index) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
        സ്ഥിരം അക്ഷരം *name = (അക്ഷരം*)symtab_section->link->data + sym->st_name;
        pn[sym_index - 1].n_strx = put_elf_str(mo->strtab, name);
        pn[sym_index - 1].n_മൂല്യം = sym_index;
    }
    section_ptr_add(mo->strtab, -mo->strtab->data_offset & (PTR_SIZE - 1));
    tcc_qsort(pn, sym_end - 1, വലുപ്പം(*pn), machosymcmp, s1);
    mo->e2msym = tcc_malloc(sym_end * വലുപ്പം(*mo->e2msym));
    mo->e2msym[0] = -1;
    വേണ്ടി (sym_index = 1; sym_index < sym_end; ++sym_index) {
        mo->e2msym[pn[sym_index - 1].n_മൂല്യം] = sym_index - 1;
    }
}

സ്ഥിരം ഘടന {
    പൂർണ്ണസംഖ്യ seg_initial;
    uint32_t flags;
    സ്ഥിരം അക്ഷരം *name;
} skinfo[sk_last] = {
    /*[sk_unknown] =*/        { 0 },
    /*[sk_discard] =*/        { 0 },
    /*[sk_text] =*/           { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS, "__text" },
    /*[sk_stubs] =*/          { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS | S_ചിഹ്നം_STUBS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stubs" },
    /*[sk_stub_helper] =*/    { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stub_helper" },
    /*[sk_ro_data] =*/        { 2, S_REGULAR, "__rodata" },
    /*[sk_uw_info] =*/        { 0 },
    /*[sk_nl_ptr] =*/         { 2, S_NON_LAZY_ചിഹ്നം_POINTERS, "__got" },
    /*[sk_debug_info] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_info" },
    /*[sk_debug_abbrev] =*/   { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_abbrev" },
    /*[sk_debug_line] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line" },
    /*[sk_debug_aranges] =*/  { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_aranges" },
    /*[sk_debug_str] =*/      { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_str" },
    /*[sk_debug_line_str] =*/ { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line_str" },
    /*[sk_stab] =*/           { 4, S_REGULAR, "__stab" },
    /*[sk_stab_str] =*/       { 4, S_REGULAR, "__stab_str" },
    /*[sk_la_ptr] =*/         { 4, S_LAZY_ചിഹ്നം_POINTERS, "__la_symbol_ptr" },
    /*[sk_init] =*/           { 4, S_MOD_INIT_FUNC_POINTERS, "__mod_init_func" },
    /*[sk_fini] =*/           { 4, S_MOD_TERM_FUNC_POINTERS, "__mod_term_func" },
    /*[sk_rw_data] =*/        { 4, S_REGULAR, "__data" },
    /*[sk_bss] =*/            { 4, S_ZEROFILL, "__bss" },
    /*[sk_linkedit] =*/       { 5, S_REGULAR, ശൂന്യ },
};

#define	START	((uint64_t)1 << 32)

സ്ഥിരം ഘടന {
    പൂർണ്ണസംഖ്യ used;
    സ്ഥിരം അക്ഷരം *name;
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

#define	N_SEGMENT	(വലുപ്പം(all_segment)/വലുപ്പം(all_segment[0]))

#ifdef CONFIG_NEW_MACHO
സ്ഥിതം ശൂന്യം calc_fixup_size(TCCState *s1, ഘടന macho *mo)
{
    പൂർണ്ണസംഖ്യ i, size;

    size = (വലുപ്പം(ഘടന dyld_chained_fixups_header) + 7) & -8;
    size += (വലുപ്പം(ഘടന dyld_chained_starts_in_image) + (mo->nseg - 1) * വലുപ്പം(uint32_t) + 7) & -8;
    വേണ്ടി (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	പൂർണ്ണസംഖ്യ page_എണ്ണം = (get_segment(mo, i)->vmsize + SEG_PAGE_SIZE - 1) / SEG_PAGE_SIZE;
	size += (വലുപ്പം(ഘടന dyld_chained_starts_in_segment) + (page_എണ്ണം - 1) * വലുപ്പം(uint16_t) + 7) & -8;
    }
    size += mo->n_bind * വലുപ്പം (ഘടന dyld_chained_import) + 1;
    വേണ്ടി (i = 0; i < mo->n_bind_rebase; i++) {
	എങ്കിൽ (mo->bind_rebase[i].bind) {
	    പൂർണ്ണസംഖ്യ sym_index = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	    സ്ഥിരം അക്ഷരം *name = (അക്ഷരം *) symtab_section->link->data + sym->st_name;
	    size += strlen(name) + 1;
	}
    }
    size = (size + 7) & -8;
    section_ptr_add(mo->chained_fixups, size);
}

#അല്ലെങ്കിൽ

സ്ഥിതം ശൂന്യം set_segment_and_offset(TCCState *s1, ഘടന macho *mo, addr_t addr,
				   uint8_t *ptr, പൂർണ്ണസംഖ്യ opcode,
				   Section *sec, addr_t offset)
{
    പൂർണ്ണസംഖ്യ i;
    ഘടന segment_command_64 *seg = ശൂന്യ;

    വേണ്ടി (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	seg = get_segment(mo, i);
	എങ്കിൽ (addr >= seg->vmaddr && addr < (seg->vmaddr + seg->vmsize))
	    നിർത്തുക;
    }
    *ptr = opcode | i;
    write_uleb128(sec, offset - seg->vmaddr);
}

സ്ഥിതം ശൂന്യം bind_rebase(TCCState *s1, ഘടന macho *mo)
{
    പൂർണ്ണസംഖ്യ i;
    uint8_t *ptr;
    ElfW(Sym) *sym;
    സ്ഥിരം അക്ഷരം *name;

    വേണ്ടി (i = 0; i < mo->n_lazy_bind; i++) {
	പൂർണ്ണസംഖ്യ sym_index = ELFW(R_SYM)(mo->s_lazy_bind[i].rel.r_info);

	sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	name = (അക്ഷരം *) symtab_section->link->data + sym->st_name;
	write32le(mo->stub_helper->data +
		  mo->s_lazy_bind[i].bind_offset,
		  mo->lazy_binding->data_offset);
	ptr = section_ptr_add(mo->lazy_binding, 1);
	set_segment_and_offset(s1, mo, mo->la_ചിഹ്നം_ptr->sh_addr, ptr,
			       BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB,
			       mo->lazy_binding,
			       mo->s_lazy_bind[i].la_ചിഹ്നം_offset +
			       mo->la_ചിഹ്നം_ptr->sh_addr);
	ptr = section_ptr_add(mo->lazy_binding, 5 + strlen(name));
	*ptr++ = BIND_OPCODE_SET_DYLIB_SPECIAL_IMM |
		 (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
	*ptr++ = BIND_OPCODE_SET_ചിഹ്നം_TRAILING_FLAGS_IMM | 0;
	strcpy((അക്ഷരം *)ptr, name);
	ptr += strlen(name) + 1;
	*ptr++ = BIND_OPCODE_DO_BIND;
	*ptr = BIND_OPCODE_DONE;
    }
    വേണ്ടി (i = 0; i < mo->n_rebase; i++) {
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
    വേണ്ടി (i = 0; i < mo->n_bind; i++) {
	പൂർണ്ണസംഖ്യ sym_index = ELFW(R_SYM)(mo->bind[i].rel.r_info);
	Section *s = s1->sections[mo->bind[i].section];
	Section *binding;

	sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	name = (അക്ഷരം *) symtab_section->link->data + sym->st_name;
	binding = ELFW(ST_BIND)(sym->st_info) == STB_WEAK
	    ? mo->weak_binding : mo->binding;
        ptr = section_ptr_add(binding, 4 + (binding == mo->binding) +
			     	       strlen(name));
	എങ്കിൽ (binding == mo->binding)
            *ptr++ = BIND_OPCODE_SET_DYLIB_SPECIAL_IMM |
	             (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
        *ptr++ = BIND_OPCODE_SET_ചിഹ്നം_TRAILING_FLAGS_IMM |
		 (binding == mo->weak_binding
		  ? BIND_ചിഹ്നം_FLAGS_WEAK_IMPORT : 0);
        strcpy((അക്ഷരം *)ptr, name);
        ptr += strlen(name) + 1;
        *ptr++ = BIND_OPCODE_SET_TYPE_IMM | BIND_TYPE_POINTER;
	set_segment_and_offset(s1, mo, s->sh_addr, ptr,
			       BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB,
			       binding,
			       mo->bind[i].rel.r_offset + s->sh_addr);
        ptr = section_ptr_add(binding, 1);
        *ptr++ = BIND_OPCODE_DO_BIND;
    }
    എങ്കിൽ (mo->rebase->data_offset) {
        ptr = section_ptr_add(mo->rebase, 1);
        *ptr = REBASE_OPCODE_DONE;
    }
    എങ്കിൽ (mo->binding->data_offset) {
        ptr = section_ptr_add(mo->binding, 1);
        *ptr = BIND_OPCODE_DONE;
    }
    എങ്കിൽ (mo->weak_binding->data_offset) {
        ptr = section_ptr_add(mo->weak_binding, 1);
        *ptr = BIND_OPCODE_DONE;
    }
    tcc_free(mo->s_lazy_bind);
    tcc_free(mo->s_rebase);
    tcc_free(mo->bind);
}
#endif

ഘടന trie_info {
    സ്ഥിരം അക്ഷരം *name;
    പൂർണ്ണസംഖ്യ flag;
    addr_t addr;
    പൂർണ്ണസംഖ്യ str_size;
    പൂർണ്ണസംഖ്യ term_size;
};

ഘടന trie_കണ്ണി {
    പൂർണ്ണസംഖ്യ start;
    പൂർണ്ണസംഖ്യ end;
    പൂർണ്ണസംഖ്യ index_start;
    പൂർണ്ണസംഖ്യ index_end;
    പൂർണ്ണസംഖ്യ n_child;
    ഘടന trie_കണ്ണി *child;
};

ഘടന trie_seq {
    പൂർണ്ണസംഖ്യ n_child;
    ഘടന trie_കണ്ണി *കണ്ണി;
    പൂർണ്ണസംഖ്യ offset;
    പൂർണ്ണസംഖ്യ nest_offset;
};

സ്ഥിതം ശൂന്യം create_trie(ഘടന trie_കണ്ണി *കണ്ണി,
                        പൂർണ്ണസംഖ്യ from, പൂർണ്ണസംഖ്യ to, പൂർണ്ണസംഖ്യ index_start,
                        പൂർണ്ണസംഖ്യ n_trie, ഘടന trie_info *trie)
{
    പൂർണ്ണസംഖ്യ i;
    പൂർണ്ണസംഖ്യ start, end, index_end;
    അക്ഷരം cur;
    ഘടന trie_കണ്ണി *child;

    വേണ്ടി (i = from; i < to; i = end) {
        cur = trie[i].name[index_start];
        start = i++;
        വേണ്ടി (; i < to; i++)
            എങ്കിൽ (cur != trie[i].name[index_start])
                നിർത്തുക;
        end = i;
        എങ്കിൽ (start == end - 1 ||
            (trie[start].name[index_start] &&
             trie[start].name[index_start + 1] == 0))
            index_end = trie[start].str_size - 1;
        അല്ലെങ്കിൽ {
            index_end = index_start + 1;
            വേണ്ടി (;;) {
                cur = trie[start].name[index_end];
                വേണ്ടി (i = start + 1; i < end; i++)
                    എങ്കിൽ (cur != trie[i].name[index_end])
                        നിർത്തുക;
                എങ്കിൽ (trie[start].name[index_end] &&
                    trie[start].name[index_end + 1] == 0) {
                    end = start + 1;
                    index_end = trie[start].str_size - 1;
                    നിർത്തുക;
                }
                എങ്കിൽ (i != end)
                    നിർത്തുക;
                index_end++;
            }
        }
        കണ്ണി->child = tcc_realloc(കണ്ണി->child,
                                  (കണ്ണി->n_child + 1) *
                                  വലുപ്പം(ഘടന trie_കണ്ണി));
        child = &കണ്ണി->child[കണ്ണി->n_child];
        child->start = start;
        child->end = end;
        child->index_start = index_start;
        child->index_end = index_end;
        child->n_child = 0;
        child->child = ശൂന്യ;
        കണ്ണി->n_child++;
        എങ്കിൽ (start != end - 1)
            create_trie(child, start, end, index_end, n_trie, trie);
    }
}

സ്ഥിതം പൂർണ്ണസംഖ്യ create_seq(പൂർണ്ണസംഖ്യ *offset, പൂർണ്ണസംഖ്യ *n_seq, ഘടന trie_seq **seq,
                        ഘടന trie_കണ്ണി *കണ്ണി,
                        പൂർണ്ണസംഖ്യ n_trie, ഘടന trie_info *trie)
{
    പൂർണ്ണസംഖ്യ i, nest_offset, last_seq = *n_seq, retval = *offset;
    ഘടന trie_seq *p_seq;
    ഘടന trie_കണ്ണി *p_nest;

    വേണ്ടി (i = 0; i < കണ്ണി->n_child; i++) {
        p_nest = &കണ്ണി->child[i];
        *seq = tcc_realloc(*seq, (*n_seq + 1) * വലുപ്പം(ഘടന trie_seq));
        p_seq = &(*seq)[(*n_seq)++];
        p_seq->n_child = i == 0 ? കണ്ണി->n_child : -1;
        p_seq->കണ്ണി = p_nest;
        p_seq->offset = *offset;
        p_seq->nest_offset = 0;
        *offset += (i == 0 ? 1 + 1 : 0) +
                   p_nest->index_end - p_nest->index_start + 1 + 3;
    }
    വേണ്ടി (i = 0; i < കണ്ണി->n_child; i++) {
        nest_offset =
            create_seq(offset, n_seq, seq, &കണ്ണി->child[i], n_trie, trie);
        p_seq = &(*seq)[last_seq + i];
        p_seq->nest_offset = nest_offset;
    }
    തിരികെ retval;
}

സ്ഥിതം ശൂന്യം കണ്ണി_free(ഘടന trie_കണ്ണി *കണ്ണി)
{
    പൂർണ്ണസംഖ്യ i;

    വേണ്ടി (i = 0; i < കണ്ണി->n_child; i++)
	കണ്ണി_free(&കണ്ണി->child[i]);
    tcc_free(കണ്ണി->child);
}

സ്ഥിതം പൂർണ്ണസംഖ്യ triecmp(സ്ഥിരം ശൂന്യം *_a, സ്ഥിരം ശൂന്യം *_b, ശൂന്യം *arg)
{
    ഘടന trie_info *a = (ഘടന trie_info *) _a;
    ഘടന trie_info *b = (ഘടന trie_info *) _b;
    പൂർണ്ണസംഖ്യ len_a = strlen(a->name);
    പൂർണ്ണസംഖ്യ len_b = strlen(b->name);

    /* strange sorting needed. Name 'xx' should be after 'xx1' */
    എങ്കിൽ (!strncmp(a->name, b->name, len_a < len_b ? len_a : len_b))
	തിരികെ len_a < len_b ? 1 : (len_a > len_b ? -1 : 0);
    തിരികെ strcmp(a->name, b->name);
}

സ്ഥിതം ശൂന്യം export_trie(TCCState *s1, ഘടന macho *mo)
{
    പൂർണ്ണസംഖ്യ i, size, offset = 0, save_offset;
    uint8_t *ptr;
    പൂർണ്ണസംഖ്യ sym_index;
    പൂർണ്ണസംഖ്യ sym_end = symtab_section->data_offset / വലുപ്പം(ElfW(Sym));
    പൂർണ്ണസംഖ്യ n_trie = 0, n_seq = 0;
    ഘടന trie_info *trie = ശൂന്യ, *p_trie;
    ഘടന trie_കണ്ണി കണ്ണി, *p_കണ്ണി;
    ഘടന trie_seq *seq = ശൂന്യ;
    addr_t vm_addr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;

    വേണ്ടി (sym_index = 1; sym_index < sym_end; ++sym_index) {
	ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
	സ്ഥിരം അക്ഷരം *name = (അക്ഷരം*)symtab_section->link->data + sym->st_name;

	എങ്കിൽ (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE &&
            (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL ||
	     ELFW(ST_BIND)(sym->st_info) == STB_WEAK)) {
	    പൂർണ്ണസംഖ്യ flag = EXPORT_ചിഹ്നം_FLAGS_KIND_REGULAR;
	    addr_t addr =
		sym->st_മൂല്യം + s1->sections[sym->st_shndx]->sh_addr - vm_addr;

	    എങ്കിൽ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
		flag |= EXPORT_ചിഹ്നം_FLAGS_WEAK_DEFINITION;
	    dprintf ("%s %d %llx\n", name, flag, (long long)addr + vm_addr);
	    trie = tcc_realloc(trie, (n_trie + 1) * വലുപ്പം(ഘടന trie_info));
	    trie[n_trie].name = name;
	    trie[n_trie].flag = flag;
	    trie[n_trie].addr = addr;
	    trie[n_trie].str_size = strlen(name) + 1;
	    trie[n_trie].term_size = uleb128_size(flag) + uleb128_size(addr);
	    n_trie++;
	}
    }
    എങ്കിൽ (n_trie) {
        tcc_qsort(trie, n_trie, വലുപ്പം(ഘടന trie_info), triecmp, ശൂന്യ);
	memset(&കണ്ണി, 0, വലുപ്പം(കണ്ണി));
        create_trie(&കണ്ണി, 0, n_trie, 0, n_trie, trie);
	create_seq(&offset, &n_seq, &seq, &കണ്ണി, n_trie, trie);
        save_offset = offset;
        വേണ്ടി (i = 0; i < n_seq; i++) {
            p_കണ്ണി = seq[i].കണ്ണി;
            എങ്കിൽ (p_കണ്ണി->n_child == 0) {
                p_trie = &trie[p_കണ്ണി->start];
                seq[i].nest_offset = offset;
                offset += 1 + p_trie->term_size + 1;
            }
        }
        വേണ്ടി (i = 0; i < n_seq; i++) {
            p_കണ്ണി = seq[i].കണ്ണി;
            p_trie = &trie[p_കണ്ണി->start];
            എങ്കിൽ (seq[i].n_child >= 0) {
                section_ptr_add(mo->exports,
				seq[i].offset - mo->exports->data_offset);
                ptr = section_ptr_add(mo->exports, 2);
                *ptr++ = 0;
                *ptr = seq[i].n_child;
            }
            size = p_കണ്ണി->index_end - p_കണ്ണി->index_start;
            ptr = section_ptr_add(mo->exports, size + 1);
            memcpy(ptr, &p_trie->name[p_കണ്ണി->index_start], size);
            ptr[size] = 0;
            write_uleb128(mo->exports, seq[i].nest_offset);
        }
        section_ptr_add(mo->exports, save_offset - mo->exports->data_offset);
        വേണ്ടി (i = 0; i < n_seq; i++) {
            p_കണ്ണി = seq[i].കണ്ണി;
            എങ്കിൽ (p_കണ്ണി->n_child == 0) {
                p_trie = &trie[p_കണ്ണി->start];
                write_uleb128(mo->exports, p_trie->term_size);
                write_uleb128(mo->exports, p_trie->flag);
                write_uleb128(mo->exports, p_trie->addr);
                ptr = section_ptr_add(mo->exports, 1);
                *ptr = 0;
            }
        }
        section_ptr_add(mo->exports, -mo->exports->data_offset & 7);
	കണ്ണി_free(&കണ്ണി);
        tcc_free(seq);
    }
    tcc_free(trie);
}

സ്ഥിതം ശൂന്യം collect_sections(TCCState *s1, ഘടന macho *mo, സ്ഥിരം അക്ഷരം *filename)
{
    പൂർണ്ണസംഖ്യ i, sk, numsec;
    പൂർണ്ണസംഖ്യ used_segment[N_SEGMENT];
    uint64_t curaddr, fileofs;
    Section *s;
    ഘടന segment_command_64 *seg;
    ഘടന dylib_command *dylib;
#ifdef CONFIG_NEW_MACHO
    ഘടന linkedit_data_command *chained_fixups_lc;
    ഘടന linkedit_data_command *export_trie_lc;
#endif
    ഘടന build_version_command *dyldbv;
    ഘടന source_version_command *dyldsv;
    ഘടന rpath_command *rpath;
    ഘടന dylinker_command *dyldlc;
    ഘടന symtab_command *symlc;
    ഘടന dysymtab_command *dysymlc;
    അക്ഷരം *str;

    വേണ്ടി (i = 0; i < N_SEGMENT; i++)
	used_segment[i] = all_segment[i].used;

    memset (mo->sk_to_sect, 0, വലുപ്പം(mo->sk_to_sect));
    വേണ്ടി (i = s1->nb_sections; i-- > 1;) {
        പൂർണ്ണസംഖ്യ type, flags;
        s = s1->sections[i];
        type = s->sh_type;
        flags = s->sh_flags;
        sk = sk_unknown;
	/* debug sections have sometimes no SHF_ALLOC */
        എങ്കിൽ ((flags & SHF_ALLOC) || !strncmp(s->name, ".debug_", 7)) {
            തിരഞ്ഞെടുപ്പ് (type) {
            സ്ഥിരസ്ഥിതി:           sk = sk_unknown; നിർത്തുക;
            അവസ്ഥ SHT_INIT_ARRAY: sk = sk_init; നിർത്തുക;
            അവസ്ഥ SHT_FINI_ARRAY: sk = sk_fini; നിർത്തുക;
            അവസ്ഥ SHT_NOBITS:   sk = sk_bss; നിർത്തുക;
            അവസ്ഥ SHT_SYMTAB:   sk = sk_discard; നിർത്തുക;
            അവസ്ഥ SHT_STRTAB:
		എങ്കിൽ (s == stabstr_section)
		  sk = sk_stab_str;
		അല്ലെങ്കിൽ
		  sk = sk_discard;
		നിർത്തുക;
            അവസ്ഥ SHT_RELX:     sk = sk_discard; നിർത്തുക;
            അവസ്ഥ SHT_LINKEDIT: sk = sk_linkedit; നിർത്തുക;
            അവസ്ഥ SHT_PROGBITS:
                എങ്കിൽ (s == mo->stubs)
                  sk = sk_stubs;
#ifndef CONFIG_NEW_MACHO
                അല്ലെങ്കിൽ എങ്കിൽ (s == mo->stub_helper)
                  sk = sk_stub_helper;
                അല്ലെങ്കിൽ എങ്കിൽ (s == mo->la_ചിഹ്നം_ptr)
                  sk = sk_la_ptr;
#endif
                അല്ലെങ്കിൽ എങ്കിൽ (s == rodata_section)
                  sk = sk_ro_data;
                അല്ലെങ്കിൽ എങ്കിൽ (s == s1->got)
                  sk = sk_nl_ptr;
                അല്ലെങ്കിൽ എങ്കിൽ (s == stab_section)
                  sk = sk_stab;
                അല്ലെങ്കിൽ എങ്കിൽ (s == dwarf_info_section)
                  sk = sk_debug_info;
                അല്ലെങ്കിൽ എങ്കിൽ (s == dwarf_abbrev_section)
                  sk = sk_debug_abbrev;
                അല്ലെങ്കിൽ എങ്കിൽ (s == dwarf_വരി_section)
                  sk = sk_debug_വരി;
                അല്ലെങ്കിൽ എങ്കിൽ (s == dwarf_aranges_section)
                  sk = sk_debug_aranges;
                അല്ലെങ്കിൽ എങ്കിൽ (s == dwarf_str_section)
                  sk = sk_debug_str;
                അല്ലെങ്കിൽ എങ്കിൽ (s == dwarf_വരി_str_section)
                  sk = sk_debug_വരി_str;
                അല്ലെങ്കിൽ എങ്കിൽ (flags & SHF_EXECINSTR)
                  sk = sk_text;
                അല്ലെങ്കിൽ എങ്കിൽ (flags & SHF_WRITE)
                  sk = sk_rw_data;
                അല്ലെങ്കിൽ
                  sk = sk_ro_data;
                നിർത്തുക;
            }
        } അല്ലെങ്കിൽ
          sk = sk_discard;
        s->prev = mo->sk_to_sect[sk].s;
        mo->sk_to_sect[sk].s = s;
	used_segment[skinfo[sk].seg_initial] = 1;
    }

    എങ്കിൽ (s1->output_type != TCC_OUTPUT_EXE)
	used_segment[0] = 0;

    വേണ്ടി (i = 0; i < N_SEGMENT; i++)
	എങ്കിൽ (used_segment[i]) {
	    seg = add_segment(mo, all_segment[i].name);
	    എങ്കിൽ (i == 1 && s1->output_type != TCC_OUTPUT_EXE)
	        seg->vmaddr = 0;
	    അല്ലെങ്കിൽ
	        seg->vmaddr = all_segment[i].vmaddr;
	    seg->vmsize = all_segment[i].vmsize;
	    seg->maxprot = all_segment[i].maxprot;
	    seg->initprot = all_segment[i].initprot;
	    seg->flags = all_segment[i].flags;
            വേണ്ടി (sk = sk_unknown; sk < sk_last; sk++)
		എങ്കിൽ (skinfo[sk].seg_initial == i)
	            mo->segment[sk] = mo->nseg - 1;
	}

    എങ്കിൽ (s1->output_type != TCC_OUTPUT_EXE) {
	സ്ഥിരം അക്ഷരം *name = s1->install_name ? s1->install_name : filename;
        i = (വലുപ്പം(*dylib) + strlen(name) + 1 + 7) &-8;
        dylib = add_lc(mo, LC_ID_DYLIB, i);
	dylib->name = വലുപ്പം(*dylib);
	dylib->timestamp = 1;
	dylib->current_version =
	    s1->current_version ? s1->current_version : 1 << 16;
	dylib->compatibility_version =
	    s1->compatibility_version ? s1->compatibility_version : 1 << 16;
        str = (അക്ഷരം*)dylib + dylib->name;
        strcpy(str, name);
    }

#ifdef CONFIG_NEW_MACHO
    chained_fixups_lc = add_lc(mo, LC_DYLD_CHAINED_FIXUPS,
			       വലുപ്പം(ഘടന linkedit_data_command));
    export_trie_lc = add_lc(mo, LC_DYLD_EXPORTS_TRIE,
			    വലുപ്പം(ഘടന linkedit_data_command));
#അല്ലെങ്കിൽ
    mo->dyldinfo = add_lc(mo, LC_DYLD_INFO_ONLY, വലുപ്പം(*mo->dyldinfo));
#endif

    symlc = add_lc(mo, LC_SYMTAB, വലുപ്പം(*symlc));
    dysymlc = add_lc(mo, LC_DYSYMTAB, വലുപ്പം(*dysymlc));

    എങ്കിൽ (s1->output_type == TCC_OUTPUT_EXE) {
        i = (വലുപ്പം(*dyldlc) + strlen("/usr/lib/dyld") + 1 + 7) &-8;
        dyldlc = add_lc(mo, LC_LOAD_DYLINKER, i);
        dyldlc->name = വലുപ്പം(*dyldlc);
        str = (അക്ഷരം*)dyldlc + dyldlc->name;
        strcpy(str, "/usr/lib/dyld");
    }

    dyldbv = add_lc(mo, LC_BUILD_VERSION, വലുപ്പം(*dyldbv));
    dyldbv->platform = PLATFORM_MACOS;
    dyldbv->minos = (10 << 16) + (6 << 8);
    dyldbv->sdk = (10 << 16) + (6 << 8);
    dyldbv->ntools = 0;

    dyldsv = add_lc(mo, LC_SOURCE_VERSION, വലുപ്പം(*dyldsv));
    dyldsv->version = 0;

    എങ്കിൽ (s1->output_type == TCC_OUTPUT_EXE) {
        mo->ep = add_lc(mo, LC_MAIN, വലുപ്പം(*mo->ep));
        mo->ep->entryoff = 4096;
    }

    വേണ്ടി(i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *dllref = s1->loaded_dlls[i];
        എങ്കിൽ (dllref->level == 0)
          add_dylib(mo, dllref->name);
    }

    എങ്കിൽ (s1->rpath) {
	അക്ഷരം *path = s1->rpath, *end;
	ചെയ്യുക {
	    end = strchr(path, ':');
	    എങ്കിൽ (!end)
		end = strchr(path, 0);
            i = (വലുപ്പം(*rpath) + (end - path) + 1 + 7) &-8;
            rpath = add_lc(mo, LC_RPATH, i);
            rpath->path = വലുപ്പം(*rpath);
            str = (അക്ഷരം*)rpath + rpath->path;
            memcpy(str, path, end - path);
	    str[end - path] = 0;
	    path = end + 1;
	} ആകുമ്പോൾ (*end);
    }

    fileofs = 4096;  /* leave space for mach-o headers */
    curaddr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;
    curaddr += 4096;
    seg = ശൂന്യ;
    numsec = 0;
    mo->elfsectomacho = tcc_mallocz(വലുപ്പം(*mo->elfsectomacho) * s1->nb_sections);
    വേണ്ടി (sk = sk_unknown; sk < sk_last; sk++) {
        ഘടന section_64 *sec = ശൂന്യ;
        എങ്കിൽ (seg) {
            seg->vmsize = curaddr - seg->vmaddr;
            seg->filesize = fileofs - seg->fileoff;
        }
#ifdef CONFIG_NEW_MACHO
	എങ്കിൽ (sk == sk_linkedit) {
	    calc_fixup_size(s1, mo);
	    export_trie(s1, mo);
	}
#അല്ലെങ്കിൽ
	എങ്കിൽ (sk == sk_linkedit) {
	    bind_rebase(s1, mo);
	    export_trie(s1, mo);
	}
#endif
        എങ്കിൽ (skinfo[sk].seg_initial &&
	    (s1->output_type != TCC_OUTPUT_EXE || mo->segment[sk]) &&
	    mo->sk_to_sect[sk].s) {
            uint64_t al = 0;
            പൂർണ്ണസംഖ്യ si;
            seg = get_segment(mo, mo->segment[sk]);
            എങ്കിൽ (skinfo[sk].name) {
                si = add_section(mo, &seg, skinfo[sk].name);
                numsec++;
                mo->lc[mo->seg2lc[mo->segment[sk]]] = (ഘടന load_command*)seg;
                mo->sk_to_sect[sk].machosect = si;
                sec = get_section(seg, si);
                sec->flags = skinfo[sk].flags;
		എങ്കിൽ (sk == sk_stubs)
#ifdef TCC_TARGET_X86_64
	    	    sec->reserved2 = 6;
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
	    	    sec->reserved2 = 12;
#endif
		എങ്കിൽ (sk == sk_nl_ptr)
	    	    sec->reserved1 = mo->nr_plt;
#ifndef CONFIG_NEW_MACHO
		എങ്കിൽ (sk == sk_la_ptr)
	    	    sec->reserved1 = mo->nr_plt + mo->n_got;
#endif
            }
            എങ്കിൽ (seg->vmaddr == -1) {
                curaddr = (curaddr + SEG_PAGE_SIZE - 1) & -SEG_PAGE_SIZE;
                seg->vmaddr = curaddr;
                fileofs = (fileofs + SEG_PAGE_SIZE - 1) & -SEG_PAGE_SIZE;
                seg->fileoff = fileofs;
            }

            വേണ്ടി (s = mo->sk_to_sect[sk].s; s; s = s->prev) {
                പൂർണ്ണസംഖ്യ a = exact_log2p1(s->sh_addralign);
                എങ്കിൽ (a && al < (a - 1))
                  al = a - 1;
                s->sh_size = s->data_offset;
            }
            എങ്കിൽ (sec)
              sec->align = al;
            al = 1ULL << al;
            എങ്കിൽ (al > 4096)
              tcc_warning("alignment > 4096"), sec->align = 12, al = 4096;
            curaddr = (curaddr + al - 1) & -al;
            fileofs = (fileofs + al - 1) & -al;
            എങ്കിൽ (sec) {
                sec->addr = curaddr;
                sec->offset = fileofs;
            }
            വേണ്ടി (s = mo->sk_to_sect[sk].s; s; s = s->prev) {
                al = s->sh_addralign;
                curaddr = (curaddr + al - 1) & -al;
                dprintf("%s: curaddr now 0x%lx\n", s->name, (long)curaddr);
                s->sh_addr = curaddr;
                curaddr += s->sh_size;
                എങ്കിൽ (s->sh_type != SHT_NOBITS) {
                    fileofs = (fileofs + al - 1) & -al;
                    s->sh_offset = fileofs;
                    fileofs += s->sh_size;
                    dprintf("%s: fileofs now %ld\n", s->name, (long)fileofs);
                }
                എങ്കിൽ (sec)
                  mo->elfsectomacho[s->sh_അക്കം] = numsec;
            }
            എങ്കിൽ (sec)
              sec->size = curaddr - sec->addr;
        }
        എങ്കിൽ (DEBUG_MACHO)
          വേണ്ടി (s = mo->sk_to_sect[sk].s; s; s = s->prev) {
              പൂർണ്ണസംഖ്യ type = s->sh_type;
              പൂർണ്ണസംഖ്യ flags = s->sh_flags;
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
                     (unsigned)s->data_offset,
                     s->sh_addralign,
                     flags & SHF_ALLOC ? "alloc" : "",
                     flags & SHF_WRITE ? "write" : "",
                     flags & SHF_EXECINSTR ? "exec" : ""
                    );
          }
    }
    എങ്കിൽ (seg) {
        seg->vmsize = curaddr - seg->vmaddr;
        seg->filesize = fileofs - seg->fileoff;
    }

    /* Fill symtab info */
    symlc->symoff = mo->symtab->sh_offset;
    symlc->nsyms = mo->symtab->data_offset / വലുപ്പം(ഘടന nlist_64);
    symlc->stroff = mo->strtab->sh_offset;
    symlc->strsize = mo->strtab->data_offset;

    dysymlc->iundefsym = mo->iundef == -1 ? symlc->nsyms : mo->iundef;
    dysymlc->iextdefsym = mo->iextdef == -1 ? dysymlc->iundefsym : mo->iextdef;
    dysymlc->ilocalsym = mo->ilocal == -1 ? dysymlc->iextdefsym : mo->ilocal;
    dysymlc->nlocalsym = dysymlc->iextdefsym - dysymlc->ilocalsym;
    dysymlc->nextdefsym = dysymlc->iundefsym - dysymlc->iextdefsym;
    dysymlc->nundefsym = symlc->nsyms - dysymlc->iundefsym;
    dysymlc->indirectsymoff = mo->indirsyms->sh_offset;
    dysymlc->nindirectsyms = mo->indirsyms->data_offset / വലുപ്പം(uint32_t);

#ifdef CONFIG_NEW_MACHO
    എങ്കിൽ (mo->chained_fixups->data_offset) {
        chained_fixups_lc->dataoff = mo->chained_fixups->sh_offset;
        chained_fixups_lc->datasize = mo->chained_fixups->data_offset;
    }
    എങ്കിൽ (mo->exports->data_offset) {
        export_trie_lc->dataoff = mo->exports->sh_offset;
        export_trie_lc->datasize = mo->exports->data_offset;
    }
#അല്ലെങ്കിൽ
    എങ്കിൽ (mo->rebase->data_offset) {
        mo->dyldinfo->rebase_off = mo->rebase->sh_offset;
        mo->dyldinfo->rebase_size = mo->rebase->data_offset;
    }
    എങ്കിൽ (mo->binding->data_offset) {
        mo->dyldinfo->bind_off = mo->binding->sh_offset;
        mo->dyldinfo->bind_size = mo->binding->data_offset;
    }
    എങ്കിൽ (mo->weak_binding->data_offset) {
        mo->dyldinfo->weak_bind_off = mo->weak_binding->sh_offset;
        mo->dyldinfo->weak_bind_size = mo->weak_binding->data_offset;
    }
    എങ്കിൽ (mo->lazy_binding->data_offset) {
        mo->dyldinfo->lazy_bind_off = mo->lazy_binding->sh_offset;
        mo->dyldinfo->lazy_bind_size = mo->lazy_binding->data_offset;
    }
    എങ്കിൽ (mo->exports->data_offset) {
        mo->dyldinfo->export_off = mo->exports->sh_offset;
        mo->dyldinfo->export_size = mo->exports->data_offset;
    }
#endif
}

സ്ഥിതം ശൂന്യം macho_write(TCCState *s1, ഘടന macho *mo, FILE *fp)
{
    പൂർണ്ണസംഖ്യ i, sk;
    uint64_t fileofs = 0;
    Section *s;
    mo->mh.mh.magic = MH_MAGIC_64;
#ifdef TCC_TARGET_X86_64
    mo->mh.mh.cputype = CPU_TYPE_X86_64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_LIB64 | CPU_SUBTYPE_X86_ALL;
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
    mo->mh.mh.cputype = CPU_TYPE_ARM64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_ARM64_ALL;
#endif
    എങ്കിൽ (s1->output_type == TCC_OUTPUT_EXE) {
        mo->mh.mh.filetype = MH_EXECUTE;
        mo->mh.mh.flags = MH_DYLDLINK | MH_PIE;
    }
    അല്ലെങ്കിൽ {
        mo->mh.mh.filetype = MH_DYLIB;
        mo->mh.mh.flags = MH_DYLDLINK;
    }
    mo->mh.mh.ncmds = mo->nlc;
    mo->mh.mh.sizeofcmds = 0;
    വേണ്ടി (i = 0; i < mo->nlc; i++)
      mo->mh.mh.sizeofcmds += mo->lc[i]->cmdsize;

    fwrite(&mo->mh, 1, വലുപ്പം(mo->mh), fp);
    fileofs += വലുപ്പം(mo->mh);
    വേണ്ടി (i = 0; i < mo->nlc; i++) {
        fwrite(mo->lc[i], 1, mo->lc[i]->cmdsize, fp);
        fileofs += mo->lc[i]->cmdsize;
    }

    വേണ്ടി (sk = sk_unknown; sk < sk_last; sk++) {
        //struct segment_command_64 *seg;
        എങ്കിൽ (skinfo[sk].seg_initial == 0 ||
	    (s1->output_type == TCC_OUTPUT_EXE && !mo->segment[sk]) ||
	    !mo->sk_to_sect[sk].s)
          തുടരുക;
        /*seg =*/ get_segment(mo, mo->segment[sk]);
        വേണ്ടി (s = mo->sk_to_sect[sk].s; s; s = s->prev) {
            എങ്കിൽ (s->sh_type != SHT_NOBITS) {
                ആകുമ്പോൾ (fileofs < s->sh_offset)
                  fputc(0, fp), fileofs++;
                എങ്കിൽ (s->sh_size) {
                    fwrite(s->data, 1, s->sh_size, fp);
                    fileofs += s->sh_size;
                }
            }
        }
    }
}

#ifdef CONFIG_NEW_MACHO
സ്ഥിതം പൂർണ്ണസംഖ്യ bind_rebase_cmp(സ്ഥിരം ശൂന്യം *_a, സ്ഥിരം ശൂന്യം *_b, ശൂന്യം *arg)
{
    TCCState *s1 = arg;
    ഘടന bind_rebase *a = (ഘടന bind_rebase *) _a;
    ഘടന bind_rebase *b = (ഘടന bind_rebase *) _b;
    addr_t aa = s1->sections[a->section]->sh_addr + a->rel.r_offset;
    addr_t ab = s1->sections[b->section]->sh_addr + b->rel.r_offset;

    തിരികെ aa > ab ? 1 : aa < ab ? -1 : 0;
}

ST_FUNC ശൂന്യം bind_rebase_import(TCCState *s1, ഘടന macho *mo)
{
    പൂർണ്ണസംഖ്യ i, j, k, bind_index, size, page_എണ്ണം, sym_index;
    സ്ഥിരം അക്ഷരം *name;
    ElfW(Sym) *sym;
    unsigned അക്ഷരം *data = mo->chained_fixups->data;
    ഘടന segment_command_64 *seg;
    ഘടന dyld_chained_fixups_header *header;
    ഘടന dyld_chained_starts_in_image *image;
    ഘടന dyld_chained_starts_in_segment *segment;
    ഘടന dyld_chained_import *import;

    tcc_qsort(mo->bind_rebase, mo->n_bind_rebase, വലുപ്പം(ഘടന bind_rebase),
	      bind_rebase_cmp, s1);
    വേണ്ടി (i = 0; i < mo->n_bind_rebase - 1; i++)
	എങ്കിൽ (mo->bind_rebase[i].section == mo->bind_rebase[i + 1].section &&
	    mo->bind_rebase[i].rel.r_offset == mo->bind_rebase[i + 1].rel.r_offset) {
	    sym_index = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
            sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	    name = (അക്ഷരം *) symtab_section->link->data + sym->st_name;
	    tcc_error("Overlap %s/%s %s:%s",
		      mo->bind_rebase[i].bind ? "bind" : "rebase",
		      mo->bind_rebase[i + 1].bind ? "bind" : "rebase",
		      s1->sections[mo->bind_rebase[i].section]->name, name);
	}
    header = (ഘടന dyld_chained_fixups_header *) data;
    data += (വലുപ്പം(ഘടന dyld_chained_fixups_header) + 7) & -8;
    header->starts_offset = data - mo->chained_fixups->data;
    header->imports_എണ്ണം = mo->n_bind;
    header->imports_format = DYLD_CHAINED_IMPORT;
    header->symbols_format = 0;
    size = വലുപ്പം(ഘടന dyld_chained_starts_in_image) +
	   (mo->nseg - 1) * വലുപ്പം(uint32_t);
    image = (ഘടന dyld_chained_starts_in_image *) data;
    data += (size + 7) & -8;
    image->seg_എണ്ണം = mo->nseg;
    വേണ്ടി (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
        image->seg_info_offset[i] = (data - mo->chained_fixups->data) -
				    header->starts_offset;
	seg = get_segment(mo, i);
	page_എണ്ണം = (seg->vmsize + SEG_PAGE_SIZE - 1) / SEG_PAGE_SIZE;
	size = വലുപ്പം(ഘടന dyld_chained_starts_in_segment) +
		      (page_എണ്ണം - 1) * വലുപ്പം(uint16_t);
        segment = (ഘടന dyld_chained_starts_in_segment *) data;
        data += (size + 7) & -8;
        segment->size = size;
        segment->page_size = SEG_PAGE_SIZE;
#എങ്കിൽ 1
#define	PTR_64_OFFSET 0
#define	PTR_64_MASK   0x7FFFFFFFFFFULL
        segment->pointer_format = DYLD_CHAINED_PTR_64;
#അല്ലെങ്കിൽ
#define	PTR_64_OFFSET 0x100000000ULL
#define	PTR_64_MASK   0xFFFFFFFFFFFFFFULL
        segment->pointer_format = DYLD_CHAINED_PTR_64_OFFSET;
#endif
        segment->segment_offset = seg->fileoff;
        segment->max_valid_pointer = 0;
        segment->page_എണ്ണം = page_എണ്ണം;
	// add bind/rebase
	bind_index = 0;
	k = 0;
	വേണ്ടി (j = 0; j < page_എണ്ണം; j++) {
	    addr_t start = seg->vmaddr + j * SEG_PAGE_SIZE;
	    addr_t end = start + SEG_PAGE_SIZE;
	    ശൂന്യം *last = ശൂന്യ;
	    addr_t last_o = 0;
	    addr_t cur_o, cur;
	    ഘടന dyld_chained_ptr_64_rebase *rebase;
	    ഘടന dyld_chained_ptr_64_bind *bind;

	    segment->page_start[j] = DYLD_CHAINED_PTR_START_NONE;
	    വേണ്ടി (; k < mo->n_bind_rebase; k++) {
	        Section *s = s1->sections[mo->bind_rebase[k].section];
		addr_t r_offset = mo->bind_rebase[k].rel.r_offset;
		addr_t addr = s->sh_addr + r_offset;

		എങ്കിൽ ((addr & 3) ||
		    (addr & (SEG_PAGE_SIZE - 1)) > SEG_PAGE_SIZE - PTR_SIZE)
		    tcc_error("Illegal rel_offset %s %lld",
			      s->name, (long long)r_offset);
		എങ്കിൽ (addr >= end)
		    നിർത്തുക;
		എങ്കിൽ (addr >= start) {
		    cur_o = addr - start;
	            എങ്കിൽ (mo->bind_rebase[k].bind) {
		        എങ്കിൽ (segment->page_start[j] == DYLD_CHAINED_PTR_START_NONE)
			    segment->page_start[j] = cur_o;
		        അല്ലെങ്കിൽ {
			    bind = (ഘടന dyld_chained_ptr_64_bind *) last;
			    bind->next = (cur_o - last_o) / 4;
		        }
		        bind = (ഘടന dyld_chained_ptr_64_bind *)
				    (s->data + r_offset);
		        last = bind;
		        last_o = cur_o;
		        bind->ordinal = bind_index;
		        bind->addend = 0;
		        bind->reserved = 0;
		        bind->next = 0;
		        bind->bind = 1;
		    }
		    അല്ലെങ്കിൽ {
		        എങ്കിൽ (segment->page_start[j] == DYLD_CHAINED_PTR_START_NONE)
			    segment->page_start[j] = cur_o;
		        അല്ലെങ്കിൽ {
			    rebase = (ഘടന dyld_chained_ptr_64_rebase *) last;
			    rebase->next = (cur_o - last_o) / 4;
		        }
		        rebase = (ഘടന dyld_chained_ptr_64_rebase *)
				    (s->data + r_offset);
		        last = rebase;
		        last_o = cur_o;
		        cur = (*(uint64_t *) (s->data + r_offset)) -
			      PTR_64_OFFSET;
		        rebase->target = cur & PTR_64_MASK;
		        rebase->high8 = cur >> (64 - 8);
			എങ്കിൽ (cur != ((uint64_t)rebase->high8 << (64 - 8)) + rebase->target)
			    tcc_error("rebase error");
		        rebase->reserved = 0;
		        rebase->next = 0;
		        rebase->bind = 0;
		    }
		}
		bind_index += mo->bind_rebase[k].bind;
	    }
	}
    }
    // add imports
    header->imports_offset = data - mo->chained_fixups->data;
    import = (ഘടന dyld_chained_import *) data;
    data += mo->n_bind * വലുപ്പം (ഘടന dyld_chained_import);
    header->symbols_offset = data - mo->chained_fixups->data;
    data++;
    വേണ്ടി (i = 0, bind_index = 0; i < mo->n_bind_rebase; i++) {
	എങ്കിൽ (mo->bind_rebase[i].bind) {
	    import[bind_index].lib_ordinal =
		BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xffu;
	    import[bind_index].name_offset =
		(data - mo->chained_fixups->data) - header->symbols_offset;
	    sym_index = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	    import[bind_index].weak_import =
		ELFW(ST_BIND)(sym->st_info) == STB_WEAK;
	    name = (അക്ഷരം *) symtab_section->link->data + sym->st_name;
            strcpy((അക്ഷരം *) data, name);
	    data += strlen(name) + 1;
	    bind_index++;
	}
    }
    tcc_free(mo->bind_rebase);
}
#endif

ST_FUNC പൂർണ്ണസംഖ്യ macho_output_file(TCCState *s1, സ്ഥിരം അക്ഷരം *filename)
{
    പൂർണ്ണസംഖ്യ fd, mode, file_type;
    FILE *fp;
    പൂർണ്ണസംഖ്യ i, ret = -1;
    ഘടന macho mo;

    (ശൂന്യം)memset(&mo, 0, വലുപ്പം(mo));

    file_type = s1->output_type;
    എങ്കിൽ (file_type == TCC_OUTPUT_OBJ)
        mode = 0666;
    അല്ലെങ്കിൽ
        mode = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_ദ്വിമാന_2, mode);
    എങ്കിൽ (fd < 0 || (fp = fdopen(fd, "wb")) == ശൂന്യ) {
        tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
        തിരികെ -1;
    }
    tcc_add_runtime(s1);
    tcc_macho_add_destructor(s1);
    resolve_common_syms(s1);
    create_symtab(s1, &mo);
    check_relocs(s1, &mo);
    ret = check_symbols(s1, &mo);
    എങ്കിൽ (!ret) {
	പൂർണ്ണസംഖ്യ save_output = s1->output_type;

        collect_sections(s1, &mo, filename);
        relocate_syms(s1, s1->symtab, 0);
	എങ്കിൽ (s1->output_type == TCC_OUTPUT_EXE)
            mo.ep->entryoff = get_sym_addr(s1, "main", 1, 1)
                            -     get_segment(&mo, 1)->vmaddr;
        എങ്കിൽ (s1->nb_errors)
          പോകുക do_ret;
	// Macho uses bind/rebase instead of dynsym
	s1->output_type = TCC_OUTPUT_EXE;
        relocate_sections(s1);
	s1->output_type = save_output;
#ifdef CONFIG_NEW_MACHO
	bind_rebase_import(s1, &mo);
#endif
        convert_symbols(s1, &mo);
        എങ്കിൽ (s1->verbose)
            printf("<- %s\n", filename);
        macho_write(s1, &mo, fp);
    }

 do_ret:
    വേണ്ടി (i = 0; i < mo.nlc; i++)
      tcc_free(mo.lc[i]);
    tcc_free(mo.seg2lc);
    tcc_free(mo.lc);
    tcc_free(mo.elfsectomacho);
    tcc_free(mo.e2msym);

    fclose(fp);
#ifdef CONFIG_CODESIGN
    എങ്കിൽ (!ret) {
	അക്ഷരം command[1024];
	പൂർണ്ണസംഖ്യ retval;

	snprintf(command, വലുപ്പം(command), "codesign -f -s - %s", filename);
	retval = system (command);
	എങ്കിൽ (retval == -1 || !(WIFEXITED(retval) && WEXITSTATUS(retval) == 0))
	    tcc_error ("command failed '%s'", command);
    }
#endif
    തിരികെ ret;
}

സ്ഥിതം uint32_t macho_swap32(uint32_t x)
{
  തിരികെ (x >> 24) | (x << 24) | ((x >> 8) & 0xff00) | ((x & 0xff00) << 8);
}
#define SWAP(x) (swap ? macho_swap32(x) : (x))
#define tbd_parse_movepast(s) \
    (pos = (pos = strstr(pos, s)) ? pos + strlen(s) : ശൂന്യ)
#define tbd_parse_movetoany(cs) (pos = strpbrk(pos, cs))
#define tbd_parse_skipws ആകുമ്പോൾ (*pos && (*pos==' '||*pos=='\n')) ++pos
#define tbd_parse_tramplequote എങ്കിൽ(*pos=='\''||*pos=='"') tbd_parse_trample
#define tbd_parse_tramplespace എങ്കിൽ(*pos==' ') tbd_parse_trample
#define tbd_parse_trample *pos++=0

#ifdef TCC_IS_NATIVE
/* Looks for the active developer SDK set by xcode-select (or the default
   one set during installation.) */
ST_FUNC ശൂന്യം tcc_add_macos_sdkpath(TCCState* s)
{
    അക്ഷരം *sdkroot = ശൂന്യ, *pos = ശൂന്യ;
    ശൂന്യം* xcs = dlopen("libxcselect.dylib", RTLD_GLOBAL | RTLD_LAZY);
    CString path;
    പൂർണ്ണസംഖ്യ (*f)(unsigned പൂർണ്ണസംഖ്യ, അക്ഷരം**) = dlsym(xcs, "xcselect_host_sdk_path");
    cstr_new(&path);
    എങ്കിൽ (f) f(1, &sdkroot);
    എങ്കിൽ (sdkroot)
        pos = strstr(sdkroot,"SDKs/MacOSX");
    എങ്കിൽ (pos)
        cstr_printf(&path, "%.*s.sdk/usr/lib", (പൂർണ്ണസംഖ്യ)(pos - sdkroot + 11), sdkroot);
    /* must use free from libc directly */
#pragma തള്ളുക_macro("free")
#undef സ്വതന്ത്രം
    സ്വതന്ത്രം(sdkroot);
#pragma എടുക്കുക_macro("free")
    എങ്കിൽ (path.size)
        tcc_add_library_path(s, (അക്ഷരം*)path.data);
    അല്ലെങ്കിൽ
        tcc_add_library_path(s,
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib"
            ":" "/Applications/Xcode.app/Developer/SDKs/MacOSX.sdk/usr/lib"
            );
    cstr_free(&path);
}

ST_FUNC അക്ഷരം* macho_tbd_soname(പൂർണ്ണസംഖ്യ fd) {
    അക്ഷരം *soname, *data, *pos;
    അക്ഷരം *ret = 0;
    pos = data = tcc_load_text(fd);
    എങ്കിൽ (!tbd_parse_movepast("install-name: ")) പോകുക the_end;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    എങ്കിൽ (!tbd_parse_movetoany("\n \"'")) പോകുക the_end;
    tbd_parse_trample;
    ret = tcc_strdup(soname);
the_end:
    tcc_free(data);
    തിരികെ ret;
}
#endif /* TCC_IS_NATIVE */

ST_FUNC പൂർണ്ണസംഖ്യ macho_load_tbd(TCCState* s1, പൂർണ്ണസംഖ്യ fd, സ്ഥിരം അക്ഷരം* filename, പൂർണ്ണസംഖ്യ lev)
{
    അക്ഷരം *soname, *data, *pos;
    പൂർണ്ണസംഖ്യ ret = -1;

    pos = data = tcc_load_text(fd);
    എങ്കിൽ (!tbd_parse_movepast("install-name: ")) പോകുക the_end;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    എങ്കിൽ (!tbd_parse_movetoany("\n \"'")) പോകുക the_end;
    tbd_parse_trample;
    ret = 0;
    എങ്കിൽ (tcc_add_dllref(s1, soname, lev)->found)
        പോകുക the_end;
    ആകുമ്പോൾ(pos) {
        അക്ഷരം* sym = ശൂന്യ;
        പൂർണ്ണസംഖ്യ cont = 1;
        എങ്കിൽ (!tbd_parse_movepast("symbols: ")) നിർത്തുക;
        എങ്കിൽ (!tbd_parse_movepast("[")) നിർത്തുക;
        ആകുമ്പോൾ (cont) {
            tbd_parse_skipws;
            tbd_parse_tramplequote;
            sym = pos;
            എങ്കിൽ (!tbd_parse_movetoany(",] \"'")) നിർത്തുക;
            tbd_parse_tramplequote;
            tbd_parse_tramplespace;
            tbd_parse_skipws;
            എങ്കിൽ (*pos==0||*pos==']') cont=0;
            tbd_parse_trample;
            set_elf_sym(s1->dynsymtab_section, 0, 0,
                ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0, SHN_UNDEF, sym);
        }
    }

the_end:
    tcc_free(data);
    തിരികെ ret;
}

ST_FUNC പൂർണ്ണസംഖ്യ macho_load_dll(TCCState * s1, പൂർണ്ണസംഖ്യ fd, സ്ഥിരം അക്ഷരം* filename, പൂർണ്ണസംഖ്യ lev)
{
    unsigned അക്ഷരം buf[വലുപ്പം(ഘടന mach_header_64)];
    ശൂന്യം *buf2;
    uint32_t machofs = 0;
    ഘടന fat_header fh;
    ഘടന mach_header mh;
    ഘടന load_command *lc;
    പൂർണ്ണസംഖ്യ i, swap = 0;
    സ്ഥിരം അക്ഷരം *soname = filename;
    ഘടന nlist_64 *symtab = 0;
    uint32_t nsyms = 0;
    അക്ഷരം *strtab = 0;
    uint32_t strsize = 0;
    uint32_t iextdef = 0;
    uint32_t nextdef = 0;

  again:
    എങ്കിൽ (full_read(fd, buf, വലുപ്പം(buf)) != വലുപ്പം(buf))
      തിരികെ -1;
    memcpy(&fh, buf, വലുപ്പം(fh));
    എങ്കിൽ (fh.magic == FAT_MAGIC || fh.magic == FAT_CIGAM) {
        ഘടന fat_arch *fa = load_data(fd, വലുപ്പം(fh),
                                        fh.nfat_arch * വലുപ്പം(*fa));
        swap = fh.magic == FAT_CIGAM;
        വേണ്ടി (i = 0; i < SWAP(fh.nfat_arch); i++)
#ifdef TCC_TARGET_X86_64
          എങ്കിൽ (SWAP(fa[i].cputype) == CPU_TYPE_X86_64
              && SWAP(fa[i].cpusubtype) == CPU_SUBTYPE_X86_ALL)
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
          എങ്കിൽ (SWAP(fa[i].cputype) == CPU_TYPE_ARM64
              && SWAP(fa[i].cpusubtype) == CPU_SUBTYPE_ARM64_ALL)
#endif
            നിർത്തുക;
        എങ്കിൽ (i == SWAP(fh.nfat_arch)) {
            tcc_free(fa);
            തിരികെ -1;
        }
        machofs = SWAP(fa[i].offset);
        tcc_free(fa);
        lseek(fd, machofs, SEEK_SET);
        പോകുക again;
    } അല്ലെങ്കിൽ എങ്കിൽ (fh.magic == FAT_MAGIC_64 || fh.magic == FAT_CIGAM_64) {
        tcc_warning("%s: Mach-O fat 64bit files of type 0x%x not handled",
                    filename, fh.magic);
        തിരികെ -1;
    }

    memcpy(&mh, buf, വലുപ്പം(mh));
    എങ്കിൽ (mh.magic != MH_MAGIC_64)
      തിരികെ -1;
    dprintf("found Mach-O at %d\n", machofs);
    buf2 = load_data(fd, machofs + വലുപ്പം(ഘടന mach_header_64), mh.sizeofcmds);
    വേണ്ടി (i = 0, lc = buf2; i < mh.ncmds; i++) {
        dprintf("lc %2d: 0x%08x\n", i, lc->cmd);
        തിരഞ്ഞെടുപ്പ് (lc->cmd) {
        അവസ്ഥ LC_SYMTAB:
        {
            ഘടന symtab_command *sc = (ഘടന symtab_command*)lc;
            nsyms = sc->nsyms;
            symtab = load_data(fd, machofs + sc->symoff, nsyms * വലുപ്പം(*symtab));
            strsize = sc->strsize;
            strtab = load_data(fd, machofs + sc->stroff, strsize);
            നിർത്തുക;
        }
        അവസ്ഥ LC_ID_DYLIB:
        {
            ഘടന dylib_command *dc = (ഘടന dylib_command*)lc;
            soname = (അക്ഷരം*)lc + dc->name;
            dprintf(" ID_DYLIB %d 0x%x 0x%x %s\n",
                    dc->timestamp, dc->current_version,
                    dc->compatibility_version, soname);
            നിർത്തുക;
        }
        അവസ്ഥ LC_REEXPORT_DYLIB:
        {
            ഘടന dylib_command *dc = (ഘടന dylib_command*)lc;
            അക്ഷരം *name = (അക്ഷരം*)lc + dc->name;
            പൂർണ്ണസംഖ്യ subfd = open(name, O_RDONLY | O_ദ്വിമാന_2);
            dprintf(" REEXPORT %s\n", name);
            എങ്കിൽ (subfd < 0)
              tcc_warning("can't open %s (reexported from %s)", name, filename);
            അല്ലെങ്കിൽ {
                /* Hopefully the REEXPORTs never form a cycle, we don't check
                   for that!  */
                macho_load_dll(s1, subfd, name, lev + 1);
                close(subfd);
            }
            നിർത്തുക;
        }
        അവസ്ഥ LC_DYSYMTAB:
        {
            ഘടന dysymtab_command *dc = (ഘടന dysymtab_command*)lc;
            iextdef = dc->iextdefsym;
            nextdef = dc->nextdefsym;
            നിർത്തുക;
        }
        }
        lc = (ഘടന load_command*) ((അക്ഷരം*)lc + lc->cmdsize);
    }

    എങ്കിൽ (tcc_add_dllref(s1, soname, lev)->found)
        പോകുക the_end;

    എങ്കിൽ (!nsyms || !nextdef)
      tcc_warning("%s doesn't export any symbols?", filename);

    //dprintf("symbols (all):\n");
    dprintf("symbols (exported):\n");
    dprintf("    n: typ sec   desc              value name\n");
    //for (i = 0; i < nsyms; i++) {
    വേണ്ടി (i = iextdef; i < iextdef + nextdef; i++) {
        ഘടന nlist_64 *sym = symtab + i;
        dprintf("%5d: %3d %3d 0x%04x 0x%016lx %s\n",
                i, sym->n_type, sym->n_sect, sym->n_desc, (long)sym->n_മൂല്യം,
                strtab + sym->n_strx);
        set_elf_sym(s1->dynsymtab_section, 0, 0,
                    ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
                    0, SHN_UNDEF, strtab + sym->n_strx);
    }

  the_end:
    tcc_free(strtab);
    tcc_free(symtab);
    tcc_free(buf2);
    തിരികെ 0;
}
