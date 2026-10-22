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
#अन्तर्भाव "tcc.h"

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

#यदि !defined TCC_TARGET_X86_64 && !defined TCC_TARGET_ARM64
#दोषः Platform not supported
#यदि_अन्तः

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#अपरिभाषय _tcc_error

#परिभाषय DEBUG_MACHO 0
#परिभाषय dprintf यदि (DEBUG_MACHO) प्रारूप_लिख

#परिभाषय MH_EXECUTE              (0x2)
#परिभाषय MH_DYLDLINK             (0x4)
#परिभाषय MH_DYLIB                (0x6)
#परिभाषय MH_PIE                  (0x200000)

#परिभाषय CPU_SUBTYPE_LIB64       (0x80000000)
#परिभाषय CPU_SUBTYPE_X86_ALL     (3)
#परिभाषय CPU_SUBTYPE_ARM64_ALL   (0)

#परिभाषय CPU_ARCH_ABI64          (0x01000000)

#परिभाषय CPU_TYPE_X86            (7)
#परिभाषय CPU_TYPE_X86_64         (CPU_TYPE_X86 | CPU_ARCH_ABI64)
#परिभाषय CPU_TYPE_ARM            (12)
#परिभाषय CPU_TYPE_ARM64          (CPU_TYPE_ARM | CPU_ARCH_ABI64)

संरचना fat_शीर्षकम् {
    uint32_t        magic;          /* FAT_MAGIC or FAT_MAGIC_64 */
    uint32_t        nfat_arch;      /* number of structs that follow */
};

संरचना fat_arch {
    पूर्णाङ्क             cputype;        /* cpu specifier (int) */
    पूर्णाङ्क             cpusubtype;     /* machine specifier (int) */
    uint32_t        विस्थापनम्;         /* file offset to this object file */
    uint32_t        आकार;           /* size of this object file */
    uint32_t        align;          /* alignment as a power of 2 */
};

#परिभाषय FAT_MAGIC       0xcafebabe
#परिभाषय FAT_CIGAM       0xbebafeca
#परिभाषय FAT_MAGIC_64    0xcafebabf
#परिभाषय FAT_CIGAM_64    0xbfbafeca

संरचना mach_शीर्षकम् {
    uint32_t        magic;          /* mach magic number identifier */
    पूर्णाङ्क             cputype;        /* cpu specifier */
    पूर्णाङ्क             cpusubtype;     /* machine specifier */
    uint32_t        filetype;       /* type of file */
    uint32_t        ncmds;          /* number of load commands */
    uint32_t        sizeofcmds;     /* the size of all the load commands */
    uint32_t        flags;          /* flags */
};

संरचना mach_शीर्षकम्_64 {
    संरचना mach_शीर्षकम्  mh;
    uint32_t            reserved;       /* reserved, pad to 64bit */
};

/* Constant for the magic field of the mach_header (32-bit architectures) */
#परिभाषय MH_MAGIC        0xfeedface      /* the mach magic number */
#परिभाषय MH_CIGAM        0xcefaedfe      /* NXSwapInt(MH_MAGIC) */
#परिभाषय MH_MAGIC_64     0xfeedfacf      /* the 64-bit mach magic number */
#परिभाषय MH_CIGAM_64     0xcffaedfe      /* NXSwapInt(MH_MAGIC_64) */

संरचना आरोपय_command {
    uint32_t        cmd;            /* type of load command */
    uint32_t        cmdsize;        /* total size of command in bytes */
};

#परिभाषय LC_REQ_DYLD 0x80000000
#परिभाषय LC_SYMTAB        0x2
#परिभाषय LC_DYSYMTAB      0xb
#परिभाषय LC_आरोपय_DYLIB    0xc
#परिभाषय LC_ID_DYLIB      0xd
#परिभाषय LC_आरोपय_DYLINKER 0xe
#परिभाषय LC_SEGMENT_64    0x19
#परिभाषय LC_RPATH (0x1c | LC_REQ_DYLD)
#परिभाषय LC_REEXPORT_DYLIB (0x1f | LC_REQ_DYLD)
#परिभाषय LC_DYLD_INFO_ONLY (0x22|LC_REQ_DYLD)
#परिभाषय LC_MAIN (0x28|LC_REQ_DYLD)
#परिभाषय LC_SOURCE_संस्करणम् 0x2A
#परिभाषय LC_BUILD_संस्करणम् 0x32
#परिभाषय LC_DYLD_EXPORTS_TRIE (0x33 | LC_REQ_DYLD)
#परिभाषय LC_DYLD_CHAINED_FIXUPS (0x34 | LC_REQ_DYLD)

#परिभाषय SG_READ_ONLY    0x10 /* This segment is made read-only after fixups */

प्रकारनिर्देश पूर्णाङ्क vm_prot_t;

संरचना segment_command_64 { /* for 64-bit architectures */
    uint32_t        cmd;            /* LC_SEGMENT_64 */
    uint32_t        cmdsize;        /* includes sizeof section_64 structs */
    वर्ण            segname[16];    /* segment name */
    uint64_t        vmaddr;         /* memory address of this segment */
    uint64_t        vmsize;         /* memory size of this segment */
    uint64_t        fileoff;        /* file offset of this segment */
    uint64_t        filesize;       /* amount to map from the file */
    vm_prot_t       maxprot;        /* maximum VM protection */
    vm_prot_t       initprot;       /* initial VM protection */
    uint32_t        nsects;         /* number of sections in segment */
    uint32_t        flags;          /* flags */
};

संरचना section_64 { /* for 64-bit architectures */
    वर्ण            sectname[16];   /* name of this section */
    वर्ण            segname[16];    /* segment this section goes in */
    uint64_t        addr;           /* memory address of this section */
    uint64_t        आकार;           /* size in bytes of this section */
    uint32_t        विस्थापनम्;         /* file offset of this section */
    uint32_t        align;          /* section alignment (power of 2) */
    uint32_t        reloff;         /* file offset of relocation entries */
    uint32_t        nreloc;         /* number of relocation entries */
    uint32_t        flags;          /* flags (section type and attributes)*/
    uint32_t        reserved1;      /* reserved (for offset or index) */
    uint32_t        reserved2;      /* reserved (for count or sizeof) */
    uint32_t        reserved3;      /* reserved */
};

गणना {
    DYLD_CHAINED_IMPORT          = 1,
};

संरचना dyld_chained_fixups_शीर्षकम् {
    uint32_t    fixups_संस्करणम्; ///< 0
    uint32_t    starts_विस्थापनम्;  ///< Offset of dyld_chained_starts_in_image.
    uint32_t    imports_विस्थापनम्; ///< Offset of imports table in chain_data.
    uint32_t    symbols_विस्थापनम्; ///< Offset of symbol strings in chain_data.
    uint32_t    imports_गणनम्;  ///< Number of imported symbol names.
    uint32_t    imports_format; ///< DYLD_CHAINED_IMPORT*
    uint32_t    symbols_format; ///< 0 => uncompressed, 1 => zlib compressed
};

संरचना dyld_chained_starts_अन्तर्_image
{
    uint32_t    seg_गणनम्;
    uint32_t    seg_info_विस्थापनम्[1];  // each entry is offset into this struct for that segment
    // followed by pool of dyld_chain_starts_in_segment data
};

गणना {
    DYLD_CHAINED_PTR_64                     =  2,    // target is vmaddr
    DYLD_CHAINED_PTR_64_विस्थापनम्              =  6,    // target is vm offset
};

गणना {
    DYLD_CHAINED_PTR_START_NONE   = 0xFFFF, // used in page_start[] to denote a page with no fixups
};

#परिभाषय SEG_PAGE_आकार 16384

संरचना dyld_chained_starts_अन्तर्_segment
{
    uint32_t    आकार;               // size of this (amount kernel needs to copy)
    uint16_t    page_आकार;          // 0x1000 or 0x4000
    uint16_t    pointer_format;     // DYLD_CHAINED_PTR_*
    uint64_t    segment_विस्थापनम्;     // offset in memory to start of segment
    uint32_t    max_valid_pointer;  // for 32-bit OS, any value beyond this is not a pointer
    uint16_t    page_गणनम्;         // how many pages are in array
    uint16_t    page_start[1];      // each entry is offset in each page of first element in chain
                                    // or DYLD_CHAINED_PTR_START_NONE if no fixups on page
};

गणना BindSpecialDylib {
  BIND_SPECIAL_DYLIB_FLAT_LOOKUP = -2,
};

संरचना dyld_chained_import
{
    uint32_t    lib_ordinal :  8,
                weak_import :  1,
                name_विस्थापनम् : 23;
};

संरचना dyld_chained_ptr_64_rebase
{
    uint64_t    target    : 36,    // vmaddr, 64GB max image size
                high8     :  8,    // top 8 bits set to this after slide added
                reserved  :  7,    // all zeros
                अग्र      : 12,    // 4-byte stride
                bind      :  1;    // == 0
};

संरचना dyld_chained_ptr_64_bind
{
    uint64_t    ordinal   : 24,
                addend    :  8,   // 0 thru 255
                reserved  : 19,   // all zeros
                अग्र      : 12,   // 4-byte stride
                bind      :  1;   // == 1
};

#परिभाषय S_REGULAR                       0x0
#परिभाषय S_ZEROFILL                      0x1
#परिभाषय S_NON_LAZY_चिह्नम्_सूचकाः      0x6
#परिभाषय S_LAZY_चिह्नम्_सूचकाः          0x7
#परिभाषय S_चिह्नम्_STUBS                  0x8
#परिभाषय S_MOD_INIT_FUNC_सूचकाः        0x9
#परिभाषय S_MOD_पदांशः_FUNC_सूचकाः        0xa

#परिभाषय S_ATTR_विशुद्धम्_INSTRUCTIONS        0x80000000
#परिभाषय S_ATTR_SOME_INSTRUCTIONS        0x00000400
#परिभाषय S_ATTR_DEBUG             	0x02000000


प्रकारनिर्देश uint32_t lc_str;

संरचना dylib_command {
    uint32_t cmd;                   /* LC_ID_DYLIB, LC_LOAD_{,WEAK_}DYLIB,
                                       LC_REEXPORT_DYLIB */
    uint32_t cmdsize;               /* includes pathname string */
    lc_str   name;                  /* library's path name */
    uint32_t timestamp;             /* library's build time stamp */
    uint32_t current_संस्करणम्;       /* library's current version number */
    uint32_t compatibility_संस्करणम्; /* library's compatibility vers number*/
};

संरचना rpath_command {
    uint32_t     cmd;           /* LC_RPATH */
    uint32_t     cmdsize;       /* includes string */
    lc_str       मार्गः;          /* path to add to run path */
};

संरचना dylinker_command {
    uint32_t        cmd;            /* LC_ID_DYLINKER, LC_LOAD_DYLINKER or
                                       LC_DYLD_ENVIRONMENT */
    uint32_t        cmdsize;        /* includes pathname string */
    lc_str          name;           /* dynamic linker's path name */
};

संरचना linkedit_दत्त_command {
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

#परिभाषय PLATFORM_MACOS 1

संरचना build_संस्करणम्_command {
    uint32_t    cmd;            /* LC_BUILD_VERSION */
    uint32_t    cmdsize;        /* sizeof(struct build_version_command) plus */
                                /* ntools * sizeof(struct build_tool_version) */
    uint32_t    platform;       /* platform */
    uint32_t    minos;          /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    sdk;            /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    ntools;         /* number of tool entries following this */
};

संरचना source_संस्करणम्_command {
    uint32_t  cmd;      /* LC_SOURCE_VERSION */
    uint32_t  cmdsize;  /* 16 */
    uint64_t  संस्करणम्;  /* A.B.C.D.E packed as a24.b10.c10.d10.e10 */
};

संरचना symtab_command {
    uint32_t        cmd;            /* LC_SYMTAB */
    uint32_t        cmdsize;        /* sizeof(struct symtab_command) */
    uint32_t        symoff;         /* symbol table offset */
    uint32_t        nsyms;          /* number of symbol table entries */
    uint32_t        stroff;         /* string table offset */
    uint32_t        strsize;        /* string table size in bytes */
};

संरचना dysymtab_command {
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

#परिभाषय BIND_OPCODE_समाप्तम्                                        0x00
#परिभाषय BIND_OPCODE_समुच्चयः_DYLIB_SPECIAL_IMM                       0x30
#परिभाषय BIND_OPCODE_समुच्चयः_चिह्नम्_TRAILING_FLAGS_IMM               0x40
#परिभाषय BIND_OPCODE_समुच्चयः_TYPE_IMM                                0x50
#परिभाषय BIND_OPCODE_समुच्चयः_SEGMENT_AND_विस्थापनम्_ULEB                 0x70
#परिभाषय BIND_OPCODE_DO_BIND                                     0x90

#परिभाषय BIND_चिह्नम्_FLAGS_WEAK_IMPORT                           0x1

#परिभाषय BIND_TYPE_POINTER                                       1
#परिभाषय BIND_SPECIAL_DYLIB_FLAT_LOOKUP                          -2

#परिभाषय REBASE_OPCODE_समाप्तम्                                      0x00
#परिभाषय REBASE_OPCODE_समुच्चयः_TYPE_IMM                              0x10
#परिभाषय REBASE_OPCODE_समुच्चयः_SEGMENT_AND_विस्थापनम्_ULEB               0x20
#परिभाषय REBASE_OPCODE_DO_REBASE_IMM_TIMES                       0x50

#परिभाषय REBASE_TYPE_POINTER                                     1

#परिभाषय EXPORT_चिह्नम्_FLAGS_विधा_REGULAR                        0x00
#परिभाषय EXPORT_चिह्नम्_FLAGS_विधा_ABSOLUTE                       0x02
#परिभाषय EXPORT_चिह्नम्_FLAGS_WEAK_DEFINITION                     0x04

संरचना dyld_info_command {
    uint32_t cmd;             /* LC_DYLD_INFO or LC_DYLD_INFO_ONLY */
    uint32_t cmdsize;         /* sizeof(struct dyld_info_command) */
    uint32_t rebase_off;      /* file offset to rebase info  */
    uint32_t rebase_आकार;     /* size of rebase info   */
    uint32_t bind_off;        /* file offset to binding info   */
    uint32_t bind_आकार;       /* size of binding info  */
    uint32_t weak_bind_off;   /* file offset to weak binding info   */
    uint32_t weak_bind_आकार;  /* size of weak binding info  */
    uint32_t lazy_bind_off;   /* file offset to lazy binding info */
    uint32_t lazy_bind_आकार;  /* size of lazy binding infs */
    uint32_t export_off;      /* file offset to lazy binding info */
    uint32_t export_आकार;     /* size of lazy binding infs */
};

#परिभाषय परोक्षम्_चिह्नम्_LOCAL   0x80000000

संरचना प्रविष्टिः_point_command {
    uint32_t  cmd;      /* LC_MAIN only used in MH_EXECUTE filetypes */
    uint32_t  cmdsize;  /* 24 */
    uint64_t  entryoff; /* file (__TEXT) offset of main() */
    uint64_t  stacksize;/* if not zero, initial stack size */
};

गणना skind {
    sk_unknown = 0,
    sk_discard,
    sk_text,
    sk_stubs,
    sk_stub_helper,
    sk_ro_दत्त,
    sk_uw_info,
    sk_nl_ptr,  // non-lazy pointers, aka GOT
    sk_debug_info,
    sk_debug_abbrev,
    sk_debug_पङ्क्तिः,
    sk_debug_aranges,
    sk_debug_str,
    sk_debug_पङ्क्तिः_str,
    sk_stab,
    sk_stab_str,
    sk_la_ptr,  // lazy pointers
    sk_init,
    sk_fini,
    sk_rw_दत्त,
    sk_bss,
    sk_linkedit,
    sk_चरमः
};

संरचना nlist_64 {
    uint32_t  n_strx;      /* index into the string table */
    uint8_t n_type;        /* type flag, see below */
    uint8_t n_sect;        /* section number or NO_SECT */
    uint16_t n_desc;       /* see <mach-o/stab.h> */
    uint64_t n_मानम्;      /* value of this symbol (or stab offset) */
};

#परिभाषय N_UNDF  0x0
#परिभाषय N_ABS   0x2
#परिभाषय N_EXT   0x1
#परिभाषय N_SECT  0xe

#परिभाषय N_WEAK_REF      0x0040
#परिभाषय N_WEAK_DEF      0x0080

संरचना macho {
    संरचना mach_शीर्षकम्_64 mh;
    पूर्णाङ्क *seg2lc, nseg;
    संरचना आरोपय_command **lc;
    संरचना प्रविष्टिः_point_command *ep;
    पूर्णाङ्क nlc;
    संरचना {
        Section *s;
        पूर्णाङ्क machosect;
    } sk_गन्तव्यम्_sect[sk_चरमः];
    पूर्णाङ्क *elfsectomacho;
    पूर्णाङ्क *e2msym;
    Section *symtab, *strtab, *indirsyms, *stubs, *exports;
    uint32_t ilocal, iextdef, iundef;
    पूर्णाङ्क stubsym, n_got, nr_plt;
    पूर्णाङ्क segment[sk_चरमः];
#यदि_परिभाषितम् CONFIG_NEW_MACHO
    Section *chained_fixups;
    पूर्णाङ्क n_bind;
    पूर्णाङ्क n_bind_rebase;
    संरचना bind_rebase {
	पूर्णाङ्क section;
	पूर्णाङ्क bind;
	ElfW_Rel rel;
    } *bind_rebase;
#अन्यथा
    Section *rebase, *binding, *weak_binding, *lazy_binding;
    Section *stub_helper, *la_चिह्नम्_ptr;
    संरचना dyld_info_command *dyldinfo;
    पूर्णाङ्क helpsym, lasym, dyld_वैयक्तिकम्, dyld_stub_binder;
    पूर्णाङ्क n_lazy_bind;    
    संरचना s_lazy_bind {
        पूर्णाङ्क section;
        पूर्णाङ्क bind_विस्थापनम्;
        पूर्णाङ्क la_चिह्नम्_विस्थापनम्;
        ElfW_Rel rel;
    } *s_lazy_bind;
    पूर्णाङ्क n_rebase;    
    संरचना s_rebase {
        पूर्णाङ्क section;
        ElfW_Rel rel;
    } *s_rebase;
    पूर्णाङ्क n_bind; 
    संरचना bind {
        पूर्णाङ्क section;
        ElfW_Rel rel;
    } *bind;
#यदि_अन्तः
};

#परिभाषय SHT_LINKEDIT (SHT_LOOS + 42)
#परिभाषय SHN_FROMDLL  (SHN_LOOS + 2)  /* Symbol is undefined, comes from a DLL */

स्थिर शून्य * सङ्कलय_lc(संरचना macho *mo, uint32_t cmd, uint32_t cmdsize)
{
    संरचना आरोपय_command *lc = tcc_mallocz(cmdsize);
    lc->cmd = cmd;
    lc->cmdsize = cmdsize;
    mo->lc = tcc_realloc(mo->lc, परिमाण(mo->lc[0]) * (mo->nlc + 1));
    mo->lc[mo->nlc++] = lc;
    प्रत्यागम lc;
}

स्थिर संरचना segment_command_64 * सङ्कलय_segment(संरचना macho *mo, ध्रुव वर्ण *name)
{
    संरचना segment_command_64 *sc = सङ्कलय_lc(mo, LC_SEGMENT_64, परिमाण(*sc));
    strncpy(sc->segname, name, 16);
    mo->seg2lc = tcc_realloc(mo->seg2lc, परिमाण(*mo->seg2lc) * (mo->nseg + 1));
    mo->seg2lc[mo->nseg++] = mo->nlc - 1;
    प्रत्यागम sc;
}

स्थिर संरचना segment_command_64 * get_segment(संरचना macho *mo, पूर्णाङ्क i)
{
    प्रत्यागम (संरचना segment_command_64 *) (mo->lc[mo->seg2lc[i]]);
}

स्थिर पूर्णाङ्क सङ्कलय_section(संरचना macho *mo, संरचना segment_command_64 **_seg, ध्रुव वर्ण *name)
{
    संरचना segment_command_64 *seg = *_seg;
    पूर्णाङ्क ret = seg->nsects;
    संरचना section_64 *sec;
    seg->nsects++;
    seg->cmdsize += परिमाण(*sec);
    seg = tcc_realloc(seg, परिमाण(*seg) + seg->nsects * परिमाण(*sec));
    sec = (संरचना section_64*)((वर्ण*)seg + परिमाण(*seg)) + ret;
    स्मृतिं_पूरय(sec, 0, परिमाण(*sec));
    strncpy(sec->sectname, name, 16);
    strncpy(sec->segname, seg->segname, 16);
    *_seg = seg;
    प्रत्यागम ret;
}

स्थिर संरचना section_64 *get_section(संरचना segment_command_64 *seg, पूर्णाङ्क i)
{
    प्रत्यागम (संरचना section_64*)((वर्ण*)seg + परिमाण(*seg)) + i;
}

स्थिर शून्य * सङ्कलय_dylib(संरचना macho *mo, वर्ण *name)
{
    संरचना dylib_command *lc;
    पूर्णाङ्क sz = (परिमाण(*lc) + वाक्यदैर्घ्यम्(name) + 1 + 7) & -8;
    lc = सङ्कलय_lc(mo, LC_आरोपय_DYLIB, sz);
    lc->name = परिमाण(*lc);
    वाक्यं_प्रतिलिख((वर्ण*)lc + lc->name, name);
    lc->timestamp = 2;
    lc->current_संस्करणम् = 1 << 16;
    lc->compatibility_संस्करणम् = 1 << 16;
    प्रत्यागम lc;
}

स्थिर पूर्णाङ्क uleb128_आकार (अचिह्नित दीर्घ दीर्घ मानम्)
{
    पूर्णाङ्क आकार =  0;

    कुरु {
        मानम् >>= 7;
        आकार++;
    } यावत् (मानम् != 0);
    प्रत्यागम आकार;
}

स्थिर शून्य write_uleb128(Section *section, uint64_t मानम्)
{
    कुरु {
        अचिह्नित वर्ण byte = मानम् & 0x7f;
	uint8_t *ptr = section_ptr_सङ्कलय(section, 1);

        मानम् >>= 7;
        *ptr = byte | (मानम् ? 0x80 : 0);
    } यावत् (मानम् != 0);
}

स्थिर शून्य tcc_macho_सङ्कलय_destructor(TCCState *s1)
{
    पूर्णाङ्क init_sym, mh_execute_शीर्षकम्, at_exit_sym;
    Section *s;
    ElfW_Rel *rel;
    uint8_t *ptr;

    mh_execute_शीर्षकम् = put_elf_sym(s1->symtab, -4096, 0,
				    ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				    text_section->sh_अङ्कः, "__mh_execute_header");
    s = find_section(s1, ".fini_array");
    यदि (s->दत्त_विस्थापनम् == 0)
        प्रत्यागम; 
    init_sym = put_elf_sym(s1->symtab, text_section->दत्त_विस्थापनम्, 0,
                           ELFW(ST_INFO)(STB_LOCAL, STT_FUNC), 0,
                           text_section->sh_अङ्कः, "___GLOBAL_init_65535");
    at_exit_sym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0,
                              SHN_UNDEF, "___cxa_atexit");
#यदि_परिभाषितम् TCC_TARGET_X86_64
    ptr = section_ptr_सङ्कलय(text_section, 4);
    ptr[0] = 0x55;  // pushq   %rbp
    ptr[1] = 0x48;  // movq    %rsp, %rbp
    ptr[2] = 0x89;
    ptr[3] = 0xe5;
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        पूर्णाङ्क sym_सूचकांक = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_सङ्कलय(text_section, 26);
        ptr[0] = 0x48;  // lea destructor(%rip),%rax
        ptr[1] = 0x8d;
        ptr[2] = 0x05;
        put_elf_reloca(s1->symtab, text_section, 
		       text_section->दत्त_विस्थापनम् - 23,
		       R_X86_64_PC32, sym_सूचकांक, -4);
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
		       text_section->दत्त_विस्थापनम् - 9,
		       R_X86_64_PC32, mh_execute_शीर्षकम्, -4);
	ptr[21] = 0xe8; // call __cxa_atexit
        put_elf_reloca(s1->symtab, text_section,
		       text_section->दत्त_विस्थापनम् - 4,
		       R_X86_64_PLT32, at_exit_sym, -4);
    }
    ptr = section_ptr_सङ्कलय(text_section, 2);
    ptr[0] = 0x5d;  // pop   %rbp
    ptr[1] = 0xc3;  // ret
#नोचेद्यदि defined TCC_TARGET_ARM64
    ptr = section_ptr_सङ्कलय(text_section, 8);
    write32le(ptr, 0xa9bf7bfd);     // stp     x29, x30, [sp, #-16]!
    write32le(ptr + 4, 0x910003fd); // mov     x29, sp
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        पूर्णाङ्क sym_सूचकांक = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_सङ्कलय(text_section, 24);
        put_elf_reloc(s1->symtab, text_section, 
		      text_section->दत्त_विस्थापनम् - 24,
		      R_AARCH64_ADR_PREL_PG_HI21, sym_सूचकांक);
        write32le(ptr, 0x90000000);      // adrp x0, destructor@page
        put_elf_reloc(s1->symtab, text_section,
		      text_section->दत्त_विस्थापनम् - 20,
		      R_AARCH64_LDST8_ABS_LO12_NC, sym_सूचकांक);
        write32le(ptr + 4, 0x91000000);  // add x0,x0,destructor@pageoff
        write32le(ptr + 8, 0xd2800001);  // mov x1, #0
        put_elf_reloc(s1->symtab, text_section, 
		      text_section->दत्त_विस्थापनम् - 12,
		      R_AARCH64_ADR_PREL_PG_HI21, mh_execute_शीर्षकम्);
        write32le(ptr + 12, 0x90000002);      // adrp x2, mh_execute_header@page
        put_elf_reloc(s1->symtab, text_section,
		      text_section->दत्त_विस्थापनम् - 8,
		      R_AARCH64_LDST8_ABS_LO12_NC, mh_execute_शीर्षकम्);
        write32le(ptr + 16, 0x91000042);  // add x2,x2,mh_execute_header@pageoff
        put_elf_reloc(s1->symtab, text_section,
		      text_section->दत्त_विस्थापनम् - 4,
		      R_AARCH64_CALL26, at_exit_sym);
	write32le(ptr + 20, 0x94000000); // bl __cxa_atexit
    }
    ptr = section_ptr_सङ्कलय(text_section, 8);
    write32le(ptr, 0xa8c17bfd);     // ldp     x29, x30, [sp], #16
    write32le(ptr + 4, 0xd65f03c0); // ret
#यदि_अन्तः
    s->reloc->दत्त_विस्थापनम् = s->दत्त_विस्थापनम् = 0;
    s->sh_flags &= ~SHF_ALLOC;
    सङ्कलय_array (s1, ".init_array", init_sym);
}

#यदि_परिभाषितम् CONFIG_NEW_MACHO
स्थिर शून्य bind_rebase_सङ्कलय(संरचना macho *mo, पूर्णाङ्क bind, पूर्णाङ्क sh_info,
			    ElfW_Rel *rel, संरचना sym_attr *attr)
{
    mo->bind_rebase = tcc_realloc(mo->bind_rebase, (mo->n_bind_rebase + 1) *
		                  परिमाण(संरचना bind_rebase));
    mo->bind_rebase[mo->n_bind_rebase].section = sh_info;
    mo->bind_rebase[mo->n_bind_rebase].bind = bind;
    mo->bind_rebase[mo->n_bind_rebase].rel = *rel;
    यदि (attr)
        mo->bind_rebase[mo->n_bind_rebase].rel.r_विस्थापनम् = attr->got_विस्थापनम्;
    mo->n_bind_rebase++;
    mo->n_bind += bind;
}

स्थिर शून्य check_relocs(TCCState *s1, संरचना macho *mo)
{
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    पूर्णाङ्क i, j, type, gotplt_प्रविष्टिः, sym_सूचकांक, for_संहिता;
    uint32_t *pi, *goti;
    संरचना sym_attr *attr;

    goti = रिक्त;
    mo->nr_plt = mo->n_got = 0;
    प्रति (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        यदि (s->sh_type != SHT_RELX ||
	    !वाक्ये_तुलय(s1->sections[s->sh_info]->name, ".debug_", 7))
            अनुवर्त;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_प्रविष्टिः = gotplt_प्रविष्टिः_type(type);
            for_संहिता = संहिता_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
            यदि (sym->st_shndx == SHN_UNDEF
                || gotplt_प्रविष्टिः == ALWAYS_GOTPLT_प्रविष्टिः) {
                attr = get_sym_attr(s1, sym_सूचकांक, 1);
                यदि (!attr->dyn_सूचकांक) {
                    attr->got_विस्थापनम् = s1->got->दत्त_विस्थापनम्;
                    attr->plt_विस्थापनम् = -1;
                    attr->dyn_सूचकांक = 1; /* used as flag */
                    section_ptr_सङ्कलय(s1->got, PTR_आकार);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_विस्थापनम्,
                                  R_JMP_SLOT, sym_सूचकांक);
	 	    goti = tcc_realloc(goti, (mo->n_got + 1) * परिमाण(*goti));
                    यदि (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        यदि (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (वर्ण *) symtab_section->link->दत्त + sym->st_name);
			goti[mo->n_got++] = परोक्षम्_चिह्नम्_LOCAL;
                    } अन्यथा {
                        goti[mo->n_got++] = mo->e2msym[sym_सूचकांक];
                        यदि (sym->st_shndx == SHN_UNDEF
#यदि_परिभाषितम् TCC_TARGET_X86_64
                            && type == R_X86_64_GOTPCREL
#नोचेद्यदि defined TCC_TARGET_ARM64
                            && type == R_AARCH64_ADR_GOT_PAGE
#यदि_अन्तः
                            ) {
			    attr->plt_विस्थापनम् = -mo->n_bind_rebase - 2;
			    bind_rebase_सङ्कलय(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
			    s1->got->reloc->दत्त_विस्थापनम् -= परिमाण (ElfW_Rel);
			}
		        यदि (for_संहिता && sym->st_shndx == SHN_UNDEF)
			    s1->got->reloc->दत्त_विस्थापनम् -= परिमाण (ElfW_Rel);
		    }
                }
                यदि (for_संहिता && sym->st_shndx == SHN_UNDEF) {
		    यदि ((पूर्णाङ्क)attr->plt_विस्थापनम् < -1) {
			/* remove above bind and replace with plt */
			mo->bind_rebase[-attr->plt_विस्थापनम् - 2].bind = 2;
			attr->plt_विस्थापनम् = -1;
		    }
                    यदि (attr->plt_विस्थापनम् == -1) {
                        uint8_t *jmp;

                        attr->plt_विस्थापनम् = mo->stubs->दत्त_विस्थापनम्;
#यदि_परिभाषितम् TCC_TARGET_X86_64
                        यदि (type != R_X86_64_PLT32)
                             अनुवर्त;
                        jmp = section_ptr_सङ्कलय(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *ofs(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_विस्थापनम् + 2,
                                      R_X86_64_GOTPCREL, sym_सूचकांक);
#नोचेद्यदि defined TCC_TARGET_ARM64
                        यदि (type != R_AARCH64_CALL26)
                             अनुवर्त;
                        jmp = section_ptr_सङ्कलय(mo->stubs, 12);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_विस्थापनम्,
                                      R_AARCH64_ADR_GOT_PAGE, sym_सूचकांक);
                        write32le(jmp, // adrp x16, #sym
                                  0x90000010);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_विस्थापनम् + 4,
                                      R_AARCH64_LD64_GOT_LO12_NC, sym_सूचकांक);
                        write32le(jmp + 4, // ld x16,[x16, #sym]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);
#यदि_अन्तः
			bind_rebase_सङ्कलय(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
                        pi = section_ptr_सङ्कलय(mo->indirsyms, परिमाण(*pi));
                        *pi = mo->e2msym[sym_सूचकांक];
                        mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_विस्थापनम्;
                }
            }
	    यदि (type == R_दत्त_PTR || type == R_JMP_SLOT)
		bind_rebase_सङ्कलय(mo, sym->st_shndx == SHN_UNDEF ? 1 : 0,
				s->sh_info, &save_rel, रिक्त);
        }
    }
    /* remove deleted binds */
    प्रति (i = 0, j = 0; i < mo->n_bind_rebase; i++)
	यदि (mo->bind_rebase[i].bind == 2)
	    mo->n_bind--;
	अन्यथा
	    mo->bind_rebase[j++] = mo->bind_rebase[i];
    mo->n_bind_rebase = j;
    pi = section_ptr_सङ्कलय(mo->indirsyms, mo->n_got * परिमाण(*pi));
    स्मृतिं_प्रतिलिख(pi, goti, mo->n_got * परिमाण(*pi));
    tcc_free(goti);
}

#अन्यथा

स्थिर शून्य check_relocs(TCCState *s1, संरचना macho *mo)
{
    uint8_t *jmp;
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    पूर्णाङ्क i, type, gotplt_प्रविष्टिः, sym_सूचकांक, for_संहिता;
    पूर्णाङ्क bind_विस्थापनम्, la_चिह्नम्_विस्थापनम्;
    uint32_t *pi, *goti;
    संरचना sym_attr *attr;

#यदि_परिभाषितम् TCC_TARGET_X86_64
    jmp = section_ptr_सङ्कलय(mo->stub_helper, 16);
    jmp[0] = 0x4c;  /* leaq _dyld_private(%rip), %r11 */
    jmp[1] = 0x8d;
    jmp[2] = 0x1d;
    put_elf_reloca(s1->symtab, mo->stub_helper, 3,
		   R_X86_64_PC32, mo->dyld_वैयक्तिकम्, -4);
    jmp[7] = 0x41;  /* pushq %r11 */
    jmp[8] = 0x53;
    jmp[9] = 0xff;  /* jmpq    *dyld_stub_binder@GOT(%rip) */
    jmp[10] = 0x25;
    put_elf_reloca(s1->symtab, mo->stub_helper, 11,
		   R_X86_64_GOTPCREL, mo->dyld_stub_binder, -4);
    jmp[15] = 0x90; /* nop */
#नोचेद्यदि defined TCC_TARGET_ARM64
    jmp = section_ptr_सङ्कलय(mo->stub_helper, 24);
    put_elf_reloc(s1->symtab, mo->stub_helper, 0,
		  R_AARCH64_ADR_PREL_PG_HI21, mo->dyld_वैयक्तिकम्);
    write32le(jmp, 0x90000011); // adrp x17, _dyld_private@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 4,
		  R_AARCH64_LDST64_ABS_LO12_NC, mo->dyld_वैयक्तिकम्);
    write32le(jmp + 4, 0x91000231); // add x17,x17,_dyld_private@pageoff
    write32le(jmp + 8, 0xa9bf47f0); // stp x16/x17, [sp, #-16]!
    put_elf_reloc(s1->symtab, mo->stub_helper, 12,
		  R_AARCH64_ADR_GOT_PAGE, mo->dyld_stub_binder);
    write32le(jmp + 12, 0x90000010); // adrp x16, dyld_stub_binder@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 16,
		  R_AARCH64_LD64_GOT_LO12_NC, mo->dyld_stub_binder);
    write32le(jmp + 16, 0xf9400210); // ldr x16,[x16,dyld_stub_binder@pageoff]
    write32le(jmp + 20, 0xd61f0200); // br x16
#यदि_अन्तः
    
    goti = रिक्त;
    mo->nr_plt = mo->n_got = 0;
    प्रति (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        यदि (s->sh_type != SHT_RELX ||
	    !वाक्ये_तुलय(s1->sections[s->sh_info]->name, ".debug_", 7))
            अनुवर्त;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_प्रविष्टिः = gotplt_प्रविष्टिः_type(type);
            for_संहिता = संहिता_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
            यदि (sym->st_shndx == SHN_UNDEF
                || gotplt_प्रविष्टिः == ALWAYS_GOTPLT_प्रविष्टिः) {
                attr = get_sym_attr(s1, sym_सूचकांक, 1);
                यदि (!attr->dyn_सूचकांक) {
                    attr->got_विस्थापनम् = s1->got->दत्त_विस्थापनम्;
                    attr->plt_विस्थापनम् = -1;
                    attr->dyn_सूचकांक = 1; /* used as flag */
		    section_ptr_सङ्कलय(s1->got, PTR_आकार);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_विस्थापनम्,
                                  R_JMP_SLOT, sym_सूचकांक);
		    goti = tcc_realloc(goti, (mo->n_got + 1) * परिमाण(*goti));
                    यदि (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        यदि (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (वर्ण *) symtab_section->link->दत्त + sym->st_name);
			goti[mo->n_got++] = परोक्षम्_चिह्नम्_LOCAL;
                    } अन्यथा {
			goti[mo->n_got++] = mo->e2msym[sym_सूचकांक];
			यदि (sym->st_shndx == SHN_UNDEF
#यदि_परिभाषितम् TCC_TARGET_X86_64
			    && type == R_X86_64_GOTPCREL
#नोचेद्यदि defined TCC_TARGET_ARM64
			    && type == R_AARCH64_ADR_GOT_PAGE
#यदि_अन्तः
			    ) {
			    mo->bind =
			        tcc_realloc(mo->bind,
					    (mo->n_bind + 1) *
					    परिमाण(संरचना bind));
			    mo->bind[mo->n_bind].section = s1->got->reloc->sh_info;
			    mo->bind[mo->n_bind].rel = save_rel;
                            mo->bind[mo->n_bind].rel.r_विस्थापनम् = attr->got_विस्थापनम्;
			    mo->n_bind++;
			    s1->got->reloc->दत्त_विस्थापनम् -= परिमाण (ElfW_Rel);
			}
		    }
                }
                यदि (for_संहिता && sym->st_shndx == SHN_UNDEF) {
                    यदि (attr->plt_विस्थापनम् == -1) {
                        attr->plt_विस्थापनम् = mo->stubs->दत्त_विस्थापनम्;
#यदि_परिभाषितम् TCC_TARGET_X86_64
			यदि (type != R_X86_64_PLT32)
			     अनुवर्त;
			/* __stubs */
                        jmp = section_ptr_सङ्कलय(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *__la_symbol_ptr(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->दत्त_विस्थापनम् - 4,
                                       R_X86_64_PC32, mo->lasym,
				       mo->la_चिह्नम्_ptr->दत्त_विस्थापनम् - 4);

			/* __stub_helper */
			bind_विस्थापनम् = mo->stub_helper->दत्त_विस्थापनम् + 1;
                        jmp = section_ptr_सङ्कलय(mo->stub_helper, 10);
                        jmp[0] = 0x68;  /* pushq $bind_offset */
                        jmp[5] = 0xe9;  /* jmpq __stub_helper */
                        write32le(jmp + 6, -mo->stub_helper->दत्त_विस्थापनम्);

			/* __la_symbol_ptr */
			la_चिह्नम्_विस्थापनम् = mo->la_चिह्नम्_ptr->दत्त_विस्थापनम्;
                        put_elf_reloca(s1->symtab, mo->la_चिह्नम्_ptr,
				       mo->la_चिह्नम्_ptr->दत्त_विस्थापनम्,
				       R_दत्त_PTR, mo->helpsym,
				       mo->stub_helper->दत्त_विस्थापनम् - 10);
			section_ptr_सङ्कलय(mo->la_चिह्नम्_ptr, PTR_आकार);
#नोचेद्यदि defined TCC_TARGET_ARM64
			यदि (type != R_AARCH64_CALL26)
			     अनुवर्त;
			/* __stubs */
                        jmp = section_ptr_सङ्कलय(mo->stubs, 12);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->दत्त_विस्थापनम् - 12,
                                       R_AARCH64_ADR_PREL_PG_HI21, mo->lasym,
				       mo->la_चिह्नम्_ptr->दत्त_विस्थापनम्);
                        write32le(jmp, // adrp x16, __la_symbol_ptr@page
                                  0x90000010);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->दत्त_विस्थापनम् - 8,
                                       R_AARCH64_LDST64_ABS_LO12_NC, mo->lasym,
				       mo->la_चिह्नम्_ptr->दत्त_विस्थापनम्);
                        write32le(jmp + 4, // ldr x16,[x16, __la_symbol_ptr@pageoff]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);

			/* __stub_helper */
			bind_विस्थापनम् = mo->stub_helper->दत्त_विस्थापनम् + 8;
                        jmp = section_ptr_सङ्कलय(mo->stub_helper, 12);
                        write32le(jmp + 0, // ldr  w16, l0
                                  0x18000050);
                        write32le(jmp + 4, // b stubHelperHeader
                                  0x14000000 +
				  ((-(mo->stub_helper->दत्त_विस्थापनम् - 8) / 4) &
				   0x3ffffff));
                        write32le(jmp + 8, 0); // l0: .long bind_offset

			/* __la_symbol_ptr */
			la_चिह्नम्_विस्थापनम् = mo->la_चिह्नम्_ptr->दत्त_विस्थापनम्;
                        put_elf_reloca(s1->symtab, mo->la_चिह्नम्_ptr,
				       mo->la_चिह्नम्_ptr->दत्त_विस्थापनम्,
				       R_दत्त_PTR, mo->helpsym,
				       mo->stub_helper->दत्त_विस्थापनम् - 12);
			section_ptr_सङ्कलय(mo->la_चिह्नम्_ptr, PTR_आकार);
#यदि_अन्तः
                        mo->s_lazy_bind =
                            tcc_realloc(mo->s_lazy_bind, (mo->n_lazy_bind + 1) *
                                        परिमाण(संरचना s_lazy_bind));
                        mo->s_lazy_bind[mo->n_lazy_bind].section =
                            mo->stub_helper->reloc->sh_info;
                        mo->s_lazy_bind[mo->n_lazy_bind].bind_विस्थापनम् =
			    bind_विस्थापनम्;
                        mo->s_lazy_bind[mo->n_lazy_bind].la_चिह्नम्_विस्थापनम् =
			    la_चिह्नम्_विस्थापनम्;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel = save_rel;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel.r_विस्थापनम् =
                            attr->plt_विस्थापनम्;
                        mo->n_lazy_bind++;
			pi = section_ptr_सङ्कलय(mo->indirsyms, परिमाण(*pi));
			*pi = mo->e2msym[sym_सूचकांक];
			mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_विस्थापनम्;
                }
            }
            यदि (type == R_दत्त_PTR || type == R_JMP_SLOT) {
		यदि (sym->st_shndx == SHN_UNDEF) {
		    mo->bind = tcc_realloc(mo->bind,
					   (mo->n_bind + 1) *
					   परिमाण(संरचना bind));
		    mo->bind[mo->n_bind].section = s->sh_info;
		    mo->bind[mo->n_bind].rel = save_rel;
		    mo->n_bind++;
		}
		अन्यथा {
                    mo->s_rebase =
                        tcc_realloc(mo->s_rebase, (mo->n_rebase + 1) *
				    परिमाण(संरचना s_rebase));
                    mo->s_rebase[mo->n_rebase].section = s->sh_info;
                    mo->s_rebase[mo->n_rebase].rel = save_rel;
                    mo->n_rebase++;
		}
	    }
        }
    }
    pi = section_ptr_सङ्कलय(mo->indirsyms, mo->n_got * परिमाण(*pi));
    स्मृतिं_प्रतिलिख(pi, goti, mo->n_got * परिमाण(*pi));
    pi = section_ptr_सङ्कलय(mo->indirsyms, mo->nr_plt * परिमाण(*pi));
    स्मृतिं_प्रतिलिख(pi, mo->indirsyms->दत्त, mo->nr_plt * परिमाण(*pi));
    tcc_free(goti);
}
#यदि_अन्तः

स्थिर पूर्णाङ्क check_symbols(TCCState *s1, संरचना macho *mo)
{
    पूर्णाङ्क sym_सूचकांक, sym_अन्तः;
    पूर्णाङ्क ret = 0;

    mo->ilocal = mo->iextdef = mo->iundef = -1;
    sym_अन्तः = symtab_section->दत्त_विस्थापनम् / परिमाण(ElfW(Sym));
    प्रति (sym_सूचकांक = 1; sym_सूचकांक < sym_अन्तः; ++sym_सूचकांक) {
        पूर्णाङ्क elf_सूचकांक = ((संरचना nlist_64 *)mo->symtab->दत्त + sym_सूचकांक - 1)->n_मानम्;
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->दत्त + elf_सूचकांक;
        ध्रुव वर्ण *name = (वर्ण*)symtab_section->link->दत्त + sym->st_name;
        अचिह्नित type = ELFW(ST_TYPE)(sym->st_info);
        अचिह्नित bind = ELFW(ST_BIND)(sym->st_info);
        अचिह्नित vis  = ELFW(ST_VISIBILITY)(sym->st_other);

        dprintf("%4d (%4d): %09lx %4d %4d %4d %3d %s\n",
                sym_सूचकांक, elf_सूचकांक, (दीर्घ)sym->st_मानम्,
                type, bind, vis, sym->st_shndx, name);
        यदि (bind == STB_LOCAL) {
            यदि (mo->ilocal == -1)
              mo->ilocal = sym_सूचकांक - 1;
            यदि (mo->iextdef != -1 || mo->iundef != -1)
              tcc_error("local syms after global ones");
        } अन्यथा यदि (sym->st_shndx != SHN_UNDEF) {
            यदि (mo->iextdef == -1)
              mo->iextdef = sym_सूचकांक - 1;
            यदि (mo->iundef != -1)
              tcc_error("external defined symbol after undefined");
        } अन्यथा यदि (sym->st_shndx == SHN_UNDEF) {
            यदि (mo->iundef == -1)
              mo->iundef = sym_सूचकांक - 1;
            यदि (ELFW(ST_BIND)(sym->st_info) == STB_WEAK
		|| s1->output_type != TCC_OUTPUT_EXE
                || find_elf_sym(s1->dynsymtab_section, name)) {
                /* Mark the symbol as coming from a dylib so that
                   relocate_syms doesn't complain.  Normally bind_exe_dynsyms
                   would do this check, and place the symbol into dynsym
                   which is checked by relocate_syms.  But Mach-O doesn't use
                   bind_exe_dynsyms.  */
                sym->st_shndx = SHN_FROMDLL;
                अनुवर्त;
            }
            tcc_error_noabort("unresolved reference to '%s'", name);
            ret = -1;
        }
    }
    प्रत्यागम ret;
}

स्थिर शून्य convert_चिह्नम्(TCCState *s1, संरचना macho *mo, संरचना nlist_64 *pn)
{
    संरचना nlist_64 n = *pn;
    ElfSym *sym = (ElfW(Sym) *)symtab_section->दत्त + pn->n_मानम्;
    ध्रुव वर्ण *name = (वर्ण*)symtab_section->link->दत्त + sym->st_name;
    विकल्प(ELFW(ST_TYPE)(sym->st_info)) {
    पक्ष STT_NOTYPE:
    पक्ष STT_OBJECT:
    पक्ष STT_FUNC:
    पक्ष STT_TLS:
    पक्ष STT_SECTION:
        n.n_type = N_SECT;
        भङ्ग;
    पक्ष STT_FILE:
        n.n_type = N_ABS;
        भङ्ग;
    स्वभाव:
        tcc_error("unhandled ELF symbol type %d %s",
                  ELFW(ST_TYPE)(sym->st_info), name);
    }
    यदि (sym->st_shndx == SHN_UNDEF)
      tcc_error("should have been rewritten to SHN_FROMDLL: %s", name);
    अन्यथा यदि (sym->st_shndx == SHN_FROMDLL)
      n.n_type = N_UNDF, n.n_sect = 0;
    अन्यथा यदि (sym->st_shndx == SHN_ABS)
      n.n_type = N_ABS, n.n_sect = 0;
    अन्यथा यदि (sym->st_shndx >= SHN_LORESERVE)
      tcc_error("unhandled ELF symbol section %d %s", sym->st_shndx, name);
    अन्यथा यदि (!mo->elfsectomacho[sym->st_shndx]) {
      यदि (वाक्ये_तुलय(s1->sections[sym->st_shndx]->name, ".debug_", 7))
        tcc_error("ELF section %d(%s) not mapped into Mach-O for symbol %s",
                  sym->st_shndx, s1->sections[sym->st_shndx]->name, name);
    }
    अन्यथा
      n.n_sect = mo->elfsectomacho[sym->st_shndx];
    यदि (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL)
      n.n_type |=  N_EXT;
    अन्यथा यदि (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
      n.n_desc |= N_WEAK_REF | (n.n_type != N_UNDF ? N_WEAK_DEF : 0);
    n.n_strx = pn->n_strx;
    n.n_मानम् = sym->st_मानम्;
    *pn = n;
}

स्थिर शून्य convert_symbols(TCCState *s1, संरचना macho *mo)
{
    संरचना nlist_64 *pn;
    for_each_elem(mo->symtab, 0, pn, संरचना nlist_64)
        convert_चिह्नम्(s1, mo, pn);
}

स्थिर पूर्णाङ्क machosymcmp(ध्रुव शून्य *_a, ध्रुव शून्य *_b, शून्य *arg)
{
    TCCState *s1 = arg;
    पूर्णाङ्क ea = ((संरचना nlist_64 *)_a)->n_मानम्;
    पूर्णाङ्क eb = ((संरचना nlist_64 *)_b)->n_मानम्;
    ElfSym *sa = (ElfSym *)symtab_section->दत्त + ea;
    ElfSym *sb = (ElfSym *)symtab_section->दत्त + eb;
    पूर्णाङ्क r;
    /* locals, then defined externals, then undefined externals, the
       last two sections also by name, otherwise stable sort */
    r = (ELFW(ST_BIND)(sb->st_info) == STB_LOCAL)
        - (ELFW(ST_BIND)(sa->st_info) == STB_LOCAL);
    यदि (r)
      प्रत्यागम r;
    r = (sa->st_shndx == SHN_UNDEF) - (sb->st_shndx == SHN_UNDEF);
    यदि (r)
      प्रत्यागम r;
    यदि (ELFW(ST_BIND)(sa->st_info) != STB_LOCAL) {
        ध्रुव वर्ण * na = (वर्ण*)symtab_section->link->दत्त + sa->st_name;
        ध्रुव वर्ण * nb = (वर्ण*)symtab_section->link->दत्त + sb->st_name;
        r = वाक्यं_तुलय(na, nb);
        यदि (r)
          प्रत्यागम r;
    }
    प्रत्यागम ea - eb;
}

/* cannot use qsort because code has to be reentrant */
स्थिर शून्य tcc_qsort (शून्य  *आधारः, आकार_t nel, आकार_t विस्तारः,
                       पूर्णाङ्क (*comp)(ध्रुव शून्य *, ध्रुव शून्य *, शून्य *), शून्य *arg)
{
    आकार_t wnel, gap, wgap, i, j, k;
    वर्ण *a, *b, tmp;

    wnel = विस्तारः * nel;
    प्रति (gap = 0; ++gap < nel;)
        gap *= 3;
    यावत् ( gap /= 3 ) {
        wgap = विस्तारः * gap;
        प्रति (i = wgap; i < wnel; i += विस्तारः) {
            प्रति (j = i - wgap; ;j -= wgap) {
                a = j + (वर्ण *)आधारः;
                b = a + wgap;
                यदि ( (*comp)(a, b, arg) <= 0 )
                    भङ्ग;
                k = विस्तारः;
                कुरु {
                    tmp = *a;
                    *a++ = *b;
                    *b++ = tmp;
                } यावत् ( --k );
                यदि (j < wgap)
                    भङ्ग;
            }
        }
    }
}

स्थिर शून्य create_symtab(TCCState *s1, संरचना macho *mo)
{
    पूर्णाङ्क sym_सूचकांक, sym_अन्तः;
    संरचना nlist_64 *pn;

    /* Stub creation belongs to check_relocs, but we need to create
       the symbol now, so its included in the sorting.  */
    mo->stubs = new_section(s1, "__stubs", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->stubsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stubs->sh_अङ्कः, ".__stubs");
#यदि_परिभाषितम् CONFIG_NEW_MACHO
    mo->chained_fixups = new_section(s1, "CHAINED_FIXUPS",
				     SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#अन्यथा
    mo->stub_helper = new_section(s1, "__stub_helper", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    mo->la_चिह्नम्_ptr = new_section(s1, "__la_symbol_ptr", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->helpsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stub_helper->sh_अङ्कः, ".__stub_helper");
    mo->lasym = put_elf_sym(s1->symtab, 0, 0,
                            ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                            mo->la_चिह्नम्_ptr->sh_अङ्कः, ".__la_symbol_ptr");
    section_ptr_सङ्कलय(दत्त_section, -दत्त_section->दत्त_विस्थापनम् & (PTR_आकार - 1));
    mo->dyld_वैयक्तिकम् = put_elf_sym(s1->symtab, दत्त_section->दत्त_विस्थापनम्, PTR_आकार,
                                   ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT), 0,
                                   दत्त_section->sh_अङ्कः, ".__dyld_private");
    section_ptr_सङ्कलय(दत्त_section, PTR_आकार);
    mo->dyld_stub_binder = put_elf_sym(s1->symtab, 0, 0,
                		       ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				       SHN_UNDEF, "dyld_stub_binder");
    mo->rebase = new_section(s1, "REBASE", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->binding = new_section(s1, "BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->weak_binding = new_section(s1, "WEAK_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->lazy_binding = new_section(s1, "LAZY_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#यदि_अन्तः
    mo->exports = new_section(s1, "EXPORT", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->indirsyms = new_section(s1, "LEINDIR", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);

    mo->symtab = new_section(s1, "LESYMTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->strtab = new_section(s1, "LESTRTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    put_elf_str(mo->strtab, " "); /* Mach-O starts strtab with a space */
    sym_अन्तः = symtab_section->दत्त_विस्थापनम् / परिमाण(ElfW(Sym));
    pn = section_ptr_सङ्कलय(mo->symtab, परिमाण(*pn) * (sym_अन्तः - 1));
    प्रति (sym_सूचकांक = 1; sym_सूचकांक < sym_अन्तः; ++sym_सूचकांक) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->दत्त + sym_सूचकांक;
        ध्रुव वर्ण *name = (वर्ण*)symtab_section->link->दत्त + sym->st_name;
        pn[sym_सूचकांक - 1].n_strx = put_elf_str(mo->strtab, name);
        pn[sym_सूचकांक - 1].n_मानम् = sym_सूचकांक;
    }
    section_ptr_सङ्कलय(mo->strtab, -mo->strtab->दत्त_विस्थापनम् & (PTR_आकार - 1));
    tcc_qsort(pn, sym_अन्तः - 1, परिमाण(*pn), machosymcmp, s1);
    mo->e2msym = tcc_malloc(sym_अन्तः * परिमाण(*mo->e2msym));
    mo->e2msym[0] = -1;
    प्रति (sym_सूचकांक = 1; sym_सूचकांक < sym_अन्तः; ++sym_सूचकांक) {
        mo->e2msym[pn[sym_सूचकांक - 1].n_मानम्] = sym_सूचकांक - 1;
    }
}

ध्रुव संरचना {
    पूर्णाङ्क seg_initial;
    uint32_t flags;
    ध्रुव वर्ण *name;
} skinfo[sk_चरमः] = {
    /*[sk_unknown] =*/        { 0 },
    /*[sk_discard] =*/        { 0 },
    /*[sk_text] =*/           { 1, S_REGULAR | S_ATTR_विशुद्धम्_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS, "__text" },
    /*[sk_stubs] =*/          { 1, S_REGULAR | S_ATTR_विशुद्धम्_INSTRUCTIONS | S_चिह्नम्_STUBS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stubs" },
    /*[sk_stub_helper] =*/    { 1, S_REGULAR | S_ATTR_विशुद्धम्_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stub_helper" },
    /*[sk_ro_data] =*/        { 2, S_REGULAR, "__rodata" },
    /*[sk_uw_info] =*/        { 0 },
    /*[sk_nl_ptr] =*/         { 2, S_NON_LAZY_चिह्नम्_सूचकाः, "__got" },
    /*[sk_debug_info] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_info" },
    /*[sk_debug_abbrev] =*/   { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_abbrev" },
    /*[sk_debug_line] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line" },
    /*[sk_debug_aranges] =*/  { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_aranges" },
    /*[sk_debug_str] =*/      { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_str" },
    /*[sk_debug_line_str] =*/ { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line_str" },
    /*[sk_stab] =*/           { 4, S_REGULAR, "__stab" },
    /*[sk_stab_str] =*/       { 4, S_REGULAR, "__stab_str" },
    /*[sk_la_ptr] =*/         { 4, S_LAZY_चिह्नम्_सूचकाः, "__la_symbol_ptr" },
    /*[sk_init] =*/           { 4, S_MOD_INIT_FUNC_सूचकाः, "__mod_init_func" },
    /*[sk_fini] =*/           { 4, S_MOD_पदांशः_FUNC_सूचकाः, "__mod_term_func" },
    /*[sk_rw_data] =*/        { 4, S_REGULAR, "__data" },
    /*[sk_bss] =*/            { 4, S_ZEROFILL, "__bss" },
    /*[sk_linkedit] =*/       { 5, S_REGULAR, रिक्त },
};

#परिभाषय	START	((uint64_t)1 << 32)

ध्रुव संरचना {
    पूर्णाङ्क प्रयुक्तम्;
    ध्रुव वर्ण *name;
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

#परिभाषय	N_SEGMENT	(परिमाण(all_segment)/परिमाण(all_segment[0]))

#यदि_परिभाषितम् CONFIG_NEW_MACHO
स्थिर शून्य calc_fixup_आकार(TCCState *s1, संरचना macho *mo)
{
    पूर्णाङ्क i, आकार;

    आकार = (परिमाण(संरचना dyld_chained_fixups_शीर्षकम्) + 7) & -8;
    आकार += (परिमाण(संरचना dyld_chained_starts_अन्तर्_image) + (mo->nseg - 1) * परिमाण(uint32_t) + 7) & -8;
    प्रति (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	पूर्णाङ्क page_गणनम् = (get_segment(mo, i)->vmsize + SEG_PAGE_आकार - 1) / SEG_PAGE_आकार;
	आकार += (परिमाण(संरचना dyld_chained_starts_अन्तर्_segment) + (page_गणनम् - 1) * परिमाण(uint16_t) + 7) & -8;
    }
    आकार += mo->n_bind * परिमाण (संरचना dyld_chained_import) + 1;
    प्रति (i = 0; i < mo->n_bind_rebase; i++) {
	यदि (mo->bind_rebase[i].bind) {
	    पूर्णाङ्क sym_सूचकांक = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
	    ध्रुव वर्ण *name = (वर्ण *) symtab_section->link->दत्त + sym->st_name;
	    आकार += वाक्यदैर्घ्यम्(name) + 1;
	}
    }
    आकार = (आकार + 7) & -8;
    section_ptr_सङ्कलय(mo->chained_fixups, आकार);
}

#अन्यथा

स्थिर शून्य समुच्चयः_segment_and_विस्थापनम्(TCCState *s1, संरचना macho *mo, addr_t addr,
				   uint8_t *ptr, पूर्णाङ्क opcode,
				   Section *sec, addr_t विस्थापनम्)
{
    पूर्णाङ्क i;
    संरचना segment_command_64 *seg = रिक्त;

    प्रति (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	seg = get_segment(mo, i);
	यदि (addr >= seg->vmaddr && addr < (seg->vmaddr + seg->vmsize))
	    भङ्ग;
    }
    *ptr = opcode | i;
    write_uleb128(sec, विस्थापनम् - seg->vmaddr);
}

स्थिर शून्य bind_rebase(TCCState *s1, संरचना macho *mo)
{
    पूर्णाङ्क i;
    uint8_t *ptr;
    ElfW(Sym) *sym;
    ध्रुव वर्ण *name;

    प्रति (i = 0; i < mo->n_lazy_bind; i++) {
	पूर्णाङ्क sym_सूचकांक = ELFW(R_SYM)(mo->s_lazy_bind[i].rel.r_info);

	sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
	name = (वर्ण *) symtab_section->link->दत्त + sym->st_name;
	write32le(mo->stub_helper->दत्त +
		  mo->s_lazy_bind[i].bind_विस्थापनम्,
		  mo->lazy_binding->दत्त_विस्थापनम्);
	ptr = section_ptr_सङ्कलय(mo->lazy_binding, 1);
	समुच्चयः_segment_and_विस्थापनम्(s1, mo, mo->la_चिह्नम्_ptr->sh_addr, ptr,
			       BIND_OPCODE_समुच्चयः_SEGMENT_AND_विस्थापनम्_ULEB,
			       mo->lazy_binding,
			       mo->s_lazy_bind[i].la_चिह्नम्_विस्थापनम् +
			       mo->la_चिह्नम्_ptr->sh_addr);
	ptr = section_ptr_सङ्कलय(mo->lazy_binding, 5 + वाक्यदैर्घ्यम्(name));
	*ptr++ = BIND_OPCODE_समुच्चयः_DYLIB_SPECIAL_IMM |
		 (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
	*ptr++ = BIND_OPCODE_समुच्चयः_चिह्नम्_TRAILING_FLAGS_IMM | 0;
	वाक्यं_प्रतिलिख((वर्ण *)ptr, name);
	ptr += वाक्यदैर्घ्यम्(name) + 1;
	*ptr++ = BIND_OPCODE_DO_BIND;
	*ptr = BIND_OPCODE_समाप्तम्;
    }
    प्रति (i = 0; i < mo->n_rebase; i++) {
	Section *s = s1->sections[mo->s_rebase[i].section];

	ptr = section_ptr_सङ्कलय(mo->rebase, 2);
	*ptr++ = REBASE_OPCODE_समुच्चयः_TYPE_IMM | REBASE_TYPE_POINTER;
	समुच्चयः_segment_and_विस्थापनम्(s1, mo, s->sh_addr, ptr,
			       REBASE_OPCODE_समुच्चयः_SEGMENT_AND_विस्थापनम्_ULEB,
			       mo->rebase,
			       mo->s_rebase[i].rel.r_विस्थापनम् +
			       s->sh_addr);
	ptr = section_ptr_सङ्कलय(mo->rebase, 1);
	*ptr = REBASE_OPCODE_DO_REBASE_IMM_TIMES | 1;
    }
    प्रति (i = 0; i < mo->n_bind; i++) {
	पूर्णाङ्क sym_सूचकांक = ELFW(R_SYM)(mo->bind[i].rel.r_info);
	Section *s = s1->sections[mo->bind[i].section];
	Section *binding;

	sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
	name = (वर्ण *) symtab_section->link->दत्त + sym->st_name;
	binding = ELFW(ST_BIND)(sym->st_info) == STB_WEAK
	    ? mo->weak_binding : mo->binding;
        ptr = section_ptr_सङ्कलय(binding, 4 + (binding == mo->binding) +
			     	       वाक्यदैर्घ्यम्(name));
	यदि (binding == mo->binding)
            *ptr++ = BIND_OPCODE_समुच्चयः_DYLIB_SPECIAL_IMM |
	             (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
        *ptr++ = BIND_OPCODE_समुच्चयः_चिह्नम्_TRAILING_FLAGS_IMM |
		 (binding == mo->weak_binding
		  ? BIND_चिह्नम्_FLAGS_WEAK_IMPORT : 0);
        वाक्यं_प्रतिलिख((वर्ण *)ptr, name);
        ptr += वाक्यदैर्घ्यम्(name) + 1;
        *ptr++ = BIND_OPCODE_समुच्चयः_TYPE_IMM | BIND_TYPE_POINTER;
	समुच्चयः_segment_and_विस्थापनम्(s1, mo, s->sh_addr, ptr,
			       BIND_OPCODE_समुच्चयः_SEGMENT_AND_विस्थापनम्_ULEB,
			       binding,
			       mo->bind[i].rel.r_विस्थापनम् + s->sh_addr);
        ptr = section_ptr_सङ्कलय(binding, 1);
        *ptr++ = BIND_OPCODE_DO_BIND;
    }
    यदि (mo->rebase->दत्त_विस्थापनम्) {
        ptr = section_ptr_सङ्कलय(mo->rebase, 1);
        *ptr = REBASE_OPCODE_समाप्तम्;
    }
    यदि (mo->binding->दत्त_विस्थापनम्) {
        ptr = section_ptr_सङ्कलय(mo->binding, 1);
        *ptr = BIND_OPCODE_समाप्तम्;
    }
    यदि (mo->weak_binding->दत्त_विस्थापनम्) {
        ptr = section_ptr_सङ्कलय(mo->weak_binding, 1);
        *ptr = BIND_OPCODE_समाप्तम्;
    }
    tcc_free(mo->s_lazy_bind);
    tcc_free(mo->s_rebase);
    tcc_free(mo->bind);
}
#यदि_अन्तः

संरचना trie_info {
    ध्रुव वर्ण *name;
    पूर्णाङ्क flag;
    addr_t addr;
    पूर्णाङ्क str_आकार;
    पूर्णाङ्क पदांशः_आकार;
};

संरचना trie_ग्रन्थिः {
    पूर्णाङ्क start;
    पूर्णाङ्क अन्तः;
    पूर्णाङ्क सूचकांक_start;
    पूर्णाङ्क सूचकांक_अन्तः;
    पूर्णाङ्क n_child;
    संरचना trie_ग्रन्थिः *child;
};

संरचना trie_seq {
    पूर्णाङ्क n_child;
    संरचना trie_ग्रन्थिः *ग्रन्थिः;
    पूर्णाङ्क विस्थापनम्;
    पूर्णाङ्क nest_विस्थापनम्;
};

स्थिर शून्य create_trie(संरचना trie_ग्रन्थिः *ग्रन्थिः,
                        पूर्णाङ्क from, पूर्णाङ्क गन्तव्यम्, पूर्णाङ्क सूचकांक_start,
                        पूर्णाङ्क n_trie, संरचना trie_info *trie)
{
    पूर्णाङ्क i;
    पूर्णाङ्क start, अन्तः, सूचकांक_अन्तः;
    वर्ण cur;
    संरचना trie_ग्रन्थिः *child;

    प्रति (i = from; i < गन्तव्यम्; i = अन्तः) {
        cur = trie[i].name[सूचकांक_start];
        start = i++;
        प्रति (; i < गन्तव्यम्; i++)
            यदि (cur != trie[i].name[सूचकांक_start])
                भङ्ग;
        अन्तः = i;
        यदि (start == अन्तः - 1 ||
            (trie[start].name[सूचकांक_start] &&
             trie[start].name[सूचकांक_start + 1] == 0))
            सूचकांक_अन्तः = trie[start].str_आकार - 1;
        अन्यथा {
            सूचकांक_अन्तः = सूचकांक_start + 1;
            प्रति (;;) {
                cur = trie[start].name[सूचकांक_अन्तः];
                प्रति (i = start + 1; i < अन्तः; i++)
                    यदि (cur != trie[i].name[सूचकांक_अन्तः])
                        भङ्ग;
                यदि (trie[start].name[सूचकांक_अन्तः] &&
                    trie[start].name[सूचकांक_अन्तः + 1] == 0) {
                    अन्तः = start + 1;
                    सूचकांक_अन्तः = trie[start].str_आकार - 1;
                    भङ्ग;
                }
                यदि (i != अन्तः)
                    भङ्ग;
                सूचकांक_अन्तः++;
            }
        }
        ग्रन्थिः->child = tcc_realloc(ग्रन्थिः->child,
                                  (ग्रन्थिः->n_child + 1) *
                                  परिमाण(संरचना trie_ग्रन्थिः));
        child = &ग्रन्थिः->child[ग्रन्थिः->n_child];
        child->start = start;
        child->अन्तः = अन्तः;
        child->सूचकांक_start = सूचकांक_start;
        child->सूचकांक_अन्तः = सूचकांक_अन्तः;
        child->n_child = 0;
        child->child = रिक्त;
        ग्रन्थिः->n_child++;
        यदि (start != अन्तः - 1)
            create_trie(child, start, अन्तः, सूचकांक_अन्तः, n_trie, trie);
    }
}

स्थिर पूर्णाङ्क create_seq(पूर्णाङ्क *विस्थापनम्, पूर्णाङ्क *n_seq, संरचना trie_seq **seq,
                        संरचना trie_ग्रन्थिः *ग्रन्थिः,
                        पूर्णाङ्क n_trie, संरचना trie_info *trie)
{
    पूर्णाङ्क i, nest_विस्थापनम्, चरमः_seq = *n_seq, retval = *विस्थापनम्;
    संरचना trie_seq *p_seq;
    संरचना trie_ग्रन्थिः *p_nest;

    प्रति (i = 0; i < ग्रन्थिः->n_child; i++) {
        p_nest = &ग्रन्थिः->child[i];
        *seq = tcc_realloc(*seq, (*n_seq + 1) * परिमाण(संरचना trie_seq));
        p_seq = &(*seq)[(*n_seq)++];
        p_seq->n_child = i == 0 ? ग्रन्थिः->n_child : -1;
        p_seq->ग्रन्थिः = p_nest;
        p_seq->विस्थापनम् = *विस्थापनम्;
        p_seq->nest_विस्थापनम् = 0;
        *विस्थापनम् += (i == 0 ? 1 + 1 : 0) +
                   p_nest->सूचकांक_अन्तः - p_nest->सूचकांक_start + 1 + 3;
    }
    प्रति (i = 0; i < ग्रन्थिः->n_child; i++) {
        nest_विस्थापनम् =
            create_seq(विस्थापनम्, n_seq, seq, &ग्रन्थिः->child[i], n_trie, trie);
        p_seq = &(*seq)[चरमः_seq + i];
        p_seq->nest_विस्थापनम् = nest_विस्थापनम्;
    }
    प्रत्यागम retval;
}

स्थिर शून्य ग्रन्थिः_free(संरचना trie_ग्रन्थिः *ग्रन्थिः)
{
    पूर्णाङ्क i;

    प्रति (i = 0; i < ग्रन्थिः->n_child; i++)
	ग्रन्थिः_free(&ग्रन्थिः->child[i]);
    tcc_free(ग्रन्थिः->child);
}

स्थिर पूर्णाङ्क triecmp(ध्रुव शून्य *_a, ध्रुव शून्य *_b, शून्य *arg)
{
    संरचना trie_info *a = (संरचना trie_info *) _a;
    संरचना trie_info *b = (संरचना trie_info *) _b;
    पूर्णाङ्क len_a = वाक्यदैर्घ्यम्(a->name);
    पूर्णाङ्क len_b = वाक्यदैर्घ्यम्(b->name);

    /* strange sorting needed. Name 'xx' should be after 'xx1' */
    यदि (!वाक्ये_तुलय(a->name, b->name, len_a < len_b ? len_a : len_b))
	प्रत्यागम len_a < len_b ? 1 : (len_a > len_b ? -1 : 0);
    प्रत्यागम वाक्यं_तुलय(a->name, b->name);
}

स्थिर शून्य export_trie(TCCState *s1, संरचना macho *mo)
{
    पूर्णाङ्क i, आकार, विस्थापनम् = 0, save_विस्थापनम्;
    uint8_t *ptr;
    पूर्णाङ्क sym_सूचकांक;
    पूर्णाङ्क sym_अन्तः = symtab_section->दत्त_विस्थापनम् / परिमाण(ElfW(Sym));
    पूर्णाङ्क n_trie = 0, n_seq = 0;
    संरचना trie_info *trie = रिक्त, *p_trie;
    संरचना trie_ग्रन्थिः ग्रन्थिः, *p_ग्रन्थिः;
    संरचना trie_seq *seq = रिक्त;
    addr_t vm_addr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;

    प्रति (sym_सूचकांक = 1; sym_सूचकांक < sym_अन्तः; ++sym_सूचकांक) {
	ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->दत्त + sym_सूचकांक;
	ध्रुव वर्ण *name = (वर्ण*)symtab_section->link->दत्त + sym->st_name;

	यदि (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE &&
            (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL ||
	     ELFW(ST_BIND)(sym->st_info) == STB_WEAK)) {
	    पूर्णाङ्क flag = EXPORT_चिह्नम्_FLAGS_विधा_REGULAR;
	    addr_t addr =
		sym->st_मानम् + s1->sections[sym->st_shndx]->sh_addr - vm_addr;

	    यदि (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
		flag |= EXPORT_चिह्नम्_FLAGS_WEAK_DEFINITION;
	    dprintf ("%s %d %llx\n", name, flag, (दीर्घ दीर्घ)addr + vm_addr);
	    trie = tcc_realloc(trie, (n_trie + 1) * परिमाण(संरचना trie_info));
	    trie[n_trie].name = name;
	    trie[n_trie].flag = flag;
	    trie[n_trie].addr = addr;
	    trie[n_trie].str_आकार = वाक्यदैर्घ्यम्(name) + 1;
	    trie[n_trie].पदांशः_आकार = uleb128_आकार(flag) + uleb128_आकार(addr);
	    n_trie++;
	}
    }
    यदि (n_trie) {
        tcc_qsort(trie, n_trie, परिमाण(संरचना trie_info), triecmp, रिक्त);
	स्मृतिं_पूरय(&ग्रन्थिः, 0, परिमाण(ग्रन्थिः));
        create_trie(&ग्रन्थिः, 0, n_trie, 0, n_trie, trie);
	create_seq(&विस्थापनम्, &n_seq, &seq, &ग्रन्थिः, n_trie, trie);
        save_विस्थापनम् = विस्थापनम्;
        प्रति (i = 0; i < n_seq; i++) {
            p_ग्रन्थिः = seq[i].ग्रन्थिः;
            यदि (p_ग्रन्थिः->n_child == 0) {
                p_trie = &trie[p_ग्रन्थिः->start];
                seq[i].nest_विस्थापनम् = विस्थापनम्;
                विस्थापनम् += 1 + p_trie->पदांशः_आकार + 1;
            }
        }
        प्रति (i = 0; i < n_seq; i++) {
            p_ग्रन्थिः = seq[i].ग्रन्थिः;
            p_trie = &trie[p_ग्रन्थिः->start];
            यदि (seq[i].n_child >= 0) {
                section_ptr_सङ्कलय(mo->exports,
				seq[i].विस्थापनम् - mo->exports->दत्त_विस्थापनम्);
                ptr = section_ptr_सङ्कलय(mo->exports, 2);
                *ptr++ = 0;
                *ptr = seq[i].n_child;
            }
            आकार = p_ग्रन्थिः->सूचकांक_अन्तः - p_ग्रन्थिः->सूचकांक_start;
            ptr = section_ptr_सङ्कलय(mo->exports, आकार + 1);
            स्मृतिं_प्रतिलिख(ptr, &p_trie->name[p_ग्रन्थिः->सूचकांक_start], आकार);
            ptr[आकार] = 0;
            write_uleb128(mo->exports, seq[i].nest_विस्थापनम्);
        }
        section_ptr_सङ्कलय(mo->exports, save_विस्थापनम् - mo->exports->दत्त_विस्थापनम्);
        प्रति (i = 0; i < n_seq; i++) {
            p_ग्रन्थिः = seq[i].ग्रन्थिः;
            यदि (p_ग्रन्थिः->n_child == 0) {
                p_trie = &trie[p_ग्रन्थिः->start];
                write_uleb128(mo->exports, p_trie->पदांशः_आकार);
                write_uleb128(mo->exports, p_trie->flag);
                write_uleb128(mo->exports, p_trie->addr);
                ptr = section_ptr_सङ्कलय(mo->exports, 1);
                *ptr = 0;
            }
        }
        section_ptr_सङ्कलय(mo->exports, -mo->exports->दत्त_विस्थापनम् & 7);
	ग्रन्थिः_free(&ग्रन्थिः);
        tcc_free(seq);
    }
    tcc_free(trie);
}

स्थिर शून्य collect_sections(TCCState *s1, संरचना macho *mo, ध्रुव वर्ण *filename)
{
    पूर्णाङ्क i, sk, numsec;
    पूर्णाङ्क प्रयुक्तम्_segment[N_SEGMENT];
    uint64_t curaddr, fileofs;
    Section *s;
    संरचना segment_command_64 *seg;
    संरचना dylib_command *dylib;
#यदि_परिभाषितम् CONFIG_NEW_MACHO
    संरचना linkedit_दत्त_command *chained_fixups_lc;
    संरचना linkedit_दत्त_command *export_trie_lc;
#यदि_अन्तः
    संरचना build_संस्करणम्_command *dyldbv;
    संरचना source_संस्करणम्_command *dyldsv;
    संरचना rpath_command *rpath;
    संरचना dylinker_command *dyldlc;
    संरचना symtab_command *symlc;
    संरचना dysymtab_command *dysymlc;
    वर्ण *str;

    प्रति (i = 0; i < N_SEGMENT; i++)
	प्रयुक्तम्_segment[i] = all_segment[i].प्रयुक्तम्;

    स्मृतिं_पूरय (mo->sk_गन्तव्यम्_sect, 0, परिमाण(mo->sk_गन्तव्यम्_sect));
    प्रति (i = s1->nb_sections; i-- > 1;) {
        पूर्णाङ्क type, flags;
        s = s1->sections[i];
        type = s->sh_type;
        flags = s->sh_flags;
        sk = sk_unknown;
	/* debug sections have sometimes no SHF_ALLOC */
        यदि ((flags & SHF_ALLOC) || !वाक्ये_तुलय(s->name, ".debug_", 7)) {
            विकल्प (type) {
            स्वभाव:           sk = sk_unknown; भङ्ग;
            पक्ष SHT_INIT_ARRAY: sk = sk_init; भङ्ग;
            पक्ष SHT_FINI_ARRAY: sk = sk_fini; भङ्ग;
            पक्ष SHT_NOBITS:   sk = sk_bss; भङ्ग;
            पक्ष SHT_SYMTAB:   sk = sk_discard; भङ्ग;
            पक्ष SHT_STRTAB:
		यदि (s == stabstr_section)
		  sk = sk_stab_str;
		अन्यथा
		  sk = sk_discard;
		भङ्ग;
            पक्ष SHT_RELX:     sk = sk_discard; भङ्ग;
            पक्ष SHT_LINKEDIT: sk = sk_linkedit; भङ्ग;
            पक्ष SHT_PROGBITS:
                यदि (s == mo->stubs)
                  sk = sk_stubs;
#यदि_अपरिभाषितम् CONFIG_NEW_MACHO
                अन्यथा यदि (s == mo->stub_helper)
                  sk = sk_stub_helper;
                अन्यथा यदि (s == mo->la_चिह्नम्_ptr)
                  sk = sk_la_ptr;
#यदि_अन्तः
                अन्यथा यदि (s == rodata_section)
                  sk = sk_ro_दत्त;
                अन्यथा यदि (s == s1->got)
                  sk = sk_nl_ptr;
                अन्यथा यदि (s == stab_section)
                  sk = sk_stab;
                अन्यथा यदि (s == dwarf_info_section)
                  sk = sk_debug_info;
                अन्यथा यदि (s == dwarf_abbrev_section)
                  sk = sk_debug_abbrev;
                अन्यथा यदि (s == dwarf_पङ्क्तिः_section)
                  sk = sk_debug_पङ्क्तिः;
                अन्यथा यदि (s == dwarf_aranges_section)
                  sk = sk_debug_aranges;
                अन्यथा यदि (s == dwarf_str_section)
                  sk = sk_debug_str;
                अन्यथा यदि (s == dwarf_पङ्क्तिः_str_section)
                  sk = sk_debug_पङ्क्तिः_str;
                अन्यथा यदि (flags & SHF_EXECINSTR)
                  sk = sk_text;
                अन्यथा यदि (flags & SHF_WRITE)
                  sk = sk_rw_दत्त;
                अन्यथा
                  sk = sk_ro_दत्त;
                भङ्ग;
            }
        } अन्यथा
          sk = sk_discard;
        s->पूर्व = mo->sk_गन्तव्यम्_sect[sk].s;
        mo->sk_गन्तव्यम्_sect[sk].s = s;
	प्रयुक्तम्_segment[skinfo[sk].seg_initial] = 1;
    }

    यदि (s1->output_type != TCC_OUTPUT_EXE)
	प्रयुक्तम्_segment[0] = 0;

    प्रति (i = 0; i < N_SEGMENT; i++)
	यदि (प्रयुक्तम्_segment[i]) {
	    seg = सङ्कलय_segment(mo, all_segment[i].name);
	    यदि (i == 1 && s1->output_type != TCC_OUTPUT_EXE)
	        seg->vmaddr = 0;
	    अन्यथा
	        seg->vmaddr = all_segment[i].vmaddr;
	    seg->vmsize = all_segment[i].vmsize;
	    seg->maxprot = all_segment[i].maxprot;
	    seg->initprot = all_segment[i].initprot;
	    seg->flags = all_segment[i].flags;
            प्रति (sk = sk_unknown; sk < sk_चरमः; sk++)
		यदि (skinfo[sk].seg_initial == i)
	            mo->segment[sk] = mo->nseg - 1;
	}

    यदि (s1->output_type != TCC_OUTPUT_EXE) {
	ध्रुव वर्ण *name = s1->install_name ? s1->install_name : filename;
        i = (परिमाण(*dylib) + वाक्यदैर्घ्यम्(name) + 1 + 7) &-8;
        dylib = सङ्कलय_lc(mo, LC_ID_DYLIB, i);
	dylib->name = परिमाण(*dylib);
	dylib->timestamp = 1;
	dylib->current_संस्करणम् =
	    s1->current_संस्करणम् ? s1->current_संस्करणम् : 1 << 16;
	dylib->compatibility_संस्करणम् =
	    s1->compatibility_संस्करणम् ? s1->compatibility_संस्करणम् : 1 << 16;
        str = (वर्ण*)dylib + dylib->name;
        वाक्यं_प्रतिलिख(str, name);
    }

#यदि_परिभाषितम् CONFIG_NEW_MACHO
    chained_fixups_lc = सङ्कलय_lc(mo, LC_DYLD_CHAINED_FIXUPS,
			       परिमाण(संरचना linkedit_दत्त_command));
    export_trie_lc = सङ्कलय_lc(mo, LC_DYLD_EXPORTS_TRIE,
			    परिमाण(संरचना linkedit_दत्त_command));
#अन्यथा
    mo->dyldinfo = सङ्कलय_lc(mo, LC_DYLD_INFO_ONLY, परिमाण(*mo->dyldinfo));
#यदि_अन्तः

    symlc = सङ्कलय_lc(mo, LC_SYMTAB, परिमाण(*symlc));
    dysymlc = सङ्कलय_lc(mo, LC_DYSYMTAB, परिमाण(*dysymlc));

    यदि (s1->output_type == TCC_OUTPUT_EXE) {
        i = (परिमाण(*dyldlc) + वाक्यदैर्घ्यम्("/usr/lib/dyld") + 1 + 7) &-8;
        dyldlc = सङ्कलय_lc(mo, LC_आरोपय_DYLINKER, i);
        dyldlc->name = परिमाण(*dyldlc);
        str = (वर्ण*)dyldlc + dyldlc->name;
        वाक्यं_प्रतिलिख(str, "/usr/lib/dyld");
    }

    dyldbv = सङ्कलय_lc(mo, LC_BUILD_संस्करणम्, परिमाण(*dyldbv));
    dyldbv->platform = PLATFORM_MACOS;
    dyldbv->minos = (10 << 16) + (6 << 8);
    dyldbv->sdk = (10 << 16) + (6 << 8);
    dyldbv->ntools = 0;

    dyldsv = सङ्कलय_lc(mo, LC_SOURCE_संस्करणम्, परिमाण(*dyldsv));
    dyldsv->संस्करणम् = 0;

    यदि (s1->output_type == TCC_OUTPUT_EXE) {
        mo->ep = सङ्कलय_lc(mo, LC_MAIN, परिमाण(*mo->ep));
        mo->ep->entryoff = 4096;
    }

    प्रति(i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *dllref = s1->loaded_dlls[i];
        यदि (dllref->level == 0)
          सङ्कलय_dylib(mo, dllref->name);
    }

    यदि (s1->rpath) {
	वर्ण *मार्गः = s1->rpath, *अन्तः;
	कुरु {
	    अन्तः = strchr(मार्गः, ':');
	    यदि (!अन्तः)
		अन्तः = strchr(मार्गः, 0);
            i = (परिमाण(*rpath) + (अन्तः - मार्गः) + 1 + 7) &-8;
            rpath = सङ्कलय_lc(mo, LC_RPATH, i);
            rpath->मार्गः = परिमाण(*rpath);
            str = (वर्ण*)rpath + rpath->मार्गः;
            स्मृतिं_प्रतिलिख(str, मार्गः, अन्तः - मार्गः);
	    str[अन्तः - मार्गः] = 0;
	    मार्गः = अन्तः + 1;
	} यावत् (*अन्तः);
    }

    fileofs = 4096;  /* leave space for mach-o headers */
    curaddr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;
    curaddr += 4096;
    seg = रिक्त;
    numsec = 0;
    mo->elfsectomacho = tcc_mallocz(परिमाण(*mo->elfsectomacho) * s1->nb_sections);
    प्रति (sk = sk_unknown; sk < sk_चरमः; sk++) {
        संरचना section_64 *sec = रिक्त;
        यदि (seg) {
            seg->vmsize = curaddr - seg->vmaddr;
            seg->filesize = fileofs - seg->fileoff;
        }
#यदि_परिभाषितम् CONFIG_NEW_MACHO
	यदि (sk == sk_linkedit) {
	    calc_fixup_आकार(s1, mo);
	    export_trie(s1, mo);
	}
#अन्यथा
	यदि (sk == sk_linkedit) {
	    bind_rebase(s1, mo);
	    export_trie(s1, mo);
	}
#यदि_अन्तः
        यदि (skinfo[sk].seg_initial &&
	    (s1->output_type != TCC_OUTPUT_EXE || mo->segment[sk]) &&
	    mo->sk_गन्तव्यम्_sect[sk].s) {
            uint64_t al = 0;
            पूर्णाङ्क si;
            seg = get_segment(mo, mo->segment[sk]);
            यदि (skinfo[sk].name) {
                si = सङ्कलय_section(mo, &seg, skinfo[sk].name);
                numsec++;
                mo->lc[mo->seg2lc[mo->segment[sk]]] = (संरचना आरोपय_command*)seg;
                mo->sk_गन्तव्यम्_sect[sk].machosect = si;
                sec = get_section(seg, si);
                sec->flags = skinfo[sk].flags;
		यदि (sk == sk_stubs)
#यदि_परिभाषितम् TCC_TARGET_X86_64
	    	    sec->reserved2 = 6;
#नोचेद्यदि defined TCC_TARGET_ARM64
	    	    sec->reserved2 = 12;
#यदि_अन्तः
		यदि (sk == sk_nl_ptr)
	    	    sec->reserved1 = mo->nr_plt;
#यदि_अपरिभाषितम् CONFIG_NEW_MACHO
		यदि (sk == sk_la_ptr)
	    	    sec->reserved1 = mo->nr_plt + mo->n_got;
#यदि_अन्तः
            }
            यदि (seg->vmaddr == -1) {
                curaddr = (curaddr + SEG_PAGE_आकार - 1) & -SEG_PAGE_आकार;
                seg->vmaddr = curaddr;
                fileofs = (fileofs + SEG_PAGE_आकार - 1) & -SEG_PAGE_आकार;
                seg->fileoff = fileofs;
            }

            प्रति (s = mo->sk_गन्तव्यम्_sect[sk].s; s; s = s->पूर्व) {
                पूर्णाङ्क a = exact_log2p1(s->sh_addralign);
                यदि (a && al < (a - 1))
                  al = a - 1;
                s->sh_आकार = s->दत्त_विस्थापनम्;
            }
            यदि (sec)
              sec->align = al;
            al = 1ULL << al;
            यदि (al > 4096)
              tcc_warning("alignment > 4096"), sec->align = 12, al = 4096;
            curaddr = (curaddr + al - 1) & -al;
            fileofs = (fileofs + al - 1) & -al;
            यदि (sec) {
                sec->addr = curaddr;
                sec->विस्थापनम् = fileofs;
            }
            प्रति (s = mo->sk_गन्तव्यम्_sect[sk].s; s; s = s->पूर्व) {
                al = s->sh_addralign;
                curaddr = (curaddr + al - 1) & -al;
                dprintf("%s: curaddr now 0x%lx\n", s->name, (दीर्घ)curaddr);
                s->sh_addr = curaddr;
                curaddr += s->sh_आकार;
                यदि (s->sh_type != SHT_NOBITS) {
                    fileofs = (fileofs + al - 1) & -al;
                    s->sh_विस्थापनम् = fileofs;
                    fileofs += s->sh_आकार;
                    dprintf("%s: fileofs now %ld\n", s->name, (दीर्घ)fileofs);
                }
                यदि (sec)
                  mo->elfsectomacho[s->sh_अङ्कः] = numsec;
            }
            यदि (sec)
              sec->आकार = curaddr - sec->addr;
        }
        यदि (DEBUG_MACHO)
          प्रति (s = mo->sk_गन्तव्यम्_sect[sk].s; s; s = s->पूर्व) {
              पूर्णाङ्क type = s->sh_type;
              पूर्णाङ्क flags = s->sh_flags;
              प्रारूप_लिख("%d section %-16s %-10s %09lx %04x %02d %s,%s,%s\n",
                     sk,
                     s->name,
                     type == SHT_PROGBITS ? "progbits" :
                     type == SHT_NOBITS ? "nobits" :
                     type == SHT_SYMTAB ? "symtab" :
                     type == SHT_STRTAB ? "strtab" :
                     type == SHT_INIT_ARRAY ? "init" :
                     type == SHT_FINI_ARRAY ? "fini" :
                     type == SHT_RELX ? "rel" : "???",
                     (दीर्घ)s->sh_addr,
                     (अचिह्नित)s->दत्त_विस्थापनम्,
                     s->sh_addralign,
                     flags & SHF_ALLOC ? "alloc" : "",
                     flags & SHF_WRITE ? "write" : "",
                     flags & SHF_EXECINSTR ? "exec" : ""
                    );
          }
    }
    यदि (seg) {
        seg->vmsize = curaddr - seg->vmaddr;
        seg->filesize = fileofs - seg->fileoff;
    }

    /* Fill symtab info */
    symlc->symoff = mo->symtab->sh_विस्थापनम्;
    symlc->nsyms = mo->symtab->दत्त_विस्थापनम् / परिमाण(संरचना nlist_64);
    symlc->stroff = mo->strtab->sh_विस्थापनम्;
    symlc->strsize = mo->strtab->दत्त_विस्थापनम्;

    dysymlc->iundefsym = mo->iundef == -1 ? symlc->nsyms : mo->iundef;
    dysymlc->iextdefsym = mo->iextdef == -1 ? dysymlc->iundefsym : mo->iextdef;
    dysymlc->ilocalsym = mo->ilocal == -1 ? dysymlc->iextdefsym : mo->ilocal;
    dysymlc->nlocalsym = dysymlc->iextdefsym - dysymlc->ilocalsym;
    dysymlc->nextdefsym = dysymlc->iundefsym - dysymlc->iextdefsym;
    dysymlc->nundefsym = symlc->nsyms - dysymlc->iundefsym;
    dysymlc->indirectsymoff = mo->indirsyms->sh_विस्थापनम्;
    dysymlc->nindirectsyms = mo->indirsyms->दत्त_विस्थापनम् / परिमाण(uint32_t);

#यदि_परिभाषितम् CONFIG_NEW_MACHO
    यदि (mo->chained_fixups->दत्त_विस्थापनम्) {
        chained_fixups_lc->dataoff = mo->chained_fixups->sh_विस्थापनम्;
        chained_fixups_lc->datasize = mo->chained_fixups->दत्त_विस्थापनम्;
    }
    यदि (mo->exports->दत्त_विस्थापनम्) {
        export_trie_lc->dataoff = mo->exports->sh_विस्थापनम्;
        export_trie_lc->datasize = mo->exports->दत्त_विस्थापनम्;
    }
#अन्यथा
    यदि (mo->rebase->दत्त_विस्थापनम्) {
        mo->dyldinfo->rebase_off = mo->rebase->sh_विस्थापनम्;
        mo->dyldinfo->rebase_आकार = mo->rebase->दत्त_विस्थापनम्;
    }
    यदि (mo->binding->दत्त_विस्थापनम्) {
        mo->dyldinfo->bind_off = mo->binding->sh_विस्थापनम्;
        mo->dyldinfo->bind_आकार = mo->binding->दत्त_विस्थापनम्;
    }
    यदि (mo->weak_binding->दत्त_विस्थापनम्) {
        mo->dyldinfo->weak_bind_off = mo->weak_binding->sh_विस्थापनम्;
        mo->dyldinfo->weak_bind_आकार = mo->weak_binding->दत्त_विस्थापनम्;
    }
    यदि (mo->lazy_binding->दत्त_विस्थापनम्) {
        mo->dyldinfo->lazy_bind_off = mo->lazy_binding->sh_विस्थापनम्;
        mo->dyldinfo->lazy_bind_आकार = mo->lazy_binding->दत्त_विस्थापनम्;
    }
    यदि (mo->exports->दत्त_विस्थापनम्) {
        mo->dyldinfo->export_off = mo->exports->sh_विस्थापनम्;
        mo->dyldinfo->export_आकार = mo->exports->दत्त_विस्थापनम्;
    }
#यदि_अन्तः
}

स्थिर शून्य macho_write(TCCState *s1, संरचना macho *mo, FILE *fp)
{
    पूर्णाङ्क i, sk;
    uint64_t fileofs = 0;
    Section *s;
    mo->mh.mh.magic = MH_MAGIC_64;
#यदि_परिभाषितम् TCC_TARGET_X86_64
    mo->mh.mh.cputype = CPU_TYPE_X86_64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_LIB64 | CPU_SUBTYPE_X86_ALL;
#नोचेद्यदि defined TCC_TARGET_ARM64
    mo->mh.mh.cputype = CPU_TYPE_ARM64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_ARM64_ALL;
#यदि_अन्तः
    यदि (s1->output_type == TCC_OUTPUT_EXE) {
        mo->mh.mh.filetype = MH_EXECUTE;
        mo->mh.mh.flags = MH_DYLDLINK | MH_PIE;
    }
    अन्यथा {
        mo->mh.mh.filetype = MH_DYLIB;
        mo->mh.mh.flags = MH_DYLDLINK;
    }
    mo->mh.mh.ncmds = mo->nlc;
    mo->mh.mh.sizeofcmds = 0;
    प्रति (i = 0; i < mo->nlc; i++)
      mo->mh.mh.sizeofcmds += mo->lc[i]->cmdsize;

    fwrite(&mo->mh, 1, परिमाण(mo->mh), fp);
    fileofs += परिमाण(mo->mh);
    प्रति (i = 0; i < mo->nlc; i++) {
        fwrite(mo->lc[i], 1, mo->lc[i]->cmdsize, fp);
        fileofs += mo->lc[i]->cmdsize;
    }

    प्रति (sk = sk_unknown; sk < sk_चरमः; sk++) {
        //struct segment_command_64 *seg;
        यदि (skinfo[sk].seg_initial == 0 ||
	    (s1->output_type == TCC_OUTPUT_EXE && !mo->segment[sk]) ||
	    !mo->sk_गन्तव्यम्_sect[sk].s)
          अनुवर्त;
        /*seg =*/ get_segment(mo, mo->segment[sk]);
        प्रति (s = mo->sk_गन्तव्यम्_sect[sk].s; s; s = s->पूर्व) {
            यदि (s->sh_type != SHT_NOBITS) {
                यावत् (fileofs < s->sh_विस्थापनम्)
                  fputc(0, fp), fileofs++;
                यदि (s->sh_आकार) {
                    fwrite(s->दत्त, 1, s->sh_आकार, fp);
                    fileofs += s->sh_आकार;
                }
            }
        }
    }
}

#यदि_परिभाषितम् CONFIG_NEW_MACHO
स्थिर पूर्णाङ्क bind_rebase_cmp(ध्रुव शून्य *_a, ध्रुव शून्य *_b, शून्य *arg)
{
    TCCState *s1 = arg;
    संरचना bind_rebase *a = (संरचना bind_rebase *) _a;
    संरचना bind_rebase *b = (संरचना bind_rebase *) _b;
    addr_t aa = s1->sections[a->section]->sh_addr + a->rel.r_विस्थापनम्;
    addr_t ab = s1->sections[b->section]->sh_addr + b->rel.r_विस्थापनम्;

    प्रत्यागम aa > ab ? 1 : aa < ab ? -1 : 0;
}

ST_FUNC शून्य bind_rebase_import(TCCState *s1, संरचना macho *mo)
{
    पूर्णाङ्क i, j, k, bind_सूचकांक, आकार, page_गणनम्, sym_सूचकांक;
    ध्रुव वर्ण *name;
    ElfW(Sym) *sym;
    अचिह्नित वर्ण *दत्त = mo->chained_fixups->दत्त;
    संरचना segment_command_64 *seg;
    संरचना dyld_chained_fixups_शीर्षकम् *शीर्षकम्;
    संरचना dyld_chained_starts_अन्तर्_image *image;
    संरचना dyld_chained_starts_अन्तर्_segment *segment;
    संरचना dyld_chained_import *import;

    tcc_qsort(mo->bind_rebase, mo->n_bind_rebase, परिमाण(संरचना bind_rebase),
	      bind_rebase_cmp, s1);
    प्रति (i = 0; i < mo->n_bind_rebase - 1; i++)
	यदि (mo->bind_rebase[i].section == mo->bind_rebase[i + 1].section &&
	    mo->bind_rebase[i].rel.r_विस्थापनम् == mo->bind_rebase[i + 1].rel.r_विस्थापनम्) {
	    sym_सूचकांक = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
            sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
	    name = (वर्ण *) symtab_section->link->दत्त + sym->st_name;
	    tcc_error("Overlap %s/%s %s:%s",
		      mo->bind_rebase[i].bind ? "bind" : "rebase",
		      mo->bind_rebase[i + 1].bind ? "bind" : "rebase",
		      s1->sections[mo->bind_rebase[i].section]->name, name);
	}
    शीर्षकम् = (संरचना dyld_chained_fixups_शीर्षकम् *) दत्त;
    दत्त += (परिमाण(संरचना dyld_chained_fixups_शीर्षकम्) + 7) & -8;
    शीर्षकम्->starts_विस्थापनम् = दत्त - mo->chained_fixups->दत्त;
    शीर्षकम्->imports_गणनम् = mo->n_bind;
    शीर्षकम्->imports_format = DYLD_CHAINED_IMPORT;
    शीर्षकम्->symbols_format = 0;
    आकार = परिमाण(संरचना dyld_chained_starts_अन्तर्_image) +
	   (mo->nseg - 1) * परिमाण(uint32_t);
    image = (संरचना dyld_chained_starts_अन्तर्_image *) दत्त;
    दत्त += (आकार + 7) & -8;
    image->seg_गणनम् = mo->nseg;
    प्रति (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
        image->seg_info_विस्थापनम्[i] = (दत्त - mo->chained_fixups->दत्त) -
				    शीर्षकम्->starts_विस्थापनम्;
	seg = get_segment(mo, i);
	page_गणनम् = (seg->vmsize + SEG_PAGE_आकार - 1) / SEG_PAGE_आकार;
	आकार = परिमाण(संरचना dyld_chained_starts_अन्तर्_segment) +
		      (page_गणनम् - 1) * परिमाण(uint16_t);
        segment = (संरचना dyld_chained_starts_अन्तर्_segment *) दत्त;
        दत्त += (आकार + 7) & -8;
        segment->आकार = आकार;
        segment->page_आकार = SEG_PAGE_आकार;
#यदि 1
#परिभाषय	PTR_64_विस्थापनम् 0
#परिभाषय	PTR_64_आवरणम्   0x7FFFFFFFFFFULL
        segment->pointer_format = DYLD_CHAINED_PTR_64;
#अन्यथा
#परिभाषय	PTR_64_विस्थापनम् 0x100000000ULL
#परिभाषय	PTR_64_आवरणम्   0xFFFFFFFFFFFFFFULL
        segment->pointer_format = DYLD_CHAINED_PTR_64_विस्थापनम्;
#यदि_अन्तः
        segment->segment_विस्थापनम् = seg->fileoff;
        segment->max_valid_pointer = 0;
        segment->page_गणनम् = page_गणनम्;
	// add bind/rebase
	bind_सूचकांक = 0;
	k = 0;
	प्रति (j = 0; j < page_गणनम्; j++) {
	    addr_t start = seg->vmaddr + j * SEG_PAGE_आकार;
	    addr_t अन्तः = start + SEG_PAGE_आकार;
	    शून्य *चरमः = रिक्त;
	    addr_t चरमः_o = 0;
	    addr_t cur_o, cur;
	    संरचना dyld_chained_ptr_64_rebase *rebase;
	    संरचना dyld_chained_ptr_64_bind *bind;

	    segment->page_start[j] = DYLD_CHAINED_PTR_START_NONE;
	    प्रति (; k < mo->n_bind_rebase; k++) {
	        Section *s = s1->sections[mo->bind_rebase[k].section];
		addr_t r_विस्थापनम् = mo->bind_rebase[k].rel.r_विस्थापनम्;
		addr_t addr = s->sh_addr + r_विस्थापनम्;

		यदि ((addr & 3) ||
		    (addr & (SEG_PAGE_आकार - 1)) > SEG_PAGE_आकार - PTR_आकार)
		    tcc_error("Illegal rel_offset %s %lld",
			      s->name, (दीर्घ दीर्घ)r_विस्थापनम्);
		यदि (addr >= अन्तः)
		    भङ्ग;
		यदि (addr >= start) {
		    cur_o = addr - start;
	            यदि (mo->bind_rebase[k].bind) {
		        यदि (segment->page_start[j] == DYLD_CHAINED_PTR_START_NONE)
			    segment->page_start[j] = cur_o;
		        अन्यथा {
			    bind = (संरचना dyld_chained_ptr_64_bind *) चरमः;
			    bind->अग्र = (cur_o - चरमः_o) / 4;
		        }
		        bind = (संरचना dyld_chained_ptr_64_bind *)
				    (s->दत्त + r_विस्थापनम्);
		        चरमः = bind;
		        चरमः_o = cur_o;
		        bind->ordinal = bind_सूचकांक;
		        bind->addend = 0;
		        bind->reserved = 0;
		        bind->अग्र = 0;
		        bind->bind = 1;
		    }
		    अन्यथा {
		        यदि (segment->page_start[j] == DYLD_CHAINED_PTR_START_NONE)
			    segment->page_start[j] = cur_o;
		        अन्यथा {
			    rebase = (संरचना dyld_chained_ptr_64_rebase *) चरमः;
			    rebase->अग्र = (cur_o - चरमः_o) / 4;
		        }
		        rebase = (संरचना dyld_chained_ptr_64_rebase *)
				    (s->दत्त + r_विस्थापनम्);
		        चरमः = rebase;
		        चरमः_o = cur_o;
		        cur = (*(uint64_t *) (s->दत्त + r_विस्थापनम्)) -
			      PTR_64_विस्थापनम्;
		        rebase->target = cur & PTR_64_आवरणम्;
		        rebase->high8 = cur >> (64 - 8);
			यदि (cur != ((uint64_t)rebase->high8 << (64 - 8)) + rebase->target)
			    tcc_error("rebase error");
		        rebase->reserved = 0;
		        rebase->अग्र = 0;
		        rebase->bind = 0;
		    }
		}
		bind_सूचकांक += mo->bind_rebase[k].bind;
	    }
	}
    }
    // add imports
    शीर्षकम्->imports_विस्थापनम् = दत्त - mo->chained_fixups->दत्त;
    import = (संरचना dyld_chained_import *) दत्त;
    दत्त += mo->n_bind * परिमाण (संरचना dyld_chained_import);
    शीर्षकम्->symbols_विस्थापनम् = दत्त - mo->chained_fixups->दत्त;
    दत्त++;
    प्रति (i = 0, bind_सूचकांक = 0; i < mo->n_bind_rebase; i++) {
	यदि (mo->bind_rebase[i].bind) {
	    import[bind_सूचकांक].lib_ordinal =
		BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xffu;
	    import[bind_सूचकांक].name_विस्थापनम् =
		(दत्त - mo->chained_fixups->दत्त) - शीर्षकम्->symbols_विस्थापनम्;
	    sym_सूचकांक = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    sym = &((ElfW(Sym) *)symtab_section->दत्त)[sym_सूचकांक];
	    import[bind_सूचकांक].weak_import =
		ELFW(ST_BIND)(sym->st_info) == STB_WEAK;
	    name = (वर्ण *) symtab_section->link->दत्त + sym->st_name;
            वाक्यं_प्रतिलिख((वर्ण *) दत्त, name);
	    दत्त += वाक्यदैर्घ्यम्(name) + 1;
	    bind_सूचकांक++;
	}
    }
    tcc_free(mo->bind_rebase);
}
#यदि_अन्तः

ST_FUNC पूर्णाङ्क macho_output_file(TCCState *s1, ध्रुव वर्ण *filename)
{
    पूर्णाङ्क fd, बहुलकम्, file_type;
    FILE *fp;
    पूर्णाङ्क i, ret = -1;
    संरचना macho mo;

    (शून्य)स्मृतिं_पूरय(&mo, 0, परिमाण(mo));

    file_type = s1->output_type;
    यदि (file_type == TCC_OUTPUT_OBJ)
        बहुलकम् = 0666;
    अन्यथा
        बहुलकम् = 0777;
    unlink(filename);
    fd = उद्घाटय(filename, O_WRONLY | O_CREAT | O_TRUNC | O_द्विमान_2, बहुलकम्);
    यदि (fd < 0 || (fp = fdopen(fd, "wb")) == रिक्त) {
        tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
        प्रत्यागम -1;
    }
    tcc_सङ्कलय_runtime(s1);
    tcc_macho_सङ्कलय_destructor(s1);
    resolve_common_syms(s1);
    create_symtab(s1, &mo);
    check_relocs(s1, &mo);
    ret = check_symbols(s1, &mo);
    यदि (!ret) {
	पूर्णाङ्क save_output = s1->output_type;

        collect_sections(s1, &mo, filename);
        relocate_syms(s1, s1->symtab, 0);
	यदि (s1->output_type == TCC_OUTPUT_EXE)
            mo.ep->entryoff = get_sym_addr(s1, "main", 1, 1)
                            -     get_segment(&mo, 1)->vmaddr;
        यदि (s1->nb_errors)
          गच्छ do_ret;
	// Macho uses bind/rebase instead of dynsym
	s1->output_type = TCC_OUTPUT_EXE;
        relocate_sections(s1);
	s1->output_type = save_output;
#यदि_परिभाषितम् CONFIG_NEW_MACHO
	bind_rebase_import(s1, &mo);
#यदि_अन्तः
        convert_symbols(s1, &mo);
        यदि (s1->verbose)
            प्रारूप_लिख("<- %s\n", filename);
        macho_write(s1, &mo, fp);
    }

 do_ret:
    प्रति (i = 0; i < mo.nlc; i++)
      tcc_free(mo.lc[i]);
    tcc_free(mo.seg2lc);
    tcc_free(mo.lc);
    tcc_free(mo.elfsectomacho);
    tcc_free(mo.e2msym);

    fclose(fp);
#यदि_परिभाषितम् CONFIG_CODESIGN
    यदि (!ret) {
	वर्ण command[1024];
	पूर्णाङ्क retval;

	snprintf(command, परिमाण(command), "codesign -f -s - %s", filename);
	retval = system (command);
	यदि (retval == -1 || !(WIFEXITED(retval) && WEXITSTATUS(retval) == 0))
	    tcc_error ("command failed '%s'", command);
    }
#यदि_अन्तः
    प्रत्यागम ret;
}

स्थिर uint32_t macho_swap32(uint32_t x)
{
  प्रत्यागम (x >> 24) | (x << 24) | ((x >> 8) & 0xff00) | ((x & 0xff00) << 8);
}
#परिभाषय SWAP(x) (swap ? macho_swap32(x) : (x))
#परिभाषय tbd_parse_movepast(s) \
    (pos = (pos = वाक्ये_अन्विष(pos, s)) ? pos + वाक्यदैर्घ्यम्(s) : रिक्त)
#परिभाषय tbd_parse_movetoany(cs) (pos = strpbrk(pos, cs))
#परिभाषय tbd_parse_skipws यावत् (*pos && (*pos==' '||*pos=='\n')) ++pos
#परिभाषय tbd_parse_tramplequote यदि(*pos=='\''||*pos=='"') tbd_parse_trample
#परिभाषय tbd_parse_tramplespace यदि(*pos==' ') tbd_parse_trample
#परिभाषय tbd_parse_trample *pos++=0

#यदि_परिभाषितम् TCC_IS_NATIVE
/* Looks for the active developer SDK set by xcode-select (or the default
   one set during installation.) */
ST_FUNC शून्य tcc_सङ्कलय_macos_sdkpath(TCCState* s)
{
    वर्ण *sdkroot = रिक्त, *pos = रिक्त;
    शून्य* xcs = dlopen("libxcselect.dylib", RTLD_GLOBAL | RTLD_LAZY);
    CString मार्गः;
    पूर्णाङ्क (*f)(अचिह्नित पूर्णाङ्क, वर्ण**) = dlsym(xcs, "xcselect_host_sdk_path");
    cstr_new(&मार्गः);
    यदि (f) f(1, &sdkroot);
    यदि (sdkroot)
        pos = वाक्ये_अन्विष(sdkroot,"SDKs/MacOSX");
    यदि (pos)
        cstr_printf(&मार्गः, "%.*s.sdk/usr/lib", (पूर्णाङ्क)(pos - sdkroot + 11), sdkroot);
    /* must use free from libc directly */
#निर्देशः प्रक्षिप_macro("free")
#अपरिभाषय मुक्त
    मुक्त(sdkroot);
#निर्देशः निष्कासय_macro("free")
    यदि (मार्गः.आकार)
        tcc_सङ्कलय_library_मार्गः(s, (वर्ण*)मार्गः.दत्त);
    अन्यथा
        tcc_सङ्कलय_library_मार्गः(s,
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib"
            ":" "/Applications/Xcode.app/Developer/SDKs/MacOSX.sdk/usr/lib"
            );
    cstr_free(&मार्गः);
}

ST_FUNC वर्ण* macho_tbd_soname(पूर्णाङ्क fd) {
    वर्ण *soname, *दत्त, *pos;
    वर्ण *ret = 0;
    pos = दत्त = tcc_आरोपय_text(fd);
    यदि (!tbd_parse_movepast("install-name: ")) गच्छ the_अन्तः;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    यदि (!tbd_parse_movetoany("\n \"'")) गच्छ the_अन्तः;
    tbd_parse_trample;
    ret = tcc_strdup(soname);
the_अन्तः:
    tcc_free(दत्त);
    प्रत्यागम ret;
}
#यदि_अन्तः /* TCC_IS_NATIVE */

ST_FUNC पूर्णाङ्क macho_आरोपय_tbd(TCCState* s1, पूर्णाङ्क fd, ध्रुव वर्ण* filename, पूर्णाङ्क lev)
{
    वर्ण *soname, *दत्त, *pos;
    पूर्णाङ्क ret = -1;

    pos = दत्त = tcc_आरोपय_text(fd);
    यदि (!tbd_parse_movepast("install-name: ")) गच्छ the_अन्तः;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    यदि (!tbd_parse_movetoany("\n \"'")) गच्छ the_अन्तः;
    tbd_parse_trample;
    ret = 0;
    यदि (tcc_सङ्कलय_dllref(s1, soname, lev)->प्राप्तम्)
        गच्छ the_अन्तः;
    यावत्(pos) {
        वर्ण* sym = रिक्त;
        पूर्णाङ्क cont = 1;
        यदि (!tbd_parse_movepast("symbols: ")) भङ्ग;
        यदि (!tbd_parse_movepast("[")) भङ्ग;
        यावत् (cont) {
            tbd_parse_skipws;
            tbd_parse_tramplequote;
            sym = pos;
            यदि (!tbd_parse_movetoany(",] \"'")) भङ्ग;
            tbd_parse_tramplequote;
            tbd_parse_tramplespace;
            tbd_parse_skipws;
            यदि (*pos==0||*pos==']') cont=0;
            tbd_parse_trample;
            समुच्चयः_elf_sym(s1->dynsymtab_section, 0, 0,
                ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0, SHN_UNDEF, sym);
        }
    }

the_अन्तः:
    tcc_free(दत्त);
    प्रत्यागम ret;
}

ST_FUNC पूर्णाङ्क macho_आरोपय_dll(TCCState * s1, पूर्णाङ्क fd, ध्रुव वर्ण* filename, पूर्णाङ्क lev)
{
    अचिह्नित वर्ण buf[परिमाण(संरचना mach_शीर्षकम्_64)];
    शून्य *buf2;
    uint32_t machofs = 0;
    संरचना fat_शीर्षकम् fh;
    संरचना mach_शीर्षकम् mh;
    संरचना आरोपय_command *lc;
    पूर्णाङ्क i, swap = 0;
    ध्रुव वर्ण *soname = filename;
    संरचना nlist_64 *symtab = 0;
    uint32_t nsyms = 0;
    वर्ण *strtab = 0;
    uint32_t strsize = 0;
    uint32_t iextdef = 0;
    uint32_t nextdef = 0;

  again:
    यदि (पूर्णम्_read(fd, buf, परिमाण(buf)) != परिमाण(buf))
      प्रत्यागम -1;
    स्मृतिं_प्रतिलिख(&fh, buf, परिमाण(fh));
    यदि (fh.magic == FAT_MAGIC || fh.magic == FAT_CIGAM) {
        संरचना fat_arch *fa = आरोपय_दत्त(fd, परिमाण(fh),
                                        fh.nfat_arch * परिमाण(*fa));
        swap = fh.magic == FAT_CIGAM;
        प्रति (i = 0; i < SWAP(fh.nfat_arch); i++)
#यदि_परिभाषितम् TCC_TARGET_X86_64
          यदि (SWAP(fa[i].cputype) == CPU_TYPE_X86_64
              && SWAP(fa[i].cpusubtype) == CPU_SUBTYPE_X86_ALL)
#नोचेद्यदि defined TCC_TARGET_ARM64
          यदि (SWAP(fa[i].cputype) == CPU_TYPE_ARM64
              && SWAP(fa[i].cpusubtype) == CPU_SUBTYPE_ARM64_ALL)
#यदि_अन्तः
            भङ्ग;
        यदि (i == SWAP(fh.nfat_arch)) {
            tcc_free(fa);
            प्रत्यागम -1;
        }
        machofs = SWAP(fa[i].विस्थापनम्);
        tcc_free(fa);
        lseek(fd, machofs, SEEK_SET);
        गच्छ again;
    } अन्यथा यदि (fh.magic == FAT_MAGIC_64 || fh.magic == FAT_CIGAM_64) {
        tcc_warning("%s: Mach-O fat 64bit files of type 0x%x not handled",
                    filename, fh.magic);
        प्रत्यागम -1;
    }

    स्मृतिं_प्रतिलिख(&mh, buf, परिमाण(mh));
    यदि (mh.magic != MH_MAGIC_64)
      प्रत्यागम -1;
    dprintf("found Mach-O at %d\n", machofs);
    buf2 = आरोपय_दत्त(fd, machofs + परिमाण(संरचना mach_शीर्षकम्_64), mh.sizeofcmds);
    प्रति (i = 0, lc = buf2; i < mh.ncmds; i++) {
        dprintf("lc %2d: 0x%08x\n", i, lc->cmd);
        विकल्प (lc->cmd) {
        पक्ष LC_SYMTAB:
        {
            संरचना symtab_command *sc = (संरचना symtab_command*)lc;
            nsyms = sc->nsyms;
            symtab = आरोपय_दत्त(fd, machofs + sc->symoff, nsyms * परिमाण(*symtab));
            strsize = sc->strsize;
            strtab = आरोपय_दत्त(fd, machofs + sc->stroff, strsize);
            भङ्ग;
        }
        पक्ष LC_ID_DYLIB:
        {
            संरचना dylib_command *dc = (संरचना dylib_command*)lc;
            soname = (वर्ण*)lc + dc->name;
            dprintf(" ID_DYLIB %d 0x%x 0x%x %s\n",
                    dc->timestamp, dc->current_संस्करणम्,
                    dc->compatibility_संस्करणम्, soname);
            भङ्ग;
        }
        पक्ष LC_REEXPORT_DYLIB:
        {
            संरचना dylib_command *dc = (संरचना dylib_command*)lc;
            वर्ण *name = (वर्ण*)lc + dc->name;
            पूर्णाङ्क subfd = उद्घाटय(name, O_RDONLY | O_द्विमान_2);
            dprintf(" REEXPORT %s\n", name);
            यदि (subfd < 0)
              tcc_warning("can't open %s (reexported from %s)", name, filename);
            अन्यथा {
                /* Hopefully the REEXPORTs never form a cycle, we don't check
                   for that!  */
                macho_आरोपय_dll(s1, subfd, name, lev + 1);
                close(subfd);
            }
            भङ्ग;
        }
        पक्ष LC_DYSYMTAB:
        {
            संरचना dysymtab_command *dc = (संरचना dysymtab_command*)lc;
            iextdef = dc->iextdefsym;
            nextdef = dc->nextdefsym;
            भङ्ग;
        }
        }
        lc = (संरचना आरोपय_command*) ((वर्ण*)lc + lc->cmdsize);
    }

    यदि (tcc_सङ्कलय_dllref(s1, soname, lev)->प्राप्तम्)
        गच्छ the_अन्तः;

    यदि (!nsyms || !nextdef)
      tcc_warning("%s doesn't export any symbols?", filename);

    //dprintf("symbols (all):\n");
    dprintf("symbols (exported):\n");
    dprintf("    n: typ sec   desc              value name\n");
    //for (i = 0; i < nsyms; i++) {
    प्रति (i = iextdef; i < iextdef + nextdef; i++) {
        संरचना nlist_64 *sym = symtab + i;
        dprintf("%5d: %3d %3d 0x%04x 0x%016lx %s\n",
                i, sym->n_type, sym->n_sect, sym->n_desc, (दीर्घ)sym->n_मानम्,
                strtab + sym->n_strx);
        समुच्चयः_elf_sym(s1->dynsymtab_section, 0, 0,
                    ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
                    0, SHN_UNDEF, strtab + sym->n_strx);
    }

  the_अन्तः:
    tcc_free(strtab);
    tcc_free(symtab);
    tcc_free(buf2);
    प्रत्यागम 0;
}
