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

#ضمن "tcc.h"

#تعریف_کړه PE_یوځای_معلومات 1
#تعریف_کړه PE_PRINT_SECTIONS 0

#که_نه_تعریف_شوی _WIN32
#تعریف_کړه stricmp strcasecmp
#تعریف_کړه strnicmp strncasecmp
#ضمن <sys/stat.h> /* chmod() */
#د_که_پای

#إذا defined TCC_موخه_X86_64
# define REL_TYPE_مستقیم R_X86_64_64
# define R_XXX_THUNKFIX R_X86_64_PC32
# define R_XXX_RELATIVE R_X86_64_RELATIVE
# define R_XXX_FUNCCALL R_X86_64_PLT32
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0x8664
# define CHARACTERISTICS_EXE 0x022F
# define CHARACTERISTICS_DLL 0x222E
# define IMAGE_بنسټ_EXE 0x00400000
# define IMAGE_بنسټ_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#وإلاإذا defined TCC_موخه_ARM
# define REL_TYPE_مستقیم R_ARM_ABS32
# define R_XXX_THUNKFIX R_ARM_ABS32
# define R_XXX_RELATIVE R_ARM_RELATIVE
# define R_XXX_FUNCCALL R_ARM_PC24
# define R_XXX_FUNCCALL2 R_ARM_ABS32
# define RSRC_RELTYPE 7 /* ??? (not tested) */
# define IMAGE_FILE_MACHINE 0x01C0
# define CHARACTERISTICS_EXE 0x010F
# define CHARACTERISTICS_DLL 0x230F
# define IMAGE_بنسټ_EXE 0x00100000
# define IMAGE_بنسټ_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#وإلاإذا defined TCC_موخه_ARM64
# define REL_TYPE_مستقیم R_AARCH64_ABS64
# define R_XXX_THUNKFIX R_AARCH64_ABS64
# define R_XXX_RELATIVE R_AARCH64_RELATIVE
# define R_XXX_FUNCCALL R_AARCH64_CALL26
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0xAA64
# define CHARACTERISTICS_EXE 0x0022
# define CHARACTERISTICS_DLL 0x2022
# define IMAGE_بنسټ_EXE 0x140000000ULL
# define IMAGE_بنسټ_DLL 0x180000000ULL
# define OS_VER 0x0602
# define DLLCHARACTERISTICS 0x8160

#وإلاإذا defined TCC_موخه_I386
# define REL_TYPE_مستقیم R_386_32
# define R_XXX_THUNKFIX R_386_32
# define R_XXX_RELATIVE R_386_RELATIVE
# define R_XXX_FUNCCALL R_386_PC32
# define RSRC_RELTYPE 7 /* DIR32NB */
# define IMAGE_FILE_MACHINE 0x014C
# define CHARACTERISTICS_EXE 0x030F
# define CHARACTERISTICS_DLL 0x230E
# define IMAGE_بنسټ_EXE 0x00400000
# define IMAGE_بنسټ_DLL 0x10000000
# define OS_VER 0x0400
# define DLLCHARACTERISTICS 0
#د_که_پای

#إذا PTR_اندازه == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#وإلا
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#د_که_پای

#که_نه_تعریف_شوی IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

تعريفنوع بینښه حرف BYTE;
تعريفنوع بینښه لنډ کلمه_3;
تعريفنوع بینښه صحيح DWORD;
تعريفنوع بینښه اوږد اوږد ULONGLONG;
#لارښوونه pack(ټېل, 1)

تعريفنوع بنية IMAGE_DOS_سرلیک {  /* DOS .EXE header */
    کلمه_3 e_magic;         /* Magic number */
    کلمه_3 e_cblp;          /* Bytes on last page of file */
    کلمه_3 e_cp;            /* Pages in file */
    کلمه_3 e_crlc;          /* Relocations */
    کلمه_3 e_cparhdr;       /* Size of header in paragraphs */
    کلمه_3 e_minalloc;      /* Minimum extra paragraphs needed */
    کلمه_3 e_maxalloc;      /* Maximum extra paragraphs needed */
    کلمه_3 e_ss;            /* Initial (relative) SS value */
    کلمه_3 e_sp;            /* Initial SP value */
    کلمه_3 e_csum;          /* Checksum */
    کلمه_3 e_ip;            /* Initial IP value */
    کلمه_3 e_cs;            /* Initial (relative) CS value */
    کلمه_3 e_lfarlc;        /* File address of relocation table */
    کلمه_3 e_ovno;          /* Overlay number */
    کلمه_3 e_res[4];        /* Reserved words */
    کلمه_3 e_oemid;         /* OEM identifier (for e_oeminfo) */
    کلمه_3 e_oeminfo;       /* OEM information; e_oemid specific */
    کلمه_3 e_res2[10];      /* Reserved words */
    DWORD e_lfanew;        /* File address of new exe header */
} IMAGE_DOS_سرلیک_2, *PIMAGE_DOS_سرلیک;

#تعریف_کړه IMAGE_NT_SIGNATURE  0x00004550  /* PE00 */

تعريفنوع بنية IMAGE_FILE_سرلیک {
    کلمه_3    Machine;
    کلمه_3    شمېره_د_Sections;
    DWORD   وخت_Date_Stamp;
    DWORD   اشاره_ګر_منزل_نښه_جدول;
    DWORD   شمېره_د_Symbols;
    کلمه_3    اندازه_د_Optional_سرلیک;
    کلمه_3    Characteristics;
} IMAGE_FILE_سرلیک_2, *PIMAGE_FILE_سرلیک;


#تعریف_کړه IMAGE_SIZEOF_FILE_سرلیک 20

تعريفنوع بنية IMAGE_معلومات_DIRECTORY {
    DWORD   Virtual_پته;
    DWORD   اندازه_3;
} IMAGE_معلومات_DIRECTORY_2, *PIMAGE_معلومات_DIRECTORY;


تعريفنوع بنية IMAGE_OPTIONAL_سرلیک {
    /* Standard fields. */
    کلمه_3    Magic;
    BYTE    Major_Linker_نسخه;
    BYTE    Minor_Linker_نسخه;
    DWORD   اندازه_د_کوډ;
    DWORD   اندازه_د_Initialized_معلومات;
    DWORD   اندازه_د_Uninitialized_معلومات;
    DWORD   پته_د_ثبت_ټکی;
    DWORD   بنسټ_د_کوډ;
#إذا PTR_اندازه == 4
    DWORD   بنسټ_د_معلومات;
#د_که_پای
    /* NT additional fields. */
    ADDR3264 Image_بنسټ;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    کلمه_3    Major_Operating_System_نسخه;
    کلمه_3    Minor_Operating_System_نسخه;
    کلمه_3    Major_Image_نسخه;
    کلمه_3    Minor_Image_نسخه;
    کلمه_3    Major_Subsystem_نسخه;
    کلمه_3    Minor_Subsystem_نسخه;
    DWORD   Win32_نسخه_ارزښت;
    DWORD   اندازه_د_Image;
    DWORD   اندازه_د_سرلیکونه;
    DWORD   Check_مجموعه;
    کلمه_3    Subsystem;
    کلمه_3    DllCharacteristics;
    ADDR3264 اندازه_د_ډېری_Reserve;
    ADDR3264 اندازه_د_ډېری_Commit;
    ADDR3264 اندازه_د_ډېرۍ_Reserve;
    ADDR3264 اندازه_د_ډېرۍ_Commit;
    DWORD   LoaderFlags;
    DWORD   شمېره_د_Rva_And_Sizes;
    IMAGE_معلومات_DIRECTORY_2 معلومات_Directory[16];
} IMAGE_OPTIONAL_HEADER32, IMAGE_OPTIONAL_HEADER64, IMAGE_OPTIONAL_سرلیک_2;

#تعریف_کړه IMAGE_DIRECTORY_ثبت_EXPORT          0   /* Export Directory */
#تعریف_کړه IMAGE_DIRECTORY_ثبت_IMPORT          1   /* Import Directory */
#تعریف_کړه IMAGE_DIRECTORY_ثبت_RESOURCE        2   /* Resource Directory */
#تعریف_کړه IMAGE_DIRECTORY_ثبت_EXCEPTION       3   /* Exception Directory */
#تعریف_کړه IMAGE_DIRECTORY_ثبت_SECURITY        4   /* Security Directory */
#تعریف_کړه IMAGE_DIRECTORY_ثبت_BASERELOC       5   /* Base Relocation Table */
#تعریف_کړه IMAGE_DIRECTORY_ثبت_DEBUG           6   /* Debug Directory */
/*      IMAGE_DIRECTORY_ENTRY_COPYRIGHT       7      (X86 usage) */
#تعریف_کړه IMAGE_DIRECTORY_ثبت_ARCHITECTURE    7   /* Architecture Specific Data */
#تعریف_کړه IMAGE_DIRECTORY_ثبت_GLOBALPTR       8   /* RVA of GP */
#تعریف_کړه IMAGE_DIRECTORY_ثبت_TLS             9   /* TLS Directory */
#تعریف_کړه IMAGE_DIRECTORY_ثبت_بارول_CONFIG    10   /* Load Configuration Directory */
#تعریف_کړه IMAGE_DIRECTORY_ثبت_BOUND_IMPORT   11   /* Bound Import Directory in headers */
#تعریف_کړه IMAGE_DIRECTORY_ثبت_IAT            12   /* Import Address Table */
#تعریف_کړه IMAGE_DIRECTORY_ثبت_DELAY_IMPORT   13   /* Delay Load Import Descriptors */
#تعریف_کړه IMAGE_DIRECTORY_ثبت_COM_DESCRIPTOR 14   /* COM Runtime descriptor */

/* Section header format. */
#تعریف_کړه IMAGE_SIZEOF_SHORT_NAME         8

تعريفنوع بنية IMAGE_SECTION_سرلیک {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    اتحاد {
            DWORD   Physical_پته;
            DWORD   Virtual_اندازه;
    } Misc;
    DWORD   Virtual_پته;
    DWORD   اندازه_د_Raw_معلومات;
    DWORD   اشاره_ګر_منزل_Raw_معلومات;
    DWORD   اشاره_ګر_منزل_Relocations;
    DWORD   اشاره_ګر_منزل_Linenumbers;
    کلمه_3    شمېره_د_Relocations;
    کلمه_3    شمېره_د_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_سرلیک_2, *PIMAGE_SECTION_سرلیک;

#تعریف_کړه IMAGE_SIZEOF_SECTION_سرلیک     40

تعريفنوع بنية _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD وخت_Date_Stamp;
    کلمه_3 Major_نسخه;
    کلمه_3 Minor_نسخه;
    DWORD Name;
    DWORD بنسټ_2;
    DWORD شمېره_د_Functions;
    DWORD شمېره_د_نومونه;
    DWORD پته_د_Functions;
    DWORD پته_د_نومونه;
    DWORD پته_د_Name_Ordinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

تعريفنوع بنية _IMAGE_TLS_DIRECTORY {
    ADDR3264 پیل_پته_د_Raw_معلومات;
    ADDR3264 پای_ټکی_پته_د_Raw_معلومات;
    ADDR3264 پته_د_شاخص;
    ADDR3264 پته_د_Call_Backs;
    DWORD اندازه_د_Zero_Fill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

تعريفنوع بنية _IMAGE_IMPORT_DESCRIPTOR {
    اتحاد {
        DWORD Characteristics;
        DWORD Original_لومړی_Thunk;
    };
    DWORD وخت_Date_Stamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD لومړی_Thunk;
} IMAGE_IMPORT_DESCRIPTOR;

تعريفنوع بنية IMAGE_بنسټ_RELOCATION {
    DWORD   Virtual_پته;
    DWORD   اندازه_د_بلاک;
//  WORD    TypeOffset[1];
} IMAGE_بنسټ_RELOCATION_2;

#تعریف_کړه IMAGE_SIZEOF_بنسټ_RELOCATION     8

#تعریف_کړه IMAGE_REL_BASED_ABSOLUTE         0
#تعریف_کړه IMAGE_REL_BASED_لوړ             1
#تعریف_کړه IMAGE_REL_BASED_ټیټ              2
#تعریف_کړه IMAGE_REL_BASED_HIGHLOW          3
#تعریف_کړه IMAGE_REL_BASED_HIGHADJ          4
#تعریف_کړه IMAGE_REL_BASED_MIPS_JMPADDR     5
#تعریف_کړه IMAGE_REL_BASED_SECTION          6
#تعریف_کړه IMAGE_REL_BASED_REL32            7
#تعریف_کړه IMAGE_REL_BASED_DIR64           10

#تعریف_کړه IMAGE_SCN_CNT_کوډ                  0x00000020
#تعریف_کړه IMAGE_SCN_CNT_INITIALIZED_معلومات      0x00000040
#تعریف_کړه IMAGE_SCN_CNT_UNINITIALIZED_معلومات    0x00000080
#تعریف_کړه IMAGE_SCN_MEM_DISCARDABLE           0x02000000
#تعریف_کړه IMAGE_SCN_MEM_SHARED                0x10000000
#تعریف_کړه IMAGE_SCN_MEM_EXECUTE               0x20000000
#تعریف_کړه IMAGE_SCN_MEM_READ                  0x40000000
#تعریف_کړه IMAGE_SCN_MEM_WRITE                 0x80000000

#تعریف_کړه IMAGE_DLLCHARACTERISTICS_لوړ_ENTROPY_VA 0x0020
#تعریف_کړه IMAGE_DLLCHARACTERISTICS_DYNAMIC_بنسټ 0x0040
#تعریف_کړه IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#تعریف_کړه IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#تعریف_کړه IMAGE_FILE_RELOCS_STRIPPED 0x0001

#لارښوونه pack(راوباسه)

/* ----------------------------------------------------------- */
#د_که_پای /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#که_نه_تعریف_شوی IMAGE_DLLCHARACTERISTICS_DYNAMIC_بنسټ
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #تعریف_کړه IMAGE_DLLCHARACTERISTICS_DYNAMIC_بنسټ 0x0040
#د_که_پای

#لارښوونه pack(ټېل, 1)
بنية pe_سرلیک
{
    IMAGE_DOS_سرلیک_2 doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_سرلیک_2 filehdr;
#إذا PTR_اندازه == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#وإلا
#که_تعریف_شوی _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#وإلا
    IMAGE_OPTIONAL_سرلیک_2 opthdr;
#د_که_پای
#د_که_پای
};

بنية pe_reloc_سرلیک {
    DWORD دننه_واټن;
    DWORD اندازه;
};

بنية pe_rsrc_سرلیک {
    بنية IMAGE_FILE_سرلیک filehdr;
    بنية IMAGE_SECTION_سرلیک sectionhdr;
};

بنية pe_rsrc_reloc {
    DWORD دننه_واټن;
    DWORD اندازه;
    کلمه_3 type;
};
#لارښوونه pack(راوباسه)

/* ------------------------------------------------------------- */
/* internal temporary structures */

تعداد {
    sec_متن = 0,
    sec_rdata ,
    sec_معلومات ,
    sec_bss ,
    sec_idata ,
    sec_pdata ,
    sec_tdata ,
    sec_tbss ,
    sec_other ,
    sec_rsrc ,
    sec_debug ,
    sec_reloc ,
    sec_وروستی
};

#إذا 0
ساكن ثابت DWORD pe_sec_flags[] = {
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
#د_که_پای

بنية section_info {
    صحيح cls;
    حرف name[32];
    ADDR3264 sh_addr;
    DWORD sh_اندازه;
    DWORD pe_flags;
    Section *sec;
    DWORD معلومات_اندازه;
    IMAGE_SECTION_سرلیک_2 ish;
};

بنية import_نښه {
    صحيح sym_شاخص;
    صحيح iat_شاخص;
    صحيح thk_دننه_واټن;
};

بنية pe_import_info {
    صحيح dll_شاخص;
    صحيح sym_شمېر;
    بنية import_نښه **symbols;
};

بنية pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    ثابت حرف *filename;
    صحيح type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    ثابت حرف *پیل_نښه;
    DWORD پیل_addr;
    DWORD imp_offs;
    DWORD imp_اندازه;
    DWORD iat_offs;
    DWORD iat_اندازه;
    DWORD exp_offs;
    DWORD exp_اندازه;
    DWORD tls_dir;
    DWORD tls_معلومات;
    DWORD tls_اندازه;
    صحيح subsystem;
    DWORD section_align;
    DWORD file_align;
    بنية section_info **sec_info;
    صحيح sec_شمېر;
    بنية pe_import_info **imp_info;
    صحيح imp_شمېر;
    /* output */
    FILE *op;
    DWORD مجموعه;
    بینښه pos;
};

#تعریف_کړه PE_NUL 0
#تعریف_کړه PE_DLL 1
#تعریف_کړه PE_GUI 2
#تعریف_کړه PE_EXE 3
#تعریف_کړه PE_پرلپسې 4

/* --------------------------------------------*/

ساكن ثابت حرف *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    ثابت حرف *name = (حرف*)symtab_section->link->معلومات + sym->st_name;
    إذا (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        أرجع name + 1;
    أرجع name;
}


ساكن صحيح dynarray_assoc(فراغ **pp, صحيح n, صحيح کلی)
{
    صحيح i;
    لكل (i = 0; i < n; ++i, ++pp)
    إذا (کلی == **(صحيح **) pp)
        أرجع i;
    أرجع -1;
}

ساكن DWORD umin(DWORD a, DWORD b)
{
    أرجع a < b ? a : b;
}

ساكن DWORD umax(DWORD a, DWORD b)
{
    أرجع a < b ? b : a;
}

ساكن DWORD pe_file_align(بنية pe_info *pe, DWORD n)
{
    أرجع (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

ساكن ADDR3264 pe_virtual_align(بنية pe_info *pe, ADDR3264 n)
{
    أرجع (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

ساكن فراغ pe_align_section(Section *s, صحيح a)
{
    صحيح i = s->معلومات_دننه_واټن & (a-1);
    إذا (i)
        section_ptr_جمع_کړه(s, a - i);
}

ساكن فراغ pe_سېټ_datadir(بنية pe_سرلیک *hdr, صحيح dir, DWORD addr, DWORD اندازه)
{
    hdr->opthdr.معلومات_Directory[dir].Virtual_پته = addr;
    hdr->opthdr.معلومات_Directory[dir].اندازه_3 = اندازه;
}

ساكن صحيح pe_fwrite(بنية pe_info *pe, ثابت فراغ *معلومات, صحيح len)
{
    ثابت کلمه_3 *p = معلومات;
    DWORD مجموعه;
    صحيح ret, i;
    pe->pos += (ret = fwrite(معلومات, 1, len, pe->op));
    مجموعه = pe->مجموعه;
    لكل (i = len; i > 0; i -= 2) {
        مجموعه += (i >= 2) ? *p++ : *(BYTE*)p;
        مجموعه = (مجموعه + (مجموعه >> 16)) & 0xFFFF;
    }
    pe->مجموعه = مجموعه;
    أرجع len == ret ? 0 : -1;
}

ساكن فراغ pe_fpad(بنية pe_info *pe, DWORD new_pos)
{
    حرف buf[256];
    صحيح n, diff = new_pos - pe->pos;
    memset(buf, 0, حجم buf);
    طالما (diff > 0) {
        diff -= n = umin(diff, حجم buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#لارښوونه pack(ټېل, 1)
بنية syment
{
    اتحاد {
        حرف        n_name[8];     /* old COFF version */
        بنية {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_دننه_واټن_2;      /* offset into string table */
        };
    };
    int32_t         n_ارزښت;        /* value of symbol */
    لنډ           n_scnum;        /* section number */
    بینښه لنډ  n_type;         /* type and derived type */
    حرف            n_sclass;       /* storage class */
    حرف            n_numaux;       /* number of aux. entries */
};
#لارښوونه pack(راوباسه)

#تعریف_کړه SHF_شخصي 0x80000000

ساكن فراغ pe_جمع_کړه_coffsym(بنية pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    بنية syment *se;
    صحيح n;

    إذا (عدم == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_شخصي);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_شخصي);
        section_ptr_جمع_کړه(pe->coffstr, 4); /* coff string table size */
        أرجع;
    }

#إذا 0
    se = section_ptr_جمع_کړه(pe->coffsym, حجم *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_جمع_کړه(pe->coffsym, حجم *se);
    strcpy((حرف*)se, "no-file");
#د_که_پای

#إذا 1
    esym = (ElfSym*)s1->symtab->معلومات;
    لكل (n = s1->symtab->معلومات_دننه_واټن / حجم *esym; ++esym, --n;) {
        صحيح sym_bind = ELFW(ST_BIND)(esym->st_info);
        إذا (sym_bind == STB_GLOBAL) {
            حرف *name = esym->st_name + (حرف*)s1->symtab->link->معلومات;
            صحيح nl = مزي_اوږدوالی(name);
            addr_t ارزښت = esym->st_ارزښت;
            صحيح shnum = esym->st_shndx;
            إذا (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                ارزښت = ارزښت - s->sh_addr;
            }
            se = section_ptr_جمع_کړه(pe->coffsym, حجم *se);
            se->n_ارزښت = ارزښت;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            إذا (nl <= 8)
                حافظه_نقل(se->n_name, name, nl);
            وإلا
                se->n_دننه_واټن_2 = put_elf_str(pe->coffstr, name);
        }
    }
#د_که_پای
    write32le(pe->coffstr->معلومات, pe->coffstr->معلومات_دننه_واټن); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
ساكن فراغ pe_create_pdb(TCCState *s1, ثابت حرف *exename)
{
    حرف buf[300]; صحيح r;
    snprintf(buf, حجم buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    strcpy(tcc_fileextension(strcpy(buf, exename)), ".pdb");
    إذا (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } وإلا إذا (s1->verbose) {
        چاپ_کړه("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
ساكن صحيح pe_write(بنية pe_info *pe)
{
    ساكن ثابت بنية pe_سرلیک pe_template = {
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
    0x00E0 + (PTR_اندازه-4)*4, /*WORD    SizeOfOptionalHeader; */
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
#إذا PTR_اندازه == 4
    0x00000000, /*DWORD   BaseOfData; */
#د_که_پای
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

    بنية pe_سرلیک pe_سرلیک = pe_template;

    صحيح i;
    DWORD file_دننه_واټن;
    بنية section_info *si;
    IMAGE_SECTION_سرلیک_2 *psh;
    TCCState *s1 = pe->s1;

    إذا (s1->do_debug)
        pe_جمع_کړه_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    إذا (عدم == pe->op)
        أرجع tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        حجم (بنية pe_سرلیک)
        + pe->sec_شمېر * حجم (IMAGE_SECTION_سرلیک_2)
        );

    file_دننه_واټن = pe->sizeofheaders;

    إذا (2 == s1->verbose)
        چاپ_کړه("-------------------------------"
               "\n  virt   file   size  section" "\n");
    لكل (i = 0; i < pe->sec_شمېر; ++i) {
        DWORD addr, اندازه;
        ثابت حرف *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        اندازه = si->sh_اندازه;
        psh = &si->ish;

        إذا (2 == s1->verbose)
            چاپ_کړه("%6x %6x %6x  %s\n",
                (بینښه)addr, (بینښه)file_دننه_واټن, (بینښه)اندازه, sh_name);

        بدل (si->cls) {
            حالة sec_متن:
                إذا (!pe_سرلیک.opthdr.بنسټ_د_کوډ)
                    pe_سرلیک.opthdr.بنسټ_د_کوډ = addr;
                اكسر;

            حالة sec_معلومات:
#إذا PTR_اندازه == 4
                إذا (!pe_سرلیک.opthdr.بنسټ_د_معلومات)
                    pe_سرلیک.opthdr.بنسټ_د_معلومات = addr;
#د_که_پای
                اكسر;

            حالة sec_bss:
                اكسر;

            حالة sec_reloc:
                pe_سېټ_datadir(&pe_سرلیک, IMAGE_DIRECTORY_ثبت_BASERELOC, addr, اندازه);
                اكسر;

            حالة sec_rsrc:
                pe_سېټ_datadir(&pe_سرلیک, IMAGE_DIRECTORY_ثبت_RESOURCE, addr, اندازه);
                اكسر;

            حالة sec_pdata:
                pe_سېټ_datadir(&pe_سرلیک, IMAGE_DIRECTORY_ثبت_EXCEPTION, addr, اندازه);
                اكسر;
        }

        إذا (pe->imp_اندازه) {
            pe_سېټ_datadir(&pe_سرلیک, IMAGE_DIRECTORY_ثبت_IMPORT,
                pe->imp_offs, pe->imp_اندازه);
            pe_سېټ_datadir(&pe_سرلیک, IMAGE_DIRECTORY_ثبت_IAT,
                pe->iat_offs, pe->iat_اندازه);
        }
        إذا (pe->exp_اندازه) {
            pe_سېټ_datadir(&pe_سرلیک, IMAGE_DIRECTORY_ثبت_EXPORT,
                pe->exp_offs, pe->exp_اندازه);
        }
        إذا (pe->tls_اندازه) {
            pe_سېټ_datadir(&pe_سرلیک, IMAGE_DIRECTORY_ثبت_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_اندازه);
        }

        حافظه_نقل(psh->Name, sh_name, umin(مزي_اوږدوالی(sh_name), حجم psh->Name));
        إذا (pe->coffstr && مزي_اوږدوالی(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((حرف*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->Virtual_پته = addr;
        psh->Misc.Virtual_اندازه = اندازه;
        pe_سرلیک.opthdr.اندازه_د_Image =
            umax(pe_virtual_align(pe, اندازه + addr), pe_سرلیک.opthdr.اندازه_د_Image);

        إذا (si->معلومات_اندازه) {
            psh->اشاره_ګر_منزل_Raw_معلومات = file_دننه_واټن;
            file_دننه_واټن = pe_file_align(pe, file_دننه_واټن + si->معلومات_اندازه);
            psh->اندازه_د_Raw_معلومات = file_دننه_واټن - psh->اشاره_ګر_منزل_Raw_معلومات;
            إذا (si->cls == sec_متن)
                pe_سرلیک.opthdr.اندازه_د_کوډ += psh->اندازه_د_Raw_معلومات;
            وإلا
                pe_سرلیک.opthdr.اندازه_د_Initialized_معلومات += psh->اندازه_د_Raw_معلومات;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_سرلیک.filehdr.شمېره_د_Sections = pe->sec_شمېر;
    pe_سرلیک.opthdr.پته_د_ثبت_ټکی = pe->پیل_addr;
    pe_سرلیک.opthdr.اندازه_د_سرلیکونه = pe->sizeofheaders;
    pe_سرلیک.opthdr.Image_بنسټ = pe->imagebase;
    pe_سرلیک.opthdr.Subsystem = pe->subsystem;
    pe_سرلیک.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    إذا (s1->pe_ډېری_اندازه)
        pe_سرلیک.opthdr.اندازه_د_ډېری_Reserve = s1->pe_ډېری_اندازه;
    إذا (PE_DLL == pe->type)
        pe_سرلیک.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_سرلیک.filehdr.Characteristics |= s1->pe_characteristics;
    إذا (pe->reloc)
        pe_سرلیک.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    إذا (pe->coffsym) {
        pe_جمع_کړه_coffsym(pe);
        pe_سرلیک.filehdr.اشاره_ګر_منزل_نښه_جدول = file_دننه_واټن;
        pe_سرلیک.filehdr.شمېره_د_Symbols
            = pe->coffsym->معلومات_دننه_واټن / حجم (بنية syment);
    }

    pe_fwrite(pe, &pe_سرلیک, حجم pe_سرلیک);
    لكل (i = 0; i < pe->sec_شمېر; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, حجم(IMAGE_SECTION_سرلیک_2));

    file_دننه_واټن = pe->sizeofheaders;
    لكل (i = 0; i < pe->sec_شمېر; ++i) {
        Section *s;
        si = pe->sec_info[i];
        إذا (!si->معلومات_اندازه)
            استمر;
        لكل (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_دننه_واټن);
            pe_fwrite(pe, s->معلومات, s->معلومات_دننه_واټن);
            إذا (s->prev)
                file_دننه_واټن += s->prev->sh_addr - s->sh_addr;
        }
        file_دننه_واټن = si->ish.اشاره_ګر_منزل_Raw_معلومات + si->ish.اندازه_د_Raw_معلومات;
        pe_fpad(pe, file_دننه_واټن);
    }

    إذا (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->معلومات, pe->coffsym->معلومات_دننه_واټن);
        pe_fwrite(pe, pe->coffstr->معلومات, pe->coffstr->معلومات_دننه_واټن);
        file_دننه_واټن = pe->pos;
    }

    pe->مجموعه += file_دننه_واټن;
    fseek(pe->op, offsetof(بنية pe_سرلیک, opthdr.Check_مجموعه), SEEK_SET);
    pe_fwrite(pe, &pe->مجموعه, حجم (DWORD));

    fclose (pe->op);
#که_نه_تعریف_شوی _WIN32
    chmod(pe->filename, 0777);
#د_که_پای

    إذا (2 == s1->verbose)
        چاپ_کړه("-------------------------------\n");
    إذا (s1->verbose)
        چاپ_کړه("<- %s (%u bytes)\n", pe->filename, (بینښه)file_دننه_واټن);

    إذا (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    أرجع 0;
}

/*----------------------------------------------------------------------------*/

ساكن بنية import_نښه *pe_جمع_کړه_import(بنية pe_info *pe, صحيح sym_شاخص)
{
    صحيح i;
    صحيح dll_شاخص;
    بنية pe_import_info *p;
    بنية import_نښه *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->معلومات + sym_شاخص;
    dll_شاخص = isym->st_اندازه;

    i = dynarray_assoc ((فراغ**)pe->imp_info, pe->imp_شمېر, dll_شاخص);
    إذا (-1 != i) {
        p = pe->imp_info[i];
        اذهب وموندل_dll;
    }
    p = tcc_mallocz(حجم *p);
    p->dll_شاخص = dll_شاخص;
    dynarray_جمع_کړه(&pe->imp_info, &pe->imp_شمېر, p);

وموندل_dll:
    i = dynarray_assoc ((فراغ**)p->symbols, p->sym_شمېر, sym_شاخص);
    إذا (-1 != i)
        أرجع p->symbols[i];

    s = tcc_mallocz(حجم *s);
    dynarray_جمع_کړه(&p->symbols, &p->sym_شمېر, s);
    s->sym_شاخص = sym_شاخص;
    أرجع s;
}

ساكن فراغ pe_free_imports(بنية pe_info *pe)
{
    صحيح i;
    لكل (i = 0; i < pe->imp_شمېر; ++i) {
        بنية pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_شمېر);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_شمېر);
}

/*----------------------------------------------------------------------------*/
ساكن فراغ pe_build_imports(بنية pe_info *pe)
{
    صحيح thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_بنسټ = pe->thunk->sh_addr - pe->imagebase;
    صحيح ndlls = pe->imp_شمېر;
    TCCState *s1 = pe->s1;

    لكل (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_شمېر;

    إذا (0 == sym_cnt)
        أرجع;

    pe_align_section(pe->thunk, 16);
    pe->imp_اندازه = (ndlls + 1) * حجم(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_اندازه = (sym_cnt + ndlls) * حجم(ADDR3264);
    dll_ptr = pe->thunk->معلومات_دننه_واټن;
    thk_ptr = dll_ptr + pe->imp_اندازه;
    ent_ptr = thk_ptr + pe->iat_اندازه;
    pe->imp_offs = dll_ptr + rva_بنسټ;
    pe->iat_offs = thk_ptr + rva_بنسټ;
    section_ptr_جمع_کړه(pe->thunk, pe->imp_اندازه + 2*pe->iat_اندازه);

    لكل (i = 0; i < pe->imp_شمېر; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        صحيح k, n, dllindex;
        ADDR3264 v;
        بنية pe_import_info *p = pe->imp_info[i];
        ثابت حرف *name;
        DLLReference *dllref;

        dllindex = p->dll_شاخص;
        إذا (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        وإلا
            name = "", dllref = عدم;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->معلومات + dll_ptr);
        hdr->لومړی_Thunk = thk_ptr + rva_بنسټ;
        hdr->Original_لومړی_Thunk = ent_ptr + rva_بنسټ;
        hdr->Name = v + rva_بنسټ;

        لكل (k = 0, n = p->sym_شمېر; k <= n; ++k) {
            إذا (k < n) {
                صحيح iat_شاخص = p->symbols[k]->iat_شاخص;
                صحيح sym_شاخص = p->symbols[k]->sym_شاخص;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->معلومات + sym_شاخص;
                ثابت حرف *name = (حرف*)s1->dynsymtab_section->link->معلومات + imp_sym->st_name;
                صحيح ordinal;

                /* patch symbol (and possibly its underscored alias) */
                افعل {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->معلومات + iat_شاخص;
                    iat_شاخص = esym->st_ارزښت;
                    esym->st_ارزښت = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_عدد;
                } طالما (iat_شاخص);

                إذا (dllref)
                    v = 0, ordinal = imp_sym->st_ارزښت; /* ordinal from pe_load_def */
                وإلا
                    ordinal = 0, v = imp_sym->st_ارزښت; /* address from tcc_add_symbol() */

#که_تعریف_شوی TCC_IS_NATIVE
                إذا (pe->type == PE_پرلپسې) {
                    إذا (dllref) {
                        إذا ( !dllref->handle )
                            dllref->handle = بارول_Library_A(dllref->name);
                        v = (ADDR3264)Get_Proc_پته(dllref->handle, ordinal?(حرف*)0+ordinal:name);
                    }
                    إذا (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } وإلا
#د_که_پای
                إذا (ordinal) {
                    v = ordinal | (ADDR3264)1 << (حجم(ADDR3264)*8 - 1);
                } وإلا {
                    v = pe->thunk->معلومات_دننه_واټن + rva_بنسټ;
                    section_ptr_جمع_کړه(pe->thunk, حجم(کلمه_3)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } وإلا {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->معلومات+thk_ptr) =
            *(ADDR3264*)(pe->thunk->معلومات+ent_ptr) = v;
            thk_ptr += حجم (ADDR3264);
            ent_ptr += حجم (ADDR3264);
        }
        dll_ptr += حجم(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

بنية pe_ترتیبول_sym
{
    صحيح شاخص;
    ثابت حرف *name;
};

ساكن صحيح sym_cmp(ثابت فراغ *va, ثابت فراغ *vb)
{
    ثابت حرف *ca = (*(بنية pe_ترتیبول_sym**)va)->name;
    ثابت حرف *cb = (*(بنية pe_ترتیبول_sym**)vb)->name;
    أرجع strcmp(ca, cb);
}

ساكن فراغ pe_build_exports(بنية pe_info *pe)
{
    ElfW(Sym) *sym;
    صحيح sym_شاخص, sym_پای_ټکی;
    DWORD rva_بنسټ, بنسټ_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    صحيح sym_شمېر, ord;
    بنية pe_ترتیبول_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    حرف buf[260];
    ثابت حرف *dllname;
    ثابت حرف *name;

    rva_بنسټ = pe->thunk->sh_addr - pe->imagebase;
    sym_شمېر = 0, sorted = عدم, op = عدم;

    sym_پای_ټکی = symtab_section->معلومات_دننه_واټن / حجم(ElfW(Sym));
    لكل (sym_شاخص = 1; sym_شاخص < sym_پای_ټکی; ++sym_شاخص) {
        sym = (ElfW(Sym)*)symtab_section->معلومات + sym_شاخص;
        name = pe_export_name(s1, sym);
        إذا (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(حجم *p);
            p->شاخص = sym_شاخص;
            p->name = name;
            dynarray_جمع_کړه(&sorted, &sym_شمېر, p);
        }
#إذا 0
        إذا (sym->st_other & ST_PE_EXPORT)
            چاپ_کړه("export: %s\n", name);
        إذا (sym->st_other & ST_PE_STDCALL)
            چاپ_کړه("stdcall: %s\n", name);
#د_که_پای
    }

    إذا (0 == sym_شمېر)
        أرجع;

    qsort (sorted, sym_شمېر, حجم *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    بنسټ_o = pe->thunk->معلومات_دننه_واټن;
    func_o = بنسټ_o + حجم(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_شمېر * حجم (DWORD);
    ord_o = name_o + sym_شمېر * حجم (DWORD);
    str_o = ord_o + sym_شمېر * حجم(کلمه_3);

    hdr = section_ptr_جمع_کړه(pe->thunk, str_o - بنسټ_o);
    hdr->Characteristics        = 0;
    hdr->بنسټ_2                   = 1;
    hdr->شمېره_د_Functions      = sym_شمېر;
    hdr->شمېره_د_نومونه          = sym_شمېر;
    hdr->پته_د_Functions     = func_o + rva_بنسټ;
    hdr->پته_د_نومونه         = name_o + rva_بنسټ;
    hdr->پته_د_Name_Ordinals  = ord_o + rva_بنسټ;
    hdr->Name                   = str_o + rva_بنسټ;
    put_elf_str(pe->thunk, dllname);

#إذا 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, حجم buf, pe->filename);
    strcpy(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    إذا (عدم == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } وإلا {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        إذا (s1->verbose)
            چاپ_کړه("<- %s (%d symbol%s)\n", buf, sym_شمېر, &"s"[sym_شمېر < 2]);
    }
#د_که_پای

    لكل (ord = 0; ord < sym_شمېر; ++ord)
    {
        p = sorted[ord], sym_شاخص = p->شاخص, name = p->name;
        /* insert actual address later in relocate_sections() */
        put_elf_reloc(symtab_section, pe->thunk,
            func_o, R_XXX_RELATIVE, sym_شاخص);
        *(DWORD*)(pe->thunk->معلومات + name_o)
            = pe->thunk->معلومات_دننه_واټن + rva_بنسټ;
        *(کلمه_3*)(pe->thunk->معلومات + ord_o)
            = ord;
        put_elf_str(pe->thunk, name);
        func_o += حجم (DWORD);
        name_o += حجم (DWORD);
        ord_o += حجم (کلمه_3);
        إذا (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = بنسټ_o + rva_بنسټ;
    pe->exp_اندازه = pe->thunk->معلومات_دننه_واټن - بنسټ_o;
    dynarray_reset(&sorted, &sym_شمېر);
    إذا (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
ساكن فراغ pe_build_reloc (بنية pe_info *pe)
{
    DWORD دننه_واټن, بلاک_ptr, sh_addr, addr;
    صحيح شمېر_2, i;
    ElfW_Rel *rel, *rel_پای_ټکی;
    Section *s = عدم, *sr;
    بنية pe_reloc_سرلیک *hdr;
    TCCState *s1 = pe->s1;
    صحيح dwarf = 0, n;

    sh_addr = دننه_واټن = بلاک_ptr = شمېر_2 = i = 0;
    rel = rel_پای_ټکی = عدم;

    لكل(;;) {
        إذا (rel < rel_پای_ټکی) {
            صحيح type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_دننه_واټن + sh_addr;
            ++ rel;
            إذا (type != REL_TYPE_مستقیم)
                استمر;
            إذا (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->معلومات + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                إذا (n >= s1->dwlo && n < s1->dwhi)
                    استمر;
            }
            إذا (شمېر_2 == 0) { /* new block */
                بلاک_ptr = pe->reloc->معلومات_دننه_واټن;
                section_ptr_جمع_کړه(pe->reloc, حجم(بنية pe_reloc_سرلیک));
                دننه_واټن = addr & 0xFFFFFFFF<<12;
            }
            إذا ((addr -= دننه_واټن)  < (1<<12)) { /* one block spans 4k addresses */
                کلمه_3 *wp = section_ptr_جمع_کړه(pe->reloc, حجم (کلمه_3));
                *wp = addr | PE_IMAGE_REL<<12;
                ++شمېر_2;
                استمر;
            }
            -- rel;

        } وإلا إذا (s) {
            sr = s->reloc;
            إذا (sr) {
                rel = (ElfW_Rel *)sr->معلومات;
                rel_پای_ټکی = (ElfW_Rel *)(sr->معلومات + sr->معلومات_دننه_واټن);
                sh_addr = s->sh_addr;
                dwarf = s->sh_عدد >= s1->dwlo && s->sh_عدد < s1->dwhi;
            }
            s = s->prev;
            استمر;

        } وإلا إذا (i < pe->sec_شمېر) {
            s = pe->sec_info[i]->sec, ++i;
            استمر;

        } وإلا إذا (!شمېر_2)
            اكسر;

        /* fill the last block and ready for a new one */
        إذا (شمېر_2 & 1) /* align for DWORDS */
            section_ptr_جمع_کړه(pe->reloc, حجم(کلمه_3)), ++شمېر_2;
        hdr = (بنية pe_reloc_سرلیک *)(pe->reloc->معلومات + بلاک_ptr);
        hdr -> دننه_واټن = دننه_واټن - pe->imagebase;
        hdr -> اندازه = شمېر_2 * حجم(کلمه_3) + حجم(بنية pe_reloc_سرلیک);
        شمېر_2 = 0;
    }
}

/* ------------------------------------------------------------- */
ساكن فراغ pe_build_tls(بنية pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    صحيح c, n;

    إذا (0 == s) {
        pe->tls_اندازه = حجم (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_جمع_کړه(pe->thunk, pe->tls_اندازه, 16);
        pe->tls_معلومات = section_جمع_کړه(معلومات_section, PTR_اندازه * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, معلومات_section->sh_عدد, 0);
        لكل (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_اندازه*n, REL_TYPE_مستقیم, c);
        /* for generators */
        سېټ_elf_sym(symtab_section, pe->tls_معلومات, PTR_اندازه * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, معلومات_section->sh_عدد, "__tls_index");
        أرجع;
    }

    إذا (0 == s1->tls_پیل)
        s1->tls_پیل = s->sh_addr;
    d = (فراغ*)(pe->thunk->معلومات + pe->tls_dir);
    d->پیل_پته_د_Raw_معلومات = s1->tls_پیل - معلومات_section->sh_addr;
    d->پای_ټکی_پته_د_Raw_معلومات = s->sh_addr + s->معلومات_دننه_واټن - معلومات_section->sh_addr;
    d->پته_د_شاخص = pe->tls_معلومات;
    d->پته_د_Call_Backs = pe->tls_معلومات + PTR_اندازه;
    d->اندازه_د_Zero_Fill = 0;
    d->Characteristics = 0;
    /* to reuse logic from linux in xxx-link.c */
    s1->tls_پای_ټکی = s1->tls_پیل;
}

/* ------------------------------------------------------------- */
ساكن صحيح pe_section_class(Section *s)
{
    صحيح type, flags;
    ثابت حرف *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    إذا (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        أرجع sec_debug;
    } وإلا إذا (flags & SHF_ALLOC) {
        إذا (flags & SHF_TLS)
            أرجع sec_tdata + (type == SHT_NOBITS);
        إذا (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            إذا (flags & SHF_EXECINSTR)
                أرجع sec_متن;
            إذا (flags & SHF_WRITE)
                أرجع sec_معلومات;
            إذا (0 == strcmp(name, ".rsrc"))
                أرجع sec_rsrc;
            إذا (0 == strcmp(name, ".iedat"))
                أرجع sec_idata;
            إذا (0 == strcmp(name, ".pdata"))
                أرجع sec_pdata;
            أرجع sec_rdata;
        } وإلا إذا (type == SHT_NOBITS) {
            أرجع sec_bss;
        }
        أرجع sec_other;
    } وإلا {
        إذا (0 == strcmp(name, ".reloc"))
            أرجع sec_reloc;
    }
    أرجع sec_وروستی;
}

ساكن صحيح pe_ټاکل_پتې (بنية pe_info *pe)
{
    صحيح i, k, n, c, nbs;
    ADDR3264 addr;
    صحيح *sec_ترتیب, *sec_cls;
    بنية section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    إذا (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_بنسټ))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_ترتیب = tcc_mallocz(2 * حجم (صحيح) * nbs);
    sec_cls = sec_ترتیب + nbs;
    لكل (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        لكل (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_ترتیب[n] = sec_ترتیب[n - 1];
        sec_cls[n] = k, sec_ترتیب[n] = i;
        إذا ((s->sh_flags & SHF_TLS) && 0 == pe->tls_اندازه)
            pe_build_tls(pe, عدم);
    }
    si = عدم;
    addr = pe->imagebase + 1;
    لكل (i = 1; (c = sec_cls[i]) < sec_وروستی; ++i) {
        s = s1->sections[sec_ترتیب[i]];

        إذا (PE_یوځای_معلومات && c == sec_bss)
            c = sec_معلومات;
        إذا (c == sec_tbss)
            c = sec_tdata;

        إذا (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } وإلا {
            si = عدم;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        إذا (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        إذا (s == pe->reloc)
            pe_build_reloc (pe);

        إذا (0 == s->معلومات_دننه_واټن)
            استمر;

        إذا (si)
            اذهب جمع_کړه_section;

        si = tcc_mallocz(حجم *si);
        dynarray_جمع_کړه(&pe->sec_info, &pe->sec_شمېر, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        إذا (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_کوډ;
        وإلا إذا (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_معلومات;
        وإلا
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_معلومات;
        إذا (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        إذا (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

جمع_کړه_section:
        s->sh_info = pe->sec_شمېر; /* section number for coff syms */
        addr += s->معلومات_دننه_واټن;
        si->sh_اندازه = addr - si->sh_addr;
        إذا (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            طالما (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = عدم;
            si->معلومات_اندازه = si->sh_اندازه;
        }

        إذا (s->sh_flags & SHF_TLS) {
            strcpy(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#إذا 0
    لكل (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_ترتیب[i]];
        صحيح type = s->sh_type;
        صحيح flags = s->sh_flags;
        چاپ_کړه("section %-16s %-10s %p %04x %2d %s,%s,%s\n",
            s->name,
            type == SHT_PROGBITS ? "progbits" :
            type == SHT_INIT_ARRAY ? "initarr" :
            type == SHT_FINI_ARRAY ? "finiarr" :
            type == SHT_NOBITS ? "nobits" :
            type == SHT_SYMTAB ? "symtab" :
            type == SHT_STRTAB ? "strtab" :
            type == SHT_RELX ? "rel" : "???",
            s->sh_addr,
            (بینښه)s->معلومات_دننه_واټن,
            s->sh_addralign,
            flags & SHF_ALLOC ? "alloc" : "",
            flags & SHF_WRITE ? "write" : "",
            flags & SHF_EXECINSTR ? "exec" : ""
            );
        fflush(stdout);
    }
    s1->verbose = 2;
#د_که_پای
    tcc_free(sec_ترتیب);
    أرجع 0;
}

/*----------------------------------------------------------------------------*/
ساكن صحيح pe_check_symbols(بنية pe_info *pe)
{
    صحيح sym_شاخص, sym_پای_ټکی;
    صحيح ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(متن_section, 8);

    sym_پای_ټکی = symtab_section->معلومات_دننه_واټن / حجم(ElfW(Sym));
    لكل (sym_شاخص = 1; sym_شاخص < sym_پای_ټکی; ++sym_شاخص) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->معلومات + sym_شاخص;
        إذا (sym->st_shndx == SHN_UNDEF) {
            ثابت حرف *name = (حرف*)symtab_section->link->معلومات + sym->st_name;
            بینښه type = ELFW(ST_TYPE)(sym->st_info);
            صحيح imp_sym = 0;
            بنية import_نښه *is;

            صحيح _imp_, n;
            حرف بفر[200];
            ثابت حرف *s, *p;

            n = _imp_ = 0;
            إذا (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            افعل {
                s = pe_export_name(s1, sym);
                إذا (n) {
                    /* second try: */
                    إذا (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        إذا (!p || s[0] != '_')
                            اكسر;
                        strcpy(بفر, s+1)[p-s-1] = 0, s = بفر;
                    } وإلا إذا (s[0] != '_') { /* try non-ansi function */
                        بفر[0] = '_', strcpy(بفر + 1, s), s = بفر;
                    } وإلا إذا (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } وإلا إذا (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } وإلا {
                        اكسر;
                    }
                }
                imp_sym = پیدا_کړه_elf_sym(s1->dynsymtab_section, s);
            } طالما (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            إذا (0 == imp_sym)
                استمر; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_جمع_کړه_import(pe, imp_sym);

            إذا (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                بینښه دننه_واټن = is->thk_دننه_واټن;
                إذا (دننه_واټن) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } وإلا {
                    بینښه حرف *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(بفر, "IAT.%s", name);
                    is->iat_شاخص = put_elf_sym(
                        symtab_section, 0, حجم(DWORD),
                        ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT),
                        0, SHN_UNDEF, بفر);

                    دننه_واټن = متن_section->معلومات_دننه_واټن;
                    is->thk_دننه_واټن = دننه_واټن;

                    /* add the 'jmp IAT[x]' instruction */
#که_تعریف_شوی TCC_موخه_ARM
                    p = section_ptr_جمع_کړه(متن_section, 8+4); // room for code and address
                    write32le(p + 0, 0xE59FC000); // arm code ldr ip, [pc] ; PC+8+0 = 0001xxxx
                    write32le(p + 4, 0xE59CF000); // arm code ldr pc, [ip]
                    put_elf_reloc(symtab_section, متن_section,
                        دننه_واټن + 8, R_XXX_THUNKFIX, is->iat_شاخص); // offset to IAT position
#وإلاإذا defined(TCC_موخه_ARM64)
                    p = section_ptr_جمع_کړه(متن_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, متن_section,
                        دننه_واټن + 16, R_XXX_THUNKFIX, is->iat_شاخص);
#وإلا
                    p = section_ptr_جمع_کړه(متن_section, 8);
                    write16le(p, 0x25FF);
#که_تعریف_شوی TCC_موخه_X86_64
                    write32le(p + 2, (DWORD)-4);
#د_که_پای
                    put_elf_reloc(symtab_section, متن_section, 
                        دننه_واټن + 2, R_XXX_THUNKFIX, is->iat_شاخص);
#د_که_پای
                }
                /* tcc_realloc might have altered sym's address */
                sym = (ElfW(Sym) *)symtab_section->معلومات + sym_شاخص;
                /* patch the original symbol */
                sym->st_ارزښت = دننه_واټن;
                sym->st_shndx = متن_section->sh_عدد;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } وإلا { /* STT_OBJECT */
                إذا (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_ارزښت = is->iat_شاخص; /* chain potential alias */
                is->iat_شاخص = sym_شاخص;
            }

        } وإلا إذا (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    أرجع ret;
}

/*----------------------------------------------------------------------------*/
#إذا PE_PRINT_SECTIONS
ساكن فراغ pe_print_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    صحيح i, n, l, m;
    p = s->معلومات;
    e = s->معلومات + s->معلومات_دننه_واټن;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    إذا (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    إذا (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (بینښه)s->sh_addr);
    fprintf(f, "\ncontents %08X", (بینښه)l);
    fprintf(f, "\n\n");

    إذا (s->sh_type == SHT_NOBITS)
        أرجع;

    إذا (0 == l)
        أرجع;

    إذا (s->sh_type == SHT_SYMTAB)
        m = حجم(ElfW(Sym));
    وإلا إذا (s->sh_type == SHT_RELX)
        m = حجم(ElfW_Rel);
    وإلا
        m = 16;

    fprintf(f, "%-8s", "offset");
    لكل (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    إذا (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        ثابت حرف *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            عدم
        };

        ثابت حرف *fields2[] = {
            "offs",
            "type",
            "symb",
            عدم
        };

        ثابت حرف **p;

        إذا (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        وإلا
            p = fields2, n = 58;

        لكل (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    لكل (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    لكل (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        لكل (n = 0; n < m; ++n) {
            إذا (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            وإلا
                fprintf(f, "   ");
        }

        إذا (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            ثابت حرف *name = s->link->معلومات + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (بینښه)sym->st_name,
                    (بینښه)sym->st_ارزښت,
                    (بینښه)sym->st_اندازه,
                    (بینښه)ELFW(ST_BIND)(sym->st_info),
                    (بینښه)ELFW(ST_TYPE)(sym->st_info),
                    (بینښه)sym->st_other,
                    (بینښه)sym->st_shndx,
                    name);

        } وإلا إذا (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->معلومات + ELFW(R_SYM)(rel->r_info);
            ثابت حرف *name = s->link->link->معلومات + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (بینښه)rel->r_دننه_واټن,
                    (بینښه)ELFW(R_TYPE)(rel->r_info),
                    (بینښه)ELFW(R_SYM)(rel->r_info),
                    name);
        } وإلا {
            fprintf(f, "   ");
            لكل (n = 0; n < m; ++n) {
                إذا (n + i < l) {
                    b = p[i + n];
                    إذا (b < 32 || b >= 127)
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

ساكن فراغ pe_print_sections(TCCState *s1, ثابت حرف *fname)
{
    Section *s;
    FILE *f;
    صحيح i;
    f = fopen(fname, "w");
    لكل (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    fclose(f);
}
#د_که_پای

/* ------------------------------------------------------------- */

ST_FUNC صحيح pe_putimport(TCCState *s1, صحيح dllindex, ثابت حرف *name, addr_t ارزښت)
{
    أرجع سېټ_elf_sym(
        s1->dynsymtab_section,
        ارزښت,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        ارزښت ? SHN_ABS : SHN_UNDEF,
        name
        );
}

ساكن صحيح read_mem(صحيح fd, بینښه دننه_واټن, فراغ *بفر, بینښه len)
{
    lseek(fd, دننه_واټن, SEEK_SET);
    أرجع len == اقرأ(fd, بفر, len);
}

/* ------------------------------------------------------------- */

ساكن صحيح get_dllexports(صحيح fd, حرف **pp)
{
    صحيح i, k, l, n, n0, ret;
    حرف *p;

    IMAGE_SECTION_سرلیک_2 ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_سرلیک_2 dh;
    IMAGE_FILE_سرلیک_2 ih;
    DWORD sig, ref, addr;
    DWORD *namep = عدم, p0 = 0, p1;

    صحيح pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = عدم;
    ret = 1;
    إذا (!read_mem(fd, 0, &dh, حجم dh))
        اذهب the_پای_ټکی;
    إذا (!read_mem(fd, dh.e_lfanew, &sig, حجم sig))
        اذهب the_پای_ټکی;
    إذا (sig != 0x00004550)
        اذهب the_پای_ټکی;
    pef_hdroffset = dh.e_lfanew + حجم sig;
    إذا (!read_mem(fd, pef_hdroffset, &ih, حجم ih))
        اذهب the_پای_ټکی;
    opt_hdroffset = pef_hdroffset + حجم ih;
    إذا (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + حجم oh;
        إذا (!read_mem(fd, opt_hdroffset, &oh, حجم oh))
            اذهب the_پای_ټکی;
        إذا (IMAGE_DIRECTORY_ثبت_EXPORT >= oh.شمېره_د_Rva_And_Sizes)
            اذهب the_پای_ټکی_0;
        addr = oh.معلومات_Directory[IMAGE_DIRECTORY_ثبت_EXPORT].Virtual_پته;
    } وإلا إذا (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + حجم oh;
        إذا (!read_mem(fd, opt_hdroffset, &oh, حجم oh))
            اذهب the_پای_ټکی;
        إذا (IMAGE_DIRECTORY_ثبت_EXPORT >= oh.شمېره_د_Rva_And_Sizes)
            اذهب the_پای_ټکی_0;
        addr = oh.معلومات_Directory[IMAGE_DIRECTORY_ثبت_EXPORT].Virtual_پته;
    } وإلا
        اذهب the_پای_ټکی;

    //printf("addr: %08x\n", addr);
    لكل (i = 0; i < ih.شمېره_د_Sections; ++i) {
        إذا (!read_mem(fd, sec_hdroffset + i * حجم ish, &ish, حجم ish))
            اذهب the_پای_ټکی;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        إذا (addr >= ish.Virtual_پته && addr < ish.Virtual_پته + ish.اندازه_د_Raw_معلومات)
            اذهب وموندل;
    }
    اذهب the_پای_ټکی_0;
وموندل:
    ref = ish.Virtual_پته - ish.اشاره_ګر_منزل_Raw_معلومات;
    إذا (!read_mem(fd, addr - ref, &ied, حجم ied))
        اذهب the_پای_ټکی;
    k = ied.شمېره_د_نومونه;
    إذا (k) {
        namep = tcc_malloc(l = k * حجم *namep);
        إذا (!read_mem(fd, ied.پته_د_نومونه - ref, namep, l))
            اذهب the_پای_ټکی;
        لكل (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            إذا (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            افعل {
                إذا (0 == l) {
                    إذا (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    إذا ((l = اقرأ(fd, p + n, 1000 - 1)) <= 0)
                        اذهب the_پای_ټکی;
                }
                --l, ++p0;
            } طالما (p[n++]);
        }
        p[n] = 0;
    }
the_پای_ټکی_0:
    ret = 0;
the_پای_ټکی:
    tcc_free(namep);
    إذا (ret && p)
        tcc_free(p), p = عدم;
    *pp = p;
    أرجع ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

ساكن صحيح pe_بارول_res(TCCState *s1, صحيح fd)
{
    بنية pe_rsrc_سرلیک hdr;
    Section *rsrc_section;
    صحيح i, ret = -1, sym_شاخص;
    BYTE *ptr;
    بینښه offs;

    إذا (!read_mem(fd, 0, &hdr, حجم hdr))
        اذهب quit;

    إذا (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.شمېره_د_Sections != 1
        || strcmp((حرف*)hdr.sectionhdr.Name, ".rsrc") != 0)
        اذهب quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_جمع_کړه(rsrc_section, hdr.sectionhdr.اندازه_د_Raw_معلومات);
    offs = hdr.sectionhdr.اشاره_ګر_منزل_Raw_معلومات;
    إذا (!read_mem(fd, offs, ptr, hdr.sectionhdr.اندازه_د_Raw_معلومات))
        اذهب quit;
    offs = hdr.sectionhdr.اشاره_ګر_منزل_Relocations;
    sym_شاخص = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_عدد, ".rsrc");
    لكل (i = 0; i < hdr.sectionhdr.شمېره_د_Relocations; ++i) {
        بنية pe_rsrc_reloc rel;
        إذا (!read_mem(fd, offs, &rel, حجم rel))
            اذهب quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        إذا (rel.type != RSRC_RELTYPE)
            اذهب quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.دننه_واټن, R_XXX_RELATIVE, sym_شاخص);
        offs += حجم rel;
    }
    ret = 0;
quit:
    أرجع ret;
}

/* ------------------------------------------------------------- */

ساكن حرف *trimfront(حرف *p)
{
    طالما ((بینښه حرف)*p <= ' ' && *p && *p != '\n')
	++p;
    أرجع p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

ساكن حرف *get_token(حرف **s, حرف *f)
{
    حرف *p, *e;
    صحيح q;

    p = trimfront(*s);
    q = *p;
    إذا (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    وإلا
        q = ' ';
    لكل (e = p; (بینښه حرف)*e >= ' ' && *e != q; ++e)
        ;
    إذا (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    أرجع p;
}

ساكن صحيح pe_بارول_def(TCCState *s1, صحيح fd)
{
    صحيح state = 0, ret = -1, dllindex = 0, ord;
    حرف dllname[80], *buf, *کرښه, *p, *x, بل;

    buf = tcc_بارول_متن(fd);
    إذا (!buf)
        أرجع ret;

    لكل (کرښه = buf;; ++کرښه)  {
        p = get_token(&کرښه, &بل);
        إذا (!(*p && *p != ';'))
            اذهب skip;
        بدل (state) {
        حالة 0:
            إذا (0 != stricmp(p, "LIBRARY") || بل == '\n')
                اذهب quit;
            pstrcpy(dllname, حجم dllname, get_token(&کرښه, &بل));
            إذا (!*tcc_fileextension(dllname))
                pstrcat(dllname, حجم dllname, ".dll");
            ++state;
            اكسر;
        حالة 1:
            إذا (0 != stricmp(p, "EXPORTS"))
                اذهب quit;
            ++state;
            اكسر;
        حالة 2:
            dllindex = tcc_جمع_کړه_dllref(s1, dllname, 0)->شاخص;
            ++state;
            /* fall through */
        افتراضي:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            إذا (بل == '@') {
                x = get_token(&کرښه, &بل);
                ord = (صحيح)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            اكسر;
        }
skip:
        طالما ((بینښه حرف)بل > ' ')
            get_token(&کرښه, &بل);
        إذا (بل != '\n')
            اكسر;
    }
    ret = 0;
quit:
    tcc_free(buf);
    أرجع ret;
}

/* ------------------------------------------------------------- */

ساكن صحيح pe_بارول_dll(TCCState *s1, صحيح fd, ثابت حرف *filename)
{
    حرف *p, *q;
    DLLReference *ref = tcc_جمع_کړه_dllref(s1, filename, 0);
    إذا (ref->وموندل)
        أرجع 0;
    إذا (get_dllexports(fd, &p))
        أرجع -1;
    إذا (p) {
        لكل (q = p; *q; q += 1 + مزي_اوږدوالی(q))
            pe_putimport(s1, ref->شاخص, q, 0);
        tcc_free(p);
    }
    أرجع 0;
}

ST_FUNC صحيح pe_بارول_file(بنية TCCState *s1, صحيح fd, ثابت حرف *filename)
{
    صحيح ret = -1;
    حرف buf[10];
    إذا (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_بارول_def(s1, fd);
    وإلا إذا (pe_بارول_res(s1, fd) == 0)
        ret = 0;
    وإلا إذا (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_بارول_dll(s1, fd, filename);
    أرجع ret;
}

PUB_FUNC صحيح tcc_get_dllexports(ثابت حرف *filename, حرف **pp)
{
    صحيح ret, fd = open(filename, O_RDONLY | O_دوګونی_2);
    إذا (fd < 0)
        أرجع -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    أرجع ret;
}

/* ------------------------------------------------------------- */
#که_تعریف_شوی TCC_موخه_X86_64
ساكن بینښه pe_جمع_کړه_unwind_info(TCCState *s1)
{
    إذا (عدم == s1->uw_pdata) {
        s1->uw_pdata = پیدا_کړه_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    إذا (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, متن_section->sh_عدد, ".uw_base");
    إذا (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        ساكن ثابت بینښه حرف uw_info[] = {
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

        Section *s = متن_section;
        بینښه حرف *p;

        section_ptr_جمع_کړه(s, -s->معلومات_دننه_واټن & 3); /* align */
        s1->uw_offs = s->معلومات_دننه_واټن;
        p = section_ptr_جمع_کړه(s, حجم uw_info);
        حافظه_نقل(p, uw_info, حجم uw_info);
    }

    أرجع s1->uw_offs;
}

ST_FUNC فراغ pe_جمع_کړه_unwind_معلومات(بینښه پیل, بینښه پای_ټکی, بینښه ډېری)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    بینښه o, n, d;
    بنية /* _RUNTIME_FUNCTION */ {
      DWORD Begin_پته;
      DWORD پای_ټکی_پته;
      DWORD Unwind_معلومات;
    } *p;

    d = pe_جمع_کړه_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->معلومات_دننه_واټن;
    p = section_ptr_جمع_کړه(pd, حجم *p);

    /* record this function */
    p->Begin_پته = پیل;
    p->پای_ټکی_پته = پای_ټکی;
    p->Unwind_معلومات = d;

    /* put relocations on it */
    لكل (n = o + حجم *p; o < n; o += حجم p->Begin_پته)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#وإلاإذا defined(TCC_موخه_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
ساكن Section *pe_جمع_کړه_unwind_info(TCCState *s1)
{
    Section *s;

    إذا (عدم == s1->uw_pdata) {
        s1->uw_pdata = پیدا_کړه_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = پیدا_کړه_section(s1, ".xdata");
    s->sh_addralign = 4;
    إذا (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  متن_section->sh_عدد, ".uw_text_base");
    إذا (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_عدد, ".uw_base");
    أرجع s;
}

ST_FUNC فراغ pe_جمع_کړه_unwind_معلومات(بینښه پیل, بینښه پای_ټکی, بینښه ډېری)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    بینښه o, d, کوډ_بایټونه, func_len;
    بینښه حرف *q;
    uint32_t سرلیک;
    بنية /* _RUNTIME_FUNCTION */ {
        DWORD Begin_پته;
        DWORD Unwind_معلومات;
    } *p;

    صحيح epilog;

    xd = pe_جمع_کړه_unwind_info(s1);
    pd = s1->uw_pdata;

    func_len = (پای_ټکی - پیل) >> 2;
    کوډ_بایټونه = 0;
    epilog = کوډ_بایټونه;
    کوډ_بایټونه += 3; /* set_fp, save_fplr_x, end */
    کوډ_بایټونه = (کوډ_بایټونه + 3) & ~3;

    section_ptr_جمع_کړه(xd, -xd->معلومات_دننه_واټن & 3);
    d = xd->معلومات_دننه_واټن;
    q = section_ptr_جمع_کړه(xd, 4 + کوډ_بایټونه);

    /* Full ARM64 xdata header: E=1 with one epilog and no exception handler. */
    سرلیک = (func_len & 0x3ffff)
        | 1 << 21
        | (epilog & 0x1F) << 22
        | (کوډ_بایټونه >> 2) << 27
        ;
    write32le(q, سرلیک);
    q += 4;
    *q++ = 0xE1; /* set_fp */
    *q++ = 0x9B; /* save_fplr_x: stp x29,lr,[sp,#-224]! */
    *q++ = 0xE4; /*پای_ټکی*/
    طالما ((بینښه)(q - (xd->معلومات + d + 4)) < کوډ_بایټونه)
        *q++ = 0xE3; /* nop padding */

    o = pd->معلومات_دننه_واټن;
    p = section_ptr_جمع_کړه(pd, حجم *p);
    p->Begin_پته = پیل;
    p->Unwind_معلومات = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#د_که_پای
/* ------------------------------------------------------------- */
#إذا defined(TCC_موخه_X86_64) || defined(TCC_موخه_ARM64)
#تعریف_کړه PE_STDSYM(n,s) n
#وإلا
#تعریف_کړه PE_STDSYM(n,s) "_" n s
#د_که_پای

ساكن فراغ pe_جمع_کړه_runtime(TCCState *s1, بنية pe_info *pe)
{
    ثابت حرف *پیل_نښه;
    صحيح pe_type;

    إذا (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        پیل_نښه = PE_STDSYM("__dllstart","@12");
    } وإلا {
        ثابت حرف *پرلپسې_نښه;
        إذا (پیدا_کړه_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            پیل_نښه = "__winstart";
            پرلپسې_نښه = "__runwinmain";
            pe_type = PE_GUI;
        } وإلا إذا (پیدا_کړه_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            پیل_نښه = "__wwinstart";
            پرلپسې_نښه = "__runwwinmain";
            pe_type = PE_GUI;
        } وإلا إذا (پیدا_کړه_elf_sym(symtab_section, "wmain")) {
            پیل_نښه = "__wstart";
            پرلپسې_نښه = "__runwmain";
            pe_type = PE_EXE;
        } وإلا {
            پیل_نښه =  "__start";
            پرلپسې_نښه = "__runmain";
            pe_type = PE_EXE;
            إذا (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        إذا (TCC_OUTPUT_حافظه == s1->output_type && !s1->nostdlib)
            پیل_نښه = پرلپسې_نښه;
    }
    إذا (s1->elf_entryname) {
        pe->پیل_نښه = پیل_نښه = s1->elf_entryname;
    } وإلا {
        pe->پیل_نښه = پیل_نښه + 1;
        إذا (!s1->leading_underscore || strchr(پیل_نښه, '@'))
            ++پیل_نښه;
    }

#که_تعریف_شوی CONFIG_TCC_BACKTRACE
    إذا (s1->do_backtrace) {
#که_تعریف_شوی CONFIG_TCC_BCHECK
        إذا (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    إذا (s1->output_type == TCC_OUTPUT_حافظه)
                tcc_جمع_کړه_support(s1, "bcheck_run.o");
	    وإلا
                tcc_جمع_کړه_support(s1, "bcheck.o");
	}
#د_که_پای
        إذا (s1->output_type == TCC_OUTPUT_EXE)
            tcc_جمع_کړه_support(s1, "bt-exe.o");
        إذا (s1->output_type == TCC_OUTPUT_DLL)
            tcc_جمع_کړه_support(s1, "bt-dll.o");
        إذا (s1->output_type != TCC_OUTPUT_DLL)
            tcc_جمع_کړه_support(s1, "bt-log.o");
        tcc_جمع_کړه_btstub(s1);
    }
#د_که_پای

    /* grab the startup code from libtcc1.a */
#که_تعریف_شوی TCC_IS_NATIVE
    إذا (TCC_OUTPUT_حافظه != s1->output_type || s1->پرلپسې_main)
#د_که_پای
    سېټ_global_sym(s1, پیل_نښه, عدم, 0);

    إذا (0 == s1->nostdlib) {
        ساكن ثابت حرف * ثابت libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", عدم
        };
        ثابت حرف * ثابت *pp, *p;
        إذا (TCC_LIBTCC1[0])
            tcc_جمع_کړه_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        لكل (pp = libs; 0 != (p = *pp); ++pp) {
            إذا (*p)
                tcc_جمع_کړه_library(s1, p);
            وإلا إذا (PE_DLL != pe_type && PE_GUI != pe_type)
                اكسر;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    إذا (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    إذا (TCC_OUTPUT_حافظه == s1->output_type)
        pe_type = PE_پرلپسې;
    pe->type = pe_type;
}

ST_FUNC صحيح pe_setsubsy(TCCState *s1, ثابت حرف *arg)
{
    ساكن ثابت بنية subsy { ثابت حرف* p; صحيح v; } x[] = {
#إذا defined(TCC_موخه_I386) || defined(TCC_موخه_X86_64) || defined(TCC_موخه_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#وإلاإذا defined(TCC_موخه_ARM)
        { "wince", 9 },
#د_که_پای
        { 0, -1 }};
    ثابت بنية subsy *y;
    لكل (y = x;; ++y) {
        إذا (!y->p)
            أرجع -1;
        إذا (0 == strcmp(y->p, arg)) {
            s1->pe_subsystem = y->v;
            أرجع 0;
        }
    }
}

ساكن فراغ pe_سېټ_options(TCCState * s1, بنية pe_info *pe)
{
    إذا (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_بنسټ_DLL;
    } وإلا {
        pe->imagebase = IMAGE_بنسټ_EXE;
    }

#إذا defined(TCC_موخه_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#وإلا
    إذا (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    وإلا
        pe->subsystem = 3;
#د_که_پای
    /* Allow override via -Wl,-subsystem=... option */
    إذا (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    إذا (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } وإلا {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    إذا (s1->section_align != 0)
        pe->section_align = s1->section_align;
    إذا (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    إذا ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    إذا (s1->has_متن_addr)
        pe->imagebase = s1->متن_addr;
}

ST_FUNC صحيح pe_output_file(TCCState *s1, ثابت حرف *filename)
{
    بنية pe_info pe;

    memset(&pe, 0, حجم pe);
    pe.filename = filename;
    pe.s1 = s1;
    s1->filetype = 0;

#که_تعریف_شوی CONFIG_TCC_BCHECK
    tcc_جمع_کړه_bcheck(s1);
#د_که_پای
    tcc_جمع_کړه_pragma_libs(s1);
    pe_جمع_کړه_runtime(s1, &pe);
    resolve_common_syms(s1);
    pe_سېټ_options(s1, &pe);
    pe_check_symbols(&pe);
    إذا (s1->nb_errors)
        اذهب بشپړ;
    إذا (filename) {
        pe_ټاکل_پتې(&pe);
        relocate_syms(s1, s1->symtab, 0);
        إذا (s1->nb_errors)
            اذهب بشپړ;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.پیل_addr = (DWORD)
            (get_sym_addr(s1, pe.پیل_نښه, 1, 1) - pe.imagebase);
        إذا (s1->nb_errors)
            اذهب بشپړ;
        pe_write(&pe);
    } وإلا {
        /* -run */
#که_تعریف_شوی TCC_IS_NATIVE
        pe.thunk = معلومات_section;
        pe_build_imports(&pe);
        s1->پرلپسې_main = pe.پیل_نښه;
#إذا defined(TCC_موخه_X86_64) || defined(TCC_موخه_ARM64)
        s1->uw_pdata = پیدا_کړه_section(s1, ".pdata");
#د_که_پای
#د_که_پای
    }
بشپړ:
    dynarray_reset(&pe.sec_info, &pe.sec_شمېر);
    pe_free_imports(&pe);
#إذا PE_PRINT_SECTIONS
    إذا (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#د_که_پای
    أرجع s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
