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

#అన్తర్భావ "tcc.h"

#నిర్వచించు PE_విలీనం_దత్తాంశం 1
#నిర్వచించు PE_PRINT_SECTIONS 0

#నిర్వచితం_కాకపోతే _WIN32
#నిర్వచించు stricmp strcasecmp
#నిర్వచించు strnicmp strncasecmp
#అన్తర్భావ <sys/stat.h> /* chmod() */
#అయితే_ముగింపు

#ఒకవేళ defined TCC_లక్ష్యం_X86_64
# define REL_TYPE_ప్రత్యక్ష R_X86_64_64
# define R_XXX_THUNKFIX R_X86_64_PC32
# define R_XXX_RELATIVE R_X86_64_RELATIVE
# define R_XXX_FUNCCALL R_X86_64_PLT32
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0x8664
# define CHARACTERISTICS_EXE 0x022F
# define CHARACTERISTICS_DLL 0x222E
# define IMAGE_పునాది_EXE 0x00400000
# define IMAGE_పునాది_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#లేదావేళ defined TCC_లక్ష్యం_ARM
# define REL_TYPE_ప్రత్యక్ష R_ARM_ABS32
# define R_XXX_THUNKFIX R_ARM_ABS32
# define R_XXX_RELATIVE R_ARM_RELATIVE
# define R_XXX_FUNCCALL R_ARM_PC24
# define R_XXX_FUNCCALL2 R_ARM_ABS32
# define RSRC_RELTYPE 7 /* ??? (not tested) */
# define IMAGE_FILE_MACHINE 0x01C0
# define CHARACTERISTICS_EXE 0x010F
# define CHARACTERISTICS_DLL 0x230F
# define IMAGE_పునాది_EXE 0x00100000
# define IMAGE_పునాది_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#లేదావేళ defined TCC_లక్ష్యం_ARM64
# define REL_TYPE_ప్రత్యక్ష R_AARCH64_ABS64
# define R_XXX_THUNKFIX R_AARCH64_ABS64
# define R_XXX_RELATIVE R_AARCH64_RELATIVE
# define R_XXX_FUNCCALL R_AARCH64_CALL26
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0xAA64
# define CHARACTERISTICS_EXE 0x0022
# define CHARACTERISTICS_DLL 0x2022
# define IMAGE_పునాది_EXE 0x140000000ULL
# define IMAGE_పునాది_DLL 0x180000000ULL
# define OS_VER 0x0602
# define DLLCHARACTERISTICS 0x8160

#లేదావేళ defined TCC_లక్ష్యం_I386
# define REL_TYPE_ప్రత్యక్ష R_386_32
# define R_XXX_THUNKFIX R_386_32
# define R_XXX_RELATIVE R_386_RELATIVE
# define R_XXX_FUNCCALL R_386_PC32
# define RSRC_RELTYPE 7 /* DIR32NB */
# define IMAGE_FILE_MACHINE 0x014C
# define CHARACTERISTICS_EXE 0x030F
# define CHARACTERISTICS_DLL 0x230E
# define IMAGE_పునాది_EXE 0x00400000
# define IMAGE_పునాది_DLL 0x10000000
# define OS_VER 0x0400
# define DLLCHARACTERISTICS 0
#అయితే_ముగింపు

#ఒకవేళ PTR_కొలత == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#లేకపోతే
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

రకనిర్వచనం గుర్తులేని అక్షరం BYTE;
రకనిర్వచనం గుర్తులేని పొట్టి మాట_3;
రకనిర్వచనం గుర్తులేని పూర్ణాంకం DWORD;
రకనిర్వచనం గుర్తులేని దీర్ఘ దీర్ఘ ULONGLONG;
#సూచన pack(నెట్టు, 1)

రకనిర్వచనం నిర్మాణం IMAGE_DOS_శీర్షిక {  /* DOS .EXE header */
    మాట_3 e_magic;         /* Magic number */
    మాట_3 e_cblp;          /* Bytes on last page of file */
    మాట_3 e_cp;            /* Pages in file */
    మాట_3 e_crlc;          /* Relocations */
    మాట_3 e_cparhdr;       /* Size of header in paragraphs */
    మాట_3 e_minalloc;      /* Minimum extra paragraphs needed */
    మాట_3 e_maxalloc;      /* Maximum extra paragraphs needed */
    మాట_3 e_ss;            /* Initial (relative) SS value */
    మాట_3 e_sp;            /* Initial SP value */
    మాట_3 e_csum;          /* Checksum */
    మాట_3 e_ip;            /* Initial IP value */
    మాట_3 e_cs;            /* Initial (relative) CS value */
    మాట_3 e_lfarlc;        /* File address of relocation table */
    మాట_3 e_ovno;          /* Overlay number */
    మాట_3 e_res[4];        /* Reserved words */
    మాట_3 e_oemid;         /* OEM identifier (for e_oeminfo) */
    మాట_3 e_oeminfo;       /* OEM information; e_oemid specific */
    మాట_3 e_res2[10];      /* Reserved words */
    DWORD e_lfanew;        /* File address of new exe header */
} IMAGE_DOS_శీర్షిక_2, *PIMAGE_DOS_శీర్షిక;

#నిర్వచించు IMAGE_NT_SIGNATURE  0x00004550  /* PE00 */

రకనిర్వచనం నిర్మాణం IMAGE_FILE_శీర్షిక {
    మాట_3    Machine;
    మాట_3    సంఖ్య_యొక్క_Sections;
    DWORD   సమయం_Date_Stamp;
    DWORD   సూచిక_గమ్యం_చిహ్నం_పట్టిక;
    DWORD   సంఖ్య_యొక్క_Symbols;
    మాట_3    కొలత_యొక్క_Optional_శీర్షిక;
    మాట_3    Characteristics;
} IMAGE_FILE_శీర్షిక_2, *PIMAGE_FILE_శీర్షిక;


#నిర్వచించు IMAGE_SIZEOF_FILE_శీర్షిక 20

రకనిర్వచనం నిర్మాణం IMAGE_దత్తాంశం_DIRECTORY {
    DWORD   Virtual_చిరునామా;
    DWORD   కొలత_3;
} IMAGE_దత్తాంశం_DIRECTORY_2, *PIMAGE_దత్తాంశం_DIRECTORY;


రకనిర్వచనం నిర్మాణం IMAGE_OPTIONAL_శీర్షిక {
    /* Standard fields. */
    మాట_3    Magic;
    BYTE    Major_Linker_సంస్కరణ;
    BYTE    Minor_Linker_సంస్కరణ;
    DWORD   కొలత_యొక్క_సంకేతం;
    DWORD   కొలత_యొక్క_Initialized_దత్తాంశం;
    DWORD   కొలత_యొక్క_Uninitialized_దత్తాంశం;
    DWORD   చిరునామా_యొక్క_నమోదు_బిందువు;
    DWORD   పునాది_యొక్క_సంకేతం;
#ఒకవేళ PTR_కొలత == 4
    DWORD   పునాది_యొక్క_దత్తాంశం;
#అయితే_ముగింపు
    /* NT additional fields. */
    ADDR3264 Image_పునాది;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    మాట_3    Major_Operating_System_సంస్కరణ;
    మాట_3    Minor_Operating_System_సంస్కరణ;
    మాట_3    Major_Image_సంస్కరణ;
    మాట_3    Minor_Image_సంస్కరణ;
    మాట_3    Major_Subsystem_సంస్కరణ;
    మాట_3    Minor_Subsystem_సంస్కరణ;
    DWORD   Win32_సంస్కరణ_విలువ;
    DWORD   కొలత_యొక్క_Image;
    DWORD   కొలత_యొక్క_శీర్షికలు;
    DWORD   Check_కూడిక;
    మాట_3    Subsystem;
    మాట_3    DllCharacteristics;
    ADDR3264 కొలత_యొక్క_దొంతర_Reserve;
    ADDR3264 కొలత_యొక్క_దొంతర_Commit;
    ADDR3264 కొలత_యొక్క_కుప్ప_Reserve;
    ADDR3264 కొలత_యొక్క_కుప్ప_Commit;
    DWORD   LoaderFlags;
    DWORD   సంఖ్య_యొక్క_Rva_And_Sizes;
    IMAGE_దత్తాంశం_DIRECTORY_2 దత్తాంశం_Directory[16];
} IMAGE_OPTIONAL_HEADER32, IMAGE_OPTIONAL_HEADER64, IMAGE_OPTIONAL_శీర్షిక_2;

#నిర్వచించు IMAGE_DIRECTORY_నమోదు_EXPORT          0   /* Export Directory */
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_IMPORT          1   /* Import Directory */
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_RESOURCE        2   /* Resource Directory */
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_EXCEPTION       3   /* Exception Directory */
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_SECURITY        4   /* Security Directory */
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_BASERELOC       5   /* Base Relocation Table */
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_DEBUG           6   /* Debug Directory */
/*      IMAGE_DIRECTORY_ENTRY_COPYRIGHT       7      (X86 usage) */
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_ARCHITECTURE    7   /* Architecture Specific Data */
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_GLOBALPTR       8   /* RVA of GP */
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_TLS             9   /* TLS Directory */
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_ఎక్కించు_CONFIG    10   /* Load Configuration Directory */
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_BOUND_IMPORT   11   /* Bound Import Directory in headers */
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_IAT            12   /* Import Address Table */
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_DELAY_IMPORT   13   /* Delay Load Import Descriptors */
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_COM_DESCRIPTOR 14   /* COM Runtime descriptor */

/* Section header format. */
#నిర్వచించు IMAGE_SIZEOF_SHORT_NAME         8

రకనిర్వచనం నిర్మాణం IMAGE_SECTION_శీర్షిక {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    సంఘం {
            DWORD   Physical_చిరునామా;
            DWORD   Virtual_కొలత;
    } Misc;
    DWORD   Virtual_చిరునామా;
    DWORD   కొలత_యొక్క_Raw_దత్తాంశం;
    DWORD   సూచిక_గమ్యం_Raw_దత్తాంశం;
    DWORD   సూచిక_గమ్యం_Relocations;
    DWORD   సూచిక_గమ్యం_Linenumbers;
    మాట_3    సంఖ్య_యొక్క_Relocations;
    మాట_3    సంఖ్య_యొక్క_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_శీర్షిక_2, *PIMAGE_SECTION_శీర్షిక;

#నిర్వచించు IMAGE_SIZEOF_SECTION_శీర్షిక     40

రకనిర్వచనం నిర్మాణం _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD సమయం_Date_Stamp;
    మాట_3 Major_సంస్కరణ;
    మాట_3 Minor_సంస్కరణ;
    DWORD Name;
    DWORD పునాది_2;
    DWORD సంఖ్య_యొక్క_Functions;
    DWORD సంఖ్య_యొక్క_పేర్లు;
    DWORD చిరునామా_యొక్క_Functions;
    DWORD చిరునామా_యొక్క_పేర్లు;
    DWORD చిరునామా_యొక్క_Name_Ordinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

రకనిర్వచనం నిర్మాణం _IMAGE_TLS_DIRECTORY {
    ADDR3264 ప్రారంభం_చిరునామా_యొక్క_Raw_దత్తాంశం;
    ADDR3264 చివర_చిరునామా_యొక్క_Raw_దత్తాంశం;
    ADDR3264 చిరునామా_యొక్క_సూచీ;
    ADDR3264 చిరునామా_యొక్క_Call_Backs;
    DWORD కొలత_యొక్క_Zero_Fill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

రకనిర్వచనం నిర్మాణం _IMAGE_IMPORT_DESCRIPTOR {
    సంఘం {
        DWORD Characteristics;
        DWORD Original_మొదటి_Thunk;
    };
    DWORD సమయం_Date_Stamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD మొదటి_Thunk;
} IMAGE_IMPORT_DESCRIPTOR;

రకనిర్వచనం నిర్మాణం IMAGE_పునాది_RELOCATION {
    DWORD   Virtual_చిరునామా;
    DWORD   కొలత_యొక్క_ఖండం;
//  WORD    TypeOffset[1];
} IMAGE_పునాది_RELOCATION_2;

#నిర్వచించు IMAGE_SIZEOF_పునాది_RELOCATION     8

#నిర్వచించు IMAGE_REL_BASED_ABSOLUTE         0
#నిర్వచించు IMAGE_REL_BASED_ఎగువ             1
#నిర్వచించు IMAGE_REL_BASED_దిగువ              2
#నిర్వచించు IMAGE_REL_BASED_HIGHLOW          3
#నిర్వచించు IMAGE_REL_BASED_HIGHADJ          4
#నిర్వచించు IMAGE_REL_BASED_MIPS_JMPADDR     5
#నిర్వచించు IMAGE_REL_BASED_SECTION          6
#నిర్వచించు IMAGE_REL_BASED_REL32            7
#నిర్వచించు IMAGE_REL_BASED_DIR64           10

#నిర్వచించు IMAGE_SCN_CNT_సంకేతం                  0x00000020
#నిర్వచించు IMAGE_SCN_CNT_INITIALIZED_దత్తాంశం      0x00000040
#నిర్వచించు IMAGE_SCN_CNT_UNINITIALIZED_దత్తాంశం    0x00000080
#నిర్వచించు IMAGE_SCN_MEM_DISCARDABLE           0x02000000
#నిర్వచించు IMAGE_SCN_MEM_SHARED                0x10000000
#నిర్వచించు IMAGE_SCN_MEM_EXECUTE               0x20000000
#నిర్వచించు IMAGE_SCN_MEM_READ                  0x40000000
#నిర్వచించు IMAGE_SCN_MEM_WRITE                 0x80000000

#నిర్వచించు IMAGE_DLLCHARACTERISTICS_ఎగువ_ENTROPY_VA 0x0020
#నిర్వచించు IMAGE_DLLCHARACTERISTICS_DYNAMIC_పునాది 0x0040
#నిర్వచించు IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#నిర్వచించు IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#నిర్వచించు IMAGE_FILE_RELOCS_STRIPPED 0x0001

#సూచన pack(తీయి)

/* ----------------------------------------------------------- */
#అయితే_ముగింపు /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#నిర్వచితం_కాకపోతే IMAGE_DLLCHARACTERISTICS_DYNAMIC_పునాది
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #నిర్వచించు IMAGE_DLLCHARACTERISTICS_DYNAMIC_పునాది 0x0040
#అయితే_ముగింపు

#సూచన pack(నెట్టు, 1)
నిర్మాణం pe_శీర్షిక
{
    IMAGE_DOS_శీర్షిక_2 doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_శీర్షిక_2 filehdr;
#ఒకవేళ PTR_కొలత == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#లేకపోతే
#నిర్వచితమైతే _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#లేకపోతే
    IMAGE_OPTIONAL_శీర్షిక_2 opthdr;
#అయితే_ముగింపు
#అయితే_ముగింపు
};

నిర్మాణం pe_reloc_శీర్షిక {
    DWORD స్థానభ్రంశం;
    DWORD కొలత;
};

నిర్మాణం pe_rsrc_శీర్షిక {
    నిర్మాణం IMAGE_FILE_శీర్షిక filehdr;
    నిర్మాణం IMAGE_SECTION_శీర్షిక sectionhdr;
};

నిర్మాణం pe_rsrc_reloc {
    DWORD స్థానభ్రంశం;
    DWORD కొలత;
    మాట_3 type;
};
#సూచన pack(తీయి)

/* ------------------------------------------------------------- */
/* internal temporary structures */

గణన {
    sec_పాఠ్యం = 0,
    sec_rdata ,
    sec_దత్తాంశం ,
    sec_bss ,
    sec_idata ,
    sec_pdata ,
    sec_tdata ,
    sec_tbss ,
    sec_other ,
    sec_rsrc ,
    sec_debug ,
    sec_reloc ,
    sec_చివరి
};

#ఒకవేళ 0
స్థిర స్థిరరాశి DWORD pe_sec_flags[] = {
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
#అయితే_ముగింపు

నిర్మాణం section_info {
    పూర్ణాంకం cls;
    అక్షరం name[32];
    ADDR3264 sh_addr;
    DWORD sh_కొలత;
    DWORD pe_flags;
    Section *sec;
    DWORD దత్తాంశం_కొలత;
    IMAGE_SECTION_శీర్షిక_2 ish;
};

నిర్మాణం import_చిహ్నం {
    పూర్ణాంకం sym_సూచీ;
    పూర్ణాంకం iat_సూచీ;
    పూర్ణాంకం thk_స్థానభ్రంశం;
};

నిర్మాణం pe_import_info {
    పూర్ణాంకం dll_సూచీ;
    పూర్ణాంకం sym_లెక్క;
    నిర్మాణం import_చిహ్నం **symbols;
};

నిర్మాణం pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    స్థిరరాశి అక్షరం *filename;
    పూర్ణాంకం type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    స్థిరరాశి అక్షరం *ప్రారంభం_చిహ్నం;
    DWORD ప్రారంభం_addr;
    DWORD imp_offs;
    DWORD imp_కొలత;
    DWORD iat_offs;
    DWORD iat_కొలత;
    DWORD exp_offs;
    DWORD exp_కొలత;
    DWORD tls_dir;
    DWORD tls_దత్తాంశం;
    DWORD tls_కొలత;
    పూర్ణాంకం subsystem;
    DWORD section_align;
    DWORD file_align;
    నిర్మాణం section_info **sec_info;
    పూర్ణాంకం sec_లెక్క;
    నిర్మాణం pe_import_info **imp_info;
    పూర్ణాంకం imp_లెక్క;
    /* output */
    FILE *op;
    DWORD కూడిక;
    గుర్తులేని pos;
};

#నిర్వచించు PE_NUL 0
#నిర్వచించు PE_DLL 1
#నిర్వచించు PE_GUI 2
#నిర్వచించు PE_EXE 3
#నిర్వచించు PE_నిరంతరం 4

/* --------------------------------------------*/

స్థిర స్థిరరాశి అక్షరం *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    స్థిరరాశి అక్షరం *name = (అక్షరం*)symtab_section->link->దత్తాంశం + sym->st_name;
    ఒకవేళ (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        తిరిగి name + 1;
    తిరిగి name;
}


స్థిర పూర్ణాంకం dynarray_assoc(శూన్య **pp, పూర్ణాంకం n, పూర్ణాంకం కీలకం)
{
    పూర్ణాంకం i;
    కొరకు (i = 0; i < n; ++i, ++pp)
    ఒకవేళ (కీలకం == **(పూర్ణాంకం **) pp)
        తిరిగి i;
    తిరిగి -1;
}

స్థిర DWORD umin(DWORD a, DWORD b)
{
    తిరిగి a < b ? a : b;
}

స్థిర DWORD umax(DWORD a, DWORD b)
{
    తిరిగి a < b ? b : a;
}

స్థిర DWORD pe_file_align(నిర్మాణం pe_info *pe, DWORD n)
{
    తిరిగి (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

స్థిర ADDR3264 pe_virtual_align(నిర్మాణం pe_info *pe, ADDR3264 n)
{
    తిరిగి (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

స్థిర శూన్య pe_align_section(Section *s, పూర్ణాంకం a)
{
    పూర్ణాంకం i = s->దత్తాంశం_స్థానభ్రంశం & (a-1);
    ఒకవేళ (i)
        section_ptr_కూడు(s, a - i);
}

స్థిర శూన్య pe_సమితి_datadir(నిర్మాణం pe_శీర్షిక *hdr, పూర్ణాంకం dir, DWORD addr, DWORD కొలత)
{
    hdr->opthdr.దత్తాంశం_Directory[dir].Virtual_చిరునామా = addr;
    hdr->opthdr.దత్తాంశం_Directory[dir].కొలత_3 = కొలత;
}

స్థిర పూర్ణాంకం pe_fwrite(నిర్మాణం pe_info *pe, స్థిరరాశి శూన్య *దత్తాంశం, పూర్ణాంకం len)
{
    స్థిరరాశి మాట_3 *p = దత్తాంశం;
    DWORD కూడిక;
    పూర్ణాంకం ret, i;
    pe->pos += (ret = fwrite(దత్తాంశం, 1, len, pe->op));
    కూడిక = pe->కూడిక;
    కొరకు (i = len; i > 0; i -= 2) {
        కూడిక += (i >= 2) ? *p++ : *(BYTE*)p;
        కూడిక = (కూడిక + (కూడిక >> 16)) & 0xFFFF;
    }
    pe->కూడిక = కూడిక;
    తిరిగి len == ret ? 0 : -1;
}

స్థిర శూన్య pe_fpad(నిర్మాణం pe_info *pe, DWORD new_pos)
{
    అక్షరం buf[256];
    పూర్ణాంకం n, diff = new_pos - pe->pos;
    memset(buf, 0, పరిమాణం buf);
    అయితే (diff > 0) {
        diff -= n = umin(diff, పరిమాణం buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#సూచన pack(నెట్టు, 1)
నిర్మాణం syment
{
    సంఘం {
        అక్షరం        n_name[8];     /* old COFF version */
        నిర్మాణం {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_స్థానభ్రంశం_2;      /* offset into string table */
        };
    };
    int32_t         n_విలువ;        /* value of symbol */
    పొట్టి           n_scnum;        /* section number */
    గుర్తులేని పొట్టి  n_type;         /* type and derived type */
    అక్షరం            n_sclass;       /* storage class */
    అక్షరం            n_numaux;       /* number of aux. entries */
};
#సూచన pack(తీయి)

#నిర్వచించు SHF_వ్యక్తిగత 0x80000000

స్థిర శూన్య pe_కూడు_coffsym(నిర్మాణం pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    నిర్మాణం syment *se;
    పూర్ణాంకం n;

    ఒకవేళ (ఖాళీ == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_వ్యక్తిగత);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_వ్యక్తిగత);
        section_ptr_కూడు(pe->coffstr, 4); /* coff string table size */
        తిరిగి;
    }

#ఒకవేళ 0
    se = section_ptr_కూడు(pe->coffsym, పరిమాణం *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_కూడు(pe->coffsym, పరిమాణం *se);
    strcpy((అక్షరం*)se, "no-file");
#అయితే_ముగింపు

#ఒకవేళ 1
    esym = (ElfSym*)s1->symtab->దత్తాంశం;
    కొరకు (n = s1->symtab->దత్తాంశం_స్థానభ్రంశం / పరిమాణం *esym; ++esym, --n;) {
        పూర్ణాంకం sym_bind = ELFW(ST_BIND)(esym->st_info);
        ఒకవేళ (sym_bind == STB_GLOBAL) {
            అక్షరం *name = esym->st_name + (అక్షరం*)s1->symtab->link->దత్తాంశం;
            పూర్ణాంకం nl = అక్షరశ్రేణి_పొడవు(name);
            addr_t విలువ = esym->st_విలువ;
            పూర్ణాంకం shnum = esym->st_shndx;
            ఒకవేళ (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                విలువ = విలువ - s->sh_addr;
            }
            se = section_ptr_కూడు(pe->coffsym, పరిమాణం *se);
            se->n_విలువ = విలువ;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            ఒకవేళ (nl <= 8)
                జ్ఞాపకం_నకలు(se->n_name, name, nl);
            లేకపోతే
                se->n_స్థానభ్రంశం_2 = put_elf_str(pe->coffstr, name);
        }
    }
#అయితే_ముగింపు
    write32le(pe->coffstr->దత్తాంశం, pe->coffstr->దత్తాంశం_స్థానభ్రంశం); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
స్థిర శూన్య pe_create_pdb(TCCState *s1, స్థిరరాశి అక్షరం *exename)
{
    అక్షరం buf[300]; పూర్ణాంకం r;
    snprintf(buf, పరిమాణం buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    strcpy(tcc_fileextension(strcpy(buf, exename)), ".pdb");
    ఒకవేళ (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } లేకపోతే ఒకవేళ (s1->verbose) {
        రాయి("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
స్థిర పూర్ణాంకం pe_write(నిర్మాణం pe_info *pe)
{
    స్థిర స్థిరరాశి నిర్మాణం pe_శీర్షిక pe_template = {
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
    0x00E0 + (PTR_కొలత-4)*4, /*WORD    SizeOfOptionalHeader; */
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
#ఒకవేళ PTR_కొలత == 4
    0x00000000, /*DWORD   BaseOfData; */
#అయితే_ముగింపు
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

    నిర్మాణం pe_శీర్షిక pe_శీర్షిక = pe_template;

    పూర్ణాంకం i;
    DWORD file_స్థానభ్రంశం;
    నిర్మాణం section_info *si;
    IMAGE_SECTION_శీర్షిక_2 *psh;
    TCCState *s1 = pe->s1;

    ఒకవేళ (s1->do_debug)
        pe_కూడు_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    ఒకవేళ (ఖాళీ == pe->op)
        తిరిగి tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        పరిమాణం (నిర్మాణం pe_శీర్షిక)
        + pe->sec_లెక్క * పరిమాణం (IMAGE_SECTION_శీర్షిక_2)
        );

    file_స్థానభ్రంశం = pe->sizeofheaders;

    ఒకవేళ (2 == s1->verbose)
        రాయి("-------------------------------"
               "\n  virt   file   size  section" "\n");
    కొరకు (i = 0; i < pe->sec_లెక్క; ++i) {
        DWORD addr, కొలత;
        స్థిరరాశి అక్షరం *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        కొలత = si->sh_కొలత;
        psh = &si->ish;

        ఒకవేళ (2 == s1->verbose)
            రాయి("%6x %6x %6x  %s\n",
                (గుర్తులేని)addr, (గుర్తులేని)file_స్థానభ్రంశం, (గుర్తులేని)కొలత, sh_name);

        ఎంపిక (si->cls) {
            స్థితి sec_పాఠ్యం:
                ఒకవేళ (!pe_శీర్షిక.opthdr.పునాది_యొక్క_సంకేతం)
                    pe_శీర్షిక.opthdr.పునాది_యొక్క_సంకేతం = addr;
                ఆపు;

            స్థితి sec_దత్తాంశం:
#ఒకవేళ PTR_కొలత == 4
                ఒకవేళ (!pe_శీర్షిక.opthdr.పునాది_యొక్క_దత్తాంశం)
                    pe_శీర్షిక.opthdr.పునాది_యొక్క_దత్తాంశం = addr;
#అయితే_ముగింపు
                ఆపు;

            స్థితి sec_bss:
                ఆపు;

            స్థితి sec_reloc:
                pe_సమితి_datadir(&pe_శీర్షిక, IMAGE_DIRECTORY_నమోదు_BASERELOC, addr, కొలత);
                ఆపు;

            స్థితి sec_rsrc:
                pe_సమితి_datadir(&pe_శీర్షిక, IMAGE_DIRECTORY_నమోదు_RESOURCE, addr, కొలత);
                ఆపు;

            స్థితి sec_pdata:
                pe_సమితి_datadir(&pe_శీర్షిక, IMAGE_DIRECTORY_నమోదు_EXCEPTION, addr, కొలత);
                ఆపు;
        }

        ఒకవేళ (pe->imp_కొలత) {
            pe_సమితి_datadir(&pe_శీర్షిక, IMAGE_DIRECTORY_నమోదు_IMPORT,
                pe->imp_offs, pe->imp_కొలత);
            pe_సమితి_datadir(&pe_శీర్షిక, IMAGE_DIRECTORY_నమోదు_IAT,
                pe->iat_offs, pe->iat_కొలత);
        }
        ఒకవేళ (pe->exp_కొలత) {
            pe_సమితి_datadir(&pe_శీర్షిక, IMAGE_DIRECTORY_నమోదు_EXPORT,
                pe->exp_offs, pe->exp_కొలత);
        }
        ఒకవేళ (pe->tls_కొలత) {
            pe_సమితి_datadir(&pe_శీర్షిక, IMAGE_DIRECTORY_నమోదు_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_కొలత);
        }

        జ్ఞాపకం_నకలు(psh->Name, sh_name, umin(అక్షరశ్రేణి_పొడవు(sh_name), పరిమాణం psh->Name));
        ఒకవేళ (pe->coffstr && అక్షరశ్రేణి_పొడవు(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((అక్షరం*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->Virtual_చిరునామా = addr;
        psh->Misc.Virtual_కొలత = కొలత;
        pe_శీర్షిక.opthdr.కొలత_యొక్క_Image =
            umax(pe_virtual_align(pe, కొలత + addr), pe_శీర్షిక.opthdr.కొలత_యొక్క_Image);

        ఒకవేళ (si->దత్తాంశం_కొలత) {
            psh->సూచిక_గమ్యం_Raw_దత్తాంశం = file_స్థానభ్రంశం;
            file_స్థానభ్రంశం = pe_file_align(pe, file_స్థానభ్రంశం + si->దత్తాంశం_కొలత);
            psh->కొలత_యొక్క_Raw_దత్తాంశం = file_స్థానభ్రంశం - psh->సూచిక_గమ్యం_Raw_దత్తాంశం;
            ఒకవేళ (si->cls == sec_పాఠ్యం)
                pe_శీర్షిక.opthdr.కొలత_యొక్క_సంకేతం += psh->కొలత_యొక్క_Raw_దత్తాంశం;
            లేకపోతే
                pe_శీర్షిక.opthdr.కొలత_యొక్క_Initialized_దత్తాంశం += psh->కొలత_యొక్క_Raw_దత్తాంశం;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_శీర్షిక.filehdr.సంఖ్య_యొక్క_Sections = pe->sec_లెక్క;
    pe_శీర్షిక.opthdr.చిరునామా_యొక్క_నమోదు_బిందువు = pe->ప్రారంభం_addr;
    pe_శీర్షిక.opthdr.కొలత_యొక్క_శీర్షికలు = pe->sizeofheaders;
    pe_శీర్షిక.opthdr.Image_పునాది = pe->imagebase;
    pe_శీర్షిక.opthdr.Subsystem = pe->subsystem;
    pe_శీర్షిక.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    ఒకవేళ (s1->pe_దొంతర_కొలత)
        pe_శీర్షిక.opthdr.కొలత_యొక్క_దొంతర_Reserve = s1->pe_దొంతర_కొలత;
    ఒకవేళ (PE_DLL == pe->type)
        pe_శీర్షిక.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_శీర్షిక.filehdr.Characteristics |= s1->pe_characteristics;
    ఒకవేళ (pe->reloc)
        pe_శీర్షిక.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    ఒకవేళ (pe->coffsym) {
        pe_కూడు_coffsym(pe);
        pe_శీర్షిక.filehdr.సూచిక_గమ్యం_చిహ్నం_పట్టిక = file_స్థానభ్రంశం;
        pe_శీర్షిక.filehdr.సంఖ్య_యొక్క_Symbols
            = pe->coffsym->దత్తాంశం_స్థానభ్రంశం / పరిమాణం (నిర్మాణం syment);
    }

    pe_fwrite(pe, &pe_శీర్షిక, పరిమాణం pe_శీర్షిక);
    కొరకు (i = 0; i < pe->sec_లెక్క; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, పరిమాణం(IMAGE_SECTION_శీర్షిక_2));

    file_స్థానభ్రంశం = pe->sizeofheaders;
    కొరకు (i = 0; i < pe->sec_లెక్క; ++i) {
        Section *s;
        si = pe->sec_info[i];
        ఒకవేళ (!si->దత్తాంశం_కొలత)
            కొనసాగు;
        కొరకు (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_స్థానభ్రంశం);
            pe_fwrite(pe, s->దత్తాంశం, s->దత్తాంశం_స్థానభ్రంశం);
            ఒకవేళ (s->prev)
                file_స్థానభ్రంశం += s->prev->sh_addr - s->sh_addr;
        }
        file_స్థానభ్రంశం = si->ish.సూచిక_గమ్యం_Raw_దత్తాంశం + si->ish.కొలత_యొక్క_Raw_దత్తాంశం;
        pe_fpad(pe, file_స్థానభ్రంశం);
    }

    ఒకవేళ (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->దత్తాంశం, pe->coffsym->దత్తాంశం_స్థానభ్రంశం);
        pe_fwrite(pe, pe->coffstr->దత్తాంశం, pe->coffstr->దత్తాంశం_స్థానభ్రంశం);
        file_స్థానభ్రంశం = pe->pos;
    }

    pe->కూడిక += file_స్థానభ్రంశం;
    fseek(pe->op, offsetof(నిర్మాణం pe_శీర్షిక, opthdr.Check_కూడిక), SEEK_SET);
    pe_fwrite(pe, &pe->కూడిక, పరిమాణం (DWORD));

    fclose (pe->op);
#నిర్వచితం_కాకపోతే _WIN32
    chmod(pe->filename, 0777);
#అయితే_ముగింపు

    ఒకవేళ (2 == s1->verbose)
        రాయి("-------------------------------\n");
    ఒకవేళ (s1->verbose)
        రాయి("<- %s (%u bytes)\n", pe->filename, (గుర్తులేని)file_స్థానభ్రంశం);

    ఒకవేళ (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    తిరిగి 0;
}

/*----------------------------------------------------------------------------*/

స్థిర నిర్మాణం import_చిహ్నం *pe_కూడు_import(నిర్మాణం pe_info *pe, పూర్ణాంకం sym_సూచీ)
{
    పూర్ణాంకం i;
    పూర్ణాంకం dll_సూచీ;
    నిర్మాణం pe_import_info *p;
    నిర్మాణం import_చిహ్నం *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->దత్తాంశం + sym_సూచీ;
    dll_సూచీ = isym->st_కొలత;

    i = dynarray_assoc ((శూన్య**)pe->imp_info, pe->imp_లెక్క, dll_సూచీ);
    ఒకవేళ (-1 != i) {
        p = pe->imp_info[i];
        వెళ్ళు దొరికింది_dll;
    }
    p = tcc_mallocz(పరిమాణం *p);
    p->dll_సూచీ = dll_సూచీ;
    dynarray_కూడు(&pe->imp_info, &pe->imp_లెక్క, p);

దొరికింది_dll:
    i = dynarray_assoc ((శూన్య**)p->symbols, p->sym_లెక్క, sym_సూచీ);
    ఒకవేళ (-1 != i)
        తిరిగి p->symbols[i];

    s = tcc_mallocz(పరిమాణం *s);
    dynarray_కూడు(&p->symbols, &p->sym_లెక్క, s);
    s->sym_సూచీ = sym_సూచీ;
    తిరిగి s;
}

స్థిర శూన్య pe_free_imports(నిర్మాణం pe_info *pe)
{
    పూర్ణాంకం i;
    కొరకు (i = 0; i < pe->imp_లెక్క; ++i) {
        నిర్మాణం pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_లెక్క);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_లెక్క);
}

/*----------------------------------------------------------------------------*/
స్థిర శూన్య pe_build_imports(నిర్మాణం pe_info *pe)
{
    పూర్ణాంకం thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_పునాది = pe->thunk->sh_addr - pe->imagebase;
    పూర్ణాంకం ndlls = pe->imp_లెక్క;
    TCCState *s1 = pe->s1;

    కొరకు (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_లెక్క;

    ఒకవేళ (0 == sym_cnt)
        తిరిగి;

    pe_align_section(pe->thunk, 16);
    pe->imp_కొలత = (ndlls + 1) * పరిమాణం(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_కొలత = (sym_cnt + ndlls) * పరిమాణం(ADDR3264);
    dll_ptr = pe->thunk->దత్తాంశం_స్థానభ్రంశం;
    thk_ptr = dll_ptr + pe->imp_కొలత;
    ent_ptr = thk_ptr + pe->iat_కొలత;
    pe->imp_offs = dll_ptr + rva_పునాది;
    pe->iat_offs = thk_ptr + rva_పునాది;
    section_ptr_కూడు(pe->thunk, pe->imp_కొలత + 2*pe->iat_కొలత);

    కొరకు (i = 0; i < pe->imp_లెక్క; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        పూర్ణాంకం k, n, dllindex;
        ADDR3264 v;
        నిర్మాణం pe_import_info *p = pe->imp_info[i];
        స్థిరరాశి అక్షరం *name;
        DLLReference *dllref;

        dllindex = p->dll_సూచీ;
        ఒకవేళ (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        లేకపోతే
            name = "", dllref = ఖాళీ;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->దత్తాంశం + dll_ptr);
        hdr->మొదటి_Thunk = thk_ptr + rva_పునాది;
        hdr->Original_మొదటి_Thunk = ent_ptr + rva_పునాది;
        hdr->Name = v + rva_పునాది;

        కొరకు (k = 0, n = p->sym_లెక్క; k <= n; ++k) {
            ఒకవేళ (k < n) {
                పూర్ణాంకం iat_సూచీ = p->symbols[k]->iat_సూచీ;
                పూర్ణాంకం sym_సూచీ = p->symbols[k]->sym_సూచీ;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->దత్తాంశం + sym_సూచీ;
                స్థిరరాశి అక్షరం *name = (అక్షరం*)s1->dynsymtab_section->link->దత్తాంశం + imp_sym->st_name;
                పూర్ణాంకం ordinal;

                /* patch symbol (and possibly its underscored alias) */
                చేయి {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->దత్తాంశం + iat_సూచీ;
                    iat_సూచీ = esym->st_విలువ;
                    esym->st_విలువ = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_అంకె;
                } అయితే (iat_సూచీ);

                ఒకవేళ (dllref)
                    v = 0, ordinal = imp_sym->st_విలువ; /* ordinal from pe_load_def */
                లేకపోతే
                    ordinal = 0, v = imp_sym->st_విలువ; /* address from tcc_add_symbol() */

#నిర్వచితమైతే TCC_IS_NATIVE
                ఒకవేళ (pe->type == PE_నిరంతరం) {
                    ఒకవేళ (dllref) {
                        ఒకవేళ ( !dllref->handle )
                            dllref->handle = ఎక్కించు_Library_A(dllref->name);
                        v = (ADDR3264)Get_Proc_చిరునామా(dllref->handle, ordinal?(అక్షరం*)0+ordinal:name);
                    }
                    ఒకవేళ (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } లేకపోతే
#అయితే_ముగింపు
                ఒకవేళ (ordinal) {
                    v = ordinal | (ADDR3264)1 << (పరిమాణం(ADDR3264)*8 - 1);
                } లేకపోతే {
                    v = pe->thunk->దత్తాంశం_స్థానభ్రంశం + rva_పునాది;
                    section_ptr_కూడు(pe->thunk, పరిమాణం(మాట_3)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } లేకపోతే {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->దత్తాంశం+thk_ptr) =
            *(ADDR3264*)(pe->thunk->దత్తాంశం+ent_ptr) = v;
            thk_ptr += పరిమాణం (ADDR3264);
            ent_ptr += పరిమాణం (ADDR3264);
        }
        dll_ptr += పరిమాణం(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

నిర్మాణం pe_క్రమీకరించు_sym
{
    పూర్ణాంకం సూచీ;
    స్థిరరాశి అక్షరం *name;
};

స్థిర పూర్ణాంకం sym_cmp(స్థిరరాశి శూన్య *va, స్థిరరాశి శూన్య *vb)
{
    స్థిరరాశి అక్షరం *ca = (*(నిర్మాణం pe_క్రమీకరించు_sym**)va)->name;
    స్థిరరాశి అక్షరం *cb = (*(నిర్మాణం pe_క్రమీకరించు_sym**)vb)->name;
    తిరిగి strcmp(ca, cb);
}

స్థిర శూన్య pe_build_exports(నిర్మాణం pe_info *pe)
{
    ElfW(Sym) *sym;
    పూర్ణాంకం sym_సూచీ, sym_చివర;
    DWORD rva_పునాది, పునాది_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    పూర్ణాంకం sym_లెక్క, ord;
    నిర్మాణం pe_క్రమీకరించు_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    అక్షరం buf[260];
    స్థిరరాశి అక్షరం *dllname;
    స్థిరరాశి అక్షరం *name;

    rva_పునాది = pe->thunk->sh_addr - pe->imagebase;
    sym_లెక్క = 0, sorted = ఖాళీ, op = ఖాళీ;

    sym_చివర = symtab_section->దత్తాంశం_స్థానభ్రంశం / పరిమాణం(ElfW(Sym));
    కొరకు (sym_సూచీ = 1; sym_సూచీ < sym_చివర; ++sym_సూచీ) {
        sym = (ElfW(Sym)*)symtab_section->దత్తాంశం + sym_సూచీ;
        name = pe_export_name(s1, sym);
        ఒకవేళ (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(పరిమాణం *p);
            p->సూచీ = sym_సూచీ;
            p->name = name;
            dynarray_కూడు(&sorted, &sym_లెక్క, p);
        }
#ఒకవేళ 0
        ఒకవేళ (sym->st_other & ST_PE_EXPORT)
            రాయి("export: %s\n", name);
        ఒకవేళ (sym->st_other & ST_PE_STDCALL)
            రాయి("stdcall: %s\n", name);
#అయితే_ముగింపు
    }

    ఒకవేళ (0 == sym_లెక్క)
        తిరిగి;

    qsort (sorted, sym_లెక్క, పరిమాణం *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    పునాది_o = pe->thunk->దత్తాంశం_స్థానభ్రంశం;
    func_o = పునాది_o + పరిమాణం(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_లెక్క * పరిమాణం (DWORD);
    ord_o = name_o + sym_లెక్క * పరిమాణం (DWORD);
    str_o = ord_o + sym_లెక్క * పరిమాణం(మాట_3);

    hdr = section_ptr_కూడు(pe->thunk, str_o - పునాది_o);
    hdr->Characteristics        = 0;
    hdr->పునాది_2                   = 1;
    hdr->సంఖ్య_యొక్క_Functions      = sym_లెక్క;
    hdr->సంఖ్య_యొక్క_పేర్లు          = sym_లెక్క;
    hdr->చిరునామా_యొక్క_Functions     = func_o + rva_పునాది;
    hdr->చిరునామా_యొక్క_పేర్లు         = name_o + rva_పునాది;
    hdr->చిరునామా_యొక్క_Name_Ordinals  = ord_o + rva_పునాది;
    hdr->Name                   = str_o + rva_పునాది;
    put_elf_str(pe->thunk, dllname);

#ఒకవేళ 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, పరిమాణం buf, pe->filename);
    strcpy(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    ఒకవేళ (ఖాళీ == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } లేకపోతే {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        ఒకవేళ (s1->verbose)
            రాయి("<- %s (%d symbol%s)\n", buf, sym_లెక్క, &"s"[sym_లెక్క < 2]);
    }
#అయితే_ముగింపు

    కొరకు (ord = 0; ord < sym_లెక్క; ++ord)
    {
        p = sorted[ord], sym_సూచీ = p->సూచీ, name = p->name;
        /* insert actual address later in relocate_sections() */
        put_elf_reloc(symtab_section, pe->thunk,
            func_o, R_XXX_RELATIVE, sym_సూచీ);
        *(DWORD*)(pe->thunk->దత్తాంశం + name_o)
            = pe->thunk->దత్తాంశం_స్థానభ్రంశం + rva_పునాది;
        *(మాట_3*)(pe->thunk->దత్తాంశం + ord_o)
            = ord;
        put_elf_str(pe->thunk, name);
        func_o += పరిమాణం (DWORD);
        name_o += పరిమాణం (DWORD);
        ord_o += పరిమాణం (మాట_3);
        ఒకవేళ (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = పునాది_o + rva_పునాది;
    pe->exp_కొలత = pe->thunk->దత్తాంశం_స్థానభ్రంశం - పునాది_o;
    dynarray_reset(&sorted, &sym_లెక్క);
    ఒకవేళ (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
స్థిర శూన్య pe_build_reloc (నిర్మాణం pe_info *pe)
{
    DWORD స్థానభ్రంశం, ఖండం_ptr, sh_addr, addr;
    పూర్ణాంకం లెక్క_2, i;
    ElfW_Rel *rel, *rel_చివర;
    Section *s = ఖాళీ, *sr;
    నిర్మాణం pe_reloc_శీర్షిక *hdr;
    TCCState *s1 = pe->s1;
    పూర్ణాంకం dwarf = 0, n;

    sh_addr = స్థానభ్రంశం = ఖండం_ptr = లెక్క_2 = i = 0;
    rel = rel_చివర = ఖాళీ;

    కొరకు(;;) {
        ఒకవేళ (rel < rel_చివర) {
            పూర్ణాంకం type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_స్థానభ్రంశం + sh_addr;
            ++ rel;
            ఒకవేళ (type != REL_TYPE_ప్రత్యక్ష)
                కొనసాగు;
            ఒకవేళ (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->దత్తాంశం + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                ఒకవేళ (n >= s1->dwlo && n < s1->dwhi)
                    కొనసాగు;
            }
            ఒకవేళ (లెక్క_2 == 0) { /* new block */
                ఖండం_ptr = pe->reloc->దత్తాంశం_స్థానభ్రంశం;
                section_ptr_కూడు(pe->reloc, పరిమాణం(నిర్మాణం pe_reloc_శీర్షిక));
                స్థానభ్రంశం = addr & 0xFFFFFFFF<<12;
            }
            ఒకవేళ ((addr -= స్థానభ్రంశం)  < (1<<12)) { /* one block spans 4k addresses */
                మాట_3 *wp = section_ptr_కూడు(pe->reloc, పరిమాణం (మాట_3));
                *wp = addr | PE_IMAGE_REL<<12;
                ++లెక్క_2;
                కొనసాగు;
            }
            -- rel;

        } లేకపోతే ఒకవేళ (s) {
            sr = s->reloc;
            ఒకవేళ (sr) {
                rel = (ElfW_Rel *)sr->దత్తాంశం;
                rel_చివర = (ElfW_Rel *)(sr->దత్తాంశం + sr->దత్తాంశం_స్థానభ్రంశం);
                sh_addr = s->sh_addr;
                dwarf = s->sh_అంకె >= s1->dwlo && s->sh_అంకె < s1->dwhi;
            }
            s = s->prev;
            కొనసాగు;

        } లేకపోతే ఒకవేళ (i < pe->sec_లెక్క) {
            s = pe->sec_info[i]->sec, ++i;
            కొనసాగు;

        } లేకపోతే ఒకవేళ (!లెక్క_2)
            ఆపు;

        /* fill the last block and ready for a new one */
        ఒకవేళ (లెక్క_2 & 1) /* align for DWORDS */
            section_ptr_కూడు(pe->reloc, పరిమాణం(మాట_3)), ++లెక్క_2;
        hdr = (నిర్మాణం pe_reloc_శీర్షిక *)(pe->reloc->దత్తాంశం + ఖండం_ptr);
        hdr -> స్థానభ్రంశం = స్థానభ్రంశం - pe->imagebase;
        hdr -> కొలత = లెక్క_2 * పరిమాణం(మాట_3) + పరిమాణం(నిర్మాణం pe_reloc_శీర్షిక);
        లెక్క_2 = 0;
    }
}

/* ------------------------------------------------------------- */
స్థిర శూన్య pe_build_tls(నిర్మాణం pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    పూర్ణాంకం c, n;

    ఒకవేళ (0 == s) {
        pe->tls_కొలత = పరిమాణం (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_కూడు(pe->thunk, pe->tls_కొలత, 16);
        pe->tls_దత్తాంశం = section_కూడు(దత్తాంశం_section, PTR_కొలత * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, దత్తాంశం_section->sh_అంకె, 0);
        కొరకు (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_కొలత*n, REL_TYPE_ప్రత్యక్ష, c);
        /* for generators */
        సమితి_elf_sym(symtab_section, pe->tls_దత్తాంశం, PTR_కొలత * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, దత్తాంశం_section->sh_అంకె, "__tls_index");
        తిరిగి;
    }

    ఒకవేళ (0 == s1->tls_ప్రారంభం)
        s1->tls_ప్రారంభం = s->sh_addr;
    d = (శూన్య*)(pe->thunk->దత్తాంశం + pe->tls_dir);
    d->ప్రారంభం_చిరునామా_యొక్క_Raw_దత్తాంశం = s1->tls_ప్రారంభం - దత్తాంశం_section->sh_addr;
    d->చివర_చిరునామా_యొక్క_Raw_దత్తాంశం = s->sh_addr + s->దత్తాంశం_స్థానభ్రంశం - దత్తాంశం_section->sh_addr;
    d->చిరునామా_యొక్క_సూచీ = pe->tls_దత్తాంశం;
    d->చిరునామా_యొక్క_Call_Backs = pe->tls_దత్తాంశం + PTR_కొలత;
    d->కొలత_యొక్క_Zero_Fill = 0;
    d->Characteristics = 0;
    /* to reuse logic from linux in xxx-link.c */
    s1->tls_చివర = s1->tls_ప్రారంభం;
}

/* ------------------------------------------------------------- */
స్థిర పూర్ణాంకం pe_section_class(Section *s)
{
    పూర్ణాంకం type, flags;
    స్థిరరాశి అక్షరం *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    ఒకవేళ (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        తిరిగి sec_debug;
    } లేకపోతే ఒకవేళ (flags & SHF_ALLOC) {
        ఒకవేళ (flags & SHF_TLS)
            తిరిగి sec_tdata + (type == SHT_NOBITS);
        ఒకవేళ (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            ఒకవేళ (flags & SHF_EXECINSTR)
                తిరిగి sec_పాఠ్యం;
            ఒకవేళ (flags & SHF_WRITE)
                తిరిగి sec_దత్తాంశం;
            ఒకవేళ (0 == strcmp(name, ".rsrc"))
                తిరిగి sec_rsrc;
            ఒకవేళ (0 == strcmp(name, ".iedat"))
                తిరిగి sec_idata;
            ఒకవేళ (0 == strcmp(name, ".pdata"))
                తిరిగి sec_pdata;
            తిరిగి sec_rdata;
        } లేకపోతే ఒకవేళ (type == SHT_NOBITS) {
            తిరిగి sec_bss;
        }
        తిరిగి sec_other;
    } లేకపోతే {
        ఒకవేళ (0 == strcmp(name, ".reloc"))
            తిరిగి sec_reloc;
    }
    తిరిగి sec_చివరి;
}

స్థిర పూర్ణాంకం pe_కేటాయించు_చిరునామాలు (నిర్మాణం pe_info *pe)
{
    పూర్ణాంకం i, k, n, c, nbs;
    ADDR3264 addr;
    పూర్ణాంకం *sec_క్రమం, *sec_cls;
    నిర్మాణం section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    ఒకవేళ (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_పునాది))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_క్రమం = tcc_mallocz(2 * పరిమాణం (పూర్ణాంకం) * nbs);
    sec_cls = sec_క్రమం + nbs;
    కొరకు (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        కొరకు (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_క్రమం[n] = sec_క్రమం[n - 1];
        sec_cls[n] = k, sec_క్రమం[n] = i;
        ఒకవేళ ((s->sh_flags & SHF_TLS) && 0 == pe->tls_కొలత)
            pe_build_tls(pe, ఖాళీ);
    }
    si = ఖాళీ;
    addr = pe->imagebase + 1;
    కొరకు (i = 1; (c = sec_cls[i]) < sec_చివరి; ++i) {
        s = s1->sections[sec_క్రమం[i]];

        ఒకవేళ (PE_విలీనం_దత్తాంశం && c == sec_bss)
            c = sec_దత్తాంశం;
        ఒకవేళ (c == sec_tbss)
            c = sec_tdata;

        ఒకవేళ (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } లేకపోతే {
            si = ఖాళీ;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        ఒకవేళ (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        ఒకవేళ (s == pe->reloc)
            pe_build_reloc (pe);

        ఒకవేళ (0 == s->దత్తాంశం_స్థానభ్రంశం)
            కొనసాగు;

        ఒకవేళ (si)
            వెళ్ళు కూడు_section;

        si = tcc_mallocz(పరిమాణం *si);
        dynarray_కూడు(&pe->sec_info, &pe->sec_లెక్క, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        ఒకవేళ (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_సంకేతం;
        లేకపోతే ఒకవేళ (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_దత్తాంశం;
        లేకపోతే
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_దత్తాంశం;
        ఒకవేళ (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        ఒకవేళ (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

కూడు_section:
        s->sh_info = pe->sec_లెక్క; /* section number for coff syms */
        addr += s->దత్తాంశం_స్థానభ్రంశం;
        si->sh_కొలత = addr - si->sh_addr;
        ఒకవేళ (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            అయితే (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = ఖాళీ;
            si->దత్తాంశం_కొలత = si->sh_కొలత;
        }

        ఒకవేళ (s->sh_flags & SHF_TLS) {
            strcpy(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#ఒకవేళ 0
    కొరకు (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_క్రమం[i]];
        పూర్ణాంకం type = s->sh_type;
        పూర్ణాంకం flags = s->sh_flags;
        రాయి("section %-16s %-10s %p %04x %2d %s,%s,%s\n",
            s->name,
            type == SHT_PROGBITS ? "progbits" :
            type == SHT_INIT_ARRAY ? "initarr" :
            type == SHT_FINI_ARRAY ? "finiarr" :
            type == SHT_NOBITS ? "nobits" :
            type == SHT_SYMTAB ? "symtab" :
            type == SHT_STRTAB ? "strtab" :
            type == SHT_RELX ? "rel" : "???",
            s->sh_addr,
            (గుర్తులేని)s->దత్తాంశం_స్థానభ్రంశం,
            s->sh_addralign,
            flags & SHF_ALLOC ? "alloc" : "",
            flags & SHF_WRITE ? "write" : "",
            flags & SHF_EXECINSTR ? "exec" : ""
            );
        fflush(stdout);
    }
    s1->verbose = 2;
#అయితే_ముగింపు
    tcc_free(sec_క్రమం);
    తిరిగి 0;
}

/*----------------------------------------------------------------------------*/
స్థిర పూర్ణాంకం pe_check_symbols(నిర్మాణం pe_info *pe)
{
    పూర్ణాంకం sym_సూచీ, sym_చివర;
    పూర్ణాంకం ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(పాఠ్యం_section, 8);

    sym_చివర = symtab_section->దత్తాంశం_స్థానభ్రంశం / పరిమాణం(ElfW(Sym));
    కొరకు (sym_సూచీ = 1; sym_సూచీ < sym_చివర; ++sym_సూచీ) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->దత్తాంశం + sym_సూచీ;
        ఒకవేళ (sym->st_shndx == SHN_UNDEF) {
            స్థిరరాశి అక్షరం *name = (అక్షరం*)symtab_section->link->దత్తాంశం + sym->st_name;
            గుర్తులేని type = ELFW(ST_TYPE)(sym->st_info);
            పూర్ణాంకం imp_sym = 0;
            నిర్మాణం import_చిహ్నం *is;

            పూర్ణాంకం _imp_, n;
            అక్షరం బఫరు[200];
            స్థిరరాశి అక్షరం *s, *p;

            n = _imp_ = 0;
            ఒకవేళ (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            చేయి {
                s = pe_export_name(s1, sym);
                ఒకవేళ (n) {
                    /* second try: */
                    ఒకవేళ (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        ఒకవేళ (!p || s[0] != '_')
                            ఆపు;
                        strcpy(బఫరు, s+1)[p-s-1] = 0, s = బఫరు;
                    } లేకపోతే ఒకవేళ (s[0] != '_') { /* try non-ansi function */
                        బఫరు[0] = '_', strcpy(బఫరు + 1, s), s = బఫరు;
                    } లేకపోతే ఒకవేళ (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } లేకపోతే ఒకవేళ (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } లేకపోతే {
                        ఆపు;
                    }
                }
                imp_sym = కనుగొను_elf_sym(s1->dynsymtab_section, s);
            } అయితే (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            ఒకవేళ (0 == imp_sym)
                కొనసాగు; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_కూడు_import(pe, imp_sym);

            ఒకవేళ (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                గుర్తులేని స్థానభ్రంశం = is->thk_స్థానభ్రంశం;
                ఒకవేళ (స్థానభ్రంశం) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } లేకపోతే {
                    గుర్తులేని అక్షరం *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(బఫరు, "IAT.%s", name);
                    is->iat_సూచీ = put_elf_sym(
                        symtab_section, 0, పరిమాణం(DWORD),
                        ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT),
                        0, SHN_UNDEF, బఫరు);

                    స్థానభ్రంశం = పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం;
                    is->thk_స్థానభ్రంశం = స్థానభ్రంశం;

                    /* add the 'jmp IAT[x]' instruction */
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
                    p = section_ptr_కూడు(పాఠ్యం_section, 8+4); // room for code and address
                    write32le(p + 0, 0xE59FC000); // arm code ldr ip, [pc] ; PC+8+0 = 0001xxxx
                    write32le(p + 4, 0xE59CF000); // arm code ldr pc, [ip]
                    put_elf_reloc(symtab_section, పాఠ్యం_section,
                        స్థానభ్రంశం + 8, R_XXX_THUNKFIX, is->iat_సూచీ); // offset to IAT position
#లేదావేళ defined(TCC_లక్ష్యం_ARM64)
                    p = section_ptr_కూడు(పాఠ్యం_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, పాఠ్యం_section,
                        స్థానభ్రంశం + 16, R_XXX_THUNKFIX, is->iat_సూచీ);
#లేకపోతే
                    p = section_ptr_కూడు(పాఠ్యం_section, 8);
                    write16le(p, 0x25FF);
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
                    write32le(p + 2, (DWORD)-4);
#అయితే_ముగింపు
                    put_elf_reloc(symtab_section, పాఠ్యం_section, 
                        స్థానభ్రంశం + 2, R_XXX_THUNKFIX, is->iat_సూచీ);
#అయితే_ముగింపు
                }
                /* tcc_realloc might have altered sym's address */
                sym = (ElfW(Sym) *)symtab_section->దత్తాంశం + sym_సూచీ;
                /* patch the original symbol */
                sym->st_విలువ = స్థానభ్రంశం;
                sym->st_shndx = పాఠ్యం_section->sh_అంకె;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } లేకపోతే { /* STT_OBJECT */
                ఒకవేళ (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_విలువ = is->iat_సూచీ; /* chain potential alias */
                is->iat_సూచీ = sym_సూచీ;
            }

        } లేకపోతే ఒకవేళ (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    తిరిగి ret;
}

/*----------------------------------------------------------------------------*/
#ఒకవేళ PE_PRINT_SECTIONS
స్థిర శూన్య pe_print_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    పూర్ణాంకం i, n, l, m;
    p = s->దత్తాంశం;
    e = s->దత్తాంశం + s->దత్తాంశం_స్థానభ్రంశం;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    ఒకవేళ (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    ఒకవేళ (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (గుర్తులేని)s->sh_addr);
    fprintf(f, "\ncontents %08X", (గుర్తులేని)l);
    fprintf(f, "\n\n");

    ఒకవేళ (s->sh_type == SHT_NOBITS)
        తిరిగి;

    ఒకవేళ (0 == l)
        తిరిగి;

    ఒకవేళ (s->sh_type == SHT_SYMTAB)
        m = పరిమాణం(ElfW(Sym));
    లేకపోతే ఒకవేళ (s->sh_type == SHT_RELX)
        m = పరిమాణం(ElfW_Rel);
    లేకపోతే
        m = 16;

    fprintf(f, "%-8s", "offset");
    కొరకు (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    ఒకవేళ (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        స్థిరరాశి అక్షరం *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            ఖాళీ
        };

        స్థిరరాశి అక్షరం *fields2[] = {
            "offs",
            "type",
            "symb",
            ఖాళీ
        };

        స్థిరరాశి అక్షరం **p;

        ఒకవేళ (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        లేకపోతే
            p = fields2, n = 58;

        కొరకు (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    కొరకు (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    కొరకు (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        కొరకు (n = 0; n < m; ++n) {
            ఒకవేళ (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            లేకపోతే
                fprintf(f, "   ");
        }

        ఒకవేళ (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            స్థిరరాశి అక్షరం *name = s->link->దత్తాంశం + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (గుర్తులేని)sym->st_name,
                    (గుర్తులేని)sym->st_విలువ,
                    (గుర్తులేని)sym->st_కొలత,
                    (గుర్తులేని)ELFW(ST_BIND)(sym->st_info),
                    (గుర్తులేని)ELFW(ST_TYPE)(sym->st_info),
                    (గుర్తులేని)sym->st_other,
                    (గుర్తులేని)sym->st_shndx,
                    name);

        } లేకపోతే ఒకవేళ (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->దత్తాంశం + ELFW(R_SYM)(rel->r_info);
            స్థిరరాశి అక్షరం *name = s->link->link->దత్తాంశం + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (గుర్తులేని)rel->r_స్థానభ్రంశం,
                    (గుర్తులేని)ELFW(R_TYPE)(rel->r_info),
                    (గుర్తులేని)ELFW(R_SYM)(rel->r_info),
                    name);
        } లేకపోతే {
            fprintf(f, "   ");
            కొరకు (n = 0; n < m; ++n) {
                ఒకవేళ (n + i < l) {
                    b = p[i + n];
                    ఒకవేళ (b < 32 || b >= 127)
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

స్థిర శూన్య pe_print_sections(TCCState *s1, స్థిరరాశి అక్షరం *fname)
{
    Section *s;
    FILE *f;
    పూర్ణాంకం i;
    f = fopen(fname, "w");
    కొరకు (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    fclose(f);
}
#అయితే_ముగింపు

/* ------------------------------------------------------------- */

ST_FUNC పూర్ణాంకం pe_putimport(TCCState *s1, పూర్ణాంకం dllindex, స్థిరరాశి అక్షరం *name, addr_t విలువ)
{
    తిరిగి సమితి_elf_sym(
        s1->dynsymtab_section,
        విలువ,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        విలువ ? SHN_ABS : SHN_UNDEF,
        name
        );
}

స్థిర పూర్ణాంకం read_mem(పూర్ణాంకం fd, గుర్తులేని స్థానభ్రంశం, శూన్య *బఫరు, గుర్తులేని len)
{
    lseek(fd, స్థానభ్రంశం, SEEK_SET);
    తిరిగి len == పఠ(fd, బఫరు, len);
}

/* ------------------------------------------------------------- */

స్థిర పూర్ణాంకం get_dllexports(పూర్ణాంకం fd, అక్షరం **pp)
{
    పూర్ణాంకం i, k, l, n, n0, ret;
    అక్షరం *p;

    IMAGE_SECTION_శీర్షిక_2 ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_శీర్షిక_2 dh;
    IMAGE_FILE_శీర్షిక_2 ih;
    DWORD sig, ref, addr;
    DWORD *namep = ఖాళీ, p0 = 0, p1;

    పూర్ణాంకం pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = ఖాళీ;
    ret = 1;
    ఒకవేళ (!read_mem(fd, 0, &dh, పరిమాణం dh))
        వెళ్ళు the_చివర;
    ఒకవేళ (!read_mem(fd, dh.e_lfanew, &sig, పరిమాణం sig))
        వెళ్ళు the_చివర;
    ఒకవేళ (sig != 0x00004550)
        వెళ్ళు the_చివర;
    pef_hdroffset = dh.e_lfanew + పరిమాణం sig;
    ఒకవేళ (!read_mem(fd, pef_hdroffset, &ih, పరిమాణం ih))
        వెళ్ళు the_చివర;
    opt_hdroffset = pef_hdroffset + పరిమాణం ih;
    ఒకవేళ (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + పరిమాణం oh;
        ఒకవేళ (!read_mem(fd, opt_hdroffset, &oh, పరిమాణం oh))
            వెళ్ళు the_చివర;
        ఒకవేళ (IMAGE_DIRECTORY_నమోదు_EXPORT >= oh.సంఖ్య_యొక్క_Rva_And_Sizes)
            వెళ్ళు the_చివర_0;
        addr = oh.దత్తాంశం_Directory[IMAGE_DIRECTORY_నమోదు_EXPORT].Virtual_చిరునామా;
    } లేకపోతే ఒకవేళ (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + పరిమాణం oh;
        ఒకవేళ (!read_mem(fd, opt_hdroffset, &oh, పరిమాణం oh))
            వెళ్ళు the_చివర;
        ఒకవేళ (IMAGE_DIRECTORY_నమోదు_EXPORT >= oh.సంఖ్య_యొక్క_Rva_And_Sizes)
            వెళ్ళు the_చివర_0;
        addr = oh.దత్తాంశం_Directory[IMAGE_DIRECTORY_నమోదు_EXPORT].Virtual_చిరునామా;
    } లేకపోతే
        వెళ్ళు the_చివర;

    //printf("addr: %08x\n", addr);
    కొరకు (i = 0; i < ih.సంఖ్య_యొక్క_Sections; ++i) {
        ఒకవేళ (!read_mem(fd, sec_hdroffset + i * పరిమాణం ish, &ish, పరిమాణం ish))
            వెళ్ళు the_చివర;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        ఒకవేళ (addr >= ish.Virtual_చిరునామా && addr < ish.Virtual_చిరునామా + ish.కొలత_యొక్క_Raw_దత్తాంశం)
            వెళ్ళు దొరికింది;
    }
    వెళ్ళు the_చివర_0;
దొరికింది:
    ref = ish.Virtual_చిరునామా - ish.సూచిక_గమ్యం_Raw_దత్తాంశం;
    ఒకవేళ (!read_mem(fd, addr - ref, &ied, పరిమాణం ied))
        వెళ్ళు the_చివర;
    k = ied.సంఖ్య_యొక్క_పేర్లు;
    ఒకవేళ (k) {
        namep = tcc_malloc(l = k * పరిమాణం *namep);
        ఒకవేళ (!read_mem(fd, ied.చిరునామా_యొక్క_పేర్లు - ref, namep, l))
            వెళ్ళు the_చివర;
        కొరకు (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            ఒకవేళ (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            చేయి {
                ఒకవేళ (0 == l) {
                    ఒకవేళ (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    ఒకవేళ ((l = పఠ(fd, p + n, 1000 - 1)) <= 0)
                        వెళ్ళు the_చివర;
                }
                --l, ++p0;
            } అయితే (p[n++]);
        }
        p[n] = 0;
    }
the_చివర_0:
    ret = 0;
the_చివర:
    tcc_free(namep);
    ఒకవేళ (ret && p)
        tcc_free(p), p = ఖాళీ;
    *pp = p;
    తిరిగి ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

స్థిర పూర్ణాంకం pe_ఎక్కించు_res(TCCState *s1, పూర్ణాంకం fd)
{
    నిర్మాణం pe_rsrc_శీర్షిక hdr;
    Section *rsrc_section;
    పూర్ణాంకం i, ret = -1, sym_సూచీ;
    BYTE *ptr;
    గుర్తులేని offs;

    ఒకవేళ (!read_mem(fd, 0, &hdr, పరిమాణం hdr))
        వెళ్ళు quit;

    ఒకవేళ (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.సంఖ్య_యొక్క_Sections != 1
        || strcmp((అక్షరం*)hdr.sectionhdr.Name, ".rsrc") != 0)
        వెళ్ళు quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_కూడు(rsrc_section, hdr.sectionhdr.కొలత_యొక్క_Raw_దత్తాంశం);
    offs = hdr.sectionhdr.సూచిక_గమ్యం_Raw_దత్తాంశం;
    ఒకవేళ (!read_mem(fd, offs, ptr, hdr.sectionhdr.కొలత_యొక్క_Raw_దత్తాంశం))
        వెళ్ళు quit;
    offs = hdr.sectionhdr.సూచిక_గమ్యం_Relocations;
    sym_సూచీ = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_అంకె, ".rsrc");
    కొరకు (i = 0; i < hdr.sectionhdr.సంఖ్య_యొక్క_Relocations; ++i) {
        నిర్మాణం pe_rsrc_reloc rel;
        ఒకవేళ (!read_mem(fd, offs, &rel, పరిమాణం rel))
            వెళ్ళు quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        ఒకవేళ (rel.type != RSRC_RELTYPE)
            వెళ్ళు quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.స్థానభ్రంశం, R_XXX_RELATIVE, sym_సూచీ);
        offs += పరిమాణం rel;
    }
    ret = 0;
quit:
    తిరిగి ret;
}

/* ------------------------------------------------------------- */

స్థిర అక్షరం *trimfront(అక్షరం *p)
{
    అయితే ((గుర్తులేని అక్షరం)*p <= ' ' && *p && *p != '\n')
	++p;
    తిరిగి p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

స్థిర అక్షరం *get_token(అక్షరం **s, అక్షరం *f)
{
    అక్షరం *p, *e;
    పూర్ణాంకం q;

    p = trimfront(*s);
    q = *p;
    ఒకవేళ (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    లేకపోతే
        q = ' ';
    కొరకు (e = p; (గుర్తులేని అక్షరం)*e >= ' ' && *e != q; ++e)
        ;
    ఒకవేళ (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    తిరిగి p;
}

స్థిర పూర్ణాంకం pe_ఎక్కించు_def(TCCState *s1, పూర్ణాంకం fd)
{
    పూర్ణాంకం state = 0, ret = -1, dllindex = 0, ord;
    అక్షరం dllname[80], *buf, *పంక్తి, *p, *x, తదుపరి;

    buf = tcc_ఎక్కించు_పాఠ్యం(fd);
    ఒకవేళ (!buf)
        తిరిగి ret;

    కొరకు (పంక్తి = buf;; ++పంక్తి)  {
        p = get_token(&పంక్తి, &తదుపరి);
        ఒకవేళ (!(*p && *p != ';'))
            వెళ్ళు skip;
        ఎంపిక (state) {
        స్థితి 0:
            ఒకవేళ (0 != stricmp(p, "LIBRARY") || తదుపరి == '\n')
                వెళ్ళు quit;
            pstrcpy(dllname, పరిమాణం dllname, get_token(&పంక్తి, &తదుపరి));
            ఒకవేళ (!*tcc_fileextension(dllname))
                pstrcat(dllname, పరిమాణం dllname, ".dll");
            ++state;
            ఆపు;
        స్థితి 1:
            ఒకవేళ (0 != stricmp(p, "EXPORTS"))
                వెళ్ళు quit;
            ++state;
            ఆపు;
        స్థితి 2:
            dllindex = tcc_కూడు_dllref(s1, dllname, 0)->సూచీ;
            ++state;
            /* fall through */
        అప్రమేయ:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            ఒకవేళ (తదుపరి == '@') {
                x = get_token(&పంక్తి, &తదుపరి);
                ord = (పూర్ణాంకం)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            ఆపు;
        }
skip:
        అయితే ((గుర్తులేని అక్షరం)తదుపరి > ' ')
            get_token(&పంక్తి, &తదుపరి);
        ఒకవేళ (తదుపరి != '\n')
            ఆపు;
    }
    ret = 0;
quit:
    tcc_free(buf);
    తిరిగి ret;
}

/* ------------------------------------------------------------- */

స్థిర పూర్ణాంకం pe_ఎక్కించు_dll(TCCState *s1, పూర్ణాంకం fd, స్థిరరాశి అక్షరం *filename)
{
    అక్షరం *p, *q;
    DLLReference *ref = tcc_కూడు_dllref(s1, filename, 0);
    ఒకవేళ (ref->దొరికింది)
        తిరిగి 0;
    ఒకవేళ (get_dllexports(fd, &p))
        తిరిగి -1;
    ఒకవేళ (p) {
        కొరకు (q = p; *q; q += 1 + అక్షరశ్రేణి_పొడవు(q))
            pe_putimport(s1, ref->సూచీ, q, 0);
        tcc_free(p);
    }
    తిరిగి 0;
}

ST_FUNC పూర్ణాంకం pe_ఎక్కించు_file(నిర్మాణం TCCState *s1, పూర్ణాంకం fd, స్థిరరాశి అక్షరం *filename)
{
    పూర్ణాంకం ret = -1;
    అక్షరం buf[10];
    ఒకవేళ (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_ఎక్కించు_def(s1, fd);
    లేకపోతే ఒకవేళ (pe_ఎక్కించు_res(s1, fd) == 0)
        ret = 0;
    లేకపోతే ఒకవేళ (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_ఎక్కించు_dll(s1, fd, filename);
    తిరిగి ret;
}

PUB_FUNC పూర్ణాంకం tcc_get_dllexports(స్థిరరాశి అక్షరం *filename, అక్షరం **pp)
{
    పూర్ణాంకం ret, fd = open(filename, O_RDONLY | O_ద్విమాన_2);
    ఒకవేళ (fd < 0)
        తిరిగి -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    తిరిగి ret;
}

/* ------------------------------------------------------------- */
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
స్థిర గుర్తులేని pe_కూడు_unwind_info(TCCState *s1)
{
    ఒకవేళ (ఖాళీ == s1->uw_pdata) {
        s1->uw_pdata = కనుగొను_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    ఒకవేళ (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, పాఠ్యం_section->sh_అంకె, ".uw_base");
    ఒకవేళ (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        స్థిర స్థిరరాశి గుర్తులేని అక్షరం uw_info[] = {
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

        Section *s = పాఠ్యం_section;
        గుర్తులేని అక్షరం *p;

        section_ptr_కూడు(s, -s->దత్తాంశం_స్థానభ్రంశం & 3); /* align */
        s1->uw_offs = s->దత్తాంశం_స్థానభ్రంశం;
        p = section_ptr_కూడు(s, పరిమాణం uw_info);
        జ్ఞాపకం_నకలు(p, uw_info, పరిమాణం uw_info);
    }

    తిరిగి s1->uw_offs;
}

ST_FUNC శూన్య pe_కూడు_unwind_దత్తాంశం(గుర్తులేని ప్రారంభం, గుర్తులేని చివర, గుర్తులేని దొంతర)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    గుర్తులేని o, n, d;
    నిర్మాణం /* _RUNTIME_FUNCTION */ {
      DWORD Begin_చిరునామా;
      DWORD చివర_చిరునామా;
      DWORD Unwind_దత్తాంశం;
    } *p;

    d = pe_కూడు_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->దత్తాంశం_స్థానభ్రంశం;
    p = section_ptr_కూడు(pd, పరిమాణం *p);

    /* record this function */
    p->Begin_చిరునామా = ప్రారంభం;
    p->చివర_చిరునామా = చివర;
    p->Unwind_దత్తాంశం = d;

    /* put relocations on it */
    కొరకు (n = o + పరిమాణం *p; o < n; o += పరిమాణం p->Begin_చిరునామా)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#లేదావేళ defined(TCC_లక్ష్యం_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
స్థిర Section *pe_కూడు_unwind_info(TCCState *s1)
{
    Section *s;

    ఒకవేళ (ఖాళీ == s1->uw_pdata) {
        s1->uw_pdata = కనుగొను_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = కనుగొను_section(s1, ".xdata");
    s->sh_addralign = 4;
    ఒకవేళ (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  పాఠ్యం_section->sh_అంకె, ".uw_text_base");
    ఒకవేళ (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_అంకె, ".uw_base");
    తిరిగి s;
}

ST_FUNC శూన్య pe_కూడు_unwind_దత్తాంశం(గుర్తులేని ప్రారంభం, గుర్తులేని చివర, గుర్తులేని దొంతర)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    గుర్తులేని o, d, సంకేతం_బైట్లు, func_len;
    గుర్తులేని అక్షరం *q;
    uint32_t శీర్షిక;
    నిర్మాణం /* _RUNTIME_FUNCTION */ {
        DWORD Begin_చిరునామా;
        DWORD Unwind_దత్తాంశం;
    } *p;

    పూర్ణాంకం epilog;

    xd = pe_కూడు_unwind_info(s1);
    pd = s1->uw_pdata;

    func_len = (చివర - ప్రారంభం) >> 2;
    సంకేతం_బైట్లు = 0;
    epilog = సంకేతం_బైట్లు;
    సంకేతం_బైట్లు += 3; /* set_fp, save_fplr_x, end */
    సంకేతం_బైట్లు = (సంకేతం_బైట్లు + 3) & ~3;

    section_ptr_కూడు(xd, -xd->దత్తాంశం_స్థానభ్రంశం & 3);
    d = xd->దత్తాంశం_స్థానభ్రంశం;
    q = section_ptr_కూడు(xd, 4 + సంకేతం_బైట్లు);

    /* Full ARM64 xdata header: E=1 with one epilog and no exception handler. */
    శీర్షిక = (func_len & 0x3ffff)
        | 1 << 21
        | (epilog & 0x1F) << 22
        | (సంకేతం_బైట్లు >> 2) << 27
        ;
    write32le(q, శీర్షిక);
    q += 4;
    *q++ = 0xE1; /* set_fp */
    *q++ = 0x9B; /* save_fplr_x: stp x29,lr,[sp,#-224]! */
    *q++ = 0xE4; /*చివర*/
    అయితే ((గుర్తులేని)(q - (xd->దత్తాంశం + d + 4)) < సంకేతం_బైట్లు)
        *q++ = 0xE3; /* nop padding */

    o = pd->దత్తాంశం_స్థానభ్రంశం;
    p = section_ptr_కూడు(pd, పరిమాణం *p);
    p->Begin_చిరునామా = ప్రారంభం;
    p->Unwind_దత్తాంశం = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#అయితే_ముగింపు
/* ------------------------------------------------------------- */
#ఒకవేళ defined(TCC_లక్ష్యం_X86_64) || defined(TCC_లక్ష్యం_ARM64)
#నిర్వచించు PE_STDSYM(n,s) n
#లేకపోతే
#నిర్వచించు PE_STDSYM(n,s) "_" n s
#అయితే_ముగింపు

స్థిర శూన్య pe_కూడు_runtime(TCCState *s1, నిర్మాణం pe_info *pe)
{
    స్థిరరాశి అక్షరం *ప్రారంభం_చిహ్నం;
    పూర్ణాంకం pe_type;

    ఒకవేళ (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        ప్రారంభం_చిహ్నం = PE_STDSYM("__dllstart","@12");
    } లేకపోతే {
        స్థిరరాశి అక్షరం *నిరంతరం_చిహ్నం;
        ఒకవేళ (కనుగొను_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            ప్రారంభం_చిహ్నం = "__winstart";
            నిరంతరం_చిహ్నం = "__runwinmain";
            pe_type = PE_GUI;
        } లేకపోతే ఒకవేళ (కనుగొను_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            ప్రారంభం_చిహ్నం = "__wwinstart";
            నిరంతరం_చిహ్నం = "__runwwinmain";
            pe_type = PE_GUI;
        } లేకపోతే ఒకవేళ (కనుగొను_elf_sym(symtab_section, "wmain")) {
            ప్రారంభం_చిహ్నం = "__wstart";
            నిరంతరం_చిహ్నం = "__runwmain";
            pe_type = PE_EXE;
        } లేకపోతే {
            ప్రారంభం_చిహ్నం =  "__start";
            నిరంతరం_చిహ్నం = "__runmain";
            pe_type = PE_EXE;
            ఒకవేళ (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        ఒకవేళ (TCC_OUTPUT_జ్ఞాపకం == s1->output_type && !s1->nostdlib)
            ప్రారంభం_చిహ్నం = నిరంతరం_చిహ్నం;
    }
    ఒకవేళ (s1->elf_entryname) {
        pe->ప్రారంభం_చిహ్నం = ప్రారంభం_చిహ్నం = s1->elf_entryname;
    } లేకపోతే {
        pe->ప్రారంభం_చిహ్నం = ప్రారంభం_చిహ్నం + 1;
        ఒకవేళ (!s1->leading_underscore || strchr(ప్రారంభం_చిహ్నం, '@'))
            ++ప్రారంభం_చిహ్నం;
    }

#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
    ఒకవేళ (s1->do_backtrace) {
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    ఒకవేళ (s1->output_type == TCC_OUTPUT_జ్ఞాపకం)
                tcc_కూడు_support(s1, "bcheck_run.o");
	    లేకపోతే
                tcc_కూడు_support(s1, "bcheck.o");
	}
#అయితే_ముగింపు
        ఒకవేళ (s1->output_type == TCC_OUTPUT_EXE)
            tcc_కూడు_support(s1, "bt-exe.o");
        ఒకవేళ (s1->output_type == TCC_OUTPUT_DLL)
            tcc_కూడు_support(s1, "bt-dll.o");
        ఒకవేళ (s1->output_type != TCC_OUTPUT_DLL)
            tcc_కూడు_support(s1, "bt-log.o");
        tcc_కూడు_btstub(s1);
    }
#అయితే_ముగింపు

    /* grab the startup code from libtcc1.a */
#నిర్వచితమైతే TCC_IS_NATIVE
    ఒకవేళ (TCC_OUTPUT_జ్ఞాపకం != s1->output_type || s1->నిరంతరం_main)
#అయితే_ముగింపు
    సమితి_global_sym(s1, ప్రారంభం_చిహ్నం, ఖాళీ, 0);

    ఒకవేళ (0 == s1->nostdlib) {
        స్థిర స్థిరరాశి అక్షరం * స్థిరరాశి libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", ఖాళీ
        };
        స్థిరరాశి అక్షరం * స్థిరరాశి *pp, *p;
        ఒకవేళ (TCC_LIBTCC1[0])
            tcc_కూడు_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        కొరకు (pp = libs; 0 != (p = *pp); ++pp) {
            ఒకవేళ (*p)
                tcc_కూడు_library(s1, p);
            లేకపోతే ఒకవేళ (PE_DLL != pe_type && PE_GUI != pe_type)
                ఆపు;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    ఒకవేళ (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    ఒకవేళ (TCC_OUTPUT_జ్ఞాపకం == s1->output_type)
        pe_type = PE_నిరంతరం;
    pe->type = pe_type;
}

ST_FUNC పూర్ణాంకం pe_setsubsy(TCCState *s1, స్థిరరాశి అక్షరం *arg)
{
    స్థిర స్థిరరాశి నిర్మాణం subsy { స్థిరరాశి అక్షరం* p; పూర్ణాంకం v; } x[] = {
#ఒకవేళ defined(TCC_లక్ష్యం_I386) || defined(TCC_లక్ష్యం_X86_64) || defined(TCC_లక్ష్యం_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#లేదావేళ defined(TCC_లక్ష్యం_ARM)
        { "wince", 9 },
#అయితే_ముగింపు
        { 0, -1 }};
    స్థిరరాశి నిర్మాణం subsy *y;
    కొరకు (y = x;; ++y) {
        ఒకవేళ (!y->p)
            తిరిగి -1;
        ఒకవేళ (0 == strcmp(y->p, arg)) {
            s1->pe_subsystem = y->v;
            తిరిగి 0;
        }
    }
}

స్థిర శూన్య pe_సమితి_options(TCCState * s1, నిర్మాణం pe_info *pe)
{
    ఒకవేళ (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_పునాది_DLL;
    } లేకపోతే {
        pe->imagebase = IMAGE_పునాది_EXE;
    }

#ఒకవేళ defined(TCC_లక్ష్యం_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#లేకపోతే
    ఒకవేళ (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    లేకపోతే
        pe->subsystem = 3;
#అయితే_ముగింపు
    /* Allow override via -Wl,-subsystem=... option */
    ఒకవేళ (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    ఒకవేళ (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } లేకపోతే {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    ఒకవేళ (s1->section_align != 0)
        pe->section_align = s1->section_align;
    ఒకవేళ (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    ఒకవేళ ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    ఒకవేళ (s1->has_పాఠ్యం_addr)
        pe->imagebase = s1->పాఠ్యం_addr;
}

ST_FUNC పూర్ణాంకం pe_output_file(TCCState *s1, స్థిరరాశి అక్షరం *filename)
{
    నిర్మాణం pe_info pe;

    memset(&pe, 0, పరిమాణం pe);
    pe.filename = filename;
    pe.s1 = s1;
    s1->filetype = 0;

#నిర్వచితమైతే CONFIG_TCC_BCHECK
    tcc_కూడు_bcheck(s1);
#అయితే_ముగింపు
    tcc_కూడు_pragma_libs(s1);
    pe_కూడు_runtime(s1, &pe);
    resolve_common_syms(s1);
    pe_సమితి_options(s1, &pe);
    pe_check_symbols(&pe);
    ఒకవేళ (s1->nb_errors)
        వెళ్ళు పూర్తి;
    ఒకవేళ (filename) {
        pe_కేటాయించు_చిరునామాలు(&pe);
        relocate_syms(s1, s1->symtab, 0);
        ఒకవేళ (s1->nb_errors)
            వెళ్ళు పూర్తి;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.ప్రారంభం_addr = (DWORD)
            (get_sym_addr(s1, pe.ప్రారంభం_చిహ్నం, 1, 1) - pe.imagebase);
        ఒకవేళ (s1->nb_errors)
            వెళ్ళు పూర్తి;
        pe_write(&pe);
    } లేకపోతే {
        /* -run */
#నిర్వచితమైతే TCC_IS_NATIVE
        pe.thunk = దత్తాంశం_section;
        pe_build_imports(&pe);
        s1->నిరంతరం_main = pe.ప్రారంభం_చిహ్నం;
#ఒకవేళ defined(TCC_లక్ష్యం_X86_64) || defined(TCC_లక్ష్యం_ARM64)
        s1->uw_pdata = కనుగొను_section(s1, ".pdata");
#అయితే_ముగింపు
#అయితే_ముగింపు
    }
పూర్తి:
    dynarray_reset(&pe.sec_info, &pe.sec_లెక్క);
    pe_free_imports(&pe);
#ఒకవేళ PE_PRINT_SECTIONS
    ఒకవేళ (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#అయితే_ముగింపు
    తిరిగి s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
