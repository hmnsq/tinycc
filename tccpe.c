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

#परिभाषय PE_MERGE_दत्त 1
#परिभाषय PE_PRINT_SECTIONS 0

#यदि_अपरिभाषितम् _WIN32
#परिभाषय stricmp strcasecmp
#परिभाषय strnicmp strncasecmp
#अन्तर्भाव <sys/stat.h> /* chmod() */
#यदि_अन्तः

#यदि defined TCC_TARGET_X86_64
# define REL_TYPE_प्रत्यक्षम् R_X86_64_64
# define R_XXX_THUNKFIX R_X86_64_PC32
# define R_XXX_RELATIVE R_X86_64_RELATIVE
# define R_XXX_FUNCCALL R_X86_64_PLT32
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0x8664
# define CHARACTERISTICS_EXE 0x022F
# define CHARACTERISTICS_DLL 0x222E
# define IMAGE_आधारः_EXE 0x00400000
# define IMAGE_आधारः_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#नोचेद्यदि defined TCC_TARGET_ARM
# define REL_TYPE_प्रत्यक्षम् R_ARM_ABS32
# define R_XXX_THUNKFIX R_ARM_ABS32
# define R_XXX_RELATIVE R_ARM_RELATIVE
# define R_XXX_FUNCCALL R_ARM_PC24
# define R_XXX_FUNCCALL2 R_ARM_ABS32
# define RSRC_RELTYPE 7 /* ??? (not tested) */
# define IMAGE_FILE_MACHINE 0x01C0
# define CHARACTERISTICS_EXE 0x010F
# define CHARACTERISTICS_DLL 0x230F
# define IMAGE_आधारः_EXE 0x00100000
# define IMAGE_आधारः_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#नोचेद्यदि defined TCC_TARGET_ARM64
# define REL_TYPE_प्रत्यक्षम् R_AARCH64_ABS64
# define R_XXX_THUNKFIX R_AARCH64_ABS64
# define R_XXX_RELATIVE R_AARCH64_RELATIVE
# define R_XXX_FUNCCALL R_AARCH64_CALL26
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0xAA64
# define CHARACTERISTICS_EXE 0x0022
# define CHARACTERISTICS_DLL 0x2022
# define IMAGE_आधारः_EXE 0x140000000ULL
# define IMAGE_आधारः_DLL 0x180000000ULL
# define OS_VER 0x0602
# define DLLCHARACTERISTICS 0x8160

#नोचेद्यदि defined TCC_TARGET_I386
# define REL_TYPE_प्रत्यक्षम् R_386_32
# define R_XXX_THUNKFIX R_386_32
# define R_XXX_RELATIVE R_386_RELATIVE
# define R_XXX_FUNCCALL R_386_PC32
# define RSRC_RELTYPE 7 /* DIR32NB */
# define IMAGE_FILE_MACHINE 0x014C
# define CHARACTERISTICS_EXE 0x030F
# define CHARACTERISTICS_DLL 0x230E
# define IMAGE_आधारः_EXE 0x00400000
# define IMAGE_आधारः_DLL 0x10000000
# define OS_VER 0x0400
# define DLLCHARACTERISTICS 0
#यदि_अन्तः

#यदि PTR_आकार == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#अन्यथा
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#यदि_अन्तः

#यदि_अपरिभाषितम् IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

प्रकारनिर्देश अचिह्नित वर्ण BYTE;
प्रकारनिर्देश अचिह्नित ह्रस्व WORD;
प्रकारनिर्देश अचिह्नित पूर्णाङ्क DWORD;
प्रकारनिर्देश अचिह्नित दीर्घ दीर्घ ULONGLONG;
#निर्देशः pack(प्रक्षिप, 1)

प्रकारनिर्देश संरचना IMAGE_DOS_शीर्षकम् {  /* DOS .EXE header */
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
} IMAGE_DOS_शीर्षकम्_2, *PIMAGE_DOS_शीर्षकम्;

#परिभाषय IMAGE_NT_SIGNATURE  0x00004550  /* PE00 */

प्रकारनिर्देश संरचना IMAGE_FILE_शीर्षकम् {
    WORD    Machine;
    WORD    सङ्ख्या_सम्बन्धि_Sections;
    DWORD   TimeDateStamp;
    DWORD   Pointer_गन्तव्यम्_चिह्नम्_सारणी;
    DWORD   सङ्ख्या_सम्बन्धि_Symbols;
    WORD    आकार_सम्बन्धि_Optional_शीर्षकम्;
    WORD    Characteristics;
} IMAGE_FILE_शीर्षकम्_2, *PIMAGE_FILE_शीर्षकम्;


#परिभाषय IMAGE_SIZEOF_FILE_शीर्षकम् 20

प्रकारनिर्देश संरचना IMAGE_दत्त_DIRECTORY {
    DWORD   Virtual_स्थानाङ्कः;
    DWORD   आकार_3;
} IMAGE_दत्त_DIRECTORY_2, *PIMAGE_दत्त_DIRECTORY;


प्रकारनिर्देश संरचना IMAGE_OPTIONAL_शीर्षकम् {
    /* Standard fields. */
    WORD    Magic;
    BYTE    Major_Linker_संस्करणम्;
    BYTE    Minor_Linker_संस्करणम्;
    DWORD   आकार_सम्बन्धि_संहिता;
    DWORD   आकार_सम्बन्धि_Initialized_दत्त;
    DWORD   आकार_सम्बन्धि_Uninitialized_दत्त;
    DWORD   स्थानाङ्कः_सम्बन्धि_प्रविष्टिः_Point;
    DWORD   आधारः_सम्बन्धि_संहिता;
#यदि PTR_आकार == 4
    DWORD   आधारः_सम्बन्धि_दत्त;
#यदि_अन्तः
    /* NT additional fields. */
    ADDR3264 Image_आधारः;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    WORD    Major_Operating_System_संस्करणम्;
    WORD    Minor_Operating_System_संस्करणम्;
    WORD    Major_Image_संस्करणम्;
    WORD    Minor_Image_संस्करणम्;
    WORD    Major_Subsystem_संस्करणम्;
    WORD    Minor_Subsystem_संस्करणम्;
    DWORD   Win32_संस्करणम्_मानम्;
    DWORD   आकार_सम्बन्धि_Image;
    DWORD   आकार_सम्बन्धि_शीर्षकाणि;
    DWORD   Check_योग;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    ADDR3264 आकार_सम्बन्धि_राशिः_Reserve;
    ADDR3264 आकार_सम्बन्धि_राशिः_Commit;
    ADDR3264 आकार_सम्बन्धि_Heap_Reserve;
    ADDR3264 आकार_सम्बन्धि_Heap_Commit;
    DWORD   LoaderFlags;
    DWORD   सङ्ख्या_सम्बन्धि_Rva_And_Sizes;
    IMAGE_दत्त_DIRECTORY_2 दत्त_Directory[16];
} IMAGE_OPTIONAL_HEADER32, IMAGE_OPTIONAL_HEADER64, IMAGE_OPTIONAL_शीर्षकम्_2;

#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_EXPORT          0   /* Export Directory */
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_IMPORT          1   /* Import Directory */
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_RESOURCE        2   /* Resource Directory */
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_EXCEPTION       3   /* Exception Directory */
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_SECURITY        4   /* Security Directory */
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_BASERELOC       5   /* Base Relocation Table */
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_DEBUG           6   /* Debug Directory */
/*      IMAGE_DIRECTORY_ENTRY_COPYRIGHT       7      (X86 usage) */
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_ARCHITECTURE    7   /* Architecture Specific Data */
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_GLOBALPTR       8   /* RVA of GP */
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_TLS             9   /* TLS Directory */
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_आरोपय_CONFIG    10   /* Load Configuration Directory */
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_BOUND_IMPORT   11   /* Bound Import Directory in headers */
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_IAT            12   /* Import Address Table */
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_DELAY_IMPORT   13   /* Delay Load Import Descriptors */
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_COM_DESCRIPTOR 14   /* COM Runtime descriptor */

/* Section header format. */
#परिभाषय IMAGE_SIZEOF_SHORT_NAME         8

प्रकारनिर्देश संरचना IMAGE_SECTION_शीर्षकम् {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    सङ्घ {
            DWORD   Physical_स्थानाङ्कः;
            DWORD   Virtual_आकार;
    } Misc;
    DWORD   Virtual_स्थानाङ्कः;
    DWORD   आकार_सम्बन्धि_Raw_दत्त;
    DWORD   Pointer_गन्तव्यम्_Raw_दत्त;
    DWORD   Pointer_गन्तव्यम्_Relocations;
    DWORD   Pointer_गन्तव्यम्_Linenumbers;
    WORD    सङ्ख्या_सम्बन्धि_Relocations;
    WORD    सङ्ख्या_सम्बन्धि_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_शीर्षकम्_2, *PIMAGE_SECTION_शीर्षकम्;

#परिभाषय IMAGE_SIZEOF_SECTION_शीर्षकम्     40

प्रकारनिर्देश संरचना _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD Major_संस्करणम्;
    WORD Minor_संस्करणम्;
    DWORD Name;
    DWORD आधारः_2;
    DWORD सङ्ख्या_सम्बन्धि_Functions;
    DWORD सङ्ख्या_सम्बन्धि_नामानि;
    DWORD स्थानाङ्कः_सम्बन्धि_Functions;
    DWORD स्थानाङ्कः_सम्बन्धि_नामानि;
    DWORD स्थानाङ्कः_सम्बन्धि_Name_Ordinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

प्रकारनिर्देश संरचना _IMAGE_TLS_DIRECTORY {
    ADDR3264 Start_स्थानाङ्कः_सम्बन्धि_Raw_दत्त;
    ADDR3264 अन्तः_स्थानाङ्कः_सम्बन्धि_Raw_दत्त;
    ADDR3264 स्थानाङ्कः_सम्बन्धि_सूचकांक;
    ADDR3264 स्थानाङ्कः_सम्बन्धि_Call_Backs;
    DWORD आकार_सम्बन्धि_Zero_Fill;
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

प्रकारनिर्देश संरचना IMAGE_आधारः_RELOCATION {
    DWORD   Virtual_स्थानाङ्कः;
    DWORD   आकार_सम्बन्धि_खण्डम्;
//  WORD    TypeOffset[1];
} IMAGE_आधारः_RELOCATION_2;

#परिभाषय IMAGE_SIZEOF_आधारः_RELOCATION     8

#परिभाषय IMAGE_REL_BASED_ABSOLUTE         0
#परिभाषय IMAGE_REL_BASED_उच्चः             1
#परिभाषय IMAGE_REL_BASED_नीचः              2
#परिभाषय IMAGE_REL_BASED_HIGHLOW          3
#परिभाषय IMAGE_REL_BASED_HIGHADJ          4
#परिभाषय IMAGE_REL_BASED_MIPS_JMPADDR     5
#परिभाषय IMAGE_REL_BASED_SECTION          6
#परिभाषय IMAGE_REL_BASED_REL32            7
#परिभाषय IMAGE_REL_BASED_DIR64           10

#परिभाषय IMAGE_SCN_CNT_संहिता                  0x00000020
#परिभाषय IMAGE_SCN_CNT_INITIALIZED_दत्त      0x00000040
#परिभाषय IMAGE_SCN_CNT_UNINITIALIZED_दत्त    0x00000080
#परिभाषय IMAGE_SCN_MEM_DISCARDABLE           0x02000000
#परिभाषय IMAGE_SCN_MEM_SHARED                0x10000000
#परिभाषय IMAGE_SCN_MEM_EXECUTE               0x20000000
#परिभाषय IMAGE_SCN_MEM_READ                  0x40000000
#परिभाषय IMAGE_SCN_MEM_WRITE                 0x80000000

#परिभाषय IMAGE_DLLCHARACTERISTICS_उच्चः_ENTROPY_VA 0x0020
#परिभाषय IMAGE_DLLCHARACTERISTICS_DYNAMIC_आधारः 0x0040
#परिभाषय IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#परिभाषय IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#परिभाषय IMAGE_FILE_RELOCS_STRIPPED 0x0001

#निर्देशः pack(निष्कासय)

/* ----------------------------------------------------------- */
#यदि_अन्तः /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#यदि_अपरिभाषितम् IMAGE_DLLCHARACTERISTICS_DYNAMIC_आधारः
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #परिभाषय IMAGE_DLLCHARACTERISTICS_DYNAMIC_आधारः 0x0040
#यदि_अन्तः

#निर्देशः pack(प्रक्षिप, 1)
संरचना pe_शीर्षकम्
{
    IMAGE_DOS_शीर्षकम्_2 doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_शीर्षकम्_2 filehdr;
#यदि PTR_आकार == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#अन्यथा
#यदि_परिभाषितम् _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#अन्यथा
    IMAGE_OPTIONAL_शीर्षकम्_2 opthdr;
#यदि_अन्तः
#यदि_अन्तः
};

संरचना pe_reloc_शीर्षकम् {
    DWORD विस्थापनम्;
    DWORD आकार;
};

संरचना pe_rsrc_शीर्षकम् {
    संरचना IMAGE_FILE_शीर्षकम् filehdr;
    संरचना IMAGE_SECTION_शीर्षकम् sectionhdr;
};

संरचना pe_rsrc_reloc {
    DWORD विस्थापनम्;
    DWORD आकार;
    WORD type;
};
#निर्देशः pack(निष्कासय)

/* ------------------------------------------------------------- */
/* internal temporary structures */

गणना {
    sec_text = 0,
    sec_rdata ,
    sec_दत्त ,
    sec_bss ,
    sec_idata ,
    sec_pdata ,
    sec_tdata ,
    sec_tbss ,
    sec_other ,
    sec_rsrc ,
    sec_debug ,
    sec_reloc ,
    sec_चरमः
};

#यदि 0
स्थिर ध्रुव DWORD pe_sec_flags[] = {
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
#यदि_अन्तः

संरचना section_info {
    पूर्णाङ्क cls;
    वर्ण name[32];
    ADDR3264 sh_addr;
    DWORD sh_आकार;
    DWORD pe_flags;
    Section *sec;
    DWORD दत्त_आकार;
    IMAGE_SECTION_शीर्षकम्_2 ish;
};

संरचना import_चिह्नम् {
    पूर्णाङ्क sym_सूचकांक;
    पूर्णाङ्क iat_सूचकांक;
    पूर्णाङ्क thk_विस्थापनम्;
};

संरचना pe_import_info {
    पूर्णाङ्क dll_सूचकांक;
    पूर्णाङ्क sym_गणनम्;
    संरचना import_चिह्नम् **symbols;
};

संरचना pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    ध्रुव वर्ण *filename;
    पूर्णाङ्क type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    ध्रुव वर्ण *start_चिह्नम्;
    DWORD start_addr;
    DWORD imp_offs;
    DWORD imp_आकार;
    DWORD iat_offs;
    DWORD iat_आकार;
    DWORD exp_offs;
    DWORD exp_आकार;
    DWORD tls_dir;
    DWORD tls_दत्त;
    DWORD tls_आकार;
    पूर्णाङ्क subsystem;
    DWORD section_align;
    DWORD file_align;
    संरचना section_info **sec_info;
    पूर्णाङ्क sec_गणनम्;
    संरचना pe_import_info **imp_info;
    पूर्णाङ्क imp_गणनम्;
    /* output */
    FILE *op;
    DWORD योग;
    अचिह्नित pos;
};

#परिभाषय PE_NUL 0
#परिभाषय PE_DLL 1
#परिभाषय PE_GUI 2
#परिभाषय PE_EXE 3
#परिभाषय PE_सततम् 4

/* --------------------------------------------*/

स्थिर ध्रुव वर्ण *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    ध्रुव वर्ण *name = (वर्ण*)symtab_section->link->दत्त + sym->st_name;
    यदि (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        प्रत्यागम name + 1;
    प्रत्यागम name;
}


स्थिर पूर्णाङ्क dynarray_assoc(शून्य **pp, पूर्णाङ्क n, पूर्णाङ्क कुञ्चिका)
{
    पूर्णाङ्क i;
    प्रति (i = 0; i < n; ++i, ++pp)
    यदि (कुञ्चिका == **(पूर्णाङ्क **) pp)
        प्रत्यागम i;
    प्रत्यागम -1;
}

स्थिर DWORD umin(DWORD a, DWORD b)
{
    प्रत्यागम a < b ? a : b;
}

स्थिर DWORD umax(DWORD a, DWORD b)
{
    प्रत्यागम a < b ? b : a;
}

स्थिर DWORD pe_file_align(संरचना pe_info *pe, DWORD n)
{
    प्रत्यागम (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

स्थिर ADDR3264 pe_virtual_align(संरचना pe_info *pe, ADDR3264 n)
{
    प्रत्यागम (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

स्थिर शून्य pe_align_section(Section *s, पूर्णाङ्क a)
{
    पूर्णाङ्क i = s->दत्त_विस्थापनम् & (a-1);
    यदि (i)
        section_ptr_सङ्कलय(s, a - i);
}

स्थिर शून्य pe_समुच्चयः_datadir(संरचना pe_शीर्षकम् *hdr, पूर्णाङ्क dir, DWORD addr, DWORD आकार)
{
    hdr->opthdr.दत्त_Directory[dir].Virtual_स्थानाङ्कः = addr;
    hdr->opthdr.दत्त_Directory[dir].आकार_3 = आकार;
}

स्थिर पूर्णाङ्क pe_fwrite(संरचना pe_info *pe, ध्रुव शून्य *दत्त, पूर्णाङ्क len)
{
    ध्रुव WORD *p = दत्त;
    DWORD योग;
    पूर्णाङ्क ret, i;
    pe->pos += (ret = fwrite(दत्त, 1, len, pe->op));
    योग = pe->योग;
    प्रति (i = len; i > 0; i -= 2) {
        योग += (i >= 2) ? *p++ : *(BYTE*)p;
        योग = (योग + (योग >> 16)) & 0xFFFF;
    }
    pe->योग = योग;
    प्रत्यागम len == ret ? 0 : -1;
}

स्थिर शून्य pe_fpad(संरचना pe_info *pe, DWORD new_pos)
{
    वर्ण buf[256];
    पूर्णाङ्क n, diff = new_pos - pe->pos;
    स्मृतिं_पूरय(buf, 0, परिमाण buf);
    यावत् (diff > 0) {
        diff -= n = umin(diff, परिमाण buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#निर्देशः pack(प्रक्षिप, 1)
संरचना syment
{
    सङ्घ {
        वर्ण        n_name[8];     /* old COFF version */
        संरचना {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_विस्थापनम्_2;      /* offset into string table */
        };
    };
    int32_t         n_मानम्;        /* value of symbol */
    ह्रस्व           n_scnum;        /* section number */
    अचिह्नित ह्रस्व  n_type;         /* type and derived type */
    वर्ण            n_sclass;       /* storage class */
    वर्ण            n_numaux;       /* number of aux. entries */
};
#निर्देशः pack(निष्कासय)

#परिभाषय SHF_वैयक्तिकम् 0x80000000

स्थिर शून्य pe_सङ्कलय_coffsym(संरचना pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    संरचना syment *se;
    पूर्णाङ्क n;

    यदि (रिक्त == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_वैयक्तिकम्);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_वैयक्तिकम्);
        section_ptr_सङ्कलय(pe->coffstr, 4); /* coff string table size */
        प्रत्यागम;
    }

#यदि 0
    se = section_ptr_सङ्कलय(pe->coffsym, परिमाण *se);
    वाक्यं_प्रतिलिख(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_सङ्कलय(pe->coffsym, परिमाण *se);
    वाक्यं_प्रतिलिख((वर्ण*)se, "no-file");
#यदि_अन्तः

#यदि 1
    esym = (ElfSym*)s1->symtab->दत्त;
    प्रति (n = s1->symtab->दत्त_विस्थापनम् / परिमाण *esym; ++esym, --n;) {
        पूर्णाङ्क sym_bind = ELFW(ST_BIND)(esym->st_info);
        यदि (sym_bind == STB_GLOBAL) {
            वर्ण *name = esym->st_name + (वर्ण*)s1->symtab->link->दत्त;
            पूर्णाङ्क nl = वाक्यदैर्घ्यम्(name);
            addr_t मानम् = esym->st_मानम्;
            पूर्णाङ्क shnum = esym->st_shndx;
            यदि (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                मानम् = मानम् - s->sh_addr;
            }
            se = section_ptr_सङ्कलय(pe->coffsym, परिमाण *se);
            se->n_मानम् = मानम्;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            यदि (nl <= 8)
                स्मृतिं_प्रतिलिख(se->n_name, name, nl);
            अन्यथा
                se->n_विस्थापनम्_2 = put_elf_str(pe->coffstr, name);
        }
    }
#यदि_अन्तः
    write32le(pe->coffstr->दत्त, pe->coffstr->दत्त_विस्थापनम्); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
स्थिर शून्य pe_create_pdb(TCCState *s1, ध्रुव वर्ण *exename)
{
    वर्ण buf[300]; पूर्णाङ्क r;
    snprintf(buf, परिमाण buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    वाक्यं_प्रतिलिख(tcc_fileextension(वाक्यं_प्रतिलिख(buf, exename)), ".pdb");
    यदि (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } अन्यथा यदि (s1->verbose) {
        प्रारूप_लिख("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
स्थिर पूर्णाङ्क pe_write(संरचना pe_info *pe)
{
    स्थिर ध्रुव संरचना pe_शीर्षकम् pe_template = {
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
#यदि PTR_आकार == 4
    0x00000000, /*DWORD   BaseOfData; */
#यदि_अन्तः
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

    संरचना pe_शीर्षकम् pe_शीर्षकम् = pe_template;

    पूर्णाङ्क i;
    DWORD file_विस्थापनम्;
    संरचना section_info *si;
    IMAGE_SECTION_शीर्षकम्_2 *psh;
    TCCState *s1 = pe->s1;

    यदि (s1->do_debug)
        pe_सङ्कलय_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    यदि (रिक्त == pe->op)
        प्रत्यागम tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        परिमाण (संरचना pe_शीर्षकम्)
        + pe->sec_गणनम् * परिमाण (IMAGE_SECTION_शीर्षकम्_2)
        );

    file_विस्थापनम् = pe->sizeofheaders;

    यदि (2 == s1->verbose)
        प्रारूप_लिख("-------------------------------"
               "\n  virt   file   size  section" "\n");
    प्रति (i = 0; i < pe->sec_गणनम्; ++i) {
        DWORD addr, आकार;
        ध्रुव वर्ण *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        आकार = si->sh_आकार;
        psh = &si->ish;

        यदि (2 == s1->verbose)
            प्रारूप_लिख("%6x %6x %6x  %s\n",
                (अचिह्नित)addr, (अचिह्नित)file_विस्थापनम्, (अचिह्नित)आकार, sh_name);

        विकल्प (si->cls) {
            पक्ष sec_text:
                यदि (!pe_शीर्षकम्.opthdr.आधारः_सम्बन्धि_संहिता)
                    pe_शीर्षकम्.opthdr.आधारः_सम्बन्धि_संहिता = addr;
                भङ्ग;

            पक्ष sec_दत्त:
#यदि PTR_आकार == 4
                यदि (!pe_शीर्षकम्.opthdr.आधारः_सम्बन्धि_दत्त)
                    pe_शीर्षकम्.opthdr.आधारः_सम्बन्धि_दत्त = addr;
#यदि_अन्तः
                भङ्ग;

            पक्ष sec_bss:
                भङ्ग;

            पक्ष sec_reloc:
                pe_समुच्चयः_datadir(&pe_शीर्षकम्, IMAGE_DIRECTORY_प्रविष्टिः_BASERELOC, addr, आकार);
                भङ्ग;

            पक्ष sec_rsrc:
                pe_समुच्चयः_datadir(&pe_शीर्षकम्, IMAGE_DIRECTORY_प्रविष्टिः_RESOURCE, addr, आकार);
                भङ्ग;

            पक्ष sec_pdata:
                pe_समुच्चयः_datadir(&pe_शीर्षकम्, IMAGE_DIRECTORY_प्रविष्टिः_EXCEPTION, addr, आकार);
                भङ्ग;
        }

        यदि (pe->imp_आकार) {
            pe_समुच्चयः_datadir(&pe_शीर्षकम्, IMAGE_DIRECTORY_प्रविष्टिः_IMPORT,
                pe->imp_offs, pe->imp_आकार);
            pe_समुच्चयः_datadir(&pe_शीर्षकम्, IMAGE_DIRECTORY_प्रविष्टिः_IAT,
                pe->iat_offs, pe->iat_आकार);
        }
        यदि (pe->exp_आकार) {
            pe_समुच्चयः_datadir(&pe_शीर्षकम्, IMAGE_DIRECTORY_प्रविष्टिः_EXPORT,
                pe->exp_offs, pe->exp_आकार);
        }
        यदि (pe->tls_आकार) {
            pe_समुच्चयः_datadir(&pe_शीर्षकम्, IMAGE_DIRECTORY_प्रविष्टिः_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_आकार);
        }

        स्मृतिं_प्रतिलिख(psh->Name, sh_name, umin(वाक्यदैर्घ्यम्(sh_name), परिमाण psh->Name));
        यदि (pe->coffstr && वाक्यदैर्घ्यम्(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((वर्ण*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->Virtual_स्थानाङ्कः = addr;
        psh->Misc.Virtual_आकार = आकार;
        pe_शीर्षकम्.opthdr.आकार_सम्बन्धि_Image =
            umax(pe_virtual_align(pe, आकार + addr), pe_शीर्षकम्.opthdr.आकार_सम्बन्धि_Image);

        यदि (si->दत्त_आकार) {
            psh->Pointer_गन्तव्यम्_Raw_दत्त = file_विस्थापनम्;
            file_विस्थापनम् = pe_file_align(pe, file_विस्थापनम् + si->दत्त_आकार);
            psh->आकार_सम्बन्धि_Raw_दत्त = file_विस्थापनम् - psh->Pointer_गन्तव्यम्_Raw_दत्त;
            यदि (si->cls == sec_text)
                pe_शीर्षकम्.opthdr.आकार_सम्बन्धि_संहिता += psh->आकार_सम्बन्धि_Raw_दत्त;
            अन्यथा
                pe_शीर्षकम्.opthdr.आकार_सम्बन्धि_Initialized_दत्त += psh->आकार_सम्बन्धि_Raw_दत्त;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_शीर्षकम्.filehdr.सङ्ख्या_सम्बन्धि_Sections = pe->sec_गणनम्;
    pe_शीर्षकम्.opthdr.स्थानाङ्कः_सम्बन्धि_प्रविष्टिः_Point = pe->start_addr;
    pe_शीर्षकम्.opthdr.आकार_सम्बन्धि_शीर्षकाणि = pe->sizeofheaders;
    pe_शीर्षकम्.opthdr.Image_आधारः = pe->imagebase;
    pe_शीर्षकम्.opthdr.Subsystem = pe->subsystem;
    pe_शीर्षकम्.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    यदि (s1->pe_राशिः_आकार)
        pe_शीर्षकम्.opthdr.आकार_सम्बन्धि_राशिः_Reserve = s1->pe_राशिः_आकार;
    यदि (PE_DLL == pe->type)
        pe_शीर्षकम्.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_शीर्षकम्.filehdr.Characteristics |= s1->pe_characteristics;
    यदि (pe->reloc)
        pe_शीर्षकम्.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    यदि (pe->coffsym) {
        pe_सङ्कलय_coffsym(pe);
        pe_शीर्षकम्.filehdr.Pointer_गन्तव्यम्_चिह्नम्_सारणी = file_विस्थापनम्;
        pe_शीर्षकम्.filehdr.सङ्ख्या_सम्बन्धि_Symbols
            = pe->coffsym->दत्त_विस्थापनम् / परिमाण (संरचना syment);
    }

    pe_fwrite(pe, &pe_शीर्षकम्, परिमाण pe_शीर्षकम्);
    प्रति (i = 0; i < pe->sec_गणनम्; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, परिमाण(IMAGE_SECTION_शीर्षकम्_2));

    file_विस्थापनम् = pe->sizeofheaders;
    प्रति (i = 0; i < pe->sec_गणनम्; ++i) {
        Section *s;
        si = pe->sec_info[i];
        यदि (!si->दत्त_आकार)
            अनुवर्त;
        प्रति (s = si->sec; s; s = s->पूर्व) {
            pe_fpad(pe, file_विस्थापनम्);
            pe_fwrite(pe, s->दत्त, s->दत्त_विस्थापनम्);
            यदि (s->पूर्व)
                file_विस्थापनम् += s->पूर्व->sh_addr - s->sh_addr;
        }
        file_विस्थापनम् = si->ish.Pointer_गन्तव्यम्_Raw_दत्त + si->ish.आकार_सम्बन्धि_Raw_दत्त;
        pe_fpad(pe, file_विस्थापनम्);
    }

    यदि (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->दत्त, pe->coffsym->दत्त_विस्थापनम्);
        pe_fwrite(pe, pe->coffstr->दत्त, pe->coffstr->दत्त_विस्थापनम्);
        file_विस्थापनम् = pe->pos;
    }

    pe->योग += file_विस्थापनम्;
    fseek(pe->op, offsetof(संरचना pe_शीर्षकम्, opthdr.Check_योग), SEEK_SET);
    pe_fwrite(pe, &pe->योग, परिमाण (DWORD));

    fclose (pe->op);
#यदि_अपरिभाषितम् _WIN32
    chmod(pe->filename, 0777);
#यदि_अन्तः

    यदि (2 == s1->verbose)
        प्रारूप_लिख("-------------------------------\n");
    यदि (s1->verbose)
        प्रारूप_लिख("<- %s (%u bytes)\n", pe->filename, (अचिह्नित)file_विस्थापनम्);

    यदि (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    प्रत्यागम 0;
}

/*----------------------------------------------------------------------------*/

स्थिर संरचना import_चिह्नम् *pe_सङ्कलय_import(संरचना pe_info *pe, पूर्णाङ्क sym_सूचकांक)
{
    पूर्णाङ्क i;
    पूर्णाङ्क dll_सूचकांक;
    संरचना pe_import_info *p;
    संरचना import_चिह्नम् *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->दत्त + sym_सूचकांक;
    dll_सूचकांक = isym->st_आकार;

    i = dynarray_assoc ((शून्य**)pe->imp_info, pe->imp_गणनम्, dll_सूचकांक);
    यदि (-1 != i) {
        p = pe->imp_info[i];
        गच्छ प्राप्तम्_dll;
    }
    p = tcc_mallocz(परिमाण *p);
    p->dll_सूचकांक = dll_सूचकांक;
    dynarray_सङ्कलय(&pe->imp_info, &pe->imp_गणनम्, p);

प्राप्तम्_dll:
    i = dynarray_assoc ((शून्य**)p->symbols, p->sym_गणनम्, sym_सूचकांक);
    यदि (-1 != i)
        प्रत्यागम p->symbols[i];

    s = tcc_mallocz(परिमाण *s);
    dynarray_सङ्कलय(&p->symbols, &p->sym_गणनम्, s);
    s->sym_सूचकांक = sym_सूचकांक;
    प्रत्यागम s;
}

स्थिर शून्य pe_free_imports(संरचना pe_info *pe)
{
    पूर्णाङ्क i;
    प्रति (i = 0; i < pe->imp_गणनम्; ++i) {
        संरचना pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_गणनम्);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_गणनम्);
}

/*----------------------------------------------------------------------------*/
स्थिर शून्य pe_build_imports(संरचना pe_info *pe)
{
    पूर्णाङ्क thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_आधारः = pe->thunk->sh_addr - pe->imagebase;
    पूर्णाङ्क ndlls = pe->imp_गणनम्;
    TCCState *s1 = pe->s1;

    प्रति (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_गणनम्;

    यदि (0 == sym_cnt)
        प्रत्यागम;

    pe_align_section(pe->thunk, 16);
    pe->imp_आकार = (ndlls + 1) * परिमाण(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_आकार = (sym_cnt + ndlls) * परिमाण(ADDR3264);
    dll_ptr = pe->thunk->दत्त_विस्थापनम्;
    thk_ptr = dll_ptr + pe->imp_आकार;
    ent_ptr = thk_ptr + pe->iat_आकार;
    pe->imp_offs = dll_ptr + rva_आधारः;
    pe->iat_offs = thk_ptr + rva_आधारः;
    section_ptr_सङ्कलय(pe->thunk, pe->imp_आकार + 2*pe->iat_आकार);

    प्रति (i = 0; i < pe->imp_गणनम्; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        पूर्णाङ्क k, n, dllindex;
        ADDR3264 v;
        संरचना pe_import_info *p = pe->imp_info[i];
        ध्रुव वर्ण *name;
        DLLReference *dllref;

        dllindex = p->dll_सूचकांक;
        यदि (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        अन्यथा
            name = "", dllref = रिक्त;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->दत्त + dll_ptr);
        hdr->FirstThunk = thk_ptr + rva_आधारः;
        hdr->OriginalFirstThunk = ent_ptr + rva_आधारः;
        hdr->Name = v + rva_आधारः;

        प्रति (k = 0, n = p->sym_गणनम्; k <= n; ++k) {
            यदि (k < n) {
                पूर्णाङ्क iat_सूचकांक = p->symbols[k]->iat_सूचकांक;
                पूर्णाङ्क sym_सूचकांक = p->symbols[k]->sym_सूचकांक;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->दत्त + sym_सूचकांक;
                ध्रुव वर्ण *name = (वर्ण*)s1->dynsymtab_section->link->दत्त + imp_sym->st_name;
                पूर्णाङ्क ordinal;

                /* patch symbol (and possibly its underscored alias) */
                कुरु {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->दत्त + iat_सूचकांक;
                    iat_सूचकांक = esym->st_मानम्;
                    esym->st_मानम् = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_अङ्कः;
                } यावत् (iat_सूचकांक);

                यदि (dllref)
                    v = 0, ordinal = imp_sym->st_मानम्; /* ordinal from pe_load_def */
                अन्यथा
                    ordinal = 0, v = imp_sym->st_मानम्; /* address from tcc_add_symbol() */

#यदि_परिभाषितम् TCC_IS_NATIVE
                यदि (pe->type == PE_सततम्) {
                    यदि (dllref) {
                        यदि ( !dllref->handle )
                            dllref->handle = आरोपय_Library_A(dllref->name);
                        v = (ADDR3264)Get_Proc_स्थानाङ्कः(dllref->handle, ordinal?(वर्ण*)0+ordinal:name);
                    }
                    यदि (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } अन्यथा
#यदि_अन्तः
                यदि (ordinal) {
                    v = ordinal | (ADDR3264)1 << (परिमाण(ADDR3264)*8 - 1);
                } अन्यथा {
                    v = pe->thunk->दत्त_विस्थापनम् + rva_आधारः;
                    section_ptr_सङ्कलय(pe->thunk, परिमाण(WORD)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } अन्यथा {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->दत्त+thk_ptr) =
            *(ADDR3264*)(pe->thunk->दत्त+ent_ptr) = v;
            thk_ptr += परिमाण (ADDR3264);
            ent_ptr += परिमाण (ADDR3264);
        }
        dll_ptr += परिमाण(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

संरचना pe_क्रमय_sym
{
    पूर्णाङ्क सूचकांक;
    ध्रुव वर्ण *name;
};

स्थिर पूर्णाङ्क sym_cmp(ध्रुव शून्य *va, ध्रुव शून्य *vb)
{
    ध्रुव वर्ण *ca = (*(संरचना pe_क्रमय_sym**)va)->name;
    ध्रुव वर्ण *cb = (*(संरचना pe_क्रमय_sym**)vb)->name;
    प्रत्यागम वाक्यं_तुलय(ca, cb);
}

स्थिर शून्य pe_build_exports(संरचना pe_info *pe)
{
    ElfW(Sym) *sym;
    पूर्णाङ्क sym_सूचकांक, sym_अन्तः;
    DWORD rva_आधारः, आधारः_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    पूर्णाङ्क sym_गणनम्, ord;
    संरचना pe_क्रमय_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    वर्ण buf[260];
    ध्रुव वर्ण *dllname;
    ध्रुव वर्ण *name;

    rva_आधारः = pe->thunk->sh_addr - pe->imagebase;
    sym_गणनम् = 0, sorted = रिक्त, op = रिक्त;

    sym_अन्तः = symtab_section->दत्त_विस्थापनम् / परिमाण(ElfW(Sym));
    प्रति (sym_सूचकांक = 1; sym_सूचकांक < sym_अन्तः; ++sym_सूचकांक) {
        sym = (ElfW(Sym)*)symtab_section->दत्त + sym_सूचकांक;
        name = pe_export_name(s1, sym);
        यदि (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(परिमाण *p);
            p->सूचकांक = sym_सूचकांक;
            p->name = name;
            dynarray_सङ्कलय(&sorted, &sym_गणनम्, p);
        }
#यदि 0
        यदि (sym->st_other & ST_PE_EXPORT)
            प्रारूप_लिख("export: %s\n", name);
        यदि (sym->st_other & ST_PE_STDCALL)
            प्रारूप_लिख("stdcall: %s\n", name);
#यदि_अन्तः
    }

    यदि (0 == sym_गणनम्)
        प्रत्यागम;

    शीघ्रं_क्रमय (sorted, sym_गणनम्, परिमाण *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    आधारः_o = pe->thunk->दत्त_विस्थापनम्;
    func_o = आधारः_o + परिमाण(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_गणनम् * परिमाण (DWORD);
    ord_o = name_o + sym_गणनम् * परिमाण (DWORD);
    str_o = ord_o + sym_गणनम् * परिमाण(WORD);

    hdr = section_ptr_सङ्कलय(pe->thunk, str_o - आधारः_o);
    hdr->Characteristics        = 0;
    hdr->आधारः_2                   = 1;
    hdr->सङ्ख्या_सम्बन्धि_Functions      = sym_गणनम्;
    hdr->सङ्ख्या_सम्बन्धि_नामानि          = sym_गणनम्;
    hdr->स्थानाङ्कः_सम्बन्धि_Functions     = func_o + rva_आधारः;
    hdr->स्थानाङ्कः_सम्बन्धि_नामानि         = name_o + rva_आधारः;
    hdr->स्थानाङ्कः_सम्बन्धि_Name_Ordinals  = ord_o + rva_आधारः;
    hdr->Name                   = str_o + rva_आधारः;
    put_elf_str(pe->thunk, dllname);

#यदि 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, परिमाण buf, pe->filename);
    वाक्यं_प्रतिलिख(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    यदि (रिक्त == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } अन्यथा {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        यदि (s1->verbose)
            प्रारूप_लिख("<- %s (%d symbol%s)\n", buf, sym_गणनम्, &"s"[sym_गणनम् < 2]);
    }
#यदि_अन्तः

    प्रति (ord = 0; ord < sym_गणनम्; ++ord)
    {
        p = sorted[ord], sym_सूचकांक = p->सूचकांक, name = p->name;
        /* insert actual address later in relocate_sections() */
        put_elf_reloc(symtab_section, pe->thunk,
            func_o, R_XXX_RELATIVE, sym_सूचकांक);
        *(DWORD*)(pe->thunk->दत्त + name_o)
            = pe->thunk->दत्त_विस्थापनम् + rva_आधारः;
        *(WORD*)(pe->thunk->दत्त + ord_o)
            = ord;
        put_elf_str(pe->thunk, name);
        func_o += परिमाण (DWORD);
        name_o += परिमाण (DWORD);
        ord_o += परिमाण (WORD);
        यदि (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = आधारः_o + rva_आधारः;
    pe->exp_आकार = pe->thunk->दत्त_विस्थापनम् - आधारः_o;
    dynarray_reset(&sorted, &sym_गणनम्);
    यदि (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
स्थिर शून्य pe_build_reloc (संरचना pe_info *pe)
{
    DWORD विस्थापनम्, खण्डम्_ptr, sh_addr, addr;
    पूर्णाङ्क गणनम्_2, i;
    ElfW_Rel *rel, *rel_अन्तः;
    Section *s = रिक्त, *sr;
    संरचना pe_reloc_शीर्षकम् *hdr;
    TCCState *s1 = pe->s1;
    पूर्णाङ्क dwarf = 0, n;

    sh_addr = विस्थापनम् = खण्डम्_ptr = गणनम्_2 = i = 0;
    rel = rel_अन्तः = रिक्त;

    प्रति(;;) {
        यदि (rel < rel_अन्तः) {
            पूर्णाङ्क type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_विस्थापनम् + sh_addr;
            ++ rel;
            यदि (type != REL_TYPE_प्रत्यक्षम्)
                अनुवर्त;
            यदि (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->दत्त + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                यदि (n >= s1->dwlo && n < s1->dwhi)
                    अनुवर्त;
            }
            यदि (गणनम्_2 == 0) { /* new block */
                खण्डम्_ptr = pe->reloc->दत्त_विस्थापनम्;
                section_ptr_सङ्कलय(pe->reloc, परिमाण(संरचना pe_reloc_शीर्षकम्));
                विस्थापनम् = addr & 0xFFFFFFFF<<12;
            }
            यदि ((addr -= विस्थापनम्)  < (1<<12)) { /* one block spans 4k addresses */
                WORD *wp = section_ptr_सङ्कलय(pe->reloc, परिमाण (WORD));
                *wp = addr | PE_IMAGE_REL<<12;
                ++गणनम्_2;
                अनुवर्त;
            }
            -- rel;

        } अन्यथा यदि (s) {
            sr = s->reloc;
            यदि (sr) {
                rel = (ElfW_Rel *)sr->दत्त;
                rel_अन्तः = (ElfW_Rel *)(sr->दत्त + sr->दत्त_विस्थापनम्);
                sh_addr = s->sh_addr;
                dwarf = s->sh_अङ्कः >= s1->dwlo && s->sh_अङ्कः < s1->dwhi;
            }
            s = s->पूर्व;
            अनुवर्त;

        } अन्यथा यदि (i < pe->sec_गणनम्) {
            s = pe->sec_info[i]->sec, ++i;
            अनुवर्त;

        } अन्यथा यदि (!गणनम्_2)
            भङ्ग;

        /* fill the last block and ready for a new one */
        यदि (गणनम्_2 & 1) /* align for DWORDS */
            section_ptr_सङ्कलय(pe->reloc, परिमाण(WORD)), ++गणनम्_2;
        hdr = (संरचना pe_reloc_शीर्षकम् *)(pe->reloc->दत्त + खण्डम्_ptr);
        hdr -> विस्थापनम् = विस्थापनम् - pe->imagebase;
        hdr -> आकार = गणनम्_2 * परिमाण(WORD) + परिमाण(संरचना pe_reloc_शीर्षकम्);
        गणनम्_2 = 0;
    }
}

/* ------------------------------------------------------------- */
स्थिर शून्य pe_build_tls(संरचना pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    पूर्णाङ्क c, n;

    यदि (0 == s) {
        pe->tls_आकार = परिमाण (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_सङ्कलय(pe->thunk, pe->tls_आकार, 16);
        pe->tls_दत्त = section_सङ्कलय(दत्त_section, PTR_आकार * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, दत्त_section->sh_अङ्कः, 0);
        प्रति (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_आकार*n, REL_TYPE_प्रत्यक्षम्, c);
        /* for generators */
        समुच्चयः_elf_sym(symtab_section, pe->tls_दत्त, PTR_आकार * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, दत्त_section->sh_अङ्कः, "__tls_index");
        प्रत्यागम;
    }

    यदि (0 == s1->tls_start)
        s1->tls_start = s->sh_addr;
    d = (शून्य*)(pe->thunk->दत्त + pe->tls_dir);
    d->Start_स्थानाङ्कः_सम्बन्धि_Raw_दत्त = s1->tls_start - दत्त_section->sh_addr;
    d->अन्तः_स्थानाङ्कः_सम्बन्धि_Raw_दत्त = s->sh_addr + s->दत्त_विस्थापनम् - दत्त_section->sh_addr;
    d->स्थानाङ्कः_सम्बन्धि_सूचकांक = pe->tls_दत्त;
    d->स्थानाङ्कः_सम्बन्धि_Call_Backs = pe->tls_दत्त + PTR_आकार;
    d->आकार_सम्बन्धि_Zero_Fill = 0;
    d->Characteristics = 0;
    /* to reuse logic from linux in xxx-link.c */
    s1->tls_अन्तः = s1->tls_start;
}

/* ------------------------------------------------------------- */
स्थिर पूर्णाङ्क pe_section_class(Section *s)
{
    पूर्णाङ्क type, flags;
    ध्रुव वर्ण *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    यदि (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        प्रत्यागम sec_debug;
    } अन्यथा यदि (flags & SHF_ALLOC) {
        यदि (flags & SHF_TLS)
            प्रत्यागम sec_tdata + (type == SHT_NOBITS);
        यदि (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            यदि (flags & SHF_EXECINSTR)
                प्रत्यागम sec_text;
            यदि (flags & SHF_WRITE)
                प्रत्यागम sec_दत्त;
            यदि (0 == वाक्यं_तुलय(name, ".rsrc"))
                प्रत्यागम sec_rsrc;
            यदि (0 == वाक्यं_तुलय(name, ".iedat"))
                प्रत्यागम sec_idata;
            यदि (0 == वाक्यं_तुलय(name, ".pdata"))
                प्रत्यागम sec_pdata;
            प्रत्यागम sec_rdata;
        } अन्यथा यदि (type == SHT_NOBITS) {
            प्रत्यागम sec_bss;
        }
        प्रत्यागम sec_other;
    } अन्यथा {
        यदि (0 == वाक्यं_तुलय(name, ".reloc"))
            प्रत्यागम sec_reloc;
    }
    प्रत्यागम sec_चरमः;
}

स्थिर पूर्णाङ्क pe_नियोजय_स्थानाङ्काः (संरचना pe_info *pe)
{
    पूर्णाङ्क i, k, n, c, nbs;
    ADDR3264 addr;
    पूर्णाङ्क *sec_क्रमः, *sec_cls;
    संरचना section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    यदि (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_आधारः))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_क्रमः = tcc_mallocz(2 * परिमाण (पूर्णाङ्क) * nbs);
    sec_cls = sec_क्रमः + nbs;
    प्रति (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        प्रति (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_क्रमः[n] = sec_क्रमः[n - 1];
        sec_cls[n] = k, sec_क्रमः[n] = i;
        यदि ((s->sh_flags & SHF_TLS) && 0 == pe->tls_आकार)
            pe_build_tls(pe, रिक्त);
    }
    si = रिक्त;
    addr = pe->imagebase + 1;
    प्रति (i = 1; (c = sec_cls[i]) < sec_चरमः; ++i) {
        s = s1->sections[sec_क्रमः[i]];

        यदि (PE_MERGE_दत्त && c == sec_bss)
            c = sec_दत्त;
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

        यदि (0 == s->दत्त_विस्थापनम्)
            अनुवर्त;

        यदि (si)
            गच्छ सङ्कलय_section;

        si = tcc_mallocz(परिमाण *si);
        dynarray_सङ्कलय(&pe->sec_info, &pe->sec_गणनम्, si);

        वाक्यं_प्रतिलिख(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        यदि (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_संहिता;
        अन्यथा यदि (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_दत्त;
        अन्यथा
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_दत्त;
        यदि (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        यदि (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

सङ्कलय_section:
        s->sh_info = pe->sec_गणनम्; /* section number for coff syms */
        addr += s->दत्त_विस्थापनम्;
        si->sh_आकार = addr - si->sh_addr;
        यदि (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            यावत् (*ps)
                ps = &(*ps)->पूर्व;
            *ps = s, s->पूर्व = रिक्त;
            si->दत्त_आकार = si->sh_आकार;
        }

        यदि (s->sh_flags & SHF_TLS) {
            वाक्यं_प्रतिलिख(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#यदि 0
    प्रति (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_क्रमः[i]];
        पूर्णाङ्क type = s->sh_type;
        पूर्णाङ्क flags = s->sh_flags;
        प्रारूप_लिख("section %-16s %-10s %p %04x %2d %s,%s,%s\n",
            s->name,
            type == SHT_PROGBITS ? "progbits" :
            type == SHT_INIT_ARRAY ? "initarr" :
            type == SHT_FINI_ARRAY ? "finiarr" :
            type == SHT_NOBITS ? "nobits" :
            type == SHT_SYMTAB ? "symtab" :
            type == SHT_STRTAB ? "strtab" :
            type == SHT_RELX ? "rel" : "???",
            s->sh_addr,
            (अचिह्नित)s->दत्त_विस्थापनम्,
            s->sh_addralign,
            flags & SHF_ALLOC ? "alloc" : "",
            flags & SHF_WRITE ? "write" : "",
            flags & SHF_EXECINSTR ? "exec" : ""
            );
        fflush(stdout);
    }
    s1->verbose = 2;
#यदि_अन्तः
    tcc_free(sec_क्रमः);
    प्रत्यागम 0;
}

/*----------------------------------------------------------------------------*/
स्थिर पूर्णाङ्क pe_check_symbols(संरचना pe_info *pe)
{
    पूर्णाङ्क sym_सूचकांक, sym_अन्तः;
    पूर्णाङ्क ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(text_section, 8);

    sym_अन्तः = symtab_section->दत्त_विस्थापनम् / परिमाण(ElfW(Sym));
    प्रति (sym_सूचकांक = 1; sym_सूचकांक < sym_अन्तः; ++sym_सूचकांक) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->दत्त + sym_सूचकांक;
        यदि (sym->st_shndx == SHN_UNDEF) {
            ध्रुव वर्ण *name = (वर्ण*)symtab_section->link->दत्त + sym->st_name;
            अचिह्नित type = ELFW(ST_TYPE)(sym->st_info);
            पूर्णाङ्क imp_sym = 0;
            संरचना import_चिह्नम् *is;

            पूर्णाङ्क _imp_, n;
            वर्ण बफर[200];
            ध्रुव वर्ण *s, *p;

            n = _imp_ = 0;
            यदि (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            कुरु {
                s = pe_export_name(s1, sym);
                यदि (n) {
                    /* second try: */
                    यदि (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        यदि (!p || s[0] != '_')
                            भङ्ग;
                        वाक्यं_प्रतिलिख(बफर, s+1)[p-s-1] = 0, s = बफर;
                    } अन्यथा यदि (s[0] != '_') { /* try non-ansi function */
                        बफर[0] = '_', वाक्यं_प्रतिलिख(बफर + 1, s), s = बफर;
                    } अन्यथा यदि (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } अन्यथा यदि (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } अन्यथा {
                        भङ्ग;
                    }
                }
                imp_sym = find_elf_sym(s1->dynsymtab_section, s);
            } यावत् (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            यदि (0 == imp_sym)
                अनुवर्त; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_सङ्कलय_import(pe, imp_sym);

            यदि (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                अचिह्नित विस्थापनम् = is->thk_विस्थापनम्;
                यदि (विस्थापनम्) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } अन्यथा {
                    अचिह्नित वर्ण *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(बफर, "IAT.%s", name);
                    is->iat_सूचकांक = put_elf_sym(
                        symtab_section, 0, परिमाण(DWORD),
                        ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT),
                        0, SHN_UNDEF, बफर);

                    विस्थापनम् = text_section->दत्त_विस्थापनम्;
                    is->thk_विस्थापनम् = विस्थापनम्;

                    /* add the 'jmp IAT[x]' instruction */
#यदि_परिभाषितम् TCC_TARGET_ARM
                    p = section_ptr_सङ्कलय(text_section, 8+4); // room for code and address
                    write32le(p + 0, 0xE59FC000); // arm code ldr ip, [pc] ; PC+8+0 = 0001xxxx
                    write32le(p + 4, 0xE59CF000); // arm code ldr pc, [ip]
                    put_elf_reloc(symtab_section, text_section,
                        विस्थापनम् + 8, R_XXX_THUNKFIX, is->iat_सूचकांक); // offset to IAT position
#नोचेद्यदि defined(TCC_TARGET_ARM64)
                    p = section_ptr_सङ्कलय(text_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, text_section,
                        विस्थापनम् + 16, R_XXX_THUNKFIX, is->iat_सूचकांक);
#अन्यथा
                    p = section_ptr_सङ्कलय(text_section, 8);
                    write16le(p, 0x25FF);
#यदि_परिभाषितम् TCC_TARGET_X86_64
                    write32le(p + 2, (DWORD)-4);
#यदि_अन्तः
                    put_elf_reloc(symtab_section, text_section, 
                        विस्थापनम् + 2, R_XXX_THUNKFIX, is->iat_सूचकांक);
#यदि_अन्तः
                }
                /* tcc_realloc might have altered sym's address */
                sym = (ElfW(Sym) *)symtab_section->दत्त + sym_सूचकांक;
                /* patch the original symbol */
                sym->st_मानम् = विस्थापनम्;
                sym->st_shndx = text_section->sh_अङ्कः;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } अन्यथा { /* STT_OBJECT */
                यदि (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_मानम् = is->iat_सूचकांक; /* chain potential alias */
                is->iat_सूचकांक = sym_सूचकांक;
            }

        } अन्यथा यदि (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    प्रत्यागम ret;
}

/*----------------------------------------------------------------------------*/
#यदि PE_PRINT_SECTIONS
स्थिर शून्य pe_print_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    पूर्णाङ्क i, n, l, m;
    p = s->दत्त;
    e = s->दत्त + s->दत्त_विस्थापनम्;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    यदि (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    यदि (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (अचिह्नित)s->sh_addr);
    fprintf(f, "\ncontents %08X", (अचिह्नित)l);
    fprintf(f, "\n\n");

    यदि (s->sh_type == SHT_NOBITS)
        प्रत्यागम;

    यदि (0 == l)
        प्रत्यागम;

    यदि (s->sh_type == SHT_SYMTAB)
        m = परिमाण(ElfW(Sym));
    अन्यथा यदि (s->sh_type == SHT_RELX)
        m = परिमाण(ElfW_Rel);
    अन्यथा
        m = 16;

    fprintf(f, "%-8s", "offset");
    प्रति (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    यदि (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        ध्रुव वर्ण *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            रिक्त
        };

        ध्रुव वर्ण *fields2[] = {
            "offs",
            "type",
            "symb",
            रिक्त
        };

        ध्रुव वर्ण **p;

        यदि (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        अन्यथा
            p = fields2, n = 58;

        प्रति (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    प्रति (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    प्रति (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        प्रति (n = 0; n < m; ++n) {
            यदि (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            अन्यथा
                fprintf(f, "   ");
        }

        यदि (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            ध्रुव वर्ण *name = s->link->दत्त + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (अचिह्नित)sym->st_name,
                    (अचिह्नित)sym->st_मानम्,
                    (अचिह्नित)sym->st_आकार,
                    (अचिह्नित)ELFW(ST_BIND)(sym->st_info),
                    (अचिह्नित)ELFW(ST_TYPE)(sym->st_info),
                    (अचिह्नित)sym->st_other,
                    (अचिह्नित)sym->st_shndx,
                    name);

        } अन्यथा यदि (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->दत्त + ELFW(R_SYM)(rel->r_info);
            ध्रुव वर्ण *name = s->link->link->दत्त + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (अचिह्नित)rel->r_विस्थापनम्,
                    (अचिह्नित)ELFW(R_TYPE)(rel->r_info),
                    (अचिह्नित)ELFW(R_SYM)(rel->r_info),
                    name);
        } अन्यथा {
            fprintf(f, "   ");
            प्रति (n = 0; n < m; ++n) {
                यदि (n + i < l) {
                    b = p[i + n];
                    यदि (b < 32 || b >= 127)
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

स्थिर शून्य pe_print_sections(TCCState *s1, ध्रुव वर्ण *fname)
{
    Section *s;
    FILE *f;
    पूर्णाङ्क i;
    f = fopen(fname, "w");
    प्रति (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    fclose(f);
}
#यदि_अन्तः

/* ------------------------------------------------------------- */

ST_FUNC पूर्णाङ्क pe_putimport(TCCState *s1, पूर्णाङ्क dllindex, ध्रुव वर्ण *name, addr_t मानम्)
{
    प्रत्यागम समुच्चयः_elf_sym(
        s1->dynsymtab_section,
        मानम्,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        मानम् ? SHN_ABS : SHN_UNDEF,
        name
        );
}

स्थिर पूर्णाङ्क read_mem(पूर्णाङ्क fd, अचिह्नित विस्थापनम्, शून्य *बफर, अचिह्नित len)
{
    lseek(fd, विस्थापनम्, SEEK_SET);
    प्रत्यागम len == पठ(fd, बफर, len);
}

/* ------------------------------------------------------------- */

स्थिर पूर्णाङ्क get_dllexports(पूर्णाङ्क fd, वर्ण **pp)
{
    पूर्णाङ्क i, k, l, n, n0, ret;
    वर्ण *p;

    IMAGE_SECTION_शीर्षकम्_2 ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_शीर्षकम्_2 dh;
    IMAGE_FILE_शीर्षकम्_2 ih;
    DWORD sig, ref, addr;
    DWORD *namep = रिक्त, p0 = 0, p1;

    पूर्णाङ्क pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = रिक्त;
    ret = 1;
    यदि (!read_mem(fd, 0, &dh, परिमाण dh))
        गच्छ the_अन्तः;
    यदि (!read_mem(fd, dh.e_lfanew, &sig, परिमाण sig))
        गच्छ the_अन्तः;
    यदि (sig != 0x00004550)
        गच्छ the_अन्तः;
    pef_hdroffset = dh.e_lfanew + परिमाण sig;
    यदि (!read_mem(fd, pef_hdroffset, &ih, परिमाण ih))
        गच्छ the_अन्तः;
    opt_hdroffset = pef_hdroffset + परिमाण ih;
    यदि (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + परिमाण oh;
        यदि (!read_mem(fd, opt_hdroffset, &oh, परिमाण oh))
            गच्छ the_अन्तः;
        यदि (IMAGE_DIRECTORY_प्रविष्टिः_EXPORT >= oh.सङ्ख्या_सम्बन्धि_Rva_And_Sizes)
            गच्छ the_अन्तः_0;
        addr = oh.दत्त_Directory[IMAGE_DIRECTORY_प्रविष्टिः_EXPORT].Virtual_स्थानाङ्कः;
    } अन्यथा यदि (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + परिमाण oh;
        यदि (!read_mem(fd, opt_hdroffset, &oh, परिमाण oh))
            गच्छ the_अन्तः;
        यदि (IMAGE_DIRECTORY_प्रविष्टिः_EXPORT >= oh.सङ्ख्या_सम्बन्धि_Rva_And_Sizes)
            गच्छ the_अन्तः_0;
        addr = oh.दत्त_Directory[IMAGE_DIRECTORY_प्रविष्टिः_EXPORT].Virtual_स्थानाङ्कः;
    } अन्यथा
        गच्छ the_अन्तः;

    //printf("addr: %08x\n", addr);
    प्रति (i = 0; i < ih.सङ्ख्या_सम्बन्धि_Sections; ++i) {
        यदि (!read_mem(fd, sec_hdroffset + i * परिमाण ish, &ish, परिमाण ish))
            गच्छ the_अन्तः;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        यदि (addr >= ish.Virtual_स्थानाङ्कः && addr < ish.Virtual_स्थानाङ्कः + ish.आकार_सम्बन्धि_Raw_दत्त)
            गच्छ प्राप्तम्;
    }
    गच्छ the_अन्तः_0;
प्राप्तम्:
    ref = ish.Virtual_स्थानाङ्कः - ish.Pointer_गन्तव्यम्_Raw_दत्त;
    यदि (!read_mem(fd, addr - ref, &ied, परिमाण ied))
        गच्छ the_अन्तः;
    k = ied.सङ्ख्या_सम्बन्धि_नामानि;
    यदि (k) {
        namep = tcc_malloc(l = k * परिमाण *namep);
        यदि (!read_mem(fd, ied.स्थानाङ्कः_सम्बन्धि_नामानि - ref, namep, l))
            गच्छ the_अन्तः;
        प्रति (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            यदि (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            कुरु {
                यदि (0 == l) {
                    यदि (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    यदि ((l = पठ(fd, p + n, 1000 - 1)) <= 0)
                        गच्छ the_अन्तः;
                }
                --l, ++p0;
            } यावत् (p[n++]);
        }
        p[n] = 0;
    }
the_अन्तः_0:
    ret = 0;
the_अन्तः:
    tcc_free(namep);
    यदि (ret && p)
        tcc_free(p), p = रिक्त;
    *pp = p;
    प्रत्यागम ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

स्थिर पूर्णाङ्क pe_आरोपय_res(TCCState *s1, पूर्णाङ्क fd)
{
    संरचना pe_rsrc_शीर्षकम् hdr;
    Section *rsrc_section;
    पूर्णाङ्क i, ret = -1, sym_सूचकांक;
    BYTE *ptr;
    अचिह्नित offs;

    यदि (!read_mem(fd, 0, &hdr, परिमाण hdr))
        गच्छ quit;

    यदि (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.सङ्ख्या_सम्बन्धि_Sections != 1
        || वाक्यं_तुलय((वर्ण*)hdr.sectionhdr.Name, ".rsrc") != 0)
        गच्छ quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_सङ्कलय(rsrc_section, hdr.sectionhdr.आकार_सम्बन्धि_Raw_दत्त);
    offs = hdr.sectionhdr.Pointer_गन्तव्यम्_Raw_दत्त;
    यदि (!read_mem(fd, offs, ptr, hdr.sectionhdr.आकार_सम्बन्धि_Raw_दत्त))
        गच्छ quit;
    offs = hdr.sectionhdr.Pointer_गन्तव्यम्_Relocations;
    sym_सूचकांक = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_अङ्कः, ".rsrc");
    प्रति (i = 0; i < hdr.sectionhdr.सङ्ख्या_सम्बन्धि_Relocations; ++i) {
        संरचना pe_rsrc_reloc rel;
        यदि (!read_mem(fd, offs, &rel, परिमाण rel))
            गच्छ quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        यदि (rel.type != RSRC_RELTYPE)
            गच्छ quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.विस्थापनम्, R_XXX_RELATIVE, sym_सूचकांक);
        offs += परिमाण rel;
    }
    ret = 0;
quit:
    प्रत्यागम ret;
}

/* ------------------------------------------------------------- */

स्थिर वर्ण *trimfront(वर्ण *p)
{
    यावत् ((अचिह्नित वर्ण)*p <= ' ' && *p && *p != '\n')
	++p;
    प्रत्यागम p;
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
    प्रति (e = p; (अचिह्नित वर्ण)*e >= ' ' && *e != q; ++e)
        ;
    यदि (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    प्रत्यागम p;
}

स्थिर पूर्णाङ्क pe_आरोपय_def(TCCState *s1, पूर्णाङ्क fd)
{
    पूर्णाङ्क state = 0, ret = -1, dllindex = 0, ord;
    वर्ण dllname[80], *buf, *पङ्क्तिः, *p, *x, अग्र;

    buf = tcc_आरोपय_text(fd);
    यदि (!buf)
        प्रत्यागम ret;

    प्रति (पङ्क्तिः = buf;; ++पङ्क्तिः)  {
        p = get_token(&पङ्क्तिः, &अग्र);
        यदि (!(*p && *p != ';'))
            गच्छ skip;
        विकल्प (state) {
        पक्ष 0:
            यदि (0 != stricmp(p, "LIBRARY") || अग्र == '\n')
                गच्छ quit;
            pstrcpy(dllname, परिमाण dllname, get_token(&पङ्क्तिः, &अग्र));
            यदि (!*tcc_fileextension(dllname))
                pstrcat(dllname, परिमाण dllname, ".dll");
            ++state;
            भङ्ग;
        पक्ष 1:
            यदि (0 != stricmp(p, "EXPORTS"))
                गच्छ quit;
            ++state;
            भङ्ग;
        पक्ष 2:
            dllindex = tcc_सङ्कलय_dllref(s1, dllname, 0)->सूचकांक;
            ++state;
            /* fall through */
        स्वभाव:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            यदि (अग्र == '@') {
                x = get_token(&पङ्क्तिः, &अग्र);
                ord = (पूर्णाङ्क)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            भङ्ग;
        }
skip:
        यावत् ((अचिह्नित वर्ण)अग्र > ' ')
            get_token(&पङ्क्तिः, &अग्र);
        यदि (अग्र != '\n')
            भङ्ग;
    }
    ret = 0;
quit:
    tcc_free(buf);
    प्रत्यागम ret;
}

/* ------------------------------------------------------------- */

स्थिर पूर्णाङ्क pe_आरोपय_dll(TCCState *s1, पूर्णाङ्क fd, ध्रुव वर्ण *filename)
{
    वर्ण *p, *q;
    DLLReference *ref = tcc_सङ्कलय_dllref(s1, filename, 0);
    यदि (ref->प्राप्तम्)
        प्रत्यागम 0;
    यदि (get_dllexports(fd, &p))
        प्रत्यागम -1;
    यदि (p) {
        प्रति (q = p; *q; q += 1 + वाक्यदैर्घ्यम्(q))
            pe_putimport(s1, ref->सूचकांक, q, 0);
        tcc_free(p);
    }
    प्रत्यागम 0;
}

ST_FUNC पूर्णाङ्क pe_आरोपय_file(संरचना TCCState *s1, पूर्णाङ्क fd, ध्रुव वर्ण *filename)
{
    पूर्णाङ्क ret = -1;
    वर्ण buf[10];
    यदि (0 == वाक्यं_तुलय(tcc_fileextension(filename), ".def"))
        ret = pe_आरोपय_def(s1, fd);
    अन्यथा यदि (pe_आरोपय_res(s1, fd) == 0)
        ret = 0;
    अन्यथा यदि (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_आरोपय_dll(s1, fd, filename);
    प्रत्यागम ret;
}

PUB_FUNC पूर्णाङ्क tcc_get_dllexports(ध्रुव वर्ण *filename, वर्ण **pp)
{
    पूर्णाङ्क ret, fd = उद्घाटय(filename, O_RDONLY | O_द्विमान_2);
    यदि (fd < 0)
        प्रत्यागम -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    प्रत्यागम ret;
}

/* ------------------------------------------------------------- */
#यदि_परिभाषितम् TCC_TARGET_X86_64
स्थिर अचिह्नित pe_सङ्कलय_unwind_info(TCCState *s1)
{
    यदि (रिक्त == s1->uw_pdata) {
        s1->uw_pdata = find_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    यदि (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, text_section->sh_अङ्कः, ".uw_base");
    यदि (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        स्थिर ध्रुव अचिह्नित वर्ण uw_info[] = {
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
        अचिह्नित वर्ण *p;

        section_ptr_सङ्कलय(s, -s->दत्त_विस्थापनम् & 3); /* align */
        s1->uw_offs = s->दत्त_विस्थापनम्;
        p = section_ptr_सङ्कलय(s, परिमाण uw_info);
        स्मृतिं_प्रतिलिख(p, uw_info, परिमाण uw_info);
    }

    प्रत्यागम s1->uw_offs;
}

ST_FUNC शून्य pe_सङ्कलय_unwind_दत्त(अचिह्नित start, अचिह्नित अन्तः, अचिह्नित राशिः)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    अचिह्नित o, n, d;
    संरचना /* _RUNTIME_FUNCTION */ {
      DWORD Begin_स्थानाङ्कः;
      DWORD अन्तः_स्थानाङ्कः;
      DWORD Unwind_दत्त;
    } *p;

    d = pe_सङ्कलय_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->दत्त_विस्थापनम्;
    p = section_ptr_सङ्कलय(pd, परिमाण *p);

    /* record this function */
    p->Begin_स्थानाङ्कः = start;
    p->अन्तः_स्थानाङ्कः = अन्तः;
    p->Unwind_दत्त = d;

    /* put relocations on it */
    प्रति (n = o + परिमाण *p; o < n; o += परिमाण p->Begin_स्थानाङ्कः)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#नोचेद्यदि defined(TCC_TARGET_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
स्थिर Section *pe_सङ्कलय_unwind_info(TCCState *s1)
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
                                  text_section->sh_अङ्कः, ".uw_text_base");
    यदि (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_अङ्कः, ".uw_base");
    प्रत्यागम s;
}

ST_FUNC शून्य pe_सङ्कलय_unwind_दत्त(अचिह्नित start, अचिह्नित अन्तः, अचिह्नित राशिः)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    अचिह्नित o, d, संहिता_अष्टकानि, func_len;
    अचिह्नित वर्ण *q;
    uint32_t शीर्षकम्;
    संरचना /* _RUNTIME_FUNCTION */ {
        DWORD Begin_स्थानाङ्कः;
        DWORD Unwind_दत्त;
    } *p;

    पूर्णाङ्क epilog;

    xd = pe_सङ्कलय_unwind_info(s1);
    pd = s1->uw_pdata;

    func_len = (अन्तः - start) >> 2;
    संहिता_अष्टकानि = 0;
    epilog = संहिता_अष्टकानि;
    संहिता_अष्टकानि += 3; /* set_fp, save_fplr_x, end */
    संहिता_अष्टकानि = (संहिता_अष्टकानि + 3) & ~3;

    section_ptr_सङ्कलय(xd, -xd->दत्त_विस्थापनम् & 3);
    d = xd->दत्त_विस्थापनम्;
    q = section_ptr_सङ्कलय(xd, 4 + संहिता_अष्टकानि);

    /* Full ARM64 xdata header: E=1 with one epilog and no exception handler. */
    शीर्षकम् = (func_len & 0x3ffff)
        | 1 << 21
        | (epilog & 0x1F) << 22
        | (संहिता_अष्टकानि >> 2) << 27
        ;
    write32le(q, शीर्षकम्);
    q += 4;
    *q++ = 0xE1; /* set_fp */
    *q++ = 0x9B; /* save_fplr_x: stp x29,lr,[sp,#-224]! */
    *q++ = 0xE4; /*अन्तः*/
    यावत् ((अचिह्नित)(q - (xd->दत्त + d + 4)) < संहिता_अष्टकानि)
        *q++ = 0xE3; /* nop padding */

    o = pd->दत्त_विस्थापनम्;
    p = section_ptr_सङ्कलय(pd, परिमाण *p);
    p->Begin_स्थानाङ्कः = start;
    p->Unwind_दत्त = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#यदि_अन्तः
/* ------------------------------------------------------------- */
#यदि defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
#परिभाषय PE_STDSYM(n,s) n
#अन्यथा
#परिभाषय PE_STDSYM(n,s) "_" n s
#यदि_अन्तः

स्थिर शून्य pe_सङ्कलय_runtime(TCCState *s1, संरचना pe_info *pe)
{
    ध्रुव वर्ण *start_चिह्नम्;
    पूर्णाङ्क pe_type;

    यदि (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        start_चिह्नम् = PE_STDSYM("__dllstart","@12");
    } अन्यथा {
        ध्रुव वर्ण *सततम्_चिह्नम्;
        यदि (find_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            start_चिह्नम् = "__winstart";
            सततम्_चिह्नम् = "__runwinmain";
            pe_type = PE_GUI;
        } अन्यथा यदि (find_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            start_चिह्नम् = "__wwinstart";
            सततम्_चिह्नम् = "__runwwinmain";
            pe_type = PE_GUI;
        } अन्यथा यदि (find_elf_sym(symtab_section, "wmain")) {
            start_चिह्नम् = "__wstart";
            सततम्_चिह्नम् = "__runwmain";
            pe_type = PE_EXE;
        } अन्यथा {
            start_चिह्नम् =  "__start";
            सततम्_चिह्नम् = "__runmain";
            pe_type = PE_EXE;
            यदि (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        यदि (TCC_OUTPUT_स्मृतिः == s1->output_type && !s1->nostdlib)
            start_चिह्नम् = सततम्_चिह्नम्;
    }
    यदि (s1->elf_entryname) {
        pe->start_चिह्नम् = start_चिह्नम् = s1->elf_entryname;
    } अन्यथा {
        pe->start_चिह्नम् = start_चिह्नम् + 1;
        यदि (!s1->leading_underscore || strchr(start_चिह्नम्, '@'))
            ++start_चिह्नम्;
    }

#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
    यदि (s1->do_backtrace) {
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
        यदि (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    यदि (s1->output_type == TCC_OUTPUT_स्मृतिः)
                tcc_सङ्कलय_support(s1, "bcheck_run.o");
	    अन्यथा
                tcc_सङ्कलय_support(s1, "bcheck.o");
	}
#यदि_अन्तः
        यदि (s1->output_type == TCC_OUTPUT_EXE)
            tcc_सङ्कलय_support(s1, "bt-exe.o");
        यदि (s1->output_type == TCC_OUTPUT_DLL)
            tcc_सङ्कलय_support(s1, "bt-dll.o");
        यदि (s1->output_type != TCC_OUTPUT_DLL)
            tcc_सङ्कलय_support(s1, "bt-log.o");
        tcc_सङ्कलय_btstub(s1);
    }
#यदि_अन्तः

    /* grab the startup code from libtcc1.a */
#यदि_परिभाषितम् TCC_IS_NATIVE
    यदि (TCC_OUTPUT_स्मृतिः != s1->output_type || s1->सततम्_main)
#यदि_अन्तः
    समुच्चयः_global_sym(s1, start_चिह्नम्, रिक्त, 0);

    यदि (0 == s1->nostdlib) {
        स्थिर ध्रुव वर्ण * ध्रुव libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", रिक्त
        };
        ध्रुव वर्ण * ध्रुव *pp, *p;
        यदि (TCC_LIBTCC1[0])
            tcc_सङ्कलय_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        प्रति (pp = libs; 0 != (p = *pp); ++pp) {
            यदि (*p)
                tcc_सङ्कलय_library(s1, p);
            अन्यथा यदि (PE_DLL != pe_type && PE_GUI != pe_type)
                भङ्ग;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    यदि (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    यदि (TCC_OUTPUT_स्मृतिः == s1->output_type)
        pe_type = PE_सततम्;
    pe->type = pe_type;
}

ST_FUNC पूर्णाङ्क pe_setsubsy(TCCState *s1, ध्रुव वर्ण *arg)
{
    स्थिर ध्रुव संरचना subsy { ध्रुव वर्ण* p; पूर्णाङ्क v; } x[] = {
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
#नोचेद्यदि defined(TCC_TARGET_ARM)
        { "wince", 9 },
#यदि_अन्तः
        { 0, -1 }};
    ध्रुव संरचना subsy *y;
    प्रति (y = x;; ++y) {
        यदि (!y->p)
            प्रत्यागम -1;
        यदि (0 == वाक्यं_तुलय(y->p, arg)) {
            s1->pe_subsystem = y->v;
            प्रत्यागम 0;
        }
    }
}

स्थिर शून्य pe_समुच्चयः_options(TCCState * s1, संरचना pe_info *pe)
{
    यदि (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_आधारः_DLL;
    } अन्यथा {
        pe->imagebase = IMAGE_आधारः_EXE;
    }

#यदि defined(TCC_TARGET_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#अन्यथा
    यदि (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    अन्यथा
        pe->subsystem = 3;
#यदि_अन्तः
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

ST_FUNC पूर्णाङ्क pe_output_file(TCCState *s1, ध्रुव वर्ण *filename)
{
    संरचना pe_info pe;

    स्मृतिं_पूरय(&pe, 0, परिमाण pe);
    pe.filename = filename;
    pe.s1 = s1;
    s1->filetype = 0;

#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    tcc_सङ्कलय_bcheck(s1);
#यदि_अन्तः
    tcc_सङ्कलय_pragma_libs(s1);
    pe_सङ्कलय_runtime(s1, &pe);
    resolve_common_syms(s1);
    pe_समुच्चयः_options(s1, &pe);
    pe_check_symbols(&pe);
    यदि (s1->nb_errors)
        गच्छ समाप्तम्;
    यदि (filename) {
        pe_नियोजय_स्थानाङ्काः(&pe);
        relocate_syms(s1, s1->symtab, 0);
        यदि (s1->nb_errors)
            गच्छ समाप्तम्;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.start_addr = (DWORD)
            (get_sym_addr(s1, pe.start_चिह्नम्, 1, 1) - pe.imagebase);
        यदि (s1->nb_errors)
            गच्छ समाप्तम्;
        pe_write(&pe);
    } अन्यथा {
        /* -run */
#यदि_परिभाषितम् TCC_IS_NATIVE
        pe.thunk = दत्त_section;
        pe_build_imports(&pe);
        s1->सततम्_main = pe.start_चिह्नम्;
#यदि defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
        s1->uw_pdata = find_section(s1, ".pdata");
#यदि_अन्तः
#यदि_अन्तः
    }
समाप्तम्:
    dynarray_reset(&pe.sec_info, &pe.sec_गणनम्);
    pe_free_imports(&pe);
#यदि PE_PRINT_SECTIONS
    यदि (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#यदि_अन्तः
    प्रत्यागम s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
