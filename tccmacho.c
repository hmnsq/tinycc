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
#అన్తర్భావ "tcc.h"

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

#ఒకవేళ !defined TCC_లక్ష్యం_X86_64 && !defined TCC_లక్ష్యం_ARM64
#దోషం Platform not supported
#అయితే_ముగింపు

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#నిర్వచనం_రద్దు _tcc_error

#నిర్వచించు DEBUG_MACHO 0
#నిర్వచించు dprintf ఒకవేళ (DEBUG_MACHO) రాయి

#నిర్వచించు MH_EXECUTE              (0x2)
#నిర్వచించు MH_DYLDLINK             (0x4)
#నిర్వచించు MH_DYLIB                (0x6)
#నిర్వచించు MH_PIE                  (0x200000)

#నిర్వచించు CPU_SUBTYPE_LIB64       (0x80000000)
#నిర్వచించు CPU_SUBTYPE_X86_ALL     (3)
#నిర్వచించు CPU_SUBTYPE_ARM64_ALL   (0)

#నిర్వచించు CPU_ARCH_ABI64          (0x01000000)

#నిర్వచించు CPU_TYPE_X86            (7)
#నిర్వచించు CPU_TYPE_X86_64         (CPU_TYPE_X86 | CPU_ARCH_ABI64)
#నిర్వచించు CPU_TYPE_ARM            (12)
#నిర్వచించు CPU_TYPE_ARM64          (CPU_TYPE_ARM | CPU_ARCH_ABI64)

నిర్మాణం fat_శీర్షిక {
    uint32_t        magic;          /* FAT_MAGIC or FAT_MAGIC_64 */
    uint32_t        nfat_arch;      /* number of structs that follow */
};

నిర్మాణం fat_arch {
    పూర్ణాంకం             cputype;        /* cpu specifier (int) */
    పూర్ణాంకం             cpusubtype;     /* machine specifier (int) */
    uint32_t        స్థానభ్రంశం;         /* file offset to this object file */
    uint32_t        కొలత;           /* size of this object file */
    uint32_t        align;          /* alignment as a power of 2 */
};

#నిర్వచించు FAT_MAGIC       0xcafebabe
#నిర్వచించు FAT_CIGAM       0xbebafeca
#నిర్వచించు FAT_MAGIC_64    0xcafebabf
#నిర్వచించు FAT_CIGAM_64    0xbfbafeca

నిర్మాణం mach_శీర్షిక {
    uint32_t        magic;          /* mach magic number identifier */
    పూర్ణాంకం             cputype;        /* cpu specifier */
    పూర్ణాంకం             cpusubtype;     /* machine specifier */
    uint32_t        filetype;       /* type of file */
    uint32_t        ncmds;          /* number of load commands */
    uint32_t        sizeofcmds;     /* the size of all the load commands */
    uint32_t        flags;          /* flags */
};

నిర్మాణం mach_శీర్షిక_64 {
    నిర్మాణం mach_శీర్షిక  mh;
    uint32_t            reserved;       /* reserved, pad to 64bit */
};

/* Constant for the magic field of the mach_header (32-bit architectures) */
#నిర్వచించు MH_MAGIC        0xfeedface      /* the mach magic number */
#నిర్వచించు MH_CIGAM        0xcefaedfe      /* NXSwapInt(MH_MAGIC) */
#నిర్వచించు MH_MAGIC_64     0xfeedfacf      /* the 64-bit mach magic number */
#నిర్వచించు MH_CIGAM_64     0xcffaedfe      /* NXSwapInt(MH_MAGIC_64) */

నిర్మాణం ఎక్కించు_command {
    uint32_t        cmd;            /* type of load command */
    uint32_t        cmdsize;        /* total size of command in bytes */
};

#నిర్వచించు LC_REQ_DYLD 0x80000000
#నిర్వచించు LC_SYMTAB        0x2
#నిర్వచించు LC_DYSYMTAB      0xb
#నిర్వచించు LC_ఎక్కించు_DYLIB    0xc
#నిర్వచించు LC_ID_DYLIB      0xd
#నిర్వచించు LC_ఎక్కించు_DYLINKER 0xe
#నిర్వచించు LC_SEGMENT_64    0x19
#నిర్వచించు LC_RPATH (0x1c | LC_REQ_DYLD)
#నిర్వచించు LC_REEXPORT_DYLIB (0x1f | LC_REQ_DYLD)
#నిర్వచించు LC_DYLD_INFO_ONLY (0x22|LC_REQ_DYLD)
#నిర్వచించు LC_MAIN (0x28|LC_REQ_DYLD)
#నిర్వచించు LC_ఆధారం_సంస్కరణ 0x2A
#నిర్వచించు LC_BUILD_సంస్కరణ 0x32
#నిర్వచించు LC_DYLD_EXPORTS_TRIE (0x33 | LC_REQ_DYLD)
#నిర్వచించు LC_DYLD_CHAINED_FIXUPS (0x34 | LC_REQ_DYLD)

#నిర్వచించు SG_READ_ONLY    0x10 /* This segment is made read-only after fixups */

రకనిర్వచనం పూర్ణాంకం vm_prot_t;

నిర్మాణం segment_command_64 { /* for 64-bit architectures */
    uint32_t        cmd;            /* LC_SEGMENT_64 */
    uint32_t        cmdsize;        /* includes sizeof section_64 structs */
    అక్షరం            segname[16];    /* segment name */
    uint64_t        vmaddr;         /* memory address of this segment */
    uint64_t        vmsize;         /* memory size of this segment */
    uint64_t        fileoff;        /* file offset of this segment */
    uint64_t        filesize;       /* amount to map from the file */
    vm_prot_t       maxprot;        /* maximum VM protection */
    vm_prot_t       initprot;       /* initial VM protection */
    uint32_t        nsects;         /* number of sections in segment */
    uint32_t        flags;          /* flags */
};

నిర్మాణం section_64 { /* for 64-bit architectures */
    అక్షరం            sectname[16];   /* name of this section */
    అక్షరం            segname[16];    /* segment this section goes in */
    uint64_t        addr;           /* memory address of this section */
    uint64_t        కొలత;           /* size in bytes of this section */
    uint32_t        స్థానభ్రంశం;         /* file offset of this section */
    uint32_t        align;          /* section alignment (power of 2) */
    uint32_t        reloff;         /* file offset of relocation entries */
    uint32_t        nreloc;         /* number of relocation entries */
    uint32_t        flags;          /* flags (section type and attributes)*/
    uint32_t        reserved1;      /* reserved (for offset or index) */
    uint32_t        reserved2;      /* reserved (for count or sizeof) */
    uint32_t        reserved3;      /* reserved */
};

గణన {
    DYLD_CHAINED_IMPORT          = 1,
};

నిర్మాణం dyld_chained_fixups_శీర్షిక {
    uint32_t    fixups_సంస్కరణ; ///< 0
    uint32_t    starts_స్థానభ్రంశం;  ///< Offset of dyld_chained_starts_in_image.
    uint32_t    imports_స్థానభ్రంశం; ///< Offset of imports table in chain_data.
    uint32_t    symbols_స్థానభ్రంశం; ///< Offset of symbol strings in chain_data.
    uint32_t    imports_లెక్క;  ///< Number of imported symbol names.
    uint32_t    imports_format; ///< DYLD_CHAINED_IMPORT*
    uint32_t    symbols_format; ///< 0 => uncompressed, 1 => zlib compressed
};

నిర్మాణం dyld_chained_starts_లోపల_image
{
    uint32_t    seg_లెక్క;
    uint32_t    seg_info_స్థానభ్రంశం[1];  // each entry is offset into this struct for that segment
    // followed by pool of dyld_chain_starts_in_segment data
};

గణన {
    DYLD_CHAINED_PTR_64                     =  2,    // target is vmaddr
    DYLD_CHAINED_PTR_64_స్థానభ్రంశం              =  6,    // target is vm offset
};

గణన {
    DYLD_CHAINED_PTR_ప్రారంభం_NONE   = 0xFFFF, // used in page_start[] to denote a page with no fixups
};

#నిర్వచించు SEG_పుట_కొలత 16384

నిర్మాణం dyld_chained_starts_లోపల_segment
{
    uint32_t    కొలత;               // size of this (amount kernel needs to copy)
    uint16_t    పుట_కొలత;          // 0x1000 or 0x4000
    uint16_t    సూచిక_format;     // DYLD_CHAINED_PTR_*
    uint64_t    segment_స్థానభ్రంశం;     // offset in memory to start of segment
    uint32_t    max_valid_సూచిక;  // for 32-bit OS, any value beyond this is not a pointer
    uint16_t    పుట_లెక్క;         // how many pages are in array
    uint16_t    పుట_ప్రారంభం[1];      // each entry is offset in each page of first element in chain
                                    // or DYLD_CHAINED_PTR_START_NONE if no fixups on page
};

గణన BindSpecialDylib {
  BIND_SPECIAL_DYLIB_FLAT_LOOKUP = -2,
};

నిర్మాణం dyld_chained_import
{
    uint32_t    lib_ordinal :  8,
                weak_import :  1,
                name_స్థానభ్రంశం : 23;
};

నిర్మాణం dyld_chained_ptr_64_rebase
{
    uint64_t    లక్ష్యం    : 36,    // vmaddr, 64GB max image size
                high8     :  8,    // top 8 bits set to this after slide added
                reserved  :  7,    // all zeros
                తదుపరి      : 12,    // 4-byte stride
                bind      :  1;    // == 0
};

నిర్మాణం dyld_chained_ptr_64_bind
{
    uint64_t    ordinal   : 24,
                addend    :  8,   // 0 thru 255
                reserved  : 19,   // all zeros
                తదుపరి      : 12,   // 4-byte stride
                bind      :  1;   // == 1
};

#నిర్వచించు S_REGULAR                       0x0
#నిర్వచించు S_ZEROFILL                      0x1
#నిర్వచించు S_NON_LAZY_చిహ్నం_సూచికలు      0x6
#నిర్వచించు S_LAZY_చిహ్నం_సూచికలు          0x7
#నిర్వచించు S_చిహ్నం_STUBS                  0x8
#నిర్వచించు S_MOD_INIT_FUNC_సూచికలు        0x9
#నిర్వచించు S_MOD_పదం_FUNC_సూచికలు        0xa

#నిర్వచించు S_ATTR_శుద్ధ_INSTRUCTIONS        0x80000000
#నిర్వచించు S_ATTR_SOME_INSTRUCTIONS        0x00000400
#నిర్వచించు S_ATTR_DEBUG             	0x02000000


రకనిర్వచనం uint32_t lc_str;

నిర్మాణం dylib_command {
    uint32_t cmd;                   /* LC_ID_DYLIB, LC_LOAD_{,WEAK_}DYLIB,
                                       LC_REEXPORT_DYLIB */
    uint32_t cmdsize;               /* includes pathname string */
    lc_str   name;                  /* library's path name */
    uint32_t timestamp;             /* library's build time stamp */
    uint32_t current_సంస్కరణ;       /* library's current version number */
    uint32_t compatibility_సంస్కరణ; /* library's compatibility vers number*/
};

నిర్మాణం rpath_command {
    uint32_t     cmd;           /* LC_RPATH */
    uint32_t     cmdsize;       /* includes string */
    lc_str       మార్గం;          /* path to add to run path */
};

నిర్మాణం dylinker_command {
    uint32_t        cmd;            /* LC_ID_DYLINKER, LC_LOAD_DYLINKER or
                                       LC_DYLD_ENVIRONMENT */
    uint32_t        cmdsize;        /* includes pathname string */
    lc_str          name;           /* dynamic linker's path name */
};

నిర్మాణం linkedit_దత్తాంశం_command {
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

#నిర్వచించు PLATFORM_MACOS 1

నిర్మాణం build_సంస్కరణ_command {
    uint32_t    cmd;            /* LC_BUILD_VERSION */
    uint32_t    cmdsize;        /* sizeof(struct build_version_command) plus */
                                /* ntools * sizeof(struct build_tool_version) */
    uint32_t    platform;       /* platform */
    uint32_t    minos;          /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    sdk;            /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    ntools;         /* number of tool entries following this */
};

నిర్మాణం ఆధారం_సంస్కరణ_command {
    uint32_t  cmd;      /* LC_SOURCE_VERSION */
    uint32_t  cmdsize;  /* 16 */
    uint64_t  సంస్కరణ;  /* A.B.C.D.E packed as a24.b10.c10.d10.e10 */
};

నిర్మాణం symtab_command {
    uint32_t        cmd;            /* LC_SYMTAB */
    uint32_t        cmdsize;        /* sizeof(struct symtab_command) */
    uint32_t        symoff;         /* symbol table offset */
    uint32_t        nsyms;          /* number of symbol table entries */
    uint32_t        stroff;         /* string table offset */
    uint32_t        strsize;        /* string table size in bytes */
};

నిర్మాణం dysymtab_command {
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

#నిర్వచించు BIND_OPCODE_పూర్తి                                        0x00
#నిర్వచించు BIND_OPCODE_సమితి_DYLIB_SPECIAL_IMM                       0x30
#నిర్వచించు BIND_OPCODE_సమితి_చిహ్నం_TRAILING_FLAGS_IMM               0x40
#నిర్వచించు BIND_OPCODE_సమితి_TYPE_IMM                                0x50
#నిర్వచించు BIND_OPCODE_సమితి_SEGMENT_AND_స్థానభ్రంశం_ULEB                 0x70
#నిర్వచించు BIND_OPCODE_DO_BIND                                     0x90

#నిర్వచించు BIND_చిహ్నం_FLAGS_WEAK_IMPORT                           0x1

#నిర్వచించు BIND_TYPE_సూచిక                                       1
#నిర్వచించు BIND_SPECIAL_DYLIB_FLAT_LOOKUP                          -2

#నిర్వచించు REBASE_OPCODE_పూర్తి                                      0x00
#నిర్వచించు REBASE_OPCODE_సమితి_TYPE_IMM                              0x10
#నిర్వచించు REBASE_OPCODE_సమితి_SEGMENT_AND_స్థానభ్రంశం_ULEB               0x20
#నిర్వచించు REBASE_OPCODE_DO_REBASE_IMM_TIMES                       0x50

#నిర్వచించు REBASE_TYPE_సూచిక                                     1

#నిర్వచించు EXPORT_చిహ్నం_FLAGS_రకం_REGULAR                        0x00
#నిర్వచించు EXPORT_చిహ్నం_FLAGS_రకం_ABSOLUTE                       0x02
#నిర్వచించు EXPORT_చిహ్నం_FLAGS_WEAK_DEFINITION                     0x04

నిర్మాణం dyld_info_command {
    uint32_t cmd;             /* LC_DYLD_INFO or LC_DYLD_INFO_ONLY */
    uint32_t cmdsize;         /* sizeof(struct dyld_info_command) */
    uint32_t rebase_off;      /* file offset to rebase info  */
    uint32_t rebase_కొలత;     /* size of rebase info   */
    uint32_t bind_off;        /* file offset to binding info   */
    uint32_t bind_కొలత;       /* size of binding info  */
    uint32_t weak_bind_off;   /* file offset to weak binding info   */
    uint32_t weak_bind_కొలత;  /* size of weak binding info  */
    uint32_t lazy_bind_off;   /* file offset to lazy binding info */
    uint32_t lazy_bind_కొలత;  /* size of lazy binding infs */
    uint32_t export_off;      /* file offset to lazy binding info */
    uint32_t export_కొలత;     /* size of lazy binding infs */
};

#నిర్వచించు పరోక్ష_చిహ్నం_LOCAL   0x80000000

నిర్మాణం నమోదు_బిందువు_command {
    uint32_t  cmd;      /* LC_MAIN only used in MH_EXECUTE filetypes */
    uint32_t  cmdsize;  /* 24 */
    uint64_t  entryoff; /* file (__TEXT) offset of main() */
    uint64_t  stacksize;/* if not zero, initial stack size */
};

గణన skind {
    sk_unknown = 0,
    sk_discard,
    sk_పాఠ్యం,
    sk_stubs,
    sk_stub_helper,
    sk_ro_దత్తాంశం,
    sk_uw_info,
    sk_nl_ptr,  // non-lazy pointers, aka GOT
    sk_debug_info,
    sk_debug_abbrev,
    sk_debug_పంక్తి,
    sk_debug_aranges,
    sk_debug_str,
    sk_debug_పంక్తి_str,
    sk_stab,
    sk_stab_str,
    sk_la_ptr,  // lazy pointers
    sk_init,
    sk_fini,
    sk_rw_దత్తాంశం,
    sk_bss,
    sk_linkedit,
    sk_చివరి
};

నిర్మాణం nlist_64 {
    uint32_t  n_strx;      /* index into the string table */
    uint8_t n_type;        /* type flag, see below */
    uint8_t n_sect;        /* section number or NO_SECT */
    uint16_t n_desc;       /* see <mach-o/stab.h> */
    uint64_t n_విలువ;      /* value of this symbol (or stab offset) */
};

#నిర్వచించు N_UNDF  0x0
#నిర్వచించు N_ABS   0x2
#నిర్వచించు N_EXT   0x1
#నిర్వచించు N_SECT  0xe

#నిర్వచించు N_WEAK_REF      0x0040
#నిర్వచించు N_WEAK_DEF      0x0080

నిర్మాణం macho {
    నిర్మాణం mach_శీర్షిక_64 mh;
    పూర్ణాంకం *seg2lc, nseg;
    నిర్మాణం ఎక్కించు_command **lc;
    నిర్మాణం నమోదు_బిందువు_command *ep;
    పూర్ణాంకం nlc;
    నిర్మాణం {
        Section *s;
        పూర్ణాంకం machosect;
    } sk_గమ్యం_sect[sk_చివరి];
    పూర్ణాంకం *elfsectomacho;
    పూర్ణాంకం *e2msym;
    Section *symtab, *strtab, *indirsyms, *stubs, *exports;
    uint32_t ilocal, iextdef, iundef;
    పూర్ణాంకం stubsym, n_got, nr_plt;
    పూర్ణాంకం segment[sk_చివరి];
#నిర్వచితమైతే CONFIG_NEW_MACHO
    Section *chained_fixups;
    పూర్ణాంకం n_bind;
    పూర్ణాంకం n_bind_rebase;
    నిర్మాణం bind_rebase {
	పూర్ణాంకం section;
	పూర్ణాంకం bind;
	ElfW_Rel rel;
    } *bind_rebase;
#లేకపోతే
    Section *rebase, *binding, *weak_binding, *lazy_binding;
    Section *stub_helper, *la_చిహ్నం_ptr;
    నిర్మాణం dyld_info_command *dyldinfo;
    పూర్ణాంకం helpsym, lasym, dyld_వ్యక్తిగత, dyld_stub_binder;
    పూర్ణాంకం n_lazy_bind;    
    నిర్మాణం s_lazy_bind {
        పూర్ణాంకం section;
        పూర్ణాంకం bind_స్థానభ్రంశం;
        పూర్ణాంకం la_చిహ్నం_స్థానభ్రంశం;
        ElfW_Rel rel;
    } *s_lazy_bind;
    పూర్ణాంకం n_rebase;    
    నిర్మాణం s_rebase {
        పూర్ణాంకం section;
        ElfW_Rel rel;
    } *s_rebase;
    పూర్ణాంకం n_bind; 
    నిర్మాణం bind {
        పూర్ణాంకం section;
        ElfW_Rel rel;
    } *bind;
#అయితే_ముగింపు
};

#నిర్వచించు SHT_LINKEDIT (SHT_LOOS + 42)
#నిర్వచించు SHN_FROMDLL  (SHN_LOOS + 2)  /* Symbol is undefined, comes from a DLL */

స్థిర శూన్య * కూడు_lc(నిర్మాణం macho *mo, uint32_t cmd, uint32_t cmdsize)
{
    నిర్మాణం ఎక్కించు_command *lc = tcc_mallocz(cmdsize);
    lc->cmd = cmd;
    lc->cmdsize = cmdsize;
    mo->lc = tcc_realloc(mo->lc, పరిమాణం(mo->lc[0]) * (mo->nlc + 1));
    mo->lc[mo->nlc++] = lc;
    తిరిగి lc;
}

స్థిర నిర్మాణం segment_command_64 * కూడు_segment(నిర్మాణం macho *mo, స్థిరరాశి అక్షరం *name)
{
    నిర్మాణం segment_command_64 *sc = కూడు_lc(mo, LC_SEGMENT_64, పరిమాణం(*sc));
    strncpy(sc->segname, name, 16);
    mo->seg2lc = tcc_realloc(mo->seg2lc, పరిమాణం(*mo->seg2lc) * (mo->nseg + 1));
    mo->seg2lc[mo->nseg++] = mo->nlc - 1;
    తిరిగి sc;
}

స్థిర నిర్మాణం segment_command_64 * get_segment(నిర్మాణం macho *mo, పూర్ణాంకం i)
{
    తిరిగి (నిర్మాణం segment_command_64 *) (mo->lc[mo->seg2lc[i]]);
}

స్థిర పూర్ణాంకం కూడు_section(నిర్మాణం macho *mo, నిర్మాణం segment_command_64 **_seg, స్థిరరాశి అక్షరం *name)
{
    నిర్మాణం segment_command_64 *seg = *_seg;
    పూర్ణాంకం ret = seg->nsects;
    నిర్మాణం section_64 *sec;
    seg->nsects++;
    seg->cmdsize += పరిమాణం(*sec);
    seg = tcc_realloc(seg, పరిమాణం(*seg) + seg->nsects * పరిమాణం(*sec));
    sec = (నిర్మాణం section_64*)((అక్షరం*)seg + పరిమాణం(*seg)) + ret;
    memset(sec, 0, పరిమాణం(*sec));
    strncpy(sec->sectname, name, 16);
    strncpy(sec->segname, seg->segname, 16);
    *_seg = seg;
    తిరిగి ret;
}

స్థిర నిర్మాణం section_64 *get_section(నిర్మాణం segment_command_64 *seg, పూర్ణాంకం i)
{
    తిరిగి (నిర్మాణం section_64*)((అక్షరం*)seg + పరిమాణం(*seg)) + i;
}

స్థిర శూన్య * కూడు_dylib(నిర్మాణం macho *mo, అక్షరం *name)
{
    నిర్మాణం dylib_command *lc;
    పూర్ణాంకం sz = (పరిమాణం(*lc) + అక్షరశ్రేణి_పొడవు(name) + 1 + 7) & -8;
    lc = కూడు_lc(mo, LC_ఎక్కించు_DYLIB, sz);
    lc->name = పరిమాణం(*lc);
    strcpy((అక్షరం*)lc + lc->name, name);
    lc->timestamp = 2;
    lc->current_సంస్కరణ = 1 << 16;
    lc->compatibility_సంస్కరణ = 1 << 16;
    తిరిగి lc;
}

స్థిర పూర్ణాంకం uleb128_కొలత (గుర్తులేని దీర్ఘ దీర్ఘ విలువ)
{
    పూర్ణాంకం కొలత =  0;

    చేయి {
        విలువ >>= 7;
        కొలత++;
    } అయితే (విలువ != 0);
    తిరిగి కొలత;
}

స్థిర శూన్య write_uleb128(Section *section, uint64_t విలువ)
{
    చేయి {
        గుర్తులేని అక్షరం byte = విలువ & 0x7f;
	uint8_t *ptr = section_ptr_కూడు(section, 1);

        విలువ >>= 7;
        *ptr = byte | (విలువ ? 0x80 : 0);
    } అయితే (విలువ != 0);
}

స్థిర శూన్య tcc_macho_కూడు_destructor(TCCState *s1)
{
    పూర్ణాంకం init_sym, mh_execute_శీర్షిక, at_exit_sym;
    Section *s;
    ElfW_Rel *rel;
    uint8_t *ptr;

    mh_execute_శీర్షిక = put_elf_sym(s1->symtab, -4096, 0,
				    ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				    పాఠ్యం_section->sh_అంకె, "__mh_execute_header");
    s = కనుగొను_section(s1, ".fini_array");
    ఒకవేళ (s->దత్తాంశం_స్థానభ్రంశం == 0)
        తిరిగి; 
    init_sym = put_elf_sym(s1->symtab, పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం, 0,
                           ELFW(ST_INFO)(STB_LOCAL, STT_FUNC), 0,
                           పాఠ్యం_section->sh_అంకె, "___GLOBAL_init_65535");
    at_exit_sym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0,
                              SHN_UNDEF, "___cxa_atexit");
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    ptr = section_ptr_కూడు(పాఠ్యం_section, 4);
    ptr[0] = 0x55;  // pushq   %rbp
    ptr[1] = 0x48;  // movq    %rsp, %rbp
    ptr[2] = 0x89;
    ptr[3] = 0xe5;
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        పూర్ణాంకం sym_సూచీ = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_కూడు(పాఠ్యం_section, 26);
        ptr[0] = 0x48;  // lea destructor(%rip),%rax
        ptr[1] = 0x8d;
        ptr[2] = 0x05;
        put_elf_reloca(s1->symtab, పాఠ్యం_section, 
		       పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం - 23,
		       R_X86_64_PC32, sym_సూచీ, -4);
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
        put_elf_reloca(s1->symtab, పాఠ్యం_section,
		       పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం - 9,
		       R_X86_64_PC32, mh_execute_శీర్షిక, -4);
	ptr[21] = 0xe8; // call __cxa_atexit
        put_elf_reloca(s1->symtab, పాఠ్యం_section,
		       పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం - 4,
		       R_X86_64_PLT32, at_exit_sym, -4);
    }
    ptr = section_ptr_కూడు(పాఠ్యం_section, 2);
    ptr[0] = 0x5d;  // pop   %rbp
    ptr[1] = 0xc3;  // ret
#లేదావేళ defined TCC_లక్ష్యం_ARM64
    ptr = section_ptr_కూడు(పాఠ్యం_section, 8);
    write32le(ptr, 0xa9bf7bfd);     // stp     x29, x30, [sp, #-16]!
    write32le(ptr + 4, 0x910003fd); // mov     x29, sp
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        పూర్ణాంకం sym_సూచీ = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_కూడు(పాఠ్యం_section, 24);
        put_elf_reloc(s1->symtab, పాఠ్యం_section, 
		      పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం - 24,
		      R_AARCH64_ADR_PREL_PG_HI21, sym_సూచీ);
        write32le(ptr, 0x90000000);      // adrp x0, destructor@page
        put_elf_reloc(s1->symtab, పాఠ్యం_section,
		      పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం - 20,
		      R_AARCH64_LDST8_ABS_LO12_NC, sym_సూచీ);
        write32le(ptr + 4, 0x91000000);  // add x0,x0,destructor@pageoff
        write32le(ptr + 8, 0xd2800001);  // mov x1, #0
        put_elf_reloc(s1->symtab, పాఠ్యం_section, 
		      పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం - 12,
		      R_AARCH64_ADR_PREL_PG_HI21, mh_execute_శీర్షిక);
        write32le(ptr + 12, 0x90000002);      // adrp x2, mh_execute_header@page
        put_elf_reloc(s1->symtab, పాఠ్యం_section,
		      పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం - 8,
		      R_AARCH64_LDST8_ABS_LO12_NC, mh_execute_శీర్షిక);
        write32le(ptr + 16, 0x91000042);  // add x2,x2,mh_execute_header@pageoff
        put_elf_reloc(s1->symtab, పాఠ్యం_section,
		      పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం - 4,
		      R_AARCH64_CALL26, at_exit_sym);
	write32le(ptr + 20, 0x94000000); // bl __cxa_atexit
    }
    ptr = section_ptr_కూడు(పాఠ్యం_section, 8);
    write32le(ptr, 0xa8c17bfd);     // ldp     x29, x30, [sp], #16
    write32le(ptr + 4, 0xd65f03c0); // ret
#అయితే_ముగింపు
    s->reloc->దత్తాంశం_స్థానభ్రంశం = s->దత్తాంశం_స్థానభ్రంశం = 0;
    s->sh_flags &= ~SHF_ALLOC;
    కూడు_array (s1, ".init_array", init_sym);
}

#నిర్వచితమైతే CONFIG_NEW_MACHO
స్థిర శూన్య bind_rebase_కూడు(నిర్మాణం macho *mo, పూర్ణాంకం bind, పూర్ణాంకం sh_info,
			    ElfW_Rel *rel, నిర్మాణం sym_attr *attr)
{
    mo->bind_rebase = tcc_realloc(mo->bind_rebase, (mo->n_bind_rebase + 1) *
		                  పరిమాణం(నిర్మాణం bind_rebase));
    mo->bind_rebase[mo->n_bind_rebase].section = sh_info;
    mo->bind_rebase[mo->n_bind_rebase].bind = bind;
    mo->bind_rebase[mo->n_bind_rebase].rel = *rel;
    ఒకవేళ (attr)
        mo->bind_rebase[mo->n_bind_rebase].rel.r_స్థానభ్రంశం = attr->got_స్థానభ్రంశం;
    mo->n_bind_rebase++;
    mo->n_bind += bind;
}

స్థిర శూన్య check_relocs(TCCState *s1, నిర్మాణం macho *mo)
{
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    పూర్ణాంకం i, j, type, gotplt_నమోదు, sym_సూచీ, for_సంకేతం;
    uint32_t *pi, *goti;
    నిర్మాణం sym_attr *attr;

    goti = ఖాళీ;
    mo->nr_plt = mo->n_got = 0;
    కొరకు (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ఒకవేళ (s->sh_type != SHT_RELX ||
	    !అక్షరశ్రేణి_పోలిక(s1->sections[s->sh_info]->name, ".debug_", 7))
            కొనసాగు;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_నమోదు = gotplt_నమోదు_type(type);
            for_సంకేతం = సంకేతం_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_సూచీ = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
            ఒకవేళ (sym->st_shndx == SHN_UNDEF
                || gotplt_నమోదు == ALWAYS_GOTPLT_నమోదు) {
                attr = get_sym_attr(s1, sym_సూచీ, 1);
                ఒకవేళ (!attr->dyn_సూచీ) {
                    attr->got_స్థానభ్రంశం = s1->got->దత్తాంశం_స్థానభ్రంశం;
                    attr->plt_స్థానభ్రంశం = -1;
                    attr->dyn_సూచీ = 1; /* used as flag */
                    section_ptr_కూడు(s1->got, PTR_కొలత);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_స్థానభ్రంశం,
                                  R_JMP_స్థానం, sym_సూచీ);
	 	    goti = tcc_realloc(goti, (mo->n_got + 1) * పరిమాణం(*goti));
                    ఒకవేళ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        ఒకవేళ (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name);
			goti[mo->n_got++] = పరోక్ష_చిహ్నం_LOCAL;
                    } లేకపోతే {
                        goti[mo->n_got++] = mo->e2msym[sym_సూచీ];
                        ఒకవేళ (sym->st_shndx == SHN_UNDEF
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
                            && type == R_X86_64_GOTPCREL
#లేదావేళ defined TCC_లక్ష్యం_ARM64
                            && type == R_AARCH64_ADR_GOT_పుట
#అయితే_ముగింపు
                            ) {
			    attr->plt_స్థానభ్రంశం = -mo->n_bind_rebase - 2;
			    bind_rebase_కూడు(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
			    s1->got->reloc->దత్తాంశం_స్థానభ్రంశం -= పరిమాణం (ElfW_Rel);
			}
		        ఒకవేళ (for_సంకేతం && sym->st_shndx == SHN_UNDEF)
			    s1->got->reloc->దత్తాంశం_స్థానభ్రంశం -= పరిమాణం (ElfW_Rel);
		    }
                }
                ఒకవేళ (for_సంకేతం && sym->st_shndx == SHN_UNDEF) {
		    ఒకవేళ ((పూర్ణాంకం)attr->plt_స్థానభ్రంశం < -1) {
			/* remove above bind and replace with plt */
			mo->bind_rebase[-attr->plt_స్థానభ్రంశం - 2].bind = 2;
			attr->plt_స్థానభ్రంశం = -1;
		    }
                    ఒకవేళ (attr->plt_స్థానభ్రంశం == -1) {
                        uint8_t *jmp;

                        attr->plt_స్థానభ్రంశం = mo->stubs->దత్తాంశం_స్థానభ్రంశం;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
                        ఒకవేళ (type != R_X86_64_PLT32)
                             కొనసాగు;
                        jmp = section_ptr_కూడు(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *ofs(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_స్థానభ్రంశం + 2,
                                      R_X86_64_GOTPCREL, sym_సూచీ);
#లేదావేళ defined TCC_లక్ష్యం_ARM64
                        ఒకవేళ (type != R_AARCH64_CALL26)
                             కొనసాగు;
                        jmp = section_ptr_కూడు(mo->stubs, 12);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_స్థానభ్రంశం,
                                      R_AARCH64_ADR_GOT_పుట, sym_సూచీ);
                        write32le(jmp, // adrp x16, #sym
                                  0x90000010);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_స్థానభ్రంశం + 4,
                                      R_AARCH64_LD64_GOT_LO12_NC, sym_సూచీ);
                        write32le(jmp + 4, // ld x16,[x16, #sym]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);
#అయితే_ముగింపు
			bind_rebase_కూడు(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
                        pi = section_ptr_కూడు(mo->indirsyms, పరిమాణం(*pi));
                        *pi = mo->e2msym[sym_సూచీ];
                        mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_స్థానభ్రంశం;
                }
            }
	    ఒకవేళ (type == R_దత్తాంశం_PTR || type == R_JMP_స్థానం)
		bind_rebase_కూడు(mo, sym->st_shndx == SHN_UNDEF ? 1 : 0,
				s->sh_info, &save_rel, ఖాళీ);
        }
    }
    /* remove deleted binds */
    కొరకు (i = 0, j = 0; i < mo->n_bind_rebase; i++)
	ఒకవేళ (mo->bind_rebase[i].bind == 2)
	    mo->n_bind--;
	లేకపోతే
	    mo->bind_rebase[j++] = mo->bind_rebase[i];
    mo->n_bind_rebase = j;
    pi = section_ptr_కూడు(mo->indirsyms, mo->n_got * పరిమాణం(*pi));
    జ్ఞాపకం_నకలు(pi, goti, mo->n_got * పరిమాణం(*pi));
    tcc_free(goti);
}

#లేకపోతే

స్థిర శూన్య check_relocs(TCCState *s1, నిర్మాణం macho *mo)
{
    uint8_t *jmp;
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    పూర్ణాంకం i, type, gotplt_నమోదు, sym_సూచీ, for_సంకేతం;
    పూర్ణాంకం bind_స్థానభ్రంశం, la_చిహ్నం_స్థానభ్రంశం;
    uint32_t *pi, *goti;
    నిర్మాణం sym_attr *attr;

#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    jmp = section_ptr_కూడు(mo->stub_helper, 16);
    jmp[0] = 0x4c;  /* leaq _dyld_private(%rip), %r11 */
    jmp[1] = 0x8d;
    jmp[2] = 0x1d;
    put_elf_reloca(s1->symtab, mo->stub_helper, 3,
		   R_X86_64_PC32, mo->dyld_వ్యక్తిగత, -4);
    jmp[7] = 0x41;  /* pushq %r11 */
    jmp[8] = 0x53;
    jmp[9] = 0xff;  /* jmpq    *dyld_stub_binder@GOT(%rip) */
    jmp[10] = 0x25;
    put_elf_reloca(s1->symtab, mo->stub_helper, 11,
		   R_X86_64_GOTPCREL, mo->dyld_stub_binder, -4);
    jmp[15] = 0x90; /* nop */
#లేదావేళ defined TCC_లక్ష్యం_ARM64
    jmp = section_ptr_కూడు(mo->stub_helper, 24);
    put_elf_reloc(s1->symtab, mo->stub_helper, 0,
		  R_AARCH64_ADR_PREL_PG_HI21, mo->dyld_వ్యక్తిగత);
    write32le(jmp, 0x90000011); // adrp x17, _dyld_private@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 4,
		  R_AARCH64_LDST64_ABS_LO12_NC, mo->dyld_వ్యక్తిగత);
    write32le(jmp + 4, 0x91000231); // add x17,x17,_dyld_private@pageoff
    write32le(jmp + 8, 0xa9bf47f0); // stp x16/x17, [sp, #-16]!
    put_elf_reloc(s1->symtab, mo->stub_helper, 12,
		  R_AARCH64_ADR_GOT_పుట, mo->dyld_stub_binder);
    write32le(jmp + 12, 0x90000010); // adrp x16, dyld_stub_binder@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 16,
		  R_AARCH64_LD64_GOT_LO12_NC, mo->dyld_stub_binder);
    write32le(jmp + 16, 0xf9400210); // ldr x16,[x16,dyld_stub_binder@pageoff]
    write32le(jmp + 20, 0xd61f0200); // br x16
#అయితే_ముగింపు
    
    goti = ఖాళీ;
    mo->nr_plt = mo->n_got = 0;
    కొరకు (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ఒకవేళ (s->sh_type != SHT_RELX ||
	    !అక్షరశ్రేణి_పోలిక(s1->sections[s->sh_info]->name, ".debug_", 7))
            కొనసాగు;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_నమోదు = gotplt_నమోదు_type(type);
            for_సంకేతం = సంకేతం_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_సూచీ = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
            ఒకవేళ (sym->st_shndx == SHN_UNDEF
                || gotplt_నమోదు == ALWAYS_GOTPLT_నమోదు) {
                attr = get_sym_attr(s1, sym_సూచీ, 1);
                ఒకవేళ (!attr->dyn_సూచీ) {
                    attr->got_స్థానభ్రంశం = s1->got->దత్తాంశం_స్థానభ్రంశం;
                    attr->plt_స్థానభ్రంశం = -1;
                    attr->dyn_సూచీ = 1; /* used as flag */
		    section_ptr_కూడు(s1->got, PTR_కొలత);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_స్థానభ్రంశం,
                                  R_JMP_స్థానం, sym_సూచీ);
		    goti = tcc_realloc(goti, (mo->n_got + 1) * పరిమాణం(*goti));
                    ఒకవేళ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        ఒకవేళ (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name);
			goti[mo->n_got++] = పరోక్ష_చిహ్నం_LOCAL;
                    } లేకపోతే {
			goti[mo->n_got++] = mo->e2msym[sym_సూచీ];
			ఒకవేళ (sym->st_shndx == SHN_UNDEF
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
			    && type == R_X86_64_GOTPCREL
#లేదావేళ defined TCC_లక్ష్యం_ARM64
			    && type == R_AARCH64_ADR_GOT_పుట
#అయితే_ముగింపు
			    ) {
			    mo->bind =
			        tcc_realloc(mo->bind,
					    (mo->n_bind + 1) *
					    పరిమాణం(నిర్మాణం bind));
			    mo->bind[mo->n_bind].section = s1->got->reloc->sh_info;
			    mo->bind[mo->n_bind].rel = save_rel;
                            mo->bind[mo->n_bind].rel.r_స్థానభ్రంశం = attr->got_స్థానభ్రంశం;
			    mo->n_bind++;
			    s1->got->reloc->దత్తాంశం_స్థానభ్రంశం -= పరిమాణం (ElfW_Rel);
			}
		    }
                }
                ఒకవేళ (for_సంకేతం && sym->st_shndx == SHN_UNDEF) {
                    ఒకవేళ (attr->plt_స్థానభ్రంశం == -1) {
                        attr->plt_స్థానభ్రంశం = mo->stubs->దత్తాంశం_స్థానభ్రంశం;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
			ఒకవేళ (type != R_X86_64_PLT32)
			     కొనసాగు;
			/* __stubs */
                        jmp = section_ptr_కూడు(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *__la_symbol_ptr(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->దత్తాంశం_స్థానభ్రంశం - 4,
                                       R_X86_64_PC32, mo->lasym,
				       mo->la_చిహ్నం_ptr->దత్తాంశం_స్థానభ్రంశం - 4);

			/* __stub_helper */
			bind_స్థానభ్రంశం = mo->stub_helper->దత్తాంశం_స్థానభ్రంశం + 1;
                        jmp = section_ptr_కూడు(mo->stub_helper, 10);
                        jmp[0] = 0x68;  /* pushq $bind_offset */
                        jmp[5] = 0xe9;  /* jmpq __stub_helper */
                        write32le(jmp + 6, -mo->stub_helper->దత్తాంశం_స్థానభ్రంశం);

			/* __la_symbol_ptr */
			la_చిహ్నం_స్థానభ్రంశం = mo->la_చిహ్నం_ptr->దత్తాంశం_స్థానభ్రంశం;
                        put_elf_reloca(s1->symtab, mo->la_చిహ్నం_ptr,
				       mo->la_చిహ్నం_ptr->దత్తాంశం_స్థానభ్రంశం,
				       R_దత్తాంశం_PTR, mo->helpsym,
				       mo->stub_helper->దత్తాంశం_స్థానభ్రంశం - 10);
			section_ptr_కూడు(mo->la_చిహ్నం_ptr, PTR_కొలత);
#లేదావేళ defined TCC_లక్ష్యం_ARM64
			ఒకవేళ (type != R_AARCH64_CALL26)
			     కొనసాగు;
			/* __stubs */
                        jmp = section_ptr_కూడు(mo->stubs, 12);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->దత్తాంశం_స్థానభ్రంశం - 12,
                                       R_AARCH64_ADR_PREL_PG_HI21, mo->lasym,
				       mo->la_చిహ్నం_ptr->దత్తాంశం_స్థానభ్రంశం);
                        write32le(jmp, // adrp x16, __la_symbol_ptr@page
                                  0x90000010);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->దత్తాంశం_స్థానభ్రంశం - 8,
                                       R_AARCH64_LDST64_ABS_LO12_NC, mo->lasym,
				       mo->la_చిహ్నం_ptr->దత్తాంశం_స్థానభ్రంశం);
                        write32le(jmp + 4, // ldr x16,[x16, __la_symbol_ptr@pageoff]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);

			/* __stub_helper */
			bind_స్థానభ్రంశం = mo->stub_helper->దత్తాంశం_స్థానభ్రంశం + 8;
                        jmp = section_ptr_కూడు(mo->stub_helper, 12);
                        write32le(jmp + 0, // ldr  w16, l0
                                  0x18000050);
                        write32le(jmp + 4, // b stubHelperHeader
                                  0x14000000 +
				  ((-(mo->stub_helper->దత్తాంశం_స్థానభ్రంశం - 8) / 4) &
				   0x3ffffff));
                        write32le(jmp + 8, 0); // l0: .long bind_offset

			/* __la_symbol_ptr */
			la_చిహ్నం_స్థానభ్రంశం = mo->la_చిహ్నం_ptr->దత్తాంశం_స్థానభ్రంశం;
                        put_elf_reloca(s1->symtab, mo->la_చిహ్నం_ptr,
				       mo->la_చిహ్నం_ptr->దత్తాంశం_స్థానభ్రంశం,
				       R_దత్తాంశం_PTR, mo->helpsym,
				       mo->stub_helper->దత్తాంశం_స్థానభ్రంశం - 12);
			section_ptr_కూడు(mo->la_చిహ్నం_ptr, PTR_కొలత);
#అయితే_ముగింపు
                        mo->s_lazy_bind =
                            tcc_realloc(mo->s_lazy_bind, (mo->n_lazy_bind + 1) *
                                        పరిమాణం(నిర్మాణం s_lazy_bind));
                        mo->s_lazy_bind[mo->n_lazy_bind].section =
                            mo->stub_helper->reloc->sh_info;
                        mo->s_lazy_bind[mo->n_lazy_bind].bind_స్థానభ్రంశం =
			    bind_స్థానభ్రంశం;
                        mo->s_lazy_bind[mo->n_lazy_bind].la_చిహ్నం_స్థానభ్రంశం =
			    la_చిహ్నం_స్థానభ్రంశం;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel = save_rel;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel.r_స్థానభ్రంశం =
                            attr->plt_స్థానభ్రంశం;
                        mo->n_lazy_bind++;
			pi = section_ptr_కూడు(mo->indirsyms, పరిమాణం(*pi));
			*pi = mo->e2msym[sym_సూచీ];
			mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_స్థానభ్రంశం;
                }
            }
            ఒకవేళ (type == R_దత్తాంశం_PTR || type == R_JMP_స్థానం) {
		ఒకవేళ (sym->st_shndx == SHN_UNDEF) {
		    mo->bind = tcc_realloc(mo->bind,
					   (mo->n_bind + 1) *
					   పరిమాణం(నిర్మాణం bind));
		    mo->bind[mo->n_bind].section = s->sh_info;
		    mo->bind[mo->n_bind].rel = save_rel;
		    mo->n_bind++;
		}
		లేకపోతే {
                    mo->s_rebase =
                        tcc_realloc(mo->s_rebase, (mo->n_rebase + 1) *
				    పరిమాణం(నిర్మాణం s_rebase));
                    mo->s_rebase[mo->n_rebase].section = s->sh_info;
                    mo->s_rebase[mo->n_rebase].rel = save_rel;
                    mo->n_rebase++;
		}
	    }
        }
    }
    pi = section_ptr_కూడు(mo->indirsyms, mo->n_got * పరిమాణం(*pi));
    జ్ఞాపకం_నకలు(pi, goti, mo->n_got * పరిమాణం(*pi));
    pi = section_ptr_కూడు(mo->indirsyms, mo->nr_plt * పరిమాణం(*pi));
    జ్ఞాపకం_నకలు(pi, mo->indirsyms->దత్తాంశం, mo->nr_plt * పరిమాణం(*pi));
    tcc_free(goti);
}
#అయితే_ముగింపు

స్థిర పూర్ణాంకం check_symbols(TCCState *s1, నిర్మాణం macho *mo)
{
    పూర్ణాంకం sym_సూచీ, sym_చివర;
    పూర్ణాంకం ret = 0;

    mo->ilocal = mo->iextdef = mo->iundef = -1;
    sym_చివర = symtab_section->దత్తాంశం_స్థానభ్రంశం / పరిమాణం(ElfW(Sym));
    కొరకు (sym_సూచీ = 1; sym_సూచీ < sym_చివర; ++sym_సూచీ) {
        పూర్ణాంకం elf_సూచీ = ((నిర్మాణం nlist_64 *)mo->symtab->దత్తాంశం + sym_సూచీ - 1)->n_విలువ;
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->దత్తాంశం + elf_సూచీ;
        స్థిరరాశి అక్షరం *name = (అక్షరం*)symtab_section->link->దత్తాంశం + sym->st_name;
        గుర్తులేని type = ELFW(ST_TYPE)(sym->st_info);
        గుర్తులేని bind = ELFW(ST_BIND)(sym->st_info);
        గుర్తులేని vis  = ELFW(ST_VISIBILITY)(sym->st_other);

        dprintf("%4d (%4d): %09lx %4d %4d %4d %3d %s\n",
                sym_సూచీ, elf_సూచీ, (దీర్ఘ)sym->st_విలువ,
                type, bind, vis, sym->st_shndx, name);
        ఒకవేళ (bind == STB_LOCAL) {
            ఒకవేళ (mo->ilocal == -1)
              mo->ilocal = sym_సూచీ - 1;
            ఒకవేళ (mo->iextdef != -1 || mo->iundef != -1)
              tcc_error("local syms after global ones");
        } లేకపోతే ఒకవేళ (sym->st_shndx != SHN_UNDEF) {
            ఒకవేళ (mo->iextdef == -1)
              mo->iextdef = sym_సూచీ - 1;
            ఒకవేళ (mo->iundef != -1)
              tcc_error("external defined symbol after undefined");
        } లేకపోతే ఒకవేళ (sym->st_shndx == SHN_UNDEF) {
            ఒకవేళ (mo->iundef == -1)
              mo->iundef = sym_సూచీ - 1;
            ఒకవేళ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK
		|| s1->output_type != TCC_OUTPUT_EXE
                || కనుగొను_elf_sym(s1->dynsymtab_section, name)) {
                /* Mark the symbol as coming from a dylib so that
                   relocate_syms doesn't complain.  Normally bind_exe_dynsyms
                   would do this check, and place the symbol into dynsym
                   which is checked by relocate_syms.  But Mach-O doesn't use
                   bind_exe_dynsyms.  */
                sym->st_shndx = SHN_FROMDLL;
                కొనసాగు;
            }
            tcc_error_noabort("unresolved reference to '%s'", name);
            ret = -1;
        }
    }
    తిరిగి ret;
}

స్థిర శూన్య convert_చిహ్నం(TCCState *s1, నిర్మాణం macho *mo, నిర్మాణం nlist_64 *pn)
{
    నిర్మాణం nlist_64 n = *pn;
    ElfSym *sym = (ElfW(Sym) *)symtab_section->దత్తాంశం + pn->n_విలువ;
    స్థిరరాశి అక్షరం *name = (అక్షరం*)symtab_section->link->దత్తాంశం + sym->st_name;
    ఎంపిక(ELFW(ST_TYPE)(sym->st_info)) {
    స్థితి STT_NOTYPE:
    స్థితి STT_OBJECT:
    స్థితి STT_FUNC:
    స్థితి STT_TLS:
    స్థితి STT_SECTION:
        n.n_type = N_SECT;
        ఆపు;
    స్థితి STT_FILE:
        n.n_type = N_ABS;
        ఆపు;
    అప్రమేయ:
        tcc_error("unhandled ELF symbol type %d %s",
                  ELFW(ST_TYPE)(sym->st_info), name);
    }
    ఒకవేళ (sym->st_shndx == SHN_UNDEF)
      tcc_error("should have been rewritten to SHN_FROMDLL: %s", name);
    లేకపోతే ఒకవేళ (sym->st_shndx == SHN_FROMDLL)
      n.n_type = N_UNDF, n.n_sect = 0;
    లేకపోతే ఒకవేళ (sym->st_shndx == SHN_ABS)
      n.n_type = N_ABS, n.n_sect = 0;
    లేకపోతే ఒకవేళ (sym->st_shndx >= SHN_LORESERVE)
      tcc_error("unhandled ELF symbol section %d %s", sym->st_shndx, name);
    లేకపోతే ఒకవేళ (!mo->elfsectomacho[sym->st_shndx]) {
      ఒకవేళ (అక్షరశ్రేణి_పోలిక(s1->sections[sym->st_shndx]->name, ".debug_", 7))
        tcc_error("ELF section %d(%s) not mapped into Mach-O for symbol %s",
                  sym->st_shndx, s1->sections[sym->st_shndx]->name, name);
    }
    లేకపోతే
      n.n_sect = mo->elfsectomacho[sym->st_shndx];
    ఒకవేళ (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL)
      n.n_type |=  N_EXT;
    లేకపోతే ఒకవేళ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
      n.n_desc |= N_WEAK_REF | (n.n_type != N_UNDF ? N_WEAK_DEF : 0);
    n.n_strx = pn->n_strx;
    n.n_విలువ = sym->st_విలువ;
    *pn = n;
}

స్థిర శూన్య convert_symbols(TCCState *s1, నిర్మాణం macho *mo)
{
    నిర్మాణం nlist_64 *pn;
    for_each_elem(mo->symtab, 0, pn, నిర్మాణం nlist_64)
        convert_చిహ్నం(s1, mo, pn);
}

స్థిర పూర్ణాంకం machosymcmp(స్థిరరాశి శూన్య *_a, స్థిరరాశి శూన్య *_b, శూన్య *arg)
{
    TCCState *s1 = arg;
    పూర్ణాంకం ea = ((నిర్మాణం nlist_64 *)_a)->n_విలువ;
    పూర్ణాంకం eb = ((నిర్మాణం nlist_64 *)_b)->n_విలువ;
    ElfSym *sa = (ElfSym *)symtab_section->దత్తాంశం + ea;
    ElfSym *sb = (ElfSym *)symtab_section->దత్తాంశం + eb;
    పూర్ణాంకం r;
    /* locals, then defined externals, then undefined externals, the
       last two sections also by name, otherwise stable sort */
    r = (ELFW(ST_BIND)(sb->st_info) == STB_LOCAL)
        - (ELFW(ST_BIND)(sa->st_info) == STB_LOCAL);
    ఒకవేళ (r)
      తిరిగి r;
    r = (sa->st_shndx == SHN_UNDEF) - (sb->st_shndx == SHN_UNDEF);
    ఒకవేళ (r)
      తిరిగి r;
    ఒకవేళ (ELFW(ST_BIND)(sa->st_info) != STB_LOCAL) {
        స్థిరరాశి అక్షరం * na = (అక్షరం*)symtab_section->link->దత్తాంశం + sa->st_name;
        స్థిరరాశి అక్షరం * nb = (అక్షరం*)symtab_section->link->దత్తాంశం + sb->st_name;
        r = strcmp(na, nb);
        ఒకవేళ (r)
          తిరిగి r;
    }
    తిరిగి ea - eb;
}

/* cannot use qsort because code has to be reentrant */
స్థిర శూన్య tcc_qsort (శూన్య  *పునాది, కొలత_t nel, కొలత_t వెడల్పు,
                       పూర్ణాంకం (*comp)(స్థిరరాశి శూన్య *, స్థిరరాశి శూన్య *, శూన్య *), శూన్య *arg)
{
    కొలత_t wnel, gap, wgap, i, j, k;
    అక్షరం *a, *b, tmp;

    wnel = వెడల్పు * nel;
    కొరకు (gap = 0; ++gap < nel;)
        gap *= 3;
    అయితే ( gap /= 3 ) {
        wgap = వెడల్పు * gap;
        కొరకు (i = wgap; i < wnel; i += వెడల్పు) {
            కొరకు (j = i - wgap; ;j -= wgap) {
                a = j + (అక్షరం *)పునాది;
                b = a + wgap;
                ఒకవేళ ( (*comp)(a, b, arg) <= 0 )
                    ఆపు;
                k = వెడల్పు;
                చేయి {
                    tmp = *a;
                    *a++ = *b;
                    *b++ = tmp;
                } అయితే ( --k );
                ఒకవేళ (j < wgap)
                    ఆపు;
            }
        }
    }
}

స్థిర శూన్య create_symtab(TCCState *s1, నిర్మాణం macho *mo)
{
    పూర్ణాంకం sym_సూచీ, sym_చివర;
    నిర్మాణం nlist_64 *pn;

    /* Stub creation belongs to check_relocs, but we need to create
       the symbol now, so its included in the sorting.  */
    mo->stubs = new_section(s1, "__stubs", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->stubsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stubs->sh_అంకె, ".__stubs");
#నిర్వచితమైతే CONFIG_NEW_MACHO
    mo->chained_fixups = new_section(s1, "CHAINED_FIXUPS",
				     SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#లేకపోతే
    mo->stub_helper = new_section(s1, "__stub_helper", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    mo->la_చిహ్నం_ptr = new_section(s1, "__la_symbol_ptr", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->helpsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stub_helper->sh_అంకె, ".__stub_helper");
    mo->lasym = put_elf_sym(s1->symtab, 0, 0,
                            ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                            mo->la_చిహ్నం_ptr->sh_అంకె, ".__la_symbol_ptr");
    section_ptr_కూడు(దత్తాంశం_section, -దత్తాంశం_section->దత్తాంశం_స్థానభ్రంశం & (PTR_కొలత - 1));
    mo->dyld_వ్యక్తిగత = put_elf_sym(s1->symtab, దత్తాంశం_section->దత్తాంశం_స్థానభ్రంశం, PTR_కొలత,
                                   ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT), 0,
                                   దత్తాంశం_section->sh_అంకె, ".__dyld_private");
    section_ptr_కూడు(దత్తాంశం_section, PTR_కొలత);
    mo->dyld_stub_binder = put_elf_sym(s1->symtab, 0, 0,
                		       ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				       SHN_UNDEF, "dyld_stub_binder");
    mo->rebase = new_section(s1, "REBASE", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->binding = new_section(s1, "BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->weak_binding = new_section(s1, "WEAK_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->lazy_binding = new_section(s1, "LAZY_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#అయితే_ముగింపు
    mo->exports = new_section(s1, "EXPORT", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->indirsyms = new_section(s1, "LEINDIR", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);

    mo->symtab = new_section(s1, "LESYMTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->strtab = new_section(s1, "LESTRTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    put_elf_str(mo->strtab, " "); /* Mach-O starts strtab with a space */
    sym_చివర = symtab_section->దత్తాంశం_స్థానభ్రంశం / పరిమాణం(ElfW(Sym));
    pn = section_ptr_కూడు(mo->symtab, పరిమాణం(*pn) * (sym_చివర - 1));
    కొరకు (sym_సూచీ = 1; sym_సూచీ < sym_చివర; ++sym_సూచీ) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->దత్తాంశం + sym_సూచీ;
        స్థిరరాశి అక్షరం *name = (అక్షరం*)symtab_section->link->దత్తాంశం + sym->st_name;
        pn[sym_సూచీ - 1].n_strx = put_elf_str(mo->strtab, name);
        pn[sym_సూచీ - 1].n_విలువ = sym_సూచీ;
    }
    section_ptr_కూడు(mo->strtab, -mo->strtab->దత్తాంశం_స్థానభ్రంశం & (PTR_కొలత - 1));
    tcc_qsort(pn, sym_చివర - 1, పరిమాణం(*pn), machosymcmp, s1);
    mo->e2msym = tcc_malloc(sym_చివర * పరిమాణం(*mo->e2msym));
    mo->e2msym[0] = -1;
    కొరకు (sym_సూచీ = 1; sym_సూచీ < sym_చివర; ++sym_సూచీ) {
        mo->e2msym[pn[sym_సూచీ - 1].n_విలువ] = sym_సూచీ - 1;
    }
}

స్థిరరాశి నిర్మాణం {
    పూర్ణాంకం seg_initial;
    uint32_t flags;
    స్థిరరాశి అక్షరం *name;
} skinfo[sk_చివరి] = {
    /*[sk_unknown] =*/        { 0 },
    /*[sk_discard] =*/        { 0 },
    /*[sk_text] =*/           { 1, S_REGULAR | S_ATTR_శుద్ధ_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS, "__text" },
    /*[sk_stubs] =*/          { 1, S_REGULAR | S_ATTR_శుద్ధ_INSTRUCTIONS | S_చిహ్నం_STUBS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stubs" },
    /*[sk_stub_helper] =*/    { 1, S_REGULAR | S_ATTR_శుద్ధ_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stub_helper" },
    /*[sk_ro_data] =*/        { 2, S_REGULAR, "__rodata" },
    /*[sk_uw_info] =*/        { 0 },
    /*[sk_nl_ptr] =*/         { 2, S_NON_LAZY_చిహ్నం_సూచికలు, "__got" },
    /*[sk_debug_info] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_info" },
    /*[sk_debug_abbrev] =*/   { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_abbrev" },
    /*[sk_debug_line] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line" },
    /*[sk_debug_aranges] =*/  { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_aranges" },
    /*[sk_debug_str] =*/      { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_str" },
    /*[sk_debug_line_str] =*/ { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line_str" },
    /*[sk_stab] =*/           { 4, S_REGULAR, "__stab" },
    /*[sk_stab_str] =*/       { 4, S_REGULAR, "__stab_str" },
    /*[sk_la_ptr] =*/         { 4, S_LAZY_చిహ్నం_సూచికలు, "__la_symbol_ptr" },
    /*[sk_init] =*/           { 4, S_MOD_INIT_FUNC_సూచికలు, "__mod_init_func" },
    /*[sk_fini] =*/           { 4, S_MOD_పదం_FUNC_సూచికలు, "__mod_term_func" },
    /*[sk_rw_data] =*/        { 4, S_REGULAR, "__data" },
    /*[sk_bss] =*/            { 4, S_ZEROFILL, "__bss" },
    /*[sk_linkedit] =*/       { 5, S_REGULAR, ఖాళీ },
};

#నిర్వచించు	ప్రారంభం_3	((uint64_t)1 << 32)

స్థిరరాశి నిర్మాణం {
    పూర్ణాంకం వాడిన;
    స్థిరరాశి అక్షరం *name;
    uint64_t vmaddr;
    uint64_t vmsize;
    vm_prot_t maxprot;
    vm_prot_t initprot;
    uint32_t flags;
} all_segment[] = {
    { 1, "__PAGEZERO",       0, ప్రారంభం_3, 0, 0,            0 },
    { 0, "__TEXT",       ప్రారంభం_3,     0, 5, 5,            0 },
    { 0, "__DATA_CONST",    -1,     0, 3, 3, SG_READ_ONLY },
    { 0, "__DWARF",         -1,     0, 7, 3,            0 },
    { 0, "__DATA",          -1,     0, 3, 3,            0 },
    { 1, "__LINKEDIT",      -1,     0, 1, 1,            0 },
};

#నిర్వచించు	N_SEGMENT	(పరిమాణం(all_segment)/పరిమాణం(all_segment[0]))

#నిర్వచితమైతే CONFIG_NEW_MACHO
స్థిర శూన్య calc_fixup_కొలత(TCCState *s1, నిర్మాణం macho *mo)
{
    పూర్ణాంకం i, కొలత;

    కొలత = (పరిమాణం(నిర్మాణం dyld_chained_fixups_శీర్షిక) + 7) & -8;
    కొలత += (పరిమాణం(నిర్మాణం dyld_chained_starts_లోపల_image) + (mo->nseg - 1) * పరిమాణం(uint32_t) + 7) & -8;
    కొరకు (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	పూర్ణాంకం పుట_లెక్క = (get_segment(mo, i)->vmsize + SEG_పుట_కొలత - 1) / SEG_పుట_కొలత;
	కొలత += (పరిమాణం(నిర్మాణం dyld_chained_starts_లోపల_segment) + (పుట_లెక్క - 1) * పరిమాణం(uint16_t) + 7) & -8;
    }
    కొలత += mo->n_bind * పరిమాణం (నిర్మాణం dyld_chained_import) + 1;
    కొరకు (i = 0; i < mo->n_bind_rebase; i++) {
	ఒకవేళ (mo->bind_rebase[i].bind) {
	    పూర్ణాంకం sym_సూచీ = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
	    స్థిరరాశి అక్షరం *name = (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name;
	    కొలత += అక్షరశ్రేణి_పొడవు(name) + 1;
	}
    }
    కొలత = (కొలత + 7) & -8;
    section_ptr_కూడు(mo->chained_fixups, కొలత);
}

#లేకపోతే

స్థిర శూన్య సమితి_segment_and_స్థానభ్రంశం(TCCState *s1, నిర్మాణం macho *mo, addr_t addr,
				   uint8_t *ptr, పూర్ణాంకం opcode,
				   Section *sec, addr_t స్థానభ్రంశం)
{
    పూర్ణాంకం i;
    నిర్మాణం segment_command_64 *seg = ఖాళీ;

    కొరకు (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	seg = get_segment(mo, i);
	ఒకవేళ (addr >= seg->vmaddr && addr < (seg->vmaddr + seg->vmsize))
	    ఆపు;
    }
    *ptr = opcode | i;
    write_uleb128(sec, స్థానభ్రంశం - seg->vmaddr);
}

స్థిర శూన్య bind_rebase(TCCState *s1, నిర్మాణం macho *mo)
{
    పూర్ణాంకం i;
    uint8_t *ptr;
    ElfW(Sym) *sym;
    స్థిరరాశి అక్షరం *name;

    కొరకు (i = 0; i < mo->n_lazy_bind; i++) {
	పూర్ణాంకం sym_సూచీ = ELFW(R_SYM)(mo->s_lazy_bind[i].rel.r_info);

	sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
	name = (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name;
	write32le(mo->stub_helper->దత్తాంశం +
		  mo->s_lazy_bind[i].bind_స్థానభ్రంశం,
		  mo->lazy_binding->దత్తాంశం_స్థానభ్రంశం);
	ptr = section_ptr_కూడు(mo->lazy_binding, 1);
	సమితి_segment_and_స్థానభ్రంశం(s1, mo, mo->la_చిహ్నం_ptr->sh_addr, ptr,
			       BIND_OPCODE_సమితి_SEGMENT_AND_స్థానభ్రంశం_ULEB,
			       mo->lazy_binding,
			       mo->s_lazy_bind[i].la_చిహ్నం_స్థానభ్రంశం +
			       mo->la_చిహ్నం_ptr->sh_addr);
	ptr = section_ptr_కూడు(mo->lazy_binding, 5 + అక్షరశ్రేణి_పొడవు(name));
	*ptr++ = BIND_OPCODE_సమితి_DYLIB_SPECIAL_IMM |
		 (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
	*ptr++ = BIND_OPCODE_సమితి_చిహ్నం_TRAILING_FLAGS_IMM | 0;
	strcpy((అక్షరం *)ptr, name);
	ptr += అక్షరశ్రేణి_పొడవు(name) + 1;
	*ptr++ = BIND_OPCODE_DO_BIND;
	*ptr = BIND_OPCODE_పూర్తి;
    }
    కొరకు (i = 0; i < mo->n_rebase; i++) {
	Section *s = s1->sections[mo->s_rebase[i].section];

	ptr = section_ptr_కూడు(mo->rebase, 2);
	*ptr++ = REBASE_OPCODE_సమితి_TYPE_IMM | REBASE_TYPE_సూచిక;
	సమితి_segment_and_స్థానభ్రంశం(s1, mo, s->sh_addr, ptr,
			       REBASE_OPCODE_సమితి_SEGMENT_AND_స్థానభ్రంశం_ULEB,
			       mo->rebase,
			       mo->s_rebase[i].rel.r_స్థానభ్రంశం +
			       s->sh_addr);
	ptr = section_ptr_కూడు(mo->rebase, 1);
	*ptr = REBASE_OPCODE_DO_REBASE_IMM_TIMES | 1;
    }
    కొరకు (i = 0; i < mo->n_bind; i++) {
	పూర్ణాంకం sym_సూచీ = ELFW(R_SYM)(mo->bind[i].rel.r_info);
	Section *s = s1->sections[mo->bind[i].section];
	Section *binding;

	sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
	name = (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name;
	binding = ELFW(ST_BIND)(sym->st_info) == STB_WEAK
	    ? mo->weak_binding : mo->binding;
        ptr = section_ptr_కూడు(binding, 4 + (binding == mo->binding) +
			     	       అక్షరశ్రేణి_పొడవు(name));
	ఒకవేళ (binding == mo->binding)
            *ptr++ = BIND_OPCODE_సమితి_DYLIB_SPECIAL_IMM |
	             (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
        *ptr++ = BIND_OPCODE_సమితి_చిహ్నం_TRAILING_FLAGS_IMM |
		 (binding == mo->weak_binding
		  ? BIND_చిహ్నం_FLAGS_WEAK_IMPORT : 0);
        strcpy((అక్షరం *)ptr, name);
        ptr += అక్షరశ్రేణి_పొడవు(name) + 1;
        *ptr++ = BIND_OPCODE_సమితి_TYPE_IMM | BIND_TYPE_సూచిక;
	సమితి_segment_and_స్థానభ్రంశం(s1, mo, s->sh_addr, ptr,
			       BIND_OPCODE_సమితి_SEGMENT_AND_స్థానభ్రంశం_ULEB,
			       binding,
			       mo->bind[i].rel.r_స్థానభ్రంశం + s->sh_addr);
        ptr = section_ptr_కూడు(binding, 1);
        *ptr++ = BIND_OPCODE_DO_BIND;
    }
    ఒకవేళ (mo->rebase->దత్తాంశం_స్థానభ్రంశం) {
        ptr = section_ptr_కూడు(mo->rebase, 1);
        *ptr = REBASE_OPCODE_పూర్తి;
    }
    ఒకవేళ (mo->binding->దత్తాంశం_స్థానభ్రంశం) {
        ptr = section_ptr_కూడు(mo->binding, 1);
        *ptr = BIND_OPCODE_పూర్తి;
    }
    ఒకవేళ (mo->weak_binding->దత్తాంశం_స్థానభ్రంశం) {
        ptr = section_ptr_కూడు(mo->weak_binding, 1);
        *ptr = BIND_OPCODE_పూర్తి;
    }
    tcc_free(mo->s_lazy_bind);
    tcc_free(mo->s_rebase);
    tcc_free(mo->bind);
}
#అయితే_ముగింపు

నిర్మాణం trie_info {
    స్థిరరాశి అక్షరం *name;
    పూర్ణాంకం flag;
    addr_t addr;
    పూర్ణాంకం str_కొలత;
    పూర్ణాంకం పదం_కొలత;
};

నిర్మాణం trie_కణుపు {
    పూర్ణాంకం ప్రారంభం;
    పూర్ణాంకం చివర;
    పూర్ణాంకం సూచీ_ప్రారంభం;
    పూర్ణాంకం సూచీ_చివర;
    పూర్ణాంకం n_బిడ్డ;
    నిర్మాణం trie_కణుపు *బిడ్డ;
};

నిర్మాణం trie_seq {
    పూర్ణాంకం n_బిడ్డ;
    నిర్మాణం trie_కణుపు *కణుపు;
    పూర్ణాంకం స్థానభ్రంశం;
    పూర్ణాంకం nest_స్థానభ్రంశం;
};

స్థిర శూన్య create_trie(నిర్మాణం trie_కణుపు *కణుపు,
                        పూర్ణాంకం from, పూర్ణాంకం గమ్యం, పూర్ణాంకం సూచీ_ప్రారంభం,
                        పూర్ణాంకం n_trie, నిర్మాణం trie_info *trie)
{
    పూర్ణాంకం i;
    పూర్ణాంకం ప్రారంభం, చివర, సూచీ_చివర;
    అక్షరం cur;
    నిర్మాణం trie_కణుపు *బిడ్డ;

    కొరకు (i = from; i < గమ్యం; i = చివర) {
        cur = trie[i].name[సూచీ_ప్రారంభం];
        ప్రారంభం = i++;
        కొరకు (; i < గమ్యం; i++)
            ఒకవేళ (cur != trie[i].name[సూచీ_ప్రారంభం])
                ఆపు;
        చివర = i;
        ఒకవేళ (ప్రారంభం == చివర - 1 ||
            (trie[ప్రారంభం].name[సూచీ_ప్రారంభం] &&
             trie[ప్రారంభం].name[సూచీ_ప్రారంభం + 1] == 0))
            సూచీ_చివర = trie[ప్రారంభం].str_కొలత - 1;
        లేకపోతే {
            సూచీ_చివర = సూచీ_ప్రారంభం + 1;
            కొరకు (;;) {
                cur = trie[ప్రారంభం].name[సూచీ_చివర];
                కొరకు (i = ప్రారంభం + 1; i < చివర; i++)
                    ఒకవేళ (cur != trie[i].name[సూచీ_చివర])
                        ఆపు;
                ఒకవేళ (trie[ప్రారంభం].name[సూచీ_చివర] &&
                    trie[ప్రారంభం].name[సూచీ_చివర + 1] == 0) {
                    చివర = ప్రారంభం + 1;
                    సూచీ_చివర = trie[ప్రారంభం].str_కొలత - 1;
                    ఆపు;
                }
                ఒకవేళ (i != చివర)
                    ఆపు;
                సూచీ_చివర++;
            }
        }
        కణుపు->బిడ్డ = tcc_realloc(కణుపు->బిడ్డ,
                                  (కణుపు->n_బిడ్డ + 1) *
                                  పరిమాణం(నిర్మాణం trie_కణుపు));
        బిడ్డ = &కణుపు->బిడ్డ[కణుపు->n_బిడ్డ];
        బిడ్డ->ప్రారంభం = ప్రారంభం;
        బిడ్డ->చివర = చివర;
        బిడ్డ->సూచీ_ప్రారంభం = సూచీ_ప్రారంభం;
        బిడ్డ->సూచీ_చివర = సూచీ_చివర;
        బిడ్డ->n_బిడ్డ = 0;
        బిడ్డ->బిడ్డ = ఖాళీ;
        కణుపు->n_బిడ్డ++;
        ఒకవేళ (ప్రారంభం != చివర - 1)
            create_trie(బిడ్డ, ప్రారంభం, చివర, సూచీ_చివర, n_trie, trie);
    }
}

స్థిర పూర్ణాంకం create_seq(పూర్ణాంకం *స్థానభ్రంశం, పూర్ణాంకం *n_seq, నిర్మాణం trie_seq **seq,
                        నిర్మాణం trie_కణుపు *కణుపు,
                        పూర్ణాంకం n_trie, నిర్మాణం trie_info *trie)
{
    పూర్ణాంకం i, nest_స్థానభ్రంశం, చివరి_seq = *n_seq, retval = *స్థానభ్రంశం;
    నిర్మాణం trie_seq *p_seq;
    నిర్మాణం trie_కణుపు *p_nest;

    కొరకు (i = 0; i < కణుపు->n_బిడ్డ; i++) {
        p_nest = &కణుపు->బిడ్డ[i];
        *seq = tcc_realloc(*seq, (*n_seq + 1) * పరిమాణం(నిర్మాణం trie_seq));
        p_seq = &(*seq)[(*n_seq)++];
        p_seq->n_బిడ్డ = i == 0 ? కణుపు->n_బిడ్డ : -1;
        p_seq->కణుపు = p_nest;
        p_seq->స్థానభ్రంశం = *స్థానభ్రంశం;
        p_seq->nest_స్థానభ్రంశం = 0;
        *స్థానభ్రంశం += (i == 0 ? 1 + 1 : 0) +
                   p_nest->సూచీ_చివర - p_nest->సూచీ_ప్రారంభం + 1 + 3;
    }
    కొరకు (i = 0; i < కణుపు->n_బిడ్డ; i++) {
        nest_స్థానభ్రంశం =
            create_seq(స్థానభ్రంశం, n_seq, seq, &కణుపు->బిడ్డ[i], n_trie, trie);
        p_seq = &(*seq)[చివరి_seq + i];
        p_seq->nest_స్థానభ్రంశం = nest_స్థానభ్రంశం;
    }
    తిరిగి retval;
}

స్థిర శూన్య కణుపు_free(నిర్మాణం trie_కణుపు *కణుపు)
{
    పూర్ణాంకం i;

    కొరకు (i = 0; i < కణుపు->n_బిడ్డ; i++)
	కణుపు_free(&కణుపు->బిడ్డ[i]);
    tcc_free(కణుపు->బిడ్డ);
}

స్థిర పూర్ణాంకం triecmp(స్థిరరాశి శూన్య *_a, స్థిరరాశి శూన్య *_b, శూన్య *arg)
{
    నిర్మాణం trie_info *a = (నిర్మాణం trie_info *) _a;
    నిర్మాణం trie_info *b = (నిర్మాణం trie_info *) _b;
    పూర్ణాంకం len_a = అక్షరశ్రేణి_పొడవు(a->name);
    పూర్ణాంకం len_b = అక్షరశ్రేణి_పొడవు(b->name);

    /* strange sorting needed. Name 'xx' should be after 'xx1' */
    ఒకవేళ (!అక్షరశ్రేణి_పోలిక(a->name, b->name, len_a < len_b ? len_a : len_b))
	తిరిగి len_a < len_b ? 1 : (len_a > len_b ? -1 : 0);
    తిరిగి strcmp(a->name, b->name);
}

స్థిర శూన్య export_trie(TCCState *s1, నిర్మాణం macho *mo)
{
    పూర్ణాంకం i, కొలత, స్థానభ్రంశం = 0, save_స్థానభ్రంశం;
    uint8_t *ptr;
    పూర్ణాంకం sym_సూచీ;
    పూర్ణాంకం sym_చివర = symtab_section->దత్తాంశం_స్థానభ్రంశం / పరిమాణం(ElfW(Sym));
    పూర్ణాంకం n_trie = 0, n_seq = 0;
    నిర్మాణం trie_info *trie = ఖాళీ, *p_trie;
    నిర్మాణం trie_కణుపు కణుపు, *p_కణుపు;
    నిర్మాణం trie_seq *seq = ఖాళీ;
    addr_t vm_addr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;

    కొరకు (sym_సూచీ = 1; sym_సూచీ < sym_చివర; ++sym_సూచీ) {
	ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->దత్తాంశం + sym_సూచీ;
	స్థిరరాశి అక్షరం *name = (అక్షరం*)symtab_section->link->దత్తాంశం + sym->st_name;

	ఒకవేళ (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE &&
            (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL ||
	     ELFW(ST_BIND)(sym->st_info) == STB_WEAK)) {
	    పూర్ణాంకం flag = EXPORT_చిహ్నం_FLAGS_రకం_REGULAR;
	    addr_t addr =
		sym->st_విలువ + s1->sections[sym->st_shndx]->sh_addr - vm_addr;

	    ఒకవేళ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
		flag |= EXPORT_చిహ్నం_FLAGS_WEAK_DEFINITION;
	    dprintf ("%s %d %llx\n", name, flag, (దీర్ఘ దీర్ఘ)addr + vm_addr);
	    trie = tcc_realloc(trie, (n_trie + 1) * పరిమాణం(నిర్మాణం trie_info));
	    trie[n_trie].name = name;
	    trie[n_trie].flag = flag;
	    trie[n_trie].addr = addr;
	    trie[n_trie].str_కొలత = అక్షరశ్రేణి_పొడవు(name) + 1;
	    trie[n_trie].పదం_కొలత = uleb128_కొలత(flag) + uleb128_కొలత(addr);
	    n_trie++;
	}
    }
    ఒకవేళ (n_trie) {
        tcc_qsort(trie, n_trie, పరిమాణం(నిర్మాణం trie_info), triecmp, ఖాళీ);
	memset(&కణుపు, 0, పరిమాణం(కణుపు));
        create_trie(&కణుపు, 0, n_trie, 0, n_trie, trie);
	create_seq(&స్థానభ్రంశం, &n_seq, &seq, &కణుపు, n_trie, trie);
        save_స్థానభ్రంశం = స్థానభ్రంశం;
        కొరకు (i = 0; i < n_seq; i++) {
            p_కణుపు = seq[i].కణుపు;
            ఒకవేళ (p_కణుపు->n_బిడ్డ == 0) {
                p_trie = &trie[p_కణుపు->ప్రారంభం];
                seq[i].nest_స్థానభ్రంశం = స్థానభ్రంశం;
                స్థానభ్రంశం += 1 + p_trie->పదం_కొలత + 1;
            }
        }
        కొరకు (i = 0; i < n_seq; i++) {
            p_కణుపు = seq[i].కణుపు;
            p_trie = &trie[p_కణుపు->ప్రారంభం];
            ఒకవేళ (seq[i].n_బిడ్డ >= 0) {
                section_ptr_కూడు(mo->exports,
				seq[i].స్థానభ్రంశం - mo->exports->దత్తాంశం_స్థానభ్రంశం);
                ptr = section_ptr_కూడు(mo->exports, 2);
                *ptr++ = 0;
                *ptr = seq[i].n_బిడ్డ;
            }
            కొలత = p_కణుపు->సూచీ_చివర - p_కణుపు->సూచీ_ప్రారంభం;
            ptr = section_ptr_కూడు(mo->exports, కొలత + 1);
            జ్ఞాపకం_నకలు(ptr, &p_trie->name[p_కణుపు->సూచీ_ప్రారంభం], కొలత);
            ptr[కొలత] = 0;
            write_uleb128(mo->exports, seq[i].nest_స్థానభ్రంశం);
        }
        section_ptr_కూడు(mo->exports, save_స్థానభ్రంశం - mo->exports->దత్తాంశం_స్థానభ్రంశం);
        కొరకు (i = 0; i < n_seq; i++) {
            p_కణుపు = seq[i].కణుపు;
            ఒకవేళ (p_కణుపు->n_బిడ్డ == 0) {
                p_trie = &trie[p_కణుపు->ప్రారంభం];
                write_uleb128(mo->exports, p_trie->పదం_కొలత);
                write_uleb128(mo->exports, p_trie->flag);
                write_uleb128(mo->exports, p_trie->addr);
                ptr = section_ptr_కూడు(mo->exports, 1);
                *ptr = 0;
            }
        }
        section_ptr_కూడు(mo->exports, -mo->exports->దత్తాంశం_స్థానభ్రంశం & 7);
	కణుపు_free(&కణుపు);
        tcc_free(seq);
    }
    tcc_free(trie);
}

స్థిర శూన్య collect_sections(TCCState *s1, నిర్మాణం macho *mo, స్థిరరాశి అక్షరం *filename)
{
    పూర్ణాంకం i, sk, numsec;
    పూర్ణాంకం వాడిన_segment[N_SEGMENT];
    uint64_t curaddr, fileofs;
    Section *s;
    నిర్మాణం segment_command_64 *seg;
    నిర్మాణం dylib_command *dylib;
#నిర్వచితమైతే CONFIG_NEW_MACHO
    నిర్మాణం linkedit_దత్తాంశం_command *chained_fixups_lc;
    నిర్మాణం linkedit_దత్తాంశం_command *export_trie_lc;
#అయితే_ముగింపు
    నిర్మాణం build_సంస్కరణ_command *dyldbv;
    నిర్మాణం ఆధారం_సంస్కరణ_command *dyldsv;
    నిర్మాణం rpath_command *rpath;
    నిర్మాణం dylinker_command *dyldlc;
    నిర్మాణం symtab_command *symlc;
    నిర్మాణం dysymtab_command *dysymlc;
    అక్షరం *str;

    కొరకు (i = 0; i < N_SEGMENT; i++)
	వాడిన_segment[i] = all_segment[i].వాడిన;

    memset (mo->sk_గమ్యం_sect, 0, పరిమాణం(mo->sk_గమ్యం_sect));
    కొరకు (i = s1->nb_sections; i-- > 1;) {
        పూర్ణాంకం type, flags;
        s = s1->sections[i];
        type = s->sh_type;
        flags = s->sh_flags;
        sk = sk_unknown;
	/* debug sections have sometimes no SHF_ALLOC */
        ఒకవేళ ((flags & SHF_ALLOC) || !అక్షరశ్రేణి_పోలిక(s->name, ".debug_", 7)) {
            ఎంపిక (type) {
            అప్రమేయ:           sk = sk_unknown; ఆపు;
            స్థితి SHT_INIT_ARRAY: sk = sk_init; ఆపు;
            స్థితి SHT_FINI_ARRAY: sk = sk_fini; ఆపు;
            స్థితి SHT_NOBITS:   sk = sk_bss; ఆపు;
            స్థితి SHT_SYMTAB:   sk = sk_discard; ఆపు;
            స్థితి SHT_STRTAB:
		ఒకవేళ (s == stabstr_section)
		  sk = sk_stab_str;
		లేకపోతే
		  sk = sk_discard;
		ఆపు;
            స్థితి SHT_RELX:     sk = sk_discard; ఆపు;
            స్థితి SHT_LINKEDIT: sk = sk_linkedit; ఆపు;
            స్థితి SHT_PROGBITS:
                ఒకవేళ (s == mo->stubs)
                  sk = sk_stubs;
#నిర్వచితం_కాకపోతే CONFIG_NEW_MACHO
                లేకపోతే ఒకవేళ (s == mo->stub_helper)
                  sk = sk_stub_helper;
                లేకపోతే ఒకవేళ (s == mo->la_చిహ్నం_ptr)
                  sk = sk_la_ptr;
#అయితే_ముగింపు
                లేకపోతే ఒకవేళ (s == rodata_section)
                  sk = sk_ro_దత్తాంశం;
                లేకపోతే ఒకవేళ (s == s1->got)
                  sk = sk_nl_ptr;
                లేకపోతే ఒకవేళ (s == stab_section)
                  sk = sk_stab;
                లేకపోతే ఒకవేళ (s == dwarf_info_section)
                  sk = sk_debug_info;
                లేకపోతే ఒకవేళ (s == dwarf_abbrev_section)
                  sk = sk_debug_abbrev;
                లేకపోతే ఒకవేళ (s == dwarf_పంక్తి_section)
                  sk = sk_debug_పంక్తి;
                లేకపోతే ఒకవేళ (s == dwarf_aranges_section)
                  sk = sk_debug_aranges;
                లేకపోతే ఒకవేళ (s == dwarf_str_section)
                  sk = sk_debug_str;
                లేకపోతే ఒకవేళ (s == dwarf_పంక్తి_str_section)
                  sk = sk_debug_పంక్తి_str;
                లేకపోతే ఒకవేళ (flags & SHF_EXECINSTR)
                  sk = sk_పాఠ్యం;
                లేకపోతే ఒకవేళ (flags & SHF_WRITE)
                  sk = sk_rw_దత్తాంశం;
                లేకపోతే
                  sk = sk_ro_దత్తాంశం;
                ఆపు;
            }
        } లేకపోతే
          sk = sk_discard;
        s->prev = mo->sk_గమ్యం_sect[sk].s;
        mo->sk_గమ్యం_sect[sk].s = s;
	వాడిన_segment[skinfo[sk].seg_initial] = 1;
    }

    ఒకవేళ (s1->output_type != TCC_OUTPUT_EXE)
	వాడిన_segment[0] = 0;

    కొరకు (i = 0; i < N_SEGMENT; i++)
	ఒకవేళ (వాడిన_segment[i]) {
	    seg = కూడు_segment(mo, all_segment[i].name);
	    ఒకవేళ (i == 1 && s1->output_type != TCC_OUTPUT_EXE)
	        seg->vmaddr = 0;
	    లేకపోతే
	        seg->vmaddr = all_segment[i].vmaddr;
	    seg->vmsize = all_segment[i].vmsize;
	    seg->maxprot = all_segment[i].maxprot;
	    seg->initprot = all_segment[i].initprot;
	    seg->flags = all_segment[i].flags;
            కొరకు (sk = sk_unknown; sk < sk_చివరి; sk++)
		ఒకవేళ (skinfo[sk].seg_initial == i)
	            mo->segment[sk] = mo->nseg - 1;
	}

    ఒకవేళ (s1->output_type != TCC_OUTPUT_EXE) {
	స్థిరరాశి అక్షరం *name = s1->install_name ? s1->install_name : filename;
        i = (పరిమాణం(*dylib) + అక్షరశ్రేణి_పొడవు(name) + 1 + 7) &-8;
        dylib = కూడు_lc(mo, LC_ID_DYLIB, i);
	dylib->name = పరిమాణం(*dylib);
	dylib->timestamp = 1;
	dylib->current_సంస్కరణ =
	    s1->current_సంస్కరణ ? s1->current_సంస్కరణ : 1 << 16;
	dylib->compatibility_సంస్కరణ =
	    s1->compatibility_సంస్కరణ ? s1->compatibility_సంస్కరణ : 1 << 16;
        str = (అక్షరం*)dylib + dylib->name;
        strcpy(str, name);
    }

#నిర్వచితమైతే CONFIG_NEW_MACHO
    chained_fixups_lc = కూడు_lc(mo, LC_DYLD_CHAINED_FIXUPS,
			       పరిమాణం(నిర్మాణం linkedit_దత్తాంశం_command));
    export_trie_lc = కూడు_lc(mo, LC_DYLD_EXPORTS_TRIE,
			    పరిమాణం(నిర్మాణం linkedit_దత్తాంశం_command));
#లేకపోతే
    mo->dyldinfo = కూడు_lc(mo, LC_DYLD_INFO_ONLY, పరిమాణం(*mo->dyldinfo));
#అయితే_ముగింపు

    symlc = కూడు_lc(mo, LC_SYMTAB, పరిమాణం(*symlc));
    dysymlc = కూడు_lc(mo, LC_DYSYMTAB, పరిమాణం(*dysymlc));

    ఒకవేళ (s1->output_type == TCC_OUTPUT_EXE) {
        i = (పరిమాణం(*dyldlc) + అక్షరశ్రేణి_పొడవు("/usr/lib/dyld") + 1 + 7) &-8;
        dyldlc = కూడు_lc(mo, LC_ఎక్కించు_DYLINKER, i);
        dyldlc->name = పరిమాణం(*dyldlc);
        str = (అక్షరం*)dyldlc + dyldlc->name;
        strcpy(str, "/usr/lib/dyld");
    }

    dyldbv = కూడు_lc(mo, LC_BUILD_సంస్కరణ, పరిమాణం(*dyldbv));
    dyldbv->platform = PLATFORM_MACOS;
    dyldbv->minos = (10 << 16) + (6 << 8);
    dyldbv->sdk = (10 << 16) + (6 << 8);
    dyldbv->ntools = 0;

    dyldsv = కూడు_lc(mo, LC_ఆధారం_సంస్కరణ, పరిమాణం(*dyldsv));
    dyldsv->సంస్కరణ = 0;

    ఒకవేళ (s1->output_type == TCC_OUTPUT_EXE) {
        mo->ep = కూడు_lc(mo, LC_MAIN, పరిమాణం(*mo->ep));
        mo->ep->entryoff = 4096;
    }

    కొరకు(i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *dllref = s1->loaded_dlls[i];
        ఒకవేళ (dllref->level == 0)
          కూడు_dylib(mo, dllref->name);
    }

    ఒకవేళ (s1->rpath) {
	అక్షరం *మార్గం = s1->rpath, *చివర;
	చేయి {
	    చివర = strchr(మార్గం, ':');
	    ఒకవేళ (!చివర)
		చివర = strchr(మార్గం, 0);
            i = (పరిమాణం(*rpath) + (చివర - మార్గం) + 1 + 7) &-8;
            rpath = కూడు_lc(mo, LC_RPATH, i);
            rpath->మార్గం = పరిమాణం(*rpath);
            str = (అక్షరం*)rpath + rpath->మార్గం;
            జ్ఞాపకం_నకలు(str, మార్గం, చివర - మార్గం);
	    str[చివర - మార్గం] = 0;
	    మార్గం = చివర + 1;
	} అయితే (*చివర);
    }

    fileofs = 4096;  /* leave space for mach-o headers */
    curaddr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;
    curaddr += 4096;
    seg = ఖాళీ;
    numsec = 0;
    mo->elfsectomacho = tcc_mallocz(పరిమాణం(*mo->elfsectomacho) * s1->nb_sections);
    కొరకు (sk = sk_unknown; sk < sk_చివరి; sk++) {
        నిర్మాణం section_64 *sec = ఖాళీ;
        ఒకవేళ (seg) {
            seg->vmsize = curaddr - seg->vmaddr;
            seg->filesize = fileofs - seg->fileoff;
        }
#నిర్వచితమైతే CONFIG_NEW_MACHO
	ఒకవేళ (sk == sk_linkedit) {
	    calc_fixup_కొలత(s1, mo);
	    export_trie(s1, mo);
	}
#లేకపోతే
	ఒకవేళ (sk == sk_linkedit) {
	    bind_rebase(s1, mo);
	    export_trie(s1, mo);
	}
#అయితే_ముగింపు
        ఒకవేళ (skinfo[sk].seg_initial &&
	    (s1->output_type != TCC_OUTPUT_EXE || mo->segment[sk]) &&
	    mo->sk_గమ్యం_sect[sk].s) {
            uint64_t al = 0;
            పూర్ణాంకం si;
            seg = get_segment(mo, mo->segment[sk]);
            ఒకవేళ (skinfo[sk].name) {
                si = కూడు_section(mo, &seg, skinfo[sk].name);
                numsec++;
                mo->lc[mo->seg2lc[mo->segment[sk]]] = (నిర్మాణం ఎక్కించు_command*)seg;
                mo->sk_గమ్యం_sect[sk].machosect = si;
                sec = get_section(seg, si);
                sec->flags = skinfo[sk].flags;
		ఒకవేళ (sk == sk_stubs)
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
	    	    sec->reserved2 = 6;
#లేదావేళ defined TCC_లక్ష్యం_ARM64
	    	    sec->reserved2 = 12;
#అయితే_ముగింపు
		ఒకవేళ (sk == sk_nl_ptr)
	    	    sec->reserved1 = mo->nr_plt;
#నిర్వచితం_కాకపోతే CONFIG_NEW_MACHO
		ఒకవేళ (sk == sk_la_ptr)
	    	    sec->reserved1 = mo->nr_plt + mo->n_got;
#అయితే_ముగింపు
            }
            ఒకవేళ (seg->vmaddr == -1) {
                curaddr = (curaddr + SEG_పుట_కొలత - 1) & -SEG_పుట_కొలత;
                seg->vmaddr = curaddr;
                fileofs = (fileofs + SEG_పుట_కొలత - 1) & -SEG_పుట_కొలత;
                seg->fileoff = fileofs;
            }

            కొరకు (s = mo->sk_గమ్యం_sect[sk].s; s; s = s->prev) {
                పూర్ణాంకం a = exact_log2p1(s->sh_addralign);
                ఒకవేళ (a && al < (a - 1))
                  al = a - 1;
                s->sh_కొలత = s->దత్తాంశం_స్థానభ్రంశం;
            }
            ఒకవేళ (sec)
              sec->align = al;
            al = 1ULL << al;
            ఒకవేళ (al > 4096)
              tcc_warning("alignment > 4096"), sec->align = 12, al = 4096;
            curaddr = (curaddr + al - 1) & -al;
            fileofs = (fileofs + al - 1) & -al;
            ఒకవేళ (sec) {
                sec->addr = curaddr;
                sec->స్థానభ్రంశం = fileofs;
            }
            కొరకు (s = mo->sk_గమ్యం_sect[sk].s; s; s = s->prev) {
                al = s->sh_addralign;
                curaddr = (curaddr + al - 1) & -al;
                dprintf("%s: curaddr now 0x%lx\n", s->name, (దీర్ఘ)curaddr);
                s->sh_addr = curaddr;
                curaddr += s->sh_కొలత;
                ఒకవేళ (s->sh_type != SHT_NOBITS) {
                    fileofs = (fileofs + al - 1) & -al;
                    s->sh_స్థానభ్రంశం = fileofs;
                    fileofs += s->sh_కొలత;
                    dprintf("%s: fileofs now %ld\n", s->name, (దీర్ఘ)fileofs);
                }
                ఒకవేళ (sec)
                  mo->elfsectomacho[s->sh_అంకె] = numsec;
            }
            ఒకవేళ (sec)
              sec->కొలత = curaddr - sec->addr;
        }
        ఒకవేళ (DEBUG_MACHO)
          కొరకు (s = mo->sk_గమ్యం_sect[sk].s; s; s = s->prev) {
              పూర్ణాంకం type = s->sh_type;
              పూర్ణాంకం flags = s->sh_flags;
              రాయి("%d section %-16s %-10s %09lx %04x %02d %s,%s,%s\n",
                     sk,
                     s->name,
                     type == SHT_PROGBITS ? "progbits" :
                     type == SHT_NOBITS ? "nobits" :
                     type == SHT_SYMTAB ? "symtab" :
                     type == SHT_STRTAB ? "strtab" :
                     type == SHT_INIT_ARRAY ? "init" :
                     type == SHT_FINI_ARRAY ? "fini" :
                     type == SHT_RELX ? "rel" : "???",
                     (దీర్ఘ)s->sh_addr,
                     (గుర్తులేని)s->దత్తాంశం_స్థానభ్రంశం,
                     s->sh_addralign,
                     flags & SHF_ALLOC ? "alloc" : "",
                     flags & SHF_WRITE ? "write" : "",
                     flags & SHF_EXECINSTR ? "exec" : ""
                    );
          }
    }
    ఒకవేళ (seg) {
        seg->vmsize = curaddr - seg->vmaddr;
        seg->filesize = fileofs - seg->fileoff;
    }

    /* Fill symtab info */
    symlc->symoff = mo->symtab->sh_స్థానభ్రంశం;
    symlc->nsyms = mo->symtab->దత్తాంశం_స్థానభ్రంశం / పరిమాణం(నిర్మాణం nlist_64);
    symlc->stroff = mo->strtab->sh_స్థానభ్రంశం;
    symlc->strsize = mo->strtab->దత్తాంశం_స్థానభ్రంశం;

    dysymlc->iundefsym = mo->iundef == -1 ? symlc->nsyms : mo->iundef;
    dysymlc->iextdefsym = mo->iextdef == -1 ? dysymlc->iundefsym : mo->iextdef;
    dysymlc->ilocalsym = mo->ilocal == -1 ? dysymlc->iextdefsym : mo->ilocal;
    dysymlc->nlocalsym = dysymlc->iextdefsym - dysymlc->ilocalsym;
    dysymlc->nextdefsym = dysymlc->iundefsym - dysymlc->iextdefsym;
    dysymlc->nundefsym = symlc->nsyms - dysymlc->iundefsym;
    dysymlc->indirectsymoff = mo->indirsyms->sh_స్థానభ్రంశం;
    dysymlc->nindirectsyms = mo->indirsyms->దత్తాంశం_స్థానభ్రంశం / పరిమాణం(uint32_t);

#నిర్వచితమైతే CONFIG_NEW_MACHO
    ఒకవేళ (mo->chained_fixups->దత్తాంశం_స్థానభ్రంశం) {
        chained_fixups_lc->dataoff = mo->chained_fixups->sh_స్థానభ్రంశం;
        chained_fixups_lc->datasize = mo->chained_fixups->దత్తాంశం_స్థానభ్రంశం;
    }
    ఒకవేళ (mo->exports->దత్తాంశం_స్థానభ్రంశం) {
        export_trie_lc->dataoff = mo->exports->sh_స్థానభ్రంశం;
        export_trie_lc->datasize = mo->exports->దత్తాంశం_స్థానభ్రంశం;
    }
#లేకపోతే
    ఒకవేళ (mo->rebase->దత్తాంశం_స్థానభ్రంశం) {
        mo->dyldinfo->rebase_off = mo->rebase->sh_స్థానభ్రంశం;
        mo->dyldinfo->rebase_కొలత = mo->rebase->దత్తాంశం_స్థానభ్రంశం;
    }
    ఒకవేళ (mo->binding->దత్తాంశం_స్థానభ్రంశం) {
        mo->dyldinfo->bind_off = mo->binding->sh_స్థానభ్రంశం;
        mo->dyldinfo->bind_కొలత = mo->binding->దత్తాంశం_స్థానభ్రంశం;
    }
    ఒకవేళ (mo->weak_binding->దత్తాంశం_స్థానభ్రంశం) {
        mo->dyldinfo->weak_bind_off = mo->weak_binding->sh_స్థానభ్రంశం;
        mo->dyldinfo->weak_bind_కొలత = mo->weak_binding->దత్తాంశం_స్థానభ్రంశం;
    }
    ఒకవేళ (mo->lazy_binding->దత్తాంశం_స్థానభ్రంశం) {
        mo->dyldinfo->lazy_bind_off = mo->lazy_binding->sh_స్థానభ్రంశం;
        mo->dyldinfo->lazy_bind_కొలత = mo->lazy_binding->దత్తాంశం_స్థానభ్రంశం;
    }
    ఒకవేళ (mo->exports->దత్తాంశం_స్థానభ్రంశం) {
        mo->dyldinfo->export_off = mo->exports->sh_స్థానభ్రంశం;
        mo->dyldinfo->export_కొలత = mo->exports->దత్తాంశం_స్థానభ్రంశం;
    }
#అయితే_ముగింపు
}

స్థిర శూన్య macho_write(TCCState *s1, నిర్మాణం macho *mo, FILE *fp)
{
    పూర్ణాంకం i, sk;
    uint64_t fileofs = 0;
    Section *s;
    mo->mh.mh.magic = MH_MAGIC_64;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    mo->mh.mh.cputype = CPU_TYPE_X86_64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_LIB64 | CPU_SUBTYPE_X86_ALL;
#లేదావేళ defined TCC_లక్ష్యం_ARM64
    mo->mh.mh.cputype = CPU_TYPE_ARM64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_ARM64_ALL;
#అయితే_ముగింపు
    ఒకవేళ (s1->output_type == TCC_OUTPUT_EXE) {
        mo->mh.mh.filetype = MH_EXECUTE;
        mo->mh.mh.flags = MH_DYLDLINK | MH_PIE;
    }
    లేకపోతే {
        mo->mh.mh.filetype = MH_DYLIB;
        mo->mh.mh.flags = MH_DYLDLINK;
    }
    mo->mh.mh.ncmds = mo->nlc;
    mo->mh.mh.sizeofcmds = 0;
    కొరకు (i = 0; i < mo->nlc; i++)
      mo->mh.mh.sizeofcmds += mo->lc[i]->cmdsize;

    fwrite(&mo->mh, 1, పరిమాణం(mo->mh), fp);
    fileofs += పరిమాణం(mo->mh);
    కొరకు (i = 0; i < mo->nlc; i++) {
        fwrite(mo->lc[i], 1, mo->lc[i]->cmdsize, fp);
        fileofs += mo->lc[i]->cmdsize;
    }

    కొరకు (sk = sk_unknown; sk < sk_చివరి; sk++) {
        //struct segment_command_64 *seg;
        ఒకవేళ (skinfo[sk].seg_initial == 0 ||
	    (s1->output_type == TCC_OUTPUT_EXE && !mo->segment[sk]) ||
	    !mo->sk_గమ్యం_sect[sk].s)
          కొనసాగు;
        /*seg =*/ get_segment(mo, mo->segment[sk]);
        కొరకు (s = mo->sk_గమ్యం_sect[sk].s; s; s = s->prev) {
            ఒకవేళ (s->sh_type != SHT_NOBITS) {
                అయితే (fileofs < s->sh_స్థానభ్రంశం)
                  fputc(0, fp), fileofs++;
                ఒకవేళ (s->sh_కొలత) {
                    fwrite(s->దత్తాంశం, 1, s->sh_కొలత, fp);
                    fileofs += s->sh_కొలత;
                }
            }
        }
    }
}

#నిర్వచితమైతే CONFIG_NEW_MACHO
స్థిర పూర్ణాంకం bind_rebase_cmp(స్థిరరాశి శూన్య *_a, స్థిరరాశి శూన్య *_b, శూన్య *arg)
{
    TCCState *s1 = arg;
    నిర్మాణం bind_rebase *a = (నిర్మాణం bind_rebase *) _a;
    నిర్మాణం bind_rebase *b = (నిర్మాణం bind_rebase *) _b;
    addr_t aa = s1->sections[a->section]->sh_addr + a->rel.r_స్థానభ్రంశం;
    addr_t ab = s1->sections[b->section]->sh_addr + b->rel.r_స్థానభ్రంశం;

    తిరిగి aa > ab ? 1 : aa < ab ? -1 : 0;
}

ST_FUNC శూన్య bind_rebase_import(TCCState *s1, నిర్మాణం macho *mo)
{
    పూర్ణాంకం i, j, k, bind_సూచీ, కొలత, పుట_లెక్క, sym_సూచీ;
    స్థిరరాశి అక్షరం *name;
    ElfW(Sym) *sym;
    గుర్తులేని అక్షరం *దత్తాంశం = mo->chained_fixups->దత్తాంశం;
    నిర్మాణం segment_command_64 *seg;
    నిర్మాణం dyld_chained_fixups_శీర్షిక *శీర్షిక;
    నిర్మాణం dyld_chained_starts_లోపల_image *image;
    నిర్మాణం dyld_chained_starts_లోపల_segment *segment;
    నిర్మాణం dyld_chained_import *import;

    tcc_qsort(mo->bind_rebase, mo->n_bind_rebase, పరిమాణం(నిర్మాణం bind_rebase),
	      bind_rebase_cmp, s1);
    కొరకు (i = 0; i < mo->n_bind_rebase - 1; i++)
	ఒకవేళ (mo->bind_rebase[i].section == mo->bind_rebase[i + 1].section &&
	    mo->bind_rebase[i].rel.r_స్థానభ్రంశం == mo->bind_rebase[i + 1].rel.r_స్థానభ్రంశం) {
	    sym_సూచీ = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
            sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
	    name = (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name;
	    tcc_error("Overlap %s/%s %s:%s",
		      mo->bind_rebase[i].bind ? "bind" : "rebase",
		      mo->bind_rebase[i + 1].bind ? "bind" : "rebase",
		      s1->sections[mo->bind_rebase[i].section]->name, name);
	}
    శీర్షిక = (నిర్మాణం dyld_chained_fixups_శీర్షిక *) దత్తాంశం;
    దత్తాంశం += (పరిమాణం(నిర్మాణం dyld_chained_fixups_శీర్షిక) + 7) & -8;
    శీర్షిక->starts_స్థానభ్రంశం = దత్తాంశం - mo->chained_fixups->దత్తాంశం;
    శీర్షిక->imports_లెక్క = mo->n_bind;
    శీర్షిక->imports_format = DYLD_CHAINED_IMPORT;
    శీర్షిక->symbols_format = 0;
    కొలత = పరిమాణం(నిర్మాణం dyld_chained_starts_లోపల_image) +
	   (mo->nseg - 1) * పరిమాణం(uint32_t);
    image = (నిర్మాణం dyld_chained_starts_లోపల_image *) దత్తాంశం;
    దత్తాంశం += (కొలత + 7) & -8;
    image->seg_లెక్క = mo->nseg;
    కొరకు (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
        image->seg_info_స్థానభ్రంశం[i] = (దత్తాంశం - mo->chained_fixups->దత్తాంశం) -
				    శీర్షిక->starts_స్థానభ్రంశం;
	seg = get_segment(mo, i);
	పుట_లెక్క = (seg->vmsize + SEG_పుట_కొలత - 1) / SEG_పుట_కొలత;
	కొలత = పరిమాణం(నిర్మాణం dyld_chained_starts_లోపల_segment) +
		      (పుట_లెక్క - 1) * పరిమాణం(uint16_t);
        segment = (నిర్మాణం dyld_chained_starts_లోపల_segment *) దత్తాంశం;
        దత్తాంశం += (కొలత + 7) & -8;
        segment->కొలత = కొలత;
        segment->పుట_కొలత = SEG_పుట_కొలత;
#ఒకవేళ 1
#నిర్వచించు	PTR_64_స్థానభ్రంశం 0
#నిర్వచించు	PTR_64_ముసుగు   0x7FFFFFFFFFFULL
        segment->సూచిక_format = DYLD_CHAINED_PTR_64;
#లేకపోతే
#నిర్వచించు	PTR_64_స్థానభ్రంశం 0x100000000ULL
#నిర్వచించు	PTR_64_ముసుగు   0xFFFFFFFFFFFFFFULL
        segment->సూచిక_format = DYLD_CHAINED_PTR_64_స్థానభ్రంశం;
#అయితే_ముగింపు
        segment->segment_స్థానభ్రంశం = seg->fileoff;
        segment->max_valid_సూచిక = 0;
        segment->పుట_లెక్క = పుట_లెక్క;
	// add bind/rebase
	bind_సూచీ = 0;
	k = 0;
	కొరకు (j = 0; j < పుట_లెక్క; j++) {
	    addr_t ప్రారంభం = seg->vmaddr + j * SEG_పుట_కొలత;
	    addr_t చివర = ప్రారంభం + SEG_పుట_కొలత;
	    శూన్య *చివరి = ఖాళీ;
	    addr_t చివరి_o = 0;
	    addr_t cur_o, cur;
	    నిర్మాణం dyld_chained_ptr_64_rebase *rebase;
	    నిర్మాణం dyld_chained_ptr_64_bind *bind;

	    segment->పుట_ప్రారంభం[j] = DYLD_CHAINED_PTR_ప్రారంభం_NONE;
	    కొరకు (; k < mo->n_bind_rebase; k++) {
	        Section *s = s1->sections[mo->bind_rebase[k].section];
		addr_t r_స్థానభ్రంశం = mo->bind_rebase[k].rel.r_స్థానభ్రంశం;
		addr_t addr = s->sh_addr + r_స్థానభ్రంశం;

		ఒకవేళ ((addr & 3) ||
		    (addr & (SEG_పుట_కొలత - 1)) > SEG_పుట_కొలత - PTR_కొలత)
		    tcc_error("Illegal rel_offset %s %lld",
			      s->name, (దీర్ఘ దీర్ఘ)r_స్థానభ్రంశం);
		ఒకవేళ (addr >= చివర)
		    ఆపు;
		ఒకవేళ (addr >= ప్రారంభం) {
		    cur_o = addr - ప్రారంభం;
	            ఒకవేళ (mo->bind_rebase[k].bind) {
		        ఒకవేళ (segment->పుట_ప్రారంభం[j] == DYLD_CHAINED_PTR_ప్రారంభం_NONE)
			    segment->పుట_ప్రారంభం[j] = cur_o;
		        లేకపోతే {
			    bind = (నిర్మాణం dyld_chained_ptr_64_bind *) చివరి;
			    bind->తదుపరి = (cur_o - చివరి_o) / 4;
		        }
		        bind = (నిర్మాణం dyld_chained_ptr_64_bind *)
				    (s->దత్తాంశం + r_స్థానభ్రంశం);
		        చివరి = bind;
		        చివరి_o = cur_o;
		        bind->ordinal = bind_సూచీ;
		        bind->addend = 0;
		        bind->reserved = 0;
		        bind->తదుపరి = 0;
		        bind->bind = 1;
		    }
		    లేకపోతే {
		        ఒకవేళ (segment->పుట_ప్రారంభం[j] == DYLD_CHAINED_PTR_ప్రారంభం_NONE)
			    segment->పుట_ప్రారంభం[j] = cur_o;
		        లేకపోతే {
			    rebase = (నిర్మాణం dyld_chained_ptr_64_rebase *) చివరి;
			    rebase->తదుపరి = (cur_o - చివరి_o) / 4;
		        }
		        rebase = (నిర్మాణం dyld_chained_ptr_64_rebase *)
				    (s->దత్తాంశం + r_స్థానభ్రంశం);
		        చివరి = rebase;
		        చివరి_o = cur_o;
		        cur = (*(uint64_t *) (s->దత్తాంశం + r_స్థానభ్రంశం)) -
			      PTR_64_స్థానభ్రంశం;
		        rebase->లక్ష్యం = cur & PTR_64_ముసుగు;
		        rebase->high8 = cur >> (64 - 8);
			ఒకవేళ (cur != ((uint64_t)rebase->high8 << (64 - 8)) + rebase->లక్ష్యం)
			    tcc_error("rebase error");
		        rebase->reserved = 0;
		        rebase->తదుపరి = 0;
		        rebase->bind = 0;
		    }
		}
		bind_సూచీ += mo->bind_rebase[k].bind;
	    }
	}
    }
    // add imports
    శీర్షిక->imports_స్థానభ్రంశం = దత్తాంశం - mo->chained_fixups->దత్తాంశం;
    import = (నిర్మాణం dyld_chained_import *) దత్తాంశం;
    దత్తాంశం += mo->n_bind * పరిమాణం (నిర్మాణం dyld_chained_import);
    శీర్షిక->symbols_స్థానభ్రంశం = దత్తాంశం - mo->chained_fixups->దత్తాంశం;
    దత్తాంశం++;
    కొరకు (i = 0, bind_సూచీ = 0; i < mo->n_bind_rebase; i++) {
	ఒకవేళ (mo->bind_rebase[i].bind) {
	    import[bind_సూచీ].lib_ordinal =
		BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xffu;
	    import[bind_సూచీ].name_స్థానభ్రంశం =
		(దత్తాంశం - mo->chained_fixups->దత్తాంశం) - శీర్షిక->symbols_స్థానభ్రంశం;
	    sym_సూచీ = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    sym = &((ElfW(Sym) *)symtab_section->దత్తాంశం)[sym_సూచీ];
	    import[bind_సూచీ].weak_import =
		ELFW(ST_BIND)(sym->st_info) == STB_WEAK;
	    name = (అక్షరం *) symtab_section->link->దత్తాంశం + sym->st_name;
            strcpy((అక్షరం *) దత్తాంశం, name);
	    దత్తాంశం += అక్షరశ్రేణి_పొడవు(name) + 1;
	    bind_సూచీ++;
	}
    }
    tcc_free(mo->bind_rebase);
}
#అయితే_ముగింపు

ST_FUNC పూర్ణాంకం macho_output_file(TCCState *s1, స్థిరరాశి అక్షరం *filename)
{
    పూర్ణాంకం fd, బహుళకం, file_type;
    FILE *fp;
    పూర్ణాంకం i, ret = -1;
    నిర్మాణం macho mo;

    (శూన్య)memset(&mo, 0, పరిమాణం(mo));

    file_type = s1->output_type;
    ఒకవేళ (file_type == TCC_OUTPUT_OBJ)
        బహుళకం = 0666;
    లేకపోతే
        బహుళకం = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_ద్విమాన_2, బహుళకం);
    ఒకవేళ (fd < 0 || (fp = fdopen(fd, "wb")) == ఖాళీ) {
        tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
        తిరిగి -1;
    }
    tcc_కూడు_runtime(s1);
    tcc_macho_కూడు_destructor(s1);
    resolve_common_syms(s1);
    create_symtab(s1, &mo);
    check_relocs(s1, &mo);
    ret = check_symbols(s1, &mo);
    ఒకవేళ (!ret) {
	పూర్ణాంకం save_output = s1->output_type;

        collect_sections(s1, &mo, filename);
        relocate_syms(s1, s1->symtab, 0);
	ఒకవేళ (s1->output_type == TCC_OUTPUT_EXE)
            mo.ep->entryoff = get_sym_addr(s1, "main", 1, 1)
                            -     get_segment(&mo, 1)->vmaddr;
        ఒకవేళ (s1->nb_errors)
          వెళ్ళు do_ret;
	// Macho uses bind/rebase instead of dynsym
	s1->output_type = TCC_OUTPUT_EXE;
        relocate_sections(s1);
	s1->output_type = save_output;
#నిర్వచితమైతే CONFIG_NEW_MACHO
	bind_rebase_import(s1, &mo);
#అయితే_ముగింపు
        convert_symbols(s1, &mo);
        ఒకవేళ (s1->verbose)
            రాయి("<- %s\n", filename);
        macho_write(s1, &mo, fp);
    }

 do_ret:
    కొరకు (i = 0; i < mo.nlc; i++)
      tcc_free(mo.lc[i]);
    tcc_free(mo.seg2lc);
    tcc_free(mo.lc);
    tcc_free(mo.elfsectomacho);
    tcc_free(mo.e2msym);

    fclose(fp);
#నిర్వచితమైతే CONFIG_CODESIGN
    ఒకవేళ (!ret) {
	అక్షరం command[1024];
	పూర్ణాంకం retval;

	snprintf(command, పరిమాణం(command), "codesign -f -s - %s", filename);
	retval = system (command);
	ఒకవేళ (retval == -1 || !(WIFEXITED(retval) && WEXITSTATUS(retval) == 0))
	    tcc_error ("command failed '%s'", command);
    }
#అయితే_ముగింపు
    తిరిగి ret;
}

స్థిర uint32_t macho_swap32(uint32_t x)
{
  తిరిగి (x >> 24) | (x << 24) | ((x >> 8) & 0xff00) | ((x & 0xff00) << 8);
}
#నిర్వచించు మార్పిడి(x) (మార్పిడి_2 ? macho_swap32(x) : (x))
#నిర్వచించు tbd_parse_movepast(s) \
    (pos = (pos = అక్షరశ్రేణి_శోధన(pos, s)) ? pos + అక్షరశ్రేణి_పొడవు(s) : ఖాళీ)
#నిర్వచించు tbd_parse_movetoany(cs) (pos = strpbrk(pos, cs))
#నిర్వచించు tbd_parse_skipws అయితే (*pos && (*pos==' '||*pos=='\n')) ++pos
#నిర్వచించు tbd_parse_tramplequote ఒకవేళ(*pos=='\''||*pos=='"') tbd_parse_trample
#నిర్వచించు tbd_parse_tramplespace ఒకవేళ(*pos==' ') tbd_parse_trample
#నిర్వచించు tbd_parse_trample *pos++=0

#నిర్వచితమైతే TCC_IS_NATIVE
/* Looks for the active developer SDK set by xcode-select (or the default
   one set during installation.) */
ST_FUNC శూన్య tcc_కూడు_macos_sdkpath(TCCState* s)
{
    అక్షరం *sdkroot = ఖాళీ, *pos = ఖాళీ;
    శూన్య* xcs = dlopen("libxcselect.dylib", RTLD_GLOBAL | RTLD_LAZY);
    CString మార్గం;
    పూర్ణాంకం (*f)(గుర్తులేని పూర్ణాంకం, అక్షరం**) = dlsym(xcs, "xcselect_host_sdk_path");
    cstr_new(&మార్గం);
    ఒకవేళ (f) f(1, &sdkroot);
    ఒకవేళ (sdkroot)
        pos = అక్షరశ్రేణి_శోధన(sdkroot,"SDKs/MacOSX");
    ఒకవేళ (pos)
        cstr_printf(&మార్గం, "%.*s.sdk/usr/lib", (పూర్ణాంకం)(pos - sdkroot + 11), sdkroot);
    /* must use free from libc directly */
#సూచన నెట్టు_macro("free")
#నిర్వచనం_రద్దు విడుదల
    విడుదల(sdkroot);
#సూచన తీయి_macro("free")
    ఒకవేళ (మార్గం.కొలత)
        tcc_కూడు_library_మార్గం(s, (అక్షరం*)మార్గం.దత్తాంశం);
    లేకపోతే
        tcc_కూడు_library_మార్గం(s,
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib"
            ":" "/Applications/Xcode.app/Developer/SDKs/MacOSX.sdk/usr/lib"
            );
    cstr_free(&మార్గం);
}

ST_FUNC అక్షరం* macho_tbd_soname(పూర్ణాంకం fd) {
    అక్షరం *soname, *దత్తాంశం, *pos;
    అక్షరం *ret = 0;
    pos = దత్తాంశం = tcc_ఎక్కించు_పాఠ్యం(fd);
    ఒకవేళ (!tbd_parse_movepast("install-name: ")) వెళ్ళు the_చివర;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    ఒకవేళ (!tbd_parse_movetoany("\n \"'")) వెళ్ళు the_చివర;
    tbd_parse_trample;
    ret = tcc_strdup(soname);
the_చివర:
    tcc_free(దత్తాంశం);
    తిరిగి ret;
}
#అయితే_ముగింపు /* TCC_IS_NATIVE */

ST_FUNC పూర్ణాంకం macho_ఎక్కించు_tbd(TCCState* s1, పూర్ణాంకం fd, స్థిరరాశి అక్షరం* filename, పూర్ణాంకం lev)
{
    అక్షరం *soname, *దత్తాంశం, *pos;
    పూర్ణాంకం ret = -1;

    pos = దత్తాంశం = tcc_ఎక్కించు_పాఠ్యం(fd);
    ఒకవేళ (!tbd_parse_movepast("install-name: ")) వెళ్ళు the_చివర;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    ఒకవేళ (!tbd_parse_movetoany("\n \"'")) వెళ్ళు the_చివర;
    tbd_parse_trample;
    ret = 0;
    ఒకవేళ (tcc_కూడు_dllref(s1, soname, lev)->దొరికింది)
        వెళ్ళు the_చివర;
    అయితే(pos) {
        అక్షరం* sym = ఖాళీ;
        పూర్ణాంకం cont = 1;
        ఒకవేళ (!tbd_parse_movepast("symbols: ")) ఆపు;
        ఒకవేళ (!tbd_parse_movepast("[")) ఆపు;
        అయితే (cont) {
            tbd_parse_skipws;
            tbd_parse_tramplequote;
            sym = pos;
            ఒకవేళ (!tbd_parse_movetoany(",] \"'")) ఆపు;
            tbd_parse_tramplequote;
            tbd_parse_tramplespace;
            tbd_parse_skipws;
            ఒకవేళ (*pos==0||*pos==']') cont=0;
            tbd_parse_trample;
            సమితి_elf_sym(s1->dynsymtab_section, 0, 0,
                ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0, SHN_UNDEF, sym);
        }
    }

the_చివర:
    tcc_free(దత్తాంశం);
    తిరిగి ret;
}

ST_FUNC పూర్ణాంకం macho_ఎక్కించు_dll(TCCState * s1, పూర్ణాంకం fd, స్థిరరాశి అక్షరం* filename, పూర్ణాంకం lev)
{
    గుర్తులేని అక్షరం buf[పరిమాణం(నిర్మాణం mach_శీర్షిక_64)];
    శూన్య *buf2;
    uint32_t machofs = 0;
    నిర్మాణం fat_శీర్షిక fh;
    నిర్మాణం mach_శీర్షిక mh;
    నిర్మాణం ఎక్కించు_command *lc;
    పూర్ణాంకం i, మార్పిడి_2 = 0;
    స్థిరరాశి అక్షరం *soname = filename;
    నిర్మాణం nlist_64 *symtab = 0;
    uint32_t nsyms = 0;
    అక్షరం *strtab = 0;
    uint32_t strsize = 0;
    uint32_t iextdef = 0;
    uint32_t nextdef = 0;

  again:
    ఒకవేళ (నిండిన_read(fd, buf, పరిమాణం(buf)) != పరిమాణం(buf))
      తిరిగి -1;
    జ్ఞాపకం_నకలు(&fh, buf, పరిమాణం(fh));
    ఒకవేళ (fh.magic == FAT_MAGIC || fh.magic == FAT_CIGAM) {
        నిర్మాణం fat_arch *fa = ఎక్కించు_దత్తాంశం(fd, పరిమాణం(fh),
                                        fh.nfat_arch * పరిమాణం(*fa));
        మార్పిడి_2 = fh.magic == FAT_CIGAM;
        కొరకు (i = 0; i < మార్పిడి(fh.nfat_arch); i++)
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
          ఒకవేళ (మార్పిడి(fa[i].cputype) == CPU_TYPE_X86_64
              && మార్పిడి(fa[i].cpusubtype) == CPU_SUBTYPE_X86_ALL)
#లేదావేళ defined TCC_లక్ష్యం_ARM64
          ఒకవేళ (మార్పిడి(fa[i].cputype) == CPU_TYPE_ARM64
              && మార్పిడి(fa[i].cpusubtype) == CPU_SUBTYPE_ARM64_ALL)
#అయితే_ముగింపు
            ఆపు;
        ఒకవేళ (i == మార్పిడి(fh.nfat_arch)) {
            tcc_free(fa);
            తిరిగి -1;
        }
        machofs = మార్పిడి(fa[i].స్థానభ్రంశం);
        tcc_free(fa);
        lseek(fd, machofs, SEEK_SET);
        వెళ్ళు again;
    } లేకపోతే ఒకవేళ (fh.magic == FAT_MAGIC_64 || fh.magic == FAT_CIGAM_64) {
        tcc_warning("%s: Mach-O fat 64bit files of type 0x%x not handled",
                    filename, fh.magic);
        తిరిగి -1;
    }

    జ్ఞాపకం_నకలు(&mh, buf, పరిమాణం(mh));
    ఒకవేళ (mh.magic != MH_MAGIC_64)
      తిరిగి -1;
    dprintf("found Mach-O at %d\n", machofs);
    buf2 = ఎక్కించు_దత్తాంశం(fd, machofs + పరిమాణం(నిర్మాణం mach_శీర్షిక_64), mh.sizeofcmds);
    కొరకు (i = 0, lc = buf2; i < mh.ncmds; i++) {
        dprintf("lc %2d: 0x%08x\n", i, lc->cmd);
        ఎంపిక (lc->cmd) {
        స్థితి LC_SYMTAB:
        {
            నిర్మాణం symtab_command *sc = (నిర్మాణం symtab_command*)lc;
            nsyms = sc->nsyms;
            symtab = ఎక్కించు_దత్తాంశం(fd, machofs + sc->symoff, nsyms * పరిమాణం(*symtab));
            strsize = sc->strsize;
            strtab = ఎక్కించు_దత్తాంశం(fd, machofs + sc->stroff, strsize);
            ఆపు;
        }
        స్థితి LC_ID_DYLIB:
        {
            నిర్మాణం dylib_command *dc = (నిర్మాణం dylib_command*)lc;
            soname = (అక్షరం*)lc + dc->name;
            dprintf(" ID_DYLIB %d 0x%x 0x%x %s\n",
                    dc->timestamp, dc->current_సంస్కరణ,
                    dc->compatibility_సంస్కరణ, soname);
            ఆపు;
        }
        స్థితి LC_REEXPORT_DYLIB:
        {
            నిర్మాణం dylib_command *dc = (నిర్మాణం dylib_command*)lc;
            అక్షరం *name = (అక్షరం*)lc + dc->name;
            పూర్ణాంకం subfd = open(name, O_RDONLY | O_ద్విమాన_2);
            dprintf(" REEXPORT %s\n", name);
            ఒకవేళ (subfd < 0)
              tcc_warning("can't open %s (reexported from %s)", name, filename);
            లేకపోతే {
                /* Hopefully the REEXPORTs never form a cycle, we don't check
                   for that!  */
                macho_ఎక్కించు_dll(s1, subfd, name, lev + 1);
                close(subfd);
            }
            ఆపు;
        }
        స్థితి LC_DYSYMTAB:
        {
            నిర్మాణం dysymtab_command *dc = (నిర్మాణం dysymtab_command*)lc;
            iextdef = dc->iextdefsym;
            nextdef = dc->nextdefsym;
            ఆపు;
        }
        }
        lc = (నిర్మాణం ఎక్కించు_command*) ((అక్షరం*)lc + lc->cmdsize);
    }

    ఒకవేళ (tcc_కూడు_dllref(s1, soname, lev)->దొరికింది)
        వెళ్ళు the_చివర;

    ఒకవేళ (!nsyms || !nextdef)
      tcc_warning("%s doesn't export any symbols?", filename);

    //dprintf("symbols (all):\n");
    dprintf("symbols (exported):\n");
    dprintf("    n: typ sec   desc              value name\n");
    //for (i = 0; i < nsyms; i++) {
    కొరకు (i = iextdef; i < iextdef + nextdef; i++) {
        నిర్మాణం nlist_64 *sym = symtab + i;
        dprintf("%5d: %3d %3d 0x%04x 0x%016lx %s\n",
                i, sym->n_type, sym->n_sect, sym->n_desc, (దీర్ఘ)sym->n_విలువ,
                strtab + sym->n_strx);
        సమితి_elf_sym(s1->dynsymtab_section, 0, 0,
                    ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
                    0, SHN_UNDEF, strtab + sym->n_strx);
    }

  the_చివర:
    tcc_free(strtab);
    tcc_free(symtab);
    tcc_free(buf2);
    తిరిగి 0;
}
