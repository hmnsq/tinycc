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

#अन्तर्भाव "tcc.h"

#define PE_MERGE_DATA 1
#define PE_PRINT_SECTIONS 0

#ifndef _WIN32
#define stricmp strcasecmp
#define strnicmp strncasecmp
#अन्तर्भाव <sys/stat.h> /* chmod() */
#endif

#यदि defined TCC_TARGET_X86_64
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

#अथवायदि defined TCC_TARGET_ARM
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

#अथवायदि defined TCC_TARGET_ARM64
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

#अथवायदि defined TCC_TARGET_I386
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

#यदि PTR_SIZE == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#अन्यथा
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#endif

#ifndef IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

प्रकारनिर्देश अचिन्हित वर्ण BYTE;
प्रकारनिर्देश अचिन्हित लघु WORD;
प्रकारनिर्देश अचिन्हित पूर्णाङ्क DWORD;
प्रकारनिर्देश अचिन्हित दीर्घ दीर्घ ULONGLONG;
#pragma pack(थप, 1)

प्रकारनिर्देश संरचना _IMAGE_DOS_HEADER {  /* DOS .EXE header */
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

प्रकारनिर्देश संरचना _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    सङ्ख्या_Of_Sections;
    DWORD   TimeDateStamp;
    DWORD   Pointer_To_चिह्न_Table;
    DWORD   सङ्ख्या_Of_Symbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;


#define IMAGE_SIZEOF_FILE_HEADER 20

प्रकारनिर्देश संरचना _IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;


प्रकारनिर्देश संरचना _IMAGE_OPTIONAL_HEADER {
    /* Standard fields. */
    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
#यदि PTR_SIZE == 4
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
    DWORD   Win32_Version_मान;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    ADDR3264 Size_Of_थाक_Reserve;
    ADDR3264 Size_Of_थाक_Commit;
    ADDR3264 SizeOfHeapReserve;
    ADDR3264 SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   सङ्ख्या_Of_Rva_And_Sizes;
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

प्रकारनिर्देश संरचना _IMAGE_SECTION_HEADER {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    सङ्घ {
            DWORD   PhysicalAddress;
            DWORD   VirtualSize;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   SizeOfRawData;
    DWORD   PointerToRawData;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    सङ्ख्या_Of_Relocations;
    WORD    सङ्ख्या_Of_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#define IMAGE_SIZEOF_SECTION_HEADER     40

प्रकारनिर्देश संरचना _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD Name;
    DWORD Base;
    DWORD सङ्ख्या_Of_Functions;
    DWORD सङ्ख्या_Of_Names;
    DWORD AddressOfFunctions;
    DWORD AddressOfNames;
    DWORD AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

प्रकारनिर्देश संरचना _IMAGE_TLS_DIRECTORY {
    ADDR3264 StartAddressOfRawData;
    ADDR3264 EndAddressOfRawData;
    ADDR3264 AddressOfIndex;
    ADDR3264 AddressOfCallBacks;
    DWORD SizeOfZeroFill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

प्रकारनिर्देश संरचना _IMAGE_IMPORT_DESCRIPTOR {
    सङ्घ {
        DWORD Characteristics;
        DWORD OriginalFirstThunk;
    };
    DWORD TimeDateStamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;

प्रकारनिर्देश संरचना _IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   SizeOfBlock;
//  WORD    TypeOffset[1];
} IMAGE_BASE_RELOCATION;

#define IMAGE_SIZEOF_BASE_RELOCATION     8

#define IMAGE_REL_BASED_ABSOLUTE         0
#define IMAGE_REL_BASED_माथिल्लो             1
#define IMAGE_REL_BASED_तल्लो              2
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

#define IMAGE_DLLCHARACTERISTICS_माथिल्लो_ENTROPY_VA 0x0020
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#define IMAGE_FILE_RELOCS_STRIPPED 0x0001

#pragma pack(झिक)

/* ----------------------------------------------------------- */
#endif /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#ifndef IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#endif

#pragma pack(थप, 1)
संरचना pe_header
{
    IMAGE_DOS_HEADER doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_HEADER filehdr;
#यदि PTR_SIZE == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#अन्यथा
#ifdef _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#अन्यथा
    IMAGE_OPTIONAL_HEADER opthdr;
#endif
#endif
};

संरचना pe_reloc_header {
    DWORD offset;
    DWORD size;
};

संरचना pe_rsrc_header {
    संरचना _IMAGE_FILE_HEADER filehdr;
    संरचना _IMAGE_SECTION_HEADER sectionhdr;
};

संरचना pe_rsrc_reloc {
    DWORD offset;
    DWORD size;
    WORD type;
};
#pragma pack(झिक)

/* ------------------------------------------------------------- */
/* internal temporary structures */

गणना {
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

#यदि 0
स्थिर अचर DWORD pe_sec_flags[] = {
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

संरचना section_info {
    पूर्णाङ्क cls;
    वर्ण name[32];
    ADDR3264 sh_addr;
    DWORD sh_size;
    DWORD pe_flags;
    Section *sec;
    DWORD data_size;
    IMAGE_SECTION_HEADER ish;
};

संरचना import_चिह्न {
    पूर्णाङ्क sym_index;
    पूर्णाङ्क iat_index;
    पूर्णाङ्क thk_offset;
};

संरचना pe_import_info {
    पूर्णाङ्क dll_index;
    पूर्णाङ्क sym_गन्ती;
    संरचना import_चिह्न **symbols;
};

संरचना pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    अचर वर्ण *filename;
    पूर्णाङ्क type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    अचर वर्ण *start_चिह्न;
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
    पूर्णाङ्क subsystem;
    DWORD section_align;
    DWORD file_align;
    संरचना section_info **sec_info;
    पूर्णाङ्क sec_गन्ती;
    संरचना pe_import_info **imp_info;
    पूर्णाङ्क imp_गन्ती;
    /* output */
    खाता *op;
    DWORD sum;
    अचिन्हित pos;
};

#define PE_NUL 0
#define PE_DLL 1
#define PE_GUI 2
#define PE_EXE 3
#define PE_RUN 4

/* --------------------------------------------*/

स्थिर अचर वर्ण *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    अचर वर्ण *name = (वर्ण*)symtab_section->link->data + sym->st_name;
    यदि (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        फर्काऊ name + 1;
    फर्काऊ name;
}


स्थिर पूर्णाङ्क dynarray_assoc(शून्य **pp, पूर्णाङ्क n, पूर्णाङ्क साँचो)
{
    पूर्णाङ्क i;
    लागि (i = 0; i < n; ++i, ++pp)
    यदि (साँचो == **(पूर्णाङ्क **) pp)
        फर्काऊ i;
    फर्काऊ -1;
}

स्थिर DWORD umin(DWORD a, DWORD b)
{
    फर्काऊ a < b ? a : b;
}

स्थिर DWORD umax(DWORD a, DWORD b)
{
    फर्काऊ a < b ? b : a;
}

स्थिर DWORD pe_file_align(संरचना pe_info *pe, DWORD n)
{
    फर्काऊ (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

स्थिर ADDR3264 pe_virtual_align(संरचना pe_info *pe, ADDR3264 n)
{
    फर्काऊ (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

स्थिर शून्य pe_align_section(Section *s, पूर्णाङ्क a)
{
    पूर्णाङ्क i = s->data_offset & (a-1);
    यदि (i)
        section_ptr_add(s, a - i);
}

स्थिर शून्य pe_set_datadir(संरचना pe_header *hdr, पूर्णाङ्क dir, DWORD addr, DWORD size)
{
    hdr->opthdr.DataDirectory[dir].VirtualAddress = addr;
    hdr->opthdr.DataDirectory[dir].Size = size;
}

स्थिर पूर्णाङ्क pe_fwrite(संरचना pe_info *pe, अचर शून्य *data, पूर्णाङ्क len)
{
    अचर WORD *p = data;
    DWORD sum;
    पूर्णाङ्क ret, i;
    pe->pos += (ret = ख_डालो(data, 1, len, pe->op));
    sum = pe->sum;
    लागि (i = len; i > 0; i -= 2) {
        sum += (i >= 2) ? *p++ : *(BYTE*)p;
        sum = (sum + (sum >> 16)) & 0xFFFF;
    }
    pe->sum = sum;
    फर्काऊ len == ret ? 0 : -1;
}

स्थिर शून्य pe_fpad(संरचना pe_info *pe, DWORD new_pos)
{
    वर्ण buf[256];
    पूर्णाङ्क n, diff = new_pos - pe->pos;
    स_रखो(buf, 0, परिमाण buf);
    जबसम्म (diff > 0) {
        diff -= n = umin(diff, परिमाण buf);
        ख_डालो(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#pragma pack(थप, 1)
संरचना syment
{
    सङ्घ {
        वर्ण        n_name[8];     /* old COFF version */
        संरचना {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_offset;      /* offset into string table */
        };
    };
    int32_t         n_मान;        /* value of symbol */
    लघु           n_scnum;        /* section number */
    अचिन्हित लघु  n_type;         /* type and derived type */
    वर्ण            n_sclass;       /* storage class */
    वर्ण            n_numaux;       /* number of aux. entries */
};
#pragma pack(झिक)

#define SHF_PRIVATE 0x80000000

स्थिर शून्य pe_add_coffsym(संरचना pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    संरचना syment *se;
    पूर्णाङ्क n;

    यदि (रिक्त == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_PRIVATE);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_PRIVATE);
        section_ptr_add(pe->coffstr, 4); /* coff string table size */
        फर्काऊ;
    }

#यदि 0
    se = section_ptr_add(pe->coffsym, परिमाण *se);
    म_नकल(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_add(pe->coffsym, परिमाण *se);
    म_नकल((वर्ण*)se, "no-file");
#endif

#यदि 1
    esym = (ElfSym*)s1->symtab->data;
    लागि (n = s1->symtab->data_offset / परिमाण *esym; ++esym, --n;) {
        पूर्णाङ्क sym_bind = ELFW(ST_BIND)(esym->st_info);
        यदि (sym_bind == STB_GLOBAL) {
            वर्ण *name = esym->st_name + (वर्ण*)s1->symtab->link->data;
            पूर्णाङ्क nl = म_माप(name);
            addr_t मान = esym->st_मान;
            पूर्णाङ्क shnum = esym->st_shndx;
            यदि (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                मान = मान - s->sh_addr;
            }
            se = section_ptr_add(pe->coffsym, परिमाण *se);
            se->n_मान = मान;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            यदि (nl <= 8)
                स_नकल(se->n_name, name, nl);
            अन्यथा
                se->n_offset = put_elf_str(pe->coffstr, name);
        }
    }
#endif
    write32le(pe->coffstr->data, pe->coffstr->data_offset); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
स्थिर शून्य pe_create_pdb(TCCState *s1, अचर वर्ण *exename)
{
    वर्ण buf[300]; पूर्णाङ्क r;
    snprintf(buf, परिमाण buf, "cv2pdb.exe \"%s\"", exename);
    r = प्रणाली(buf);
    म_नकल(tcc_fileextension(म_नकल(buf, exename)), ".pdb");
    यदि (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } अन्यथा यदि (s1->verbose) {
        म_लिखो("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
स्थिर पूर्णाङ्क pe_write(संरचना pe_info *pe)
{
    स्थिर अचर संरचना pe_header pe_template = {
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
#यदि PTR_SIZE == 4
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

    संरचना pe_header pe_header = pe_template;

    पूर्णाङ्क i;
    DWORD file_offset;
    संरचना section_info *si;
    IMAGE_SECTION_HEADER *psh;
    TCCState *s1 = pe->s1;

    यदि (s1->do_debug)
        pe_add_coffsym(pe);

    pe->op = ख_खोलो(pe->filename, "wb");
    यदि (रिक्त == pe->op)
        फर्काऊ tcc_error_noabort("could not write '%s': %s", pe->filename, म_त्रुटि(त्रुटि_सं));

    pe->sizeofheaders = pe_file_align(pe,
        परिमाण (संरचना pe_header)
        + pe->sec_गन्ती * परिमाण (IMAGE_SECTION_HEADER)
        );

    file_offset = pe->sizeofheaders;

    यदि (2 == s1->verbose)
        म_लिखो("-------------------------------"
               "\n  virt   file   size  section" "\n");
    लागि (i = 0; i < pe->sec_गन्ती; ++i) {
        DWORD addr, size;
        अचर वर्ण *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        size = si->sh_size;
        psh = &si->ish;

        यदि (2 == s1->verbose)
            म_लिखो("%6x %6x %6x  %s\n",
                (अचिन्हित)addr, (अचिन्हित)file_offset, (अचिन्हित)size, sh_name);

        विकल्प (si->cls) {
            पक्ष sec_text:
                यदि (!pe_header.opthdr.BaseOfCode)
                    pe_header.opthdr.BaseOfCode = addr;
                रोक;

            पक्ष sec_data:
#यदि PTR_SIZE == 4
                यदि (!pe_header.opthdr.BaseOfData)
                    pe_header.opthdr.BaseOfData = addr;
#endif
                रोक;

            पक्ष sec_bss:
                रोक;

            पक्ष sec_reloc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_BASERELOC, addr, size);
                रोक;

            पक्ष sec_rsrc:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_RESOURCE, addr, size);
                रोक;

            पक्ष sec_pdata:
                pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXCEPTION, addr, size);
                रोक;
        }

        यदि (pe->imp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IMPORT,
                pe->imp_offs, pe->imp_size);
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_IAT,
                pe->iat_offs, pe->iat_size);
        }
        यदि (pe->exp_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_EXPORT,
                pe->exp_offs, pe->exp_size);
        }
        यदि (pe->tls_size) {
            pe_set_datadir(&pe_header, IMAGE_DIRECTORY_ENTRY_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_size);
        }

        स_नकल(psh->Name, sh_name, umin(म_माप(sh_name), परिमाण psh->Name));
        यदि (pe->coffstr && म_माप(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((वर्ण*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->VirtualAddress = addr;
        psh->Misc.VirtualSize = size;
        pe_header.opthdr.SizeOfImage =
            umax(pe_virtual_align(pe, size + addr), pe_header.opthdr.SizeOfImage);

        यदि (si->data_size) {
            psh->PointerToRawData = file_offset;
            file_offset = pe_file_align(pe, file_offset + si->data_size);
            psh->SizeOfRawData = file_offset - psh->PointerToRawData;
            यदि (si->cls == sec_text)
                pe_header.opthdr.SizeOfCode += psh->SizeOfRawData;
            अन्यथा
                pe_header.opthdr.SizeOfInitializedData += psh->SizeOfRawData;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_header.filehdr.सङ्ख्या_Of_Sections = pe->sec_गन्ती;
    pe_header.opthdr.AddressOfEntryPoint = pe->start_addr;
    pe_header.opthdr.SizeOfHeaders = pe->sizeofheaders;
    pe_header.opthdr.ImageBase = pe->imagebase;
    pe_header.opthdr.Subsystem = pe->subsystem;
    pe_header.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    यदि (s1->pe_थाक_size)
        pe_header.opthdr.Size_Of_थाक_Reserve = s1->pe_थाक_size;
    यदि (PE_DLL == pe->type)
        pe_header.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_header.filehdr.Characteristics |= s1->pe_characteristics;
    यदि (pe->reloc)
        pe_header.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    यदि (pe->coffsym) {
        pe_add_coffsym(pe);
        pe_header.filehdr.Pointer_To_चिह्न_Table = file_offset;
        pe_header.filehdr.सङ्ख्या_Of_Symbols
            = pe->coffsym->data_offset / परिमाण (संरचना syment);
    }

    pe_fwrite(pe, &pe_header, परिमाण pe_header);
    लागि (i = 0; i < pe->sec_गन्ती; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, परिमाण(IMAGE_SECTION_HEADER));

    file_offset = pe->sizeofheaders;
    लागि (i = 0; i < pe->sec_गन्ती; ++i) {
        Section *s;
        si = pe->sec_info[i];
        यदि (!si->data_size)
            जारी;
        लागि (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_offset);
            pe_fwrite(pe, s->data, s->data_offset);
            यदि (s->prev)
                file_offset += s->prev->sh_addr - s->sh_addr;
        }
        file_offset = si->ish.PointerToRawData + si->ish.SizeOfRawData;
        pe_fpad(pe, file_offset);
    }

    यदि (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->data, pe->coffsym->data_offset);
        pe_fwrite(pe, pe->coffstr->data, pe->coffstr->data_offset);
        file_offset = pe->pos;
    }

    pe->sum += file_offset;
    ख_जाओ(pe->op, दुरत्व(संरचना pe_header, opthdr.CheckSum), शुरू_से);
    pe_fwrite(pe, &pe->sum, परिमाण (DWORD));

    ख_बंद (pe->op);
#ifndef _WIN32
    chmod(pe->filename, 0777);
#endif

    यदि (2 == s1->verbose)
        म_लिखो("-------------------------------\n");
    यदि (s1->verbose)
        म_लिखो("<- %s (%u bytes)\n", pe->filename, (अचिन्हित)file_offset);

    यदि (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    फर्काऊ 0;
}

/*----------------------------------------------------------------------------*/

स्थिर संरचना import_चिह्न *pe_add_import(संरचना pe_info *pe, पूर्णाङ्क sym_index)
{
    पूर्णाङ्क i;
    पूर्णाङ्क dll_index;
    संरचना pe_import_info *p;
    संरचना import_चिह्न *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->data + sym_index;
    dll_index = isym->st_size;

    i = dynarray_assoc ((शून्य**)pe->imp_info, pe->imp_गन्ती, dll_index);
    यदि (-1 != i) {
        p = pe->imp_info[i];
        गच्छ found_dll;
    }
    p = tcc_mallocz(परिमाण *p);
    p->dll_index = dll_index;
    dynarray_add(&pe->imp_info, &pe->imp_गन्ती, p);

found_dll:
    i = dynarray_assoc ((शून्य**)p->symbols, p->sym_गन्ती, sym_index);
    यदि (-1 != i)
        फर्काऊ p->symbols[i];

    s = tcc_mallocz(परिमाण *s);
    dynarray_add(&p->symbols, &p->sym_गन्ती, s);
    s->sym_index = sym_index;
    फर्काऊ s;
}

स्थिर शून्य pe_free_imports(संरचना pe_info *pe)
{
    पूर्णाङ्क i;
    लागि (i = 0; i < pe->imp_गन्ती; ++i) {
        संरचना pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_गन्ती);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_गन्ती);
}

/*----------------------------------------------------------------------------*/
स्थिर शून्य pe_build_imports(संरचना pe_info *pe)
{
    पूर्णाङ्क thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_base = pe->thunk->sh_addr - pe->imagebase;
    पूर्णाङ्क ndlls = pe->imp_गन्ती;
    TCCState *s1 = pe->s1;

    लागि (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_गन्ती;

    यदि (0 == sym_cnt)
        फर्काऊ;

    pe_align_section(pe->thunk, 16);
    pe->imp_size = (ndlls + 1) * परिमाण(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_size = (sym_cnt + ndlls) * परिमाण(ADDR3264);
    dll_ptr = pe->thunk->data_offset;
    thk_ptr = dll_ptr + pe->imp_size;
    ent_ptr = thk_ptr + pe->iat_size;
    pe->imp_offs = dll_ptr + rva_base;
    pe->iat_offs = thk_ptr + rva_base;
    section_ptr_add(pe->thunk, pe->imp_size + 2*pe->iat_size);

    लागि (i = 0; i < pe->imp_गन्ती; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        पूर्णाङ्क k, n, dllindex;
        ADDR3264 v;
        संरचना pe_import_info *p = pe->imp_info[i];
        अचर वर्ण *name;
        DLLReference *dllref;

        dllindex = p->dll_index;
        यदि (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        अन्यथा
            name = "", dllref = रिक्त;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->data + dll_ptr);
        hdr->FirstThunk = thk_ptr + rva_base;
        hdr->OriginalFirstThunk = ent_ptr + rva_base;
        hdr->Name = v + rva_base;

        लागि (k = 0, n = p->sym_गन्ती; k <= n; ++k) {
            यदि (k < n) {
                पूर्णाङ्क iat_index = p->symbols[k]->iat_index;
                पूर्णाङ्क sym_index = p->symbols[k]->sym_index;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->data + sym_index;
                अचर वर्ण *name = (वर्ण*)s1->dynsymtab_section->link->data + imp_sym->st_name;
                पूर्णाङ्क ordinal;

                /* patch symbol (and possibly its underscored alias) */
                गर {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->data + iat_index;
                    iat_index = esym->st_मान;
                    esym->st_मान = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_अङ्क;
                } जबसम्म (iat_index);

                यदि (dllref)
                    v = 0, ordinal = imp_sym->st_मान; /* ordinal from pe_load_def */
                अन्यथा
                    ordinal = 0, v = imp_sym->st_मान; /* address from tcc_add_symbol() */

#ifdef TCC_IS_NATIVE
                यदि (pe->type == PE_RUN) {
                    यदि (dllref) {
                        यदि ( !dllref->handle )
                            dllref->handle = LoadLibraryA(dllref->name);
                        v = (ADDR3264)GetProcAddress(dllref->handle, ordinal?(वर्ण*)0+ordinal:name);
                    }
                    यदि (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } अन्यथा
#endif
                यदि (ordinal) {
                    v = ordinal | (ADDR3264)1 << (परिमाण(ADDR3264)*8 - 1);
                } अन्यथा {
                    v = pe->thunk->data_offset + rva_base;
                    section_ptr_add(pe->thunk, परिमाण(WORD)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } अन्यथा {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->data+thk_ptr) =
            *(ADDR3264*)(pe->thunk->data+ent_ptr) = v;
            thk_ptr += परिमाण (ADDR3264);
            ent_ptr += परिमाण (ADDR3264);
        }
        dll_ptr += परिमाण(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

संरचना pe_sort_sym
{
    पूर्णाङ्क index;
    अचर वर्ण *name;
};

स्थिर पूर्णाङ्क sym_cmp(अचर शून्य *va, अचर शून्य *vb)
{
    अचर वर्ण *ca = (*(संरचना pe_sort_sym**)va)->name;
    अचर वर्ण *cb = (*(संरचना pe_sort_sym**)vb)->name;
    फर्काऊ म_भेद(ca, cb);
}

स्थिर शून्य pe_build_exports(संरचना pe_info *pe)
{
    ElfW(Sym) *sym;
    पूर्णाङ्क sym_index, sym_end;
    DWORD rva_base, base_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    पूर्णाङ्क sym_गन्ती, ord;
    संरचना pe_sort_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    खाता *op;
    वर्ण buf[260];
    अचर वर्ण *dllname;
    अचर वर्ण *name;

    rva_base = pe->thunk->sh_addr - pe->imagebase;
    sym_गन्ती = 0, sorted = रिक्त, op = रिक्त;

    sym_end = symtab_section->data_offset / परिमाण(ElfW(Sym));
    लागि (sym_index = 1; sym_index < sym_end; ++sym_index) {
        sym = (ElfW(Sym)*)symtab_section->data + sym_index;
        name = pe_export_name(s1, sym);
        यदि (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(परिमाण *p);
            p->index = sym_index;
            p->name = name;
            dynarray_add(&sorted, &sym_गन्ती, p);
        }
#यदि 0
        यदि (sym->st_other & ST_PE_EXPORT)
            म_लिखो("export: %s\n", name);
        यदि (sym->st_other & ST_PE_STDCALL)
            म_लिखो("stdcall: %s\n", name);
#endif
    }

    यदि (0 == sym_गन्ती)
        फर्काऊ;

    क्विक (sorted, sym_गन्ती, परिमाण *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    base_o = pe->thunk->data_offset;
    func_o = base_o + परिमाण(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_गन्ती * परिमाण (DWORD);
    ord_o = name_o + sym_गन्ती * परिमाण (DWORD);
    str_o = ord_o + sym_गन्ती * परिमाण(WORD);

    hdr = section_ptr_add(pe->thunk, str_o - base_o);
    hdr->Characteristics        = 0;
    hdr->Base                   = 1;
    hdr->सङ्ख्या_Of_Functions      = sym_गन्ती;
    hdr->सङ्ख्या_Of_Names          = sym_गन्ती;
    hdr->AddressOfFunctions     = func_o + rva_base;
    hdr->AddressOfNames         = name_o + rva_base;
    hdr->AddressOfNameOrdinals  = ord_o + rva_base;
    hdr->Name                   = str_o + rva_base;
    put_elf_str(pe->thunk, dllname);

#यदि 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, परिमाण buf, pe->filename);
    म_नकल(tcc_fileextension(buf), ".def");
    op = ख_खोलो(buf, "wb");
    यदि (रिक्त == op) {
        tcc_error_noabort("could not create '%s': %s", buf, म_त्रुटि(त्रुटि_सं));
    } अन्यथा {
        ख_लिखो(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        यदि (s1->verbose)
            म_लिखो("<- %s (%d symbol%s)\n", buf, sym_गन्ती, &"s"[sym_गन्ती < 2]);
    }
#endif

    लागि (ord = 0; ord < sym_गन्ती; ++ord)
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
        func_o += परिमाण (DWORD);
        name_o += परिमाण (DWORD);
        ord_o += परिमाण (WORD);
        यदि (op)
            ख_लिखो(op, "%s\n", name);
    }

    pe->exp_offs = base_o + rva_base;
    pe->exp_size = pe->thunk->data_offset - base_o;
    dynarray_reset(&sorted, &sym_गन्ती);
    यदि (op)
        ख_बंद(op);
}

/* ------------------------------------------------------------- */
स्थिर शून्य pe_build_reloc (संरचना pe_info *pe)
{
    DWORD offset, block_ptr, sh_addr, addr;
    पूर्णाङ्क गन्ती_2, i;
    ElfW_Rel *rel, *rel_end;
    Section *s = रिक्त, *sr;
    संरचना pe_reloc_header *hdr;
    TCCState *s1 = pe->s1;
    पूर्णाङ्क dwarf = 0, n;

    sh_addr = offset = block_ptr = गन्ती_2 = i = 0;
    rel = rel_end = रिक्त;

    लागि(;;) {
        यदि (rel < rel_end) {
            पूर्णाङ्क type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_offset + sh_addr;
            ++ rel;
            यदि (type != REL_TYPE_DIRECT)
                जारी;
            यदि (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->data + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                यदि (n >= s1->dwlo && n < s1->dwhi)
                    जारी;
            }
            यदि (गन्ती_2 == 0) { /* new block */
                block_ptr = pe->reloc->data_offset;
                section_ptr_add(pe->reloc, परिमाण(संरचना pe_reloc_header));
                offset = addr & 0xFFFFFFFF<<12;
            }
            यदि ((addr -= offset)  < (1<<12)) { /* one block spans 4k addresses */
                WORD *wp = section_ptr_add(pe->reloc, परिमाण (WORD));
                *wp = addr | PE_IMAGE_REL<<12;
                ++गन्ती_2;
                जारी;
            }
            -- rel;

        } अन्यथा यदि (s) {
            sr = s->reloc;
            यदि (sr) {
                rel = (ElfW_Rel *)sr->data;
                rel_end = (ElfW_Rel *)(sr->data + sr->data_offset);
                sh_addr = s->sh_addr;
                dwarf = s->sh_अङ्क >= s1->dwlo && s->sh_अङ्क < s1->dwhi;
            }
            s = s->prev;
            जारी;

        } अन्यथा यदि (i < pe->sec_गन्ती) {
            s = pe->sec_info[i]->sec, ++i;
            जारी;

        } अन्यथा यदि (!गन्ती_2)
            रोक;

        /* fill the last block and ready for a new one */
        यदि (गन्ती_2 & 1) /* align for DWORDS */
            section_ptr_add(pe->reloc, परिमाण(WORD)), ++गन्ती_2;
        hdr = (संरचना pe_reloc_header *)(pe->reloc->data + block_ptr);
        hdr -> offset = offset - pe->imagebase;
        hdr -> size = गन्ती_2 * परिमाण(WORD) + परिमाण(संरचना pe_reloc_header);
        गन्ती_2 = 0;
    }
}

/* ------------------------------------------------------------- */
स्थिर शून्य pe_build_tls(संरचना pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    पूर्णाङ्क c, n;

    यदि (0 == s) {
        pe->tls_size = परिमाण (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_add(pe->thunk, pe->tls_size, 16);
        pe->tls_data = section_add(data_section, PTR_SIZE * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, data_section->sh_अङ्क, 0);
        लागि (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_SIZE*n, REL_TYPE_DIRECT, c);
        /* for generators */
        set_elf_sym(symtab_section, pe->tls_data, PTR_SIZE * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, data_section->sh_अङ्क, "__tls_index");
        फर्काऊ;
    }

    यदि (0 == s1->tls_start)
        s1->tls_start = s->sh_addr;
    d = (शून्य*)(pe->thunk->data + pe->tls_dir);
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
स्थिर पूर्णाङ्क pe_section_class(Section *s)
{
    पूर्णाङ्क type, flags;
    अचर वर्ण *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    यदि (0 == स_भेद(name, ".stab", 5) || 0 == स_भेद(name, ".debug_", 7)) {
        फर्काऊ sec_debug;
    } अन्यथा यदि (flags & SHF_ALLOC) {
        यदि (flags & SHF_TLS)
            फर्काऊ sec_tdata + (type == SHT_NOBITS);
        यदि (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            यदि (flags & SHF_EXECINSTR)
                फर्काऊ sec_text;
            यदि (flags & SHF_WRITE)
                फर्काऊ sec_data;
            यदि (0 == म_भेद(name, ".rsrc"))
                फर्काऊ sec_rsrc;
            यदि (0 == म_भेद(name, ".iedat"))
                फर्काऊ sec_idata;
            यदि (0 == म_भेद(name, ".pdata"))
                फर्काऊ sec_pdata;
            फर्काऊ sec_rdata;
        } अन्यथा यदि (type == SHT_NOBITS) {
            फर्काऊ sec_bss;
        }
        फर्काऊ sec_other;
    } अन्यथा {
        यदि (0 == म_भेद(name, ".reloc"))
            फर्काऊ sec_reloc;
    }
    फर्काऊ sec_last;
}

स्थिर पूर्णाङ्क pe_assign_addresses (संरचना pe_info *pe)
{
    पूर्णाङ्क i, k, n, c, nbs;
    ADDR3264 addr;
    पूर्णाङ्क *sec_order, *sec_cls;
    संरचना section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    यदि (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_order = tcc_mallocz(2 * परिमाण (पूर्णाङ्क) * nbs);
    sec_cls = sec_order + nbs;
    लागि (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        लागि (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_order[n] = sec_order[n - 1];
        sec_cls[n] = k, sec_order[n] = i;
        यदि ((s->sh_flags & SHF_TLS) && 0 == pe->tls_size)
            pe_build_tls(pe, रिक्त);
    }
    si = रिक्त;
    addr = pe->imagebase + 1;
    लागि (i = 1; (c = sec_cls[i]) < sec_last; ++i) {
        s = s1->sections[sec_order[i]];

        यदि (PE_MERGE_DATA && c == sec_bss)
            c = sec_data;
        यदि (c == sec_tbss)
            c = sec_tdata;

        यदि (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } अन्यथा {
            si = रिक्त;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        यदि (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        यदि (s == pe->reloc)
            pe_build_reloc (pe);

        यदि (0 == s->data_offset)
            जारी;

        यदि (si)
            गच्छ add_section;

        si = tcc_mallocz(परिमाण *si);
        dynarray_add(&pe->sec_info, &pe->sec_गन्ती, si);

        म_नकल(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        यदि (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_CODE;
        अन्यथा यदि (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_DATA;
        अन्यथा
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_DATA;
        यदि (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        यदि (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

add_section:
        s->sh_info = pe->sec_गन्ती; /* section number for coff syms */
        addr += s->data_offset;
        si->sh_size = addr - si->sh_addr;
        यदि (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            जबसम्म (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = रिक्त;
            si->data_size = si->sh_size;
        }

        यदि (s->sh_flags & SHF_TLS) {
            म_नकल(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#यदि 0
    लागि (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_order[i]];
        पूर्णाङ्क type = s->sh_type;
        पूर्णाङ्क flags = s->sh_flags;
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
            (अचिन्हित)s->data_offset,
            s->sh_addralign,
            flags & SHF_ALLOC ? "alloc" : "",
            flags & SHF_WRITE ? "write" : "",
            flags & SHF_EXECINSTR ? "exec" : ""
            );
        ख_साफ(मानक_निकास);
    }
    s1->verbose = 2;
#endif
    tcc_free(sec_order);
    फर्काऊ 0;
}

/*----------------------------------------------------------------------------*/
स्थिर पूर्णाङ्क pe_check_symbols(संरचना pe_info *pe)
{
    पूर्णाङ्क sym_index, sym_end;
    पूर्णाङ्क ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(text_section, 8);

    sym_end = symtab_section->data_offset / परिमाण(ElfW(Sym));
    लागि (sym_index = 1; sym_index < sym_end; ++sym_index) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->data + sym_index;
        यदि (sym->st_shndx == SHN_UNDEF) {
            अचर वर्ण *name = (वर्ण*)symtab_section->link->data + sym->st_name;
            अचिन्हित type = ELFW(ST_TYPE)(sym->st_info);
            पूर्णाङ्क imp_sym = 0;
            संरचना import_चिह्न *is;

            पूर्णाङ्क _imp_, n;
            वर्ण buffer[200];
            अचर वर्ण *s, *p;

            n = _imp_ = 0;
            यदि (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            गर {
                s = pe_export_name(s1, sym);
                यदि (n) {
                    /* second try: */
                    यदि (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = म_खोजप(s, '@');
                        यदि (!p || s[0] != '_')
                            रोक;
                        म_नकल(buffer, s+1)[p-s-1] = 0, s = buffer;
                    } अन्यथा यदि (s[0] != '_') { /* try non-ansi function */
                        buffer[0] = '_', म_नकल(buffer + 1, s), s = buffer;
                    } अन्यथा यदि (0 == स_भेद(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } अन्यथा यदि (0 == स_भेद(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } अन्यथा {
                        रोक;
                    }
                }
                imp_sym = find_elf_sym(s1->dynsymtab_section, s);
            } जबसम्म (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            यदि (0 == imp_sym)
                जारी; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_add_import(pe, imp_sym);

            यदि (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                अचिन्हित offset = is->thk_offset;
                यदि (offset) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } अन्यथा {
                    अचिन्हित वर्ण *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    प्र_लिखो(buffer, "IAT.%s", name);
                    is->iat_index = put_elf_sym(
                        symtab_section, 0, परिमाण(DWORD),
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
#अथवायदि defined(TCC_TARGET_ARM64)
                    p = section_ptr_add(text_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, text_section,
                        offset + 16, R_XXX_THUNKFIX, is->iat_index);
#अन्यथा
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
                sym->st_मान = offset;
                sym->st_shndx = text_section->sh_अङ्क;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } अन्यथा { /* STT_OBJECT */
                यदि (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_मान = is->iat_index; /* chain potential alias */
                is->iat_index = sym_index;
            }

        } अन्यथा यदि (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    फर्काऊ ret;
}

/*----------------------------------------------------------------------------*/
#यदि PE_PRINT_SECTIONS
स्थिर शून्य pe_print_section(खाता * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    पूर्णाङ्क i, n, l, m;
    p = s->data;
    e = s->data + s->data_offset;
    l = e - p;

    ख_लिखो(f, "section  \"%s\"", s->name);
    यदि (s->link)
        ख_लिखो(f, "\nlink     \"%s\"", s->link->name);
    यदि (s->reloc)
        ख_लिखो(f, "\nreloc    \"%s\"", s->reloc->name);
    ख_लिखो(f, "\nv_addr   %08X", (अचिन्हित)s->sh_addr);
    ख_लिखो(f, "\ncontents %08X", (अचिन्हित)l);
    ख_लिखो(f, "\n\n");

    यदि (s->sh_type == SHT_NOBITS)
        फर्काऊ;

    यदि (0 == l)
        फर्काऊ;

    यदि (s->sh_type == SHT_SYMTAB)
        m = परिमाण(ElfW(Sym));
    अन्यथा यदि (s->sh_type == SHT_RELX)
        m = परिमाण(ElfW_Rel);
    अन्यथा
        m = 16;

    ख_लिखो(f, "%-8s", "offset");
    लागि (i = 0; i < m; ++i)
        ख_लिखो(f, " %02x", i);
    n = 56;

    यदि (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        अचर वर्ण *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            रिक्त
        };

        अचर वर्ण *fields2[] = {
            "offs",
            "type",
            "symb",
            रिक्त
        };

        अचर वर्ण **p;

        यदि (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        अन्यथा
            p = fields2, n = 58;

        लागि (i = 0; p[i]; ++i)
            ख_लिखो(f, "%6s", p[i]);
        ख_लिखो(f, "  symbol");
    }

    ख_लिखो(f, "\n");
    लागि (i = 0; i < n; ++i)
        ख_लिखो(f, "-");
    ख_लिखो(f, "\n");

    लागि (i = 0; i < l;)
    {
        ख_लिखो(f, "%08X", i);
        लागि (n = 0; n < m; ++n) {
            यदि (n + i < l)
                ख_लिखो(f, " %02X", p[i + n]);
            अन्यथा
                ख_लिखो(f, "   ");
        }

        यदि (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            अचर वर्ण *name = s->link->data + sym->st_name;
            ख_लिखो(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (अचिन्हित)sym->st_name,
                    (अचिन्हित)sym->st_मान,
                    (अचिन्हित)sym->st_size,
                    (अचिन्हित)ELFW(ST_BIND)(sym->st_info),
                    (अचिन्हित)ELFW(ST_TYPE)(sym->st_info),
                    (अचिन्हित)sym->st_other,
                    (अचिन्हित)sym->st_shndx,
                    name);

        } अन्यथा यदि (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->data + ELFW(R_SYM)(rel->r_info);
            अचर वर्ण *name = s->link->link->data + sym->st_name;
            ख_लिखो(f, "  %04X   %02X   %04X  \"%s\"",
                    (अचिन्हित)rel->r_offset,
                    (अचिन्हित)ELFW(R_TYPE)(rel->r_info),
                    (अचिन्हित)ELFW(R_SYM)(rel->r_info),
                    name);
        } अन्यथा {
            ख_लिखो(f, "   ");
            लागि (n = 0; n < m; ++n) {
                यदि (n + i < l) {
                    b = p[i + n];
                    यदि (b < 32 || b >= 127)
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

स्थिर शून्य pe_print_sections(TCCState *s1, अचर वर्ण *fname)
{
    Section *s;
    खाता *f;
    पूर्णाङ्क i;
    f = ख_खोलो(fname, "w");
    लागि (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    ख_बंद(f);
}
#endif

/* ------------------------------------------------------------- */

ST_FUNC पूर्णाङ्क pe_putimport(TCCState *s1, पूर्णाङ्क dllindex, अचर वर्ण *name, addr_t मान)
{
    फर्काऊ set_elf_sym(
        s1->dynsymtab_section,
        मान,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        मान ? SHN_ABS : SHN_UNDEF,
        name
        );
}

स्थिर पूर्णाङ्क read_mem(पूर्णाङ्क fd, अचिन्हित offset, शून्य *buffer, अचिन्हित len)
{
    lseek(fd, offset, शुरू_से);
    फर्काऊ len == पठ(fd, buffer, len);
}

/* ------------------------------------------------------------- */

स्थिर पूर्णाङ्क get_dllexports(पूर्णाङ्क fd, वर्ण **pp)
{
    पूर्णाङ्क i, k, l, n, n0, ret;
    वर्ण *p;

    IMAGE_SECTION_HEADER ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_HEADER dh;
    IMAGE_FILE_HEADER ih;
    DWORD sig, ref, addr;
    DWORD *namep = रिक्त, p0 = 0, p1;

    पूर्णाङ्क pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = रिक्त;
    ret = 1;
    यदि (!read_mem(fd, 0, &dh, परिमाण dh))
        गच्छ the_end;
    यदि (!read_mem(fd, dh.e_lfanew, &sig, परिमाण sig))
        गच्छ the_end;
    यदि (sig != 0x00004550)
        गच्छ the_end;
    pef_hdroffset = dh.e_lfanew + परिमाण sig;
    यदि (!read_mem(fd, pef_hdroffset, &ih, परिमाण ih))
        गच्छ the_end;
    opt_hdroffset = pef_hdroffset + परिमाण ih;
    यदि (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + परिमाण oh;
        यदि (!read_mem(fd, opt_hdroffset, &oh, परिमाण oh))
            गच्छ the_end;
        यदि (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.सङ्ख्या_Of_Rva_And_Sizes)
            गच्छ the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } अन्यथा यदि (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + परिमाण oh;
        यदि (!read_mem(fd, opt_hdroffset, &oh, परिमाण oh))
            गच्छ the_end;
        यदि (IMAGE_DIRECTORY_ENTRY_EXPORT >= oh.सङ्ख्या_Of_Rva_And_Sizes)
            गच्छ the_end_0;
        addr = oh.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } अन्यथा
        गच्छ the_end;

    //printf("addr: %08x\n", addr);
    लागि (i = 0; i < ih.सङ्ख्या_Of_Sections; ++i) {
        यदि (!read_mem(fd, sec_hdroffset + i * परिमाण ish, &ish, परिमाण ish))
            गच्छ the_end;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        यदि (addr >= ish.VirtualAddress && addr < ish.VirtualAddress + ish.SizeOfRawData)
            गच्छ found;
    }
    गच्छ the_end_0;
found:
    ref = ish.VirtualAddress - ish.PointerToRawData;
    यदि (!read_mem(fd, addr - ref, &ied, परिमाण ied))
        गच्छ the_end;
    k = ied.सङ्ख्या_Of_Names;
    यदि (k) {
        namep = tcc_malloc(l = k * परिमाण *namep);
        यदि (!read_mem(fd, ied.AddressOfNames - ref, namep, l))
            गच्छ the_end;
        लागि (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            यदि (p1 != p0)
                lseek(fd, p0 = p1, शुरू_से), l = 0;
            गर {
                यदि (0 == l) {
                    यदि (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    यदि ((l = पठ(fd, p + n, 1000 - 1)) <= 0)
                        गच्छ the_end;
                }
                --l, ++p0;
            } जबसम्म (p[n++]);
        }
        p[n] = 0;
    }
the_end_0:
    ret = 0;
the_end:
    tcc_free(namep);
    यदि (ret && p)
        tcc_free(p), p = रिक्त;
    *pp = p;
    फर्काऊ ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

स्थिर पूर्णाङ्क pe_load_res(TCCState *s1, पूर्णाङ्क fd)
{
    संरचना pe_rsrc_header hdr;
    Section *rsrc_section;
    पूर्णाङ्क i, ret = -1, sym_index;
    BYTE *ptr;
    अचिन्हित offs;

    यदि (!read_mem(fd, 0, &hdr, परिमाण hdr))
        गच्छ quit;

    यदि (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.सङ्ख्या_Of_Sections != 1
        || म_भेद((वर्ण*)hdr.sectionhdr.Name, ".rsrc") != 0)
        गच्छ quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_add(rsrc_section, hdr.sectionhdr.SizeOfRawData);
    offs = hdr.sectionhdr.PointerToRawData;
    यदि (!read_mem(fd, offs, ptr, hdr.sectionhdr.SizeOfRawData))
        गच्छ quit;
    offs = hdr.sectionhdr.PointerToRelocations;
    sym_index = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_अङ्क, ".rsrc");
    लागि (i = 0; i < hdr.sectionhdr.सङ्ख्या_Of_Relocations; ++i) {
        संरचना pe_rsrc_reloc rel;
        यदि (!read_mem(fd, offs, &rel, परिमाण rel))
            गच्छ quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        यदि (rel.type != RSRC_RELTYPE)
            गच्छ quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.offset, R_XXX_RELATIVE, sym_index);
        offs += परिमाण rel;
    }
    ret = 0;
quit:
    फर्काऊ ret;
}

/* ------------------------------------------------------------- */

स्थिर वर्ण *trimfront(वर्ण *p)
{
    जबसम्म ((अचिन्हित वर्ण)*p <= ' ' && *p && *p != '\n')
	++p;
    फर्काऊ p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

स्थिर वर्ण *get_token(वर्ण **s, वर्ण *f)
{
    वर्ण *p, *e;
    पूर्णाङ्क q;

    p = trimfront(*s);
    q = *p;
    यदि (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    अन्यथा
        q = ' ';
    लागि (e = p; (अचिन्हित वर्ण)*e >= ' ' && *e != q; ++e)
        ;
    यदि (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    फर्काऊ p;
}

स्थिर पूर्णाङ्क pe_load_def(TCCState *s1, पूर्णाङ्क fd)
{
    पूर्णाङ्क state = 0, ret = -1, dllindex = 0, ord;
    वर्ण dllname[80], *buf, *पङ्क्ति, *p, *x, next;

    buf = tcc_load_text(fd);
    यदि (!buf)
        फर्काऊ ret;

    लागि (पङ्क्ति = buf;; ++पङ्क्ति)  {
        p = get_token(&पङ्क्ति, &next);
        यदि (!(*p && *p != ';'))
            गच्छ skip;
        विकल्प (state) {
        पक्ष 0:
            यदि (0 != stricmp(p, "LIBRARY") || next == '\n')
                गच्छ quit;
            pstrcpy(dllname, परिमाण dllname, get_token(&पङ्क्ति, &next));
            यदि (!*tcc_fileextension(dllname))
                pstrcat(dllname, परिमाण dllname, ".dll");
            ++state;
            रोक;
        पक्ष 1:
            यदि (0 != stricmp(p, "EXPORTS"))
                गच्छ quit;
            ++state;
            रोक;
        पक्ष 2:
            dllindex = tcc_add_dllref(s1, dllname, 0)->index;
            ++state;
            /* fall through */
        स्वभाव:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            यदि (next == '@') {
                x = get_token(&पङ्क्ति, &next);
                ord = (पूर्णाङ्क)म_से_दीर्घ(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            रोक;
        }
skip:
        जबसम्म ((अचिन्हित वर्ण)next > ' ')
            get_token(&पङ्क्ति, &next);
        यदि (next != '\n')
            रोक;
    }
    ret = 0;
quit:
    tcc_free(buf);
    फर्काऊ ret;
}

/* ------------------------------------------------------------- */

स्थिर पूर्णाङ्क pe_load_dll(TCCState *s1, पूर्णाङ्क fd, अचर वर्ण *filename)
{
    वर्ण *p, *q;
    DLLReference *ref = tcc_add_dllref(s1, filename, 0);
    यदि (ref->found)
        फर्काऊ 0;
    यदि (get_dllexports(fd, &p))
        फर्काऊ -1;
    यदि (p) {
        लागि (q = p; *q; q += 1 + म_माप(q))
            pe_putimport(s1, ref->index, q, 0);
        tcc_free(p);
    }
    फर्काऊ 0;
}

ST_FUNC पूर्णाङ्क pe_load_file(संरचना TCCState *s1, पूर्णाङ्क fd, अचर वर्ण *filename)
{
    पूर्णाङ्क ret = -1;
    वर्ण buf[10];
    यदि (0 == म_भेद(tcc_fileextension(filename), ".def"))
        ret = pe_load_def(s1, fd);
    अन्यथा यदि (pe_load_res(s1, fd) == 0)
        ret = 0;
    अन्यथा यदि (read_mem(fd, 0, buf, 4) && 0 == स_भेद(buf, "MZ", 2))
        ret = pe_load_dll(s1, fd, filename);
    फर्काऊ ret;
}

PUB_FUNC पूर्णाङ्क tcc_get_dllexports(अचर वर्ण *filename, वर्ण **pp)
{
    पूर्णाङ्क ret, fd = खोलो(filename, O_RDONLY | O_द्विआधारी_2);
    यदि (fd < 0)
        फर्काऊ -1;
    ret = get_dllexports(fd, pp);
    बंद(fd);
    फर्काऊ ret;
}

/* ------------------------------------------------------------- */
#ifdef TCC_TARGET_X86_64
स्थिर अचिन्हित pe_add_unwind_info(TCCState *s1)
{
    यदि (रिक्त == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    यदि (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, text_section->sh_अङ्क, ".uw_base");
    यदि (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        स्थिर अचर अचिन्हित वर्ण uw_info[] = {
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
        अचिन्हित वर्ण *p;

        section_ptr_add(s, -s->data_offset & 3); /* align */
        s1->uw_offs = s->data_offset;
        p = section_ptr_add(s, परिमाण uw_info);
        स_नकल(p, uw_info, परिमाण uw_info);
    }

    फर्काऊ s1->uw_offs;
}

ST_FUNC शून्य pe_add_unwind_data(अचिन्हित start, अचिन्हित end, अचिन्हित थाक)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    अचिन्हित o, n, d;
    संरचना /* _RUNTIME_FUNCTION */ {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD UnwindData;
    } *p;

    d = pe_add_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->data_offset;
    p = section_ptr_add(pd, परिमाण *p);

    /* record this function */
    p->BeginAddress = start;
    p->EndAddress = end;
    p->UnwindData = d;

    /* put relocations on it */
    लागि (n = o + परिमाण *p; o < n; o += परिमाण p->BeginAddress)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#अथवायदि defined(TCC_TARGET_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
स्थिर Section *pe_add_unwind_info(TCCState *s1)
{
    Section *s;

    यदि (रिक्त == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = find_section(s1, ".xdata");
    s->sh_addralign = 4;
    यदि (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  text_section->sh_अङ्क, ".uw_text_base");
    यदि (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_अङ्क, ".uw_base");
    फर्काऊ s;
}

ST_FUNC शून्य pe_add_unwind_data(अचिन्हित start, अचिन्हित end, अचिन्हित थाक)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    अचिन्हित o, d, code_bytes, func_len;
    अचिन्हित वर्ण *q;
    uint32_t header;
    संरचना /* _RUNTIME_FUNCTION */ {
        DWORD BeginAddress;
        DWORD UnwindData;
    } *p;

    पूर्णाङ्क epilog;

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
    जबसम्म ((अचिन्हित)(q - (xd->data + d + 4)) < code_bytes)
        *q++ = 0xE3; /* nop padding */

    o = pd->data_offset;
    p = section_ptr_add(pd, परिमाण *p);
    p->BeginAddress = start;
    p->UnwindData = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#endif
/* ------------------------------------------------------------- */
#यदि defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
#define PE_STDSYM(n,s) n
#अन्यथा
#define PE_STDSYM(n,s) "_" n s
#endif

स्थिर शून्य pe_add_runtime(TCCState *s1, संरचना pe_info *pe)
{
    अचर वर्ण *start_चिह्न;
    पूर्णाङ्क pe_type;

    यदि (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        start_चिह्न = PE_STDSYM("__dllstart","@12");
    } अन्यथा {
        अचर वर्ण *run_चिह्न;
        यदि (find_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            start_चिह्न = "__winstart";
            run_चिह्न = "__runwinmain";
            pe_type = PE_GUI;
        } अन्यथा यदि (find_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            start_चिह्न = "__wwinstart";
            run_चिह्न = "__runwwinmain";
            pe_type = PE_GUI;
        } अन्यथा यदि (find_elf_sym(symtab_section, "wmain")) {
            start_चिह्न = "__wstart";
            run_चिह्न = "__runwmain";
            pe_type = PE_EXE;
        } अन्यथा {
            start_चिह्न =  "__start";
            run_चिह्न = "__runmain";
            pe_type = PE_EXE;
            यदि (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        यदि (TCC_OUTPUT_MEMORY == s1->output_type && !s1->nostdlib)
            start_चिह्न = run_चिह्न;
    }
    यदि (s1->elf_entryname) {
        pe->start_चिह्न = start_चिह्न = s1->elf_entryname;
    } अन्यथा {
        pe->start_चिह्न = start_चिह्न + 1;
        यदि (!s1->leading_underscore || म_अक्षर(start_चिह्न, '@'))
            ++start_चिह्न;
    }

#ifdef CONFIG_TCC_BACKTRACE
    यदि (s1->do_backtrace) {
#ifdef CONFIG_TCC_BCHECK
        यदि (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    यदि (s1->output_type == TCC_OUTPUT_MEMORY)
                tcc_add_support(s1, "bcheck_run.o");
	    अन्यथा
                tcc_add_support(s1, "bcheck.o");
	}
#endif
        यदि (s1->output_type == TCC_OUTPUT_EXE)
            tcc_add_support(s1, "bt-exe.o");
        यदि (s1->output_type == TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-dll.o");
        यदि (s1->output_type != TCC_OUTPUT_DLL)
            tcc_add_support(s1, "bt-log.o");
        tcc_add_btstub(s1);
    }
#endif

    /* grab the startup code from libtcc1.a */
#ifdef TCC_IS_NATIVE
    यदि (TCC_OUTPUT_MEMORY != s1->output_type || s1->run_main)
#endif
    set_global_sym(s1, start_चिह्न, रिक्त, 0);

    यदि (0 == s1->nostdlib) {
        स्थिर अचर वर्ण * अचर libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", रिक्त
        };
        अचर वर्ण * अचर *pp, *p;
        यदि (TCC_LIBTCC1[0])
            tcc_add_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        लागि (pp = libs; 0 != (p = *pp); ++pp) {
            यदि (*p)
                tcc_add_library(s1, p);
            अन्यथा यदि (PE_DLL != pe_type && PE_GUI != pe_type)
                रोक;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    यदि (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    यदि (TCC_OUTPUT_MEMORY == s1->output_type)
        pe_type = PE_RUN;
    pe->type = pe_type;
}

ST_FUNC पूर्णाङ्क pe_setsubsy(TCCState *s1, अचर वर्ण *arg)
{
    स्थिर अचर संरचना subsy { अचर वर्ण* p; पूर्णाङ्क v; } x[] = {
#यदि defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#अथवायदि defined(TCC_TARGET_ARM)
        { "wince", 9 },
#endif
        { 0, -1 }};
    अचर संरचना subsy *y;
    लागि (y = x;; ++y) {
        यदि (!y->p)
            फर्काऊ -1;
        यदि (0 == म_भेद(y->p, arg)) {
            s1->pe_subsystem = y->v;
            फर्काऊ 0;
        }
    }
}

स्थिर शून्य pe_set_options(TCCState * s1, संरचना pe_info *pe)
{
    यदि (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_BASE_DLL;
    } अन्यथा {
        pe->imagebase = IMAGE_BASE_EXE;
    }

#यदि defined(TCC_TARGET_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#अन्यथा
    यदि (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    अन्यथा
        pe->subsystem = 3;
#endif
    /* Allow override via -Wl,-subsystem=... option */
    यदि (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    यदि (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } अन्यथा {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    यदि (s1->section_align != 0)
        pe->section_align = s1->section_align;
    यदि (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    यदि ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    यदि (s1->has_text_addr)
        pe->imagebase = s1->text_addr;
}

ST_FUNC पूर्णाङ्क pe_output_file(TCCState *s1, अचर वर्ण *filename)
{
    संरचना pe_info pe;

    स_रखो(&pe, 0, परिमाण pe);
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
    यदि (s1->nb_errors)
        गच्छ done;
    यदि (filename) {
        pe_assign_addresses(&pe);
        relocate_syms(s1, s1->symtab, 0);
        यदि (s1->nb_errors)
            गच्छ done;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.start_addr = (DWORD)
            (get_sym_addr(s1, pe.start_चिह्न, 1, 1) - pe.imagebase);
        यदि (s1->nb_errors)
            गच्छ done;
        pe_write(&pe);
    } अन्यथा {
        /* -run */
#ifdef TCC_IS_NATIVE
        pe.thunk = data_section;
        pe_build_imports(&pe);
        s1->run_main = pe.start_चिह्न;
#यदि defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        s1->uw_pdata = find_section(s1, ".pdata");
#endif
#endif
    }
done:
    dynarray_reset(&pe.sec_info, &pe.sec_गन्ती);
    pe_free_imports(&pe);
#यदि PE_PRINT_SECTIONS
    यदि (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#endif
    फर्काऊ s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
