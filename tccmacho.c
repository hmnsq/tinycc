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
#ಅನ್ತರ್ಭಾವ "tcc.h"

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

#ಆದರೆ !defined TCC_ಗುರಿ_X86_64 && !defined TCC_ಗುರಿ_ARM64
#ದೋಷ Platform not supported
#ಆದರೆ_ಅಂತ್ಯ

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು _tcc_error

#ವ್ಯಾಖ್ಯಾನಿಸು DEBUG_MACHO 0
#ವ್ಯಾಖ್ಯಾನಿಸು dprintf ಆದರೆ (DEBUG_MACHO) ಬರೆ

#ವ್ಯಾಖ್ಯಾನಿಸು MH_EXECUTE              (0x2)
#ವ್ಯಾಖ್ಯಾನಿಸು MH_DYLDLINK             (0x4)
#ವ್ಯಾಖ್ಯಾನಿಸು MH_DYLIB                (0x6)
#ವ್ಯಾಖ್ಯಾನಿಸು MH_PIE                  (0x200000)

#ವ್ಯಾಖ್ಯಾನಿಸು CPU_SUBTYPE_LIB64       (0x80000000)
#ವ್ಯಾಖ್ಯಾನಿಸು CPU_SUBTYPE_X86_ALL     (3)
#ವ್ಯಾಖ್ಯಾನಿಸು CPU_SUBTYPE_ARM64_ALL   (0)

#ವ್ಯಾಖ್ಯಾನಿಸು CPU_ARCH_ABI64          (0x01000000)

#ವ್ಯಾಖ್ಯಾನಿಸು CPU_TYPE_X86            (7)
#ವ್ಯಾಖ್ಯಾನಿಸು CPU_TYPE_X86_64         (CPU_TYPE_X86 | CPU_ARCH_ABI64)
#ವ್ಯಾಖ್ಯಾನಿಸು CPU_TYPE_ARM            (12)
#ವ್ಯಾಖ್ಯಾನಿಸು CPU_TYPE_ARM64          (CPU_TYPE_ARM | CPU_ARCH_ABI64)

ರಚನೆ fat_ಶೀರ್ಷಿಕೆ {
    uint32_t        magic;          /* FAT_MAGIC or FAT_MAGIC_64 */
    uint32_t        nfat_arch;      /* number of structs that follow */
};

ರಚನೆ fat_arch {
    ಪೂರ್ಣಾಂಕ             cputype;        /* cpu specifier (int) */
    ಪೂರ್ಣಾಂಕ             cpusubtype;     /* machine specifier (int) */
    uint32_t        ಸ್ಥಾನಾಂತರ;         /* file offset to this object file */
    uint32_t        ಗಾತ್ರ_2;           /* size of this object file */
    uint32_t        align;          /* alignment as a power of 2 */
};

#ವ್ಯಾಖ್ಯಾನಿಸು FAT_MAGIC       0xcafebabe
#ವ್ಯಾಖ್ಯಾನಿಸು FAT_CIGAM       0xbebafeca
#ವ್ಯಾಖ್ಯಾನಿಸು FAT_MAGIC_64    0xcafebabf
#ವ್ಯಾಖ್ಯಾನಿಸು FAT_CIGAM_64    0xbfbafeca

ರಚನೆ mach_ಶೀರ್ಷಿಕೆ {
    uint32_t        magic;          /* mach magic number identifier */
    ಪೂರ್ಣಾಂಕ             cputype;        /* cpu specifier */
    ಪೂರ್ಣಾಂಕ             cpusubtype;     /* machine specifier */
    uint32_t        filetype;       /* type of file */
    uint32_t        ncmds;          /* number of load commands */
    uint32_t        sizeofcmds;     /* the size of all the load commands */
    uint32_t        flags;          /* flags */
};

ರಚನೆ mach_ಶೀರ್ಷಿಕೆ_64 {
    ರಚನೆ mach_ಶೀರ್ಷಿಕೆ  mh;
    uint32_t            reserved;       /* reserved, pad to 64bit */
};

/* Constant for the magic field of the mach_header (32-bit architectures) */
#ವ್ಯಾಖ್ಯಾನಿಸು MH_MAGIC        0xfeedface      /* the mach magic number */
#ವ್ಯಾಖ್ಯಾನಿಸು MH_CIGAM        0xcefaedfe      /* NXSwapInt(MH_MAGIC) */
#ವ್ಯಾಖ್ಯಾನಿಸು MH_MAGIC_64     0xfeedfacf      /* the 64-bit mach magic number */
#ವ್ಯಾಖ್ಯಾನಿಸು MH_CIGAM_64     0xcffaedfe      /* NXSwapInt(MH_MAGIC_64) */

ರಚನೆ ತುಂಬು_command {
    uint32_t        cmd;            /* type of load command */
    uint32_t        cmdsize;        /* total size of command in bytes */
};

#ವ್ಯಾಖ್ಯಾನಿಸು LC_REQ_DYLD 0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು LC_SYMTAB        0x2
#ವ್ಯಾಖ್ಯಾನಿಸು LC_DYSYMTAB      0xb
#ವ್ಯಾಖ್ಯಾನಿಸು LC_ತುಂಬು_DYLIB    0xc
#ವ್ಯಾಖ್ಯಾನಿಸು LC_ID_DYLIB      0xd
#ವ್ಯಾಖ್ಯಾನಿಸು LC_ತುಂಬು_DYLINKER 0xe
#ವ್ಯಾಖ್ಯಾನಿಸು LC_SEGMENT_64    0x19
#ವ್ಯಾಖ್ಯಾನಿಸು LC_RPATH (0x1c | LC_REQ_DYLD)
#ವ್ಯಾಖ್ಯಾನಿಸು LC_REEXPORT_DYLIB (0x1f | LC_REQ_DYLD)
#ವ್ಯಾಖ್ಯಾನಿಸು LC_DYLD_INFO_ONLY (0x22|LC_REQ_DYLD)
#ವ್ಯಾಖ್ಯಾನಿಸು LC_MAIN (0x28|LC_REQ_DYLD)
#ವ್ಯಾಖ್ಯಾನಿಸು LC_ಮೂಲ_ಆವೃತ್ತಿ 0x2A
#ವ್ಯಾಖ್ಯಾನಿಸು LC_BUILD_ಆವೃತ್ತಿ 0x32
#ವ್ಯಾಖ್ಯಾನಿಸು LC_DYLD_EXPORTS_TRIE (0x33 | LC_REQ_DYLD)
#ವ್ಯಾಖ್ಯಾನಿಸು LC_DYLD_CHAINED_FIXUPS (0x34 | LC_REQ_DYLD)

#ವ್ಯಾಖ್ಯಾನಿಸು SG_READ_ONLY    0x10 /* This segment is made read-only after fixups */

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ vm_prot_t;

ರಚನೆ segment_command_64 { /* for 64-bit architectures */
    uint32_t        cmd;            /* LC_SEGMENT_64 */
    uint32_t        cmdsize;        /* includes sizeof section_64 structs */
    ಅಕ್ಷರ            segname[16];    /* segment name */
    uint64_t        vmaddr;         /* memory address of this segment */
    uint64_t        vmsize;         /* memory size of this segment */
    uint64_t        fileoff;        /* file offset of this segment */
    uint64_t        filesize;       /* amount to map from the file */
    vm_prot_t       maxprot;        /* maximum VM protection */
    vm_prot_t       initprot;       /* initial VM protection */
    uint32_t        nsects;         /* number of sections in segment */
    uint32_t        flags;          /* flags */
};

ರಚನೆ section_64 { /* for 64-bit architectures */
    ಅಕ್ಷರ            sectname[16];   /* name of this section */
    ಅಕ್ಷರ            segname[16];    /* segment this section goes in */
    uint64_t        addr;           /* memory address of this section */
    uint64_t        ಗಾತ್ರ_2;           /* size in bytes of this section */
    uint32_t        ಸ್ಥಾನಾಂತರ;         /* file offset of this section */
    uint32_t        align;          /* section alignment (power of 2) */
    uint32_t        reloff;         /* file offset of relocation entries */
    uint32_t        nreloc;         /* number of relocation entries */
    uint32_t        flags;          /* flags (section type and attributes)*/
    uint32_t        reserved1;      /* reserved (for offset or index) */
    uint32_t        reserved2;      /* reserved (for count or sizeof) */
    uint32_t        reserved3;      /* reserved */
};

ಎಣಿಕೆ {
    DYLD_CHAINED_IMPORT          = 1,
};

ರಚನೆ dyld_chained_fixups_ಶೀರ್ಷಿಕೆ {
    uint32_t    fixups_ಆವೃತ್ತಿ; ///< 0
    uint32_t    starts_ಸ್ಥಾನಾಂತರ;  ///< Offset of dyld_chained_starts_in_image.
    uint32_t    imports_ಸ್ಥಾನಾಂತರ; ///< Offset of imports table in chain_data.
    uint32_t    symbols_ಸ್ಥಾನಾಂತರ; ///< Offset of symbol strings in chain_data.
    uint32_t    imports_ಎಣಿಕೆ;  ///< Number of imported symbol names.
    uint32_t    imports_format; ///< DYLD_CHAINED_IMPORT*
    uint32_t    symbols_format; ///< 0 => uncompressed, 1 => zlib compressed
};

ರಚನೆ dyld_chained_starts_ಒಳ_image
{
    uint32_t    seg_ಎಣಿಕೆ;
    uint32_t    seg_info_ಸ್ಥಾನಾಂತರ[1];  // each entry is offset into this struct for that segment
    // followed by pool of dyld_chain_starts_in_segment data
};

ಎಣಿಕೆ {
    DYLD_CHAINED_PTR_64                     =  2,    // target is vmaddr
    DYLD_CHAINED_PTR_64_ಸ್ಥಾನಾಂತರ              =  6,    // target is vm offset
};

ಎಣಿಕೆ {
    DYLD_CHAINED_PTR_ಆರಂಭ_NONE   = 0xFFFF, // used in page_start[] to denote a page with no fixups
};

#ವ್ಯಾಖ್ಯಾನಿಸು SEG_ಪುಟ_ಗಾತ್ರ 16384

ರಚನೆ dyld_chained_starts_ಒಳ_segment
{
    uint32_t    ಗಾತ್ರ_2;               // size of this (amount kernel needs to copy)
    uint16_t    ಪುಟ_ಗಾತ್ರ;          // 0x1000 or 0x4000
    uint16_t    ಸೂಚಕ_format;     // DYLD_CHAINED_PTR_*
    uint64_t    segment_ಸ್ಥಾನಾಂತರ;     // offset in memory to start of segment
    uint32_t    max_valid_ಸೂಚಕ;  // for 32-bit OS, any value beyond this is not a pointer
    uint16_t    ಪುಟ_ಎಣಿಕೆ;         // how many pages are in array
    uint16_t    ಪುಟ_ಆರಂಭ[1];      // each entry is offset in each page of first element in chain
                                    // or DYLD_CHAINED_PTR_START_NONE if no fixups on page
};

ಎಣಿಕೆ BindSpecialDylib {
  BIND_SPECIAL_DYLIB_FLAT_LOOKUP = -2,
};

ರಚನೆ dyld_chained_import
{
    uint32_t    lib_ordinal :  8,
                weak_import :  1,
                name_ಸ್ಥಾನಾಂತರ : 23;
};

ರಚನೆ dyld_chained_ptr_64_rebase
{
    uint64_t    ಗುರಿ    : 36,    // vmaddr, 64GB max image size
                high8     :  8,    // top 8 bits set to this after slide added
                reserved  :  7,    // all zeros
                ಮುಂದಿನ      : 12,    // 4-byte stride
                bind      :  1;    // == 0
};

ರಚನೆ dyld_chained_ptr_64_bind
{
    uint64_t    ordinal   : 24,
                addend    :  8,   // 0 thru 255
                reserved  : 19,   // all zeros
                ಮುಂದಿನ      : 12,   // 4-byte stride
                bind      :  1;   // == 1
};

#ವ್ಯಾಖ್ಯಾನಿಸು S_REGULAR                       0x0
#ವ್ಯಾಖ್ಯಾನಿಸು S_ZEROFILL                      0x1
#ವ್ಯಾಖ್ಯಾನಿಸು S_NON_LAZY_ಚಿಹ್ನೆ_ಸೂಚಕಗಳು      0x6
#ವ್ಯಾಖ್ಯಾನಿಸು S_LAZY_ಚಿಹ್ನೆ_ಸೂಚಕಗಳು          0x7
#ವ್ಯಾಖ್ಯಾನಿಸು S_ಚಿಹ್ನೆ_STUBS                  0x8
#ವ್ಯಾಖ್ಯಾನಿಸು S_MOD_INIT_FUNC_ಸೂಚಕಗಳು        0x9
#ವ್ಯಾಖ್ಯಾನಿಸು S_MOD_ಪದ_FUNC_ಸೂಚಕಗಳು        0xa

#ವ್ಯಾಖ್ಯಾನಿಸು S_ATTR_ಶುದ್ಧ_INSTRUCTIONS        0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು S_ATTR_SOME_INSTRUCTIONS        0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು S_ATTR_DEBUG             	0x02000000


ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ uint32_t lc_str;

ರಚನೆ dylib_command {
    uint32_t cmd;                   /* LC_ID_DYLIB, LC_LOAD_{,WEAK_}DYLIB,
                                       LC_REEXPORT_DYLIB */
    uint32_t cmdsize;               /* includes pathname string */
    lc_str   name;                  /* library's path name */
    uint32_t timestamp;             /* library's build time stamp */
    uint32_t current_ಆವೃತ್ತಿ;       /* library's current version number */
    uint32_t compatibility_ಆವೃತ್ತಿ; /* library's compatibility vers number*/
};

ರಚನೆ rpath_command {
    uint32_t     cmd;           /* LC_RPATH */
    uint32_t     cmdsize;       /* includes string */
    lc_str       ಮಾರ್ಗ;          /* path to add to run path */
};

ರಚನೆ dylinker_command {
    uint32_t        cmd;            /* LC_ID_DYLINKER, LC_LOAD_DYLINKER or
                                       LC_DYLD_ENVIRONMENT */
    uint32_t        cmdsize;        /* includes pathname string */
    lc_str          name;           /* dynamic linker's path name */
};

ರಚನೆ linkedit_ದತ್ತಾಂಶ_command {
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

#ವ್ಯಾಖ್ಯಾನಿಸು PLATFORM_MACOS 1

ರಚನೆ build_ಆವೃತ್ತಿ_command {
    uint32_t    cmd;            /* LC_BUILD_VERSION */
    uint32_t    cmdsize;        /* sizeof(struct build_version_command) plus */
                                /* ntools * sizeof(struct build_tool_version) */
    uint32_t    platform;       /* platform */
    uint32_t    minos;          /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    sdk;            /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    ntools;         /* number of tool entries following this */
};

ರಚನೆ ಮೂಲ_ಆವೃತ್ತಿ_command {
    uint32_t  cmd;      /* LC_SOURCE_VERSION */
    uint32_t  cmdsize;  /* 16 */
    uint64_t  ಆವೃತ್ತಿ;  /* A.B.C.D.E packed as a24.b10.c10.d10.e10 */
};

ರಚನೆ symtab_command {
    uint32_t        cmd;            /* LC_SYMTAB */
    uint32_t        cmdsize;        /* sizeof(struct symtab_command) */
    uint32_t        symoff;         /* symbol table offset */
    uint32_t        nsyms;          /* number of symbol table entries */
    uint32_t        stroff;         /* string table offset */
    uint32_t        strsize;        /* string table size in bytes */
};

ರಚನೆ dysymtab_command {
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

#ವ್ಯಾಖ್ಯಾನಿಸು BIND_OPCODE_ಮುಗಿದ                                        0x00
#ವ್ಯಾಖ್ಯಾನಿಸು BIND_OPCODE_ಗಣ_DYLIB_SPECIAL_IMM                       0x30
#ವ್ಯಾಖ್ಯಾನಿಸು BIND_OPCODE_ಗಣ_ಚಿಹ್ನೆ_TRAILING_FLAGS_IMM               0x40
#ವ್ಯಾಖ್ಯಾನಿಸು BIND_OPCODE_ಗಣ_TYPE_IMM                                0x50
#ವ್ಯಾಖ್ಯಾನಿಸು BIND_OPCODE_ಗಣ_SEGMENT_AND_ಸ್ಥಾನಾಂತರ_ULEB                 0x70
#ವ್ಯಾಖ್ಯಾನಿಸು BIND_OPCODE_DO_BIND                                     0x90

#ವ್ಯಾಖ್ಯಾನಿಸು BIND_ಚಿಹ್ನೆ_FLAGS_WEAK_IMPORT                           0x1

#ವ್ಯಾಖ್ಯಾನಿಸು BIND_TYPE_ಸೂಚಕ                                       1
#ವ್ಯಾಖ್ಯಾನಿಸು BIND_SPECIAL_DYLIB_FLAT_LOOKUP                          -2

#ವ್ಯಾಖ್ಯಾನಿಸು REBASE_OPCODE_ಮುಗಿದ                                      0x00
#ವ್ಯಾಖ್ಯಾನಿಸು REBASE_OPCODE_ಗಣ_TYPE_IMM                              0x10
#ವ್ಯಾಖ್ಯಾನಿಸು REBASE_OPCODE_ಗಣ_SEGMENT_AND_ಸ್ಥಾನಾಂತರ_ULEB               0x20
#ವ್ಯಾಖ್ಯಾನಿಸು REBASE_OPCODE_DO_REBASE_IMM_TIMES                       0x50

#ವ್ಯಾಖ್ಯಾನಿಸು REBASE_TYPE_ಸೂಚಕ                                     1

#ವ್ಯಾಖ್ಯಾನಿಸು EXPORT_ಚಿಹ್ನೆ_FLAGS_ಬಗೆ_REGULAR                        0x00
#ವ್ಯಾಖ್ಯಾನಿಸು EXPORT_ಚಿಹ್ನೆ_FLAGS_ಬಗೆ_ABSOLUTE                       0x02
#ವ್ಯಾಖ್ಯಾನಿಸು EXPORT_ಚಿಹ್ನೆ_FLAGS_WEAK_DEFINITION                     0x04

ರಚನೆ dyld_info_command {
    uint32_t cmd;             /* LC_DYLD_INFO or LC_DYLD_INFO_ONLY */
    uint32_t cmdsize;         /* sizeof(struct dyld_info_command) */
    uint32_t rebase_off;      /* file offset to rebase info  */
    uint32_t rebase_ಗಾತ್ರ;     /* size of rebase info   */
    uint32_t bind_off;        /* file offset to binding info   */
    uint32_t bind_ಗಾತ್ರ;       /* size of binding info  */
    uint32_t weak_bind_off;   /* file offset to weak binding info   */
    uint32_t weak_bind_ಗಾತ್ರ;  /* size of weak binding info  */
    uint32_t lazy_bind_off;   /* file offset to lazy binding info */
    uint32_t lazy_bind_ಗಾತ್ರ;  /* size of lazy binding infs */
    uint32_t export_off;      /* file offset to lazy binding info */
    uint32_t export_ಗಾತ್ರ;     /* size of lazy binding infs */
};

#ವ್ಯಾಖ್ಯಾನಿಸು ಪರೋಕ್ಷ_ಚಿಹ್ನೆ_LOCAL   0x80000000

ರಚನೆ ನಮೂದು_ಬಿಂದು_command {
    uint32_t  cmd;      /* LC_MAIN only used in MH_EXECUTE filetypes */
    uint32_t  cmdsize;  /* 24 */
    uint64_t  entryoff; /* file (__TEXT) offset of main() */
    uint64_t  stacksize;/* if not zero, initial stack size */
};

ಎಣಿಕೆ skind {
    sk_unknown = 0,
    sk_discard,
    sk_ಪಠ್ಯ,
    sk_stubs,
    sk_stub_helper,
    sk_ro_ದತ್ತಾಂಶ,
    sk_uw_info,
    sk_nl_ptr,  // non-lazy pointers, aka GOT
    sk_debug_info,
    sk_debug_abbrev,
    sk_debug_ಸಾಲು,
    sk_debug_aranges,
    sk_debug_str,
    sk_debug_ಸಾಲು_str,
    sk_stab,
    sk_stab_str,
    sk_la_ptr,  // lazy pointers
    sk_init,
    sk_fini,
    sk_rw_ದತ್ತಾಂಶ,
    sk_bss,
    sk_linkedit,
    sk_ಕೊನೆಯ
};

ರಚನೆ nlist_64 {
    uint32_t  n_strx;      /* index into the string table */
    uint8_t n_type;        /* type flag, see below */
    uint8_t n_sect;        /* section number or NO_SECT */
    uint16_t n_desc;       /* see <mach-o/stab.h> */
    uint64_t n_ಮೌಲ್ಯ;      /* value of this symbol (or stab offset) */
};

#ವ್ಯಾಖ್ಯಾನಿಸು N_UNDF  0x0
#ವ್ಯಾಖ್ಯಾನಿಸು N_ABS   0x2
#ವ್ಯಾಖ್ಯಾನಿಸು N_EXT   0x1
#ವ್ಯಾಖ್ಯಾನಿಸು N_SECT  0xe

#ವ್ಯಾಖ್ಯಾನಿಸು N_WEAK_REF      0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು N_WEAK_DEF      0x0080

ರಚನೆ macho {
    ರಚನೆ mach_ಶೀರ್ಷಿಕೆ_64 mh;
    ಪೂರ್ಣಾಂಕ *seg2lc, nseg;
    ರಚನೆ ತುಂಬು_command **lc;
    ರಚನೆ ನಮೂದು_ಬಿಂದು_command *ep;
    ಪೂರ್ಣಾಂಕ nlc;
    ರಚನೆ {
        Section *s;
        ಪೂರ್ಣಾಂಕ machosect;
    } sk_ಗಮ್ಯ_sect[sk_ಕೊನೆಯ];
    ಪೂರ್ಣಾಂಕ *elfsectomacho;
    ಪೂರ್ಣಾಂಕ *e2msym;
    Section *symtab, *strtab, *indirsyms, *stubs, *exports;
    uint32_t ilocal, iextdef, iundef;
    ಪೂರ್ಣಾಂಕ stubsym, n_got, nr_plt;
    ಪೂರ್ಣಾಂಕ segment[sk_ಕೊನೆಯ];
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_NEW_MACHO
    Section *chained_fixups;
    ಪೂರ್ಣಾಂಕ n_bind;
    ಪೂರ್ಣಾಂಕ n_bind_rebase;
    ರಚನೆ bind_rebase {
	ಪೂರ್ಣಾಂಕ section;
	ಪೂರ್ಣಾಂಕ bind;
	ElfW_Rel rel;
    } *bind_rebase;
#ಇಲ್ಲದಿದ್ದರೆ
    Section *rebase, *binding, *weak_binding, *lazy_binding;
    Section *stub_helper, *la_ಚಿಹ್ನೆ_ptr;
    ರಚನೆ dyld_info_command *dyldinfo;
    ಪೂರ್ಣಾಂಕ helpsym, lasym, dyld_ಖಾಸಗಿ, dyld_stub_binder;
    ಪೂರ್ಣಾಂಕ n_lazy_bind;    
    ರಚನೆ s_lazy_bind {
        ಪೂರ್ಣಾಂಕ section;
        ಪೂರ್ಣಾಂಕ bind_ಸ್ಥಾನಾಂತರ;
        ಪೂರ್ಣಾಂಕ la_ಚಿಹ್ನೆ_ಸ್ಥಾನಾಂತರ;
        ElfW_Rel rel;
    } *s_lazy_bind;
    ಪೂರ್ಣಾಂಕ n_rebase;    
    ರಚನೆ s_rebase {
        ಪೂರ್ಣಾಂಕ section;
        ElfW_Rel rel;
    } *s_rebase;
    ಪೂರ್ಣಾಂಕ n_bind; 
    ರಚನೆ bind {
        ಪೂರ್ಣಾಂಕ section;
        ElfW_Rel rel;
    } *bind;
#ಆದರೆ_ಅಂತ್ಯ
};

#ವ್ಯಾಖ್ಯಾನಿಸು SHT_LINKEDIT (SHT_LOOS + 42)
#ವ್ಯಾಖ್ಯಾನಿಸು SHN_FROMDLL  (SHN_LOOS + 2)  /* Symbol is undefined, comes from a DLL */

ಸ್ಥಿರ ಶೂನ್ಯ * ಕೂಡಿಸು_lc(ರಚನೆ macho *mo, uint32_t cmd, uint32_t cmdsize)
{
    ರಚನೆ ತುಂಬು_command *lc = tcc_mallocz(cmdsize);
    lc->cmd = cmd;
    lc->cmdsize = cmdsize;
    mo->lc = tcc_realloc(mo->lc, ಗಾತ್ರ(mo->lc[0]) * (mo->nlc + 1));
    mo->lc[mo->nlc++] = lc;
    ಹಿಂತಿರುಗಿ lc;
}

ಸ್ಥಿರ ರಚನೆ segment_command_64 * ಕೂಡಿಸು_segment(ರಚನೆ macho *mo, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name)
{
    ರಚನೆ segment_command_64 *sc = ಕೂಡಿಸು_lc(mo, LC_SEGMENT_64, ಗಾತ್ರ(*sc));
    strncpy(sc->segname, name, 16);
    mo->seg2lc = tcc_realloc(mo->seg2lc, ಗಾತ್ರ(*mo->seg2lc) * (mo->nseg + 1));
    mo->seg2lc[mo->nseg++] = mo->nlc - 1;
    ಹಿಂತಿರುಗಿ sc;
}

ಸ್ಥಿರ ರಚನೆ segment_command_64 * get_segment(ರಚನೆ macho *mo, ಪೂರ್ಣಾಂಕ i)
{
    ಹಿಂತಿರುಗಿ (ರಚನೆ segment_command_64 *) (mo->lc[mo->seg2lc[i]]);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಕೂಡಿಸು_section(ರಚನೆ macho *mo, ರಚನೆ segment_command_64 **_seg, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name)
{
    ರಚನೆ segment_command_64 *seg = *_seg;
    ಪೂರ್ಣಾಂಕ ret = seg->nsects;
    ರಚನೆ section_64 *sec;
    seg->nsects++;
    seg->cmdsize += ಗಾತ್ರ(*sec);
    seg = tcc_realloc(seg, ಗಾತ್ರ(*seg) + seg->nsects * ಗಾತ್ರ(*sec));
    sec = (ರಚನೆ section_64*)((ಅಕ್ಷರ*)seg + ಗಾತ್ರ(*seg)) + ret;
    memset(sec, 0, ಗಾತ್ರ(*sec));
    strncpy(sec->sectname, name, 16);
    strncpy(sec->segname, seg->segname, 16);
    *_seg = seg;
    ಹಿಂತಿರುಗಿ ret;
}

ಸ್ಥಿರ ರಚನೆ section_64 *get_section(ರಚನೆ segment_command_64 *seg, ಪೂರ್ಣಾಂಕ i)
{
    ಹಿಂತಿರುಗಿ (ರಚನೆ section_64*)((ಅಕ್ಷರ*)seg + ಗಾತ್ರ(*seg)) + i;
}

ಸ್ಥಿರ ಶೂನ್ಯ * ಕೂಡಿಸು_dylib(ರಚನೆ macho *mo, ಅಕ್ಷರ *name)
{
    ರಚನೆ dylib_command *lc;
    ಪೂರ್ಣಾಂಕ sz = (ಗಾತ್ರ(*lc) + ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name) + 1 + 7) & -8;
    lc = ಕೂಡಿಸು_lc(mo, LC_ತುಂಬು_DYLIB, sz);
    lc->name = ಗಾತ್ರ(*lc);
    strcpy((ಅಕ್ಷರ*)lc + lc->name, name);
    lc->timestamp = 2;
    lc->current_ಆವೃತ್ತಿ = 1 << 16;
    lc->compatibility_ಆವೃತ್ತಿ = 1 << 16;
    ಹಿಂತಿರುಗಿ lc;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ uleb128_ಗಾತ್ರ (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಮೌಲ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2 =  0;

    ಮಾಡು {
        ಮೌಲ್ಯ >>= 7;
        ಗಾತ್ರ_2++;
    } ಆಗ (ಮೌಲ್ಯ != 0);
    ಹಿಂತಿರುಗಿ ಗಾತ್ರ_2;
}

ಸ್ಥಿರ ಶೂನ್ಯ write_uleb128(Section *section, uint64_t ಮೌಲ್ಯ)
{
    ಮಾಡು {
        ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ byte = ಮೌಲ್ಯ & 0x7f;
	uint8_t *ptr = section_ptr_ಕೂಡಿಸು(section, 1);

        ಮೌಲ್ಯ >>= 7;
        *ptr = byte | (ಮೌಲ್ಯ ? 0x80 : 0);
    } ಆಗ (ಮೌಲ್ಯ != 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ tcc_macho_ಕೂಡಿಸು_destructor(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ init_sym, mh_execute_ಶೀರ್ಷಿಕೆ, at_exit_sym;
    Section *s;
    ElfW_Rel *rel;
    uint8_t *ptr;

    mh_execute_ಶೀರ್ಷಿಕೆ = put_elf_sym(s1->symtab, -4096, 0,
				    ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				    ಪಠ್ಯ_section->sh_ಅಂಕೆ, "__mh_execute_header");
    s = ಕಂಡುಹಿಡಿ_section(s1, ".fini_array");
    ಆದರೆ (s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ == 0)
        ಹಿಂತಿರುಗಿ; 
    init_sym = put_elf_sym(s1->symtab, ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ, 0,
                           ELFW(ST_INFO)(STB_LOCAL, STT_FUNC), 0,
                           ಪಠ್ಯ_section->sh_ಅಂಕೆ, "___GLOBAL_init_65535");
    at_exit_sym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0,
                              SHN_UNDEF, "___cxa_atexit");
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    ptr = section_ptr_ಕೂಡಿಸು(ಪಠ್ಯ_section, 4);
    ptr[0] = 0x55;  // pushq   %rbp
    ptr[1] = 0x48;  // movq    %rsp, %rbp
    ptr[2] = 0x89;
    ptr[3] = 0xe5;
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_ಕೂಡಿಸು(ಪಠ್ಯ_section, 26);
        ptr[0] = 0x48;  // lea destructor(%rip),%rax
        ptr[1] = 0x8d;
        ptr[2] = 0x05;
        put_elf_reloca(s1->symtab, ಪಠ್ಯ_section, 
		       ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 23,
		       R_X86_64_PC32, sym_ಸೂಚ್ಯಂಕ, -4);
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
        put_elf_reloca(s1->symtab, ಪಠ್ಯ_section,
		       ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 9,
		       R_X86_64_PC32, mh_execute_ಶೀರ್ಷಿಕೆ, -4);
	ptr[21] = 0xe8; // call __cxa_atexit
        put_elf_reloca(s1->symtab, ಪಠ್ಯ_section,
		       ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 4,
		       R_X86_64_PLT32, at_exit_sym, -4);
    }
    ptr = section_ptr_ಕೂಡಿಸು(ಪಠ್ಯ_section, 2);
    ptr[0] = 0x5d;  // pop   %rbp
    ptr[1] = 0xc3;  // ret
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
    ptr = section_ptr_ಕೂಡಿಸು(ಪಠ್ಯ_section, 8);
    write32le(ptr, 0xa9bf7bfd);     // stp     x29, x30, [sp, #-16]!
    write32le(ptr + 4, 0x910003fd); // mov     x29, sp
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_ಕೂಡಿಸು(ಪಠ್ಯ_section, 24);
        put_elf_reloc(s1->symtab, ಪಠ್ಯ_section, 
		      ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 24,
		      R_AARCH64_ADR_PREL_PG_HI21, sym_ಸೂಚ್ಯಂಕ);
        write32le(ptr, 0x90000000);      // adrp x0, destructor@page
        put_elf_reloc(s1->symtab, ಪಠ್ಯ_section,
		      ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 20,
		      R_AARCH64_LDST8_ABS_LO12_NC, sym_ಸೂಚ್ಯಂಕ);
        write32le(ptr + 4, 0x91000000);  // add x0,x0,destructor@pageoff
        write32le(ptr + 8, 0xd2800001);  // mov x1, #0
        put_elf_reloc(s1->symtab, ಪಠ್ಯ_section, 
		      ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 12,
		      R_AARCH64_ADR_PREL_PG_HI21, mh_execute_ಶೀರ್ಷಿಕೆ);
        write32le(ptr + 12, 0x90000002);      // adrp x2, mh_execute_header@page
        put_elf_reloc(s1->symtab, ಪಠ್ಯ_section,
		      ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 8,
		      R_AARCH64_LDST8_ABS_LO12_NC, mh_execute_ಶೀರ್ಷಿಕೆ);
        write32le(ptr + 16, 0x91000042);  // add x2,x2,mh_execute_header@pageoff
        put_elf_reloc(s1->symtab, ಪಠ್ಯ_section,
		      ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 4,
		      R_AARCH64_CALL26, at_exit_sym);
	write32le(ptr + 20, 0x94000000); // bl __cxa_atexit
    }
    ptr = section_ptr_ಕೂಡಿಸು(ಪಠ್ಯ_section, 8);
    write32le(ptr, 0xa8c17bfd);     // ldp     x29, x30, [sp], #16
    write32le(ptr + 4, 0xd65f03c0); // ret
#ಆದರೆ_ಅಂತ್ಯ
    s->reloc->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = 0;
    s->sh_flags &= ~SHF_ALLOC;
    ಕೂಡಿಸು_array (s1, ".init_array", init_sym);
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_NEW_MACHO
ಸ್ಥಿರ ಶೂನ್ಯ bind_rebase_ಕೂಡಿಸು(ರಚನೆ macho *mo, ಪೂರ್ಣಾಂಕ bind, ಪೂರ್ಣಾಂಕ sh_info,
			    ElfW_Rel *rel, ರಚನೆ sym_attr *attr)
{
    mo->bind_rebase = tcc_realloc(mo->bind_rebase, (mo->n_bind_rebase + 1) *
		                  ಗಾತ್ರ(ರಚನೆ bind_rebase));
    mo->bind_rebase[mo->n_bind_rebase].section = sh_info;
    mo->bind_rebase[mo->n_bind_rebase].bind = bind;
    mo->bind_rebase[mo->n_bind_rebase].rel = *rel;
    ಆದರೆ (attr)
        mo->bind_rebase[mo->n_bind_rebase].rel.r_ಸ್ಥಾನಾಂತರ = attr->got_ಸ್ಥಾನಾಂತರ;
    mo->n_bind_rebase++;
    mo->n_bind += bind;
}

ಸ್ಥಿರ ಶೂನ್ಯ check_relocs(TCCState *s1, ರಚನೆ macho *mo)
{
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಂಕ i, j, type, gotplt_ನಮೂದು, sym_ಸೂಚ್ಯಂಕ, for_ಸಂಕೇತ;
    uint32_t *pi, *goti;
    ರಚನೆ sym_attr *attr;

    goti = ಖಾಲಿ;
    mo->nr_plt = mo->n_got = 0;
    ಗಾಗಿ (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ಆದರೆ (s->sh_type != SHT_RELX ||
	    !ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(s1->sections[s->sh_info]->name, ".debug_", 7))
            ಮುಂದುವರಿ;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_ನಮೂದು = gotplt_ನಮೂದು_type(type);
            for_ಸಂಕೇತ = ಸಂಕೇತ_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
            ಆದರೆ (sym->st_shndx == SHN_UNDEF
                || gotplt_ನಮೂದು == ALWAYS_GOTPLT_ನಮೂದು) {
                attr = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 1);
                ಆದರೆ (!attr->dyn_ಸೂಚ್ಯಂಕ) {
                    attr->got_ಸ್ಥಾನಾಂತರ = s1->got->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
                    attr->plt_ಸ್ಥಾನಾಂತರ = -1;
                    attr->dyn_ಸೂಚ್ಯಂಕ = 1; /* used as flag */
                    section_ptr_ಕೂಡಿಸು(s1->got, PTR_ಗಾತ್ರ);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_ಸ್ಥಾನಾಂತರ,
                                  R_JMP_ಸ್ಥಾನ, sym_ಸೂಚ್ಯಂಕ);
	 	    goti = tcc_realloc(goti, (mo->n_got + 1) * ಗಾತ್ರ(*goti));
                    ಆದರೆ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        ಆದರೆ (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name);
			goti[mo->n_got++] = ಪರೋಕ್ಷ_ಚಿಹ್ನೆ_LOCAL;
                    } ಇಲ್ಲದಿದ್ದರೆ {
                        goti[mo->n_got++] = mo->e2msym[sym_ಸೂಚ್ಯಂಕ];
                        ಆದರೆ (sym->st_shndx == SHN_UNDEF
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
                            && type == R_X86_64_GOTPCREL
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
                            && type == R_AARCH64_ADR_GOT_ಪುಟ
#ಆದರೆ_ಅಂತ್ಯ
                            ) {
			    attr->plt_ಸ್ಥಾನಾಂತರ = -mo->n_bind_rebase - 2;
			    bind_rebase_ಕೂಡಿಸು(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
			    s1->got->reloc->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ -= ಗಾತ್ರ (ElfW_Rel);
			}
		        ಆದರೆ (for_ಸಂಕೇತ && sym->st_shndx == SHN_UNDEF)
			    s1->got->reloc->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ -= ಗಾತ್ರ (ElfW_Rel);
		    }
                }
                ಆದರೆ (for_ಸಂಕೇತ && sym->st_shndx == SHN_UNDEF) {
		    ಆದರೆ ((ಪೂರ್ಣಾಂಕ)attr->plt_ಸ್ಥಾನಾಂತರ < -1) {
			/* remove above bind and replace with plt */
			mo->bind_rebase[-attr->plt_ಸ್ಥಾನಾಂತರ - 2].bind = 2;
			attr->plt_ಸ್ಥಾನಾಂತರ = -1;
		    }
                    ಆದರೆ (attr->plt_ಸ್ಥಾನಾಂತರ == -1) {
                        uint8_t *jmp;

                        attr->plt_ಸ್ಥಾನಾಂತರ = mo->stubs->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
                        ಆದರೆ (type != R_X86_64_PLT32)
                             ಮುಂದುವರಿ;
                        jmp = section_ptr_ಕೂಡಿಸು(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *ofs(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_ಸ್ಥಾನಾಂತರ + 2,
                                      R_X86_64_GOTPCREL, sym_ಸೂಚ್ಯಂಕ);
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
                        ಆದರೆ (type != R_AARCH64_CALL26)
                             ಮುಂದುವರಿ;
                        jmp = section_ptr_ಕೂಡಿಸು(mo->stubs, 12);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_ಸ್ಥಾನಾಂತರ,
                                      R_AARCH64_ADR_GOT_ಪುಟ, sym_ಸೂಚ್ಯಂಕ);
                        write32le(jmp, // adrp x16, #sym
                                  0x90000010);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_ಸ್ಥಾನಾಂತರ + 4,
                                      R_AARCH64_LD64_GOT_LO12_NC, sym_ಸೂಚ್ಯಂಕ);
                        write32le(jmp + 4, // ld x16,[x16, #sym]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);
#ಆದರೆ_ಅಂತ್ಯ
			bind_rebase_ಕೂಡಿಸು(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
                        pi = section_ptr_ಕೂಡಿಸು(mo->indirsyms, ಗಾತ್ರ(*pi));
                        *pi = mo->e2msym[sym_ಸೂಚ್ಯಂಕ];
                        mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_ಸ್ಥಾನಾಂತರ;
                }
            }
	    ಆದರೆ (type == R_ದತ್ತಾಂಶ_PTR || type == R_JMP_ಸ್ಥಾನ)
		bind_rebase_ಕೂಡಿಸು(mo, sym->st_shndx == SHN_UNDEF ? 1 : 0,
				s->sh_info, &save_rel, ಖಾಲಿ);
        }
    }
    /* remove deleted binds */
    ಗಾಗಿ (i = 0, j = 0; i < mo->n_bind_rebase; i++)
	ಆದರೆ (mo->bind_rebase[i].bind == 2)
	    mo->n_bind--;
	ಇಲ್ಲದಿದ್ದರೆ
	    mo->bind_rebase[j++] = mo->bind_rebase[i];
    mo->n_bind_rebase = j;
    pi = section_ptr_ಕೂಡಿಸು(mo->indirsyms, mo->n_got * ಗಾತ್ರ(*pi));
    ಸ್ಮರಣೆ_ನಕಲು(pi, goti, mo->n_got * ಗಾತ್ರ(*pi));
    tcc_free(goti);
}

#ಇಲ್ಲದಿದ್ದರೆ

ಸ್ಥಿರ ಶೂನ್ಯ check_relocs(TCCState *s1, ರಚನೆ macho *mo)
{
    uint8_t *jmp;
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಂಕ i, type, gotplt_ನಮೂದು, sym_ಸೂಚ್ಯಂಕ, for_ಸಂಕೇತ;
    ಪೂರ್ಣಾಂಕ bind_ಸ್ಥಾನಾಂತರ, la_ಚಿಹ್ನೆ_ಸ್ಥಾನಾಂತರ;
    uint32_t *pi, *goti;
    ರಚನೆ sym_attr *attr;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    jmp = section_ptr_ಕೂಡಿಸು(mo->stub_helper, 16);
    jmp[0] = 0x4c;  /* leaq _dyld_private(%rip), %r11 */
    jmp[1] = 0x8d;
    jmp[2] = 0x1d;
    put_elf_reloca(s1->symtab, mo->stub_helper, 3,
		   R_X86_64_PC32, mo->dyld_ಖಾಸಗಿ, -4);
    jmp[7] = 0x41;  /* pushq %r11 */
    jmp[8] = 0x53;
    jmp[9] = 0xff;  /* jmpq    *dyld_stub_binder@GOT(%rip) */
    jmp[10] = 0x25;
    put_elf_reloca(s1->symtab, mo->stub_helper, 11,
		   R_X86_64_GOTPCREL, mo->dyld_stub_binder, -4);
    jmp[15] = 0x90; /* nop */
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
    jmp = section_ptr_ಕೂಡಿಸು(mo->stub_helper, 24);
    put_elf_reloc(s1->symtab, mo->stub_helper, 0,
		  R_AARCH64_ADR_PREL_PG_HI21, mo->dyld_ಖಾಸಗಿ);
    write32le(jmp, 0x90000011); // adrp x17, _dyld_private@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 4,
		  R_AARCH64_LDST64_ABS_LO12_NC, mo->dyld_ಖಾಸಗಿ);
    write32le(jmp + 4, 0x91000231); // add x17,x17,_dyld_private@pageoff
    write32le(jmp + 8, 0xa9bf47f0); // stp x16/x17, [sp, #-16]!
    put_elf_reloc(s1->symtab, mo->stub_helper, 12,
		  R_AARCH64_ADR_GOT_ಪುಟ, mo->dyld_stub_binder);
    write32le(jmp + 12, 0x90000010); // adrp x16, dyld_stub_binder@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 16,
		  R_AARCH64_LD64_GOT_LO12_NC, mo->dyld_stub_binder);
    write32le(jmp + 16, 0xf9400210); // ldr x16,[x16,dyld_stub_binder@pageoff]
    write32le(jmp + 20, 0xd61f0200); // br x16
#ಆದರೆ_ಅಂತ್ಯ
    
    goti = ಖಾಲಿ;
    mo->nr_plt = mo->n_got = 0;
    ಗಾಗಿ (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ಆದರೆ (s->sh_type != SHT_RELX ||
	    !ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(s1->sections[s->sh_info]->name, ".debug_", 7))
            ಮುಂದುವರಿ;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_ನಮೂದು = gotplt_ನಮೂದು_type(type);
            for_ಸಂಕೇತ = ಸಂಕೇತ_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
            ಆದರೆ (sym->st_shndx == SHN_UNDEF
                || gotplt_ನಮೂದು == ALWAYS_GOTPLT_ನಮೂದು) {
                attr = get_sym_attr(s1, sym_ಸೂಚ್ಯಂಕ, 1);
                ಆದರೆ (!attr->dyn_ಸೂಚ್ಯಂಕ) {
                    attr->got_ಸ್ಥಾನಾಂತರ = s1->got->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
                    attr->plt_ಸ್ಥಾನಾಂತರ = -1;
                    attr->dyn_ಸೂಚ್ಯಂಕ = 1; /* used as flag */
		    section_ptr_ಕೂಡಿಸು(s1->got, PTR_ಗಾತ್ರ);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_ಸ್ಥಾನಾಂತರ,
                                  R_JMP_ಸ್ಥಾನ, sym_ಸೂಚ್ಯಂಕ);
		    goti = tcc_realloc(goti, (mo->n_got + 1) * ಗಾತ್ರ(*goti));
                    ಆದರೆ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        ಆದರೆ (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name);
			goti[mo->n_got++] = ಪರೋಕ್ಷ_ಚಿಹ್ನೆ_LOCAL;
                    } ಇಲ್ಲದಿದ್ದರೆ {
			goti[mo->n_got++] = mo->e2msym[sym_ಸೂಚ್ಯಂಕ];
			ಆದರೆ (sym->st_shndx == SHN_UNDEF
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
			    && type == R_X86_64_GOTPCREL
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
			    && type == R_AARCH64_ADR_GOT_ಪುಟ
#ಆದರೆ_ಅಂತ್ಯ
			    ) {
			    mo->bind =
			        tcc_realloc(mo->bind,
					    (mo->n_bind + 1) *
					    ಗಾತ್ರ(ರಚನೆ bind));
			    mo->bind[mo->n_bind].section = s1->got->reloc->sh_info;
			    mo->bind[mo->n_bind].rel = save_rel;
                            mo->bind[mo->n_bind].rel.r_ಸ್ಥಾನಾಂತರ = attr->got_ಸ್ಥಾನಾಂತರ;
			    mo->n_bind++;
			    s1->got->reloc->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ -= ಗಾತ್ರ (ElfW_Rel);
			}
		    }
                }
                ಆದರೆ (for_ಸಂಕೇತ && sym->st_shndx == SHN_UNDEF) {
                    ಆದರೆ (attr->plt_ಸ್ಥಾನಾಂತರ == -1) {
                        attr->plt_ಸ್ಥಾನಾಂತರ = mo->stubs->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
			ಆದರೆ (type != R_X86_64_PLT32)
			     ಮುಂದುವರಿ;
			/* __stubs */
                        jmp = section_ptr_ಕೂಡಿಸು(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *__la_symbol_ptr(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 4,
                                       R_X86_64_PC32, mo->lasym,
				       mo->la_ಚಿಹ್ನೆ_ptr->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 4);

			/* __stub_helper */
			bind_ಸ್ಥಾನಾಂತರ = mo->stub_helper->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ + 1;
                        jmp = section_ptr_ಕೂಡಿಸು(mo->stub_helper, 10);
                        jmp[0] = 0x68;  /* pushq $bind_offset */
                        jmp[5] = 0xe9;  /* jmpq __stub_helper */
                        write32le(jmp + 6, -mo->stub_helper->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);

			/* __la_symbol_ptr */
			la_ಚಿಹ್ನೆ_ಸ್ಥಾನಾಂತರ = mo->la_ಚಿಹ್ನೆ_ptr->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
                        put_elf_reloca(s1->symtab, mo->la_ಚಿಹ್ನೆ_ptr,
				       mo->la_ಚಿಹ್ನೆ_ptr->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ,
				       R_ದತ್ತಾಂಶ_PTR, mo->helpsym,
				       mo->stub_helper->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 10);
			section_ptr_ಕೂಡಿಸು(mo->la_ಚಿಹ್ನೆ_ptr, PTR_ಗಾತ್ರ);
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
			ಆದರೆ (type != R_AARCH64_CALL26)
			     ಮುಂದುವರಿ;
			/* __stubs */
                        jmp = section_ptr_ಕೂಡಿಸು(mo->stubs, 12);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 12,
                                       R_AARCH64_ADR_PREL_PG_HI21, mo->lasym,
				       mo->la_ಚಿಹ್ನೆ_ptr->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
                        write32le(jmp, // adrp x16, __la_symbol_ptr@page
                                  0x90000010);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 8,
                                       R_AARCH64_LDST64_ABS_LO12_NC, mo->lasym,
				       mo->la_ಚಿಹ್ನೆ_ptr->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
                        write32le(jmp + 4, // ldr x16,[x16, __la_symbol_ptr@pageoff]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);

			/* __stub_helper */
			bind_ಸ್ಥಾನಾಂತರ = mo->stub_helper->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ + 8;
                        jmp = section_ptr_ಕೂಡಿಸು(mo->stub_helper, 12);
                        write32le(jmp + 0, // ldr  w16, l0
                                  0x18000050);
                        write32le(jmp + 4, // b stubHelperHeader
                                  0x14000000 +
				  ((-(mo->stub_helper->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 8) / 4) &
				   0x3ffffff));
                        write32le(jmp + 8, 0); // l0: .long bind_offset

			/* __la_symbol_ptr */
			la_ಚಿಹ್ನೆ_ಸ್ಥಾನಾಂತರ = mo->la_ಚಿಹ್ನೆ_ptr->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
                        put_elf_reloca(s1->symtab, mo->la_ಚಿಹ್ನೆ_ptr,
				       mo->la_ಚಿಹ್ನೆ_ptr->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ,
				       R_ದತ್ತಾಂಶ_PTR, mo->helpsym,
				       mo->stub_helper->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 12);
			section_ptr_ಕೂಡಿಸು(mo->la_ಚಿಹ್ನೆ_ptr, PTR_ಗಾತ್ರ);
#ಆದರೆ_ಅಂತ್ಯ
                        mo->s_lazy_bind =
                            tcc_realloc(mo->s_lazy_bind, (mo->n_lazy_bind + 1) *
                                        ಗಾತ್ರ(ರಚನೆ s_lazy_bind));
                        mo->s_lazy_bind[mo->n_lazy_bind].section =
                            mo->stub_helper->reloc->sh_info;
                        mo->s_lazy_bind[mo->n_lazy_bind].bind_ಸ್ಥಾನಾಂತರ =
			    bind_ಸ್ಥಾನಾಂತರ;
                        mo->s_lazy_bind[mo->n_lazy_bind].la_ಚಿಹ್ನೆ_ಸ್ಥಾನಾಂತರ =
			    la_ಚಿಹ್ನೆ_ಸ್ಥಾನಾಂತರ;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel = save_rel;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel.r_ಸ್ಥಾನಾಂತರ =
                            attr->plt_ಸ್ಥಾನಾಂತರ;
                        mo->n_lazy_bind++;
			pi = section_ptr_ಕೂಡಿಸು(mo->indirsyms, ಗಾತ್ರ(*pi));
			*pi = mo->e2msym[sym_ಸೂಚ್ಯಂಕ];
			mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_ಸ್ಥಾನಾಂತರ;
                }
            }
            ಆದರೆ (type == R_ದತ್ತಾಂಶ_PTR || type == R_JMP_ಸ್ಥಾನ) {
		ಆದರೆ (sym->st_shndx == SHN_UNDEF) {
		    mo->bind = tcc_realloc(mo->bind,
					   (mo->n_bind + 1) *
					   ಗಾತ್ರ(ರಚನೆ bind));
		    mo->bind[mo->n_bind].section = s->sh_info;
		    mo->bind[mo->n_bind].rel = save_rel;
		    mo->n_bind++;
		}
		ಇಲ್ಲದಿದ್ದರೆ {
                    mo->s_rebase =
                        tcc_realloc(mo->s_rebase, (mo->n_rebase + 1) *
				    ಗಾತ್ರ(ರಚನೆ s_rebase));
                    mo->s_rebase[mo->n_rebase].section = s->sh_info;
                    mo->s_rebase[mo->n_rebase].rel = save_rel;
                    mo->n_rebase++;
		}
	    }
        }
    }
    pi = section_ptr_ಕೂಡಿಸು(mo->indirsyms, mo->n_got * ಗಾತ್ರ(*pi));
    ಸ್ಮರಣೆ_ನಕಲು(pi, goti, mo->n_got * ಗಾತ್ರ(*pi));
    pi = section_ptr_ಕೂಡಿಸು(mo->indirsyms, mo->nr_plt * ಗಾತ್ರ(*pi));
    ಸ್ಮರಣೆ_ನಕಲು(pi, mo->indirsyms->ದತ್ತಾಂಶ, mo->nr_plt * ಗಾತ್ರ(*pi));
    tcc_free(goti);
}
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ check_symbols(TCCState *s1, ರಚನೆ macho *mo)
{
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ, sym_ಕೊನೆ;
    ಪೂರ್ಣಾಂಕ ret = 0;

    mo->ilocal = mo->iextdef = mo->iundef = -1;
    sym_ಕೊನೆ = symtab_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ(ElfW(Sym));
    ಗಾಗಿ (sym_ಸೂಚ್ಯಂಕ = 1; sym_ಸೂಚ್ಯಂಕ < sym_ಕೊನೆ; ++sym_ಸೂಚ್ಯಂಕ) {
        ಪೂರ್ಣಾಂಕ elf_ಸೂಚ್ಯಂಕ = ((ರಚನೆ nlist_64 *)mo->symtab->ದತ್ತಾಂಶ + sym_ಸೂಚ್ಯಂಕ - 1)->n_ಮೌಲ್ಯ;
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ + elf_ಸೂಚ್ಯಂಕ;
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = (ಅಕ್ಷರ*)symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
        ಚಿಹ್ನೆರಹಿತ type = ELFW(ST_TYPE)(sym->st_info);
        ಚಿಹ್ನೆರಹಿತ bind = ELFW(ST_BIND)(sym->st_info);
        ಚಿಹ್ನೆರಹಿತ vis  = ELFW(ST_VISIBILITY)(sym->st_other);

        dprintf("%4d (%4d): %09lx %4d %4d %4d %3d %s\n",
                sym_ಸೂಚ್ಯಂಕ, elf_ಸೂಚ್ಯಂಕ, (ದೀರ್ಘ)sym->st_ಮೌಲ್ಯ,
                type, bind, vis, sym->st_shndx, name);
        ಆದರೆ (bind == STB_LOCAL) {
            ಆದರೆ (mo->ilocal == -1)
              mo->ilocal = sym_ಸೂಚ್ಯಂಕ - 1;
            ಆದರೆ (mo->iextdef != -1 || mo->iundef != -1)
              tcc_error("local syms after global ones");
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sym->st_shndx != SHN_UNDEF) {
            ಆದರೆ (mo->iextdef == -1)
              mo->iextdef = sym_ಸೂಚ್ಯಂಕ - 1;
            ಆದರೆ (mo->iundef != -1)
              tcc_error("external defined symbol after undefined");
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sym->st_shndx == SHN_UNDEF) {
            ಆದರೆ (mo->iundef == -1)
              mo->iundef = sym_ಸೂಚ್ಯಂಕ - 1;
            ಆದರೆ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK
		|| s1->output_type != TCC_OUTPUT_EXE
                || ಕಂಡುಹಿಡಿ_elf_sym(s1->dynsymtab_section, name)) {
                /* Mark the symbol as coming from a dylib so that
                   relocate_syms doesn't complain.  Normally bind_exe_dynsyms
                   would do this check, and place the symbol into dynsym
                   which is checked by relocate_syms.  But Mach-O doesn't use
                   bind_exe_dynsyms.  */
                sym->st_shndx = SHN_FROMDLL;
                ಮುಂದುವರಿ;
            }
            tcc_error_noabort("unresolved reference to '%s'", name);
            ret = -1;
        }
    }
    ಹಿಂತಿರುಗಿ ret;
}

ಸ್ಥಿರ ಶೂನ್ಯ convert_ಚಿಹ್ನೆ(TCCState *s1, ರಚನೆ macho *mo, ರಚನೆ nlist_64 *pn)
{
    ರಚನೆ nlist_64 n = *pn;
    ElfSym *sym = (ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ + pn->n_ಮೌಲ್ಯ;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = (ಅಕ್ಷರ*)symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
    ಆಯ್ಕೆ(ELFW(ST_TYPE)(sym->st_info)) {
    ಸ್ಥಿತಿ STT_NOTYPE:
    ಸ್ಥಿತಿ STT_OBJECT:
    ಸ್ಥಿತಿ STT_FUNC:
    ಸ್ಥಿತಿ STT_TLS:
    ಸ್ಥಿತಿ STT_SECTION:
        n.n_type = N_SECT;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ STT_FILE:
        n.n_type = N_ABS;
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        tcc_error("unhandled ELF symbol type %d %s",
                  ELFW(ST_TYPE)(sym->st_info), name);
    }
    ಆದರೆ (sym->st_shndx == SHN_UNDEF)
      tcc_error("should have been rewritten to SHN_FROMDLL: %s", name);
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sym->st_shndx == SHN_FROMDLL)
      n.n_type = N_UNDF, n.n_sect = 0;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sym->st_shndx == SHN_ABS)
      n.n_type = N_ABS, n.n_sect = 0;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sym->st_shndx >= SHN_LORESERVE)
      tcc_error("unhandled ELF symbol section %d %s", sym->st_shndx, name);
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!mo->elfsectomacho[sym->st_shndx]) {
      ಆದರೆ (ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(s1->sections[sym->st_shndx]->name, ".debug_", 7))
        tcc_error("ELF section %d(%s) not mapped into Mach-O for symbol %s",
                  sym->st_shndx, s1->sections[sym->st_shndx]->name, name);
    }
    ಇಲ್ಲದಿದ್ದರೆ
      n.n_sect = mo->elfsectomacho[sym->st_shndx];
    ಆದರೆ (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL)
      n.n_type |=  N_EXT;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
      n.n_desc |= N_WEAK_REF | (n.n_type != N_UNDF ? N_WEAK_DEF : 0);
    n.n_strx = pn->n_strx;
    n.n_ಮೌಲ್ಯ = sym->st_ಮೌಲ್ಯ;
    *pn = n;
}

ಸ್ಥಿರ ಶೂನ್ಯ convert_symbols(TCCState *s1, ರಚನೆ macho *mo)
{
    ರಚನೆ nlist_64 *pn;
    for_each_elem(mo->symtab, 0, pn, ರಚನೆ nlist_64)
        convert_ಚಿಹ್ನೆ(s1, mo, pn);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ machosymcmp(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *_a, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *_b, ಶೂನ್ಯ *arg)
{
    TCCState *s1 = arg;
    ಪೂರ್ಣಾಂಕ ea = ((ರಚನೆ nlist_64 *)_a)->n_ಮೌಲ್ಯ;
    ಪೂರ್ಣಾಂಕ eb = ((ರಚನೆ nlist_64 *)_b)->n_ಮೌಲ್ಯ;
    ElfSym *sa = (ElfSym *)symtab_section->ದತ್ತಾಂಶ + ea;
    ElfSym *sb = (ElfSym *)symtab_section->ದತ್ತಾಂಶ + eb;
    ಪೂರ್ಣಾಂಕ r;
    /* locals, then defined externals, then undefined externals, the
       last two sections also by name, otherwise stable sort */
    r = (ELFW(ST_BIND)(sb->st_info) == STB_LOCAL)
        - (ELFW(ST_BIND)(sa->st_info) == STB_LOCAL);
    ಆದರೆ (r)
      ಹಿಂತಿರುಗಿ r;
    r = (sa->st_shndx == SHN_UNDEF) - (sb->st_shndx == SHN_UNDEF);
    ಆದರೆ (r)
      ಹಿಂತಿರುಗಿ r;
    ಆದರೆ (ELFW(ST_BIND)(sa->st_info) != STB_LOCAL) {
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * na = (ಅಕ್ಷರ*)symtab_section->link->ದತ್ತಾಂಶ + sa->st_name;
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * nb = (ಅಕ್ಷರ*)symtab_section->link->ದತ್ತಾಂಶ + sb->st_name;
        r = strcmp(na, nb);
        ಆದರೆ (r)
          ಹಿಂತಿರುಗಿ r;
    }
    ಹಿಂತಿರುಗಿ ea - eb;
}

/* cannot use qsort because code has to be reentrant */
ಸ್ಥಿರ ಶೂನ್ಯ tcc_qsort (ಶೂನ್ಯ  *ತಳ, ಗಾತ್ರ_t nel, ಗಾತ್ರ_t ಅಗಲ,
                       ಪೂರ್ಣಾಂಕ (*comp)(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *, ಶೂನ್ಯ *), ಶೂನ್ಯ *arg)
{
    ಗಾತ್ರ_t wnel, gap, wgap, i, j, k;
    ಅಕ್ಷರ *a, *b, tmp;

    wnel = ಅಗಲ * nel;
    ಗಾಗಿ (gap = 0; ++gap < nel;)
        gap *= 3;
    ಆಗ ( gap /= 3 ) {
        wgap = ಅಗಲ * gap;
        ಗಾಗಿ (i = wgap; i < wnel; i += ಅಗಲ) {
            ಗಾಗಿ (j = i - wgap; ;j -= wgap) {
                a = j + (ಅಕ್ಷರ *)ತಳ;
                b = a + wgap;
                ಆದರೆ ( (*comp)(a, b, arg) <= 0 )
                    ನಿಲ್ಲಿಸು;
                k = ಅಗಲ;
                ಮಾಡು {
                    tmp = *a;
                    *a++ = *b;
                    *b++ = tmp;
                } ಆಗ ( --k );
                ಆದರೆ (j < wgap)
                    ನಿಲ್ಲಿಸು;
            }
        }
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ create_symtab(TCCState *s1, ರಚನೆ macho *mo)
{
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ, sym_ಕೊನೆ;
    ರಚನೆ nlist_64 *pn;

    /* Stub creation belongs to check_relocs, but we need to create
       the symbol now, so its included in the sorting.  */
    mo->stubs = new_section(s1, "__stubs", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->stubsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stubs->sh_ಅಂಕೆ, ".__stubs");
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_NEW_MACHO
    mo->chained_fixups = new_section(s1, "CHAINED_FIXUPS",
				     SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#ಇಲ್ಲದಿದ್ದರೆ
    mo->stub_helper = new_section(s1, "__stub_helper", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    mo->la_ಚಿಹ್ನೆ_ptr = new_section(s1, "__la_symbol_ptr", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->helpsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stub_helper->sh_ಅಂಕೆ, ".__stub_helper");
    mo->lasym = put_elf_sym(s1->symtab, 0, 0,
                            ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                            mo->la_ಚಿಹ್ನೆ_ptr->sh_ಅಂಕೆ, ".__la_symbol_ptr");
    section_ptr_ಕೂಡಿಸು(ದತ್ತಾಂಶ_section, -ದತ್ತಾಂಶ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ & (PTR_ಗಾತ್ರ - 1));
    mo->dyld_ಖಾಸಗಿ = put_elf_sym(s1->symtab, ದತ್ತಾಂಶ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ, PTR_ಗಾತ್ರ,
                                   ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT), 0,
                                   ದತ್ತಾಂಶ_section->sh_ಅಂಕೆ, ".__dyld_private");
    section_ptr_ಕೂಡಿಸು(ದತ್ತಾಂಶ_section, PTR_ಗಾತ್ರ);
    mo->dyld_stub_binder = put_elf_sym(s1->symtab, 0, 0,
                		       ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				       SHN_UNDEF, "dyld_stub_binder");
    mo->rebase = new_section(s1, "REBASE", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->binding = new_section(s1, "BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->weak_binding = new_section(s1, "WEAK_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->lazy_binding = new_section(s1, "LAZY_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#ಆದರೆ_ಅಂತ್ಯ
    mo->exports = new_section(s1, "EXPORT", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->indirsyms = new_section(s1, "LEINDIR", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);

    mo->symtab = new_section(s1, "LESYMTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->strtab = new_section(s1, "LESTRTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    put_elf_str(mo->strtab, " "); /* Mach-O starts strtab with a space */
    sym_ಕೊನೆ = symtab_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ(ElfW(Sym));
    pn = section_ptr_ಕೂಡಿಸು(mo->symtab, ಗಾತ್ರ(*pn) * (sym_ಕೊನೆ - 1));
    ಗಾಗಿ (sym_ಸೂಚ್ಯಂಕ = 1; sym_ಸೂಚ್ಯಂಕ < sym_ಕೊನೆ; ++sym_ಸೂಚ್ಯಂಕ) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ + sym_ಸೂಚ್ಯಂಕ;
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = (ಅಕ್ಷರ*)symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
        pn[sym_ಸೂಚ್ಯಂಕ - 1].n_strx = put_elf_str(mo->strtab, name);
        pn[sym_ಸೂಚ್ಯಂಕ - 1].n_ಮೌಲ್ಯ = sym_ಸೂಚ್ಯಂಕ;
    }
    section_ptr_ಕೂಡಿಸು(mo->strtab, -mo->strtab->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ & (PTR_ಗಾತ್ರ - 1));
    tcc_qsort(pn, sym_ಕೊನೆ - 1, ಗಾತ್ರ(*pn), machosymcmp, s1);
    mo->e2msym = tcc_malloc(sym_ಕೊನೆ * ಗಾತ್ರ(*mo->e2msym));
    mo->e2msym[0] = -1;
    ಗಾಗಿ (sym_ಸೂಚ್ಯಂಕ = 1; sym_ಸೂಚ್ಯಂಕ < sym_ಕೊನೆ; ++sym_ಸೂಚ್ಯಂಕ) {
        mo->e2msym[pn[sym_ಸೂಚ್ಯಂಕ - 1].n_ಮೌಲ್ಯ] = sym_ಸೂಚ್ಯಂಕ - 1;
    }
}

ಸ್ಥಿರಾಂಕ ರಚನೆ {
    ಪೂರ್ಣಾಂಕ seg_initial;
    uint32_t flags;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
} skinfo[sk_ಕೊನೆಯ] = {
    /*[sk_unknown] =*/        { 0 },
    /*[sk_discard] =*/        { 0 },
    /*[sk_text] =*/           { 1, S_REGULAR | S_ATTR_ಶುದ್ಧ_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS, "__text" },
    /*[sk_stubs] =*/          { 1, S_REGULAR | S_ATTR_ಶುದ್ಧ_INSTRUCTIONS | S_ಚಿಹ್ನೆ_STUBS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stubs" },
    /*[sk_stub_helper] =*/    { 1, S_REGULAR | S_ATTR_ಶುದ್ಧ_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stub_helper" },
    /*[sk_ro_data] =*/        { 2, S_REGULAR, "__rodata" },
    /*[sk_uw_info] =*/        { 0 },
    /*[sk_nl_ptr] =*/         { 2, S_NON_LAZY_ಚಿಹ್ನೆ_ಸೂಚಕಗಳು, "__got" },
    /*[sk_debug_info] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_info" },
    /*[sk_debug_abbrev] =*/   { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_abbrev" },
    /*[sk_debug_line] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line" },
    /*[sk_debug_aranges] =*/  { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_aranges" },
    /*[sk_debug_str] =*/      { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_str" },
    /*[sk_debug_line_str] =*/ { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line_str" },
    /*[sk_stab] =*/           { 4, S_REGULAR, "__stab" },
    /*[sk_stab_str] =*/       { 4, S_REGULAR, "__stab_str" },
    /*[sk_la_ptr] =*/         { 4, S_LAZY_ಚಿಹ್ನೆ_ಸೂಚಕಗಳು, "__la_symbol_ptr" },
    /*[sk_init] =*/           { 4, S_MOD_INIT_FUNC_ಸೂಚಕಗಳು, "__mod_init_func" },
    /*[sk_fini] =*/           { 4, S_MOD_ಪದ_FUNC_ಸೂಚಕಗಳು, "__mod_term_func" },
    /*[sk_rw_data] =*/        { 4, S_REGULAR, "__data" },
    /*[sk_bss] =*/            { 4, S_ZEROFILL, "__bss" },
    /*[sk_linkedit] =*/       { 5, S_REGULAR, ಖಾಲಿ },
};

#ವ್ಯಾಖ್ಯಾನಿಸು	ಆರಂಭ_3	((uint64_t)1 << 32)

ಸ್ಥಿರಾಂಕ ರಚನೆ {
    ಪೂರ್ಣಾಂಕ ಬಳಸಿದ;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
    uint64_t vmaddr;
    uint64_t vmsize;
    vm_prot_t maxprot;
    vm_prot_t initprot;
    uint32_t flags;
} all_segment[] = {
    { 1, "__PAGEZERO",       0, ಆರಂಭ_3, 0, 0,            0 },
    { 0, "__TEXT",       ಆರಂಭ_3,     0, 5, 5,            0 },
    { 0, "__DATA_CONST",    -1,     0, 3, 3, SG_READ_ONLY },
    { 0, "__DWARF",         -1,     0, 7, 3,            0 },
    { 0, "__DATA",          -1,     0, 3, 3,            0 },
    { 1, "__LINKEDIT",      -1,     0, 1, 1,            0 },
};

#ವ್ಯಾಖ್ಯಾನಿಸು	N_SEGMENT	(ಗಾತ್ರ(all_segment)/ಗಾತ್ರ(all_segment[0]))

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_NEW_MACHO
ಸ್ಥಿರ ಶೂನ್ಯ calc_fixup_ಗಾತ್ರ(TCCState *s1, ರಚನೆ macho *mo)
{
    ಪೂರ್ಣಾಂಕ i, ಗಾತ್ರ_2;

    ಗಾತ್ರ_2 = (ಗಾತ್ರ(ರಚನೆ dyld_chained_fixups_ಶೀರ್ಷಿಕೆ) + 7) & -8;
    ಗಾತ್ರ_2 += (ಗಾತ್ರ(ರಚನೆ dyld_chained_starts_ಒಳ_image) + (mo->nseg - 1) * ಗಾತ್ರ(uint32_t) + 7) & -8;
    ಗಾಗಿ (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	ಪೂರ್ಣಾಂಕ ಪುಟ_ಎಣಿಕೆ = (get_segment(mo, i)->vmsize + SEG_ಪುಟ_ಗಾತ್ರ - 1) / SEG_ಪುಟ_ಗಾತ್ರ;
	ಗಾತ್ರ_2 += (ಗಾತ್ರ(ರಚನೆ dyld_chained_starts_ಒಳ_segment) + (ಪುಟ_ಎಣಿಕೆ - 1) * ಗಾತ್ರ(uint16_t) + 7) & -8;
    }
    ಗಾತ್ರ_2 += mo->n_bind * ಗಾತ್ರ (ರಚನೆ dyld_chained_import) + 1;
    ಗಾಗಿ (i = 0; i < mo->n_bind_rebase; i++) {
	ಆದರೆ (mo->bind_rebase[i].bind) {
	    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
	    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
	    ಗಾತ್ರ_2 += ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name) + 1;
	}
    }
    ಗಾತ್ರ_2 = (ಗಾತ್ರ_2 + 7) & -8;
    section_ptr_ಕೂಡಿಸು(mo->chained_fixups, ಗಾತ್ರ_2);
}

#ಇಲ್ಲದಿದ್ದರೆ

ಸ್ಥಿರ ಶೂನ್ಯ ಗಣ_segment_and_ಸ್ಥಾನಾಂತರ(TCCState *s1, ರಚನೆ macho *mo, addr_t addr,
				   uint8_t *ptr, ಪೂರ್ಣಾಂಕ opcode,
				   Section *sec, addr_t ಸ್ಥಾನಾಂತರ)
{
    ಪೂರ್ಣಾಂಕ i;
    ರಚನೆ segment_command_64 *seg = ಖಾಲಿ;

    ಗಾಗಿ (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	seg = get_segment(mo, i);
	ಆದರೆ (addr >= seg->vmaddr && addr < (seg->vmaddr + seg->vmsize))
	    ನಿಲ್ಲಿಸು;
    }
    *ptr = opcode | i;
    write_uleb128(sec, ಸ್ಥಾನಾಂತರ - seg->vmaddr);
}

ಸ್ಥಿರ ಶೂನ್ಯ bind_rebase(TCCState *s1, ರಚನೆ macho *mo)
{
    ಪೂರ್ಣಾಂಕ i;
    uint8_t *ptr;
    ElfW(Sym) *sym;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;

    ಗಾಗಿ (i = 0; i < mo->n_lazy_bind; i++) {
	ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(mo->s_lazy_bind[i].rel.r_info);

	sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
	name = (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
	write32le(mo->stub_helper->ದತ್ತಾಂಶ +
		  mo->s_lazy_bind[i].bind_ಸ್ಥಾನಾಂತರ,
		  mo->lazy_binding->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
	ptr = section_ptr_ಕೂಡಿಸು(mo->lazy_binding, 1);
	ಗಣ_segment_and_ಸ್ಥಾನಾಂತರ(s1, mo, mo->la_ಚಿಹ್ನೆ_ptr->sh_addr, ptr,
			       BIND_OPCODE_ಗಣ_SEGMENT_AND_ಸ್ಥಾನಾಂತರ_ULEB,
			       mo->lazy_binding,
			       mo->s_lazy_bind[i].la_ಚಿಹ್ನೆ_ಸ್ಥಾನಾಂತರ +
			       mo->la_ಚಿಹ್ನೆ_ptr->sh_addr);
	ptr = section_ptr_ಕೂಡಿಸು(mo->lazy_binding, 5 + ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name));
	*ptr++ = BIND_OPCODE_ಗಣ_DYLIB_SPECIAL_IMM |
		 (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
	*ptr++ = BIND_OPCODE_ಗಣ_ಚಿಹ್ನೆ_TRAILING_FLAGS_IMM | 0;
	strcpy((ಅಕ್ಷರ *)ptr, name);
	ptr += ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name) + 1;
	*ptr++ = BIND_OPCODE_DO_BIND;
	*ptr = BIND_OPCODE_ಮುಗಿದ;
    }
    ಗಾಗಿ (i = 0; i < mo->n_rebase; i++) {
	Section *s = s1->sections[mo->s_rebase[i].section];

	ptr = section_ptr_ಕೂಡಿಸು(mo->rebase, 2);
	*ptr++ = REBASE_OPCODE_ಗಣ_TYPE_IMM | REBASE_TYPE_ಸೂಚಕ;
	ಗಣ_segment_and_ಸ್ಥಾನಾಂತರ(s1, mo, s->sh_addr, ptr,
			       REBASE_OPCODE_ಗಣ_SEGMENT_AND_ಸ್ಥಾನಾಂತರ_ULEB,
			       mo->rebase,
			       mo->s_rebase[i].rel.r_ಸ್ಥಾನಾಂತರ +
			       s->sh_addr);
	ptr = section_ptr_ಕೂಡಿಸು(mo->rebase, 1);
	*ptr = REBASE_OPCODE_DO_REBASE_IMM_TIMES | 1;
    }
    ಗಾಗಿ (i = 0; i < mo->n_bind; i++) {
	ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(mo->bind[i].rel.r_info);
	Section *s = s1->sections[mo->bind[i].section];
	Section *binding;

	sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
	name = (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
	binding = ELFW(ST_BIND)(sym->st_info) == STB_WEAK
	    ? mo->weak_binding : mo->binding;
        ptr = section_ptr_ಕೂಡಿಸು(binding, 4 + (binding == mo->binding) +
			     	       ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name));
	ಆದರೆ (binding == mo->binding)
            *ptr++ = BIND_OPCODE_ಗಣ_DYLIB_SPECIAL_IMM |
	             (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
        *ptr++ = BIND_OPCODE_ಗಣ_ಚಿಹ್ನೆ_TRAILING_FLAGS_IMM |
		 (binding == mo->weak_binding
		  ? BIND_ಚಿಹ್ನೆ_FLAGS_WEAK_IMPORT : 0);
        strcpy((ಅಕ್ಷರ *)ptr, name);
        ptr += ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name) + 1;
        *ptr++ = BIND_OPCODE_ಗಣ_TYPE_IMM | BIND_TYPE_ಸೂಚಕ;
	ಗಣ_segment_and_ಸ್ಥಾನಾಂತರ(s1, mo, s->sh_addr, ptr,
			       BIND_OPCODE_ಗಣ_SEGMENT_AND_ಸ್ಥಾನಾಂತರ_ULEB,
			       binding,
			       mo->bind[i].rel.r_ಸ್ಥಾನಾಂತರ + s->sh_addr);
        ptr = section_ptr_ಕೂಡಿಸು(binding, 1);
        *ptr++ = BIND_OPCODE_DO_BIND;
    }
    ಆದರೆ (mo->rebase->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        ptr = section_ptr_ಕೂಡಿಸು(mo->rebase, 1);
        *ptr = REBASE_OPCODE_ಮುಗಿದ;
    }
    ಆದರೆ (mo->binding->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        ptr = section_ptr_ಕೂಡಿಸು(mo->binding, 1);
        *ptr = BIND_OPCODE_ಮುಗಿದ;
    }
    ಆದರೆ (mo->weak_binding->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        ptr = section_ptr_ಕೂಡಿಸು(mo->weak_binding, 1);
        *ptr = BIND_OPCODE_ಮುಗಿದ;
    }
    tcc_free(mo->s_lazy_bind);
    tcc_free(mo->s_rebase);
    tcc_free(mo->bind);
}
#ಆದರೆ_ಅಂತ್ಯ

ರಚನೆ trie_info {
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
    ಪೂರ್ಣಾಂಕ flag;
    addr_t addr;
    ಪೂರ್ಣಾಂಕ str_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ ಪದ_ಗಾತ್ರ;
};

ರಚನೆ trie_ಗಂಟು {
    ಪೂರ್ಣಾಂಕ ಆರಂಭ;
    ಪೂರ್ಣಾಂಕ ಕೊನೆ;
    ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ_ಆರಂಭ;
    ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ_ಕೊನೆ;
    ಪೂರ್ಣಾಂಕ n_ಮಗು;
    ರಚನೆ trie_ಗಂಟು *ಮಗು;
};

ರಚನೆ trie_seq {
    ಪೂರ್ಣಾಂಕ n_ಮಗು;
    ರಚನೆ trie_ಗಂಟು *ಗಂಟು;
    ಪೂರ್ಣಾಂಕ ಸ್ಥಾನಾಂತರ;
    ಪೂರ್ಣಾಂಕ nest_ಸ್ಥಾನಾಂತರ;
};

ಸ್ಥಿರ ಶೂನ್ಯ create_trie(ರಚನೆ trie_ಗಂಟು *ಗಂಟು,
                        ಪೂರ್ಣಾಂಕ from, ಪೂರ್ಣಾಂಕ ಗಮ್ಯ, ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ_ಆರಂಭ,
                        ಪೂರ್ಣಾಂಕ n_trie, ರಚನೆ trie_info *trie)
{
    ಪೂರ್ಣಾಂಕ i;
    ಪೂರ್ಣಾಂಕ ಆರಂಭ, ಕೊನೆ, ಸೂಚ್ಯಂಕ_ಕೊನೆ;
    ಅಕ್ಷರ cur;
    ರಚನೆ trie_ಗಂಟು *ಮಗು;

    ಗಾಗಿ (i = from; i < ಗಮ್ಯ; i = ಕೊನೆ) {
        cur = trie[i].name[ಸೂಚ್ಯಂಕ_ಆರಂಭ];
        ಆರಂಭ = i++;
        ಗಾಗಿ (; i < ಗಮ್ಯ; i++)
            ಆದರೆ (cur != trie[i].name[ಸೂಚ್ಯಂಕ_ಆರಂಭ])
                ನಿಲ್ಲಿಸು;
        ಕೊನೆ = i;
        ಆದರೆ (ಆರಂಭ == ಕೊನೆ - 1 ||
            (trie[ಆರಂಭ].name[ಸೂಚ್ಯಂಕ_ಆರಂಭ] &&
             trie[ಆರಂಭ].name[ಸೂಚ್ಯಂಕ_ಆರಂಭ + 1] == 0))
            ಸೂಚ್ಯಂಕ_ಕೊನೆ = trie[ಆರಂಭ].str_ಗಾತ್ರ - 1;
        ಇಲ್ಲದಿದ್ದರೆ {
            ಸೂಚ್ಯಂಕ_ಕೊನೆ = ಸೂಚ್ಯಂಕ_ಆರಂಭ + 1;
            ಗಾಗಿ (;;) {
                cur = trie[ಆರಂಭ].name[ಸೂಚ್ಯಂಕ_ಕೊನೆ];
                ಗಾಗಿ (i = ಆರಂಭ + 1; i < ಕೊನೆ; i++)
                    ಆದರೆ (cur != trie[i].name[ಸೂಚ್ಯಂಕ_ಕೊನೆ])
                        ನಿಲ್ಲಿಸು;
                ಆದರೆ (trie[ಆರಂಭ].name[ಸೂಚ್ಯಂಕ_ಕೊನೆ] &&
                    trie[ಆರಂಭ].name[ಸೂಚ್ಯಂಕ_ಕೊನೆ + 1] == 0) {
                    ಕೊನೆ = ಆರಂಭ + 1;
                    ಸೂಚ್ಯಂಕ_ಕೊನೆ = trie[ಆರಂಭ].str_ಗಾತ್ರ - 1;
                    ನಿಲ್ಲಿಸು;
                }
                ಆದರೆ (i != ಕೊನೆ)
                    ನಿಲ್ಲಿಸು;
                ಸೂಚ್ಯಂಕ_ಕೊನೆ++;
            }
        }
        ಗಂಟು->ಮಗು = tcc_realloc(ಗಂಟು->ಮಗು,
                                  (ಗಂಟು->n_ಮಗು + 1) *
                                  ಗಾತ್ರ(ರಚನೆ trie_ಗಂಟು));
        ಮಗು = &ಗಂಟು->ಮಗು[ಗಂಟು->n_ಮಗು];
        ಮಗು->ಆರಂಭ = ಆರಂಭ;
        ಮಗು->ಕೊನೆ = ಕೊನೆ;
        ಮಗು->ಸೂಚ್ಯಂಕ_ಆರಂಭ = ಸೂಚ್ಯಂಕ_ಆರಂಭ;
        ಮಗು->ಸೂಚ್ಯಂಕ_ಕೊನೆ = ಸೂಚ್ಯಂಕ_ಕೊನೆ;
        ಮಗು->n_ಮಗು = 0;
        ಮಗು->ಮಗು = ಖಾಲಿ;
        ಗಂಟು->n_ಮಗು++;
        ಆದರೆ (ಆರಂಭ != ಕೊನೆ - 1)
            create_trie(ಮಗು, ಆರಂಭ, ಕೊನೆ, ಸೂಚ್ಯಂಕ_ಕೊನೆ, n_trie, trie);
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ create_seq(ಪೂರ್ಣಾಂಕ *ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ *n_seq, ರಚನೆ trie_seq **seq,
                        ರಚನೆ trie_ಗಂಟು *ಗಂಟು,
                        ಪೂರ್ಣಾಂಕ n_trie, ರಚನೆ trie_info *trie)
{
    ಪೂರ್ಣಾಂಕ i, nest_ಸ್ಥಾನಾಂತರ, ಕೊನೆಯ_seq = *n_seq, retval = *ಸ್ಥಾನಾಂತರ;
    ರಚನೆ trie_seq *p_seq;
    ರಚನೆ trie_ಗಂಟು *p_nest;

    ಗಾಗಿ (i = 0; i < ಗಂಟು->n_ಮಗು; i++) {
        p_nest = &ಗಂಟು->ಮಗು[i];
        *seq = tcc_realloc(*seq, (*n_seq + 1) * ಗಾತ್ರ(ರಚನೆ trie_seq));
        p_seq = &(*seq)[(*n_seq)++];
        p_seq->n_ಮಗು = i == 0 ? ಗಂಟು->n_ಮಗು : -1;
        p_seq->ಗಂಟು = p_nest;
        p_seq->ಸ್ಥಾನಾಂತರ = *ಸ್ಥಾನಾಂತರ;
        p_seq->nest_ಸ್ಥಾನಾಂತರ = 0;
        *ಸ್ಥಾನಾಂತರ += (i == 0 ? 1 + 1 : 0) +
                   p_nest->ಸೂಚ್ಯಂಕ_ಕೊನೆ - p_nest->ಸೂಚ್ಯಂಕ_ಆರಂಭ + 1 + 3;
    }
    ಗಾಗಿ (i = 0; i < ಗಂಟು->n_ಮಗು; i++) {
        nest_ಸ್ಥಾನಾಂತರ =
            create_seq(ಸ್ಥಾನಾಂತರ, n_seq, seq, &ಗಂಟು->ಮಗು[i], n_trie, trie);
        p_seq = &(*seq)[ಕೊನೆಯ_seq + i];
        p_seq->nest_ಸ್ಥಾನಾಂತರ = nest_ಸ್ಥಾನಾಂತರ;
    }
    ಹಿಂತಿರುಗಿ retval;
}

ಸ್ಥಿರ ಶೂನ್ಯ ಗಂಟು_free(ರಚನೆ trie_ಗಂಟು *ಗಂಟು)
{
    ಪೂರ್ಣಾಂಕ i;

    ಗಾಗಿ (i = 0; i < ಗಂಟು->n_ಮಗು; i++)
	ಗಂಟು_free(&ಗಂಟು->ಮಗು[i]);
    tcc_free(ಗಂಟು->ಮಗು);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ triecmp(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *_a, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *_b, ಶೂನ್ಯ *arg)
{
    ರಚನೆ trie_info *a = (ರಚನೆ trie_info *) _a;
    ರಚನೆ trie_info *b = (ರಚನೆ trie_info *) _b;
    ಪೂರ್ಣಾಂಕ len_a = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(a->name);
    ಪೂರ್ಣಾಂಕ len_b = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(b->name);

    /* strange sorting needed. Name 'xx' should be after 'xx1' */
    ಆದರೆ (!ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(a->name, b->name, len_a < len_b ? len_a : len_b))
	ಹಿಂತಿರುಗಿ len_a < len_b ? 1 : (len_a > len_b ? -1 : 0);
    ಹಿಂತಿರುಗಿ strcmp(a->name, b->name);
}

ಸ್ಥಿರ ಶೂನ್ಯ export_trie(TCCState *s1, ರಚನೆ macho *mo)
{
    ಪೂರ್ಣಾಂಕ i, ಗಾತ್ರ_2, ಸ್ಥಾನಾಂತರ = 0, save_ಸ್ಥಾನಾಂತರ;
    uint8_t *ptr;
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ;
    ಪೂರ್ಣಾಂಕ sym_ಕೊನೆ = symtab_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ(ElfW(Sym));
    ಪೂರ್ಣಾಂಕ n_trie = 0, n_seq = 0;
    ರಚನೆ trie_info *trie = ಖಾಲಿ, *p_trie;
    ರಚನೆ trie_ಗಂಟು ಗಂಟು, *p_ಗಂಟು;
    ರಚನೆ trie_seq *seq = ಖಾಲಿ;
    addr_t vm_addr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;

    ಗಾಗಿ (sym_ಸೂಚ್ಯಂಕ = 1; sym_ಸೂಚ್ಯಂಕ < sym_ಕೊನೆ; ++sym_ಸೂಚ್ಯಂಕ) {
	ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ + sym_ಸೂಚ್ಯಂಕ;
	ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = (ಅಕ್ಷರ*)symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;

	ಆದರೆ (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE &&
            (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL ||
	     ELFW(ST_BIND)(sym->st_info) == STB_WEAK)) {
	    ಪೂರ್ಣಾಂಕ flag = EXPORT_ಚಿಹ್ನೆ_FLAGS_ಬಗೆ_REGULAR;
	    addr_t addr =
		sym->st_ಮೌಲ್ಯ + s1->sections[sym->st_shndx]->sh_addr - vm_addr;

	    ಆದರೆ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
		flag |= EXPORT_ಚಿಹ್ನೆ_FLAGS_WEAK_DEFINITION;
	    dprintf ("%s %d %llx\n", name, flag, (ದೀರ್ಘ ದೀರ್ಘ)addr + vm_addr);
	    trie = tcc_realloc(trie, (n_trie + 1) * ಗಾತ್ರ(ರಚನೆ trie_info));
	    trie[n_trie].name = name;
	    trie[n_trie].flag = flag;
	    trie[n_trie].addr = addr;
	    trie[n_trie].str_ಗಾತ್ರ = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name) + 1;
	    trie[n_trie].ಪದ_ಗಾತ್ರ = uleb128_ಗಾತ್ರ(flag) + uleb128_ಗಾತ್ರ(addr);
	    n_trie++;
	}
    }
    ಆದರೆ (n_trie) {
        tcc_qsort(trie, n_trie, ಗಾತ್ರ(ರಚನೆ trie_info), triecmp, ಖಾಲಿ);
	memset(&ಗಂಟು, 0, ಗಾತ್ರ(ಗಂಟು));
        create_trie(&ಗಂಟು, 0, n_trie, 0, n_trie, trie);
	create_seq(&ಸ್ಥಾನಾಂತರ, &n_seq, &seq, &ಗಂಟು, n_trie, trie);
        save_ಸ್ಥಾನಾಂತರ = ಸ್ಥಾನಾಂತರ;
        ಗಾಗಿ (i = 0; i < n_seq; i++) {
            p_ಗಂಟು = seq[i].ಗಂಟು;
            ಆದರೆ (p_ಗಂಟು->n_ಮಗು == 0) {
                p_trie = &trie[p_ಗಂಟು->ಆರಂಭ];
                seq[i].nest_ಸ್ಥಾನಾಂತರ = ಸ್ಥಾನಾಂತರ;
                ಸ್ಥಾನಾಂತರ += 1 + p_trie->ಪದ_ಗಾತ್ರ + 1;
            }
        }
        ಗಾಗಿ (i = 0; i < n_seq; i++) {
            p_ಗಂಟು = seq[i].ಗಂಟು;
            p_trie = &trie[p_ಗಂಟು->ಆರಂಭ];
            ಆದರೆ (seq[i].n_ಮಗು >= 0) {
                section_ptr_ಕೂಡಿಸು(mo->exports,
				seq[i].ಸ್ಥಾನಾಂತರ - mo->exports->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
                ptr = section_ptr_ಕೂಡಿಸು(mo->exports, 2);
                *ptr++ = 0;
                *ptr = seq[i].n_ಮಗು;
            }
            ಗಾತ್ರ_2 = p_ಗಂಟು->ಸೂಚ್ಯಂಕ_ಕೊನೆ - p_ಗಂಟು->ಸೂಚ್ಯಂಕ_ಆರಂಭ;
            ptr = section_ptr_ಕೂಡಿಸು(mo->exports, ಗಾತ್ರ_2 + 1);
            ಸ್ಮರಣೆ_ನಕಲು(ptr, &p_trie->name[p_ಗಂಟು->ಸೂಚ್ಯಂಕ_ಆರಂಭ], ಗಾತ್ರ_2);
            ptr[ಗಾತ್ರ_2] = 0;
            write_uleb128(mo->exports, seq[i].nest_ಸ್ಥಾನಾಂತರ);
        }
        section_ptr_ಕೂಡಿಸು(mo->exports, save_ಸ್ಥಾನಾಂತರ - mo->exports->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
        ಗಾಗಿ (i = 0; i < n_seq; i++) {
            p_ಗಂಟು = seq[i].ಗಂಟು;
            ಆದರೆ (p_ಗಂಟು->n_ಮಗು == 0) {
                p_trie = &trie[p_ಗಂಟು->ಆರಂಭ];
                write_uleb128(mo->exports, p_trie->ಪದ_ಗಾತ್ರ);
                write_uleb128(mo->exports, p_trie->flag);
                write_uleb128(mo->exports, p_trie->addr);
                ptr = section_ptr_ಕೂಡಿಸು(mo->exports, 1);
                *ptr = 0;
            }
        }
        section_ptr_ಕೂಡಿಸು(mo->exports, -mo->exports->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ & 7);
	ಗಂಟು_free(&ಗಂಟು);
        tcc_free(seq);
    }
    tcc_free(trie);
}

ಸ್ಥಿರ ಶೂನ್ಯ collect_sections(TCCState *s1, ರಚನೆ macho *mo, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    ಪೂರ್ಣಾಂಕ i, sk, numsec;
    ಪೂರ್ಣಾಂಕ ಬಳಸಿದ_segment[N_SEGMENT];
    uint64_t curaddr, fileofs;
    Section *s;
    ರಚನೆ segment_command_64 *seg;
    ರಚನೆ dylib_command *dylib;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_NEW_MACHO
    ರಚನೆ linkedit_ದತ್ತಾಂಶ_command *chained_fixups_lc;
    ರಚನೆ linkedit_ದತ್ತಾಂಶ_command *export_trie_lc;
#ಆದರೆ_ಅಂತ್ಯ
    ರಚನೆ build_ಆವೃತ್ತಿ_command *dyldbv;
    ರಚನೆ ಮೂಲ_ಆವೃತ್ತಿ_command *dyldsv;
    ರಚನೆ rpath_command *rpath;
    ರಚನೆ dylinker_command *dyldlc;
    ರಚನೆ symtab_command *symlc;
    ರಚನೆ dysymtab_command *dysymlc;
    ಅಕ್ಷರ *str;

    ಗಾಗಿ (i = 0; i < N_SEGMENT; i++)
	ಬಳಸಿದ_segment[i] = all_segment[i].ಬಳಸಿದ;

    memset (mo->sk_ಗಮ್ಯ_sect, 0, ಗಾತ್ರ(mo->sk_ಗಮ್ಯ_sect));
    ಗಾಗಿ (i = s1->nb_sections; i-- > 1;) {
        ಪೂರ್ಣಾಂಕ type, flags;
        s = s1->sections[i];
        type = s->sh_type;
        flags = s->sh_flags;
        sk = sk_unknown;
	/* debug sections have sometimes no SHF_ALLOC */
        ಆದರೆ ((flags & SHF_ALLOC) || !ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(s->name, ".debug_", 7)) {
            ಆಯ್ಕೆ (type) {
            ಪೂರ್ವನಿಯೋಜಿತ:           sk = sk_unknown; ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ SHT_INIT_ARRAY: sk = sk_init; ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ SHT_FINI_ARRAY: sk = sk_fini; ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ SHT_NOBITS:   sk = sk_bss; ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ SHT_SYMTAB:   sk = sk_discard; ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ SHT_STRTAB:
		ಆದರೆ (s == stabstr_section)
		  sk = sk_stab_str;
		ಇಲ್ಲದಿದ್ದರೆ
		  sk = sk_discard;
		ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ SHT_RELX:     sk = sk_discard; ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ SHT_LINKEDIT: sk = sk_linkedit; ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ SHT_PROGBITS:
                ಆದರೆ (s == mo->stubs)
                  sk = sk_stubs;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_NEW_MACHO
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == mo->stub_helper)
                  sk = sk_stub_helper;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == mo->la_ಚಿಹ್ನೆ_ptr)
                  sk = sk_la_ptr;
#ಆದರೆ_ಅಂತ್ಯ
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == rodata_section)
                  sk = sk_ro_ದತ್ತಾಂಶ;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == s1->got)
                  sk = sk_nl_ptr;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == stab_section)
                  sk = sk_stab;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == dwarf_info_section)
                  sk = sk_debug_info;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == dwarf_abbrev_section)
                  sk = sk_debug_abbrev;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == dwarf_ಸಾಲು_section)
                  sk = sk_debug_ಸಾಲು;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == dwarf_aranges_section)
                  sk = sk_debug_aranges;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == dwarf_str_section)
                  sk = sk_debug_str;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == dwarf_ಸಾಲು_str_section)
                  sk = sk_debug_ಸಾಲು_str;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (flags & SHF_EXECINSTR)
                  sk = sk_ಪಠ್ಯ;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (flags & SHF_WRITE)
                  sk = sk_rw_ದತ್ತಾಂಶ;
                ಇಲ್ಲದಿದ್ದರೆ
                  sk = sk_ro_ದತ್ತಾಂಶ;
                ನಿಲ್ಲಿಸು;
            }
        } ಇಲ್ಲದಿದ್ದರೆ
          sk = sk_discard;
        s->prev = mo->sk_ಗಮ್ಯ_sect[sk].s;
        mo->sk_ಗಮ್ಯ_sect[sk].s = s;
	ಬಳಸಿದ_segment[skinfo[sk].seg_initial] = 1;
    }

    ಆದರೆ (s1->output_type != TCC_OUTPUT_EXE)
	ಬಳಸಿದ_segment[0] = 0;

    ಗಾಗಿ (i = 0; i < N_SEGMENT; i++)
	ಆದರೆ (ಬಳಸಿದ_segment[i]) {
	    seg = ಕೂಡಿಸು_segment(mo, all_segment[i].name);
	    ಆದರೆ (i == 1 && s1->output_type != TCC_OUTPUT_EXE)
	        seg->vmaddr = 0;
	    ಇಲ್ಲದಿದ್ದರೆ
	        seg->vmaddr = all_segment[i].vmaddr;
	    seg->vmsize = all_segment[i].vmsize;
	    seg->maxprot = all_segment[i].maxprot;
	    seg->initprot = all_segment[i].initprot;
	    seg->flags = all_segment[i].flags;
            ಗಾಗಿ (sk = sk_unknown; sk < sk_ಕೊನೆಯ; sk++)
		ಆದರೆ (skinfo[sk].seg_initial == i)
	            mo->segment[sk] = mo->nseg - 1;
	}

    ಆದರೆ (s1->output_type != TCC_OUTPUT_EXE) {
	ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = s1->install_name ? s1->install_name : filename;
        i = (ಗಾತ್ರ(*dylib) + ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name) + 1 + 7) &-8;
        dylib = ಕೂಡಿಸು_lc(mo, LC_ID_DYLIB, i);
	dylib->name = ಗಾತ್ರ(*dylib);
	dylib->timestamp = 1;
	dylib->current_ಆವೃತ್ತಿ =
	    s1->current_ಆವೃತ್ತಿ ? s1->current_ಆವೃತ್ತಿ : 1 << 16;
	dylib->compatibility_ಆವೃತ್ತಿ =
	    s1->compatibility_ಆವೃತ್ತಿ ? s1->compatibility_ಆವೃತ್ತಿ : 1 << 16;
        str = (ಅಕ್ಷರ*)dylib + dylib->name;
        strcpy(str, name);
    }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_NEW_MACHO
    chained_fixups_lc = ಕೂಡಿಸು_lc(mo, LC_DYLD_CHAINED_FIXUPS,
			       ಗಾತ್ರ(ರಚನೆ linkedit_ದತ್ತಾಂಶ_command));
    export_trie_lc = ಕೂಡಿಸು_lc(mo, LC_DYLD_EXPORTS_TRIE,
			    ಗಾತ್ರ(ರಚನೆ linkedit_ದತ್ತಾಂಶ_command));
#ಇಲ್ಲದಿದ್ದರೆ
    mo->dyldinfo = ಕೂಡಿಸು_lc(mo, LC_DYLD_INFO_ONLY, ಗಾತ್ರ(*mo->dyldinfo));
#ಆದರೆ_ಅಂತ್ಯ

    symlc = ಕೂಡಿಸು_lc(mo, LC_SYMTAB, ಗಾತ್ರ(*symlc));
    dysymlc = ಕೂಡಿಸು_lc(mo, LC_DYSYMTAB, ಗಾತ್ರ(*dysymlc));

    ಆದರೆ (s1->output_type == TCC_OUTPUT_EXE) {
        i = (ಗಾತ್ರ(*dyldlc) + ಅಕ್ಷರಸರಣಿ_ಉದ್ದ("/usr/lib/dyld") + 1 + 7) &-8;
        dyldlc = ಕೂಡಿಸು_lc(mo, LC_ತುಂಬು_DYLINKER, i);
        dyldlc->name = ಗಾತ್ರ(*dyldlc);
        str = (ಅಕ್ಷರ*)dyldlc + dyldlc->name;
        strcpy(str, "/usr/lib/dyld");
    }

    dyldbv = ಕೂಡಿಸು_lc(mo, LC_BUILD_ಆವೃತ್ತಿ, ಗಾತ್ರ(*dyldbv));
    dyldbv->platform = PLATFORM_MACOS;
    dyldbv->minos = (10 << 16) + (6 << 8);
    dyldbv->sdk = (10 << 16) + (6 << 8);
    dyldbv->ntools = 0;

    dyldsv = ಕೂಡಿಸು_lc(mo, LC_ಮೂಲ_ಆವೃತ್ತಿ, ಗಾತ್ರ(*dyldsv));
    dyldsv->ಆವೃತ್ತಿ = 0;

    ಆದರೆ (s1->output_type == TCC_OUTPUT_EXE) {
        mo->ep = ಕೂಡಿಸು_lc(mo, LC_MAIN, ಗಾತ್ರ(*mo->ep));
        mo->ep->entryoff = 4096;
    }

    ಗಾಗಿ(i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *dllref = s1->loaded_dlls[i];
        ಆದರೆ (dllref->level == 0)
          ಕೂಡಿಸು_dylib(mo, dllref->name);
    }

    ಆದರೆ (s1->rpath) {
	ಅಕ್ಷರ *ಮಾರ್ಗ = s1->rpath, *ಕೊನೆ;
	ಮಾಡು {
	    ಕೊನೆ = strchr(ಮಾರ್ಗ, ':');
	    ಆದರೆ (!ಕೊನೆ)
		ಕೊನೆ = strchr(ಮಾರ್ಗ, 0);
            i = (ಗಾತ್ರ(*rpath) + (ಕೊನೆ - ಮಾರ್ಗ) + 1 + 7) &-8;
            rpath = ಕೂಡಿಸು_lc(mo, LC_RPATH, i);
            rpath->ಮಾರ್ಗ = ಗಾತ್ರ(*rpath);
            str = (ಅಕ್ಷರ*)rpath + rpath->ಮಾರ್ಗ;
            ಸ್ಮರಣೆ_ನಕಲು(str, ಮಾರ್ಗ, ಕೊನೆ - ಮಾರ್ಗ);
	    str[ಕೊನೆ - ಮಾರ್ಗ] = 0;
	    ಮಾರ್ಗ = ಕೊನೆ + 1;
	} ಆಗ (*ಕೊನೆ);
    }

    fileofs = 4096;  /* leave space for mach-o headers */
    curaddr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;
    curaddr += 4096;
    seg = ಖಾಲಿ;
    numsec = 0;
    mo->elfsectomacho = tcc_mallocz(ಗಾತ್ರ(*mo->elfsectomacho) * s1->nb_sections);
    ಗಾಗಿ (sk = sk_unknown; sk < sk_ಕೊನೆಯ; sk++) {
        ರಚನೆ section_64 *sec = ಖಾಲಿ;
        ಆದರೆ (seg) {
            seg->vmsize = curaddr - seg->vmaddr;
            seg->filesize = fileofs - seg->fileoff;
        }
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_NEW_MACHO
	ಆದರೆ (sk == sk_linkedit) {
	    calc_fixup_ಗಾತ್ರ(s1, mo);
	    export_trie(s1, mo);
	}
#ಇಲ್ಲದಿದ್ದರೆ
	ಆದರೆ (sk == sk_linkedit) {
	    bind_rebase(s1, mo);
	    export_trie(s1, mo);
	}
#ಆದರೆ_ಅಂತ್ಯ
        ಆದರೆ (skinfo[sk].seg_initial &&
	    (s1->output_type != TCC_OUTPUT_EXE || mo->segment[sk]) &&
	    mo->sk_ಗಮ್ಯ_sect[sk].s) {
            uint64_t al = 0;
            ಪೂರ್ಣಾಂಕ si;
            seg = get_segment(mo, mo->segment[sk]);
            ಆದರೆ (skinfo[sk].name) {
                si = ಕೂಡಿಸು_section(mo, &seg, skinfo[sk].name);
                numsec++;
                mo->lc[mo->seg2lc[mo->segment[sk]]] = (ರಚನೆ ತುಂಬು_command*)seg;
                mo->sk_ಗಮ್ಯ_sect[sk].machosect = si;
                sec = get_section(seg, si);
                sec->flags = skinfo[sk].flags;
		ಆದರೆ (sk == sk_stubs)
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
	    	    sec->reserved2 = 6;
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
	    	    sec->reserved2 = 12;
#ಆದರೆ_ಅಂತ್ಯ
		ಆದರೆ (sk == sk_nl_ptr)
	    	    sec->reserved1 = mo->nr_plt;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_NEW_MACHO
		ಆದರೆ (sk == sk_la_ptr)
	    	    sec->reserved1 = mo->nr_plt + mo->n_got;
#ಆದರೆ_ಅಂತ್ಯ
            }
            ಆದರೆ (seg->vmaddr == -1) {
                curaddr = (curaddr + SEG_ಪುಟ_ಗಾತ್ರ - 1) & -SEG_ಪುಟ_ಗಾತ್ರ;
                seg->vmaddr = curaddr;
                fileofs = (fileofs + SEG_ಪುಟ_ಗಾತ್ರ - 1) & -SEG_ಪುಟ_ಗಾತ್ರ;
                seg->fileoff = fileofs;
            }

            ಗಾಗಿ (s = mo->sk_ಗಮ್ಯ_sect[sk].s; s; s = s->prev) {
                ಪೂರ್ಣಾಂಕ a = exact_log2p1(s->sh_addralign);
                ಆದರೆ (a && al < (a - 1))
                  al = a - 1;
                s->sh_ಗಾತ್ರ = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
            }
            ಆದರೆ (sec)
              sec->align = al;
            al = 1ULL << al;
            ಆದರೆ (al > 4096)
              tcc_warning("alignment > 4096"), sec->align = 12, al = 4096;
            curaddr = (curaddr + al - 1) & -al;
            fileofs = (fileofs + al - 1) & -al;
            ಆದರೆ (sec) {
                sec->addr = curaddr;
                sec->ಸ್ಥಾನಾಂತರ = fileofs;
            }
            ಗಾಗಿ (s = mo->sk_ಗಮ್ಯ_sect[sk].s; s; s = s->prev) {
                al = s->sh_addralign;
                curaddr = (curaddr + al - 1) & -al;
                dprintf("%s: curaddr now 0x%lx\n", s->name, (ದೀರ್ಘ)curaddr);
                s->sh_addr = curaddr;
                curaddr += s->sh_ಗಾತ್ರ;
                ಆದರೆ (s->sh_type != SHT_NOBITS) {
                    fileofs = (fileofs + al - 1) & -al;
                    s->sh_ಸ್ಥಾನಾಂತರ = fileofs;
                    fileofs += s->sh_ಗಾತ್ರ;
                    dprintf("%s: fileofs now %ld\n", s->name, (ದೀರ್ಘ)fileofs);
                }
                ಆದರೆ (sec)
                  mo->elfsectomacho[s->sh_ಅಂಕೆ] = numsec;
            }
            ಆದರೆ (sec)
              sec->ಗಾತ್ರ_2 = curaddr - sec->addr;
        }
        ಆದರೆ (DEBUG_MACHO)
          ಗಾಗಿ (s = mo->sk_ಗಮ್ಯ_sect[sk].s; s; s = s->prev) {
              ಪೂರ್ಣಾಂಕ type = s->sh_type;
              ಪೂರ್ಣಾಂಕ flags = s->sh_flags;
              ಬರೆ("%d section %-16s %-10s %09lx %04x %02d %s,%s,%s\n",
                     sk,
                     s->name,
                     type == SHT_PROGBITS ? "progbits" :
                     type == SHT_NOBITS ? "nobits" :
                     type == SHT_SYMTAB ? "symtab" :
                     type == SHT_STRTAB ? "strtab" :
                     type == SHT_INIT_ARRAY ? "init" :
                     type == SHT_FINI_ARRAY ? "fini" :
                     type == SHT_RELX ? "rel" : "???",
                     (ದೀರ್ಘ)s->sh_addr,
                     (ಚಿಹ್ನೆರಹಿತ)s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ,
                     s->sh_addralign,
                     flags & SHF_ALLOC ? "alloc" : "",
                     flags & SHF_WRITE ? "write" : "",
                     flags & SHF_EXECINSTR ? "exec" : ""
                    );
          }
    }
    ಆದರೆ (seg) {
        seg->vmsize = curaddr - seg->vmaddr;
        seg->filesize = fileofs - seg->fileoff;
    }

    /* Fill symtab info */
    symlc->symoff = mo->symtab->sh_ಸ್ಥಾನಾಂತರ;
    symlc->nsyms = mo->symtab->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ(ರಚನೆ nlist_64);
    symlc->stroff = mo->strtab->sh_ಸ್ಥಾನಾಂತರ;
    symlc->strsize = mo->strtab->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

    dysymlc->iundefsym = mo->iundef == -1 ? symlc->nsyms : mo->iundef;
    dysymlc->iextdefsym = mo->iextdef == -1 ? dysymlc->iundefsym : mo->iextdef;
    dysymlc->ilocalsym = mo->ilocal == -1 ? dysymlc->iextdefsym : mo->ilocal;
    dysymlc->nlocalsym = dysymlc->iextdefsym - dysymlc->ilocalsym;
    dysymlc->nextdefsym = dysymlc->iundefsym - dysymlc->iextdefsym;
    dysymlc->nundefsym = symlc->nsyms - dysymlc->iundefsym;
    dysymlc->indirectsymoff = mo->indirsyms->sh_ಸ್ಥಾನಾಂತರ;
    dysymlc->nindirectsyms = mo->indirsyms->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ(uint32_t);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_NEW_MACHO
    ಆದರೆ (mo->chained_fixups->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        chained_fixups_lc->dataoff = mo->chained_fixups->sh_ಸ್ಥಾನಾಂತರ;
        chained_fixups_lc->datasize = mo->chained_fixups->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    }
    ಆದರೆ (mo->exports->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        export_trie_lc->dataoff = mo->exports->sh_ಸ್ಥಾನಾಂತರ;
        export_trie_lc->datasize = mo->exports->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    }
#ಇಲ್ಲದಿದ್ದರೆ
    ಆದರೆ (mo->rebase->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        mo->dyldinfo->rebase_off = mo->rebase->sh_ಸ್ಥಾನಾಂತರ;
        mo->dyldinfo->rebase_ಗಾತ್ರ = mo->rebase->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    }
    ಆದರೆ (mo->binding->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        mo->dyldinfo->bind_off = mo->binding->sh_ಸ್ಥಾನಾಂತರ;
        mo->dyldinfo->bind_ಗಾತ್ರ = mo->binding->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    }
    ಆದರೆ (mo->weak_binding->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        mo->dyldinfo->weak_bind_off = mo->weak_binding->sh_ಸ್ಥಾನಾಂತರ;
        mo->dyldinfo->weak_bind_ಗಾತ್ರ = mo->weak_binding->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    }
    ಆದರೆ (mo->lazy_binding->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        mo->dyldinfo->lazy_bind_off = mo->lazy_binding->sh_ಸ್ಥಾನಾಂತರ;
        mo->dyldinfo->lazy_bind_ಗಾತ್ರ = mo->lazy_binding->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    }
    ಆದರೆ (mo->exports->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ) {
        mo->dyldinfo->export_off = mo->exports->sh_ಸ್ಥಾನಾಂತರ;
        mo->dyldinfo->export_ಗಾತ್ರ = mo->exports->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    }
#ಆದರೆ_ಅಂತ್ಯ
}

ಸ್ಥಿರ ಶೂನ್ಯ macho_write(TCCState *s1, ರಚನೆ macho *mo, FILE *fp)
{
    ಪೂರ್ಣಾಂಕ i, sk;
    uint64_t fileofs = 0;
    Section *s;
    mo->mh.mh.magic = MH_MAGIC_64;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    mo->mh.mh.cputype = CPU_TYPE_X86_64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_LIB64 | CPU_SUBTYPE_X86_ALL;
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
    mo->mh.mh.cputype = CPU_TYPE_ARM64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_ARM64_ALL;
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (s1->output_type == TCC_OUTPUT_EXE) {
        mo->mh.mh.filetype = MH_EXECUTE;
        mo->mh.mh.flags = MH_DYLDLINK | MH_PIE;
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        mo->mh.mh.filetype = MH_DYLIB;
        mo->mh.mh.flags = MH_DYLDLINK;
    }
    mo->mh.mh.ncmds = mo->nlc;
    mo->mh.mh.sizeofcmds = 0;
    ಗಾಗಿ (i = 0; i < mo->nlc; i++)
      mo->mh.mh.sizeofcmds += mo->lc[i]->cmdsize;

    fwrite(&mo->mh, 1, ಗಾತ್ರ(mo->mh), fp);
    fileofs += ಗಾತ್ರ(mo->mh);
    ಗಾಗಿ (i = 0; i < mo->nlc; i++) {
        fwrite(mo->lc[i], 1, mo->lc[i]->cmdsize, fp);
        fileofs += mo->lc[i]->cmdsize;
    }

    ಗಾಗಿ (sk = sk_unknown; sk < sk_ಕೊನೆಯ; sk++) {
        //struct segment_command_64 *seg;
        ಆದರೆ (skinfo[sk].seg_initial == 0 ||
	    (s1->output_type == TCC_OUTPUT_EXE && !mo->segment[sk]) ||
	    !mo->sk_ಗಮ್ಯ_sect[sk].s)
          ಮುಂದುವರಿ;
        /*seg =*/ get_segment(mo, mo->segment[sk]);
        ಗಾಗಿ (s = mo->sk_ಗಮ್ಯ_sect[sk].s; s; s = s->prev) {
            ಆದರೆ (s->sh_type != SHT_NOBITS) {
                ಆಗ (fileofs < s->sh_ಸ್ಥಾನಾಂತರ)
                  fputc(0, fp), fileofs++;
                ಆದರೆ (s->sh_ಗಾತ್ರ) {
                    fwrite(s->ದತ್ತಾಂಶ, 1, s->sh_ಗಾತ್ರ, fp);
                    fileofs += s->sh_ಗಾತ್ರ;
                }
            }
        }
    }
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_NEW_MACHO
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ bind_rebase_cmp(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *_a, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *_b, ಶೂನ್ಯ *arg)
{
    TCCState *s1 = arg;
    ರಚನೆ bind_rebase *a = (ರಚನೆ bind_rebase *) _a;
    ರಚನೆ bind_rebase *b = (ರಚನೆ bind_rebase *) _b;
    addr_t aa = s1->sections[a->section]->sh_addr + a->rel.r_ಸ್ಥಾನಾಂತರ;
    addr_t ab = s1->sections[b->section]->sh_addr + b->rel.r_ಸ್ಥಾನಾಂತರ;

    ಹಿಂತಿರುಗಿ aa > ab ? 1 : aa < ab ? -1 : 0;
}

ST_FUNC ಶೂನ್ಯ bind_rebase_import(TCCState *s1, ರಚನೆ macho *mo)
{
    ಪೂರ್ಣಾಂಕ i, j, k, bind_ಸೂಚ್ಯಂಕ, ಗಾತ್ರ_2, ಪುಟ_ಎಣಿಕೆ, sym_ಸೂಚ್ಯಂಕ;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
    ElfW(Sym) *sym;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ದತ್ತಾಂಶ = mo->chained_fixups->ದತ್ತಾಂಶ;
    ರಚನೆ segment_command_64 *seg;
    ರಚನೆ dyld_chained_fixups_ಶೀರ್ಷಿಕೆ *ಶೀರ್ಷಿಕೆ;
    ರಚನೆ dyld_chained_starts_ಒಳ_image *image;
    ರಚನೆ dyld_chained_starts_ಒಳ_segment *segment;
    ರಚನೆ dyld_chained_import *import;

    tcc_qsort(mo->bind_rebase, mo->n_bind_rebase, ಗಾತ್ರ(ರಚನೆ bind_rebase),
	      bind_rebase_cmp, s1);
    ಗಾಗಿ (i = 0; i < mo->n_bind_rebase - 1; i++)
	ಆದರೆ (mo->bind_rebase[i].section == mo->bind_rebase[i + 1].section &&
	    mo->bind_rebase[i].rel.r_ಸ್ಥಾನಾಂತರ == mo->bind_rebase[i + 1].rel.r_ಸ್ಥಾನಾಂತರ) {
	    sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
            sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
	    name = (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
	    tcc_error("Overlap %s/%s %s:%s",
		      mo->bind_rebase[i].bind ? "bind" : "rebase",
		      mo->bind_rebase[i + 1].bind ? "bind" : "rebase",
		      s1->sections[mo->bind_rebase[i].section]->name, name);
	}
    ಶೀರ್ಷಿಕೆ = (ರಚನೆ dyld_chained_fixups_ಶೀರ್ಷಿಕೆ *) ದತ್ತಾಂಶ;
    ದತ್ತಾಂಶ += (ಗಾತ್ರ(ರಚನೆ dyld_chained_fixups_ಶೀರ್ಷಿಕೆ) + 7) & -8;
    ಶೀರ್ಷಿಕೆ->starts_ಸ್ಥಾನಾಂತರ = ದತ್ತಾಂಶ - mo->chained_fixups->ದತ್ತಾಂಶ;
    ಶೀರ್ಷಿಕೆ->imports_ಎಣಿಕೆ = mo->n_bind;
    ಶೀರ್ಷಿಕೆ->imports_format = DYLD_CHAINED_IMPORT;
    ಶೀರ್ಷಿಕೆ->symbols_format = 0;
    ಗಾತ್ರ_2 = ಗಾತ್ರ(ರಚನೆ dyld_chained_starts_ಒಳ_image) +
	   (mo->nseg - 1) * ಗಾತ್ರ(uint32_t);
    image = (ರಚನೆ dyld_chained_starts_ಒಳ_image *) ದತ್ತಾಂಶ;
    ದತ್ತಾಂಶ += (ಗಾತ್ರ_2 + 7) & -8;
    image->seg_ಎಣಿಕೆ = mo->nseg;
    ಗಾಗಿ (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
        image->seg_info_ಸ್ಥಾನಾಂತರ[i] = (ದತ್ತಾಂಶ - mo->chained_fixups->ದತ್ತಾಂಶ) -
				    ಶೀರ್ಷಿಕೆ->starts_ಸ್ಥಾನಾಂತರ;
	seg = get_segment(mo, i);
	ಪುಟ_ಎಣಿಕೆ = (seg->vmsize + SEG_ಪುಟ_ಗಾತ್ರ - 1) / SEG_ಪುಟ_ಗಾತ್ರ;
	ಗಾತ್ರ_2 = ಗಾತ್ರ(ರಚನೆ dyld_chained_starts_ಒಳ_segment) +
		      (ಪುಟ_ಎಣಿಕೆ - 1) * ಗಾತ್ರ(uint16_t);
        segment = (ರಚನೆ dyld_chained_starts_ಒಳ_segment *) ದತ್ತಾಂಶ;
        ದತ್ತಾಂಶ += (ಗಾತ್ರ_2 + 7) & -8;
        segment->ಗಾತ್ರ_2 = ಗಾತ್ರ_2;
        segment->ಪುಟ_ಗಾತ್ರ = SEG_ಪುಟ_ಗಾತ್ರ;
#ಆದರೆ 1
#ವ್ಯಾಖ್ಯಾನಿಸು	PTR_64_ಸ್ಥಾನಾಂತರ 0
#ವ್ಯಾಖ್ಯಾನಿಸು	PTR_64_ಮುಖವಾಡ   0x7FFFFFFFFFFULL
        segment->ಸೂಚಕ_format = DYLD_CHAINED_PTR_64;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು	PTR_64_ಸ್ಥಾನಾಂತರ 0x100000000ULL
#ವ್ಯಾಖ್ಯಾನಿಸು	PTR_64_ಮುಖವಾಡ   0xFFFFFFFFFFFFFFULL
        segment->ಸೂಚಕ_format = DYLD_CHAINED_PTR_64_ಸ್ಥಾನಾಂತರ;
#ಆದರೆ_ಅಂತ್ಯ
        segment->segment_ಸ್ಥಾನಾಂತರ = seg->fileoff;
        segment->max_valid_ಸೂಚಕ = 0;
        segment->ಪುಟ_ಎಣಿಕೆ = ಪುಟ_ಎಣಿಕೆ;
	// add bind/rebase
	bind_ಸೂಚ್ಯಂಕ = 0;
	k = 0;
	ಗಾಗಿ (j = 0; j < ಪುಟ_ಎಣಿಕೆ; j++) {
	    addr_t ಆರಂಭ = seg->vmaddr + j * SEG_ಪುಟ_ಗಾತ್ರ;
	    addr_t ಕೊನೆ = ಆರಂಭ + SEG_ಪುಟ_ಗಾತ್ರ;
	    ಶೂನ್ಯ *ಕೊನೆಯ = ಖಾಲಿ;
	    addr_t ಕೊನೆಯ_o = 0;
	    addr_t cur_o, cur;
	    ರಚನೆ dyld_chained_ptr_64_rebase *rebase;
	    ರಚನೆ dyld_chained_ptr_64_bind *bind;

	    segment->ಪುಟ_ಆರಂಭ[j] = DYLD_CHAINED_PTR_ಆರಂಭ_NONE;
	    ಗಾಗಿ (; k < mo->n_bind_rebase; k++) {
	        Section *s = s1->sections[mo->bind_rebase[k].section];
		addr_t r_ಸ್ಥಾನಾಂತರ = mo->bind_rebase[k].rel.r_ಸ್ಥಾನಾಂತರ;
		addr_t addr = s->sh_addr + r_ಸ್ಥಾನಾಂತರ;

		ಆದರೆ ((addr & 3) ||
		    (addr & (SEG_ಪುಟ_ಗಾತ್ರ - 1)) > SEG_ಪುಟ_ಗಾತ್ರ - PTR_ಗಾತ್ರ)
		    tcc_error("Illegal rel_offset %s %lld",
			      s->name, (ದೀರ್ಘ ದೀರ್ಘ)r_ಸ್ಥಾನಾಂತರ);
		ಆದರೆ (addr >= ಕೊನೆ)
		    ನಿಲ್ಲಿಸು;
		ಆದರೆ (addr >= ಆರಂಭ) {
		    cur_o = addr - ಆರಂಭ;
	            ಆದರೆ (mo->bind_rebase[k].bind) {
		        ಆದರೆ (segment->ಪುಟ_ಆರಂಭ[j] == DYLD_CHAINED_PTR_ಆರಂಭ_NONE)
			    segment->ಪುಟ_ಆರಂಭ[j] = cur_o;
		        ಇಲ್ಲದಿದ್ದರೆ {
			    bind = (ರಚನೆ dyld_chained_ptr_64_bind *) ಕೊನೆಯ;
			    bind->ಮುಂದಿನ = (cur_o - ಕೊನೆಯ_o) / 4;
		        }
		        bind = (ರಚನೆ dyld_chained_ptr_64_bind *)
				    (s->ದತ್ತಾಂಶ + r_ಸ್ಥಾನಾಂತರ);
		        ಕೊನೆಯ = bind;
		        ಕೊನೆಯ_o = cur_o;
		        bind->ordinal = bind_ಸೂಚ್ಯಂಕ;
		        bind->addend = 0;
		        bind->reserved = 0;
		        bind->ಮುಂದಿನ = 0;
		        bind->bind = 1;
		    }
		    ಇಲ್ಲದಿದ್ದರೆ {
		        ಆದರೆ (segment->ಪುಟ_ಆರಂಭ[j] == DYLD_CHAINED_PTR_ಆರಂಭ_NONE)
			    segment->ಪುಟ_ಆರಂಭ[j] = cur_o;
		        ಇಲ್ಲದಿದ್ದರೆ {
			    rebase = (ರಚನೆ dyld_chained_ptr_64_rebase *) ಕೊನೆಯ;
			    rebase->ಮುಂದಿನ = (cur_o - ಕೊನೆಯ_o) / 4;
		        }
		        rebase = (ರಚನೆ dyld_chained_ptr_64_rebase *)
				    (s->ದತ್ತಾಂಶ + r_ಸ್ಥಾನಾಂತರ);
		        ಕೊನೆಯ = rebase;
		        ಕೊನೆಯ_o = cur_o;
		        cur = (*(uint64_t *) (s->ದತ್ತಾಂಶ + r_ಸ್ಥಾನಾಂತರ)) -
			      PTR_64_ಸ್ಥಾನಾಂತರ;
		        rebase->ಗುರಿ = cur & PTR_64_ಮುಖವಾಡ;
		        rebase->high8 = cur >> (64 - 8);
			ಆದರೆ (cur != ((uint64_t)rebase->high8 << (64 - 8)) + rebase->ಗುರಿ)
			    tcc_error("rebase error");
		        rebase->reserved = 0;
		        rebase->ಮುಂದಿನ = 0;
		        rebase->bind = 0;
		    }
		}
		bind_ಸೂಚ್ಯಂಕ += mo->bind_rebase[k].bind;
	    }
	}
    }
    // add imports
    ಶೀರ್ಷಿಕೆ->imports_ಸ್ಥಾನಾಂತರ = ದತ್ತಾಂಶ - mo->chained_fixups->ದತ್ತಾಂಶ;
    import = (ರಚನೆ dyld_chained_import *) ದತ್ತಾಂಶ;
    ದತ್ತಾಂಶ += mo->n_bind * ಗಾತ್ರ (ರಚನೆ dyld_chained_import);
    ಶೀರ್ಷಿಕೆ->symbols_ಸ್ಥಾನಾಂತರ = ದತ್ತಾಂಶ - mo->chained_fixups->ದತ್ತಾಂಶ;
    ದತ್ತಾಂಶ++;
    ಗಾಗಿ (i = 0, bind_ಸೂಚ್ಯಂಕ = 0; i < mo->n_bind_rebase; i++) {
	ಆದರೆ (mo->bind_rebase[i].bind) {
	    import[bind_ಸೂಚ್ಯಂಕ].lib_ordinal =
		BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xffu;
	    import[bind_ಸೂಚ್ಯಂಕ].name_ಸ್ಥಾನಾಂತರ =
		(ದತ್ತಾಂಶ - mo->chained_fixups->ದತ್ತಾಂಶ) - ಶೀರ್ಷಿಕೆ->symbols_ಸ್ಥಾನಾಂತರ;
	    sym_ಸೂಚ್ಯಂಕ = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    sym = &((ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
	    import[bind_ಸೂಚ್ಯಂಕ].weak_import =
		ELFW(ST_BIND)(sym->st_info) == STB_WEAK;
	    name = (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
            strcpy((ಅಕ್ಷರ *) ದತ್ತಾಂಶ, name);
	    ದತ್ತಾಂಶ += ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name) + 1;
	    bind_ಸೂಚ್ಯಂಕ++;
	}
    }
    tcc_free(mo->bind_rebase);
}
#ಆದರೆ_ಅಂತ್ಯ

ST_FUNC ಪೂರ್ಣಾಂಕ macho_output_file(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    ಪೂರ್ಣಾಂಕ fd, ಬಹುಲಕ, file_type;
    FILE *fp;
    ಪೂರ್ಣಾಂಕ i, ret = -1;
    ರಚನೆ macho mo;

    (ಶೂನ್ಯ)memset(&mo, 0, ಗಾತ್ರ(mo));

    file_type = s1->output_type;
    ಆದರೆ (file_type == TCC_OUTPUT_OBJ)
        ಬಹುಲಕ = 0666;
    ಇಲ್ಲದಿದ್ದರೆ
        ಬಹುಲಕ = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_ದ್ವಿಮಾನ_2, ಬಹುಲಕ);
    ಆದರೆ (fd < 0 || (fp = fdopen(fd, "wb")) == ಖಾಲಿ) {
        tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
        ಹಿಂತಿರುಗಿ -1;
    }
    tcc_ಕೂಡಿಸು_runtime(s1);
    tcc_macho_ಕೂಡಿಸು_destructor(s1);
    resolve_common_syms(s1);
    create_symtab(s1, &mo);
    check_relocs(s1, &mo);
    ret = check_symbols(s1, &mo);
    ಆದರೆ (!ret) {
	ಪೂರ್ಣಾಂಕ save_output = s1->output_type;

        collect_sections(s1, &mo, filename);
        relocate_syms(s1, s1->symtab, 0);
	ಆದರೆ (s1->output_type == TCC_OUTPUT_EXE)
            mo.ep->entryoff = get_sym_addr(s1, "main", 1, 1)
                            -     get_segment(&mo, 1)->vmaddr;
        ಆದರೆ (s1->nb_errors)
          ಹೋಗು do_ret;
	// Macho uses bind/rebase instead of dynsym
	s1->output_type = TCC_OUTPUT_EXE;
        relocate_sections(s1);
	s1->output_type = save_output;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_NEW_MACHO
	bind_rebase_import(s1, &mo);
#ಆದರೆ_ಅಂತ್ಯ
        convert_symbols(s1, &mo);
        ಆದರೆ (s1->verbose)
            ಬರೆ("<- %s\n", filename);
        macho_write(s1, &mo, fp);
    }

 do_ret:
    ಗಾಗಿ (i = 0; i < mo.nlc; i++)
      tcc_free(mo.lc[i]);
    tcc_free(mo.seg2lc);
    tcc_free(mo.lc);
    tcc_free(mo.elfsectomacho);
    tcc_free(mo.e2msym);

    fclose(fp);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_CODESIGN
    ಆದರೆ (!ret) {
	ಅಕ್ಷರ command[1024];
	ಪೂರ್ಣಾಂಕ retval;

	snprintf(command, ಗಾತ್ರ(command), "codesign -f -s - %s", filename);
	retval = system (command);
	ಆದರೆ (retval == -1 || !(WIFEXITED(retval) && WEXITSTATUS(retval) == 0))
	    tcc_error ("command failed '%s'", command);
    }
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ ret;
}

ಸ್ಥಿರ uint32_t macho_swap32(uint32_t x)
{
  ಹಿಂತಿರುಗಿ (x >> 24) | (x << 24) | ((x >> 8) & 0xff00) | ((x & 0xff00) << 8);
}
#ವ್ಯಾಖ್ಯಾನಿಸು ಅದಲುಬದಲು(x) (ಅದಲುಬದಲು_2 ? macho_swap32(x) : (x))
#ವ್ಯಾಖ್ಯಾನಿಸು tbd_parse_movepast(s) \
    (pos = (pos = ಅಕ್ಷರಸರಣಿ_ಹುಡುಕು(pos, s)) ? pos + ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(s) : ಖಾಲಿ)
#ವ್ಯಾಖ್ಯಾನಿಸು tbd_parse_movetoany(cs) (pos = strpbrk(pos, cs))
#ವ್ಯಾಖ್ಯಾನಿಸು tbd_parse_skipws ಆಗ (*pos && (*pos==' '||*pos=='\n')) ++pos
#ವ್ಯಾಖ್ಯಾನಿಸು tbd_parse_tramplequote ಆದರೆ(*pos=='\''||*pos=='"') tbd_parse_trample
#ವ್ಯಾಖ್ಯಾನಿಸು tbd_parse_tramplespace ಆದರೆ(*pos==' ') tbd_parse_trample
#ವ್ಯಾಖ್ಯಾನಿಸು tbd_parse_trample *pos++=0

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
/* Looks for the active developer SDK set by xcode-select (or the default
   one set during installation.) */
ST_FUNC ಶೂನ್ಯ tcc_ಕೂಡಿಸು_macos_sdkpath(TCCState* s)
{
    ಅಕ್ಷರ *sdkroot = ಖಾಲಿ, *pos = ಖಾಲಿ;
    ಶೂನ್ಯ* xcs = dlopen("libxcselect.dylib", RTLD_GLOBAL | RTLD_LAZY);
    CString ಮಾರ್ಗ;
    ಪೂರ್ಣಾಂಕ (*f)(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ, ಅಕ್ಷರ**) = dlsym(xcs, "xcselect_host_sdk_path");
    cstr_new(&ಮಾರ್ಗ);
    ಆದರೆ (f) f(1, &sdkroot);
    ಆದರೆ (sdkroot)
        pos = ಅಕ್ಷರಸರಣಿ_ಹುಡುಕು(sdkroot,"SDKs/MacOSX");
    ಆದರೆ (pos)
        cstr_printf(&ಮಾರ್ಗ, "%.*s.sdk/usr/lib", (ಪೂರ್ಣಾಂಕ)(pos - sdkroot + 11), sdkroot);
    /* must use free from libc directly */
#ಸೂಚನೆ ತಳ್ಳು_macro("free")
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು ಬಿಡುಗಡೆ
    ಬಿಡುಗಡೆ(sdkroot);
#ಸೂಚನೆ ತೆಗೆ_macro("free")
    ಆದರೆ (ಮಾರ್ಗ.ಗಾತ್ರ_2)
        tcc_ಕೂಡಿಸು_library_ಮಾರ್ಗ(s, (ಅಕ್ಷರ*)ಮಾರ್ಗ.ದತ್ತಾಂಶ);
    ಇಲ್ಲದಿದ್ದರೆ
        tcc_ಕೂಡಿಸು_library_ಮಾರ್ಗ(s,
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib"
            ":" "/Applications/Xcode.app/Developer/SDKs/MacOSX.sdk/usr/lib"
            );
    cstr_free(&ಮಾರ್ಗ);
}

ST_FUNC ಅಕ್ಷರ* macho_tbd_soname(ಪೂರ್ಣಾಂಕ fd) {
    ಅಕ್ಷರ *soname, *ದತ್ತಾಂಶ, *pos;
    ಅಕ್ಷರ *ret = 0;
    pos = ದತ್ತಾಂಶ = tcc_ತುಂಬು_ಪಠ್ಯ(fd);
    ಆದರೆ (!tbd_parse_movepast("install-name: ")) ಹೋಗು the_ಕೊನೆ;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    ಆದರೆ (!tbd_parse_movetoany("\n \"'")) ಹೋಗು the_ಕೊನೆ;
    tbd_parse_trample;
    ret = tcc_strdup(soname);
the_ಕೊನೆ:
    tcc_free(ದತ್ತಾಂಶ);
    ಹಿಂತಿರುಗಿ ret;
}
#ಆದರೆ_ಅಂತ್ಯ /* TCC_IS_NATIVE */

ST_FUNC ಪೂರ್ಣಾಂಕ macho_ತುಂಬು_tbd(TCCState* s1, ಪೂರ್ಣಾಂಕ fd, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* filename, ಪೂರ್ಣಾಂಕ lev)
{
    ಅಕ್ಷರ *soname, *ದತ್ತಾಂಶ, *pos;
    ಪೂರ್ಣಾಂಕ ret = -1;

    pos = ದತ್ತಾಂಶ = tcc_ತುಂಬು_ಪಠ್ಯ(fd);
    ಆದರೆ (!tbd_parse_movepast("install-name: ")) ಹೋಗು the_ಕೊನೆ;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    ಆದರೆ (!tbd_parse_movetoany("\n \"'")) ಹೋಗು the_ಕೊನೆ;
    tbd_parse_trample;
    ret = 0;
    ಆದರೆ (tcc_ಕೂಡಿಸು_dllref(s1, soname, lev)->ಸಿಕ್ಕಿತು)
        ಹೋಗು the_ಕೊನೆ;
    ಆಗ(pos) {
        ಅಕ್ಷರ* sym = ಖಾಲಿ;
        ಪೂರ್ಣಾಂಕ cont = 1;
        ಆದರೆ (!tbd_parse_movepast("symbols: ")) ನಿಲ್ಲಿಸು;
        ಆದರೆ (!tbd_parse_movepast("[")) ನಿಲ್ಲಿಸು;
        ಆಗ (cont) {
            tbd_parse_skipws;
            tbd_parse_tramplequote;
            sym = pos;
            ಆದರೆ (!tbd_parse_movetoany(",] \"'")) ನಿಲ್ಲಿಸು;
            tbd_parse_tramplequote;
            tbd_parse_tramplespace;
            tbd_parse_skipws;
            ಆದರೆ (*pos==0||*pos==']') cont=0;
            tbd_parse_trample;
            ಗಣ_elf_sym(s1->dynsymtab_section, 0, 0,
                ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0, SHN_UNDEF, sym);
        }
    }

the_ಕೊನೆ:
    tcc_free(ದತ್ತಾಂಶ);
    ಹಿಂತಿರುಗಿ ret;
}

ST_FUNC ಪೂರ್ಣಾಂಕ macho_ತುಂಬು_dll(TCCState * s1, ಪೂರ್ಣಾಂಕ fd, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* filename, ಪೂರ್ಣಾಂಕ lev)
{
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ buf[ಗಾತ್ರ(ರಚನೆ mach_ಶೀರ್ಷಿಕೆ_64)];
    ಶೂನ್ಯ *buf2;
    uint32_t machofs = 0;
    ರಚನೆ fat_ಶೀರ್ಷಿಕೆ fh;
    ರಚನೆ mach_ಶೀರ್ಷಿಕೆ mh;
    ರಚನೆ ತುಂಬು_command *lc;
    ಪೂರ್ಣಾಂಕ i, ಅದಲುಬದಲು_2 = 0;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *soname = filename;
    ರಚನೆ nlist_64 *symtab = 0;
    uint32_t nsyms = 0;
    ಅಕ್ಷರ *strtab = 0;
    uint32_t strsize = 0;
    uint32_t iextdef = 0;
    uint32_t nextdef = 0;

  again:
    ಆದರೆ (ತುಂಬಿದ_read(fd, buf, ಗಾತ್ರ(buf)) != ಗಾತ್ರ(buf))
      ಹಿಂತಿರುಗಿ -1;
    ಸ್ಮರಣೆ_ನಕಲು(&fh, buf, ಗಾತ್ರ(fh));
    ಆದರೆ (fh.magic == FAT_MAGIC || fh.magic == FAT_CIGAM) {
        ರಚನೆ fat_arch *fa = ತುಂಬು_ದತ್ತಾಂಶ(fd, ಗಾತ್ರ(fh),
                                        fh.nfat_arch * ಗಾತ್ರ(*fa));
        ಅದಲುಬದಲು_2 = fh.magic == FAT_CIGAM;
        ಗಾಗಿ (i = 0; i < ಅದಲುಬದಲು(fh.nfat_arch); i++)
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
          ಆದರೆ (ಅದಲುಬದಲು(fa[i].cputype) == CPU_TYPE_X86_64
              && ಅದಲುಬದಲು(fa[i].cpusubtype) == CPU_SUBTYPE_X86_ALL)
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
          ಆದರೆ (ಅದಲುಬದಲು(fa[i].cputype) == CPU_TYPE_ARM64
              && ಅದಲುಬದಲು(fa[i].cpusubtype) == CPU_SUBTYPE_ARM64_ALL)
#ಆದರೆ_ಅಂತ್ಯ
            ನಿಲ್ಲಿಸು;
        ಆದರೆ (i == ಅದಲುಬದಲು(fh.nfat_arch)) {
            tcc_free(fa);
            ಹಿಂತಿರುಗಿ -1;
        }
        machofs = ಅದಲುಬದಲು(fa[i].ಸ್ಥಾನಾಂತರ);
        tcc_free(fa);
        lseek(fd, machofs, SEEK_SET);
        ಹೋಗು again;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (fh.magic == FAT_MAGIC_64 || fh.magic == FAT_CIGAM_64) {
        tcc_warning("%s: Mach-O fat 64bit files of type 0x%x not handled",
                    filename, fh.magic);
        ಹಿಂತಿರುಗಿ -1;
    }

    ಸ್ಮರಣೆ_ನಕಲು(&mh, buf, ಗಾತ್ರ(mh));
    ಆದರೆ (mh.magic != MH_MAGIC_64)
      ಹಿಂತಿರುಗಿ -1;
    dprintf("found Mach-O at %d\n", machofs);
    buf2 = ತುಂಬು_ದತ್ತಾಂಶ(fd, machofs + ಗಾತ್ರ(ರಚನೆ mach_ಶೀರ್ಷಿಕೆ_64), mh.sizeofcmds);
    ಗಾಗಿ (i = 0, lc = buf2; i < mh.ncmds; i++) {
        dprintf("lc %2d: 0x%08x\n", i, lc->cmd);
        ಆಯ್ಕೆ (lc->cmd) {
        ಸ್ಥಿತಿ LC_SYMTAB:
        {
            ರಚನೆ symtab_command *sc = (ರಚನೆ symtab_command*)lc;
            nsyms = sc->nsyms;
            symtab = ತುಂಬು_ದತ್ತಾಂಶ(fd, machofs + sc->symoff, nsyms * ಗಾತ್ರ(*symtab));
            strsize = sc->strsize;
            strtab = ತುಂಬು_ದತ್ತಾಂಶ(fd, machofs + sc->stroff, strsize);
            ನಿಲ್ಲಿಸು;
        }
        ಸ್ಥಿತಿ LC_ID_DYLIB:
        {
            ರಚನೆ dylib_command *dc = (ರಚನೆ dylib_command*)lc;
            soname = (ಅಕ್ಷರ*)lc + dc->name;
            dprintf(" ID_DYLIB %d 0x%x 0x%x %s\n",
                    dc->timestamp, dc->current_ಆವೃತ್ತಿ,
                    dc->compatibility_ಆವೃತ್ತಿ, soname);
            ನಿಲ್ಲಿಸು;
        }
        ಸ್ಥಿತಿ LC_REEXPORT_DYLIB:
        {
            ರಚನೆ dylib_command *dc = (ರಚನೆ dylib_command*)lc;
            ಅಕ್ಷರ *name = (ಅಕ್ಷರ*)lc + dc->name;
            ಪೂರ್ಣಾಂಕ subfd = open(name, O_RDONLY | O_ದ್ವಿಮಾನ_2);
            dprintf(" REEXPORT %s\n", name);
            ಆದರೆ (subfd < 0)
              tcc_warning("can't open %s (reexported from %s)", name, filename);
            ಇಲ್ಲದಿದ್ದರೆ {
                /* Hopefully the REEXPORTs never form a cycle, we don't check
                   for that!  */
                macho_ತುಂಬು_dll(s1, subfd, name, lev + 1);
                close(subfd);
            }
            ನಿಲ್ಲಿಸು;
        }
        ಸ್ಥಿತಿ LC_DYSYMTAB:
        {
            ರಚನೆ dysymtab_command *dc = (ರಚನೆ dysymtab_command*)lc;
            iextdef = dc->iextdefsym;
            nextdef = dc->nextdefsym;
            ನಿಲ್ಲಿಸು;
        }
        }
        lc = (ರಚನೆ ತುಂಬು_command*) ((ಅಕ್ಷರ*)lc + lc->cmdsize);
    }

    ಆದರೆ (tcc_ಕೂಡಿಸು_dllref(s1, soname, lev)->ಸಿಕ್ಕಿತು)
        ಹೋಗು the_ಕೊನೆ;

    ಆದರೆ (!nsyms || !nextdef)
      tcc_warning("%s doesn't export any symbols?", filename);

    //dprintf("symbols (all):\n");
    dprintf("symbols (exported):\n");
    dprintf("    n: typ sec   desc              value name\n");
    //for (i = 0; i < nsyms; i++) {
    ಗಾಗಿ (i = iextdef; i < iextdef + nextdef; i++) {
        ರಚನೆ nlist_64 *sym = symtab + i;
        dprintf("%5d: %3d %3d 0x%04x 0x%016lx %s\n",
                i, sym->n_type, sym->n_sect, sym->n_desc, (ದೀರ್ಘ)sym->n_ಮೌಲ್ಯ,
                strtab + sym->n_strx);
        ಗಣ_elf_sym(s1->dynsymtab_section, 0, 0,
                    ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
                    0, SHN_UNDEF, strtab + sym->n_strx);
    }

  the_ಕೊನೆ:
    tcc_free(strtab);
    tcc_free(symtab);
    tcc_free(buf2);
    ಹಿಂತಿರುಗಿ 0;
}
