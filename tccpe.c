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

#ضمن "tcc.h"

#define PE_MERGE_DATA 1
#define PE_بغ_SECTIONS 0

#ifndef _WIN32
#define stricmp strcasecmp
#define strnicmp strncasecmp
#ضمن <sys/stat.h> /* chmod() */
#endif

#إذا defined TCC_TARGET_X86_64
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

#وإلاإذا defined TCC_TARGET_ARM
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

#وإلاإذا defined TCC_TARGET_ARM64
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

#وإلاإذا defined TCC_TARGET_I386
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

#إذا PTR_SIZE == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#وإلا
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#endif

#ifndef IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

تعريفنوع unsigned حرف BYTE;
تعريفنوع unsigned short WORD;
تعريفنوع unsigned صحيح DWORD;
تعريفنوع unsigned long long ULONGLONG;
#pragma pack(تور, 1)

تعريفنوع بنية _IMAGE_DOS_HEADER {  /* DOS .EXE header */
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

تعريفنوع بنية _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    لمب_Of_Sections;
    DWORD   TimeDateStamp;
    DWORD   Pointer_To_علام_Table;
    DWORD   لمب_Of_Symbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;


#define IMAGE_SIZEOF_FILE_HEADER 20

تعريفنوع بنية _IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;


تعريفنوع بنية _IMAGE_OPTIONAL_HEADER {
    /* Standard fields. */
    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
#إذا PTR_SIZE == 4
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
    DWORD   Win32_Version_درج;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    ADDR3264 Size_Of_تر_Reserve;
    ADDR3264 Size_Of_تر_Commit;
    ADDR3264 SizeOfHeapReserve;
    ADDR3264 SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   لمب_Of_Rva_And_Sizes;
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

تعريفنوع بنية _IMAGE_SECTION_HEADER {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    اتحاد {
            DWORD   PhysicalAddress;
            DWORD   VirtualSize;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   SizeOfRawData;
    DWORD   PointerToRawData;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    لمب_Of_Relocations;
    WORD    لمب_Of_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#define IMAGE_SIZEOF_SECTION_HEADER     40

تعريفنوع بنية _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD Name;
    DWORD Base;
    DWORD لمب_Of_Functions;
    DWORD لمب_Of_Names;
    DWORD AddressOfFunctions;
    DWORD AddressOfNames;
    DWORD AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

تعريفنوع بنية _IMAGE_TLS_DIRECTORY {
    ADDR3264 StartAddressOfRawData;
    ADDR3264 EndAddressOfRawData;
    ADDR3264 AddressOfIndex;
    ADDR3264 AddressOfCallBacks;
    DWORD SizeOfZeroFill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

تعريفنوع بنية _IMAGE_IMPORT_DESCRIPTOR {
    اتحاد {
        DWORD Characteristics;
        DWORD OriginalFirstThunk;
    };
    DWORD TimeDateStamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;

تعريفنوع بنية _IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   SizeOfBlock;
//  WORD    TypeOffset[1];
} IMAGE_BASE_RELOCATION;

#define IMAGE_SIZEOF_BASE_RELOCATION     8

#define IMAGE_REL_BASED_ABSOLUTE         0
#define IMAGE_REL_BASED_سم             1
#define IMAGE_REL_BASED_كس              2
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

#define IMAGE_DLLCHARACTERISTICS_سم_ENTROPY_VA 0x0020
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#define IMAGE_FILE_RELOCS_STRIPPED 0x0001

#pragma pack(چرو)

/* ----------------------------------------------------------- */
#endif /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#ifndef IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#endif

#pragma pack(تور, 1)
بنية pe_header
{
    IMAGE_DOS_HEADER doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_HEADER filehdr;
#إذا PTR_SIZE == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#وإلا
#ifdef _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#وإلا
    IMAGE_OPTIONAL_HEADER opthdr;
#endif
#endif
};

بنية pe_reloc_header {
    DWORD offset;
    DWORD size;
};

بنية pe_rsrc_header {
    بنية _IMAGE_FILE_HEADER filehdr;
    بنية _IMAGE_SECTION_HEADER sectionhdr;
};

بنية pe_rsrc_reloc {
    DWORD offset;
    DWORD size;
    WORD type;
};
#pragma pack(چرو)

/* ------------------------------------------------------------- */
/* internal temporary structures */

تعداد {
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

#إذا 0
ساكن ثابت DWORD pe_sec_flags[] = {
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

بنية section_info {
    صحيح cls;
    حرف name[32];
    ADDR3264 sh_addr;
    DWORD sh_size;
    DWORD pe_flags;
    Section *sec;
    DWORD data_size;
    IMAGE_SECTION_HEADER ish;
};

بنية import_علام {
    صحيح sym_index;
    صحيح iat_index;
    صحيح thk_offset;
};

بنية pe_import_info {
    صحيح dll_index;
    صحيح sym_كدي;
    بنية import_علام **symbols;
};

بنية pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    ثابت حرف *filename;
    صحيح type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    ثابت حرف *start_علام;
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
    صحيح subsystem;
    DWORD section_align;
    DWORD file_align;
    بنية section_info **sec_info;
    صحيح sec_كدي;
    بنية pe_import_info **imp_info;
    صحيح imp_كدي;
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

ساكن ثابت حرف *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    ثابت حرف *name = (حرف*)symtab_section->link->data + sym->st_name;
    إذا (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        أرجع name + 1;
    أرجع name;
}


ساكن صحيح dynarray_assoc(فراغ **pp, صحيح n, صحيح مبودي)
{
    صحيح i;
    لكل (i = 0; i < n; ++i, ++pp)
    إذا (مبودي == **(صحيح **) pp)
        أرجع i;
    أرجع -1;
}

ساكن DWORD umin(DWORD a, DWORD b)
{
    أرجع a < b ? a : b;
}

ساكن DWORD umax(DWORD a, DWORD b)
{
    أرجع a < b ? b : a;
}

ساكن DWORD pe_file_align(بنية pe_info *pe, DWORD n)
{
    أرجع (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

ساكن ADDR3264 pe_virtual_align(بنية pe_info *pe, ADDR3264 n)
{
    أرجع (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

ساكن فراغ pe_align_section(Section *s, صحيح a)
{
    صحيح i = s->data_offset & (a-1);
    إذا (i)
        section_ptr_add(s, a - i);
}

ساكن فراغ pe_set_datadir(بنية pe_header *hdr, صحيح dir, DWORD addr, DWORD size)
{
    hdr->opthdr.DataDirectory[dir].VirtualAddress = addr;
    hdr->opthdr.DataDirectory[dir].Size = size;
}

ساكن صحيح pe_fwrite(بنية pe_info *pe, ثابت فراغ *data, صحيح len)
{
    ثابت WORD *p = data;
    DWORD sum;
    صحيح ret, i;
    pe->pos += (ret = fwrite(data, 1, len, pe->op));
    sum = pe->sum;
    لكل (i = len; i > 0; i -= 2) {
        sum += (i >= 2) ? *p++ : *(BYTE*)p;
        sum = (sum + (sum >> 16)) & 0xFFFF;
    }
    pe->sum = sum;
    أرجع len == ret ? 0 : -1;
}

ساكن فراغ pe_fpad(بنية pe_info *pe, DWORD new_pos)
{
    حرف buf[256];
    صحيح n, diff = new_pos - pe->pos;
    memset(buf, 0, حجم buf);
    طالما (diff > 0) {
        diff -= n = umin(diff, حجم buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#pragma pack(تور, 1)
بنية syment
{
    اتحاد {
        حرف        n_name[8];     /* old COFF version */
        بنية {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_offset;      /* offset into string table */
        };
    };
    int32_t         n_درج;        /* value of symbol */
    short           n_scnum;        /* section number */
    unsigned short  n_type;         /* type and derived type */
    حرف            n_sclass;       /* storage class */
    حرف            n_numaux;       /* number of aux. entries */
};
#pragma pack(چرو)

#define SHF_PRIVATE 0x80000000

ساكن فراغ pe_add_coffsym(بنية pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    بنية syment *se;
    صحيح n;

    إذا (عدم == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_PRIVATE);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_PRIVATE);
        section_ptr_add(pe->coffstr, 4); /* coff string table size */
        أرجع;
    }

#إذا 0
    se = section_ptr_add(pe->coffsym, حجم *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_add(pe->coffsym, حجم *se);
    strcpy((حرف*)se, "no-file");
#endif

#إذا 1
    esym = (ElfSym*)s1->symtab->data;
    لكل (n = s1->symtab->data_offset / حجم *esym; ++esym, --n;) {
        صحيح sym_bind = ELFW(ST_BIND)(esym->st_info);
        إذا (sym_bind == STB_GLOBAL) {
            حرف *name = esym->st_name + (حرف*)s1->symtab->link->data;
            صحيح nl = strlen(name);
            addr_t درج = esym->st_درج;
            صحيح shnum = esym->st_shndx;
            إذا (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                درج = درج - s->sh_addr;
            }
            se = section_ptr_add(pe->coffsym, حجم *se);
            se->n_درج = درج;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            إذا (nl <= 8)
                memcpy(se->n_name, name, nl);
            وإلا
                se->n_offset = put_elf_str(pe->coffstr, name);
        }
    }
#endif
    write32le(pe->coffstr->data, pe->coffstr->data_offset); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
ساكن فراغ pe_create_pdb(TCCState *s1, ثابت حرف *exename)
{
    حرف buf[300]; صحيح r;
    snprintf(buf, حجم buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    strcpy(tcc_fileextension(strcpy(buf, exename)), ".pdb");
    إذا (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } وإلا إذا (s1->verbose) {
        printf("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
ساكن صحيح pe_write(بنية pe_info *pe)
{
    ساكن ثابت بنية pe_header pe_template = {
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
#إذا PTR_SIZE == 4
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

    بنية pe_header pe_header = pe_template;

    صحيح i;
    DWORD file_offset;
    بنية section_info *si;
    IMAGE_SECTION_HEADER *psh;
    TCCState *s1 = pe->s1;

    إذا (s1->do_debug)
        pe_add_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    إذا (عدم == pe->op)
        أرجع tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        حجم (بنية pe_header)
        + pe->sec_كدي * حجم (IMAGE_SECTION_HEADER)
        );

    file_offset = pe->sizeofheaders;

    إذا (2 == s1->verbose)
        printf("-------------------------------"
               "\n  virt   file   size  section" "\n");
    لكل (i = 0; i < pe->sec_كدي; ++i) {
        DWORD addr, size;
        ثابت حرف *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        size = si->sh_size;
        psh = &si->ish;

        إذا (2 == s1->verbose)
            printf("%6x %6x %6x  %s\n",
                (unsigned)addr, (unsigned)file_offset, (unsigned)size, sh_name);

        بدل (si->cls) {
            حالة sec_text:
                إذا (!pe_header.opthdr.BaseOfCode)
                    pe_header.opthdr.BaseOfCode = addr;
                اكسر;

            حالة sec_data:
#إذا PTR_SIZE == 4
                إذا (!pe_header.opthdr.BaseOfData)
                    pe_header.opthdr.BaseOfData = addr;
#endif
                اكسر;

            حالة sec_bss:
                اكسر;

            حالة sec_reloc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_BASERELOC, addr, size);
                اكسر;

            حالة sec_rsrc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_RESOURCE, addr, size);
                اكسر;

            حالة sec_pdata:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXCEPTION, addr, size);
                اكسر;
        }

        إذا (pe->imp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IMPORT,
                pe->imp_offs, pe->imp_size);
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IAT,
                pe->iat_offs, pe->iat_size);
        }
        إذا (pe->exp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXPORT,
                pe->exp_offs, pe->exp_size);
        }
        إذا (pe->tls_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_size);
        }

        memcpy(psh->Name, sh_name, umin(strlen(sh_name), حجم psh->Name));
        إذا (pe->coffstr && strlen(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((حرف*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->VirtualAddress = addr;
        psh->Misc.VirtualSize = size;
        pe_header.opthdr.SizeOfImage =
            umax(pe_virtual_align(pe, size + addr), pe_header.opthdr.SizeOfImage);

        إذا (si->data_size) {
            psh->PointerToRawData = file_offset;
            file_offset = pe_file_align(pe, file_offset + si->data_size);
            psh->SizeOfRawData = file_offset - psh->PointerToRawData;
            إذا (si->cls == sec_text)
                pe_header.opthdr.SizeOfCode += psh->SizeOfRawData;
            وإلا
                pe_header.opthdr.SizeOfInitializedData += psh->SizeOfRawData;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_header.filehdr.لمب_Of_Sections = pe->sec_كدي;
    pe_header.opthdr.AddressOfEntryPoint = pe->start_addr;
    pe_header.opthdr.SizeOfHeaders = pe->sizeofheaders;
    pe_header.opthdr.ImageBase = pe->imagebase;
    pe_header.opthdr.Subsystem = pe->subsystem;
    pe_header.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    إذا (s1->pe_تر_size)
        pe_header.opthdr.Size_Of_تر_Reserve = s1->pe_تر_size;
    إذا (PE_DLL == pe->type)
        pe_header.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_header.filehdr.Characteristics |= s1->pe_characteristics;
    إذا (pe->reloc)
        pe_header.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    إذا (pe->coffsym) {
        pe_add_coffsym(pe);
        pe_header.filehdr.Pointer_To_علام_Table = file_offset;
        pe_header.filehdr.لمب_Of_Symbols
            = pe->coffsym->data_offset / حجم (بنية syment);
    }

    pe_fwrite(pe, &pe_header, حجم pe_header);
    لكل (i = 0; i < pe->sec_كدي; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, حجم(IMAGE_SECTION_HEADER));

    file_offset = pe->sizeofheaders;
    لكل (i = 0; i < pe->sec_كدي; ++i) {
        Section *s;
        si = pe->sec_info[i];
        إذا (!si->data_size)
            استمر;
        لكل (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_offset);
            pe_fwrite(pe, s->data, s->data_offset);
            إذا (s->prev)
                file_offset += s->prev->sh_addr - s->sh_addr;
        }
        file_offset = si->ish.PointerToRawData + si->ish.SizeOfRawData;
        pe_fpad(pe, file_offset);
    }

    إذا (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->data, pe->coffsym->data_offset);
        pe_fwrite(pe, pe->coffstr->data, pe->coffstr->data_offset);
        file_offset = pe->pos;
    }

    pe->sum += file_offset;
    fseek(pe->op, offsetof(بنية pe_header, opthdr.CheckSum), SEEK_SET);
    pe_fwrite(pe, &pe->sum, حجم (DWORD));

    fclose (pe->op);
#ifndef _WIN32
    chmod(pe->filename, 0777);
#endif

    إذا (2 == s1->verbose)
        printf("-------------------------------\n");
    إذا (s1->verbose)
        printf("<- %s (%u bytes)\n", pe->filename, (unsigned)file_offset);

    إذا (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    أرجع 0;
}

/*----------------------------------------------------------------------------*/

ساكن بنية import_علام *pe_add_import(بنية pe_info *pe, صحيح sym_index)
{
    صحيح i;
    صحيح dll_index;
    بنية pe_import_info *p;
    بنية import_علام *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->data + sym_index;
    dll_index = isym->st_size;

    i = dynarray_assoc ((فراغ**)pe->imp_info, pe->imp_كدي, dll_index);
    إذا (-1 != i) {
        p = pe->imp_info[i];
        اذهب found_dll;
    }
    p = tcc_mallocz(حجم *p);
    p->dll_index = dll_index;
    dynarray_add(&pe->imp_info, &pe->imp_كدي, p);

found_dll:
    i = dynarray_assoc ((فراغ**)p->symbols, p->sym_كدي, sym_index);
    إذا (-1 != i)
        أرجع p->symbols[i];

    s = tcc_mallocz(حجم *s);
    dynarray_add(&p->symbols, &p->sym_كدي, s);
    s->sym_index = sym_index;
    أرجع s;
}

ساكن فراغ pe_free_imports(بنية pe_info *pe)
{
    صحيح i;
    لكل (i = 0; i < pe->imp_كدي; ++i) {
        بنية pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_كدي);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_كدي);
}

/*----------------------------------------------------------------------------*/
ساكن فراغ pe_build_imports(بنية pe_info *pe)
{
    صحيح thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_base = pe->thunk->sh_addr - pe->imagebase;
    صحيح ndlls = pe->imp_كدي;
    TCCState *s1 = pe->s1;

    لكل (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_كدي;

    إذا (0 == sym_cnt)
        أرجع;

    pe_align_section(pe->thunk, 16);
    pe->imp_size = (ndlls + 1) * حجم(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_size = (sym_cnt + ndlls) * حجم(ADDR3264);
    dll_ptr = pe->thunk->data_offset;
    thk_ptr = dll_ptr + pe->imp_size;
    ent_ptr = thk_ptr + pe->iat_size;
    pe->imp_offs = dll_ptr + rva_base;
    pe->iat_offs = thk_ptr + rva_base;
    section_ptr_add(pe->thunk, pe->imp_size + 2*pe->iat_size);

    لكل (i = 0; i < pe->imp_كدي; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        صحيح k, n, dllindex;
        ADDR3264 v;
        بنية pe_import_info *p = pe->imp_info[i];
        ثابت حرف *name;
        DLLReference *dllref;

        dllindex = p->dll_index;
        إذا (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        وإلا
            name = "", dllref = عدم;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->data + dll_ptr);
        hdr->FirstThunk = thk_ptr + rva_base;
        hdr->OriginalFirstThunk = ent_ptr + rva_base;
        hdr->Name = v + rva_base;

        لكل (k = 0, n = p->sym_كدي; k <= n; ++k) {
            إذا (k < n) {
                صحيح iat_index = p->symbols[k]->iat_index;
                صحيح sym_index = p->symbols[k]->sym_index;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->data + sym_index;
                ثابت حرف *name = (حرف*)s1->dynsymtab_section->link->data + imp_sym->st_name;
                صحيح ordinal;

                /* patch symbol (and possibly its underscored alias) */
                افعل {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->data + iat_index;
                    iat_index = esym->st_درج;
                    esym->st_درج = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_لمب;
                } طالما (iat_index);

                إذا (dllref)
                    v = 0, ordinal = imp_sym->st_درج; /* ordinal from pe_load_def */
                وإلا
                    ordinal = 0, v = imp_sym->st_درج; /* address from tcc_add_symbol() */

#ifdef TCC_IS_NATIVE
                إذا (pe->type == PE_RUN) {
                    إذا (dllref) {
                        إذا ( !dllref->handle )
                            dllref->handle = LoadLibraryA(dllref->name);
                        v = (ADDR3264)GetProcAddress(dllref->handle, ordinal?(حرف*)0+ordinal:name);
                    }
                    إذا (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } وإلا
#endif
                إذا (ordinal) {
                    v = ordinal | (ADDR3264)1 << (حجم(ADDR3264)*8 - 1);
                } وإلا {
                    v = pe->thunk->data_offset + rva_base;
                    section_ptr_add(pe->thunk, حجم(WORD)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } وإلا {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->data+thk_ptr) =
            *(ADDR3264*)(pe->thunk->data+ent_ptr) = v;
            thk_ptr += حجم (ADDR3264);
            ent_ptr += حجم (ADDR3264);
        }
        dll_ptr += حجم(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

بنية pe_sort_sym
{
    صحيح index;
    ثابت حرف *name;
};

ساكن صحيح sym_cmp(ثابت فراغ *va, ثابت فراغ *vb)
{
    ثابت حرف *ca = (*(بنية pe_sort_sym**)va)->name;
    ثابت حرف *cb = (*(بنية pe_sort_sym**)vb)->name;
    أرجع strcmp(ca, cb);
}

ساكن فراغ pe_build_exports(بنية pe_info *pe)
{
    ElfW(Sym) *sym;
    صحيح sym_index, sym_end;
    DWORD rva_base, base_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    صحيح sym_كدي, ord;
    بنية pe_sort_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    حرف buf[260];
    ثابت حرف *dllname;
    ثابت حرف *name;

    rva_base = pe->thunk->sh_addr - pe->imagebase;
    sym_كدي = 0, sorted = عدم, op = عدم;

    sym_end = symtab_section->data_offset / حجم(ElfW(Sym));
    لكل (sym_index = 1; sym_index < sym_end; ++sym_index) {
        sym = (ElfW(Sym)*)symtab_section->data + sym_index;
        name = pe_export_name(s1, sym);
        إذا (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(حجم *p);
            p->index = sym_index;
            p->name = name;
            dynarray_add(&sorted, &sym_كدي, p);
        }
#إذا 0
        إذا (sym->st_other & ST_PE_EXPORT)
            printf("export: %s\n", name);
        إذا (sym->st_other & ST_PE_STDCALL)
            printf("stdcall: %s\n", name);
#endif
    }

    إذا (0 == sym_كدي)
        أرجع;

    qsort (sorted, sym_كدي, حجم *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    base_o = pe->thunk->data_offset;
    func_o = base_o + حجم(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_كدي * حجم (DWORD);
    ord_o = name_o + sym_كدي * حجم (DWORD);
    str_o = ord_o + sym_كدي * حجم(WORD);

    hdr = section_ptr_add(pe->thunk, str_o - base_o);
    hdr->Characteristics        = 0;
    hdr->Base                   = 1;
    hdr->لمب_Of_Functions      = sym_كدي;
    hdr->لمب_Of_Names          = sym_كدي;
    hdr->AddressOfFunctions     = func_o + rva_base;
    hdr->AddressOfNames         = name_o + rva_base;
    hdr->AddressOfNameOrdinals  = ord_o + rva_base;
    hdr->Name                   = str_o + rva_base;
    put_elf_str(pe->thunk, dllname);

#إذا 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, حجم buf, pe->filename);
    strcpy(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    إذا (عدم == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } وإلا {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        إذا (s1->verbose)
            printf("<- %s (%d symbol%s)\n", buf, sym_كدي, &"s"[sym_كدي < 2]);
    }
#endif

    لكل (ord = 0; ord < sym_كدي; ++ord)
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
        func_o += حجم (DWORD);
        name_o += حجم (DWORD);
        ord_o += حجم (WORD);
        إذا (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = base_o + rva_base;
    pe->exp_size = pe->thunk->data_offset - base_o;
    dynarray_reset(&sorted, &sym_كدي);
    إذا (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
ساكن فراغ pe_build_reloc (بنية pe_info *pe)
{
    DWORD offset, block_ptr, sh_addr, addr;
    صحيح كدي_2, i;
    ElfW_Rel *rel, *rel_end;
    Section *s = عدم, *sr;
    بنية pe_reloc_header *hdr;
    TCCState *s1 = pe->s1;
    صحيح dwarf = 0, n;

    sh_addr = offset = block_ptr = كدي_2 = i = 0;
    rel = rel_end = عدم;

    لكل(;;) {
        إذا (rel < rel_end) {
            صحيح type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_offset + sh_addr;
            ++ rel;
            إذا (type != REL_TYPE_DIRECT)
                استمر;
            إذا (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->data + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                إذا (n >= s1->dwlo && n < s1->dwhi)
                    استمر;
            }
            إذا (كدي_2 == 0) { /* new block */
                block_ptr = pe->reloc->data_offset;
                section_ptr_add(pe->reloc, حجم(بنية pe_reloc_header));
                offset = addr & 0xFFFFFFFF<<12;
            }
            إذا ((addr -= offset)  < (1<<12)) { /* one block spans 4k addresses */
                WORD *wp = section_ptr_add(pe->reloc, حجم (WORD));
                *wp = addr | PE_IMAGE_REL<<12;
                ++كدي_2;
                استمر;
            }
            -- rel;

        } وإلا إذا (s) {
            sr = s->reloc;
            إذا (sr) {
                rel = (ElfW_Rel *)sr->data;
                rel_end = (ElfW_Rel *)(sr->data + sr->data_offset);
                sh_addr = s->sh_addr;
                dwarf = s->sh_لمب >= s1->dwlo && s->sh_لمب < s1->dwhi;
            }
            s = s->prev;
            استمر;

        } وإلا إذا (i < pe->sec_كدي) {
            s = pe->sec_info[i]->sec, ++i;
            استمر;

        } وإلا إذا (!كدي_2)
            اكسر;

        /* fill the last block and ready for a new one */
        إذا (كدي_2 & 1) /* align for DWORDS */
            section_ptr_add(pe->reloc, حجم(WORD)), ++كدي_2;
        hdr = (بنية pe_reloc_header *)(pe->reloc->data + block_ptr);
        hdr -> offset = offset - pe->imagebase;
        hdr -> size = كدي_2 * حجم(WORD) + حجم(بنية pe_reloc_header);
        كدي_2 = 0;
    }
}

/* ------------------------------------------------------------- */
ساكن فراغ pe_build_tls(بنية pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    صحيح c, n;

    إذا (0 == s) {
        pe->tls_size = حجم (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_add(pe->thunk, pe->tls_size, 16);
        pe->tls_data = section_add(data_section, PTR_SIZE * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, data_section->sh_لمب, 0);
        لكل (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_SIZE*n, REL_TYPE_DIRECT, c);
        /* for generators */
        set_elf_sym(symtab_section, pe->tls_data, PTR_SIZE * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, data_section->sh_لمب, "__tls_index");
        أرجع;
    }

    إذا (0 == s1->tls_start)
        s1->tls_start = s->sh_addr;
    d = (فراغ*)(pe->thunk->data + pe->tls_dir);
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
ساكن صحيح pe_section_class(Section *s)
{
    صحيح type, flags;
    ثابت حرف *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    إذا (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        أرجع sec_debug;
    } وإلا إذا (flags & SHF_ALLOC) {
        إذا (flags & SHF_TLS)
            أرجع sec_tdata + (type == SHT_NOBITS);
        إذا (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            إذا (flags & SHF_EXECINSTR)
                أرجع sec_text;
            إذا (flags & SHF_WRITE)
                أرجع sec_data;
            إذا (0 == strcmp(name, ".rsrc"))
                أرجع sec_rsrc;
            إذا (0 == strcmp(name, ".iedat"))
                أرجع sec_idata;
            إذا (0 == strcmp(name, ".pdata"))
                أرجع sec_pdata;
            أرجع sec_rdata;
        } وإلا إذا (type == SHT_NOBITS) {
            أرجع sec_bss;
        }
        أرجع sec_other;
    } وإلا {
        إذا (0 == strcmp(name, ".reloc"))
            أرجع sec_reloc;
    }
    أرجع sec_last;
}

ساكن صحيح pe_assign_addresses (بنية pe_info *pe)
{
    صحيح i, k, n, c, nbs;
    ADDR3264 addr;
    صحيح *sec_order, *sec_cls;
    بنية section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    إذا (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_order = tcc_mallocz(2 * حجم (صحيح) * nbs);
    sec_cls = sec_order + nbs;
    لكل (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        لكل (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
        إذا ((s->sh_flags & SHF_TLS) && 0 == pe->tls_size)
            pe_build_tls(pe, عدم);
    }
    si = عدم;
    addr = pe->imagebase + 1;
    لكل (i = 1; (c = sec_cls[i]) < sec_last; ++i) {
        s = s1->sections[sec_order[i]];

        إذا (PE_MERGE_DATA && c == sec_bss)
            c = sec_data;
        إذا (c == sec_tbss)
            c = sec_tdata;

        إذا (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } وإلا {
            si = عدم;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        إذا (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        إذا (s == pe->reloc)
            pe_build_reloc (pe);

        إذا (0 == s->data_offset)
            استمر;

        إذا (si)
            اذهب add_section;

        si = tcc_mallocz(حجم *si);
        dynarray_add(&pe->sec_info, &pe->sec_كدي, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        إذا (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_CODE;
        وإلا إذا (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_DATA;
        وإلا
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_DATA;
        إذا (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        إذا (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

add_section:
        s->sh_info = pe->sec_كدي; /* section number for coff syms */
        addr += s->data_offset;
        si->sh_size = addr - si->sh_addr;
        إذا (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            طالما (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = عدم;
            si->data_size = si->sh_size;
        }

        إذا (s->sh_flags & SHF_TLS) {
            strcpy(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#إذا 0
    لكل (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_order[i]];
        صحيح type = s->sh_type;
        صحيح flags = s->sh_flags;
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
    أرجع 0;
}

/*----------------------------------------------------------------------------*/
ساكن صحيح pe_check_symbols(بنية pe_info *pe)
{
    صحيح sym_index, sym_end;
    صحيح ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(text_section, 8);

    sym_end = symtab_section->data_offset / حجم(ElfW(Sym));
    لكل (sym_index = 1; sym_index < sym_end; ++sym_index) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
        إذا (sym->st_shndx == SHN_UNDEF) {
            ثابت حرف *name = (حرف*)symtab_section->link->data + sym->st_name;
            unsigned type = ELFW(ST_TYPE)(sym->st_info);
            صحيح imp_sym = 0;
            بنية import_علام *is;

            صحيح _imp_, n;
            حرف buffer[200];
            ثابت حرف *s, *p;

            n = _imp_ = 0;
            إذا (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            افعل {
                s = pe_export_name(s1, sym);
                إذا (n) {
                    /* second try: */
                    إذا (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        إذا (!p || s[0] != '_')
                            اكسر;
                        strcpy(buffer, s+1)[p-s-1] = 0, s = buffer;
                    } وإلا إذا (s[0] != '_') { /* try non-ansi function */
                        buffer[0] = '_', strcpy(buffer + 1, s), s = buffer;
                    } وإلا إذا (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } وإلا إذا (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } وإلا {
                        اكسر;
                    }
                }
                imp_sym = find_elf_sym(s1->dynsymtab_section, s);
            } طالما (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            إذا (0 == imp_sym)
                استمر; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_add_import(pe, imp_sym);

            إذا (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                unsigned offset = is->thk_offset;
                إذا (offset) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } وإلا {
                    unsigned حرف *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(buffer, "IAT.%s", name);
                    is->iat_index = put_elf_sym(
                        symtab_section, 0, حجم(DWORD),
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
#وإلاإذا defined(TCC_TARGET_ARM64)
                    p = section_ptr_add(text_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, text_section,
                        offset + 16, R_XXX_THUNKFIX, is->iat_index);
#وإلا
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
                sym->st_درج = offset;
                sym->st_shndx = text_section->sh_لمب;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } وإلا { /* STT_OBJECT */
                إذا (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_درج = is->iat_index; /* chain potential alias */
                is->iat_index = sym_index;
            }

        } وإلا إذا (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    أرجع ret;
}

/*----------------------------------------------------------------------------*/
#إذا PE_بغ_SECTIONS
ساكن فراغ pe_بغ_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    صحيح i, n, l, m;
    p = s->data;
    e = s->data + s->data_offset;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    إذا (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    إذا (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (unsigned)s->sh_addr);
    fprintf(f, "\ncontents %08X", (unsigned)l);
    fprintf(f, "\n\n");

    إذا (s->sh_type == SHT_NOBITS)
        أرجع;

    إذا (0 == l)
        أرجع;

    إذا (s->sh_type == SHT_SYMTAB)
        m = حجم(ElfW(Sym));
    وإلا إذا (s->sh_type == SHT_RELX)
        m = حجم(ElfW_Rel);
    وإلا
        m = 16;

    fprintf(f, "%-8s", "offset");
    لكل (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    إذا (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        ثابت حرف *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            عدم
        };

        ثابت حرف *fields2[] = {
            "offs",
            "type",
            "symb",
            عدم
        };

        ثابت حرف **p;

        إذا (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        وإلا
            p = fields2, n = 58;

        لكل (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    لكل (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    لكل (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        لكل (n = 0; n < m; ++n) {
            إذا (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            وإلا
                fprintf(f, "   ");
        }

        إذا (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            ثابت حرف *name = s->link->data + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (unsigned)sym->st_name,
                    (unsigned)sym->st_درج,
                    (unsigned)sym->st_size,
                    (unsigned)ELFW(ST_BIND)(sym->st_info),
                    (unsigned)ELFW(ST_TYPE)(sym->st_info),
                    (unsigned)sym->st_other,
                    (unsigned)sym->st_shndx,
                    name);

        } وإلا إذا (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->data + ELFW(R_SYM)(rel->r_info);
            ثابت حرف *name = s->link->link->data + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (unsigned)rel->r_offset,
                    (unsigned)ELFW(R_TYPE)(rel->r_info),
                    (unsigned)ELFW(R_SYM)(rel->r_info),
                    name);
        } وإلا {
            fprintf(f, "   ");
            لكل (n = 0; n < m; ++n) {
                إذا (n + i < l) {
                    b = p[i + n];
                    إذا (b < 32 || b >= 127)
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

ساكن فراغ pe_بغ_sections(TCCState *s1, ثابت حرف *fname)
{
    Section *s;
    FILE *f;
    صحيح i;
    f = fopen(fname, "w");
    لكل (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_بغ_section(f, s);
    }
    pe_بغ_section(f, s1->dynsymtab_section);
    fclose(f);
}
#endif

/* ------------------------------------------------------------- */

ST_FUNC صحيح pe_putimport(TCCState *s1, صحيح dllindex, ثابت حرف *name, addr_t درج)
{
    أرجع set_elf_sym(
        s1->dynsymtab_section,
        درج,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        درج ? SHN_ABS : SHN_UNDEF,
        name
        );
}

ساكن صحيح read_mem(صحيح fd, unsigned offset, فراغ *buffer, unsigned len)
{
    lseek(fd, offset, SEEK_SET);
    أرجع len == اقرأ(fd, buffer, len);
}

/* ------------------------------------------------------------- */

ساكن صحيح get_dllexports(صحيح fd, حرف **pp)
{
    صحيح i, k, l, n, n0, ret;
    حرف *p;

    IMAGE_SECTION_HEADER ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_HEADER dh;
    IMAGE_FILE_HEADER ih;
    DWORD sig, ref, addr;
    DWORD *namep = عدم, p0 = 0, p1;

    صحيح pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = عدم;
    ret = 1;
    إذا (!read_mem(fd, 0, &dh, حجم dh))
        اذهب the_end;
    إذا (!read_mem(fd, dh.e_lfanew, &sig, حجم sig))
        اذهب the_end;
    إذا (sig != 0x00004550)
        اذهب the_end;
    pef_hdroffset = dh.e_lfanew + حجم sig;
    إذا (!read_mem(fd, pef_hdroffset, &ih, حجم ih))
        اذهب the_end;
    opt_hdroffset = pef_hdroffset + حجم ih;
    إذا (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + حجم oh;
        إذا (!read_mem(fd, opt_hdroffset, &oh, حجم oh))
            اذهب the_end;
        إذا (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.لمب_Of_Rva_And_Sizes)
            اذهب the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } وإلا إذا (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + حجم oh;
        إذا (!read_mem(fd, opt_hdroffset, &oh, حجم oh))
            اذهب the_end;
        إذا (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.لمب_Of_Rva_And_Sizes)
            اذهب the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } وإلا
        اذهب the_end;

    //printf("addr: %08x\n", addr);
    لكل (i = 0; i < ih.لمب_Of_Sections; ++i) {
        إذا (!read_mem(fd, sec_hdroffset + i * حجم ish, &ish, حجم ish))
            اذهب the_end;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        إذا (addr >= ish.VirtualAddress && addr < ish.VirtualAddress + ish.SizeOfRawData)
            اذهب found;
    }
    اذهب the_end_0;
found:
    ref = ish.VirtualAddress - ish.PointerToRawData;
    إذا (!read_mem(fd, addr - ref, &ied, حجم ied))
        اذهب the_end;
    k = ied.لمب_Of_Names;
    إذا (k) {
        namep = tcc_malloc(l = k * حجم *namep);
        إذا (!read_mem(fd, ied.AddressOfNames - ref, namep, l))
            اذهب the_end;
        لكل (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            إذا (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            افعل {
                إذا (0 == l) {
                    إذا (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    إذا ((l = اقرأ(fd, p + n, 1000 - 1)) <= 0)
                        اذهب the_end;
                }
                --l, ++p0;
            } طالما (p[n++]);
        }
        p[n] = 0;
    }
the_end_0:
    ret = 0;
the_end:
    tcc_free(namep);
    إذا (ret && p)
        tcc_free(p), p = عدم;
    *pp = p;
    أرجع ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

ساكن صحيح pe_load_res(TCCState *s1, صحيح fd)
{
    بنية pe_rsrc_header hdr;
    Section *rsrc_section;
    صحيح i, ret = -1, sym_index;
    BYTE *ptr;
    unsigned offs;

    إذا (!read_mem(fd, 0, &hdr, حجم hdr))
        اذهب quit;

    إذا (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.لمب_Of_Sections != 1
        || strcmp((حرف*)hdr.sectionhdr.Name, ".rsrc") != 0)
        اذهب quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_add(rsrc_section, hdr.sectionhdr.SizeOfRawData);
    offs = hdr.sectionhdr.PointerToRawData;
    إذا (!read_mem(fd, offs, ptr, hdr.sectionhdr.SizeOfRawData))
        اذهب quit;
    offs = hdr.sectionhdr.PointerToRelocations;
    sym_index = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_لمب, ".rsrc");
    لكل (i = 0; i < hdr.sectionhdr.لمب_Of_Relocations; ++i) {
        بنية pe_rsrc_reloc rel;
        إذا (!read_mem(fd, offs, &rel, حجم rel))
            اذهب quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        إذا (rel.type != RSRC_RELTYPE)
            اذهب quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.offset, R_XXX_RELATIVE, sym_index);
        offs += حجم rel;
    }
    ret = 0;
quit:
    أرجع ret;
}

/* ------------------------------------------------------------- */

ساكن حرف *trimfront(حرف *p)
{
    طالما ((unsigned حرف)*p <= ' ' && *p && *p != '\n')
	++p;
    أرجع p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

ساكن حرف *get_token(حرف **s, حرف *f)
{
    حرف *p, *e;
    صحيح q;

    p = trimfront(*s);
    q = *p;
    إذا (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    وإلا
        q = ' ';
    لكل (e = p; (unsigned حرف)*e >= ' ' && *e != q; ++e)
        ;
    إذا (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    أرجع p;
}

ساكن صحيح pe_load_def(TCCState *s1, صحيح fd)
{
    صحيح state = 0, ret = -1, dllindex = 0, ord;
    حرف dllname[80], *buf, *لي, *p, *x, next;

    buf = tcc_load_text(fd);
    إذا (!buf)
        أرجع ret;

    لكل (لي = buf;; ++لي)  {
        p = get_token(&لي, &next);
        إذا (!(*p && *p != ';'))
            اذهب skip;
        بدل (state) {
        حالة 0:
            إذا (0 != stricmp(p, "LIBRARY") || next == '\n')
                اذهب quit;
            pstrcpy(dllname, حجم dllname, get_token(&لي, &next));
            إذا (!*tcc_fileextension(dllname))
                pstrcat(dllname, حجم dllname, ".dll");
            ++state;
            اكسر;
        حالة 1:
            إذا (0 != stricmp(p, "EXPORTS"))
                اذهب quit;
            ++state;
            اكسر;
        حالة 2:
            dllindex = tcc_add_dllref(s1, dllname, 0)->index;
            ++state;
            /* fall through */
        افتراضي:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            إذا (next == '@') {
                x = get_token(&لي, &next);
                ord = (صحيح)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            اكسر;
        }
skip:
        طالما ((unsigned حرف)next > ' ')
            get_token(&لي, &next);
        إذا (next != '\n')
            اكسر;
    }
    ret = 0;
quit:
    tcc_free(buf);
    أرجع ret;
}

/* ------------------------------------------------------------- */

ساكن صحيح pe_load_dll(TCCState *s1, صحيح fd, ثابت حرف *filename)
{
    حرف *p, *q;
    DLLReference *ref = tcc_add_dllref(s1, filename, 0);
    إذا (ref->found)
        أرجع 0;
    إذا (get_dllexports(fd, &p))
        أرجع -1;
    إذا (p) {
        لكل (q = p; *q; q += 1 + strlen(q))
            pe_putimport(s1, ref->index, q, 0);
        tcc_free(p);
    }
    أرجع 0;
}

ST_FUNC صحيح pe_load_file(بنية TCCState *s1, صحيح fd, ثابت حرف *filename)
{
    صحيح ret = -1;
    حرف buf[10];
    إذا (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_load_def(s1, fd);
    وإلا إذا (pe_load_res(s1, fd) == 0)
        ret = 0;
    وإلا إذا (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_load_dll(s1, fd, filename);
    أرجع ret;
}

PUB_FUNC صحيح tcc_get_dllexports(ثابت حرف *filename, حرف **pp)
{
    صحيح ret, fd = open(filename, O_RDONLY | O_نبيو_2);
    إذا (fd < 0)
        أرجع -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    أرجع ret;
}

/* ------------------------------------------------------------- */
#ifdef TCC_TARGET_X86_64
ساكن unsigned pe_add_unwind_info(TCCState *s1)
{
    إذا (عدم == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    إذا (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, text_section->sh_لمب, ".uw_base");
    إذا (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        ساكن ثابت unsigned حرف uw_info[] = {
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
        unsigned حرف *p;

        section_ptr_add(s, -s->data_offset & 3); /* align */
        s1->uw_offs = s->data_offset;
        p = section_ptr_add(s, حجم uw_info);
        memcpy(p, uw_info, حجم uw_info);
    }

    أرجع s1->uw_offs;
}

ST_FUNC فراغ pe_add_unwind_data(unsigned start, unsigned end, unsigned تر)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    unsigned o, n, d;
    بنية /* _RUNTIME_FUNCTION */ {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD UnwindData;
    } *p;

    d = pe_add_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->data_offset;
    p = section_ptr_add(pd, حجم *p);

    /* record this function */
    p->BeginAddress = start;
    p->EndAddress = end;
    p->UnwindData = d;

    /* put relocations on it */
    لكل (n = o + حجم *p; o < n; o += حجم p->BeginAddress)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#وإلاإذا defined(TCC_TARGET_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
ساكن Section *pe_add_unwind_info(TCCState *s1)
{
    Section *s;

    إذا (عدم == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = find_section(s1, ".xdata");
    s->sh_addralign = 4;
    إذا (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  text_section->sh_لمب, ".uw_text_base");
    إذا (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_لمب, ".uw_base");
    أرجع s;
}

ST_FUNC فراغ pe_add_unwind_data(unsigned start, unsigned end, unsigned تر)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    unsigned o, d, code_bytes, func_len;
    unsigned حرف *q;
    uint32_t header;
    بنية /* _RUNTIME_FUNCTION */ {
        DWORD BeginAddress;
        DWORD UnwindData;
    } *p;

    صحيح epilog;

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
    طالما ((unsigned)(q - (xd->data + d + 4)) < code_bytes)
        *q++ = 0xE3; /* nop padding */

    o = pd->data_offset;
    p = section_ptr_add(pd, حجم *p);
    p->BeginAddress = start;
    p->UnwindData = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#endif
/* ------------------------------------------------------------- */
#إذا defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
#define PE_STDSYM(n,s) n
#وإلا
#define PE_STDSYM(n,s) "_" n s
#endif

ساكن فراغ pe_add_runtime(TCCState *s1, بنية pe_info *pe)
{
    ثابت حرف *start_علام;
    صحيح pe_type;

    إذا (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        start_علام = PE_STDSYM("__dllstart","@12");
    } وإلا {
        ثابت حرف *run_علام;
        إذا (find_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            start_علام = "__winstart";
            run_علام = "__runwinmain";
            pe_type = PE_GUI;
        } وإلا إذا (find_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            start_علام = "__wwinstart";
            run_علام = "__runwwinmain";
            pe_type = PE_GUI;
        } وإلا إذا (find_elf_sym(symtab_section, "wmain")) {
            start_علام = "__wstart";
            run_علام = "__runwmain";
            pe_type = PE_EXE;
        } وإلا {
            start_علام =  "__start";
            run_علام = "__runmain";
            pe_type = PE_EXE;
            إذا (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        إذا (TCC_OUTPUT_MEMORY == s1->output_type && !s1->nostdlib)
            start_علام = run_علام;
    }
    إذا (s1->elf_entryname) {
        pe->start_علام = start_علام = s1->elf_entryname;
    } وإلا {
        pe->start_علام = start_علام + 1;
        إذا (!s1->leading_underscore || strchr(start_علام, '@'))
            ++start_علام;
    }

#ifdef CONFIG_TCC_BACKTRACE
    إذا (s1->do_backtrace) {
#ifdef CONFIG_TCC_BCHECK
        إذا (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    إذا (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    وإلا
                tcc_add_support(s1, "bcheck.o");
	}
#endif
        إذا (s1->output_type == TCC_OUTPUT_EXE)
            tcc_add_support(s1, "bt-exe.o");
        إذا (s1->output_type == TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-dll.o");
        إذا (s1->output_type != TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-log.o");
        tcc_add_btstub(s1);
    }
#endif

    /* grab the startup code from libtcc1.a */
#ifdef TCC_IS_NATIVE
    إذا (TCC_OUTPUT_MEMORY != s1->output_type || s1->run_main)
#endif
    set_global_sym(s1, start_علام, عدم, 0);

    إذا (0 == s1->nostdlib) {
        ساكن ثابت حرف * ثابت libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", عدم
        };
        ثابت حرف * ثابت *pp, *p;
        إذا (TCC_LIBTCC1[0])
            tcc_add_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        لكل (pp = libs; 0 != (p = *pp); ++pp) {
            إذا (*p)
                tcc_add_library(s1, p);
            وإلا إذا (PE_DLL != pe_type && PE_GUI != pe_type)
                اكسر;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    إذا (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    إذا (TCC_OUTPUT_MEMORY == s1->output_type)
        pe_type = PE_RUN;
    pe->type = pe_type;
}

ST_FUNC صحيح pe_setsubsy(TCCState *s1, ثابت حرف *arg)
{
    ساكن ثابت بنية subsy { ثابت حرف* p; صحيح v; } x[] = {
#إذا defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#وإلاإذا defined(TCC_TARGET_ARM)
        { "wince", 9 },
#endif
        { 0, -1 }};
    ثابت بنية subsy *y;
    لكل (y = x;; ++y) {
        إذا (!y->p)
            أرجع -1;
        إذا (0 == strcmp(y->p, arg)) {
            s1->pe_subsystem = y->v;
            أرجع 0;
        }
    }
}

ساكن فراغ pe_set_options(TCCState * s1, بنية pe_info *pe)
{
    إذا (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_BASE_DLL;
    } وإلا {
        pe->imagebase = IMAGE_BASE_EXE;
    }

#إذا defined(TCC_TARGET_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#وإلا
    إذا (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    وإلا
        pe->subsystem = 3;
#endif
    /* Allow override via -Wl,-subsystem=... option */
    إذا (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    إذا (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } وإلا {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    إذا (s1->section_align != 0)
        pe->section_align = s1->section_align;
    إذا (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    إذا ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    إذا (s1->has_text_addr)
        pe->imagebase = s1->text_addr;
}

ST_FUNC صحيح pe_output_file(TCCState *s1, ثابت حرف *filename)
{
    بنية pe_info pe;

    memset(&pe, 0, حجم pe);
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
    إذا (s1->nb_errors)
        اذهب done;
    إذا (filename) {
        pe_assign_addresses(&pe);
        relocate_syms(s1, s1->symtab, 0);
        إذا (s1->nb_errors)
            اذهب done;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.start_addr = (DWORD)
            (get_sym_addr(s1, pe.start_علام, 1, 1) - pe.imagebase);
        إذا (s1->nb_errors)
            اذهب done;
        pe_write(&pe);
    } وإلا {
        /* -run */
#ifdef TCC_IS_NATIVE
        pe.thunk = data_section;
        pe_build_imports(&pe);
        s1->run_main = pe.start_علام;
#إذا defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        s1->uw_pdata = find_section(s1, ".pdata");
#endif
#endif
    }
done:
    dynarray_reset(&pe.sec_info, &pe.sec_كدي);
    pe_free_imports(&pe);
#إذا PE_بغ_SECTIONS
    إذا (g_debug & 8)
        pe_بغ_sections(s1, "tcc.log");
#endif
    أرجع s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
