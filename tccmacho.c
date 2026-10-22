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

#إذا !defined TCC_هدف_X86_64 && !defined TCC_هدف_ARM64
#غلطي Platform not supported
#جيڪڏهن_پورو

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#وصف_رد _tcc_error

#وصف_ڪريو DEBUG_MACHO 0
#وصف_ڪريو dprintf إذا (DEBUG_MACHO) لکو

#وصف_ڪريو MH_EXECUTE              (0x2)
#وصف_ڪريو MH_DYLDLINK             (0x4)
#وصف_ڪريو MH_DYLIB                (0x6)
#وصف_ڪريو MH_PIE                  (0x200000)

#وصف_ڪريو CPU_SUBTYPE_LIB64       (0x80000000)
#وصف_ڪريو CPU_SUBTYPE_X86_ALL     (3)
#وصف_ڪريو CPU_SUBTYPE_ARM64_ALL   (0)

#وصف_ڪريو CPU_ARCH_ABI64          (0x01000000)

#وصف_ڪريو CPU_TYPE_X86            (7)
#وصف_ڪريو CPU_TYPE_X86_64         (CPU_TYPE_X86 | CPU_ARCH_ABI64)
#وصف_ڪريو CPU_TYPE_ARM            (12)
#وصف_ڪريو CPU_TYPE_ARM64          (CPU_TYPE_ARM | CPU_ARCH_ABI64)

بنية fat_سرو {
    uint32_t        magic;          /* FAT_MAGIC or FAT_MAGIC_64 */
    uint32_t        nfat_arch;      /* number of structs that follow */
};

بنية fat_arch {
    صحيح             cputype;        /* cpu specifier (int) */
    صحيح             cpusubtype;     /* machine specifier (int) */
    uint32_t        وٿي;         /* file offset to this object file */
    uint32_t        سائيز;           /* size of this object file */
    uint32_t        align;          /* alignment as a power of 2 */
};

#وصف_ڪريو FAT_MAGIC       0xcafebabe
#وصف_ڪريو FAT_CIGAM       0xbebafeca
#وصف_ڪريو FAT_MAGIC_64    0xcafebabf
#وصف_ڪريو FAT_CIGAM_64    0xbfbafeca

بنية mach_سرو {
    uint32_t        magic;          /* mach magic number identifier */
    صحيح             cputype;        /* cpu specifier */
    صحيح             cpusubtype;     /* machine specifier */
    uint32_t        filetype;       /* type of file */
    uint32_t        ncmds;          /* number of load commands */
    uint32_t        sizeofcmds;     /* the size of all the load commands */
    uint32_t        flags;          /* flags */
};

بنية mach_سرو_64 {
    بنية mach_سرو  mh;
    uint32_t            reserved;       /* reserved, pad to 64bit */
};

/* Constant for the magic field of the mach_header (32-bit architectures) */
#وصف_ڪريو MH_MAGIC        0xfeedface      /* the mach magic number */
#وصف_ڪريو MH_CIGAM        0xcefaedfe      /* NXSwapInt(MH_MAGIC) */
#وصف_ڪريو MH_MAGIC_64     0xfeedfacf      /* the 64-bit mach magic number */
#وصف_ڪريو MH_CIGAM_64     0xcffaedfe      /* NXSwapInt(MH_MAGIC_64) */

بنية ڀريو_command {
    uint32_t        cmd;            /* type of load command */
    uint32_t        cmdsize;        /* total size of command in bytes */
};

#وصف_ڪريو LC_REQ_DYLD 0x80000000
#وصف_ڪريو LC_SYMTAB        0x2
#وصف_ڪريو LC_DYSYMTAB      0xb
#وصف_ڪريو LC_ڀريو_DYLIB    0xc
#وصف_ڪريو LC_ID_DYLIB      0xd
#وصف_ڪريو LC_ڀريو_DYLINKER 0xe
#وصف_ڪريو LC_SEGMENT_64    0x19
#وصف_ڪريو LC_RPATH (0x1c | LC_REQ_DYLD)
#وصف_ڪريو LC_REEXPORT_DYLIB (0x1f | LC_REQ_DYLD)
#وصف_ڪريو LC_DYLD_INFO_ONLY (0x22|LC_REQ_DYLD)
#وصف_ڪريو LC_MAIN (0x28|LC_REQ_DYLD)
#وصف_ڪريو LC_ذريعو_نسخو 0x2A
#وصف_ڪريو LC_BUILD_نسخو 0x32
#وصف_ڪريو LC_DYLD_EXPORTS_TRIE (0x33 | LC_REQ_DYLD)
#وصف_ڪريو LC_DYLD_CHAINED_FIXUPS (0x34 | LC_REQ_DYLD)

#وصف_ڪريو SG_READ_ONLY    0x10 /* This segment is made read-only after fixups */

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
    uint64_t        سائيز;           /* size in bytes of this section */
    uint32_t        وٿي;         /* file offset of this section */
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

بنية dyld_chained_fixups_سرو {
    uint32_t    fixups_نسخو; ///< 0
    uint32_t    starts_وٿي;  ///< Offset of dyld_chained_starts_in_image.
    uint32_t    imports_وٿي; ///< Offset of imports table in chain_data.
    uint32_t    symbols_وٿي; ///< Offset of symbol strings in chain_data.
    uint32_t    imports_ڳڻپ;  ///< Number of imported symbol names.
    uint32_t    imports_format; ///< DYLD_CHAINED_IMPORT*
    uint32_t    symbols_format; ///< 0 => uncompressed, 1 => zlib compressed
};

بنية dyld_chained_starts_اندريون_image
{
    uint32_t    seg_ڳڻپ;
    uint32_t    seg_info_وٿي[1];  // each entry is offset into this struct for that segment
    // followed by pool of dyld_chain_starts_in_segment data
};

تعداد {
    DYLD_CHAINED_PTR_64                     =  2,    // target is vmaddr
    DYLD_CHAINED_PTR_64_وٿي              =  6,    // target is vm offset
};

تعداد {
    DYLD_CHAINED_PTR_شروعات_NONE   = 0xFFFF, // used in page_start[] to denote a page with no fixups
};

#وصف_ڪريو SEG_صفحو_سائيز 16384

بنية dyld_chained_starts_اندريون_segment
{
    uint32_t    سائيز;               // size of this (amount kernel needs to copy)
    uint16_t    صفحو_سائيز;          // 0x1000 or 0x4000
    uint16_t    اشارو_format;     // DYLD_CHAINED_PTR_*
    uint64_t    segment_وٿي;     // offset in memory to start of segment
    uint32_t    max_valid_اشارو;  // for 32-bit OS, any value beyond this is not a pointer
    uint16_t    صفحو_ڳڻپ;         // how many pages are in array
    uint16_t    صفحو_شروعات[1];      // each entry is offset in each page of first element in chain
                                    // or DYLD_CHAINED_PTR_START_NONE if no fixups on page
};

تعداد BindSpecialDylib {
  BIND_SPECIAL_DYLIB_FLAT_LOOKUP = -2,
};

بنية dyld_chained_import
{
    uint32_t    lib_ordinal :  8,
                weak_import :  1,
                name_وٿي : 23;
};

بنية dyld_chained_ptr_64_rebase
{
    uint64_t    هدف    : 36,    // vmaddr, 64GB max image size
                high8     :  8,    // top 8 bits set to this after slide added
                reserved  :  7,    // all zeros
                ايندڙ      : 12,    // 4-byte stride
                bind      :  1;    // == 0
};

بنية dyld_chained_ptr_64_bind
{
    uint64_t    ordinal   : 24,
                addend    :  8,   // 0 thru 255
                reserved  : 19,   // all zeros
                ايندڙ      : 12,   // 4-byte stride
                bind      :  1;   // == 1
};

#وصف_ڪريو S_REGULAR                       0x0
#وصف_ڪريو S_ZEROFILL                      0x1
#وصف_ڪريو S_NON_LAZY_نشان_اشارا      0x6
#وصف_ڪريو S_LAZY_نشان_اشارا          0x7
#وصف_ڪريو S_نشان_STUBS                  0x8
#وصف_ڪريو S_MOD_INIT_FUNC_اشارا        0x9
#وصف_ڪريو S_MOD_رڪن_FUNC_اشارا        0xa

#وصف_ڪريو S_ATTR_خالص_INSTRUCTIONS        0x80000000
#وصف_ڪريو S_ATTR_SOME_INSTRUCTIONS        0x00000400
#وصف_ڪريو S_ATTR_DEBUG             	0x02000000


تعريفنوع uint32_t lc_str;

بنية dylib_command {
    uint32_t cmd;                   /* LC_ID_DYLIB, LC_LOAD_{,WEAK_}DYLIB,
                                       LC_REEXPORT_DYLIB */
    uint32_t cmdsize;               /* includes pathname string */
    lc_str   name;                  /* library's path name */
    uint32_t timestamp;             /* library's build time stamp */
    uint32_t current_نسخو;       /* library's current version number */
    uint32_t compatibility_نسخو; /* library's compatibility vers number*/
};

بنية rpath_command {
    uint32_t     cmd;           /* LC_RPATH */
    uint32_t     cmdsize;       /* includes string */
    lc_str       رستو;          /* path to add to run path */
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

#وصف_ڪريو PLATFORM_MACOS 1

بنية build_نسخو_command {
    uint32_t    cmd;            /* LC_BUILD_VERSION */
    uint32_t    cmdsize;        /* sizeof(struct build_version_command) plus */
                                /* ntools * sizeof(struct build_tool_version) */
    uint32_t    platform;       /* platform */
    uint32_t    minos;          /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    sdk;            /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    ntools;         /* number of tool entries following this */
};

بنية ذريعو_نسخو_command {
    uint32_t  cmd;      /* LC_SOURCE_VERSION */
    uint32_t  cmdsize;  /* 16 */
    uint64_t  نسخو;  /* A.B.C.D.E packed as a24.b10.c10.d10.e10 */
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

#وصف_ڪريو BIND_OPCODE_پورو                                        0x00
#وصف_ڪريو BIND_OPCODE_سيٽ_DYLIB_SPECIAL_IMM                       0x30
#وصف_ڪريو BIND_OPCODE_سيٽ_نشان_TRAILING_FLAGS_IMM               0x40
#وصف_ڪريو BIND_OPCODE_سيٽ_TYPE_IMM                                0x50
#وصف_ڪريو BIND_OPCODE_سيٽ_SEGMENT_AND_وٿي_ULEB                 0x70
#وصف_ڪريو BIND_OPCODE_DO_BIND                                     0x90

#وصف_ڪريو BIND_نشان_FLAGS_WEAK_IMPORT                           0x1

#وصف_ڪريو BIND_TYPE_اشارو                                       1
#وصف_ڪريو BIND_SPECIAL_DYLIB_FLAT_LOOKUP                          -2

#وصف_ڪريو REBASE_OPCODE_پورو                                      0x00
#وصف_ڪريو REBASE_OPCODE_سيٽ_TYPE_IMM                              0x10
#وصف_ڪريو REBASE_OPCODE_سيٽ_SEGMENT_AND_وٿي_ULEB               0x20
#وصف_ڪريو REBASE_OPCODE_DO_REBASE_IMM_TIMES                       0x50

#وصف_ڪريو REBASE_TYPE_اشارو                                     1

#وصف_ڪريو EXPORT_نشان_FLAGS_قسم_REGULAR                        0x00
#وصف_ڪريو EXPORT_نشان_FLAGS_قسم_ABSOLUTE                       0x02
#وصف_ڪريو EXPORT_نشان_FLAGS_WEAK_DEFINITION                     0x04

بنية dyld_info_command {
    uint32_t cmd;             /* LC_DYLD_INFO or LC_DYLD_INFO_ONLY */
    uint32_t cmdsize;         /* sizeof(struct dyld_info_command) */
    uint32_t rebase_off;      /* file offset to rebase info  */
    uint32_t rebase_سائيز;     /* size of rebase info   */
    uint32_t bind_off;        /* file offset to binding info   */
    uint32_t bind_سائيز;       /* size of binding info  */
    uint32_t weak_bind_off;   /* file offset to weak binding info   */
    uint32_t weak_bind_سائيز;  /* size of weak binding info  */
    uint32_t lazy_bind_off;   /* file offset to lazy binding info */
    uint32_t lazy_bind_سائيز;  /* size of lazy binding infs */
    uint32_t export_off;      /* file offset to lazy binding info */
    uint32_t export_سائيز;     /* size of lazy binding infs */
};

#وصف_ڪريو اڻسڌو_نشان_LOCAL   0x80000000

بنية داخلا_نقطو_command {
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
    sk_debug_سٽ,
    sk_debug_aranges,
    sk_debug_str,
    sk_debug_سٽ_str,
    sk_stab,
    sk_stab_str,
    sk_la_ptr,  // lazy pointers
    sk_init,
    sk_fini,
    sk_rw_معلومات,
    sk_bss,
    sk_linkedit,
    sk_آخري
};

بنية nlist_64 {
    uint32_t  n_strx;      /* index into the string table */
    uint8_t n_type;        /* type flag, see below */
    uint8_t n_sect;        /* section number or NO_SECT */
    uint16_t n_desc;       /* see <mach-o/stab.h> */
    uint64_t n_قدر;      /* value of this symbol (or stab offset) */
};

#وصف_ڪريو N_UNDF  0x0
#وصف_ڪريو N_ABS   0x2
#وصف_ڪريو N_EXT   0x1
#وصف_ڪريو N_SECT  0xe

#وصف_ڪريو N_WEAK_REF      0x0040
#وصف_ڪريو N_WEAK_DEF      0x0080

بنية macho {
    بنية mach_سرو_64 mh;
    صحيح *seg2lc, nseg;
    بنية ڀريو_command **lc;
    بنية داخلا_نقطو_command *ep;
    صحيح nlc;
    بنية {
        Section *s;
        صحيح machosect;
    } sk_منزل_sect[sk_آخري];
    صحيح *elfsectomacho;
    صحيح *e2msym;
    Section *symtab, *strtab, *indirsyms, *stubs, *exports;
    uint32_t ilocal, iextdef, iundef;
    صحيح stubsym, n_got, nr_plt;
    صحيح segment[sk_آخري];
#جيڪڏهن_وصف_ٿيل CONFIG_NEW_MACHO
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
    Section *stub_helper, *la_نشان_ptr;
    بنية dyld_info_command *dyldinfo;
    صحيح helpsym, lasym, dyld_ذاتي, dyld_stub_binder;
    صحيح n_lazy_bind;    
    بنية s_lazy_bind {
        صحيح section;
        صحيح bind_وٿي;
        صحيح la_نشان_وٿي;
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
#جيڪڏهن_پورو
};

#وصف_ڪريو SHT_LINKEDIT (SHT_LOOS + 42)
#وصف_ڪريو SHN_FROMDLL  (SHN_LOOS + 2)  /* Symbol is undefined, comes from a DLL */

ساكن فراغ * جوڙيو_lc(بنية macho *mo, uint32_t cmd, uint32_t cmdsize)
{
    بنية ڀريو_command *lc = tcc_mallocz(cmdsize);
    lc->cmd = cmd;
    lc->cmdsize = cmdsize;
    mo->lc = tcc_realloc(mo->lc, حجم(mo->lc[0]) * (mo->nlc + 1));
    mo->lc[mo->nlc++] = lc;
    أرجع lc;
}

ساكن بنية segment_command_64 * جوڙيو_segment(بنية macho *mo, ثابت حرف *name)
{
    بنية segment_command_64 *sc = جوڙيو_lc(mo, LC_SEGMENT_64, حجم(*sc));
    strncpy(sc->segname, name, 16);
    mo->seg2lc = tcc_realloc(mo->seg2lc, حجم(*mo->seg2lc) * (mo->nseg + 1));
    mo->seg2lc[mo->nseg++] = mo->nlc - 1;
    أرجع sc;
}

ساكن بنية segment_command_64 * get_segment(بنية macho *mo, صحيح i)
{
    أرجع (بنية segment_command_64 *) (mo->lc[mo->seg2lc[i]]);
}

ساكن صحيح جوڙيو_section(بنية macho *mo, بنية segment_command_64 **_seg, ثابت حرف *name)
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

ساكن فراغ * جوڙيو_dylib(بنية macho *mo, حرف *name)
{
    بنية dylib_command *lc;
    صحيح sz = (حجم(*lc) + لڙي_ڊيگهه(name) + 1 + 7) & -8;
    lc = جوڙيو_lc(mo, LC_ڀريو_DYLIB, sz);
    lc->name = حجم(*lc);
    strcpy((حرف*)lc + lc->name, name);
    lc->timestamp = 2;
    lc->current_نسخو = 1 << 16;
    lc->compatibility_نسخو = 1 << 16;
    أرجع lc;
}

ساكن صحيح uleb128_سائيز (بنانشان ڊگهو ڊگهو قدر)
{
    صحيح سائيز =  0;

    افعل {
        قدر >>= 7;
        سائيز++;
    } طالما (قدر != 0);
    أرجع سائيز;
}

ساكن فراغ write_uleb128(Section *section, uint64_t قدر)
{
    افعل {
        بنانشان حرف byte = قدر & 0x7f;
	uint8_t *ptr = section_ptr_جوڙيو(section, 1);

        قدر >>= 7;
        *ptr = byte | (قدر ? 0x80 : 0);
    } طالما (قدر != 0);
}

ساكن فراغ tcc_macho_جوڙيو_destructor(TCCState *s1)
{
    صحيح init_sym, mh_execute_سرو, at_exit_sym;
    Section *s;
    ElfW_Rel *rel;
    uint8_t *ptr;

    mh_execute_سرو = put_elf_sym(s1->symtab, -4096, 0,
				    ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				    متن_section->sh_انگ, "__mh_execute_header");
    s = ڳوليو_section(s1, ".fini_array");
    إذا (s->معلومات_وٿي == 0)
        أرجع; 
    init_sym = put_elf_sym(s1->symtab, متن_section->معلومات_وٿي, 0,
                           ELFW(ST_INFO)(STB_LOCAL, STT_FUNC), 0,
                           متن_section->sh_انگ, "___GLOBAL_init_65535");
    at_exit_sym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0,
                              SHN_UNDEF, "___cxa_atexit");
#جيڪڏهن_وصف_ٿيل TCC_هدف_X86_64
    ptr = section_ptr_جوڙيو(متن_section, 4);
    ptr[0] = 0x55;  // pushq   %rbp
    ptr[1] = 0x48;  // movq    %rsp, %rbp
    ptr[2] = 0x89;
    ptr[3] = 0xe5;
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        صحيح sym_اشاريو = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_جوڙيو(متن_section, 26);
        ptr[0] = 0x48;  // lea destructor(%rip),%rax
        ptr[1] = 0x8d;
        ptr[2] = 0x05;
        put_elf_reloca(s1->symtab, متن_section, 
		       متن_section->معلومات_وٿي - 23,
		       R_X86_64_PC32, sym_اشاريو, -4);
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
		       متن_section->معلومات_وٿي - 9,
		       R_X86_64_PC32, mh_execute_سرو, -4);
	ptr[21] = 0xe8; // call __cxa_atexit
        put_elf_reloca(s1->symtab, متن_section,
		       متن_section->معلومات_وٿي - 4,
		       R_X86_64_PLT32, at_exit_sym, -4);
    }
    ptr = section_ptr_جوڙيو(متن_section, 2);
    ptr[0] = 0x5d;  // pop   %rbp
    ptr[1] = 0xc3;  // ret
#وإلاإذا defined TCC_هدف_ARM64
    ptr = section_ptr_جوڙيو(متن_section, 8);
    write32le(ptr, 0xa9bf7bfd);     // stp     x29, x30, [sp, #-16]!
    write32le(ptr + 4, 0x910003fd); // mov     x29, sp
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        صحيح sym_اشاريو = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_جوڙيو(متن_section, 24);
        put_elf_reloc(s1->symtab, متن_section, 
		      متن_section->معلومات_وٿي - 24,
		      R_AARCH64_ADR_PREL_PG_HI21, sym_اشاريو);
        write32le(ptr, 0x90000000);      // adrp x0, destructor@page
        put_elf_reloc(s1->symtab, متن_section,
		      متن_section->معلومات_وٿي - 20,
		      R_AARCH64_LDST8_ABS_LO12_NC, sym_اشاريو);
        write32le(ptr + 4, 0x91000000);  // add x0,x0,destructor@pageoff
        write32le(ptr + 8, 0xd2800001);  // mov x1, #0
        put_elf_reloc(s1->symtab, متن_section, 
		      متن_section->معلومات_وٿي - 12,
		      R_AARCH64_ADR_PREL_PG_HI21, mh_execute_سرو);
        write32le(ptr + 12, 0x90000002);      // adrp x2, mh_execute_header@page
        put_elf_reloc(s1->symtab, متن_section,
		      متن_section->معلومات_وٿي - 8,
		      R_AARCH64_LDST8_ABS_LO12_NC, mh_execute_سرو);
        write32le(ptr + 16, 0x91000042);  // add x2,x2,mh_execute_header@pageoff
        put_elf_reloc(s1->symtab, متن_section,
		      متن_section->معلومات_وٿي - 4,
		      R_AARCH64_CALL26, at_exit_sym);
	write32le(ptr + 20, 0x94000000); // bl __cxa_atexit
    }
    ptr = section_ptr_جوڙيو(متن_section, 8);
    write32le(ptr, 0xa8c17bfd);     // ldp     x29, x30, [sp], #16
    write32le(ptr + 4, 0xd65f03c0); // ret
#جيڪڏهن_پورو
    s->reloc->معلومات_وٿي = s->معلومات_وٿي = 0;
    s->sh_flags &= ~SHF_ALLOC;
    جوڙيو_array (s1, ".init_array", init_sym);
}

#جيڪڏهن_وصف_ٿيل CONFIG_NEW_MACHO
ساكن فراغ bind_rebase_جوڙيو(بنية macho *mo, صحيح bind, صحيح sh_info,
			    ElfW_Rel *rel, بنية sym_attr *attr)
{
    mo->bind_rebase = tcc_realloc(mo->bind_rebase, (mo->n_bind_rebase + 1) *
		                  حجم(بنية bind_rebase));
    mo->bind_rebase[mo->n_bind_rebase].section = sh_info;
    mo->bind_rebase[mo->n_bind_rebase].bind = bind;
    mo->bind_rebase[mo->n_bind_rebase].rel = *rel;
    إذا (attr)
        mo->bind_rebase[mo->n_bind_rebase].rel.r_وٿي = attr->got_وٿي;
    mo->n_bind_rebase++;
    mo->n_bind += bind;
}

ساكن فراغ check_relocs(TCCState *s1, بنية macho *mo)
{
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    صحيح i, j, type, gotplt_داخلا, sym_اشاريو, for_ڪوڊ;
    uint32_t *pi, *goti;
    بنية sym_attr *attr;

    goti = عدم;
    mo->nr_plt = mo->n_got = 0;
    لكل (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        إذا (s->sh_type != SHT_RELX ||
	    !لڙي_ڀيٽ(s1->sections[s->sh_info]->name, ".debug_", 7))
            استمر;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_داخلا = gotplt_داخلا_type(type);
            for_ڪوڊ = ڪوڊ_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_اشاريو = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_اشاريو];
            إذا (sym->st_shndx == SHN_UNDEF
                || gotplt_داخلا == ALWAYS_GOTPLT_داخلا) {
                attr = get_sym_attr(s1, sym_اشاريو, 1);
                إذا (!attr->dyn_اشاريو) {
                    attr->got_وٿي = s1->got->معلومات_وٿي;
                    attr->plt_وٿي = -1;
                    attr->dyn_اشاريو = 1; /* used as flag */
                    section_ptr_جوڙيو(s1->got, PTR_سائيز);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_وٿي,
                                  R_JMP_جڳهه, sym_اشاريو);
	 	    goti = tcc_realloc(goti, (mo->n_got + 1) * حجم(*goti));
                    إذا (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        إذا (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (حرف *) symtab_section->link->معلومات + sym->st_name);
			goti[mo->n_got++] = اڻسڌو_نشان_LOCAL;
                    } وإلا {
                        goti[mo->n_got++] = mo->e2msym[sym_اشاريو];
                        إذا (sym->st_shndx == SHN_UNDEF
#جيڪڏهن_وصف_ٿيل TCC_هدف_X86_64
                            && type == R_X86_64_GOTPCREL
#وإلاإذا defined TCC_هدف_ARM64
                            && type == R_AARCH64_ADR_GOT_صفحو
#جيڪڏهن_پورو
                            ) {
			    attr->plt_وٿي = -mo->n_bind_rebase - 2;
			    bind_rebase_جوڙيو(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
			    s1->got->reloc->معلومات_وٿي -= حجم (ElfW_Rel);
			}
		        إذا (for_ڪوڊ && sym->st_shndx == SHN_UNDEF)
			    s1->got->reloc->معلومات_وٿي -= حجم (ElfW_Rel);
		    }
                }
                إذا (for_ڪوڊ && sym->st_shndx == SHN_UNDEF) {
		    إذا ((صحيح)attr->plt_وٿي < -1) {
			/* remove above bind and replace with plt */
			mo->bind_rebase[-attr->plt_وٿي - 2].bind = 2;
			attr->plt_وٿي = -1;
		    }
                    إذا (attr->plt_وٿي == -1) {
                        uint8_t *jmp;

                        attr->plt_وٿي = mo->stubs->معلومات_وٿي;
#جيڪڏهن_وصف_ٿيل TCC_هدف_X86_64
                        إذا (type != R_X86_64_PLT32)
                             استمر;
                        jmp = section_ptr_جوڙيو(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *ofs(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_وٿي + 2,
                                      R_X86_64_GOTPCREL, sym_اشاريو);
#وإلاإذا defined TCC_هدف_ARM64
                        إذا (type != R_AARCH64_CALL26)
                             استمر;
                        jmp = section_ptr_جوڙيو(mo->stubs, 12);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_وٿي,
                                      R_AARCH64_ADR_GOT_صفحو, sym_اشاريو);
                        write32le(jmp, // adrp x16, #sym
                                  0x90000010);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_وٿي + 4,
                                      R_AARCH64_LD64_GOT_LO12_NC, sym_اشاريو);
                        write32le(jmp + 4, // ld x16,[x16, #sym]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);
#جيڪڏهن_پورو
			bind_rebase_جوڙيو(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
                        pi = section_ptr_جوڙيو(mo->indirsyms, حجم(*pi));
                        *pi = mo->e2msym[sym_اشاريو];
                        mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_وٿي;
                }
            }
	    إذا (type == R_معلومات_PTR || type == R_JMP_جڳهه)
		bind_rebase_جوڙيو(mo, sym->st_shndx == SHN_UNDEF ? 1 : 0,
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
    pi = section_ptr_جوڙيو(mo->indirsyms, mo->n_got * حجم(*pi));
    يادگيري_نقل(pi, goti, mo->n_got * حجم(*pi));
    tcc_free(goti);
}

#وإلا

ساكن فراغ check_relocs(TCCState *s1, بنية macho *mo)
{
    uint8_t *jmp;
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    صحيح i, type, gotplt_داخلا, sym_اشاريو, for_ڪوڊ;
    صحيح bind_وٿي, la_نشان_وٿي;
    uint32_t *pi, *goti;
    بنية sym_attr *attr;

#جيڪڏهن_وصف_ٿيل TCC_هدف_X86_64
    jmp = section_ptr_جوڙيو(mo->stub_helper, 16);
    jmp[0] = 0x4c;  /* leaq _dyld_private(%rip), %r11 */
    jmp[1] = 0x8d;
    jmp[2] = 0x1d;
    put_elf_reloca(s1->symtab, mo->stub_helper, 3,
		   R_X86_64_PC32, mo->dyld_ذاتي, -4);
    jmp[7] = 0x41;  /* pushq %r11 */
    jmp[8] = 0x53;
    jmp[9] = 0xff;  /* jmpq    *dyld_stub_binder@GOT(%rip) */
    jmp[10] = 0x25;
    put_elf_reloca(s1->symtab, mo->stub_helper, 11,
		   R_X86_64_GOTPCREL, mo->dyld_stub_binder, -4);
    jmp[15] = 0x90; /* nop */
#وإلاإذا defined TCC_هدف_ARM64
    jmp = section_ptr_جوڙيو(mo->stub_helper, 24);
    put_elf_reloc(s1->symtab, mo->stub_helper, 0,
		  R_AARCH64_ADR_PREL_PG_HI21, mo->dyld_ذاتي);
    write32le(jmp, 0x90000011); // adrp x17, _dyld_private@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 4,
		  R_AARCH64_LDST64_ABS_LO12_NC, mo->dyld_ذاتي);
    write32le(jmp + 4, 0x91000231); // add x17,x17,_dyld_private@pageoff
    write32le(jmp + 8, 0xa9bf47f0); // stp x16/x17, [sp, #-16]!
    put_elf_reloc(s1->symtab, mo->stub_helper, 12,
		  R_AARCH64_ADR_GOT_صفحو, mo->dyld_stub_binder);
    write32le(jmp + 12, 0x90000010); // adrp x16, dyld_stub_binder@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 16,
		  R_AARCH64_LD64_GOT_LO12_NC, mo->dyld_stub_binder);
    write32le(jmp + 16, 0xf9400210); // ldr x16,[x16,dyld_stub_binder@pageoff]
    write32le(jmp + 20, 0xd61f0200); // br x16
#جيڪڏهن_پورو
    
    goti = عدم;
    mo->nr_plt = mo->n_got = 0;
    لكل (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        إذا (s->sh_type != SHT_RELX ||
	    !لڙي_ڀيٽ(s1->sections[s->sh_info]->name, ".debug_", 7))
            استمر;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_داخلا = gotplt_داخلا_type(type);
            for_ڪوڊ = ڪوڊ_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_اشاريو = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_اشاريو];
            إذا (sym->st_shndx == SHN_UNDEF
                || gotplt_داخلا == ALWAYS_GOTPLT_داخلا) {
                attr = get_sym_attr(s1, sym_اشاريو, 1);
                إذا (!attr->dyn_اشاريو) {
                    attr->got_وٿي = s1->got->معلومات_وٿي;
                    attr->plt_وٿي = -1;
                    attr->dyn_اشاريو = 1; /* used as flag */
		    section_ptr_جوڙيو(s1->got, PTR_سائيز);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_وٿي,
                                  R_JMP_جڳهه, sym_اشاريو);
		    goti = tcc_realloc(goti, (mo->n_got + 1) * حجم(*goti));
                    إذا (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        إذا (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (حرف *) symtab_section->link->معلومات + sym->st_name);
			goti[mo->n_got++] = اڻسڌو_نشان_LOCAL;
                    } وإلا {
			goti[mo->n_got++] = mo->e2msym[sym_اشاريو];
			إذا (sym->st_shndx == SHN_UNDEF
#جيڪڏهن_وصف_ٿيل TCC_هدف_X86_64
			    && type == R_X86_64_GOTPCREL
#وإلاإذا defined TCC_هدف_ARM64
			    && type == R_AARCH64_ADR_GOT_صفحو
#جيڪڏهن_پورو
			    ) {
			    mo->bind =
			        tcc_realloc(mo->bind,
					    (mo->n_bind + 1) *
					    حجم(بنية bind));
			    mo->bind[mo->n_bind].section = s1->got->reloc->sh_info;
			    mo->bind[mo->n_bind].rel = save_rel;
                            mo->bind[mo->n_bind].rel.r_وٿي = attr->got_وٿي;
			    mo->n_bind++;
			    s1->got->reloc->معلومات_وٿي -= حجم (ElfW_Rel);
			}
		    }
                }
                إذا (for_ڪوڊ && sym->st_shndx == SHN_UNDEF) {
                    إذا (attr->plt_وٿي == -1) {
                        attr->plt_وٿي = mo->stubs->معلومات_وٿي;
#جيڪڏهن_وصف_ٿيل TCC_هدف_X86_64
			إذا (type != R_X86_64_PLT32)
			     استمر;
			/* __stubs */
                        jmp = section_ptr_جوڙيو(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *__la_symbol_ptr(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->معلومات_وٿي - 4,
                                       R_X86_64_PC32, mo->lasym,
				       mo->la_نشان_ptr->معلومات_وٿي - 4);

			/* __stub_helper */
			bind_وٿي = mo->stub_helper->معلومات_وٿي + 1;
                        jmp = section_ptr_جوڙيو(mo->stub_helper, 10);
                        jmp[0] = 0x68;  /* pushq $bind_offset */
                        jmp[5] = 0xe9;  /* jmpq __stub_helper */
                        write32le(jmp + 6, -mo->stub_helper->معلومات_وٿي);

			/* __la_symbol_ptr */
			la_نشان_وٿي = mo->la_نشان_ptr->معلومات_وٿي;
                        put_elf_reloca(s1->symtab, mo->la_نشان_ptr,
				       mo->la_نشان_ptr->معلومات_وٿي,
				       R_معلومات_PTR, mo->helpsym,
				       mo->stub_helper->معلومات_وٿي - 10);
			section_ptr_جوڙيو(mo->la_نشان_ptr, PTR_سائيز);
#وإلاإذا defined TCC_هدف_ARM64
			إذا (type != R_AARCH64_CALL26)
			     استمر;
			/* __stubs */
                        jmp = section_ptr_جوڙيو(mo->stubs, 12);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->معلومات_وٿي - 12,
                                       R_AARCH64_ADR_PREL_PG_HI21, mo->lasym,
				       mo->la_نشان_ptr->معلومات_وٿي);
                        write32le(jmp, // adrp x16, __la_symbol_ptr@page
                                  0x90000010);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->معلومات_وٿي - 8,
                                       R_AARCH64_LDST64_ABS_LO12_NC, mo->lasym,
				       mo->la_نشان_ptr->معلومات_وٿي);
                        write32le(jmp + 4, // ldr x16,[x16, __la_symbol_ptr@pageoff]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);

			/* __stub_helper */
			bind_وٿي = mo->stub_helper->معلومات_وٿي + 8;
                        jmp = section_ptr_جوڙيو(mo->stub_helper, 12);
                        write32le(jmp + 0, // ldr  w16, l0
                                  0x18000050);
                        write32le(jmp + 4, // b stubHelperHeader
                                  0x14000000 +
				  ((-(mo->stub_helper->معلومات_وٿي - 8) / 4) &
				   0x3ffffff));
                        write32le(jmp + 8, 0); // l0: .long bind_offset

			/* __la_symbol_ptr */
			la_نشان_وٿي = mo->la_نشان_ptr->معلومات_وٿي;
                        put_elf_reloca(s1->symtab, mo->la_نشان_ptr,
				       mo->la_نشان_ptr->معلومات_وٿي,
				       R_معلومات_PTR, mo->helpsym,
				       mo->stub_helper->معلومات_وٿي - 12);
			section_ptr_جوڙيو(mo->la_نشان_ptr, PTR_سائيز);
#جيڪڏهن_پورو
                        mo->s_lazy_bind =
                            tcc_realloc(mo->s_lazy_bind, (mo->n_lazy_bind + 1) *
                                        حجم(بنية s_lazy_bind));
                        mo->s_lazy_bind[mo->n_lazy_bind].section =
                            mo->stub_helper->reloc->sh_info;
                        mo->s_lazy_bind[mo->n_lazy_bind].bind_وٿي =
			    bind_وٿي;
                        mo->s_lazy_bind[mo->n_lazy_bind].la_نشان_وٿي =
			    la_نشان_وٿي;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel = save_rel;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel.r_وٿي =
                            attr->plt_وٿي;
                        mo->n_lazy_bind++;
			pi = section_ptr_جوڙيو(mo->indirsyms, حجم(*pi));
			*pi = mo->e2msym[sym_اشاريو];
			mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_وٿي;
                }
            }
            إذا (type == R_معلومات_PTR || type == R_JMP_جڳهه) {
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
    pi = section_ptr_جوڙيو(mo->indirsyms, mo->n_got * حجم(*pi));
    يادگيري_نقل(pi, goti, mo->n_got * حجم(*pi));
    pi = section_ptr_جوڙيو(mo->indirsyms, mo->nr_plt * حجم(*pi));
    يادگيري_نقل(pi, mo->indirsyms->معلومات, mo->nr_plt * حجم(*pi));
    tcc_free(goti);
}
#جيڪڏهن_پورو

ساكن صحيح check_symbols(TCCState *s1, بنية macho *mo)
{
    صحيح sym_اشاريو, sym_پڇاڙي;
    صحيح ret = 0;

    mo->ilocal = mo->iextdef = mo->iundef = -1;
    sym_پڇاڙي = symtab_section->معلومات_وٿي / حجم(ElfW(Sym));
    لكل (sym_اشاريو = 1; sym_اشاريو < sym_پڇاڙي; ++sym_اشاريو) {
        صحيح elf_اشاريو = ((بنية nlist_64 *)mo->symtab->معلومات + sym_اشاريو - 1)->n_قدر;
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->معلومات + elf_اشاريو;
        ثابت حرف *name = (حرف*)symtab_section->link->معلومات + sym->st_name;
        بنانشان type = ELFW(ST_TYPE)(sym->st_info);
        بنانشان bind = ELFW(ST_BIND)(sym->st_info);
        بنانشان vis  = ELFW(ST_VISIBILITY)(sym->st_other);

        dprintf("%4d (%4d): %09lx %4d %4d %4d %3d %s\n",
                sym_اشاريو, elf_اشاريو, (ڊگهو)sym->st_قدر,
                type, bind, vis, sym->st_shndx, name);
        إذا (bind == STB_LOCAL) {
            إذا (mo->ilocal == -1)
              mo->ilocal = sym_اشاريو - 1;
            إذا (mo->iextdef != -1 || mo->iundef != -1)
              tcc_error("local syms after global ones");
        } وإلا إذا (sym->st_shndx != SHN_UNDEF) {
            إذا (mo->iextdef == -1)
              mo->iextdef = sym_اشاريو - 1;
            إذا (mo->iundef != -1)
              tcc_error("external defined symbol after undefined");
        } وإلا إذا (sym->st_shndx == SHN_UNDEF) {
            إذا (mo->iundef == -1)
              mo->iundef = sym_اشاريو - 1;
            إذا (ELFW(ST_BIND)(sym->st_info) == STB_WEAK
		|| s1->output_type != TCC_OUTPUT_EXE
                || ڳوليو_elf_sym(s1->dynsymtab_section, name)) {
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

ساكن فراغ convert_نشان(TCCState *s1, بنية macho *mo, بنية nlist_64 *pn)
{
    بنية nlist_64 n = *pn;
    ElfSym *sym = (ElfW(Sym) *)symtab_section->معلومات + pn->n_قدر;
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
      إذا (لڙي_ڀيٽ(s1->sections[sym->st_shndx]->name, ".debug_", 7))
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
    n.n_قدر = sym->st_قدر;
    *pn = n;
}

ساكن فراغ convert_symbols(TCCState *s1, بنية macho *mo)
{
    بنية nlist_64 *pn;
    for_each_elem(mo->symtab, 0, pn, بنية nlist_64)
        convert_نشان(s1, mo, pn);
}

ساكن صحيح machosymcmp(ثابت فراغ *_a, ثابت فراغ *_b, فراغ *arg)
{
    TCCState *s1 = arg;
    صحيح ea = ((بنية nlist_64 *)_a)->n_قدر;
    صحيح eb = ((بنية nlist_64 *)_b)->n_قدر;
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
ساكن فراغ tcc_qsort (فراغ  *بنياد, سائيز_t nel, سائيز_t ويڪر,
                       صحيح (*comp)(ثابت فراغ *, ثابت فراغ *, فراغ *), فراغ *arg)
{
    سائيز_t wnel, gap, wgap, i, j, k;
    حرف *a, *b, tmp;

    wnel = ويڪر * nel;
    لكل (gap = 0; ++gap < nel;)
        gap *= 3;
    طالما ( gap /= 3 ) {
        wgap = ويڪر * gap;
        لكل (i = wgap; i < wnel; i += ويڪر) {
            لكل (j = i - wgap; ;j -= wgap) {
                a = j + (حرف *)بنياد;
                b = a + wgap;
                إذا ( (*comp)(a, b, arg) <= 0 )
                    اكسر;
                k = ويڪر;
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
    صحيح sym_اشاريو, sym_پڇاڙي;
    بنية nlist_64 *pn;

    /* Stub creation belongs to check_relocs, but we need to create
       the symbol now, so its included in the sorting.  */
    mo->stubs = new_section(s1, "__stubs", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->stubsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stubs->sh_انگ, ".__stubs");
#جيڪڏهن_وصف_ٿيل CONFIG_NEW_MACHO
    mo->chained_fixups = new_section(s1, "CHAINED_FIXUPS",
				     SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#وإلا
    mo->stub_helper = new_section(s1, "__stub_helper", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    mo->la_نشان_ptr = new_section(s1, "__la_symbol_ptr", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->helpsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stub_helper->sh_انگ, ".__stub_helper");
    mo->lasym = put_elf_sym(s1->symtab, 0, 0,
                            ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                            mo->la_نشان_ptr->sh_انگ, ".__la_symbol_ptr");
    section_ptr_جوڙيو(معلومات_section, -معلومات_section->معلومات_وٿي & (PTR_سائيز - 1));
    mo->dyld_ذاتي = put_elf_sym(s1->symtab, معلومات_section->معلومات_وٿي, PTR_سائيز,
                                   ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT), 0,
                                   معلومات_section->sh_انگ, ".__dyld_private");
    section_ptr_جوڙيو(معلومات_section, PTR_سائيز);
    mo->dyld_stub_binder = put_elf_sym(s1->symtab, 0, 0,
                		       ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				       SHN_UNDEF, "dyld_stub_binder");
    mo->rebase = new_section(s1, "REBASE", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->binding = new_section(s1, "BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->weak_binding = new_section(s1, "WEAK_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->lazy_binding = new_section(s1, "LAZY_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#جيڪڏهن_پورو
    mo->exports = new_section(s1, "EXPORT", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->indirsyms = new_section(s1, "LEINDIR", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);

    mo->symtab = new_section(s1, "LESYMTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->strtab = new_section(s1, "LESTRTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    put_elf_str(mo->strtab, " "); /* Mach-O starts strtab with a space */
    sym_پڇاڙي = symtab_section->معلومات_وٿي / حجم(ElfW(Sym));
    pn = section_ptr_جوڙيو(mo->symtab, حجم(*pn) * (sym_پڇاڙي - 1));
    لكل (sym_اشاريو = 1; sym_اشاريو < sym_پڇاڙي; ++sym_اشاريو) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->معلومات + sym_اشاريو;
        ثابت حرف *name = (حرف*)symtab_section->link->معلومات + sym->st_name;
        pn[sym_اشاريو - 1].n_strx = put_elf_str(mo->strtab, name);
        pn[sym_اشاريو - 1].n_قدر = sym_اشاريو;
    }
    section_ptr_جوڙيو(mo->strtab, -mo->strtab->معلومات_وٿي & (PTR_سائيز - 1));
    tcc_qsort(pn, sym_پڇاڙي - 1, حجم(*pn), machosymcmp, s1);
    mo->e2msym = tcc_malloc(sym_پڇاڙي * حجم(*mo->e2msym));
    mo->e2msym[0] = -1;
    لكل (sym_اشاريو = 1; sym_اشاريو < sym_پڇاڙي; ++sym_اشاريو) {
        mo->e2msym[pn[sym_اشاريو - 1].n_قدر] = sym_اشاريو - 1;
    }
}

ثابت بنية {
    صحيح seg_initial;
    uint32_t flags;
    ثابت حرف *name;
} skinfo[sk_آخري] = {
    /*[sk_unknown] =*/        { 0 },
    /*[sk_discard] =*/        { 0 },
    /*[sk_text] =*/           { 1, S_REGULAR | S_ATTR_خالص_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS, "__text" },
    /*[sk_stubs] =*/          { 1, S_REGULAR | S_ATTR_خالص_INSTRUCTIONS | S_نشان_STUBS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stubs" },
    /*[sk_stub_helper] =*/    { 1, S_REGULAR | S_ATTR_خالص_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stub_helper" },
    /*[sk_ro_data] =*/        { 2, S_REGULAR, "__rodata" },
    /*[sk_uw_info] =*/        { 0 },
    /*[sk_nl_ptr] =*/         { 2, S_NON_LAZY_نشان_اشارا, "__got" },
    /*[sk_debug_info] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_info" },
    /*[sk_debug_abbrev] =*/   { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_abbrev" },
    /*[sk_debug_line] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line" },
    /*[sk_debug_aranges] =*/  { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_aranges" },
    /*[sk_debug_str] =*/      { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_str" },
    /*[sk_debug_line_str] =*/ { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line_str" },
    /*[sk_stab] =*/           { 4, S_REGULAR, "__stab" },
    /*[sk_stab_str] =*/       { 4, S_REGULAR, "__stab_str" },
    /*[sk_la_ptr] =*/         { 4, S_LAZY_نشان_اشارا, "__la_symbol_ptr" },
    /*[sk_init] =*/           { 4, S_MOD_INIT_FUNC_اشارا, "__mod_init_func" },
    /*[sk_fini] =*/           { 4, S_MOD_رڪن_FUNC_اشارا, "__mod_term_func" },
    /*[sk_rw_data] =*/        { 4, S_REGULAR, "__data" },
    /*[sk_bss] =*/            { 4, S_ZEROFILL, "__bss" },
    /*[sk_linkedit] =*/       { 5, S_REGULAR, عدم },
};

#وصف_ڪريو	شروعات_3	((uint64_t)1 << 32)

ثابت بنية {
    صحيح استعمال_ٿيل;
    ثابت حرف *name;
    uint64_t vmaddr;
    uint64_t vmsize;
    vm_prot_t maxprot;
    vm_prot_t initprot;
    uint32_t flags;
} all_segment[] = {
    { 1, "__PAGEZERO",       0, شروعات_3, 0, 0,            0 },
    { 0, "__TEXT",       شروعات_3,     0, 5, 5,            0 },
    { 0, "__DATA_CONST",    -1,     0, 3, 3, SG_READ_ONLY },
    { 0, "__DWARF",         -1,     0, 7, 3,            0 },
    { 0, "__DATA",          -1,     0, 3, 3,            0 },
    { 1, "__LINKEDIT",      -1,     0, 1, 1,            0 },
};

#وصف_ڪريو	N_SEGMENT	(حجم(all_segment)/حجم(all_segment[0]))

#جيڪڏهن_وصف_ٿيل CONFIG_NEW_MACHO
ساكن فراغ calc_fixup_سائيز(TCCState *s1, بنية macho *mo)
{
    صحيح i, سائيز;

    سائيز = (حجم(بنية dyld_chained_fixups_سرو) + 7) & -8;
    سائيز += (حجم(بنية dyld_chained_starts_اندريون_image) + (mo->nseg - 1) * حجم(uint32_t) + 7) & -8;
    لكل (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	صحيح صفحو_ڳڻپ = (get_segment(mo, i)->vmsize + SEG_صفحو_سائيز - 1) / SEG_صفحو_سائيز;
	سائيز += (حجم(بنية dyld_chained_starts_اندريون_segment) + (صفحو_ڳڻپ - 1) * حجم(uint16_t) + 7) & -8;
    }
    سائيز += mo->n_bind * حجم (بنية dyld_chained_import) + 1;
    لكل (i = 0; i < mo->n_bind_rebase; i++) {
	إذا (mo->bind_rebase[i].bind) {
	    صحيح sym_اشاريو = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_اشاريو];
	    ثابت حرف *name = (حرف *) symtab_section->link->معلومات + sym->st_name;
	    سائيز += لڙي_ڊيگهه(name) + 1;
	}
    }
    سائيز = (سائيز + 7) & -8;
    section_ptr_جوڙيو(mo->chained_fixups, سائيز);
}

#وإلا

ساكن فراغ سيٽ_segment_and_وٿي(TCCState *s1, بنية macho *mo, addr_t addr,
				   uint8_t *ptr, صحيح opcode,
				   Section *sec, addr_t وٿي)
{
    صحيح i;
    بنية segment_command_64 *seg = عدم;

    لكل (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	seg = get_segment(mo, i);
	إذا (addr >= seg->vmaddr && addr < (seg->vmaddr + seg->vmsize))
	    اكسر;
    }
    *ptr = opcode | i;
    write_uleb128(sec, وٿي - seg->vmaddr);
}

ساكن فراغ bind_rebase(TCCState *s1, بنية macho *mo)
{
    صحيح i;
    uint8_t *ptr;
    ElfW(Sym) *sym;
    ثابت حرف *name;

    لكل (i = 0; i < mo->n_lazy_bind; i++) {
	صحيح sym_اشاريو = ELFW(R_SYM)(mo->s_lazy_bind[i].rel.r_info);

	sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_اشاريو];
	name = (حرف *) symtab_section->link->معلومات + sym->st_name;
	write32le(mo->stub_helper->معلومات +
		  mo->s_lazy_bind[i].bind_وٿي,
		  mo->lazy_binding->معلومات_وٿي);
	ptr = section_ptr_جوڙيو(mo->lazy_binding, 1);
	سيٽ_segment_and_وٿي(s1, mo, mo->la_نشان_ptr->sh_addr, ptr,
			       BIND_OPCODE_سيٽ_SEGMENT_AND_وٿي_ULEB,
			       mo->lazy_binding,
			       mo->s_lazy_bind[i].la_نشان_وٿي +
			       mo->la_نشان_ptr->sh_addr);
	ptr = section_ptr_جوڙيو(mo->lazy_binding, 5 + لڙي_ڊيگهه(name));
	*ptr++ = BIND_OPCODE_سيٽ_DYLIB_SPECIAL_IMM |
		 (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
	*ptr++ = BIND_OPCODE_سيٽ_نشان_TRAILING_FLAGS_IMM | 0;
	strcpy((حرف *)ptr, name);
	ptr += لڙي_ڊيگهه(name) + 1;
	*ptr++ = BIND_OPCODE_DO_BIND;
	*ptr = BIND_OPCODE_پورو;
    }
    لكل (i = 0; i < mo->n_rebase; i++) {
	Section *s = s1->sections[mo->s_rebase[i].section];

	ptr = section_ptr_جوڙيو(mo->rebase, 2);
	*ptr++ = REBASE_OPCODE_سيٽ_TYPE_IMM | REBASE_TYPE_اشارو;
	سيٽ_segment_and_وٿي(s1, mo, s->sh_addr, ptr,
			       REBASE_OPCODE_سيٽ_SEGMENT_AND_وٿي_ULEB,
			       mo->rebase,
			       mo->s_rebase[i].rel.r_وٿي +
			       s->sh_addr);
	ptr = section_ptr_جوڙيو(mo->rebase, 1);
	*ptr = REBASE_OPCODE_DO_REBASE_IMM_TIMES | 1;
    }
    لكل (i = 0; i < mo->n_bind; i++) {
	صحيح sym_اشاريو = ELFW(R_SYM)(mo->bind[i].rel.r_info);
	Section *s = s1->sections[mo->bind[i].section];
	Section *binding;

	sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_اشاريو];
	name = (حرف *) symtab_section->link->معلومات + sym->st_name;
	binding = ELFW(ST_BIND)(sym->st_info) == STB_WEAK
	    ? mo->weak_binding : mo->binding;
        ptr = section_ptr_جوڙيو(binding, 4 + (binding == mo->binding) +
			     	       لڙي_ڊيگهه(name));
	إذا (binding == mo->binding)
            *ptr++ = BIND_OPCODE_سيٽ_DYLIB_SPECIAL_IMM |
	             (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
        *ptr++ = BIND_OPCODE_سيٽ_نشان_TRAILING_FLAGS_IMM |
		 (binding == mo->weak_binding
		  ? BIND_نشان_FLAGS_WEAK_IMPORT : 0);
        strcpy((حرف *)ptr, name);
        ptr += لڙي_ڊيگهه(name) + 1;
        *ptr++ = BIND_OPCODE_سيٽ_TYPE_IMM | BIND_TYPE_اشارو;
	سيٽ_segment_and_وٿي(s1, mo, s->sh_addr, ptr,
			       BIND_OPCODE_سيٽ_SEGMENT_AND_وٿي_ULEB,
			       binding,
			       mo->bind[i].rel.r_وٿي + s->sh_addr);
        ptr = section_ptr_جوڙيو(binding, 1);
        *ptr++ = BIND_OPCODE_DO_BIND;
    }
    إذا (mo->rebase->معلومات_وٿي) {
        ptr = section_ptr_جوڙيو(mo->rebase, 1);
        *ptr = REBASE_OPCODE_پورو;
    }
    إذا (mo->binding->معلومات_وٿي) {
        ptr = section_ptr_جوڙيو(mo->binding, 1);
        *ptr = BIND_OPCODE_پورو;
    }
    إذا (mo->weak_binding->معلومات_وٿي) {
        ptr = section_ptr_جوڙيو(mo->weak_binding, 1);
        *ptr = BIND_OPCODE_پورو;
    }
    tcc_free(mo->s_lazy_bind);
    tcc_free(mo->s_rebase);
    tcc_free(mo->bind);
}
#جيڪڏهن_پورو

بنية trie_info {
    ثابت حرف *name;
    صحيح flag;
    addr_t addr;
    صحيح str_سائيز;
    صحيح رڪن_سائيز;
};

بنية trie_ڳنڍ {
    صحيح شروعات;
    صحيح پڇاڙي;
    صحيح اشاريو_شروعات;
    صحيح اشاريو_پڇاڙي;
    صحيح n_ٻار;
    بنية trie_ڳنڍ *ٻار;
};

بنية trie_seq {
    صحيح n_ٻار;
    بنية trie_ڳنڍ *ڳنڍ;
    صحيح وٿي;
    صحيح nest_وٿي;
};

ساكن فراغ create_trie(بنية trie_ڳنڍ *ڳنڍ,
                        صحيح from, صحيح منزل, صحيح اشاريو_شروعات,
                        صحيح n_trie, بنية trie_info *trie)
{
    صحيح i;
    صحيح شروعات, پڇاڙي, اشاريو_پڇاڙي;
    حرف cur;
    بنية trie_ڳنڍ *ٻار;

    لكل (i = from; i < منزل; i = پڇاڙي) {
        cur = trie[i].name[اشاريو_شروعات];
        شروعات = i++;
        لكل (; i < منزل; i++)
            إذا (cur != trie[i].name[اشاريو_شروعات])
                اكسر;
        پڇاڙي = i;
        إذا (شروعات == پڇاڙي - 1 ||
            (trie[شروعات].name[اشاريو_شروعات] &&
             trie[شروعات].name[اشاريو_شروعات + 1] == 0))
            اشاريو_پڇاڙي = trie[شروعات].str_سائيز - 1;
        وإلا {
            اشاريو_پڇاڙي = اشاريو_شروعات + 1;
            لكل (;;) {
                cur = trie[شروعات].name[اشاريو_پڇاڙي];
                لكل (i = شروعات + 1; i < پڇاڙي; i++)
                    إذا (cur != trie[i].name[اشاريو_پڇاڙي])
                        اكسر;
                إذا (trie[شروعات].name[اشاريو_پڇاڙي] &&
                    trie[شروعات].name[اشاريو_پڇاڙي + 1] == 0) {
                    پڇاڙي = شروعات + 1;
                    اشاريو_پڇاڙي = trie[شروعات].str_سائيز - 1;
                    اكسر;
                }
                إذا (i != پڇاڙي)
                    اكسر;
                اشاريو_پڇاڙي++;
            }
        }
        ڳنڍ->ٻار = tcc_realloc(ڳنڍ->ٻار,
                                  (ڳنڍ->n_ٻار + 1) *
                                  حجم(بنية trie_ڳنڍ));
        ٻار = &ڳنڍ->ٻار[ڳنڍ->n_ٻار];
        ٻار->شروعات = شروعات;
        ٻار->پڇاڙي = پڇاڙي;
        ٻار->اشاريو_شروعات = اشاريو_شروعات;
        ٻار->اشاريو_پڇاڙي = اشاريو_پڇاڙي;
        ٻار->n_ٻار = 0;
        ٻار->ٻار = عدم;
        ڳنڍ->n_ٻار++;
        إذا (شروعات != پڇاڙي - 1)
            create_trie(ٻار, شروعات, پڇاڙي, اشاريو_پڇاڙي, n_trie, trie);
    }
}

ساكن صحيح create_seq(صحيح *وٿي, صحيح *n_seq, بنية trie_seq **seq,
                        بنية trie_ڳنڍ *ڳنڍ,
                        صحيح n_trie, بنية trie_info *trie)
{
    صحيح i, nest_وٿي, آخري_seq = *n_seq, retval = *وٿي;
    بنية trie_seq *p_seq;
    بنية trie_ڳنڍ *p_nest;

    لكل (i = 0; i < ڳنڍ->n_ٻار; i++) {
        p_nest = &ڳنڍ->ٻار[i];
        *seq = tcc_realloc(*seq, (*n_seq + 1) * حجم(بنية trie_seq));
        p_seq = &(*seq)[(*n_seq)++];
        p_seq->n_ٻار = i == 0 ? ڳنڍ->n_ٻار : -1;
        p_seq->ڳنڍ = p_nest;
        p_seq->وٿي = *وٿي;
        p_seq->nest_وٿي = 0;
        *وٿي += (i == 0 ? 1 + 1 : 0) +
                   p_nest->اشاريو_پڇاڙي - p_nest->اشاريو_شروعات + 1 + 3;
    }
    لكل (i = 0; i < ڳنڍ->n_ٻار; i++) {
        nest_وٿي =
            create_seq(وٿي, n_seq, seq, &ڳنڍ->ٻار[i], n_trie, trie);
        p_seq = &(*seq)[آخري_seq + i];
        p_seq->nest_وٿي = nest_وٿي;
    }
    أرجع retval;
}

ساكن فراغ ڳنڍ_free(بنية trie_ڳنڍ *ڳنڍ)
{
    صحيح i;

    لكل (i = 0; i < ڳنڍ->n_ٻار; i++)
	ڳنڍ_free(&ڳنڍ->ٻار[i]);
    tcc_free(ڳنڍ->ٻار);
}

ساكن صحيح triecmp(ثابت فراغ *_a, ثابت فراغ *_b, فراغ *arg)
{
    بنية trie_info *a = (بنية trie_info *) _a;
    بنية trie_info *b = (بنية trie_info *) _b;
    صحيح len_a = لڙي_ڊيگهه(a->name);
    صحيح len_b = لڙي_ڊيگهه(b->name);

    /* strange sorting needed. Name 'xx' should be after 'xx1' */
    إذا (!لڙي_ڀيٽ(a->name, b->name, len_a < len_b ? len_a : len_b))
	أرجع len_a < len_b ? 1 : (len_a > len_b ? -1 : 0);
    أرجع strcmp(a->name, b->name);
}

ساكن فراغ export_trie(TCCState *s1, بنية macho *mo)
{
    صحيح i, سائيز, وٿي = 0, save_وٿي;
    uint8_t *ptr;
    صحيح sym_اشاريو;
    صحيح sym_پڇاڙي = symtab_section->معلومات_وٿي / حجم(ElfW(Sym));
    صحيح n_trie = 0, n_seq = 0;
    بنية trie_info *trie = عدم, *p_trie;
    بنية trie_ڳنڍ ڳنڍ, *p_ڳنڍ;
    بنية trie_seq *seq = عدم;
    addr_t vm_addr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;

    لكل (sym_اشاريو = 1; sym_اشاريو < sym_پڇاڙي; ++sym_اشاريو) {
	ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->معلومات + sym_اشاريو;
	ثابت حرف *name = (حرف*)symtab_section->link->معلومات + sym->st_name;

	إذا (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE &&
            (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL ||
	     ELFW(ST_BIND)(sym->st_info) == STB_WEAK)) {
	    صحيح flag = EXPORT_نشان_FLAGS_قسم_REGULAR;
	    addr_t addr =
		sym->st_قدر + s1->sections[sym->st_shndx]->sh_addr - vm_addr;

	    إذا (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
		flag |= EXPORT_نشان_FLAGS_WEAK_DEFINITION;
	    dprintf ("%s %d %llx\n", name, flag, (ڊگهو ڊگهو)addr + vm_addr);
	    trie = tcc_realloc(trie, (n_trie + 1) * حجم(بنية trie_info));
	    trie[n_trie].name = name;
	    trie[n_trie].flag = flag;
	    trie[n_trie].addr = addr;
	    trie[n_trie].str_سائيز = لڙي_ڊيگهه(name) + 1;
	    trie[n_trie].رڪن_سائيز = uleb128_سائيز(flag) + uleb128_سائيز(addr);
	    n_trie++;
	}
    }
    إذا (n_trie) {
        tcc_qsort(trie, n_trie, حجم(بنية trie_info), triecmp, عدم);
	memset(&ڳنڍ, 0, حجم(ڳنڍ));
        create_trie(&ڳنڍ, 0, n_trie, 0, n_trie, trie);
	create_seq(&وٿي, &n_seq, &seq, &ڳنڍ, n_trie, trie);
        save_وٿي = وٿي;
        لكل (i = 0; i < n_seq; i++) {
            p_ڳنڍ = seq[i].ڳنڍ;
            إذا (p_ڳنڍ->n_ٻار == 0) {
                p_trie = &trie[p_ڳنڍ->شروعات];
                seq[i].nest_وٿي = وٿي;
                وٿي += 1 + p_trie->رڪن_سائيز + 1;
            }
        }
        لكل (i = 0; i < n_seq; i++) {
            p_ڳنڍ = seq[i].ڳنڍ;
            p_trie = &trie[p_ڳنڍ->شروعات];
            إذا (seq[i].n_ٻار >= 0) {
                section_ptr_جوڙيو(mo->exports,
				seq[i].وٿي - mo->exports->معلومات_وٿي);
                ptr = section_ptr_جوڙيو(mo->exports, 2);
                *ptr++ = 0;
                *ptr = seq[i].n_ٻار;
            }
            سائيز = p_ڳنڍ->اشاريو_پڇاڙي - p_ڳنڍ->اشاريو_شروعات;
            ptr = section_ptr_جوڙيو(mo->exports, سائيز + 1);
            يادگيري_نقل(ptr, &p_trie->name[p_ڳنڍ->اشاريو_شروعات], سائيز);
            ptr[سائيز] = 0;
            write_uleb128(mo->exports, seq[i].nest_وٿي);
        }
        section_ptr_جوڙيو(mo->exports, save_وٿي - mo->exports->معلومات_وٿي);
        لكل (i = 0; i < n_seq; i++) {
            p_ڳنڍ = seq[i].ڳنڍ;
            إذا (p_ڳنڍ->n_ٻار == 0) {
                p_trie = &trie[p_ڳنڍ->شروعات];
                write_uleb128(mo->exports, p_trie->رڪن_سائيز);
                write_uleb128(mo->exports, p_trie->flag);
                write_uleb128(mo->exports, p_trie->addr);
                ptr = section_ptr_جوڙيو(mo->exports, 1);
                *ptr = 0;
            }
        }
        section_ptr_جوڙيو(mo->exports, -mo->exports->معلومات_وٿي & 7);
	ڳنڍ_free(&ڳنڍ);
        tcc_free(seq);
    }
    tcc_free(trie);
}

ساكن فراغ collect_sections(TCCState *s1, بنية macho *mo, ثابت حرف *filename)
{
    صحيح i, sk, numsec;
    صحيح استعمال_ٿيل_segment[N_SEGMENT];
    uint64_t curaddr, fileofs;
    Section *s;
    بنية segment_command_64 *seg;
    بنية dylib_command *dylib;
#جيڪڏهن_وصف_ٿيل CONFIG_NEW_MACHO
    بنية linkedit_معلومات_command *chained_fixups_lc;
    بنية linkedit_معلومات_command *export_trie_lc;
#جيڪڏهن_پورو
    بنية build_نسخو_command *dyldbv;
    بنية ذريعو_نسخو_command *dyldsv;
    بنية rpath_command *rpath;
    بنية dylinker_command *dyldlc;
    بنية symtab_command *symlc;
    بنية dysymtab_command *dysymlc;
    حرف *str;

    لكل (i = 0; i < N_SEGMENT; i++)
	استعمال_ٿيل_segment[i] = all_segment[i].استعمال_ٿيل;

    memset (mo->sk_منزل_sect, 0, حجم(mo->sk_منزل_sect));
    لكل (i = s1->nb_sections; i-- > 1;) {
        صحيح type, flags;
        s = s1->sections[i];
        type = s->sh_type;
        flags = s->sh_flags;
        sk = sk_unknown;
	/* debug sections have sometimes no SHF_ALLOC */
        إذا ((flags & SHF_ALLOC) || !لڙي_ڀيٽ(s->name, ".debug_", 7)) {
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
#جيڪڏهن_وصف_نه_ٿيل CONFIG_NEW_MACHO
                وإلا إذا (s == mo->stub_helper)
                  sk = sk_stub_helper;
                وإلا إذا (s == mo->la_نشان_ptr)
                  sk = sk_la_ptr;
#جيڪڏهن_پورو
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
                وإلا إذا (s == dwarf_سٽ_section)
                  sk = sk_debug_سٽ;
                وإلا إذا (s == dwarf_aranges_section)
                  sk = sk_debug_aranges;
                وإلا إذا (s == dwarf_str_section)
                  sk = sk_debug_str;
                وإلا إذا (s == dwarf_سٽ_str_section)
                  sk = sk_debug_سٽ_str;
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
	استعمال_ٿيل_segment[skinfo[sk].seg_initial] = 1;
    }

    إذا (s1->output_type != TCC_OUTPUT_EXE)
	استعمال_ٿيل_segment[0] = 0;

    لكل (i = 0; i < N_SEGMENT; i++)
	إذا (استعمال_ٿيل_segment[i]) {
	    seg = جوڙيو_segment(mo, all_segment[i].name);
	    إذا (i == 1 && s1->output_type != TCC_OUTPUT_EXE)
	        seg->vmaddr = 0;
	    وإلا
	        seg->vmaddr = all_segment[i].vmaddr;
	    seg->vmsize = all_segment[i].vmsize;
	    seg->maxprot = all_segment[i].maxprot;
	    seg->initprot = all_segment[i].initprot;
	    seg->flags = all_segment[i].flags;
            لكل (sk = sk_unknown; sk < sk_آخري; sk++)
		إذا (skinfo[sk].seg_initial == i)
	            mo->segment[sk] = mo->nseg - 1;
	}

    إذا (s1->output_type != TCC_OUTPUT_EXE) {
	ثابت حرف *name = s1->install_name ? s1->install_name : filename;
        i = (حجم(*dylib) + لڙي_ڊيگهه(name) + 1 + 7) &-8;
        dylib = جوڙيو_lc(mo, LC_ID_DYLIB, i);
	dylib->name = حجم(*dylib);
	dylib->timestamp = 1;
	dylib->current_نسخو =
	    s1->current_نسخو ? s1->current_نسخو : 1 << 16;
	dylib->compatibility_نسخو =
	    s1->compatibility_نسخو ? s1->compatibility_نسخو : 1 << 16;
        str = (حرف*)dylib + dylib->name;
        strcpy(str, name);
    }

#جيڪڏهن_وصف_ٿيل CONFIG_NEW_MACHO
    chained_fixups_lc = جوڙيو_lc(mo, LC_DYLD_CHAINED_FIXUPS,
			       حجم(بنية linkedit_معلومات_command));
    export_trie_lc = جوڙيو_lc(mo, LC_DYLD_EXPORTS_TRIE,
			    حجم(بنية linkedit_معلومات_command));
#وإلا
    mo->dyldinfo = جوڙيو_lc(mo, LC_DYLD_INFO_ONLY, حجم(*mo->dyldinfo));
#جيڪڏهن_پورو

    symlc = جوڙيو_lc(mo, LC_SYMTAB, حجم(*symlc));
    dysymlc = جوڙيو_lc(mo, LC_DYSYMTAB, حجم(*dysymlc));

    إذا (s1->output_type == TCC_OUTPUT_EXE) {
        i = (حجم(*dyldlc) + لڙي_ڊيگهه("/usr/lib/dyld") + 1 + 7) &-8;
        dyldlc = جوڙيو_lc(mo, LC_ڀريو_DYLINKER, i);
        dyldlc->name = حجم(*dyldlc);
        str = (حرف*)dyldlc + dyldlc->name;
        strcpy(str, "/usr/lib/dyld");
    }

    dyldbv = جوڙيو_lc(mo, LC_BUILD_نسخو, حجم(*dyldbv));
    dyldbv->platform = PLATFORM_MACOS;
    dyldbv->minos = (10 << 16) + (6 << 8);
    dyldbv->sdk = (10 << 16) + (6 << 8);
    dyldbv->ntools = 0;

    dyldsv = جوڙيو_lc(mo, LC_ذريعو_نسخو, حجم(*dyldsv));
    dyldsv->نسخو = 0;

    إذا (s1->output_type == TCC_OUTPUT_EXE) {
        mo->ep = جوڙيو_lc(mo, LC_MAIN, حجم(*mo->ep));
        mo->ep->entryoff = 4096;
    }

    لكل(i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *dllref = s1->loaded_dlls[i];
        إذا (dllref->level == 0)
          جوڙيو_dylib(mo, dllref->name);
    }

    إذا (s1->rpath) {
	حرف *رستو = s1->rpath, *پڇاڙي;
	افعل {
	    پڇاڙي = strchr(رستو, ':');
	    إذا (!پڇاڙي)
		پڇاڙي = strchr(رستو, 0);
            i = (حجم(*rpath) + (پڇاڙي - رستو) + 1 + 7) &-8;
            rpath = جوڙيو_lc(mo, LC_RPATH, i);
            rpath->رستو = حجم(*rpath);
            str = (حرف*)rpath + rpath->رستو;
            يادگيري_نقل(str, رستو, پڇاڙي - رستو);
	    str[پڇاڙي - رستو] = 0;
	    رستو = پڇاڙي + 1;
	} طالما (*پڇاڙي);
    }

    fileofs = 4096;  /* leave space for mach-o headers */
    curaddr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;
    curaddr += 4096;
    seg = عدم;
    numsec = 0;
    mo->elfsectomacho = tcc_mallocz(حجم(*mo->elfsectomacho) * s1->nb_sections);
    لكل (sk = sk_unknown; sk < sk_آخري; sk++) {
        بنية section_64 *sec = عدم;
        إذا (seg) {
            seg->vmsize = curaddr - seg->vmaddr;
            seg->filesize = fileofs - seg->fileoff;
        }
#جيڪڏهن_وصف_ٿيل CONFIG_NEW_MACHO
	إذا (sk == sk_linkedit) {
	    calc_fixup_سائيز(s1, mo);
	    export_trie(s1, mo);
	}
#وإلا
	إذا (sk == sk_linkedit) {
	    bind_rebase(s1, mo);
	    export_trie(s1, mo);
	}
#جيڪڏهن_پورو
        إذا (skinfo[sk].seg_initial &&
	    (s1->output_type != TCC_OUTPUT_EXE || mo->segment[sk]) &&
	    mo->sk_منزل_sect[sk].s) {
            uint64_t al = 0;
            صحيح si;
            seg = get_segment(mo, mo->segment[sk]);
            إذا (skinfo[sk].name) {
                si = جوڙيو_section(mo, &seg, skinfo[sk].name);
                numsec++;
                mo->lc[mo->seg2lc[mo->segment[sk]]] = (بنية ڀريو_command*)seg;
                mo->sk_منزل_sect[sk].machosect = si;
                sec = get_section(seg, si);
                sec->flags = skinfo[sk].flags;
		إذا (sk == sk_stubs)
#جيڪڏهن_وصف_ٿيل TCC_هدف_X86_64
	    	    sec->reserved2 = 6;
#وإلاإذا defined TCC_هدف_ARM64
	    	    sec->reserved2 = 12;
#جيڪڏهن_پورو
		إذا (sk == sk_nl_ptr)
	    	    sec->reserved1 = mo->nr_plt;
#جيڪڏهن_وصف_نه_ٿيل CONFIG_NEW_MACHO
		إذا (sk == sk_la_ptr)
	    	    sec->reserved1 = mo->nr_plt + mo->n_got;
#جيڪڏهن_پورو
            }
            إذا (seg->vmaddr == -1) {
                curaddr = (curaddr + SEG_صفحو_سائيز - 1) & -SEG_صفحو_سائيز;
                seg->vmaddr = curaddr;
                fileofs = (fileofs + SEG_صفحو_سائيز - 1) & -SEG_صفحو_سائيز;
                seg->fileoff = fileofs;
            }

            لكل (s = mo->sk_منزل_sect[sk].s; s; s = s->prev) {
                صحيح a = exact_log2p1(s->sh_addralign);
                إذا (a && al < (a - 1))
                  al = a - 1;
                s->sh_سائيز = s->معلومات_وٿي;
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
                sec->وٿي = fileofs;
            }
            لكل (s = mo->sk_منزل_sect[sk].s; s; s = s->prev) {
                al = s->sh_addralign;
                curaddr = (curaddr + al - 1) & -al;
                dprintf("%s: curaddr now 0x%lx\n", s->name, (ڊگهو)curaddr);
                s->sh_addr = curaddr;
                curaddr += s->sh_سائيز;
                إذا (s->sh_type != SHT_NOBITS) {
                    fileofs = (fileofs + al - 1) & -al;
                    s->sh_وٿي = fileofs;
                    fileofs += s->sh_سائيز;
                    dprintf("%s: fileofs now %ld\n", s->name, (ڊگهو)fileofs);
                }
                إذا (sec)
                  mo->elfsectomacho[s->sh_انگ] = numsec;
            }
            إذا (sec)
              sec->سائيز = curaddr - sec->addr;
        }
        إذا (DEBUG_MACHO)
          لكل (s = mo->sk_منزل_sect[sk].s; s; s = s->prev) {
              صحيح type = s->sh_type;
              صحيح flags = s->sh_flags;
              لکو("%d section %-16s %-10s %09lx %04x %02d %s,%s,%s\n",
                     sk,
                     s->name,
                     type == SHT_PROGBITS ? "progbits" :
                     type == SHT_NOBITS ? "nobits" :
                     type == SHT_SYMTAB ? "symtab" :
                     type == SHT_STRTAB ? "strtab" :
                     type == SHT_INIT_ARRAY ? "init" :
                     type == SHT_FINI_ARRAY ? "fini" :
                     type == SHT_RELX ? "rel" : "???",
                     (ڊگهو)s->sh_addr,
                     (بنانشان)s->معلومات_وٿي,
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
    symlc->symoff = mo->symtab->sh_وٿي;
    symlc->nsyms = mo->symtab->معلومات_وٿي / حجم(بنية nlist_64);
    symlc->stroff = mo->strtab->sh_وٿي;
    symlc->strsize = mo->strtab->معلومات_وٿي;

    dysymlc->iundefsym = mo->iundef == -1 ? symlc->nsyms : mo->iundef;
    dysymlc->iextdefsym = mo->iextdef == -1 ? dysymlc->iundefsym : mo->iextdef;
    dysymlc->ilocalsym = mo->ilocal == -1 ? dysymlc->iextdefsym : mo->ilocal;
    dysymlc->nlocalsym = dysymlc->iextdefsym - dysymlc->ilocalsym;
    dysymlc->nextdefsym = dysymlc->iundefsym - dysymlc->iextdefsym;
    dysymlc->nundefsym = symlc->nsyms - dysymlc->iundefsym;
    dysymlc->indirectsymoff = mo->indirsyms->sh_وٿي;
    dysymlc->nindirectsyms = mo->indirsyms->معلومات_وٿي / حجم(uint32_t);

#جيڪڏهن_وصف_ٿيل CONFIG_NEW_MACHO
    إذا (mo->chained_fixups->معلومات_وٿي) {
        chained_fixups_lc->dataoff = mo->chained_fixups->sh_وٿي;
        chained_fixups_lc->datasize = mo->chained_fixups->معلومات_وٿي;
    }
    إذا (mo->exports->معلومات_وٿي) {
        export_trie_lc->dataoff = mo->exports->sh_وٿي;
        export_trie_lc->datasize = mo->exports->معلومات_وٿي;
    }
#وإلا
    إذا (mo->rebase->معلومات_وٿي) {
        mo->dyldinfo->rebase_off = mo->rebase->sh_وٿي;
        mo->dyldinfo->rebase_سائيز = mo->rebase->معلومات_وٿي;
    }
    إذا (mo->binding->معلومات_وٿي) {
        mo->dyldinfo->bind_off = mo->binding->sh_وٿي;
        mo->dyldinfo->bind_سائيز = mo->binding->معلومات_وٿي;
    }
    إذا (mo->weak_binding->معلومات_وٿي) {
        mo->dyldinfo->weak_bind_off = mo->weak_binding->sh_وٿي;
        mo->dyldinfo->weak_bind_سائيز = mo->weak_binding->معلومات_وٿي;
    }
    إذا (mo->lazy_binding->معلومات_وٿي) {
        mo->dyldinfo->lazy_bind_off = mo->lazy_binding->sh_وٿي;
        mo->dyldinfo->lazy_bind_سائيز = mo->lazy_binding->معلومات_وٿي;
    }
    إذا (mo->exports->معلومات_وٿي) {
        mo->dyldinfo->export_off = mo->exports->sh_وٿي;
        mo->dyldinfo->export_سائيز = mo->exports->معلومات_وٿي;
    }
#جيڪڏهن_پورو
}

ساكن فراغ macho_write(TCCState *s1, بنية macho *mo, FILE *fp)
{
    صحيح i, sk;
    uint64_t fileofs = 0;
    Section *s;
    mo->mh.mh.magic = MH_MAGIC_64;
#جيڪڏهن_وصف_ٿيل TCC_هدف_X86_64
    mo->mh.mh.cputype = CPU_TYPE_X86_64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_LIB64 | CPU_SUBTYPE_X86_ALL;
#وإلاإذا defined TCC_هدف_ARM64
    mo->mh.mh.cputype = CPU_TYPE_ARM64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_ARM64_ALL;
#جيڪڏهن_پورو
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

    لكل (sk = sk_unknown; sk < sk_آخري; sk++) {
        //struct segment_command_64 *seg;
        إذا (skinfo[sk].seg_initial == 0 ||
	    (s1->output_type == TCC_OUTPUT_EXE && !mo->segment[sk]) ||
	    !mo->sk_منزل_sect[sk].s)
          استمر;
        /*seg =*/ get_segment(mo, mo->segment[sk]);
        لكل (s = mo->sk_منزل_sect[sk].s; s; s = s->prev) {
            إذا (s->sh_type != SHT_NOBITS) {
                طالما (fileofs < s->sh_وٿي)
                  fputc(0, fp), fileofs++;
                إذا (s->sh_سائيز) {
                    fwrite(s->معلومات, 1, s->sh_سائيز, fp);
                    fileofs += s->sh_سائيز;
                }
            }
        }
    }
}

#جيڪڏهن_وصف_ٿيل CONFIG_NEW_MACHO
ساكن صحيح bind_rebase_cmp(ثابت فراغ *_a, ثابت فراغ *_b, فراغ *arg)
{
    TCCState *s1 = arg;
    بنية bind_rebase *a = (بنية bind_rebase *) _a;
    بنية bind_rebase *b = (بنية bind_rebase *) _b;
    addr_t aa = s1->sections[a->section]->sh_addr + a->rel.r_وٿي;
    addr_t ab = s1->sections[b->section]->sh_addr + b->rel.r_وٿي;

    أرجع aa > ab ? 1 : aa < ab ? -1 : 0;
}

ST_FUNC فراغ bind_rebase_import(TCCState *s1, بنية macho *mo)
{
    صحيح i, j, k, bind_اشاريو, سائيز, صفحو_ڳڻپ, sym_اشاريو;
    ثابت حرف *name;
    ElfW(Sym) *sym;
    بنانشان حرف *معلومات = mo->chained_fixups->معلومات;
    بنية segment_command_64 *seg;
    بنية dyld_chained_fixups_سرو *سرو;
    بنية dyld_chained_starts_اندريون_image *image;
    بنية dyld_chained_starts_اندريون_segment *segment;
    بنية dyld_chained_import *import;

    tcc_qsort(mo->bind_rebase, mo->n_bind_rebase, حجم(بنية bind_rebase),
	      bind_rebase_cmp, s1);
    لكل (i = 0; i < mo->n_bind_rebase - 1; i++)
	إذا (mo->bind_rebase[i].section == mo->bind_rebase[i + 1].section &&
	    mo->bind_rebase[i].rel.r_وٿي == mo->bind_rebase[i + 1].rel.r_وٿي) {
	    sym_اشاريو = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
            sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_اشاريو];
	    name = (حرف *) symtab_section->link->معلومات + sym->st_name;
	    tcc_error("Overlap %s/%s %s:%s",
		      mo->bind_rebase[i].bind ? "bind" : "rebase",
		      mo->bind_rebase[i + 1].bind ? "bind" : "rebase",
		      s1->sections[mo->bind_rebase[i].section]->name, name);
	}
    سرو = (بنية dyld_chained_fixups_سرو *) معلومات;
    معلومات += (حجم(بنية dyld_chained_fixups_سرو) + 7) & -8;
    سرو->starts_وٿي = معلومات - mo->chained_fixups->معلومات;
    سرو->imports_ڳڻپ = mo->n_bind;
    سرو->imports_format = DYLD_CHAINED_IMPORT;
    سرو->symbols_format = 0;
    سائيز = حجم(بنية dyld_chained_starts_اندريون_image) +
	   (mo->nseg - 1) * حجم(uint32_t);
    image = (بنية dyld_chained_starts_اندريون_image *) معلومات;
    معلومات += (سائيز + 7) & -8;
    image->seg_ڳڻپ = mo->nseg;
    لكل (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
        image->seg_info_وٿي[i] = (معلومات - mo->chained_fixups->معلومات) -
				    سرو->starts_وٿي;
	seg = get_segment(mo, i);
	صفحو_ڳڻپ = (seg->vmsize + SEG_صفحو_سائيز - 1) / SEG_صفحو_سائيز;
	سائيز = حجم(بنية dyld_chained_starts_اندريون_segment) +
		      (صفحو_ڳڻپ - 1) * حجم(uint16_t);
        segment = (بنية dyld_chained_starts_اندريون_segment *) معلومات;
        معلومات += (سائيز + 7) & -8;
        segment->سائيز = سائيز;
        segment->صفحو_سائيز = SEG_صفحو_سائيز;
#إذا 1
#وصف_ڪريو	PTR_64_وٿي 0
#وصف_ڪريو	PTR_64_نقاب   0x7FFFFFFFFFFULL
        segment->اشارو_format = DYLD_CHAINED_PTR_64;
#وإلا
#وصف_ڪريو	PTR_64_وٿي 0x100000000ULL
#وصف_ڪريو	PTR_64_نقاب   0xFFFFFFFFFFFFFFULL
        segment->اشارو_format = DYLD_CHAINED_PTR_64_وٿي;
#جيڪڏهن_پورو
        segment->segment_وٿي = seg->fileoff;
        segment->max_valid_اشارو = 0;
        segment->صفحو_ڳڻپ = صفحو_ڳڻپ;
	// add bind/rebase
	bind_اشاريو = 0;
	k = 0;
	لكل (j = 0; j < صفحو_ڳڻپ; j++) {
	    addr_t شروعات = seg->vmaddr + j * SEG_صفحو_سائيز;
	    addr_t پڇاڙي = شروعات + SEG_صفحو_سائيز;
	    فراغ *آخري = عدم;
	    addr_t آخري_o = 0;
	    addr_t cur_o, cur;
	    بنية dyld_chained_ptr_64_rebase *rebase;
	    بنية dyld_chained_ptr_64_bind *bind;

	    segment->صفحو_شروعات[j] = DYLD_CHAINED_PTR_شروعات_NONE;
	    لكل (; k < mo->n_bind_rebase; k++) {
	        Section *s = s1->sections[mo->bind_rebase[k].section];
		addr_t r_وٿي = mo->bind_rebase[k].rel.r_وٿي;
		addr_t addr = s->sh_addr + r_وٿي;

		إذا ((addr & 3) ||
		    (addr & (SEG_صفحو_سائيز - 1)) > SEG_صفحو_سائيز - PTR_سائيز)
		    tcc_error("Illegal rel_offset %s %lld",
			      s->name, (ڊگهو ڊگهو)r_وٿي);
		إذا (addr >= پڇاڙي)
		    اكسر;
		إذا (addr >= شروعات) {
		    cur_o = addr - شروعات;
	            إذا (mo->bind_rebase[k].bind) {
		        إذا (segment->صفحو_شروعات[j] == DYLD_CHAINED_PTR_شروعات_NONE)
			    segment->صفحو_شروعات[j] = cur_o;
		        وإلا {
			    bind = (بنية dyld_chained_ptr_64_bind *) آخري;
			    bind->ايندڙ = (cur_o - آخري_o) / 4;
		        }
		        bind = (بنية dyld_chained_ptr_64_bind *)
				    (s->معلومات + r_وٿي);
		        آخري = bind;
		        آخري_o = cur_o;
		        bind->ordinal = bind_اشاريو;
		        bind->addend = 0;
		        bind->reserved = 0;
		        bind->ايندڙ = 0;
		        bind->bind = 1;
		    }
		    وإلا {
		        إذا (segment->صفحو_شروعات[j] == DYLD_CHAINED_PTR_شروعات_NONE)
			    segment->صفحو_شروعات[j] = cur_o;
		        وإلا {
			    rebase = (بنية dyld_chained_ptr_64_rebase *) آخري;
			    rebase->ايندڙ = (cur_o - آخري_o) / 4;
		        }
		        rebase = (بنية dyld_chained_ptr_64_rebase *)
				    (s->معلومات + r_وٿي);
		        آخري = rebase;
		        آخري_o = cur_o;
		        cur = (*(uint64_t *) (s->معلومات + r_وٿي)) -
			      PTR_64_وٿي;
		        rebase->هدف = cur & PTR_64_نقاب;
		        rebase->high8 = cur >> (64 - 8);
			إذا (cur != ((uint64_t)rebase->high8 << (64 - 8)) + rebase->هدف)
			    tcc_error("rebase error");
		        rebase->reserved = 0;
		        rebase->ايندڙ = 0;
		        rebase->bind = 0;
		    }
		}
		bind_اشاريو += mo->bind_rebase[k].bind;
	    }
	}
    }
    // add imports
    سرو->imports_وٿي = معلومات - mo->chained_fixups->معلومات;
    import = (بنية dyld_chained_import *) معلومات;
    معلومات += mo->n_bind * حجم (بنية dyld_chained_import);
    سرو->symbols_وٿي = معلومات - mo->chained_fixups->معلومات;
    معلومات++;
    لكل (i = 0, bind_اشاريو = 0; i < mo->n_bind_rebase; i++) {
	إذا (mo->bind_rebase[i].bind) {
	    import[bind_اشاريو].lib_ordinal =
		BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xffu;
	    import[bind_اشاريو].name_وٿي =
		(معلومات - mo->chained_fixups->معلومات) - سرو->symbols_وٿي;
	    sym_اشاريو = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    sym = &((ElfW(Sym) *)symtab_section->معلومات)[sym_اشاريو];
	    import[bind_اشاريو].weak_import =
		ELFW(ST_BIND)(sym->st_info) == STB_WEAK;
	    name = (حرف *) symtab_section->link->معلومات + sym->st_name;
            strcpy((حرف *) معلومات, name);
	    معلومات += لڙي_ڊيگهه(name) + 1;
	    bind_اشاريو++;
	}
    }
    tcc_free(mo->bind_rebase);
}
#جيڪڏهن_پورو

ST_FUNC صحيح macho_output_file(TCCState *s1, ثابت حرف *filename)
{
    صحيح fd, گهڻائي, file_type;
    FILE *fp;
    صحيح i, ret = -1;
    بنية macho mo;

    (فراغ)memset(&mo, 0, حجم(mo));

    file_type = s1->output_type;
    إذا (file_type == TCC_OUTPUT_OBJ)
        گهڻائي = 0666;
    وإلا
        گهڻائي = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_ٻٽو_2, گهڻائي);
    إذا (fd < 0 || (fp = fdopen(fd, "wb")) == عدم) {
        tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
        أرجع -1;
    }
    tcc_جوڙيو_runtime(s1);
    tcc_macho_جوڙيو_destructor(s1);
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
#جيڪڏهن_وصف_ٿيل CONFIG_NEW_MACHO
	bind_rebase_import(s1, &mo);
#جيڪڏهن_پورو
        convert_symbols(s1, &mo);
        إذا (s1->verbose)
            لکو("<- %s\n", filename);
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
#جيڪڏهن_وصف_ٿيل CONFIG_CODESIGN
    إذا (!ret) {
	حرف command[1024];
	صحيح retval;

	snprintf(command, حجم(command), "codesign -f -s - %s", filename);
	retval = system (command);
	إذا (retval == -1 || !(WIFEXITED(retval) && WEXITSTATUS(retval) == 0))
	    tcc_error ("command failed '%s'", command);
    }
#جيڪڏهن_پورو
    أرجع ret;
}

ساكن uint32_t macho_swap32(uint32_t x)
{
  أرجع (x >> 24) | (x << 24) | ((x >> 8) & 0xff00) | ((x & 0xff00) << 8);
}
#وصف_ڪريو مٽا_سٽا(x) (مٽا_سٽا_2 ? macho_swap32(x) : (x))
#وصف_ڪريو tbd_parse_movepast(s) \
    (pos = (pos = لڙي_ڳولا(pos, s)) ? pos + لڙي_ڊيگهه(s) : عدم)
#وصف_ڪريو tbd_parse_movetoany(cs) (pos = strpbrk(pos, cs))
#وصف_ڪريو tbd_parse_skipws طالما (*pos && (*pos==' '||*pos=='\n')) ++pos
#وصف_ڪريو tbd_parse_tramplequote إذا(*pos=='\''||*pos=='"') tbd_parse_trample
#وصف_ڪريو tbd_parse_tramplespace إذا(*pos==' ') tbd_parse_trample
#وصف_ڪريو tbd_parse_trample *pos++=0

#جيڪڏهن_وصف_ٿيل TCC_IS_NATIVE
/* Looks for the active developer SDK set by xcode-select (or the default
   one set during installation.) */
ST_FUNC فراغ tcc_جوڙيو_macos_sdkpath(TCCState* s)
{
    حرف *sdkroot = عدم, *pos = عدم;
    فراغ* xcs = dlopen("libxcselect.dylib", RTLD_GLOBAL | RTLD_LAZY);
    CString رستو;
    صحيح (*f)(بنانشان صحيح, حرف**) = dlsym(xcs, "xcselect_host_sdk_path");
    cstr_new(&رستو);
    إذا (f) f(1, &sdkroot);
    إذا (sdkroot)
        pos = لڙي_ڳولا(sdkroot,"SDKs/MacOSX");
    إذا (pos)
        cstr_printf(&رستو, "%.*s.sdk/usr/lib", (صحيح)(pos - sdkroot + 11), sdkroot);
    /* must use free from libc directly */
#هدايت ڌڪو_macro("free")
#وصف_رد حرر
    حرر(sdkroot);
#هدايت ڪڍو_macro("free")
    إذا (رستو.سائيز)
        tcc_جوڙيو_library_رستو(s, (حرف*)رستو.معلومات);
    وإلا
        tcc_جوڙيو_library_رستو(s,
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib"
            ":" "/Applications/Xcode.app/Developer/SDKs/MacOSX.sdk/usr/lib"
            );
    cstr_free(&رستو);
}

ST_FUNC حرف* macho_tbd_soname(صحيح fd) {
    حرف *soname, *معلومات, *pos;
    حرف *ret = 0;
    pos = معلومات = tcc_ڀريو_متن(fd);
    إذا (!tbd_parse_movepast("install-name: ")) اذهب the_پڇاڙي;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    إذا (!tbd_parse_movetoany("\n \"'")) اذهب the_پڇاڙي;
    tbd_parse_trample;
    ret = tcc_strdup(soname);
the_پڇاڙي:
    tcc_free(معلومات);
    أرجع ret;
}
#جيڪڏهن_پورو /* TCC_IS_NATIVE */

ST_FUNC صحيح macho_ڀريو_tbd(TCCState* s1, صحيح fd, ثابت حرف* filename, صحيح lev)
{
    حرف *soname, *معلومات, *pos;
    صحيح ret = -1;

    pos = معلومات = tcc_ڀريو_متن(fd);
    إذا (!tbd_parse_movepast("install-name: ")) اذهب the_پڇاڙي;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    إذا (!tbd_parse_movetoany("\n \"'")) اذهب the_پڇاڙي;
    tbd_parse_trample;
    ret = 0;
    إذا (tcc_جوڙيو_dllref(s1, soname, lev)->مليو)
        اذهب the_پڇاڙي;
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
            سيٽ_elf_sym(s1->dynsymtab_section, 0, 0,
                ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0, SHN_UNDEF, sym);
        }
    }

the_پڇاڙي:
    tcc_free(معلومات);
    أرجع ret;
}

ST_FUNC صحيح macho_ڀريو_dll(TCCState * s1, صحيح fd, ثابت حرف* filename, صحيح lev)
{
    بنانشان حرف buf[حجم(بنية mach_سرو_64)];
    فراغ *buf2;
    uint32_t machofs = 0;
    بنية fat_سرو fh;
    بنية mach_سرو mh;
    بنية ڀريو_command *lc;
    صحيح i, مٽا_سٽا_2 = 0;
    ثابت حرف *soname = filename;
    بنية nlist_64 *symtab = 0;
    uint32_t nsyms = 0;
    حرف *strtab = 0;
    uint32_t strsize = 0;
    uint32_t iextdef = 0;
    uint32_t nextdef = 0;

  again:
    إذا (ڀريل_read(fd, buf, حجم(buf)) != حجم(buf))
      أرجع -1;
    يادگيري_نقل(&fh, buf, حجم(fh));
    إذا (fh.magic == FAT_MAGIC || fh.magic == FAT_CIGAM) {
        بنية fat_arch *fa = ڀريو_معلومات(fd, حجم(fh),
                                        fh.nfat_arch * حجم(*fa));
        مٽا_سٽا_2 = fh.magic == FAT_CIGAM;
        لكل (i = 0; i < مٽا_سٽا(fh.nfat_arch); i++)
#جيڪڏهن_وصف_ٿيل TCC_هدف_X86_64
          إذا (مٽا_سٽا(fa[i].cputype) == CPU_TYPE_X86_64
              && مٽا_سٽا(fa[i].cpusubtype) == CPU_SUBTYPE_X86_ALL)
#وإلاإذا defined TCC_هدف_ARM64
          إذا (مٽا_سٽا(fa[i].cputype) == CPU_TYPE_ARM64
              && مٽا_سٽا(fa[i].cpusubtype) == CPU_SUBTYPE_ARM64_ALL)
#جيڪڏهن_پورو
            اكسر;
        إذا (i == مٽا_سٽا(fh.nfat_arch)) {
            tcc_free(fa);
            أرجع -1;
        }
        machofs = مٽا_سٽا(fa[i].وٿي);
        tcc_free(fa);
        lseek(fd, machofs, SEEK_SET);
        اذهب again;
    } وإلا إذا (fh.magic == FAT_MAGIC_64 || fh.magic == FAT_CIGAM_64) {
        tcc_warning("%s: Mach-O fat 64bit files of type 0x%x not handled",
                    filename, fh.magic);
        أرجع -1;
    }

    يادگيري_نقل(&mh, buf, حجم(mh));
    إذا (mh.magic != MH_MAGIC_64)
      أرجع -1;
    dprintf("found Mach-O at %d\n", machofs);
    buf2 = ڀريو_معلومات(fd, machofs + حجم(بنية mach_سرو_64), mh.sizeofcmds);
    لكل (i = 0, lc = buf2; i < mh.ncmds; i++) {
        dprintf("lc %2d: 0x%08x\n", i, lc->cmd);
        بدل (lc->cmd) {
        حالة LC_SYMTAB:
        {
            بنية symtab_command *sc = (بنية symtab_command*)lc;
            nsyms = sc->nsyms;
            symtab = ڀريو_معلومات(fd, machofs + sc->symoff, nsyms * حجم(*symtab));
            strsize = sc->strsize;
            strtab = ڀريو_معلومات(fd, machofs + sc->stroff, strsize);
            اكسر;
        }
        حالة LC_ID_DYLIB:
        {
            بنية dylib_command *dc = (بنية dylib_command*)lc;
            soname = (حرف*)lc + dc->name;
            dprintf(" ID_DYLIB %d 0x%x 0x%x %s\n",
                    dc->timestamp, dc->current_نسخو,
                    dc->compatibility_نسخو, soname);
            اكسر;
        }
        حالة LC_REEXPORT_DYLIB:
        {
            بنية dylib_command *dc = (بنية dylib_command*)lc;
            حرف *name = (حرف*)lc + dc->name;
            صحيح subfd = open(name, O_RDONLY | O_ٻٽو_2);
            dprintf(" REEXPORT %s\n", name);
            إذا (subfd < 0)
              tcc_warning("can't open %s (reexported from %s)", name, filename);
            وإلا {
                /* Hopefully the REEXPORTs never form a cycle, we don't check
                   for that!  */
                macho_ڀريو_dll(s1, subfd, name, lev + 1);
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
        lc = (بنية ڀريو_command*) ((حرف*)lc + lc->cmdsize);
    }

    إذا (tcc_جوڙيو_dllref(s1, soname, lev)->مليو)
        اذهب the_پڇاڙي;

    إذا (!nsyms || !nextdef)
      tcc_warning("%s doesn't export any symbols?", filename);

    //dprintf("symbols (all):\n");
    dprintf("symbols (exported):\n");
    dprintf("    n: typ sec   desc              value name\n");
    //for (i = 0; i < nsyms; i++) {
    لكل (i = iextdef; i < iextdef + nextdef; i++) {
        بنية nlist_64 *sym = symtab + i;
        dprintf("%5d: %3d %3d 0x%04x 0x%016lx %s\n",
                i, sym->n_type, sym->n_sect, sym->n_desc, (ڊگهو)sym->n_قدر,
                strtab + sym->n_strx);
        سيٽ_elf_sym(s1->dynsymtab_section, 0, 0,
                    ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
                    0, SHN_UNDEF, strtab + sym->n_strx);
    }

  the_پڇاڙي:
    tcc_free(strtab);
    tcc_free(symtab);
    tcc_free(buf2);
    أرجع 0;
}
