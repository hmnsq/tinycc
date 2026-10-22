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

#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PE_ਮਿਲਾਓ_ਅੰਕੜੇ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PE_PRINT_SECTIONS 0

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ stricmp strcasecmp
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ strnicmp strncasecmp
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/stat.h> /* chmod() */
#ਜੇ_ਅੰਤ

#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_X86_64
# define REL_TYPE_ਸਿੱਧਾ R_X86_64_64
# define R_XXX_THUNKFIX R_X86_64_PC32
# define R_XXX_RELATIVE R_X86_64_RELATIVE
# define R_XXX_FUNCCALL R_X86_64_PLT32
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0x8664
# define CHARACTERISTICS_EXE 0x022F
# define CHARACTERISTICS_DLL 0x222E
# define IMAGE_ਅਧਾਰ_EXE 0x00400000
# define IMAGE_ਅਧਾਰ_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM
# define REL_TYPE_ਸਿੱਧਾ R_ARM_ABS32
# define R_XXX_THUNKFIX R_ARM_ABS32
# define R_XXX_RELATIVE R_ARM_RELATIVE
# define R_XXX_FUNCCALL R_ARM_PC24
# define R_XXX_FUNCCALL2 R_ARM_ABS32
# define RSRC_RELTYPE 7 /* ??? (not tested) */
# define IMAGE_FILE_MACHINE 0x01C0
# define CHARACTERISTICS_EXE 0x010F
# define CHARACTERISTICS_DLL 0x230F
# define IMAGE_ਅਧਾਰ_EXE 0x00100000
# define IMAGE_ਅਧਾਰ_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
# define REL_TYPE_ਸਿੱਧਾ R_AARCH64_ABS64
# define R_XXX_THUNKFIX R_AARCH64_ABS64
# define R_XXX_RELATIVE R_AARCH64_RELATIVE
# define R_XXX_FUNCCALL R_AARCH64_CALL26
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0xAA64
# define CHARACTERISTICS_EXE 0x0022
# define CHARACTERISTICS_DLL 0x2022
# define IMAGE_ਅਧਾਰ_EXE 0x140000000ULL
# define IMAGE_ਅਧਾਰ_DLL 0x180000000ULL
# define OS_VER 0x0602
# define DLLCHARACTERISTICS 0x8160

#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_I386
# define REL_TYPE_ਸਿੱਧਾ R_386_32
# define R_XXX_THUNKFIX R_386_32
# define R_XXX_RELATIVE R_386_RELATIVE
# define R_XXX_FUNCCALL R_386_PC32
# define RSRC_RELTYPE 7 /* DIR32NB */
# define IMAGE_FILE_MACHINE 0x014C
# define CHARACTERISTICS_EXE 0x030F
# define CHARACTERISTICS_DLL 0x230E
# define IMAGE_ਅਧਾਰ_EXE 0x00400000
# define IMAGE_ਅਧਾਰ_DLL 0x10000000
# define OS_VER 0x0400
# define DLLCHARACTERISTICS 0
#ਜੇ_ਅੰਤ

#ਜੇ PTR_ਮਾਪ == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#ਨਹੀਂਤਾਂ
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ BYTE;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਸ਼ਬਦ_3;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ DWORD;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ULONGLONG;
#ਹਦਾਇਤ pack(ਧੱਕੋ, 1)

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_DOS_ਸਿਰਲੇਖ {  /* DOS .EXE header */
    ਸ਼ਬਦ_3 e_magic;         /* Magic number */
    ਸ਼ਬਦ_3 e_cblp;          /* Bytes on last page of file */
    ਸ਼ਬਦ_3 e_cp;            /* Pages in file */
    ਸ਼ਬਦ_3 e_crlc;          /* Relocations */
    ਸ਼ਬਦ_3 e_cparhdr;       /* Size of header in paragraphs */
    ਸ਼ਬਦ_3 e_minalloc;      /* Minimum extra paragraphs needed */
    ਸ਼ਬਦ_3 e_maxalloc;      /* Maximum extra paragraphs needed */
    ਸ਼ਬਦ_3 e_ss;            /* Initial (relative) SS value */
    ਸ਼ਬਦ_3 e_sp;            /* Initial SP value */
    ਸ਼ਬਦ_3 e_csum;          /* Checksum */
    ਸ਼ਬਦ_3 e_ip;            /* Initial IP value */
    ਸ਼ਬਦ_3 e_cs;            /* Initial (relative) CS value */
    ਸ਼ਬਦ_3 e_lfarlc;        /* File address of relocation table */
    ਸ਼ਬਦ_3 e_ovno;          /* Overlay number */
    ਸ਼ਬਦ_3 e_res[4];        /* Reserved words */
    ਸ਼ਬਦ_3 e_oemid;         /* OEM identifier (for e_oeminfo) */
    ਸ਼ਬਦ_3 e_oeminfo;       /* OEM information; e_oemid specific */
    ਸ਼ਬਦ_3 e_res2[10];      /* Reserved words */
    DWORD e_lfanew;        /* File address of new exe header */
} IMAGE_DOS_ਸਿਰਲੇਖ_2, *PIMAGE_DOS_ਸਿਰਲੇਖ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_NT_SIGNATURE  0x00004550  /* PE00 */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_FILE_ਸਿਰਲੇਖ {
    ਸ਼ਬਦ_3    Machine;
    ਸ਼ਬਦ_3    ਸੰਖਿਆ_ਦਾ_Sections;
    DWORD   ਸਮਾਂ_Date_Stamp;
    DWORD   ਸੂਚਕ_ਮੰਜ਼ਿਲ_ਚਿੰਨ੍ਹ_ਸਾਰਣੀ;
    DWORD   ਸੰਖਿਆ_ਦਾ_Symbols;
    ਸ਼ਬਦ_3    ਮਾਪ_ਦਾ_Optional_ਸਿਰਲੇਖ;
    ਸ਼ਬਦ_3    Characteristics;
} IMAGE_FILE_ਸਿਰਲੇਖ_2, *PIMAGE_FILE_ਸਿਰਲੇਖ;


#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_FILE_ਸਿਰਲੇਖ 20

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_ਅੰਕੜੇ_DIRECTORY {
    DWORD   Virtual_ਪਤਾ;
    DWORD   ਮਾਪ_3;
} IMAGE_ਅੰਕੜੇ_DIRECTORY_2, *PIMAGE_ਅੰਕੜੇ_DIRECTORY;


ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_OPTIONAL_ਸਿਰਲੇਖ {
    /* Standard fields. */
    ਸ਼ਬਦ_3    Magic;
    BYTE    Major_Linker_ਸੰਸਕਰਣ;
    BYTE    Minor_Linker_ਸੰਸਕਰਣ;
    DWORD   ਮਾਪ_ਦਾ_ਕੋਡ;
    DWORD   ਮਾਪ_ਦਾ_Initialized_ਅੰਕੜੇ;
    DWORD   ਮਾਪ_ਦਾ_Uninitialized_ਅੰਕੜੇ;
    DWORD   ਪਤਾ_ਦਾ_ਇੰਦਰਾਜ_ਬਿੰਦੂ;
    DWORD   ਅਧਾਰ_ਦਾ_ਕੋਡ;
#ਜੇ PTR_ਮਾਪ == 4
    DWORD   ਅਧਾਰ_ਦਾ_ਅੰਕੜੇ;
#ਜੇ_ਅੰਤ
    /* NT additional fields. */
    ADDR3264 Image_ਅਧਾਰ;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    ਸ਼ਬਦ_3    Major_Operating_System_ਸੰਸਕਰਣ;
    ਸ਼ਬਦ_3    Minor_Operating_System_ਸੰਸਕਰਣ;
    ਸ਼ਬਦ_3    Major_Image_ਸੰਸਕਰਣ;
    ਸ਼ਬਦ_3    Minor_Image_ਸੰਸਕਰਣ;
    ਸ਼ਬਦ_3    Major_Subsystem_ਸੰਸਕਰਣ;
    ਸ਼ਬਦ_3    Minor_Subsystem_ਸੰਸਕਰਣ;
    DWORD   Win32_ਸੰਸਕਰਣ_ਮੁੱਲ;
    DWORD   ਮਾਪ_ਦਾ_Image;
    DWORD   ਮਾਪ_ਦਾ_ਸਿਰਲੇਖਾਂ;
    DWORD   Check_ਜੋੜ;
    ਸ਼ਬਦ_3    Subsystem;
    ਸ਼ਬਦ_3    DllCharacteristics;
    ADDR3264 ਮਾਪ_ਦਾ_ਢੇਰ_Reserve;
    ADDR3264 ਮਾਪ_ਦਾ_ਢੇਰ_Commit;
    ADDR3264 ਮਾਪ_ਦਾ_ਢੇਰ_Reserve_2;
    ADDR3264 ਮਾਪ_ਦਾ_ਢੇਰ_Commit_2;
    DWORD   LoaderFlags;
    DWORD   ਸੰਖਿਆ_ਦਾ_Rva_And_Sizes;
    IMAGE_ਅੰਕੜੇ_DIRECTORY_2 ਅੰਕੜੇ_Directory[16];
} IMAGE_OPTIONAL_HEADER32, IMAGE_OPTIONAL_HEADER64, IMAGE_OPTIONAL_ਸਿਰਲੇਖ_2;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_EXPORT          0   /* Export Directory */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_IMPORT          1   /* Import Directory */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_RESOURCE        2   /* Resource Directory */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_EXCEPTION       3   /* Exception Directory */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_SECURITY        4   /* Security Directory */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_BASERELOC       5   /* Base Relocation Table */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_DEBUG           6   /* Debug Directory */
/*      IMAGE_DIRECTORY_ENTRY_COPYRIGHT       7      (X86 usage) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_ARCHITECTURE    7   /* Architecture Specific Data */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_GLOBALPTR       8   /* RVA of GP */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_TLS             9   /* TLS Directory */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_ਲੱਦੋ_CONFIG    10   /* Load Configuration Directory */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_BOUND_IMPORT   11   /* Bound Import Directory in headers */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_IAT            12   /* Import Address Table */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_DELAY_IMPORT   13   /* Delay Load Import Descriptors */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_COM_DESCRIPTOR 14   /* COM Runtime descriptor */

/* Section header format. */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_SHORT_NAME         8

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_SECTION_ਸਿਰਲੇਖ {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    ਸੰਘ {
            DWORD   Physical_ਪਤਾ;
            DWORD   Virtual_ਮਾਪ;
    } Misc;
    DWORD   Virtual_ਪਤਾ;
    DWORD   ਮਾਪ_ਦਾ_Raw_ਅੰਕੜੇ;
    DWORD   ਸੂਚਕ_ਮੰਜ਼ਿਲ_Raw_ਅੰਕੜੇ;
    DWORD   ਸੂਚਕ_ਮੰਜ਼ਿਲ_Relocations;
    DWORD   ਸੂਚਕ_ਮੰਜ਼ਿਲ_Linenumbers;
    ਸ਼ਬਦ_3    ਸੰਖਿਆ_ਦਾ_Relocations;
    ਸ਼ਬਦ_3    ਸੰਖਿਆ_ਦਾ_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_ਸਿਰਲੇਖ_2, *PIMAGE_SECTION_ਸਿਰਲੇਖ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_SECTION_ਸਿਰਲੇਖ     40

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD ਸਮਾਂ_Date_Stamp;
    ਸ਼ਬਦ_3 Major_ਸੰਸਕਰਣ;
    ਸ਼ਬਦ_3 Minor_ਸੰਸਕਰਣ;
    DWORD Name;
    DWORD ਅਧਾਰ_2;
    DWORD ਸੰਖਿਆ_ਦਾ_Functions;
    DWORD ਸੰਖਿਆ_ਦਾ_ਨਾਂ;
    DWORD ਪਤਾ_ਦਾ_Functions;
    DWORD ਪਤਾ_ਦਾ_ਨਾਂ;
    DWORD ਪਤਾ_ਦਾ_Name_Ordinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_TLS_DIRECTORY {
    ADDR3264 ਸ਼ੁਰੂ_ਪਤਾ_ਦਾ_Raw_ਅੰਕੜੇ;
    ADDR3264 ਸਿਰਾ_ਪਤਾ_ਦਾ_Raw_ਅੰਕੜੇ;
    ADDR3264 ਪਤਾ_ਦਾ_ਸੂਚਕਾਂਕ;
    ADDR3264 ਪਤਾ_ਦਾ_Call_Backs;
    DWORD ਮਾਪ_ਦਾ_Zero_Fill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_IMPORT_DESCRIPTOR {
    ਸੰਘ {
        DWORD Characteristics;
        DWORD Original_ਪਹਿਲਾ_Thunk;
    };
    DWORD ਸਮਾਂ_Date_Stamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD ਪਹਿਲਾ_Thunk;
} IMAGE_IMPORT_DESCRIPTOR;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_ਅਧਾਰ_RELOCATION {
    DWORD   Virtual_ਪਤਾ;
    DWORD   ਮਾਪ_ਦਾ_ਖੰਡ;
//  WORD    TypeOffset[1];
} IMAGE_ਅਧਾਰ_RELOCATION_2;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_ਅਧਾਰ_RELOCATION     8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_ABSOLUTE         0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_ਉੱਚਾ             1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_ਨੀਵਾਂ              2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_HIGHLOW          3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_HIGHADJ          4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_MIPS_JMPADDR     5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_SECTION          6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_REL32            7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_DIR64           10

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_CNT_ਕੋਡ                  0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_CNT_INITIALIZED_ਅੰਕੜੇ      0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_CNT_UNINITIALIZED_ਅੰਕੜੇ    0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_DISCARDABLE           0x02000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_SHARED                0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_EXECUTE               0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_READ                  0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_WRITE                 0x80000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_ਉੱਚਾ_ENTROPY_VA 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_DYNAMIC_ਅਧਾਰ 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_RELOCS_STRIPPED 0x0001

#ਹਦਾਇਤ pack(ਕੱਢੋ)

/* ----------------------------------------------------------- */
#ਜੇ_ਅੰਤ /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ IMAGE_DLLCHARACTERISTICS_DYNAMIC_ਅਧਾਰ
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_DYNAMIC_ਅਧਾਰ 0x0040
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਧੱਕੋ, 1)
ਬਣਤਰ pe_ਸਿਰਲੇਖ
{
    IMAGE_DOS_ਸਿਰਲੇਖ_2 doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_ਸਿਰਲੇਖ_2 filehdr;
#ਜੇ PTR_ਮਾਪ == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#ਨਹੀਂਤਾਂ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#ਨਹੀਂਤਾਂ
    IMAGE_OPTIONAL_ਸਿਰਲੇਖ_2 opthdr;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
};

ਬਣਤਰ pe_reloc_ਸਿਰਲੇਖ {
    DWORD ਵਿੱਥ;
    DWORD ਮਾਪ;
};

ਬਣਤਰ pe_rsrc_ਸਿਰਲੇਖ {
    ਬਣਤਰ IMAGE_FILE_ਸਿਰਲੇਖ filehdr;
    ਬਣਤਰ IMAGE_SECTION_ਸਿਰਲੇਖ sectionhdr;
};

ਬਣਤਰ pe_rsrc_reloc {
    DWORD ਵਿੱਥ;
    DWORD ਮਾਪ;
    ਸ਼ਬਦ_3 type;
};
#ਹਦਾਇਤ pack(ਕੱਢੋ)

/* ------------------------------------------------------------- */
/* internal temporary structures */

ਗਿਣਤੀ {
    sec_ਪਾਠ = 0,
    sec_rdata ,
    sec_ਅੰਕੜੇ ,
    sec_bss ,
    sec_idata ,
    sec_pdata ,
    sec_tdata ,
    sec_tbss ,
    sec_other ,
    sec_rsrc ,
    sec_debug ,
    sec_reloc ,
    sec_ਆਖਰੀ
};

#ਜੇ 0
ਸਥਿਰ ਅਚਲ DWORD pe_sec_flags[] = {
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
#ਜੇ_ਅੰਤ

ਬਣਤਰ section_info {
    ਪੂਰਨ cls;
    ਅੱਖਰ name[32];
    ADDR3264 sh_addr;
    DWORD sh_ਮਾਪ;
    DWORD pe_flags;
    Section *sec;
    DWORD ਅੰਕੜੇ_ਮਾਪ;
    IMAGE_SECTION_ਸਿਰਲੇਖ_2 ish;
};

ਬਣਤਰ import_ਚਿੰਨ੍ਹ {
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ;
    ਪੂਰਨ iat_ਸੂਚਕਾਂਕ;
    ਪੂਰਨ thk_ਵਿੱਥ;
};

ਬਣਤਰ pe_import_info {
    ਪੂਰਨ dll_ਸੂਚਕਾਂਕ;
    ਪੂਰਨ sym_ਗਿਣਤੀ;
    ਬਣਤਰ import_ਚਿੰਨ੍ਹ **symbols;
};

ਬਣਤਰ pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    ਅਚਲ ਅੱਖਰ *filename;
    ਪੂਰਨ type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    ਅਚਲ ਅੱਖਰ *ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ;
    DWORD ਸ਼ੁਰੂ_addr;
    DWORD imp_offs;
    DWORD imp_ਮਾਪ;
    DWORD iat_offs;
    DWORD iat_ਮਾਪ;
    DWORD exp_offs;
    DWORD exp_ਮਾਪ;
    DWORD tls_dir;
    DWORD tls_ਅੰਕੜੇ;
    DWORD tls_ਮਾਪ;
    ਪੂਰਨ subsystem;
    DWORD section_align;
    DWORD file_align;
    ਬਣਤਰ section_info **sec_info;
    ਪੂਰਨ sec_ਗਿਣਤੀ;
    ਬਣਤਰ pe_import_info **imp_info;
    ਪੂਰਨ imp_ਗਿਣਤੀ;
    /* output */
    FILE *op;
    DWORD ਜੋੜ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ pos;
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PE_NUL 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PE_DLL 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PE_GUI 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PE_EXE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PE_ਲੜੀਵਾਰ 4

/* --------------------------------------------*/

ਸਥਿਰ ਅਚਲ ਅੱਖਰ *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    ਅਚਲ ਅੱਖਰ *name = (ਅੱਖਰ*)symtab_section->link->ਅੰਕੜੇ + sym->st_name;
    ਜੇ (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        ਵਾਪਸ name + 1;
    ਵਾਪਸ name;
}


ਸਥਿਰ ਪੂਰਨ dynarray_assoc(ਖਾਲੀ **pp, ਪੂਰਨ n, ਪੂਰਨ ਕੁੰਜੀ)
{
    ਪੂਰਨ i;
    ਲਈ (i = 0; i < n; ++i, ++pp)
    ਜੇ (ਕੁੰਜੀ == **(ਪੂਰਨ **) pp)
        ਵਾਪਸ i;
    ਵਾਪਸ -1;
}

ਸਥਿਰ DWORD umin(DWORD a, DWORD b)
{
    ਵਾਪਸ a < b ? a : b;
}

ਸਥਿਰ DWORD umax(DWORD a, DWORD b)
{
    ਵਾਪਸ a < b ? b : a;
}

ਸਥਿਰ DWORD pe_file_align(ਬਣਤਰ pe_info *pe, DWORD n)
{
    ਵਾਪਸ (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

ਸਥਿਰ ADDR3264 pe_virtual_align(ਬਣਤਰ pe_info *pe, ADDR3264 n)
{
    ਵਾਪਸ (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

ਸਥਿਰ ਖਾਲੀ pe_align_section(Section *s, ਪੂਰਨ a)
{
    ਪੂਰਨ i = s->ਅੰਕੜੇ_ਵਿੱਥ & (a-1);
    ਜੇ (i)
        section_ptr_ਜੋੜੋ(s, a - i);
}

ਸਥਿਰ ਖਾਲੀ pe_ਸੈੱਟ_datadir(ਬਣਤਰ pe_ਸਿਰਲੇਖ *hdr, ਪੂਰਨ dir, DWORD addr, DWORD ਮਾਪ)
{
    hdr->opthdr.ਅੰਕੜੇ_Directory[dir].Virtual_ਪਤਾ = addr;
    hdr->opthdr.ਅੰਕੜੇ_Directory[dir].ਮਾਪ_3 = ਮਾਪ;
}

ਸਥਿਰ ਪੂਰਨ pe_fwrite(ਬਣਤਰ pe_info *pe, ਅਚਲ ਖਾਲੀ *ਅੰਕੜੇ, ਪੂਰਨ len)
{
    ਅਚਲ ਸ਼ਬਦ_3 *p = ਅੰਕੜੇ;
    DWORD ਜੋੜ;
    ਪੂਰਨ ret, i;
    pe->pos += (ret = fwrite(ਅੰਕੜੇ, 1, len, pe->op));
    ਜੋੜ = pe->ਜੋੜ;
    ਲਈ (i = len; i > 0; i -= 2) {
        ਜੋੜ += (i >= 2) ? *p++ : *(BYTE*)p;
        ਜੋੜ = (ਜੋੜ + (ਜੋੜ >> 16)) & 0xFFFF;
    }
    pe->ਜੋੜ = ਜੋੜ;
    ਵਾਪਸ len == ret ? 0 : -1;
}

ਸਥਿਰ ਖਾਲੀ pe_fpad(ਬਣਤਰ pe_info *pe, DWORD new_pos)
{
    ਅੱਖਰ buf[256];
    ਪੂਰਨ n, diff = new_pos - pe->pos;
    memset(buf, 0, ਆਕਾਰ buf);
    ਜਦੋਂ (diff > 0) {
        diff -= n = umin(diff, ਆਕਾਰ buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#ਹਦਾਇਤ pack(ਧੱਕੋ, 1)
ਬਣਤਰ syment
{
    ਸੰਘ {
        ਅੱਖਰ        n_name[8];     /* old COFF version */
        ਬਣਤਰ {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_ਵਿੱਥ_2;      /* offset into string table */
        };
    };
    int32_t         n_ਮੁੱਲ;        /* value of symbol */
    ਛੋਟਾ           n_scnum;        /* section number */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  n_type;         /* type and derived type */
    ਅੱਖਰ            n_sclass;       /* storage class */
    ਅੱਖਰ            n_numaux;       /* number of aux. entries */
};
#ਹਦਾਇਤ pack(ਕੱਢੋ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHF_ਨਿੱਜੀ 0x80000000

ਸਥਿਰ ਖਾਲੀ pe_ਜੋੜੋ_coffsym(ਬਣਤਰ pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    ਬਣਤਰ syment *se;
    ਪੂਰਨ n;

    ਜੇ (ਨਿਰਾ == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_ਨਿੱਜੀ);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_ਨਿੱਜੀ);
        section_ptr_ਜੋੜੋ(pe->coffstr, 4); /* coff string table size */
        ਵਾਪਸ;
    }

#ਜੇ 0
    se = section_ptr_ਜੋੜੋ(pe->coffsym, ਆਕਾਰ *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_ਜੋੜੋ(pe->coffsym, ਆਕਾਰ *se);
    strcpy((ਅੱਖਰ*)se, "no-file");
#ਜੇ_ਅੰਤ

#ਜੇ 1
    esym = (ElfSym*)s1->symtab->ਅੰਕੜੇ;
    ਲਈ (n = s1->symtab->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ *esym; ++esym, --n;) {
        ਪੂਰਨ sym_bind = ELFW(ST_BIND)(esym->st_info);
        ਜੇ (sym_bind == STB_GLOBAL) {
            ਅੱਖਰ *name = esym->st_name + (ਅੱਖਰ*)s1->symtab->link->ਅੰਕੜੇ;
            ਪੂਰਨ nl = ਲੜੀ_ਲੰਬਾਈ(name);
            addr_t ਮੁੱਲ = esym->st_ਮੁੱਲ;
            ਪੂਰਨ shnum = esym->st_shndx;
            ਜੇ (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                ਮੁੱਲ = ਮੁੱਲ - s->sh_addr;
            }
            se = section_ptr_ਜੋੜੋ(pe->coffsym, ਆਕਾਰ *se);
            se->n_ਮੁੱਲ = ਮੁੱਲ;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            ਜੇ (nl <= 8)
                ਸਮ੍ਰਿਤੀ_ਨਕਲ(se->n_name, name, nl);
            ਨਹੀਂਤਾਂ
                se->n_ਵਿੱਥ_2 = put_elf_str(pe->coffstr, name);
        }
    }
#ਜੇ_ਅੰਤ
    write32le(pe->coffstr->ਅੰਕੜੇ, pe->coffstr->ਅੰਕੜੇ_ਵਿੱਥ); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
ਸਥਿਰ ਖਾਲੀ pe_create_pdb(TCCState *s1, ਅਚਲ ਅੱਖਰ *exename)
{
    ਅੱਖਰ buf[300]; ਪੂਰਨ r;
    snprintf(buf, ਆਕਾਰ buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    strcpy(tcc_fileextension(strcpy(buf, exename)), ".pdb");
    ਜੇ (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } ਨਹੀਂਤਾਂ ਜੇ (s1->verbose) {
        ਲਿਖੋ("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
ਸਥਿਰ ਪੂਰਨ pe_write(ਬਣਤਰ pe_info *pe)
{
    ਸਥਿਰ ਅਚਲ ਬਣਤਰ pe_ਸਿਰਲੇਖ pe_template = {
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
    0x00E0 + (PTR_ਮਾਪ-4)*4, /*WORD    SizeOfOptionalHeader; */
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
#ਜੇ PTR_ਮਾਪ == 4
    0x00000000, /*DWORD   BaseOfData; */
#ਜੇ_ਅੰਤ
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

    ਬਣਤਰ pe_ਸਿਰਲੇਖ pe_ਸਿਰਲੇਖ = pe_template;

    ਪੂਰਨ i;
    DWORD file_ਵਿੱਥ;
    ਬਣਤਰ section_info *si;
    IMAGE_SECTION_ਸਿਰਲੇਖ_2 *psh;
    TCCState *s1 = pe->s1;

    ਜੇ (s1->do_debug)
        pe_ਜੋੜੋ_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    ਜੇ (ਨਿਰਾ == pe->op)
        ਵਾਪਸ tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        ਆਕਾਰ (ਬਣਤਰ pe_ਸਿਰਲੇਖ)
        + pe->sec_ਗਿਣਤੀ * ਆਕਾਰ (IMAGE_SECTION_ਸਿਰਲੇਖ_2)
        );

    file_ਵਿੱਥ = pe->sizeofheaders;

    ਜੇ (2 == s1->verbose)
        ਲਿਖੋ("-------------------------------"
               "\n  virt   file   size  section" "\n");
    ਲਈ (i = 0; i < pe->sec_ਗਿਣਤੀ; ++i) {
        DWORD addr, ਮਾਪ;
        ਅਚਲ ਅੱਖਰ *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        ਮਾਪ = si->sh_ਮਾਪ;
        psh = &si->ish;

        ਜੇ (2 == s1->verbose)
            ਲਿਖੋ("%6x %6x %6x  %s\n",
                (ਬਿਨਾਨਿਸ਼ਾਨੀ)addr, (ਬਿਨਾਨਿਸ਼ਾਨੀ)file_ਵਿੱਥ, (ਬਿਨਾਨਿਸ਼ਾਨੀ)ਮਾਪ, sh_name);

        ਚੋਣ (si->cls) {
            ਹਾਲਤ sec_ਪਾਠ:
                ਜੇ (!pe_ਸਿਰਲੇਖ.opthdr.ਅਧਾਰ_ਦਾ_ਕੋਡ)
                    pe_ਸਿਰਲੇਖ.opthdr.ਅਧਾਰ_ਦਾ_ਕੋਡ = addr;
                ਰੋਕੋ;

            ਹਾਲਤ sec_ਅੰਕੜੇ:
#ਜੇ PTR_ਮਾਪ == 4
                ਜੇ (!pe_ਸਿਰਲੇਖ.opthdr.ਅਧਾਰ_ਦਾ_ਅੰਕੜੇ)
                    pe_ਸਿਰਲੇਖ.opthdr.ਅਧਾਰ_ਦਾ_ਅੰਕੜੇ = addr;
#ਜੇ_ਅੰਤ
                ਰੋਕੋ;

            ਹਾਲਤ sec_bss:
                ਰੋਕੋ;

            ਹਾਲਤ sec_reloc:
                pe_ਸੈੱਟ_datadir(&pe_ਸਿਰਲੇਖ, IMAGE_DIRECTORY_ਇੰਦਰਾਜ_BASERELOC, addr, ਮਾਪ);
                ਰੋਕੋ;

            ਹਾਲਤ sec_rsrc:
                pe_ਸੈੱਟ_datadir(&pe_ਸਿਰਲੇਖ, IMAGE_DIRECTORY_ਇੰਦਰਾਜ_RESOURCE, addr, ਮਾਪ);
                ਰੋਕੋ;

            ਹਾਲਤ sec_pdata:
                pe_ਸੈੱਟ_datadir(&pe_ਸਿਰਲੇਖ, IMAGE_DIRECTORY_ਇੰਦਰਾਜ_EXCEPTION, addr, ਮਾਪ);
                ਰੋਕੋ;
        }

        ਜੇ (pe->imp_ਮਾਪ) {
            pe_ਸੈੱਟ_datadir(&pe_ਸਿਰਲੇਖ, IMAGE_DIRECTORY_ਇੰਦਰਾਜ_IMPORT,
                pe->imp_offs, pe->imp_ਮਾਪ);
            pe_ਸੈੱਟ_datadir(&pe_ਸਿਰਲੇਖ, IMAGE_DIRECTORY_ਇੰਦਰਾਜ_IAT,
                pe->iat_offs, pe->iat_ਮਾਪ);
        }
        ਜੇ (pe->exp_ਮਾਪ) {
            pe_ਸੈੱਟ_datadir(&pe_ਸਿਰਲੇਖ, IMAGE_DIRECTORY_ਇੰਦਰਾਜ_EXPORT,
                pe->exp_offs, pe->exp_ਮਾਪ);
        }
        ਜੇ (pe->tls_ਮਾਪ) {
            pe_ਸੈੱਟ_datadir(&pe_ਸਿਰਲੇਖ, IMAGE_DIRECTORY_ਇੰਦਰਾਜ_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_ਮਾਪ);
        }

        ਸਮ੍ਰਿਤੀ_ਨਕਲ(psh->Name, sh_name, umin(ਲੜੀ_ਲੰਬਾਈ(sh_name), ਆਕਾਰ psh->Name));
        ਜੇ (pe->coffstr && ਲੜੀ_ਲੰਬਾਈ(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((ਅੱਖਰ*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->Virtual_ਪਤਾ = addr;
        psh->Misc.Virtual_ਮਾਪ = ਮਾਪ;
        pe_ਸਿਰਲੇਖ.opthdr.ਮਾਪ_ਦਾ_Image =
            umax(pe_virtual_align(pe, ਮਾਪ + addr), pe_ਸਿਰਲੇਖ.opthdr.ਮਾਪ_ਦਾ_Image);

        ਜੇ (si->ਅੰਕੜੇ_ਮਾਪ) {
            psh->ਸੂਚਕ_ਮੰਜ਼ਿਲ_Raw_ਅੰਕੜੇ = file_ਵਿੱਥ;
            file_ਵਿੱਥ = pe_file_align(pe, file_ਵਿੱਥ + si->ਅੰਕੜੇ_ਮਾਪ);
            psh->ਮਾਪ_ਦਾ_Raw_ਅੰਕੜੇ = file_ਵਿੱਥ - psh->ਸੂਚਕ_ਮੰਜ਼ਿਲ_Raw_ਅੰਕੜੇ;
            ਜੇ (si->cls == sec_ਪਾਠ)
                pe_ਸਿਰਲੇਖ.opthdr.ਮਾਪ_ਦਾ_ਕੋਡ += psh->ਮਾਪ_ਦਾ_Raw_ਅੰਕੜੇ;
            ਨਹੀਂਤਾਂ
                pe_ਸਿਰਲੇਖ.opthdr.ਮਾਪ_ਦਾ_Initialized_ਅੰਕੜੇ += psh->ਮਾਪ_ਦਾ_Raw_ਅੰਕੜੇ;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_ਸਿਰਲੇਖ.filehdr.ਸੰਖਿਆ_ਦਾ_Sections = pe->sec_ਗਿਣਤੀ;
    pe_ਸਿਰਲੇਖ.opthdr.ਪਤਾ_ਦਾ_ਇੰਦਰਾਜ_ਬਿੰਦੂ = pe->ਸ਼ੁਰੂ_addr;
    pe_ਸਿਰਲੇਖ.opthdr.ਮਾਪ_ਦਾ_ਸਿਰਲੇਖਾਂ = pe->sizeofheaders;
    pe_ਸਿਰਲੇਖ.opthdr.Image_ਅਧਾਰ = pe->imagebase;
    pe_ਸਿਰਲੇਖ.opthdr.Subsystem = pe->subsystem;
    pe_ਸਿਰਲੇਖ.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    ਜੇ (s1->pe_ਢੇਰ_ਮਾਪ)
        pe_ਸਿਰਲੇਖ.opthdr.ਮਾਪ_ਦਾ_ਢੇਰ_Reserve = s1->pe_ਢੇਰ_ਮਾਪ;
    ਜੇ (PE_DLL == pe->type)
        pe_ਸਿਰਲੇਖ.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_ਸਿਰਲੇਖ.filehdr.Characteristics |= s1->pe_characteristics;
    ਜੇ (pe->reloc)
        pe_ਸਿਰਲੇਖ.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    ਜੇ (pe->coffsym) {
        pe_ਜੋੜੋ_coffsym(pe);
        pe_ਸਿਰਲੇਖ.filehdr.ਸੂਚਕ_ਮੰਜ਼ਿਲ_ਚਿੰਨ੍ਹ_ਸਾਰਣੀ = file_ਵਿੱਥ;
        pe_ਸਿਰਲੇਖ.filehdr.ਸੰਖਿਆ_ਦਾ_Symbols
            = pe->coffsym->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ (ਬਣਤਰ syment);
    }

    pe_fwrite(pe, &pe_ਸਿਰਲੇਖ, ਆਕਾਰ pe_ਸਿਰਲੇਖ);
    ਲਈ (i = 0; i < pe->sec_ਗਿਣਤੀ; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, ਆਕਾਰ(IMAGE_SECTION_ਸਿਰਲੇਖ_2));

    file_ਵਿੱਥ = pe->sizeofheaders;
    ਲਈ (i = 0; i < pe->sec_ਗਿਣਤੀ; ++i) {
        Section *s;
        si = pe->sec_info[i];
        ਜੇ (!si->ਅੰਕੜੇ_ਮਾਪ)
            ਜਾਰੀ;
        ਲਈ (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_ਵਿੱਥ);
            pe_fwrite(pe, s->ਅੰਕੜੇ, s->ਅੰਕੜੇ_ਵਿੱਥ);
            ਜੇ (s->prev)
                file_ਵਿੱਥ += s->prev->sh_addr - s->sh_addr;
        }
        file_ਵਿੱਥ = si->ish.ਸੂਚਕ_ਮੰਜ਼ਿਲ_Raw_ਅੰਕੜੇ + si->ish.ਮਾਪ_ਦਾ_Raw_ਅੰਕੜੇ;
        pe_fpad(pe, file_ਵਿੱਥ);
    }

    ਜੇ (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->ਅੰਕੜੇ, pe->coffsym->ਅੰਕੜੇ_ਵਿੱਥ);
        pe_fwrite(pe, pe->coffstr->ਅੰਕੜੇ, pe->coffstr->ਅੰਕੜੇ_ਵਿੱਥ);
        file_ਵਿੱਥ = pe->pos;
    }

    pe->ਜੋੜ += file_ਵਿੱਥ;
    fseek(pe->op, offsetof(ਬਣਤਰ pe_ਸਿਰਲੇਖ, opthdr.Check_ਜੋੜ), SEEK_SET);
    pe_fwrite(pe, &pe->ਜੋੜ, ਆਕਾਰ (DWORD));

    fclose (pe->op);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
    chmod(pe->filename, 0777);
#ਜੇ_ਅੰਤ

    ਜੇ (2 == s1->verbose)
        ਲਿਖੋ("-------------------------------\n");
    ਜੇ (s1->verbose)
        ਲਿਖੋ("<- %s (%u bytes)\n", pe->filename, (ਬਿਨਾਨਿਸ਼ਾਨੀ)file_ਵਿੱਥ);

    ਜੇ (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    ਵਾਪਸ 0;
}

/*----------------------------------------------------------------------------*/

ਸਥਿਰ ਬਣਤਰ import_ਚਿੰਨ੍ਹ *pe_ਜੋੜੋ_import(ਬਣਤਰ pe_info *pe, ਪੂਰਨ sym_ਸੂਚਕਾਂਕ)
{
    ਪੂਰਨ i;
    ਪੂਰਨ dll_ਸੂਚਕਾਂਕ;
    ਬਣਤਰ pe_import_info *p;
    ਬਣਤਰ import_ਚਿੰਨ੍ਹ *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->ਅੰਕੜੇ + sym_ਸੂਚਕਾਂਕ;
    dll_ਸੂਚਕਾਂਕ = isym->st_ਮਾਪ;

    i = dynarray_assoc ((ਖਾਲੀ**)pe->imp_info, pe->imp_ਗਿਣਤੀ, dll_ਸੂਚਕਾਂਕ);
    ਜੇ (-1 != i) {
        p = pe->imp_info[i];
        ਜਾਓ ਮਿਲਿਆ_dll;
    }
    p = tcc_mallocz(ਆਕਾਰ *p);
    p->dll_ਸੂਚਕਾਂਕ = dll_ਸੂਚਕਾਂਕ;
    dynarray_ਜੋੜੋ(&pe->imp_info, &pe->imp_ਗਿਣਤੀ, p);

ਮਿਲਿਆ_dll:
    i = dynarray_assoc ((ਖਾਲੀ**)p->symbols, p->sym_ਗਿਣਤੀ, sym_ਸੂਚਕਾਂਕ);
    ਜੇ (-1 != i)
        ਵਾਪਸ p->symbols[i];

    s = tcc_mallocz(ਆਕਾਰ *s);
    dynarray_ਜੋੜੋ(&p->symbols, &p->sym_ਗਿਣਤੀ, s);
    s->sym_ਸੂਚਕਾਂਕ = sym_ਸੂਚਕਾਂਕ;
    ਵਾਪਸ s;
}

ਸਥਿਰ ਖਾਲੀ pe_free_imports(ਬਣਤਰ pe_info *pe)
{
    ਪੂਰਨ i;
    ਲਈ (i = 0; i < pe->imp_ਗਿਣਤੀ; ++i) {
        ਬਣਤਰ pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_ਗਿਣਤੀ);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_ਗਿਣਤੀ);
}

/*----------------------------------------------------------------------------*/
ਸਥਿਰ ਖਾਲੀ pe_build_imports(ਬਣਤਰ pe_info *pe)
{
    ਪੂਰਨ thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_ਅਧਾਰ = pe->thunk->sh_addr - pe->imagebase;
    ਪੂਰਨ ndlls = pe->imp_ਗਿਣਤੀ;
    TCCState *s1 = pe->s1;

    ਲਈ (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_ਗਿਣਤੀ;

    ਜੇ (0 == sym_cnt)
        ਵਾਪਸ;

    pe_align_section(pe->thunk, 16);
    pe->imp_ਮਾਪ = (ndlls + 1) * ਆਕਾਰ(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_ਮਾਪ = (sym_cnt + ndlls) * ਆਕਾਰ(ADDR3264);
    dll_ptr = pe->thunk->ਅੰਕੜੇ_ਵਿੱਥ;
    thk_ptr = dll_ptr + pe->imp_ਮਾਪ;
    ent_ptr = thk_ptr + pe->iat_ਮਾਪ;
    pe->imp_offs = dll_ptr + rva_ਅਧਾਰ;
    pe->iat_offs = thk_ptr + rva_ਅਧਾਰ;
    section_ptr_ਜੋੜੋ(pe->thunk, pe->imp_ਮਾਪ + 2*pe->iat_ਮਾਪ);

    ਲਈ (i = 0; i < pe->imp_ਗਿਣਤੀ; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        ਪੂਰਨ k, n, dllindex;
        ADDR3264 v;
        ਬਣਤਰ pe_import_info *p = pe->imp_info[i];
        ਅਚਲ ਅੱਖਰ *name;
        DLLReference *dllref;

        dllindex = p->dll_ਸੂਚਕਾਂਕ;
        ਜੇ (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        ਨਹੀਂਤਾਂ
            name = "", dllref = ਨਿਰਾ;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->ਅੰਕੜੇ + dll_ptr);
        hdr->ਪਹਿਲਾ_Thunk = thk_ptr + rva_ਅਧਾਰ;
        hdr->Original_ਪਹਿਲਾ_Thunk = ent_ptr + rva_ਅਧਾਰ;
        hdr->Name = v + rva_ਅਧਾਰ;

        ਲਈ (k = 0, n = p->sym_ਗਿਣਤੀ; k <= n; ++k) {
            ਜੇ (k < n) {
                ਪੂਰਨ iat_ਸੂਚਕਾਂਕ = p->symbols[k]->iat_ਸੂਚਕਾਂਕ;
                ਪੂਰਨ sym_ਸੂਚਕਾਂਕ = p->symbols[k]->sym_ਸੂਚਕਾਂਕ;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->ਅੰਕੜੇ + sym_ਸੂਚਕਾਂਕ;
                ਅਚਲ ਅੱਖਰ *name = (ਅੱਖਰ*)s1->dynsymtab_section->link->ਅੰਕੜੇ + imp_sym->st_name;
                ਪੂਰਨ ordinal;

                /* patch symbol (and possibly its underscored alias) */
                ਕਰੋ {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->ਅੰਕੜੇ + iat_ਸੂਚਕਾਂਕ;
                    iat_ਸੂਚਕਾਂਕ = esym->st_ਮੁੱਲ;
                    esym->st_ਮੁੱਲ = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_ਅੰਕ;
                } ਜਦੋਂ (iat_ਸੂਚਕਾਂਕ);

                ਜੇ (dllref)
                    v = 0, ordinal = imp_sym->st_ਮੁੱਲ; /* ordinal from pe_load_def */
                ਨਹੀਂਤਾਂ
                    ordinal = 0, v = imp_sym->st_ਮੁੱਲ; /* address from tcc_add_symbol() */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
                ਜੇ (pe->type == PE_ਲੜੀਵਾਰ) {
                    ਜੇ (dllref) {
                        ਜੇ ( !dllref->handle )
                            dllref->handle = ਲੱਦੋ_Library_A(dllref->name);
                        v = (ADDR3264)Get_Proc_ਪਤਾ(dllref->handle, ordinal?(ਅੱਖਰ*)0+ordinal:name);
                    }
                    ਜੇ (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
                ਜੇ (ordinal) {
                    v = ordinal | (ADDR3264)1 << (ਆਕਾਰ(ADDR3264)*8 - 1);
                } ਨਹੀਂਤਾਂ {
                    v = pe->thunk->ਅੰਕੜੇ_ਵਿੱਥ + rva_ਅਧਾਰ;
                    section_ptr_ਜੋੜੋ(pe->thunk, ਆਕਾਰ(ਸ਼ਬਦ_3)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } ਨਹੀਂਤਾਂ {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->ਅੰਕੜੇ+thk_ptr) =
            *(ADDR3264*)(pe->thunk->ਅੰਕੜੇ+ent_ptr) = v;
            thk_ptr += ਆਕਾਰ (ADDR3264);
            ent_ptr += ਆਕਾਰ (ADDR3264);
        }
        dll_ptr += ਆਕਾਰ(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

ਬਣਤਰ pe_ਛਾਂਟੋ_sym
{
    ਪੂਰਨ ਸੂਚਕਾਂਕ;
    ਅਚਲ ਅੱਖਰ *name;
};

ਸਥਿਰ ਪੂਰਨ sym_cmp(ਅਚਲ ਖਾਲੀ *va, ਅਚਲ ਖਾਲੀ *vb)
{
    ਅਚਲ ਅੱਖਰ *ca = (*(ਬਣਤਰ pe_ਛਾਂਟੋ_sym**)va)->name;
    ਅਚਲ ਅੱਖਰ *cb = (*(ਬਣਤਰ pe_ਛਾਂਟੋ_sym**)vb)->name;
    ਵਾਪਸ strcmp(ca, cb);
}

ਸਥਿਰ ਖਾਲੀ pe_build_exports(ਬਣਤਰ pe_info *pe)
{
    ElfW(Sym) *sym;
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ, sym_ਸਿਰਾ;
    DWORD rva_ਅਧਾਰ, ਅਧਾਰ_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    ਪੂਰਨ sym_ਗਿਣਤੀ, ord;
    ਬਣਤਰ pe_ਛਾਂਟੋ_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    ਅੱਖਰ buf[260];
    ਅਚਲ ਅੱਖਰ *dllname;
    ਅਚਲ ਅੱਖਰ *name;

    rva_ਅਧਾਰ = pe->thunk->sh_addr - pe->imagebase;
    sym_ਗਿਣਤੀ = 0, sorted = ਨਿਰਾ, op = ਨਿਰਾ;

    sym_ਸਿਰਾ = symtab_section->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ(ElfW(Sym));
    ਲਈ (sym_ਸੂਚਕਾਂਕ = 1; sym_ਸੂਚਕਾਂਕ < sym_ਸਿਰਾ; ++sym_ਸੂਚਕਾਂਕ) {
        sym = (ElfW(Sym)*)symtab_section->ਅੰਕੜੇ + sym_ਸੂਚਕਾਂਕ;
        name = pe_export_name(s1, sym);
        ਜੇ (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(ਆਕਾਰ *p);
            p->ਸੂਚਕਾਂਕ = sym_ਸੂਚਕਾਂਕ;
            p->name = name;
            dynarray_ਜੋੜੋ(&sorted, &sym_ਗਿਣਤੀ, p);
        }
#ਜੇ 0
        ਜੇ (sym->st_other & ST_PE_EXPORT)
            ਲਿਖੋ("export: %s\n", name);
        ਜੇ (sym->st_other & ST_PE_STDCALL)
            ਲਿਖੋ("stdcall: %s\n", name);
#ਜੇ_ਅੰਤ
    }

    ਜੇ (0 == sym_ਗਿਣਤੀ)
        ਵਾਪਸ;

    qsort (sorted, sym_ਗਿਣਤੀ, ਆਕਾਰ *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    ਅਧਾਰ_o = pe->thunk->ਅੰਕੜੇ_ਵਿੱਥ;
    func_o = ਅਧਾਰ_o + ਆਕਾਰ(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_ਗਿਣਤੀ * ਆਕਾਰ (DWORD);
    ord_o = name_o + sym_ਗਿਣਤੀ * ਆਕਾਰ (DWORD);
    str_o = ord_o + sym_ਗਿਣਤੀ * ਆਕਾਰ(ਸ਼ਬਦ_3);

    hdr = section_ptr_ਜੋੜੋ(pe->thunk, str_o - ਅਧਾਰ_o);
    hdr->Characteristics        = 0;
    hdr->ਅਧਾਰ_2                   = 1;
    hdr->ਸੰਖਿਆ_ਦਾ_Functions      = sym_ਗਿਣਤੀ;
    hdr->ਸੰਖਿਆ_ਦਾ_ਨਾਂ          = sym_ਗਿਣਤੀ;
    hdr->ਪਤਾ_ਦਾ_Functions     = func_o + rva_ਅਧਾਰ;
    hdr->ਪਤਾ_ਦਾ_ਨਾਂ         = name_o + rva_ਅਧਾਰ;
    hdr->ਪਤਾ_ਦਾ_Name_Ordinals  = ord_o + rva_ਅਧਾਰ;
    hdr->Name                   = str_o + rva_ਅਧਾਰ;
    put_elf_str(pe->thunk, dllname);

#ਜੇ 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, ਆਕਾਰ buf, pe->filename);
    strcpy(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    ਜੇ (ਨਿਰਾ == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } ਨਹੀਂਤਾਂ {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        ਜੇ (s1->verbose)
            ਲਿਖੋ("<- %s (%d symbol%s)\n", buf, sym_ਗਿਣਤੀ, &"s"[sym_ਗਿਣਤੀ < 2]);
    }
#ਜੇ_ਅੰਤ

    ਲਈ (ord = 0; ord < sym_ਗਿਣਤੀ; ++ord)
    {
        p = sorted[ord], sym_ਸੂਚਕਾਂਕ = p->ਸੂਚਕਾਂਕ, name = p->name;
        /* insert actual address later in relocate_sections() */
        put_elf_reloc(symtab_section, pe->thunk,
            func_o, R_XXX_RELATIVE, sym_ਸੂਚਕਾਂਕ);
        *(DWORD*)(pe->thunk->ਅੰਕੜੇ + name_o)
            = pe->thunk->ਅੰਕੜੇ_ਵਿੱਥ + rva_ਅਧਾਰ;
        *(ਸ਼ਬਦ_3*)(pe->thunk->ਅੰਕੜੇ + ord_o)
            = ord;
        put_elf_str(pe->thunk, name);
        func_o += ਆਕਾਰ (DWORD);
        name_o += ਆਕਾਰ (DWORD);
        ord_o += ਆਕਾਰ (ਸ਼ਬਦ_3);
        ਜੇ (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = ਅਧਾਰ_o + rva_ਅਧਾਰ;
    pe->exp_ਮਾਪ = pe->thunk->ਅੰਕੜੇ_ਵਿੱਥ - ਅਧਾਰ_o;
    dynarray_reset(&sorted, &sym_ਗਿਣਤੀ);
    ਜੇ (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
ਸਥਿਰ ਖਾਲੀ pe_build_reloc (ਬਣਤਰ pe_info *pe)
{
    DWORD ਵਿੱਥ, ਖੰਡ_ptr, sh_addr, addr;
    ਪੂਰਨ ਗਿਣਤੀ_3, i;
    ElfW_Rel *rel, *rel_ਸਿਰਾ;
    Section *s = ਨਿਰਾ, *sr;
    ਬਣਤਰ pe_reloc_ਸਿਰਲੇਖ *hdr;
    TCCState *s1 = pe->s1;
    ਪੂਰਨ dwarf = 0, n;

    sh_addr = ਵਿੱਥ = ਖੰਡ_ptr = ਗਿਣਤੀ_3 = i = 0;
    rel = rel_ਸਿਰਾ = ਨਿਰਾ;

    ਲਈ(;;) {
        ਜੇ (rel < rel_ਸਿਰਾ) {
            ਪੂਰਨ type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_ਵਿੱਥ + sh_addr;
            ++ rel;
            ਜੇ (type != REL_TYPE_ਸਿੱਧਾ)
                ਜਾਰੀ;
            ਜੇ (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->ਅੰਕੜੇ + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                ਜੇ (n >= s1->dwlo && n < s1->dwhi)
                    ਜਾਰੀ;
            }
            ਜੇ (ਗਿਣਤੀ_3 == 0) { /* new block */
                ਖੰਡ_ptr = pe->reloc->ਅੰਕੜੇ_ਵਿੱਥ;
                section_ptr_ਜੋੜੋ(pe->reloc, ਆਕਾਰ(ਬਣਤਰ pe_reloc_ਸਿਰਲੇਖ));
                ਵਿੱਥ = addr & 0xFFFFFFFF<<12;
            }
            ਜੇ ((addr -= ਵਿੱਥ)  < (1<<12)) { /* one block spans 4k addresses */
                ਸ਼ਬਦ_3 *wp = section_ptr_ਜੋੜੋ(pe->reloc, ਆਕਾਰ (ਸ਼ਬਦ_3));
                *wp = addr | PE_IMAGE_REL<<12;
                ++ਗਿਣਤੀ_3;
                ਜਾਰੀ;
            }
            -- rel;

        } ਨਹੀਂਤਾਂ ਜੇ (s) {
            sr = s->reloc;
            ਜੇ (sr) {
                rel = (ElfW_Rel *)sr->ਅੰਕੜੇ;
                rel_ਸਿਰਾ = (ElfW_Rel *)(sr->ਅੰਕੜੇ + sr->ਅੰਕੜੇ_ਵਿੱਥ);
                sh_addr = s->sh_addr;
                dwarf = s->sh_ਅੰਕ >= s1->dwlo && s->sh_ਅੰਕ < s1->dwhi;
            }
            s = s->prev;
            ਜਾਰੀ;

        } ਨਹੀਂਤਾਂ ਜੇ (i < pe->sec_ਗਿਣਤੀ) {
            s = pe->sec_info[i]->sec, ++i;
            ਜਾਰੀ;

        } ਨਹੀਂਤਾਂ ਜੇ (!ਗਿਣਤੀ_3)
            ਰੋਕੋ;

        /* fill the last block and ready for a new one */
        ਜੇ (ਗਿਣਤੀ_3 & 1) /* align for DWORDS */
            section_ptr_ਜੋੜੋ(pe->reloc, ਆਕਾਰ(ਸ਼ਬਦ_3)), ++ਗਿਣਤੀ_3;
        hdr = (ਬਣਤਰ pe_reloc_ਸਿਰਲੇਖ *)(pe->reloc->ਅੰਕੜੇ + ਖੰਡ_ptr);
        hdr -> ਵਿੱਥ = ਵਿੱਥ - pe->imagebase;
        hdr -> ਮਾਪ = ਗਿਣਤੀ_3 * ਆਕਾਰ(ਸ਼ਬਦ_3) + ਆਕਾਰ(ਬਣਤਰ pe_reloc_ਸਿਰਲੇਖ);
        ਗਿਣਤੀ_3 = 0;
    }
}

/* ------------------------------------------------------------- */
ਸਥਿਰ ਖਾਲੀ pe_build_tls(ਬਣਤਰ pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    ਪੂਰਨ c, n;

    ਜੇ (0 == s) {
        pe->tls_ਮਾਪ = ਆਕਾਰ (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_ਜੋੜੋ(pe->thunk, pe->tls_ਮਾਪ, 16);
        pe->tls_ਅੰਕੜੇ = section_ਜੋੜੋ(ਅੰਕੜੇ_section, PTR_ਮਾਪ * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, ਅੰਕੜੇ_section->sh_ਅੰਕ, 0);
        ਲਈ (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_ਮਾਪ*n, REL_TYPE_ਸਿੱਧਾ, c);
        /* for generators */
        ਸੈੱਟ_elf_sym(symtab_section, pe->tls_ਅੰਕੜੇ, PTR_ਮਾਪ * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, ਅੰਕੜੇ_section->sh_ਅੰਕ, "__tls_index");
        ਵਾਪਸ;
    }

    ਜੇ (0 == s1->tls_ਸ਼ੁਰੂ)
        s1->tls_ਸ਼ੁਰੂ = s->sh_addr;
    d = (ਖਾਲੀ*)(pe->thunk->ਅੰਕੜੇ + pe->tls_dir);
    d->ਸ਼ੁਰੂ_ਪਤਾ_ਦਾ_Raw_ਅੰਕੜੇ = s1->tls_ਸ਼ੁਰੂ - ਅੰਕੜੇ_section->sh_addr;
    d->ਸਿਰਾ_ਪਤਾ_ਦਾ_Raw_ਅੰਕੜੇ = s->sh_addr + s->ਅੰਕੜੇ_ਵਿੱਥ - ਅੰਕੜੇ_section->sh_addr;
    d->ਪਤਾ_ਦਾ_ਸੂਚਕਾਂਕ = pe->tls_ਅੰਕੜੇ;
    d->ਪਤਾ_ਦਾ_Call_Backs = pe->tls_ਅੰਕੜੇ + PTR_ਮਾਪ;
    d->ਮਾਪ_ਦਾ_Zero_Fill = 0;
    d->Characteristics = 0;
    /* to reuse logic from linux in xxx-link.c */
    s1->tls_ਸਿਰਾ = s1->tls_ਸ਼ੁਰੂ;
}

/* ------------------------------------------------------------- */
ਸਥਿਰ ਪੂਰਨ pe_section_class(Section *s)
{
    ਪੂਰਨ type, flags;
    ਅਚਲ ਅੱਖਰ *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    ਜੇ (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        ਵਾਪਸ sec_debug;
    } ਨਹੀਂਤਾਂ ਜੇ (flags & SHF_ALLOC) {
        ਜੇ (flags & SHF_TLS)
            ਵਾਪਸ sec_tdata + (type == SHT_NOBITS);
        ਜੇ (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            ਜੇ (flags & SHF_EXECINSTR)
                ਵਾਪਸ sec_ਪਾਠ;
            ਜੇ (flags & SHF_WRITE)
                ਵਾਪਸ sec_ਅੰਕੜੇ;
            ਜੇ (0 == strcmp(name, ".rsrc"))
                ਵਾਪਸ sec_rsrc;
            ਜੇ (0 == strcmp(name, ".iedat"))
                ਵਾਪਸ sec_idata;
            ਜੇ (0 == strcmp(name, ".pdata"))
                ਵਾਪਸ sec_pdata;
            ਵਾਪਸ sec_rdata;
        } ਨਹੀਂਤਾਂ ਜੇ (type == SHT_NOBITS) {
            ਵਾਪਸ sec_bss;
        }
        ਵਾਪਸ sec_other;
    } ਨਹੀਂਤਾਂ {
        ਜੇ (0 == strcmp(name, ".reloc"))
            ਵਾਪਸ sec_reloc;
    }
    ਵਾਪਸ sec_ਆਖਰੀ;
}

ਸਥਿਰ ਪੂਰਨ pe_ਸੌਂਪੋ_ਪਤੇ (ਬਣਤਰ pe_info *pe)
{
    ਪੂਰਨ i, k, n, c, nbs;
    ADDR3264 addr;
    ਪੂਰਨ *sec_ਕ੍ਰਮ, *sec_cls;
    ਬਣਤਰ section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    ਜੇ (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_ਅਧਾਰ))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_ਕ੍ਰਮ = tcc_mallocz(2 * ਆਕਾਰ (ਪੂਰਨ) * nbs);
    sec_cls = sec_ਕ੍ਰਮ + nbs;
    ਲਈ (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        ਲਈ (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_ਕ੍ਰਮ[n] = sec_ਕ੍ਰਮ[n - 1];
        sec_cls[n] = k, sec_ਕ੍ਰਮ[n] = i;
        ਜੇ ((s->sh_flags & SHF_TLS) && 0 == pe->tls_ਮਾਪ)
            pe_build_tls(pe, ਨਿਰਾ);
    }
    si = ਨਿਰਾ;
    addr = pe->imagebase + 1;
    ਲਈ (i = 1; (c = sec_cls[i]) < sec_ਆਖਰੀ; ++i) {
        s = s1->sections[sec_ਕ੍ਰਮ[i]];

        ਜੇ (PE_ਮਿਲਾਓ_ਅੰਕੜੇ && c == sec_bss)
            c = sec_ਅੰਕੜੇ;
        ਜੇ (c == sec_tbss)
            c = sec_tdata;

        ਜੇ (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } ਨਹੀਂਤਾਂ {
            si = ਨਿਰਾ;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        ਜੇ (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        ਜੇ (s == pe->reloc)
            pe_build_reloc (pe);

        ਜੇ (0 == s->ਅੰਕੜੇ_ਵਿੱਥ)
            ਜਾਰੀ;

        ਜੇ (si)
            ਜਾਓ ਜੋੜੋ_section;

        si = tcc_mallocz(ਆਕਾਰ *si);
        dynarray_ਜੋੜੋ(&pe->sec_info, &pe->sec_ਗਿਣਤੀ, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        ਜੇ (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_ਕੋਡ;
        ਨਹੀਂਤਾਂ ਜੇ (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_ਅੰਕੜੇ;
        ਨਹੀਂਤਾਂ
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_ਅੰਕੜੇ;
        ਜੇ (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        ਜੇ (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

ਜੋੜੋ_section:
        s->sh_info = pe->sec_ਗਿਣਤੀ; /* section number for coff syms */
        addr += s->ਅੰਕੜੇ_ਵਿੱਥ;
        si->sh_ਮਾਪ = addr - si->sh_addr;
        ਜੇ (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            ਜਦੋਂ (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = ਨਿਰਾ;
            si->ਅੰਕੜੇ_ਮਾਪ = si->sh_ਮਾਪ;
        }

        ਜੇ (s->sh_flags & SHF_TLS) {
            strcpy(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#ਜੇ 0
    ਲਈ (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_ਕ੍ਰਮ[i]];
        ਪੂਰਨ type = s->sh_type;
        ਪੂਰਨ flags = s->sh_flags;
        ਲਿਖੋ("section %-16s %-10s %p %04x %2d %s,%s,%s\n",
            s->name,
            type == SHT_PROGBITS ? "progbits" :
            type == SHT_INIT_ARRAY ? "initarr" :
            type == SHT_FINI_ARRAY ? "finiarr" :
            type == SHT_NOBITS ? "nobits" :
            type == SHT_SYMTAB ? "symtab" :
            type == SHT_STRTAB ? "strtab" :
            type == SHT_RELX ? "rel" : "???",
            s->sh_addr,
            (ਬਿਨਾਨਿਸ਼ਾਨੀ)s->ਅੰਕੜੇ_ਵਿੱਥ,
            s->sh_addralign,
            flags & SHF_ALLOC ? "alloc" : "",
            flags & SHF_WRITE ? "write" : "",
            flags & SHF_EXECINSTR ? "exec" : ""
            );
        fflush(stdout);
    }
    s1->verbose = 2;
#ਜੇ_ਅੰਤ
    tcc_free(sec_ਕ੍ਰਮ);
    ਵਾਪਸ 0;
}

/*----------------------------------------------------------------------------*/
ਸਥਿਰ ਪੂਰਨ pe_check_symbols(ਬਣਤਰ pe_info *pe)
{
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ, sym_ਸਿਰਾ;
    ਪੂਰਨ ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(ਪਾਠ_section, 8);

    sym_ਸਿਰਾ = symtab_section->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ(ElfW(Sym));
    ਲਈ (sym_ਸੂਚਕਾਂਕ = 1; sym_ਸੂਚਕਾਂਕ < sym_ਸਿਰਾ; ++sym_ਸੂਚਕਾਂਕ) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->ਅੰਕੜੇ + sym_ਸੂਚਕਾਂਕ;
        ਜੇ (sym->st_shndx == SHN_UNDEF) {
            ਅਚਲ ਅੱਖਰ *name = (ਅੱਖਰ*)symtab_section->link->ਅੰਕੜੇ + sym->st_name;
            ਬਿਨਾਨਿਸ਼ਾਨੀ type = ELFW(ST_TYPE)(sym->st_info);
            ਪੂਰਨ imp_sym = 0;
            ਬਣਤਰ import_ਚਿੰਨ੍ਹ *is;

            ਪੂਰਨ _imp_, n;
            ਅੱਖਰ ਬਫਰ[200];
            ਅਚਲ ਅੱਖਰ *s, *p;

            n = _imp_ = 0;
            ਜੇ (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            ਕਰੋ {
                s = pe_export_name(s1, sym);
                ਜੇ (n) {
                    /* second try: */
                    ਜੇ (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        ਜੇ (!p || s[0] != '_')
                            ਰੋਕੋ;
                        strcpy(ਬਫਰ, s+1)[p-s-1] = 0, s = ਬਫਰ;
                    } ਨਹੀਂਤਾਂ ਜੇ (s[0] != '_') { /* try non-ansi function */
                        ਬਫਰ[0] = '_', strcpy(ਬਫਰ + 1, s), s = ਬਫਰ;
                    } ਨਹੀਂਤਾਂ ਜੇ (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } ਨਹੀਂਤਾਂ ਜੇ (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } ਨਹੀਂਤਾਂ {
                        ਰੋਕੋ;
                    }
                }
                imp_sym = ਲੱਭੋ_elf_sym(s1->dynsymtab_section, s);
            } ਜਦੋਂ (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            ਜੇ (0 == imp_sym)
                ਜਾਰੀ; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_ਜੋੜੋ_import(pe, imp_sym);

            ਜੇ (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                ਬਿਨਾਨਿਸ਼ਾਨੀ ਵਿੱਥ = is->thk_ਵਿੱਥ;
                ਜੇ (ਵਿੱਥ) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } ਨਹੀਂਤਾਂ {
                    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(ਬਫਰ, "IAT.%s", name);
                    is->iat_ਸੂਚਕਾਂਕ = put_elf_sym(
                        symtab_section, 0, ਆਕਾਰ(DWORD),
                        ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT),
                        0, SHN_UNDEF, ਬਫਰ);

                    ਵਿੱਥ = ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ;
                    is->thk_ਵਿੱਥ = ਵਿੱਥ;

                    /* add the 'jmp IAT[x]' instruction */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
                    p = section_ptr_ਜੋੜੋ(ਪਾਠ_section, 8+4); // room for code and address
                    write32le(p + 0, 0xE59FC000); // arm code ldr ip, [pc] ; PC+8+0 = 0001xxxx
                    write32le(p + 4, 0xE59CF000); // arm code ldr pc, [ip]
                    put_elf_reloc(symtab_section, ਪਾਠ_section,
                        ਵਿੱਥ + 8, R_XXX_THUNKFIX, is->iat_ਸੂਚਕਾਂਕ); // offset to IAT position
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64)
                    p = section_ptr_ਜੋੜੋ(ਪਾਠ_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, ਪਾਠ_section,
                        ਵਿੱਥ + 16, R_XXX_THUNKFIX, is->iat_ਸੂਚਕਾਂਕ);
#ਨਹੀਂਤਾਂ
                    p = section_ptr_ਜੋੜੋ(ਪਾਠ_section, 8);
                    write16le(p, 0x25FF);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
                    write32le(p + 2, (DWORD)-4);
#ਜੇ_ਅੰਤ
                    put_elf_reloc(symtab_section, ਪਾਠ_section, 
                        ਵਿੱਥ + 2, R_XXX_THUNKFIX, is->iat_ਸੂਚਕਾਂਕ);
#ਜੇ_ਅੰਤ
                }
                /* tcc_realloc might have altered sym's address */
                sym = (ElfW(Sym) *)symtab_section->ਅੰਕੜੇ + sym_ਸੂਚਕਾਂਕ;
                /* patch the original symbol */
                sym->st_ਮੁੱਲ = ਵਿੱਥ;
                sym->st_shndx = ਪਾਠ_section->sh_ਅੰਕ;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } ਨਹੀਂਤਾਂ { /* STT_OBJECT */
                ਜੇ (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_ਮੁੱਲ = is->iat_ਸੂਚਕਾਂਕ; /* chain potential alias */
                is->iat_ਸੂਚਕਾਂਕ = sym_ਸੂਚਕਾਂਕ;
            }

        } ਨਹੀਂਤਾਂ ਜੇ (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    ਵਾਪਸ ret;
}

/*----------------------------------------------------------------------------*/
#ਜੇ PE_PRINT_SECTIONS
ਸਥਿਰ ਖਾਲੀ pe_print_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    ਪੂਰਨ i, n, l, m;
    p = s->ਅੰਕੜੇ;
    e = s->ਅੰਕੜੇ + s->ਅੰਕੜੇ_ਵਿੱਥ;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    ਜੇ (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    ਜੇ (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (ਬਿਨਾਨਿਸ਼ਾਨੀ)s->sh_addr);
    fprintf(f, "\ncontents %08X", (ਬਿਨਾਨਿਸ਼ਾਨੀ)l);
    fprintf(f, "\n\n");

    ਜੇ (s->sh_type == SHT_NOBITS)
        ਵਾਪਸ;

    ਜੇ (0 == l)
        ਵਾਪਸ;

    ਜੇ (s->sh_type == SHT_SYMTAB)
        m = ਆਕਾਰ(ElfW(Sym));
    ਨਹੀਂਤਾਂ ਜੇ (s->sh_type == SHT_RELX)
        m = ਆਕਾਰ(ElfW_Rel);
    ਨਹੀਂਤਾਂ
        m = 16;

    fprintf(f, "%-8s", "offset");
    ਲਈ (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    ਜੇ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        ਅਚਲ ਅੱਖਰ *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            ਨਿਰਾ
        };

        ਅਚਲ ਅੱਖਰ *fields2[] = {
            "offs",
            "type",
            "symb",
            ਨਿਰਾ
        };

        ਅਚਲ ਅੱਖਰ **p;

        ਜੇ (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        ਨਹੀਂਤਾਂ
            p = fields2, n = 58;

        ਲਈ (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    ਲਈ (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    ਲਈ (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        ਲਈ (n = 0; n < m; ++n) {
            ਜੇ (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            ਨਹੀਂਤਾਂ
                fprintf(f, "   ");
        }

        ਜੇ (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            ਅਚਲ ਅੱਖਰ *name = s->link->ਅੰਕੜੇ + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (ਬਿਨਾਨਿਸ਼ਾਨੀ)sym->st_name,
                    (ਬਿਨਾਨਿਸ਼ਾਨੀ)sym->st_ਮੁੱਲ,
                    (ਬਿਨਾਨਿਸ਼ਾਨੀ)sym->st_ਮਾਪ,
                    (ਬਿਨਾਨਿਸ਼ਾਨੀ)ELFW(ST_BIND)(sym->st_info),
                    (ਬਿਨਾਨਿਸ਼ਾਨੀ)ELFW(ST_TYPE)(sym->st_info),
                    (ਬਿਨਾਨਿਸ਼ਾਨੀ)sym->st_other,
                    (ਬਿਨਾਨਿਸ਼ਾਨੀ)sym->st_shndx,
                    name);

        } ਨਹੀਂਤਾਂ ਜੇ (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->ਅੰਕੜੇ + ELFW(R_SYM)(rel->r_info);
            ਅਚਲ ਅੱਖਰ *name = s->link->link->ਅੰਕੜੇ + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (ਬਿਨਾਨਿਸ਼ਾਨੀ)rel->r_ਵਿੱਥ,
                    (ਬਿਨਾਨਿਸ਼ਾਨੀ)ELFW(R_TYPE)(rel->r_info),
                    (ਬਿਨਾਨਿਸ਼ਾਨੀ)ELFW(R_SYM)(rel->r_info),
                    name);
        } ਨਹੀਂਤਾਂ {
            fprintf(f, "   ");
            ਲਈ (n = 0; n < m; ++n) {
                ਜੇ (n + i < l) {
                    b = p[i + n];
                    ਜੇ (b < 32 || b >= 127)
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

ਸਥਿਰ ਖਾਲੀ pe_print_sections(TCCState *s1, ਅਚਲ ਅੱਖਰ *fname)
{
    Section *s;
    FILE *f;
    ਪੂਰਨ i;
    f = fopen(fname, "w");
    ਲਈ (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    fclose(f);
}
#ਜੇ_ਅੰਤ

/* ------------------------------------------------------------- */

ST_FUNC ਪੂਰਨ pe_putimport(TCCState *s1, ਪੂਰਨ dllindex, ਅਚਲ ਅੱਖਰ *name, addr_t ਮੁੱਲ)
{
    ਵਾਪਸ ਸੈੱਟ_elf_sym(
        s1->dynsymtab_section,
        ਮੁੱਲ,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        ਮੁੱਲ ? SHN_ABS : SHN_UNDEF,
        name
        );
}

ਸਥਿਰ ਪੂਰਨ read_mem(ਪੂਰਨ fd, ਬਿਨਾਨਿਸ਼ਾਨੀ ਵਿੱਥ, ਖਾਲੀ *ਬਫਰ, ਬਿਨਾਨਿਸ਼ਾਨੀ len)
{
    lseek(fd, ਵਿੱਥ, SEEK_SET);
    ਵਾਪਸ len == ਪਠ(fd, ਬਫਰ, len);
}

/* ------------------------------------------------------------- */

ਸਥਿਰ ਪੂਰਨ get_dllexports(ਪੂਰਨ fd, ਅੱਖਰ **pp)
{
    ਪੂਰਨ i, k, l, n, n0, ret;
    ਅੱਖਰ *p;

    IMAGE_SECTION_ਸਿਰਲੇਖ_2 ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_ਸਿਰਲੇਖ_2 dh;
    IMAGE_FILE_ਸਿਰਲੇਖ_2 ih;
    DWORD sig, ref, addr;
    DWORD *namep = ਨਿਰਾ, p0 = 0, p1;

    ਪੂਰਨ pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = ਨਿਰਾ;
    ret = 1;
    ਜੇ (!read_mem(fd, 0, &dh, ਆਕਾਰ dh))
        ਜਾਓ the_ਸਿਰਾ;
    ਜੇ (!read_mem(fd, dh.e_lfanew, &sig, ਆਕਾਰ sig))
        ਜਾਓ the_ਸਿਰਾ;
    ਜੇ (sig != 0x00004550)
        ਜਾਓ the_ਸਿਰਾ;
    pef_hdroffset = dh.e_lfanew + ਆਕਾਰ sig;
    ਜੇ (!read_mem(fd, pef_hdroffset, &ih, ਆਕਾਰ ih))
        ਜਾਓ the_ਸਿਰਾ;
    opt_hdroffset = pef_hdroffset + ਆਕਾਰ ih;
    ਜੇ (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + ਆਕਾਰ oh;
        ਜੇ (!read_mem(fd, opt_hdroffset, &oh, ਆਕਾਰ oh))
            ਜਾਓ the_ਸਿਰਾ;
        ਜੇ (IMAGE_DIRECTORY_ਇੰਦਰਾਜ_EXPORT >= oh.ਸੰਖਿਆ_ਦਾ_Rva_And_Sizes)
            ਜਾਓ the_ਸਿਰਾ_0;
        addr = oh.ਅੰਕੜੇ_Directory[IMAGE_DIRECTORY_ਇੰਦਰਾਜ_EXPORT].Virtual_ਪਤਾ;
    } ਨਹੀਂਤਾਂ ਜੇ (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + ਆਕਾਰ oh;
        ਜੇ (!read_mem(fd, opt_hdroffset, &oh, ਆਕਾਰ oh))
            ਜਾਓ the_ਸਿਰਾ;
        ਜੇ (IMAGE_DIRECTORY_ਇੰਦਰਾਜ_EXPORT >= oh.ਸੰਖਿਆ_ਦਾ_Rva_And_Sizes)
            ਜਾਓ the_ਸਿਰਾ_0;
        addr = oh.ਅੰਕੜੇ_Directory[IMAGE_DIRECTORY_ਇੰਦਰਾਜ_EXPORT].Virtual_ਪਤਾ;
    } ਨਹੀਂਤਾਂ
        ਜਾਓ the_ਸਿਰਾ;

    //printf("addr: %08x\n", addr);
    ਲਈ (i = 0; i < ih.ਸੰਖਿਆ_ਦਾ_Sections; ++i) {
        ਜੇ (!read_mem(fd, sec_hdroffset + i * ਆਕਾਰ ish, &ish, ਆਕਾਰ ish))
            ਜਾਓ the_ਸਿਰਾ;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        ਜੇ (addr >= ish.Virtual_ਪਤਾ && addr < ish.Virtual_ਪਤਾ + ish.ਮਾਪ_ਦਾ_Raw_ਅੰਕੜੇ)
            ਜਾਓ ਮਿਲਿਆ;
    }
    ਜਾਓ the_ਸਿਰਾ_0;
ਮਿਲਿਆ:
    ref = ish.Virtual_ਪਤਾ - ish.ਸੂਚਕ_ਮੰਜ਼ਿਲ_Raw_ਅੰਕੜੇ;
    ਜੇ (!read_mem(fd, addr - ref, &ied, ਆਕਾਰ ied))
        ਜਾਓ the_ਸਿਰਾ;
    k = ied.ਸੰਖਿਆ_ਦਾ_ਨਾਂ;
    ਜੇ (k) {
        namep = tcc_malloc(l = k * ਆਕਾਰ *namep);
        ਜੇ (!read_mem(fd, ied.ਪਤਾ_ਦਾ_ਨਾਂ - ref, namep, l))
            ਜਾਓ the_ਸਿਰਾ;
        ਲਈ (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            ਜੇ (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            ਕਰੋ {
                ਜੇ (0 == l) {
                    ਜੇ (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    ਜੇ ((l = ਪਠ(fd, p + n, 1000 - 1)) <= 0)
                        ਜਾਓ the_ਸਿਰਾ;
                }
                --l, ++p0;
            } ਜਦੋਂ (p[n++]);
        }
        p[n] = 0;
    }
the_ਸਿਰਾ_0:
    ret = 0;
the_ਸਿਰਾ:
    tcc_free(namep);
    ਜੇ (ret && p)
        tcc_free(p), p = ਨਿਰਾ;
    *pp = p;
    ਵਾਪਸ ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

ਸਥਿਰ ਪੂਰਨ pe_ਲੱਦੋ_res(TCCState *s1, ਪੂਰਨ fd)
{
    ਬਣਤਰ pe_rsrc_ਸਿਰਲੇਖ hdr;
    Section *rsrc_section;
    ਪੂਰਨ i, ret = -1, sym_ਸੂਚਕਾਂਕ;
    BYTE *ptr;
    ਬਿਨਾਨਿਸ਼ਾਨੀ offs;

    ਜੇ (!read_mem(fd, 0, &hdr, ਆਕਾਰ hdr))
        ਜਾਓ quit;

    ਜੇ (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.ਸੰਖਿਆ_ਦਾ_Sections != 1
        || strcmp((ਅੱਖਰ*)hdr.sectionhdr.Name, ".rsrc") != 0)
        ਜਾਓ quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_ਜੋੜੋ(rsrc_section, hdr.sectionhdr.ਮਾਪ_ਦਾ_Raw_ਅੰਕੜੇ);
    offs = hdr.sectionhdr.ਸੂਚਕ_ਮੰਜ਼ਿਲ_Raw_ਅੰਕੜੇ;
    ਜੇ (!read_mem(fd, offs, ptr, hdr.sectionhdr.ਮਾਪ_ਦਾ_Raw_ਅੰਕੜੇ))
        ਜਾਓ quit;
    offs = hdr.sectionhdr.ਸੂਚਕ_ਮੰਜ਼ਿਲ_Relocations;
    sym_ਸੂਚਕਾਂਕ = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_ਅੰਕ, ".rsrc");
    ਲਈ (i = 0; i < hdr.sectionhdr.ਸੰਖਿਆ_ਦਾ_Relocations; ++i) {
        ਬਣਤਰ pe_rsrc_reloc rel;
        ਜੇ (!read_mem(fd, offs, &rel, ਆਕਾਰ rel))
            ਜਾਓ quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        ਜੇ (rel.type != RSRC_RELTYPE)
            ਜਾਓ quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.ਵਿੱਥ, R_XXX_RELATIVE, sym_ਸੂਚਕਾਂਕ);
        offs += ਆਕਾਰ rel;
    }
    ret = 0;
quit:
    ਵਾਪਸ ret;
}

/* ------------------------------------------------------------- */

ਸਥਿਰ ਅੱਖਰ *trimfront(ਅੱਖਰ *p)
{
    ਜਦੋਂ ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)*p <= ' ' && *p && *p != '\n')
	++p;
    ਵਾਪਸ p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

ਸਥਿਰ ਅੱਖਰ *get_token(ਅੱਖਰ **s, ਅੱਖਰ *f)
{
    ਅੱਖਰ *p, *e;
    ਪੂਰਨ q;

    p = trimfront(*s);
    q = *p;
    ਜੇ (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    ਨਹੀਂਤਾਂ
        q = ' ';
    ਲਈ (e = p; (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)*e >= ' ' && *e != q; ++e)
        ;
    ਜੇ (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    ਵਾਪਸ p;
}

ਸਥਿਰ ਪੂਰਨ pe_ਲੱਦੋ_def(TCCState *s1, ਪੂਰਨ fd)
{
    ਪੂਰਨ state = 0, ret = -1, dllindex = 0, ord;
    ਅੱਖਰ dllname[80], *buf, *ਸਤਰ, *p, *x, ਅਗਲਾ;

    buf = tcc_ਲੱਦੋ_ਪਾਠ(fd);
    ਜੇ (!buf)
        ਵਾਪਸ ret;

    ਲਈ (ਸਤਰ = buf;; ++ਸਤਰ)  {
        p = get_token(&ਸਤਰ, &ਅਗਲਾ);
        ਜੇ (!(*p && *p != ';'))
            ਜਾਓ skip;
        ਚੋਣ (state) {
        ਹਾਲਤ 0:
            ਜੇ (0 != stricmp(p, "LIBRARY") || ਅਗਲਾ == '\n')
                ਜਾਓ quit;
            pstrcpy(dllname, ਆਕਾਰ dllname, get_token(&ਸਤਰ, &ਅਗਲਾ));
            ਜੇ (!*tcc_fileextension(dllname))
                pstrcat(dllname, ਆਕਾਰ dllname, ".dll");
            ++state;
            ਰੋਕੋ;
        ਹਾਲਤ 1:
            ਜੇ (0 != stricmp(p, "EXPORTS"))
                ਜਾਓ quit;
            ++state;
            ਰੋਕੋ;
        ਹਾਲਤ 2:
            dllindex = tcc_ਜੋੜੋ_dllref(s1, dllname, 0)->ਸੂਚਕਾਂਕ;
            ++state;
            /* fall through */
        ਮੂਲ:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            ਜੇ (ਅਗਲਾ == '@') {
                x = get_token(&ਸਤਰ, &ਅਗਲਾ);
                ord = (ਪੂਰਨ)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            ਰੋਕੋ;
        }
skip:
        ਜਦੋਂ ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)ਅਗਲਾ > ' ')
            get_token(&ਸਤਰ, &ਅਗਲਾ);
        ਜੇ (ਅਗਲਾ != '\n')
            ਰੋਕੋ;
    }
    ret = 0;
quit:
    tcc_free(buf);
    ਵਾਪਸ ret;
}

/* ------------------------------------------------------------- */

ਸਥਿਰ ਪੂਰਨ pe_ਲੱਦੋ_dll(TCCState *s1, ਪੂਰਨ fd, ਅਚਲ ਅੱਖਰ *filename)
{
    ਅੱਖਰ *p, *q;
    DLLReference *ref = tcc_ਜੋੜੋ_dllref(s1, filename, 0);
    ਜੇ (ref->ਮਿਲਿਆ)
        ਵਾਪਸ 0;
    ਜੇ (get_dllexports(fd, &p))
        ਵਾਪਸ -1;
    ਜੇ (p) {
        ਲਈ (q = p; *q; q += 1 + ਲੜੀ_ਲੰਬਾਈ(q))
            pe_putimport(s1, ref->ਸੂਚਕਾਂਕ, q, 0);
        tcc_free(p);
    }
    ਵਾਪਸ 0;
}

ST_FUNC ਪੂਰਨ pe_ਲੱਦੋ_file(ਬਣਤਰ TCCState *s1, ਪੂਰਨ fd, ਅਚਲ ਅੱਖਰ *filename)
{
    ਪੂਰਨ ret = -1;
    ਅੱਖਰ buf[10];
    ਜੇ (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_ਲੱਦੋ_def(s1, fd);
    ਨਹੀਂਤਾਂ ਜੇ (pe_ਲੱਦੋ_res(s1, fd) == 0)
        ret = 0;
    ਨਹੀਂਤਾਂ ਜੇ (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_ਲੱਦੋ_dll(s1, fd, filename);
    ਵਾਪਸ ret;
}

PUB_FUNC ਪੂਰਨ tcc_get_dllexports(ਅਚਲ ਅੱਖਰ *filename, ਅੱਖਰ **pp)
{
    ਪੂਰਨ ret, fd = open(filename, O_RDONLY | O_ਦੁਆਧਾਰੀ_2);
    ਜੇ (fd < 0)
        ਵਾਪਸ -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    ਵਾਪਸ ret;
}

/* ------------------------------------------------------------- */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ pe_ਜੋੜੋ_unwind_info(TCCState *s1)
{
    ਜੇ (ਨਿਰਾ == s1->uw_pdata) {
        s1->uw_pdata = ਲੱਭੋ_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    ਜੇ (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, ਪਾਠ_section->sh_ਅੰਕ, ".uw_base");
    ਜੇ (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ uw_info[] = {
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

        Section *s = ਪਾਠ_section;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *p;

        section_ptr_ਜੋੜੋ(s, -s->ਅੰਕੜੇ_ਵਿੱਥ & 3); /* align */
        s1->uw_offs = s->ਅੰਕੜੇ_ਵਿੱਥ;
        p = section_ptr_ਜੋੜੋ(s, ਆਕਾਰ uw_info);
        ਸਮ੍ਰਿਤੀ_ਨਕਲ(p, uw_info, ਆਕਾਰ uw_info);
    }

    ਵਾਪਸ s1->uw_offs;
}

ST_FUNC ਖਾਲੀ pe_ਜੋੜੋ_unwind_ਅੰਕੜੇ(ਬਿਨਾਨਿਸ਼ਾਨੀ ਸ਼ੁਰੂ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਸਿਰਾ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਢੇਰ)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    ਬਿਨਾਨਿਸ਼ਾਨੀ o, n, d;
    ਬਣਤਰ /* _RUNTIME_FUNCTION */ {
      DWORD Begin_ਪਤਾ;
      DWORD ਸਿਰਾ_ਪਤਾ;
      DWORD Unwind_ਅੰਕੜੇ;
    } *p;

    d = pe_ਜੋੜੋ_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->ਅੰਕੜੇ_ਵਿੱਥ;
    p = section_ptr_ਜੋੜੋ(pd, ਆਕਾਰ *p);

    /* record this function */
    p->Begin_ਪਤਾ = ਸ਼ੁਰੂ;
    p->ਸਿਰਾ_ਪਤਾ = ਸਿਰਾ;
    p->Unwind_ਅੰਕੜੇ = d;

    /* put relocations on it */
    ਲਈ (n = o + ਆਕਾਰ *p; o < n; o += ਆਕਾਰ p->Begin_ਪਤਾ)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
ਸਥਿਰ Section *pe_ਜੋੜੋ_unwind_info(TCCState *s1)
{
    Section *s;

    ਜੇ (ਨਿਰਾ == s1->uw_pdata) {
        s1->uw_pdata = ਲੱਭੋ_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = ਲੱਭੋ_section(s1, ".xdata");
    s->sh_addralign = 4;
    ਜੇ (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  ਪਾਠ_section->sh_ਅੰਕ, ".uw_text_base");
    ਜੇ (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_ਅੰਕ, ".uw_base");
    ਵਾਪਸ s;
}

ST_FUNC ਖਾਲੀ pe_ਜੋੜੋ_unwind_ਅੰਕੜੇ(ਬਿਨਾਨਿਸ਼ਾਨੀ ਸ਼ੁਰੂ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਸਿਰਾ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਢੇਰ)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    ਬਿਨਾਨਿਸ਼ਾਨੀ o, d, ਕੋਡ_ਬਾਈਟਾਂ, func_len;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *q;
    uint32_t ਸਿਰਲੇਖ;
    ਬਣਤਰ /* _RUNTIME_FUNCTION */ {
        DWORD Begin_ਪਤਾ;
        DWORD Unwind_ਅੰਕੜੇ;
    } *p;

    ਪੂਰਨ epilog;

    xd = pe_ਜੋੜੋ_unwind_info(s1);
    pd = s1->uw_pdata;

    func_len = (ਸਿਰਾ - ਸ਼ੁਰੂ) >> 2;
    ਕੋਡ_ਬਾਈਟਾਂ = 0;
    epilog = ਕੋਡ_ਬਾਈਟਾਂ;
    ਕੋਡ_ਬਾਈਟਾਂ += 3; /* set_fp, save_fplr_x, end */
    ਕੋਡ_ਬਾਈਟਾਂ = (ਕੋਡ_ਬਾਈਟਾਂ + 3) & ~3;

    section_ptr_ਜੋੜੋ(xd, -xd->ਅੰਕੜੇ_ਵਿੱਥ & 3);
    d = xd->ਅੰਕੜੇ_ਵਿੱਥ;
    q = section_ptr_ਜੋੜੋ(xd, 4 + ਕੋਡ_ਬਾਈਟਾਂ);

    /* Full ARM64 xdata header: E=1 with one epilog and no exception handler. */
    ਸਿਰਲੇਖ = (func_len & 0x3ffff)
        | 1 << 21
        | (epilog & 0x1F) << 22
        | (ਕੋਡ_ਬਾਈਟਾਂ >> 2) << 27
        ;
    write32le(q, ਸਿਰਲੇਖ);
    q += 4;
    *q++ = 0xE1; /* set_fp */
    *q++ = 0x9B; /* save_fplr_x: stp x29,lr,[sp,#-224]! */
    *q++ = 0xE4; /*ਸਿਰਾ*/
    ਜਦੋਂ ((ਬਿਨਾਨਿਸ਼ਾਨੀ)(q - (xd->ਅੰਕੜੇ + d + 4)) < ਕੋਡ_ਬਾਈਟਾਂ)
        *q++ = 0xE3; /* nop padding */

    o = pd->ਅੰਕੜੇ_ਵਿੱਥ;
    p = section_ptr_ਜੋੜੋ(pd, ਆਕਾਰ *p);
    p->Begin_ਪਤਾ = ਸ਼ੁਰੂ;
    p->Unwind_ਅੰਕੜੇ = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#ਜੇ_ਅੰਤ
/* ------------------------------------------------------------- */
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64) || defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PE_STDSYM(n,s) n
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PE_STDSYM(n,s) "_" n s
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਖਾਲੀ pe_ਜੋੜੋ_runtime(TCCState *s1, ਬਣਤਰ pe_info *pe)
{
    ਅਚਲ ਅੱਖਰ *ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ;
    ਪੂਰਨ pe_type;

    ਜੇ (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ = PE_STDSYM("__dllstart","@12");
    } ਨਹੀਂਤਾਂ {
        ਅਚਲ ਅੱਖਰ *ਲੜੀਵਾਰ_ਚਿੰਨ੍ਹ;
        ਜੇ (ਲੱਭੋ_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ = "__winstart";
            ਲੜੀਵਾਰ_ਚਿੰਨ੍ਹ = "__runwinmain";
            pe_type = PE_GUI;
        } ਨਹੀਂਤਾਂ ਜੇ (ਲੱਭੋ_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ = "__wwinstart";
            ਲੜੀਵਾਰ_ਚਿੰਨ੍ਹ = "__runwwinmain";
            pe_type = PE_GUI;
        } ਨਹੀਂਤਾਂ ਜੇ (ਲੱਭੋ_elf_sym(symtab_section, "wmain")) {
            ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ = "__wstart";
            ਲੜੀਵਾਰ_ਚਿੰਨ੍ਹ = "__runwmain";
            pe_type = PE_EXE;
        } ਨਹੀਂਤਾਂ {
            ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ =  "__start";
            ਲੜੀਵਾਰ_ਚਿੰਨ੍ਹ = "__runmain";
            pe_type = PE_EXE;
            ਜੇ (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        ਜੇ (TCC_OUTPUT_ਸਮ੍ਰਿਤੀ == s1->output_type && !s1->nostdlib)
            ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ = ਲੜੀਵਾਰ_ਚਿੰਨ੍ਹ;
    }
    ਜੇ (s1->elf_entryname) {
        pe->ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ = ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ = s1->elf_entryname;
    } ਨਹੀਂਤਾਂ {
        pe->ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ = ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ + 1;
        ਜੇ (!s1->leading_underscore || strchr(ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ, '@'))
            ++ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ;
    }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
    ਜੇ (s1->do_backtrace) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    ਜੇ (s1->output_type == TCC_OUTPUT_ਸਮ੍ਰਿਤੀ)
                tcc_ਜੋੜੋ_support(s1, "bcheck_run.o");
	    ਨਹੀਂਤਾਂ
                tcc_ਜੋੜੋ_support(s1, "bcheck.o");
	}
#ਜੇ_ਅੰਤ
        ਜੇ (s1->output_type == TCC_OUTPUT_EXE)
            tcc_ਜੋੜੋ_support(s1, "bt-exe.o");
        ਜੇ (s1->output_type == TCC_OUTPUT_DLL)
            tcc_ਜੋੜੋ_support(s1, "bt-dll.o");
        ਜੇ (s1->output_type != TCC_OUTPUT_DLL)
            tcc_ਜੋੜੋ_support(s1, "bt-log.o");
        tcc_ਜੋੜੋ_btstub(s1);
    }
#ਜੇ_ਅੰਤ

    /* grab the startup code from libtcc1.a */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
    ਜੇ (TCC_OUTPUT_ਸਮ੍ਰਿਤੀ != s1->output_type || s1->ਲੜੀਵਾਰ_main)
#ਜੇ_ਅੰਤ
    ਸੈੱਟ_global_sym(s1, ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ, ਨਿਰਾ, 0);

    ਜੇ (0 == s1->nostdlib) {
        ਸਥਿਰ ਅਚਲ ਅੱਖਰ * ਅਚਲ libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", ਨਿਰਾ
        };
        ਅਚਲ ਅੱਖਰ * ਅਚਲ *pp, *p;
        ਜੇ (TCC_LIBTCC1[0])
            tcc_ਜੋੜੋ_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        ਲਈ (pp = libs; 0 != (p = *pp); ++pp) {
            ਜੇ (*p)
                tcc_ਜੋੜੋ_library(s1, p);
            ਨਹੀਂਤਾਂ ਜੇ (PE_DLL != pe_type && PE_GUI != pe_type)
                ਰੋਕੋ;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    ਜੇ (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    ਜੇ (TCC_OUTPUT_ਸਮ੍ਰਿਤੀ == s1->output_type)
        pe_type = PE_ਲੜੀਵਾਰ;
    pe->type = pe_type;
}

ST_FUNC ਪੂਰਨ pe_setsubsy(TCCState *s1, ਅਚਲ ਅੱਖਰ *arg)
{
    ਸਥਿਰ ਅਚਲ ਬਣਤਰ subsy { ਅਚਲ ਅੱਖਰ* p; ਪੂਰਨ v; } x[] = {
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_I386) || defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64) || defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_ARM)
        { "wince", 9 },
#ਜੇ_ਅੰਤ
        { 0, -1 }};
    ਅਚਲ ਬਣਤਰ subsy *y;
    ਲਈ (y = x;; ++y) {
        ਜੇ (!y->p)
            ਵਾਪਸ -1;
        ਜੇ (0 == strcmp(y->p, arg)) {
            s1->pe_subsystem = y->v;
            ਵਾਪਸ 0;
        }
    }
}

ਸਥਿਰ ਖਾਲੀ pe_ਸੈੱਟ_options(TCCState * s1, ਬਣਤਰ pe_info *pe)
{
    ਜੇ (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_ਅਧਾਰ_DLL;
    } ਨਹੀਂਤਾਂ {
        pe->imagebase = IMAGE_ਅਧਾਰ_EXE;
    }

#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#ਨਹੀਂਤਾਂ
    ਜੇ (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    ਨਹੀਂਤਾਂ
        pe->subsystem = 3;
#ਜੇ_ਅੰਤ
    /* Allow override via -Wl,-subsystem=... option */
    ਜੇ (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    ਜੇ (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } ਨਹੀਂਤਾਂ {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    ਜੇ (s1->section_align != 0)
        pe->section_align = s1->section_align;
    ਜੇ (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    ਜੇ ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    ਜੇ (s1->has_ਪਾਠ_addr)
        pe->imagebase = s1->ਪਾਠ_addr;
}

ST_FUNC ਪੂਰਨ pe_output_file(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename)
{
    ਬਣਤਰ pe_info pe;

    memset(&pe, 0, ਆਕਾਰ pe);
    pe.filename = filename;
    pe.s1 = s1;
    s1->filetype = 0;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    tcc_ਜੋੜੋ_bcheck(s1);
#ਜੇ_ਅੰਤ
    tcc_ਜੋੜੋ_pragma_libs(s1);
    pe_ਜੋੜੋ_runtime(s1, &pe);
    resolve_common_syms(s1);
    pe_ਸੈੱਟ_options(s1, &pe);
    pe_check_symbols(&pe);
    ਜੇ (s1->nb_errors)
        ਜਾਓ ਪੂਰਾ;
    ਜੇ (filename) {
        pe_ਸੌਂਪੋ_ਪਤੇ(&pe);
        relocate_syms(s1, s1->symtab, 0);
        ਜੇ (s1->nb_errors)
            ਜਾਓ ਪੂਰਾ;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.ਸ਼ੁਰੂ_addr = (DWORD)
            (get_sym_addr(s1, pe.ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ, 1, 1) - pe.imagebase);
        ਜੇ (s1->nb_errors)
            ਜਾਓ ਪੂਰਾ;
        pe_write(&pe);
    } ਨਹੀਂਤਾਂ {
        /* -run */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
        pe.thunk = ਅੰਕੜੇ_section;
        pe_build_imports(&pe);
        s1->ਲੜੀਵਾਰ_main = pe.ਸ਼ੁਰੂ_ਚਿੰਨ੍ਹ;
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64) || defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64)
        s1->uw_pdata = ਲੱਭੋ_section(s1, ".pdata");
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
    }
ਪੂਰਾ:
    dynarray_reset(&pe.sec_info, &pe.sec_ਗਿਣਤੀ);
    pe_free_imports(&pe);
#ਜੇ PE_PRINT_SECTIONS
    ਜੇ (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#ਜੇ_ਅੰਤ
    ਵਾਪਸ s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
