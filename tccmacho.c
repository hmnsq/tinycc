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
#અન્તર્ભાવ "tcc.h"

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

#જો !defined TCC_TARGET_X86_64 && !defined TCC_TARGET_ARM64
#error Platform not supported
#endif

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#undef _tcc_error

#define DEBUG_MACHO 0
#define dprintf જો (DEBUG_MACHO) printf

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

સંરચના fat_header {
    uint32_t        magic;          /* FAT_MAGIC or FAT_MAGIC_64 */
    uint32_t        nfat_arch;      /* number of structs that follow */
};

સંરચના fat_arch {
    પૂર્ણાંક             cputype;        /* cpu specifier (int) */
    પૂર્ણાંક             cpusubtype;     /* machine specifier (int) */
    uint32_t        offset;         /* file offset to this object file */
    uint32_t        size;           /* size of this object file */
    uint32_t        align;          /* alignment as a power of 2 */
};

#define FAT_MAGIC       0xcafebabe
#define FAT_CIGAM       0xbebafeca
#define FAT_MAGIC_64    0xcafebabf
#define FAT_CIGAM_64    0xbfbafeca

સંરચના mach_header {
    uint32_t        magic;          /* mach magic number identifier */
    પૂર્ણાંક             cputype;        /* cpu specifier */
    પૂર્ણાંક             cpusubtype;     /* machine specifier */
    uint32_t        filetype;       /* type of file */
    uint32_t        ncmds;          /* number of load commands */
    uint32_t        sizeofcmds;     /* the size of all the load commands */
    uint32_t        flags;          /* flags */
};

સંરચના mach_header_64 {
    સંરચના mach_header  mh;
    uint32_t            reserved;       /* reserved, pad to 64bit */
};

/* Constant for the magic field of the mach_header (32-bit architectures) */
#define MH_MAGIC        0xfeedface      /* the mach magic number */
#define MH_CIGAM        0xcefaedfe      /* NXSwapInt(MH_MAGIC) */
#define MH_MAGIC_64     0xfeedfacf      /* the 64-bit mach magic number */
#define MH_CIGAM_64     0xcffaedfe      /* NXSwapInt(MH_MAGIC_64) */

સંરચના load_command {
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

પ્રકારવ્યાખ્યા પૂર્ણાંક vm_prot_t;

સંરચના segment_command_64 { /* for 64-bit architectures */
    uint32_t        cmd;            /* LC_SEGMENT_64 */
    uint32_t        cmdsize;        /* includes sizeof section_64 structs */
    અક્ષર            segname[16];    /* segment name */
    uint64_t        vmaddr;         /* memory address of this segment */
    uint64_t        vmsize;         /* memory size of this segment */
    uint64_t        fileoff;        /* file offset of this segment */
    uint64_t        filesize;       /* amount to map from the file */
    vm_prot_t       maxprot;        /* maximum VM protection */
    vm_prot_t       initprot;       /* initial VM protection */
    uint32_t        nsects;         /* number of sections in segment */
    uint32_t        flags;          /* flags */
};

સંરચના section_64 { /* for 64-bit architectures */
    અક્ષર            sectname[16];   /* name of this section */
    અક્ષર            segname[16];    /* segment this section goes in */
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

ગણના {
    DYLD_CHAINED_IMPORT          = 1,
};

સંરચના dyld_chained_fixups_header {
    uint32_t    fixups_version; ///< 0
    uint32_t    starts_offset;  ///< Offset of dyld_chained_starts_in_image.
    uint32_t    imports_offset; ///< Offset of imports table in chain_data.
    uint32_t    symbols_offset; ///< Offset of symbol strings in chain_data.
    uint32_t    imports_ગણતરી;  ///< Number of imported symbol names.
    uint32_t    imports_format; ///< DYLD_CHAINED_IMPORT*
    uint32_t    symbols_format; ///< 0 => uncompressed, 1 => zlib compressed
};

સંરચના dyld_chained_starts_in_image
{
    uint32_t    seg_ગણતરી;
    uint32_t    seg_info_offset[1];  // each entry is offset into this struct for that segment
    // followed by pool of dyld_chain_starts_in_segment data
};

ગણના {
    DYLD_CHAINED_PTR_64                     =  2,    // target is vmaddr
    DYLD_CHAINED_PTR_64_OFFSET              =  6,    // target is vm offset
};

ગણના {
    DYLD_CHAINED_PTR_START_NONE   = 0xFFFF, // used in page_start[] to denote a page with no fixups
};

#define SEG_PAGE_SIZE 16384

સંરચના dyld_chained_starts_in_segment
{
    uint32_t    size;               // size of this (amount kernel needs to copy)
    uint16_t    page_size;          // 0x1000 or 0x4000
    uint16_t    pointer_format;     // DYLD_CHAINED_PTR_*
    uint64_t    segment_offset;     // offset in memory to start of segment
    uint32_t    max_valid_pointer;  // for 32-bit OS, any value beyond this is not a pointer
    uint16_t    page_ગણતરી;         // how many pages are in array
    uint16_t    page_start[1];      // each entry is offset in each page of first element in chain
                                    // or DYLD_CHAINED_PTR_START_NONE if no fixups on page
};

ગણના BindSpecialDylib {
  BIND_SPECIAL_DYLIB_FLAT_LOOKUP = -2,
};

સંરચના dyld_chained_import
{
    uint32_t    lib_ordinal :  8,
                weak_import :  1,
                name_offset : 23;
};

સંરચના dyld_chained_ptr_64_rebase
{
    uint64_t    target    : 36,    // vmaddr, 64GB max image size
                high8     :  8,    // top 8 bits set to this after slide added
                reserved  :  7,    // all zeros
                next      : 12,    // 4-byte stride
                bind      :  1;    // == 0
};

સંરચના dyld_chained_ptr_64_bind
{
    uint64_t    ordinal   : 24,
                addend    :  8,   // 0 thru 255
                reserved  : 19,   // all zeros
                next      : 12,   // 4-byte stride
                bind      :  1;   // == 1
};

#define S_REGULAR                       0x0
#define S_ZEROFILL                      0x1
#define S_NON_LAZY_પ્રતીક_POINTERS      0x6
#define S_LAZY_પ્રતીક_POINTERS          0x7
#define S_પ્રતીક_STUBS                  0x8
#define S_MOD_INIT_FUNC_POINTERS        0x9
#define S_MOD_TERM_FUNC_POINTERS        0xa

#define S_ATTR_PURE_INSTRUCTIONS        0x80000000
#define S_ATTR_SOME_INSTRUCTIONS        0x00000400
#define S_ATTR_DEBUG             	0x02000000


પ્રકારવ્યાખ્યા uint32_t lc_str;

સંરચના dylib_command {
    uint32_t cmd;                   /* LC_ID_DYLIB, LC_LOAD_{,WEAK_}DYLIB,
                                       LC_REEXPORT_DYLIB */
    uint32_t cmdsize;               /* includes pathname string */
    lc_str   name;                  /* library's path name */
    uint32_t timestamp;             /* library's build time stamp */
    uint32_t current_version;       /* library's current version number */
    uint32_t compatibility_version; /* library's compatibility vers number*/
};

સંરચના rpath_command {
    uint32_t     cmd;           /* LC_RPATH */
    uint32_t     cmdsize;       /* includes string */
    lc_str       path;          /* path to add to run path */
};

સંરચના dylinker_command {
    uint32_t        cmd;            /* LC_ID_DYLINKER, LC_LOAD_DYLINKER or
                                       LC_DYLD_ENVIRONMENT */
    uint32_t        cmdsize;        /* includes pathname string */
    lc_str          name;           /* dynamic linker's path name */
};

સંરચના linkedit_data_command {
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

સંરચના build_version_command {
    uint32_t    cmd;            /* LC_BUILD_VERSION */
    uint32_t    cmdsize;        /* sizeof(struct build_version_command) plus */
                                /* ntools * sizeof(struct build_tool_version) */
    uint32_t    platform;       /* platform */
    uint32_t    minos;          /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    sdk;            /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    ntools;         /* number of tool entries following this */
};

સંરચના source_version_command {
    uint32_t  cmd;      /* LC_SOURCE_VERSION */
    uint32_t  cmdsize;  /* 16 */
    uint64_t  version;  /* A.B.C.D.E packed as a24.b10.c10.d10.e10 */
};

સંરચના symtab_command {
    uint32_t        cmd;            /* LC_SYMTAB */
    uint32_t        cmdsize;        /* sizeof(struct symtab_command) */
    uint32_t        symoff;         /* symbol table offset */
    uint32_t        nsyms;          /* number of symbol table entries */
    uint32_t        stroff;         /* string table offset */
    uint32_t        strsize;        /* string table size in bytes */
};

સંરચના dysymtab_command {
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
#define BIND_OPCODE_SET_પ્રતીક_TRAILING_FLAGS_IMM               0x40
#define BIND_OPCODE_SET_TYPE_IMM                                0x50
#define BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB                 0x70
#define BIND_OPCODE_DO_BIND                                     0x90

#define BIND_પ્રતીક_FLAGS_WEAK_IMPORT                           0x1

#define BIND_TYPE_POINTER                                       1
#define BIND_SPECIAL_DYLIB_FLAT_LOOKUP                          -2

#define REBASE_OPCODE_DONE                                      0x00
#define REBASE_OPCODE_SET_TYPE_IMM                              0x10
#define REBASE_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB               0x20
#define REBASE_OPCODE_DO_REBASE_IMM_TIMES                       0x50

#define REBASE_TYPE_POINTER                                     1

#define EXPORT_પ્રતીક_FLAGS_KIND_REGULAR                        0x00
#define EXPORT_પ્રતીક_FLAGS_KIND_ABSOLUTE                       0x02
#define EXPORT_પ્રતીક_FLAGS_WEAK_DEFINITION                     0x04

સંરચના dyld_info_command {
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

#define INDIRECT_પ્રતીક_LOCAL   0x80000000

સંરચના entry_point_command {
    uint32_t  cmd;      /* LC_MAIN only used in MH_EXECUTE filetypes */
    uint32_t  cmdsize;  /* 24 */
    uint64_t  entryoff; /* file (__TEXT) offset of main() */
    uint64_t  stacksize;/* if not zero, initial stack size */
};

ગણના skind {
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
    sk_debug_લીટી,
    sk_debug_aranges,
    sk_debug_str,
    sk_debug_લીટી_str,
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

સંરચના nlist_64 {
    uint32_t  n_strx;      /* index into the string table */
    uint8_t n_type;        /* type flag, see below */
    uint8_t n_sect;        /* section number or NO_SECT */
    uint16_t n_desc;       /* see <mach-o/stab.h> */
    uint64_t n_કિંમત;      /* value of this symbol (or stab offset) */
};

#define N_UNDF  0x0
#define N_ABS   0x2
#define N_EXT   0x1
#define N_SECT  0xe

#define N_WEAK_REF      0x0040
#define N_WEAK_DEF      0x0080

સંરચના macho {
    સંરચના mach_header_64 mh;
    પૂર્ણાંક *seg2lc, nseg;
    સંરચના load_command **lc;
    સંરચના entry_point_command *ep;
    પૂર્ણાંક nlc;
    સંરચના {
        Section *s;
        પૂર્ણાંક machosect;
    } sk_to_sect[sk_last];
    પૂર્ણાંક *elfsectomacho;
    પૂર્ણાંક *e2msym;
    Section *symtab, *strtab, *indirsyms, *stubs, *exports;
    uint32_t ilocal, iextdef, iundef;
    પૂર્ણાંક stubsym, n_got, nr_plt;
    પૂર્ણાંક segment[sk_last];
#ifdef CONFIG_NEW_MACHO
    Section *chained_fixups;
    પૂર્ણાંક n_bind;
    પૂર્ણાંક n_bind_rebase;
    સંરચના bind_rebase {
	પૂર્ણાંક section;
	પૂર્ણાંક bind;
	ElfW_Rel rel;
    } *bind_rebase;
#નહીંતર
    Section *rebase, *binding, *weak_binding, *lazy_binding;
    Section *stub_helper, *la_પ્રતીક_ptr;
    સંરચના dyld_info_command *dyldinfo;
    પૂર્ણાંક helpsym, lasym, dyld_private, dyld_stub_binder;
    પૂર્ણાંક n_lazy_bind;    
    સંરચના s_lazy_bind {
        પૂર્ણાંક section;
        પૂર્ણાંક bind_offset;
        પૂર્ણાંક la_પ્રતીક_offset;
        ElfW_Rel rel;
    } *s_lazy_bind;
    પૂર્ણાંક n_rebase;    
    સંરચના s_rebase {
        પૂર્ણાંક section;
        ElfW_Rel rel;
    } *s_rebase;
    પૂર્ણાંક n_bind; 
    સંરચના bind {
        પૂર્ણાંક section;
        ElfW_Rel rel;
    } *bind;
#endif
};

#define SHT_LINKEDIT (SHT_LOOS + 42)
#define SHN_FROMDLL  (SHN_LOOS + 2)  /* Symbol is undefined, comes from a DLL */

સ્થિર શૂન્ય * add_lc(સંરચના macho *mo, uint32_t cmd, uint32_t cmdsize)
{
    સંરચના load_command *lc = tcc_mallocz(cmdsize);
    lc->cmd = cmd;
    lc->cmdsize = cmdsize;
    mo->lc = tcc_realloc(mo->lc, કદ(mo->lc[0]) * (mo->nlc + 1));
    mo->lc[mo->nlc++] = lc;
    પાછા lc;
}

સ્થિર સંરચના segment_command_64 * add_segment(સંરચના macho *mo, અચલ અક્ષર *name)
{
    સંરચના segment_command_64 *sc = add_lc(mo, LC_SEGMENT_64, કદ(*sc));
    strncpy(sc->segname, name, 16);
    mo->seg2lc = tcc_realloc(mo->seg2lc, કદ(*mo->seg2lc) * (mo->nseg + 1));
    mo->seg2lc[mo->nseg++] = mo->nlc - 1;
    પાછા sc;
}

સ્થિર સંરચના segment_command_64 * get_segment(સંરચના macho *mo, પૂર્ણાંક i)
{
    પાછા (સંરચના segment_command_64 *) (mo->lc[mo->seg2lc[i]]);
}

સ્થિર પૂર્ણાંક add_section(સંરચના macho *mo, સંરચના segment_command_64 **_seg, અચલ અક્ષર *name)
{
    સંરચના segment_command_64 *seg = *_seg;
    પૂર્ણાંક ret = seg->nsects;
    સંરચના section_64 *sec;
    seg->nsects++;
    seg->cmdsize += કદ(*sec);
    seg = tcc_realloc(seg, કદ(*seg) + seg->nsects * કદ(*sec));
    sec = (સંરચના section_64*)((અક્ષર*)seg + કદ(*seg)) + ret;
    memset(sec, 0, કદ(*sec));
    strncpy(sec->sectname, name, 16);
    strncpy(sec->segname, seg->segname, 16);
    *_seg = seg;
    પાછા ret;
}

સ્થિર સંરચના section_64 *get_section(સંરચના segment_command_64 *seg, પૂર્ણાંક i)
{
    પાછા (સંરચના section_64*)((અક્ષર*)seg + કદ(*seg)) + i;
}

સ્થિર શૂન્ય * add_dylib(સંરચના macho *mo, અક્ષર *name)
{
    સંરચના dylib_command *lc;
    પૂર્ણાંક sz = (કદ(*lc) + strlen(name) + 1 + 7) & -8;
    lc = add_lc(mo, LC_LOAD_DYLIB, sz);
    lc->name = કદ(*lc);
    strcpy((અક્ષર*)lc + lc->name, name);
    lc->timestamp = 2;
    lc->current_version = 1 << 16;
    lc->compatibility_version = 1 << 16;
    પાછા lc;
}

સ્થિર પૂર્ણાંક uleb128_size (unsigned long long કિંમત)
{
    પૂર્ણાંક size =  0;

    કરો {
        કિંમત >>= 7;
        size++;
    } જ્યારે (કિંમત != 0);
    પાછા size;
}

સ્થિર શૂન્ય write_uleb128(Section *section, uint64_t કિંમત)
{
    કરો {
        unsigned અક્ષર byte = કિંમત & 0x7f;
	uint8_t *ptr = section_ptr_add(section, 1);

        કિંમત >>= 7;
        *ptr = byte | (કિંમત ? 0x80 : 0);
    } જ્યારે (કિંમત != 0);
}

સ્થિર શૂન્ય tcc_macho_add_destructor(TCCState *s1)
{
    પૂર્ણાંક init_sym, mh_execute_header, at_exit_sym;
    Section *s;
    ElfW_Rel *rel;
    uint8_t *ptr;

    mh_execute_header = put_elf_sym(s1->symtab, -4096, 0,
				    ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				    text_section->sh_અંક, "__mh_execute_header");
    s = find_section(s1, ".fini_array");
    જો (s->data_offset == 0)
        પાછા; 
    init_sym = put_elf_sym(s1->symtab, text_section->data_offset, 0,
                           ELFW(ST_INFO)(STB_LOCAL, STT_FUNC), 0,
                           text_section->sh_અંક, "___GLOBAL_init_65535");
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
        પૂર્ણાંક sym_index = ELFW(R_SYM)(rel->r_info);

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
#અથવાજો defined TCC_TARGET_ARM64
    ptr = section_ptr_add(text_section, 8);
    write32le(ptr, 0xa9bf7bfd);     // stp     x29, x30, [sp, #-16]!
    write32le(ptr + 4, 0x910003fd); // mov     x29, sp
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        પૂર્ણાંક sym_index = ELFW(R_SYM)(rel->r_info);

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
સ્થિર શૂન્ય bind_rebase_add(સંરચના macho *mo, પૂર્ણાંક bind, પૂર્ણાંક sh_info,
			    ElfW_Rel *rel, સંરચના sym_attr *attr)
{
    mo->bind_rebase = tcc_realloc(mo->bind_rebase, (mo->n_bind_rebase + 1) *
		                  કદ(સંરચના bind_rebase));
    mo->bind_rebase[mo->n_bind_rebase].section = sh_info;
    mo->bind_rebase[mo->n_bind_rebase].bind = bind;
    mo->bind_rebase[mo->n_bind_rebase].rel = *rel;
    જો (attr)
        mo->bind_rebase[mo->n_bind_rebase].rel.r_offset = attr->got_offset;
    mo->n_bind_rebase++;
    mo->n_bind += bind;
}

સ્થિર શૂન્ય check_relocs(TCCState *s1, સંરચના macho *mo)
{
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    પૂર્ણાંક i, j, type, gotplt_entry, sym_index, for_code;
    uint32_t *pi, *goti;
    સંરચના sym_attr *attr;

    goti = ખાલી;
    mo->nr_plt = mo->n_got = 0;
    માટે (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        જો (s->sh_type != SHT_RELX ||
	    !strncmp(s1->sections[s->sh_info]->name, ".debug_", 7))
            ચાલુ;
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
            જો (sym->st_shndx == SHN_UNDEF
                || gotplt_entry == ALWAYS_GOTPLT_ENTRY) {
                attr = get_sym_attr(s1, sym_index, 1);
                જો (!attr->dyn_index) {
                    attr->got_offset = s1->got->data_offset;
                    attr->plt_offset = -1;
                    attr->dyn_index = 1; /* used as flag */
                    section_ptr_add(s1->got, PTR_SIZE);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_offset,
                                  R_JMP_SLOT, sym_index);
	 	    goti = tcc_realloc(goti, (mo->n_got + 1) * કદ(*goti));
                    જો (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        જો (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (અક્ષર *) symtab_section->link->data + sym->st_name);
			goti[mo->n_got++] = INDIRECT_પ્રતીક_LOCAL;
                    } નહીંતર {
                        goti[mo->n_got++] = mo->e2msym[sym_index];
                        જો (sym->st_shndx == SHN_UNDEF
#ifdef TCC_TARGET_X86_64
                            && type == R_X86_64_GOTPCREL
#અથવાજો defined TCC_TARGET_ARM64
                            && type == R_AARCH64_ADR_GOT_PAGE
#endif
                            ) {
			    attr->plt_offset = -mo->n_bind_rebase - 2;
			    bind_rebase_add(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
			    s1->got->reloc->data_offset -= કદ (ElfW_Rel);
			}
		        જો (for_code && sym->st_shndx == SHN_UNDEF)
			    s1->got->reloc->data_offset -= કદ (ElfW_Rel);
		    }
                }
                જો (for_code && sym->st_shndx == SHN_UNDEF) {
		    જો ((પૂર્ણાંક)attr->plt_offset < -1) {
			/* remove above bind and replace with plt */
			mo->bind_rebase[-attr->plt_offset - 2].bind = 2;
			attr->plt_offset = -1;
		    }
                    જો (attr->plt_offset == -1) {
                        uint8_t *jmp;

                        attr->plt_offset = mo->stubs->data_offset;
#ifdef TCC_TARGET_X86_64
                        જો (type != R_X86_64_PLT32)
                             ચાલુ;
                        jmp = section_ptr_add(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *ofs(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_offset + 2,
                                      R_X86_64_GOTPCREL, sym_index);
#અથવાજો defined TCC_TARGET_ARM64
                        જો (type != R_AARCH64_CALL26)
                             ચાલુ;
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
                        pi = section_ptr_add(mo->indirsyms, કદ(*pi));
                        *pi = mo->e2msym[sym_index];
                        mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_offset;
                }
            }
	    જો (type == R_DATA_PTR || type == R_JMP_SLOT)
		bind_rebase_add(mo, sym->st_shndx == SHN_UNDEF ? 1 : 0,
				s->sh_info, &save_rel, ખાલી);
        }
    }
    /* remove deleted binds */
    માટે (i = 0, j = 0; i < mo->n_bind_rebase; i++)
	જો (mo->bind_rebase[i].bind == 2)
	    mo->n_bind--;
	નહીંતર
	    mo->bind_rebase[j++] = mo->bind_rebase[i];
    mo->n_bind_rebase = j;
    pi = section_ptr_add(mo->indirsyms, mo->n_got * કદ(*pi));
    memcpy(pi, goti, mo->n_got * કદ(*pi));
    tcc_free(goti);
}

#નહીંતર

સ્થિર શૂન્ય check_relocs(TCCState *s1, સંરચના macho *mo)
{
    uint8_t *jmp;
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    પૂર્ણાંક i, type, gotplt_entry, sym_index, for_code;
    પૂર્ણાંક bind_offset, la_પ્રતીક_offset;
    uint32_t *pi, *goti;
    સંરચના sym_attr *attr;

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
#અથવાજો defined TCC_TARGET_ARM64
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
    
    goti = ખાલી;
    mo->nr_plt = mo->n_got = 0;
    માટે (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        જો (s->sh_type != SHT_RELX ||
	    !strncmp(s1->sections[s->sh_info]->name, ".debug_", 7))
            ચાલુ;
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
            જો (sym->st_shndx == SHN_UNDEF
                || gotplt_entry == ALWAYS_GOTPLT_ENTRY) {
                attr = get_sym_attr(s1, sym_index, 1);
                જો (!attr->dyn_index) {
                    attr->got_offset = s1->got->data_offset;
                    attr->plt_offset = -1;
                    attr->dyn_index = 1; /* used as flag */
		    section_ptr_add(s1->got, PTR_SIZE);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_offset,
                                  R_JMP_SLOT, sym_index);
		    goti = tcc_realloc(goti, (mo->n_got + 1) * કદ(*goti));
                    જો (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        જો (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (અક્ષર *) symtab_section->link->data + sym->st_name);
			goti[mo->n_got++] = INDIRECT_પ્રતીક_LOCAL;
                    } નહીંતર {
			goti[mo->n_got++] = mo->e2msym[sym_index];
			જો (sym->st_shndx == SHN_UNDEF
#ifdef TCC_TARGET_X86_64
			    && type == R_X86_64_GOTPCREL
#અથવાજો defined TCC_TARGET_ARM64
			    && type == R_AARCH64_ADR_GOT_PAGE
#endif
			    ) {
			    mo->bind =
			        tcc_realloc(mo->bind,
					    (mo->n_bind + 1) *
					    કદ(સંરચના bind));
			    mo->bind[mo->n_bind].section = s1->got->reloc->sh_info;
			    mo->bind[mo->n_bind].rel = save_rel;
                            mo->bind[mo->n_bind].rel.r_offset = attr->got_offset;
			    mo->n_bind++;
			    s1->got->reloc->data_offset -= કદ (ElfW_Rel);
			}
		    }
                }
                જો (for_code && sym->st_shndx == SHN_UNDEF) {
                    જો (attr->plt_offset == -1) {
                        attr->plt_offset = mo->stubs->data_offset;
#ifdef TCC_TARGET_X86_64
			જો (type != R_X86_64_PLT32)
			     ચાલુ;
			/* __stubs */
                        jmp = section_ptr_add(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *__la_symbol_ptr(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->data_offset - 4,
                                       R_X86_64_PC32, mo->lasym,
				       mo->la_પ્રતીક_ptr->data_offset - 4);

			/* __stub_helper */
			bind_offset = mo->stub_helper->data_offset + 1;
                        jmp = section_ptr_add(mo->stub_helper, 10);
                        jmp[0] = 0x68;  /* pushq $bind_offset */
                        jmp[5] = 0xe9;  /* jmpq __stub_helper */
                        write32le(jmp + 6, -mo->stub_helper->data_offset);

			/* __la_symbol_ptr */
			la_પ્રતીક_offset = mo->la_પ્રતીક_ptr->data_offset;
                        put_elf_reloca(s1->symtab, mo->la_પ્રતીક_ptr,
				       mo->la_પ્રતીક_ptr->data_offset,
				       R_DATA_PTR, mo->helpsym,
				       mo->stub_helper->data_offset - 10);
			section_ptr_add(mo->la_પ્રતીક_ptr, PTR_SIZE);
#અથવાજો defined TCC_TARGET_ARM64
			જો (type != R_AARCH64_CALL26)
			     ચાલુ;
			/* __stubs */
                        jmp = section_ptr_add(mo->stubs, 12);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->data_offset - 12,
                                       R_AARCH64_ADR_PREL_PG_HI21, mo->lasym,
				       mo->la_પ્રતીક_ptr->data_offset);
                        write32le(jmp, // adrp x16, __la_symbol_ptr@page
                                  0x90000010);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->data_offset - 8,
                                       R_AARCH64_LDST64_ABS_LO12_NC, mo->lasym,
				       mo->la_પ્રતીક_ptr->data_offset);
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
			la_પ્રતીક_offset = mo->la_પ્રતીક_ptr->data_offset;
                        put_elf_reloca(s1->symtab, mo->la_પ્રતીક_ptr,
				       mo->la_પ્રતીક_ptr->data_offset,
				       R_DATA_PTR, mo->helpsym,
				       mo->stub_helper->data_offset - 12);
			section_ptr_add(mo->la_પ્રતીક_ptr, PTR_SIZE);
#endif
                        mo->s_lazy_bind =
                            tcc_realloc(mo->s_lazy_bind, (mo->n_lazy_bind + 1) *
                                        કદ(સંરચના s_lazy_bind));
                        mo->s_lazy_bind[mo->n_lazy_bind].section =
                            mo->stub_helper->reloc->sh_info;
                        mo->s_lazy_bind[mo->n_lazy_bind].bind_offset =
			    bind_offset;
                        mo->s_lazy_bind[mo->n_lazy_bind].la_પ્રતીક_offset =
			    la_પ્રતીક_offset;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel = save_rel;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel.r_offset =
                            attr->plt_offset;
                        mo->n_lazy_bind++;
			pi = section_ptr_add(mo->indirsyms, કદ(*pi));
			*pi = mo->e2msym[sym_index];
			mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_offset;
                }
            }
            જો (type == R_DATA_PTR || type == R_JMP_SLOT) {
		જો (sym->st_shndx == SHN_UNDEF) {
		    mo->bind = tcc_realloc(mo->bind,
					   (mo->n_bind + 1) *
					   કદ(સંરચના bind));
		    mo->bind[mo->n_bind].section = s->sh_info;
		    mo->bind[mo->n_bind].rel = save_rel;
		    mo->n_bind++;
		}
		નહીંતર {
                    mo->s_rebase =
                        tcc_realloc(mo->s_rebase, (mo->n_rebase + 1) *
				    કદ(સંરચના s_rebase));
                    mo->s_rebase[mo->n_rebase].section = s->sh_info;
                    mo->s_rebase[mo->n_rebase].rel = save_rel;
                    mo->n_rebase++;
		}
	    }
        }
    }
    pi = section_ptr_add(mo->indirsyms, mo->n_got * કદ(*pi));
    memcpy(pi, goti, mo->n_got * કદ(*pi));
    pi = section_ptr_add(mo->indirsyms, mo->nr_plt * કદ(*pi));
    memcpy(pi, mo->indirsyms->data, mo->nr_plt * કદ(*pi));
    tcc_free(goti);
}
#endif

સ્થિર પૂર્ણાંક check_symbols(TCCState *s1, સંરચના macho *mo)
{
    પૂર્ણાંક sym_index, sym_end;
    પૂર્ણાંક ret = 0;

    mo->ilocal = mo->iextdef = mo->iundef = -1;
    sym_end = symtab_section->data_offset / કદ(ElfW(Sym));
    માટે (sym_index = 1; sym_index < sym_end; ++sym_index) {
        પૂર્ણાંક elf_index = ((સંરચના nlist_64 *)mo->symtab->data + sym_index - 1)->n_કિંમત;
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + elf_index;
        અચલ અક્ષર *name = (અક્ષર*)symtab_section->link->data + sym->st_name;
        unsigned type = ELFW(ST_TYPE)(sym->st_info);
        unsigned bind = ELFW(ST_BIND)(sym->st_info);
        unsigned vis  = ELFW(ST_VISIBILITY)(sym->st_other);

        dprintf("%4d (%4d): %09lx %4d %4d %4d %3d %s\n",
                sym_index, elf_index, (long)sym->st_કિંમત,
                type, bind, vis, sym->st_shndx, name);
        જો (bind == STB_LOCAL) {
            જો (mo->ilocal == -1)
              mo->ilocal = sym_index - 1;
            જો (mo->iextdef != -1 || mo->iundef != -1)
              tcc_error("local syms after global ones");
        } નહીંતર જો (sym->st_shndx != SHN_UNDEF) {
            જો (mo->iextdef == -1)
              mo->iextdef = sym_index - 1;
            જો (mo->iundef != -1)
              tcc_error("external defined symbol after undefined");
        } નહીંતર જો (sym->st_shndx == SHN_UNDEF) {
            જો (mo->iundef == -1)
              mo->iundef = sym_index - 1;
            જો (ELFW(ST_BIND)(sym->st_info) == STB_WEAK
		|| s1->output_type != TCC_OUTPUT_EXE
                || find_elf_sym(s1->dynsymtab_section, name)) {
                /* Mark the symbol as coming from a dylib so that
                   relocate_syms doesn't complain.  Normally bind_exe_dynsyms
                   would do this check, and place the symbol into dynsym
                   which is checked by relocate_syms.  But Mach-O doesn't use
                   bind_exe_dynsyms.  */
                sym->st_shndx = SHN_FROMDLL;
                ચાલુ;
            }
            tcc_error_noabort("unresolved reference to '%s'", name);
            ret = -1;
        }
    }
    પાછા ret;
}

સ્થિર શૂન્ય convert_પ્રતીક(TCCState *s1, સંરચના macho *mo, સંરચના nlist_64 *pn)
{
    સંરચના nlist_64 n = *pn;
    ElfSym *sym = (ElfW(Sym) *)symtab_section->data + pn->n_કિંમત;
    અચલ અક્ષર *name = (અક્ષર*)symtab_section->link->data + sym->st_name;
    પસંદગી(ELFW(ST_TYPE)(sym->st_info)) {
    સ્થિતિ STT_NOTYPE:
    સ્થિતિ STT_OBJECT:
    સ્થિતિ STT_FUNC:
    સ્થિતિ STT_TLS:
    સ્થિતિ STT_SECTION:
        n.n_type = N_SECT;
        તોડો;
    સ્થિતિ STT_FILE:
        n.n_type = N_ABS;
        તોડો;
    મૂળભૂત:
        tcc_error("unhandled ELF symbol type %d %s",
                  ELFW(ST_TYPE)(sym->st_info), name);
    }
    જો (sym->st_shndx == SHN_UNDEF)
      tcc_error("should have been rewritten to SHN_FROMDLL: %s", name);
    નહીંતર જો (sym->st_shndx == SHN_FROMDLL)
      n.n_type = N_UNDF, n.n_sect = 0;
    નહીંતર જો (sym->st_shndx == SHN_ABS)
      n.n_type = N_ABS, n.n_sect = 0;
    નહીંતર જો (sym->st_shndx >= SHN_LORESERVE)
      tcc_error("unhandled ELF symbol section %d %s", sym->st_shndx, name);
    નહીંતર જો (!mo->elfsectomacho[sym->st_shndx]) {
      જો (strncmp(s1->sections[sym->st_shndx]->name, ".debug_", 7))
        tcc_error("ELF section %d(%s) not mapped into Mach-O for symbol %s",
                  sym->st_shndx, s1->sections[sym->st_shndx]->name, name);
    }
    નહીંતર
      n.n_sect = mo->elfsectomacho[sym->st_shndx];
    જો (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL)
      n.n_type |=  N_EXT;
    નહીંતર જો (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
      n.n_desc |= N_WEAK_REF | (n.n_type != N_UNDF ? N_WEAK_DEF : 0);
    n.n_strx = pn->n_strx;
    n.n_કિંમત = sym->st_કિંમત;
    *pn = n;
}

સ્થિર શૂન્ય convert_symbols(TCCState *s1, સંરચના macho *mo)
{
    સંરચના nlist_64 *pn;
    for_each_elem(mo->symtab, 0, pn, સંરચના nlist_64)
        convert_પ્રતીક(s1, mo, pn);
}

સ્થિર પૂર્ણાંક machosymcmp(અચલ શૂન્ય *_a, અચલ શૂન્ય *_b, શૂન્ય *arg)
{
    TCCState *s1 = arg;
    પૂર્ણાંક ea = ((સંરચના nlist_64 *)_a)->n_કિંમત;
    પૂર્ણાંક eb = ((સંરચના nlist_64 *)_b)->n_કિંમત;
    ElfSym *sa = (ElfSym *)symtab_section->data + ea;
    ElfSym *sb = (ElfSym *)symtab_section->data + eb;
    પૂર્ણાંક r;
    /* locals, then defined externals, then undefined externals, the
       last two sections also by name, otherwise stable sort */
    r = (ELFW(ST_BIND)(sb->st_info) == STB_LOCAL)
        - (ELFW(ST_BIND)(sa->st_info) == STB_LOCAL);
    જો (r)
      પાછા r;
    r = (sa->st_shndx == SHN_UNDEF) - (sb->st_shndx == SHN_UNDEF);
    જો (r)
      પાછા r;
    જો (ELFW(ST_BIND)(sa->st_info) != STB_LOCAL) {
        અચલ અક્ષર * na = (અક્ષર*)symtab_section->link->data + sa->st_name;
        અચલ અક્ષર * nb = (અક્ષર*)symtab_section->link->data + sb->st_name;
        r = strcmp(na, nb);
        જો (r)
          પાછા r;
    }
    પાછા ea - eb;
}

/* cannot use qsort because code has to be reentrant */
સ્થિર શૂન્ય tcc_qsort (શૂન્ય  *base, size_t nel, size_t width,
                       પૂર્ણાંક (*comp)(અચલ શૂન્ય *, અચલ શૂન્ય *, શૂન્ય *), શૂન્ય *arg)
{
    size_t wnel, gap, wgap, i, j, k;
    અક્ષર *a, *b, tmp;

    wnel = width * nel;
    માટે (gap = 0; ++gap < nel;)
        gap *= 3;
    જ્યારે ( gap /= 3 ) {
        wgap = width * gap;
        માટે (i = wgap; i < wnel; i += width) {
            માટે (j = i - wgap; ;j -= wgap) {
                a = j + (અક્ષર *)base;
                b = a + wgap;
                જો ( (*comp)(a, b, arg) <= 0 )
                    તોડો;
                k = width;
                કરો {
                    tmp = *a;
                    *a++ = *b;
                    *b++ = tmp;
                } જ્યારે ( --k );
                જો (j < wgap)
                    તોડો;
            }
        }
    }
}

સ્થિર શૂન્ય create_symtab(TCCState *s1, સંરચના macho *mo)
{
    પૂર્ણાંક sym_index, sym_end;
    સંરચના nlist_64 *pn;

    /* Stub creation belongs to check_relocs, but we need to create
       the symbol now, so its included in the sorting.  */
    mo->stubs = new_section(s1, "__stubs", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->stubsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stubs->sh_અંક, ".__stubs");
#ifdef CONFIG_NEW_MACHO
    mo->chained_fixups = new_section(s1, "CHAINED_FIXUPS",
				     SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#નહીંતર
    mo->stub_helper = new_section(s1, "__stub_helper", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    mo->la_પ્રતીક_ptr = new_section(s1, "__la_symbol_ptr", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->helpsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stub_helper->sh_અંક, ".__stub_helper");
    mo->lasym = put_elf_sym(s1->symtab, 0, 0,
                            ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                            mo->la_પ્રતીક_ptr->sh_અંક, ".__la_symbol_ptr");
    section_ptr_add(data_section, -data_section->data_offset & (PTR_SIZE - 1));
    mo->dyld_private = put_elf_sym(s1->symtab, data_section->data_offset, PTR_SIZE,
                                   ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT), 0,
                                   data_section->sh_અંક, ".__dyld_private");
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
    sym_end = symtab_section->data_offset / કદ(ElfW(Sym));
    pn = section_ptr_add(mo->symtab, કદ(*pn) * (sym_end - 1));
    માટે (sym_index = 1; sym_index < sym_end; ++sym_index) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
        અચલ અક્ષર *name = (અક્ષર*)symtab_section->link->data + sym->st_name;
        pn[sym_index - 1].n_strx = put_elf_str(mo->strtab, name);
        pn[sym_index - 1].n_કિંમત = sym_index;
    }
    section_ptr_add(mo->strtab, -mo->strtab->data_offset & (PTR_SIZE - 1));
    tcc_qsort(pn, sym_end - 1, કદ(*pn), machosymcmp, s1);
    mo->e2msym = tcc_malloc(sym_end * કદ(*mo->e2msym));
    mo->e2msym[0] = -1;
    માટે (sym_index = 1; sym_index < sym_end; ++sym_index) {
        mo->e2msym[pn[sym_index - 1].n_કિંમત] = sym_index - 1;
    }
}

અચલ સંરચના {
    પૂર્ણાંક seg_initial;
    uint32_t flags;
    અચલ અક્ષર *name;
} skinfo[sk_last] = {
    /*[sk_unknown] =*/        { 0 },
    /*[sk_discard] =*/        { 0 },
    /*[sk_text] =*/           { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS, "__text" },
    /*[sk_stubs] =*/          { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS | S_પ્રતીક_STUBS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stubs" },
    /*[sk_stub_helper] =*/    { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stub_helper" },
    /*[sk_ro_data] =*/        { 2, S_REGULAR, "__rodata" },
    /*[sk_uw_info] =*/        { 0 },
    /*[sk_nl_ptr] =*/         { 2, S_NON_LAZY_પ્રતીક_POINTERS, "__got" },
    /*[sk_debug_info] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_info" },
    /*[sk_debug_abbrev] =*/   { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_abbrev" },
    /*[sk_debug_line] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line" },
    /*[sk_debug_aranges] =*/  { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_aranges" },
    /*[sk_debug_str] =*/      { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_str" },
    /*[sk_debug_line_str] =*/ { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line_str" },
    /*[sk_stab] =*/           { 4, S_REGULAR, "__stab" },
    /*[sk_stab_str] =*/       { 4, S_REGULAR, "__stab_str" },
    /*[sk_la_ptr] =*/         { 4, S_LAZY_પ્રતીક_POINTERS, "__la_symbol_ptr" },
    /*[sk_init] =*/           { 4, S_MOD_INIT_FUNC_POINTERS, "__mod_init_func" },
    /*[sk_fini] =*/           { 4, S_MOD_TERM_FUNC_POINTERS, "__mod_term_func" },
    /*[sk_rw_data] =*/        { 4, S_REGULAR, "__data" },
    /*[sk_bss] =*/            { 4, S_ZEROFILL, "__bss" },
    /*[sk_linkedit] =*/       { 5, S_REGULAR, ખાલી },
};

#define	START	((uint64_t)1 << 32)

અચલ સંરચના {
    પૂર્ણાંક used;
    અચલ અક્ષર *name;
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

#define	N_SEGMENT	(કદ(all_segment)/કદ(all_segment[0]))

#ifdef CONFIG_NEW_MACHO
સ્થિર શૂન્ય calc_fixup_size(TCCState *s1, સંરચના macho *mo)
{
    પૂર્ણાંક i, size;

    size = (કદ(સંરચના dyld_chained_fixups_header) + 7) & -8;
    size += (કદ(સંરચના dyld_chained_starts_in_image) + (mo->nseg - 1) * કદ(uint32_t) + 7) & -8;
    માટે (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	પૂર્ણાંક page_ગણતરી = (get_segment(mo, i)->vmsize + SEG_PAGE_SIZE - 1) / SEG_PAGE_SIZE;
	size += (કદ(સંરચના dyld_chained_starts_in_segment) + (page_ગણતરી - 1) * કદ(uint16_t) + 7) & -8;
    }
    size += mo->n_bind * કદ (સંરચના dyld_chained_import) + 1;
    માટે (i = 0; i < mo->n_bind_rebase; i++) {
	જો (mo->bind_rebase[i].bind) {
	    પૂર્ણાંક sym_index = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	    અચલ અક્ષર *name = (અક્ષર *) symtab_section->link->data + sym->st_name;
	    size += strlen(name) + 1;
	}
    }
    size = (size + 7) & -8;
    section_ptr_add(mo->chained_fixups, size);
}

#નહીંતર

સ્થિર શૂન્ય set_segment_and_offset(TCCState *s1, સંરચના macho *mo, addr_t addr,
				   uint8_t *ptr, પૂર્ણાંક opcode,
				   Section *sec, addr_t offset)
{
    પૂર્ણાંક i;
    સંરચના segment_command_64 *seg = ખાલી;

    માટે (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	seg = get_segment(mo, i);
	જો (addr >= seg->vmaddr && addr < (seg->vmaddr + seg->vmsize))
	    તોડો;
    }
    *ptr = opcode | i;
    write_uleb128(sec, offset - seg->vmaddr);
}

સ્થિર શૂન્ય bind_rebase(TCCState *s1, સંરચના macho *mo)
{
    પૂર્ણાંક i;
    uint8_t *ptr;
    ElfW(Sym) *sym;
    અચલ અક્ષર *name;

    માટે (i = 0; i < mo->n_lazy_bind; i++) {
	પૂર્ણાંક sym_index = ELFW(R_SYM)(mo->s_lazy_bind[i].rel.r_info);

	sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	name = (અક્ષર *) symtab_section->link->data + sym->st_name;
	write32le(mo->stub_helper->data +
		  mo->s_lazy_bind[i].bind_offset,
		  mo->lazy_binding->data_offset);
	ptr = section_ptr_add(mo->lazy_binding, 1);
	set_segment_and_offset(s1, mo, mo->la_પ્રતીક_ptr->sh_addr, ptr,
			       BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB,
			       mo->lazy_binding,
			       mo->s_lazy_bind[i].la_પ્રતીક_offset +
			       mo->la_પ્રતીક_ptr->sh_addr);
	ptr = section_ptr_add(mo->lazy_binding, 5 + strlen(name));
	*ptr++ = BIND_OPCODE_SET_DYLIB_SPECIAL_IMM |
		 (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
	*ptr++ = BIND_OPCODE_SET_પ્રતીક_TRAILING_FLAGS_IMM | 0;
	strcpy((અક્ષર *)ptr, name);
	ptr += strlen(name) + 1;
	*ptr++ = BIND_OPCODE_DO_BIND;
	*ptr = BIND_OPCODE_DONE;
    }
    માટે (i = 0; i < mo->n_rebase; i++) {
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
    માટે (i = 0; i < mo->n_bind; i++) {
	પૂર્ણાંક sym_index = ELFW(R_SYM)(mo->bind[i].rel.r_info);
	Section *s = s1->sections[mo->bind[i].section];
	Section *binding;

	sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	name = (અક્ષર *) symtab_section->link->data + sym->st_name;
	binding = ELFW(ST_BIND)(sym->st_info) == STB_WEAK
	    ? mo->weak_binding : mo->binding;
        ptr = section_ptr_add(binding, 4 + (binding == mo->binding) +
			     	       strlen(name));
	જો (binding == mo->binding)
            *ptr++ = BIND_OPCODE_SET_DYLIB_SPECIAL_IMM |
	             (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
        *ptr++ = BIND_OPCODE_SET_પ્રતીક_TRAILING_FLAGS_IMM |
		 (binding == mo->weak_binding
		  ? BIND_પ્રતીક_FLAGS_WEAK_IMPORT : 0);
        strcpy((અક્ષર *)ptr, name);
        ptr += strlen(name) + 1;
        *ptr++ = BIND_OPCODE_SET_TYPE_IMM | BIND_TYPE_POINTER;
	set_segment_and_offset(s1, mo, s->sh_addr, ptr,
			       BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB,
			       binding,
			       mo->bind[i].rel.r_offset + s->sh_addr);
        ptr = section_ptr_add(binding, 1);
        *ptr++ = BIND_OPCODE_DO_BIND;
    }
    જો (mo->rebase->data_offset) {
        ptr = section_ptr_add(mo->rebase, 1);
        *ptr = REBASE_OPCODE_DONE;
    }
    જો (mo->binding->data_offset) {
        ptr = section_ptr_add(mo->binding, 1);
        *ptr = BIND_OPCODE_DONE;
    }
    જો (mo->weak_binding->data_offset) {
        ptr = section_ptr_add(mo->weak_binding, 1);
        *ptr = BIND_OPCODE_DONE;
    }
    tcc_free(mo->s_lazy_bind);
    tcc_free(mo->s_rebase);
    tcc_free(mo->bind);
}
#endif

સંરચના trie_info {
    અચલ અક્ષર *name;
    પૂર્ણાંક flag;
    addr_t addr;
    પૂર્ણાંક str_size;
    પૂર્ણાંક term_size;
};

સંરચના trie_ગાંઠ {
    પૂર્ણાંક start;
    પૂર્ણાંક end;
    પૂર્ણાંક index_start;
    પૂર્ણાંક index_end;
    પૂર્ણાંક n_child;
    સંરચના trie_ગાંઠ *child;
};

સંરચના trie_seq {
    પૂર્ણાંક n_child;
    સંરચના trie_ગાંઠ *ગાંઠ;
    પૂર્ણાંક offset;
    પૂર્ણાંક nest_offset;
};

સ્થિર શૂન્ય create_trie(સંરચના trie_ગાંઠ *ગાંઠ,
                        પૂર્ણાંક from, પૂર્ણાંક to, પૂર્ણાંક index_start,
                        પૂર્ણાંક n_trie, સંરચના trie_info *trie)
{
    પૂર્ણાંક i;
    પૂર્ણાંક start, end, index_end;
    અક્ષર cur;
    સંરચના trie_ગાંઠ *child;

    માટે (i = from; i < to; i = end) {
        cur = trie[i].name[index_start];
        start = i++;
        માટે (; i < to; i++)
            જો (cur != trie[i].name[index_start])
                તોડો;
        end = i;
        જો (start == end - 1 ||
            (trie[start].name[index_start] &&
             trie[start].name[index_start + 1] == 0))
            index_end = trie[start].str_size - 1;
        નહીંતર {
            index_end = index_start + 1;
            માટે (;;) {
                cur = trie[start].name[index_end];
                માટે (i = start + 1; i < end; i++)
                    જો (cur != trie[i].name[index_end])
                        તોડો;
                જો (trie[start].name[index_end] &&
                    trie[start].name[index_end + 1] == 0) {
                    end = start + 1;
                    index_end = trie[start].str_size - 1;
                    તોડો;
                }
                જો (i != end)
                    તોડો;
                index_end++;
            }
        }
        ગાંઠ->child = tcc_realloc(ગાંઠ->child,
                                  (ગાંઠ->n_child + 1) *
                                  કદ(સંરચના trie_ગાંઠ));
        child = &ગાંઠ->child[ગાંઠ->n_child];
        child->start = start;
        child->end = end;
        child->index_start = index_start;
        child->index_end = index_end;
        child->n_child = 0;
        child->child = ખાલી;
        ગાંઠ->n_child++;
        જો (start != end - 1)
            create_trie(child, start, end, index_end, n_trie, trie);
    }
}

સ્થિર પૂર્ણાંક create_seq(પૂર્ણાંક *offset, પૂર્ણાંક *n_seq, સંરચના trie_seq **seq,
                        સંરચના trie_ગાંઠ *ગાંઠ,
                        પૂર્ણાંક n_trie, સંરચના trie_info *trie)
{
    પૂર્ણાંક i, nest_offset, last_seq = *n_seq, retval = *offset;
    સંરચના trie_seq *p_seq;
    સંરચના trie_ગાંઠ *p_nest;

    માટે (i = 0; i < ગાંઠ->n_child; i++) {
        p_nest = &ગાંઠ->child[i];
        *seq = tcc_realloc(*seq, (*n_seq + 1) * કદ(સંરચના trie_seq));
        p_seq = &(*seq)[(*n_seq)++];
        p_seq->n_child = i == 0 ? ગાંઠ->n_child : -1;
        p_seq->ગાંઠ = p_nest;
        p_seq->offset = *offset;
        p_seq->nest_offset = 0;
        *offset += (i == 0 ? 1 + 1 : 0) +
                   p_nest->index_end - p_nest->index_start + 1 + 3;
    }
    માટે (i = 0; i < ગાંઠ->n_child; i++) {
        nest_offset =
            create_seq(offset, n_seq, seq, &ગાંઠ->child[i], n_trie, trie);
        p_seq = &(*seq)[last_seq + i];
        p_seq->nest_offset = nest_offset;
    }
    પાછા retval;
}

સ્થિર શૂન્ય ગાંઠ_free(સંરચના trie_ગાંઠ *ગાંઠ)
{
    પૂર્ણાંક i;

    માટે (i = 0; i < ગાંઠ->n_child; i++)
	ગાંઠ_free(&ગાંઠ->child[i]);
    tcc_free(ગાંઠ->child);
}

સ્થિર પૂર્ણાંક triecmp(અચલ શૂન્ય *_a, અચલ શૂન્ય *_b, શૂન્ય *arg)
{
    સંરચના trie_info *a = (સંરચના trie_info *) _a;
    સંરચના trie_info *b = (સંરચના trie_info *) _b;
    પૂર્ણાંક len_a = strlen(a->name);
    પૂર્ણાંક len_b = strlen(b->name);

    /* strange sorting needed. Name 'xx' should be after 'xx1' */
    જો (!strncmp(a->name, b->name, len_a < len_b ? len_a : len_b))
	પાછા len_a < len_b ? 1 : (len_a > len_b ? -1 : 0);
    પાછા strcmp(a->name, b->name);
}

સ્થિર શૂન્ય export_trie(TCCState *s1, સંરચના macho *mo)
{
    પૂર્ણાંક i, size, offset = 0, save_offset;
    uint8_t *ptr;
    પૂર્ણાંક sym_index;
    પૂર્ણાંક sym_end = symtab_section->data_offset / કદ(ElfW(Sym));
    પૂર્ણાંક n_trie = 0, n_seq = 0;
    સંરચના trie_info *trie = ખાલી, *p_trie;
    સંરચના trie_ગાંઠ ગાંઠ, *p_ગાંઠ;
    સંરચના trie_seq *seq = ખાલી;
    addr_t vm_addr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;

    માટે (sym_index = 1; sym_index < sym_end; ++sym_index) {
	ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
	અચલ અક્ષર *name = (અક્ષર*)symtab_section->link->data + sym->st_name;

	જો (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE &&
            (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL ||
	     ELFW(ST_BIND)(sym->st_info) == STB_WEAK)) {
	    પૂર્ણાંક flag = EXPORT_પ્રતીક_FLAGS_KIND_REGULAR;
	    addr_t addr =
		sym->st_કિંમત + s1->sections[sym->st_shndx]->sh_addr - vm_addr;

	    જો (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
		flag |= EXPORT_પ્રતીક_FLAGS_WEAK_DEFINITION;
	    dprintf ("%s %d %llx\n", name, flag, (long long)addr + vm_addr);
	    trie = tcc_realloc(trie, (n_trie + 1) * કદ(સંરચના trie_info));
	    trie[n_trie].name = name;
	    trie[n_trie].flag = flag;
	    trie[n_trie].addr = addr;
	    trie[n_trie].str_size = strlen(name) + 1;
	    trie[n_trie].term_size = uleb128_size(flag) + uleb128_size(addr);
	    n_trie++;
	}
    }
    જો (n_trie) {
        tcc_qsort(trie, n_trie, કદ(સંરચના trie_info), triecmp, ખાલી);
	memset(&ગાંઠ, 0, કદ(ગાંઠ));
        create_trie(&ગાંઠ, 0, n_trie, 0, n_trie, trie);
	create_seq(&offset, &n_seq, &seq, &ગાંઠ, n_trie, trie);
        save_offset = offset;
        માટે (i = 0; i < n_seq; i++) {
            p_ગાંઠ = seq[i].ગાંઠ;
            જો (p_ગાંઠ->n_child == 0) {
                p_trie = &trie[p_ગાંઠ->start];
                seq[i].nest_offset = offset;
                offset += 1 + p_trie->term_size + 1;
            }
        }
        માટે (i = 0; i < n_seq; i++) {
            p_ગાંઠ = seq[i].ગાંઠ;
            p_trie = &trie[p_ગાંઠ->start];
            જો (seq[i].n_child >= 0) {
                section_ptr_add(mo->exports,
				seq[i].offset - mo->exports->data_offset);
                ptr = section_ptr_add(mo->exports, 2);
                *ptr++ = 0;
                *ptr = seq[i].n_child;
            }
            size = p_ગાંઠ->index_end - p_ગાંઠ->index_start;
            ptr = section_ptr_add(mo->exports, size + 1);
            memcpy(ptr, &p_trie->name[p_ગાંઠ->index_start], size);
            ptr[size] = 0;
            write_uleb128(mo->exports, seq[i].nest_offset);
        }
        section_ptr_add(mo->exports, save_offset - mo->exports->data_offset);
        માટે (i = 0; i < n_seq; i++) {
            p_ગાંઠ = seq[i].ગાંઠ;
            જો (p_ગાંઠ->n_child == 0) {
                p_trie = &trie[p_ગાંઠ->start];
                write_uleb128(mo->exports, p_trie->term_size);
                write_uleb128(mo->exports, p_trie->flag);
                write_uleb128(mo->exports, p_trie->addr);
                ptr = section_ptr_add(mo->exports, 1);
                *ptr = 0;
            }
        }
        section_ptr_add(mo->exports, -mo->exports->data_offset & 7);
	ગાંઠ_free(&ગાંઠ);
        tcc_free(seq);
    }
    tcc_free(trie);
}

સ્થિર શૂન્ય collect_sections(TCCState *s1, સંરચના macho *mo, અચલ અક્ષર *filename)
{
    પૂર્ણાંક i, sk, numsec;
    પૂર્ણાંક used_segment[N_SEGMENT];
    uint64_t curaddr, fileofs;
    Section *s;
    સંરચના segment_command_64 *seg;
    સંરચના dylib_command *dylib;
#ifdef CONFIG_NEW_MACHO
    સંરચના linkedit_data_command *chained_fixups_lc;
    સંરચના linkedit_data_command *export_trie_lc;
#endif
    સંરચના build_version_command *dyldbv;
    સંરચના source_version_command *dyldsv;
    સંરચના rpath_command *rpath;
    સંરચના dylinker_command *dyldlc;
    સંરચના symtab_command *symlc;
    સંરચના dysymtab_command *dysymlc;
    અક્ષર *str;

    માટે (i = 0; i < N_SEGMENT; i++)
	used_segment[i] = all_segment[i].used;

    memset (mo->sk_to_sect, 0, કદ(mo->sk_to_sect));
    માટે (i = s1->nb_sections; i-- > 1;) {
        પૂર્ણાંક type, flags;
        s = s1->sections[i];
        type = s->sh_type;
        flags = s->sh_flags;
        sk = sk_unknown;
	/* debug sections have sometimes no SHF_ALLOC */
        જો ((flags & SHF_ALLOC) || !strncmp(s->name, ".debug_", 7)) {
            પસંદગી (type) {
            મૂળભૂત:           sk = sk_unknown; તોડો;
            સ્થિતિ SHT_INIT_ARRAY: sk = sk_init; તોડો;
            સ્થિતિ SHT_FINI_ARRAY: sk = sk_fini; તોડો;
            સ્થિતિ SHT_NOBITS:   sk = sk_bss; તોડો;
            સ્થિતિ SHT_SYMTAB:   sk = sk_discard; તોડો;
            સ્થિતિ SHT_STRTAB:
		જો (s == stabstr_section)
		  sk = sk_stab_str;
		નહીંતર
		  sk = sk_discard;
		તોડો;
            સ્થિતિ SHT_RELX:     sk = sk_discard; તોડો;
            સ્થિતિ SHT_LINKEDIT: sk = sk_linkedit; તોડો;
            સ્થિતિ SHT_PROGBITS:
                જો (s == mo->stubs)
                  sk = sk_stubs;
#ifndef CONFIG_NEW_MACHO
                નહીંતર જો (s == mo->stub_helper)
                  sk = sk_stub_helper;
                નહીંતર જો (s == mo->la_પ્રતીક_ptr)
                  sk = sk_la_ptr;
#endif
                નહીંતર જો (s == rodata_section)
                  sk = sk_ro_data;
                નહીંતર જો (s == s1->got)
                  sk = sk_nl_ptr;
                નહીંતર જો (s == stab_section)
                  sk = sk_stab;
                નહીંતર જો (s == dwarf_info_section)
                  sk = sk_debug_info;
                નહીંતર જો (s == dwarf_abbrev_section)
                  sk = sk_debug_abbrev;
                નહીંતર જો (s == dwarf_લીટી_section)
                  sk = sk_debug_લીટી;
                નહીંતર જો (s == dwarf_aranges_section)
                  sk = sk_debug_aranges;
                નહીંતર જો (s == dwarf_str_section)
                  sk = sk_debug_str;
                નહીંતર જો (s == dwarf_લીટી_str_section)
                  sk = sk_debug_લીટી_str;
                નહીંતર જો (flags & SHF_EXECINSTR)
                  sk = sk_text;
                નહીંતર જો (flags & SHF_WRITE)
                  sk = sk_rw_data;
                નહીંતર
                  sk = sk_ro_data;
                તોડો;
            }
        } નહીંતર
          sk = sk_discard;
        s->prev = mo->sk_to_sect[sk].s;
        mo->sk_to_sect[sk].s = s;
	used_segment[skinfo[sk].seg_initial] = 1;
    }

    જો (s1->output_type != TCC_OUTPUT_EXE)
	used_segment[0] = 0;

    માટે (i = 0; i < N_SEGMENT; i++)
	જો (used_segment[i]) {
	    seg = add_segment(mo, all_segment[i].name);
	    જો (i == 1 && s1->output_type != TCC_OUTPUT_EXE)
	        seg->vmaddr = 0;
	    નહીંતર
	        seg->vmaddr = all_segment[i].vmaddr;
	    seg->vmsize = all_segment[i].vmsize;
	    seg->maxprot = all_segment[i].maxprot;
	    seg->initprot = all_segment[i].initprot;
	    seg->flags = all_segment[i].flags;
            માટે (sk = sk_unknown; sk < sk_last; sk++)
		જો (skinfo[sk].seg_initial == i)
	            mo->segment[sk] = mo->nseg - 1;
	}

    જો (s1->output_type != TCC_OUTPUT_EXE) {
	અચલ અક્ષર *name = s1->install_name ? s1->install_name : filename;
        i = (કદ(*dylib) + strlen(name) + 1 + 7) &-8;
        dylib = add_lc(mo, LC_ID_DYLIB, i);
	dylib->name = કદ(*dylib);
	dylib->timestamp = 1;
	dylib->current_version =
	    s1->current_version ? s1->current_version : 1 << 16;
	dylib->compatibility_version =
	    s1->compatibility_version ? s1->compatibility_version : 1 << 16;
        str = (અક્ષર*)dylib + dylib->name;
        strcpy(str, name);
    }

#ifdef CONFIG_NEW_MACHO
    chained_fixups_lc = add_lc(mo, LC_DYLD_CHAINED_FIXUPS,
			       કદ(સંરચના linkedit_data_command));
    export_trie_lc = add_lc(mo, LC_DYLD_EXPORTS_TRIE,
			    કદ(સંરચના linkedit_data_command));
#નહીંતર
    mo->dyldinfo = add_lc(mo, LC_DYLD_INFO_ONLY, કદ(*mo->dyldinfo));
#endif

    symlc = add_lc(mo, LC_SYMTAB, કદ(*symlc));
    dysymlc = add_lc(mo, LC_DYSYMTAB, કદ(*dysymlc));

    જો (s1->output_type == TCC_OUTPUT_EXE) {
        i = (કદ(*dyldlc) + strlen("/usr/lib/dyld") + 1 + 7) &-8;
        dyldlc = add_lc(mo, LC_LOAD_DYLINKER, i);
        dyldlc->name = કદ(*dyldlc);
        str = (અક્ષર*)dyldlc + dyldlc->name;
        strcpy(str, "/usr/lib/dyld");
    }

    dyldbv = add_lc(mo, LC_BUILD_VERSION, કદ(*dyldbv));
    dyldbv->platform = PLATFORM_MACOS;
    dyldbv->minos = (10 << 16) + (6 << 8);
    dyldbv->sdk = (10 << 16) + (6 << 8);
    dyldbv->ntools = 0;

    dyldsv = add_lc(mo, LC_SOURCE_VERSION, કદ(*dyldsv));
    dyldsv->version = 0;

    જો (s1->output_type == TCC_OUTPUT_EXE) {
        mo->ep = add_lc(mo, LC_MAIN, કદ(*mo->ep));
        mo->ep->entryoff = 4096;
    }

    માટે(i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *dllref = s1->loaded_dlls[i];
        જો (dllref->level == 0)
          add_dylib(mo, dllref->name);
    }

    જો (s1->rpath) {
	અક્ષર *path = s1->rpath, *end;
	કરો {
	    end = strchr(path, ':');
	    જો (!end)
		end = strchr(path, 0);
            i = (કદ(*rpath) + (end - path) + 1 + 7) &-8;
            rpath = add_lc(mo, LC_RPATH, i);
            rpath->path = કદ(*rpath);
            str = (અક્ષર*)rpath + rpath->path;
            memcpy(str, path, end - path);
	    str[end - path] = 0;
	    path = end + 1;
	} જ્યારે (*end);
    }

    fileofs = 4096;  /* leave space for mach-o headers */
    curaddr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;
    curaddr += 4096;
    seg = ખાલી;
    numsec = 0;
    mo->elfsectomacho = tcc_mallocz(કદ(*mo->elfsectomacho) * s1->nb_sections);
    માટે (sk = sk_unknown; sk < sk_last; sk++) {
        સંરચના section_64 *sec = ખાલી;
        જો (seg) {
            seg->vmsize = curaddr - seg->vmaddr;
            seg->filesize = fileofs - seg->fileoff;
        }
#ifdef CONFIG_NEW_MACHO
	જો (sk == sk_linkedit) {
	    calc_fixup_size(s1, mo);
	    export_trie(s1, mo);
	}
#નહીંતર
	જો (sk == sk_linkedit) {
	    bind_rebase(s1, mo);
	    export_trie(s1, mo);
	}
#endif
        જો (skinfo[sk].seg_initial &&
	    (s1->output_type != TCC_OUTPUT_EXE || mo->segment[sk]) &&
	    mo->sk_to_sect[sk].s) {
            uint64_t al = 0;
            પૂર્ણાંક si;
            seg = get_segment(mo, mo->segment[sk]);
            જો (skinfo[sk].name) {
                si = add_section(mo, &seg, skinfo[sk].name);
                numsec++;
                mo->lc[mo->seg2lc[mo->segment[sk]]] = (સંરચના load_command*)seg;
                mo->sk_to_sect[sk].machosect = si;
                sec = get_section(seg, si);
                sec->flags = skinfo[sk].flags;
		જો (sk == sk_stubs)
#ifdef TCC_TARGET_X86_64
	    	    sec->reserved2 = 6;
#અથવાજો defined TCC_TARGET_ARM64
	    	    sec->reserved2 = 12;
#endif
		જો (sk == sk_nl_ptr)
	    	    sec->reserved1 = mo->nr_plt;
#ifndef CONFIG_NEW_MACHO
		જો (sk == sk_la_ptr)
	    	    sec->reserved1 = mo->nr_plt + mo->n_got;
#endif
            }
            જો (seg->vmaddr == -1) {
                curaddr = (curaddr + SEG_PAGE_SIZE - 1) & -SEG_PAGE_SIZE;
                seg->vmaddr = curaddr;
                fileofs = (fileofs + SEG_PAGE_SIZE - 1) & -SEG_PAGE_SIZE;
                seg->fileoff = fileofs;
            }

            માટે (s = mo->sk_to_sect[sk].s; s; s = s->prev) {
                પૂર્ણાંક a = exact_log2p1(s->sh_addralign);
                જો (a && al < (a - 1))
                  al = a - 1;
                s->sh_size = s->data_offset;
            }
            જો (sec)
              sec->align = al;
            al = 1ULL << al;
            જો (al > 4096)
              tcc_warning("alignment > 4096"), sec->align = 12, al = 4096;
            curaddr = (curaddr + al - 1) & -al;
            fileofs = (fileofs + al - 1) & -al;
            જો (sec) {
                sec->addr = curaddr;
                sec->offset = fileofs;
            }
            માટે (s = mo->sk_to_sect[sk].s; s; s = s->prev) {
                al = s->sh_addralign;
                curaddr = (curaddr + al - 1) & -al;
                dprintf("%s: curaddr now 0x%lx\n", s->name, (long)curaddr);
                s->sh_addr = curaddr;
                curaddr += s->sh_size;
                જો (s->sh_type != SHT_NOBITS) {
                    fileofs = (fileofs + al - 1) & -al;
                    s->sh_offset = fileofs;
                    fileofs += s->sh_size;
                    dprintf("%s: fileofs now %ld\n", s->name, (long)fileofs);
                }
                જો (sec)
                  mo->elfsectomacho[s->sh_અંક] = numsec;
            }
            જો (sec)
              sec->size = curaddr - sec->addr;
        }
        જો (DEBUG_MACHO)
          માટે (s = mo->sk_to_sect[sk].s; s; s = s->prev) {
              પૂર્ણાંક type = s->sh_type;
              પૂર્ણાંક flags = s->sh_flags;
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
    જો (seg) {
        seg->vmsize = curaddr - seg->vmaddr;
        seg->filesize = fileofs - seg->fileoff;
    }

    /* Fill symtab info */
    symlc->symoff = mo->symtab->sh_offset;
    symlc->nsyms = mo->symtab->data_offset / કદ(સંરચના nlist_64);
    symlc->stroff = mo->strtab->sh_offset;
    symlc->strsize = mo->strtab->data_offset;

    dysymlc->iundefsym = mo->iundef == -1 ? symlc->nsyms : mo->iundef;
    dysymlc->iextdefsym = mo->iextdef == -1 ? dysymlc->iundefsym : mo->iextdef;
    dysymlc->ilocalsym = mo->ilocal == -1 ? dysymlc->iextdefsym : mo->ilocal;
    dysymlc->nlocalsym = dysymlc->iextdefsym - dysymlc->ilocalsym;
    dysymlc->nextdefsym = dysymlc->iundefsym - dysymlc->iextdefsym;
    dysymlc->nundefsym = symlc->nsyms - dysymlc->iundefsym;
    dysymlc->indirectsymoff = mo->indirsyms->sh_offset;
    dysymlc->nindirectsyms = mo->indirsyms->data_offset / કદ(uint32_t);

#ifdef CONFIG_NEW_MACHO
    જો (mo->chained_fixups->data_offset) {
        chained_fixups_lc->dataoff = mo->chained_fixups->sh_offset;
        chained_fixups_lc->datasize = mo->chained_fixups->data_offset;
    }
    જો (mo->exports->data_offset) {
        export_trie_lc->dataoff = mo->exports->sh_offset;
        export_trie_lc->datasize = mo->exports->data_offset;
    }
#નહીંતર
    જો (mo->rebase->data_offset) {
        mo->dyldinfo->rebase_off = mo->rebase->sh_offset;
        mo->dyldinfo->rebase_size = mo->rebase->data_offset;
    }
    જો (mo->binding->data_offset) {
        mo->dyldinfo->bind_off = mo->binding->sh_offset;
        mo->dyldinfo->bind_size = mo->binding->data_offset;
    }
    જો (mo->weak_binding->data_offset) {
        mo->dyldinfo->weak_bind_off = mo->weak_binding->sh_offset;
        mo->dyldinfo->weak_bind_size = mo->weak_binding->data_offset;
    }
    જો (mo->lazy_binding->data_offset) {
        mo->dyldinfo->lazy_bind_off = mo->lazy_binding->sh_offset;
        mo->dyldinfo->lazy_bind_size = mo->lazy_binding->data_offset;
    }
    જો (mo->exports->data_offset) {
        mo->dyldinfo->export_off = mo->exports->sh_offset;
        mo->dyldinfo->export_size = mo->exports->data_offset;
    }
#endif
}

સ્થિર શૂન્ય macho_write(TCCState *s1, સંરચના macho *mo, FILE *fp)
{
    પૂર્ણાંક i, sk;
    uint64_t fileofs = 0;
    Section *s;
    mo->mh.mh.magic = MH_MAGIC_64;
#ifdef TCC_TARGET_X86_64
    mo->mh.mh.cputype = CPU_TYPE_X86_64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_LIB64 | CPU_SUBTYPE_X86_ALL;
#અથવાજો defined TCC_TARGET_ARM64
    mo->mh.mh.cputype = CPU_TYPE_ARM64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_ARM64_ALL;
#endif
    જો (s1->output_type == TCC_OUTPUT_EXE) {
        mo->mh.mh.filetype = MH_EXECUTE;
        mo->mh.mh.flags = MH_DYLDLINK | MH_PIE;
    }
    નહીંતર {
        mo->mh.mh.filetype = MH_DYLIB;
        mo->mh.mh.flags = MH_DYLDLINK;
    }
    mo->mh.mh.ncmds = mo->nlc;
    mo->mh.mh.sizeofcmds = 0;
    માટે (i = 0; i < mo->nlc; i++)
      mo->mh.mh.sizeofcmds += mo->lc[i]->cmdsize;

    fwrite(&mo->mh, 1, કદ(mo->mh), fp);
    fileofs += કદ(mo->mh);
    માટે (i = 0; i < mo->nlc; i++) {
        fwrite(mo->lc[i], 1, mo->lc[i]->cmdsize, fp);
        fileofs += mo->lc[i]->cmdsize;
    }

    માટે (sk = sk_unknown; sk < sk_last; sk++) {
        //struct segment_command_64 *seg;
        જો (skinfo[sk].seg_initial == 0 ||
	    (s1->output_type == TCC_OUTPUT_EXE && !mo->segment[sk]) ||
	    !mo->sk_to_sect[sk].s)
          ચાલુ;
        /*seg =*/ get_segment(mo, mo->segment[sk]);
        માટે (s = mo->sk_to_sect[sk].s; s; s = s->prev) {
            જો (s->sh_type != SHT_NOBITS) {
                જ્યારે (fileofs < s->sh_offset)
                  fputc(0, fp), fileofs++;
                જો (s->sh_size) {
                    fwrite(s->data, 1, s->sh_size, fp);
                    fileofs += s->sh_size;
                }
            }
        }
    }
}

#ifdef CONFIG_NEW_MACHO
સ્થિર પૂર્ણાંક bind_rebase_cmp(અચલ શૂન્ય *_a, અચલ શૂન્ય *_b, શૂન્ય *arg)
{
    TCCState *s1 = arg;
    સંરચના bind_rebase *a = (સંરચના bind_rebase *) _a;
    સંરચના bind_rebase *b = (સંરચના bind_rebase *) _b;
    addr_t aa = s1->sections[a->section]->sh_addr + a->rel.r_offset;
    addr_t ab = s1->sections[b->section]->sh_addr + b->rel.r_offset;

    પાછા aa > ab ? 1 : aa < ab ? -1 : 0;
}

ST_FUNC શૂન્ય bind_rebase_import(TCCState *s1, સંરચના macho *mo)
{
    પૂર્ણાંક i, j, k, bind_index, size, page_ગણતરી, sym_index;
    અચલ અક્ષર *name;
    ElfW(Sym) *sym;
    unsigned અક્ષર *data = mo->chained_fixups->data;
    સંરચના segment_command_64 *seg;
    સંરચના dyld_chained_fixups_header *header;
    સંરચના dyld_chained_starts_in_image *image;
    સંરચના dyld_chained_starts_in_segment *segment;
    સંરચના dyld_chained_import *import;

    tcc_qsort(mo->bind_rebase, mo->n_bind_rebase, કદ(સંરચના bind_rebase),
	      bind_rebase_cmp, s1);
    માટે (i = 0; i < mo->n_bind_rebase - 1; i++)
	જો (mo->bind_rebase[i].section == mo->bind_rebase[i + 1].section &&
	    mo->bind_rebase[i].rel.r_offset == mo->bind_rebase[i + 1].rel.r_offset) {
	    sym_index = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
            sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	    name = (અક્ષર *) symtab_section->link->data + sym->st_name;
	    tcc_error("Overlap %s/%s %s:%s",
		      mo->bind_rebase[i].bind ? "bind" : "rebase",
		      mo->bind_rebase[i + 1].bind ? "bind" : "rebase",
		      s1->sections[mo->bind_rebase[i].section]->name, name);
	}
    header = (સંરચના dyld_chained_fixups_header *) data;
    data += (કદ(સંરચના dyld_chained_fixups_header) + 7) & -8;
    header->starts_offset = data - mo->chained_fixups->data;
    header->imports_ગણતરી = mo->n_bind;
    header->imports_format = DYLD_CHAINED_IMPORT;
    header->symbols_format = 0;
    size = કદ(સંરચના dyld_chained_starts_in_image) +
	   (mo->nseg - 1) * કદ(uint32_t);
    image = (સંરચના dyld_chained_starts_in_image *) data;
    data += (size + 7) & -8;
    image->seg_ગણતરી = mo->nseg;
    માટે (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
        image->seg_info_offset[i] = (data - mo->chained_fixups->data) -
				    header->starts_offset;
	seg = get_segment(mo, i);
	page_ગણતરી = (seg->vmsize + SEG_PAGE_SIZE - 1) / SEG_PAGE_SIZE;
	size = કદ(સંરચના dyld_chained_starts_in_segment) +
		      (page_ગણતરી - 1) * કદ(uint16_t);
        segment = (સંરચના dyld_chained_starts_in_segment *) data;
        data += (size + 7) & -8;
        segment->size = size;
        segment->page_size = SEG_PAGE_SIZE;
#જો 1
#define	PTR_64_OFFSET 0
#define	PTR_64_MASK   0x7FFFFFFFFFFULL
        segment->pointer_format = DYLD_CHAINED_PTR_64;
#નહીંતર
#define	PTR_64_OFFSET 0x100000000ULL
#define	PTR_64_MASK   0xFFFFFFFFFFFFFFULL
        segment->pointer_format = DYLD_CHAINED_PTR_64_OFFSET;
#endif
        segment->segment_offset = seg->fileoff;
        segment->max_valid_pointer = 0;
        segment->page_ગણતરી = page_ગણતરી;
	// add bind/rebase
	bind_index = 0;
	k = 0;
	માટે (j = 0; j < page_ગણતરી; j++) {
	    addr_t start = seg->vmaddr + j * SEG_PAGE_SIZE;
	    addr_t end = start + SEG_PAGE_SIZE;
	    શૂન્ય *last = ખાલી;
	    addr_t last_o = 0;
	    addr_t cur_o, cur;
	    સંરચના dyld_chained_ptr_64_rebase *rebase;
	    સંરચના dyld_chained_ptr_64_bind *bind;

	    segment->page_start[j] = DYLD_CHAINED_PTR_START_NONE;
	    માટે (; k < mo->n_bind_rebase; k++) {
	        Section *s = s1->sections[mo->bind_rebase[k].section];
		addr_t r_offset = mo->bind_rebase[k].rel.r_offset;
		addr_t addr = s->sh_addr + r_offset;

		જો ((addr & 3) ||
		    (addr & (SEG_PAGE_SIZE - 1)) > SEG_PAGE_SIZE - PTR_SIZE)
		    tcc_error("Illegal rel_offset %s %lld",
			      s->name, (long long)r_offset);
		જો (addr >= end)
		    તોડો;
		જો (addr >= start) {
		    cur_o = addr - start;
	            જો (mo->bind_rebase[k].bind) {
		        જો (segment->page_start[j] == DYLD_CHAINED_PTR_START_NONE)
			    segment->page_start[j] = cur_o;
		        નહીંતર {
			    bind = (સંરચના dyld_chained_ptr_64_bind *) last;
			    bind->next = (cur_o - last_o) / 4;
		        }
		        bind = (સંરચના dyld_chained_ptr_64_bind *)
				    (s->data + r_offset);
		        last = bind;
		        last_o = cur_o;
		        bind->ordinal = bind_index;
		        bind->addend = 0;
		        bind->reserved = 0;
		        bind->next = 0;
		        bind->bind = 1;
		    }
		    નહીંતર {
		        જો (segment->page_start[j] == DYLD_CHAINED_PTR_START_NONE)
			    segment->page_start[j] = cur_o;
		        નહીંતર {
			    rebase = (સંરચના dyld_chained_ptr_64_rebase *) last;
			    rebase->next = (cur_o - last_o) / 4;
		        }
		        rebase = (સંરચના dyld_chained_ptr_64_rebase *)
				    (s->data + r_offset);
		        last = rebase;
		        last_o = cur_o;
		        cur = (*(uint64_t *) (s->data + r_offset)) -
			      PTR_64_OFFSET;
		        rebase->target = cur & PTR_64_MASK;
		        rebase->high8 = cur >> (64 - 8);
			જો (cur != ((uint64_t)rebase->high8 << (64 - 8)) + rebase->target)
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
    import = (સંરચના dyld_chained_import *) data;
    data += mo->n_bind * કદ (સંરચના dyld_chained_import);
    header->symbols_offset = data - mo->chained_fixups->data;
    data++;
    માટે (i = 0, bind_index = 0; i < mo->n_bind_rebase; i++) {
	જો (mo->bind_rebase[i].bind) {
	    import[bind_index].lib_ordinal =
		BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xffu;
	    import[bind_index].name_offset =
		(data - mo->chained_fixups->data) - header->symbols_offset;
	    sym_index = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	    import[bind_index].weak_import =
		ELFW(ST_BIND)(sym->st_info) == STB_WEAK;
	    name = (અક્ષર *) symtab_section->link->data + sym->st_name;
            strcpy((અક્ષર *) data, name);
	    data += strlen(name) + 1;
	    bind_index++;
	}
    }
    tcc_free(mo->bind_rebase);
}
#endif

ST_FUNC પૂર્ણાંક macho_output_file(TCCState *s1, અચલ અક્ષર *filename)
{
    પૂર્ણાંક fd, mode, file_type;
    FILE *fp;
    પૂર્ણાંક i, ret = -1;
    સંરચના macho mo;

    (શૂન્ય)memset(&mo, 0, કદ(mo));

    file_type = s1->output_type;
    જો (file_type == TCC_OUTPUT_OBJ)
        mode = 0666;
    નહીંતર
        mode = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_દ્વિઅંકી_2, mode);
    જો (fd < 0 || (fp = fdopen(fd, "wb")) == ખાલી) {
        tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
        પાછા -1;
    }
    tcc_add_runtime(s1);
    tcc_macho_add_destructor(s1);
    resolve_common_syms(s1);
    create_symtab(s1, &mo);
    check_relocs(s1, &mo);
    ret = check_symbols(s1, &mo);
    જો (!ret) {
	પૂર્ણાંક save_output = s1->output_type;

        collect_sections(s1, &mo, filename);
        relocate_syms(s1, s1->symtab, 0);
	જો (s1->output_type == TCC_OUTPUT_EXE)
            mo.ep->entryoff = get_sym_addr(s1, "main", 1, 1)
                            -     get_segment(&mo, 1)->vmaddr;
        જો (s1->nb_errors)
          જાઓ do_ret;
	// Macho uses bind/rebase instead of dynsym
	s1->output_type = TCC_OUTPUT_EXE;
        relocate_sections(s1);
	s1->output_type = save_output;
#ifdef CONFIG_NEW_MACHO
	bind_rebase_import(s1, &mo);
#endif
        convert_symbols(s1, &mo);
        જો (s1->verbose)
            printf("<- %s\n", filename);
        macho_write(s1, &mo, fp);
    }

 do_ret:
    માટે (i = 0; i < mo.nlc; i++)
      tcc_free(mo.lc[i]);
    tcc_free(mo.seg2lc);
    tcc_free(mo.lc);
    tcc_free(mo.elfsectomacho);
    tcc_free(mo.e2msym);

    fclose(fp);
#ifdef CONFIG_CODESIGN
    જો (!ret) {
	અક્ષર command[1024];
	પૂર્ણાંક retval;

	snprintf(command, કદ(command), "codesign -f -s - %s", filename);
	retval = system (command);
	જો (retval == -1 || !(WIFEXITED(retval) && WEXITSTATUS(retval) == 0))
	    tcc_error ("command failed '%s'", command);
    }
#endif
    પાછા ret;
}

સ્થિર uint32_t macho_swap32(uint32_t x)
{
  પાછા (x >> 24) | (x << 24) | ((x >> 8) & 0xff00) | ((x & 0xff00) << 8);
}
#define SWAP(x) (swap ? macho_swap32(x) : (x))
#define tbd_parse_movepast(s) \
    (pos = (pos = strstr(pos, s)) ? pos + strlen(s) : ખાલી)
#define tbd_parse_movetoany(cs) (pos = strpbrk(pos, cs))
#define tbd_parse_skipws જ્યારે (*pos && (*pos==' '||*pos=='\n')) ++pos
#define tbd_parse_tramplequote જો(*pos=='\''||*pos=='"') tbd_parse_trample
#define tbd_parse_tramplespace જો(*pos==' ') tbd_parse_trample
#define tbd_parse_trample *pos++=0

#ifdef TCC_IS_NATIVE
/* Looks for the active developer SDK set by xcode-select (or the default
   one set during installation.) */
ST_FUNC શૂન્ય tcc_add_macos_sdkpath(TCCState* s)
{
    અક્ષર *sdkroot = ખાલી, *pos = ખાલી;
    શૂન્ય* xcs = dlopen("libxcselect.dylib", RTLD_GLOBAL | RTLD_LAZY);
    CString path;
    પૂર્ણાંક (*f)(unsigned પૂર્ણાંક, અક્ષર**) = dlsym(xcs, "xcselect_host_sdk_path");
    cstr_new(&path);
    જો (f) f(1, &sdkroot);
    જો (sdkroot)
        pos = strstr(sdkroot,"SDKs/MacOSX");
    જો (pos)
        cstr_printf(&path, "%.*s.sdk/usr/lib", (પૂર્ણાંક)(pos - sdkroot + 11), sdkroot);
    /* must use free from libc directly */
#pragma ધકેલો_macro("free")
#undef મુક્ત
    મુક્ત(sdkroot);
#pragma કાઢો_macro("free")
    જો (path.size)
        tcc_add_library_path(s, (અક્ષર*)path.data);
    નહીંતર
        tcc_add_library_path(s,
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib"
            ":" "/Applications/Xcode.app/Developer/SDKs/MacOSX.sdk/usr/lib"
            );
    cstr_free(&path);
}

ST_FUNC અક્ષર* macho_tbd_soname(પૂર્ણાંક fd) {
    અક્ષર *soname, *data, *pos;
    અક્ષર *ret = 0;
    pos = data = tcc_load_text(fd);
    જો (!tbd_parse_movepast("install-name: ")) જાઓ the_end;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    જો (!tbd_parse_movetoany("\n \"'")) જાઓ the_end;
    tbd_parse_trample;
    ret = tcc_strdup(soname);
the_end:
    tcc_free(data);
    પાછા ret;
}
#endif /* TCC_IS_NATIVE */

ST_FUNC પૂર્ણાંક macho_load_tbd(TCCState* s1, પૂર્ણાંક fd, અચલ અક્ષર* filename, પૂર્ણાંક lev)
{
    અક્ષર *soname, *data, *pos;
    પૂર્ણાંક ret = -1;

    pos = data = tcc_load_text(fd);
    જો (!tbd_parse_movepast("install-name: ")) જાઓ the_end;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    જો (!tbd_parse_movetoany("\n \"'")) જાઓ the_end;
    tbd_parse_trample;
    ret = 0;
    જો (tcc_add_dllref(s1, soname, lev)->found)
        જાઓ the_end;
    જ્યારે(pos) {
        અક્ષર* sym = ખાલી;
        પૂર્ણાંક cont = 1;
        જો (!tbd_parse_movepast("symbols: ")) તોડો;
        જો (!tbd_parse_movepast("[")) તોડો;
        જ્યારે (cont) {
            tbd_parse_skipws;
            tbd_parse_tramplequote;
            sym = pos;
            જો (!tbd_parse_movetoany(",] \"'")) તોડો;
            tbd_parse_tramplequote;
            tbd_parse_tramplespace;
            tbd_parse_skipws;
            જો (*pos==0||*pos==']') cont=0;
            tbd_parse_trample;
            set_elf_sym(s1->dynsymtab_section, 0, 0,
                ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0, SHN_UNDEF, sym);
        }
    }

the_end:
    tcc_free(data);
    પાછા ret;
}

ST_FUNC પૂર્ણાંક macho_load_dll(TCCState * s1, પૂર્ણાંક fd, અચલ અક્ષર* filename, પૂર્ણાંક lev)
{
    unsigned અક્ષર buf[કદ(સંરચના mach_header_64)];
    શૂન્ય *buf2;
    uint32_t machofs = 0;
    સંરચના fat_header fh;
    સંરચના mach_header mh;
    સંરચના load_command *lc;
    પૂર્ણાંક i, swap = 0;
    અચલ અક્ષર *soname = filename;
    સંરચના nlist_64 *symtab = 0;
    uint32_t nsyms = 0;
    અક્ષર *strtab = 0;
    uint32_t strsize = 0;
    uint32_t iextdef = 0;
    uint32_t nextdef = 0;

  again:
    જો (full_read(fd, buf, કદ(buf)) != કદ(buf))
      પાછા -1;
    memcpy(&fh, buf, કદ(fh));
    જો (fh.magic == FAT_MAGIC || fh.magic == FAT_CIGAM) {
        સંરચના fat_arch *fa = load_data(fd, કદ(fh),
                                        fh.nfat_arch * કદ(*fa));
        swap = fh.magic == FAT_CIGAM;
        માટે (i = 0; i < SWAP(fh.nfat_arch); i++)
#ifdef TCC_TARGET_X86_64
          જો (SWAP(fa[i].cputype) == CPU_TYPE_X86_64
              && SWAP(fa[i].cpusubtype) == CPU_SUBTYPE_X86_ALL)
#અથવાજો defined TCC_TARGET_ARM64
          જો (SWAP(fa[i].cputype) == CPU_TYPE_ARM64
              && SWAP(fa[i].cpusubtype) == CPU_SUBTYPE_ARM64_ALL)
#endif
            તોડો;
        જો (i == SWAP(fh.nfat_arch)) {
            tcc_free(fa);
            પાછા -1;
        }
        machofs = SWAP(fa[i].offset);
        tcc_free(fa);
        lseek(fd, machofs, SEEK_SET);
        જાઓ again;
    } નહીંતર જો (fh.magic == FAT_MAGIC_64 || fh.magic == FAT_CIGAM_64) {
        tcc_warning("%s: Mach-O fat 64bit files of type 0x%x not handled",
                    filename, fh.magic);
        પાછા -1;
    }

    memcpy(&mh, buf, કદ(mh));
    જો (mh.magic != MH_MAGIC_64)
      પાછા -1;
    dprintf("found Mach-O at %d\n", machofs);
    buf2 = load_data(fd, machofs + કદ(સંરચના mach_header_64), mh.sizeofcmds);
    માટે (i = 0, lc = buf2; i < mh.ncmds; i++) {
        dprintf("lc %2d: 0x%08x\n", i, lc->cmd);
        પસંદગી (lc->cmd) {
        સ્થિતિ LC_SYMTAB:
        {
            સંરચના symtab_command *sc = (સંરચના symtab_command*)lc;
            nsyms = sc->nsyms;
            symtab = load_data(fd, machofs + sc->symoff, nsyms * કદ(*symtab));
            strsize = sc->strsize;
            strtab = load_data(fd, machofs + sc->stroff, strsize);
            તોડો;
        }
        સ્થિતિ LC_ID_DYLIB:
        {
            સંરચના dylib_command *dc = (સંરચના dylib_command*)lc;
            soname = (અક્ષર*)lc + dc->name;
            dprintf(" ID_DYLIB %d 0x%x 0x%x %s\n",
                    dc->timestamp, dc->current_version,
                    dc->compatibility_version, soname);
            તોડો;
        }
        સ્થિતિ LC_REEXPORT_DYLIB:
        {
            સંરચના dylib_command *dc = (સંરચના dylib_command*)lc;
            અક્ષર *name = (અક્ષર*)lc + dc->name;
            પૂર્ણાંક subfd = open(name, O_RDONLY | O_દ્વિઅંકી_2);
            dprintf(" REEXPORT %s\n", name);
            જો (subfd < 0)
              tcc_warning("can't open %s (reexported from %s)", name, filename);
            નહીંતર {
                /* Hopefully the REEXPORTs never form a cycle, we don't check
                   for that!  */
                macho_load_dll(s1, subfd, name, lev + 1);
                close(subfd);
            }
            તોડો;
        }
        સ્થિતિ LC_DYSYMTAB:
        {
            સંરચના dysymtab_command *dc = (સંરચના dysymtab_command*)lc;
            iextdef = dc->iextdefsym;
            nextdef = dc->nextdefsym;
            તોડો;
        }
        }
        lc = (સંરચના load_command*) ((અક્ષર*)lc + lc->cmdsize);
    }

    જો (tcc_add_dllref(s1, soname, lev)->found)
        જાઓ the_end;

    જો (!nsyms || !nextdef)
      tcc_warning("%s doesn't export any symbols?", filename);

    //dprintf("symbols (all):\n");
    dprintf("symbols (exported):\n");
    dprintf("    n: typ sec   desc              value name\n");
    //for (i = 0; i < nsyms; i++) {
    માટે (i = iextdef; i < iextdef + nextdef; i++) {
        સંરચના nlist_64 *sym = symtab + i;
        dprintf("%5d: %3d %3d 0x%04x 0x%016lx %s\n",
                i, sym->n_type, sym->n_sect, sym->n_desc, (long)sym->n_કિંમત,
                strtab + sym->n_strx);
        set_elf_sym(s1->dynsymtab_section, 0, 0,
                    ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
                    0, SHN_UNDEF, strtab + sym->n_strx);
    }

  the_end:
    tcc_free(strtab);
    tcc_free(symtab);
    tcc_free(buf2);
    પાછા 0;
}
