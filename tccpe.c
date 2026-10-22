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

#അന്തര്ഭാവ "tcc.h"

#define PE_MERGE_DATA 1
#define PE_PRINT_SECTIONS 0

#ifndef _WIN32
#define stricmp strcasecmp
#define strnicmp strncasecmp
#അന്തര്ഭാവ <sys/stat.h> /* chmod() */
#endif

#എങ്കിൽ defined TCC_TARGET_X86_64
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

#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM
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

#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
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

#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_I386
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

#എങ്കിൽ PTR_SIZE == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#അല്ലെങ്കിൽ
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#endif

#ifndef IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

തരനിർവചനം unsigned അക്ഷരം BYTE;
തരനിർവചനം unsigned short WORD;
തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ DWORD;
തരനിർവചനം unsigned long long ULONGLONG;
#pragma pack(തള്ളുക, 1)

തരനിർവചനം ഘടന _IMAGE_DOS_HEADER {  /* DOS .EXE header */
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

തരനിർവചനം ഘടന _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    സംഖ്യ_Of_Sections;
    DWORD   TimeDateStamp;
    DWORD   Pointer_To_ചിഹ്നം_Table;
    DWORD   സംഖ്യ_Of_Symbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;


#define IMAGE_SIZEOF_FILE_HEADER 20

തരനിർവചനം ഘടന _IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;


തരനിർവചനം ഘടന _IMAGE_OPTIONAL_HEADER {
    /* Standard fields. */
    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
#എങ്കിൽ PTR_SIZE == 4
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
    DWORD   Win32_Version_മൂല്യം;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    ADDR3264 Size_Of_അട്ടി_Reserve;
    ADDR3264 Size_Of_അട്ടി_Commit;
    ADDR3264 SizeOfHeapReserve;
    ADDR3264 SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   സംഖ്യ_Of_Rva_And_Sizes;
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

തരനിർവചനം ഘടന _IMAGE_SECTION_HEADER {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    സംഘം {
            DWORD   PhysicalAddress;
            DWORD   VirtualSize;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   SizeOfRawData;
    DWORD   PointerToRawData;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    സംഖ്യ_Of_Relocations;
    WORD    സംഖ്യ_Of_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#define IMAGE_SIZEOF_SECTION_HEADER     40

തരനിർവചനം ഘടന _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD Name;
    DWORD Base;
    DWORD സംഖ്യ_Of_Functions;
    DWORD സംഖ്യ_Of_Names;
    DWORD AddressOfFunctions;
    DWORD AddressOfNames;
    DWORD AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

തരനിർവചനം ഘടന _IMAGE_TLS_DIRECTORY {
    ADDR3264 StartAddressOfRawData;
    ADDR3264 EndAddressOfRawData;
    ADDR3264 AddressOfIndex;
    ADDR3264 AddressOfCallBacks;
    DWORD SizeOfZeroFill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

തരനിർവചനം ഘടന _IMAGE_IMPORT_DESCRIPTOR {
    സംഘം {
        DWORD Characteristics;
        DWORD OriginalFirstThunk;
    };
    DWORD TimeDateStamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;

തരനിർവചനം ഘടന _IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   SizeOfBlock;
//  WORD    TypeOffset[1];
} IMAGE_BASE_RELOCATION;

#define IMAGE_SIZEOF_BASE_RELOCATION     8

#define IMAGE_REL_BASED_ABSOLUTE         0
#define IMAGE_REL_BASED_മുകളിലെ             1
#define IMAGE_REL_BASED_താഴെയുള്ള              2
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

#define IMAGE_DLLCHARACTERISTICS_മുകളിലെ_ENTROPY_VA 0x0020
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#define IMAGE_FILE_RELOCS_STRIPPED 0x0001

#pragma pack(എടുക്കുക)

/* ----------------------------------------------------------- */
#endif /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#ifndef IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#endif

#pragma pack(തള്ളുക, 1)
ഘടന pe_header
{
    IMAGE_DOS_HEADER doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_HEADER filehdr;
#എങ്കിൽ PTR_SIZE == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#അല്ലെങ്കിൽ
#ifdef _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#അല്ലെങ്കിൽ
    IMAGE_OPTIONAL_HEADER opthdr;
#endif
#endif
};

ഘടന pe_reloc_header {
    DWORD offset;
    DWORD size;
};

ഘടന pe_rsrc_header {
    ഘടന _IMAGE_FILE_HEADER filehdr;
    ഘടന _IMAGE_SECTION_HEADER sectionhdr;
};

ഘടന pe_rsrc_reloc {
    DWORD offset;
    DWORD size;
    WORD type;
};
#pragma pack(എടുക്കുക)

/* ------------------------------------------------------------- */
/* internal temporary structures */

എണ്ണൽ {
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

#എങ്കിൽ 0
സ്ഥിതം സ്ഥിരം DWORD pe_sec_flags[] = {
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

ഘടന section_info {
    പൂർണ്ണസംഖ്യ cls;
    അക്ഷരം name[32];
    ADDR3264 sh_addr;
    DWORD sh_size;
    DWORD pe_flags;
    Section *sec;
    DWORD data_size;
    IMAGE_SECTION_HEADER ish;
};

ഘടന import_ചിഹ്നം {
    പൂർണ്ണസംഖ്യ sym_index;
    പൂർണ്ണസംഖ്യ iat_index;
    പൂർണ്ണസംഖ്യ thk_offset;
};

ഘടന pe_import_info {
    പൂർണ്ണസംഖ്യ dll_index;
    പൂർണ്ണസംഖ്യ sym_എണ്ണം;
    ഘടന import_ചിഹ്നം **symbols;
};

ഘടന pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    സ്ഥിരം അക്ഷരം *filename;
    പൂർണ്ണസംഖ്യ type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    സ്ഥിരം അക്ഷരം *start_ചിഹ്നം;
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
    പൂർണ്ണസംഖ്യ subsystem;
    DWORD section_align;
    DWORD file_align;
    ഘടന section_info **sec_info;
    പൂർണ്ണസംഖ്യ sec_എണ്ണം;
    ഘടന pe_import_info **imp_info;
    പൂർണ്ണസംഖ്യ imp_എണ്ണം;
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

സ്ഥിതം സ്ഥിരം അക്ഷരം *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    സ്ഥിരം അക്ഷരം *name = (അക്ഷരം*)symtab_section->link->data + sym->st_name;
    എങ്കിൽ (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        തിരികെ name + 1;
    തിരികെ name;
}


സ്ഥിതം പൂർണ്ണസംഖ്യ dynarray_assoc(ശൂന്യം **pp, പൂർണ്ണസംഖ്യ n, പൂർണ്ണസംഖ്യ താക്കോൽ)
{
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി (i = 0; i < n; ++i, ++pp)
    എങ്കിൽ (താക്കോൽ == **(പൂർണ്ണസംഖ്യ **) pp)
        തിരികെ i;
    തിരികെ -1;
}

സ്ഥിതം DWORD umin(DWORD a, DWORD b)
{
    തിരികെ a < b ? a : b;
}

സ്ഥിതം DWORD umax(DWORD a, DWORD b)
{
    തിരികെ a < b ? b : a;
}

സ്ഥിതം DWORD pe_file_align(ഘടന pe_info *pe, DWORD n)
{
    തിരികെ (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

സ്ഥിതം ADDR3264 pe_virtual_align(ഘടന pe_info *pe, ADDR3264 n)
{
    തിരികെ (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

സ്ഥിതം ശൂന്യം pe_align_section(Section *s, പൂർണ്ണസംഖ്യ a)
{
    പൂർണ്ണസംഖ്യ i = s->data_offset & (a-1);
    എങ്കിൽ (i)
        section_ptr_add(s, a - i);
}

സ്ഥിതം ശൂന്യം pe_set_datadir(ഘടന pe_header *hdr, പൂർണ്ണസംഖ്യ dir, DWORD addr, DWORD size)
{
    hdr->opthdr.DataDirectory[dir].VirtualAddress = addr;
    hdr->opthdr.DataDirectory[dir].Size = size;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ pe_fwrite(ഘടന pe_info *pe, സ്ഥിരം ശൂന്യം *data, പൂർണ്ണസംഖ്യ len)
{
    സ്ഥിരം WORD *p = data;
    DWORD sum;
    പൂർണ്ണസംഖ്യ ret, i;
    pe->pos += (ret = fwrite(data, 1, len, pe->op));
    sum = pe->sum;
    വേണ്ടി (i = len; i > 0; i -= 2) {
        sum += (i >= 2) ? *p++ : *(BYTE*)p;
        sum = (sum + (sum >> 16)) & 0xFFFF;
    }
    pe->sum = sum;
    തിരികെ len == ret ? 0 : -1;
}

സ്ഥിതം ശൂന്യം pe_fpad(ഘടന pe_info *pe, DWORD new_pos)
{
    അക്ഷരം buf[256];
    പൂർണ്ണസംഖ്യ n, diff = new_pos - pe->pos;
    memset(buf, 0, വലുപ്പം buf);
    ആകുമ്പോൾ (diff > 0) {
        diff -= n = umin(diff, വലുപ്പം buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#pragma pack(തള്ളുക, 1)
ഘടന syment
{
    സംഘം {
        അക്ഷരം        n_name[8];     /* old COFF version */
        ഘടന {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_offset;      /* offset into string table */
        };
    };
    int32_t         n_മൂല്യം;        /* value of symbol */
    short           n_scnum;        /* section number */
    unsigned short  n_type;         /* type and derived type */
    അക്ഷരം            n_sclass;       /* storage class */
    അക്ഷരം            n_numaux;       /* number of aux. entries */
};
#pragma pack(എടുക്കുക)

#define SHF_PRIVATE 0x80000000

സ്ഥിതം ശൂന്യം pe_add_coffsym(ഘടന pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    ഘടന syment *se;
    പൂർണ്ണസംഖ്യ n;

    എങ്കിൽ (ശൂന്യ == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_PRIVATE);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_PRIVATE);
        section_ptr_add(pe->coffstr, 4); /* coff string table size */
        തിരികെ;
    }

#എങ്കിൽ 0
    se = section_ptr_add(pe->coffsym, വലുപ്പം *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_add(pe->coffsym, വലുപ്പം *se);
    strcpy((അക്ഷരം*)se, "no-file");
#endif

#എങ്കിൽ 1
    esym = (ElfSym*)s1->symtab->data;
    വേണ്ടി (n = s1->symtab->data_offset / വലുപ്പം *esym; ++esym, --n;) {
        പൂർണ്ണസംഖ്യ sym_bind = ELFW(ST_BIND)(esym->st_info);
        എങ്കിൽ (sym_bind == STB_GLOBAL) {
            അക്ഷരം *name = esym->st_name + (അക്ഷരം*)s1->symtab->link->data;
            പൂർണ്ണസംഖ്യ nl = strlen(name);
            addr_t മൂല്യം = esym->st_മൂല്യം;
            പൂർണ്ണസംഖ്യ shnum = esym->st_shndx;
            എങ്കിൽ (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                മൂല്യം = മൂല്യം - s->sh_addr;
            }
            se = section_ptr_add(pe->coffsym, വലുപ്പം *se);
            se->n_മൂല്യം = മൂല്യം;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            എങ്കിൽ (nl <= 8)
                memcpy(se->n_name, name, nl);
            അല്ലെങ്കിൽ
                se->n_offset = put_elf_str(pe->coffstr, name);
        }
    }
#endif
    write32le(pe->coffstr->data, pe->coffstr->data_offset); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
സ്ഥിതം ശൂന്യം pe_create_pdb(TCCState *s1, സ്ഥിരം അക്ഷരം *exename)
{
    അക്ഷരം buf[300]; പൂർണ്ണസംഖ്യ r;
    snprintf(buf, വലുപ്പം buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    strcpy(tcc_fileextension(strcpy(buf, exename)), ".pdb");
    എങ്കിൽ (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } അല്ലെങ്കിൽ എങ്കിൽ (s1->verbose) {
        printf("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
സ്ഥിതം പൂർണ്ണസംഖ്യ pe_write(ഘടന pe_info *pe)
{
    സ്ഥിതം സ്ഥിരം ഘടന pe_header pe_template = {
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
#എങ്കിൽ PTR_SIZE == 4
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

    ഘടന pe_header pe_header = pe_template;

    പൂർണ്ണസംഖ്യ i;
    DWORD file_offset;
    ഘടന section_info *si;
    IMAGE_SECTION_HEADER *psh;
    TCCState *s1 = pe->s1;

    എങ്കിൽ (s1->do_debug)
        pe_add_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    എങ്കിൽ (ശൂന്യ == pe->op)
        തിരികെ tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        വലുപ്പം (ഘടന pe_header)
        + pe->sec_എണ്ണം * വലുപ്പം (IMAGE_SECTION_HEADER)
        );

    file_offset = pe->sizeofheaders;

    എങ്കിൽ (2 == s1->verbose)
        printf("-------------------------------"
               "\n  virt   file   size  section" "\n");
    വേണ്ടി (i = 0; i < pe->sec_എണ്ണം; ++i) {
        DWORD addr, size;
        സ്ഥിരം അക്ഷരം *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        size = si->sh_size;
        psh = &si->ish;

        എങ്കിൽ (2 == s1->verbose)
            printf("%6x %6x %6x  %s\n",
                (unsigned)addr, (unsigned)file_offset, (unsigned)size, sh_name);

        തിരഞ്ഞെടുപ്പ് (si->cls) {
            അവസ്ഥ sec_text:
                എങ്കിൽ (!pe_header.opthdr.BaseOfCode)
                    pe_header.opthdr.BaseOfCode = addr;
                നിർത്തുക;

            അവസ്ഥ sec_data:
#എങ്കിൽ PTR_SIZE == 4
                എങ്കിൽ (!pe_header.opthdr.BaseOfData)
                    pe_header.opthdr.BaseOfData = addr;
#endif
                നിർത്തുക;

            അവസ്ഥ sec_bss:
                നിർത്തുക;

            അവസ്ഥ sec_reloc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_BASERELOC, addr, size);
                നിർത്തുക;

            അവസ്ഥ sec_rsrc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_RESOURCE, addr, size);
                നിർത്തുക;

            അവസ്ഥ sec_pdata:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXCEPTION, addr, size);
                നിർത്തുക;
        }

        എങ്കിൽ (pe->imp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IMPORT,
                pe->imp_offs, pe->imp_size);
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IAT,
                pe->iat_offs, pe->iat_size);
        }
        എങ്കിൽ (pe->exp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXPORT,
                pe->exp_offs, pe->exp_size);
        }
        എങ്കിൽ (pe->tls_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_size);
        }

        memcpy(psh->Name, sh_name, umin(strlen(sh_name), വലുപ്പം psh->Name));
        എങ്കിൽ (pe->coffstr && strlen(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((അക്ഷരം*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->VirtualAddress = addr;
        psh->Misc.VirtualSize = size;
        pe_header.opthdr.SizeOfImage =
            umax(pe_virtual_align(pe, size + addr), pe_header.opthdr.SizeOfImage);

        എങ്കിൽ (si->data_size) {
            psh->PointerToRawData = file_offset;
            file_offset = pe_file_align(pe, file_offset + si->data_size);
            psh->SizeOfRawData = file_offset - psh->PointerToRawData;
            എങ്കിൽ (si->cls == sec_text)
                pe_header.opthdr.SizeOfCode += psh->SizeOfRawData;
            അല്ലെങ്കിൽ
                pe_header.opthdr.SizeOfInitializedData += psh->SizeOfRawData;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_header.filehdr.സംഖ്യ_Of_Sections = pe->sec_എണ്ണം;
    pe_header.opthdr.AddressOfEntryPoint = pe->start_addr;
    pe_header.opthdr.SizeOfHeaders = pe->sizeofheaders;
    pe_header.opthdr.ImageBase = pe->imagebase;
    pe_header.opthdr.Subsystem = pe->subsystem;
    pe_header.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    എങ്കിൽ (s1->pe_അട്ടി_size)
        pe_header.opthdr.Size_Of_അട്ടി_Reserve = s1->pe_അട്ടി_size;
    എങ്കിൽ (PE_DLL == pe->type)
        pe_header.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_header.filehdr.Characteristics |= s1->pe_characteristics;
    എങ്കിൽ (pe->reloc)
        pe_header.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    എങ്കിൽ (pe->coffsym) {
        pe_add_coffsym(pe);
        pe_header.filehdr.Pointer_To_ചിഹ്നം_Table = file_offset;
        pe_header.filehdr.സംഖ്യ_Of_Symbols
            = pe->coffsym->data_offset / വലുപ്പം (ഘടന syment);
    }

    pe_fwrite(pe, &pe_header, വലുപ്പം pe_header);
    വേണ്ടി (i = 0; i < pe->sec_എണ്ണം; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, വലുപ്പം(IMAGE_SECTION_HEADER));

    file_offset = pe->sizeofheaders;
    വേണ്ടി (i = 0; i < pe->sec_എണ്ണം; ++i) {
        Section *s;
        si = pe->sec_info[i];
        എങ്കിൽ (!si->data_size)
            തുടരുക;
        വേണ്ടി (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_offset);
            pe_fwrite(pe, s->data, s->data_offset);
            എങ്കിൽ (s->prev)
                file_offset += s->prev->sh_addr - s->sh_addr;
        }
        file_offset = si->ish.PointerToRawData + si->ish.SizeOfRawData;
        pe_fpad(pe, file_offset);
    }

    എങ്കിൽ (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->data, pe->coffsym->data_offset);
        pe_fwrite(pe, pe->coffstr->data, pe->coffstr->data_offset);
        file_offset = pe->pos;
    }

    pe->sum += file_offset;
    fseek(pe->op, offsetof(ഘടന pe_header, opthdr.CheckSum), SEEK_SET);
    pe_fwrite(pe, &pe->sum, വലുപ്പം (DWORD));

    fclose (pe->op);
#ifndef _WIN32
    chmod(pe->filename, 0777);
#endif

    എങ്കിൽ (2 == s1->verbose)
        printf("-------------------------------\n");
    എങ്കിൽ (s1->verbose)
        printf("<- %s (%u bytes)\n", pe->filename, (unsigned)file_offset);

    എങ്കിൽ (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    തിരികെ 0;
}

/*----------------------------------------------------------------------------*/

സ്ഥിതം ഘടന import_ചിഹ്നം *pe_add_import(ഘടന pe_info *pe, പൂർണ്ണസംഖ്യ sym_index)
{
    പൂർണ്ണസംഖ്യ i;
    പൂർണ്ണസംഖ്യ dll_index;
    ഘടന pe_import_info *p;
    ഘടന import_ചിഹ്നം *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->data + sym_index;
    dll_index = isym->st_size;

    i = dynarray_assoc ((ശൂന്യം**)pe->imp_info, pe->imp_എണ്ണം, dll_index);
    എങ്കിൽ (-1 != i) {
        p = pe->imp_info[i];
        പോകുക found_dll;
    }
    p = tcc_mallocz(വലുപ്പം *p);
    p->dll_index = dll_index;
    dynarray_add(&pe->imp_info, &pe->imp_എണ്ണം, p);

found_dll:
    i = dynarray_assoc ((ശൂന്യം**)p->symbols, p->sym_എണ്ണം, sym_index);
    എങ്കിൽ (-1 != i)
        തിരികെ p->symbols[i];

    s = tcc_mallocz(വലുപ്പം *s);
    dynarray_add(&p->symbols, &p->sym_എണ്ണം, s);
    s->sym_index = sym_index;
    തിരികെ s;
}

സ്ഥിതം ശൂന്യം pe_free_imports(ഘടന pe_info *pe)
{
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി (i = 0; i < pe->imp_എണ്ണം; ++i) {
        ഘടന pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_എണ്ണം);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_എണ്ണം);
}

/*----------------------------------------------------------------------------*/
സ്ഥിതം ശൂന്യം pe_build_imports(ഘടന pe_info *pe)
{
    പൂർണ്ണസംഖ്യ thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_base = pe->thunk->sh_addr - pe->imagebase;
    പൂർണ്ണസംഖ്യ ndlls = pe->imp_എണ്ണം;
    TCCState *s1 = pe->s1;

    വേണ്ടി (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_എണ്ണം;

    എങ്കിൽ (0 == sym_cnt)
        തിരികെ;

    pe_align_section(pe->thunk, 16);
    pe->imp_size = (ndlls + 1) * വലുപ്പം(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_size = (sym_cnt + ndlls) * വലുപ്പം(ADDR3264);
    dll_ptr = pe->thunk->data_offset;
    thk_ptr = dll_ptr + pe->imp_size;
    ent_ptr = thk_ptr + pe->iat_size;
    pe->imp_offs = dll_ptr + rva_base;
    pe->iat_offs = thk_ptr + rva_base;
    section_ptr_add(pe->thunk, pe->imp_size + 2*pe->iat_size);

    വേണ്ടി (i = 0; i < pe->imp_എണ്ണം; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        പൂർണ്ണസംഖ്യ k, n, dllindex;
        ADDR3264 v;
        ഘടന pe_import_info *p = pe->imp_info[i];
        സ്ഥിരം അക്ഷരം *name;
        DLLReference *dllref;

        dllindex = p->dll_index;
        എങ്കിൽ (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        അല്ലെങ്കിൽ
            name = "", dllref = ശൂന്യ;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->data + dll_ptr);
        hdr->FirstThunk = thk_ptr + rva_base;
        hdr->OriginalFirstThunk = ent_ptr + rva_base;
        hdr->Name = v + rva_base;

        വേണ്ടി (k = 0, n = p->sym_എണ്ണം; k <= n; ++k) {
            എങ്കിൽ (k < n) {
                പൂർണ്ണസംഖ്യ iat_index = p->symbols[k]->iat_index;
                പൂർണ്ണസംഖ്യ sym_index = p->symbols[k]->sym_index;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->data + sym_index;
                സ്ഥിരം അക്ഷരം *name = (അക്ഷരം*)s1->dynsymtab_section->link->data + imp_sym->st_name;
                പൂർണ്ണസംഖ്യ ordinal;

                /* patch symbol (and possibly its underscored alias) */
                ചെയ്യുക {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->data + iat_index;
                    iat_index = esym->st_മൂല്യം;
                    esym->st_മൂല്യം = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_അക്കം;
                } ആകുമ്പോൾ (iat_index);

                എങ്കിൽ (dllref)
                    v = 0, ordinal = imp_sym->st_മൂല്യം; /* ordinal from pe_load_def */
                അല്ലെങ്കിൽ
                    ordinal = 0, v = imp_sym->st_മൂല്യം; /* address from tcc_add_symbol() */

#ifdef TCC_IS_NATIVE
                എങ്കിൽ (pe->type == PE_RUN) {
                    എങ്കിൽ (dllref) {
                        എങ്കിൽ ( !dllref->handle )
                            dllref->handle = LoadLibraryA(dllref->name);
                        v = (ADDR3264)GetProcAddress(dllref->handle, ordinal?(അക്ഷരം*)0+ordinal:name);
                    }
                    എങ്കിൽ (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } അല്ലെങ്കിൽ
#endif
                എങ്കിൽ (ordinal) {
                    v = ordinal | (ADDR3264)1 << (വലുപ്പം(ADDR3264)*8 - 1);
                } അല്ലെങ്കിൽ {
                    v = pe->thunk->data_offset + rva_base;
                    section_ptr_add(pe->thunk, വലുപ്പം(WORD)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } അല്ലെങ്കിൽ {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->data+thk_ptr) =
            *(ADDR3264*)(pe->thunk->data+ent_ptr) = v;
            thk_ptr += വലുപ്പം (ADDR3264);
            ent_ptr += വലുപ്പം (ADDR3264);
        }
        dll_ptr += വലുപ്പം(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

ഘടന pe_sort_sym
{
    പൂർണ്ണസംഖ്യ index;
    സ്ഥിരം അക്ഷരം *name;
};

സ്ഥിതം പൂർണ്ണസംഖ്യ sym_cmp(സ്ഥിരം ശൂന്യം *va, സ്ഥിരം ശൂന്യം *vb)
{
    സ്ഥിരം അക്ഷരം *ca = (*(ഘടന pe_sort_sym**)va)->name;
    സ്ഥിരം അക്ഷരം *cb = (*(ഘടന pe_sort_sym**)vb)->name;
    തിരികെ strcmp(ca, cb);
}

സ്ഥിതം ശൂന്യം pe_build_exports(ഘടന pe_info *pe)
{
    ElfW(Sym) *sym;
    പൂർണ്ണസംഖ്യ sym_index, sym_end;
    DWORD rva_base, base_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    പൂർണ്ണസംഖ്യ sym_എണ്ണം, ord;
    ഘടന pe_sort_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    അക്ഷരം buf[260];
    സ്ഥിരം അക്ഷരം *dllname;
    സ്ഥിരം അക്ഷരം *name;

    rva_base = pe->thunk->sh_addr - pe->imagebase;
    sym_എണ്ണം = 0, sorted = ശൂന്യ, op = ശൂന്യ;

    sym_end = symtab_section->data_offset / വലുപ്പം(ElfW(Sym));
    വേണ്ടി (sym_index = 1; sym_index < sym_end; ++sym_index) {
        sym = (ElfW(Sym)*)symtab_section->data + sym_index;
        name = pe_export_name(s1, sym);
        എങ്കിൽ (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(വലുപ്പം *p);
            p->index = sym_index;
            p->name = name;
            dynarray_add(&sorted, &sym_എണ്ണം, p);
        }
#എങ്കിൽ 0
        എങ്കിൽ (sym->st_other & ST_PE_EXPORT)
            printf("export: %s\n", name);
        എങ്കിൽ (sym->st_other & ST_PE_STDCALL)
            printf("stdcall: %s\n", name);
#endif
    }

    എങ്കിൽ (0 == sym_എണ്ണം)
        തിരികെ;

    qsort (sorted, sym_എണ്ണം, വലുപ്പം *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    base_o = pe->thunk->data_offset;
    func_o = base_o + വലുപ്പം(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_എണ്ണം * വലുപ്പം (DWORD);
    ord_o = name_o + sym_എണ്ണം * വലുപ്പം (DWORD);
    str_o = ord_o + sym_എണ്ണം * വലുപ്പം(WORD);

    hdr = section_ptr_add(pe->thunk, str_o - base_o);
    hdr->Characteristics        = 0;
    hdr->Base                   = 1;
    hdr->സംഖ്യ_Of_Functions      = sym_എണ്ണം;
    hdr->സംഖ്യ_Of_Names          = sym_എണ്ണം;
    hdr->AddressOfFunctions     = func_o + rva_base;
    hdr->AddressOfNames         = name_o + rva_base;
    hdr->AddressOfNameOrdinals  = ord_o + rva_base;
    hdr->Name                   = str_o + rva_base;
    put_elf_str(pe->thunk, dllname);

#എങ്കിൽ 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, വലുപ്പം buf, pe->filename);
    strcpy(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    എങ്കിൽ (ശൂന്യ == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } അല്ലെങ്കിൽ {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        എങ്കിൽ (s1->verbose)
            printf("<- %s (%d symbol%s)\n", buf, sym_എണ്ണം, &"s"[sym_എണ്ണം < 2]);
    }
#endif

    വേണ്ടി (ord = 0; ord < sym_എണ്ണം; ++ord)
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
        func_o += വലുപ്പം (DWORD);
        name_o += വലുപ്പം (DWORD);
        ord_o += വലുപ്പം (WORD);
        എങ്കിൽ (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = base_o + rva_base;
    pe->exp_size = pe->thunk->data_offset - base_o;
    dynarray_reset(&sorted, &sym_എണ്ണം);
    എങ്കിൽ (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
സ്ഥിതം ശൂന്യം pe_build_reloc (ഘടന pe_info *pe)
{
    DWORD offset, block_ptr, sh_addr, addr;
    പൂർണ്ണസംഖ്യ എണ്ണം_2, i;
    ElfW_Rel *rel, *rel_end;
    Section *s = ശൂന്യ, *sr;
    ഘടന pe_reloc_header *hdr;
    TCCState *s1 = pe->s1;
    പൂർണ്ണസംഖ്യ dwarf = 0, n;

    sh_addr = offset = block_ptr = എണ്ണം_2 = i = 0;
    rel = rel_end = ശൂന്യ;

    വേണ്ടി(;;) {
        എങ്കിൽ (rel < rel_end) {
            പൂർണ്ണസംഖ്യ type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_offset + sh_addr;
            ++ rel;
            എങ്കിൽ (type != REL_TYPE_DIRECT)
                തുടരുക;
            എങ്കിൽ (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->data + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                എങ്കിൽ (n >= s1->dwlo && n < s1->dwhi)
                    തുടരുക;
            }
            എങ്കിൽ (എണ്ണം_2 == 0) { /* new block */
                block_ptr = pe->reloc->data_offset;
                section_ptr_add(pe->reloc, വലുപ്പം(ഘടന pe_reloc_header));
                offset = addr & 0xFFFFFFFF<<12;
            }
            എങ്കിൽ ((addr -= offset)  < (1<<12)) { /* one block spans 4k addresses */
                WORD *wp = section_ptr_add(pe->reloc, വലുപ്പം (WORD));
                *wp = addr | PE_IMAGE_REL<<12;
                ++എണ്ണം_2;
                തുടരുക;
            }
            -- rel;

        } അല്ലെങ്കിൽ എങ്കിൽ (s) {
            sr = s->reloc;
            എങ്കിൽ (sr) {
                rel = (ElfW_Rel *)sr->data;
                rel_end = (ElfW_Rel *)(sr->data + sr->data_offset);
                sh_addr = s->sh_addr;
                dwarf = s->sh_അക്കം >= s1->dwlo && s->sh_അക്കം < s1->dwhi;
            }
            s = s->prev;
            തുടരുക;

        } അല്ലെങ്കിൽ എങ്കിൽ (i < pe->sec_എണ്ണം) {
            s = pe->sec_info[i]->sec, ++i;
            തുടരുക;

        } അല്ലെങ്കിൽ എങ്കിൽ (!എണ്ണം_2)
            നിർത്തുക;

        /* fill the last block and ready for a new one */
        എങ്കിൽ (എണ്ണം_2 & 1) /* align for DWORDS */
            section_ptr_add(pe->reloc, വലുപ്പം(WORD)), ++എണ്ണം_2;
        hdr = (ഘടന pe_reloc_header *)(pe->reloc->data + block_ptr);
        hdr -> offset = offset - pe->imagebase;
        hdr -> size = എണ്ണം_2 * വലുപ്പം(WORD) + വലുപ്പം(ഘടന pe_reloc_header);
        എണ്ണം_2 = 0;
    }
}

/* ------------------------------------------------------------- */
സ്ഥിതം ശൂന്യം pe_build_tls(ഘടന pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    പൂർണ്ണസംഖ്യ c, n;

    എങ്കിൽ (0 == s) {
        pe->tls_size = വലുപ്പം (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_add(pe->thunk, pe->tls_size, 16);
        pe->tls_data = section_add(data_section, PTR_SIZE * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, data_section->sh_അക്കം, 0);
        വേണ്ടി (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_SIZE*n, REL_TYPE_DIRECT, c);
        /* for generators */
        set_elf_sym(symtab_section, pe->tls_data, PTR_SIZE * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, data_section->sh_അക്കം, "__tls_index");
        തിരികെ;
    }

    എങ്കിൽ (0 == s1->tls_start)
        s1->tls_start = s->sh_addr;
    d = (ശൂന്യം*)(pe->thunk->data + pe->tls_dir);
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
സ്ഥിതം പൂർണ്ണസംഖ്യ pe_section_class(Section *s)
{
    പൂർണ്ണസംഖ്യ type, flags;
    സ്ഥിരം അക്ഷരം *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    എങ്കിൽ (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        തിരികെ sec_debug;
    } അല്ലെങ്കിൽ എങ്കിൽ (flags & SHF_ALLOC) {
        എങ്കിൽ (flags & SHF_TLS)
            തിരികെ sec_tdata + (type == SHT_NOBITS);
        എങ്കിൽ (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            എങ്കിൽ (flags & SHF_EXECINSTR)
                തിരികെ sec_text;
            എങ്കിൽ (flags & SHF_WRITE)
                തിരികെ sec_data;
            എങ്കിൽ (0 == strcmp(name, ".rsrc"))
                തിരികെ sec_rsrc;
            എങ്കിൽ (0 == strcmp(name, ".iedat"))
                തിരികെ sec_idata;
            എങ്കിൽ (0 == strcmp(name, ".pdata"))
                തിരികെ sec_pdata;
            തിരികെ sec_rdata;
        } അല്ലെങ്കിൽ എങ്കിൽ (type == SHT_NOBITS) {
            തിരികെ sec_bss;
        }
        തിരികെ sec_other;
    } അല്ലെങ്കിൽ {
        എങ്കിൽ (0 == strcmp(name, ".reloc"))
            തിരികെ sec_reloc;
    }
    തിരികെ sec_last;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ pe_assign_addresses (ഘടന pe_info *pe)
{
    പൂർണ്ണസംഖ്യ i, k, n, c, nbs;
    ADDR3264 addr;
    പൂർണ്ണസംഖ്യ *sec_order, *sec_cls;
    ഘടന section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    എങ്കിൽ (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_order = tcc_mallocz(2 * വലുപ്പം (പൂർണ്ണസംഖ്യ) * nbs);
    sec_cls = sec_order + nbs;
    വേണ്ടി (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        വേണ്ടി (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
        എങ്കിൽ ((s->sh_flags & SHF_TLS) && 0 == pe->tls_size)
            pe_build_tls(pe, ശൂന്യ);
    }
    si = ശൂന്യ;
    addr = pe->imagebase + 1;
    വേണ്ടി (i = 1; (c = sec_cls[i]) < sec_last; ++i) {
        s = s1->sections[sec_order[i]];

        എങ്കിൽ (PE_MERGE_DATA && c == sec_bss)
            c = sec_data;
        എങ്കിൽ (c == sec_tbss)
            c = sec_tdata;

        എങ്കിൽ (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } അല്ലെങ്കിൽ {
            si = ശൂന്യ;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        എങ്കിൽ (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        എങ്കിൽ (s == pe->reloc)
            pe_build_reloc (pe);

        എങ്കിൽ (0 == s->data_offset)
            തുടരുക;

        എങ്കിൽ (si)
            പോകുക add_section;

        si = tcc_mallocz(വലുപ്പം *si);
        dynarray_add(&pe->sec_info, &pe->sec_എണ്ണം, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        എങ്കിൽ (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_CODE;
        അല്ലെങ്കിൽ എങ്കിൽ (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_DATA;
        അല്ലെങ്കിൽ
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_DATA;
        എങ്കിൽ (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        എങ്കിൽ (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

add_section:
        s->sh_info = pe->sec_എണ്ണം; /* section number for coff syms */
        addr += s->data_offset;
        si->sh_size = addr - si->sh_addr;
        എങ്കിൽ (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            ആകുമ്പോൾ (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = ശൂന്യ;
            si->data_size = si->sh_size;
        }

        എങ്കിൽ (s->sh_flags & SHF_TLS) {
            strcpy(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#എങ്കിൽ 0
    വേണ്ടി (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_order[i]];
        പൂർണ്ണസംഖ്യ type = s->sh_type;
        പൂർണ്ണസംഖ്യ flags = s->sh_flags;
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
    തിരികെ 0;
}

/*----------------------------------------------------------------------------*/
സ്ഥിതം പൂർണ്ണസംഖ്യ pe_check_symbols(ഘടന pe_info *pe)
{
    പൂർണ്ണസംഖ്യ sym_index, sym_end;
    പൂർണ്ണസംഖ്യ ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(text_section, 8);

    sym_end = symtab_section->data_offset / വലുപ്പം(ElfW(Sym));
    വേണ്ടി (sym_index = 1; sym_index < sym_end; ++sym_index) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
        എങ്കിൽ (sym->st_shndx == SHN_UNDEF) {
            സ്ഥിരം അക്ഷരം *name = (അക്ഷരം*)symtab_section->link->data + sym->st_name;
            unsigned type = ELFW(ST_TYPE)(sym->st_info);
            പൂർണ്ണസംഖ്യ imp_sym = 0;
            ഘടന import_ചിഹ്നം *is;

            പൂർണ്ണസംഖ്യ _imp_, n;
            അക്ഷരം buffer[200];
            സ്ഥിരം അക്ഷരം *s, *p;

            n = _imp_ = 0;
            എങ്കിൽ (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            ചെയ്യുക {
                s = pe_export_name(s1, sym);
                എങ്കിൽ (n) {
                    /* second try: */
                    എങ്കിൽ (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        എങ്കിൽ (!p || s[0] != '_')
                            നിർത്തുക;
                        strcpy(buffer, s+1)[p-s-1] = 0, s = buffer;
                    } അല്ലെങ്കിൽ എങ്കിൽ (s[0] != '_') { /* try non-ansi function */
                        buffer[0] = '_', strcpy(buffer + 1, s), s = buffer;
                    } അല്ലെങ്കിൽ എങ്കിൽ (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } അല്ലെങ്കിൽ എങ്കിൽ (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } അല്ലെങ്കിൽ {
                        നിർത്തുക;
                    }
                }
                imp_sym = find_elf_sym(s1->dynsymtab_section, s);
            } ആകുമ്പോൾ (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            എങ്കിൽ (0 == imp_sym)
                തുടരുക; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_add_import(pe, imp_sym);

            എങ്കിൽ (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                unsigned offset = is->thk_offset;
                എങ്കിൽ (offset) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } അല്ലെങ്കിൽ {
                    unsigned അക്ഷരം *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(buffer, "IAT.%s", name);
                    is->iat_index = put_elf_sym(
                        symtab_section, 0, വലുപ്പം(DWORD),
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
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_ARM64)
                    p = section_ptr_add(text_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, text_section,
                        offset + 16, R_XXX_THUNKFIX, is->iat_index);
#അല്ലെങ്കിൽ
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
                sym->st_മൂല്യം = offset;
                sym->st_shndx = text_section->sh_അക്കം;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } അല്ലെങ്കിൽ { /* STT_OBJECT */
                എങ്കിൽ (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_മൂല്യം = is->iat_index; /* chain potential alias */
                is->iat_index = sym_index;
            }

        } അല്ലെങ്കിൽ എങ്കിൽ (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    തിരികെ ret;
}

/*----------------------------------------------------------------------------*/
#എങ്കിൽ PE_PRINT_SECTIONS
സ്ഥിതം ശൂന്യം pe_print_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    പൂർണ്ണസംഖ്യ i, n, l, m;
    p = s->data;
    e = s->data + s->data_offset;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    എങ്കിൽ (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    എങ്കിൽ (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (unsigned)s->sh_addr);
    fprintf(f, "\ncontents %08X", (unsigned)l);
    fprintf(f, "\n\n");

    എങ്കിൽ (s->sh_type == SHT_NOBITS)
        തിരികെ;

    എങ്കിൽ (0 == l)
        തിരികെ;

    എങ്കിൽ (s->sh_type == SHT_SYMTAB)
        m = വലുപ്പം(ElfW(Sym));
    അല്ലെങ്കിൽ എങ്കിൽ (s->sh_type == SHT_RELX)
        m = വലുപ്പം(ElfW_Rel);
    അല്ലെങ്കിൽ
        m = 16;

    fprintf(f, "%-8s", "offset");
    വേണ്ടി (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    എങ്കിൽ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        സ്ഥിരം അക്ഷരം *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            ശൂന്യ
        };

        സ്ഥിരം അക്ഷരം *fields2[] = {
            "offs",
            "type",
            "symb",
            ശൂന്യ
        };

        സ്ഥിരം അക്ഷരം **p;

        എങ്കിൽ (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        അല്ലെങ്കിൽ
            p = fields2, n = 58;

        വേണ്ടി (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    വേണ്ടി (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    വേണ്ടി (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        വേണ്ടി (n = 0; n < m; ++n) {
            എങ്കിൽ (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            അല്ലെങ്കിൽ
                fprintf(f, "   ");
        }

        എങ്കിൽ (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            സ്ഥിരം അക്ഷരം *name = s->link->data + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (unsigned)sym->st_name,
                    (unsigned)sym->st_മൂല്യം,
                    (unsigned)sym->st_size,
                    (unsigned)ELFW(ST_BIND)(sym->st_info),
                    (unsigned)ELFW(ST_TYPE)(sym->st_info),
                    (unsigned)sym->st_other,
                    (unsigned)sym->st_shndx,
                    name);

        } അല്ലെങ്കിൽ എങ്കിൽ (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->data + ELFW(R_SYM)(rel->r_info);
            സ്ഥിരം അക്ഷരം *name = s->link->link->data + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (unsigned)rel->r_offset,
                    (unsigned)ELFW(R_TYPE)(rel->r_info),
                    (unsigned)ELFW(R_SYM)(rel->r_info),
                    name);
        } അല്ലെങ്കിൽ {
            fprintf(f, "   ");
            വേണ്ടി (n = 0; n < m; ++n) {
                എങ്കിൽ (n + i < l) {
                    b = p[i + n];
                    എങ്കിൽ (b < 32 || b >= 127)
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

സ്ഥിതം ശൂന്യം pe_print_sections(TCCState *s1, സ്ഥിരം അക്ഷരം *fname)
{
    Section *s;
    FILE *f;
    പൂർണ്ണസംഖ്യ i;
    f = fopen(fname, "w");
    വേണ്ടി (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    fclose(f);
}
#endif

/* ------------------------------------------------------------- */

ST_FUNC പൂർണ്ണസംഖ്യ pe_putimport(TCCState *s1, പൂർണ്ണസംഖ്യ dllindex, സ്ഥിരം അക്ഷരം *name, addr_t മൂല്യം)
{
    തിരികെ set_elf_sym(
        s1->dynsymtab_section,
        മൂല്യം,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        മൂല്യം ? SHN_ABS : SHN_UNDEF,
        name
        );
}

സ്ഥിതം പൂർണ്ണസംഖ്യ read_mem(പൂർണ്ണസംഖ്യ fd, unsigned offset, ശൂന്യം *buffer, unsigned len)
{
    lseek(fd, offset, SEEK_SET);
    തിരികെ len == പഠ(fd, buffer, len);
}

/* ------------------------------------------------------------- */

സ്ഥിതം പൂർണ്ണസംഖ്യ get_dllexports(പൂർണ്ണസംഖ്യ fd, അക്ഷരം **pp)
{
    പൂർണ്ണസംഖ്യ i, k, l, n, n0, ret;
    അക്ഷരം *p;

    IMAGE_SECTION_HEADER ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_HEADER dh;
    IMAGE_FILE_HEADER ih;
    DWORD sig, ref, addr;
    DWORD *namep = ശൂന്യ, p0 = 0, p1;

    പൂർണ്ണസംഖ്യ pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = ശൂന്യ;
    ret = 1;
    എങ്കിൽ (!read_mem(fd, 0, &dh, വലുപ്പം dh))
        പോകുക the_end;
    എങ്കിൽ (!read_mem(fd, dh.e_lfanew, &sig, വലുപ്പം sig))
        പോകുക the_end;
    എങ്കിൽ (sig != 0x00004550)
        പോകുക the_end;
    pef_hdroffset = dh.e_lfanew + വലുപ്പം sig;
    എങ്കിൽ (!read_mem(fd, pef_hdroffset, &ih, വലുപ്പം ih))
        പോകുക the_end;
    opt_hdroffset = pef_hdroffset + വലുപ്പം ih;
    എങ്കിൽ (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + വലുപ്പം oh;
        എങ്കിൽ (!read_mem(fd, opt_hdroffset, &oh, വലുപ്പം oh))
            പോകുക the_end;
        എങ്കിൽ (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.സംഖ്യ_Of_Rva_And_Sizes)
            പോകുക the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } അല്ലെങ്കിൽ എങ്കിൽ (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + വലുപ്പം oh;
        എങ്കിൽ (!read_mem(fd, opt_hdroffset, &oh, വലുപ്പം oh))
            പോകുക the_end;
        എങ്കിൽ (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.സംഖ്യ_Of_Rva_And_Sizes)
            പോകുക the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } അല്ലെങ്കിൽ
        പോകുക the_end;

    //printf("addr: %08x\n", addr);
    വേണ്ടി (i = 0; i < ih.സംഖ്യ_Of_Sections; ++i) {
        എങ്കിൽ (!read_mem(fd, sec_hdroffset + i * വലുപ്പം ish, &ish, വലുപ്പം ish))
            പോകുക the_end;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        എങ്കിൽ (addr >= ish.VirtualAddress && addr < ish.VirtualAddress + ish.SizeOfRawData)
            പോകുക found;
    }
    പോകുക the_end_0;
found:
    ref = ish.VirtualAddress - ish.PointerToRawData;
    എങ്കിൽ (!read_mem(fd, addr - ref, &ied, വലുപ്പം ied))
        പോകുക the_end;
    k = ied.സംഖ്യ_Of_Names;
    എങ്കിൽ (k) {
        namep = tcc_malloc(l = k * വലുപ്പം *namep);
        എങ്കിൽ (!read_mem(fd, ied.AddressOfNames - ref, namep, l))
            പോകുക the_end;
        വേണ്ടി (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            എങ്കിൽ (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            ചെയ്യുക {
                എങ്കിൽ (0 == l) {
                    എങ്കിൽ (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    എങ്കിൽ ((l = പഠ(fd, p + n, 1000 - 1)) <= 0)
                        പോകുക the_end;
                }
                --l, ++p0;
            } ആകുമ്പോൾ (p[n++]);
        }
        p[n] = 0;
    }
the_end_0:
    ret = 0;
the_end:
    tcc_free(namep);
    എങ്കിൽ (ret && p)
        tcc_free(p), p = ശൂന്യ;
    *pp = p;
    തിരികെ ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

സ്ഥിതം പൂർണ്ണസംഖ്യ pe_load_res(TCCState *s1, പൂർണ്ണസംഖ്യ fd)
{
    ഘടന pe_rsrc_header hdr;
    Section *rsrc_section;
    പൂർണ്ണസംഖ്യ i, ret = -1, sym_index;
    BYTE *ptr;
    unsigned offs;

    എങ്കിൽ (!read_mem(fd, 0, &hdr, വലുപ്പം hdr))
        പോകുക quit;

    എങ്കിൽ (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.സംഖ്യ_Of_Sections != 1
        || strcmp((അക്ഷരം*)hdr.sectionhdr.Name, ".rsrc") != 0)
        പോകുക quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_add(rsrc_section, hdr.sectionhdr.SizeOfRawData);
    offs = hdr.sectionhdr.PointerToRawData;
    എങ്കിൽ (!read_mem(fd, offs, ptr, hdr.sectionhdr.SizeOfRawData))
        പോകുക quit;
    offs = hdr.sectionhdr.PointerToRelocations;
    sym_index = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_അക്കം, ".rsrc");
    വേണ്ടി (i = 0; i < hdr.sectionhdr.സംഖ്യ_Of_Relocations; ++i) {
        ഘടന pe_rsrc_reloc rel;
        എങ്കിൽ (!read_mem(fd, offs, &rel, വലുപ്പം rel))
            പോകുക quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        എങ്കിൽ (rel.type != RSRC_RELTYPE)
            പോകുക quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.offset, R_XXX_RELATIVE, sym_index);
        offs += വലുപ്പം rel;
    }
    ret = 0;
quit:
    തിരികെ ret;
}

/* ------------------------------------------------------------- */

സ്ഥിതം അക്ഷരം *trimfront(അക്ഷരം *p)
{
    ആകുമ്പോൾ ((unsigned അക്ഷരം)*p <= ' ' && *p && *p != '\n')
	++p;
    തിരികെ p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

സ്ഥിതം അക്ഷരം *get_token(അക്ഷരം **s, അക്ഷരം *f)
{
    അക്ഷരം *p, *e;
    പൂർണ്ണസംഖ്യ q;

    p = trimfront(*s);
    q = *p;
    എങ്കിൽ (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    അല്ലെങ്കിൽ
        q = ' ';
    വേണ്ടി (e = p; (unsigned അക്ഷരം)*e >= ' ' && *e != q; ++e)
        ;
    എങ്കിൽ (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    തിരികെ p;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ pe_load_def(TCCState *s1, പൂർണ്ണസംഖ്യ fd)
{
    പൂർണ്ണസംഖ്യ state = 0, ret = -1, dllindex = 0, ord;
    അക്ഷരം dllname[80], *buf, *വരി, *p, *x, next;

    buf = tcc_load_text(fd);
    എങ്കിൽ (!buf)
        തിരികെ ret;

    വേണ്ടി (വരി = buf;; ++വരി)  {
        p = get_token(&വരി, &next);
        എങ്കിൽ (!(*p && *p != ';'))
            പോകുക skip;
        തിരഞ്ഞെടുപ്പ് (state) {
        അവസ്ഥ 0:
            എങ്കിൽ (0 != stricmp(p, "LIBRARY") || next == '\n')
                പോകുക quit;
            pstrcpy(dllname, വലുപ്പം dllname, get_token(&വരി, &next));
            എങ്കിൽ (!*tcc_fileextension(dllname))
                pstrcat(dllname, വലുപ്പം dllname, ".dll");
            ++state;
            നിർത്തുക;
        അവസ്ഥ 1:
            എങ്കിൽ (0 != stricmp(p, "EXPORTS"))
                പോകുക quit;
            ++state;
            നിർത്തുക;
        അവസ്ഥ 2:
            dllindex = tcc_add_dllref(s1, dllname, 0)->index;
            ++state;
            /* fall through */
        സ്ഥിരസ്ഥിതി:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            എങ്കിൽ (next == '@') {
                x = get_token(&വരി, &next);
                ord = (പൂർണ്ണസംഖ്യ)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            നിർത്തുക;
        }
skip:
        ആകുമ്പോൾ ((unsigned അക്ഷരം)next > ' ')
            get_token(&വരി, &next);
        എങ്കിൽ (next != '\n')
            നിർത്തുക;
    }
    ret = 0;
quit:
    tcc_free(buf);
    തിരികെ ret;
}

/* ------------------------------------------------------------- */

സ്ഥിതം പൂർണ്ണസംഖ്യ pe_load_dll(TCCState *s1, പൂർണ്ണസംഖ്യ fd, സ്ഥിരം അക്ഷരം *filename)
{
    അക്ഷരം *p, *q;
    DLLReference *ref = tcc_add_dllref(s1, filename, 0);
    എങ്കിൽ (ref->found)
        തിരികെ 0;
    എങ്കിൽ (get_dllexports(fd, &p))
        തിരികെ -1;
    എങ്കിൽ (p) {
        വേണ്ടി (q = p; *q; q += 1 + strlen(q))
            pe_putimport(s1, ref->index, q, 0);
        tcc_free(p);
    }
    തിരികെ 0;
}

ST_FUNC പൂർണ്ണസംഖ്യ pe_load_file(ഘടന TCCState *s1, പൂർണ്ണസംഖ്യ fd, സ്ഥിരം അക്ഷരം *filename)
{
    പൂർണ്ണസംഖ്യ ret = -1;
    അക്ഷരം buf[10];
    എങ്കിൽ (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_load_def(s1, fd);
    അല്ലെങ്കിൽ എങ്കിൽ (pe_load_res(s1, fd) == 0)
        ret = 0;
    അല്ലെങ്കിൽ എങ്കിൽ (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_load_dll(s1, fd, filename);
    തിരികെ ret;
}

PUB_FUNC പൂർണ്ണസംഖ്യ tcc_get_dllexports(സ്ഥിരം അക്ഷരം *filename, അക്ഷരം **pp)
{
    പൂർണ്ണസംഖ്യ ret, fd = open(filename, O_RDONLY | O_ദ്വിമാന_2);
    എങ്കിൽ (fd < 0)
        തിരികെ -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    തിരികെ ret;
}

/* ------------------------------------------------------------- */
#ifdef TCC_TARGET_X86_64
സ്ഥിതം unsigned pe_add_unwind_info(TCCState *s1)
{
    എങ്കിൽ (ശൂന്യ == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    എങ്കിൽ (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, text_section->sh_അക്കം, ".uw_base");
    എങ്കിൽ (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        സ്ഥിതം സ്ഥിരം unsigned അക്ഷരം uw_info[] = {
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
        unsigned അക്ഷരം *p;

        section_ptr_add(s, -s->data_offset & 3); /* align */
        s1->uw_offs = s->data_offset;
        p = section_ptr_add(s, വലുപ്പം uw_info);
        memcpy(p, uw_info, വലുപ്പം uw_info);
    }

    തിരികെ s1->uw_offs;
}

ST_FUNC ശൂന്യം pe_add_unwind_data(unsigned start, unsigned end, unsigned അട്ടി)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    unsigned o, n, d;
    ഘടന /* _RUNTIME_FUNCTION */ {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD UnwindData;
    } *p;

    d = pe_add_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->data_offset;
    p = section_ptr_add(pd, വലുപ്പം *p);

    /* record this function */
    p->BeginAddress = start;
    p->EndAddress = end;
    p->UnwindData = d;

    /* put relocations on it */
    വേണ്ടി (n = o + വലുപ്പം *p; o < n; o += വലുപ്പം p->BeginAddress)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
സ്ഥിതം Section *pe_add_unwind_info(TCCState *s1)
{
    Section *s;

    എങ്കിൽ (ശൂന്യ == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = find_section(s1, ".xdata");
    s->sh_addralign = 4;
    എങ്കിൽ (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  text_section->sh_അക്കം, ".uw_text_base");
    എങ്കിൽ (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_അക്കം, ".uw_base");
    തിരികെ s;
}

ST_FUNC ശൂന്യം pe_add_unwind_data(unsigned start, unsigned end, unsigned അട്ടി)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    unsigned o, d, code_bytes, func_len;
    unsigned അക്ഷരം *q;
    uint32_t header;
    ഘടന /* _RUNTIME_FUNCTION */ {
        DWORD BeginAddress;
        DWORD UnwindData;
    } *p;

    പൂർണ്ണസംഖ്യ epilog;

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
    ആകുമ്പോൾ ((unsigned)(q - (xd->data + d + 4)) < code_bytes)
        *q++ = 0xE3; /* nop padding */

    o = pd->data_offset;
    p = section_ptr_add(pd, വലുപ്പം *p);
    p->BeginAddress = start;
    p->UnwindData = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#endif
/* ------------------------------------------------------------- */
#എങ്കിൽ defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
#define PE_STDSYM(n,s) n
#അല്ലെങ്കിൽ
#define PE_STDSYM(n,s) "_" n s
#endif

സ്ഥിതം ശൂന്യം pe_add_runtime(TCCState *s1, ഘടന pe_info *pe)
{
    സ്ഥിരം അക്ഷരം *start_ചിഹ്നം;
    പൂർണ്ണസംഖ്യ pe_type;

    എങ്കിൽ (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        start_ചിഹ്നം = PE_STDSYM("__dllstart","@12");
    } അല്ലെങ്കിൽ {
        സ്ഥിരം അക്ഷരം *run_ചിഹ്നം;
        എങ്കിൽ (find_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            start_ചിഹ്നം = "__winstart";
            run_ചിഹ്നം = "__runwinmain";
            pe_type = PE_GUI;
        } അല്ലെങ്കിൽ എങ്കിൽ (find_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            start_ചിഹ്നം = "__wwinstart";
            run_ചിഹ്നം = "__runwwinmain";
            pe_type = PE_GUI;
        } അല്ലെങ്കിൽ എങ്കിൽ (find_elf_sym(symtab_section, "wmain")) {
            start_ചിഹ്നം = "__wstart";
            run_ചിഹ്നം = "__runwmain";
            pe_type = PE_EXE;
        } അല്ലെങ്കിൽ {
            start_ചിഹ്നം =  "__start";
            run_ചിഹ്നം = "__runmain";
            pe_type = PE_EXE;
            എങ്കിൽ (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        എങ്കിൽ (TCC_OUTPUT_MEMORY == s1->output_type && !s1->nostdlib)
            start_ചിഹ്നം = run_ചിഹ്നം;
    }
    എങ്കിൽ (s1->elf_entryname) {
        pe->start_ചിഹ്നം = start_ചിഹ്നം = s1->elf_entryname;
    } അല്ലെങ്കിൽ {
        pe->start_ചിഹ്നം = start_ചിഹ്നം + 1;
        എങ്കിൽ (!s1->leading_underscore || strchr(start_ചിഹ്നം, '@'))
            ++start_ചിഹ്നം;
    }

#ifdef CONFIG_TCC_BACKTRACE
    എങ്കിൽ (s1->do_backtrace) {
#ifdef CONFIG_TCC_BCHECK
        എങ്കിൽ (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    എങ്കിൽ (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    അല്ലെങ്കിൽ
                tcc_add_support(s1, "bcheck.o");
	}
#endif
        എങ്കിൽ (s1->output_type == TCC_OUTPUT_EXE)
            tcc_add_support(s1, "bt-exe.o");
        എങ്കിൽ (s1->output_type == TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-dll.o");
        എങ്കിൽ (s1->output_type != TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-log.o");
        tcc_add_btstub(s1);
    }
#endif

    /* grab the startup code from libtcc1.a */
#ifdef TCC_IS_NATIVE
    എങ്കിൽ (TCC_OUTPUT_MEMORY != s1->output_type || s1->run_main)
#endif
    set_global_sym(s1, start_ചിഹ്നം, ശൂന്യ, 0);

    എങ്കിൽ (0 == s1->nostdlib) {
        സ്ഥിതം സ്ഥിരം അക്ഷരം * സ്ഥിരം libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", ശൂന്യ
        };
        സ്ഥിരം അക്ഷരം * സ്ഥിരം *pp, *p;
        എങ്കിൽ (TCC_LIBTCC1[0])
            tcc_add_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        വേണ്ടി (pp = libs; 0 != (p = *pp); ++pp) {
            എങ്കിൽ (*p)
                tcc_add_library(s1, p);
            അല്ലെങ്കിൽ എങ്കിൽ (PE_DLL != pe_type && PE_GUI != pe_type)
                നിർത്തുക;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    എങ്കിൽ (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    എങ്കിൽ (TCC_OUTPUT_MEMORY == s1->output_type)
        pe_type = PE_RUN;
    pe->type = pe_type;
}

ST_FUNC പൂർണ്ണസംഖ്യ pe_setsubsy(TCCState *s1, സ്ഥിരം അക്ഷരം *arg)
{
    സ്ഥിതം സ്ഥിരം ഘടന subsy { സ്ഥിരം അക്ഷരം* p; പൂർണ്ണസംഖ്യ v; } x[] = {
#എങ്കിൽ defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_ARM)
        { "wince", 9 },
#endif
        { 0, -1 }};
    സ്ഥിരം ഘടന subsy *y;
    വേണ്ടി (y = x;; ++y) {
        എങ്കിൽ (!y->p)
            തിരികെ -1;
        എങ്കിൽ (0 == strcmp(y->p, arg)) {
            s1->pe_subsystem = y->v;
            തിരികെ 0;
        }
    }
}

സ്ഥിതം ശൂന്യം pe_set_options(TCCState * s1, ഘടന pe_info *pe)
{
    എങ്കിൽ (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_BASE_DLL;
    } അല്ലെങ്കിൽ {
        pe->imagebase = IMAGE_BASE_EXE;
    }

#എങ്കിൽ defined(TCC_TARGET_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#അല്ലെങ്കിൽ
    എങ്കിൽ (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    അല്ലെങ്കിൽ
        pe->subsystem = 3;
#endif
    /* Allow override via -Wl,-subsystem=... option */
    എങ്കിൽ (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    എങ്കിൽ (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } അല്ലെങ്കിൽ {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    എങ്കിൽ (s1->section_align != 0)
        pe->section_align = s1->section_align;
    എങ്കിൽ (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    എങ്കിൽ ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    എങ്കിൽ (s1->has_text_addr)
        pe->imagebase = s1->text_addr;
}

ST_FUNC പൂർണ്ണസംഖ്യ pe_output_file(TCCState *s1, സ്ഥിരം അക്ഷരം *filename)
{
    ഘടന pe_info pe;

    memset(&pe, 0, വലുപ്പം pe);
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
    എങ്കിൽ (s1->nb_errors)
        പോകുക done;
    എങ്കിൽ (filename) {
        pe_assign_addresses(&pe);
        relocate_syms(s1, s1->symtab, 0);
        എങ്കിൽ (s1->nb_errors)
            പോകുക done;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.start_addr = (DWORD)
            (get_sym_addr(s1, pe.start_ചിഹ്നം, 1, 1) - pe.imagebase);
        എങ്കിൽ (s1->nb_errors)
            പോകുക done;
        pe_write(&pe);
    } അല്ലെങ്കിൽ {
        /* -run */
#ifdef TCC_IS_NATIVE
        pe.thunk = data_section;
        pe_build_imports(&pe);
        s1->run_main = pe.start_ചിഹ്നം;
#എങ്കിൽ defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        s1->uw_pdata = find_section(s1, ".pdata");
#endif
#endif
    }
done:
    dynarray_reset(&pe.sec_info, &pe.sec_എണ്ണം);
    pe_free_imports(&pe);
#എങ്കിൽ PE_PRINT_SECTIONS
    എങ്കിൽ (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#endif
    തിരികെ s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
