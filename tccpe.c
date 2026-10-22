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

#ଅନ୍ତର୍ଭାଵ "tcc.h"

#define PE_MERGE_DATA 1
#define PE_PRINT_SECTIONS 0

#ifndef _WIN32
#define stricmp strcasecmp
#define strnicmp strncasecmp
#ଅନ୍ତର୍ଭାଵ <sys/stat.h> /* chmod() */
#endif

#ଯଦି defined TCC_TARGET_X86_64
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

#ନଚେତଯଦି defined TCC_TARGET_ARM
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

#ନଚେତଯଦି defined TCC_TARGET_ARM64
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

#ନଚେତଯଦି defined TCC_TARGET_I386
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

#ଯଦି PTR_SIZE == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#ଅନ୍ୟଥା
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#endif

#ifndef IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ଅକ୍ଷର BYTE;
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned short WORD;
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା DWORD;
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned long long ULONGLONG;
#pragma pack(ଠେଲ, 1)

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _IMAGE_DOS_HEADER {  /* DOS .EXE header */
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

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    ସଂଖ୍ୟା_Of_Sections;
    DWORD   TimeDateStamp;
    DWORD   Pointer_To_ପ୍ରତୀକ_Table;
    DWORD   ସଂଖ୍ୟା_Of_Symbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;


#define IMAGE_SIZEOF_FILE_HEADER 20

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;


ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _IMAGE_OPTIONAL_HEADER {
    /* Standard fields. */
    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
#ଯଦି PTR_SIZE == 4
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
    DWORD   Win32_Version_ମୂଲ୍ୟ;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    ADDR3264 Size_Of_ଗଦା_Reserve;
    ADDR3264 Size_Of_ଗଦା_Commit;
    ADDR3264 SizeOfHeapReserve;
    ADDR3264 SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   ସଂଖ୍ୟା_Of_Rva_And_Sizes;
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

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _IMAGE_SECTION_HEADER {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    ସଂଘ {
            DWORD   PhysicalAddress;
            DWORD   VirtualSize;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   SizeOfRawData;
    DWORD   PointerToRawData;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    ସଂଖ୍ୟା_Of_Relocations;
    WORD    ସଂଖ୍ୟା_Of_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#define IMAGE_SIZEOF_SECTION_HEADER     40

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD Name;
    DWORD Base;
    DWORD ସଂଖ୍ୟା_Of_Functions;
    DWORD ସଂଖ୍ୟା_Of_Names;
    DWORD AddressOfFunctions;
    DWORD AddressOfNames;
    DWORD AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _IMAGE_TLS_DIRECTORY {
    ADDR3264 StartAddressOfRawData;
    ADDR3264 EndAddressOfRawData;
    ADDR3264 AddressOfIndex;
    ADDR3264 AddressOfCallBacks;
    DWORD SizeOfZeroFill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _IMAGE_IMPORT_DESCRIPTOR {
    ସଂଘ {
        DWORD Characteristics;
        DWORD OriginalFirstThunk;
    };
    DWORD TimeDateStamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   SizeOfBlock;
//  WORD    TypeOffset[1];
} IMAGE_BASE_RELOCATION;

#define IMAGE_SIZEOF_BASE_RELOCATION     8

#define IMAGE_REL_BASED_ABSOLUTE         0
#define IMAGE_REL_BASED_ଉପର             1
#define IMAGE_REL_BASED_ତଳ              2
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

#define IMAGE_DLLCHARACTERISTICS_ଉପର_ENTROPY_VA 0x0020
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#define IMAGE_FILE_RELOCS_STRIPPED 0x0001

#pragma pack(କାଢ଼)

/* ----------------------------------------------------------- */
#endif /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#ifndef IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#endif

#pragma pack(ଠେଲ, 1)
ସଂରଚନା pe_header
{
    IMAGE_DOS_HEADER doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_HEADER filehdr;
#ଯଦି PTR_SIZE == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#ଅନ୍ୟଥା
#ifdef _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#ଅନ୍ୟଥା
    IMAGE_OPTIONAL_HEADER opthdr;
#endif
#endif
};

ସଂରଚନା pe_reloc_header {
    DWORD offset;
    DWORD size;
};

ସଂରଚନା pe_rsrc_header {
    ସଂରଚନା _IMAGE_FILE_HEADER filehdr;
    ସଂରଚନା _IMAGE_SECTION_HEADER sectionhdr;
};

ସଂରଚନା pe_rsrc_reloc {
    DWORD offset;
    DWORD size;
    WORD type;
};
#pragma pack(କାଢ଼)

/* ------------------------------------------------------------- */
/* internal temporary structures */

ଗଣନା {
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

#ଯଦି 0
ସ୍ଥିର ଅଚଳ DWORD pe_sec_flags[] = {
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

ସଂରଚନା section_info {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା cls;
    ଅକ୍ଷର name[32];
    ADDR3264 sh_addr;
    DWORD sh_size;
    DWORD pe_flags;
    Section *sec;
    DWORD data_size;
    IMAGE_SECTION_HEADER ish;
};

ସଂରଚନା import_ପ୍ରତୀକ {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_index;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା iat_index;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା thk_offset;
};

ସଂରଚନା pe_import_info {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା dll_index;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_ଗଣନା;
    ସଂରଚନା import_ପ୍ରତୀକ **symbols;
};

ସଂରଚନା pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    ଅଚଳ ଅକ୍ଷର *filename;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    ଅଚଳ ଅକ୍ଷର *start_ପ୍ରତୀକ;
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
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା subsystem;
    DWORD section_align;
    DWORD file_align;
    ସଂରଚନା section_info **sec_info;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sec_ଗଣନା;
    ସଂରଚନା pe_import_info **imp_info;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା imp_ଗଣନା;
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

ସ୍ଥିର ଅଚଳ ଅକ୍ଷର *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    ଅଚଳ ଅକ୍ଷର *name = (ଅକ୍ଷର*)symtab_section->link->data + sym->st_name;
    ଯଦି (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        ଫେରନ୍ତୁ name + 1;
    ଫେରନ୍ତୁ name;
}


ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା dynarray_assoc(ଶୂନ୍ୟ **pp, ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଚାବି)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପାଇଁ (i = 0; i < n; ++i, ++pp)
    ଯଦି (ଚାବି == **(ପୂର୍ଣ୍ଣସଂଖ୍ୟା **) pp)
        ଫେରନ୍ତୁ i;
    ଫେରନ୍ତୁ -1;
}

ସ୍ଥିର DWORD umin(DWORD a, DWORD b)
{
    ଫେରନ୍ତୁ a < b ? a : b;
}

ସ୍ଥିର DWORD umax(DWORD a, DWORD b)
{
    ଫେରନ୍ତୁ a < b ? b : a;
}

ସ୍ଥିର DWORD pe_file_align(ସଂରଚନା pe_info *pe, DWORD n)
{
    ଫେରନ୍ତୁ (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

ସ୍ଥିର ADDR3264 pe_virtual_align(ସଂରଚନା pe_info *pe, ADDR3264 n)
{
    ଫେରନ୍ତୁ (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

ସ୍ଥିର ଶୂନ୍ୟ pe_align_section(Section *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା a)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = s->data_offset & (a-1);
    ଯଦି (i)
        section_ptr_add(s, a - i);
}

ସ୍ଥିର ଶୂନ୍ୟ pe_set_datadir(ସଂରଚନା pe_header *hdr, ପୂର୍ଣ୍ଣସଂଖ୍ୟା dir, DWORD addr, DWORD size)
{
    hdr->opthdr.DataDirectory[dir].VirtualAddress = addr;
    hdr->opthdr.DataDirectory[dir].Size = size;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_fwrite(ସଂରଚନା pe_info *pe, ଅଚଳ ଶୂନ୍ୟ *data, ପୂର୍ଣ୍ଣସଂଖ୍ୟା len)
{
    ଅଚଳ WORD *p = data;
    DWORD sum;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret, i;
    pe->pos += (ret = fwrite(data, 1, len, pe->op));
    sum = pe->sum;
    ପାଇଁ (i = len; i > 0; i -= 2) {
        sum += (i >= 2) ? *p++ : *(BYTE*)p;
        sum = (sum + (sum >> 16)) & 0xFFFF;
    }
    pe->sum = sum;
    ଫେରନ୍ତୁ len == ret ? 0 : -1;
}

ସ୍ଥିର ଶୂନ୍ୟ pe_fpad(ସଂରଚନା pe_info *pe, DWORD new_pos)
{
    ଅକ୍ଷର buf[256];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, diff = new_pos - pe->pos;
    memset(buf, 0, ଆକାର buf);
    ଯେତେବେଳେ (diff > 0) {
        diff -= n = umin(diff, ଆକାର buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#pragma pack(ଠେଲ, 1)
ସଂରଚନା syment
{
    ସଂଘ {
        ଅକ୍ଷର        n_name[8];     /* old COFF version */
        ସଂରଚନା {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_offset;      /* offset into string table */
        };
    };
    int32_t         n_ମୂଲ୍ୟ;        /* value of symbol */
    short           n_scnum;        /* section number */
    unsigned short  n_type;         /* type and derived type */
    ଅକ୍ଷର            n_sclass;       /* storage class */
    ଅକ୍ଷର            n_numaux;       /* number of aux. entries */
};
#pragma pack(କାଢ଼)

#define SHF_PRIVATE 0x80000000

ସ୍ଥିର ଶୂନ୍ୟ pe_add_coffsym(ସଂରଚନା pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    ସଂରଚନା syment *se;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n;

    ଯଦି (ଖାଲି == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_PRIVATE);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_PRIVATE);
        section_ptr_add(pe->coffstr, 4); /* coff string table size */
        ଫେରନ୍ତୁ;
    }

#ଯଦି 0
    se = section_ptr_add(pe->coffsym, ଆକାର *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_add(pe->coffsym, ଆକାର *se);
    strcpy((ଅକ୍ଷର*)se, "no-file");
#endif

#ଯଦି 1
    esym = (ElfSym*)s1->symtab->data;
    ପାଇଁ (n = s1->symtab->data_offset / ଆକାର *esym; ++esym, --n;) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_bind = ELFW(ST_BIND)(esym->st_info);
        ଯଦି (sym_bind == STB_GLOBAL) {
            ଅକ୍ଷର *name = esym->st_name + (ଅକ୍ଷର*)s1->symtab->link->data;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା nl = strlen(name);
            addr_t ମୂଲ୍ୟ = esym->st_ମୂଲ୍ୟ;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା shnum = esym->st_shndx;
            ଯଦି (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                ମୂଲ୍ୟ = ମୂଲ୍ୟ - s->sh_addr;
            }
            se = section_ptr_add(pe->coffsym, ଆକାର *se);
            se->n_ମୂଲ୍ୟ = ମୂଲ୍ୟ;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            ଯଦି (nl <= 8)
                memcpy(se->n_name, name, nl);
            ଅନ୍ୟଥା
                se->n_offset = put_elf_str(pe->coffstr, name);
        }
    }
#endif
    write32le(pe->coffstr->data, pe->coffstr->data_offset); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
ସ୍ଥିର ଶୂନ୍ୟ pe_create_pdb(TCCState *s1, ଅଚଳ ଅକ୍ଷର *exename)
{
    ଅକ୍ଷର buf[300]; ପୂର୍ଣ୍ଣସଂଖ୍ୟା r;
    snprintf(buf, ଆକାର buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    strcpy(tcc_fileextension(strcpy(buf, exename)), ".pdb");
    ଯଦି (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } ଅନ୍ୟଥା ଯଦି (s1->verbose) {
        printf("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_write(ସଂରଚନା pe_info *pe)
{
    ସ୍ଥିର ଅଚଳ ସଂରଚନା pe_header pe_template = {
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
#ଯଦି PTR_SIZE == 4
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

    ସଂରଚନା pe_header pe_header = pe_template;

    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    DWORD file_offset;
    ସଂରଚନା section_info *si;
    IMAGE_SECTION_HEADER *psh;
    TCCState *s1 = pe->s1;

    ଯଦି (s1->do_debug)
        pe_add_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    ଯଦି (ଖାଲି == pe->op)
        ଫେରନ୍ତୁ tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        ଆକାର (ସଂରଚନା pe_header)
        + pe->sec_ଗଣନା * ଆକାର (IMAGE_SECTION_HEADER)
        );

    file_offset = pe->sizeofheaders;

    ଯଦି (2 == s1->verbose)
        printf("-------------------------------"
               "\n  virt   file   size  section" "\n");
    ପାଇଁ (i = 0; i < pe->sec_ଗଣନା; ++i) {
        DWORD addr, size;
        ଅଚଳ ଅକ୍ଷର *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        size = si->sh_size;
        psh = &si->ish;

        ଯଦି (2 == s1->verbose)
            printf("%6x %6x %6x  %s\n",
                (unsigned)addr, (unsigned)file_offset, (unsigned)size, sh_name);

        ବାଛ (si->cls) {
            ସ୍ଥିତି sec_text:
                ଯଦି (!pe_header.opthdr.BaseOfCode)
                    pe_header.opthdr.BaseOfCode = addr;
                ଭାଙ୍ଗ;

            ସ୍ଥିତି sec_data:
#ଯଦି PTR_SIZE == 4
                ଯଦି (!pe_header.opthdr.BaseOfData)
                    pe_header.opthdr.BaseOfData = addr;
#endif
                ଭାଙ୍ଗ;

            ସ୍ଥିତି sec_bss:
                ଭାଙ୍ଗ;

            ସ୍ଥିତି sec_reloc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_BASERELOC, addr, size);
                ଭାଙ୍ଗ;

            ସ୍ଥିତି sec_rsrc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_RESOURCE, addr, size);
                ଭାଙ୍ଗ;

            ସ୍ଥିତି sec_pdata:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXCEPTION, addr, size);
                ଭାଙ୍ଗ;
        }

        ଯଦି (pe->imp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IMPORT,
                pe->imp_offs, pe->imp_size);
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IAT,
                pe->iat_offs, pe->iat_size);
        }
        ଯଦି (pe->exp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXPORT,
                pe->exp_offs, pe->exp_size);
        }
        ଯଦି (pe->tls_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_size);
        }

        memcpy(psh->Name, sh_name, umin(strlen(sh_name), ଆକାର psh->Name));
        ଯଦି (pe->coffstr && strlen(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((ଅକ୍ଷର*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->VirtualAddress = addr;
        psh->Misc.VirtualSize = size;
        pe_header.opthdr.SizeOfImage =
            umax(pe_virtual_align(pe, size + addr), pe_header.opthdr.SizeOfImage);

        ଯଦି (si->data_size) {
            psh->PointerToRawData = file_offset;
            file_offset = pe_file_align(pe, file_offset + si->data_size);
            psh->SizeOfRawData = file_offset - psh->PointerToRawData;
            ଯଦି (si->cls == sec_text)
                pe_header.opthdr.SizeOfCode += psh->SizeOfRawData;
            ଅନ୍ୟଥା
                pe_header.opthdr.SizeOfInitializedData += psh->SizeOfRawData;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_header.filehdr.ସଂଖ୍ୟା_Of_Sections = pe->sec_ଗଣନା;
    pe_header.opthdr.AddressOfEntryPoint = pe->start_addr;
    pe_header.opthdr.SizeOfHeaders = pe->sizeofheaders;
    pe_header.opthdr.ImageBase = pe->imagebase;
    pe_header.opthdr.Subsystem = pe->subsystem;
    pe_header.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    ଯଦି (s1->pe_ଗଦା_size)
        pe_header.opthdr.Size_Of_ଗଦା_Reserve = s1->pe_ଗଦା_size;
    ଯଦି (PE_DLL == pe->type)
        pe_header.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_header.filehdr.Characteristics |= s1->pe_characteristics;
    ଯଦି (pe->reloc)
        pe_header.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    ଯଦି (pe->coffsym) {
        pe_add_coffsym(pe);
        pe_header.filehdr.Pointer_To_ପ୍ରତୀକ_Table = file_offset;
        pe_header.filehdr.ସଂଖ୍ୟା_Of_Symbols
            = pe->coffsym->data_offset / ଆକାର (ସଂରଚନା syment);
    }

    pe_fwrite(pe, &pe_header, ଆକାର pe_header);
    ପାଇଁ (i = 0; i < pe->sec_ଗଣନା; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, ଆକାର(IMAGE_SECTION_HEADER));

    file_offset = pe->sizeofheaders;
    ପାଇଁ (i = 0; i < pe->sec_ଗଣନା; ++i) {
        Section *s;
        si = pe->sec_info[i];
        ଯଦି (!si->data_size)
            ଜାରି;
        ପାଇଁ (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_offset);
            pe_fwrite(pe, s->data, s->data_offset);
            ଯଦି (s->prev)
                file_offset += s->prev->sh_addr - s->sh_addr;
        }
        file_offset = si->ish.PointerToRawData + si->ish.SizeOfRawData;
        pe_fpad(pe, file_offset);
    }

    ଯଦି (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->data, pe->coffsym->data_offset);
        pe_fwrite(pe, pe->coffstr->data, pe->coffstr->data_offset);
        file_offset = pe->pos;
    }

    pe->sum += file_offset;
    fseek(pe->op, offsetof(ସଂରଚନା pe_header, opthdr.CheckSum), SEEK_SET);
    pe_fwrite(pe, &pe->sum, ଆକାର (DWORD));

    fclose (pe->op);
#ifndef _WIN32
    chmod(pe->filename, 0777);
#endif

    ଯଦି (2 == s1->verbose)
        printf("-------------------------------\n");
    ଯଦି (s1->verbose)
        printf("<- %s (%u bytes)\n", pe->filename, (unsigned)file_offset);

    ଯଦି (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    ଫେରନ୍ତୁ 0;
}

/*----------------------------------------------------------------------------*/

ସ୍ଥିର ସଂରଚନା import_ପ୍ରତୀକ *pe_add_import(ସଂରଚନା pe_info *pe, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_index)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା dll_index;
    ସଂରଚନା pe_import_info *p;
    ସଂରଚନା import_ପ୍ରତୀକ *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->data + sym_index;
    dll_index = isym->st_size;

    i = dynarray_assoc ((ଶୂନ୍ୟ**)pe->imp_info, pe->imp_ଗଣନା, dll_index);
    ଯଦି (-1 != i) {
        p = pe->imp_info[i];
        ଯାଅ found_dll;
    }
    p = tcc_mallocz(ଆକାର *p);
    p->dll_index = dll_index;
    dynarray_add(&pe->imp_info, &pe->imp_ଗଣନା, p);

found_dll:
    i = dynarray_assoc ((ଶୂନ୍ୟ**)p->symbols, p->sym_ଗଣନା, sym_index);
    ଯଦି (-1 != i)
        ଫେରନ୍ତୁ p->symbols[i];

    s = tcc_mallocz(ଆକାର *s);
    dynarray_add(&p->symbols, &p->sym_ଗଣନା, s);
    s->sym_index = sym_index;
    ଫେରନ୍ତୁ s;
}

ସ୍ଥିର ଶୂନ୍ୟ pe_free_imports(ସଂରଚନା pe_info *pe)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପାଇଁ (i = 0; i < pe->imp_ଗଣନା; ++i) {
        ସଂରଚନା pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_ଗଣନା);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_ଗଣନା);
}

/*----------------------------------------------------------------------------*/
ସ୍ଥିର ଶୂନ୍ୟ pe_build_imports(ସଂରଚନା pe_info *pe)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_base = pe->thunk->sh_addr - pe->imagebase;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ndlls = pe->imp_ଗଣନା;
    TCCState *s1 = pe->s1;

    ପାଇଁ (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_ଗଣନା;

    ଯଦି (0 == sym_cnt)
        ଫେରନ୍ତୁ;

    pe_align_section(pe->thunk, 16);
    pe->imp_size = (ndlls + 1) * ଆକାର(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_size = (sym_cnt + ndlls) * ଆକାର(ADDR3264);
    dll_ptr = pe->thunk->data_offset;
    thk_ptr = dll_ptr + pe->imp_size;
    ent_ptr = thk_ptr + pe->iat_size;
    pe->imp_offs = dll_ptr + rva_base;
    pe->iat_offs = thk_ptr + rva_base;
    section_ptr_add(pe->thunk, pe->imp_size + 2*pe->iat_size);

    ପାଇଁ (i = 0; i < pe->imp_ଗଣନା; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା k, n, dllindex;
        ADDR3264 v;
        ସଂରଚନା pe_import_info *p = pe->imp_info[i];
        ଅଚଳ ଅକ୍ଷର *name;
        DLLReference *dllref;

        dllindex = p->dll_index;
        ଯଦି (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        ଅନ୍ୟଥା
            name = "", dllref = ଖାଲି;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->data + dll_ptr);
        hdr->FirstThunk = thk_ptr + rva_base;
        hdr->OriginalFirstThunk = ent_ptr + rva_base;
        hdr->Name = v + rva_base;

        ପାଇଁ (k = 0, n = p->sym_ଗଣନା; k <= n; ++k) {
            ଯଦି (k < n) {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା iat_index = p->symbols[k]->iat_index;
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_index = p->symbols[k]->sym_index;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->data + sym_index;
                ଅଚଳ ଅକ୍ଷର *name = (ଅକ୍ଷର*)s1->dynsymtab_section->link->data + imp_sym->st_name;
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା ordinal;

                /* patch symbol (and possibly its underscored alias) */
                କର {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->data + iat_index;
                    iat_index = esym->st_ମୂଲ୍ୟ;
                    esym->st_ମୂଲ୍ୟ = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_ଅଙ୍କ;
                } ଯେତେବେଳେ (iat_index);

                ଯଦି (dllref)
                    v = 0, ordinal = imp_sym->st_ମୂଲ୍ୟ; /* ordinal from pe_load_def */
                ଅନ୍ୟଥା
                    ordinal = 0, v = imp_sym->st_ମୂଲ୍ୟ; /* address from tcc_add_symbol() */

#ifdef TCC_IS_NATIVE
                ଯଦି (pe->type == PE_RUN) {
                    ଯଦି (dllref) {
                        ଯଦି ( !dllref->handle )
                            dllref->handle = LoadLibraryA(dllref->name);
                        v = (ADDR3264)GetProcAddress(dllref->handle, ordinal?(ଅକ୍ଷର*)0+ordinal:name);
                    }
                    ଯଦି (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } ଅନ୍ୟଥା
#endif
                ଯଦି (ordinal) {
                    v = ordinal | (ADDR3264)1 << (ଆକାର(ADDR3264)*8 - 1);
                } ଅନ୍ୟଥା {
                    v = pe->thunk->data_offset + rva_base;
                    section_ptr_add(pe->thunk, ଆକାର(WORD)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } ଅନ୍ୟଥା {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->data+thk_ptr) =
            *(ADDR3264*)(pe->thunk->data+ent_ptr) = v;
            thk_ptr += ଆକାର (ADDR3264);
            ent_ptr += ଆକାର (ADDR3264);
        }
        dll_ptr += ଆକାର(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

ସଂରଚନା pe_sort_sym
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା index;
    ଅଚଳ ଅକ୍ଷର *name;
};

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_cmp(ଅଚଳ ଶୂନ୍ୟ *va, ଅଚଳ ଶୂନ୍ୟ *vb)
{
    ଅଚଳ ଅକ୍ଷର *ca = (*(ସଂରଚନା pe_sort_sym**)va)->name;
    ଅଚଳ ଅକ୍ଷର *cb = (*(ସଂରଚନା pe_sort_sym**)vb)->name;
    ଫେରନ୍ତୁ strcmp(ca, cb);
}

ସ୍ଥିର ଶୂନ୍ୟ pe_build_exports(ସଂରଚନା pe_info *pe)
{
    ElfW(Sym) *sym;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_index, sym_end;
    DWORD rva_base, base_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_ଗଣନା, ord;
    ସଂରଚନା pe_sort_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    ଅକ୍ଷର buf[260];
    ଅଚଳ ଅକ୍ଷର *dllname;
    ଅଚଳ ଅକ୍ଷର *name;

    rva_base = pe->thunk->sh_addr - pe->imagebase;
    sym_ଗଣନା = 0, sorted = ଖାଲି, op = ଖାଲି;

    sym_end = symtab_section->data_offset / ଆକାର(ElfW(Sym));
    ପାଇଁ (sym_index = 1; sym_index < sym_end; ++sym_index) {
        sym = (ElfW(Sym)*)symtab_section->data + sym_index;
        name = pe_export_name(s1, sym);
        ଯଦି (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(ଆକାର *p);
            p->index = sym_index;
            p->name = name;
            dynarray_add(&sorted, &sym_ଗଣନା, p);
        }
#ଯଦି 0
        ଯଦି (sym->st_other & ST_PE_EXPORT)
            printf("export: %s\n", name);
        ଯଦି (sym->st_other & ST_PE_STDCALL)
            printf("stdcall: %s\n", name);
#endif
    }

    ଯଦି (0 == sym_ଗଣନା)
        ଫେରନ୍ତୁ;

    qsort (sorted, sym_ଗଣନା, ଆକାର *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    base_o = pe->thunk->data_offset;
    func_o = base_o + ଆକାର(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_ଗଣନା * ଆକାର (DWORD);
    ord_o = name_o + sym_ଗଣନା * ଆକାର (DWORD);
    str_o = ord_o + sym_ଗଣନା * ଆକାର(WORD);

    hdr = section_ptr_add(pe->thunk, str_o - base_o);
    hdr->Characteristics        = 0;
    hdr->Base                   = 1;
    hdr->ସଂଖ୍ୟା_Of_Functions      = sym_ଗଣନା;
    hdr->ସଂଖ୍ୟା_Of_Names          = sym_ଗଣନା;
    hdr->AddressOfFunctions     = func_o + rva_base;
    hdr->AddressOfNames         = name_o + rva_base;
    hdr->AddressOfNameOrdinals  = ord_o + rva_base;
    hdr->Name                   = str_o + rva_base;
    put_elf_str(pe->thunk, dllname);

#ଯଦି 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, ଆକାର buf, pe->filename);
    strcpy(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    ଯଦି (ଖାଲି == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } ଅନ୍ୟଥା {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        ଯଦି (s1->verbose)
            printf("<- %s (%d symbol%s)\n", buf, sym_ଗଣନା, &"s"[sym_ଗଣନା < 2]);
    }
#endif

    ପାଇଁ (ord = 0; ord < sym_ଗଣନା; ++ord)
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
        func_o += ଆକାର (DWORD);
        name_o += ଆକାର (DWORD);
        ord_o += ଆକାର (WORD);
        ଯଦି (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = base_o + rva_base;
    pe->exp_size = pe->thunk->data_offset - base_o;
    dynarray_reset(&sorted, &sym_ଗଣନା);
    ଯଦି (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
ସ୍ଥିର ଶୂନ୍ୟ pe_build_reloc (ସଂରଚନା pe_info *pe)
{
    DWORD offset, block_ptr, sh_addr, addr;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଗଣନା_3, i;
    ElfW_Rel *rel, *rel_end;
    Section *s = ଖାଲି, *sr;
    ସଂରଚନା pe_reloc_header *hdr;
    TCCState *s1 = pe->s1;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା dwarf = 0, n;

    sh_addr = offset = block_ptr = ଗଣନା_3 = i = 0;
    rel = rel_end = ଖାଲି;

    ପାଇଁ(;;) {
        ଯଦି (rel < rel_end) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_offset + sh_addr;
            ++ rel;
            ଯଦି (type != REL_TYPE_DIRECT)
                ଜାରି;
            ଯଦି (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->data + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                ଯଦି (n >= s1->dwlo && n < s1->dwhi)
                    ଜାରି;
            }
            ଯଦି (ଗଣନା_3 == 0) { /* new block */
                block_ptr = pe->reloc->data_offset;
                section_ptr_add(pe->reloc, ଆକାର(ସଂରଚନା pe_reloc_header));
                offset = addr & 0xFFFFFFFF<<12;
            }
            ଯଦି ((addr -= offset)  < (1<<12)) { /* one block spans 4k addresses */
                WORD *wp = section_ptr_add(pe->reloc, ଆକାର (WORD));
                *wp = addr | PE_IMAGE_REL<<12;
                ++ଗଣନା_3;
                ଜାରି;
            }
            -- rel;

        } ଅନ୍ୟଥା ଯଦି (s) {
            sr = s->reloc;
            ଯଦି (sr) {
                rel = (ElfW_Rel *)sr->data;
                rel_end = (ElfW_Rel *)(sr->data + sr->data_offset);
                sh_addr = s->sh_addr;
                dwarf = s->sh_ଅଙ୍କ >= s1->dwlo && s->sh_ଅଙ୍କ < s1->dwhi;
            }
            s = s->prev;
            ଜାରି;

        } ଅନ୍ୟଥା ଯଦି (i < pe->sec_ଗଣନା) {
            s = pe->sec_info[i]->sec, ++i;
            ଜାରି;

        } ଅନ୍ୟଥା ଯଦି (!ଗଣନା_3)
            ଭାଙ୍ଗ;

        /* fill the last block and ready for a new one */
        ଯଦି (ଗଣନା_3 & 1) /* align for DWORDS */
            section_ptr_add(pe->reloc, ଆକାର(WORD)), ++ଗଣନା_3;
        hdr = (ସଂରଚନା pe_reloc_header *)(pe->reloc->data + block_ptr);
        hdr -> offset = offset - pe->imagebase;
        hdr -> size = ଗଣନା_3 * ଆକାର(WORD) + ଆକାର(ସଂରଚନା pe_reloc_header);
        ଗଣନା_3 = 0;
    }
}

/* ------------------------------------------------------------- */
ସ୍ଥିର ଶୂନ୍ୟ pe_build_tls(ସଂରଚନା pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, n;

    ଯଦି (0 == s) {
        pe->tls_size = ଆକାର (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_add(pe->thunk, pe->tls_size, 16);
        pe->tls_data = section_add(data_section, PTR_SIZE * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, data_section->sh_ଅଙ୍କ, 0);
        ପାଇଁ (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_SIZE*n, REL_TYPE_DIRECT, c);
        /* for generators */
        set_elf_sym(symtab_section, pe->tls_data, PTR_SIZE * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, data_section->sh_ଅଙ୍କ, "__tls_index");
        ଫେରନ୍ତୁ;
    }

    ଯଦି (0 == s1->tls_start)
        s1->tls_start = s->sh_addr;
    d = (ଶୂନ୍ୟ*)(pe->thunk->data + pe->tls_dir);
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
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_section_class(Section *s)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, flags;
    ଅଚଳ ଅକ୍ଷର *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    ଯଦି (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        ଫେରନ୍ତୁ sec_debug;
    } ଅନ୍ୟଥା ଯଦି (flags & SHF_ALLOC) {
        ଯଦି (flags & SHF_TLS)
            ଫେରନ୍ତୁ sec_tdata + (type == SHT_NOBITS);
        ଯଦି (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            ଯଦି (flags & SHF_EXECINSTR)
                ଫେରନ୍ତୁ sec_text;
            ଯଦି (flags & SHF_WRITE)
                ଫେରନ୍ତୁ sec_data;
            ଯଦି (0 == strcmp(name, ".rsrc"))
                ଫେରନ୍ତୁ sec_rsrc;
            ଯଦି (0 == strcmp(name, ".iedat"))
                ଫେରନ୍ତୁ sec_idata;
            ଯଦି (0 == strcmp(name, ".pdata"))
                ଫେରନ୍ତୁ sec_pdata;
            ଫେରନ୍ତୁ sec_rdata;
        } ଅନ୍ୟଥା ଯଦି (type == SHT_NOBITS) {
            ଫେରନ୍ତୁ sec_bss;
        }
        ଫେରନ୍ତୁ sec_other;
    } ଅନ୍ୟଥା {
        ଯଦି (0 == strcmp(name, ".reloc"))
            ଫେରନ୍ତୁ sec_reloc;
    }
    ଫେରନ୍ତୁ sec_last;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_assign_addresses (ସଂରଚନା pe_info *pe)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, k, n, c, nbs;
    ADDR3264 addr;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *sec_order, *sec_cls;
    ସଂରଚନା section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    ଯଦି (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_order = tcc_mallocz(2 * ଆକାର (ପୂର୍ଣ୍ଣସଂଖ୍ୟା) * nbs);
    sec_cls = sec_order + nbs;
    ପାଇଁ (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        ପାଇଁ (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
        ଯଦି ((s->sh_flags & SHF_TLS) && 0 == pe->tls_size)
            pe_build_tls(pe, ଖାଲି);
    }
    si = ଖାଲି;
    addr = pe->imagebase + 1;
    ପାଇଁ (i = 1; (c = sec_cls[i]) < sec_last; ++i) {
        s = s1->sections[sec_order[i]];

        ଯଦି (PE_MERGE_DATA && c == sec_bss)
            c = sec_data;
        ଯଦି (c == sec_tbss)
            c = sec_tdata;

        ଯଦି (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } ଅନ୍ୟଥା {
            si = ଖାଲି;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        ଯଦି (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        ଯଦି (s == pe->reloc)
            pe_build_reloc (pe);

        ଯଦି (0 == s->data_offset)
            ଜାରି;

        ଯଦି (si)
            ଯାଅ add_section;

        si = tcc_mallocz(ଆକାର *si);
        dynarray_add(&pe->sec_info, &pe->sec_ଗଣନା, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        ଯଦି (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_CODE;
        ଅନ୍ୟଥା ଯଦି (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_DATA;
        ଅନ୍ୟଥା
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_DATA;
        ଯଦି (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        ଯଦି (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

add_section:
        s->sh_info = pe->sec_ଗଣନା; /* section number for coff syms */
        addr += s->data_offset;
        si->sh_size = addr - si->sh_addr;
        ଯଦି (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            ଯେତେବେଳେ (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = ଖାଲି;
            si->data_size = si->sh_size;
        }

        ଯଦି (s->sh_flags & SHF_TLS) {
            strcpy(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#ଯଦି 0
    ପାଇଁ (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_order[i]];
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା type = s->sh_type;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags = s->sh_flags;
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
    ଫେରନ୍ତୁ 0;
}

/*----------------------------------------------------------------------------*/
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_check_symbols(ସଂରଚନା pe_info *pe)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_index, sym_end;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(text_section, 8);

    sym_end = symtab_section->data_offset / ଆକାର(ElfW(Sym));
    ପାଇଁ (sym_index = 1; sym_index < sym_end; ++sym_index) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
        ଯଦି (sym->st_shndx == SHN_UNDEF) {
            ଅଚଳ ଅକ୍ଷର *name = (ଅକ୍ଷର*)symtab_section->link->data + sym->st_name;
            unsigned type = ELFW(ST_TYPE)(sym->st_info);
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା imp_sym = 0;
            ସଂରଚନା import_ପ୍ରତୀକ *is;

            ପୂର୍ଣ୍ଣସଂଖ୍ୟା _imp_, n;
            ଅକ୍ଷର buffer[200];
            ଅଚଳ ଅକ୍ଷର *s, *p;

            n = _imp_ = 0;
            ଯଦି (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            କର {
                s = pe_export_name(s1, sym);
                ଯଦି (n) {
                    /* second try: */
                    ଯଦି (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        ଯଦି (!p || s[0] != '_')
                            ଭାଙ୍ଗ;
                        strcpy(buffer, s+1)[p-s-1] = 0, s = buffer;
                    } ଅନ୍ୟଥା ଯଦି (s[0] != '_') { /* try non-ansi function */
                        buffer[0] = '_', strcpy(buffer + 1, s), s = buffer;
                    } ଅନ୍ୟଥା ଯଦି (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } ଅନ୍ୟଥା ଯଦି (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } ଅନ୍ୟଥା {
                        ଭାଙ୍ଗ;
                    }
                }
                imp_sym = find_elf_sym(s1->dynsymtab_section, s);
            } ଯେତେବେଳେ (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            ଯଦି (0 == imp_sym)
                ଜାରି; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_add_import(pe, imp_sym);

            ଯଦି (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                unsigned offset = is->thk_offset;
                ଯଦି (offset) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } ଅନ୍ୟଥା {
                    unsigned ଅକ୍ଷର *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(buffer, "IAT.%s", name);
                    is->iat_index = put_elf_sym(
                        symtab_section, 0, ଆକାର(DWORD),
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
#ନଚେତଯଦି defined(TCC_TARGET_ARM64)
                    p = section_ptr_add(text_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, text_section,
                        offset + 16, R_XXX_THUNKFIX, is->iat_index);
#ଅନ୍ୟଥା
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
                sym->st_ମୂଲ୍ୟ = offset;
                sym->st_shndx = text_section->sh_ଅଙ୍କ;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } ଅନ୍ୟଥା { /* STT_OBJECT */
                ଯଦି (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_ମୂଲ୍ୟ = is->iat_index; /* chain potential alias */
                is->iat_index = sym_index;
            }

        } ଅନ୍ୟଥା ଯଦି (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    ଫେରନ୍ତୁ ret;
}

/*----------------------------------------------------------------------------*/
#ଯଦି PE_PRINT_SECTIONS
ସ୍ଥିର ଶୂନ୍ୟ pe_print_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, n, l, m;
    p = s->data;
    e = s->data + s->data_offset;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    ଯଦି (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    ଯଦି (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (unsigned)s->sh_addr);
    fprintf(f, "\ncontents %08X", (unsigned)l);
    fprintf(f, "\n\n");

    ଯଦି (s->sh_type == SHT_NOBITS)
        ଫେରନ୍ତୁ;

    ଯଦି (0 == l)
        ଫେରନ୍ତୁ;

    ଯଦି (s->sh_type == SHT_SYMTAB)
        m = ଆକାର(ElfW(Sym));
    ଅନ୍ୟଥା ଯଦି (s->sh_type == SHT_RELX)
        m = ଆକାର(ElfW_Rel);
    ଅନ୍ୟଥା
        m = 16;

    fprintf(f, "%-8s", "offset");
    ପାଇଁ (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    ଯଦି (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        ଅଚଳ ଅକ୍ଷର *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            ଖାଲି
        };

        ଅଚଳ ଅକ୍ଷର *fields2[] = {
            "offs",
            "type",
            "symb",
            ଖାଲି
        };

        ଅଚଳ ଅକ୍ଷର **p;

        ଯଦି (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        ଅନ୍ୟଥା
            p = fields2, n = 58;

        ପାଇଁ (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    ପାଇଁ (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    ପାଇଁ (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        ପାଇଁ (n = 0; n < m; ++n) {
            ଯଦି (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            ଅନ୍ୟଥା
                fprintf(f, "   ");
        }

        ଯଦି (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            ଅଚଳ ଅକ୍ଷର *name = s->link->data + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (unsigned)sym->st_name,
                    (unsigned)sym->st_ମୂଲ୍ୟ,
                    (unsigned)sym->st_size,
                    (unsigned)ELFW(ST_BIND)(sym->st_info),
                    (unsigned)ELFW(ST_TYPE)(sym->st_info),
                    (unsigned)sym->st_other,
                    (unsigned)sym->st_shndx,
                    name);

        } ଅନ୍ୟଥା ଯଦି (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->data + ELFW(R_SYM)(rel->r_info);
            ଅଚଳ ଅକ୍ଷର *name = s->link->link->data + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (unsigned)rel->r_offset,
                    (unsigned)ELFW(R_TYPE)(rel->r_info),
                    (unsigned)ELFW(R_SYM)(rel->r_info),
                    name);
        } ଅନ୍ୟଥା {
            fprintf(f, "   ");
            ପାଇଁ (n = 0; n < m; ++n) {
                ଯଦି (n + i < l) {
                    b = p[i + n];
                    ଯଦି (b < 32 || b >= 127)
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

ସ୍ଥିର ଶୂନ୍ୟ pe_print_sections(TCCState *s1, ଅଚଳ ଅକ୍ଷର *fname)
{
    Section *s;
    FILE *f;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    f = fopen(fname, "w");
    ପାଇଁ (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    fclose(f);
}
#endif

/* ------------------------------------------------------------- */

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_putimport(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା dllindex, ଅଚଳ ଅକ୍ଷର *name, addr_t ମୂଲ୍ୟ)
{
    ଫେରନ୍ତୁ set_elf_sym(
        s1->dynsymtab_section,
        ମୂଲ୍ୟ,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        ମୂଲ୍ୟ ? SHN_ABS : SHN_UNDEF,
        name
        );
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା read_mem(ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, unsigned offset, ଶୂନ୍ୟ *buffer, unsigned len)
{
    lseek(fd, offset, SEEK_SET);
    ଫେରନ୍ତୁ len == ପଠ(fd, buffer, len);
}

/* ------------------------------------------------------------- */

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା get_dllexports(ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, ଅକ୍ଷର **pp)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, k, l, n, n0, ret;
    ଅକ୍ଷର *p;

    IMAGE_SECTION_HEADER ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_HEADER dh;
    IMAGE_FILE_HEADER ih;
    DWORD sig, ref, addr;
    DWORD *namep = ଖାଲି, p0 = 0, p1;

    ପୂର୍ଣ୍ଣସଂଖ୍ୟା pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = ଖାଲି;
    ret = 1;
    ଯଦି (!read_mem(fd, 0, &dh, ଆକାର dh))
        ଯାଅ the_end;
    ଯଦି (!read_mem(fd, dh.e_lfanew, &sig, ଆକାର sig))
        ଯାଅ the_end;
    ଯଦି (sig != 0x00004550)
        ଯାଅ the_end;
    pef_hdroffset = dh.e_lfanew + ଆକାର sig;
    ଯଦି (!read_mem(fd, pef_hdroffset, &ih, ଆକାର ih))
        ଯାଅ the_end;
    opt_hdroffset = pef_hdroffset + ଆକାର ih;
    ଯଦି (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + ଆକାର oh;
        ଯଦି (!read_mem(fd, opt_hdroffset, &oh, ଆକାର oh))
            ଯାଅ the_end;
        ଯଦି (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.ସଂଖ୍ୟା_Of_Rva_And_Sizes)
            ଯାଅ the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } ଅନ୍ୟଥା ଯଦି (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + ଆକାର oh;
        ଯଦି (!read_mem(fd, opt_hdroffset, &oh, ଆକାର oh))
            ଯାଅ the_end;
        ଯଦି (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.ସଂଖ୍ୟା_Of_Rva_And_Sizes)
            ଯାଅ the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } ଅନ୍ୟଥା
        ଯାଅ the_end;

    //printf("addr: %08x\n", addr);
    ପାଇଁ (i = 0; i < ih.ସଂଖ୍ୟା_Of_Sections; ++i) {
        ଯଦି (!read_mem(fd, sec_hdroffset + i * ଆକାର ish, &ish, ଆକାର ish))
            ଯାଅ the_end;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        ଯଦି (addr >= ish.VirtualAddress && addr < ish.VirtualAddress + ish.SizeOfRawData)
            ଯାଅ found;
    }
    ଯାଅ the_end_0;
found:
    ref = ish.VirtualAddress - ish.PointerToRawData;
    ଯଦି (!read_mem(fd, addr - ref, &ied, ଆକାର ied))
        ଯାଅ the_end;
    k = ied.ସଂଖ୍ୟା_Of_Names;
    ଯଦି (k) {
        namep = tcc_malloc(l = k * ଆକାର *namep);
        ଯଦି (!read_mem(fd, ied.AddressOfNames - ref, namep, l))
            ଯାଅ the_end;
        ପାଇଁ (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            ଯଦି (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            କର {
                ଯଦି (0 == l) {
                    ଯଦି (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    ଯଦି ((l = ପଠ(fd, p + n, 1000 - 1)) <= 0)
                        ଯାଅ the_end;
                }
                --l, ++p0;
            } ଯେତେବେଳେ (p[n++]);
        }
        p[n] = 0;
    }
the_end_0:
    ret = 0;
the_end:
    tcc_free(namep);
    ଯଦି (ret && p)
        tcc_free(p), p = ଖାଲି;
    *pp = p;
    ଫେରନ୍ତୁ ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_load_res(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd)
{
    ସଂରଚନା pe_rsrc_header hdr;
    Section *rsrc_section;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, ret = -1, sym_index;
    BYTE *ptr;
    unsigned offs;

    ଯଦି (!read_mem(fd, 0, &hdr, ଆକାର hdr))
        ଯାଅ quit;

    ଯଦି (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.ସଂଖ୍ୟା_Of_Sections != 1
        || strcmp((ଅକ୍ଷର*)hdr.sectionhdr.Name, ".rsrc") != 0)
        ଯାଅ quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_add(rsrc_section, hdr.sectionhdr.SizeOfRawData);
    offs = hdr.sectionhdr.PointerToRawData;
    ଯଦି (!read_mem(fd, offs, ptr, hdr.sectionhdr.SizeOfRawData))
        ଯାଅ quit;
    offs = hdr.sectionhdr.PointerToRelocations;
    sym_index = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_ଅଙ୍କ, ".rsrc");
    ପାଇଁ (i = 0; i < hdr.sectionhdr.ସଂଖ୍ୟା_Of_Relocations; ++i) {
        ସଂରଚନା pe_rsrc_reloc rel;
        ଯଦି (!read_mem(fd, offs, &rel, ଆକାର rel))
            ଯାଅ quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        ଯଦି (rel.type != RSRC_RELTYPE)
            ଯାଅ quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.offset, R_XXX_RELATIVE, sym_index);
        offs += ଆକାର rel;
    }
    ret = 0;
quit:
    ଫେରନ୍ତୁ ret;
}

/* ------------------------------------------------------------- */

ସ୍ଥିର ଅକ୍ଷର *trimfront(ଅକ୍ଷର *p)
{
    ଯେତେବେଳେ ((unsigned ଅକ୍ଷର)*p <= ' ' && *p && *p != '\n')
	++p;
    ଫେରନ୍ତୁ p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

ସ୍ଥିର ଅକ୍ଷର *get_token(ଅକ୍ଷର **s, ଅକ୍ଷର *f)
{
    ଅକ୍ଷର *p, *e;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା q;

    p = trimfront(*s);
    q = *p;
    ଯଦି (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    ଅନ୍ୟଥା
        q = ' ';
    ପାଇଁ (e = p; (unsigned ଅକ୍ଷର)*e >= ' ' && *e != q; ++e)
        ;
    ଯଦି (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    ଫେରନ୍ତୁ p;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_load_def(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା state = 0, ret = -1, dllindex = 0, ord;
    ଅକ୍ଷର dllname[80], *buf, *ଧାଡ଼ି, *p, *x, next;

    buf = tcc_load_text(fd);
    ଯଦି (!buf)
        ଫେରନ୍ତୁ ret;

    ପାଇଁ (ଧାଡ଼ି = buf;; ++ଧାଡ଼ି)  {
        p = get_token(&ଧାଡ଼ି, &next);
        ଯଦି (!(*p && *p != ';'))
            ଯାଅ skip;
        ବାଛ (state) {
        ସ୍ଥିତି 0:
            ଯଦି (0 != stricmp(p, "LIBRARY") || next == '\n')
                ଯାଅ quit;
            pstrcpy(dllname, ଆକାର dllname, get_token(&ଧାଡ଼ି, &next));
            ଯଦି (!*tcc_fileextension(dllname))
                pstrcat(dllname, ଆକାର dllname, ".dll");
            ++state;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 1:
            ଯଦି (0 != stricmp(p, "EXPORTS"))
                ଯାଅ quit;
            ++state;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 2:
            dllindex = tcc_add_dllref(s1, dllname, 0)->index;
            ++state;
            /* fall through */
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            ଯଦି (next == '@') {
                x = get_token(&ଧାଡ଼ି, &next);
                ord = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            ଭାଙ୍ଗ;
        }
skip:
        ଯେତେବେଳେ ((unsigned ଅକ୍ଷର)next > ' ')
            get_token(&ଧାଡ଼ି, &next);
        ଯଦି (next != '\n')
            ଭାଙ୍ଗ;
    }
    ret = 0;
quit:
    tcc_free(buf);
    ଫେରନ୍ତୁ ret;
}

/* ------------------------------------------------------------- */

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_load_dll(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, ଅଚଳ ଅକ୍ଷର *filename)
{
    ଅକ୍ଷର *p, *q;
    DLLReference *ref = tcc_add_dllref(s1, filename, 0);
    ଯଦି (ref->found)
        ଫେରନ୍ତୁ 0;
    ଯଦି (get_dllexports(fd, &p))
        ଫେରନ୍ତୁ -1;
    ଯଦି (p) {
        ପାଇଁ (q = p; *q; q += 1 + strlen(q))
            pe_putimport(s1, ref->index, q, 0);
        tcc_free(p);
    }
    ଫେରନ୍ତୁ 0;
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_load_file(ସଂରଚନା TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, ଅଚଳ ଅକ୍ଷର *filename)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret = -1;
    ଅକ୍ଷର buf[10];
    ଯଦି (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_load_def(s1, fd);
    ଅନ୍ୟଥା ଯଦି (pe_load_res(s1, fd) == 0)
        ret = 0;
    ଅନ୍ୟଥା ଯଦି (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_load_dll(s1, fd, filename);
    ଫେରନ୍ତୁ ret;
}

PUB_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_get_dllexports(ଅଚଳ ଅକ୍ଷର *filename, ଅକ୍ଷର **pp)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret, fd = open(filename, O_RDONLY | O_ଦ୍ୱିମିକ_2);
    ଯଦି (fd < 0)
        ଫେରନ୍ତୁ -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    ଫେରନ୍ତୁ ret;
}

/* ------------------------------------------------------------- */
#ifdef TCC_TARGET_X86_64
ସ୍ଥିର unsigned pe_add_unwind_info(TCCState *s1)
{
    ଯଦି (ଖାଲି == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    ଯଦି (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, text_section->sh_ଅଙ୍କ, ".uw_base");
    ଯଦି (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        ସ୍ଥିର ଅଚଳ unsigned ଅକ୍ଷର uw_info[] = {
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
        unsigned ଅକ୍ଷର *p;

        section_ptr_add(s, -s->data_offset & 3); /* align */
        s1->uw_offs = s->data_offset;
        p = section_ptr_add(s, ଆକାର uw_info);
        memcpy(p, uw_info, ଆକାର uw_info);
    }

    ଫେରନ୍ତୁ s1->uw_offs;
}

ST_FUNC ଶୂନ୍ୟ pe_add_unwind_data(unsigned start, unsigned end, unsigned ଗଦା)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    unsigned o, n, d;
    ସଂରଚନା /* _RUNTIME_FUNCTION */ {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD UnwindData;
    } *p;

    d = pe_add_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->data_offset;
    p = section_ptr_add(pd, ଆକାର *p);

    /* record this function */
    p->BeginAddress = start;
    p->EndAddress = end;
    p->UnwindData = d;

    /* put relocations on it */
    ପାଇଁ (n = o + ଆକାର *p; o < n; o += ଆକାର p->BeginAddress)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#ନଚେତଯଦି defined(TCC_TARGET_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
ସ୍ଥିର Section *pe_add_unwind_info(TCCState *s1)
{
    Section *s;

    ଯଦି (ଖାଲି == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = find_section(s1, ".xdata");
    s->sh_addralign = 4;
    ଯଦି (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  text_section->sh_ଅଙ୍କ, ".uw_text_base");
    ଯଦି (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_ଅଙ୍କ, ".uw_base");
    ଫେରନ୍ତୁ s;
}

ST_FUNC ଶୂନ୍ୟ pe_add_unwind_data(unsigned start, unsigned end, unsigned ଗଦା)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    unsigned o, d, code_bytes, func_len;
    unsigned ଅକ୍ଷର *q;
    uint32_t header;
    ସଂରଚନା /* _RUNTIME_FUNCTION */ {
        DWORD BeginAddress;
        DWORD UnwindData;
    } *p;

    ପୂର୍ଣ୍ଣସଂଖ୍ୟା epilog;

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
    ଯେତେବେଳେ ((unsigned)(q - (xd->data + d + 4)) < code_bytes)
        *q++ = 0xE3; /* nop padding */

    o = pd->data_offset;
    p = section_ptr_add(pd, ଆକାର *p);
    p->BeginAddress = start;
    p->UnwindData = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#endif
/* ------------------------------------------------------------- */
#ଯଦି defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
#define PE_STDSYM(n,s) n
#ଅନ୍ୟଥା
#define PE_STDSYM(n,s) "_" n s
#endif

ସ୍ଥିର ଶୂନ୍ୟ pe_add_runtime(TCCState *s1, ସଂରଚନା pe_info *pe)
{
    ଅଚଳ ଅକ୍ଷର *start_ପ୍ରତୀକ;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_type;

    ଯଦି (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        start_ପ୍ରତୀକ = PE_STDSYM("__dllstart","@12");
    } ଅନ୍ୟଥା {
        ଅଚଳ ଅକ୍ଷର *run_ପ୍ରତୀକ;
        ଯଦି (find_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            start_ପ୍ରତୀକ = "__winstart";
            run_ପ୍ରତୀକ = "__runwinmain";
            pe_type = PE_GUI;
        } ଅନ୍ୟଥା ଯଦି (find_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            start_ପ୍ରତୀକ = "__wwinstart";
            run_ପ୍ରତୀକ = "__runwwinmain";
            pe_type = PE_GUI;
        } ଅନ୍ୟଥା ଯଦି (find_elf_sym(symtab_section, "wmain")) {
            start_ପ୍ରତୀକ = "__wstart";
            run_ପ୍ରତୀକ = "__runwmain";
            pe_type = PE_EXE;
        } ଅନ୍ୟଥା {
            start_ପ୍ରତୀକ =  "__start";
            run_ପ୍ରତୀକ = "__runmain";
            pe_type = PE_EXE;
            ଯଦି (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        ଯଦି (TCC_OUTPUT_MEMORY == s1->output_type && !s1->nostdlib)
            start_ପ୍ରତୀକ = run_ପ୍ରତୀକ;
    }
    ଯଦି (s1->elf_entryname) {
        pe->start_ପ୍ରତୀକ = start_ପ୍ରତୀକ = s1->elf_entryname;
    } ଅନ୍ୟଥା {
        pe->start_ପ୍ରତୀକ = start_ପ୍ରତୀକ + 1;
        ଯଦି (!s1->leading_underscore || strchr(start_ପ୍ରତୀକ, '@'))
            ++start_ପ୍ରତୀକ;
    }

#ifdef CONFIG_TCC_BACKTRACE
    ଯଦି (s1->do_backtrace) {
#ifdef CONFIG_TCC_BCHECK
        ଯଦି (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    ଯଦି (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    ଅନ୍ୟଥା
                tcc_add_support(s1, "bcheck.o");
	}
#endif
        ଯଦି (s1->output_type == TCC_OUTPUT_EXE)
            tcc_add_support(s1, "bt-exe.o");
        ଯଦି (s1->output_type == TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-dll.o");
        ଯଦି (s1->output_type != TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-log.o");
        tcc_add_btstub(s1);
    }
#endif

    /* grab the startup code from libtcc1.a */
#ifdef TCC_IS_NATIVE
    ଯଦି (TCC_OUTPUT_MEMORY != s1->output_type || s1->run_main)
#endif
    set_global_sym(s1, start_ପ୍ରତୀକ, ଖାଲି, 0);

    ଯଦି (0 == s1->nostdlib) {
        ସ୍ଥିର ଅଚଳ ଅକ୍ଷର * ଅଚଳ libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", ଖାଲି
        };
        ଅଚଳ ଅକ୍ଷର * ଅଚଳ *pp, *p;
        ଯଦି (TCC_LIBTCC1[0])
            tcc_add_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        ପାଇଁ (pp = libs; 0 != (p = *pp); ++pp) {
            ଯଦି (*p)
                tcc_add_library(s1, p);
            ଅନ୍ୟଥା ଯଦି (PE_DLL != pe_type && PE_GUI != pe_type)
                ଭାଙ୍ଗ;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    ଯଦି (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    ଯଦି (TCC_OUTPUT_MEMORY == s1->output_type)
        pe_type = PE_RUN;
    pe->type = pe_type;
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_setsubsy(TCCState *s1, ଅଚଳ ଅକ୍ଷର *arg)
{
    ସ୍ଥିର ଅଚଳ ସଂରଚନା subsy { ଅଚଳ ଅକ୍ଷର* p; ପୂର୍ଣ୍ଣସଂଖ୍ୟା v; } x[] = {
#ଯଦି defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#ନଚେତଯଦି defined(TCC_TARGET_ARM)
        { "wince", 9 },
#endif
        { 0, -1 }};
    ଅଚଳ ସଂରଚନା subsy *y;
    ପାଇଁ (y = x;; ++y) {
        ଯଦି (!y->p)
            ଫେରନ୍ତୁ -1;
        ଯଦି (0 == strcmp(y->p, arg)) {
            s1->pe_subsystem = y->v;
            ଫେରନ୍ତୁ 0;
        }
    }
}

ସ୍ଥିର ଶୂନ୍ୟ pe_set_options(TCCState * s1, ସଂରଚନା pe_info *pe)
{
    ଯଦି (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_BASE_DLL;
    } ଅନ୍ୟଥା {
        pe->imagebase = IMAGE_BASE_EXE;
    }

#ଯଦି defined(TCC_TARGET_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#ଅନ୍ୟଥା
    ଯଦି (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    ଅନ୍ୟଥା
        pe->subsystem = 3;
#endif
    /* Allow override via -Wl,-subsystem=... option */
    ଯଦି (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    ଯଦି (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } ଅନ୍ୟଥା {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    ଯଦି (s1->section_align != 0)
        pe->section_align = s1->section_align;
    ଯଦି (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    ଯଦି ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    ଯଦି (s1->has_text_addr)
        pe->imagebase = s1->text_addr;
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_output_file(TCCState *s1, ଅଚଳ ଅକ୍ଷର *filename)
{
    ସଂରଚନା pe_info pe;

    memset(&pe, 0, ଆକାର pe);
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
    ଯଦି (s1->nb_errors)
        ଯାଅ done;
    ଯଦି (filename) {
        pe_assign_addresses(&pe);
        relocate_syms(s1, s1->symtab, 0);
        ଯଦି (s1->nb_errors)
            ଯାଅ done;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.start_addr = (DWORD)
            (get_sym_addr(s1, pe.start_ପ୍ରତୀକ, 1, 1) - pe.imagebase);
        ଯଦି (s1->nb_errors)
            ଯାଅ done;
        pe_write(&pe);
    } ଅନ୍ୟଥା {
        /* -run */
#ifdef TCC_IS_NATIVE
        pe.thunk = data_section;
        pe_build_imports(&pe);
        s1->run_main = pe.start_ପ୍ରତୀକ;
#ଯଦି defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        s1->uw_pdata = find_section(s1, ".pdata");
#endif
#endif
    }
done:
    dynarray_reset(&pe.sec_info, &pe.sec_ଗଣନା);
    pe_free_imports(&pe);
#ଯଦି PE_PRINT_SECTIONS
    ଯଦି (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#endif
    ଫେରନ୍ତୁ s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
