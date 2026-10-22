/*
 *  TCCPE.C - PE file output for the Tiny C Compiler
 *
 *  Copyright (c) 2005-2007 grischka
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

#define PE_MERGE_DATA 1
#define PE_PRINT_SECTIONS 0

#ifndef _WIN32
#define stricmp strcasecmp
#define strnicmp strncasecmp
#ಅನ್ತರ್ಭಾವ <sys/stat.h> /* chmod() */
#endif

#ಯದಿ defined TCC_TARGET_X86_64
# define REL_TYPE_DIRECT R_X86_64_64
# define R_XXX_THUNKFIX R_X86_64_PC32
# define R_XXX_RELATIVE R_X86_64_RELATIVE
# define R_XXX_FUNCCALL R_X86_64_PLT32
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0x8664
# define CHARACTERISTICS_EXE 0x022F
# define CHARACTERISTICS_DLL 0x222E
# define IMAGE_BASE_EXE 0x00400000
# define IMAGE_BASE_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM
# define REL_TYPE_DIRECT R_ARM_ABS32
# define R_XXX_THUNKFIX R_ARM_ABS32
# define R_XXX_RELATIVE R_ARM_RELATIVE
# define R_XXX_FUNCCALL R_ARM_PC24
# define R_XXX_FUNCCALL2 R_ARM_ABS32
# define RSRC_RELTYPE 7 /* ??? (not tested) */
# define IMAGE_FILE_MACHINE 0x01C0
# define CHARACTERISTICS_EXE 0x010F
# define CHARACTERISTICS_DLL 0x230F
# define IMAGE_BASE_EXE 0x00100000
# define IMAGE_BASE_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM64
# define REL_TYPE_DIRECT R_AARCH64_ABS64
# define R_XXX_THUNKFIX R_AARCH64_ABS64
# define R_XXX_RELATIVE R_AARCH64_RELATIVE
# define R_XXX_FUNCCALL R_AARCH64_CALL26
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0xAA64
# define CHARACTERISTICS_EXE 0x0022
# define CHARACTERISTICS_DLL 0x2022
# define IMAGE_BASE_EXE 0x140000000ULL
# define IMAGE_BASE_DLL 0x180000000ULL
# define OS_VER 0x0602
# define DLLCHARACTERISTICS 0x8160

#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_I386
# define REL_TYPE_DIRECT R_386_32
# define R_XXX_THUNKFIX R_386_32
# define R_XXX_RELATIVE R_386_RELATIVE
# define R_XXX_FUNCCALL R_386_PC32
# define RSRC_RELTYPE 7 /* DIR32NB */
# define IMAGE_FILE_MACHINE 0x014C
# define CHARACTERISTICS_EXE 0x030F
# define CHARACTERISTICS_DLL 0x230E
# define IMAGE_BASE_EXE 0x00400000
# define IMAGE_BASE_DLL 0x10000000
# define OS_VER 0x0400
# define DLLCHARACTERISTICS 0
#endif

#ಯದಿ PTR_SIZE == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#ಅನ್ಯಥಾ
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#endif

#ifndef IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ವರ್ಣ BYTE;
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short WORD;
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ DWORD;
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned long long ULONGLONG;
#pragma pack(ತಳ್ಳು, 1)

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _IMAGE_DOS_HEADER {  /* DOS .EXE header */
    WORD e_magic;         /* Magic number */
    WORD e_cblp;          /* Bytes on last page of file */
    WORD e_cp;            /* Pages in file */
    WORD e_crlc;          /* Relocations */
    WORD e_cparhdr;       /* Size of header in paragraphs */
    WORD e_minalloc;      /* Minimum extra paragraphs needed */
    WORD e_maxalloc;      /* Maximum extra paragraphs needed */
    WORD e_ss;            /* Initial (relative) SS value */
    WORD e_sp;            /* Initial SP value */
    WORD e_csum;          /* Checksum */
    WORD e_ip;            /* Initial IP value */
    WORD e_cs;            /* Initial (relative) CS value */
    WORD e_lfarlc;        /* File address of relocation table */
    WORD e_ovno;          /* Overlay number */
    WORD e_res[4];        /* Reserved words */
    WORD e_oemid;         /* OEM identifier (for e_oeminfo) */
    WORD e_oeminfo;       /* OEM information; e_oemid specific */
    WORD e_res2[10];      /* Reserved words */
    DWORD e_lfanew;        /* File address of new exe header */
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

#define IMAGE_NT_SIGNATURE  0x00004550  /* PE00 */

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    ಸಂಖ್ಯೆ_Of_Sections;
    DWORD   TimeDateStamp;
    DWORD   Pointer_To_ಚಿಹ್ನೆ_Table;
    DWORD   ಸಂಖ್ಯೆ_Of_Symbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;


#define IMAGE_SIZEOF_FILE_HEADER 20

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;


ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _IMAGE_OPTIONAL_HEADER {
    /* Standard fields. */
    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
#ಯದಿ PTR_SIZE == 4
    DWORD   BaseOfData;
#endif
    /* NT additional fields. */
    ADDR3264 ImageBase;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    WORD    MajorOperatingSystemVersion;
    WORD    MinorOperatingSystemVersion;
    WORD    MajorImageVersion;
    WORD    MinorImageVersion;
    WORD    MajorSubsystemVersion;
    WORD    MinorSubsystemVersion;
    DWORD   Win32_Version_ಮೌಲ್ಯ;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    ADDR3264 Size_Of_ರಾಶಿ_Reserve;
    ADDR3264 Size_Of_ರಾಶಿ_Commit;
    ADDR3264 SizeOfHeapReserve;
    ADDR3264 SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   ಸಂಖ್ಯೆ_Of_Rva_And_Sizes;
    IMAGE_DATA_DIRECTORY DataDirectory[16];
} IMAGE_OPTIONAL_HEADER32, IMAGE_OPTIONAL_HEADER64, IMAGE_OPTIONAL_HEADER;

#define IMAGE_DIRECTORY_ENTRY_EXPORT          0   /* Export Directory */
#define IMAGE_DIRECTORY_ENTRY_IMPORT          1   /* Import Directory */
#define IMAGE_DIRECTORY_ENTRY_RESOURCE        2   /* Resource Directory */
#define IMAGE_DIRECTORY_ENTRY_EXCEPTION       3   /* Exception Directory */
#define IMAGE_DIRECTORY_ENTRY_SECURITY        4   /* Security Directory */
#define IMAGE_DIRECTORY_ENTRY_BASERELOC       5   /* Base Relocation Table */
#define IMAGE_DIRECTORY_ENTRY_DEBUG           6   /* Debug Directory */
/*      IMAGE_DIRECTORY_ENTRY_COPYRIGHT       7      (X86 usage) */
#define IMAGE_DIRECTORY_ENTRY_ARCHITECTURE    7   /* Architecture Specific Data */
#define IMAGE_DIRECTORY_ENTRY_GLOBALPTR       8   /* RVA of GP */
#define IMAGE_DIRECTORY_ENTRY_TLS             9   /* TLS Directory */
#define IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG    10   /* Load Configuration Directory */
#define IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT   11   /* Bound Import Directory in headers */
#define IMAGE_DIRECTORY_ENTRY_IAT            12   /* Import Address Table */
#define IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT   13   /* Delay Load Import Descriptors */
#define IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR 14   /* COM Runtime descriptor */

/* Section header format. */
#define IMAGE_SIZEOF_SHORT_NAME         8

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _IMAGE_SECTION_HEADER {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    ಸಙ್ಘ {
            DWORD   PhysicalAddress;
            DWORD   VirtualSize;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   SizeOfRawData;
    DWORD   PointerToRawData;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    ಸಂಖ್ಯೆ_Of_Relocations;
    WORD    ಸಂಖ್ಯೆ_Of_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#define IMAGE_SIZEOF_SECTION_HEADER     40

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD Name;
    DWORD Base;
    DWORD ಸಂಖ್ಯೆ_Of_Functions;
    DWORD ಸಂಖ್ಯೆ_Of_Names;
    DWORD AddressOfFunctions;
    DWORD AddressOfNames;
    DWORD AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _IMAGE_TLS_DIRECTORY {
    ADDR3264 StartAddressOfRawData;
    ADDR3264 EndAddressOfRawData;
    ADDR3264 AddressOfIndex;
    ADDR3264 AddressOfCallBacks;
    DWORD SizeOfZeroFill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _IMAGE_IMPORT_DESCRIPTOR {
    ಸಙ್ಘ {
        DWORD Characteristics;
        DWORD OriginalFirstThunk;
    };
    DWORD TimeDateStamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   SizeOfBlock;
//  WORD    TypeOffset[1];
} IMAGE_BASE_RELOCATION;

#define IMAGE_SIZEOF_BASE_RELOCATION     8

#define IMAGE_REL_BASED_ABSOLUTE         0
#define IMAGE_REL_BASED_ಮೇಲಿನ             1
#define IMAGE_REL_BASED_ಕೆಳಗಿನ              2
#define IMAGE_REL_BASED_HIGHLOW          3
#define IMAGE_REL_BASED_HIGHADJ          4
#define IMAGE_REL_BASED_MIPS_JMPADDR     5
#define IMAGE_REL_BASED_SECTION          6
#define IMAGE_REL_BASED_REL32            7
#define IMAGE_REL_BASED_DIR64           10

#define IMAGE_SCN_CNT_CODE                  0x00000020
#define IMAGE_SCN_CNT_INITIALIZED_DATA      0x00000040
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA    0x00000080
#define IMAGE_SCN_MEM_DISCARDABLE           0x02000000
#define IMAGE_SCN_MEM_SHARED                0x10000000
#define IMAGE_SCN_MEM_EXECUTE               0x20000000
#define IMAGE_SCN_MEM_READ                  0x40000000
#define IMAGE_SCN_MEM_WRITE                 0x80000000

#define IMAGE_DLLCHARACTERISTICS_ಮೇಲಿನ_ENTROPY_VA 0x0020
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#define IMAGE_FILE_RELOCS_STRIPPED 0x0001

#pragma pack(ತೆಗೆ)

/* ----------------------------------------------------------- */
#endif /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#ifndef IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#endif

#pragma pack(ತಳ್ಳು, 1)
ಸಂರಚನಾ pe_header
{
    IMAGE_DOS_HEADER doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_HEADER filehdr;
#ಯದಿ PTR_SIZE == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#ಅನ್ಯಥಾ
#ifdef _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#ಅನ್ಯಥಾ
    IMAGE_OPTIONAL_HEADER opthdr;
#endif
#endif
};

ಸಂರಚನಾ pe_reloc_header {
    DWORD offset;
    DWORD size;
};

ಸಂರಚನಾ pe_rsrc_header {
    ಸಂರಚನಾ _IMAGE_FILE_HEADER filehdr;
    ಸಂರಚನಾ _IMAGE_SECTION_HEADER sectionhdr;
};

ಸಂರಚನಾ pe_rsrc_reloc {
    DWORD offset;
    DWORD size;
    WORD type;
};
#pragma pack(ತೆಗೆ)

/* ------------------------------------------------------------- */
/* internal temporary structures */

ಗಣನಾ {
    sec_text = 0,
    sec_rdata ,
    sec_data ,
    sec_bss ,
    sec_idata ,
    sec_pdata ,
    sec_tdata ,
    sec_tbss ,
    sec_other ,
    sec_rsrc ,
    sec_debug ,
    sec_reloc ,
    sec_last
};

#ಯದಿ 0
ಸ್ಥಿರ ಧ್ರುವ DWORD pe_sec_flags[] = {
    0x60000020, /* ".text"     , */
    0xC0000040, /* ".data"     , */
    0xC0000080, /* ".bss"      , */
    0x40000040, /* ".idata"    , */
    0x40000040, /* ".pdata"    , */
    0xE0000060, /* < other >   , */
    0x40000040, /* ".rsrc"     , */
    0x42000802, /* ".stab"     , */
    0x42000040, /* ".reloc"    , */
};
#endif

ಸಂರಚನಾ section_info {
    ಪೂರ್ಣಾಙ್ಕ cls;
    ವರ್ಣ name[32];
    ADDR3264 sh_addr;
    DWORD sh_size;
    DWORD pe_flags;
    Section *sec;
    DWORD data_size;
    IMAGE_SECTION_HEADER ish;
};

ಸಂರಚನಾ import_ಚಿಹ್ನೆ {
    ಪೂರ್ಣಾಙ್ಕ sym_index;
    ಪೂರ್ಣಾಙ್ಕ iat_index;
    ಪೂರ್ಣಾಙ್ಕ thk_offset;
};

ಸಂರಚನಾ pe_import_info {
    ಪೂರ್ಣಾಙ್ಕ dll_index;
    ಪೂರ್ಣಾಙ್ಕ sym_ಎಣಿಕೆ;
    ಸಂರಚನಾ import_ಚಿಹ್ನೆ **symbols;
};

ಸಂರಚನಾ pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    ಧ್ರುವ ವರ್ಣ *filename;
    ಪೂರ್ಣಾಙ್ಕ type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    ಧ್ರುವ ವರ್ಣ *start_ಚಿಹ್ನೆ;
    DWORD start_addr;
    DWORD imp_offs;
    DWORD imp_size;
    DWORD iat_offs;
    DWORD iat_size;
    DWORD exp_offs;
    DWORD exp_size;
    DWORD tls_dir;
    DWORD tls_data;
    DWORD tls_size;
    ಪೂರ್ಣಾಙ್ಕ subsystem;
    DWORD section_align;
    DWORD file_align;
    ಸಂರಚನಾ section_info **sec_info;
    ಪೂರ್ಣಾಙ್ಕ sec_ಎಣಿಕೆ;
    ಸಂರಚನಾ pe_import_info **imp_info;
    ಪೂರ್ಣಾಙ್ಕ imp_ಎಣಿಕೆ;
    /* output */
    FILE *op;
    DWORD sum;
    unsigned pos;
};

#define PE_NUL 0
#define PE_DLL 1
#define PE_GUI 2
#define PE_EXE 3
#define PE_RUN 4

/* --------------------------------------------*/

ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    ಧ್ರುವ ವರ್ಣ *name = (ವರ್ಣ*)symtab_section->link->data + sym->st_name;
    ಯದಿ (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        ಪ್ರತ್ಯಾಗಮ name + 1;
    ಪ್ರತ್ಯಾಗಮ name;
}


ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ dynarray_assoc(ಶೂನ್ಯ **pp, ಪೂರ್ಣಾಙ್ಕ n, ಪೂರ್ಣಾಙ್ಕ ಕೀಲಿ)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ (i = 0; i < n; ++i, ++pp)
    ಯದಿ (ಕೀಲಿ == **(ಪೂರ್ಣಾಙ್ಕ **) pp)
        ಪ್ರತ್ಯಾಗಮ i;
    ಪ್ರತ್ಯಾಗಮ -1;
}

ಸ್ಥಿರ DWORD umin(DWORD a, DWORD b)
{
    ಪ್ರತ್ಯಾಗಮ a < b ? a : b;
}

ಸ್ಥಿರ DWORD umax(DWORD a, DWORD b)
{
    ಪ್ರತ್ಯಾಗಮ a < b ? b : a;
}

ಸ್ಥಿರ DWORD pe_file_align(ಸಂರಚನಾ pe_info *pe, DWORD n)
{
    ಪ್ರತ್ಯಾಗಮ (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

ಸ್ಥಿರ ADDR3264 pe_virtual_align(ಸಂರಚನಾ pe_info *pe, ADDR3264 n)
{
    ಪ್ರತ್ಯಾಗಮ (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

ಸ್ಥಿರ ಶೂನ್ಯ pe_align_section(Section *s, ಪೂರ್ಣಾಙ್ಕ a)
{
    ಪೂರ್ಣಾಙ್ಕ i = s->data_offset & (a-1);
    ಯದಿ (i)
        section_ptr_add(s, a - i);
}

ಸ್ಥಿರ ಶೂನ್ಯ pe_set_datadir(ಸಂರಚನಾ pe_header *hdr, ಪೂರ್ಣಾಙ್ಕ dir, DWORD addr, DWORD size)
{
    hdr->opthdr.DataDirectory[dir].VirtualAddress = addr;
    hdr->opthdr.DataDirectory[dir].Size = size;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pe_fwrite(ಸಂರಚನಾ pe_info *pe, ಧ್ರುವ ಶೂನ್ಯ *data, ಪೂರ್ಣಾಙ್ಕ len)
{
    ಧ್ರುವ WORD *p = data;
    DWORD sum;
    ಪೂರ್ಣಾಙ್ಕ ret, i;
    pe->pos += (ret = fwrite(data, 1, len, pe->op));
    sum = pe->sum;
    ಪ್ರತಿ (i = len; i > 0; i -= 2) {
        sum += (i >= 2) ? *p++ : *(BYTE*)p;
        sum = (sum + (sum >> 16)) & 0xFFFF;
    }
    pe->sum = sum;
    ಪ್ರತ್ಯಾಗಮ len == ret ? 0 : -1;
}

ಸ್ಥಿರ ಶೂನ್ಯ pe_fpad(ಸಂರಚನಾ pe_info *pe, DWORD new_pos)
{
    ವರ್ಣ buf[256];
    ಪೂರ್ಣಾಙ್ಕ n, diff = new_pos - pe->pos;
    memset(buf, 0, ಪರಿಮಾಣ buf);
    ಯಾವತ್ (diff > 0) {
        diff -= n = umin(diff, ಪರಿಮಾಣ buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#pragma pack(ತಳ್ಳು, 1)
ಸಂರಚನಾ syment
{
    ಸಙ್ಘ {
        ವರ್ಣ        n_name[8];     /* old COFF version */
        ಸಂರಚನಾ {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_offset;      /* offset into string table */
        };
    };
    int32_t         n_ಮೌಲ್ಯ;        /* value of symbol */
    short           n_scnum;        /* section number */
    unsigned short  n_type;         /* type and derived type */
    ವರ್ಣ            n_sclass;       /* storage class */
    ವರ್ಣ            n_numaux;       /* number of aux. entries */
};
#pragma pack(ತೆಗೆ)

#define SHF_PRIVATE 0x80000000

ಸ್ಥಿರ ಶೂನ್ಯ pe_add_coffsym(ಸಂರಚನಾ pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    ಸಂರಚನಾ syment *se;
    ಪೂರ್ಣಾಙ್ಕ n;

    ಯದಿ (ರಿಕ್ತ == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_PRIVATE);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_PRIVATE);
        section_ptr_add(pe->coffstr, 4); /* coff string table size */
        ಪ್ರತ್ಯಾಗಮ;
    }

#ಯದಿ 0
    se = section_ptr_add(pe->coffsym, ಪರಿಮಾಣ *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_add(pe->coffsym, ಪರಿಮಾಣ *se);
    strcpy((ವರ್ಣ*)se, "no-file");
#endif

#ಯದಿ 1
    esym = (ElfSym*)s1->symtab->data;
    ಪ್ರತಿ (n = s1->symtab->data_offset / ಪರಿಮಾಣ *esym; ++esym, --n;) {
        ಪೂರ್ಣಾಙ್ಕ sym_bind = ELFW(ST_BIND)(esym->st_info);
        ಯದಿ (sym_bind == STB_GLOBAL) {
            ವರ್ಣ *name = esym->st_name + (ವರ್ಣ*)s1->symtab->link->data;
            ಪೂರ್ಣಾಙ್ಕ nl = strlen(name);
            addr_t ಮೌಲ್ಯ = esym->st_ಮೌಲ್ಯ;
            ಪೂರ್ಣಾಙ್ಕ shnum = esym->st_shndx;
            ಯದಿ (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                ಮೌಲ್ಯ = ಮೌಲ್ಯ - s->sh_addr;
            }
            se = section_ptr_add(pe->coffsym, ಪರಿಮಾಣ *se);
            se->n_ಮೌಲ್ಯ = ಮೌಲ್ಯ;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            ಯದಿ (nl <= 8)
                memcpy(se->n_name, name, nl);
            ಅನ್ಯಥಾ
                se->n_offset = put_elf_str(pe->coffstr, name);
        }
    }
#endif
    write32le(pe->coffstr->data, pe->coffstr->data_offset); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
ಸ್ಥಿರ ಶೂನ್ಯ pe_create_pdb(TCCState *s1, ಧ್ರುವ ವರ್ಣ *exename)
{
    ವರ್ಣ buf[300]; ಪೂರ್ಣಾಙ್ಕ r;
    snprintf(buf, ಪರಿಮಾಣ buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    strcpy(tcc_fileextension(strcpy(buf, exename)), ".pdb");
    ಯದಿ (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } ಅನ್ಯಥಾ ಯದಿ (s1->verbose) {
        printf("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pe_write(ಸಂರಚನಾ pe_info *pe)
{
    ಸ್ಥಿರ ಧ್ರುವ ಸಂರಚನಾ pe_header pe_template = {
    {
    /* IMAGE_DOS_HEADER doshdr */
    0x5A4D, /*WORD e_magic;         Magic number */
    0x0090, /*WORD e_cblp;          Bytes on last page of file */
    0x0003, /*WORD e_cp;            Pages in file */
    0x0000, /*WORD e_crlc;          Relocations */

    0x0004, /*WORD e_cparhdr;       Size of header in paragraphs */
    0x0000, /*WORD e_minalloc;      Minimum extra paragraphs needed */
    0xFFFF, /*WORD e_maxalloc;      Maximum extra paragraphs needed */
    0x0000, /*WORD e_ss;            Initial (relative) SS value */

    0x00B8, /*WORD e_sp;            Initial SP value */
    0x0000, /*WORD e_csum;          Checksum */
    0x0000, /*WORD e_ip;            Initial IP value */
    0x0000, /*WORD e_cs;            Initial (relative) CS value */
    0x0040, /*WORD e_lfarlc;        File address of relocation table */
    0x0000, /*WORD e_ovno;          Overlay number */
    {0,0,0,0}, /*WORD e_res[4];     Reserved words */
    0x0000, /*WORD e_oemid;         OEM identifier (for e_oeminfo) */
    0x0000, /*WORD e_oeminfo;       OEM information; e_oemid specific */
    {0,0,0,0,0,0,0,0,0,0}, /*WORD e_res2[10];      Reserved words */
    0x00000080  /*DWORD   e_lfanew;        File address of new exe header */
    },{
    /* BYTE dosstub[0x40] */
    /* 14 code bytes + "This program cannot be run in DOS mode.\r\r\n$" + 6 * 0x00 */
    0x0e,0x1f,0xba,0x0e,0x00,0xb4,0x09,0xcd,0x21,0xb8,0x01,0x4c,0xcd,0x21,0x54,0x68,
    0x69,0x73,0x20,0x70,0x72,0x6f,0x67,0x72,0x61,0x6d,0x20,0x63,0x61,0x6e,0x6e,0x6f,
    0x74,0x20,0x62,0x65,0x20,0x72,0x75,0x6e,0x20,0x69,0x6e,0x20,0x44,0x4f,0x53,0x20,
    0x6d,0x6f,0x64,0x65,0x2e,0x0d,0x0d,0x0a,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    },
    0x00004550, /* DWORD nt_sig = IMAGE_NT_SIGNATURE */
    {
    /* IMAGE_FILE_HEADER filehdr */
    IMAGE_FILE_MACHINE, /*WORD    Machine; */
    0x0003, /*WORD    NumberOfSections; */
    0x00000000, /*DWORD   TimeDateStamp; */
    0x00000000, /*DWORD   PointerToSymbolTable; */
    0x00000000, /*DWORD   NumberOfSymbols; */
    0x00E0 + (PTR_SIZE-4)*4, /*WORD    SizeOfOptionalHeader; */
    CHARACTERISTICS_EXE, /*WORD    Characteristics; */
    },{
    /* IMAGE_OPTIONAL_HEADER opthdr */
    /* Standard fields. */
    PE_MAGIC, /*WORD    Magic; */
    0x06, /*BYTE    MajorLinkerVersion; */
    0x00, /*BYTE    MinorLinkerVersion; */
    0x00000000, /*DWORD   SizeOfCode; */
    0x00000000, /*DWORD   SizeOfInitializedData; */
    0x00000000, /*DWORD   SizeOfUninitializedData; */
    0x00000000, /*DWORD   AddressOfEntryPoint; */
    0x00000000, /*DWORD   BaseOfCode; */
#ಯದಿ PTR_SIZE == 4
    0x00000000, /*DWORD   BaseOfData; */
#endif
    /* NT additional fields. */
    0x00000000,	/*ADDR3264   ImageBase; */
    0x00001000, /*DWORD   SectionAlignment; */
    0x00000200, /*DWORD   FileAlignment; */
    OS_VER >> 8, /*WORD    MajorOperatingSystemVersion; */
    OS_VER & 255, /*WORD    MinorOperatingSystemVersion; */
    0x0000, /*WORD    MajorImageVersion; */
    0x0000, /*WORD    MinorImageVersion; */
    OS_VER >> 8, /*WORD    MajorSubsystemVersion; */
    OS_VER & 255, /*WORD    MinorSubsystemVersion; */
    0x00000000, /*DWORD   Win32VersionValue; */
    0x00000000, /*DWORD   SizeOfImage; */
    0x00000200, /*DWORD   SizeOfHeaders; */
    0x00000000, /*DWORD   CheckSum; */
    0x0002, /*WORD    Subsystem; */
    DLLCHARACTERISTICS, /*WORD    DllCharacteristics; */
    0x00100000, /*ADDR3264 SizeOfStackReserve; */
    0x00001000, /*ADDR3264 SizeOfStackCommit; */
    0x00100000, /*ADDR3264 SizeOfHeapReserve; */
    0x00001000, /*ADDR3264 SizeOfHeapCommit; */
    0x00000000, /*DWORD   LoaderFlags; */
    0x00000010, /*DWORD   NumberOfRvaAndSizes; */

    /* IMAGE_DATA_DIRECTORY DataDirectory[16]; */
    {{0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0},
     {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}}
    }};

    ಸಂರಚನಾ pe_header pe_header = pe_template;

    ಪೂರ್ಣಾಙ್ಕ i;
    DWORD file_offset;
    ಸಂರಚನಾ section_info *si;
    IMAGE_SECTION_HEADER *psh;
    TCCState *s1 = pe->s1;

    ಯದಿ (s1->do_debug)
        pe_add_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    ಯದಿ (ರಿಕ್ತ == pe->op)
        ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        ಪರಿಮಾಣ (ಸಂರಚನಾ pe_header)
        + pe->sec_ಎಣಿಕೆ * ಪರಿಮಾಣ (IMAGE_SECTION_HEADER)
        );

    file_offset = pe->sizeofheaders;

    ಯದಿ (2 == s1->verbose)
        printf("-------------------------------"
               "\n  virt   file   size  section" "\n");
    ಪ್ರತಿ (i = 0; i < pe->sec_ಎಣಿಕೆ; ++i) {
        DWORD addr, size;
        ಧ್ರುವ ವರ್ಣ *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        size = si->sh_size;
        psh = &si->ish;

        ಯದಿ (2 == s1->verbose)
            printf("%6x %6x %6x  %s\n",
                (unsigned)addr, (unsigned)file_offset, (unsigned)size, sh_name);

        ವಿಕಲ್ಪ (si->cls) {
            ಪಕ್ಷ sec_text:
                ಯದಿ (!pe_header.opthdr.BaseOfCode)
                    pe_header.opthdr.BaseOfCode = addr;
                ಭಙ್ಗ;

            ಪಕ್ಷ sec_data:
#ಯದಿ PTR_SIZE == 4
                ಯದಿ (!pe_header.opthdr.BaseOfData)
                    pe_header.opthdr.BaseOfData = addr;
#endif
                ಭಙ್ಗ;

            ಪಕ್ಷ sec_bss:
                ಭಙ್ಗ;

            ಪಕ್ಷ sec_reloc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_BASERELOC, addr, size);
                ಭಙ್ಗ;

            ಪಕ್ಷ sec_rsrc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_RESOURCE, addr, size);
                ಭಙ್ಗ;

            ಪಕ್ಷ sec_pdata:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXCEPTION, addr, size);
                ಭಙ್ಗ;
        }

        ಯದಿ (pe->imp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IMPORT,
                pe->imp_offs, pe->imp_size);
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IAT,
                pe->iat_offs, pe->iat_size);
        }
        ಯದಿ (pe->exp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXPORT,
                pe->exp_offs, pe->exp_size);
        }
        ಯದಿ (pe->tls_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_size);
        }

        memcpy(psh->Name, sh_name, umin(strlen(sh_name), ಪರಿಮಾಣ psh->Name));
        ಯದಿ (pe->coffstr && strlen(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((ವರ್ಣ*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->VirtualAddress = addr;
        psh->Misc.VirtualSize = size;
        pe_header.opthdr.SizeOfImage =
            umax(pe_virtual_align(pe, size + addr), pe_header.opthdr.SizeOfImage);

        ಯದಿ (si->data_size) {
            psh->PointerToRawData = file_offset;
            file_offset = pe_file_align(pe, file_offset + si->data_size);
            psh->SizeOfRawData = file_offset - psh->PointerToRawData;
            ಯದಿ (si->cls == sec_text)
                pe_header.opthdr.SizeOfCode += psh->SizeOfRawData;
            ಅನ್ಯಥಾ
                pe_header.opthdr.SizeOfInitializedData += psh->SizeOfRawData;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_header.filehdr.ಸಂಖ್ಯೆ_Of_Sections = pe->sec_ಎಣಿಕೆ;
    pe_header.opthdr.AddressOfEntryPoint = pe->start_addr;
    pe_header.opthdr.SizeOfHeaders = pe->sizeofheaders;
    pe_header.opthdr.ImageBase = pe->imagebase;
    pe_header.opthdr.Subsystem = pe->subsystem;
    pe_header.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    ಯದಿ (s1->pe_ರಾಶಿ_size)
        pe_header.opthdr.Size_Of_ರಾಶಿ_Reserve = s1->pe_ರಾಶಿ_size;
    ಯದಿ (PE_DLL == pe->type)
        pe_header.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_header.filehdr.Characteristics |= s1->pe_characteristics;
    ಯದಿ (pe->reloc)
        pe_header.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    ಯದಿ (pe->coffsym) {
        pe_add_coffsym(pe);
        pe_header.filehdr.Pointer_To_ಚಿಹ್ನೆ_Table = file_offset;
        pe_header.filehdr.ಸಂಖ್ಯೆ_Of_Symbols
            = pe->coffsym->data_offset / ಪರಿಮಾಣ (ಸಂರಚನಾ syment);
    }

    pe_fwrite(pe, &pe_header, ಪರಿಮಾಣ pe_header);
    ಪ್ರತಿ (i = 0; i < pe->sec_ಎಣಿಕೆ; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, ಪರಿಮಾಣ(IMAGE_SECTION_HEADER));

    file_offset = pe->sizeofheaders;
    ಪ್ರತಿ (i = 0; i < pe->sec_ಎಣಿಕೆ; ++i) {
        Section *s;
        si = pe->sec_info[i];
        ಯದಿ (!si->data_size)
            ಅನುವರ್ತ;
        ಪ್ರತಿ (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_offset);
            pe_fwrite(pe, s->data, s->data_offset);
            ಯದಿ (s->prev)
                file_offset += s->prev->sh_addr - s->sh_addr;
        }
        file_offset = si->ish.PointerToRawData + si->ish.SizeOfRawData;
        pe_fpad(pe, file_offset);
    }

    ಯದಿ (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->data, pe->coffsym->data_offset);
        pe_fwrite(pe, pe->coffstr->data, pe->coffstr->data_offset);
        file_offset = pe->pos;
    }

    pe->sum += file_offset;
    fseek(pe->op, offsetof(ಸಂರಚನಾ pe_header, opthdr.CheckSum), SEEK_SET);
    pe_fwrite(pe, &pe->sum, ಪರಿಮಾಣ (DWORD));

    fclose (pe->op);
#ifndef _WIN32
    chmod(pe->filename, 0777);
#endif

    ಯದಿ (2 == s1->verbose)
        printf("-------------------------------\n");
    ಯದಿ (s1->verbose)
        printf("<- %s (%u bytes)\n", pe->filename, (unsigned)file_offset);

    ಯದಿ (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    ಪ್ರತ್ಯಾಗಮ 0;
}

/*----------------------------------------------------------------------------*/

ಸ್ಥಿರ ಸಂರಚನಾ import_ಚಿಹ್ನೆ *pe_add_import(ಸಂರಚನಾ pe_info *pe, ಪೂರ್ಣಾಙ್ಕ sym_index)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪೂರ್ಣಾಙ್ಕ dll_index;
    ಸಂರಚನಾ pe_import_info *p;
    ಸಂರಚನಾ import_ಚಿಹ್ನೆ *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->data + sym_index;
    dll_index = isym->st_size;

    i = dynarray_assoc ((ಶೂನ್ಯ**)pe->imp_info, pe->imp_ಎಣಿಕೆ, dll_index);
    ಯದಿ (-1 != i) {
        p = pe->imp_info[i];
        ಗಚ್ಛ found_dll;
    }
    p = tcc_mallocz(ಪರಿಮಾಣ *p);
    p->dll_index = dll_index;
    dynarray_add(&pe->imp_info, &pe->imp_ಎಣಿಕೆ, p);

found_dll:
    i = dynarray_assoc ((ಶೂನ್ಯ**)p->symbols, p->sym_ಎಣಿಕೆ, sym_index);
    ಯದಿ (-1 != i)
        ಪ್ರತ್ಯಾಗಮ p->symbols[i];

    s = tcc_mallocz(ಪರಿಮಾಣ *s);
    dynarray_add(&p->symbols, &p->sym_ಎಣಿಕೆ, s);
    s->sym_index = sym_index;
    ಪ್ರತ್ಯಾಗಮ s;
}

ಸ್ಥಿರ ಶೂನ್ಯ pe_free_imports(ಸಂರಚನಾ pe_info *pe)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ (i = 0; i < pe->imp_ಎಣಿಕೆ; ++i) {
        ಸಂರಚನಾ pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_ಎಣಿಕೆ);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_ಎಣಿಕೆ);
}

/*----------------------------------------------------------------------------*/
ಸ್ಥಿರ ಶೂನ್ಯ pe_build_imports(ಸಂರಚನಾ pe_info *pe)
{
    ಪೂರ್ಣಾಙ್ಕ thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_base = pe->thunk->sh_addr - pe->imagebase;
    ಪೂರ್ಣಾಙ್ಕ ndlls = pe->imp_ಎಣಿಕೆ;
    TCCState *s1 = pe->s1;

    ಪ್ರತಿ (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_ಎಣಿಕೆ;

    ಯದಿ (0 == sym_cnt)
        ಪ್ರತ್ಯಾಗಮ;

    pe_align_section(pe->thunk, 16);
    pe->imp_size = (ndlls + 1) * ಪರಿಮಾಣ(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_size = (sym_cnt + ndlls) * ಪರಿಮಾಣ(ADDR3264);
    dll_ptr = pe->thunk->data_offset;
    thk_ptr = dll_ptr + pe->imp_size;
    ent_ptr = thk_ptr + pe->iat_size;
    pe->imp_offs = dll_ptr + rva_base;
    pe->iat_offs = thk_ptr + rva_base;
    section_ptr_add(pe->thunk, pe->imp_size + 2*pe->iat_size);

    ಪ್ರತಿ (i = 0; i < pe->imp_ಎಣಿಕೆ; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        ಪೂರ್ಣಾಙ್ಕ k, n, dllindex;
        ADDR3264 v;
        ಸಂರಚನಾ pe_import_info *p = pe->imp_info[i];
        ಧ್ರುವ ವರ್ಣ *name;
        DLLReference *dllref;

        dllindex = p->dll_index;
        ಯದಿ (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        ಅನ್ಯಥಾ
            name = "", dllref = ರಿಕ್ತ;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->data + dll_ptr);
        hdr->FirstThunk = thk_ptr + rva_base;
        hdr->OriginalFirstThunk = ent_ptr + rva_base;
        hdr->Name = v + rva_base;

        ಪ್ರತಿ (k = 0, n = p->sym_ಎಣಿಕೆ; k <= n; ++k) {
            ಯದಿ (k < n) {
                ಪೂರ್ಣಾಙ್ಕ iat_index = p->symbols[k]->iat_index;
                ಪೂರ್ಣಾಙ್ಕ sym_index = p->symbols[k]->sym_index;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->data + sym_index;
                ಧ್ರುವ ವರ್ಣ *name = (ವರ್ಣ*)s1->dynsymtab_section->link->data + imp_sym->st_name;
                ಪೂರ್ಣಾಙ್ಕ ordinal;

                /* patch symbol (and possibly its underscored alias) */
                ಕುರು {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->data + iat_index;
                    iat_index = esym->st_ಮೌಲ್ಯ;
                    esym->st_ಮೌಲ್ಯ = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_ಅಂಕೆ;
                } ಯಾವತ್ (iat_index);

                ಯದಿ (dllref)
                    v = 0, ordinal = imp_sym->st_ಮೌಲ್ಯ; /* ordinal from pe_load_def */
                ಅನ್ಯಥಾ
                    ordinal = 0, v = imp_sym->st_ಮೌಲ್ಯ; /* address from tcc_add_symbol() */

#ifdef TCC_IS_NATIVE
                ಯದಿ (pe->type == PE_RUN) {
                    ಯದಿ (dllref) {
                        ಯದಿ ( !dllref->handle )
                            dllref->handle = LoadLibraryA(dllref->name);
                        v = (ADDR3264)GetProcAddress(dllref->handle, ordinal?(ವರ್ಣ*)0+ordinal:name);
                    }
                    ಯದಿ (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } ಅನ್ಯಥಾ
#endif
                ಯದಿ (ordinal) {
                    v = ordinal | (ADDR3264)1 << (ಪರಿಮಾಣ(ADDR3264)*8 - 1);
                } ಅನ್ಯಥಾ {
                    v = pe->thunk->data_offset + rva_base;
                    section_ptr_add(pe->thunk, ಪರಿಮಾಣ(WORD)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } ಅನ್ಯಥಾ {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->data+thk_ptr) =
            *(ADDR3264*)(pe->thunk->data+ent_ptr) = v;
            thk_ptr += ಪರಿಮಾಣ (ADDR3264);
            ent_ptr += ಪರಿಮಾಣ (ADDR3264);
        }
        dll_ptr += ಪರಿಮಾಣ(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

ಸಂರಚನಾ pe_sort_sym
{
    ಪೂರ್ಣಾಙ್ಕ index;
    ಧ್ರುವ ವರ್ಣ *name;
};

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ sym_cmp(ಧ್ರುವ ಶೂನ್ಯ *va, ಧ್ರುವ ಶೂನ್ಯ *vb)
{
    ಧ್ರುವ ವರ್ಣ *ca = (*(ಸಂರಚನಾ pe_sort_sym**)va)->name;
    ಧ್ರುವ ವರ್ಣ *cb = (*(ಸಂರಚನಾ pe_sort_sym**)vb)->name;
    ಪ್ರತ್ಯಾಗಮ strcmp(ca, cb);
}

ಸ್ಥಿರ ಶೂನ್ಯ pe_build_exports(ಸಂರಚನಾ pe_info *pe)
{
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಙ್ಕ sym_index, sym_end;
    DWORD rva_base, base_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    ಪೂರ್ಣಾಙ್ಕ sym_ಎಣಿಕೆ, ord;
    ಸಂರಚನಾ pe_sort_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    ವರ್ಣ buf[260];
    ಧ್ರುವ ವರ್ಣ *dllname;
    ಧ್ರುವ ವರ್ಣ *name;

    rva_base = pe->thunk->sh_addr - pe->imagebase;
    sym_ಎಣಿಕೆ = 0, sorted = ರಿಕ್ತ, op = ರಿಕ್ತ;

    sym_end = symtab_section->data_offset / ಪರಿಮಾಣ(ElfW(Sym));
    ಪ್ರತಿ (sym_index = 1; sym_index < sym_end; ++sym_index) {
        sym = (ElfW(Sym)*)symtab_section->data + sym_index;
        name = pe_export_name(s1, sym);
        ಯದಿ (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(ಪರಿಮಾಣ *p);
            p->index = sym_index;
            p->name = name;
            dynarray_add(&sorted, &sym_ಎಣಿಕೆ, p);
        }
#ಯದಿ 0
        ಯದಿ (sym->st_other & ST_PE_EXPORT)
            printf("export: %s\n", name);
        ಯದಿ (sym->st_other & ST_PE_STDCALL)
            printf("stdcall: %s\n", name);
#endif
    }

    ಯದಿ (0 == sym_ಎಣಿಕೆ)
        ಪ್ರತ್ಯಾಗಮ;

    qsort (sorted, sym_ಎಣಿಕೆ, ಪರಿಮಾಣ *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    base_o = pe->thunk->data_offset;
    func_o = base_o + ಪರಿಮಾಣ(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_ಎಣಿಕೆ * ಪರಿಮಾಣ (DWORD);
    ord_o = name_o + sym_ಎಣಿಕೆ * ಪರಿಮಾಣ (DWORD);
    str_o = ord_o + sym_ಎಣಿಕೆ * ಪರಿಮಾಣ(WORD);

    hdr = section_ptr_add(pe->thunk, str_o - base_o);
    hdr->Characteristics        = 0;
    hdr->Base                   = 1;
    hdr->ಸಂಖ್ಯೆ_Of_Functions      = sym_ಎಣಿಕೆ;
    hdr->ಸಂಖ್ಯೆ_Of_Names          = sym_ಎಣಿಕೆ;
    hdr->AddressOfFunctions     = func_o + rva_base;
    hdr->AddressOfNames         = name_o + rva_base;
    hdr->AddressOfNameOrdinals  = ord_o + rva_base;
    hdr->Name                   = str_o + rva_base;
    put_elf_str(pe->thunk, dllname);

#ಯದಿ 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, ಪರಿಮಾಣ buf, pe->filename);
    strcpy(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    ಯದಿ (ರಿಕ್ತ == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } ಅನ್ಯಥಾ {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        ಯದಿ (s1->verbose)
            printf("<- %s (%d symbol%s)\n", buf, sym_ಎಣಿಕೆ, &"s"[sym_ಎಣಿಕೆ < 2]);
    }
#endif

    ಪ್ರತಿ (ord = 0; ord < sym_ಎಣಿಕೆ; ++ord)
    {
        p = sorted[ord], sym_index = p->index, name = p->name;
        /* insert actual address later in relocate_sections() */
        put_elf_reloc(symtab_section, pe->thunk,
            func_o, R_XXX_RELATIVE, sym_index);
        *(DWORD*)(pe->thunk->data + name_o)
            = pe->thunk->data_offset + rva_base;
        *(WORD*)(pe->thunk->data + ord_o)
            = ord;
        put_elf_str(pe->thunk, name);
        func_o += ಪರಿಮಾಣ (DWORD);
        name_o += ಪರಿಮಾಣ (DWORD);
        ord_o += ಪರಿಮಾಣ (WORD);
        ಯದಿ (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = base_o + rva_base;
    pe->exp_size = pe->thunk->data_offset - base_o;
    dynarray_reset(&sorted, &sym_ಎಣಿಕೆ);
    ಯದಿ (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
ಸ್ಥಿರ ಶೂನ್ಯ pe_build_reloc (ಸಂರಚನಾ pe_info *pe)
{
    DWORD offset, block_ptr, sh_addr, addr;
    ಪೂರ್ಣಾಙ್ಕ ಎಣಿಕೆ_2, i;
    ElfW_Rel *rel, *rel_end;
    Section *s = ರಿಕ್ತ, *sr;
    ಸಂರಚನಾ pe_reloc_header *hdr;
    TCCState *s1 = pe->s1;
    ಪೂರ್ಣಾಙ್ಕ dwarf = 0, n;

    sh_addr = offset = block_ptr = ಎಣಿಕೆ_2 = i = 0;
    rel = rel_end = ರಿಕ್ತ;

    ಪ್ರತಿ(;;) {
        ಯದಿ (rel < rel_end) {
            ಪೂರ್ಣಾಙ್ಕ type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_offset + sh_addr;
            ++ rel;
            ಯದಿ (type != REL_TYPE_DIRECT)
                ಅನುವರ್ತ;
            ಯದಿ (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->data + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                ಯದಿ (n >= s1->dwlo && n < s1->dwhi)
                    ಅನುವರ್ತ;
            }
            ಯದಿ (ಎಣಿಕೆ_2 == 0) { /* new block */
                block_ptr = pe->reloc->data_offset;
                section_ptr_add(pe->reloc, ಪರಿಮಾಣ(ಸಂರಚನಾ pe_reloc_header));
                offset = addr & 0xFFFFFFFF<<12;
            }
            ಯದಿ ((addr -= offset)  < (1<<12)) { /* one block spans 4k addresses */
                WORD *wp = section_ptr_add(pe->reloc, ಪರಿಮಾಣ (WORD));
                *wp = addr | PE_IMAGE_REL<<12;
                ++ಎಣಿಕೆ_2;
                ಅನುವರ್ತ;
            }
            -- rel;

        } ಅನ್ಯಥಾ ಯದಿ (s) {
            sr = s->reloc;
            ಯದಿ (sr) {
                rel = (ElfW_Rel *)sr->data;
                rel_end = (ElfW_Rel *)(sr->data + sr->data_offset);
                sh_addr = s->sh_addr;
                dwarf = s->sh_ಅಂಕೆ >= s1->dwlo && s->sh_ಅಂಕೆ < s1->dwhi;
            }
            s = s->prev;
            ಅನುವರ್ತ;

        } ಅನ್ಯಥಾ ಯದಿ (i < pe->sec_ಎಣಿಕೆ) {
            s = pe->sec_info[i]->sec, ++i;
            ಅನುವರ್ತ;

        } ಅನ್ಯಥಾ ಯದಿ (!ಎಣಿಕೆ_2)
            ಭಙ್ಗ;

        /* fill the last block and ready for a new one */
        ಯದಿ (ಎಣಿಕೆ_2 & 1) /* align for DWORDS */
            section_ptr_add(pe->reloc, ಪರಿಮಾಣ(WORD)), ++ಎಣಿಕೆ_2;
        hdr = (ಸಂರಚನಾ pe_reloc_header *)(pe->reloc->data + block_ptr);
        hdr -> offset = offset - pe->imagebase;
        hdr -> size = ಎಣಿಕೆ_2 * ಪರಿಮಾಣ(WORD) + ಪರಿಮಾಣ(ಸಂರಚನಾ pe_reloc_header);
        ಎಣಿಕೆ_2 = 0;
    }
}

/* ------------------------------------------------------------- */
ಸ್ಥಿರ ಶೂನ್ಯ pe_build_tls(ಸಂರಚನಾ pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    ಪೂರ್ಣಾಙ್ಕ c, n;

    ಯದಿ (0 == s) {
        pe->tls_size = ಪರಿಮಾಣ (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_add(pe->thunk, pe->tls_size, 16);
        pe->tls_data = section_add(data_section, PTR_SIZE * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, data_section->sh_ಅಂಕೆ, 0);
        ಪ್ರತಿ (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_SIZE*n, REL_TYPE_DIRECT, c);
        /* for generators */
        set_elf_sym(symtab_section, pe->tls_data, PTR_SIZE * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, data_section->sh_ಅಂಕೆ, "__tls_index");
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (0 == s1->tls_start)
        s1->tls_start = s->sh_addr;
    d = (ಶೂನ್ಯ*)(pe->thunk->data + pe->tls_dir);
    d->StartAddressOfRawData = s1->tls_start - data_section->sh_addr;
    d->EndAddressOfRawData = s->sh_addr + s->data_offset - data_section->sh_addr;
    d->AddressOfIndex = pe->tls_data;
    d->AddressOfCallBacks = pe->tls_data + PTR_SIZE;
    d->SizeOfZeroFill = 0;
    d->Characteristics = 0;
    /* to reuse logic from linux in xxx-link.c */
    s1->tls_end = s1->tls_start;
}

/* ------------------------------------------------------------- */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pe_section_class(Section *s)
{
    ಪೂರ್ಣಾಙ್ಕ type, flags;
    ಧ್ರುವ ವರ್ಣ *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    ಯದಿ (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        ಪ್ರತ್ಯಾಗಮ sec_debug;
    } ಅನ್ಯಥಾ ಯದಿ (flags & SHF_ALLOC) {
        ಯದಿ (flags & SHF_TLS)
            ಪ್ರತ್ಯಾಗಮ sec_tdata + (type == SHT_NOBITS);
        ಯದಿ (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            ಯದಿ (flags & SHF_EXECINSTR)
                ಪ್ರತ್ಯಾಗಮ sec_text;
            ಯದಿ (flags & SHF_WRITE)
                ಪ್ರತ್ಯಾಗಮ sec_data;
            ಯದಿ (0 == strcmp(name, ".rsrc"))
                ಪ್ರತ್ಯಾಗಮ sec_rsrc;
            ಯದಿ (0 == strcmp(name, ".iedat"))
                ಪ್ರತ್ಯಾಗಮ sec_idata;
            ಯದಿ (0 == strcmp(name, ".pdata"))
                ಪ್ರತ್ಯಾಗಮ sec_pdata;
            ಪ್ರತ್ಯಾಗಮ sec_rdata;
        } ಅನ್ಯಥಾ ಯದಿ (type == SHT_NOBITS) {
            ಪ್ರತ್ಯಾಗಮ sec_bss;
        }
        ಪ್ರತ್ಯಾಗಮ sec_other;
    } ಅನ್ಯಥಾ {
        ಯದಿ (0 == strcmp(name, ".reloc"))
            ಪ್ರತ್ಯಾಗಮ sec_reloc;
    }
    ಪ್ರತ್ಯಾಗಮ sec_last;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pe_assign_addresses (ಸಂರಚನಾ pe_info *pe)
{
    ಪೂರ್ಣಾಙ್ಕ i, k, n, c, nbs;
    ADDR3264 addr;
    ಪೂರ್ಣಾಙ್ಕ *sec_order, *sec_cls;
    ಸಂರಚನಾ section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    ಯದಿ (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_order = tcc_mallocz(2 * ಪರಿಮಾಣ (ಪೂರ್ಣಾಙ್ಕ) * nbs);
    sec_cls = sec_order + nbs;
    ಪ್ರತಿ (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        ಪ್ರತಿ (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
        ಯದಿ ((s->sh_flags & SHF_TLS) && 0 == pe->tls_size)
            pe_build_tls(pe, ರಿಕ್ತ);
    }
    si = ರಿಕ್ತ;
    addr = pe->imagebase + 1;
    ಪ್ರತಿ (i = 1; (c = sec_cls[i]) < sec_last; ++i) {
        s = s1->sections[sec_order[i]];

        ಯದಿ (PE_MERGE_DATA && c == sec_bss)
            c = sec_data;
        ಯದಿ (c == sec_tbss)
            c = sec_tdata;

        ಯದಿ (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } ಅನ್ಯಥಾ {
            si = ರಿಕ್ತ;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        ಯದಿ (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        ಯದಿ (s == pe->reloc)
            pe_build_reloc (pe);

        ಯದಿ (0 == s->data_offset)
            ಅನುವರ್ತ;

        ಯದಿ (si)
            ಗಚ್ಛ add_section;

        si = tcc_mallocz(ಪರಿಮಾಣ *si);
        dynarray_add(&pe->sec_info, &pe->sec_ಎಣಿಕೆ, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        ಯದಿ (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_CODE;
        ಅನ್ಯಥಾ ಯದಿ (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_DATA;
        ಅನ್ಯಥಾ
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_DATA;
        ಯದಿ (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        ಯದಿ (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

add_section:
        s->sh_info = pe->sec_ಎಣಿಕೆ; /* section number for coff syms */
        addr += s->data_offset;
        si->sh_size = addr - si->sh_addr;
        ಯದಿ (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            ಯಾವತ್ (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = ರಿಕ್ತ;
            si->data_size = si->sh_size;
        }

        ಯದಿ (s->sh_flags & SHF_TLS) {
            strcpy(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#ಯದಿ 0
    ಪ್ರತಿ (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_order[i]];
        ಪೂರ್ಣಾಙ್ಕ type = s->sh_type;
        ಪೂರ್ಣಾಙ್ಕ flags = s->sh_flags;
        printf("section %-16s %-10s %p %04x %2d %s,%s,%s\n",
            s->name,
            type == SHT_PROGBITS ? "progbits" :
            type == SHT_INIT_ARRAY ? "initarr" :
            type == SHT_FINI_ARRAY ? "finiarr" :
            type == SHT_NOBITS ? "nobits" :
            type == SHT_SYMTAB ? "symtab" :
            type == SHT_STRTAB ? "strtab" :
            type == SHT_RELX ? "rel" : "???",
            s->sh_addr,
            (unsigned)s->data_offset,
            s->sh_addralign,
            flags & SHF_ALLOC ? "alloc" : "",
            flags & SHF_WRITE ? "write" : "",
            flags & SHF_EXECINSTR ? "exec" : ""
            );
        fflush(stdout);
    }
    s1->verbose = 2;
#endif
    tcc_free(sec_order);
    ಪ್ರತ್ಯಾಗಮ 0;
}

/*----------------------------------------------------------------------------*/
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pe_check_symbols(ಸಂರಚನಾ pe_info *pe)
{
    ಪೂರ್ಣಾಙ್ಕ sym_index, sym_end;
    ಪೂರ್ಣಾಙ್ಕ ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(text_section, 8);

    sym_end = symtab_section->data_offset / ಪರಿಮಾಣ(ElfW(Sym));
    ಪ್ರತಿ (sym_index = 1; sym_index < sym_end; ++sym_index) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
        ಯದಿ (sym->st_shndx == SHN_UNDEF) {
            ಧ್ರುವ ವರ್ಣ *name = (ವರ್ಣ*)symtab_section->link->data + sym->st_name;
            unsigned type = ELFW(ST_TYPE)(sym->st_info);
            ಪೂರ್ಣಾಙ್ಕ imp_sym = 0;
            ಸಂರಚನಾ import_ಚಿಹ್ನೆ *is;

            ಪೂರ್ಣಾಙ್ಕ _imp_, n;
            ವರ್ಣ buffer[200];
            ಧ್ರುವ ವರ್ಣ *s, *p;

            n = _imp_ = 0;
            ಯದಿ (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            ಕುರು {
                s = pe_export_name(s1, sym);
                ಯದಿ (n) {
                    /* second try: */
                    ಯದಿ (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        ಯದಿ (!p || s[0] != '_')
                            ಭಙ್ಗ;
                        strcpy(buffer, s+1)[p-s-1] = 0, s = buffer;
                    } ಅನ್ಯಥಾ ಯದಿ (s[0] != '_') { /* try non-ansi function */
                        buffer[0] = '_', strcpy(buffer + 1, s), s = buffer;
                    } ಅನ್ಯಥಾ ಯದಿ (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } ಅನ್ಯಥಾ ಯದಿ (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } ಅನ್ಯಥಾ {
                        ಭಙ್ಗ;
                    }
                }
                imp_sym = find_elf_sym(s1->dynsymtab_section, s);
            } ಯಾವತ್ (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            ಯದಿ (0 == imp_sym)
                ಅನುವರ್ತ; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_add_import(pe, imp_sym);

            ಯದಿ (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                unsigned offset = is->thk_offset;
                ಯದಿ (offset) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } ಅನ್ಯಥಾ {
                    unsigned ವರ್ಣ *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(buffer, "IAT.%s", name);
                    is->iat_index = put_elf_sym(
                        symtab_section, 0, ಪರಿಮಾಣ(DWORD),
                        ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT),
                        0, SHN_UNDEF, buffer);

                    offset = text_section->data_offset;
                    is->thk_offset = offset;

                    /* add the 'jmp IAT[x]' instruction */
#ifdef TCC_TARGET_ARM
                    p = section_ptr_add(text_section, 8+4); // room for code and address
                    write32le(p + 0, 0xE59FC000); // arm code ldr ip, [pc] ; PC+8+0 = 0001xxxx
                    write32le(p + 4, 0xE59CF000); // arm code ldr pc, [ip]
                    put_elf_reloc(symtab_section, text_section,
                        offset + 8, R_XXX_THUNKFIX, is->iat_index); // offset to IAT position
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_ARM64)
                    p = section_ptr_add(text_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, text_section,
                        offset + 16, R_XXX_THUNKFIX, is->iat_index);
#ಅನ್ಯಥಾ
                    p = section_ptr_add(text_section, 8);
                    write16le(p, 0x25FF);
#ifdef TCC_TARGET_X86_64
                    write32le(p + 2, (DWORD)-4);
#endif
                    put_elf_reloc(symtab_section, text_section, 
                        offset + 2, R_XXX_THUNKFIX, is->iat_index);
#endif
                }
                /* tcc_realloc might have altered sym's address */
                sym = (ElfW(Sym) *)symtab_section->data + sym_index;
                /* patch the original symbol */
                sym->st_ಮೌಲ್ಯ = offset;
                sym->st_shndx = text_section->sh_ಅಂಕೆ;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } ಅನ್ಯಥಾ { /* STT_OBJECT */
                ಯದಿ (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_ಮೌಲ್ಯ = is->iat_index; /* chain potential alias */
                is->iat_index = sym_index;
            }

        } ಅನ್ಯಥಾ ಯದಿ (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    ಪ್ರತ್ಯಾಗಮ ret;
}

/*----------------------------------------------------------------------------*/
#ಯದಿ PE_PRINT_SECTIONS
ಸ್ಥಿರ ಶೂನ್ಯ pe_print_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    ಪೂರ್ಣಾಙ್ಕ i, n, l, m;
    p = s->data;
    e = s->data + s->data_offset;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    ಯದಿ (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    ಯದಿ (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (unsigned)s->sh_addr);
    fprintf(f, "\ncontents %08X", (unsigned)l);
    fprintf(f, "\n\n");

    ಯದಿ (s->sh_type == SHT_NOBITS)
        ಪ್ರತ್ಯಾಗಮ;

    ಯದಿ (0 == l)
        ಪ್ರತ್ಯಾಗಮ;

    ಯದಿ (s->sh_type == SHT_SYMTAB)
        m = ಪರಿಮಾಣ(ElfW(Sym));
    ಅನ್ಯಥಾ ಯದಿ (s->sh_type == SHT_RELX)
        m = ಪರಿಮಾಣ(ElfW_Rel);
    ಅನ್ಯಥಾ
        m = 16;

    fprintf(f, "%-8s", "offset");
    ಪ್ರತಿ (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    ಯದಿ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        ಧ್ರುವ ವರ್ಣ *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            ರಿಕ್ತ
        };

        ಧ್ರುವ ವರ್ಣ *fields2[] = {
            "offs",
            "type",
            "symb",
            ರಿಕ್ತ
        };

        ಧ್ರುವ ವರ್ಣ **p;

        ಯದಿ (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        ಅನ್ಯಥಾ
            p = fields2, n = 58;

        ಪ್ರತಿ (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    ಪ್ರತಿ (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    ಪ್ರತಿ (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        ಪ್ರತಿ (n = 0; n < m; ++n) {
            ಯದಿ (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            ಅನ್ಯಥಾ
                fprintf(f, "   ");
        }

        ಯದಿ (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            ಧ್ರುವ ವರ್ಣ *name = s->link->data + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (unsigned)sym->st_name,
                    (unsigned)sym->st_ಮೌಲ್ಯ,
                    (unsigned)sym->st_size,
                    (unsigned)ELFW(ST_BIND)(sym->st_info),
                    (unsigned)ELFW(ST_TYPE)(sym->st_info),
                    (unsigned)sym->st_other,
                    (unsigned)sym->st_shndx,
                    name);

        } ಅನ್ಯಥಾ ಯದಿ (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->data + ELFW(R_SYM)(rel->r_info);
            ಧ್ರುವ ವರ್ಣ *name = s->link->link->data + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (unsigned)rel->r_offset,
                    (unsigned)ELFW(R_TYPE)(rel->r_info),
                    (unsigned)ELFW(R_SYM)(rel->r_info),
                    name);
        } ಅನ್ಯಥಾ {
            fprintf(f, "   ");
            ಪ್ರತಿ (n = 0; n < m; ++n) {
                ಯದಿ (n + i < l) {
                    b = p[i + n];
                    ಯದಿ (b < 32 || b >= 127)
                        b = '.';
                    fprintf(f, "%c", b);
                }
            }
        }
        i += m;
        fprintf(f, "\n");
    }
    fprintf(f, "\n\n");
}

ಸ್ಥಿರ ಶೂನ್ಯ pe_print_sections(TCCState *s1, ಧ್ರುವ ವರ್ಣ *fname)
{
    Section *s;
    FILE *f;
    ಪೂರ್ಣಾಙ್ಕ i;
    f = fopen(fname, "w");
    ಪ್ರತಿ (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    fclose(f);
}
#endif

/* ------------------------------------------------------------- */

ST_FUNC ಪೂರ್ಣಾಙ್ಕ pe_putimport(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ dllindex, ಧ್ರುವ ವರ್ಣ *name, addr_t ಮೌಲ್ಯ)
{
    ಪ್ರತ್ಯಾಗಮ set_elf_sym(
        s1->dynsymtab_section,
        ಮೌಲ್ಯ,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        ಮೌಲ್ಯ ? SHN_ABS : SHN_UNDEF,
        name
        );
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ read_mem(ಪೂರ್ಣಾಙ್ಕ fd, unsigned offset, ಶೂನ್ಯ *buffer, unsigned len)
{
    lseek(fd, offset, SEEK_SET);
    ಪ್ರತ್ಯಾಗಮ len == ಪಠ(fd, buffer, len);
}

/* ------------------------------------------------------------- */

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ get_dllexports(ಪೂರ್ಣಾಙ್ಕ fd, ವರ್ಣ **pp)
{
    ಪೂರ್ಣಾಙ್ಕ i, k, l, n, n0, ret;
    ವರ್ಣ *p;

    IMAGE_SECTION_HEADER ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_HEADER dh;
    IMAGE_FILE_HEADER ih;
    DWORD sig, ref, addr;
    DWORD *namep = ರಿಕ್ತ, p0 = 0, p1;

    ಪೂರ್ಣಾಙ್ಕ pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = ರಿಕ್ತ;
    ret = 1;
    ಯದಿ (!read_mem(fd, 0, &dh, ಪರಿಮಾಣ dh))
        ಗಚ್ಛ the_end;
    ಯದಿ (!read_mem(fd, dh.e_lfanew, &sig, ಪರಿಮಾಣ sig))
        ಗಚ್ಛ the_end;
    ಯದಿ (sig != 0x00004550)
        ಗಚ್ಛ the_end;
    pef_hdroffset = dh.e_lfanew + ಪರಿಮಾಣ sig;
    ಯದಿ (!read_mem(fd, pef_hdroffset, &ih, ಪರಿಮಾಣ ih))
        ಗಚ್ಛ the_end;
    opt_hdroffset = pef_hdroffset + ಪರಿಮಾಣ ih;
    ಯದಿ (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + ಪರಿಮಾಣ oh;
        ಯದಿ (!read_mem(fd, opt_hdroffset, &oh, ಪರಿಮಾಣ oh))
            ಗಚ್ಛ the_end;
        ಯದಿ (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.ಸಂಖ್ಯೆ_Of_Rva_And_Sizes)
            ಗಚ್ಛ the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } ಅನ್ಯಥಾ ಯದಿ (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + ಪರಿಮಾಣ oh;
        ಯದಿ (!read_mem(fd, opt_hdroffset, &oh, ಪರಿಮಾಣ oh))
            ಗಚ್ಛ the_end;
        ಯದಿ (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.ಸಂಖ್ಯೆ_Of_Rva_And_Sizes)
            ಗಚ್ಛ the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } ಅನ್ಯಥಾ
        ಗಚ್ಛ the_end;

    //printf("addr: %08x\n", addr);
    ಪ್ರತಿ (i = 0; i < ih.ಸಂಖ್ಯೆ_Of_Sections; ++i) {
        ಯದಿ (!read_mem(fd, sec_hdroffset + i * ಪರಿಮಾಣ ish, &ish, ಪರಿಮಾಣ ish))
            ಗಚ್ಛ the_end;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        ಯದಿ (addr >= ish.VirtualAddress && addr < ish.VirtualAddress + ish.SizeOfRawData)
            ಗಚ್ಛ found;
    }
    ಗಚ್ಛ the_end_0;
found:
    ref = ish.VirtualAddress - ish.PointerToRawData;
    ಯದಿ (!read_mem(fd, addr - ref, &ied, ಪರಿಮಾಣ ied))
        ಗಚ್ಛ the_end;
    k = ied.ಸಂಖ್ಯೆ_Of_Names;
    ಯದಿ (k) {
        namep = tcc_malloc(l = k * ಪರಿಮಾಣ *namep);
        ಯದಿ (!read_mem(fd, ied.AddressOfNames - ref, namep, l))
            ಗಚ್ಛ the_end;
        ಪ್ರತಿ (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            ಯದಿ (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            ಕುರು {
                ಯದಿ (0 == l) {
                    ಯದಿ (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    ಯದಿ ((l = ಪಠ(fd, p + n, 1000 - 1)) <= 0)
                        ಗಚ್ಛ the_end;
                }
                --l, ++p0;
            } ಯಾವತ್ (p[n++]);
        }
        p[n] = 0;
    }
the_end_0:
    ret = 0;
the_end:
    tcc_free(namep);
    ಯದಿ (ret && p)
        tcc_free(p), p = ರಿಕ್ತ;
    *pp = p;
    ಪ್ರತ್ಯಾಗಮ ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pe_load_res(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd)
{
    ಸಂರಚನಾ pe_rsrc_header hdr;
    Section *rsrc_section;
    ಪೂರ್ಣಾಙ್ಕ i, ret = -1, sym_index;
    BYTE *ptr;
    unsigned offs;

    ಯದಿ (!read_mem(fd, 0, &hdr, ಪರಿಮಾಣ hdr))
        ಗಚ್ಛ quit;

    ಯದಿ (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.ಸಂಖ್ಯೆ_Of_Sections != 1
        || strcmp((ವರ್ಣ*)hdr.sectionhdr.Name, ".rsrc") != 0)
        ಗಚ್ಛ quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_add(rsrc_section, hdr.sectionhdr.SizeOfRawData);
    offs = hdr.sectionhdr.PointerToRawData;
    ಯದಿ (!read_mem(fd, offs, ptr, hdr.sectionhdr.SizeOfRawData))
        ಗಚ್ಛ quit;
    offs = hdr.sectionhdr.PointerToRelocations;
    sym_index = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_ಅಂಕೆ, ".rsrc");
    ಪ್ರತಿ (i = 0; i < hdr.sectionhdr.ಸಂಖ್ಯೆ_Of_Relocations; ++i) {
        ಸಂರಚನಾ pe_rsrc_reloc rel;
        ಯದಿ (!read_mem(fd, offs, &rel, ಪರಿಮಾಣ rel))
            ಗಚ್ಛ quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        ಯದಿ (rel.type != RSRC_RELTYPE)
            ಗಚ್ಛ quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.offset, R_XXX_RELATIVE, sym_index);
        offs += ಪರಿಮಾಣ rel;
    }
    ret = 0;
quit:
    ಪ್ರತ್ಯಾಗಮ ret;
}

/* ------------------------------------------------------------- */

ಸ್ಥಿರ ವರ್ಣ *trimfront(ವರ್ಣ *p)
{
    ಯಾವತ್ ((unsigned ವರ್ಣ)*p <= ' ' && *p && *p != '\n')
	++p;
    ಪ್ರತ್ಯಾಗಮ p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

ಸ್ಥಿರ ವರ್ಣ *get_token(ವರ್ಣ **s, ವರ್ಣ *f)
{
    ವರ್ಣ *p, *e;
    ಪೂರ್ಣಾಙ್ಕ q;

    p = trimfront(*s);
    q = *p;
    ಯದಿ (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    ಅನ್ಯಥಾ
        q = ' ';
    ಪ್ರತಿ (e = p; (unsigned ವರ್ಣ)*e >= ' ' && *e != q; ++e)
        ;
    ಯದಿ (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    ಪ್ರತ್ಯಾಗಮ p;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pe_load_def(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd)
{
    ಪೂರ್ಣಾಙ್ಕ state = 0, ret = -1, dllindex = 0, ord;
    ವರ್ಣ dllname[80], *buf, *ಸಾಲು, *p, *x, next;

    buf = tcc_load_text(fd);
    ಯದಿ (!buf)
        ಪ್ರತ್ಯಾಗಮ ret;

    ಪ್ರತಿ (ಸಾಲು = buf;; ++ಸಾಲು)  {
        p = get_token(&ಸಾಲು, &next);
        ಯದಿ (!(*p && *p != ';'))
            ಗಚ್ಛ skip;
        ವಿಕಲ್ಪ (state) {
        ಪಕ್ಷ 0:
            ಯದಿ (0 != stricmp(p, "LIBRARY") || next == '\n')
                ಗಚ್ಛ quit;
            pstrcpy(dllname, ಪರಿಮಾಣ dllname, get_token(&ಸಾಲು, &next));
            ಯದಿ (!*tcc_fileextension(dllname))
                pstrcat(dllname, ಪರಿಮಾಣ dllname, ".dll");
            ++state;
            ಭಙ್ಗ;
        ಪಕ್ಷ 1:
            ಯದಿ (0 != stricmp(p, "EXPORTS"))
                ಗಚ್ಛ quit;
            ++state;
            ಭಙ್ಗ;
        ಪಕ್ಷ 2:
            dllindex = tcc_add_dllref(s1, dllname, 0)->index;
            ++state;
            /* fall through */
        ಸ್ವಭಾವ:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            ಯದಿ (next == '@') {
                x = get_token(&ಸಾಲು, &next);
                ord = (ಪೂರ್ಣಾಙ್ಕ)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            ಭಙ್ಗ;
        }
skip:
        ಯಾವತ್ ((unsigned ವರ್ಣ)next > ' ')
            get_token(&ಸಾಲು, &next);
        ಯದಿ (next != '\n')
            ಭಙ್ಗ;
    }
    ret = 0;
quit:
    tcc_free(buf);
    ಪ್ರತ್ಯಾಗಮ ret;
}

/* ------------------------------------------------------------- */

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pe_load_dll(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd, ಧ್ರುವ ವರ್ಣ *filename)
{
    ವರ್ಣ *p, *q;
    DLLReference *ref = tcc_add_dllref(s1, filename, 0);
    ಯದಿ (ref->found)
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ (get_dllexports(fd, &p))
        ಪ್ರತ್ಯಾಗಮ -1;
    ಯದಿ (p) {
        ಪ್ರತಿ (q = p; *q; q += 1 + strlen(q))
            pe_putimport(s1, ref->index, q, 0);
        tcc_free(p);
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ pe_load_file(ಸಂರಚನಾ TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd, ಧ್ರುವ ವರ್ಣ *filename)
{
    ಪೂರ್ಣಾಙ್ಕ ret = -1;
    ವರ್ಣ buf[10];
    ಯದಿ (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_load_def(s1, fd);
    ಅನ್ಯಥಾ ಯದಿ (pe_load_res(s1, fd) == 0)
        ret = 0;
    ಅನ್ಯಥಾ ಯದಿ (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_load_dll(s1, fd, filename);
    ಪ್ರತ್ಯಾಗಮ ret;
}

PUB_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_get_dllexports(ಧ್ರುವ ವರ್ಣ *filename, ವರ್ಣ **pp)
{
    ಪೂರ್ಣಾಙ್ಕ ret, fd = open(filename, O_RDONLY | O_ದ್ವಿಮಾನ_2);
    ಯದಿ (fd < 0)
        ಪ್ರತ್ಯಾಗಮ -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    ಪ್ರತ್ಯಾಗಮ ret;
}

/* ------------------------------------------------------------- */
#ifdef TCC_TARGET_X86_64
ಸ್ಥಿರ unsigned pe_add_unwind_info(TCCState *s1)
{
    ಯದಿ (ರಿಕ್ತ == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    ಯದಿ (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, text_section->sh_ಅಂಕೆ, ".uw_base");
    ಯದಿ (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        ಸ್ಥಿರ ಧ್ರುವ unsigned ವರ್ಣ uw_info[] = {
            0x01, // UBYTE: 3 Version , UBYTE: 5 Flags
            0x04, // UBYTE Size of prolog
            0x02, // UBYTE Count of unwind codes
            0x05, // UBYTE: 4 Frame Register (rbp), UBYTE: 4 Frame Register offset (scaled)
            // USHORT * n Unwind codes array (descending order)
            // 0x0b, 0x01, 0xff, 0xff, // stack size
            // UBYTE offset of end of instr in prolog + 1, UBYTE:4 operation, UBYTE:4 info
            0x04, 0x03, // 3:0 UWOP_SET_FPREG (mov rsp -> rbp)
            0x01, 0x50, // 0:5 UWOP_PUSH_NONVOL (push rbp)
        };

        Section *s = text_section;
        unsigned ವರ್ಣ *p;

        section_ptr_add(s, -s->data_offset & 3); /* align */
        s1->uw_offs = s->data_offset;
        p = section_ptr_add(s, ಪರಿಮಾಣ uw_info);
        memcpy(p, uw_info, ಪರಿಮಾಣ uw_info);
    }

    ಪ್ರತ್ಯಾಗಮ s1->uw_offs;
}

ST_FUNC ಶೂನ್ಯ pe_add_unwind_data(unsigned start, unsigned end, unsigned ರಾಶಿ)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    unsigned o, n, d;
    ಸಂರಚನಾ /* _RUNTIME_FUNCTION */ {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD UnwindData;
    } *p;

    d = pe_add_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->data_offset;
    p = section_ptr_add(pd, ಪರಿಮಾಣ *p);

    /* record this function */
    p->BeginAddress = start;
    p->EndAddress = end;
    p->UnwindData = d;

    /* put relocations on it */
    ಪ್ರತಿ (n = o + ಪರಿಮಾಣ *p; o < n; o += ಪರಿಮಾಣ p->BeginAddress)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
ಸ್ಥಿರ Section *pe_add_unwind_info(TCCState *s1)
{
    Section *s;

    ಯದಿ (ರಿಕ್ತ == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = find_section(s1, ".xdata");
    s->sh_addralign = 4;
    ಯದಿ (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  text_section->sh_ಅಂಕೆ, ".uw_text_base");
    ಯದಿ (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_ಅಂಕೆ, ".uw_base");
    ಪ್ರತ್ಯಾಗಮ s;
}

ST_FUNC ಶೂನ್ಯ pe_add_unwind_data(unsigned start, unsigned end, unsigned ರಾಶಿ)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    unsigned o, d, code_bytes, func_len;
    unsigned ವರ್ಣ *q;
    uint32_t header;
    ಸಂರಚನಾ /* _RUNTIME_FUNCTION */ {
        DWORD BeginAddress;
        DWORD UnwindData;
    } *p;

    ಪೂರ್ಣಾಙ್ಕ epilog;

    xd = pe_add_unwind_info(s1);
    pd = s1->uw_pdata;

    func_len = (end - start) >> 2;
    code_bytes = 0;
    epilog = code_bytes;
    code_bytes += 3; /* set_fp, save_fplr_x, end */
    code_bytes = (code_bytes + 3) & ~3;

    section_ptr_add(xd, -xd->data_offset & 3);
    d = xd->data_offset;
    q = section_ptr_add(xd, 4 + code_bytes);

    /* Full ARM64 xdata header: E=1 with one epilog and no exception handler. */
    header = (func_len & 0x3ffff)
        | 1 << 21
        | (epilog & 0x1F) << 22
        | (code_bytes >> 2) << 27
        ;
    write32le(q, header);
    q += 4;
    *q++ = 0xE1; /* set_fp */
    *q++ = 0x9B; /* save_fplr_x: stp x29,lr,[sp,#-224]! */
    *q++ = 0xE4; /* end */
    ಯಾವತ್ ((unsigned)(q - (xd->data + d + 4)) < code_bytes)
        *q++ = 0xE3; /* nop padding */

    o = pd->data_offset;
    p = section_ptr_add(pd, ಪರಿಮಾಣ *p);
    p->BeginAddress = start;
    p->UnwindData = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#endif
/* ------------------------------------------------------------- */
#ಯದಿ defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
#define PE_STDSYM(n,s) n
#ಅನ್ಯಥಾ
#define PE_STDSYM(n,s) "_" n s
#endif

ಸ್ಥಿರ ಶೂನ್ಯ pe_add_runtime(TCCState *s1, ಸಂರಚನಾ pe_info *pe)
{
    ಧ್ರುವ ವರ್ಣ *start_ಚಿಹ್ನೆ;
    ಪೂರ್ಣಾಙ್ಕ pe_type;

    ಯದಿ (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        start_ಚಿಹ್ನೆ = PE_STDSYM("__dllstart","@12");
    } ಅನ್ಯಥಾ {
        ಧ್ರುವ ವರ್ಣ *run_ಚಿಹ್ನೆ;
        ಯದಿ (find_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            start_ಚಿಹ್ನೆ = "__winstart";
            run_ಚಿಹ್ನೆ = "__runwinmain";
            pe_type = PE_GUI;
        } ಅನ್ಯಥಾ ಯದಿ (find_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            start_ಚಿಹ್ನೆ = "__wwinstart";
            run_ಚಿಹ್ನೆ = "__runwwinmain";
            pe_type = PE_GUI;
        } ಅನ್ಯಥಾ ಯದಿ (find_elf_sym(symtab_section, "wmain")) {
            start_ಚಿಹ್ನೆ = "__wstart";
            run_ಚಿಹ್ನೆ = "__runwmain";
            pe_type = PE_EXE;
        } ಅನ್ಯಥಾ {
            start_ಚಿಹ್ನೆ =  "__start";
            run_ಚಿಹ್ನೆ = "__runmain";
            pe_type = PE_EXE;
            ಯದಿ (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        ಯದಿ (TCC_OUTPUT_MEMORY == s1->output_type && !s1->nostdlib)
            start_ಚಿಹ್ನೆ = run_ಚಿಹ್ನೆ;
    }
    ಯದಿ (s1->elf_entryname) {
        pe->start_ಚಿಹ್ನೆ = start_ಚಿಹ್ನೆ = s1->elf_entryname;
    } ಅನ್ಯಥಾ {
        pe->start_ಚಿಹ್ನೆ = start_ಚಿಹ್ನೆ + 1;
        ಯದಿ (!s1->leading_underscore || strchr(start_ಚಿಹ್ನೆ, '@'))
            ++start_ಚಿಹ್ನೆ;
    }

#ifdef CONFIG_TCC_BACKTRACE
    ಯದಿ (s1->do_backtrace) {
#ifdef CONFIG_TCC_BCHECK
        ಯದಿ (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    ಯದಿ (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    ಅನ್ಯಥಾ
                tcc_add_support(s1, "bcheck.o");
	}
#endif
        ಯದಿ (s1->output_type == TCC_OUTPUT_EXE)
            tcc_add_support(s1, "bt-exe.o");
        ಯದಿ (s1->output_type == TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-dll.o");
        ಯದಿ (s1->output_type != TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-log.o");
        tcc_add_btstub(s1);
    }
#endif

    /* grab the startup code from libtcc1.a */
#ifdef TCC_IS_NATIVE
    ಯದಿ (TCC_OUTPUT_MEMORY != s1->output_type || s1->run_main)
#endif
    set_global_sym(s1, start_ಚಿಹ್ನೆ, ರಿಕ್ತ, 0);

    ಯದಿ (0 == s1->nostdlib) {
        ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ * ಧ್ರುವ libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", ರಿಕ್ತ
        };
        ಧ್ರುವ ವರ್ಣ * ಧ್ರುವ *pp, *p;
        ಯದಿ (TCC_LIBTCC1[0])
            tcc_add_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        ಪ್ರತಿ (pp = libs; 0 != (p = *pp); ++pp) {
            ಯದಿ (*p)
                tcc_add_library(s1, p);
            ಅನ್ಯಥಾ ಯದಿ (PE_DLL != pe_type && PE_GUI != pe_type)
                ಭಙ್ಗ;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    ಯದಿ (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    ಯದಿ (TCC_OUTPUT_MEMORY == s1->output_type)
        pe_type = PE_RUN;
    pe->type = pe_type;
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ pe_setsubsy(TCCState *s1, ಧ್ರುವ ವರ್ಣ *arg)
{
    ಸ್ಥಿರ ಧ್ರುವ ಸಂರಚನಾ subsy { ಧ್ರುವ ವರ್ಣ* p; ಪೂರ್ಣಾಙ್ಕ v; } x[] = {
#ಯದಿ defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_ARM)
        { "wince", 9 },
#endif
        { 0, -1 }};
    ಧ್ರುವ ಸಂರಚನಾ subsy *y;
    ಪ್ರತಿ (y = x;; ++y) {
        ಯದಿ (!y->p)
            ಪ್ರತ್ಯಾಗಮ -1;
        ಯದಿ (0 == strcmp(y->p, arg)) {
            s1->pe_subsystem = y->v;
            ಪ್ರತ್ಯಾಗಮ 0;
        }
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ pe_set_options(TCCState * s1, ಸಂರಚನಾ pe_info *pe)
{
    ಯದಿ (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_BASE_DLL;
    } ಅನ್ಯಥಾ {
        pe->imagebase = IMAGE_BASE_EXE;
    }

#ಯದಿ defined(TCC_TARGET_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#ಅನ್ಯಥಾ
    ಯದಿ (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    ಅನ್ಯಥಾ
        pe->subsystem = 3;
#endif
    /* Allow override via -Wl,-subsystem=... option */
    ಯದಿ (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    ಯದಿ (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } ಅನ್ಯಥಾ {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    ಯದಿ (s1->section_align != 0)
        pe->section_align = s1->section_align;
    ಯದಿ (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    ಯದಿ ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    ಯದಿ (s1->has_text_addr)
        pe->imagebase = s1->text_addr;
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ pe_output_file(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename)
{
    ಸಂರಚನಾ pe_info pe;

    memset(&pe, 0, ಪರಿಮಾಣ pe);
    pe.filename = filename;
    pe.s1 = s1;
    s1->filetype = 0;

#ifdef CONFIG_TCC_BCHECK
    tcc_add_bcheck(s1);
#endif
    tcc_add_pragma_libs(s1);
    pe_add_runtime(s1, &pe);
    resolve_common_syms(s1);
    pe_set_options(s1, &pe);
    pe_check_symbols(&pe);
    ಯದಿ (s1->nb_errors)
        ಗಚ್ಛ done;
    ಯದಿ (filename) {
        pe_assign_addresses(&pe);
        relocate_syms(s1, s1->symtab, 0);
        ಯದಿ (s1->nb_errors)
            ಗಚ್ಛ done;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.start_addr = (DWORD)
            (get_sym_addr(s1, pe.start_ಚಿಹ್ನೆ, 1, 1) - pe.imagebase);
        ಯದಿ (s1->nb_errors)
            ಗಚ್ಛ done;
        pe_write(&pe);
    } ಅನ್ಯಥಾ {
        /* -run */
#ifdef TCC_IS_NATIVE
        pe.thunk = data_section;
        pe_build_imports(&pe);
        s1->run_main = pe.start_ಚಿಹ್ನೆ;
#ಯದಿ defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        s1->uw_pdata = find_section(s1, ".pdata");
#endif
#endif
    }
done:
    dynarray_reset(&pe.sec_info, &pe.sec_ಎಣಿಕೆ);
    pe_free_imports(&pe);
#ಯದಿ PE_PRINT_SECTIONS
    ಯದಿ (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#endif
    ಪ್ರತ್ಯಾಗಮ s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
