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

#অন্তর্ভাৱ "tcc.h"

#define PE_MERGE_DATA 1
#define PE_PRINT_SECTIONS 0

#ifndef _WIN32
#define stricmp strcasecmp
#define strnicmp strncasecmp
#অন্তর্ভাৱ <sys/stat.h> /* chmod() */
#endif

#যদি defined TCC_TARGET_X86_64
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

#নোচেদ্যদি defined TCC_TARGET_ARM
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

#নোচেদ্যদি defined TCC_TARGET_ARM64
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

#নোচেদ্যদি defined TCC_TARGET_I386
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

#যদি PTR_SIZE == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#অন্যথা
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#endif

#ifndef IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

প্রকারনির্দেশ unsigned ৱর্ণ BYTE;
প্রকারনির্দেশ unsigned short WORD;
প্রকারনির্দেশ unsigned পূর্ণাঙ্ক DWORD;
প্রকারনির্দেশ unsigned long long ULONGLONG;
#pragma pack(ঠেলো, 1)

প্রকারনির্দেশ সংরচনা _IMAGE_DOS_HEADER {  /* DOS .EXE header */
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

প্রকারনির্দেশ সংরচনা _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    সংখ্যা_Of_Sections;
    DWORD   TimeDateStamp;
    DWORD   Pointer_To_প্ৰতীক_Table;
    DWORD   সংখ্যা_Of_Symbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;


#define IMAGE_SIZEOF_FILE_HEADER 20

প্রকারনির্দেশ সংরচনা _IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;


প্রকারনির্দেশ সংরচনা _IMAGE_OPTIONAL_HEADER {
    /* Standard fields. */
    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
#যদি PTR_SIZE == 4
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
    DWORD   Win32_Version_মান;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    ADDR3264 Size_Of_স্তূপ_Reserve;
    ADDR3264 Size_Of_স্তূপ_Commit;
    ADDR3264 SizeOfHeapReserve;
    ADDR3264 SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   সংখ্যা_Of_Rva_And_Sizes;
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

প্রকারনির্দেশ সংরচনা _IMAGE_SECTION_HEADER {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    সঙ্ঘ {
            DWORD   PhysicalAddress;
            DWORD   VirtualSize;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   SizeOfRawData;
    DWORD   PointerToRawData;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    সংখ্যা_Of_Relocations;
    WORD    সংখ্যা_Of_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#define IMAGE_SIZEOF_SECTION_HEADER     40

প্রকারনির্দেশ সংরচনা _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD Name;
    DWORD Base;
    DWORD সংখ্যা_Of_Functions;
    DWORD সংখ্যা_Of_Names;
    DWORD AddressOfFunctions;
    DWORD AddressOfNames;
    DWORD AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

প্রকারনির্দেশ সংরচনা _IMAGE_TLS_DIRECTORY {
    ADDR3264 StartAddressOfRawData;
    ADDR3264 EndAddressOfRawData;
    ADDR3264 AddressOfIndex;
    ADDR3264 AddressOfCallBacks;
    DWORD SizeOfZeroFill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

প্রকারনির্দেশ সংরচনা _IMAGE_IMPORT_DESCRIPTOR {
    সঙ্ঘ {
        DWORD Characteristics;
        DWORD OriginalFirstThunk;
    };
    DWORD TimeDateStamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;

প্রকারনির্দেশ সংরচনা _IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   SizeOfBlock;
//  WORD    TypeOffset[1];
} IMAGE_BASE_RELOCATION;

#define IMAGE_SIZEOF_BASE_RELOCATION     8

#define IMAGE_REL_BASED_ABSOLUTE         0
#define IMAGE_REL_BASED_উপৰেৰ             1
#define IMAGE_REL_BASED_নিচেৰ              2
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

#define IMAGE_DLLCHARACTERISTICS_উপৰেৰ_ENTROPY_VA 0x0020
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#define IMAGE_FILE_RELOCS_STRIPPED 0x0001

#pragma pack(বেৰ_কৰো)

/* ----------------------------------------------------------- */
#endif /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#ifndef IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#endif

#pragma pack(ঠেলো, 1)
সংরচনা pe_header
{
    IMAGE_DOS_HEADER doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_HEADER filehdr;
#যদি PTR_SIZE == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#অন্যথা
#ifdef _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#অন্যথা
    IMAGE_OPTIONAL_HEADER opthdr;
#endif
#endif
};

সংরচনা pe_reloc_header {
    DWORD offset;
    DWORD size;
};

সংরচনা pe_rsrc_header {
    সংরচনা _IMAGE_FILE_HEADER filehdr;
    সংরচনা _IMAGE_SECTION_HEADER sectionhdr;
};

সংরচনা pe_rsrc_reloc {
    DWORD offset;
    DWORD size;
    WORD type;
};
#pragma pack(বেৰ_কৰো)

/* ------------------------------------------------------------- */
/* internal temporary structures */

গণনা {
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

#যদি 0
স্থির ধ্রুৱ DWORD pe_sec_flags[] = {
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

সংরচনা section_info {
    পূর্ণাঙ্ক cls;
    ৱর্ণ name[32];
    ADDR3264 sh_addr;
    DWORD sh_size;
    DWORD pe_flags;
    Section *sec;
    DWORD data_size;
    IMAGE_SECTION_HEADER ish;
};

সংরচনা import_প্ৰতীক {
    পূর্ণাঙ্ক sym_index;
    পূর্ণাঙ্ক iat_index;
    পূর্ণাঙ্ক thk_offset;
};

সংরচনা pe_import_info {
    পূর্ণাঙ্ক dll_index;
    পূর্ণাঙ্ক sym_গুনতি;
    সংরচনা import_প্ৰতীক **symbols;
};

সংরচনা pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    ধ্রুৱ ৱর্ণ *filename;
    পূর্ণাঙ্ক type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    ধ্রুৱ ৱর্ণ *start_প্ৰতীক;
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
    পূর্ণাঙ্ক subsystem;
    DWORD section_align;
    DWORD file_align;
    সংরচনা section_info **sec_info;
    পূর্ণাঙ্ক sec_গুনতি;
    সংরচনা pe_import_info **imp_info;
    পূর্ণাঙ্ক imp_গুনতি;
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

স্থির ধ্রুৱ ৱর্ণ *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    ধ্রুৱ ৱর্ণ *name = (ৱর্ণ*)symtab_section->link->data + sym->st_name;
    যদি (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        ঘূৰাই name + 1;
    ঘূৰাই name;
}


স্থির পূর্ণাঙ্ক dynarray_assoc(শূন্য **pp, পূর্ণাঙ্ক n, পূর্ণাঙ্ক চাবি)
{
    পূর্ণাঙ্ক i;
    বাবে (i = 0; i < n; ++i, ++pp)
    যদি (চাবি == **(পূর্ণাঙ্ক **) pp)
        ঘূৰাই i;
    ঘূৰাই -1;
}

স্থির DWORD umin(DWORD a, DWORD b)
{
    ঘূৰাই a < b ? a : b;
}

স্থির DWORD umax(DWORD a, DWORD b)
{
    ঘূৰাই a < b ? b : a;
}

স্থির DWORD pe_file_align(সংরচনা pe_info *pe, DWORD n)
{
    ঘূৰাই (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

স্থির ADDR3264 pe_virtual_align(সংরচনা pe_info *pe, ADDR3264 n)
{
    ঘূৰাই (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

স্থির শূন্য pe_align_section(Section *s, পূর্ণাঙ্ক a)
{
    পূর্ণাঙ্ক i = s->data_offset & (a-1);
    যদি (i)
        section_ptr_add(s, a - i);
}

স্থির শূন্য pe_set_datadir(সংরচনা pe_header *hdr, পূর্ণাঙ্ক dir, DWORD addr, DWORD size)
{
    hdr->opthdr.DataDirectory[dir].VirtualAddress = addr;
    hdr->opthdr.DataDirectory[dir].Size = size;
}

স্থির পূর্ণাঙ্ক pe_fwrite(সংরচনা pe_info *pe, ধ্রুৱ শূন্য *data, পূর্ণাঙ্ক len)
{
    ধ্রুৱ WORD *p = data;
    DWORD sum;
    পূর্ণাঙ্ক ret, i;
    pe->pos += (ret = fwrite(data, 1, len, pe->op));
    sum = pe->sum;
    বাবে (i = len; i > 0; i -= 2) {
        sum += (i >= 2) ? *p++ : *(BYTE*)p;
        sum = (sum + (sum >> 16)) & 0xFFFF;
    }
    pe->sum = sum;
    ঘূৰাই len == ret ? 0 : -1;
}

স্থির শূন্য pe_fpad(সংরচনা pe_info *pe, DWORD new_pos)
{
    ৱর্ণ buf[256];
    পূর্ণাঙ্ক n, diff = new_pos - pe->pos;
    memset(buf, 0, পরিমাণ buf);
    যেতিয়ালৈ (diff > 0) {
        diff -= n = umin(diff, পরিমাণ buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#pragma pack(ঠেলো, 1)
সংরচনা syment
{
    সঙ্ঘ {
        ৱর্ণ        n_name[8];     /* old COFF version */
        সংরচনা {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_offset;      /* offset into string table */
        };
    };
    int32_t         n_মান;        /* value of symbol */
    short           n_scnum;        /* section number */
    unsigned short  n_type;         /* type and derived type */
    ৱর্ণ            n_sclass;       /* storage class */
    ৱর্ণ            n_numaux;       /* number of aux. entries */
};
#pragma pack(বেৰ_কৰো)

#define SHF_PRIVATE 0x80000000

স্থির শূন্য pe_add_coffsym(সংরচনা pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    সংরচনা syment *se;
    পূর্ণাঙ্ক n;

    যদি (রিক্ত == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_PRIVATE);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_PRIVATE);
        section_ptr_add(pe->coffstr, 4); /* coff string table size */
        ঘূৰাই;
    }

#যদি 0
    se = section_ptr_add(pe->coffsym, পরিমাণ *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_add(pe->coffsym, পরিমাণ *se);
    strcpy((ৱর্ণ*)se, "no-file");
#endif

#যদি 1
    esym = (ElfSym*)s1->symtab->data;
    বাবে (n = s1->symtab->data_offset / পরিমাণ *esym; ++esym, --n;) {
        পূর্ণাঙ্ক sym_bind = ELFW(ST_BIND)(esym->st_info);
        যদি (sym_bind == STB_GLOBAL) {
            ৱর্ণ *name = esym->st_name + (ৱর্ণ*)s1->symtab->link->data;
            পূর্ণাঙ্ক nl = strlen(name);
            addr_t মান = esym->st_মান;
            পূর্ণাঙ্ক shnum = esym->st_shndx;
            যদি (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                মান = মান - s->sh_addr;
            }
            se = section_ptr_add(pe->coffsym, পরিমাণ *se);
            se->n_মান = মান;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            যদি (nl <= 8)
                memcpy(se->n_name, name, nl);
            অন্যথা
                se->n_offset = put_elf_str(pe->coffstr, name);
        }
    }
#endif
    write32le(pe->coffstr->data, pe->coffstr->data_offset); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
স্থির শূন্য pe_create_pdb(TCCState *s1, ধ্রুৱ ৱর্ণ *exename)
{
    ৱর্ণ buf[300]; পূর্ণাঙ্ক r;
    snprintf(buf, পরিমাণ buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    strcpy(tcc_fileextension(strcpy(buf, exename)), ".pdb");
    যদি (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } অন্যথা যদি (s1->verbose) {
        printf("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
স্থির পূর্ণাঙ্ক pe_write(সংরচনা pe_info *pe)
{
    স্থির ধ্রুৱ সংরচনা pe_header pe_template = {
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
#যদি PTR_SIZE == 4
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

    সংরচনা pe_header pe_header = pe_template;

    পূর্ণাঙ্ক i;
    DWORD file_offset;
    সংরচনা section_info *si;
    IMAGE_SECTION_HEADER *psh;
    TCCState *s1 = pe->s1;

    যদি (s1->do_debug)
        pe_add_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    যদি (রিক্ত == pe->op)
        ঘূৰাই tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        পরিমাণ (সংরচনা pe_header)
        + pe->sec_গুনতি * পরিমাণ (IMAGE_SECTION_HEADER)
        );

    file_offset = pe->sizeofheaders;

    যদি (2 == s1->verbose)
        printf("-------------------------------"
               "\n  virt   file   size  section" "\n");
    বাবে (i = 0; i < pe->sec_গুনতি; ++i) {
        DWORD addr, size;
        ধ্রুৱ ৱর্ণ *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        size = si->sh_size;
        psh = &si->ish;

        যদি (2 == s1->verbose)
            printf("%6x %6x %6x  %s\n",
                (unsigned)addr, (unsigned)file_offset, (unsigned)size, sh_name);

        ৱিকল্প (si->cls) {
            পক্ষ sec_text:
                যদি (!pe_header.opthdr.BaseOfCode)
                    pe_header.opthdr.BaseOfCode = addr;
                ভঙ্গ;

            পক্ষ sec_data:
#যদি PTR_SIZE == 4
                যদি (!pe_header.opthdr.BaseOfData)
                    pe_header.opthdr.BaseOfData = addr;
#endif
                ভঙ্গ;

            পক্ষ sec_bss:
                ভঙ্গ;

            পক্ষ sec_reloc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_BASERELOC, addr, size);
                ভঙ্গ;

            পক্ষ sec_rsrc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_RESOURCE, addr, size);
                ভঙ্গ;

            পক্ষ sec_pdata:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXCEPTION, addr, size);
                ভঙ্গ;
        }

        যদি (pe->imp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IMPORT,
                pe->imp_offs, pe->imp_size);
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IAT,
                pe->iat_offs, pe->iat_size);
        }
        যদি (pe->exp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXPORT,
                pe->exp_offs, pe->exp_size);
        }
        যদি (pe->tls_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_size);
        }

        memcpy(psh->Name, sh_name, umin(strlen(sh_name), পরিমাণ psh->Name));
        যদি (pe->coffstr && strlen(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((ৱর্ণ*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->VirtualAddress = addr;
        psh->Misc.VirtualSize = size;
        pe_header.opthdr.SizeOfImage =
            umax(pe_virtual_align(pe, size + addr), pe_header.opthdr.SizeOfImage);

        যদি (si->data_size) {
            psh->PointerToRawData = file_offset;
            file_offset = pe_file_align(pe, file_offset + si->data_size);
            psh->SizeOfRawData = file_offset - psh->PointerToRawData;
            যদি (si->cls == sec_text)
                pe_header.opthdr.SizeOfCode += psh->SizeOfRawData;
            অন্যথা
                pe_header.opthdr.SizeOfInitializedData += psh->SizeOfRawData;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_header.filehdr.সংখ্যা_Of_Sections = pe->sec_গুনতি;
    pe_header.opthdr.AddressOfEntryPoint = pe->start_addr;
    pe_header.opthdr.SizeOfHeaders = pe->sizeofheaders;
    pe_header.opthdr.ImageBase = pe->imagebase;
    pe_header.opthdr.Subsystem = pe->subsystem;
    pe_header.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    যদি (s1->pe_স্তূপ_size)
        pe_header.opthdr.Size_Of_স্তূপ_Reserve = s1->pe_স্তূপ_size;
    যদি (PE_DLL == pe->type)
        pe_header.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_header.filehdr.Characteristics |= s1->pe_characteristics;
    যদি (pe->reloc)
        pe_header.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    যদি (pe->coffsym) {
        pe_add_coffsym(pe);
        pe_header.filehdr.Pointer_To_প্ৰতীক_Table = file_offset;
        pe_header.filehdr.সংখ্যা_Of_Symbols
            = pe->coffsym->data_offset / পরিমাণ (সংরচনা syment);
    }

    pe_fwrite(pe, &pe_header, পরিমাণ pe_header);
    বাবে (i = 0; i < pe->sec_গুনতি; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, পরিমাণ(IMAGE_SECTION_HEADER));

    file_offset = pe->sizeofheaders;
    বাবে (i = 0; i < pe->sec_গুনতি; ++i) {
        Section *s;
        si = pe->sec_info[i];
        যদি (!si->data_size)
            অনুৱর্ত;
        বাবে (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_offset);
            pe_fwrite(pe, s->data, s->data_offset);
            যদি (s->prev)
                file_offset += s->prev->sh_addr - s->sh_addr;
        }
        file_offset = si->ish.PointerToRawData + si->ish.SizeOfRawData;
        pe_fpad(pe, file_offset);
    }

    যদি (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->data, pe->coffsym->data_offset);
        pe_fwrite(pe, pe->coffstr->data, pe->coffstr->data_offset);
        file_offset = pe->pos;
    }

    pe->sum += file_offset;
    fseek(pe->op, offsetof(সংরচনা pe_header, opthdr.CheckSum), SEEK_SET);
    pe_fwrite(pe, &pe->sum, পরিমাণ (DWORD));

    fclose (pe->op);
#ifndef _WIN32
    chmod(pe->filename, 0777);
#endif

    যদি (2 == s1->verbose)
        printf("-------------------------------\n");
    যদি (s1->verbose)
        printf("<- %s (%u bytes)\n", pe->filename, (unsigned)file_offset);

    যদি (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    ঘূৰাই 0;
}

/*----------------------------------------------------------------------------*/

স্থির সংরচনা import_প্ৰতীক *pe_add_import(সংরচনা pe_info *pe, পূর্ণাঙ্ক sym_index)
{
    পূর্ণাঙ্ক i;
    পূর্ণাঙ্ক dll_index;
    সংরচনা pe_import_info *p;
    সংরচনা import_প্ৰতীক *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->data + sym_index;
    dll_index = isym->st_size;

    i = dynarray_assoc ((শূন্য**)pe->imp_info, pe->imp_গুনতি, dll_index);
    যদি (-1 != i) {
        p = pe->imp_info[i];
        গচ্ছ found_dll;
    }
    p = tcc_mallocz(পরিমাণ *p);
    p->dll_index = dll_index;
    dynarray_add(&pe->imp_info, &pe->imp_গুনতি, p);

found_dll:
    i = dynarray_assoc ((শূন্য**)p->symbols, p->sym_গুনতি, sym_index);
    যদি (-1 != i)
        ঘূৰাই p->symbols[i];

    s = tcc_mallocz(পরিমাণ *s);
    dynarray_add(&p->symbols, &p->sym_গুনতি, s);
    s->sym_index = sym_index;
    ঘূৰাই s;
}

স্থির শূন্য pe_free_imports(সংরচনা pe_info *pe)
{
    পূর্ণাঙ্ক i;
    বাবে (i = 0; i < pe->imp_গুনতি; ++i) {
        সংরচনা pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_গুনতি);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_গুনতি);
}

/*----------------------------------------------------------------------------*/
স্থির শূন্য pe_build_imports(সংরচনা pe_info *pe)
{
    পূর্ণাঙ্ক thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_base = pe->thunk->sh_addr - pe->imagebase;
    পূর্ণাঙ্ক ndlls = pe->imp_গুনতি;
    TCCState *s1 = pe->s1;

    বাবে (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_গুনতি;

    যদি (0 == sym_cnt)
        ঘূৰাই;

    pe_align_section(pe->thunk, 16);
    pe->imp_size = (ndlls + 1) * পরিমাণ(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_size = (sym_cnt + ndlls) * পরিমাণ(ADDR3264);
    dll_ptr = pe->thunk->data_offset;
    thk_ptr = dll_ptr + pe->imp_size;
    ent_ptr = thk_ptr + pe->iat_size;
    pe->imp_offs = dll_ptr + rva_base;
    pe->iat_offs = thk_ptr + rva_base;
    section_ptr_add(pe->thunk, pe->imp_size + 2*pe->iat_size);

    বাবে (i = 0; i < pe->imp_গুনতি; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        পূর্ণাঙ্ক k, n, dllindex;
        ADDR3264 v;
        সংরচনা pe_import_info *p = pe->imp_info[i];
        ধ্রুৱ ৱর্ণ *name;
        DLLReference *dllref;

        dllindex = p->dll_index;
        যদি (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        অন্যথা
            name = "", dllref = রিক্ত;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->data + dll_ptr);
        hdr->FirstThunk = thk_ptr + rva_base;
        hdr->OriginalFirstThunk = ent_ptr + rva_base;
        hdr->Name = v + rva_base;

        বাবে (k = 0, n = p->sym_গুনতি; k <= n; ++k) {
            যদি (k < n) {
                পূর্ণাঙ্ক iat_index = p->symbols[k]->iat_index;
                পূর্ণাঙ্ক sym_index = p->symbols[k]->sym_index;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->data + sym_index;
                ধ্রুৱ ৱর্ণ *name = (ৱর্ণ*)s1->dynsymtab_section->link->data + imp_sym->st_name;
                পূর্ণাঙ্ক ordinal;

                /* patch symbol (and possibly its underscored alias) */
                কৰা {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->data + iat_index;
                    iat_index = esym->st_মান;
                    esym->st_মান = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_অঙ্ক;
                } যেতিয়ালৈ (iat_index);

                যদি (dllref)
                    v = 0, ordinal = imp_sym->st_মান; /* ordinal from pe_load_def */
                অন্যথা
                    ordinal = 0, v = imp_sym->st_মান; /* address from tcc_add_symbol() */

#ifdef TCC_IS_NATIVE
                যদি (pe->type == PE_RUN) {
                    যদি (dllref) {
                        যদি ( !dllref->handle )
                            dllref->handle = LoadLibraryA(dllref->name);
                        v = (ADDR3264)GetProcAddress(dllref->handle, ordinal?(ৱর্ণ*)0+ordinal:name);
                    }
                    যদি (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } অন্যথা
#endif
                যদি (ordinal) {
                    v = ordinal | (ADDR3264)1 << (পরিমাণ(ADDR3264)*8 - 1);
                } অন্যথা {
                    v = pe->thunk->data_offset + rva_base;
                    section_ptr_add(pe->thunk, পরিমাণ(WORD)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } অন্যথা {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->data+thk_ptr) =
            *(ADDR3264*)(pe->thunk->data+ent_ptr) = v;
            thk_ptr += পরিমাণ (ADDR3264);
            ent_ptr += পরিমাণ (ADDR3264);
        }
        dll_ptr += পরিমাণ(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

সংরচনা pe_sort_sym
{
    পূর্ণাঙ্ক index;
    ধ্রুৱ ৱর্ণ *name;
};

স্থির পূর্ণাঙ্ক sym_cmp(ধ্রুৱ শূন্য *va, ধ্রুৱ শূন্য *vb)
{
    ধ্রুৱ ৱর্ণ *ca = (*(সংরচনা pe_sort_sym**)va)->name;
    ধ্রুৱ ৱর্ণ *cb = (*(সংরচনা pe_sort_sym**)vb)->name;
    ঘূৰাই strcmp(ca, cb);
}

স্থির শূন্য pe_build_exports(সংরচনা pe_info *pe)
{
    ElfW(Sym) *sym;
    পূর্ণাঙ্ক sym_index, sym_end;
    DWORD rva_base, base_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    পূর্ণাঙ্ক sym_গুনতি, ord;
    সংরচনা pe_sort_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    ৱর্ণ buf[260];
    ধ্রুৱ ৱর্ণ *dllname;
    ধ্রুৱ ৱর্ণ *name;

    rva_base = pe->thunk->sh_addr - pe->imagebase;
    sym_গুনতি = 0, sorted = রিক্ত, op = রিক্ত;

    sym_end = symtab_section->data_offset / পরিমাণ(ElfW(Sym));
    বাবে (sym_index = 1; sym_index < sym_end; ++sym_index) {
        sym = (ElfW(Sym)*)symtab_section->data + sym_index;
        name = pe_export_name(s1, sym);
        যদি (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(পরিমাণ *p);
            p->index = sym_index;
            p->name = name;
            dynarray_add(&sorted, &sym_গুনতি, p);
        }
#যদি 0
        যদি (sym->st_other & ST_PE_EXPORT)
            printf("export: %s\n", name);
        যদি (sym->st_other & ST_PE_STDCALL)
            printf("stdcall: %s\n", name);
#endif
    }

    যদি (0 == sym_গুনতি)
        ঘূৰাই;

    qsort (sorted, sym_গুনতি, পরিমাণ *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    base_o = pe->thunk->data_offset;
    func_o = base_o + পরিমাণ(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_গুনতি * পরিমাণ (DWORD);
    ord_o = name_o + sym_গুনতি * পরিমাণ (DWORD);
    str_o = ord_o + sym_গুনতি * পরিমাণ(WORD);

    hdr = section_ptr_add(pe->thunk, str_o - base_o);
    hdr->Characteristics        = 0;
    hdr->Base                   = 1;
    hdr->সংখ্যা_Of_Functions      = sym_গুনতি;
    hdr->সংখ্যা_Of_Names          = sym_গুনতি;
    hdr->AddressOfFunctions     = func_o + rva_base;
    hdr->AddressOfNames         = name_o + rva_base;
    hdr->AddressOfNameOrdinals  = ord_o + rva_base;
    hdr->Name                   = str_o + rva_base;
    put_elf_str(pe->thunk, dllname);

#যদি 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, পরিমাণ buf, pe->filename);
    strcpy(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    যদি (রিক্ত == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } অন্যথা {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        যদি (s1->verbose)
            printf("<- %s (%d symbol%s)\n", buf, sym_গুনতি, &"s"[sym_গুনতি < 2]);
    }
#endif

    বাবে (ord = 0; ord < sym_গুনতি; ++ord)
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
        func_o += পরিমাণ (DWORD);
        name_o += পরিমাণ (DWORD);
        ord_o += পরিমাণ (WORD);
        যদি (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = base_o + rva_base;
    pe->exp_size = pe->thunk->data_offset - base_o;
    dynarray_reset(&sorted, &sym_গুনতি);
    যদি (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
স্থির শূন্য pe_build_reloc (সংরচনা pe_info *pe)
{
    DWORD offset, block_ptr, sh_addr, addr;
    পূর্ণাঙ্ক গুনতি_2, i;
    ElfW_Rel *rel, *rel_end;
    Section *s = রিক্ত, *sr;
    সংরচনা pe_reloc_header *hdr;
    TCCState *s1 = pe->s1;
    পূর্ণাঙ্ক dwarf = 0, n;

    sh_addr = offset = block_ptr = গুনতি_2 = i = 0;
    rel = rel_end = রিক্ত;

    বাবে(;;) {
        যদি (rel < rel_end) {
            পূর্ণাঙ্ক type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_offset + sh_addr;
            ++ rel;
            যদি (type != REL_TYPE_DIRECT)
                অনুৱর্ত;
            যদি (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->data + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                যদি (n >= s1->dwlo && n < s1->dwhi)
                    অনুৱর্ত;
            }
            যদি (গুনতি_2 == 0) { /* new block */
                block_ptr = pe->reloc->data_offset;
                section_ptr_add(pe->reloc, পরিমাণ(সংরচনা pe_reloc_header));
                offset = addr & 0xFFFFFFFF<<12;
            }
            যদি ((addr -= offset)  < (1<<12)) { /* one block spans 4k addresses */
                WORD *wp = section_ptr_add(pe->reloc, পরিমাণ (WORD));
                *wp = addr | PE_IMAGE_REL<<12;
                ++গুনতি_2;
                অনুৱর্ত;
            }
            -- rel;

        } অন্যথা যদি (s) {
            sr = s->reloc;
            যদি (sr) {
                rel = (ElfW_Rel *)sr->data;
                rel_end = (ElfW_Rel *)(sr->data + sr->data_offset);
                sh_addr = s->sh_addr;
                dwarf = s->sh_অঙ্ক >= s1->dwlo && s->sh_অঙ্ক < s1->dwhi;
            }
            s = s->prev;
            অনুৱর্ত;

        } অন্যথা যদি (i < pe->sec_গুনতি) {
            s = pe->sec_info[i]->sec, ++i;
            অনুৱর্ত;

        } অন্যথা যদি (!গুনতি_2)
            ভঙ্গ;

        /* fill the last block and ready for a new one */
        যদি (গুনতি_2 & 1) /* align for DWORDS */
            section_ptr_add(pe->reloc, পরিমাণ(WORD)), ++গুনতি_2;
        hdr = (সংরচনা pe_reloc_header *)(pe->reloc->data + block_ptr);
        hdr -> offset = offset - pe->imagebase;
        hdr -> size = গুনতি_2 * পরিমাণ(WORD) + পরিমাণ(সংরচনা pe_reloc_header);
        গুনতি_2 = 0;
    }
}

/* ------------------------------------------------------------- */
স্থির শূন্য pe_build_tls(সংরচনা pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    পূর্ণাঙ্ক c, n;

    যদি (0 == s) {
        pe->tls_size = পরিমাণ (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_add(pe->thunk, pe->tls_size, 16);
        pe->tls_data = section_add(data_section, PTR_SIZE * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, data_section->sh_অঙ্ক, 0);
        বাবে (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_SIZE*n, REL_TYPE_DIRECT, c);
        /* for generators */
        set_elf_sym(symtab_section, pe->tls_data, PTR_SIZE * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, data_section->sh_অঙ্ক, "__tls_index");
        ঘূৰাই;
    }

    যদি (0 == s1->tls_start)
        s1->tls_start = s->sh_addr;
    d = (শূন্য*)(pe->thunk->data + pe->tls_dir);
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
স্থির পূর্ণাঙ্ক pe_section_class(Section *s)
{
    পূর্ণাঙ্ক type, flags;
    ধ্রুৱ ৱর্ণ *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    যদি (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        ঘূৰাই sec_debug;
    } অন্যথা যদি (flags & SHF_ALLOC) {
        যদি (flags & SHF_TLS)
            ঘূৰাই sec_tdata + (type == SHT_NOBITS);
        যদি (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            যদি (flags & SHF_EXECINSTR)
                ঘূৰাই sec_text;
            যদি (flags & SHF_WRITE)
                ঘূৰাই sec_data;
            যদি (0 == strcmp(name, ".rsrc"))
                ঘূৰাই sec_rsrc;
            যদি (0 == strcmp(name, ".iedat"))
                ঘূৰাই sec_idata;
            যদি (0 == strcmp(name, ".pdata"))
                ঘূৰাই sec_pdata;
            ঘূৰাই sec_rdata;
        } অন্যথা যদি (type == SHT_NOBITS) {
            ঘূৰাই sec_bss;
        }
        ঘূৰাই sec_other;
    } অন্যথা {
        যদি (0 == strcmp(name, ".reloc"))
            ঘূৰাই sec_reloc;
    }
    ঘূৰাই sec_last;
}

স্থির পূর্ণাঙ্ক pe_assign_addresses (সংরচনা pe_info *pe)
{
    পূর্ণাঙ্ক i, k, n, c, nbs;
    ADDR3264 addr;
    পূর্ণাঙ্ক *sec_order, *sec_cls;
    সংরচনা section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    যদি (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_order = tcc_mallocz(2 * পরিমাণ (পূর্ণাঙ্ক) * nbs);
    sec_cls = sec_order + nbs;
    বাবে (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        বাবে (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
        যদি ((s->sh_flags & SHF_TLS) && 0 == pe->tls_size)
            pe_build_tls(pe, রিক্ত);
    }
    si = রিক্ত;
    addr = pe->imagebase + 1;
    বাবে (i = 1; (c = sec_cls[i]) < sec_last; ++i) {
        s = s1->sections[sec_order[i]];

        যদি (PE_MERGE_DATA && c == sec_bss)
            c = sec_data;
        যদি (c == sec_tbss)
            c = sec_tdata;

        যদি (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } অন্যথা {
            si = রিক্ত;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        যদি (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        যদি (s == pe->reloc)
            pe_build_reloc (pe);

        যদি (0 == s->data_offset)
            অনুৱর্ত;

        যদি (si)
            গচ্ছ add_section;

        si = tcc_mallocz(পরিমাণ *si);
        dynarray_add(&pe->sec_info, &pe->sec_গুনতি, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        যদি (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_CODE;
        অন্যথা যদি (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_DATA;
        অন্যথা
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_DATA;
        যদি (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        যদি (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

add_section:
        s->sh_info = pe->sec_গুনতি; /* section number for coff syms */
        addr += s->data_offset;
        si->sh_size = addr - si->sh_addr;
        যদি (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            যেতিয়ালৈ (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = রিক্ত;
            si->data_size = si->sh_size;
        }

        যদি (s->sh_flags & SHF_TLS) {
            strcpy(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#যদি 0
    বাবে (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_order[i]];
        পূর্ণাঙ্ক type = s->sh_type;
        পূর্ণাঙ্ক flags = s->sh_flags;
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
    ঘূৰাই 0;
}

/*----------------------------------------------------------------------------*/
স্থির পূর্ণাঙ্ক pe_check_symbols(সংরচনা pe_info *pe)
{
    পূর্ণাঙ্ক sym_index, sym_end;
    পূর্ণাঙ্ক ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(text_section, 8);

    sym_end = symtab_section->data_offset / পরিমাণ(ElfW(Sym));
    বাবে (sym_index = 1; sym_index < sym_end; ++sym_index) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
        যদি (sym->st_shndx == SHN_UNDEF) {
            ধ্রুৱ ৱর্ণ *name = (ৱর্ণ*)symtab_section->link->data + sym->st_name;
            unsigned type = ELFW(ST_TYPE)(sym->st_info);
            পূর্ণাঙ্ক imp_sym = 0;
            সংরচনা import_প্ৰতীক *is;

            পূর্ণাঙ্ক _imp_, n;
            ৱর্ণ buffer[200];
            ধ্রুৱ ৱর্ণ *s, *p;

            n = _imp_ = 0;
            যদি (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            কৰা {
                s = pe_export_name(s1, sym);
                যদি (n) {
                    /* second try: */
                    যদি (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        যদি (!p || s[0] != '_')
                            ভঙ্গ;
                        strcpy(buffer, s+1)[p-s-1] = 0, s = buffer;
                    } অন্যথা যদি (s[0] != '_') { /* try non-ansi function */
                        buffer[0] = '_', strcpy(buffer + 1, s), s = buffer;
                    } অন্যথা যদি (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } অন্যথা যদি (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } অন্যথা {
                        ভঙ্গ;
                    }
                }
                imp_sym = find_elf_sym(s1->dynsymtab_section, s);
            } যেতিয়ালৈ (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            যদি (0 == imp_sym)
                অনুৱর্ত; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_add_import(pe, imp_sym);

            যদি (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                unsigned offset = is->thk_offset;
                যদি (offset) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } অন্যথা {
                    unsigned ৱর্ণ *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(buffer, "IAT.%s", name);
                    is->iat_index = put_elf_sym(
                        symtab_section, 0, পরিমাণ(DWORD),
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
#নোচেদ্যদি defined(TCC_TARGET_ARM64)
                    p = section_ptr_add(text_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, text_section,
                        offset + 16, R_XXX_THUNKFIX, is->iat_index);
#অন্যথা
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
                sym->st_মান = offset;
                sym->st_shndx = text_section->sh_অঙ্ক;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } অন্যথা { /* STT_OBJECT */
                যদি (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_মান = is->iat_index; /* chain potential alias */
                is->iat_index = sym_index;
            }

        } অন্যথা যদি (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    ঘূৰাই ret;
}

/*----------------------------------------------------------------------------*/
#যদি PE_PRINT_SECTIONS
স্থির শূন্য pe_print_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    পূর্ণাঙ্ক i, n, l, m;
    p = s->data;
    e = s->data + s->data_offset;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    যদি (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    যদি (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (unsigned)s->sh_addr);
    fprintf(f, "\ncontents %08X", (unsigned)l);
    fprintf(f, "\n\n");

    যদি (s->sh_type == SHT_NOBITS)
        ঘূৰাই;

    যদি (0 == l)
        ঘূৰাই;

    যদি (s->sh_type == SHT_SYMTAB)
        m = পরিমাণ(ElfW(Sym));
    অন্যথা যদি (s->sh_type == SHT_RELX)
        m = পরিমাণ(ElfW_Rel);
    অন্যথা
        m = 16;

    fprintf(f, "%-8s", "offset");
    বাবে (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    যদি (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        ধ্রুৱ ৱর্ণ *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            রিক্ত
        };

        ধ্রুৱ ৱর্ণ *fields2[] = {
            "offs",
            "type",
            "symb",
            রিক্ত
        };

        ধ্রুৱ ৱর্ণ **p;

        যদি (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        অন্যথা
            p = fields2, n = 58;

        বাবে (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    বাবে (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    বাবে (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        বাবে (n = 0; n < m; ++n) {
            যদি (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            অন্যথা
                fprintf(f, "   ");
        }

        যদি (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            ধ্রুৱ ৱর্ণ *name = s->link->data + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (unsigned)sym->st_name,
                    (unsigned)sym->st_মান,
                    (unsigned)sym->st_size,
                    (unsigned)ELFW(ST_BIND)(sym->st_info),
                    (unsigned)ELFW(ST_TYPE)(sym->st_info),
                    (unsigned)sym->st_other,
                    (unsigned)sym->st_shndx,
                    name);

        } অন্যথা যদি (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->data + ELFW(R_SYM)(rel->r_info);
            ধ্রুৱ ৱর্ণ *name = s->link->link->data + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (unsigned)rel->r_offset,
                    (unsigned)ELFW(R_TYPE)(rel->r_info),
                    (unsigned)ELFW(R_SYM)(rel->r_info),
                    name);
        } অন্যথা {
            fprintf(f, "   ");
            বাবে (n = 0; n < m; ++n) {
                যদি (n + i < l) {
                    b = p[i + n];
                    যদি (b < 32 || b >= 127)
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

স্থির শূন্য pe_print_sections(TCCState *s1, ধ্রুৱ ৱর্ণ *fname)
{
    Section *s;
    FILE *f;
    পূর্ণাঙ্ক i;
    f = fopen(fname, "w");
    বাবে (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    fclose(f);
}
#endif

/* ------------------------------------------------------------- */

ST_FUNC পূর্ণাঙ্ক pe_putimport(TCCState *s1, পূর্ণাঙ্ক dllindex, ধ্রুৱ ৱর্ণ *name, addr_t মান)
{
    ঘূৰাই set_elf_sym(
        s1->dynsymtab_section,
        মান,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        মান ? SHN_ABS : SHN_UNDEF,
        name
        );
}

স্থির পূর্ণাঙ্ক read_mem(পূর্ণাঙ্ক fd, unsigned offset, শূন্য *buffer, unsigned len)
{
    lseek(fd, offset, SEEK_SET);
    ঘূৰাই len == পঠ(fd, buffer, len);
}

/* ------------------------------------------------------------- */

স্থির পূর্ণাঙ্ক get_dllexports(পূর্ণাঙ্ক fd, ৱর্ণ **pp)
{
    পূর্ণাঙ্ক i, k, l, n, n0, ret;
    ৱর্ণ *p;

    IMAGE_SECTION_HEADER ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_HEADER dh;
    IMAGE_FILE_HEADER ih;
    DWORD sig, ref, addr;
    DWORD *namep = রিক্ত, p0 = 0, p1;

    পূর্ণাঙ্ক pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = রিক্ত;
    ret = 1;
    যদি (!read_mem(fd, 0, &dh, পরিমাণ dh))
        গচ্ছ the_end;
    যদি (!read_mem(fd, dh.e_lfanew, &sig, পরিমাণ sig))
        গচ্ছ the_end;
    যদি (sig != 0x00004550)
        গচ্ছ the_end;
    pef_hdroffset = dh.e_lfanew + পরিমাণ sig;
    যদি (!read_mem(fd, pef_hdroffset, &ih, পরিমাণ ih))
        গচ্ছ the_end;
    opt_hdroffset = pef_hdroffset + পরিমাণ ih;
    যদি (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + পরিমাণ oh;
        যদি (!read_mem(fd, opt_hdroffset, &oh, পরিমাণ oh))
            গচ্ছ the_end;
        যদি (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.সংখ্যা_Of_Rva_And_Sizes)
            গচ্ছ the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } অন্যথা যদি (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + পরিমাণ oh;
        যদি (!read_mem(fd, opt_hdroffset, &oh, পরিমাণ oh))
            গচ্ছ the_end;
        যদি (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.সংখ্যা_Of_Rva_And_Sizes)
            গচ্ছ the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } অন্যথা
        গচ্ছ the_end;

    //printf("addr: %08x\n", addr);
    বাবে (i = 0; i < ih.সংখ্যা_Of_Sections; ++i) {
        যদি (!read_mem(fd, sec_hdroffset + i * পরিমাণ ish, &ish, পরিমাণ ish))
            গচ্ছ the_end;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        যদি (addr >= ish.VirtualAddress && addr < ish.VirtualAddress + ish.SizeOfRawData)
            গচ্ছ found;
    }
    গচ্ছ the_end_0;
found:
    ref = ish.VirtualAddress - ish.PointerToRawData;
    যদি (!read_mem(fd, addr - ref, &ied, পরিমাণ ied))
        গচ্ছ the_end;
    k = ied.সংখ্যা_Of_Names;
    যদি (k) {
        namep = tcc_malloc(l = k * পরিমাণ *namep);
        যদি (!read_mem(fd, ied.AddressOfNames - ref, namep, l))
            গচ্ছ the_end;
        বাবে (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            যদি (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            কৰা {
                যদি (0 == l) {
                    যদি (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    যদি ((l = পঠ(fd, p + n, 1000 - 1)) <= 0)
                        গচ্ছ the_end;
                }
                --l, ++p0;
            } যেতিয়ালৈ (p[n++]);
        }
        p[n] = 0;
    }
the_end_0:
    ret = 0;
the_end:
    tcc_free(namep);
    যদি (ret && p)
        tcc_free(p), p = রিক্ত;
    *pp = p;
    ঘূৰাই ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

স্থির পূর্ণাঙ্ক pe_load_res(TCCState *s1, পূর্ণাঙ্ক fd)
{
    সংরচনা pe_rsrc_header hdr;
    Section *rsrc_section;
    পূর্ণাঙ্ক i, ret = -1, sym_index;
    BYTE *ptr;
    unsigned offs;

    যদি (!read_mem(fd, 0, &hdr, পরিমাণ hdr))
        গচ্ছ quit;

    যদি (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.সংখ্যা_Of_Sections != 1
        || strcmp((ৱর্ণ*)hdr.sectionhdr.Name, ".rsrc") != 0)
        গচ্ছ quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_add(rsrc_section, hdr.sectionhdr.SizeOfRawData);
    offs = hdr.sectionhdr.PointerToRawData;
    যদি (!read_mem(fd, offs, ptr, hdr.sectionhdr.SizeOfRawData))
        গচ্ছ quit;
    offs = hdr.sectionhdr.PointerToRelocations;
    sym_index = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_অঙ্ক, ".rsrc");
    বাবে (i = 0; i < hdr.sectionhdr.সংখ্যা_Of_Relocations; ++i) {
        সংরচনা pe_rsrc_reloc rel;
        যদি (!read_mem(fd, offs, &rel, পরিমাণ rel))
            গচ্ছ quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        যদি (rel.type != RSRC_RELTYPE)
            গচ্ছ quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.offset, R_XXX_RELATIVE, sym_index);
        offs += পরিমাণ rel;
    }
    ret = 0;
quit:
    ঘূৰাই ret;
}

/* ------------------------------------------------------------- */

স্থির ৱর্ণ *trimfront(ৱর্ণ *p)
{
    যেতিয়ালৈ ((unsigned ৱর্ণ)*p <= ' ' && *p && *p != '\n')
	++p;
    ঘূৰাই p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

স্থির ৱর্ণ *get_token(ৱর্ণ **s, ৱর্ণ *f)
{
    ৱর্ণ *p, *e;
    পূর্ণাঙ্ক q;

    p = trimfront(*s);
    q = *p;
    যদি (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    অন্যথা
        q = ' ';
    বাবে (e = p; (unsigned ৱর্ণ)*e >= ' ' && *e != q; ++e)
        ;
    যদি (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    ঘূৰাই p;
}

স্থির পূর্ণাঙ্ক pe_load_def(TCCState *s1, পূর্ণাঙ্ক fd)
{
    পূর্ণাঙ্ক state = 0, ret = -1, dllindex = 0, ord;
    ৱর্ণ dllname[80], *buf, *সাৰি, *p, *x, next;

    buf = tcc_load_text(fd);
    যদি (!buf)
        ঘূৰাই ret;

    বাবে (সাৰি = buf;; ++সাৰি)  {
        p = get_token(&সাৰি, &next);
        যদি (!(*p && *p != ';'))
            গচ্ছ skip;
        ৱিকল্প (state) {
        পক্ষ 0:
            যদি (0 != stricmp(p, "LIBRARY") || next == '\n')
                গচ্ছ quit;
            pstrcpy(dllname, পরিমাণ dllname, get_token(&সাৰি, &next));
            যদি (!*tcc_fileextension(dllname))
                pstrcat(dllname, পরিমাণ dllname, ".dll");
            ++state;
            ভঙ্গ;
        পক্ষ 1:
            যদি (0 != stricmp(p, "EXPORTS"))
                গচ্ছ quit;
            ++state;
            ভঙ্গ;
        পক্ষ 2:
            dllindex = tcc_add_dllref(s1, dllname, 0)->index;
            ++state;
            /* fall through */
        স্ৱভাৱ:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            যদি (next == '@') {
                x = get_token(&সাৰি, &next);
                ord = (পূর্ণাঙ্ক)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            ভঙ্গ;
        }
skip:
        যেতিয়ালৈ ((unsigned ৱর্ণ)next > ' ')
            get_token(&সাৰি, &next);
        যদি (next != '\n')
            ভঙ্গ;
    }
    ret = 0;
quit:
    tcc_free(buf);
    ঘূৰাই ret;
}

/* ------------------------------------------------------------- */

স্থির পূর্ণাঙ্ক pe_load_dll(TCCState *s1, পূর্ণাঙ্ক fd, ধ্রুৱ ৱর্ণ *filename)
{
    ৱর্ণ *p, *q;
    DLLReference *ref = tcc_add_dllref(s1, filename, 0);
    যদি (ref->found)
        ঘূৰাই 0;
    যদি (get_dllexports(fd, &p))
        ঘূৰাই -1;
    যদি (p) {
        বাবে (q = p; *q; q += 1 + strlen(q))
            pe_putimport(s1, ref->index, q, 0);
        tcc_free(p);
    }
    ঘূৰাই 0;
}

ST_FUNC পূর্ণাঙ্ক pe_load_file(সংরচনা TCCState *s1, পূর্ণাঙ্ক fd, ধ্রুৱ ৱর্ণ *filename)
{
    পূর্ণাঙ্ক ret = -1;
    ৱর্ণ buf[10];
    যদি (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_load_def(s1, fd);
    অন্যথা যদি (pe_load_res(s1, fd) == 0)
        ret = 0;
    অন্যথা যদি (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_load_dll(s1, fd, filename);
    ঘূৰাই ret;
}

PUB_FUNC পূর্ণাঙ্ক tcc_get_dllexports(ধ্রুৱ ৱর্ণ *filename, ৱর্ণ **pp)
{
    পূর্ণাঙ্ক ret, fd = open(filename, O_RDONLY | O_দ্বিমিক_2);
    যদি (fd < 0)
        ঘূৰাই -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    ঘূৰাই ret;
}

/* ------------------------------------------------------------- */
#ifdef TCC_TARGET_X86_64
স্থির unsigned pe_add_unwind_info(TCCState *s1)
{
    যদি (রিক্ত == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    যদি (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, text_section->sh_অঙ্ক, ".uw_base");
    যদি (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        স্থির ধ্রুৱ unsigned ৱর্ণ uw_info[] = {
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
        unsigned ৱর্ণ *p;

        section_ptr_add(s, -s->data_offset & 3); /* align */
        s1->uw_offs = s->data_offset;
        p = section_ptr_add(s, পরিমাণ uw_info);
        memcpy(p, uw_info, পরিমাণ uw_info);
    }

    ঘূৰাই s1->uw_offs;
}

ST_FUNC শূন্য pe_add_unwind_data(unsigned start, unsigned end, unsigned স্তূপ)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    unsigned o, n, d;
    সংরচনা /* _RUNTIME_FUNCTION */ {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD UnwindData;
    } *p;

    d = pe_add_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->data_offset;
    p = section_ptr_add(pd, পরিমাণ *p);

    /* record this function */
    p->BeginAddress = start;
    p->EndAddress = end;
    p->UnwindData = d;

    /* put relocations on it */
    বাবে (n = o + পরিমাণ *p; o < n; o += পরিমাণ p->BeginAddress)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#নোচেদ্যদি defined(TCC_TARGET_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
স্থির Section *pe_add_unwind_info(TCCState *s1)
{
    Section *s;

    যদি (রিক্ত == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = find_section(s1, ".xdata");
    s->sh_addralign = 4;
    যদি (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  text_section->sh_অঙ্ক, ".uw_text_base");
    যদি (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_অঙ্ক, ".uw_base");
    ঘূৰাই s;
}

ST_FUNC শূন্য pe_add_unwind_data(unsigned start, unsigned end, unsigned স্তূপ)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    unsigned o, d, code_bytes, func_len;
    unsigned ৱর্ণ *q;
    uint32_t header;
    সংরচনা /* _RUNTIME_FUNCTION */ {
        DWORD BeginAddress;
        DWORD UnwindData;
    } *p;

    পূর্ণাঙ্ক epilog;

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
    যেতিয়ালৈ ((unsigned)(q - (xd->data + d + 4)) < code_bytes)
        *q++ = 0xE3; /* nop padding */

    o = pd->data_offset;
    p = section_ptr_add(pd, পরিমাণ *p);
    p->BeginAddress = start;
    p->UnwindData = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#endif
/* ------------------------------------------------------------- */
#যদি defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
#define PE_STDSYM(n,s) n
#অন্যথা
#define PE_STDSYM(n,s) "_" n s
#endif

স্থির শূন্য pe_add_runtime(TCCState *s1, সংরচনা pe_info *pe)
{
    ধ্রুৱ ৱর্ণ *start_প্ৰতীক;
    পূর্ণাঙ্ক pe_type;

    যদি (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        start_প্ৰতীক = PE_STDSYM("__dllstart","@12");
    } অন্যথা {
        ধ্রুৱ ৱর্ণ *run_প্ৰতীক;
        যদি (find_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            start_প্ৰতীক = "__winstart";
            run_প্ৰতীক = "__runwinmain";
            pe_type = PE_GUI;
        } অন্যথা যদি (find_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            start_প্ৰতীক = "__wwinstart";
            run_প্ৰতীক = "__runwwinmain";
            pe_type = PE_GUI;
        } অন্যথা যদি (find_elf_sym(symtab_section, "wmain")) {
            start_প্ৰতীক = "__wstart";
            run_প্ৰতীক = "__runwmain";
            pe_type = PE_EXE;
        } অন্যথা {
            start_প্ৰতীক =  "__start";
            run_প্ৰতীক = "__runmain";
            pe_type = PE_EXE;
            যদি (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        যদি (TCC_OUTPUT_MEMORY == s1->output_type && !s1->nostdlib)
            start_প্ৰতীক = run_প্ৰতীক;
    }
    যদি (s1->elf_entryname) {
        pe->start_প্ৰতীক = start_প্ৰতীক = s1->elf_entryname;
    } অন্যথা {
        pe->start_প্ৰতীক = start_প্ৰতীক + 1;
        যদি (!s1->leading_underscore || strchr(start_প্ৰতীক, '@'))
            ++start_প্ৰতীক;
    }

#ifdef CONFIG_TCC_BACKTRACE
    যদি (s1->do_backtrace) {
#ifdef CONFIG_TCC_BCHECK
        যদি (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    যদি (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    অন্যথা
                tcc_add_support(s1, "bcheck.o");
	}
#endif
        যদি (s1->output_type == TCC_OUTPUT_EXE)
            tcc_add_support(s1, "bt-exe.o");
        যদি (s1->output_type == TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-dll.o");
        যদি (s1->output_type != TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-log.o");
        tcc_add_btstub(s1);
    }
#endif

    /* grab the startup code from libtcc1.a */
#ifdef TCC_IS_NATIVE
    যদি (TCC_OUTPUT_MEMORY != s1->output_type || s1->run_main)
#endif
    set_global_sym(s1, start_প্ৰতীক, রিক্ত, 0);

    যদি (0 == s1->nostdlib) {
        স্থির ধ্রুৱ ৱর্ণ * ধ্রুৱ libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", রিক্ত
        };
        ধ্রুৱ ৱর্ণ * ধ্রুৱ *pp, *p;
        যদি (TCC_LIBTCC1[0])
            tcc_add_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        বাবে (pp = libs; 0 != (p = *pp); ++pp) {
            যদি (*p)
                tcc_add_library(s1, p);
            অন্যথা যদি (PE_DLL != pe_type && PE_GUI != pe_type)
                ভঙ্গ;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    যদি (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    যদি (TCC_OUTPUT_MEMORY == s1->output_type)
        pe_type = PE_RUN;
    pe->type = pe_type;
}

ST_FUNC পূর্ণাঙ্ক pe_setsubsy(TCCState *s1, ধ্রুৱ ৱর্ণ *arg)
{
    স্থির ধ্রুৱ সংরচনা subsy { ধ্রুৱ ৱর্ণ* p; পূর্ণাঙ্ক v; } x[] = {
#যদি defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#নোচেদ্যদি defined(TCC_TARGET_ARM)
        { "wince", 9 },
#endif
        { 0, -1 }};
    ধ্রুৱ সংরচনা subsy *y;
    বাবে (y = x;; ++y) {
        যদি (!y->p)
            ঘূৰাই -1;
        যদি (0 == strcmp(y->p, arg)) {
            s1->pe_subsystem = y->v;
            ঘূৰাই 0;
        }
    }
}

স্থির শূন্য pe_set_options(TCCState * s1, সংরচনা pe_info *pe)
{
    যদি (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_BASE_DLL;
    } অন্যথা {
        pe->imagebase = IMAGE_BASE_EXE;
    }

#যদি defined(TCC_TARGET_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#অন্যথা
    যদি (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    অন্যথা
        pe->subsystem = 3;
#endif
    /* Allow override via -Wl,-subsystem=... option */
    যদি (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    যদি (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } অন্যথা {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    যদি (s1->section_align != 0)
        pe->section_align = s1->section_align;
    যদি (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    যদি ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    যদি (s1->has_text_addr)
        pe->imagebase = s1->text_addr;
}

ST_FUNC পূর্ণাঙ্ক pe_output_file(TCCState *s1, ধ্রুৱ ৱর্ণ *filename)
{
    সংরচনা pe_info pe;

    memset(&pe, 0, পরিমাণ pe);
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
    যদি (s1->nb_errors)
        গচ্ছ done;
    যদি (filename) {
        pe_assign_addresses(&pe);
        relocate_syms(s1, s1->symtab, 0);
        যদি (s1->nb_errors)
            গচ্ছ done;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.start_addr = (DWORD)
            (get_sym_addr(s1, pe.start_প্ৰতীক, 1, 1) - pe.imagebase);
        যদি (s1->nb_errors)
            গচ্ছ done;
        pe_write(&pe);
    } অন্যথা {
        /* -run */
#ifdef TCC_IS_NATIVE
        pe.thunk = data_section;
        pe_build_imports(&pe);
        s1->run_main = pe.start_প্ৰতীক;
#যদি defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        s1->uw_pdata = find_section(s1, ".pdata");
#endif
#endif
    }
done:
    dynarray_reset(&pe.sec_info, &pe.sec_গুনতি);
    pe_free_imports(&pe);
#যদি PE_PRINT_SECTIONS
    যদি (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#endif
    ঘূৰাই s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
