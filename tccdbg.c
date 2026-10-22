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

#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

/* stab debug support */

ਸਥਿਰ ਅਚਲ ਬਣਤਰ {
  ਪੂਰਨ type;
  ਪੂਰਨ ਮਾਪ;
  ਪੂਰਨ encoding;
  ਅਚਲ ਅੱਖਰ *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#ਜੇ LONG_ਮਾਪ == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#ਨਹੀਂਤਾਂ
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#ਜੇ_ਅੰਤ
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#ਜੇ LONG_ਮਾਪ == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#ਨਹੀਂਤਾਂ
    /* use octal instead of -1 so size_t works (-gstabs+ in gcc) */
    {   VT_LLONG | VT_LONG | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t5=r5;0;01777777777777777777777;" },
#ਜੇ_ਅੰਤ
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
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_USING_DOUBLE_FOR_LDOUBLE
    {   VT_DOUBLE | VT_LONG, 8, DW_ATE_float, "long double:t16=r1;8;0;" },
#ਨਹੀਂਤਾਂ
    {   VT_LDOUBLE, 16, DW_ATE_float, "long double:t16=r1;16;0;" },
#ਜੇ_ਅੰਤ
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
#ਜੇ LONG_ਮਾਪ == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#ਨਹੀਂਤਾਂ
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#ਜੇ_ਅੰਤ
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	N_DEFAULT_DEBUG	(ਆਕਾਰ (default_debug) / ਆਕਾਰ (default_debug[0]))

/* dwarf debug */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ਸਤਰ_ਅਧਾਰ				-5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ਸਤਰ_RANGE			14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_OPCODE_ਅਧਾਰ			13

#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_MIN_INSTR_LEN			4
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_MIN_INSTR_LEN			2
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_MIN_INSTR_LEN			1
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_COMPILE_UNIT		1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_ਅਧਾਰ_TYPE			2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_VARIABLE_EXTERNAL		3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_VARIABLE_STATIC		4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_VARIABLE_LOCAL		5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_FORMAL_PARAMETER		6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_ਸੂਚਕ			7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_ARRAY_TYPE			8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_SUBRANGE_TYPE		9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_TYPEDEF			10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_ENUMERATOR_SIGNED		11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_ENUMERATOR_UNSIGNED	12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_ENUMERATION_TYPE		13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_MEMBER			14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_MEMBER_BF			15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_STRUCTURE_TYPE		16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_STRUCTURE_ਖਾਲੀ_ਥਾਵਾਂ_TYPE	17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_UNION_TYPE			18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_UNION_ਖਾਲੀ_ਥਾਵਾਂ_TYPE		19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_SUBPROGRAM_EXTERNAL	20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_SUBPROGRAM_STATIC		21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_LEXICAL_ਖੰਡ		22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_LEXICAL_ਖਾਲੀ_ਥਾਵਾਂ_ਖੰਡ	23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_SUBROUTINE_TYPE		24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_SUBROUTINE_ਖਾਲੀ_ਥਾਵਾਂ_TYPE	25
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	DWARF_ABBREV_FORMAL_PARAMETER2		26

/* all entries should have been generated with dwarf_uleb128 except
   has_children. All values are currently below 128 so this currently
   works.  */
ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_ਟੈਗ_compile_unit, 1,
          DW_AT_ਉਤਪਾਦਕ, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_ਸਤਰ_strp,
          DW_AT_comp_dir, DW_FORM_ਸਤਰ_strp,
          DW_AT_ਨੀਵਾਂ_pc, DW_FORM_addr,
#ਜੇ PTR_ਮਾਪ == 4
          DW_AT_ਉੱਚਾ_pc, DW_FORM_data4,
#ਨਹੀਂਤਾਂ
          DW_AT_ਉੱਚਾ_pc, DW_FORM_data8,
#ਜੇ_ਅੰਤ
          DW_AT_stmt_list, DW_FORM_sec_ਵਿੱਥ,
          0, 0,
    DWARF_ABBREV_ਅਧਾਰ_TYPE, DW_ਟੈਗ_ਅਧਾਰ_type, 0,
          DW_AT_byte_ਮਾਪ, DW_FORM_udata,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_name, DW_FORM_strp,
          0, 0,
    DWARF_ABBREV_VARIABLE_EXTERNAL, DW_ਟੈਗ_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ਸਤਰ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_ਟੈਗ_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ਸਤਰ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_LOCAL, DW_ਟੈਗ_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER, DW_ਟੈਗ_formal_parameter, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_ਸੂਚਕ, DW_ਟੈਗ_ਸੂਚਕ_type, 0,
          DW_AT_byte_ਮਾਪ, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ARRAY_TYPE, DW_ਟੈਗ_array_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBRANGE_TYPE, DW_ਟੈਗ_subrange_type, 0,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ਉੱਤਲਾ_bound, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_TYPEDEF, DW_ਟੈਗ_typedef, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ਸਤਰ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_ਟੈਗ_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_ਮੁੱਲ, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_ਟੈਗ_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_ਮੁੱਲ, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_ਟੈਗ_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_ਮਾਪ, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ਸਤਰ, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_ਟੈਗ_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ਸਤਰ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ਅੰਕੜੇ_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_ਟੈਗ_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ਸਤਰ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ, DW_FORM_udata,
          DW_AT_ਅੰਕੜੇ_ਦੋਆਧਾਰੀ_ਅੰਕ_ਵਿੱਥ, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_ਟੈਗ_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_ਮਾਪ, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ਸਤਰ, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_ਖਾਲੀ_ਥਾਵਾਂ_TYPE, DW_ਟੈਗ_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_ਮਾਪ, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ਸਤਰ, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_ਟੈਗ_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_ਮਾਪ, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ਸਤਰ, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_ਖਾਲੀ_ਥਾਵਾਂ_TYPE, DW_ਟੈਗ_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_ਮਾਪ, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ਸਤਰ, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_ਟੈਗ_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ਸਤਰ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ਨੀਵਾਂ_pc, DW_FORM_addr,
#ਜੇ PTR_ਮਾਪ == 4
          DW_AT_ਉੱਚਾ_pc, DW_FORM_data4,
#ਨਹੀਂਤਾਂ
          DW_AT_ਉੱਚਾ_pc, DW_FORM_data8,
#ਜੇ_ਅੰਤ
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_ਚੌਖਟਾ_ਅਧਾਰ, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_ਟੈਗ_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ਸਤਰ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ਨੀਵਾਂ_pc, DW_FORM_addr,
#ਜੇ PTR_ਮਾਪ == 4
          DW_AT_ਉੱਚਾ_pc, DW_FORM_data4,
#ਨਹੀਂਤਾਂ
          DW_AT_ਉੱਚਾ_pc, DW_FORM_data8,
#ਜੇ_ਅੰਤ
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_ਚੌਖਟਾ_ਅਧਾਰ, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_ਖੰਡ, DW_ਟੈਗ_lexical_ਖੰਡ, 1,
          DW_AT_ਨੀਵਾਂ_pc, DW_FORM_addr,
#ਜੇ PTR_ਮਾਪ == 4
          DW_AT_ਉੱਚਾ_pc, DW_FORM_data4,
#ਨਹੀਂਤਾਂ
          DW_AT_ਉੱਚਾ_pc, DW_FORM_data8,
#ਜੇ_ਅੰਤ
          0, 0,
    DWARF_ABBREV_LEXICAL_ਖਾਲੀ_ਥਾਵਾਂ_ਖੰਡ, DW_ਟੈਗ_lexical_ਖੰਡ, 0,
          DW_AT_ਨੀਵਾਂ_pc, DW_FORM_addr,
#ਜੇ PTR_ਮਾਪ == 4
          DW_AT_ਉੱਚਾ_pc, DW_FORM_data4,
#ਨਹੀਂਤਾਂ
          DW_AT_ਉੱਚਾ_pc, DW_FORM_data8,
#ਜੇ_ਅੰਤ
          0, 0,
    DWARF_ABBREV_SUBROUTINE_TYPE, DW_ਟੈਗ_subroutine_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBROUTINE_ਖਾਲੀ_ਥਾਵਾਂ_TYPE, DW_ਟੈਗ_subroutine_type, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER2, DW_ਟੈਗ_formal_parameter, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
  0
};

ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ dwarf_ਸਤਰ_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N_STR_HASH (251)

ਬਣਤਰ dwarf_str_hash {
    ਪੂਰਨ len;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਅੰਕੜੇ_ਵਿੱਥ;
    ਬਣਤਰ dwarf_str_hash *ਅਗਲਾ;
};

ਬਣਤਰ _tccdbg {

    ਪੂਰਨ ਆਖਰੀ_ਸਤਰ_ਅੰਕ, new_file;
    ਪੂਰਨ section_sym;

    ਪੂਰਨ debug_ਅਗਲਾ_type;

    ਬਣਤਰ _debug_hash {
        ਪੂਰਨ debug_type;
        Sym *type;
    } *debug_hash_global, *debug_hash_local;

    /* store forward structure/unions types */
    ਬਣਤਰ _debug_forw_hash {
        Sym *type;
        ਪੂਰਨ n_debug_type;
        ਪੂਰਨ *debug_type;
    } *debug_forw_hash_global, *debug_forw_hash_local;

    ਪੂਰਨ n_debug_hash_global;
    ਪੂਰਨ n_debug_hash_local;
    ਪੂਰਨ n_debug_forw_hash_global;
    ਪੂਰਨ n_debug_forw_hash_local;

    ਬਣਤਰ _debug_info {
        ਪੂਰਨ ਸ਼ੁਰੂ;
        ਪੂਰਨ ਸਿਰਾ;
        ਪੂਰਨ ਆਖਰੀ_debug_hash;
        ਪੂਰਨ ਆਖਰੀ_debug_forw_hash;
        ਪੂਰਨ n_sym;
        ਬਣਤਰ debug_sym {
            ਪੂਰਨ type;
            ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮੁੱਲ;
            ਅੱਖਰ *str;
            Section *sec;
            ਪੂਰਨ sym_ਸੂਚਕਾਂਕ;
            ਪੂਰਨ info;
            ਪੂਰਨ file;
            ਪੂਰਨ ਸਤਰ;
        } *sym;
        ਬਣਤਰ _debug_info *ਬੱਚਾ, *ਅਗਲਾ, *ਆਖਰੀ, *ਮਾਪਾ;
    } *debug_info, *debug_info_ਜੜ੍ਹ;

    ਬਣਤਰ {
        ਪੂਰਨ info;
        ਪੂਰਨ abbrev;
        ਪੂਰਨ ਸਤਰ;
        ਪੂਰਨ str;
        ਪੂਰਨ ਸਤਰ_str;
    } dwarf_sym;

    ਬਣਤਰ {
        ਪੂਰਨ ਸ਼ੁਰੂ;
        ਪੂਰਨ dir_ਮਾਪ;
        ਅੱਖਰ **dir_ਸਾਰਣੀ;
        ਪੂਰਨ filename_ਮਾਪ;
        ਬਣਤਰ dwarf_filename_struct {
            ਪੂਰਨ dir_ਇੰਦਰਾਜ;
            ਅੱਖਰ *name;
        } *filename_ਸਾਰਣੀ;
        ਪੂਰਨ ਸਤਰ_ਮਾਪ;
        ਪੂਰਨ ਸਤਰ_max_ਮਾਪ;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ਸਤਰ_ਅੰਕੜੇ;
        ਪੂਰਨ cur_file;
        ਪੂਰਨ ਆਖਰੀ_file;
        ਪੂਰਨ ਆਖਰੀ_pc;
        ਪੂਰਨ ਆਖਰੀ_ਸਤਰ;
    } dwarf_ਸਤਰ;

    ਬਣਤਰ {
        ਪੂਰਨ ਸ਼ੁਰੂ;
        Sym *func;
        ਪੂਰਨ ਸਤਰ;
        ਪੂਰਨ ਅਧਾਰ_type_ਵਰਤਿਆ[N_DEFAULT_DEBUG];
    } dwarf_info;

    ਬਣਤਰ dwarf_str_hash *dwarf_str[N_STR_HASH];
    ਬਣਤਰ dwarf_str_hash *dwarf_ਸਤਰ_str[N_STR_HASH];

    /* test coverage */
    ਬਣਤਰ {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਆਖਰੀ_file_name;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਆਖਰੀ_func_name;
        ਪੂਰਨ ind;
        ਪੂਰਨ ਸਤਰ;
    } tcov_ਅੰਕੜੇ;
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਆਖਰੀ_ਸਤਰ_ਅੰਕ             s1->dState->ਆਖਰੀ_ਸਤਰ_ਅੰਕ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ new_file                  s1->dState->new_file
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ section_sym               s1->dState->section_sym
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ debug_ਅਗਲਾ_type           s1->dState->debug_ਅਗਲਾ_type
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ debug_hash_global         s1->dState->debug_hash_global
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ debug_hash_local          s1->dState->debug_hash_local
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ debug_forw_hash_global    s1->dState->debug_forw_hash_global
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ debug_forw_hash_local     s1->dState->debug_forw_hash_local
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ n_debug_hash_global       s1->dState->n_debug_hash_global
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ n_debug_hash_local        s1->dState->n_debug_hash_local
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ n_debug_forw_hash_global  s1->dState->n_debug_forw_hash_global
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ n_debug_forw_hash_local   s1->dState->n_debug_forw_hash_local
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ debug_info                s1->dState->debug_info
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ debug_info_ਜੜ੍ਹ           s1->dState->debug_info_ਜੜ੍ਹ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dwarf_sym                 s1->dState->dwarf_sym
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dwarf_ਸਤਰ                s1->dState->dwarf_ਸਤਰ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dwarf_info                s1->dState->dwarf_info
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dwarf_str                 s1->dState->dwarf_str
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dwarf_ਸਤਰ_str            s1->dState->dwarf_ਸਤਰ_str
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcov_ਅੰਕੜੇ                 s1->dState->tcov_ਅੰਕੜੇ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
ਸਥਿਰ ਪੂਰਨ put_stabs(TCCState *s1, ਅਚਲ ਅੱਖਰ *str, ਪੂਰਨ type, ਪੂਰਨ other,
    ਪੂਰਨ desc, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮੁੱਲ);

ST_FUNC ਖਾਲੀ tcc_debug_new(TCCState *s1)
{
    ਪੂਰਨ shf = 0;
    ਜੇ (!s1->dState)
        s1->dState = tcc_mallocz(ਆਕਾਰ *s1->dState);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    ਜੇ (s1->do_debug && s1->output_type == TCC_OUTPUT_ਸਮ੍ਰਿਤੀ)
        s1->do_backtrace = 1;
    ਜੇ (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#ਜੇ_ਅੰਤ

    ਜੇ (s1->dwarf) {
	ਪੂਰਨ i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	ਸਥਿਰ ਅਚਲ ਅੱਖਰ *ਅਚਲ debug[] = {
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
        dwarf_ਸਤਰ_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	ਲਈ (i = 0; i < ਆਕਾਰ(debug)/ਆਕਾਰ(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_ਮਿਲਾਓ | SHF_ਲੜੀਆਂ;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_ਸਤਰ_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	ਜੇ (s1->dwarf >= 5) {
            dwarf_ਸਤਰ_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_ਸਤਰ_str_section->sh_entsize = 1;
	    dwarf_ਸਤਰ_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    ਨਹੀਂਤਾਂ
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = ਆਕਾਰ(Stab_Sym);
        stab_section->sh_addralign = ਆਕਾਰ ((Stab_Sym*)0)->n_ਮੁੱਲ;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
ਸਥਿਰ ਪੂਰਨ put_stabs(TCCState *s1, ਅਚਲ ਅੱਖਰ *str, ਪੂਰਨ type, ਪੂਰਨ other, ਪੂਰਨ desc,
                      ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮੁੱਲ)
{
    Stab_Sym *sym;

    ਬਿਨਾਨਿਸ਼ਾਨੀ ਵਿੱਥ;
    ਜੇ (type == N_SLINE
        && (ਵਿੱਥ = stab_section->ਅੰਕੜੇ_ਵਿੱਥ)
        && (sym = (Stab_Sym*)(stab_section->ਅੰਕੜੇ + ਵਿੱਥ) - 1)
        && sym->n_type == type
        && sym->n_ਮੁੱਲ == ਮੁੱਲ) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        ਵਾਪਸ 0;
    }

    sym = section_ptr_ਜੋੜੋ(stab_section, ਆਕਾਰ(Stab_Sym));
    ਜੇ (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } ਨਹੀਂਤਾਂ {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_ਮੁੱਲ = ਮੁੱਲ;
    ਵਾਪਸ 1;
}

ਸਥਿਰ ਖਾਲੀ put_stabs_r(TCCState *s1, ਅਚਲ ਅੱਖਰ *str, ਪੂਰਨ type, ਪੂਰਨ other, ਪੂਰਨ desc,
                        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮੁੱਲ, Section *sec, ਪੂਰਨ sym_ਸੂਚਕਾਂਕ)
{
    ਜੇ (put_stabs(s1, str, type, other, desc, ਮੁੱਲ))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->ਅੰਕੜੇ_ਵਿੱਥ - 4,
                      ਆਕਾਰ ((Stab_Sym*)0)->n_ਮੁੱਲ == PTR_ਮਾਪ ? R_ਅੰਕੜੇ_PTR : R_ਅੰਕੜੇ_32,
                      sym_ਸੂਚਕਾਂਕ);
}

ਸਥਿਰ ਖਾਲੀ put_stabn(TCCState *s1, ਪੂਰਨ type, ਪੂਰਨ other, ਪੂਰਨ desc, ਪੂਰਨ ਮੁੱਲ)
{
    put_stabs(s1, ਨਿਰਾ, type, other, desc, ਮੁੱਲ);
}

/* ------------------------------------------------------------------------- */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	dwarf_data1(s,ਅੰਕੜੇ) \
	(*(uint8_t*)section_ptr_ਜੋੜੋ((s), 1) = (ਅੰਕੜੇ))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	dwarf_data2(s,ਅੰਕੜੇ) \
	write16le(section_ptr_ਜੋੜੋ((s), 2), (ਅੰਕੜੇ))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	dwarf_data4(s,ਅੰਕੜੇ) \
	write32le(section_ptr_ਜੋੜੋ((s), 4), (ਅੰਕੜੇ))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	dwarf_data8(s,ਅੰਕੜੇ) \
	write64le(section_ptr_ਜੋੜੋ((s), 8), (ਅੰਕੜੇ))

ਸਥਿਰ ਪੂਰਨ dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    ਵਾਪਸ put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_ਅੰਕ, ਨਿਰਾ);
}

ਸਥਿਰ ਖਾਲੀ dwarf_reloc(Section *s, ਪੂਰਨ sym, ਪੂਰਨ rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->ਅੰਕੜੇ_ਵਿੱਥ, rel, sym, 0);
}

ਸਥਿਰ ਖਾਲੀ free_str(ਬਣਤਰ dwarf_str_hash **str)
{
    ਪੂਰਨ i;

    ਲਈ (i = 0; i < N_STR_HASH; i++) {
       ਜਦੋਂ (str[i]) {
           ਬਣਤਰ dwarf_str_hash *ਅਗਲਾ = str[i]->ਅਗਲਾ;

           tcc_free(str[i]);
           str[i] = ਅਗਲਾ;
       }
    }
}

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ str_hash(ਅਚਲ ਅੱਖਰ *s)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ h = 5381;

    ਜਦੋਂ (*s)
       h += (*s++ & 0xffu) + h * 31;
    ਵਾਪਸ h;
}

ਸਥਿਰ ਖਾਲੀ dwarf_string(Section *s, Section *dw, ਪੂਰਨ sym, ਅਚਲ ਅੱਖਰ *str)
{
    TCCState *s1 = s->s1;
    ਪੂਰਨ len, hash = str_hash(str) % N_STR_HASH;
    ਅੱਖਰ *ptr;
    ਬਣਤਰ dwarf_str_hash *new_hash;
    ਬਣਤਰ dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_ਸਤਰ_str;

    len = ਲੜੀ_ਲੰਬਾਈ(str) + 1;
    new_hash = dw_hash[hash];
    ਜਦੋਂ (new_hash) {
	ਜੇ (new_hash->len == len &&
	    !memcmp(str, dw->ਅੰਕੜੇ + new_hash->ਅੰਕੜੇ_ਵਿੱਥ, len))
	    ਰੋਕੋ;
	new_hash = new_hash->ਅਗਲਾ;
    }
    ਜੇ (new_hash == ਨਿਰਾ) {
	ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ = dw->ਅੰਕੜੇ_ਵਿੱਥ;

        new_hash = dw_hash[hash];
        ਜਦੋਂ (new_hash) {
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ n = new_hash->ਅੰਕੜੇ_ਵਿੱਥ + new_hash->len - len;

	    ਜੇ (new_hash->len > len &&
	        !memcmp(str, dw->ਅੰਕੜੇ + n, len)) {
		ਵਿੱਥ = n;
		ਰੋਕੋ;
	    }
	    new_hash = new_hash->ਅਗਲਾ;
        }
	ਜੇ (new_hash == ਨਿਰਾ) {
	    ptr = section_ptr_ਜੋੜੋ(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (ਬਣਤਰ dwarf_str_hash *)
	    tcc_malloc(ਆਕਾਰ(ਬਣਤਰ dwarf_str_hash));
	new_hash->len = len;
	new_hash->ਅੰਕੜੇ_ਵਿੱਥ = ਵਿੱਥ;
	new_hash->ਅਗਲਾ = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->ਅੰਕੜੇ_ਵਿੱਥ, R_ਅੰਕੜੇ_32_DW, sym,
                   PTR_ਮਾਪ == 4 ? 0 : new_hash->ਅੰਕੜੇ_ਵਿੱਥ);
    dwarf_data4(s, PTR_ਮਾਪ == 4 ? new_hash->ਅੰਕੜੇ_ਵਿੱਥ : 0);
}

ਸਥਿਰ ਖਾਲੀ dwarf_strp(Section *s, ਅਚਲ ਅੱਖਰ *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

ਸਥਿਰ ਖਾਲੀ dwarf_ਸਤਰ_strp(Section *s, ਅਚਲ ਅੱਖਰ *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_ਸਤਰ_str_section, dwarf_sym.ਸਤਰ_str, str);
}

ਸਥਿਰ ਖਾਲੀ dwarf_ਸਤਰ_op(TCCState *s1, ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ op)
{
    ਜੇ (dwarf_ਸਤਰ.ਸਤਰ_ਮਾਪ >= dwarf_ਸਤਰ.ਸਤਰ_max_ਮਾਪ) {
	dwarf_ਸਤਰ.ਸਤਰ_max_ਮਾਪ += 1024;
	dwarf_ਸਤਰ.ਸਤਰ_ਅੰਕੜੇ =
	    (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *)tcc_realloc(dwarf_ਸਤਰ.ਸਤਰ_ਅੰਕੜੇ,
					 dwarf_ਸਤਰ.ਸਤਰ_max_ਮਾਪ);
    }
    dwarf_ਸਤਰ.ਸਤਰ_ਅੰਕੜੇ[dwarf_ਸਤਰ.ਸਤਰ_ਮਾਪ++] = op;
}

ਸਥਿਰ ਖਾਲੀ dwarf_file(TCCState *s1)
{
    ਪੂਰਨ i, j;
    ਅੱਖਰ *filename;
    ਪੂਰਨ ਸੂਚਕਾਂਕ_ਵਿੱਥ = s1->dwarf < 5;

    ਜੇ (!strcmp(file->filename, "<command line>")) {
        dwarf_ਸਤਰ.cur_file = 1;
	ਵਾਪਸ;
    }
    filename = strrchr(file->filename, '/');
    ਜੇ (filename == ਨਿਰਾ) {
        ਲਈ (i = 1; i < dwarf_ਸਤਰ.filename_ਮਾਪ; i++)
            ਜੇ (dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[i].dir_ਇੰਦਰਾਜ == 0 &&
		strcmp(dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[i].name,
		       file->filename) == 0) {
		    dwarf_ਸਤਰ.cur_file = i + ਸੂਚਕਾਂਕ_ਵਿੱਥ;
	            ਵਾਪਸ;
		}
	i = -ਸੂਚਕਾਂਕ_ਵਿੱਥ;
	filename = file->filename;
    }
    ਨਹੀਂਤਾਂ {
	ਅੱਖਰ *undo = filename;
	ਅੱਖਰ *dir = file->filename;

	*filename++ = '\0';
        ਲਈ (i = 0; i < dwarf_ਸਤਰ.dir_ਮਾਪ; i++)
	    ਜੇ (strcmp(dwarf_ਸਤਰ.dir_ਸਾਰਣੀ[i], dir) == 0) {
		ਲਈ (j = 1; j < dwarf_ਸਤਰ.filename_ਮਾਪ; j++)
		    ਜੇ (dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[j].dir_ਇੰਦਰਾਜ - ਸੂਚਕਾਂਕ_ਵਿੱਥ
			== i &&
			strcmp(dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_ਸਤਰ.cur_file = j + ਸੂਚਕਾਂਕ_ਵਿੱਥ;
			ਵਾਪਸ;
		    }
		ਰੋਕੋ;
	    }
	ਜੇ (i == dwarf_ਸਤਰ.dir_ਮਾਪ) {
	    dwarf_ਸਤਰ.dir_ਮਾਪ++;
	    dwarf_ਸਤਰ.dir_ਸਾਰਣੀ =
                (ਅੱਖਰ **) tcc_realloc(dwarf_ਸਤਰ.dir_ਸਾਰਣੀ,
                                      dwarf_ਸਤਰ.dir_ਮਾਪ *
                                      ਆਕਾਰ (ਅੱਖਰ *));
            dwarf_ਸਤਰ.dir_ਸਾਰਣੀ[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_ਸਤਰ.filename_ਸਾਰਣੀ =
        (ਬਣਤਰ dwarf_filename_struct *)
        tcc_realloc(dwarf_ਸਤਰ.filename_ਸਾਰਣੀ,
                    (dwarf_ਸਤਰ.filename_ਮਾਪ + 1) *
                    ਆਕਾਰ (ਬਣਤਰ dwarf_filename_struct));
    dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[dwarf_ਸਤਰ.filename_ਮਾਪ].dir_ਇੰਦਰਾਜ =
	i + ਸੂਚਕਾਂਕ_ਵਿੱਥ;
    dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[dwarf_ਸਤਰ.filename_ਮਾਪ].name =
        tcc_strdup(filename);
    dwarf_ਸਤਰ.cur_file = dwarf_ਸਤਰ.filename_ਮਾਪ++ + ਸੂਚਕਾਂਕ_ਵਿੱਥ;
    ਵਾਪਸ;
}

#ਜੇ 0
ਸਥਿਰ ਪੂਰਨ dwarf_uleb128_ਮਾਪ (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਮੁੱਲ)
{
    ਪੂਰਨ ਮਾਪ =  0;

    ਕਰੋ {
        ਮੁੱਲ >>= 7;
        ਮਾਪ++;
    } ਜਦੋਂ (ਮੁੱਲ != 0);
    ਵਾਪਸ ਮਾਪ;
}
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਪੂਰਨ dwarf_sleb128_ਮਾਪ (ਲੰਮਾ ਲੰਮਾ ਮੁੱਲ)
{
    ਪੂਰਨ ਮਾਪ =  0;
    ਲੰਮਾ ਲੰਮਾ ਸਿਰਾ = ਮੁੱਲ >> 63;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਆਖਰੀ = ਸਿਰਾ & 0x40;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ byte;

    ਕਰੋ {
        byte = ਮੁੱਲ & 0x7f;
        ਮੁੱਲ >>= 7;
        ਮਾਪ++;
    } ਜਦੋਂ (ਮੁੱਲ != ਸਿਰਾ || (byte & 0x40) != ਆਖਰੀ);
    ਵਾਪਸ ਮਾਪ;
}

ਸਥਿਰ ਖਾਲੀ dwarf_uleb128 (Section *s, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਮੁੱਲ)
{
    ਕਰੋ {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ byte = ਮੁੱਲ & 0x7f;

        ਮੁੱਲ >>= 7;
        dwarf_data1(s, byte | (ਮੁੱਲ ? 0x80 : 0));
    } ਜਦੋਂ (ਮੁੱਲ != 0);
}

ਸਥਿਰ ਖਾਲੀ dwarf_sleb128 (Section *s, ਲੰਮਾ ਲੰਮਾ ਮੁੱਲ)
{
    ਪੂਰਨ ਹੋਰ;
    ਲੰਮਾ ਲੰਮਾ ਸਿਰਾ = ਮੁੱਲ >> 63;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਆਖਰੀ = ਸਿਰਾ & 0x40;

    ਕਰੋ {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ byte = ਮੁੱਲ & 0x7f;

        ਮੁੱਲ >>= 7;
	ਹੋਰ = ਮੁੱਲ != ਸਿਰਾ || (byte & 0x40) != ਆਖਰੀ;
        dwarf_data1(s, byte | (0x80 * ਹੋਰ));
    } ਜਦੋਂ (ਹੋਰ);
}

ਸਥਿਰ ਖਾਲੀ dwarf_uleb128_op (TCCState *s1, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਮੁੱਲ)
{
    ਕਰੋ {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ byte = ਮੁੱਲ & 0x7f;

        ਮੁੱਲ >>= 7;
        dwarf_ਸਤਰ_op(s1, byte | (ਮੁੱਲ ? 0x80 : 0));
    } ਜਦੋਂ (ਮੁੱਲ != 0);
}

ਸਥਿਰ ਖਾਲੀ dwarf_sleb128_op (TCCState *s1, ਲੰਮਾ ਲੰਮਾ ਮੁੱਲ)
{
    ਪੂਰਨ ਹੋਰ;
    ਲੰਮਾ ਲੰਮਾ ਸਿਰਾ = ਮੁੱਲ >> 63;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਆਖਰੀ = ਸਿਰਾ & 0x40;

    ਕਰੋ {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ byte = ਮੁੱਲ & 0x7f;

        ਮੁੱਲ >>= 7;
        ਹੋਰ = ਮੁੱਲ != ਸਿਰਾ || (byte & 0x40) != ਆਖਰੀ;
        dwarf_ਸਤਰ_op(s1, byte | (0x80 * ਹੋਰ));
    } ਜਦੋਂ (ਹੋਰ);
}

#ਜੇ TCC_EH_ਚੌਖਟਾ
ST_FUNC ਖਾਲੀ tcc_eh_ਚੌਖਟਾ_ਸ਼ੁਰੂ(TCCState *s1)
{
    ਜੇ (!s1->unwind_tables)
        ਵਾਪਸ;
    eh_ਚੌਖਟਾ_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_ਸ਼ੁਰੂ = eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ_ਵਿੱਥ;
    dwarf_data4(eh_ਚੌਖਟਾ_section, 0); //ਲੰਮਾਈ
    dwarf_data4(eh_ਚੌਖਟਾ_section, 0); // CIE ID
    dwarf_data1(eh_ਚੌਖਟਾ_section, 1); //ਸੰਸਕਰਣ
    dwarf_data1(eh_ਚੌਖਟਾ_section, 'z'); // Augmentation String
    dwarf_data1(eh_ਚੌਖਟਾ_section, 'R');
    dwarf_data1(eh_ਚੌਖਟਾ_section, 0);
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_I386
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_ਚੌਖਟਾ_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 8); // return address column
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 1); // Augmentation len
    dwarf_data1(eh_ਚੌਖਟਾ_section, FDE_ENCODING);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 4); // r4 (esp)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 4); // ofs 4
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_ਵਿੱਥ + 8); // r8 (eip)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 1); // cfa-4
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_X86_64
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_ਚੌਖਟਾ_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 16); // return address column
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 1); // Augmentation len
    dwarf_data1(eh_ਚੌਖਟਾ_section, FDE_ENCODING);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 8); // ofs 8
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_ਵਿੱਥ + 16); // r16 (rip)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 1); // cfa-8
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM
    /* TODO: arm must be compiled with: -funwind-tables */
    /* arm also uses .ARM.extab and .ARM.exidx sections */
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 2); // code_alignment_factor
    dwarf_sleb128(eh_ਚੌਖਟਾ_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 14); // return address column
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 1); // Augmentation len
    dwarf_data1(eh_ਚੌਖਟਾ_section, FDE_ENCODING);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 13); // r13 (sp)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 0); // ofs 0
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_ਚੌਖਟਾ_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 30); // return address column
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 1); // Augmentation len
    dwarf_data1(eh_ਚੌਖਟਾ_section, FDE_ENCODING);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 31); // x31 (sp)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 0); // ofs 0
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ[s1->eh_ਸ਼ੁਰੂ + 8] = 3; // version = 3
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_ਚੌਖਟਾ_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 1); // return address column
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 1); // Augmentation len
    dwarf_data1(eh_ਚੌਖਟਾ_section, FDE_ENCODING);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 2); // r2 (sp)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 0); // ofs 0
#ਜੇ_ਅੰਤ
    ਜਦੋਂ ((eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ_ਵਿੱਥ - s1->eh_ਸ਼ੁਰੂ) & 3)
	dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_nop);
    write32le(eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ + s1->eh_ਸ਼ੁਰੂ, //ਲੰਮਾਈ
	      eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ_ਵਿੱਥ - s1->eh_ਸ਼ੁਰੂ - 4);
}

ਸਥਿਰ ਖਾਲੀ tcc_debug_ਚੌਖਟਾ_ਸਿਰਾ(TCCState *s1, ਪੂਰਨ ਮਾਪ)
{
    ਪੂਰਨ eh_section_sym;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ fde_ਸ਼ੁਰੂ;

    ਜੇ (!eh_ਚੌਖਟਾ_section)
	ਵਾਪਸ;
    eh_section_sym = dwarf_get_section_sym(ਪਾਠ_section);
    fde_ਸ਼ੁਰੂ = eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ_ਵਿੱਥ;
    dwarf_data4(eh_ਚੌਖਟਾ_section, 0); //ਲੰਮਾਈ
    dwarf_data4(eh_ਚੌਖਟਾ_section,
		fde_ਸ਼ੁਰੂ - s1->eh_ਸ਼ੁਰੂ + 4); // CIE Pointer
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_I386
    dwarf_reloc(eh_ਚੌਖਟਾ_section, eh_section_sym, R_386_PC32);
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_X86_64
    dwarf_reloc(eh_ਚੌਖਟਾ_section, eh_section_sym, R_X86_64_PC32);
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM
    dwarf_reloc(eh_ਚੌਖਟਾ_section, eh_section_sym, R_ARM_REL32);
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
    dwarf_reloc(eh_ਚੌਖਟਾ_section, eh_section_sym, R_AARCH64_PREL32);
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    dwarf_reloc(eh_ਚੌਖਟਾ_section, eh_section_sym, R_RISCV_32_PCREL);
#ਜੇ_ਅੰਤ
    dwarf_data4(eh_ਚੌਖਟਾ_section, func_ind); // PC Begin
    dwarf_data4(eh_ਚੌਖਟਾ_section, ਮਾਪ); // PC Range
    dwarf_data1(eh_ਚੌਖਟਾ_section, 0); // Augmentation Length
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_I386
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa_ਵਿੱਥ);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 8);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_ਵਿੱਥ + 5); // r5 (ebp)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 2); // cfa-8
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa_ਰਜਿਸਟਰ);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 5); // r5 (ebp)
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_ਚੌਖਟਾ_section, ਮਾਪ - 5);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_restore + 5); // r5 (ebp)
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 4); // r4 (esp)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 4); // ofs 4
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_X86_64
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa_ਵਿੱਥ);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 16);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_ਵਿੱਥ + 6); // r6 (rbp)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 2); // cfa-16
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa_ਰਜਿਸਟਰ);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 6); // r6 (rbp)
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_ਚੌਖਟਾ_section, ਮਾਪ - 5);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 8); // ofs 8
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM
    /* TODO */
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa_ਵਿੱਥ);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 8);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_ਵਿੱਥ + 14); // r14 (lr)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 1);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_ਵਿੱਥ + 11); // r11 (fp)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 2);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_ਚੌਖਟਾ_section, ਮਾਪ / 2 - 5);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa_ਰਜਿਸਟਰ);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 11); // r11 (fp)
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa_ਵਿੱਥ);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 224);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_ਵਿੱਥ + 29); // x29 (fp)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 28); // cfa-224
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_ਵਿੱਥ + 30); // x30 (lr)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 27); // cfa-216
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa_ਵਿੱਥ);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 224 + ((-loc + 15) & ~15));
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_ਚੌਖਟਾ_section, ਮਾਪ / 4 - 5);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_restore + 30); // x30 (lr)
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_restore + 29); // x29 (fp)
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa_ਵਿੱਥ);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 0);
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa_ਵਿੱਥ);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 16); // ofs 16
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_ਵਿੱਥ + 1); // r1 (ra, lr)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 2); // cfa-8
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_ਵਿੱਥ + 8); // r8 (s0, fp)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 4); // cfa-16
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 8); // r8 (s0, fp)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 0); // ofs 0
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc4);
    ਜਦੋਂ (ਮਾਪ >= 4 &&
	   read32le(cur_ਪਾਠ_section->ਅੰਕੜੇ + func_ind + ਮਾਪ - 4) != 0x00008067)
	ਮਾਪ -= 4;
    dwarf_data4(eh_ਚੌਖਟਾ_section, ਮਾਪ - 36);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 2); // r2 (r2, sp)
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 16); // ofs 16
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_restore + 1); // r1 (lr)
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_restore + 8); // r8 (s0, fp)
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_def_cfa_ਵਿੱਥ);
    dwarf_uleb128(eh_ਚੌਖਟਾ_section, 0); // ofs 0
#ਜੇ_ਅੰਤ
    ਜਦੋਂ ((eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ_ਵਿੱਥ - fde_ਸ਼ੁਰੂ) & 3)
	dwarf_data1(eh_ਚੌਖਟਾ_section, DW_CFA_nop);
    write32le(eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ + fde_ਸ਼ੁਰੂ, //ਲੰਮਾਈ
	      eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ_ਵਿੱਥ - fde_ਸ਼ੁਰੂ - 4);
}

ST_FUNC ਖਾਲੀ tcc_eh_ਚੌਖਟਾ_ਸਿਰਾ(TCCState *s1)
{
    ਜੇ (!eh_ਚੌਖਟਾ_section)
	ਵਾਪਸ;
    dwarf_data4(eh_ਚੌਖਟਾ_section, 0);
}

ਬਣਤਰ eh_ਖੋਜ_ਸਾਰਣੀ {
    uint32_t pc_ਵਿੱਥ;
    uint32_t fde_ਵਿੱਥ;
};

ਸਥਿਰ ਪੂਰਨ ਛਾਂਟੋ_eh_ਸਾਰਣੀ(ਅਚਲ ਖਾਲੀ *a, ਅਚਲ ਖਾਲੀ *b)
{
    uint32_t pc1 = ((ਅਚਲ ਬਣਤਰ eh_ਖੋਜ_ਸਾਰਣੀ *)a)->pc_ਵਿੱਥ;
    uint32_t pc2 = ((ਅਚਲ ਬਣਤਰ eh_ਖੋਜ_ਸਾਰਣੀ *)b)->pc_ਵਿੱਥ;

    ਵਾਪਸ pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC ਖਾਲੀ tcc_eh_ਚੌਖਟਾ_hdr(TCCState *s1, ਪੂਰਨ final)
{
    ਪੂਰਨ ਗਿਣਤੀ_3 = 0, ਵਿੱਥ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਗਿਣਤੀ_ਵਿੱਥ, tab_ਵਿੱਥ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ln, *ਸਿਰਾ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਆਖਰੀ_cie_ਵਿੱਥ = 0xffffffff;

    ਜੇ (!eh_ਚੌਖਟਾ_section || !eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ_ਵਿੱਥ)
	ਵਾਪਸ;
    ਜੇ (final && !eh_ਚੌਖਟਾ_hdr_section)
	ਵਾਪਸ;
    ਜੇ (final == 0)
        eh_ਚੌਖਟਾ_hdr_section =
	    new_section(s1, ".eh_frame_hdr", SHT_PROGBITS, SHF_ALLOC);
    eh_ਚੌਖਟਾ_hdr_section->ਅੰਕੜੇ_ਵਿੱਥ = 0;
    dwarf_data1(eh_ਚੌਖਟਾ_hdr_section, 1); //ਸੰਸਕਰਣ
    // Pointer Encoding Format
    dwarf_data1(eh_ਚੌਖਟਾ_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_pcrel);
    // Count Encoding Format
    dwarf_data1(eh_ਚੌਖਟਾ_hdr_section, DW_EH_PE_udata4 | DW_EH_PE_absptr);
    // Table Encoding Format
    dwarf_data1(eh_ਚੌਖਟਾ_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_datarel);
    ਵਿੱਥ = eh_ਚੌਖਟਾ_section->sh_addr -
             eh_ਚੌਖਟਾ_hdr_section->sh_addr -
             eh_ਚੌਖਟਾ_hdr_section->ਅੰਕੜੇ_ਵਿੱਥ;
    dwarf_data4(eh_ਚੌਖਟਾ_hdr_section, ਵਿੱਥ); // eh_frame_ptr
    //ਗਿਣਤੀ
    ਗਿਣਤੀ_ਵਿੱਥ = eh_ਚੌਖਟਾ_hdr_section->ਅੰਕੜੇ_ਵਿੱਥ;
    dwarf_data4(eh_ਚੌਖਟਾ_hdr_section, 0);
    tab_ਵਿੱਥ = eh_ਚੌਖਟਾ_hdr_section->ਅੰਕੜੇ_ਵਿੱਥ;
    ln = eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ;
    ਸਿਰਾ = eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ + eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ_ਵਿੱਥ;
    ਜਦੋਂ (ln < ਸਿਰਾ) {
	ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *fde = ln, *rd = ln;
	ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ cie_ਵਿੱਥ, ਸੰਸਕਰਣ, ਲੰਮਾਈ = dwarf_read_4(rd, ਸਿਰਾ);
	ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ pc_ਵਿੱਥ, fde_ਵਿੱਥ;

	ਜੇ (ਲੰਮਾਈ == 0)
	    ਜਾਓ ਅਗਲਾ;
        cie_ਵਿੱਥ = dwarf_read_4(rd, ਸਿਰਾ);
	ਜੇ (cie_ਵਿੱਥ == 0)
	    ਜਾਓ ਅਗਲਾ;
	ਜੇ (cie_ਵਿੱਥ != ਆਖਰੀ_cie_ਵਿੱਥ) {
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *cie = rd - cie_ਵਿੱਥ + 4;

	    ਜੇ (cie < eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ)
		ਜਾਓ ਅਗਲਾ;
	    ਸੰਸਕਰਣ = dwarf_read_1(cie, ਸਿਰਾ);
	    ਜੇ ((ਸੰਸਕਰਣ == 1 || ਸੰਸਕਰਣ == 3) &&
	        dwarf_read_1(cie, ਸਿਰਾ) == 'z' && // Augmentation String
		dwarf_read_1(cie, ਸਿਰਾ) == 'R' &&
		dwarf_read_1(cie, ਸਿਰਾ) == 0) {
	        dwarf_read_uleb128(&cie, ਸਿਰਾ); // code_alignment_factor
	        dwarf_read_sleb128(&cie, ਸਿਰਾ); // data_alignment_factor
		dwarf_read_1(cie, ਸਿਰਾ); // return address column
		ਜੇ (dwarf_read_uleb128(&cie, ਸਿਰਾ) == 1 &&
		    dwarf_read_1(cie, ਸਿਰਾ) == FDE_ENCODING) {
		    ਆਖਰੀ_cie_ਵਿੱਥ = cie_ਵਿੱਥ;
		}
		ਨਹੀਂਤਾਂ
		    ਜਾਓ ਅਗਲਾ;
	    }
	    ਨਹੀਂਤਾਂ
		ਜਾਓ ਅਗਲਾ;
	}
	ਗਿਣਤੀ_3++;
	fde_ਵਿੱਥ = eh_ਚੌਖਟਾ_section->sh_addr +
		     (fde - eh_ਚੌਖਟਾ_section->ਅੰਕੜੇ) -
		     eh_ਚੌਖਟਾ_hdr_section->sh_addr;
	pc_ਵਿੱਥ = dwarf_read_4(rd, ਸਿਰਾ) + fde_ਵਿੱਥ + 8;
	dwarf_data4(eh_ਚੌਖਟਾ_hdr_section, pc_ਵਿੱਥ);
	dwarf_data4(eh_ਚੌਖਟਾ_hdr_section, fde_ਵਿੱਥ);
ਅਗਲਾ:
	ln += ਲੰਮਾਈ + 4;
    }
    add32le(eh_ਚੌਖਟਾ_hdr_section->ਅੰਕੜੇ + ਗਿਣਤੀ_ਵਿੱਥ, ਗਿਣਤੀ_3);
    qsort(eh_ਚੌਖਟਾ_hdr_section->ਅੰਕੜੇ + tab_ਵਿੱਥ, ਗਿਣਤੀ_3,
	  ਆਕਾਰ(ਬਣਤਰ eh_ਖੋਜ_ਸਾਰਣੀ), ਛਾਂਟੋ_eh_ਸਾਰਣੀ);
}
#ਜੇ_ਅੰਤ

/* start of translation unit info */
ST_FUNC ਖਾਲੀ tcc_debug_ਸ਼ੁਰੂ(TCCState *s1)
{
    ਪੂਰਨ i;
    ਅੱਖਰ buf[512];
    ਅੱਖਰ *filename;

    /* we might currently #include the <command-line> */
    filename = file->prev ? file->prev->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    ਜੇ (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            ਪਾਠ_section->sh_ਅੰਕ, "$a");

        new_file = ਆਖਰੀ_ਸਤਰ_ਅੰਕ = 0;
        debug_ਅਗਲਾ_type = N_DEFAULT_DEBUG;
        debug_hash_global = ਨਿਰਾ;
        debug_hash_local = ਨਿਰਾ;
        debug_forw_hash_global = ਨਿਰਾ;
        debug_forw_hash_local = ਨਿਰਾ;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, ਆਕਾਰ(buf));
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
        normalize_slashes(buf);
#ਜੇ_ਅੰਤ

        ਜੇ (s1->dwarf) {
            ਪੂਰਨ ਸ਼ੁਰੂ_abbrev;
            ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr;
	    ਅੱਖਰ *undo;

            /* dwarf_abbrev */
            ਸ਼ੁਰੂ_abbrev = dwarf_abbrev_section->ਅੰਕੜੇ_ਵਿੱਥ;
            ptr = section_ptr_ਜੋੜੋ(dwarf_abbrev_section, ਆਕਾਰ(dwarf_abbrev_init));
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(ptr, dwarf_abbrev_init, ਆਕਾਰ(dwarf_abbrev_init));

            ਜੇ (s1->dwarf < 5) {
    	        ਜਦੋਂ (*ptr) {
    	            ptr += 3;
    	            ਜਦੋਂ (*ptr) {
    	                ਜੇ (ptr[1] == DW_FORM_ਸਤਰ_strp)
    		            ptr[1] = DW_FORM_strp;
		        ਜੇ (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    ਜੇ  (ptr[1] == DW_FORM_sec_ਵਿੱਥ)
			         ptr[1] = DW_FORM_data4;
			    /* This code uses only size < 0x80 so these are
			       compatible. */
			    ਜੇ  (ptr[1] == DW_FORM_exprloc)
			         ptr[1] = DW_FORM_block1;
			}
    	                ptr += 2;
    	            }
		    ptr += 2;
    	        }
            }

            dwarf_sym.info = dwarf_get_section_sym(dwarf_info_section);
            dwarf_sym.abbrev = dwarf_get_section_sym(dwarf_abbrev_section);
            dwarf_sym.ਸਤਰ = dwarf_get_section_sym(dwarf_ਸਤਰ_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            ਜੇ (tcc_state->dwarf >= 5)
    	        dwarf_sym.ਸਤਰ_str = dwarf_get_section_sym(dwarf_ਸਤਰ_str_section);
            ਨਹੀਂਤਾਂ {
    	        dwarf_ਸਤਰ_str_section = dwarf_str_section;
                dwarf_sym.ਸਤਰ_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(ਪਾਠ_section);

            /* dwarf_info */
            dwarf_info.ਸ਼ੁਰੂ = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
            dwarf_data4(dwarf_info_section, 0); //ਮਾਪ
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            ਜੇ (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_ਮਾਪ);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_ਅੰਕੜੇ_32_DW);
                dwarf_data4(dwarf_info_section, ਸ਼ੁਰੂ_abbrev);
            }
            ਨਹੀਂਤਾਂ {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_ਅੰਕੜੇ_32_DW);
                dwarf_data4(dwarf_info_section, ਸ਼ੁਰੂ_abbrev);
                dwarf_data1(dwarf_info_section, PTR_ਮਾਪ);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_ਸੰਸਕਰਣ);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_ਸਤਰ_strp(dwarf_info_section, filename);
            dwarf_ਸਤਰ_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_ਅੰਕੜੇ_PTR);
#ਜੇ PTR_ਮਾਪ == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#ਨਹੀਂਤਾਂ
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#ਜੇ_ਅੰਤ
            dwarf_reloc(dwarf_info_section, dwarf_sym.ਸਤਰ, R_ਅੰਕੜੇ_32_DW);
            dwarf_data4(dwarf_info_section, dwarf_ਸਤਰ_section->ਅੰਕੜੇ_ਵਿੱਥ); // stmt_list

            /* dwarf_line */
            dwarf_ਸਤਰ.ਸ਼ੁਰੂ = dwarf_ਸਤਰ_section->ਅੰਕੜੇ_ਵਿੱਥ;
            dwarf_data4(dwarf_ਸਤਰ_section, 0); //ਲੰਮਾਈ
            dwarf_data2(dwarf_ਸਤਰ_section, s1->dwarf); // version
            ਜੇ (s1->dwarf >= 5) {
                dwarf_data1(dwarf_ਸਤਰ_section, PTR_ਮਾਪ); // address size
                dwarf_data1(dwarf_ਸਤਰ_section, 0); // segment selector
            }
            dwarf_data4(dwarf_ਸਤਰ_section, 0); // prologue Length
            dwarf_data1(dwarf_ਸਤਰ_section, DWARF_MIN_INSTR_LEN);
            ਜੇ (s1->dwarf >= 4)
                dwarf_data1(dwarf_ਸਤਰ_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_ਸਤਰ_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_ਸਤਰ_section, DWARF_ਸਤਰ_ਅਧਾਰ);
            dwarf_data1(dwarf_ਸਤਰ_section, DWARF_ਸਤਰ_RANGE);
            dwarf_data1(dwarf_ਸਤਰ_section, DWARF_OPCODE_ਅਧਾਰ);
            ptr = section_ptr_ਜੋੜੋ(dwarf_ਸਤਰ_section, ਆਕਾਰ(dwarf_ਸਤਰ_opcodes));
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(ptr, dwarf_ਸਤਰ_opcodes, ਆਕਾਰ(dwarf_ਸਤਰ_opcodes));
	    undo = strrchr(filename, '/');
	    ਜੇ (undo)
		*undo = 0;
            dwarf_ਸਤਰ.dir_ਮਾਪ = 1 + (undo != ਨਿਰਾ);
            dwarf_ਸਤਰ.dir_ਸਾਰਣੀ = (ਅੱਖਰ **) tcc_malloc(ਆਕਾਰ (ਅੱਖਰ *) *
							dwarf_ਸਤਰ.dir_ਮਾਪ);
            dwarf_ਸਤਰ.dir_ਸਾਰਣੀ[0] = tcc_strdup(buf);
	    ਜੇ (undo)
                dwarf_ਸਤਰ.dir_ਸਾਰਣੀ[1] = tcc_strdup(filename);
            dwarf_ਸਤਰ.filename_ਮਾਪ = 2;
            dwarf_ਸਤਰ.filename_ਸਾਰਣੀ =
    	        (ਬਣਤਰ dwarf_filename_struct *)
    	        tcc_malloc(2*ਆਕਾਰ (ਬਣਤਰ dwarf_filename_struct));
            dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[0].dir_ਇੰਦਰਾਜ = 0;
	    ਜੇ (undo) {
                dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[0].name = tcc_strdup(undo + 1);
                dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[1].dir_ਇੰਦਰਾਜ = 1;
                dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    ਨਹੀਂਤਾਂ {
                dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[0].name = tcc_strdup(filename);
                dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[1].dir_ਇੰਦਰਾਜ = 0;
                dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[1].name = tcc_strdup(filename);
	    }
            dwarf_ਸਤਰ.ਸਤਰ_ਮਾਪ = dwarf_ਸਤਰ.ਸਤਰ_max_ਮਾਪ = 0;
            dwarf_ਸਤਰ.ਸਤਰ_ਅੰਕੜੇ = ਨਿਰਾ;
            dwarf_ਸਤਰ.cur_file = 1;
            dwarf_ਸਤਰ.ਆਖਰੀ_file = 0;
            dwarf_ਸਤਰ.ਆਖਰੀ_pc = 0;
            dwarf_ਸਤਰ.ਆਖਰੀ_ਸਤਰ = 1;
            dwarf_ਸਤਰ_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_ਮਾਪ); // extended size
            dwarf_ਸਤਰ_op(s1, DW_LNE_ਸੈੱਟ_ਪਤਾ);
            ਲਈ (i = 0; i < PTR_ਮਾਪ; i++)
    	        dwarf_ਸਤਰ_op(s1, 0);
            memset(&dwarf_info.ਅਧਾਰ_type_ਵਰਤਿਆ, 0, ਆਕਾਰ(dwarf_info.ਅਧਾਰ_type_ਵਰਤਿਆ));
        }
        ਨਹੀਂਤਾਂ
        {
            /* file info: full path + filename */
            pstrcat(buf, ਆਕਾਰ(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      ਪਾਠ_section->sh_ਅੰਕ, ਨਿਰਾ);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ, ਪਾਠ_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ, ਪਾਠ_section, section_sym);
            ਲਈ (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

ਸਥਿਰ ਖਾਲੀ fix_debug_forw_hash(TCCState *s1, ਪੂਰਨ global, ਪੂਰਨ ਸ਼ੁਰੂ);

/* put end of translation unit info */
ST_FUNC ਖਾਲੀ tcc_debug_ਸਿਰਾ(TCCState *s1)
{

    ਜੇ (!s1->do_debug || debug_ਅਗਲਾ_type == 0)
        ਵਾਪਸ;

    ਜੇ (debug_info_ਜੜ੍ਹ)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    ਜੇ (s1->dwarf) {
	ਪੂਰਨ i;
	ਪੂਰਨ ਸ਼ੁਰੂ_aranges;
	ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr;
	ਪੂਰਨ ਪਾਠ_ਮਾਪ = ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ;

	/* dwarf_info */
	fix_debug_forw_hash(s1, 0, 0);
	fix_debug_forw_hash(s1, 1, 0);
	dwarf_data1(dwarf_info_section, 0);
	ptr = dwarf_info_section->ਅੰਕੜੇ + dwarf_info.ਸ਼ੁਰੂ;
	write32le(ptr, dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ - dwarf_info.ਸ਼ੁਰੂ - 4);
	write32le(ptr + 25 + (s1->dwarf >= 5) + PTR_ਮਾਪ, ਪਾਠ_ਮਾਪ);

	/* dwarf_aranges */
	ਸ਼ੁਰੂ_aranges = dwarf_aranges_section->ਅੰਕੜੇ_ਵਿੱਥ;
	dwarf_data4(dwarf_aranges_section, 0); //ਮਾਪ
	dwarf_data2(dwarf_aranges_section, 2); // version
	dwarf_reloc(dwarf_aranges_section, dwarf_sym.info, R_ਅੰਕੜੇ_32_DW);
	dwarf_data4(dwarf_aranges_section, 0); // dwarf_info
#ਜੇ PTR_ਮਾਪ == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#ਨਹੀਂਤਾਂ
	dwarf_data1(dwarf_aranges_section, 8); // address size
#ਜੇ_ਅੰਤ
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_ਅੰਕੜੇ_PTR);
#ਜੇ PTR_ਮਾਪ == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, ਪਾਠ_ਮਾਪ); //ਸਿਰਾ
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#ਨਹੀਂਤਾਂ
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, ਪਾਠ_ਮਾਪ); //ਸਿਰਾ
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#ਜੇ_ਅੰਤ
	ptr = dwarf_aranges_section->ਅੰਕੜੇ + ਸ਼ੁਰੂ_aranges;
	write32le(ptr, dwarf_aranges_section->ਅੰਕੜੇ_ਵਿੱਥ - ਸ਼ੁਰੂ_aranges - 4);

	/* dwarf_line */
	ਜੇ (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_ਸਤਰ_section, 1); /*ਖਾਨਾ*/
	    dwarf_uleb128(dwarf_ਸਤਰ_section, DW_LNCT_ਰਸਤਾ);
	    dwarf_uleb128(dwarf_ਸਤਰ_section, DW_FORM_ਸਤਰ_strp);
	    dwarf_uleb128(dwarf_ਸਤਰ_section, dwarf_ਸਤਰ.dir_ਮਾਪ);
	    ਲਈ (i = 0; i < dwarf_ਸਤਰ.dir_ਮਾਪ; i++)
	        dwarf_ਸਤਰ_strp(dwarf_ਸਤਰ_section, dwarf_ਸਤਰ.dir_ਸਾਰਣੀ[i]);
	    dwarf_data1(dwarf_ਸਤਰ_section, 2); /*ਖਾਨਾ*/
	    dwarf_uleb128(dwarf_ਸਤਰ_section, DW_LNCT_ਰਸਤਾ);
	    dwarf_uleb128(dwarf_ਸਤਰ_section, DW_FORM_ਸਤਰ_strp);
	    dwarf_uleb128(dwarf_ਸਤਰ_section, DW_LNCT_directory_ਸੂਚਕਾਂਕ);
	    dwarf_uleb128(dwarf_ਸਤਰ_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_ਸਤਰ_section, dwarf_ਸਤਰ.filename_ਮਾਪ);
	    ਲਈ (i = 0; i < dwarf_ਸਤਰ.filename_ਮਾਪ; i++) {
	        dwarf_ਸਤਰ_strp(dwarf_ਸਤਰ_section,
				dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[i].name);
	        dwarf_uleb128(dwarf_ਸਤਰ_section,
			      dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[i].dir_ਇੰਦਰਾਜ);
	    }
	}
	ਨਹੀਂਤਾਂ {
	    ਪੂਰਨ len;

	    ਲਈ (i = 0; i < dwarf_ਸਤਰ.dir_ਮਾਪ; i++) {
	        len = ਲੜੀ_ਲੰਬਾਈ(dwarf_ਸਤਰ.dir_ਸਾਰਣੀ[i]) + 1;
	        ptr = section_ptr_ਜੋੜੋ(dwarf_ਸਤਰ_section, len);
	        memmove(ptr, dwarf_ਸਤਰ.dir_ਸਾਰਣੀ[i], len);
	    }
	    dwarf_data1(dwarf_ਸਤਰ_section, 0); /* end dir */
	    ਲਈ (i = 0; i < dwarf_ਸਤਰ.filename_ਮਾਪ; i++) {
	        len = ਲੜੀ_ਲੰਬਾਈ(dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[i].name) + 1;
	        ptr = section_ptr_ਜੋੜੋ(dwarf_ਸਤਰ_section, len);
	        memmove(ptr, dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[i].name, len);
	        dwarf_uleb128(dwarf_ਸਤਰ_section,
			      dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[i].dir_ਇੰਦਰਾਜ);
	        dwarf_uleb128(dwarf_ਸਤਰ_section, 0); /*ਸਮਾਂ*/
	        dwarf_uleb128(dwarf_ਸਤਰ_section, 0); /*ਮਾਪ*/
	    }
	    dwarf_data1(dwarf_ਸਤਰ_section, 0); /* end file */
	}
	ਲਈ (i = 0; i < dwarf_ਸਤਰ.dir_ਮਾਪ; i++)
	    tcc_free(dwarf_ਸਤਰ.dir_ਸਾਰਣੀ[i]);
	tcc_free(dwarf_ਸਤਰ.dir_ਸਾਰਣੀ);
	ਲਈ (i = 0; i < dwarf_ਸਤਰ.filename_ਮਾਪ; i++)
	    tcc_free(dwarf_ਸਤਰ.filename_ਸਾਰਣੀ[i].name);
	tcc_free(dwarf_ਸਤਰ.filename_ਸਾਰਣੀ);

	dwarf_ਸਤਰ_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_ਸਤਰ_op(s1, DW_LNE_ਸਿਰਾ_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_ਸਤਰ_section->ਅੰਕੜੇ[dwarf_ਸਤਰ.ਸ਼ੁਰੂ + 6 + i],
		  dwarf_ਸਤਰ_section->ਅੰਕੜੇ_ਵਿੱਥ - dwarf_ਸਤਰ.ਸ਼ੁਰੂ - (10 + i));
	section_ptr_ਜੋੜੋ(dwarf_ਸਤਰ_section, 3);
	dwarf_reloc(dwarf_ਸਤਰ_section, section_sym, R_ਅੰਕੜੇ_PTR);
	ptr = section_ptr_ਜੋੜੋ(dwarf_ਸਤਰ_section, dwarf_ਸਤਰ.ਸਤਰ_ਮਾਪ - 3);
	memmove(ptr - 3, dwarf_ਸਤਰ.ਸਤਰ_ਅੰਕੜੇ, dwarf_ਸਤਰ.ਸਤਰ_ਮਾਪ);
	tcc_free(dwarf_ਸਤਰ.ਸਤਰ_ਅੰਕੜੇ);
	write32le(dwarf_ਸਤਰ_section->ਅੰਕੜੇ + dwarf_ਸਤਰ.ਸ਼ੁਰੂ,
		  dwarf_ਸਤਰ_section->ਅੰਕੜੇ_ਵਿੱਥ - dwarf_ਸਤਰ.ਸ਼ੁਰੂ - 4);
    }
    ਨਹੀਂਤਾਂ
    {
        put_stabs_r(s1, ਨਿਰਾ, N_SO, 0, 0,
                    ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ, ਪਾਠ_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_ਸਤਰ_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_ਅਗਲਾ_type = 0;
}

ਸਥਿਰ BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    ਜੇ (f->filename[0] == ':')
        f = f->prev;
    ਜੇ (f && new_file) {
        new_file = ਆਖਰੀ_ਸਤਰ_ਅੰਕ = 0;
        ਜੇ (s1->dwarf)
            dwarf_file(s1);
        ਨਹੀਂਤਾਂ
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, ਪਾਠ_section, section_sym);
    }
    ਵਾਪਸ f;
}

/* put alternative filename */
ST_FUNC ਖਾਲੀ tcc_debug_newfile(TCCState *s1)
{
    ਜੇ (!s1->do_debug)
        ਵਾਪਸ;
    ਜੇ (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC ਖਾਲੀ tcc_debug_bincl(TCCState *s1)
{
    ਜੇ (!s1->do_debug)
        ਵਾਪਸ;
    ਜੇ (s1->dwarf)
        dwarf_file(s1);
    ਨਹੀਂਤਾਂ
        put_stabs(s1, file->filename, N_BINCL, 0, 0, 0);
    new_file = 1;
}

/* end of #include */
ST_FUNC ਖਾਲੀ tcc_debug_eincl(TCCState *s1)
{
    ਜੇ (!s1->do_debug)
        ਵਾਪਸ;
    ਜੇ (s1->dwarf)
        dwarf_file(s1);
    ਨਹੀਂਤਾਂ
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC ਖਾਲੀ tcc_debug_ਸਤਰ(TCCState *s1)
{
    BufferedFile *f;

    ਜੇ (!s1->do_debug)
        ਵਾਪਸ;
    ਜੇ (cur_ਪਾਠ_section != ਪਾਠ_section || nocode_wanted)
        ਵਾਪਸ;
    f = put_new_file(s1);
    ਜੇ (!f)
        ਵਾਪਸ;
    ਜੇ (ਆਖਰੀ_ਸਤਰ_ਅੰਕ == f->ਸਤਰ_ਅੰਕ)
        ਵਾਪਸ;
    ਆਖਰੀ_ਸਤਰ_ਅੰਕ = f->ਸਤਰ_ਅੰਕ;

    ਜੇ (s1->dwarf) {
	ਪੂਰਨ len_pc = (ind - dwarf_ਸਤਰ.ਆਖਰੀ_pc) / DWARF_MIN_INSTR_LEN;
	ਪੂਰਨ len_ਸਤਰ = f->ਸਤਰ_ਅੰਕ - dwarf_ਸਤਰ.ਆਖਰੀ_ਸਤਰ;
	ਪੂਰਨ n = len_pc * DWARF_ਸਤਰ_RANGE + len_ਸਤਰ + DWARF_OPCODE_ਅਧਾਰ - DWARF_ਸਤਰ_ਅਧਾਰ;

	ਜੇ (dwarf_ਸਤਰ.cur_file != dwarf_ਸਤਰ.ਆਖਰੀ_file) {
	    dwarf_ਸਤਰ.ਆਖਰੀ_file = dwarf_ਸਤਰ.cur_file;
	    dwarf_ਸਤਰ_op(s1, DW_LNS_ਸੈੱਟ_file);
	    dwarf_uleb128_op(s1, dwarf_ਸਤਰ.cur_file);
	}
	ਜੇ (len_pc &&
	    len_ਸਤਰ >= DWARF_ਸਤਰ_ਅਧਾਰ && len_ਸਤਰ <= (DWARF_OPCODE_ਅਧਾਰ + DWARF_ਸਤਰ_ਅਧਾਰ) &&
	    n >= DWARF_OPCODE_ਅਧਾਰ && n <= 255)
            dwarf_ਸਤਰ_op(s1, n);
	ਨਹੀਂਤਾਂ {
	    ਜੇ (len_pc) {
	        n = len_pc * DWARF_ਸਤਰ_RANGE + 0 + DWARF_OPCODE_ਅਧਾਰ - DWARF_ਸਤਰ_ਅਧਾਰ;
	        ਜੇ (n >= DWARF_OPCODE_ਅਧਾਰ && n <= 255)
                    dwarf_ਸਤਰ_op(s1, n);
		ਨਹੀਂਤਾਂ {
	            dwarf_ਸਤਰ_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    ਜੇ (len_ਸਤਰ) {
	        n = 0 * DWARF_ਸਤਰ_RANGE + len_ਸਤਰ + DWARF_OPCODE_ਅਧਾਰ - DWARF_ਸਤਰ_ਅਧਾਰ;
	        ਜੇ (len_ਸਤਰ >= DWARF_ਸਤਰ_ਅਧਾਰ && len_ਸਤਰ <= (DWARF_OPCODE_ਅਧਾਰ + DWARF_ਸਤਰ_ਅਧਾਰ) &&
		    n >= DWARF_OPCODE_ਅਧਾਰ && n <= 255)
	            dwarf_ਸਤਰ_op(s1, n);
		ਨਹੀਂਤਾਂ {
	            dwarf_ਸਤਰ_op(s1, DW_LNS_advance_ਸਤਰ);
		    dwarf_sleb128_op(s1, len_ਸਤਰ);
                    /* advance by nothing */
	            dwarf_ਸਤਰ_op(s1, DWARF_OPCODE_ਅਧਾਰ - DWARF_ਸਤਰ_ਅਧਾਰ);
		}
	    }
	}
	dwarf_ਸਤਰ.ਆਖਰੀ_pc = ind;
	dwarf_ਸਤਰ.ਆਖਰੀ_ਸਤਰ = f->ਸਤਰ_ਅੰਕ;
    }
    ਨਹੀਂਤਾਂ
    {
	ਜੇ (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->ਸਤਰ_ਅੰਕ, ind - func_ind);
        } ਨਹੀਂਤਾਂ {
            /* from tcc_assemble */
            put_stabs_r(s1, ਨਿਰਾ, N_SLINE, 0, f->ਸਤਰ_ਅੰਕ, ind, ਪਾਠ_section, section_sym);
        }
    }
}

ਸਥਿਰ ਖਾਲੀ tcc_debug_stabs (TCCState *s1, ਅਚਲ ਅੱਖਰ *str, ਪੂਰਨ type, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮੁੱਲ,
                             Section *sec, ਪੂਰਨ sym_ਸੂਚਕਾਂਕ, ਪੂਰਨ info)
{
    ਬਣਤਰ debug_sym *s;

    ਜੇ (debug_info) {
        debug_info->sym =
            (ਬਣਤਰ debug_sym *)tcc_realloc (debug_info->sym,
                                             ਆਕਾਰ(ਬਣਤਰ debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->ਮੁੱਲ = ਮੁੱਲ;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_ਸੂਚਕਾਂਕ = sym_ਸੂਚਕਾਂਕ;
        s->info = info;
        s->file = dwarf_ਸਤਰ.cur_file;
        s->ਸਤਰ = file->ਸਤਰ_ਅੰਕ;
    }
    ਨਹੀਂਤਾਂ ਜੇ (sec)
        put_stabs_r (s1, str, type, 0, 0, ਮੁੱਲ, sec, sym_ਸੂਚਕਾਂਕ);
    ਨਹੀਂਤਾਂ
        put_stabs (s1, str, type, 0, 0, ਮੁੱਲ);
}

ਸਥਿਰ ਖਾਲੀ fix_debug_forw_hash(TCCState *s1, ਪੂਰਨ global, ਪੂਰਨ ਸ਼ੁਰੂ)
{
    ਜੇ (s1->dwarf) {
        ਪੂਰਨ i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	ਬਣਤਰ _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	ਲਈ (i = ਸ਼ੁਰੂ; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    ਪੂਰਨ pos = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_ਖਾਲੀ_ਥਾਵਾਂ_TYPE
                                             : DWARF_ABBREV_STRUCTURE_ਖਾਲੀ_ਥਾਵਾਂ_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_ਪਹਿਲਾ_ANOM
                       ? "" : get_tok_str(t->v, ਨਿਰਾ));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_ਸਤਰ.cur_file);
            dwarf_uleb128(dwarf_info_section, file->ਸਤਰ_ਅੰਕ);
	    ਲਈ (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->ਅੰਕੜੇ +
			  hash[i].debug_type[j],
			  pos - dwarf_info.ਸ਼ੁਰੂ);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC ਖਾਲੀ tcc_debug_stabn(TCCState *s1, ਪੂਰਨ type, ਪੂਰਨ ਮੁੱਲ)
{
    ਜੇ (!s1->do_debug)
        ਵਾਪਸ;
    ਜੇ (type == N_LBRAC) {
        ਬਣਤਰ _debug_info *info =
            (ਬਣਤਰ _debug_info *) tcc_mallocz(ਆਕਾਰ (*info));

        info->ਸ਼ੁਰੂ = ਮੁੱਲ;
        info->ਆਖਰੀ_debug_hash = n_debug_hash_local;
        info->ਆਖਰੀ_debug_forw_hash = n_debug_forw_hash_local;
        info->ਮਾਪਾ = debug_info;
        ਜੇ (debug_info) {
            ਜੇ (debug_info->ਬੱਚਾ) {
                ਜੇ (debug_info->ਬੱਚਾ->ਆਖਰੀ)
                    debug_info->ਬੱਚਾ->ਆਖਰੀ->ਅਗਲਾ = info;
                ਨਹੀਂਤਾਂ
                    debug_info->ਬੱਚਾ->ਅਗਲਾ = info;
                debug_info->ਬੱਚਾ->ਆਖਰੀ = info;
            }
            ਨਹੀਂਤਾਂ
                debug_info->ਬੱਚਾ = info;
        }
        ਨਹੀਂਤਾਂ
            debug_info_ਜੜ੍ਹ = info;
        debug_info = info;
    }
    ਨਹੀਂਤਾਂ {
	fix_debug_forw_hash(s1, 0, debug_info->ਆਖਰੀ_debug_forw_hash);
        n_debug_hash_local = debug_info->ਆਖਰੀ_debug_hash;
        n_debug_forw_hash_local = debug_info->ਆਖਰੀ_debug_forw_hash;
        debug_info->ਸਿਰਾ = ਮੁੱਲ;
        debug_info = debug_info->ਮਾਪਾ;
    }
}

ਸਥਿਰ ਪੂਰਨ check_global(Sym *t)
{
    Sym *g = local_ਢੇਰ;

    ਜਦੋਂ (g) {
	ਜੇ (t == g)
	    ਵਾਪਸ 0;
	g = g->prev;
    }
    ਵਾਪਸ 1;
}

ਸਥਿਰ ਪੂਰਨ tcc_debug_ਲੱਭੋ(TCCState *s1, Sym *t, ਪੂਰਨ dwarf)
{
    ਪੂਰਨ i , g = check_global(t);
    ਪੂਰਨ n_hash, *n_forw_hash;
    ਬਣਤਰ _debug_hash *hash;
    ਬਣਤਰ _debug_forw_hash **forw_hash;

    ਜੇ ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	ਲਈ (i = 0; i < *n_forw_hash; i++)
            ਜੇ (t == (*forw_hash)[i].type)
		ਵਾਪਸ 0;
	*forw_hash = (ਬਣਤਰ _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * ਆਕਾਰ(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = ਨਿਰਾ;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	ਵਾਪਸ 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    ਲਈ (i = 0; i < n_hash; i++)
        ਜੇ (t == hash[i].type)
	    ਵਾਪਸ hash[i].debug_type;
    ਵਾਪਸ -1;
}

ਸਥਿਰ ਪੂਰਨ tcc_get_dwarf_info(TCCState *s1, Sym *s);

ਸਥਿਰ ਖਾਲੀ tcc_debug_check_forw(TCCState *s1, Sym *t, ਪੂਰਨ debug_type)
{
    ਜੇ ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        ਪੂਰਨ i, j, g = check_global(t);
        ਪੂਰਨ n_forw_hash;
        ਬਣਤਰ _debug_forw_hash **forw_hash;

	ਲਈ (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    ਲਈ (j = 0; j < n_forw_hash; j++)
                ਜੇ (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * ਆਕਾਰ(ਪੂਰਨ));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    ਵਾਪਸ;
                }
	}
    }
}

ਸਥਿਰ ਖਾਲੀ stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC ਖਾਲੀ tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    ਜੇ (!(s1->do_debug & 2))
	ਵਾਪਸ;
    ਜੇ (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        ਵਾਪਸ;
    }
    ਜੇ ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        ਪੂਰਨ i, j, debug_type, g = check_global(t->ref);
        ਪੂਰਨ *n_forw_hash;
        ਬਣਤਰ _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	ਲਈ (i = 0; i < *n_forw_hash; i++)
	    ਜੇ (t->ref == (*forw_hash)[i].type) {
		ਜੇ (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    ਲਈ (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->ਅੰਕੜੇ +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.ਸ਼ੁਰੂ);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		ਲਈ (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

ਸਥਿਰ ਪੂਰਨ tcc_debug_ਜੋੜੋ(TCCState *s1, Sym *t, ਪੂਰਨ dwarf)
{
    ਪੂਰਨ ਵਿੱਥ = dwarf ? dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ : ++debug_ਅਗਲਾ_type;
    ਪੂਰਨ *n_hash, g = check_global(t);
    ਬਣਤਰ _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (ਬਣਤਰ _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * ਆਕਾਰ(**hash));
    (*hash)[*n_hash].debug_type = ਵਿੱਥ;
    (*hash)[(*n_hash)++].type = t;
    ਵਾਪਸ ਵਿੱਥ;
}

ਸਥਿਰ ਪੂਰਨ STRUCT_NODEBUG(Sym *s)
{
    ਵਾਪਸ
    (s->a.nodebug ||
     ((s->v & ~SYM_ਖੇਤਰ) >= SYM_ਪਹਿਲਾ_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

ਸਥਿਰ ਪੂਰਨ stabs_struct_ਲੱਭੋ(TCCState *s1, Sym *t, ਪੂਰਨ *p_id)
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
    ਜੇ (ਨਿਰਾ == p_id)
        ਵਾਪਸ s && !s->r && t->c >= 0;
    ਜੇ (ਨਿਰਾ == s) {
        /* just use global_stack always */
        s = sym_push2(&global_ਢੇਰ, SYM_ਖੇਤਰ|0x00DEBBED, 0, ++debug_ਅਗਲਾ_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    ਜੇ (s->r || t->c < 0) /* already defined or still incomplete */
        ਵਾਪਸ 0;
    s->r = 1;
    ਵਾਪਸ 1;
}

ਸਥਿਰ ਪੂਰਨ remove_type_info(ਪੂਰਨ type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        ਜੇ ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        ਜੇ (!(type & VT_BITFIELD) && (type & VT_STRUCT_ਨਕਾਬ) > VT_ENUM)
	    type &= ~VT_STRUCT_ਨਕਾਬ;
	ਵਾਪਸ type;
}

ਸਥਿਰ ਖਾਲੀ tcc_get_debug_info(TCCState *s1, Sym *s, CString *ਨਤੀਜਾ)
{
    ਪੂਰਨ type;
    ਪੂਰਨ n = 0;
    ਪੂਰਨ debug_type = -1;
    Sym *t = s;
    CString str;

    ਲਈ (;;) {
        type = remove_type_info (t->type.t);
        ਜੇ (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        ਨਹੀਂਤਾਂ
            ਰੋਕੋ;
    }
    ਜੇ ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        ਜੇ (stabs_struct_ਲੱਭੋ(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_ਪਹਿਲਾ_ANOM
                         ? "" : get_tok_str(t->v, ਨਿਰਾ),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            ਜਦੋਂ (t->ਅਗਲਾ) {
                ਪੂਰਨ pos, ਮਾਪ, align;
                t = t->ਅਗਲਾ;
		ਜੇ (STRUCT_NODEBUG(t))
		    ਜਾਰੀ;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_ਖੇਤਰ) >= SYM_ਪਹਿਲਾ_ANOM
                             ? "" : get_tok_str(t->v, ਨਿਰਾ)
                             );
                tcc_get_debug_info (s1, t, &str);
                ਜੇ (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + ਦੋਆਧਾਰੀ_ਅੰਕ_POS(t->type.t);
                    ਮਾਪ = ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ(t->type.t);
                }
                ਨਹੀਂਤਾਂ {
                    pos = t->c * 8;
                    ਮਾਪ = type_ਮਾਪ(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, ਮਾਪ);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.ਅੰਕੜੇ, N_LSYM, 0, ਨਿਰਾ, 0, 0);
            cstr_free (&str);
        }
    }
    ਨਹੀਂਤਾਂ ਜੇ (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        ਜੇ (stabs_struct_ਲੱਭੋ(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_ਪਹਿਲਾ_ANOM
                         ? "" : get_tok_str(t->v, ਨਿਰਾ),
                         debug_type);
            ਜਦੋਂ (t->ਅਗਲਾ) {
                t = t->ਅਗਲਾ;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_ਖੇਤਰ) >= SYM_ਪਹਿਲਾ_ANOM
                             ? "" : get_tok_str(t->v, ਨਿਰਾ));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (ਪੂਰਨ)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.ਅੰਕੜੇ, N_LSYM, 0, ਨਿਰਾ, 0, 0);
            cstr_free (&str);
	}
    }
    ਨਹੀਂਤਾਂ ਜੇ ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_ਨਕਾਬ;
        ਲਈ (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            ਜੇ (default_debug[debug_type - 1].type == type)
                ਰੋਕੋ;
        ਜੇ (debug_type > N_DEFAULT_DEBUG)
            ਵਾਪਸ;
    }

    ਜੇ (ਨਿਰਾ == ਨਤੀਜਾ) /* from stabs_struct_complete() */
        ਵਾਪਸ;

    ਜੇ (n > 0)
        cstr_printf (ਨਤੀਜਾ, "%d=", ++debug_ਅਗਲਾ_type);
    t = s;
    ਲਈ (;;) {
        type = remove_type_info (t->type.t);
        ਜੇ (type == VT_PTR)
            cstr_printf (ਨਤੀਜਾ, "%d=*", ++debug_ਅਗਲਾ_type);
        ਨਹੀਂਤਾਂ ਜੇ (type == (VT_PTR | VT_ARRAY))
            cstr_printf (ਨਤੀਜਾ, "%d=ar1;0;%d;",
                         ++debug_ਅਗਲਾ_type, t->type.ref->c - 1);
        ਨਹੀਂਤਾਂ ਜੇ (type == VT_FUNC) {
            cstr_printf (ਨਤੀਜਾ, "%d=f", ++debug_ਅਗਲਾ_type);
            tcc_get_debug_info (s1, t->type.ref, ਨਤੀਜਾ);
            ਵਾਪਸ;
        }
        ਨਹੀਂਤਾਂ
            ਰੋਕੋ;
        t = t->type.ref;
    }
    cstr_printf (ਨਤੀਜਾ, "%d", debug_type);
}

ਸਥਿਰ ਖਾਲੀ stabs_struct_complete(TCCState *s1, CType *t)
{
    ਜੇ (stabs_struct_ਲੱਭੋ(s1, t->ref, ਨਿਰਾ)) {
        Sym s = {0}; s.type = *t;
        tcc_get_debug_info(s1, &s, ਨਿਰਾ);
    }
}

ਸਥਿਰ ਪੂਰਨ tcc_get_dwarf_info(TCCState *s1, Sym *s)
{
    ਪੂਰਨ type;
    ਪੂਰਨ debug_type = -1;
    Sym *e, *t = s;
    ਪੂਰਨ i;
    ਪੂਰਨ ਆਖਰੀ_pos = -1;
    ਪੂਰਨ retval;

    ਜੇ (new_file)
        put_new_file(s1);
    ਲਈ (;;) {
        type = remove_type_info (t->type.t);
        ਜੇ (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        ਨਹੀਂਤਾਂ
            ਰੋਕੋ;
    }
    ਜੇ ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_ਲੱਭੋ(s1, t, 1);
	ਜੇ (debug_type == -1) {
	    ਪੂਰਨ pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_ਜੋੜੋ(s1, t, 1);
	    e = t;
	    i = 0;
	    ਜਦੋਂ (e->ਅਗਲਾ) {
		e = e->ਅਗਲਾ;
		ਜੇ (STRUCT_NODEBUG(e))
		    ਜਾਰੀ;
		i++;
	    }
	    pos_type = (ਪੂਰਨ *) tcc_malloc(i * ਆਕਾਰ(ਪੂਰਨ));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->ਅਗਲਾ ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_ਖਾਲੀ_ਥਾਵਾਂ_TYPE
		        : t->ਅਗਲਾ ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_ਖਾਲੀ_ਥਾਵਾਂ_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_ਪਹਿਲਾ_ANOM
                       ? "" : get_tok_str(t->v, ਨਿਰਾ));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_ਸਤਰ.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ਸਤਰ_ਅੰਕ);
	    ਜੇ (t->ਅਗਲਾ) {
	        pos_sib = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            ਜਦੋਂ (e->ਅਗਲਾ) {
                e = e->ਅਗਲਾ;
		ਜੇ (STRUCT_NODEBUG(e))
		    ਜਾਰੀ;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, ਨਿਰਾ));
		dwarf_uleb128(dwarf_info_section, dwarf_ਸਤਰ.cur_file);
		dwarf_uleb128(dwarf_info_section, file->ਸਤਰ_ਅੰਕ);
		pos_type[i++] = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
		dwarf_data4(dwarf_info_section, 0);
                ਜੇ (e->type.t & VT_BITFIELD) {
                    ਪੂਰਨ pos = e->c * 8 + ਦੋਆਧਾਰੀ_ਅੰਕ_POS(e->type.t);
                    ਪੂਰਨ ਮਾਪ = ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ(e->type.t);

		    dwarf_uleb128(dwarf_info_section, ਮਾਪ);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		ਨਹੀਂਤਾਂ
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    ਜੇ (t->ਅਗਲਾ) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->ਅੰਕੜੇ + pos_sib,
		          dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ - dwarf_info.ਸ਼ੁਰੂ);
	    }
	    e = t;
	    i = 0;
	    ਜਦੋਂ (e->ਅਗਲਾ) {
		e = e->ਅਗਲਾ;
		ਜੇ (STRUCT_NODEBUG(e))
		    ਜਾਰੀ;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->ਅੰਕੜੇ + pos_type[i++],
			  type - dwarf_info.ਸ਼ੁਰੂ);
	    }
	    tcc_free(pos_type);
        }
    }
    ਨਹੀਂਤਾਂ ਜੇ (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_ਲੱਭੋ(s1, t, 1);
	ਜੇ (debug_type == -1) {
	    ਪੂਰਨ pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_ਜੋੜੋ(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_ਪਹਿਲਾ_ANOM
                       ? "" : get_tok_str(t->v, ਨਿਰਾ));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.ਸ਼ੁਰੂ);
	    dwarf_uleb128(dwarf_info_section, dwarf_ਸਤਰ.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ਸਤਰ_ਅੰਕ);
	    pos_sib = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            ਜਦੋਂ (e->ਅਗਲਾ) {
                e = e->ਅਗਲਾ;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_ਖੇਤਰ) >= SYM_ਪਹਿਲਾ_ANOM
                           ? "" : get_tok_str(e->v, ਨਿਰਾ));
		ਜੇ (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		ਨਹੀਂਤਾਂ
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->ਅੰਕੜੇ + pos_sib,
		      dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ - dwarf_info.ਸ਼ੁਰੂ);
	}
    }
    ਨਹੀਂਤਾਂ ਜੇ ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_ਨਕਾਬ;
        ਲਈ (i = 1; i <= N_DEFAULT_DEBUG; i++)
            ਜੇ (default_debug[i - 1].type == type)
                ਰੋਕੋ;
        ਜੇ (i > N_DEFAULT_DEBUG)
            ਵਾਪਸ 0;
	debug_type = dwarf_info.ਅਧਾਰ_type_ਵਰਤਿਆ[i - 1];
	ਜੇ (debug_type == 0) {
	    ਅੱਖਰ name[100];

	    debug_type = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ਅਧਾਰ_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].ਮਾਪ);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, ਆਕਾਰ name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.ਅਧਾਰ_type_ਵਰਤਿਆ[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = ਨਿਰਾ;
    t = s;
    ਲਈ (;;) {
        type = remove_type_info (t->type.t);
        ਜੇ (type == VT_PTR) {
	    i = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
	    ਜੇ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ਸੂਚਕ);
	    dwarf_data1(dwarf_info_section, PTR_ਮਾਪ);
	    ਜੇ (ਆਖਰੀ_pos != -1) {
		tcc_debug_check_forw(s1, e, ਆਖਰੀ_pos);
		write32le(dwarf_info_section->ਅੰਕੜੇ + ਆਖਰੀ_pos,
			  i - dwarf_info.ਸ਼ੁਰੂ);
	    }
	    ਆਖਰੀ_pos = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        ਨਹੀਂਤਾਂ ਜੇ (type == (VT_PTR | VT_ARRAY)) {
	    ਪੂਰਨ sib_pos, sub_type;
#ਜੇ LONG_ਮਾਪ == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#ਨਹੀਂਤਾਂ
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#ਜੇ_ਅੰਤ

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
	    ਜੇ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    ਜੇ (ਆਖਰੀ_pos != -1) {
		tcc_debug_check_forw(s1, e, ਆਖਰੀ_pos);
		write32le(dwarf_info_section->ਅੰਕੜੇ + ਆਖਰੀ_pos,
			  i - dwarf_info.ਸ਼ੁਰੂ);
	    }
	    ਆਖਰੀ_pos = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
	    dwarf_data4(dwarf_info_section, 0);
	    ਲਈ (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.ਸ਼ੁਰੂ);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		ਜੇ (type != (VT_PTR | VT_ARRAY))
		    ਰੋਕੋ;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->ਅੰਕੜੇ + sib_pos,
		      dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ - dwarf_info.ਸ਼ੁਰੂ);
	}
        ਨਹੀਂਤਾਂ ਜੇ (type == VT_FUNC) {
	    ਪੂਰਨ sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    ਜੇ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->ਅਗਲਾ ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_ਖਾਲੀ_ਥਾਵਾਂ_TYPE);
	    ਜੇ (ਆਖਰੀ_pos != -1) {
		tcc_debug_check_forw(s1, e, ਆਖਰੀ_pos);
		write32le(dwarf_info_section->ਅੰਕੜੇ + ਆਖਰੀ_pos,
			  i - dwarf_info.ਸ਼ੁਰੂ);
	    }
	    ਆਖਰੀ_pos = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    ਜੇ (t->type.ref->ਅਗਲਾ) {
	        sib_pos = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    ਜਦੋਂ (f->ਅਗਲਾ) {
		f = f->ਅਗਲਾ;
		i++;
	    }
	    pos_type = (ਪੂਰਨ *) tcc_malloc(i * ਆਕਾਰ(ਪੂਰਨ));
	    f = t->type.ref;
	    i = 0;
	    ਜਦੋਂ (f->ਅਗਲਾ) {
		f = f->ਅਗਲਾ;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    ਜੇ (t->type.ref->ਅਗਲਾ) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->ਅੰਕੜੇ + sib_pos,
		          dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ - dwarf_info.ਸ਼ੁਰੂ);
	    }
	    f = t->type.ref;
	    i = 0;
	    ਜਦੋਂ (f->ਅਗਲਾ) {
		f = f->ਅਗਲਾ;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->ਅੰਕੜੇ + pos_type[i++],
                          type - dwarf_info.ਸ਼ੁਰੂ);
	    }
	    tcc_free(pos_type);
        }
        ਨਹੀਂਤਾਂ {
	    ਜੇ (ਆਖਰੀ_pos != -1) {
		tcc_debug_check_forw(s1, e, ਆਖਰੀ_pos);
		write32le(dwarf_info_section->ਅੰਕੜੇ + ਆਖਰੀ_pos,
			  debug_type - dwarf_info.ਸ਼ੁਰੂ);
	    }
            ਰੋਕੋ;
	}
        t = t->type.ref;
    }
    ਵਾਪਸ retval;
}

ਸਥਿਰ ਖਾਲੀ tcc_debug_ਅੰਤ (TCCState *s1, ਬਣਤਰ _debug_info *cur)
{
    ਜਦੋਂ (cur) {
        ਬਣਤਰ _debug_info *ਅਗਲਾ = cur->ਅਗਲਾ;
        ਪੂਰਨ i;

        ਜੇ (s1->dwarf) {

            ਲਈ (i = cur->n_sym - 1; i >= 0; i--) {
                ਬਣਤਰ debug_sym *s = &cur->sym[i];

		dwarf_data1(dwarf_info_section,
                            s->type == N_PSYM
			    ? DWARF_ABBREV_FORMAL_PARAMETER
			    : s->type == N_GSYM
                            ? DWARF_ABBREV_VARIABLE_EXTERNAL
                            : s->type == N_STSYM
			    ? DWARF_ABBREV_VARIABLE_STATIC
			    : DWARF_ABBREV_VARIABLE_LOCAL);
                dwarf_strp(dwarf_info_section, s->str);
		ਜੇ (s->type == N_GSYM || s->type == N_STSYM) {
                    dwarf_uleb128(dwarf_info_section, s->file);
                    dwarf_uleb128(dwarf_info_section, s->ਸਤਰ);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.ਸ਼ੁਰੂ);
		ਜੇ (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    ਜੇ (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_ਮਾਪ + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    ਜੇ (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_ਅੰਕੜੇ_PTR);
#ਜੇ PTR_ਮਾਪ == 4
                    dwarf_data4(dwarf_info_section, s->ਮੁੱਲ);
#ਨਹੀਂਤਾਂ
                    dwarf_data8(dwarf_info_section, s->ਮੁੱਲ);
#ਜੇ_ਅੰਤ
		}
		ਨਹੀਂਤਾਂ {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_ਮਾਪ((ਲੰਮਾ)s->ਮੁੱਲ) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (ਲੰਮਾ)s->ਮੁੱਲ);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->ਬੱਚਾ ? DWARF_ABBREV_LEXICAL_ਖੰਡ
			           : DWARF_ABBREV_LEXICAL_ਖਾਲੀ_ਥਾਵਾਂ_ਖੰਡ);
            dwarf_reloc(dwarf_info_section, section_sym, R_ਅੰਕੜੇ_PTR);
#ਜੇ PTR_ਮਾਪ == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->ਸ਼ੁਰੂ);
            dwarf_data4(dwarf_info_section, cur->ਸਿਰਾ - cur->ਸ਼ੁਰੂ);
#ਨਹੀਂਤਾਂ
            dwarf_data8(dwarf_info_section, func_ind + cur->ਸ਼ੁਰੂ);
            dwarf_data8(dwarf_info_section, cur->ਸਿਰਾ - cur->ਸ਼ੁਰੂ);
#ਜੇ_ਅੰਤ
            tcc_debug_ਅੰਤ (s1, cur->ਬੱਚਾ);
	    ਜੇ (cur->ਬੱਚਾ)
                dwarf_data1(dwarf_info_section, 0);
        }
        ਨਹੀਂਤਾਂ
        {
            ਲਈ (i = 0; i < cur->n_sym; i++) {
                ਬਣਤਰ debug_sym *s = &cur->sym[i];

                ਜੇ (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->ਮੁੱਲ,
                                s->sec, s->sym_ਸੂਚਕਾਂਕ);
                ਨਹੀਂਤਾਂ
                    put_stabs(s1, s->str, s->type, 0, 0, s->ਮੁੱਲ);
                tcc_free (s->str);
            }
            tcc_free (cur->sym);
            put_stabn(s1, N_LBRAC, 0, 0, cur->ਸ਼ੁਰੂ);
            tcc_debug_ਅੰਤ (s1, cur->ਬੱਚਾ);
            put_stabn(s1, N_RBRAC, 0, 0, cur->ਸਿਰਾ);
        }
        tcc_free (cur);
        cur = ਅਗਲਾ;
    }
}

ST_FUNC ਖਾਲੀ tcc_ਜੋੜੋ_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    ਪੂਰਨ param;

    ਜੇ (!(s1->do_debug & 2))
        ਵਾਪਸ;

    cstr_new (&debug_str);
    param = !e;
    ਲਈ (; s != e; s = s->prev) {
        ਜੇ (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            ਜਾਰੀ;
	ਜੇ (s1->dwarf) {
	    tcc_debug_stabs(s1, get_tok_str(s->v, ਨਿਰਾ),
			    param ? N_PSYM : N_LSYM, s->c, ਨਿਰਾ, 0,
			    tcc_get_dwarf_info(s1, s));
	}
	ਨਹੀਂਤਾਂ
        {
            cstr_reset (&debug_str);
            cstr_printf (&debug_str, "%s:%s", get_tok_str(s->v, ਨਿਰਾ),
			 param ? "p" : "");
            tcc_get_debug_info(s1, s, &debug_str);
            tcc_debug_stabs(s1, debug_str.ਅੰਕੜੇ, param ? N_PSYM : N_LSYM,
			    s->c, ਨਿਰਾ, 0, 0);
	}
    }
    cstr_free (&debug_str);
}

/* put function symbol */
ST_FUNC ਖਾਲੀ tcc_debug_funcstart(TCCState *s1, Sym *sym)
{
    CString debug_str;
    BufferedFile *f;

    ਜੇ (!s1->do_debug)
        ਵਾਪਸ;
    debug_info_ਜੜ੍ਹ = ਨਿਰਾ;
    debug_info = ਨਿਰਾ;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    ਜੇ (!f)
	ਵਾਪਸ;

    ਜੇ (s1->dwarf) {
        tcc_debug_ਸਤਰ(s1);
        dwarf_info.func = sym;
        dwarf_info.ਸਤਰ = file->ਸਤਰ_ਅੰਕ;
	ਜੇ (s1->do_backtrace) {
	    ਪੂਰਨ i, len;

	    dwarf_ਸਤਰ_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, ਲੜੀ_ਲੰਬਾਈ(funcname) + 2);
	    dwarf_ਸਤਰ_op(s1, DW_LNE_hi_user - 1);
	    len = ਲੜੀ_ਲੰਬਾਈ(funcname) + 1;
	    ਲਈ (i = 0; i < len; i++)
		dwarf_ਸਤਰ_op(s1, funcname[i]);
	}
    }
    ਨਹੀਂਤਾਂ
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.ਅੰਕੜੇ, N_FUN, 0, f->ਸਤਰ_ਅੰਕ, 0, cur_ਪਾਠ_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_ਸਤਰ(s1);
    }
}

ST_FUNC ਖਾਲੀ tcc_debug_prolog_epilog(TCCState *s1, ਪੂਰਨ ਮੁੱਲ)
{
    ਜੇ (!s1->do_debug)
        ਵਾਪਸ;
    ਜੇ (s1->dwarf) {
	dwarf_ਸਤਰ_op(s1, ਮੁੱਲ == 0 ? DW_LNS_ਸੈੱਟ_prologue_ਸਿਰਾ
				     : DW_LNS_ਸੈੱਟ_epilogue_begin);
    }
}

/* put function size */
ST_FUNC ਖਾਲੀ tcc_debug_funcend(TCCState *s1, ਪੂਰਨ ਮਾਪ)
{
    /* lldb does not like function end and next function start at same pc */
    ਪੂਰਨ min_instr_len;

#ਜੇ TCC_EH_ਚੌਖਟਾ
    tcc_debug_ਚੌਖਟਾ_ਸਿਰਾ(s1, ਮਾਪ);
#ਜੇ_ਅੰਤ
    ਜੇ (!s1->do_debug)
        ਵਾਪਸ;
    min_instr_len = dwarf_ਸਤਰ.ਆਖਰੀ_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_ਸਤਰ(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, ਮਾਪ);
    ਜੇ (s1->dwarf) {
        ਪੂਰਨ func_sib = 0;
	Sym *sym = dwarf_info.func;
	ਪੂਰਨ n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        ਜੇ ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_ਸਤਰ.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.ਸਤਰ);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.ਸ਼ੁਰੂ);
        dwarf_reloc(dwarf_info_section, section_sym, R_ਅੰਕੜੇ_PTR);
#ਜੇ PTR_ਮਾਪ == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, ਮਾਪ); // high_pc
#ਨਹੀਂਤਾਂ
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, ਮਾਪ); // high_pc
#ਜੇ_ਅੰਤ
        func_sib = dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#ਨਹੀਂਤਾਂ
        dwarf_data1(dwarf_info_section, DW_OP_call_ਚੌਖਟਾ_cfa);
#ਜੇ_ਅੰਤ
        tcc_debug_ਅੰਤ (s1, debug_info_ਜੜ੍ਹ);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->ਅੰਕੜੇ + func_sib,
                  dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ - dwarf_info.ਸ਼ੁਰੂ);
    }
    ਨਹੀਂਤਾਂ
    {
        tcc_debug_ਅੰਤ (s1, debug_info_ਜੜ੍ਹ);
    }
    debug_info_ਜੜ੍ਹ = 0;
}


ST_FUNC ਖਾਲੀ tcc_debug_extern_sym(TCCState *s1, Sym *sym, ਪੂਰਨ sh_ਅੰਕ, ਪੂਰਨ sym_bind, ਪੂਰਨ sym_type)
{
    ਜੇ (!(s1->do_debug & 2))
        ਵਾਪਸ;

    ਜੇ (sym_type == STT_FUNC || sym->v >= SYM_ਪਹਿਲਾ_ANOM)
        ਵਾਪਸ;
    ਜੇ (s1->dwarf) {
        ਪੂਰਨ debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, ਨਿਰਾ));
	dwarf_uleb128(dwarf_info_section, dwarf_ਸਤਰ.cur_file);
	dwarf_uleb128(dwarf_info_section, file->ਸਤਰ_ਅੰਕ);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.ਸ਼ੁਰੂ);
	ਜੇ (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_ਮਾਪ + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ,
		R_ਅੰਕੜੇ_PTR, 0);
#ਜੇ PTR_ਮਾਪ == 4
	dwarf_data4(dwarf_info_section, 0);
#ਨਹੀਂਤਾਂ
	dwarf_data8(dwarf_info_section, 0);
#ਜੇ_ਅੰਤ
    }
    ਨਹੀਂਤਾਂ
    {
        Section *s = sh_ਅੰਕ == SHN_COMMON ? common_section
					  : s1->sections[sh_ਅੰਕ];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, ਨਿਰਾ),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        ਜੇ (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.ਅੰਕੜੇ, N_GSYM, 0, ਨਿਰਾ, 0, 0);
        ਨਹੀਂਤਾਂ
            tcc_debug_stabs(s1, str.ਅੰਕੜੇ,
                (sym->type.t & VT_STATIC) && ਅੰਕੜੇ_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC ਖਾਲੀ tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    ਜੇ (!(s1->do_debug & 2))
        ਵਾਪਸ;

    ਜੇ (s1->dwarf) {
	ਪੂਰਨ debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	ਜੇ (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, ਨਿਰਾ));
	    dwarf_uleb128(dwarf_info_section, dwarf_ਸਤਰ.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ਸਤਰ_ਅੰਕ);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->ਅੰਕੜੇ_ਵਿੱਥ);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.ਸ਼ੁਰੂ);
	}
    }
    ਨਹੀਂਤਾਂ
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, ਨਿਰਾ));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.ਅੰਕੜੇ, N_LSYM, 0, ਨਿਰਾ, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC ਖਾਲੀ tcc_tcov_ਖੰਡ_ਸਿਰਾ(TCCState *s1, ਪੂਰਨ ਸਤਰ);

ST_FUNC ਖਾਲੀ tcc_tcov_ਖੰਡ_begin(TCCState *s1)
{
    SValue sv;
    ਖਾਲੀ *ptr;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਆਖਰੀ_ਵਿੱਥ = tcov_ਅੰਕੜੇ.ਵਿੱਥ;

    tcc_tcov_ਖੰਡ_ਸਿਰਾ (tcc_state, 0);
    ਜੇ (s1->test_coverage == 0 || nocode_wanted)
	ਵਾਪਸ;

    ਜੇ (tcov_ਅੰਕੜੇ.ਆਖਰੀ_file_name == 0 ||
	strcmp ((ਅਚਲ ਅੱਖਰ *)(tcov_section->ਅੰਕੜੇ + tcov_ਅੰਕੜੇ.ਆਖਰੀ_file_name),
		file->true_filename) != 0) {
	ਅੱਖਰ wd[1024];
	CString cstr;

	ਜੇ (tcov_ਅੰਕੜੇ.ਆਖਰੀ_func_name)
	    section_ptr_ਜੋੜੋ(tcov_section, 1);
	ਜੇ (tcov_ਅੰਕੜੇ.ਆਖਰੀ_file_name)
	    section_ptr_ਜੋੜੋ(tcov_section, 1);
	tcov_ਅੰਕੜੇ.ਆਖਰੀ_func_name = 0;
	cstr_new (&cstr);
	ਜੇ (file->true_filename[0] == '/') {
	    tcov_ਅੰਕੜੇ.ਆਖਰੀ_file_name = tcov_section->ਅੰਕੜੇ_ਵਿੱਥ;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	ਨਹੀਂਤਾਂ {
	    getcwd (wd, ਆਕਾਰ(wd));
	    tcov_ਅੰਕੜੇ.ਆਖਰੀ_file_name = tcov_section->ਅੰਕੜੇ_ਵਿੱਥ + ਲੜੀ_ਲੰਬਾਈ(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_ਜੋੜੋ(tcov_section, cstr.ਮਾਪ + 1);
	strcpy((ਅੱਖਰ *)ptr, cstr.ਅੰਕੜੇ);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
        normalize_slashes((ਅੱਖਰ *)ptr);
#ਜੇ_ਅੰਤ
	cstr_free (&cstr);
    }
    ਜੇ (tcov_ਅੰਕੜੇ.ਆਖਰੀ_func_name == 0 ||
	strcmp ((ਅਚਲ ਅੱਖਰ *)(tcov_section->ਅੰਕੜੇ + tcov_ਅੰਕੜੇ.ਆਖਰੀ_func_name),
		funcname) != 0) {
	ਮਾਪ_t len;

	ਜੇ (tcov_ਅੰਕੜੇ.ਆਖਰੀ_func_name)
	    section_ptr_ਜੋੜੋ(tcov_section, 1);
	tcov_ਅੰਕੜੇ.ਆਖਰੀ_func_name = tcov_section->ਅੰਕੜੇ_ਵਿੱਥ;
	len = ਲੜੀ_ਲੰਬਾਈ (funcname);
	ptr = section_ptr_ਜੋੜੋ(tcov_section, len + 1);
	strcpy((ਅੱਖਰ *)ptr, funcname);
	section_ptr_ਜੋੜੋ(tcov_section, -tcov_section->ਅੰਕੜੇ_ਵਿੱਥ & 7);
	ptr = section_ptr_ਜੋੜੋ(tcov_section, 8);
	write64le (ptr, file->ਸਤਰ_ਅੰਕ);
    }
    ਜੇ (ind == tcov_ਅੰਕੜੇ.ind && tcov_ਅੰਕੜੇ.ਸਤਰ == file->ਸਤਰ_ਅੰਕ)
        tcov_ਅੰਕੜੇ.ਵਿੱਥ = ਆਖਰੀ_ਵਿੱਥ;
    ਨਹੀਂਤਾਂ {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_ਜੋੜੋ(tcov_section, 16);
        tcov_ਅੰਕੜੇ.ਸਤਰ = file->ਸਤਰ_ਅੰਕ;
        write64le (ptr, (tcov_ਅੰਕੜੇ.ਸਤਰ << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *)ptr - tcov_section->ਅੰਕੜੇ) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_I386 || defined TCC_ਨਿਸ਼ਾਨਾ_X86_64 || \
    defined TCC_ਨਿਸ਼ਾਨਾ_ARM || defined TCC_ਨਿਸ਼ਾਨਾ_ARM64 || \
    defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
        gen_increment_tcov (&sv);
#ਨਹੀਂਤਾਂ
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#ਜੇ_ਅੰਤ
        tcov_ਅੰਕੜੇ.ਵਿੱਥ = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *)ptr - tcov_section->ਅੰਕੜੇ;
        tcov_ਅੰਕੜੇ.ind = ind;
    }
}

ST_FUNC ਖਾਲੀ tcc_tcov_ਖੰਡ_ਸਿਰਾ(TCCState *s1, ਪੂਰਨ ਸਤਰ)
{
    ਜੇ (s1->test_coverage == 0)
	ਵਾਪਸ;
    ਜੇ (ਸਤਰ == -1)
        ਸਤਰ = tcov_ਅੰਕੜੇ.ਸਤਰ;
    ਜੇ (tcov_ਅੰਕੜੇ.ਵਿੱਥ) {
	ਖਾਲੀ *ptr = tcov_section->ਅੰਕੜੇ + tcov_ਅੰਕੜੇ.ਵਿੱਥ;
	ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ nline = ਸਤਰ ? ਸਤਰ : file->ਸਤਰ_ਅੰਕ;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_ਅੰਕੜੇ.ਵਿੱਥ = 0;
    }
}

ST_FUNC ਖਾਲੀ tcc_tcov_check_ਸਤਰ(TCCState *s1, ਪੂਰਨ ਸ਼ੁਰੂ)
{
    ਜੇ (s1->test_coverage == 0)
	ਵਾਪਸ;
    ਜੇ (tcov_ਅੰਕੜੇ.ਸਤਰ != file->ਸਤਰ_ਅੰਕ) {
        ਜੇ ((tcov_ਅੰਕੜੇ.ਸਤਰ + 1) != file->ਸਤਰ_ਅੰਕ) {
	    tcc_tcov_ਖੰਡ_ਸਿਰਾ (s1, -1);
	    ਜੇ (ਸ਼ੁਰੂ)
                tcc_tcov_ਖੰਡ_begin (s1);
	}
	ਨਹੀਂਤਾਂ
	    tcov_ਅੰਕੜੇ.ਸਤਰ = file->ਸਤਰ_ਅੰਕ;
    }
}

ST_FUNC ਖਾਲੀ tcc_tcov_ਸ਼ੁਰੂ(TCCState *s1)
{
    ਜੇ (s1->test_coverage == 0)
	ਵਾਪਸ;
    ਜੇ (!s1->dState)
        s1->dState = tcc_mallocz(ਆਕਾਰ *s1->dState);
    memset (&tcov_ਅੰਕੜੇ, 0, ਆਕਾਰ (tcov_ਅੰਕੜੇ));
    ਜੇ (tcov_section == ਨਿਰਾ) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_ਜੋੜੋ(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC ਖਾਲੀ tcc_tcov_ਸਿਰਾ(TCCState *s1)
{
    ਜੇ (s1->test_coverage == 0)
	ਵਾਪਸ;
    ਜੇ (tcov_ਅੰਕੜੇ.ਆਖਰੀ_func_name)
        section_ptr_ਜੋੜੋ(tcov_section, 1);
    ਜੇ (tcov_ਅੰਕੜੇ.ਆਖਰੀ_file_name)
        section_ptr_ਜੋੜੋ(tcov_section, 1);
}

ST_FUNC ਖਾਲੀ tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_ਅੰਕੜੇ.ind = 0;
}

/* ------------------------------------------------------------------------- */
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ ਆਖਰੀ_ਸਤਰ_ਅੰਕ
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ new_file
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ section_sym
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ debug_ਅਗਲਾ_type
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ debug_hash_global
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ debug_hash_local
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ n_debug_hash_global
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ n_debug_hash_local
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ debug_forw_hash_global
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ debug_forw_hash_local
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ n_debug_forw_hash_global
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ n_debug_forw_hash_local
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ debug_info
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ debug_info_ਜੜ੍ਹ
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ dwarf_sym
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ dwarf_ਸਤਰ
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ dwarf_info
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ dwarf_str
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ dwarf_ਸਤਰ_str
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ tcov_ਅੰਕੜੇ
