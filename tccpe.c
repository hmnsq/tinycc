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

#ಅನ್ತರ್ಭಾವ "tcc.h"

#ವ್ಯಾಖ್ಯಾನಿಸು PE_ವಿಲೀನ_ದತ್ತಾಂಶ 1
#ವ್ಯಾಖ್ಯಾನಿಸು PE_PRINT_SECTIONS 0

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
#ವ್ಯಾಖ್ಯಾನಿಸು stricmp strcasecmp
#ವ್ಯಾಖ್ಯಾನಿಸು strnicmp strncasecmp
#ಅನ್ತರ್ಭಾವ <sys/stat.h> /* chmod() */
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined TCC_ಗುರಿ_X86_64
# define REL_TYPE_ನೇರ R_X86_64_64
# define R_XXX_THUNKFIX R_X86_64_PC32
# define R_XXX_RELATIVE R_X86_64_RELATIVE
# define R_XXX_FUNCCALL R_X86_64_PLT32
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0x8664
# define CHARACTERISTICS_EXE 0x022F
# define CHARACTERISTICS_DLL 0x222E
# define IMAGE_ತಳ_EXE 0x00400000
# define IMAGE_ತಳ_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM
# define REL_TYPE_ನೇರ R_ARM_ABS32
# define R_XXX_THUNKFIX R_ARM_ABS32
# define R_XXX_RELATIVE R_ARM_RELATIVE
# define R_XXX_FUNCCALL R_ARM_PC24
# define R_XXX_FUNCCALL2 R_ARM_ABS32
# define RSRC_RELTYPE 7 /* ??? (not tested) */
# define IMAGE_FILE_MACHINE 0x01C0
# define CHARACTERISTICS_EXE 0x010F
# define CHARACTERISTICS_DLL 0x230F
# define IMAGE_ತಳ_EXE 0x00100000
# define IMAGE_ತಳ_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
# define REL_TYPE_ನೇರ R_AARCH64_ABS64
# define R_XXX_THUNKFIX R_AARCH64_ABS64
# define R_XXX_RELATIVE R_AARCH64_RELATIVE
# define R_XXX_FUNCCALL R_AARCH64_CALL26
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0xAA64
# define CHARACTERISTICS_EXE 0x0022
# define CHARACTERISTICS_DLL 0x2022
# define IMAGE_ತಳ_EXE 0x140000000ULL
# define IMAGE_ತಳ_DLL 0x180000000ULL
# define OS_VER 0x0602
# define DLLCHARACTERISTICS 0x8160

#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_I386
# define REL_TYPE_ನೇರ R_386_32
# define R_XXX_THUNKFIX R_386_32
# define R_XXX_RELATIVE R_386_RELATIVE
# define R_XXX_FUNCCALL R_386_PC32
# define RSRC_RELTYPE 7 /* DIR32NB */
# define IMAGE_FILE_MACHINE 0x014C
# define CHARACTERISTICS_EXE 0x030F
# define CHARACTERISTICS_DLL 0x230E
# define IMAGE_ತಳ_EXE 0x00400000
# define IMAGE_ತಳ_DLL 0x10000000
# define OS_VER 0x0400
# define DLLCHARACTERISTICS 0
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ PTR_ಗಾತ್ರ == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#ಇಲ್ಲದಿದ್ದರೆ
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ BYTE;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಶಬ್ದ_3;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ DWORD;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ULONGLONG;
#ಸೂಚನೆ pack(ತಳ್ಳು, 1)

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_DOS_ಶೀರ್ಷಿಕೆ {  /* DOS .EXE header */
    ಶಬ್ದ_3 e_magic;         /* Magic number */
    ಶಬ್ದ_3 e_cblp;          /* Bytes on last page of file */
    ಶಬ್ದ_3 e_cp;            /* Pages in file */
    ಶಬ್ದ_3 e_crlc;          /* Relocations */
    ಶಬ್ದ_3 e_cparhdr;       /* Size of header in paragraphs */
    ಶಬ್ದ_3 e_minalloc;      /* Minimum extra paragraphs needed */
    ಶಬ್ದ_3 e_maxalloc;      /* Maximum extra paragraphs needed */
    ಶಬ್ದ_3 e_ss;            /* Initial (relative) SS value */
    ಶಬ್ದ_3 e_sp;            /* Initial SP value */
    ಶಬ್ದ_3 e_csum;          /* Checksum */
    ಶಬ್ದ_3 e_ip;            /* Initial IP value */
    ಶಬ್ದ_3 e_cs;            /* Initial (relative) CS value */
    ಶಬ್ದ_3 e_lfarlc;        /* File address of relocation table */
    ಶಬ್ದ_3 e_ovno;          /* Overlay number */
    ಶಬ್ದ_3 e_res[4];        /* Reserved words */
    ಶಬ್ದ_3 e_oemid;         /* OEM identifier (for e_oeminfo) */
    ಶಬ್ದ_3 e_oeminfo;       /* OEM information; e_oemid specific */
    ಶಬ್ದ_3 e_res2[10];      /* Reserved words */
    DWORD e_lfanew;        /* File address of new exe header */
} IMAGE_DOS_ಶೀರ್ಷಿಕೆ_2, *PIMAGE_DOS_ಶೀರ್ಷಿಕೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_NT_SIGNATURE  0x00004550  /* PE00 */

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_FILE_ಶೀರ್ಷಿಕೆ {
    ಶಬ್ದ_3    Machine;
    ಶಬ್ದ_3    ಸಂಖ್ಯೆ_ದ_Sections;
    DWORD   ಸಮಯ_Date_Stamp;
    DWORD   ಸೂಚಕ_ಗಮ್ಯ_ಚಿಹ್ನೆ_ಕೋಷ್ಟಕ;
    DWORD   ಸಂಖ್ಯೆ_ದ_Symbols;
    ಶಬ್ದ_3    ಗಾತ್ರ_ದ_Optional_ಶೀರ್ಷಿಕೆ;
    ಶಬ್ದ_3    Characteristics;
} IMAGE_FILE_ಶೀರ್ಷಿಕೆ_2, *PIMAGE_FILE_ಶೀರ್ಷಿಕೆ;


#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_FILE_ಶೀರ್ಷಿಕೆ 20

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_ದತ್ತಾಂಶ_DIRECTORY {
    DWORD   Virtual_ವಿಳಾಸ;
    DWORD   ಗಾತ್ರ_4;
} IMAGE_ದತ್ತಾಂಶ_DIRECTORY_2, *PIMAGE_ದತ್ತಾಂಶ_DIRECTORY;


ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_OPTIONAL_ಶೀರ್ಷಿಕೆ {
    /* Standard fields. */
    ಶಬ್ದ_3    Magic;
    BYTE    Major_Linker_ಆವೃತ್ತಿ;
    BYTE    Minor_Linker_ಆವೃತ್ತಿ;
    DWORD   ಗಾತ್ರ_ದ_ಸಂಕೇತ;
    DWORD   ಗಾತ್ರ_ದ_Initialized_ದತ್ತಾಂಶ;
    DWORD   ಗಾತ್ರ_ದ_Uninitialized_ದತ್ತಾಂಶ;
    DWORD   ವಿಳಾಸ_ದ_ನಮೂದು_ಬಿಂದು;
    DWORD   ತಳ_ದ_ಸಂಕೇತ;
#ಆದರೆ PTR_ಗಾತ್ರ == 4
    DWORD   ತಳ_ದ_ದತ್ತಾಂಶ;
#ಆದರೆ_ಅಂತ್ಯ
    /* NT additional fields. */
    ADDR3264 Image_ತಳ;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    ಶಬ್ದ_3    Major_Operating_System_ಆವೃತ್ತಿ;
    ಶಬ್ದ_3    Minor_Operating_System_ಆವೃತ್ತಿ;
    ಶಬ್ದ_3    Major_Image_ಆವೃತ್ತಿ;
    ಶಬ್ದ_3    Minor_Image_ಆವೃತ್ತಿ;
    ಶಬ್ದ_3    Major_Subsystem_ಆವೃತ್ತಿ;
    ಶಬ್ದ_3    Minor_Subsystem_ಆವೃತ್ತಿ;
    DWORD   Win32_ಆವೃತ್ತಿ_ಮೌಲ್ಯ;
    DWORD   ಗಾತ್ರ_ದ_Image;
    DWORD   ಗಾತ್ರ_ದ_ಶೀರ್ಷಿಕೆಗಳು;
    DWORD   Check_ಮೊತ್ತ;
    ಶಬ್ದ_3    Subsystem;
    ಶಬ್ದ_3    DllCharacteristics;
    ADDR3264 ಗಾತ್ರ_ದ_ರಾಶಿ_Reserve;
    ADDR3264 ಗಾತ್ರ_ದ_ರಾಶಿ_Commit;
    ADDR3264 ಗಾತ್ರ_ದ_ರಾಶಿ_Reserve_2;
    ADDR3264 ಗಾತ್ರ_ದ_ರಾಶಿ_Commit_2;
    DWORD   LoaderFlags;
    DWORD   ಸಂಖ್ಯೆ_ದ_Rva_And_Sizes;
    IMAGE_ದತ್ತಾಂಶ_DIRECTORY_2 ದತ್ತಾಂಶ_Directory[16];
} IMAGE_OPTIONAL_HEADER32, IMAGE_OPTIONAL_HEADER64, IMAGE_OPTIONAL_ಶೀರ್ಷಿಕೆ_2;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_EXPORT          0   /* Export Directory */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_IMPORT          1   /* Import Directory */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_RESOURCE        2   /* Resource Directory */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_EXCEPTION       3   /* Exception Directory */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_SECURITY        4   /* Security Directory */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_BASERELOC       5   /* Base Relocation Table */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_DEBUG           6   /* Debug Directory */
/*      IMAGE_DIRECTORY_ENTRY_COPYRIGHT       7      (X86 usage) */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_ARCHITECTURE    7   /* Architecture Specific Data */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_GLOBALPTR       8   /* RVA of GP */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_TLS             9   /* TLS Directory */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_ತುಂಬು_CONFIG    10   /* Load Configuration Directory */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_BOUND_IMPORT   11   /* Bound Import Directory in headers */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_IAT            12   /* Import Address Table */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_DELAY_IMPORT   13   /* Delay Load Import Descriptors */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_COM_DESCRIPTOR 14   /* COM Runtime descriptor */

/* Section header format. */
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_SHORT_NAME         8

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_SECTION_ಶೀರ್ಷಿಕೆ {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    ಒಕ್ಕೂಟ {
            DWORD   Physical_ವಿಳಾಸ;
            DWORD   Virtual_ಗಾತ್ರ;
    } Misc;
    DWORD   Virtual_ವಿಳಾಸ;
    DWORD   ಗಾತ್ರ_ದ_Raw_ದತ್ತಾಂಶ;
    DWORD   ಸೂಚಕ_ಗಮ್ಯ_Raw_ದತ್ತಾಂಶ;
    DWORD   ಸೂಚಕ_ಗಮ್ಯ_Relocations;
    DWORD   ಸೂಚಕ_ಗಮ್ಯ_Linenumbers;
    ಶಬ್ದ_3    ಸಂಖ್ಯೆ_ದ_Relocations;
    ಶಬ್ದ_3    ಸಂಖ್ಯೆ_ದ_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_ಶೀರ್ಷಿಕೆ_2, *PIMAGE_SECTION_ಶೀರ್ಷಿಕೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_SECTION_ಶೀರ್ಷಿಕೆ     40

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD ಸಮಯ_Date_Stamp;
    ಶಬ್ದ_3 Major_ಆವೃತ್ತಿ;
    ಶಬ್ದ_3 Minor_ಆವೃತ್ತಿ;
    DWORD Name;
    DWORD ತಳ_2;
    DWORD ಸಂಖ್ಯೆ_ದ_Functions;
    DWORD ಸಂಖ್ಯೆ_ದ_ಹೆಸರುಗಳು;
    DWORD ವಿಳಾಸ_ದ_Functions;
    DWORD ವಿಳಾಸ_ದ_ಹೆಸರುಗಳು;
    DWORD ವಿಳಾಸ_ದ_Name_Ordinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_TLS_DIRECTORY {
    ADDR3264 ಆರಂಭ_ವಿಳಾಸ_ದ_Raw_ದತ್ತಾಂಶ;
    ADDR3264 ಕೊನೆ_ವಿಳಾಸ_ದ_Raw_ದತ್ತಾಂಶ;
    ADDR3264 ವಿಳಾಸ_ದ_ಸೂಚ್ಯಂಕ;
    ADDR3264 ವಿಳಾಸ_ದ_Call_Backs;
    DWORD ಗಾತ್ರ_ದ_Zero_Fill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_IMPORT_DESCRIPTOR {
    ಒಕ್ಕೂಟ {
        DWORD Characteristics;
        DWORD Original_ಮೊದಲ_Thunk;
    };
    DWORD ಸಮಯ_Date_Stamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD ಮೊದಲ_Thunk;
} IMAGE_IMPORT_DESCRIPTOR;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_ತಳ_RELOCATION {
    DWORD   Virtual_ವಿಳಾಸ;
    DWORD   ಗಾತ್ರ_ದ_ಖಂಡ;
//  WORD    TypeOffset[1];
} IMAGE_ತಳ_RELOCATION_2;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_ತಳ_RELOCATION     8

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_ABSOLUTE         0
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_ಮೇಲಿನ             1
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_ಕೆಳಗಿನ              2
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_HIGHLOW          3
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_HIGHADJ          4
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_MIPS_JMPADDR     5
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_SECTION          6
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_REL32            7
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_DIR64           10

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_CNT_ಸಂಕೇತ                  0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_CNT_INITIALIZED_ದತ್ತಾಂಶ      0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_CNT_UNINITIALIZED_ದತ್ತಾಂಶ    0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_DISCARDABLE           0x02000000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_SHARED                0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_EXECUTE               0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_READ                  0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_WRITE                 0x80000000

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_ಮೇಲಿನ_ENTROPY_VA 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_DYNAMIC_ತಳ 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_RELOCS_STRIPPED 0x0001

#ಸೂಚನೆ pack(ತೆಗೆ)

/* ----------------------------------------------------------- */
#ಆದರೆ_ಅಂತ್ಯ /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ IMAGE_DLLCHARACTERISTICS_DYNAMIC_ತಳ
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_DYNAMIC_ತಳ 0x0040
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತಳ್ಳು, 1)
ರಚನೆ pe_ಶೀರ್ಷಿಕೆ
{
    IMAGE_DOS_ಶೀರ್ಷಿಕೆ_2 doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_ಶೀರ್ಷಿಕೆ_2 filehdr;
#ಆದರೆ PTR_ಗಾತ್ರ == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#ಇಲ್ಲದಿದ್ದರೆ
    IMAGE_OPTIONAL_ಶೀರ್ಷಿಕೆ_2 opthdr;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
};

ರಚನೆ pe_reloc_ಶೀರ್ಷಿಕೆ {
    DWORD ಸ್ಥಾನಾಂತರ;
    DWORD ಗಾತ್ರ_2;
};

ರಚನೆ pe_rsrc_ಶೀರ್ಷಿಕೆ {
    ರಚನೆ IMAGE_FILE_ಶೀರ್ಷಿಕೆ filehdr;
    ರಚನೆ IMAGE_SECTION_ಶೀರ್ಷಿಕೆ sectionhdr;
};

ರಚನೆ pe_rsrc_reloc {
    DWORD ಸ್ಥಾನಾಂತರ;
    DWORD ಗಾತ್ರ_2;
    ಶಬ್ದ_3 type;
};
#ಸೂಚನೆ pack(ತೆಗೆ)

/* ------------------------------------------------------------- */
/* internal temporary structures */

ಎಣಿಕೆ {
    sec_ಪಠ್ಯ = 0,
    sec_rdata ,
    sec_ದತ್ತಾಂಶ ,
    sec_bss ,
    sec_idata ,
    sec_pdata ,
    sec_tdata ,
    sec_tbss ,
    sec_other ,
    sec_rsrc ,
    sec_debug ,
    sec_reloc ,
    sec_ಕೊನೆಯ
};

#ಆದರೆ 0
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ DWORD pe_sec_flags[] = {
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
#ಆದರೆ_ಅಂತ್ಯ

ರಚನೆ section_info {
    ಪೂರ್ಣಾಂಕ cls;
    ಅಕ್ಷರ name[32];
    ADDR3264 sh_addr;
    DWORD sh_ಗಾತ್ರ;
    DWORD pe_flags;
    Section *sec;
    DWORD ದತ್ತಾಂಶ_ಗಾತ್ರ;
    IMAGE_SECTION_ಶೀರ್ಷಿಕೆ_2 ish;
};

ರಚನೆ import_ಚಿಹ್ನೆ {
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ;
    ಪೂರ್ಣಾಂಕ iat_ಸೂಚ್ಯಂಕ;
    ಪೂರ್ಣಾಂಕ thk_ಸ್ಥಾನಾಂತರ;
};

ರಚನೆ pe_import_info {
    ಪೂರ್ಣಾಂಕ dll_ಸೂಚ್ಯಂಕ;
    ಪೂರ್ಣಾಂಕ sym_ಎಣಿಕೆ;
    ರಚನೆ import_ಚಿಹ್ನೆ **symbols;
};

ರಚನೆ pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename;
    ಪೂರ್ಣಾಂಕ type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಆರಂಭ_ಚಿಹ್ನೆ;
    DWORD ಆರಂಭ_addr;
    DWORD imp_offs;
    DWORD imp_ಗಾತ್ರ;
    DWORD iat_offs;
    DWORD iat_ಗಾತ್ರ;
    DWORD exp_offs;
    DWORD exp_ಗಾತ್ರ;
    DWORD tls_dir;
    DWORD tls_ದತ್ತಾಂಶ;
    DWORD tls_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ subsystem;
    DWORD section_align;
    DWORD file_align;
    ರಚನೆ section_info **sec_info;
    ಪೂರ್ಣಾಂಕ sec_ಎಣಿಕೆ;
    ರಚನೆ pe_import_info **imp_info;
    ಪೂರ್ಣಾಂಕ imp_ಎಣಿಕೆ;
    /* output */
    FILE *op;
    DWORD ಮೊತ್ತ;
    ಚಿಹ್ನೆರಹಿತ pos;
};

#ವ್ಯಾಖ್ಯಾನಿಸು PE_NUL 0
#ವ್ಯಾಖ್ಯಾನಿಸು PE_DLL 1
#ವ್ಯಾಖ್ಯಾನಿಸು PE_GUI 2
#ವ್ಯಾಖ್ಯಾನಿಸು PE_EXE 3
#ವ್ಯಾಖ್ಯಾನಿಸು PE_ಸತತ 4

/* --------------------------------------------*/

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = (ಅಕ್ಷರ*)symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
    ಆದರೆ (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        ಹಿಂತಿರುಗಿ name + 1;
    ಹಿಂತಿರುಗಿ name;
}


ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ dynarray_assoc(ಶೂನ್ಯ **pp, ಪೂರ್ಣಾಂಕ n, ಪೂರ್ಣಾಂಕ ಕೀಲಿ)
{
    ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ (i = 0; i < n; ++i, ++pp)
    ಆದರೆ (ಕೀಲಿ == **(ಪೂರ್ಣಾಂಕ **) pp)
        ಹಿಂತಿರುಗಿ i;
    ಹಿಂತಿರುಗಿ -1;
}

ಸ್ಥಿರ DWORD umin(DWORD a, DWORD b)
{
    ಹಿಂತಿರುಗಿ a < b ? a : b;
}

ಸ್ಥಿರ DWORD umax(DWORD a, DWORD b)
{
    ಹಿಂತಿರುಗಿ a < b ? b : a;
}

ಸ್ಥಿರ DWORD pe_file_align(ರಚನೆ pe_info *pe, DWORD n)
{
    ಹಿಂತಿರುಗಿ (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

ಸ್ಥಿರ ADDR3264 pe_virtual_align(ರಚನೆ pe_info *pe, ADDR3264 n)
{
    ಹಿಂತಿರುಗಿ (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

ಸ್ಥಿರ ಶೂನ್ಯ pe_align_section(Section *s, ಪೂರ್ಣಾಂಕ a)
{
    ಪೂರ್ಣಾಂಕ i = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ & (a-1);
    ಆದರೆ (i)
        section_ptr_ಕೂಡಿಸು(s, a - i);
}

ಸ್ಥಿರ ಶೂನ್ಯ pe_ಗಣ_datadir(ರಚನೆ pe_ಶೀರ್ಷಿಕೆ *hdr, ಪೂರ್ಣಾಂಕ dir, DWORD addr, DWORD ಗಾತ್ರ_2)
{
    hdr->opthdr.ದತ್ತಾಂಶ_Directory[dir].Virtual_ವಿಳಾಸ = addr;
    hdr->opthdr.ದತ್ತಾಂಶ_Directory[dir].ಗಾತ್ರ_4 = ಗಾತ್ರ_2;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pe_fwrite(ರಚನೆ pe_info *pe, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *ದತ್ತಾಂಶ, ಪೂರ್ಣಾಂಕ len)
{
    ಸ್ಥಿರಾಂಕ ಶಬ್ದ_3 *p = ದತ್ತಾಂಶ;
    DWORD ಮೊತ್ತ;
    ಪೂರ್ಣಾಂಕ ret, i;
    pe->pos += (ret = fwrite(ದತ್ತಾಂಶ, 1, len, pe->op));
    ಮೊತ್ತ = pe->ಮೊತ್ತ;
    ಗಾಗಿ (i = len; i > 0; i -= 2) {
        ಮೊತ್ತ += (i >= 2) ? *p++ : *(BYTE*)p;
        ಮೊತ್ತ = (ಮೊತ್ತ + (ಮೊತ್ತ >> 16)) & 0xFFFF;
    }
    pe->ಮೊತ್ತ = ಮೊತ್ತ;
    ಹಿಂತಿರುಗಿ len == ret ? 0 : -1;
}

ಸ್ಥಿರ ಶೂನ್ಯ pe_fpad(ರಚನೆ pe_info *pe, DWORD new_pos)
{
    ಅಕ್ಷರ buf[256];
    ಪೂರ್ಣಾಂಕ n, diff = new_pos - pe->pos;
    memset(buf, 0, ಗಾತ್ರ buf);
    ಆಗ (diff > 0) {
        diff -= n = umin(diff, ಗಾತ್ರ buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#ಸೂಚನೆ pack(ತಳ್ಳು, 1)
ರಚನೆ syment
{
    ಒಕ್ಕೂಟ {
        ಅಕ್ಷರ        n_name[8];     /* old COFF version */
        ರಚನೆ {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_ಸ್ಥಾನಾಂತರ_2;      /* offset into string table */
        };
    };
    int32_t         n_ಮೌಲ್ಯ;        /* value of symbol */
    ಗಿಡ್ಡ           n_scnum;        /* section number */
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  n_type;         /* type and derived type */
    ಅಕ್ಷರ            n_sclass;       /* storage class */
    ಅಕ್ಷರ            n_numaux;       /* number of aux. entries */
};
#ಸೂಚನೆ pack(ತೆಗೆ)

#ವ್ಯಾಖ್ಯಾನಿಸು SHF_ಖಾಸಗಿ 0x80000000

ಸ್ಥಿರ ಶೂನ್ಯ pe_ಕೂಡಿಸು_coffsym(ರಚನೆ pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    ರಚನೆ syment *se;
    ಪೂರ್ಣಾಂಕ n;

    ಆದರೆ (ಖಾಲಿ == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_ಖಾಸಗಿ);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_ಖಾಸಗಿ);
        section_ptr_ಕೂಡಿಸು(pe->coffstr, 4); /* coff string table size */
        ಹಿಂತಿರುಗಿ;
    }

#ಆದರೆ 0
    se = section_ptr_ಕೂಡಿಸು(pe->coffsym, ಗಾತ್ರ *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_ಕೂಡಿಸು(pe->coffsym, ಗಾತ್ರ *se);
    strcpy((ಅಕ್ಷರ*)se, "no-file");
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ 1
    esym = (ElfSym*)s1->symtab->ದತ್ತಾಂಶ;
    ಗಾಗಿ (n = s1->symtab->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ *esym; ++esym, --n;) {
        ಪೂರ್ಣಾಂಕ sym_bind = ELFW(ST_BIND)(esym->st_info);
        ಆದರೆ (sym_bind == STB_GLOBAL) {
            ಅಕ್ಷರ *name = esym->st_name + (ಅಕ್ಷರ*)s1->symtab->link->ದತ್ತಾಂಶ;
            ಪೂರ್ಣಾಂಕ nl = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name);
            addr_t ಮೌಲ್ಯ = esym->st_ಮೌಲ್ಯ;
            ಪೂರ್ಣಾಂಕ shnum = esym->st_shndx;
            ಆದರೆ (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                ಮೌಲ್ಯ = ಮೌಲ್ಯ - s->sh_addr;
            }
            se = section_ptr_ಕೂಡಿಸು(pe->coffsym, ಗಾತ್ರ *se);
            se->n_ಮೌಲ್ಯ = ಮೌಲ್ಯ;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            ಆದರೆ (nl <= 8)
                ಸ್ಮರಣೆ_ನಕಲು(se->n_name, name, nl);
            ಇಲ್ಲದಿದ್ದರೆ
                se->n_ಸ್ಥಾನಾಂತರ_2 = put_elf_str(pe->coffstr, name);
        }
    }
#ಆದರೆ_ಅಂತ್ಯ
    write32le(pe->coffstr->ದತ್ತಾಂಶ, pe->coffstr->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
ಸ್ಥಿರ ಶೂನ್ಯ pe_create_pdb(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *exename)
{
    ಅಕ್ಷರ buf[300]; ಪೂರ್ಣಾಂಕ r;
    snprintf(buf, ಗಾತ್ರ buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    strcpy(tcc_fileextension(strcpy(buf, exename)), ".pdb");
    ಆದರೆ (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s1->verbose) {
        ಬರೆ("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pe_write(ರಚನೆ pe_info *pe)
{
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ರಚನೆ pe_ಶೀರ್ಷಿಕೆ pe_template = {
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
    0x00E0 + (PTR_ಗಾತ್ರ-4)*4, /*WORD    SizeOfOptionalHeader; */
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
#ಆದರೆ PTR_ಗಾತ್ರ == 4
    0x00000000, /*DWORD   BaseOfData; */
#ಆದರೆ_ಅಂತ್ಯ
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

    ರಚನೆ pe_ಶೀರ್ಷಿಕೆ pe_ಶೀರ್ಷಿಕೆ = pe_template;

    ಪೂರ್ಣಾಂಕ i;
    DWORD file_ಸ್ಥಾನಾಂತರ;
    ರಚನೆ section_info *si;
    IMAGE_SECTION_ಶೀರ್ಷಿಕೆ_2 *psh;
    TCCState *s1 = pe->s1;

    ಆದರೆ (s1->do_debug)
        pe_ಕೂಡಿಸು_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    ಆದರೆ (ಖಾಲಿ == pe->op)
        ಹಿಂತಿರುಗಿ tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        ಗಾತ್ರ (ರಚನೆ pe_ಶೀರ್ಷಿಕೆ)
        + pe->sec_ಎಣಿಕೆ * ಗಾತ್ರ (IMAGE_SECTION_ಶೀರ್ಷಿಕೆ_2)
        );

    file_ಸ್ಥಾನಾಂತರ = pe->sizeofheaders;

    ಆದರೆ (2 == s1->verbose)
        ಬರೆ("-------------------------------"
               "\n  virt   file   size  section" "\n");
    ಗಾಗಿ (i = 0; i < pe->sec_ಎಣಿಕೆ; ++i) {
        DWORD addr, ಗಾತ್ರ_2;
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        ಗಾತ್ರ_2 = si->sh_ಗಾತ್ರ;
        psh = &si->ish;

        ಆದರೆ (2 == s1->verbose)
            ಬರೆ("%6x %6x %6x  %s\n",
                (ಚಿಹ್ನೆರಹಿತ)addr, (ಚಿಹ್ನೆರಹಿತ)file_ಸ್ಥಾನಾಂತರ, (ಚಿಹ್ನೆರಹಿತ)ಗಾತ್ರ_2, sh_name);

        ಆಯ್ಕೆ (si->cls) {
            ಸ್ಥಿತಿ sec_ಪಠ್ಯ:
                ಆದರೆ (!pe_ಶೀರ್ಷಿಕೆ.opthdr.ತಳ_ದ_ಸಂಕೇತ)
                    pe_ಶೀರ್ಷಿಕೆ.opthdr.ತಳ_ದ_ಸಂಕೇತ = addr;
                ನಿಲ್ಲಿಸು;

            ಸ್ಥಿತಿ sec_ದತ್ತಾಂಶ:
#ಆದರೆ PTR_ಗಾತ್ರ == 4
                ಆದರೆ (!pe_ಶೀರ್ಷಿಕೆ.opthdr.ತಳ_ದ_ದತ್ತಾಂಶ)
                    pe_ಶೀರ್ಷಿಕೆ.opthdr.ತಳ_ದ_ದತ್ತಾಂಶ = addr;
#ಆದರೆ_ಅಂತ್ಯ
                ನಿಲ್ಲಿಸು;

            ಸ್ಥಿತಿ sec_bss:
                ನಿಲ್ಲಿಸು;

            ಸ್ಥಿತಿ sec_reloc:
                pe_ಗಣ_datadir(&pe_ಶೀರ್ಷಿಕೆ, IMAGE_DIRECTORY_ನಮೂದು_BASERELOC, addr, ಗಾತ್ರ_2);
                ನಿಲ್ಲಿಸು;

            ಸ್ಥಿತಿ sec_rsrc:
                pe_ಗಣ_datadir(&pe_ಶೀರ್ಷಿಕೆ, IMAGE_DIRECTORY_ನಮೂದು_RESOURCE, addr, ಗಾತ್ರ_2);
                ನಿಲ್ಲಿಸು;

            ಸ್ಥಿತಿ sec_pdata:
                pe_ಗಣ_datadir(&pe_ಶೀರ್ಷಿಕೆ, IMAGE_DIRECTORY_ನಮೂದು_EXCEPTION, addr, ಗಾತ್ರ_2);
                ನಿಲ್ಲಿಸು;
        }

        ಆದರೆ (pe->imp_ಗಾತ್ರ) {
            pe_ಗಣ_datadir(&pe_ಶೀರ್ಷಿಕೆ, IMAGE_DIRECTORY_ನಮೂದು_IMPORT,
                pe->imp_offs, pe->imp_ಗಾತ್ರ);
            pe_ಗಣ_datadir(&pe_ಶೀರ್ಷಿಕೆ, IMAGE_DIRECTORY_ನಮೂದು_IAT,
                pe->iat_offs, pe->iat_ಗಾತ್ರ);
        }
        ಆದರೆ (pe->exp_ಗಾತ್ರ) {
            pe_ಗಣ_datadir(&pe_ಶೀರ್ಷಿಕೆ, IMAGE_DIRECTORY_ನಮೂದು_EXPORT,
                pe->exp_offs, pe->exp_ಗಾತ್ರ);
        }
        ಆದರೆ (pe->tls_ಗಾತ್ರ) {
            pe_ಗಣ_datadir(&pe_ಶೀರ್ಷಿಕೆ, IMAGE_DIRECTORY_ನಮೂದು_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_ಗಾತ್ರ);
        }

        ಸ್ಮರಣೆ_ನಕಲು(psh->Name, sh_name, umin(ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(sh_name), ಗಾತ್ರ psh->Name));
        ಆದರೆ (pe->coffstr && ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((ಅಕ್ಷರ*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->Virtual_ವಿಳಾಸ = addr;
        psh->Misc.Virtual_ಗಾತ್ರ = ಗಾತ್ರ_2;
        pe_ಶೀರ್ಷಿಕೆ.opthdr.ಗಾತ್ರ_ದ_Image =
            umax(pe_virtual_align(pe, ಗಾತ್ರ_2 + addr), pe_ಶೀರ್ಷಿಕೆ.opthdr.ಗಾತ್ರ_ದ_Image);

        ಆದರೆ (si->ದತ್ತಾಂಶ_ಗಾತ್ರ) {
            psh->ಸೂಚಕ_ಗಮ್ಯ_Raw_ದತ್ತಾಂಶ = file_ಸ್ಥಾನಾಂತರ;
            file_ಸ್ಥಾನಾಂತರ = pe_file_align(pe, file_ಸ್ಥಾನಾಂತರ + si->ದತ್ತಾಂಶ_ಗಾತ್ರ);
            psh->ಗಾತ್ರ_ದ_Raw_ದತ್ತಾಂಶ = file_ಸ್ಥಾನಾಂತರ - psh->ಸೂಚಕ_ಗಮ್ಯ_Raw_ದತ್ತಾಂಶ;
            ಆದರೆ (si->cls == sec_ಪಠ್ಯ)
                pe_ಶೀರ್ಷಿಕೆ.opthdr.ಗಾತ್ರ_ದ_ಸಂಕೇತ += psh->ಗಾತ್ರ_ದ_Raw_ದತ್ತಾಂಶ;
            ಇಲ್ಲದಿದ್ದರೆ
                pe_ಶೀರ್ಷಿಕೆ.opthdr.ಗಾತ್ರ_ದ_Initialized_ದತ್ತಾಂಶ += psh->ಗಾತ್ರ_ದ_Raw_ದತ್ತಾಂಶ;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_ಶೀರ್ಷಿಕೆ.filehdr.ಸಂಖ್ಯೆ_ದ_Sections = pe->sec_ಎಣಿಕೆ;
    pe_ಶೀರ್ಷಿಕೆ.opthdr.ವಿಳಾಸ_ದ_ನಮೂದು_ಬಿಂದು = pe->ಆರಂಭ_addr;
    pe_ಶೀರ್ಷಿಕೆ.opthdr.ಗಾತ್ರ_ದ_ಶೀರ್ಷಿಕೆಗಳು = pe->sizeofheaders;
    pe_ಶೀರ್ಷಿಕೆ.opthdr.Image_ತಳ = pe->imagebase;
    pe_ಶೀರ್ಷಿಕೆ.opthdr.Subsystem = pe->subsystem;
    pe_ಶೀರ್ಷಿಕೆ.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    ಆದರೆ (s1->pe_ರಾಶಿ_ಗಾತ್ರ)
        pe_ಶೀರ್ಷಿಕೆ.opthdr.ಗಾತ್ರ_ದ_ರಾಶಿ_Reserve = s1->pe_ರಾಶಿ_ಗಾತ್ರ;
    ಆದರೆ (PE_DLL == pe->type)
        pe_ಶೀರ್ಷಿಕೆ.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_ಶೀರ್ಷಿಕೆ.filehdr.Characteristics |= s1->pe_characteristics;
    ಆದರೆ (pe->reloc)
        pe_ಶೀರ್ಷಿಕೆ.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    ಆದರೆ (pe->coffsym) {
        pe_ಕೂಡಿಸು_coffsym(pe);
        pe_ಶೀರ್ಷಿಕೆ.filehdr.ಸೂಚಕ_ಗಮ್ಯ_ಚಿಹ್ನೆ_ಕೋಷ್ಟಕ = file_ಸ್ಥಾನಾಂತರ;
        pe_ಶೀರ್ಷಿಕೆ.filehdr.ಸಂಖ್ಯೆ_ದ_Symbols
            = pe->coffsym->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ (ರಚನೆ syment);
    }

    pe_fwrite(pe, &pe_ಶೀರ್ಷಿಕೆ, ಗಾತ್ರ pe_ಶೀರ್ಷಿಕೆ);
    ಗಾಗಿ (i = 0; i < pe->sec_ಎಣಿಕೆ; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, ಗಾತ್ರ(IMAGE_SECTION_ಶೀರ್ಷಿಕೆ_2));

    file_ಸ್ಥಾನಾಂತರ = pe->sizeofheaders;
    ಗಾಗಿ (i = 0; i < pe->sec_ಎಣಿಕೆ; ++i) {
        Section *s;
        si = pe->sec_info[i];
        ಆದರೆ (!si->ದತ್ತಾಂಶ_ಗಾತ್ರ)
            ಮುಂದುವರಿ;
        ಗಾಗಿ (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_ಸ್ಥಾನಾಂತರ);
            pe_fwrite(pe, s->ದತ್ತಾಂಶ, s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
            ಆದರೆ (s->prev)
                file_ಸ್ಥಾನಾಂತರ += s->prev->sh_addr - s->sh_addr;
        }
        file_ಸ್ಥಾನಾಂತರ = si->ish.ಸೂಚಕ_ಗಮ್ಯ_Raw_ದತ್ತಾಂಶ + si->ish.ಗಾತ್ರ_ದ_Raw_ದತ್ತಾಂಶ;
        pe_fpad(pe, file_ಸ್ಥಾನಾಂತರ);
    }

    ಆದರೆ (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->ದತ್ತಾಂಶ, pe->coffsym->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
        pe_fwrite(pe, pe->coffstr->ದತ್ತಾಂಶ, pe->coffstr->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
        file_ಸ್ಥಾನಾಂತರ = pe->pos;
    }

    pe->ಮೊತ್ತ += file_ಸ್ಥಾನಾಂತರ;
    fseek(pe->op, offsetof(ರಚನೆ pe_ಶೀರ್ಷಿಕೆ, opthdr.Check_ಮೊತ್ತ), SEEK_SET);
    pe_fwrite(pe, &pe->ಮೊತ್ತ, ಗಾತ್ರ (DWORD));

    fclose (pe->op);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
    chmod(pe->filename, 0777);
#ಆದರೆ_ಅಂತ್ಯ

    ಆದರೆ (2 == s1->verbose)
        ಬರೆ("-------------------------------\n");
    ಆದರೆ (s1->verbose)
        ಬರೆ("<- %s (%u bytes)\n", pe->filename, (ಚಿಹ್ನೆರಹಿತ)file_ಸ್ಥಾನಾಂತರ);

    ಆದರೆ (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    ಹಿಂತಿರುಗಿ 0;
}

/*----------------------------------------------------------------------------*/

ಸ್ಥಿರ ರಚನೆ import_ಚಿಹ್ನೆ *pe_ಕೂಡಿಸು_import(ರಚನೆ pe_info *pe, ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ)
{
    ಪೂರ್ಣಾಂಕ i;
    ಪೂರ್ಣಾಂಕ dll_ಸೂಚ್ಯಂಕ;
    ರಚನೆ pe_import_info *p;
    ರಚನೆ import_ಚಿಹ್ನೆ *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->ದತ್ತಾಂಶ + sym_ಸೂಚ್ಯಂಕ;
    dll_ಸೂಚ್ಯಂಕ = isym->st_ಗಾತ್ರ;

    i = dynarray_assoc ((ಶೂನ್ಯ**)pe->imp_info, pe->imp_ಎಣಿಕೆ, dll_ಸೂಚ್ಯಂಕ);
    ಆದರೆ (-1 != i) {
        p = pe->imp_info[i];
        ಹೋಗು ಸಿಕ್ಕಿತು_dll;
    }
    p = tcc_mallocz(ಗಾತ್ರ *p);
    p->dll_ಸೂಚ್ಯಂಕ = dll_ಸೂಚ್ಯಂಕ;
    dynarray_ಕೂಡಿಸು(&pe->imp_info, &pe->imp_ಎಣಿಕೆ, p);

ಸಿಕ್ಕಿತು_dll:
    i = dynarray_assoc ((ಶೂನ್ಯ**)p->symbols, p->sym_ಎಣಿಕೆ, sym_ಸೂಚ್ಯಂಕ);
    ಆದರೆ (-1 != i)
        ಹಿಂತಿರುಗಿ p->symbols[i];

    s = tcc_mallocz(ಗಾತ್ರ *s);
    dynarray_ಕೂಡಿಸು(&p->symbols, &p->sym_ಎಣಿಕೆ, s);
    s->sym_ಸೂಚ್ಯಂಕ = sym_ಸೂಚ್ಯಂಕ;
    ಹಿಂತಿರುಗಿ s;
}

ಸ್ಥಿರ ಶೂನ್ಯ pe_free_imports(ರಚನೆ pe_info *pe)
{
    ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ (i = 0; i < pe->imp_ಎಣಿಕೆ; ++i) {
        ರಚನೆ pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_ಎಣಿಕೆ);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_ಎಣಿಕೆ);
}

/*----------------------------------------------------------------------------*/
ಸ್ಥಿರ ಶೂನ್ಯ pe_build_imports(ರಚನೆ pe_info *pe)
{
    ಪೂರ್ಣಾಂಕ thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_ತಳ = pe->thunk->sh_addr - pe->imagebase;
    ಪೂರ್ಣಾಂಕ ndlls = pe->imp_ಎಣಿಕೆ;
    TCCState *s1 = pe->s1;

    ಗಾಗಿ (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_ಎಣಿಕೆ;

    ಆದರೆ (0 == sym_cnt)
        ಹಿಂತಿರುಗಿ;

    pe_align_section(pe->thunk, 16);
    pe->imp_ಗಾತ್ರ = (ndlls + 1) * ಗಾತ್ರ(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_ಗಾತ್ರ = (sym_cnt + ndlls) * ಗಾತ್ರ(ADDR3264);
    dll_ptr = pe->thunk->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    thk_ptr = dll_ptr + pe->imp_ಗಾತ್ರ;
    ent_ptr = thk_ptr + pe->iat_ಗಾತ್ರ;
    pe->imp_offs = dll_ptr + rva_ತಳ;
    pe->iat_offs = thk_ptr + rva_ತಳ;
    section_ptr_ಕೂಡಿಸು(pe->thunk, pe->imp_ಗಾತ್ರ + 2*pe->iat_ಗಾತ್ರ);

    ಗಾಗಿ (i = 0; i < pe->imp_ಎಣಿಕೆ; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        ಪೂರ್ಣಾಂಕ k, n, dllindex;
        ADDR3264 v;
        ರಚನೆ pe_import_info *p = pe->imp_info[i];
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
        DLLReference *dllref;

        dllindex = p->dll_ಸೂಚ್ಯಂಕ;
        ಆದರೆ (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        ಇಲ್ಲದಿದ್ದರೆ
            name = "", dllref = ಖಾಲಿ;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->ದತ್ತಾಂಶ + dll_ptr);
        hdr->ಮೊದಲ_Thunk = thk_ptr + rva_ತಳ;
        hdr->Original_ಮೊದಲ_Thunk = ent_ptr + rva_ತಳ;
        hdr->Name = v + rva_ತಳ;

        ಗಾಗಿ (k = 0, n = p->sym_ಎಣಿಕೆ; k <= n; ++k) {
            ಆದರೆ (k < n) {
                ಪೂರ್ಣಾಂಕ iat_ಸೂಚ್ಯಂಕ = p->symbols[k]->iat_ಸೂಚ್ಯಂಕ;
                ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ = p->symbols[k]->sym_ಸೂಚ್ಯಂಕ;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->ದತ್ತಾಂಶ + sym_ಸೂಚ್ಯಂಕ;
                ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = (ಅಕ್ಷರ*)s1->dynsymtab_section->link->ದತ್ತಾಂಶ + imp_sym->st_name;
                ಪೂರ್ಣಾಂಕ ordinal;

                /* patch symbol (and possibly its underscored alias) */
                ಮಾಡು {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ + iat_ಸೂಚ್ಯಂಕ;
                    iat_ಸೂಚ್ಯಂಕ = esym->st_ಮೌಲ್ಯ;
                    esym->st_ಮೌಲ್ಯ = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_ಅಂಕೆ;
                } ಆಗ (iat_ಸೂಚ್ಯಂಕ);

                ಆದರೆ (dllref)
                    v = 0, ordinal = imp_sym->st_ಮೌಲ್ಯ; /* ordinal from pe_load_def */
                ಇಲ್ಲದಿದ್ದರೆ
                    ordinal = 0, v = imp_sym->st_ಮೌಲ್ಯ; /* address from tcc_add_symbol() */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
                ಆದರೆ (pe->type == PE_ಸತತ) {
                    ಆದರೆ (dllref) {
                        ಆದರೆ ( !dllref->handle )
                            dllref->handle = ತುಂಬು_Library_A(dllref->name);
                        v = (ADDR3264)Get_Proc_ವಿಳಾಸ(dllref->handle, ordinal?(ಅಕ್ಷರ*)0+ordinal:name);
                    }
                    ಆದರೆ (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
                ಆದರೆ (ordinal) {
                    v = ordinal | (ADDR3264)1 << (ಗಾತ್ರ(ADDR3264)*8 - 1);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    v = pe->thunk->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ + rva_ತಳ;
                    section_ptr_ಕೂಡಿಸು(pe->thunk, ಗಾತ್ರ(ಶಬ್ದ_3)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } ಇಲ್ಲದಿದ್ದರೆ {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->ದತ್ತಾಂಶ+thk_ptr) =
            *(ADDR3264*)(pe->thunk->ದತ್ತಾಂಶ+ent_ptr) = v;
            thk_ptr += ಗಾತ್ರ (ADDR3264);
            ent_ptr += ಗಾತ್ರ (ADDR3264);
        }
        dll_ptr += ಗಾತ್ರ(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

ರಚನೆ pe_ವಿಂಗಡಿಸು_sym
{
    ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
};

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ sym_cmp(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *va, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *vb)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ca = (*(ರಚನೆ pe_ವಿಂಗಡಿಸು_sym**)va)->name;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *cb = (*(ರಚನೆ pe_ವಿಂಗಡಿಸು_sym**)vb)->name;
    ಹಿಂತಿರುಗಿ strcmp(ca, cb);
}

ಸ್ಥಿರ ಶೂನ್ಯ pe_build_exports(ರಚನೆ pe_info *pe)
{
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ, sym_ಕೊನೆ;
    DWORD rva_ತಳ, ತಳ_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    ಪೂರ್ಣಾಂಕ sym_ಎಣಿಕೆ, ord;
    ರಚನೆ pe_ವಿಂಗಡಿಸು_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    ಅಕ್ಷರ buf[260];
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *dllname;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;

    rva_ತಳ = pe->thunk->sh_addr - pe->imagebase;
    sym_ಎಣಿಕೆ = 0, sorted = ಖಾಲಿ, op = ಖಾಲಿ;

    sym_ಕೊನೆ = symtab_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ(ElfW(Sym));
    ಗಾಗಿ (sym_ಸೂಚ್ಯಂಕ = 1; sym_ಸೂಚ್ಯಂಕ < sym_ಕೊನೆ; ++sym_ಸೂಚ್ಯಂಕ) {
        sym = (ElfW(Sym)*)symtab_section->ದತ್ತಾಂಶ + sym_ಸೂಚ್ಯಂಕ;
        name = pe_export_name(s1, sym);
        ಆದರೆ (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(ಗಾತ್ರ *p);
            p->ಸೂಚ್ಯಂಕ = sym_ಸೂಚ್ಯಂಕ;
            p->name = name;
            dynarray_ಕೂಡಿಸು(&sorted, &sym_ಎಣಿಕೆ, p);
        }
#ಆದರೆ 0
        ಆದರೆ (sym->st_other & ST_PE_EXPORT)
            ಬರೆ("export: %s\n", name);
        ಆದರೆ (sym->st_other & ST_PE_STDCALL)
            ಬರೆ("stdcall: %s\n", name);
#ಆದರೆ_ಅಂತ್ಯ
    }

    ಆದರೆ (0 == sym_ಎಣಿಕೆ)
        ಹಿಂತಿರುಗಿ;

    qsort (sorted, sym_ಎಣಿಕೆ, ಗಾತ್ರ *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    ತಳ_o = pe->thunk->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    func_o = ತಳ_o + ಗಾತ್ರ(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_ಎಣಿಕೆ * ಗಾತ್ರ (DWORD);
    ord_o = name_o + sym_ಎಣಿಕೆ * ಗಾತ್ರ (DWORD);
    str_o = ord_o + sym_ಎಣಿಕೆ * ಗಾತ್ರ(ಶಬ್ದ_3);

    hdr = section_ptr_ಕೂಡಿಸು(pe->thunk, str_o - ತಳ_o);
    hdr->Characteristics        = 0;
    hdr->ತಳ_2                   = 1;
    hdr->ಸಂಖ್ಯೆ_ದ_Functions      = sym_ಎಣಿಕೆ;
    hdr->ಸಂಖ್ಯೆ_ದ_ಹೆಸರುಗಳು          = sym_ಎಣಿಕೆ;
    hdr->ವಿಳಾಸ_ದ_Functions     = func_o + rva_ತಳ;
    hdr->ವಿಳಾಸ_ದ_ಹೆಸರುಗಳು         = name_o + rva_ತಳ;
    hdr->ವಿಳಾಸ_ದ_Name_Ordinals  = ord_o + rva_ತಳ;
    hdr->Name                   = str_o + rva_ತಳ;
    put_elf_str(pe->thunk, dllname);

#ಆದರೆ 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, ಗಾತ್ರ buf, pe->filename);
    strcpy(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    ಆದರೆ (ಖಾಲಿ == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } ಇಲ್ಲದಿದ್ದರೆ {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        ಆದರೆ (s1->verbose)
            ಬರೆ("<- %s (%d symbol%s)\n", buf, sym_ಎಣಿಕೆ, &"s"[sym_ಎಣಿಕೆ < 2]);
    }
#ಆದರೆ_ಅಂತ್ಯ

    ಗಾಗಿ (ord = 0; ord < sym_ಎಣಿಕೆ; ++ord)
    {
        p = sorted[ord], sym_ಸೂಚ್ಯಂಕ = p->ಸೂಚ್ಯಂಕ, name = p->name;
        /* insert actual address later in relocate_sections() */
        put_elf_reloc(symtab_section, pe->thunk,
            func_o, R_XXX_RELATIVE, sym_ಸೂಚ್ಯಂಕ);
        *(DWORD*)(pe->thunk->ದತ್ತಾಂಶ + name_o)
            = pe->thunk->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ + rva_ತಳ;
        *(ಶಬ್ದ_3*)(pe->thunk->ದತ್ತಾಂಶ + ord_o)
            = ord;
        put_elf_str(pe->thunk, name);
        func_o += ಗಾತ್ರ (DWORD);
        name_o += ಗಾತ್ರ (DWORD);
        ord_o += ಗಾತ್ರ (ಶಬ್ದ_3);
        ಆದರೆ (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = ತಳ_o + rva_ತಳ;
    pe->exp_ಗಾತ್ರ = pe->thunk->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - ತಳ_o;
    dynarray_reset(&sorted, &sym_ಎಣಿಕೆ);
    ಆದರೆ (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
ಸ್ಥಿರ ಶೂನ್ಯ pe_build_reloc (ರಚನೆ pe_info *pe)
{
    DWORD ಸ್ಥಾನಾಂತರ, ಖಂಡ_ptr, sh_addr, addr;
    ಪೂರ್ಣಾಂಕ ಎಣಿಕೆ_3, i;
    ElfW_Rel *rel, *rel_ಕೊನೆ;
    Section *s = ಖಾಲಿ, *sr;
    ರಚನೆ pe_reloc_ಶೀರ್ಷಿಕೆ *hdr;
    TCCState *s1 = pe->s1;
    ಪೂರ್ಣಾಂಕ dwarf = 0, n;

    sh_addr = ಸ್ಥಾನಾಂತರ = ಖಂಡ_ptr = ಎಣಿಕೆ_3 = i = 0;
    rel = rel_ಕೊನೆ = ಖಾಲಿ;

    ಗಾಗಿ(;;) {
        ಆದರೆ (rel < rel_ಕೊನೆ) {
            ಪೂರ್ಣಾಂಕ type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_ಸ್ಥಾನಾಂತರ + sh_addr;
            ++ rel;
            ಆದರೆ (type != REL_TYPE_ನೇರ)
                ಮುಂದುವರಿ;
            ಆದರೆ (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->ದತ್ತಾಂಶ + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                ಆದರೆ (n >= s1->dwlo && n < s1->dwhi)
                    ಮುಂದುವರಿ;
            }
            ಆದರೆ (ಎಣಿಕೆ_3 == 0) { /* new block */
                ಖಂಡ_ptr = pe->reloc->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
                section_ptr_ಕೂಡಿಸು(pe->reloc, ಗಾತ್ರ(ರಚನೆ pe_reloc_ಶೀರ್ಷಿಕೆ));
                ಸ್ಥಾನಾಂತರ = addr & 0xFFFFFFFF<<12;
            }
            ಆದರೆ ((addr -= ಸ್ಥಾನಾಂತರ)  < (1<<12)) { /* one block spans 4k addresses */
                ಶಬ್ದ_3 *wp = section_ptr_ಕೂಡಿಸು(pe->reloc, ಗಾತ್ರ (ಶಬ್ದ_3));
                *wp = addr | PE_IMAGE_REL<<12;
                ++ಎಣಿಕೆ_3;
                ಮುಂದುವರಿ;
            }
            -- rel;

        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s) {
            sr = s->reloc;
            ಆದರೆ (sr) {
                rel = (ElfW_Rel *)sr->ದತ್ತಾಂಶ;
                rel_ಕೊನೆ = (ElfW_Rel *)(sr->ದತ್ತಾಂಶ + sr->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
                sh_addr = s->sh_addr;
                dwarf = s->sh_ಅಂಕೆ >= s1->dwlo && s->sh_ಅಂಕೆ < s1->dwhi;
            }
            s = s->prev;
            ಮುಂದುವರಿ;

        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (i < pe->sec_ಎಣಿಕೆ) {
            s = pe->sec_info[i]->sec, ++i;
            ಮುಂದುವರಿ;

        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!ಎಣಿಕೆ_3)
            ನಿಲ್ಲಿಸು;

        /* fill the last block and ready for a new one */
        ಆದರೆ (ಎಣಿಕೆ_3 & 1) /* align for DWORDS */
            section_ptr_ಕೂಡಿಸು(pe->reloc, ಗಾತ್ರ(ಶಬ್ದ_3)), ++ಎಣಿಕೆ_3;
        hdr = (ರಚನೆ pe_reloc_ಶೀರ್ಷಿಕೆ *)(pe->reloc->ದತ್ತಾಂಶ + ಖಂಡ_ptr);
        hdr -> ಸ್ಥಾನಾಂತರ = ಸ್ಥಾನಾಂತರ - pe->imagebase;
        hdr -> ಗಾತ್ರ_2 = ಎಣಿಕೆ_3 * ಗಾತ್ರ(ಶಬ್ದ_3) + ಗಾತ್ರ(ರಚನೆ pe_reloc_ಶೀರ್ಷಿಕೆ);
        ಎಣಿಕೆ_3 = 0;
    }
}

/* ------------------------------------------------------------- */
ಸ್ಥಿರ ಶೂನ್ಯ pe_build_tls(ರಚನೆ pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    ಪೂರ್ಣಾಂಕ c, n;

    ಆದರೆ (0 == s) {
        pe->tls_ಗಾತ್ರ = ಗಾತ್ರ (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_ಕೂಡಿಸು(pe->thunk, pe->tls_ಗಾತ್ರ, 16);
        pe->tls_ದತ್ತಾಂಶ = section_ಕೂಡಿಸು(ದತ್ತಾಂಶ_section, PTR_ಗಾತ್ರ * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, ದತ್ತಾಂಶ_section->sh_ಅಂಕೆ, 0);
        ಗಾಗಿ (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_ಗಾತ್ರ*n, REL_TYPE_ನೇರ, c);
        /* for generators */
        ಗಣ_elf_sym(symtab_section, pe->tls_ದತ್ತಾಂಶ, PTR_ಗಾತ್ರ * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, ದತ್ತಾಂಶ_section->sh_ಅಂಕೆ, "__tls_index");
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (0 == s1->tls_ಆರಂಭ)
        s1->tls_ಆರಂಭ = s->sh_addr;
    d = (ಶೂನ್ಯ*)(pe->thunk->ದತ್ತಾಂಶ + pe->tls_dir);
    d->ಆರಂಭ_ವಿಳಾಸ_ದ_Raw_ದತ್ತಾಂಶ = s1->tls_ಆರಂಭ - ದತ್ತಾಂಶ_section->sh_addr;
    d->ಕೊನೆ_ವಿಳಾಸ_ದ_Raw_ದತ್ತಾಂಶ = s->sh_addr + s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - ದತ್ತಾಂಶ_section->sh_addr;
    d->ವಿಳಾಸ_ದ_ಸೂಚ್ಯಂಕ = pe->tls_ದತ್ತಾಂಶ;
    d->ವಿಳಾಸ_ದ_Call_Backs = pe->tls_ದತ್ತಾಂಶ + PTR_ಗಾತ್ರ;
    d->ಗಾತ್ರ_ದ_Zero_Fill = 0;
    d->Characteristics = 0;
    /* to reuse logic from linux in xxx-link.c */
    s1->tls_ಕೊನೆ = s1->tls_ಆರಂಭ;
}

/* ------------------------------------------------------------- */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pe_section_class(Section *s)
{
    ಪೂರ್ಣಾಂಕ type, flags;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    ಆದರೆ (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        ಹಿಂತಿರುಗಿ sec_debug;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (flags & SHF_ALLOC) {
        ಆದರೆ (flags & SHF_TLS)
            ಹಿಂತಿರುಗಿ sec_tdata + (type == SHT_NOBITS);
        ಆದರೆ (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            ಆದರೆ (flags & SHF_EXECINSTR)
                ಹಿಂತಿರುಗಿ sec_ಪಠ್ಯ;
            ಆದರೆ (flags & SHF_WRITE)
                ಹಿಂತಿರುಗಿ sec_ದತ್ತಾಂಶ;
            ಆದರೆ (0 == strcmp(name, ".rsrc"))
                ಹಿಂತಿರುಗಿ sec_rsrc;
            ಆದರೆ (0 == strcmp(name, ".iedat"))
                ಹಿಂತಿರುಗಿ sec_idata;
            ಆದರೆ (0 == strcmp(name, ".pdata"))
                ಹಿಂತಿರುಗಿ sec_pdata;
            ಹಿಂತಿರುಗಿ sec_rdata;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (type == SHT_NOBITS) {
            ಹಿಂತಿರುಗಿ sec_bss;
        }
        ಹಿಂತಿರುಗಿ sec_other;
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ (0 == strcmp(name, ".reloc"))
            ಹಿಂತಿರುಗಿ sec_reloc;
    }
    ಹಿಂತಿರುಗಿ sec_ಕೊನೆಯ;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pe_ನಿಯೋಜಿಸು_ವಿಳಾಸಗಳು (ರಚನೆ pe_info *pe)
{
    ಪೂರ್ಣಾಂಕ i, k, n, c, nbs;
    ADDR3264 addr;
    ಪೂರ್ಣಾಂಕ *sec_ಕ್ರಮ, *sec_cls;
    ರಚನೆ section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    ಆದರೆ (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_ತಳ))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_ಕ್ರಮ = tcc_mallocz(2 * ಗಾತ್ರ (ಪೂರ್ಣಾಂಕ) * nbs);
    sec_cls = sec_ಕ್ರಮ + nbs;
    ಗಾಗಿ (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        ಗಾಗಿ (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_ಕ್ರಮ[n] = sec_ಕ್ರಮ[n - 1];
        sec_cls[n] = k, sec_ಕ್ರಮ[n] = i;
        ಆದರೆ ((s->sh_flags & SHF_TLS) && 0 == pe->tls_ಗಾತ್ರ)
            pe_build_tls(pe, ಖಾಲಿ);
    }
    si = ಖಾಲಿ;
    addr = pe->imagebase + 1;
    ಗಾಗಿ (i = 1; (c = sec_cls[i]) < sec_ಕೊನೆಯ; ++i) {
        s = s1->sections[sec_ಕ್ರಮ[i]];

        ಆದರೆ (PE_ವಿಲೀನ_ದತ್ತಾಂಶ && c == sec_bss)
            c = sec_ದತ್ತಾಂಶ;
        ಆದರೆ (c == sec_tbss)
            c = sec_tdata;

        ಆದರೆ (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } ಇಲ್ಲದಿದ್ದರೆ {
            si = ಖಾಲಿ;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        ಆದರೆ (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        ಆದರೆ (s == pe->reloc)
            pe_build_reloc (pe);

        ಆದರೆ (0 == s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ)
            ಮುಂದುವರಿ;

        ಆದರೆ (si)
            ಹೋಗು ಕೂಡಿಸು_section;

        si = tcc_mallocz(ಗಾತ್ರ *si);
        dynarray_ಕೂಡಿಸು(&pe->sec_info, &pe->sec_ಎಣಿಕೆ, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        ಆದರೆ (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_ಸಂಕೇತ;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_ದತ್ತಾಂಶ;
        ಇಲ್ಲದಿದ್ದರೆ
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_ದತ್ತಾಂಶ;
        ಆದರೆ (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        ಆದರೆ (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

ಕೂಡಿಸು_section:
        s->sh_info = pe->sec_ಎಣಿಕೆ; /* section number for coff syms */
        addr += s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
        si->sh_ಗಾತ್ರ = addr - si->sh_addr;
        ಆದರೆ (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            ಆಗ (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = ಖಾಲಿ;
            si->ದತ್ತಾಂಶ_ಗಾತ್ರ = si->sh_ಗಾತ್ರ;
        }

        ಆದರೆ (s->sh_flags & SHF_TLS) {
            strcpy(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#ಆದರೆ 0
    ಗಾಗಿ (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_ಕ್ರಮ[i]];
        ಪೂರ್ಣಾಂಕ type = s->sh_type;
        ಪೂರ್ಣಾಂಕ flags = s->sh_flags;
        ಬರೆ("section %-16s %-10s %p %04x %2d %s,%s,%s\n",
            s->name,
            type == SHT_PROGBITS ? "progbits" :
            type == SHT_INIT_ARRAY ? "initarr" :
            type == SHT_FINI_ARRAY ? "finiarr" :
            type == SHT_NOBITS ? "nobits" :
            type == SHT_SYMTAB ? "symtab" :
            type == SHT_STRTAB ? "strtab" :
            type == SHT_RELX ? "rel" : "???",
            s->sh_addr,
            (ಚಿಹ್ನೆರಹಿತ)s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ,
            s->sh_addralign,
            flags & SHF_ALLOC ? "alloc" : "",
            flags & SHF_WRITE ? "write" : "",
            flags & SHF_EXECINSTR ? "exec" : ""
            );
        fflush(stdout);
    }
    s1->verbose = 2;
#ಆದರೆ_ಅಂತ್ಯ
    tcc_free(sec_ಕ್ರಮ);
    ಹಿಂತಿರುಗಿ 0;
}

/*----------------------------------------------------------------------------*/
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pe_check_symbols(ರಚನೆ pe_info *pe)
{
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ, sym_ಕೊನೆ;
    ಪೂರ್ಣಾಂಕ ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(ಪಠ್ಯ_section, 8);

    sym_ಕೊನೆ = symtab_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ(ElfW(Sym));
    ಗಾಗಿ (sym_ಸೂಚ್ಯಂಕ = 1; sym_ಸೂಚ್ಯಂಕ < sym_ಕೊನೆ; ++sym_ಸೂಚ್ಯಂಕ) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ + sym_ಸೂಚ್ಯಂಕ;
        ಆದರೆ (sym->st_shndx == SHN_UNDEF) {
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = (ಅಕ್ಷರ*)symtab_section->link->ದತ್ತಾಂಶ + sym->st_name;
            ಚಿಹ್ನೆರಹಿತ type = ELFW(ST_TYPE)(sym->st_info);
            ಪೂರ್ಣಾಂಕ imp_sym = 0;
            ರಚನೆ import_ಚಿಹ್ನೆ *is;

            ಪೂರ್ಣಾಂಕ _imp_, n;
            ಅಕ್ಷರ ಬಫರ್[200];
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s, *p;

            n = _imp_ = 0;
            ಆದರೆ (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            ಮಾಡು {
                s = pe_export_name(s1, sym);
                ಆದರೆ (n) {
                    /* second try: */
                    ಆದರೆ (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        ಆದರೆ (!p || s[0] != '_')
                            ನಿಲ್ಲಿಸು;
                        strcpy(ಬಫರ್, s+1)[p-s-1] = 0, s = ಬಫರ್;
                    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s[0] != '_') { /* try non-ansi function */
                        ಬಫರ್[0] = '_', strcpy(ಬಫರ್ + 1, s), s = ಬಫರ್;
                    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } ಇಲ್ಲದಿದ್ದರೆ {
                        ನಿಲ್ಲಿಸು;
                    }
                }
                imp_sym = ಕಂಡುಹಿಡಿ_elf_sym(s1->dynsymtab_section, s);
            } ಆಗ (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            ಆದರೆ (0 == imp_sym)
                ಮುಂದುವರಿ; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_ಕೂಡಿಸು_import(pe, imp_sym);

            ಆದರೆ (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                ಚಿಹ್ನೆರಹಿತ ಸ್ಥಾನಾಂತರ = is->thk_ಸ್ಥಾನಾಂತರ;
                ಆದರೆ (ಸ್ಥಾನಾಂತರ) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } ಇಲ್ಲದಿದ್ದರೆ {
                    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(ಬಫರ್, "IAT.%s", name);
                    is->iat_ಸೂಚ್ಯಂಕ = put_elf_sym(
                        symtab_section, 0, ಗಾತ್ರ(DWORD),
                        ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT),
                        0, SHN_UNDEF, ಬಫರ್);

                    ಸ್ಥಾನಾಂತರ = ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
                    is->thk_ಸ್ಥಾನಾಂತರ = ಸ್ಥಾನಾಂತರ;

                    /* add the 'jmp IAT[x]' instruction */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
                    p = section_ptr_ಕೂಡಿಸು(ಪಠ್ಯ_section, 8+4); // room for code and address
                    write32le(p + 0, 0xE59FC000); // arm code ldr ip, [pc] ; PC+8+0 = 0001xxxx
                    write32le(p + 4, 0xE59CF000); // arm code ldr pc, [ip]
                    put_elf_reloc(symtab_section, ಪಠ್ಯ_section,
                        ಸ್ಥಾನಾಂತರ + 8, R_XXX_THUNKFIX, is->iat_ಸೂಚ್ಯಂಕ); // offset to IAT position
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_ARM64)
                    p = section_ptr_ಕೂಡಿಸು(ಪಠ್ಯ_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, ಪಠ್ಯ_section,
                        ಸ್ಥಾನಾಂತರ + 16, R_XXX_THUNKFIX, is->iat_ಸೂಚ್ಯಂಕ);
#ಇಲ್ಲದಿದ್ದರೆ
                    p = section_ptr_ಕೂಡಿಸು(ಪಠ್ಯ_section, 8);
                    write16le(p, 0x25FF);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
                    write32le(p + 2, (DWORD)-4);
#ಆದರೆ_ಅಂತ್ಯ
                    put_elf_reloc(symtab_section, ಪಠ್ಯ_section, 
                        ಸ್ಥಾನಾಂತರ + 2, R_XXX_THUNKFIX, is->iat_ಸೂಚ್ಯಂಕ);
#ಆದರೆ_ಅಂತ್ಯ
                }
                /* tcc_realloc might have altered sym's address */
                sym = (ElfW(Sym) *)symtab_section->ದತ್ತಾಂಶ + sym_ಸೂಚ್ಯಂಕ;
                /* patch the original symbol */
                sym->st_ಮೌಲ್ಯ = ಸ್ಥಾನಾಂತರ;
                sym->st_shndx = ಪಠ್ಯ_section->sh_ಅಂಕೆ;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } ಇಲ್ಲದಿದ್ದರೆ { /* STT_OBJECT */
                ಆದರೆ (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_ಮೌಲ್ಯ = is->iat_ಸೂಚ್ಯಂಕ; /* chain potential alias */
                is->iat_ಸೂಚ್ಯಂಕ = sym_ಸೂಚ್ಯಂಕ;
            }

        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    ಹಿಂತಿರುಗಿ ret;
}

/*----------------------------------------------------------------------------*/
#ಆದರೆ PE_PRINT_SECTIONS
ಸ್ಥಿರ ಶೂನ್ಯ pe_print_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    ಪೂರ್ಣಾಂಕ i, n, l, m;
    p = s->ದತ್ತಾಂಶ;
    e = s->ದತ್ತಾಂಶ + s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    ಆದರೆ (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    ಆದರೆ (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (ಚಿಹ್ನೆರಹಿತ)s->sh_addr);
    fprintf(f, "\ncontents %08X", (ಚಿಹ್ನೆರಹಿತ)l);
    fprintf(f, "\n\n");

    ಆದರೆ (s->sh_type == SHT_NOBITS)
        ಹಿಂತಿರುಗಿ;

    ಆದರೆ (0 == l)
        ಹಿಂತಿರುಗಿ;

    ಆದರೆ (s->sh_type == SHT_SYMTAB)
        m = ಗಾತ್ರ(ElfW(Sym));
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_type == SHT_RELX)
        m = ಗಾತ್ರ(ElfW_Rel);
    ಇಲ್ಲದಿದ್ದರೆ
        m = 16;

    fprintf(f, "%-8s", "offset");
    ಗಾಗಿ (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    ಆದರೆ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            ಖಾಲಿ
        };

        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fields2[] = {
            "offs",
            "type",
            "symb",
            ಖಾಲಿ
        };

        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ **p;

        ಆದರೆ (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        ಇಲ್ಲದಿದ್ದರೆ
            p = fields2, n = 58;

        ಗಾಗಿ (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    ಗಾಗಿ (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    ಗಾಗಿ (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        ಗಾಗಿ (n = 0; n < m; ++n) {
            ಆದರೆ (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            ಇಲ್ಲದಿದ್ದರೆ
                fprintf(f, "   ");
        }

        ಆದರೆ (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = s->link->ದತ್ತಾಂಶ + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (ಚಿಹ್ನೆರಹಿತ)sym->st_name,
                    (ಚಿಹ್ನೆರಹಿತ)sym->st_ಮೌಲ್ಯ,
                    (ಚಿಹ್ನೆರಹಿತ)sym->st_ಗಾತ್ರ,
                    (ಚಿಹ್ನೆರಹಿತ)ELFW(ST_BIND)(sym->st_info),
                    (ಚಿಹ್ನೆರಹಿತ)ELFW(ST_TYPE)(sym->st_info),
                    (ಚಿಹ್ನೆರಹಿತ)sym->st_other,
                    (ಚಿಹ್ನೆರಹಿತ)sym->st_shndx,
                    name);

        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->ದತ್ತಾಂಶ + ELFW(R_SYM)(rel->r_info);
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = s->link->link->ದತ್ತಾಂಶ + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (ಚಿಹ್ನೆರಹಿತ)rel->r_ಸ್ಥಾನಾಂತರ,
                    (ಚಿಹ್ನೆರಹಿತ)ELFW(R_TYPE)(rel->r_info),
                    (ಚಿಹ್ನೆರಹಿತ)ELFW(R_SYM)(rel->r_info),
                    name);
        } ಇಲ್ಲದಿದ್ದರೆ {
            fprintf(f, "   ");
            ಗಾಗಿ (n = 0; n < m; ++n) {
                ಆದರೆ (n + i < l) {
                    b = p[i + n];
                    ಆದರೆ (b < 32 || b >= 127)
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

ಸ್ಥಿರ ಶೂನ್ಯ pe_print_sections(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fname)
{
    Section *s;
    FILE *f;
    ಪೂರ್ಣಾಂಕ i;
    f = fopen(fname, "w");
    ಗಾಗಿ (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    fclose(f);
}
#ಆದರೆ_ಅಂತ್ಯ

/* ------------------------------------------------------------- */

ST_FUNC ಪೂರ್ಣಾಂಕ pe_putimport(TCCState *s1, ಪೂರ್ಣಾಂಕ dllindex, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, addr_t ಮೌಲ್ಯ)
{
    ಹಿಂತಿರುಗಿ ಗಣ_elf_sym(
        s1->dynsymtab_section,
        ಮೌಲ್ಯ,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        ಮೌಲ್ಯ ? SHN_ABS : SHN_UNDEF,
        name
        );
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ read_mem(ಪೂರ್ಣಾಂಕ fd, ಚಿಹ್ನೆರಹಿತ ಸ್ಥಾನಾಂತರ, ಶೂನ್ಯ *ಬಫರ್, ಚಿಹ್ನೆರಹಿತ len)
{
    lseek(fd, ಸ್ಥಾನಾಂತರ, SEEK_SET);
    ಹಿಂತಿರುಗಿ len == ಪಠ(fd, ಬಫರ್, len);
}

/* ------------------------------------------------------------- */

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ get_dllexports(ಪೂರ್ಣಾಂಕ fd, ಅಕ್ಷರ **pp)
{
    ಪೂರ್ಣಾಂಕ i, k, l, n, n0, ret;
    ಅಕ್ಷರ *p;

    IMAGE_SECTION_ಶೀರ್ಷಿಕೆ_2 ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_ಶೀರ್ಷಿಕೆ_2 dh;
    IMAGE_FILE_ಶೀರ್ಷಿಕೆ_2 ih;
    DWORD sig, ref, addr;
    DWORD *namep = ಖಾಲಿ, p0 = 0, p1;

    ಪೂರ್ಣಾಂಕ pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = ಖಾಲಿ;
    ret = 1;
    ಆದರೆ (!read_mem(fd, 0, &dh, ಗಾತ್ರ dh))
        ಹೋಗು the_ಕೊನೆ;
    ಆದರೆ (!read_mem(fd, dh.e_lfanew, &sig, ಗಾತ್ರ sig))
        ಹೋಗು the_ಕೊನೆ;
    ಆದರೆ (sig != 0x00004550)
        ಹೋಗು the_ಕೊನೆ;
    pef_hdroffset = dh.e_lfanew + ಗಾತ್ರ sig;
    ಆದರೆ (!read_mem(fd, pef_hdroffset, &ih, ಗಾತ್ರ ih))
        ಹೋಗು the_ಕೊನೆ;
    opt_hdroffset = pef_hdroffset + ಗಾತ್ರ ih;
    ಆದರೆ (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + ಗಾತ್ರ oh;
        ಆದರೆ (!read_mem(fd, opt_hdroffset, &oh, ಗಾತ್ರ oh))
            ಹೋಗು the_ಕೊನೆ;
        ಆದರೆ (IMAGE_DIRECTORY_ನಮೂದು_EXPORT >= oh.ಸಂಖ್ಯೆ_ದ_Rva_And_Sizes)
            ಹೋಗು the_ಕೊನೆ_0;
        addr = oh.ದತ್ತಾಂಶ_Directory[IMAGE_DIRECTORY_ನಮೂದು_EXPORT].Virtual_ವಿಳಾಸ;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + ಗಾತ್ರ oh;
        ಆದರೆ (!read_mem(fd, opt_hdroffset, &oh, ಗಾತ್ರ oh))
            ಹೋಗು the_ಕೊನೆ;
        ಆದರೆ (IMAGE_DIRECTORY_ನಮೂದು_EXPORT >= oh.ಸಂಖ್ಯೆ_ದ_Rva_And_Sizes)
            ಹೋಗು the_ಕೊನೆ_0;
        addr = oh.ದತ್ತಾಂಶ_Directory[IMAGE_DIRECTORY_ನಮೂದು_EXPORT].Virtual_ವಿಳಾಸ;
    } ಇಲ್ಲದಿದ್ದರೆ
        ಹೋಗು the_ಕೊನೆ;

    //printf("addr: %08x\n", addr);
    ಗಾಗಿ (i = 0; i < ih.ಸಂಖ್ಯೆ_ದ_Sections; ++i) {
        ಆದರೆ (!read_mem(fd, sec_hdroffset + i * ಗಾತ್ರ ish, &ish, ಗಾತ್ರ ish))
            ಹೋಗು the_ಕೊನೆ;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        ಆದರೆ (addr >= ish.Virtual_ವಿಳಾಸ && addr < ish.Virtual_ವಿಳಾಸ + ish.ಗಾತ್ರ_ದ_Raw_ದತ್ತಾಂಶ)
            ಹೋಗು ಸಿಕ್ಕಿತು;
    }
    ಹೋಗು the_ಕೊನೆ_0;
ಸಿಕ್ಕಿತು:
    ref = ish.Virtual_ವಿಳಾಸ - ish.ಸೂಚಕ_ಗಮ್ಯ_Raw_ದತ್ತಾಂಶ;
    ಆದರೆ (!read_mem(fd, addr - ref, &ied, ಗಾತ್ರ ied))
        ಹೋಗು the_ಕೊನೆ;
    k = ied.ಸಂಖ್ಯೆ_ದ_ಹೆಸರುಗಳು;
    ಆದರೆ (k) {
        namep = tcc_malloc(l = k * ಗಾತ್ರ *namep);
        ಆದರೆ (!read_mem(fd, ied.ವಿಳಾಸ_ದ_ಹೆಸರುಗಳು - ref, namep, l))
            ಹೋಗು the_ಕೊನೆ;
        ಗಾಗಿ (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            ಆದರೆ (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            ಮಾಡು {
                ಆದರೆ (0 == l) {
                    ಆದರೆ (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    ಆದರೆ ((l = ಪಠ(fd, p + n, 1000 - 1)) <= 0)
                        ಹೋಗು the_ಕೊನೆ;
                }
                --l, ++p0;
            } ಆಗ (p[n++]);
        }
        p[n] = 0;
    }
the_ಕೊನೆ_0:
    ret = 0;
the_ಕೊನೆ:
    tcc_free(namep);
    ಆದರೆ (ret && p)
        tcc_free(p), p = ಖಾಲಿ;
    *pp = p;
    ಹಿಂತಿರುಗಿ ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pe_ತುಂಬು_res(TCCState *s1, ಪೂರ್ಣಾಂಕ fd)
{
    ರಚನೆ pe_rsrc_ಶೀರ್ಷಿಕೆ hdr;
    Section *rsrc_section;
    ಪೂರ್ಣಾಂಕ i, ret = -1, sym_ಸೂಚ್ಯಂಕ;
    BYTE *ptr;
    ಚಿಹ್ನೆರಹಿತ offs;

    ಆದರೆ (!read_mem(fd, 0, &hdr, ಗಾತ್ರ hdr))
        ಹೋಗು quit;

    ಆದರೆ (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.ಸಂಖ್ಯೆ_ದ_Sections != 1
        || strcmp((ಅಕ್ಷರ*)hdr.sectionhdr.Name, ".rsrc") != 0)
        ಹೋಗು quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_ಕೂಡಿಸು(rsrc_section, hdr.sectionhdr.ಗಾತ್ರ_ದ_Raw_ದತ್ತಾಂಶ);
    offs = hdr.sectionhdr.ಸೂಚಕ_ಗಮ್ಯ_Raw_ದತ್ತಾಂಶ;
    ಆದರೆ (!read_mem(fd, offs, ptr, hdr.sectionhdr.ಗಾತ್ರ_ದ_Raw_ದತ್ತಾಂಶ))
        ಹೋಗು quit;
    offs = hdr.sectionhdr.ಸೂಚಕ_ಗಮ್ಯ_Relocations;
    sym_ಸೂಚ್ಯಂಕ = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_ಅಂಕೆ, ".rsrc");
    ಗಾಗಿ (i = 0; i < hdr.sectionhdr.ಸಂಖ್ಯೆ_ದ_Relocations; ++i) {
        ರಚನೆ pe_rsrc_reloc rel;
        ಆದರೆ (!read_mem(fd, offs, &rel, ಗಾತ್ರ rel))
            ಹೋಗು quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        ಆದರೆ (rel.type != RSRC_RELTYPE)
            ಹೋಗು quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.ಸ್ಥಾನಾಂತರ, R_XXX_RELATIVE, sym_ಸೂಚ್ಯಂಕ);
        offs += ಗಾತ್ರ rel;
    }
    ret = 0;
quit:
    ಹಿಂತಿರುಗಿ ret;
}

/* ------------------------------------------------------------- */

ಸ್ಥಿರ ಅಕ್ಷರ *trimfront(ಅಕ್ಷರ *p)
{
    ಆಗ ((ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)*p <= ' ' && *p && *p != '\n')
	++p;
    ಹಿಂತಿರುಗಿ p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

ಸ್ಥಿರ ಅಕ್ಷರ *get_token(ಅಕ್ಷರ **s, ಅಕ್ಷರ *f)
{
    ಅಕ್ಷರ *p, *e;
    ಪೂರ್ಣಾಂಕ q;

    p = trimfront(*s);
    q = *p;
    ಆದರೆ (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    ಇಲ್ಲದಿದ್ದರೆ
        q = ' ';
    ಗಾಗಿ (e = p; (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)*e >= ' ' && *e != q; ++e)
        ;
    ಆದರೆ (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    ಹಿಂತಿರುಗಿ p;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pe_ತುಂಬು_def(TCCState *s1, ಪೂರ್ಣಾಂಕ fd)
{
    ಪೂರ್ಣಾಂಕ state = 0, ret = -1, dllindex = 0, ord;
    ಅಕ್ಷರ dllname[80], *buf, *ಸಾಲು, *p, *x, ಮುಂದಿನ;

    buf = tcc_ತುಂಬು_ಪಠ್ಯ(fd);
    ಆದರೆ (!buf)
        ಹಿಂತಿರುಗಿ ret;

    ಗಾಗಿ (ಸಾಲು = buf;; ++ಸಾಲು)  {
        p = get_token(&ಸಾಲು, &ಮುಂದಿನ);
        ಆದರೆ (!(*p && *p != ';'))
            ಹೋಗು skip;
        ಆಯ್ಕೆ (state) {
        ಸ್ಥಿತಿ 0:
            ಆದರೆ (0 != stricmp(p, "LIBRARY") || ಮುಂದಿನ == '\n')
                ಹೋಗು quit;
            pstrcpy(dllname, ಗಾತ್ರ dllname, get_token(&ಸಾಲು, &ಮುಂದಿನ));
            ಆದರೆ (!*tcc_fileextension(dllname))
                pstrcat(dllname, ಗಾತ್ರ dllname, ".dll");
            ++state;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 1:
            ಆದರೆ (0 != stricmp(p, "EXPORTS"))
                ಹೋಗು quit;
            ++state;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 2:
            dllindex = tcc_ಕೂಡಿಸು_dllref(s1, dllname, 0)->ಸೂಚ್ಯಂಕ;
            ++state;
            /* fall through */
        ಪೂರ್ವನಿಯೋಜಿತ:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            ಆದರೆ (ಮುಂದಿನ == '@') {
                x = get_token(&ಸಾಲು, &ಮುಂದಿನ);
                ord = (ಪೂರ್ಣಾಂಕ)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            ನಿಲ್ಲಿಸು;
        }
skip:
        ಆಗ ((ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)ಮುಂದಿನ > ' ')
            get_token(&ಸಾಲು, &ಮುಂದಿನ);
        ಆದರೆ (ಮುಂದಿನ != '\n')
            ನಿಲ್ಲಿಸು;
    }
    ret = 0;
quit:
    tcc_free(buf);
    ಹಿಂತಿರುಗಿ ret;
}

/* ------------------------------------------------------------- */

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pe_ತುಂಬು_dll(TCCState *s1, ಪೂರ್ಣಾಂಕ fd, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    ಅಕ್ಷರ *p, *q;
    DLLReference *ref = tcc_ಕೂಡಿಸು_dllref(s1, filename, 0);
    ಆದರೆ (ref->ಸಿಕ್ಕಿತು)
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ (get_dllexports(fd, &p))
        ಹಿಂತಿರುಗಿ -1;
    ಆದರೆ (p) {
        ಗಾಗಿ (q = p; *q; q += 1 + ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(q))
            pe_putimport(s1, ref->ಸೂಚ್ಯಂಕ, q, 0);
        tcc_free(p);
    }
    ಹಿಂತಿರುಗಿ 0;
}

ST_FUNC ಪೂರ್ಣಾಂಕ pe_ತುಂಬು_file(ರಚನೆ TCCState *s1, ಪೂರ್ಣಾಂಕ fd, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    ಪೂರ್ಣಾಂಕ ret = -1;
    ಅಕ್ಷರ buf[10];
    ಆದರೆ (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_ತುಂಬು_def(s1, fd);
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (pe_ತುಂಬು_res(s1, fd) == 0)
        ret = 0;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_ತುಂಬು_dll(s1, fd, filename);
    ಹಿಂತಿರುಗಿ ret;
}

PUB_FUNC ಪೂರ್ಣಾಂಕ tcc_get_dllexports(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಅಕ್ಷರ **pp)
{
    ಪೂರ್ಣಾಂಕ ret, fd = open(filename, O_RDONLY | O_ದ್ವಿಮಾನ_2);
    ಆದರೆ (fd < 0)
        ಹಿಂತಿರುಗಿ -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    ಹಿಂತಿರುಗಿ ret;
}

/* ------------------------------------------------------------- */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ pe_ಕೂಡಿಸು_unwind_info(TCCState *s1)
{
    ಆದರೆ (ಖಾಲಿ == s1->uw_pdata) {
        s1->uw_pdata = ಕಂಡುಹಿಡಿ_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    ಆದರೆ (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, ಪಠ್ಯ_section->sh_ಅಂಕೆ, ".uw_base");
    ಆದರೆ (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ uw_info[] = {
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

        Section *s = ಪಠ್ಯ_section;
        ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *p;

        section_ptr_ಕೂಡಿಸು(s, -s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ & 3); /* align */
        s1->uw_offs = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
        p = section_ptr_ಕೂಡಿಸು(s, ಗಾತ್ರ uw_info);
        ಸ್ಮರಣೆ_ನಕಲು(p, uw_info, ಗಾತ್ರ uw_info);
    }

    ಹಿಂತಿರುಗಿ s1->uw_offs;
}

ST_FUNC ಶೂನ್ಯ pe_ಕೂಡಿಸು_unwind_ದತ್ತಾಂಶ(ಚಿಹ್ನೆರಹಿತ ಆರಂಭ, ಚಿಹ್ನೆರಹಿತ ಕೊನೆ, ಚಿಹ್ನೆರಹಿತ ರಾಶಿ)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    ಚಿಹ್ನೆರಹಿತ o, n, d;
    ರಚನೆ /* _RUNTIME_FUNCTION */ {
      DWORD Begin_ವಿಳಾಸ;
      DWORD ಕೊನೆ_ವಿಳಾಸ;
      DWORD Unwind_ದತ್ತಾಂಶ;
    } *p;

    d = pe_ಕೂಡಿಸು_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    p = section_ptr_ಕೂಡಿಸು(pd, ಗಾತ್ರ *p);

    /* record this function */
    p->Begin_ವಿಳಾಸ = ಆರಂಭ;
    p->ಕೊನೆ_ವಿಳಾಸ = ಕೊನೆ;
    p->Unwind_ದತ್ತಾಂಶ = d;

    /* put relocations on it */
    ಗಾಗಿ (n = o + ಗಾತ್ರ *p; o < n; o += ಗಾತ್ರ p->Begin_ವಿಳಾಸ)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
ಸ್ಥಿರ Section *pe_ಕೂಡಿಸು_unwind_info(TCCState *s1)
{
    Section *s;

    ಆದರೆ (ಖಾಲಿ == s1->uw_pdata) {
        s1->uw_pdata = ಕಂಡುಹಿಡಿ_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = ಕಂಡುಹಿಡಿ_section(s1, ".xdata");
    s->sh_addralign = 4;
    ಆದರೆ (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  ಪಠ್ಯ_section->sh_ಅಂಕೆ, ".uw_text_base");
    ಆದರೆ (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_ಅಂಕೆ, ".uw_base");
    ಹಿಂತಿರುಗಿ s;
}

ST_FUNC ಶೂನ್ಯ pe_ಕೂಡಿಸು_unwind_ದತ್ತಾಂಶ(ಚಿಹ್ನೆರಹಿತ ಆರಂಭ, ಚಿಹ್ನೆರಹಿತ ಕೊನೆ, ಚಿಹ್ನೆರಹಿತ ರಾಶಿ)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    ಚಿಹ್ನೆರಹಿತ o, d, ಸಂಕೇತ_ಬೈಟುಗಳು, func_len;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *q;
    uint32_t ಶೀರ್ಷಿಕೆ;
    ರಚನೆ /* _RUNTIME_FUNCTION */ {
        DWORD Begin_ವಿಳಾಸ;
        DWORD Unwind_ದತ್ತಾಂಶ;
    } *p;

    ಪೂರ್ಣಾಂಕ epilog;

    xd = pe_ಕೂಡಿಸು_unwind_info(s1);
    pd = s1->uw_pdata;

    func_len = (ಕೊನೆ - ಆರಂಭ) >> 2;
    ಸಂಕೇತ_ಬೈಟುಗಳು = 0;
    epilog = ಸಂಕೇತ_ಬೈಟುಗಳು;
    ಸಂಕೇತ_ಬೈಟುಗಳು += 3; /* set_fp, save_fplr_x, end */
    ಸಂಕೇತ_ಬೈಟುಗಳು = (ಸಂಕೇತ_ಬೈಟುಗಳು + 3) & ~3;

    section_ptr_ಕೂಡಿಸು(xd, -xd->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ & 3);
    d = xd->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    q = section_ptr_ಕೂಡಿಸು(xd, 4 + ಸಂಕೇತ_ಬೈಟುಗಳು);

    /* Full ARM64 xdata header: E=1 with one epilog and no exception handler. */
    ಶೀರ್ಷಿಕೆ = (func_len & 0x3ffff)
        | 1 << 21
        | (epilog & 0x1F) << 22
        | (ಸಂಕೇತ_ಬೈಟುಗಳು >> 2) << 27
        ;
    write32le(q, ಶೀರ್ಷಿಕೆ);
    q += 4;
    *q++ = 0xE1; /* set_fp */
    *q++ = 0x9B; /* save_fplr_x: stp x29,lr,[sp,#-224]! */
    *q++ = 0xE4; /*ಕೊನೆ*/
    ಆಗ ((ಚಿಹ್ನೆರಹಿತ)(q - (xd->ದತ್ತಾಂಶ + d + 4)) < ಸಂಕೇತ_ಬೈಟುಗಳು)
        *q++ = 0xE3; /* nop padding */

    o = pd->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    p = section_ptr_ಕೂಡಿಸು(pd, ಗಾತ್ರ *p);
    p->Begin_ವಿಳಾಸ = ಆರಂಭ;
    p->Unwind_ದತ್ತಾಂಶ = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#ಆದರೆ_ಅಂತ್ಯ
/* ------------------------------------------------------------- */
#ಆದರೆ defined(TCC_ಗುರಿ_X86_64) || defined(TCC_ಗುರಿ_ARM64)
#ವ್ಯಾಖ್ಯಾನಿಸು PE_STDSYM(n,s) n
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು PE_STDSYM(n,s) "_" n s
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಶೂನ್ಯ pe_ಕೂಡಿಸು_runtime(TCCState *s1, ರಚನೆ pe_info *pe)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಆರಂಭ_ಚಿಹ್ನೆ;
    ಪೂರ್ಣಾಂಕ pe_type;

    ಆದರೆ (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        ಆರಂಭ_ಚಿಹ್ನೆ = PE_STDSYM("__dllstart","@12");
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸತತ_ಚಿಹ್ನೆ;
        ಆದರೆ (ಕಂಡುಹಿಡಿ_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            ಆರಂಭ_ಚಿಹ್ನೆ = "__winstart";
            ಸತತ_ಚಿಹ್ನೆ = "__runwinmain";
            pe_type = PE_GUI;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಕಂಡುಹಿಡಿ_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            ಆರಂಭ_ಚಿಹ್ನೆ = "__wwinstart";
            ಸತತ_ಚಿಹ್ನೆ = "__runwwinmain";
            pe_type = PE_GUI;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಕಂಡುಹಿಡಿ_elf_sym(symtab_section, "wmain")) {
            ಆರಂಭ_ಚಿಹ್ನೆ = "__wstart";
            ಸತತ_ಚಿಹ್ನೆ = "__runwmain";
            pe_type = PE_EXE;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆರಂಭ_ಚಿಹ್ನೆ =  "__start";
            ಸತತ_ಚಿಹ್ನೆ = "__runmain";
            pe_type = PE_EXE;
            ಆದರೆ (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        ಆದರೆ (TCC_OUTPUT_ಸ್ಮರಣೆ == s1->output_type && !s1->nostdlib)
            ಆರಂಭ_ಚಿಹ್ನೆ = ಸತತ_ಚಿಹ್ನೆ;
    }
    ಆದರೆ (s1->elf_entryname) {
        pe->ಆರಂಭ_ಚಿಹ್ನೆ = ಆರಂಭ_ಚಿಹ್ನೆ = s1->elf_entryname;
    } ಇಲ್ಲದಿದ್ದರೆ {
        pe->ಆರಂಭ_ಚಿಹ್ನೆ = ಆರಂಭ_ಚಿಹ್ನೆ + 1;
        ಆದರೆ (!s1->leading_underscore || strchr(ಆರಂಭ_ಚಿಹ್ನೆ, '@'))
            ++ಆರಂಭ_ಚಿಹ್ನೆ;
    }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
    ಆದರೆ (s1->do_backtrace) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    ಆದರೆ (s1->output_type == TCC_OUTPUT_ಸ್ಮರಣೆ)
                tcc_ಕೂಡಿಸು_support(s1, "bcheck_run.o");
	    ಇಲ್ಲದಿದ್ದರೆ
                tcc_ಕೂಡಿಸು_support(s1, "bcheck.o");
	}
#ಆದರೆ_ಅಂತ್ಯ
        ಆದರೆ (s1->output_type == TCC_OUTPUT_EXE)
            tcc_ಕೂಡಿಸು_support(s1, "bt-exe.o");
        ಆದರೆ (s1->output_type == TCC_OUTPUT_DLL)
            tcc_ಕೂಡಿಸು_support(s1, "bt-dll.o");
        ಆದರೆ (s1->output_type != TCC_OUTPUT_DLL)
            tcc_ಕೂಡಿಸು_support(s1, "bt-log.o");
        tcc_ಕೂಡಿಸು_btstub(s1);
    }
#ಆದರೆ_ಅಂತ್ಯ

    /* grab the startup code from libtcc1.a */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
    ಆದರೆ (TCC_OUTPUT_ಸ್ಮರಣೆ != s1->output_type || s1->ಸತತ_main)
#ಆದರೆ_ಅಂತ್ಯ
    ಗಣ_global_sym(s1, ಆರಂಭ_ಚಿಹ್ನೆ, ಖಾಲಿ, 0);

    ಆದರೆ (0 == s1->nostdlib) {
        ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * ಸ್ಥಿರಾಂಕ libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", ಖಾಲಿ
        };
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * ಸ್ಥಿರಾಂಕ *pp, *p;
        ಆದರೆ (TCC_LIBTCC1[0])
            tcc_ಕೂಡಿಸು_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        ಗಾಗಿ (pp = libs; 0 != (p = *pp); ++pp) {
            ಆದರೆ (*p)
                tcc_ಕೂಡಿಸು_library(s1, p);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (PE_DLL != pe_type && PE_GUI != pe_type)
                ನಿಲ್ಲಿಸು;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    ಆದರೆ (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    ಆದರೆ (TCC_OUTPUT_ಸ್ಮರಣೆ == s1->output_type)
        pe_type = PE_ಸತತ;
    pe->type = pe_type;
}

ST_FUNC ಪೂರ್ಣಾಂಕ pe_setsubsy(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *arg)
{
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ರಚನೆ subsy { ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* p; ಪೂರ್ಣಾಂಕ v; } x[] = {
#ಆದರೆ defined(TCC_ಗುರಿ_I386) || defined(TCC_ಗುರಿ_X86_64) || defined(TCC_ಗುರಿ_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_ARM)
        { "wince", 9 },
#ಆದರೆ_ಅಂತ್ಯ
        { 0, -1 }};
    ಸ್ಥಿರಾಂಕ ರಚನೆ subsy *y;
    ಗಾಗಿ (y = x;; ++y) {
        ಆದರೆ (!y->p)
            ಹಿಂತಿರುಗಿ -1;
        ಆದರೆ (0 == strcmp(y->p, arg)) {
            s1->pe_subsystem = y->v;
            ಹಿಂತಿರುಗಿ 0;
        }
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ pe_ಗಣ_options(TCCState * s1, ರಚನೆ pe_info *pe)
{
    ಆದರೆ (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_ತಳ_DLL;
    } ಇಲ್ಲದಿದ್ದರೆ {
        pe->imagebase = IMAGE_ತಳ_EXE;
    }

#ಆದರೆ defined(TCC_ಗುರಿ_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#ಇಲ್ಲದಿದ್ದರೆ
    ಆದರೆ (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    ಇಲ್ಲದಿದ್ದರೆ
        pe->subsystem = 3;
#ಆದರೆ_ಅಂತ್ಯ
    /* Allow override via -Wl,-subsystem=... option */
    ಆದರೆ (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    ಆದರೆ (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } ಇಲ್ಲದಿದ್ದರೆ {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    ಆದರೆ (s1->section_align != 0)
        pe->section_align = s1->section_align;
    ಆದರೆ (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    ಆದರೆ ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    ಆದರೆ (s1->has_ಪಠ್ಯ_addr)
        pe->imagebase = s1->ಪಠ್ಯ_addr;
}

ST_FUNC ಪೂರ್ಣಾಂಕ pe_output_file(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    ರಚನೆ pe_info pe;

    memset(&pe, 0, ಗಾತ್ರ pe);
    pe.filename = filename;
    pe.s1 = s1;
    s1->filetype = 0;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    tcc_ಕೂಡಿಸು_bcheck(s1);
#ಆದರೆ_ಅಂತ್ಯ
    tcc_ಕೂಡಿಸು_pragma_libs(s1);
    pe_ಕೂಡಿಸು_runtime(s1, &pe);
    resolve_common_syms(s1);
    pe_ಗಣ_options(s1, &pe);
    pe_check_symbols(&pe);
    ಆದರೆ (s1->nb_errors)
        ಹೋಗು ಮುಗಿದ;
    ಆದರೆ (filename) {
        pe_ನಿಯೋಜಿಸು_ವಿಳಾಸಗಳು(&pe);
        relocate_syms(s1, s1->symtab, 0);
        ಆದರೆ (s1->nb_errors)
            ಹೋಗು ಮುಗಿದ;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.ಆರಂಭ_addr = (DWORD)
            (get_sym_addr(s1, pe.ಆರಂಭ_ಚಿಹ್ನೆ, 1, 1) - pe.imagebase);
        ಆದರೆ (s1->nb_errors)
            ಹೋಗು ಮುಗಿದ;
        pe_write(&pe);
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* -run */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
        pe.thunk = ದತ್ತಾಂಶ_section;
        pe_build_imports(&pe);
        s1->ಸತತ_main = pe.ಆರಂಭ_ಚಿಹ್ನೆ;
#ಆದರೆ defined(TCC_ಗುರಿ_X86_64) || defined(TCC_ಗುರಿ_ARM64)
        s1->uw_pdata = ಕಂಡುಹಿಡಿ_section(s1, ".pdata");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
    }
ಮುಗಿದ:
    dynarray_reset(&pe.sec_info, &pe.sec_ಎಣಿಕೆ);
    pe_free_imports(&pe);
#ಆದರೆ PE_PRINT_SECTIONS
    ಆದರೆ (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
