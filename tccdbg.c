/*
 *  TCC - Tiny C Compiler
 *
 *  Copyright (c) 2001-2004 Fabrice Bellard
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

/* stab debug support */

ساكن ثابت بنية {
  صحيح type;
  صحيح ناپ;
  صحيح encoding;
  ثابت حرف *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#إذا LONG_ناپ == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#وإلا
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#جے_انت
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#إذا LONG_ناپ == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#وإلا
    /* use octal instead of -1 so size_t works (-gstabs+ in gcc) */
    {   VT_LLONG | VT_LONG | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t5=r5;0;01777777777777777777777;" },
#جے_انت
    {   VT_QLONG, 16, DW_ATE_signed, "__int128:t6=r6;0;-1;" },
    {   VT_QLONG | VT_UNSIGNED, 16, DW_ATE_unsigned, "__int128 unsigned:t7=r7;0;-1;" },
    {   VT_LLONG, 8, DW_ATE_signed, "long long int:t8=r8;-9223372036854775808;9223372036854775807;" },
    {   VT_LLONG | VT_UNSIGNED, 8, DW_ATE_unsigned, "long long unsigned int:t9=r9;0;01777777777777777777777;" },
    {   VT_SHORT, 2, DW_ATE_signed, "short int:t10=r10;-32768;32767;" },
    {   VT_SHORT | VT_UNSIGNED, 2, DW_ATE_unsigned, "short unsigned int:t11=r11;0;65535;" },
    {   VT_BYTE | VT_DEFSIGN, 1, DW_ATE_signed_char, "signed char:t12=r12;-128;127;" },
    {   VT_BYTE | VT_DEFSIGN | VT_UNSIGNED, 1, DW_ATE_unsigned_char, "unsigned char:t13=r13;0;255;" },
    {   VT_FLOAT, 4, DW_ATE_float, "float:t14=r1;4;0;" },
    {   VT_DOUBLE, 8, DW_ATE_float, "double:t15=r1;8;0;" },
#جے_تعریف_شدہ TCC_USING_DOUBLE_FOR_LDOUBLE
    {   VT_DOUBLE | VT_LONG, 8, DW_ATE_float, "long double:t16=r1;8;0;" },
#وإلا
    {   VT_LDOUBLE, 16, DW_ATE_float, "long double:t16=r1;16;0;" },
#جے_انت
    {   -1, -1, -1, "_Float32:t17=r1;4;0;" },
    {   -1, -1, -1, "_Float64:t18=r1;8;0;" },
    {   -1, -1, -1, "_Float128:t19=r1;16;0;" },
    {   -1, -1, -1, "_Float32x:t20=r1;8;0;" },
    {   -1, -1, -1, "_Float64x:t21=r1;16;0;" },
    {   -1, -1, -1, "_Decimal32:t22=r1;4;0;" },
    {   -1, -1, -1, "_Decimal64:t23=r1;8;0;" },
    {   -1, -1, -1, "_Decimal128:t24=r1;16;0;" },
    /* if default char is unsigned */
    {   VT_BYTE | VT_UNSIGNED, 1, DW_ATE_unsigned_char, "unsigned char:t25=r25;0;255;" },
    /* boolean type */
    {   VT_BOOL, 1, DW_ATE_boolean, "bool:t26=r26;0;255;" },
#إذا LONG_ناپ == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#وإلا
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#جے_انت
};

#تعریف_کرو	N_DEFAULT_DEBUG	(حجم (default_debug) / حجم (default_debug[0]))

/* dwarf debug */

#تعریف_کرو	DWARF_سطر_ادھار				-5
#تعریف_کرو	DWARF_سطر_RANGE			14
#تعریف_کرو	DWARF_OPCODE_ادھار			13

#إذا defined TCC_نشانہ_ARM64
#تعریف_کرو	DWARF_MIN_INSTR_LEN			4
#وإلاإذا defined TCC_نشانہ_ARM
#تعریف_کرو	DWARF_MIN_INSTR_LEN			2
#وإلا
#تعریف_کرو	DWARF_MIN_INSTR_LEN			1
#جے_انت

#تعریف_کرو	DWARF_ABBREV_COMPILE_UNIT		1
#تعریف_کرو	DWARF_ABBREV_ادھار_TYPE			2
#تعریف_کرو	DWARF_ABBREV_VARIABLE_EXTERNAL		3
#تعریف_کرو	DWARF_ABBREV_VARIABLE_STATIC		4
#تعریف_کرو	DWARF_ABBREV_VARIABLE_LOCAL		5
#تعریف_کرو	DWARF_ABBREV_FORMAL_PARAMETER		6
#تعریف_کرو	DWARF_ABBREV_اشارہ_گر			7
#تعریف_کرو	DWARF_ABBREV_ARRAY_TYPE			8
#تعریف_کرو	DWARF_ABBREV_SUBRANGE_TYPE		9
#تعریف_کرو	DWARF_ABBREV_TYPEDEF			10
#تعریف_کرو	DWARF_ABBREV_ENUMERATOR_SIGNED		11
#تعریف_کرو	DWARF_ABBREV_ENUMERATOR_UNSIGNED	12
#تعریف_کرو	DWARF_ABBREV_ENUMERATION_TYPE		13
#تعریف_کرو	DWARF_ABBREV_MEMBER			14
#تعریف_کرو	DWARF_ABBREV_MEMBER_BF			15
#تعریف_کرو	DWARF_ABBREV_STRUCTURE_TYPE		16
#تعریف_کرو	DWARF_ABBREV_STRUCTURE_خالی_تھاواں_TYPE	17
#تعریف_کرو	DWARF_ABBREV_UNION_TYPE			18
#تعریف_کرو	DWARF_ABBREV_UNION_خالی_تھاواں_TYPE		19
#تعریف_کرو	DWARF_ABBREV_SUBPROGRAM_EXTERNAL	20
#تعریف_کرو	DWARF_ABBREV_SUBPROGRAM_STATIC		21
#تعریف_کرو	DWARF_ABBREV_LEXICAL_بلاک		22
#تعریف_کرو	DWARF_ABBREV_LEXICAL_خالی_تھاواں_بلاک	23
#تعریف_کرو	DWARF_ABBREV_SUBROUTINE_TYPE		24
#تعریف_کرو	DWARF_ABBREV_SUBROUTINE_خالی_تھاواں_TYPE	25
#تعریف_کرو	DWARF_ABBREV_FORMAL_PARAMETER2		26

/* all entries should have been generated with dwarf_uleb128 except
   has_children. All values are currently below 128 so this currently
   works.  */
ساكن ثابت بنانشانی حرف dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_ٹیگ_compile_unit, 1,
          DW_AT_پیداکار, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_سطر_strp,
          DW_AT_comp_dir, DW_FORM_سطر_strp,
          DW_AT_کم_pc, DW_FORM_addr,
#إذا PTR_ناپ == 4
          DW_AT_بلند_pc, DW_FORM_data4,
#وإلا
          DW_AT_بلند_pc, DW_FORM_data8,
#جے_انت
          DW_AT_stmt_list, DW_FORM_sec_وتھ,
          0, 0,
    DWARF_ABBREV_ادھار_TYPE, DW_ٹیگ_ادھار_type, 0,
          DW_AT_byte_ناپ, DW_FORM_udata,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_name, DW_FORM_strp,
          0, 0,
    DWARF_ABBREV_VARIABLE_EXTERNAL, DW_ٹیگ_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_ٹیگ_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_LOCAL, DW_ٹیگ_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER, DW_ٹیگ_formal_parameter, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_اشارہ_گر, DW_ٹیگ_اشارہ_گر_type, 0,
          DW_AT_byte_ناپ, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ARRAY_TYPE, DW_ٹیگ_array_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBRANGE_TYPE, DW_ٹیگ_subrange_type, 0,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_اتلا_bound, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_TYPEDEF, DW_ٹیگ_typedef, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_ٹیگ_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_قدر, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_ٹیگ_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_قدر, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_ٹیگ_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_ناپ, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_ٹیگ_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_انکڑے_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_ٹیگ_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ثنائی_ہندسہ_ناپ, DW_FORM_udata,
          DW_AT_انکڑے_ثنائی_ہندسہ_وتھ, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_ٹیگ_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_ناپ, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_خالی_تھاواں_TYPE, DW_ٹیگ_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_ناپ, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_ٹیگ_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_ناپ, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_خالی_تھاواں_TYPE, DW_ٹیگ_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_ناپ, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_ٹیگ_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_کم_pc, DW_FORM_addr,
#إذا PTR_ناپ == 4
          DW_AT_بلند_pc, DW_FORM_data4,
#وإلا
          DW_AT_بلند_pc, DW_FORM_data8,
#جے_انت
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_چوکھٹا_ادھار, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_ٹیگ_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_کم_pc, DW_FORM_addr,
#إذا PTR_ناپ == 4
          DW_AT_بلند_pc, DW_FORM_data4,
#وإلا
          DW_AT_بلند_pc, DW_FORM_data8,
#جے_انت
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_چوکھٹا_ادھار, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_بلاک, DW_ٹیگ_lexical_بلاک, 1,
          DW_AT_کم_pc, DW_FORM_addr,
#إذا PTR_ناپ == 4
          DW_AT_بلند_pc, DW_FORM_data4,
#وإلا
          DW_AT_بلند_pc, DW_FORM_data8,
#جے_انت
          0, 0,
    DWARF_ABBREV_LEXICAL_خالی_تھاواں_بلاک, DW_ٹیگ_lexical_بلاک, 0,
          DW_AT_کم_pc, DW_FORM_addr,
#إذا PTR_ناپ == 4
          DW_AT_بلند_pc, DW_FORM_data4,
#وإلا
          DW_AT_بلند_pc, DW_FORM_data8,
#جے_انت
          0, 0,
    DWARF_ABBREV_SUBROUTINE_TYPE, DW_ٹیگ_subroutine_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBROUTINE_خالی_تھاواں_TYPE, DW_ٹیگ_subroutine_type, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER2, DW_ٹیگ_formal_parameter, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
  0
};

ساكن ثابت بنانشانی حرف dwarf_سطر_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#تعریف_کرو N_STR_HASH (251)

بنية dwarf_str_hash {
    صحيح len;
    بنانشانی لما انکڑے_وتھ;
    بنية dwarf_str_hash *اگلا;
};

بنية _tccdbg {

    صحيح آخری_سطر_عدد, new_file;
    صحيح section_sym;

    صحيح debug_اگلا_type;

    بنية _debug_hash {
        صحيح debug_type;
        Sym *type;
    } *debug_hash_global, *debug_hash_local;

    /* store forward structure/unions types */
    بنية _debug_forw_hash {
        Sym *type;
        صحيح n_debug_type;
        صحيح *debug_type;
    } *debug_forw_hash_global, *debug_forw_hash_local;

    صحيح n_debug_hash_global;
    صحيح n_debug_hash_local;
    صحيح n_debug_forw_hash_global;
    صحيح n_debug_forw_hash_local;

    بنية _debug_info {
        صحيح شروع;
        صحيح سرا;
        صحيح آخری_debug_hash;
        صحيح آخری_debug_forw_hash;
        صحيح n_sym;
        بنية debug_sym {
            صحيح type;
            بنانشانی لما قدر;
            حرف *str;
            Section *sec;
            صحيح sym_اشاریہ;
            صحيح info;
            صحيح file;
            صحيح سطر;
        } *sym;
        بنية _debug_info *بچہ, *اگلا, *آخری, *ماپا;
    } *debug_info, *debug_info_جڑ;

    بنية {
        صحيح info;
        صحيح abbrev;
        صحيح سطر;
        صحيح str;
        صحيح سطر_str;
    } dwarf_sym;

    بنية {
        صحيح شروع;
        صحيح dir_ناپ;
        حرف **dir_جدول;
        صحيح filename_ناپ;
        بنية dwarf_filename_struct {
            صحيح dir_اندراج;
            حرف *name;
        } *filename_جدول;
        صحيح سطر_ناپ;
        صحيح سطر_max_ناپ;
        بنانشانی حرف *سطر_انکڑے;
        صحيح cur_file;
        صحيح آخری_file;
        صحيح آخری_pc;
        صحيح آخری_سطر;
    } dwarf_سطر;

    بنية {
        صحيح شروع;
        Sym *func;
        صحيح سطر;
        صحيح ادھار_type_ورتیا[N_DEFAULT_DEBUG];
    } dwarf_info;

    بنية dwarf_str_hash *dwarf_str[N_STR_HASH];
    بنية dwarf_str_hash *dwarf_سطر_str[N_STR_HASH];

    /* test coverage */
    بنية {
        بنانشانی لما وتھ;
        بنانشانی لما آخری_file_name;
        بنانشانی لما آخری_func_name;
        صحيح ind;
        صحيح سطر;
    } tcov_انکڑے;
};

#تعریف_کرو آخری_سطر_عدد             s1->dState->آخری_سطر_عدد
#تعریف_کرو new_file                  s1->dState->new_file
#تعریف_کرو section_sym               s1->dState->section_sym
#تعریف_کرو debug_اگلا_type           s1->dState->debug_اگلا_type
#تعریف_کرو debug_hash_global         s1->dState->debug_hash_global
#تعریف_کرو debug_hash_local          s1->dState->debug_hash_local
#تعریف_کرو debug_forw_hash_global    s1->dState->debug_forw_hash_global
#تعریف_کرو debug_forw_hash_local     s1->dState->debug_forw_hash_local
#تعریف_کرو n_debug_hash_global       s1->dState->n_debug_hash_global
#تعریف_کرو n_debug_hash_local        s1->dState->n_debug_hash_local
#تعریف_کرو n_debug_forw_hash_global  s1->dState->n_debug_forw_hash_global
#تعریف_کرو n_debug_forw_hash_local   s1->dState->n_debug_forw_hash_local
#تعریف_کرو debug_info                s1->dState->debug_info
#تعریف_کرو debug_info_جڑ           s1->dState->debug_info_جڑ
#تعریف_کرو dwarf_sym                 s1->dState->dwarf_sym
#تعریف_کرو dwarf_سطر                s1->dState->dwarf_سطر
#تعریف_کرو dwarf_info                s1->dState->dwarf_info
#تعریف_کرو dwarf_str                 s1->dState->dwarf_str
#تعریف_کرو dwarf_سطر_str            s1->dState->dwarf_سطر_str
#تعریف_کرو tcov_انکڑے                 s1->dState->tcov_انکڑے

#تعریف_کرو	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
ساكن صحيح put_stabs(TCCState *s1, ثابت حرف *str, صحيح type, صحيح other,
    صحيح desc, بنانشانی لما قدر);

ST_FUNC فراغ tcc_debug_new(TCCState *s1)
{
    صحيح shf = 0;
    إذا (!s1->dState)
        s1->dState = tcc_mallocz(حجم *s1->dState);

#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    إذا (s1->do_debug && s1->output_type == TCC_OUTPUT_حافظہ)
        s1->do_backtrace = 1;
    إذا (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#جے_انت

    إذا (s1->dwarf) {
	صحيح i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	ساكن ثابت حرف *ثابت debug[] = {
	    ".debug_macro",
	    ".debug_loc",
	    ".debug_ranges",
	    ".debug_loclists",
	    ".debug_rnglists",
	    ".debug_str_offsets",
	    ".debug_addr"
	};

        s1->dwlo = s1->nb_sections;
        dwarf_info_section =
	    new_section(s1, ".debug_info", SHT_PROGBITS, shf);
        dwarf_abbrev_section =
	    new_section(s1, ".debug_abbrev", SHT_PROGBITS, shf);
        dwarf_سطر_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	لكل (i = 0; i < حجم(debug)/حجم(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_ملاؤ | SHF_لڑیاں;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_سطر_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	إذا (s1->dwarf >= 5) {
            dwarf_سطر_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_سطر_str_section->sh_entsize = 1;
	    dwarf_سطر_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    وإلا
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = حجم(Stab_Sym);
        stab_section->sh_addralign = حجم ((Stab_Sym*)0)->n_قدر;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
ساكن صحيح put_stabs(TCCState *s1, ثابت حرف *str, صحيح type, صحيح other, صحيح desc,
                      بنانشانی لما قدر)
{
    Stab_Sym *sym;

    بنانشانی وتھ;
    إذا (type == N_SLINE
        && (وتھ = stab_section->انکڑے_وتھ)
        && (sym = (Stab_Sym*)(stab_section->انکڑے + وتھ) - 1)
        && sym->n_type == type
        && sym->n_قدر == قدر) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        أرجع 0;
    }

    sym = section_ptr_جوڑو(stab_section, حجم(Stab_Sym));
    إذا (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } وإلا {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_قدر = قدر;
    أرجع 1;
}

ساكن فراغ put_stabs_r(TCCState *s1, ثابت حرف *str, صحيح type, صحيح other, صحيح desc,
                        بنانشانی لما قدر, Section *sec, صحيح sym_اشاریہ)
{
    إذا (put_stabs(s1, str, type, other, desc, قدر))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->انکڑے_وتھ - 4,
                      حجم ((Stab_Sym*)0)->n_قدر == PTR_ناپ ? R_انکڑے_PTR : R_انکڑے_32,
                      sym_اشاریہ);
}

ساكن فراغ put_stabn(TCCState *s1, صحيح type, صحيح other, صحيح desc, صحيح قدر)
{
    put_stabs(s1, عدم, type, other, desc, قدر);
}

/* ------------------------------------------------------------------------- */
#تعریف_کرو	dwarf_data1(s,انکڑے) \
	(*(uint8_t*)section_ptr_جوڑو((s), 1) = (انکڑے))
#تعریف_کرو	dwarf_data2(s,انکڑے) \
	write16le(section_ptr_جوڑو((s), 2), (انکڑے))
#تعریف_کرو	dwarf_data4(s,انکڑے) \
	write32le(section_ptr_جوڑو((s), 4), (انکڑے))
#تعریف_کرو	dwarf_data8(s,انکڑے) \
	write64le(section_ptr_جوڑو((s), 8), (انکڑے))

ساكن صحيح dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    أرجع put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_عدد, عدم);
}

ساكن فراغ dwarf_reloc(Section *s, صحيح sym, صحيح rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->انکڑے_وتھ, rel, sym, 0);
}

ساكن فراغ free_str(بنية dwarf_str_hash **str)
{
    صحيح i;

    لكل (i = 0; i < N_STR_HASH; i++) {
       طالما (str[i]) {
           بنية dwarf_str_hash *اگلا = str[i]->اگلا;

           tcc_free(str[i]);
           str[i] = اگلا;
       }
    }
}

ساكن بنانشانی str_hash(ثابت حرف *s)
{
    بنانشانی h = 5381;

    طالما (*s)
       h += (*s++ & 0xffu) + h * 31;
    أرجع h;
}

ساكن فراغ dwarf_string(Section *s, Section *dw, صحيح sym, ثابت حرف *str)
{
    TCCState *s1 = s->s1;
    صحيح len, hash = str_hash(str) % N_STR_HASH;
    حرف *ptr;
    بنية dwarf_str_hash *new_hash;
    بنية dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_سطر_str;

    len = لڑی_لمبائی(str) + 1;
    new_hash = dw_hash[hash];
    طالما (new_hash) {
	إذا (new_hash->len == len &&
	    !memcmp(str, dw->انکڑے + new_hash->انکڑے_وتھ, len))
	    اكسر;
	new_hash = new_hash->اگلا;
    }
    إذا (new_hash == عدم) {
	بنانشانی لما وتھ = dw->انکڑے_وتھ;

        new_hash = dw_hash[hash];
        طالما (new_hash) {
	    بنانشانی لما n = new_hash->انکڑے_وتھ + new_hash->len - len;

	    إذا (new_hash->len > len &&
	        !memcmp(str, dw->انکڑے + n, len)) {
		وتھ = n;
		اكسر;
	    }
	    new_hash = new_hash->اگلا;
        }
	إذا (new_hash == عدم) {
	    ptr = section_ptr_جوڑو(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (بنية dwarf_str_hash *)
	    tcc_malloc(حجم(بنية dwarf_str_hash));
	new_hash->len = len;
	new_hash->انکڑے_وتھ = وتھ;
	new_hash->اگلا = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->انکڑے_وتھ, R_انکڑے_32_DW, sym,
                   PTR_ناپ == 4 ? 0 : new_hash->انکڑے_وتھ);
    dwarf_data4(s, PTR_ناپ == 4 ? new_hash->انکڑے_وتھ : 0);
}

ساكن فراغ dwarf_strp(Section *s, ثابت حرف *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

ساكن فراغ dwarf_سطر_strp(Section *s, ثابت حرف *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_سطر_str_section, dwarf_sym.سطر_str, str);
}

ساكن فراغ dwarf_سطر_op(TCCState *s1, بنانشانی حرف op)
{
    إذا (dwarf_سطر.سطر_ناپ >= dwarf_سطر.سطر_max_ناپ) {
	dwarf_سطر.سطر_max_ناپ += 1024;
	dwarf_سطر.سطر_انکڑے =
	    (بنانشانی حرف *)tcc_realloc(dwarf_سطر.سطر_انکڑے,
					 dwarf_سطر.سطر_max_ناپ);
    }
    dwarf_سطر.سطر_انکڑے[dwarf_سطر.سطر_ناپ++] = op;
}

ساكن فراغ dwarf_file(TCCState *s1)
{
    صحيح i, j;
    حرف *filename;
    صحيح اشاریہ_وتھ = s1->dwarf < 5;

    إذا (!strcmp(file->filename, "<command line>")) {
        dwarf_سطر.cur_file = 1;
	أرجع;
    }
    filename = strrchr(file->filename, '/');
    إذا (filename == عدم) {
        لكل (i = 1; i < dwarf_سطر.filename_ناپ; i++)
            إذا (dwarf_سطر.filename_جدول[i].dir_اندراج == 0 &&
		strcmp(dwarf_سطر.filename_جدول[i].name,
		       file->filename) == 0) {
		    dwarf_سطر.cur_file = i + اشاریہ_وتھ;
	            أرجع;
		}
	i = -اشاریہ_وتھ;
	filename = file->filename;
    }
    وإلا {
	حرف *undo = filename;
	حرف *dir = file->filename;

	*filename++ = '\0';
        لكل (i = 0; i < dwarf_سطر.dir_ناپ; i++)
	    إذا (strcmp(dwarf_سطر.dir_جدول[i], dir) == 0) {
		لكل (j = 1; j < dwarf_سطر.filename_ناپ; j++)
		    إذا (dwarf_سطر.filename_جدول[j].dir_اندراج - اشاریہ_وتھ
			== i &&
			strcmp(dwarf_سطر.filename_جدول[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_سطر.cur_file = j + اشاریہ_وتھ;
			أرجع;
		    }
		اكسر;
	    }
	إذا (i == dwarf_سطر.dir_ناپ) {
	    dwarf_سطر.dir_ناپ++;
	    dwarf_سطر.dir_جدول =
                (حرف **) tcc_realloc(dwarf_سطر.dir_جدول,
                                      dwarf_سطر.dir_ناپ *
                                      حجم (حرف *));
            dwarf_سطر.dir_جدول[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_سطر.filename_جدول =
        (بنية dwarf_filename_struct *)
        tcc_realloc(dwarf_سطر.filename_جدول,
                    (dwarf_سطر.filename_ناپ + 1) *
                    حجم (بنية dwarf_filename_struct));
    dwarf_سطر.filename_جدول[dwarf_سطر.filename_ناپ].dir_اندراج =
	i + اشاریہ_وتھ;
    dwarf_سطر.filename_جدول[dwarf_سطر.filename_ناپ].name =
        tcc_strdup(filename);
    dwarf_سطر.cur_file = dwarf_سطر.filename_ناپ++ + اشاریہ_وتھ;
    أرجع;
}

#إذا 0
ساكن صحيح dwarf_uleb128_ناپ (بنانشانی لما لما قدر)
{
    صحيح ناپ =  0;

    افعل {
        قدر >>= 7;
        ناپ++;
    } طالما (قدر != 0);
    أرجع ناپ;
}
#جے_انت

ساكن صحيح dwarf_sleb128_ناپ (لما لما قدر)
{
    صحيح ناپ =  0;
    لما لما سرا = قدر >> 63;
    بنانشانی حرف آخری = سرا & 0x40;
    بنانشانی حرف byte;

    افعل {
        byte = قدر & 0x7f;
        قدر >>= 7;
        ناپ++;
    } طالما (قدر != سرا || (byte & 0x40) != آخری);
    أرجع ناپ;
}

ساكن فراغ dwarf_uleb128 (Section *s, بنانشانی لما لما قدر)
{
    افعل {
        بنانشانی حرف byte = قدر & 0x7f;

        قدر >>= 7;
        dwarf_data1(s, byte | (قدر ? 0x80 : 0));
    } طالما (قدر != 0);
}

ساكن فراغ dwarf_sleb128 (Section *s, لما لما قدر)
{
    صحيح ہور;
    لما لما سرا = قدر >> 63;
    بنانشانی حرف آخری = سرا & 0x40;

    افعل {
        بنانشانی حرف byte = قدر & 0x7f;

        قدر >>= 7;
	ہور = قدر != سرا || (byte & 0x40) != آخری;
        dwarf_data1(s, byte | (0x80 * ہور));
    } طالما (ہور);
}

ساكن فراغ dwarf_uleb128_op (TCCState *s1, بنانشانی لما لما قدر)
{
    افعل {
        بنانشانی حرف byte = قدر & 0x7f;

        قدر >>= 7;
        dwarf_سطر_op(s1, byte | (قدر ? 0x80 : 0));
    } طالما (قدر != 0);
}

ساكن فراغ dwarf_sleb128_op (TCCState *s1, لما لما قدر)
{
    صحيح ہور;
    لما لما سرا = قدر >> 63;
    بنانشانی حرف آخری = سرا & 0x40;

    افعل {
        بنانشانی حرف byte = قدر & 0x7f;

        قدر >>= 7;
        ہور = قدر != سرا || (byte & 0x40) != آخری;
        dwarf_سطر_op(s1, byte | (0x80 * ہور));
    } طالما (ہور);
}

#إذا TCC_EH_چوکھٹا
ST_FUNC فراغ tcc_eh_چوکھٹا_شروع(TCCState *s1)
{
    إذا (!s1->unwind_tables)
        أرجع;
    eh_چوکھٹا_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_شروع = eh_چوکھٹا_section->انکڑے_وتھ;
    dwarf_data4(eh_چوکھٹا_section, 0); //لمائی
    dwarf_data4(eh_چوکھٹا_section, 0); // CIE ID
    dwarf_data1(eh_چوکھٹا_section, 1); //نسخہ
    dwarf_data1(eh_چوکھٹا_section, 'z'); // Augmentation String
    dwarf_data1(eh_چوکھٹا_section, 'R');
    dwarf_data1(eh_چوکھٹا_section, 0);
#إذا defined TCC_نشانہ_I386
    dwarf_uleb128(eh_چوکھٹا_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_چوکھٹا_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_چوکھٹا_section, 8); // return address column
    dwarf_uleb128(eh_چوکھٹا_section, 1); // Augmentation len
    dwarf_data1(eh_چوکھٹا_section, FDE_ENCODING);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 4); // r4 (esp)
    dwarf_uleb128(eh_چوکھٹا_section, 4); // ofs 4
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_وتھ + 8); // r8 (eip)
    dwarf_uleb128(eh_چوکھٹا_section, 1); // cfa-4
#وإلاإذا defined TCC_نشانہ_X86_64
    dwarf_uleb128(eh_چوکھٹا_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_چوکھٹا_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_چوکھٹا_section, 16); // return address column
    dwarf_uleb128(eh_چوکھٹا_section, 1); // Augmentation len
    dwarf_data1(eh_چوکھٹا_section, FDE_ENCODING);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_چوکھٹا_section, 8); // ofs 8
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_وتھ + 16); // r16 (rip)
    dwarf_uleb128(eh_چوکھٹا_section, 1); // cfa-8
#وإلاإذا defined TCC_نشانہ_ARM
    /* TODO: arm must be compiled with: -funwind-tables */
    /* arm also uses .ARM.extab and .ARM.exidx sections */
    dwarf_uleb128(eh_چوکھٹا_section, 2); // code_alignment_factor
    dwarf_sleb128(eh_چوکھٹا_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_چوکھٹا_section, 14); // return address column
    dwarf_uleb128(eh_چوکھٹا_section, 1); // Augmentation len
    dwarf_data1(eh_چوکھٹا_section, FDE_ENCODING);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 13); // r13 (sp)
    dwarf_uleb128(eh_چوکھٹا_section, 0); // ofs 0
#وإلاإذا defined TCC_نشانہ_ARM64
    dwarf_uleb128(eh_چوکھٹا_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_چوکھٹا_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_چوکھٹا_section, 30); // return address column
    dwarf_uleb128(eh_چوکھٹا_section, 1); // Augmentation len
    dwarf_data1(eh_چوکھٹا_section, FDE_ENCODING);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 31); // x31 (sp)
    dwarf_uleb128(eh_چوکھٹا_section, 0); // ofs 0
#وإلاإذا defined TCC_نشانہ_RISCV64
    eh_چوکھٹا_section->انکڑے[s1->eh_شروع + 8] = 3; // version = 3
    dwarf_uleb128(eh_چوکھٹا_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_چوکھٹا_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_چوکھٹا_section, 1); // return address column
    dwarf_uleb128(eh_چوکھٹا_section, 1); // Augmentation len
    dwarf_data1(eh_چوکھٹا_section, FDE_ENCODING);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 2); // r2 (sp)
    dwarf_uleb128(eh_چوکھٹا_section, 0); // ofs 0
#جے_انت
    طالما ((eh_چوکھٹا_section->انکڑے_وتھ - s1->eh_شروع) & 3)
	dwarf_data1(eh_چوکھٹا_section, DW_CFA_nop);
    write32le(eh_چوکھٹا_section->انکڑے + s1->eh_شروع, //لمائی
	      eh_چوکھٹا_section->انکڑے_وتھ - s1->eh_شروع - 4);
}

ساكن فراغ tcc_debug_چوکھٹا_سرا(TCCState *s1, صحيح ناپ)
{
    صحيح eh_section_sym;
    بنانشانی لما fde_شروع;

    إذا (!eh_چوکھٹا_section)
	أرجع;
    eh_section_sym = dwarf_get_section_sym(متن_section);
    fde_شروع = eh_چوکھٹا_section->انکڑے_وتھ;
    dwarf_data4(eh_چوکھٹا_section, 0); //لمائی
    dwarf_data4(eh_چوکھٹا_section,
		fde_شروع - s1->eh_شروع + 4); // CIE Pointer
#إذا defined TCC_نشانہ_I386
    dwarf_reloc(eh_چوکھٹا_section, eh_section_sym, R_386_PC32);
#وإلاإذا defined TCC_نشانہ_X86_64
    dwarf_reloc(eh_چوکھٹا_section, eh_section_sym, R_X86_64_PC32);
#وإلاإذا defined TCC_نشانہ_ARM
    dwarf_reloc(eh_چوکھٹا_section, eh_section_sym, R_ARM_REL32);
#وإلاإذا defined TCC_نشانہ_ARM64
    dwarf_reloc(eh_چوکھٹا_section, eh_section_sym, R_AARCH64_PREL32);
#وإلاإذا defined TCC_نشانہ_RISCV64
    dwarf_reloc(eh_چوکھٹا_section, eh_section_sym, R_RISCV_32_PCREL);
#جے_انت
    dwarf_data4(eh_چوکھٹا_section, func_ind); // PC Begin
    dwarf_data4(eh_چوکھٹا_section, ناپ); // PC Range
    dwarf_data1(eh_چوکھٹا_section, 0); // Augmentation Length
#إذا defined TCC_نشانہ_I386
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_وتھ);
    dwarf_uleb128(eh_چوکھٹا_section, 8);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_وتھ + 5); // r5 (ebp)
    dwarf_uleb128(eh_چوکھٹا_section, 2); // cfa-8
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_رجسٹر);
    dwarf_uleb128(eh_چوکھٹا_section, 5); // r5 (ebp)
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکھٹا_section, ناپ - 5);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_restore + 5); // r5 (ebp)
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 4); // r4 (esp)
    dwarf_uleb128(eh_چوکھٹا_section, 4); // ofs 4
#وإلاإذا defined TCC_نشانہ_X86_64
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_وتھ);
    dwarf_uleb128(eh_چوکھٹا_section, 16);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_وتھ + 6); // r6 (rbp)
    dwarf_uleb128(eh_چوکھٹا_section, 2); // cfa-16
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_رجسٹر);
    dwarf_uleb128(eh_چوکھٹا_section, 6); // r6 (rbp)
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکھٹا_section, ناپ - 5);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_چوکھٹا_section, 8); // ofs 8
#وإلاإذا defined TCC_نشانہ_ARM
    /* TODO */
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_وتھ);
    dwarf_uleb128(eh_چوکھٹا_section, 8);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_وتھ + 14); // r14 (lr)
    dwarf_uleb128(eh_چوکھٹا_section, 1);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_وتھ + 11); // r11 (fp)
    dwarf_uleb128(eh_چوکھٹا_section, 2);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکھٹا_section, ناپ / 2 - 5);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_رجسٹر);
    dwarf_uleb128(eh_چوکھٹا_section, 11); // r11 (fp)
#وإلاإذا defined TCC_نشانہ_ARM64
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_وتھ);
    dwarf_uleb128(eh_چوکھٹا_section, 224);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_وتھ + 29); // x29 (fp)
    dwarf_uleb128(eh_چوکھٹا_section, 28); // cfa-224
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_وتھ + 30); // x30 (lr)
    dwarf_uleb128(eh_چوکھٹا_section, 27); // cfa-216
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_وتھ);
    dwarf_uleb128(eh_چوکھٹا_section, 224 + ((-loc + 15) & ~15));
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکھٹا_section, ناپ / 4 - 5);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_restore + 30); // x30 (lr)
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_restore + 29); // x29 (fp)
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_وتھ);
    dwarf_uleb128(eh_چوکھٹا_section, 0);
#وإلاإذا defined TCC_نشانہ_RISCV64
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_وتھ);
    dwarf_uleb128(eh_چوکھٹا_section, 16); // ofs 16
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_وتھ + 1); // r1 (ra, lr)
    dwarf_uleb128(eh_چوکھٹا_section, 2); // cfa-8
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_وتھ + 8); // r8 (s0, fp)
    dwarf_uleb128(eh_چوکھٹا_section, 4); // cfa-16
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 8); // r8 (s0, fp)
    dwarf_uleb128(eh_چوکھٹا_section, 0); // ofs 0
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc4);
    طالما (ناپ >= 4 &&
	   read32le(cur_متن_section->انکڑے + func_ind + ناپ - 4) != 0x00008067)
	ناپ -= 4;
    dwarf_data4(eh_چوکھٹا_section, ناپ - 36);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 2); // r2 (r2, sp)
    dwarf_uleb128(eh_چوکھٹا_section, 16); // ofs 16
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_restore + 1); // r1 (lr)
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_restore + 8); // r8 (s0, fp)
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_وتھ);
    dwarf_uleb128(eh_چوکھٹا_section, 0); // ofs 0
#جے_انت
    طالما ((eh_چوکھٹا_section->انکڑے_وتھ - fde_شروع) & 3)
	dwarf_data1(eh_چوکھٹا_section, DW_CFA_nop);
    write32le(eh_چوکھٹا_section->انکڑے + fde_شروع, //لمائی
	      eh_چوکھٹا_section->انکڑے_وتھ - fde_شروع - 4);
}

ST_FUNC فراغ tcc_eh_چوکھٹا_سرا(TCCState *s1)
{
    إذا (!eh_چوکھٹا_section)
	أرجع;
    dwarf_data4(eh_چوکھٹا_section, 0);
}

بنية eh_تلاش_جدول {
    uint32_t pc_وتھ;
    uint32_t fde_وتھ;
};

ساكن صحيح ترتیب_دیو_eh_جدول(ثابت فراغ *a, ثابت فراغ *b)
{
    uint32_t pc1 = ((ثابت بنية eh_تلاش_جدول *)a)->pc_وتھ;
    uint32_t pc2 = ((ثابت بنية eh_تلاش_جدول *)b)->pc_وتھ;

    أرجع pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC فراغ tcc_eh_چوکھٹا_hdr(TCCState *s1, صحيح final)
{
    صحيح گنتی_2 = 0, وتھ;
    بنانشانی لما گنتی_وتھ, tab_وتھ;
    بنانشانی حرف *ln, *سرا;
    بنانشانی صحيح آخری_cie_وتھ = 0xffffffff;

    إذا (!eh_چوکھٹا_section || !eh_چوکھٹا_section->انکڑے_وتھ)
	أرجع;
    إذا (final && !eh_چوکھٹا_hdr_section)
	أرجع;
    إذا (final == 0)
        eh_چوکھٹا_hdr_section =
	    new_section(s1, ".eh_frame_hdr", SHT_PROGBITS, SHF_ALLOC);
    eh_چوکھٹا_hdr_section->انکڑے_وتھ = 0;
    dwarf_data1(eh_چوکھٹا_hdr_section, 1); //نسخہ
    // Pointer Encoding Format
    dwarf_data1(eh_چوکھٹا_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_pcrel);
    // Count Encoding Format
    dwarf_data1(eh_چوکھٹا_hdr_section, DW_EH_PE_udata4 | DW_EH_PE_absptr);
    // Table Encoding Format
    dwarf_data1(eh_چوکھٹا_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_datarel);
    وتھ = eh_چوکھٹا_section->sh_addr -
             eh_چوکھٹا_hdr_section->sh_addr -
             eh_چوکھٹا_hdr_section->انکڑے_وتھ;
    dwarf_data4(eh_چوکھٹا_hdr_section, وتھ); // eh_frame_ptr
    //گنتی
    گنتی_وتھ = eh_چوکھٹا_hdr_section->انکڑے_وتھ;
    dwarf_data4(eh_چوکھٹا_hdr_section, 0);
    tab_وتھ = eh_چوکھٹا_hdr_section->انکڑے_وتھ;
    ln = eh_چوکھٹا_section->انکڑے;
    سرا = eh_چوکھٹا_section->انکڑے + eh_چوکھٹا_section->انکڑے_وتھ;
    طالما (ln < سرا) {
	بنانشانی حرف *fde = ln, *rd = ln;
	بنانشانی صحيح cie_وتھ, نسخہ, لمائی = dwarf_read_4(rd, سرا);
	بنانشانی صحيح pc_وتھ, fde_وتھ;

	إذا (لمائی == 0)
	    اذهب اگلا;
        cie_وتھ = dwarf_read_4(rd, سرا);
	إذا (cie_وتھ == 0)
	    اذهب اگلا;
	إذا (cie_وتھ != آخری_cie_وتھ) {
	    بنانشانی حرف *cie = rd - cie_وتھ + 4;

	    إذا (cie < eh_چوکھٹا_section->انکڑے)
		اذهب اگلا;
	    نسخہ = dwarf_read_1(cie, سرا);
	    إذا ((نسخہ == 1 || نسخہ == 3) &&
	        dwarf_read_1(cie, سرا) == 'z' && // Augmentation String
		dwarf_read_1(cie, سرا) == 'R' &&
		dwarf_read_1(cie, سرا) == 0) {
	        dwarf_read_uleb128(&cie, سرا); // code_alignment_factor
	        dwarf_read_sleb128(&cie, سرا); // data_alignment_factor
		dwarf_read_1(cie, سرا); // return address column
		إذا (dwarf_read_uleb128(&cie, سرا) == 1 &&
		    dwarf_read_1(cie, سرا) == FDE_ENCODING) {
		    آخری_cie_وتھ = cie_وتھ;
		}
		وإلا
		    اذهب اگلا;
	    }
	    وإلا
		اذهب اگلا;
	}
	گنتی_2++;
	fde_وتھ = eh_چوکھٹا_section->sh_addr +
		     (fde - eh_چوکھٹا_section->انکڑے) -
		     eh_چوکھٹا_hdr_section->sh_addr;
	pc_وتھ = dwarf_read_4(rd, سرا) + fde_وتھ + 8;
	dwarf_data4(eh_چوکھٹا_hdr_section, pc_وتھ);
	dwarf_data4(eh_چوکھٹا_hdr_section, fde_وتھ);
اگلا:
	ln += لمائی + 4;
    }
    add32le(eh_چوکھٹا_hdr_section->انکڑے + گنتی_وتھ, گنتی_2);
    qsort(eh_چوکھٹا_hdr_section->انکڑے + tab_وتھ, گنتی_2,
	  حجم(بنية eh_تلاش_جدول), ترتیب_دیو_eh_جدول);
}
#جے_انت

/* start of translation unit info */
ST_FUNC فراغ tcc_debug_شروع(TCCState *s1)
{
    صحيح i;
    حرف buf[512];
    حرف *filename;

    /* we might currently #include the <command-line> */
    filename = file->prev ? file->prev->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    إذا (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, متن_section->انکڑے_وتھ, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            متن_section->sh_عدد, "$a");

        new_file = آخری_سطر_عدد = 0;
        debug_اگلا_type = N_DEFAULT_DEBUG;
        debug_hash_global = عدم;
        debug_hash_local = عدم;
        debug_forw_hash_global = عدم;
        debug_forw_hash_local = عدم;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, حجم(buf));
#جے_تعریف_شدہ _WIN32
        normalize_slashes(buf);
#جے_انت

        إذا (s1->dwarf) {
            صحيح شروع_abbrev;
            بنانشانی حرف *ptr;
	    حرف *undo;

            /* dwarf_abbrev */
            شروع_abbrev = dwarf_abbrev_section->انکڑے_وتھ;
            ptr = section_ptr_جوڑو(dwarf_abbrev_section, حجم(dwarf_abbrev_init));
            حافظہ_نقل(ptr, dwarf_abbrev_init, حجم(dwarf_abbrev_init));

            إذا (s1->dwarf < 5) {
    	        طالما (*ptr) {
    	            ptr += 3;
    	            طالما (*ptr) {
    	                إذا (ptr[1] == DW_FORM_سطر_strp)
    		            ptr[1] = DW_FORM_strp;
		        إذا (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    إذا  (ptr[1] == DW_FORM_sec_وتھ)
			         ptr[1] = DW_FORM_data4;
			    /* This code uses only size < 0x80 so these are
			       compatible. */
			    إذا  (ptr[1] == DW_FORM_exprloc)
			         ptr[1] = DW_FORM_block1;
			}
    	                ptr += 2;
    	            }
		    ptr += 2;
    	        }
            }

            dwarf_sym.info = dwarf_get_section_sym(dwarf_info_section);
            dwarf_sym.abbrev = dwarf_get_section_sym(dwarf_abbrev_section);
            dwarf_sym.سطر = dwarf_get_section_sym(dwarf_سطر_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            إذا (tcc_state->dwarf >= 5)
    	        dwarf_sym.سطر_str = dwarf_get_section_sym(dwarf_سطر_str_section);
            وإلا {
    	        dwarf_سطر_str_section = dwarf_str_section;
                dwarf_sym.سطر_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(متن_section);

            /* dwarf_info */
            dwarf_info.شروع = dwarf_info_section->انکڑے_وتھ;
            dwarf_data4(dwarf_info_section, 0); //ناپ
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            إذا (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_ناپ);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_انکڑے_32_DW);
                dwarf_data4(dwarf_info_section, شروع_abbrev);
            }
            وإلا {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_انکڑے_32_DW);
                dwarf_data4(dwarf_info_section, شروع_abbrev);
                dwarf_data1(dwarf_info_section, PTR_ناپ);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_نسخہ);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_سطر_strp(dwarf_info_section, filename);
            dwarf_سطر_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_انکڑے_PTR);
#إذا PTR_ناپ == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#وإلا
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#جے_انت
            dwarf_reloc(dwarf_info_section, dwarf_sym.سطر, R_انکڑے_32_DW);
            dwarf_data4(dwarf_info_section, dwarf_سطر_section->انکڑے_وتھ); // stmt_list

            /* dwarf_line */
            dwarf_سطر.شروع = dwarf_سطر_section->انکڑے_وتھ;
            dwarf_data4(dwarf_سطر_section, 0); //لمائی
            dwarf_data2(dwarf_سطر_section, s1->dwarf); // version
            إذا (s1->dwarf >= 5) {
                dwarf_data1(dwarf_سطر_section, PTR_ناپ); // address size
                dwarf_data1(dwarf_سطر_section, 0); // segment selector
            }
            dwarf_data4(dwarf_سطر_section, 0); // prologue Length
            dwarf_data1(dwarf_سطر_section, DWARF_MIN_INSTR_LEN);
            إذا (s1->dwarf >= 4)
                dwarf_data1(dwarf_سطر_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_سطر_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_سطر_section, DWARF_سطر_ادھار);
            dwarf_data1(dwarf_سطر_section, DWARF_سطر_RANGE);
            dwarf_data1(dwarf_سطر_section, DWARF_OPCODE_ادھار);
            ptr = section_ptr_جوڑو(dwarf_سطر_section, حجم(dwarf_سطر_opcodes));
            حافظہ_نقل(ptr, dwarf_سطر_opcodes, حجم(dwarf_سطر_opcodes));
	    undo = strrchr(filename, '/');
	    إذا (undo)
		*undo = 0;
            dwarf_سطر.dir_ناپ = 1 + (undo != عدم);
            dwarf_سطر.dir_جدول = (حرف **) tcc_malloc(حجم (حرف *) *
							dwarf_سطر.dir_ناپ);
            dwarf_سطر.dir_جدول[0] = tcc_strdup(buf);
	    إذا (undo)
                dwarf_سطر.dir_جدول[1] = tcc_strdup(filename);
            dwarf_سطر.filename_ناپ = 2;
            dwarf_سطر.filename_جدول =
    	        (بنية dwarf_filename_struct *)
    	        tcc_malloc(2*حجم (بنية dwarf_filename_struct));
            dwarf_سطر.filename_جدول[0].dir_اندراج = 0;
	    إذا (undo) {
                dwarf_سطر.filename_جدول[0].name = tcc_strdup(undo + 1);
                dwarf_سطر.filename_جدول[1].dir_اندراج = 1;
                dwarf_سطر.filename_جدول[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    وإلا {
                dwarf_سطر.filename_جدول[0].name = tcc_strdup(filename);
                dwarf_سطر.filename_جدول[1].dir_اندراج = 0;
                dwarf_سطر.filename_جدول[1].name = tcc_strdup(filename);
	    }
            dwarf_سطر.سطر_ناپ = dwarf_سطر.سطر_max_ناپ = 0;
            dwarf_سطر.سطر_انکڑے = عدم;
            dwarf_سطر.cur_file = 1;
            dwarf_سطر.آخری_file = 0;
            dwarf_سطر.آخری_pc = 0;
            dwarf_سطر.آخری_سطر = 1;
            dwarf_سطر_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_ناپ); // extended size
            dwarf_سطر_op(s1, DW_LNE_سیٹ_پتہ);
            لكل (i = 0; i < PTR_ناپ; i++)
    	        dwarf_سطر_op(s1, 0);
            memset(&dwarf_info.ادھار_type_ورتیا, 0, حجم(dwarf_info.ادھار_type_ورتیا));
        }
        وإلا
        {
            /* file info: full path + filename */
            pstrcat(buf, حجم(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      متن_section->sh_عدد, عدم);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        متن_section->انکڑے_وتھ, متن_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        متن_section->انکڑے_وتھ, متن_section, section_sym);
            لكل (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

ساكن فراغ fix_debug_forw_hash(TCCState *s1, صحيح global, صحيح شروع);

/* put end of translation unit info */
ST_FUNC فراغ tcc_debug_سرا(TCCState *s1)
{

    إذا (!s1->do_debug || debug_اگلا_type == 0)
        أرجع;

    إذا (debug_info_جڑ)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    إذا (s1->dwarf) {
	صحيح i;
	صحيح شروع_aranges;
	بنانشانی حرف *ptr;
	صحيح متن_ناپ = متن_section->انکڑے_وتھ;

	/* dwarf_info */
	fix_debug_forw_hash(s1, 0, 0);
	fix_debug_forw_hash(s1, 1, 0);
	dwarf_data1(dwarf_info_section, 0);
	ptr = dwarf_info_section->انکڑے + dwarf_info.شروع;
	write32le(ptr, dwarf_info_section->انکڑے_وتھ - dwarf_info.شروع - 4);
	write32le(ptr + 25 + (s1->dwarf >= 5) + PTR_ناپ, متن_ناپ);

	/* dwarf_aranges */
	شروع_aranges = dwarf_aranges_section->انکڑے_وتھ;
	dwarf_data4(dwarf_aranges_section, 0); //ناپ
	dwarf_data2(dwarf_aranges_section, 2); // version
	dwarf_reloc(dwarf_aranges_section, dwarf_sym.info, R_انکڑے_32_DW);
	dwarf_data4(dwarf_aranges_section, 0); // dwarf_info
#إذا PTR_ناپ == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#وإلا
	dwarf_data1(dwarf_aranges_section, 8); // address size
#جے_انت
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_انکڑے_PTR);
#إذا PTR_ناپ == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, متن_ناپ); //سرا
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#وإلا
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, متن_ناپ); //سرا
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#جے_انت
	ptr = dwarf_aranges_section->انکڑے + شروع_aranges;
	write32le(ptr, dwarf_aranges_section->انکڑے_وتھ - شروع_aranges - 4);

	/* dwarf_line */
	إذا (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_سطر_section, 1); /*خانہ*/
	    dwarf_uleb128(dwarf_سطر_section, DW_LNCT_رستہ);
	    dwarf_uleb128(dwarf_سطر_section, DW_FORM_سطر_strp);
	    dwarf_uleb128(dwarf_سطر_section, dwarf_سطر.dir_ناپ);
	    لكل (i = 0; i < dwarf_سطر.dir_ناپ; i++)
	        dwarf_سطر_strp(dwarf_سطر_section, dwarf_سطر.dir_جدول[i]);
	    dwarf_data1(dwarf_سطر_section, 2); /*خانہ*/
	    dwarf_uleb128(dwarf_سطر_section, DW_LNCT_رستہ);
	    dwarf_uleb128(dwarf_سطر_section, DW_FORM_سطر_strp);
	    dwarf_uleb128(dwarf_سطر_section, DW_LNCT_directory_اشاریہ);
	    dwarf_uleb128(dwarf_سطر_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_سطر_section, dwarf_سطر.filename_ناپ);
	    لكل (i = 0; i < dwarf_سطر.filename_ناپ; i++) {
	        dwarf_سطر_strp(dwarf_سطر_section,
				dwarf_سطر.filename_جدول[i].name);
	        dwarf_uleb128(dwarf_سطر_section,
			      dwarf_سطر.filename_جدول[i].dir_اندراج);
	    }
	}
	وإلا {
	    صحيح len;

	    لكل (i = 0; i < dwarf_سطر.dir_ناپ; i++) {
	        len = لڑی_لمبائی(dwarf_سطر.dir_جدول[i]) + 1;
	        ptr = section_ptr_جوڑو(dwarf_سطر_section, len);
	        memmove(ptr, dwarf_سطر.dir_جدول[i], len);
	    }
	    dwarf_data1(dwarf_سطر_section, 0); /* end dir */
	    لكل (i = 0; i < dwarf_سطر.filename_ناپ; i++) {
	        len = لڑی_لمبائی(dwarf_سطر.filename_جدول[i].name) + 1;
	        ptr = section_ptr_جوڑو(dwarf_سطر_section, len);
	        memmove(ptr, dwarf_سطر.filename_جدول[i].name, len);
	        dwarf_uleb128(dwarf_سطر_section,
			      dwarf_سطر.filename_جدول[i].dir_اندراج);
	        dwarf_uleb128(dwarf_سطر_section, 0); /*ویلا*/
	        dwarf_uleb128(dwarf_سطر_section, 0); /*ناپ*/
	    }
	    dwarf_data1(dwarf_سطر_section, 0); /* end file */
	}
	لكل (i = 0; i < dwarf_سطر.dir_ناپ; i++)
	    tcc_free(dwarf_سطر.dir_جدول[i]);
	tcc_free(dwarf_سطر.dir_جدول);
	لكل (i = 0; i < dwarf_سطر.filename_ناپ; i++)
	    tcc_free(dwarf_سطر.filename_جدول[i].name);
	tcc_free(dwarf_سطر.filename_جدول);

	dwarf_سطر_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_سطر_op(s1, DW_LNE_سرا_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_سطر_section->انکڑے[dwarf_سطر.شروع + 6 + i],
		  dwarf_سطر_section->انکڑے_وتھ - dwarf_سطر.شروع - (10 + i));
	section_ptr_جوڑو(dwarf_سطر_section, 3);
	dwarf_reloc(dwarf_سطر_section, section_sym, R_انکڑے_PTR);
	ptr = section_ptr_جوڑو(dwarf_سطر_section, dwarf_سطر.سطر_ناپ - 3);
	memmove(ptr - 3, dwarf_سطر.سطر_انکڑے, dwarf_سطر.سطر_ناپ);
	tcc_free(dwarf_سطر.سطر_انکڑے);
	write32le(dwarf_سطر_section->انکڑے + dwarf_سطر.شروع,
		  dwarf_سطر_section->انکڑے_وتھ - dwarf_سطر.شروع - 4);
    }
    وإلا
    {
        put_stabs_r(s1, عدم, N_SO, 0, 0,
                    متن_section->انکڑے_وتھ, متن_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_سطر_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_اگلا_type = 0;
}

ساكن BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    إذا (f->filename[0] == ':')
        f = f->prev;
    إذا (f && new_file) {
        new_file = آخری_سطر_عدد = 0;
        إذا (s1->dwarf)
            dwarf_file(s1);
        وإلا
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, متن_section, section_sym);
    }
    أرجع f;
}

/* put alternative filename */
ST_FUNC فراغ tcc_debug_newfile(TCCState *s1)
{
    إذا (!s1->do_debug)
        أرجع;
    إذا (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC فراغ tcc_debug_bincl(TCCState *s1)
{
    إذا (!s1->do_debug)
        أرجع;
    إذا (s1->dwarf)
        dwarf_file(s1);
    وإلا
        put_stabs(s1, file->filename, N_BINCL, 0, 0, 0);
    new_file = 1;
}

/* end of #include */
ST_FUNC فراغ tcc_debug_eincl(TCCState *s1)
{
    إذا (!s1->do_debug)
        أرجع;
    إذا (s1->dwarf)
        dwarf_file(s1);
    وإلا
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC فراغ tcc_debug_سطر(TCCState *s1)
{
    BufferedFile *f;

    إذا (!s1->do_debug)
        أرجع;
    إذا (cur_متن_section != متن_section || nocode_wanted)
        أرجع;
    f = put_new_file(s1);
    إذا (!f)
        أرجع;
    إذا (آخری_سطر_عدد == f->سطر_عدد)
        أرجع;
    آخری_سطر_عدد = f->سطر_عدد;

    إذا (s1->dwarf) {
	صحيح len_pc = (ind - dwarf_سطر.آخری_pc) / DWARF_MIN_INSTR_LEN;
	صحيح len_سطر = f->سطر_عدد - dwarf_سطر.آخری_سطر;
	صحيح n = len_pc * DWARF_سطر_RANGE + len_سطر + DWARF_OPCODE_ادھار - DWARF_سطر_ادھار;

	إذا (dwarf_سطر.cur_file != dwarf_سطر.آخری_file) {
	    dwarf_سطر.آخری_file = dwarf_سطر.cur_file;
	    dwarf_سطر_op(s1, DW_LNS_سیٹ_file);
	    dwarf_uleb128_op(s1, dwarf_سطر.cur_file);
	}
	إذا (len_pc &&
	    len_سطر >= DWARF_سطر_ادھار && len_سطر <= (DWARF_OPCODE_ادھار + DWARF_سطر_ادھار) &&
	    n >= DWARF_OPCODE_ادھار && n <= 255)
            dwarf_سطر_op(s1, n);
	وإلا {
	    إذا (len_pc) {
	        n = len_pc * DWARF_سطر_RANGE + 0 + DWARF_OPCODE_ادھار - DWARF_سطر_ادھار;
	        إذا (n >= DWARF_OPCODE_ادھار && n <= 255)
                    dwarf_سطر_op(s1, n);
		وإلا {
	            dwarf_سطر_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    إذا (len_سطر) {
	        n = 0 * DWARF_سطر_RANGE + len_سطر + DWARF_OPCODE_ادھار - DWARF_سطر_ادھار;
	        إذا (len_سطر >= DWARF_سطر_ادھار && len_سطر <= (DWARF_OPCODE_ادھار + DWARF_سطر_ادھار) &&
		    n >= DWARF_OPCODE_ادھار && n <= 255)
	            dwarf_سطر_op(s1, n);
		وإلا {
	            dwarf_سطر_op(s1, DW_LNS_advance_سطر);
		    dwarf_sleb128_op(s1, len_سطر);
                    /* advance by nothing */
	            dwarf_سطر_op(s1, DWARF_OPCODE_ادھار - DWARF_سطر_ادھار);
		}
	    }
	}
	dwarf_سطر.آخری_pc = ind;
	dwarf_سطر.آخری_سطر = f->سطر_عدد;
    }
    وإلا
    {
	إذا (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->سطر_عدد, ind - func_ind);
        } وإلا {
            /* from tcc_assemble */
            put_stabs_r(s1, عدم, N_SLINE, 0, f->سطر_عدد, ind, متن_section, section_sym);
        }
    }
}

ساكن فراغ tcc_debug_stabs (TCCState *s1, ثابت حرف *str, صحيح type, بنانشانی لما قدر,
                             Section *sec, صحيح sym_اشاریہ, صحيح info)
{
    بنية debug_sym *s;

    إذا (debug_info) {
        debug_info->sym =
            (بنية debug_sym *)tcc_realloc (debug_info->sym,
                                             حجم(بنية debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->قدر = قدر;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_اشاریہ = sym_اشاریہ;
        s->info = info;
        s->file = dwarf_سطر.cur_file;
        s->سطر = file->سطر_عدد;
    }
    وإلا إذا (sec)
        put_stabs_r (s1, str, type, 0, 0, قدر, sec, sym_اشاریہ);
    وإلا
        put_stabs (s1, str, type, 0, 0, قدر);
}

ساكن فراغ fix_debug_forw_hash(TCCState *s1, صحيح global, صحيح شروع)
{
    إذا (s1->dwarf) {
        صحيح i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	بنية _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	لكل (i = شروع; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    صحيح pos = dwarf_info_section->انکڑے_وتھ;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_خالی_تھاواں_TYPE
                                             : DWARF_ABBREV_STRUCTURE_خالی_تھاواں_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_پہلا_ANOM
                       ? "" : get_tok_str(t->v, عدم));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_سطر.cur_file);
            dwarf_uleb128(dwarf_info_section, file->سطر_عدد);
	    لكل (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->انکڑے +
			  hash[i].debug_type[j],
			  pos - dwarf_info.شروع);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC فراغ tcc_debug_stabn(TCCState *s1, صحيح type, صحيح قدر)
{
    إذا (!s1->do_debug)
        أرجع;
    إذا (type == N_LBRAC) {
        بنية _debug_info *info =
            (بنية _debug_info *) tcc_mallocz(حجم (*info));

        info->شروع = قدر;
        info->آخری_debug_hash = n_debug_hash_local;
        info->آخری_debug_forw_hash = n_debug_forw_hash_local;
        info->ماپا = debug_info;
        إذا (debug_info) {
            إذا (debug_info->بچہ) {
                إذا (debug_info->بچہ->آخری)
                    debug_info->بچہ->آخری->اگلا = info;
                وإلا
                    debug_info->بچہ->اگلا = info;
                debug_info->بچہ->آخری = info;
            }
            وإلا
                debug_info->بچہ = info;
        }
        وإلا
            debug_info_جڑ = info;
        debug_info = info;
    }
    وإلا {
	fix_debug_forw_hash(s1, 0, debug_info->آخری_debug_forw_hash);
        n_debug_hash_local = debug_info->آخری_debug_hash;
        n_debug_forw_hash_local = debug_info->آخری_debug_forw_hash;
        debug_info->سرا = قدر;
        debug_info = debug_info->ماپا;
    }
}

ساكن صحيح check_global(Sym *t)
{
    Sym *g = local_ڈھیر;

    طالما (g) {
	إذا (t == g)
	    أرجع 0;
	g = g->prev;
    }
    أرجع 1;
}

ساكن صحيح tcc_debug_لبھو(TCCState *s1, Sym *t, صحيح dwarf)
{
    صحيح i , g = check_global(t);
    صحيح n_hash, *n_forw_hash;
    بنية _debug_hash *hash;
    بنية _debug_forw_hash **forw_hash;

    إذا ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	لكل (i = 0; i < *n_forw_hash; i++)
            إذا (t == (*forw_hash)[i].type)
		أرجع 0;
	*forw_hash = (بنية _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * حجم(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = عدم;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	أرجع 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    لكل (i = 0; i < n_hash; i++)
        إذا (t == hash[i].type)
	    أرجع hash[i].debug_type;
    أرجع -1;
}

ساكن صحيح tcc_get_dwarf_info(TCCState *s1, Sym *s);

ساكن فراغ tcc_debug_check_forw(TCCState *s1, Sym *t, صحيح debug_type)
{
    إذا ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        صحيح i, j, g = check_global(t);
        صحيح n_forw_hash;
        بنية _debug_forw_hash **forw_hash;

	لكل (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    لكل (j = 0; j < n_forw_hash; j++)
                إذا (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * حجم(صحيح));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    أرجع;
                }
	}
    }
}

ساكن فراغ stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC فراغ tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    إذا (!(s1->do_debug & 2))
	أرجع;
    إذا (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        أرجع;
    }
    إذا ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        صحيح i, j, debug_type, g = check_global(t->ref);
        صحيح *n_forw_hash;
        بنية _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	لكل (i = 0; i < *n_forw_hash; i++)
	    إذا (t->ref == (*forw_hash)[i].type) {
		إذا (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    لكل (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->انکڑے +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.شروع);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		لكل (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

ساكن صحيح tcc_debug_جوڑو(TCCState *s1, Sym *t, صحيح dwarf)
{
    صحيح وتھ = dwarf ? dwarf_info_section->انکڑے_وتھ : ++debug_اگلا_type;
    صحيح *n_hash, g = check_global(t);
    بنية _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (بنية _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * حجم(**hash));
    (*hash)[*n_hash].debug_type = وتھ;
    (*hash)[(*n_hash)++].type = t;
    أرجع وتھ;
}

ساكن صحيح STRUCT_NODEBUG(Sym *s)
{
    أرجع
    (s->a.nodebug ||
     ((s->v & ~SYM_میدان) >= SYM_پہلا_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

ساكن صحيح stabs_struct_لبھو(TCCState *s1, Sym *t, صحيح *p_id)
{
    /* A struct/enum has a ref to its type but that type has no ref.
       So we can (ab)use it for some info.  Here:
         s->c : stabs type id
         s->r : already defined in stabs */
    Sym *s = t->type.ref;
/*
    if (s && s->v != (SYM_FIELD|0x00DEBBED)) {
        tcc_error_noabort("tccdbg: internal error: %s", get_tok_str(t->v, 0));
        if (p_id)
            *p_id = 0;
        return 0;
    }
*/
    إذا (عدم == p_id)
        أرجع s && !s->r && t->c >= 0;
    إذا (عدم == s) {
        /* just use global_stack always */
        s = sym_push2(&global_ڈھیر, SYM_میدان|0x00DEBBED, 0, ++debug_اگلا_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    إذا (s->r || t->c < 0) /* already defined or still incomplete */
        أرجع 0;
    s->r = 1;
    أرجع 1;
}

ساكن صحيح remove_type_info(صحيح type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        إذا ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        إذا (!(type & VT_BITFIELD) && (type & VT_STRUCT_نقاب) > VT_ENUM)
	    type &= ~VT_STRUCT_نقاب;
	أرجع type;
}

ساكن فراغ tcc_get_debug_info(TCCState *s1, Sym *s, CString *نتیجہ)
{
    صحيح type;
    صحيح n = 0;
    صحيح debug_type = -1;
    Sym *t = s;
    CString str;

    لكل (;;) {
        type = remove_type_info (t->type.t);
        إذا (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        وإلا
            اكسر;
    }
    إذا ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        إذا (stabs_struct_لبھو(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_پہلا_ANOM
                         ? "" : get_tok_str(t->v, عدم),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            طالما (t->اگلا) {
                صحيح pos, ناپ, align;
                t = t->اگلا;
		إذا (STRUCT_NODEBUG(t))
		    استمر;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_میدان) >= SYM_پہلا_ANOM
                             ? "" : get_tok_str(t->v, عدم)
                             );
                tcc_get_debug_info (s1, t, &str);
                إذا (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + ثنائی_ہندسہ_POS(t->type.t);
                    ناپ = ثنائی_ہندسہ_ناپ(t->type.t);
                }
                وإلا {
                    pos = t->c * 8;
                    ناپ = type_ناپ(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, ناپ);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.انکڑے, N_LSYM, 0, عدم, 0, 0);
            cstr_free (&str);
        }
    }
    وإلا إذا (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        إذا (stabs_struct_لبھو(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_پہلا_ANOM
                         ? "" : get_tok_str(t->v, عدم),
                         debug_type);
            طالما (t->اگلا) {
                t = t->اگلا;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_میدان) >= SYM_پہلا_ANOM
                             ? "" : get_tok_str(t->v, عدم));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (صحيح)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.انکڑے, N_LSYM, 0, عدم, 0, 0);
            cstr_free (&str);
	}
    }
    وإلا إذا ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_نقاب;
        لكل (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            إذا (default_debug[debug_type - 1].type == type)
                اكسر;
        إذا (debug_type > N_DEFAULT_DEBUG)
            أرجع;
    }

    إذا (عدم == نتیجہ) /* from stabs_struct_complete() */
        أرجع;

    إذا (n > 0)
        cstr_printf (نتیجہ, "%d=", ++debug_اگلا_type);
    t = s;
    لكل (;;) {
        type = remove_type_info (t->type.t);
        إذا (type == VT_PTR)
            cstr_printf (نتیجہ, "%d=*", ++debug_اگلا_type);
        وإلا إذا (type == (VT_PTR | VT_ARRAY))
            cstr_printf (نتیجہ, "%d=ar1;0;%d;",
                         ++debug_اگلا_type, t->type.ref->c - 1);
        وإلا إذا (type == VT_FUNC) {
            cstr_printf (نتیجہ, "%d=f", ++debug_اگلا_type);
            tcc_get_debug_info (s1, t->type.ref, نتیجہ);
            أرجع;
        }
        وإلا
            اكسر;
        t = t->type.ref;
    }
    cstr_printf (نتیجہ, "%d", debug_type);
}

ساكن فراغ stabs_struct_complete(TCCState *s1, CType *t)
{
    إذا (stabs_struct_لبھو(s1, t->ref, عدم)) {
        Sym s = {0}; s.type = *t;
        tcc_get_debug_info(s1, &s, عدم);
    }
}

ساكن صحيح tcc_get_dwarf_info(TCCState *s1, Sym *s)
{
    صحيح type;
    صحيح debug_type = -1;
    Sym *e, *t = s;
    صحيح i;
    صحيح آخری_pos = -1;
    صحيح retval;

    إذا (new_file)
        put_new_file(s1);
    لكل (;;) {
        type = remove_type_info (t->type.t);
        إذا (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        وإلا
            اكسر;
    }
    إذا ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_لبھو(s1, t, 1);
	إذا (debug_type == -1) {
	    صحيح pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_جوڑو(s1, t, 1);
	    e = t;
	    i = 0;
	    طالما (e->اگلا) {
		e = e->اگلا;
		إذا (STRUCT_NODEBUG(e))
		    استمر;
		i++;
	    }
	    pos_type = (صحيح *) tcc_malloc(i * حجم(صحيح));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->اگلا ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_خالی_تھاواں_TYPE
		        : t->اگلا ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_خالی_تھاواں_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_پہلا_ANOM
                       ? "" : get_tok_str(t->v, عدم));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_سطر.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->سطر_عدد);
	    إذا (t->اگلا) {
	        pos_sib = dwarf_info_section->انکڑے_وتھ;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            طالما (e->اگلا) {
                e = e->اگلا;
		إذا (STRUCT_NODEBUG(e))
		    استمر;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, عدم));
		dwarf_uleb128(dwarf_info_section, dwarf_سطر.cur_file);
		dwarf_uleb128(dwarf_info_section, file->سطر_عدد);
		pos_type[i++] = dwarf_info_section->انکڑے_وتھ;
		dwarf_data4(dwarf_info_section, 0);
                إذا (e->type.t & VT_BITFIELD) {
                    صحيح pos = e->c * 8 + ثنائی_ہندسہ_POS(e->type.t);
                    صحيح ناپ = ثنائی_ہندسہ_ناپ(e->type.t);

		    dwarf_uleb128(dwarf_info_section, ناپ);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		وإلا
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    إذا (t->اگلا) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->انکڑے + pos_sib,
		          dwarf_info_section->انکڑے_وتھ - dwarf_info.شروع);
	    }
	    e = t;
	    i = 0;
	    طالما (e->اگلا) {
		e = e->اگلا;
		إذا (STRUCT_NODEBUG(e))
		    استمر;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->انکڑے + pos_type[i++],
			  type - dwarf_info.شروع);
	    }
	    tcc_free(pos_type);
        }
    }
    وإلا إذا (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_لبھو(s1, t, 1);
	إذا (debug_type == -1) {
	    صحيح pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_جوڑو(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_پہلا_ANOM
                       ? "" : get_tok_str(t->v, عدم));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.شروع);
	    dwarf_uleb128(dwarf_info_section, dwarf_سطر.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->سطر_عدد);
	    pos_sib = dwarf_info_section->انکڑے_وتھ;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            طالما (e->اگلا) {
                e = e->اگلا;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_میدان) >= SYM_پہلا_ANOM
                           ? "" : get_tok_str(e->v, عدم));
		إذا (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		وإلا
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->انکڑے + pos_sib,
		      dwarf_info_section->انکڑے_وتھ - dwarf_info.شروع);
	}
    }
    وإلا إذا ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_نقاب;
        لكل (i = 1; i <= N_DEFAULT_DEBUG; i++)
            إذا (default_debug[i - 1].type == type)
                اكسر;
        إذا (i > N_DEFAULT_DEBUG)
            أرجع 0;
	debug_type = dwarf_info.ادھار_type_ورتیا[i - 1];
	إذا (debug_type == 0) {
	    حرف name[100];

	    debug_type = dwarf_info_section->انکڑے_وتھ;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ادھار_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].ناپ);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, حجم name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.ادھار_type_ورتیا[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = عدم;
    t = s;
    لكل (;;) {
        type = remove_type_info (t->type.t);
        إذا (type == VT_PTR) {
	    i = dwarf_info_section->انکڑے_وتھ;
	    إذا (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_اشارہ_گر);
	    dwarf_data1(dwarf_info_section, PTR_ناپ);
	    إذا (آخری_pos != -1) {
		tcc_debug_check_forw(s1, e, آخری_pos);
		write32le(dwarf_info_section->انکڑے + آخری_pos,
			  i - dwarf_info.شروع);
	    }
	    آخری_pos = dwarf_info_section->انکڑے_وتھ;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        وإلا إذا (type == (VT_PTR | VT_ARRAY)) {
	    صحيح sib_pos, sub_type;
#إذا LONG_ناپ == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#وإلا
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#جے_انت

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->انکڑے_وتھ;
	    إذا (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    إذا (آخری_pos != -1) {
		tcc_debug_check_forw(s1, e, آخری_pos);
		write32le(dwarf_info_section->انکڑے + آخری_pos,
			  i - dwarf_info.شروع);
	    }
	    آخری_pos = dwarf_info_section->انکڑے_وتھ;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->انکڑے_وتھ;
	    dwarf_data4(dwarf_info_section, 0);
	    لكل (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.شروع);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		إذا (type != (VT_PTR | VT_ARRAY))
		    اكسر;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->انکڑے + sib_pos,
		      dwarf_info_section->انکڑے_وتھ - dwarf_info.شروع);
	}
        وإلا إذا (type == VT_FUNC) {
	    صحيح sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->انکڑے_وتھ;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    إذا (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->اگلا ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_خالی_تھاواں_TYPE);
	    إذا (آخری_pos != -1) {
		tcc_debug_check_forw(s1, e, آخری_pos);
		write32le(dwarf_info_section->انکڑے + آخری_pos,
			  i - dwarf_info.شروع);
	    }
	    آخری_pos = dwarf_info_section->انکڑے_وتھ;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    إذا (t->type.ref->اگلا) {
	        sib_pos = dwarf_info_section->انکڑے_وتھ;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    طالما (f->اگلا) {
		f = f->اگلا;
		i++;
	    }
	    pos_type = (صحيح *) tcc_malloc(i * حجم(صحيح));
	    f = t->type.ref;
	    i = 0;
	    طالما (f->اگلا) {
		f = f->اگلا;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->انکڑے_وتھ;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    إذا (t->type.ref->اگلا) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->انکڑے + sib_pos,
		          dwarf_info_section->انکڑے_وتھ - dwarf_info.شروع);
	    }
	    f = t->type.ref;
	    i = 0;
	    طالما (f->اگلا) {
		f = f->اگلا;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->انکڑے + pos_type[i++],
                          type - dwarf_info.شروع);
	    }
	    tcc_free(pos_type);
        }
        وإلا {
	    إذا (آخری_pos != -1) {
		tcc_debug_check_forw(s1, e, آخری_pos);
		write32le(dwarf_info_section->انکڑے + آخری_pos,
			  debug_type - dwarf_info.شروع);
	    }
            اكسر;
	}
        t = t->type.ref;
    }
    أرجع retval;
}

ساكن فراغ tcc_debug_انت (TCCState *s1, بنية _debug_info *cur)
{
    طالما (cur) {
        بنية _debug_info *اگلا = cur->اگلا;
        صحيح i;

        إذا (s1->dwarf) {

            لكل (i = cur->n_sym - 1; i >= 0; i--) {
                بنية debug_sym *s = &cur->sym[i];

		dwarf_data1(dwarf_info_section,
                            s->type == N_PSYM
			    ? DWARF_ABBREV_FORMAL_PARAMETER
			    : s->type == N_GSYM
                            ? DWARF_ABBREV_VARIABLE_EXTERNAL
                            : s->type == N_STSYM
			    ? DWARF_ABBREV_VARIABLE_STATIC
			    : DWARF_ABBREV_VARIABLE_LOCAL);
                dwarf_strp(dwarf_info_section, s->str);
		إذا (s->type == N_GSYM || s->type == N_STSYM) {
                    dwarf_uleb128(dwarf_info_section, s->file);
                    dwarf_uleb128(dwarf_info_section, s->سطر);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.شروع);
		إذا (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    إذا (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_ناپ + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    إذا (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_انکڑے_PTR);
#إذا PTR_ناپ == 4
                    dwarf_data4(dwarf_info_section, s->قدر);
#وإلا
                    dwarf_data8(dwarf_info_section, s->قدر);
#جے_انت
		}
		وإلا {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_ناپ((لما)s->قدر) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (لما)s->قدر);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->بچہ ? DWARF_ABBREV_LEXICAL_بلاک
			           : DWARF_ABBREV_LEXICAL_خالی_تھاواں_بلاک);
            dwarf_reloc(dwarf_info_section, section_sym, R_انکڑے_PTR);
#إذا PTR_ناپ == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->شروع);
            dwarf_data4(dwarf_info_section, cur->سرا - cur->شروع);
#وإلا
            dwarf_data8(dwarf_info_section, func_ind + cur->شروع);
            dwarf_data8(dwarf_info_section, cur->سرا - cur->شروع);
#جے_انت
            tcc_debug_انت (s1, cur->بچہ);
	    إذا (cur->بچہ)
                dwarf_data1(dwarf_info_section, 0);
        }
        وإلا
        {
            لكل (i = 0; i < cur->n_sym; i++) {
                بنية debug_sym *s = &cur->sym[i];

                إذا (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->قدر,
                                s->sec, s->sym_اشاریہ);
                وإلا
                    put_stabs(s1, s->str, s->type, 0, 0, s->قدر);
                tcc_free (s->str);
            }
            tcc_free (cur->sym);
            put_stabn(s1, N_LBRAC, 0, 0, cur->شروع);
            tcc_debug_انت (s1, cur->بچہ);
            put_stabn(s1, N_RBRAC, 0, 0, cur->سرا);
        }
        tcc_free (cur);
        cur = اگلا;
    }
}

ST_FUNC فراغ tcc_جوڑو_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    صحيح param;

    إذا (!(s1->do_debug & 2))
        أرجع;

    cstr_new (&debug_str);
    param = !e;
    لكل (; s != e; s = s->prev) {
        إذا (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            استمر;
	إذا (s1->dwarf) {
	    tcc_debug_stabs(s1, get_tok_str(s->v, عدم),
			    param ? N_PSYM : N_LSYM, s->c, عدم, 0,
			    tcc_get_dwarf_info(s1, s));
	}
	وإلا
        {
            cstr_reset (&debug_str);
            cstr_printf (&debug_str, "%s:%s", get_tok_str(s->v, عدم),
			 param ? "p" : "");
            tcc_get_debug_info(s1, s, &debug_str);
            tcc_debug_stabs(s1, debug_str.انکڑے, param ? N_PSYM : N_LSYM,
			    s->c, عدم, 0, 0);
	}
    }
    cstr_free (&debug_str);
}

/* put function symbol */
ST_FUNC فراغ tcc_debug_funcstart(TCCState *s1, Sym *sym)
{
    CString debug_str;
    BufferedFile *f;

    إذا (!s1->do_debug)
        أرجع;
    debug_info_جڑ = عدم;
    debug_info = عدم;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    إذا (!f)
	أرجع;

    إذا (s1->dwarf) {
        tcc_debug_سطر(s1);
        dwarf_info.func = sym;
        dwarf_info.سطر = file->سطر_عدد;
	إذا (s1->do_backtrace) {
	    صحيح i, len;

	    dwarf_سطر_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, لڑی_لمبائی(funcname) + 2);
	    dwarf_سطر_op(s1, DW_LNE_hi_user - 1);
	    len = لڑی_لمبائی(funcname) + 1;
	    لكل (i = 0; i < len; i++)
		dwarf_سطر_op(s1, funcname[i]);
	}
    }
    وإلا
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.انکڑے, N_FUN, 0, f->سطر_عدد, 0, cur_متن_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_سطر(s1);
    }
}

ST_FUNC فراغ tcc_debug_prolog_epilog(TCCState *s1, صحيح قدر)
{
    إذا (!s1->do_debug)
        أرجع;
    إذا (s1->dwarf) {
	dwarf_سطر_op(s1, قدر == 0 ? DW_LNS_سیٹ_prologue_سرا
				     : DW_LNS_سیٹ_epilogue_begin);
    }
}

/* put function size */
ST_FUNC فراغ tcc_debug_funcend(TCCState *s1, صحيح ناپ)
{
    /* lldb does not like function end and next function start at same pc */
    صحيح min_instr_len;

#إذا TCC_EH_چوکھٹا
    tcc_debug_چوکھٹا_سرا(s1, ناپ);
#جے_انت
    إذا (!s1->do_debug)
        أرجع;
    min_instr_len = dwarf_سطر.آخری_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_سطر(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, ناپ);
    إذا (s1->dwarf) {
        صحيح func_sib = 0;
	Sym *sym = dwarf_info.func;
	صحيح n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        إذا ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_سطر.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.سطر);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->انکڑے_وتھ);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.شروع);
        dwarf_reloc(dwarf_info_section, section_sym, R_انکڑے_PTR);
#إذا PTR_ناپ == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, ناپ); // high_pc
#وإلا
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, ناپ); // high_pc
#جے_انت
        func_sib = dwarf_info_section->انکڑے_وتھ;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#إذا defined(TCC_نشانہ_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#وإلاإذا defined(TCC_نشانہ_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#وإلاإذا defined TCC_نشانہ_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#وإلاإذا defined TCC_نشانہ_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#وإلاإذا defined TCC_نشانہ_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#وإلا
        dwarf_data1(dwarf_info_section, DW_OP_call_چوکھٹا_cfa);
#جے_انت
        tcc_debug_انت (s1, debug_info_جڑ);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->انکڑے + func_sib,
                  dwarf_info_section->انکڑے_وتھ - dwarf_info.شروع);
    }
    وإلا
    {
        tcc_debug_انت (s1, debug_info_جڑ);
    }
    debug_info_جڑ = 0;
}


ST_FUNC فراغ tcc_debug_extern_sym(TCCState *s1, Sym *sym, صحيح sh_عدد, صحيح sym_bind, صحيح sym_type)
{
    إذا (!(s1->do_debug & 2))
        أرجع;

    إذا (sym_type == STT_FUNC || sym->v >= SYM_پہلا_ANOM)
        أرجع;
    إذا (s1->dwarf) {
        صحيح debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, عدم));
	dwarf_uleb128(dwarf_info_section, dwarf_سطر.cur_file);
	dwarf_uleb128(dwarf_info_section, file->سطر_عدد);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->انکڑے_وتھ);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.شروع);
	إذا (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_ناپ + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->انکڑے_وتھ,
		R_انکڑے_PTR, 0);
#إذا PTR_ناپ == 4
	dwarf_data4(dwarf_info_section, 0);
#وإلا
	dwarf_data8(dwarf_info_section, 0);
#جے_انت
    }
    وإلا
    {
        Section *s = sh_عدد == SHN_COMMON ? common_section
					  : s1->sections[sh_عدد];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, عدم),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        إذا (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.انکڑے, N_GSYM, 0, عدم, 0, 0);
        وإلا
            tcc_debug_stabs(s1, str.انکڑے,
                (sym->type.t & VT_STATIC) && انکڑے_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC فراغ tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    إذا (!(s1->do_debug & 2))
        أرجع;

    إذا (s1->dwarf) {
	صحيح debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	إذا (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, عدم));
	    dwarf_uleb128(dwarf_info_section, dwarf_سطر.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->سطر_عدد);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->انکڑے_وتھ);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.شروع);
	}
    }
    وإلا
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, عدم));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.انکڑے, N_LSYM, 0, عدم, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC فراغ tcc_tcov_بلاک_سرا(TCCState *s1, صحيح سطر);

ST_FUNC فراغ tcc_tcov_بلاک_begin(TCCState *s1)
{
    SValue sv;
    فراغ *ptr;
    بنانشانی لما آخری_وتھ = tcov_انکڑے.وتھ;

    tcc_tcov_بلاک_سرا (tcc_state, 0);
    إذا (s1->test_coverage == 0 || nocode_wanted)
	أرجع;

    إذا (tcov_انکڑے.آخری_file_name == 0 ||
	strcmp ((ثابت حرف *)(tcov_section->انکڑے + tcov_انکڑے.آخری_file_name),
		file->true_filename) != 0) {
	حرف wd[1024];
	CString cstr;

	إذا (tcov_انکڑے.آخری_func_name)
	    section_ptr_جوڑو(tcov_section, 1);
	إذا (tcov_انکڑے.آخری_file_name)
	    section_ptr_جوڑو(tcov_section, 1);
	tcov_انکڑے.آخری_func_name = 0;
	cstr_new (&cstr);
	إذا (file->true_filename[0] == '/') {
	    tcov_انکڑے.آخری_file_name = tcov_section->انکڑے_وتھ;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	وإلا {
	    getcwd (wd, حجم(wd));
	    tcov_انکڑے.آخری_file_name = tcov_section->انکڑے_وتھ + لڑی_لمبائی(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_جوڑو(tcov_section, cstr.ناپ + 1);
	strcpy((حرف *)ptr, cstr.انکڑے);
#جے_تعریف_شدہ _WIN32
        normalize_slashes((حرف *)ptr);
#جے_انت
	cstr_free (&cstr);
    }
    إذا (tcov_انکڑے.آخری_func_name == 0 ||
	strcmp ((ثابت حرف *)(tcov_section->انکڑے + tcov_انکڑے.آخری_func_name),
		funcname) != 0) {
	ناپ_t len;

	إذا (tcov_انکڑے.آخری_func_name)
	    section_ptr_جوڑو(tcov_section, 1);
	tcov_انکڑے.آخری_func_name = tcov_section->انکڑے_وتھ;
	len = لڑی_لمبائی (funcname);
	ptr = section_ptr_جوڑو(tcov_section, len + 1);
	strcpy((حرف *)ptr, funcname);
	section_ptr_جوڑو(tcov_section, -tcov_section->انکڑے_وتھ & 7);
	ptr = section_ptr_جوڑو(tcov_section, 8);
	write64le (ptr, file->سطر_عدد);
    }
    إذا (ind == tcov_انکڑے.ind && tcov_انکڑے.سطر == file->سطر_عدد)
        tcov_انکڑے.وتھ = آخری_وتھ;
    وإلا {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_جوڑو(tcov_section, 16);
        tcov_انکڑے.سطر = file->سطر_عدد;
        write64le (ptr, (tcov_انکڑے.سطر << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((بنانشانی حرف *)ptr - tcov_section->انکڑے) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#إذا defined TCC_نشانہ_I386 || defined TCC_نشانہ_X86_64 || \
    defined TCC_نشانہ_ARM || defined TCC_نشانہ_ARM64 || \
    defined TCC_نشانہ_RISCV64
        gen_increment_tcov (&sv);
#وإلا
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#جے_انت
        tcov_انکڑے.وتھ = (بنانشانی حرف *)ptr - tcov_section->انکڑے;
        tcov_انکڑے.ind = ind;
    }
}

ST_FUNC فراغ tcc_tcov_بلاک_سرا(TCCState *s1, صحيح سطر)
{
    إذا (s1->test_coverage == 0)
	أرجع;
    إذا (سطر == -1)
        سطر = tcov_انکڑے.سطر;
    إذا (tcov_انکڑے.وتھ) {
	فراغ *ptr = tcov_section->انکڑے + tcov_انکڑے.وتھ;
	بنانشانی لما لما nline = سطر ? سطر : file->سطر_عدد;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_انکڑے.وتھ = 0;
    }
}

ST_FUNC فراغ tcc_tcov_check_سطر(TCCState *s1, صحيح شروع)
{
    إذا (s1->test_coverage == 0)
	أرجع;
    إذا (tcov_انکڑے.سطر != file->سطر_عدد) {
        إذا ((tcov_انکڑے.سطر + 1) != file->سطر_عدد) {
	    tcc_tcov_بلاک_سرا (s1, -1);
	    إذا (شروع)
                tcc_tcov_بلاک_begin (s1);
	}
	وإلا
	    tcov_انکڑے.سطر = file->سطر_عدد;
    }
}

ST_FUNC فراغ tcc_tcov_شروع(TCCState *s1)
{
    إذا (s1->test_coverage == 0)
	أرجع;
    إذا (!s1->dState)
        s1->dState = tcc_mallocz(حجم *s1->dState);
    memset (&tcov_انکڑے, 0, حجم (tcov_انکڑے));
    إذا (tcov_section == عدم) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_جوڑو(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC فراغ tcc_tcov_سرا(TCCState *s1)
{
    إذا (s1->test_coverage == 0)
	أرجع;
    إذا (tcov_انکڑے.آخری_func_name)
        section_ptr_جوڑو(tcov_section, 1);
    إذا (tcov_انکڑے.آخری_file_name)
        section_ptr_جوڑو(tcov_section, 1);
}

ST_FUNC فراغ tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_انکڑے.ind = 0;
}

/* ------------------------------------------------------------------------- */
#تعریف_رد آخری_سطر_عدد
#تعریف_رد new_file
#تعریف_رد section_sym
#تعریف_رد debug_اگلا_type
#تعریف_رد debug_hash_global
#تعریف_رد debug_hash_local
#تعریف_رد n_debug_hash_global
#تعریف_رد n_debug_hash_local
#تعریف_رد debug_forw_hash_global
#تعریف_رد debug_forw_hash_local
#تعریف_رد n_debug_forw_hash_global
#تعریف_رد n_debug_forw_hash_local
#تعریف_رد debug_info
#تعریف_رد debug_info_جڑ
#تعریف_رد dwarf_sym
#تعریف_رد dwarf_سطر
#تعریف_رد dwarf_info
#تعریف_رد dwarf_str
#تعریف_رد dwarf_سطر_str
#تعریف_رد tcov_انکڑے
