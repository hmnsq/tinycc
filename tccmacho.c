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
#ضمن "tcc.h"

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

#إذا !defined TCC_موخه_X86_64 && !defined TCC_موخه_ARM64
#تېروتنه Platform not supported
#د_که_پای

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#تعریف_لغوه _tcc_error

#تعریف_کړه DEBUG_MACHO 0
#تعریف_کړه dprintf إذا (DEBUG_MACHO) چاپ_کړه

#تعریف_کړه MH_EXECUTE              (0x2)
#تعریف_کړه MH_DYLDLINK             (0x4)
#تعریف_کړه MH_DYLIB                (0x6)
#تعریف_کړه MH_PIE                  (0x200000)

#تعریف_کړه CPU_SUBTYPE_LIB64       (0x80000000)
#تعریف_کړه CPU_SUBTYPE_X86_ALL     (3)
#تعریف_کړه CPU_SUBTYPE_ARM64_ALL   (0)

#تعریف_کړه CPU_ARCH_ABI64          (0x01000000)

#تعریف_کړه CPU_TYPE_X86            (7)
#تعریف_کړه CPU_TYPE_X86_64         (CPU_TYPE_X86 | CPU_ARCH_ABI64)
#تعریف_کړه CPU_TYPE_ARM            (12)
#تعریف_کړه CPU_TYPE_ARM64          (CPU_TYPE_ARM | CPU_ARCH_ABI64)

بنية fat_سرلیک {
    uint32_t        magic;          /* FAT_MAGIC or FAT_MAGIC_64 */
    uint32_t        nfat_arch;      /* number of structs that follow */
};

بنية fat_arch {
    صحيح             cputype;        /* cpu specifier (int) */
    صحيح             cpusubtype;     /* machine specifier (int) */
    uint32_t        دننه_واټن;         /* file offset to this object file */
    uint32_t        اندازه;           /* size of this object file */
    uint32_t        align;          /* alignment as a power of 2 */
};

#تعریف_کړه FAT_MAGIC       0xcafebabe
#تعریف_کړه FAT_CIGAM       0xbebafeca
#تعریف_کړه FAT_MAGIC_64    0xcafebabf
#تعریف_کړه FAT_CIGAM_64    0xbfbafeca

بنية mach_سرلیک {
    uint32_t        magic;          /* mach magic number identifier */
    صحيح             cputype;        /* cpu specifier */
    صحيح             cpusubtype;     /* machine specifier */
    uint32_t        filetype;       /* type of file */
    uint32_t        ncmds;          /* number of load commands */
    uint32_t        sizeofcmds;     /* the size of all the load commands */
    uint32_t        flags;          /* flags */
};

بنية mach_سرلیک_64 {
    بنية mach_سرلیک  mh;
    uint32_t            reserved;       /* reserved, pad to 64bit */
};

/* Constant for the magic field of the mach_header (32-bit architectures) */
#تعریف_کړه MH_MAGIC        0xfeedface      /* the mach magic number */
#تعریف_کړه MH_CIGAM        0xcefaedfe      /* NXSwapInt(MH_MAGIC) */
#تعریف_کړه MH_MAGIC_64     0xfeedfacf      /* the 64-bit mach magic number */
#تعریف_کړه MH_CIGAM_64     0xcffaedfe      /* NXSwapInt(MH_MAGIC_64) */

بنية بارول_command {
    uint32_t        cmd;            /* type of load command */
    uint32_t        cmdsize;        /* total size of command in bytes */
};

#تعریف_کړه LC_REQ_DYLD 0x80000000
#تعریف_کړه LC_SYMTAB        0x2
#تعریف_کړه LC_DYSYMTAB      0xb
#تعریف_کړه LC_بارول_DYLIB    0xc
#تعریف_کړه LC_ID_DYLIB      0xd
#تعریف_کړه LC_بارول_DYLINKER 0xe
#تعریف_کړه LC_SEGMENT_64    0x19
#تعریف_کړه LC_RPATH (0x1c | LC_REQ_DYLD)
#تعریف_کړه LC_REEXPORT_DYLIB (0x1f | LC_REQ_DYLD)
#تعریف_کړه LC_DYLD_INFO_ONLY (0x22|LC_REQ_DYLD)
#تعریف_کړه LC_MAIN (0x28|LC_REQ_DYLD)
#تعریف_کړه LC_سرچینه_نسخه 0x2A
#تعریف_کړه LC_BUILD_نسخه 0x32
#تعریف_کړه LC_DYLD_EXPORTS_TRIE (0x33 | LC_REQ_DYLD)
#تعریف_کړه LC_DYLD_CHAINED_FIXUPS (0x34 | LC_REQ_DYLD)

#تعریف_کړه SG_READ_ONLY    0x10 /* This segment is made read-only after fixups */

تعريفنوع صحيح vm_prot_t;

بنية segment_command_64 { /* for 64-bit architectures */
    uint32_t        cmd;            /* LC_SEGMENT_64 */
    uint32_t        cmdsize;        /* includes sizeof section_64 structs */
    حرف            segname[16];    /* segment name */
    uint64_t        vmaddr;         /* memory address of this segment */
    uint64_t        vmsize;         /* memory size of this segment */
    uint64_t        fileoff;        /* file offset of this segment */
    uint64_t        filesize;       /* amount to map from the file */
    vm_prot_t       maxprot;        /* maximum VM protection */
    vm_prot_t       initprot;       /* initial VM protection */
    uint32_t        nsects;         /* number of sections in segment */
    uint32_t        flags;          /* flags */
};

بنية section_64 { /* for 64-bit architectures */
    حرف            sectname[16];   /* name of this section */
    حرف            segname[16];    /* segment this section goes in */
    uint64_t        addr;           /* memory address of this section */
    uint64_t        اندازه;           /* size in bytes of this section */
    uint32_t        دننه_واټن;         /* file offset of this section */
    uint32_t        align;          /* section alignment (power of 2) */
    uint32_t        reloff;         /* file offset of relocation entries */
    uint32_t        nreloc;         /* number of relocation entries */
    uint32_t        flags;          /* flags (section type and attributes)*/
    uint32_t        reserved1;      /* reserved (for offset or index) */
    uint32_t        reserved2;      /* reserved (for count or sizeof) */
    uint32_t        reserved3;      /* reserved */
};

تعداد {
    DYLD_CHAINED_IMPORT          = 1,
};

بنية dyld_chained_fixups_سرلیک {
    uint32_t    fixups_نسخه; ///< 0
    uint32_t    starts_دننه_واټن;  ///< Offset of dyld_chained_starts_in_image.
    uint32_t    imports_دننه_واټن; ///< Offset of imports table in chain_data.
    uint32_t    symbols_دننه_واټن; ///< Offset of symbol strings in chain_data.
    uint32_t    imports_شمېر;  ///< Number of imported symbol names.
    uint32_t    imports_format; ///< DYLD_CHAINED_IMPORT*
    uint32_t    symbols_format; ///< 0 => uncompressed, 1 => zlib compressed
};

بنية dyld_chained_starts_دننه_image
{
    uint32_t    seg_شمېر;
    uint32_t    seg_info_دننه_واټن[1];  // each entry is offset into this struct for that segment
    // followed by pool of dyld_chain_starts_in_segment data
};

تعداد {
    DYLD_CHAINED_PTR_64                     =  2,    // target is vmaddr
    DYLD_CHAINED_PTR_64_دننه_واټن              =  6,    // target is vm offset
};

تعداد {
    DYLD_CHAINED_PTR_پیل_NONE   = 0xFFFF, // used in page_start[] to denote a page with no fixups
};

#تعریف_کړه SEG_پاڼه_اندازه 16384

بنية dyld_chained_starts_دننه_segment
{
    uint32_t    اندازه;               // size of this (amount kernel needs to copy)
    uint16_t    پاڼه_اندازه;          // 0x1000 or 0x4000
    uint16_t    اشاره_ګر_format;     // DYLD_CHAINED_PTR_*
    uint64_t    segment_دننه_واټن;     // offset in memory to start of segment
    uint32_t    max_valid_اشاره_ګر;  // for 32-bit OS, any value beyond this is not a pointer
    uint16_t    پاڼه_شمېر;         // how many pages are in array
    uint16_t    پاڼه_پیل[1];      // each entry is offset in each page of first element in chain
                                    // or DYLD_CHAINED_PTR_START_NONE if no fixups on page
};

تعداد BindSpecialDylib {
  BIND_SPECIAL_DYLIB_FLAT_LOOKUP = -2,
};

بنية dyld_chained_import
{
    uint32_t    lib_ordinal :  8,
                weak_import :  1,
                name_دننه_واټن : 23;
};

بنية dyld_chained_ptr_64_rebase
{
    uint64_t    موخه    : 36,    // vmaddr, 64GB max image size
                high8     :  8,    // top 8 bits set to this after slide added
                reserved  :  7,    // all zeros
                بل      : 12,    // 4-byte stride
                bind      :  1;    // == 0
};

بنية dyld_chained_ptr_64_bind
{
    uint64_t    ordinal   : 24,
                addend    :  8,   // 0 thru 255
                reserved  : 19,   // all zeros
                بل      : 12,   // 4-byte stride
                bind      :  1;   // == 1
};

#تعریف_کړه S_REGULAR                       0x0
#تعریف_کړه S_ZEROFILL                      0x1
#تعریف_کړه S_NON_LAZY_نښه_اشارې      0x6
#تعریف_کړه S_LAZY_نښه_اشارې          0x7
#تعریف_کړه S_نښه_STUBS                  0x8
#تعریف_کړه S_MOD_INIT_FUNC_اشارې        0x9
#تعریف_کړه S_MOD_غړی_FUNC_اشارې        0xa

#تعریف_کړه S_ATTR_خالص_INSTRUCTIONS        0x80000000
#تعریف_کړه S_ATTR_SOME_INSTRUCTIONS        0x00000400
#تعریف_کړه S_ATTR_DEBUG             	0x02000000


تعريفنوع uint32_t lc_str;

بنية dylib_command {
    uint32_t cmd;                   /* LC_ID_DYLIB, LC_LOAD_{,WEAK_}DYLIB,
                                       LC_REEXPORT_DYLIB */
    uint32_t cmdsize;               /* includes pathname string */
    lc_str   name;                  /* library's path name */
    uint32_t timestamp;             /* library's build time stamp */
    uint32_t current_نسخه;       /* library's current version number */
    uint32_t compatibility_نسخه; /* library's compatibility vers number*/
};

بنية rpath_command {
    uint32_t     cmd;           /* LC_RPATH */
    uint32_t     cmdsize;       /* includes string */
    lc_str       لار;          /* path to add to run path */
};

بنية dylinker_command {
    uint32_t        cmd;            /* LC_ID_DYLINKER, LC_LOAD_DYLINKER or
                                       LC_DYLD_ENVIRONMENT */
    uint32_t        cmdsize;        /* includes pathname string */
    lc_str          name;           /* dynamic linker's path name */
};

بنية linkedit_معلومات_command {
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

#تعریف_کړه PLATFORM_MACOS 1

بنية build_نسخه_command {
    uint32_t    cmd;            /* LC_BUILD_VERSION */
    uint32_t    cmdsize;        /* sizeof(struct build_version_command) plus */
                                /* ntools * sizeof(struct build_tool_version) */
    uint32_t    platform;       /* platform */
    uint32_t    minos;          /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    sdk;            /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    ntools;         /* number of tool entries following this */
};

بنية سرچینه_نسخه_command {
    uint32_t  cmd;      /* LC_SOURCE_VERSION */
    uint32_t  cmdsize;  /* 16 */
    uint64_t  نسخه;  /* A.B.C.D.E packed as a24.b10.c10.d10.e10 */
};

بنية symtab_command {
    uint32_t        cmd;            /* LC_SYMTAB */
    uint32_t        cmdsize;        /* sizeof(struct symtab_command) */
    uint32_t        symoff;         /* symbol table offset */
    uint32_t        nsyms;          /* number of symbol table entries */
    uint32_t        stroff;         /* string table offset */
    uint32_t        strsize;        /* string table size in bytes */
};

بنية dysymtab_command {
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

#تعریف_کړه BIND_OPCODE_بشپړ                                        0x00
#تعریف_کړه BIND_OPCODE_سېټ_DYLIB_SPECIAL_IMM                       0x30
#تعریف_کړه BIND_OPCODE_سېټ_نښه_TRAILING_FLAGS_IMM               0x40
#تعریف_کړه BIND_OPCODE_سېټ_TYPE_IMM                                0x50
#تعریف_کړه BIND_OPCODE_سېټ_SEGMENT_AND_دننه_واټن_ULEB                 0x70
#تعریف_کړه BIND_OPCODE_DO_BIND                                     0x90

#تعریف_کړه BIND_نښه_FLAGS_WEAK_IMPORT                           0x1

#تعریف_کړه BIND_TYPE_اشاره_ګر                                       1
#تعریف_کړه BIND_SPECIAL_DYLIB_FLAT_LOOKUP                          -2

#تعریف_کړه REBASE_OPCODE_بشپړ                                      0x00
#تعریف_کړه REBASE_OPCODE_سېټ_TYPE_IMM                              0x10
#تعریف_کړه REBASE_OPCODE_سېټ_SEGMENT_AND_دننه_واټن_ULEB               0x20
#تعریف_کړه REBASE_OPCODE_DO_REBASE_IMM_TIMES                       0x50

#تعریف_کړه REBASE_TYPE_اشاره_ګر                                     1

#تعریف_کړه EXPORT_نښه_FLAGS_ډول_REGULAR                        0x00
#تعریف_کړه EXPORT_نښه_FLAGS_ډول_ABSOLUTE                       0x02
#تعریف_کړه EXPORT_نښه_FLAGS_WEAK_DEFINITION                     0x04

بنية dyld_info_command {
    uint32_t cmd;             /* LC_DYLD_INFO or LC_DYLD_INFO_ONLY */
    uint32_t cmdsize;         /* sizeof(struct dyld_info_command) */
    uint32_t rebase_off;      /* file offset to rebase info  */
    uint32_t rebase_اندازه;     /* size of rebase info   */
    uint32_t bind_off;        /* file offset to binding info   */
    uint32_t bind_اندازه;       /* size of binding info  */
    uint32_t weak_bind_off;   /* file offset to weak binding info   */
    uint32_t weak_bind_اندازه;  /* size of weak binding info  */
    uint32_t lazy_bind_off;   /* file offset to lazy binding info */
    uint32_t lazy_bind_اندازه;  /* size of lazy binding infs */
    uint32_t export_off;      /* file offset to lazy binding info */
    uint32_t export_اندازه;     /* size of lazy binding infs */
};

#تعریف_کړه غیرمستقیم_نښه_LOCAL   0x80000000

بنية ثبت_ټکی_command {
    uint32_t  cmd;      /* LC_MAIN only used in MH_EXECUTE filetypes */
    uint32_t  cmdsize;  /* 24 */
    uint64_t  entryoff; /* file (__TEXT) offset of main() */
    uint64_t  stacksize;/* if not zero, initial stack size */
};

تعداد skind {
    sk_unknown = 0,
    sk_discard,
    sk_متن,
    sk_stubs,
    sk_stub_helper,
    sk_ro_معلومات,
    sk_uw_info,
    sk_nl_ptr,  // non-lazy pointers, aka GOT
    sk_debug_info,
    sk_debug_abbrev,
    sk_debug_کرښه,
    sk_debug_aranges,
    sk_debug_str,
    sk_debug_کرښه_str,
    sk_stab,
    sk_stab_str,
    sk_la_ptr,  // lazy pointers
    sk_init,
    sk_fini,
    sk_rw_معلومات,
    sk_bss,
    sk_linkedit,
    sk_وروستی
};

بنية nlist_64 {
    uint32_t  n_strx;      /* index into the string table */
    uint8_t n_type;        /* type flag, see below */
    uint8_t n_sect;        /* section number or NO_SECT */
    uint16_t n_desc;       /* see <mach-o/stab.h> */
    uint64_t n_ارزښت;      /* value of this symbol (or stab offset) */
};

#تعریف_کړه N_UNDF  0x0
#تعریف_کړه N_ABS   0x2
#تعریف_کړه N_EXT   0x1
#تعریف_کړه N_SECT  0xe

#تعریف_کړه N_WEAK_REF      0x0040
#تعریف_کړه N_WEAK_DEF      0x0080

بنية macho {
    بنية mach_سرلیک_64 mh;
    صحيح *seg2lc, nseg;
    بنية بارول_command **lc;
    بنية ثبت_ټکی_command *ep;
    صحيح nlc;
    بنية {
        Section *s;
        صحيح machosect;
    } sk_منزل_sect[sk_وروستی];
    صحيح *elfsectomacho;
    صحيح *e2msym;
    Section *symtab, *strtab, *indirsyms, *stubs, *exports;
    uint32_t ilocal, iextdef, iundef;
    صحيح stubsym, n_got, nr_plt;
    صحيح segment[sk_وروستی];
#که_تعریف_شوی CONFIG_NEW_MACHO
    Section *chained_fixups;
    صحيح n_bind;
    صحيح n_bind_rebase;
    بنية bind_rebase {
	صحيح section;
	صحيح bind;
	ElfW_Rel rel;
    } *bind_rebase;
#وإلا
    Section *rebase, *binding, *weak_binding, *lazy_binding;
    Section *stub_helper, *la_نښه_ptr;
    بنية dyld_info_command *dyldinfo;
    صحيح helpsym, lasym, dyld_شخصي, dyld_stub_binder;
    صحيح n_lazy_bind;    
    بنية s_lazy_bind {
        صحيح section;
        صحيح bind_دننه_واټن;
        صحيح la_نښه_دننه_واټن;
        ElfW_Rel rel;
    } *s_lazy_bind;
    صحيح n_rebase;    
    بنية s_rebase {
        صحيح section;
        ElfW_Rel rel;
    } *s_rebase;
    صحيح n_bind; 
    بنية bind {
        صحيح section;
        ElfW_Rel rel;
    } *bind;
#د_که_پای
};

#تعریف_کړه SHT_LINKEDIT (SHT_LOOS + 42)
#تعریف_کړه SHN_FROMDLL  (SHN_LOOS + 2)  /* Symbol is undefined, comes from a DLL */

ساكن فراغ * جمع_کړه_lc(بنية macho *mo, uint32_t cmd, uint32_t cmdsize)
{
    بنية بارول_command *lc = tcc_mallocz(cmdsize);
    lc->cmd = cmd;
    lc->cmdsize = cmdsize;
    mo->lc = tcc_realloc(mo->lc, حجم(mo->lc[0]) * (mo->nlc + 1));
    mo->lc[mo->nlc++] = lc;
    أرجع lc;
}

ساكن بنية segment_command_64 * جمع_کړه_segment(بنية macho *mo, ثابت حرف *name)
{
    بنية segment_command_64 *sc = جمع_کړه_lc(mo, LC_SEGMENT_64, حجم(*sc));
    strncpy(sc->segname, name, 16);
    mo->seg2lc = tcc_realloc(mo->seg2lc, حجم(*mo->seg2lc) * (mo->nseg + 1));
    mo->seg2lc[mo->nseg++] = mo->nlc - 1;
    أرجع sc;
}

ساكن بنية segment_command_64 * get_segment(بنية macho *mo, صحيح i)
{
    أرجع (بنية segment_command_64 *) (mo->lc[mo->seg2lc[i]]);
}

ساكن صحيح جمع_کړه_section(بنية macho *mo, بنية segment_command_64 **_seg, ثابت حرف *name)
{
    بنية segment_command_64 *seg = *_seg;
    صحيح ret = seg->nsects;
    بنية section_64 *sec;
    seg->nsects++;
    seg->cmdsize += حجم(*sec);
    seg = tcc_realloc(seg, حجم(*seg) + seg->nsects * حجم(*sec));
    sec = (بنية section_64*)((حرف*)seg + حجم(*seg)) + ret;
    memset(sec, 0, حجم(*sec));
    strncpy(sec->sectname, name, 16);
    strncpy(sec->segname, seg->segname, 16);
    *_seg = seg;
    أرجع ret;
}

ساكن بنية section_64 *get_section(بنية segment_command_64 *seg, صحيح i)
{
    أرجع (بنية section_64*)((حرف*)seg + حجم(*seg)) + i;
}

ساكن فراغ * جمع_کړه_dylib(بنية macho *mo, حرف *name)
{
    بنية dylib_command *lc;
    صحيح sz = (حجم(*lc) + مزي_اوږدوالی(name) + 1 + 7) & -8;
    lc = جمع_کړه_lc(mo, LC_بارول_DYLIB, sz);
    lc->name = حجم(*lc);
    strcpy((حرف*)lc + lc->name, name);
    lc->timestamp = 2;
    lc->current_نسخه = 1 << 16;
    lc->compatibility_نسخه = 1 << 16;
    أرجع lc;
}

ساكن صحيح uleb128_اندازه (بینښه اوږد اوږد ارزښت)
{
    صحيح اندازه =  0;

    افعل {
        ارزښت >>= 7;
        اندازه++;
    } طالما (ارزښت != 0);
    أرجع اندازه;
}

ساكن فراغ write_uleb128(Section *section, uint64_t ارزښت)
{
    افعل {
        بینښه حرف byte = ارزښت & 0x7f;
	uint8_t *ptr = section_ptr_جمع_کړه(section, 1);

        ارزښت >>= 7;
        *ptr = byte | (ارزښت ? 0x80 : 0);
    } طالما (ارزښت != 0);
}

ساكن فراغ tcc_macho_جمع_کړه_destructor(TCCState *s1)
{
    صحيح init_sym, mh_execute_سرلیک, at_exit_sym;
    Section *s;
    ElfW_Rel *rel;
    uint8_t *ptr;

    mh_execute_سرلیک = put_elf_sym(s1->symtab, -4096, 0,
				    ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				    متن_section->sh_عدد, "__mh_execute_header");
    s = پیدا_کړه_section(s1, ".fini_array");
    إذا (s->معلومات_دننه_واټن == 0)
        أرجع; 
    init_sym = put_elf_sym(s1->symtab, متن_section->معلومات_دننه_واټن, 0,
                           ELFW(ST_INFO)(STB_LOCAL, STT_FUNC), 0,
                           متن_section->sh_عدد, "___GLOBAL_init_65535");
    at_exit_sym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0,
                              SHN_UNDEF, "___cxa_atexit");
#که_تعریف_شوی TCC_موخه_X86_64
    ptr = section_ptr_جمع_کړه(متن_section, 4);
    ptr[0] = 0x55;  // pushq   %rbp
    ptr[1] = 0x48;  // movq    %rsp, %rbp
    ptr[2] = 0x89;
    ptr[3] = 0xe5;
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        صحيح sym_شاخص = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_جمع_کړه(متن_section, 26);
        ptr[0] = 0x48;  // lea destructor(%rip),%rax
        ptr[1] = 0x8d;
        ptr[2] = 0x05;
        put_elf_reloca(s1->symtab, متن_section, 
		       متن_section->معلومات_دننه_واټن - 23,
		       R_X86_64_PC32, sym_شاخص, -4);
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
        put_elf_reloca(s1->symtab, متن_section,
		       متن_section->معلومات_دننه_واټن - 9,
		       R_X86_64_PC32, mh_execute_سرلیک, -4);
	ptr[21] = 0xe8; // call __cxa_atexit
        put_elf_reloca(s1->symtab, متن_section,
		       متن_section->معلومات_دننه_واټن - 4,
		       R_X86_64_PLT32, at_exit_sym, -4);
    }
    ptr = section_ptr_جمع_کړه(متن_section, 2);
    ptr[0] = 0x5d;  // pop   %rbp
    ptr[1] = 0xc3;  // ret
#وإلاإذا defined TCC_موخه_ARM64
    ptr = section_ptr_جمع_کړه(متن_section, 8);
    write32le(ptr, 0xa9bf7bfd);     // stp     x29, x30, [sp, #-16]!
    write32le(ptr + 4, 0x910003fd); // mov     x29, sp
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        صحيح sym_شاخص = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_جمع_کړه(متن_section, 24);
        put_elf_reloc(s1->symtab, متن_section, 
		      متن_section->معلومات_دننه_واټن - 24,
		      R_AARCH64_ADR_PREL_PG_HI21, sym_شاخص);
        write32le(ptr, 0x90000000);      // adrp x0, destructor@page
        put_elf_reloc(s1->symtab, متن_section,
		      متن_section->معلومات_دننه_واټن - 20,
		      R_AARCH64_LDST8_ABS_LO12_NC, sym_شاخص);
        write32le(ptr + 4, 0x91000000);  // add x0,x0,destructor@pageoff
        write32le(ptr + 8, 0xd2800001);  // mov x1, #0
        put_elf_reloc(s1->symtab, متن_section, 
		      متن_section->معلومات_دننه_واټن - 12,
		      R_AARCH64_ADR_PREL_PG_HI21, mh_execute_سرلیک);
        write32le(ptr + 12, 0x90000002);      // adrp x2, mh_execute_header@page
        put_elf_reloc(s1->symtab, متن_section,
		      متن_section->معلومات_دننه_واټن - 8,
		      R_AARCH64_LDST8_ABS_LO12_NC, mh_execute_سرلیک);
        write32le(ptr + 16, 0x91000042);  // add x2,x2,mh_execute_header@pageoff
        put_elf_reloc(s1->symtab, متن_section,
		      متن_section->معلومات_دننه_واټن - 4,
		      R_AARCH64_CALL26, at_exit_sym);
	write32le(ptr + 20, 0x94000000); // bl __cxa_atexit
    }
    ptr = section_ptr_جمع_کړه(متن_section, 8);
    write32le(ptr, 0xa8c17bfd);     // ldp     x29, x30, [sp], #16
    write32le(ptr + 4, 0xd65f03c0); // ret
#د_که_پای
    s->reloc->معلومات_دننه_واټن = s->معلومات_دننه_واټن = 0;
    s->sh_flags &= ~SHF_ALLOC;
    جمع_کړه_array (s1, ".init_array", init_sym);
}

#که_تعریف_شوی CONFIG_NEW_MACHO
ساكن فراغ bind_rebase_جمع_کړه(بنية macho *mo, صحيح bind, صحيح sh_info,
			    ElfW_Rel *rel, بنية sym_attr *attr)
{
    mo->bind_rebase = tcc_realloc(mo->bind_rebase, (mo->n_bind_rebase + 1) *
		                  حجم(بنية bind_rebase));
    mo->bind_rebase[mo->n_bind_rebase].section = sh_info;
    mo->bind_rebase[mo->n_bind_rebase].bind = bind;
    mo->bind_rebase[mo->n_bind_rebase].rel = *rel;
    إذا (attr)
        mo->bind_rebase[mo->n_bind_rebase].rel.r_دننه_واټن = attr->got_دننه_واټن;
    mo->n_bind_rebase++;
    mo->n_bind += bind;
}

ساكن فراغ check_relocs(TCCState *s1, بنية macho *mo)
{
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    صحيح i, j, type, gotplt_ثبت, sym_شاخص, for_کوډ;
    uint32_t *pi, *goti;
    بنية sym_attr *attr;

    goti = عدم;
    mo->nr_plt = mo->n_got = 0;
    لكل (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        إذا (s->sh_type != SHT_RELX ||
	    !مزي_پرتله(s1->sections[s->sh_info]->name, ".debug_", 7))
            استمر;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_ثبت = gotplt_ثبت_type(type);
            for_کوډ = کوډ_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_شاخص = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
            إذا (sym->st_shndx == SHN_UNDEF
                || gotplt_ثبت == ALWAYS_GOTPLT_ثبت) {
                attr = get_sym_attr(s1, sym_شاخص, 1);
                إذا (!attr->dyn_شاخص) {
                    attr->got_دننه_واټن = s1->got->معلومات_دننه_واټن;
                    attr->plt_دننه_واټن = -1;
                    attr->dyn_شاخص = 1; /* used as flag */
                    section_ptr_جمع_کړه(s1->got, PTR_اندازه);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_دننه_واټن,
                                  R_JMP_خونه, sym_شاخص);
	 	    goti = tcc_realloc(goti, (mo->n_got + 1) * حجم(*goti));
                    إذا (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        إذا (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (حرف *) symtab_section->link->معلومات + sym->st_name);
			goti[mo->n_got++] = غیرمستقیم_نښه_LOCAL;
                    } وإلا {
                        goti[mo->n_got++] = mo->e2msym[sym_شاخص];
                        إذا (sym->st_shndx == SHN_UNDEF
#که_تعریف_شوی TCC_موخه_X86_64
                            && type == R_X86_64_GOTPCREL
#وإلاإذا defined TCC_موخه_ARM64
                            && type == R_AARCH64_ADR_GOT_پاڼه
#د_که_پای
                            ) {
			    attr->plt_دننه_واټن = -mo->n_bind_rebase - 2;
			    bind_rebase_جمع_کړه(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
			    s1->got->reloc->معلومات_دننه_واټن -= حجم (ElfW_Rel);
			}
		        إذا (for_کوډ && sym->st_shndx == SHN_UNDEF)
			    s1->got->reloc->معلومات_دننه_واټن -= حجم (ElfW_Rel);
		    }
                }
                إذا (for_کوډ && sym->st_shndx == SHN_UNDEF) {
		    إذا ((صحيح)attr->plt_دننه_واټن < -1) {
			/* remove above bind and replace with plt */
			mo->bind_rebase[-attr->plt_دننه_واټن - 2].bind = 2;
			attr->plt_دننه_واټن = -1;
		    }
                    إذا (attr->plt_دننه_واټن == -1) {
                        uint8_t *jmp;

                        attr->plt_دننه_واټن = mo->stubs->معلومات_دننه_واټن;
#که_تعریف_شوی TCC_موخه_X86_64
                        إذا (type != R_X86_64_PLT32)
                             استمر;
                        jmp = section_ptr_جمع_کړه(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *ofs(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_دننه_واټن + 2,
                                      R_X86_64_GOTPCREL, sym_شاخص);
#وإلاإذا defined TCC_موخه_ARM64
                        إذا (type != R_AARCH64_CALL26)
                             استمر;
                        jmp = section_ptr_جمع_کړه(mo->stubs, 12);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_دننه_واټن,
                                      R_AARCH64_ADR_GOT_پاڼه, sym_شاخص);
                        write32le(jmp, // adrp x16, #sym
                                  0x90000010);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_دننه_واټن + 4,
                                      R_AARCH64_LD64_GOT_LO12_NC, sym_شاخص);
                        write32le(jmp + 4, // ld x16,[x16, #sym]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);
#د_که_پای
			bind_rebase_جمع_کړه(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
                        pi = section_ptr_جمع_کړه(mo->indirsyms, حجم(*pi));
                        *pi = mo->e2msym[sym_شاخص];
                        mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_دننه_واټن;
                }
            }
	    إذا (type == R_معلومات_PTR || type == R_JMP_خونه)
		bind_rebase_جمع_کړه(mo, sym->st_shndx == SHN_UNDEF ? 1 : 0,
				s->sh_info, &save_rel, عدم);
        }
    }
    /* remove deleted binds */
    لكل (i = 0, j = 0; i < mo->n_bind_rebase; i++)
	إذا (mo->bind_rebase[i].bind == 2)
	    mo->n_bind--;
	وإلا
	    mo->bind_rebase[j++] = mo->bind_rebase[i];
    mo->n_bind_rebase = j;
    pi = section_ptr_جمع_کړه(mo->indirsyms, mo->n_got * حجم(*pi));
    حافظه_نقل(pi, goti, mo->n_got * حجم(*pi));
    tcc_free(goti);
}

#وإلا

ساكن فراغ check_relocs(TCCState *s1, بنية macho *mo)
{
    uint8_t *jmp;
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    صحيح i, type, gotplt_ثبت, sym_شاخص, for_کوډ;
    صحيح bind_دننه_واټن, la_نښه_دننه_واټن;
    uint32_t *pi, *goti;
    بنية sym_attr *attr;

#که_تعریف_شوی TCC_موخه_X86_64
    jmp = section_ptr_جمع_کړه(mo->stub_helper, 16);
    jmp[0] = 0x4c;  /* leaq _dyld_private(%rip), %r11 */
    jmp[1] = 0x8d;
    jmp[2] = 0x1d;
    put_elf_reloca(s1->symtab, mo->stub_helper, 3,
		   R_X86_64_PC32, mo->dyld_شخصي, -4);
    jmp[7] = 0x41;  /* pushq %r11 */
    jmp[8] = 0x53;
    jmp[9] = 0xff;  /* jmpq    *dyld_stub_binder@GOT(%rip) */
    jmp[10] = 0x25;
    put_elf_reloca(s1->symtab, mo->stub_helper, 11,
		   R_X86_64_GOTPCREL, mo->dyld_stub_binder, -4);
    jmp[15] = 0x90; /* nop */
#وإلاإذا defined TCC_موخه_ARM64
    jmp = section_ptr_جمع_کړه(mo->stub_helper, 24);
    put_elf_reloc(s1->symtab, mo->stub_helper, 0,
		  R_AARCH64_ADR_PREL_PG_HI21, mo->dyld_شخصي);
    write32le(jmp, 0x90000011); // adrp x17, _dyld_private@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 4,
		  R_AARCH64_LDST64_ABS_LO12_NC, mo->dyld_شخصي);
    write32le(jmp + 4, 0x91000231); // add x17,x17,_dyld_private@pageoff
    write32le(jmp + 8, 0xa9bf47f0); // stp x16/x17, [sp, #-16]!
    put_elf_reloc(s1->symtab, mo->stub_helper, 12,
		  R_AARCH64_ADR_GOT_پاڼه, mo->dyld_stub_binder);
    write32le(jmp + 12, 0x90000010); // adrp x16, dyld_stub_binder@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 16,
		  R_AARCH64_LD64_GOT_LO12_NC, mo->dyld_stub_binder);
    write32le(jmp + 16, 0xf9400210); // ldr x16,[x16,dyld_stub_binder@pageoff]
    write32le(jmp + 20, 0xd61f0200); // br x16
#د_که_پای
    
    goti = عدم;
    mo->nr_plt = mo->n_got = 0;
    لكل (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        إذا (s->sh_type != SHT_RELX ||
	    !مزي_پرتله(s1->sections[s->sh_info]->name, ".debug_", 7))
            استمر;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_ثبت = gotplt_ثبت_type(type);
            for_کوډ = کوډ_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_شاخص = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
            إذا (sym->st_shndx == SHN_UNDEF
                || gotplt_ثبت == ALWAYS_GOTPLT_ثبت) {
                attr = get_sym_attr(s1, sym_شاخص, 1);
                إذا (!attr->dyn_شاخص) {
                    attr->got_دننه_واټن = s1->got->معلومات_دننه_واټن;
                    attr->plt_دننه_واټن = -1;
                    attr->dyn_شاخص = 1; /* used as flag */
		    section_ptr_جمع_کړه(s1->got, PTR_اندازه);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_دننه_واټن,
                                  R_JMP_خونه, sym_شاخص);
		    goti = tcc_realloc(goti, (mo->n_got + 1) * حجم(*goti));
                    إذا (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        إذا (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (حرف *) symtab_section->link->معلومات + sym->st_name);
			goti[mo->n_got++] = غیرمستقیم_نښه_LOCAL;
                    } وإلا {
			goti[mo->n_got++] = mo->e2msym[sym_شاخص];
			إذا (sym->st_shndx == SHN_UNDEF
#که_تعریف_شوی TCC_موخه_X86_64
			    && type == R_X86_64_GOTPCREL
#وإلاإذا defined TCC_موخه_ARM64
			    && type == R_AARCH64_ADR_GOT_پاڼه
#د_که_پای
			    ) {
			    mo->bind =
			        tcc_realloc(mo->bind,
					    (mo->n_bind + 1) *
					    حجم(بنية bind));
			    mo->bind[mo->n_bind].section = s1->got->reloc->sh_info;
			    mo->bind[mo->n_bind].rel = save_rel;
                            mo->bind[mo->n_bind].rel.r_دننه_واټن = attr->got_دننه_واټن;
			    mo->n_bind++;
			    s1->got->reloc->معلومات_دننه_واټن -= حجم (ElfW_Rel);
			}
		    }
                }
                إذا (for_کوډ && sym->st_shndx == SHN_UNDEF) {
                    إذا (attr->plt_دننه_واټن == -1) {
                        attr->plt_دننه_واټن = mo->stubs->معلومات_دننه_واټن;
#که_تعریف_شوی TCC_موخه_X86_64
			إذا (type != R_X86_64_PLT32)
			     استمر;
			/* __stubs */
                        jmp = section_ptr_جمع_کړه(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *__la_symbol_ptr(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->معلومات_دننه_واټن - 4,
                                       R_X86_64_PC32, mo->lasym,
				       mo->la_نښه_ptr->معلومات_دننه_واټن - 4);

			/* __stub_helper */
			bind_دننه_واټن = mo->stub_helper->معلومات_دننه_واټن + 1;
                        jmp = section_ptr_جمع_کړه(mo->stub_helper, 10);
                        jmp[0] = 0x68;  /* pushq $bind_offset */
                        jmp[5] = 0xe9;  /* jmpq __stub_helper */
                        write32le(jmp + 6, -mo->stub_helper->معلومات_دننه_واټن);

			/* __la_symbol_ptr */
			la_نښه_دننه_واټن = mo->la_نښه_ptr->معلومات_دننه_واټن;
                        put_elf_reloca(s1->symtab, mo->la_نښه_ptr,
				       mo->la_نښه_ptr->معلومات_دننه_واټن,
				       R_معلومات_PTR, mo->helpsym,
				       mo->stub_helper->معلومات_دننه_واټن - 10);
			section_ptr_جمع_کړه(mo->la_نښه_ptr, PTR_اندازه);
#وإلاإذا defined TCC_موخه_ARM64
			إذا (type != R_AARCH64_CALL26)
			     استمر;
			/* __stubs */
                        jmp = section_ptr_جمع_کړه(mo->stubs, 12);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->معلومات_دننه_واټن - 12,
                                       R_AARCH64_ADR_PREL_PG_HI21, mo->lasym,
				       mo->la_نښه_ptr->معلومات_دننه_واټن);
                        write32le(jmp, // adrp x16, __la_symbol_ptr@page
                                  0x90000010);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->معلومات_دننه_واټن - 8,
                                       R_AARCH64_LDST64_ABS_LO12_NC, mo->lasym,
				       mo->la_نښه_ptr->معلومات_دننه_واټن);
                        write32le(jmp + 4, // ldr x16,[x16, __la_symbol_ptr@pageoff]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);

			/* __stub_helper */
			bind_دننه_واټن = mo->stub_helper->معلومات_دننه_واټن + 8;
                        jmp = section_ptr_جمع_کړه(mo->stub_helper, 12);
                        write32le(jmp + 0, // ldr  w16, l0
                                  0x18000050);
                        write32le(jmp + 4, // b stubHelperHeader
                                  0x14000000 +
				  ((-(mo->stub_helper->معلومات_دننه_واټن - 8) / 4) &
				   0x3ffffff));
                        write32le(jmp + 8, 0); // l0: .long bind_offset

			/* __la_symbol_ptr */
			la_نښه_دننه_واټن = mo->la_نښه_ptr->معلومات_دننه_واټن;
                        put_elf_reloca(s1->symtab, mo->la_نښه_ptr,
				       mo->la_نښه_ptr->معلومات_دننه_واټن,
				       R_معلومات_PTR, mo->helpsym,
				       mo->stub_helper->معلومات_دننه_واټن - 12);
			section_ptr_جمع_کړه(mo->la_نښه_ptr, PTR_اندازه);
#د_که_پای
                        mo->s_lazy_bind =
                            tcc_realloc(mo->s_lazy_bind, (mo->n_lazy_bind + 1) *
                                        حجم(بنية s_lazy_bind));
                        mo->s_lazy_bind[mo->n_lazy_bind].section =
                            mo->stub_helper->reloc->sh_info;
                        mo->s_lazy_bind[mo->n_lazy_bind].bind_دننه_واټن =
			    bind_دننه_واټن;
                        mo->s_lazy_bind[mo->n_lazy_bind].la_نښه_دننه_واټن =
			    la_نښه_دننه_واټن;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel = save_rel;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel.r_دننه_واټن =
                            attr->plt_دننه_واټن;
                        mo->n_lazy_bind++;
			pi = section_ptr_جمع_کړه(mo->indirsyms, حجم(*pi));
			*pi = mo->e2msym[sym_شاخص];
			mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_دننه_واټن;
                }
            }
            إذا (type == R_معلومات_PTR || type == R_JMP_خونه) {
		إذا (sym->st_shndx == SHN_UNDEF) {
		    mo->bind = tcc_realloc(mo->bind,
					   (mo->n_bind + 1) *
					   حجم(بنية bind));
		    mo->bind[mo->n_bind].section = s->sh_info;
		    mo->bind[mo->n_bind].rel = save_rel;
		    mo->n_bind++;
		}
		وإلا {
                    mo->s_rebase =
                        tcc_realloc(mo->s_rebase, (mo->n_rebase + 1) *
				    حجم(بنية s_rebase));
                    mo->s_rebase[mo->n_rebase].section = s->sh_info;
                    mo->s_rebase[mo->n_rebase].rel = save_rel;
                    mo->n_rebase++;
		}
	    }
        }
    }
    pi = section_ptr_جمع_کړه(mo->indirsyms, mo->n_got * حجم(*pi));
    حافظه_نقل(pi, goti, mo->n_got * حجم(*pi));
    pi = section_ptr_جمع_کړه(mo->indirsyms, mo->nr_plt * حجم(*pi));
    حافظه_نقل(pi, mo->indirsyms->معلومات, mo->nr_plt * حجم(*pi));
    tcc_free(goti);
}
#د_که_پای

ساكن صحيح check_symbols(TCCState *s1, بنية macho *mo)
{
    صحيح sym_شاخص, sym_پای_ټکی;
    صحيح ret = 0;

    mo->ilocal = mo->iextdef = mo->iundef = -1;
    sym_پای_ټکی = symtab_section->معلومات_دننه_واټن / حجم(ElfW(Sym));
    لكل (sym_شاخص = 1; sym_شاخص < sym_پای_ټکی; ++sym_شاخص) {
        صحيح elf_شاخص = ((بنية nlist_64 *)mo->symtab->معلومات + sym_شاخص - 1)->n_ارزښت;
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->معلومات + elf_شاخص;
        ثابت حرف *name = (حرف*)symtab_section->link->معلومات + sym->st_name;
        بینښه type = ELFW(ST_TYPE)(sym->st_info);
        بینښه bind = ELFW(ST_BIND)(sym->st_info);
        بینښه vis  = ELFW(ST_VISIBILITY)(sym->st_other);

        dprintf("%4d (%4d): %09lx %4d %4d %4d %3d %s\n",
                sym_شاخص, elf_شاخص, (اوږد)sym->st_ارزښت,
                type, bind, vis, sym->st_shndx, name);
        إذا (bind == STB_LOCAL) {
            إذا (mo->ilocal == -1)
              mo->ilocal = sym_شاخص - 1;
            إذا (mo->iextdef != -1 || mo->iundef != -1)
              tcc_error("local syms after global ones");
        } وإلا إذا (sym->st_shndx != SHN_UNDEF) {
            إذا (mo->iextdef == -1)
              mo->iextdef = sym_شاخص - 1;
            إذا (mo->iundef != -1)
              tcc_error("external defined symbol after undefined");
        } وإلا إذا (sym->st_shndx == SHN_UNDEF) {
            إذا (mo->iundef == -1)
              mo->iundef = sym_شاخص - 1;
            إذا (ELFW(ST_BIND)(sym->st_info) == STB_WEAK
		|| s1->output_type != TCC_OUTPUT_EXE
                || پیدا_کړه_elf_sym(s1->dynsymtab_section, name)) {
                /* Mark the symbol as coming from a dylib so that
                   relocate_syms doesn't complain.  Normally bind_exe_dynsyms
                   would do this check, and place the symbol into dynsym
                   which is checked by relocate_syms.  But Mach-O doesn't use
                   bind_exe_dynsyms.  */
                sym->st_shndx = SHN_FROMDLL;
                استمر;
            }
            tcc_error_noabort("unresolved reference to '%s'", name);
            ret = -1;
        }
    }
    أرجع ret;
}

ساكن فراغ convert_نښه(TCCState *s1, بنية macho *mo, بنية nlist_64 *pn)
{
    بنية nlist_64 n = *pn;
    ElfSym *sym = (ElfW(Sym) *)symtab_section->معلومات + pn->n_ارزښت;
    ثابت حرف *name = (حرف*)symtab_section->link->معلومات + sym->st_name;
    بدل(ELFW(ST_TYPE)(sym->st_info)) {
    حالة STT_NOTYPE:
    حالة STT_OBJECT:
    حالة STT_FUNC:
    حالة STT_TLS:
    حالة STT_SECTION:
        n.n_type = N_SECT;
        اكسر;
    حالة STT_FILE:
        n.n_type = N_ABS;
        اكسر;
    افتراضي:
        tcc_error("unhandled ELF symbol type %d %s",
                  ELFW(ST_TYPE)(sym->st_info), name);
    }
    إذا (sym->st_shndx == SHN_UNDEF)
      tcc_error("should have been rewritten to SHN_FROMDLL: %s", name);
    وإلا إذا (sym->st_shndx == SHN_FROMDLL)
      n.n_type = N_UNDF, n.n_sect = 0;
    وإلا إذا (sym->st_shndx == SHN_ABS)
      n.n_type = N_ABS, n.n_sect = 0;
    وإلا إذا (sym->st_shndx >= SHN_LORESERVE)
      tcc_error("unhandled ELF symbol section %d %s", sym->st_shndx, name);
    وإلا إذا (!mo->elfsectomacho[sym->st_shndx]) {
      إذا (مزي_پرتله(s1->sections[sym->st_shndx]->name, ".debug_", 7))
        tcc_error("ELF section %d(%s) not mapped into Mach-O for symbol %s",
                  sym->st_shndx, s1->sections[sym->st_shndx]->name, name);
    }
    وإلا
      n.n_sect = mo->elfsectomacho[sym->st_shndx];
    إذا (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL)
      n.n_type |=  N_EXT;
    وإلا إذا (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
      n.n_desc |= N_WEAK_REF | (n.n_type != N_UNDF ? N_WEAK_DEF : 0);
    n.n_strx = pn->n_strx;
    n.n_ارزښت = sym->st_ارزښت;
    *pn = n;
}

ساكن فراغ convert_symbols(TCCState *s1, بنية macho *mo)
{
    بنية nlist_64 *pn;
    for_each_elem(mo->symtab, 0, pn, بنية nlist_64)
        convert_نښه(s1, mo, pn);
}

ساكن صحيح machosymcmp(ثابت فراغ *_a, ثابت فراغ *_b, فراغ *arg)
{
    TCCState *s1 = arg;
    صحيح ea = ((بنية nlist_64 *)_a)->n_ارزښت;
    صحيح eb = ((بنية nlist_64 *)_b)->n_ارزښت;
    ElfSym *sa = (ElfSym *)symtab_section->معلومات + ea;
    ElfSym *sb = (ElfSym *)symtab_section->معلومات + eb;
    صحيح r;
    /* locals, then defined externals, then undefined externals, the
       last two sections also by name, otherwise stable sort */
    r = (ELFW(ST_BIND)(sb->st_info) == STB_LOCAL)
        - (ELFW(ST_BIND)(sa->st_info) == STB_LOCAL);
    إذا (r)
      أرجع r;
    r = (sa->st_shndx == SHN_UNDEF) - (sb->st_shndx == SHN_UNDEF);
    إذا (r)
      أرجع r;
    إذا (ELFW(ST_BIND)(sa->st_info) != STB_LOCAL) {
        ثابت حرف * na = (حرف*)symtab_section->link->معلومات + sa->st_name;
        ثابت حرف * nb = (حرف*)symtab_section->link->معلومات + sb->st_name;
        r = strcmp(na, nb);
        إذا (r)
          أرجع r;
    }
    أرجع ea - eb;
}

/* cannot use qsort because code has to be reentrant */
ساكن فراغ tcc_qsort (فراغ  *بنسټ, اندازه_t nel, اندازه_t پلنوالی,
                       صحيح (*comp)(ثابت فراغ *, ثابت فراغ *, فراغ *), فراغ *arg)
{
    اندازه_t wnel, gap, wgap, i, j, k;
    حرف *a, *b, tmp;

    wnel = پلنوالی * nel;
    لكل (gap = 0; ++gap < nel;)
        gap *= 3;
    طالما ( gap /= 3 ) {
        wgap = پلنوالی * gap;
        لكل (i = wgap; i < wnel; i += پلنوالی) {
            لكل (j = i - wgap; ;j -= wgap) {
                a = j + (حرف *)بنسټ;
                b = a + wgap;
                إذا ( (*comp)(a, b, arg) <= 0 )
                    اكسر;
                k = پلنوالی;
                افعل {
                    tmp = *a;
                    *a++ = *b;
                    *b++ = tmp;
                } طالما ( --k );
                إذا (j < wgap)
                    اكسر;
            }
        }
    }
}

ساكن فراغ create_symtab(TCCState *s1, بنية macho *mo)
{
    صحيح sym_شاخص, sym_پای_ټکی;
    بنية nlist_64 *pn;

    /* Stub creation belongs to check_relocs, but we need to create
       the symbol now, so its included in the sorting.  */
    mo->stubs = new_section(s1, "__stubs", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->stubsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stubs->sh_عدد, ".__stubs");
#که_تعریف_شوی CONFIG_NEW_MACHO
    mo->chained_fixups = new_section(s1, "CHAINED_FIXUPS",
				     SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#وإلا
    mo->stub_helper = new_section(s1, "__stub_helper", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    mo->la_نښه_ptr = new_section(s1, "__la_symbol_ptr", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->helpsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stub_helper->sh_عدد, ".__stub_helper");
    mo->lasym = put_elf_sym(s1->symtab, 0, 0,
                            ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                            mo->la_نښه_ptr->sh_عدد, ".__la_symbol_ptr");
    section_ptr_جمع_کړه(معلومات_section, -معلومات_section->معلومات_دننه_واټن & (PTR_اندازه - 1));
    mo->dyld_شخصي = put_elf_sym(s1->symtab, معلومات_section->معلومات_دننه_واټن, PTR_اندازه,
                                   ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT), 0,
                                   معلومات_section->sh_عدد, ".__dyld_private");
    section_ptr_جمع_کړه(معلومات_section, PTR_اندازه);
    mo->dyld_stub_binder = put_elf_sym(s1->symtab, 0, 0,
                		       ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				       SHN_UNDEF, "dyld_stub_binder");
    mo->rebase = new_section(s1, "REBASE", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->binding = new_section(s1, "BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->weak_binding = new_section(s1, "WEAK_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->lazy_binding = new_section(s1, "LAZY_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#د_که_پای
    mo->exports = new_section(s1, "EXPORT", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->indirsyms = new_section(s1, "LEINDIR", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);

    mo->symtab = new_section(s1, "LESYMTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->strtab = new_section(s1, "LESTRTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    put_elf_str(mo->strtab, " "); /* Mach-O starts strtab with a space */
    sym_پای_ټکی = symtab_section->معلومات_دننه_واټن / حجم(ElfW(Sym));
    pn = section_ptr_جمع_کړه(mo->symtab, حجم(*pn) * (sym_پای_ټکی - 1));
    لكل (sym_شاخص = 1; sym_شاخص < sym_پای_ټکی; ++sym_شاخص) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->معلومات + sym_شاخص;
        ثابت حرف *name = (حرف*)symtab_section->link->معلومات + sym->st_name;
        pn[sym_شاخص - 1].n_strx = put_elf_str(mo->strtab, name);
        pn[sym_شاخص - 1].n_ارزښت = sym_شاخص;
    }
    section_ptr_جمع_کړه(mo->strtab, -mo->strtab->معلومات_دننه_واټن & (PTR_اندازه - 1));
    tcc_qsort(pn, sym_پای_ټکی - 1, حجم(*pn), machosymcmp, s1);
    mo->e2msym = tcc_malloc(sym_پای_ټکی * حجم(*mo->e2msym));
    mo->e2msym[0] = -1;
    لكل (sym_شاخص = 1; sym_شاخص < sym_پای_ټکی; ++sym_شاخص) {
        mo->e2msym[pn[sym_شاخص - 1].n_ارزښت] = sym_شاخص - 1;
    }
}

ثابت بنية {
    صحيح seg_initial;
    uint32_t flags;
    ثابت حرف *name;
} skinfo[sk_وروستی] = {
    /*[sk_unknown] =*/        { 0 },
    /*[sk_discard] =*/        { 0 },
    /*[sk_text] =*/           { 1, S_REGULAR | S_ATTR_خالص_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS, "__text" },
    /*[sk_stubs] =*/          { 1, S_REGULAR | S_ATTR_خالص_INSTRUCTIONS | S_نښه_STUBS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stubs" },
    /*[sk_stub_helper] =*/    { 1, S_REGULAR | S_ATTR_خالص_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stub_helper" },
    /*[sk_ro_data] =*/        { 2, S_REGULAR, "__rodata" },
    /*[sk_uw_info] =*/        { 0 },
    /*[sk_nl_ptr] =*/         { 2, S_NON_LAZY_نښه_اشارې, "__got" },
    /*[sk_debug_info] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_info" },
    /*[sk_debug_abbrev] =*/   { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_abbrev" },
    /*[sk_debug_line] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line" },
    /*[sk_debug_aranges] =*/  { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_aranges" },
    /*[sk_debug_str] =*/      { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_str" },
    /*[sk_debug_line_str] =*/ { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line_str" },
    /*[sk_stab] =*/           { 4, S_REGULAR, "__stab" },
    /*[sk_stab_str] =*/       { 4, S_REGULAR, "__stab_str" },
    /*[sk_la_ptr] =*/         { 4, S_LAZY_نښه_اشارې, "__la_symbol_ptr" },
    /*[sk_init] =*/           { 4, S_MOD_INIT_FUNC_اشارې, "__mod_init_func" },
    /*[sk_fini] =*/           { 4, S_MOD_غړی_FUNC_اشارې, "__mod_term_func" },
    /*[sk_rw_data] =*/        { 4, S_REGULAR, "__data" },
    /*[sk_bss] =*/            { 4, S_ZEROFILL, "__bss" },
    /*[sk_linkedit] =*/       { 5, S_REGULAR, عدم },
};

#تعریف_کړه	پیل_3	((uint64_t)1 << 32)

ثابت بنية {
    صحيح کارول_شوی;
    ثابت حرف *name;
    uint64_t vmaddr;
    uint64_t vmsize;
    vm_prot_t maxprot;
    vm_prot_t initprot;
    uint32_t flags;
} all_segment[] = {
    { 1, "__PAGEZERO",       0, پیل_3, 0, 0,            0 },
    { 0, "__TEXT",       پیل_3,     0, 5, 5,            0 },
    { 0, "__DATA_CONST",    -1,     0, 3, 3, SG_READ_ONLY },
    { 0, "__DWARF",         -1,     0, 7, 3,            0 },
    { 0, "__DATA",          -1,     0, 3, 3,            0 },
    { 1, "__LINKEDIT",      -1,     0, 1, 1,            0 },
};

#تعریف_کړه	N_SEGMENT	(حجم(all_segment)/حجم(all_segment[0]))

#که_تعریف_شوی CONFIG_NEW_MACHO
ساكن فراغ calc_fixup_اندازه(TCCState *s1, بنية macho *mo)
{
    صحيح i, اندازه;

    اندازه = (حجم(بنية dyld_chained_fixups_سرلیک) + 7) & -8;
    اندازه += (حجم(بنية dyld_chained_starts_دننه_image) + (mo->nseg - 1) * حجم(uint32_t) + 7) & -8;
    لكل (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	صحيح پاڼه_شمېر = (get_segment(mo, i)->vmsize + SEG_پاڼه_اندازه - 1) / SEG_پاڼه_اندازه;
	اندازه += (حجم(بنية dyld_chained_starts_دننه_segment) + (پاڼه_شمېر - 1) * حجم(uint16_t) + 7) & -8;
    }
    اندازه += mo->n_bind * حجم (بنية dyld_chained_import) + 1;
    لكل (i = 0; i < mo->n_bind_rebase; i++) {
	إذا (mo->bind_rebase[i].bind) {
	    صحيح sym_شاخص = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
	    ثابت حرف *name = (حرف *) symtab_section->link->معلومات + sym->st_name;
	    اندازه += مزي_اوږدوالی(name) + 1;
	}
    }
    اندازه = (اندازه + 7) & -8;
    section_ptr_جمع_کړه(mo->chained_fixups, اندازه);
}

#وإلا

ساكن فراغ سېټ_segment_and_دننه_واټن(TCCState *s1, بنية macho *mo, addr_t addr,
				   uint8_t *ptr, صحيح opcode,
				   Section *sec, addr_t دننه_واټن)
{
    صحيح i;
    بنية segment_command_64 *seg = عدم;

    لكل (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	seg = get_segment(mo, i);
	إذا (addr >= seg->vmaddr && addr < (seg->vmaddr + seg->vmsize))
	    اكسر;
    }
    *ptr = opcode | i;
    write_uleb128(sec, دننه_واټن - seg->vmaddr);
}

ساكن فراغ bind_rebase(TCCState *s1, بنية macho *mo)
{
    صحيح i;
    uint8_t *ptr;
    ElfW(Sym) *sym;
    ثابت حرف *name;

    لكل (i = 0; i < mo->n_lazy_bind; i++) {
	صحيح sym_شاخص = ELFW(R_SYM)(mo->s_lazy_bind[i].rel.r_info);

	sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
	name = (حرف *) symtab_section->link->معلومات + sym->st_name;
	write32le(mo->stub_helper->معلومات +
		  mo->s_lazy_bind[i].bind_دننه_واټن,
		  mo->lazy_binding->معلومات_دننه_واټن);
	ptr = section_ptr_جمع_کړه(mo->lazy_binding, 1);
	سېټ_segment_and_دننه_واټن(s1, mo, mo->la_نښه_ptr->sh_addr, ptr,
			       BIND_OPCODE_سېټ_SEGMENT_AND_دننه_واټن_ULEB,
			       mo->lazy_binding,
			       mo->s_lazy_bind[i].la_نښه_دننه_واټن +
			       mo->la_نښه_ptr->sh_addr);
	ptr = section_ptr_جمع_کړه(mo->lazy_binding, 5 + مزي_اوږدوالی(name));
	*ptr++ = BIND_OPCODE_سېټ_DYLIB_SPECIAL_IMM |
		 (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
	*ptr++ = BIND_OPCODE_سېټ_نښه_TRAILING_FLAGS_IMM | 0;
	strcpy((حرف *)ptr, name);
	ptr += مزي_اوږدوالی(name) + 1;
	*ptr++ = BIND_OPCODE_DO_BIND;
	*ptr = BIND_OPCODE_بشپړ;
    }
    لكل (i = 0; i < mo->n_rebase; i++) {
	Section *s = s1->sections[mo->s_rebase[i].section];

	ptr = section_ptr_جمع_کړه(mo->rebase, 2);
	*ptr++ = REBASE_OPCODE_سېټ_TYPE_IMM | REBASE_TYPE_اشاره_ګر;
	سېټ_segment_and_دننه_واټن(s1, mo, s->sh_addr, ptr,
			       REBASE_OPCODE_سېټ_SEGMENT_AND_دننه_واټن_ULEB,
			       mo->rebase,
			       mo->s_rebase[i].rel.r_دننه_واټن +
			       s->sh_addr);
	ptr = section_ptr_جمع_کړه(mo->rebase, 1);
	*ptr = REBASE_OPCODE_DO_REBASE_IMM_TIMES | 1;
    }
    لكل (i = 0; i < mo->n_bind; i++) {
	صحيح sym_شاخص = ELFW(R_SYM)(mo->bind[i].rel.r_info);
	Section *s = s1->sections[mo->bind[i].section];
	Section *binding;

	sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
	name = (حرف *) symtab_section->link->معلومات + sym->st_name;
	binding = ELFW(ST_BIND)(sym->st_info) == STB_WEAK
	    ? mo->weak_binding : mo->binding;
        ptr = section_ptr_جمع_کړه(binding, 4 + (binding == mo->binding) +
			     	       مزي_اوږدوالی(name));
	إذا (binding == mo->binding)
            *ptr++ = BIND_OPCODE_سېټ_DYLIB_SPECIAL_IMM |
	             (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
        *ptr++ = BIND_OPCODE_سېټ_نښه_TRAILING_FLAGS_IMM |
		 (binding == mo->weak_binding
		  ? BIND_نښه_FLAGS_WEAK_IMPORT : 0);
        strcpy((حرف *)ptr, name);
        ptr += مزي_اوږدوالی(name) + 1;
        *ptr++ = BIND_OPCODE_سېټ_TYPE_IMM | BIND_TYPE_اشاره_ګر;
	سېټ_segment_and_دننه_واټن(s1, mo, s->sh_addr, ptr,
			       BIND_OPCODE_سېټ_SEGMENT_AND_دننه_واټن_ULEB,
			       binding,
			       mo->bind[i].rel.r_دننه_واټن + s->sh_addr);
        ptr = section_ptr_جمع_کړه(binding, 1);
        *ptr++ = BIND_OPCODE_DO_BIND;
    }
    إذا (mo->rebase->معلومات_دننه_واټن) {
        ptr = section_ptr_جمع_کړه(mo->rebase, 1);
        *ptr = REBASE_OPCODE_بشپړ;
    }
    إذا (mo->binding->معلومات_دننه_واټن) {
        ptr = section_ptr_جمع_کړه(mo->binding, 1);
        *ptr = BIND_OPCODE_بشپړ;
    }
    إذا (mo->weak_binding->معلومات_دننه_واټن) {
        ptr = section_ptr_جمع_کړه(mo->weak_binding, 1);
        *ptr = BIND_OPCODE_بشپړ;
    }
    tcc_free(mo->s_lazy_bind);
    tcc_free(mo->s_rebase);
    tcc_free(mo->bind);
}
#د_که_پای

بنية trie_info {
    ثابت حرف *name;
    صحيح flag;
    addr_t addr;
    صحيح str_اندازه;
    صحيح غړی_اندازه;
};

بنية trie_غوټه {
    صحيح پیل;
    صحيح پای_ټکی;
    صحيح شاخص_پیل;
    صحيح شاخص_پای_ټکی;
    صحيح n_ماشوم;
    بنية trie_غوټه *ماشوم;
};

بنية trie_seq {
    صحيح n_ماشوم;
    بنية trie_غوټه *غوټه;
    صحيح دننه_واټن;
    صحيح nest_دننه_واټن;
};

ساكن فراغ create_trie(بنية trie_غوټه *غوټه,
                        صحيح from, صحيح منزل, صحيح شاخص_پیل,
                        صحيح n_trie, بنية trie_info *trie)
{
    صحيح i;
    صحيح پیل, پای_ټکی, شاخص_پای_ټکی;
    حرف cur;
    بنية trie_غوټه *ماشوم;

    لكل (i = from; i < منزل; i = پای_ټکی) {
        cur = trie[i].name[شاخص_پیل];
        پیل = i++;
        لكل (; i < منزل; i++)
            إذا (cur != trie[i].name[شاخص_پیل])
                اكسر;
        پای_ټکی = i;
        إذا (پیل == پای_ټکی - 1 ||
            (trie[پیل].name[شاخص_پیل] &&
             trie[پیل].name[شاخص_پیل + 1] == 0))
            شاخص_پای_ټکی = trie[پیل].str_اندازه - 1;
        وإلا {
            شاخص_پای_ټکی = شاخص_پیل + 1;
            لكل (;;) {
                cur = trie[پیل].name[شاخص_پای_ټکی];
                لكل (i = پیل + 1; i < پای_ټکی; i++)
                    إذا (cur != trie[i].name[شاخص_پای_ټکی])
                        اكسر;
                إذا (trie[پیل].name[شاخص_پای_ټکی] &&
                    trie[پیل].name[شاخص_پای_ټکی + 1] == 0) {
                    پای_ټکی = پیل + 1;
                    شاخص_پای_ټکی = trie[پیل].str_اندازه - 1;
                    اكسر;
                }
                إذا (i != پای_ټکی)
                    اكسر;
                شاخص_پای_ټکی++;
            }
        }
        غوټه->ماشوم = tcc_realloc(غوټه->ماشوم,
                                  (غوټه->n_ماشوم + 1) *
                                  حجم(بنية trie_غوټه));
        ماشوم = &غوټه->ماشوم[غوټه->n_ماشوم];
        ماشوم->پیل = پیل;
        ماشوم->پای_ټکی = پای_ټکی;
        ماشوم->شاخص_پیل = شاخص_پیل;
        ماشوم->شاخص_پای_ټکی = شاخص_پای_ټکی;
        ماشوم->n_ماشوم = 0;
        ماشوم->ماشوم = عدم;
        غوټه->n_ماشوم++;
        إذا (پیل != پای_ټکی - 1)
            create_trie(ماشوم, پیل, پای_ټکی, شاخص_پای_ټکی, n_trie, trie);
    }
}

ساكن صحيح create_seq(صحيح *دننه_واټن, صحيح *n_seq, بنية trie_seq **seq,
                        بنية trie_غوټه *غوټه,
                        صحيح n_trie, بنية trie_info *trie)
{
    صحيح i, nest_دننه_واټن, وروستی_seq = *n_seq, retval = *دننه_واټن;
    بنية trie_seq *p_seq;
    بنية trie_غوټه *p_nest;

    لكل (i = 0; i < غوټه->n_ماشوم; i++) {
        p_nest = &غوټه->ماشوم[i];
        *seq = tcc_realloc(*seq, (*n_seq + 1) * حجم(بنية trie_seq));
        p_seq = &(*seq)[(*n_seq)++];
        p_seq->n_ماشوم = i == 0 ? غوټه->n_ماشوم : -1;
        p_seq->غوټه = p_nest;
        p_seq->دننه_واټن = *دننه_واټن;
        p_seq->nest_دننه_واټن = 0;
        *دننه_واټن += (i == 0 ? 1 + 1 : 0) +
                   p_nest->شاخص_پای_ټکی - p_nest->شاخص_پیل + 1 + 3;
    }
    لكل (i = 0; i < غوټه->n_ماشوم; i++) {
        nest_دننه_واټن =
            create_seq(دننه_واټن, n_seq, seq, &غوټه->ماشوم[i], n_trie, trie);
        p_seq = &(*seq)[وروستی_seq + i];
        p_seq->nest_دننه_واټن = nest_دننه_واټن;
    }
    أرجع retval;
}

ساكن فراغ غوټه_free(بنية trie_غوټه *غوټه)
{
    صحيح i;

    لكل (i = 0; i < غوټه->n_ماشوم; i++)
	غوټه_free(&غوټه->ماشوم[i]);
    tcc_free(غوټه->ماشوم);
}

ساكن صحيح triecmp(ثابت فراغ *_a, ثابت فراغ *_b, فراغ *arg)
{
    بنية trie_info *a = (بنية trie_info *) _a;
    بنية trie_info *b = (بنية trie_info *) _b;
    صحيح len_a = مزي_اوږدوالی(a->name);
    صحيح len_b = مزي_اوږدوالی(b->name);

    /* strange sorting needed. Name 'xx' should be after 'xx1' */
    إذا (!مزي_پرتله(a->name, b->name, len_a < len_b ? len_a : len_b))
	أرجع len_a < len_b ? 1 : (len_a > len_b ? -1 : 0);
    أرجع strcmp(a->name, b->name);
}

ساكن فراغ export_trie(TCCState *s1, بنية macho *mo)
{
    صحيح i, اندازه, دننه_واټن = 0, save_دننه_واټن;
    uint8_t *ptr;
    صحيح sym_شاخص;
    صحيح sym_پای_ټکی = symtab_section->معلومات_دننه_واټن / حجم(ElfW(Sym));
    صحيح n_trie = 0, n_seq = 0;
    بنية trie_info *trie = عدم, *p_trie;
    بنية trie_غوټه غوټه, *p_غوټه;
    بنية trie_seq *seq = عدم;
    addr_t vm_addr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;

    لكل (sym_شاخص = 1; sym_شاخص < sym_پای_ټکی; ++sym_شاخص) {
	ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->معلومات + sym_شاخص;
	ثابت حرف *name = (حرف*)symtab_section->link->معلومات + sym->st_name;

	إذا (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE &&
            (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL ||
	     ELFW(ST_BIND)(sym->st_info) == STB_WEAK)) {
	    صحيح flag = EXPORT_نښه_FLAGS_ډول_REGULAR;
	    addr_t addr =
		sym->st_ارزښت + s1->sections[sym->st_shndx]->sh_addr - vm_addr;

	    إذا (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
		flag |= EXPORT_نښه_FLAGS_WEAK_DEFINITION;
	    dprintf ("%s %d %llx\n", name, flag, (اوږد اوږد)addr + vm_addr);
	    trie = tcc_realloc(trie, (n_trie + 1) * حجم(بنية trie_info));
	    trie[n_trie].name = name;
	    trie[n_trie].flag = flag;
	    trie[n_trie].addr = addr;
	    trie[n_trie].str_اندازه = مزي_اوږدوالی(name) + 1;
	    trie[n_trie].غړی_اندازه = uleb128_اندازه(flag) + uleb128_اندازه(addr);
	    n_trie++;
	}
    }
    إذا (n_trie) {
        tcc_qsort(trie, n_trie, حجم(بنية trie_info), triecmp, عدم);
	memset(&غوټه, 0, حجم(غوټه));
        create_trie(&غوټه, 0, n_trie, 0, n_trie, trie);
	create_seq(&دننه_واټن, &n_seq, &seq, &غوټه, n_trie, trie);
        save_دننه_واټن = دننه_واټن;
        لكل (i = 0; i < n_seq; i++) {
            p_غوټه = seq[i].غوټه;
            إذا (p_غوټه->n_ماشوم == 0) {
                p_trie = &trie[p_غوټه->پیل];
                seq[i].nest_دننه_واټن = دننه_واټن;
                دننه_واټن += 1 + p_trie->غړی_اندازه + 1;
            }
        }
        لكل (i = 0; i < n_seq; i++) {
            p_غوټه = seq[i].غوټه;
            p_trie = &trie[p_غوټه->پیل];
            إذا (seq[i].n_ماشوم >= 0) {
                section_ptr_جمع_کړه(mo->exports,
				seq[i].دننه_واټن - mo->exports->معلومات_دننه_واټن);
                ptr = section_ptr_جمع_کړه(mo->exports, 2);
                *ptr++ = 0;
                *ptr = seq[i].n_ماشوم;
            }
            اندازه = p_غوټه->شاخص_پای_ټکی - p_غوټه->شاخص_پیل;
            ptr = section_ptr_جمع_کړه(mo->exports, اندازه + 1);
            حافظه_نقل(ptr, &p_trie->name[p_غوټه->شاخص_پیل], اندازه);
            ptr[اندازه] = 0;
            write_uleb128(mo->exports, seq[i].nest_دننه_واټن);
        }
        section_ptr_جمع_کړه(mo->exports, save_دننه_واټن - mo->exports->معلومات_دننه_واټن);
        لكل (i = 0; i < n_seq; i++) {
            p_غوټه = seq[i].غوټه;
            إذا (p_غوټه->n_ماشوم == 0) {
                p_trie = &trie[p_غوټه->پیل];
                write_uleb128(mo->exports, p_trie->غړی_اندازه);
                write_uleb128(mo->exports, p_trie->flag);
                write_uleb128(mo->exports, p_trie->addr);
                ptr = section_ptr_جمع_کړه(mo->exports, 1);
                *ptr = 0;
            }
        }
        section_ptr_جمع_کړه(mo->exports, -mo->exports->معلومات_دننه_واټن & 7);
	غوټه_free(&غوټه);
        tcc_free(seq);
    }
    tcc_free(trie);
}

ساكن فراغ collect_sections(TCCState *s1, بنية macho *mo, ثابت حرف *filename)
{
    صحيح i, sk, numsec;
    صحيح کارول_شوی_segment[N_SEGMENT];
    uint64_t curaddr, fileofs;
    Section *s;
    بنية segment_command_64 *seg;
    بنية dylib_command *dylib;
#که_تعریف_شوی CONFIG_NEW_MACHO
    بنية linkedit_معلومات_command *chained_fixups_lc;
    بنية linkedit_معلومات_command *export_trie_lc;
#د_که_پای
    بنية build_نسخه_command *dyldbv;
    بنية سرچینه_نسخه_command *dyldsv;
    بنية rpath_command *rpath;
    بنية dylinker_command *dyldlc;
    بنية symtab_command *symlc;
    بنية dysymtab_command *dysymlc;
    حرف *str;

    لكل (i = 0; i < N_SEGMENT; i++)
	کارول_شوی_segment[i] = all_segment[i].کارول_شوی;

    memset (mo->sk_منزل_sect, 0, حجم(mo->sk_منزل_sect));
    لكل (i = s1->nb_sections; i-- > 1;) {
        صحيح type, flags;
        s = s1->sections[i];
        type = s->sh_type;
        flags = s->sh_flags;
        sk = sk_unknown;
	/* debug sections have sometimes no SHF_ALLOC */
        إذا ((flags & SHF_ALLOC) || !مزي_پرتله(s->name, ".debug_", 7)) {
            بدل (type) {
            افتراضي:           sk = sk_unknown; اكسر;
            حالة SHT_INIT_ARRAY: sk = sk_init; اكسر;
            حالة SHT_FINI_ARRAY: sk = sk_fini; اكسر;
            حالة SHT_NOBITS:   sk = sk_bss; اكسر;
            حالة SHT_SYMTAB:   sk = sk_discard; اكسر;
            حالة SHT_STRTAB:
		إذا (s == stabstr_section)
		  sk = sk_stab_str;
		وإلا
		  sk = sk_discard;
		اكسر;
            حالة SHT_RELX:     sk = sk_discard; اكسر;
            حالة SHT_LINKEDIT: sk = sk_linkedit; اكسر;
            حالة SHT_PROGBITS:
                إذا (s == mo->stubs)
                  sk = sk_stubs;
#که_نه_تعریف_شوی CONFIG_NEW_MACHO
                وإلا إذا (s == mo->stub_helper)
                  sk = sk_stub_helper;
                وإلا إذا (s == mo->la_نښه_ptr)
                  sk = sk_la_ptr;
#د_که_پای
                وإلا إذا (s == rodata_section)
                  sk = sk_ro_معلومات;
                وإلا إذا (s == s1->got)
                  sk = sk_nl_ptr;
                وإلا إذا (s == stab_section)
                  sk = sk_stab;
                وإلا إذا (s == dwarf_info_section)
                  sk = sk_debug_info;
                وإلا إذا (s == dwarf_abbrev_section)
                  sk = sk_debug_abbrev;
                وإلا إذا (s == dwarf_کرښه_section)
                  sk = sk_debug_کرښه;
                وإلا إذا (s == dwarf_aranges_section)
                  sk = sk_debug_aranges;
                وإلا إذا (s == dwarf_str_section)
                  sk = sk_debug_str;
                وإلا إذا (s == dwarf_کرښه_str_section)
                  sk = sk_debug_کرښه_str;
                وإلا إذا (flags & SHF_EXECINSTR)
                  sk = sk_متن;
                وإلا إذا (flags & SHF_WRITE)
                  sk = sk_rw_معلومات;
                وإلا
                  sk = sk_ro_معلومات;
                اكسر;
            }
        } وإلا
          sk = sk_discard;
        s->prev = mo->sk_منزل_sect[sk].s;
        mo->sk_منزل_sect[sk].s = s;
	کارول_شوی_segment[skinfo[sk].seg_initial] = 1;
    }

    إذا (s1->output_type != TCC_OUTPUT_EXE)
	کارول_شوی_segment[0] = 0;

    لكل (i = 0; i < N_SEGMENT; i++)
	إذا (کارول_شوی_segment[i]) {
	    seg = جمع_کړه_segment(mo, all_segment[i].name);
	    إذا (i == 1 && s1->output_type != TCC_OUTPUT_EXE)
	        seg->vmaddr = 0;
	    وإلا
	        seg->vmaddr = all_segment[i].vmaddr;
	    seg->vmsize = all_segment[i].vmsize;
	    seg->maxprot = all_segment[i].maxprot;
	    seg->initprot = all_segment[i].initprot;
	    seg->flags = all_segment[i].flags;
            لكل (sk = sk_unknown; sk < sk_وروستی; sk++)
		إذا (skinfo[sk].seg_initial == i)
	            mo->segment[sk] = mo->nseg - 1;
	}

    إذا (s1->output_type != TCC_OUTPUT_EXE) {
	ثابت حرف *name = s1->install_name ? s1->install_name : filename;
        i = (حجم(*dylib) + مزي_اوږدوالی(name) + 1 + 7) &-8;
        dylib = جمع_کړه_lc(mo, LC_ID_DYLIB, i);
	dylib->name = حجم(*dylib);
	dylib->timestamp = 1;
	dylib->current_نسخه =
	    s1->current_نسخه ? s1->current_نسخه : 1 << 16;
	dylib->compatibility_نسخه =
	    s1->compatibility_نسخه ? s1->compatibility_نسخه : 1 << 16;
        str = (حرف*)dylib + dylib->name;
        strcpy(str, name);
    }

#که_تعریف_شوی CONFIG_NEW_MACHO
    chained_fixups_lc = جمع_کړه_lc(mo, LC_DYLD_CHAINED_FIXUPS,
			       حجم(بنية linkedit_معلومات_command));
    export_trie_lc = جمع_کړه_lc(mo, LC_DYLD_EXPORTS_TRIE,
			    حجم(بنية linkedit_معلومات_command));
#وإلا
    mo->dyldinfo = جمع_کړه_lc(mo, LC_DYLD_INFO_ONLY, حجم(*mo->dyldinfo));
#د_که_پای

    symlc = جمع_کړه_lc(mo, LC_SYMTAB, حجم(*symlc));
    dysymlc = جمع_کړه_lc(mo, LC_DYSYMTAB, حجم(*dysymlc));

    إذا (s1->output_type == TCC_OUTPUT_EXE) {
        i = (حجم(*dyldlc) + مزي_اوږدوالی("/usr/lib/dyld") + 1 + 7) &-8;
        dyldlc = جمع_کړه_lc(mo, LC_بارول_DYLINKER, i);
        dyldlc->name = حجم(*dyldlc);
        str = (حرف*)dyldlc + dyldlc->name;
        strcpy(str, "/usr/lib/dyld");
    }

    dyldbv = جمع_کړه_lc(mo, LC_BUILD_نسخه, حجم(*dyldbv));
    dyldbv->platform = PLATFORM_MACOS;
    dyldbv->minos = (10 << 16) + (6 << 8);
    dyldbv->sdk = (10 << 16) + (6 << 8);
    dyldbv->ntools = 0;

    dyldsv = جمع_کړه_lc(mo, LC_سرچینه_نسخه, حجم(*dyldsv));
    dyldsv->نسخه = 0;

    إذا (s1->output_type == TCC_OUTPUT_EXE) {
        mo->ep = جمع_کړه_lc(mo, LC_MAIN, حجم(*mo->ep));
        mo->ep->entryoff = 4096;
    }

    لكل(i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *dllref = s1->loaded_dlls[i];
        إذا (dllref->level == 0)
          جمع_کړه_dylib(mo, dllref->name);
    }

    إذا (s1->rpath) {
	حرف *لار = s1->rpath, *پای_ټکی;
	افعل {
	    پای_ټکی = strchr(لار, ':');
	    إذا (!پای_ټکی)
		پای_ټکی = strchr(لار, 0);
            i = (حجم(*rpath) + (پای_ټکی - لار) + 1 + 7) &-8;
            rpath = جمع_کړه_lc(mo, LC_RPATH, i);
            rpath->لار = حجم(*rpath);
            str = (حرف*)rpath + rpath->لار;
            حافظه_نقل(str, لار, پای_ټکی - لار);
	    str[پای_ټکی - لار] = 0;
	    لار = پای_ټکی + 1;
	} طالما (*پای_ټکی);
    }

    fileofs = 4096;  /* leave space for mach-o headers */
    curaddr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;
    curaddr += 4096;
    seg = عدم;
    numsec = 0;
    mo->elfsectomacho = tcc_mallocz(حجم(*mo->elfsectomacho) * s1->nb_sections);
    لكل (sk = sk_unknown; sk < sk_وروستی; sk++) {
        بنية section_64 *sec = عدم;
        إذا (seg) {
            seg->vmsize = curaddr - seg->vmaddr;
            seg->filesize = fileofs - seg->fileoff;
        }
#که_تعریف_شوی CONFIG_NEW_MACHO
	إذا (sk == sk_linkedit) {
	    calc_fixup_اندازه(s1, mo);
	    export_trie(s1, mo);
	}
#وإلا
	إذا (sk == sk_linkedit) {
	    bind_rebase(s1, mo);
	    export_trie(s1, mo);
	}
#د_که_پای
        إذا (skinfo[sk].seg_initial &&
	    (s1->output_type != TCC_OUTPUT_EXE || mo->segment[sk]) &&
	    mo->sk_منزل_sect[sk].s) {
            uint64_t al = 0;
            صحيح si;
            seg = get_segment(mo, mo->segment[sk]);
            إذا (skinfo[sk].name) {
                si = جمع_کړه_section(mo, &seg, skinfo[sk].name);
                numsec++;
                mo->lc[mo->seg2lc[mo->segment[sk]]] = (بنية بارول_command*)seg;
                mo->sk_منزل_sect[sk].machosect = si;
                sec = get_section(seg, si);
                sec->flags = skinfo[sk].flags;
		إذا (sk == sk_stubs)
#که_تعریف_شوی TCC_موخه_X86_64
	    	    sec->reserved2 = 6;
#وإلاإذا defined TCC_موخه_ARM64
	    	    sec->reserved2 = 12;
#د_که_پای
		إذا (sk == sk_nl_ptr)
	    	    sec->reserved1 = mo->nr_plt;
#که_نه_تعریف_شوی CONFIG_NEW_MACHO
		إذا (sk == sk_la_ptr)
	    	    sec->reserved1 = mo->nr_plt + mo->n_got;
#د_که_پای
            }
            إذا (seg->vmaddr == -1) {
                curaddr = (curaddr + SEG_پاڼه_اندازه - 1) & -SEG_پاڼه_اندازه;
                seg->vmaddr = curaddr;
                fileofs = (fileofs + SEG_پاڼه_اندازه - 1) & -SEG_پاڼه_اندازه;
                seg->fileoff = fileofs;
            }

            لكل (s = mo->sk_منزل_sect[sk].s; s; s = s->prev) {
                صحيح a = exact_log2p1(s->sh_addralign);
                إذا (a && al < (a - 1))
                  al = a - 1;
                s->sh_اندازه = s->معلومات_دننه_واټن;
            }
            إذا (sec)
              sec->align = al;
            al = 1ULL << al;
            إذا (al > 4096)
              tcc_warning("alignment > 4096"), sec->align = 12, al = 4096;
            curaddr = (curaddr + al - 1) & -al;
            fileofs = (fileofs + al - 1) & -al;
            إذا (sec) {
                sec->addr = curaddr;
                sec->دننه_واټن = fileofs;
            }
            لكل (s = mo->sk_منزل_sect[sk].s; s; s = s->prev) {
                al = s->sh_addralign;
                curaddr = (curaddr + al - 1) & -al;
                dprintf("%s: curaddr now 0x%lx\n", s->name, (اوږد)curaddr);
                s->sh_addr = curaddr;
                curaddr += s->sh_اندازه;
                إذا (s->sh_type != SHT_NOBITS) {
                    fileofs = (fileofs + al - 1) & -al;
                    s->sh_دننه_واټن = fileofs;
                    fileofs += s->sh_اندازه;
                    dprintf("%s: fileofs now %ld\n", s->name, (اوږد)fileofs);
                }
                إذا (sec)
                  mo->elfsectomacho[s->sh_عدد] = numsec;
            }
            إذا (sec)
              sec->اندازه = curaddr - sec->addr;
        }
        إذا (DEBUG_MACHO)
          لكل (s = mo->sk_منزل_sect[sk].s; s; s = s->prev) {
              صحيح type = s->sh_type;
              صحيح flags = s->sh_flags;
              چاپ_کړه("%d section %-16s %-10s %09lx %04x %02d %s,%s,%s\n",
                     sk,
                     s->name,
                     type == SHT_PROGBITS ? "progbits" :
                     type == SHT_NOBITS ? "nobits" :
                     type == SHT_SYMTAB ? "symtab" :
                     type == SHT_STRTAB ? "strtab" :
                     type == SHT_INIT_ARRAY ? "init" :
                     type == SHT_FINI_ARRAY ? "fini" :
                     type == SHT_RELX ? "rel" : "???",
                     (اوږد)s->sh_addr,
                     (بینښه)s->معلومات_دننه_واټن,
                     s->sh_addralign,
                     flags & SHF_ALLOC ? "alloc" : "",
                     flags & SHF_WRITE ? "write" : "",
                     flags & SHF_EXECINSTR ? "exec" : ""
                    );
          }
    }
    إذا (seg) {
        seg->vmsize = curaddr - seg->vmaddr;
        seg->filesize = fileofs - seg->fileoff;
    }

    /* Fill symtab info */
    symlc->symoff = mo->symtab->sh_دننه_واټن;
    symlc->nsyms = mo->symtab->معلومات_دننه_واټن / حجم(بنية nlist_64);
    symlc->stroff = mo->strtab->sh_دننه_واټن;
    symlc->strsize = mo->strtab->معلومات_دننه_واټن;

    dysymlc->iundefsym = mo->iundef == -1 ? symlc->nsyms : mo->iundef;
    dysymlc->iextdefsym = mo->iextdef == -1 ? dysymlc->iundefsym : mo->iextdef;
    dysymlc->ilocalsym = mo->ilocal == -1 ? dysymlc->iextdefsym : mo->ilocal;
    dysymlc->nlocalsym = dysymlc->iextdefsym - dysymlc->ilocalsym;
    dysymlc->nextdefsym = dysymlc->iundefsym - dysymlc->iextdefsym;
    dysymlc->nundefsym = symlc->nsyms - dysymlc->iundefsym;
    dysymlc->indirectsymoff = mo->indirsyms->sh_دننه_واټن;
    dysymlc->nindirectsyms = mo->indirsyms->معلومات_دننه_واټن / حجم(uint32_t);

#که_تعریف_شوی CONFIG_NEW_MACHO
    إذا (mo->chained_fixups->معلومات_دننه_واټن) {
        chained_fixups_lc->dataoff = mo->chained_fixups->sh_دننه_واټن;
        chained_fixups_lc->datasize = mo->chained_fixups->معلومات_دننه_واټن;
    }
    إذا (mo->exports->معلومات_دننه_واټن) {
        export_trie_lc->dataoff = mo->exports->sh_دننه_واټن;
        export_trie_lc->datasize = mo->exports->معلومات_دننه_واټن;
    }
#وإلا
    إذا (mo->rebase->معلومات_دننه_واټن) {
        mo->dyldinfo->rebase_off = mo->rebase->sh_دننه_واټن;
        mo->dyldinfo->rebase_اندازه = mo->rebase->معلومات_دننه_واټن;
    }
    إذا (mo->binding->معلومات_دننه_واټن) {
        mo->dyldinfo->bind_off = mo->binding->sh_دننه_واټن;
        mo->dyldinfo->bind_اندازه = mo->binding->معلومات_دننه_واټن;
    }
    إذا (mo->weak_binding->معلومات_دننه_واټن) {
        mo->dyldinfo->weak_bind_off = mo->weak_binding->sh_دننه_واټن;
        mo->dyldinfo->weak_bind_اندازه = mo->weak_binding->معلومات_دننه_واټن;
    }
    إذا (mo->lazy_binding->معلومات_دننه_واټن) {
        mo->dyldinfo->lazy_bind_off = mo->lazy_binding->sh_دننه_واټن;
        mo->dyldinfo->lazy_bind_اندازه = mo->lazy_binding->معلومات_دننه_واټن;
    }
    إذا (mo->exports->معلومات_دننه_واټن) {
        mo->dyldinfo->export_off = mo->exports->sh_دننه_واټن;
        mo->dyldinfo->export_اندازه = mo->exports->معلومات_دننه_واټن;
    }
#د_که_پای
}

ساكن فراغ macho_write(TCCState *s1, بنية macho *mo, FILE *fp)
{
    صحيح i, sk;
    uint64_t fileofs = 0;
    Section *s;
    mo->mh.mh.magic = MH_MAGIC_64;
#که_تعریف_شوی TCC_موخه_X86_64
    mo->mh.mh.cputype = CPU_TYPE_X86_64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_LIB64 | CPU_SUBTYPE_X86_ALL;
#وإلاإذا defined TCC_موخه_ARM64
    mo->mh.mh.cputype = CPU_TYPE_ARM64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_ARM64_ALL;
#د_که_پای
    إذا (s1->output_type == TCC_OUTPUT_EXE) {
        mo->mh.mh.filetype = MH_EXECUTE;
        mo->mh.mh.flags = MH_DYLDLINK | MH_PIE;
    }
    وإلا {
        mo->mh.mh.filetype = MH_DYLIB;
        mo->mh.mh.flags = MH_DYLDLINK;
    }
    mo->mh.mh.ncmds = mo->nlc;
    mo->mh.mh.sizeofcmds = 0;
    لكل (i = 0; i < mo->nlc; i++)
      mo->mh.mh.sizeofcmds += mo->lc[i]->cmdsize;

    fwrite(&mo->mh, 1, حجم(mo->mh), fp);
    fileofs += حجم(mo->mh);
    لكل (i = 0; i < mo->nlc; i++) {
        fwrite(mo->lc[i], 1, mo->lc[i]->cmdsize, fp);
        fileofs += mo->lc[i]->cmdsize;
    }

    لكل (sk = sk_unknown; sk < sk_وروستی; sk++) {
        //struct segment_command_64 *seg;
        إذا (skinfo[sk].seg_initial == 0 ||
	    (s1->output_type == TCC_OUTPUT_EXE && !mo->segment[sk]) ||
	    !mo->sk_منزل_sect[sk].s)
          استمر;
        /*seg =*/ get_segment(mo, mo->segment[sk]);
        لكل (s = mo->sk_منزل_sect[sk].s; s; s = s->prev) {
            إذا (s->sh_type != SHT_NOBITS) {
                طالما (fileofs < s->sh_دننه_واټن)
                  fputc(0, fp), fileofs++;
                إذا (s->sh_اندازه) {
                    fwrite(s->معلومات, 1, s->sh_اندازه, fp);
                    fileofs += s->sh_اندازه;
                }
            }
        }
    }
}

#که_تعریف_شوی CONFIG_NEW_MACHO
ساكن صحيح bind_rebase_cmp(ثابت فراغ *_a, ثابت فراغ *_b, فراغ *arg)
{
    TCCState *s1 = arg;
    بنية bind_rebase *a = (بنية bind_rebase *) _a;
    بنية bind_rebase *b = (بنية bind_rebase *) _b;
    addr_t aa = s1->sections[a->section]->sh_addr + a->rel.r_دننه_واټن;
    addr_t ab = s1->sections[b->section]->sh_addr + b->rel.r_دننه_واټن;

    أرجع aa > ab ? 1 : aa < ab ? -1 : 0;
}

ST_FUNC فراغ bind_rebase_import(TCCState *s1, بنية macho *mo)
{
    صحيح i, j, k, bind_شاخص, اندازه, پاڼه_شمېر, sym_شاخص;
    ثابت حرف *name;
    ElfW(Sym) *sym;
    بینښه حرف *معلومات = mo->chained_fixups->معلومات;
    بنية segment_command_64 *seg;
    بنية dyld_chained_fixups_سرلیک *سرلیک;
    بنية dyld_chained_starts_دننه_image *image;
    بنية dyld_chained_starts_دننه_segment *segment;
    بنية dyld_chained_import *import;

    tcc_qsort(mo->bind_rebase, mo->n_bind_rebase, حجم(بنية bind_rebase),
	      bind_rebase_cmp, s1);
    لكل (i = 0; i < mo->n_bind_rebase - 1; i++)
	إذا (mo->bind_rebase[i].section == mo->bind_rebase[i + 1].section &&
	    mo->bind_rebase[i].rel.r_دننه_واټن == mo->bind_rebase[i + 1].rel.r_دننه_واټن) {
	    sym_شاخص = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
            sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
	    name = (حرف *) symtab_section->link->معلومات + sym->st_name;
	    tcc_error("Overlap %s/%s %s:%s",
		      mo->bind_rebase[i].bind ? "bind" : "rebase",
		      mo->bind_rebase[i + 1].bind ? "bind" : "rebase",
		      s1->sections[mo->bind_rebase[i].section]->name, name);
	}
    سرلیک = (بنية dyld_chained_fixups_سرلیک *) معلومات;
    معلومات += (حجم(بنية dyld_chained_fixups_سرلیک) + 7) & -8;
    سرلیک->starts_دننه_واټن = معلومات - mo->chained_fixups->معلومات;
    سرلیک->imports_شمېر = mo->n_bind;
    سرلیک->imports_format = DYLD_CHAINED_IMPORT;
    سرلیک->symbols_format = 0;
    اندازه = حجم(بنية dyld_chained_starts_دننه_image) +
	   (mo->nseg - 1) * حجم(uint32_t);
    image = (بنية dyld_chained_starts_دننه_image *) معلومات;
    معلومات += (اندازه + 7) & -8;
    image->seg_شمېر = mo->nseg;
    لكل (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
        image->seg_info_دننه_واټن[i] = (معلومات - mo->chained_fixups->معلومات) -
				    سرلیک->starts_دننه_واټن;
	seg = get_segment(mo, i);
	پاڼه_شمېر = (seg->vmsize + SEG_پاڼه_اندازه - 1) / SEG_پاڼه_اندازه;
	اندازه = حجم(بنية dyld_chained_starts_دننه_segment) +
		      (پاڼه_شمېر - 1) * حجم(uint16_t);
        segment = (بنية dyld_chained_starts_دننه_segment *) معلومات;
        معلومات += (اندازه + 7) & -8;
        segment->اندازه = اندازه;
        segment->پاڼه_اندازه = SEG_پاڼه_اندازه;
#إذا 1
#تعریف_کړه	PTR_64_دننه_واټن 0
#تعریف_کړه	PTR_64_ماسک   0x7FFFFFFFFFFULL
        segment->اشاره_ګر_format = DYLD_CHAINED_PTR_64;
#وإلا
#تعریف_کړه	PTR_64_دننه_واټن 0x100000000ULL
#تعریف_کړه	PTR_64_ماسک   0xFFFFFFFFFFFFFFULL
        segment->اشاره_ګر_format = DYLD_CHAINED_PTR_64_دننه_واټن;
#د_که_پای
        segment->segment_دننه_واټن = seg->fileoff;
        segment->max_valid_اشاره_ګر = 0;
        segment->پاڼه_شمېر = پاڼه_شمېر;
	// add bind/rebase
	bind_شاخص = 0;
	k = 0;
	لكل (j = 0; j < پاڼه_شمېر; j++) {
	    addr_t پیل = seg->vmaddr + j * SEG_پاڼه_اندازه;
	    addr_t پای_ټکی = پیل + SEG_پاڼه_اندازه;
	    فراغ *وروستی = عدم;
	    addr_t وروستی_o = 0;
	    addr_t cur_o, cur;
	    بنية dyld_chained_ptr_64_rebase *rebase;
	    بنية dyld_chained_ptr_64_bind *bind;

	    segment->پاڼه_پیل[j] = DYLD_CHAINED_PTR_پیل_NONE;
	    لكل (; k < mo->n_bind_rebase; k++) {
	        Section *s = s1->sections[mo->bind_rebase[k].section];
		addr_t r_دننه_واټن = mo->bind_rebase[k].rel.r_دننه_واټن;
		addr_t addr = s->sh_addr + r_دننه_واټن;

		إذا ((addr & 3) ||
		    (addr & (SEG_پاڼه_اندازه - 1)) > SEG_پاڼه_اندازه - PTR_اندازه)
		    tcc_error("Illegal rel_offset %s %lld",
			      s->name, (اوږد اوږد)r_دننه_واټن);
		إذا (addr >= پای_ټکی)
		    اكسر;
		إذا (addr >= پیل) {
		    cur_o = addr - پیل;
	            إذا (mo->bind_rebase[k].bind) {
		        إذا (segment->پاڼه_پیل[j] == DYLD_CHAINED_PTR_پیل_NONE)
			    segment->پاڼه_پیل[j] = cur_o;
		        وإلا {
			    bind = (بنية dyld_chained_ptr_64_bind *) وروستی;
			    bind->بل = (cur_o - وروستی_o) / 4;
		        }
		        bind = (بنية dyld_chained_ptr_64_bind *)
				    (s->معلومات + r_دننه_واټن);
		        وروستی = bind;
		        وروستی_o = cur_o;
		        bind->ordinal = bind_شاخص;
		        bind->addend = 0;
		        bind->reserved = 0;
		        bind->بل = 0;
		        bind->bind = 1;
		    }
		    وإلا {
		        إذا (segment->پاڼه_پیل[j] == DYLD_CHAINED_PTR_پیل_NONE)
			    segment->پاڼه_پیل[j] = cur_o;
		        وإلا {
			    rebase = (بنية dyld_chained_ptr_64_rebase *) وروستی;
			    rebase->بل = (cur_o - وروستی_o) / 4;
		        }
		        rebase = (بنية dyld_chained_ptr_64_rebase *)
				    (s->معلومات + r_دننه_واټن);
		        وروستی = rebase;
		        وروستی_o = cur_o;
		        cur = (*(uint64_t *) (s->معلومات + r_دننه_واټن)) -
			      PTR_64_دننه_واټن;
		        rebase->موخه = cur & PTR_64_ماسک;
		        rebase->high8 = cur >> (64 - 8);
			إذا (cur != ((uint64_t)rebase->high8 << (64 - 8)) + rebase->موخه)
			    tcc_error("rebase error");
		        rebase->reserved = 0;
		        rebase->بل = 0;
		        rebase->bind = 0;
		    }
		}
		bind_شاخص += mo->bind_rebase[k].bind;
	    }
	}
    }
    // add imports
    سرلیک->imports_دننه_واټن = معلومات - mo->chained_fixups->معلومات;
    import = (بنية dyld_chained_import *) معلومات;
    معلومات += mo->n_bind * حجم (بنية dyld_chained_import);
    سرلیک->symbols_دننه_واټن = معلومات - mo->chained_fixups->معلومات;
    معلومات++;
    لكل (i = 0, bind_شاخص = 0; i < mo->n_bind_rebase; i++) {
	إذا (mo->bind_rebase[i].bind) {
	    import[bind_شاخص].lib_ordinal =
		BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xffu;
	    import[bind_شاخص].name_دننه_واټن =
		(معلومات - mo->chained_fixups->معلومات) - سرلیک->symbols_دننه_واټن;
	    sym_شاخص = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_شاخص];
	    import[bind_شاخص].weak_import =
		ELFW(ST_BIND)(sym->st_info) == STB_WEAK;
	    name = (حرف *) symtab_section->link->معلومات + sym->st_name;
            strcpy((حرف *) معلومات, name);
	    معلومات += مزي_اوږدوالی(name) + 1;
	    bind_شاخص++;
	}
    }
    tcc_free(mo->bind_rebase);
}
#د_که_پای

ST_FUNC صحيح macho_output_file(TCCState *s1, ثابت حرف *filename)
{
    صحيح fd, ډېرپېښ, file_type;
    FILE *fp;
    صحيح i, ret = -1;
    بنية macho mo;

    (فراغ)memset(&mo, 0, حجم(mo));

    file_type = s1->output_type;
    إذا (file_type == TCC_OUTPUT_OBJ)
        ډېرپېښ = 0666;
    وإلا
        ډېرپېښ = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_دوګونی_2, ډېرپېښ);
    إذا (fd < 0 || (fp = fdopen(fd, "wb")) == عدم) {
        tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
        أرجع -1;
    }
    tcc_جمع_کړه_runtime(s1);
    tcc_macho_جمع_کړه_destructor(s1);
    resolve_common_syms(s1);
    create_symtab(s1, &mo);
    check_relocs(s1, &mo);
    ret = check_symbols(s1, &mo);
    إذا (!ret) {
	صحيح save_output = s1->output_type;

        collect_sections(s1, &mo, filename);
        relocate_syms(s1, s1->symtab, 0);
	إذا (s1->output_type == TCC_OUTPUT_EXE)
            mo.ep->entryoff = get_sym_addr(s1, "main", 1, 1)
                            -     get_segment(&mo, 1)->vmaddr;
        إذا (s1->nb_errors)
          اذهب do_ret;
	// Macho uses bind/rebase instead of dynsym
	s1->output_type = TCC_OUTPUT_EXE;
        relocate_sections(s1);
	s1->output_type = save_output;
#که_تعریف_شوی CONFIG_NEW_MACHO
	bind_rebase_import(s1, &mo);
#د_که_پای
        convert_symbols(s1, &mo);
        إذا (s1->verbose)
            چاپ_کړه("<- %s\n", filename);
        macho_write(s1, &mo, fp);
    }

 do_ret:
    لكل (i = 0; i < mo.nlc; i++)
      tcc_free(mo.lc[i]);
    tcc_free(mo.seg2lc);
    tcc_free(mo.lc);
    tcc_free(mo.elfsectomacho);
    tcc_free(mo.e2msym);

    fclose(fp);
#که_تعریف_شوی CONFIG_CODESIGN
    إذا (!ret) {
	حرف command[1024];
	صحيح retval;

	snprintf(command, حجم(command), "codesign -f -s - %s", filename);
	retval = system (command);
	إذا (retval == -1 || !(WIFEXITED(retval) && WEXITSTATUS(retval) == 0))
	    tcc_error ("command failed '%s'", command);
    }
#د_که_پای
    أرجع ret;
}

ساكن uint32_t macho_swap32(uint32_t x)
{
  أرجع (x >> 24) | (x << 24) | ((x >> 8) & 0xff00) | ((x & 0xff00) << 8);
}
#تعریف_کړه بدلون(x) (بدلون_2 ? macho_swap32(x) : (x))
#تعریف_کړه tbd_parse_movepast(s) \
    (pos = (pos = مزي_پلټنه(pos, s)) ? pos + مزي_اوږدوالی(s) : عدم)
#تعریف_کړه tbd_parse_movetoany(cs) (pos = strpbrk(pos, cs))
#تعریف_کړه tbd_parse_skipws طالما (*pos && (*pos==' '||*pos=='\n')) ++pos
#تعریف_کړه tbd_parse_tramplequote إذا(*pos=='\''||*pos=='"') tbd_parse_trample
#تعریف_کړه tbd_parse_tramplespace إذا(*pos==' ') tbd_parse_trample
#تعریف_کړه tbd_parse_trample *pos++=0

#که_تعریف_شوی TCC_IS_NATIVE
/* Looks for the active developer SDK set by xcode-select (or the default
   one set during installation.) */
ST_FUNC فراغ tcc_جمع_کړه_macos_sdkpath(TCCState* s)
{
    حرف *sdkroot = عدم, *pos = عدم;
    فراغ* xcs = dlopen("libxcselect.dylib", RTLD_GLOBAL | RTLD_LAZY);
    CString لار;
    صحيح (*f)(بینښه صحيح, حرف**) = dlsym(xcs, "xcselect_host_sdk_path");
    cstr_new(&لار);
    إذا (f) f(1, &sdkroot);
    إذا (sdkroot)
        pos = مزي_پلټنه(sdkroot,"SDKs/MacOSX");
    إذا (pos)
        cstr_printf(&لار, "%.*s.sdk/usr/lib", (صحيح)(pos - sdkroot + 11), sdkroot);
    /* must use free from libc directly */
#لارښوونه ټېل_macro("free")
#تعریف_لغوه حرر
    حرر(sdkroot);
#لارښوونه راوباسه_macro("free")
    إذا (لار.اندازه)
        tcc_جمع_کړه_library_لار(s, (حرف*)لار.معلومات);
    وإلا
        tcc_جمع_کړه_library_لار(s,
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib"
            ":" "/Applications/Xcode.app/Developer/SDKs/MacOSX.sdk/usr/lib"
            );
    cstr_free(&لار);
}

ST_FUNC حرف* macho_tbd_soname(صحيح fd) {
    حرف *soname, *معلومات, *pos;
    حرف *ret = 0;
    pos = معلومات = tcc_بارول_متن(fd);
    إذا (!tbd_parse_movepast("install-name: ")) اذهب the_پای_ټکی;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    إذا (!tbd_parse_movetoany("\n \"'")) اذهب the_پای_ټکی;
    tbd_parse_trample;
    ret = tcc_strdup(soname);
the_پای_ټکی:
    tcc_free(معلومات);
    أرجع ret;
}
#د_که_پای /* TCC_IS_NATIVE */

ST_FUNC صحيح macho_بارول_tbd(TCCState* s1, صحيح fd, ثابت حرف* filename, صحيح lev)
{
    حرف *soname, *معلومات, *pos;
    صحيح ret = -1;

    pos = معلومات = tcc_بارول_متن(fd);
    إذا (!tbd_parse_movepast("install-name: ")) اذهب the_پای_ټکی;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    إذا (!tbd_parse_movetoany("\n \"'")) اذهب the_پای_ټکی;
    tbd_parse_trample;
    ret = 0;
    إذا (tcc_جمع_کړه_dllref(s1, soname, lev)->وموندل)
        اذهب the_پای_ټکی;
    طالما(pos) {
        حرف* sym = عدم;
        صحيح cont = 1;
        إذا (!tbd_parse_movepast("symbols: ")) اكسر;
        إذا (!tbd_parse_movepast("[")) اكسر;
        طالما (cont) {
            tbd_parse_skipws;
            tbd_parse_tramplequote;
            sym = pos;
            إذا (!tbd_parse_movetoany(",] \"'")) اكسر;
            tbd_parse_tramplequote;
            tbd_parse_tramplespace;
            tbd_parse_skipws;
            إذا (*pos==0||*pos==']') cont=0;
            tbd_parse_trample;
            سېټ_elf_sym(s1->dynsymtab_section, 0, 0,
                ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0, SHN_UNDEF, sym);
        }
    }

the_پای_ټکی:
    tcc_free(معلومات);
    أرجع ret;
}

ST_FUNC صحيح macho_بارول_dll(TCCState * s1, صحيح fd, ثابت حرف* filename, صحيح lev)
{
    بینښه حرف buf[حجم(بنية mach_سرلیک_64)];
    فراغ *buf2;
    uint32_t machofs = 0;
    بنية fat_سرلیک fh;
    بنية mach_سرلیک mh;
    بنية بارول_command *lc;
    صحيح i, بدلون_2 = 0;
    ثابت حرف *soname = filename;
    بنية nlist_64 *symtab = 0;
    uint32_t nsyms = 0;
    حرف *strtab = 0;
    uint32_t strsize = 0;
    uint32_t iextdef = 0;
    uint32_t nextdef = 0;

  again:
    إذا (ډک_read(fd, buf, حجم(buf)) != حجم(buf))
      أرجع -1;
    حافظه_نقل(&fh, buf, حجم(fh));
    إذا (fh.magic == FAT_MAGIC || fh.magic == FAT_CIGAM) {
        بنية fat_arch *fa = بارول_معلومات(fd, حجم(fh),
                                        fh.nfat_arch * حجم(*fa));
        بدلون_2 = fh.magic == FAT_CIGAM;
        لكل (i = 0; i < بدلون(fh.nfat_arch); i++)
#که_تعریف_شوی TCC_موخه_X86_64
          إذا (بدلون(fa[i].cputype) == CPU_TYPE_X86_64
              && بدلون(fa[i].cpusubtype) == CPU_SUBTYPE_X86_ALL)
#وإلاإذا defined TCC_موخه_ARM64
          إذا (بدلون(fa[i].cputype) == CPU_TYPE_ARM64
              && بدلون(fa[i].cpusubtype) == CPU_SUBTYPE_ARM64_ALL)
#د_که_پای
            اكسر;
        إذا (i == بدلون(fh.nfat_arch)) {
            tcc_free(fa);
            أرجع -1;
        }
        machofs = بدلون(fa[i].دننه_واټن);
        tcc_free(fa);
        lseek(fd, machofs, SEEK_SET);
        اذهب again;
    } وإلا إذا (fh.magic == FAT_MAGIC_64 || fh.magic == FAT_CIGAM_64) {
        tcc_warning("%s: Mach-O fat 64bit files of type 0x%x not handled",
                    filename, fh.magic);
        أرجع -1;
    }

    حافظه_نقل(&mh, buf, حجم(mh));
    إذا (mh.magic != MH_MAGIC_64)
      أرجع -1;
    dprintf("found Mach-O at %d\n", machofs);
    buf2 = بارول_معلومات(fd, machofs + حجم(بنية mach_سرلیک_64), mh.sizeofcmds);
    لكل (i = 0, lc = buf2; i < mh.ncmds; i++) {
        dprintf("lc %2d: 0x%08x\n", i, lc->cmd);
        بدل (lc->cmd) {
        حالة LC_SYMTAB:
        {
            بنية symtab_command *sc = (بنية symtab_command*)lc;
            nsyms = sc->nsyms;
            symtab = بارول_معلومات(fd, machofs + sc->symoff, nsyms * حجم(*symtab));
            strsize = sc->strsize;
            strtab = بارول_معلومات(fd, machofs + sc->stroff, strsize);
            اكسر;
        }
        حالة LC_ID_DYLIB:
        {
            بنية dylib_command *dc = (بنية dylib_command*)lc;
            soname = (حرف*)lc + dc->name;
            dprintf(" ID_DYLIB %d 0x%x 0x%x %s\n",
                    dc->timestamp, dc->current_نسخه,
                    dc->compatibility_نسخه, soname);
            اكسر;
        }
        حالة LC_REEXPORT_DYLIB:
        {
            بنية dylib_command *dc = (بنية dylib_command*)lc;
            حرف *name = (حرف*)lc + dc->name;
            صحيح subfd = open(name, O_RDONLY | O_دوګونی_2);
            dprintf(" REEXPORT %s\n", name);
            إذا (subfd < 0)
              tcc_warning("can't open %s (reexported from %s)", name, filename);
            وإلا {
                /* Hopefully the REEXPORTs never form a cycle, we don't check
                   for that!  */
                macho_بارول_dll(s1, subfd, name, lev + 1);
                close(subfd);
            }
            اكسر;
        }
        حالة LC_DYSYMTAB:
        {
            بنية dysymtab_command *dc = (بنية dysymtab_command*)lc;
            iextdef = dc->iextdefsym;
            nextdef = dc->nextdefsym;
            اكسر;
        }
        }
        lc = (بنية بارول_command*) ((حرف*)lc + lc->cmdsize);
    }

    إذا (tcc_جمع_کړه_dllref(s1, soname, lev)->وموندل)
        اذهب the_پای_ټکی;

    إذا (!nsyms || !nextdef)
      tcc_warning("%s doesn't export any symbols?", filename);

    //dprintf("symbols (all):\n");
    dprintf("symbols (exported):\n");
    dprintf("    n: typ sec   desc              value name\n");
    //for (i = 0; i < nsyms; i++) {
    لكل (i = iextdef; i < iextdef + nextdef; i++) {
        بنية nlist_64 *sym = symtab + i;
        dprintf("%5d: %3d %3d 0x%04x 0x%016lx %s\n",
                i, sym->n_type, sym->n_sect, sym->n_desc, (اوږد)sym->n_ارزښت,
                strtab + sym->n_strx);
        سېټ_elf_sym(s1->dynsymtab_section, 0, 0,
                    ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
                    0, SHN_UNDEF, strtab + sym->n_strx);
    }

  the_پای_ټکی:
    tcc_free(strtab);
    tcc_free(symtab);
    tcc_free(buf2);
    أرجع 0;
}
