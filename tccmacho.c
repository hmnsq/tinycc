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
#समावेश "tcc.h"

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

#अगर !defined TCC_TARGET_X86_64 && !defined TCC_TARGET_ARM64
#त्रुटि Platform not supported
#पूर्ण_अगर

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#अघोषित _tcc_error

#घोषणा DEBUG_MACHO 0
#घोषणा dprintf अगर (DEBUG_MACHO) म_लिखो

#घोषणा MH_EXECUTE              (0x2)
#घोषणा MH_DYLDLINK             (0x4)
#घोषणा MH_DYLIB                (0x6)
#घोषणा MH_PIE                  (0x200000)

#घोषणा CPU_SUBTYPE_LIB64       (0x80000000)
#घोषणा CPU_SUBTYPE_X86_ALL     (3)
#घोषणा CPU_SUBTYPE_ARM64_ALL   (0)

#घोषणा CPU_ARCH_ABI64          (0x01000000)

#घोषणा CPU_TYPE_X86            (7)
#घोषणा CPU_TYPE_X86_64         (CPU_TYPE_X86 | CPU_ARCH_ABI64)
#घोषणा CPU_TYPE_ARM            (12)
#घोषणा CPU_TYPE_ARM64          (CPU_TYPE_ARM | CPU_ARCH_ABI64)

काष्ठा fat_header {
    uint32_t        magic;          /* FAT_MAGIC or FAT_MAGIC_64 */
    uint32_t        nfat_arch;      /* number of structs that follow */
};

काष्ठा fat_arch {
    पूर्णांक             cputype;        /* cpu specifier (int) */
    पूर्णांक             cpusubtype;     /* machine specifier (int) */
    uint32_t        offset;         /* file offset to this object file */
    uint32_t        आकार;           /* size of this object file */
    uint32_t        align;          /* alignment as a power of 2 */
};

#घोषणा FAT_MAGIC       0xcafebabe
#घोषणा FAT_CIGAM       0xbebafeca
#घोषणा FAT_MAGIC_64    0xcafebabf
#घोषणा FAT_CIGAM_64    0xbfbafeca

काष्ठा mach_header {
    uint32_t        magic;          /* mach magic number identifier */
    पूर्णांक             cputype;        /* cpu specifier */
    पूर्णांक             cpusubtype;     /* machine specifier */
    uint32_t        filetype;       /* type of file */
    uint32_t        ncmds;          /* number of load commands */
    uint32_t        sizeofcmds;     /* the size of all the load commands */
    uint32_t        flags;          /* flags */
};

काष्ठा mach_header_64 {
    काष्ठा mach_header  mh;
    uint32_t            reserved;       /* reserved, pad to 64bit */
};

/* Constant for the magic field of the mach_header (32-bit architectures) */
#घोषणा MH_MAGIC        0xfeedface      /* the mach magic number */
#घोषणा MH_CIGAM        0xcefaedfe      /* NXSwapInt(MH_MAGIC) */
#घोषणा MH_MAGIC_64     0xfeedfacf      /* the 64-bit mach magic number */
#घोषणा MH_CIGAM_64     0xcffaedfe      /* NXSwapInt(MH_MAGIC_64) */

काष्ठा load_command {
    uint32_t        cmd;            /* type of load command */
    uint32_t        cmdsize;        /* total size of command in bytes */
};

#घोषणा LC_REQ_DYLD 0x80000000
#घोषणा LC_SYMTAB        0x2
#घोषणा LC_DYSYMTAB      0xb
#घोषणा LC_LOAD_DYLIB    0xc
#घोषणा LC_ID_DYLIB      0xd
#घोषणा LC_LOAD_DYLINKER 0xe
#घोषणा LC_SEGMENT_64    0x19
#घोषणा LC_RPATH (0x1c | LC_REQ_DYLD)
#घोषणा LC_REEXPORT_DYLIB (0x1f | LC_REQ_DYLD)
#घोषणा LC_DYLD_INFO_ONLY (0x22|LC_REQ_DYLD)
#घोषणा LC_MAIN (0x28|LC_REQ_DYLD)
#घोषणा LC_SOURCE_VERSION 0x2A
#घोषणा LC_BUILD_VERSION 0x32
#घोषणा LC_DYLD_EXPORTS_TRIE (0x33 | LC_REQ_DYLD)
#घोषणा LC_DYLD_CHAINED_FIXUPS (0x34 | LC_REQ_DYLD)

#घोषणा SG_READ_ONLY    0x10 /* This segment is made read-only after fixups */

प्रकार पूर्णांक vm_prot_t;

काष्ठा segment_command_64 { /* for 64-bit architectures */
    uint32_t        cmd;            /* LC_SEGMENT_64 */
    uint32_t        cmdsize;        /* includes sizeof section_64 structs */
    अक्षर            segname[16];    /* segment name */
    uint64_t        vmaddr;         /* memory address of this segment */
    uint64_t        vmsize;         /* memory size of this segment */
    uint64_t        fileoff;        /* file offset of this segment */
    uint64_t        filesize;       /* amount to map from the file */
    vm_prot_t       maxprot;        /* maximum VM protection */
    vm_prot_t       initprot;       /* initial VM protection */
    uint32_t        nsects;         /* number of sections in segment */
    uint32_t        flags;          /* flags */
};

काष्ठा section_64 { /* for 64-bit architectures */
    अक्षर            sectname[16];   /* name of this section */
    अक्षर            segname[16];    /* segment this section goes in */
    uint64_t        addr;           /* memory address of this section */
    uint64_t        आकार;           /* size in bytes of this section */
    uint32_t        offset;         /* file offset of this section */
    uint32_t        align;          /* section alignment (power of 2) */
    uint32_t        reloff;         /* file offset of relocation entries */
    uint32_t        nreloc;         /* number of relocation entries */
    uint32_t        flags;          /* flags (section type and attributes)*/
    uint32_t        reserved1;      /* reserved (for offset or index) */
    uint32_t        reserved2;      /* reserved (for count or sizeof) */
    uint32_t        reserved3;      /* reserved */
};

क्रमागत {
    DYLD_CHAINED_IMPORT          = 1,
};

काष्ठा dyld_chained_fixups_header {
    uint32_t    fixups_version; ///< 0
    uint32_t    starts_offset;  ///< Offset of dyld_chained_starts_in_image.
    uint32_t    imports_offset; ///< Offset of imports table in chain_data.
    uint32_t    symbols_offset; ///< Offset of symbol strings in chain_data.
    uint32_t    imports_गिनती;  ///< Number of imported symbol names.
    uint32_t    imports_format; ///< DYLD_CHAINED_IMPORT*
    uint32_t    symbols_format; ///< 0 => uncompressed, 1 => zlib compressed
};

काष्ठा dyld_chained_starts_in_image
{
    uint32_t    seg_गिनती;
    uint32_t    seg_info_offset[1];  // each entry is offset into this struct for that segment
    // followed by pool of dyld_chain_starts_in_segment data
};

क्रमागत {
    DYLD_CHAINED_PTR_64                     =  2,    // target is vmaddr
    DYLD_CHAINED_PTR_64_OFFSET              =  6,    // target is vm offset
};

क्रमागत {
    DYLD_CHAINED_PTR_START_NONE   = 0xFFFF, // used in page_start[] to denote a page with no fixups
};

#घोषणा SEG_PAGE_आकार 16384

काष्ठा dyld_chained_starts_in_segment
{
    uint32_t    आकार;               // size of this (amount kernel needs to copy)
    uint16_t    page_आकार;          // 0x1000 or 0x4000
    uint16_t    pointer_format;     // DYLD_CHAINED_PTR_*
    uint64_t    segment_offset;     // offset in memory to start of segment
    uint32_t    max_valid_pointer;  // for 32-bit OS, any value beyond this is not a pointer
    uint16_t    page_गिनती;         // how many pages are in array
    uint16_t    page_start[1];      // each entry is offset in each page of first element in chain
                                    // or DYLD_CHAINED_PTR_START_NONE if no fixups on page
};

क्रमागत BindSpecialDylib {
  BIND_SPECIAL_DYLIB_FLAT_LOOKUP = -2,
};

काष्ठा dyld_chained_import
{
    uint32_t    lib_ordinal :  8,
                weak_import :  1,
                name_offset : 23;
};

काष्ठा dyld_chained_ptr_64_rebase
{
    uint64_t    target    : 36,    // vmaddr, 64GB max image size
                high8     :  8,    // top 8 bits set to this after slide added
                reserved  :  7,    // all zeros
                अग्र      : 12,    // 4-byte stride
                bind      :  1;    // == 0
};

काष्ठा dyld_chained_ptr_64_bind
{
    uint64_t    ordinal   : 24,
                addend    :  8,   // 0 thru 255
                reserved  : 19,   // all zeros
                अग्र      : 12,   // 4-byte stride
                bind      :  1;   // == 1
};

#घोषणा S_REGULAR                       0x0
#घोषणा S_ZEROFILL                      0x1
#घोषणा S_NON_LAZY_प्रतीक_POINTERS      0x6
#घोषणा S_LAZY_प्रतीक_POINTERS          0x7
#घोषणा S_प्रतीक_STUBS                  0x8
#घोषणा S_MOD_INIT_FUNC_POINTERS        0x9
#घोषणा S_MOD_TERM_FUNC_POINTERS        0xa

#घोषणा S_ATTR_PURE_INSTRUCTIONS        0x80000000
#घोषणा S_ATTR_SOME_INSTRUCTIONS        0x00000400
#घोषणा S_ATTR_DEBUG             	0x02000000


प्रकार uint32_t lc_str;

काष्ठा dylib_command {
    uint32_t cmd;                   /* LC_ID_DYLIB, LC_LOAD_{,WEAK_}DYLIB,
                                       LC_REEXPORT_DYLIB */
    uint32_t cmdsize;               /* includes pathname string */
    lc_str   name;                  /* library's path name */
    uint32_t timestamp;             /* library's build time stamp */
    uint32_t current_version;       /* library's current version number */
    uint32_t compatibility_version; /* library's compatibility vers number*/
};

काष्ठा rpath_command {
    uint32_t     cmd;           /* LC_RPATH */
    uint32_t     cmdsize;       /* includes string */
    lc_str       path;          /* path to add to run path */
};

काष्ठा dylinker_command {
    uint32_t        cmd;            /* LC_ID_DYLINKER, LC_LOAD_DYLINKER or
                                       LC_DYLD_ENVIRONMENT */
    uint32_t        cmdsize;        /* includes pathname string */
    lc_str          name;           /* dynamic linker's path name */
};

काष्ठा linkedit_तथ्य_command {
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

#घोषणा PLATFORM_MACOS 1

काष्ठा build_version_command {
    uint32_t    cmd;            /* LC_BUILD_VERSION */
    uint32_t    cmdsize;        /* sizeof(struct build_version_command) plus */
                                /* ntools * sizeof(struct build_tool_version) */
    uint32_t    platform;       /* platform */
    uint32_t    minos;          /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    sdk;            /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    ntools;         /* number of tool entries following this */
};

काष्ठा source_version_command {
    uint32_t  cmd;      /* LC_SOURCE_VERSION */
    uint32_t  cmdsize;  /* 16 */
    uint64_t  version;  /* A.B.C.D.E packed as a24.b10.c10.d10.e10 */
};

काष्ठा symtab_command {
    uint32_t        cmd;            /* LC_SYMTAB */
    uint32_t        cmdsize;        /* sizeof(struct symtab_command) */
    uint32_t        symoff;         /* symbol table offset */
    uint32_t        nsyms;          /* number of symbol table entries */
    uint32_t        stroff;         /* string table offset */
    uint32_t        strsize;        /* string table size in bytes */
};

काष्ठा dysymtab_command {
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

#घोषणा BIND_OPCODE_DONE                                        0x00
#घोषणा BIND_OPCODE_SET_DYLIB_SPECIAL_IMM                       0x30
#घोषणा BIND_OPCODE_SET_प्रतीक_TRAILING_FLAGS_IMM               0x40
#घोषणा BIND_OPCODE_SET_TYPE_IMM                                0x50
#घोषणा BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB                 0x70
#घोषणा BIND_OPCODE_DO_BIND                                     0x90

#घोषणा BIND_प्रतीक_FLAGS_WEAK_IMPORT                           0x1

#घोषणा BIND_TYPE_POINTER                                       1
#घोषणा BIND_SPECIAL_DYLIB_FLAT_LOOKUP                          -2

#घोषणा REBASE_OPCODE_DONE                                      0x00
#घोषणा REBASE_OPCODE_SET_TYPE_IMM                              0x10
#घोषणा REBASE_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB               0x20
#घोषणा REBASE_OPCODE_DO_REBASE_IMM_TIMES                       0x50

#घोषणा REBASE_TYPE_POINTER                                     1

#घोषणा EXPORT_प्रतीक_FLAGS_KIND_REGULAR                        0x00
#घोषणा EXPORT_प्रतीक_FLAGS_KIND_ABSOLUTE                       0x02
#घोषणा EXPORT_प्रतीक_FLAGS_WEAK_DEFINITION                     0x04

काष्ठा dyld_info_command {
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

#घोषणा INDIRECT_प्रतीक_LOCAL   0x80000000

काष्ठा entry_point_command {
    uint32_t  cmd;      /* LC_MAIN only used in MH_EXECUTE filetypes */
    uint32_t  cmdsize;  /* 24 */
    uint64_t  entryoff; /* file (__TEXT) offset of main() */
    uint64_t  stacksize;/* if not zero, initial stack size */
};

क्रमागत skind {
    sk_unknown = 0,
    sk_discard,
    sk_text,
    sk_stubs,
    sk_stub_helper,
    sk_ro_तथ्य,
    sk_uw_info,
    sk_nl_ptr,  // non-lazy pointers, aka GOT
    sk_debug_info,
    sk_debug_abbrev,
    sk_debug_पंक्ति,
    sk_debug_aranges,
    sk_debug_str,
    sk_debug_पंक्ति_str,
    sk_stab,
    sk_stab_str,
    sk_la_ptr,  // lazy pointers
    sk_init,
    sk_fini,
    sk_rw_तथ्य,
    sk_bss,
    sk_linkedit,
    sk_last
};

काष्ठा nlist_64 {
    uint32_t  n_strx;      /* index into the string table */
    uint8_t n_type;        /* type flag, see below */
    uint8_t n_sect;        /* section number or NO_SECT */
    uint16_t n_desc;       /* see <mach-o/stab.h> */
    uint64_t n_मूल्य;      /* value of this symbol (or stab offset) */
};

#घोषणा N_UNDF  0x0
#घोषणा N_ABS   0x2
#घोषणा N_EXT   0x1
#घोषणा N_SECT  0xe

#घोषणा N_WEAK_REF      0x0040
#घोषणा N_WEAK_DEF      0x0080

काष्ठा macho {
    काष्ठा mach_header_64 mh;
    पूर्णांक *seg2lc, nseg;
    काष्ठा load_command **lc;
    काष्ठा entry_point_command *ep;
    पूर्णांक nlc;
    काष्ठा {
        Section *s;
        पूर्णांक machosect;
    } sk_to_sect[sk_last];
    पूर्णांक *elfsectomacho;
    पूर्णांक *e2msym;
    Section *symtab, *strtab, *indirsyms, *stubs, *exports;
    uint32_t ilocal, iextdef, iundef;
    पूर्णांक stubsym, n_got, nr_plt;
    पूर्णांक segment[sk_last];
#अगर_घोषित CONFIG_NEW_MACHO
    Section *chained_fixups;
    पूर्णांक n_bind;
    पूर्णांक n_bind_rebase;
    काष्ठा bind_rebase {
	पूर्णांक section;
	पूर्णांक bind;
	ElfW_Rel rel;
    } *bind_rebase;
#अन्यथा
    Section *rebase, *binding, *weak_binding, *lazy_binding;
    Section *stub_helper, *la_प्रतीक_ptr;
    काष्ठा dyld_info_command *dyldinfo;
    पूर्णांक helpsym, lasym, dyld_private, dyld_stub_binder;
    पूर्णांक n_lazy_bind;    
    काष्ठा s_lazy_bind {
        पूर्णांक section;
        पूर्णांक bind_offset;
        पूर्णांक la_प्रतीक_offset;
        ElfW_Rel rel;
    } *s_lazy_bind;
    पूर्णांक n_rebase;    
    काष्ठा s_rebase {
        पूर्णांक section;
        ElfW_Rel rel;
    } *s_rebase;
    पूर्णांक n_bind; 
    काष्ठा bind {
        पूर्णांक section;
        ElfW_Rel rel;
    } *bind;
#पूर्ण_अगर
};

#घोषणा SHT_LINKEDIT (SHT_LOOS + 42)
#घोषणा SHN_FROMDLL  (SHN_LOOS + 2)  /* Symbol is undefined, comes from a DLL */

अटल व्योम * add_lc(काष्ठा macho *mo, uint32_t cmd, uint32_t cmdsize)
{
    काष्ठा load_command *lc = tcc_mallocz(cmdsize);
    lc->cmd = cmd;
    lc->cmdsize = cmdsize;
    mo->lc = tcc_realloc(mo->lc, माप(mo->lc[0]) * (mo->nlc + 1));
    mo->lc[mo->nlc++] = lc;
    वापस lc;
}

अटल काष्ठा segment_command_64 * add_segment(काष्ठा macho *mo, स्थिर अक्षर *name)
{
    काष्ठा segment_command_64 *sc = add_lc(mo, LC_SEGMENT_64, माप(*sc));
    म_नकलन(sc->segname, name, 16);
    mo->seg2lc = tcc_realloc(mo->seg2lc, माप(*mo->seg2lc) * (mo->nseg + 1));
    mo->seg2lc[mo->nseg++] = mo->nlc - 1;
    वापस sc;
}

अटल काष्ठा segment_command_64 * get_segment(काष्ठा macho *mo, पूर्णांक i)
{
    वापस (काष्ठा segment_command_64 *) (mo->lc[mo->seg2lc[i]]);
}

अटल पूर्णांक add_section(काष्ठा macho *mo, काष्ठा segment_command_64 **_seg, स्थिर अक्षर *name)
{
    काष्ठा segment_command_64 *seg = *_seg;
    पूर्णांक ret = seg->nsects;
    काष्ठा section_64 *sec;
    seg->nsects++;
    seg->cmdsize += माप(*sec);
    seg = tcc_realloc(seg, माप(*seg) + seg->nsects * माप(*sec));
    sec = (काष्ठा section_64*)((अक्षर*)seg + माप(*seg)) + ret;
    स_रखो(sec, 0, माप(*sec));
    म_नकलन(sec->sectname, name, 16);
    म_नकलन(sec->segname, seg->segname, 16);
    *_seg = seg;
    वापस ret;
}

अटल काष्ठा section_64 *get_section(काष्ठा segment_command_64 *seg, पूर्णांक i)
{
    वापस (काष्ठा section_64*)((अक्षर*)seg + माप(*seg)) + i;
}

अटल व्योम * add_dylib(काष्ठा macho *mo, अक्षर *name)
{
    काष्ठा dylib_command *lc;
    पूर्णांक sz = (माप(*lc) + म_माप(name) + 1 + 7) & -8;
    lc = add_lc(mo, LC_LOAD_DYLIB, sz);
    lc->name = माप(*lc);
    म_नकल((अक्षर*)lc + lc->name, name);
    lc->timestamp = 2;
    lc->current_version = 1 << 16;
    lc->compatibility_version = 1 << 16;
    वापस lc;
}

अटल पूर्णांक uleb128_आकार (अचिन्हित दीर्घ दीर्घ मूल्य)
{
    पूर्णांक आकार =  0;

    करो {
        मूल्य >>= 7;
        आकार++;
    } जबतक (मूल्य != 0);
    वापस आकार;
}

अटल व्योम write_uleb128(Section *section, uint64_t मूल्य)
{
    करो {
        अचिन्हित अक्षर byte = मूल्य & 0x7f;
	uint8_t *ptr = section_ptr_add(section, 1);

        मूल्य >>= 7;
        *ptr = byte | (मूल्य ? 0x80 : 0);
    } जबतक (मूल्य != 0);
}

अटल व्योम tcc_macho_add_destructor(TCCState *s1)
{
    पूर्णांक init_sym, mh_execute_header, at_exit_sym;
    Section *s;
    ElfW_Rel *rel;
    uint8_t *ptr;

    mh_execute_header = put_elf_sym(s1->symtab, -4096, 0,
				    ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				    text_section->sh_अंक, "__mh_execute_header");
    s = find_section(s1, ".fini_array");
    अगर (s->तथ्य_offset == 0)
        वापस; 
    init_sym = put_elf_sym(s1->symtab, text_section->तथ्य_offset, 0,
                           ELFW(ST_INFO)(STB_LOCAL, STT_FUNC), 0,
                           text_section->sh_अंक, "___GLOBAL_init_65535");
    at_exit_sym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0,
                              SHN_UNDEF, "___cxa_atexit");
#अगर_घोषित TCC_TARGET_X86_64
    ptr = section_ptr_add(text_section, 4);
    ptr[0] = 0x55;  // pushq   %rbp
    ptr[1] = 0x48;  // movq    %rsp, %rbp
    ptr[2] = 0x89;
    ptr[3] = 0xe5;
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        पूर्णांक sym_सूचकांक = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_add(text_section, 26);
        ptr[0] = 0x48;  // lea destructor(%rip),%rax
        ptr[1] = 0x8d;
        ptr[2] = 0x05;
        put_elf_reloca(s1->symtab, text_section, 
		       text_section->तथ्य_offset - 23,
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
		       text_section->तथ्य_offset - 9,
		       R_X86_64_PC32, mh_execute_header, -4);
	ptr[21] = 0xe8; // call __cxa_atexit
        put_elf_reloca(s1->symtab, text_section,
		       text_section->तथ्य_offset - 4,
		       R_X86_64_PLT32, at_exit_sym, -4);
    }
    ptr = section_ptr_add(text_section, 2);
    ptr[0] = 0x5d;  // pop   %rbp
    ptr[1] = 0xc3;  // ret
#या_अगर defined TCC_TARGET_ARM64
    ptr = section_ptr_add(text_section, 8);
    write32le(ptr, 0xa9bf7bfd);     // stp     x29, x30, [sp, #-16]!
    write32le(ptr + 4, 0x910003fd); // mov     x29, sp
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        पूर्णांक sym_सूचकांक = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_add(text_section, 24);
        put_elf_reloc(s1->symtab, text_section, 
		      text_section->तथ्य_offset - 24,
		      R_AARCH64_ADR_PREL_PG_HI21, sym_सूचकांक);
        write32le(ptr, 0x90000000);      // adrp x0, destructor@page
        put_elf_reloc(s1->symtab, text_section,
		      text_section->तथ्य_offset - 20,
		      R_AARCH64_LDST8_ABS_LO12_NC, sym_सूचकांक);
        write32le(ptr + 4, 0x91000000);  // add x0,x0,destructor@pageoff
        write32le(ptr + 8, 0xd2800001);  // mov x1, #0
        put_elf_reloc(s1->symtab, text_section, 
		      text_section->तथ्य_offset - 12,
		      R_AARCH64_ADR_PREL_PG_HI21, mh_execute_header);
        write32le(ptr + 12, 0x90000002);      // adrp x2, mh_execute_header@page
        put_elf_reloc(s1->symtab, text_section,
		      text_section->तथ्य_offset - 8,
		      R_AARCH64_LDST8_ABS_LO12_NC, mh_execute_header);
        write32le(ptr + 16, 0x91000042);  // add x2,x2,mh_execute_header@pageoff
        put_elf_reloc(s1->symtab, text_section,
		      text_section->तथ्य_offset - 4,
		      R_AARCH64_CALL26, at_exit_sym);
	write32le(ptr + 20, 0x94000000); // bl __cxa_atexit
    }
    ptr = section_ptr_add(text_section, 8);
    write32le(ptr, 0xa8c17bfd);     // ldp     x29, x30, [sp], #16
    write32le(ptr + 4, 0xd65f03c0); // ret
#पूर्ण_अगर
    s->reloc->तथ्य_offset = s->तथ्य_offset = 0;
    s->sh_flags &= ~SHF_ALLOC;
    add_array (s1, ".init_array", init_sym);
}

#अगर_घोषित CONFIG_NEW_MACHO
अटल व्योम bind_rebase_add(काष्ठा macho *mo, पूर्णांक bind, पूर्णांक sh_info,
			    ElfW_Rel *rel, काष्ठा sym_attr *attr)
{
    mo->bind_rebase = tcc_realloc(mo->bind_rebase, (mo->n_bind_rebase + 1) *
		                  माप(काष्ठा bind_rebase));
    mo->bind_rebase[mo->n_bind_rebase].section = sh_info;
    mo->bind_rebase[mo->n_bind_rebase].bind = bind;
    mo->bind_rebase[mo->n_bind_rebase].rel = *rel;
    अगर (attr)
        mo->bind_rebase[mo->n_bind_rebase].rel.r_offset = attr->got_offset;
    mo->n_bind_rebase++;
    mo->n_bind += bind;
}

अटल व्योम check_relocs(TCCState *s1, काष्ठा macho *mo)
{
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    पूर्णांक i, j, type, gotplt_entry, sym_सूचकांक, for_code;
    uint32_t *pi, *goti;
    काष्ठा sym_attr *attr;

    goti = शून्य;
    mo->nr_plt = mo->n_got = 0;
    क्रम (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        अगर (s->sh_type != SHT_RELX ||
	    !म_भेदन(s1->sections[s->sh_info]->name, ".debug_", 7))
            जारी;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_entry = gotplt_entry_type(type);
            for_code = code_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
            अगर (sym->st_shndx == SHN_UNDEF
                || gotplt_entry == ALWAYS_GOTPLT_ENTRY) {
                attr = get_sym_attr(s1, sym_सूचकांक, 1);
                अगर (!attr->dyn_सूचकांक) {
                    attr->got_offset = s1->got->तथ्य_offset;
                    attr->plt_offset = -1;
                    attr->dyn_सूचकांक = 1; /* used as flag */
                    section_ptr_add(s1->got, PTR_आकार);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_offset,
                                  R_JMP_SLOT, sym_सूचकांक);
	 	    goti = tcc_realloc(goti, (mo->n_got + 1) * माप(*goti));
                    अगर (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        अगर (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (अक्षर *) symtab_section->link->तथ्य + sym->st_name);
			goti[mo->n_got++] = INDIRECT_प्रतीक_LOCAL;
                    } अन्यथा {
                        goti[mo->n_got++] = mo->e2msym[sym_सूचकांक];
                        अगर (sym->st_shndx == SHN_UNDEF
#अगर_घोषित TCC_TARGET_X86_64
                            && type == R_X86_64_GOTPCREL
#या_अगर defined TCC_TARGET_ARM64
                            && type == R_AARCH64_ADR_GOT_PAGE
#पूर्ण_अगर
                            ) {
			    attr->plt_offset = -mo->n_bind_rebase - 2;
			    bind_rebase_add(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
			    s1->got->reloc->तथ्य_offset -= माप (ElfW_Rel);
			}
		        अगर (for_code && sym->st_shndx == SHN_UNDEF)
			    s1->got->reloc->तथ्य_offset -= माप (ElfW_Rel);
		    }
                }
                अगर (for_code && sym->st_shndx == SHN_UNDEF) {
		    अगर ((पूर्णांक)attr->plt_offset < -1) {
			/* remove above bind and replace with plt */
			mo->bind_rebase[-attr->plt_offset - 2].bind = 2;
			attr->plt_offset = -1;
		    }
                    अगर (attr->plt_offset == -1) {
                        uint8_t *jmp;

                        attr->plt_offset = mo->stubs->तथ्य_offset;
#अगर_घोषित TCC_TARGET_X86_64
                        अगर (type != R_X86_64_PLT32)
                             जारी;
                        jmp = section_ptr_add(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *ofs(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_offset + 2,
                                      R_X86_64_GOTPCREL, sym_सूचकांक);
#या_अगर defined TCC_TARGET_ARM64
                        अगर (type != R_AARCH64_CALL26)
                             जारी;
                        jmp = section_ptr_add(mo->stubs, 12);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_offset,
                                      R_AARCH64_ADR_GOT_PAGE, sym_सूचकांक);
                        write32le(jmp, // adrp x16, #sym
                                  0x90000010);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_offset + 4,
                                      R_AARCH64_LD64_GOT_LO12_NC, sym_सूचकांक);
                        write32le(jmp + 4, // ld x16,[x16, #sym]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);
#पूर्ण_अगर
			bind_rebase_add(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
                        pi = section_ptr_add(mo->indirsyms, माप(*pi));
                        *pi = mo->e2msym[sym_सूचकांक];
                        mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_offset;
                }
            }
	    अगर (type == R_तथ्य_PTR || type == R_JMP_SLOT)
		bind_rebase_add(mo, sym->st_shndx == SHN_UNDEF ? 1 : 0,
				s->sh_info, &save_rel, शून्य);
        }
    }
    /* remove deleted binds */
    क्रम (i = 0, j = 0; i < mo->n_bind_rebase; i++)
	अगर (mo->bind_rebase[i].bind == 2)
	    mo->n_bind--;
	अन्यथा
	    mo->bind_rebase[j++] = mo->bind_rebase[i];
    mo->n_bind_rebase = j;
    pi = section_ptr_add(mo->indirsyms, mo->n_got * माप(*pi));
    स_नकल(pi, goti, mo->n_got * माप(*pi));
    tcc_free(goti);
}

#अन्यथा

अटल व्योम check_relocs(TCCState *s1, काष्ठा macho *mo)
{
    uint8_t *jmp;
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    पूर्णांक i, type, gotplt_entry, sym_सूचकांक, for_code;
    पूर्णांक bind_offset, la_प्रतीक_offset;
    uint32_t *pi, *goti;
    काष्ठा sym_attr *attr;

#अगर_घोषित TCC_TARGET_X86_64
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
#या_अगर defined TCC_TARGET_ARM64
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
#पूर्ण_अगर
    
    goti = शून्य;
    mo->nr_plt = mo->n_got = 0;
    क्रम (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        अगर (s->sh_type != SHT_RELX ||
	    !म_भेदन(s1->sections[s->sh_info]->name, ".debug_", 7))
            जारी;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_entry = gotplt_entry_type(type);
            for_code = code_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_सूचकांक = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
            अगर (sym->st_shndx == SHN_UNDEF
                || gotplt_entry == ALWAYS_GOTPLT_ENTRY) {
                attr = get_sym_attr(s1, sym_सूचकांक, 1);
                अगर (!attr->dyn_सूचकांक) {
                    attr->got_offset = s1->got->तथ्य_offset;
                    attr->plt_offset = -1;
                    attr->dyn_सूचकांक = 1; /* used as flag */
		    section_ptr_add(s1->got, PTR_आकार);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_offset,
                                  R_JMP_SLOT, sym_सूचकांक);
		    goti = tcc_realloc(goti, (mo->n_got + 1) * माप(*goti));
                    अगर (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        अगर (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (अक्षर *) symtab_section->link->तथ्य + sym->st_name);
			goti[mo->n_got++] = INDIRECT_प्रतीक_LOCAL;
                    } अन्यथा {
			goti[mo->n_got++] = mo->e2msym[sym_सूचकांक];
			अगर (sym->st_shndx == SHN_UNDEF
#अगर_घोषित TCC_TARGET_X86_64
			    && type == R_X86_64_GOTPCREL
#या_अगर defined TCC_TARGET_ARM64
			    && type == R_AARCH64_ADR_GOT_PAGE
#पूर्ण_अगर
			    ) {
			    mo->bind =
			        tcc_realloc(mo->bind,
					    (mo->n_bind + 1) *
					    माप(काष्ठा bind));
			    mo->bind[mo->n_bind].section = s1->got->reloc->sh_info;
			    mo->bind[mo->n_bind].rel = save_rel;
                            mo->bind[mo->n_bind].rel.r_offset = attr->got_offset;
			    mo->n_bind++;
			    s1->got->reloc->तथ्य_offset -= माप (ElfW_Rel);
			}
		    }
                }
                अगर (for_code && sym->st_shndx == SHN_UNDEF) {
                    अगर (attr->plt_offset == -1) {
                        attr->plt_offset = mo->stubs->तथ्य_offset;
#अगर_घोषित TCC_TARGET_X86_64
			अगर (type != R_X86_64_PLT32)
			     जारी;
			/* __stubs */
                        jmp = section_ptr_add(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *__la_symbol_ptr(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->तथ्य_offset - 4,
                                       R_X86_64_PC32, mo->lasym,
				       mo->la_प्रतीक_ptr->तथ्य_offset - 4);

			/* __stub_helper */
			bind_offset = mo->stub_helper->तथ्य_offset + 1;
                        jmp = section_ptr_add(mo->stub_helper, 10);
                        jmp[0] = 0x68;  /* pushq $bind_offset */
                        jmp[5] = 0xe9;  /* jmpq __stub_helper */
                        write32le(jmp + 6, -mo->stub_helper->तथ्य_offset);

			/* __la_symbol_ptr */
			la_प्रतीक_offset = mo->la_प्रतीक_ptr->तथ्य_offset;
                        put_elf_reloca(s1->symtab, mo->la_प्रतीक_ptr,
				       mo->la_प्रतीक_ptr->तथ्य_offset,
				       R_तथ्य_PTR, mo->helpsym,
				       mo->stub_helper->तथ्य_offset - 10);
			section_ptr_add(mo->la_प्रतीक_ptr, PTR_आकार);
#या_अगर defined TCC_TARGET_ARM64
			अगर (type != R_AARCH64_CALL26)
			     जारी;
			/* __stubs */
                        jmp = section_ptr_add(mo->stubs, 12);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->तथ्य_offset - 12,
                                       R_AARCH64_ADR_PREL_PG_HI21, mo->lasym,
				       mo->la_प्रतीक_ptr->तथ्य_offset);
                        write32le(jmp, // adrp x16, __la_symbol_ptr@page
                                  0x90000010);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->तथ्य_offset - 8,
                                       R_AARCH64_LDST64_ABS_LO12_NC, mo->lasym,
				       mo->la_प्रतीक_ptr->तथ्य_offset);
                        write32le(jmp + 4, // ldr x16,[x16, __la_symbol_ptr@pageoff]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);

			/* __stub_helper */
			bind_offset = mo->stub_helper->तथ्य_offset + 8;
                        jmp = section_ptr_add(mo->stub_helper, 12);
                        write32le(jmp + 0, // ldr  w16, l0
                                  0x18000050);
                        write32le(jmp + 4, // b stubHelperHeader
                                  0x14000000 +
				  ((-(mo->stub_helper->तथ्य_offset - 8) / 4) &
				   0x3ffffff));
                        write32le(jmp + 8, 0); // l0: .long bind_offset

			/* __la_symbol_ptr */
			la_प्रतीक_offset = mo->la_प्रतीक_ptr->तथ्य_offset;
                        put_elf_reloca(s1->symtab, mo->la_प्रतीक_ptr,
				       mo->la_प्रतीक_ptr->तथ्य_offset,
				       R_तथ्य_PTR, mo->helpsym,
				       mo->stub_helper->तथ्य_offset - 12);
			section_ptr_add(mo->la_प्रतीक_ptr, PTR_आकार);
#पूर्ण_अगर
                        mo->s_lazy_bind =
                            tcc_realloc(mo->s_lazy_bind, (mo->n_lazy_bind + 1) *
                                        माप(काष्ठा s_lazy_bind));
                        mo->s_lazy_bind[mo->n_lazy_bind].section =
                            mo->stub_helper->reloc->sh_info;
                        mo->s_lazy_bind[mo->n_lazy_bind].bind_offset =
			    bind_offset;
                        mo->s_lazy_bind[mo->n_lazy_bind].la_प्रतीक_offset =
			    la_प्रतीक_offset;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel = save_rel;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel.r_offset =
                            attr->plt_offset;
                        mo->n_lazy_bind++;
			pi = section_ptr_add(mo->indirsyms, माप(*pi));
			*pi = mo->e2msym[sym_सूचकांक];
			mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_offset;
                }
            }
            अगर (type == R_तथ्य_PTR || type == R_JMP_SLOT) {
		अगर (sym->st_shndx == SHN_UNDEF) {
		    mo->bind = tcc_realloc(mo->bind,
					   (mo->n_bind + 1) *
					   माप(काष्ठा bind));
		    mo->bind[mo->n_bind].section = s->sh_info;
		    mo->bind[mo->n_bind].rel = save_rel;
		    mo->n_bind++;
		}
		अन्यथा {
                    mo->s_rebase =
                        tcc_realloc(mo->s_rebase, (mo->n_rebase + 1) *
				    माप(काष्ठा s_rebase));
                    mo->s_rebase[mo->n_rebase].section = s->sh_info;
                    mo->s_rebase[mo->n_rebase].rel = save_rel;
                    mo->n_rebase++;
		}
	    }
        }
    }
    pi = section_ptr_add(mo->indirsyms, mo->n_got * माप(*pi));
    स_नकल(pi, goti, mo->n_got * माप(*pi));
    pi = section_ptr_add(mo->indirsyms, mo->nr_plt * माप(*pi));
    स_नकल(pi, mo->indirsyms->तथ्य, mo->nr_plt * माप(*pi));
    tcc_free(goti);
}
#पूर्ण_अगर

अटल पूर्णांक check_symbols(TCCState *s1, काष्ठा macho *mo)
{
    पूर्णांक sym_सूचकांक, sym_end;
    पूर्णांक ret = 0;

    mo->ilocal = mo->iextdef = mo->iundef = -1;
    sym_end = symtab_section->तथ्य_offset / माप(ElfW(Sym));
    क्रम (sym_सूचकांक = 1; sym_सूचकांक < sym_end; ++sym_सूचकांक) {
        पूर्णांक elf_सूचकांक = ((काष्ठा nlist_64 *)mo->symtab->तथ्य + sym_सूचकांक - 1)->n_मूल्य;
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->तथ्य + elf_सूचकांक;
        स्थिर अक्षर *name = (अक्षर*)symtab_section->link->तथ्य + sym->st_name;
        अचिन्हित type = ELFW(ST_TYPE)(sym->st_info);
        अचिन्हित bind = ELFW(ST_BIND)(sym->st_info);
        अचिन्हित vis  = ELFW(ST_VISIBILITY)(sym->st_other);

        dprintf("%4d (%4d): %09lx %4d %4d %4d %3d %s\n",
                sym_सूचकांक, elf_सूचकांक, (दीर्घ)sym->st_मूल्य,
                type, bind, vis, sym->st_shndx, name);
        अगर (bind == STB_LOCAL) {
            अगर (mo->ilocal == -1)
              mo->ilocal = sym_सूचकांक - 1;
            अगर (mo->iextdef != -1 || mo->iundef != -1)
              tcc_error("local syms after global ones");
        } अन्यथा अगर (sym->st_shndx != SHN_UNDEF) {
            अगर (mo->iextdef == -1)
              mo->iextdef = sym_सूचकांक - 1;
            अगर (mo->iundef != -1)
              tcc_error("external defined symbol after undefined");
        } अन्यथा अगर (sym->st_shndx == SHN_UNDEF) {
            अगर (mo->iundef == -1)
              mo->iundef = sym_सूचकांक - 1;
            अगर (ELFW(ST_BIND)(sym->st_info) == STB_WEAK
		|| s1->output_type != TCC_OUTPUT_EXE
                || find_elf_sym(s1->dynsymtab_section, name)) {
                /* Mark the symbol as coming from a dylib so that
                   relocate_syms doesn't complain.  Normally bind_exe_dynsyms
                   would do this check, and place the symbol into dynsym
                   which is checked by relocate_syms.  But Mach-O doesn't use
                   bind_exe_dynsyms.  */
                sym->st_shndx = SHN_FROMDLL;
                जारी;
            }
            tcc_error_noabort("unresolved reference to '%s'", name);
            ret = -1;
        }
    }
    वापस ret;
}

अटल व्योम convert_प्रतीक(TCCState *s1, काष्ठा macho *mo, काष्ठा nlist_64 *pn)
{
    काष्ठा nlist_64 n = *pn;
    ElfSym *sym = (ElfW(Sym) *)symtab_section->तथ्य + pn->n_मूल्य;
    स्थिर अक्षर *name = (अक्षर*)symtab_section->link->तथ्य + sym->st_name;
    चयन(ELFW(ST_TYPE)(sym->st_info)) {
    हाल STT_NOTYPE:
    हाल STT_OBJECT:
    हाल STT_FUNC:
    हाल STT_TLS:
    हाल STT_SECTION:
        n.n_type = N_SECT;
        अवरोध;
    हाल STT_FILE:
        n.n_type = N_ABS;
        अवरोध;
    शेष:
        tcc_error("unhandled ELF symbol type %d %s",
                  ELFW(ST_TYPE)(sym->st_info), name);
    }
    अगर (sym->st_shndx == SHN_UNDEF)
      tcc_error("should have been rewritten to SHN_FROMDLL: %s", name);
    अन्यथा अगर (sym->st_shndx == SHN_FROMDLL)
      n.n_type = N_UNDF, n.n_sect = 0;
    अन्यथा अगर (sym->st_shndx == SHN_ABS)
      n.n_type = N_ABS, n.n_sect = 0;
    अन्यथा अगर (sym->st_shndx >= SHN_LORESERVE)
      tcc_error("unhandled ELF symbol section %d %s", sym->st_shndx, name);
    अन्यथा अगर (!mo->elfsectomacho[sym->st_shndx]) {
      अगर (म_भेदन(s1->sections[sym->st_shndx]->name, ".debug_", 7))
        tcc_error("ELF section %d(%s) not mapped into Mach-O for symbol %s",
                  sym->st_shndx, s1->sections[sym->st_shndx]->name, name);
    }
    अन्यथा
      n.n_sect = mo->elfsectomacho[sym->st_shndx];
    अगर (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL)
      n.n_type |=  N_EXT;
    अन्यथा अगर (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
      n.n_desc |= N_WEAK_REF | (n.n_type != N_UNDF ? N_WEAK_DEF : 0);
    n.n_strx = pn->n_strx;
    n.n_मूल्य = sym->st_मूल्य;
    *pn = n;
}

अटल व्योम convert_symbols(TCCState *s1, काष्ठा macho *mo)
{
    काष्ठा nlist_64 *pn;
    for_each_elem(mo->symtab, 0, pn, काष्ठा nlist_64)
        convert_प्रतीक(s1, mo, pn);
}

अटल पूर्णांक machosymcmp(स्थिर व्योम *_a, स्थिर व्योम *_b, व्योम *arg)
{
    TCCState *s1 = arg;
    पूर्णांक ea = ((काष्ठा nlist_64 *)_a)->n_मूल्य;
    पूर्णांक eb = ((काष्ठा nlist_64 *)_b)->n_मूल्य;
    ElfSym *sa = (ElfSym *)symtab_section->तथ्य + ea;
    ElfSym *sb = (ElfSym *)symtab_section->तथ्य + eb;
    पूर्णांक r;
    /* locals, then defined externals, then undefined externals, the
       last two sections also by name, otherwise stable sort */
    r = (ELFW(ST_BIND)(sb->st_info) == STB_LOCAL)
        - (ELFW(ST_BIND)(sa->st_info) == STB_LOCAL);
    अगर (r)
      वापस r;
    r = (sa->st_shndx == SHN_UNDEF) - (sb->st_shndx == SHN_UNDEF);
    अगर (r)
      वापस r;
    अगर (ELFW(ST_BIND)(sa->st_info) != STB_LOCAL) {
        स्थिर अक्षर * na = (अक्षर*)symtab_section->link->तथ्य + sa->st_name;
        स्थिर अक्षर * nb = (अक्षर*)symtab_section->link->तथ्य + sb->st_name;
        r = म_भेद(na, nb);
        अगर (r)
          वापस r;
    }
    वापस ea - eb;
}

/* cannot use qsort because code has to be reentrant */
अटल व्योम tcc_qsort (व्योम  *base, माप_प्रकार nel, माप_प्रकार width,
                       पूर्णांक (*comp)(स्थिर व्योम *, स्थिर व्योम *, व्योम *), व्योम *arg)
{
    माप_प्रकार wnel, gap, wgap, i, j, k;
    अक्षर *a, *b, tmp;

    wnel = width * nel;
    क्रम (gap = 0; ++gap < nel;)
        gap *= 3;
    जबतक ( gap /= 3 ) {
        wgap = width * gap;
        क्रम (i = wgap; i < wnel; i += width) {
            क्रम (j = i - wgap; ;j -= wgap) {
                a = j + (अक्षर *)base;
                b = a + wgap;
                अगर ( (*comp)(a, b, arg) <= 0 )
                    अवरोध;
                k = width;
                करो {
                    tmp = *a;
                    *a++ = *b;
                    *b++ = tmp;
                } जबतक ( --k );
                अगर (j < wgap)
                    अवरोध;
            }
        }
    }
}

अटल व्योम create_symtab(TCCState *s1, काष्ठा macho *mo)
{
    पूर्णांक sym_सूचकांक, sym_end;
    काष्ठा nlist_64 *pn;

    /* Stub creation belongs to check_relocs, but we need to create
       the symbol now, so its included in the sorting.  */
    mo->stubs = new_section(s1, "__stubs", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->stubsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stubs->sh_अंक, ".__stubs");
#अगर_घोषित CONFIG_NEW_MACHO
    mo->chained_fixups = new_section(s1, "CHAINED_FIXUPS",
				     SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#अन्यथा
    mo->stub_helper = new_section(s1, "__stub_helper", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    mo->la_प्रतीक_ptr = new_section(s1, "__la_symbol_ptr", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->helpsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stub_helper->sh_अंक, ".__stub_helper");
    mo->lasym = put_elf_sym(s1->symtab, 0, 0,
                            ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                            mo->la_प्रतीक_ptr->sh_अंक, ".__la_symbol_ptr");
    section_ptr_add(तथ्य_section, -तथ्य_section->तथ्य_offset & (PTR_आकार - 1));
    mo->dyld_private = put_elf_sym(s1->symtab, तथ्य_section->तथ्य_offset, PTR_आकार,
                                   ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT), 0,
                                   तथ्य_section->sh_अंक, ".__dyld_private");
    section_ptr_add(तथ्य_section, PTR_आकार);
    mo->dyld_stub_binder = put_elf_sym(s1->symtab, 0, 0,
                		       ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				       SHN_UNDEF, "dyld_stub_binder");
    mo->rebase = new_section(s1, "REBASE", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->binding = new_section(s1, "BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->weak_binding = new_section(s1, "WEAK_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->lazy_binding = new_section(s1, "LAZY_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#पूर्ण_अगर
    mo->exports = new_section(s1, "EXPORT", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->indirsyms = new_section(s1, "LEINDIR", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);

    mo->symtab = new_section(s1, "LESYMTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->strtab = new_section(s1, "LESTRTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    put_elf_str(mo->strtab, " "); /* Mach-O starts strtab with a space */
    sym_end = symtab_section->तथ्य_offset / माप(ElfW(Sym));
    pn = section_ptr_add(mo->symtab, माप(*pn) * (sym_end - 1));
    क्रम (sym_सूचकांक = 1; sym_सूचकांक < sym_end; ++sym_सूचकांक) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->तथ्य + sym_सूचकांक;
        स्थिर अक्षर *name = (अक्षर*)symtab_section->link->तथ्य + sym->st_name;
        pn[sym_सूचकांक - 1].n_strx = put_elf_str(mo->strtab, name);
        pn[sym_सूचकांक - 1].n_मूल्य = sym_सूचकांक;
    }
    section_ptr_add(mo->strtab, -mo->strtab->तथ्य_offset & (PTR_आकार - 1));
    tcc_qsort(pn, sym_end - 1, माप(*pn), machosymcmp, s1);
    mo->e2msym = tcc_malloc(sym_end * माप(*mo->e2msym));
    mo->e2msym[0] = -1;
    क्रम (sym_सूचकांक = 1; sym_सूचकांक < sym_end; ++sym_सूचकांक) {
        mo->e2msym[pn[sym_सूचकांक - 1].n_मूल्य] = sym_सूचकांक - 1;
    }
}

स्थिर काष्ठा {
    पूर्णांक seg_initial;
    uint32_t flags;
    स्थिर अक्षर *name;
} skinfo[sk_last] = {
    /*[sk_unknown] =*/        { 0 },
    /*[sk_discard] =*/        { 0 },
    /*[sk_text] =*/           { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS, "__text" },
    /*[sk_stubs] =*/          { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS | S_प्रतीक_STUBS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stubs" },
    /*[sk_stub_helper] =*/    { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stub_helper" },
    /*[sk_ro_data] =*/        { 2, S_REGULAR, "__rodata" },
    /*[sk_uw_info] =*/        { 0 },
    /*[sk_nl_ptr] =*/         { 2, S_NON_LAZY_प्रतीक_POINTERS, "__got" },
    /*[sk_debug_info] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_info" },
    /*[sk_debug_abbrev] =*/   { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_abbrev" },
    /*[sk_debug_line] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line" },
    /*[sk_debug_aranges] =*/  { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_aranges" },
    /*[sk_debug_str] =*/      { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_str" },
    /*[sk_debug_line_str] =*/ { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line_str" },
    /*[sk_stab] =*/           { 4, S_REGULAR, "__stab" },
    /*[sk_stab_str] =*/       { 4, S_REGULAR, "__stab_str" },
    /*[sk_la_ptr] =*/         { 4, S_LAZY_प्रतीक_POINTERS, "__la_symbol_ptr" },
    /*[sk_init] =*/           { 4, S_MOD_INIT_FUNC_POINTERS, "__mod_init_func" },
    /*[sk_fini] =*/           { 4, S_MOD_TERM_FUNC_POINTERS, "__mod_term_func" },
    /*[sk_rw_data] =*/        { 4, S_REGULAR, "__data" },
    /*[sk_bss] =*/            { 4, S_ZEROFILL, "__bss" },
    /*[sk_linkedit] =*/       { 5, S_REGULAR, शून्य },
};

#घोषणा	START	((uint64_t)1 << 32)

स्थिर काष्ठा {
    पूर्णांक used;
    स्थिर अक्षर *name;
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

#घोषणा	N_SEGMENT	(माप(all_segment)/माप(all_segment[0]))

#अगर_घोषित CONFIG_NEW_MACHO
अटल व्योम calc_fixup_आकार(TCCState *s1, काष्ठा macho *mo)
{
    पूर्णांक i, आकार;

    आकार = (माप(काष्ठा dyld_chained_fixups_header) + 7) & -8;
    आकार += (माप(काष्ठा dyld_chained_starts_in_image) + (mo->nseg - 1) * माप(uint32_t) + 7) & -8;
    क्रम (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	पूर्णांक page_गिनती = (get_segment(mo, i)->vmsize + SEG_PAGE_आकार - 1) / SEG_PAGE_आकार;
	आकार += (माप(काष्ठा dyld_chained_starts_in_segment) + (page_गिनती - 1) * माप(uint16_t) + 7) & -8;
    }
    आकार += mo->n_bind * माप (काष्ठा dyld_chained_import) + 1;
    क्रम (i = 0; i < mo->n_bind_rebase; i++) {
	अगर (mo->bind_rebase[i].bind) {
	    पूर्णांक sym_सूचकांक = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
	    स्थिर अक्षर *name = (अक्षर *) symtab_section->link->तथ्य + sym->st_name;
	    आकार += म_माप(name) + 1;
	}
    }
    आकार = (आकार + 7) & -8;
    section_ptr_add(mo->chained_fixups, आकार);
}

#अन्यथा

अटल व्योम set_segment_and_offset(TCCState *s1, काष्ठा macho *mo, addr_t addr,
				   uint8_t *ptr, पूर्णांक opcode,
				   Section *sec, addr_t offset)
{
    पूर्णांक i;
    काष्ठा segment_command_64 *seg = शून्य;

    क्रम (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	seg = get_segment(mo, i);
	अगर (addr >= seg->vmaddr && addr < (seg->vmaddr + seg->vmsize))
	    अवरोध;
    }
    *ptr = opcode | i;
    write_uleb128(sec, offset - seg->vmaddr);
}

अटल व्योम bind_rebase(TCCState *s1, काष्ठा macho *mo)
{
    पूर्णांक i;
    uint8_t *ptr;
    ElfW(Sym) *sym;
    स्थिर अक्षर *name;

    क्रम (i = 0; i < mo->n_lazy_bind; i++) {
	पूर्णांक sym_सूचकांक = ELFW(R_SYM)(mo->s_lazy_bind[i].rel.r_info);

	sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
	name = (अक्षर *) symtab_section->link->तथ्य + sym->st_name;
	write32le(mo->stub_helper->तथ्य +
		  mo->s_lazy_bind[i].bind_offset,
		  mo->lazy_binding->तथ्य_offset);
	ptr = section_ptr_add(mo->lazy_binding, 1);
	set_segment_and_offset(s1, mo, mo->la_प्रतीक_ptr->sh_addr, ptr,
			       BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB,
			       mo->lazy_binding,
			       mo->s_lazy_bind[i].la_प्रतीक_offset +
			       mo->la_प्रतीक_ptr->sh_addr);
	ptr = section_ptr_add(mo->lazy_binding, 5 + म_माप(name));
	*ptr++ = BIND_OPCODE_SET_DYLIB_SPECIAL_IMM |
		 (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
	*ptr++ = BIND_OPCODE_SET_प्रतीक_TRAILING_FLAGS_IMM | 0;
	म_नकल((अक्षर *)ptr, name);
	ptr += म_माप(name) + 1;
	*ptr++ = BIND_OPCODE_DO_BIND;
	*ptr = BIND_OPCODE_DONE;
    }
    क्रम (i = 0; i < mo->n_rebase; i++) {
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
    क्रम (i = 0; i < mo->n_bind; i++) {
	पूर्णांक sym_सूचकांक = ELFW(R_SYM)(mo->bind[i].rel.r_info);
	Section *s = s1->sections[mo->bind[i].section];
	Section *binding;

	sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
	name = (अक्षर *) symtab_section->link->तथ्य + sym->st_name;
	binding = ELFW(ST_BIND)(sym->st_info) == STB_WEAK
	    ? mo->weak_binding : mo->binding;
        ptr = section_ptr_add(binding, 4 + (binding == mo->binding) +
			     	       म_माप(name));
	अगर (binding == mo->binding)
            *ptr++ = BIND_OPCODE_SET_DYLIB_SPECIAL_IMM |
	             (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
        *ptr++ = BIND_OPCODE_SET_प्रतीक_TRAILING_FLAGS_IMM |
		 (binding == mo->weak_binding
		  ? BIND_प्रतीक_FLAGS_WEAK_IMPORT : 0);
        म_नकल((अक्षर *)ptr, name);
        ptr += म_माप(name) + 1;
        *ptr++ = BIND_OPCODE_SET_TYPE_IMM | BIND_TYPE_POINTER;
	set_segment_and_offset(s1, mo, s->sh_addr, ptr,
			       BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB,
			       binding,
			       mo->bind[i].rel.r_offset + s->sh_addr);
        ptr = section_ptr_add(binding, 1);
        *ptr++ = BIND_OPCODE_DO_BIND;
    }
    अगर (mo->rebase->तथ्य_offset) {
        ptr = section_ptr_add(mo->rebase, 1);
        *ptr = REBASE_OPCODE_DONE;
    }
    अगर (mo->binding->तथ्य_offset) {
        ptr = section_ptr_add(mo->binding, 1);
        *ptr = BIND_OPCODE_DONE;
    }
    अगर (mo->weak_binding->तथ्य_offset) {
        ptr = section_ptr_add(mo->weak_binding, 1);
        *ptr = BIND_OPCODE_DONE;
    }
    tcc_free(mo->s_lazy_bind);
    tcc_free(mo->s_rebase);
    tcc_free(mo->bind);
}
#पूर्ण_अगर

काष्ठा trie_info {
    स्थिर अक्षर *name;
    पूर्णांक flag;
    addr_t addr;
    पूर्णांक str_आकार;
    पूर्णांक term_आकार;
};

काष्ठा trie_गाँठ {
    पूर्णांक start;
    पूर्णांक end;
    पूर्णांक सूचकांक_start;
    पूर्णांक सूचकांक_end;
    पूर्णांक n_child;
    काष्ठा trie_गाँठ *child;
};

काष्ठा trie_seq {
    पूर्णांक n_child;
    काष्ठा trie_गाँठ *गाँठ;
    पूर्णांक offset;
    पूर्णांक nest_offset;
};

अटल व्योम create_trie(काष्ठा trie_गाँठ *गाँठ,
                        पूर्णांक from, पूर्णांक to, पूर्णांक सूचकांक_start,
                        पूर्णांक n_trie, काष्ठा trie_info *trie)
{
    पूर्णांक i;
    पूर्णांक start, end, सूचकांक_end;
    अक्षर cur;
    काष्ठा trie_गाँठ *child;

    क्रम (i = from; i < to; i = end) {
        cur = trie[i].name[सूचकांक_start];
        start = i++;
        क्रम (; i < to; i++)
            अगर (cur != trie[i].name[सूचकांक_start])
                अवरोध;
        end = i;
        अगर (start == end - 1 ||
            (trie[start].name[सूचकांक_start] &&
             trie[start].name[सूचकांक_start + 1] == 0))
            सूचकांक_end = trie[start].str_आकार - 1;
        अन्यथा {
            सूचकांक_end = सूचकांक_start + 1;
            क्रम (;;) {
                cur = trie[start].name[सूचकांक_end];
                क्रम (i = start + 1; i < end; i++)
                    अगर (cur != trie[i].name[सूचकांक_end])
                        अवरोध;
                अगर (trie[start].name[सूचकांक_end] &&
                    trie[start].name[सूचकांक_end + 1] == 0) {
                    end = start + 1;
                    सूचकांक_end = trie[start].str_आकार - 1;
                    अवरोध;
                }
                अगर (i != end)
                    अवरोध;
                सूचकांक_end++;
            }
        }
        गाँठ->child = tcc_realloc(गाँठ->child,
                                  (गाँठ->n_child + 1) *
                                  माप(काष्ठा trie_गाँठ));
        child = &गाँठ->child[गाँठ->n_child];
        child->start = start;
        child->end = end;
        child->सूचकांक_start = सूचकांक_start;
        child->सूचकांक_end = सूचकांक_end;
        child->n_child = 0;
        child->child = शून्य;
        गाँठ->n_child++;
        अगर (start != end - 1)
            create_trie(child, start, end, सूचकांक_end, n_trie, trie);
    }
}

अटल पूर्णांक create_seq(पूर्णांक *offset, पूर्णांक *n_seq, काष्ठा trie_seq **seq,
                        काष्ठा trie_गाँठ *गाँठ,
                        पूर्णांक n_trie, काष्ठा trie_info *trie)
{
    पूर्णांक i, nest_offset, last_seq = *n_seq, retval = *offset;
    काष्ठा trie_seq *p_seq;
    काष्ठा trie_गाँठ *p_nest;

    क्रम (i = 0; i < गाँठ->n_child; i++) {
        p_nest = &गाँठ->child[i];
        *seq = tcc_realloc(*seq, (*n_seq + 1) * माप(काष्ठा trie_seq));
        p_seq = &(*seq)[(*n_seq)++];
        p_seq->n_child = i == 0 ? गाँठ->n_child : -1;
        p_seq->गाँठ = p_nest;
        p_seq->offset = *offset;
        p_seq->nest_offset = 0;
        *offset += (i == 0 ? 1 + 1 : 0) +
                   p_nest->सूचकांक_end - p_nest->सूचकांक_start + 1 + 3;
    }
    क्रम (i = 0; i < गाँठ->n_child; i++) {
        nest_offset =
            create_seq(offset, n_seq, seq, &गाँठ->child[i], n_trie, trie);
        p_seq = &(*seq)[last_seq + i];
        p_seq->nest_offset = nest_offset;
    }
    वापस retval;
}

अटल व्योम गाँठ_free(काष्ठा trie_गाँठ *गाँठ)
{
    पूर्णांक i;

    क्रम (i = 0; i < गाँठ->n_child; i++)
	गाँठ_free(&गाँठ->child[i]);
    tcc_free(गाँठ->child);
}

अटल पूर्णांक triecmp(स्थिर व्योम *_a, स्थिर व्योम *_b, व्योम *arg)
{
    काष्ठा trie_info *a = (काष्ठा trie_info *) _a;
    काष्ठा trie_info *b = (काष्ठा trie_info *) _b;
    पूर्णांक len_a = म_माप(a->name);
    पूर्णांक len_b = म_माप(b->name);

    /* strange sorting needed. Name 'xx' should be after 'xx1' */
    अगर (!म_भेदन(a->name, b->name, len_a < len_b ? len_a : len_b))
	वापस len_a < len_b ? 1 : (len_a > len_b ? -1 : 0);
    वापस म_भेद(a->name, b->name);
}

अटल व्योम export_trie(TCCState *s1, काष्ठा macho *mo)
{
    पूर्णांक i, आकार, offset = 0, save_offset;
    uint8_t *ptr;
    पूर्णांक sym_सूचकांक;
    पूर्णांक sym_end = symtab_section->तथ्य_offset / माप(ElfW(Sym));
    पूर्णांक n_trie = 0, n_seq = 0;
    काष्ठा trie_info *trie = शून्य, *p_trie;
    काष्ठा trie_गाँठ गाँठ, *p_गाँठ;
    काष्ठा trie_seq *seq = शून्य;
    addr_t vm_addr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;

    क्रम (sym_सूचकांक = 1; sym_सूचकांक < sym_end; ++sym_सूचकांक) {
	ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->तथ्य + sym_सूचकांक;
	स्थिर अक्षर *name = (अक्षर*)symtab_section->link->तथ्य + sym->st_name;

	अगर (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE &&
            (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL ||
	     ELFW(ST_BIND)(sym->st_info) == STB_WEAK)) {
	    पूर्णांक flag = EXPORT_प्रतीक_FLAGS_KIND_REGULAR;
	    addr_t addr =
		sym->st_मूल्य + s1->sections[sym->st_shndx]->sh_addr - vm_addr;

	    अगर (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
		flag |= EXPORT_प्रतीक_FLAGS_WEAK_DEFINITION;
	    dprintf ("%s %d %llx\n", name, flag, (दीर्घ दीर्घ)addr + vm_addr);
	    trie = tcc_realloc(trie, (n_trie + 1) * माप(काष्ठा trie_info));
	    trie[n_trie].name = name;
	    trie[n_trie].flag = flag;
	    trie[n_trie].addr = addr;
	    trie[n_trie].str_आकार = म_माप(name) + 1;
	    trie[n_trie].term_आकार = uleb128_आकार(flag) + uleb128_आकार(addr);
	    n_trie++;
	}
    }
    अगर (n_trie) {
        tcc_qsort(trie, n_trie, माप(काष्ठा trie_info), triecmp, शून्य);
	स_रखो(&गाँठ, 0, माप(गाँठ));
        create_trie(&गाँठ, 0, n_trie, 0, n_trie, trie);
	create_seq(&offset, &n_seq, &seq, &गाँठ, n_trie, trie);
        save_offset = offset;
        क्रम (i = 0; i < n_seq; i++) {
            p_गाँठ = seq[i].गाँठ;
            अगर (p_गाँठ->n_child == 0) {
                p_trie = &trie[p_गाँठ->start];
                seq[i].nest_offset = offset;
                offset += 1 + p_trie->term_आकार + 1;
            }
        }
        क्रम (i = 0; i < n_seq; i++) {
            p_गाँठ = seq[i].गाँठ;
            p_trie = &trie[p_गाँठ->start];
            अगर (seq[i].n_child >= 0) {
                section_ptr_add(mo->exports,
				seq[i].offset - mo->exports->तथ्य_offset);
                ptr = section_ptr_add(mo->exports, 2);
                *ptr++ = 0;
                *ptr = seq[i].n_child;
            }
            आकार = p_गाँठ->सूचकांक_end - p_गाँठ->सूचकांक_start;
            ptr = section_ptr_add(mo->exports, आकार + 1);
            स_नकल(ptr, &p_trie->name[p_गाँठ->सूचकांक_start], आकार);
            ptr[आकार] = 0;
            write_uleb128(mo->exports, seq[i].nest_offset);
        }
        section_ptr_add(mo->exports, save_offset - mo->exports->तथ्य_offset);
        क्रम (i = 0; i < n_seq; i++) {
            p_गाँठ = seq[i].गाँठ;
            अगर (p_गाँठ->n_child == 0) {
                p_trie = &trie[p_गाँठ->start];
                write_uleb128(mo->exports, p_trie->term_आकार);
                write_uleb128(mo->exports, p_trie->flag);
                write_uleb128(mo->exports, p_trie->addr);
                ptr = section_ptr_add(mo->exports, 1);
                *ptr = 0;
            }
        }
        section_ptr_add(mo->exports, -mo->exports->तथ्य_offset & 7);
	गाँठ_free(&गाँठ);
        tcc_free(seq);
    }
    tcc_free(trie);
}

अटल व्योम collect_sections(TCCState *s1, काष्ठा macho *mo, स्थिर अक्षर *filename)
{
    पूर्णांक i, sk, numsec;
    पूर्णांक used_segment[N_SEGMENT];
    uint64_t curaddr, fileofs;
    Section *s;
    काष्ठा segment_command_64 *seg;
    काष्ठा dylib_command *dylib;
#अगर_घोषित CONFIG_NEW_MACHO
    काष्ठा linkedit_तथ्य_command *chained_fixups_lc;
    काष्ठा linkedit_तथ्य_command *export_trie_lc;
#पूर्ण_अगर
    काष्ठा build_version_command *dyldbv;
    काष्ठा source_version_command *dyldsv;
    काष्ठा rpath_command *rpath;
    काष्ठा dylinker_command *dyldlc;
    काष्ठा symtab_command *symlc;
    काष्ठा dysymtab_command *dysymlc;
    अक्षर *str;

    क्रम (i = 0; i < N_SEGMENT; i++)
	used_segment[i] = all_segment[i].used;

    स_रखो (mo->sk_to_sect, 0, माप(mo->sk_to_sect));
    क्रम (i = s1->nb_sections; i-- > 1;) {
        पूर्णांक type, flags;
        s = s1->sections[i];
        type = s->sh_type;
        flags = s->sh_flags;
        sk = sk_unknown;
	/* debug sections have sometimes no SHF_ALLOC */
        अगर ((flags & SHF_ALLOC) || !म_भेदन(s->name, ".debug_", 7)) {
            चयन (type) {
            शेष:           sk = sk_unknown; अवरोध;
            हाल SHT_INIT_ARRAY: sk = sk_init; अवरोध;
            हाल SHT_FINI_ARRAY: sk = sk_fini; अवरोध;
            हाल SHT_NOBITS:   sk = sk_bss; अवरोध;
            हाल SHT_SYMTAB:   sk = sk_discard; अवरोध;
            हाल SHT_STRTAB:
		अगर (s == stabstr_section)
		  sk = sk_stab_str;
		अन्यथा
		  sk = sk_discard;
		अवरोध;
            हाल SHT_RELX:     sk = sk_discard; अवरोध;
            हाल SHT_LINKEDIT: sk = sk_linkedit; अवरोध;
            हाल SHT_PROGBITS:
                अगर (s == mo->stubs)
                  sk = sk_stubs;
#अगर_अघोषित CONFIG_NEW_MACHO
                अन्यथा अगर (s == mo->stub_helper)
                  sk = sk_stub_helper;
                अन्यथा अगर (s == mo->la_प्रतीक_ptr)
                  sk = sk_la_ptr;
#पूर्ण_अगर
                अन्यथा अगर (s == rodata_section)
                  sk = sk_ro_तथ्य;
                अन्यथा अगर (s == s1->got)
                  sk = sk_nl_ptr;
                अन्यथा अगर (s == stab_section)
                  sk = sk_stab;
                अन्यथा अगर (s == dwarf_info_section)
                  sk = sk_debug_info;
                अन्यथा अगर (s == dwarf_abbrev_section)
                  sk = sk_debug_abbrev;
                अन्यथा अगर (s == dwarf_पंक्ति_section)
                  sk = sk_debug_पंक्ति;
                अन्यथा अगर (s == dwarf_aranges_section)
                  sk = sk_debug_aranges;
                अन्यथा अगर (s == dwarf_str_section)
                  sk = sk_debug_str;
                अन्यथा अगर (s == dwarf_पंक्ति_str_section)
                  sk = sk_debug_पंक्ति_str;
                अन्यथा अगर (flags & SHF_EXECINSTR)
                  sk = sk_text;
                अन्यथा अगर (flags & SHF_WRITE)
                  sk = sk_rw_तथ्य;
                अन्यथा
                  sk = sk_ro_तथ्य;
                अवरोध;
            }
        } अन्यथा
          sk = sk_discard;
        s->पूर्व = mo->sk_to_sect[sk].s;
        mo->sk_to_sect[sk].s = s;
	used_segment[skinfo[sk].seg_initial] = 1;
    }

    अगर (s1->output_type != TCC_OUTPUT_EXE)
	used_segment[0] = 0;

    क्रम (i = 0; i < N_SEGMENT; i++)
	अगर (used_segment[i]) {
	    seg = add_segment(mo, all_segment[i].name);
	    अगर (i == 1 && s1->output_type != TCC_OUTPUT_EXE)
	        seg->vmaddr = 0;
	    अन्यथा
	        seg->vmaddr = all_segment[i].vmaddr;
	    seg->vmsize = all_segment[i].vmsize;
	    seg->maxprot = all_segment[i].maxprot;
	    seg->initprot = all_segment[i].initprot;
	    seg->flags = all_segment[i].flags;
            क्रम (sk = sk_unknown; sk < sk_last; sk++)
		अगर (skinfo[sk].seg_initial == i)
	            mo->segment[sk] = mo->nseg - 1;
	}

    अगर (s1->output_type != TCC_OUTPUT_EXE) {
	स्थिर अक्षर *name = s1->install_name ? s1->install_name : filename;
        i = (माप(*dylib) + म_माप(name) + 1 + 7) &-8;
        dylib = add_lc(mo, LC_ID_DYLIB, i);
	dylib->name = माप(*dylib);
	dylib->timestamp = 1;
	dylib->current_version =
	    s1->current_version ? s1->current_version : 1 << 16;
	dylib->compatibility_version =
	    s1->compatibility_version ? s1->compatibility_version : 1 << 16;
        str = (अक्षर*)dylib + dylib->name;
        म_नकल(str, name);
    }

#अगर_घोषित CONFIG_NEW_MACHO
    chained_fixups_lc = add_lc(mo, LC_DYLD_CHAINED_FIXUPS,
			       माप(काष्ठा linkedit_तथ्य_command));
    export_trie_lc = add_lc(mo, LC_DYLD_EXPORTS_TRIE,
			    माप(काष्ठा linkedit_तथ्य_command));
#अन्यथा
    mo->dyldinfo = add_lc(mo, LC_DYLD_INFO_ONLY, माप(*mo->dyldinfo));
#पूर्ण_अगर

    symlc = add_lc(mo, LC_SYMTAB, माप(*symlc));
    dysymlc = add_lc(mo, LC_DYSYMTAB, माप(*dysymlc));

    अगर (s1->output_type == TCC_OUTPUT_EXE) {
        i = (माप(*dyldlc) + म_माप("/usr/lib/dyld") + 1 + 7) &-8;
        dyldlc = add_lc(mo, LC_LOAD_DYLINKER, i);
        dyldlc->name = माप(*dyldlc);
        str = (अक्षर*)dyldlc + dyldlc->name;
        म_नकल(str, "/usr/lib/dyld");
    }

    dyldbv = add_lc(mo, LC_BUILD_VERSION, माप(*dyldbv));
    dyldbv->platform = PLATFORM_MACOS;
    dyldbv->minos = (10 << 16) + (6 << 8);
    dyldbv->sdk = (10 << 16) + (6 << 8);
    dyldbv->ntools = 0;

    dyldsv = add_lc(mo, LC_SOURCE_VERSION, माप(*dyldsv));
    dyldsv->version = 0;

    अगर (s1->output_type == TCC_OUTPUT_EXE) {
        mo->ep = add_lc(mo, LC_MAIN, माप(*mo->ep));
        mo->ep->entryoff = 4096;
    }

    क्रम(i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *dllref = s1->loaded_dlls[i];
        अगर (dllref->level == 0)
          add_dylib(mo, dllref->name);
    }

    अगर (s1->rpath) {
	अक्षर *path = s1->rpath, *end;
	करो {
	    end = म_अक्षर(path, ':');
	    अगर (!end)
		end = म_अक्षर(path, 0);
            i = (माप(*rpath) + (end - path) + 1 + 7) &-8;
            rpath = add_lc(mo, LC_RPATH, i);
            rpath->path = माप(*rpath);
            str = (अक्षर*)rpath + rpath->path;
            स_नकल(str, path, end - path);
	    str[end - path] = 0;
	    path = end + 1;
	} जबतक (*end);
    }

    fileofs = 4096;  /* leave space for mach-o headers */
    curaddr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;
    curaddr += 4096;
    seg = शून्य;
    numsec = 0;
    mo->elfsectomacho = tcc_mallocz(माप(*mo->elfsectomacho) * s1->nb_sections);
    क्रम (sk = sk_unknown; sk < sk_last; sk++) {
        काष्ठा section_64 *sec = शून्य;
        अगर (seg) {
            seg->vmsize = curaddr - seg->vmaddr;
            seg->filesize = fileofs - seg->fileoff;
        }
#अगर_घोषित CONFIG_NEW_MACHO
	अगर (sk == sk_linkedit) {
	    calc_fixup_आकार(s1, mo);
	    export_trie(s1, mo);
	}
#अन्यथा
	अगर (sk == sk_linkedit) {
	    bind_rebase(s1, mo);
	    export_trie(s1, mo);
	}
#पूर्ण_अगर
        अगर (skinfo[sk].seg_initial &&
	    (s1->output_type != TCC_OUTPUT_EXE || mo->segment[sk]) &&
	    mo->sk_to_sect[sk].s) {
            uint64_t al = 0;
            पूर्णांक si;
            seg = get_segment(mo, mo->segment[sk]);
            अगर (skinfo[sk].name) {
                si = add_section(mo, &seg, skinfo[sk].name);
                numsec++;
                mo->lc[mo->seg2lc[mo->segment[sk]]] = (काष्ठा load_command*)seg;
                mo->sk_to_sect[sk].machosect = si;
                sec = get_section(seg, si);
                sec->flags = skinfo[sk].flags;
		अगर (sk == sk_stubs)
#अगर_घोषित TCC_TARGET_X86_64
	    	    sec->reserved2 = 6;
#या_अगर defined TCC_TARGET_ARM64
	    	    sec->reserved2 = 12;
#पूर्ण_अगर
		अगर (sk == sk_nl_ptr)
	    	    sec->reserved1 = mo->nr_plt;
#अगर_अघोषित CONFIG_NEW_MACHO
		अगर (sk == sk_la_ptr)
	    	    sec->reserved1 = mo->nr_plt + mo->n_got;
#पूर्ण_अगर
            }
            अगर (seg->vmaddr == -1) {
                curaddr = (curaddr + SEG_PAGE_आकार - 1) & -SEG_PAGE_आकार;
                seg->vmaddr = curaddr;
                fileofs = (fileofs + SEG_PAGE_आकार - 1) & -SEG_PAGE_आकार;
                seg->fileoff = fileofs;
            }

            क्रम (s = mo->sk_to_sect[sk].s; s; s = s->पूर्व) {
                पूर्णांक a = exact_log2p1(s->sh_addralign);
                अगर (a && al < (a - 1))
                  al = a - 1;
                s->sh_आकार = s->तथ्य_offset;
            }
            अगर (sec)
              sec->align = al;
            al = 1ULL << al;
            अगर (al > 4096)
              tcc_warning("alignment > 4096"), sec->align = 12, al = 4096;
            curaddr = (curaddr + al - 1) & -al;
            fileofs = (fileofs + al - 1) & -al;
            अगर (sec) {
                sec->addr = curaddr;
                sec->offset = fileofs;
            }
            क्रम (s = mo->sk_to_sect[sk].s; s; s = s->पूर्व) {
                al = s->sh_addralign;
                curaddr = (curaddr + al - 1) & -al;
                dprintf("%s: curaddr now 0x%lx\n", s->name, (दीर्घ)curaddr);
                s->sh_addr = curaddr;
                curaddr += s->sh_आकार;
                अगर (s->sh_type != SHT_NOBITS) {
                    fileofs = (fileofs + al - 1) & -al;
                    s->sh_offset = fileofs;
                    fileofs += s->sh_आकार;
                    dprintf("%s: fileofs now %ld\n", s->name, (दीर्घ)fileofs);
                }
                अगर (sec)
                  mo->elfsectomacho[s->sh_अंक] = numsec;
            }
            अगर (sec)
              sec->आकार = curaddr - sec->addr;
        }
        अगर (DEBUG_MACHO)
          क्रम (s = mo->sk_to_sect[sk].s; s; s = s->पूर्व) {
              पूर्णांक type = s->sh_type;
              पूर्णांक flags = s->sh_flags;
              म_लिखो("%d section %-16s %-10s %09lx %04x %02d %s,%s,%s\n",
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
                     (अचिन्हित)s->तथ्य_offset,
                     s->sh_addralign,
                     flags & SHF_ALLOC ? "alloc" : "",
                     flags & SHF_WRITE ? "write" : "",
                     flags & SHF_EXECINSTR ? "exec" : ""
                    );
          }
    }
    अगर (seg) {
        seg->vmsize = curaddr - seg->vmaddr;
        seg->filesize = fileofs - seg->fileoff;
    }

    /* Fill symtab info */
    symlc->symoff = mo->symtab->sh_offset;
    symlc->nsyms = mo->symtab->तथ्य_offset / माप(काष्ठा nlist_64);
    symlc->stroff = mo->strtab->sh_offset;
    symlc->strsize = mo->strtab->तथ्य_offset;

    dysymlc->iundefsym = mo->iundef == -1 ? symlc->nsyms : mo->iundef;
    dysymlc->iextdefsym = mo->iextdef == -1 ? dysymlc->iundefsym : mo->iextdef;
    dysymlc->ilocalsym = mo->ilocal == -1 ? dysymlc->iextdefsym : mo->ilocal;
    dysymlc->nlocalsym = dysymlc->iextdefsym - dysymlc->ilocalsym;
    dysymlc->nextdefsym = dysymlc->iundefsym - dysymlc->iextdefsym;
    dysymlc->nundefsym = symlc->nsyms - dysymlc->iundefsym;
    dysymlc->indirectsymoff = mo->indirsyms->sh_offset;
    dysymlc->nindirectsyms = mo->indirsyms->तथ्य_offset / माप(uint32_t);

#अगर_घोषित CONFIG_NEW_MACHO
    अगर (mo->chained_fixups->तथ्य_offset) {
        chained_fixups_lc->dataoff = mo->chained_fixups->sh_offset;
        chained_fixups_lc->datasize = mo->chained_fixups->तथ्य_offset;
    }
    अगर (mo->exports->तथ्य_offset) {
        export_trie_lc->dataoff = mo->exports->sh_offset;
        export_trie_lc->datasize = mo->exports->तथ्य_offset;
    }
#अन्यथा
    अगर (mo->rebase->तथ्य_offset) {
        mo->dyldinfo->rebase_off = mo->rebase->sh_offset;
        mo->dyldinfo->rebase_आकार = mo->rebase->तथ्य_offset;
    }
    अगर (mo->binding->तथ्य_offset) {
        mo->dyldinfo->bind_off = mo->binding->sh_offset;
        mo->dyldinfo->bind_आकार = mo->binding->तथ्य_offset;
    }
    अगर (mo->weak_binding->तथ्य_offset) {
        mo->dyldinfo->weak_bind_off = mo->weak_binding->sh_offset;
        mo->dyldinfo->weak_bind_आकार = mo->weak_binding->तथ्य_offset;
    }
    अगर (mo->lazy_binding->तथ्य_offset) {
        mo->dyldinfo->lazy_bind_off = mo->lazy_binding->sh_offset;
        mo->dyldinfo->lazy_bind_आकार = mo->lazy_binding->तथ्य_offset;
    }
    अगर (mo->exports->तथ्य_offset) {
        mo->dyldinfo->export_off = mo->exports->sh_offset;
        mo->dyldinfo->export_आकार = mo->exports->तथ्य_offset;
    }
#पूर्ण_अगर
}

अटल व्योम macho_write(TCCState *s1, काष्ठा macho *mo, खाता *fp)
{
    पूर्णांक i, sk;
    uint64_t fileofs = 0;
    Section *s;
    mo->mh.mh.magic = MH_MAGIC_64;
#अगर_घोषित TCC_TARGET_X86_64
    mo->mh.mh.cputype = CPU_TYPE_X86_64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_LIB64 | CPU_SUBTYPE_X86_ALL;
#या_अगर defined TCC_TARGET_ARM64
    mo->mh.mh.cputype = CPU_TYPE_ARM64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_ARM64_ALL;
#पूर्ण_अगर
    अगर (s1->output_type == TCC_OUTPUT_EXE) {
        mo->mh.mh.filetype = MH_EXECUTE;
        mo->mh.mh.flags = MH_DYLDLINK | MH_PIE;
    }
    अन्यथा {
        mo->mh.mh.filetype = MH_DYLIB;
        mo->mh.mh.flags = MH_DYLDLINK;
    }
    mo->mh.mh.ncmds = mo->nlc;
    mo->mh.mh.sizeofcmds = 0;
    क्रम (i = 0; i < mo->nlc; i++)
      mo->mh.mh.sizeofcmds += mo->lc[i]->cmdsize;

    ख_डालो(&mo->mh, 1, माप(mo->mh), fp);
    fileofs += माप(mo->mh);
    क्रम (i = 0; i < mo->nlc; i++) {
        ख_डालो(mo->lc[i], 1, mo->lc[i]->cmdsize, fp);
        fileofs += mo->lc[i]->cmdsize;
    }

    क्रम (sk = sk_unknown; sk < sk_last; sk++) {
        //struct segment_command_64 *seg;
        अगर (skinfo[sk].seg_initial == 0 ||
	    (s1->output_type == TCC_OUTPUT_EXE && !mo->segment[sk]) ||
	    !mo->sk_to_sect[sk].s)
          जारी;
        /*seg =*/ get_segment(mo, mo->segment[sk]);
        क्रम (s = mo->sk_to_sect[sk].s; s; s = s->पूर्व) {
            अगर (s->sh_type != SHT_NOBITS) {
                जबतक (fileofs < s->sh_offset)
                  ख_अक्षर_दो(0, fp), fileofs++;
                अगर (s->sh_आकार) {
                    ख_डालो(s->तथ्य, 1, s->sh_आकार, fp);
                    fileofs += s->sh_आकार;
                }
            }
        }
    }
}

#अगर_घोषित CONFIG_NEW_MACHO
अटल पूर्णांक bind_rebase_cmp(स्थिर व्योम *_a, स्थिर व्योम *_b, व्योम *arg)
{
    TCCState *s1 = arg;
    काष्ठा bind_rebase *a = (काष्ठा bind_rebase *) _a;
    काष्ठा bind_rebase *b = (काष्ठा bind_rebase *) _b;
    addr_t aa = s1->sections[a->section]->sh_addr + a->rel.r_offset;
    addr_t ab = s1->sections[b->section]->sh_addr + b->rel.r_offset;

    वापस aa > ab ? 1 : aa < ab ? -1 : 0;
}

ST_FUNC व्योम bind_rebase_import(TCCState *s1, काष्ठा macho *mo)
{
    पूर्णांक i, j, k, bind_सूचकांक, आकार, page_गिनती, sym_सूचकांक;
    स्थिर अक्षर *name;
    ElfW(Sym) *sym;
    अचिन्हित अक्षर *तथ्य = mo->chained_fixups->तथ्य;
    काष्ठा segment_command_64 *seg;
    काष्ठा dyld_chained_fixups_header *header;
    काष्ठा dyld_chained_starts_in_image *image;
    काष्ठा dyld_chained_starts_in_segment *segment;
    काष्ठा dyld_chained_import *import;

    tcc_qsort(mo->bind_rebase, mo->n_bind_rebase, माप(काष्ठा bind_rebase),
	      bind_rebase_cmp, s1);
    क्रम (i = 0; i < mo->n_bind_rebase - 1; i++)
	अगर (mo->bind_rebase[i].section == mo->bind_rebase[i + 1].section &&
	    mo->bind_rebase[i].rel.r_offset == mo->bind_rebase[i + 1].rel.r_offset) {
	    sym_सूचकांक = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
            sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
	    name = (अक्षर *) symtab_section->link->तथ्य + sym->st_name;
	    tcc_error("Overlap %s/%s %s:%s",
		      mo->bind_rebase[i].bind ? "bind" : "rebase",
		      mo->bind_rebase[i + 1].bind ? "bind" : "rebase",
		      s1->sections[mo->bind_rebase[i].section]->name, name);
	}
    header = (काष्ठा dyld_chained_fixups_header *) तथ्य;
    तथ्य += (माप(काष्ठा dyld_chained_fixups_header) + 7) & -8;
    header->starts_offset = तथ्य - mo->chained_fixups->तथ्य;
    header->imports_गिनती = mo->n_bind;
    header->imports_format = DYLD_CHAINED_IMPORT;
    header->symbols_format = 0;
    आकार = माप(काष्ठा dyld_chained_starts_in_image) +
	   (mo->nseg - 1) * माप(uint32_t);
    image = (काष्ठा dyld_chained_starts_in_image *) तथ्य;
    तथ्य += (आकार + 7) & -8;
    image->seg_गिनती = mo->nseg;
    क्रम (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
        image->seg_info_offset[i] = (तथ्य - mo->chained_fixups->तथ्य) -
				    header->starts_offset;
	seg = get_segment(mo, i);
	page_गिनती = (seg->vmsize + SEG_PAGE_आकार - 1) / SEG_PAGE_आकार;
	आकार = माप(काष्ठा dyld_chained_starts_in_segment) +
		      (page_गिनती - 1) * माप(uint16_t);
        segment = (काष्ठा dyld_chained_starts_in_segment *) तथ्य;
        तथ्य += (आकार + 7) & -8;
        segment->आकार = आकार;
        segment->page_आकार = SEG_PAGE_आकार;
#अगर 1
#घोषणा	PTR_64_OFFSET 0
#घोषणा	PTR_64_MASK   0x7FFFFFFFFFFULL
        segment->pointer_format = DYLD_CHAINED_PTR_64;
#अन्यथा
#घोषणा	PTR_64_OFFSET 0x100000000ULL
#घोषणा	PTR_64_MASK   0xFFFFFFFFFFFFFFULL
        segment->pointer_format = DYLD_CHAINED_PTR_64_OFFSET;
#पूर्ण_अगर
        segment->segment_offset = seg->fileoff;
        segment->max_valid_pointer = 0;
        segment->page_गिनती = page_गिनती;
	// add bind/rebase
	bind_सूचकांक = 0;
	k = 0;
	क्रम (j = 0; j < page_गिनती; j++) {
	    addr_t start = seg->vmaddr + j * SEG_PAGE_आकार;
	    addr_t end = start + SEG_PAGE_आकार;
	    व्योम *last = शून्य;
	    addr_t last_o = 0;
	    addr_t cur_o, cur;
	    काष्ठा dyld_chained_ptr_64_rebase *rebase;
	    काष्ठा dyld_chained_ptr_64_bind *bind;

	    segment->page_start[j] = DYLD_CHAINED_PTR_START_NONE;
	    क्रम (; k < mo->n_bind_rebase; k++) {
	        Section *s = s1->sections[mo->bind_rebase[k].section];
		addr_t r_offset = mo->bind_rebase[k].rel.r_offset;
		addr_t addr = s->sh_addr + r_offset;

		अगर ((addr & 3) ||
		    (addr & (SEG_PAGE_आकार - 1)) > SEG_PAGE_आकार - PTR_आकार)
		    tcc_error("Illegal rel_offset %s %lld",
			      s->name, (दीर्घ दीर्घ)r_offset);
		अगर (addr >= end)
		    अवरोध;
		अगर (addr >= start) {
		    cur_o = addr - start;
	            अगर (mo->bind_rebase[k].bind) {
		        अगर (segment->page_start[j] == DYLD_CHAINED_PTR_START_NONE)
			    segment->page_start[j] = cur_o;
		        अन्यथा {
			    bind = (काष्ठा dyld_chained_ptr_64_bind *) last;
			    bind->अग्र = (cur_o - last_o) / 4;
		        }
		        bind = (काष्ठा dyld_chained_ptr_64_bind *)
				    (s->तथ्य + r_offset);
		        last = bind;
		        last_o = cur_o;
		        bind->ordinal = bind_सूचकांक;
		        bind->addend = 0;
		        bind->reserved = 0;
		        bind->अग्र = 0;
		        bind->bind = 1;
		    }
		    अन्यथा {
		        अगर (segment->page_start[j] == DYLD_CHAINED_PTR_START_NONE)
			    segment->page_start[j] = cur_o;
		        अन्यथा {
			    rebase = (काष्ठा dyld_chained_ptr_64_rebase *) last;
			    rebase->अग्र = (cur_o - last_o) / 4;
		        }
		        rebase = (काष्ठा dyld_chained_ptr_64_rebase *)
				    (s->तथ्य + r_offset);
		        last = rebase;
		        last_o = cur_o;
		        cur = (*(uint64_t *) (s->तथ्य + r_offset)) -
			      PTR_64_OFFSET;
		        rebase->target = cur & PTR_64_MASK;
		        rebase->high8 = cur >> (64 - 8);
			अगर (cur != ((uint64_t)rebase->high8 << (64 - 8)) + rebase->target)
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
    header->imports_offset = तथ्य - mo->chained_fixups->तथ्य;
    import = (काष्ठा dyld_chained_import *) तथ्य;
    तथ्य += mo->n_bind * माप (काष्ठा dyld_chained_import);
    header->symbols_offset = तथ्य - mo->chained_fixups->तथ्य;
    तथ्य++;
    क्रम (i = 0, bind_सूचकांक = 0; i < mo->n_bind_rebase; i++) {
	अगर (mo->bind_rebase[i].bind) {
	    import[bind_सूचकांक].lib_ordinal =
		BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xffu;
	    import[bind_सूचकांक].name_offset =
		(तथ्य - mo->chained_fixups->तथ्य) - header->symbols_offset;
	    sym_सूचकांक = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    sym = &((ElfW(Sym) *)symtab_section->तथ्य)[sym_सूचकांक];
	    import[bind_सूचकांक].weak_import =
		ELFW(ST_BIND)(sym->st_info) == STB_WEAK;
	    name = (अक्षर *) symtab_section->link->तथ्य + sym->st_name;
            म_नकल((अक्षर *) तथ्य, name);
	    तथ्य += म_माप(name) + 1;
	    bind_सूचकांक++;
	}
    }
    tcc_free(mo->bind_rebase);
}
#पूर्ण_अगर

ST_FUNC पूर्णांक macho_output_file(TCCState *s1, स्थिर अक्षर *filename)
{
    पूर्णांक fd, mode, file_type;
    खाता *fp;
    पूर्णांक i, ret = -1;
    काष्ठा macho mo;

    (व्योम)स_रखो(&mo, 0, माप(mo));

    file_type = s1->output_type;
    अगर (file_type == TCC_OUTPUT_OBJ)
        mode = 0666;
    अन्यथा
        mode = 0777;
    unlink(filename);
    fd = खोलो(filename, O_WRONLY | O_CREAT | O_TRUNC | O_द्विआधारी_2, mode);
    अगर (fd < 0 || (fp = fdopen(fd, "wb")) == शून्य) {
        tcc_error_noabort("could not write '%s: %s'", filename, म_त्रुटि(त्रुटि_सं));
        वापस -1;
    }
    tcc_add_runtime(s1);
    tcc_macho_add_destructor(s1);
    resolve_common_syms(s1);
    create_symtab(s1, &mo);
    check_relocs(s1, &mo);
    ret = check_symbols(s1, &mo);
    अगर (!ret) {
	पूर्णांक save_output = s1->output_type;

        collect_sections(s1, &mo, filename);
        relocate_syms(s1, s1->symtab, 0);
	अगर (s1->output_type == TCC_OUTPUT_EXE)
            mo.ep->entryoff = get_sym_addr(s1, "main", 1, 1)
                            -     get_segment(&mo, 1)->vmaddr;
        अगर (s1->nb_errors)
          जाओ do_ret;
	// Macho uses bind/rebase instead of dynsym
	s1->output_type = TCC_OUTPUT_EXE;
        relocate_sections(s1);
	s1->output_type = save_output;
#अगर_घोषित CONFIG_NEW_MACHO
	bind_rebase_import(s1, &mo);
#पूर्ण_अगर
        convert_symbols(s1, &mo);
        अगर (s1->verbose)
            म_लिखो("<- %s\n", filename);
        macho_write(s1, &mo, fp);
    }

 do_ret:
    क्रम (i = 0; i < mo.nlc; i++)
      tcc_free(mo.lc[i]);
    tcc_free(mo.seg2lc);
    tcc_free(mo.lc);
    tcc_free(mo.elfsectomacho);
    tcc_free(mo.e2msym);

    ख_बंद(fp);
#अगर_घोषित CONFIG_CODESIGN
    अगर (!ret) {
	अक्षर command[1024];
	पूर्णांक retval;

	snprintf(command, माप(command), "codesign -f -s - %s", filename);
	retval = प्रणाली (command);
	अगर (retval == -1 || !(WIFEXITED(retval) && WEXITSTATUS(retval) == 0))
	    tcc_error ("command failed '%s'", command);
    }
#पूर्ण_अगर
    वापस ret;
}

अटल uint32_t macho_swap32(uint32_t x)
{
  वापस (x >> 24) | (x << 24) | ((x >> 8) & 0xff00) | ((x & 0xff00) << 8);
}
#घोषणा SWAP(x) (swap ? macho_swap32(x) : (x))
#घोषणा tbd_parse_movepast(s) \
    (pos = (pos = म_माला(pos, s)) ? pos + म_माप(s) : शून्य)
#घोषणा tbd_parse_movetoany(cs) (pos = strpbrk(pos, cs))
#घोषणा tbd_parse_skipws जबतक (*pos && (*pos==' '||*pos=='\n')) ++pos
#घोषणा tbd_parse_tramplequote अगर(*pos=='\''||*pos=='"') tbd_parse_trample
#घोषणा tbd_parse_tramplespace अगर(*pos==' ') tbd_parse_trample
#घोषणा tbd_parse_trample *pos++=0

#अगर_घोषित TCC_IS_NATIVE
/* Looks for the active developer SDK set by xcode-select (or the default
   one set during installation.) */
ST_FUNC व्योम tcc_add_macos_sdkpath(TCCState* s)
{
    अक्षर *sdkroot = शून्य, *pos = शून्य;
    व्योम* xcs = dlopen("libxcselect.dylib", RTLD_GLOBAL | RTLD_LAZY);
    CString path;
    पूर्णांक (*f)(अचिन्हित पूर्णांक, अक्षर**) = dlsym(xcs, "xcselect_host_sdk_path");
    cstr_new(&path);
    अगर (f) f(1, &sdkroot);
    अगर (sdkroot)
        pos = म_माला(sdkroot,"SDKs/MacOSX");
    अगर (pos)
        cstr_printf(&path, "%.*s.sdk/usr/lib", (पूर्णांक)(pos - sdkroot + 11), sdkroot);
    /* must use free from libc directly */
#आशय धकेलो_macro("free")
#अघोषित मुक्त
    मुक्त(sdkroot);
#आशय निकालो_macro("free")
    अगर (path.आकार)
        tcc_add_library_path(s, (अक्षर*)path.तथ्य);
    अन्यथा
        tcc_add_library_path(s,
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib"
            ":" "/Applications/Xcode.app/Developer/SDKs/MacOSX.sdk/usr/lib"
            );
    cstr_free(&path);
}

ST_FUNC अक्षर* macho_tbd_soname(पूर्णांक fd) {
    अक्षर *soname, *तथ्य, *pos;
    अक्षर *ret = 0;
    pos = तथ्य = tcc_load_text(fd);
    अगर (!tbd_parse_movepast("install-name: ")) जाओ the_end;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    अगर (!tbd_parse_movetoany("\n \"'")) जाओ the_end;
    tbd_parse_trample;
    ret = tcc_strdup(soname);
the_end:
    tcc_free(तथ्य);
    वापस ret;
}
#पूर्ण_अगर /* TCC_IS_NATIVE */

ST_FUNC पूर्णांक macho_load_tbd(TCCState* s1, पूर्णांक fd, स्थिर अक्षर* filename, पूर्णांक lev)
{
    अक्षर *soname, *तथ्य, *pos;
    पूर्णांक ret = -1;

    pos = तथ्य = tcc_load_text(fd);
    अगर (!tbd_parse_movepast("install-name: ")) जाओ the_end;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    अगर (!tbd_parse_movetoany("\n \"'")) जाओ the_end;
    tbd_parse_trample;
    ret = 0;
    अगर (tcc_add_dllref(s1, soname, lev)->found)
        जाओ the_end;
    जबतक(pos) {
        अक्षर* sym = शून्य;
        पूर्णांक cont = 1;
        अगर (!tbd_parse_movepast("symbols: ")) अवरोध;
        अगर (!tbd_parse_movepast("[")) अवरोध;
        जबतक (cont) {
            tbd_parse_skipws;
            tbd_parse_tramplequote;
            sym = pos;
            अगर (!tbd_parse_movetoany(",] \"'")) अवरोध;
            tbd_parse_tramplequote;
            tbd_parse_tramplespace;
            tbd_parse_skipws;
            अगर (*pos==0||*pos==']') cont=0;
            tbd_parse_trample;
            set_elf_sym(s1->dynsymtab_section, 0, 0,
                ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0, SHN_UNDEF, sym);
        }
    }

the_end:
    tcc_free(तथ्य);
    वापस ret;
}

ST_FUNC पूर्णांक macho_load_dll(TCCState * s1, पूर्णांक fd, स्थिर अक्षर* filename, पूर्णांक lev)
{
    अचिन्हित अक्षर buf[माप(काष्ठा mach_header_64)];
    व्योम *buf2;
    uint32_t machofs = 0;
    काष्ठा fat_header fh;
    काष्ठा mach_header mh;
    काष्ठा load_command *lc;
    पूर्णांक i, swap = 0;
    स्थिर अक्षर *soname = filename;
    काष्ठा nlist_64 *symtab = 0;
    uint32_t nsyms = 0;
    अक्षर *strtab = 0;
    uint32_t strsize = 0;
    uint32_t iextdef = 0;
    uint32_t nextdef = 0;

  again:
    अगर (full_read(fd, buf, माप(buf)) != माप(buf))
      वापस -1;
    स_नकल(&fh, buf, माप(fh));
    अगर (fh.magic == FAT_MAGIC || fh.magic == FAT_CIGAM) {
        काष्ठा fat_arch *fa = load_तथ्य(fd, माप(fh),
                                        fh.nfat_arch * माप(*fa));
        swap = fh.magic == FAT_CIGAM;
        क्रम (i = 0; i < SWAP(fh.nfat_arch); i++)
#अगर_घोषित TCC_TARGET_X86_64
          अगर (SWAP(fa[i].cputype) == CPU_TYPE_X86_64
              && SWAP(fa[i].cpusubtype) == CPU_SUBTYPE_X86_ALL)
#या_अगर defined TCC_TARGET_ARM64
          अगर (SWAP(fa[i].cputype) == CPU_TYPE_ARM64
              && SWAP(fa[i].cpusubtype) == CPU_SUBTYPE_ARM64_ALL)
#पूर्ण_अगर
            अवरोध;
        अगर (i == SWAP(fh.nfat_arch)) {
            tcc_free(fa);
            वापस -1;
        }
        machofs = SWAP(fa[i].offset);
        tcc_free(fa);
        lseek(fd, machofs, शुरू_से);
        जाओ again;
    } अन्यथा अगर (fh.magic == FAT_MAGIC_64 || fh.magic == FAT_CIGAM_64) {
        tcc_warning("%s: Mach-O fat 64bit files of type 0x%x not handled",
                    filename, fh.magic);
        वापस -1;
    }

    स_नकल(&mh, buf, माप(mh));
    अगर (mh.magic != MH_MAGIC_64)
      वापस -1;
    dprintf("found Mach-O at %d\n", machofs);
    buf2 = load_तथ्य(fd, machofs + माप(काष्ठा mach_header_64), mh.sizeofcmds);
    क्रम (i = 0, lc = buf2; i < mh.ncmds; i++) {
        dprintf("lc %2d: 0x%08x\n", i, lc->cmd);
        चयन (lc->cmd) {
        हाल LC_SYMTAB:
        {
            काष्ठा symtab_command *sc = (काष्ठा symtab_command*)lc;
            nsyms = sc->nsyms;
            symtab = load_तथ्य(fd, machofs + sc->symoff, nsyms * माप(*symtab));
            strsize = sc->strsize;
            strtab = load_तथ्य(fd, machofs + sc->stroff, strsize);
            अवरोध;
        }
        हाल LC_ID_DYLIB:
        {
            काष्ठा dylib_command *dc = (काष्ठा dylib_command*)lc;
            soname = (अक्षर*)lc + dc->name;
            dprintf(" ID_DYLIB %d 0x%x 0x%x %s\n",
                    dc->timestamp, dc->current_version,
                    dc->compatibility_version, soname);
            अवरोध;
        }
        हाल LC_REEXPORT_DYLIB:
        {
            काष्ठा dylib_command *dc = (काष्ठा dylib_command*)lc;
            अक्षर *name = (अक्षर*)lc + dc->name;
            पूर्णांक subfd = खोलो(name, O_RDONLY | O_द्विआधारी_2);
            dprintf(" REEXPORT %s\n", name);
            अगर (subfd < 0)
              tcc_warning("can't open %s (reexported from %s)", name, filename);
            अन्यथा {
                /* Hopefully the REEXPORTs never form a cycle, we don't check
                   for that!  */
                macho_load_dll(s1, subfd, name, lev + 1);
                बंद(subfd);
            }
            अवरोध;
        }
        हाल LC_DYSYMTAB:
        {
            काष्ठा dysymtab_command *dc = (काष्ठा dysymtab_command*)lc;
            iextdef = dc->iextdefsym;
            nextdef = dc->nextdefsym;
            अवरोध;
        }
        }
        lc = (काष्ठा load_command*) ((अक्षर*)lc + lc->cmdsize);
    }

    अगर (tcc_add_dllref(s1, soname, lev)->found)
        जाओ the_end;

    अगर (!nsyms || !nextdef)
      tcc_warning("%s doesn't export any symbols?", filename);

    //dprintf("symbols (all):\n");
    dprintf("symbols (exported):\n");
    dprintf("    n: typ sec   desc              value name\n");
    //for (i = 0; i < nsyms; i++) {
    क्रम (i = iextdef; i < iextdef + nextdef; i++) {
        काष्ठा nlist_64 *sym = symtab + i;
        dprintf("%5d: %3d %3d 0x%04x 0x%016lx %s\n",
                i, sym->n_type, sym->n_sect, sym->n_desc, (दीर्घ)sym->n_मूल्य,
                strtab + sym->n_strx);
        set_elf_sym(s1->dynsymtab_section, 0, 0,
                    ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
                    0, SHN_UNDEF, strtab + sym->n_strx);
    }

  the_end:
    tcc_free(strtab);
    tcc_free(symtab);
    tcc_free(buf2);
    वापस 0;
}
