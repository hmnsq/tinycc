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

#شامل "tcc.h"

#define PE_MERGE_DATA 1
#define PE_PRINT_SECTIONS 0

#ifndef _WIN32
#define stricmp strcasecmp
#define strnicmp strncasecmp
#شامل <sys/stat.h> /* chmod() */
#endif

#اگر defined TCC_TARGET_X86_64
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

#وگرنهاگر defined TCC_TARGET_ARM
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

#وگرنهاگر defined TCC_TARGET_ARM64
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

#وگرنهاگر defined TCC_TARGET_I386
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

#اگر PTR_SIZE == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#وگرنه
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#endif

#ifndef IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

تعریفنوع unsigned نویسه BYTE;
تعریفنوع unsigned short WORD;
تعریفنوع unsigned صحیح DWORD;
تعریفنوع unsigned long long ULONGLONG;
#pragma pack(افزودن, 1)

تعریفنوع ساختار _IMAGE_DOS_HEADER {  /* DOS .EXE header */
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

تعریفنوع ساختار _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    عدد_Of_Sections;
    DWORD   TimeDateStamp;
    DWORD   Pointer_To_نماد_Table;
    DWORD   عدد_Of_Symbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;


#define IMAGE_SIZEOF_FILE_HEADER 20

تعریفنوع ساختار _IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;


تعریفنوع ساختار _IMAGE_OPTIONAL_HEADER {
    /* Standard fields. */
    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
#اگر PTR_SIZE == 4
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
    DWORD   Win32_Version_مقدار;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    ADDR3264 Size_Of_پشته_Reserve;
    ADDR3264 Size_Of_پشته_Commit;
    ADDR3264 SizeOfHeapReserve;
    ADDR3264 SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   عدد_Of_Rva_And_Sizes;
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

تعریفنوع ساختار _IMAGE_SECTION_HEADER {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    اجتماع {
            DWORD   PhysicalAddress;
            DWORD   VirtualSize;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   SizeOfRawData;
    DWORD   PointerToRawData;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    عدد_Of_Relocations;
    WORD    عدد_Of_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#define IMAGE_SIZEOF_SECTION_HEADER     40

تعریفنوع ساختار _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD Name;
    DWORD Base;
    DWORD عدد_Of_Functions;
    DWORD عدد_Of_Names;
    DWORD AddressOfFunctions;
    DWORD AddressOfNames;
    DWORD AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

تعریفنوع ساختار _IMAGE_TLS_DIRECTORY {
    ADDR3264 StartAddressOfRawData;
    ADDR3264 EndAddressOfRawData;
    ADDR3264 AddressOfIndex;
    ADDR3264 AddressOfCallBacks;
    DWORD SizeOfZeroFill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

تعریفنوع ساختار _IMAGE_IMPORT_DESCRIPTOR {
    اجتماع {
        DWORD Characteristics;
        DWORD OriginalFirstThunk;
    };
    DWORD TimeDateStamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;

تعریفنوع ساختار _IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   SizeOfBlock;
//  WORD    TypeOffset[1];
} IMAGE_BASE_RELOCATION;

#define IMAGE_SIZEOF_BASE_RELOCATION     8

#define IMAGE_REL_BASED_ABSOLUTE         0
#define IMAGE_REL_BASED_بالا             1
#define IMAGE_REL_BASED_کم              2
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

#define IMAGE_DLLCHARACTERISTICS_بالا_ENTROPY_VA 0x0020
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#define IMAGE_FILE_RELOCS_STRIPPED 0x0001

#pragma pack(برداشت)

/* ----------------------------------------------------------- */
#endif /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#ifndef IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#endif

#pragma pack(افزودن, 1)
ساختار pe_header
{
    IMAGE_DOS_HEADER doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_HEADER filehdr;
#اگر PTR_SIZE == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#وگرنه
#ifdef _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#وگرنه
    IMAGE_OPTIONAL_HEADER opthdr;
#endif
#endif
};

ساختار pe_reloc_header {
    DWORD offset;
    DWORD size;
};

ساختار pe_rsrc_header {
    ساختار _IMAGE_FILE_HEADER filehdr;
    ساختار _IMAGE_SECTION_HEADER sectionhdr;
};

ساختار pe_rsrc_reloc {
    DWORD offset;
    DWORD size;
    WORD type;
};
#pragma pack(برداشت)

/* ------------------------------------------------------------- */
/* internal temporary structures */

شمارش {
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

#اگر 0
ایستا ثابت DWORD pe_sec_flags[] = {
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

ساختار section_info {
    صحیح cls;
    نویسه name[32];
    ADDR3264 sh_addr;
    DWORD sh_size;
    DWORD pe_flags;
    Section *sec;
    DWORD data_size;
    IMAGE_SECTION_HEADER ish;
};

ساختار import_نماد {
    صحیح sym_index;
    صحیح iat_index;
    صحیح thk_offset;
};

ساختار pe_import_info {
    صحیح dll_index;
    صحیح sym_شمار;
    ساختار import_نماد **symbols;
};

ساختار pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    ثابت نویسه *filename;
    صحیح type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    ثابت نویسه *start_نماد;
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
    صحیح subsystem;
    DWORD section_align;
    DWORD file_align;
    ساختار section_info **sec_info;
    صحیح sec_شمار;
    ساختار pe_import_info **imp_info;
    صحیح imp_شمار;
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

ایستا ثابت نویسه *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    ثابت نویسه *name = (نویسه*)symtab_section->link->data + sym->st_name;
    اگر (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        بازگشت name + 1;
    بازگشت name;
}


ایستا صحیح dynarray_assoc(تهی **pp, صحیح n, صحیح کلید)
{
    صحیح i;
    برای (i = 0; i < n; ++i, ++pp)
    اگر (کلید == **(صحیح **) pp)
        بازگشت i;
    بازگشت -1;
}

ایستا DWORD umin(DWORD a, DWORD b)
{
    بازگشت a < b ? a : b;
}

ایستا DWORD umax(DWORD a, DWORD b)
{
    بازگشت a < b ? b : a;
}

ایستا DWORD pe_file_align(ساختار pe_info *pe, DWORD n)
{
    بازگشت (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

ایستا ADDR3264 pe_virtual_align(ساختار pe_info *pe, ADDR3264 n)
{
    بازگشت (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

ایستا تهی pe_align_section(Section *s, صحیح a)
{
    صحیح i = s->data_offset & (a-1);
    اگر (i)
        section_ptr_add(s, a - i);
}

ایستا تهی pe_set_datadir(ساختار pe_header *hdr, صحیح dir, DWORD addr, DWORD size)
{
    hdr->opthdr.DataDirectory[dir].VirtualAddress = addr;
    hdr->opthdr.DataDirectory[dir].Size = size;
}

ایستا صحیح pe_fwrite(ساختار pe_info *pe, ثابت تهی *data, صحیح len)
{
    ثابت WORD *p = data;
    DWORD sum;
    صحیح ret, i;
    pe->pos += (ret = fwrite(data, 1, len, pe->op));
    sum = pe->sum;
    برای (i = len; i > 0; i -= 2) {
        sum += (i >= 2) ? *p++ : *(BYTE*)p;
        sum = (sum + (sum >> 16)) & 0xFFFF;
    }
    pe->sum = sum;
    بازگشت len == ret ? 0 : -1;
}

ایستا تهی pe_fpad(ساختار pe_info *pe, DWORD new_pos)
{
    نویسه buf[256];
    صحیح n, diff = new_pos - pe->pos;
    memset(buf, 0, اندازه buf);
    وقتی (diff > 0) {
        diff -= n = umin(diff, اندازه buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#pragma pack(افزودن, 1)
ساختار syment
{
    اجتماع {
        نویسه        n_name[8];     /* old COFF version */
        ساختار {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_offset;      /* offset into string table */
        };
    };
    int32_t         n_مقدار;        /* value of symbol */
    short           n_scnum;        /* section number */
    unsigned short  n_type;         /* type and derived type */
    نویسه            n_sclass;       /* storage class */
    نویسه            n_numaux;       /* number of aux. entries */
};
#pragma pack(برداشت)

#define SHF_PRIVATE 0x80000000

ایستا تهی pe_add_coffsym(ساختار pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    ساختار syment *se;
    صحیح n;

    اگر (پوچ == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_PRIVATE);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_PRIVATE);
        section_ptr_add(pe->coffstr, 4); /* coff string table size */
        بازگشت;
    }

#اگر 0
    se = section_ptr_add(pe->coffsym, اندازه *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_add(pe->coffsym, اندازه *se);
    strcpy((نویسه*)se, "no-file");
#endif

#اگر 1
    esym = (ElfSym*)s1->symtab->data;
    برای (n = s1->symtab->data_offset / اندازه *esym; ++esym, --n;) {
        صحیح sym_bind = ELFW(ST_BIND)(esym->st_info);
        اگر (sym_bind == STB_GLOBAL) {
            نویسه *name = esym->st_name + (نویسه*)s1->symtab->link->data;
            صحیح nl = strlen(name);
            addr_t مقدار = esym->st_مقدار;
            صحیح shnum = esym->st_shndx;
            اگر (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                مقدار = مقدار - s->sh_addr;
            }
            se = section_ptr_add(pe->coffsym, اندازه *se);
            se->n_مقدار = مقدار;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            اگر (nl <= 8)
                memcpy(se->n_name, name, nl);
            وگرنه
                se->n_offset = put_elf_str(pe->coffstr, name);
        }
    }
#endif
    write32le(pe->coffstr->data, pe->coffstr->data_offset); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
ایستا تهی pe_create_pdb(TCCState *s1, ثابت نویسه *exename)
{
    نویسه buf[300]; صحیح r;
    snprintf(buf, اندازه buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    strcpy(tcc_fileextension(strcpy(buf, exename)), ".pdb");
    اگر (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } وگرنه اگر (s1->verbose) {
        printf("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
ایستا صحیح pe_write(ساختار pe_info *pe)
{
    ایستا ثابت ساختار pe_header pe_template = {
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
#اگر PTR_SIZE == 4
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

    ساختار pe_header pe_header = pe_template;

    صحیح i;
    DWORD file_offset;
    ساختار section_info *si;
    IMAGE_SECTION_HEADER *psh;
    TCCState *s1 = pe->s1;

    اگر (s1->do_debug)
        pe_add_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    اگر (پوچ == pe->op)
        بازگشت tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        اندازه (ساختار pe_header)
        + pe->sec_شمار * اندازه (IMAGE_SECTION_HEADER)
        );

    file_offset = pe->sizeofheaders;

    اگر (2 == s1->verbose)
        printf("-------------------------------"
               "\n  virt   file   size  section" "\n");
    برای (i = 0; i < pe->sec_شمار; ++i) {
        DWORD addr, size;
        ثابت نویسه *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        size = si->sh_size;
        psh = &si->ish;

        اگر (2 == s1->verbose)
            printf("%6x %6x %6x  %s\n",
                (unsigned)addr, (unsigned)file_offset, (unsigned)size, sh_name);

        انتخاب (si->cls) {
            حالت sec_text:
                اگر (!pe_header.opthdr.BaseOfCode)
                    pe_header.opthdr.BaseOfCode = addr;
                بشکن;

            حالت sec_data:
#اگر PTR_SIZE == 4
                اگر (!pe_header.opthdr.BaseOfData)
                    pe_header.opthdr.BaseOfData = addr;
#endif
                بشکن;

            حالت sec_bss:
                بشکن;

            حالت sec_reloc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_BASERELOC, addr, size);
                بشکن;

            حالت sec_rsrc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_RESOURCE, addr, size);
                بشکن;

            حالت sec_pdata:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXCEPTION, addr, size);
                بشکن;
        }

        اگر (pe->imp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IMPORT,
                pe->imp_offs, pe->imp_size);
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IAT,
                pe->iat_offs, pe->iat_size);
        }
        اگر (pe->exp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXPORT,
                pe->exp_offs, pe->exp_size);
        }
        اگر (pe->tls_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_size);
        }

        memcpy(psh->Name, sh_name, umin(strlen(sh_name), اندازه psh->Name));
        اگر (pe->coffstr && strlen(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((نویسه*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->VirtualAddress = addr;
        psh->Misc.VirtualSize = size;
        pe_header.opthdr.SizeOfImage =
            umax(pe_virtual_align(pe, size + addr), pe_header.opthdr.SizeOfImage);

        اگر (si->data_size) {
            psh->PointerToRawData = file_offset;
            file_offset = pe_file_align(pe, file_offset + si->data_size);
            psh->SizeOfRawData = file_offset - psh->PointerToRawData;
            اگر (si->cls == sec_text)
                pe_header.opthdr.SizeOfCode += psh->SizeOfRawData;
            وگرنه
                pe_header.opthdr.SizeOfInitializedData += psh->SizeOfRawData;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_header.filehdr.عدد_Of_Sections = pe->sec_شمار;
    pe_header.opthdr.AddressOfEntryPoint = pe->start_addr;
    pe_header.opthdr.SizeOfHeaders = pe->sizeofheaders;
    pe_header.opthdr.ImageBase = pe->imagebase;
    pe_header.opthdr.Subsystem = pe->subsystem;
    pe_header.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    اگر (s1->pe_پشته_size)
        pe_header.opthdr.Size_Of_پشته_Reserve = s1->pe_پشته_size;
    اگر (PE_DLL == pe->type)
        pe_header.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_header.filehdr.Characteristics |= s1->pe_characteristics;
    اگر (pe->reloc)
        pe_header.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    اگر (pe->coffsym) {
        pe_add_coffsym(pe);
        pe_header.filehdr.Pointer_To_نماد_Table = file_offset;
        pe_header.filehdr.عدد_Of_Symbols
            = pe->coffsym->data_offset / اندازه (ساختار syment);
    }

    pe_fwrite(pe, &pe_header, اندازه pe_header);
    برای (i = 0; i < pe->sec_شمار; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, اندازه(IMAGE_SECTION_HEADER));

    file_offset = pe->sizeofheaders;
    برای (i = 0; i < pe->sec_شمار; ++i) {
        Section *s;
        si = pe->sec_info[i];
        اگر (!si->data_size)
            ادامه;
        برای (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_offset);
            pe_fwrite(pe, s->data, s->data_offset);
            اگر (s->prev)
                file_offset += s->prev->sh_addr - s->sh_addr;
        }
        file_offset = si->ish.PointerToRawData + si->ish.SizeOfRawData;
        pe_fpad(pe, file_offset);
    }

    اگر (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->data, pe->coffsym->data_offset);
        pe_fwrite(pe, pe->coffstr->data, pe->coffstr->data_offset);
        file_offset = pe->pos;
    }

    pe->sum += file_offset;
    fseek(pe->op, offsetof(ساختار pe_header, opthdr.CheckSum), SEEK_SET);
    pe_fwrite(pe, &pe->sum, اندازه (DWORD));

    fclose (pe->op);
#ifndef _WIN32
    chmod(pe->filename, 0777);
#endif

    اگر (2 == s1->verbose)
        printf("-------------------------------\n");
    اگر (s1->verbose)
        printf("<- %s (%u bytes)\n", pe->filename, (unsigned)file_offset);

    اگر (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    بازگشت 0;
}

/*----------------------------------------------------------------------------*/

ایستا ساختار import_نماد *pe_add_import(ساختار pe_info *pe, صحیح sym_index)
{
    صحیح i;
    صحیح dll_index;
    ساختار pe_import_info *p;
    ساختار import_نماد *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->data + sym_index;
    dll_index = isym->st_size;

    i = dynarray_assoc ((تهی**)pe->imp_info, pe->imp_شمار, dll_index);
    اگر (-1 != i) {
        p = pe->imp_info[i];
        برو found_dll;
    }
    p = tcc_mallocz(اندازه *p);
    p->dll_index = dll_index;
    dynarray_add(&pe->imp_info, &pe->imp_شمار, p);

found_dll:
    i = dynarray_assoc ((تهی**)p->symbols, p->sym_شمار, sym_index);
    اگر (-1 != i)
        بازگشت p->symbols[i];

    s = tcc_mallocz(اندازه *s);
    dynarray_add(&p->symbols, &p->sym_شمار, s);
    s->sym_index = sym_index;
    بازگشت s;
}

ایستا تهی pe_free_imports(ساختار pe_info *pe)
{
    صحیح i;
    برای (i = 0; i < pe->imp_شمار; ++i) {
        ساختار pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_شمار);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_شمار);
}

/*----------------------------------------------------------------------------*/
ایستا تهی pe_build_imports(ساختار pe_info *pe)
{
    صحیح thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_base = pe->thunk->sh_addr - pe->imagebase;
    صحیح ndlls = pe->imp_شمار;
    TCCState *s1 = pe->s1;

    برای (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_شمار;

    اگر (0 == sym_cnt)
        بازگشت;

    pe_align_section(pe->thunk, 16);
    pe->imp_size = (ndlls + 1) * اندازه(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_size = (sym_cnt + ndlls) * اندازه(ADDR3264);
    dll_ptr = pe->thunk->data_offset;
    thk_ptr = dll_ptr + pe->imp_size;
    ent_ptr = thk_ptr + pe->iat_size;
    pe->imp_offs = dll_ptr + rva_base;
    pe->iat_offs = thk_ptr + rva_base;
    section_ptr_add(pe->thunk, pe->imp_size + 2*pe->iat_size);

    برای (i = 0; i < pe->imp_شمار; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        صحیح k, n, dllindex;
        ADDR3264 v;
        ساختار pe_import_info *p = pe->imp_info[i];
        ثابت نویسه *name;
        DLLReference *dllref;

        dllindex = p->dll_index;
        اگر (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        وگرنه
            name = "", dllref = پوچ;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->data + dll_ptr);
        hdr->FirstThunk = thk_ptr + rva_base;
        hdr->OriginalFirstThunk = ent_ptr + rva_base;
        hdr->Name = v + rva_base;

        برای (k = 0, n = p->sym_شمار; k <= n; ++k) {
            اگر (k < n) {
                صحیح iat_index = p->symbols[k]->iat_index;
                صحیح sym_index = p->symbols[k]->sym_index;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->data + sym_index;
                ثابت نویسه *name = (نویسه*)s1->dynsymtab_section->link->data + imp_sym->st_name;
                صحیح ordinal;

                /* patch symbol (and possibly its underscored alias) */
                انجامبده {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->data + iat_index;
                    iat_index = esym->st_مقدار;
                    esym->st_مقدار = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_رقم;
                } وقتی (iat_index);

                اگر (dllref)
                    v = 0, ordinal = imp_sym->st_مقدار; /* ordinal from pe_load_def */
                وگرنه
                    ordinal = 0, v = imp_sym->st_مقدار; /* address from tcc_add_symbol() */

#ifdef TCC_IS_NATIVE
                اگر (pe->type == PE_RUN) {
                    اگر (dllref) {
                        اگر ( !dllref->handle )
                            dllref->handle = LoadLibraryA(dllref->name);
                        v = (ADDR3264)GetProcAddress(dllref->handle, ordinal?(نویسه*)0+ordinal:name);
                    }
                    اگر (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } وگرنه
#endif
                اگر (ordinal) {
                    v = ordinal | (ADDR3264)1 << (اندازه(ADDR3264)*8 - 1);
                } وگرنه {
                    v = pe->thunk->data_offset + rva_base;
                    section_ptr_add(pe->thunk, اندازه(WORD)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } وگرنه {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->data+thk_ptr) =
            *(ADDR3264*)(pe->thunk->data+ent_ptr) = v;
            thk_ptr += اندازه (ADDR3264);
            ent_ptr += اندازه (ADDR3264);
        }
        dll_ptr += اندازه(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

ساختار pe_sort_sym
{
    صحیح index;
    ثابت نویسه *name;
};

ایستا صحیح sym_cmp(ثابت تهی *va, ثابت تهی *vb)
{
    ثابت نویسه *ca = (*(ساختار pe_sort_sym**)va)->name;
    ثابت نویسه *cb = (*(ساختار pe_sort_sym**)vb)->name;
    بازگشت strcmp(ca, cb);
}

ایستا تهی pe_build_exports(ساختار pe_info *pe)
{
    ElfW(Sym) *sym;
    صحیح sym_index, sym_end;
    DWORD rva_base, base_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    صحیح sym_شمار, ord;
    ساختار pe_sort_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    نویسه buf[260];
    ثابت نویسه *dllname;
    ثابت نویسه *name;

    rva_base = pe->thunk->sh_addr - pe->imagebase;
    sym_شمار = 0, sorted = پوچ, op = پوچ;

    sym_end = symtab_section->data_offset / اندازه(ElfW(Sym));
    برای (sym_index = 1; sym_index < sym_end; ++sym_index) {
        sym = (ElfW(Sym)*)symtab_section->data + sym_index;
        name = pe_export_name(s1, sym);
        اگر (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(اندازه *p);
            p->index = sym_index;
            p->name = name;
            dynarray_add(&sorted, &sym_شمار, p);
        }
#اگر 0
        اگر (sym->st_other & ST_PE_EXPORT)
            printf("export: %s\n", name);
        اگر (sym->st_other & ST_PE_STDCALL)
            printf("stdcall: %s\n", name);
#endif
    }

    اگر (0 == sym_شمار)
        بازگشت;

    qsort (sorted, sym_شمار, اندازه *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    base_o = pe->thunk->data_offset;
    func_o = base_o + اندازه(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_شمار * اندازه (DWORD);
    ord_o = name_o + sym_شمار * اندازه (DWORD);
    str_o = ord_o + sym_شمار * اندازه(WORD);

    hdr = section_ptr_add(pe->thunk, str_o - base_o);
    hdr->Characteristics        = 0;
    hdr->Base                   = 1;
    hdr->عدد_Of_Functions      = sym_شمار;
    hdr->عدد_Of_Names          = sym_شمار;
    hdr->AddressOfFunctions     = func_o + rva_base;
    hdr->AddressOfNames         = name_o + rva_base;
    hdr->AddressOfNameOrdinals  = ord_o + rva_base;
    hdr->Name                   = str_o + rva_base;
    put_elf_str(pe->thunk, dllname);

#اگر 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, اندازه buf, pe->filename);
    strcpy(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    اگر (پوچ == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } وگرنه {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        اگر (s1->verbose)
            printf("<- %s (%d symbol%s)\n", buf, sym_شمار, &"s"[sym_شمار < 2]);
    }
#endif

    برای (ord = 0; ord < sym_شمار; ++ord)
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
        func_o += اندازه (DWORD);
        name_o += اندازه (DWORD);
        ord_o += اندازه (WORD);
        اگر (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = base_o + rva_base;
    pe->exp_size = pe->thunk->data_offset - base_o;
    dynarray_reset(&sorted, &sym_شمار);
    اگر (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
ایستا تهی pe_build_reloc (ساختار pe_info *pe)
{
    DWORD offset, block_ptr, sh_addr, addr;
    صحیح شمار_2, i;
    ElfW_Rel *rel, *rel_end;
    Section *s = پوچ, *sr;
    ساختار pe_reloc_header *hdr;
    TCCState *s1 = pe->s1;
    صحیح dwarf = 0, n;

    sh_addr = offset = block_ptr = شمار_2 = i = 0;
    rel = rel_end = پوچ;

    برای(;;) {
        اگر (rel < rel_end) {
            صحیح type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_offset + sh_addr;
            ++ rel;
            اگر (type != REL_TYPE_DIRECT)
                ادامه;
            اگر (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->data + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                اگر (n >= s1->dwlo && n < s1->dwhi)
                    ادامه;
            }
            اگر (شمار_2 == 0) { /* new block */
                block_ptr = pe->reloc->data_offset;
                section_ptr_add(pe->reloc, اندازه(ساختار pe_reloc_header));
                offset = addr & 0xFFFFFFFF<<12;
            }
            اگر ((addr -= offset)  < (1<<12)) { /* one block spans 4k addresses */
                WORD *wp = section_ptr_add(pe->reloc, اندازه (WORD));
                *wp = addr | PE_IMAGE_REL<<12;
                ++شمار_2;
                ادامه;
            }
            -- rel;

        } وگرنه اگر (s) {
            sr = s->reloc;
            اگر (sr) {
                rel = (ElfW_Rel *)sr->data;
                rel_end = (ElfW_Rel *)(sr->data + sr->data_offset);
                sh_addr = s->sh_addr;
                dwarf = s->sh_رقم >= s1->dwlo && s->sh_رقم < s1->dwhi;
            }
            s = s->prev;
            ادامه;

        } وگرنه اگر (i < pe->sec_شمار) {
            s = pe->sec_info[i]->sec, ++i;
            ادامه;

        } وگرنه اگر (!شمار_2)
            بشکن;

        /* fill the last block and ready for a new one */
        اگر (شمار_2 & 1) /* align for DWORDS */
            section_ptr_add(pe->reloc, اندازه(WORD)), ++شمار_2;
        hdr = (ساختار pe_reloc_header *)(pe->reloc->data + block_ptr);
        hdr -> offset = offset - pe->imagebase;
        hdr -> size = شمار_2 * اندازه(WORD) + اندازه(ساختار pe_reloc_header);
        شمار_2 = 0;
    }
}

/* ------------------------------------------------------------- */
ایستا تهی pe_build_tls(ساختار pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    صحیح c, n;

    اگر (0 == s) {
        pe->tls_size = اندازه (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_add(pe->thunk, pe->tls_size, 16);
        pe->tls_data = section_add(data_section, PTR_SIZE * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, data_section->sh_رقم, 0);
        برای (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_SIZE*n, REL_TYPE_DIRECT, c);
        /* for generators */
        set_elf_sym(symtab_section, pe->tls_data, PTR_SIZE * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, data_section->sh_رقم, "__tls_index");
        بازگشت;
    }

    اگر (0 == s1->tls_start)
        s1->tls_start = s->sh_addr;
    d = (تهی*)(pe->thunk->data + pe->tls_dir);
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
ایستا صحیح pe_section_class(Section *s)
{
    صحیح type, flags;
    ثابت نویسه *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    اگر (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        بازگشت sec_debug;
    } وگرنه اگر (flags & SHF_ALLOC) {
        اگر (flags & SHF_TLS)
            بازگشت sec_tdata + (type == SHT_NOBITS);
        اگر (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            اگر (flags & SHF_EXECINSTR)
                بازگشت sec_text;
            اگر (flags & SHF_WRITE)
                بازگشت sec_data;
            اگر (0 == strcmp(name, ".rsrc"))
                بازگشت sec_rsrc;
            اگر (0 == strcmp(name, ".iedat"))
                بازگشت sec_idata;
            اگر (0 == strcmp(name, ".pdata"))
                بازگشت sec_pdata;
            بازگشت sec_rdata;
        } وگرنه اگر (type == SHT_NOBITS) {
            بازگشت sec_bss;
        }
        بازگشت sec_other;
    } وگرنه {
        اگر (0 == strcmp(name, ".reloc"))
            بازگشت sec_reloc;
    }
    بازگشت sec_last;
}

ایستا صحیح pe_assign_addresses (ساختار pe_info *pe)
{
    صحیح i, k, n, c, nbs;
    ADDR3264 addr;
    صحیح *sec_order, *sec_cls;
    ساختار section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    اگر (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_order = tcc_mallocz(2 * اندازه (صحیح) * nbs);
    sec_cls = sec_order + nbs;
    برای (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        برای (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
        اگر ((s->sh_flags & SHF_TLS) && 0 == pe->tls_size)
            pe_build_tls(pe, پوچ);
    }
    si = پوچ;
    addr = pe->imagebase + 1;
    برای (i = 1; (c = sec_cls[i]) < sec_last; ++i) {
        s = s1->sections[sec_order[i]];

        اگر (PE_MERGE_DATA && c == sec_bss)
            c = sec_data;
        اگر (c == sec_tbss)
            c = sec_tdata;

        اگر (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } وگرنه {
            si = پوچ;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        اگر (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        اگر (s == pe->reloc)
            pe_build_reloc (pe);

        اگر (0 == s->data_offset)
            ادامه;

        اگر (si)
            برو add_section;

        si = tcc_mallocz(اندازه *si);
        dynarray_add(&pe->sec_info, &pe->sec_شمار, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        اگر (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_CODE;
        وگرنه اگر (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_DATA;
        وگرنه
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_DATA;
        اگر (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        اگر (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

add_section:
        s->sh_info = pe->sec_شمار; /* section number for coff syms */
        addr += s->data_offset;
        si->sh_size = addr - si->sh_addr;
        اگر (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            وقتی (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = پوچ;
            si->data_size = si->sh_size;
        }

        اگر (s->sh_flags & SHF_TLS) {
            strcpy(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#اگر 0
    برای (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_order[i]];
        صحیح type = s->sh_type;
        صحیح flags = s->sh_flags;
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
    بازگشت 0;
}

/*----------------------------------------------------------------------------*/
ایستا صحیح pe_check_symbols(ساختار pe_info *pe)
{
    صحیح sym_index, sym_end;
    صحیح ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(text_section, 8);

    sym_end = symtab_section->data_offset / اندازه(ElfW(Sym));
    برای (sym_index = 1; sym_index < sym_end; ++sym_index) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
        اگر (sym->st_shndx == SHN_UNDEF) {
            ثابت نویسه *name = (نویسه*)symtab_section->link->data + sym->st_name;
            unsigned type = ELFW(ST_TYPE)(sym->st_info);
            صحیح imp_sym = 0;
            ساختار import_نماد *is;

            صحیح _imp_, n;
            نویسه buffer[200];
            ثابت نویسه *s, *p;

            n = _imp_ = 0;
            اگر (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            انجامبده {
                s = pe_export_name(s1, sym);
                اگر (n) {
                    /* second try: */
                    اگر (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        اگر (!p || s[0] != '_')
                            بشکن;
                        strcpy(buffer, s+1)[p-s-1] = 0, s = buffer;
                    } وگرنه اگر (s[0] != '_') { /* try non-ansi function */
                        buffer[0] = '_', strcpy(buffer + 1, s), s = buffer;
                    } وگرنه اگر (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } وگرنه اگر (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } وگرنه {
                        بشکن;
                    }
                }
                imp_sym = find_elf_sym(s1->dynsymtab_section, s);
            } وقتی (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            اگر (0 == imp_sym)
                ادامه; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_add_import(pe, imp_sym);

            اگر (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                unsigned offset = is->thk_offset;
                اگر (offset) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } وگرنه {
                    unsigned نویسه *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(buffer, "IAT.%s", name);
                    is->iat_index = put_elf_sym(
                        symtab_section, 0, اندازه(DWORD),
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
#وگرنهاگر defined(TCC_TARGET_ARM64)
                    p = section_ptr_add(text_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, text_section,
                        offset + 16, R_XXX_THUNKFIX, is->iat_index);
#وگرنه
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
                sym->st_مقدار = offset;
                sym->st_shndx = text_section->sh_رقم;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } وگرنه { /* STT_OBJECT */
                اگر (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_مقدار = is->iat_index; /* chain potential alias */
                is->iat_index = sym_index;
            }

        } وگرنه اگر (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    بازگشت ret;
}

/*----------------------------------------------------------------------------*/
#اگر PE_PRINT_SECTIONS
ایستا تهی pe_print_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    صحیح i, n, l, m;
    p = s->data;
    e = s->data + s->data_offset;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    اگر (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    اگر (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (unsigned)s->sh_addr);
    fprintf(f, "\ncontents %08X", (unsigned)l);
    fprintf(f, "\n\n");

    اگر (s->sh_type == SHT_NOBITS)
        بازگشت;

    اگر (0 == l)
        بازگشت;

    اگر (s->sh_type == SHT_SYMTAB)
        m = اندازه(ElfW(Sym));
    وگرنه اگر (s->sh_type == SHT_RELX)
        m = اندازه(ElfW_Rel);
    وگرنه
        m = 16;

    fprintf(f, "%-8s", "offset");
    برای (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    اگر (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        ثابت نویسه *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            پوچ
        };

        ثابت نویسه *fields2[] = {
            "offs",
            "type",
            "symb",
            پوچ
        };

        ثابت نویسه **p;

        اگر (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        وگرنه
            p = fields2, n = 58;

        برای (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    برای (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    برای (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        برای (n = 0; n < m; ++n) {
            اگر (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            وگرنه
                fprintf(f, "   ");
        }

        اگر (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            ثابت نویسه *name = s->link->data + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (unsigned)sym->st_name,
                    (unsigned)sym->st_مقدار,
                    (unsigned)sym->st_size,
                    (unsigned)ELFW(ST_BIND)(sym->st_info),
                    (unsigned)ELFW(ST_TYPE)(sym->st_info),
                    (unsigned)sym->st_other,
                    (unsigned)sym->st_shndx,
                    name);

        } وگرنه اگر (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->data + ELFW(R_SYM)(rel->r_info);
            ثابت نویسه *name = s->link->link->data + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (unsigned)rel->r_offset,
                    (unsigned)ELFW(R_TYPE)(rel->r_info),
                    (unsigned)ELFW(R_SYM)(rel->r_info),
                    name);
        } وگرنه {
            fprintf(f, "   ");
            برای (n = 0; n < m; ++n) {
                اگر (n + i < l) {
                    b = p[i + n];
                    اگر (b < 32 || b >= 127)
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

ایستا تهی pe_print_sections(TCCState *s1, ثابت نویسه *fname)
{
    Section *s;
    FILE *f;
    صحیح i;
    f = fopen(fname, "w");
    برای (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    fclose(f);
}
#endif

/* ------------------------------------------------------------- */

ST_FUNC صحیح pe_putimport(TCCState *s1, صحیح dllindex, ثابت نویسه *name, addr_t مقدار)
{
    بازگشت set_elf_sym(
        s1->dynsymtab_section,
        مقدار,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        مقدار ? SHN_ABS : SHN_UNDEF,
        name
        );
}

ایستا صحیح read_mem(صحیح fd, unsigned offset, تهی *buffer, unsigned len)
{
    lseek(fd, offset, SEEK_SET);
    بازگشت len == اقرأ(fd, buffer, len);
}

/* ------------------------------------------------------------- */

ایستا صحیح get_dllexports(صحیح fd, نویسه **pp)
{
    صحیح i, k, l, n, n0, ret;
    نویسه *p;

    IMAGE_SECTION_HEADER ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_HEADER dh;
    IMAGE_FILE_HEADER ih;
    DWORD sig, ref, addr;
    DWORD *namep = پوچ, p0 = 0, p1;

    صحیح pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = پوچ;
    ret = 1;
    اگر (!read_mem(fd, 0, &dh, اندازه dh))
        برو the_end;
    اگر (!read_mem(fd, dh.e_lfanew, &sig, اندازه sig))
        برو the_end;
    اگر (sig != 0x00004550)
        برو the_end;
    pef_hdroffset = dh.e_lfanew + اندازه sig;
    اگر (!read_mem(fd, pef_hdroffset, &ih, اندازه ih))
        برو the_end;
    opt_hdroffset = pef_hdroffset + اندازه ih;
    اگر (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + اندازه oh;
        اگر (!read_mem(fd, opt_hdroffset, &oh, اندازه oh))
            برو the_end;
        اگر (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.عدد_Of_Rva_And_Sizes)
            برو the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } وگرنه اگر (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + اندازه oh;
        اگر (!read_mem(fd, opt_hdroffset, &oh, اندازه oh))
            برو the_end;
        اگر (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.عدد_Of_Rva_And_Sizes)
            برو the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } وگرنه
        برو the_end;

    //printf("addr: %08x\n", addr);
    برای (i = 0; i < ih.عدد_Of_Sections; ++i) {
        اگر (!read_mem(fd, sec_hdroffset + i * اندازه ish, &ish, اندازه ish))
            برو the_end;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        اگر (addr >= ish.VirtualAddress && addr < ish.VirtualAddress + ish.SizeOfRawData)
            برو found;
    }
    برو the_end_0;
found:
    ref = ish.VirtualAddress - ish.PointerToRawData;
    اگر (!read_mem(fd, addr - ref, &ied, اندازه ied))
        برو the_end;
    k = ied.عدد_Of_Names;
    اگر (k) {
        namep = tcc_malloc(l = k * اندازه *namep);
        اگر (!read_mem(fd, ied.AddressOfNames - ref, namep, l))
            برو the_end;
        برای (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            اگر (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            انجامبده {
                اگر (0 == l) {
                    اگر (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    اگر ((l = اقرأ(fd, p + n, 1000 - 1)) <= 0)
                        برو the_end;
                }
                --l, ++p0;
            } وقتی (p[n++]);
        }
        p[n] = 0;
    }
the_end_0:
    ret = 0;
the_end:
    tcc_free(namep);
    اگر (ret && p)
        tcc_free(p), p = پوچ;
    *pp = p;
    بازگشت ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

ایستا صحیح pe_load_res(TCCState *s1, صحیح fd)
{
    ساختار pe_rsrc_header hdr;
    Section *rsrc_section;
    صحیح i, ret = -1, sym_index;
    BYTE *ptr;
    unsigned offs;

    اگر (!read_mem(fd, 0, &hdr, اندازه hdr))
        برو quit;

    اگر (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.عدد_Of_Sections != 1
        || strcmp((نویسه*)hdr.sectionhdr.Name, ".rsrc") != 0)
        برو quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_add(rsrc_section, hdr.sectionhdr.SizeOfRawData);
    offs = hdr.sectionhdr.PointerToRawData;
    اگر (!read_mem(fd, offs, ptr, hdr.sectionhdr.SizeOfRawData))
        برو quit;
    offs = hdr.sectionhdr.PointerToRelocations;
    sym_index = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_رقم, ".rsrc");
    برای (i = 0; i < hdr.sectionhdr.عدد_Of_Relocations; ++i) {
        ساختار pe_rsrc_reloc rel;
        اگر (!read_mem(fd, offs, &rel, اندازه rel))
            برو quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        اگر (rel.type != RSRC_RELTYPE)
            برو quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.offset, R_XXX_RELATIVE, sym_index);
        offs += اندازه rel;
    }
    ret = 0;
quit:
    بازگشت ret;
}

/* ------------------------------------------------------------- */

ایستا نویسه *trimfront(نویسه *p)
{
    وقتی ((unsigned نویسه)*p <= ' ' && *p && *p != '\n')
	++p;
    بازگشت p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

ایستا نویسه *get_token(نویسه **s, نویسه *f)
{
    نویسه *p, *e;
    صحیح q;

    p = trimfront(*s);
    q = *p;
    اگر (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    وگرنه
        q = ' ';
    برای (e = p; (unsigned نویسه)*e >= ' ' && *e != q; ++e)
        ;
    اگر (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    بازگشت p;
}

ایستا صحیح pe_load_def(TCCState *s1, صحیح fd)
{
    صحیح state = 0, ret = -1, dllindex = 0, ord;
    نویسه dllname[80], *buf, *سطر, *p, *x, next;

    buf = tcc_load_text(fd);
    اگر (!buf)
        بازگشت ret;

    برای (سطر = buf;; ++سطر)  {
        p = get_token(&سطر, &next);
        اگر (!(*p && *p != ';'))
            برو skip;
        انتخاب (state) {
        حالت 0:
            اگر (0 != stricmp(p, "LIBRARY") || next == '\n')
                برو quit;
            pstrcpy(dllname, اندازه dllname, get_token(&سطر, &next));
            اگر (!*tcc_fileextension(dllname))
                pstrcat(dllname, اندازه dllname, ".dll");
            ++state;
            بشکن;
        حالت 1:
            اگر (0 != stricmp(p, "EXPORTS"))
                برو quit;
            ++state;
            بشکن;
        حالت 2:
            dllindex = tcc_add_dllref(s1, dllname, 0)->index;
            ++state;
            /* fall through */
        پیشفرض:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            اگر (next == '@') {
                x = get_token(&سطر, &next);
                ord = (صحیح)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            بشکن;
        }
skip:
        وقتی ((unsigned نویسه)next > ' ')
            get_token(&سطر, &next);
        اگر (next != '\n')
            بشکن;
    }
    ret = 0;
quit:
    tcc_free(buf);
    بازگشت ret;
}

/* ------------------------------------------------------------- */

ایستا صحیح pe_load_dll(TCCState *s1, صحیح fd, ثابت نویسه *filename)
{
    نویسه *p, *q;
    DLLReference *ref = tcc_add_dllref(s1, filename, 0);
    اگر (ref->found)
        بازگشت 0;
    اگر (get_dllexports(fd, &p))
        بازگشت -1;
    اگر (p) {
        برای (q = p; *q; q += 1 + strlen(q))
            pe_putimport(s1, ref->index, q, 0);
        tcc_free(p);
    }
    بازگشت 0;
}

ST_FUNC صحیح pe_load_file(ساختار TCCState *s1, صحیح fd, ثابت نویسه *filename)
{
    صحیح ret = -1;
    نویسه buf[10];
    اگر (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_load_def(s1, fd);
    وگرنه اگر (pe_load_res(s1, fd) == 0)
        ret = 0;
    وگرنه اگر (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_load_dll(s1, fd, filename);
    بازگشت ret;
}

PUB_FUNC صحیح tcc_get_dllexports(ثابت نویسه *filename, نویسه **pp)
{
    صحیح ret, fd = open(filename, O_RDONLY | O_دودویی_2);
    اگر (fd < 0)
        بازگشت -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    بازگشت ret;
}

/* ------------------------------------------------------------- */
#ifdef TCC_TARGET_X86_64
ایستا unsigned pe_add_unwind_info(TCCState *s1)
{
    اگر (پوچ == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    اگر (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, text_section->sh_رقم, ".uw_base");
    اگر (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        ایستا ثابت unsigned نویسه uw_info[] = {
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
        unsigned نویسه *p;

        section_ptr_add(s, -s->data_offset & 3); /* align */
        s1->uw_offs = s->data_offset;
        p = section_ptr_add(s, اندازه uw_info);
        memcpy(p, uw_info, اندازه uw_info);
    }

    بازگشت s1->uw_offs;
}

ST_FUNC تهی pe_add_unwind_data(unsigned start, unsigned end, unsigned پشته)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    unsigned o, n, d;
    ساختار /* _RUNTIME_FUNCTION */ {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD UnwindData;
    } *p;

    d = pe_add_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->data_offset;
    p = section_ptr_add(pd, اندازه *p);

    /* record this function */
    p->BeginAddress = start;
    p->EndAddress = end;
    p->UnwindData = d;

    /* put relocations on it */
    برای (n = o + اندازه *p; o < n; o += اندازه p->BeginAddress)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#وگرنهاگر defined(TCC_TARGET_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
ایستا Section *pe_add_unwind_info(TCCState *s1)
{
    Section *s;

    اگر (پوچ == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = find_section(s1, ".xdata");
    s->sh_addralign = 4;
    اگر (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  text_section->sh_رقم, ".uw_text_base");
    اگر (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_رقم, ".uw_base");
    بازگشت s;
}

ST_FUNC تهی pe_add_unwind_data(unsigned start, unsigned end, unsigned پشته)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    unsigned o, d, code_bytes, func_len;
    unsigned نویسه *q;
    uint32_t header;
    ساختار /* _RUNTIME_FUNCTION */ {
        DWORD BeginAddress;
        DWORD UnwindData;
    } *p;

    صحیح epilog;

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
    وقتی ((unsigned)(q - (xd->data + d + 4)) < code_bytes)
        *q++ = 0xE3; /* nop padding */

    o = pd->data_offset;
    p = section_ptr_add(pd, اندازه *p);
    p->BeginAddress = start;
    p->UnwindData = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#endif
/* ------------------------------------------------------------- */
#اگر defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
#define PE_STDSYM(n,s) n
#وگرنه
#define PE_STDSYM(n,s) "_" n s
#endif

ایستا تهی pe_add_runtime(TCCState *s1, ساختار pe_info *pe)
{
    ثابت نویسه *start_نماد;
    صحیح pe_type;

    اگر (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        start_نماد = PE_STDSYM("__dllstart","@12");
    } وگرنه {
        ثابت نویسه *run_نماد;
        اگر (find_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            start_نماد = "__winstart";
            run_نماد = "__runwinmain";
            pe_type = PE_GUI;
        } وگرنه اگر (find_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            start_نماد = "__wwinstart";
            run_نماد = "__runwwinmain";
            pe_type = PE_GUI;
        } وگرنه اگر (find_elf_sym(symtab_section, "wmain")) {
            start_نماد = "__wstart";
            run_نماد = "__runwmain";
            pe_type = PE_EXE;
        } وگرنه {
            start_نماد =  "__start";
            run_نماد = "__runmain";
            pe_type = PE_EXE;
            اگر (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        اگر (TCC_OUTPUT_MEMORY == s1->output_type && !s1->nostdlib)
            start_نماد = run_نماد;
    }
    اگر (s1->elf_entryname) {
        pe->start_نماد = start_نماد = s1->elf_entryname;
    } وگرنه {
        pe->start_نماد = start_نماد + 1;
        اگر (!s1->leading_underscore || strchr(start_نماد, '@'))
            ++start_نماد;
    }

#ifdef CONFIG_TCC_BACKTRACE
    اگر (s1->do_backtrace) {
#ifdef CONFIG_TCC_BCHECK
        اگر (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    اگر (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    وگرنه
                tcc_add_support(s1, "bcheck.o");
	}
#endif
        اگر (s1->output_type == TCC_OUTPUT_EXE)
            tcc_add_support(s1, "bt-exe.o");
        اگر (s1->output_type == TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-dll.o");
        اگر (s1->output_type != TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-log.o");
        tcc_add_btstub(s1);
    }
#endif

    /* grab the startup code from libtcc1.a */
#ifdef TCC_IS_NATIVE
    اگر (TCC_OUTPUT_MEMORY != s1->output_type || s1->run_main)
#endif
    set_global_sym(s1, start_نماد, پوچ, 0);

    اگر (0 == s1->nostdlib) {
        ایستا ثابت نویسه * ثابت libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", پوچ
        };
        ثابت نویسه * ثابت *pp, *p;
        اگر (TCC_LIBTCC1[0])
            tcc_add_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        برای (pp = libs; 0 != (p = *pp); ++pp) {
            اگر (*p)
                tcc_add_library(s1, p);
            وگرنه اگر (PE_DLL != pe_type && PE_GUI != pe_type)
                بشکن;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    اگر (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    اگر (TCC_OUTPUT_MEMORY == s1->output_type)
        pe_type = PE_RUN;
    pe->type = pe_type;
}

ST_FUNC صحیح pe_setsubsy(TCCState *s1, ثابت نویسه *arg)
{
    ایستا ثابت ساختار subsy { ثابت نویسه* p; صحیح v; } x[] = {
#اگر defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#وگرنهاگر defined(TCC_TARGET_ARM)
        { "wince", 9 },
#endif
        { 0, -1 }};
    ثابت ساختار subsy *y;
    برای (y = x;; ++y) {
        اگر (!y->p)
            بازگشت -1;
        اگر (0 == strcmp(y->p, arg)) {
            s1->pe_subsystem = y->v;
            بازگشت 0;
        }
    }
}

ایستا تهی pe_set_options(TCCState * s1, ساختار pe_info *pe)
{
    اگر (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_BASE_DLL;
    } وگرنه {
        pe->imagebase = IMAGE_BASE_EXE;
    }

#اگر defined(TCC_TARGET_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#وگرنه
    اگر (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    وگرنه
        pe->subsystem = 3;
#endif
    /* Allow override via -Wl,-subsystem=... option */
    اگر (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    اگر (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } وگرنه {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    اگر (s1->section_align != 0)
        pe->section_align = s1->section_align;
    اگر (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    اگر ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    اگر (s1->has_text_addr)
        pe->imagebase = s1->text_addr;
}

ST_FUNC صحیح pe_output_file(TCCState *s1, ثابت نویسه *filename)
{
    ساختار pe_info pe;

    memset(&pe, 0, اندازه pe);
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
    اگر (s1->nb_errors)
        برو done;
    اگر (filename) {
        pe_assign_addresses(&pe);
        relocate_syms(s1, s1->symtab, 0);
        اگر (s1->nb_errors)
            برو done;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.start_addr = (DWORD)
            (get_sym_addr(s1, pe.start_نماد, 1, 1) - pe.imagebase);
        اگر (s1->nb_errors)
            برو done;
        pe_write(&pe);
    } وگرنه {
        /* -run */
#ifdef TCC_IS_NATIVE
        pe.thunk = data_section;
        pe_build_imports(&pe);
        s1->run_main = pe.start_نماد;
#اگر defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        s1->uw_pdata = find_section(s1, ".pdata");
#endif
#endif
    }
done:
    dynarray_reset(&pe.sec_info, &pe.sec_شمار);
    pe_free_imports(&pe);
#اگر PE_PRINT_SECTIONS
    اگر (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#endif
    بازگشت s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
