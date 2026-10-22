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
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

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

#ਜੇ !defined TCC_ਨਿਸ਼ਾਨਾ_X86_64 && !defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
#ਗਲਤੀ Platform not supported
#ਜੇ_ਅੰਤ

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ _tcc_error

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEBUG_MACHO 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dprintf ਜੇ (DEBUG_MACHO) ਲਿਖੋ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MH_EXECUTE              (0x2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MH_DYLDLINK             (0x4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MH_DYLIB                (0x6)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MH_PIE                  (0x200000)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CPU_SUBTYPE_LIB64       (0x80000000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CPU_SUBTYPE_X86_ALL     (3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CPU_SUBTYPE_ARM64_ALL   (0)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CPU_ARCH_ABI64          (0x01000000)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CPU_TYPE_X86            (7)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CPU_TYPE_X86_64         (CPU_TYPE_X86 | CPU_ARCH_ABI64)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CPU_TYPE_ARM            (12)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CPU_TYPE_ARM64          (CPU_TYPE_ARM | CPU_ARCH_ABI64)

ਬਣਤਰ fat_ਸਿਰਲੇਖ {
    uint32_t        magic;          /* FAT_MAGIC or FAT_MAGIC_64 */
    uint32_t        nfat_arch;      /* number of structs that follow */
};

ਬਣਤਰ fat_arch {
    ਪੂਰਨ             cputype;        /* cpu specifier (int) */
    ਪੂਰਨ             cpusubtype;     /* machine specifier (int) */
    uint32_t        ਵਿੱਥ;         /* file offset to this object file */
    uint32_t        ਮਾਪ;           /* size of this object file */
    uint32_t        align;          /* alignment as a power of 2 */
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FAT_MAGIC       0xcafebabe
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FAT_CIGAM       0xbebafeca
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FAT_MAGIC_64    0xcafebabf
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FAT_CIGAM_64    0xbfbafeca

ਬਣਤਰ mach_ਸਿਰਲੇਖ {
    uint32_t        magic;          /* mach magic number identifier */
    ਪੂਰਨ             cputype;        /* cpu specifier */
    ਪੂਰਨ             cpusubtype;     /* machine specifier */
    uint32_t        filetype;       /* type of file */
    uint32_t        ncmds;          /* number of load commands */
    uint32_t        sizeofcmds;     /* the size of all the load commands */
    uint32_t        flags;          /* flags */
};

ਬਣਤਰ mach_ਸਿਰਲੇਖ_64 {
    ਬਣਤਰ mach_ਸਿਰਲੇਖ  mh;
    uint32_t            reserved;       /* reserved, pad to 64bit */
};

/* Constant for the magic field of the mach_header (32-bit architectures) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MH_MAGIC        0xfeedface      /* the mach magic number */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MH_CIGAM        0xcefaedfe      /* NXSwapInt(MH_MAGIC) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MH_MAGIC_64     0xfeedfacf      /* the 64-bit mach magic number */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MH_CIGAM_64     0xcffaedfe      /* NXSwapInt(MH_MAGIC_64) */

ਬਣਤਰ ਲੱਦੋ_command {
    uint32_t        cmd;            /* type of load command */
    uint32_t        cmdsize;        /* total size of command in bytes */
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_REQ_DYLD 0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_SYMTAB        0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_DYSYMTAB      0xb
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_ਲੱਦੋ_DYLIB    0xc
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_ID_DYLIB      0xd
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_ਲੱਦੋ_DYLINKER 0xe
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_SEGMENT_64    0x19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_RPATH (0x1c | LC_REQ_DYLD)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_REEXPORT_DYLIB (0x1f | LC_REQ_DYLD)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_DYLD_INFO_ONLY (0x22|LC_REQ_DYLD)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_MAIN (0x28|LC_REQ_DYLD)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_ਸਰੋਤ_ਸੰਸਕਰਣ 0x2A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_BUILD_ਸੰਸਕਰਣ 0x32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_DYLD_EXPORTS_TRIE (0x33 | LC_REQ_DYLD)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_DYLD_CHAINED_FIXUPS (0x34 | LC_REQ_DYLD)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SG_READ_ONLY    0x10 /* This segment is made read-only after fixups */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ vm_prot_t;

ਬਣਤਰ segment_command_64 { /* for 64-bit architectures */
    uint32_t        cmd;            /* LC_SEGMENT_64 */
    uint32_t        cmdsize;        /* includes sizeof section_64 structs */
    ਅੱਖਰ            segname[16];    /* segment name */
    uint64_t        vmaddr;         /* memory address of this segment */
    uint64_t        vmsize;         /* memory size of this segment */
    uint64_t        fileoff;        /* file offset of this segment */
    uint64_t        filesize;       /* amount to map from the file */
    vm_prot_t       maxprot;        /* maximum VM protection */
    vm_prot_t       initprot;       /* initial VM protection */
    uint32_t        nsects;         /* number of sections in segment */
    uint32_t        flags;          /* flags */
};

ਬਣਤਰ section_64 { /* for 64-bit architectures */
    ਅੱਖਰ            sectname[16];   /* name of this section */
    ਅੱਖਰ            segname[16];    /* segment this section goes in */
    uint64_t        addr;           /* memory address of this section */
    uint64_t        ਮਾਪ;           /* size in bytes of this section */
    uint32_t        ਵਿੱਥ;         /* file offset of this section */
    uint32_t        align;          /* section alignment (power of 2) */
    uint32_t        reloff;         /* file offset of relocation entries */
    uint32_t        nreloc;         /* number of relocation entries */
    uint32_t        flags;          /* flags (section type and attributes)*/
    uint32_t        reserved1;      /* reserved (for offset or index) */
    uint32_t        reserved2;      /* reserved (for count or sizeof) */
    uint32_t        reserved3;      /* reserved */
};

ਗਿਣਤੀ {
    DYLD_CHAINED_IMPORT          = 1,
};

ਬਣਤਰ dyld_chained_fixups_ਸਿਰਲੇਖ {
    uint32_t    fixups_ਸੰਸਕਰਣ; ///< 0
    uint32_t    starts_ਵਿੱਥ;  ///< Offset of dyld_chained_starts_in_image.
    uint32_t    imports_ਵਿੱਥ; ///< Offset of imports table in chain_data.
    uint32_t    symbols_ਵਿੱਥ; ///< Offset of symbol strings in chain_data.
    uint32_t    imports_ਗਿਣਤੀ;  ///< Number of imported symbol names.
    uint32_t    imports_format; ///< DYLD_CHAINED_IMPORT*
    uint32_t    symbols_format; ///< 0 => uncompressed, 1 => zlib compressed
};

ਬਣਤਰ dyld_chained_starts_ਵਿੱਚ_image
{
    uint32_t    seg_ਗਿਣਤੀ;
    uint32_t    seg_info_ਵਿੱਥ[1];  // each entry is offset into this struct for that segment
    // followed by pool of dyld_chain_starts_in_segment data
};

ਗਿਣਤੀ {
    DYLD_CHAINED_PTR_64                     =  2,    // target is vmaddr
    DYLD_CHAINED_PTR_64_ਵਿੱਥ              =  6,    // target is vm offset
};

ਗਿਣਤੀ {
    DYLD_CHAINED_PTR_ਸ਼ੁਰੂ_NONE   = 0xFFFF, // used in page_start[] to denote a page with no fixups
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEG_ਪੰਨਾ_ਮਾਪ 16384

ਬਣਤਰ dyld_chained_starts_ਵਿੱਚ_segment
{
    uint32_t    ਮਾਪ;               // size of this (amount kernel needs to copy)
    uint16_t    ਪੰਨਾ_ਮਾਪ;          // 0x1000 or 0x4000
    uint16_t    ਸੂਚਕ_format;     // DYLD_CHAINED_PTR_*
    uint64_t    segment_ਵਿੱਥ;     // offset in memory to start of segment
    uint32_t    max_valid_ਸੂਚਕ;  // for 32-bit OS, any value beyond this is not a pointer
    uint16_t    ਪੰਨਾ_ਗਿਣਤੀ;         // how many pages are in array
    uint16_t    ਪੰਨਾ_ਸ਼ੁਰੂ[1];      // each entry is offset in each page of first element in chain
                                    // or DYLD_CHAINED_PTR_START_NONE if no fixups on page
};

ਗਿਣਤੀ BindSpecialDylib {
  BIND_SPECIAL_DYLIB_FLAT_LOOKUP = -2,
};

ਬਣਤਰ dyld_chained_import
{
    uint32_t    lib_ordinal :  8,
                weak_import :  1,
                name_ਵਿੱਥ : 23;
};

ਬਣਤਰ dyld_chained_ptr_64_rebase
{
    uint64_t    ਨਿਸ਼ਾਨਾ    : 36,    // vmaddr, 64GB max image size
                high8     :  8,    // top 8 bits set to this after slide added
                reserved  :  7,    // all zeros
                ਅਗਲਾ      : 12,    // 4-byte stride
                bind      :  1;    // == 0
};

ਬਣਤਰ dyld_chained_ptr_64_bind
{
    uint64_t    ordinal   : 24,
                addend    :  8,   // 0 thru 255
                reserved  : 19,   // all zeros
                ਅਗਲਾ      : 12,   // 4-byte stride
                bind      :  1;   // == 1
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_REGULAR                       0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_ZEROFILL                      0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_NON_LAZY_ਚਿੰਨ੍ਹ_ਸੂਚਕ_ਸਾਰੇ      0x6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_LAZY_ਚਿੰਨ੍ਹ_ਸੂਚਕ_ਸਾਰੇ          0x7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_ਚਿੰਨ੍ਹ_STUBS                  0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_MOD_INIT_FUNC_ਸੂਚਕ_ਸਾਰੇ        0x9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_MOD_ਪਦ_FUNC_ਸੂਚਕ_ਸਾਰੇ        0xa

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_ATTR_ਸ਼ੁੱਧ_INSTRUCTIONS        0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_ATTR_SOME_INSTRUCTIONS        0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_ATTR_DEBUG             	0x02000000


ਕਿਸਮਪਰਿਭਾਸ਼ਾ uint32_t lc_str;

ਬਣਤਰ dylib_command {
    uint32_t cmd;                   /* LC_ID_DYLIB, LC_LOAD_{,WEAK_}DYLIB,
                                       LC_REEXPORT_DYLIB */
    uint32_t cmdsize;               /* includes pathname string */
    lc_str   name;                  /* library's path name */
    uint32_t timestamp;             /* library's build time stamp */
    uint32_t current_ਸੰਸਕਰਣ;       /* library's current version number */
    uint32_t compatibility_ਸੰਸਕਰਣ; /* library's compatibility vers number*/
};

ਬਣਤਰ rpath_command {
    uint32_t     cmd;           /* LC_RPATH */
    uint32_t     cmdsize;       /* includes string */
    lc_str       ਰਸਤਾ;          /* path to add to run path */
};

ਬਣਤਰ dylinker_command {
    uint32_t        cmd;            /* LC_ID_DYLINKER, LC_LOAD_DYLINKER or
                                       LC_DYLD_ENVIRONMENT */
    uint32_t        cmdsize;        /* includes pathname string */
    lc_str          name;           /* dynamic linker's path name */
};

ਬਣਤਰ linkedit_ਅੰਕੜੇ_command {
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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PLATFORM_MACOS 1

ਬਣਤਰ build_ਸੰਸਕਰਣ_command {
    uint32_t    cmd;            /* LC_BUILD_VERSION */
    uint32_t    cmdsize;        /* sizeof(struct build_version_command) plus */
                                /* ntools * sizeof(struct build_tool_version) */
    uint32_t    platform;       /* platform */
    uint32_t    minos;          /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    sdk;            /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    ntools;         /* number of tool entries following this */
};

ਬਣਤਰ ਸਰੋਤ_ਸੰਸਕਰਣ_command {
    uint32_t  cmd;      /* LC_SOURCE_VERSION */
    uint32_t  cmdsize;  /* 16 */
    uint64_t  ਸੰਸਕਰਣ;  /* A.B.C.D.E packed as a24.b10.c10.d10.e10 */
};

ਬਣਤਰ symtab_command {
    uint32_t        cmd;            /* LC_SYMTAB */
    uint32_t        cmdsize;        /* sizeof(struct symtab_command) */
    uint32_t        symoff;         /* symbol table offset */
    uint32_t        nsyms;          /* number of symbol table entries */
    uint32_t        stroff;         /* string table offset */
    uint32_t        strsize;        /* string table size in bytes */
};

ਬਣਤਰ dysymtab_command {
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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BIND_OPCODE_ਪੂਰਾ                                        0x00
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BIND_OPCODE_ਸੈੱਟ_DYLIB_SPECIAL_IMM                       0x30
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BIND_OPCODE_ਸੈੱਟ_ਚਿੰਨ੍ਹ_TRAILING_FLAGS_IMM               0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BIND_OPCODE_ਸੈੱਟ_TYPE_IMM                                0x50
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BIND_OPCODE_ਸੈੱਟ_SEGMENT_AND_ਵਿੱਥ_ULEB                 0x70
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BIND_OPCODE_DO_BIND                                     0x90

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BIND_ਚਿੰਨ੍ਹ_FLAGS_WEAK_IMPORT                           0x1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BIND_TYPE_ਸੂਚਕ                                       1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BIND_SPECIAL_DYLIB_FLAT_LOOKUP                          -2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REBASE_OPCODE_ਪੂਰਾ                                      0x00
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REBASE_OPCODE_ਸੈੱਟ_TYPE_IMM                              0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REBASE_OPCODE_ਸੈੱਟ_SEGMENT_AND_ਵਿੱਥ_ULEB               0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REBASE_OPCODE_DO_REBASE_IMM_TIMES                       0x50

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REBASE_TYPE_ਸੂਚਕ                                     1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXPORT_ਚਿੰਨ੍ਹ_FLAGS_ਕਿਸਮ_REGULAR                        0x00
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXPORT_ਚਿੰਨ੍ਹ_FLAGS_ਕਿਸਮ_ABSOLUTE                       0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXPORT_ਚਿੰਨ੍ਹ_FLAGS_WEAK_DEFINITION                     0x04

ਬਣਤਰ dyld_info_command {
    uint32_t cmd;             /* LC_DYLD_INFO or LC_DYLD_INFO_ONLY */
    uint32_t cmdsize;         /* sizeof(struct dyld_info_command) */
    uint32_t rebase_off;      /* file offset to rebase info  */
    uint32_t rebase_ਮਾਪ;     /* size of rebase info   */
    uint32_t bind_off;        /* file offset to binding info   */
    uint32_t bind_ਮਾਪ;       /* size of binding info  */
    uint32_t weak_bind_off;   /* file offset to weak binding info   */
    uint32_t weak_bind_ਮਾਪ;  /* size of weak binding info  */
    uint32_t lazy_bind_off;   /* file offset to lazy binding info */
    uint32_t lazy_bind_ਮਾਪ;  /* size of lazy binding infs */
    uint32_t export_off;      /* file offset to lazy binding info */
    uint32_t export_ਮਾਪ;     /* size of lazy binding infs */
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਅਸਿੱਧਾ_ਚਿੰਨ੍ਹ_LOCAL   0x80000000

ਬਣਤਰ ਇੰਦਰਾਜ_ਬਿੰਦੂ_command {
    uint32_t  cmd;      /* LC_MAIN only used in MH_EXECUTE filetypes */
    uint32_t  cmdsize;  /* 24 */
    uint64_t  entryoff; /* file (__TEXT) offset of main() */
    uint64_t  stacksize;/* if not zero, initial stack size */
};

ਗਿਣਤੀ skind {
    sk_unknown = 0,
    sk_discard,
    sk_ਪਾਠ,
    sk_stubs,
    sk_stub_helper,
    sk_ro_ਅੰਕੜੇ,
    sk_uw_info,
    sk_nl_ptr,  // non-lazy pointers, aka GOT
    sk_debug_info,
    sk_debug_abbrev,
    sk_debug_ਸਤਰ,
    sk_debug_aranges,
    sk_debug_str,
    sk_debug_ਸਤਰ_str,
    sk_stab,
    sk_stab_str,
    sk_la_ptr,  // lazy pointers
    sk_init,
    sk_fini,
    sk_rw_ਅੰਕੜੇ,
    sk_bss,
    sk_linkedit,
    sk_ਆਖਰੀ
};

ਬਣਤਰ nlist_64 {
    uint32_t  n_strx;      /* index into the string table */
    uint8_t n_type;        /* type flag, see below */
    uint8_t n_sect;        /* section number or NO_SECT */
    uint16_t n_desc;       /* see <mach-o/stab.h> */
    uint64_t n_ਮੁੱਲ;      /* value of this symbol (or stab offset) */
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N_UNDF  0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N_ABS   0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N_EXT   0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N_SECT  0xe

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N_WEAK_REF      0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N_WEAK_DEF      0x0080

ਬਣਤਰ macho {
    ਬਣਤਰ mach_ਸਿਰਲੇਖ_64 mh;
    ਪੂਰਨ *seg2lc, nseg;
    ਬਣਤਰ ਲੱਦੋ_command **lc;
    ਬਣਤਰ ਇੰਦਰਾਜ_ਬਿੰਦੂ_command *ep;
    ਪੂਰਨ nlc;
    ਬਣਤਰ {
        Section *s;
        ਪੂਰਨ machosect;
    } sk_ਮੰਜ਼ਿਲ_sect[sk_ਆਖਰੀ];
    ਪੂਰਨ *elfsectomacho;
    ਪੂਰਨ *e2msym;
    Section *symtab, *strtab, *indirsyms, *stubs, *exports;
    uint32_t ilocal, iextdef, iundef;
    ਪੂਰਨ stubsym, n_got, nr_plt;
    ਪੂਰਨ segment[sk_ਆਖਰੀ];
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_NEW_MACHO
    Section *chained_fixups;
    ਪੂਰਨ n_bind;
    ਪੂਰਨ n_bind_rebase;
    ਬਣਤਰ bind_rebase {
	ਪੂਰਨ section;
	ਪੂਰਨ bind;
	ElfW_Rel rel;
    } *bind_rebase;
#ਨਹੀਂਤਾਂ
    Section *rebase, *binding, *weak_binding, *lazy_binding;
    Section *stub_helper, *la_ਚਿੰਨ੍ਹ_ptr;
    ਬਣਤਰ dyld_info_command *dyldinfo;
    ਪੂਰਨ helpsym, lasym, dyld_ਨਿੱਜੀ, dyld_stub_binder;
    ਪੂਰਨ n_lazy_bind;    
    ਬਣਤਰ s_lazy_bind {
        ਪੂਰਨ section;
        ਪੂਰਨ bind_ਵਿੱਥ;
        ਪੂਰਨ la_ਚਿੰਨ੍ਹ_ਵਿੱਥ;
        ElfW_Rel rel;
    } *s_lazy_bind;
    ਪੂਰਨ n_rebase;    
    ਬਣਤਰ s_rebase {
        ਪੂਰਨ section;
        ElfW_Rel rel;
    } *s_rebase;
    ਪੂਰਨ n_bind; 
    ਬਣਤਰ bind {
        ਪੂਰਨ section;
        ElfW_Rel rel;
    } *bind;
#ਜੇ_ਅੰਤ
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHT_LINKEDIT (SHT_LOOS + 42)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHN_FROMDLL  (SHN_LOOS + 2)  /* Symbol is undefined, comes from a DLL */

ਸਥਿਰ ਖਾਲੀ * ਜੋੜੋ_lc(ਬਣਤਰ macho *mo, uint32_t cmd, uint32_t cmdsize)
{
    ਬਣਤਰ ਲੱਦੋ_command *lc = tcc_mallocz(cmdsize);
    lc->cmd = cmd;
    lc->cmdsize = cmdsize;
    mo->lc = tcc_realloc(mo->lc, ਆਕਾਰ(mo->lc[0]) * (mo->nlc + 1));
    mo->lc[mo->nlc++] = lc;
    ਵਾਪਸ lc;
}

ਸਥਿਰ ਬਣਤਰ segment_command_64 * ਜੋੜੋ_segment(ਬਣਤਰ macho *mo, ਅਚਲ ਅੱਖਰ *name)
{
    ਬਣਤਰ segment_command_64 *sc = ਜੋੜੋ_lc(mo, LC_SEGMENT_64, ਆਕਾਰ(*sc));
    strncpy(sc->segname, name, 16);
    mo->seg2lc = tcc_realloc(mo->seg2lc, ਆਕਾਰ(*mo->seg2lc) * (mo->nseg + 1));
    mo->seg2lc[mo->nseg++] = mo->nlc - 1;
    ਵਾਪਸ sc;
}

ਸਥਿਰ ਬਣਤਰ segment_command_64 * get_segment(ਬਣਤਰ macho *mo, ਪੂਰਨ i)
{
    ਵਾਪਸ (ਬਣਤਰ segment_command_64 *) (mo->lc[mo->seg2lc[i]]);
}

ਸਥਿਰ ਪੂਰਨ ਜੋੜੋ_section(ਬਣਤਰ macho *mo, ਬਣਤਰ segment_command_64 **_seg, ਅਚਲ ਅੱਖਰ *name)
{
    ਬਣਤਰ segment_command_64 *seg = *_seg;
    ਪੂਰਨ ret = seg->nsects;
    ਬਣਤਰ section_64 *sec;
    seg->nsects++;
    seg->cmdsize += ਆਕਾਰ(*sec);
    seg = tcc_realloc(seg, ਆਕਾਰ(*seg) + seg->nsects * ਆਕਾਰ(*sec));
    sec = (ਬਣਤਰ section_64*)((ਅੱਖਰ*)seg + ਆਕਾਰ(*seg)) + ret;
    memset(sec, 0, ਆਕਾਰ(*sec));
    strncpy(sec->sectname, name, 16);
    strncpy(sec->segname, seg->segname, 16);
    *_seg = seg;
    ਵਾਪਸ ret;
}

ਸਥਿਰ ਬਣਤਰ section_64 *get_section(ਬਣਤਰ segment_command_64 *seg, ਪੂਰਨ i)
{
    ਵਾਪਸ (ਬਣਤਰ section_64*)((ਅੱਖਰ*)seg + ਆਕਾਰ(*seg)) + i;
}

ਸਥਿਰ ਖਾਲੀ * ਜੋੜੋ_dylib(ਬਣਤਰ macho *mo, ਅੱਖਰ *name)
{
    ਬਣਤਰ dylib_command *lc;
    ਪੂਰਨ sz = (ਆਕਾਰ(*lc) + ਲੜੀ_ਲੰਬਾਈ(name) + 1 + 7) & -8;
    lc = ਜੋੜੋ_lc(mo, LC_ਲੱਦੋ_DYLIB, sz);
    lc->name = ਆਕਾਰ(*lc);
    strcpy((ਅੱਖਰ*)lc + lc->name, name);
    lc->timestamp = 2;
    lc->current_ਸੰਸਕਰਣ = 1 << 16;
    lc->compatibility_ਸੰਸਕਰਣ = 1 << 16;
    ਵਾਪਸ lc;
}

ਸਥਿਰ ਪੂਰਨ uleb128_ਮਾਪ (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਮੁੱਲ)
{
    ਪੂਰਨ ਮਾਪ =  0;

    ਕਰੋ {
        ਮੁੱਲ >>= 7;
        ਮਾਪ++;
    } ਜਦੋਂ (ਮੁੱਲ != 0);
    ਵਾਪਸ ਮਾਪ;
}

ਸਥਿਰ ਖਾਲੀ write_uleb128(Section *section, uint64_t ਮੁੱਲ)
{
    ਕਰੋ {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ byte = ਮੁੱਲ & 0x7f;
	uint8_t *ptr = section_ptr_ਜੋੜੋ(section, 1);

        ਮੁੱਲ >>= 7;
        *ptr = byte | (ਮੁੱਲ ? 0x80 : 0);
    } ਜਦੋਂ (ਮੁੱਲ != 0);
}

ਸਥਿਰ ਖਾਲੀ tcc_macho_ਜੋੜੋ_destructor(TCCState *s1)
{
    ਪੂਰਨ init_sym, mh_execute_ਸਿਰਲੇਖ, at_exit_sym;
    Section *s;
    ElfW_Rel *rel;
    uint8_t *ptr;

    mh_execute_ਸਿਰਲੇਖ = put_elf_sym(s1->symtab, -4096, 0,
				    ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				    ਪਾਠ_section->sh_ਅੰਕ, "__mh_execute_header");
    s = ਲੱਭੋ_section(s1, ".fini_array");
    ਜੇ (s->ਅੰਕੜੇ_ਵਿੱਥ == 0)
        ਵਾਪਸ; 
    init_sym = put_elf_sym(s1->symtab, ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ, 0,
                           ELFW(ST_INFO)(STB_LOCAL, STT_FUNC), 0,
                           ਪਾਠ_section->sh_ਅੰਕ, "___GLOBAL_init_65535");
    at_exit_sym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0,
                              SHN_UNDEF, "___cxa_atexit");
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    ptr = section_ptr_ਜੋੜੋ(ਪਾਠ_section, 4);
    ptr[0] = 0x55;  // pushq   %rbp
    ptr[1] = 0x48;  // movq    %rsp, %rbp
    ptr[2] = 0x89;
    ptr[3] = 0xe5;
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        ਪੂਰਨ sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_ਜੋੜੋ(ਪਾਠ_section, 26);
        ptr[0] = 0x48;  // lea destructor(%rip),%rax
        ptr[1] = 0x8d;
        ptr[2] = 0x05;
        put_elf_reloca(s1->symtab, ਪਾਠ_section, 
		       ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ - 23,
		       R_X86_64_PC32, sym_ਸੂਚਕਾਂਕ, -4);
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
        put_elf_reloca(s1->symtab, ਪਾਠ_section,
		       ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ - 9,
		       R_X86_64_PC32, mh_execute_ਸਿਰਲੇਖ, -4);
	ptr[21] = 0xe8; // call __cxa_atexit
        put_elf_reloca(s1->symtab, ਪਾਠ_section,
		       ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ - 4,
		       R_X86_64_PLT32, at_exit_sym, -4);
    }
    ptr = section_ptr_ਜੋੜੋ(ਪਾਠ_section, 2);
    ptr[0] = 0x5d;  // pop   %rbp
    ptr[1] = 0xc3;  // ret
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
    ptr = section_ptr_ਜੋੜੋ(ਪਾਠ_section, 8);
    write32le(ptr, 0xa9bf7bfd);     // stp     x29, x30, [sp, #-16]!
    write32le(ptr + 4, 0x910003fd); // mov     x29, sp
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        ਪੂਰਨ sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_ਜੋੜੋ(ਪਾਠ_section, 24);
        put_elf_reloc(s1->symtab, ਪਾਠ_section, 
		      ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ - 24,
		      R_AARCH64_ADR_PREL_PG_HI21, sym_ਸੂਚਕਾਂਕ);
        write32le(ptr, 0x90000000);      // adrp x0, destructor@page
        put_elf_reloc(s1->symtab, ਪਾਠ_section,
		      ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ - 20,
		      R_AARCH64_LDST8_ABS_LO12_NC, sym_ਸੂਚਕਾਂਕ);
        write32le(ptr + 4, 0x91000000);  // add x0,x0,destructor@pageoff
        write32le(ptr + 8, 0xd2800001);  // mov x1, #0
        put_elf_reloc(s1->symtab, ਪਾਠ_section, 
		      ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ - 12,
		      R_AARCH64_ADR_PREL_PG_HI21, mh_execute_ਸਿਰਲੇਖ);
        write32le(ptr + 12, 0x90000002);      // adrp x2, mh_execute_header@page
        put_elf_reloc(s1->symtab, ਪਾਠ_section,
		      ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ - 8,
		      R_AARCH64_LDST8_ABS_LO12_NC, mh_execute_ਸਿਰਲੇਖ);
        write32le(ptr + 16, 0x91000042);  // add x2,x2,mh_execute_header@pageoff
        put_elf_reloc(s1->symtab, ਪਾਠ_section,
		      ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ - 4,
		      R_AARCH64_CALL26, at_exit_sym);
	write32le(ptr + 20, 0x94000000); // bl __cxa_atexit
    }
    ptr = section_ptr_ਜੋੜੋ(ਪਾਠ_section, 8);
    write32le(ptr, 0xa8c17bfd);     // ldp     x29, x30, [sp], #16
    write32le(ptr + 4, 0xd65f03c0); // ret
#ਜੇ_ਅੰਤ
    s->reloc->ਅੰਕੜੇ_ਵਿੱਥ = s->ਅੰਕੜੇ_ਵਿੱਥ = 0;
    s->sh_flags &= ~SHF_ALLOC;
    ਜੋੜੋ_array (s1, ".init_array", init_sym);
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_NEW_MACHO
ਸਥਿਰ ਖਾਲੀ bind_rebase_ਜੋੜੋ(ਬਣਤਰ macho *mo, ਪੂਰਨ bind, ਪੂਰਨ sh_info,
			    ElfW_Rel *rel, ਬਣਤਰ sym_attr *attr)
{
    mo->bind_rebase = tcc_realloc(mo->bind_rebase, (mo->n_bind_rebase + 1) *
		                  ਆਕਾਰ(ਬਣਤਰ bind_rebase));
    mo->bind_rebase[mo->n_bind_rebase].section = sh_info;
    mo->bind_rebase[mo->n_bind_rebase].bind = bind;
    mo->bind_rebase[mo->n_bind_rebase].rel = *rel;
    ਜੇ (attr)
        mo->bind_rebase[mo->n_bind_rebase].rel.r_ਵਿੱਥ = attr->got_ਵਿੱਥ;
    mo->n_bind_rebase++;
    mo->n_bind += bind;
}

ਸਥਿਰ ਖਾਲੀ check_relocs(TCCState *s1, ਬਣਤਰ macho *mo)
{
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    ਪੂਰਨ i, j, type, gotplt_ਇੰਦਰਾਜ, sym_ਸੂਚਕਾਂਕ, for_ਕੋਡ;
    uint32_t *pi, *goti;
    ਬਣਤਰ sym_attr *attr;

    goti = ਨਿਰਾ;
    mo->nr_plt = mo->n_got = 0;
    ਲਈ (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ਜੇ (s->sh_type != SHT_RELX ||
	    !ਲੜੀ_ਤੁਲਨਾ(s1->sections[s->sh_info]->name, ".debug_", 7))
            ਜਾਰੀ;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_ਇੰਦਰਾਜ = gotplt_ਇੰਦਰਾਜ_type(type);
            for_ਕੋਡ = ਕੋਡ_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
            ਜੇ (sym->st_shndx == SHN_UNDEF
                || gotplt_ਇੰਦਰਾਜ == ALWAYS_GOTPLT_ਇੰਦਰਾਜ) {
                attr = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 1);
                ਜੇ (!attr->dyn_ਸੂਚਕਾਂਕ) {
                    attr->got_ਵਿੱਥ = s1->got->ਅੰਕੜੇ_ਵਿੱਥ;
                    attr->plt_ਵਿੱਥ = -1;
                    attr->dyn_ਸੂਚਕਾਂਕ = 1; /* used as flag */
                    section_ptr_ਜੋੜੋ(s1->got, PTR_ਮਾਪ);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_ਵਿੱਥ,
                                  R_JMP_ਥਾਂ, sym_ਸੂਚਕਾਂਕ);
	 	    goti = tcc_realloc(goti, (mo->n_got + 1) * ਆਕਾਰ(*goti));
                    ਜੇ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        ਜੇ (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name);
			goti[mo->n_got++] = ਅਸਿੱਧਾ_ਚਿੰਨ੍ਹ_LOCAL;
                    } ਨਹੀਂਤਾਂ {
                        goti[mo->n_got++] = mo->e2msym[sym_ਸੂਚਕਾਂਕ];
                        ਜੇ (sym->st_shndx == SHN_UNDEF
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
                            && type == R_X86_64_GOTPCREL
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
                            && type == R_AARCH64_ADR_GOT_ਪੰਨਾ
#ਜੇ_ਅੰਤ
                            ) {
			    attr->plt_ਵਿੱਥ = -mo->n_bind_rebase - 2;
			    bind_rebase_ਜੋੜੋ(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
			    s1->got->reloc->ਅੰਕੜੇ_ਵਿੱਥ -= ਆਕਾਰ (ElfW_Rel);
			}
		        ਜੇ (for_ਕੋਡ && sym->st_shndx == SHN_UNDEF)
			    s1->got->reloc->ਅੰਕੜੇ_ਵਿੱਥ -= ਆਕਾਰ (ElfW_Rel);
		    }
                }
                ਜੇ (for_ਕੋਡ && sym->st_shndx == SHN_UNDEF) {
		    ਜੇ ((ਪੂਰਨ)attr->plt_ਵਿੱਥ < -1) {
			/* remove above bind and replace with plt */
			mo->bind_rebase[-attr->plt_ਵਿੱਥ - 2].bind = 2;
			attr->plt_ਵਿੱਥ = -1;
		    }
                    ਜੇ (attr->plt_ਵਿੱਥ == -1) {
                        uint8_t *jmp;

                        attr->plt_ਵਿੱਥ = mo->stubs->ਅੰਕੜੇ_ਵਿੱਥ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
                        ਜੇ (type != R_X86_64_PLT32)
                             ਜਾਰੀ;
                        jmp = section_ptr_ਜੋੜੋ(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *ofs(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_ਵਿੱਥ + 2,
                                      R_X86_64_GOTPCREL, sym_ਸੂਚਕਾਂਕ);
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
                        ਜੇ (type != R_AARCH64_CALL26)
                             ਜਾਰੀ;
                        jmp = section_ptr_ਜੋੜੋ(mo->stubs, 12);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_ਵਿੱਥ,
                                      R_AARCH64_ADR_GOT_ਪੰਨਾ, sym_ਸੂਚਕਾਂਕ);
                        write32le(jmp, // adrp x16, #sym
                                  0x90000010);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_ਵਿੱਥ + 4,
                                      R_AARCH64_LD64_GOT_LO12_NC, sym_ਸੂਚਕਾਂਕ);
                        write32le(jmp + 4, // ld x16,[x16, #sym]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);
#ਜੇ_ਅੰਤ
			bind_rebase_ਜੋੜੋ(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
                        pi = section_ptr_ਜੋੜੋ(mo->indirsyms, ਆਕਾਰ(*pi));
                        *pi = mo->e2msym[sym_ਸੂਚਕਾਂਕ];
                        mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_ਵਿੱਥ;
                }
            }
	    ਜੇ (type == R_ਅੰਕੜੇ_PTR || type == R_JMP_ਥਾਂ)
		bind_rebase_ਜੋੜੋ(mo, sym->st_shndx == SHN_UNDEF ? 1 : 0,
				s->sh_info, &save_rel, ਨਿਰਾ);
        }
    }
    /* remove deleted binds */
    ਲਈ (i = 0, j = 0; i < mo->n_bind_rebase; i++)
	ਜੇ (mo->bind_rebase[i].bind == 2)
	    mo->n_bind--;
	ਨਹੀਂਤਾਂ
	    mo->bind_rebase[j++] = mo->bind_rebase[i];
    mo->n_bind_rebase = j;
    pi = section_ptr_ਜੋੜੋ(mo->indirsyms, mo->n_got * ਆਕਾਰ(*pi));
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(pi, goti, mo->n_got * ਆਕਾਰ(*pi));
    tcc_free(goti);
}

#ਨਹੀਂਤਾਂ

ਸਥਿਰ ਖਾਲੀ check_relocs(TCCState *s1, ਬਣਤਰ macho *mo)
{
    uint8_t *jmp;
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    ਪੂਰਨ i, type, gotplt_ਇੰਦਰਾਜ, sym_ਸੂਚਕਾਂਕ, for_ਕੋਡ;
    ਪੂਰਨ bind_ਵਿੱਥ, la_ਚਿੰਨ੍ਹ_ਵਿੱਥ;
    uint32_t *pi, *goti;
    ਬਣਤਰ sym_attr *attr;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    jmp = section_ptr_ਜੋੜੋ(mo->stub_helper, 16);
    jmp[0] = 0x4c;  /* leaq _dyld_private(%rip), %r11 */
    jmp[1] = 0x8d;
    jmp[2] = 0x1d;
    put_elf_reloca(s1->symtab, mo->stub_helper, 3,
		   R_X86_64_PC32, mo->dyld_ਨਿੱਜੀ, -4);
    jmp[7] = 0x41;  /* pushq %r11 */
    jmp[8] = 0x53;
    jmp[9] = 0xff;  /* jmpq    *dyld_stub_binder@GOT(%rip) */
    jmp[10] = 0x25;
    put_elf_reloca(s1->symtab, mo->stub_helper, 11,
		   R_X86_64_GOTPCREL, mo->dyld_stub_binder, -4);
    jmp[15] = 0x90; /* nop */
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
    jmp = section_ptr_ਜੋੜੋ(mo->stub_helper, 24);
    put_elf_reloc(s1->symtab, mo->stub_helper, 0,
		  R_AARCH64_ADR_PREL_PG_HI21, mo->dyld_ਨਿੱਜੀ);
    write32le(jmp, 0x90000011); // adrp x17, _dyld_private@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 4,
		  R_AARCH64_LDST64_ABS_LO12_NC, mo->dyld_ਨਿੱਜੀ);
    write32le(jmp + 4, 0x91000231); // add x17,x17,_dyld_private@pageoff
    write32le(jmp + 8, 0xa9bf47f0); // stp x16/x17, [sp, #-16]!
    put_elf_reloc(s1->symtab, mo->stub_helper, 12,
		  R_AARCH64_ADR_GOT_ਪੰਨਾ, mo->dyld_stub_binder);
    write32le(jmp + 12, 0x90000010); // adrp x16, dyld_stub_binder@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 16,
		  R_AARCH64_LD64_GOT_LO12_NC, mo->dyld_stub_binder);
    write32le(jmp + 16, 0xf9400210); // ldr x16,[x16,dyld_stub_binder@pageoff]
    write32le(jmp + 20, 0xd61f0200); // br x16
#ਜੇ_ਅੰਤ
    
    goti = ਨਿਰਾ;
    mo->nr_plt = mo->n_got = 0;
    ਲਈ (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ਜੇ (s->sh_type != SHT_RELX ||
	    !ਲੜੀ_ਤੁਲਨਾ(s1->sections[s->sh_info]->name, ".debug_", 7))
            ਜਾਰੀ;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_ਇੰਦਰਾਜ = gotplt_ਇੰਦਰਾਜ_type(type);
            for_ਕੋਡ = ਕੋਡ_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
            ਜੇ (sym->st_shndx == SHN_UNDEF
                || gotplt_ਇੰਦਰਾਜ == ALWAYS_GOTPLT_ਇੰਦਰਾਜ) {
                attr = get_sym_attr(s1, sym_ਸੂਚਕਾਂਕ, 1);
                ਜੇ (!attr->dyn_ਸੂਚਕਾਂਕ) {
                    attr->got_ਵਿੱਥ = s1->got->ਅੰਕੜੇ_ਵਿੱਥ;
                    attr->plt_ਵਿੱਥ = -1;
                    attr->dyn_ਸੂਚਕਾਂਕ = 1; /* used as flag */
		    section_ptr_ਜੋੜੋ(s1->got, PTR_ਮਾਪ);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_ਵਿੱਥ,
                                  R_JMP_ਥਾਂ, sym_ਸੂਚਕਾਂਕ);
		    goti = tcc_realloc(goti, (mo->n_got + 1) * ਆਕਾਰ(*goti));
                    ਜੇ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        ਜੇ (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name);
			goti[mo->n_got++] = ਅਸਿੱਧਾ_ਚਿੰਨ੍ਹ_LOCAL;
                    } ਨਹੀਂਤਾਂ {
			goti[mo->n_got++] = mo->e2msym[sym_ਸੂਚਕਾਂਕ];
			ਜੇ (sym->st_shndx == SHN_UNDEF
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
			    && type == R_X86_64_GOTPCREL
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
			    && type == R_AARCH64_ADR_GOT_ਪੰਨਾ
#ਜੇ_ਅੰਤ
			    ) {
			    mo->bind =
			        tcc_realloc(mo->bind,
					    (mo->n_bind + 1) *
					    ਆਕਾਰ(ਬਣਤਰ bind));
			    mo->bind[mo->n_bind].section = s1->got->reloc->sh_info;
			    mo->bind[mo->n_bind].rel = save_rel;
                            mo->bind[mo->n_bind].rel.r_ਵਿੱਥ = attr->got_ਵਿੱਥ;
			    mo->n_bind++;
			    s1->got->reloc->ਅੰਕੜੇ_ਵਿੱਥ -= ਆਕਾਰ (ElfW_Rel);
			}
		    }
                }
                ਜੇ (for_ਕੋਡ && sym->st_shndx == SHN_UNDEF) {
                    ਜੇ (attr->plt_ਵਿੱਥ == -1) {
                        attr->plt_ਵਿੱਥ = mo->stubs->ਅੰਕੜੇ_ਵਿੱਥ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
			ਜੇ (type != R_X86_64_PLT32)
			     ਜਾਰੀ;
			/* __stubs */
                        jmp = section_ptr_ਜੋੜੋ(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *__la_symbol_ptr(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->ਅੰਕੜੇ_ਵਿੱਥ - 4,
                                       R_X86_64_PC32, mo->lasym,
				       mo->la_ਚਿੰਨ੍ਹ_ptr->ਅੰਕੜੇ_ਵਿੱਥ - 4);

			/* __stub_helper */
			bind_ਵਿੱਥ = mo->stub_helper->ਅੰਕੜੇ_ਵਿੱਥ + 1;
                        jmp = section_ptr_ਜੋੜੋ(mo->stub_helper, 10);
                        jmp[0] = 0x68;  /* pushq $bind_offset */
                        jmp[5] = 0xe9;  /* jmpq __stub_helper */
                        write32le(jmp + 6, -mo->stub_helper->ਅੰਕੜੇ_ਵਿੱਥ);

			/* __la_symbol_ptr */
			la_ਚਿੰਨ੍ਹ_ਵਿੱਥ = mo->la_ਚਿੰਨ੍ਹ_ptr->ਅੰਕੜੇ_ਵਿੱਥ;
                        put_elf_reloca(s1->symtab, mo->la_ਚਿੰਨ੍ਹ_ptr,
				       mo->la_ਚਿੰਨ੍ਹ_ptr->ਅੰਕੜੇ_ਵਿੱਥ,
				       R_ਅੰਕੜੇ_PTR, mo->helpsym,
				       mo->stub_helper->ਅੰਕੜੇ_ਵਿੱਥ - 10);
			section_ptr_ਜੋੜੋ(mo->la_ਚਿੰਨ੍ਹ_ptr, PTR_ਮਾਪ);
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
			ਜੇ (type != R_AARCH64_CALL26)
			     ਜਾਰੀ;
			/* __stubs */
                        jmp = section_ptr_ਜੋੜੋ(mo->stubs, 12);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->ਅੰਕੜੇ_ਵਿੱਥ - 12,
                                       R_AARCH64_ADR_PREL_PG_HI21, mo->lasym,
				       mo->la_ਚਿੰਨ੍ਹ_ptr->ਅੰਕੜੇ_ਵਿੱਥ);
                        write32le(jmp, // adrp x16, __la_symbol_ptr@page
                                  0x90000010);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->ਅੰਕੜੇ_ਵਿੱਥ - 8,
                                       R_AARCH64_LDST64_ABS_LO12_NC, mo->lasym,
				       mo->la_ਚਿੰਨ੍ਹ_ptr->ਅੰਕੜੇ_ਵਿੱਥ);
                        write32le(jmp + 4, // ldr x16,[x16, __la_symbol_ptr@pageoff]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);

			/* __stub_helper */
			bind_ਵਿੱਥ = mo->stub_helper->ਅੰਕੜੇ_ਵਿੱਥ + 8;
                        jmp = section_ptr_ਜੋੜੋ(mo->stub_helper, 12);
                        write32le(jmp + 0, // ldr  w16, l0
                                  0x18000050);
                        write32le(jmp + 4, // b stubHelperHeader
                                  0x14000000 +
				  ((-(mo->stub_helper->ਅੰਕੜੇ_ਵਿੱਥ - 8) / 4) &
				   0x3ffffff));
                        write32le(jmp + 8, 0); // l0: .long bind_offset

			/* __la_symbol_ptr */
			la_ਚਿੰਨ੍ਹ_ਵਿੱਥ = mo->la_ਚਿੰਨ੍ਹ_ptr->ਅੰਕੜੇ_ਵਿੱਥ;
                        put_elf_reloca(s1->symtab, mo->la_ਚਿੰਨ੍ਹ_ptr,
				       mo->la_ਚਿੰਨ੍ਹ_ptr->ਅੰਕੜੇ_ਵਿੱਥ,
				       R_ਅੰਕੜੇ_PTR, mo->helpsym,
				       mo->stub_helper->ਅੰਕੜੇ_ਵਿੱਥ - 12);
			section_ptr_ਜੋੜੋ(mo->la_ਚਿੰਨ੍ਹ_ptr, PTR_ਮਾਪ);
#ਜੇ_ਅੰਤ
                        mo->s_lazy_bind =
                            tcc_realloc(mo->s_lazy_bind, (mo->n_lazy_bind + 1) *
                                        ਆਕਾਰ(ਬਣਤਰ s_lazy_bind));
                        mo->s_lazy_bind[mo->n_lazy_bind].section =
                            mo->stub_helper->reloc->sh_info;
                        mo->s_lazy_bind[mo->n_lazy_bind].bind_ਵਿੱਥ =
			    bind_ਵਿੱਥ;
                        mo->s_lazy_bind[mo->n_lazy_bind].la_ਚਿੰਨ੍ਹ_ਵਿੱਥ =
			    la_ਚਿੰਨ੍ਹ_ਵਿੱਥ;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel = save_rel;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel.r_ਵਿੱਥ =
                            attr->plt_ਵਿੱਥ;
                        mo->n_lazy_bind++;
			pi = section_ptr_ਜੋੜੋ(mo->indirsyms, ਆਕਾਰ(*pi));
			*pi = mo->e2msym[sym_ਸੂਚਕਾਂਕ];
			mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_ਵਿੱਥ;
                }
            }
            ਜੇ (type == R_ਅੰਕੜੇ_PTR || type == R_JMP_ਥਾਂ) {
		ਜੇ (sym->st_shndx == SHN_UNDEF) {
		    mo->bind = tcc_realloc(mo->bind,
					   (mo->n_bind + 1) *
					   ਆਕਾਰ(ਬਣਤਰ bind));
		    mo->bind[mo->n_bind].section = s->sh_info;
		    mo->bind[mo->n_bind].rel = save_rel;
		    mo->n_bind++;
		}
		ਨਹੀਂਤਾਂ {
                    mo->s_rebase =
                        tcc_realloc(mo->s_rebase, (mo->n_rebase + 1) *
				    ਆਕਾਰ(ਬਣਤਰ s_rebase));
                    mo->s_rebase[mo->n_rebase].section = s->sh_info;
                    mo->s_rebase[mo->n_rebase].rel = save_rel;
                    mo->n_rebase++;
		}
	    }
        }
    }
    pi = section_ptr_ਜੋੜੋ(mo->indirsyms, mo->n_got * ਆਕਾਰ(*pi));
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(pi, goti, mo->n_got * ਆਕਾਰ(*pi));
    pi = section_ptr_ਜੋੜੋ(mo->indirsyms, mo->nr_plt * ਆਕਾਰ(*pi));
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(pi, mo->indirsyms->ਅੰਕੜੇ, mo->nr_plt * ਆਕਾਰ(*pi));
    tcc_free(goti);
}
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਪੂਰਨ check_symbols(TCCState *s1, ਬਣਤਰ macho *mo)
{
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ, sym_ਸਿਰਾ;
    ਪੂਰਨ ret = 0;

    mo->ilocal = mo->iextdef = mo->iundef = -1;
    sym_ਸਿਰਾ = symtab_section->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ(ElfW(Sym));
    ਲਈ (sym_ਸੂਚਕਾਂਕ = 1; sym_ਸੂਚਕਾਂਕ < sym_ਸਿਰਾ; ++sym_ਸੂਚਕਾਂਕ) {
        ਪੂਰਨ elf_ਸੂਚਕਾਂਕ = ((ਬਣਤਰ nlist_64 *)mo->symtab->ਅੰਕੜੇ + sym_ਸੂਚਕਾਂਕ - 1)->n_ਮੁੱਲ;
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->ਅੰਕੜੇ + elf_ਸੂਚਕਾਂਕ;
        ਅਚਲ ਅੱਖਰ *name = (ਅੱਖਰ*)symtab_section->link->ਅੰਕੜੇ + sym->st_name;
        ਬਿਨਾਨਿਸ਼ਾਨੀ type = ELFW(ST_TYPE)(sym->st_info);
        ਬਿਨਾਨਿਸ਼ਾਨੀ bind = ELFW(ST_BIND)(sym->st_info);
        ਬਿਨਾਨਿਸ਼ਾਨੀ vis  = ELFW(ST_VISIBILITY)(sym->st_other);

        dprintf("%4d (%4d): %09lx %4d %4d %4d %3d %s\n",
                sym_ਸੂਚਕਾਂਕ, elf_ਸੂਚਕਾਂਕ, (ਲੰਮਾ)sym->st_ਮੁੱਲ,
                type, bind, vis, sym->st_shndx, name);
        ਜੇ (bind == STB_LOCAL) {
            ਜੇ (mo->ilocal == -1)
              mo->ilocal = sym_ਸੂਚਕਾਂਕ - 1;
            ਜੇ (mo->iextdef != -1 || mo->iundef != -1)
              tcc_error("local syms after global ones");
        } ਨਹੀਂਤਾਂ ਜੇ (sym->st_shndx != SHN_UNDEF) {
            ਜੇ (mo->iextdef == -1)
              mo->iextdef = sym_ਸੂਚਕਾਂਕ - 1;
            ਜੇ (mo->iundef != -1)
              tcc_error("external defined symbol after undefined");
        } ਨਹੀਂਤਾਂ ਜੇ (sym->st_shndx == SHN_UNDEF) {
            ਜੇ (mo->iundef == -1)
              mo->iundef = sym_ਸੂਚਕਾਂਕ - 1;
            ਜੇ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK
		|| s1->output_type != TCC_OUTPUT_EXE
                || ਲੱਭੋ_elf_sym(s1->dynsymtab_section, name)) {
                /* Mark the symbol as coming from a dylib so that
                   relocate_syms doesn't complain.  Normally bind_exe_dynsyms
                   would do this check, and place the symbol into dynsym
                   which is checked by relocate_syms.  But Mach-O doesn't use
                   bind_exe_dynsyms.  */
                sym->st_shndx = SHN_FROMDLL;
                ਜਾਰੀ;
            }
            tcc_error_noabort("unresolved reference to '%s'", name);
            ret = -1;
        }
    }
    ਵਾਪਸ ret;
}

ਸਥਿਰ ਖਾਲੀ convert_ਚਿੰਨ੍ਹ(TCCState *s1, ਬਣਤਰ macho *mo, ਬਣਤਰ nlist_64 *pn)
{
    ਬਣਤਰ nlist_64 n = *pn;
    ElfSym *sym = (ElfW(Sym) *)symtab_section->ਅੰਕੜੇ + pn->n_ਮੁੱਲ;
    ਅਚਲ ਅੱਖਰ *name = (ਅੱਖਰ*)symtab_section->link->ਅੰਕੜੇ + sym->st_name;
    ਚੋਣ(ELFW(ST_TYPE)(sym->st_info)) {
    ਹਾਲਤ STT_NOTYPE:
    ਹਾਲਤ STT_OBJECT:
    ਹਾਲਤ STT_FUNC:
    ਹਾਲਤ STT_TLS:
    ਹਾਲਤ STT_SECTION:
        n.n_type = N_SECT;
        ਰੋਕੋ;
    ਹਾਲਤ STT_FILE:
        n.n_type = N_ABS;
        ਰੋਕੋ;
    ਮੂਲ:
        tcc_error("unhandled ELF symbol type %d %s",
                  ELFW(ST_TYPE)(sym->st_info), name);
    }
    ਜੇ (sym->st_shndx == SHN_UNDEF)
      tcc_error("should have been rewritten to SHN_FROMDLL: %s", name);
    ਨਹੀਂਤਾਂ ਜੇ (sym->st_shndx == SHN_FROMDLL)
      n.n_type = N_UNDF, n.n_sect = 0;
    ਨਹੀਂਤਾਂ ਜੇ (sym->st_shndx == SHN_ABS)
      n.n_type = N_ABS, n.n_sect = 0;
    ਨਹੀਂਤਾਂ ਜੇ (sym->st_shndx >= SHN_LORESERVE)
      tcc_error("unhandled ELF symbol section %d %s", sym->st_shndx, name);
    ਨਹੀਂਤਾਂ ਜੇ (!mo->elfsectomacho[sym->st_shndx]) {
      ਜੇ (ਲੜੀ_ਤੁਲਨਾ(s1->sections[sym->st_shndx]->name, ".debug_", 7))
        tcc_error("ELF section %d(%s) not mapped into Mach-O for symbol %s",
                  sym->st_shndx, s1->sections[sym->st_shndx]->name, name);
    }
    ਨਹੀਂਤਾਂ
      n.n_sect = mo->elfsectomacho[sym->st_shndx];
    ਜੇ (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL)
      n.n_type |=  N_EXT;
    ਨਹੀਂਤਾਂ ਜੇ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
      n.n_desc |= N_WEAK_REF | (n.n_type != N_UNDF ? N_WEAK_DEF : 0);
    n.n_strx = pn->n_strx;
    n.n_ਮੁੱਲ = sym->st_ਮੁੱਲ;
    *pn = n;
}

ਸਥਿਰ ਖਾਲੀ convert_symbols(TCCState *s1, ਬਣਤਰ macho *mo)
{
    ਬਣਤਰ nlist_64 *pn;
    for_each_elem(mo->symtab, 0, pn, ਬਣਤਰ nlist_64)
        convert_ਚਿੰਨ੍ਹ(s1, mo, pn);
}

ਸਥਿਰ ਪੂਰਨ machosymcmp(ਅਚਲ ਖਾਲੀ *_a, ਅਚਲ ਖਾਲੀ *_b, ਖਾਲੀ *arg)
{
    TCCState *s1 = arg;
    ਪੂਰਨ ea = ((ਬਣਤਰ nlist_64 *)_a)->n_ਮੁੱਲ;
    ਪੂਰਨ eb = ((ਬਣਤਰ nlist_64 *)_b)->n_ਮੁੱਲ;
    ElfSym *sa = (ElfSym *)symtab_section->ਅੰਕੜੇ + ea;
    ElfSym *sb = (ElfSym *)symtab_section->ਅੰਕੜੇ + eb;
    ਪੂਰਨ r;
    /* locals, then defined externals, then undefined externals, the
       last two sections also by name, otherwise stable sort */
    r = (ELFW(ST_BIND)(sb->st_info) == STB_LOCAL)
        - (ELFW(ST_BIND)(sa->st_info) == STB_LOCAL);
    ਜੇ (r)
      ਵਾਪਸ r;
    r = (sa->st_shndx == SHN_UNDEF) - (sb->st_shndx == SHN_UNDEF);
    ਜੇ (r)
      ਵਾਪਸ r;
    ਜੇ (ELFW(ST_BIND)(sa->st_info) != STB_LOCAL) {
        ਅਚਲ ਅੱਖਰ * na = (ਅੱਖਰ*)symtab_section->link->ਅੰਕੜੇ + sa->st_name;
        ਅਚਲ ਅੱਖਰ * nb = (ਅੱਖਰ*)symtab_section->link->ਅੰਕੜੇ + sb->st_name;
        r = strcmp(na, nb);
        ਜੇ (r)
          ਵਾਪਸ r;
    }
    ਵਾਪਸ ea - eb;
}

/* cannot use qsort because code has to be reentrant */
ਸਥਿਰ ਖਾਲੀ tcc_qsort (ਖਾਲੀ  *ਅਧਾਰ, ਮਾਪ_t nel, ਮਾਪ_t ਚੌੜਾਈ,
                       ਪੂਰਨ (*comp)(ਅਚਲ ਖਾਲੀ *, ਅਚਲ ਖਾਲੀ *, ਖਾਲੀ *), ਖਾਲੀ *arg)
{
    ਮਾਪ_t wnel, gap, wgap, i, j, k;
    ਅੱਖਰ *a, *b, tmp;

    wnel = ਚੌੜਾਈ * nel;
    ਲਈ (gap = 0; ++gap < nel;)
        gap *= 3;
    ਜਦੋਂ ( gap /= 3 ) {
        wgap = ਚੌੜਾਈ * gap;
        ਲਈ (i = wgap; i < wnel; i += ਚੌੜਾਈ) {
            ਲਈ (j = i - wgap; ;j -= wgap) {
                a = j + (ਅੱਖਰ *)ਅਧਾਰ;
                b = a + wgap;
                ਜੇ ( (*comp)(a, b, arg) <= 0 )
                    ਰੋਕੋ;
                k = ਚੌੜਾਈ;
                ਕਰੋ {
                    tmp = *a;
                    *a++ = *b;
                    *b++ = tmp;
                } ਜਦੋਂ ( --k );
                ਜੇ (j < wgap)
                    ਰੋਕੋ;
            }
        }
    }
}

ਸਥਿਰ ਖਾਲੀ create_symtab(TCCState *s1, ਬਣਤਰ macho *mo)
{
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ, sym_ਸਿਰਾ;
    ਬਣਤਰ nlist_64 *pn;

    /* Stub creation belongs to check_relocs, but we need to create
       the symbol now, so its included in the sorting.  */
    mo->stubs = new_section(s1, "__stubs", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->stubsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stubs->sh_ਅੰਕ, ".__stubs");
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_NEW_MACHO
    mo->chained_fixups = new_section(s1, "CHAINED_FIXUPS",
				     SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#ਨਹੀਂਤਾਂ
    mo->stub_helper = new_section(s1, "__stub_helper", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    mo->la_ਚਿੰਨ੍ਹ_ptr = new_section(s1, "__la_symbol_ptr", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->helpsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stub_helper->sh_ਅੰਕ, ".__stub_helper");
    mo->lasym = put_elf_sym(s1->symtab, 0, 0,
                            ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                            mo->la_ਚਿੰਨ੍ਹ_ptr->sh_ਅੰਕ, ".__la_symbol_ptr");
    section_ptr_ਜੋੜੋ(ਅੰਕੜੇ_section, -ਅੰਕੜੇ_section->ਅੰਕੜੇ_ਵਿੱਥ & (PTR_ਮਾਪ - 1));
    mo->dyld_ਨਿੱਜੀ = put_elf_sym(s1->symtab, ਅੰਕੜੇ_section->ਅੰਕੜੇ_ਵਿੱਥ, PTR_ਮਾਪ,
                                   ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT), 0,
                                   ਅੰਕੜੇ_section->sh_ਅੰਕ, ".__dyld_private");
    section_ptr_ਜੋੜੋ(ਅੰਕੜੇ_section, PTR_ਮਾਪ);
    mo->dyld_stub_binder = put_elf_sym(s1->symtab, 0, 0,
                		       ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				       SHN_UNDEF, "dyld_stub_binder");
    mo->rebase = new_section(s1, "REBASE", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->binding = new_section(s1, "BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->weak_binding = new_section(s1, "WEAK_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->lazy_binding = new_section(s1, "LAZY_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#ਜੇ_ਅੰਤ
    mo->exports = new_section(s1, "EXPORT", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->indirsyms = new_section(s1, "LEINDIR", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);

    mo->symtab = new_section(s1, "LESYMTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->strtab = new_section(s1, "LESTRTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    put_elf_str(mo->strtab, " "); /* Mach-O starts strtab with a space */
    sym_ਸਿਰਾ = symtab_section->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ(ElfW(Sym));
    pn = section_ptr_ਜੋੜੋ(mo->symtab, ਆਕਾਰ(*pn) * (sym_ਸਿਰਾ - 1));
    ਲਈ (sym_ਸੂਚਕਾਂਕ = 1; sym_ਸੂਚਕਾਂਕ < sym_ਸਿਰਾ; ++sym_ਸੂਚਕਾਂਕ) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->ਅੰਕੜੇ + sym_ਸੂਚਕਾਂਕ;
        ਅਚਲ ਅੱਖਰ *name = (ਅੱਖਰ*)symtab_section->link->ਅੰਕੜੇ + sym->st_name;
        pn[sym_ਸੂਚਕਾਂਕ - 1].n_strx = put_elf_str(mo->strtab, name);
        pn[sym_ਸੂਚਕਾਂਕ - 1].n_ਮੁੱਲ = sym_ਸੂਚਕਾਂਕ;
    }
    section_ptr_ਜੋੜੋ(mo->strtab, -mo->strtab->ਅੰਕੜੇ_ਵਿੱਥ & (PTR_ਮਾਪ - 1));
    tcc_qsort(pn, sym_ਸਿਰਾ - 1, ਆਕਾਰ(*pn), machosymcmp, s1);
    mo->e2msym = tcc_malloc(sym_ਸਿਰਾ * ਆਕਾਰ(*mo->e2msym));
    mo->e2msym[0] = -1;
    ਲਈ (sym_ਸੂਚਕਾਂਕ = 1; sym_ਸੂਚਕਾਂਕ < sym_ਸਿਰਾ; ++sym_ਸੂਚਕਾਂਕ) {
        mo->e2msym[pn[sym_ਸੂਚਕਾਂਕ - 1].n_ਮੁੱਲ] = sym_ਸੂਚਕਾਂਕ - 1;
    }
}

ਅਚਲ ਬਣਤਰ {
    ਪੂਰਨ seg_initial;
    uint32_t flags;
    ਅਚਲ ਅੱਖਰ *name;
} skinfo[sk_ਆਖਰੀ] = {
    /*[sk_unknown] =*/        { 0 },
    /*[sk_discard] =*/        { 0 },
    /*[sk_text] =*/           { 1, S_REGULAR | S_ATTR_ਸ਼ੁੱਧ_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS, "__text" },
    /*[sk_stubs] =*/          { 1, S_REGULAR | S_ATTR_ਸ਼ੁੱਧ_INSTRUCTIONS | S_ਚਿੰਨ੍ਹ_STUBS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stubs" },
    /*[sk_stub_helper] =*/    { 1, S_REGULAR | S_ATTR_ਸ਼ੁੱਧ_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stub_helper" },
    /*[sk_ro_data] =*/        { 2, S_REGULAR, "__rodata" },
    /*[sk_uw_info] =*/        { 0 },
    /*[sk_nl_ptr] =*/         { 2, S_NON_LAZY_ਚਿੰਨ੍ਹ_ਸੂਚਕ_ਸਾਰੇ, "__got" },
    /*[sk_debug_info] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_info" },
    /*[sk_debug_abbrev] =*/   { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_abbrev" },
    /*[sk_debug_line] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line" },
    /*[sk_debug_aranges] =*/  { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_aranges" },
    /*[sk_debug_str] =*/      { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_str" },
    /*[sk_debug_line_str] =*/ { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line_str" },
    /*[sk_stab] =*/           { 4, S_REGULAR, "__stab" },
    /*[sk_stab_str] =*/       { 4, S_REGULAR, "__stab_str" },
    /*[sk_la_ptr] =*/         { 4, S_LAZY_ਚਿੰਨ੍ਹ_ਸੂਚਕ_ਸਾਰੇ, "__la_symbol_ptr" },
    /*[sk_init] =*/           { 4, S_MOD_INIT_FUNC_ਸੂਚਕ_ਸਾਰੇ, "__mod_init_func" },
    /*[sk_fini] =*/           { 4, S_MOD_ਪਦ_FUNC_ਸੂਚਕ_ਸਾਰੇ, "__mod_term_func" },
    /*[sk_rw_data] =*/        { 4, S_REGULAR, "__data" },
    /*[sk_bss] =*/            { 4, S_ZEROFILL, "__bss" },
    /*[sk_linkedit] =*/       { 5, S_REGULAR, ਨਿਰਾ },
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	ਸ਼ੁਰੂ_3	((uint64_t)1 << 32)

ਅਚਲ ਬਣਤਰ {
    ਪੂਰਨ ਵਰਤਿਆ;
    ਅਚਲ ਅੱਖਰ *name;
    uint64_t vmaddr;
    uint64_t vmsize;
    vm_prot_t maxprot;
    vm_prot_t initprot;
    uint32_t flags;
} all_segment[] = {
    { 1, "__PAGEZERO",       0, ਸ਼ੁਰੂ_3, 0, 0,            0 },
    { 0, "__TEXT",       ਸ਼ੁਰੂ_3,     0, 5, 5,            0 },
    { 0, "__DATA_CONST",    -1,     0, 3, 3, SG_READ_ONLY },
    { 0, "__DWARF",         -1,     0, 7, 3,            0 },
    { 0, "__DATA",          -1,     0, 3, 3,            0 },
    { 1, "__LINKEDIT",      -1,     0, 1, 1,            0 },
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	N_SEGMENT	(ਆਕਾਰ(all_segment)/ਆਕਾਰ(all_segment[0]))

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_NEW_MACHO
ਸਥਿਰ ਖਾਲੀ calc_fixup_ਮਾਪ(TCCState *s1, ਬਣਤਰ macho *mo)
{
    ਪੂਰਨ i, ਮਾਪ;

    ਮਾਪ = (ਆਕਾਰ(ਬਣਤਰ dyld_chained_fixups_ਸਿਰਲੇਖ) + 7) & -8;
    ਮਾਪ += (ਆਕਾਰ(ਬਣਤਰ dyld_chained_starts_ਵਿੱਚ_image) + (mo->nseg - 1) * ਆਕਾਰ(uint32_t) + 7) & -8;
    ਲਈ (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	ਪੂਰਨ ਪੰਨਾ_ਗਿਣਤੀ = (get_segment(mo, i)->vmsize + SEG_ਪੰਨਾ_ਮਾਪ - 1) / SEG_ਪੰਨਾ_ਮਾਪ;
	ਮਾਪ += (ਆਕਾਰ(ਬਣਤਰ dyld_chained_starts_ਵਿੱਚ_segment) + (ਪੰਨਾ_ਗਿਣਤੀ - 1) * ਆਕਾਰ(uint16_t) + 7) & -8;
    }
    ਮਾਪ += mo->n_bind * ਆਕਾਰ (ਬਣਤਰ dyld_chained_import) + 1;
    ਲਈ (i = 0; i < mo->n_bind_rebase; i++) {
	ਜੇ (mo->bind_rebase[i].bind) {
	    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
	    ਅਚਲ ਅੱਖਰ *name = (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name;
	    ਮਾਪ += ਲੜੀ_ਲੰਬਾਈ(name) + 1;
	}
    }
    ਮਾਪ = (ਮਾਪ + 7) & -8;
    section_ptr_ਜੋੜੋ(mo->chained_fixups, ਮਾਪ);
}

#ਨਹੀਂਤਾਂ

ਸਥਿਰ ਖਾਲੀ ਸੈੱਟ_segment_and_ਵਿੱਥ(TCCState *s1, ਬਣਤਰ macho *mo, addr_t addr,
				   uint8_t *ptr, ਪੂਰਨ opcode,
				   Section *sec, addr_t ਵਿੱਥ)
{
    ਪੂਰਨ i;
    ਬਣਤਰ segment_command_64 *seg = ਨਿਰਾ;

    ਲਈ (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	seg = get_segment(mo, i);
	ਜੇ (addr >= seg->vmaddr && addr < (seg->vmaddr + seg->vmsize))
	    ਰੋਕੋ;
    }
    *ptr = opcode | i;
    write_uleb128(sec, ਵਿੱਥ - seg->vmaddr);
}

ਸਥਿਰ ਖਾਲੀ bind_rebase(TCCState *s1, ਬਣਤਰ macho *mo)
{
    ਪੂਰਨ i;
    uint8_t *ptr;
    ElfW(Sym) *sym;
    ਅਚਲ ਅੱਖਰ *name;

    ਲਈ (i = 0; i < mo->n_lazy_bind; i++) {
	ਪੂਰਨ sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(mo->s_lazy_bind[i].rel.r_info);

	sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
	name = (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name;
	write32le(mo->stub_helper->ਅੰਕੜੇ +
		  mo->s_lazy_bind[i].bind_ਵਿੱਥ,
		  mo->lazy_binding->ਅੰਕੜੇ_ਵਿੱਥ);
	ptr = section_ptr_ਜੋੜੋ(mo->lazy_binding, 1);
	ਸੈੱਟ_segment_and_ਵਿੱਥ(s1, mo, mo->la_ਚਿੰਨ੍ਹ_ptr->sh_addr, ptr,
			       BIND_OPCODE_ਸੈੱਟ_SEGMENT_AND_ਵਿੱਥ_ULEB,
			       mo->lazy_binding,
			       mo->s_lazy_bind[i].la_ਚਿੰਨ੍ਹ_ਵਿੱਥ +
			       mo->la_ਚਿੰਨ੍ਹ_ptr->sh_addr);
	ptr = section_ptr_ਜੋੜੋ(mo->lazy_binding, 5 + ਲੜੀ_ਲੰਬਾਈ(name));
	*ptr++ = BIND_OPCODE_ਸੈੱਟ_DYLIB_SPECIAL_IMM |
		 (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
	*ptr++ = BIND_OPCODE_ਸੈੱਟ_ਚਿੰਨ੍ਹ_TRAILING_FLAGS_IMM | 0;
	strcpy((ਅੱਖਰ *)ptr, name);
	ptr += ਲੜੀ_ਲੰਬਾਈ(name) + 1;
	*ptr++ = BIND_OPCODE_DO_BIND;
	*ptr = BIND_OPCODE_ਪੂਰਾ;
    }
    ਲਈ (i = 0; i < mo->n_rebase; i++) {
	Section *s = s1->sections[mo->s_rebase[i].section];

	ptr = section_ptr_ਜੋੜੋ(mo->rebase, 2);
	*ptr++ = REBASE_OPCODE_ਸੈੱਟ_TYPE_IMM | REBASE_TYPE_ਸੂਚਕ;
	ਸੈੱਟ_segment_and_ਵਿੱਥ(s1, mo, s->sh_addr, ptr,
			       REBASE_OPCODE_ਸੈੱਟ_SEGMENT_AND_ਵਿੱਥ_ULEB,
			       mo->rebase,
			       mo->s_rebase[i].rel.r_ਵਿੱਥ +
			       s->sh_addr);
	ptr = section_ptr_ਜੋੜੋ(mo->rebase, 1);
	*ptr = REBASE_OPCODE_DO_REBASE_IMM_TIMES | 1;
    }
    ਲਈ (i = 0; i < mo->n_bind; i++) {
	ਪੂਰਨ sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(mo->bind[i].rel.r_info);
	Section *s = s1->sections[mo->bind[i].section];
	Section *binding;

	sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
	name = (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name;
	binding = ELFW(ST_BIND)(sym->st_info) == STB_WEAK
	    ? mo->weak_binding : mo->binding;
        ptr = section_ptr_ਜੋੜੋ(binding, 4 + (binding == mo->binding) +
			     	       ਲੜੀ_ਲੰਬਾਈ(name));
	ਜੇ (binding == mo->binding)
            *ptr++ = BIND_OPCODE_ਸੈੱਟ_DYLIB_SPECIAL_IMM |
	             (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
        *ptr++ = BIND_OPCODE_ਸੈੱਟ_ਚਿੰਨ੍ਹ_TRAILING_FLAGS_IMM |
		 (binding == mo->weak_binding
		  ? BIND_ਚਿੰਨ੍ਹ_FLAGS_WEAK_IMPORT : 0);
        strcpy((ਅੱਖਰ *)ptr, name);
        ptr += ਲੜੀ_ਲੰਬਾਈ(name) + 1;
        *ptr++ = BIND_OPCODE_ਸੈੱਟ_TYPE_IMM | BIND_TYPE_ਸੂਚਕ;
	ਸੈੱਟ_segment_and_ਵਿੱਥ(s1, mo, s->sh_addr, ptr,
			       BIND_OPCODE_ਸੈੱਟ_SEGMENT_AND_ਵਿੱਥ_ULEB,
			       binding,
			       mo->bind[i].rel.r_ਵਿੱਥ + s->sh_addr);
        ptr = section_ptr_ਜੋੜੋ(binding, 1);
        *ptr++ = BIND_OPCODE_DO_BIND;
    }
    ਜੇ (mo->rebase->ਅੰਕੜੇ_ਵਿੱਥ) {
        ptr = section_ptr_ਜੋੜੋ(mo->rebase, 1);
        *ptr = REBASE_OPCODE_ਪੂਰਾ;
    }
    ਜੇ (mo->binding->ਅੰਕੜੇ_ਵਿੱਥ) {
        ptr = section_ptr_ਜੋੜੋ(mo->binding, 1);
        *ptr = BIND_OPCODE_ਪੂਰਾ;
    }
    ਜੇ (mo->weak_binding->ਅੰਕੜੇ_ਵਿੱਥ) {
        ptr = section_ptr_ਜੋੜੋ(mo->weak_binding, 1);
        *ptr = BIND_OPCODE_ਪੂਰਾ;
    }
    tcc_free(mo->s_lazy_bind);
    tcc_free(mo->s_rebase);
    tcc_free(mo->bind);
}
#ਜੇ_ਅੰਤ

ਬਣਤਰ trie_info {
    ਅਚਲ ਅੱਖਰ *name;
    ਪੂਰਨ flag;
    addr_t addr;
    ਪੂਰਨ str_ਮਾਪ;
    ਪੂਰਨ ਪਦ_ਮਾਪ;
};

ਬਣਤਰ trie_ਗੰਢ {
    ਪੂਰਨ ਸ਼ੁਰੂ;
    ਪੂਰਨ ਸਿਰਾ;
    ਪੂਰਨ ਸੂਚਕਾਂਕ_ਸ਼ੁਰੂ;
    ਪੂਰਨ ਸੂਚਕਾਂਕ_ਸਿਰਾ;
    ਪੂਰਨ n_ਬੱਚਾ;
    ਬਣਤਰ trie_ਗੰਢ *ਬੱਚਾ;
};

ਬਣਤਰ trie_seq {
    ਪੂਰਨ n_ਬੱਚਾ;
    ਬਣਤਰ trie_ਗੰਢ *ਗੰਢ;
    ਪੂਰਨ ਵਿੱਥ;
    ਪੂਰਨ nest_ਵਿੱਥ;
};

ਸਥਿਰ ਖਾਲੀ create_trie(ਬਣਤਰ trie_ਗੰਢ *ਗੰਢ,
                        ਪੂਰਨ from, ਪੂਰਨ ਮੰਜ਼ਿਲ, ਪੂਰਨ ਸੂਚਕਾਂਕ_ਸ਼ੁਰੂ,
                        ਪੂਰਨ n_trie, ਬਣਤਰ trie_info *trie)
{
    ਪੂਰਨ i;
    ਪੂਰਨ ਸ਼ੁਰੂ, ਸਿਰਾ, ਸੂਚਕਾਂਕ_ਸਿਰਾ;
    ਅੱਖਰ cur;
    ਬਣਤਰ trie_ਗੰਢ *ਬੱਚਾ;

    ਲਈ (i = from; i < ਮੰਜ਼ਿਲ; i = ਸਿਰਾ) {
        cur = trie[i].name[ਸੂਚਕਾਂਕ_ਸ਼ੁਰੂ];
        ਸ਼ੁਰੂ = i++;
        ਲਈ (; i < ਮੰਜ਼ਿਲ; i++)
            ਜੇ (cur != trie[i].name[ਸੂਚਕਾਂਕ_ਸ਼ੁਰੂ])
                ਰੋਕੋ;
        ਸਿਰਾ = i;
        ਜੇ (ਸ਼ੁਰੂ == ਸਿਰਾ - 1 ||
            (trie[ਸ਼ੁਰੂ].name[ਸੂਚਕਾਂਕ_ਸ਼ੁਰੂ] &&
             trie[ਸ਼ੁਰੂ].name[ਸੂਚਕਾਂਕ_ਸ਼ੁਰੂ + 1] == 0))
            ਸੂਚਕਾਂਕ_ਸਿਰਾ = trie[ਸ਼ੁਰੂ].str_ਮਾਪ - 1;
        ਨਹੀਂਤਾਂ {
            ਸੂਚਕਾਂਕ_ਸਿਰਾ = ਸੂਚਕਾਂਕ_ਸ਼ੁਰੂ + 1;
            ਲਈ (;;) {
                cur = trie[ਸ਼ੁਰੂ].name[ਸੂਚਕਾਂਕ_ਸਿਰਾ];
                ਲਈ (i = ਸ਼ੁਰੂ + 1; i < ਸਿਰਾ; i++)
                    ਜੇ (cur != trie[i].name[ਸੂਚਕਾਂਕ_ਸਿਰਾ])
                        ਰੋਕੋ;
                ਜੇ (trie[ਸ਼ੁਰੂ].name[ਸੂਚਕਾਂਕ_ਸਿਰਾ] &&
                    trie[ਸ਼ੁਰੂ].name[ਸੂਚਕਾਂਕ_ਸਿਰਾ + 1] == 0) {
                    ਸਿਰਾ = ਸ਼ੁਰੂ + 1;
                    ਸੂਚਕਾਂਕ_ਸਿਰਾ = trie[ਸ਼ੁਰੂ].str_ਮਾਪ - 1;
                    ਰੋਕੋ;
                }
                ਜੇ (i != ਸਿਰਾ)
                    ਰੋਕੋ;
                ਸੂਚਕਾਂਕ_ਸਿਰਾ++;
            }
        }
        ਗੰਢ->ਬੱਚਾ = tcc_realloc(ਗੰਢ->ਬੱਚਾ,
                                  (ਗੰਢ->n_ਬੱਚਾ + 1) *
                                  ਆਕਾਰ(ਬਣਤਰ trie_ਗੰਢ));
        ਬੱਚਾ = &ਗੰਢ->ਬੱਚਾ[ਗੰਢ->n_ਬੱਚਾ];
        ਬੱਚਾ->ਸ਼ੁਰੂ = ਸ਼ੁਰੂ;
        ਬੱਚਾ->ਸਿਰਾ = ਸਿਰਾ;
        ਬੱਚਾ->ਸੂਚਕਾਂਕ_ਸ਼ੁਰੂ = ਸੂਚਕਾਂਕ_ਸ਼ੁਰੂ;
        ਬੱਚਾ->ਸੂਚਕਾਂਕ_ਸਿਰਾ = ਸੂਚਕਾਂਕ_ਸਿਰਾ;
        ਬੱਚਾ->n_ਬੱਚਾ = 0;
        ਬੱਚਾ->ਬੱਚਾ = ਨਿਰਾ;
        ਗੰਢ->n_ਬੱਚਾ++;
        ਜੇ (ਸ਼ੁਰੂ != ਸਿਰਾ - 1)
            create_trie(ਬੱਚਾ, ਸ਼ੁਰੂ, ਸਿਰਾ, ਸੂਚਕਾਂਕ_ਸਿਰਾ, n_trie, trie);
    }
}

ਸਥਿਰ ਪੂਰਨ create_seq(ਪੂਰਨ *ਵਿੱਥ, ਪੂਰਨ *n_seq, ਬਣਤਰ trie_seq **seq,
                        ਬਣਤਰ trie_ਗੰਢ *ਗੰਢ,
                        ਪੂਰਨ n_trie, ਬਣਤਰ trie_info *trie)
{
    ਪੂਰਨ i, nest_ਵਿੱਥ, ਆਖਰੀ_seq = *n_seq, retval = *ਵਿੱਥ;
    ਬਣਤਰ trie_seq *p_seq;
    ਬਣਤਰ trie_ਗੰਢ *p_nest;

    ਲਈ (i = 0; i < ਗੰਢ->n_ਬੱਚਾ; i++) {
        p_nest = &ਗੰਢ->ਬੱਚਾ[i];
        *seq = tcc_realloc(*seq, (*n_seq + 1) * ਆਕਾਰ(ਬਣਤਰ trie_seq));
        p_seq = &(*seq)[(*n_seq)++];
        p_seq->n_ਬੱਚਾ = i == 0 ? ਗੰਢ->n_ਬੱਚਾ : -1;
        p_seq->ਗੰਢ = p_nest;
        p_seq->ਵਿੱਥ = *ਵਿੱਥ;
        p_seq->nest_ਵਿੱਥ = 0;
        *ਵਿੱਥ += (i == 0 ? 1 + 1 : 0) +
                   p_nest->ਸੂਚਕਾਂਕ_ਸਿਰਾ - p_nest->ਸੂਚਕਾਂਕ_ਸ਼ੁਰੂ + 1 + 3;
    }
    ਲਈ (i = 0; i < ਗੰਢ->n_ਬੱਚਾ; i++) {
        nest_ਵਿੱਥ =
            create_seq(ਵਿੱਥ, n_seq, seq, &ਗੰਢ->ਬੱਚਾ[i], n_trie, trie);
        p_seq = &(*seq)[ਆਖਰੀ_seq + i];
        p_seq->nest_ਵਿੱਥ = nest_ਵਿੱਥ;
    }
    ਵਾਪਸ retval;
}

ਸਥਿਰ ਖਾਲੀ ਗੰਢ_free(ਬਣਤਰ trie_ਗੰਢ *ਗੰਢ)
{
    ਪੂਰਨ i;

    ਲਈ (i = 0; i < ਗੰਢ->n_ਬੱਚਾ; i++)
	ਗੰਢ_free(&ਗੰਢ->ਬੱਚਾ[i]);
    tcc_free(ਗੰਢ->ਬੱਚਾ);
}

ਸਥਿਰ ਪੂਰਨ triecmp(ਅਚਲ ਖਾਲੀ *_a, ਅਚਲ ਖਾਲੀ *_b, ਖਾਲੀ *arg)
{
    ਬਣਤਰ trie_info *a = (ਬਣਤਰ trie_info *) _a;
    ਬਣਤਰ trie_info *b = (ਬਣਤਰ trie_info *) _b;
    ਪੂਰਨ len_a = ਲੜੀ_ਲੰਬਾਈ(a->name);
    ਪੂਰਨ len_b = ਲੜੀ_ਲੰਬਾਈ(b->name);

    /* strange sorting needed. Name 'xx' should be after 'xx1' */
    ਜੇ (!ਲੜੀ_ਤੁਲਨਾ(a->name, b->name, len_a < len_b ? len_a : len_b))
	ਵਾਪਸ len_a < len_b ? 1 : (len_a > len_b ? -1 : 0);
    ਵਾਪਸ strcmp(a->name, b->name);
}

ਸਥਿਰ ਖਾਲੀ export_trie(TCCState *s1, ਬਣਤਰ macho *mo)
{
    ਪੂਰਨ i, ਮਾਪ, ਵਿੱਥ = 0, save_ਵਿੱਥ;
    uint8_t *ptr;
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ;
    ਪੂਰਨ sym_ਸਿਰਾ = symtab_section->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ(ElfW(Sym));
    ਪੂਰਨ n_trie = 0, n_seq = 0;
    ਬਣਤਰ trie_info *trie = ਨਿਰਾ, *p_trie;
    ਬਣਤਰ trie_ਗੰਢ ਗੰਢ, *p_ਗੰਢ;
    ਬਣਤਰ trie_seq *seq = ਨਿਰਾ;
    addr_t vm_addr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;

    ਲਈ (sym_ਸੂਚਕਾਂਕ = 1; sym_ਸੂਚਕਾਂਕ < sym_ਸਿਰਾ; ++sym_ਸੂਚਕਾਂਕ) {
	ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->ਅੰਕੜੇ + sym_ਸੂਚਕਾਂਕ;
	ਅਚਲ ਅੱਖਰ *name = (ਅੱਖਰ*)symtab_section->link->ਅੰਕੜੇ + sym->st_name;

	ਜੇ (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE &&
            (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL ||
	     ELFW(ST_BIND)(sym->st_info) == STB_WEAK)) {
	    ਪੂਰਨ flag = EXPORT_ਚਿੰਨ੍ਹ_FLAGS_ਕਿਸਮ_REGULAR;
	    addr_t addr =
		sym->st_ਮੁੱਲ + s1->sections[sym->st_shndx]->sh_addr - vm_addr;

	    ਜੇ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
		flag |= EXPORT_ਚਿੰਨ੍ਹ_FLAGS_WEAK_DEFINITION;
	    dprintf ("%s %d %llx\n", name, flag, (ਲੰਮਾ ਲੰਮਾ)addr + vm_addr);
	    trie = tcc_realloc(trie, (n_trie + 1) * ਆਕਾਰ(ਬਣਤਰ trie_info));
	    trie[n_trie].name = name;
	    trie[n_trie].flag = flag;
	    trie[n_trie].addr = addr;
	    trie[n_trie].str_ਮਾਪ = ਲੜੀ_ਲੰਬਾਈ(name) + 1;
	    trie[n_trie].ਪਦ_ਮਾਪ = uleb128_ਮਾਪ(flag) + uleb128_ਮਾਪ(addr);
	    n_trie++;
	}
    }
    ਜੇ (n_trie) {
        tcc_qsort(trie, n_trie, ਆਕਾਰ(ਬਣਤਰ trie_info), triecmp, ਨਿਰਾ);
	memset(&ਗੰਢ, 0, ਆਕਾਰ(ਗੰਢ));
        create_trie(&ਗੰਢ, 0, n_trie, 0, n_trie, trie);
	create_seq(&ਵਿੱਥ, &n_seq, &seq, &ਗੰਢ, n_trie, trie);
        save_ਵਿੱਥ = ਵਿੱਥ;
        ਲਈ (i = 0; i < n_seq; i++) {
            p_ਗੰਢ = seq[i].ਗੰਢ;
            ਜੇ (p_ਗੰਢ->n_ਬੱਚਾ == 0) {
                p_trie = &trie[p_ਗੰਢ->ਸ਼ੁਰੂ];
                seq[i].nest_ਵਿੱਥ = ਵਿੱਥ;
                ਵਿੱਥ += 1 + p_trie->ਪਦ_ਮਾਪ + 1;
            }
        }
        ਲਈ (i = 0; i < n_seq; i++) {
            p_ਗੰਢ = seq[i].ਗੰਢ;
            p_trie = &trie[p_ਗੰਢ->ਸ਼ੁਰੂ];
            ਜੇ (seq[i].n_ਬੱਚਾ >= 0) {
                section_ptr_ਜੋੜੋ(mo->exports,
				seq[i].ਵਿੱਥ - mo->exports->ਅੰਕੜੇ_ਵਿੱਥ);
                ptr = section_ptr_ਜੋੜੋ(mo->exports, 2);
                *ptr++ = 0;
                *ptr = seq[i].n_ਬੱਚਾ;
            }
            ਮਾਪ = p_ਗੰਢ->ਸੂਚਕਾਂਕ_ਸਿਰਾ - p_ਗੰਢ->ਸੂਚਕਾਂਕ_ਸ਼ੁਰੂ;
            ptr = section_ptr_ਜੋੜੋ(mo->exports, ਮਾਪ + 1);
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(ptr, &p_trie->name[p_ਗੰਢ->ਸੂਚਕਾਂਕ_ਸ਼ੁਰੂ], ਮਾਪ);
            ptr[ਮਾਪ] = 0;
            write_uleb128(mo->exports, seq[i].nest_ਵਿੱਥ);
        }
        section_ptr_ਜੋੜੋ(mo->exports, save_ਵਿੱਥ - mo->exports->ਅੰਕੜੇ_ਵਿੱਥ);
        ਲਈ (i = 0; i < n_seq; i++) {
            p_ਗੰਢ = seq[i].ਗੰਢ;
            ਜੇ (p_ਗੰਢ->n_ਬੱਚਾ == 0) {
                p_trie = &trie[p_ਗੰਢ->ਸ਼ੁਰੂ];
                write_uleb128(mo->exports, p_trie->ਪਦ_ਮਾਪ);
                write_uleb128(mo->exports, p_trie->flag);
                write_uleb128(mo->exports, p_trie->addr);
                ptr = section_ptr_ਜੋੜੋ(mo->exports, 1);
                *ptr = 0;
            }
        }
        section_ptr_ਜੋੜੋ(mo->exports, -mo->exports->ਅੰਕੜੇ_ਵਿੱਥ & 7);
	ਗੰਢ_free(&ਗੰਢ);
        tcc_free(seq);
    }
    tcc_free(trie);
}

ਸਥਿਰ ਖਾਲੀ collect_sections(TCCState *s1, ਬਣਤਰ macho *mo, ਅਚਲ ਅੱਖਰ *filename)
{
    ਪੂਰਨ i, sk, numsec;
    ਪੂਰਨ ਵਰਤਿਆ_segment[N_SEGMENT];
    uint64_t curaddr, fileofs;
    Section *s;
    ਬਣਤਰ segment_command_64 *seg;
    ਬਣਤਰ dylib_command *dylib;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_NEW_MACHO
    ਬਣਤਰ linkedit_ਅੰਕੜੇ_command *chained_fixups_lc;
    ਬਣਤਰ linkedit_ਅੰਕੜੇ_command *export_trie_lc;
#ਜੇ_ਅੰਤ
    ਬਣਤਰ build_ਸੰਸਕਰਣ_command *dyldbv;
    ਬਣਤਰ ਸਰੋਤ_ਸੰਸਕਰਣ_command *dyldsv;
    ਬਣਤਰ rpath_command *rpath;
    ਬਣਤਰ dylinker_command *dyldlc;
    ਬਣਤਰ symtab_command *symlc;
    ਬਣਤਰ dysymtab_command *dysymlc;
    ਅੱਖਰ *str;

    ਲਈ (i = 0; i < N_SEGMENT; i++)
	ਵਰਤਿਆ_segment[i] = all_segment[i].ਵਰਤਿਆ;

    memset (mo->sk_ਮੰਜ਼ਿਲ_sect, 0, ਆਕਾਰ(mo->sk_ਮੰਜ਼ਿਲ_sect));
    ਲਈ (i = s1->nb_sections; i-- > 1;) {
        ਪੂਰਨ type, flags;
        s = s1->sections[i];
        type = s->sh_type;
        flags = s->sh_flags;
        sk = sk_unknown;
	/* debug sections have sometimes no SHF_ALLOC */
        ਜੇ ((flags & SHF_ALLOC) || !ਲੜੀ_ਤੁਲਨਾ(s->name, ".debug_", 7)) {
            ਚੋਣ (type) {
            ਮੂਲ:           sk = sk_unknown; ਰੋਕੋ;
            ਹਾਲਤ SHT_INIT_ARRAY: sk = sk_init; ਰੋਕੋ;
            ਹਾਲਤ SHT_FINI_ARRAY: sk = sk_fini; ਰੋਕੋ;
            ਹਾਲਤ SHT_NOBITS:   sk = sk_bss; ਰੋਕੋ;
            ਹਾਲਤ SHT_SYMTAB:   sk = sk_discard; ਰੋਕੋ;
            ਹਾਲਤ SHT_STRTAB:
		ਜੇ (s == stabstr_section)
		  sk = sk_stab_str;
		ਨਹੀਂਤਾਂ
		  sk = sk_discard;
		ਰੋਕੋ;
            ਹਾਲਤ SHT_RELX:     sk = sk_discard; ਰੋਕੋ;
            ਹਾਲਤ SHT_LINKEDIT: sk = sk_linkedit; ਰੋਕੋ;
            ਹਾਲਤ SHT_PROGBITS:
                ਜੇ (s == mo->stubs)
                  sk = sk_stubs;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_NEW_MACHO
                ਨਹੀਂਤਾਂ ਜੇ (s == mo->stub_helper)
                  sk = sk_stub_helper;
                ਨਹੀਂਤਾਂ ਜੇ (s == mo->la_ਚਿੰਨ੍ਹ_ptr)
                  sk = sk_la_ptr;
#ਜੇ_ਅੰਤ
                ਨਹੀਂਤਾਂ ਜੇ (s == rodata_section)
                  sk = sk_ro_ਅੰਕੜੇ;
                ਨਹੀਂਤਾਂ ਜੇ (s == s1->got)
                  sk = sk_nl_ptr;
                ਨਹੀਂਤਾਂ ਜੇ (s == stab_section)
                  sk = sk_stab;
                ਨਹੀਂਤਾਂ ਜੇ (s == dwarf_info_section)
                  sk = sk_debug_info;
                ਨਹੀਂਤਾਂ ਜੇ (s == dwarf_abbrev_section)
                  sk = sk_debug_abbrev;
                ਨਹੀਂਤਾਂ ਜੇ (s == dwarf_ਸਤਰ_section)
                  sk = sk_debug_ਸਤਰ;
                ਨਹੀਂਤਾਂ ਜੇ (s == dwarf_aranges_section)
                  sk = sk_debug_aranges;
                ਨਹੀਂਤਾਂ ਜੇ (s == dwarf_str_section)
                  sk = sk_debug_str;
                ਨਹੀਂਤਾਂ ਜੇ (s == dwarf_ਸਤਰ_str_section)
                  sk = sk_debug_ਸਤਰ_str;
                ਨਹੀਂਤਾਂ ਜੇ (flags & SHF_EXECINSTR)
                  sk = sk_ਪਾਠ;
                ਨਹੀਂਤਾਂ ਜੇ (flags & SHF_WRITE)
                  sk = sk_rw_ਅੰਕੜੇ;
                ਨਹੀਂਤਾਂ
                  sk = sk_ro_ਅੰਕੜੇ;
                ਰੋਕੋ;
            }
        } ਨਹੀਂਤਾਂ
          sk = sk_discard;
        s->prev = mo->sk_ਮੰਜ਼ਿਲ_sect[sk].s;
        mo->sk_ਮੰਜ਼ਿਲ_sect[sk].s = s;
	ਵਰਤਿਆ_segment[skinfo[sk].seg_initial] = 1;
    }

    ਜੇ (s1->output_type != TCC_OUTPUT_EXE)
	ਵਰਤਿਆ_segment[0] = 0;

    ਲਈ (i = 0; i < N_SEGMENT; i++)
	ਜੇ (ਵਰਤਿਆ_segment[i]) {
	    seg = ਜੋੜੋ_segment(mo, all_segment[i].name);
	    ਜੇ (i == 1 && s1->output_type != TCC_OUTPUT_EXE)
	        seg->vmaddr = 0;
	    ਨਹੀਂਤਾਂ
	        seg->vmaddr = all_segment[i].vmaddr;
	    seg->vmsize = all_segment[i].vmsize;
	    seg->maxprot = all_segment[i].maxprot;
	    seg->initprot = all_segment[i].initprot;
	    seg->flags = all_segment[i].flags;
            ਲਈ (sk = sk_unknown; sk < sk_ਆਖਰੀ; sk++)
		ਜੇ (skinfo[sk].seg_initial == i)
	            mo->segment[sk] = mo->nseg - 1;
	}

    ਜੇ (s1->output_type != TCC_OUTPUT_EXE) {
	ਅਚਲ ਅੱਖਰ *name = s1->install_name ? s1->install_name : filename;
        i = (ਆਕਾਰ(*dylib) + ਲੜੀ_ਲੰਬਾਈ(name) + 1 + 7) &-8;
        dylib = ਜੋੜੋ_lc(mo, LC_ID_DYLIB, i);
	dylib->name = ਆਕਾਰ(*dylib);
	dylib->timestamp = 1;
	dylib->current_ਸੰਸਕਰਣ =
	    s1->current_ਸੰਸਕਰਣ ? s1->current_ਸੰਸਕਰਣ : 1 << 16;
	dylib->compatibility_ਸੰਸਕਰਣ =
	    s1->compatibility_ਸੰਸਕਰਣ ? s1->compatibility_ਸੰਸਕਰਣ : 1 << 16;
        str = (ਅੱਖਰ*)dylib + dylib->name;
        strcpy(str, name);
    }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_NEW_MACHO
    chained_fixups_lc = ਜੋੜੋ_lc(mo, LC_DYLD_CHAINED_FIXUPS,
			       ਆਕਾਰ(ਬਣਤਰ linkedit_ਅੰਕੜੇ_command));
    export_trie_lc = ਜੋੜੋ_lc(mo, LC_DYLD_EXPORTS_TRIE,
			    ਆਕਾਰ(ਬਣਤਰ linkedit_ਅੰਕੜੇ_command));
#ਨਹੀਂਤਾਂ
    mo->dyldinfo = ਜੋੜੋ_lc(mo, LC_DYLD_INFO_ONLY, ਆਕਾਰ(*mo->dyldinfo));
#ਜੇ_ਅੰਤ

    symlc = ਜੋੜੋ_lc(mo, LC_SYMTAB, ਆਕਾਰ(*symlc));
    dysymlc = ਜੋੜੋ_lc(mo, LC_DYSYMTAB, ਆਕਾਰ(*dysymlc));

    ਜੇ (s1->output_type == TCC_OUTPUT_EXE) {
        i = (ਆਕਾਰ(*dyldlc) + ਲੜੀ_ਲੰਬਾਈ("/usr/lib/dyld") + 1 + 7) &-8;
        dyldlc = ਜੋੜੋ_lc(mo, LC_ਲੱਦੋ_DYLINKER, i);
        dyldlc->name = ਆਕਾਰ(*dyldlc);
        str = (ਅੱਖਰ*)dyldlc + dyldlc->name;
        strcpy(str, "/usr/lib/dyld");
    }

    dyldbv = ਜੋੜੋ_lc(mo, LC_BUILD_ਸੰਸਕਰਣ, ਆਕਾਰ(*dyldbv));
    dyldbv->platform = PLATFORM_MACOS;
    dyldbv->minos = (10 << 16) + (6 << 8);
    dyldbv->sdk = (10 << 16) + (6 << 8);
    dyldbv->ntools = 0;

    dyldsv = ਜੋੜੋ_lc(mo, LC_ਸਰੋਤ_ਸੰਸਕਰਣ, ਆਕਾਰ(*dyldsv));
    dyldsv->ਸੰਸਕਰਣ = 0;

    ਜੇ (s1->output_type == TCC_OUTPUT_EXE) {
        mo->ep = ਜੋੜੋ_lc(mo, LC_MAIN, ਆਕਾਰ(*mo->ep));
        mo->ep->entryoff = 4096;
    }

    ਲਈ(i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *dllref = s1->loaded_dlls[i];
        ਜੇ (dllref->level == 0)
          ਜੋੜੋ_dylib(mo, dllref->name);
    }

    ਜੇ (s1->rpath) {
	ਅੱਖਰ *ਰਸਤਾ = s1->rpath, *ਸਿਰਾ;
	ਕਰੋ {
	    ਸਿਰਾ = strchr(ਰਸਤਾ, ':');
	    ਜੇ (!ਸਿਰਾ)
		ਸਿਰਾ = strchr(ਰਸਤਾ, 0);
            i = (ਆਕਾਰ(*rpath) + (ਸਿਰਾ - ਰਸਤਾ) + 1 + 7) &-8;
            rpath = ਜੋੜੋ_lc(mo, LC_RPATH, i);
            rpath->ਰਸਤਾ = ਆਕਾਰ(*rpath);
            str = (ਅੱਖਰ*)rpath + rpath->ਰਸਤਾ;
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(str, ਰਸਤਾ, ਸਿਰਾ - ਰਸਤਾ);
	    str[ਸਿਰਾ - ਰਸਤਾ] = 0;
	    ਰਸਤਾ = ਸਿਰਾ + 1;
	} ਜਦੋਂ (*ਸਿਰਾ);
    }

    fileofs = 4096;  /* leave space for mach-o headers */
    curaddr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;
    curaddr += 4096;
    seg = ਨਿਰਾ;
    numsec = 0;
    mo->elfsectomacho = tcc_mallocz(ਆਕਾਰ(*mo->elfsectomacho) * s1->nb_sections);
    ਲਈ (sk = sk_unknown; sk < sk_ਆਖਰੀ; sk++) {
        ਬਣਤਰ section_64 *sec = ਨਿਰਾ;
        ਜੇ (seg) {
            seg->vmsize = curaddr - seg->vmaddr;
            seg->filesize = fileofs - seg->fileoff;
        }
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_NEW_MACHO
	ਜੇ (sk == sk_linkedit) {
	    calc_fixup_ਮਾਪ(s1, mo);
	    export_trie(s1, mo);
	}
#ਨਹੀਂਤਾਂ
	ਜੇ (sk == sk_linkedit) {
	    bind_rebase(s1, mo);
	    export_trie(s1, mo);
	}
#ਜੇ_ਅੰਤ
        ਜੇ (skinfo[sk].seg_initial &&
	    (s1->output_type != TCC_OUTPUT_EXE || mo->segment[sk]) &&
	    mo->sk_ਮੰਜ਼ਿਲ_sect[sk].s) {
            uint64_t al = 0;
            ਪੂਰਨ si;
            seg = get_segment(mo, mo->segment[sk]);
            ਜੇ (skinfo[sk].name) {
                si = ਜੋੜੋ_section(mo, &seg, skinfo[sk].name);
                numsec++;
                mo->lc[mo->seg2lc[mo->segment[sk]]] = (ਬਣਤਰ ਲੱਦੋ_command*)seg;
                mo->sk_ਮੰਜ਼ਿਲ_sect[sk].machosect = si;
                sec = get_section(seg, si);
                sec->flags = skinfo[sk].flags;
		ਜੇ (sk == sk_stubs)
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
	    	    sec->reserved2 = 6;
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
	    	    sec->reserved2 = 12;
#ਜੇ_ਅੰਤ
		ਜੇ (sk == sk_nl_ptr)
	    	    sec->reserved1 = mo->nr_plt;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_NEW_MACHO
		ਜੇ (sk == sk_la_ptr)
	    	    sec->reserved1 = mo->nr_plt + mo->n_got;
#ਜੇ_ਅੰਤ
            }
            ਜੇ (seg->vmaddr == -1) {
                curaddr = (curaddr + SEG_ਪੰਨਾ_ਮਾਪ - 1) & -SEG_ਪੰਨਾ_ਮਾਪ;
                seg->vmaddr = curaddr;
                fileofs = (fileofs + SEG_ਪੰਨਾ_ਮਾਪ - 1) & -SEG_ਪੰਨਾ_ਮਾਪ;
                seg->fileoff = fileofs;
            }

            ਲਈ (s = mo->sk_ਮੰਜ਼ਿਲ_sect[sk].s; s; s = s->prev) {
                ਪੂਰਨ a = exact_log2p1(s->sh_addralign);
                ਜੇ (a && al < (a - 1))
                  al = a - 1;
                s->sh_ਮਾਪ = s->ਅੰਕੜੇ_ਵਿੱਥ;
            }
            ਜੇ (sec)
              sec->align = al;
            al = 1ULL << al;
            ਜੇ (al > 4096)
              tcc_warning("alignment > 4096"), sec->align = 12, al = 4096;
            curaddr = (curaddr + al - 1) & -al;
            fileofs = (fileofs + al - 1) & -al;
            ਜੇ (sec) {
                sec->addr = curaddr;
                sec->ਵਿੱਥ = fileofs;
            }
            ਲਈ (s = mo->sk_ਮੰਜ਼ਿਲ_sect[sk].s; s; s = s->prev) {
                al = s->sh_addralign;
                curaddr = (curaddr + al - 1) & -al;
                dprintf("%s: curaddr now 0x%lx\n", s->name, (ਲੰਮਾ)curaddr);
                s->sh_addr = curaddr;
                curaddr += s->sh_ਮਾਪ;
                ਜੇ (s->sh_type != SHT_NOBITS) {
                    fileofs = (fileofs + al - 1) & -al;
                    s->sh_ਵਿੱਥ = fileofs;
                    fileofs += s->sh_ਮਾਪ;
                    dprintf("%s: fileofs now %ld\n", s->name, (ਲੰਮਾ)fileofs);
                }
                ਜੇ (sec)
                  mo->elfsectomacho[s->sh_ਅੰਕ] = numsec;
            }
            ਜੇ (sec)
              sec->ਮਾਪ = curaddr - sec->addr;
        }
        ਜੇ (DEBUG_MACHO)
          ਲਈ (s = mo->sk_ਮੰਜ਼ਿਲ_sect[sk].s; s; s = s->prev) {
              ਪੂਰਨ type = s->sh_type;
              ਪੂਰਨ flags = s->sh_flags;
              ਲਿਖੋ("%d section %-16s %-10s %09lx %04x %02d %s,%s,%s\n",
                     sk,
                     s->name,
                     type == SHT_PROGBITS ? "progbits" :
                     type == SHT_NOBITS ? "nobits" :
                     type == SHT_SYMTAB ? "symtab" :
                     type == SHT_STRTAB ? "strtab" :
                     type == SHT_INIT_ARRAY ? "init" :
                     type == SHT_FINI_ARRAY ? "fini" :
                     type == SHT_RELX ? "rel" : "???",
                     (ਲੰਮਾ)s->sh_addr,
                     (ਬਿਨਾਨਿਸ਼ਾਨੀ)s->ਅੰਕੜੇ_ਵਿੱਥ,
                     s->sh_addralign,
                     flags & SHF_ALLOC ? "alloc" : "",
                     flags & SHF_WRITE ? "write" : "",
                     flags & SHF_EXECINSTR ? "exec" : ""
                    );
          }
    }
    ਜੇ (seg) {
        seg->vmsize = curaddr - seg->vmaddr;
        seg->filesize = fileofs - seg->fileoff;
    }

    /* Fill symtab info */
    symlc->symoff = mo->symtab->sh_ਵਿੱਥ;
    symlc->nsyms = mo->symtab->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ(ਬਣਤਰ nlist_64);
    symlc->stroff = mo->strtab->sh_ਵਿੱਥ;
    symlc->strsize = mo->strtab->ਅੰਕੜੇ_ਵਿੱਥ;

    dysymlc->iundefsym = mo->iundef == -1 ? symlc->nsyms : mo->iundef;
    dysymlc->iextdefsym = mo->iextdef == -1 ? dysymlc->iundefsym : mo->iextdef;
    dysymlc->ilocalsym = mo->ilocal == -1 ? dysymlc->iextdefsym : mo->ilocal;
    dysymlc->nlocalsym = dysymlc->iextdefsym - dysymlc->ilocalsym;
    dysymlc->nextdefsym = dysymlc->iundefsym - dysymlc->iextdefsym;
    dysymlc->nundefsym = symlc->nsyms - dysymlc->iundefsym;
    dysymlc->indirectsymoff = mo->indirsyms->sh_ਵਿੱਥ;
    dysymlc->nindirectsyms = mo->indirsyms->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ(uint32_t);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_NEW_MACHO
    ਜੇ (mo->chained_fixups->ਅੰਕੜੇ_ਵਿੱਥ) {
        chained_fixups_lc->dataoff = mo->chained_fixups->sh_ਵਿੱਥ;
        chained_fixups_lc->datasize = mo->chained_fixups->ਅੰਕੜੇ_ਵਿੱਥ;
    }
    ਜੇ (mo->exports->ਅੰਕੜੇ_ਵਿੱਥ) {
        export_trie_lc->dataoff = mo->exports->sh_ਵਿੱਥ;
        export_trie_lc->datasize = mo->exports->ਅੰਕੜੇ_ਵਿੱਥ;
    }
#ਨਹੀਂਤਾਂ
    ਜੇ (mo->rebase->ਅੰਕੜੇ_ਵਿੱਥ) {
        mo->dyldinfo->rebase_off = mo->rebase->sh_ਵਿੱਥ;
        mo->dyldinfo->rebase_ਮਾਪ = mo->rebase->ਅੰਕੜੇ_ਵਿੱਥ;
    }
    ਜੇ (mo->binding->ਅੰਕੜੇ_ਵਿੱਥ) {
        mo->dyldinfo->bind_off = mo->binding->sh_ਵਿੱਥ;
        mo->dyldinfo->bind_ਮਾਪ = mo->binding->ਅੰਕੜੇ_ਵਿੱਥ;
    }
    ਜੇ (mo->weak_binding->ਅੰਕੜੇ_ਵਿੱਥ) {
        mo->dyldinfo->weak_bind_off = mo->weak_binding->sh_ਵਿੱਥ;
        mo->dyldinfo->weak_bind_ਮਾਪ = mo->weak_binding->ਅੰਕੜੇ_ਵਿੱਥ;
    }
    ਜੇ (mo->lazy_binding->ਅੰਕੜੇ_ਵਿੱਥ) {
        mo->dyldinfo->lazy_bind_off = mo->lazy_binding->sh_ਵਿੱਥ;
        mo->dyldinfo->lazy_bind_ਮਾਪ = mo->lazy_binding->ਅੰਕੜੇ_ਵਿੱਥ;
    }
    ਜੇ (mo->exports->ਅੰਕੜੇ_ਵਿੱਥ) {
        mo->dyldinfo->export_off = mo->exports->sh_ਵਿੱਥ;
        mo->dyldinfo->export_ਮਾਪ = mo->exports->ਅੰਕੜੇ_ਵਿੱਥ;
    }
#ਜੇ_ਅੰਤ
}

ਸਥਿਰ ਖਾਲੀ macho_write(TCCState *s1, ਬਣਤਰ macho *mo, FILE *fp)
{
    ਪੂਰਨ i, sk;
    uint64_t fileofs = 0;
    Section *s;
    mo->mh.mh.magic = MH_MAGIC_64;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    mo->mh.mh.cputype = CPU_TYPE_X86_64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_LIB64 | CPU_SUBTYPE_X86_ALL;
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
    mo->mh.mh.cputype = CPU_TYPE_ARM64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_ARM64_ALL;
#ਜੇ_ਅੰਤ
    ਜੇ (s1->output_type == TCC_OUTPUT_EXE) {
        mo->mh.mh.filetype = MH_EXECUTE;
        mo->mh.mh.flags = MH_DYLDLINK | MH_PIE;
    }
    ਨਹੀਂਤਾਂ {
        mo->mh.mh.filetype = MH_DYLIB;
        mo->mh.mh.flags = MH_DYLDLINK;
    }
    mo->mh.mh.ncmds = mo->nlc;
    mo->mh.mh.sizeofcmds = 0;
    ਲਈ (i = 0; i < mo->nlc; i++)
      mo->mh.mh.sizeofcmds += mo->lc[i]->cmdsize;

    fwrite(&mo->mh, 1, ਆਕਾਰ(mo->mh), fp);
    fileofs += ਆਕਾਰ(mo->mh);
    ਲਈ (i = 0; i < mo->nlc; i++) {
        fwrite(mo->lc[i], 1, mo->lc[i]->cmdsize, fp);
        fileofs += mo->lc[i]->cmdsize;
    }

    ਲਈ (sk = sk_unknown; sk < sk_ਆਖਰੀ; sk++) {
        //struct segment_command_64 *seg;
        ਜੇ (skinfo[sk].seg_initial == 0 ||
	    (s1->output_type == TCC_OUTPUT_EXE && !mo->segment[sk]) ||
	    !mo->sk_ਮੰਜ਼ਿਲ_sect[sk].s)
          ਜਾਰੀ;
        /*seg =*/ get_segment(mo, mo->segment[sk]);
        ਲਈ (s = mo->sk_ਮੰਜ਼ਿਲ_sect[sk].s; s; s = s->prev) {
            ਜੇ (s->sh_type != SHT_NOBITS) {
                ਜਦੋਂ (fileofs < s->sh_ਵਿੱਥ)
                  fputc(0, fp), fileofs++;
                ਜੇ (s->sh_ਮਾਪ) {
                    fwrite(s->ਅੰਕੜੇ, 1, s->sh_ਮਾਪ, fp);
                    fileofs += s->sh_ਮਾਪ;
                }
            }
        }
    }
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_NEW_MACHO
ਸਥਿਰ ਪੂਰਨ bind_rebase_cmp(ਅਚਲ ਖਾਲੀ *_a, ਅਚਲ ਖਾਲੀ *_b, ਖਾਲੀ *arg)
{
    TCCState *s1 = arg;
    ਬਣਤਰ bind_rebase *a = (ਬਣਤਰ bind_rebase *) _a;
    ਬਣਤਰ bind_rebase *b = (ਬਣਤਰ bind_rebase *) _b;
    addr_t aa = s1->sections[a->section]->sh_addr + a->rel.r_ਵਿੱਥ;
    addr_t ab = s1->sections[b->section]->sh_addr + b->rel.r_ਵਿੱਥ;

    ਵਾਪਸ aa > ab ? 1 : aa < ab ? -1 : 0;
}

ST_FUNC ਖਾਲੀ bind_rebase_import(TCCState *s1, ਬਣਤਰ macho *mo)
{
    ਪੂਰਨ i, j, k, bind_ਸੂਚਕਾਂਕ, ਮਾਪ, ਪੰਨਾ_ਗਿਣਤੀ, sym_ਸੂਚਕਾਂਕ;
    ਅਚਲ ਅੱਖਰ *name;
    ElfW(Sym) *sym;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ਅੰਕੜੇ = mo->chained_fixups->ਅੰਕੜੇ;
    ਬਣਤਰ segment_command_64 *seg;
    ਬਣਤਰ dyld_chained_fixups_ਸਿਰਲੇਖ *ਸਿਰਲੇਖ;
    ਬਣਤਰ dyld_chained_starts_ਵਿੱਚ_image *image;
    ਬਣਤਰ dyld_chained_starts_ਵਿੱਚ_segment *segment;
    ਬਣਤਰ dyld_chained_import *import;

    tcc_qsort(mo->bind_rebase, mo->n_bind_rebase, ਆਕਾਰ(ਬਣਤਰ bind_rebase),
	      bind_rebase_cmp, s1);
    ਲਈ (i = 0; i < mo->n_bind_rebase - 1; i++)
	ਜੇ (mo->bind_rebase[i].section == mo->bind_rebase[i + 1].section &&
	    mo->bind_rebase[i].rel.r_ਵਿੱਥ == mo->bind_rebase[i + 1].rel.r_ਵਿੱਥ) {
	    sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
            sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
	    name = (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name;
	    tcc_error("Overlap %s/%s %s:%s",
		      mo->bind_rebase[i].bind ? "bind" : "rebase",
		      mo->bind_rebase[i + 1].bind ? "bind" : "rebase",
		      s1->sections[mo->bind_rebase[i].section]->name, name);
	}
    ਸਿਰਲੇਖ = (ਬਣਤਰ dyld_chained_fixups_ਸਿਰਲੇਖ *) ਅੰਕੜੇ;
    ਅੰਕੜੇ += (ਆਕਾਰ(ਬਣਤਰ dyld_chained_fixups_ਸਿਰਲੇਖ) + 7) & -8;
    ਸਿਰਲੇਖ->starts_ਵਿੱਥ = ਅੰਕੜੇ - mo->chained_fixups->ਅੰਕੜੇ;
    ਸਿਰਲੇਖ->imports_ਗਿਣਤੀ = mo->n_bind;
    ਸਿਰਲੇਖ->imports_format = DYLD_CHAINED_IMPORT;
    ਸਿਰਲੇਖ->symbols_format = 0;
    ਮਾਪ = ਆਕਾਰ(ਬਣਤਰ dyld_chained_starts_ਵਿੱਚ_image) +
	   (mo->nseg - 1) * ਆਕਾਰ(uint32_t);
    image = (ਬਣਤਰ dyld_chained_starts_ਵਿੱਚ_image *) ਅੰਕੜੇ;
    ਅੰਕੜੇ += (ਮਾਪ + 7) & -8;
    image->seg_ਗਿਣਤੀ = mo->nseg;
    ਲਈ (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
        image->seg_info_ਵਿੱਥ[i] = (ਅੰਕੜੇ - mo->chained_fixups->ਅੰਕੜੇ) -
				    ਸਿਰਲੇਖ->starts_ਵਿੱਥ;
	seg = get_segment(mo, i);
	ਪੰਨਾ_ਗਿਣਤੀ = (seg->vmsize + SEG_ਪੰਨਾ_ਮਾਪ - 1) / SEG_ਪੰਨਾ_ਮਾਪ;
	ਮਾਪ = ਆਕਾਰ(ਬਣਤਰ dyld_chained_starts_ਵਿੱਚ_segment) +
		      (ਪੰਨਾ_ਗਿਣਤੀ - 1) * ਆਕਾਰ(uint16_t);
        segment = (ਬਣਤਰ dyld_chained_starts_ਵਿੱਚ_segment *) ਅੰਕੜੇ;
        ਅੰਕੜੇ += (ਮਾਪ + 7) & -8;
        segment->ਮਾਪ = ਮਾਪ;
        segment->ਪੰਨਾ_ਮਾਪ = SEG_ਪੰਨਾ_ਮਾਪ;
#ਜੇ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	PTR_64_ਵਿੱਥ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	PTR_64_ਨਕਾਬ   0x7FFFFFFFFFFULL
        segment->ਸੂਚਕ_format = DYLD_CHAINED_PTR_64;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	PTR_64_ਵਿੱਥ 0x100000000ULL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	PTR_64_ਨਕਾਬ   0xFFFFFFFFFFFFFFULL
        segment->ਸੂਚਕ_format = DYLD_CHAINED_PTR_64_ਵਿੱਥ;
#ਜੇ_ਅੰਤ
        segment->segment_ਵਿੱਥ = seg->fileoff;
        segment->max_valid_ਸੂਚਕ = 0;
        segment->ਪੰਨਾ_ਗਿਣਤੀ = ਪੰਨਾ_ਗਿਣਤੀ;
	// add bind/rebase
	bind_ਸੂਚਕਾਂਕ = 0;
	k = 0;
	ਲਈ (j = 0; j < ਪੰਨਾ_ਗਿਣਤੀ; j++) {
	    addr_t ਸ਼ੁਰੂ = seg->vmaddr + j * SEG_ਪੰਨਾ_ਮਾਪ;
	    addr_t ਸਿਰਾ = ਸ਼ੁਰੂ + SEG_ਪੰਨਾ_ਮਾਪ;
	    ਖਾਲੀ *ਆਖਰੀ = ਨਿਰਾ;
	    addr_t ਆਖਰੀ_o = 0;
	    addr_t cur_o, cur;
	    ਬਣਤਰ dyld_chained_ptr_64_rebase *rebase;
	    ਬਣਤਰ dyld_chained_ptr_64_bind *bind;

	    segment->ਪੰਨਾ_ਸ਼ੁਰੂ[j] = DYLD_CHAINED_PTR_ਸ਼ੁਰੂ_NONE;
	    ਲਈ (; k < mo->n_bind_rebase; k++) {
	        Section *s = s1->sections[mo->bind_rebase[k].section];
		addr_t r_ਵਿੱਥ = mo->bind_rebase[k].rel.r_ਵਿੱਥ;
		addr_t addr = s->sh_addr + r_ਵਿੱਥ;

		ਜੇ ((addr & 3) ||
		    (addr & (SEG_ਪੰਨਾ_ਮਾਪ - 1)) > SEG_ਪੰਨਾ_ਮਾਪ - PTR_ਮਾਪ)
		    tcc_error("Illegal rel_offset %s %lld",
			      s->name, (ਲੰਮਾ ਲੰਮਾ)r_ਵਿੱਥ);
		ਜੇ (addr >= ਸਿਰਾ)
		    ਰੋਕੋ;
		ਜੇ (addr >= ਸ਼ੁਰੂ) {
		    cur_o = addr - ਸ਼ੁਰੂ;
	            ਜੇ (mo->bind_rebase[k].bind) {
		        ਜੇ (segment->ਪੰਨਾ_ਸ਼ੁਰੂ[j] == DYLD_CHAINED_PTR_ਸ਼ੁਰੂ_NONE)
			    segment->ਪੰਨਾ_ਸ਼ੁਰੂ[j] = cur_o;
		        ਨਹੀਂਤਾਂ {
			    bind = (ਬਣਤਰ dyld_chained_ptr_64_bind *) ਆਖਰੀ;
			    bind->ਅਗਲਾ = (cur_o - ਆਖਰੀ_o) / 4;
		        }
		        bind = (ਬਣਤਰ dyld_chained_ptr_64_bind *)
				    (s->ਅੰਕੜੇ + r_ਵਿੱਥ);
		        ਆਖਰੀ = bind;
		        ਆਖਰੀ_o = cur_o;
		        bind->ordinal = bind_ਸੂਚਕਾਂਕ;
		        bind->addend = 0;
		        bind->reserved = 0;
		        bind->ਅਗਲਾ = 0;
		        bind->bind = 1;
		    }
		    ਨਹੀਂਤਾਂ {
		        ਜੇ (segment->ਪੰਨਾ_ਸ਼ੁਰੂ[j] == DYLD_CHAINED_PTR_ਸ਼ੁਰੂ_NONE)
			    segment->ਪੰਨਾ_ਸ਼ੁਰੂ[j] = cur_o;
		        ਨਹੀਂਤਾਂ {
			    rebase = (ਬਣਤਰ dyld_chained_ptr_64_rebase *) ਆਖਰੀ;
			    rebase->ਅਗਲਾ = (cur_o - ਆਖਰੀ_o) / 4;
		        }
		        rebase = (ਬਣਤਰ dyld_chained_ptr_64_rebase *)
				    (s->ਅੰਕੜੇ + r_ਵਿੱਥ);
		        ਆਖਰੀ = rebase;
		        ਆਖਰੀ_o = cur_o;
		        cur = (*(uint64_t *) (s->ਅੰਕੜੇ + r_ਵਿੱਥ)) -
			      PTR_64_ਵਿੱਥ;
		        rebase->ਨਿਸ਼ਾਨਾ = cur & PTR_64_ਨਕਾਬ;
		        rebase->high8 = cur >> (64 - 8);
			ਜੇ (cur != ((uint64_t)rebase->high8 << (64 - 8)) + rebase->ਨਿਸ਼ਾਨਾ)
			    tcc_error("rebase error");
		        rebase->reserved = 0;
		        rebase->ਅਗਲਾ = 0;
		        rebase->bind = 0;
		    }
		}
		bind_ਸੂਚਕਾਂਕ += mo->bind_rebase[k].bind;
	    }
	}
    }
    // add imports
    ਸਿਰਲੇਖ->imports_ਵਿੱਥ = ਅੰਕੜੇ - mo->chained_fixups->ਅੰਕੜੇ;
    import = (ਬਣਤਰ dyld_chained_import *) ਅੰਕੜੇ;
    ਅੰਕੜੇ += mo->n_bind * ਆਕਾਰ (ਬਣਤਰ dyld_chained_import);
    ਸਿਰਲੇਖ->symbols_ਵਿੱਥ = ਅੰਕੜੇ - mo->chained_fixups->ਅੰਕੜੇ;
    ਅੰਕੜੇ++;
    ਲਈ (i = 0, bind_ਸੂਚਕਾਂਕ = 0; i < mo->n_bind_rebase; i++) {
	ਜੇ (mo->bind_rebase[i].bind) {
	    import[bind_ਸੂਚਕਾਂਕ].lib_ordinal =
		BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xffu;
	    import[bind_ਸੂਚਕਾਂਕ].name_ਵਿੱਥ =
		(ਅੰਕੜੇ - mo->chained_fixups->ਅੰਕੜੇ) - ਸਿਰਲੇਖ->symbols_ਵਿੱਥ;
	    sym_ਸੂਚਕਾਂਕ = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    sym = &((ElfW(Sym) *)symtab_section->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
	    import[bind_ਸੂਚਕਾਂਕ].weak_import =
		ELFW(ST_BIND)(sym->st_info) == STB_WEAK;
	    name = (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + sym->st_name;
            strcpy((ਅੱਖਰ *) ਅੰਕੜੇ, name);
	    ਅੰਕੜੇ += ਲੜੀ_ਲੰਬਾਈ(name) + 1;
	    bind_ਸੂਚਕਾਂਕ++;
	}
    }
    tcc_free(mo->bind_rebase);
}
#ਜੇ_ਅੰਤ

ST_FUNC ਪੂਰਨ macho_output_file(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename)
{
    ਪੂਰਨ fd, ਬਹੁਲਕ, file_type;
    FILE *fp;
    ਪੂਰਨ i, ret = -1;
    ਬਣਤਰ macho mo;

    (ਖਾਲੀ)memset(&mo, 0, ਆਕਾਰ(mo));

    file_type = s1->output_type;
    ਜੇ (file_type == TCC_OUTPUT_OBJ)
        ਬਹੁਲਕ = 0666;
    ਨਹੀਂਤਾਂ
        ਬਹੁਲਕ = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_ਦੁਆਧਾਰੀ_2, ਬਹੁਲਕ);
    ਜੇ (fd < 0 || (fp = fdopen(fd, "wb")) == ਨਿਰਾ) {
        tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
        ਵਾਪਸ -1;
    }
    tcc_ਜੋੜੋ_runtime(s1);
    tcc_macho_ਜੋੜੋ_destructor(s1);
    resolve_common_syms(s1);
    create_symtab(s1, &mo);
    check_relocs(s1, &mo);
    ret = check_symbols(s1, &mo);
    ਜੇ (!ret) {
	ਪੂਰਨ save_output = s1->output_type;

        collect_sections(s1, &mo, filename);
        relocate_syms(s1, s1->symtab, 0);
	ਜੇ (s1->output_type == TCC_OUTPUT_EXE)
            mo.ep->entryoff = get_sym_addr(s1, "main", 1, 1)
                            -     get_segment(&mo, 1)->vmaddr;
        ਜੇ (s1->nb_errors)
          ਜਾਓ do_ret;
	// Macho uses bind/rebase instead of dynsym
	s1->output_type = TCC_OUTPUT_EXE;
        relocate_sections(s1);
	s1->output_type = save_output;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_NEW_MACHO
	bind_rebase_import(s1, &mo);
#ਜੇ_ਅੰਤ
        convert_symbols(s1, &mo);
        ਜੇ (s1->verbose)
            ਲਿਖੋ("<- %s\n", filename);
        macho_write(s1, &mo, fp);
    }

 do_ret:
    ਲਈ (i = 0; i < mo.nlc; i++)
      tcc_free(mo.lc[i]);
    tcc_free(mo.seg2lc);
    tcc_free(mo.lc);
    tcc_free(mo.elfsectomacho);
    tcc_free(mo.e2msym);

    fclose(fp);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_CODESIGN
    ਜੇ (!ret) {
	ਅੱਖਰ command[1024];
	ਪੂਰਨ retval;

	snprintf(command, ਆਕਾਰ(command), "codesign -f -s - %s", filename);
	retval = system (command);
	ਜੇ (retval == -1 || !(WIFEXITED(retval) && WEXITSTATUS(retval) == 0))
	    tcc_error ("command failed '%s'", command);
    }
#ਜੇ_ਅੰਤ
    ਵਾਪਸ ret;
}

ਸਥਿਰ uint32_t macho_swap32(uint32_t x)
{
  ਵਾਪਸ (x >> 24) | (x << 24) | ((x >> 8) & 0xff00) | ((x & 0xff00) << 8);
}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਅਦਲਾ_ਬਦਲੀ(x) (ਅਦਲਾ_ਬਦਲੀ_2 ? macho_swap32(x) : (x))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tbd_parse_movepast(s) \
    (pos = (pos = ਲੜੀ_ਖੋਜ(pos, s)) ? pos + ਲੜੀ_ਲੰਬਾਈ(s) : ਨਿਰਾ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tbd_parse_movetoany(cs) (pos = strpbrk(pos, cs))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tbd_parse_skipws ਜਦੋਂ (*pos && (*pos==' '||*pos=='\n')) ++pos
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tbd_parse_tramplequote ਜੇ(*pos=='\''||*pos=='"') tbd_parse_trample
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tbd_parse_tramplespace ਜੇ(*pos==' ') tbd_parse_trample
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tbd_parse_trample *pos++=0

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
/* Looks for the active developer SDK set by xcode-select (or the default
   one set during installation.) */
ST_FUNC ਖਾਲੀ tcc_ਜੋੜੋ_macos_sdkpath(TCCState* s)
{
    ਅੱਖਰ *sdkroot = ਨਿਰਾ, *pos = ਨਿਰਾ;
    ਖਾਲੀ* xcs = dlopen("libxcselect.dylib", RTLD_GLOBAL | RTLD_LAZY);
    CString ਰਸਤਾ;
    ਪੂਰਨ (*f)(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ, ਅੱਖਰ**) = dlsym(xcs, "xcselect_host_sdk_path");
    cstr_new(&ਰਸਤਾ);
    ਜੇ (f) f(1, &sdkroot);
    ਜੇ (sdkroot)
        pos = ਲੜੀ_ਖੋਜ(sdkroot,"SDKs/MacOSX");
    ਜੇ (pos)
        cstr_printf(&ਰਸਤਾ, "%.*s.sdk/usr/lib", (ਪੂਰਨ)(pos - sdkroot + 11), sdkroot);
    /* must use free from libc directly */
#ਹਦਾਇਤ ਧੱਕੋ_macro("free")
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ ਮੁਕਤ
    ਮੁਕਤ(sdkroot);
#ਹਦਾਇਤ ਕੱਢੋ_macro("free")
    ਜੇ (ਰਸਤਾ.ਮਾਪ)
        tcc_ਜੋੜੋ_library_ਰਸਤਾ(s, (ਅੱਖਰ*)ਰਸਤਾ.ਅੰਕੜੇ);
    ਨਹੀਂਤਾਂ
        tcc_ਜੋੜੋ_library_ਰਸਤਾ(s,
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib"
            ":" "/Applications/Xcode.app/Developer/SDKs/MacOSX.sdk/usr/lib"
            );
    cstr_free(&ਰਸਤਾ);
}

ST_FUNC ਅੱਖਰ* macho_tbd_soname(ਪੂਰਨ fd) {
    ਅੱਖਰ *soname, *ਅੰਕੜੇ, *pos;
    ਅੱਖਰ *ret = 0;
    pos = ਅੰਕੜੇ = tcc_ਲੱਦੋ_ਪਾਠ(fd);
    ਜੇ (!tbd_parse_movepast("install-name: ")) ਜਾਓ the_ਸਿਰਾ;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    ਜੇ (!tbd_parse_movetoany("\n \"'")) ਜਾਓ the_ਸਿਰਾ;
    tbd_parse_trample;
    ret = tcc_strdup(soname);
the_ਸਿਰਾ:
    tcc_free(ਅੰਕੜੇ);
    ਵਾਪਸ ret;
}
#ਜੇ_ਅੰਤ /* TCC_IS_NATIVE */

ST_FUNC ਪੂਰਨ macho_ਲੱਦੋ_tbd(TCCState* s1, ਪੂਰਨ fd, ਅਚਲ ਅੱਖਰ* filename, ਪੂਰਨ lev)
{
    ਅੱਖਰ *soname, *ਅੰਕੜੇ, *pos;
    ਪੂਰਨ ret = -1;

    pos = ਅੰਕੜੇ = tcc_ਲੱਦੋ_ਪਾਠ(fd);
    ਜੇ (!tbd_parse_movepast("install-name: ")) ਜਾਓ the_ਸਿਰਾ;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    ਜੇ (!tbd_parse_movetoany("\n \"'")) ਜਾਓ the_ਸਿਰਾ;
    tbd_parse_trample;
    ret = 0;
    ਜੇ (tcc_ਜੋੜੋ_dllref(s1, soname, lev)->ਮਿਲਿਆ)
        ਜਾਓ the_ਸਿਰਾ;
    ਜਦੋਂ(pos) {
        ਅੱਖਰ* sym = ਨਿਰਾ;
        ਪੂਰਨ cont = 1;
        ਜੇ (!tbd_parse_movepast("symbols: ")) ਰੋਕੋ;
        ਜੇ (!tbd_parse_movepast("[")) ਰੋਕੋ;
        ਜਦੋਂ (cont) {
            tbd_parse_skipws;
            tbd_parse_tramplequote;
            sym = pos;
            ਜੇ (!tbd_parse_movetoany(",] \"'")) ਰੋਕੋ;
            tbd_parse_tramplequote;
            tbd_parse_tramplespace;
            tbd_parse_skipws;
            ਜੇ (*pos==0||*pos==']') cont=0;
            tbd_parse_trample;
            ਸੈੱਟ_elf_sym(s1->dynsymtab_section, 0, 0,
                ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0, SHN_UNDEF, sym);
        }
    }

the_ਸਿਰਾ:
    tcc_free(ਅੰਕੜੇ);
    ਵਾਪਸ ret;
}

ST_FUNC ਪੂਰਨ macho_ਲੱਦੋ_dll(TCCState * s1, ਪੂਰਨ fd, ਅਚਲ ਅੱਖਰ* filename, ਪੂਰਨ lev)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ buf[ਆਕਾਰ(ਬਣਤਰ mach_ਸਿਰਲੇਖ_64)];
    ਖਾਲੀ *buf2;
    uint32_t machofs = 0;
    ਬਣਤਰ fat_ਸਿਰਲੇਖ fh;
    ਬਣਤਰ mach_ਸਿਰਲੇਖ mh;
    ਬਣਤਰ ਲੱਦੋ_command *lc;
    ਪੂਰਨ i, ਅਦਲਾ_ਬਦਲੀ_2 = 0;
    ਅਚਲ ਅੱਖਰ *soname = filename;
    ਬਣਤਰ nlist_64 *symtab = 0;
    uint32_t nsyms = 0;
    ਅੱਖਰ *strtab = 0;
    uint32_t strsize = 0;
    uint32_t iextdef = 0;
    uint32_t nextdef = 0;

  again:
    ਜੇ (ਭਰਿਆ_read(fd, buf, ਆਕਾਰ(buf)) != ਆਕਾਰ(buf))
      ਵਾਪਸ -1;
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(&fh, buf, ਆਕਾਰ(fh));
    ਜੇ (fh.magic == FAT_MAGIC || fh.magic == FAT_CIGAM) {
        ਬਣਤਰ fat_arch *fa = ਲੱਦੋ_ਅੰਕੜੇ(fd, ਆਕਾਰ(fh),
                                        fh.nfat_arch * ਆਕਾਰ(*fa));
        ਅਦਲਾ_ਬਦਲੀ_2 = fh.magic == FAT_CIGAM;
        ਲਈ (i = 0; i < ਅਦਲਾ_ਬਦਲੀ(fh.nfat_arch); i++)
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
          ਜੇ (ਅਦਲਾ_ਬਦਲੀ(fa[i].cputype) == CPU_TYPE_X86_64
              && ਅਦਲਾ_ਬਦਲੀ(fa[i].cpusubtype) == CPU_SUBTYPE_X86_ALL)
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
          ਜੇ (ਅਦਲਾ_ਬਦਲੀ(fa[i].cputype) == CPU_TYPE_ARM64
              && ਅਦਲਾ_ਬਦਲੀ(fa[i].cpusubtype) == CPU_SUBTYPE_ARM64_ALL)
#ਜੇ_ਅੰਤ
            ਰੋਕੋ;
        ਜੇ (i == ਅਦਲਾ_ਬਦਲੀ(fh.nfat_arch)) {
            tcc_free(fa);
            ਵਾਪਸ -1;
        }
        machofs = ਅਦਲਾ_ਬਦਲੀ(fa[i].ਵਿੱਥ);
        tcc_free(fa);
        lseek(fd, machofs, SEEK_SET);
        ਜਾਓ again;
    } ਨਹੀਂਤਾਂ ਜੇ (fh.magic == FAT_MAGIC_64 || fh.magic == FAT_CIGAM_64) {
        tcc_warning("%s: Mach-O fat 64bit files of type 0x%x not handled",
                    filename, fh.magic);
        ਵਾਪਸ -1;
    }

    ਸਮ੍ਰਿਤੀ_ਨਕਲ(&mh, buf, ਆਕਾਰ(mh));
    ਜੇ (mh.magic != MH_MAGIC_64)
      ਵਾਪਸ -1;
    dprintf("found Mach-O at %d\n", machofs);
    buf2 = ਲੱਦੋ_ਅੰਕੜੇ(fd, machofs + ਆਕਾਰ(ਬਣਤਰ mach_ਸਿਰਲੇਖ_64), mh.sizeofcmds);
    ਲਈ (i = 0, lc = buf2; i < mh.ncmds; i++) {
        dprintf("lc %2d: 0x%08x\n", i, lc->cmd);
        ਚੋਣ (lc->cmd) {
        ਹਾਲਤ LC_SYMTAB:
        {
            ਬਣਤਰ symtab_command *sc = (ਬਣਤਰ symtab_command*)lc;
            nsyms = sc->nsyms;
            symtab = ਲੱਦੋ_ਅੰਕੜੇ(fd, machofs + sc->symoff, nsyms * ਆਕਾਰ(*symtab));
            strsize = sc->strsize;
            strtab = ਲੱਦੋ_ਅੰਕੜੇ(fd, machofs + sc->stroff, strsize);
            ਰੋਕੋ;
        }
        ਹਾਲਤ LC_ID_DYLIB:
        {
            ਬਣਤਰ dylib_command *dc = (ਬਣਤਰ dylib_command*)lc;
            soname = (ਅੱਖਰ*)lc + dc->name;
            dprintf(" ID_DYLIB %d 0x%x 0x%x %s\n",
                    dc->timestamp, dc->current_ਸੰਸਕਰਣ,
                    dc->compatibility_ਸੰਸਕਰਣ, soname);
            ਰੋਕੋ;
        }
        ਹਾਲਤ LC_REEXPORT_DYLIB:
        {
            ਬਣਤਰ dylib_command *dc = (ਬਣਤਰ dylib_command*)lc;
            ਅੱਖਰ *name = (ਅੱਖਰ*)lc + dc->name;
            ਪੂਰਨ subfd = open(name, O_RDONLY | O_ਦੁਆਧਾਰੀ_2);
            dprintf(" REEXPORT %s\n", name);
            ਜੇ (subfd < 0)
              tcc_warning("can't open %s (reexported from %s)", name, filename);
            ਨਹੀਂਤਾਂ {
                /* Hopefully the REEXPORTs never form a cycle, we don't check
                   for that!  */
                macho_ਲੱਦੋ_dll(s1, subfd, name, lev + 1);
                close(subfd);
            }
            ਰੋਕੋ;
        }
        ਹਾਲਤ LC_DYSYMTAB:
        {
            ਬਣਤਰ dysymtab_command *dc = (ਬਣਤਰ dysymtab_command*)lc;
            iextdef = dc->iextdefsym;
            nextdef = dc->nextdefsym;
            ਰੋਕੋ;
        }
        }
        lc = (ਬਣਤਰ ਲੱਦੋ_command*) ((ਅੱਖਰ*)lc + lc->cmdsize);
    }

    ਜੇ (tcc_ਜੋੜੋ_dllref(s1, soname, lev)->ਮਿਲਿਆ)
        ਜਾਓ the_ਸਿਰਾ;

    ਜੇ (!nsyms || !nextdef)
      tcc_warning("%s doesn't export any symbols?", filename);

    //dprintf("symbols (all):\n");
    dprintf("symbols (exported):\n");
    dprintf("    n: typ sec   desc              value name\n");
    //for (i = 0; i < nsyms; i++) {
    ਲਈ (i = iextdef; i < iextdef + nextdef; i++) {
        ਬਣਤਰ nlist_64 *sym = symtab + i;
        dprintf("%5d: %3d %3d 0x%04x 0x%016lx %s\n",
                i, sym->n_type, sym->n_sect, sym->n_desc, (ਲੰਮਾ)sym->n_ਮੁੱਲ,
                strtab + sym->n_strx);
        ਸੈੱਟ_elf_sym(s1->dynsymtab_section, 0, 0,
                    ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
                    0, SHN_UNDEF, strtab + sym->n_strx);
    }

  the_ਸਿਰਾ:
    tcc_free(strtab);
    tcc_free(symtab);
    tcc_free(buf2);
    ਵਾਪਸ 0;
}
