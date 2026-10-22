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

#અન્તર્ભાવ "tcc.h"

#define PE_MERGE_DATA 1
#define PE_PRINT_SECTIONS 0

#ifndef _WIN32
#define stricmp strcasecmp
#define strnicmp strncasecmp
#અન્તર્ભાવ <sys/stat.h> /* chmod() */
#endif

#જો defined TCC_TARGET_X86_64
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

#અથવાજો defined TCC_TARGET_ARM
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

#અથવાજો defined TCC_TARGET_ARM64
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

#અથવાજો defined TCC_TARGET_I386
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

#જો PTR_SIZE == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#નહીંતર
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#endif

#ifndef IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

પ્રકારવ્યાખ્યા unsigned અક્ષર BYTE;
પ્રકારવ્યાખ્યા unsigned short WORD;
પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક DWORD;
પ્રકારવ્યાખ્યા unsigned long long ULONGLONG;
#pragma pack(ધકેલો, 1)

પ્રકારવ્યાખ્યા સંરચના _IMAGE_DOS_HEADER {  /* DOS .EXE header */
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

પ્રકારવ્યાખ્યા સંરચના _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    સંખ્યા_Of_Sections;
    DWORD   TimeDateStamp;
    DWORD   Pointer_To_પ્રતીક_Table;
    DWORD   સંખ્યા_Of_Symbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;


#define IMAGE_SIZEOF_FILE_HEADER 20

પ્રકારવ્યાખ્યા સંરચના _IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;


પ્રકારવ્યાખ્યા સંરચના _IMAGE_OPTIONAL_HEADER {
    /* Standard fields. */
    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
#જો PTR_SIZE == 4
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
    DWORD   Win32_Version_કિંમત;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    ADDR3264 Size_Of_ઢગલો_Reserve;
    ADDR3264 Size_Of_ઢગલો_Commit;
    ADDR3264 SizeOfHeapReserve;
    ADDR3264 SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   સંખ્યા_Of_Rva_And_Sizes;
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

પ્રકારવ્યાખ્યા સંરચના _IMAGE_SECTION_HEADER {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    સંઘ {
            DWORD   PhysicalAddress;
            DWORD   VirtualSize;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   SizeOfRawData;
    DWORD   PointerToRawData;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    સંખ્યા_Of_Relocations;
    WORD    સંખ્યા_Of_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#define IMAGE_SIZEOF_SECTION_HEADER     40

પ્રકારવ્યાખ્યા સંરચના _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD Name;
    DWORD Base;
    DWORD સંખ્યા_Of_Functions;
    DWORD સંખ્યા_Of_Names;
    DWORD AddressOfFunctions;
    DWORD AddressOfNames;
    DWORD AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

પ્રકારવ્યાખ્યા સંરચના _IMAGE_TLS_DIRECTORY {
    ADDR3264 StartAddressOfRawData;
    ADDR3264 EndAddressOfRawData;
    ADDR3264 AddressOfIndex;
    ADDR3264 AddressOfCallBacks;
    DWORD SizeOfZeroFill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

પ્રકારવ્યાખ્યા સંરચના _IMAGE_IMPORT_DESCRIPTOR {
    સંઘ {
        DWORD Characteristics;
        DWORD OriginalFirstThunk;
    };
    DWORD TimeDateStamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;

પ્રકારવ્યાખ્યા સંરચના _IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   SizeOfBlock;
//  WORD    TypeOffset[1];
} IMAGE_BASE_RELOCATION;

#define IMAGE_SIZEOF_BASE_RELOCATION     8

#define IMAGE_REL_BASED_ABSOLUTE         0
#define IMAGE_REL_BASED_ઉપલું             1
#define IMAGE_REL_BASED_નીચલું              2
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

#define IMAGE_DLLCHARACTERISTICS_ઉપલું_ENTROPY_VA 0x0020
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#define IMAGE_FILE_RELOCS_STRIPPED 0x0001

#pragma pack(કાઢો)

/* ----------------------------------------------------------- */
#endif /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#ifndef IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#endif

#pragma pack(ધકેલો, 1)
સંરચના pe_header
{
    IMAGE_DOS_HEADER doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_HEADER filehdr;
#જો PTR_SIZE == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#નહીંતર
#ifdef _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#નહીંતર
    IMAGE_OPTIONAL_HEADER opthdr;
#endif
#endif
};

સંરચના pe_reloc_header {
    DWORD offset;
    DWORD size;
};

સંરચના pe_rsrc_header {
    સંરચના _IMAGE_FILE_HEADER filehdr;
    સંરચના _IMAGE_SECTION_HEADER sectionhdr;
};

સંરચના pe_rsrc_reloc {
    DWORD offset;
    DWORD size;
    WORD type;
};
#pragma pack(કાઢો)

/* ------------------------------------------------------------- */
/* internal temporary structures */

ગણના {
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

#જો 0
સ્થિર અચલ DWORD pe_sec_flags[] = {
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

સંરચના section_info {
    પૂર્ણાંક cls;
    અક્ષર name[32];
    ADDR3264 sh_addr;
    DWORD sh_size;
    DWORD pe_flags;
    Section *sec;
    DWORD data_size;
    IMAGE_SECTION_HEADER ish;
};

સંરચના import_પ્રતીક {
    પૂર્ણાંક sym_index;
    પૂર્ણાંક iat_index;
    પૂર્ણાંક thk_offset;
};

સંરચના pe_import_info {
    પૂર્ણાંક dll_index;
    પૂર્ણાંક sym_ગણતરી;
    સંરચના import_પ્રતીક **symbols;
};

સંરચના pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    અચલ અક્ષર *filename;
    પૂર્ણાંક type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    અચલ અક્ષર *start_પ્રતીક;
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
    પૂર્ણાંક subsystem;
    DWORD section_align;
    DWORD file_align;
    સંરચના section_info **sec_info;
    પૂર્ણાંક sec_ગણતરી;
    સંરચના pe_import_info **imp_info;
    પૂર્ણાંક imp_ગણતરી;
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

સ્થિર અચલ અક્ષર *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    અચલ અક્ષર *name = (અક્ષર*)symtab_section->link->data + sym->st_name;
    જો (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        પાછા name + 1;
    પાછા name;
}


સ્થિર પૂર્ણાંક dynarray_assoc(શૂન્ય **pp, પૂર્ણાંક n, પૂર્ણાંક ચાવી)
{
    પૂર્ણાંક i;
    માટે (i = 0; i < n; ++i, ++pp)
    જો (ચાવી == **(પૂર્ણાંક **) pp)
        પાછા i;
    પાછા -1;
}

સ્થિર DWORD umin(DWORD a, DWORD b)
{
    પાછા a < b ? a : b;
}

સ્થિર DWORD umax(DWORD a, DWORD b)
{
    પાછા a < b ? b : a;
}

સ્થિર DWORD pe_file_align(સંરચના pe_info *pe, DWORD n)
{
    પાછા (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

સ્થિર ADDR3264 pe_virtual_align(સંરચના pe_info *pe, ADDR3264 n)
{
    પાછા (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

સ્થિર શૂન્ય pe_align_section(Section *s, પૂર્ણાંક a)
{
    પૂર્ણાંક i = s->data_offset & (a-1);
    જો (i)
        section_ptr_add(s, a - i);
}

સ્થિર શૂન્ય pe_set_datadir(સંરચના pe_header *hdr, પૂર્ણાંક dir, DWORD addr, DWORD size)
{
    hdr->opthdr.DataDirectory[dir].VirtualAddress = addr;
    hdr->opthdr.DataDirectory[dir].Size = size;
}

સ્થિર પૂર્ણાંક pe_fwrite(સંરચના pe_info *pe, અચલ શૂન્ય *data, પૂર્ણાંક len)
{
    અચલ WORD *p = data;
    DWORD sum;
    પૂર્ણાંક ret, i;
    pe->pos += (ret = fwrite(data, 1, len, pe->op));
    sum = pe->sum;
    માટે (i = len; i > 0; i -= 2) {
        sum += (i >= 2) ? *p++ : *(BYTE*)p;
        sum = (sum + (sum >> 16)) & 0xFFFF;
    }
    pe->sum = sum;
    પાછા len == ret ? 0 : -1;
}

સ્થિર શૂન્ય pe_fpad(સંરચના pe_info *pe, DWORD new_pos)
{
    અક્ષર buf[256];
    પૂર્ણાંક n, diff = new_pos - pe->pos;
    memset(buf, 0, કદ buf);
    જ્યારે (diff > 0) {
        diff -= n = umin(diff, કદ buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#pragma pack(ધકેલો, 1)
સંરચના syment
{
    સંઘ {
        અક્ષર        n_name[8];     /* old COFF version */
        સંરચના {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_offset;      /* offset into string table */
        };
    };
    int32_t         n_કિંમત;        /* value of symbol */
    short           n_scnum;        /* section number */
    unsigned short  n_type;         /* type and derived type */
    અક્ષર            n_sclass;       /* storage class */
    અક્ષર            n_numaux;       /* number of aux. entries */
};
#pragma pack(કાઢો)

#define SHF_PRIVATE 0x80000000

સ્થિર શૂન્ય pe_add_coffsym(સંરચના pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    સંરચના syment *se;
    પૂર્ણાંક n;

    જો (ખાલી == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_PRIVATE);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_PRIVATE);
        section_ptr_add(pe->coffstr, 4); /* coff string table size */
        પાછા;
    }

#જો 0
    se = section_ptr_add(pe->coffsym, કદ *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_add(pe->coffsym, કદ *se);
    strcpy((અક્ષર*)se, "no-file");
#endif

#જો 1
    esym = (ElfSym*)s1->symtab->data;
    માટે (n = s1->symtab->data_offset / કદ *esym; ++esym, --n;) {
        પૂર્ણાંક sym_bind = ELFW(ST_BIND)(esym->st_info);
        જો (sym_bind == STB_GLOBAL) {
            અક્ષર *name = esym->st_name + (અક્ષર*)s1->symtab->link->data;
            પૂર્ણાંક nl = strlen(name);
            addr_t કિંમત = esym->st_કિંમત;
            પૂર્ણાંક shnum = esym->st_shndx;
            જો (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                કિંમત = કિંમત - s->sh_addr;
            }
            se = section_ptr_add(pe->coffsym, કદ *se);
            se->n_કિંમત = કિંમત;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            જો (nl <= 8)
                memcpy(se->n_name, name, nl);
            નહીંતર
                se->n_offset = put_elf_str(pe->coffstr, name);
        }
    }
#endif
    write32le(pe->coffstr->data, pe->coffstr->data_offset); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
સ્થિર શૂન્ય pe_create_pdb(TCCState *s1, અચલ અક્ષર *exename)
{
    અક્ષર buf[300]; પૂર્ણાંક r;
    snprintf(buf, કદ buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    strcpy(tcc_fileextension(strcpy(buf, exename)), ".pdb");
    જો (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } નહીંતર જો (s1->verbose) {
        printf("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
સ્થિર પૂર્ણાંક pe_write(સંરચના pe_info *pe)
{
    સ્થિર અચલ સંરચના pe_header pe_template = {
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
#જો PTR_SIZE == 4
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

    સંરચના pe_header pe_header = pe_template;

    પૂર્ણાંક i;
    DWORD file_offset;
    સંરચના section_info *si;
    IMAGE_SECTION_HEADER *psh;
    TCCState *s1 = pe->s1;

    જો (s1->do_debug)
        pe_add_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    જો (ખાલી == pe->op)
        પાછા tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        કદ (સંરચના pe_header)
        + pe->sec_ગણતરી * કદ (IMAGE_SECTION_HEADER)
        );

    file_offset = pe->sizeofheaders;

    જો (2 == s1->verbose)
        printf("-------------------------------"
               "\n  virt   file   size  section" "\n");
    માટે (i = 0; i < pe->sec_ગણતરી; ++i) {
        DWORD addr, size;
        અચલ અક્ષર *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        size = si->sh_size;
        psh = &si->ish;

        જો (2 == s1->verbose)
            printf("%6x %6x %6x  %s\n",
                (unsigned)addr, (unsigned)file_offset, (unsigned)size, sh_name);

        પસંદગી (si->cls) {
            સ્થિતિ sec_text:
                જો (!pe_header.opthdr.BaseOfCode)
                    pe_header.opthdr.BaseOfCode = addr;
                તોડો;

            સ્થિતિ sec_data:
#જો PTR_SIZE == 4
                જો (!pe_header.opthdr.BaseOfData)
                    pe_header.opthdr.BaseOfData = addr;
#endif
                તોડો;

            સ્થિતિ sec_bss:
                તોડો;

            સ્થિતિ sec_reloc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_BASERELOC, addr, size);
                તોડો;

            સ્થિતિ sec_rsrc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_RESOURCE, addr, size);
                તોડો;

            સ્થિતિ sec_pdata:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXCEPTION, addr, size);
                તોડો;
        }

        જો (pe->imp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IMPORT,
                pe->imp_offs, pe->imp_size);
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IAT,
                pe->iat_offs, pe->iat_size);
        }
        જો (pe->exp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXPORT,
                pe->exp_offs, pe->exp_size);
        }
        જો (pe->tls_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_size);
        }

        memcpy(psh->Name, sh_name, umin(strlen(sh_name), કદ psh->Name));
        જો (pe->coffstr && strlen(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((અક્ષર*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->VirtualAddress = addr;
        psh->Misc.VirtualSize = size;
        pe_header.opthdr.SizeOfImage =
            umax(pe_virtual_align(pe, size + addr), pe_header.opthdr.SizeOfImage);

        જો (si->data_size) {
            psh->PointerToRawData = file_offset;
            file_offset = pe_file_align(pe, file_offset + si->data_size);
            psh->SizeOfRawData = file_offset - psh->PointerToRawData;
            જો (si->cls == sec_text)
                pe_header.opthdr.SizeOfCode += psh->SizeOfRawData;
            નહીંતર
                pe_header.opthdr.SizeOfInitializedData += psh->SizeOfRawData;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_header.filehdr.સંખ્યા_Of_Sections = pe->sec_ગણતરી;
    pe_header.opthdr.AddressOfEntryPoint = pe->start_addr;
    pe_header.opthdr.SizeOfHeaders = pe->sizeofheaders;
    pe_header.opthdr.ImageBase = pe->imagebase;
    pe_header.opthdr.Subsystem = pe->subsystem;
    pe_header.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    જો (s1->pe_ઢગલો_size)
        pe_header.opthdr.Size_Of_ઢગલો_Reserve = s1->pe_ઢગલો_size;
    જો (PE_DLL == pe->type)
        pe_header.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_header.filehdr.Characteristics |= s1->pe_characteristics;
    જો (pe->reloc)
        pe_header.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    જો (pe->coffsym) {
        pe_add_coffsym(pe);
        pe_header.filehdr.Pointer_To_પ્રતીક_Table = file_offset;
        pe_header.filehdr.સંખ્યા_Of_Symbols
            = pe->coffsym->data_offset / કદ (સંરચના syment);
    }

    pe_fwrite(pe, &pe_header, કદ pe_header);
    માટે (i = 0; i < pe->sec_ગણતરી; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, કદ(IMAGE_SECTION_HEADER));

    file_offset = pe->sizeofheaders;
    માટે (i = 0; i < pe->sec_ગણતરી; ++i) {
        Section *s;
        si = pe->sec_info[i];
        જો (!si->data_size)
            ચાલુ;
        માટે (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_offset);
            pe_fwrite(pe, s->data, s->data_offset);
            જો (s->prev)
                file_offset += s->prev->sh_addr - s->sh_addr;
        }
        file_offset = si->ish.PointerToRawData + si->ish.SizeOfRawData;
        pe_fpad(pe, file_offset);
    }

    જો (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->data, pe->coffsym->data_offset);
        pe_fwrite(pe, pe->coffstr->data, pe->coffstr->data_offset);
        file_offset = pe->pos;
    }

    pe->sum += file_offset;
    fseek(pe->op, offsetof(સંરચના pe_header, opthdr.CheckSum), SEEK_SET);
    pe_fwrite(pe, &pe->sum, કદ (DWORD));

    fclose (pe->op);
#ifndef _WIN32
    chmod(pe->filename, 0777);
#endif

    જો (2 == s1->verbose)
        printf("-------------------------------\n");
    જો (s1->verbose)
        printf("<- %s (%u bytes)\n", pe->filename, (unsigned)file_offset);

    જો (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    પાછા 0;
}

/*----------------------------------------------------------------------------*/

સ્થિર સંરચના import_પ્રતીક *pe_add_import(સંરચના pe_info *pe, પૂર્ણાંક sym_index)
{
    પૂર્ણાંક i;
    પૂર્ણાંક dll_index;
    સંરચના pe_import_info *p;
    સંરચના import_પ્રતીક *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->data + sym_index;
    dll_index = isym->st_size;

    i = dynarray_assoc ((શૂન્ય**)pe->imp_info, pe->imp_ગણતરી, dll_index);
    જો (-1 != i) {
        p = pe->imp_info[i];
        જાઓ found_dll;
    }
    p = tcc_mallocz(કદ *p);
    p->dll_index = dll_index;
    dynarray_add(&pe->imp_info, &pe->imp_ગણતરી, p);

found_dll:
    i = dynarray_assoc ((શૂન્ય**)p->symbols, p->sym_ગણતરી, sym_index);
    જો (-1 != i)
        પાછા p->symbols[i];

    s = tcc_mallocz(કદ *s);
    dynarray_add(&p->symbols, &p->sym_ગણતરી, s);
    s->sym_index = sym_index;
    પાછા s;
}

સ્થિર શૂન્ય pe_free_imports(સંરચના pe_info *pe)
{
    પૂર્ણાંક i;
    માટે (i = 0; i < pe->imp_ગણતરી; ++i) {
        સંરચના pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_ગણતરી);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_ગણતરી);
}

/*----------------------------------------------------------------------------*/
સ્થિર શૂન્ય pe_build_imports(સંરચના pe_info *pe)
{
    પૂર્ણાંક thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_base = pe->thunk->sh_addr - pe->imagebase;
    પૂર્ણાંક ndlls = pe->imp_ગણતરી;
    TCCState *s1 = pe->s1;

    માટે (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_ગણતરી;

    જો (0 == sym_cnt)
        પાછા;

    pe_align_section(pe->thunk, 16);
    pe->imp_size = (ndlls + 1) * કદ(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_size = (sym_cnt + ndlls) * કદ(ADDR3264);
    dll_ptr = pe->thunk->data_offset;
    thk_ptr = dll_ptr + pe->imp_size;
    ent_ptr = thk_ptr + pe->iat_size;
    pe->imp_offs = dll_ptr + rva_base;
    pe->iat_offs = thk_ptr + rva_base;
    section_ptr_add(pe->thunk, pe->imp_size + 2*pe->iat_size);

    માટે (i = 0; i < pe->imp_ગણતરી; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        પૂર્ણાંક k, n, dllindex;
        ADDR3264 v;
        સંરચના pe_import_info *p = pe->imp_info[i];
        અચલ અક્ષર *name;
        DLLReference *dllref;

        dllindex = p->dll_index;
        જો (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        નહીંતર
            name = "", dllref = ખાલી;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->data + dll_ptr);
        hdr->FirstThunk = thk_ptr + rva_base;
        hdr->OriginalFirstThunk = ent_ptr + rva_base;
        hdr->Name = v + rva_base;

        માટે (k = 0, n = p->sym_ગણતરી; k <= n; ++k) {
            જો (k < n) {
                પૂર્ણાંક iat_index = p->symbols[k]->iat_index;
                પૂર્ણાંક sym_index = p->symbols[k]->sym_index;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->data + sym_index;
                અચલ અક્ષર *name = (અક્ષર*)s1->dynsymtab_section->link->data + imp_sym->st_name;
                પૂર્ણાંક ordinal;

                /* patch symbol (and possibly its underscored alias) */
                કરો {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->data + iat_index;
                    iat_index = esym->st_કિંમત;
                    esym->st_કિંમત = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_અંક;
                } જ્યારે (iat_index);

                જો (dllref)
                    v = 0, ordinal = imp_sym->st_કિંમત; /* ordinal from pe_load_def */
                નહીંતર
                    ordinal = 0, v = imp_sym->st_કિંમત; /* address from tcc_add_symbol() */

#ifdef TCC_IS_NATIVE
                જો (pe->type == PE_RUN) {
                    જો (dllref) {
                        જો ( !dllref->handle )
                            dllref->handle = LoadLibraryA(dllref->name);
                        v = (ADDR3264)GetProcAddress(dllref->handle, ordinal?(અક્ષર*)0+ordinal:name);
                    }
                    જો (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } નહીંતર
#endif
                જો (ordinal) {
                    v = ordinal | (ADDR3264)1 << (કદ(ADDR3264)*8 - 1);
                } નહીંતર {
                    v = pe->thunk->data_offset + rva_base;
                    section_ptr_add(pe->thunk, કદ(WORD)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } નહીંતર {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->data+thk_ptr) =
            *(ADDR3264*)(pe->thunk->data+ent_ptr) = v;
            thk_ptr += કદ (ADDR3264);
            ent_ptr += કદ (ADDR3264);
        }
        dll_ptr += કદ(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

સંરચના pe_sort_sym
{
    પૂર્ણાંક index;
    અચલ અક્ષર *name;
};

સ્થિર પૂર્ણાંક sym_cmp(અચલ શૂન્ય *va, અચલ શૂન્ય *vb)
{
    અચલ અક્ષર *ca = (*(સંરચના pe_sort_sym**)va)->name;
    અચલ અક્ષર *cb = (*(સંરચના pe_sort_sym**)vb)->name;
    પાછા strcmp(ca, cb);
}

સ્થિર શૂન્ય pe_build_exports(સંરચના pe_info *pe)
{
    ElfW(Sym) *sym;
    પૂર્ણાંક sym_index, sym_end;
    DWORD rva_base, base_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    પૂર્ણાંક sym_ગણતરી, ord;
    સંરચના pe_sort_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    અક્ષર buf[260];
    અચલ અક્ષર *dllname;
    અચલ અક્ષર *name;

    rva_base = pe->thunk->sh_addr - pe->imagebase;
    sym_ગણતરી = 0, sorted = ખાલી, op = ખાલી;

    sym_end = symtab_section->data_offset / કદ(ElfW(Sym));
    માટે (sym_index = 1; sym_index < sym_end; ++sym_index) {
        sym = (ElfW(Sym)*)symtab_section->data + sym_index;
        name = pe_export_name(s1, sym);
        જો (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(કદ *p);
            p->index = sym_index;
            p->name = name;
            dynarray_add(&sorted, &sym_ગણતરી, p);
        }
#જો 0
        જો (sym->st_other & ST_PE_EXPORT)
            printf("export: %s\n", name);
        જો (sym->st_other & ST_PE_STDCALL)
            printf("stdcall: %s\n", name);
#endif
    }

    જો (0 == sym_ગણતરી)
        પાછા;

    qsort (sorted, sym_ગણતરી, કદ *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    base_o = pe->thunk->data_offset;
    func_o = base_o + કદ(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_ગણતરી * કદ (DWORD);
    ord_o = name_o + sym_ગણતરી * કદ (DWORD);
    str_o = ord_o + sym_ગણતરી * કદ(WORD);

    hdr = section_ptr_add(pe->thunk, str_o - base_o);
    hdr->Characteristics        = 0;
    hdr->Base                   = 1;
    hdr->સંખ્યા_Of_Functions      = sym_ગણતરી;
    hdr->સંખ્યા_Of_Names          = sym_ગણતરી;
    hdr->AddressOfFunctions     = func_o + rva_base;
    hdr->AddressOfNames         = name_o + rva_base;
    hdr->AddressOfNameOrdinals  = ord_o + rva_base;
    hdr->Name                   = str_o + rva_base;
    put_elf_str(pe->thunk, dllname);

#જો 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, કદ buf, pe->filename);
    strcpy(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    જો (ખાલી == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } નહીંતર {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        જો (s1->verbose)
            printf("<- %s (%d symbol%s)\n", buf, sym_ગણતરી, &"s"[sym_ગણતરી < 2]);
    }
#endif

    માટે (ord = 0; ord < sym_ગણતરી; ++ord)
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
        func_o += કદ (DWORD);
        name_o += કદ (DWORD);
        ord_o += કદ (WORD);
        જો (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = base_o + rva_base;
    pe->exp_size = pe->thunk->data_offset - base_o;
    dynarray_reset(&sorted, &sym_ગણતરી);
    જો (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
સ્થિર શૂન્ય pe_build_reloc (સંરચના pe_info *pe)
{
    DWORD offset, block_ptr, sh_addr, addr;
    પૂર્ણાંક ગણતરી_2, i;
    ElfW_Rel *rel, *rel_end;
    Section *s = ખાલી, *sr;
    સંરચના pe_reloc_header *hdr;
    TCCState *s1 = pe->s1;
    પૂર્ણાંક dwarf = 0, n;

    sh_addr = offset = block_ptr = ગણતરી_2 = i = 0;
    rel = rel_end = ખાલી;

    માટે(;;) {
        જો (rel < rel_end) {
            પૂર્ણાંક type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_offset + sh_addr;
            ++ rel;
            જો (type != REL_TYPE_DIRECT)
                ચાલુ;
            જો (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->data + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                જો (n >= s1->dwlo && n < s1->dwhi)
                    ચાલુ;
            }
            જો (ગણતરી_2 == 0) { /* new block */
                block_ptr = pe->reloc->data_offset;
                section_ptr_add(pe->reloc, કદ(સંરચના pe_reloc_header));
                offset = addr & 0xFFFFFFFF<<12;
            }
            જો ((addr -= offset)  < (1<<12)) { /* one block spans 4k addresses */
                WORD *wp = section_ptr_add(pe->reloc, કદ (WORD));
                *wp = addr | PE_IMAGE_REL<<12;
                ++ગણતરી_2;
                ચાલુ;
            }
            -- rel;

        } નહીંતર જો (s) {
            sr = s->reloc;
            જો (sr) {
                rel = (ElfW_Rel *)sr->data;
                rel_end = (ElfW_Rel *)(sr->data + sr->data_offset);
                sh_addr = s->sh_addr;
                dwarf = s->sh_અંક >= s1->dwlo && s->sh_અંક < s1->dwhi;
            }
            s = s->prev;
            ચાલુ;

        } નહીંતર જો (i < pe->sec_ગણતરી) {
            s = pe->sec_info[i]->sec, ++i;
            ચાલુ;

        } નહીંતર જો (!ગણતરી_2)
            તોડો;

        /* fill the last block and ready for a new one */
        જો (ગણતરી_2 & 1) /* align for DWORDS */
            section_ptr_add(pe->reloc, કદ(WORD)), ++ગણતરી_2;
        hdr = (સંરચના pe_reloc_header *)(pe->reloc->data + block_ptr);
        hdr -> offset = offset - pe->imagebase;
        hdr -> size = ગણતરી_2 * કદ(WORD) + કદ(સંરચના pe_reloc_header);
        ગણતરી_2 = 0;
    }
}

/* ------------------------------------------------------------- */
સ્થિર શૂન્ય pe_build_tls(સંરચના pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    પૂર્ણાંક c, n;

    જો (0 == s) {
        pe->tls_size = કદ (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_add(pe->thunk, pe->tls_size, 16);
        pe->tls_data = section_add(data_section, PTR_SIZE * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, data_section->sh_અંક, 0);
        માટે (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_SIZE*n, REL_TYPE_DIRECT, c);
        /* for generators */
        set_elf_sym(symtab_section, pe->tls_data, PTR_SIZE * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, data_section->sh_અંક, "__tls_index");
        પાછા;
    }

    જો (0 == s1->tls_start)
        s1->tls_start = s->sh_addr;
    d = (શૂન્ય*)(pe->thunk->data + pe->tls_dir);
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
સ્થિર પૂર્ણાંક pe_section_class(Section *s)
{
    પૂર્ણાંક type, flags;
    અચલ અક્ષર *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    જો (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        પાછા sec_debug;
    } નહીંતર જો (flags & SHF_ALLOC) {
        જો (flags & SHF_TLS)
            પાછા sec_tdata + (type == SHT_NOBITS);
        જો (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            જો (flags & SHF_EXECINSTR)
                પાછા sec_text;
            જો (flags & SHF_WRITE)
                પાછા sec_data;
            જો (0 == strcmp(name, ".rsrc"))
                પાછા sec_rsrc;
            જો (0 == strcmp(name, ".iedat"))
                પાછા sec_idata;
            જો (0 == strcmp(name, ".pdata"))
                પાછા sec_pdata;
            પાછા sec_rdata;
        } નહીંતર જો (type == SHT_NOBITS) {
            પાછા sec_bss;
        }
        પાછા sec_other;
    } નહીંતર {
        જો (0 == strcmp(name, ".reloc"))
            પાછા sec_reloc;
    }
    પાછા sec_last;
}

સ્થિર પૂર્ણાંક pe_assign_addresses (સંરચના pe_info *pe)
{
    પૂર્ણાંક i, k, n, c, nbs;
    ADDR3264 addr;
    પૂર્ણાંક *sec_order, *sec_cls;
    સંરચના section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    જો (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_order = tcc_mallocz(2 * કદ (પૂર્ણાંક) * nbs);
    sec_cls = sec_order + nbs;
    માટે (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        માટે (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
        જો ((s->sh_flags & SHF_TLS) && 0 == pe->tls_size)
            pe_build_tls(pe, ખાલી);
    }
    si = ખાલી;
    addr = pe->imagebase + 1;
    માટે (i = 1; (c = sec_cls[i]) < sec_last; ++i) {
        s = s1->sections[sec_order[i]];

        જો (PE_MERGE_DATA && c == sec_bss)
            c = sec_data;
        જો (c == sec_tbss)
            c = sec_tdata;

        જો (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } નહીંતર {
            si = ખાલી;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        જો (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        જો (s == pe->reloc)
            pe_build_reloc (pe);

        જો (0 == s->data_offset)
            ચાલુ;

        જો (si)
            જાઓ add_section;

        si = tcc_mallocz(કદ *si);
        dynarray_add(&pe->sec_info, &pe->sec_ગણતરી, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        જો (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_CODE;
        નહીંતર જો (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_DATA;
        નહીંતર
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_DATA;
        જો (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        જો (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

add_section:
        s->sh_info = pe->sec_ગણતરી; /* section number for coff syms */
        addr += s->data_offset;
        si->sh_size = addr - si->sh_addr;
        જો (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            જ્યારે (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = ખાલી;
            si->data_size = si->sh_size;
        }

        જો (s->sh_flags & SHF_TLS) {
            strcpy(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#જો 0
    માટે (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_order[i]];
        પૂર્ણાંક type = s->sh_type;
        પૂર્ણાંક flags = s->sh_flags;
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
    પાછા 0;
}

/*----------------------------------------------------------------------------*/
સ્થિર પૂર્ણાંક pe_check_symbols(સંરચના pe_info *pe)
{
    પૂર્ણાંક sym_index, sym_end;
    પૂર્ણાંક ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(text_section, 8);

    sym_end = symtab_section->data_offset / કદ(ElfW(Sym));
    માટે (sym_index = 1; sym_index < sym_end; ++sym_index) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
        જો (sym->st_shndx == SHN_UNDEF) {
            અચલ અક્ષર *name = (અક્ષર*)symtab_section->link->data + sym->st_name;
            unsigned type = ELFW(ST_TYPE)(sym->st_info);
            પૂર્ણાંક imp_sym = 0;
            સંરચના import_પ્રતીક *is;

            પૂર્ણાંક _imp_, n;
            અક્ષર buffer[200];
            અચલ અક્ષર *s, *p;

            n = _imp_ = 0;
            જો (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            કરો {
                s = pe_export_name(s1, sym);
                જો (n) {
                    /* second try: */
                    જો (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        જો (!p || s[0] != '_')
                            તોડો;
                        strcpy(buffer, s+1)[p-s-1] = 0, s = buffer;
                    } નહીંતર જો (s[0] != '_') { /* try non-ansi function */
                        buffer[0] = '_', strcpy(buffer + 1, s), s = buffer;
                    } નહીંતર જો (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } નહીંતર જો (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } નહીંતર {
                        તોડો;
                    }
                }
                imp_sym = find_elf_sym(s1->dynsymtab_section, s);
            } જ્યારે (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            જો (0 == imp_sym)
                ચાલુ; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_add_import(pe, imp_sym);

            જો (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                unsigned offset = is->thk_offset;
                જો (offset) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } નહીંતર {
                    unsigned અક્ષર *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(buffer, "IAT.%s", name);
                    is->iat_index = put_elf_sym(
                        symtab_section, 0, કદ(DWORD),
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
#અથવાજો defined(TCC_TARGET_ARM64)
                    p = section_ptr_add(text_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, text_section,
                        offset + 16, R_XXX_THUNKFIX, is->iat_index);
#નહીંતર
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
                sym->st_કિંમત = offset;
                sym->st_shndx = text_section->sh_અંક;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } નહીંતર { /* STT_OBJECT */
                જો (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_કિંમત = is->iat_index; /* chain potential alias */
                is->iat_index = sym_index;
            }

        } નહીંતર જો (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    પાછા ret;
}

/*----------------------------------------------------------------------------*/
#જો PE_PRINT_SECTIONS
સ્થિર શૂન્ય pe_print_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    પૂર્ણાંક i, n, l, m;
    p = s->data;
    e = s->data + s->data_offset;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    જો (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    જો (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (unsigned)s->sh_addr);
    fprintf(f, "\ncontents %08X", (unsigned)l);
    fprintf(f, "\n\n");

    જો (s->sh_type == SHT_NOBITS)
        પાછા;

    જો (0 == l)
        પાછા;

    જો (s->sh_type == SHT_SYMTAB)
        m = કદ(ElfW(Sym));
    નહીંતર જો (s->sh_type == SHT_RELX)
        m = કદ(ElfW_Rel);
    નહીંતર
        m = 16;

    fprintf(f, "%-8s", "offset");
    માટે (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    જો (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        અચલ અક્ષર *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            ખાલી
        };

        અચલ અક્ષર *fields2[] = {
            "offs",
            "type",
            "symb",
            ખાલી
        };

        અચલ અક્ષર **p;

        જો (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        નહીંતર
            p = fields2, n = 58;

        માટે (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    માટે (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    માટે (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        માટે (n = 0; n < m; ++n) {
            જો (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            નહીંતર
                fprintf(f, "   ");
        }

        જો (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            અચલ અક્ષર *name = s->link->data + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (unsigned)sym->st_name,
                    (unsigned)sym->st_કિંમત,
                    (unsigned)sym->st_size,
                    (unsigned)ELFW(ST_BIND)(sym->st_info),
                    (unsigned)ELFW(ST_TYPE)(sym->st_info),
                    (unsigned)sym->st_other,
                    (unsigned)sym->st_shndx,
                    name);

        } નહીંતર જો (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->data + ELFW(R_SYM)(rel->r_info);
            અચલ અક્ષર *name = s->link->link->data + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (unsigned)rel->r_offset,
                    (unsigned)ELFW(R_TYPE)(rel->r_info),
                    (unsigned)ELFW(R_SYM)(rel->r_info),
                    name);
        } નહીંતર {
            fprintf(f, "   ");
            માટે (n = 0; n < m; ++n) {
                જો (n + i < l) {
                    b = p[i + n];
                    જો (b < 32 || b >= 127)
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

સ્થિર શૂન્ય pe_print_sections(TCCState *s1, અચલ અક્ષર *fname)
{
    Section *s;
    FILE *f;
    પૂર્ણાંક i;
    f = fopen(fname, "w");
    માટે (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    fclose(f);
}
#endif

/* ------------------------------------------------------------- */

ST_FUNC પૂર્ણાંક pe_putimport(TCCState *s1, પૂર્ણાંક dllindex, અચલ અક્ષર *name, addr_t કિંમત)
{
    પાછા set_elf_sym(
        s1->dynsymtab_section,
        કિંમત,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        કિંમત ? SHN_ABS : SHN_UNDEF,
        name
        );
}

સ્થિર પૂર્ણાંક read_mem(પૂર્ણાંક fd, unsigned offset, શૂન્ય *buffer, unsigned len)
{
    lseek(fd, offset, SEEK_SET);
    પાછા len == પઠ(fd, buffer, len);
}

/* ------------------------------------------------------------- */

સ્થિર પૂર્ણાંક get_dllexports(પૂર્ણાંક fd, અક્ષર **pp)
{
    પૂર્ણાંક i, k, l, n, n0, ret;
    અક્ષર *p;

    IMAGE_SECTION_HEADER ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_HEADER dh;
    IMAGE_FILE_HEADER ih;
    DWORD sig, ref, addr;
    DWORD *namep = ખાલી, p0 = 0, p1;

    પૂર્ણાંક pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = ખાલી;
    ret = 1;
    જો (!read_mem(fd, 0, &dh, કદ dh))
        જાઓ the_end;
    જો (!read_mem(fd, dh.e_lfanew, &sig, કદ sig))
        જાઓ the_end;
    જો (sig != 0x00004550)
        જાઓ the_end;
    pef_hdroffset = dh.e_lfanew + કદ sig;
    જો (!read_mem(fd, pef_hdroffset, &ih, કદ ih))
        જાઓ the_end;
    opt_hdroffset = pef_hdroffset + કદ ih;
    જો (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + કદ oh;
        જો (!read_mem(fd, opt_hdroffset, &oh, કદ oh))
            જાઓ the_end;
        જો (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.સંખ્યા_Of_Rva_And_Sizes)
            જાઓ the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } નહીંતર જો (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + કદ oh;
        જો (!read_mem(fd, opt_hdroffset, &oh, કદ oh))
            જાઓ the_end;
        જો (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.સંખ્યા_Of_Rva_And_Sizes)
            જાઓ the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } નહીંતર
        જાઓ the_end;

    //printf("addr: %08x\n", addr);
    માટે (i = 0; i < ih.સંખ્યા_Of_Sections; ++i) {
        જો (!read_mem(fd, sec_hdroffset + i * કદ ish, &ish, કદ ish))
            જાઓ the_end;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        જો (addr >= ish.VirtualAddress && addr < ish.VirtualAddress + ish.SizeOfRawData)
            જાઓ found;
    }
    જાઓ the_end_0;
found:
    ref = ish.VirtualAddress - ish.PointerToRawData;
    જો (!read_mem(fd, addr - ref, &ied, કદ ied))
        જાઓ the_end;
    k = ied.સંખ્યા_Of_Names;
    જો (k) {
        namep = tcc_malloc(l = k * કદ *namep);
        જો (!read_mem(fd, ied.AddressOfNames - ref, namep, l))
            જાઓ the_end;
        માટે (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            જો (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            કરો {
                જો (0 == l) {
                    જો (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    જો ((l = પઠ(fd, p + n, 1000 - 1)) <= 0)
                        જાઓ the_end;
                }
                --l, ++p0;
            } જ્યારે (p[n++]);
        }
        p[n] = 0;
    }
the_end_0:
    ret = 0;
the_end:
    tcc_free(namep);
    જો (ret && p)
        tcc_free(p), p = ખાલી;
    *pp = p;
    પાછા ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

સ્થિર પૂર્ણાંક pe_load_res(TCCState *s1, પૂર્ણાંક fd)
{
    સંરચના pe_rsrc_header hdr;
    Section *rsrc_section;
    પૂર્ણાંક i, ret = -1, sym_index;
    BYTE *ptr;
    unsigned offs;

    જો (!read_mem(fd, 0, &hdr, કદ hdr))
        જાઓ quit;

    જો (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.સંખ્યા_Of_Sections != 1
        || strcmp((અક્ષર*)hdr.sectionhdr.Name, ".rsrc") != 0)
        જાઓ quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_add(rsrc_section, hdr.sectionhdr.SizeOfRawData);
    offs = hdr.sectionhdr.PointerToRawData;
    જો (!read_mem(fd, offs, ptr, hdr.sectionhdr.SizeOfRawData))
        જાઓ quit;
    offs = hdr.sectionhdr.PointerToRelocations;
    sym_index = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_અંક, ".rsrc");
    માટે (i = 0; i < hdr.sectionhdr.સંખ્યા_Of_Relocations; ++i) {
        સંરચના pe_rsrc_reloc rel;
        જો (!read_mem(fd, offs, &rel, કદ rel))
            જાઓ quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        જો (rel.type != RSRC_RELTYPE)
            જાઓ quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.offset, R_XXX_RELATIVE, sym_index);
        offs += કદ rel;
    }
    ret = 0;
quit:
    પાછા ret;
}

/* ------------------------------------------------------------- */

સ્થિર અક્ષર *trimfront(અક્ષર *p)
{
    જ્યારે ((unsigned અક્ષર)*p <= ' ' && *p && *p != '\n')
	++p;
    પાછા p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

સ્થિર અક્ષર *get_token(અક્ષર **s, અક્ષર *f)
{
    અક્ષર *p, *e;
    પૂર્ણાંક q;

    p = trimfront(*s);
    q = *p;
    જો (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    નહીંતર
        q = ' ';
    માટે (e = p; (unsigned અક્ષર)*e >= ' ' && *e != q; ++e)
        ;
    જો (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    પાછા p;
}

સ્થિર પૂર્ણાંક pe_load_def(TCCState *s1, પૂર્ણાંક fd)
{
    પૂર્ણાંક state = 0, ret = -1, dllindex = 0, ord;
    અક્ષર dllname[80], *buf, *લીટી, *p, *x, next;

    buf = tcc_load_text(fd);
    જો (!buf)
        પાછા ret;

    માટે (લીટી = buf;; ++લીટી)  {
        p = get_token(&લીટી, &next);
        જો (!(*p && *p != ';'))
            જાઓ skip;
        પસંદગી (state) {
        સ્થિતિ 0:
            જો (0 != stricmp(p, "LIBRARY") || next == '\n')
                જાઓ quit;
            pstrcpy(dllname, કદ dllname, get_token(&લીટી, &next));
            જો (!*tcc_fileextension(dllname))
                pstrcat(dllname, કદ dllname, ".dll");
            ++state;
            તોડો;
        સ્થિતિ 1:
            જો (0 != stricmp(p, "EXPORTS"))
                જાઓ quit;
            ++state;
            તોડો;
        સ્થિતિ 2:
            dllindex = tcc_add_dllref(s1, dllname, 0)->index;
            ++state;
            /* fall through */
        મૂળભૂત:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            જો (next == '@') {
                x = get_token(&લીટી, &next);
                ord = (પૂર્ણાંક)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            તોડો;
        }
skip:
        જ્યારે ((unsigned અક્ષર)next > ' ')
            get_token(&લીટી, &next);
        જો (next != '\n')
            તોડો;
    }
    ret = 0;
quit:
    tcc_free(buf);
    પાછા ret;
}

/* ------------------------------------------------------------- */

સ્થિર પૂર્ણાંક pe_load_dll(TCCState *s1, પૂર્ણાંક fd, અચલ અક્ષર *filename)
{
    અક્ષર *p, *q;
    DLLReference *ref = tcc_add_dllref(s1, filename, 0);
    જો (ref->found)
        પાછા 0;
    જો (get_dllexports(fd, &p))
        પાછા -1;
    જો (p) {
        માટે (q = p; *q; q += 1 + strlen(q))
            pe_putimport(s1, ref->index, q, 0);
        tcc_free(p);
    }
    પાછા 0;
}

ST_FUNC પૂર્ણાંક pe_load_file(સંરચના TCCState *s1, પૂર્ણાંક fd, અચલ અક્ષર *filename)
{
    પૂર્ણાંક ret = -1;
    અક્ષર buf[10];
    જો (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_load_def(s1, fd);
    નહીંતર જો (pe_load_res(s1, fd) == 0)
        ret = 0;
    નહીંતર જો (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_load_dll(s1, fd, filename);
    પાછા ret;
}

PUB_FUNC પૂર્ણાંક tcc_get_dllexports(અચલ અક્ષર *filename, અક્ષર **pp)
{
    પૂર્ણાંક ret, fd = open(filename, O_RDONLY | O_દ્વિઅંકી_2);
    જો (fd < 0)
        પાછા -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    પાછા ret;
}

/* ------------------------------------------------------------- */
#ifdef TCC_TARGET_X86_64
સ્થિર unsigned pe_add_unwind_info(TCCState *s1)
{
    જો (ખાલી == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    જો (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, text_section->sh_અંક, ".uw_base");
    જો (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        સ્થિર અચલ unsigned અક્ષર uw_info[] = {
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
        unsigned અક્ષર *p;

        section_ptr_add(s, -s->data_offset & 3); /* align */
        s1->uw_offs = s->data_offset;
        p = section_ptr_add(s, કદ uw_info);
        memcpy(p, uw_info, કદ uw_info);
    }

    પાછા s1->uw_offs;
}

ST_FUNC શૂન્ય pe_add_unwind_data(unsigned start, unsigned end, unsigned ઢગલો)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    unsigned o, n, d;
    સંરચના /* _RUNTIME_FUNCTION */ {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD UnwindData;
    } *p;

    d = pe_add_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->data_offset;
    p = section_ptr_add(pd, કદ *p);

    /* record this function */
    p->BeginAddress = start;
    p->EndAddress = end;
    p->UnwindData = d;

    /* put relocations on it */
    માટે (n = o + કદ *p; o < n; o += કદ p->BeginAddress)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#અથવાજો defined(TCC_TARGET_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
સ્થિર Section *pe_add_unwind_info(TCCState *s1)
{
    Section *s;

    જો (ખાલી == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = find_section(s1, ".xdata");
    s->sh_addralign = 4;
    જો (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  text_section->sh_અંક, ".uw_text_base");
    જો (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_અંક, ".uw_base");
    પાછા s;
}

ST_FUNC શૂન્ય pe_add_unwind_data(unsigned start, unsigned end, unsigned ઢગલો)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    unsigned o, d, code_bytes, func_len;
    unsigned અક્ષર *q;
    uint32_t header;
    સંરચના /* _RUNTIME_FUNCTION */ {
        DWORD BeginAddress;
        DWORD UnwindData;
    } *p;

    પૂર્ણાંક epilog;

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
    જ્યારે ((unsigned)(q - (xd->data + d + 4)) < code_bytes)
        *q++ = 0xE3; /* nop padding */

    o = pd->data_offset;
    p = section_ptr_add(pd, કદ *p);
    p->BeginAddress = start;
    p->UnwindData = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#endif
/* ------------------------------------------------------------- */
#જો defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
#define PE_STDSYM(n,s) n
#નહીંતર
#define PE_STDSYM(n,s) "_" n s
#endif

સ્થિર શૂન્ય pe_add_runtime(TCCState *s1, સંરચના pe_info *pe)
{
    અચલ અક્ષર *start_પ્રતીક;
    પૂર્ણાંક pe_type;

    જો (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        start_પ્રતીક = PE_STDSYM("__dllstart","@12");
    } નહીંતર {
        અચલ અક્ષર *run_પ્રતીક;
        જો (find_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            start_પ્રતીક = "__winstart";
            run_પ્રતીક = "__runwinmain";
            pe_type = PE_GUI;
        } નહીંતર જો (find_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            start_પ્રતીક = "__wwinstart";
            run_પ્રતીક = "__runwwinmain";
            pe_type = PE_GUI;
        } નહીંતર જો (find_elf_sym(symtab_section, "wmain")) {
            start_પ્રતીક = "__wstart";
            run_પ્રતીક = "__runwmain";
            pe_type = PE_EXE;
        } નહીંતર {
            start_પ્રતીક =  "__start";
            run_પ્રતીક = "__runmain";
            pe_type = PE_EXE;
            જો (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        જો (TCC_OUTPUT_MEMORY == s1->output_type && !s1->nostdlib)
            start_પ્રતીક = run_પ્રતીક;
    }
    જો (s1->elf_entryname) {
        pe->start_પ્રતીક = start_પ્રતીક = s1->elf_entryname;
    } નહીંતર {
        pe->start_પ્રતીક = start_પ્રતીક + 1;
        જો (!s1->leading_underscore || strchr(start_પ્રતીક, '@'))
            ++start_પ્રતીક;
    }

#ifdef CONFIG_TCC_BACKTRACE
    જો (s1->do_backtrace) {
#ifdef CONFIG_TCC_BCHECK
        જો (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    જો (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    નહીંતર
                tcc_add_support(s1, "bcheck.o");
	}
#endif
        જો (s1->output_type == TCC_OUTPUT_EXE)
            tcc_add_support(s1, "bt-exe.o");
        જો (s1->output_type == TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-dll.o");
        જો (s1->output_type != TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-log.o");
        tcc_add_btstub(s1);
    }
#endif

    /* grab the startup code from libtcc1.a */
#ifdef TCC_IS_NATIVE
    જો (TCC_OUTPUT_MEMORY != s1->output_type || s1->run_main)
#endif
    set_global_sym(s1, start_પ્રતીક, ખાલી, 0);

    જો (0 == s1->nostdlib) {
        સ્થિર અચલ અક્ષર * અચલ libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", ખાલી
        };
        અચલ અક્ષર * અચલ *pp, *p;
        જો (TCC_LIBTCC1[0])
            tcc_add_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        માટે (pp = libs; 0 != (p = *pp); ++pp) {
            જો (*p)
                tcc_add_library(s1, p);
            નહીંતર જો (PE_DLL != pe_type && PE_GUI != pe_type)
                તોડો;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    જો (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    જો (TCC_OUTPUT_MEMORY == s1->output_type)
        pe_type = PE_RUN;
    pe->type = pe_type;
}

ST_FUNC પૂર્ણાંક pe_setsubsy(TCCState *s1, અચલ અક્ષર *arg)
{
    સ્થિર અચલ સંરચના subsy { અચલ અક્ષર* p; પૂર્ણાંક v; } x[] = {
#જો defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#અથવાજો defined(TCC_TARGET_ARM)
        { "wince", 9 },
#endif
        { 0, -1 }};
    અચલ સંરચના subsy *y;
    માટે (y = x;; ++y) {
        જો (!y->p)
            પાછા -1;
        જો (0 == strcmp(y->p, arg)) {
            s1->pe_subsystem = y->v;
            પાછા 0;
        }
    }
}

સ્થિર શૂન્ય pe_set_options(TCCState * s1, સંરચના pe_info *pe)
{
    જો (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_BASE_DLL;
    } નહીંતર {
        pe->imagebase = IMAGE_BASE_EXE;
    }

#જો defined(TCC_TARGET_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#નહીંતર
    જો (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    નહીંતર
        pe->subsystem = 3;
#endif
    /* Allow override via -Wl,-subsystem=... option */
    જો (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    જો (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } નહીંતર {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    જો (s1->section_align != 0)
        pe->section_align = s1->section_align;
    જો (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    જો ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    જો (s1->has_text_addr)
        pe->imagebase = s1->text_addr;
}

ST_FUNC પૂર્ણાંક pe_output_file(TCCState *s1, અચલ અક્ષર *filename)
{
    સંરચના pe_info pe;

    memset(&pe, 0, કદ pe);
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
    જો (s1->nb_errors)
        જાઓ done;
    જો (filename) {
        pe_assign_addresses(&pe);
        relocate_syms(s1, s1->symtab, 0);
        જો (s1->nb_errors)
            જાઓ done;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.start_addr = (DWORD)
            (get_sym_addr(s1, pe.start_પ્રતીક, 1, 1) - pe.imagebase);
        જો (s1->nb_errors)
            જાઓ done;
        pe_write(&pe);
    } નહીંતર {
        /* -run */
#ifdef TCC_IS_NATIVE
        pe.thunk = data_section;
        pe_build_imports(&pe);
        s1->run_main = pe.start_પ્રતીક;
#જો defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        s1->uw_pdata = find_section(s1, ".pdata");
#endif
#endif
    }
done:
    dynarray_reset(&pe.sec_info, &pe.sec_ગણતરી);
    pe_free_imports(&pe);
#જો PE_PRINT_SECTIONS
    જો (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#endif
    પાછા s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
