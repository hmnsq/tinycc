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

#समावेश "tcc.h"

#घोषणा PE_MERGE_तथ्य 1
#घोषणा PE_PRINT_SECTIONS 0

#अगर_अघोषित _WIN32
#घोषणा stricmp strcasecmp
#घोषणा strnicmp strncasecmp
#समावेश <sys/stat.h> /* chmod() */
#पूर्ण_अगर

#अगर defined TCC_TARGET_X86_64
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

#या_अगर defined TCC_TARGET_ARM
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

#या_अगर defined TCC_TARGET_ARM64
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

#या_अगर defined TCC_TARGET_I386
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
#पूर्ण_अगर

#अगर PTR_आकार == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#अन्यथा
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#पूर्ण_अगर

#अगर_अघोषित IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

प्रकार अचिन्हित अक्षर BYTE;
प्रकार अचिन्हित लघु WORD;
प्रकार अचिन्हित पूर्णांक DWORD;
प्रकार अचिन्हित दीर्घ दीर्घ ULONGLONG;
#आशय pack(धकेलो, 1)

प्रकार काष्ठा _IMAGE_DOS_HEADER {  /* DOS .EXE header */
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

#घोषणा IMAGE_NT_SIGNATURE  0x00004550  /* PE00 */

प्रकार काष्ठा _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    संख्या_Of_Sections;
    DWORD   TimeDateStamp;
    DWORD   Pointer_To_प्रतीक_Table;
    DWORD   संख्या_Of_Symbols;
    WORD    आकार_Of_Optional_Header;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;


#घोषणा IMAGE_SIZEOF_FILE_HEADER 20

प्रकार काष्ठा IMAGE_तथ्य_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   आकार_3;
} IMAGE_तथ्य_DIRECTORY_2, *PIMAGE_तथ्य_DIRECTORY;


प्रकार काष्ठा _IMAGE_OPTIONAL_HEADER {
    /* Standard fields. */
    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   आकार_Of_Code;
    DWORD   आकार_Of_Initialized_तथ्य;
    DWORD   आकार_Of_Uninitialized_तथ्य;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
#अगर PTR_आकार == 4
    DWORD   Base_Of_तथ्य;
#पूर्ण_अगर
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
    DWORD   Win32_Version_मूल्य;
    DWORD   आकार_Of_Image;
    DWORD   आकार_Of_Headers;
    DWORD   Check_योग;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    ADDR3264 आकार_Of_ढेर_Reserve;
    ADDR3264 आकार_Of_ढेर_Commit;
    ADDR3264 आकार_Of_Heap_Reserve;
    ADDR3264 आकार_Of_Heap_Commit;
    DWORD   LoaderFlags;
    DWORD   संख्या_Of_Rva_And_Sizes;
    IMAGE_तथ्य_DIRECTORY_2 तथ्य_Directory[16];
} IMAGE_OPTIONAL_HEADER32, IMAGE_OPTIONAL_HEADER64, IMAGE_OPTIONAL_HEADER;

#घोषणा IMAGE_DIRECTORY_ENTRY_EXPORT          0   /* Export Directory */
#घोषणा IMAGE_DIRECTORY_ENTRY_IMPORT          1   /* Import Directory */
#घोषणा IMAGE_DIRECTORY_ENTRY_RESOURCE        2   /* Resource Directory */
#घोषणा IMAGE_DIRECTORY_ENTRY_EXCEPTION       3   /* Exception Directory */
#घोषणा IMAGE_DIRECTORY_ENTRY_SECURITY        4   /* Security Directory */
#घोषणा IMAGE_DIRECTORY_ENTRY_BASERELOC       5   /* Base Relocation Table */
#घोषणा IMAGE_DIRECTORY_ENTRY_DEBUG           6   /* Debug Directory */
/*      IMAGE_DIRECTORY_ENTRY_COPYRIGHT       7      (X86 usage) */
#घोषणा IMAGE_DIRECTORY_ENTRY_ARCHITECTURE    7   /* Architecture Specific Data */
#घोषणा IMAGE_DIRECTORY_ENTRY_GLOBALPTR       8   /* RVA of GP */
#घोषणा IMAGE_DIRECTORY_ENTRY_TLS             9   /* TLS Directory */
#घोषणा IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG    10   /* Load Configuration Directory */
#घोषणा IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT   11   /* Bound Import Directory in headers */
#घोषणा IMAGE_DIRECTORY_ENTRY_IAT            12   /* Import Address Table */
#घोषणा IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT   13   /* Delay Load Import Descriptors */
#घोषणा IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR 14   /* COM Runtime descriptor */

/* Section header format. */
#घोषणा IMAGE_SIZEOF_SHORT_NAME         8

प्रकार काष्ठा _IMAGE_SECTION_HEADER {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    जोड़ {
            DWORD   PhysicalAddress;
            DWORD   Virtual_आकार;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   आकार_Of_Raw_तथ्य;
    DWORD   Pointer_To_Raw_तथ्य;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    संख्या_Of_Relocations;
    WORD    संख्या_Of_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#घोषणा IMAGE_SIZEOF_SECTION_HEADER     40

प्रकार काष्ठा _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD Name;
    DWORD Base;
    DWORD संख्या_Of_Functions;
    DWORD संख्या_Of_Names;
    DWORD AddressOfFunctions;
    DWORD AddressOfNames;
    DWORD AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

प्रकार काष्ठा _IMAGE_TLS_DIRECTORY {
    ADDR3264 Start_Address_Of_Raw_तथ्य;
    ADDR3264 End_Address_Of_Raw_तथ्य;
    ADDR3264 Address_Of_सूचकांक;
    ADDR3264 AddressOfCallBacks;
    DWORD आकार_Of_Zero_Fill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

प्रकार काष्ठा _IMAGE_IMPORT_DESCRIPTOR {
    जोड़ {
        DWORD Characteristics;
        DWORD OriginalFirstThunk;
    };
    DWORD TimeDateStamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;

प्रकार काष्ठा _IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   आकार_Of_Block;
//  WORD    TypeOffset[1];
} IMAGE_BASE_RELOCATION;

#घोषणा IMAGE_SIZEOF_BASE_RELOCATION     8

#घोषणा IMAGE_REL_BASED_ABSOLUTE         0
#घोषणा IMAGE_REL_BASED_ऊपरी             1
#घोषणा IMAGE_REL_BASED_निचला              2
#घोषणा IMAGE_REL_BASED_HIGHLOW          3
#घोषणा IMAGE_REL_BASED_HIGHADJ          4
#घोषणा IMAGE_REL_BASED_MIPS_JMPADDR     5
#घोषणा IMAGE_REL_BASED_SECTION          6
#घोषणा IMAGE_REL_BASED_REL32            7
#घोषणा IMAGE_REL_BASED_DIR64           10

#घोषणा IMAGE_SCN_CNT_CODE                  0x00000020
#घोषणा IMAGE_SCN_CNT_INITIALIZED_तथ्य      0x00000040
#घोषणा IMAGE_SCN_CNT_UNINITIALIZED_तथ्य    0x00000080
#घोषणा IMAGE_SCN_MEM_DISCARDABLE           0x02000000
#घोषणा IMAGE_SCN_MEM_SHARED                0x10000000
#घोषणा IMAGE_SCN_MEM_EXECUTE               0x20000000
#घोषणा IMAGE_SCN_MEM_READ                  0x40000000
#घोषणा IMAGE_SCN_MEM_WRITE                 0x80000000

#घोषणा IMAGE_DLLCHARACTERISTICS_ऊपरी_ENTROPY_VA 0x0020
#घोषणा IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#घोषणा IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#घोषणा IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#घोषणा IMAGE_FILE_RELOCS_STRIPPED 0x0001

#आशय pack(निकालो)

/* ----------------------------------------------------------- */
#पूर्ण_अगर /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#अगर_अघोषित IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #घोषणा IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#पूर्ण_अगर

#आशय pack(धकेलो, 1)
काष्ठा pe_header
{
    IMAGE_DOS_HEADER doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_HEADER filehdr;
#अगर PTR_आकार == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#अन्यथा
#अगर_घोषित _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#अन्यथा
    IMAGE_OPTIONAL_HEADER opthdr;
#पूर्ण_अगर
#पूर्ण_अगर
};

काष्ठा pe_reloc_header {
    DWORD offset;
    DWORD आकार;
};

काष्ठा pe_rsrc_header {
    काष्ठा _IMAGE_FILE_HEADER filehdr;
    काष्ठा _IMAGE_SECTION_HEADER sectionhdr;
};

काष्ठा pe_rsrc_reloc {
    DWORD offset;
    DWORD आकार;
    WORD type;
};
#आशय pack(निकालो)

/* ------------------------------------------------------------- */
/* internal temporary structures */

क्रमागत {
    sec_text = 0,
    sec_rdata ,
    sec_तथ्य ,
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

#अगर 0
अटल स्थिर DWORD pe_sec_flags[] = {
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
#पूर्ण_अगर

काष्ठा section_info {
    पूर्णांक cls;
    अक्षर name[32];
    ADDR3264 sh_addr;
    DWORD sh_आकार;
    DWORD pe_flags;
    Section *sec;
    DWORD तथ्य_आकार;
    IMAGE_SECTION_HEADER ish;
};

काष्ठा import_प्रतीक {
    पूर्णांक sym_सूचकांक;
    पूर्णांक iat_सूचकांक;
    पूर्णांक thk_offset;
};

काष्ठा pe_import_info {
    पूर्णांक dll_सूचकांक;
    पूर्णांक sym_गिनती;
    काष्ठा import_प्रतीक **symbols;
};

काष्ठा pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    स्थिर अक्षर *filename;
    पूर्णांक type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    स्थिर अक्षर *start_प्रतीक;
    DWORD start_addr;
    DWORD imp_offs;
    DWORD imp_आकार;
    DWORD iat_offs;
    DWORD iat_आकार;
    DWORD exp_offs;
    DWORD exp_आकार;
    DWORD tls_dir;
    DWORD tls_तथ्य;
    DWORD tls_आकार;
    पूर्णांक subsystem;
    DWORD section_align;
    DWORD file_align;
    काष्ठा section_info **sec_info;
    पूर्णांक sec_गिनती;
    काष्ठा pe_import_info **imp_info;
    पूर्णांक imp_गिनती;
    /* output */
    खाता *op;
    DWORD योग;
    अचिन्हित pos;
};

#घोषणा PE_NUL 0
#घोषणा PE_DLL 1
#घोषणा PE_GUI 2
#घोषणा PE_EXE 3
#घोषणा PE_RUN 4

/* --------------------------------------------*/

अटल स्थिर अक्षर *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    स्थिर अक्षर *name = (अक्षर*)symtab_section->link->तथ्य + sym->st_name;
    अगर (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        वापस name + 1;
    वापस name;
}


अटल पूर्णांक dynarray_assoc(व्योम **pp, पूर्णांक n, पूर्णांक कुंजी)
{
    पूर्णांक i;
    क्रम (i = 0; i < n; ++i, ++pp)
    अगर (कुंजी == **(पूर्णांक **) pp)
        वापस i;
    वापस -1;
}

अटल DWORD umin(DWORD a, DWORD b)
{
    वापस a < b ? a : b;
}

अटल DWORD umax(DWORD a, DWORD b)
{
    वापस a < b ? b : a;
}

अटल DWORD pe_file_align(काष्ठा pe_info *pe, DWORD n)
{
    वापस (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

अटल ADDR3264 pe_virtual_align(काष्ठा pe_info *pe, ADDR3264 n)
{
    वापस (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

अटल व्योम pe_align_section(Section *s, पूर्णांक a)
{
    पूर्णांक i = s->तथ्य_offset & (a-1);
    अगर (i)
        section_ptr_add(s, a - i);
}

अटल व्योम pe_set_datadir(काष्ठा pe_header *hdr, पूर्णांक dir, DWORD addr, DWORD आकार)
{
    hdr->opthdr.तथ्य_Directory[dir].VirtualAddress = addr;
    hdr->opthdr.तथ्य_Directory[dir].आकार_3 = आकार;
}

अटल पूर्णांक pe_fwrite(काष्ठा pe_info *pe, स्थिर व्योम *तथ्य, पूर्णांक len)
{
    स्थिर WORD *p = तथ्य;
    DWORD योग;
    पूर्णांक ret, i;
    pe->pos += (ret = ख_डालो(तथ्य, 1, len, pe->op));
    योग = pe->योग;
    क्रम (i = len; i > 0; i -= 2) {
        योग += (i >= 2) ? *p++ : *(BYTE*)p;
        योग = (योग + (योग >> 16)) & 0xFFFF;
    }
    pe->योग = योग;
    वापस len == ret ? 0 : -1;
}

अटल व्योम pe_fpad(काष्ठा pe_info *pe, DWORD new_pos)
{
    अक्षर buf[256];
    पूर्णांक n, diff = new_pos - pe->pos;
    स_रखो(buf, 0, माप buf);
    जबतक (diff > 0) {
        diff -= n = umin(diff, माप buf);
        ख_डालो(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#आशय pack(धकेलो, 1)
काष्ठा syment
{
    जोड़ {
        अक्षर        n_name[8];     /* old COFF version */
        काष्ठा {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_offset;      /* offset into string table */
        };
    };
    int32_t         n_मूल्य;        /* value of symbol */
    लघु           n_scnum;        /* section number */
    अचिन्हित लघु  n_type;         /* type and derived type */
    अक्षर            n_sclass;       /* storage class */
    अक्षर            n_numaux;       /* number of aux. entries */
};
#आशय pack(निकालो)

#घोषणा SHF_PRIVATE 0x80000000

अटल व्योम pe_add_coffsym(काष्ठा pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    काष्ठा syment *se;
    पूर्णांक n;

    अगर (शून्य == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_PRIVATE);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_PRIVATE);
        section_ptr_add(pe->coffstr, 4); /* coff string table size */
        वापस;
    }

#अगर 0
    se = section_ptr_add(pe->coffsym, माप *se);
    म_नकल(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_add(pe->coffsym, माप *se);
    म_नकल((अक्षर*)se, "no-file");
#पूर्ण_अगर

#अगर 1
    esym = (ElfSym*)s1->symtab->तथ्य;
    क्रम (n = s1->symtab->तथ्य_offset / माप *esym; ++esym, --n;) {
        पूर्णांक sym_bind = ELFW(ST_BIND)(esym->st_info);
        अगर (sym_bind == STB_GLOBAL) {
            अक्षर *name = esym->st_name + (अक्षर*)s1->symtab->link->तथ्य;
            पूर्णांक nl = म_माप(name);
            addr_t मूल्य = esym->st_मूल्य;
            पूर्णांक shnum = esym->st_shndx;
            अगर (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                मूल्य = मूल्य - s->sh_addr;
            }
            se = section_ptr_add(pe->coffsym, माप *se);
            se->n_मूल्य = मूल्य;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            अगर (nl <= 8)
                स_नकल(se->n_name, name, nl);
            अन्यथा
                se->n_offset = put_elf_str(pe->coffstr, name);
        }
    }
#पूर्ण_अगर
    write32le(pe->coffstr->तथ्य, pe->coffstr->तथ्य_offset); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
अटल व्योम pe_create_pdb(TCCState *s1, स्थिर अक्षर *exename)
{
    अक्षर buf[300]; पूर्णांक r;
    snprintf(buf, माप buf, "cv2pdb.exe \"%s\"", exename);
    r = प्रणाली(buf);
    म_नकल(tcc_fileextension(म_नकल(buf, exename)), ".pdb");
    अगर (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } अन्यथा अगर (s1->verbose) {
        म_लिखो("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
अटल पूर्णांक pe_write(काष्ठा pe_info *pe)
{
    अटल स्थिर काष्ठा pe_header pe_template = {
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
    0x00E0 + (PTR_आकार-4)*4, /*WORD    SizeOfOptionalHeader; */
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
#अगर PTR_आकार == 4
    0x00000000, /*DWORD   BaseOfData; */
#पूर्ण_अगर
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

    काष्ठा pe_header pe_header = pe_template;

    पूर्णांक i;
    DWORD file_offset;
    काष्ठा section_info *si;
    IMAGE_SECTION_HEADER *psh;
    TCCState *s1 = pe->s1;

    अगर (s1->do_debug)
        pe_add_coffsym(pe);

    pe->op = ख_खोलो(pe->filename, "wb");
    अगर (शून्य == pe->op)
        वापस tcc_error_noabort("could not write '%s': %s", pe->filename, म_त्रुटि(त्रुटि_सं));

    pe->sizeofheaders = pe_file_align(pe,
        माप (काष्ठा pe_header)
        + pe->sec_गिनती * माप (IMAGE_SECTION_HEADER)
        );

    file_offset = pe->sizeofheaders;

    अगर (2 == s1->verbose)
        म_लिखो("-------------------------------"
               "\n  virt   file   size  section" "\n");
    क्रम (i = 0; i < pe->sec_गिनती; ++i) {
        DWORD addr, आकार;
        स्थिर अक्षर *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        आकार = si->sh_आकार;
        psh = &si->ish;

        अगर (2 == s1->verbose)
            म_लिखो("%6x %6x %6x  %s\n",
                (अचिन्हित)addr, (अचिन्हित)file_offset, (अचिन्हित)आकार, sh_name);

        चयन (si->cls) {
            हाल sec_text:
                अगर (!pe_header.opthdr.BaseOfCode)
                    pe_header.opthdr.BaseOfCode = addr;
                अवरोध;

            हाल sec_तथ्य:
#अगर PTR_आकार == 4
                अगर (!pe_header.opthdr.Base_Of_तथ्य)
                    pe_header.opthdr.Base_Of_तथ्य = addr;
#पूर्ण_अगर
                अवरोध;

            हाल sec_bss:
                अवरोध;

            हाल sec_reloc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_BASERELOC, addr, आकार);
                अवरोध;

            हाल sec_rsrc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_RESOURCE, addr, आकार);
                अवरोध;

            हाल sec_pdata:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXCEPTION, addr, आकार);
                अवरोध;
        }

        अगर (pe->imp_आकार) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IMPORT,
                pe->imp_offs, pe->imp_आकार);
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IAT,
                pe->iat_offs, pe->iat_आकार);
        }
        अगर (pe->exp_आकार) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXPORT,
                pe->exp_offs, pe->exp_आकार);
        }
        अगर (pe->tls_आकार) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_आकार);
        }

        स_नकल(psh->Name, sh_name, umin(म_माप(sh_name), माप psh->Name));
        अगर (pe->coffstr && म_माप(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((अक्षर*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->VirtualAddress = addr;
        psh->Misc.Virtual_आकार = आकार;
        pe_header.opthdr.आकार_Of_Image =
            umax(pe_virtual_align(pe, आकार + addr), pe_header.opthdr.आकार_Of_Image);

        अगर (si->तथ्य_आकार) {
            psh->Pointer_To_Raw_तथ्य = file_offset;
            file_offset = pe_file_align(pe, file_offset + si->तथ्य_आकार);
            psh->आकार_Of_Raw_तथ्य = file_offset - psh->Pointer_To_Raw_तथ्य;
            अगर (si->cls == sec_text)
                pe_header.opthdr.आकार_Of_Code += psh->आकार_Of_Raw_तथ्य;
            अन्यथा
                pe_header.opthdr.आकार_Of_Initialized_तथ्य += psh->आकार_Of_Raw_तथ्य;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_header.filehdr.संख्या_Of_Sections = pe->sec_गिनती;
    pe_header.opthdr.AddressOfEntryPoint = pe->start_addr;
    pe_header.opthdr.आकार_Of_Headers = pe->sizeofheaders;
    pe_header.opthdr.ImageBase = pe->imagebase;
    pe_header.opthdr.Subsystem = pe->subsystem;
    pe_header.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    अगर (s1->pe_ढेर_आकार)
        pe_header.opthdr.आकार_Of_ढेर_Reserve = s1->pe_ढेर_आकार;
    अगर (PE_DLL == pe->type)
        pe_header.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_header.filehdr.Characteristics |= s1->pe_characteristics;
    अगर (pe->reloc)
        pe_header.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    अगर (pe->coffsym) {
        pe_add_coffsym(pe);
        pe_header.filehdr.Pointer_To_प्रतीक_Table = file_offset;
        pe_header.filehdr.संख्या_Of_Symbols
            = pe->coffsym->तथ्य_offset / माप (काष्ठा syment);
    }

    pe_fwrite(pe, &pe_header, माप pe_header);
    क्रम (i = 0; i < pe->sec_गिनती; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, माप(IMAGE_SECTION_HEADER));

    file_offset = pe->sizeofheaders;
    क्रम (i = 0; i < pe->sec_गिनती; ++i) {
        Section *s;
        si = pe->sec_info[i];
        अगर (!si->तथ्य_आकार)
            जारी;
        क्रम (s = si->sec; s; s = s->पूर्व) {
            pe_fpad(pe, file_offset);
            pe_fwrite(pe, s->तथ्य, s->तथ्य_offset);
            अगर (s->पूर्व)
                file_offset += s->पूर्व->sh_addr - s->sh_addr;
        }
        file_offset = si->ish.Pointer_To_Raw_तथ्य + si->ish.आकार_Of_Raw_तथ्य;
        pe_fpad(pe, file_offset);
    }

    अगर (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->तथ्य, pe->coffsym->तथ्य_offset);
        pe_fwrite(pe, pe->coffstr->तथ्य, pe->coffstr->तथ्य_offset);
        file_offset = pe->pos;
    }

    pe->योग += file_offset;
    ख_जाओ(pe->op, दुरत्व(काष्ठा pe_header, opthdr.Check_योग), शुरू_से);
    pe_fwrite(pe, &pe->योग, माप (DWORD));

    ख_बंद (pe->op);
#अगर_अघोषित _WIN32
    chmod(pe->filename, 0777);
#पूर्ण_अगर

    अगर (2 == s1->verbose)
        म_लिखो("-------------------------------\n");
    अगर (s1->verbose)
        म_लिखो("<- %s (%u bytes)\n", pe->filename, (अचिन्हित)file_offset);

    अगर (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    वापस 0;
}

/*----------------------------------------------------------------------------*/

अटल काष्ठा import_प्रतीक *pe_add_import(काष्ठा pe_info *pe, पूर्णांक sym_सूचकांक)
{
    पूर्णांक i;
    पूर्णांक dll_सूचकांक;
    काष्ठा pe_import_info *p;
    काष्ठा import_प्रतीक *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->तथ्य + sym_सूचकांक;
    dll_सूचकांक = isym->st_आकार;

    i = dynarray_assoc ((व्योम**)pe->imp_info, pe->imp_गिनती, dll_सूचकांक);
    अगर (-1 != i) {
        p = pe->imp_info[i];
        जाओ found_dll;
    }
    p = tcc_mallocz(माप *p);
    p->dll_सूचकांक = dll_सूचकांक;
    dynarray_add(&pe->imp_info, &pe->imp_गिनती, p);

found_dll:
    i = dynarray_assoc ((व्योम**)p->symbols, p->sym_गिनती, sym_सूचकांक);
    अगर (-1 != i)
        वापस p->symbols[i];

    s = tcc_mallocz(माप *s);
    dynarray_add(&p->symbols, &p->sym_गिनती, s);
    s->sym_सूचकांक = sym_सूचकांक;
    वापस s;
}

अटल व्योम pe_free_imports(काष्ठा pe_info *pe)
{
    पूर्णांक i;
    क्रम (i = 0; i < pe->imp_गिनती; ++i) {
        काष्ठा pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_गिनती);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_गिनती);
}

/*----------------------------------------------------------------------------*/
अटल व्योम pe_build_imports(काष्ठा pe_info *pe)
{
    पूर्णांक thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_base = pe->thunk->sh_addr - pe->imagebase;
    पूर्णांक ndlls = pe->imp_गिनती;
    TCCState *s1 = pe->s1;

    क्रम (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_गिनती;

    अगर (0 == sym_cnt)
        वापस;

    pe_align_section(pe->thunk, 16);
    pe->imp_आकार = (ndlls + 1) * माप(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_आकार = (sym_cnt + ndlls) * माप(ADDR3264);
    dll_ptr = pe->thunk->तथ्य_offset;
    thk_ptr = dll_ptr + pe->imp_आकार;
    ent_ptr = thk_ptr + pe->iat_आकार;
    pe->imp_offs = dll_ptr + rva_base;
    pe->iat_offs = thk_ptr + rva_base;
    section_ptr_add(pe->thunk, pe->imp_आकार + 2*pe->iat_आकार);

    क्रम (i = 0; i < pe->imp_गिनती; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        पूर्णांक k, n, dllindex;
        ADDR3264 v;
        काष्ठा pe_import_info *p = pe->imp_info[i];
        स्थिर अक्षर *name;
        DLLReference *dllref;

        dllindex = p->dll_सूचकांक;
        अगर (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        अन्यथा
            name = "", dllref = शून्य;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->तथ्य + dll_ptr);
        hdr->FirstThunk = thk_ptr + rva_base;
        hdr->OriginalFirstThunk = ent_ptr + rva_base;
        hdr->Name = v + rva_base;

        क्रम (k = 0, n = p->sym_गिनती; k <= n; ++k) {
            अगर (k < n) {
                पूर्णांक iat_सूचकांक = p->symbols[k]->iat_सूचकांक;
                पूर्णांक sym_सूचकांक = p->symbols[k]->sym_सूचकांक;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->तथ्य + sym_सूचकांक;
                स्थिर अक्षर *name = (अक्षर*)s1->dynsymtab_section->link->तथ्य + imp_sym->st_name;
                पूर्णांक ordinal;

                /* patch symbol (and possibly its underscored alias) */
                करो {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->तथ्य + iat_सूचकांक;
                    iat_सूचकांक = esym->st_मूल्य;
                    esym->st_मूल्य = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_अंक;
                } जबतक (iat_सूचकांक);

                अगर (dllref)
                    v = 0, ordinal = imp_sym->st_मूल्य; /* ordinal from pe_load_def */
                अन्यथा
                    ordinal = 0, v = imp_sym->st_मूल्य; /* address from tcc_add_symbol() */

#अगर_घोषित TCC_IS_NATIVE
                अगर (pe->type == PE_RUN) {
                    अगर (dllref) {
                        अगर ( !dllref->handle )
                            dllref->handle = LoadLibraryA(dllref->name);
                        v = (ADDR3264)GetProcAddress(dllref->handle, ordinal?(अक्षर*)0+ordinal:name);
                    }
                    अगर (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } अन्यथा
#पूर्ण_अगर
                अगर (ordinal) {
                    v = ordinal | (ADDR3264)1 << (माप(ADDR3264)*8 - 1);
                } अन्यथा {
                    v = pe->thunk->तथ्य_offset + rva_base;
                    section_ptr_add(pe->thunk, माप(WORD)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } अन्यथा {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->तथ्य+thk_ptr) =
            *(ADDR3264*)(pe->thunk->तथ्य+ent_ptr) = v;
            thk_ptr += माप (ADDR3264);
            ent_ptr += माप (ADDR3264);
        }
        dll_ptr += माप(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

काष्ठा pe_sort_sym
{
    पूर्णांक सूचकांक;
    स्थिर अक्षर *name;
};

अटल पूर्णांक sym_cmp(स्थिर व्योम *va, स्थिर व्योम *vb)
{
    स्थिर अक्षर *ca = (*(काष्ठा pe_sort_sym**)va)->name;
    स्थिर अक्षर *cb = (*(काष्ठा pe_sort_sym**)vb)->name;
    वापस म_भेद(ca, cb);
}

अटल व्योम pe_build_exports(काष्ठा pe_info *pe)
{
    ElfW(Sym) *sym;
    पूर्णांक sym_सूचकांक, sym_end;
    DWORD rva_base, base_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    पूर्णांक sym_गिनती, ord;
    काष्ठा pe_sort_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    खाता *op;
    अक्षर buf[260];
    स्थिर अक्षर *dllname;
    स्थिर अक्षर *name;

    rva_base = pe->thunk->sh_addr - pe->imagebase;
    sym_गिनती = 0, sorted = शून्य, op = शून्य;

    sym_end = symtab_section->तथ्य_offset / माप(ElfW(Sym));
    क्रम (sym_सूचकांक = 1; sym_सूचकांक < sym_end; ++sym_सूचकांक) {
        sym = (ElfW(Sym)*)symtab_section->तथ्य + sym_सूचकांक;
        name = pe_export_name(s1, sym);
        अगर (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(माप *p);
            p->सूचकांक = sym_सूचकांक;
            p->name = name;
            dynarray_add(&sorted, &sym_गिनती, p);
        }
#अगर 0
        अगर (sym->st_other & ST_PE_EXPORT)
            म_लिखो("export: %s\n", name);
        अगर (sym->st_other & ST_PE_STDCALL)
            म_लिखो("stdcall: %s\n", name);
#पूर्ण_अगर
    }

    अगर (0 == sym_गिनती)
        वापस;

    क्विक (sorted, sym_गिनती, माप *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    base_o = pe->thunk->तथ्य_offset;
    func_o = base_o + माप(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_गिनती * माप (DWORD);
    ord_o = name_o + sym_गिनती * माप (DWORD);
    str_o = ord_o + sym_गिनती * माप(WORD);

    hdr = section_ptr_add(pe->thunk, str_o - base_o);
    hdr->Characteristics        = 0;
    hdr->Base                   = 1;
    hdr->संख्या_Of_Functions      = sym_गिनती;
    hdr->संख्या_Of_Names          = sym_गिनती;
    hdr->AddressOfFunctions     = func_o + rva_base;
    hdr->AddressOfNames         = name_o + rva_base;
    hdr->AddressOfNameOrdinals  = ord_o + rva_base;
    hdr->Name                   = str_o + rva_base;
    put_elf_str(pe->thunk, dllname);

#अगर 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, माप buf, pe->filename);
    म_नकल(tcc_fileextension(buf), ".def");
    op = ख_खोलो(buf, "wb");
    अगर (शून्य == op) {
        tcc_error_noabort("could not create '%s': %s", buf, म_त्रुटि(त्रुटि_सं));
    } अन्यथा {
        ख_लिखो(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        अगर (s1->verbose)
            म_लिखो("<- %s (%d symbol%s)\n", buf, sym_गिनती, &"s"[sym_गिनती < 2]);
    }
#पूर्ण_अगर

    क्रम (ord = 0; ord < sym_गिनती; ++ord)
    {
        p = sorted[ord], sym_सूचकांक = p->सूचकांक, name = p->name;
        /* insert actual address later in relocate_sections() */
        put_elf_reloc(symtab_section, pe->thunk,
            func_o, R_XXX_RELATIVE, sym_सूचकांक);
        *(DWORD*)(pe->thunk->तथ्य + name_o)
            = pe->thunk->तथ्य_offset + rva_base;
        *(WORD*)(pe->thunk->तथ्य + ord_o)
            = ord;
        put_elf_str(pe->thunk, name);
        func_o += माप (DWORD);
        name_o += माप (DWORD);
        ord_o += माप (WORD);
        अगर (op)
            ख_लिखो(op, "%s\n", name);
    }

    pe->exp_offs = base_o + rva_base;
    pe->exp_आकार = pe->thunk->तथ्य_offset - base_o;
    dynarray_reset(&sorted, &sym_गिनती);
    अगर (op)
        ख_बंद(op);
}

/* ------------------------------------------------------------- */
अटल व्योम pe_build_reloc (काष्ठा pe_info *pe)
{
    DWORD offset, block_ptr, sh_addr, addr;
    पूर्णांक गिनती_2, i;
    ElfW_Rel *rel, *rel_end;
    Section *s = शून्य, *sr;
    काष्ठा pe_reloc_header *hdr;
    TCCState *s1 = pe->s1;
    पूर्णांक dwarf = 0, n;

    sh_addr = offset = block_ptr = गिनती_2 = i = 0;
    rel = rel_end = शून्य;

    क्रम(;;) {
        अगर (rel < rel_end) {
            पूर्णांक type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_offset + sh_addr;
            ++ rel;
            अगर (type != REL_TYPE_DIRECT)
                जारी;
            अगर (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->तथ्य + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                अगर (n >= s1->dwlo && n < s1->dwhi)
                    जारी;
            }
            अगर (गिनती_2 == 0) { /* new block */
                block_ptr = pe->reloc->तथ्य_offset;
                section_ptr_add(pe->reloc, माप(काष्ठा pe_reloc_header));
                offset = addr & 0xFFFFFFFF<<12;
            }
            अगर ((addr -= offset)  < (1<<12)) { /* one block spans 4k addresses */
                WORD *wp = section_ptr_add(pe->reloc, माप (WORD));
                *wp = addr | PE_IMAGE_REL<<12;
                ++गिनती_2;
                जारी;
            }
            -- rel;

        } अन्यथा अगर (s) {
            sr = s->reloc;
            अगर (sr) {
                rel = (ElfW_Rel *)sr->तथ्य;
                rel_end = (ElfW_Rel *)(sr->तथ्य + sr->तथ्य_offset);
                sh_addr = s->sh_addr;
                dwarf = s->sh_अंक >= s1->dwlo && s->sh_अंक < s1->dwhi;
            }
            s = s->पूर्व;
            जारी;

        } अन्यथा अगर (i < pe->sec_गिनती) {
            s = pe->sec_info[i]->sec, ++i;
            जारी;

        } अन्यथा अगर (!गिनती_2)
            अवरोध;

        /* fill the last block and ready for a new one */
        अगर (गिनती_2 & 1) /* align for DWORDS */
            section_ptr_add(pe->reloc, माप(WORD)), ++गिनती_2;
        hdr = (काष्ठा pe_reloc_header *)(pe->reloc->तथ्य + block_ptr);
        hdr -> offset = offset - pe->imagebase;
        hdr -> आकार = गिनती_2 * माप(WORD) + माप(काष्ठा pe_reloc_header);
        गिनती_2 = 0;
    }
}

/* ------------------------------------------------------------- */
अटल व्योम pe_build_tls(काष्ठा pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    पूर्णांक c, n;

    अगर (0 == s) {
        pe->tls_आकार = माप (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_add(pe->thunk, pe->tls_आकार, 16);
        pe->tls_तथ्य = section_add(तथ्य_section, PTR_आकार * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, तथ्य_section->sh_अंक, 0);
        क्रम (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_आकार*n, REL_TYPE_DIRECT, c);
        /* for generators */
        set_elf_sym(symtab_section, pe->tls_तथ्य, PTR_आकार * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, तथ्य_section->sh_अंक, "__tls_index");
        वापस;
    }

    अगर (0 == s1->tls_start)
        s1->tls_start = s->sh_addr;
    d = (व्योम*)(pe->thunk->तथ्य + pe->tls_dir);
    d->Start_Address_Of_Raw_तथ्य = s1->tls_start - तथ्य_section->sh_addr;
    d->End_Address_Of_Raw_तथ्य = s->sh_addr + s->तथ्य_offset - तथ्य_section->sh_addr;
    d->Address_Of_सूचकांक = pe->tls_तथ्य;
    d->AddressOfCallBacks = pe->tls_तथ्य + PTR_आकार;
    d->आकार_Of_Zero_Fill = 0;
    d->Characteristics = 0;
    /* to reuse logic from linux in xxx-link.c */
    s1->tls_end = s1->tls_start;
}

/* ------------------------------------------------------------- */
अटल पूर्णांक pe_section_class(Section *s)
{
    पूर्णांक type, flags;
    स्थिर अक्षर *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    अगर (0 == स_भेद(name, ".stab", 5) || 0 == स_भेद(name, ".debug_", 7)) {
        वापस sec_debug;
    } अन्यथा अगर (flags & SHF_ALLOC) {
        अगर (flags & SHF_TLS)
            वापस sec_tdata + (type == SHT_NOBITS);
        अगर (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            अगर (flags & SHF_EXECINSTR)
                वापस sec_text;
            अगर (flags & SHF_WRITE)
                वापस sec_तथ्य;
            अगर (0 == म_भेद(name, ".rsrc"))
                वापस sec_rsrc;
            अगर (0 == म_भेद(name, ".iedat"))
                वापस sec_idata;
            अगर (0 == म_भेद(name, ".pdata"))
                वापस sec_pdata;
            वापस sec_rdata;
        } अन्यथा अगर (type == SHT_NOBITS) {
            वापस sec_bss;
        }
        वापस sec_other;
    } अन्यथा {
        अगर (0 == म_भेद(name, ".reloc"))
            वापस sec_reloc;
    }
    वापस sec_last;
}

अटल पूर्णांक pe_assign_addresses (काष्ठा pe_info *pe)
{
    पूर्णांक i, k, n, c, nbs;
    ADDR3264 addr;
    पूर्णांक *sec_order, *sec_cls;
    काष्ठा section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    अगर (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_order = tcc_mallocz(2 * माप (पूर्णांक) * nbs);
    sec_cls = sec_order + nbs;
    क्रम (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        क्रम (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
        अगर ((s->sh_flags & SHF_TLS) && 0 == pe->tls_आकार)
            pe_build_tls(pe, शून्य);
    }
    si = शून्य;
    addr = pe->imagebase + 1;
    क्रम (i = 1; (c = sec_cls[i]) < sec_last; ++i) {
        s = s1->sections[sec_order[i]];

        अगर (PE_MERGE_तथ्य && c == sec_bss)
            c = sec_तथ्य;
        अगर (c == sec_tbss)
            c = sec_tdata;

        अगर (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } अन्यथा {
            si = शून्य;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        अगर (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        अगर (s == pe->reloc)
            pe_build_reloc (pe);

        अगर (0 == s->तथ्य_offset)
            जारी;

        अगर (si)
            जाओ add_section;

        si = tcc_mallocz(माप *si);
        dynarray_add(&pe->sec_info, &pe->sec_गिनती, si);

        म_नकल(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        अगर (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_CODE;
        अन्यथा अगर (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_तथ्य;
        अन्यथा
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_तथ्य;
        अगर (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        अगर (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

add_section:
        s->sh_info = pe->sec_गिनती; /* section number for coff syms */
        addr += s->तथ्य_offset;
        si->sh_आकार = addr - si->sh_addr;
        अगर (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            जबतक (*ps)
                ps = &(*ps)->पूर्व;
            *ps = s, s->पूर्व = शून्य;
            si->तथ्य_आकार = si->sh_आकार;
        }

        अगर (s->sh_flags & SHF_TLS) {
            म_नकल(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#अगर 0
    क्रम (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_order[i]];
        पूर्णांक type = s->sh_type;
        पूर्णांक flags = s->sh_flags;
        म_लिखो("section %-16s %-10s %p %04x %2d %s,%s,%s\n",
            s->name,
            type == SHT_PROGBITS ? "progbits" :
            type == SHT_INIT_ARRAY ? "initarr" :
            type == SHT_FINI_ARRAY ? "finiarr" :
            type == SHT_NOBITS ? "nobits" :
            type == SHT_SYMTAB ? "symtab" :
            type == SHT_STRTAB ? "strtab" :
            type == SHT_RELX ? "rel" : "???",
            s->sh_addr,
            (अचिन्हित)s->तथ्य_offset,
            s->sh_addralign,
            flags & SHF_ALLOC ? "alloc" : "",
            flags & SHF_WRITE ? "write" : "",
            flags & SHF_EXECINSTR ? "exec" : ""
            );
        ख_साफ(मानक_निकास);
    }
    s1->verbose = 2;
#पूर्ण_अगर
    tcc_free(sec_order);
    वापस 0;
}

/*----------------------------------------------------------------------------*/
अटल पूर्णांक pe_check_symbols(काष्ठा pe_info *pe)
{
    पूर्णांक sym_सूचकांक, sym_end;
    पूर्णांक ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(text_section, 8);

    sym_end = symtab_section->तथ्य_offset / माप(ElfW(Sym));
    क्रम (sym_सूचकांक = 1; sym_सूचकांक < sym_end; ++sym_सूचकांक) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->तथ्य + sym_सूचकांक;
        अगर (sym->st_shndx == SHN_UNDEF) {
            स्थिर अक्षर *name = (अक्षर*)symtab_section->link->तथ्य + sym->st_name;
            अचिन्हित type = ELFW(ST_TYPE)(sym->st_info);
            पूर्णांक imp_sym = 0;
            काष्ठा import_प्रतीक *is;

            पूर्णांक _imp_, n;
            अक्षर बफर[200];
            स्थिर अक्षर *s, *p;

            n = _imp_ = 0;
            अगर (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            करो {
                s = pe_export_name(s1, sym);
                अगर (n) {
                    /* second try: */
                    अगर (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = म_खोजप(s, '@');
                        अगर (!p || s[0] != '_')
                            अवरोध;
                        म_नकल(बफर, s+1)[p-s-1] = 0, s = बफर;
                    } अन्यथा अगर (s[0] != '_') { /* try non-ansi function */
                        बफर[0] = '_', म_नकल(बफर + 1, s), s = बफर;
                    } अन्यथा अगर (0 == स_भेद(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } अन्यथा अगर (0 == स_भेद(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } अन्यथा {
                        अवरोध;
                    }
                }
                imp_sym = find_elf_sym(s1->dynsymtab_section, s);
            } जबतक (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            अगर (0 == imp_sym)
                जारी; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_add_import(pe, imp_sym);

            अगर (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                अचिन्हित offset = is->thk_offset;
                अगर (offset) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } अन्यथा {
                    अचिन्हित अक्षर *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    प्र_लिखो(बफर, "IAT.%s", name);
                    is->iat_सूचकांक = put_elf_sym(
                        symtab_section, 0, माप(DWORD),
                        ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT),
                        0, SHN_UNDEF, बफर);

                    offset = text_section->तथ्य_offset;
                    is->thk_offset = offset;

                    /* add the 'jmp IAT[x]' instruction */
#अगर_घोषित TCC_TARGET_ARM
                    p = section_ptr_add(text_section, 8+4); // room for code and address
                    write32le(p + 0, 0xE59FC000); // arm code ldr ip, [pc] ; PC+8+0 = 0001xxxx
                    write32le(p + 4, 0xE59CF000); // arm code ldr pc, [ip]
                    put_elf_reloc(symtab_section, text_section,
                        offset + 8, R_XXX_THUNKFIX, is->iat_सूचकांक); // offset to IAT position
#या_अगर defined(TCC_TARGET_ARM64)
                    p = section_ptr_add(text_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, text_section,
                        offset + 16, R_XXX_THUNKFIX, is->iat_सूचकांक);
#अन्यथा
                    p = section_ptr_add(text_section, 8);
                    write16le(p, 0x25FF);
#अगर_घोषित TCC_TARGET_X86_64
                    write32le(p + 2, (DWORD)-4);
#पूर्ण_अगर
                    put_elf_reloc(symtab_section, text_section, 
                        offset + 2, R_XXX_THUNKFIX, is->iat_सूचकांक);
#पूर्ण_अगर
                }
                /* tcc_realloc might have altered sym's address */
                sym = (ElfW(Sym) *)symtab_section->तथ्य + sym_सूचकांक;
                /* patch the original symbol */
                sym->st_मूल्य = offset;
                sym->st_shndx = text_section->sh_अंक;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } अन्यथा { /* STT_OBJECT */
                अगर (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_मूल्य = is->iat_सूचकांक; /* chain potential alias */
                is->iat_सूचकांक = sym_सूचकांक;
            }

        } अन्यथा अगर (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    वापस ret;
}

/*----------------------------------------------------------------------------*/
#अगर PE_PRINT_SECTIONS
अटल व्योम pe_print_section(खाता * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    पूर्णांक i, n, l, m;
    p = s->तथ्य;
    e = s->तथ्य + s->तथ्य_offset;
    l = e - p;

    ख_लिखो(f, "section  \"%s\"", s->name);
    अगर (s->link)
        ख_लिखो(f, "\nlink     \"%s\"", s->link->name);
    अगर (s->reloc)
        ख_लिखो(f, "\nreloc    \"%s\"", s->reloc->name);
    ख_लिखो(f, "\nv_addr   %08X", (अचिन्हित)s->sh_addr);
    ख_लिखो(f, "\ncontents %08X", (अचिन्हित)l);
    ख_लिखो(f, "\n\n");

    अगर (s->sh_type == SHT_NOBITS)
        वापस;

    अगर (0 == l)
        वापस;

    अगर (s->sh_type == SHT_SYMTAB)
        m = माप(ElfW(Sym));
    अन्यथा अगर (s->sh_type == SHT_RELX)
        m = माप(ElfW_Rel);
    अन्यथा
        m = 16;

    ख_लिखो(f, "%-8s", "offset");
    क्रम (i = 0; i < m; ++i)
        ख_लिखो(f, " %02x", i);
    n = 56;

    अगर (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        स्थिर अक्षर *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            शून्य
        };

        स्थिर अक्षर *fields2[] = {
            "offs",
            "type",
            "symb",
            शून्य
        };

        स्थिर अक्षर **p;

        अगर (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        अन्यथा
            p = fields2, n = 58;

        क्रम (i = 0; p[i]; ++i)
            ख_लिखो(f, "%6s", p[i]);
        ख_लिखो(f, "  symbol");
    }

    ख_लिखो(f, "\n");
    क्रम (i = 0; i < n; ++i)
        ख_लिखो(f, "-");
    ख_लिखो(f, "\n");

    क्रम (i = 0; i < l;)
    {
        ख_लिखो(f, "%08X", i);
        क्रम (n = 0; n < m; ++n) {
            अगर (n + i < l)
                ख_लिखो(f, " %02X", p[i + n]);
            अन्यथा
                ख_लिखो(f, "   ");
        }

        अगर (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            स्थिर अक्षर *name = s->link->तथ्य + sym->st_name;
            ख_लिखो(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (अचिन्हित)sym->st_name,
                    (अचिन्हित)sym->st_मूल्य,
                    (अचिन्हित)sym->st_आकार,
                    (अचिन्हित)ELFW(ST_BIND)(sym->st_info),
                    (अचिन्हित)ELFW(ST_TYPE)(sym->st_info),
                    (अचिन्हित)sym->st_other,
                    (अचिन्हित)sym->st_shndx,
                    name);

        } अन्यथा अगर (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->तथ्य + ELFW(R_SYM)(rel->r_info);
            स्थिर अक्षर *name = s->link->link->तथ्य + sym->st_name;
            ख_लिखो(f, "  %04X   %02X   %04X  \"%s\"",
                    (अचिन्हित)rel->r_offset,
                    (अचिन्हित)ELFW(R_TYPE)(rel->r_info),
                    (अचिन्हित)ELFW(R_SYM)(rel->r_info),
                    name);
        } अन्यथा {
            ख_लिखो(f, "   ");
            क्रम (n = 0; n < m; ++n) {
                अगर (n + i < l) {
                    b = p[i + n];
                    अगर (b < 32 || b >= 127)
                        b = '.';
                    ख_लिखो(f, "%c", b);
                }
            }
        }
        i += m;
        ख_लिखो(f, "\n");
    }
    ख_लिखो(f, "\n\n");
}

अटल व्योम pe_print_sections(TCCState *s1, स्थिर अक्षर *fname)
{
    Section *s;
    खाता *f;
    पूर्णांक i;
    f = ख_खोलो(fname, "w");
    क्रम (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    ख_बंद(f);
}
#पूर्ण_अगर

/* ------------------------------------------------------------- */

ST_FUNC पूर्णांक pe_putimport(TCCState *s1, पूर्णांक dllindex, स्थिर अक्षर *name, addr_t मूल्य)
{
    वापस set_elf_sym(
        s1->dynsymtab_section,
        मूल्य,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        मूल्य ? SHN_ABS : SHN_UNDEF,
        name
        );
}

अटल पूर्णांक read_mem(पूर्णांक fd, अचिन्हित offset, व्योम *बफर, अचिन्हित len)
{
    lseek(fd, offset, शुरू_से);
    वापस len == पढ़ो(fd, बफर, len);
}

/* ------------------------------------------------------------- */

अटल पूर्णांक get_dllexports(पूर्णांक fd, अक्षर **pp)
{
    पूर्णांक i, k, l, n, n0, ret;
    अक्षर *p;

    IMAGE_SECTION_HEADER ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_HEADER dh;
    IMAGE_FILE_HEADER ih;
    DWORD sig, ref, addr;
    DWORD *namep = शून्य, p0 = 0, p1;

    पूर्णांक pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = शून्य;
    ret = 1;
    अगर (!read_mem(fd, 0, &dh, माप dh))
        जाओ the_end;
    अगर (!read_mem(fd, dh.e_lfanew, &sig, माप sig))
        जाओ the_end;
    अगर (sig != 0x00004550)
        जाओ the_end;
    pef_hdroffset = dh.e_lfanew + माप sig;
    अगर (!read_mem(fd, pef_hdroffset, &ih, माप ih))
        जाओ the_end;
    opt_hdroffset = pef_hdroffset + माप ih;
    अगर (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + माप oh;
        अगर (!read_mem(fd, opt_hdroffset, &oh, माप oh))
            जाओ the_end;
        अगर (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.संख्या_Of_Rva_And_Sizes)
            जाओ the_end_0;
        addr = oh.तथ्य_Directory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } अन्यथा अगर (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + माप oh;
        अगर (!read_mem(fd, opt_hdroffset, &oh, माप oh))
            जाओ the_end;
        अगर (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.संख्या_Of_Rva_And_Sizes)
            जाओ the_end_0;
        addr = oh.तथ्य_Directory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } अन्यथा
        जाओ the_end;

    //printf("addr: %08x\n", addr);
    क्रम (i = 0; i < ih.संख्या_Of_Sections; ++i) {
        अगर (!read_mem(fd, sec_hdroffset + i * माप ish, &ish, माप ish))
            जाओ the_end;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        अगर (addr >= ish.VirtualAddress && addr < ish.VirtualAddress + ish.आकार_Of_Raw_तथ्य)
            जाओ found;
    }
    जाओ the_end_0;
found:
    ref = ish.VirtualAddress - ish.Pointer_To_Raw_तथ्य;
    अगर (!read_mem(fd, addr - ref, &ied, माप ied))
        जाओ the_end;
    k = ied.संख्या_Of_Names;
    अगर (k) {
        namep = tcc_malloc(l = k * माप *namep);
        अगर (!read_mem(fd, ied.AddressOfNames - ref, namep, l))
            जाओ the_end;
        क्रम (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            अगर (p1 != p0)
                lseek(fd, p0 = p1, शुरू_से), l = 0;
            करो {
                अगर (0 == l) {
                    अगर (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    अगर ((l = पढ़ो(fd, p + n, 1000 - 1)) <= 0)
                        जाओ the_end;
                }
                --l, ++p0;
            } जबतक (p[n++]);
        }
        p[n] = 0;
    }
the_end_0:
    ret = 0;
the_end:
    tcc_free(namep);
    अगर (ret && p)
        tcc_free(p), p = शून्य;
    *pp = p;
    वापस ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

अटल पूर्णांक pe_load_res(TCCState *s1, पूर्णांक fd)
{
    काष्ठा pe_rsrc_header hdr;
    Section *rsrc_section;
    पूर्णांक i, ret = -1, sym_सूचकांक;
    BYTE *ptr;
    अचिन्हित offs;

    अगर (!read_mem(fd, 0, &hdr, माप hdr))
        जाओ quit;

    अगर (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.संख्या_Of_Sections != 1
        || म_भेद((अक्षर*)hdr.sectionhdr.Name, ".rsrc") != 0)
        जाओ quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_add(rsrc_section, hdr.sectionhdr.आकार_Of_Raw_तथ्य);
    offs = hdr.sectionhdr.Pointer_To_Raw_तथ्य;
    अगर (!read_mem(fd, offs, ptr, hdr.sectionhdr.आकार_Of_Raw_तथ्य))
        जाओ quit;
    offs = hdr.sectionhdr.PointerToRelocations;
    sym_सूचकांक = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_अंक, ".rsrc");
    क्रम (i = 0; i < hdr.sectionhdr.संख्या_Of_Relocations; ++i) {
        काष्ठा pe_rsrc_reloc rel;
        अगर (!read_mem(fd, offs, &rel, माप rel))
            जाओ quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        अगर (rel.type != RSRC_RELTYPE)
            जाओ quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.offset, R_XXX_RELATIVE, sym_सूचकांक);
        offs += माप rel;
    }
    ret = 0;
quit:
    वापस ret;
}

/* ------------------------------------------------------------- */

अटल अक्षर *trimfront(अक्षर *p)
{
    जबतक ((अचिन्हित अक्षर)*p <= ' ' && *p && *p != '\n')
	++p;
    वापस p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

अटल अक्षर *get_token(अक्षर **s, अक्षर *f)
{
    अक्षर *p, *e;
    पूर्णांक q;

    p = trimfront(*s);
    q = *p;
    अगर (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    अन्यथा
        q = ' ';
    क्रम (e = p; (अचिन्हित अक्षर)*e >= ' ' && *e != q; ++e)
        ;
    अगर (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    वापस p;
}

अटल पूर्णांक pe_load_def(TCCState *s1, पूर्णांक fd)
{
    पूर्णांक state = 0, ret = -1, dllindex = 0, ord;
    अक्षर dllname[80], *buf, *पंक्ति_2, *p, *x, अग्र;

    buf = tcc_load_text(fd);
    अगर (!buf)
        वापस ret;

    क्रम (पंक्ति_2 = buf;; ++पंक्ति_2)  {
        p = get_token(&पंक्ति_2, &अग्र);
        अगर (!(*p && *p != ';'))
            जाओ skip;
        चयन (state) {
        हाल 0:
            अगर (0 != stricmp(p, "LIBRARY") || अग्र == '\n')
                जाओ quit;
            pstrcpy(dllname, माप dllname, get_token(&पंक्ति_2, &अग्र));
            अगर (!*tcc_fileextension(dllname))
                pstrcat(dllname, माप dllname, ".dll");
            ++state;
            अवरोध;
        हाल 1:
            अगर (0 != stricmp(p, "EXPORTS"))
                जाओ quit;
            ++state;
            अवरोध;
        हाल 2:
            dllindex = tcc_add_dllref(s1, dllname, 0)->सूचकांक;
            ++state;
            /* fall through */
        शेष:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            अगर (अग्र == '@') {
                x = get_token(&पंक्ति_2, &अग्र);
                ord = (पूर्णांक)म_से_दीर्घ(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            अवरोध;
        }
skip:
        जबतक ((अचिन्हित अक्षर)अग्र > ' ')
            get_token(&पंक्ति_2, &अग्र);
        अगर (अग्र != '\n')
            अवरोध;
    }
    ret = 0;
quit:
    tcc_free(buf);
    वापस ret;
}

/* ------------------------------------------------------------- */

अटल पूर्णांक pe_load_dll(TCCState *s1, पूर्णांक fd, स्थिर अक्षर *filename)
{
    अक्षर *p, *q;
    DLLReference *ref = tcc_add_dllref(s1, filename, 0);
    अगर (ref->found)
        वापस 0;
    अगर (get_dllexports(fd, &p))
        वापस -1;
    अगर (p) {
        क्रम (q = p; *q; q += 1 + म_माप(q))
            pe_putimport(s1, ref->सूचकांक, q, 0);
        tcc_free(p);
    }
    वापस 0;
}

ST_FUNC पूर्णांक pe_load_file(काष्ठा TCCState *s1, पूर्णांक fd, स्थिर अक्षर *filename)
{
    पूर्णांक ret = -1;
    अक्षर buf[10];
    अगर (0 == म_भेद(tcc_fileextension(filename), ".def"))
        ret = pe_load_def(s1, fd);
    अन्यथा अगर (pe_load_res(s1, fd) == 0)
        ret = 0;
    अन्यथा अगर (read_mem(fd, 0, buf, 4) && 0 == स_भेद(buf, "MZ", 2))
        ret = pe_load_dll(s1, fd, filename);
    वापस ret;
}

PUB_FUNC पूर्णांक tcc_get_dllexports(स्थिर अक्षर *filename, अक्षर **pp)
{
    पूर्णांक ret, fd = खोलो(filename, O_RDONLY | O_द्विआधारी_2);
    अगर (fd < 0)
        वापस -1;
    ret = get_dllexports(fd, pp);
    बंद(fd);
    वापस ret;
}

/* ------------------------------------------------------------- */
#अगर_घोषित TCC_TARGET_X86_64
अटल अचिन्हित pe_add_unwind_info(TCCState *s1)
{
    अगर (शून्य == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    अगर (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, text_section->sh_अंक, ".uw_base");
    अगर (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        अटल स्थिर अचिन्हित अक्षर uw_info[] = {
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
        अचिन्हित अक्षर *p;

        section_ptr_add(s, -s->तथ्य_offset & 3); /* align */
        s1->uw_offs = s->तथ्य_offset;
        p = section_ptr_add(s, माप uw_info);
        स_नकल(p, uw_info, माप uw_info);
    }

    वापस s1->uw_offs;
}

ST_FUNC व्योम pe_add_unwind_तथ्य(अचिन्हित start, अचिन्हित end, अचिन्हित ढेर)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    अचिन्हित o, n, d;
    काष्ठा /* _RUNTIME_FUNCTION */ {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD Unwind_तथ्य;
    } *p;

    d = pe_add_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->तथ्य_offset;
    p = section_ptr_add(pd, माप *p);

    /* record this function */
    p->BeginAddress = start;
    p->EndAddress = end;
    p->Unwind_तथ्य = d;

    /* put relocations on it */
    क्रम (n = o + माप *p; o < n; o += माप p->BeginAddress)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#या_अगर defined(TCC_TARGET_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
अटल Section *pe_add_unwind_info(TCCState *s1)
{
    Section *s;

    अगर (शून्य == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = find_section(s1, ".xdata");
    s->sh_addralign = 4;
    अगर (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  text_section->sh_अंक, ".uw_text_base");
    अगर (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_अंक, ".uw_base");
    वापस s;
}

ST_FUNC व्योम pe_add_unwind_तथ्य(अचिन्हित start, अचिन्हित end, अचिन्हित ढेर)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    अचिन्हित o, d, code_bytes, func_len;
    अचिन्हित अक्षर *q;
    uint32_t header;
    काष्ठा /* _RUNTIME_FUNCTION */ {
        DWORD BeginAddress;
        DWORD Unwind_तथ्य;
    } *p;

    पूर्णांक epilog;

    xd = pe_add_unwind_info(s1);
    pd = s1->uw_pdata;

    func_len = (end - start) >> 2;
    code_bytes = 0;
    epilog = code_bytes;
    code_bytes += 3; /* set_fp, save_fplr_x, end */
    code_bytes = (code_bytes + 3) & ~3;

    section_ptr_add(xd, -xd->तथ्य_offset & 3);
    d = xd->तथ्य_offset;
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
    जबतक ((अचिन्हित)(q - (xd->तथ्य + d + 4)) < code_bytes)
        *q++ = 0xE3; /* nop padding */

    o = pd->तथ्य_offset;
    p = section_ptr_add(pd, माप *p);
    p->BeginAddress = start;
    p->Unwind_तथ्य = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#पूर्ण_अगर
/* ------------------------------------------------------------- */
#अगर defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
#घोषणा PE_STDSYM(n,s) n
#अन्यथा
#घोषणा PE_STDSYM(n,s) "_" n s
#पूर्ण_अगर

अटल व्योम pe_add_runtime(TCCState *s1, काष्ठा pe_info *pe)
{
    स्थिर अक्षर *start_प्रतीक;
    पूर्णांक pe_type;

    अगर (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        start_प्रतीक = PE_STDSYM("__dllstart","@12");
    } अन्यथा {
        स्थिर अक्षर *run_प्रतीक;
        अगर (find_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            start_प्रतीक = "__winstart";
            run_प्रतीक = "__runwinmain";
            pe_type = PE_GUI;
        } अन्यथा अगर (find_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            start_प्रतीक = "__wwinstart";
            run_प्रतीक = "__runwwinmain";
            pe_type = PE_GUI;
        } अन्यथा अगर (find_elf_sym(symtab_section, "wmain")) {
            start_प्रतीक = "__wstart";
            run_प्रतीक = "__runwmain";
            pe_type = PE_EXE;
        } अन्यथा {
            start_प्रतीक =  "__start";
            run_प्रतीक = "__runmain";
            pe_type = PE_EXE;
            अगर (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        अगर (TCC_OUTPUT_MEMORY == s1->output_type && !s1->nostdlib)
            start_प्रतीक = run_प्रतीक;
    }
    अगर (s1->elf_entryname) {
        pe->start_प्रतीक = start_प्रतीक = s1->elf_entryname;
    } अन्यथा {
        pe->start_प्रतीक = start_प्रतीक + 1;
        अगर (!s1->leading_underscore || म_अक्षर(start_प्रतीक, '@'))
            ++start_प्रतीक;
    }

#अगर_घोषित CONFIG_TCC_BACKTRACE
    अगर (s1->do_backtrace) {
#अगर_घोषित CONFIG_TCC_BCHECK
        अगर (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    अगर (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    अन्यथा
                tcc_add_support(s1, "bcheck.o");
	}
#पूर्ण_अगर
        अगर (s1->output_type == TCC_OUTPUT_EXE)
            tcc_add_support(s1, "bt-exe.o");
        अगर (s1->output_type == TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-dll.o");
        अगर (s1->output_type != TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-log.o");
        tcc_add_btstub(s1);
    }
#पूर्ण_अगर

    /* grab the startup code from libtcc1.a */
#अगर_घोषित TCC_IS_NATIVE
    अगर (TCC_OUTPUT_MEMORY != s1->output_type || s1->run_main)
#पूर्ण_अगर
    set_global_sym(s1, start_प्रतीक, शून्य, 0);

    अगर (0 == s1->nostdlib) {
        अटल स्थिर अक्षर * स्थिर libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", शून्य
        };
        स्थिर अक्षर * स्थिर *pp, *p;
        अगर (TCC_LIBTCC1[0])
            tcc_add_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        क्रम (pp = libs; 0 != (p = *pp); ++pp) {
            अगर (*p)
                tcc_add_library(s1, p);
            अन्यथा अगर (PE_DLL != pe_type && PE_GUI != pe_type)
                अवरोध;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    अगर (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    अगर (TCC_OUTPUT_MEMORY == s1->output_type)
        pe_type = PE_RUN;
    pe->type = pe_type;
}

ST_FUNC पूर्णांक pe_setsubsy(TCCState *s1, स्थिर अक्षर *arg)
{
    अटल स्थिर काष्ठा subsy { स्थिर अक्षर* p; पूर्णांक v; } x[] = {
#अगर defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#या_अगर defined(TCC_TARGET_ARM)
        { "wince", 9 },
#पूर्ण_अगर
        { 0, -1 }};
    स्थिर काष्ठा subsy *y;
    क्रम (y = x;; ++y) {
        अगर (!y->p)
            वापस -1;
        अगर (0 == म_भेद(y->p, arg)) {
            s1->pe_subsystem = y->v;
            वापस 0;
        }
    }
}

अटल व्योम pe_set_options(TCCState * s1, काष्ठा pe_info *pe)
{
    अगर (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_BASE_DLL;
    } अन्यथा {
        pe->imagebase = IMAGE_BASE_EXE;
    }

#अगर defined(TCC_TARGET_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#अन्यथा
    अगर (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    अन्यथा
        pe->subsystem = 3;
#पूर्ण_अगर
    /* Allow override via -Wl,-subsystem=... option */
    अगर (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    अगर (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } अन्यथा {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    अगर (s1->section_align != 0)
        pe->section_align = s1->section_align;
    अगर (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    अगर ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    अगर (s1->has_text_addr)
        pe->imagebase = s1->text_addr;
}

ST_FUNC पूर्णांक pe_output_file(TCCState *s1, स्थिर अक्षर *filename)
{
    काष्ठा pe_info pe;

    स_रखो(&pe, 0, माप pe);
    pe.filename = filename;
    pe.s1 = s1;
    s1->filetype = 0;

#अगर_घोषित CONFIG_TCC_BCHECK
    tcc_add_bcheck(s1);
#पूर्ण_अगर
    tcc_add_pragma_libs(s1);
    pe_add_runtime(s1, &pe);
    resolve_common_syms(s1);
    pe_set_options(s1, &pe);
    pe_check_symbols(&pe);
    अगर (s1->nb_errors)
        जाओ done;
    अगर (filename) {
        pe_assign_addresses(&pe);
        relocate_syms(s1, s1->symtab, 0);
        अगर (s1->nb_errors)
            जाओ done;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.start_addr = (DWORD)
            (get_sym_addr(s1, pe.start_प्रतीक, 1, 1) - pe.imagebase);
        अगर (s1->nb_errors)
            जाओ done;
        pe_write(&pe);
    } अन्यथा {
        /* -run */
#अगर_घोषित TCC_IS_NATIVE
        pe.thunk = तथ्य_section;
        pe_build_imports(&pe);
        s1->run_main = pe.start_प्रतीक;
#अगर defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        s1->uw_pdata = find_section(s1, ".pdata");
#पूर्ण_अगर
#पूर्ण_अगर
    }
done:
    dynarray_reset(&pe.sec_info, &pe.sec_गिनती);
    pe_free_imports(&pe);
#अगर PE_PRINT_SECTIONS
    अगर (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#पूर्ण_अगर
    वापस s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
