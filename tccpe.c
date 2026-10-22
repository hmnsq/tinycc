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

#شامل "tcc.h"

#تعریف_کرو PE_ملاؤ_ڈیٹا 1
#تعریف_کرو PE_PRINT_SECTIONS 0

#اگر_غیر_تعریف_شدہ _WIN32
#تعریف_کرو stricmp strcasecmp
#تعریف_کرو strnicmp strncasecmp
#شامل <sys/stat.h> /* chmod() */
#اگر_ختم

#اگر defined TCC_ہدف_X86_64
# define REL_TYPE_براہ_راست R_X86_64_64
# define R_XXX_THUNKFIX R_X86_64_PC32
# define R_XXX_RELATIVE R_X86_64_RELATIVE
# define R_XXX_FUNCCALL R_X86_64_PLT32
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0x8664
# define CHARACTERISTICS_EXE 0x022F
# define CHARACTERISTICS_DLL 0x222E
# define IMAGE_بنیاد_EXE 0x00400000
# define IMAGE_بنیاد_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#وگرنہ_اگر defined TCC_ہدف_ARM
# define REL_TYPE_براہ_راست R_ARM_ABS32
# define R_XXX_THUNKFIX R_ARM_ABS32
# define R_XXX_RELATIVE R_ARM_RELATIVE
# define R_XXX_FUNCCALL R_ARM_PC24
# define R_XXX_FUNCCALL2 R_ARM_ABS32
# define RSRC_RELTYPE 7 /* ??? (not tested) */
# define IMAGE_FILE_MACHINE 0x01C0
# define CHARACTERISTICS_EXE 0x010F
# define CHARACTERISTICS_DLL 0x230F
# define IMAGE_بنیاد_EXE 0x00100000
# define IMAGE_بنیاد_DLL 0x10000000
# define DLLCHARACTERISTICS 0
# define OS_VER 0x0400

#وگرنہ_اگر defined TCC_ہدف_ARM64
# define REL_TYPE_براہ_راست R_AARCH64_ABS64
# define R_XXX_THUNKFIX R_AARCH64_ABS64
# define R_XXX_RELATIVE R_AARCH64_RELATIVE
# define R_XXX_FUNCCALL R_AARCH64_CALL26
# define RSRC_RELTYPE 3
# define IMAGE_FILE_MACHINE 0xAA64
# define CHARACTERISTICS_EXE 0x0022
# define CHARACTERISTICS_DLL 0x2022
# define IMAGE_بنیاد_EXE 0x140000000ULL
# define IMAGE_بنیاد_DLL 0x180000000ULL
# define OS_VER 0x0602
# define DLLCHARACTERISTICS 0x8160

#وگرنہ_اگر defined TCC_ہدف_I386
# define REL_TYPE_براہ_راست R_386_32
# define R_XXX_THUNKFIX R_386_32
# define R_XXX_RELATIVE R_386_RELATIVE
# define R_XXX_FUNCCALL R_386_PC32
# define RSRC_RELTYPE 7 /* DIR32NB */
# define IMAGE_FILE_MACHINE 0x014C
# define CHARACTERISTICS_EXE 0x030F
# define CHARACTERISTICS_DLL 0x230E
# define IMAGE_بنیاد_EXE 0x00400000
# define IMAGE_بنیاد_DLL 0x10000000
# define OS_VER 0x0400
# define DLLCHARACTERISTICS 0
#اگر_ختم

#اگر PTR_سائز == 8
# define ADDR3264 ULONGLONG
# define PE_MAGIC 0x020B
# define PE_IMAGE_REL IMAGE_REL_BASED_DIR64
#ورنہ
# define ADDR3264 DWORD
# define PE_MAGIC 0x010B
# define PE_IMAGE_REL IMAGE_REL_BASED_HIGHLOW
#اگر_ختم

#اگر_غیر_تعریف_شدہ IMAGE_NT_SIGNATURE
/* cross compiler: windows.h was not included */
/* ----------------------------------------------------------- */
/* definitions below are from winnt.h */

قسمتعریف غیرعلامتی حرف BYTE;
قسمتعریف غیرعلامتی مختصر لفظ_3;
قسمتعریف غیرعلامتی صحیح DWORD;
قسمتعریف غیرعلامتی طویل طویل ULONGLONG;
#ہدایت pack(ڈالو, 1)

قسمتعریف ساخت IMAGE_DOS_سرخی {  /* DOS .EXE header */
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

قسمتعریف ساخت IMAGE_FILE_سرخی {
    لفظ_3    Machine;
    لفظ_3    نمبر_کا_Sections;
    DWORD   وقت_Date_Stamp;
    DWORD   اشارہ_گر_مقصد_علامت_جدول;
    DWORD   نمبر_کا_Symbols;
    لفظ_3    سائز_کا_Optional_سرخی;
    لفظ_3    Characteristics;
} IMAGE_FILE_سرخی_2, *PIMAGE_FILE_سرخی;


#تعریف_کرو IMAGE_SIZEOF_FILE_سرخی 20

قسمتعریف ساخت IMAGE_ڈیٹا_DIRECTORY {
    DWORD   Virtual_پتہ;
    DWORD   سائز_3;
} IMAGE_ڈیٹا_DIRECTORY_2, *PIMAGE_ڈیٹا_DIRECTORY;


قسمتعریف ساخت IMAGE_OPTIONAL_سرخی {
    /* Standard fields. */
    لفظ_3    Magic;
    BYTE    Major_Linker_نسخہ;
    BYTE    Minor_Linker_نسخہ;
    DWORD   سائز_کا_رمز;
    DWORD   سائز_کا_Initialized_ڈیٹا;
    DWORD   سائز_کا_Uninitialized_ڈیٹا;
    DWORD   پتہ_کا_اندراج_نقطہ;
    DWORD   بنیاد_کا_رمز;
#اگر PTR_سائز == 4
    DWORD   بنیاد_کا_ڈیٹا;
#اگر_ختم
    /* NT additional fields. */
    ADDR3264 Image_بنیاد;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    لفظ_3    Major_Operating_System_نسخہ;
    لفظ_3    Minor_Operating_System_نسخہ;
    لفظ_3    Major_Image_نسخہ;
    لفظ_3    Minor_Image_نسخہ;
    لفظ_3    Major_Subsystem_نسخہ;
    لفظ_3    Minor_Subsystem_نسخہ;
    DWORD   Win32_نسخہ_قدر;
    DWORD   سائز_کا_Image;
    DWORD   سائز_کا_سرخیاں;
    DWORD   Check_مجموع;
    لفظ_3    Subsystem;
    لفظ_3    DllCharacteristics;
    ADDR3264 سائز_کا_ڈھیر_Reserve;
    ADDR3264 سائز_کا_ڈھیر_Commit;
    ADDR3264 سائز_کا_ڈھیر_Reserve_2;
    ADDR3264 سائز_کا_ڈھیر_Commit_2;
    DWORD   LoaderFlags;
    DWORD   نمبر_کا_Rva_And_Sizes;
    IMAGE_ڈیٹا_DIRECTORY_2 ڈیٹا_Directory[16];
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
#تعریف_کرو IMAGE_DIRECTORY_اندراج_بھرو_CONFIG    10   /* Load Configuration Directory */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_BOUND_IMPORT   11   /* Bound Import Directory in headers */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_IAT            12   /* Import Address Table */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_DELAY_IMPORT   13   /* Delay Load Import Descriptors */
#تعریف_کرو IMAGE_DIRECTORY_اندراج_COM_DESCRIPTOR 14   /* COM Runtime descriptor */

/* Section header format. */
#تعریف_کرو IMAGE_SIZEOF_SHORT_NAME         8

قسمتعریف ساخت IMAGE_SECTION_سرخی {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    اتحاد {
            DWORD   Physical_پتہ;
            DWORD   Virtual_سائز;
    } Misc;
    DWORD   Virtual_پتہ;
    DWORD   سائز_کا_Raw_ڈیٹا;
    DWORD   اشارہ_گر_مقصد_Raw_ڈیٹا;
    DWORD   اشارہ_گر_مقصد_Relocations;
    DWORD   اشارہ_گر_مقصد_Linenumbers;
    لفظ_3    نمبر_کا_Relocations;
    لفظ_3    نمبر_کا_Linenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_سرخی_2, *PIMAGE_SECTION_سرخی;

#تعریف_کرو IMAGE_SIZEOF_SECTION_سرخی     40

قسمتعریف ساخت _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD وقت_Date_Stamp;
    لفظ_3 Major_نسخہ;
    لفظ_3 Minor_نسخہ;
    DWORD Name;
    DWORD بنیاد_2;
    DWORD نمبر_کا_Functions;
    DWORD نمبر_کا_نام;
    DWORD پتہ_کا_Functions;
    DWORD پتہ_کا_نام;
    DWORD پتہ_کا_Name_Ordinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

قسمتعریف ساخت _IMAGE_TLS_DIRECTORY {
    ADDR3264 آغاز_پتہ_کا_Raw_ڈیٹا;
    ADDR3264 انتہا_پتہ_کا_Raw_ڈیٹا;
    ADDR3264 پتہ_کا_اشاریہ;
    ADDR3264 پتہ_کا_Call_Backs;
    DWORD سائز_کا_Zero_Fill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;

قسمتعریف ساخت _IMAGE_IMPORT_DESCRIPTOR {
    اتحاد {
        DWORD Characteristics;
        DWORD Original_پہلا_Thunk;
    };
    DWORD وقت_Date_Stamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD پہلا_Thunk;
} IMAGE_IMPORT_DESCRIPTOR;

قسمتعریف ساخت IMAGE_بنیاد_RELOCATION {
    DWORD   Virtual_پتہ;
    DWORD   سائز_کا_بلاک;
//  WORD    TypeOffset[1];
} IMAGE_بنیاد_RELOCATION_2;

#تعریف_کرو IMAGE_SIZEOF_بنیاد_RELOCATION     8

#تعریف_کرو IMAGE_REL_BASED_ABSOLUTE         0
#تعریف_کرو IMAGE_REL_BASED_بلند             1
#تعریف_کرو IMAGE_REL_BASED_کم              2
#تعریف_کرو IMAGE_REL_BASED_HIGHLOW          3
#تعریف_کرو IMAGE_REL_BASED_HIGHADJ          4
#تعریف_کرو IMAGE_REL_BASED_MIPS_JMPADDR     5
#تعریف_کرو IMAGE_REL_BASED_SECTION          6
#تعریف_کرو IMAGE_REL_BASED_REL32            7
#تعریف_کرو IMAGE_REL_BASED_DIR64           10

#تعریف_کرو IMAGE_SCN_CNT_رمز                  0x00000020
#تعریف_کرو IMAGE_SCN_CNT_INITIALIZED_ڈیٹا      0x00000040
#تعریف_کرو IMAGE_SCN_CNT_UNINITIALIZED_ڈیٹا    0x00000080
#تعریف_کرو IMAGE_SCN_MEM_DISCARDABLE           0x02000000
#تعریف_کرو IMAGE_SCN_MEM_SHARED                0x10000000
#تعریف_کرو IMAGE_SCN_MEM_EXECUTE               0x20000000
#تعریف_کرو IMAGE_SCN_MEM_READ                  0x40000000
#تعریف_کرو IMAGE_SCN_MEM_WRITE                 0x80000000

#تعریف_کرو IMAGE_DLLCHARACTERISTICS_بلند_ENTROPY_VA 0x0020
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_DYNAMIC_بنیاد 0x0040
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#تعریف_کرو IMAGE_FILE_RELOCS_STRIPPED 0x0001

#ہدایت pack(نکالو)

/* ----------------------------------------------------------- */
#اگر_ختم /* ndef IMAGE_NT_SIGNATURE */
/* ----------------------------------------------------------- */

#اگر_غیر_تعریف_شدہ IMAGE_DLLCHARACTERISTICS_DYNAMIC_بنیاد
  /* allow self-host build with tcc 0.9.27 - doesn't have this in winnt.h */
  #تعریف_کرو IMAGE_DLLCHARACTERISTICS_DYNAMIC_بنیاد 0x0040
#اگر_ختم

#ہدایت pack(ڈالو, 1)
ساخت pe_سرخی
{
    IMAGE_DOS_سرخی_2 doshdr;
    BYTE dosstub[0x40];
    DWORD nt_sig;
    IMAGE_FILE_سرخی_2 filehdr;
#اگر PTR_سائز == 8
    IMAGE_OPTIONAL_HEADER64 opthdr;
#ورنہ
#اگر_تعریف_شدہ _WIN64
    IMAGE_OPTIONAL_HEADER32 opthdr;
#ورنہ
    IMAGE_OPTIONAL_سرخی_2 opthdr;
#اگر_ختم
#اگر_ختم
};

ساخت pe_reloc_سرخی {
    DWORD انحراف;
    DWORD سائز;
};

ساخت pe_rsrc_سرخی {
    ساخت IMAGE_FILE_سرخی filehdr;
    ساخت IMAGE_SECTION_سرخی sectionhdr;
};

ساخت pe_rsrc_reloc {
    DWORD انحراف;
    DWORD سائز;
    لفظ_3 type;
};
#ہدایت pack(نکالو)

/* ------------------------------------------------------------- */
/* internal temporary structures */

شمار {
    sec_متن = 0,
    sec_rdata ,
    sec_ڈیٹا ,
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

#اگر 0
ساکن ثابت DWORD pe_sec_flags[] = {
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
#اگر_ختم

ساخت section_info {
    صحیح cls;
    حرف name[32];
    ADDR3264 sh_addr;
    DWORD sh_سائز;
    DWORD pe_flags;
    Section *sec;
    DWORD ڈیٹا_سائز;
    IMAGE_SECTION_سرخی_2 ish;
};

ساخت import_علامت {
    صحیح sym_اشاریہ;
    صحیح iat_اشاریہ;
    صحیح thk_انحراف;
};

ساخت pe_import_info {
    صحیح dll_اشاریہ;
    صحیح sym_گنتی;
    ساخت import_علامت **symbols;
};

ساخت pe_info {
    TCCState *s1;
    Section *reloc;
    Section *thunk;
    Section *coffsym;
    Section *coffstr;
    ثابت حرف *filename;
    صحیح type;
    DWORD sizeofheaders;
    ADDR3264 imagebase;
    ثابت حرف *آغاز_علامت;
    DWORD آغاز_addr;
    DWORD imp_offs;
    DWORD imp_سائز;
    DWORD iat_offs;
    DWORD iat_سائز;
    DWORD exp_offs;
    DWORD exp_سائز;
    DWORD tls_dir;
    DWORD tls_ڈیٹا;
    DWORD tls_سائز;
    صحیح subsystem;
    DWORD section_align;
    DWORD file_align;
    ساخت section_info **sec_info;
    صحیح sec_گنتی;
    ساخت pe_import_info **imp_info;
    صحیح imp_گنتی;
    /* output */
    FILE *op;
    DWORD مجموع;
    غیرعلامتی pos;
};

#تعریف_کرو PE_NUL 0
#تعریف_کرو PE_DLL 1
#تعریف_کرو PE_GUI 2
#تعریف_کرو PE_EXE 3
#تعریف_کرو PE_تسلسل 4

/* --------------------------------------------*/

ساکن ثابت حرف *pe_export_name(TCCState *s1, ElfW(Sym) *sym)
{
    ثابت حرف *name = (حرف*)symtab_section->link->ڈیٹا + sym->st_name;
    اگر (s1->leading_underscore && name[0] == '_' && !(sym->st_other & ST_PE_STDCALL))
        واپس name + 1;
    واپس name;
}


ساکن صحیح dynarray_assoc(خالی **pp, صحیح n, صحیح کلید)
{
    صحیح i;
    برائے (i = 0; i < n; ++i, ++pp)
    اگر (کلید == **(صحیح **) pp)
        واپس i;
    واپس -1;
}

ساکن DWORD umin(DWORD a, DWORD b)
{
    واپس a < b ? a : b;
}

ساکن DWORD umax(DWORD a, DWORD b)
{
    واپس a < b ? b : a;
}

ساکن DWORD pe_file_align(ساخت pe_info *pe, DWORD n)
{
    واپس (n + (pe->file_align - 1)) & ~(pe->file_align - 1);
}

ساکن ADDR3264 pe_virtual_align(ساخت pe_info *pe, ADDR3264 n)
{
    واپس (n + (pe->section_align - 1)) & ~(ADDR3264)(pe->section_align - 1);
}

ساکن خالی pe_align_section(Section *s, صحیح a)
{
    صحیح i = s->ڈیٹا_انحراف & (a-1);
    اگر (i)
        section_ptr_جوڑو(s, a - i);
}

ساکن خالی pe_سیٹ_datadir(ساخت pe_سرخی *hdr, صحیح dir, DWORD addr, DWORD سائز)
{
    hdr->opthdr.ڈیٹا_Directory[dir].Virtual_پتہ = addr;
    hdr->opthdr.ڈیٹا_Directory[dir].سائز_3 = سائز;
}

ساکن صحیح pe_fwrite(ساخت pe_info *pe, ثابت خالی *ڈیٹا, صحیح len)
{
    ثابت لفظ_3 *p = ڈیٹا;
    DWORD مجموع;
    صحیح ret, i;
    pe->pos += (ret = fwrite(ڈیٹا, 1, len, pe->op));
    مجموع = pe->مجموع;
    برائے (i = len; i > 0; i -= 2) {
        مجموع += (i >= 2) ? *p++ : *(BYTE*)p;
        مجموع = (مجموع + (مجموع >> 16)) & 0xFFFF;
    }
    pe->مجموع = مجموع;
    واپس len == ret ? 0 : -1;
}

ساکن خالی pe_fpad(ساخت pe_info *pe, DWORD new_pos)
{
    حرف buf[256];
    صحیح n, diff = new_pos - pe->pos;
    memset(buf, 0, حجم buf);
    جب (diff > 0) {
        diff -= n = umin(diff, حجم buf);
        fwrite(buf, n, 1, pe->op);
    }
    pe->pos = new_pos;
}

/*----------------------------------------------------------------------------*/
/* some DWARF support with COFF symbol/string table for gdb */

#ہدایت pack(ڈالو, 1)
ساخت syment
{
    اتحاد {
        حرف        n_name[8];     /* old COFF version */
        ساخت {
            int32_t n_zeroes;      /* new == 0 */
            int32_t n_انحراف_2;      /* offset into string table */
        };
    };
    int32_t         n_قدر;        /* value of symbol */
    مختصر           n_scnum;        /* section number */
    غیرعلامتی مختصر  n_type;         /* type and derived type */
    حرف            n_sclass;       /* storage class */
    حرف            n_numaux;       /* number of aux. entries */
};
#ہدایت pack(نکالو)

#تعریف_کرو SHF_نجی 0x80000000

ساکن خالی pe_جوڑو_coffsym(ساخت pe_info *pe)
{
    TCCState *s1 = pe->s1;
    ElfSym *esym;
    ساخت syment *se;
    صحیح n;

    اگر (تہی == pe->coffsym) {
        pe->coffsym = new_section(s1, ".coffsym", SHT_PROGBITS, SHF_نجی);
        pe->coffstr = new_section(s1, ".coffstr", SHT_PROGBITS, SHF_نجی);
        section_ptr_جوڑو(pe->coffstr, 4); /* coff string table size */
        واپس;
    }

#اگر 0
    se = section_ptr_جوڑو(pe->coffsym, حجم *se);
    strcpy(se->n_name, ".file");
    se->n_scnum = -2;
    se->n_sclass = 0x67;
    se->n_numaux = 1;
    se = section_ptr_جوڑو(pe->coffsym, حجم *se);
    strcpy((حرف*)se, "no-file");
#اگر_ختم

#اگر 1
    esym = (ElfSym*)s1->symtab->ڈیٹا;
    برائے (n = s1->symtab->ڈیٹا_انحراف / حجم *esym; ++esym, --n;) {
        صحیح sym_bind = ELFW(ST_BIND)(esym->st_info);
        اگر (sym_bind == STB_GLOBAL) {
            حرف *name = esym->st_name + (حرف*)s1->symtab->link->ڈیٹا;
            صحیح nl = لڑی_لمبائی(name);
            addr_t قدر = esym->st_قدر;
            صحیح shnum = esym->st_shndx;
            اگر (shnum != SHN_UNDEF && shnum < s1->nb_sections) {
                Section *s = s1->sections[shnum];
                shnum = s->sh_info;
                قدر = قدر - s->sh_addr;
            }
            se = section_ptr_جوڑو(pe->coffsym, حجم *se);
            se->n_قدر = قدر;
            se->n_scnum = shnum;
            se->n_sclass = 2; // C_EXT
            اگر (nl <= 8)
                حافظہ_نقل(se->n_name, name, nl);
            ورنہ
                se->n_انحراف_2 = put_elf_str(pe->coffstr, name);
        }
    }
#اگر_ختم
    write32le(pe->coffstr->ڈیٹا, pe->coffstr->ڈیٹا_انحراف); /* coff string table size */
}

/* Run cv2pdb, available at https://github.com/rainers/cv2pdb.  It reads
   and strips the dwarf info and creates a <exename>.pdb file instead */
ساکن خالی pe_create_pdb(TCCState *s1, ثابت حرف *exename)
{
    حرف buf[300]; صحیح r;
    snprintf(buf, حجم buf, "cv2pdb.exe \"%s\"", exename);
    r = system(buf);
    strcpy(tcc_fileextension(strcpy(buf, exename)), ".pdb");
    اگر (r) {
        tcc_error_noabort("could not create '%s'\n(need working cv2pdb from https://github.com/rainers/cv2pdb)", buf);
    } ورنہ اگر (s1->verbose) {
        لکھو("<- %s\n", buf);
    }
}

/*----------------------------------------------------------------------------*/
ساکن صحیح pe_write(ساخت pe_info *pe)
{
    ساکن ثابت ساخت pe_سرخی pe_template = {
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
    0x00E0 + (PTR_سائز-4)*4, /*WORD    SizeOfOptionalHeader; */
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
#اگر PTR_سائز == 4
    0x00000000, /*DWORD   BaseOfData; */
#اگر_ختم
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

    ساخت pe_سرخی pe_سرخی = pe_template;

    صحیح i;
    DWORD file_انحراف;
    ساخت section_info *si;
    IMAGE_SECTION_سرخی_2 *psh;
    TCCState *s1 = pe->s1;

    اگر (s1->do_debug)
        pe_جوڑو_coffsym(pe);

    pe->op = fopen(pe->filename, "wb");
    اگر (تہی == pe->op)
        واپس tcc_error_noabort("could not write '%s': %s", pe->filename, strerror(errno));

    pe->sizeofheaders = pe_file_align(pe,
        حجم (ساخت pe_سرخی)
        + pe->sec_گنتی * حجم (IMAGE_SECTION_سرخی_2)
        );

    file_انحراف = pe->sizeofheaders;

    اگر (2 == s1->verbose)
        لکھو("-------------------------------"
               "\n  virt   file   size  section" "\n");
    برائے (i = 0; i < pe->sec_گنتی; ++i) {
        DWORD addr, سائز;
        ثابت حرف *sh_name;

        si = pe->sec_info[i];
        sh_name = si->name;
        addr = si->sh_addr - pe->imagebase;
        سائز = si->sh_سائز;
        psh = &si->ish;

        اگر (2 == s1->verbose)
            لکھو("%6x %6x %6x  %s\n",
                (غیرعلامتی)addr, (غیرعلامتی)file_انحراف, (غیرعلامتی)سائز, sh_name);

        انتخاب (si->cls) {
            حالت sec_متن:
                اگر (!pe_سرخی.opthdr.بنیاد_کا_رمز)
                    pe_سرخی.opthdr.بنیاد_کا_رمز = addr;
                توڑو;

            حالت sec_ڈیٹا:
#اگر PTR_سائز == 4
                اگر (!pe_سرخی.opthdr.بنیاد_کا_ڈیٹا)
                    pe_سرخی.opthdr.بنیاد_کا_ڈیٹا = addr;
#اگر_ختم
                توڑو;

            حالت sec_bss:
                توڑو;

            حالت sec_reloc:
                pe_سیٹ_datadir(&pe_سرخی, IMAGE_DIRECTORY_اندراج_BASERELOC, addr, سائز);
                توڑو;

            حالت sec_rsrc:
                pe_سیٹ_datadir(&pe_سرخی, IMAGE_DIRECTORY_اندراج_RESOURCE, addr, سائز);
                توڑو;

            حالت sec_pdata:
                pe_سیٹ_datadir(&pe_سرخی, IMAGE_DIRECTORY_اندراج_EXCEPTION, addr, سائز);
                توڑو;
        }

        اگر (pe->imp_سائز) {
            pe_سیٹ_datadir(&pe_سرخی, IMAGE_DIRECTORY_اندراج_IMPORT,
                pe->imp_offs, pe->imp_سائز);
            pe_سیٹ_datadir(&pe_سرخی, IMAGE_DIRECTORY_اندراج_IAT,
                pe->iat_offs, pe->iat_سائز);
        }
        اگر (pe->exp_سائز) {
            pe_سیٹ_datadir(&pe_سرخی, IMAGE_DIRECTORY_اندراج_EXPORT,
                pe->exp_offs, pe->exp_سائز);
        }
        اگر (pe->tls_سائز) {
            pe_سیٹ_datadir(&pe_سرخی, IMAGE_DIRECTORY_اندراج_TLS,
                pe->tls_dir + (pe->thunk->sh_addr - pe->imagebase), pe->tls_سائز);
        }

        حافظہ_نقل(psh->Name, sh_name, umin(لڑی_لمبائی(sh_name), حجم psh->Name));
        اگر (pe->coffstr && لڑی_لمبائی(sh_name) > 8) {
            /* long section name, for example ".debug_info" */
            snprintf((حرف*)psh->Name, 8, "/%d", put_elf_str(pe->coffstr, sh_name));
        }

        psh->Characteristics = si->pe_flags;
        psh->Virtual_پتہ = addr;
        psh->Misc.Virtual_سائز = سائز;
        pe_سرخی.opthdr.سائز_کا_Image =
            umax(pe_virtual_align(pe, سائز + addr), pe_سرخی.opthdr.سائز_کا_Image);

        اگر (si->ڈیٹا_سائز) {
            psh->اشارہ_گر_مقصد_Raw_ڈیٹا = file_انحراف;
            file_انحراف = pe_file_align(pe, file_انحراف + si->ڈیٹا_سائز);
            psh->سائز_کا_Raw_ڈیٹا = file_انحراف - psh->اشارہ_گر_مقصد_Raw_ڈیٹا;
            اگر (si->cls == sec_متن)
                pe_سرخی.opthdr.سائز_کا_رمز += psh->سائز_کا_Raw_ڈیٹا;
            ورنہ
                pe_سرخی.opthdr.سائز_کا_Initialized_ڈیٹا += psh->سائز_کا_Raw_ڈیٹا;
        }
    }

    //pe_header.filehdr.TimeDateStamp = time(NULL);
    pe_سرخی.filehdr.نمبر_کا_Sections = pe->sec_گنتی;
    pe_سرخی.opthdr.پتہ_کا_اندراج_نقطہ = pe->آغاز_addr;
    pe_سرخی.opthdr.سائز_کا_سرخیاں = pe->sizeofheaders;
    pe_سرخی.opthdr.Image_بنیاد = pe->imagebase;
    pe_سرخی.opthdr.Subsystem = pe->subsystem;
    pe_سرخی.opthdr.DllCharacteristics = s1->pe_dll_characteristics;
    اگر (s1->pe_ڈھیر_سائز)
        pe_سرخی.opthdr.سائز_کا_ڈھیر_Reserve = s1->pe_ڈھیر_سائز;
    اگر (PE_DLL == pe->type)
        pe_سرخی.filehdr.Characteristics = CHARACTERISTICS_DLL;
    pe_سرخی.filehdr.Characteristics |= s1->pe_characteristics;
    اگر (pe->reloc)
        pe_سرخی.filehdr.Characteristics &= ~IMAGE_FILE_RELOCS_STRIPPED;

    اگر (pe->coffsym) {
        pe_جوڑو_coffsym(pe);
        pe_سرخی.filehdr.اشارہ_گر_مقصد_علامت_جدول = file_انحراف;
        pe_سرخی.filehdr.نمبر_کا_Symbols
            = pe->coffsym->ڈیٹا_انحراف / حجم (ساخت syment);
    }

    pe_fwrite(pe, &pe_سرخی, حجم pe_سرخی);
    برائے (i = 0; i < pe->sec_گنتی; ++i)
        pe_fwrite(pe, &pe->sec_info[i]->ish, حجم(IMAGE_SECTION_سرخی_2));

    file_انحراف = pe->sizeofheaders;
    برائے (i = 0; i < pe->sec_گنتی; ++i) {
        Section *s;
        si = pe->sec_info[i];
        اگر (!si->ڈیٹا_سائز)
            جاری;
        برائے (s = si->sec; s; s = s->پچھلا) {
            pe_fpad(pe, file_انحراف);
            pe_fwrite(pe, s->ڈیٹا, s->ڈیٹا_انحراف);
            اگر (s->پچھلا)
                file_انحراف += s->پچھلا->sh_addr - s->sh_addr;
        }
        file_انحراف = si->ish.اشارہ_گر_مقصد_Raw_ڈیٹا + si->ish.سائز_کا_Raw_ڈیٹا;
        pe_fpad(pe, file_انحراف);
    }

    اگر (pe->coffsym) {
        pe_fwrite(pe, pe->coffsym->ڈیٹا, pe->coffsym->ڈیٹا_انحراف);
        pe_fwrite(pe, pe->coffstr->ڈیٹا, pe->coffstr->ڈیٹا_انحراف);
        file_انحراف = pe->pos;
    }

    pe->مجموع += file_انحراف;
    fseek(pe->op, offsetof(ساخت pe_سرخی, opthdr.Check_مجموع), SEEK_SET);
    pe_fwrite(pe, &pe->مجموع, حجم (DWORD));

    fclose (pe->op);
#اگر_غیر_تعریف_شدہ _WIN32
    chmod(pe->filename, 0777);
#اگر_ختم

    اگر (2 == s1->verbose)
        لکھو("-------------------------------\n");
    اگر (s1->verbose)
        لکھو("<- %s (%u bytes)\n", pe->filename, (غیرعلامتی)file_انحراف);

    اگر (s1->do_debug & 16)
        pe_create_pdb(s1, pe->filename);
    واپس 0;
}

/*----------------------------------------------------------------------------*/

ساکن ساخت import_علامت *pe_جوڑو_import(ساخت pe_info *pe, صحیح sym_اشاریہ)
{
    صحیح i;
    صحیح dll_اشاریہ;
    ساخت pe_import_info *p;
    ساخت import_علامت *s;
    ElfW(Sym) *isym;

    isym = (ElfW(Sym) *)pe->s1->dynsymtab_section->ڈیٹا + sym_اشاریہ;
    dll_اشاریہ = isym->st_سائز;

    i = dynarray_assoc ((خالی**)pe->imp_info, pe->imp_گنتی, dll_اشاریہ);
    اگر (-1 != i) {
        p = pe->imp_info[i];
        جاؤ ملا_dll;
    }
    p = tcc_mallocz(حجم *p);
    p->dll_اشاریہ = dll_اشاریہ;
    dynarray_جوڑو(&pe->imp_info, &pe->imp_گنتی, p);

ملا_dll:
    i = dynarray_assoc ((خالی**)p->symbols, p->sym_گنتی, sym_اشاریہ);
    اگر (-1 != i)
        واپس p->symbols[i];

    s = tcc_mallocz(حجم *s);
    dynarray_جوڑو(&p->symbols, &p->sym_گنتی, s);
    s->sym_اشاریہ = sym_اشاریہ;
    واپس s;
}

ساکن خالی pe_free_imports(ساخت pe_info *pe)
{
    صحیح i;
    برائے (i = 0; i < pe->imp_گنتی; ++i) {
        ساخت pe_import_info *p = pe->imp_info[i];
        dynarray_reset(&p->symbols, &p->sym_گنتی);
    }
    dynarray_reset(&pe->imp_info, &pe->imp_گنتی);
}

/*----------------------------------------------------------------------------*/
ساکن خالی pe_build_imports(ساخت pe_info *pe)
{
    صحیح thk_ptr, ent_ptr, dll_ptr, sym_cnt, i;
    DWORD rva_بنیاد = pe->thunk->sh_addr - pe->imagebase;
    صحیح ndlls = pe->imp_گنتی;
    TCCState *s1 = pe->s1;

    برائے (sym_cnt = i = 0; i < ndlls; ++i)
        sym_cnt += pe->imp_info[i]->sym_گنتی;

    اگر (0 == sym_cnt)
        واپس;

    pe_align_section(pe->thunk, 16);
    pe->imp_سائز = (ndlls + 1) * حجم(IMAGE_IMPORT_DESCRIPTOR);
    pe->iat_سائز = (sym_cnt + ndlls) * حجم(ADDR3264);
    dll_ptr = pe->thunk->ڈیٹا_انحراف;
    thk_ptr = dll_ptr + pe->imp_سائز;
    ent_ptr = thk_ptr + pe->iat_سائز;
    pe->imp_offs = dll_ptr + rva_بنیاد;
    pe->iat_offs = thk_ptr + rva_بنیاد;
    section_ptr_جوڑو(pe->thunk, pe->imp_سائز + 2*pe->iat_سائز);

    برائے (i = 0; i < pe->imp_گنتی; ++i) {
        IMAGE_IMPORT_DESCRIPTOR *hdr;
        صحیح k, n, dllindex;
        ADDR3264 v;
        ساخت pe_import_info *p = pe->imp_info[i];
        ثابت حرف *name;
        DLLReference *dllref;

        dllindex = p->dll_اشاریہ;
        اگر (dllindex)
            name = tcc_basename((dllref = s1->loaded_dlls[dllindex-1])->name);
        ورنہ
            name = "", dllref = تہی;

        /* put the dll name into the import header */
        v = put_elf_str(pe->thunk, name);
        hdr = (IMAGE_IMPORT_DESCRIPTOR*)(pe->thunk->ڈیٹا + dll_ptr);
        hdr->پہلا_Thunk = thk_ptr + rva_بنیاد;
        hdr->Original_پہلا_Thunk = ent_ptr + rva_بنیاد;
        hdr->Name = v + rva_بنیاد;

        برائے (k = 0, n = p->sym_گنتی; k <= n; ++k) {
            اگر (k < n) {
                صحیح iat_اشاریہ = p->symbols[k]->iat_اشاریہ;
                صحیح sym_اشاریہ = p->symbols[k]->sym_اشاریہ;
                ElfW(Sym) *imp_sym = (ElfW(Sym) *)s1->dynsymtab_section->ڈیٹا + sym_اشاریہ;
                ثابت حرف *name = (حرف*)s1->dynsymtab_section->link->ڈیٹا + imp_sym->st_name;
                صحیح ordinal;

                /* patch symbol (and possibly its underscored alias) */
                کرو {
                    ElfW(Sym) *esym = (ElfW(Sym) *)symtab_section->ڈیٹا + iat_اشاریہ;
                    iat_اشاریہ = esym->st_قدر;
                    esym->st_قدر = thk_ptr;
                    esym->st_shndx = pe->thunk->sh_عدد;
                } جب (iat_اشاریہ);

                اگر (dllref)
                    v = 0, ordinal = imp_sym->st_قدر; /* ordinal from pe_load_def */
                ورنہ
                    ordinal = 0, v = imp_sym->st_قدر; /* address from tcc_add_symbol() */

#اگر_تعریف_شدہ TCC_IS_NATIVE
                اگر (pe->type == PE_تسلسل) {
                    اگر (dllref) {
                        اگر ( !dllref->handle )
                            dllref->handle = بھرو_Library_A(dllref->name);
                        v = (ADDR3264)Get_Proc_پتہ(dllref->handle, ordinal?(حرف*)0+ordinal:name);
                    }
                    اگر (!v)
                        tcc_error_noabort("could not resolve symbol '%s'", name);
                } ورنہ
#اگر_ختم
                اگر (ordinal) {
                    v = ordinal | (ADDR3264)1 << (حجم(ADDR3264)*8 - 1);
                } ورنہ {
                    v = pe->thunk->ڈیٹا_انحراف + rva_بنیاد;
                    section_ptr_جوڑو(pe->thunk, حجم(لفظ_3)); /* hint, not used */
                    put_elf_str(pe->thunk, name);
                }

            } ورنہ {
                v = 0; /* last entry is zero */
            }

            *(ADDR3264*)(pe->thunk->ڈیٹا+thk_ptr) =
            *(ADDR3264*)(pe->thunk->ڈیٹا+ent_ptr) = v;
            thk_ptr += حجم (ADDR3264);
            ent_ptr += حجم (ADDR3264);
        }
        dll_ptr += حجم(IMAGE_IMPORT_DESCRIPTOR);
    }
}

/* ------------------------------------------------------------- */

ساخت pe_ترتیب_دو_sym
{
    صحیح اشاریہ;
    ثابت حرف *name;
};

ساکن صحیح sym_cmp(ثابت خالی *va, ثابت خالی *vb)
{
    ثابت حرف *ca = (*(ساخت pe_ترتیب_دو_sym**)va)->name;
    ثابت حرف *cb = (*(ساخت pe_ترتیب_دو_sym**)vb)->name;
    واپس strcmp(ca, cb);
}

ساکن خالی pe_build_exports(ساخت pe_info *pe)
{
    ElfW(Sym) *sym;
    صحیح sym_اشاریہ, sym_انتہا;
    DWORD rva_بنیاد, بنیاد_o, func_o, name_o, ord_o, str_o;
    IMAGE_EXPORT_DIRECTORY *hdr;
    صحیح sym_گنتی, ord;
    ساخت pe_ترتیب_دو_sym **sorted, *p;
    TCCState *s1 = pe->s1;

    FILE *op;
    حرف buf[260];
    ثابت حرف *dllname;
    ثابت حرف *name;

    rva_بنیاد = pe->thunk->sh_addr - pe->imagebase;
    sym_گنتی = 0, sorted = تہی, op = تہی;

    sym_انتہا = symtab_section->ڈیٹا_انحراف / حجم(ElfW(Sym));
    برائے (sym_اشاریہ = 1; sym_اشاریہ < sym_انتہا; ++sym_اشاریہ) {
        sym = (ElfW(Sym)*)symtab_section->ڈیٹا + sym_اشاریہ;
        name = pe_export_name(s1, sym);
        اگر (sym->st_other & ST_PE_EXPORT) {
            p = tcc_malloc(حجم *p);
            p->اشاریہ = sym_اشاریہ;
            p->name = name;
            dynarray_جوڑو(&sorted, &sym_گنتی, p);
        }
#اگر 0
        اگر (sym->st_other & ST_PE_EXPORT)
            لکھو("export: %s\n", name);
        اگر (sym->st_other & ST_PE_STDCALL)
            لکھو("stdcall: %s\n", name);
#اگر_ختم
    }

    اگر (0 == sym_گنتی)
        واپس;

    qsort (sorted, sym_گنتی, حجم *sorted, sym_cmp);

    pe_align_section(pe->thunk, 16);
    dllname = tcc_basename(pe->filename);

    بنیاد_o = pe->thunk->ڈیٹا_انحراف;
    func_o = بنیاد_o + حجم(IMAGE_EXPORT_DIRECTORY);
    name_o = func_o + sym_گنتی * حجم (DWORD);
    ord_o = name_o + sym_گنتی * حجم (DWORD);
    str_o = ord_o + sym_گنتی * حجم(لفظ_3);

    hdr = section_ptr_جوڑو(pe->thunk, str_o - بنیاد_o);
    hdr->Characteristics        = 0;
    hdr->بنیاد_2                   = 1;
    hdr->نمبر_کا_Functions      = sym_گنتی;
    hdr->نمبر_کا_نام          = sym_گنتی;
    hdr->پتہ_کا_Functions     = func_o + rva_بنیاد;
    hdr->پتہ_کا_نام         = name_o + rva_بنیاد;
    hdr->پتہ_کا_Name_Ordinals  = ord_o + rva_بنیاد;
    hdr->Name                   = str_o + rva_بنیاد;
    put_elf_str(pe->thunk, dllname);

#اگر 1
    /* automatically write exports to <output-filename>.def */
    pstrcpy(buf, حجم buf, pe->filename);
    strcpy(tcc_fileextension(buf), ".def");
    op = fopen(buf, "wb");
    اگر (تہی == op) {
        tcc_error_noabort("could not create '%s': %s", buf, strerror(errno));
    } ورنہ {
        fprintf(op, "LIBRARY %s\n\nEXPORTS\n", dllname);
        اگر (s1->verbose)
            لکھو("<- %s (%d symbol%s)\n", buf, sym_گنتی, &"s"[sym_گنتی < 2]);
    }
#اگر_ختم

    برائے (ord = 0; ord < sym_گنتی; ++ord)
    {
        p = sorted[ord], sym_اشاریہ = p->اشاریہ, name = p->name;
        /* insert actual address later in relocate_sections() */
        put_elf_reloc(symtab_section, pe->thunk,
            func_o, R_XXX_RELATIVE, sym_اشاریہ);
        *(DWORD*)(pe->thunk->ڈیٹا + name_o)
            = pe->thunk->ڈیٹا_انحراف + rva_بنیاد;
        *(لفظ_3*)(pe->thunk->ڈیٹا + ord_o)
            = ord;
        put_elf_str(pe->thunk, name);
        func_o += حجم (DWORD);
        name_o += حجم (DWORD);
        ord_o += حجم (لفظ_3);
        اگر (op)
            fprintf(op, "%s\n", name);
    }

    pe->exp_offs = بنیاد_o + rva_بنیاد;
    pe->exp_سائز = pe->thunk->ڈیٹا_انحراف - بنیاد_o;
    dynarray_reset(&sorted, &sym_گنتی);
    اگر (op)
        fclose(op);
}

/* ------------------------------------------------------------- */
ساکن خالی pe_build_reloc (ساخت pe_info *pe)
{
    DWORD انحراف, بلاک_ptr, sh_addr, addr;
    صحیح گنتی_2, i;
    ElfW_Rel *rel, *rel_انتہا;
    Section *s = تہی, *sr;
    ساخت pe_reloc_سرخی *hdr;
    TCCState *s1 = pe->s1;
    صحیح dwarf = 0, n;

    sh_addr = انحراف = بلاک_ptr = گنتی_2 = i = 0;
    rel = rel_انتہا = تہی;

    برائے(;;) {
        اگر (rel < rel_انتہا) {
            صحیح type = ELFW(R_TYPE)(rel->r_info);
            addr = rel->r_انحراف + sh_addr;
            ++ rel;
            اگر (type != REL_TYPE_براہ_راست)
                جاری;
            اگر (dwarf) { /* don't runtime-relocate dwarf-to-dwarf */
                n = ((ElfSym *)s1->symtab->ڈیٹا + ELFW(R_SYM)(rel[-1].r_info))->st_shndx;
                اگر (n >= s1->dwlo && n < s1->dwhi)
                    جاری;
            }
            اگر (گنتی_2 == 0) { /* new block */
                بلاک_ptr = pe->reloc->ڈیٹا_انحراف;
                section_ptr_جوڑو(pe->reloc, حجم(ساخت pe_reloc_سرخی));
                انحراف = addr & 0xFFFFFFFF<<12;
            }
            اگر ((addr -= انحراف)  < (1<<12)) { /* one block spans 4k addresses */
                لفظ_3 *wp = section_ptr_جوڑو(pe->reloc, حجم (لفظ_3));
                *wp = addr | PE_IMAGE_REL<<12;
                ++گنتی_2;
                جاری;
            }
            -- rel;

        } ورنہ اگر (s) {
            sr = s->reloc;
            اگر (sr) {
                rel = (ElfW_Rel *)sr->ڈیٹا;
                rel_انتہا = (ElfW_Rel *)(sr->ڈیٹا + sr->ڈیٹا_انحراف);
                sh_addr = s->sh_addr;
                dwarf = s->sh_عدد >= s1->dwlo && s->sh_عدد < s1->dwhi;
            }
            s = s->پچھلا;
            جاری;

        } ورنہ اگر (i < pe->sec_گنتی) {
            s = pe->sec_info[i]->sec, ++i;
            جاری;

        } ورنہ اگر (!گنتی_2)
            توڑو;

        /* fill the last block and ready for a new one */
        اگر (گنتی_2 & 1) /* align for DWORDS */
            section_ptr_جوڑو(pe->reloc, حجم(لفظ_3)), ++گنتی_2;
        hdr = (ساخت pe_reloc_سرخی *)(pe->reloc->ڈیٹا + بلاک_ptr);
        hdr -> انحراف = انحراف - pe->imagebase;
        hdr -> سائز = گنتی_2 * حجم(لفظ_3) + حجم(ساخت pe_reloc_سرخی);
        گنتی_2 = 0;
    }
}

/* ------------------------------------------------------------- */
ساکن خالی pe_build_tls(ساخت pe_info *pe, Section *s)
{
    TCCState *s1 = pe->s1;
    IMAGE_TLS_DIRECTORY *d;
    صحیح c, n;

    اگر (0 == s) {
        pe->tls_سائز = حجم (IMAGE_TLS_DIRECTORY);
        pe->tls_dir = section_جوڑو(pe->thunk, pe->tls_سائز, 16);
        pe->tls_ڈیٹا = section_جوڑو(ڈیٹا_section, PTR_سائز * (1+3), 16);
        /* put relocations on entries */
        c = put_elf_sym(symtab_section, 0, 0, 0, 0, ڈیٹا_section->sh_عدد, 0);
        برائے (n = 0; n < 4; ++n)
            put_elf_reloc(symtab_section, pe->thunk, pe->tls_dir + PTR_سائز*n, REL_TYPE_براہ_راست, c);
        /* for generators */
        سیٹ_elf_sym(symtab_section, pe->tls_ڈیٹا, PTR_سائز * 4,
                ELFW(ST_INFO)(STB_GLOBAL, STT_OBJECT),
                0, ڈیٹا_section->sh_عدد, "__tls_index");
        واپس;
    }

    اگر (0 == s1->tls_آغاز)
        s1->tls_آغاز = s->sh_addr;
    d = (خالی*)(pe->thunk->ڈیٹا + pe->tls_dir);
    d->آغاز_پتہ_کا_Raw_ڈیٹا = s1->tls_آغاز - ڈیٹا_section->sh_addr;
    d->انتہا_پتہ_کا_Raw_ڈیٹا = s->sh_addr + s->ڈیٹا_انحراف - ڈیٹا_section->sh_addr;
    d->پتہ_کا_اشاریہ = pe->tls_ڈیٹا;
    d->پتہ_کا_Call_Backs = pe->tls_ڈیٹا + PTR_سائز;
    d->سائز_کا_Zero_Fill = 0;
    d->Characteristics = 0;
    /* to reuse logic from linux in xxx-link.c */
    s1->tls_انتہا = s1->tls_آغاز;
}

/* ------------------------------------------------------------- */
ساکن صحیح pe_section_class(Section *s)
{
    صحیح type, flags;
    ثابت حرف *name;
    type = s->sh_type;
    flags = s->sh_flags;
    name = s->name;

    اگر (0 == memcmp(name, ".stab", 5) || 0 == memcmp(name, ".debug_", 7)) {
        واپس sec_debug;
    } ورنہ اگر (flags & SHF_ALLOC) {
        اگر (flags & SHF_TLS)
            واپس sec_tdata + (type == SHT_NOBITS);
        اگر (type == SHT_PROGBITS
         || type == SHT_INIT_ARRAY
         || type == SHT_FINI_ARRAY) {
            اگر (flags & SHF_EXECINSTR)
                واپس sec_متن;
            اگر (flags & SHF_WRITE)
                واپس sec_ڈیٹا;
            اگر (0 == strcmp(name, ".rsrc"))
                واپس sec_rsrc;
            اگر (0 == strcmp(name, ".iedat"))
                واپس sec_idata;
            اگر (0 == strcmp(name, ".pdata"))
                واپس sec_pdata;
            واپس sec_rdata;
        } ورنہ اگر (type == SHT_NOBITS) {
            واپس sec_bss;
        }
        واپس sec_other;
    } ورنہ {
        اگر (0 == strcmp(name, ".reloc"))
            واپس sec_reloc;
    }
    واپس sec_آخری;
}

ساکن صحیح pe_تفویض_پتے (ساخت pe_info *pe)
{
    صحیح i, k, n, c, nbs;
    ADDR3264 addr;
    صحیح *sec_ترتیب, *sec_cls;
    ساخت section_info *si;
    Section *s;
    TCCState *s1 = pe->s1;

    اگر (PE_DLL == pe->type
        || (s1->pe_dll_characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_بنیاد))
        pe->reloc = new_section(s1, ".reloc", SHT_PROGBITS, 0);
    pe->thunk = rodata_section;
    //pe->thunk = new_section(s1, ".iedat", SHT_PROGBITS, SHF_ALLOC);

    nbs = s1->nb_sections;
    sec_ترتیب = tcc_mallocz(2 * حجم (صحیح) * nbs);
    sec_cls = sec_ترتیب + nbs;
    برائے (i = 1; i < nbs; ++i) {
        s = s1->sections[i];
        k = pe_section_class(s);
        برائے (n = i; n > 1 && k < (c = sec_cls[n - 1]); --n)
            sec_cls[n] = c, sec_ترتیب[n] = sec_ترتیب[n - 1];
        sec_cls[n] = k, sec_ترتیب[n] = i;
        اگر ((s->sh_flags & SHF_TLS) && 0 == pe->tls_سائز)
            pe_build_tls(pe, تہی);
    }
    si = تہی;
    addr = pe->imagebase + 1;
    برائے (i = 1; (c = sec_cls[i]) < sec_آخری; ++i) {
        s = s1->sections[sec_ترتیب[i]];

        اگر (PE_ملاؤ_ڈیٹا && c == sec_bss)
            c = sec_ڈیٹا;
        اگر (c == sec_tbss)
            c = sec_tdata;

        اگر (si && c == si->cls && c != sec_debug) {
            /* merge with previous section */
            s->sh_addr = addr = ((addr - 1) | (s->sh_addralign - 1)) + 1;
        } ورنہ {
            si = تہی;
            s->sh_addr = addr = pe_virtual_align(pe, addr);
        }

        اگر (s == pe->thunk) {
            pe_build_imports(pe);
            pe_build_exports(pe);
        }

        اگر (s == pe->reloc)
            pe_build_reloc (pe);

        اگر (0 == s->ڈیٹا_انحراف)
            جاری;

        اگر (si)
            جاؤ جوڑو_section;

        si = tcc_mallocz(حجم *si);
        dynarray_جوڑو(&pe->sec_info, &pe->sec_گنتی, si);

        strcpy(si->name, s->name);
        si->cls = c;
        si->sh_addr = addr;

        si->pe_flags = IMAGE_SCN_MEM_READ;
        اگر (s->sh_flags & SHF_EXECINSTR)
            si->pe_flags |= IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_رمز;
        ورنہ اگر (s->sh_type == SHT_NOBITS && !(s->sh_flags & SHF_TLS))
            si->pe_flags |= IMAGE_SCN_CNT_UNINITIALIZED_ڈیٹا;
        ورنہ
            si->pe_flags |= IMAGE_SCN_CNT_INITIALIZED_ڈیٹا;
        اگر (s->sh_flags & SHF_WRITE)
            si->pe_flags |= IMAGE_SCN_MEM_WRITE;
        اگر (0 == (s->sh_flags & SHF_ALLOC))
            si->pe_flags |= IMAGE_SCN_MEM_DISCARDABLE;

جوڑو_section:
        s->sh_info = pe->sec_گنتی; /* section number for coff syms */
        addr += s->ڈیٹا_انحراف;
        si->sh_سائز = addr - si->sh_addr;
        اگر (s->sh_type != SHT_NOBITS) {
            Section **ps = &si->sec;
            جب (*ps)
                ps = &(*ps)->پچھلا;
            *ps = s, s->پچھلا = تہی;
            si->ڈیٹا_سائز = si->sh_سائز;
        }

        اگر (s->sh_flags & SHF_TLS) {
            strcpy(si->name, ".tls");
            pe_build_tls(pe, s);
        }

        //printf("%08x %05x %08x %s\n", si->sh_addr, si->sh_size, si->pe_flags, s->name);
    }
#اگر 0
    برائے (i = 1; i < nbs; ++i) {
        Section *s = s1->sections[sec_ترتیب[i]];
        صحیح type = s->sh_type;
        صحیح flags = s->sh_flags;
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
            (غیرعلامتی)s->ڈیٹا_انحراف,
            s->sh_addralign,
            flags & SHF_ALLOC ? "alloc" : "",
            flags & SHF_WRITE ? "write" : "",
            flags & SHF_EXECINSTR ? "exec" : ""
            );
        fflush(stdout);
    }
    s1->verbose = 2;
#اگر_ختم
    tcc_free(sec_ترتیب);
    واپس 0;
}

/*----------------------------------------------------------------------------*/
ساکن صحیح pe_check_symbols(ساخت pe_info *pe)
{
    صحیح sym_اشاریہ, sym_انتہا;
    صحیح ret = 0;
    TCCState *s1 = pe->s1;

    pe_align_section(متن_section, 8);

    sym_انتہا = symtab_section->ڈیٹا_انحراف / حجم(ElfW(Sym));
    برائے (sym_اشاریہ = 1; sym_اشاریہ < sym_انتہا; ++sym_اشاریہ) {
        ElfW(Sym) *sym = (ElfW(Sym) *)symtab_section->ڈیٹا + sym_اشاریہ;
        اگر (sym->st_shndx == SHN_UNDEF) {
            ثابت حرف *name = (حرف*)symtab_section->link->ڈیٹا + sym->st_name;
            غیرعلامتی type = ELFW(ST_TYPE)(sym->st_info);
            صحیح imp_sym = 0;
            ساخت import_علامت *is;

            صحیح _imp_, n;
            حرف بفر[200];
            ثابت حرف *s, *p;

            n = _imp_ = 0;
            اگر (sym->st_other & ST_PE_IMPORT)
                _imp_ = 1;
            کرو {
                s = pe_export_name(s1, sym);
                اگر (n) {
                    /* second try: */
                    اگر (sym->st_other & ST_PE_STDCALL) {
                        /* try w/0 stdcall deco (windows API convention) */
                        p = strrchr(s, '@');
                        اگر (!p || s[0] != '_')
                            توڑو;
                        strcpy(بفر, s+1)[p-s-1] = 0, s = بفر;
                    } ورنہ اگر (s[0] != '_') { /* try non-ansi function */
                        بفر[0] = '_', strcpy(بفر + 1, s), s = بفر;
                    } ورنہ اگر (0 == memcmp(s, "_imp__", 6)) { /* mingw 3.7 */
                        s += 6, _imp_ = 1;
                    } ورنہ اگر (0 == memcmp(s, "__imp_", 6)) { /* mingw 2.0 */
                        s += 6, _imp_ = 1;
                    } ورنہ {
                        توڑو;
                    }
                }
                imp_sym = ڈھونڈو_elf_sym(s1->dynsymtab_section, s);
            } جب (0 == imp_sym && ++n < 2);

            //printf("pe_find_export (%d) %4x %s\n", n, imp_sym, name);
            اگر (0 == imp_sym)
                جاری; /* will throw the 'undefined' error in relocate_syms() */

            is = pe_جوڑو_import(pe, imp_sym);

            اگر (type == STT_FUNC
                /* symbols from assembler often have no type */
                || (type == STT_NOTYPE && 0 == _imp_)) {
                غیرعلامتی انحراف = is->thk_انحراف;
                اگر (انحراف) {
                    /* got aliased symbol, like stricmp and _stricmp */
                } ورنہ {
                    غیرعلامتی حرف *p;

                    /* add a helper symbol, will be patched later in
                       pe_build_imports */
                    sprintf(بفر, "IAT.%s", name);
                    is->iat_اشاریہ = put_elf_sym(
                        symtab_section, 0, حجم(DWORD),
                        ELFW(ST_INFO)(STB_LOCAL, STT_OBJECT),
                        0, SHN_UNDEF, بفر);

                    انحراف = متن_section->ڈیٹا_انحراف;
                    is->thk_انحراف = انحراف;

                    /* add the 'jmp IAT[x]' instruction */
#اگر_تعریف_شدہ TCC_ہدف_ARM
                    p = section_ptr_جوڑو(متن_section, 8+4); // room for code and address
                    write32le(p + 0, 0xE59FC000); // arm code ldr ip, [pc] ; PC+8+0 = 0001xxxx
                    write32le(p + 4, 0xE59CF000); // arm code ldr pc, [ip]
                    put_elf_reloc(symtab_section, متن_section,
                        انحراف + 8, R_XXX_THUNKFIX, is->iat_اشاریہ); // offset to IAT position
#وگرنہ_اگر defined(TCC_ہدف_ARM64)
                    p = section_ptr_جوڑو(متن_section, 24);
                    write32le(p + 0, 0x58000090); /* ldr x16, [pc, #16] */
                    write32le(p + 4, 0xf9400210); /* ldr x16, [x16] */
                    write32le(p + 8, 0xd61f0200); /* br x16 */
                    write32le(p + 12, 0xd503201f); /* nop for alignment */
                    put_elf_reloc(symtab_section, متن_section,
                        انحراف + 16, R_XXX_THUNKFIX, is->iat_اشاریہ);
#ورنہ
                    p = section_ptr_جوڑو(متن_section, 8);
                    write16le(p, 0x25FF);
#اگر_تعریف_شدہ TCC_ہدف_X86_64
                    write32le(p + 2, (DWORD)-4);
#اگر_ختم
                    put_elf_reloc(symtab_section, متن_section, 
                        انحراف + 2, R_XXX_THUNKFIX, is->iat_اشاریہ);
#اگر_ختم
                }
                /* tcc_realloc might have altered sym's address */
                sym = (ElfW(Sym) *)symtab_section->ڈیٹا + sym_اشاریہ;
                /* patch the original symbol */
                sym->st_قدر = انحراف;
                sym->st_shndx = متن_section->sh_عدد;
                sym->st_other &= ~ST_PE_EXPORT; /* do not export */

            } ورنہ { /* STT_OBJECT */
                اگر (0 == _imp_)
                    ret = tcc_error_noabort("symbol '%s' is missing __declspec(dllimport)", name);
                /* original symbol will be patched later in pe_build_imports */
                sym->st_قدر = is->iat_اشاریہ; /* chain potential alias */
                is->iat_اشاریہ = sym_اشاریہ;
            }

        } ورنہ اگر (s1->rdynamic
                   && ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
            /* if -rdynamic option, then export all non local symbols */
            sym->st_other |= ST_PE_EXPORT;
        }
    }
    واپس ret;
}

/*----------------------------------------------------------------------------*/
#اگر PE_PRINT_SECTIONS
ساکن خالی pe_print_section(FILE * f, Section * s)
{
    /* just if you're curious */
    BYTE *p, *e, b;
    صحیح i, n, l, m;
    p = s->ڈیٹا;
    e = s->ڈیٹا + s->ڈیٹا_انحراف;
    l = e - p;

    fprintf(f, "section  \"%s\"", s->name);
    اگر (s->link)
        fprintf(f, "\nlink     \"%s\"", s->link->name);
    اگر (s->reloc)
        fprintf(f, "\nreloc    \"%s\"", s->reloc->name);
    fprintf(f, "\nv_addr   %08X", (غیرعلامتی)s->sh_addr);
    fprintf(f, "\ncontents %08X", (غیرعلامتی)l);
    fprintf(f, "\n\n");

    اگر (s->sh_type == SHT_NOBITS)
        واپس;

    اگر (0 == l)
        واپس;

    اگر (s->sh_type == SHT_SYMTAB)
        m = حجم(ElfW(Sym));
    ورنہ اگر (s->sh_type == SHT_RELX)
        m = حجم(ElfW_Rel);
    ورنہ
        m = 16;

    fprintf(f, "%-8s", "offset");
    برائے (i = 0; i < m; ++i)
        fprintf(f, " %02x", i);
    n = 56;

    اگر (s->sh_type == SHT_SYMTAB || s->sh_type == SHT_RELX) {
        ثابت حرف *fields1[] = {
            "name",
            "value",
            "size",
            "bind",
            "type",
            "other",
            "shndx",
            تہی
        };

        ثابت حرف *fields2[] = {
            "offs",
            "type",
            "symb",
            تہی
        };

        ثابت حرف **p;

        اگر (s->sh_type == SHT_SYMTAB)
            p = fields1, n = 106;
        ورنہ
            p = fields2, n = 58;

        برائے (i = 0; p[i]; ++i)
            fprintf(f, "%6s", p[i]);
        fprintf(f, "  symbol");
    }

    fprintf(f, "\n");
    برائے (i = 0; i < n; ++i)
        fprintf(f, "-");
    fprintf(f, "\n");

    برائے (i = 0; i < l;)
    {
        fprintf(f, "%08X", i);
        برائے (n = 0; n < m; ++n) {
            اگر (n + i < l)
                fprintf(f, " %02X", p[i + n]);
            ورنہ
                fprintf(f, "   ");
        }

        اگر (s->sh_type == SHT_SYMTAB) {
            ElfW(Sym) *sym = (ElfW(Sym) *) (p + i);
            ثابت حرف *name = s->link->ڈیٹا + sym->st_name;
            fprintf(f, "  %04X  %04X  %04X   %02X    %02X    %02X   %04X  \"%s\"",
                    (غیرعلامتی)sym->st_name,
                    (غیرعلامتی)sym->st_قدر,
                    (غیرعلامتی)sym->st_سائز,
                    (غیرعلامتی)ELFW(ST_BIND)(sym->st_info),
                    (غیرعلامتی)ELFW(ST_TYPE)(sym->st_info),
                    (غیرعلامتی)sym->st_other,
                    (غیرعلامتی)sym->st_shndx,
                    name);

        } ورنہ اگر (s->sh_type == SHT_RELX) {
            ElfW_Rel *rel = (ElfW_Rel *) (p + i);
            ElfW(Sym) *sym =
                (ElfW(Sym) *) s->link->ڈیٹا + ELFW(R_SYM)(rel->r_info);
            ثابت حرف *name = s->link->link->ڈیٹا + sym->st_name;
            fprintf(f, "  %04X   %02X   %04X  \"%s\"",
                    (غیرعلامتی)rel->r_انحراف,
                    (غیرعلامتی)ELFW(R_TYPE)(rel->r_info),
                    (غیرعلامتی)ELFW(R_SYM)(rel->r_info),
                    name);
        } ورنہ {
            fprintf(f, "   ");
            برائے (n = 0; n < m; ++n) {
                اگر (n + i < l) {
                    b = p[i + n];
                    اگر (b < 32 || b >= 127)
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

ساکن خالی pe_print_sections(TCCState *s1, ثابت حرف *fname)
{
    Section *s;
    FILE *f;
    صحیح i;
    f = fopen(fname, "w");
    برائے (i = 1; i < s1->nb_sections; ++i) {
        s = s1->sections[i];
        pe_print_section(f, s);
    }
    pe_print_section(f, s1->dynsymtab_section);
    fclose(f);
}
#اگر_ختم

/* ------------------------------------------------------------- */

ST_FUNC صحیح pe_putimport(TCCState *s1, صحیح dllindex, ثابت حرف *name, addr_t قدر)
{
    واپس سیٹ_elf_sym(
        s1->dynsymtab_section,
        قدر,
        dllindex, /* st_size */
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE),
        0,
        قدر ? SHN_ABS : SHN_UNDEF,
        name
        );
}

ساکن صحیح read_mem(صحیح fd, غیرعلامتی انحراف, خالی *بفر, غیرعلامتی len)
{
    lseek(fd, انحراف, SEEK_SET);
    واپس len == اقرأ(fd, بفر, len);
}

/* ------------------------------------------------------------- */

ساکن صحیح get_dllexports(صحیح fd, حرف **pp)
{
    صحیح i, k, l, n, n0, ret;
    حرف *p;

    IMAGE_SECTION_سرخی_2 ish;
    IMAGE_EXPORT_DIRECTORY ied;
    IMAGE_DOS_سرخی_2 dh;
    IMAGE_FILE_سرخی_2 ih;
    DWORD sig, ref, addr;
    DWORD *namep = تہی, p0 = 0, p1;

    صحیح pef_hdroffset, opt_hdroffset, sec_hdroffset;

    n = n0 = 0;
    p = تہی;
    ret = 1;
    اگر (!read_mem(fd, 0, &dh, حجم dh))
        جاؤ the_انتہا;
    اگر (!read_mem(fd, dh.e_lfanew, &sig, حجم sig))
        جاؤ the_انتہا;
    اگر (sig != 0x00004550)
        جاؤ the_انتہا;
    pef_hdroffset = dh.e_lfanew + حجم sig;
    اگر (!read_mem(fd, pef_hdroffset, &ih, حجم ih))
        جاؤ the_انتہا;
    opt_hdroffset = pef_hdroffset + حجم ih;
    اگر (ih.Machine == 0x014C || ih.Machine == 0x01C0) {
        IMAGE_OPTIONAL_HEADER32 oh;
        sec_hdroffset = opt_hdroffset + حجم oh;
        اگر (!read_mem(fd, opt_hdroffset, &oh, حجم oh))
            جاؤ the_انتہا;
        اگر (IMAGE_DIRECTORY_اندراج_EXPORT >= oh.نمبر_کا_Rva_And_Sizes)
            جاؤ the_انتہا_0;
        addr = oh.ڈیٹا_Directory[IMAGE_DIRECTORY_اندراج_EXPORT].Virtual_پتہ;
    } ورنہ اگر (ih.Machine == 0x8664 || ih.Machine == 0xAA64) {
        IMAGE_OPTIONAL_HEADER64 oh;
        sec_hdroffset = opt_hdroffset + حجم oh;
        اگر (!read_mem(fd, opt_hdroffset, &oh, حجم oh))
            جاؤ the_انتہا;
        اگر (IMAGE_DIRECTORY_اندراج_EXPORT >= oh.نمبر_کا_Rva_And_Sizes)
            جاؤ the_انتہا_0;
        addr = oh.ڈیٹا_Directory[IMAGE_DIRECTORY_اندراج_EXPORT].Virtual_پتہ;
    } ورنہ
        جاؤ the_انتہا;

    //printf("addr: %08x\n", addr);
    برائے (i = 0; i < ih.نمبر_کا_Sections; ++i) {
        اگر (!read_mem(fd, sec_hdroffset + i * حجم ish, &ish, حجم ish))
            جاؤ the_انتہا;
        //printf("vaddr: %08x\n", ish.VirtualAddress);
        اگر (addr >= ish.Virtual_پتہ && addr < ish.Virtual_پتہ + ish.سائز_کا_Raw_ڈیٹا)
            جاؤ ملا;
    }
    جاؤ the_انتہا_0;
ملا:
    ref = ish.Virtual_پتہ - ish.اشارہ_گر_مقصد_Raw_ڈیٹا;
    اگر (!read_mem(fd, addr - ref, &ied, حجم ied))
        جاؤ the_انتہا;
    k = ied.نمبر_کا_نام;
    اگر (k) {
        namep = tcc_malloc(l = k * حجم *namep);
        اگر (!read_mem(fd, ied.پتہ_کا_نام - ref, namep, l))
            جاؤ the_انتہا;
        برائے (i = l = 0; i < k; ++i) {
            p1 = namep[i] - ref;
            اگر (p1 != p0)
                lseek(fd, p0 = p1, SEEK_SET), l = 0;
            کرو {
                اگر (0 == l) {
                    اگر (n + 1000 >= n0)
                        p = tcc_realloc(p, n0 += 1000);
                    اگر ((l = اقرأ(fd, p + n, 1000 - 1)) <= 0)
                        جاؤ the_انتہا;
                }
                --l, ++p0;
            } جب (p[n++]);
        }
        p[n] = 0;
    }
the_انتہا_0:
    ret = 0;
the_انتہا:
    tcc_free(namep);
    اگر (ret && p)
        tcc_free(p), p = تہی;
    *pp = p;
    واپس ret;
}

/* -------------------------------------------------------------
 *  This is for compiled windows resources in 'coff' format
 *  as generated by 'windres.exe -O coff ...'.
 */

ساکن صحیح pe_بھرو_res(TCCState *s1, صحیح fd)
{
    ساخت pe_rsrc_سرخی hdr;
    Section *rsrc_section;
    صحیح i, ret = -1, sym_اشاریہ;
    BYTE *ptr;
    غیرعلامتی offs;

    اگر (!read_mem(fd, 0, &hdr, حجم hdr))
        جاؤ quit;

    اگر (hdr.filehdr.Machine != IMAGE_FILE_MACHINE
        || hdr.filehdr.نمبر_کا_Sections != 1
        || strcmp((حرف*)hdr.sectionhdr.Name, ".rsrc") != 0)
        جاؤ quit;

    rsrc_section = new_section(s1, ".rsrc", SHT_PROGBITS, SHF_ALLOC);
    ptr = section_ptr_جوڑو(rsrc_section, hdr.sectionhdr.سائز_کا_Raw_ڈیٹا);
    offs = hdr.sectionhdr.اشارہ_گر_مقصد_Raw_ڈیٹا;
    اگر (!read_mem(fd, offs, ptr, hdr.sectionhdr.سائز_کا_Raw_ڈیٹا))
        جاؤ quit;
    offs = hdr.sectionhdr.اشارہ_گر_مقصد_Relocations;
    sym_اشاریہ = put_elf_sym(symtab_section, 0, 0, 0, 0, rsrc_section->sh_عدد, ".rsrc");
    برائے (i = 0; i < hdr.sectionhdr.نمبر_کا_Relocations; ++i) {
        ساخت pe_rsrc_reloc rel;
        اگر (!read_mem(fd, offs, &rel, حجم rel))
            جاؤ quit;
        // printf("rsrc_reloc: %x %x %x\n", rel.offset, rel.size, rel.type);
        اگر (rel.type != RSRC_RELTYPE)
            جاؤ quit;
        put_elf_reloc(symtab_section, rsrc_section,
            rel.انحراف, R_XXX_RELATIVE, sym_اشاریہ);
        offs += حجم rel;
    }
    ret = 0;
quit:
    واپس ret;
}

/* ------------------------------------------------------------- */

ساکن حرف *trimfront(حرف *p)
{
    جب ((غیرعلامتی حرف)*p <= ' ' && *p && *p != '\n')
	++p;
    واپس p;
}

/*
static char *trimback(char *a, char *e)
{
    while (e > a && (unsigned char)e[-1] <= ' ')
	--e;
    *e = 0;;
    return a;
}*/

ساکن حرف *get_token(حرف **s, حرف *f)
{
    حرف *p, *e;
    صحیح q;

    p = trimfront(*s);
    q = *p;
    اگر (q == '"') /* support quoted LIBRARY "xyz.dll" */
        ++p;
    ورنہ
        q = ' ';
    برائے (e = p; (غیرعلامتی حرف)*e >= ' ' && *e != q; ++e)
        ;
    اگر (*e == '"')
        *e++ = 0;
    *s = trimfront(e);
    *f = **s, *e = 0;
    واپس p;
}

ساکن صحیح pe_بھرو_def(TCCState *s1, صحیح fd)
{
    صحیح state = 0, ret = -1, dllindex = 0, ord;
    حرف dllname[80], *buf, *سطر, *p, *x, اگلا;

    buf = tcc_بھرو_متن(fd);
    اگر (!buf)
        واپس ret;

    برائے (سطر = buf;; ++سطر)  {
        p = get_token(&سطر, &اگلا);
        اگر (!(*p && *p != ';'))
            جاؤ skip;
        انتخاب (state) {
        حالت 0:
            اگر (0 != stricmp(p, "LIBRARY") || اگلا == '\n')
                جاؤ quit;
            pstrcpy(dllname, حجم dllname, get_token(&سطر, &اگلا));
            اگر (!*tcc_fileextension(dllname))
                pstrcat(dllname, حجم dllname, ".dll");
            ++state;
            توڑو;
        حالت 1:
            اگر (0 != stricmp(p, "EXPORTS"))
                جاؤ quit;
            ++state;
            توڑو;
        حالت 2:
            dllindex = tcc_جوڑو_dllref(s1, dllname, 0)->اشاریہ;
            ++state;
            /* fall through */
        طےشدہ:
            /* get ordinal and will store in sym->st_value */
            ord = 0;
            اگر (اگلا == '@') {
                x = get_token(&سطر, &اگلا);
                ord = (صحیح)strtol(x + 1, &x, 10);
            }
            //printf("token %s ; %s : %d\n", dllname, p, ord);
            pe_putimport(s1, dllindex, p, ord);
            توڑو;
        }
skip:
        جب ((غیرعلامتی حرف)اگلا > ' ')
            get_token(&سطر, &اگلا);
        اگر (اگلا != '\n')
            توڑو;
    }
    ret = 0;
quit:
    tcc_free(buf);
    واپس ret;
}

/* ------------------------------------------------------------- */

ساکن صحیح pe_بھرو_dll(TCCState *s1, صحیح fd, ثابت حرف *filename)
{
    حرف *p, *q;
    DLLReference *ref = tcc_جوڑو_dllref(s1, filename, 0);
    اگر (ref->ملا)
        واپس 0;
    اگر (get_dllexports(fd, &p))
        واپس -1;
    اگر (p) {
        برائے (q = p; *q; q += 1 + لڑی_لمبائی(q))
            pe_putimport(s1, ref->اشاریہ, q, 0);
        tcc_free(p);
    }
    واپس 0;
}

ST_FUNC صحیح pe_بھرو_file(ساخت TCCState *s1, صحیح fd, ثابت حرف *filename)
{
    صحیح ret = -1;
    حرف buf[10];
    اگر (0 == strcmp(tcc_fileextension(filename), ".def"))
        ret = pe_بھرو_def(s1, fd);
    ورنہ اگر (pe_بھرو_res(s1, fd) == 0)
        ret = 0;
    ورنہ اگر (read_mem(fd, 0, buf, 4) && 0 == memcmp(buf, "MZ", 2))
        ret = pe_بھرو_dll(s1, fd, filename);
    واپس ret;
}

PUB_FUNC صحیح tcc_get_dllexports(ثابت حرف *filename, حرف **pp)
{
    صحیح ret, fd = open(filename, O_RDONLY | O_ثنائی_2);
    اگر (fd < 0)
        واپس -1;
    ret = get_dllexports(fd, pp);
    close(fd);
    واپس ret;
}

/* ------------------------------------------------------------- */
#اگر_تعریف_شدہ TCC_ہدف_X86_64
ساکن غیرعلامتی pe_جوڑو_unwind_info(TCCState *s1)
{
    اگر (تہی == s1->uw_pdata) {
        s1->uw_pdata = ڈھونڈو_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    اگر (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0, متن_section->sh_عدد, ".uw_base");
    اگر (0 == s1->uw_offs) {
        /* As our functions all have the same stackframe, we use one entry for all */
        ساکن ثابت غیرعلامتی حرف uw_info[] = {
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
        غیرعلامتی حرف *p;

        section_ptr_جوڑو(s, -s->ڈیٹا_انحراف & 3); /* align */
        s1->uw_offs = s->ڈیٹا_انحراف;
        p = section_ptr_جوڑو(s, حجم uw_info);
        حافظہ_نقل(p, uw_info, حجم uw_info);
    }

    واپس s1->uw_offs;
}

ST_FUNC خالی pe_جوڑو_unwind_ڈیٹا(غیرعلامتی آغاز, غیرعلامتی انتہا, غیرعلامتی ڈھیر)
{
    TCCState *s1 = tcc_state;
    Section *pd;
    غیرعلامتی o, n, d;
    ساخت /* _RUNTIME_FUNCTION */ {
      DWORD Begin_پتہ;
      DWORD انتہا_پتہ;
      DWORD Unwind_ڈیٹا;
    } *p;

    d = pe_جوڑو_unwind_info(s1);
    pd = s1->uw_pdata;
    o = pd->ڈیٹا_انحراف;
    p = section_ptr_جوڑو(pd, حجم *p);

    /* record this function */
    p->Begin_پتہ = آغاز;
    p->انتہا_پتہ = انتہا;
    p->Unwind_ڈیٹا = d;

    /* put relocations on it */
    برائے (n = o + حجم *p; o < n; o += حجم p->Begin_پتہ)
        put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
}

#وگرنہ_اگر defined(TCC_ہدف_ARM64)
/* ARM64 unwind codes:
   save_fplr_x: 10iiiiii  - stp x29,lr,[sp,#-(i+1)*8]!
   set_fp:      11100001  - mov x29,sp
   alloc_s:     000iiiii  - sub sp,sp,#i*16 (up to 496 bytes)
   alloc_m:     11000iii xxxxxxxx - sub sp,sp,#X*16 (up to 32KB)
   end:         11100100  - end of unwind codes
*/
ساکن Section *pe_جوڑو_unwind_info(TCCState *s1)
{
    Section *s;

    اگر (تہی == s1->uw_pdata) {
        s1->uw_pdata = ڈھونڈو_section(s1, ".pdata");
        s1->uw_pdata->sh_addralign = 4;
    }
    s = ڈھونڈو_section(s1, ".xdata");
    s->sh_addralign = 4;
    اگر (0 == s1->uw_sym)
        s1->uw_sym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  متن_section->sh_عدد, ".uw_text_base");
    اگر (0 == s1->uw_xsym)
        s1->uw_xsym = put_elf_sym(symtab_section, 0, 0, 0, 0,
                                  s->sh_عدد, ".uw_base");
    واپس s;
}

ST_FUNC خالی pe_جوڑو_unwind_ڈیٹا(غیرعلامتی آغاز, غیرعلامتی انتہا, غیرعلامتی ڈھیر)
{
    TCCState *s1 = tcc_state;
    Section *pd, *xd;
    غیرعلامتی o, d, رمز_بائٹیں, func_len;
    غیرعلامتی حرف *q;
    uint32_t سرخی;
    ساخت /* _RUNTIME_FUNCTION */ {
        DWORD Begin_پتہ;
        DWORD Unwind_ڈیٹا;
    } *p;

    صحیح epilog;

    xd = pe_جوڑو_unwind_info(s1);
    pd = s1->uw_pdata;

    func_len = (انتہا - آغاز) >> 2;
    رمز_بائٹیں = 0;
    epilog = رمز_بائٹیں;
    رمز_بائٹیں += 3; /* set_fp, save_fplr_x, end */
    رمز_بائٹیں = (رمز_بائٹیں + 3) & ~3;

    section_ptr_جوڑو(xd, -xd->ڈیٹا_انحراف & 3);
    d = xd->ڈیٹا_انحراف;
    q = section_ptr_جوڑو(xd, 4 + رمز_بائٹیں);

    /* Full ARM64 xdata header: E=1 with one epilog and no exception handler. */
    سرخی = (func_len & 0x3ffff)
        | 1 << 21
        | (epilog & 0x1F) << 22
        | (رمز_بائٹیں >> 2) << 27
        ;
    write32le(q, سرخی);
    q += 4;
    *q++ = 0xE1; /* set_fp */
    *q++ = 0x9B; /* save_fplr_x: stp x29,lr,[sp,#-224]! */
    *q++ = 0xE4; /*انتہا*/
    جب ((غیرعلامتی)(q - (xd->ڈیٹا + d + 4)) < رمز_بائٹیں)
        *q++ = 0xE3; /* nop padding */

    o = pd->ڈیٹا_انحراف;
    p = section_ptr_جوڑو(pd, حجم *p);
    p->Begin_پتہ = آغاز;
    p->Unwind_ڈیٹا = d;
    put_elf_reloc(symtab_section, pd, o, R_XXX_RELATIVE, s1->uw_sym);
    put_elf_reloc(symtab_section, pd, o + 4, R_XXX_RELATIVE, s1->uw_xsym);
}
#اگر_ختم
/* ------------------------------------------------------------- */
#اگر defined(TCC_ہدف_X86_64) || defined(TCC_ہدف_ARM64)
#تعریف_کرو PE_STDSYM(n,s) n
#ورنہ
#تعریف_کرو PE_STDSYM(n,s) "_" n s
#اگر_ختم

ساکن خالی pe_جوڑو_runtime(TCCState *s1, ساخت pe_info *pe)
{
    ثابت حرف *آغاز_علامت;
    صحیح pe_type;

    اگر (TCC_OUTPUT_DLL == s1->output_type) {
        pe_type = PE_DLL;
        آغاز_علامت = PE_STDSYM("__dllstart","@12");
    } ورنہ {
        ثابت حرف *تسلسل_علامت;
        اگر (ڈھونڈو_elf_sym(symtab_section, PE_STDSYM("WinMain","@16"))) {
            آغاز_علامت = "__winstart";
            تسلسل_علامت = "__runwinmain";
            pe_type = PE_GUI;
        } ورنہ اگر (ڈھونڈو_elf_sym(symtab_section, PE_STDSYM("wWinMain","@16"))) {
            آغاز_علامت = "__wwinstart";
            تسلسل_علامت = "__runwwinmain";
            pe_type = PE_GUI;
        } ورنہ اگر (ڈھونڈو_elf_sym(symtab_section, "wmain")) {
            آغاز_علامت = "__wstart";
            تسلسل_علامت = "__runwmain";
            pe_type = PE_EXE;
        } ورنہ {
            آغاز_علامت =  "__start";
            تسلسل_علامت = "__runmain";
            pe_type = PE_EXE;
            اگر (s1->pe_subsystem == 2)
                pe_type = PE_GUI;
        }

        اگر (TCC_OUTPUT_حافظہ == s1->output_type && !s1->nostdlib)
            آغاز_علامت = تسلسل_علامت;
    }
    اگر (s1->elf_entryname) {
        pe->آغاز_علامت = آغاز_علامت = s1->elf_entryname;
    } ورنہ {
        pe->آغاز_علامت = آغاز_علامت + 1;
        اگر (!s1->leading_underscore || strchr(آغاز_علامت, '@'))
            ++آغاز_علامت;
    }

#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
    اگر (s1->do_backtrace) {
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر (s1->do_bounds_check && s1->output_type != TCC_OUTPUT_DLL) {
	    اگر (s1->output_type == TCC_OUTPUT_حافظہ)
                tcc_جوڑو_support(s1, "bcheck_run.o");
	    ورنہ
                tcc_جوڑو_support(s1, "bcheck.o");
	}
#اگر_ختم
        اگر (s1->output_type == TCC_OUTPUT_EXE)
            tcc_جوڑو_support(s1, "bt-exe.o");
        اگر (s1->output_type == TCC_OUTPUT_DLL)
            tcc_جوڑو_support(s1, "bt-dll.o");
        اگر (s1->output_type != TCC_OUTPUT_DLL)
            tcc_جوڑو_support(s1, "bt-log.o");
        tcc_جوڑو_btstub(s1);
    }
#اگر_ختم

    /* grab the startup code from libtcc1.a */
#اگر_تعریف_شدہ TCC_IS_NATIVE
    اگر (TCC_OUTPUT_حافظہ != s1->output_type || s1->تسلسل_main)
#اگر_ختم
    سیٹ_global_sym(s1, آغاز_علامت, تہی, 0);

    اگر (0 == s1->nostdlib) {
        ساکن ثابت حرف * ثابت libs[] = {
            "msvcrt", "kernel32", "", "user32", "gdi32", تہی
        };
        ثابت حرف * ثابت *pp, *p;
        اگر (TCC_LIBTCC1[0])
            tcc_جوڑو_support(s1, TCC_LIBTCC1);
        s1->static_link = 0; /* no static crt for tcc */
        برائے (pp = libs; 0 != (p = *pp); ++pp) {
            اگر (*p)
                tcc_جوڑو_library(s1, p);
            ورنہ اگر (PE_DLL != pe_type && PE_GUI != pe_type)
                توڑو;
        }
    }

    /* need this for 'tccelf.c:relocate_sections()' */
    اگر (TCC_OUTPUT_DLL == s1->output_type)
        s1->output_type = TCC_OUTPUT_EXE;
    اگر (TCC_OUTPUT_حافظہ == s1->output_type)
        pe_type = PE_تسلسل;
    pe->type = pe_type;
}

ST_FUNC صحیح pe_setsubsy(TCCState *s1, ثابت حرف *arg)
{
    ساکن ثابت ساخت subsy { ثابت حرف* p; صحیح v; } x[] = {
#اگر defined(TCC_ہدف_I386) || defined(TCC_ہدف_X86_64) || defined(TCC_ہدف_ARM64)
        { "native", 1 },
        { "gui", 2 },
        { "windows", 2 },
        { "console", 3 },
        { "posix", 7 },
        { "efiapp", 10 },
        { "efiboot", 11 },
        { "efiruntime", 12 },
        { "efirom", 13 },
#وگرنہ_اگر defined(TCC_ہدف_ARM)
        { "wince", 9 },
#اگر_ختم
        { 0, -1 }};
    ثابت ساخت subsy *y;
    برائے (y = x;; ++y) {
        اگر (!y->p)
            واپس -1;
        اگر (0 == strcmp(y->p, arg)) {
            s1->pe_subsystem = y->v;
            واپس 0;
        }
    }
}

ساکن خالی pe_سیٹ_options(TCCState * s1, ساخت pe_info *pe)
{
    اگر (PE_DLL == pe->type) {
        /* XXX: check if is correct for arm-pe target */
        pe->imagebase = IMAGE_بنیاد_DLL;
    } ورنہ {
        pe->imagebase = IMAGE_بنیاد_EXE;
    }

#اگر defined(TCC_ہدف_ARM)
    /* we use "console" subsystem by default */
    pe->subsystem = 9;
#ورنہ
    اگر (PE_DLL == pe->type || PE_GUI == pe->type)
        pe->subsystem = 2;
    ورنہ
        pe->subsystem = 3;
#اگر_ختم
    /* Allow override via -Wl,-subsystem=... option */
    اگر (s1->pe_subsystem != 0)
        pe->subsystem = s1->pe_subsystem;

    /* set default file/section alignment */
    اگر (pe->subsystem == 1) {
        pe->section_align = 0x20;
        pe->file_align = 0x20;
    } ورنہ {
        pe->section_align = 0x1000;
        pe->file_align = 0x200;
    }

    اگر (s1->section_align != 0)
        pe->section_align = s1->section_align;
    اگر (s1->pe_file_align != 0)
        pe->file_align = s1->pe_file_align;

    اگر ((pe->subsystem >= 10) && (pe->subsystem <= 12))
        pe->imagebase = 0;

    اگر (s1->has_متن_addr)
        pe->imagebase = s1->متن_addr;
}

ST_FUNC صحیح pe_output_file(TCCState *s1, ثابت حرف *filename)
{
    ساخت pe_info pe;

    memset(&pe, 0, حجم pe);
    pe.filename = filename;
    pe.s1 = s1;
    s1->filetype = 0;

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    tcc_جوڑو_bcheck(s1);
#اگر_ختم
    tcc_جوڑو_pragma_libs(s1);
    pe_جوڑو_runtime(s1, &pe);
    resolve_common_syms(s1);
    pe_سیٹ_options(s1, &pe);
    pe_check_symbols(&pe);
    اگر (s1->nb_errors)
        جاؤ مکمل;
    اگر (filename) {
        pe_تفویض_پتے(&pe);
        relocate_syms(s1, s1->symtab, 0);
        اگر (s1->nb_errors)
            جاؤ مکمل;
        s1->pe_imagebase = pe.imagebase;
        relocate_sections(s1);
        pe.آغاز_addr = (DWORD)
            (get_sym_addr(s1, pe.آغاز_علامت, 1, 1) - pe.imagebase);
        اگر (s1->nb_errors)
            جاؤ مکمل;
        pe_write(&pe);
    } ورنہ {
        /* -run */
#اگر_تعریف_شدہ TCC_IS_NATIVE
        pe.thunk = ڈیٹا_section;
        pe_build_imports(&pe);
        s1->تسلسل_main = pe.آغاز_علامت;
#اگر defined(TCC_ہدف_X86_64) || defined(TCC_ہدف_ARM64)
        s1->uw_pdata = ڈھونڈو_section(s1, ".pdata");
#اگر_ختم
#اگر_ختم
    }
مکمل:
    dynarray_reset(&pe.sec_info, &pe.sec_گنتی);
    pe_free_imports(&pe);
#اگر PE_PRINT_SECTIONS
    اگر (g_debug & 8)
        pe_print_sections(s1, "tcc.log");
#اگر_ختم
    واپس s1->nb_errors ? -1 : 0;
}

/* ------------------------------------------------------------- */
