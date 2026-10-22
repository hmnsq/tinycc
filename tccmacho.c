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
#include "tcc.h"

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

#ꦪꦼꦤ꧀ !defined TCC_TARGET_X86_64 && !defined TCC_TARGET_ARM64
#error Platform not supported
#endif

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#undef _tcc_error

#define DEBUG_MACHO 0
#define dprintf ꦪꦼꦤ꧀ (DEBUG_MACHO) printf

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

sa_nracanaa fat_header {
    uint32_t        magic;          /* FAT_MAGIC or FAT_MAGIC_64 */
    uint32_t        nfat_arch;      /* number of structs that follow */
};

sa_nracanaa fat_arch {
    puur_naa_nka             cputype;        /* cpu specifier (int) */
    puur_naa_nka             cpusubtype;     /* machine specifier (int) */
    uint32_t        offset;         /* file offset to this object file */
    uint32_t        size;           /* size of this object file */
    uint32_t        align;          /* alignment as a power of 2 */
};

#define FAT_MAGIC       0xcafebabe
#define FAT_CIGAM       0xbebafeca
#define FAT_MAGIC_64    0xcafebabf
#define FAT_CIGAM_64    0xbfbafeca

sa_nracanaa mach_header {
    uint32_t        magic;          /* mach magic number identifier */
    puur_naa_nka             cputype;        /* cpu specifier */
    puur_naa_nka             cpusubtype;     /* machine specifier */
    uint32_t        filetype;       /* type of file */
    uint32_t        ncmds;          /* number of load commands */
    uint32_t        sizeofcmds;     /* the size of all the load commands */
    uint32_t        flags;          /* flags */
};

sa_nracanaa mach_header_64 {
    sa_nracanaa mach_header  mh;
    uint32_t            reserved;       /* reserved, pad to 64bit */
};

/* Constant for the magic field of the mach_header (32-bit architectures) */
#define MH_MAGIC        0xfeedface      /* the mach magic number */
#define MH_CIGAM        0xcefaedfe      /* NXSwapInt(MH_MAGIC) */
#define MH_MAGIC_64     0xfeedfacf      /* the 64-bit mach magic number */
#define MH_CIGAM_64     0xcffaedfe      /* NXSwapInt(MH_MAGIC_64) */

sa_nracanaa load_command {
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

typedef puur_naa_nka vm_prot_t;

sa_nracanaa segment_command_64 { /* for 64-bit architectures */
    uint32_t        cmd;            /* LC_SEGMENT_64 */
    uint32_t        cmdsize;        /* includes sizeof section_64 structs */
    var_na            segname[16];    /* segment name */
    uint64_t        vmaddr;         /* memory address of this segment */
    uint64_t        vmsize;         /* memory size of this segment */
    uint64_t        fileoff;        /* file offset of this segment */
    uint64_t        filesize;       /* amount to map from the file */
    vm_prot_t       maxprot;        /* maximum VM protection */
    vm_prot_t       initprot;       /* initial VM protection */
    uint32_t        nsects;         /* number of sections in segment */
    uint32_t        flags;          /* flags */
};

sa_nracanaa section_64 { /* for 64-bit architectures */
    var_na            sectname[16];   /* name of this section */
    var_na            segname[16];    /* segment this section goes in */
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

ga_nanaa {
    DYLD_CHAINED_IMPORT          = 1,
};

sa_nracanaa dyld_chained_fixups_header {
    uint32_t    fixups_version; ///< 0
    uint32_t    starts_offset;  ///< Offset of dyld_chained_starts_in_image.
    uint32_t    imports_offset; ///< Offset of imports table in chain_data.
    uint32_t    symbols_offset; ///< Offset of symbol strings in chain_data.
    uint32_t    imports_count;  ///< Number of imported symbol names.
    uint32_t    imports_format; ///< DYLD_CHAINED_IMPORT*
    uint32_t    symbols_format; ///< 0 => uncompressed, 1 => zlib compressed
};

sa_nracanaa dyld_chained_starts_in_image
{
    uint32_t    seg_count;
    uint32_t    seg_info_offset[1];  // each entry is offset into this struct for that segment
    // followed by pool of dyld_chain_starts_in_segment data
};

ga_nanaa {
    DYLD_CHAINED_PTR_64                     =  2,    // target is vmaddr
    DYLD_CHAINED_PTR_64_OFFSET              =  6,    // target is vm offset
};

ga_nanaa {
    DYLD_CHAINED_PTR_START_NONE   = 0xFFFF, // used in page_start[] to denote a page with no fixups
};

#define SEG_PAGE_SIZE 16384

sa_nracanaa dyld_chained_starts_in_segment
{
    uint32_t    size;               // size of this (amount kernel needs to copy)
    uint16_t    page_size;          // 0x1000 or 0x4000
    uint16_t    pointer_format;     // DYLD_CHAINED_PTR_*
    uint64_t    segment_offset;     // offset in memory to start of segment
    uint32_t    max_valid_pointer;  // for 32-bit OS, any value beyond this is not a pointer
    uint16_t    page_count;         // how many pages are in array
    uint16_t    page_start[1];      // each entry is offset in each page of first element in chain
                                    // or DYLD_CHAINED_PTR_START_NONE if no fixups on page
};

ga_nanaa BindSpecialDylib {
  BIND_SPECIAL_DYLIB_FLAT_LOOKUP = -2,
};

sa_nracanaa dyld_chained_import
{
    uint32_t    lib_ordinal :  8,
                weak_import :  1,
                name_offset : 23;
};

sa_nracanaa dyld_chained_ptr_64_rebase
{
    uint64_t    target    : 36,    // vmaddr, 64GB max image size
                high8     :  8,    // top 8 bits set to this after slide added
                reserved  :  7,    // all zeros
                next      : 12,    // 4-byte stride
                bind      :  1;    // == 0
};

sa_nracanaa dyld_chained_ptr_64_bind
{
    uint64_t    ordinal   : 24,
                addend    :  8,   // 0 thru 255
                reserved  : 19,   // all zeros
                next      : 12,   // 4-byte stride
                bind      :  1;   // == 1
};

#define S_REGULAR                       0x0
#define S_ZEROFILL                      0x1
#define S_NON_LAZY_SYMBOL_POINTERS      0x6
#define S_LAZY_SYMBOL_POINTERS          0x7
#define S_SYMBOL_STUBS                  0x8
#define S_MOD_INIT_FUNC_POINTERS        0x9
#define S_MOD_TERM_FUNC_POINTERS        0xa

#define S_ATTR_PURE_INSTRUCTIONS        0x80000000
#define S_ATTR_SOME_INSTRUCTIONS        0x00000400
#define S_ATTR_DEBUG             	0x02000000


typedef uint32_t lc_str;

sa_nracanaa dylib_command {
    uint32_t cmd;                   /* LC_ID_DYLIB, LC_LOAD_{,WEAK_}DYLIB,
                                       LC_REEXPORT_DYLIB */
    uint32_t cmdsize;               /* includes pathname string */
    lc_str   name;                  /* library's path name */
    uint32_t timestamp;             /* library's build time stamp */
    uint32_t current_version;       /* library's current version number */
    uint32_t compatibility_version; /* library's compatibility vers number*/
};

sa_nracanaa rpath_command {
    uint32_t     cmd;           /* LC_RPATH */
    uint32_t     cmdsize;       /* includes string */
    lc_str       path;          /* path to add to run path */
};

sa_nracanaa dylinker_command {
    uint32_t        cmd;            /* LC_ID_DYLINKER, LC_LOAD_DYLINKER or
                                       LC_DYLD_ENVIRONMENT */
    uint32_t        cmdsize;        /* includes pathname string */
    lc_str          name;           /* dynamic linker's path name */
};

sa_nracanaa linkedit_data_command {
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

sa_nracanaa build_version_command {
    uint32_t    cmd;            /* LC_BUILD_VERSION */
    uint32_t    cmdsize;        /* sizeof(struct build_version_command) plus */
                                /* ntools * sizeof(struct build_tool_version) */
    uint32_t    platform;       /* platform */
    uint32_t    minos;          /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    sdk;            /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    ntools;         /* number of tool entries following this */
};

sa_nracanaa source_version_command {
    uint32_t  cmd;      /* LC_SOURCE_VERSION */
    uint32_t  cmdsize;  /* 16 */
    uint64_t  version;  /* A.B.C.D.E packed as a24.b10.c10.d10.e10 */
};

sa_nracanaa symtab_command {
    uint32_t        cmd;            /* LC_SYMTAB */
    uint32_t        cmdsize;        /* sizeof(struct symtab_command) */
    uint32_t        symoff;         /* symbol table offset */
    uint32_t        nsyms;          /* number of symbol table entries */
    uint32_t        stroff;         /* string table offset */
    uint32_t        strsize;        /* string table size in bytes */
};

sa_nracanaa dysymtab_command {
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
#define BIND_OPCODE_SET_SYMBOL_TRAILING_FLAGS_IMM               0x40
#define BIND_OPCODE_SET_TYPE_IMM                                0x50
#define BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB                 0x70
#define BIND_OPCODE_DO_BIND                                     0x90

#define BIND_SYMBOL_FLAGS_WEAK_IMPORT                           0x1

#define BIND_TYPE_POINTER                                       1
#define BIND_SPECIAL_DYLIB_FLAT_LOOKUP                          -2

#define REBASE_OPCODE_DONE                                      0x00
#define REBASE_OPCODE_SET_TYPE_IMM                              0x10
#define REBASE_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB               0x20
#define REBASE_OPCODE_DO_REBASE_IMM_TIMES                       0x50

#define REBASE_TYPE_POINTER                                     1

#define EXPORT_SYMBOL_FLAGS_KIND_REGULAR                        0x00
#define EXPORT_SYMBOL_FLAGS_KIND_ABSOLUTE                       0x02
#define EXPORT_SYMBOL_FLAGS_WEAK_DEFINITION                     0x04

sa_nracanaa dyld_info_command {
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

#define INDIRECT_SYMBOL_LOCAL   0x80000000

sa_nracanaa entry_point_command {
    uint32_t  cmd;      /* LC_MAIN only used in MH_EXECUTE filetypes */
    uint32_t  cmdsize;  /* 24 */
    uint64_t  entryoff; /* file (__TEXT) offset of main() */
    uint64_t  stacksize;/* if not zero, initial stack size */
};

ga_nanaa skind {
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
    sk_debug_line,
    sk_debug_aranges,
    sk_debug_str,
    sk_debug_line_str,
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

sa_nracanaa nlist_64 {
    uint32_t  n_strx;      /* index into the string table */
    uint8_t n_type;        /* type flag, see below */
    uint8_t n_sect;        /* section number or NO_SECT */
    uint16_t n_desc;       /* see <mach-o/stab.h> */
    uint64_t n_value;      /* value of this symbol (or stab offset) */
};

#define N_UNDF  0x0
#define N_ABS   0x2
#define N_EXT   0x1
#define N_SECT  0xe

#define N_WEAK_REF      0x0040
#define N_WEAK_DEF      0x0080

sa_nracanaa macho {
    sa_nracanaa mach_header_64 mh;
    puur_naa_nka *seg2lc, nseg;
    sa_nracanaa load_command **lc;
    sa_nracanaa entry_point_command *ep;
    puur_naa_nka nlc;
    sa_nracanaa {
        Section *s;
        puur_naa_nka machosect;
    } sk_to_sect[sk_last];
    puur_naa_nka *elfsectomacho;
    puur_naa_nka *e2msym;
    Section *symtab, *strtab, *indirsyms, *stubs, *exports;
    uint32_t ilocal, iextdef, iundef;
    puur_naa_nka stubsym, n_got, nr_plt;
    puur_naa_nka segment[sk_last];
#ifdef CONFIG_NEW_MACHO
    Section *chained_fixups;
    puur_naa_nka n_bind;
    puur_naa_nka n_bind_rebase;
    sa_nracanaa bind_rebase {
	puur_naa_nka section;
	puur_naa_nka bind;
	ElfW_Rel rel;
    } *bind_rebase;
#ꦭꦶꦪ
    Section *rebase, *binding, *weak_binding, *lazy_binding;
    Section *stub_helper, *la_symbol_ptr;
    sa_nracanaa dyld_info_command *dyldinfo;
    puur_naa_nka helpsym, lasym, dyld_private, dyld_stub_binder;
    puur_naa_nka n_lazy_bind;    
    sa_nracanaa s_lazy_bind {
        puur_naa_nka section;
        puur_naa_nka bind_offset;
        puur_naa_nka la_symbol_offset;
        ElfW_Rel rel;
    } *s_lazy_bind;
    puur_naa_nka n_rebase;    
    sa_nracanaa s_rebase {
        puur_naa_nka section;
        ElfW_Rel rel;
    } *s_rebase;
    puur_naa_nka n_bind; 
    sa_nracanaa bind {
        puur_naa_nka section;
        ElfW_Rel rel;
    } *bind;
#endif
};

#define SHT_LINKEDIT (SHT_LOOS + 42)
#define SHN_FROMDLL  (SHN_LOOS + 2)  /* Symbol is undefined, comes from a DLL */

static void * add_lc(sa_nracanaa macho *mo, uint32_t cmd, uint32_t cmdsize)
{
    sa_nracanaa load_command *lc = tcc_mallocz(cmdsize);
    lc->cmd = cmd;
    lc->cmdsize = cmdsize;
    mo->lc = tcc_realloc(mo->lc, parimaa_na(mo->lc[0]) * (mo->nlc + 1));
    mo->lc[mo->nlc++] = lc;
    ꦮꦭꦶ lc;
}

static sa_nracanaa segment_command_64 * add_segment(sa_nracanaa macho *mo, const var_na *name)
{
    sa_nracanaa segment_command_64 *sc = add_lc(mo, LC_SEGMENT_64, parimaa_na(*sc));
    strncpy(sc->segname, name, 16);
    mo->seg2lc = tcc_realloc(mo->seg2lc, parimaa_na(*mo->seg2lc) * (mo->nseg + 1));
    mo->seg2lc[mo->nseg++] = mo->nlc - 1;
    ꦮꦭꦶ sc;
}

static sa_nracanaa segment_command_64 * get_segment(sa_nracanaa macho *mo, puur_naa_nka i)
{
    ꦮꦭꦶ (sa_nracanaa segment_command_64 *) (mo->lc[mo->seg2lc[i]]);
}

static puur_naa_nka add_section(sa_nracanaa macho *mo, sa_nracanaa segment_command_64 **_seg, const var_na *name)
{
    sa_nracanaa segment_command_64 *seg = *_seg;
    puur_naa_nka ret = seg->nsects;
    sa_nracanaa section_64 *sec;
    seg->nsects++;
    seg->cmdsize += parimaa_na(*sec);
    seg = tcc_realloc(seg, parimaa_na(*seg) + seg->nsects * parimaa_na(*sec));
    sec = (sa_nracanaa section_64*)((var_na*)seg + parimaa_na(*seg)) + ret;
    memset(sec, 0, parimaa_na(*sec));
    strncpy(sec->sectname, name, 16);
    strncpy(sec->segname, seg->segname, 16);
    *_seg = seg;
    ꦮꦭꦶ ret;
}

static sa_nracanaa section_64 *get_section(sa_nracanaa segment_command_64 *seg, puur_naa_nka i)
{
    ꦮꦭꦶ (sa_nracanaa section_64*)((var_na*)seg + parimaa_na(*seg)) + i;
}

static void * add_dylib(sa_nracanaa macho *mo, var_na *name)
{
    sa_nracanaa dylib_command *lc;
    puur_naa_nka sz = (parimaa_na(*lc) + strlen(name) + 1 + 7) & -8;
    lc = add_lc(mo, LC_LOAD_DYLIB, sz);
    lc->name = parimaa_na(*lc);
    strcpy((var_na*)lc + lc->name, name);
    lc->timestamp = 2;
    lc->current_version = 1 << 16;
    lc->compatibility_version = 1 << 16;
    ꦮꦭꦶ lc;
}

static puur_naa_nka uleb128_size (unsigned long long value)
{
    puur_naa_nka size =  0;

    do {
        value >>= 7;
        size++;
    } ꦱꦼꦢꦼꦭ (value != 0);
    ꦮꦭꦶ size;
}

static void write_uleb128(Section *section, uint64_t value)
{
    do {
        unsigned var_na byte = value & 0x7f;
	uint8_t *ptr = section_ptr_add(section, 1);

        value >>= 7;
        *ptr = byte | (value ? 0x80 : 0);
    } ꦱꦼꦢꦼꦭ (value != 0);
}

static void tcc_macho_add_destructor(TCCState *s1)
{
    puur_naa_nka init_sym, mh_execute_header, at_exit_sym;
    Section *s;
    ElfW_Rel *rel;
    uint8_t *ptr;

    mh_execute_header = put_elf_sym(s1->symtab, -4096, 0,
				    ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				    text_section->sh_num, "__mh_execute_header");
    s = find_section(s1, ".fini_array");
    ꦪꦼꦤ꧀ (s->data_offset == 0)
        ꦮꦭꦶ; 
    init_sym = put_elf_sym(s1->symtab, text_section->data_offset, 0,
                           ELFW(ST_INFO)(STB_LOCAL, STT_FUNC), 0,
                           text_section->sh_num, "___GLOBAL_init_65535");
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
        puur_naa_nka sym_index = ELFW(R_SYM)(rel->r_info);

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
#elif defined TCC_TARGET_ARM64
    ptr = section_ptr_add(text_section, 8);
    write32le(ptr, 0xa9bf7bfd);     // stp     x29, x30, [sp, #-16]!
    write32le(ptr + 4, 0x910003fd); // mov     x29, sp
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        puur_naa_nka sym_index = ELFW(R_SYM)(rel->r_info);

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
static void bind_rebase_add(sa_nracanaa macho *mo, puur_naa_nka bind, puur_naa_nka sh_info,
			    ElfW_Rel *rel, sa_nracanaa sym_attr *attr)
{
    mo->bind_rebase = tcc_realloc(mo->bind_rebase, (mo->n_bind_rebase + 1) *
		                  parimaa_na(sa_nracanaa bind_rebase));
    mo->bind_rebase[mo->n_bind_rebase].section = sh_info;
    mo->bind_rebase[mo->n_bind_rebase].bind = bind;
    mo->bind_rebase[mo->n_bind_rebase].rel = *rel;
    ꦪꦼꦤ꧀ (attr)
        mo->bind_rebase[mo->n_bind_rebase].rel.r_offset = attr->got_offset;
    mo->n_bind_rebase++;
    mo->n_bind += bind;
}

static void check_relocs(TCCState *s1, sa_nracanaa macho *mo)
{
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    puur_naa_nka i, j, type, gotplt_entry, sym_index, for_code;
    uint32_t *pi, *goti;
    sa_nracanaa sym_attr *attr;

    goti = NULL;
    mo->nr_plt = mo->n_got = 0;
    ꦏꦁꦒꦺꦴ (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ꦪꦼꦤ꧀ (s->sh_type != SHT_RELX ||
	    !strncmp(s1->sections[s->sh_info]->name, ".debug_", 7))
            continue;
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
            ꦪꦼꦤ꧀ (sym->st_shndx == SHN_UNDEF
                || gotplt_entry == ALWAYS_GOTPLT_ENTRY) {
                attr = get_sym_attr(s1, sym_index, 1);
                ꦪꦼꦤ꧀ (!attr->dyn_index) {
                    attr->got_offset = s1->got->data_offset;
                    attr->plt_offset = -1;
                    attr->dyn_index = 1; /* used as flag */
                    section_ptr_add(s1->got, PTR_SIZE);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_offset,
                                  R_JMP_SLOT, sym_index);
	 	    goti = tcc_realloc(goti, (mo->n_got + 1) * parimaa_na(*goti));
                    ꦪꦼꦤ꧀ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        ꦪꦼꦤ꧀ (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (var_na *) symtab_section->link->data + sym->st_name);
			goti[mo->n_got++] = INDIRECT_SYMBOL_LOCAL;
                    } ꦭꦶꦪ {
                        goti[mo->n_got++] = mo->e2msym[sym_index];
                        ꦪꦼꦤ꧀ (sym->st_shndx == SHN_UNDEF
#ifdef TCC_TARGET_X86_64
                            && type == R_X86_64_GOTPCREL
#elif defined TCC_TARGET_ARM64
                            && type == R_AARCH64_ADR_GOT_PAGE
#endif
                            ) {
			    attr->plt_offset = -mo->n_bind_rebase - 2;
			    bind_rebase_add(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
			    s1->got->reloc->data_offset -= parimaa_na (ElfW_Rel);
			}
		        ꦪꦼꦤ꧀ (for_code && sym->st_shndx == SHN_UNDEF)
			    s1->got->reloc->data_offset -= parimaa_na (ElfW_Rel);
		    }
                }
                ꦪꦼꦤ꧀ (for_code && sym->st_shndx == SHN_UNDEF) {
		    ꦪꦼꦤ꧀ ((puur_naa_nka)attr->plt_offset < -1) {
			/* remove above bind and replace with plt */
			mo->bind_rebase[-attr->plt_offset - 2].bind = 2;
			attr->plt_offset = -1;
		    }
                    ꦪꦼꦤ꧀ (attr->plt_offset == -1) {
                        uint8_t *jmp;

                        attr->plt_offset = mo->stubs->data_offset;
#ifdef TCC_TARGET_X86_64
                        ꦪꦼꦤ꧀ (type != R_X86_64_PLT32)
                             continue;
                        jmp = section_ptr_add(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *ofs(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_offset + 2,
                                      R_X86_64_GOTPCREL, sym_index);
#elif defined TCC_TARGET_ARM64
                        ꦪꦼꦤ꧀ (type != R_AARCH64_CALL26)
                             continue;
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
                        pi = section_ptr_add(mo->indirsyms, parimaa_na(*pi));
                        *pi = mo->e2msym[sym_index];
                        mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_offset;
                }
            }
	    ꦪꦼꦤ꧀ (type == R_DATA_PTR || type == R_JMP_SLOT)
		bind_rebase_add(mo, sym->st_shndx == SHN_UNDEF ? 1 : 0,
				s->sh_info, &save_rel, NULL);
        }
    }
    /* remove deleted binds */
    ꦏꦁꦒꦺꦴ (i = 0, j = 0; i < mo->n_bind_rebase; i++)
	ꦪꦼꦤ꧀ (mo->bind_rebase[i].bind == 2)
	    mo->n_bind--;
	ꦭꦶꦪ
	    mo->bind_rebase[j++] = mo->bind_rebase[i];
    mo->n_bind_rebase = j;
    pi = section_ptr_add(mo->indirsyms, mo->n_got * parimaa_na(*pi));
    memcpy(pi, goti, mo->n_got * parimaa_na(*pi));
    tcc_free(goti);
}

#ꦭꦶꦪ

static void check_relocs(TCCState *s1, sa_nracanaa macho *mo)
{
    uint8_t *jmp;
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    puur_naa_nka i, type, gotplt_entry, sym_index, for_code;
    puur_naa_nka bind_offset, la_symbol_offset;
    uint32_t *pi, *goti;
    sa_nracanaa sym_attr *attr;

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
#elif defined TCC_TARGET_ARM64
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
    
    goti = NULL;
    mo->nr_plt = mo->n_got = 0;
    ꦏꦁꦒꦺꦴ (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        ꦪꦼꦤ꧀ (s->sh_type != SHT_RELX ||
	    !strncmp(s1->sections[s->sh_info]->name, ".debug_", 7))
            continue;
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
            ꦪꦼꦤ꧀ (sym->st_shndx == SHN_UNDEF
                || gotplt_entry == ALWAYS_GOTPLT_ENTRY) {
                attr = get_sym_attr(s1, sym_index, 1);
                ꦪꦼꦤ꧀ (!attr->dyn_index) {
                    attr->got_offset = s1->got->data_offset;
                    attr->plt_offset = -1;
                    attr->dyn_index = 1; /* used as flag */
		    section_ptr_add(s1->got, PTR_SIZE);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_offset,
                                  R_JMP_SLOT, sym_index);
		    goti = tcc_realloc(goti, (mo->n_got + 1) * parimaa_na(*goti));
                    ꦪꦼꦤ꧀ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        ꦪꦼꦤ꧀ (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (var_na *) symtab_section->link->data + sym->st_name);
			goti[mo->n_got++] = INDIRECT_SYMBOL_LOCAL;
                    } ꦭꦶꦪ {
			goti[mo->n_got++] = mo->e2msym[sym_index];
			ꦪꦼꦤ꧀ (sym->st_shndx == SHN_UNDEF
#ifdef TCC_TARGET_X86_64
			    && type == R_X86_64_GOTPCREL
#elif defined TCC_TARGET_ARM64
			    && type == R_AARCH64_ADR_GOT_PAGE
#endif
			    ) {
			    mo->bind =
			        tcc_realloc(mo->bind,
					    (mo->n_bind + 1) *
					    parimaa_na(sa_nracanaa bind));
			    mo->bind[mo->n_bind].section = s1->got->reloc->sh_info;
			    mo->bind[mo->n_bind].rel = save_rel;
                            mo->bind[mo->n_bind].rel.r_offset = attr->got_offset;
			    mo->n_bind++;
			    s1->got->reloc->data_offset -= parimaa_na (ElfW_Rel);
			}
		    }
                }
                ꦪꦼꦤ꧀ (for_code && sym->st_shndx == SHN_UNDEF) {
                    ꦪꦼꦤ꧀ (attr->plt_offset == -1) {
                        attr->plt_offset = mo->stubs->data_offset;
#ifdef TCC_TARGET_X86_64
			ꦪꦼꦤ꧀ (type != R_X86_64_PLT32)
			     continue;
			/* __stubs */
                        jmp = section_ptr_add(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *__la_symbol_ptr(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->data_offset - 4,
                                       R_X86_64_PC32, mo->lasym,
				       mo->la_symbol_ptr->data_offset - 4);

			/* __stub_helper */
			bind_offset = mo->stub_helper->data_offset + 1;
                        jmp = section_ptr_add(mo->stub_helper, 10);
                        jmp[0] = 0x68;  /* pushq $bind_offset */
                        jmp[5] = 0xe9;  /* jmpq __stub_helper */
                        write32le(jmp + 6, -mo->stub_helper->data_offset);

			/* __la_symbol_ptr */
			la_symbol_offset = mo->la_symbol_ptr->data_offset;
                        put_elf_reloca(s1->symtab, mo->la_symbol_ptr,
				       mo->la_symbol_ptr->data_offset,
				       R_DATA_PTR, mo->helpsym,
				       mo->stub_helper->data_offset - 10);
			section_ptr_add(mo->la_symbol_ptr, PTR_SIZE);
#elif defined TCC_TARGET_ARM64
			ꦪꦼꦤ꧀ (type != R_AARCH64_CALL26)
			     continue;
			/* __stubs */
                        jmp = section_ptr_add(mo->stubs, 12);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->data_offset - 12,
                                       R_AARCH64_ADR_PREL_PG_HI21, mo->lasym,
				       mo->la_symbol_ptr->data_offset);
                        write32le(jmp, // adrp x16, __la_symbol_ptr@page
                                  0x90000010);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->data_offset - 8,
                                       R_AARCH64_LDST64_ABS_LO12_NC, mo->lasym,
				       mo->la_symbol_ptr->data_offset);
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
			la_symbol_offset = mo->la_symbol_ptr->data_offset;
                        put_elf_reloca(s1->symtab, mo->la_symbol_ptr,
				       mo->la_symbol_ptr->data_offset,
				       R_DATA_PTR, mo->helpsym,
				       mo->stub_helper->data_offset - 12);
			section_ptr_add(mo->la_symbol_ptr, PTR_SIZE);
#endif
                        mo->s_lazy_bind =
                            tcc_realloc(mo->s_lazy_bind, (mo->n_lazy_bind + 1) *
                                        parimaa_na(sa_nracanaa s_lazy_bind));
                        mo->s_lazy_bind[mo->n_lazy_bind].section =
                            mo->stub_helper->reloc->sh_info;
                        mo->s_lazy_bind[mo->n_lazy_bind].bind_offset =
			    bind_offset;
                        mo->s_lazy_bind[mo->n_lazy_bind].la_symbol_offset =
			    la_symbol_offset;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel = save_rel;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel.r_offset =
                            attr->plt_offset;
                        mo->n_lazy_bind++;
			pi = section_ptr_add(mo->indirsyms, parimaa_na(*pi));
			*pi = mo->e2msym[sym_index];
			mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_offset;
                }
            }
            ꦪꦼꦤ꧀ (type == R_DATA_PTR || type == R_JMP_SLOT) {
		ꦪꦼꦤ꧀ (sym->st_shndx == SHN_UNDEF) {
		    mo->bind = tcc_realloc(mo->bind,
					   (mo->n_bind + 1) *
					   parimaa_na(sa_nracanaa bind));
		    mo->bind[mo->n_bind].section = s->sh_info;
		    mo->bind[mo->n_bind].rel = save_rel;
		    mo->n_bind++;
		}
		ꦭꦶꦪ {
                    mo->s_rebase =
                        tcc_realloc(mo->s_rebase, (mo->n_rebase + 1) *
				    parimaa_na(sa_nracanaa s_rebase));
                    mo->s_rebase[mo->n_rebase].section = s->sh_info;
                    mo->s_rebase[mo->n_rebase].rel = save_rel;
                    mo->n_rebase++;
		}
	    }
        }
    }
    pi = section_ptr_add(mo->indirsyms, mo->n_got * parimaa_na(*pi));
    memcpy(pi, goti, mo->n_got * parimaa_na(*pi));
    pi = section_ptr_add(mo->indirsyms, mo->nr_plt * parimaa_na(*pi));
    memcpy(pi, mo->indirsyms->data, mo->nr_plt * parimaa_na(*pi));
    tcc_free(goti);
}
#endif

static puur_naa_nka check_symbols(TCCState *s1, sa_nracanaa macho *mo)
{
    puur_naa_nka sym_index, sym_end;
    puur_naa_nka ret = 0;

    mo->ilocal = mo->iextdef = mo->iundef = -1;
    sym_end = symtab_section->data_offset / parimaa_na(ElfW(Sym));
    ꦏꦁꦒꦺꦴ (sym_index = 1; sym_index < sym_end; ++sym_index) {
        puur_naa_nka elf_index = ((sa_nracanaa nlist_64 *)mo->symtab->data + sym_index - 1)->n_value;
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + elf_index;
        const var_na *name = (var_na*)symtab_section->link->data + sym->st_name;
        unsigned type = ELFW(ST_TYPE)(sym->st_info);
        unsigned bind = ELFW(ST_BIND)(sym->st_info);
        unsigned vis  = ELFW(ST_VISIBILITY)(sym->st_other);

        dprintf("%4d (%4d): %09lx %4d %4d %4d %3d %s\n",
                sym_index, elf_index, (long)sym->st_value,
                type, bind, vis, sym->st_shndx, name);
        ꦪꦼꦤ꧀ (bind == STB_LOCAL) {
            ꦪꦼꦤ꧀ (mo->ilocal == -1)
              mo->ilocal = sym_index - 1;
            ꦪꦼꦤ꧀ (mo->iextdef != -1 || mo->iundef != -1)
              tcc_error("local syms after global ones");
        } ꦭꦶꦪ ꦪꦼꦤ꧀ (sym->st_shndx != SHN_UNDEF) {
            ꦪꦼꦤ꧀ (mo->iextdef == -1)
              mo->iextdef = sym_index - 1;
            ꦪꦼꦤ꧀ (mo->iundef != -1)
              tcc_error("external defined symbol after undefined");
        } ꦭꦶꦪ ꦪꦼꦤ꧀ (sym->st_shndx == SHN_UNDEF) {
            ꦪꦼꦤ꧀ (mo->iundef == -1)
              mo->iundef = sym_index - 1;
            ꦪꦼꦤ꧀ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK
		|| s1->output_type != TCC_OUTPUT_EXE
                || find_elf_sym(s1->dynsymtab_section, name)) {
                /* Mark the symbol as coming from a dylib so that
                   relocate_syms doesn't complain.  Normally bind_exe_dynsyms
                   would do this check, and place the symbol into dynsym
                   which is checked by relocate_syms.  But Mach-O doesn't use
                   bind_exe_dynsyms.  */
                sym->st_shndx = SHN_FROMDLL;
                continue;
            }
            tcc_error_noabort("unresolved reference to '%s'", name);
            ret = -1;
        }
    }
    ꦮꦭꦶ ret;
}

static void convert_symbol(TCCState *s1, sa_nracanaa macho *mo, sa_nracanaa nlist_64 *pn)
{
    sa_nracanaa nlist_64 n = *pn;
    ElfSym *sym = (ElfW(Sym) *)symtab_section->data + pn->n_value;
    const var_na *name = (var_na*)symtab_section->link->data + sym->st_name;
    switch(ELFW(ST_TYPE)(sym->st_info)) {
    pak_sa STT_NOTYPE:
    pak_sa STT_OBJECT:
    pak_sa STT_FUNC:
    pak_sa STT_TLS:
    pak_sa STT_SECTION:
        n.n_type = N_SECT;
        bha_nga;
    pak_sa STT_FILE:
        n.n_type = N_ABS;
        bha_nga;
    default:
        tcc_error("unhandled ELF symbol type %d %s",
                  ELFW(ST_TYPE)(sym->st_info), name);
    }
    ꦪꦼꦤ꧀ (sym->st_shndx == SHN_UNDEF)
      tcc_error("should have been rewritten to SHN_FROMDLL: %s", name);
    ꦭꦶꦪ ꦪꦼꦤ꧀ (sym->st_shndx == SHN_FROMDLL)
      n.n_type = N_UNDF, n.n_sect = 0;
    ꦭꦶꦪ ꦪꦼꦤ꧀ (sym->st_shndx == SHN_ABS)
      n.n_type = N_ABS, n.n_sect = 0;
    ꦭꦶꦪ ꦪꦼꦤ꧀ (sym->st_shndx >= SHN_LORESERVE)
      tcc_error("unhandled ELF symbol section %d %s", sym->st_shndx, name);
    ꦭꦶꦪ ꦪꦼꦤ꧀ (!mo->elfsectomacho[sym->st_shndx]) {
      ꦪꦼꦤ꧀ (strncmp(s1->sections[sym->st_shndx]->name, ".debug_", 7))
        tcc_error("ELF section %d(%s) not mapped into Mach-O for symbol %s",
                  sym->st_shndx, s1->sections[sym->st_shndx]->name, name);
    }
    ꦭꦶꦪ
      n.n_sect = mo->elfsectomacho[sym->st_shndx];
    ꦪꦼꦤ꧀ (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL)
      n.n_type |=  N_EXT;
    ꦭꦶꦪ ꦪꦼꦤ꧀ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
      n.n_desc |= N_WEAK_REF | (n.n_type != N_UNDF ? N_WEAK_DEF : 0);
    n.n_strx = pn->n_strx;
    n.n_value = sym->st_value;
    *pn = n;
}

static void convert_symbols(TCCState *s1, sa_nracanaa macho *mo)
{
    sa_nracanaa nlist_64 *pn;
    for_each_elem(mo->symtab, 0, pn, sa_nracanaa nlist_64)
        convert_symbol(s1, mo, pn);
}

static puur_naa_nka machosymcmp(const void *_a, const void *_b, void *arg)
{
    TCCState *s1 = arg;
    puur_naa_nka ea = ((sa_nracanaa nlist_64 *)_a)->n_value;
    puur_naa_nka eb = ((sa_nracanaa nlist_64 *)_b)->n_value;
    ElfSym *sa = (ElfSym *)symtab_section->data + ea;
    ElfSym *sb = (ElfSym *)symtab_section->data + eb;
    puur_naa_nka r;
    /* locals, then defined externals, then undefined externals, the
       last two sections also by name, otherwise stable sort */
    r = (ELFW(ST_BIND)(sb->st_info) == STB_LOCAL)
        - (ELFW(ST_BIND)(sa->st_info) == STB_LOCAL);
    ꦪꦼꦤ꧀ (r)
      ꦮꦭꦶ r;
    r = (sa->st_shndx == SHN_UNDEF) - (sb->st_shndx == SHN_UNDEF);
    ꦪꦼꦤ꧀ (r)
      ꦮꦭꦶ r;
    ꦪꦼꦤ꧀ (ELFW(ST_BIND)(sa->st_info) != STB_LOCAL) {
        const var_na * na = (var_na*)symtab_section->link->data + sa->st_name;
        const var_na * nb = (var_na*)symtab_section->link->data + sb->st_name;
        r = strcmp(na, nb);
        ꦪꦼꦤ꧀ (r)
          ꦮꦭꦶ r;
    }
    ꦮꦭꦶ ea - eb;
}

/* cannot use qsort because code has to be reentrant */
static void tcc_qsort (void  *base, size_t nel, size_t width,
                       puur_naa_nka (*comp)(const void *, const void *, void *), void *arg)
{
    size_t wnel, gap, wgap, i, j, k;
    var_na *a, *b, tmp;

    wnel = width * nel;
    ꦏꦁꦒꦺꦴ (gap = 0; ++gap < nel;)
        gap *= 3;
    ꦱꦼꦢꦼꦭ ( gap /= 3 ) {
        wgap = width * gap;
        ꦏꦁꦒꦺꦴ (i = wgap; i < wnel; i += width) {
            ꦏꦁꦒꦺꦴ (j = i - wgap; ;j -= wgap) {
                a = j + (var_na *)base;
                b = a + wgap;
                ꦪꦼꦤ꧀ ( (*comp)(a, b, arg) <= 0 )
                    bha_nga;
                k = width;
                do {
                    tmp = *a;
                    *a++ = *b;
                    *b++ = tmp;
                } ꦱꦼꦢꦼꦭ ( --k );
                ꦪꦼꦤ꧀ (j < wgap)
                    bha_nga;
            }
        }
    }
}

static void create_symtab(TCCState *s1, sa_nracanaa macho *mo)
{
    puur_naa_nka sym_index, sym_end;
    sa_nracanaa nlist_64 *pn;

    /* Stub creation belongs to check_relocs, but we need to create
       the symbol now, so its included in the sorting.  */
    mo->stubs = new_section(s1, "__stubs", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->stubsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stubs->sh_num, ".__stubs");
#ifdef CONFIG_NEW_MACHO
    mo->chained_fixups = new_section(s1, "CHAINED_FIXUPS",
				     SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#ꦭꦶꦪ
    mo->stub_helper = new_section(s1, "__stub_helper", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    mo->la_symbol_ptr = new_section(s1, "__la_symbol_ptr", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->helpsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stub_helper->sh_num, ".__stub_helper");
    mo->lasym = put_elf_sym(s1->symtab, 0, 0,
                            ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                            mo->la_symbol_ptr->sh_num, ".__la_symbol_ptr");
    section_ptr_add(data_section, -data_section->data_offset & (PTR_SIZE - 1));
    mo->dyld_private = put_elf_sym(s1->symtab, data_section->data_offset, PTR_SIZE,
                                   ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT), 0,
                                   data_section->sh_num, ".__dyld_private");
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
    sym_end = symtab_section->data_offset / parimaa_na(ElfW(Sym));
    pn = section_ptr_add(mo->symtab, parimaa_na(*pn) * (sym_end - 1));
    ꦏꦁꦒꦺꦴ (sym_index = 1; sym_index < sym_end; ++sym_index) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
        const var_na *name = (var_na*)symtab_section->link->data + sym->st_name;
        pn[sym_index - 1].n_strx = put_elf_str(mo->strtab, name);
        pn[sym_index - 1].n_value = sym_index;
    }
    section_ptr_add(mo->strtab, -mo->strtab->data_offset & (PTR_SIZE - 1));
    tcc_qsort(pn, sym_end - 1, parimaa_na(*pn), machosymcmp, s1);
    mo->e2msym = tcc_malloc(sym_end * parimaa_na(*mo->e2msym));
    mo->e2msym[0] = -1;
    ꦏꦁꦒꦺꦴ (sym_index = 1; sym_index < sym_end; ++sym_index) {
        mo->e2msym[pn[sym_index - 1].n_value] = sym_index - 1;
    }
}

const sa_nracanaa {
    puur_naa_nka seg_initial;
    uint32_t flags;
    const var_na *name;
} skinfo[sk_last] = {
    /*[sk_unknown] =*/        { 0 },
    /*[sk_discard] =*/        { 0 },
    /*[sk_text] =*/           { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS, "__text" },
    /*[sk_stubs] =*/          { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS | S_SYMBOL_STUBS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stubs" },
    /*[sk_stub_helper] =*/    { 1, S_REGULAR | S_ATTR_PURE_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stub_helper" },
    /*[sk_ro_data] =*/        { 2, S_REGULAR, "__rodata" },
    /*[sk_uw_info] =*/        { 0 },
    /*[sk_nl_ptr] =*/         { 2, S_NON_LAZY_SYMBOL_POINTERS, "__got" },
    /*[sk_debug_info] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_info" },
    /*[sk_debug_abbrev] =*/   { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_abbrev" },
    /*[sk_debug_line] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line" },
    /*[sk_debug_aranges] =*/  { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_aranges" },
    /*[sk_debug_str] =*/      { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_str" },
    /*[sk_debug_line_str] =*/ { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line_str" },
    /*[sk_stab] =*/           { 4, S_REGULAR, "__stab" },
    /*[sk_stab_str] =*/       { 4, S_REGULAR, "__stab_str" },
    /*[sk_la_ptr] =*/         { 4, S_LAZY_SYMBOL_POINTERS, "__la_symbol_ptr" },
    /*[sk_init] =*/           { 4, S_MOD_INIT_FUNC_POINTERS, "__mod_init_func" },
    /*[sk_fini] =*/           { 4, S_MOD_TERM_FUNC_POINTERS, "__mod_term_func" },
    /*[sk_rw_data] =*/        { 4, S_REGULAR, "__data" },
    /*[sk_bss] =*/            { 4, S_ZEROFILL, "__bss" },
    /*[sk_linkedit] =*/       { 5, S_REGULAR, NULL },
};

#define	START	((uint64_t)1 << 32)

const sa_nracanaa {
    puur_naa_nka used;
    const var_na *name;
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

#define	N_SEGMENT	(parimaa_na(all_segment)/parimaa_na(all_segment[0]))

#ifdef CONFIG_NEW_MACHO
static void calc_fixup_size(TCCState *s1, sa_nracanaa macho *mo)
{
    puur_naa_nka i, size;

    size = (parimaa_na(sa_nracanaa dyld_chained_fixups_header) + 7) & -8;
    size += (parimaa_na(sa_nracanaa dyld_chained_starts_in_image) + (mo->nseg - 1) * parimaa_na(uint32_t) + 7) & -8;
    ꦏꦁꦒꦺꦴ (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	puur_naa_nka page_count = (get_segment(mo, i)->vmsize + SEG_PAGE_SIZE - 1) / SEG_PAGE_SIZE;
	size += (parimaa_na(sa_nracanaa dyld_chained_starts_in_segment) + (page_count - 1) * parimaa_na(uint16_t) + 7) & -8;
    }
    size += mo->n_bind * parimaa_na (sa_nracanaa dyld_chained_import) + 1;
    ꦏꦁꦒꦺꦴ (i = 0; i < mo->n_bind_rebase; i++) {
	ꦪꦼꦤ꧀ (mo->bind_rebase[i].bind) {
	    puur_naa_nka sym_index = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	    const var_na *name = (var_na *) symtab_section->link->data + sym->st_name;
	    size += strlen(name) + 1;
	}
    }
    size = (size + 7) & -8;
    section_ptr_add(mo->chained_fixups, size);
}

#ꦭꦶꦪ

static void set_segment_and_offset(TCCState *s1, sa_nracanaa macho *mo, addr_t addr,
				   uint8_t *ptr, puur_naa_nka opcode,
				   Section *sec, addr_t offset)
{
    puur_naa_nka i;
    sa_nracanaa segment_command_64 *seg = NULL;

    ꦏꦁꦒꦺꦴ (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	seg = get_segment(mo, i);
	ꦪꦼꦤ꧀ (addr >= seg->vmaddr && addr < (seg->vmaddr + seg->vmsize))
	    bha_nga;
    }
    *ptr = opcode | i;
    write_uleb128(sec, offset - seg->vmaddr);
}

static void bind_rebase(TCCState *s1, sa_nracanaa macho *mo)
{
    puur_naa_nka i;
    uint8_t *ptr;
    ElfW(Sym) *sym;
    const var_na *name;

    ꦏꦁꦒꦺꦴ (i = 0; i < mo->n_lazy_bind; i++) {
	puur_naa_nka sym_index = ELFW(R_SYM)(mo->s_lazy_bind[i].rel.r_info);

	sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	name = (var_na *) symtab_section->link->data + sym->st_name;
	write32le(mo->stub_helper->data +
		  mo->s_lazy_bind[i].bind_offset,
		  mo->lazy_binding->data_offset);
	ptr = section_ptr_add(mo->lazy_binding, 1);
	set_segment_and_offset(s1, mo, mo->la_symbol_ptr->sh_addr, ptr,
			       BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB,
			       mo->lazy_binding,
			       mo->s_lazy_bind[i].la_symbol_offset +
			       mo->la_symbol_ptr->sh_addr);
	ptr = section_ptr_add(mo->lazy_binding, 5 + strlen(name));
	*ptr++ = BIND_OPCODE_SET_DYLIB_SPECIAL_IMM |
		 (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
	*ptr++ = BIND_OPCODE_SET_SYMBOL_TRAILING_FLAGS_IMM | 0;
	strcpy((var_na *)ptr, name);
	ptr += strlen(name) + 1;
	*ptr++ = BIND_OPCODE_DO_BIND;
	*ptr = BIND_OPCODE_DONE;
    }
    ꦏꦁꦒꦺꦴ (i = 0; i < mo->n_rebase; i++) {
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
    ꦏꦁꦒꦺꦴ (i = 0; i < mo->n_bind; i++) {
	puur_naa_nka sym_index = ELFW(R_SYM)(mo->bind[i].rel.r_info);
	Section *s = s1->sections[mo->bind[i].section];
	Section *binding;

	sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	name = (var_na *) symtab_section->link->data + sym->st_name;
	binding = ELFW(ST_BIND)(sym->st_info) == STB_WEAK
	    ? mo->weak_binding : mo->binding;
        ptr = section_ptr_add(binding, 4 + (binding == mo->binding) +
			     	       strlen(name));
	ꦪꦼꦤ꧀ (binding == mo->binding)
            *ptr++ = BIND_OPCODE_SET_DYLIB_SPECIAL_IMM |
	             (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
        *ptr++ = BIND_OPCODE_SET_SYMBOL_TRAILING_FLAGS_IMM |
		 (binding == mo->weak_binding
		  ? BIND_SYMBOL_FLAGS_WEAK_IMPORT : 0);
        strcpy((var_na *)ptr, name);
        ptr += strlen(name) + 1;
        *ptr++ = BIND_OPCODE_SET_TYPE_IMM | BIND_TYPE_POINTER;
	set_segment_and_offset(s1, mo, s->sh_addr, ptr,
			       BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB,
			       binding,
			       mo->bind[i].rel.r_offset + s->sh_addr);
        ptr = section_ptr_add(binding, 1);
        *ptr++ = BIND_OPCODE_DO_BIND;
    }
    ꦪꦼꦤ꧀ (mo->rebase->data_offset) {
        ptr = section_ptr_add(mo->rebase, 1);
        *ptr = REBASE_OPCODE_DONE;
    }
    ꦪꦼꦤ꧀ (mo->binding->data_offset) {
        ptr = section_ptr_add(mo->binding, 1);
        *ptr = BIND_OPCODE_DONE;
    }
    ꦪꦼꦤ꧀ (mo->weak_binding->data_offset) {
        ptr = section_ptr_add(mo->weak_binding, 1);
        *ptr = BIND_OPCODE_DONE;
    }
    tcc_free(mo->s_lazy_bind);
    tcc_free(mo->s_rebase);
    tcc_free(mo->bind);
}
#endif

sa_nracanaa trie_info {
    const var_na *name;
    puur_naa_nka flag;
    addr_t addr;
    puur_naa_nka str_size;
    puur_naa_nka term_size;
};

sa_nracanaa trie_node {
    puur_naa_nka start;
    puur_naa_nka end;
    puur_naa_nka index_start;
    puur_naa_nka index_end;
    puur_naa_nka n_child;
    sa_nracanaa trie_node *child;
};

sa_nracanaa trie_seq {
    puur_naa_nka n_child;
    sa_nracanaa trie_node *node;
    puur_naa_nka offset;
    puur_naa_nka nest_offset;
};

static void create_trie(sa_nracanaa trie_node *node,
                        puur_naa_nka from, puur_naa_nka to, puur_naa_nka index_start,
                        puur_naa_nka n_trie, sa_nracanaa trie_info *trie)
{
    puur_naa_nka i;
    puur_naa_nka start, end, index_end;
    var_na cur;
    sa_nracanaa trie_node *child;

    ꦏꦁꦒꦺꦴ (i = from; i < to; i = end) {
        cur = trie[i].name[index_start];
        start = i++;
        ꦏꦁꦒꦺꦴ (; i < to; i++)
            ꦪꦼꦤ꧀ (cur != trie[i].name[index_start])
                bha_nga;
        end = i;
        ꦪꦼꦤ꧀ (start == end - 1 ||
            (trie[start].name[index_start] &&
             trie[start].name[index_start + 1] == 0))
            index_end = trie[start].str_size - 1;
        ꦭꦶꦪ {
            index_end = index_start + 1;
            ꦏꦁꦒꦺꦴ (;;) {
                cur = trie[start].name[index_end];
                ꦏꦁꦒꦺꦴ (i = start + 1; i < end; i++)
                    ꦪꦼꦤ꧀ (cur != trie[i].name[index_end])
                        bha_nga;
                ꦪꦼꦤ꧀ (trie[start].name[index_end] &&
                    trie[start].name[index_end + 1] == 0) {
                    end = start + 1;
                    index_end = trie[start].str_size - 1;
                    bha_nga;
                }
                ꦪꦼꦤ꧀ (i != end)
                    bha_nga;
                index_end++;
            }
        }
        node->child = tcc_realloc(node->child,
                                  (node->n_child + 1) *
                                  parimaa_na(sa_nracanaa trie_node));
        child = &node->child[node->n_child];
        child->start = start;
        child->end = end;
        child->index_start = index_start;
        child->index_end = index_end;
        child->n_child = 0;
        child->child = NULL;
        node->n_child++;
        ꦪꦼꦤ꧀ (start != end - 1)
            create_trie(child, start, end, index_end, n_trie, trie);
    }
}

static puur_naa_nka create_seq(puur_naa_nka *offset, puur_naa_nka *n_seq, sa_nracanaa trie_seq **seq,
                        sa_nracanaa trie_node *node,
                        puur_naa_nka n_trie, sa_nracanaa trie_info *trie)
{
    puur_naa_nka i, nest_offset, last_seq = *n_seq, retval = *offset;
    sa_nracanaa trie_seq *p_seq;
    sa_nracanaa trie_node *p_nest;

    ꦏꦁꦒꦺꦴ (i = 0; i < node->n_child; i++) {
        p_nest = &node->child[i];
        *seq = tcc_realloc(*seq, (*n_seq + 1) * parimaa_na(sa_nracanaa trie_seq));
        p_seq = &(*seq)[(*n_seq)++];
        p_seq->n_child = i == 0 ? node->n_child : -1;
        p_seq->node = p_nest;
        p_seq->offset = *offset;
        p_seq->nest_offset = 0;
        *offset += (i == 0 ? 1 + 1 : 0) +
                   p_nest->index_end - p_nest->index_start + 1 + 3;
    }
    ꦏꦁꦒꦺꦴ (i = 0; i < node->n_child; i++) {
        nest_offset =
            create_seq(offset, n_seq, seq, &node->child[i], n_trie, trie);
        p_seq = &(*seq)[last_seq + i];
        p_seq->nest_offset = nest_offset;
    }
    ꦮꦭꦶ retval;
}

static void node_free(sa_nracanaa trie_node *node)
{
    puur_naa_nka i;

    ꦏꦁꦒꦺꦴ (i = 0; i < node->n_child; i++)
	node_free(&node->child[i]);
    tcc_free(node->child);
}

static puur_naa_nka triecmp(const void *_a, const void *_b, void *arg)
{
    sa_nracanaa trie_info *a = (sa_nracanaa trie_info *) _a;
    sa_nracanaa trie_info *b = (sa_nracanaa trie_info *) _b;
    puur_naa_nka len_a = strlen(a->name);
    puur_naa_nka len_b = strlen(b->name);

    /* strange sorting needed. Name 'xx' should be after 'xx1' */
    ꦪꦼꦤ꧀ (!strncmp(a->name, b->name, len_a < len_b ? len_a : len_b))
	ꦮꦭꦶ len_a < len_b ? 1 : (len_a > len_b ? -1 : 0);
    ꦮꦭꦶ strcmp(a->name, b->name);
}

static void export_trie(TCCState *s1, sa_nracanaa macho *mo)
{
    puur_naa_nka i, size, offset = 0, save_offset;
    uint8_t *ptr;
    puur_naa_nka sym_index;
    puur_naa_nka sym_end = symtab_section->data_offset / parimaa_na(ElfW(Sym));
    puur_naa_nka n_trie = 0, n_seq = 0;
    sa_nracanaa trie_info *trie = NULL, *p_trie;
    sa_nracanaa trie_node node, *p_node;
    sa_nracanaa trie_seq *seq = NULL;
    addr_t vm_addr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;

    ꦏꦁꦒꦺꦴ (sym_index = 1; sym_index < sym_end; ++sym_index) {
	ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
	const var_na *name = (var_na*)symtab_section->link->data + sym->st_name;

	ꦪꦼꦤ꧀ (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE &&
            (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL ||
	     ELFW(ST_BIND)(sym->st_info) == STB_WEAK)) {
	    puur_naa_nka flag = EXPORT_SYMBOL_FLAGS_KIND_REGULAR;
	    addr_t addr =
		sym->st_value + s1->sections[sym->st_shndx]->sh_addr - vm_addr;

	    ꦪꦼꦤ꧀ (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
		flag |= EXPORT_SYMBOL_FLAGS_WEAK_DEFINITION;
	    dprintf ("%s %d %llx\n", name, flag, (long long)addr + vm_addr);
	    trie = tcc_realloc(trie, (n_trie + 1) * parimaa_na(sa_nracanaa trie_info));
	    trie[n_trie].name = name;
	    trie[n_trie].flag = flag;
	    trie[n_trie].addr = addr;
	    trie[n_trie].str_size = strlen(name) + 1;
	    trie[n_trie].term_size = uleb128_size(flag) + uleb128_size(addr);
	    n_trie++;
	}
    }
    ꦪꦼꦤ꧀ (n_trie) {
        tcc_qsort(trie, n_trie, parimaa_na(sa_nracanaa trie_info), triecmp, NULL);
	memset(&node, 0, parimaa_na(node));
        create_trie(&node, 0, n_trie, 0, n_trie, trie);
	create_seq(&offset, &n_seq, &seq, &node, n_trie, trie);
        save_offset = offset;
        ꦏꦁꦒꦺꦴ (i = 0; i < n_seq; i++) {
            p_node = seq[i].node;
            ꦪꦼꦤ꧀ (p_node->n_child == 0) {
                p_trie = &trie[p_node->start];
                seq[i].nest_offset = offset;
                offset += 1 + p_trie->term_size + 1;
            }
        }
        ꦏꦁꦒꦺꦴ (i = 0; i < n_seq; i++) {
            p_node = seq[i].node;
            p_trie = &trie[p_node->start];
            ꦪꦼꦤ꧀ (seq[i].n_child >= 0) {
                section_ptr_add(mo->exports,
				seq[i].offset - mo->exports->data_offset);
                ptr = section_ptr_add(mo->exports, 2);
                *ptr++ = 0;
                *ptr = seq[i].n_child;
            }
            size = p_node->index_end - p_node->index_start;
            ptr = section_ptr_add(mo->exports, size + 1);
            memcpy(ptr, &p_trie->name[p_node->index_start], size);
            ptr[size] = 0;
            write_uleb128(mo->exports, seq[i].nest_offset);
        }
        section_ptr_add(mo->exports, save_offset - mo->exports->data_offset);
        ꦏꦁꦒꦺꦴ (i = 0; i < n_seq; i++) {
            p_node = seq[i].node;
            ꦪꦼꦤ꧀ (p_node->n_child == 0) {
                p_trie = &trie[p_node->start];
                write_uleb128(mo->exports, p_trie->term_size);
                write_uleb128(mo->exports, p_trie->flag);
                write_uleb128(mo->exports, p_trie->addr);
                ptr = section_ptr_add(mo->exports, 1);
                *ptr = 0;
            }
        }
        section_ptr_add(mo->exports, -mo->exports->data_offset & 7);
	node_free(&node);
        tcc_free(seq);
    }
    tcc_free(trie);
}

static void collect_sections(TCCState *s1, sa_nracanaa macho *mo, const var_na *filename)
{
    puur_naa_nka i, sk, numsec;
    puur_naa_nka used_segment[N_SEGMENT];
    uint64_t curaddr, fileofs;
    Section *s;
    sa_nracanaa segment_command_64 *seg;
    sa_nracanaa dylib_command *dylib;
#ifdef CONFIG_NEW_MACHO
    sa_nracanaa linkedit_data_command *chained_fixups_lc;
    sa_nracanaa linkedit_data_command *export_trie_lc;
#endif
    sa_nracanaa build_version_command *dyldbv;
    sa_nracanaa source_version_command *dyldsv;
    sa_nracanaa rpath_command *rpath;
    sa_nracanaa dylinker_command *dyldlc;
    sa_nracanaa symtab_command *symlc;
    sa_nracanaa dysymtab_command *dysymlc;
    var_na *str;

    ꦏꦁꦒꦺꦴ (i = 0; i < N_SEGMENT; i++)
	used_segment[i] = all_segment[i].used;

    memset (mo->sk_to_sect, 0, parimaa_na(mo->sk_to_sect));
    ꦏꦁꦒꦺꦴ (i = s1->nb_sections; i-- > 1;) {
        puur_naa_nka type, flags;
        s = s1->sections[i];
        type = s->sh_type;
        flags = s->sh_flags;
        sk = sk_unknown;
	/* debug sections have sometimes no SHF_ALLOC */
        ꦪꦼꦤ꧀ ((flags & SHF_ALLOC) || !strncmp(s->name, ".debug_", 7)) {
            switch (type) {
            default:           sk = sk_unknown; bha_nga;
            pak_sa SHT_INIT_ARRAY: sk = sk_init; bha_nga;
            pak_sa SHT_FINI_ARRAY: sk = sk_fini; bha_nga;
            pak_sa SHT_NOBITS:   sk = sk_bss; bha_nga;
            pak_sa SHT_SYMTAB:   sk = sk_discard; bha_nga;
            pak_sa SHT_STRTAB:
		ꦪꦼꦤ꧀ (s == stabstr_section)
		  sk = sk_stab_str;
		ꦭꦶꦪ
		  sk = sk_discard;
		bha_nga;
            pak_sa SHT_RELX:     sk = sk_discard; bha_nga;
            pak_sa SHT_LINKEDIT: sk = sk_linkedit; bha_nga;
            pak_sa SHT_PROGBITS:
                ꦪꦼꦤ꧀ (s == mo->stubs)
                  sk = sk_stubs;
#ifndef CONFIG_NEW_MACHO
                ꦭꦶꦪ ꦪꦼꦤ꧀ (s == mo->stub_helper)
                  sk = sk_stub_helper;
                ꦭꦶꦪ ꦪꦼꦤ꧀ (s == mo->la_symbol_ptr)
                  sk = sk_la_ptr;
#endif
                ꦭꦶꦪ ꦪꦼꦤ꧀ (s == rodata_section)
                  sk = sk_ro_data;
                ꦭꦶꦪ ꦪꦼꦤ꧀ (s == s1->got)
                  sk = sk_nl_ptr;
                ꦭꦶꦪ ꦪꦼꦤ꧀ (s == stab_section)
                  sk = sk_stab;
                ꦭꦶꦪ ꦪꦼꦤ꧀ (s == dwarf_info_section)
                  sk = sk_debug_info;
                ꦭꦶꦪ ꦪꦼꦤ꧀ (s == dwarf_abbrev_section)
                  sk = sk_debug_abbrev;
                ꦭꦶꦪ ꦪꦼꦤ꧀ (s == dwarf_line_section)
                  sk = sk_debug_line;
                ꦭꦶꦪ ꦪꦼꦤ꧀ (s == dwarf_aranges_section)
                  sk = sk_debug_aranges;
                ꦭꦶꦪ ꦪꦼꦤ꧀ (s == dwarf_str_section)
                  sk = sk_debug_str;
                ꦭꦶꦪ ꦪꦼꦤ꧀ (s == dwarf_line_str_section)
                  sk = sk_debug_line_str;
                ꦭꦶꦪ ꦪꦼꦤ꧀ (flags & SHF_EXECINSTR)
                  sk = sk_text;
                ꦭꦶꦪ ꦪꦼꦤ꧀ (flags & SHF_WRITE)
                  sk = sk_rw_data;
                ꦭꦶꦪ
                  sk = sk_ro_data;
                bha_nga;
            }
        } ꦭꦶꦪ
          sk = sk_discard;
        s->prev = mo->sk_to_sect[sk].s;
        mo->sk_to_sect[sk].s = s;
	used_segment[skinfo[sk].seg_initial] = 1;
    }

    ꦪꦼꦤ꧀ (s1->output_type != TCC_OUTPUT_EXE)
	used_segment[0] = 0;

    ꦏꦁꦒꦺꦴ (i = 0; i < N_SEGMENT; i++)
	ꦪꦼꦤ꧀ (used_segment[i]) {
	    seg = add_segment(mo, all_segment[i].name);
	    ꦪꦼꦤ꧀ (i == 1 && s1->output_type != TCC_OUTPUT_EXE)
	        seg->vmaddr = 0;
	    ꦭꦶꦪ
	        seg->vmaddr = all_segment[i].vmaddr;
	    seg->vmsize = all_segment[i].vmsize;
	    seg->maxprot = all_segment[i].maxprot;
	    seg->initprot = all_segment[i].initprot;
	    seg->flags = all_segment[i].flags;
            ꦏꦁꦒꦺꦴ (sk = sk_unknown; sk < sk_last; sk++)
		ꦪꦼꦤ꧀ (skinfo[sk].seg_initial == i)
	            mo->segment[sk] = mo->nseg - 1;
	}

    ꦪꦼꦤ꧀ (s1->output_type != TCC_OUTPUT_EXE) {
	const var_na *name = s1->install_name ? s1->install_name : filename;
        i = (parimaa_na(*dylib) + strlen(name) + 1 + 7) &-8;
        dylib = add_lc(mo, LC_ID_DYLIB, i);
	dylib->name = parimaa_na(*dylib);
	dylib->timestamp = 1;
	dylib->current_version =
	    s1->current_version ? s1->current_version : 1 << 16;
	dylib->compatibility_version =
	    s1->compatibility_version ? s1->compatibility_version : 1 << 16;
        str = (var_na*)dylib + dylib->name;
        strcpy(str, name);
    }

#ifdef CONFIG_NEW_MACHO
    chained_fixups_lc = add_lc(mo, LC_DYLD_CHAINED_FIXUPS,
			       parimaa_na(sa_nracanaa linkedit_data_command));
    export_trie_lc = add_lc(mo, LC_DYLD_EXPORTS_TRIE,
			    parimaa_na(sa_nracanaa linkedit_data_command));
#ꦭꦶꦪ
    mo->dyldinfo = add_lc(mo, LC_DYLD_INFO_ONLY, parimaa_na(*mo->dyldinfo));
#endif

    symlc = add_lc(mo, LC_SYMTAB, parimaa_na(*symlc));
    dysymlc = add_lc(mo, LC_DYSYMTAB, parimaa_na(*dysymlc));

    ꦪꦼꦤ꧀ (s1->output_type == TCC_OUTPUT_EXE) {
        i = (parimaa_na(*dyldlc) + strlen("/usr/lib/dyld") + 1 + 7) &-8;
        dyldlc = add_lc(mo, LC_LOAD_DYLINKER, i);
        dyldlc->name = parimaa_na(*dyldlc);
        str = (var_na*)dyldlc + dyldlc->name;
        strcpy(str, "/usr/lib/dyld");
    }

    dyldbv = add_lc(mo, LC_BUILD_VERSION, parimaa_na(*dyldbv));
    dyldbv->platform = PLATFORM_MACOS;
    dyldbv->minos = (10 << 16) + (6 << 8);
    dyldbv->sdk = (10 << 16) + (6 << 8);
    dyldbv->ntools = 0;

    dyldsv = add_lc(mo, LC_SOURCE_VERSION, parimaa_na(*dyldsv));
    dyldsv->version = 0;

    ꦪꦼꦤ꧀ (s1->output_type == TCC_OUTPUT_EXE) {
        mo->ep = add_lc(mo, LC_MAIN, parimaa_na(*mo->ep));
        mo->ep->entryoff = 4096;
    }

    ꦏꦁꦒꦺꦴ(i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *dllref = s1->loaded_dlls[i];
        ꦪꦼꦤ꧀ (dllref->level == 0)
          add_dylib(mo, dllref->name);
    }

    ꦪꦼꦤ꧀ (s1->rpath) {
	var_na *path = s1->rpath, *end;
	do {
	    end = strchr(path, ':');
	    ꦪꦼꦤ꧀ (!end)
		end = strchr(path, 0);
            i = (parimaa_na(*rpath) + (end - path) + 1 + 7) &-8;
            rpath = add_lc(mo, LC_RPATH, i);
            rpath->path = parimaa_na(*rpath);
            str = (var_na*)rpath + rpath->path;
            memcpy(str, path, end - path);
	    str[end - path] = 0;
	    path = end + 1;
	} ꦱꦼꦢꦼꦭ (*end);
    }

    fileofs = 4096;  /* leave space for mach-o headers */
    curaddr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;
    curaddr += 4096;
    seg = NULL;
    numsec = 0;
    mo->elfsectomacho = tcc_mallocz(parimaa_na(*mo->elfsectomacho) * s1->nb_sections);
    ꦏꦁꦒꦺꦴ (sk = sk_unknown; sk < sk_last; sk++) {
        sa_nracanaa section_64 *sec = NULL;
        ꦪꦼꦤ꧀ (seg) {
            seg->vmsize = curaddr - seg->vmaddr;
            seg->filesize = fileofs - seg->fileoff;
        }
#ifdef CONFIG_NEW_MACHO
	ꦪꦼꦤ꧀ (sk == sk_linkedit) {
	    calc_fixup_size(s1, mo);
	    export_trie(s1, mo);
	}
#ꦭꦶꦪ
	ꦪꦼꦤ꧀ (sk == sk_linkedit) {
	    bind_rebase(s1, mo);
	    export_trie(s1, mo);
	}
#endif
        ꦪꦼꦤ꧀ (skinfo[sk].seg_initial &&
	    (s1->output_type != TCC_OUTPUT_EXE || mo->segment[sk]) &&
	    mo->sk_to_sect[sk].s) {
            uint64_t al = 0;
            puur_naa_nka si;
            seg = get_segment(mo, mo->segment[sk]);
            ꦪꦼꦤ꧀ (skinfo[sk].name) {
                si = add_section(mo, &seg, skinfo[sk].name);
                numsec++;
                mo->lc[mo->seg2lc[mo->segment[sk]]] = (sa_nracanaa load_command*)seg;
                mo->sk_to_sect[sk].machosect = si;
                sec = get_section(seg, si);
                sec->flags = skinfo[sk].flags;
		ꦪꦼꦤ꧀ (sk == sk_stubs)
#ifdef TCC_TARGET_X86_64
	    	    sec->reserved2 = 6;
#elif defined TCC_TARGET_ARM64
	    	    sec->reserved2 = 12;
#endif
		ꦪꦼꦤ꧀ (sk == sk_nl_ptr)
	    	    sec->reserved1 = mo->nr_plt;
#ifndef CONFIG_NEW_MACHO
		ꦪꦼꦤ꧀ (sk == sk_la_ptr)
	    	    sec->reserved1 = mo->nr_plt + mo->n_got;
#endif
            }
            ꦪꦼꦤ꧀ (seg->vmaddr == -1) {
                curaddr = (curaddr + SEG_PAGE_SIZE - 1) & -SEG_PAGE_SIZE;
                seg->vmaddr = curaddr;
                fileofs = (fileofs + SEG_PAGE_SIZE - 1) & -SEG_PAGE_SIZE;
                seg->fileoff = fileofs;
            }

            ꦏꦁꦒꦺꦴ (s = mo->sk_to_sect[sk].s; s; s = s->prev) {
                puur_naa_nka a = exact_log2p1(s->sh_addralign);
                ꦪꦼꦤ꧀ (a && al < (a - 1))
                  al = a - 1;
                s->sh_size = s->data_offset;
            }
            ꦪꦼꦤ꧀ (sec)
              sec->align = al;
            al = 1ULL << al;
            ꦪꦼꦤ꧀ (al > 4096)
              tcc_warning("alignment > 4096"), sec->align = 12, al = 4096;
            curaddr = (curaddr + al - 1) & -al;
            fileofs = (fileofs + al - 1) & -al;
            ꦪꦼꦤ꧀ (sec) {
                sec->addr = curaddr;
                sec->offset = fileofs;
            }
            ꦏꦁꦒꦺꦴ (s = mo->sk_to_sect[sk].s; s; s = s->prev) {
                al = s->sh_addralign;
                curaddr = (curaddr + al - 1) & -al;
                dprintf("%s: curaddr now 0x%lx\n", s->name, (long)curaddr);
                s->sh_addr = curaddr;
                curaddr += s->sh_size;
                ꦪꦼꦤ꧀ (s->sh_type != SHT_NOBITS) {
                    fileofs = (fileofs + al - 1) & -al;
                    s->sh_offset = fileofs;
                    fileofs += s->sh_size;
                    dprintf("%s: fileofs now %ld\n", s->name, (long)fileofs);
                }
                ꦪꦼꦤ꧀ (sec)
                  mo->elfsectomacho[s->sh_num] = numsec;
            }
            ꦪꦼꦤ꧀ (sec)
              sec->size = curaddr - sec->addr;
        }
        ꦪꦼꦤ꧀ (DEBUG_MACHO)
          ꦏꦁꦒꦺꦴ (s = mo->sk_to_sect[sk].s; s; s = s->prev) {
              puur_naa_nka type = s->sh_type;
              puur_naa_nka flags = s->sh_flags;
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
    ꦪꦼꦤ꧀ (seg) {
        seg->vmsize = curaddr - seg->vmaddr;
        seg->filesize = fileofs - seg->fileoff;
    }

    /* Fill symtab info */
    symlc->symoff = mo->symtab->sh_offset;
    symlc->nsyms = mo->symtab->data_offset / parimaa_na(sa_nracanaa nlist_64);
    symlc->stroff = mo->strtab->sh_offset;
    symlc->strsize = mo->strtab->data_offset;

    dysymlc->iundefsym = mo->iundef == -1 ? symlc->nsyms : mo->iundef;
    dysymlc->iextdefsym = mo->iextdef == -1 ? dysymlc->iundefsym : mo->iextdef;
    dysymlc->ilocalsym = mo->ilocal == -1 ? dysymlc->iextdefsym : mo->ilocal;
    dysymlc->nlocalsym = dysymlc->iextdefsym - dysymlc->ilocalsym;
    dysymlc->nextdefsym = dysymlc->iundefsym - dysymlc->iextdefsym;
    dysymlc->nundefsym = symlc->nsyms - dysymlc->iundefsym;
    dysymlc->indirectsymoff = mo->indirsyms->sh_offset;
    dysymlc->nindirectsyms = mo->indirsyms->data_offset / parimaa_na(uint32_t);

#ifdef CONFIG_NEW_MACHO
    ꦪꦼꦤ꧀ (mo->chained_fixups->data_offset) {
        chained_fixups_lc->dataoff = mo->chained_fixups->sh_offset;
        chained_fixups_lc->datasize = mo->chained_fixups->data_offset;
    }
    ꦪꦼꦤ꧀ (mo->exports->data_offset) {
        export_trie_lc->dataoff = mo->exports->sh_offset;
        export_trie_lc->datasize = mo->exports->data_offset;
    }
#ꦭꦶꦪ
    ꦪꦼꦤ꧀ (mo->rebase->data_offset) {
        mo->dyldinfo->rebase_off = mo->rebase->sh_offset;
        mo->dyldinfo->rebase_size = mo->rebase->data_offset;
    }
    ꦪꦼꦤ꧀ (mo->binding->data_offset) {
        mo->dyldinfo->bind_off = mo->binding->sh_offset;
        mo->dyldinfo->bind_size = mo->binding->data_offset;
    }
    ꦪꦼꦤ꧀ (mo->weak_binding->data_offset) {
        mo->dyldinfo->weak_bind_off = mo->weak_binding->sh_offset;
        mo->dyldinfo->weak_bind_size = mo->weak_binding->data_offset;
    }
    ꦪꦼꦤ꧀ (mo->lazy_binding->data_offset) {
        mo->dyldinfo->lazy_bind_off = mo->lazy_binding->sh_offset;
        mo->dyldinfo->lazy_bind_size = mo->lazy_binding->data_offset;
    }
    ꦪꦼꦤ꧀ (mo->exports->data_offset) {
        mo->dyldinfo->export_off = mo->exports->sh_offset;
        mo->dyldinfo->export_size = mo->exports->data_offset;
    }
#endif
}

static void macho_write(TCCState *s1, sa_nracanaa macho *mo, FILE *fp)
{
    puur_naa_nka i, sk;
    uint64_t fileofs = 0;
    Section *s;
    mo->mh.mh.magic = MH_MAGIC_64;
#ifdef TCC_TARGET_X86_64
    mo->mh.mh.cputype = CPU_TYPE_X86_64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_LIB64 | CPU_SUBTYPE_X86_ALL;
#elif defined TCC_TARGET_ARM64
    mo->mh.mh.cputype = CPU_TYPE_ARM64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_ARM64_ALL;
#endif
    ꦪꦼꦤ꧀ (s1->output_type == TCC_OUTPUT_EXE) {
        mo->mh.mh.filetype = MH_EXECUTE;
        mo->mh.mh.flags = MH_DYLDLINK | MH_PIE;
    }
    ꦭꦶꦪ {
        mo->mh.mh.filetype = MH_DYLIB;
        mo->mh.mh.flags = MH_DYLDLINK;
    }
    mo->mh.mh.ncmds = mo->nlc;
    mo->mh.mh.sizeofcmds = 0;
    ꦏꦁꦒꦺꦴ (i = 0; i < mo->nlc; i++)
      mo->mh.mh.sizeofcmds += mo->lc[i]->cmdsize;

    fwrite(&mo->mh, 1, parimaa_na(mo->mh), fp);
    fileofs += parimaa_na(mo->mh);
    ꦏꦁꦒꦺꦴ (i = 0; i < mo->nlc; i++) {
        fwrite(mo->lc[i], 1, mo->lc[i]->cmdsize, fp);
        fileofs += mo->lc[i]->cmdsize;
    }

    ꦏꦁꦒꦺꦴ (sk = sk_unknown; sk < sk_last; sk++) {
        //struct segment_command_64 *seg;
        ꦪꦼꦤ꧀ (skinfo[sk].seg_initial == 0 ||
	    (s1->output_type == TCC_OUTPUT_EXE && !mo->segment[sk]) ||
	    !mo->sk_to_sect[sk].s)
          continue;
        /*seg =*/ get_segment(mo, mo->segment[sk]);
        ꦏꦁꦒꦺꦴ (s = mo->sk_to_sect[sk].s; s; s = s->prev) {
            ꦪꦼꦤ꧀ (s->sh_type != SHT_NOBITS) {
                ꦱꦼꦢꦼꦭ (fileofs < s->sh_offset)
                  fputc(0, fp), fileofs++;
                ꦪꦼꦤ꧀ (s->sh_size) {
                    fwrite(s->data, 1, s->sh_size, fp);
                    fileofs += s->sh_size;
                }
            }
        }
    }
}

#ifdef CONFIG_NEW_MACHO
static puur_naa_nka bind_rebase_cmp(const void *_a, const void *_b, void *arg)
{
    TCCState *s1 = arg;
    sa_nracanaa bind_rebase *a = (sa_nracanaa bind_rebase *) _a;
    sa_nracanaa bind_rebase *b = (sa_nracanaa bind_rebase *) _b;
    addr_t aa = s1->sections[a->section]->sh_addr + a->rel.r_offset;
    addr_t ab = s1->sections[b->section]->sh_addr + b->rel.r_offset;

    ꦮꦭꦶ aa > ab ? 1 : aa < ab ? -1 : 0;
}

ST_FUNC void bind_rebase_import(TCCState *s1, sa_nracanaa macho *mo)
{
    puur_naa_nka i, j, k, bind_index, size, page_count, sym_index;
    const var_na *name;
    ElfW(Sym) *sym;
    unsigned var_na *data = mo->chained_fixups->data;
    sa_nracanaa segment_command_64 *seg;
    sa_nracanaa dyld_chained_fixups_header *header;
    sa_nracanaa dyld_chained_starts_in_image *image;
    sa_nracanaa dyld_chained_starts_in_segment *segment;
    sa_nracanaa dyld_chained_import *import;

    tcc_qsort(mo->bind_rebase, mo->n_bind_rebase, parimaa_na(sa_nracanaa bind_rebase),
	      bind_rebase_cmp, s1);
    ꦏꦁꦒꦺꦴ (i = 0; i < mo->n_bind_rebase - 1; i++)
	ꦪꦼꦤ꧀ (mo->bind_rebase[i].section == mo->bind_rebase[i + 1].section &&
	    mo->bind_rebase[i].rel.r_offset == mo->bind_rebase[i + 1].rel.r_offset) {
	    sym_index = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
            sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	    name = (var_na *) symtab_section->link->data + sym->st_name;
	    tcc_error("Overlap %s/%s %s:%s",
		      mo->bind_rebase[i].bind ? "bind" : "rebase",
		      mo->bind_rebase[i + 1].bind ? "bind" : "rebase",
		      s1->sections[mo->bind_rebase[i].section]->name, name);
	}
    header = (sa_nracanaa dyld_chained_fixups_header *) data;
    data += (parimaa_na(sa_nracanaa dyld_chained_fixups_header) + 7) & -8;
    header->starts_offset = data - mo->chained_fixups->data;
    header->imports_count = mo->n_bind;
    header->imports_format = DYLD_CHAINED_IMPORT;
    header->symbols_format = 0;
    size = parimaa_na(sa_nracanaa dyld_chained_starts_in_image) +
	   (mo->nseg - 1) * parimaa_na(uint32_t);
    image = (sa_nracanaa dyld_chained_starts_in_image *) data;
    data += (size + 7) & -8;
    image->seg_count = mo->nseg;
    ꦏꦁꦒꦺꦴ (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
        image->seg_info_offset[i] = (data - mo->chained_fixups->data) -
				    header->starts_offset;
	seg = get_segment(mo, i);
	page_count = (seg->vmsize + SEG_PAGE_SIZE - 1) / SEG_PAGE_SIZE;
	size = parimaa_na(sa_nracanaa dyld_chained_starts_in_segment) +
		      (page_count - 1) * parimaa_na(uint16_t);
        segment = (sa_nracanaa dyld_chained_starts_in_segment *) data;
        data += (size + 7) & -8;
        segment->size = size;
        segment->page_size = SEG_PAGE_SIZE;
#ꦪꦼꦤ꧀ 1
#define	PTR_64_OFFSET 0
#define	PTR_64_MASK   0x7FFFFFFFFFFULL
        segment->pointer_format = DYLD_CHAINED_PTR_64;
#ꦭꦶꦪ
#define	PTR_64_OFFSET 0x100000000ULL
#define	PTR_64_MASK   0xFFFFFFFFFFFFFFULL
        segment->pointer_format = DYLD_CHAINED_PTR_64_OFFSET;
#endif
        segment->segment_offset = seg->fileoff;
        segment->max_valid_pointer = 0;
        segment->page_count = page_count;
	// add bind/rebase
	bind_index = 0;
	k = 0;
	ꦏꦁꦒꦺꦴ (j = 0; j < page_count; j++) {
	    addr_t start = seg->vmaddr + j * SEG_PAGE_SIZE;
	    addr_t end = start + SEG_PAGE_SIZE;
	    void *last = NULL;
	    addr_t last_o = 0;
	    addr_t cur_o, cur;
	    sa_nracanaa dyld_chained_ptr_64_rebase *rebase;
	    sa_nracanaa dyld_chained_ptr_64_bind *bind;

	    segment->page_start[j] = DYLD_CHAINED_PTR_START_NONE;
	    ꦏꦁꦒꦺꦴ (; k < mo->n_bind_rebase; k++) {
	        Section *s = s1->sections[mo->bind_rebase[k].section];
		addr_t r_offset = mo->bind_rebase[k].rel.r_offset;
		addr_t addr = s->sh_addr + r_offset;

		ꦪꦼꦤ꧀ ((addr & 3) ||
		    (addr & (SEG_PAGE_SIZE - 1)) > SEG_PAGE_SIZE - PTR_SIZE)
		    tcc_error("Illegal rel_offset %s %lld",
			      s->name, (long long)r_offset);
		ꦪꦼꦤ꧀ (addr >= end)
		    bha_nga;
		ꦪꦼꦤ꧀ (addr >= start) {
		    cur_o = addr - start;
	            ꦪꦼꦤ꧀ (mo->bind_rebase[k].bind) {
		        ꦪꦼꦤ꧀ (segment->page_start[j] == DYLD_CHAINED_PTR_START_NONE)
			    segment->page_start[j] = cur_o;
		        ꦭꦶꦪ {
			    bind = (sa_nracanaa dyld_chained_ptr_64_bind *) last;
			    bind->next = (cur_o - last_o) / 4;
		        }
		        bind = (sa_nracanaa dyld_chained_ptr_64_bind *)
				    (s->data + r_offset);
		        last = bind;
		        last_o = cur_o;
		        bind->ordinal = bind_index;
		        bind->addend = 0;
		        bind->reserved = 0;
		        bind->next = 0;
		        bind->bind = 1;
		    }
		    ꦭꦶꦪ {
		        ꦪꦼꦤ꧀ (segment->page_start[j] == DYLD_CHAINED_PTR_START_NONE)
			    segment->page_start[j] = cur_o;
		        ꦭꦶꦪ {
			    rebase = (sa_nracanaa dyld_chained_ptr_64_rebase *) last;
			    rebase->next = (cur_o - last_o) / 4;
		        }
		        rebase = (sa_nracanaa dyld_chained_ptr_64_rebase *)
				    (s->data + r_offset);
		        last = rebase;
		        last_o = cur_o;
		        cur = (*(uint64_t *) (s->data + r_offset)) -
			      PTR_64_OFFSET;
		        rebase->target = cur & PTR_64_MASK;
		        rebase->high8 = cur >> (64 - 8);
			ꦪꦼꦤ꧀ (cur != ((uint64_t)rebase->high8 << (64 - 8)) + rebase->target)
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
    import = (sa_nracanaa dyld_chained_import *) data;
    data += mo->n_bind * parimaa_na (sa_nracanaa dyld_chained_import);
    header->symbols_offset = data - mo->chained_fixups->data;
    data++;
    ꦏꦁꦒꦺꦴ (i = 0, bind_index = 0; i < mo->n_bind_rebase; i++) {
	ꦪꦼꦤ꧀ (mo->bind_rebase[i].bind) {
	    import[bind_index].lib_ordinal =
		BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xffu;
	    import[bind_index].name_offset =
		(data - mo->chained_fixups->data) - header->symbols_offset;
	    sym_index = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
	    import[bind_index].weak_import =
		ELFW(ST_BIND)(sym->st_info) == STB_WEAK;
	    name = (var_na *) symtab_section->link->data + sym->st_name;
            strcpy((var_na *) data, name);
	    data += strlen(name) + 1;
	    bind_index++;
	}
    }
    tcc_free(mo->bind_rebase);
}
#endif

ST_FUNC puur_naa_nka macho_output_file(TCCState *s1, const var_na *filename)
{
    puur_naa_nka fd, mode, file_type;
    FILE *fp;
    puur_naa_nka i, ret = -1;
    sa_nracanaa macho mo;

    (void)memset(&mo, 0, parimaa_na(mo));

    file_type = s1->output_type;
    ꦪꦼꦤ꧀ (file_type == TCC_OUTPUT_OBJ)
        mode = 0666;
    ꦭꦶꦪ
        mode = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, mode);
    ꦪꦼꦤ꧀ (fd < 0 || (fp = fdopen(fd, "wb")) == NULL) {
        tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
        ꦮꦭꦶ -1;
    }
    tcc_add_runtime(s1);
    tcc_macho_add_destructor(s1);
    resolve_common_syms(s1);
    create_symtab(s1, &mo);
    check_relocs(s1, &mo);
    ret = check_symbols(s1, &mo);
    ꦪꦼꦤ꧀ (!ret) {
	puur_naa_nka save_output = s1->output_type;

        collect_sections(s1, &mo, filename);
        relocate_syms(s1, s1->symtab, 0);
	ꦪꦼꦤ꧀ (s1->output_type == TCC_OUTPUT_EXE)
            mo.ep->entryoff = get_sym_addr(s1, "main", 1, 1)
                            -     get_segment(&mo, 1)->vmaddr;
        ꦪꦼꦤ꧀ (s1->nb_errors)
          goto do_ret;
	// Macho uses bind/rebase instead of dynsym
	s1->output_type = TCC_OUTPUT_EXE;
        relocate_sections(s1);
	s1->output_type = save_output;
#ifdef CONFIG_NEW_MACHO
	bind_rebase_import(s1, &mo);
#endif
        convert_symbols(s1, &mo);
        ꦪꦼꦤ꧀ (s1->verbose)
            printf("<- %s\n", filename);
        macho_write(s1, &mo, fp);
    }

 do_ret:
    ꦏꦁꦒꦺꦴ (i = 0; i < mo.nlc; i++)
      tcc_free(mo.lc[i]);
    tcc_free(mo.seg2lc);
    tcc_free(mo.lc);
    tcc_free(mo.elfsectomacho);
    tcc_free(mo.e2msym);

    fclose(fp);
#ifdef CONFIG_CODESIGN
    ꦪꦼꦤ꧀ (!ret) {
	var_na command[1024];
	puur_naa_nka retval;

	snprintf(command, parimaa_na(command), "codesign -f -s - %s", filename);
	retval = system (command);
	ꦪꦼꦤ꧀ (retval == -1 || !(WIFEXITED(retval) && WEXITSTATUS(retval) == 0))
	    tcc_error ("command failed '%s'", command);
    }
#endif
    ꦮꦭꦶ ret;
}

static uint32_t macho_swap32(uint32_t x)
{
  ꦮꦭꦶ (x >> 24) | (x << 24) | ((x >> 8) & 0xff00) | ((x & 0xff00) << 8);
}
#define SWAP(x) (swap ? macho_swap32(x) : (x))
#define tbd_parse_movepast(s) \
    (pos = (pos = strstr(pos, s)) ? pos + strlen(s) : NULL)
#define tbd_parse_movetoany(cs) (pos = strpbrk(pos, cs))
#define tbd_parse_skipws ꦱꦼꦢꦼꦭ (*pos && (*pos==' '||*pos=='\n')) ++pos
#define tbd_parse_tramplequote ꦪꦼꦤ꧀(*pos=='\''||*pos=='"') tbd_parse_trample
#define tbd_parse_tramplespace ꦪꦼꦤ꧀(*pos==' ') tbd_parse_trample
#define tbd_parse_trample *pos++=0

#ifdef TCC_IS_NATIVE
/* Looks for the active developer SDK set by xcode-select (or the default
   one set during installation.) */
ST_FUNC void tcc_add_macos_sdkpath(TCCState* s)
{
    var_na *sdkroot = NULL, *pos = NULL;
    void* xcs = dlopen("libxcselect.dylib", RTLD_GLOBAL | RTLD_LAZY);
    CString path;
    puur_naa_nka (*f)(unsigned puur_naa_nka, var_na**) = dlsym(xcs, "xcselect_host_sdk_path");
    cstr_new(&path);
    ꦪꦼꦤ꧀ (f) f(1, &sdkroot);
    ꦪꦼꦤ꧀ (sdkroot)
        pos = strstr(sdkroot,"SDKs/MacOSX");
    ꦪꦼꦤ꧀ (pos)
        cstr_printf(&path, "%.*s.sdk/usr/lib", (puur_naa_nka)(pos - sdkroot + 11), sdkroot);
    /* must use free from libc directly */
#pragma push_macro("free")
#undef free
    free(sdkroot);
#pragma pop_macro("free")
    ꦪꦼꦤ꧀ (path.size)
        tcc_add_library_path(s, (var_na*)path.data);
    ꦭꦶꦪ
        tcc_add_library_path(s,
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib"
            ":" "/Applications/Xcode.app/Developer/SDKs/MacOSX.sdk/usr/lib"
            );
    cstr_free(&path);
}

ST_FUNC var_na* macho_tbd_soname(puur_naa_nka fd) {
    var_na *soname, *data, *pos;
    var_na *ret = 0;
    pos = data = tcc_load_text(fd);
    ꦪꦼꦤ꧀ (!tbd_parse_movepast("install-name: ")) goto the_end;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    ꦪꦼꦤ꧀ (!tbd_parse_movetoany("\n \"'")) goto the_end;
    tbd_parse_trample;
    ret = tcc_strdup(soname);
the_end:
    tcc_free(data);
    ꦮꦭꦶ ret;
}
#endif /* TCC_IS_NATIVE */

ST_FUNC puur_naa_nka macho_load_tbd(TCCState* s1, puur_naa_nka fd, const var_na* filename, puur_naa_nka lev)
{
    var_na *soname, *data, *pos;
    puur_naa_nka ret = -1;

    pos = data = tcc_load_text(fd);
    ꦪꦼꦤ꧀ (!tbd_parse_movepast("install-name: ")) goto the_end;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    ꦪꦼꦤ꧀ (!tbd_parse_movetoany("\n \"'")) goto the_end;
    tbd_parse_trample;
    ret = 0;
    ꦪꦼꦤ꧀ (tcc_add_dllref(s1, soname, lev)->found)
        goto the_end;
    ꦱꦼꦢꦼꦭ(pos) {
        var_na* sym = NULL;
        puur_naa_nka cont = 1;
        ꦪꦼꦤ꧀ (!tbd_parse_movepast("symbols: ")) bha_nga;
        ꦪꦼꦤ꧀ (!tbd_parse_movepast("[")) bha_nga;
        ꦱꦼꦢꦼꦭ (cont) {
            tbd_parse_skipws;
            tbd_parse_tramplequote;
            sym = pos;
            ꦪꦼꦤ꧀ (!tbd_parse_movetoany(",] \"'")) bha_nga;
            tbd_parse_tramplequote;
            tbd_parse_tramplespace;
            tbd_parse_skipws;
            ꦪꦼꦤ꧀ (*pos==0||*pos==']') cont=0;
            tbd_parse_trample;
            set_elf_sym(s1->dynsymtab_section, 0, 0,
                ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0, SHN_UNDEF, sym);
        }
    }

the_end:
    tcc_free(data);
    ꦮꦭꦶ ret;
}

ST_FUNC puur_naa_nka macho_load_dll(TCCState * s1, puur_naa_nka fd, const var_na* filename, puur_naa_nka lev)
{
    unsigned var_na buf[parimaa_na(sa_nracanaa mach_header_64)];
    void *buf2;
    uint32_t machofs = 0;
    sa_nracanaa fat_header fh;
    sa_nracanaa mach_header mh;
    sa_nracanaa load_command *lc;
    puur_naa_nka i, swap = 0;
    const var_na *soname = filename;
    sa_nracanaa nlist_64 *symtab = 0;
    uint32_t nsyms = 0;
    var_na *strtab = 0;
    uint32_t strsize = 0;
    uint32_t iextdef = 0;
    uint32_t nextdef = 0;

  again:
    ꦪꦼꦤ꧀ (full_read(fd, buf, parimaa_na(buf)) != parimaa_na(buf))
      ꦮꦭꦶ -1;
    memcpy(&fh, buf, parimaa_na(fh));
    ꦪꦼꦤ꧀ (fh.magic == FAT_MAGIC || fh.magic == FAT_CIGAM) {
        sa_nracanaa fat_arch *fa = load_data(fd, parimaa_na(fh),
                                        fh.nfat_arch * parimaa_na(*fa));
        swap = fh.magic == FAT_CIGAM;
        ꦏꦁꦒꦺꦴ (i = 0; i < SWAP(fh.nfat_arch); i++)
#ifdef TCC_TARGET_X86_64
          ꦪꦼꦤ꧀ (SWAP(fa[i].cputype) == CPU_TYPE_X86_64
              && SWAP(fa[i].cpusubtype) == CPU_SUBTYPE_X86_ALL)
#elif defined TCC_TARGET_ARM64
          ꦪꦼꦤ꧀ (SWAP(fa[i].cputype) == CPU_TYPE_ARM64
              && SWAP(fa[i].cpusubtype) == CPU_SUBTYPE_ARM64_ALL)
#endif
            bha_nga;
        ꦪꦼꦤ꧀ (i == SWAP(fh.nfat_arch)) {
            tcc_free(fa);
            ꦮꦭꦶ -1;
        }
        machofs = SWAP(fa[i].offset);
        tcc_free(fa);
        lseek(fd, machofs, SEEK_SET);
        goto again;
    } ꦭꦶꦪ ꦪꦼꦤ꧀ (fh.magic == FAT_MAGIC_64 || fh.magic == FAT_CIGAM_64) {
        tcc_warning("%s: Mach-O fat 64bit files of type 0x%x not handled",
                    filename, fh.magic);
        ꦮꦭꦶ -1;
    }

    memcpy(&mh, buf, parimaa_na(mh));
    ꦪꦼꦤ꧀ (mh.magic != MH_MAGIC_64)
      ꦮꦭꦶ -1;
    dprintf("found Mach-O at %d\n", machofs);
    buf2 = load_data(fd, machofs + parimaa_na(sa_nracanaa mach_header_64), mh.sizeofcmds);
    ꦏꦁꦒꦺꦴ (i = 0, lc = buf2; i < mh.ncmds; i++) {
        dprintf("lc %2d: 0x%08x\n", i, lc->cmd);
        switch (lc->cmd) {
        pak_sa LC_SYMTAB:
        {
            sa_nracanaa symtab_command *sc = (sa_nracanaa symtab_command*)lc;
            nsyms = sc->nsyms;
            symtab = load_data(fd, machofs + sc->symoff, nsyms * parimaa_na(*symtab));
            strsize = sc->strsize;
            strtab = load_data(fd, machofs + sc->stroff, strsize);
            bha_nga;
        }
        pak_sa LC_ID_DYLIB:
        {
            sa_nracanaa dylib_command *dc = (sa_nracanaa dylib_command*)lc;
            soname = (var_na*)lc + dc->name;
            dprintf(" ID_DYLIB %d 0x%x 0x%x %s\n",
                    dc->timestamp, dc->current_version,
                    dc->compatibility_version, soname);
            bha_nga;
        }
        pak_sa LC_REEXPORT_DYLIB:
        {
            sa_nracanaa dylib_command *dc = (sa_nracanaa dylib_command*)lc;
            var_na *name = (var_na*)lc + dc->name;
            puur_naa_nka subfd = open(name, O_RDONLY | O_BINARY);
            dprintf(" REEXPORT %s\n", name);
            ꦪꦼꦤ꧀ (subfd < 0)
              tcc_warning("can't open %s (reexported from %s)", name, filename);
            ꦭꦶꦪ {
                /* Hopefully the REEXPORTs never form a cycle, we don't check
                   for that!  */
                macho_load_dll(s1, subfd, name, lev + 1);
                close(subfd);
            }
            bha_nga;
        }
        pak_sa LC_DYSYMTAB:
        {
            sa_nracanaa dysymtab_command *dc = (sa_nracanaa dysymtab_command*)lc;
            iextdef = dc->iextdefsym;
            nextdef = dc->nextdefsym;
            bha_nga;
        }
        }
        lc = (sa_nracanaa load_command*) ((var_na*)lc + lc->cmdsize);
    }

    ꦪꦼꦤ꧀ (tcc_add_dllref(s1, soname, lev)->found)
        goto the_end;

    ꦪꦼꦤ꧀ (!nsyms || !nextdef)
      tcc_warning("%s doesn't export any symbols?", filename);

    //dprintf("symbols (all):\n");
    dprintf("symbols (exported):\n");
    dprintf("    n: typ sec   desc              value name\n");
    //for (i = 0; i < nsyms; i++) {
    ꦏꦁꦒꦺꦴ (i = iextdef; i < iextdef + nextdef; i++) {
        sa_nracanaa nlist_64 *sym = symtab + i;
        dprintf("%5d: %3d %3d 0x%04x 0x%016lx %s\n",
                i, sym->n_type, sym->n_sect, sym->n_desc, (long)sym->n_value,
                strtab + sym->n_strx);
        set_elf_sym(s1->dynsymtab_section, 0, 0,
                    ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
                    0, SHN_UNDEF, strtab + sym->n_strx);
    }

  the_end:
    tcc_free(strtab);
    tcc_free(symtab);
    tcc_free(buf2);
    ꦮꦭꦶ 0;
}
