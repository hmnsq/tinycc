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
#شامل "tcc.h"

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

#اگر !defined TCC_ہدف_X86_64 && !defined TCC_ہدف_ARM64
#غلطی Platform not supported
#اگر_ختم

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#تعریف_منسوخ _tcc_error

#تعریف_کرو DEBUG_MACHO 0
#تعریف_کرو dprintf اگر (DEBUG_MACHO) لکھو

#تعریف_کرو MH_EXECUTE              (0x2)
#تعریف_کرو MH_DYLDLINK             (0x4)
#تعریف_کرو MH_DYLIB                (0x6)
#تعریف_کرو MH_PIE                  (0x200000)

#تعریف_کرو CPU_SUBTYPE_LIB64       (0x80000000)
#تعریف_کرو CPU_SUBTYPE_X86_ALL     (3)
#تعریف_کرو CPU_SUBTYPE_ARM64_ALL   (0)

#تعریف_کرو CPU_ARCH_ABI64          (0x01000000)

#تعریف_کرو CPU_TYPE_X86            (7)
#تعریف_کرو CPU_TYPE_X86_64         (CPU_TYPE_X86 | CPU_ARCH_ABI64)
#تعریف_کرو CPU_TYPE_ARM            (12)
#تعریف_کرو CPU_TYPE_ARM64          (CPU_TYPE_ARM | CPU_ARCH_ABI64)

ساخت fat_سرخی {
    uint32_t        magic;          /* FAT_MAGIC or FAT_MAGIC_64 */
    uint32_t        nfat_arch;      /* number of structs that follow */
};

ساخت fat_arch {
    صحیح             cputype;        /* cpu specifier (int) */
    صحیح             cpusubtype;     /* machine specifier (int) */
    uint32_t        انحراف;         /* file offset to this object file */
    uint32_t        سائز;           /* size of this object file */
    uint32_t        align;          /* alignment as a power of 2 */
};

#تعریف_کرو FAT_MAGIC       0xcafebabe
#تعریف_کرو FAT_CIGAM       0xbebafeca
#تعریف_کرو FAT_MAGIC_64    0xcafebabf
#تعریف_کرو FAT_CIGAM_64    0xbfbafeca

ساخت mach_سرخی {
    uint32_t        magic;          /* mach magic number identifier */
    صحیح             cputype;        /* cpu specifier */
    صحیح             cpusubtype;     /* machine specifier */
    uint32_t        filetype;       /* type of file */
    uint32_t        ncmds;          /* number of load commands */
    uint32_t        sizeofcmds;     /* the size of all the load commands */
    uint32_t        flags;          /* flags */
};

ساخت mach_سرخی_64 {
    ساخت mach_سرخی  mh;
    uint32_t            reserved;       /* reserved, pad to 64bit */
};

/* Constant for the magic field of the mach_header (32-bit architectures) */
#تعریف_کرو MH_MAGIC        0xfeedface      /* the mach magic number */
#تعریف_کرو MH_CIGAM        0xcefaedfe      /* NXSwapInt(MH_MAGIC) */
#تعریف_کرو MH_MAGIC_64     0xfeedfacf      /* the 64-bit mach magic number */
#تعریف_کرو MH_CIGAM_64     0xcffaedfe      /* NXSwapInt(MH_MAGIC_64) */

ساخت بھرو_command {
    uint32_t        cmd;            /* type of load command */
    uint32_t        cmdsize;        /* total size of command in bytes */
};

#تعریف_کرو LC_REQ_DYLD 0x80000000
#تعریف_کرو LC_SYMTAB        0x2
#تعریف_کرو LC_DYSYMTAB      0xb
#تعریف_کرو LC_بھرو_DYLIB    0xc
#تعریف_کرو LC_ID_DYLIB      0xd
#تعریف_کرو LC_بھرو_DYLINKER 0xe
#تعریف_کرو LC_SEGMENT_64    0x19
#تعریف_کرو LC_RPATH (0x1c | LC_REQ_DYLD)
#تعریف_کرو LC_REEXPORT_DYLIB (0x1f | LC_REQ_DYLD)
#تعریف_کرو LC_DYLD_INFO_ONLY (0x22|LC_REQ_DYLD)
#تعریف_کرو LC_MAIN (0x28|LC_REQ_DYLD)
#تعریف_کرو LC_ماخذ_نسخہ 0x2A
#تعریف_کرو LC_BUILD_نسخہ 0x32
#تعریف_کرو LC_DYLD_EXPORTS_TRIE (0x33 | LC_REQ_DYLD)
#تعریف_کرو LC_DYLD_CHAINED_FIXUPS (0x34 | LC_REQ_DYLD)

#تعریف_کرو SG_READ_ONLY    0x10 /* This segment is made read-only after fixups */

قسمتعریف صحیح vm_prot_t;

ساخت segment_command_64 { /* for 64-bit architectures */
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

ساخت section_64 { /* for 64-bit architectures */
    حرف            sectname[16];   /* name of this section */
    حرف            segname[16];    /* segment this section goes in */
    uint64_t        addr;           /* memory address of this section */
    uint64_t        سائز;           /* size in bytes of this section */
    uint32_t        انحراف;         /* file offset of this section */
    uint32_t        align;          /* section alignment (power of 2) */
    uint32_t        reloff;         /* file offset of relocation entries */
    uint32_t        nreloc;         /* number of relocation entries */
    uint32_t        flags;          /* flags (section type and attributes)*/
    uint32_t        reserved1;      /* reserved (for offset or index) */
    uint32_t        reserved2;      /* reserved (for count or sizeof) */
    uint32_t        reserved3;      /* reserved */
};

شمار {
    DYLD_CHAINED_IMPORT          = 1,
};

ساخت dyld_chained_fixups_سرخی {
    uint32_t    fixups_نسخہ; ///< 0
    uint32_t    starts_انحراف;  ///< Offset of dyld_chained_starts_in_image.
    uint32_t    imports_انحراف; ///< Offset of imports table in chain_data.
    uint32_t    symbols_انحراف; ///< Offset of symbol strings in chain_data.
    uint32_t    imports_گنتی;  ///< Number of imported symbol names.
    uint32_t    imports_format; ///< DYLD_CHAINED_IMPORT*
    uint32_t    symbols_format; ///< 0 => uncompressed, 1 => zlib compressed
};

ساخت dyld_chained_starts_اندر_image
{
    uint32_t    seg_گنتی;
    uint32_t    seg_info_انحراف[1];  // each entry is offset into this struct for that segment
    // followed by pool of dyld_chain_starts_in_segment data
};

شمار {
    DYLD_CHAINED_PTR_64                     =  2,    // target is vmaddr
    DYLD_CHAINED_PTR_64_انحراف              =  6,    // target is vm offset
};

شمار {
    DYLD_CHAINED_PTR_آغاز_NONE   = 0xFFFF, // used in page_start[] to denote a page with no fixups
};

#تعریف_کرو SEG_صفحہ_سائز 16384

ساخت dyld_chained_starts_اندر_segment
{
    uint32_t    سائز;               // size of this (amount kernel needs to copy)
    uint16_t    صفحہ_سائز;          // 0x1000 or 0x4000
    uint16_t    اشارہ_گر_format;     // DYLD_CHAINED_PTR_*
    uint64_t    segment_انحراف;     // offset in memory to start of segment
    uint32_t    max_valid_اشارہ_گر;  // for 32-bit OS, any value beyond this is not a pointer
    uint16_t    صفحہ_گنتی;         // how many pages are in array
    uint16_t    صفحہ_آغاز[1];      // each entry is offset in each page of first element in chain
                                    // or DYLD_CHAINED_PTR_START_NONE if no fixups on page
};

شمار BindSpecialDylib {
  BIND_SPECIAL_DYLIB_FLAT_LOOKUP = -2,
};

ساخت dyld_chained_import
{
    uint32_t    lib_ordinal :  8,
                weak_import :  1,
                name_انحراف : 23;
};

ساخت dyld_chained_ptr_64_rebase
{
    uint64_t    ہدف    : 36,    // vmaddr, 64GB max image size
                high8     :  8,    // top 8 bits set to this after slide added
                reserved  :  7,    // all zeros
                اگلا      : 12,    // 4-byte stride
                bind      :  1;    // == 0
};

ساخت dyld_chained_ptr_64_bind
{
    uint64_t    ordinal   : 24,
                addend    :  8,   // 0 thru 255
                reserved  : 19,   // all zeros
                اگلا      : 12,   // 4-byte stride
                bind      :  1;   // == 1
};

#تعریف_کرو S_REGULAR                       0x0
#تعریف_کرو S_ZEROFILL                      0x1
#تعریف_کرو S_NON_LAZY_علامت_اشارے      0x6
#تعریف_کرو S_LAZY_علامت_اشارے          0x7
#تعریف_کرو S_علامت_STUBS                  0x8
#تعریف_کرو S_MOD_INIT_FUNC_اشارے        0x9
#تعریف_کرو S_MOD_رکن_FUNC_اشارے        0xa

#تعریف_کرو S_ATTR_خالص_INSTRUCTIONS        0x80000000
#تعریف_کرو S_ATTR_SOME_INSTRUCTIONS        0x00000400
#تعریف_کرو S_ATTR_DEBUG             	0x02000000


قسمتعریف uint32_t lc_str;

ساخت dylib_command {
    uint32_t cmd;                   /* LC_ID_DYLIB, LC_LOAD_{,WEAK_}DYLIB,
                                       LC_REEXPORT_DYLIB */
    uint32_t cmdsize;               /* includes pathname string */
    lc_str   name;                  /* library's path name */
    uint32_t timestamp;             /* library's build time stamp */
    uint32_t current_نسخہ;       /* library's current version number */
    uint32_t compatibility_نسخہ; /* library's compatibility vers number*/
};

ساخت rpath_command {
    uint32_t     cmd;           /* LC_RPATH */
    uint32_t     cmdsize;       /* includes string */
    lc_str       راستہ;          /* path to add to run path */
};

ساخت dylinker_command {
    uint32_t        cmd;            /* LC_ID_DYLINKER, LC_LOAD_DYLINKER or
                                       LC_DYLD_ENVIRONMENT */
    uint32_t        cmdsize;        /* includes pathname string */
    lc_str          name;           /* dynamic linker's path name */
};

ساخت linkedit_ڈیٹا_command {
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

#تعریف_کرو PLATFORM_MACOS 1

ساخت build_نسخہ_command {
    uint32_t    cmd;            /* LC_BUILD_VERSION */
    uint32_t    cmdsize;        /* sizeof(struct build_version_command) plus */
                                /* ntools * sizeof(struct build_tool_version) */
    uint32_t    platform;       /* platform */
    uint32_t    minos;          /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    sdk;            /* X.Y.Z is encoded in nibbles xxxx.yy.zz */
    uint32_t    ntools;         /* number of tool entries following this */
};

ساخت ماخذ_نسخہ_command {
    uint32_t  cmd;      /* LC_SOURCE_VERSION */
    uint32_t  cmdsize;  /* 16 */
    uint64_t  نسخہ;  /* A.B.C.D.E packed as a24.b10.c10.d10.e10 */
};

ساخت symtab_command {
    uint32_t        cmd;            /* LC_SYMTAB */
    uint32_t        cmdsize;        /* sizeof(struct symtab_command) */
    uint32_t        symoff;         /* symbol table offset */
    uint32_t        nsyms;          /* number of symbol table entries */
    uint32_t        stroff;         /* string table offset */
    uint32_t        strsize;        /* string table size in bytes */
};

ساخت dysymtab_command {
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

#تعریف_کرو BIND_OPCODE_مکمل                                        0x00
#تعریف_کرو BIND_OPCODE_سیٹ_DYLIB_SPECIAL_IMM                       0x30
#تعریف_کرو BIND_OPCODE_سیٹ_علامت_TRAILING_FLAGS_IMM               0x40
#تعریف_کرو BIND_OPCODE_سیٹ_TYPE_IMM                                0x50
#تعریف_کرو BIND_OPCODE_سیٹ_SEGMENT_AND_انحراف_ULEB                 0x70
#تعریف_کرو BIND_OPCODE_DO_BIND                                     0x90

#تعریف_کرو BIND_علامت_FLAGS_WEAK_IMPORT                           0x1

#تعریف_کرو BIND_TYPE_اشارہ_گر                                       1
#تعریف_کرو BIND_SPECIAL_DYLIB_FLAT_LOOKUP                          -2

#تعریف_کرو REBASE_OPCODE_مکمل                                      0x00
#تعریف_کرو REBASE_OPCODE_سیٹ_TYPE_IMM                              0x10
#تعریف_کرو REBASE_OPCODE_سیٹ_SEGMENT_AND_انحراف_ULEB               0x20
#تعریف_کرو REBASE_OPCODE_DO_REBASE_IMM_TIMES                       0x50

#تعریف_کرو REBASE_TYPE_اشارہ_گر                                     1

#تعریف_کرو EXPORT_علامت_FLAGS_قسم_REGULAR                        0x00
#تعریف_کرو EXPORT_علامت_FLAGS_قسم_ABSOLUTE                       0x02
#تعریف_کرو EXPORT_علامت_FLAGS_WEAK_DEFINITION                     0x04

ساخت dyld_info_command {
    uint32_t cmd;             /* LC_DYLD_INFO or LC_DYLD_INFO_ONLY */
    uint32_t cmdsize;         /* sizeof(struct dyld_info_command) */
    uint32_t rebase_off;      /* file offset to rebase info  */
    uint32_t rebase_سائز;     /* size of rebase info   */
    uint32_t bind_off;        /* file offset to binding info   */
    uint32_t bind_سائز;       /* size of binding info  */
    uint32_t weak_bind_off;   /* file offset to weak binding info   */
    uint32_t weak_bind_سائز;  /* size of weak binding info  */
    uint32_t lazy_bind_off;   /* file offset to lazy binding info */
    uint32_t lazy_bind_سائز;  /* size of lazy binding infs */
    uint32_t export_off;      /* file offset to lazy binding info */
    uint32_t export_سائز;     /* size of lazy binding infs */
};

#تعریف_کرو بالواسطہ_علامت_LOCAL   0x80000000

ساخت اندراج_نقطہ_command {
    uint32_t  cmd;      /* LC_MAIN only used in MH_EXECUTE filetypes */
    uint32_t  cmdsize;  /* 24 */
    uint64_t  entryoff; /* file (__TEXT) offset of main() */
    uint64_t  stacksize;/* if not zero, initial stack size */
};

شمار skind {
    sk_unknown = 0,
    sk_discard,
    sk_متن,
    sk_stubs,
    sk_stub_helper,
    sk_ro_ڈیٹا,
    sk_uw_info,
    sk_nl_ptr,  // non-lazy pointers, aka GOT
    sk_debug_info,
    sk_debug_abbrev,
    sk_debug_سطر,
    sk_debug_aranges,
    sk_debug_str,
    sk_debug_سطر_str,
    sk_stab,
    sk_stab_str,
    sk_la_ptr,  // lazy pointers
    sk_init,
    sk_fini,
    sk_rw_ڈیٹا,
    sk_bss,
    sk_linkedit,
    sk_آخری
};

ساخت nlist_64 {
    uint32_t  n_strx;      /* index into the string table */
    uint8_t n_type;        /* type flag, see below */
    uint8_t n_sect;        /* section number or NO_SECT */
    uint16_t n_desc;       /* see <mach-o/stab.h> */
    uint64_t n_قدر;      /* value of this symbol (or stab offset) */
};

#تعریف_کرو N_UNDF  0x0
#تعریف_کرو N_ABS   0x2
#تعریف_کرو N_EXT   0x1
#تعریف_کرو N_SECT  0xe

#تعریف_کرو N_WEAK_REF      0x0040
#تعریف_کرو N_WEAK_DEF      0x0080

ساخت macho {
    ساخت mach_سرخی_64 mh;
    صحیح *seg2lc, nseg;
    ساخت بھرو_command **lc;
    ساخت اندراج_نقطہ_command *ep;
    صحیح nlc;
    ساخت {
        Section *s;
        صحیح machosect;
    } sk_مقصد_sect[sk_آخری];
    صحیح *elfsectomacho;
    صحیح *e2msym;
    Section *symtab, *strtab, *indirsyms, *stubs, *exports;
    uint32_t ilocal, iextdef, iundef;
    صحیح stubsym, n_got, nr_plt;
    صحیح segment[sk_آخری];
#اگر_تعریف_شدہ CONFIG_NEW_MACHO
    Section *chained_fixups;
    صحیح n_bind;
    صحیح n_bind_rebase;
    ساخت bind_rebase {
	صحیح section;
	صحیح bind;
	ElfW_Rel rel;
    } *bind_rebase;
#ورنہ
    Section *rebase, *binding, *weak_binding, *lazy_binding;
    Section *stub_helper, *la_علامت_ptr;
    ساخت dyld_info_command *dyldinfo;
    صحیح helpsym, lasym, dyld_نجی, dyld_stub_binder;
    صحیح n_lazy_bind;    
    ساخت s_lazy_bind {
        صحیح section;
        صحیح bind_انحراف;
        صحیح la_علامت_انحراف;
        ElfW_Rel rel;
    } *s_lazy_bind;
    صحیح n_rebase;    
    ساخت s_rebase {
        صحیح section;
        ElfW_Rel rel;
    } *s_rebase;
    صحیح n_bind; 
    ساخت bind {
        صحیح section;
        ElfW_Rel rel;
    } *bind;
#اگر_ختم
};

#تعریف_کرو SHT_LINKEDIT (SHT_LOOS + 42)
#تعریف_کرو SHN_FROMDLL  (SHN_LOOS + 2)  /* Symbol is undefined, comes from a DLL */

ساکن خالی * جوڑو_lc(ساخت macho *mo, uint32_t cmd, uint32_t cmdsize)
{
    ساخت بھرو_command *lc = tcc_mallocz(cmdsize);
    lc->cmd = cmd;
    lc->cmdsize = cmdsize;
    mo->lc = tcc_realloc(mo->lc, حجم(mo->lc[0]) * (mo->nlc + 1));
    mo->lc[mo->nlc++] = lc;
    واپس lc;
}

ساکن ساخت segment_command_64 * جوڑو_segment(ساخت macho *mo, ثابت حرف *name)
{
    ساخت segment_command_64 *sc = جوڑو_lc(mo, LC_SEGMENT_64, حجم(*sc));
    strncpy(sc->segname, name, 16);
    mo->seg2lc = tcc_realloc(mo->seg2lc, حجم(*mo->seg2lc) * (mo->nseg + 1));
    mo->seg2lc[mo->nseg++] = mo->nlc - 1;
    واپس sc;
}

ساکن ساخت segment_command_64 * get_segment(ساخت macho *mo, صحیح i)
{
    واپس (ساخت segment_command_64 *) (mo->lc[mo->seg2lc[i]]);
}

ساکن صحیح جوڑو_section(ساخت macho *mo, ساخت segment_command_64 **_seg, ثابت حرف *name)
{
    ساخت segment_command_64 *seg = *_seg;
    صحیح ret = seg->nsects;
    ساخت section_64 *sec;
    seg->nsects++;
    seg->cmdsize += حجم(*sec);
    seg = tcc_realloc(seg, حجم(*seg) + seg->nsects * حجم(*sec));
    sec = (ساخت section_64*)((حرف*)seg + حجم(*seg)) + ret;
    memset(sec, 0, حجم(*sec));
    strncpy(sec->sectname, name, 16);
    strncpy(sec->segname, seg->segname, 16);
    *_seg = seg;
    واپس ret;
}

ساکن ساخت section_64 *get_section(ساخت segment_command_64 *seg, صحیح i)
{
    واپس (ساخت section_64*)((حرف*)seg + حجم(*seg)) + i;
}

ساکن خالی * جوڑو_dylib(ساخت macho *mo, حرف *name)
{
    ساخت dylib_command *lc;
    صحیح sz = (حجم(*lc) + لڑی_لمبائی(name) + 1 + 7) & -8;
    lc = جوڑو_lc(mo, LC_بھرو_DYLIB, sz);
    lc->name = حجم(*lc);
    strcpy((حرف*)lc + lc->name, name);
    lc->timestamp = 2;
    lc->current_نسخہ = 1 << 16;
    lc->compatibility_نسخہ = 1 << 16;
    واپس lc;
}

ساکن صحیح uleb128_سائز (غیرعلامتی طویل طویل قدر)
{
    صحیح سائز =  0;

    کرو {
        قدر >>= 7;
        سائز++;
    } جب (قدر != 0);
    واپس سائز;
}

ساکن خالی write_uleb128(Section *section, uint64_t قدر)
{
    کرو {
        غیرعلامتی حرف byte = قدر & 0x7f;
	uint8_t *ptr = section_ptr_جوڑو(section, 1);

        قدر >>= 7;
        *ptr = byte | (قدر ? 0x80 : 0);
    } جب (قدر != 0);
}

ساکن خالی tcc_macho_جوڑو_destructor(TCCState *s1)
{
    صحیح init_sym, mh_execute_سرخی, at_exit_sym;
    Section *s;
    ElfW_Rel *rel;
    uint8_t *ptr;

    mh_execute_سرخی = put_elf_sym(s1->symtab, -4096, 0,
				    ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				    متن_section->sh_عدد, "__mh_execute_header");
    s = ڈھونڈو_section(s1, ".fini_array");
    اگر (s->ڈیٹا_انحراف == 0)
        واپس; 
    init_sym = put_elf_sym(s1->symtab, متن_section->ڈیٹا_انحراف, 0,
                           ELFW(ST_INFO)(STB_LOCAL, STT_FUNC), 0,
                           متن_section->sh_عدد, "___GLOBAL_init_65535");
    at_exit_sym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_GLOBAL, STT_FUNC), 0,
                              SHN_UNDEF, "___cxa_atexit");
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    ptr = section_ptr_جوڑو(متن_section, 4);
    ptr[0] = 0x55;  // pushq   %rbp
    ptr[1] = 0x48;  // movq    %rsp, %rbp
    ptr[2] = 0x89;
    ptr[3] = 0xe5;
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        صحیح sym_اشاریہ = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_جوڑو(متن_section, 26);
        ptr[0] = 0x48;  // lea destructor(%rip),%rax
        ptr[1] = 0x8d;
        ptr[2] = 0x05;
        put_elf_reloca(s1->symtab, متن_section, 
		       متن_section->ڈیٹا_انحراف - 23,
		       R_X86_64_PC32, sym_اشاریہ, -4);
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
		       متن_section->ڈیٹا_انحراف - 9,
		       R_X86_64_PC32, mh_execute_سرخی, -4);
	ptr[21] = 0xe8; // call __cxa_atexit
        put_elf_reloca(s1->symtab, متن_section,
		       متن_section->ڈیٹا_انحراف - 4,
		       R_X86_64_PLT32, at_exit_sym, -4);
    }
    ptr = section_ptr_جوڑو(متن_section, 2);
    ptr[0] = 0x5d;  // pop   %rbp
    ptr[1] = 0xc3;  // ret
#وگرنہ_اگر defined TCC_ہدف_ARM64
    ptr = section_ptr_جوڑو(متن_section, 8);
    write32le(ptr, 0xa9bf7bfd);     // stp     x29, x30, [sp, #-16]!
    write32le(ptr + 4, 0x910003fd); // mov     x29, sp
    for_each_elem(s->reloc, 0, rel, ElfW_Rel) {
        صحیح sym_اشاریہ = ELFW(R_SYM)(rel->r_info);

        ptr = section_ptr_جوڑو(متن_section, 24);
        put_elf_reloc(s1->symtab, متن_section, 
		      متن_section->ڈیٹا_انحراف - 24,
		      R_AARCH64_ADR_PREL_PG_HI21, sym_اشاریہ);
        write32le(ptr, 0x90000000);      // adrp x0, destructor@page
        put_elf_reloc(s1->symtab, متن_section,
		      متن_section->ڈیٹا_انحراف - 20,
		      R_AARCH64_LDST8_ABS_LO12_NC, sym_اشاریہ);
        write32le(ptr + 4, 0x91000000);  // add x0,x0,destructor@pageoff
        write32le(ptr + 8, 0xd2800001);  // mov x1, #0
        put_elf_reloc(s1->symtab, متن_section, 
		      متن_section->ڈیٹا_انحراف - 12,
		      R_AARCH64_ADR_PREL_PG_HI21, mh_execute_سرخی);
        write32le(ptr + 12, 0x90000002);      // adrp x2, mh_execute_header@page
        put_elf_reloc(s1->symtab, متن_section,
		      متن_section->ڈیٹا_انحراف - 8,
		      R_AARCH64_LDST8_ABS_LO12_NC, mh_execute_سرخی);
        write32le(ptr + 16, 0x91000042);  // add x2,x2,mh_execute_header@pageoff
        put_elf_reloc(s1->symtab, متن_section,
		      متن_section->ڈیٹا_انحراف - 4,
		      R_AARCH64_CALL26, at_exit_sym);
	write32le(ptr + 20, 0x94000000); // bl __cxa_atexit
    }
    ptr = section_ptr_جوڑو(متن_section, 8);
    write32le(ptr, 0xa8c17bfd);     // ldp     x29, x30, [sp], #16
    write32le(ptr + 4, 0xd65f03c0); // ret
#اگر_ختم
    s->reloc->ڈیٹا_انحراف = s->ڈیٹا_انحراف = 0;
    s->sh_flags &= ~SHF_ALLOC;
    جوڑو_array (s1, ".init_array", init_sym);
}

#اگر_تعریف_شدہ CONFIG_NEW_MACHO
ساکن خالی bind_rebase_جوڑو(ساخت macho *mo, صحیح bind, صحیح sh_info,
			    ElfW_Rel *rel, ساخت sym_attr *attr)
{
    mo->bind_rebase = tcc_realloc(mo->bind_rebase, (mo->n_bind_rebase + 1) *
		                  حجم(ساخت bind_rebase));
    mo->bind_rebase[mo->n_bind_rebase].section = sh_info;
    mo->bind_rebase[mo->n_bind_rebase].bind = bind;
    mo->bind_rebase[mo->n_bind_rebase].rel = *rel;
    اگر (attr)
        mo->bind_rebase[mo->n_bind_rebase].rel.r_انحراف = attr->got_انحراف;
    mo->n_bind_rebase++;
    mo->n_bind += bind;
}

ساکن خالی check_relocs(TCCState *s1, ساخت macho *mo)
{
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    صحیح i, j, type, gotplt_اندراج, sym_اشاریہ, for_رمز;
    uint32_t *pi, *goti;
    ساخت sym_attr *attr;

    goti = تہی;
    mo->nr_plt = mo->n_got = 0;
    برائے (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        اگر (s->sh_type != SHT_RELX ||
	    !لڑی_موازنہ(s1->sections[s->sh_info]->name, ".debug_", 7))
            جاری;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_اندراج = gotplt_اندراج_type(type);
            for_رمز = رمز_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_اشاریہ = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
            اگر (sym->st_shndx == SHN_UNDEF
                || gotplt_اندراج == ALWAYS_GOTPLT_اندراج) {
                attr = get_sym_attr(s1, sym_اشاریہ, 1);
                اگر (!attr->dyn_اشاریہ) {
                    attr->got_انحراف = s1->got->ڈیٹا_انحراف;
                    attr->plt_انحراف = -1;
                    attr->dyn_اشاریہ = 1; /* used as flag */
                    section_ptr_جوڑو(s1->got, PTR_سائز);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_انحراف,
                                  R_JMP_خانہ, sym_اشاریہ);
	 	    goti = tcc_realloc(goti, (mo->n_got + 1) * حجم(*goti));
                    اگر (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        اگر (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (حرف *) symtab_section->link->ڈیٹا + sym->st_name);
			goti[mo->n_got++] = بالواسطہ_علامت_LOCAL;
                    } ورنہ {
                        goti[mo->n_got++] = mo->e2msym[sym_اشاریہ];
                        اگر (sym->st_shndx == SHN_UNDEF
#اگر_تعریف_شدہ TCC_ہدف_X86_64
                            && type == R_X86_64_GOTPCREL
#وگرنہ_اگر defined TCC_ہدف_ARM64
                            && type == R_AARCH64_ADR_GOT_صفحہ
#اگر_ختم
                            ) {
			    attr->plt_انحراف = -mo->n_bind_rebase - 2;
			    bind_rebase_جوڑو(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
			    s1->got->reloc->ڈیٹا_انحراف -= حجم (ElfW_Rel);
			}
		        اگر (for_رمز && sym->st_shndx == SHN_UNDEF)
			    s1->got->reloc->ڈیٹا_انحراف -= حجم (ElfW_Rel);
		    }
                }
                اگر (for_رمز && sym->st_shndx == SHN_UNDEF) {
		    اگر ((صحیح)attr->plt_انحراف < -1) {
			/* remove above bind and replace with plt */
			mo->bind_rebase[-attr->plt_انحراف - 2].bind = 2;
			attr->plt_انحراف = -1;
		    }
                    اگر (attr->plt_انحراف == -1) {
                        uint8_t *jmp;

                        attr->plt_انحراف = mo->stubs->ڈیٹا_انحراف;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
                        اگر (type != R_X86_64_PLT32)
                             جاری;
                        jmp = section_ptr_جوڑو(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *ofs(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_انحراف + 2,
                                      R_X86_64_GOTPCREL, sym_اشاریہ);
#وگرنہ_اگر defined TCC_ہدف_ARM64
                        اگر (type != R_AARCH64_CALL26)
                             جاری;
                        jmp = section_ptr_جوڑو(mo->stubs, 12);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_انحراف,
                                      R_AARCH64_ADR_GOT_صفحہ, sym_اشاریہ);
                        write32le(jmp, // adrp x16, #sym
                                  0x90000010);
                        put_elf_reloc(s1->symtab, mo->stubs,
                                      attr->plt_انحراف + 4,
                                      R_AARCH64_LD64_GOT_LO12_NC, sym_اشاریہ);
                        write32le(jmp + 4, // ld x16,[x16, #sym]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);
#اگر_ختم
			bind_rebase_جوڑو(mo, 1, s1->got->reloc->sh_info, &save_rel, attr);
                        pi = section_ptr_جوڑو(mo->indirsyms, حجم(*pi));
                        *pi = mo->e2msym[sym_اشاریہ];
                        mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_انحراف;
                }
            }
	    اگر (type == R_ڈیٹا_PTR || type == R_JMP_خانہ)
		bind_rebase_جوڑو(mo, sym->st_shndx == SHN_UNDEF ? 1 : 0,
				s->sh_info, &save_rel, تہی);
        }
    }
    /* remove deleted binds */
    برائے (i = 0, j = 0; i < mo->n_bind_rebase; i++)
	اگر (mo->bind_rebase[i].bind == 2)
	    mo->n_bind--;
	ورنہ
	    mo->bind_rebase[j++] = mo->bind_rebase[i];
    mo->n_bind_rebase = j;
    pi = section_ptr_جوڑو(mo->indirsyms, mo->n_got * حجم(*pi));
    حافظہ_نقل(pi, goti, mo->n_got * حجم(*pi));
    tcc_free(goti);
}

#ورنہ

ساکن خالی check_relocs(TCCState *s1, ساخت macho *mo)
{
    uint8_t *jmp;
    Section *s;
    ElfW_Rel *rel, save_rel;
    ElfW(Sym) *sym;
    صحیح i, type, gotplt_اندراج, sym_اشاریہ, for_رمز;
    صحیح bind_انحراف, la_علامت_انحراف;
    uint32_t *pi, *goti;
    ساخت sym_attr *attr;

#اگر_تعریف_شدہ TCC_ہدف_X86_64
    jmp = section_ptr_جوڑو(mo->stub_helper, 16);
    jmp[0] = 0x4c;  /* leaq _dyld_private(%rip), %r11 */
    jmp[1] = 0x8d;
    jmp[2] = 0x1d;
    put_elf_reloca(s1->symtab, mo->stub_helper, 3,
		   R_X86_64_PC32, mo->dyld_نجی, -4);
    jmp[7] = 0x41;  /* pushq %r11 */
    jmp[8] = 0x53;
    jmp[9] = 0xff;  /* jmpq    *dyld_stub_binder@GOT(%rip) */
    jmp[10] = 0x25;
    put_elf_reloca(s1->symtab, mo->stub_helper, 11,
		   R_X86_64_GOTPCREL, mo->dyld_stub_binder, -4);
    jmp[15] = 0x90; /* nop */
#وگرنہ_اگر defined TCC_ہدف_ARM64
    jmp = section_ptr_جوڑو(mo->stub_helper, 24);
    put_elf_reloc(s1->symtab, mo->stub_helper, 0,
		  R_AARCH64_ADR_PREL_PG_HI21, mo->dyld_نجی);
    write32le(jmp, 0x90000011); // adrp x17, _dyld_private@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 4,
		  R_AARCH64_LDST64_ABS_LO12_NC, mo->dyld_نجی);
    write32le(jmp + 4, 0x91000231); // add x17,x17,_dyld_private@pageoff
    write32le(jmp + 8, 0xa9bf47f0); // stp x16/x17, [sp, #-16]!
    put_elf_reloc(s1->symtab, mo->stub_helper, 12,
		  R_AARCH64_ADR_GOT_صفحہ, mo->dyld_stub_binder);
    write32le(jmp + 12, 0x90000010); // adrp x16, dyld_stub_binder@page
    put_elf_reloc(s1->symtab, mo->stub_helper, 16,
		  R_AARCH64_LD64_GOT_LO12_NC, mo->dyld_stub_binder);
    write32le(jmp + 16, 0xf9400210); // ldr x16,[x16,dyld_stub_binder@pageoff]
    write32le(jmp + 20, 0xd61f0200); // br x16
#اگر_ختم
    
    goti = تہی;
    mo->nr_plt = mo->n_got = 0;
    برائے (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        اگر (s->sh_type != SHT_RELX ||
	    !لڑی_موازنہ(s1->sections[s->sh_info]->name, ".debug_", 7))
            جاری;
        for_each_elem(s, 0, rel, ElfW_Rel) {
	    save_rel = *rel;
            type = ELFW(R_TYPE)(rel->r_info);
            gotplt_اندراج = gotplt_اندراج_type(type);
            for_رمز = رمز_reloc(type);
            /* We generate a non-lazy pointer for used undefined symbols
               and for defined symbols that must have a place for their
               address due to codegen (i.e. a reloc requiring a got slot).  */
            sym_اشاریہ = ELFW(R_SYM)(rel->r_info);
            sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
            اگر (sym->st_shndx == SHN_UNDEF
                || gotplt_اندراج == ALWAYS_GOTPLT_اندراج) {
                attr = get_sym_attr(s1, sym_اشاریہ, 1);
                اگر (!attr->dyn_اشاریہ) {
                    attr->got_انحراف = s1->got->ڈیٹا_انحراف;
                    attr->plt_انحراف = -1;
                    attr->dyn_اشاریہ = 1; /* used as flag */
		    section_ptr_جوڑو(s1->got, PTR_سائز);
                    put_elf_reloc(s1->symtab, s1->got, attr->got_انحراف,
                                  R_JMP_خانہ, sym_اشاریہ);
		    goti = tcc_realloc(goti, (mo->n_got + 1) * حجم(*goti));
                    اگر (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL) {
                        اگر (sym->st_shndx == SHN_UNDEF)
                          tcc_error("unresolved local reference to '%s'",
				    (حرف *) symtab_section->link->ڈیٹا + sym->st_name);
			goti[mo->n_got++] = بالواسطہ_علامت_LOCAL;
                    } ورنہ {
			goti[mo->n_got++] = mo->e2msym[sym_اشاریہ];
			اگر (sym->st_shndx == SHN_UNDEF
#اگر_تعریف_شدہ TCC_ہدف_X86_64
			    && type == R_X86_64_GOTPCREL
#وگرنہ_اگر defined TCC_ہدف_ARM64
			    && type == R_AARCH64_ADR_GOT_صفحہ
#اگر_ختم
			    ) {
			    mo->bind =
			        tcc_realloc(mo->bind,
					    (mo->n_bind + 1) *
					    حجم(ساخت bind));
			    mo->bind[mo->n_bind].section = s1->got->reloc->sh_info;
			    mo->bind[mo->n_bind].rel = save_rel;
                            mo->bind[mo->n_bind].rel.r_انحراف = attr->got_انحراف;
			    mo->n_bind++;
			    s1->got->reloc->ڈیٹا_انحراف -= حجم (ElfW_Rel);
			}
		    }
                }
                اگر (for_رمز && sym->st_shndx == SHN_UNDEF) {
                    اگر (attr->plt_انحراف == -1) {
                        attr->plt_انحراف = mo->stubs->ڈیٹا_انحراف;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
			اگر (type != R_X86_64_PLT32)
			     جاری;
			/* __stubs */
                        jmp = section_ptr_جوڑو(mo->stubs, 6);
                        jmp[0] = 0xff;  /* jmpq *__la_symbol_ptr(%rip) */
                        jmp[1] = 0x25;
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->ڈیٹا_انحراف - 4,
                                       R_X86_64_PC32, mo->lasym,
				       mo->la_علامت_ptr->ڈیٹا_انحراف - 4);

			/* __stub_helper */
			bind_انحراف = mo->stub_helper->ڈیٹا_انحراف + 1;
                        jmp = section_ptr_جوڑو(mo->stub_helper, 10);
                        jmp[0] = 0x68;  /* pushq $bind_offset */
                        jmp[5] = 0xe9;  /* jmpq __stub_helper */
                        write32le(jmp + 6, -mo->stub_helper->ڈیٹا_انحراف);

			/* __la_symbol_ptr */
			la_علامت_انحراف = mo->la_علامت_ptr->ڈیٹا_انحراف;
                        put_elf_reloca(s1->symtab, mo->la_علامت_ptr,
				       mo->la_علامت_ptr->ڈیٹا_انحراف,
				       R_ڈیٹا_PTR, mo->helpsym,
				       mo->stub_helper->ڈیٹا_انحراف - 10);
			section_ptr_جوڑو(mo->la_علامت_ptr, PTR_سائز);
#وگرنہ_اگر defined TCC_ہدف_ARM64
			اگر (type != R_AARCH64_CALL26)
			     جاری;
			/* __stubs */
                        jmp = section_ptr_جوڑو(mo->stubs, 12);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->ڈیٹا_انحراف - 12,
                                       R_AARCH64_ADR_PREL_PG_HI21, mo->lasym,
				       mo->la_علامت_ptr->ڈیٹا_انحراف);
                        write32le(jmp, // adrp x16, __la_symbol_ptr@page
                                  0x90000010);
                        put_elf_reloca(s1->symtab, mo->stubs,
                                       mo->stubs->ڈیٹا_انحراف - 8,
                                       R_AARCH64_LDST64_ABS_LO12_NC, mo->lasym,
				       mo->la_علامت_ptr->ڈیٹا_انحراف);
                        write32le(jmp + 4, // ldr x16,[x16, __la_symbol_ptr@pageoff]
                                  0xf9400210);
                        write32le(jmp + 8, // br x16
                                  0xd61f0200);

			/* __stub_helper */
			bind_انحراف = mo->stub_helper->ڈیٹا_انحراف + 8;
                        jmp = section_ptr_جوڑو(mo->stub_helper, 12);
                        write32le(jmp + 0, // ldr  w16, l0
                                  0x18000050);
                        write32le(jmp + 4, // b stubHelperHeader
                                  0x14000000 +
				  ((-(mo->stub_helper->ڈیٹا_انحراف - 8) / 4) &
				   0x3ffffff));
                        write32le(jmp + 8, 0); // l0: .long bind_offset

			/* __la_symbol_ptr */
			la_علامت_انحراف = mo->la_علامت_ptr->ڈیٹا_انحراف;
                        put_elf_reloca(s1->symtab, mo->la_علامت_ptr,
				       mo->la_علامت_ptr->ڈیٹا_انحراف,
				       R_ڈیٹا_PTR, mo->helpsym,
				       mo->stub_helper->ڈیٹا_انحراف - 12);
			section_ptr_جوڑو(mo->la_علامت_ptr, PTR_سائز);
#اگر_ختم
                        mo->s_lazy_bind =
                            tcc_realloc(mo->s_lazy_bind, (mo->n_lazy_bind + 1) *
                                        حجم(ساخت s_lazy_bind));
                        mo->s_lazy_bind[mo->n_lazy_bind].section =
                            mo->stub_helper->reloc->sh_info;
                        mo->s_lazy_bind[mo->n_lazy_bind].bind_انحراف =
			    bind_انحراف;
                        mo->s_lazy_bind[mo->n_lazy_bind].la_علامت_انحراف =
			    la_علامت_انحراف;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel = save_rel;
                        mo->s_lazy_bind[mo->n_lazy_bind].rel.r_انحراف =
                            attr->plt_انحراف;
                        mo->n_lazy_bind++;
			pi = section_ptr_جوڑو(mo->indirsyms, حجم(*pi));
			*pi = mo->e2msym[sym_اشاریہ];
			mo->nr_plt++;
                    }
                    rel->r_info = ELFW(R_INFO)(mo->stubsym, type);
                    rel->r_addend += attr->plt_انحراف;
                }
            }
            اگر (type == R_ڈیٹا_PTR || type == R_JMP_خانہ) {
		اگر (sym->st_shndx == SHN_UNDEF) {
		    mo->bind = tcc_realloc(mo->bind,
					   (mo->n_bind + 1) *
					   حجم(ساخت bind));
		    mo->bind[mo->n_bind].section = s->sh_info;
		    mo->bind[mo->n_bind].rel = save_rel;
		    mo->n_bind++;
		}
		ورنہ {
                    mo->s_rebase =
                        tcc_realloc(mo->s_rebase, (mo->n_rebase + 1) *
				    حجم(ساخت s_rebase));
                    mo->s_rebase[mo->n_rebase].section = s->sh_info;
                    mo->s_rebase[mo->n_rebase].rel = save_rel;
                    mo->n_rebase++;
		}
	    }
        }
    }
    pi = section_ptr_جوڑو(mo->indirsyms, mo->n_got * حجم(*pi));
    حافظہ_نقل(pi, goti, mo->n_got * حجم(*pi));
    pi = section_ptr_جوڑو(mo->indirsyms, mo->nr_plt * حجم(*pi));
    حافظہ_نقل(pi, mo->indirsyms->ڈیٹا, mo->nr_plt * حجم(*pi));
    tcc_free(goti);
}
#اگر_ختم

ساکن صحیح check_symbols(TCCState *s1, ساخت macho *mo)
{
    صحیح sym_اشاریہ, sym_انتہا;
    صحیح ret = 0;

    mo->ilocal = mo->iextdef = mo->iundef = -1;
    sym_انتہا = symtab_section->ڈیٹا_انحراف / حجم(ElfW(Sym));
    برائے (sym_اشاریہ = 1; sym_اشاریہ < sym_انتہا; ++sym_اشاریہ) {
        صحیح elf_اشاریہ = ((ساخت nlist_64 *)mo->symtab->ڈیٹا + sym_اشاریہ - 1)->n_قدر;
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->ڈیٹا + elf_اشاریہ;
        ثابت حرف *name = (حرف*)symtab_section->link->ڈیٹا + sym->st_name;
        غیرعلامتی type = ELFW(ST_TYPE)(sym->st_info);
        غیرعلامتی bind = ELFW(ST_BIND)(sym->st_info);
        غیرعلامتی vis  = ELFW(ST_VISIBILITY)(sym->st_other);

        dprintf("%4d (%4d): %09lx %4d %4d %4d %3d %s\n",
                sym_اشاریہ, elf_اشاریہ, (طویل)sym->st_قدر,
                type, bind, vis, sym->st_shndx, name);
        اگر (bind == STB_LOCAL) {
            اگر (mo->ilocal == -1)
              mo->ilocal = sym_اشاریہ - 1;
            اگر (mo->iextdef != -1 || mo->iundef != -1)
              tcc_error("local syms after global ones");
        } ورنہ اگر (sym->st_shndx != SHN_UNDEF) {
            اگر (mo->iextdef == -1)
              mo->iextdef = sym_اشاریہ - 1;
            اگر (mo->iundef != -1)
              tcc_error("external defined symbol after undefined");
        } ورنہ اگر (sym->st_shndx == SHN_UNDEF) {
            اگر (mo->iundef == -1)
              mo->iundef = sym_اشاریہ - 1;
            اگر (ELFW(ST_BIND)(sym->st_info) == STB_WEAK
		|| s1->output_type != TCC_OUTPUT_EXE
                || ڈھونڈو_elf_sym(s1->dynsymtab_section, name)) {
                /* Mark the symbol as coming from a dylib so that
                   relocate_syms doesn't complain.  Normally bind_exe_dynsyms
                   would do this check, and place the symbol into dynsym
                   which is checked by relocate_syms.  But Mach-O doesn't use
                   bind_exe_dynsyms.  */
                sym->st_shndx = SHN_FROMDLL;
                جاری;
            }
            tcc_error_noabort("unresolved reference to '%s'", name);
            ret = -1;
        }
    }
    واپس ret;
}

ساکن خالی convert_علامت(TCCState *s1, ساخت macho *mo, ساخت nlist_64 *pn)
{
    ساخت nlist_64 n = *pn;
    ElfSym *sym = (ElfW(Sym) *)symtab_section->ڈیٹا + pn->n_قدر;
    ثابت حرف *name = (حرف*)symtab_section->link->ڈیٹا + sym->st_name;
    انتخاب(ELFW(ST_TYPE)(sym->st_info)) {
    حالت STT_NOTYPE:
    حالت STT_OBJECT:
    حالت STT_FUNC:
    حالت STT_TLS:
    حالت STT_SECTION:
        n.n_type = N_SECT;
        توڑو;
    حالت STT_FILE:
        n.n_type = N_ABS;
        توڑو;
    طےشدہ:
        tcc_error("unhandled ELF symbol type %d %s",
                  ELFW(ST_TYPE)(sym->st_info), name);
    }
    اگر (sym->st_shndx == SHN_UNDEF)
      tcc_error("should have been rewritten to SHN_FROMDLL: %s", name);
    ورنہ اگر (sym->st_shndx == SHN_FROMDLL)
      n.n_type = N_UNDF, n.n_sect = 0;
    ورنہ اگر (sym->st_shndx == SHN_ABS)
      n.n_type = N_ABS, n.n_sect = 0;
    ورنہ اگر (sym->st_shndx >= SHN_LORESERVE)
      tcc_error("unhandled ELF symbol section %d %s", sym->st_shndx, name);
    ورنہ اگر (!mo->elfsectomacho[sym->st_shndx]) {
      اگر (لڑی_موازنہ(s1->sections[sym->st_shndx]->name, ".debug_", 7))
        tcc_error("ELF section %d(%s) not mapped into Mach-O for symbol %s",
                  sym->st_shndx, s1->sections[sym->st_shndx]->name, name);
    }
    ورنہ
      n.n_sect = mo->elfsectomacho[sym->st_shndx];
    اگر (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL)
      n.n_type |=  N_EXT;
    ورنہ اگر (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
      n.n_desc |= N_WEAK_REF | (n.n_type != N_UNDF ? N_WEAK_DEF : 0);
    n.n_strx = pn->n_strx;
    n.n_قدر = sym->st_قدر;
    *pn = n;
}

ساکن خالی convert_symbols(TCCState *s1, ساخت macho *mo)
{
    ساخت nlist_64 *pn;
    for_each_elem(mo->symtab, 0, pn, ساخت nlist_64)
        convert_علامت(s1, mo, pn);
}

ساکن صحیح machosymcmp(ثابت خالی *_a, ثابت خالی *_b, خالی *arg)
{
    TCCState *s1 = arg;
    صحیح ea = ((ساخت nlist_64 *)_a)->n_قدر;
    صحیح eb = ((ساخت nlist_64 *)_b)->n_قدر;
    ElfSym *sa = (ElfSym *)symtab_section->ڈیٹا + ea;
    ElfSym *sb = (ElfSym *)symtab_section->ڈیٹا + eb;
    صحیح r;
    /* locals, then defined externals, then undefined externals, the
       last two sections also by name, otherwise stable sort */
    r = (ELFW(ST_BIND)(sb->st_info) == STB_LOCAL)
        - (ELFW(ST_BIND)(sa->st_info) == STB_LOCAL);
    اگر (r)
      واپس r;
    r = (sa->st_shndx == SHN_UNDEF) - (sb->st_shndx == SHN_UNDEF);
    اگر (r)
      واپس r;
    اگر (ELFW(ST_BIND)(sa->st_info) != STB_LOCAL) {
        ثابت حرف * na = (حرف*)symtab_section->link->ڈیٹا + sa->st_name;
        ثابت حرف * nb = (حرف*)symtab_section->link->ڈیٹا + sb->st_name;
        r = strcmp(na, nb);
        اگر (r)
          واپس r;
    }
    واپس ea - eb;
}

/* cannot use qsort because code has to be reentrant */
ساکن خالی tcc_qsort (خالی  *بنیاد, سائز_t nel, سائز_t چوڑائی,
                       صحیح (*comp)(ثابت خالی *, ثابت خالی *, خالی *), خالی *arg)
{
    سائز_t wnel, gap, wgap, i, j, k;
    حرف *a, *b, tmp;

    wnel = چوڑائی * nel;
    برائے (gap = 0; ++gap < nel;)
        gap *= 3;
    جب ( gap /= 3 ) {
        wgap = چوڑائی * gap;
        برائے (i = wgap; i < wnel; i += چوڑائی) {
            برائے (j = i - wgap; ;j -= wgap) {
                a = j + (حرف *)بنیاد;
                b = a + wgap;
                اگر ( (*comp)(a, b, arg) <= 0 )
                    توڑو;
                k = چوڑائی;
                کرو {
                    tmp = *a;
                    *a++ = *b;
                    *b++ = tmp;
                } جب ( --k );
                اگر (j < wgap)
                    توڑو;
            }
        }
    }
}

ساکن خالی create_symtab(TCCState *s1, ساخت macho *mo)
{
    صحیح sym_اشاریہ, sym_انتہا;
    ساخت nlist_64 *pn;

    /* Stub creation belongs to check_relocs, but we need to create
       the symbol now, so its included in the sorting.  */
    mo->stubs = new_section(s1, "__stubs", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    s1->got = new_section(s1, ".got", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->stubsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stubs->sh_عدد, ".__stubs");
#اگر_تعریف_شدہ CONFIG_NEW_MACHO
    mo->chained_fixups = new_section(s1, "CHAINED_FIXUPS",
				     SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#ورنہ
    mo->stub_helper = new_section(s1, "__stub_helper", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    mo->la_علامت_ptr = new_section(s1, "__la_symbol_ptr", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    mo->helpsym = put_elf_sym(s1->symtab, 0, 0,
                              ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                              mo->stub_helper->sh_عدد, ".__stub_helper");
    mo->lasym = put_elf_sym(s1->symtab, 0, 0,
                            ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                            mo->la_علامت_ptr->sh_عدد, ".__la_symbol_ptr");
    section_ptr_جوڑو(ڈیٹا_section, -ڈیٹا_section->ڈیٹا_انحراف & (PTR_سائز - 1));
    mo->dyld_نجی = put_elf_sym(s1->symtab, ڈیٹا_section->ڈیٹا_انحراف, PTR_سائز,
                                   ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT), 0,
                                   ڈیٹا_section->sh_عدد, ".__dyld_private");
    section_ptr_جوڑو(ڈیٹا_section, PTR_سائز);
    mo->dyld_stub_binder = put_elf_sym(s1->symtab, 0, 0,
                		       ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT), 0,
				       SHN_UNDEF, "dyld_stub_binder");
    mo->rebase = new_section(s1, "REBASE", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->binding = new_section(s1, "BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->weak_binding = new_section(s1, "WEAK_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->lazy_binding = new_section(s1, "LAZY_BINDING", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
#اگر_ختم
    mo->exports = new_section(s1, "EXPORT", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->indirsyms = new_section(s1, "LEINDIR", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);

    mo->symtab = new_section(s1, "LESYMTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    mo->strtab = new_section(s1, "LESTRTAB", SHT_LINKEDIT, SHF_ALLOC | SHF_WRITE);
    put_elf_str(mo->strtab, " "); /* Mach-O starts strtab with a space */
    sym_انتہا = symtab_section->ڈیٹا_انحراف / حجم(ElfW(Sym));
    pn = section_ptr_جوڑو(mo->symtab, حجم(*pn) * (sym_انتہا - 1));
    برائے (sym_اشاریہ = 1; sym_اشاریہ < sym_انتہا; ++sym_اشاریہ) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->ڈیٹا + sym_اشاریہ;
        ثابت حرف *name = (حرف*)symtab_section->link->ڈیٹا + sym->st_name;
        pn[sym_اشاریہ - 1].n_strx = put_elf_str(mo->strtab, name);
        pn[sym_اشاریہ - 1].n_قدر = sym_اشاریہ;
    }
    section_ptr_جوڑو(mo->strtab, -mo->strtab->ڈیٹا_انحراف & (PTR_سائز - 1));
    tcc_qsort(pn, sym_انتہا - 1, حجم(*pn), machosymcmp, s1);
    mo->e2msym = tcc_malloc(sym_انتہا * حجم(*mo->e2msym));
    mo->e2msym[0] = -1;
    برائے (sym_اشاریہ = 1; sym_اشاریہ < sym_انتہا; ++sym_اشاریہ) {
        mo->e2msym[pn[sym_اشاریہ - 1].n_قدر] = sym_اشاریہ - 1;
    }
}

ثابت ساخت {
    صحیح seg_initial;
    uint32_t flags;
    ثابت حرف *name;
} skinfo[sk_آخری] = {
    /*[sk_unknown] =*/        { 0 },
    /*[sk_discard] =*/        { 0 },
    /*[sk_text] =*/           { 1, S_REGULAR | S_ATTR_خالص_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS, "__text" },
    /*[sk_stubs] =*/          { 1, S_REGULAR | S_ATTR_خالص_INSTRUCTIONS | S_علامت_STUBS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stubs" },
    /*[sk_stub_helper] =*/    { 1, S_REGULAR | S_ATTR_خالص_INSTRUCTIONS
                                   | S_ATTR_SOME_INSTRUCTIONS , "__stub_helper" },
    /*[sk_ro_data] =*/        { 2, S_REGULAR, "__rodata" },
    /*[sk_uw_info] =*/        { 0 },
    /*[sk_nl_ptr] =*/         { 2, S_NON_LAZY_علامت_اشارے, "__got" },
    /*[sk_debug_info] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_info" },
    /*[sk_debug_abbrev] =*/   { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_abbrev" },
    /*[sk_debug_line] =*/     { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line" },
    /*[sk_debug_aranges] =*/  { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_aranges" },
    /*[sk_debug_str] =*/      { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_str" },
    /*[sk_debug_line_str] =*/ { 3, S_REGULAR | S_ATTR_DEBUG, "__debug_line_str" },
    /*[sk_stab] =*/           { 4, S_REGULAR, "__stab" },
    /*[sk_stab_str] =*/       { 4, S_REGULAR, "__stab_str" },
    /*[sk_la_ptr] =*/         { 4, S_LAZY_علامت_اشارے, "__la_symbol_ptr" },
    /*[sk_init] =*/           { 4, S_MOD_INIT_FUNC_اشارے, "__mod_init_func" },
    /*[sk_fini] =*/           { 4, S_MOD_رکن_FUNC_اشارے, "__mod_term_func" },
    /*[sk_rw_data] =*/        { 4, S_REGULAR, "__data" },
    /*[sk_bss] =*/            { 4, S_ZEROFILL, "__bss" },
    /*[sk_linkedit] =*/       { 5, S_REGULAR, تہی },
};

#تعریف_کرو	آغاز_3	((uint64_t)1 << 32)

ثابت ساخت {
    صحیح مستعمل;
    ثابت حرف *name;
    uint64_t vmaddr;
    uint64_t vmsize;
    vm_prot_t maxprot;
    vm_prot_t initprot;
    uint32_t flags;
} all_segment[] = {
    { 1, "__PAGEZERO",       0, آغاز_3, 0, 0,            0 },
    { 0, "__TEXT",       آغاز_3,     0, 5, 5,            0 },
    { 0, "__DATA_CONST",    -1,     0, 3, 3, SG_READ_ONLY },
    { 0, "__DWARF",         -1,     0, 7, 3,            0 },
    { 0, "__DATA",          -1,     0, 3, 3,            0 },
    { 1, "__LINKEDIT",      -1,     0, 1, 1,            0 },
};

#تعریف_کرو	N_SEGMENT	(حجم(all_segment)/حجم(all_segment[0]))

#اگر_تعریف_شدہ CONFIG_NEW_MACHO
ساکن خالی calc_fixup_سائز(TCCState *s1, ساخت macho *mo)
{
    صحیح i, سائز;

    سائز = (حجم(ساخت dyld_chained_fixups_سرخی) + 7) & -8;
    سائز += (حجم(ساخت dyld_chained_starts_اندر_image) + (mo->nseg - 1) * حجم(uint32_t) + 7) & -8;
    برائے (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	صحیح صفحہ_گنتی = (get_segment(mo, i)->vmsize + SEG_صفحہ_سائز - 1) / SEG_صفحہ_سائز;
	سائز += (حجم(ساخت dyld_chained_starts_اندر_segment) + (صفحہ_گنتی - 1) * حجم(uint16_t) + 7) & -8;
    }
    سائز += mo->n_bind * حجم (ساخت dyld_chained_import) + 1;
    برائے (i = 0; i < mo->n_bind_rebase; i++) {
	اگر (mo->bind_rebase[i].bind) {
	    صحیح sym_اشاریہ = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
	    ثابت حرف *name = (حرف *) symtab_section->link->ڈیٹا + sym->st_name;
	    سائز += لڑی_لمبائی(name) + 1;
	}
    }
    سائز = (سائز + 7) & -8;
    section_ptr_جوڑو(mo->chained_fixups, سائز);
}

#ورنہ

ساکن خالی سیٹ_segment_and_انحراف(TCCState *s1, ساخت macho *mo, addr_t addr,
				   uint8_t *ptr, صحیح opcode,
				   Section *sec, addr_t انحراف)
{
    صحیح i;
    ساخت segment_command_64 *seg = تہی;

    برائے (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
	seg = get_segment(mo, i);
	اگر (addr >= seg->vmaddr && addr < (seg->vmaddr + seg->vmsize))
	    توڑو;
    }
    *ptr = opcode | i;
    write_uleb128(sec, انحراف - seg->vmaddr);
}

ساکن خالی bind_rebase(TCCState *s1, ساخت macho *mo)
{
    صحیح i;
    uint8_t *ptr;
    ElfW(Sym) *sym;
    ثابت حرف *name;

    برائے (i = 0; i < mo->n_lazy_bind; i++) {
	صحیح sym_اشاریہ = ELFW(R_SYM)(mo->s_lazy_bind[i].rel.r_info);

	sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
	name = (حرف *) symtab_section->link->ڈیٹا + sym->st_name;
	write32le(mo->stub_helper->ڈیٹا +
		  mo->s_lazy_bind[i].bind_انحراف,
		  mo->lazy_binding->ڈیٹا_انحراف);
	ptr = section_ptr_جوڑو(mo->lazy_binding, 1);
	سیٹ_segment_and_انحراف(s1, mo, mo->la_علامت_ptr->sh_addr, ptr,
			       BIND_OPCODE_سیٹ_SEGMENT_AND_انحراف_ULEB,
			       mo->lazy_binding,
			       mo->s_lazy_bind[i].la_علامت_انحراف +
			       mo->la_علامت_ptr->sh_addr);
	ptr = section_ptr_جوڑو(mo->lazy_binding, 5 + لڑی_لمبائی(name));
	*ptr++ = BIND_OPCODE_سیٹ_DYLIB_SPECIAL_IMM |
		 (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
	*ptr++ = BIND_OPCODE_سیٹ_علامت_TRAILING_FLAGS_IMM | 0;
	strcpy((حرف *)ptr, name);
	ptr += لڑی_لمبائی(name) + 1;
	*ptr++ = BIND_OPCODE_DO_BIND;
	*ptr = BIND_OPCODE_مکمل;
    }
    برائے (i = 0; i < mo->n_rebase; i++) {
	Section *s = s1->sections[mo->s_rebase[i].section];

	ptr = section_ptr_جوڑو(mo->rebase, 2);
	*ptr++ = REBASE_OPCODE_سیٹ_TYPE_IMM | REBASE_TYPE_اشارہ_گر;
	سیٹ_segment_and_انحراف(s1, mo, s->sh_addr, ptr,
			       REBASE_OPCODE_سیٹ_SEGMENT_AND_انحراف_ULEB,
			       mo->rebase,
			       mo->s_rebase[i].rel.r_انحراف +
			       s->sh_addr);
	ptr = section_ptr_جوڑو(mo->rebase, 1);
	*ptr = REBASE_OPCODE_DO_REBASE_IMM_TIMES | 1;
    }
    برائے (i = 0; i < mo->n_bind; i++) {
	صحیح sym_اشاریہ = ELFW(R_SYM)(mo->bind[i].rel.r_info);
	Section *s = s1->sections[mo->bind[i].section];
	Section *binding;

	sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
	name = (حرف *) symtab_section->link->ڈیٹا + sym->st_name;
	binding = ELFW(ST_BIND)(sym->st_info) == STB_WEAK
	    ? mo->weak_binding : mo->binding;
        ptr = section_ptr_جوڑو(binding, 4 + (binding == mo->binding) +
			     	       لڑی_لمبائی(name));
	اگر (binding == mo->binding)
            *ptr++ = BIND_OPCODE_سیٹ_DYLIB_SPECIAL_IMM |
	             (BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xf);
        *ptr++ = BIND_OPCODE_سیٹ_علامت_TRAILING_FLAGS_IMM |
		 (binding == mo->weak_binding
		  ? BIND_علامت_FLAGS_WEAK_IMPORT : 0);
        strcpy((حرف *)ptr, name);
        ptr += لڑی_لمبائی(name) + 1;
        *ptr++ = BIND_OPCODE_سیٹ_TYPE_IMM | BIND_TYPE_اشارہ_گر;
	سیٹ_segment_and_انحراف(s1, mo, s->sh_addr, ptr,
			       BIND_OPCODE_سیٹ_SEGMENT_AND_انحراف_ULEB,
			       binding,
			       mo->bind[i].rel.r_انحراف + s->sh_addr);
        ptr = section_ptr_جوڑو(binding, 1);
        *ptr++ = BIND_OPCODE_DO_BIND;
    }
    اگر (mo->rebase->ڈیٹا_انحراف) {
        ptr = section_ptr_جوڑو(mo->rebase, 1);
        *ptr = REBASE_OPCODE_مکمل;
    }
    اگر (mo->binding->ڈیٹا_انحراف) {
        ptr = section_ptr_جوڑو(mo->binding, 1);
        *ptr = BIND_OPCODE_مکمل;
    }
    اگر (mo->weak_binding->ڈیٹا_انحراف) {
        ptr = section_ptr_جوڑو(mo->weak_binding, 1);
        *ptr = BIND_OPCODE_مکمل;
    }
    tcc_free(mo->s_lazy_bind);
    tcc_free(mo->s_rebase);
    tcc_free(mo->bind);
}
#اگر_ختم

ساخت trie_info {
    ثابت حرف *name;
    صحیح flag;
    addr_t addr;
    صحیح str_سائز;
    صحیح رکن_سائز;
};

ساخت trie_گرہ {
    صحیح آغاز;
    صحیح انتہا;
    صحیح اشاریہ_آغاز;
    صحیح اشاریہ_انتہا;
    صحیح n_بچہ;
    ساخت trie_گرہ *بچہ;
};

ساخت trie_seq {
    صحیح n_بچہ;
    ساخت trie_گرہ *گرہ;
    صحیح انحراف;
    صحیح nest_انحراف;
};

ساکن خالی create_trie(ساخت trie_گرہ *گرہ,
                        صحیح from, صحیح مقصد, صحیح اشاریہ_آغاز,
                        صحیح n_trie, ساخت trie_info *trie)
{
    صحیح i;
    صحیح آغاز, انتہا, اشاریہ_انتہا;
    حرف cur;
    ساخت trie_گرہ *بچہ;

    برائے (i = from; i < مقصد; i = انتہا) {
        cur = trie[i].name[اشاریہ_آغاز];
        آغاز = i++;
        برائے (; i < مقصد; i++)
            اگر (cur != trie[i].name[اشاریہ_آغاز])
                توڑو;
        انتہا = i;
        اگر (آغاز == انتہا - 1 ||
            (trie[آغاز].name[اشاریہ_آغاز] &&
             trie[آغاز].name[اشاریہ_آغاز + 1] == 0))
            اشاریہ_انتہا = trie[آغاز].str_سائز - 1;
        ورنہ {
            اشاریہ_انتہا = اشاریہ_آغاز + 1;
            برائے (;;) {
                cur = trie[آغاز].name[اشاریہ_انتہا];
                برائے (i = آغاز + 1; i < انتہا; i++)
                    اگر (cur != trie[i].name[اشاریہ_انتہا])
                        توڑو;
                اگر (trie[آغاز].name[اشاریہ_انتہا] &&
                    trie[آغاز].name[اشاریہ_انتہا + 1] == 0) {
                    انتہا = آغاز + 1;
                    اشاریہ_انتہا = trie[آغاز].str_سائز - 1;
                    توڑو;
                }
                اگر (i != انتہا)
                    توڑو;
                اشاریہ_انتہا++;
            }
        }
        گرہ->بچہ = tcc_realloc(گرہ->بچہ,
                                  (گرہ->n_بچہ + 1) *
                                  حجم(ساخت trie_گرہ));
        بچہ = &گرہ->بچہ[گرہ->n_بچہ];
        بچہ->آغاز = آغاز;
        بچہ->انتہا = انتہا;
        بچہ->اشاریہ_آغاز = اشاریہ_آغاز;
        بچہ->اشاریہ_انتہا = اشاریہ_انتہا;
        بچہ->n_بچہ = 0;
        بچہ->بچہ = تہی;
        گرہ->n_بچہ++;
        اگر (آغاز != انتہا - 1)
            create_trie(بچہ, آغاز, انتہا, اشاریہ_انتہا, n_trie, trie);
    }
}

ساکن صحیح create_seq(صحیح *انحراف, صحیح *n_seq, ساخت trie_seq **seq,
                        ساخت trie_گرہ *گرہ,
                        صحیح n_trie, ساخت trie_info *trie)
{
    صحیح i, nest_انحراف, آخری_seq = *n_seq, retval = *انحراف;
    ساخت trie_seq *p_seq;
    ساخت trie_گرہ *p_nest;

    برائے (i = 0; i < گرہ->n_بچہ; i++) {
        p_nest = &گرہ->بچہ[i];
        *seq = tcc_realloc(*seq, (*n_seq + 1) * حجم(ساخت trie_seq));
        p_seq = &(*seq)[(*n_seq)++];
        p_seq->n_بچہ = i == 0 ? گرہ->n_بچہ : -1;
        p_seq->گرہ = p_nest;
        p_seq->انحراف = *انحراف;
        p_seq->nest_انحراف = 0;
        *انحراف += (i == 0 ? 1 + 1 : 0) +
                   p_nest->اشاریہ_انتہا - p_nest->اشاریہ_آغاز + 1 + 3;
    }
    برائے (i = 0; i < گرہ->n_بچہ; i++) {
        nest_انحراف =
            create_seq(انحراف, n_seq, seq, &گرہ->بچہ[i], n_trie, trie);
        p_seq = &(*seq)[آخری_seq + i];
        p_seq->nest_انحراف = nest_انحراف;
    }
    واپس retval;
}

ساکن خالی گرہ_free(ساخت trie_گرہ *گرہ)
{
    صحیح i;

    برائے (i = 0; i < گرہ->n_بچہ; i++)
	گرہ_free(&گرہ->بچہ[i]);
    tcc_free(گرہ->بچہ);
}

ساکن صحیح triecmp(ثابت خالی *_a, ثابت خالی *_b, خالی *arg)
{
    ساخت trie_info *a = (ساخت trie_info *) _a;
    ساخت trie_info *b = (ساخت trie_info *) _b;
    صحیح len_a = لڑی_لمبائی(a->name);
    صحیح len_b = لڑی_لمبائی(b->name);

    /* strange sorting needed. Name 'xx' should be after 'xx1' */
    اگر (!لڑی_موازنہ(a->name, b->name, len_a < len_b ? len_a : len_b))
	واپس len_a < len_b ? 1 : (len_a > len_b ? -1 : 0);
    واپس strcmp(a->name, b->name);
}

ساکن خالی export_trie(TCCState *s1, ساخت macho *mo)
{
    صحیح i, سائز, انحراف = 0, save_انحراف;
    uint8_t *ptr;
    صحیح sym_اشاریہ;
    صحیح sym_انتہا = symtab_section->ڈیٹا_انحراف / حجم(ElfW(Sym));
    صحیح n_trie = 0, n_seq = 0;
    ساخت trie_info *trie = تہی, *p_trie;
    ساخت trie_گرہ گرہ, *p_گرہ;
    ساخت trie_seq *seq = تہی;
    addr_t vm_addr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;

    برائے (sym_اشاریہ = 1; sym_اشاریہ < sym_انتہا; ++sym_اشاریہ) {
	ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->ڈیٹا + sym_اشاریہ;
	ثابت حرف *name = (حرف*)symtab_section->link->ڈیٹا + sym->st_name;

	اگر (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE &&
            (ELFW(ST_BIND)(sym->st_info) == STB_GLOBAL ||
	     ELFW(ST_BIND)(sym->st_info) == STB_WEAK)) {
	    صحیح flag = EXPORT_علامت_FLAGS_قسم_REGULAR;
	    addr_t addr =
		sym->st_قدر + s1->sections[sym->st_shndx]->sh_addr - vm_addr;

	    اگر (ELFW(ST_BIND)(sym->st_info) == STB_WEAK)
		flag |= EXPORT_علامت_FLAGS_WEAK_DEFINITION;
	    dprintf ("%s %d %llx\n", name, flag, (طویل طویل)addr + vm_addr);
	    trie = tcc_realloc(trie, (n_trie + 1) * حجم(ساخت trie_info));
	    trie[n_trie].name = name;
	    trie[n_trie].flag = flag;
	    trie[n_trie].addr = addr;
	    trie[n_trie].str_سائز = لڑی_لمبائی(name) + 1;
	    trie[n_trie].رکن_سائز = uleb128_سائز(flag) + uleb128_سائز(addr);
	    n_trie++;
	}
    }
    اگر (n_trie) {
        tcc_qsort(trie, n_trie, حجم(ساخت trie_info), triecmp, تہی);
	memset(&گرہ, 0, حجم(گرہ));
        create_trie(&گرہ, 0, n_trie, 0, n_trie, trie);
	create_seq(&انحراف, &n_seq, &seq, &گرہ, n_trie, trie);
        save_انحراف = انحراف;
        برائے (i = 0; i < n_seq; i++) {
            p_گرہ = seq[i].گرہ;
            اگر (p_گرہ->n_بچہ == 0) {
                p_trie = &trie[p_گرہ->آغاز];
                seq[i].nest_انحراف = انحراف;
                انحراف += 1 + p_trie->رکن_سائز + 1;
            }
        }
        برائے (i = 0; i < n_seq; i++) {
            p_گرہ = seq[i].گرہ;
            p_trie = &trie[p_گرہ->آغاز];
            اگر (seq[i].n_بچہ >= 0) {
                section_ptr_جوڑو(mo->exports,
				seq[i].انحراف - mo->exports->ڈیٹا_انحراف);
                ptr = section_ptr_جوڑو(mo->exports, 2);
                *ptr++ = 0;
                *ptr = seq[i].n_بچہ;
            }
            سائز = p_گرہ->اشاریہ_انتہا - p_گرہ->اشاریہ_آغاز;
            ptr = section_ptr_جوڑو(mo->exports, سائز + 1);
            حافظہ_نقل(ptr, &p_trie->name[p_گرہ->اشاریہ_آغاز], سائز);
            ptr[سائز] = 0;
            write_uleb128(mo->exports, seq[i].nest_انحراف);
        }
        section_ptr_جوڑو(mo->exports, save_انحراف - mo->exports->ڈیٹا_انحراف);
        برائے (i = 0; i < n_seq; i++) {
            p_گرہ = seq[i].گرہ;
            اگر (p_گرہ->n_بچہ == 0) {
                p_trie = &trie[p_گرہ->آغاز];
                write_uleb128(mo->exports, p_trie->رکن_سائز);
                write_uleb128(mo->exports, p_trie->flag);
                write_uleb128(mo->exports, p_trie->addr);
                ptr = section_ptr_جوڑو(mo->exports, 1);
                *ptr = 0;
            }
        }
        section_ptr_جوڑو(mo->exports, -mo->exports->ڈیٹا_انحراف & 7);
	گرہ_free(&گرہ);
        tcc_free(seq);
    }
    tcc_free(trie);
}

ساکن خالی collect_sections(TCCState *s1, ساخت macho *mo, ثابت حرف *filename)
{
    صحیح i, sk, numsec;
    صحیح مستعمل_segment[N_SEGMENT];
    uint64_t curaddr, fileofs;
    Section *s;
    ساخت segment_command_64 *seg;
    ساخت dylib_command *dylib;
#اگر_تعریف_شدہ CONFIG_NEW_MACHO
    ساخت linkedit_ڈیٹا_command *chained_fixups_lc;
    ساخت linkedit_ڈیٹا_command *export_trie_lc;
#اگر_ختم
    ساخت build_نسخہ_command *dyldbv;
    ساخت ماخذ_نسخہ_command *dyldsv;
    ساخت rpath_command *rpath;
    ساخت dylinker_command *dyldlc;
    ساخت symtab_command *symlc;
    ساخت dysymtab_command *dysymlc;
    حرف *str;

    برائے (i = 0; i < N_SEGMENT; i++)
	مستعمل_segment[i] = all_segment[i].مستعمل;

    memset (mo->sk_مقصد_sect, 0, حجم(mo->sk_مقصد_sect));
    برائے (i = s1->nb_sections; i-- > 1;) {
        صحیح type, flags;
        s = s1->sections[i];
        type = s->sh_type;
        flags = s->sh_flags;
        sk = sk_unknown;
	/* debug sections have sometimes no SHF_ALLOC */
        اگر ((flags & SHF_ALLOC) || !لڑی_موازنہ(s->name, ".debug_", 7)) {
            انتخاب (type) {
            طےشدہ:           sk = sk_unknown; توڑو;
            حالت SHT_INIT_ARRAY: sk = sk_init; توڑو;
            حالت SHT_FINI_ARRAY: sk = sk_fini; توڑو;
            حالت SHT_NOBITS:   sk = sk_bss; توڑو;
            حالت SHT_SYMTAB:   sk = sk_discard; توڑو;
            حالت SHT_STRTAB:
		اگر (s == stabstr_section)
		  sk = sk_stab_str;
		ورنہ
		  sk = sk_discard;
		توڑو;
            حالت SHT_RELX:     sk = sk_discard; توڑو;
            حالت SHT_LINKEDIT: sk = sk_linkedit; توڑو;
            حالت SHT_PROGBITS:
                اگر (s == mo->stubs)
                  sk = sk_stubs;
#اگر_غیر_تعریف_شدہ CONFIG_NEW_MACHO
                ورنہ اگر (s == mo->stub_helper)
                  sk = sk_stub_helper;
                ورنہ اگر (s == mo->la_علامت_ptr)
                  sk = sk_la_ptr;
#اگر_ختم
                ورنہ اگر (s == rodata_section)
                  sk = sk_ro_ڈیٹا;
                ورنہ اگر (s == s1->got)
                  sk = sk_nl_ptr;
                ورنہ اگر (s == stab_section)
                  sk = sk_stab;
                ورنہ اگر (s == dwarf_info_section)
                  sk = sk_debug_info;
                ورنہ اگر (s == dwarf_abbrev_section)
                  sk = sk_debug_abbrev;
                ورنہ اگر (s == dwarf_سطر_section)
                  sk = sk_debug_سطر;
                ورنہ اگر (s == dwarf_aranges_section)
                  sk = sk_debug_aranges;
                ورنہ اگر (s == dwarf_str_section)
                  sk = sk_debug_str;
                ورنہ اگر (s == dwarf_سطر_str_section)
                  sk = sk_debug_سطر_str;
                ورنہ اگر (flags & SHF_EXECINSTR)
                  sk = sk_متن;
                ورنہ اگر (flags & SHF_WRITE)
                  sk = sk_rw_ڈیٹا;
                ورنہ
                  sk = sk_ro_ڈیٹا;
                توڑو;
            }
        } ورنہ
          sk = sk_discard;
        s->پچھلا = mo->sk_مقصد_sect[sk].s;
        mo->sk_مقصد_sect[sk].s = s;
	مستعمل_segment[skinfo[sk].seg_initial] = 1;
    }

    اگر (s1->output_type != TCC_OUTPUT_EXE)
	مستعمل_segment[0] = 0;

    برائے (i = 0; i < N_SEGMENT; i++)
	اگر (مستعمل_segment[i]) {
	    seg = جوڑو_segment(mo, all_segment[i].name);
	    اگر (i == 1 && s1->output_type != TCC_OUTPUT_EXE)
	        seg->vmaddr = 0;
	    ورنہ
	        seg->vmaddr = all_segment[i].vmaddr;
	    seg->vmsize = all_segment[i].vmsize;
	    seg->maxprot = all_segment[i].maxprot;
	    seg->initprot = all_segment[i].initprot;
	    seg->flags = all_segment[i].flags;
            برائے (sk = sk_unknown; sk < sk_آخری; sk++)
		اگر (skinfo[sk].seg_initial == i)
	            mo->segment[sk] = mo->nseg - 1;
	}

    اگر (s1->output_type != TCC_OUTPUT_EXE) {
	ثابت حرف *name = s1->install_name ? s1->install_name : filename;
        i = (حجم(*dylib) + لڑی_لمبائی(name) + 1 + 7) &-8;
        dylib = جوڑو_lc(mo, LC_ID_DYLIB, i);
	dylib->name = حجم(*dylib);
	dylib->timestamp = 1;
	dylib->current_نسخہ =
	    s1->current_نسخہ ? s1->current_نسخہ : 1 << 16;
	dylib->compatibility_نسخہ =
	    s1->compatibility_نسخہ ? s1->compatibility_نسخہ : 1 << 16;
        str = (حرف*)dylib + dylib->name;
        strcpy(str, name);
    }

#اگر_تعریف_شدہ CONFIG_NEW_MACHO
    chained_fixups_lc = جوڑو_lc(mo, LC_DYLD_CHAINED_FIXUPS,
			       حجم(ساخت linkedit_ڈیٹا_command));
    export_trie_lc = جوڑو_lc(mo, LC_DYLD_EXPORTS_TRIE,
			    حجم(ساخت linkedit_ڈیٹا_command));
#ورنہ
    mo->dyldinfo = جوڑو_lc(mo, LC_DYLD_INFO_ONLY, حجم(*mo->dyldinfo));
#اگر_ختم

    symlc = جوڑو_lc(mo, LC_SYMTAB, حجم(*symlc));
    dysymlc = جوڑو_lc(mo, LC_DYSYMTAB, حجم(*dysymlc));

    اگر (s1->output_type == TCC_OUTPUT_EXE) {
        i = (حجم(*dyldlc) + لڑی_لمبائی("/usr/lib/dyld") + 1 + 7) &-8;
        dyldlc = جوڑو_lc(mo, LC_بھرو_DYLINKER, i);
        dyldlc->name = حجم(*dyldlc);
        str = (حرف*)dyldlc + dyldlc->name;
        strcpy(str, "/usr/lib/dyld");
    }

    dyldbv = جوڑو_lc(mo, LC_BUILD_نسخہ, حجم(*dyldbv));
    dyldbv->platform = PLATFORM_MACOS;
    dyldbv->minos = (10 << 16) + (6 << 8);
    dyldbv->sdk = (10 << 16) + (6 << 8);
    dyldbv->ntools = 0;

    dyldsv = جوڑو_lc(mo, LC_ماخذ_نسخہ, حجم(*dyldsv));
    dyldsv->نسخہ = 0;

    اگر (s1->output_type == TCC_OUTPUT_EXE) {
        mo->ep = جوڑو_lc(mo, LC_MAIN, حجم(*mo->ep));
        mo->ep->entryoff = 4096;
    }

    برائے(i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *dllref = s1->loaded_dlls[i];
        اگر (dllref->level == 0)
          جوڑو_dylib(mo, dllref->name);
    }

    اگر (s1->rpath) {
	حرف *راستہ = s1->rpath, *انتہا;
	کرو {
	    انتہا = strchr(راستہ, ':');
	    اگر (!انتہا)
		انتہا = strchr(راستہ, 0);
            i = (حجم(*rpath) + (انتہا - راستہ) + 1 + 7) &-8;
            rpath = جوڑو_lc(mo, LC_RPATH, i);
            rpath->راستہ = حجم(*rpath);
            str = (حرف*)rpath + rpath->راستہ;
            حافظہ_نقل(str, راستہ, انتہا - راستہ);
	    str[انتہا - راستہ] = 0;
	    راستہ = انتہا + 1;
	} جب (*انتہا);
    }

    fileofs = 4096;  /* leave space for mach-o headers */
    curaddr = get_segment(mo, s1->output_type == TCC_OUTPUT_EXE)->vmaddr;
    curaddr += 4096;
    seg = تہی;
    numsec = 0;
    mo->elfsectomacho = tcc_mallocz(حجم(*mo->elfsectomacho) * s1->nb_sections);
    برائے (sk = sk_unknown; sk < sk_آخری; sk++) {
        ساخت section_64 *sec = تہی;
        اگر (seg) {
            seg->vmsize = curaddr - seg->vmaddr;
            seg->filesize = fileofs - seg->fileoff;
        }
#اگر_تعریف_شدہ CONFIG_NEW_MACHO
	اگر (sk == sk_linkedit) {
	    calc_fixup_سائز(s1, mo);
	    export_trie(s1, mo);
	}
#ورنہ
	اگر (sk == sk_linkedit) {
	    bind_rebase(s1, mo);
	    export_trie(s1, mo);
	}
#اگر_ختم
        اگر (skinfo[sk].seg_initial &&
	    (s1->output_type != TCC_OUTPUT_EXE || mo->segment[sk]) &&
	    mo->sk_مقصد_sect[sk].s) {
            uint64_t al = 0;
            صحیح si;
            seg = get_segment(mo, mo->segment[sk]);
            اگر (skinfo[sk].name) {
                si = جوڑو_section(mo, &seg, skinfo[sk].name);
                numsec++;
                mo->lc[mo->seg2lc[mo->segment[sk]]] = (ساخت بھرو_command*)seg;
                mo->sk_مقصد_sect[sk].machosect = si;
                sec = get_section(seg, si);
                sec->flags = skinfo[sk].flags;
		اگر (sk == sk_stubs)
#اگر_تعریف_شدہ TCC_ہدف_X86_64
	    	    sec->reserved2 = 6;
#وگرنہ_اگر defined TCC_ہدف_ARM64
	    	    sec->reserved2 = 12;
#اگر_ختم
		اگر (sk == sk_nl_ptr)
	    	    sec->reserved1 = mo->nr_plt;
#اگر_غیر_تعریف_شدہ CONFIG_NEW_MACHO
		اگر (sk == sk_la_ptr)
	    	    sec->reserved1 = mo->nr_plt + mo->n_got;
#اگر_ختم
            }
            اگر (seg->vmaddr == -1) {
                curaddr = (curaddr + SEG_صفحہ_سائز - 1) & -SEG_صفحہ_سائز;
                seg->vmaddr = curaddr;
                fileofs = (fileofs + SEG_صفحہ_سائز - 1) & -SEG_صفحہ_سائز;
                seg->fileoff = fileofs;
            }

            برائے (s = mo->sk_مقصد_sect[sk].s; s; s = s->پچھلا) {
                صحیح a = exact_log2p1(s->sh_addralign);
                اگر (a && al < (a - 1))
                  al = a - 1;
                s->sh_سائز = s->ڈیٹا_انحراف;
            }
            اگر (sec)
              sec->align = al;
            al = 1ULL << al;
            اگر (al > 4096)
              tcc_warning("alignment > 4096"), sec->align = 12, al = 4096;
            curaddr = (curaddr + al - 1) & -al;
            fileofs = (fileofs + al - 1) & -al;
            اگر (sec) {
                sec->addr = curaddr;
                sec->انحراف = fileofs;
            }
            برائے (s = mo->sk_مقصد_sect[sk].s; s; s = s->پچھلا) {
                al = s->sh_addralign;
                curaddr = (curaddr + al - 1) & -al;
                dprintf("%s: curaddr now 0x%lx\n", s->name, (طویل)curaddr);
                s->sh_addr = curaddr;
                curaddr += s->sh_سائز;
                اگر (s->sh_type != SHT_NOBITS) {
                    fileofs = (fileofs + al - 1) & -al;
                    s->sh_انحراف = fileofs;
                    fileofs += s->sh_سائز;
                    dprintf("%s: fileofs now %ld\n", s->name, (طویل)fileofs);
                }
                اگر (sec)
                  mo->elfsectomacho[s->sh_عدد] = numsec;
            }
            اگر (sec)
              sec->سائز = curaddr - sec->addr;
        }
        اگر (DEBUG_MACHO)
          برائے (s = mo->sk_مقصد_sect[sk].s; s; s = s->پچھلا) {
              صحیح type = s->sh_type;
              صحیح flags = s->sh_flags;
              لکھو("%d section %-16s %-10s %09lx %04x %02d %s,%s,%s\n",
                     sk,
                     s->name,
                     type == SHT_PROGBITS ? "progbits" :
                     type == SHT_NOBITS ? "nobits" :
                     type == SHT_SYMTAB ? "symtab" :
                     type == SHT_STRTAB ? "strtab" :
                     type == SHT_INIT_ARRAY ? "init" :
                     type == SHT_FINI_ARRAY ? "fini" :
                     type == SHT_RELX ? "rel" : "???",
                     (طویل)s->sh_addr,
                     (غیرعلامتی)s->ڈیٹا_انحراف,
                     s->sh_addralign,
                     flags & SHF_ALLOC ? "alloc" : "",
                     flags & SHF_WRITE ? "write" : "",
                     flags & SHF_EXECINSTR ? "exec" : ""
                    );
          }
    }
    اگر (seg) {
        seg->vmsize = curaddr - seg->vmaddr;
        seg->filesize = fileofs - seg->fileoff;
    }

    /* Fill symtab info */
    symlc->symoff = mo->symtab->sh_انحراف;
    symlc->nsyms = mo->symtab->ڈیٹا_انحراف / حجم(ساخت nlist_64);
    symlc->stroff = mo->strtab->sh_انحراف;
    symlc->strsize = mo->strtab->ڈیٹا_انحراف;

    dysymlc->iundefsym = mo->iundef == -1 ? symlc->nsyms : mo->iundef;
    dysymlc->iextdefsym = mo->iextdef == -1 ? dysymlc->iundefsym : mo->iextdef;
    dysymlc->ilocalsym = mo->ilocal == -1 ? dysymlc->iextdefsym : mo->ilocal;
    dysymlc->nlocalsym = dysymlc->iextdefsym - dysymlc->ilocalsym;
    dysymlc->nextdefsym = dysymlc->iundefsym - dysymlc->iextdefsym;
    dysymlc->nundefsym = symlc->nsyms - dysymlc->iundefsym;
    dysymlc->indirectsymoff = mo->indirsyms->sh_انحراف;
    dysymlc->nindirectsyms = mo->indirsyms->ڈیٹا_انحراف / حجم(uint32_t);

#اگر_تعریف_شدہ CONFIG_NEW_MACHO
    اگر (mo->chained_fixups->ڈیٹا_انحراف) {
        chained_fixups_lc->dataoff = mo->chained_fixups->sh_انحراف;
        chained_fixups_lc->datasize = mo->chained_fixups->ڈیٹا_انحراف;
    }
    اگر (mo->exports->ڈیٹا_انحراف) {
        export_trie_lc->dataoff = mo->exports->sh_انحراف;
        export_trie_lc->datasize = mo->exports->ڈیٹا_انحراف;
    }
#ورنہ
    اگر (mo->rebase->ڈیٹا_انحراف) {
        mo->dyldinfo->rebase_off = mo->rebase->sh_انحراف;
        mo->dyldinfo->rebase_سائز = mo->rebase->ڈیٹا_انحراف;
    }
    اگر (mo->binding->ڈیٹا_انحراف) {
        mo->dyldinfo->bind_off = mo->binding->sh_انحراف;
        mo->dyldinfo->bind_سائز = mo->binding->ڈیٹا_انحراف;
    }
    اگر (mo->weak_binding->ڈیٹا_انحراف) {
        mo->dyldinfo->weak_bind_off = mo->weak_binding->sh_انحراف;
        mo->dyldinfo->weak_bind_سائز = mo->weak_binding->ڈیٹا_انحراف;
    }
    اگر (mo->lazy_binding->ڈیٹا_انحراف) {
        mo->dyldinfo->lazy_bind_off = mo->lazy_binding->sh_انحراف;
        mo->dyldinfo->lazy_bind_سائز = mo->lazy_binding->ڈیٹا_انحراف;
    }
    اگر (mo->exports->ڈیٹا_انحراف) {
        mo->dyldinfo->export_off = mo->exports->sh_انحراف;
        mo->dyldinfo->export_سائز = mo->exports->ڈیٹا_انحراف;
    }
#اگر_ختم
}

ساکن خالی macho_write(TCCState *s1, ساخت macho *mo, FILE *fp)
{
    صحیح i, sk;
    uint64_t fileofs = 0;
    Section *s;
    mo->mh.mh.magic = MH_MAGIC_64;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    mo->mh.mh.cputype = CPU_TYPE_X86_64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_LIB64 | CPU_SUBTYPE_X86_ALL;
#وگرنہ_اگر defined TCC_ہدف_ARM64
    mo->mh.mh.cputype = CPU_TYPE_ARM64;
    mo->mh.mh.cpusubtype = CPU_SUBTYPE_ARM64_ALL;
#اگر_ختم
    اگر (s1->output_type == TCC_OUTPUT_EXE) {
        mo->mh.mh.filetype = MH_EXECUTE;
        mo->mh.mh.flags = MH_DYLDLINK | MH_PIE;
    }
    ورنہ {
        mo->mh.mh.filetype = MH_DYLIB;
        mo->mh.mh.flags = MH_DYLDLINK;
    }
    mo->mh.mh.ncmds = mo->nlc;
    mo->mh.mh.sizeofcmds = 0;
    برائے (i = 0; i < mo->nlc; i++)
      mo->mh.mh.sizeofcmds += mo->lc[i]->cmdsize;

    fwrite(&mo->mh, 1, حجم(mo->mh), fp);
    fileofs += حجم(mo->mh);
    برائے (i = 0; i < mo->nlc; i++) {
        fwrite(mo->lc[i], 1, mo->lc[i]->cmdsize, fp);
        fileofs += mo->lc[i]->cmdsize;
    }

    برائے (sk = sk_unknown; sk < sk_آخری; sk++) {
        //struct segment_command_64 *seg;
        اگر (skinfo[sk].seg_initial == 0 ||
	    (s1->output_type == TCC_OUTPUT_EXE && !mo->segment[sk]) ||
	    !mo->sk_مقصد_sect[sk].s)
          جاری;
        /*seg =*/ get_segment(mo, mo->segment[sk]);
        برائے (s = mo->sk_مقصد_sect[sk].s; s; s = s->پچھلا) {
            اگر (s->sh_type != SHT_NOBITS) {
                جب (fileofs < s->sh_انحراف)
                  fputc(0, fp), fileofs++;
                اگر (s->sh_سائز) {
                    fwrite(s->ڈیٹا, 1, s->sh_سائز, fp);
                    fileofs += s->sh_سائز;
                }
            }
        }
    }
}

#اگر_تعریف_شدہ CONFIG_NEW_MACHO
ساکن صحیح bind_rebase_cmp(ثابت خالی *_a, ثابت خالی *_b, خالی *arg)
{
    TCCState *s1 = arg;
    ساخت bind_rebase *a = (ساخت bind_rebase *) _a;
    ساخت bind_rebase *b = (ساخت bind_rebase *) _b;
    addr_t aa = s1->sections[a->section]->sh_addr + a->rel.r_انحراف;
    addr_t ab = s1->sections[b->section]->sh_addr + b->rel.r_انحراف;

    واپس aa > ab ? 1 : aa < ab ? -1 : 0;
}

ST_FUNC خالی bind_rebase_import(TCCState *s1, ساخت macho *mo)
{
    صحیح i, j, k, bind_اشاریہ, سائز, صفحہ_گنتی, sym_اشاریہ;
    ثابت حرف *name;
    ElfW(Sym) *sym;
    غیرعلامتی حرف *ڈیٹا = mo->chained_fixups->ڈیٹا;
    ساخت segment_command_64 *seg;
    ساخت dyld_chained_fixups_سرخی *سرخی;
    ساخت dyld_chained_starts_اندر_image *image;
    ساخت dyld_chained_starts_اندر_segment *segment;
    ساخت dyld_chained_import *import;

    tcc_qsort(mo->bind_rebase, mo->n_bind_rebase, حجم(ساخت bind_rebase),
	      bind_rebase_cmp, s1);
    برائے (i = 0; i < mo->n_bind_rebase - 1; i++)
	اگر (mo->bind_rebase[i].section == mo->bind_rebase[i + 1].section &&
	    mo->bind_rebase[i].rel.r_انحراف == mo->bind_rebase[i + 1].rel.r_انحراف) {
	    sym_اشاریہ = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
            sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
	    name = (حرف *) symtab_section->link->ڈیٹا + sym->st_name;
	    tcc_error("Overlap %s/%s %s:%s",
		      mo->bind_rebase[i].bind ? "bind" : "rebase",
		      mo->bind_rebase[i + 1].bind ? "bind" : "rebase",
		      s1->sections[mo->bind_rebase[i].section]->name, name);
	}
    سرخی = (ساخت dyld_chained_fixups_سرخی *) ڈیٹا;
    ڈیٹا += (حجم(ساخت dyld_chained_fixups_سرخی) + 7) & -8;
    سرخی->starts_انحراف = ڈیٹا - mo->chained_fixups->ڈیٹا;
    سرخی->imports_گنتی = mo->n_bind;
    سرخی->imports_format = DYLD_CHAINED_IMPORT;
    سرخی->symbols_format = 0;
    سائز = حجم(ساخت dyld_chained_starts_اندر_image) +
	   (mo->nseg - 1) * حجم(uint32_t);
    image = (ساخت dyld_chained_starts_اندر_image *) ڈیٹا;
    ڈیٹا += (سائز + 7) & -8;
    image->seg_گنتی = mo->nseg;
    برائے (i = (s1->output_type == TCC_OUTPUT_EXE); i < mo->nseg - 1; i++) {
        image->seg_info_انحراف[i] = (ڈیٹا - mo->chained_fixups->ڈیٹا) -
				    سرخی->starts_انحراف;
	seg = get_segment(mo, i);
	صفحہ_گنتی = (seg->vmsize + SEG_صفحہ_سائز - 1) / SEG_صفحہ_سائز;
	سائز = حجم(ساخت dyld_chained_starts_اندر_segment) +
		      (صفحہ_گنتی - 1) * حجم(uint16_t);
        segment = (ساخت dyld_chained_starts_اندر_segment *) ڈیٹا;
        ڈیٹا += (سائز + 7) & -8;
        segment->سائز = سائز;
        segment->صفحہ_سائز = SEG_صفحہ_سائز;
#اگر 1
#تعریف_کرو	PTR_64_انحراف 0
#تعریف_کرو	PTR_64_نقاب   0x7FFFFFFFFFFULL
        segment->اشارہ_گر_format = DYLD_CHAINED_PTR_64;
#ورنہ
#تعریف_کرو	PTR_64_انحراف 0x100000000ULL
#تعریف_کرو	PTR_64_نقاب   0xFFFFFFFFFFFFFFULL
        segment->اشارہ_گر_format = DYLD_CHAINED_PTR_64_انحراف;
#اگر_ختم
        segment->segment_انحراف = seg->fileoff;
        segment->max_valid_اشارہ_گر = 0;
        segment->صفحہ_گنتی = صفحہ_گنتی;
	// add bind/rebase
	bind_اشاریہ = 0;
	k = 0;
	برائے (j = 0; j < صفحہ_گنتی; j++) {
	    addr_t آغاز = seg->vmaddr + j * SEG_صفحہ_سائز;
	    addr_t انتہا = آغاز + SEG_صفحہ_سائز;
	    خالی *آخری = تہی;
	    addr_t آخری_o = 0;
	    addr_t cur_o, cur;
	    ساخت dyld_chained_ptr_64_rebase *rebase;
	    ساخت dyld_chained_ptr_64_bind *bind;

	    segment->صفحہ_آغاز[j] = DYLD_CHAINED_PTR_آغاز_NONE;
	    برائے (; k < mo->n_bind_rebase; k++) {
	        Section *s = s1->sections[mo->bind_rebase[k].section];
		addr_t r_انحراف = mo->bind_rebase[k].rel.r_انحراف;
		addr_t addr = s->sh_addr + r_انحراف;

		اگر ((addr & 3) ||
		    (addr & (SEG_صفحہ_سائز - 1)) > SEG_صفحہ_سائز - PTR_سائز)
		    tcc_error("Illegal rel_offset %s %lld",
			      s->name, (طویل طویل)r_انحراف);
		اگر (addr >= انتہا)
		    توڑو;
		اگر (addr >= آغاز) {
		    cur_o = addr - آغاز;
	            اگر (mo->bind_rebase[k].bind) {
		        اگر (segment->صفحہ_آغاز[j] == DYLD_CHAINED_PTR_آغاز_NONE)
			    segment->صفحہ_آغاز[j] = cur_o;
		        ورنہ {
			    bind = (ساخت dyld_chained_ptr_64_bind *) آخری;
			    bind->اگلا = (cur_o - آخری_o) / 4;
		        }
		        bind = (ساخت dyld_chained_ptr_64_bind *)
				    (s->ڈیٹا + r_انحراف);
		        آخری = bind;
		        آخری_o = cur_o;
		        bind->ordinal = bind_اشاریہ;
		        bind->addend = 0;
		        bind->reserved = 0;
		        bind->اگلا = 0;
		        bind->bind = 1;
		    }
		    ورنہ {
		        اگر (segment->صفحہ_آغاز[j] == DYLD_CHAINED_PTR_آغاز_NONE)
			    segment->صفحہ_آغاز[j] = cur_o;
		        ورنہ {
			    rebase = (ساخت dyld_chained_ptr_64_rebase *) آخری;
			    rebase->اگلا = (cur_o - آخری_o) / 4;
		        }
		        rebase = (ساخت dyld_chained_ptr_64_rebase *)
				    (s->ڈیٹا + r_انحراف);
		        آخری = rebase;
		        آخری_o = cur_o;
		        cur = (*(uint64_t *) (s->ڈیٹا + r_انحراف)) -
			      PTR_64_انحراف;
		        rebase->ہدف = cur & PTR_64_نقاب;
		        rebase->high8 = cur >> (64 - 8);
			اگر (cur != ((uint64_t)rebase->high8 << (64 - 8)) + rebase->ہدف)
			    tcc_error("rebase error");
		        rebase->reserved = 0;
		        rebase->اگلا = 0;
		        rebase->bind = 0;
		    }
		}
		bind_اشاریہ += mo->bind_rebase[k].bind;
	    }
	}
    }
    // add imports
    سرخی->imports_انحراف = ڈیٹا - mo->chained_fixups->ڈیٹا;
    import = (ساخت dyld_chained_import *) ڈیٹا;
    ڈیٹا += mo->n_bind * حجم (ساخت dyld_chained_import);
    سرخی->symbols_انحراف = ڈیٹا - mo->chained_fixups->ڈیٹا;
    ڈیٹا++;
    برائے (i = 0, bind_اشاریہ = 0; i < mo->n_bind_rebase; i++) {
	اگر (mo->bind_rebase[i].bind) {
	    import[bind_اشاریہ].lib_ordinal =
		BIND_SPECIAL_DYLIB_FLAT_LOOKUP & 0xffu;
	    import[bind_اشاریہ].name_انحراف =
		(ڈیٹا - mo->chained_fixups->ڈیٹا) - سرخی->symbols_انحراف;
	    sym_اشاریہ = ELFW(R_SYM)(mo->bind_rebase[i].rel.r_info);
	    sym = &((ElfW(Sym) *)symtab_section->ڈیٹا)[sym_اشاریہ];
	    import[bind_اشاریہ].weak_import =
		ELFW(ST_BIND)(sym->st_info) == STB_WEAK;
	    name = (حرف *) symtab_section->link->ڈیٹا + sym->st_name;
            strcpy((حرف *) ڈیٹا, name);
	    ڈیٹا += لڑی_لمبائی(name) + 1;
	    bind_اشاریہ++;
	}
    }
    tcc_free(mo->bind_rebase);
}
#اگر_ختم

ST_FUNC صحیح macho_output_file(TCCState *s1, ثابت حرف *filename)
{
    صحیح fd, منوال, file_type;
    FILE *fp;
    صحیح i, ret = -1;
    ساخت macho mo;

    (خالی)memset(&mo, 0, حجم(mo));

    file_type = s1->output_type;
    اگر (file_type == TCC_OUTPUT_OBJ)
        منوال = 0666;
    ورنہ
        منوال = 0777;
    unlink(filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_ثنائی_2, منوال);
    اگر (fd < 0 || (fp = fdopen(fd, "wb")) == تہی) {
        tcc_error_noabort("could not write '%s: %s'", filename, strerror(errno));
        واپس -1;
    }
    tcc_جوڑو_runtime(s1);
    tcc_macho_جوڑو_destructor(s1);
    resolve_common_syms(s1);
    create_symtab(s1, &mo);
    check_relocs(s1, &mo);
    ret = check_symbols(s1, &mo);
    اگر (!ret) {
	صحیح save_output = s1->output_type;

        collect_sections(s1, &mo, filename);
        relocate_syms(s1, s1->symtab, 0);
	اگر (s1->output_type == TCC_OUTPUT_EXE)
            mo.ep->entryoff = get_sym_addr(s1, "main", 1, 1)
                            -     get_segment(&mo, 1)->vmaddr;
        اگر (s1->nb_errors)
          جاؤ do_ret;
	// Macho uses bind/rebase instead of dynsym
	s1->output_type = TCC_OUTPUT_EXE;
        relocate_sections(s1);
	s1->output_type = save_output;
#اگر_تعریف_شدہ CONFIG_NEW_MACHO
	bind_rebase_import(s1, &mo);
#اگر_ختم
        convert_symbols(s1, &mo);
        اگر (s1->verbose)
            لکھو("<- %s\n", filename);
        macho_write(s1, &mo, fp);
    }

 do_ret:
    برائے (i = 0; i < mo.nlc; i++)
      tcc_free(mo.lc[i]);
    tcc_free(mo.seg2lc);
    tcc_free(mo.lc);
    tcc_free(mo.elfsectomacho);
    tcc_free(mo.e2msym);

    fclose(fp);
#اگر_تعریف_شدہ CONFIG_CODESIGN
    اگر (!ret) {
	حرف command[1024];
	صحیح retval;

	snprintf(command, حجم(command), "codesign -f -s - %s", filename);
	retval = system (command);
	اگر (retval == -1 || !(WIFEXITED(retval) && WEXITSTATUS(retval) == 0))
	    tcc_error ("command failed '%s'", command);
    }
#اگر_ختم
    واپس ret;
}

ساکن uint32_t macho_swap32(uint32_t x)
{
  واپس (x >> 24) | (x << 24) | ((x >> 8) & 0xff00) | ((x & 0xff00) << 8);
}
#تعریف_کرو تبادلہ(x) (تبادلہ_2 ? macho_swap32(x) : (x))
#تعریف_کرو tbd_parse_movepast(s) \
    (pos = (pos = لڑی_تلاش(pos, s)) ? pos + لڑی_لمبائی(s) : تہی)
#تعریف_کرو tbd_parse_movetoany(cs) (pos = strpbrk(pos, cs))
#تعریف_کرو tbd_parse_skipws جب (*pos && (*pos==' '||*pos=='\n')) ++pos
#تعریف_کرو tbd_parse_tramplequote اگر(*pos=='\''||*pos=='"') tbd_parse_trample
#تعریف_کرو tbd_parse_tramplespace اگر(*pos==' ') tbd_parse_trample
#تعریف_کرو tbd_parse_trample *pos++=0

#اگر_تعریف_شدہ TCC_IS_NATIVE
/* Looks for the active developer SDK set by xcode-select (or the default
   one set during installation.) */
ST_FUNC خالی tcc_جوڑو_macos_sdkpath(TCCState* s)
{
    حرف *sdkroot = تہی, *pos = تہی;
    خالی* xcs = dlopen("libxcselect.dylib", RTLD_GLOBAL | RTLD_LAZY);
    CString راستہ;
    صحیح (*f)(غیرعلامتی صحیح, حرف**) = dlsym(xcs, "xcselect_host_sdk_path");
    cstr_new(&راستہ);
    اگر (f) f(1, &sdkroot);
    اگر (sdkroot)
        pos = لڑی_تلاش(sdkroot,"SDKs/MacOSX");
    اگر (pos)
        cstr_printf(&راستہ, "%.*s.sdk/usr/lib", (صحیح)(pos - sdkroot + 11), sdkroot);
    /* must use free from libc directly */
#ہدایت ڈالو_macro("free")
#تعریف_منسوخ آزاد
    آزاد(sdkroot);
#ہدایت نکالو_macro("free")
    اگر (راستہ.سائز)
        tcc_جوڑو_library_راستہ(s, (حرف*)راستہ.ڈیٹا);
    ورنہ
        tcc_جوڑو_library_راستہ(s,
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib"
            ":" "/Applications/Xcode.app/Developer/SDKs/MacOSX.sdk/usr/lib"
            );
    cstr_free(&راستہ);
}

ST_FUNC حرف* macho_tbd_soname(صحیح fd) {
    حرف *soname, *ڈیٹا, *pos;
    حرف *ret = 0;
    pos = ڈیٹا = tcc_بھرو_متن(fd);
    اگر (!tbd_parse_movepast("install-name: ")) جاؤ the_انتہا;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    اگر (!tbd_parse_movetoany("\n \"'")) جاؤ the_انتہا;
    tbd_parse_trample;
    ret = tcc_strdup(soname);
the_انتہا:
    tcc_free(ڈیٹا);
    واپس ret;
}
#اگر_ختم /* TCC_IS_NATIVE */

ST_FUNC صحیح macho_بھرو_tbd(TCCState* s1, صحیح fd, ثابت حرف* filename, صحیح lev)
{
    حرف *soname, *ڈیٹا, *pos;
    صحیح ret = -1;

    pos = ڈیٹا = tcc_بھرو_متن(fd);
    اگر (!tbd_parse_movepast("install-name: ")) جاؤ the_انتہا;
    tbd_parse_skipws;
    tbd_parse_tramplequote;
    soname = pos;
    اگر (!tbd_parse_movetoany("\n \"'")) جاؤ the_انتہا;
    tbd_parse_trample;
    ret = 0;
    اگر (tcc_جوڑو_dllref(s1, soname, lev)->ملا)
        جاؤ the_انتہا;
    جب(pos) {
        حرف* sym = تہی;
        صحیح cont = 1;
        اگر (!tbd_parse_movepast("symbols: ")) توڑو;
        اگر (!tbd_parse_movepast("[")) توڑو;
        جب (cont) {
            tbd_parse_skipws;
            tbd_parse_tramplequote;
            sym = pos;
            اگر (!tbd_parse_movetoany(",] \"'")) توڑو;
            tbd_parse_tramplequote;
            tbd_parse_tramplespace;
            tbd_parse_skipws;
            اگر (*pos==0||*pos==']') cont=0;
            tbd_parse_trample;
            سیٹ_elf_sym(s1->dynsymtab_section, 0, 0,
                ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0, SHN_UNDEF, sym);
        }
    }

the_انتہا:
    tcc_free(ڈیٹا);
    واپس ret;
}

ST_FUNC صحیح macho_بھرو_dll(TCCState * s1, صحیح fd, ثابت حرف* filename, صحیح lev)
{
    غیرعلامتی حرف buf[حجم(ساخت mach_سرخی_64)];
    خالی *buf2;
    uint32_t machofs = 0;
    ساخت fat_سرخی fh;
    ساخت mach_سرخی mh;
    ساخت بھرو_command *lc;
    صحیح i, تبادلہ_2 = 0;
    ثابت حرف *soname = filename;
    ساخت nlist_64 *symtab = 0;
    uint32_t nsyms = 0;
    حرف *strtab = 0;
    uint32_t strsize = 0;
    uint32_t iextdef = 0;
    uint32_t nextdef = 0;

  again:
    اگر (بھرا_read(fd, buf, حجم(buf)) != حجم(buf))
      واپس -1;
    حافظہ_نقل(&fh, buf, حجم(fh));
    اگر (fh.magic == FAT_MAGIC || fh.magic == FAT_CIGAM) {
        ساخت fat_arch *fa = بھرو_ڈیٹا(fd, حجم(fh),
                                        fh.nfat_arch * حجم(*fa));
        تبادلہ_2 = fh.magic == FAT_CIGAM;
        برائے (i = 0; i < تبادلہ(fh.nfat_arch); i++)
#اگر_تعریف_شدہ TCC_ہدف_X86_64
          اگر (تبادلہ(fa[i].cputype) == CPU_TYPE_X86_64
              && تبادلہ(fa[i].cpusubtype) == CPU_SUBTYPE_X86_ALL)
#وگرنہ_اگر defined TCC_ہدف_ARM64
          اگر (تبادلہ(fa[i].cputype) == CPU_TYPE_ARM64
              && تبادلہ(fa[i].cpusubtype) == CPU_SUBTYPE_ARM64_ALL)
#اگر_ختم
            توڑو;
        اگر (i == تبادلہ(fh.nfat_arch)) {
            tcc_free(fa);
            واپس -1;
        }
        machofs = تبادلہ(fa[i].انحراف);
        tcc_free(fa);
        lseek(fd, machofs, SEEK_SET);
        جاؤ again;
    } ورنہ اگر (fh.magic == FAT_MAGIC_64 || fh.magic == FAT_CIGAM_64) {
        tcc_warning("%s: Mach-O fat 64bit files of type 0x%x not handled",
                    filename, fh.magic);
        واپس -1;
    }

    حافظہ_نقل(&mh, buf, حجم(mh));
    اگر (mh.magic != MH_MAGIC_64)
      واپس -1;
    dprintf("found Mach-O at %d\n", machofs);
    buf2 = بھرو_ڈیٹا(fd, machofs + حجم(ساخت mach_سرخی_64), mh.sizeofcmds);
    برائے (i = 0, lc = buf2; i < mh.ncmds; i++) {
        dprintf("lc %2d: 0x%08x\n", i, lc->cmd);
        انتخاب (lc->cmd) {
        حالت LC_SYMTAB:
        {
            ساخت symtab_command *sc = (ساخت symtab_command*)lc;
            nsyms = sc->nsyms;
            symtab = بھرو_ڈیٹا(fd, machofs + sc->symoff, nsyms * حجم(*symtab));
            strsize = sc->strsize;
            strtab = بھرو_ڈیٹا(fd, machofs + sc->stroff, strsize);
            توڑو;
        }
        حالت LC_ID_DYLIB:
        {
            ساخت dylib_command *dc = (ساخت dylib_command*)lc;
            soname = (حرف*)lc + dc->name;
            dprintf(" ID_DYLIB %d 0x%x 0x%x %s\n",
                    dc->timestamp, dc->current_نسخہ,
                    dc->compatibility_نسخہ, soname);
            توڑو;
        }
        حالت LC_REEXPORT_DYLIB:
        {
            ساخت dylib_command *dc = (ساخت dylib_command*)lc;
            حرف *name = (حرف*)lc + dc->name;
            صحیح subfd = open(name, O_RDONLY | O_ثنائی_2);
            dprintf(" REEXPORT %s\n", name);
            اگر (subfd < 0)
              tcc_warning("can't open %s (reexported from %s)", name, filename);
            ورنہ {
                /* Hopefully the REEXPORTs never form a cycle, we don't check
                   for that!  */
                macho_بھرو_dll(s1, subfd, name, lev + 1);
                close(subfd);
            }
            توڑو;
        }
        حالت LC_DYSYMTAB:
        {
            ساخت dysymtab_command *dc = (ساخت dysymtab_command*)lc;
            iextdef = dc->iextdefsym;
            nextdef = dc->nextdefsym;
            توڑو;
        }
        }
        lc = (ساخت بھرو_command*) ((حرف*)lc + lc->cmdsize);
    }

    اگر (tcc_جوڑو_dllref(s1, soname, lev)->ملا)
        جاؤ the_انتہا;

    اگر (!nsyms || !nextdef)
      tcc_warning("%s doesn't export any symbols?", filename);

    //dprintf("symbols (all):\n");
    dprintf("symbols (exported):\n");
    dprintf("    n: typ sec   desc              value name\n");
    //for (i = 0; i < nsyms; i++) {
    برائے (i = iextdef; i < iextdef + nextdef; i++) {
        ساخت nlist_64 *sym = symtab + i;
        dprintf("%5d: %3d %3d 0x%04x 0x%016lx %s\n",
                i, sym->n_type, sym->n_sect, sym->n_desc, (طویل)sym->n_قدر,
                strtab + sym->n_strx);
        سیٹ_elf_sym(s1->dynsymtab_section, 0, 0,
                    ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
                    0, SHN_UNDEF, strtab + sym->n_strx);
    }

  the_انتہا:
    tcc_free(strtab);
    tcc_free(symtab);
    tcc_free(buf2);
    واپس 0;
}
