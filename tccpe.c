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

#تعریف_کن PE_ادغام_داده 1
#تعریف_کن PE_PRINT_SECTIONS 0

#اگر_تعریف_نشده _WIN32
#تعریف_کن stricmp strcasecmp
#تعریف_کن strnicmp strncasecmp
#ضمن <sys/stat.h> /* chmod() */
#پایان_اگر

#إذا defined TCC_هدف_X86_64
# define REL_TYPE_مستقیم R_X86_64_64
# define R_XXX_THUNKFIX R_X86_64_PC32
# define R_XXX_RELATIVE R_X86_64_RELATIVE
# define R_XXX_FUNCCALL R_X86_64_PLT32
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0x8664
# define CHARACTERISTICS_EXE 0x022F
# define CHARACTERISTICS_DLL 0x222E
# define IMAGE_پایه_EXE 0x00400000
# define IMAGE_پایه_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#وإلاإذا defined TCC_هدف_ARM
# define REL_TYPE_مستقیم R_ARM_ABS32
# define R_XXX_THUNKFIX R_ARM_ABS32
# define R_XXX_RELATIVE R_ARM_RELATIVE
# define R_XXX_FUNCCALL R_ARM_PC24
# define R_XXX_FUNCCALL2 R_ARM_ABS32
# define RSRC_RELTYPE 7 /* ??? (not tested) */
# define IMAGE_FILE_MACHINE 0x01C0
# define CHARACTERISTICS_EXE 0x010F
# define CHARACTERISTICS_DLL 0x230F
# define IMAGE_پایه_EXE 0x00100000
# define IMAGE_پایه_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#وإلاإذا defined TCC_هدف_ARM64
# define REL_TYPE_مستقیم R_AARCH64_ABS64
# define R_XXX_THUNKFIX R_AARCH64_ABS64
# define R_XXX_RELATIVE R_AARCH64_RELATIVE
# define R_XXX_FUNCCALL R_AARCH64_CALL26
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0xAA64
# define CHARACTERISTICS_EXE 0x0022
# define CHARACTERISTICS_DLL 0x2022
# define IMAGE_پایه_EXE 0x140000000ULL
# define IMAGE_پایه_DLL 0x180000000ULL
# define OS_VER 0x0602
# define DLLCHARACTERISTICS 0x8160

#وإلاإذا defined TCC_هدف_I386
# define REL_TYPE_مستقیم R_386_32
# define R_XXX_THUNKFIX R_386_32
# define R_XXX_RELATIVE R_386_RELATIVE
# define R_XXX_FUNCCALL R_386_PC32
# define RSRC_RELTYPE 7 /* DIR32NB */
# define IMAGE_FILE_MACHINE 0x014C
# define CHARACTERISTICS_EXE 0x030F
# define CHARACTERISTICS_DLL 0x230E
# define IMAGE_پایه_EXE 0x00400000
# define IMAGE_پایه_DLL 0x10000000
# define OS_VER 0x0400
# define DLLCHARACTERISTICS 0
#پایان_اگر

#إذا PTR_اندازه == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#وإلا
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#پایان_اگر

#اگر_تعریف_نشده IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

تعريفنوع بیعلامت حرف BYTE;
تعريفنوع بیعلامت کوتاه کلمه_3;
تعريفنوع بیعلامت صحيح DWORD;
تعريفنوع بیعلامت دراز دراز ULONGLONG;
#رهنمود pack(افزودن, 1)

تعريفنوع بنية IMAGE_DOS_سرآیند {  /* DOS .EXE header */
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
} IMAGE_DOS_سرآیند_2, *PIMAGE_DOS_سرآیند;

#تعریف_کن IMAGE_NT_SIGNATURE  0x00004550  /* PE00 */

تعريفنوع بنية IMAGE_FILE_سرآیند {
    کلمه_3    Machine;
    کلمه_3    عدد_از_Sections;
    DWORD   زمان_Date_Stamp;
    DWORD   اشاره_گر_مقصد_نماد_جدول;
    DWORD   عدد_از_Symbols;
    کلمه_3    اندازه_از_Optional_سرآیند;
    کلمه_3    Characteristics;
} IMAGE_FILE_سرآیند_2, *PIMAGE_FILE_سرآیند;


#تعریف_کن IMAGE_SIZEOF_FILE_سرآیند 20

تعريفنوع بنية IMAGE_داده_DIRECTORY {
    DWORD   Virtual_آدرس;
    DWORD   اندازه_3;
} IMAGE_داده_DIRECTORY_2, *PIMAGE_داده_DIRECTORY;


تعريفنوع بنية IMAGE_OPTIONAL_سرآیند {
    /* Standard fields. */
    کلمه_3    Magic;
    BYTE    Major_Linker_نسخه;
    BYTE    Minor_Linker_نسخه;
    DWORD   اندازه_از_کد;
    DWORD   اندازه_از_Initialized_داده;
    DWORD   اندازه_از_Uninitialized_داده;
    DWORD   آدرس_از_مدخل_نقطه;
    DWORD   پایه_از_کد;
#إذا PTR_اندازه == 4
    DWORD   پایه_از_داده;
#پایان_اگر
    /* NT additional fields. */
    ADDR3264 Image_پایه;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    کلمه_3    Major_Operating_System_نسخه;
    کلمه_3    Minor_Operating_System_نسخه;
    کلمه_3    Major_Image_نسخه;
    کلمه_3    Minor_Image_نسخه;
    کلمه_3    Major_Subsystem_نسخه;
    کلمه_3    Minor_Subsystem_نسخه;
    DWORD   Win32_نسخه_مقدار;
    DWORD   اندازه_از_Image;
    DWORD   اندازه_از_سرآیندها;
    DWORD   Check_جمع;
    کلمه_3    Subsystem;
    کلمه_3    DllCharacteristics;
    ADDR3264 اندازه_از_پشته_Reserve;
    ADDR3264 اندازه_از_پشته_Commit;
    ADDR3264 اندازه_از_انباشته_Reserve;
    ADDR3264 اندازه_از_انباشته_Commit;
    DWORD   LoaderFlags;
    DWORD   عدد_از_Rva_And_Sizes;
    IMAGE_داده_DIRECTORY_2 داده_Directory[16];
} IMAGE_OPTIONAL_HEADER32, IMAGE_OPTIONAL_HEADER64, IMAGE_OPTIONAL_سرآیند_2;

#تعریف_کن IMAGE_DIRECTORY_مدخل_EXPORT          0   /* Export Directory */
#تعریف_کن IMAGE_DIRECTORY_مدخل_IMPORT          1   /* Import Directory */
#تعریف_کن IMAGE_DIRECTORY_مدخل_RESOURCE        2   /* Resource Directory */
#تعریف_کن IMAGE_DIRECTORY_مدخل_EXCEPTION       3   /* Exception Directory */
#تعریف_کن IMAGE_DIRECTORY_مدخل_SECURITY        4   /* Security Directory */
#تعریف_کن IMAGE_DIRECTORY_مدخل_BASERELOC       5   /* Base Relocation Table */
#تعریف_کن IMAGE_DIRECTORY_مدخل_DEBUG           6   /* Debug Directory */
/*      IMAGE_DIRECTORY_ENTRY_COPYRIGHT       7      (X86 usage) */
#تعریف_کن IMAGE_DIRECTORY_مدخل_ARCHITECTURE    7   /* Architecture Specific Data */
#تعریف_کن IMAGE_DIRECTORY_مدخل_GLOBALPTR       8   /* RVA of GP */
#تعریف_کن IMAGE_DIRECTORY_مدخل_TLS             9   /* TLS Directory */
#تعریف_کن IMAGE_DIRECTORY_مدخل_بارگیری_CONFIG    10   /* Load Configuration Directory */
#تعریف_کن IMAGE_DIRECTORY_مدخل_BOUND_IMPORT   11   /* Bound Import Directory in headers */
#تعریف_کن IMAGE_DIRECTORY_مدخل_IAT            12   /* Import Address Table */
#تعریف_کن IMAGE_DIRECTORY_مدخل_DELAY_IMPORT   13   /* Delay Load Import Descriptors */
#تعریف_کن IMAGE_DIRECTORY_مدخل_COM_DESCRIPTOR 14   /* COM Runtime descriptor */

/* Section header format. */
#تعریف_کن IMAGE_SIZEOF_SHORT_NAME         8

تعريفنوع بنية IMAGE_SECTION_سرآیند {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    اتحاد {
            DWORD   Physical_آدرس;
            DWORD   Virtual_اندازه;
    } Misc;
    DWORD   Virtual_آدرس;
    DWORD   اندازه_از_Raw_داده;
    DWORD   اشاره_گر_مقصد_Raw_داده;
    DWORD   اشاره_گر_مقصد_Relocations;
    DWORD   اشاره_گر_مقصد_Linenumbers;
    کلمه_3    عدد_از_Relocations;
    کلمه_3    عدد_از_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_سرآیند_2, *PIMAGE_SECTION_سرآیند;

#تعریف_کن IMAGE_SIZEOF_SECTION_سرآیند     40

تعريفنوع بنية _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD زمان_Date_Stamp;
    کلمه_3 Major_نسخه;
    کلمه_3 Minor_نسخه;
    DWORD Name;
    DWORD پایه_2;
    DWORD عدد_از_Functions;
    DWORD عدد_از_نامها;
    DWORD آدرس_از_Functions;
    DWORD آدرس_از_نامها;
    DWORD آدرس_از_Name_Ordinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

تعريفنوع بنية _IMAGE_TLS_DIRECTORY {
    ADDR3264 شروع_آدرس_از_Raw_داده;
    ADDR3264 انتها_آدرس_از_Raw_داده;
    ADDR3264 آدرس_از_شاخص;
    ADDR3264 آدرس_از_Call_Backs;
    DWORD اندازه_از_Zero_Fill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

تعريفنوع بنية _IMAGE_IMPORT_DESCRIPTOR {
    اتحاد {
        DWORD Characteristics;
        DWORD Original_اولی_Thunk;
    };
    DWORD زمان_Date_Stamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD اولی_Thunk;
} IMAGE_IMPORT_DESCRIPTOR;

تعريفنوع بنية IMAGE_پایه_RELOCATION {
    DWORD   Virtual_آدرس;
    DWORD   اندازه_از_بلوک;
//  WORD    TypeOffset[1];
} IMAGE_پایه_RELOCATION_2;

#تعریف_کن IMAGE_SIZEOF_پایه_RELOCATION     8

#تعریف_کن IMAGE_REL_BASED_ABSOLUTE         0
#تعریف_کن IMAGE_REL_BASED_بالا             1
#تعریف_کن IMAGE_REL_BASED_کم              2
#تعریف_کن IMAGE_REL_BASED_HIGHLOW          3
#تعریف_کن IMAGE_REL_BASED_HIGHADJ          4
#تعریف_کن IMAGE_REL_BASED_MIPS_JMPADDR     5
#تعریف_کن IMAGE_REL_BASED_SECTION          6
#تعریف_کن IMAGE_REL_BASED_REL32            7
#تعریف_کن IMAGE_REL_BASED_DIR64           10

#تعریف_کن IMAGE_SCN_CNT_کد                  0x00000020
#تعریف_کن IMAGE_SCN_CNT_INITIALIZED_داده      0x00000040
#تعریف_کن IMAGE_SCN_CNT_UNINITIALIZED_داده    0x00000080
#تعریف_کن IMAGE_SCN_MEM_DISCARDABLE           0x02000000
#تعریف_کن IMAGE_SCN_MEM_SHARED                0x10000000
#تعریف_کن IMAGE_SCN_MEM_EXECUTE               0x20000000
#تعریف_کن IMAGE_SCN_MEM_READ                  0x40000000
#تعریف_کن IMAGE_SCN_MEM_WRITE                 0x80000000

#تعریف_کن IMAGE_DLLCHARACTERISTICS_بالا_ENTROPY_VA 0x0020
#تعریف_کن IMAGE_DLLCHARACTERISTICS_DYNAMIC_پایه 0x0040
#تعریف_کن IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#تعریف_کن IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#تعریف_کن IMAGE_FILE_RELOCS_STRIPPED 0x0001

#رهنمود pack(برداشت)

/* ----------------------------------------------------------- */
#پایان_اگر /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#اگر_تعریف_نشده IMAGE_DLLCHARACTERISTICS_DYNAMIC_پایه
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #تعریف_کن IMAGE_DLLCHARACTERISTICS_DYNAMIC_پایه 0x0040
#پایان_اگر

#رهنمود pack(افزودن, 1)
بنية pe_سرآیند
{
    IMAGE_DOS_سرآیند_2 doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_سرآیند_2 filehdr;
#إذا PTR_اندازه == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#وإلا
#اگر_تعریف_شده _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#وإلا
    IMAGE_OPTIONAL_سرآیند_2 opthdr;
#پایان_اگر
#پایان_اگر
};

بنية pe_reloc_سرآیند {
    DWORD جابه_جایی;
    DWORD اندازه;
};

بنية pe_rsrc_سرآیند {
    بنية IMAGE_FILE_سرآیند filehdr;
    بنية IMAGE_SECTION_سرآیند sectionhdr;
};

بنية pe_rsrc_reloc {
    DWORD جابه_جایی;
    DWORD اندازه;
    کلمه_3 type;
};
#رهنمود pack(برداشت)

/* ------------------------------------------------------------- */
/* internal temporary structures */

تعداد {
    sec_متن = 0,
    sec_rdata ,
    sec_داده ,
    sec_bss ,
    sec_idata ,
    sec_pdata ,
    sec_tdata ,
    sec_tbss ,
    sec_other ,
    sec_rsrc ,
    sec_debug ,
    sec_reloc ,
    sec_آخرین
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
#پایان_اگر

بنية section_info {
    صحيح cls;
    حرف name[32];
    ADDR3264 sh_addr;
    DWORD sh_اندازه;
    DWORD pe_flags;
    Section *sec;
    DWORD داده_اندازه;
    IMAGE_SECTION_سرآیند_2 ish;
};

بنية import_نماد {
    صحيح sym_شاخص;
    صحيح iat_شاخص;
    صحيح thk_جابه_جایی;
};

بنية pe_import_info {
    صحيح dll_شاخص;
    صحيح sym_شمار;
    بنية import_نماد **symbols;
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
    ثابت حرف *شروع_نماد;
    DWORD شروع_addr;
    DWORD imp_offs;
    DWORD imp_اندازه;
    DWORD iat_offs;
    DWORD iat_اندازه;
    DWORD exp_offs;
    DWORD exp_اندازه;
    DWORD tls_dir;
    DWORD tls_داده;
    DWORD tls_اندازه;
    صحيح subsystem;
    DWORD section_align;
    DWORD file_align;
    بنية section_info **sec_info;
    صحيح sec_شمار;
    بنية pe_import_info **imp_info;
    صحيح imp_شمار;
    /* output */
    FILE *op;
    DWORD جمع;
    بیعلامت pos;
};

#تعریف_کن PE_NUL 0
#تعریف_کن PE_DLL 1
#تعریف_کن PE_GUI 2
#تعریف_کن PE_EXE 3
#تعریف_کن PE_پیاپی 4

/* --------------------------------------------*/

ساكن ثابت حرف *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    ثابت حرف *name = (حرف*)symtab_section->link->داده + sym->st_name;
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
    صحيح i = s->داده_جابه_جایی & (a-1);
    إذا (i)
        section_ptr_جمع_کن(s, a - i);
}

ساكن فراغ pe_مجموعه_datadir(بنية pe_سرآیند *hdr, صحيح dir, DWORD addr, DWORD اندازه)
{
    hdr->opthdr.داده_Directory[dir].Virtual_آدرس = addr;
    hdr->opthdr.داده_Directory[dir].اندازه_3 = اندازه;
}

ساكن صحيح pe_fwrite(بنية pe_info *pe, ثابت فراغ *داده, صحيح len)
{
    ثابت کلمه_3 *p = داده;
    DWORD جمع;
    صحيح ret, i;
    pe->pos += (ret = fwrite(داده, 1, len, pe->op));
    جمع = pe->جمع;
    لكل (i = len; i > 0; i -= 2) {
        جمع += (i >= 2) ? *p++ : *(BYTE*)p;
        جمع = (جمع + (جمع >> 16)) & 0xFFFF;
    }
    pe->جمع = جمع;
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

#رهنمود pack(افزودن, 1)
بنية syment
{
    اتحاد {
        حرف        n_name[8];     /* old COFF version */
        بنية {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_جابه_جایی_2;      /* offset into string table */
        };
    };
    int32_t         n_مقدار;        /* value of symbol */
    کوتاه           n_scnum;        /* section number */
    بیعلامت کوتاه  n_type;         /* type and derived type */
    حرف            n_sclass;       /* storage class */
    حرف            n_numaux;       /* number of aux. entries */
};
#رهنمود pack(برداشت)

#تعریف_کن SHF_خصوصی 0x80000000

ساكن فراغ pe_جمع_کن_coffsym(بنية pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    بنية syment *se;
    صحيح n;

    إذا (عدم == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_خصوصی);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_خصوصی);
        section_ptr_جمع_کن(pe->coffstr, 4); /* coff string table size */
        أرجع;
    }

#إذا 0
    se = section_ptr_جمع_کن(pe->coffsym, حجم *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_جمع_کن(pe->coffsym, حجم *se);
    strcpy((حرف*)se, "no-file");
#پایان_اگر

#إذا 1
    esym = (ElfSym*)s1->symtab->داده;
    لكل (n = s1->symtab->داده_جابه_جایی / حجم *esym; ++esym, --n;) {
        صحيح sym_bind = ELFW(ST_BIND)(esym->st_info);
        إذا (sym_bind == STB_GLOBAL) {
            حرف *name = esym->st_name + (حرف*)s1->symtab->link->داده;
            صحيح nl = طول_رشته(name);
            addr_t مقدار = esym->st_مقدار;
            صحيح shnum = esym->st_shndx;
            إذا (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                مقدار = مقدار - s->sh_addr;
            }
            se = section_ptr_جمع_کن(pe->coffsym, حجم *se);
            se->n_مقدار = مقدار;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            إذا (nl <= 8)
                کپی_حافظه(se->n_name, name, nl);
            وإلا
                se->n_جابه_جایی_2 = put_elf_str(pe->coffstr, name);
        }
    }
#پایان_اگر
    write32le(pe->coffstr->داده, pe->coffstr->داده_جابه_جایی); /* coff string table size */
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
        چاپ_کن("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
ساكن صحيح pe_write(بنية pe_info *pe)
{
    ساكن ثابت بنية pe_سرآیند pe_template = {
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
#پایان_اگر
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

    بنية pe_سرآیند pe_سرآیند = pe_template;

    صحيح i;
    DWORD file_جابه_جایی;
    بنية section_info *si;
    IMAGE_SECTION_سرآیند_2 *psh;
    TCCState *s1 = pe->s1;

    إذا (s1->do_debug)
        pe_جمع_کن_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    إذا (عدم == pe->op)
        أرجع tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        حجم (بنية pe_سرآیند)
        + pe->sec_شمار * حجم (IMAGE_SECTION_سرآیند_2)
        );

    file_جابه_جایی = pe->sizeofheaders;

    إذا (2 == s1->verbose)
        چاپ_کن("-------------------------------"
               "\n  virt   file   size  section" "\n");
    لكل (i = 0; i < pe->sec_شمار; ++i) {
        DWORD addr, اندازه;
        ثابت حرف *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        اندازه = si->sh_اندازه;
        psh = &si->ish;

        إذا (2 == s1->verbose)
            چاپ_کن("%6x %6x %6x  %s\n",
                (بیعلامت)addr, (بیعلامت)file_جابه_جایی, (بیعلامت)اندازه, sh_name);

        بدل (si->cls) {
            حالة sec_متن:
                إذا (!pe_سرآیند.opthdr.پایه_از_کد)
                    pe_سرآیند.opthdr.پایه_از_کد = addr;
                اكسر;

            حالة sec_داده:
#إذا PTR_اندازه == 4
                إذا (!pe_سرآیند.opthdr.پایه_از_داده)
                    pe_سرآیند.opthdr.پایه_از_داده = addr;
#پایان_اگر
                اكسر;

            حالة sec_bss:
                اكسر;

            حالة sec_reloc:
                pe_مجموعه_datadir(&pe_سرآیند, IMAGE_DIRECTORY_مدخل_BASERELOC, addr, اندازه);
                اكسر;

            حالة sec_rsrc:
                pe_مجموعه_datadir(&pe_سرآیند, IMAGE_DIRECTORY_مدخل_RESOURCE, addr, اندازه);
                اكسر;

            حالة sec_pdata:
                pe_مجموعه_datadir(&pe_سرآیند, IMAGE_DIRECTORY_مدخل_EXCEPTION, addr, اندازه);
                اكسر;
        }

        إذا (pe->imp_اندازه) {
            pe_مجموعه_datadir(&pe_سرآیند, IMAGE_DIRECTORY_مدخل_IMPORT,
                pe->imp_offs, pe->imp_اندازه);
            pe_مجموعه_datadir(&pe_سرآیند, IMAGE_DIRECTORY_مدخل_IAT,
                pe->iat_offs, pe->iat_اندازه);
        }
        إذا (pe->exp_اندازه) {
            pe_مجموعه_datadir(&pe_سرآیند, IMAGE_DIRECTORY_مدخل_EXPORT,
                pe->exp_offs, pe->exp_اندازه);
        }
        إذا (pe->tls_اندازه) {
            pe_مجموعه_datadir(&pe_سرآیند, IMAGE_DIRECTORY_مدخل_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_اندازه);
        }

        کپی_حافظه(psh->Name, sh_name, umin(طول_رشته(sh_name), حجم psh->Name));
        إذا (pe->coffstr && طول_رشته(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((حرف*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->Virtual_آدرس = addr;
        psh->Misc.Virtual_اندازه = اندازه;
        pe_سرآیند.opthdr.اندازه_از_Image =
            umax(pe_virtual_align(pe, اندازه + addr), pe_سرآیند.opthdr.اندازه_از_Image);

        إذا (si->داده_اندازه) {
            psh->اشاره_گر_مقصد_Raw_داده = file_جابه_جایی;
            file_جابه_جایی = pe_file_align(pe, file_جابه_جایی + si->داده_اندازه);
            psh->اندازه_از_Raw_داده = file_جابه_جایی - psh->اشاره_گر_مقصد_Raw_داده;
            إذا (si->cls == sec_متن)
                pe_سرآیند.opthdr.اندازه_از_کد += psh->اندازه_از_Raw_داده;
            وإلا
                pe_سرآیند.opthdr.اندازه_از_Initialized_داده += psh->اندازه_از_Raw_داده;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_سرآیند.filehdr.عدد_از_Sections = pe->sec_شمار;
    pe_سرآیند.opthdr.آدرس_از_مدخل_نقطه = pe->شروع_addr;
    pe_سرآیند.opthdr.اندازه_از_سرآیندها = pe->sizeofheaders;
    pe_سرآیند.opthdr.Image_پایه = pe->imagebase;
    pe_سرآیند.opthdr.Subsystem = pe->subsystem;
    pe_سرآیند.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    إذا (s1->pe_پشته_اندازه)
        pe_سرآیند.opthdr.اندازه_از_پشته_Reserve = s1->pe_پشته_اندازه;
    إذا (PE_DLL == pe->type)
        pe_سرآیند.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_سرآیند.filehdr.Characteristics |= s1->pe_characteristics;
    إذا (pe->reloc)
        pe_سرآیند.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    إذا (pe->coffsym) {
        pe_جمع_کن_coffsym(pe);
        pe_سرآیند.filehdr.اشاره_گر_مقصد_نماد_جدول = file_جابه_جایی;
        pe_سرآیند.filehdr.عدد_از_Symbols
            = pe->coffsym->داده_جابه_جایی / حجم (بنية syment);
    }

    pe_fwrite(pe, &pe_سرآیند, حجم pe_سرآیند);
    لكل (i = 0; i < pe->sec_شمار; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, حجم(IMAGE_SECTION_سرآیند_2));

    file_جابه_جایی = pe->sizeofheaders;
    لكل (i = 0; i < pe->sec_شمار; ++i) {
        Section *s;
        si = pe->sec_info[i];
        إذا (!si->داده_اندازه)
            استمر;
        لكل (s = si->sec; s; s = s->prev) {
            pe_fpad(pe, file_جابه_جایی);
            pe_fwrite(pe, s->داده, s->داده_جابه_جایی);
            إذا (s->prev)
                file_جابه_جایی += s->prev->sh_addr - s->sh_addr;
        }
        file_جابه_جایی = si->ish.اشاره_گر_مقصد_Raw_داده + si->ish.اندازه_از_Raw_داده;
        pe_fpad(pe, file_جابه_جایی);
    }

    إذا (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->داده, pe->coffsym->داده_جابه_جایی);
        pe_fwrite(pe, pe->coffstr->داده, pe->coffstr->داده_جابه_جایی);
        file_جابه_جایی = pe->pos;
    }

    pe->جمع += file_جابه_جایی;
    fseek(pe->op, offsetof(بنية pe_سرآیند, opthdr.Check_جمع), SEEK_SET);
    pe_fwrite(pe, &pe->جمع, حجم (DWORD));

    fclose (pe->op);
#اگر_تعریف_نشده _WIN32
    chmod(pe->filename, 0777);
#پایان_اگر

    إذا (2 == s1->verbose)
        چاپ_کن("-------------------------------\n");
    إذا (s1->verbose)
        چاپ_کن("<- %s (%u bytes)\n", pe->filename, (بیعلامت)file_جابه_جایی);

    إذا (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    أرجع 0;
}

/*----------------------------------------------------------------------------*/

ساكن بنية import_نماد *pe_جمع_کن_import(بنية pe_info *pe, صحيح sym_شاخص)
{
    صحيح i;
    صحيح dll_شاخص;
    بنية pe_import_info *p;
    بنية import_نماد *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->داده + sym_شاخص;
    dll_شاخص = isym->st_اندازه;

    i = dynarray_assoc ((فراغ**)pe->imp_info, pe->imp_شمار, dll_شاخص);
    إذا (-1 != i) {
        p = pe->imp_info[i];
        اذهب یافت_dll;
    }
    p = tcc_mallocz(حجم *p);
    p->dll_شاخص = dll_شاخص;
    dynarray_جمع_کن(&pe->imp_info, &pe->imp_شمار, p);

یافت_dll:
    i = dynarray_assoc ((فراغ**)p->symbols, p->sym_شمار, sym_شاخص);
    إذا (-1 != i)
        أرجع p->symbols[i];

    s = tcc_mallocz(حجم *s);
    dynarray_جمع_کن(&p->symbols, &p->sym_شمار, s);
    s->sym_شاخص = sym_شاخص;
    أرجع s;
}

ساكن فراغ pe_free_imports(بنية pe_info *pe)
{
    صحيح i;
    لكل (i = 0; i < pe->imp_شمار; ++i) {
        بنية pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_شمار);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_شمار);
}

/*----------------------------------------------------------------------------*/
ساكن فراغ pe_build_imports(بنية pe_info *pe)
{
    صحيح thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_پایه = pe->thunk->sh_addr - pe->imagebase;
    صحيح ndlls = pe->imp_شمار;
    TCCState *s1 = pe->s1;

    لكل (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_شمار;

    إذا (0 == sym_cnt)
        أرجع;

    pe_align_section(pe->thunk, 16);
    pe->imp_اندازه = (ndlls + 1) * حجم(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_اندازه = (sym_cnt + ndlls) * حجم(ADDR3264);
    dll_ptr = pe->thunk->داده_جابه_جایی;
    thk_ptr = dll_ptr + pe->imp_اندازه;
    ent_ptr = thk_ptr + pe->iat_اندازه;
    pe->imp_offs = dll_ptr + rva_پایه;
    pe->iat_offs = thk_ptr + rva_پایه;
    section_ptr_جمع_کن(pe->thunk, pe->imp_اندازه + 2*pe->iat_اندازه);

    لكل (i = 0; i < pe->imp_شمار; ++i) {
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
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->داده + dll_ptr);
        hdr->اولی_Thunk = thk_ptr + rva_پایه;
        hdr->Original_اولی_Thunk = ent_ptr + rva_پایه;
        hdr->Name = v + rva_پایه;

        لكل (k = 0, n = p->sym_شمار; k <= n; ++k) {
            إذا (k < n) {
                صحيح iat_شاخص = p->symbols[k]->iat_شاخص;
                صحيح sym_شاخص = p->symbols[k]->sym_شاخص;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->داده + sym_شاخص;
                ثابت حرف *name = (حرف*)s1->dynsymtab_section->link->داده + imp_sym->st_name;
                صحيح ordinal;

                /* patch symbol (and possibly its underscored alias) */
                افعل {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->داده + iat_شاخص;
                    iat_شاخص = esym->st_مقدار;
                    esym->st_مقدار = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_رقم;
                } طالما (iat_شاخص);

                إذا (dllref)
                    v = 0, ordinal = imp_sym->st_مقدار; /* ordinal from pe_load_def */
                وإلا
                    ordinal = 0, v = imp_sym->st_مقدار; /* address from tcc_add_symbol() */

#اگر_تعریف_شده TCC_IS_NATIVE
                إذا (pe->type == PE_پیاپی) {
                    إذا (dllref) {
                        إذا ( !dllref->handle )
                            dllref->handle = بارگیری_Library_A(dllref->name);
                        v = (ADDR3264)Get_Proc_آدرس(dllref->handle, ordinal?(حرف*)0+ordinal:name);
                    }
                    إذا (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } وإلا
#پایان_اگر
                إذا (ordinal) {
                    v = ordinal | (ADDR3264)1 << (حجم(ADDR3264)*8 - 1);
                } وإلا {
                    v = pe->thunk->داده_جابه_جایی + rva_پایه;
                    section_ptr_جمع_کن(pe->thunk, حجم(کلمه_3)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } وإلا {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->داده+thk_ptr) =
            *(ADDR3264*)(pe->thunk->داده+ent_ptr) = v;
            thk_ptr += حجم (ADDR3264);
            ent_ptr += حجم (ADDR3264);
        }
        dll_ptr += حجم(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

بنية pe_مرتب_سازی_sym
{
    صحيح شاخص;
    ثابت حرف *name;
};

ساكن صحيح sym_cmp(ثابت فراغ *va, ثابت فراغ *vb)
{
    ثابت حرف *ca = (*(بنية pe_مرتب_سازی_sym**)va)->name;
    ثابت حرف *cb = (*(بنية pe_مرتب_سازی_sym**)vb)->name;
    أرجع strcmp(ca, cb);
}

ساكن فراغ pe_build_exports(بنية pe_info *pe)
{
    ElfW(Sym) *sym;
    صحيح sym_شاخص, sym_انتها;
    DWORD rva_پایه, پایه_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    صحيح sym_شمار, ord;
    بنية pe_مرتب_سازی_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    حرف buf[260];
    ثابت حرف *dllname;
    ثابت حرف *name;

    rva_پایه = pe->thunk->sh_addr - pe->imagebase;
    sym_شمار = 0, sorted = عدم, op = عدم;

    sym_انتها = symtab_section->داده_جابه_جایی / حجم(ElfW(Sym));
    لكل (sym_شاخص = 1; sym_شاخص < sym_انتها; ++sym_شاخص) {
        sym = (ElfW(Sym)*)symtab_section->داده + sym_شاخص;
        name = pe_export_name(s1, sym);
        إذا (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(حجم *p);
            p->شاخص = sym_شاخص;
            p->name = name;
            dynarray_جمع_کن(&sorted, &sym_شمار, p);
        }
#إذا 0
        إذا (sym->st_other & ST_PE_EXPORT)
            چاپ_کن("export: %s\n", name);
        إذا (sym->st_other & ST_PE_STDCALL)
            چاپ_کن("stdcall: %s\n", name);
#پایان_اگر
    }

    إذا (0 == sym_شمار)
        أرجع;

    qsort (sorted, sym_شمار, حجم *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    پایه_o = pe->thunk->داده_جابه_جایی;
    func_o = پایه_o + حجم(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_شمار * حجم (DWORD);
    ord_o = name_o + sym_شمار * حجم (DWORD);
    str_o = ord_o + sym_شمار * حجم(کلمه_3);

    hdr = section_ptr_جمع_کن(pe->thunk, str_o - پایه_o);
    hdr->Characteristics        = 0;
    hdr->پایه_2                   = 1;
    hdr->عدد_از_Functions      = sym_شمار;
    hdr->عدد_از_نامها          = sym_شمار;
    hdr->آدرس_از_Functions     = func_o + rva_پایه;
    hdr->آدرس_از_نامها         = name_o + rva_پایه;
    hdr->آدرس_از_Name_Ordinals  = ord_o + rva_پایه;
    hdr->Name                   = str_o + rva_پایه;
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
            چاپ_کن("<- %s (%d symbol%s)\n", buf, sym_شمار, &"s"[sym_شمار < 2]);
    }
#پایان_اگر

    لكل (ord = 0; ord < sym_شمار; ++ord)
    {
        p = sorted[ord], sym_شاخص = p->شاخص, name = p->name;
        /* insert actual address later in relocate_sections() */
        put_elf_reloc(symtab_section, pe->thunk,
            func_o, R_XXX_RELATIVE, sym_شاخص);
        *(DWORD*)(pe->thunk->داده + name_o)
            = pe->thunk->داده_جابه_جایی + rva_پایه;
        *(کلمه_3*)(pe->thunk->داده + ord_o)
            = ord;
        put_elf_str(pe->thunk, name);
        func_o += حجم (DWORD);
        name_o += حجم (DWORD);
        ord_o += حجم (کلمه_3);
        إذا (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = پایه_o + rva_پایه;
    pe->exp_اندازه = pe->thunk->داده_جابه_جایی - پایه_o;
    dynarray_reset(&sorted, &sym_شمار);
    إذا (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
ساكن فراغ pe_build_reloc (بنية pe_info *pe)
{
    DWORD جابه_جایی, بلوک_ptr, sh_addr, addr;
    صحيح شمار_2, i;
    ElfW_Rel *rel, *rel_انتها;
    Section *s = عدم, *sr;
    بنية pe_reloc_سرآیند *hdr;
    TCCState *s1 = pe->s1;
    صحيح dwarf = 0, n;

    sh_addr = جابه_جایی = بلوک_ptr = شمار_2 = i = 0;
    rel = rel_انتها = عدم;

    لكل(;;) {
        إذا (rel < rel_انتها) {
            صحيح type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_جابه_جایی + sh_addr;
            ++ rel;
            إذا (type != REL_TYPE_مستقیم)
                استمر;
            إذا (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->داده + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                إذا (n >= s1->dwlo && n < s1->dwhi)
                    استمر;
            }
            إذا (شمار_2 == 0) { /* new block */
                بلوک_ptr = pe->reloc->داده_جابه_جایی;
                section_ptr_جمع_کن(pe->reloc, حجم(بنية pe_reloc_سرآیند));
                جابه_جایی = addr & 0xFFFFFFFF<<12;
            }
            إذا ((addr -= جابه_جایی)  < (1<<12)) { /* one block spans 4k addresses */
                کلمه_3 *wp = section_ptr_جمع_کن(pe->reloc, حجم (کلمه_3));
                *wp = addr | PE_IMAGE_REL<<12;
                ++شمار_2;
                استمر;
            }
            -- rel;

        } وإلا إذا (s) {
            sr = s->reloc;
            إذا (sr) {
                rel = (ElfW_Rel *)sr->داده;
                rel_انتها = (ElfW_Rel *)(sr->داده + sr->داده_جابه_جایی);
                sh_addr = s->sh_addr;
                dwarf = s->sh_رقم >= s1->dwlo && s->sh_رقم < s1->dwhi;
            }
            s = s->prev;
            استمر;

        } وإلا إذا (i < pe->sec_شمار) {
            s = pe->sec_info[i]->sec, ++i;
            استمر;

        } وإلا إذا (!شمار_2)
            اكسر;

        /* fill the last block and ready for a new one */
        إذا (شمار_2 & 1) /* align for DWORDS */
            section_ptr_جمع_کن(pe->reloc, حجم(کلمه_3)), ++شمار_2;
        hdr = (بنية pe_reloc_سرآیند *)(pe->reloc->داده + بلوک_ptr);
        hdr -> جابه_جایی = جابه_جایی - pe->imagebase;
        hdr -> اندازه = شمار_2 * حجم(کلمه_3) + حجم(بنية pe_reloc_سرآیند);
        شمار_2 = 0;
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
        pe->tls_dir = section_جمع_کن(pe->thunk, pe->tls_اندازه, 16);
        pe->tls_داده = section_جمع_کن(داده_section, PTR_اندازه * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, داده_section->sh_رقم, 0);
        لكل (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_اندازه*n, REL_TYPE_مستقیم, c);
        /* for generators */
        مجموعه_elf_sym(symtab_section, pe->tls_داده, PTR_اندازه * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, داده_section->sh_رقم, "__tls_index");
        أرجع;
    }

    إذا (0 == s1->tls_شروع)
        s1->tls_شروع = s->sh_addr;
    d = (فراغ*)(pe->thunk->داده + pe->tls_dir);
    d->شروع_آدرس_از_Raw_داده = s1->tls_شروع - داده_section->sh_addr;
    d->انتها_آدرس_از_Raw_داده = s->sh_addr + s->داده_جابه_جایی - داده_section->sh_addr;
    d->آدرس_از_شاخص = pe->tls_داده;
    d->آدرس_از_Call_Backs = pe->tls_داده + PTR_اندازه;
    d->اندازه_از_Zero_Fill = 0;
    d->Characteristics = 0;
    /* to reuse logic from linux in xxx-link.c */
    s1->tls_انتها = s1->tls_شروع;
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
                أرجع sec_داده;
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
    أرجع sec_آخرین;
}

ساكن صحيح pe_تخصیص_بده_آدرسها (بنية pe_info *pe)
{
    صحيح i, k, n, c, nbs;
    ADDR3264 addr;
    صحيح *sec_ترتیب, *sec_cls;
    بنية section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    إذا (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_پایه))
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
    لكل (i = 1; (c = sec_cls[i]) < sec_آخرین; ++i) {
        s = s1->sections[sec_ترتیب[i]];

        إذا (PE_ادغام_داده && c == sec_bss)
            c = sec_داده;
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

        إذا (0 == s->داده_جابه_جایی)
            استمر;

        إذا (si)
            اذهب جمع_کن_section;

        si = tcc_mallocz(حجم *si);
        dynarray_جمع_کن(&pe->sec_info, &pe->sec_شمار, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        إذا (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_کد;
        وإلا إذا (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_داده;
        وإلا
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_داده;
        إذا (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        إذا (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

جمع_کن_section:
        s->sh_info = pe->sec_شمار; /* section number for coff syms */
        addr += s->داده_جابه_جایی;
        si->sh_اندازه = addr - si->sh_addr;
        إذا (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            طالما (*ps)
                ps = &(*ps)->prev;
            *ps = s, s->prev = عدم;
            si->داده_اندازه = si->sh_اندازه;
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
        چاپ_کن("section %-16s %-10s %p %04x %2d %s,%s,%s\n",
            s->name,
            type == SHT_PROGBITS ? "progbits" :
            type == SHT_INIT_ARRAY ? "initarr" :
            type == SHT_FINI_ARRAY ? "finiarr" :
            type == SHT_NOBITS ? "nobits" :
            type == SHT_SYMTAB ? "symtab" :
            type == SHT_STRTAB ? "strtab" :
            type == SHT_RELX ? "rel" : "???",
            s->sh_addr,
            (بیعلامت)s->داده_جابه_جایی,
            s->sh_addralign,
            flags & SHF_ALLOC ? "alloc" : "",
            flags & SHF_WRITE ? "write" : "",
            flags & SHF_EXECINSTR ? "exec" : ""
            );
        fflush(stdout);
    }
    s1->verbose = 2;
#پایان_اگر
    tcc_free(sec_ترتیب);
    أرجع 0;
}

/*----------------------------------------------------------------------------*/
ساكن صحيح pe_check_symbols(بنية pe_info *pe)
{
    صحيح sym_شاخص, sym_انتها;
    صحيح ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(متن_section, 8);

    sym_انتها = symtab_section->داده_جابه_جایی / حجم(ElfW(Sym));
    لكل (sym_شاخص = 1; sym_شاخص < sym_انتها; ++sym_شاخص) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->داده + sym_شاخص;
        إذا (sym->st_shndx == SHN_UNDEF) {
            ثابت حرف *name = (حرف*)symtab_section->link->داده + sym->st_name;
            بیعلامت type = ELFW(ST_TYPE)(sym->st_info);
            صحيح imp_sym = 0;
            بنية import_نماد *is;

            صحيح _imp_, n;
            حرف میانگیر[200];
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
                        strcpy(میانگیر, s+1)[p-s-1] = 0, s = میانگیر;
                    } وإلا إذا (s[0] != '_') { /* try non-ansi function */
                        میانگیر[0] = '_', strcpy(میانگیر + 1, s), s = میانگیر;
                    } وإلا إذا (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } وإلا إذا (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } وإلا {
                        اكسر;
                    }
                }
                imp_sym = پیدا_کن_elf_sym(s1->dynsymtab_section, s);
            } طالما (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            إذا (0 == imp_sym)
                استمر; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_جمع_کن_import(pe, imp_sym);

            إذا (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                بیعلامت جابه_جایی = is->thk_جابه_جایی;
                إذا (جابه_جایی) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } وإلا {
                    بیعلامت حرف *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(میانگیر, "IAT.%s", name);
                    is->iat_شاخص = put_elf_sym(
                        symtab_section, 0, حجم(DWORD),
                        ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT),
                        0, SHN_UNDEF, میانگیر);

                    جابه_جایی = متن_section->داده_جابه_جایی;
                    is->thk_جابه_جایی = جابه_جایی;

                    /* add the 'jmp IAT[x]' instruction */
#اگر_تعریف_شده TCC_هدف_ARM
                    p = section_ptr_جمع_کن(متن_section, 8+4); // room for code and address
                    write32le(p + 0, 0xE59FC000); // arm code ldr ip, [pc] ; PC+8+0 = 0001xxxx
                    write32le(p + 4, 0xE59CF000); // arm code ldr pc, [ip]
                    put_elf_reloc(symtab_section, متن_section,
                        جابه_جایی + 8, R_XXX_THUNKFIX, is->iat_شاخص); // offset to IAT position
#وإلاإذا defined(TCC_هدف_ARM64)
                    p = section_ptr_جمع_کن(متن_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, متن_section,
                        جابه_جایی + 16, R_XXX_THUNKFIX, is->iat_شاخص);
#وإلا
                    p = section_ptr_جمع_کن(متن_section, 8);
                    write16le(p, 0x25FF);
#اگر_تعریف_شده TCC_هدف_X86_64
                    write32le(p + 2, (DWORD)-4);
#پایان_اگر
                    put_elf_reloc(symtab_section, متن_section, 
                        جابه_جایی + 2, R_XXX_THUNKFIX, is->iat_شاخص);
#پایان_اگر
                }
                /* tcc_realloc might have altered sym's address */
                sym = (ElfW(Sym) *)symtab_section->داده + sym_شاخص;
                /* patch the original symbol */
                sym->st_مقدار = جابه_جایی;
                sym->st_shndx = متن_section->sh_رقم;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } وإلا { /* STT_OBJECT */
                إذا (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_مقدار = is->iat_شاخص; /* chain potential alias */
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
    p = s->داده;
    e = s->داده + s->داده_جابه_جایی;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    إذا (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    إذا (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (بیعلامت)s->sh_addr);
    fprintf(f, "\ncontents %08X", (بیعلامت)l);
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
            ثابت حرف *name = s->link->داده + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (بیعلامت)sym->st_name,
                    (بیعلامت)sym->st_مقدار,
                    (بیعلامت)sym->st_اندازه,
                    (بیعلامت)ELFW(ST_BIND)(sym->st_info),
                    (بیعلامت)ELFW(ST_TYPE)(sym->st_info),
                    (بیعلامت)sym->st_other,
                    (بیعلامت)sym->st_shndx,
                    name);

        } وإلا إذا (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->داده + ELFW(R_SYM)(rel->r_info);
            ثابت حرف *name = s->link->link->داده + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (بیعلامت)rel->r_جابه_جایی,
                    (بیعلامت)ELFW(R_TYPE)(rel->r_info),
                    (بیعلامت)ELFW(R_SYM)(rel->r_info),
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
#پایان_اگر

/* ------------------------------------------------------------- */

ST_FUNC صحيح pe_putimport(TCCState *s1, صحيح dllindex, ثابت حرف *name, addr_t مقدار)
{
    أرجع مجموعه_elf_sym(
        s1->dynsymtab_section,
        مقدار,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        مقدار ? SHN_ABS : SHN_UNDEF,
        name
        );
}

ساكن صحيح read_mem(صحيح fd, بیعلامت جابه_جایی, فراغ *میانگیر, بیعلامت len)
{
    lseek(fd, جابه_جایی, SEEK_SET);
    أرجع len == اقرأ(fd, میانگیر, len);
}

/* ------------------------------------------------------------- */

ساكن صحيح get_dllexports(صحيح fd, حرف **pp)
{
    صحيح i, k, l, n, n0, ret;
    حرف *p;

    IMAGE_SECTION_سرآیند_2 ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_سرآیند_2 dh;
    IMAGE_FILE_سرآیند_2 ih;
    DWORD sig, ref, addr;
    DWORD *namep = عدم, p0 = 0, p1;

    صحيح pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = عدم;
    ret = 1;
    إذا (!read_mem(fd, 0, &dh, حجم dh))
        اذهب the_انتها;
    إذا (!read_mem(fd, dh.e_lfanew, &sig, حجم sig))
        اذهب the_انتها;
    إذا (sig != 0x00004550)
        اذهب the_انتها;
    pef_hdroffset = dh.e_lfanew + حجم sig;
    إذا (!read_mem(fd, pef_hdroffset, &ih, حجم ih))
        اذهب the_انتها;
    opt_hdroffset = pef_hdroffset + حجم ih;
    إذا (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + حجم oh;
        إذا (!read_mem(fd, opt_hdroffset, &oh, حجم oh))
            اذهب the_انتها;
        إذا (IMAGE_DIRECTORY_مدخل_EXPORT >= oh.عدد_از_Rva_And_Sizes)
            اذهب the_انتها_0;
        addr = oh.داده_Directory[IMAGE_DIRECTORY_مدخل_EXPORT].Virtual_آدرس;
    } وإلا إذا (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + حجم oh;
        إذا (!read_mem(fd, opt_hdroffset, &oh, حجم oh))
            اذهب the_انتها;
        إذا (IMAGE_DIRECTORY_مدخل_EXPORT >= oh.عدد_از_Rva_And_Sizes)
            اذهب the_انتها_0;
        addr = oh.داده_Directory[IMAGE_DIRECTORY_مدخل_EXPORT].Virtual_آدرس;
    } وإلا
        اذهب the_انتها;

    //printf("addr: %08x\n", addr);
    لكل (i = 0; i < ih.عدد_از_Sections; ++i) {
        إذا (!read_mem(fd, sec_hdroffset + i * حجم ish, &ish, حجم ish))
            اذهب the_انتها;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        إذا (addr >= ish.Virtual_آدرس && addr < ish.Virtual_آدرس + ish.اندازه_از_Raw_داده)
            اذهب یافت;
    }
    اذهب the_انتها_0;
یافت:
    ref = ish.Virtual_آدرس - ish.اشاره_گر_مقصد_Raw_داده;
    إذا (!read_mem(fd, addr - ref, &ied, حجم ied))
        اذهب the_انتها;
    k = ied.عدد_از_نامها;
    إذا (k) {
        namep = tcc_malloc(l = k * حجم *namep);
        إذا (!read_mem(fd, ied.آدرس_از_نامها - ref, namep, l))
            اذهب the_انتها;
        لكل (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            إذا (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            افعل {
                إذا (0 == l) {
                    إذا (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    إذا ((l = اقرأ(fd, p + n, 1000 - 1)) <= 0)
                        اذهب the_انتها;
                }
                --l, ++p0;
            } طالما (p[n++]);
        }
        p[n] = 0;
    }
the_انتها_0:
    ret = 0;
the_انتها:
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

ساكن صحيح pe_بارگیری_res(TCCState *s1, صحيح fd)
{
    بنية pe_rsrc_سرآیند hdr;
    Section *rsrc_section;
    صحيح i, ret = -1, sym_شاخص;
    BYTE *ptr;
    بیعلامت offs;

    إذا (!read_mem(fd, 0, &hdr, حجم hdr))
        اذهب quit;

    إذا (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.عدد_از_Sections != 1
        || strcmp((حرف*)hdr.sectionhdr.Name, ".rsrc") != 0)
        اذهب quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_جمع_کن(rsrc_section, hdr.sectionhdr.اندازه_از_Raw_داده);
    offs = hdr.sectionhdr.اشاره_گر_مقصد_Raw_داده;
    إذا (!read_mem(fd, offs, ptr, hdr.sectionhdr.اندازه_از_Raw_داده))
        اذهب quit;
    offs = hdr.sectionhdr.اشاره_گر_مقصد_Relocations;
    sym_شاخص = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_رقم, ".rsrc");
    لكل (i = 0; i < hdr.sectionhdr.عدد_از_Relocations; ++i) {
        بنية pe_rsrc_reloc rel;
        إذا (!read_mem(fd, offs, &rel, حجم rel))
            اذهب quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        إذا (rel.type != RSRC_RELTYPE)
            اذهب quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.جابه_جایی, R_XXX_RELATIVE, sym_شاخص);
        offs += حجم rel;
    }
    ret = 0;
quit:
    أرجع ret;
}

/* ------------------------------------------------------------- */

ساكن حرف *trimfront(حرف *p)
{
    طالما ((بیعلامت حرف)*p <= ' ' && *p && *p != '\n')
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
    لكل (e = p; (بیعلامت حرف)*e >= ' ' && *e != q; ++e)
        ;
    إذا (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    أرجع p;
}

ساكن صحيح pe_بارگیری_def(TCCState *s1, صحيح fd)
{
    صحيح state = 0, ret = -1, dllindex = 0, ord;
    حرف dllname[80], *buf, *سطر, *p, *x, بعدی;

    buf = tcc_بارگیری_متن(fd);
    إذا (!buf)
        أرجع ret;

    لكل (سطر = buf;; ++سطر)  {
        p = get_token(&سطر, &بعدی);
        إذا (!(*p && *p != ';'))
            اذهب skip;
        بدل (state) {
        حالة 0:
            إذا (0 != stricmp(p, "LIBRARY") || بعدی == '\n')
                اذهب quit;
            pstrcpy(dllname, حجم dllname, get_token(&سطر, &بعدی));
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
            dllindex = tcc_جمع_کن_dllref(s1, dllname, 0)->شاخص;
            ++state;
            /* fall through */
        افتراضي:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            إذا (بعدی == '@') {
                x = get_token(&سطر, &بعدی);
                ord = (صحيح)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            اكسر;
        }
skip:
        طالما ((بیعلامت حرف)بعدی > ' ')
            get_token(&سطر, &بعدی);
        إذا (بعدی != '\n')
            اكسر;
    }
    ret = 0;
quit:
    tcc_free(buf);
    أرجع ret;
}

/* ------------------------------------------------------------- */

ساكن صحيح pe_بارگیری_dll(TCCState *s1, صحيح fd, ثابت حرف *filename)
{
    حرف *p, *q;
    DLLReference *ref = tcc_جمع_کن_dllref(s1, filename, 0);
    إذا (ref->یافت)
        أرجع 0;
    إذا (get_dllexports(fd, &p))
        أرجع -1;
    إذا (p) {
        لكل (q = p; *q; q += 1 + طول_رشته(q))
            pe_putimport(s1, ref->شاخص, q, 0);
        tcc_free(p);
    }
    أرجع 0;
}

ST_FUNC صحيح pe_بارگیری_file(بنية TCCState *s1, صحيح fd, ثابت حرف *filename)
{
    صحيح ret = -1;
    حرف buf[10];
    إذا (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_بارگیری_def(s1, fd);
    وإلا إذا (pe_بارگیری_res(s1, fd) == 0)
        ret = 0;
    وإلا إذا (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_بارگیری_dll(s1, fd, filename);
    أرجع ret;
}

PUB_FUNC صحيح tcc_get_dllexports(ثابت حرف *filename, حرف **pp)
{
    صحيح ret, fd = open(filename, O_RDONLY | O_دودویی_2);
    إذا (fd < 0)
        أرجع -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    أرجع ret;
}

/* ------------------------------------------------------------- */
#اگر_تعریف_شده TCC_هدف_X86_64
ساكن بیعلامت pe_جمع_کن_unwind_info(TCCState *s1)
{
    إذا (عدم == s1->uw_pdata) {
        s1->uw_pdata = پیدا_کن_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    إذا (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, متن_section->sh_رقم, ".uw_base");
    إذا (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        ساكن ثابت بیعلامت حرف uw_info[] = {
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
        بیعلامت حرف *p;

        section_ptr_جمع_کن(s, -s->داده_جابه_جایی & 3); /* align */
        s1->uw_offs = s->داده_جابه_جایی;
        p = section_ptr_جمع_کن(s, حجم uw_info);
        کپی_حافظه(p, uw_info, حجم uw_info);
    }

    أرجع s1->uw_offs;
}

ST_FUNC فراغ pe_جمع_کن_unwind_داده(بیعلامت شروع, بیعلامت انتها, بیعلامت پشته)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    بیعلامت o, n, d;
    بنية /* _RUNTIME_FUNCTION */ {
      DWORD Begin_آدرس;
      DWORD انتها_آدرس;
      DWORD Unwind_داده;
    } *p;

    d = pe_جمع_کن_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->داده_جابه_جایی;
    p = section_ptr_جمع_کن(pd, حجم *p);

    /* record this function */
    p->Begin_آدرس = شروع;
    p->انتها_آدرس = انتها;
    p->Unwind_داده = d;

    /* put relocations on it */
    لكل (n = o + حجم *p; o < n; o += حجم p->Begin_آدرس)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#وإلاإذا defined(TCC_هدف_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
ساكن Section *pe_جمع_کن_unwind_info(TCCState *s1)
{
    Section *s;

    إذا (عدم == s1->uw_pdata) {
        s1->uw_pdata = پیدا_کن_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = پیدا_کن_section(s1, ".xdata");
    s->sh_addralign = 4;
    إذا (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  متن_section->sh_رقم, ".uw_text_base");
    إذا (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_رقم, ".uw_base");
    أرجع s;
}

ST_FUNC فراغ pe_جمع_کن_unwind_داده(بیعلامت شروع, بیعلامت انتها, بیعلامت پشته)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    بیعلامت o, d, کد_بایتها, func_len;
    بیعلامت حرف *q;
    uint32_t سرآیند;
    بنية /* _RUNTIME_FUNCTION */ {
        DWORD Begin_آدرس;
        DWORD Unwind_داده;
    } *p;

    صحيح epilog;

    xd = pe_جمع_کن_unwind_info(s1);
    pd = s1->uw_pdata;

    func_len = (انتها - شروع) >> 2;
    کد_بایتها = 0;
    epilog = کد_بایتها;
    کد_بایتها += 3; /* set_fp, save_fplr_x, end */
    کد_بایتها = (کد_بایتها + 3) & ~3;

    section_ptr_جمع_کن(xd, -xd->داده_جابه_جایی & 3);
    d = xd->داده_جابه_جایی;
    q = section_ptr_جمع_کن(xd, 4 + کد_بایتها);

    /* Full ARM64 xdata header: E=1 with one epilog and no exception handler. */
    سرآیند = (func_len & 0x3ffff)
        | 1 << 21
        | (epilog & 0x1F) << 22
        | (کد_بایتها >> 2) << 27
        ;
    write32le(q, سرآیند);
    q += 4;
    *q++ = 0xE1; /* set_fp */
    *q++ = 0x9B; /* save_fplr_x: stp x29,lr,[sp,#-224]! */
    *q++ = 0xE4; /*انتها*/
    طالما ((بیعلامت)(q - (xd->داده + d + 4)) < کد_بایتها)
        *q++ = 0xE3; /* nop padding */

    o = pd->داده_جابه_جایی;
    p = section_ptr_جمع_کن(pd, حجم *p);
    p->Begin_آدرس = شروع;
    p->Unwind_داده = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#پایان_اگر
/* ------------------------------------------------------------- */
#إذا defined(TCC_هدف_X86_64) || defined(TCC_هدف_ARM64)
#تعریف_کن PE_STDSYM(n,s) n
#وإلا
#تعریف_کن PE_STDSYM(n,s) "_" n s
#پایان_اگر

ساكن فراغ pe_جمع_کن_runtime(TCCState *s1, بنية pe_info *pe)
{
    ثابت حرف *شروع_نماد;
    صحيح pe_type;

    إذا (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        شروع_نماد = PE_STDSYM("__dllstart","@12");
    } وإلا {
        ثابت حرف *پیاپی_نماد;
        إذا (پیدا_کن_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            شروع_نماد = "__winstart";
            پیاپی_نماد = "__runwinmain";
            pe_type = PE_GUI;
        } وإلا إذا (پیدا_کن_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            شروع_نماد = "__wwinstart";
            پیاپی_نماد = "__runwwinmain";
            pe_type = PE_GUI;
        } وإلا إذا (پیدا_کن_elf_sym(symtab_section, "wmain")) {
            شروع_نماد = "__wstart";
            پیاپی_نماد = "__runwmain";
            pe_type = PE_EXE;
        } وإلا {
            شروع_نماد =  "__start";
            پیاپی_نماد = "__runmain";
            pe_type = PE_EXE;
            إذا (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        إذا (TCC_OUTPUT_حافظه == s1->output_type && !s1->nostdlib)
            شروع_نماد = پیاپی_نماد;
    }
    إذا (s1->elf_entryname) {
        pe->شروع_نماد = شروع_نماد = s1->elf_entryname;
    } وإلا {
        pe->شروع_نماد = شروع_نماد + 1;
        إذا (!s1->leading_underscore || strchr(شروع_نماد, '@'))
            ++شروع_نماد;
    }

#اگر_تعریف_شده CONFIG_TCC_BACKTRACE
    إذا (s1->do_backtrace) {
#اگر_تعریف_شده CONFIG_TCC_BCHECK
        إذا (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    إذا (s1->output_type == TCC_OUTPUT_حافظه)
                tcc_جمع_کن_support(s1, "bcheck_run.o");
	    وإلا
                tcc_جمع_کن_support(s1, "bcheck.o");
	}
#پایان_اگر
        إذا (s1->output_type == TCC_OUTPUT_EXE)
            tcc_جمع_کن_support(s1, "bt-exe.o");
        إذا (s1->output_type == TCC_OUTPUT_DLL)
            tcc_جمع_کن_support(s1, "bt-dll.o");
        إذا (s1->output_type != TCC_OUTPUT_DLL)
            tcc_جمع_کن_support(s1, "bt-log.o");
        tcc_جمع_کن_btstub(s1);
    }
#پایان_اگر

    /* grab the startup code from libtcc1.a */
#اگر_تعریف_شده TCC_IS_NATIVE
    إذا (TCC_OUTPUT_حافظه != s1->output_type || s1->پیاپی_main)
#پایان_اگر
    مجموعه_global_sym(s1, شروع_نماد, عدم, 0);

    إذا (0 == s1->nostdlib) {
        ساكن ثابت حرف * ثابت libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", عدم
        };
        ثابت حرف * ثابت *pp, *p;
        إذا (TCC_LIBTCC1[0])
            tcc_جمع_کن_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        لكل (pp = libs; 0 != (p = *pp); ++pp) {
            إذا (*p)
                tcc_جمع_کن_library(s1, p);
            وإلا إذا (PE_DLL != pe_type && PE_GUI != pe_type)
                اكسر;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    إذا (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    إذا (TCC_OUTPUT_حافظه == s1->output_type)
        pe_type = PE_پیاپی;
    pe->type = pe_type;
}

ST_FUNC صحيح pe_setsubsy(TCCState *s1, ثابت حرف *arg)
{
    ساكن ثابت بنية subsy { ثابت حرف* p; صحيح v; } x[] = {
#إذا defined(TCC_هدف_I386) || defined(TCC_هدف_X86_64) || defined(TCC_هدف_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#وإلاإذا defined(TCC_هدف_ARM)
        { "wince", 9 },
#پایان_اگر
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

ساكن فراغ pe_مجموعه_options(TCCState * s1, بنية pe_info *pe)
{
    إذا (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_پایه_DLL;
    } وإلا {
        pe->imagebase = IMAGE_پایه_EXE;
    }

#إذا defined(TCC_هدف_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#وإلا
    إذا (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    وإلا
        pe->subsystem = 3;
#پایان_اگر
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

#اگر_تعریف_شده CONFIG_TCC_BCHECK
    tcc_جمع_کن_bcheck(s1);
#پایان_اگر
    tcc_جمع_کن_pragma_libs(s1);
    pe_جمع_کن_runtime(s1, &pe);
    resolve_common_syms(s1);
    pe_مجموعه_options(s1, &pe);
    pe_check_symbols(&pe);
    إذا (s1->nb_errors)
        اذهب انجامشده;
    إذا (filename) {
        pe_تخصیص_بده_آدرسها(&pe);
        relocate_syms(s1, s1->symtab, 0);
        إذا (s1->nb_errors)
            اذهب انجامشده;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.شروع_addr = (DWORD)
            (get_sym_addr(s1, pe.شروع_نماد, 1, 1) - pe.imagebase);
        إذا (s1->nb_errors)
            اذهب انجامشده;
        pe_write(&pe);
    } وإلا {
        /* -run */
#اگر_تعریف_شده TCC_IS_NATIVE
        pe.thunk = داده_section;
        pe_build_imports(&pe);
        s1->پیاپی_main = pe.شروع_نماد;
#إذا defined(TCC_هدف_X86_64) || defined(TCC_هدف_ARM64)
        s1->uw_pdata = پیدا_کن_section(s1, ".pdata");
#پایان_اگر
#پایان_اگر
    }
انجامشده:
    dynarray_reset(&pe.sec_info, &pe.sec_شمار);
    pe_free_imports(&pe);
#إذا PE_PRINT_SECTIONS
    إذا (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#پایان_اگر
    أرجع s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
