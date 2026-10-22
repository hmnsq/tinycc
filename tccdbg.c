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

#شامل "tcc.h"

/* stab debug support */

ساکن ثابت ساخت {
  صحیح type;
  صحیح سائز;
  صحیح encoding;
  ثابت حرف *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#اگر LONG_سائز == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#ورنہ
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#اگر_ختم
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#اگر LONG_سائز == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#ورنہ
    /* use octal instead of -1 so size_t works (-gstabs+ in gcc) */
    {   VT_LLONG | VT_LONG | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t5=r5;0;01777777777777777777777;" },
#اگر_ختم
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
#اگر_تعریف_شدہ TCC_USING_DOUBLE_FOR_LDOUBLE
    {   VT_DOUBLE | VT_LONG, 8, DW_ATE_float, "long double:t16=r1;8;0;" },
#ورنہ
    {   VT_LDOUBLE, 16, DW_ATE_float, "long double:t16=r1;16;0;" },
#اگر_ختم
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
#اگر LONG_سائز == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#ورنہ
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#اگر_ختم
};

#تعریف_کرو	N_DEFAULT_DEBUG	(حجم (default_debug) / حجم (default_debug[0]))

/* dwarf debug */

#تعریف_کرو	DWARF_سطر_بنیاد				-5
#تعریف_کرو	DWARF_سطر_RANGE			14
#تعریف_کرو	DWARF_OPCODE_بنیاد			13

#اگر defined TCC_ہدف_ARM64
#تعریف_کرو	DWARF_MIN_INSTR_LEN			4
#وگرنہ_اگر defined TCC_ہدف_ARM
#تعریف_کرو	DWARF_MIN_INSTR_LEN			2
#ورنہ
#تعریف_کرو	DWARF_MIN_INSTR_LEN			1
#اگر_ختم

#تعریف_کرو	DWARF_ABBREV_COMPILE_UNIT		1
#تعریف_کرو	DWARF_ABBREV_بنیاد_TYPE			2
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
#تعریف_کرو	DWARF_ABBREV_STRUCTURE_خالی_خانے_TYPE	17
#تعریف_کرو	DWARF_ABBREV_UNION_TYPE			18
#تعریف_کرو	DWARF_ABBREV_UNION_خالی_خانے_TYPE		19
#تعریف_کرو	DWARF_ABBREV_SUBPROGRAM_EXTERNAL	20
#تعریف_کرو	DWARF_ABBREV_SUBPROGRAM_STATIC		21
#تعریف_کرو	DWARF_ABBREV_LEXICAL_بلاک		22
#تعریف_کرو	DWARF_ABBREV_LEXICAL_خالی_خانے_بلاک	23
#تعریف_کرو	DWARF_ABBREV_SUBROUTINE_TYPE		24
#تعریف_کرو	DWARF_ABBREV_SUBROUTINE_خالی_خانے_TYPE	25
#تعریف_کرو	DWARF_ABBREV_FORMAL_PARAMETER2		26

/* all entries should have been generated with dwarf_uleb128 except
   has_children. All values are currently below 128 so this currently
   works.  */
ساکن ثابت غیرعلامتی حرف dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_لیبل_compile_unit, 1,
          DW_AT_پیداکار, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_سطر_strp,
          DW_AT_comp_dir, DW_FORM_سطر_strp,
          DW_AT_کم_pc, DW_FORM_addr,
#اگر PTR_سائز == 4
          DW_AT_بلند_pc, DW_FORM_data4,
#ورنہ
          DW_AT_بلند_pc, DW_FORM_data8,
#اگر_ختم
          DW_AT_stmt_list, DW_FORM_sec_انحراف,
          0, 0,
    DWARF_ABBREV_بنیاد_TYPE, DW_لیبل_بنیاد_type, 0,
          DW_AT_byte_سائز, DW_FORM_udata,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_name, DW_FORM_strp,
          0, 0,
    DWARF_ABBREV_VARIABLE_EXTERNAL, DW_لیبل_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_لیبل_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_LOCAL, DW_لیبل_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER, DW_لیبل_formal_parameter, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_اشارہ_گر, DW_لیبل_اشارہ_گر_type, 0,
          DW_AT_byte_سائز, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ARRAY_TYPE, DW_لیبل_array_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBRANGE_TYPE, DW_لیبل_subrange_type, 0,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_بالائی_bound, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_TYPEDEF, DW_لیبل_typedef, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_لیبل_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_قدر, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_لیبل_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_قدر, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_لیبل_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_سائز, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_لیبل_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ڈیٹا_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_لیبل_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ثنائی_ہندسہ_سائز, DW_FORM_udata,
          DW_AT_ڈیٹا_ثنائی_ہندسہ_انحراف, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_لیبل_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_سائز, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_خالی_خانے_TYPE, DW_لیبل_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_سائز, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_لیبل_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_سائز, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_خالی_خانے_TYPE, DW_لیبل_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_سائز, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_لیبل_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_کم_pc, DW_FORM_addr,
#اگر PTR_سائز == 4
          DW_AT_بلند_pc, DW_FORM_data4,
#ورنہ
          DW_AT_بلند_pc, DW_FORM_data8,
#اگر_ختم
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_چوکھٹا_بنیاد, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_لیبل_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سطر, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_کم_pc, DW_FORM_addr,
#اگر PTR_سائز == 4
          DW_AT_بلند_pc, DW_FORM_data4,
#ورنہ
          DW_AT_بلند_pc, DW_FORM_data8,
#اگر_ختم
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_چوکھٹا_بنیاد, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_بلاک, DW_لیبل_lexical_بلاک, 1,
          DW_AT_کم_pc, DW_FORM_addr,
#اگر PTR_سائز == 4
          DW_AT_بلند_pc, DW_FORM_data4,
#ورنہ
          DW_AT_بلند_pc, DW_FORM_data8,
#اگر_ختم
          0, 0,
    DWARF_ABBREV_LEXICAL_خالی_خانے_بلاک, DW_لیبل_lexical_بلاک, 0,
          DW_AT_کم_pc, DW_FORM_addr,
#اگر PTR_سائز == 4
          DW_AT_بلند_pc, DW_FORM_data4,
#ورنہ
          DW_AT_بلند_pc, DW_FORM_data8,
#اگر_ختم
          0, 0,
    DWARF_ABBREV_SUBROUTINE_TYPE, DW_لیبل_subroutine_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBROUTINE_خالی_خانے_TYPE, DW_لیبل_subroutine_type, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER2, DW_لیبل_formal_parameter, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
  0
};

ساکن ثابت غیرعلامتی حرف dwarf_سطر_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#تعریف_کرو N_STR_HASH (251)

ساخت dwarf_str_hash {
    صحیح len;
    غیرعلامتی طویل ڈیٹا_انحراف;
    ساخت dwarf_str_hash *اگلا;
};

ساخت _tccdbg {

    صحیح آخری_سطر_عدد, new_file;
    صحیح section_sym;

    صحیح debug_اگلا_type;

    ساخت _debug_hash {
        صحیح debug_type;
        Sym *type;
    } *debug_hash_global, *debug_hash_local;

    /* store forward structure/unions types */
    ساخت _debug_forw_hash {
        Sym *type;
        صحیح n_debug_type;
        صحیح *debug_type;
    } *debug_forw_hash_global, *debug_forw_hash_local;

    صحیح n_debug_hash_global;
    صحیح n_debug_hash_local;
    صحیح n_debug_forw_hash_global;
    صحیح n_debug_forw_hash_local;

    ساخت _debug_info {
        صحیح آغاز;
        صحیح انتہا;
        صحیح آخری_debug_hash;
        صحیح آخری_debug_forw_hash;
        صحیح n_sym;
        ساخت debug_sym {
            صحیح type;
            غیرعلامتی طویل قدر;
            حرف *str;
            Section *sec;
            صحیح sym_اشاریہ;
            صحیح info;
            صحیح file;
            صحیح سطر;
        } *sym;
        ساخت _debug_info *بچہ, *اگلا, *آخری, *والد;
    } *debug_info, *debug_info_جڑ;

    ساخت {
        صحیح info;
        صحیح abbrev;
        صحیح سطر;
        صحیح str;
        صحیح سطر_str;
    } dwarf_sym;

    ساخت {
        صحیح آغاز;
        صحیح dir_سائز;
        حرف **dir_جدول;
        صحیح filename_سائز;
        ساخت dwarf_filename_struct {
            صحیح dir_اندراج;
            حرف *name;
        } *filename_جدول;
        صحیح سطر_سائز;
        صحیح سطر_max_سائز;
        غیرعلامتی حرف *سطر_ڈیٹا;
        صحیح cur_file;
        صحیح آخری_file;
        صحیح آخری_pc;
        صحیح آخری_سطر;
    } dwarf_سطر;

    ساخت {
        صحیح آغاز;
        Sym *func;
        صحیح سطر;
        صحیح بنیاد_type_مستعمل[N_DEFAULT_DEBUG];
    } dwarf_info;

    ساخت dwarf_str_hash *dwarf_str[N_STR_HASH];
    ساخت dwarf_str_hash *dwarf_سطر_str[N_STR_HASH];

    /* test coverage */
    ساخت {
        غیرعلامتی طویل انحراف;
        غیرعلامتی طویل آخری_file_name;
        غیرعلامتی طویل آخری_func_name;
        صحیح ind;
        صحیح سطر;
    } tcov_ڈیٹا;
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
#تعریف_کرو tcov_ڈیٹا                 s1->dState->tcov_ڈیٹا

#تعریف_کرو	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
ساکن صحیح put_stabs(TCCState *s1, ثابت حرف *str, صحیح type, صحیح other,
    صحیح desc, غیرعلامتی طویل قدر);

ST_FUNC خالی tcc_debug_new(TCCState *s1)
{
    صحیح shf = 0;
    اگر (!s1->dState)
        s1->dState = tcc_mallocz(حجم *s1->dState);

#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    اگر (s1->do_debug && s1->output_type == TCC_OUTPUT_حافظہ)
        s1->do_backtrace = 1;
    اگر (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#اگر_ختم

    اگر (s1->dwarf) {
	صحیح i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	ساکن ثابت حرف *ثابت debug[] = {
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
	برائے (i = 0; i < حجم(debug)/حجم(debug[0]); i++)
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
	اگر (s1->dwarf >= 5) {
            dwarf_سطر_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_سطر_str_section->sh_entsize = 1;
	    dwarf_سطر_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    ورنہ
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
ساکن صحیح put_stabs(TCCState *s1, ثابت حرف *str, صحیح type, صحیح other, صحیح desc,
                      غیرعلامتی طویل قدر)
{
    Stab_Sym *sym;

    غیرعلامتی انحراف;
    اگر (type == N_SLINE
        && (انحراف = stab_section->ڈیٹا_انحراف)
        && (sym = (Stab_Sym*)(stab_section->ڈیٹا + انحراف) - 1)
        && sym->n_type == type
        && sym->n_قدر == قدر) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        واپس 0;
    }

    sym = section_ptr_جوڑو(stab_section, حجم(Stab_Sym));
    اگر (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } ورنہ {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_قدر = قدر;
    واپس 1;
}

ساکن خالی put_stabs_r(TCCState *s1, ثابت حرف *str, صحیح type, صحیح other, صحیح desc,
                        غیرعلامتی طویل قدر, Section *sec, صحیح sym_اشاریہ)
{
    اگر (put_stabs(s1, str, type, other, desc, قدر))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->ڈیٹا_انحراف - 4,
                      حجم ((Stab_Sym*)0)->n_قدر == PTR_سائز ? R_ڈیٹا_PTR : R_ڈیٹا_32,
                      sym_اشاریہ);
}

ساکن خالی put_stabn(TCCState *s1, صحیح type, صحیح other, صحیح desc, صحیح قدر)
{
    put_stabs(s1, تہی, type, other, desc, قدر);
}

/* ------------------------------------------------------------------------- */
#تعریف_کرو	dwarf_data1(s,ڈیٹا) \
	(*(uint8_t*)section_ptr_جوڑو((s), 1) = (ڈیٹا))
#تعریف_کرو	dwarf_data2(s,ڈیٹا) \
	write16le(section_ptr_جوڑو((s), 2), (ڈیٹا))
#تعریف_کرو	dwarf_data4(s,ڈیٹا) \
	write32le(section_ptr_جوڑو((s), 4), (ڈیٹا))
#تعریف_کرو	dwarf_data8(s,ڈیٹا) \
	write64le(section_ptr_جوڑو((s), 8), (ڈیٹا))

ساکن صحیح dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    واپس put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_عدد, تہی);
}

ساکن خالی dwarf_reloc(Section *s, صحیح sym, صحیح rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->ڈیٹا_انحراف, rel, sym, 0);
}

ساکن خالی free_str(ساخت dwarf_str_hash **str)
{
    صحیح i;

    برائے (i = 0; i < N_STR_HASH; i++) {
       جب (str[i]) {
           ساخت dwarf_str_hash *اگلا = str[i]->اگلا;

           tcc_free(str[i]);
           str[i] = اگلا;
       }
    }
}

ساکن غیرعلامتی str_hash(ثابت حرف *s)
{
    غیرعلامتی h = 5381;

    جب (*s)
       h += (*s++ & 0xffu) + h * 31;
    واپس h;
}

ساکن خالی dwarf_string(Section *s, Section *dw, صحیح sym, ثابت حرف *str)
{
    TCCState *s1 = s->s1;
    صحیح len, hash = str_hash(str) % N_STR_HASH;
    حرف *ptr;
    ساخت dwarf_str_hash *new_hash;
    ساخت dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_سطر_str;

    len = لڑی_لمبائی(str) + 1;
    new_hash = dw_hash[hash];
    جب (new_hash) {
	اگر (new_hash->len == len &&
	    !memcmp(str, dw->ڈیٹا + new_hash->ڈیٹا_انحراف, len))
	    توڑو;
	new_hash = new_hash->اگلا;
    }
    اگر (new_hash == تہی) {
	غیرعلامتی طویل انحراف = dw->ڈیٹا_انحراف;

        new_hash = dw_hash[hash];
        جب (new_hash) {
	    غیرعلامتی طویل n = new_hash->ڈیٹا_انحراف + new_hash->len - len;

	    اگر (new_hash->len > len &&
	        !memcmp(str, dw->ڈیٹا + n, len)) {
		انحراف = n;
		توڑو;
	    }
	    new_hash = new_hash->اگلا;
        }
	اگر (new_hash == تہی) {
	    ptr = section_ptr_جوڑو(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (ساخت dwarf_str_hash *)
	    tcc_malloc(حجم(ساخت dwarf_str_hash));
	new_hash->len = len;
	new_hash->ڈیٹا_انحراف = انحراف;
	new_hash->اگلا = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->ڈیٹا_انحراف, R_ڈیٹا_32_DW, sym,
                   PTR_سائز == 4 ? 0 : new_hash->ڈیٹا_انحراف);
    dwarf_data4(s, PTR_سائز == 4 ? new_hash->ڈیٹا_انحراف : 0);
}

ساکن خالی dwarf_strp(Section *s, ثابت حرف *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

ساکن خالی dwarf_سطر_strp(Section *s, ثابت حرف *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_سطر_str_section, dwarf_sym.سطر_str, str);
}

ساکن خالی dwarf_سطر_op(TCCState *s1, غیرعلامتی حرف op)
{
    اگر (dwarf_سطر.سطر_سائز >= dwarf_سطر.سطر_max_سائز) {
	dwarf_سطر.سطر_max_سائز += 1024;
	dwarf_سطر.سطر_ڈیٹا =
	    (غیرعلامتی حرف *)tcc_realloc(dwarf_سطر.سطر_ڈیٹا,
					 dwarf_سطر.سطر_max_سائز);
    }
    dwarf_سطر.سطر_ڈیٹا[dwarf_سطر.سطر_سائز++] = op;
}

ساکن خالی dwarf_file(TCCState *s1)
{
    صحیح i, j;
    حرف *filename;
    صحیح اشاریہ_انحراف = s1->dwarf < 5;

    اگر (!strcmp(file->filename, "<command line>")) {
        dwarf_سطر.cur_file = 1;
	واپس;
    }
    filename = strrchr(file->filename, '/');
    اگر (filename == تہی) {
        برائے (i = 1; i < dwarf_سطر.filename_سائز; i++)
            اگر (dwarf_سطر.filename_جدول[i].dir_اندراج == 0 &&
		strcmp(dwarf_سطر.filename_جدول[i].name,
		       file->filename) == 0) {
		    dwarf_سطر.cur_file = i + اشاریہ_انحراف;
	            واپس;
		}
	i = -اشاریہ_انحراف;
	filename = file->filename;
    }
    ورنہ {
	حرف *undo = filename;
	حرف *dir = file->filename;

	*filename++ = '\0';
        برائے (i = 0; i < dwarf_سطر.dir_سائز; i++)
	    اگر (strcmp(dwarf_سطر.dir_جدول[i], dir) == 0) {
		برائے (j = 1; j < dwarf_سطر.filename_سائز; j++)
		    اگر (dwarf_سطر.filename_جدول[j].dir_اندراج - اشاریہ_انحراف
			== i &&
			strcmp(dwarf_سطر.filename_جدول[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_سطر.cur_file = j + اشاریہ_انحراف;
			واپس;
		    }
		توڑو;
	    }
	اگر (i == dwarf_سطر.dir_سائز) {
	    dwarf_سطر.dir_سائز++;
	    dwarf_سطر.dir_جدول =
                (حرف **) tcc_realloc(dwarf_سطر.dir_جدول,
                                      dwarf_سطر.dir_سائز *
                                      حجم (حرف *));
            dwarf_سطر.dir_جدول[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_سطر.filename_جدول =
        (ساخت dwarf_filename_struct *)
        tcc_realloc(dwarf_سطر.filename_جدول,
                    (dwarf_سطر.filename_سائز + 1) *
                    حجم (ساخت dwarf_filename_struct));
    dwarf_سطر.filename_جدول[dwarf_سطر.filename_سائز].dir_اندراج =
	i + اشاریہ_انحراف;
    dwarf_سطر.filename_جدول[dwarf_سطر.filename_سائز].name =
        tcc_strdup(filename);
    dwarf_سطر.cur_file = dwarf_سطر.filename_سائز++ + اشاریہ_انحراف;
    واپس;
}

#اگر 0
ساکن صحیح dwarf_uleb128_سائز (غیرعلامتی طویل طویل قدر)
{
    صحیح سائز =  0;

    کرو {
        قدر >>= 7;
        سائز++;
    } جب (قدر != 0);
    واپس سائز;
}
#اگر_ختم

ساکن صحیح dwarf_sleb128_سائز (طویل طویل قدر)
{
    صحیح سائز =  0;
    طویل طویل انتہا = قدر >> 63;
    غیرعلامتی حرف آخری = انتہا & 0x40;
    غیرعلامتی حرف byte;

    کرو {
        byte = قدر & 0x7f;
        قدر >>= 7;
        سائز++;
    } جب (قدر != انتہا || (byte & 0x40) != آخری);
    واپس سائز;
}

ساکن خالی dwarf_uleb128 (Section *s, غیرعلامتی طویل طویل قدر)
{
    کرو {
        غیرعلامتی حرف byte = قدر & 0x7f;

        قدر >>= 7;
        dwarf_data1(s, byte | (قدر ? 0x80 : 0));
    } جب (قدر != 0);
}

ساکن خالی dwarf_sleb128 (Section *s, طویل طویل قدر)
{
    صحیح مزید;
    طویل طویل انتہا = قدر >> 63;
    غیرعلامتی حرف آخری = انتہا & 0x40;

    کرو {
        غیرعلامتی حرف byte = قدر & 0x7f;

        قدر >>= 7;
	مزید = قدر != انتہا || (byte & 0x40) != آخری;
        dwarf_data1(s, byte | (0x80 * مزید));
    } جب (مزید);
}

ساکن خالی dwarf_uleb128_op (TCCState *s1, غیرعلامتی طویل طویل قدر)
{
    کرو {
        غیرعلامتی حرف byte = قدر & 0x7f;

        قدر >>= 7;
        dwarf_سطر_op(s1, byte | (قدر ? 0x80 : 0));
    } جب (قدر != 0);
}

ساکن خالی dwarf_sleb128_op (TCCState *s1, طویل طویل قدر)
{
    صحیح مزید;
    طویل طویل انتہا = قدر >> 63;
    غیرعلامتی حرف آخری = انتہا & 0x40;

    کرو {
        غیرعلامتی حرف byte = قدر & 0x7f;

        قدر >>= 7;
        مزید = قدر != انتہا || (byte & 0x40) != آخری;
        dwarf_سطر_op(s1, byte | (0x80 * مزید));
    } جب (مزید);
}

#اگر TCC_EH_چوکھٹا
ST_FUNC خالی tcc_eh_چوکھٹا_آغاز(TCCState *s1)
{
    اگر (!s1->unwind_tables)
        واپس;
    eh_چوکھٹا_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_آغاز = eh_چوکھٹا_section->ڈیٹا_انحراف;
    dwarf_data4(eh_چوکھٹا_section, 0); //لمبائی
    dwarf_data4(eh_چوکھٹا_section, 0); // CIE ID
    dwarf_data1(eh_چوکھٹا_section, 1); //نسخہ
    dwarf_data1(eh_چوکھٹا_section, 'z'); // Augmentation String
    dwarf_data1(eh_چوکھٹا_section, 'R');
    dwarf_data1(eh_چوکھٹا_section, 0);
#اگر defined TCC_ہدف_I386
    dwarf_uleb128(eh_چوکھٹا_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_چوکھٹا_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_چوکھٹا_section, 8); // return address column
    dwarf_uleb128(eh_چوکھٹا_section, 1); // Augmentation len
    dwarf_data1(eh_چوکھٹا_section, FDE_ENCODING);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 4); // r4 (esp)
    dwarf_uleb128(eh_چوکھٹا_section, 4); // ofs 4
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_انحراف + 8); // r8 (eip)
    dwarf_uleb128(eh_چوکھٹا_section, 1); // cfa-4
#وگرنہ_اگر defined TCC_ہدف_X86_64
    dwarf_uleb128(eh_چوکھٹا_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_چوکھٹا_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_چوکھٹا_section, 16); // return address column
    dwarf_uleb128(eh_چوکھٹا_section, 1); // Augmentation len
    dwarf_data1(eh_چوکھٹا_section, FDE_ENCODING);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_چوکھٹا_section, 8); // ofs 8
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_انحراف + 16); // r16 (rip)
    dwarf_uleb128(eh_چوکھٹا_section, 1); // cfa-8
#وگرنہ_اگر defined TCC_ہدف_ARM
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
#وگرنہ_اگر defined TCC_ہدف_ARM64
    dwarf_uleb128(eh_چوکھٹا_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_چوکھٹا_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_چوکھٹا_section, 30); // return address column
    dwarf_uleb128(eh_چوکھٹا_section, 1); // Augmentation len
    dwarf_data1(eh_چوکھٹا_section, FDE_ENCODING);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 31); // x31 (sp)
    dwarf_uleb128(eh_چوکھٹا_section, 0); // ofs 0
#وگرنہ_اگر defined TCC_ہدف_RISCV64
    eh_چوکھٹا_section->ڈیٹا[s1->eh_آغاز + 8] = 3; // version = 3
    dwarf_uleb128(eh_چوکھٹا_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_چوکھٹا_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_چوکھٹا_section, 1); // return address column
    dwarf_uleb128(eh_چوکھٹا_section, 1); // Augmentation len
    dwarf_data1(eh_چوکھٹا_section, FDE_ENCODING);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 2); // r2 (sp)
    dwarf_uleb128(eh_چوکھٹا_section, 0); // ofs 0
#اگر_ختم
    جب ((eh_چوکھٹا_section->ڈیٹا_انحراف - s1->eh_آغاز) & 3)
	dwarf_data1(eh_چوکھٹا_section, DW_CFA_nop);
    write32le(eh_چوکھٹا_section->ڈیٹا + s1->eh_آغاز, //لمبائی
	      eh_چوکھٹا_section->ڈیٹا_انحراف - s1->eh_آغاز - 4);
}

ساکن خالی tcc_debug_چوکھٹا_انتہا(TCCState *s1, صحیح سائز)
{
    صحیح eh_section_sym;
    غیرعلامتی طویل fde_آغاز;

    اگر (!eh_چوکھٹا_section)
	واپس;
    eh_section_sym = dwarf_get_section_sym(متن_section);
    fde_آغاز = eh_چوکھٹا_section->ڈیٹا_انحراف;
    dwarf_data4(eh_چوکھٹا_section, 0); //لمبائی
    dwarf_data4(eh_چوکھٹا_section,
		fde_آغاز - s1->eh_آغاز + 4); // CIE Pointer
#اگر defined TCC_ہدف_I386
    dwarf_reloc(eh_چوکھٹا_section, eh_section_sym, R_386_PC32);
#وگرنہ_اگر defined TCC_ہدف_X86_64
    dwarf_reloc(eh_چوکھٹا_section, eh_section_sym, R_X86_64_PC32);
#وگرنہ_اگر defined TCC_ہدف_ARM
    dwarf_reloc(eh_چوکھٹا_section, eh_section_sym, R_ARM_REL32);
#وگرنہ_اگر defined TCC_ہدف_ARM64
    dwarf_reloc(eh_چوکھٹا_section, eh_section_sym, R_AARCH64_PREL32);
#وگرنہ_اگر defined TCC_ہدف_RISCV64
    dwarf_reloc(eh_چوکھٹا_section, eh_section_sym, R_RISCV_32_PCREL);
#اگر_ختم
    dwarf_data4(eh_چوکھٹا_section, func_ind); // PC Begin
    dwarf_data4(eh_چوکھٹا_section, سائز); // PC Range
    dwarf_data1(eh_چوکھٹا_section, 0); // Augmentation Length
#اگر defined TCC_ہدف_I386
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_انحراف);
    dwarf_uleb128(eh_چوکھٹا_section, 8);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_انحراف + 5); // r5 (ebp)
    dwarf_uleb128(eh_چوکھٹا_section, 2); // cfa-8
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_رجسٹر);
    dwarf_uleb128(eh_چوکھٹا_section, 5); // r5 (ebp)
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکھٹا_section, سائز - 5);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_restore + 5); // r5 (ebp)
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 4); // r4 (esp)
    dwarf_uleb128(eh_چوکھٹا_section, 4); // ofs 4
#وگرنہ_اگر defined TCC_ہدف_X86_64
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_انحراف);
    dwarf_uleb128(eh_چوکھٹا_section, 16);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_انحراف + 6); // r6 (rbp)
    dwarf_uleb128(eh_چوکھٹا_section, 2); // cfa-16
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_رجسٹر);
    dwarf_uleb128(eh_چوکھٹا_section, 6); // r6 (rbp)
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکھٹا_section, سائز - 5);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_چوکھٹا_section, 8); // ofs 8
#وگرنہ_اگر defined TCC_ہدف_ARM
    /* TODO */
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_انحراف);
    dwarf_uleb128(eh_چوکھٹا_section, 8);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_انحراف + 14); // r14 (lr)
    dwarf_uleb128(eh_چوکھٹا_section, 1);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_انحراف + 11); // r11 (fp)
    dwarf_uleb128(eh_چوکھٹا_section, 2);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکھٹا_section, سائز / 2 - 5);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_رجسٹر);
    dwarf_uleb128(eh_چوکھٹا_section, 11); // r11 (fp)
#وگرنہ_اگر defined TCC_ہدف_ARM64
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_انحراف);
    dwarf_uleb128(eh_چوکھٹا_section, 224);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_انحراف + 29); // x29 (fp)
    dwarf_uleb128(eh_چوکھٹا_section, 28); // cfa-224
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_انحراف + 30); // x30 (lr)
    dwarf_uleb128(eh_چوکھٹا_section, 27); // cfa-216
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_انحراف);
    dwarf_uleb128(eh_چوکھٹا_section, 224 + ((-loc + 15) & ~15));
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکھٹا_section, سائز / 4 - 5);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_restore + 30); // x30 (lr)
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_restore + 29); // x29 (fp)
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_انحراف);
    dwarf_uleb128(eh_چوکھٹا_section, 0);
#وگرنہ_اگر defined TCC_ہدف_RISCV64
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_انحراف);
    dwarf_uleb128(eh_چوکھٹا_section, 16); // ofs 16
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_انحراف + 1); // r1 (ra, lr)
    dwarf_uleb128(eh_چوکھٹا_section, 2); // cfa-8
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_انحراف + 8); // r8 (s0, fp)
    dwarf_uleb128(eh_چوکھٹا_section, 4); // cfa-16
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 8); // r8 (s0, fp)
    dwarf_uleb128(eh_چوکھٹا_section, 0); // ofs 0
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc4);
    جب (سائز >= 4 &&
	   read32le(cur_متن_section->ڈیٹا + func_ind + سائز - 4) != 0x00008067)
	سائز -= 4;
    dwarf_data4(eh_چوکھٹا_section, سائز - 36);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکھٹا_section, 2); // r2 (r2, sp)
    dwarf_uleb128(eh_چوکھٹا_section, 16); // ofs 16
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_restore + 1); // r1 (lr)
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_restore + 8); // r8 (s0, fp)
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکھٹا_section, DW_CFA_def_cfa_انحراف);
    dwarf_uleb128(eh_چوکھٹا_section, 0); // ofs 0
#اگر_ختم
    جب ((eh_چوکھٹا_section->ڈیٹا_انحراف - fde_آغاز) & 3)
	dwarf_data1(eh_چوکھٹا_section, DW_CFA_nop);
    write32le(eh_چوکھٹا_section->ڈیٹا + fde_آغاز, //لمبائی
	      eh_چوکھٹا_section->ڈیٹا_انحراف - fde_آغاز - 4);
}

ST_FUNC خالی tcc_eh_چوکھٹا_انتہا(TCCState *s1)
{
    اگر (!eh_چوکھٹا_section)
	واپس;
    dwarf_data4(eh_چوکھٹا_section, 0);
}

ساخت eh_تلاش_جدول {
    uint32_t pc_انحراف;
    uint32_t fde_انحراف;
};

ساکن صحیح ترتیب_دو_eh_جدول(ثابت خالی *a, ثابت خالی *b)
{
    uint32_t pc1 = ((ثابت ساخت eh_تلاش_جدول *)a)->pc_انحراف;
    uint32_t pc2 = ((ثابت ساخت eh_تلاش_جدول *)b)->pc_انحراف;

    واپس pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC خالی tcc_eh_چوکھٹا_hdr(TCCState *s1, صحیح final)
{
    صحیح گنتی_2 = 0, انحراف;
    غیرعلامتی طویل گنتی_انحراف, tab_انحراف;
    غیرعلامتی حرف *ln, *انتہا;
    غیرعلامتی صحیح آخری_cie_انحراف = 0xffffffff;

    اگر (!eh_چوکھٹا_section || !eh_چوکھٹا_section->ڈیٹا_انحراف)
	واپس;
    اگر (final && !eh_چوکھٹا_hdr_section)
	واپس;
    اگر (final == 0)
        eh_چوکھٹا_hdr_section =
	    new_section(s1, ".eh_frame_hdr", SHT_PROGBITS, SHF_ALLOC);
    eh_چوکھٹا_hdr_section->ڈیٹا_انحراف = 0;
    dwarf_data1(eh_چوکھٹا_hdr_section, 1); //نسخہ
    // Pointer Encoding Format
    dwarf_data1(eh_چوکھٹا_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_pcrel);
    // Count Encoding Format
    dwarf_data1(eh_چوکھٹا_hdr_section, DW_EH_PE_udata4 | DW_EH_PE_absptr);
    // Table Encoding Format
    dwarf_data1(eh_چوکھٹا_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_datarel);
    انحراف = eh_چوکھٹا_section->sh_addr -
             eh_چوکھٹا_hdr_section->sh_addr -
             eh_چوکھٹا_hdr_section->ڈیٹا_انحراف;
    dwarf_data4(eh_چوکھٹا_hdr_section, انحراف); // eh_frame_ptr
    //گنتی
    گنتی_انحراف = eh_چوکھٹا_hdr_section->ڈیٹا_انحراف;
    dwarf_data4(eh_چوکھٹا_hdr_section, 0);
    tab_انحراف = eh_چوکھٹا_hdr_section->ڈیٹا_انحراف;
    ln = eh_چوکھٹا_section->ڈیٹا;
    انتہا = eh_چوکھٹا_section->ڈیٹا + eh_چوکھٹا_section->ڈیٹا_انحراف;
    جب (ln < انتہا) {
	غیرعلامتی حرف *fde = ln, *rd = ln;
	غیرعلامتی صحیح cie_انحراف, نسخہ, لمبائی = dwarf_read_4(rd, انتہا);
	غیرعلامتی صحیح pc_انحراف, fde_انحراف;

	اگر (لمبائی == 0)
	    جاؤ اگلا;
        cie_انحراف = dwarf_read_4(rd, انتہا);
	اگر (cie_انحراف == 0)
	    جاؤ اگلا;
	اگر (cie_انحراف != آخری_cie_انحراف) {
	    غیرعلامتی حرف *cie = rd - cie_انحراف + 4;

	    اگر (cie < eh_چوکھٹا_section->ڈیٹا)
		جاؤ اگلا;
	    نسخہ = dwarf_read_1(cie, انتہا);
	    اگر ((نسخہ == 1 || نسخہ == 3) &&
	        dwarf_read_1(cie, انتہا) == 'z' && // Augmentation String
		dwarf_read_1(cie, انتہا) == 'R' &&
		dwarf_read_1(cie, انتہا) == 0) {
	        dwarf_read_uleb128(&cie, انتہا); // code_alignment_factor
	        dwarf_read_sleb128(&cie, انتہا); // data_alignment_factor
		dwarf_read_1(cie, انتہا); // return address column
		اگر (dwarf_read_uleb128(&cie, انتہا) == 1 &&
		    dwarf_read_1(cie, انتہا) == FDE_ENCODING) {
		    آخری_cie_انحراف = cie_انحراف;
		}
		ورنہ
		    جاؤ اگلا;
	    }
	    ورنہ
		جاؤ اگلا;
	}
	گنتی_2++;
	fde_انحراف = eh_چوکھٹا_section->sh_addr +
		     (fde - eh_چوکھٹا_section->ڈیٹا) -
		     eh_چوکھٹا_hdr_section->sh_addr;
	pc_انحراف = dwarf_read_4(rd, انتہا) + fde_انحراف + 8;
	dwarf_data4(eh_چوکھٹا_hdr_section, pc_انحراف);
	dwarf_data4(eh_چوکھٹا_hdr_section, fde_انحراف);
اگلا:
	ln += لمبائی + 4;
    }
    add32le(eh_چوکھٹا_hdr_section->ڈیٹا + گنتی_انحراف, گنتی_2);
    qsort(eh_چوکھٹا_hdr_section->ڈیٹا + tab_انحراف, گنتی_2,
	  حجم(ساخت eh_تلاش_جدول), ترتیب_دو_eh_جدول);
}
#اگر_ختم

/* start of translation unit info */
ST_FUNC خالی tcc_debug_آغاز(TCCState *s1)
{
    صحیح i;
    حرف buf[512];
    حرف *filename;

    /* we might currently #include the <command-line> */
    filename = file->پچھلا ? file->پچھلا->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    اگر (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, متن_section->ڈیٹا_انحراف, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            متن_section->sh_عدد, "$a");

        new_file = آخری_سطر_عدد = 0;
        debug_اگلا_type = N_DEFAULT_DEBUG;
        debug_hash_global = تہی;
        debug_hash_local = تہی;
        debug_forw_hash_global = تہی;
        debug_forw_hash_local = تہی;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, حجم(buf));
#اگر_تعریف_شدہ _WIN32
        normalize_slashes(buf);
#اگر_ختم

        اگر (s1->dwarf) {
            صحیح آغاز_abbrev;
            غیرعلامتی حرف *ptr;
	    حرف *undo;

            /* dwarf_abbrev */
            آغاز_abbrev = dwarf_abbrev_section->ڈیٹا_انحراف;
            ptr = section_ptr_جوڑو(dwarf_abbrev_section, حجم(dwarf_abbrev_init));
            حافظہ_نقل(ptr, dwarf_abbrev_init, حجم(dwarf_abbrev_init));

            اگر (s1->dwarf < 5) {
    	        جب (*ptr) {
    	            ptr += 3;
    	            جب (*ptr) {
    	                اگر (ptr[1] == DW_FORM_سطر_strp)
    		            ptr[1] = DW_FORM_strp;
		        اگر (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    اگر  (ptr[1] == DW_FORM_sec_انحراف)
			         ptr[1] = DW_FORM_data4;
			    /* This code uses only size < 0x80 so these are
			       compatible. */
			    اگر  (ptr[1] == DW_FORM_exprloc)
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
            اگر (tcc_state->dwarf >= 5)
    	        dwarf_sym.سطر_str = dwarf_get_section_sym(dwarf_سطر_str_section);
            ورنہ {
    	        dwarf_سطر_str_section = dwarf_str_section;
                dwarf_sym.سطر_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(متن_section);

            /* dwarf_info */
            dwarf_info.آغاز = dwarf_info_section->ڈیٹا_انحراف;
            dwarf_data4(dwarf_info_section, 0); //سائز
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            اگر (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_سائز);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_ڈیٹا_32_DW);
                dwarf_data4(dwarf_info_section, آغاز_abbrev);
            }
            ورنہ {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_ڈیٹا_32_DW);
                dwarf_data4(dwarf_info_section, آغاز_abbrev);
                dwarf_data1(dwarf_info_section, PTR_سائز);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_نسخہ);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_سطر_strp(dwarf_info_section, filename);
            dwarf_سطر_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_ڈیٹا_PTR);
#اگر PTR_سائز == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#ورنہ
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#اگر_ختم
            dwarf_reloc(dwarf_info_section, dwarf_sym.سطر, R_ڈیٹا_32_DW);
            dwarf_data4(dwarf_info_section, dwarf_سطر_section->ڈیٹا_انحراف); // stmt_list

            /* dwarf_line */
            dwarf_سطر.آغاز = dwarf_سطر_section->ڈیٹا_انحراف;
            dwarf_data4(dwarf_سطر_section, 0); //لمبائی
            dwarf_data2(dwarf_سطر_section, s1->dwarf); // version
            اگر (s1->dwarf >= 5) {
                dwarf_data1(dwarf_سطر_section, PTR_سائز); // address size
                dwarf_data1(dwarf_سطر_section, 0); // segment selector
            }
            dwarf_data4(dwarf_سطر_section, 0); // prologue Length
            dwarf_data1(dwarf_سطر_section, DWARF_MIN_INSTR_LEN);
            اگر (s1->dwarf >= 4)
                dwarf_data1(dwarf_سطر_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_سطر_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_سطر_section, DWARF_سطر_بنیاد);
            dwarf_data1(dwarf_سطر_section, DWARF_سطر_RANGE);
            dwarf_data1(dwarf_سطر_section, DWARF_OPCODE_بنیاد);
            ptr = section_ptr_جوڑو(dwarf_سطر_section, حجم(dwarf_سطر_opcodes));
            حافظہ_نقل(ptr, dwarf_سطر_opcodes, حجم(dwarf_سطر_opcodes));
	    undo = strrchr(filename, '/');
	    اگر (undo)
		*undo = 0;
            dwarf_سطر.dir_سائز = 1 + (undo != تہی);
            dwarf_سطر.dir_جدول = (حرف **) tcc_malloc(حجم (حرف *) *
							dwarf_سطر.dir_سائز);
            dwarf_سطر.dir_جدول[0] = tcc_strdup(buf);
	    اگر (undo)
                dwarf_سطر.dir_جدول[1] = tcc_strdup(filename);
            dwarf_سطر.filename_سائز = 2;
            dwarf_سطر.filename_جدول =
    	        (ساخت dwarf_filename_struct *)
    	        tcc_malloc(2*حجم (ساخت dwarf_filename_struct));
            dwarf_سطر.filename_جدول[0].dir_اندراج = 0;
	    اگر (undo) {
                dwarf_سطر.filename_جدول[0].name = tcc_strdup(undo + 1);
                dwarf_سطر.filename_جدول[1].dir_اندراج = 1;
                dwarf_سطر.filename_جدول[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    ورنہ {
                dwarf_سطر.filename_جدول[0].name = tcc_strdup(filename);
                dwarf_سطر.filename_جدول[1].dir_اندراج = 0;
                dwarf_سطر.filename_جدول[1].name = tcc_strdup(filename);
	    }
            dwarf_سطر.سطر_سائز = dwarf_سطر.سطر_max_سائز = 0;
            dwarf_سطر.سطر_ڈیٹا = تہی;
            dwarf_سطر.cur_file = 1;
            dwarf_سطر.آخری_file = 0;
            dwarf_سطر.آخری_pc = 0;
            dwarf_سطر.آخری_سطر = 1;
            dwarf_سطر_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_سائز); // extended size
            dwarf_سطر_op(s1, DW_LNE_سیٹ_پتہ);
            برائے (i = 0; i < PTR_سائز; i++)
    	        dwarf_سطر_op(s1, 0);
            memset(&dwarf_info.بنیاد_type_مستعمل, 0, حجم(dwarf_info.بنیاد_type_مستعمل));
        }
        ورنہ
        {
            /* file info: full path + filename */
            pstrcat(buf, حجم(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      متن_section->sh_عدد, تہی);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        متن_section->ڈیٹا_انحراف, متن_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        متن_section->ڈیٹا_انحراف, متن_section, section_sym);
            برائے (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

ساکن خالی fix_debug_forw_hash(TCCState *s1, صحیح global, صحیح آغاز);

/* put end of translation unit info */
ST_FUNC خالی tcc_debug_انتہا(TCCState *s1)
{

    اگر (!s1->do_debug || debug_اگلا_type == 0)
        واپس;

    اگر (debug_info_جڑ)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    اگر (s1->dwarf) {
	صحیح i;
	صحیح آغاز_aranges;
	غیرعلامتی حرف *ptr;
	صحیح متن_سائز = متن_section->ڈیٹا_انحراف;

	/* dwarf_info */
	fix_debug_forw_hash(s1, 0, 0);
	fix_debug_forw_hash(s1, 1, 0);
	dwarf_data1(dwarf_info_section, 0);
	ptr = dwarf_info_section->ڈیٹا + dwarf_info.آغاز;
	write32le(ptr, dwarf_info_section->ڈیٹا_انحراف - dwarf_info.آغاز - 4);
	write32le(ptr + 25 + (s1->dwarf >= 5) + PTR_سائز, متن_سائز);

	/* dwarf_aranges */
	آغاز_aranges = dwarf_aranges_section->ڈیٹا_انحراف;
	dwarf_data4(dwarf_aranges_section, 0); //سائز
	dwarf_data2(dwarf_aranges_section, 2); // version
	dwarf_reloc(dwarf_aranges_section, dwarf_sym.info, R_ڈیٹا_32_DW);
	dwarf_data4(dwarf_aranges_section, 0); // dwarf_info
#اگر PTR_سائز == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#ورنہ
	dwarf_data1(dwarf_aranges_section, 8); // address size
#اگر_ختم
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_ڈیٹا_PTR);
#اگر PTR_سائز == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, متن_سائز); //انتہا
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#ورنہ
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, متن_سائز); //انتہا
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#اگر_ختم
	ptr = dwarf_aranges_section->ڈیٹا + آغاز_aranges;
	write32le(ptr, dwarf_aranges_section->ڈیٹا_انحراف - آغاز_aranges - 4);

	/* dwarf_line */
	اگر (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_سطر_section, 1); /*ستون*/
	    dwarf_uleb128(dwarf_سطر_section, DW_LNCT_راستہ);
	    dwarf_uleb128(dwarf_سطر_section, DW_FORM_سطر_strp);
	    dwarf_uleb128(dwarf_سطر_section, dwarf_سطر.dir_سائز);
	    برائے (i = 0; i < dwarf_سطر.dir_سائز; i++)
	        dwarf_سطر_strp(dwarf_سطر_section, dwarf_سطر.dir_جدول[i]);
	    dwarf_data1(dwarf_سطر_section, 2); /*ستون*/
	    dwarf_uleb128(dwarf_سطر_section, DW_LNCT_راستہ);
	    dwarf_uleb128(dwarf_سطر_section, DW_FORM_سطر_strp);
	    dwarf_uleb128(dwarf_سطر_section, DW_LNCT_directory_اشاریہ);
	    dwarf_uleb128(dwarf_سطر_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_سطر_section, dwarf_سطر.filename_سائز);
	    برائے (i = 0; i < dwarf_سطر.filename_سائز; i++) {
	        dwarf_سطر_strp(dwarf_سطر_section,
				dwarf_سطر.filename_جدول[i].name);
	        dwarf_uleb128(dwarf_سطر_section,
			      dwarf_سطر.filename_جدول[i].dir_اندراج);
	    }
	}
	ورنہ {
	    صحیح len;

	    برائے (i = 0; i < dwarf_سطر.dir_سائز; i++) {
	        len = لڑی_لمبائی(dwarf_سطر.dir_جدول[i]) + 1;
	        ptr = section_ptr_جوڑو(dwarf_سطر_section, len);
	        memmove(ptr, dwarf_سطر.dir_جدول[i], len);
	    }
	    dwarf_data1(dwarf_سطر_section, 0); /* end dir */
	    برائے (i = 0; i < dwarf_سطر.filename_سائز; i++) {
	        len = لڑی_لمبائی(dwarf_سطر.filename_جدول[i].name) + 1;
	        ptr = section_ptr_جوڑو(dwarf_سطر_section, len);
	        memmove(ptr, dwarf_سطر.filename_جدول[i].name, len);
	        dwarf_uleb128(dwarf_سطر_section,
			      dwarf_سطر.filename_جدول[i].dir_اندراج);
	        dwarf_uleb128(dwarf_سطر_section, 0); /*وقت*/
	        dwarf_uleb128(dwarf_سطر_section, 0); /*سائز*/
	    }
	    dwarf_data1(dwarf_سطر_section, 0); /* end file */
	}
	برائے (i = 0; i < dwarf_سطر.dir_سائز; i++)
	    tcc_free(dwarf_سطر.dir_جدول[i]);
	tcc_free(dwarf_سطر.dir_جدول);
	برائے (i = 0; i < dwarf_سطر.filename_سائز; i++)
	    tcc_free(dwarf_سطر.filename_جدول[i].name);
	tcc_free(dwarf_سطر.filename_جدول);

	dwarf_سطر_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_سطر_op(s1, DW_LNE_انتہا_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_سطر_section->ڈیٹا[dwarf_سطر.آغاز + 6 + i],
		  dwarf_سطر_section->ڈیٹا_انحراف - dwarf_سطر.آغاز - (10 + i));
	section_ptr_جوڑو(dwarf_سطر_section, 3);
	dwarf_reloc(dwarf_سطر_section, section_sym, R_ڈیٹا_PTR);
	ptr = section_ptr_جوڑو(dwarf_سطر_section, dwarf_سطر.سطر_سائز - 3);
	memmove(ptr - 3, dwarf_سطر.سطر_ڈیٹا, dwarf_سطر.سطر_سائز);
	tcc_free(dwarf_سطر.سطر_ڈیٹا);
	write32le(dwarf_سطر_section->ڈیٹا + dwarf_سطر.آغاز,
		  dwarf_سطر_section->ڈیٹا_انحراف - dwarf_سطر.آغاز - 4);
    }
    ورنہ
    {
        put_stabs_r(s1, تہی, N_SO, 0, 0,
                    متن_section->ڈیٹا_انحراف, متن_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_سطر_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_اگلا_type = 0;
}

ساکن BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    اگر (f->filename[0] == ':')
        f = f->پچھلا;
    اگر (f && new_file) {
        new_file = آخری_سطر_عدد = 0;
        اگر (s1->dwarf)
            dwarf_file(s1);
        ورنہ
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, متن_section, section_sym);
    }
    واپس f;
}

/* put alternative filename */
ST_FUNC خالی tcc_debug_newfile(TCCState *s1)
{
    اگر (!s1->do_debug)
        واپس;
    اگر (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC خالی tcc_debug_bincl(TCCState *s1)
{
    اگر (!s1->do_debug)
        واپس;
    اگر (s1->dwarf)
        dwarf_file(s1);
    ورنہ
        put_stabs(s1, file->filename, N_BINCL, 0, 0, 0);
    new_file = 1;
}

/* end of #include */
ST_FUNC خالی tcc_debug_eincl(TCCState *s1)
{
    اگر (!s1->do_debug)
        واپس;
    اگر (s1->dwarf)
        dwarf_file(s1);
    ورنہ
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC خالی tcc_debug_سطر(TCCState *s1)
{
    BufferedFile *f;

    اگر (!s1->do_debug)
        واپس;
    اگر (cur_متن_section != متن_section || nocode_wanted)
        واپس;
    f = put_new_file(s1);
    اگر (!f)
        واپس;
    اگر (آخری_سطر_عدد == f->سطر_عدد)
        واپس;
    آخری_سطر_عدد = f->سطر_عدد;

    اگر (s1->dwarf) {
	صحیح len_pc = (ind - dwarf_سطر.آخری_pc) / DWARF_MIN_INSTR_LEN;
	صحیح len_سطر = f->سطر_عدد - dwarf_سطر.آخری_سطر;
	صحیح n = len_pc * DWARF_سطر_RANGE + len_سطر + DWARF_OPCODE_بنیاد - DWARF_سطر_بنیاد;

	اگر (dwarf_سطر.cur_file != dwarf_سطر.آخری_file) {
	    dwarf_سطر.آخری_file = dwarf_سطر.cur_file;
	    dwarf_سطر_op(s1, DW_LNS_سیٹ_file);
	    dwarf_uleb128_op(s1, dwarf_سطر.cur_file);
	}
	اگر (len_pc &&
	    len_سطر >= DWARF_سطر_بنیاد && len_سطر <= (DWARF_OPCODE_بنیاد + DWARF_سطر_بنیاد) &&
	    n >= DWARF_OPCODE_بنیاد && n <= 255)
            dwarf_سطر_op(s1, n);
	ورنہ {
	    اگر (len_pc) {
	        n = len_pc * DWARF_سطر_RANGE + 0 + DWARF_OPCODE_بنیاد - DWARF_سطر_بنیاد;
	        اگر (n >= DWARF_OPCODE_بنیاد && n <= 255)
                    dwarf_سطر_op(s1, n);
		ورنہ {
	            dwarf_سطر_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    اگر (len_سطر) {
	        n = 0 * DWARF_سطر_RANGE + len_سطر + DWARF_OPCODE_بنیاد - DWARF_سطر_بنیاد;
	        اگر (len_سطر >= DWARF_سطر_بنیاد && len_سطر <= (DWARF_OPCODE_بنیاد + DWARF_سطر_بنیاد) &&
		    n >= DWARF_OPCODE_بنیاد && n <= 255)
	            dwarf_سطر_op(s1, n);
		ورنہ {
	            dwarf_سطر_op(s1, DW_LNS_advance_سطر);
		    dwarf_sleb128_op(s1, len_سطر);
                    /* advance by nothing */
	            dwarf_سطر_op(s1, DWARF_OPCODE_بنیاد - DWARF_سطر_بنیاد);
		}
	    }
	}
	dwarf_سطر.آخری_pc = ind;
	dwarf_سطر.آخری_سطر = f->سطر_عدد;
    }
    ورنہ
    {
	اگر (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->سطر_عدد, ind - func_ind);
        } ورنہ {
            /* from tcc_assemble */
            put_stabs_r(s1, تہی, N_SLINE, 0, f->سطر_عدد, ind, متن_section, section_sym);
        }
    }
}

ساکن خالی tcc_debug_stabs (TCCState *s1, ثابت حرف *str, صحیح type, غیرعلامتی طویل قدر,
                             Section *sec, صحیح sym_اشاریہ, صحیح info)
{
    ساخت debug_sym *s;

    اگر (debug_info) {
        debug_info->sym =
            (ساخت debug_sym *)tcc_realloc (debug_info->sym,
                                             حجم(ساخت debug_sym) *
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
    ورنہ اگر (sec)
        put_stabs_r (s1, str, type, 0, 0, قدر, sec, sym_اشاریہ);
    ورنہ
        put_stabs (s1, str, type, 0, 0, قدر);
}

ساکن خالی fix_debug_forw_hash(TCCState *s1, صحیح global, صحیح آغاز)
{
    اگر (s1->dwarf) {
        صحیح i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	ساخت _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	برائے (i = آغاز; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    صحیح pos = dwarf_info_section->ڈیٹا_انحراف;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_خالی_خانے_TYPE
                                             : DWARF_ABBREV_STRUCTURE_خالی_خانے_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_پہلا_ANOM
                       ? "" : get_tok_str(t->v, تہی));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_سطر.cur_file);
            dwarf_uleb128(dwarf_info_section, file->سطر_عدد);
	    برائے (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->ڈیٹا +
			  hash[i].debug_type[j],
			  pos - dwarf_info.آغاز);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC خالی tcc_debug_stabn(TCCState *s1, صحیح type, صحیح قدر)
{
    اگر (!s1->do_debug)
        واپس;
    اگر (type == N_LBRAC) {
        ساخت _debug_info *info =
            (ساخت _debug_info *) tcc_mallocz(حجم (*info));

        info->آغاز = قدر;
        info->آخری_debug_hash = n_debug_hash_local;
        info->آخری_debug_forw_hash = n_debug_forw_hash_local;
        info->والد = debug_info;
        اگر (debug_info) {
            اگر (debug_info->بچہ) {
                اگر (debug_info->بچہ->آخری)
                    debug_info->بچہ->آخری->اگلا = info;
                ورنہ
                    debug_info->بچہ->اگلا = info;
                debug_info->بچہ->آخری = info;
            }
            ورنہ
                debug_info->بچہ = info;
        }
        ورنہ
            debug_info_جڑ = info;
        debug_info = info;
    }
    ورنہ {
	fix_debug_forw_hash(s1, 0, debug_info->آخری_debug_forw_hash);
        n_debug_hash_local = debug_info->آخری_debug_hash;
        n_debug_forw_hash_local = debug_info->آخری_debug_forw_hash;
        debug_info->انتہا = قدر;
        debug_info = debug_info->والد;
    }
}

ساکن صحیح check_global(Sym *t)
{
    Sym *g = local_ڈھیر;

    جب (g) {
	اگر (t == g)
	    واپس 0;
	g = g->پچھلا;
    }
    واپس 1;
}

ساکن صحیح tcc_debug_ڈھونڈو(TCCState *s1, Sym *t, صحیح dwarf)
{
    صحیح i , g = check_global(t);
    صحیح n_hash, *n_forw_hash;
    ساخت _debug_hash *hash;
    ساخت _debug_forw_hash **forw_hash;

    اگر ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	برائے (i = 0; i < *n_forw_hash; i++)
            اگر (t == (*forw_hash)[i].type)
		واپس 0;
	*forw_hash = (ساخت _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * حجم(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = تہی;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	واپس 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    برائے (i = 0; i < n_hash; i++)
        اگر (t == hash[i].type)
	    واپس hash[i].debug_type;
    واپس -1;
}

ساکن صحیح tcc_get_dwarf_info(TCCState *s1, Sym *s);

ساکن خالی tcc_debug_check_forw(TCCState *s1, Sym *t, صحیح debug_type)
{
    اگر ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        صحیح i, j, g = check_global(t);
        صحیح n_forw_hash;
        ساخت _debug_forw_hash **forw_hash;

	برائے (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    برائے (j = 0; j < n_forw_hash; j++)
                اگر (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * حجم(صحیح));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    واپس;
                }
	}
    }
}

ساکن خالی stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC خالی tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    اگر (!(s1->do_debug & 2))
	واپس;
    اگر (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        واپس;
    }
    اگر ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        صحیح i, j, debug_type, g = check_global(t->ref);
        صحیح *n_forw_hash;
        ساخت _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	برائے (i = 0; i < *n_forw_hash; i++)
	    اگر (t->ref == (*forw_hash)[i].type) {
		اگر (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    برائے (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->ڈیٹا +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.آغاز);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		برائے (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

ساکن صحیح tcc_debug_جوڑو(TCCState *s1, Sym *t, صحیح dwarf)
{
    صحیح انحراف = dwarf ? dwarf_info_section->ڈیٹا_انحراف : ++debug_اگلا_type;
    صحیح *n_hash, g = check_global(t);
    ساخت _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (ساخت _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * حجم(**hash));
    (*hash)[*n_hash].debug_type = انحراف;
    (*hash)[(*n_hash)++].type = t;
    واپس انحراف;
}

ساکن صحیح STRUCT_NODEBUG(Sym *s)
{
    واپس
    (s->a.nodebug ||
     ((s->v & ~SYM_میدان) >= SYM_پہلا_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

ساکن صحیح stabs_struct_ڈھونڈو(TCCState *s1, Sym *t, صحیح *p_id)
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
    اگر (تہی == p_id)
        واپس s && !s->r && t->c >= 0;
    اگر (تہی == s) {
        /* just use global_stack always */
        s = sym_push2(&global_ڈھیر, SYM_میدان|0x00DEBBED, 0, ++debug_اگلا_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    اگر (s->r || t->c < 0) /* already defined or still incomplete */
        واپس 0;
    s->r = 1;
    واپس 1;
}

ساکن صحیح remove_type_info(صحیح type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        اگر ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        اگر (!(type & VT_BITFIELD) && (type & VT_STRUCT_نقاب) > VT_ENUM)
	    type &= ~VT_STRUCT_نقاب;
	واپس type;
}

ساکن خالی tcc_get_debug_info(TCCState *s1, Sym *s, CString *نتیجہ)
{
    صحیح type;
    صحیح n = 0;
    صحیح debug_type = -1;
    Sym *t = s;
    CString str;

    برائے (;;) {
        type = remove_type_info (t->type.t);
        اگر (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        ورنہ
            توڑو;
    }
    اگر ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        اگر (stabs_struct_ڈھونڈو(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_پہلا_ANOM
                         ? "" : get_tok_str(t->v, تہی),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            جب (t->اگلا) {
                صحیح pos, سائز, align;
                t = t->اگلا;
		اگر (STRUCT_NODEBUG(t))
		    جاری;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_میدان) >= SYM_پہلا_ANOM
                             ? "" : get_tok_str(t->v, تہی)
                             );
                tcc_get_debug_info (s1, t, &str);
                اگر (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + ثنائی_ہندسہ_POS(t->type.t);
                    سائز = ثنائی_ہندسہ_سائز(t->type.t);
                }
                ورنہ {
                    pos = t->c * 8;
                    سائز = type_سائز(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, سائز);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.ڈیٹا, N_LSYM, 0, تہی, 0, 0);
            cstr_free (&str);
        }
    }
    ورنہ اگر (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        اگر (stabs_struct_ڈھونڈو(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_پہلا_ANOM
                         ? "" : get_tok_str(t->v, تہی),
                         debug_type);
            جب (t->اگلا) {
                t = t->اگلا;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_میدان) >= SYM_پہلا_ANOM
                             ? "" : get_tok_str(t->v, تہی));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (صحیح)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.ڈیٹا, N_LSYM, 0, تہی, 0, 0);
            cstr_free (&str);
	}
    }
    ورنہ اگر ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_نقاب;
        برائے (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            اگر (default_debug[debug_type - 1].type == type)
                توڑو;
        اگر (debug_type > N_DEFAULT_DEBUG)
            واپس;
    }

    اگر (تہی == نتیجہ) /* from stabs_struct_complete() */
        واپس;

    اگر (n > 0)
        cstr_printf (نتیجہ, "%d=", ++debug_اگلا_type);
    t = s;
    برائے (;;) {
        type = remove_type_info (t->type.t);
        اگر (type == VT_PTR)
            cstr_printf (نتیجہ, "%d=*", ++debug_اگلا_type);
        ورنہ اگر (type == (VT_PTR | VT_ARRAY))
            cstr_printf (نتیجہ, "%d=ar1;0;%d;",
                         ++debug_اگلا_type, t->type.ref->c - 1);
        ورنہ اگر (type == VT_FUNC) {
            cstr_printf (نتیجہ, "%d=f", ++debug_اگلا_type);
            tcc_get_debug_info (s1, t->type.ref, نتیجہ);
            واپس;
        }
        ورنہ
            توڑو;
        t = t->type.ref;
    }
    cstr_printf (نتیجہ, "%d", debug_type);
}

ساکن خالی stabs_struct_complete(TCCState *s1, CType *t)
{
    اگر (stabs_struct_ڈھونڈو(s1, t->ref, تہی)) {
        Sym s = {0}; s.type = *t;
        tcc_get_debug_info(s1, &s, تہی);
    }
}

ساکن صحیح tcc_get_dwarf_info(TCCState *s1, Sym *s)
{
    صحیح type;
    صحیح debug_type = -1;
    Sym *e, *t = s;
    صحیح i;
    صحیح آخری_pos = -1;
    صحیح retval;

    اگر (new_file)
        put_new_file(s1);
    برائے (;;) {
        type = remove_type_info (t->type.t);
        اگر (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        ورنہ
            توڑو;
    }
    اگر ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_ڈھونڈو(s1, t, 1);
	اگر (debug_type == -1) {
	    صحیح pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_جوڑو(s1, t, 1);
	    e = t;
	    i = 0;
	    جب (e->اگلا) {
		e = e->اگلا;
		اگر (STRUCT_NODEBUG(e))
		    جاری;
		i++;
	    }
	    pos_type = (صحیح *) tcc_malloc(i * حجم(صحیح));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->اگلا ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_خالی_خانے_TYPE
		        : t->اگلا ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_خالی_خانے_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_پہلا_ANOM
                       ? "" : get_tok_str(t->v, تہی));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_سطر.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->سطر_عدد);
	    اگر (t->اگلا) {
	        pos_sib = dwarf_info_section->ڈیٹا_انحراف;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            جب (e->اگلا) {
                e = e->اگلا;
		اگر (STRUCT_NODEBUG(e))
		    جاری;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, تہی));
		dwarf_uleb128(dwarf_info_section, dwarf_سطر.cur_file);
		dwarf_uleb128(dwarf_info_section, file->سطر_عدد);
		pos_type[i++] = dwarf_info_section->ڈیٹا_انحراف;
		dwarf_data4(dwarf_info_section, 0);
                اگر (e->type.t & VT_BITFIELD) {
                    صحیح pos = e->c * 8 + ثنائی_ہندسہ_POS(e->type.t);
                    صحیح سائز = ثنائی_ہندسہ_سائز(e->type.t);

		    dwarf_uleb128(dwarf_info_section, سائز);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		ورنہ
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    اگر (t->اگلا) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->ڈیٹا + pos_sib,
		          dwarf_info_section->ڈیٹا_انحراف - dwarf_info.آغاز);
	    }
	    e = t;
	    i = 0;
	    جب (e->اگلا) {
		e = e->اگلا;
		اگر (STRUCT_NODEBUG(e))
		    جاری;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->ڈیٹا + pos_type[i++],
			  type - dwarf_info.آغاز);
	    }
	    tcc_free(pos_type);
        }
    }
    ورنہ اگر (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_ڈھونڈو(s1, t, 1);
	اگر (debug_type == -1) {
	    صحیح pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_جوڑو(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_پہلا_ANOM
                       ? "" : get_tok_str(t->v, تہی));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.آغاز);
	    dwarf_uleb128(dwarf_info_section, dwarf_سطر.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->سطر_عدد);
	    pos_sib = dwarf_info_section->ڈیٹا_انحراف;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            جب (e->اگلا) {
                e = e->اگلا;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_میدان) >= SYM_پہلا_ANOM
                           ? "" : get_tok_str(e->v, تہی));
		اگر (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		ورنہ
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->ڈیٹا + pos_sib,
		      dwarf_info_section->ڈیٹا_انحراف - dwarf_info.آغاز);
	}
    }
    ورنہ اگر ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_نقاب;
        برائے (i = 1; i <= N_DEFAULT_DEBUG; i++)
            اگر (default_debug[i - 1].type == type)
                توڑو;
        اگر (i > N_DEFAULT_DEBUG)
            واپس 0;
	debug_type = dwarf_info.بنیاد_type_مستعمل[i - 1];
	اگر (debug_type == 0) {
	    حرف name[100];

	    debug_type = dwarf_info_section->ڈیٹا_انحراف;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_بنیاد_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].سائز);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, حجم name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.بنیاد_type_مستعمل[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = تہی;
    t = s;
    برائے (;;) {
        type = remove_type_info (t->type.t);
        اگر (type == VT_PTR) {
	    i = dwarf_info_section->ڈیٹا_انحراف;
	    اگر (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_اشارہ_گر);
	    dwarf_data1(dwarf_info_section, PTR_سائز);
	    اگر (آخری_pos != -1) {
		tcc_debug_check_forw(s1, e, آخری_pos);
		write32le(dwarf_info_section->ڈیٹا + آخری_pos,
			  i - dwarf_info.آغاز);
	    }
	    آخری_pos = dwarf_info_section->ڈیٹا_انحراف;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        ورنہ اگر (type == (VT_PTR | VT_ARRAY)) {
	    صحیح sib_pos, sub_type;
#اگر LONG_سائز == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#ورنہ
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#اگر_ختم

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->ڈیٹا_انحراف;
	    اگر (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    اگر (آخری_pos != -1) {
		tcc_debug_check_forw(s1, e, آخری_pos);
		write32le(dwarf_info_section->ڈیٹا + آخری_pos,
			  i - dwarf_info.آغاز);
	    }
	    آخری_pos = dwarf_info_section->ڈیٹا_انحراف;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->ڈیٹا_انحراف;
	    dwarf_data4(dwarf_info_section, 0);
	    برائے (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.آغاز);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		اگر (type != (VT_PTR | VT_ARRAY))
		    توڑو;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->ڈیٹا + sib_pos,
		      dwarf_info_section->ڈیٹا_انحراف - dwarf_info.آغاز);
	}
        ورنہ اگر (type == VT_FUNC) {
	    صحیح sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->ڈیٹا_انحراف;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    اگر (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->اگلا ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_خالی_خانے_TYPE);
	    اگر (آخری_pos != -1) {
		tcc_debug_check_forw(s1, e, آخری_pos);
		write32le(dwarf_info_section->ڈیٹا + آخری_pos,
			  i - dwarf_info.آغاز);
	    }
	    آخری_pos = dwarf_info_section->ڈیٹا_انحراف;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    اگر (t->type.ref->اگلا) {
	        sib_pos = dwarf_info_section->ڈیٹا_انحراف;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    جب (f->اگلا) {
		f = f->اگلا;
		i++;
	    }
	    pos_type = (صحیح *) tcc_malloc(i * حجم(صحیح));
	    f = t->type.ref;
	    i = 0;
	    جب (f->اگلا) {
		f = f->اگلا;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->ڈیٹا_انحراف;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    اگر (t->type.ref->اگلا) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->ڈیٹا + sib_pos,
		          dwarf_info_section->ڈیٹا_انحراف - dwarf_info.آغاز);
	    }
	    f = t->type.ref;
	    i = 0;
	    جب (f->اگلا) {
		f = f->اگلا;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->ڈیٹا + pos_type[i++],
                          type - dwarf_info.آغاز);
	    }
	    tcc_free(pos_type);
        }
        ورنہ {
	    اگر (آخری_pos != -1) {
		tcc_debug_check_forw(s1, e, آخری_pos);
		write32le(dwarf_info_section->ڈیٹا + آخری_pos,
			  debug_type - dwarf_info.آغاز);
	    }
            توڑو;
	}
        t = t->type.ref;
    }
    واپس retval;
}

ساکن خالی tcc_debug_اختتام (TCCState *s1, ساخت _debug_info *cur)
{
    جب (cur) {
        ساخت _debug_info *اگلا = cur->اگلا;
        صحیح i;

        اگر (s1->dwarf) {

            برائے (i = cur->n_sym - 1; i >= 0; i--) {
                ساخت debug_sym *s = &cur->sym[i];

		dwarf_data1(dwarf_info_section,
                            s->type == N_PSYM
			    ? DWARF_ABBREV_FORMAL_PARAMETER
			    : s->type == N_GSYM
                            ? DWARF_ABBREV_VARIABLE_EXTERNAL
                            : s->type == N_STSYM
			    ? DWARF_ABBREV_VARIABLE_STATIC
			    : DWARF_ABBREV_VARIABLE_LOCAL);
                dwarf_strp(dwarf_info_section, s->str);
		اگر (s->type == N_GSYM || s->type == N_STSYM) {
                    dwarf_uleb128(dwarf_info_section, s->file);
                    dwarf_uleb128(dwarf_info_section, s->سطر);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.آغاز);
		اگر (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    اگر (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_سائز + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    اگر (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_ڈیٹا_PTR);
#اگر PTR_سائز == 4
                    dwarf_data4(dwarf_info_section, s->قدر);
#ورنہ
                    dwarf_data8(dwarf_info_section, s->قدر);
#اگر_ختم
		}
		ورنہ {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_سائز((طویل)s->قدر) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (طویل)s->قدر);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->بچہ ? DWARF_ABBREV_LEXICAL_بلاک
			           : DWARF_ABBREV_LEXICAL_خالی_خانے_بلاک);
            dwarf_reloc(dwarf_info_section, section_sym, R_ڈیٹا_PTR);
#اگر PTR_سائز == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->آغاز);
            dwarf_data4(dwarf_info_section, cur->انتہا - cur->آغاز);
#ورنہ
            dwarf_data8(dwarf_info_section, func_ind + cur->آغاز);
            dwarf_data8(dwarf_info_section, cur->انتہا - cur->آغاز);
#اگر_ختم
            tcc_debug_اختتام (s1, cur->بچہ);
	    اگر (cur->بچہ)
                dwarf_data1(dwarf_info_section, 0);
        }
        ورنہ
        {
            برائے (i = 0; i < cur->n_sym; i++) {
                ساخت debug_sym *s = &cur->sym[i];

                اگر (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->قدر,
                                s->sec, s->sym_اشاریہ);
                ورنہ
                    put_stabs(s1, s->str, s->type, 0, 0, s->قدر);
                tcc_free (s->str);
            }
            tcc_free (cur->sym);
            put_stabn(s1, N_LBRAC, 0, 0, cur->آغاز);
            tcc_debug_اختتام (s1, cur->بچہ);
            put_stabn(s1, N_RBRAC, 0, 0, cur->انتہا);
        }
        tcc_free (cur);
        cur = اگلا;
    }
}

ST_FUNC خالی tcc_جوڑو_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    صحیح param;

    اگر (!(s1->do_debug & 2))
        واپس;

    cstr_new (&debug_str);
    param = !e;
    برائے (; s != e; s = s->پچھلا) {
        اگر (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            جاری;
	اگر (s1->dwarf) {
	    tcc_debug_stabs(s1, get_tok_str(s->v, تہی),
			    param ? N_PSYM : N_LSYM, s->c, تہی, 0,
			    tcc_get_dwarf_info(s1, s));
	}
	ورنہ
        {
            cstr_reset (&debug_str);
            cstr_printf (&debug_str, "%s:%s", get_tok_str(s->v, تہی),
			 param ? "p" : "");
            tcc_get_debug_info(s1, s, &debug_str);
            tcc_debug_stabs(s1, debug_str.ڈیٹا, param ? N_PSYM : N_LSYM,
			    s->c, تہی, 0, 0);
	}
    }
    cstr_free (&debug_str);
}

/* put function symbol */
ST_FUNC خالی tcc_debug_funcstart(TCCState *s1, Sym *sym)
{
    CString debug_str;
    BufferedFile *f;

    اگر (!s1->do_debug)
        واپس;
    debug_info_جڑ = تہی;
    debug_info = تہی;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    اگر (!f)
	واپس;

    اگر (s1->dwarf) {
        tcc_debug_سطر(s1);
        dwarf_info.func = sym;
        dwarf_info.سطر = file->سطر_عدد;
	اگر (s1->do_backtrace) {
	    صحیح i, len;

	    dwarf_سطر_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, لڑی_لمبائی(funcname) + 2);
	    dwarf_سطر_op(s1, DW_LNE_hi_user - 1);
	    len = لڑی_لمبائی(funcname) + 1;
	    برائے (i = 0; i < len; i++)
		dwarf_سطر_op(s1, funcname[i]);
	}
    }
    ورنہ
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.ڈیٹا, N_FUN, 0, f->سطر_عدد, 0, cur_متن_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_سطر(s1);
    }
}

ST_FUNC خالی tcc_debug_prolog_epilog(TCCState *s1, صحیح قدر)
{
    اگر (!s1->do_debug)
        واپس;
    اگر (s1->dwarf) {
	dwarf_سطر_op(s1, قدر == 0 ? DW_LNS_سیٹ_prologue_انتہا
				     : DW_LNS_سیٹ_epilogue_begin);
    }
}

/* put function size */
ST_FUNC خالی tcc_debug_funcend(TCCState *s1, صحیح سائز)
{
    /* lldb does not like function end and next function start at same pc */
    صحیح min_instr_len;

#اگر TCC_EH_چوکھٹا
    tcc_debug_چوکھٹا_انتہا(s1, سائز);
#اگر_ختم
    اگر (!s1->do_debug)
        واپس;
    min_instr_len = dwarf_سطر.آخری_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_سطر(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, سائز);
    اگر (s1->dwarf) {
        صحیح func_sib = 0;
	Sym *sym = dwarf_info.func;
	صحیح n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        اگر ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_سطر.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.سطر);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->ڈیٹا_انحراف);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.آغاز);
        dwarf_reloc(dwarf_info_section, section_sym, R_ڈیٹا_PTR);
#اگر PTR_سائز == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, سائز); // high_pc
#ورنہ
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, سائز); // high_pc
#اگر_ختم
        func_sib = dwarf_info_section->ڈیٹا_انحراف;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#اگر defined(TCC_ہدف_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#وگرنہ_اگر defined(TCC_ہدف_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#وگرنہ_اگر defined TCC_ہدف_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#وگرنہ_اگر defined TCC_ہدف_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#وگرنہ_اگر defined TCC_ہدف_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#ورنہ
        dwarf_data1(dwarf_info_section, DW_OP_call_چوکھٹا_cfa);
#اگر_ختم
        tcc_debug_اختتام (s1, debug_info_جڑ);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->ڈیٹا + func_sib,
                  dwarf_info_section->ڈیٹا_انحراف - dwarf_info.آغاز);
    }
    ورنہ
    {
        tcc_debug_اختتام (s1, debug_info_جڑ);
    }
    debug_info_جڑ = 0;
}


ST_FUNC خالی tcc_debug_extern_sym(TCCState *s1, Sym *sym, صحیح sh_عدد, صحیح sym_bind, صحیح sym_type)
{
    اگر (!(s1->do_debug & 2))
        واپس;

    اگر (sym_type == STT_FUNC || sym->v >= SYM_پہلا_ANOM)
        واپس;
    اگر (s1->dwarf) {
        صحیح debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, تہی));
	dwarf_uleb128(dwarf_info_section, dwarf_سطر.cur_file);
	dwarf_uleb128(dwarf_info_section, file->سطر_عدد);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->ڈیٹا_انحراف);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.آغاز);
	اگر (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_سائز + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->ڈیٹا_انحراف,
		R_ڈیٹا_PTR, 0);
#اگر PTR_سائز == 4
	dwarf_data4(dwarf_info_section, 0);
#ورنہ
	dwarf_data8(dwarf_info_section, 0);
#اگر_ختم
    }
    ورنہ
    {
        Section *s = sh_عدد == SHN_COMMON ? common_section
					  : s1->sections[sh_عدد];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, تہی),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        اگر (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.ڈیٹا, N_GSYM, 0, تہی, 0, 0);
        ورنہ
            tcc_debug_stabs(s1, str.ڈیٹا,
                (sym->type.t & VT_STATIC) && ڈیٹا_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC خالی tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    اگر (!(s1->do_debug & 2))
        واپس;

    اگر (s1->dwarf) {
	صحیح debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	اگر (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, تہی));
	    dwarf_uleb128(dwarf_info_section, dwarf_سطر.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->سطر_عدد);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->ڈیٹا_انحراف);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.آغاز);
	}
    }
    ورنہ
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, تہی));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.ڈیٹا, N_LSYM, 0, تہی, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC خالی tcc_tcov_بلاک_انتہا(TCCState *s1, صحیح سطر);

ST_FUNC خالی tcc_tcov_بلاک_begin(TCCState *s1)
{
    SValue sv;
    خالی *ptr;
    غیرعلامتی طویل آخری_انحراف = tcov_ڈیٹا.انحراف;

    tcc_tcov_بلاک_انتہا (tcc_state, 0);
    اگر (s1->test_coverage == 0 || nocode_wanted)
	واپس;

    اگر (tcov_ڈیٹا.آخری_file_name == 0 ||
	strcmp ((ثابت حرف *)(tcov_section->ڈیٹا + tcov_ڈیٹا.آخری_file_name),
		file->true_filename) != 0) {
	حرف wd[1024];
	CString cstr;

	اگر (tcov_ڈیٹا.آخری_func_name)
	    section_ptr_جوڑو(tcov_section, 1);
	اگر (tcov_ڈیٹا.آخری_file_name)
	    section_ptr_جوڑو(tcov_section, 1);
	tcov_ڈیٹا.آخری_func_name = 0;
	cstr_new (&cstr);
	اگر (file->true_filename[0] == '/') {
	    tcov_ڈیٹا.آخری_file_name = tcov_section->ڈیٹا_انحراف;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	ورنہ {
	    getcwd (wd, حجم(wd));
	    tcov_ڈیٹا.آخری_file_name = tcov_section->ڈیٹا_انحراف + لڑی_لمبائی(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_جوڑو(tcov_section, cstr.سائز + 1);
	strcpy((حرف *)ptr, cstr.ڈیٹا);
#اگر_تعریف_شدہ _WIN32
        normalize_slashes((حرف *)ptr);
#اگر_ختم
	cstr_free (&cstr);
    }
    اگر (tcov_ڈیٹا.آخری_func_name == 0 ||
	strcmp ((ثابت حرف *)(tcov_section->ڈیٹا + tcov_ڈیٹا.آخری_func_name),
		funcname) != 0) {
	سائز_t len;

	اگر (tcov_ڈیٹا.آخری_func_name)
	    section_ptr_جوڑو(tcov_section, 1);
	tcov_ڈیٹا.آخری_func_name = tcov_section->ڈیٹا_انحراف;
	len = لڑی_لمبائی (funcname);
	ptr = section_ptr_جوڑو(tcov_section, len + 1);
	strcpy((حرف *)ptr, funcname);
	section_ptr_جوڑو(tcov_section, -tcov_section->ڈیٹا_انحراف & 7);
	ptr = section_ptr_جوڑو(tcov_section, 8);
	write64le (ptr, file->سطر_عدد);
    }
    اگر (ind == tcov_ڈیٹا.ind && tcov_ڈیٹا.سطر == file->سطر_عدد)
        tcov_ڈیٹا.انحراف = آخری_انحراف;
    ورنہ {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_جوڑو(tcov_section, 16);
        tcov_ڈیٹا.سطر = file->سطر_عدد;
        write64le (ptr, (tcov_ڈیٹا.سطر << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((غیرعلامتی حرف *)ptr - tcov_section->ڈیٹا) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#اگر defined TCC_ہدف_I386 || defined TCC_ہدف_X86_64 || \
    defined TCC_ہدف_ARM || defined TCC_ہدف_ARM64 || \
    defined TCC_ہدف_RISCV64
        gen_increment_tcov (&sv);
#ورنہ
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#اگر_ختم
        tcov_ڈیٹا.انحراف = (غیرعلامتی حرف *)ptr - tcov_section->ڈیٹا;
        tcov_ڈیٹا.ind = ind;
    }
}

ST_FUNC خالی tcc_tcov_بلاک_انتہا(TCCState *s1, صحیح سطر)
{
    اگر (s1->test_coverage == 0)
	واپس;
    اگر (سطر == -1)
        سطر = tcov_ڈیٹا.سطر;
    اگر (tcov_ڈیٹا.انحراف) {
	خالی *ptr = tcov_section->ڈیٹا + tcov_ڈیٹا.انحراف;
	غیرعلامتی طویل طویل nline = سطر ? سطر : file->سطر_عدد;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_ڈیٹا.انحراف = 0;
    }
}

ST_FUNC خالی tcc_tcov_check_سطر(TCCState *s1, صحیح آغاز)
{
    اگر (s1->test_coverage == 0)
	واپس;
    اگر (tcov_ڈیٹا.سطر != file->سطر_عدد) {
        اگر ((tcov_ڈیٹا.سطر + 1) != file->سطر_عدد) {
	    tcc_tcov_بلاک_انتہا (s1, -1);
	    اگر (آغاز)
                tcc_tcov_بلاک_begin (s1);
	}
	ورنہ
	    tcov_ڈیٹا.سطر = file->سطر_عدد;
    }
}

ST_FUNC خالی tcc_tcov_آغاز(TCCState *s1)
{
    اگر (s1->test_coverage == 0)
	واپس;
    اگر (!s1->dState)
        s1->dState = tcc_mallocz(حجم *s1->dState);
    memset (&tcov_ڈیٹا, 0, حجم (tcov_ڈیٹا));
    اگر (tcov_section == تہی) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_جوڑو(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC خالی tcc_tcov_انتہا(TCCState *s1)
{
    اگر (s1->test_coverage == 0)
	واپس;
    اگر (tcov_ڈیٹا.آخری_func_name)
        section_ptr_جوڑو(tcov_section, 1);
    اگر (tcov_ڈیٹا.آخری_file_name)
        section_ptr_جوڑو(tcov_section, 1);
}

ST_FUNC خالی tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_ڈیٹا.ind = 0;
}

/* ------------------------------------------------------------------------- */
#تعریف_منسوخ آخری_سطر_عدد
#تعریف_منسوخ new_file
#تعریف_منسوخ section_sym
#تعریف_منسوخ debug_اگلا_type
#تعریف_منسوخ debug_hash_global
#تعریف_منسوخ debug_hash_local
#تعریف_منسوخ n_debug_hash_global
#تعریف_منسوخ n_debug_hash_local
#تعریف_منسوخ debug_forw_hash_global
#تعریف_منسوخ debug_forw_hash_local
#تعریف_منسوخ n_debug_forw_hash_global
#تعریف_منسوخ n_debug_forw_hash_local
#تعریف_منسوخ debug_info
#تعریف_منسوخ debug_info_جڑ
#تعریف_منسوخ dwarf_sym
#تعریف_منسوخ dwarf_سطر
#تعریف_منسوخ dwarf_info
#تعریف_منسوخ dwarf_str
#تعریف_منسوخ dwarf_سطر_str
#تعریف_منسوخ tcov_ڈیٹا
