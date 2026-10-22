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

#تعریف_کرو PE_ملاؤ_انکڑے 1
#تعریف_کرو PE_PRINT_SECTIONS 0

#جے_بنا_تعریف _WIN32
#تعریف_کرو stricmp strcasecmp
#تعریف_کرو strnicmp strncasecmp
#ضمن <sys/stat.h> /* chmod() */
#جے_انت

#إذا defined TCC_نشانہ_X86_64
# define REL_TYPE_سدھا R_X86_64_64
# define R_XXX_THUNKFIX R_X86_64_PC32
# define R_XXX_RELATIVE R_X86_64_RELATIVE
# define R_XXX_FUNCCALL R_X86_64_PLT32
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0x8664
# define CHARACTERISTICS_EXE 0x022F
# define CHARACTERISTICS_DLL 0x222E
# define IMAGE_ادھار_EXE 0x00400000
# define IMAGE_ادھار_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#وإلاإذا defined TCC_نشانہ_ARM
# define REL_TYPE_سدھا R_ARM_ABS32
# define R_XXX_THUNKFIX R_ARM_ABS32
# define R_XXX_RELATIVE R_ARM_RELATIVE
# define R_XXX_FUNCCALL R_ARM_PC24
# define R_XXX_FUNCCALL2 R_ARM_ABS32
# define RSRC_RELTYPE 7 /* ??? (not tested) */
# define IMAGE_FILE_MACHINE 0x01C0
# define CHARACTERISTICS_EXE 0x010F
# define CHARACTERISTICS_DLL 0x230F
# define IMAGE_ادھار_EXE 0x00100000
# define IMAGE_ادھار_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#وإلاإذا defined TCC_نشانہ_ARM64
# define REL_TYPE_سدھا R_AARCH64_ABS64
# define R_XXX_THUNKFIX R_AARCH64_ABS64
# define R_XXX_RELATIVE R_AARCH64_RELATIVE
# define R_XXX_FUNCCALL R_AARCH64_CALL26
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0xAA64
# define CHARACTERISTICS_EXE 0x0022
# define CHARACTERISTICS_DLL 0x2022
# define IMAGE_ادھار_EXE 0x140000000ULL
# define IMAGE_ادھار_DLL 0x180000000ULL
# define OS_VER 0x0602
# define DLLCHARACTERISTICS 0x8160

#وإلاإذا defined TCC_نشانہ_I386
# define REL_TYPE_سدھا R_386_32
# define R_XXX_THUNKFIX R_386_32
# define R_XXX_RELATIVE R_386_RELATIVE
# define R_XXX_FUNCCALL R_386_PC32
# define RSRC_RELTYPE 7 /* DIR32NB */
# define IMAGE_FILE_MACHINE 0x014C
# define CHARACTERISTICS_EXE 0x030F
# define CHARACTERISTICS_DLL 0x230E
# define IMAGE_ادھار_EXE 0x00400000
# define IMAGE_ادھار_DLL 0x10000000
# define OS_VER 0x0400
# define DLLCHARACTERISTICS 0
#جے_انت

#إذا PTR_ناپ == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#وإلا
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#جے_انت

#جے_بنا_تعریف IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

تعريفنوع بنانشانی حرف BYTE;
تعريفنوع بنانشانی چھوٹا لفظ_3;
تعريفنوع بنانشانی صحيح DWORD;
تعريفنوع بنانشانی لما لما ULONGLONG;
#ہدایت pack(ڈالو, 1)

تعريفنوع بنية IMAGE_DOS_سرخی {  /* DOS .EXE header */
    لفظ_3 e_magic;         /* Magic number */
    لفظ_3 e_cblp;          /* Bytes on last page of file */
    لفظ_3 e_cp;            /* Pages in file */
    لفظ_3 e_crlc;          /* Relocations */
    لفظ_3 e_cparhdr;       /* Size of header in paragraphs */
    لفظ_3 e_minalloc;      /* Minimum extra paragraphs needed */
    لفظ_3 e_maxalloc;      /* Maximum extra paragraphs needed */
    لفظ_3 e_ss;            /* Initial (relative) SS value */
    لفظ_3 e_sp;            /* Initial SP value */
    لفظ_3 e_csum;          /* Checksum */
    لفظ_3 e_ip;            /* Initial IP value */
    لفظ_3 e_cs;            /* Initial (relative) CS value */
    لفظ_3 e_lfarlc;        /* File address of relocation table */
    لفظ_3 e_ovno;          /* Overlay number */
    لفظ_3 e_res[4];        /* Reserved words */
    لفظ_3 e_oemid;         /* OEM identifier (for e_oeminfo) */
    لفظ_3 e_oeminfo;       /* OEM information; e_oemid specific */
    لفظ_3 e_res2[10];      /* Reserved words */
    DWORD e_lfanew;        /* File address of new exe header */
} IMAGE_DOS_سرخی_2, *PIMAGE_DOS_سرخی;

#تعریف_کرو IMAGE_NT_SIGNATURE  0x00004550  /* PE00 */

تعريفنوع بنية IMAGE_FILE_سرخی {
    لفظ_3    Machine;
    لفظ_3    نمبر_دا_Sections;
    DWORD   ویلا_Date_Stamp;
    DWORD   اشارہ_گر_منزل_علامت_جدول;
    DWORD   نمبر_دا_Symbols;
    لفظ_3    ناپ_دا_Optional_سرخی;
    لفظ_3    Characteristics;
} IMAGE_FILE_سرخی_2, *PIMAGE_FILE_سرخی;


#تعریف_کرو IMAGE_SIZEOF_FILE_سرخی 20

تعريفنوع بنية IMAGE_انکڑے_DIRECTORY {
    DWORD   Virtual_پتہ;
    DWORD   ناپ_3;
} IMAGE_انکڑے_DIRECTORY_2, *PIMAGE_انکڑے_DIRECTORY;


تعريفنوع بنية IMAGE_OPTIONAL_سرخی {
    /* Standard fields. */
    لفظ_3    Magic;
    BYTE    Major_Linker_نسخہ;
    BYTE    Minor_Linker_نسخہ;
    DWORD   ناپ_دا_کوڈ;
    DWORD   ناپ_دا_Initialized_انکڑے;
    DWORD   ناپ_دا_Uninitialized_انکڑے;
    DWORD   پتہ_دا_اندراج_نقطہ;
    DWORD   ادھار_دا_کوڈ;
#إذا PTR_ناپ == 4
    DWORD   ادھار_دا_انکڑے;
#جے_انت
    /* NT additional fields. */
    ADDR3264 Image_ادھار;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    لفظ_3    Major_Operating_System_نسخہ;
    لفظ_3    Minor_Operating_System_نسخہ;
    لفظ_3    Major_Image_نسخہ;
    لفظ_3    Minor_Image_نسخہ;
    لفظ_3    Major_Subsystem_نسخہ;
    لفظ_3    Minor_Subsystem_نسخہ;
    DWORD   Win32_نسخہ_قدر;
    DWORD   ناپ_دا_Image;
    DWORD   ناپ_دا_سرخیاں;
    DWORD   Check_جوڑ;
    لفظ_3    Subsystem;
    لفظ_3    DllCharacteristics;
    ADDR3264 ناپ_دا_ڈھیر_Reserve;
    ADDR3264 ناپ_دا_ڈھیر_Commit;
    ADDR3264 ناپ_دا_ڈھیر_Reserve_2;
    ADDR3264 ناپ_دا_ڈھیر_Commit_2;
    DWORD   LoaderFlags;
    DWORD   نمبر_دا_Rva_And_Sizes;
    IMAGE_انکڑے_DIRECTORY_2 انکڑے_Directory[16];
} IMAGE_OPTIONAL_HEADER32, IMAGE_OPTIONAL_HEADER64, IMAGE_OPTIONAL_سرخی_2;

#تعریف_کرو IMAGE_DIRECTORY_اندراج_EXPORT          0   /* Export Directory */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_IMPORT          1   /* Import Directory */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_RESOURCE        2   /* Resource Directory */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_EXCEPTION       3   /* Exception Directory */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_SECURITY        4   /* Security Directory */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_BASERELOC       5   /* Base Relocation Table */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_DEBUG           6   /* Debug Directory */
/*      IMAGE_DIRECTORY_ENTRY_COPYRIGHT       7      (X86 usage) */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_ARCHITECTURE    7   /* Architecture Specific Data */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_GLOBALPTR       8   /* RVA of GP */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_TLS             9   /* TLS Directory */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_لدو_CONFIG    10   /* Load Configuration Directory */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_BOUND_IMPORT   11   /* Bound Import Directory in headers */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_IAT            12   /* Import Address Table */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_DELAY_IMPORT   13   /* Delay Load Import Descriptors */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_COM_DESCRIPTOR 14   /* COM Runtime descriptor */

/* Section header format. */
#تعریف_کرو IMAGE_SIZEOF_SHORT_NAME         8

تعريفنوع بنية IMAGE_SECTION_سرخی {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    اتحاد {
            DWORD   Physical_پتہ;
            DWORD   Virtual_ناپ;
    } Misc;
    DWORD   Virtual_پتہ;
    DWORD   ناپ_دا_Raw_انکڑے;
    DWORD   اشارہ_گر_منزل_Raw_انکڑے;
    DWORD   اشارہ_گر_منزل_Relocations;
    DWORD   اشارہ_گر_منزل_Linenumbers;
    لفظ_3    نمبر_دا_Relocations;
    لفظ_3    نمبر_دا_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_سرخی_2, *PIMAGE_SECTION_سرخی;

#تعریف_کرو IMAGE_SIZEOF_SECTION_سرخی     40

تعريفنوع بنية _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD ویلا_Date_Stamp;
    لفظ_3 Major_نسخہ;
    لفظ_3 Minor_نسخہ;
    DWORD Name;
    DWORD ادھار_2;
    DWORD نمبر_دا_Functions;
    DWORD نمبر_دا_ناں;
    DWORD پتہ_دا_Functions;
    DWORD پتہ_دا_ناں;
    DWORD پتہ_دا_Name_Ordinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

تعريفنوع بنية _IMAGE_TLS_DIRECTORY {
    ADDR3264 شروع_پتہ_دا_Raw_انکڑے;
    ADDR3264 سرا_پتہ_دا_Raw_انکڑے;
    ADDR3264 پتہ_دا_اشاریہ;
    ADDR3264 پتہ_دا_Call_Backs;
    DWORD ناپ_دا_Zero_Fill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

تعريفنوع بنية _IMAGE_IMPORT_DESCRIPTOR {
    اتحاد {
        DWORD Characteristics;
        DWORD Original_پہلا_Thunk;
    };
    DWORD ویلا_Date_Stamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD پہلا_Thunk;
} IMAGE_IMPORT_DESCRIPTOR;

تعريفنوع بنية IMAGE_ادھار_RELOCATION {
    DWORD   Virtual_پتہ;
    DWORD   ناپ_دا_بلاک;
//  WORD    TypeOffset[1];
} IMAGE_ادھار_RELOCATION_2;

#تعریف_کرو IMAGE_SIZEOF_ادھار_RELOCATION     8

#تعریف_کرو IMAGE_REL_BASED_ABSOLUTE         0
#تعریف_کرو IMAGE_REL_BASED_بلند             1
#تعریف_کرو IMAGE_REL_BASED_کم              2
#تعریف_کرو IMAGE_REL_BASED_HIGHLOW          3
#تعریف_کرو IMAGE_REL_BASED_HIGHADJ          4
#تعریف_کرو IMAGE_REL_BASED_MIPS_JMPADDR     5
#تعریف_کرو IMAGE_REL_BASED_SECTION          6
#تعریف_کرو IMAGE_REL_BASED_REL32            7
#تعریف_کرو IMAGE_REL_BASED_DIR64           10

#تعریف_کرو IMAGE_SCN_CNT_کوڈ                  0x00000020
#تعریف_کرو IMAGE_SCN_CNT_INITIALIZED_انکڑے      0x00000040
#تعریف_کرو IMAGE_SCN_CNT_UNINITIALIZED_انکڑے    0x00000080
#تعریف_کرو IMAGE_SCN_MEM_DISCARDABLE           0x02000000
#تعریف_کرو IMAGE_SCN_MEM_SHARED                0x10000000
#تعریف_کرو IMAGE_SCN_MEM_EXECUTE               0x20000000
#تعریف_کرو IMAGE_SCN_MEM_READ                  0x40000000
#تعریف_کرو IMAGE_SCN_MEM_WRITE                 0x80000000

#تعریف_کرو IMAGE_DLLCHARACTERISTICS_بلند_ENTROPY_VA 0x0020
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_DYNAMIC_ادھار 0x0040
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#تعریف_کرو IMAGE_FILE_RELOCS_STRIPPED 0x0001

#ہدایت pack(نکالو)

/* ----------------------------------------------------------- */
#جے_انت /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#جے_بنا_تعریف IMAGE_DLLCHARACTERISTICS_DYNAMIC_ادھار
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #تعریف_کرو IMAGE_DLLCHARACTERISTICS_DYNAMIC_ادھار 0x0040
#جے_انت

#ہدایت pack(ڈالو, 1)
بنية pe_سرخی
{
    IMAGE_DOS_سرخی_2 doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_سرخی_2 filehdr;
#إذا PTR_ناپ == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#وإلا
#جے_تعریف_شدہ _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#وإلا
    IMAGE_OPTIONAL_سرخی_2 opthdr;
#جے_انت
#جے_انت
};

بنية pe_reloc_سرخی {
    DWORD وتھ;
    DWORD ناپ;
};

بنية pe_rsrc_سرخی {
    بنية IMAGE_FILE_سرخی filehdr;
    بنية IMAGE_SECTION_سرخی sectionhdr;
};

بنية pe_rsrc_reloc {
    DWORD وتھ;
    DWORD ناپ;
    لفظ_3 type;
};
#ہدایت pack(نکالو)

/* ------------------------------------------------------------- */
/* internal temporary structures */

تعداد {
    sec_متن = 0,
    sec_rdata ,
    sec_انکڑے ,
    sec_bss ,
    sec_idata ,
    sec_pdata ,
    sec_tdata ,
    sec_tbss ,
    sec_other ,
    sec_rsrc ,
    sec_debug ,
    sec_reloc ,
    sec_آخری
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
#جے_انت

بنية section_info {
    صحيح cls;
    حرف name[32];
    ADDR3264 sh_addr;
    DWORD sh_ناپ;
    DWORD pe_flags;
    Section *sec;
    DWORD انکڑے_ناپ;
    IMAGE_SECTION_سرخی_2 ish;
};

بنية import_علامت {
    صحيح sym_اشاریہ;
    صحيح iat_اشاریہ;
    صحيح thk_وتھ;
};

بنية pe_import_info {
    صحيح dll_اشاریہ;
    صحيح sym_گنتی;
    بنية import_علامت **symbols;
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
    ثابت حرف *شروع_علامت;
    DWORD شروع_addr;
    DWORD imp_offs;
    DWORD imp_ناپ;
    DWORD iat_offs;
    DWORD iat_ناپ;
    DWORD exp_offs;
    DWORD exp_ناپ;
    DWORD tls_dir;
    DWORD tls_انکڑے;
    DWORD tls_ناپ;
    صحيح subsystem;
    DWORD section_align;
    DWORD file_align;
    بنية section_info **sec_info;
    صحيح sec_گنتی;
    بنية pe_import_info **imp_info;
    صحيح imp_گنتی;
    /* output */
    FILE *op;
    DWORD جوڑ;
    بنانشانی pos;
};

#تعریف_کرو PE_NUL 0
#تعریف_کرو PE_DLL 1
#تعریف_کرو PE_GUI 2
#تعریف_کرو PE_EXE 3
#تعریف_کرو PE_لگاتار 4

/* --------------------------------------------*/

ساكن ثابت حرف *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    ثابت حرف *name = (حرف*)symtab_section->link->انکڑے + sym->st_name;
    إذا (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        أرجع name + 1;
    أرجع name;
}


ساكن صحيح dynarray_assoc(فراغ **pp, صحيح n, صحيح کلید)
{
    صحيح i;
    لكل (i = 0; i < n; ++i, ++pp)
    إذا (کلید == **(صحيح **) pp)
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
    صحيح i = s->انکڑے_وتھ & (a-1);
    إذا (i)
        section_ptr_جوڑو(s, a - i);
}

ساكن فراغ pe_سیٹ_datadir(بنية pe_سرخی *hdr, صحيح dir, DWORD addr, DWORD ناپ)
{
    hdr->opthdr.انکڑے_Directory[dir].Virtual_پتہ = addr;
    hdr->opthdr.انکڑے_Directory[dir].ناپ_3 = ناپ;
}

ساكن صحيح pe_fwrite(بنية pe_info *pe, ثابت فراغ *انکڑے, صحيح len)
{
    ثابت لفظ_3 *p = انکڑے;
    DWORD جوڑ;
    صحيح ret, i;
    pe->pos += (ret = fwrite(انکڑے, 1, len, pe->op));
    جوڑ = pe->جوڑ;
    لكل (i = len; i > 0; i -= 2) {
        جوڑ += (i >= 2) ? *p++ : *(BYTE*)p;
        جوڑ = (جوڑ + (جوڑ >> 16)) & 0xFFFF;
    }
    pe->جوڑ = جوڑ;
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

#ہدایت pack(ڈالو, 1)
بنية syment
{
    اتحاد {
        حرف        n_name[8];     /* old COFF version */
        بنية {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_وتھ_2;      /* offset into string table */
        };
    };
    int32_t         n_قدر;        /* value of symbol */
    چھوٹا           n_scnum;        /* section number */
    بنانشانی چھوٹا  n_type;         /* type and derived type */
    حرف            n_sclass;       /* storage class */
    حرف            n_numaux;       /* number of aux. entries */
};
#ہدایت pack(نکالو)

#تعریف_کرو SHF_نجی 0x80000000

ساكن فراغ pe_جوڑو_coffsym(بنية pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    بنية syment *se;
    صحيح n;

    إذا (عدم == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_نجی);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_نجی);
        section_ptr_جوڑو(pe->coffstr, 4); /* coff string table size */
        أرجع;
    }

#إذا 0
    se = section_ptr_جوڑو(pe->coffsym, حجم *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_جوڑو(pe->coffsym, حجم *se);
    strcpy((حرف*)se, "no-file");
#جے_انت

#إذا 1
    esym = (ElfSym*)s1->symtab->انکڑے;
    لكل (n = s1->symtab->انکڑے_وتھ / حجم *esym; ++esym, --n;) {
        صحيح sym_bind = ELFW(ST_BIND)(esym->st_info);
        إذا (sym_bind == STB_GLOBAL) {
            حرف *name = esym->st_name + (حرف*)s1->symtab->link->انکڑے;
            صحيح nl = لڑی_لمبائی(name);
            addr_t قدر = esym->st_قدر;
            صحيح shnum = esym->st_shndx;
            إذا (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                قدر = قدر - s->sh_addr;
            }
            se = section_ptr_جوڑو(pe->coffsym, حجم *se);
            se->n_قدر = قدر;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            إذا (nl <= 8)
                حافظہ_نقل(se->n_name, name, nl);
            وإلا
                se->n_وتھ_2 = put_elf_str(pe->coffstr, name);
        }
    }
#جے_انت
    write32le(pe->coffstr->انکڑے, pe->coffstr->انکڑے_وتھ); /* coff string table size */
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
        لکھو("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
ساكن صحيح pe_write(بنية pe_info *pe)
{
    ساكن ثابت بنية pe_سرخی pe_template = {
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
    0x00E0 + (PTR_ناپ-4)*4, /*WORD    SizeOfOptionalHeader; */
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
#إذا PTR_ناپ == 4
    0x00000000, /*DWORD   BaseOfData; */
#جے_انت
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

    بنية pe_سرخی pe_سرخی = pe_template;

    صحيح i;
    DWORD file_وتھ;
    بنية section_info *si;
    IMAGE_SECTION_سرخی_2 *psh;
    TCCState *s1 = pe->s1;

    إذا (s1->do_debug)
        pe_جوڑو_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    إذا (عدم == pe->op)
        أرجع tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        حجم (بنية pe_سرخی)
        + pe->sec_گنتی * حجم (IMAGE_SECTION_سرخی_2)
        );

    file_وتھ = pe->sizeofheaders;

    إذا (2 == s1->verbose)
        لکھو("-------------------------------"
               "\n  virt   file   size  section" "\n");
    لكل (i = 0; i < pe->sec_گنتی; ++i) {
        DWORD addr, ناپ;
        ثابت حرف *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        ناپ = si->sh_ناپ;
        psh = &si->ish;

        إذا (2 == s1->verbose)
            لکھو("%6x %6x %6x  %s\n",
                (بنانشانی)addr, (بنانشانی)file_وتھ, (بنانشانی)ناپ, sh_name);

        بدل (si->cls) {
            حالة sec_متن:
                إذا (!pe_سرخی.opthdr.ادھار_دا_کوڈ)
                    pe_سرخی.opthdr.ادھار_دا_کوڈ = addr;
                اكسر;

            حالة sec_انکڑے:
#إذا PTR_ناپ == 4
                إذا (!pe_سرخی.opthdr.ادھار_دا_انکڑے)
                    pe_سرخی.opthdr.ادھار_دا_انکڑے = addr;
#جے_انت
                اكسر;

            حالة sec_bss:
                اكسر;

            حالة sec_reloc:
                pe_سیٹ_datadir(&pe_سرخی, IMAGE_DIRECTORY_اندراج_BASERELOC, addr, ناپ);
                اكسر;

            حالة sec_rsrc:
                pe_سیٹ_datadir(&pe_سرخی, IMAGE_DIRECTORY_اندراج_RESOURCE, addr, ناپ);
                اكسر;

            حالة sec_pdata:
                pe_سیٹ_datadir(&pe_سرخی, IMAGE_DIRECTORY_اندراج_EXCEPTION, addr, ناپ);
                اكسر;
        }

        إذا (pe->imp_ناپ) {
            pe_سیٹ_datadir(&pe_سرخی, IMAGE_DIRECTORY_اندراج_IMPORT,
                pe->imp_offs, pe->imp_ناپ);
            pe_سیٹ_datadir(&pe_سرخی, IMAGE_DIRECTORY_اندراج_IAT,
                pe->iat_offs, pe->iat_ناپ);
        }
        إذا (pe->exp_ناپ) {
            pe_سیٹ_datadir(&pe_سرخی, IMAGE_DIRECTORY_اندراج_EXPORT,
                pe->exp_offs, pe->exp_ناپ);
        }
        إذا (pe->tls_ناپ) {
            pe_سیٹ_datadir(&pe_سرخی, IMAGE_DIRECTORY_اندراج_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_ناپ);
        }

        حافظہ_نقل(psh->Name, sh_name, umin(لڑی_لمبائی(sh_name), حجم psh->Name));
        إذا (pe->coffstr && لڑی_لمبائی(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((حرف*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->Virtual_پتہ = addr;
        psh->Misc.Virtual_ناپ = ناپ;
        pe_سرخی.opthdr.ناپ_دا_Image =
            umax(pe_virtual_align(pe, ناپ + addr), pe_سرخی.opthdr.ناپ_دا_Image);

        إذا (si->انکڑے_ناپ) {
            psh->اشارہ_گر_منزل_Raw_انکڑے = file_وتھ;
            file_وتھ = pe_file_align(pe, file_وتھ + si->انکڑے_ناپ);
            psh->ناپ_دا_Raw_انکڑے = file_وتھ - psh->اشارہ_گر_منزل_Raw_انکڑے;
            إذا (si->cls == sec_متن)
                pe_سرخی.opthdr.ناپ_دا_کوڈ += psh->ناپ_دا_Raw_انکڑے;
            وإلا
                pe_سرخی.opthdr.ناپ_دا_Initialized_انکڑے += psh->ناپ_دا_Raw_انکڑے;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_سرخی.filehdr.نمبر_دا_Sections = pe->sec_گنتی;
    pe_سرخی.opthdr.پتہ_دا_اندراج_نقطہ = pe->شروع_addr;
    pe_سرخی.opthdr.ناپ_دا_سرخیاں = pe->sizeofheaders;
    pe_سرخی.opthdr.Image_ادھار = pe->imagebase;
    pe_سرخی.opthdr.Subsystem = pe->subsystem;
    pe_سرخی.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    إذا (s1->pe_ڈھیر_ناپ)
        pe_سرخی.opthdr.ناپ_دا_ڈھیر_Reserve = s1->pe_ڈھیر_ناپ;
    إذا (PE_DLL == pe->type)
        pe_سرخی.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_سرخی.filehdr.Characteristics |= s1->pe_characteristics;
    إذا (pe->reloc)
        pe_سرخی.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    إذا (pe->coffsym) {
        pe_جوڑو_coffsym(pe);
        pe_سرخی.filehdr.اشارہ_گر_منزل_علامت_جدول = file_وتھ;
        pe_سرخی.filehdr.نمبر_دا_Symbols
            = pe->coffsym->انکڑے_وتھ / حجم (بنية syment);
    }

    pe_fwrite(pe, &pe_سرخی, حجم pe_سرخی);
    لكل (i = 0; i < pe->sec_گنتی; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, حجم(IMAGE_SECTION_سرخی_2));

    file_وتھ = pe->sizeofheaders;
    لكل (i = 0; i < pe->sec_گنتی; ++i) {
        Section *s;
        si = pe->sec_info[i];
        إذا (!si->انکڑے_ناپ)
            استمر;
        لكل (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_وتھ);
            pe_fwrite(pe, s->انکڑے, s->انکڑے_وتھ);
            إذا (s->prev)
                file_وتھ += s->prev->sh_addr - s->sh_addr;
        }
        file_وتھ = si->ish.اشارہ_گر_منزل_Raw_انکڑے + si->ish.ناپ_دا_Raw_انکڑے;
        pe_fpad(pe, file_وتھ);
    }

    إذا (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->انکڑے, pe->coffsym->انکڑے_وتھ);
        pe_fwrite(pe, pe->coffstr->انکڑے, pe->coffstr->انکڑے_وتھ);
        file_وتھ = pe->pos;
    }

    pe->جوڑ += file_وتھ;
    fseek(pe->op, offsetof(بنية pe_سرخی, opthdr.Check_جوڑ), SEEK_SET);
    pe_fwrite(pe, &pe->جوڑ, حجم (DWORD));

    fclose (pe->op);
#جے_بنا_تعریف _WIN32
    chmod(pe->filename, 0777);
#جے_انت

    إذا (2 == s1->verbose)
        لکھو("-------------------------------\n");
    إذا (s1->verbose)
        لکھو("<- %s (%u bytes)\n", pe->filename, (بنانشانی)file_وتھ);

    إذا (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    أرجع 0;
}

/*----------------------------------------------------------------------------*/

ساكن بنية import_علامت *pe_جوڑو_import(بنية pe_info *pe, صحيح sym_اشاریہ)
{
    صحيح i;
    صحيح dll_اشاریہ;
    بنية pe_import_info *p;
    بنية import_علامت *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->انکڑے + sym_اشاریہ;
    dll_اشاریہ = isym->st_ناپ;

    i = dynarray_assoc ((فراغ**)pe->imp_info, pe->imp_گنتی, dll_اشاریہ);
    إذا (-1 != i) {
        p = pe->imp_info[i];
        اذهب لبھیا_dll;
    }
    p = tcc_mallocz(حجم *p);
    p->dll_اشاریہ = dll_اشاریہ;
    dynarray_جوڑو(&pe->imp_info, &pe->imp_گنتی, p);

لبھیا_dll:
    i = dynarray_assoc ((فراغ**)p->symbols, p->sym_گنتی, sym_اشاریہ);
    إذا (-1 != i)
        أرجع p->symbols[i];

    s = tcc_mallocz(حجم *s);
    dynarray_جوڑو(&p->symbols, &p->sym_گنتی, s);
    s->sym_اشاریہ = sym_اشاریہ;
    أرجع s;
}

ساكن فراغ pe_free_imports(بنية pe_info *pe)
{
    صحيح i;
    لكل (i = 0; i < pe->imp_گنتی; ++i) {
        بنية pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_گنتی);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_گنتی);
}

/*----------------------------------------------------------------------------*/
ساكن فراغ pe_build_imports(بنية pe_info *pe)
{
    صحيح thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_ادھار = pe->thunk->sh_addr - pe->imagebase;
    صحيح ndlls = pe->imp_گنتی;
    TCCState *s1 = pe->s1;

    لكل (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_گنتی;

    إذا (0 == sym_cnt)
        أرجع;

    pe_align_section(pe->thunk, 16);
    pe->imp_ناپ = (ndlls + 1) * حجم(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_ناپ = (sym_cnt + ndlls) * حجم(ADDR3264);
    dll_ptr = pe->thunk->انکڑے_وتھ;
    thk_ptr = dll_ptr + pe->imp_ناپ;
    ent_ptr = thk_ptr + pe->iat_ناپ;
    pe->imp_offs = dll_ptr + rva_ادھار;
    pe->iat_offs = thk_ptr + rva_ادھار;
    section_ptr_جوڑو(pe->thunk, pe->imp_ناپ + 2*pe->iat_ناپ);

    لكل (i = 0; i < pe->imp_گنتی; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        صحيح k, n, dllindex;
        ADDR3264 v;
        بنية pe_import_info *p = pe->imp_info[i];
        ثابت حرف *name;
        DLLReference *dllref;

        dllindex = p->dll_اشاریہ;
        إذا (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        وإلا
            name = "", dllref = عدم;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->انکڑے + dll_ptr);
        hdr->پہلا_Thunk = thk_ptr + rva_ادھار;
        hdr->Original_پہلا_Thunk = ent_ptr + rva_ادھار;
        hdr->Name = v + rva_ادھار;

        لكل (k = 0, n = p->sym_گنتی; k <= n; ++k) {
            إذا (k < n) {
                صحيح iat_اشاریہ = p->symbols[k]->iat_اشاریہ;
                صحيح sym_اشاریہ = p->symbols[k]->sym_اشاریہ;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->انکڑے + sym_اشاریہ;
                ثابت حرف *name = (حرف*)s1->dynsymtab_section->link->انکڑے + imp_sym->st_name;
                صحيح ordinal;

                /* patch symbol (and possibly its underscored alias) */
                افعل {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->انکڑے + iat_اشاریہ;
                    iat_اشاریہ = esym->st_قدر;
                    esym->st_قدر = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_عدد;
                } طالما (iat_اشاریہ);

                إذا (dllref)
                    v = 0, ordinal = imp_sym->st_قدر; /* ordinal from pe_load_def */
                وإلا
                    ordinal = 0, v = imp_sym->st_قدر; /* address from tcc_add_symbol() */

#جے_تعریف_شدہ TCC_IS_NATIVE
                إذا (pe->type == PE_لگاتار) {
                    إذا (dllref) {
                        إذا ( !dllref->handle )
                            dllref->handle = لدو_Library_A(dllref->name);
                        v = (ADDR3264)Get_Proc_پتہ(dllref->handle, ordinal?(حرف*)0+ordinal:name);
                    }
                    إذا (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } وإلا
#جے_انت
                إذا (ordinal) {
                    v = ordinal | (ADDR3264)1 << (حجم(ADDR3264)*8 - 1);
                } وإلا {
                    v = pe->thunk->انکڑے_وتھ + rva_ادھار;
                    section_ptr_جوڑو(pe->thunk, حجم(لفظ_3)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } وإلا {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->انکڑے+thk_ptr) =
            *(ADDR3264*)(pe->thunk->انکڑے+ent_ptr) = v;
            thk_ptr += حجم (ADDR3264);
            ent_ptr += حجم (ADDR3264);
        }
        dll_ptr += حجم(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

بنية pe_ترتیب_دیو_sym
{
    صحيح اشاریہ;
    ثابت حرف *name;
};

ساكن صحيح sym_cmp(ثابت فراغ *va, ثابت فراغ *vb)
{
    ثابت حرف *ca = (*(بنية pe_ترتیب_دیو_sym**)va)->name;
    ثابت حرف *cb = (*(بنية pe_ترتیب_دیو_sym**)vb)->name;
    أرجع strcmp(ca, cb);
}

ساكن فراغ pe_build_exports(بنية pe_info *pe)
{
    ElfW(Sym) *sym;
    صحيح sym_اشاریہ, sym_سرا;
    DWORD rva_ادھار, ادھار_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    صحيح sym_گنتی, ord;
    بنية pe_ترتیب_دیو_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    حرف buf[260];
    ثابت حرف *dllname;
    ثابت حرف *name;

    rva_ادھار = pe->thunk->sh_addr - pe->imagebase;
    sym_گنتی = 0, sorted = عدم, op = عدم;

    sym_سرا = symtab_section->انکڑے_وتھ / حجم(ElfW(Sym));
    لكل (sym_اشاریہ = 1; sym_اشاریہ < sym_سرا; ++sym_اشاریہ) {
        sym = (ElfW(Sym)*)symtab_section->انکڑے + sym_اشاریہ;
        name = pe_export_name(s1, sym);
        إذا (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(حجم *p);
            p->اشاریہ = sym_اشاریہ;
            p->name = name;
            dynarray_جوڑو(&sorted, &sym_گنتی, p);
        }
#إذا 0
        إذا (sym->st_other & ST_PE_EXPORT)
            لکھو("export: %s\n", name);
        إذا (sym->st_other & ST_PE_STDCALL)
            لکھو("stdcall: %s\n", name);
#جے_انت
    }

    إذا (0 == sym_گنتی)
        أرجع;

    qsort (sorted, sym_گنتی, حجم *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    ادھار_o = pe->thunk->انکڑے_وتھ;
    func_o = ادھار_o + حجم(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_گنتی * حجم (DWORD);
    ord_o = name_o + sym_گنتی * حجم (DWORD);
    str_o = ord_o + sym_گنتی * حجم(لفظ_3);

    hdr = section_ptr_جوڑو(pe->thunk, str_o - ادھار_o);
    hdr->Characteristics        = 0;
    hdr->ادھار_2                   = 1;
    hdr->نمبر_دا_Functions      = sym_گنتی;
    hdr->نمبر_دا_ناں          = sym_گنتی;
    hdr->پتہ_دا_Functions     = func_o + rva_ادھار;
    hdr->پتہ_دا_ناں         = name_o + rva_ادھار;
    hdr->پتہ_دا_Name_Ordinals  = ord_o + rva_ادھار;
    hdr->Name                   = str_o + rva_ادھار;
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
            لکھو("<- %s (%d symbol%s)\n", buf, sym_گنتی, &"s"[sym_گنتی < 2]);
    }
#جے_انت

    لكل (ord = 0; ord < sym_گنتی; ++ord)
    {
        p = sorted[ord], sym_اشاریہ = p->اشاریہ, name = p->name;
        /* insert actual address later in relocate_sections() */
        put_elf_reloc(symtab_section, pe->thunk,
            func_o, R_XXX_RELATIVE, sym_اشاریہ);
        *(DWORD*)(pe->thunk->انکڑے + name_o)
            = pe->thunk->انکڑے_وتھ + rva_ادھار;
        *(لفظ_3*)(pe->thunk->انکڑے + ord_o)
            = ord;
        put_elf_str(pe->thunk, name);
        func_o += حجم (DWORD);
        name_o += حجم (DWORD);
        ord_o += حجم (لفظ_3);
        إذا (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = ادھار_o + rva_ادھار;
    pe->exp_ناپ = pe->thunk->انکڑے_وتھ - ادھار_o;
    dynarray_reset(&sorted, &sym_گنتی);
    إذا (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
ساكن فراغ pe_build_reloc (بنية pe_info *pe)
{
    DWORD وتھ, بلاک_ptr, sh_addr, addr;
    صحيح گنتی_2, i;
    ElfW_Rel *rel, *rel_سرا;
    Section *s = عدم, *sr;
    بنية pe_reloc_سرخی *hdr;
    TCCState *s1 = pe->s1;
    صحيح dwarf = 0, n;

    sh_addr = وتھ = بلاک_ptr = گنتی_2 = i = 0;
    rel = rel_سرا = عدم;

    لكل(;;) {
        إذا (rel < rel_سرا) {
            صحيح type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_وتھ + sh_addr;
            ++ rel;
            إذا (type != REL_TYPE_سدھا)
                استمر;
            إذا (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->انکڑے + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                إذا (n >= s1->dwlo && n < s1->dwhi)
                    استمر;
            }
            إذا (گنتی_2 == 0) { /* new block */
                بلاک_ptr = pe->reloc->انکڑے_وتھ;
                section_ptr_جوڑو(pe->reloc, حجم(بنية pe_reloc_سرخی));
                وتھ = addr & 0xFFFFFFFF<<12;
            }
            إذا ((addr -= وتھ)  < (1<<12)) { /* one block spans 4k addresses */
                لفظ_3 *wp = section_ptr_جوڑو(pe->reloc, حجم (لفظ_3));
                *wp = addr | PE_IMAGE_REL<<12;
                ++گنتی_2;
                استمر;
            }
            -- rel;

        } وإلا إذا (s) {
            sr = s->reloc;
            إذا (sr) {
                rel = (ElfW_Rel *)sr->انکڑے;
                rel_سرا = (ElfW_Rel *)(sr->انکڑے + sr->انکڑے_وتھ);
                sh_addr = s->sh_addr;
                dwarf = s->sh_عدد >= s1->dwlo && s->sh_عدد < s1->dwhi;
            }
            s = s->prev;
            استمر;

        } وإلا إذا (i < pe->sec_گنتی) {
            s = pe->sec_info[i]->sec, ++i;
            استمر;

        } وإلا إذا (!گنتی_2)
            اكسر;

        /* fill the last block and ready for a new one */
        إذا (گنتی_2 & 1) /* align for DWORDS */
            section_ptr_جوڑو(pe->reloc, حجم(لفظ_3)), ++گنتی_2;
        hdr = (بنية pe_reloc_سرخی *)(pe->reloc->انکڑے + بلاک_ptr);
        hdr -> وتھ = وتھ - pe->imagebase;
        hdr -> ناپ = گنتی_2 * حجم(لفظ_3) + حجم(بنية pe_reloc_سرخی);
        گنتی_2 = 0;
    }
}

/* ------------------------------------------------------------- */
ساكن فراغ pe_build_tls(بنية pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    صحيح c, n;

    إذا (0 == s) {
        pe->tls_ناپ = حجم (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_جوڑو(pe->thunk, pe->tls_ناپ, 16);
        pe->tls_انکڑے = section_جوڑو(انکڑے_section, PTR_ناپ * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, انکڑے_section->sh_عدد, 0);
        لكل (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_ناپ*n, REL_TYPE_سدھا, c);
        /* for generators */
        سیٹ_elf_sym(symtab_section, pe->tls_انکڑے, PTR_ناپ * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, انکڑے_section->sh_عدد, "__tls_index");
        أرجع;
    }

    إذا (0 == s1->tls_شروع)
        s1->tls_شروع = s->sh_addr;
    d = (فراغ*)(pe->thunk->انکڑے + pe->tls_dir);
    d->شروع_پتہ_دا_Raw_انکڑے = s1->tls_شروع - انکڑے_section->sh_addr;
    d->سرا_پتہ_دا_Raw_انکڑے = s->sh_addr + s->انکڑے_وتھ - انکڑے_section->sh_addr;
    d->پتہ_دا_اشاریہ = pe->tls_انکڑے;
    d->پتہ_دا_Call_Backs = pe->tls_انکڑے + PTR_ناپ;
    d->ناپ_دا_Zero_Fill = 0;
    d->Characteristics = 0;
    /* to reuse logic from linux in xxx-link.c */
    s1->tls_سرا = s1->tls_شروع;
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
                أرجع sec_انکڑے;
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
    أرجع sec_آخری;
}

ساكن صحيح pe_سونپو_پتے (بنية pe_info *pe)
{
    صحيح i, k, n, c, nbs;
    ADDR3264 addr;
    صحيح *sec_ترتیب, *sec_cls;
    بنية section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    إذا (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_ادھار))
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
        إذا ((s->sh_flags & SHF_TLS) && 0 == pe->tls_ناپ)
            pe_build_tls(pe, عدم);
    }
    si = عدم;
    addr = pe->imagebase + 1;
    لكل (i = 1; (c = sec_cls[i]) < sec_آخری; ++i) {
        s = s1->sections[sec_ترتیب[i]];

        إذا (PE_ملاؤ_انکڑے && c == sec_bss)
            c = sec_انکڑے;
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

        إذا (0 == s->انکڑے_وتھ)
            استمر;

        إذا (si)
            اذهب جوڑو_section;

        si = tcc_mallocz(حجم *si);
        dynarray_جوڑو(&pe->sec_info, &pe->sec_گنتی, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        إذا (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_کوڈ;
        وإلا إذا (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_انکڑے;
        وإلا
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_انکڑے;
        إذا (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        إذا (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

جوڑو_section:
        s->sh_info = pe->sec_گنتی; /* section number for coff syms */
        addr += s->انکڑے_وتھ;
        si->sh_ناپ = addr - si->sh_addr;
        إذا (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            طالما (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = عدم;
            si->انکڑے_ناپ = si->sh_ناپ;
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
        لکھو("section %-16s %-10s %p %04x %2d %s,%s,%s\n",
            s->name,
            type == SHT_PROGBITS ? "progbits" :
            type == SHT_INIT_ARRAY ? "initarr" :
            type == SHT_FINI_ARRAY ? "finiarr" :
            type == SHT_NOBITS ? "nobits" :
            type == SHT_SYMTAB ? "symtab" :
            type == SHT_STRTAB ? "strtab" :
            type == SHT_RELX ? "rel" : "???",
            s->sh_addr,
            (بنانشانی)s->انکڑے_وتھ,
            s->sh_addralign,
            flags & SHF_ALLOC ? "alloc" : "",
            flags & SHF_WRITE ? "write" : "",
            flags & SHF_EXECINSTR ? "exec" : ""
            );
        fflush(stdout);
    }
    s1->verbose = 2;
#جے_انت
    tcc_free(sec_ترتیب);
    أرجع 0;
}

/*----------------------------------------------------------------------------*/
ساكن صحيح pe_check_symbols(بنية pe_info *pe)
{
    صحيح sym_اشاریہ, sym_سرا;
    صحيح ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(متن_section, 8);

    sym_سرا = symtab_section->انکڑے_وتھ / حجم(ElfW(Sym));
    لكل (sym_اشاریہ = 1; sym_اشاریہ < sym_سرا; ++sym_اشاریہ) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->انکڑے + sym_اشاریہ;
        إذا (sym->st_shndx == SHN_UNDEF) {
            ثابت حرف *name = (حرف*)symtab_section->link->انکڑے + sym->st_name;
            بنانشانی type = ELFW(ST_TYPE)(sym->st_info);
            صحيح imp_sym = 0;
            بنية import_علامت *is;

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
                imp_sym = لبھو_elf_sym(s1->dynsymtab_section, s);
            } طالما (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            إذا (0 == imp_sym)
                استمر; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_جوڑو_import(pe, imp_sym);

            إذا (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                بنانشانی وتھ = is->thk_وتھ;
                إذا (وتھ) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } وإلا {
                    بنانشانی حرف *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(بفر, "IAT.%s", name);
                    is->iat_اشاریہ = put_elf_sym(
                        symtab_section, 0, حجم(DWORD),
                        ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT),
                        0, SHN_UNDEF, بفر);

                    وتھ = متن_section->انکڑے_وتھ;
                    is->thk_وتھ = وتھ;

                    /* add the 'jmp IAT[x]' instruction */
#جے_تعریف_شدہ TCC_نشانہ_ARM
                    p = section_ptr_جوڑو(متن_section, 8+4); // room for code and address
                    write32le(p + 0, 0xE59FC000); // arm code ldr ip, [pc] ; PC+8+0 = 0001xxxx
                    write32le(p + 4, 0xE59CF000); // arm code ldr pc, [ip]
                    put_elf_reloc(symtab_section, متن_section,
                        وتھ + 8, R_XXX_THUNKFIX, is->iat_اشاریہ); // offset to IAT position
#وإلاإذا defined(TCC_نشانہ_ARM64)
                    p = section_ptr_جوڑو(متن_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, متن_section,
                        وتھ + 16, R_XXX_THUNKFIX, is->iat_اشاریہ);
#وإلا
                    p = section_ptr_جوڑو(متن_section, 8);
                    write16le(p, 0x25FF);
#جے_تعریف_شدہ TCC_نشانہ_X86_64
                    write32le(p + 2, (DWORD)-4);
#جے_انت
                    put_elf_reloc(symtab_section, متن_section, 
                        وتھ + 2, R_XXX_THUNKFIX, is->iat_اشاریہ);
#جے_انت
                }
                /* tcc_realloc might have altered sym's address */
                sym = (ElfW(Sym) *)symtab_section->انکڑے + sym_اشاریہ;
                /* patch the original symbol */
                sym->st_قدر = وتھ;
                sym->st_shndx = متن_section->sh_عدد;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } وإلا { /* STT_OBJECT */
                إذا (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_قدر = is->iat_اشاریہ; /* chain potential alias */
                is->iat_اشاریہ = sym_اشاریہ;
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
    p = s->انکڑے;
    e = s->انکڑے + s->انکڑے_وتھ;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    إذا (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    إذا (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (بنانشانی)s->sh_addr);
    fprintf(f, "\ncontents %08X", (بنانشانی)l);
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
            ثابت حرف *name = s->link->انکڑے + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (بنانشانی)sym->st_name,
                    (بنانشانی)sym->st_قدر,
                    (بنانشانی)sym->st_ناپ,
                    (بنانشانی)ELFW(ST_BIND)(sym->st_info),
                    (بنانشانی)ELFW(ST_TYPE)(sym->st_info),
                    (بنانشانی)sym->st_other,
                    (بنانشانی)sym->st_shndx,
                    name);

        } وإلا إذا (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->انکڑے + ELFW(R_SYM)(rel->r_info);
            ثابت حرف *name = s->link->link->انکڑے + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (بنانشانی)rel->r_وتھ,
                    (بنانشانی)ELFW(R_TYPE)(rel->r_info),
                    (بنانشانی)ELFW(R_SYM)(rel->r_info),
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
#جے_انت

/* ------------------------------------------------------------- */

ST_FUNC صحيح pe_putimport(TCCState *s1, صحيح dllindex, ثابت حرف *name, addr_t قدر)
{
    أرجع سیٹ_elf_sym(
        s1->dynsymtab_section,
        قدر,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        قدر ? SHN_ABS : SHN_UNDEF,
        name
        );
}

ساكن صحيح read_mem(صحيح fd, بنانشانی وتھ, فراغ *بفر, بنانشانی len)
{
    lseek(fd, وتھ, SEEK_SET);
    أرجع len == اقرأ(fd, بفر, len);
}

/* ------------------------------------------------------------- */

ساكن صحيح get_dllexports(صحيح fd, حرف **pp)
{
    صحيح i, k, l, n, n0, ret;
    حرف *p;

    IMAGE_SECTION_سرخی_2 ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_سرخی_2 dh;
    IMAGE_FILE_سرخی_2 ih;
    DWORD sig, ref, addr;
    DWORD *namep = عدم, p0 = 0, p1;

    صحيح pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = عدم;
    ret = 1;
    إذا (!read_mem(fd, 0, &dh, حجم dh))
        اذهب the_سرا;
    إذا (!read_mem(fd, dh.e_lfanew, &sig, حجم sig))
        اذهب the_سرا;
    إذا (sig != 0x00004550)
        اذهب the_سرا;
    pef_hdroffset = dh.e_lfanew + حجم sig;
    إذا (!read_mem(fd, pef_hdroffset, &ih, حجم ih))
        اذهب the_سرا;
    opt_hdroffset = pef_hdroffset + حجم ih;
    إذا (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + حجم oh;
        إذا (!read_mem(fd, opt_hdroffset, &oh, حجم oh))
            اذهب the_سرا;
        إذا (IMAGE_DIRECTORY_اندراج_EXPORT >= oh.نمبر_دا_Rva_And_Sizes)
            اذهب the_سرا_0;
        addr = oh.انکڑے_Directory[IMAGE_DIRECTORY_اندراج_EXPORT].Virtual_پتہ;
    } وإلا إذا (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + حجم oh;
        إذا (!read_mem(fd, opt_hdroffset, &oh, حجم oh))
            اذهب the_سرا;
        إذا (IMAGE_DIRECTORY_اندراج_EXPORT >= oh.نمبر_دا_Rva_And_Sizes)
            اذهب the_سرا_0;
        addr = oh.انکڑے_Directory[IMAGE_DIRECTORY_اندراج_EXPORT].Virtual_پتہ;
    } وإلا
        اذهب the_سرا;

    //printf("addr: %08x\n", addr);
    لكل (i = 0; i < ih.نمبر_دا_Sections; ++i) {
        إذا (!read_mem(fd, sec_hdroffset + i * حجم ish, &ish, حجم ish))
            اذهب the_سرا;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        إذا (addr >= ish.Virtual_پتہ && addr < ish.Virtual_پتہ + ish.ناپ_دا_Raw_انکڑے)
            اذهب لبھیا;
    }
    اذهب the_سرا_0;
لبھیا:
    ref = ish.Virtual_پتہ - ish.اشارہ_گر_منزل_Raw_انکڑے;
    إذا (!read_mem(fd, addr - ref, &ied, حجم ied))
        اذهب the_سرا;
    k = ied.نمبر_دا_ناں;
    إذا (k) {
        namep = tcc_malloc(l = k * حجم *namep);
        إذا (!read_mem(fd, ied.پتہ_دا_ناں - ref, namep, l))
            اذهب the_سرا;
        لكل (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            إذا (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            افعل {
                إذا (0 == l) {
                    إذا (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    إذا ((l = اقرأ(fd, p + n, 1000 - 1)) <= 0)
                        اذهب the_سرا;
                }
                --l, ++p0;
            } طالما (p[n++]);
        }
        p[n] = 0;
    }
the_سرا_0:
    ret = 0;
the_سرا:
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

ساكن صحيح pe_لدو_res(TCCState *s1, صحيح fd)
{
    بنية pe_rsrc_سرخی hdr;
    Section *rsrc_section;
    صحيح i, ret = -1, sym_اشاریہ;
    BYTE *ptr;
    بنانشانی offs;

    إذا (!read_mem(fd, 0, &hdr, حجم hdr))
        اذهب quit;

    إذا (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.نمبر_دا_Sections != 1
        || strcmp((حرف*)hdr.sectionhdr.Name, ".rsrc") != 0)
        اذهب quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_جوڑو(rsrc_section, hdr.sectionhdr.ناپ_دا_Raw_انکڑے);
    offs = hdr.sectionhdr.اشارہ_گر_منزل_Raw_انکڑے;
    إذا (!read_mem(fd, offs, ptr, hdr.sectionhdr.ناپ_دا_Raw_انکڑے))
        اذهب quit;
    offs = hdr.sectionhdr.اشارہ_گر_منزل_Relocations;
    sym_اشاریہ = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_عدد, ".rsrc");
    لكل (i = 0; i < hdr.sectionhdr.نمبر_دا_Relocations; ++i) {
        بنية pe_rsrc_reloc rel;
        إذا (!read_mem(fd, offs, &rel, حجم rel))
            اذهب quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        إذا (rel.type != RSRC_RELTYPE)
            اذهب quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.وتھ, R_XXX_RELATIVE, sym_اشاریہ);
        offs += حجم rel;
    }
    ret = 0;
quit:
    أرجع ret;
}

/* ------------------------------------------------------------- */

ساكن حرف *trimfront(حرف *p)
{
    طالما ((بنانشانی حرف)*p <= ' ' && *p && *p != '\n')
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
    لكل (e = p; (بنانشانی حرف)*e >= ' ' && *e != q; ++e)
        ;
    إذا (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    أرجع p;
}

ساكن صحيح pe_لدو_def(TCCState *s1, صحيح fd)
{
    صحيح state = 0, ret = -1, dllindex = 0, ord;
    حرف dllname[80], *buf, *سطر, *p, *x, اگلا;

    buf = tcc_لدو_متن(fd);
    إذا (!buf)
        أرجع ret;

    لكل (سطر = buf;; ++سطر)  {
        p = get_token(&سطر, &اگلا);
        إذا (!(*p && *p != ';'))
            اذهب skip;
        بدل (state) {
        حالة 0:
            إذا (0 != stricmp(p, "LIBRARY") || اگلا == '\n')
                اذهب quit;
            pstrcpy(dllname, حجم dllname, get_token(&سطر, &اگلا));
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
            dllindex = tcc_جوڑو_dllref(s1, dllname, 0)->اشاریہ;
            ++state;
            /* fall through */
        افتراضي:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            إذا (اگلا == '@') {
                x = get_token(&سطر, &اگلا);
                ord = (صحيح)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            اكسر;
        }
skip:
        طالما ((بنانشانی حرف)اگلا > ' ')
            get_token(&سطر, &اگلا);
        إذا (اگلا != '\n')
            اكسر;
    }
    ret = 0;
quit:
    tcc_free(buf);
    أرجع ret;
}

/* ------------------------------------------------------------- */

ساكن صحيح pe_لدو_dll(TCCState *s1, صحيح fd, ثابت حرف *filename)
{
    حرف *p, *q;
    DLLReference *ref = tcc_جوڑو_dllref(s1, filename, 0);
    إذا (ref->لبھیا)
        أرجع 0;
    إذا (get_dllexports(fd, &p))
        أرجع -1;
    إذا (p) {
        لكل (q = p; *q; q += 1 + لڑی_لمبائی(q))
            pe_putimport(s1, ref->اشاریہ, q, 0);
        tcc_free(p);
    }
    أرجع 0;
}

ST_FUNC صحيح pe_لدو_file(بنية TCCState *s1, صحيح fd, ثابت حرف *filename)
{
    صحيح ret = -1;
    حرف buf[10];
    إذا (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_لدو_def(s1, fd);
    وإلا إذا (pe_لدو_res(s1, fd) == 0)
        ret = 0;
    وإلا إذا (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_لدو_dll(s1, fd, filename);
    أرجع ret;
}

PUB_FUNC صحيح tcc_get_dllexports(ثابت حرف *filename, حرف **pp)
{
    صحيح ret, fd = open(filename, O_RDONLY | O_ثنائی_2);
    إذا (fd < 0)
        أرجع -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    أرجع ret;
}

/* ------------------------------------------------------------- */
#جے_تعریف_شدہ TCC_نشانہ_X86_64
ساكن بنانشانی pe_جوڑو_unwind_info(TCCState *s1)
{
    إذا (عدم == s1->uw_pdata) {
        s1->uw_pdata = لبھو_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    إذا (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, متن_section->sh_عدد, ".uw_base");
    إذا (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        ساكن ثابت بنانشانی حرف uw_info[] = {
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
        بنانشانی حرف *p;

        section_ptr_جوڑو(s, -s->انکڑے_وتھ & 3); /* align */
        s1->uw_offs = s->انکڑے_وتھ;
        p = section_ptr_جوڑو(s, حجم uw_info);
        حافظہ_نقل(p, uw_info, حجم uw_info);
    }

    أرجع s1->uw_offs;
}

ST_FUNC فراغ pe_جوڑو_unwind_انکڑے(بنانشانی شروع, بنانشانی سرا, بنانشانی ڈھیر)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    بنانشانی o, n, d;
    بنية /* _RUNTIME_FUNCTION */ {
      DWORD Begin_پتہ;
      DWORD سرا_پتہ;
      DWORD Unwind_انکڑے;
    } *p;

    d = pe_جوڑو_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->انکڑے_وتھ;
    p = section_ptr_جوڑو(pd, حجم *p);

    /* record this function */
    p->Begin_پتہ = شروع;
    p->سرا_پتہ = سرا;
    p->Unwind_انکڑے = d;

    /* put relocations on it */
    لكل (n = o + حجم *p; o < n; o += حجم p->Begin_پتہ)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#وإلاإذا defined(TCC_نشانہ_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
ساكن Section *pe_جوڑو_unwind_info(TCCState *s1)
{
    Section *s;

    إذا (عدم == s1->uw_pdata) {
        s1->uw_pdata = لبھو_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = لبھو_section(s1, ".xdata");
    s->sh_addralign = 4;
    إذا (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  متن_section->sh_عدد, ".uw_text_base");
    إذا (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_عدد, ".uw_base");
    أرجع s;
}

ST_FUNC فراغ pe_جوڑو_unwind_انکڑے(بنانشانی شروع, بنانشانی سرا, بنانشانی ڈھیر)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    بنانشانی o, d, کوڈ_بائٹاں, func_len;
    بنانشانی حرف *q;
    uint32_t سرخی;
    بنية /* _RUNTIME_FUNCTION */ {
        DWORD Begin_پتہ;
        DWORD Unwind_انکڑے;
    } *p;

    صحيح epilog;

    xd = pe_جوڑو_unwind_info(s1);
    pd = s1->uw_pdata;

    func_len = (سرا - شروع) >> 2;
    کوڈ_بائٹاں = 0;
    epilog = کوڈ_بائٹاں;
    کوڈ_بائٹاں += 3; /* set_fp, save_fplr_x, end */
    کوڈ_بائٹاں = (کوڈ_بائٹاں + 3) & ~3;

    section_ptr_جوڑو(xd, -xd->انکڑے_وتھ & 3);
    d = xd->انکڑے_وتھ;
    q = section_ptr_جوڑو(xd, 4 + کوڈ_بائٹاں);

    /* Full ARM64 xdata header: E=1 with one epilog and no exception handler. */
    سرخی = (func_len & 0x3ffff)
        | 1 << 21
        | (epilog & 0x1F) << 22
        | (کوڈ_بائٹاں >> 2) << 27
        ;
    write32le(q, سرخی);
    q += 4;
    *q++ = 0xE1; /* set_fp */
    *q++ = 0x9B; /* save_fplr_x: stp x29,lr,[sp,#-224]! */
    *q++ = 0xE4; /*سرا*/
    طالما ((بنانشانی)(q - (xd->انکڑے + d + 4)) < کوڈ_بائٹاں)
        *q++ = 0xE3; /* nop padding */

    o = pd->انکڑے_وتھ;
    p = section_ptr_جوڑو(pd, حجم *p);
    p->Begin_پتہ = شروع;
    p->Unwind_انکڑے = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#جے_انت
/* ------------------------------------------------------------- */
#إذا defined(TCC_نشانہ_X86_64) || defined(TCC_نشانہ_ARM64)
#تعریف_کرو PE_STDSYM(n,s) n
#وإلا
#تعریف_کرو PE_STDSYM(n,s) "_" n s
#جے_انت

ساكن فراغ pe_جوڑو_runtime(TCCState *s1, بنية pe_info *pe)
{
    ثابت حرف *شروع_علامت;
    صحيح pe_type;

    إذا (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        شروع_علامت = PE_STDSYM("__dllstart","@12");
    } وإلا {
        ثابت حرف *لگاتار_علامت;
        إذا (لبھو_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            شروع_علامت = "__winstart";
            لگاتار_علامت = "__runwinmain";
            pe_type = PE_GUI;
        } وإلا إذا (لبھو_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            شروع_علامت = "__wwinstart";
            لگاتار_علامت = "__runwwinmain";
            pe_type = PE_GUI;
        } وإلا إذا (لبھو_elf_sym(symtab_section, "wmain")) {
            شروع_علامت = "__wstart";
            لگاتار_علامت = "__runwmain";
            pe_type = PE_EXE;
        } وإلا {
            شروع_علامت =  "__start";
            لگاتار_علامت = "__runmain";
            pe_type = PE_EXE;
            إذا (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        إذا (TCC_OUTPUT_حافظہ == s1->output_type && !s1->nostdlib)
            شروع_علامت = لگاتار_علامت;
    }
    إذا (s1->elf_entryname) {
        pe->شروع_علامت = شروع_علامت = s1->elf_entryname;
    } وإلا {
        pe->شروع_علامت = شروع_علامت + 1;
        إذا (!s1->leading_underscore || strchr(شروع_علامت, '@'))
            ++شروع_علامت;
    }

#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE
    إذا (s1->do_backtrace) {
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
        إذا (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    إذا (s1->output_type == TCC_OUTPUT_حافظہ)
                tcc_جوڑو_support(s1, "bcheck_run.o");
	    وإلا
                tcc_جوڑو_support(s1, "bcheck.o");
	}
#جے_انت
        إذا (s1->output_type == TCC_OUTPUT_EXE)
            tcc_جوڑو_support(s1, "bt-exe.o");
        إذا (s1->output_type == TCC_OUTPUT_DLL)
            tcc_جوڑو_support(s1, "bt-dll.o");
        إذا (s1->output_type != TCC_OUTPUT_DLL)
            tcc_جوڑو_support(s1, "bt-log.o");
        tcc_جوڑو_btstub(s1);
    }
#جے_انت

    /* grab the startup code from libtcc1.a */
#جے_تعریف_شدہ TCC_IS_NATIVE
    إذا (TCC_OUTPUT_حافظہ != s1->output_type || s1->لگاتار_main)
#جے_انت
    سیٹ_global_sym(s1, شروع_علامت, عدم, 0);

    إذا (0 == s1->nostdlib) {
        ساكن ثابت حرف * ثابت libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", عدم
        };
        ثابت حرف * ثابت *pp, *p;
        إذا (TCC_LIBTCC1[0])
            tcc_جوڑو_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        لكل (pp = libs; 0 != (p = *pp); ++pp) {
            إذا (*p)
                tcc_جوڑو_library(s1, p);
            وإلا إذا (PE_DLL != pe_type && PE_GUI != pe_type)
                اكسر;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    إذا (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    إذا (TCC_OUTPUT_حافظہ == s1->output_type)
        pe_type = PE_لگاتار;
    pe->type = pe_type;
}

ST_FUNC صحيح pe_setsubsy(TCCState *s1, ثابت حرف *arg)
{
    ساكن ثابت بنية subsy { ثابت حرف* p; صحيح v; } x[] = {
#إذا defined(TCC_نشانہ_I386) || defined(TCC_نشانہ_X86_64) || defined(TCC_نشانہ_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#وإلاإذا defined(TCC_نشانہ_ARM)
        { "wince", 9 },
#جے_انت
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

ساكن فراغ pe_سیٹ_options(TCCState * s1, بنية pe_info *pe)
{
    إذا (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_ادھار_DLL;
    } وإلا {
        pe->imagebase = IMAGE_ادھار_EXE;
    }

#إذا defined(TCC_نشانہ_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#وإلا
    إذا (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    وإلا
        pe->subsystem = 3;
#جے_انت
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

#جے_تعریف_شدہ CONFIG_TCC_BCHECK
    tcc_جوڑو_bcheck(s1);
#جے_انت
    tcc_جوڑو_pragma_libs(s1);
    pe_جوڑو_runtime(s1, &pe);
    resolve_common_syms(s1);
    pe_سیٹ_options(s1, &pe);
    pe_check_symbols(&pe);
    إذا (s1->nb_errors)
        اذهب پورا;
    إذا (filename) {
        pe_سونپو_پتے(&pe);
        relocate_syms(s1, s1->symtab, 0);
        إذا (s1->nb_errors)
            اذهب پورا;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.شروع_addr = (DWORD)
            (get_sym_addr(s1, pe.شروع_علامت, 1, 1) - pe.imagebase);
        إذا (s1->nb_errors)
            اذهب پورا;
        pe_write(&pe);
    } وإلا {
        /* -run */
#جے_تعریف_شدہ TCC_IS_NATIVE
        pe.thunk = انکڑے_section;
        pe_build_imports(&pe);
        s1->لگاتار_main = pe.شروع_علامت;
#إذا defined(TCC_نشانہ_X86_64) || defined(TCC_نشانہ_ARM64)
        s1->uw_pdata = لبھو_section(s1, ".pdata");
#جے_انت
#جے_انت
    }
پورا:
    dynarray_reset(&pe.sec_info, &pe.sec_گنتی);
    pe_free_imports(&pe);
#إذا PE_PRINT_SECTIONS
    إذا (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#جے_انت
    أرجع s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
