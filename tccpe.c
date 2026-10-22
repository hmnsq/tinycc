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

#অন্তর্ভাব "tcc.h"

#define PE_MERGE_তথ্য 1
#define PE_PRINT_SECTIONS 0

#ifndef _WIN32
#define stricmp strcasecmp
#define strnicmp strncasecmp
#অন্তর্ভাব <sys/stat.h> /* chmod() */
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

#নতুবা_যদি defined TCC_TARGET_ARM
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

#নতুবা_যদি defined TCC_TARGET_ARM64
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

#নতুবা_যদি defined TCC_TARGET_I386
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

#যদি PTR_আকার == 8
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

প্রকারলেখ unsigned অক্ষর BYTE;
প্রকারলেখ unsigned short WORD;
প্রকারলেখ unsigned পূর্ণসংখ্যা DWORD;
প্রকারলেখ unsigned long long ULONGLONG;
#pragma pack(ঠেলো, 1)

প্রকারলেখ কাঠামো _IMAGE_DOS_HEADER {  /* DOS .EXE header */
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

প্রকারলেখ কাঠামো _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    সংখ্যা_Of_Sections;
    DWORD   TimeDateStamp;
    DWORD   Pointer_To_প্রতীক_Table;
    DWORD   সংখ্যা_Of_Symbols;
    WORD    আকার_Of_Optional_Header;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;


#define IMAGE_SIZEOF_FILE_HEADER 20

প্রকারলেখ কাঠামো IMAGE_তথ্য_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   আকার_4;
} IMAGE_তথ্য_DIRECTORY_2, *PIMAGE_তথ্য_DIRECTORY;


প্রকারলেখ কাঠামো _IMAGE_OPTIONAL_HEADER {
    /* Standard fields. */
    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   আকার_Of_Code;
    DWORD   আকার_Of_Initialized_তথ্য;
    DWORD   আকার_Of_Uninitialized_তথ্য;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
#যদি PTR_আকার == 4
    DWORD   Base_Of_তথ্য;
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
    DWORD   আকার_Of_Image;
    DWORD   আকার_Of_Headers;
    DWORD   Check_যোগ;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    ADDR3264 আকার_Of_স্তূপ_Reserve;
    ADDR3264 আকার_Of_স্তূপ_Commit;
    ADDR3264 আকার_Of_Heap_Reserve;
    ADDR3264 আকার_Of_Heap_Commit;
    DWORD   LoaderFlags;
    DWORD   সংখ্যা_Of_Rva_And_Sizes;
    IMAGE_তথ্য_DIRECTORY_2 তথ্য_Directory[16];
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

প্রকারলেখ কাঠামো _IMAGE_SECTION_HEADER {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    সংঘ {
            DWORD   PhysicalAddress;
            DWORD   Virtual_আকার;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   আকার_Of_Raw_তথ্য;
    DWORD   Pointer_To_Raw_তথ্য;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    সংখ্যা_Of_Relocations;
    WORD    সংখ্যা_Of_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#define IMAGE_SIZEOF_SECTION_HEADER     40

প্রকারলেখ কাঠামো _IMAGE_EXPORT_DIRECTORY {
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

প্রকারলেখ কাঠামো _IMAGE_TLS_DIRECTORY {
    ADDR3264 Start_Address_Of_Raw_তথ্য;
    ADDR3264 End_Address_Of_Raw_তথ্য;
    ADDR3264 Address_Of_সূচক;
    ADDR3264 AddressOfCallBacks;
    DWORD আকার_Of_Zero_Fill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

প্রকারলেখ কাঠামো _IMAGE_IMPORT_DESCRIPTOR {
    সংঘ {
        DWORD Characteristics;
        DWORD OriginalFirstThunk;
    };
    DWORD TimeDateStamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;

প্রকারলেখ কাঠামো _IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   আকার_Of_Block;
//  WORD    TypeOffset[1];
} IMAGE_BASE_RELOCATION;

#define IMAGE_SIZEOF_BASE_RELOCATION     8

#define IMAGE_REL_BASED_ABSOLUTE         0
#define IMAGE_REL_BASED_উপরের             1
#define IMAGE_REL_BASED_নিচের              2
#define IMAGE_REL_BASED_HIGHLOW          3
#define IMAGE_REL_BASED_HIGHADJ          4
#define IMAGE_REL_BASED_MIPS_JMPADDR     5
#define IMAGE_REL_BASED_SECTION          6
#define IMAGE_REL_BASED_REL32            7
#define IMAGE_REL_BASED_DIR64           10

#define IMAGE_SCN_CNT_CODE                  0x00000020
#define IMAGE_SCN_CNT_INITIALIZED_তথ্য      0x00000040
#define IMAGE_SCN_CNT_UNINITIALIZED_তথ্য    0x00000080
#define IMAGE_SCN_MEM_DISCARDABLE           0x02000000
#define IMAGE_SCN_MEM_SHARED                0x10000000
#define IMAGE_SCN_MEM_EXECUTE               0x20000000
#define IMAGE_SCN_MEM_READ                  0x40000000
#define IMAGE_SCN_MEM_WRITE                 0x80000000

#define IMAGE_DLLCHARACTERISTICS_উপরের_ENTROPY_VA 0x0020
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#define IMAGE_FILE_RELOCS_STRIPPED 0x0001

#pragma pack(বের_করো)

/* ----------------------------------------------------------- */
#endif /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#ifndef IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#endif

#pragma pack(ঠেলো, 1)
কাঠামো pe_header
{
    IMAGE_DOS_HEADER doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_HEADER filehdr;
#যদি PTR_আকার == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#অন্যথা
#ifdef _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#অন্যথা
    IMAGE_OPTIONAL_HEADER opthdr;
#endif
#endif
};

কাঠামো pe_reloc_header {
    DWORD offset;
    DWORD আকার_2;
};

কাঠামো pe_rsrc_header {
    কাঠামো _IMAGE_FILE_HEADER filehdr;
    কাঠামো _IMAGE_SECTION_HEADER sectionhdr;
};

কাঠামো pe_rsrc_reloc {
    DWORD offset;
    DWORD আকার_2;
    WORD type;
};
#pragma pack(বের_করো)

/* ------------------------------------------------------------- */
/* internal temporary structures */

গণনা {
    sec_text = 0,
    sec_rdata ,
    sec_তথ্য ,
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
স্থির ধ্রুবক DWORD pe_sec_flags[] = {
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

কাঠামো section_info {
    পূর্ণসংখ্যা cls;
    অক্ষর name[32];
    ADDR3264 sh_addr;
    DWORD sh_আকার;
    DWORD pe_flags;
    Section *sec;
    DWORD তথ্য_আকার;
    IMAGE_SECTION_HEADER ish;
};

কাঠামো import_প্রতীক {
    পূর্ণসংখ্যা sym_সূচক;
    পূর্ণসংখ্যা iat_সূচক;
    পূর্ণসংখ্যা thk_offset;
};

কাঠামো pe_import_info {
    পূর্ণসংখ্যা dll_সূচক;
    পূর্ণসংখ্যা sym_গুনতি;
    কাঠামো import_প্রতীক **symbols;
};

কাঠামো pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    ধ্রুবক অক্ষর *filename;
    পূর্ণসংখ্যা type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    ধ্রুবক অক্ষর *start_প্রতীক;
    DWORD start_addr;
    DWORD imp_offs;
    DWORD imp_আকার;
    DWORD iat_offs;
    DWORD iat_আকার;
    DWORD exp_offs;
    DWORD exp_আকার;
    DWORD tls_dir;
    DWORD tls_তথ্য;
    DWORD tls_আকার;
    পূর্ণসংখ্যা subsystem;
    DWORD section_align;
    DWORD file_align;
    কাঠামো section_info **sec_info;
    পূর্ণসংখ্যা sec_গুনতি;
    কাঠামো pe_import_info **imp_info;
    পূর্ণসংখ্যা imp_গুনতি;
    /* output */
    FILE *op;
    DWORD যোগ;
    unsigned pos;
};

#define PE_NUL 0
#define PE_DLL 1
#define PE_GUI 2
#define PE_EXE 3
#define PE_RUN 4

/* --------------------------------------------*/

স্থির ধ্রুবক অক্ষর *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    ধ্রুবক অক্ষর *name = (অক্ষর*)symtab_section->link->তথ্য + sym->st_name;
    যদি (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        ফেরত name + 1;
    ফেরত name;
}


স্থির পূর্ণসংখ্যা dynarray_assoc(শূন্য **pp, পূর্ণসংখ্যা n, পূর্ণসংখ্যা চাবি)
{
    পূর্ণসংখ্যা i;
    জন্য (i = 0; i < n; ++i, ++pp)
    যদি (চাবি == **(পূর্ণসংখ্যা **) pp)
        ফেরত i;
    ফেরত -1;
}

স্থির DWORD umin(DWORD a, DWORD b)
{
    ফেরত a < b ? a : b;
}

স্থির DWORD umax(DWORD a, DWORD b)
{
    ফেরত a < b ? b : a;
}

স্থির DWORD pe_file_align(কাঠামো pe_info *pe, DWORD n)
{
    ফেরত (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

স্থির ADDR3264 pe_virtual_align(কাঠামো pe_info *pe, ADDR3264 n)
{
    ফেরত (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

স্থির শূন্য pe_align_section(Section *s, পূর্ণসংখ্যা a)
{
    পূর্ণসংখ্যা i = s->তথ্য_offset & (a-1);
    যদি (i)
        section_ptr_add(s, a - i);
}

স্থির শূন্য pe_set_datadir(কাঠামো pe_header *hdr, পূর্ণসংখ্যা dir, DWORD addr, DWORD আকার_2)
{
    hdr->opthdr.তথ্য_Directory[dir].VirtualAddress = addr;
    hdr->opthdr.তথ্য_Directory[dir].আকার_4 = আকার_2;
}

স্থির পূর্ণসংখ্যা pe_fwrite(কাঠামো pe_info *pe, ধ্রুবক শূন্য *তথ্য, পূর্ণসংখ্যা len)
{
    ধ্রুবক WORD *p = তথ্য;
    DWORD যোগ;
    পূর্ণসংখ্যা ret, i;
    pe->pos += (ret = fwrite(তথ্য, 1, len, pe->op));
    যোগ = pe->যোগ;
    জন্য (i = len; i > 0; i -= 2) {
        যোগ += (i >= 2) ? *p++ : *(BYTE*)p;
        যোগ = (যোগ + (যোগ >> 16)) & 0xFFFF;
    }
    pe->যোগ = যোগ;
    ফেরত len == ret ? 0 : -1;
}

স্থির শূন্য pe_fpad(কাঠামো pe_info *pe, DWORD new_pos)
{
    অক্ষর buf[256];
    পূর্ণসংখ্যা n, diff = new_pos - pe->pos;
    memset(buf, 0, আকার buf);
    যখন (diff > 0) {
        diff -= n = umin(diff, আকার buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#pragma pack(ঠেলো, 1)
কাঠামো syment
{
    সংঘ {
        অক্ষর        n_name[8];     /* old COFF version */
        কাঠামো {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_offset;      /* offset into string table */
        };
    };
    int32_t         n_মান;        /* value of symbol */
    short           n_scnum;        /* section number */
    unsigned short  n_type;         /* type and derived type */
    অক্ষর            n_sclass;       /* storage class */
    অক্ষর            n_numaux;       /* number of aux. entries */
};
#pragma pack(বের_করো)

#define SHF_PRIVATE 0x80000000

স্থির শূন্য pe_add_coffsym(কাঠামো pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    কাঠামো syment *se;
    পূর্ণসংখ্যা n;

    যদি (ফাঁকা == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_PRIVATE);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_PRIVATE);
        section_ptr_add(pe->coffstr, 4); /* coff string table size */
        ফেরত;
    }

#যদি 0
    se = section_ptr_add(pe->coffsym, আকার *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_add(pe->coffsym, আকার *se);
    strcpy((অক্ষর*)se, "no-file");
#endif

#যদি 1
    esym = (ElfSym*)s1->symtab->তথ্য;
    জন্য (n = s1->symtab->তথ্য_offset / আকার *esym; ++esym, --n;) {
        পূর্ণসংখ্যা sym_bind = ELFW(ST_BIND)(esym->st_info);
        যদি (sym_bind == STB_GLOBAL) {
            অক্ষর *name = esym->st_name + (অক্ষর*)s1->symtab->link->তথ্য;
            পূর্ণসংখ্যা nl = strlen(name);
            addr_t মান = esym->st_মান;
            পূর্ণসংখ্যা shnum = esym->st_shndx;
            যদি (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                মান = মান - s->sh_addr;
            }
            se = section_ptr_add(pe->coffsym, আকার *se);
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
    write32le(pe->coffstr->তথ্য, pe->coffstr->তথ্য_offset); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
স্থির শূন্য pe_create_pdb(TCCState *s1, ধ্রুবক অক্ষর *exename)
{
    অক্ষর buf[300]; পূর্ণসংখ্যা r;
    snprintf(buf, আকার buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    strcpy(tcc_fileextension(strcpy(buf, exename)), ".pdb");
    যদি (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } অন্যথা যদি (s1->verbose) {
        printf("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
স্থির পূর্ণসংখ্যা pe_write(কাঠামো pe_info *pe)
{
    স্থির ধ্রুবক কাঠামো pe_header pe_template = {
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
    0x00E0 + (PTR_আকার-4)*4, /*WORD    SizeOfOptionalHeader; */
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
#যদি PTR_আকার == 4
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

    কাঠামো pe_header pe_header = pe_template;

    পূর্ণসংখ্যা i;
    DWORD file_offset;
    কাঠামো section_info *si;
    IMAGE_SECTION_HEADER *psh;
    TCCState *s1 = pe->s1;

    যদি (s1->do_debug)
        pe_add_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    যদি (ফাঁকা == pe->op)
        ফেরত tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        আকার (কাঠামো pe_header)
        + pe->sec_গুনতি * আকার (IMAGE_SECTION_HEADER)
        );

    file_offset = pe->sizeofheaders;

    যদি (2 == s1->verbose)
        printf("-------------------------------"
               "\n  virt   file   size  section" "\n");
    জন্য (i = 0; i < pe->sec_গুনতি; ++i) {
        DWORD addr, আকার_2;
        ধ্রুবক অক্ষর *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        আকার_2 = si->sh_আকার;
        psh = &si->ish;

        যদি (2 == s1->verbose)
            printf("%6x %6x %6x  %s\n",
                (unsigned)addr, (unsigned)file_offset, (unsigned)আকার_2, sh_name);

        নির্বাচন (si->cls) {
            ক্ষেত্র sec_text:
                যদি (!pe_header.opthdr.BaseOfCode)
                    pe_header.opthdr.BaseOfCode = addr;
                বিরতি;

            ক্ষেত্র sec_তথ্য:
#যদি PTR_আকার == 4
                যদি (!pe_header.opthdr.Base_Of_তথ্য)
                    pe_header.opthdr.Base_Of_তথ্য = addr;
#endif
                বিরতি;

            ক্ষেত্র sec_bss:
                বিরতি;

            ক্ষেত্র sec_reloc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_BASERELOC, addr, আকার_2);
                বিরতি;

            ক্ষেত্র sec_rsrc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_RESOURCE, addr, আকার_2);
                বিরতি;

            ক্ষেত্র sec_pdata:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXCEPTION, addr, আকার_2);
                বিরতি;
        }

        যদি (pe->imp_আকার) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IMPORT,
                pe->imp_offs, pe->imp_আকার);
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IAT,
                pe->iat_offs, pe->iat_আকার);
        }
        যদি (pe->exp_আকার) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXPORT,
                pe->exp_offs, pe->exp_আকার);
        }
        যদি (pe->tls_আকার) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_আকার);
        }

        memcpy(psh->Name, sh_name, umin(strlen(sh_name), আকার psh->Name));
        যদি (pe->coffstr && strlen(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((অক্ষর*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->VirtualAddress = addr;
        psh->Misc.Virtual_আকার = আকার_2;
        pe_header.opthdr.আকার_Of_Image =
            umax(pe_virtual_align(pe, আকার_2 + addr), pe_header.opthdr.আকার_Of_Image);

        যদি (si->তথ্য_আকার) {
            psh->Pointer_To_Raw_তথ্য = file_offset;
            file_offset = pe_file_align(pe, file_offset + si->তথ্য_আকার);
            psh->আকার_Of_Raw_তথ্য = file_offset - psh->Pointer_To_Raw_তথ্য;
            যদি (si->cls == sec_text)
                pe_header.opthdr.আকার_Of_Code += psh->আকার_Of_Raw_তথ্য;
            অন্যথা
                pe_header.opthdr.আকার_Of_Initialized_তথ্য += psh->আকার_Of_Raw_তথ্য;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_header.filehdr.সংখ্যা_Of_Sections = pe->sec_গুনতি;
    pe_header.opthdr.AddressOfEntryPoint = pe->start_addr;
    pe_header.opthdr.আকার_Of_Headers = pe->sizeofheaders;
    pe_header.opthdr.ImageBase = pe->imagebase;
    pe_header.opthdr.Subsystem = pe->subsystem;
    pe_header.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    যদি (s1->pe_স্তূপ_আকার)
        pe_header.opthdr.আকার_Of_স্তূপ_Reserve = s1->pe_স্তূপ_আকার;
    যদি (PE_DLL == pe->type)
        pe_header.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_header.filehdr.Characteristics |= s1->pe_characteristics;
    যদি (pe->reloc)
        pe_header.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    যদি (pe->coffsym) {
        pe_add_coffsym(pe);
        pe_header.filehdr.Pointer_To_প্রতীক_Table = file_offset;
        pe_header.filehdr.সংখ্যা_Of_Symbols
            = pe->coffsym->তথ্য_offset / আকার (কাঠামো syment);
    }

    pe_fwrite(pe, &pe_header, আকার pe_header);
    জন্য (i = 0; i < pe->sec_গুনতি; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, আকার(IMAGE_SECTION_HEADER));

    file_offset = pe->sizeofheaders;
    জন্য (i = 0; i < pe->sec_গুনতি; ++i) {
        Section *s;
        si = pe->sec_info[i];
        যদি (!si->তথ্য_আকার)
            চালু;
        জন্য (s = si->sec; s; s = s->পূর্ব) {
            pe_fpad(pe, file_offset);
            pe_fwrite(pe, s->তথ্য, s->তথ্য_offset);
            যদি (s->পূর্ব)
                file_offset += s->পূর্ব->sh_addr - s->sh_addr;
        }
        file_offset = si->ish.Pointer_To_Raw_তথ্য + si->ish.আকার_Of_Raw_তথ্য;
        pe_fpad(pe, file_offset);
    }

    যদি (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->তথ্য, pe->coffsym->তথ্য_offset);
        pe_fwrite(pe, pe->coffstr->তথ্য, pe->coffstr->তথ্য_offset);
        file_offset = pe->pos;
    }

    pe->যোগ += file_offset;
    fseek(pe->op, offsetof(কাঠামো pe_header, opthdr.Check_যোগ), SEEK_SET);
    pe_fwrite(pe, &pe->যোগ, আকার (DWORD));

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
    ফেরত 0;
}

/*----------------------------------------------------------------------------*/

স্থির কাঠামো import_প্রতীক *pe_add_import(কাঠামো pe_info *pe, পূর্ণসংখ্যা sym_সূচক)
{
    পূর্ণসংখ্যা i;
    পূর্ণসংখ্যা dll_সূচক;
    কাঠামো pe_import_info *p;
    কাঠামো import_প্রতীক *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->তথ্য + sym_সূচক;
    dll_সূচক = isym->st_আকার;

    i = dynarray_assoc ((শূন্য**)pe->imp_info, pe->imp_গুনতি, dll_সূচক);
    যদি (-1 != i) {
        p = pe->imp_info[i];
        যাও found_dll;
    }
    p = tcc_mallocz(আকার *p);
    p->dll_সূচক = dll_সূচক;
    dynarray_add(&pe->imp_info, &pe->imp_গুনতি, p);

found_dll:
    i = dynarray_assoc ((শূন্য**)p->symbols, p->sym_গুনতি, sym_সূচক);
    যদি (-1 != i)
        ফেরত p->symbols[i];

    s = tcc_mallocz(আকার *s);
    dynarray_add(&p->symbols, &p->sym_গুনতি, s);
    s->sym_সূচক = sym_সূচক;
    ফেরত s;
}

স্থির শূন্য pe_free_imports(কাঠামো pe_info *pe)
{
    পূর্ণসংখ্যা i;
    জন্য (i = 0; i < pe->imp_গুনতি; ++i) {
        কাঠামো pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_গুনতি);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_গুনতি);
}

/*----------------------------------------------------------------------------*/
স্থির শূন্য pe_build_imports(কাঠামো pe_info *pe)
{
    পূর্ণসংখ্যা thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_base = pe->thunk->sh_addr - pe->imagebase;
    পূর্ণসংখ্যা ndlls = pe->imp_গুনতি;
    TCCState *s1 = pe->s1;

    জন্য (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_গুনতি;

    যদি (0 == sym_cnt)
        ফেরত;

    pe_align_section(pe->thunk, 16);
    pe->imp_আকার = (ndlls + 1) * আকার(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_আকার = (sym_cnt + ndlls) * আকার(ADDR3264);
    dll_ptr = pe->thunk->তথ্য_offset;
    thk_ptr = dll_ptr + pe->imp_আকার;
    ent_ptr = thk_ptr + pe->iat_আকার;
    pe->imp_offs = dll_ptr + rva_base;
    pe->iat_offs = thk_ptr + rva_base;
    section_ptr_add(pe->thunk, pe->imp_আকার + 2*pe->iat_আকার);

    জন্য (i = 0; i < pe->imp_গুনতি; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        পূর্ণসংখ্যা k, n, dllindex;
        ADDR3264 v;
        কাঠামো pe_import_info *p = pe->imp_info[i];
        ধ্রুবক অক্ষর *name;
        DLLReference *dllref;

        dllindex = p->dll_সূচক;
        যদি (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        অন্যথা
            name = "", dllref = ফাঁকা;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->তথ্য + dll_ptr);
        hdr->FirstThunk = thk_ptr + rva_base;
        hdr->OriginalFirstThunk = ent_ptr + rva_base;
        hdr->Name = v + rva_base;

        জন্য (k = 0, n = p->sym_গুনতি; k <= n; ++k) {
            যদি (k < n) {
                পূর্ণসংখ্যা iat_সূচক = p->symbols[k]->iat_সূচক;
                পূর্ণসংখ্যা sym_সূচক = p->symbols[k]->sym_সূচক;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->তথ্য + sym_সূচক;
                ধ্রুবক অক্ষর *name = (অক্ষর*)s1->dynsymtab_section->link->তথ্য + imp_sym->st_name;
                পূর্ণসংখ্যা ordinal;

                /* patch symbol (and possibly its underscored alias) */
                করো {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->তথ্য + iat_সূচক;
                    iat_সূচক = esym->st_মান;
                    esym->st_মান = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_অঙ্ক;
                } যখন (iat_সূচক);

                যদি (dllref)
                    v = 0, ordinal = imp_sym->st_মান; /* ordinal from pe_load_def */
                অন্যথা
                    ordinal = 0, v = imp_sym->st_মান; /* address from tcc_add_symbol() */

#ifdef TCC_IS_NATIVE
                যদি (pe->type == PE_RUN) {
                    যদি (dllref) {
                        যদি ( !dllref->handle )
                            dllref->handle = LoadLibraryA(dllref->name);
                        v = (ADDR3264)GetProcAddress(dllref->handle, ordinal?(অক্ষর*)0+ordinal:name);
                    }
                    যদি (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } অন্যথা
#endif
                যদি (ordinal) {
                    v = ordinal | (ADDR3264)1 << (আকার(ADDR3264)*8 - 1);
                } অন্যথা {
                    v = pe->thunk->তথ্য_offset + rva_base;
                    section_ptr_add(pe->thunk, আকার(WORD)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } অন্যথা {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->তথ্য+thk_ptr) =
            *(ADDR3264*)(pe->thunk->তথ্য+ent_ptr) = v;
            thk_ptr += আকার (ADDR3264);
            ent_ptr += আকার (ADDR3264);
        }
        dll_ptr += আকার(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

কাঠামো pe_sort_sym
{
    পূর্ণসংখ্যা সূচক;
    ধ্রুবক অক্ষর *name;
};

স্থির পূর্ণসংখ্যা sym_cmp(ধ্রুবক শূন্য *va, ধ্রুবক শূন্য *vb)
{
    ধ্রুবক অক্ষর *ca = (*(কাঠামো pe_sort_sym**)va)->name;
    ধ্রুবক অক্ষর *cb = (*(কাঠামো pe_sort_sym**)vb)->name;
    ফেরত strcmp(ca, cb);
}

স্থির শূন্য pe_build_exports(কাঠামো pe_info *pe)
{
    ElfW(Sym) *sym;
    পূর্ণসংখ্যা sym_সূচক, sym_end;
    DWORD rva_base, base_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    পূর্ণসংখ্যা sym_গুনতি, ord;
    কাঠামো pe_sort_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    অক্ষর buf[260];
    ধ্রুবক অক্ষর *dllname;
    ধ্রুবক অক্ষর *name;

    rva_base = pe->thunk->sh_addr - pe->imagebase;
    sym_গুনতি = 0, sorted = ফাঁকা, op = ফাঁকা;

    sym_end = symtab_section->তথ্য_offset / আকার(ElfW(Sym));
    জন্য (sym_সূচক = 1; sym_সূচক < sym_end; ++sym_সূচক) {
        sym = (ElfW(Sym)*)symtab_section->তথ্য + sym_সূচক;
        name = pe_export_name(s1, sym);
        যদি (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(আকার *p);
            p->সূচক = sym_সূচক;
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
        ফেরত;

    qsort (sorted, sym_গুনতি, আকার *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    base_o = pe->thunk->তথ্য_offset;
    func_o = base_o + আকার(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_গুনতি * আকার (DWORD);
    ord_o = name_o + sym_গুনতি * আকার (DWORD);
    str_o = ord_o + sym_গুনতি * আকার(WORD);

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
    pstrcpy(buf, আকার buf, pe->filename);
    strcpy(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    যদি (ফাঁকা == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } অন্যথা {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        যদি (s1->verbose)
            printf("<- %s (%d symbol%s)\n", buf, sym_গুনতি, &"s"[sym_গুনতি < 2]);
    }
#endif

    জন্য (ord = 0; ord < sym_গুনতি; ++ord)
    {
        p = sorted[ord], sym_সূচক = p->সূচক, name = p->name;
        /* insert actual address later in relocate_sections() */
        put_elf_reloc(symtab_section, pe->thunk,
            func_o, R_XXX_RELATIVE, sym_সূচক);
        *(DWORD*)(pe->thunk->তথ্য + name_o)
            = pe->thunk->তথ্য_offset + rva_base;
        *(WORD*)(pe->thunk->তথ্য + ord_o)
            = ord;
        put_elf_str(pe->thunk, name);
        func_o += আকার (DWORD);
        name_o += আকার (DWORD);
        ord_o += আকার (WORD);
        যদি (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = base_o + rva_base;
    pe->exp_আকার = pe->thunk->তথ্য_offset - base_o;
    dynarray_reset(&sorted, &sym_গুনতি);
    যদি (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
স্থির শূন্য pe_build_reloc (কাঠামো pe_info *pe)
{
    DWORD offset, block_ptr, sh_addr, addr;
    পূর্ণসংখ্যা গুনতি_2, i;
    ElfW_Rel *rel, *rel_end;
    Section *s = ফাঁকা, *sr;
    কাঠামো pe_reloc_header *hdr;
    TCCState *s1 = pe->s1;
    পূর্ণসংখ্যা dwarf = 0, n;

    sh_addr = offset = block_ptr = গুনতি_2 = i = 0;
    rel = rel_end = ফাঁকা;

    জন্য(;;) {
        যদি (rel < rel_end) {
            পূর্ণসংখ্যা type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_offset + sh_addr;
            ++ rel;
            যদি (type != REL_TYPE_DIRECT)
                চালু;
            যদি (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->তথ্য + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                যদি (n >= s1->dwlo && n < s1->dwhi)
                    চালু;
            }
            যদি (গুনতি_2 == 0) { /* new block */
                block_ptr = pe->reloc->তথ্য_offset;
                section_ptr_add(pe->reloc, আকার(কাঠামো pe_reloc_header));
                offset = addr & 0xFFFFFFFF<<12;
            }
            যদি ((addr -= offset)  < (1<<12)) { /* one block spans 4k addresses */
                WORD *wp = section_ptr_add(pe->reloc, আকার (WORD));
                *wp = addr | PE_IMAGE_REL<<12;
                ++গুনতি_2;
                চালু;
            }
            -- rel;

        } অন্যথা যদি (s) {
            sr = s->reloc;
            যদি (sr) {
                rel = (ElfW_Rel *)sr->তথ্য;
                rel_end = (ElfW_Rel *)(sr->তথ্য + sr->তথ্য_offset);
                sh_addr = s->sh_addr;
                dwarf = s->sh_অঙ্ক >= s1->dwlo && s->sh_অঙ্ক < s1->dwhi;
            }
            s = s->পূর্ব;
            চালু;

        } অন্যথা যদি (i < pe->sec_গুনতি) {
            s = pe->sec_info[i]->sec, ++i;
            চালু;

        } অন্যথা যদি (!গুনতি_2)
            বিরতি;

        /* fill the last block and ready for a new one */
        যদি (গুনতি_2 & 1) /* align for DWORDS */
            section_ptr_add(pe->reloc, আকার(WORD)), ++গুনতি_2;
        hdr = (কাঠামো pe_reloc_header *)(pe->reloc->তথ্য + block_ptr);
        hdr -> offset = offset - pe->imagebase;
        hdr -> আকার_2 = গুনতি_2 * আকার(WORD) + আকার(কাঠামো pe_reloc_header);
        গুনতি_2 = 0;
    }
}

/* ------------------------------------------------------------- */
স্থির শূন্য pe_build_tls(কাঠামো pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    পূর্ণসংখ্যা c, n;

    যদি (0 == s) {
        pe->tls_আকার = আকার (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_add(pe->thunk, pe->tls_আকার, 16);
        pe->tls_তথ্য = section_add(তথ্য_section, PTR_আকার * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, তথ্য_section->sh_অঙ্ক, 0);
        জন্য (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_আকার*n, REL_TYPE_DIRECT, c);
        /* for generators */
        set_elf_sym(symtab_section, pe->tls_তথ্য, PTR_আকার * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, তথ্য_section->sh_অঙ্ক, "__tls_index");
        ফেরত;
    }

    যদি (0 == s1->tls_start)
        s1->tls_start = s->sh_addr;
    d = (শূন্য*)(pe->thunk->তথ্য + pe->tls_dir);
    d->Start_Address_Of_Raw_তথ্য = s1->tls_start - তথ্য_section->sh_addr;
    d->End_Address_Of_Raw_তথ্য = s->sh_addr + s->তথ্য_offset - তথ্য_section->sh_addr;
    d->Address_Of_সূচক = pe->tls_তথ্য;
    d->AddressOfCallBacks = pe->tls_তথ্য + PTR_আকার;
    d->আকার_Of_Zero_Fill = 0;
    d->Characteristics = 0;
    /* to reuse logic from linux in xxx-link.c */
    s1->tls_end = s1->tls_start;
}

/* ------------------------------------------------------------- */
স্থির পূর্ণসংখ্যা pe_section_class(Section *s)
{
    পূর্ণসংখ্যা type, flags;
    ধ্রুবক অক্ষর *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    যদি (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        ফেরত sec_debug;
    } অন্যথা যদি (flags & SHF_ALLOC) {
        যদি (flags & SHF_TLS)
            ফেরত sec_tdata + (type == SHT_NOBITS);
        যদি (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            যদি (flags & SHF_EXECINSTR)
                ফেরত sec_text;
            যদি (flags & SHF_WRITE)
                ফেরত sec_তথ্য;
            যদি (0 == strcmp(name, ".rsrc"))
                ফেরত sec_rsrc;
            যদি (0 == strcmp(name, ".iedat"))
                ফেরত sec_idata;
            যদি (0 == strcmp(name, ".pdata"))
                ফেরত sec_pdata;
            ফেরত sec_rdata;
        } অন্যথা যদি (type == SHT_NOBITS) {
            ফেরত sec_bss;
        }
        ফেরত sec_other;
    } অন্যথা {
        যদি (0 == strcmp(name, ".reloc"))
            ফেরত sec_reloc;
    }
    ফেরত sec_last;
}

স্থির পূর্ণসংখ্যা pe_assign_addresses (কাঠামো pe_info *pe)
{
    পূর্ণসংখ্যা i, k, n, c, nbs;
    ADDR3264 addr;
    পূর্ণসংখ্যা *sec_order, *sec_cls;
    কাঠামো section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    যদি (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_order = tcc_mallocz(2 * আকার (পূর্ণসংখ্যা) * nbs);
    sec_cls = sec_order + nbs;
    জন্য (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        জন্য (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
        যদি ((s->sh_flags & SHF_TLS) && 0 == pe->tls_আকার)
            pe_build_tls(pe, ফাঁকা);
    }
    si = ফাঁকা;
    addr = pe->imagebase + 1;
    জন্য (i = 1; (c = sec_cls[i]) < sec_last; ++i) {
        s = s1->sections[sec_order[i]];

        যদি (PE_MERGE_তথ্য && c == sec_bss)
            c = sec_তথ্য;
        যদি (c == sec_tbss)
            c = sec_tdata;

        যদি (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } অন্যথা {
            si = ফাঁকা;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        যদি (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        যদি (s == pe->reloc)
            pe_build_reloc (pe);

        যদি (0 == s->তথ্য_offset)
            চালু;

        যদি (si)
            যাও add_section;

        si = tcc_mallocz(আকার *si);
        dynarray_add(&pe->sec_info, &pe->sec_গুনতি, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        যদি (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_CODE;
        অন্যথা যদি (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_তথ্য;
        অন্যথা
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_তথ্য;
        যদি (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        যদি (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

add_section:
        s->sh_info = pe->sec_গুনতি; /* section number for coff syms */
        addr += s->তথ্য_offset;
        si->sh_আকার = addr - si->sh_addr;
        যদি (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            যখন (*ps)
                ps = &(*ps)->পূর্ব;
            *ps = s, s->পূর্ব = ফাঁকা;
            si->তথ্য_আকার = si->sh_আকার;
        }

        যদি (s->sh_flags & SHF_TLS) {
            strcpy(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#যদি 0
    জন্য (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_order[i]];
        পূর্ণসংখ্যা type = s->sh_type;
        পূর্ণসংখ্যা flags = s->sh_flags;
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
            (unsigned)s->তথ্য_offset,
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
    ফেরত 0;
}

/*----------------------------------------------------------------------------*/
স্থির পূর্ণসংখ্যা pe_check_symbols(কাঠামো pe_info *pe)
{
    পূর্ণসংখ্যা sym_সূচক, sym_end;
    পূর্ণসংখ্যা ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(text_section, 8);

    sym_end = symtab_section->তথ্য_offset / আকার(ElfW(Sym));
    জন্য (sym_সূচক = 1; sym_সূচক < sym_end; ++sym_সূচক) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->তথ্য + sym_সূচক;
        যদি (sym->st_shndx == SHN_UNDEF) {
            ধ্রুবক অক্ষর *name = (অক্ষর*)symtab_section->link->তথ্য + sym->st_name;
            unsigned type = ELFW(ST_TYPE)(sym->st_info);
            পূর্ণসংখ্যা imp_sym = 0;
            কাঠামো import_প্রতীক *is;

            পূর্ণসংখ্যা _imp_, n;
            অক্ষর বাফার[200];
            ধ্রুবক অক্ষর *s, *p;

            n = _imp_ = 0;
            যদি (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            করো {
                s = pe_export_name(s1, sym);
                যদি (n) {
                    /* second try: */
                    যদি (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        যদি (!p || s[0] != '_')
                            বিরতি;
                        strcpy(বাফার, s+1)[p-s-1] = 0, s = বাফার;
                    } অন্যথা যদি (s[0] != '_') { /* try non-ansi function */
                        বাফার[0] = '_', strcpy(বাফার + 1, s), s = বাফার;
                    } অন্যথা যদি (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } অন্যথা যদি (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } অন্যথা {
                        বিরতি;
                    }
                }
                imp_sym = find_elf_sym(s1->dynsymtab_section, s);
            } যখন (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            যদি (0 == imp_sym)
                চালু; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_add_import(pe, imp_sym);

            যদি (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                unsigned offset = is->thk_offset;
                যদি (offset) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } অন্যথা {
                    unsigned অক্ষর *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(বাফার, "IAT.%s", name);
                    is->iat_সূচক = put_elf_sym(
                        symtab_section, 0, আকার(DWORD),
                        ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT),
                        0, SHN_UNDEF, বাফার);

                    offset = text_section->তথ্য_offset;
                    is->thk_offset = offset;

                    /* add the 'jmp IAT[x]' instruction */
#ifdef TCC_TARGET_ARM
                    p = section_ptr_add(text_section, 8+4); // room for code and address
                    write32le(p + 0, 0xE59FC000); // arm code ldr ip, [pc] ; PC+8+0 = 0001xxxx
                    write32le(p + 4, 0xE59CF000); // arm code ldr pc, [ip]
                    put_elf_reloc(symtab_section, text_section,
                        offset + 8, R_XXX_THUNKFIX, is->iat_সূচক); // offset to IAT position
#নতুবা_যদি defined(TCC_TARGET_ARM64)
                    p = section_ptr_add(text_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, text_section,
                        offset + 16, R_XXX_THUNKFIX, is->iat_সূচক);
#অন্যথা
                    p = section_ptr_add(text_section, 8);
                    write16le(p, 0x25FF);
#ifdef TCC_TARGET_X86_64
                    write32le(p + 2, (DWORD)-4);
#endif
                    put_elf_reloc(symtab_section, text_section, 
                        offset + 2, R_XXX_THUNKFIX, is->iat_সূচক);
#endif
                }
                /* tcc_realloc might have altered sym's address */
                sym = (ElfW(Sym) *)symtab_section->তথ্য + sym_সূচক;
                /* patch the original symbol */
                sym->st_মান = offset;
                sym->st_shndx = text_section->sh_অঙ্ক;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } অন্যথা { /* STT_OBJECT */
                যদি (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_মান = is->iat_সূচক; /* chain potential alias */
                is->iat_সূচক = sym_সূচক;
            }

        } অন্যথা যদি (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    ফেরত ret;
}

/*----------------------------------------------------------------------------*/
#যদি PE_PRINT_SECTIONS
স্থির শূন্য pe_print_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    পূর্ণসংখ্যা i, n, l, m;
    p = s->তথ্য;
    e = s->তথ্য + s->তথ্য_offset;
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
        ফেরত;

    যদি (0 == l)
        ফেরত;

    যদি (s->sh_type == SHT_SYMTAB)
        m = আকার(ElfW(Sym));
    অন্যথা যদি (s->sh_type == SHT_RELX)
        m = আকার(ElfW_Rel);
    অন্যথা
        m = 16;

    fprintf(f, "%-8s", "offset");
    জন্য (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    যদি (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        ধ্রুবক অক্ষর *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            ফাঁকা
        };

        ধ্রুবক অক্ষর *fields2[] = {
            "offs",
            "type",
            "symb",
            ফাঁকা
        };

        ধ্রুবক অক্ষর **p;

        যদি (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        অন্যথা
            p = fields2, n = 58;

        জন্য (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    জন্য (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    জন্য (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        জন্য (n = 0; n < m; ++n) {
            যদি (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            অন্যথা
                fprintf(f, "   ");
        }

        যদি (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            ধ্রুবক অক্ষর *name = s->link->তথ্য + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (unsigned)sym->st_name,
                    (unsigned)sym->st_মান,
                    (unsigned)sym->st_আকার,
                    (unsigned)ELFW(ST_BIND)(sym->st_info),
                    (unsigned)ELFW(ST_TYPE)(sym->st_info),
                    (unsigned)sym->st_other,
                    (unsigned)sym->st_shndx,
                    name);

        } অন্যথা যদি (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->তথ্য + ELFW(R_SYM)(rel->r_info);
            ধ্রুবক অক্ষর *name = s->link->link->তথ্য + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (unsigned)rel->r_offset,
                    (unsigned)ELFW(R_TYPE)(rel->r_info),
                    (unsigned)ELFW(R_SYM)(rel->r_info),
                    name);
        } অন্যথা {
            fprintf(f, "   ");
            জন্য (n = 0; n < m; ++n) {
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

স্থির শূন্য pe_print_sections(TCCState *s1, ধ্রুবক অক্ষর *fname)
{
    Section *s;
    FILE *f;
    পূর্ণসংখ্যা i;
    f = fopen(fname, "w");
    জন্য (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    fclose(f);
}
#endif

/* ------------------------------------------------------------- */

ST_FUNC পূর্ণসংখ্যা pe_putimport(TCCState *s1, পূর্ণসংখ্যা dllindex, ধ্রুবক অক্ষর *name, addr_t মান)
{
    ফেরত set_elf_sym(
        s1->dynsymtab_section,
        মান,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        মান ? SHN_ABS : SHN_UNDEF,
        name
        );
}

স্থির পূর্ণসংখ্যা read_mem(পূর্ণসংখ্যা fd, unsigned offset, শূন্য *বাফার, unsigned len)
{
    lseek(fd, offset, SEEK_SET);
    ফেরত len == পঠ(fd, বাফার, len);
}

/* ------------------------------------------------------------- */

স্থির পূর্ণসংখ্যা get_dllexports(পূর্ণসংখ্যা fd, অক্ষর **pp)
{
    পূর্ণসংখ্যা i, k, l, n, n0, ret;
    অক্ষর *p;

    IMAGE_SECTION_HEADER ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_HEADER dh;
    IMAGE_FILE_HEADER ih;
    DWORD sig, ref, addr;
    DWORD *namep = ফাঁকা, p0 = 0, p1;

    পূর্ণসংখ্যা pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = ফাঁকা;
    ret = 1;
    যদি (!read_mem(fd, 0, &dh, আকার dh))
        যাও the_end;
    যদি (!read_mem(fd, dh.e_lfanew, &sig, আকার sig))
        যাও the_end;
    যদি (sig != 0x00004550)
        যাও the_end;
    pef_hdroffset = dh.e_lfanew + আকার sig;
    যদি (!read_mem(fd, pef_hdroffset, &ih, আকার ih))
        যাও the_end;
    opt_hdroffset = pef_hdroffset + আকার ih;
    যদি (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + আকার oh;
        যদি (!read_mem(fd, opt_hdroffset, &oh, আকার oh))
            যাও the_end;
        যদি (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.সংখ্যা_Of_Rva_And_Sizes)
            যাও the_end_0;
        addr = oh.তথ্য_Directory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } অন্যথা যদি (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + আকার oh;
        যদি (!read_mem(fd, opt_hdroffset, &oh, আকার oh))
            যাও the_end;
        যদি (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.সংখ্যা_Of_Rva_And_Sizes)
            যাও the_end_0;
        addr = oh.তথ্য_Directory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } অন্যথা
        যাও the_end;

    //printf("addr: %08x\n", addr);
    জন্য (i = 0; i < ih.সংখ্যা_Of_Sections; ++i) {
        যদি (!read_mem(fd, sec_hdroffset + i * আকার ish, &ish, আকার ish))
            যাও the_end;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        যদি (addr >= ish.VirtualAddress && addr < ish.VirtualAddress + ish.আকার_Of_Raw_তথ্য)
            যাও found;
    }
    যাও the_end_0;
found:
    ref = ish.VirtualAddress - ish.Pointer_To_Raw_তথ্য;
    যদি (!read_mem(fd, addr - ref, &ied, আকার ied))
        যাও the_end;
    k = ied.সংখ্যা_Of_Names;
    যদি (k) {
        namep = tcc_malloc(l = k * আকার *namep);
        যদি (!read_mem(fd, ied.AddressOfNames - ref, namep, l))
            যাও the_end;
        জন্য (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            যদি (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            করো {
                যদি (0 == l) {
                    যদি (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    যদি ((l = পঠ(fd, p + n, 1000 - 1)) <= 0)
                        যাও the_end;
                }
                --l, ++p0;
            } যখন (p[n++]);
        }
        p[n] = 0;
    }
the_end_0:
    ret = 0;
the_end:
    tcc_free(namep);
    যদি (ret && p)
        tcc_free(p), p = ফাঁকা;
    *pp = p;
    ফেরত ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

স্থির পূর্ণসংখ্যা pe_load_res(TCCState *s1, পূর্ণসংখ্যা fd)
{
    কাঠামো pe_rsrc_header hdr;
    Section *rsrc_section;
    পূর্ণসংখ্যা i, ret = -1, sym_সূচক;
    BYTE *ptr;
    unsigned offs;

    যদি (!read_mem(fd, 0, &hdr, আকার hdr))
        যাও quit;

    যদি (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.সংখ্যা_Of_Sections != 1
        || strcmp((অক্ষর*)hdr.sectionhdr.Name, ".rsrc") != 0)
        যাও quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_add(rsrc_section, hdr.sectionhdr.আকার_Of_Raw_তথ্য);
    offs = hdr.sectionhdr.Pointer_To_Raw_তথ্য;
    যদি (!read_mem(fd, offs, ptr, hdr.sectionhdr.আকার_Of_Raw_তথ্য))
        যাও quit;
    offs = hdr.sectionhdr.PointerToRelocations;
    sym_সূচক = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_অঙ্ক, ".rsrc");
    জন্য (i = 0; i < hdr.sectionhdr.সংখ্যা_Of_Relocations; ++i) {
        কাঠামো pe_rsrc_reloc rel;
        যদি (!read_mem(fd, offs, &rel, আকার rel))
            যাও quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        যদি (rel.type != RSRC_RELTYPE)
            যাও quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.offset, R_XXX_RELATIVE, sym_সূচক);
        offs += আকার rel;
    }
    ret = 0;
quit:
    ফেরত ret;
}

/* ------------------------------------------------------------- */

স্থির অক্ষর *trimfront(অক্ষর *p)
{
    যখন ((unsigned অক্ষর)*p <= ' ' && *p && *p != '\n')
	++p;
    ফেরত p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

স্থির অক্ষর *get_token(অক্ষর **s, অক্ষর *f)
{
    অক্ষর *p, *e;
    পূর্ণসংখ্যা q;

    p = trimfront(*s);
    q = *p;
    যদি (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    অন্যথা
        q = ' ';
    জন্য (e = p; (unsigned অক্ষর)*e >= ' ' && *e != q; ++e)
        ;
    যদি (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    ফেরত p;
}

স্থির পূর্ণসংখ্যা pe_load_def(TCCState *s1, পূর্ণসংখ্যা fd)
{
    পূর্ণসংখ্যা state = 0, ret = -1, dllindex = 0, ord;
    অক্ষর dllname[80], *buf, *সারি, *p, *x, পরবর্তী;

    buf = tcc_load_text(fd);
    যদি (!buf)
        ফেরত ret;

    জন্য (সারি = buf;; ++সারি)  {
        p = get_token(&সারি, &পরবর্তী);
        যদি (!(*p && *p != ';'))
            যাও skip;
        নির্বাচন (state) {
        ক্ষেত্র 0:
            যদি (0 != stricmp(p, "LIBRARY") || পরবর্তী == '\n')
                যাও quit;
            pstrcpy(dllname, আকার dllname, get_token(&সারি, &পরবর্তী));
            যদি (!*tcc_fileextension(dllname))
                pstrcat(dllname, আকার dllname, ".dll");
            ++state;
            বিরতি;
        ক্ষেত্র 1:
            যদি (0 != stricmp(p, "EXPORTS"))
                যাও quit;
            ++state;
            বিরতি;
        ক্ষেত্র 2:
            dllindex = tcc_add_dllref(s1, dllname, 0)->সূচক;
            ++state;
            /* fall through */
        পূর্বনির্ধারিত:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            যদি (পরবর্তী == '@') {
                x = get_token(&সারি, &পরবর্তী);
                ord = (পূর্ণসংখ্যা)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            বিরতি;
        }
skip:
        যখন ((unsigned অক্ষর)পরবর্তী > ' ')
            get_token(&সারি, &পরবর্তী);
        যদি (পরবর্তী != '\n')
            বিরতি;
    }
    ret = 0;
quit:
    tcc_free(buf);
    ফেরত ret;
}

/* ------------------------------------------------------------- */

স্থির পূর্ণসংখ্যা pe_load_dll(TCCState *s1, পূর্ণসংখ্যা fd, ধ্রুবক অক্ষর *filename)
{
    অক্ষর *p, *q;
    DLLReference *ref = tcc_add_dllref(s1, filename, 0);
    যদি (ref->found)
        ফেরত 0;
    যদি (get_dllexports(fd, &p))
        ফেরত -1;
    যদি (p) {
        জন্য (q = p; *q; q += 1 + strlen(q))
            pe_putimport(s1, ref->সূচক, q, 0);
        tcc_free(p);
    }
    ফেরত 0;
}

ST_FUNC পূর্ণসংখ্যা pe_load_file(কাঠামো TCCState *s1, পূর্ণসংখ্যা fd, ধ্রুবক অক্ষর *filename)
{
    পূর্ণসংখ্যা ret = -1;
    অক্ষর buf[10];
    যদি (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_load_def(s1, fd);
    অন্যথা যদি (pe_load_res(s1, fd) == 0)
        ret = 0;
    অন্যথা যদি (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_load_dll(s1, fd, filename);
    ফেরত ret;
}

PUB_FUNC পূর্ণসংখ্যা tcc_get_dllexports(ধ্রুবক অক্ষর *filename, অক্ষর **pp)
{
    পূর্ণসংখ্যা ret, fd = open(filename, O_RDONLY | O_দ্বিমিক_2);
    যদি (fd < 0)
        ফেরত -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    ফেরত ret;
}

/* ------------------------------------------------------------- */
#ifdef TCC_TARGET_X86_64
স্থির unsigned pe_add_unwind_info(TCCState *s1)
{
    যদি (ফাঁকা == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    যদি (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, text_section->sh_অঙ্ক, ".uw_base");
    যদি (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        স্থির ধ্রুবক unsigned অক্ষর uw_info[] = {
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
        unsigned অক্ষর *p;

        section_ptr_add(s, -s->তথ্য_offset & 3); /* align */
        s1->uw_offs = s->তথ্য_offset;
        p = section_ptr_add(s, আকার uw_info);
        memcpy(p, uw_info, আকার uw_info);
    }

    ফেরত s1->uw_offs;
}

ST_FUNC শূন্য pe_add_unwind_তথ্য(unsigned start, unsigned end, unsigned স্তূপ)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    unsigned o, n, d;
    কাঠামো /* _RUNTIME_FUNCTION */ {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD Unwind_তথ্য;
    } *p;

    d = pe_add_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->তথ্য_offset;
    p = section_ptr_add(pd, আকার *p);

    /* record this function */
    p->BeginAddress = start;
    p->EndAddress = end;
    p->Unwind_তথ্য = d;

    /* put relocations on it */
    জন্য (n = o + আকার *p; o < n; o += আকার p->BeginAddress)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#নতুবা_যদি defined(TCC_TARGET_ARM64)
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

    যদি (ফাঁকা == s1->uw_pdata) {
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
    ফেরত s;
}

ST_FUNC শূন্য pe_add_unwind_তথ্য(unsigned start, unsigned end, unsigned স্তূপ)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    unsigned o, d, code_bytes, func_len;
    unsigned অক্ষর *q;
    uint32_t header;
    কাঠামো /* _RUNTIME_FUNCTION */ {
        DWORD BeginAddress;
        DWORD Unwind_তথ্য;
    } *p;

    পূর্ণসংখ্যা epilog;

    xd = pe_add_unwind_info(s1);
    pd = s1->uw_pdata;

    func_len = (end - start) >> 2;
    code_bytes = 0;
    epilog = code_bytes;
    code_bytes += 3; /* set_fp, save_fplr_x, end */
    code_bytes = (code_bytes + 3) & ~3;

    section_ptr_add(xd, -xd->তথ্য_offset & 3);
    d = xd->তথ্য_offset;
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
    যখন ((unsigned)(q - (xd->তথ্য + d + 4)) < code_bytes)
        *q++ = 0xE3; /* nop padding */

    o = pd->তথ্য_offset;
    p = section_ptr_add(pd, আকার *p);
    p->BeginAddress = start;
    p->Unwind_তথ্য = d;
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

স্থির শূন্য pe_add_runtime(TCCState *s1, কাঠামো pe_info *pe)
{
    ধ্রুবক অক্ষর *start_প্রতীক;
    পূর্ণসংখ্যা pe_type;

    যদি (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        start_প্রতীক = PE_STDSYM("__dllstart","@12");
    } অন্যথা {
        ধ্রুবক অক্ষর *run_প্রতীক;
        যদি (find_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            start_প্রতীক = "__winstart";
            run_প্রতীক = "__runwinmain";
            pe_type = PE_GUI;
        } অন্যথা যদি (find_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            start_প্রতীক = "__wwinstart";
            run_প্রতীক = "__runwwinmain";
            pe_type = PE_GUI;
        } অন্যথা যদি (find_elf_sym(symtab_section, "wmain")) {
            start_প্রতীক = "__wstart";
            run_প্রতীক = "__runwmain";
            pe_type = PE_EXE;
        } অন্যথা {
            start_প্রতীক =  "__start";
            run_প্রতীক = "__runmain";
            pe_type = PE_EXE;
            যদি (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        যদি (TCC_OUTPUT_MEMORY == s1->output_type && !s1->nostdlib)
            start_প্রতীক = run_প্রতীক;
    }
    যদি (s1->elf_entryname) {
        pe->start_প্রতীক = start_প্রতীক = s1->elf_entryname;
    } অন্যথা {
        pe->start_প্রতীক = start_প্রতীক + 1;
        যদি (!s1->leading_underscore || strchr(start_প্রতীক, '@'))
            ++start_প্রতীক;
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
    set_global_sym(s1, start_প্রতীক, ফাঁকা, 0);

    যদি (0 == s1->nostdlib) {
        স্থির ধ্রুবক অক্ষর * ধ্রুবক libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", ফাঁকা
        };
        ধ্রুবক অক্ষর * ধ্রুবক *pp, *p;
        যদি (TCC_LIBTCC1[0])
            tcc_add_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        জন্য (pp = libs; 0 != (p = *pp); ++pp) {
            যদি (*p)
                tcc_add_library(s1, p);
            অন্যথা যদি (PE_DLL != pe_type && PE_GUI != pe_type)
                বিরতি;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    যদি (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    যদি (TCC_OUTPUT_MEMORY == s1->output_type)
        pe_type = PE_RUN;
    pe->type = pe_type;
}

ST_FUNC পূর্ণসংখ্যা pe_setsubsy(TCCState *s1, ধ্রুবক অক্ষর *arg)
{
    স্থির ধ্রুবক কাঠামো subsy { ধ্রুবক অক্ষর* p; পূর্ণসংখ্যা v; } x[] = {
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
#নতুবা_যদি defined(TCC_TARGET_ARM)
        { "wince", 9 },
#endif
        { 0, -1 }};
    ধ্রুবক কাঠামো subsy *y;
    জন্য (y = x;; ++y) {
        যদি (!y->p)
            ফেরত -1;
        যদি (0 == strcmp(y->p, arg)) {
            s1->pe_subsystem = y->v;
            ফেরত 0;
        }
    }
}

স্থির শূন্য pe_set_options(TCCState * s1, কাঠামো pe_info *pe)
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

ST_FUNC পূর্ণসংখ্যা pe_output_file(TCCState *s1, ধ্রুবক অক্ষর *filename)
{
    কাঠামো pe_info pe;

    memset(&pe, 0, আকার pe);
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
        যাও done;
    যদি (filename) {
        pe_assign_addresses(&pe);
        relocate_syms(s1, s1->symtab, 0);
        যদি (s1->nb_errors)
            যাও done;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.start_addr = (DWORD)
            (get_sym_addr(s1, pe.start_প্রতীক, 1, 1) - pe.imagebase);
        যদি (s1->nb_errors)
            যাও done;
        pe_write(&pe);
    } অন্যথা {
        /* -run */
#ifdef TCC_IS_NATIVE
        pe.thunk = তথ্য_section;
        pe_build_imports(&pe);
        s1->run_main = pe.start_প্রতীক;
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
    ফেরত s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
