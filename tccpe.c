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

#அந்தர்பாவ "tcc.h"

#define PE_MERGE_DATA 1
#define PE_PRINT_SECTIONS 0

#ifndef _WIN32
#define stricmp strcasecmp
#define strnicmp strncasecmp
#அந்தர்பாவ <sys/stat.h> /* chmod() */
#endif

#எனில் defined TCC_TARGET_X86_64
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

#அல்லதெனில் defined TCC_TARGET_ARM
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

#அல்லதெனில் defined TCC_TARGET_ARM64
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

#அல்லதெனில் defined TCC_TARGET_I386
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

#எனில் PTR_SIZE == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#இல்லையெனில்
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#endif

#ifndef IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

வகைவரை unsigned எழுத்து BYTE;
வகைவரை unsigned short WORD;
வகைவரை unsigned முழு DWORD;
வகைவரை unsigned long long ULONGLONG;
#pragma pack(தள்ளு, 1)

வகைவரை கட்டமைப்பு _IMAGE_DOS_HEADER {  /* DOS .EXE header */
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

வகைவரை கட்டமைப்பு _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    எண்_Of_Sections;
    DWORD   TimeDateStamp;
    DWORD   Pointer_To_குறியீடு_Table;
    DWORD   எண்_Of_Symbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;


#define IMAGE_SIZEOF_FILE_HEADER 20

வகைவரை கட்டமைப்பு _IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;


வகைவரை கட்டமைப்பு _IMAGE_OPTIONAL_HEADER {
    /* Standard fields. */
    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
#எனில் PTR_SIZE == 4
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
    DWORD   Win32_Version_மதிப்பு;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    ADDR3264 Size_Of_அடுக்கு_Reserve;
    ADDR3264 Size_Of_அடுக்கு_Commit;
    ADDR3264 SizeOfHeapReserve;
    ADDR3264 SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   எண்_Of_Rva_And_Sizes;
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

வகைவரை கட்டமைப்பு _IMAGE_SECTION_HEADER {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    ஒன்றிப்பு {
            DWORD   PhysicalAddress;
            DWORD   VirtualSize;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   SizeOfRawData;
    DWORD   PointerToRawData;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    எண்_Of_Relocations;
    WORD    எண்_Of_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#define IMAGE_SIZEOF_SECTION_HEADER     40

வகைவரை கட்டமைப்பு _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD Name;
    DWORD Base;
    DWORD எண்_Of_Functions;
    DWORD எண்_Of_Names;
    DWORD AddressOfFunctions;
    DWORD AddressOfNames;
    DWORD AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

வகைவரை கட்டமைப்பு _IMAGE_TLS_DIRECTORY {
    ADDR3264 StartAddressOfRawData;
    ADDR3264 EndAddressOfRawData;
    ADDR3264 AddressOfIndex;
    ADDR3264 AddressOfCallBacks;
    DWORD SizeOfZeroFill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

வகைவரை கட்டமைப்பு _IMAGE_IMPORT_DESCRIPTOR {
    ஒன்றிப்பு {
        DWORD Characteristics;
        DWORD OriginalFirstThunk;
    };
    DWORD TimeDateStamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;

வகைவரை கட்டமைப்பு _IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   SizeOfBlock;
//  WORD    TypeOffset[1];
} IMAGE_BASE_RELOCATION;

#define IMAGE_SIZEOF_BASE_RELOCATION     8

#define IMAGE_REL_BASED_ABSOLUTE         0
#define IMAGE_REL_BASED_உயர்வு             1
#define IMAGE_REL_BASED_கீழ்              2
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

#define IMAGE_DLLCHARACTERISTICS_உயர்வு_ENTROPY_VA 0x0020
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#define IMAGE_FILE_RELOCS_STRIPPED 0x0001

#pragma pack(எடு)

/* ----------------------------------------------------------- */
#endif /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#ifndef IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#endif

#pragma pack(தள்ளு, 1)
கட்டமைப்பு pe_header
{
    IMAGE_DOS_HEADER doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_HEADER filehdr;
#எனில் PTR_SIZE == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#இல்லையெனில்
#ifdef _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#இல்லையெனில்
    IMAGE_OPTIONAL_HEADER opthdr;
#endif
#endif
};

கட்டமைப்பு pe_reloc_header {
    DWORD offset;
    DWORD size;
};

கட்டமைப்பு pe_rsrc_header {
    கட்டமைப்பு _IMAGE_FILE_HEADER filehdr;
    கட்டமைப்பு _IMAGE_SECTION_HEADER sectionhdr;
};

கட்டமைப்பு pe_rsrc_reloc {
    DWORD offset;
    DWORD size;
    WORD type;
};
#pragma pack(எடு)

/* ------------------------------------------------------------- */
/* internal temporary structures */

எண்ணிக்கை {
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

#எனில் 0
நிலையான மாறிலி DWORD pe_sec_flags[] = {
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

கட்டமைப்பு section_info {
    முழு cls;
    எழுத்து name[32];
    ADDR3264 sh_addr;
    DWORD sh_size;
    DWORD pe_flags;
    Section *sec;
    DWORD data_size;
    IMAGE_SECTION_HEADER ish;
};

கட்டமைப்பு import_குறியீடு {
    முழு sym_index;
    முழு iat_index;
    முழு thk_offset;
};

கட்டமைப்பு pe_import_info {
    முழு dll_index;
    முழு sym_மொத்தம்;
    கட்டமைப்பு import_குறியீடு **symbols;
};

கட்டமைப்பு pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    மாறிலி எழுத்து *filename;
    முழு type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    மாறிலி எழுத்து *start_குறியீடு;
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
    முழு subsystem;
    DWORD section_align;
    DWORD file_align;
    கட்டமைப்பு section_info **sec_info;
    முழு sec_மொத்தம்;
    கட்டமைப்பு pe_import_info **imp_info;
    முழு imp_மொத்தம்;
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

நிலையான மாறிலி எழுத்து *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    மாறிலி எழுத்து *name = (எழுத்து*)symtab_section->link->data + sym->st_name;
    எனில் (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        திரும்பு name + 1;
    திரும்பு name;
}


நிலையான முழு dynarray_assoc(வெறுமை **pp, முழு n, முழு சாவி)
{
    முழு i;
    க்கு (i = 0; i < n; ++i, ++pp)
    எனில் (சாவி == **(முழு **) pp)
        திரும்பு i;
    திரும்பு -1;
}

நிலையான DWORD umin(DWORD a, DWORD b)
{
    திரும்பு a < b ? a : b;
}

நிலையான DWORD umax(DWORD a, DWORD b)
{
    திரும்பு a < b ? b : a;
}

நிலையான DWORD pe_file_align(கட்டமைப்பு pe_info *pe, DWORD n)
{
    திரும்பு (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

நிலையான ADDR3264 pe_virtual_align(கட்டமைப்பு pe_info *pe, ADDR3264 n)
{
    திரும்பு (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

நிலையான வெறுமை pe_align_section(Section *s, முழு a)
{
    முழு i = s->data_offset & (a-1);
    எனில் (i)
        section_ptr_add(s, a - i);
}

நிலையான வெறுமை pe_set_datadir(கட்டமைப்பு pe_header *hdr, முழு dir, DWORD addr, DWORD size)
{
    hdr->opthdr.DataDirectory[dir].VirtualAddress = addr;
    hdr->opthdr.DataDirectory[dir].Size = size;
}

நிலையான முழு pe_fwrite(கட்டமைப்பு pe_info *pe, மாறிலி வெறுமை *data, முழு len)
{
    மாறிலி WORD *p = data;
    DWORD sum;
    முழு ret, i;
    pe->pos += (ret = fwrite(data, 1, len, pe->op));
    sum = pe->sum;
    க்கு (i = len; i > 0; i -= 2) {
        sum += (i >= 2) ? *p++ : *(BYTE*)p;
        sum = (sum + (sum >> 16)) & 0xFFFF;
    }
    pe->sum = sum;
    திரும்பு len == ret ? 0 : -1;
}

நிலையான வெறுமை pe_fpad(கட்டமைப்பு pe_info *pe, DWORD new_pos)
{
    எழுத்து buf[256];
    முழு n, diff = new_pos - pe->pos;
    memset(buf, 0, அளவு buf);
    போது (diff > 0) {
        diff -= n = umin(diff, அளவு buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#pragma pack(தள்ளு, 1)
கட்டமைப்பு syment
{
    ஒன்றிப்பு {
        எழுத்து        n_name[8];     /* old COFF version */
        கட்டமைப்பு {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_offset;      /* offset into string table */
        };
    };
    int32_t         n_மதிப்பு;        /* value of symbol */
    short           n_scnum;        /* section number */
    unsigned short  n_type;         /* type and derived type */
    எழுத்து            n_sclass;       /* storage class */
    எழுத்து            n_numaux;       /* number of aux. entries */
};
#pragma pack(எடு)

#define SHF_PRIVATE 0x80000000

நிலையான வெறுமை pe_add_coffsym(கட்டமைப்பு pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    கட்டமைப்பு syment *se;
    முழு n;

    எனில் (வெற்று == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_PRIVATE);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_PRIVATE);
        section_ptr_add(pe->coffstr, 4); /* coff string table size */
        திரும்பு;
    }

#எனில் 0
    se = section_ptr_add(pe->coffsym, அளவு *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_add(pe->coffsym, அளவு *se);
    strcpy((எழுத்து*)se, "no-file");
#endif

#எனில் 1
    esym = (ElfSym*)s1->symtab->data;
    க்கு (n = s1->symtab->data_offset / அளவு *esym; ++esym, --n;) {
        முழு sym_bind = ELFW(ST_BIND)(esym->st_info);
        எனில் (sym_bind == STB_GLOBAL) {
            எழுத்து *name = esym->st_name + (எழுத்து*)s1->symtab->link->data;
            முழு nl = strlen(name);
            addr_t மதிப்பு = esym->st_மதிப்பு;
            முழு shnum = esym->st_shndx;
            எனில் (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                மதிப்பு = மதிப்பு - s->sh_addr;
            }
            se = section_ptr_add(pe->coffsym, அளவு *se);
            se->n_மதிப்பு = மதிப்பு;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            எனில் (nl <= 8)
                memcpy(se->n_name, name, nl);
            இல்லையெனில்
                se->n_offset = put_elf_str(pe->coffstr, name);
        }
    }
#endif
    write32le(pe->coffstr->data, pe->coffstr->data_offset); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
நிலையான வெறுமை pe_create_pdb(TCCState *s1, மாறிலி எழுத்து *exename)
{
    எழுத்து buf[300]; முழு r;
    snprintf(buf, அளவு buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    strcpy(tcc_fileextension(strcpy(buf, exename)), ".pdb");
    எனில் (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } இல்லையெனில் எனில் (s1->verbose) {
        printf("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
நிலையான முழு pe_write(கட்டமைப்பு pe_info *pe)
{
    நிலையான மாறிலி கட்டமைப்பு pe_header pe_template = {
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
#எனில் PTR_SIZE == 4
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

    கட்டமைப்பு pe_header pe_header = pe_template;

    முழு i;
    DWORD file_offset;
    கட்டமைப்பு section_info *si;
    IMAGE_SECTION_HEADER *psh;
    TCCState *s1 = pe->s1;

    எனில் (s1->do_debug)
        pe_add_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    எனில் (வெற்று == pe->op)
        திரும்பு tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        அளவு (கட்டமைப்பு pe_header)
        + pe->sec_மொத்தம் * அளவு (IMAGE_SECTION_HEADER)
        );

    file_offset = pe->sizeofheaders;

    எனில் (2 == s1->verbose)
        printf("-------------------------------"
               "\n  virt   file   size  section" "\n");
    க்கு (i = 0; i < pe->sec_மொத்தம்; ++i) {
        DWORD addr, size;
        மாறிலி எழுத்து *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        size = si->sh_size;
        psh = &si->ish;

        எனில் (2 == s1->verbose)
            printf("%6x %6x %6x  %s\n",
                (unsigned)addr, (unsigned)file_offset, (unsigned)size, sh_name);

        தேர்வு (si->cls) {
            நிலை sec_text:
                எனில் (!pe_header.opthdr.BaseOfCode)
                    pe_header.opthdr.BaseOfCode = addr;
                நிறுத்து;

            நிலை sec_data:
#எனில் PTR_SIZE == 4
                எனில் (!pe_header.opthdr.BaseOfData)
                    pe_header.opthdr.BaseOfData = addr;
#endif
                நிறுத்து;

            நிலை sec_bss:
                நிறுத்து;

            நிலை sec_reloc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_BASERELOC, addr, size);
                நிறுத்து;

            நிலை sec_rsrc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_RESOURCE, addr, size);
                நிறுத்து;

            நிலை sec_pdata:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXCEPTION, addr, size);
                நிறுத்து;
        }

        எனில் (pe->imp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IMPORT,
                pe->imp_offs, pe->imp_size);
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IAT,
                pe->iat_offs, pe->iat_size);
        }
        எனில் (pe->exp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXPORT,
                pe->exp_offs, pe->exp_size);
        }
        எனில் (pe->tls_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_size);
        }

        memcpy(psh->Name, sh_name, umin(strlen(sh_name), அளவு psh->Name));
        எனில் (pe->coffstr && strlen(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((எழுத்து*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->VirtualAddress = addr;
        psh->Misc.VirtualSize = size;
        pe_header.opthdr.SizeOfImage =
            umax(pe_virtual_align(pe, size + addr), pe_header.opthdr.SizeOfImage);

        எனில் (si->data_size) {
            psh->PointerToRawData = file_offset;
            file_offset = pe_file_align(pe, file_offset + si->data_size);
            psh->SizeOfRawData = file_offset - psh->PointerToRawData;
            எனில் (si->cls == sec_text)
                pe_header.opthdr.SizeOfCode += psh->SizeOfRawData;
            இல்லையெனில்
                pe_header.opthdr.SizeOfInitializedData += psh->SizeOfRawData;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_header.filehdr.எண்_Of_Sections = pe->sec_மொத்தம்;
    pe_header.opthdr.AddressOfEntryPoint = pe->start_addr;
    pe_header.opthdr.SizeOfHeaders = pe->sizeofheaders;
    pe_header.opthdr.ImageBase = pe->imagebase;
    pe_header.opthdr.Subsystem = pe->subsystem;
    pe_header.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    எனில் (s1->pe_அடுக்கு_size)
        pe_header.opthdr.Size_Of_அடுக்கு_Reserve = s1->pe_அடுக்கு_size;
    எனில் (PE_DLL == pe->type)
        pe_header.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_header.filehdr.Characteristics |= s1->pe_characteristics;
    எனில் (pe->reloc)
        pe_header.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    எனில் (pe->coffsym) {
        pe_add_coffsym(pe);
        pe_header.filehdr.Pointer_To_குறியீடு_Table = file_offset;
        pe_header.filehdr.எண்_Of_Symbols
            = pe->coffsym->data_offset / அளவு (கட்டமைப்பு syment);
    }

    pe_fwrite(pe, &pe_header, அளவு pe_header);
    க்கு (i = 0; i < pe->sec_மொத்தம்; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, அளவு(IMAGE_SECTION_HEADER));

    file_offset = pe->sizeofheaders;
    க்கு (i = 0; i < pe->sec_மொத்தம்; ++i) {
        Section *s;
        si = pe->sec_info[i];
        எனில் (!si->data_size)
            தொடர்;
        க்கு (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_offset);
            pe_fwrite(pe, s->data, s->data_offset);
            எனில் (s->prev)
                file_offset += s->prev->sh_addr - s->sh_addr;
        }
        file_offset = si->ish.PointerToRawData + si->ish.SizeOfRawData;
        pe_fpad(pe, file_offset);
    }

    எனில் (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->data, pe->coffsym->data_offset);
        pe_fwrite(pe, pe->coffstr->data, pe->coffstr->data_offset);
        file_offset = pe->pos;
    }

    pe->sum += file_offset;
    fseek(pe->op, offsetof(கட்டமைப்பு pe_header, opthdr.CheckSum), SEEK_SET);
    pe_fwrite(pe, &pe->sum, அளவு (DWORD));

    fclose (pe->op);
#ifndef _WIN32
    chmod(pe->filename, 0777);
#endif

    எனில் (2 == s1->verbose)
        printf("-------------------------------\n");
    எனில் (s1->verbose)
        printf("<- %s (%u bytes)\n", pe->filename, (unsigned)file_offset);

    எனில் (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    திரும்பு 0;
}

/*----------------------------------------------------------------------------*/

நிலையான கட்டமைப்பு import_குறியீடு *pe_add_import(கட்டமைப்பு pe_info *pe, முழு sym_index)
{
    முழு i;
    முழு dll_index;
    கட்டமைப்பு pe_import_info *p;
    கட்டமைப்பு import_குறியீடு *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->data + sym_index;
    dll_index = isym->st_size;

    i = dynarray_assoc ((வெறுமை**)pe->imp_info, pe->imp_மொத்தம், dll_index);
    எனில் (-1 != i) {
        p = pe->imp_info[i];
        செல் found_dll;
    }
    p = tcc_mallocz(அளவு *p);
    p->dll_index = dll_index;
    dynarray_add(&pe->imp_info, &pe->imp_மொத்தம், p);

found_dll:
    i = dynarray_assoc ((வெறுமை**)p->symbols, p->sym_மொத்தம், sym_index);
    எனில் (-1 != i)
        திரும்பு p->symbols[i];

    s = tcc_mallocz(அளவு *s);
    dynarray_add(&p->symbols, &p->sym_மொத்தம், s);
    s->sym_index = sym_index;
    திரும்பு s;
}

நிலையான வெறுமை pe_free_imports(கட்டமைப்பு pe_info *pe)
{
    முழு i;
    க்கு (i = 0; i < pe->imp_மொத்தம்; ++i) {
        கட்டமைப்பு pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_மொத்தம்);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_மொத்தம்);
}

/*----------------------------------------------------------------------------*/
நிலையான வெறுமை pe_build_imports(கட்டமைப்பு pe_info *pe)
{
    முழு thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_base = pe->thunk->sh_addr - pe->imagebase;
    முழு ndlls = pe->imp_மொத்தம்;
    TCCState *s1 = pe->s1;

    க்கு (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_மொத்தம்;

    எனில் (0 == sym_cnt)
        திரும்பு;

    pe_align_section(pe->thunk, 16);
    pe->imp_size = (ndlls + 1) * அளவு(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_size = (sym_cnt + ndlls) * அளவு(ADDR3264);
    dll_ptr = pe->thunk->data_offset;
    thk_ptr = dll_ptr + pe->imp_size;
    ent_ptr = thk_ptr + pe->iat_size;
    pe->imp_offs = dll_ptr + rva_base;
    pe->iat_offs = thk_ptr + rva_base;
    section_ptr_add(pe->thunk, pe->imp_size + 2*pe->iat_size);

    க்கு (i = 0; i < pe->imp_மொத்தம்; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        முழு k, n, dllindex;
        ADDR3264 v;
        கட்டமைப்பு pe_import_info *p = pe->imp_info[i];
        மாறிலி எழுத்து *name;
        DLLReference *dllref;

        dllindex = p->dll_index;
        எனில் (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        இல்லையெனில்
            name = "", dllref = வெற்று;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->data + dll_ptr);
        hdr->FirstThunk = thk_ptr + rva_base;
        hdr->OriginalFirstThunk = ent_ptr + rva_base;
        hdr->Name = v + rva_base;

        க்கு (k = 0, n = p->sym_மொத்தம்; k <= n; ++k) {
            எனில் (k < n) {
                முழு iat_index = p->symbols[k]->iat_index;
                முழு sym_index = p->symbols[k]->sym_index;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->data + sym_index;
                மாறிலி எழுத்து *name = (எழுத்து*)s1->dynsymtab_section->link->data + imp_sym->st_name;
                முழு ordinal;

                /* patch symbol (and possibly its underscored alias) */
                செய் {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->data + iat_index;
                    iat_index = esym->st_மதிப்பு;
                    esym->st_மதிப்பு = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_இலக்கம்;
                } போது (iat_index);

                எனில் (dllref)
                    v = 0, ordinal = imp_sym->st_மதிப்பு; /* ordinal from pe_load_def */
                இல்லையெனில்
                    ordinal = 0, v = imp_sym->st_மதிப்பு; /* address from tcc_add_symbol() */

#ifdef TCC_IS_NATIVE
                எனில் (pe->type == PE_RUN) {
                    எனில் (dllref) {
                        எனில் ( !dllref->handle )
                            dllref->handle = LoadLibraryA(dllref->name);
                        v = (ADDR3264)GetProcAddress(dllref->handle, ordinal?(எழுத்து*)0+ordinal:name);
                    }
                    எனில் (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } இல்லையெனில்
#endif
                எனில் (ordinal) {
                    v = ordinal | (ADDR3264)1 << (அளவு(ADDR3264)*8 - 1);
                } இல்லையெனில் {
                    v = pe->thunk->data_offset + rva_base;
                    section_ptr_add(pe->thunk, அளவு(WORD)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } இல்லையெனில் {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->data+thk_ptr) =
            *(ADDR3264*)(pe->thunk->data+ent_ptr) = v;
            thk_ptr += அளவு (ADDR3264);
            ent_ptr += அளவு (ADDR3264);
        }
        dll_ptr += அளவு(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

கட்டமைப்பு pe_sort_sym
{
    முழு index;
    மாறிலி எழுத்து *name;
};

நிலையான முழு sym_cmp(மாறிலி வெறுமை *va, மாறிலி வெறுமை *vb)
{
    மாறிலி எழுத்து *ca = (*(கட்டமைப்பு pe_sort_sym**)va)->name;
    மாறிலி எழுத்து *cb = (*(கட்டமைப்பு pe_sort_sym**)vb)->name;
    திரும்பு strcmp(ca, cb);
}

நிலையான வெறுமை pe_build_exports(கட்டமைப்பு pe_info *pe)
{
    ElfW(Sym) *sym;
    முழு sym_index, sym_end;
    DWORD rva_base, base_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    முழு sym_மொத்தம், ord;
    கட்டமைப்பு pe_sort_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    எழுத்து buf[260];
    மாறிலி எழுத்து *dllname;
    மாறிலி எழுத்து *name;

    rva_base = pe->thunk->sh_addr - pe->imagebase;
    sym_மொத்தம் = 0, sorted = வெற்று, op = வெற்று;

    sym_end = symtab_section->data_offset / அளவு(ElfW(Sym));
    க்கு (sym_index = 1; sym_index < sym_end; ++sym_index) {
        sym = (ElfW(Sym)*)symtab_section->data + sym_index;
        name = pe_export_name(s1, sym);
        எனில் (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(அளவு *p);
            p->index = sym_index;
            p->name = name;
            dynarray_add(&sorted, &sym_மொத்தம், p);
        }
#எனில் 0
        எனில் (sym->st_other & ST_PE_EXPORT)
            printf("export: %s\n", name);
        எனில் (sym->st_other & ST_PE_STDCALL)
            printf("stdcall: %s\n", name);
#endif
    }

    எனில் (0 == sym_மொத்தம்)
        திரும்பு;

    qsort (sorted, sym_மொத்தம், அளவு *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    base_o = pe->thunk->data_offset;
    func_o = base_o + அளவு(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_மொத்தம் * அளவு (DWORD);
    ord_o = name_o + sym_மொத்தம் * அளவு (DWORD);
    str_o = ord_o + sym_மொத்தம் * அளவு(WORD);

    hdr = section_ptr_add(pe->thunk, str_o - base_o);
    hdr->Characteristics        = 0;
    hdr->Base                   = 1;
    hdr->எண்_Of_Functions      = sym_மொத்தம்;
    hdr->எண்_Of_Names          = sym_மொத்தம்;
    hdr->AddressOfFunctions     = func_o + rva_base;
    hdr->AddressOfNames         = name_o + rva_base;
    hdr->AddressOfNameOrdinals  = ord_o + rva_base;
    hdr->Name                   = str_o + rva_base;
    put_elf_str(pe->thunk, dllname);

#எனில் 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, அளவு buf, pe->filename);
    strcpy(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    எனில் (வெற்று == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } இல்லையெனில் {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        எனில் (s1->verbose)
            printf("<- %s (%d symbol%s)\n", buf, sym_மொத்தம், &"s"[sym_மொத்தம் < 2]);
    }
#endif

    க்கு (ord = 0; ord < sym_மொத்தம்; ++ord)
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
        func_o += அளவு (DWORD);
        name_o += அளவு (DWORD);
        ord_o += அளவு (WORD);
        எனில் (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = base_o + rva_base;
    pe->exp_size = pe->thunk->data_offset - base_o;
    dynarray_reset(&sorted, &sym_மொத்தம்);
    எனில் (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
நிலையான வெறுமை pe_build_reloc (கட்டமைப்பு pe_info *pe)
{
    DWORD offset, block_ptr, sh_addr, addr;
    முழு மொத்தம்_2, i;
    ElfW_Rel *rel, *rel_end;
    Section *s = வெற்று, *sr;
    கட்டமைப்பு pe_reloc_header *hdr;
    TCCState *s1 = pe->s1;
    முழு dwarf = 0, n;

    sh_addr = offset = block_ptr = மொத்தம்_2 = i = 0;
    rel = rel_end = வெற்று;

    க்கு(;;) {
        எனில் (rel < rel_end) {
            முழு type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_offset + sh_addr;
            ++ rel;
            எனில் (type != REL_TYPE_DIRECT)
                தொடர்;
            எனில் (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->data + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                எனில் (n >= s1->dwlo && n < s1->dwhi)
                    தொடர்;
            }
            எனில் (மொத்தம்_2 == 0) { /* new block */
                block_ptr = pe->reloc->data_offset;
                section_ptr_add(pe->reloc, அளவு(கட்டமைப்பு pe_reloc_header));
                offset = addr & 0xFFFFFFFF<<12;
            }
            எனில் ((addr -= offset)  < (1<<12)) { /* one block spans 4k addresses */
                WORD *wp = section_ptr_add(pe->reloc, அளவு (WORD));
                *wp = addr | PE_IMAGE_REL<<12;
                ++மொத்தம்_2;
                தொடர்;
            }
            -- rel;

        } இல்லையெனில் எனில் (s) {
            sr = s->reloc;
            எனில் (sr) {
                rel = (ElfW_Rel *)sr->data;
                rel_end = (ElfW_Rel *)(sr->data + sr->data_offset);
                sh_addr = s->sh_addr;
                dwarf = s->sh_இலக்கம் >= s1->dwlo && s->sh_இலக்கம் < s1->dwhi;
            }
            s = s->prev;
            தொடர்;

        } இல்லையெனில் எனில் (i < pe->sec_மொத்தம்) {
            s = pe->sec_info[i]->sec, ++i;
            தொடர்;

        } இல்லையெனில் எனில் (!மொத்தம்_2)
            நிறுத்து;

        /* fill the last block and ready for a new one */
        எனில் (மொத்தம்_2 & 1) /* align for DWORDS */
            section_ptr_add(pe->reloc, அளவு(WORD)), ++மொத்தம்_2;
        hdr = (கட்டமைப்பு pe_reloc_header *)(pe->reloc->data + block_ptr);
        hdr -> offset = offset - pe->imagebase;
        hdr -> size = மொத்தம்_2 * அளவு(WORD) + அளவு(கட்டமைப்பு pe_reloc_header);
        மொத்தம்_2 = 0;
    }
}

/* ------------------------------------------------------------- */
நிலையான வெறுமை pe_build_tls(கட்டமைப்பு pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    முழு c, n;

    எனில் (0 == s) {
        pe->tls_size = அளவு (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_add(pe->thunk, pe->tls_size, 16);
        pe->tls_data = section_add(data_section, PTR_SIZE * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, data_section->sh_இலக்கம், 0);
        க்கு (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_SIZE*n, REL_TYPE_DIRECT, c);
        /* for generators */
        set_elf_sym(symtab_section, pe->tls_data, PTR_SIZE * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, data_section->sh_இலக்கம், "__tls_index");
        திரும்பு;
    }

    எனில் (0 == s1->tls_start)
        s1->tls_start = s->sh_addr;
    d = (வெறுமை*)(pe->thunk->data + pe->tls_dir);
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
நிலையான முழு pe_section_class(Section *s)
{
    முழு type, flags;
    மாறிலி எழுத்து *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    எனில் (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        திரும்பு sec_debug;
    } இல்லையெனில் எனில் (flags & SHF_ALLOC) {
        எனில் (flags & SHF_TLS)
            திரும்பு sec_tdata + (type == SHT_NOBITS);
        எனில் (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            எனில் (flags & SHF_EXECINSTR)
                திரும்பு sec_text;
            எனில் (flags & SHF_WRITE)
                திரும்பு sec_data;
            எனில் (0 == strcmp(name, ".rsrc"))
                திரும்பு sec_rsrc;
            எனில் (0 == strcmp(name, ".iedat"))
                திரும்பு sec_idata;
            எனில் (0 == strcmp(name, ".pdata"))
                திரும்பு sec_pdata;
            திரும்பு sec_rdata;
        } இல்லையெனில் எனில் (type == SHT_NOBITS) {
            திரும்பு sec_bss;
        }
        திரும்பு sec_other;
    } இல்லையெனில் {
        எனில் (0 == strcmp(name, ".reloc"))
            திரும்பு sec_reloc;
    }
    திரும்பு sec_last;
}

நிலையான முழு pe_assign_addresses (கட்டமைப்பு pe_info *pe)
{
    முழு i, k, n, c, nbs;
    ADDR3264 addr;
    முழு *sec_order, *sec_cls;
    கட்டமைப்பு section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    எனில் (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_order = tcc_mallocz(2 * அளவு (முழு) * nbs);
    sec_cls = sec_order + nbs;
    க்கு (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        க்கு (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
        எனில் ((s->sh_flags & SHF_TLS) && 0 == pe->tls_size)
            pe_build_tls(pe, வெற்று);
    }
    si = வெற்று;
    addr = pe->imagebase + 1;
    க்கு (i = 1; (c = sec_cls[i]) < sec_last; ++i) {
        s = s1->sections[sec_order[i]];

        எனில் (PE_MERGE_DATA && c == sec_bss)
            c = sec_data;
        எனில் (c == sec_tbss)
            c = sec_tdata;

        எனில் (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } இல்லையெனில் {
            si = வெற்று;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        எனில் (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        எனில் (s == pe->reloc)
            pe_build_reloc (pe);

        எனில் (0 == s->data_offset)
            தொடர்;

        எனில் (si)
            செல் add_section;

        si = tcc_mallocz(அளவு *si);
        dynarray_add(&pe->sec_info, &pe->sec_மொத்தம், si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        எனில் (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_CODE;
        இல்லையெனில் எனில் (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_DATA;
        இல்லையெனில்
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_DATA;
        எனில் (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        எனில் (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

add_section:
        s->sh_info = pe->sec_மொத்தம்; /* section number for coff syms */
        addr += s->data_offset;
        si->sh_size = addr - si->sh_addr;
        எனில் (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            போது (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = வெற்று;
            si->data_size = si->sh_size;
        }

        எனில் (s->sh_flags & SHF_TLS) {
            strcpy(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#எனில் 0
    க்கு (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_order[i]];
        முழு type = s->sh_type;
        முழு flags = s->sh_flags;
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
    திரும்பு 0;
}

/*----------------------------------------------------------------------------*/
நிலையான முழு pe_check_symbols(கட்டமைப்பு pe_info *pe)
{
    முழு sym_index, sym_end;
    முழு ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(text_section, 8);

    sym_end = symtab_section->data_offset / அளவு(ElfW(Sym));
    க்கு (sym_index = 1; sym_index < sym_end; ++sym_index) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
        எனில் (sym->st_shndx == SHN_UNDEF) {
            மாறிலி எழுத்து *name = (எழுத்து*)symtab_section->link->data + sym->st_name;
            unsigned type = ELFW(ST_TYPE)(sym->st_info);
            முழு imp_sym = 0;
            கட்டமைப்பு import_குறியீடு *is;

            முழு _imp_, n;
            எழுத்து buffer[200];
            மாறிலி எழுத்து *s, *p;

            n = _imp_ = 0;
            எனில் (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            செய் {
                s = pe_export_name(s1, sym);
                எனில் (n) {
                    /* second try: */
                    எனில் (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        எனில் (!p || s[0] != '_')
                            நிறுத்து;
                        strcpy(buffer, s+1)[p-s-1] = 0, s = buffer;
                    } இல்லையெனில் எனில் (s[0] != '_') { /* try non-ansi function */
                        buffer[0] = '_', strcpy(buffer + 1, s), s = buffer;
                    } இல்லையெனில் எனில் (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } இல்லையெனில் எனில் (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } இல்லையெனில் {
                        நிறுத்து;
                    }
                }
                imp_sym = find_elf_sym(s1->dynsymtab_section, s);
            } போது (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            எனில் (0 == imp_sym)
                தொடர்; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_add_import(pe, imp_sym);

            எனில் (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                unsigned offset = is->thk_offset;
                எனில் (offset) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } இல்லையெனில் {
                    unsigned எழுத்து *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(buffer, "IAT.%s", name);
                    is->iat_index = put_elf_sym(
                        symtab_section, 0, அளவு(DWORD),
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
#அல்லதெனில் defined(TCC_TARGET_ARM64)
                    p = section_ptr_add(text_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, text_section,
                        offset + 16, R_XXX_THUNKFIX, is->iat_index);
#இல்லையெனில்
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
                sym->st_மதிப்பு = offset;
                sym->st_shndx = text_section->sh_இலக்கம்;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } இல்லையெனில் { /* STT_OBJECT */
                எனில் (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_மதிப்பு = is->iat_index; /* chain potential alias */
                is->iat_index = sym_index;
            }

        } இல்லையெனில் எனில் (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    திரும்பு ret;
}

/*----------------------------------------------------------------------------*/
#எனில் PE_PRINT_SECTIONS
நிலையான வெறுமை pe_print_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    முழு i, n, l, m;
    p = s->data;
    e = s->data + s->data_offset;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    எனில் (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    எனில் (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (unsigned)s->sh_addr);
    fprintf(f, "\ncontents %08X", (unsigned)l);
    fprintf(f, "\n\n");

    எனில் (s->sh_type == SHT_NOBITS)
        திரும்பு;

    எனில் (0 == l)
        திரும்பு;

    எனில் (s->sh_type == SHT_SYMTAB)
        m = அளவு(ElfW(Sym));
    இல்லையெனில் எனில் (s->sh_type == SHT_RELX)
        m = அளவு(ElfW_Rel);
    இல்லையெனில்
        m = 16;

    fprintf(f, "%-8s", "offset");
    க்கு (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    எனில் (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        மாறிலி எழுத்து *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            வெற்று
        };

        மாறிலி எழுத்து *fields2[] = {
            "offs",
            "type",
            "symb",
            வெற்று
        };

        மாறிலி எழுத்து **p;

        எனில் (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        இல்லையெனில்
            p = fields2, n = 58;

        க்கு (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    க்கு (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    க்கு (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        க்கு (n = 0; n < m; ++n) {
            எனில் (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            இல்லையெனில்
                fprintf(f, "   ");
        }

        எனில் (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            மாறிலி எழுத்து *name = s->link->data + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (unsigned)sym->st_name,
                    (unsigned)sym->st_மதிப்பு,
                    (unsigned)sym->st_size,
                    (unsigned)ELFW(ST_BIND)(sym->st_info),
                    (unsigned)ELFW(ST_TYPE)(sym->st_info),
                    (unsigned)sym->st_other,
                    (unsigned)sym->st_shndx,
                    name);

        } இல்லையெனில் எனில் (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->data + ELFW(R_SYM)(rel->r_info);
            மாறிலி எழுத்து *name = s->link->link->data + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (unsigned)rel->r_offset,
                    (unsigned)ELFW(R_TYPE)(rel->r_info),
                    (unsigned)ELFW(R_SYM)(rel->r_info),
                    name);
        } இல்லையெனில் {
            fprintf(f, "   ");
            க்கு (n = 0; n < m; ++n) {
                எனில் (n + i < l) {
                    b = p[i + n];
                    எனில் (b < 32 || b >= 127)
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

நிலையான வெறுமை pe_print_sections(TCCState *s1, மாறிலி எழுத்து *fname)
{
    Section *s;
    FILE *f;
    முழு i;
    f = fopen(fname, "w");
    க்கு (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    fclose(f);
}
#endif

/* ------------------------------------------------------------- */

ST_FUNC முழு pe_putimport(TCCState *s1, முழு dllindex, மாறிலி எழுத்து *name, addr_t மதிப்பு)
{
    திரும்பு set_elf_sym(
        s1->dynsymtab_section,
        மதிப்பு,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        மதிப்பு ? SHN_ABS : SHN_UNDEF,
        name
        );
}

நிலையான முழு read_mem(முழு fd, unsigned offset, வெறுமை *buffer, unsigned len)
{
    lseek(fd, offset, SEEK_SET);
    திரும்பு len == பட(fd, buffer, len);
}

/* ------------------------------------------------------------- */

நிலையான முழு get_dllexports(முழு fd, எழுத்து **pp)
{
    முழு i, k, l, n, n0, ret;
    எழுத்து *p;

    IMAGE_SECTION_HEADER ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_HEADER dh;
    IMAGE_FILE_HEADER ih;
    DWORD sig, ref, addr;
    DWORD *namep = வெற்று, p0 = 0, p1;

    முழு pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = வெற்று;
    ret = 1;
    எனில் (!read_mem(fd, 0, &dh, அளவு dh))
        செல் the_end;
    எனில் (!read_mem(fd, dh.e_lfanew, &sig, அளவு sig))
        செல் the_end;
    எனில் (sig != 0x00004550)
        செல் the_end;
    pef_hdroffset = dh.e_lfanew + அளவு sig;
    எனில் (!read_mem(fd, pef_hdroffset, &ih, அளவு ih))
        செல் the_end;
    opt_hdroffset = pef_hdroffset + அளவு ih;
    எனில் (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + அளவு oh;
        எனில் (!read_mem(fd, opt_hdroffset, &oh, அளவு oh))
            செல் the_end;
        எனில் (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.எண்_Of_Rva_And_Sizes)
            செல் the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } இல்லையெனில் எனில் (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + அளவு oh;
        எனில் (!read_mem(fd, opt_hdroffset, &oh, அளவு oh))
            செல் the_end;
        எனில் (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.எண்_Of_Rva_And_Sizes)
            செல் the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } இல்லையெனில்
        செல் the_end;

    //printf("addr: %08x\n", addr);
    க்கு (i = 0; i < ih.எண்_Of_Sections; ++i) {
        எனில் (!read_mem(fd, sec_hdroffset + i * அளவு ish, &ish, அளவு ish))
            செல் the_end;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        எனில் (addr >= ish.VirtualAddress && addr < ish.VirtualAddress + ish.SizeOfRawData)
            செல் found;
    }
    செல் the_end_0;
found:
    ref = ish.VirtualAddress - ish.PointerToRawData;
    எனில் (!read_mem(fd, addr - ref, &ied, அளவு ied))
        செல் the_end;
    k = ied.எண்_Of_Names;
    எனில் (k) {
        namep = tcc_malloc(l = k * அளவு *namep);
        எனில் (!read_mem(fd, ied.AddressOfNames - ref, namep, l))
            செல் the_end;
        க்கு (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            எனில் (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            செய் {
                எனில் (0 == l) {
                    எனில் (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    எனில் ((l = பட(fd, p + n, 1000 - 1)) <= 0)
                        செல் the_end;
                }
                --l, ++p0;
            } போது (p[n++]);
        }
        p[n] = 0;
    }
the_end_0:
    ret = 0;
the_end:
    tcc_free(namep);
    எனில் (ret && p)
        tcc_free(p), p = வெற்று;
    *pp = p;
    திரும்பு ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

நிலையான முழு pe_load_res(TCCState *s1, முழு fd)
{
    கட்டமைப்பு pe_rsrc_header hdr;
    Section *rsrc_section;
    முழு i, ret = -1, sym_index;
    BYTE *ptr;
    unsigned offs;

    எனில் (!read_mem(fd, 0, &hdr, அளவு hdr))
        செல் quit;

    எனில் (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.எண்_Of_Sections != 1
        || strcmp((எழுத்து*)hdr.sectionhdr.Name, ".rsrc") != 0)
        செல் quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_add(rsrc_section, hdr.sectionhdr.SizeOfRawData);
    offs = hdr.sectionhdr.PointerToRawData;
    எனில் (!read_mem(fd, offs, ptr, hdr.sectionhdr.SizeOfRawData))
        செல் quit;
    offs = hdr.sectionhdr.PointerToRelocations;
    sym_index = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_இலக்கம், ".rsrc");
    க்கு (i = 0; i < hdr.sectionhdr.எண்_Of_Relocations; ++i) {
        கட்டமைப்பு pe_rsrc_reloc rel;
        எனில் (!read_mem(fd, offs, &rel, அளவு rel))
            செல் quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        எனில் (rel.type != RSRC_RELTYPE)
            செல் quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.offset, R_XXX_RELATIVE, sym_index);
        offs += அளவு rel;
    }
    ret = 0;
quit:
    திரும்பு ret;
}

/* ------------------------------------------------------------- */

நிலையான எழுத்து *trimfront(எழுத்து *p)
{
    போது ((unsigned எழுத்து)*p <= ' ' && *p && *p != '\n')
	++p;
    திரும்பு p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

நிலையான எழுத்து *get_token(எழுத்து **s, எழுத்து *f)
{
    எழுத்து *p, *e;
    முழு q;

    p = trimfront(*s);
    q = *p;
    எனில் (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    இல்லையெனில்
        q = ' ';
    க்கு (e = p; (unsigned எழுத்து)*e >= ' ' && *e != q; ++e)
        ;
    எனில் (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    திரும்பு p;
}

நிலையான முழு pe_load_def(TCCState *s1, முழு fd)
{
    முழு state = 0, ret = -1, dllindex = 0, ord;
    எழுத்து dllname[80], *buf, *வரி, *p, *x, next;

    buf = tcc_load_text(fd);
    எனில் (!buf)
        திரும்பு ret;

    க்கு (வரி = buf;; ++வரி)  {
        p = get_token(&வரி, &next);
        எனில் (!(*p && *p != ';'))
            செல் skip;
        தேர்வு (state) {
        நிலை 0:
            எனில் (0 != stricmp(p, "LIBRARY") || next == '\n')
                செல் quit;
            pstrcpy(dllname, அளவு dllname, get_token(&வரி, &next));
            எனில் (!*tcc_fileextension(dllname))
                pstrcat(dllname, அளவு dllname, ".dll");
            ++state;
            நிறுத்து;
        நிலை 1:
            எனில் (0 != stricmp(p, "EXPORTS"))
                செல் quit;
            ++state;
            நிறுத்து;
        நிலை 2:
            dllindex = tcc_add_dllref(s1, dllname, 0)->index;
            ++state;
            /* fall through */
        இயல்பு:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            எனில் (next == '@') {
                x = get_token(&வரி, &next);
                ord = (முழு)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            நிறுத்து;
        }
skip:
        போது ((unsigned எழுத்து)next > ' ')
            get_token(&வரி, &next);
        எனில் (next != '\n')
            நிறுத்து;
    }
    ret = 0;
quit:
    tcc_free(buf);
    திரும்பு ret;
}

/* ------------------------------------------------------------- */

நிலையான முழு pe_load_dll(TCCState *s1, முழு fd, மாறிலி எழுத்து *filename)
{
    எழுத்து *p, *q;
    DLLReference *ref = tcc_add_dllref(s1, filename, 0);
    எனில் (ref->found)
        திரும்பு 0;
    எனில் (get_dllexports(fd, &p))
        திரும்பு -1;
    எனில் (p) {
        க்கு (q = p; *q; q += 1 + strlen(q))
            pe_putimport(s1, ref->index, q, 0);
        tcc_free(p);
    }
    திரும்பு 0;
}

ST_FUNC முழு pe_load_file(கட்டமைப்பு TCCState *s1, முழு fd, மாறிலி எழுத்து *filename)
{
    முழு ret = -1;
    எழுத்து buf[10];
    எனில் (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_load_def(s1, fd);
    இல்லையெனில் எனில் (pe_load_res(s1, fd) == 0)
        ret = 0;
    இல்லையெனில் எனில் (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_load_dll(s1, fd, filename);
    திரும்பு ret;
}

PUB_FUNC முழு tcc_get_dllexports(மாறிலி எழுத்து *filename, எழுத்து **pp)
{
    முழு ret, fd = open(filename, O_RDONLY | O_இருமம்_2);
    எனில் (fd < 0)
        திரும்பு -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    திரும்பு ret;
}

/* ------------------------------------------------------------- */
#ifdef TCC_TARGET_X86_64
நிலையான unsigned pe_add_unwind_info(TCCState *s1)
{
    எனில் (வெற்று == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    எனில் (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, text_section->sh_இலக்கம், ".uw_base");
    எனில் (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        நிலையான மாறிலி unsigned எழுத்து uw_info[] = {
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
        unsigned எழுத்து *p;

        section_ptr_add(s, -s->data_offset & 3); /* align */
        s1->uw_offs = s->data_offset;
        p = section_ptr_add(s, அளவு uw_info);
        memcpy(p, uw_info, அளவு uw_info);
    }

    திரும்பு s1->uw_offs;
}

ST_FUNC வெறுமை pe_add_unwind_data(unsigned start, unsigned end, unsigned அடுக்கு)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    unsigned o, n, d;
    கட்டமைப்பு /* _RUNTIME_FUNCTION */ {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD UnwindData;
    } *p;

    d = pe_add_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->data_offset;
    p = section_ptr_add(pd, அளவு *p);

    /* record this function */
    p->BeginAddress = start;
    p->EndAddress = end;
    p->UnwindData = d;

    /* put relocations on it */
    க்கு (n = o + அளவு *p; o < n; o += அளவு p->BeginAddress)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#அல்லதெனில் defined(TCC_TARGET_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
நிலையான Section *pe_add_unwind_info(TCCState *s1)
{
    Section *s;

    எனில் (வெற்று == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = find_section(s1, ".xdata");
    s->sh_addralign = 4;
    எனில் (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  text_section->sh_இலக்கம், ".uw_text_base");
    எனில் (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_இலக்கம், ".uw_base");
    திரும்பு s;
}

ST_FUNC வெறுமை pe_add_unwind_data(unsigned start, unsigned end, unsigned அடுக்கு)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    unsigned o, d, code_bytes, func_len;
    unsigned எழுத்து *q;
    uint32_t header;
    கட்டமைப்பு /* _RUNTIME_FUNCTION */ {
        DWORD BeginAddress;
        DWORD UnwindData;
    } *p;

    முழு epilog;

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
    போது ((unsigned)(q - (xd->data + d + 4)) < code_bytes)
        *q++ = 0xE3; /* nop padding */

    o = pd->data_offset;
    p = section_ptr_add(pd, அளவு *p);
    p->BeginAddress = start;
    p->UnwindData = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#endif
/* ------------------------------------------------------------- */
#எனில் defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
#define PE_STDSYM(n,s) n
#இல்லையெனில்
#define PE_STDSYM(n,s) "_" n s
#endif

நிலையான வெறுமை pe_add_runtime(TCCState *s1, கட்டமைப்பு pe_info *pe)
{
    மாறிலி எழுத்து *start_குறியீடு;
    முழு pe_type;

    எனில் (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        start_குறியீடு = PE_STDSYM("__dllstart","@12");
    } இல்லையெனில் {
        மாறிலி எழுத்து *run_குறியீடு;
        எனில் (find_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            start_குறியீடு = "__winstart";
            run_குறியீடு = "__runwinmain";
            pe_type = PE_GUI;
        } இல்லையெனில் எனில் (find_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            start_குறியீடு = "__wwinstart";
            run_குறியீடு = "__runwwinmain";
            pe_type = PE_GUI;
        } இல்லையெனில் எனில் (find_elf_sym(symtab_section, "wmain")) {
            start_குறியீடு = "__wstart";
            run_குறியீடு = "__runwmain";
            pe_type = PE_EXE;
        } இல்லையெனில் {
            start_குறியீடு =  "__start";
            run_குறியீடு = "__runmain";
            pe_type = PE_EXE;
            எனில் (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        எனில் (TCC_OUTPUT_MEMORY == s1->output_type && !s1->nostdlib)
            start_குறியீடு = run_குறியீடு;
    }
    எனில் (s1->elf_entryname) {
        pe->start_குறியீடு = start_குறியீடு = s1->elf_entryname;
    } இல்லையெனில் {
        pe->start_குறியீடு = start_குறியீடு + 1;
        எனில் (!s1->leading_underscore || strchr(start_குறியீடு, '@'))
            ++start_குறியீடு;
    }

#ifdef CONFIG_TCC_BACKTRACE
    எனில் (s1->do_backtrace) {
#ifdef CONFIG_TCC_BCHECK
        எனில் (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    எனில் (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    இல்லையெனில்
                tcc_add_support(s1, "bcheck.o");
	}
#endif
        எனில் (s1->output_type == TCC_OUTPUT_EXE)
            tcc_add_support(s1, "bt-exe.o");
        எனில் (s1->output_type == TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-dll.o");
        எனில் (s1->output_type != TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-log.o");
        tcc_add_btstub(s1);
    }
#endif

    /* grab the startup code from libtcc1.a */
#ifdef TCC_IS_NATIVE
    எனில் (TCC_OUTPUT_MEMORY != s1->output_type || s1->run_main)
#endif
    set_global_sym(s1, start_குறியீடு, வெற்று, 0);

    எனில் (0 == s1->nostdlib) {
        நிலையான மாறிலி எழுத்து * மாறிலி libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", வெற்று
        };
        மாறிலி எழுத்து * மாறிலி *pp, *p;
        எனில் (TCC_LIBTCC1[0])
            tcc_add_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        க்கு (pp = libs; 0 != (p = *pp); ++pp) {
            எனில் (*p)
                tcc_add_library(s1, p);
            இல்லையெனில் எனில் (PE_DLL != pe_type && PE_GUI != pe_type)
                நிறுத்து;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    எனில் (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    எனில் (TCC_OUTPUT_MEMORY == s1->output_type)
        pe_type = PE_RUN;
    pe->type = pe_type;
}

ST_FUNC முழு pe_setsubsy(TCCState *s1, மாறிலி எழுத்து *arg)
{
    நிலையான மாறிலி கட்டமைப்பு subsy { மாறிலி எழுத்து* p; முழு v; } x[] = {
#எனில் defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#அல்லதெனில் defined(TCC_TARGET_ARM)
        { "wince", 9 },
#endif
        { 0, -1 }};
    மாறிலி கட்டமைப்பு subsy *y;
    க்கு (y = x;; ++y) {
        எனில் (!y->p)
            திரும்பு -1;
        எனில் (0 == strcmp(y->p, arg)) {
            s1->pe_subsystem = y->v;
            திரும்பு 0;
        }
    }
}

நிலையான வெறுமை pe_set_options(TCCState * s1, கட்டமைப்பு pe_info *pe)
{
    எனில் (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_BASE_DLL;
    } இல்லையெனில் {
        pe->imagebase = IMAGE_BASE_EXE;
    }

#எனில் defined(TCC_TARGET_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#இல்லையெனில்
    எனில் (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    இல்லையெனில்
        pe->subsystem = 3;
#endif
    /* Allow override via -Wl,-subsystem=... option */
    எனில் (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    எனில் (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } இல்லையெனில் {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    எனில் (s1->section_align != 0)
        pe->section_align = s1->section_align;
    எனில் (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    எனில் ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    எனில் (s1->has_text_addr)
        pe->imagebase = s1->text_addr;
}

ST_FUNC முழு pe_output_file(TCCState *s1, மாறிலி எழுத்து *filename)
{
    கட்டமைப்பு pe_info pe;

    memset(&pe, 0, அளவு pe);
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
    எனில் (s1->nb_errors)
        செல் done;
    எனில் (filename) {
        pe_assign_addresses(&pe);
        relocate_syms(s1, s1->symtab, 0);
        எனில் (s1->nb_errors)
            செல் done;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.start_addr = (DWORD)
            (get_sym_addr(s1, pe.start_குறியீடு, 1, 1) - pe.imagebase);
        எனில் (s1->nb_errors)
            செல் done;
        pe_write(&pe);
    } இல்லையெனில் {
        /* -run */
#ifdef TCC_IS_NATIVE
        pe.thunk = data_section;
        pe_build_imports(&pe);
        s1->run_main = pe.start_குறியீடு;
#எனில் defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        s1->uw_pdata = find_section(s1, ".pdata");
#endif
#endif
    }
done:
    dynarray_reset(&pe.sec_info, &pe.sec_மொத்தம்);
    pe_free_imports(&pe);
#எனில் PE_PRINT_SECTIONS
    எனில் (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#endif
    திரும்பு s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
