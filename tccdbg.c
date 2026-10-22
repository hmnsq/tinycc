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
  صحيح اندازه;
  صحيح encoding;
  ثابت حرف *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#إذا LONG_اندازه == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#وإلا
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#د_که_پای
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#إذا LONG_اندازه == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#وإلا
    /* use octal instead of -1 so size_t works (-gstabs+ in gcc) */
    {   VT_LLONG | VT_LONG | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t5=r5;0;01777777777777777777777;" },
#د_که_پای
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
#که_تعریف_شوی TCC_USING_DOUBLE_FOR_LDOUBLE
    {   VT_DOUBLE | VT_LONG, 8, DW_ATE_float, "long double:t16=r1;8;0;" },
#وإلا
    {   VT_LDOUBLE, 16, DW_ATE_float, "long double:t16=r1;16;0;" },
#د_که_پای
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
#إذا LONG_اندازه == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#وإلا
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#د_که_پای
};

#تعریف_کړه	N_DEFAULT_DEBUG	(حجم (default_debug) / حجم (default_debug[0]))

/* dwarf debug */

#تعریف_کړه	DWARF_کرښه_بنسټ				-5
#تعریف_کړه	DWARF_کرښه_RANGE			14
#تعریف_کړه	DWARF_OPCODE_بنسټ			13

#إذا defined TCC_موخه_ARM64
#تعریف_کړه	DWARF_MIN_INSTR_LEN			4
#وإلاإذا defined TCC_موخه_ARM
#تعریف_کړه	DWARF_MIN_INSTR_LEN			2
#وإلا
#تعریف_کړه	DWARF_MIN_INSTR_LEN			1
#د_که_پای

#تعریف_کړه	DWARF_ABBREV_COMPILE_UNIT		1
#تعریف_کړه	DWARF_ABBREV_بنسټ_TYPE			2
#تعریف_کړه	DWARF_ABBREV_VARIABLE_EXTERNAL		3
#تعریف_کړه	DWARF_ABBREV_VARIABLE_STATIC		4
#تعریف_کړه	DWARF_ABBREV_VARIABLE_LOCAL		5
#تعریف_کړه	DWARF_ABBREV_FORMAL_PARAMETER		6
#تعریف_کړه	DWARF_ABBREV_اشاره_ګر			7
#تعریف_کړه	DWARF_ABBREV_ARRAY_TYPE			8
#تعریف_کړه	DWARF_ABBREV_SUBRANGE_TYPE		9
#تعریف_کړه	DWARF_ABBREV_TYPEDEF			10
#تعریف_کړه	DWARF_ABBREV_ENUMERATOR_SIGNED		11
#تعریف_کړه	DWARF_ABBREV_ENUMERATOR_UNSIGNED	12
#تعریف_کړه	DWARF_ABBREV_ENUMERATION_TYPE		13
#تعریف_کړه	DWARF_ABBREV_MEMBER			14
#تعریف_کړه	DWARF_ABBREV_MEMBER_BF			15
#تعریف_کړه	DWARF_ABBREV_STRUCTURE_TYPE		16
#تعریف_کړه	DWARF_ABBREV_STRUCTURE_تشه_TYPE	17
#تعریف_کړه	DWARF_ABBREV_UNION_TYPE			18
#تعریف_کړه	DWARF_ABBREV_UNION_تشه_TYPE		19
#تعریف_کړه	DWARF_ABBREV_SUBPROGRAM_EXTERNAL	20
#تعریف_کړه	DWARF_ABBREV_SUBPROGRAM_STATIC		21
#تعریف_کړه	DWARF_ABBREV_LEXICAL_بلاک		22
#تعریف_کړه	DWARF_ABBREV_LEXICAL_تشه_بلاک	23
#تعریف_کړه	DWARF_ABBREV_SUBROUTINE_TYPE		24
#تعریف_کړه	DWARF_ABBREV_SUBROUTINE_تشه_TYPE	25
#تعریف_کړه	DWARF_ABBREV_FORMAL_PARAMETER2		26

/* all entries should have been generated with dwarf_uleb128 except
   has_children. All values are currently below 128 so this currently
   works.  */
ساكن ثابت بینښه حرف dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_نښان_compile_unit, 1,
          DW_AT_تولیدوونکی, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_کرښه_strp,
          DW_AT_comp_dir, DW_FORM_کرښه_strp,
          DW_AT_ټیټ_pc, DW_FORM_addr,
#إذا PTR_اندازه == 4
          DW_AT_لوړ_pc, DW_FORM_data4,
#وإلا
          DW_AT_لوړ_pc, DW_FORM_data8,
#د_که_پای
          DW_AT_stmt_list, DW_FORM_sec_دننه_واټن,
          0, 0,
    DWARF_ABBREV_بنسټ_TYPE, DW_نښان_بنسټ_type, 0,
          DW_AT_byte_اندازه, DW_FORM_udata,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_name, DW_FORM_strp,
          0, 0,
    DWARF_ABBREV_VARIABLE_EXTERNAL, DW_نښان_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_کرښه, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_نښان_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_کرښه, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_LOCAL, DW_نښان_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER, DW_نښان_formal_parameter, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_اشاره_ګر, DW_نښان_اشاره_ګر_type, 0,
          DW_AT_byte_اندازه, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ARRAY_TYPE, DW_نښان_array_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBRANGE_TYPE, DW_نښان_subrange_type, 0,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_پاسنی_bound, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_TYPEDEF, DW_نښان_typedef, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_کرښه, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_نښان_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_ارزښت, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_نښان_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_ارزښت, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_نښان_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_اندازه, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_کرښه, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_نښان_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_کرښه, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_معلومات_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_نښان_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_کرښه, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_بټ_اندازه, DW_FORM_udata,
          DW_AT_معلومات_بټ_دننه_واټن, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_نښان_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_اندازه, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_کرښه, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_تشه_TYPE, DW_نښان_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_اندازه, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_کرښه, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_نښان_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_اندازه, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_کرښه, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_تشه_TYPE, DW_نښان_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_اندازه, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_کرښه, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_نښان_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_کرښه, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ټیټ_pc, DW_FORM_addr,
#إذا PTR_اندازه == 4
          DW_AT_لوړ_pc, DW_FORM_data4,
#وإلا
          DW_AT_لوړ_pc, DW_FORM_data8,
#د_که_پای
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_چوکاټ_بنسټ, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_نښان_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_کرښه, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ټیټ_pc, DW_FORM_addr,
#إذا PTR_اندازه == 4
          DW_AT_لوړ_pc, DW_FORM_data4,
#وإلا
          DW_AT_لوړ_pc, DW_FORM_data8,
#د_که_پای
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_چوکاټ_بنسټ, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_بلاک, DW_نښان_lexical_بلاک, 1,
          DW_AT_ټیټ_pc, DW_FORM_addr,
#إذا PTR_اندازه == 4
          DW_AT_لوړ_pc, DW_FORM_data4,
#وإلا
          DW_AT_لوړ_pc, DW_FORM_data8,
#د_که_پای
          0, 0,
    DWARF_ABBREV_LEXICAL_تشه_بلاک, DW_نښان_lexical_بلاک, 0,
          DW_AT_ټیټ_pc, DW_FORM_addr,
#إذا PTR_اندازه == 4
          DW_AT_لوړ_pc, DW_FORM_data4,
#وإلا
          DW_AT_لوړ_pc, DW_FORM_data8,
#د_که_پای
          0, 0,
    DWARF_ABBREV_SUBROUTINE_TYPE, DW_نښان_subroutine_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBROUTINE_تشه_TYPE, DW_نښان_subroutine_type, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER2, DW_نښان_formal_parameter, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
  0
};

ساكن ثابت بینښه حرف dwarf_کرښه_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#تعریف_کړه N_STR_HASH (251)

بنية dwarf_str_hash {
    صحيح len;
    بینښه اوږد معلومات_دننه_واټن;
    بنية dwarf_str_hash *بل;
};

بنية _tccdbg {

    صحيح وروستی_کرښه_عدد, new_file;
    صحيح section_sym;

    صحيح debug_بل_type;

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
        صحيح پیل;
        صحيح پای_ټکی;
        صحيح وروستی_debug_hash;
        صحيح وروستی_debug_forw_hash;
        صحيح n_sym;
        بنية debug_sym {
            صحيح type;
            بینښه اوږد ارزښت;
            حرف *str;
            Section *sec;
            صحيح sym_شاخص;
            صحيح info;
            صحيح file;
            صحيح کرښه;
        } *sym;
        بنية _debug_info *ماشوم, *بل, *وروستی, *پلار;
    } *debug_info, *debug_info_ریښه;

    بنية {
        صحيح info;
        صحيح abbrev;
        صحيح کرښه;
        صحيح str;
        صحيح کرښه_str;
    } dwarf_sym;

    بنية {
        صحيح پیل;
        صحيح dir_اندازه;
        حرف **dir_جدول;
        صحيح filename_اندازه;
        بنية dwarf_filename_struct {
            صحيح dir_ثبت;
            حرف *name;
        } *filename_جدول;
        صحيح کرښه_اندازه;
        صحيح کرښه_max_اندازه;
        بینښه حرف *کرښه_معلومات;
        صحيح cur_file;
        صحيح وروستی_file;
        صحيح وروستی_pc;
        صحيح وروستی_کرښه;
    } dwarf_کرښه;

    بنية {
        صحيح پیل;
        Sym *func;
        صحيح کرښه;
        صحيح بنسټ_type_کارول_شوی[N_DEFAULT_DEBUG];
    } dwarf_info;

    بنية dwarf_str_hash *dwarf_str[N_STR_HASH];
    بنية dwarf_str_hash *dwarf_کرښه_str[N_STR_HASH];

    /* test coverage */
    بنية {
        بینښه اوږد دننه_واټن;
        بینښه اوږد وروستی_file_name;
        بینښه اوږد وروستی_func_name;
        صحيح ind;
        صحيح کرښه;
    } tcov_معلومات;
};

#تعریف_کړه وروستی_کرښه_عدد             s1->dState->وروستی_کرښه_عدد
#تعریف_کړه new_file                  s1->dState->new_file
#تعریف_کړه section_sym               s1->dState->section_sym
#تعریف_کړه debug_بل_type           s1->dState->debug_بل_type
#تعریف_کړه debug_hash_global         s1->dState->debug_hash_global
#تعریف_کړه debug_hash_local          s1->dState->debug_hash_local
#تعریف_کړه debug_forw_hash_global    s1->dState->debug_forw_hash_global
#تعریف_کړه debug_forw_hash_local     s1->dState->debug_forw_hash_local
#تعریف_کړه n_debug_hash_global       s1->dState->n_debug_hash_global
#تعریف_کړه n_debug_hash_local        s1->dState->n_debug_hash_local
#تعریف_کړه n_debug_forw_hash_global  s1->dState->n_debug_forw_hash_global
#تعریف_کړه n_debug_forw_hash_local   s1->dState->n_debug_forw_hash_local
#تعریف_کړه debug_info                s1->dState->debug_info
#تعریف_کړه debug_info_ریښه           s1->dState->debug_info_ریښه
#تعریف_کړه dwarf_sym                 s1->dState->dwarf_sym
#تعریف_کړه dwarf_کرښه                s1->dState->dwarf_کرښه
#تعریف_کړه dwarf_info                s1->dState->dwarf_info
#تعریف_کړه dwarf_str                 s1->dState->dwarf_str
#تعریف_کړه dwarf_کرښه_str            s1->dState->dwarf_کرښه_str
#تعریف_کړه tcov_معلومات                 s1->dState->tcov_معلومات

#تعریف_کړه	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
ساكن صحيح put_stabs(TCCState *s1, ثابت حرف *str, صحيح type, صحيح other,
    صحيح desc, بینښه اوږد ارزښت);

ST_FUNC فراغ tcc_debug_new(TCCState *s1)
{
    صحيح shf = 0;
    إذا (!s1->dState)
        s1->dState = tcc_mallocz(حجم *s1->dState);

#که_تعریف_شوی CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    إذا (s1->do_debug && s1->output_type == TCC_OUTPUT_حافظه)
        s1->do_backtrace = 1;
    إذا (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#د_که_پای

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
        dwarf_کرښه_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	لكل (i = 0; i < حجم(debug)/حجم(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_یوځای | SHF_مزي_ګانې;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_کرښه_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	إذا (s1->dwarf >= 5) {
            dwarf_کرښه_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_کرښه_str_section->sh_entsize = 1;
	    dwarf_کرښه_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    وإلا
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = حجم(Stab_Sym);
        stab_section->sh_addralign = حجم ((Stab_Sym*)0)->n_ارزښت;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
ساكن صحيح put_stabs(TCCState *s1, ثابت حرف *str, صحيح type, صحيح other, صحيح desc,
                      بینښه اوږد ارزښت)
{
    Stab_Sym *sym;

    بینښه دننه_واټن;
    إذا (type == N_SLINE
        && (دننه_واټن = stab_section->معلومات_دننه_واټن)
        && (sym = (Stab_Sym*)(stab_section->معلومات + دننه_واټن) - 1)
        && sym->n_type == type
        && sym->n_ارزښت == ارزښت) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        أرجع 0;
    }

    sym = section_ptr_جمع_کړه(stab_section, حجم(Stab_Sym));
    إذا (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } وإلا {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_ارزښت = ارزښت;
    أرجع 1;
}

ساكن فراغ put_stabs_r(TCCState *s1, ثابت حرف *str, صحيح type, صحيح other, صحيح desc,
                        بینښه اوږد ارزښت, Section *sec, صحيح sym_شاخص)
{
    إذا (put_stabs(s1, str, type, other, desc, ارزښت))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->معلومات_دننه_واټن - 4,
                      حجم ((Stab_Sym*)0)->n_ارزښت == PTR_اندازه ? R_معلومات_PTR : R_معلومات_32,
                      sym_شاخص);
}

ساكن فراغ put_stabn(TCCState *s1, صحيح type, صحيح other, صحيح desc, صحيح ارزښت)
{
    put_stabs(s1, عدم, type, other, desc, ارزښت);
}

/* ------------------------------------------------------------------------- */
#تعریف_کړه	dwarf_data1(s,معلومات) \
	(*(uint8_t*)section_ptr_جمع_کړه((s), 1) = (معلومات))
#تعریف_کړه	dwarf_data2(s,معلومات) \
	write16le(section_ptr_جمع_کړه((s), 2), (معلومات))
#تعریف_کړه	dwarf_data4(s,معلومات) \
	write32le(section_ptr_جمع_کړه((s), 4), (معلومات))
#تعریف_کړه	dwarf_data8(s,معلومات) \
	write64le(section_ptr_جمع_کړه((s), 8), (معلومات))

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
    put_elf_reloca(symtab_section, s, s->معلومات_دننه_واټن, rel, sym, 0);
}

ساكن فراغ free_str(بنية dwarf_str_hash **str)
{
    صحيح i;

    لكل (i = 0; i < N_STR_HASH; i++) {
       طالما (str[i]) {
           بنية dwarf_str_hash *بل = str[i]->بل;

           tcc_free(str[i]);
           str[i] = بل;
       }
    }
}

ساكن بینښه str_hash(ثابت حرف *s)
{
    بینښه h = 5381;

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
	dw == dwarf_str_section ? dwarf_str : dwarf_کرښه_str;

    len = مزي_اوږدوالی(str) + 1;
    new_hash = dw_hash[hash];
    طالما (new_hash) {
	إذا (new_hash->len == len &&
	    !memcmp(str, dw->معلومات + new_hash->معلومات_دننه_واټن, len))
	    اكسر;
	new_hash = new_hash->بل;
    }
    إذا (new_hash == عدم) {
	بینښه اوږد دننه_واټن = dw->معلومات_دننه_واټن;

        new_hash = dw_hash[hash];
        طالما (new_hash) {
	    بینښه اوږد n = new_hash->معلومات_دننه_واټن + new_hash->len - len;

	    إذا (new_hash->len > len &&
	        !memcmp(str, dw->معلومات + n, len)) {
		دننه_واټن = n;
		اكسر;
	    }
	    new_hash = new_hash->بل;
        }
	إذا (new_hash == عدم) {
	    ptr = section_ptr_جمع_کړه(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (بنية dwarf_str_hash *)
	    tcc_malloc(حجم(بنية dwarf_str_hash));
	new_hash->len = len;
	new_hash->معلومات_دننه_واټن = دننه_واټن;
	new_hash->بل = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->معلومات_دننه_واټن, R_معلومات_32_DW, sym,
                   PTR_اندازه == 4 ? 0 : new_hash->معلومات_دننه_واټن);
    dwarf_data4(s, PTR_اندازه == 4 ? new_hash->معلومات_دننه_واټن : 0);
}

ساكن فراغ dwarf_strp(Section *s, ثابت حرف *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

ساكن فراغ dwarf_کرښه_strp(Section *s, ثابت حرف *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_کرښه_str_section, dwarf_sym.کرښه_str, str);
}

ساكن فراغ dwarf_کرښه_op(TCCState *s1, بینښه حرف op)
{
    إذا (dwarf_کرښه.کرښه_اندازه >= dwarf_کرښه.کرښه_max_اندازه) {
	dwarf_کرښه.کرښه_max_اندازه += 1024;
	dwarf_کرښه.کرښه_معلومات =
	    (بینښه حرف *)tcc_realloc(dwarf_کرښه.کرښه_معلومات,
					 dwarf_کرښه.کرښه_max_اندازه);
    }
    dwarf_کرښه.کرښه_معلومات[dwarf_کرښه.کرښه_اندازه++] = op;
}

ساكن فراغ dwarf_file(TCCState *s1)
{
    صحيح i, j;
    حرف *filename;
    صحيح شاخص_دننه_واټن = s1->dwarf < 5;

    إذا (!strcmp(file->filename, "<command line>")) {
        dwarf_کرښه.cur_file = 1;
	أرجع;
    }
    filename = strrchr(file->filename, '/');
    إذا (filename == عدم) {
        لكل (i = 1; i < dwarf_کرښه.filename_اندازه; i++)
            إذا (dwarf_کرښه.filename_جدول[i].dir_ثبت == 0 &&
		strcmp(dwarf_کرښه.filename_جدول[i].name,
		       file->filename) == 0) {
		    dwarf_کرښه.cur_file = i + شاخص_دننه_واټن;
	            أرجع;
		}
	i = -شاخص_دننه_واټن;
	filename = file->filename;
    }
    وإلا {
	حرف *undo = filename;
	حرف *dir = file->filename;

	*filename++ = '\0';
        لكل (i = 0; i < dwarf_کرښه.dir_اندازه; i++)
	    إذا (strcmp(dwarf_کرښه.dir_جدول[i], dir) == 0) {
		لكل (j = 1; j < dwarf_کرښه.filename_اندازه; j++)
		    إذا (dwarf_کرښه.filename_جدول[j].dir_ثبت - شاخص_دننه_واټن
			== i &&
			strcmp(dwarf_کرښه.filename_جدول[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_کرښه.cur_file = j + شاخص_دننه_واټن;
			أرجع;
		    }
		اكسر;
	    }
	إذا (i == dwarf_کرښه.dir_اندازه) {
	    dwarf_کرښه.dir_اندازه++;
	    dwarf_کرښه.dir_جدول =
                (حرف **) tcc_realloc(dwarf_کرښه.dir_جدول,
                                      dwarf_کرښه.dir_اندازه *
                                      حجم (حرف *));
            dwarf_کرښه.dir_جدول[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_کرښه.filename_جدول =
        (بنية dwarf_filename_struct *)
        tcc_realloc(dwarf_کرښه.filename_جدول,
                    (dwarf_کرښه.filename_اندازه + 1) *
                    حجم (بنية dwarf_filename_struct));
    dwarf_کرښه.filename_جدول[dwarf_کرښه.filename_اندازه].dir_ثبت =
	i + شاخص_دننه_واټن;
    dwarf_کرښه.filename_جدول[dwarf_کرښه.filename_اندازه].name =
        tcc_strdup(filename);
    dwarf_کرښه.cur_file = dwarf_کرښه.filename_اندازه++ + شاخص_دننه_واټن;
    أرجع;
}

#إذا 0
ساكن صحيح dwarf_uleb128_اندازه (بینښه اوږد اوږد ارزښت)
{
    صحيح اندازه =  0;

    افعل {
        ارزښت >>= 7;
        اندازه++;
    } طالما (ارزښت != 0);
    أرجع اندازه;
}
#د_که_پای

ساكن صحيح dwarf_sleb128_اندازه (اوږد اوږد ارزښت)
{
    صحيح اندازه =  0;
    اوږد اوږد پای_ټکی = ارزښت >> 63;
    بینښه حرف وروستی = پای_ټکی & 0x40;
    بینښه حرف byte;

    افعل {
        byte = ارزښت & 0x7f;
        ارزښت >>= 7;
        اندازه++;
    } طالما (ارزښت != پای_ټکی || (byte & 0x40) != وروستی);
    أرجع اندازه;
}

ساكن فراغ dwarf_uleb128 (Section *s, بینښه اوږد اوږد ارزښت)
{
    افعل {
        بینښه حرف byte = ارزښت & 0x7f;

        ارزښت >>= 7;
        dwarf_data1(s, byte | (ارزښت ? 0x80 : 0));
    } طالما (ارزښت != 0);
}

ساكن فراغ dwarf_sleb128 (Section *s, اوږد اوږد ارزښت)
{
    صحيح نور;
    اوږد اوږد پای_ټکی = ارزښت >> 63;
    بینښه حرف وروستی = پای_ټکی & 0x40;

    افعل {
        بینښه حرف byte = ارزښت & 0x7f;

        ارزښت >>= 7;
	نور = ارزښت != پای_ټکی || (byte & 0x40) != وروستی;
        dwarf_data1(s, byte | (0x80 * نور));
    } طالما (نور);
}

ساكن فراغ dwarf_uleb128_op (TCCState *s1, بینښه اوږد اوږد ارزښت)
{
    افعل {
        بینښه حرف byte = ارزښت & 0x7f;

        ارزښت >>= 7;
        dwarf_کرښه_op(s1, byte | (ارزښت ? 0x80 : 0));
    } طالما (ارزښت != 0);
}

ساكن فراغ dwarf_sleb128_op (TCCState *s1, اوږد اوږد ارزښت)
{
    صحيح نور;
    اوږد اوږد پای_ټکی = ارزښت >> 63;
    بینښه حرف وروستی = پای_ټکی & 0x40;

    افعل {
        بینښه حرف byte = ارزښت & 0x7f;

        ارزښت >>= 7;
        نور = ارزښت != پای_ټکی || (byte & 0x40) != وروستی;
        dwarf_کرښه_op(s1, byte | (0x80 * نور));
    } طالما (نور);
}

#إذا TCC_EH_چوکاټ
ST_FUNC فراغ tcc_eh_چوکاټ_پیل(TCCState *s1)
{
    إذا (!s1->unwind_tables)
        أرجع;
    eh_چوکاټ_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_پیل = eh_چوکاټ_section->معلومات_دننه_واټن;
    dwarf_data4(eh_چوکاټ_section, 0); //اوږدتیا
    dwarf_data4(eh_چوکاټ_section, 0); // CIE ID
    dwarf_data1(eh_چوکاټ_section, 1); //نسخه
    dwarf_data1(eh_چوکاټ_section, 'z'); // Augmentation String
    dwarf_data1(eh_چوکاټ_section, 'R');
    dwarf_data1(eh_چوکاټ_section, 0);
#إذا defined TCC_موخه_I386
    dwarf_uleb128(eh_چوکاټ_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_چوکاټ_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_چوکاټ_section, 8); // return address column
    dwarf_uleb128(eh_چوکاټ_section, 1); // Augmentation len
    dwarf_data1(eh_چوکاټ_section, FDE_ENCODING);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکاټ_section, 4); // r4 (esp)
    dwarf_uleb128(eh_چوکاټ_section, 4); // ofs 4
    dwarf_data1(eh_چوکاټ_section, DW_CFA_دننه_واټن + 8); // r8 (eip)
    dwarf_uleb128(eh_چوکاټ_section, 1); // cfa-4
#وإلاإذا defined TCC_موخه_X86_64
    dwarf_uleb128(eh_چوکاټ_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_چوکاټ_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_چوکاټ_section, 16); // return address column
    dwarf_uleb128(eh_چوکاټ_section, 1); // Augmentation len
    dwarf_data1(eh_چوکاټ_section, FDE_ENCODING);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکاټ_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_چوکاټ_section, 8); // ofs 8
    dwarf_data1(eh_چوکاټ_section, DW_CFA_دننه_واټن + 16); // r16 (rip)
    dwarf_uleb128(eh_چوکاټ_section, 1); // cfa-8
#وإلاإذا defined TCC_موخه_ARM
    /* TODO: arm must be compiled with: -funwind-tables */
    /* arm also uses .ARM.extab and .ARM.exidx sections */
    dwarf_uleb128(eh_چوکاټ_section, 2); // code_alignment_factor
    dwarf_sleb128(eh_چوکاټ_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_چوکاټ_section, 14); // return address column
    dwarf_uleb128(eh_چوکاټ_section, 1); // Augmentation len
    dwarf_data1(eh_چوکاټ_section, FDE_ENCODING);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکاټ_section, 13); // r13 (sp)
    dwarf_uleb128(eh_چوکاټ_section, 0); // ofs 0
#وإلاإذا defined TCC_موخه_ARM64
    dwarf_uleb128(eh_چوکاټ_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_چوکاټ_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_چوکاټ_section, 30); // return address column
    dwarf_uleb128(eh_چوکاټ_section, 1); // Augmentation len
    dwarf_data1(eh_چوکاټ_section, FDE_ENCODING);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکاټ_section, 31); // x31 (sp)
    dwarf_uleb128(eh_چوکاټ_section, 0); // ofs 0
#وإلاإذا defined TCC_موخه_RISCV64
    eh_چوکاټ_section->معلومات[s1->eh_پیل + 8] = 3; // version = 3
    dwarf_uleb128(eh_چوکاټ_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_چوکاټ_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_چوکاټ_section, 1); // return address column
    dwarf_uleb128(eh_چوکاټ_section, 1); // Augmentation len
    dwarf_data1(eh_چوکاټ_section, FDE_ENCODING);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکاټ_section, 2); // r2 (sp)
    dwarf_uleb128(eh_چوکاټ_section, 0); // ofs 0
#د_که_پای
    طالما ((eh_چوکاټ_section->معلومات_دننه_واټن - s1->eh_پیل) & 3)
	dwarf_data1(eh_چوکاټ_section, DW_CFA_nop);
    write32le(eh_چوکاټ_section->معلومات + s1->eh_پیل, //اوږدتیا
	      eh_چوکاټ_section->معلومات_دننه_واټن - s1->eh_پیل - 4);
}

ساكن فراغ tcc_debug_چوکاټ_پای_ټکی(TCCState *s1, صحيح اندازه)
{
    صحيح eh_section_sym;
    بینښه اوږد fde_پیل;

    إذا (!eh_چوکاټ_section)
	أرجع;
    eh_section_sym = dwarf_get_section_sym(متن_section);
    fde_پیل = eh_چوکاټ_section->معلومات_دننه_واټن;
    dwarf_data4(eh_چوکاټ_section, 0); //اوږدتیا
    dwarf_data4(eh_چوکاټ_section,
		fde_پیل - s1->eh_پیل + 4); // CIE Pointer
#إذا defined TCC_موخه_I386
    dwarf_reloc(eh_چوکاټ_section, eh_section_sym, R_386_PC32);
#وإلاإذا defined TCC_موخه_X86_64
    dwarf_reloc(eh_چوکاټ_section, eh_section_sym, R_X86_64_PC32);
#وإلاإذا defined TCC_موخه_ARM
    dwarf_reloc(eh_چوکاټ_section, eh_section_sym, R_ARM_REL32);
#وإلاإذا defined TCC_موخه_ARM64
    dwarf_reloc(eh_چوکاټ_section, eh_section_sym, R_AARCH64_PREL32);
#وإلاإذا defined TCC_موخه_RISCV64
    dwarf_reloc(eh_چوکاټ_section, eh_section_sym, R_RISCV_32_PCREL);
#د_که_پای
    dwarf_data4(eh_چوکاټ_section, func_ind); // PC Begin
    dwarf_data4(eh_چوکاټ_section, اندازه); // PC Range
    dwarf_data1(eh_چوکاټ_section, 0); // Augmentation Length
#إذا defined TCC_موخه_I386
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa_دننه_واټن);
    dwarf_uleb128(eh_چوکاټ_section, 8);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_دننه_واټن + 5); // r5 (ebp)
    dwarf_uleb128(eh_چوکاټ_section, 2); // cfa-8
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa_ثبتوونکی);
    dwarf_uleb128(eh_چوکاټ_section, 5); // r5 (ebp)
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکاټ_section, اندازه - 5);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_restore + 5); // r5 (ebp)
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکاټ_section, 4); // r4 (esp)
    dwarf_uleb128(eh_چوکاټ_section, 4); // ofs 4
#وإلاإذا defined TCC_موخه_X86_64
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa_دننه_واټن);
    dwarf_uleb128(eh_چوکاټ_section, 16);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_دننه_واټن + 6); // r6 (rbp)
    dwarf_uleb128(eh_چوکاټ_section, 2); // cfa-16
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa_ثبتوونکی);
    dwarf_uleb128(eh_چوکاټ_section, 6); // r6 (rbp)
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکاټ_section, اندازه - 5);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکاټ_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_چوکاټ_section, 8); // ofs 8
#وإلاإذا defined TCC_موخه_ARM
    /* TODO */
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa_دننه_واټن);
    dwarf_uleb128(eh_چوکاټ_section, 8);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_دننه_واټن + 14); // r14 (lr)
    dwarf_uleb128(eh_چوکاټ_section, 1);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_دننه_واټن + 11); // r11 (fp)
    dwarf_uleb128(eh_چوکاټ_section, 2);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکاټ_section, اندازه / 2 - 5);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa_ثبتوونکی);
    dwarf_uleb128(eh_چوکاټ_section, 11); // r11 (fp)
#وإلاإذا defined TCC_موخه_ARM64
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa_دننه_واټن);
    dwarf_uleb128(eh_چوکاټ_section, 224);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_دننه_واټن + 29); // x29 (fp)
    dwarf_uleb128(eh_چوکاټ_section, 28); // cfa-224
    dwarf_data1(eh_چوکاټ_section, DW_CFA_دننه_واټن + 30); // x30 (lr)
    dwarf_uleb128(eh_چوکاټ_section, 27); // cfa-216
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa_دننه_واټن);
    dwarf_uleb128(eh_چوکاټ_section, 224 + ((-loc + 15) & ~15));
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکاټ_section, اندازه / 4 - 5);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_restore + 30); // x30 (lr)
    dwarf_data1(eh_چوکاټ_section, DW_CFA_restore + 29); // x29 (fp)
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa_دننه_واټن);
    dwarf_uleb128(eh_چوکاټ_section, 0);
#وإلاإذا defined TCC_موخه_RISCV64
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa_دننه_واټن);
    dwarf_uleb128(eh_چوکاټ_section, 16); // ofs 16
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_دننه_واټن + 1); // r1 (ra, lr)
    dwarf_uleb128(eh_چوکاټ_section, 2); // cfa-8
    dwarf_data1(eh_چوکاټ_section, DW_CFA_دننه_واټن + 8); // r8 (s0, fp)
    dwarf_uleb128(eh_چوکاټ_section, 4); // cfa-16
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکاټ_section, 8); // r8 (s0, fp)
    dwarf_uleb128(eh_چوکاټ_section, 0); // ofs 0
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc4);
    طالما (اندازه >= 4 &&
	   read32le(cur_متن_section->معلومات + func_ind + اندازه - 4) != 0x00008067)
	اندازه -= 4;
    dwarf_data4(eh_چوکاټ_section, اندازه - 36);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکاټ_section, 2); // r2 (r2, sp)
    dwarf_uleb128(eh_چوکاټ_section, 16); // ofs 16
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_restore + 1); // r1 (lr)
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_restore + 8); // r8 (s0, fp)
    dwarf_data1(eh_چوکاټ_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکاټ_section, DW_CFA_def_cfa_دننه_واټن);
    dwarf_uleb128(eh_چوکاټ_section, 0); // ofs 0
#د_که_پای
    طالما ((eh_چوکاټ_section->معلومات_دننه_واټن - fde_پیل) & 3)
	dwarf_data1(eh_چوکاټ_section, DW_CFA_nop);
    write32le(eh_چوکاټ_section->معلومات + fde_پیل, //اوږدتیا
	      eh_چوکاټ_section->معلومات_دننه_واټن - fde_پیل - 4);
}

ST_FUNC فراغ tcc_eh_چوکاټ_پای_ټکی(TCCState *s1)
{
    إذا (!eh_چوکاټ_section)
	أرجع;
    dwarf_data4(eh_چوکاټ_section, 0);
}

بنية eh_پلټنه_جدول {
    uint32_t pc_دننه_واټن;
    uint32_t fde_دننه_واټن;
};

ساكن صحيح ترتیبول_eh_جدول(ثابت فراغ *a, ثابت فراغ *b)
{
    uint32_t pc1 = ((ثابت بنية eh_پلټنه_جدول *)a)->pc_دننه_واټن;
    uint32_t pc2 = ((ثابت بنية eh_پلټنه_جدول *)b)->pc_دننه_واټن;

    أرجع pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC فراغ tcc_eh_چوکاټ_hdr(TCCState *s1, صحيح final)
{
    صحيح شمېر_2 = 0, دننه_واټن;
    بینښه اوږد شمېر_دننه_واټن, tab_دننه_واټن;
    بینښه حرف *ln, *پای_ټکی;
    بینښه صحيح وروستی_cie_دننه_واټن = 0xffffffff;

    إذا (!eh_چوکاټ_section || !eh_چوکاټ_section->معلومات_دننه_واټن)
	أرجع;
    إذا (final && !eh_چوکاټ_hdr_section)
	أرجع;
    إذا (final == 0)
        eh_چوکاټ_hdr_section =
	    new_section(s1, ".eh_frame_hdr", SHT_PROGBITS, SHF_ALLOC);
    eh_چوکاټ_hdr_section->معلومات_دننه_واټن = 0;
    dwarf_data1(eh_چوکاټ_hdr_section, 1); //نسخه
    // Pointer Encoding Format
    dwarf_data1(eh_چوکاټ_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_pcrel);
    // Count Encoding Format
    dwarf_data1(eh_چوکاټ_hdr_section, DW_EH_PE_udata4 | DW_EH_PE_absptr);
    // Table Encoding Format
    dwarf_data1(eh_چوکاټ_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_datarel);
    دننه_واټن = eh_چوکاټ_section->sh_addr -
             eh_چوکاټ_hdr_section->sh_addr -
             eh_چوکاټ_hdr_section->معلومات_دننه_واټن;
    dwarf_data4(eh_چوکاټ_hdr_section, دننه_واټن); // eh_frame_ptr
    //شمېر
    شمېر_دننه_واټن = eh_چوکاټ_hdr_section->معلومات_دننه_واټن;
    dwarf_data4(eh_چوکاټ_hdr_section, 0);
    tab_دننه_واټن = eh_چوکاټ_hdr_section->معلومات_دننه_واټن;
    ln = eh_چوکاټ_section->معلومات;
    پای_ټکی = eh_چوکاټ_section->معلومات + eh_چوکاټ_section->معلومات_دننه_واټن;
    طالما (ln < پای_ټکی) {
	بینښه حرف *fde = ln, *rd = ln;
	بینښه صحيح cie_دننه_واټن, نسخه, اوږدتیا = dwarf_read_4(rd, پای_ټکی);
	بینښه صحيح pc_دننه_واټن, fde_دننه_واټن;

	إذا (اوږدتیا == 0)
	    اذهب بل;
        cie_دننه_واټن = dwarf_read_4(rd, پای_ټکی);
	إذا (cie_دننه_واټن == 0)
	    اذهب بل;
	إذا (cie_دننه_واټن != وروستی_cie_دننه_واټن) {
	    بینښه حرف *cie = rd - cie_دننه_واټن + 4;

	    إذا (cie < eh_چوکاټ_section->معلومات)
		اذهب بل;
	    نسخه = dwarf_read_1(cie, پای_ټکی);
	    إذا ((نسخه == 1 || نسخه == 3) &&
	        dwarf_read_1(cie, پای_ټکی) == 'z' && // Augmentation String
		dwarf_read_1(cie, پای_ټکی) == 'R' &&
		dwarf_read_1(cie, پای_ټکی) == 0) {
	        dwarf_read_uleb128(&cie, پای_ټکی); // code_alignment_factor
	        dwarf_read_sleb128(&cie, پای_ټکی); // data_alignment_factor
		dwarf_read_1(cie, پای_ټکی); // return address column
		إذا (dwarf_read_uleb128(&cie, پای_ټکی) == 1 &&
		    dwarf_read_1(cie, پای_ټکی) == FDE_ENCODING) {
		    وروستی_cie_دننه_واټن = cie_دننه_واټن;
		}
		وإلا
		    اذهب بل;
	    }
	    وإلا
		اذهب بل;
	}
	شمېر_2++;
	fde_دننه_واټن = eh_چوکاټ_section->sh_addr +
		     (fde - eh_چوکاټ_section->معلومات) -
		     eh_چوکاټ_hdr_section->sh_addr;
	pc_دننه_واټن = dwarf_read_4(rd, پای_ټکی) + fde_دننه_واټن + 8;
	dwarf_data4(eh_چوکاټ_hdr_section, pc_دننه_واټن);
	dwarf_data4(eh_چوکاټ_hdr_section, fde_دننه_واټن);
بل:
	ln += اوږدتیا + 4;
    }
    add32le(eh_چوکاټ_hdr_section->معلومات + شمېر_دننه_واټن, شمېر_2);
    qsort(eh_چوکاټ_hdr_section->معلومات + tab_دننه_واټن, شمېر_2,
	  حجم(بنية eh_پلټنه_جدول), ترتیبول_eh_جدول);
}
#د_که_پای

/* start of translation unit info */
ST_FUNC فراغ tcc_debug_پیل(TCCState *s1)
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
        put_elf_sym(symtab_section, متن_section->معلومات_دننه_واټن, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            متن_section->sh_عدد, "$a");

        new_file = وروستی_کرښه_عدد = 0;
        debug_بل_type = N_DEFAULT_DEBUG;
        debug_hash_global = عدم;
        debug_hash_local = عدم;
        debug_forw_hash_global = عدم;
        debug_forw_hash_local = عدم;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, حجم(buf));
#که_تعریف_شوی _WIN32
        normalize_slashes(buf);
#د_که_پای

        إذا (s1->dwarf) {
            صحيح پیل_abbrev;
            بینښه حرف *ptr;
	    حرف *undo;

            /* dwarf_abbrev */
            پیل_abbrev = dwarf_abbrev_section->معلومات_دننه_واټن;
            ptr = section_ptr_جمع_کړه(dwarf_abbrev_section, حجم(dwarf_abbrev_init));
            حافظه_نقل(ptr, dwarf_abbrev_init, حجم(dwarf_abbrev_init));

            إذا (s1->dwarf < 5) {
    	        طالما (*ptr) {
    	            ptr += 3;
    	            طالما (*ptr) {
    	                إذا (ptr[1] == DW_FORM_کرښه_strp)
    		            ptr[1] = DW_FORM_strp;
		        إذا (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    إذا  (ptr[1] == DW_FORM_sec_دننه_واټن)
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
            dwarf_sym.کرښه = dwarf_get_section_sym(dwarf_کرښه_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            إذا (tcc_state->dwarf >= 5)
    	        dwarf_sym.کرښه_str = dwarf_get_section_sym(dwarf_کرښه_str_section);
            وإلا {
    	        dwarf_کرښه_str_section = dwarf_str_section;
                dwarf_sym.کرښه_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(متن_section);

            /* dwarf_info */
            dwarf_info.پیل = dwarf_info_section->معلومات_دننه_واټن;
            dwarf_data4(dwarf_info_section, 0); //اندازه
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            إذا (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_اندازه);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_معلومات_32_DW);
                dwarf_data4(dwarf_info_section, پیل_abbrev);
            }
            وإلا {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_معلومات_32_DW);
                dwarf_data4(dwarf_info_section, پیل_abbrev);
                dwarf_data1(dwarf_info_section, PTR_اندازه);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_نسخه);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_کرښه_strp(dwarf_info_section, filename);
            dwarf_کرښه_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_معلومات_PTR);
#إذا PTR_اندازه == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#وإلا
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#د_که_پای
            dwarf_reloc(dwarf_info_section, dwarf_sym.کرښه, R_معلومات_32_DW);
            dwarf_data4(dwarf_info_section, dwarf_کرښه_section->معلومات_دننه_واټن); // stmt_list

            /* dwarf_line */
            dwarf_کرښه.پیل = dwarf_کرښه_section->معلومات_دننه_واټن;
            dwarf_data4(dwarf_کرښه_section, 0); //اوږدتیا
            dwarf_data2(dwarf_کرښه_section, s1->dwarf); // version
            إذا (s1->dwarf >= 5) {
                dwarf_data1(dwarf_کرښه_section, PTR_اندازه); // address size
                dwarf_data1(dwarf_کرښه_section, 0); // segment selector
            }
            dwarf_data4(dwarf_کرښه_section, 0); // prologue Length
            dwarf_data1(dwarf_کرښه_section, DWARF_MIN_INSTR_LEN);
            إذا (s1->dwarf >= 4)
                dwarf_data1(dwarf_کرښه_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_کرښه_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_کرښه_section, DWARF_کرښه_بنسټ);
            dwarf_data1(dwarf_کرښه_section, DWARF_کرښه_RANGE);
            dwarf_data1(dwarf_کرښه_section, DWARF_OPCODE_بنسټ);
            ptr = section_ptr_جمع_کړه(dwarf_کرښه_section, حجم(dwarf_کرښه_opcodes));
            حافظه_نقل(ptr, dwarf_کرښه_opcodes, حجم(dwarf_کرښه_opcodes));
	    undo = strrchr(filename, '/');
	    إذا (undo)
		*undo = 0;
            dwarf_کرښه.dir_اندازه = 1 + (undo != عدم);
            dwarf_کرښه.dir_جدول = (حرف **) tcc_malloc(حجم (حرف *) *
							dwarf_کرښه.dir_اندازه);
            dwarf_کرښه.dir_جدول[0] = tcc_strdup(buf);
	    إذا (undo)
                dwarf_کرښه.dir_جدول[1] = tcc_strdup(filename);
            dwarf_کرښه.filename_اندازه = 2;
            dwarf_کرښه.filename_جدول =
    	        (بنية dwarf_filename_struct *)
    	        tcc_malloc(2*حجم (بنية dwarf_filename_struct));
            dwarf_کرښه.filename_جدول[0].dir_ثبت = 0;
	    إذا (undo) {
                dwarf_کرښه.filename_جدول[0].name = tcc_strdup(undo + 1);
                dwarf_کرښه.filename_جدول[1].dir_ثبت = 1;
                dwarf_کرښه.filename_جدول[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    وإلا {
                dwarf_کرښه.filename_جدول[0].name = tcc_strdup(filename);
                dwarf_کرښه.filename_جدول[1].dir_ثبت = 0;
                dwarf_کرښه.filename_جدول[1].name = tcc_strdup(filename);
	    }
            dwarf_کرښه.کرښه_اندازه = dwarf_کرښه.کرښه_max_اندازه = 0;
            dwarf_کرښه.کرښه_معلومات = عدم;
            dwarf_کرښه.cur_file = 1;
            dwarf_کرښه.وروستی_file = 0;
            dwarf_کرښه.وروستی_pc = 0;
            dwarf_کرښه.وروستی_کرښه = 1;
            dwarf_کرښه_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_اندازه); // extended size
            dwarf_کرښه_op(s1, DW_LNE_سېټ_پته);
            لكل (i = 0; i < PTR_اندازه; i++)
    	        dwarf_کرښه_op(s1, 0);
            memset(&dwarf_info.بنسټ_type_کارول_شوی, 0, حجم(dwarf_info.بنسټ_type_کارول_شوی));
        }
        وإلا
        {
            /* file info: full path + filename */
            pstrcat(buf, حجم(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      متن_section->sh_عدد, عدم);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        متن_section->معلومات_دننه_واټن, متن_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        متن_section->معلومات_دننه_واټن, متن_section, section_sym);
            لكل (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

ساكن فراغ fix_debug_forw_hash(TCCState *s1, صحيح global, صحيح پیل);

/* put end of translation unit info */
ST_FUNC فراغ tcc_debug_پای_ټکی(TCCState *s1)
{

    إذا (!s1->do_debug || debug_بل_type == 0)
        أرجع;

    إذا (debug_info_ریښه)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    إذا (s1->dwarf) {
	صحيح i;
	صحيح پیل_aranges;
	بینښه حرف *ptr;
	صحيح متن_اندازه = متن_section->معلومات_دننه_واټن;

	/* dwarf_info */
	fix_debug_forw_hash(s1, 0, 0);
	fix_debug_forw_hash(s1, 1, 0);
	dwarf_data1(dwarf_info_section, 0);
	ptr = dwarf_info_section->معلومات + dwarf_info.پیل;
	write32le(ptr, dwarf_info_section->معلومات_دننه_واټن - dwarf_info.پیل - 4);
	write32le(ptr + 25 + (s1->dwarf >= 5) + PTR_اندازه, متن_اندازه);

	/* dwarf_aranges */
	پیل_aranges = dwarf_aranges_section->معلومات_دننه_واټن;
	dwarf_data4(dwarf_aranges_section, 0); //اندازه
	dwarf_data2(dwarf_aranges_section, 2); // version
	dwarf_reloc(dwarf_aranges_section, dwarf_sym.info, R_معلومات_32_DW);
	dwarf_data4(dwarf_aranges_section, 0); // dwarf_info
#إذا PTR_اندازه == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#وإلا
	dwarf_data1(dwarf_aranges_section, 8); // address size
#د_که_پای
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_معلومات_PTR);
#إذا PTR_اندازه == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, متن_اندازه); //پای_ټکی
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#وإلا
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, متن_اندازه); //پای_ټکی
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#د_که_پای
	ptr = dwarf_aranges_section->معلومات + پیل_aranges;
	write32le(ptr, dwarf_aranges_section->معلومات_دننه_واټن - پیل_aranges - 4);

	/* dwarf_line */
	إذا (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_کرښه_section, 1); /*ستون*/
	    dwarf_uleb128(dwarf_کرښه_section, DW_LNCT_لار);
	    dwarf_uleb128(dwarf_کرښه_section, DW_FORM_کرښه_strp);
	    dwarf_uleb128(dwarf_کرښه_section, dwarf_کرښه.dir_اندازه);
	    لكل (i = 0; i < dwarf_کرښه.dir_اندازه; i++)
	        dwarf_کرښه_strp(dwarf_کرښه_section, dwarf_کرښه.dir_جدول[i]);
	    dwarf_data1(dwarf_کرښه_section, 2); /*ستون*/
	    dwarf_uleb128(dwarf_کرښه_section, DW_LNCT_لار);
	    dwarf_uleb128(dwarf_کرښه_section, DW_FORM_کرښه_strp);
	    dwarf_uleb128(dwarf_کرښه_section, DW_LNCT_directory_شاخص);
	    dwarf_uleb128(dwarf_کرښه_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_کرښه_section, dwarf_کرښه.filename_اندازه);
	    لكل (i = 0; i < dwarf_کرښه.filename_اندازه; i++) {
	        dwarf_کرښه_strp(dwarf_کرښه_section,
				dwarf_کرښه.filename_جدول[i].name);
	        dwarf_uleb128(dwarf_کرښه_section,
			      dwarf_کرښه.filename_جدول[i].dir_ثبت);
	    }
	}
	وإلا {
	    صحيح len;

	    لكل (i = 0; i < dwarf_کرښه.dir_اندازه; i++) {
	        len = مزي_اوږدوالی(dwarf_کرښه.dir_جدول[i]) + 1;
	        ptr = section_ptr_جمع_کړه(dwarf_کرښه_section, len);
	        memmove(ptr, dwarf_کرښه.dir_جدول[i], len);
	    }
	    dwarf_data1(dwarf_کرښه_section, 0); /* end dir */
	    لكل (i = 0; i < dwarf_کرښه.filename_اندازه; i++) {
	        len = مزي_اوږدوالی(dwarf_کرښه.filename_جدول[i].name) + 1;
	        ptr = section_ptr_جمع_کړه(dwarf_کرښه_section, len);
	        memmove(ptr, dwarf_کرښه.filename_جدول[i].name, len);
	        dwarf_uleb128(dwarf_کرښه_section,
			      dwarf_کرښه.filename_جدول[i].dir_ثبت);
	        dwarf_uleb128(dwarf_کرښه_section, 0); /*وخت*/
	        dwarf_uleb128(dwarf_کرښه_section, 0); /*اندازه*/
	    }
	    dwarf_data1(dwarf_کرښه_section, 0); /* end file */
	}
	لكل (i = 0; i < dwarf_کرښه.dir_اندازه; i++)
	    tcc_free(dwarf_کرښه.dir_جدول[i]);
	tcc_free(dwarf_کرښه.dir_جدول);
	لكل (i = 0; i < dwarf_کرښه.filename_اندازه; i++)
	    tcc_free(dwarf_کرښه.filename_جدول[i].name);
	tcc_free(dwarf_کرښه.filename_جدول);

	dwarf_کرښه_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_کرښه_op(s1, DW_LNE_پای_ټکی_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_کرښه_section->معلومات[dwarf_کرښه.پیل + 6 + i],
		  dwarf_کرښه_section->معلومات_دننه_واټن - dwarf_کرښه.پیل - (10 + i));
	section_ptr_جمع_کړه(dwarf_کرښه_section, 3);
	dwarf_reloc(dwarf_کرښه_section, section_sym, R_معلومات_PTR);
	ptr = section_ptr_جمع_کړه(dwarf_کرښه_section, dwarf_کرښه.کرښه_اندازه - 3);
	memmove(ptr - 3, dwarf_کرښه.کرښه_معلومات, dwarf_کرښه.کرښه_اندازه);
	tcc_free(dwarf_کرښه.کرښه_معلومات);
	write32le(dwarf_کرښه_section->معلومات + dwarf_کرښه.پیل,
		  dwarf_کرښه_section->معلومات_دننه_واټن - dwarf_کرښه.پیل - 4);
    }
    وإلا
    {
        put_stabs_r(s1, عدم, N_SO, 0, 0,
                    متن_section->معلومات_دننه_واټن, متن_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_کرښه_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_بل_type = 0;
}

ساكن BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    إذا (f->filename[0] == ':')
        f = f->prev;
    إذا (f && new_file) {
        new_file = وروستی_کرښه_عدد = 0;
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
ST_FUNC فراغ tcc_debug_کرښه(TCCState *s1)
{
    BufferedFile *f;

    إذا (!s1->do_debug)
        أرجع;
    إذا (cur_متن_section != متن_section || nocode_wanted)
        أرجع;
    f = put_new_file(s1);
    إذا (!f)
        أرجع;
    إذا (وروستی_کرښه_عدد == f->کرښه_عدد)
        أرجع;
    وروستی_کرښه_عدد = f->کرښه_عدد;

    إذا (s1->dwarf) {
	صحيح len_pc = (ind - dwarf_کرښه.وروستی_pc) / DWARF_MIN_INSTR_LEN;
	صحيح len_کرښه = f->کرښه_عدد - dwarf_کرښه.وروستی_کرښه;
	صحيح n = len_pc * DWARF_کرښه_RANGE + len_کرښه + DWARF_OPCODE_بنسټ - DWARF_کرښه_بنسټ;

	إذا (dwarf_کرښه.cur_file != dwarf_کرښه.وروستی_file) {
	    dwarf_کرښه.وروستی_file = dwarf_کرښه.cur_file;
	    dwarf_کرښه_op(s1, DW_LNS_سېټ_file);
	    dwarf_uleb128_op(s1, dwarf_کرښه.cur_file);
	}
	إذا (len_pc &&
	    len_کرښه >= DWARF_کرښه_بنسټ && len_کرښه <= (DWARF_OPCODE_بنسټ + DWARF_کرښه_بنسټ) &&
	    n >= DWARF_OPCODE_بنسټ && n <= 255)
            dwarf_کرښه_op(s1, n);
	وإلا {
	    إذا (len_pc) {
	        n = len_pc * DWARF_کرښه_RANGE + 0 + DWARF_OPCODE_بنسټ - DWARF_کرښه_بنسټ;
	        إذا (n >= DWARF_OPCODE_بنسټ && n <= 255)
                    dwarf_کرښه_op(s1, n);
		وإلا {
	            dwarf_کرښه_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    إذا (len_کرښه) {
	        n = 0 * DWARF_کرښه_RANGE + len_کرښه + DWARF_OPCODE_بنسټ - DWARF_کرښه_بنسټ;
	        إذا (len_کرښه >= DWARF_کرښه_بنسټ && len_کرښه <= (DWARF_OPCODE_بنسټ + DWARF_کرښه_بنسټ) &&
		    n >= DWARF_OPCODE_بنسټ && n <= 255)
	            dwarf_کرښه_op(s1, n);
		وإلا {
	            dwarf_کرښه_op(s1, DW_LNS_advance_کرښه);
		    dwarf_sleb128_op(s1, len_کرښه);
                    /* advance by nothing */
	            dwarf_کرښه_op(s1, DWARF_OPCODE_بنسټ - DWARF_کرښه_بنسټ);
		}
	    }
	}
	dwarf_کرښه.وروستی_pc = ind;
	dwarf_کرښه.وروستی_کرښه = f->کرښه_عدد;
    }
    وإلا
    {
	إذا (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->کرښه_عدد, ind - func_ind);
        } وإلا {
            /* from tcc_assemble */
            put_stabs_r(s1, عدم, N_SLINE, 0, f->کرښه_عدد, ind, متن_section, section_sym);
        }
    }
}

ساكن فراغ tcc_debug_stabs (TCCState *s1, ثابت حرف *str, صحيح type, بینښه اوږد ارزښت,
                             Section *sec, صحيح sym_شاخص, صحيح info)
{
    بنية debug_sym *s;

    إذا (debug_info) {
        debug_info->sym =
            (بنية debug_sym *)tcc_realloc (debug_info->sym,
                                             حجم(بنية debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->ارزښت = ارزښت;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_شاخص = sym_شاخص;
        s->info = info;
        s->file = dwarf_کرښه.cur_file;
        s->کرښه = file->کرښه_عدد;
    }
    وإلا إذا (sec)
        put_stabs_r (s1, str, type, 0, 0, ارزښت, sec, sym_شاخص);
    وإلا
        put_stabs (s1, str, type, 0, 0, ارزښت);
}

ساكن فراغ fix_debug_forw_hash(TCCState *s1, صحيح global, صحيح پیل)
{
    إذا (s1->dwarf) {
        صحيح i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	بنية _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	لكل (i = پیل; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    صحيح pos = dwarf_info_section->معلومات_دننه_واټن;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_تشه_TYPE
                                             : DWARF_ABBREV_STRUCTURE_تشه_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_لومړی_ANOM
                       ? "" : get_tok_str(t->v, عدم));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_کرښه.cur_file);
            dwarf_uleb128(dwarf_info_section, file->کرښه_عدد);
	    لكل (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->معلومات +
			  hash[i].debug_type[j],
			  pos - dwarf_info.پیل);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC فراغ tcc_debug_stabn(TCCState *s1, صحيح type, صحيح ارزښت)
{
    إذا (!s1->do_debug)
        أرجع;
    إذا (type == N_LBRAC) {
        بنية _debug_info *info =
            (بنية _debug_info *) tcc_mallocz(حجم (*info));

        info->پیل = ارزښت;
        info->وروستی_debug_hash = n_debug_hash_local;
        info->وروستی_debug_forw_hash = n_debug_forw_hash_local;
        info->پلار = debug_info;
        إذا (debug_info) {
            إذا (debug_info->ماشوم) {
                إذا (debug_info->ماشوم->وروستی)
                    debug_info->ماشوم->وروستی->بل = info;
                وإلا
                    debug_info->ماشوم->بل = info;
                debug_info->ماشوم->وروستی = info;
            }
            وإلا
                debug_info->ماشوم = info;
        }
        وإلا
            debug_info_ریښه = info;
        debug_info = info;
    }
    وإلا {
	fix_debug_forw_hash(s1, 0, debug_info->وروستی_debug_forw_hash);
        n_debug_hash_local = debug_info->وروستی_debug_hash;
        n_debug_forw_hash_local = debug_info->وروستی_debug_forw_hash;
        debug_info->پای_ټکی = ارزښت;
        debug_info = debug_info->پلار;
    }
}

ساكن صحيح check_global(Sym *t)
{
    Sym *g = local_ډېری;

    طالما (g) {
	إذا (t == g)
	    أرجع 0;
	g = g->prev;
    }
    أرجع 1;
}

ساكن صحيح tcc_debug_پیدا_کړه(TCCState *s1, Sym *t, صحيح dwarf)
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
		        write32le(dwarf_info_section->معلومات +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.پیل);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		لكل (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

ساكن صحيح tcc_debug_جمع_کړه(TCCState *s1, Sym *t, صحيح dwarf)
{
    صحيح دننه_واټن = dwarf ? dwarf_info_section->معلومات_دننه_واټن : ++debug_بل_type;
    صحيح *n_hash, g = check_global(t);
    بنية _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (بنية _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * حجم(**hash));
    (*hash)[*n_hash].debug_type = دننه_واټن;
    (*hash)[(*n_hash)++].type = t;
    أرجع دننه_واټن;
}

ساكن صحيح STRUCT_NODEBUG(Sym *s)
{
    أرجع
    (s->a.nodebug ||
     ((s->v & ~SYM_ډګر) >= SYM_لومړی_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

ساكن صحيح stabs_struct_پیدا_کړه(TCCState *s1, Sym *t, صحيح *p_id)
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
        s = sym_push2(&global_ډېری, SYM_ډګر|0x00DEBBED, 0, ++debug_بل_type);
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
        إذا (!(type & VT_BITFIELD) && (type & VT_STRUCT_ماسک) > VT_ENUM)
	    type &= ~VT_STRUCT_ماسک;
	أرجع type;
}

ساكن فراغ tcc_get_debug_info(TCCState *s1, Sym *s, CString *پایله)
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
        إذا (stabs_struct_پیدا_کړه(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_لومړی_ANOM
                         ? "" : get_tok_str(t->v, عدم),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            طالما (t->بل) {
                صحيح pos, اندازه, align;
                t = t->بل;
		إذا (STRUCT_NODEBUG(t))
		    استمر;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_ډګر) >= SYM_لومړی_ANOM
                             ? "" : get_tok_str(t->v, عدم)
                             );
                tcc_get_debug_info (s1, t, &str);
                إذا (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + بټ_POS(t->type.t);
                    اندازه = بټ_اندازه(t->type.t);
                }
                وإلا {
                    pos = t->c * 8;
                    اندازه = type_اندازه(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, اندازه);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.معلومات, N_LSYM, 0, عدم, 0, 0);
            cstr_free (&str);
        }
    }
    وإلا إذا (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        إذا (stabs_struct_پیدا_کړه(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_لومړی_ANOM
                         ? "" : get_tok_str(t->v, عدم),
                         debug_type);
            طالما (t->بل) {
                t = t->بل;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_ډګر) >= SYM_لومړی_ANOM
                             ? "" : get_tok_str(t->v, عدم));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (صحيح)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.معلومات, N_LSYM, 0, عدم, 0, 0);
            cstr_free (&str);
	}
    }
    وإلا إذا ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_ماسک;
        لكل (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            إذا (default_debug[debug_type - 1].type == type)
                اكسر;
        إذا (debug_type > N_DEFAULT_DEBUG)
            أرجع;
    }

    إذا (عدم == پایله) /* from stabs_struct_complete() */
        أرجع;

    إذا (n > 0)
        cstr_printf (پایله, "%d=", ++debug_بل_type);
    t = s;
    لكل (;;) {
        type = remove_type_info (t->type.t);
        إذا (type == VT_PTR)
            cstr_printf (پایله, "%d=*", ++debug_بل_type);
        وإلا إذا (type == (VT_PTR | VT_ARRAY))
            cstr_printf (پایله, "%d=ar1;0;%d;",
                         ++debug_بل_type, t->type.ref->c - 1);
        وإلا إذا (type == VT_FUNC) {
            cstr_printf (پایله, "%d=f", ++debug_بل_type);
            tcc_get_debug_info (s1, t->type.ref, پایله);
            أرجع;
        }
        وإلا
            اكسر;
        t = t->type.ref;
    }
    cstr_printf (پایله, "%d", debug_type);
}

ساكن فراغ stabs_struct_complete(TCCState *s1, CType *t)
{
    إذا (stabs_struct_پیدا_کړه(s1, t->ref, عدم)) {
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
    صحيح وروستی_pos = -1;
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
	debug_type = tcc_debug_پیدا_کړه(s1, t, 1);
	إذا (debug_type == -1) {
	    صحيح pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_جمع_کړه(s1, t, 1);
	    e = t;
	    i = 0;
	    طالما (e->بل) {
		e = e->بل;
		إذا (STRUCT_NODEBUG(e))
		    استمر;
		i++;
	    }
	    pos_type = (صحيح *) tcc_malloc(i * حجم(صحيح));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->بل ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_تشه_TYPE
		        : t->بل ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_تشه_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_لومړی_ANOM
                       ? "" : get_tok_str(t->v, عدم));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_کرښه.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->کرښه_عدد);
	    إذا (t->بل) {
	        pos_sib = dwarf_info_section->معلومات_دننه_واټن;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            طالما (e->بل) {
                e = e->بل;
		إذا (STRUCT_NODEBUG(e))
		    استمر;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, عدم));
		dwarf_uleb128(dwarf_info_section, dwarf_کرښه.cur_file);
		dwarf_uleb128(dwarf_info_section, file->کرښه_عدد);
		pos_type[i++] = dwarf_info_section->معلومات_دننه_واټن;
		dwarf_data4(dwarf_info_section, 0);
                إذا (e->type.t & VT_BITFIELD) {
                    صحيح pos = e->c * 8 + بټ_POS(e->type.t);
                    صحيح اندازه = بټ_اندازه(e->type.t);

		    dwarf_uleb128(dwarf_info_section, اندازه);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		وإلا
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    إذا (t->بل) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->معلومات + pos_sib,
		          dwarf_info_section->معلومات_دننه_واټن - dwarf_info.پیل);
	    }
	    e = t;
	    i = 0;
	    طالما (e->بل) {
		e = e->بل;
		إذا (STRUCT_NODEBUG(e))
		    استمر;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->معلومات + pos_type[i++],
			  type - dwarf_info.پیل);
	    }
	    tcc_free(pos_type);
        }
    }
    وإلا إذا (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_پیدا_کړه(s1, t, 1);
	إذا (debug_type == -1) {
	    صحيح pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_جمع_کړه(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_لومړی_ANOM
                       ? "" : get_tok_str(t->v, عدم));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.پیل);
	    dwarf_uleb128(dwarf_info_section, dwarf_کرښه.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->کرښه_عدد);
	    pos_sib = dwarf_info_section->معلومات_دننه_واټن;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            طالما (e->بل) {
                e = e->بل;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_ډګر) >= SYM_لومړی_ANOM
                           ? "" : get_tok_str(e->v, عدم));
		إذا (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		وإلا
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->معلومات + pos_sib,
		      dwarf_info_section->معلومات_دننه_واټن - dwarf_info.پیل);
	}
    }
    وإلا إذا ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_ماسک;
        لكل (i = 1; i <= N_DEFAULT_DEBUG; i++)
            إذا (default_debug[i - 1].type == type)
                اكسر;
        إذا (i > N_DEFAULT_DEBUG)
            أرجع 0;
	debug_type = dwarf_info.بنسټ_type_کارول_شوی[i - 1];
	إذا (debug_type == 0) {
	    حرف name[100];

	    debug_type = dwarf_info_section->معلومات_دننه_واټن;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_بنسټ_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].اندازه);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, حجم name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.بنسټ_type_کارول_شوی[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = عدم;
    t = s;
    لكل (;;) {
        type = remove_type_info (t->type.t);
        إذا (type == VT_PTR) {
	    i = dwarf_info_section->معلومات_دننه_واټن;
	    إذا (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_اشاره_ګر);
	    dwarf_data1(dwarf_info_section, PTR_اندازه);
	    إذا (وروستی_pos != -1) {
		tcc_debug_check_forw(s1, e, وروستی_pos);
		write32le(dwarf_info_section->معلومات + وروستی_pos,
			  i - dwarf_info.پیل);
	    }
	    وروستی_pos = dwarf_info_section->معلومات_دننه_واټن;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        وإلا إذا (type == (VT_PTR | VT_ARRAY)) {
	    صحيح sib_pos, sub_type;
#إذا LONG_اندازه == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#وإلا
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#د_که_پای

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->معلومات_دننه_واټن;
	    إذا (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    إذا (وروستی_pos != -1) {
		tcc_debug_check_forw(s1, e, وروستی_pos);
		write32le(dwarf_info_section->معلومات + وروستی_pos,
			  i - dwarf_info.پیل);
	    }
	    وروستی_pos = dwarf_info_section->معلومات_دننه_واټن;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->معلومات_دننه_واټن;
	    dwarf_data4(dwarf_info_section, 0);
	    لكل (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.پیل);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		إذا (type != (VT_PTR | VT_ARRAY))
		    اكسر;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->معلومات + sib_pos,
		      dwarf_info_section->معلومات_دننه_واټن - dwarf_info.پیل);
	}
        وإلا إذا (type == VT_FUNC) {
	    صحيح sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->معلومات_دننه_واټن;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    إذا (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->بل ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_تشه_TYPE);
	    إذا (وروستی_pos != -1) {
		tcc_debug_check_forw(s1, e, وروستی_pos);
		write32le(dwarf_info_section->معلومات + وروستی_pos,
			  i - dwarf_info.پیل);
	    }
	    وروستی_pos = dwarf_info_section->معلومات_دننه_واټن;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    إذا (t->type.ref->بل) {
	        sib_pos = dwarf_info_section->معلومات_دننه_واټن;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    طالما (f->بل) {
		f = f->بل;
		i++;
	    }
	    pos_type = (صحيح *) tcc_malloc(i * حجم(صحيح));
	    f = t->type.ref;
	    i = 0;
	    طالما (f->بل) {
		f = f->بل;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->معلومات_دننه_واټن;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    إذا (t->type.ref->بل) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->معلومات + sib_pos,
		          dwarf_info_section->معلومات_دننه_واټن - dwarf_info.پیل);
	    }
	    f = t->type.ref;
	    i = 0;
	    طالما (f->بل) {
		f = f->بل;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->معلومات + pos_type[i++],
                          type - dwarf_info.پیل);
	    }
	    tcc_free(pos_type);
        }
        وإلا {
	    إذا (وروستی_pos != -1) {
		tcc_debug_check_forw(s1, e, وروستی_pos);
		write32le(dwarf_info_section->معلومات + وروستی_pos,
			  debug_type - dwarf_info.پیل);
	    }
            اكسر;
	}
        t = t->type.ref;
    }
    أرجع retval;
}

ساكن فراغ tcc_debug_پای (TCCState *s1, بنية _debug_info *cur)
{
    طالما (cur) {
        بنية _debug_info *بل = cur->بل;
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
                    dwarf_uleb128(dwarf_info_section, s->کرښه);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.پیل);
		إذا (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    إذا (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_اندازه + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    إذا (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_معلومات_PTR);
#إذا PTR_اندازه == 4
                    dwarf_data4(dwarf_info_section, s->ارزښت);
#وإلا
                    dwarf_data8(dwarf_info_section, s->ارزښت);
#د_که_پای
		}
		وإلا {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_اندازه((اوږد)s->ارزښت) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (اوږد)s->ارزښت);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->ماشوم ? DWARF_ABBREV_LEXICAL_بلاک
			           : DWARF_ABBREV_LEXICAL_تشه_بلاک);
            dwarf_reloc(dwarf_info_section, section_sym, R_معلومات_PTR);
#إذا PTR_اندازه == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->پیل);
            dwarf_data4(dwarf_info_section, cur->پای_ټکی - cur->پیل);
#وإلا
            dwarf_data8(dwarf_info_section, func_ind + cur->پیل);
            dwarf_data8(dwarf_info_section, cur->پای_ټکی - cur->پیل);
#د_که_پای
            tcc_debug_پای (s1, cur->ماشوم);
	    إذا (cur->ماشوم)
                dwarf_data1(dwarf_info_section, 0);
        }
        وإلا
        {
            لكل (i = 0; i < cur->n_sym; i++) {
                بنية debug_sym *s = &cur->sym[i];

                إذا (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->ارزښت,
                                s->sec, s->sym_شاخص);
                وإلا
                    put_stabs(s1, s->str, s->type, 0, 0, s->ارزښت);
                tcc_free (s->str);
            }
            tcc_free (cur->sym);
            put_stabn(s1, N_LBRAC, 0, 0, cur->پیل);
            tcc_debug_پای (s1, cur->ماشوم);
            put_stabn(s1, N_RBRAC, 0, 0, cur->پای_ټکی);
        }
        tcc_free (cur);
        cur = بل;
    }
}

ST_FUNC فراغ tcc_جمع_کړه_debug_info(TCCState *s1, Sym *s, Sym *e)
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
            tcc_debug_stabs(s1, debug_str.معلومات, param ? N_PSYM : N_LSYM,
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
    debug_info_ریښه = عدم;
    debug_info = عدم;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    إذا (!f)
	أرجع;

    إذا (s1->dwarf) {
        tcc_debug_کرښه(s1);
        dwarf_info.func = sym;
        dwarf_info.کرښه = file->کرښه_عدد;
	إذا (s1->do_backtrace) {
	    صحيح i, len;

	    dwarf_کرښه_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, مزي_اوږدوالی(funcname) + 2);
	    dwarf_کرښه_op(s1, DW_LNE_hi_user - 1);
	    len = مزي_اوږدوالی(funcname) + 1;
	    لكل (i = 0; i < len; i++)
		dwarf_کرښه_op(s1, funcname[i]);
	}
    }
    وإلا
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.معلومات, N_FUN, 0, f->کرښه_عدد, 0, cur_متن_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_کرښه(s1);
    }
}

ST_FUNC فراغ tcc_debug_prolog_epilog(TCCState *s1, صحيح ارزښت)
{
    إذا (!s1->do_debug)
        أرجع;
    إذا (s1->dwarf) {
	dwarf_کرښه_op(s1, ارزښت == 0 ? DW_LNS_سېټ_prologue_پای_ټکی
				     : DW_LNS_سېټ_epilogue_begin);
    }
}

/* put function size */
ST_FUNC فراغ tcc_debug_funcend(TCCState *s1, صحيح اندازه)
{
    /* lldb does not like function end and next function start at same pc */
    صحيح min_instr_len;

#إذا TCC_EH_چوکاټ
    tcc_debug_چوکاټ_پای_ټکی(s1, اندازه);
#د_که_پای
    إذا (!s1->do_debug)
        أرجع;
    min_instr_len = dwarf_کرښه.وروستی_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_کرښه(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, اندازه);
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
        dwarf_uleb128(dwarf_info_section, dwarf_کرښه.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.کرښه);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->معلومات_دننه_واټن);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.پیل);
        dwarf_reloc(dwarf_info_section, section_sym, R_معلومات_PTR);
#إذا PTR_اندازه == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, اندازه); // high_pc
#وإلا
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, اندازه); // high_pc
#د_که_پای
        func_sib = dwarf_info_section->معلومات_دننه_واټن;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#إذا defined(TCC_موخه_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#وإلاإذا defined(TCC_موخه_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#وإلاإذا defined TCC_موخه_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#وإلاإذا defined TCC_موخه_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#وإلاإذا defined TCC_موخه_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#وإلا
        dwarf_data1(dwarf_info_section, DW_OP_call_چوکاټ_cfa);
#د_که_پای
        tcc_debug_پای (s1, debug_info_ریښه);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->معلومات + func_sib,
                  dwarf_info_section->معلومات_دننه_واټن - dwarf_info.پیل);
    }
    وإلا
    {
        tcc_debug_پای (s1, debug_info_ریښه);
    }
    debug_info_ریښه = 0;
}


ST_FUNC فراغ tcc_debug_extern_sym(TCCState *s1, Sym *sym, صحيح sh_عدد, صحيح sym_bind, صحيح sym_type)
{
    إذا (!(s1->do_debug & 2))
        أرجع;

    إذا (sym_type == STT_FUNC || sym->v >= SYM_لومړی_ANOM)
        أرجع;
    إذا (s1->dwarf) {
        صحيح debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, عدم));
	dwarf_uleb128(dwarf_info_section, dwarf_کرښه.cur_file);
	dwarf_uleb128(dwarf_info_section, file->کرښه_عدد);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->معلومات_دننه_واټن);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.پیل);
	إذا (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_اندازه + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->معلومات_دننه_واټن,
		R_معلومات_PTR, 0);
#إذا PTR_اندازه == 4
	dwarf_data4(dwarf_info_section, 0);
#وإلا
	dwarf_data8(dwarf_info_section, 0);
#د_که_پای
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
            tcc_debug_stabs(s1, str.معلومات, N_GSYM, 0, عدم, 0, 0);
        وإلا
            tcc_debug_stabs(s1, str.معلومات,
                (sym->type.t & VT_STATIC) && معلومات_section == s
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
	    dwarf_uleb128(dwarf_info_section, dwarf_کرښه.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->کرښه_عدد);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->معلومات_دننه_واټن);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.پیل);
	}
    }
    وإلا
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, عدم));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.معلومات, N_LSYM, 0, عدم, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC فراغ tcc_tcov_بلاک_پای_ټکی(TCCState *s1, صحيح کرښه);

ST_FUNC فراغ tcc_tcov_بلاک_begin(TCCState *s1)
{
    SValue sv;
    فراغ *ptr;
    بینښه اوږد وروستی_دننه_واټن = tcov_معلومات.دننه_واټن;

    tcc_tcov_بلاک_پای_ټکی (tcc_state, 0);
    إذا (s1->test_coverage == 0 || nocode_wanted)
	أرجع;

    إذا (tcov_معلومات.وروستی_file_name == 0 ||
	strcmp ((ثابت حرف *)(tcov_section->معلومات + tcov_معلومات.وروستی_file_name),
		file->true_filename) != 0) {
	حرف wd[1024];
	CString cstr;

	إذا (tcov_معلومات.وروستی_func_name)
	    section_ptr_جمع_کړه(tcov_section, 1);
	إذا (tcov_معلومات.وروستی_file_name)
	    section_ptr_جمع_کړه(tcov_section, 1);
	tcov_معلومات.وروستی_func_name = 0;
	cstr_new (&cstr);
	إذا (file->true_filename[0] == '/') {
	    tcov_معلومات.وروستی_file_name = tcov_section->معلومات_دننه_واټن;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	وإلا {
	    getcwd (wd, حجم(wd));
	    tcov_معلومات.وروستی_file_name = tcov_section->معلومات_دننه_واټن + مزي_اوږدوالی(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_جمع_کړه(tcov_section, cstr.اندازه + 1);
	strcpy((حرف *)ptr, cstr.معلومات);
#که_تعریف_شوی _WIN32
        normalize_slashes((حرف *)ptr);
#د_که_پای
	cstr_free (&cstr);
    }
    إذا (tcov_معلومات.وروستی_func_name == 0 ||
	strcmp ((ثابت حرف *)(tcov_section->معلومات + tcov_معلومات.وروستی_func_name),
		funcname) != 0) {
	اندازه_t len;

	إذا (tcov_معلومات.وروستی_func_name)
	    section_ptr_جمع_کړه(tcov_section, 1);
	tcov_معلومات.وروستی_func_name = tcov_section->معلومات_دننه_واټن;
	len = مزي_اوږدوالی (funcname);
	ptr = section_ptr_جمع_کړه(tcov_section, len + 1);
	strcpy((حرف *)ptr, funcname);
	section_ptr_جمع_کړه(tcov_section, -tcov_section->معلومات_دننه_واټن & 7);
	ptr = section_ptr_جمع_کړه(tcov_section, 8);
	write64le (ptr, file->کرښه_عدد);
    }
    إذا (ind == tcov_معلومات.ind && tcov_معلومات.کرښه == file->کرښه_عدد)
        tcov_معلومات.دننه_واټن = وروستی_دننه_واټن;
    وإلا {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_جمع_کړه(tcov_section, 16);
        tcov_معلومات.کرښه = file->کرښه_عدد;
        write64le (ptr, (tcov_معلومات.کرښه << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((بینښه حرف *)ptr - tcov_section->معلومات) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#إذا defined TCC_موخه_I386 || defined TCC_موخه_X86_64 || \
    defined TCC_موخه_ARM || defined TCC_موخه_ARM64 || \
    defined TCC_موخه_RISCV64
        gen_increment_tcov (&sv);
#وإلا
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#د_که_پای
        tcov_معلومات.دننه_واټن = (بینښه حرف *)ptr - tcov_section->معلومات;
        tcov_معلومات.ind = ind;
    }
}

ST_FUNC فراغ tcc_tcov_بلاک_پای_ټکی(TCCState *s1, صحيح کرښه)
{
    إذا (s1->test_coverage == 0)
	أرجع;
    إذا (کرښه == -1)
        کرښه = tcov_معلومات.کرښه;
    إذا (tcov_معلومات.دننه_واټن) {
	فراغ *ptr = tcov_section->معلومات + tcov_معلومات.دننه_واټن;
	بینښه اوږد اوږد nline = کرښه ? کرښه : file->کرښه_عدد;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_معلومات.دننه_واټن = 0;
    }
}

ST_FUNC فراغ tcc_tcov_check_کرښه(TCCState *s1, صحيح پیل)
{
    إذا (s1->test_coverage == 0)
	أرجع;
    إذا (tcov_معلومات.کرښه != file->کرښه_عدد) {
        إذا ((tcov_معلومات.کرښه + 1) != file->کرښه_عدد) {
	    tcc_tcov_بلاک_پای_ټکی (s1, -1);
	    إذا (پیل)
                tcc_tcov_بلاک_begin (s1);
	}
	وإلا
	    tcov_معلومات.کرښه = file->کرښه_عدد;
    }
}

ST_FUNC فراغ tcc_tcov_پیل(TCCState *s1)
{
    إذا (s1->test_coverage == 0)
	أرجع;
    إذا (!s1->dState)
        s1->dState = tcc_mallocz(حجم *s1->dState);
    memset (&tcov_معلومات, 0, حجم (tcov_معلومات));
    إذا (tcov_section == عدم) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_جمع_کړه(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC فراغ tcc_tcov_پای_ټکی(TCCState *s1)
{
    إذا (s1->test_coverage == 0)
	أرجع;
    إذا (tcov_معلومات.وروستی_func_name)
        section_ptr_جمع_کړه(tcov_section, 1);
    إذا (tcov_معلومات.وروستی_file_name)
        section_ptr_جمع_کړه(tcov_section, 1);
}

ST_FUNC فراغ tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_معلومات.ind = 0;
}

/* ------------------------------------------------------------------------- */
#تعریف_لغوه وروستی_کرښه_عدد
#تعریف_لغوه new_file
#تعریف_لغوه section_sym
#تعریف_لغوه debug_بل_type
#تعریف_لغوه debug_hash_global
#تعریف_لغوه debug_hash_local
#تعریف_لغوه n_debug_hash_global
#تعریف_لغوه n_debug_hash_local
#تعریف_لغوه debug_forw_hash_global
#تعریف_لغوه debug_forw_hash_local
#تعریف_لغوه n_debug_forw_hash_global
#تعریف_لغوه n_debug_forw_hash_local
#تعریف_لغوه debug_info
#تعریف_لغوه debug_info_ریښه
#تعریف_لغوه dwarf_sym
#تعریف_لغوه dwarf_کرښه
#تعریف_لغوه dwarf_info
#تعریف_لغوه dwarf_str
#تعریف_لغوه dwarf_کرښه_str
#تعریف_لغوه tcov_معلومات
