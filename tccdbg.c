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

#ಅನ್ತರ್ಭಾವ "tcc.h"

/* stab debug support */

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ರಚನೆ {
  ಪೂರ್ಣಾಂಕ type;
  ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2;
  ಪೂರ್ಣಾಂಕ encoding;
  ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#ಆದರೆ LONG_ಗಾತ್ರ == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#ಇಲ್ಲದಿದ್ದರೆ
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#ಆದರೆ_ಅಂತ್ಯ
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#ಆದರೆ LONG_ಗಾತ್ರ == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#ಇಲ್ಲದಿದ್ದರೆ
    /* use octal instead of -1 so size_t works (-gstabs+ in gcc) */
    {   VT_LLONG | VT_LONG | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t5=r5;0;01777777777777777777777;" },
#ಆದರೆ_ಅಂತ್ಯ
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
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_USING_DOUBLE_FOR_LDOUBLE
    {   VT_DOUBLE | VT_LONG, 8, DW_ATE_float, "long double:t16=r1;8;0;" },
#ಇಲ್ಲದಿದ್ದರೆ
    {   VT_LDOUBLE, 16, DW_ATE_float, "long double:t16=r1;16;0;" },
#ಆದರೆ_ಅಂತ್ಯ
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
#ಆದರೆ LONG_ಗಾತ್ರ == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#ಇಲ್ಲದಿದ್ದರೆ
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#ಆದರೆ_ಅಂತ್ಯ
};

#ವ್ಯಾಖ್ಯಾನಿಸು	N_DEFAULT_DEBUG	(ಗಾತ್ರ (default_debug) / ಗಾತ್ರ (default_debug[0]))

/* dwarf debug */

#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ಸಾಲು_ತಳ				-5
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ಸಾಲು_RANGE			14
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_OPCODE_ತಳ			13

#ಆದರೆ defined TCC_ಗುರಿ_ARM64
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_MIN_INSTR_LEN			4
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_MIN_INSTR_LEN			2
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_MIN_INSTR_LEN			1
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_COMPILE_UNIT		1
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_ತಳ_TYPE			2
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_VARIABLE_EXTERNAL		3
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_VARIABLE_STATIC		4
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_VARIABLE_LOCAL		5
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_FORMAL_PARAMETER		6
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_ಸೂಚಕ			7
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_ARRAY_TYPE			8
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_SUBRANGE_TYPE		9
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_TYPEDEF			10
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_ENUMERATOR_SIGNED		11
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_ENUMERATOR_UNSIGNED	12
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_ENUMERATION_TYPE		13
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_MEMBER			14
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_MEMBER_BF			15
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_STRUCTURE_TYPE		16
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_STRUCTURE_ಖಾಲಿಗಳು_TYPE	17
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_UNION_TYPE			18
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_UNION_ಖಾಲಿಗಳು_TYPE		19
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_SUBPROGRAM_EXTERNAL	20
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_SUBPROGRAM_STATIC		21
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_LEXICAL_ಖಂಡ		22
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_LEXICAL_ಖಾಲಿಗಳು_ಖಂಡ	23
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_SUBROUTINE_TYPE		24
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_SUBROUTINE_ಖಾಲಿಗಳು_TYPE	25
#ವ್ಯಾಖ್ಯಾನಿಸು	DWARF_ABBREV_FORMAL_PARAMETER2		26

/* all entries should have been generated with dwarf_uleb128 except
   has_children. All values are currently below 128 so this currently
   works.  */
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_ಟ್ಯಾಗ್_compile_unit, 1,
          DW_AT_ಉತ್ಪಾದಕ, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_ಸಾಲು_strp,
          DW_AT_comp_dir, DW_FORM_ಸಾಲು_strp,
          DW_AT_ಕೆಳಗಿನ_pc, DW_FORM_addr,
#ಆದರೆ PTR_ಗಾತ್ರ == 4
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data4,
#ಇಲ್ಲದಿದ್ದರೆ
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data8,
#ಆದರೆ_ಅಂತ್ಯ
          DW_AT_stmt_list, DW_FORM_sec_ಸ್ಥಾನಾಂತರ,
          0, 0,
    DWARF_ABBREV_ತಳ_TYPE, DW_ಟ್ಯಾಗ್_ತಳ_type, 0,
          DW_AT_byte_ಗಾತ್ರ, DW_FORM_udata,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_name, DW_FORM_strp,
          0, 0,
    DWARF_ABBREV_VARIABLE_EXTERNAL, DW_ಟ್ಯಾಗ್_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_ಟ್ಯಾಗ್_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_LOCAL, DW_ಟ್ಯಾಗ್_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER, DW_ಟ್ಯಾಗ್_formal_parameter, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_ಸೂಚಕ, DW_ಟ್ಯಾಗ್_ಸೂಚಕ_type, 0,
          DW_AT_byte_ಗಾತ್ರ, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ARRAY_TYPE, DW_ಟ್ಯಾಗ್_array_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBRANGE_TYPE, DW_ಟ್ಯಾಗ್_subrange_type, 0,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ಊರ್ಧ್ವ_bound, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_TYPEDEF, DW_ಟ್ಯಾಗ್_typedef, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_ಟ್ಯಾಗ್_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_ಮೌಲ್ಯ, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_ಟ್ಯಾಗ್_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_ಮೌಲ್ಯ, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_ಟ್ಯಾಗ್_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_ಗಾತ್ರ, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_ಟ್ಯಾಗ್_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ದತ್ತಾಂಶ_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_ಟ್ಯಾಗ್_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ಬಿಟ್_ಗಾತ್ರ, DW_FORM_udata,
          DW_AT_ದತ್ತಾಂಶ_ಬಿಟ್_ಸ್ಥಾನಾಂತರ, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_ಟ್ಯಾಗ್_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_ಗಾತ್ರ, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_ಖಾಲಿಗಳು_TYPE, DW_ಟ್ಯಾಗ್_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_ಗಾತ್ರ, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_ಟ್ಯಾಗ್_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_ಗಾತ್ರ, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_ಖಾಲಿಗಳು_TYPE, DW_ಟ್ಯಾಗ್_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_ಗಾತ್ರ, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_ಟ್ಯಾಗ್_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ಕೆಳಗಿನ_pc, DW_FORM_addr,
#ಆದರೆ PTR_ಗಾತ್ರ == 4
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data4,
#ಇಲ್ಲದಿದ್ದರೆ
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data8,
#ಆದರೆ_ಅಂತ್ಯ
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_ಚೌಕಟ್ಟು_ತಳ, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_ಟ್ಯಾಗ್_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ಕೆಳಗಿನ_pc, DW_FORM_addr,
#ಆದರೆ PTR_ಗಾತ್ರ == 4
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data4,
#ಇಲ್ಲದಿದ್ದರೆ
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data8,
#ಆದರೆ_ಅಂತ್ಯ
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_ಚೌಕಟ್ಟು_ತಳ, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_ಖಂಡ, DW_ಟ್ಯಾಗ್_lexical_ಖಂಡ, 1,
          DW_AT_ಕೆಳಗಿನ_pc, DW_FORM_addr,
#ಆದರೆ PTR_ಗಾತ್ರ == 4
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data4,
#ಇಲ್ಲದಿದ್ದರೆ
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data8,
#ಆದರೆ_ಅಂತ್ಯ
          0, 0,
    DWARF_ABBREV_LEXICAL_ಖಾಲಿಗಳು_ಖಂಡ, DW_ಟ್ಯಾಗ್_lexical_ಖಂಡ, 0,
          DW_AT_ಕೆಳಗಿನ_pc, DW_FORM_addr,
#ಆದರೆ PTR_ಗಾತ್ರ == 4
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data4,
#ಇಲ್ಲದಿದ್ದರೆ
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data8,
#ಆದರೆ_ಅಂತ್ಯ
          0, 0,
    DWARF_ABBREV_SUBROUTINE_TYPE, DW_ಟ್ಯಾಗ್_subroutine_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBROUTINE_ಖಾಲಿಗಳು_TYPE, DW_ಟ್ಯಾಗ್_subroutine_type, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER2, DW_ಟ್ಯಾಗ್_formal_parameter, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
  0
};

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ dwarf_ಸಾಲು_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#ವ್ಯಾಖ್ಯಾನಿಸು N_STR_HASH (251)

ರಚನೆ dwarf_str_hash {
    ಪೂರ್ಣಾಂಕ len;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    ರಚನೆ dwarf_str_hash *ಮುಂದಿನ;
};

ರಚನೆ _tccdbg {

    ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ, new_file;
    ಪೂರ್ಣಾಂಕ section_sym;

    ಪೂರ್ಣಾಂಕ debug_ಮುಂದಿನ_type;

    ರಚನೆ _debug_hash {
        ಪೂರ್ಣಾಂಕ debug_type;
        Sym *type;
    } *debug_hash_global, *debug_hash_local;

    /* store forward structure/unions types */
    ರಚನೆ _debug_forw_hash {
        Sym *type;
        ಪೂರ್ಣಾಂಕ n_debug_type;
        ಪೂರ್ಣಾಂಕ *debug_type;
    } *debug_forw_hash_global, *debug_forw_hash_local;

    ಪೂರ್ಣಾಂಕ n_debug_hash_global;
    ಪೂರ್ಣಾಂಕ n_debug_hash_local;
    ಪೂರ್ಣಾಂಕ n_debug_forw_hash_global;
    ಪೂರ್ಣಾಂಕ n_debug_forw_hash_local;

    ರಚನೆ _debug_info {
        ಪೂರ್ಣಾಂಕ ಆರಂಭ;
        ಪೂರ್ಣಾಂಕ ಕೊನೆ;
        ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_debug_hash;
        ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_debug_forw_hash;
        ಪೂರ್ಣಾಂಕ n_sym;
        ರಚನೆ debug_sym {
            ಪೂರ್ಣಾಂಕ type;
            ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಮೌಲ್ಯ;
            ಅಕ್ಷರ *str;
            Section *sec;
            ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ;
            ಪೂರ್ಣಾಂಕ info;
            ಪೂರ್ಣಾಂಕ file;
            ಪೂರ್ಣಾಂಕ ಸಾಲು;
        } *sym;
        ರಚನೆ _debug_info *ಮಗು, *ಮುಂದಿನ, *ಕೊನೆಯ, *ಪೋಷಕ;
    } *debug_info, *debug_info_ಬೇರು;

    ರಚನೆ {
        ಪೂರ್ಣಾಂಕ info;
        ಪೂರ್ಣಾಂಕ abbrev;
        ಪೂರ್ಣಾಂಕ ಸಾಲು;
        ಪೂರ್ಣಾಂಕ str;
        ಪೂರ್ಣಾಂಕ ಸಾಲು_str;
    } dwarf_sym;

    ರಚನೆ {
        ಪೂರ್ಣಾಂಕ ಆರಂಭ;
        ಪೂರ್ಣಾಂಕ dir_ಗಾತ್ರ;
        ಅಕ್ಷರ **dir_ಕೋಷ್ಟಕ;
        ಪೂರ್ಣಾಂಕ filename_ಗಾತ್ರ;
        ರಚನೆ dwarf_filename_struct {
            ಪೂರ್ಣಾಂಕ dir_ನಮೂದು;
            ಅಕ್ಷರ *name;
        } *filename_ಕೋಷ್ಟಕ;
        ಪೂರ್ಣಾಂಕ ಸಾಲು_ಗಾತ್ರ;
        ಪೂರ್ಣಾಂಕ ಸಾಲು_max_ಗಾತ್ರ;
        ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ಸಾಲು_ದತ್ತಾಂಶ;
        ಪೂರ್ಣಾಂಕ cur_file;
        ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_file;
        ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_pc;
        ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_ಸಾಲು;
    } dwarf_ಸಾಲು;

    ರಚನೆ {
        ಪೂರ್ಣಾಂಕ ಆರಂಭ;
        Sym *func;
        ಪೂರ್ಣಾಂಕ ಸಾಲು;
        ಪೂರ್ಣಾಂಕ ತಳ_type_ಬಳಸಿದ[N_DEFAULT_DEBUG];
    } dwarf_info;

    ರಚನೆ dwarf_str_hash *dwarf_str[N_STR_HASH];
    ರಚನೆ dwarf_str_hash *dwarf_ಸಾಲು_str[N_STR_HASH];

    /* test coverage */
    ರಚನೆ {
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ;
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಕೊನೆಯ_file_name;
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಕೊನೆಯ_func_name;
        ಪೂರ್ಣಾಂಕ ind;
        ಪೂರ್ಣಾಂಕ ಸಾಲು;
    } tcov_ದತ್ತಾಂಶ;
};

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ             s1->dState->ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ
#ವ್ಯಾಖ್ಯಾನಿಸು new_file                  s1->dState->new_file
#ವ್ಯಾಖ್ಯಾನಿಸು section_sym               s1->dState->section_sym
#ವ್ಯಾಖ್ಯಾನಿಸು debug_ಮುಂದಿನ_type           s1->dState->debug_ಮುಂದಿನ_type
#ವ್ಯಾಖ್ಯಾನಿಸು debug_hash_global         s1->dState->debug_hash_global
#ವ್ಯಾಖ್ಯಾನಿಸು debug_hash_local          s1->dState->debug_hash_local
#ವ್ಯಾಖ್ಯಾನಿಸು debug_forw_hash_global    s1->dState->debug_forw_hash_global
#ವ್ಯಾಖ್ಯಾನಿಸು debug_forw_hash_local     s1->dState->debug_forw_hash_local
#ವ್ಯಾಖ್ಯಾನಿಸು n_debug_hash_global       s1->dState->n_debug_hash_global
#ವ್ಯಾಖ್ಯಾನಿಸು n_debug_hash_local        s1->dState->n_debug_hash_local
#ವ್ಯಾಖ್ಯಾನಿಸು n_debug_forw_hash_global  s1->dState->n_debug_forw_hash_global
#ವ್ಯಾಖ್ಯಾನಿಸು n_debug_forw_hash_local   s1->dState->n_debug_forw_hash_local
#ವ್ಯಾಖ್ಯಾನಿಸು debug_info                s1->dState->debug_info
#ವ್ಯಾಖ್ಯಾನಿಸು debug_info_ಬೇರು           s1->dState->debug_info_ಬೇರು
#ವ್ಯಾಖ್ಯಾನಿಸು dwarf_sym                 s1->dState->dwarf_sym
#ವ್ಯಾಖ್ಯಾನಿಸು dwarf_ಸಾಲು                s1->dState->dwarf_ಸಾಲು
#ವ್ಯಾಖ್ಯಾನಿಸು dwarf_info                s1->dState->dwarf_info
#ವ್ಯಾಖ್ಯಾನಿಸು dwarf_str                 s1->dState->dwarf_str
#ವ್ಯಾಖ್ಯಾನಿಸು dwarf_ಸಾಲು_str            s1->dState->dwarf_ಸಾಲು_str
#ವ್ಯಾಖ್ಯಾನಿಸು tcov_ದತ್ತಾಂಶ                 s1->dState->tcov_ದತ್ತಾಂಶ

#ವ್ಯಾಖ್ಯಾನಿಸು	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ put_stabs(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, ಪೂರ್ಣಾಂಕ type, ಪೂರ್ಣಾಂಕ other,
    ಪೂರ್ಣಾಂಕ desc, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಮೌಲ್ಯ);

ST_FUNC ಶೂನ್ಯ tcc_debug_new(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ shf = 0;
    ಆದರೆ (!s1->dState)
        s1->dState = tcc_mallocz(ಗಾತ್ರ *s1->dState);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    ಆದರೆ (s1->do_debug && s1->output_type == TCC_OUTPUT_ಸ್ಮರಣೆ)
        s1->do_backtrace = 1;
    ಆದರೆ (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#ಆದರೆ_ಅಂತ್ಯ

    ಆದರೆ (s1->dwarf) {
	ಪೂರ್ಣಾಂಕ i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ debug[] = {
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
        dwarf_ಸಾಲು_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	ಗಾಗಿ (i = 0; i < ಗಾತ್ರ(debug)/ಗಾತ್ರ(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_ವಿಲೀನ | SHF_ಅಕ್ಷರಸರಣಿಗಳು;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_ಸಾಲು_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	ಆದರೆ (s1->dwarf >= 5) {
            dwarf_ಸಾಲು_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_ಸಾಲು_str_section->sh_entsize = 1;
	    dwarf_ಸಾಲು_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    ಇಲ್ಲದಿದ್ದರೆ
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = ಗಾತ್ರ(Stab_Sym);
        stab_section->sh_addralign = ಗಾತ್ರ ((Stab_Sym*)0)->n_ಮೌಲ್ಯ;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ put_stabs(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, ಪೂರ್ಣಾಂಕ type, ಪೂರ್ಣಾಂಕ other, ಪೂರ್ಣಾಂಕ desc,
                      ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಮೌಲ್ಯ)
{
    Stab_Sym *sym;

    ಚಿಹ್ನೆರಹಿತ ಸ್ಥಾನಾಂತರ;
    ಆದರೆ (type == N_SLINE
        && (ಸ್ಥಾನಾಂತರ = stab_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ)
        && (sym = (Stab_Sym*)(stab_section->ದತ್ತಾಂಶ + ಸ್ಥಾನಾಂತರ) - 1)
        && sym->n_type == type
        && sym->n_ಮೌಲ್ಯ == ಮೌಲ್ಯ) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        ಹಿಂತಿರುಗಿ 0;
    }

    sym = section_ptr_ಕೂಡಿಸು(stab_section, ಗಾತ್ರ(Stab_Sym));
    ಆದರೆ (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } ಇಲ್ಲದಿದ್ದರೆ {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_ಮೌಲ್ಯ = ಮೌಲ್ಯ;
    ಹಿಂತಿರುಗಿ 1;
}

ಸ್ಥಿರ ಶೂನ್ಯ put_stabs_r(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, ಪೂರ್ಣಾಂಕ type, ಪೂರ್ಣಾಂಕ other, ಪೂರ್ಣಾಂಕ desc,
                        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಮೌಲ್ಯ, Section *sec, ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ)
{
    ಆದರೆ (put_stabs(s1, str, type, other, desc, ಮೌಲ್ಯ))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - 4,
                      ಗಾತ್ರ ((Stab_Sym*)0)->n_ಮೌಲ್ಯ == PTR_ಗಾತ್ರ ? R_ದತ್ತಾಂಶ_PTR : R_ದತ್ತಾಂಶ_32,
                      sym_ಸೂಚ್ಯಂಕ);
}

ಸ್ಥಿರ ಶೂನ್ಯ put_stabn(TCCState *s1, ಪೂರ್ಣಾಂಕ type, ಪೂರ್ಣಾಂಕ other, ಪೂರ್ಣಾಂಕ desc, ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ)
{
    put_stabs(s1, ಖಾಲಿ, type, other, desc, ಮೌಲ್ಯ);
}

/* ------------------------------------------------------------------------- */
#ವ್ಯಾಖ್ಯಾನಿಸು	dwarf_data1(s,ದತ್ತಾಂಶ) \
	(*(uint8_t*)section_ptr_ಕೂಡಿಸು((s), 1) = (ದತ್ತಾಂಶ))
#ವ್ಯಾಖ್ಯಾನಿಸು	dwarf_data2(s,ದತ್ತಾಂಶ) \
	write16le(section_ptr_ಕೂಡಿಸು((s), 2), (ದತ್ತಾಂಶ))
#ವ್ಯಾಖ್ಯಾನಿಸು	dwarf_data4(s,ದತ್ತಾಂಶ) \
	write32le(section_ptr_ಕೂಡಿಸು((s), 4), (ದತ್ತಾಂಶ))
#ವ್ಯಾಖ್ಯಾನಿಸು	dwarf_data8(s,ದತ್ತಾಂಶ) \
	write64le(section_ptr_ಕೂಡಿಸು((s), 8), (ದತ್ತಾಂಶ))

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    ಹಿಂತಿರುಗಿ put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_ಅಂಕೆ, ಖಾಲಿ);
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_reloc(Section *s, ಪೂರ್ಣಾಂಕ sym, ಪೂರ್ಣಾಂಕ rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ, rel, sym, 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ free_str(ರಚನೆ dwarf_str_hash **str)
{
    ಪೂರ್ಣಾಂಕ i;

    ಗಾಗಿ (i = 0; i < N_STR_HASH; i++) {
       ಆಗ (str[i]) {
           ರಚನೆ dwarf_str_hash *ಮುಂದಿನ = str[i]->ಮುಂದಿನ;

           tcc_free(str[i]);
           str[i] = ಮುಂದಿನ;
       }
    }
}

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ str_hash(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s)
{
    ಚಿಹ್ನೆರಹಿತ h = 5381;

    ಆಗ (*s)
       h += (*s++ & 0xffu) + h * 31;
    ಹಿಂತಿರುಗಿ h;
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_string(Section *s, Section *dw, ಪೂರ್ಣಾಂಕ sym, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    TCCState *s1 = s->s1;
    ಪೂರ್ಣಾಂಕ len, hash = str_hash(str) % N_STR_HASH;
    ಅಕ್ಷರ *ptr;
    ರಚನೆ dwarf_str_hash *new_hash;
    ರಚನೆ dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_ಸಾಲು_str;

    len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(str) + 1;
    new_hash = dw_hash[hash];
    ಆಗ (new_hash) {
	ಆದರೆ (new_hash->len == len &&
	    !memcmp(str, dw->ದತ್ತಾಂಶ + new_hash->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ, len))
	    ನಿಲ್ಲಿಸು;
	new_hash = new_hash->ಮುಂದಿನ;
    }
    ಆದರೆ (new_hash == ಖಾಲಿ) {
	ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ = dw->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

        new_hash = dw_hash[hash];
        ಆಗ (new_hash) {
	    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ n = new_hash->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ + new_hash->len - len;

	    ಆದರೆ (new_hash->len > len &&
	        !memcmp(str, dw->ದತ್ತಾಂಶ + n, len)) {
		ಸ್ಥಾನಾಂತರ = n;
		ನಿಲ್ಲಿಸು;
	    }
	    new_hash = new_hash->ಮುಂದಿನ;
        }
	ಆದರೆ (new_hash == ಖಾಲಿ) {
	    ptr = section_ptr_ಕೂಡಿಸು(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (ರಚನೆ dwarf_str_hash *)
	    tcc_malloc(ಗಾತ್ರ(ರಚನೆ dwarf_str_hash));
	new_hash->len = len;
	new_hash->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = ಸ್ಥಾನಾಂತರ;
	new_hash->ಮುಂದಿನ = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ, R_ದತ್ತಾಂಶ_32_DW, sym,
                   PTR_ಗಾತ್ರ == 4 ? 0 : new_hash->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
    dwarf_data4(s, PTR_ಗಾತ್ರ == 4 ? new_hash->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ : 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_strp(Section *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_ಸಾಲು_strp(Section *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_ಸಾಲು_str_section, dwarf_sym.ಸಾಲು_str, str);
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_ಸಾಲು_op(TCCState *s1, ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ op)
{
    ಆದರೆ (dwarf_ಸಾಲು.ಸಾಲು_ಗಾತ್ರ >= dwarf_ಸಾಲು.ಸಾಲು_max_ಗಾತ್ರ) {
	dwarf_ಸಾಲು.ಸಾಲು_max_ಗಾತ್ರ += 1024;
	dwarf_ಸಾಲು.ಸಾಲು_ದತ್ತಾಂಶ =
	    (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *)tcc_realloc(dwarf_ಸಾಲು.ಸಾಲು_ದತ್ತಾಂಶ,
					 dwarf_ಸಾಲು.ಸಾಲು_max_ಗಾತ್ರ);
    }
    dwarf_ಸಾಲು.ಸಾಲು_ದತ್ತಾಂಶ[dwarf_ಸಾಲು.ಸಾಲು_ಗಾತ್ರ++] = op;
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_file(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ i, j;
    ಅಕ್ಷರ *filename;
    ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ_ಸ್ಥಾನಾಂತರ = s1->dwarf < 5;

    ಆದರೆ (!strcmp(file->filename, "<command line>")) {
        dwarf_ಸಾಲು.cur_file = 1;
	ಹಿಂತಿರುಗಿ;
    }
    filename = strrchr(file->filename, '/');
    ಆದರೆ (filename == ಖಾಲಿ) {
        ಗಾಗಿ (i = 1; i < dwarf_ಸಾಲು.filename_ಗಾತ್ರ; i++)
            ಆದರೆ (dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[i].dir_ನಮೂದು == 0 &&
		strcmp(dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[i].name,
		       file->filename) == 0) {
		    dwarf_ಸಾಲು.cur_file = i + ಸೂಚ್ಯಂಕ_ಸ್ಥಾನಾಂತರ;
	            ಹಿಂತಿರುಗಿ;
		}
	i = -ಸೂಚ್ಯಂಕ_ಸ್ಥಾನಾಂತರ;
	filename = file->filename;
    }
    ಇಲ್ಲದಿದ್ದರೆ {
	ಅಕ್ಷರ *undo = filename;
	ಅಕ್ಷರ *dir = file->filename;

	*filename++ = '\0';
        ಗಾಗಿ (i = 0; i < dwarf_ಸಾಲು.dir_ಗಾತ್ರ; i++)
	    ಆದರೆ (strcmp(dwarf_ಸಾಲು.dir_ಕೋಷ್ಟಕ[i], dir) == 0) {
		ಗಾಗಿ (j = 1; j < dwarf_ಸಾಲು.filename_ಗಾತ್ರ; j++)
		    ಆದರೆ (dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[j].dir_ನಮೂದು - ಸೂಚ್ಯಂಕ_ಸ್ಥಾನಾಂತರ
			== i &&
			strcmp(dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_ಸಾಲು.cur_file = j + ಸೂಚ್ಯಂಕ_ಸ್ಥಾನಾಂತರ;
			ಹಿಂತಿರುಗಿ;
		    }
		ನಿಲ್ಲಿಸು;
	    }
	ಆದರೆ (i == dwarf_ಸಾಲು.dir_ಗಾತ್ರ) {
	    dwarf_ಸಾಲು.dir_ಗಾತ್ರ++;
	    dwarf_ಸಾಲು.dir_ಕೋಷ್ಟಕ =
                (ಅಕ್ಷರ **) tcc_realloc(dwarf_ಸಾಲು.dir_ಕೋಷ್ಟಕ,
                                      dwarf_ಸಾಲು.dir_ಗಾತ್ರ *
                                      ಗಾತ್ರ (ಅಕ್ಷರ *));
            dwarf_ಸಾಲು.dir_ಕೋಷ್ಟಕ[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ =
        (ರಚನೆ dwarf_filename_struct *)
        tcc_realloc(dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ,
                    (dwarf_ಸಾಲು.filename_ಗಾತ್ರ + 1) *
                    ಗಾತ್ರ (ರಚನೆ dwarf_filename_struct));
    dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[dwarf_ಸಾಲು.filename_ಗಾತ್ರ].dir_ನಮೂದು =
	i + ಸೂಚ್ಯಂಕ_ಸ್ಥಾನಾಂತರ;
    dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[dwarf_ಸಾಲು.filename_ಗಾತ್ರ].name =
        tcc_strdup(filename);
    dwarf_ಸಾಲು.cur_file = dwarf_ಸಾಲು.filename_ಗಾತ್ರ++ + ಸೂಚ್ಯಂಕ_ಸ್ಥಾನಾಂತರ;
    ಹಿಂತಿರುಗಿ;
}

#ಆದರೆ 0
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ dwarf_uleb128_ಗಾತ್ರ (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಮೌಲ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2 =  0;

    ಮಾಡು {
        ಮೌಲ್ಯ >>= 7;
        ಗಾತ್ರ_2++;
    } ಆಗ (ಮೌಲ್ಯ != 0);
    ಹಿಂತಿರುಗಿ ಗಾತ್ರ_2;
}
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ dwarf_sleb128_ಗಾತ್ರ (ದೀರ್ಘ ದೀರ್ಘ ಮೌಲ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2 =  0;
    ದೀರ್ಘ ದೀರ್ಘ ಕೊನೆ = ಮೌಲ್ಯ >> 63;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಕೊನೆಯ = ಕೊನೆ & 0x40;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ byte;

    ಮಾಡು {
        byte = ಮೌಲ್ಯ & 0x7f;
        ಮೌಲ್ಯ >>= 7;
        ಗಾತ್ರ_2++;
    } ಆಗ (ಮೌಲ್ಯ != ಕೊನೆ || (byte & 0x40) != ಕೊನೆಯ);
    ಹಿಂತಿರುಗಿ ಗಾತ್ರ_2;
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_uleb128 (Section *s, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಮೌಲ್ಯ)
{
    ಮಾಡು {
        ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ byte = ಮೌಲ್ಯ & 0x7f;

        ಮೌಲ್ಯ >>= 7;
        dwarf_data1(s, byte | (ಮೌಲ್ಯ ? 0x80 : 0));
    } ಆಗ (ಮೌಲ್ಯ != 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_sleb128 (Section *s, ದೀರ್ಘ ದೀರ್ಘ ಮೌಲ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ಇನ್ನಷ್ಟು;
    ದೀರ್ಘ ದೀರ್ಘ ಕೊನೆ = ಮೌಲ್ಯ >> 63;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಕೊನೆಯ = ಕೊನೆ & 0x40;

    ಮಾಡು {
        ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ byte = ಮೌಲ್ಯ & 0x7f;

        ಮೌಲ್ಯ >>= 7;
	ಇನ್ನಷ್ಟು = ಮೌಲ್ಯ != ಕೊನೆ || (byte & 0x40) != ಕೊನೆಯ;
        dwarf_data1(s, byte | (0x80 * ಇನ್ನಷ್ಟು));
    } ಆಗ (ಇನ್ನಷ್ಟು);
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_uleb128_op (TCCState *s1, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಮೌಲ್ಯ)
{
    ಮಾಡು {
        ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ byte = ಮೌಲ್ಯ & 0x7f;

        ಮೌಲ್ಯ >>= 7;
        dwarf_ಸಾಲು_op(s1, byte | (ಮೌಲ್ಯ ? 0x80 : 0));
    } ಆಗ (ಮೌಲ್ಯ != 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_sleb128_op (TCCState *s1, ದೀರ್ಘ ದೀರ್ಘ ಮೌಲ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ಇನ್ನಷ್ಟು;
    ದೀರ್ಘ ದೀರ್ಘ ಕೊನೆ = ಮೌಲ್ಯ >> 63;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಕೊನೆಯ = ಕೊನೆ & 0x40;

    ಮಾಡು {
        ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ byte = ಮೌಲ್ಯ & 0x7f;

        ಮೌಲ್ಯ >>= 7;
        ಇನ್ನಷ್ಟು = ಮೌಲ್ಯ != ಕೊನೆ || (byte & 0x40) != ಕೊನೆಯ;
        dwarf_ಸಾಲು_op(s1, byte | (0x80 * ಇನ್ನಷ್ಟು));
    } ಆಗ (ಇನ್ನಷ್ಟು);
}

#ಆದರೆ TCC_EH_ಚೌಕಟ್ಟು
ST_FUNC ಶೂನ್ಯ tcc_eh_ಚೌಕಟ್ಟು_ಆರಂಭ(TCCState *s1)
{
    ಆದರೆ (!s1->unwind_tables)
        ಹಿಂತಿರುಗಿ;
    eh_ಚೌಕಟ್ಟು_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_ಆರಂಭ = eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    dwarf_data4(eh_ಚೌಕಟ್ಟು_section, 0); //ಉದ್ದಳತೆ
    dwarf_data4(eh_ಚೌಕಟ್ಟು_section, 0); // CIE ID
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, 1); //ಆವೃತ್ತಿ
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, 'z'); // Augmentation String
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, 'R');
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, 0);
#ಆದರೆ defined TCC_ಗುರಿ_I386
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_ಚೌಕಟ್ಟು_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 8); // return address column
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 1); // Augmentation len
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, FDE_ENCODING);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 4); // r4 (esp)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 4); // ofs 4
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_ಸ್ಥಾನಾಂತರ + 8); // r8 (eip)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 1); // cfa-4
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_X86_64
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_ಚೌಕಟ್ಟು_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 16); // return address column
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 1); // Augmentation len
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, FDE_ENCODING);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 8); // ofs 8
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_ಸ್ಥಾನಾಂತರ + 16); // r16 (rip)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 1); // cfa-8
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM
    /* TODO: arm must be compiled with: -funwind-tables */
    /* arm also uses .ARM.extab and .ARM.exidx sections */
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 2); // code_alignment_factor
    dwarf_sleb128(eh_ಚೌಕಟ್ಟು_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 14); // return address column
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 1); // Augmentation len
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, FDE_ENCODING);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 13); // r13 (sp)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 0); // ofs 0
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_ಚೌಕಟ್ಟು_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 30); // return address column
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 1); // Augmentation len
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, FDE_ENCODING);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 31); // x31 (sp)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 0); // ofs 0
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_RISCV64
    eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ[s1->eh_ಆರಂಭ + 8] = 3; // version = 3
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_ಚೌಕಟ್ಟು_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 1); // return address column
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 1); // Augmentation len
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, FDE_ENCODING);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 2); // r2 (sp)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 0); // ofs 0
#ಆದರೆ_ಅಂತ್ಯ
    ಆಗ ((eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - s1->eh_ಆರಂಭ) & 3)
	dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_nop);
    write32le(eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ + s1->eh_ಆರಂಭ, //ಉದ್ದಳತೆ
	      eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - s1->eh_ಆರಂಭ - 4);
}

ಸ್ಥಿರ ಶೂನ್ಯ tcc_debug_ಚೌಕಟ್ಟು_ಕೊನೆ(TCCState *s1, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2)
{
    ಪೂರ್ಣಾಂಕ eh_section_sym;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ fde_ಆರಂಭ;

    ಆದರೆ (!eh_ಚೌಕಟ್ಟು_section)
	ಹಿಂತಿರುಗಿ;
    eh_section_sym = dwarf_get_section_sym(ಪಠ್ಯ_section);
    fde_ಆರಂಭ = eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    dwarf_data4(eh_ಚೌಕಟ್ಟು_section, 0); //ಉದ್ದಳತೆ
    dwarf_data4(eh_ಚೌಕಟ್ಟು_section,
		fde_ಆರಂಭ - s1->eh_ಆರಂಭ + 4); // CIE Pointer
#ಆದರೆ defined TCC_ಗುರಿ_I386
    dwarf_reloc(eh_ಚೌಕಟ್ಟು_section, eh_section_sym, R_386_PC32);
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_X86_64
    dwarf_reloc(eh_ಚೌಕಟ್ಟು_section, eh_section_sym, R_X86_64_PC32);
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM
    dwarf_reloc(eh_ಚೌಕಟ್ಟು_section, eh_section_sym, R_ARM_REL32);
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
    dwarf_reloc(eh_ಚೌಕಟ್ಟು_section, eh_section_sym, R_AARCH64_PREL32);
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_RISCV64
    dwarf_reloc(eh_ಚೌಕಟ್ಟು_section, eh_section_sym, R_RISCV_32_PCREL);
#ಆದರೆ_ಅಂತ್ಯ
    dwarf_data4(eh_ಚೌಕಟ್ಟು_section, func_ind); // PC Begin
    dwarf_data4(eh_ಚೌಕಟ್ಟು_section, ಗಾತ್ರ_2); // PC Range
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, 0); // Augmentation Length
#ಆದರೆ defined TCC_ಗುರಿ_I386
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa_ಸ್ಥಾನಾಂತರ);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 8);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_ಸ್ಥಾನಾಂತರ + 5); // r5 (ebp)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 2); // cfa-8
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa_ರಿಜಿಸ್ಟರ್);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 5); // r5 (ebp)
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_ಚೌಕಟ್ಟು_section, ಗಾತ್ರ_2 - 5);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_restore + 5); // r5 (ebp)
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 4); // r4 (esp)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 4); // ofs 4
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_X86_64
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa_ಸ್ಥಾನಾಂತರ);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 16);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_ಸ್ಥಾನಾಂತರ + 6); // r6 (rbp)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 2); // cfa-16
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa_ರಿಜಿಸ್ಟರ್);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 6); // r6 (rbp)
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_ಚೌಕಟ್ಟು_section, ಗಾತ್ರ_2 - 5);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 8); // ofs 8
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM
    /* TODO */
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa_ಸ್ಥಾನಾಂತರ);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 8);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_ಸ್ಥಾನಾಂತರ + 14); // r14 (lr)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 1);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_ಸ್ಥಾನಾಂತರ + 11); // r11 (fp)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 2);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_ಚೌಕಟ್ಟು_section, ಗಾತ್ರ_2 / 2 - 5);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa_ರಿಜಿಸ್ಟರ್);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 11); // r11 (fp)
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa_ಸ್ಥಾನಾಂತರ);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 224);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_ಸ್ಥಾನಾಂತರ + 29); // x29 (fp)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 28); // cfa-224
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_ಸ್ಥಾನಾಂತರ + 30); // x30 (lr)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 27); // cfa-216
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa_ಸ್ಥಾನಾಂತರ);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 224 + ((-loc + 15) & ~15));
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_ಚೌಕಟ್ಟು_section, ಗಾತ್ರ_2 / 4 - 5);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_restore + 30); // x30 (lr)
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_restore + 29); // x29 (fp)
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa_ಸ್ಥಾನಾಂತರ);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 0);
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_RISCV64
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa_ಸ್ಥಾನಾಂತರ);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 16); // ofs 16
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_ಸ್ಥಾನಾಂತರ + 1); // r1 (ra, lr)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 2); // cfa-8
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_ಸ್ಥಾನಾಂತರ + 8); // r8 (s0, fp)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 4); // cfa-16
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 8); // r8 (s0, fp)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 0); // ofs 0
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc4);
    ಆಗ (ಗಾತ್ರ_2 >= 4 &&
	   read32le(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + func_ind + ಗಾತ್ರ_2 - 4) != 0x00008067)
	ಗಾತ್ರ_2 -= 4;
    dwarf_data4(eh_ಚೌಕಟ್ಟು_section, ಗಾತ್ರ_2 - 36);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 2); // r2 (r2, sp)
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 16); // ofs 16
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_restore + 1); // r1 (lr)
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_restore + 8); // r8 (s0, fp)
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_def_cfa_ಸ್ಥಾನಾಂತರ);
    dwarf_uleb128(eh_ಚೌಕಟ್ಟು_section, 0); // ofs 0
#ಆದರೆ_ಅಂತ್ಯ
    ಆಗ ((eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - fde_ಆರಂಭ) & 3)
	dwarf_data1(eh_ಚೌಕಟ್ಟು_section, DW_CFA_nop);
    write32le(eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ + fde_ಆರಂಭ, //ಉದ್ದಳತೆ
	      eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - fde_ಆರಂಭ - 4);
}

ST_FUNC ಶೂನ್ಯ tcc_eh_ಚೌಕಟ್ಟು_ಕೊನೆ(TCCState *s1)
{
    ಆದರೆ (!eh_ಚೌಕಟ್ಟು_section)
	ಹಿಂತಿರುಗಿ;
    dwarf_data4(eh_ಚೌಕಟ್ಟು_section, 0);
}

ರಚನೆ eh_ಹುಡುಕು_ಕೋಷ್ಟಕ {
    uint32_t pc_ಸ್ಥಾನಾಂತರ;
    uint32_t fde_ಸ್ಥಾನಾಂತರ;
};

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ವಿಂಗಡಿಸು_eh_ಕೋಷ್ಟಕ(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *a, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *b)
{
    uint32_t pc1 = ((ಸ್ಥಿರಾಂಕ ರಚನೆ eh_ಹುಡುಕು_ಕೋಷ್ಟಕ *)a)->pc_ಸ್ಥಾನಾಂತರ;
    uint32_t pc2 = ((ಸ್ಥಿರಾಂಕ ರಚನೆ eh_ಹುಡುಕು_ಕೋಷ್ಟಕ *)b)->pc_ಸ್ಥಾನಾಂತರ;

    ಹಿಂತಿರುಗಿ pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC ಶೂನ್ಯ tcc_eh_ಚೌಕಟ್ಟು_hdr(TCCState *s1, ಪೂರ್ಣಾಂಕ final)
{
    ಪೂರ್ಣಾಂಕ ಎಣಿಕೆ_3 = 0, ಸ್ಥಾನಾಂತರ;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಎಣಿಕೆ_ಸ್ಥಾನಾಂತರ, tab_ಸ್ಥಾನಾಂತರ;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ln, *ಕೊನೆ;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_cie_ಸ್ಥಾನಾಂತರ = 0xffffffff;

    ಆದರೆ (!eh_ಚೌಕಟ್ಟು_section || !eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ)
	ಹಿಂತಿರುಗಿ;
    ಆದರೆ (final && !eh_ಚೌಕಟ್ಟು_hdr_section)
	ಹಿಂತಿರುಗಿ;
    ಆದರೆ (final == 0)
        eh_ಚೌಕಟ್ಟು_hdr_section =
	    new_section(s1, ".eh_frame_hdr", SHT_PROGBITS, SHF_ALLOC);
    eh_ಚೌಕಟ್ಟು_hdr_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = 0;
    dwarf_data1(eh_ಚೌಕಟ್ಟು_hdr_section, 1); //ಆವೃತ್ತಿ
    // Pointer Encoding Format
    dwarf_data1(eh_ಚೌಕಟ್ಟು_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_pcrel);
    // Count Encoding Format
    dwarf_data1(eh_ಚೌಕಟ್ಟು_hdr_section, DW_EH_PE_udata4 | DW_EH_PE_absptr);
    // Table Encoding Format
    dwarf_data1(eh_ಚೌಕಟ್ಟು_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_datarel);
    ಸ್ಥಾನಾಂತರ = eh_ಚೌಕಟ್ಟು_section->sh_addr -
             eh_ಚೌಕಟ್ಟು_hdr_section->sh_addr -
             eh_ಚೌಕಟ್ಟು_hdr_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    dwarf_data4(eh_ಚೌಕಟ್ಟು_hdr_section, ಸ್ಥಾನಾಂತರ); // eh_frame_ptr
    //ಎಣಿಕೆ
    ಎಣಿಕೆ_ಸ್ಥಾನಾಂತರ = eh_ಚೌಕಟ್ಟು_hdr_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    dwarf_data4(eh_ಚೌಕಟ್ಟು_hdr_section, 0);
    tab_ಸ್ಥಾನಾಂತರ = eh_ಚೌಕಟ್ಟು_hdr_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    ln = eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ;
    ಕೊನೆ = eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ + eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    ಆಗ (ln < ಕೊನೆ) {
	ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *fde = ln, *rd = ln;
	ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ cie_ಸ್ಥಾನಾಂತರ, ಆವೃತ್ತಿ, ಉದ್ದಳತೆ = dwarf_read_4(rd, ಕೊನೆ);
	ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ pc_ಸ್ಥಾನಾಂತರ, fde_ಸ್ಥಾನಾಂತರ;

	ಆದರೆ (ಉದ್ದಳತೆ == 0)
	    ಹೋಗು ಮುಂದಿನ;
        cie_ಸ್ಥಾನಾಂತರ = dwarf_read_4(rd, ಕೊನೆ);
	ಆದರೆ (cie_ಸ್ಥಾನಾಂತರ == 0)
	    ಹೋಗು ಮುಂದಿನ;
	ಆದರೆ (cie_ಸ್ಥಾನಾಂತರ != ಕೊನೆಯ_cie_ಸ್ಥಾನಾಂತರ) {
	    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *cie = rd - cie_ಸ್ಥಾನಾಂತರ + 4;

	    ಆದರೆ (cie < eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ)
		ಹೋಗು ಮುಂದಿನ;
	    ಆವೃತ್ತಿ = dwarf_read_1(cie, ಕೊನೆ);
	    ಆದರೆ ((ಆವೃತ್ತಿ == 1 || ಆವೃತ್ತಿ == 3) &&
	        dwarf_read_1(cie, ಕೊನೆ) == 'z' && // Augmentation String
		dwarf_read_1(cie, ಕೊನೆ) == 'R' &&
		dwarf_read_1(cie, ಕೊನೆ) == 0) {
	        dwarf_read_uleb128(&cie, ಕೊನೆ); // code_alignment_factor
	        dwarf_read_sleb128(&cie, ಕೊನೆ); // data_alignment_factor
		dwarf_read_1(cie, ಕೊನೆ); // return address column
		ಆದರೆ (dwarf_read_uleb128(&cie, ಕೊನೆ) == 1 &&
		    dwarf_read_1(cie, ಕೊನೆ) == FDE_ENCODING) {
		    ಕೊನೆಯ_cie_ಸ್ಥಾನಾಂತರ = cie_ಸ್ಥಾನಾಂತರ;
		}
		ಇಲ್ಲದಿದ್ದರೆ
		    ಹೋಗು ಮುಂದಿನ;
	    }
	    ಇಲ್ಲದಿದ್ದರೆ
		ಹೋಗು ಮುಂದಿನ;
	}
	ಎಣಿಕೆ_3++;
	fde_ಸ್ಥಾನಾಂತರ = eh_ಚೌಕಟ್ಟು_section->sh_addr +
		     (fde - eh_ಚೌಕಟ್ಟು_section->ದತ್ತಾಂಶ) -
		     eh_ಚೌಕಟ್ಟು_hdr_section->sh_addr;
	pc_ಸ್ಥಾನಾಂತರ = dwarf_read_4(rd, ಕೊನೆ) + fde_ಸ್ಥಾನಾಂತರ + 8;
	dwarf_data4(eh_ಚೌಕಟ್ಟು_hdr_section, pc_ಸ್ಥಾನಾಂತರ);
	dwarf_data4(eh_ಚೌಕಟ್ಟು_hdr_section, fde_ಸ್ಥಾನಾಂತರ);
ಮುಂದಿನ:
	ln += ಉದ್ದಳತೆ + 4;
    }
    add32le(eh_ಚೌಕಟ್ಟು_hdr_section->ದತ್ತಾಂಶ + ಎಣಿಕೆ_ಸ್ಥಾನಾಂತರ, ಎಣಿಕೆ_3);
    qsort(eh_ಚೌಕಟ್ಟು_hdr_section->ದತ್ತಾಂಶ + tab_ಸ್ಥಾನಾಂತರ, ಎಣಿಕೆ_3,
	  ಗಾತ್ರ(ರಚನೆ eh_ಹುಡುಕು_ಕೋಷ್ಟಕ), ವಿಂಗಡಿಸು_eh_ಕೋಷ್ಟಕ);
}
#ಆದರೆ_ಅಂತ್ಯ

/* start of translation unit info */
ST_FUNC ಶೂನ್ಯ tcc_debug_ಆರಂಭ(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ i;
    ಅಕ್ಷರ buf[512];
    ಅಕ್ಷರ *filename;

    /* we might currently #include the <command-line> */
    filename = file->prev ? file->prev->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    ಆದರೆ (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            ಪಠ್ಯ_section->sh_ಅಂಕೆ, "$a");

        new_file = ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ = 0;
        debug_ಮುಂದಿನ_type = N_DEFAULT_DEBUG;
        debug_hash_global = ಖಾಲಿ;
        debug_hash_local = ಖಾಲಿ;
        debug_forw_hash_global = ಖಾಲಿ;
        debug_forw_hash_local = ಖಾಲಿ;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, ಗಾತ್ರ(buf));
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
        normalize_slashes(buf);
#ಆದರೆ_ಅಂತ್ಯ

        ಆದರೆ (s1->dwarf) {
            ಪೂರ್ಣಾಂಕ ಆರಂಭ_abbrev;
            ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr;
	    ಅಕ್ಷರ *undo;

            /* dwarf_abbrev */
            ಆರಂಭ_abbrev = dwarf_abbrev_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
            ptr = section_ptr_ಕೂಡಿಸು(dwarf_abbrev_section, ಗಾತ್ರ(dwarf_abbrev_init));
            ಸ್ಮರಣೆ_ನಕಲು(ptr, dwarf_abbrev_init, ಗಾತ್ರ(dwarf_abbrev_init));

            ಆದರೆ (s1->dwarf < 5) {
    	        ಆಗ (*ptr) {
    	            ptr += 3;
    	            ಆಗ (*ptr) {
    	                ಆದರೆ (ptr[1] == DW_FORM_ಸಾಲು_strp)
    		            ptr[1] = DW_FORM_strp;
		        ಆದರೆ (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    ಆದರೆ  (ptr[1] == DW_FORM_sec_ಸ್ಥಾನಾಂತರ)
			         ptr[1] = DW_FORM_data4;
			    /* This code uses only size < 0x80 so these are
			       compatible. */
			    ಆದರೆ  (ptr[1] == DW_FORM_exprloc)
			         ptr[1] = DW_FORM_block1;
			}
    	                ptr += 2;
    	            }
		    ptr += 2;
    	        }
            }

            dwarf_sym.info = dwarf_get_section_sym(dwarf_info_section);
            dwarf_sym.abbrev = dwarf_get_section_sym(dwarf_abbrev_section);
            dwarf_sym.ಸಾಲು = dwarf_get_section_sym(dwarf_ಸಾಲು_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            ಆದರೆ (tcc_state->dwarf >= 5)
    	        dwarf_sym.ಸಾಲು_str = dwarf_get_section_sym(dwarf_ಸಾಲು_str_section);
            ಇಲ್ಲದಿದ್ದರೆ {
    	        dwarf_ಸಾಲು_str_section = dwarf_str_section;
                dwarf_sym.ಸಾಲು_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(ಪಠ್ಯ_section);

            /* dwarf_info */
            dwarf_info.ಆರಂಭ = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
            dwarf_data4(dwarf_info_section, 0); //ಗಾತ್ರ
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            ಆದರೆ (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_ಗಾತ್ರ);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_ದತ್ತಾಂಶ_32_DW);
                dwarf_data4(dwarf_info_section, ಆರಂಭ_abbrev);
            }
            ಇಲ್ಲದಿದ್ದರೆ {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_ದತ್ತಾಂಶ_32_DW);
                dwarf_data4(dwarf_info_section, ಆರಂಭ_abbrev);
                dwarf_data1(dwarf_info_section, PTR_ಗಾತ್ರ);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_ಆವೃತ್ತಿ);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_ಸಾಲು_strp(dwarf_info_section, filename);
            dwarf_ಸಾಲು_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_ದತ್ತಾಂಶ_PTR);
#ಆದರೆ PTR_ಗಾತ್ರ == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#ಇಲ್ಲದಿದ್ದರೆ
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#ಆದರೆ_ಅಂತ್ಯ
            dwarf_reloc(dwarf_info_section, dwarf_sym.ಸಾಲು, R_ದತ್ತಾಂಶ_32_DW);
            dwarf_data4(dwarf_info_section, dwarf_ಸಾಲು_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ); // stmt_list

            /* dwarf_line */
            dwarf_ಸಾಲು.ಆರಂಭ = dwarf_ಸಾಲು_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
            dwarf_data4(dwarf_ಸಾಲು_section, 0); //ಉದ್ದಳತೆ
            dwarf_data2(dwarf_ಸಾಲು_section, s1->dwarf); // version
            ಆದರೆ (s1->dwarf >= 5) {
                dwarf_data1(dwarf_ಸಾಲು_section, PTR_ಗಾತ್ರ); // address size
                dwarf_data1(dwarf_ಸಾಲು_section, 0); // segment selector
            }
            dwarf_data4(dwarf_ಸಾಲು_section, 0); // prologue Length
            dwarf_data1(dwarf_ಸಾಲು_section, DWARF_MIN_INSTR_LEN);
            ಆದರೆ (s1->dwarf >= 4)
                dwarf_data1(dwarf_ಸಾಲು_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_ಸಾಲು_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_ಸಾಲು_section, DWARF_ಸಾಲು_ತಳ);
            dwarf_data1(dwarf_ಸಾಲು_section, DWARF_ಸಾಲು_RANGE);
            dwarf_data1(dwarf_ಸಾಲು_section, DWARF_OPCODE_ತಳ);
            ptr = section_ptr_ಕೂಡಿಸು(dwarf_ಸಾಲು_section, ಗಾತ್ರ(dwarf_ಸಾಲು_opcodes));
            ಸ್ಮರಣೆ_ನಕಲು(ptr, dwarf_ಸಾಲು_opcodes, ಗಾತ್ರ(dwarf_ಸಾಲು_opcodes));
	    undo = strrchr(filename, '/');
	    ಆದರೆ (undo)
		*undo = 0;
            dwarf_ಸಾಲು.dir_ಗಾತ್ರ = 1 + (undo != ಖಾಲಿ);
            dwarf_ಸಾಲು.dir_ಕೋಷ್ಟಕ = (ಅಕ್ಷರ **) tcc_malloc(ಗಾತ್ರ (ಅಕ್ಷರ *) *
							dwarf_ಸಾಲು.dir_ಗಾತ್ರ);
            dwarf_ಸಾಲು.dir_ಕೋಷ್ಟಕ[0] = tcc_strdup(buf);
	    ಆದರೆ (undo)
                dwarf_ಸಾಲು.dir_ಕೋಷ್ಟಕ[1] = tcc_strdup(filename);
            dwarf_ಸಾಲು.filename_ಗಾತ್ರ = 2;
            dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ =
    	        (ರಚನೆ dwarf_filename_struct *)
    	        tcc_malloc(2*ಗಾತ್ರ (ರಚನೆ dwarf_filename_struct));
            dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[0].dir_ನಮೂದು = 0;
	    ಆದರೆ (undo) {
                dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[0].name = tcc_strdup(undo + 1);
                dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[1].dir_ನಮೂದು = 1;
                dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    ಇಲ್ಲದಿದ್ದರೆ {
                dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[0].name = tcc_strdup(filename);
                dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[1].dir_ನಮೂದು = 0;
                dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[1].name = tcc_strdup(filename);
	    }
            dwarf_ಸಾಲು.ಸಾಲು_ಗಾತ್ರ = dwarf_ಸಾಲು.ಸಾಲು_max_ಗಾತ್ರ = 0;
            dwarf_ಸಾಲು.ಸಾಲು_ದತ್ತಾಂಶ = ಖಾಲಿ;
            dwarf_ಸಾಲು.cur_file = 1;
            dwarf_ಸಾಲು.ಕೊನೆಯ_file = 0;
            dwarf_ಸಾಲು.ಕೊನೆಯ_pc = 0;
            dwarf_ಸಾಲು.ಕೊನೆಯ_ಸಾಲು = 1;
            dwarf_ಸಾಲು_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_ಗಾತ್ರ); // extended size
            dwarf_ಸಾಲು_op(s1, DW_LNE_ಗಣ_ವಿಳಾಸ);
            ಗಾಗಿ (i = 0; i < PTR_ಗಾತ್ರ; i++)
    	        dwarf_ಸಾಲು_op(s1, 0);
            memset(&dwarf_info.ತಳ_type_ಬಳಸಿದ, 0, ಗಾತ್ರ(dwarf_info.ತಳ_type_ಬಳಸಿದ));
        }
        ಇಲ್ಲದಿದ್ದರೆ
        {
            /* file info: full path + filename */
            pstrcat(buf, ಗಾತ್ರ(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      ಪಠ್ಯ_section->sh_ಅಂಕೆ, ಖಾಲಿ);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ, ಪಠ್ಯ_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ, ಪಠ್ಯ_section, section_sym);
            ಗಾಗಿ (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ fix_debug_forw_hash(TCCState *s1, ಪೂರ್ಣಾಂಕ global, ಪೂರ್ಣಾಂಕ ಆರಂಭ);

/* put end of translation unit info */
ST_FUNC ಶೂನ್ಯ tcc_debug_ಕೊನೆ(TCCState *s1)
{

    ಆದರೆ (!s1->do_debug || debug_ಮುಂದಿನ_type == 0)
        ಹಿಂತಿರುಗಿ;

    ಆದರೆ (debug_info_ಬೇರು)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    ಆದರೆ (s1->dwarf) {
	ಪೂರ್ಣಾಂಕ i;
	ಪೂರ್ಣಾಂಕ ಆರಂಭ_aranges;
	ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr;
	ಪೂರ್ಣಾಂಕ ಪಠ್ಯ_ಗಾತ್ರ = ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

	/* dwarf_info */
	fix_debug_forw_hash(s1, 0, 0);
	fix_debug_forw_hash(s1, 1, 0);
	dwarf_data1(dwarf_info_section, 0);
	ptr = dwarf_info_section->ದತ್ತಾಂಶ + dwarf_info.ಆರಂಭ;
	write32le(ptr, dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - dwarf_info.ಆರಂಭ - 4);
	write32le(ptr + 25 + (s1->dwarf >= 5) + PTR_ಗಾತ್ರ, ಪಠ್ಯ_ಗಾತ್ರ);

	/* dwarf_aranges */
	ಆರಂಭ_aranges = dwarf_aranges_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	dwarf_data4(dwarf_aranges_section, 0); //ಗಾತ್ರ
	dwarf_data2(dwarf_aranges_section, 2); // version
	dwarf_reloc(dwarf_aranges_section, dwarf_sym.info, R_ದತ್ತಾಂಶ_32_DW);
	dwarf_data4(dwarf_aranges_section, 0); // dwarf_info
#ಆದರೆ PTR_ಗಾತ್ರ == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#ಇಲ್ಲದಿದ್ದರೆ
	dwarf_data1(dwarf_aranges_section, 8); // address size
#ಆದರೆ_ಅಂತ್ಯ
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_ದತ್ತಾಂಶ_PTR);
#ಆದರೆ PTR_ಗಾತ್ರ == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, ಪಠ್ಯ_ಗಾತ್ರ); //ಕೊನೆ
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#ಇಲ್ಲದಿದ್ದರೆ
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, ಪಠ್ಯ_ಗಾತ್ರ); //ಕೊನೆ
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#ಆದರೆ_ಅಂತ್ಯ
	ptr = dwarf_aranges_section->ದತ್ತಾಂಶ + ಆರಂಭ_aranges;
	write32le(ptr, dwarf_aranges_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - ಆರಂಭ_aranges - 4);

	/* dwarf_line */
	ಆದರೆ (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_ಸಾಲು_section, 1); /*ಲಂಬಸಾಲು*/
	    dwarf_uleb128(dwarf_ಸಾಲು_section, DW_LNCT_ಮಾರ್ಗ);
	    dwarf_uleb128(dwarf_ಸಾಲು_section, DW_FORM_ಸಾಲು_strp);
	    dwarf_uleb128(dwarf_ಸಾಲು_section, dwarf_ಸಾಲು.dir_ಗಾತ್ರ);
	    ಗಾಗಿ (i = 0; i < dwarf_ಸಾಲು.dir_ಗಾತ್ರ; i++)
	        dwarf_ಸಾಲು_strp(dwarf_ಸಾಲು_section, dwarf_ಸಾಲು.dir_ಕೋಷ್ಟಕ[i]);
	    dwarf_data1(dwarf_ಸಾಲು_section, 2); /*ಲಂಬಸಾಲು*/
	    dwarf_uleb128(dwarf_ಸಾಲು_section, DW_LNCT_ಮಾರ್ಗ);
	    dwarf_uleb128(dwarf_ಸಾಲು_section, DW_FORM_ಸಾಲು_strp);
	    dwarf_uleb128(dwarf_ಸಾಲು_section, DW_LNCT_directory_ಸೂಚ್ಯಂಕ);
	    dwarf_uleb128(dwarf_ಸಾಲು_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_ಸಾಲು_section, dwarf_ಸಾಲು.filename_ಗಾತ್ರ);
	    ಗಾಗಿ (i = 0; i < dwarf_ಸಾಲು.filename_ಗಾತ್ರ; i++) {
	        dwarf_ಸಾಲು_strp(dwarf_ಸಾಲು_section,
				dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[i].name);
	        dwarf_uleb128(dwarf_ಸಾಲು_section,
			      dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[i].dir_ನಮೂದು);
	    }
	}
	ಇಲ್ಲದಿದ್ದರೆ {
	    ಪೂರ್ಣಾಂಕ len;

	    ಗಾಗಿ (i = 0; i < dwarf_ಸಾಲು.dir_ಗಾತ್ರ; i++) {
	        len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(dwarf_ಸಾಲು.dir_ಕೋಷ್ಟಕ[i]) + 1;
	        ptr = section_ptr_ಕೂಡಿಸು(dwarf_ಸಾಲು_section, len);
	        memmove(ptr, dwarf_ಸಾಲು.dir_ಕೋಷ್ಟಕ[i], len);
	    }
	    dwarf_data1(dwarf_ಸಾಲು_section, 0); /* end dir */
	    ಗಾಗಿ (i = 0; i < dwarf_ಸಾಲು.filename_ಗಾತ್ರ; i++) {
	        len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[i].name) + 1;
	        ptr = section_ptr_ಕೂಡಿಸು(dwarf_ಸಾಲು_section, len);
	        memmove(ptr, dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[i].name, len);
	        dwarf_uleb128(dwarf_ಸಾಲು_section,
			      dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[i].dir_ನಮೂದು);
	        dwarf_uleb128(dwarf_ಸಾಲು_section, 0); /*ಸಮಯ*/
	        dwarf_uleb128(dwarf_ಸಾಲು_section, 0); /*ಗಾತ್ರ*/
	    }
	    dwarf_data1(dwarf_ಸಾಲು_section, 0); /* end file */
	}
	ಗಾಗಿ (i = 0; i < dwarf_ಸಾಲು.dir_ಗಾತ್ರ; i++)
	    tcc_free(dwarf_ಸಾಲು.dir_ಕೋಷ್ಟಕ[i]);
	tcc_free(dwarf_ಸಾಲು.dir_ಕೋಷ್ಟಕ);
	ಗಾಗಿ (i = 0; i < dwarf_ಸಾಲು.filename_ಗಾತ್ರ; i++)
	    tcc_free(dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ[i].name);
	tcc_free(dwarf_ಸಾಲು.filename_ಕೋಷ್ಟಕ);

	dwarf_ಸಾಲು_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_ಸಾಲು_op(s1, DW_LNE_ಕೊನೆ_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_ಸಾಲು_section->ದತ್ತಾಂಶ[dwarf_ಸಾಲು.ಆರಂಭ + 6 + i],
		  dwarf_ಸಾಲು_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - dwarf_ಸಾಲು.ಆರಂಭ - (10 + i));
	section_ptr_ಕೂಡಿಸು(dwarf_ಸಾಲು_section, 3);
	dwarf_reloc(dwarf_ಸಾಲು_section, section_sym, R_ದತ್ತಾಂಶ_PTR);
	ptr = section_ptr_ಕೂಡಿಸು(dwarf_ಸಾಲು_section, dwarf_ಸಾಲು.ಸಾಲು_ಗಾತ್ರ - 3);
	memmove(ptr - 3, dwarf_ಸಾಲು.ಸಾಲು_ದತ್ತಾಂಶ, dwarf_ಸಾಲು.ಸಾಲು_ಗಾತ್ರ);
	tcc_free(dwarf_ಸಾಲು.ಸಾಲು_ದತ್ತಾಂಶ);
	write32le(dwarf_ಸಾಲು_section->ದತ್ತಾಂಶ + dwarf_ಸಾಲು.ಆರಂಭ,
		  dwarf_ಸಾಲು_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - dwarf_ಸಾಲು.ಆರಂಭ - 4);
    }
    ಇಲ್ಲದಿದ್ದರೆ
    {
        put_stabs_r(s1, ಖಾಲಿ, N_SO, 0, 0,
                    ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ, ಪಠ್ಯ_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_ಸಾಲು_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_ಮುಂದಿನ_type = 0;
}

ಸ್ಥಿರ BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    ಆದರೆ (f->filename[0] == ':')
        f = f->prev;
    ಆದರೆ (f && new_file) {
        new_file = ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ = 0;
        ಆದರೆ (s1->dwarf)
            dwarf_file(s1);
        ಇಲ್ಲದಿದ್ದರೆ
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, ಪಠ್ಯ_section, section_sym);
    }
    ಹಿಂತಿರುಗಿ f;
}

/* put alternative filename */
ST_FUNC ಶೂನ್ಯ tcc_debug_newfile(TCCState *s1)
{
    ಆದರೆ (!s1->do_debug)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC ಶೂನ್ಯ tcc_debug_bincl(TCCState *s1)
{
    ಆದರೆ (!s1->do_debug)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (s1->dwarf)
        dwarf_file(s1);
    ಇಲ್ಲದಿದ್ದರೆ
        put_stabs(s1, file->filename, N_BINCL, 0, 0, 0);
    new_file = 1;
}

/* end of #include */
ST_FUNC ಶೂನ್ಯ tcc_debug_eincl(TCCState *s1)
{
    ಆದರೆ (!s1->do_debug)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (s1->dwarf)
        dwarf_file(s1);
    ಇಲ್ಲದಿದ್ದರೆ
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC ಶೂನ್ಯ tcc_debug_ಸಾಲು(TCCState *s1)
{
    BufferedFile *f;

    ಆದರೆ (!s1->do_debug)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (cur_ಪಠ್ಯ_section != ಪಠ್ಯ_section || nocode_wanted)
        ಹಿಂತಿರುಗಿ;
    f = put_new_file(s1);
    ಆದರೆ (!f)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ == f->ಸಾಲು_ಅಂಕೆ)
        ಹಿಂತಿರುಗಿ;
    ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ = f->ಸಾಲು_ಅಂಕೆ;

    ಆದರೆ (s1->dwarf) {
	ಪೂರ್ಣಾಂಕ len_pc = (ind - dwarf_ಸಾಲು.ಕೊನೆಯ_pc) / DWARF_MIN_INSTR_LEN;
	ಪೂರ್ಣಾಂಕ len_ಸಾಲು = f->ಸಾಲು_ಅಂಕೆ - dwarf_ಸಾಲು.ಕೊನೆಯ_ಸಾಲು;
	ಪೂರ್ಣಾಂಕ n = len_pc * DWARF_ಸಾಲು_RANGE + len_ಸಾಲು + DWARF_OPCODE_ತಳ - DWARF_ಸಾಲು_ತಳ;

	ಆದರೆ (dwarf_ಸಾಲು.cur_file != dwarf_ಸಾಲು.ಕೊನೆಯ_file) {
	    dwarf_ಸಾಲು.ಕೊನೆಯ_file = dwarf_ಸಾಲು.cur_file;
	    dwarf_ಸಾಲು_op(s1, DW_LNS_ಗಣ_file);
	    dwarf_uleb128_op(s1, dwarf_ಸಾಲು.cur_file);
	}
	ಆದರೆ (len_pc &&
	    len_ಸಾಲು >= DWARF_ಸಾಲು_ತಳ && len_ಸಾಲು <= (DWARF_OPCODE_ತಳ + DWARF_ಸಾಲು_ತಳ) &&
	    n >= DWARF_OPCODE_ತಳ && n <= 255)
            dwarf_ಸಾಲು_op(s1, n);
	ಇಲ್ಲದಿದ್ದರೆ {
	    ಆದರೆ (len_pc) {
	        n = len_pc * DWARF_ಸಾಲು_RANGE + 0 + DWARF_OPCODE_ತಳ - DWARF_ಸಾಲು_ತಳ;
	        ಆದರೆ (n >= DWARF_OPCODE_ತಳ && n <= 255)
                    dwarf_ಸಾಲು_op(s1, n);
		ಇಲ್ಲದಿದ್ದರೆ {
	            dwarf_ಸಾಲು_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    ಆದರೆ (len_ಸಾಲು) {
	        n = 0 * DWARF_ಸಾಲು_RANGE + len_ಸಾಲು + DWARF_OPCODE_ತಳ - DWARF_ಸಾಲು_ತಳ;
	        ಆದರೆ (len_ಸಾಲು >= DWARF_ಸಾಲು_ತಳ && len_ಸಾಲು <= (DWARF_OPCODE_ತಳ + DWARF_ಸಾಲು_ತಳ) &&
		    n >= DWARF_OPCODE_ತಳ && n <= 255)
	            dwarf_ಸಾಲು_op(s1, n);
		ಇಲ್ಲದಿದ್ದರೆ {
	            dwarf_ಸಾಲು_op(s1, DW_LNS_advance_ಸಾಲು);
		    dwarf_sleb128_op(s1, len_ಸಾಲು);
                    /* advance by nothing */
	            dwarf_ಸಾಲು_op(s1, DWARF_OPCODE_ತಳ - DWARF_ಸಾಲು_ತಳ);
		}
	    }
	}
	dwarf_ಸಾಲು.ಕೊನೆಯ_pc = ind;
	dwarf_ಸಾಲು.ಕೊನೆಯ_ಸಾಲು = f->ಸಾಲು_ಅಂಕೆ;
    }
    ಇಲ್ಲದಿದ್ದರೆ
    {
	ಆದರೆ (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->ಸಾಲು_ಅಂಕೆ, ind - func_ind);
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* from tcc_assemble */
            put_stabs_r(s1, ಖಾಲಿ, N_SLINE, 0, f->ಸಾಲು_ಅಂಕೆ, ind, ಪಠ್ಯ_section, section_sym);
        }
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ tcc_debug_stabs (TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, ಪೂರ್ಣಾಂಕ type, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಮೌಲ್ಯ,
                             Section *sec, ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ, ಪೂರ್ಣಾಂಕ info)
{
    ರಚನೆ debug_sym *s;

    ಆದರೆ (debug_info) {
        debug_info->sym =
            (ರಚನೆ debug_sym *)tcc_realloc (debug_info->sym,
                                             ಗಾತ್ರ(ರಚನೆ debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->ಮೌಲ್ಯ = ಮೌಲ್ಯ;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_ಸೂಚ್ಯಂಕ = sym_ಸೂಚ್ಯಂಕ;
        s->info = info;
        s->file = dwarf_ಸಾಲು.cur_file;
        s->ಸಾಲು = file->ಸಾಲು_ಅಂಕೆ;
    }
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sec)
        put_stabs_r (s1, str, type, 0, 0, ಮೌಲ್ಯ, sec, sym_ಸೂಚ್ಯಂಕ);
    ಇಲ್ಲದಿದ್ದರೆ
        put_stabs (s1, str, type, 0, 0, ಮೌಲ್ಯ);
}

ಸ್ಥಿರ ಶೂನ್ಯ fix_debug_forw_hash(TCCState *s1, ಪೂರ್ಣಾಂಕ global, ಪೂರ್ಣಾಂಕ ಆರಂಭ)
{
    ಆದರೆ (s1->dwarf) {
        ಪೂರ್ಣಾಂಕ i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	ರಚನೆ _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	ಗಾಗಿ (i = ಆರಂಭ; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    ಪೂರ್ಣಾಂಕ pos = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_ಖಾಲಿಗಳು_TYPE
                                             : DWARF_ABBREV_STRUCTURE_ಖಾಲಿಗಳು_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_ಮೊದಲ_ANOM
                       ? "" : get_tok_str(t->v, ಖಾಲಿ));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_ಸಾಲು.cur_file);
            dwarf_uleb128(dwarf_info_section, file->ಸಾಲು_ಅಂಕೆ);
	    ಗಾಗಿ (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->ದತ್ತಾಂಶ +
			  hash[i].debug_type[j],
			  pos - dwarf_info.ಆರಂಭ);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC ಶೂನ್ಯ tcc_debug_stabn(TCCState *s1, ಪೂರ್ಣಾಂಕ type, ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ)
{
    ಆದರೆ (!s1->do_debug)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (type == N_LBRAC) {
        ರಚನೆ _debug_info *info =
            (ರಚನೆ _debug_info *) tcc_mallocz(ಗಾತ್ರ (*info));

        info->ಆರಂಭ = ಮೌಲ್ಯ;
        info->ಕೊನೆಯ_debug_hash = n_debug_hash_local;
        info->ಕೊನೆಯ_debug_forw_hash = n_debug_forw_hash_local;
        info->ಪೋಷಕ = debug_info;
        ಆದರೆ (debug_info) {
            ಆದರೆ (debug_info->ಮಗು) {
                ಆದರೆ (debug_info->ಮಗು->ಕೊನೆಯ)
                    debug_info->ಮಗು->ಕೊನೆಯ->ಮುಂದಿನ = info;
                ಇಲ್ಲದಿದ್ದರೆ
                    debug_info->ಮಗು->ಮುಂದಿನ = info;
                debug_info->ಮಗು->ಕೊನೆಯ = info;
            }
            ಇಲ್ಲದಿದ್ದರೆ
                debug_info->ಮಗು = info;
        }
        ಇಲ್ಲದಿದ್ದರೆ
            debug_info_ಬೇರು = info;
        debug_info = info;
    }
    ಇಲ್ಲದಿದ್ದರೆ {
	fix_debug_forw_hash(s1, 0, debug_info->ಕೊನೆಯ_debug_forw_hash);
        n_debug_hash_local = debug_info->ಕೊನೆಯ_debug_hash;
        n_debug_forw_hash_local = debug_info->ಕೊನೆಯ_debug_forw_hash;
        debug_info->ಕೊನೆ = ಮೌಲ್ಯ;
        debug_info = debug_info->ಪೋಷಕ;
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ check_global(Sym *t)
{
    Sym *g = local_ರಾಶಿ;

    ಆಗ (g) {
	ಆದರೆ (t == g)
	    ಹಿಂತಿರುಗಿ 0;
	g = g->prev;
    }
    ಹಿಂತಿರುಗಿ 1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_debug_ಕಂಡುಹಿಡಿ(TCCState *s1, Sym *t, ಪೂರ್ಣಾಂಕ dwarf)
{
    ಪೂರ್ಣಾಂಕ i , g = check_global(t);
    ಪೂರ್ಣಾಂಕ n_hash, *n_forw_hash;
    ರಚನೆ _debug_hash *hash;
    ರಚನೆ _debug_forw_hash **forw_hash;

    ಆದರೆ ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	ಗಾಗಿ (i = 0; i < *n_forw_hash; i++)
            ಆದರೆ (t == (*forw_hash)[i].type)
		ಹಿಂತಿರುಗಿ 0;
	*forw_hash = (ರಚನೆ _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * ಗಾತ್ರ(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = ಖಾಲಿ;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	ಹಿಂತಿರುಗಿ 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    ಗಾಗಿ (i = 0; i < n_hash; i++)
        ಆದರೆ (t == hash[i].type)
	    ಹಿಂತಿರುಗಿ hash[i].debug_type;
    ಹಿಂತಿರುಗಿ -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_get_dwarf_info(TCCState *s1, Sym *s);

ಸ್ಥಿರ ಶೂನ್ಯ tcc_debug_check_forw(TCCState *s1, Sym *t, ಪೂರ್ಣಾಂಕ debug_type)
{
    ಆದರೆ ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        ಪೂರ್ಣಾಂಕ i, j, g = check_global(t);
        ಪೂರ್ಣಾಂಕ n_forw_hash;
        ರಚನೆ _debug_forw_hash **forw_hash;

	ಗಾಗಿ (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    ಗಾಗಿ (j = 0; j < n_forw_hash; j++)
                ಆದರೆ (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    ಹಿಂತಿರುಗಿ;
                }
	}
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC ಶೂನ್ಯ tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    ಆದರೆ (!(s1->do_debug & 2))
	ಹಿಂತಿರುಗಿ;
    ಆದರೆ (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        ಹಿಂತಿರುಗಿ;
    }
    ಆದರೆ ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        ಪೂರ್ಣಾಂಕ i, j, debug_type, g = check_global(t->ref);
        ಪೂರ್ಣಾಂಕ *n_forw_hash;
        ರಚನೆ _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	ಗಾಗಿ (i = 0; i < *n_forw_hash; i++)
	    ಆದರೆ (t->ref == (*forw_hash)[i].type) {
		ಆದರೆ (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    ಗಾಗಿ (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->ದತ್ತಾಂಶ +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.ಆರಂಭ);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		ಗಾಗಿ (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_debug_ಕೂಡಿಸು(TCCState *s1, Sym *t, ಪೂರ್ಣಾಂಕ dwarf)
{
    ಪೂರ್ಣಾಂಕ ಸ್ಥಾನಾಂತರ = dwarf ? dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ : ++debug_ಮುಂದಿನ_type;
    ಪೂರ್ಣಾಂಕ *n_hash, g = check_global(t);
    ರಚನೆ _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (ರಚನೆ _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * ಗಾತ್ರ(**hash));
    (*hash)[*n_hash].debug_type = ಸ್ಥಾನಾಂತರ;
    (*hash)[(*n_hash)++].type = t;
    ಹಿಂತಿರುಗಿ ಸ್ಥಾನಾಂತರ;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ STRUCT_NODEBUG(Sym *s)
{
    ಹಿಂತಿರುಗಿ
    (s->a.nodebug ||
     ((s->v & ~SYM_ಕ್ಷೇತ್ರ) >= SYM_ಮೊದಲ_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ stabs_struct_ಕಂಡುಹಿಡಿ(TCCState *s1, Sym *t, ಪೂರ್ಣಾಂಕ *p_id)
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
    ಆದರೆ (ಖಾಲಿ == p_id)
        ಹಿಂತಿರುಗಿ s && !s->r && t->c >= 0;
    ಆದರೆ (ಖಾಲಿ == s) {
        /* just use global_stack always */
        s = sym_push2(&global_ರಾಶಿ, SYM_ಕ್ಷೇತ್ರ|0x00DEBBED, 0, ++debug_ಮುಂದಿನ_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    ಆದರೆ (s->r || t->c < 0) /* already defined or still incomplete */
        ಹಿಂತಿರುಗಿ 0;
    s->r = 1;
    ಹಿಂತಿರುಗಿ 1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ remove_type_info(ಪೂರ್ಣಾಂಕ type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        ಆದರೆ ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        ಆದರೆ (!(type & VT_BITFIELD) && (type & VT_STRUCT_ಮುಖವಾಡ) > VT_ENUM)
	    type &= ~VT_STRUCT_ಮುಖವಾಡ;
	ಹಿಂತಿರುಗಿ type;
}

ಸ್ಥಿರ ಶೂನ್ಯ tcc_get_debug_info(TCCState *s1, Sym *s, CString *ಫಲಿತಾಂಶ)
{
    ಪೂರ್ಣಾಂಕ type;
    ಪೂರ್ಣಾಂಕ n = 0;
    ಪೂರ್ಣಾಂಕ debug_type = -1;
    Sym *t = s;
    CString str;

    ಗಾಗಿ (;;) {
        type = remove_type_info (t->type.t);
        ಆದರೆ (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        ಇಲ್ಲದಿದ್ದರೆ
            ನಿಲ್ಲಿಸು;
    }
    ಆದರೆ ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        ಆದರೆ (stabs_struct_ಕಂಡುಹಿಡಿ(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_ಮೊದಲ_ANOM
                         ? "" : get_tok_str(t->v, ಖಾಲಿ),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            ಆಗ (t->ಮುಂದಿನ) {
                ಪೂರ್ಣಾಂಕ pos, ಗಾತ್ರ_2, align;
                t = t->ಮುಂದಿನ;
		ಆದರೆ (STRUCT_NODEBUG(t))
		    ಮುಂದುವರಿ;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_ಕ್ಷೇತ್ರ) >= SYM_ಮೊದಲ_ANOM
                             ? "" : get_tok_str(t->v, ಖಾಲಿ)
                             );
                tcc_get_debug_info (s1, t, &str);
                ಆದರೆ (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + ಬಿಟ್_POS(t->type.t);
                    ಗಾತ್ರ_2 = ಬಿಟ್_ಗಾತ್ರ(t->type.t);
                }
                ಇಲ್ಲದಿದ್ದರೆ {
                    pos = t->c * 8;
                    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, ಗಾತ್ರ_2);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.ದತ್ತಾಂಶ, N_LSYM, 0, ಖಾಲಿ, 0, 0);
            cstr_free (&str);
        }
    }
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        ಆದರೆ (stabs_struct_ಕಂಡುಹಿಡಿ(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_ಮೊದಲ_ANOM
                         ? "" : get_tok_str(t->v, ಖಾಲಿ),
                         debug_type);
            ಆಗ (t->ಮುಂದಿನ) {
                t = t->ಮುಂದಿನ;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_ಕ್ಷೇತ್ರ) >= SYM_ಮೊದಲ_ANOM
                             ? "" : get_tok_str(t->v, ಖಾಲಿ));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (ಪೂರ್ಣಾಂಕ)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.ದತ್ತಾಂಶ, N_LSYM, 0, ಖಾಲಿ, 0, 0);
            cstr_free (&str);
	}
    }
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_ಮುಖವಾಡ;
        ಗಾಗಿ (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            ಆದರೆ (default_debug[debug_type - 1].type == type)
                ನಿಲ್ಲಿಸು;
        ಆದರೆ (debug_type > N_DEFAULT_DEBUG)
            ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (ಖಾಲಿ == ಫಲಿತಾಂಶ) /* from stabs_struct_complete() */
        ಹಿಂತಿರುಗಿ;

    ಆದರೆ (n > 0)
        cstr_printf (ಫಲಿತಾಂಶ, "%d=", ++debug_ಮುಂದಿನ_type);
    t = s;
    ಗಾಗಿ (;;) {
        type = remove_type_info (t->type.t);
        ಆದರೆ (type == VT_PTR)
            cstr_printf (ಫಲಿತಾಂಶ, "%d=*", ++debug_ಮುಂದಿನ_type);
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (type == (VT_PTR | VT_ARRAY))
            cstr_printf (ಫಲಿತಾಂಶ, "%d=ar1;0;%d;",
                         ++debug_ಮುಂದಿನ_type, t->type.ref->c - 1);
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (type == VT_FUNC) {
            cstr_printf (ಫಲಿತಾಂಶ, "%d=f", ++debug_ಮುಂದಿನ_type);
            tcc_get_debug_info (s1, t->type.ref, ಫಲಿತಾಂಶ);
            ಹಿಂತಿರುಗಿ;
        }
        ಇಲ್ಲದಿದ್ದರೆ
            ನಿಲ್ಲಿಸು;
        t = t->type.ref;
    }
    cstr_printf (ಫಲಿತಾಂಶ, "%d", debug_type);
}

ಸ್ಥಿರ ಶೂನ್ಯ stabs_struct_complete(TCCState *s1, CType *t)
{
    ಆದರೆ (stabs_struct_ಕಂಡುಹಿಡಿ(s1, t->ref, ಖಾಲಿ)) {
        Sym s = {0}; s.type = *t;
        tcc_get_debug_info(s1, &s, ಖಾಲಿ);
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_get_dwarf_info(TCCState *s1, Sym *s)
{
    ಪೂರ್ಣಾಂಕ type;
    ಪೂರ್ಣಾಂಕ debug_type = -1;
    Sym *e, *t = s;
    ಪೂರ್ಣಾಂಕ i;
    ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_pos = -1;
    ಪೂರ್ಣಾಂಕ retval;

    ಆದರೆ (new_file)
        put_new_file(s1);
    ಗಾಗಿ (;;) {
        type = remove_type_info (t->type.t);
        ಆದರೆ (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        ಇಲ್ಲದಿದ್ದರೆ
            ನಿಲ್ಲಿಸು;
    }
    ಆದರೆ ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_ಕಂಡುಹಿಡಿ(s1, t, 1);
	ಆದರೆ (debug_type == -1) {
	    ಪೂರ್ಣಾಂಕ pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_ಕೂಡಿಸು(s1, t, 1);
	    e = t;
	    i = 0;
	    ಆಗ (e->ಮುಂದಿನ) {
		e = e->ಮುಂದಿನ;
		ಆದರೆ (STRUCT_NODEBUG(e))
		    ಮುಂದುವರಿ;
		i++;
	    }
	    pos_type = (ಪೂರ್ಣಾಂಕ *) tcc_malloc(i * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->ಮುಂದಿನ ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_ಖಾಲಿಗಳು_TYPE
		        : t->ಮುಂದಿನ ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_ಖಾಲಿಗಳು_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_ಮೊದಲ_ANOM
                       ? "" : get_tok_str(t->v, ಖಾಲಿ));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_ಸಾಲು.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ಸಾಲು_ಅಂಕೆ);
	    ಆದರೆ (t->ಮುಂದಿನ) {
	        pos_sib = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            ಆಗ (e->ಮುಂದಿನ) {
                e = e->ಮುಂದಿನ;
		ಆದರೆ (STRUCT_NODEBUG(e))
		    ಮುಂದುವರಿ;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, ಖಾಲಿ));
		dwarf_uleb128(dwarf_info_section, dwarf_ಸಾಲು.cur_file);
		dwarf_uleb128(dwarf_info_section, file->ಸಾಲು_ಅಂಕೆ);
		pos_type[i++] = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
		dwarf_data4(dwarf_info_section, 0);
                ಆದರೆ (e->type.t & VT_BITFIELD) {
                    ಪೂರ್ಣಾಂಕ pos = e->c * 8 + ಬಿಟ್_POS(e->type.t);
                    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2 = ಬಿಟ್_ಗಾತ್ರ(e->type.t);

		    dwarf_uleb128(dwarf_info_section, ಗಾತ್ರ_2);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		ಇಲ್ಲದಿದ್ದರೆ
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    ಆದರೆ (t->ಮುಂದಿನ) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->ದತ್ತಾಂಶ + pos_sib,
		          dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - dwarf_info.ಆರಂಭ);
	    }
	    e = t;
	    i = 0;
	    ಆಗ (e->ಮುಂದಿನ) {
		e = e->ಮುಂದಿನ;
		ಆದರೆ (STRUCT_NODEBUG(e))
		    ಮುಂದುವರಿ;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->ದತ್ತಾಂಶ + pos_type[i++],
			  type - dwarf_info.ಆರಂಭ);
	    }
	    tcc_free(pos_type);
        }
    }
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_ಕಂಡುಹಿಡಿ(s1, t, 1);
	ಆದರೆ (debug_type == -1) {
	    ಪೂರ್ಣಾಂಕ pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_ಕೂಡಿಸು(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_ಮೊದಲ_ANOM
                       ? "" : get_tok_str(t->v, ಖಾಲಿ));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.ಆರಂಭ);
	    dwarf_uleb128(dwarf_info_section, dwarf_ಸಾಲು.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ಸಾಲು_ಅಂಕೆ);
	    pos_sib = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            ಆಗ (e->ಮುಂದಿನ) {
                e = e->ಮುಂದಿನ;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_ಕ್ಷೇತ್ರ) >= SYM_ಮೊದಲ_ANOM
                           ? "" : get_tok_str(e->v, ಖಾಲಿ));
		ಆದರೆ (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		ಇಲ್ಲದಿದ್ದರೆ
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->ದತ್ತಾಂಶ + pos_sib,
		      dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - dwarf_info.ಆರಂಭ);
	}
    }
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_ಮುಖವಾಡ;
        ಗಾಗಿ (i = 1; i <= N_DEFAULT_DEBUG; i++)
            ಆದರೆ (default_debug[i - 1].type == type)
                ನಿಲ್ಲಿಸು;
        ಆದರೆ (i > N_DEFAULT_DEBUG)
            ಹಿಂತಿರುಗಿ 0;
	debug_type = dwarf_info.ತಳ_type_ಬಳಸಿದ[i - 1];
	ಆದರೆ (debug_type == 0) {
	    ಅಕ್ಷರ name[100];

	    debug_type = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ತಳ_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].ಗಾತ್ರ_2);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, ಗಾತ್ರ name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.ತಳ_type_ಬಳಸಿದ[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = ಖಾಲಿ;
    t = s;
    ಗಾಗಿ (;;) {
        type = remove_type_info (t->type.t);
        ಆದರೆ (type == VT_PTR) {
	    i = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	    ಆದರೆ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ಸೂಚಕ);
	    dwarf_data1(dwarf_info_section, PTR_ಗಾತ್ರ);
	    ಆದರೆ (ಕೊನೆಯ_pos != -1) {
		tcc_debug_check_forw(s1, e, ಕೊನೆಯ_pos);
		write32le(dwarf_info_section->ದತ್ತಾಂಶ + ಕೊನೆಯ_pos,
			  i - dwarf_info.ಆರಂಭ);
	    }
	    ಕೊನೆಯ_pos = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (type == (VT_PTR | VT_ARRAY)) {
	    ಪೂರ್ಣಾಂಕ sib_pos, sub_type;
#ಆದರೆ LONG_ಗಾತ್ರ == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#ಇಲ್ಲದಿದ್ದರೆ
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#ಆದರೆ_ಅಂತ್ಯ

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	    ಆದರೆ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    ಆದರೆ (ಕೊನೆಯ_pos != -1) {
		tcc_debug_check_forw(s1, e, ಕೊನೆಯ_pos);
		write32le(dwarf_info_section->ದತ್ತಾಂಶ + ಕೊನೆಯ_pos,
			  i - dwarf_info.ಆರಂಭ);
	    }
	    ಕೊನೆಯ_pos = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	    dwarf_data4(dwarf_info_section, 0);
	    ಗಾಗಿ (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.ಆರಂಭ);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		ಆದರೆ (type != (VT_PTR | VT_ARRAY))
		    ನಿಲ್ಲಿಸು;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->ದತ್ತಾಂಶ + sib_pos,
		      dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - dwarf_info.ಆರಂಭ);
	}
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (type == VT_FUNC) {
	    ಪೂರ್ಣಾಂಕ sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    ಆದರೆ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->ಮುಂದಿನ ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_ಖಾಲಿಗಳು_TYPE);
	    ಆದರೆ (ಕೊನೆಯ_pos != -1) {
		tcc_debug_check_forw(s1, e, ಕೊನೆಯ_pos);
		write32le(dwarf_info_section->ದತ್ತಾಂಶ + ಕೊನೆಯ_pos,
			  i - dwarf_info.ಆರಂಭ);
	    }
	    ಕೊನೆಯ_pos = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    ಆದರೆ (t->type.ref->ಮುಂದಿನ) {
	        sib_pos = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    ಆಗ (f->ಮುಂದಿನ) {
		f = f->ಮುಂದಿನ;
		i++;
	    }
	    pos_type = (ಪೂರ್ಣಾಂಕ *) tcc_malloc(i * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));
	    f = t->type.ref;
	    i = 0;
	    ಆಗ (f->ಮುಂದಿನ) {
		f = f->ಮುಂದಿನ;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    ಆದರೆ (t->type.ref->ಮುಂದಿನ) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->ದತ್ತಾಂಶ + sib_pos,
		          dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - dwarf_info.ಆರಂಭ);
	    }
	    f = t->type.ref;
	    i = 0;
	    ಆಗ (f->ಮುಂದಿನ) {
		f = f->ಮುಂದಿನ;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->ದತ್ತಾಂಶ + pos_type[i++],
                          type - dwarf_info.ಆರಂಭ);
	    }
	    tcc_free(pos_type);
        }
        ಇಲ್ಲದಿದ್ದರೆ {
	    ಆದರೆ (ಕೊನೆಯ_pos != -1) {
		tcc_debug_check_forw(s1, e, ಕೊನೆಯ_pos);
		write32le(dwarf_info_section->ದತ್ತಾಂಶ + ಕೊನೆಯ_pos,
			  debug_type - dwarf_info.ಆರಂಭ);
	    }
            ನಿಲ್ಲಿಸು;
	}
        t = t->type.ref;
    }
    ಹಿಂತಿರುಗಿ retval;
}

ಸ್ಥಿರ ಶೂನ್ಯ tcc_debug_ಮುಕ್ತಾಯ (TCCState *s1, ರಚನೆ _debug_info *cur)
{
    ಆಗ (cur) {
        ರಚನೆ _debug_info *ಮುಂದಿನ = cur->ಮುಂದಿನ;
        ಪೂರ್ಣಾಂಕ i;

        ಆದರೆ (s1->dwarf) {

            ಗಾಗಿ (i = cur->n_sym - 1; i >= 0; i--) {
                ರಚನೆ debug_sym *s = &cur->sym[i];

		dwarf_data1(dwarf_info_section,
                            s->type == N_PSYM
			    ? DWARF_ABBREV_FORMAL_PARAMETER
			    : s->type == N_GSYM
                            ? DWARF_ABBREV_VARIABLE_EXTERNAL
                            : s->type == N_STSYM
			    ? DWARF_ABBREV_VARIABLE_STATIC
			    : DWARF_ABBREV_VARIABLE_LOCAL);
                dwarf_strp(dwarf_info_section, s->str);
		ಆದರೆ (s->type == N_GSYM || s->type == N_STSYM) {
                    dwarf_uleb128(dwarf_info_section, s->file);
                    dwarf_uleb128(dwarf_info_section, s->ಸಾಲು);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.ಆರಂಭ);
		ಆದರೆ (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    ಆದರೆ (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_ಗಾತ್ರ + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    ಆದರೆ (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_ದತ್ತಾಂಶ_PTR);
#ಆದರೆ PTR_ಗಾತ್ರ == 4
                    dwarf_data4(dwarf_info_section, s->ಮೌಲ್ಯ);
#ಇಲ್ಲದಿದ್ದರೆ
                    dwarf_data8(dwarf_info_section, s->ಮೌಲ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ
		}
		ಇಲ್ಲದಿದ್ದರೆ {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_ಗಾತ್ರ((ದೀರ್ಘ)s->ಮೌಲ್ಯ) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (ದೀರ್ಘ)s->ಮೌಲ್ಯ);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->ಮಗು ? DWARF_ABBREV_LEXICAL_ಖಂಡ
			           : DWARF_ABBREV_LEXICAL_ಖಾಲಿಗಳು_ಖಂಡ);
            dwarf_reloc(dwarf_info_section, section_sym, R_ದತ್ತಾಂಶ_PTR);
#ಆದರೆ PTR_ಗಾತ್ರ == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->ಆರಂಭ);
            dwarf_data4(dwarf_info_section, cur->ಕೊನೆ - cur->ಆರಂಭ);
#ಇಲ್ಲದಿದ್ದರೆ
            dwarf_data8(dwarf_info_section, func_ind + cur->ಆರಂಭ);
            dwarf_data8(dwarf_info_section, cur->ಕೊನೆ - cur->ಆರಂಭ);
#ಆದರೆ_ಅಂತ್ಯ
            tcc_debug_ಮುಕ್ತಾಯ (s1, cur->ಮಗು);
	    ಆದರೆ (cur->ಮಗು)
                dwarf_data1(dwarf_info_section, 0);
        }
        ಇಲ್ಲದಿದ್ದರೆ
        {
            ಗಾಗಿ (i = 0; i < cur->n_sym; i++) {
                ರಚನೆ debug_sym *s = &cur->sym[i];

                ಆದರೆ (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->ಮೌಲ್ಯ,
                                s->sec, s->sym_ಸೂಚ್ಯಂಕ);
                ಇಲ್ಲದಿದ್ದರೆ
                    put_stabs(s1, s->str, s->type, 0, 0, s->ಮೌಲ್ಯ);
                tcc_free (s->str);
            }
            tcc_free (cur->sym);
            put_stabn(s1, N_LBRAC, 0, 0, cur->ಆರಂಭ);
            tcc_debug_ಮುಕ್ತಾಯ (s1, cur->ಮಗು);
            put_stabn(s1, N_RBRAC, 0, 0, cur->ಕೊನೆ);
        }
        tcc_free (cur);
        cur = ಮುಂದಿನ;
    }
}

ST_FUNC ಶೂನ್ಯ tcc_ಕೂಡಿಸು_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    ಪೂರ್ಣಾಂಕ param;

    ಆದರೆ (!(s1->do_debug & 2))
        ಹಿಂತಿರುಗಿ;

    cstr_new (&debug_str);
    param = !e;
    ಗಾಗಿ (; s != e; s = s->prev) {
        ಆದರೆ (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            ಮುಂದುವರಿ;
	ಆದರೆ (s1->dwarf) {
	    tcc_debug_stabs(s1, get_tok_str(s->v, ಖಾಲಿ),
			    param ? N_PSYM : N_LSYM, s->c, ಖಾಲಿ, 0,
			    tcc_get_dwarf_info(s1, s));
	}
	ಇಲ್ಲದಿದ್ದರೆ
        {
            cstr_reset (&debug_str);
            cstr_printf (&debug_str, "%s:%s", get_tok_str(s->v, ಖಾಲಿ),
			 param ? "p" : "");
            tcc_get_debug_info(s1, s, &debug_str);
            tcc_debug_stabs(s1, debug_str.ದತ್ತಾಂಶ, param ? N_PSYM : N_LSYM,
			    s->c, ಖಾಲಿ, 0, 0);
	}
    }
    cstr_free (&debug_str);
}

/* put function symbol */
ST_FUNC ಶೂನ್ಯ tcc_debug_funcstart(TCCState *s1, Sym *sym)
{
    CString debug_str;
    BufferedFile *f;

    ಆದರೆ (!s1->do_debug)
        ಹಿಂತಿರುಗಿ;
    debug_info_ಬೇರು = ಖಾಲಿ;
    debug_info = ಖಾಲಿ;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    ಆದರೆ (!f)
	ಹಿಂತಿರುಗಿ;

    ಆದರೆ (s1->dwarf) {
        tcc_debug_ಸಾಲು(s1);
        dwarf_info.func = sym;
        dwarf_info.ಸಾಲು = file->ಸಾಲು_ಅಂಕೆ;
	ಆದರೆ (s1->do_backtrace) {
	    ಪೂರ್ಣಾಂಕ i, len;

	    dwarf_ಸಾಲು_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(funcname) + 2);
	    dwarf_ಸಾಲು_op(s1, DW_LNE_hi_user - 1);
	    len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(funcname) + 1;
	    ಗಾಗಿ (i = 0; i < len; i++)
		dwarf_ಸಾಲು_op(s1, funcname[i]);
	}
    }
    ಇಲ್ಲದಿದ್ದರೆ
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.ದತ್ತಾಂಶ, N_FUN, 0, f->ಸಾಲು_ಅಂಕೆ, 0, cur_ಪಠ್ಯ_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_ಸಾಲು(s1);
    }
}

ST_FUNC ಶೂನ್ಯ tcc_debug_prolog_epilog(TCCState *s1, ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ)
{
    ಆದರೆ (!s1->do_debug)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (s1->dwarf) {
	dwarf_ಸಾಲು_op(s1, ಮೌಲ್ಯ == 0 ? DW_LNS_ಗಣ_prologue_ಕೊನೆ
				     : DW_LNS_ಗಣ_epilogue_begin);
    }
}

/* put function size */
ST_FUNC ಶೂನ್ಯ tcc_debug_funcend(TCCState *s1, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2)
{
    /* lldb does not like function end and next function start at same pc */
    ಪೂರ್ಣಾಂಕ min_instr_len;

#ಆದರೆ TCC_EH_ಚೌಕಟ್ಟು
    tcc_debug_ಚೌಕಟ್ಟು_ಕೊನೆ(s1, ಗಾತ್ರ_2);
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (!s1->do_debug)
        ಹಿಂತಿರುಗಿ;
    min_instr_len = dwarf_ಸಾಲು.ಕೊನೆಯ_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_ಸಾಲು(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, ಗಾತ್ರ_2);
    ಆದರೆ (s1->dwarf) {
        ಪೂರ್ಣಾಂಕ func_sib = 0;
	Sym *sym = dwarf_info.func;
	ಪೂರ್ಣಾಂಕ n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        ಆದರೆ ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_ಸಾಲು.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.ಸಾಲು);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.ಆರಂಭ);
        dwarf_reloc(dwarf_info_section, section_sym, R_ದತ್ತಾಂಶ_PTR);
#ಆದರೆ PTR_ಗಾತ್ರ == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, ಗಾತ್ರ_2); // high_pc
#ಇಲ್ಲದಿದ್ದರೆ
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, ಗಾತ್ರ_2); // high_pc
#ಆದರೆ_ಅಂತ್ಯ
        func_sib = dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#ಆದರೆ defined(TCC_ಗುರಿ_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#ಇಲ್ಲದಿದ್ದರೆ
        dwarf_data1(dwarf_info_section, DW_OP_call_ಚೌಕಟ್ಟು_cfa);
#ಆದರೆ_ಅಂತ್ಯ
        tcc_debug_ಮುಕ್ತಾಯ (s1, debug_info_ಬೇರು);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->ದತ್ತಾಂಶ + func_sib,
                  dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - dwarf_info.ಆರಂಭ);
    }
    ಇಲ್ಲದಿದ್ದರೆ
    {
        tcc_debug_ಮುಕ್ತಾಯ (s1, debug_info_ಬೇರು);
    }
    debug_info_ಬೇರು = 0;
}


ST_FUNC ಶೂನ್ಯ tcc_debug_extern_sym(TCCState *s1, Sym *sym, ಪೂರ್ಣಾಂಕ sh_ಅಂಕೆ, ಪೂರ್ಣಾಂಕ sym_bind, ಪೂರ್ಣಾಂಕ sym_type)
{
    ಆದರೆ (!(s1->do_debug & 2))
        ಹಿಂತಿರುಗಿ;

    ಆದರೆ (sym_type == STT_FUNC || sym->v >= SYM_ಮೊದಲ_ANOM)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (s1->dwarf) {
        ಪೂರ್ಣಾಂಕ debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, ಖಾಲಿ));
	dwarf_uleb128(dwarf_info_section, dwarf_ಸಾಲು.cur_file);
	dwarf_uleb128(dwarf_info_section, file->ಸಾಲು_ಅಂಕೆ);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.ಆರಂಭ);
	ಆದರೆ (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_ಗಾತ್ರ + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ,
		R_ದತ್ತಾಂಶ_PTR, 0);
#ಆದರೆ PTR_ಗಾತ್ರ == 4
	dwarf_data4(dwarf_info_section, 0);
#ಇಲ್ಲದಿದ್ದರೆ
	dwarf_data8(dwarf_info_section, 0);
#ಆದರೆ_ಅಂತ್ಯ
    }
    ಇಲ್ಲದಿದ್ದರೆ
    {
        Section *s = sh_ಅಂಕೆ == SHN_COMMON ? common_section
					  : s1->sections[sh_ಅಂಕೆ];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, ಖಾಲಿ),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        ಆದರೆ (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.ದತ್ತಾಂಶ, N_GSYM, 0, ಖಾಲಿ, 0, 0);
        ಇಲ್ಲದಿದ್ದರೆ
            tcc_debug_stabs(s1, str.ದತ್ತಾಂಶ,
                (sym->type.t & VT_STATIC) && ದತ್ತಾಂಶ_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC ಶೂನ್ಯ tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    ಆದರೆ (!(s1->do_debug & 2))
        ಹಿಂತಿರುಗಿ;

    ಆದರೆ (s1->dwarf) {
	ಪೂರ್ಣಾಂಕ debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	ಆದರೆ (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, ಖಾಲಿ));
	    dwarf_uleb128(dwarf_info_section, dwarf_ಸಾಲು.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ಸಾಲು_ಅಂಕೆ);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.ಆರಂಭ);
	}
    }
    ಇಲ್ಲದಿದ್ದರೆ
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, ಖಾಲಿ));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.ದತ್ತಾಂಶ, N_LSYM, 0, ಖಾಲಿ, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC ಶೂನ್ಯ tcc_tcov_ಖಂಡ_ಕೊನೆ(TCCState *s1, ಪೂರ್ಣಾಂಕ ಸಾಲು);

ST_FUNC ಶೂನ್ಯ tcc_tcov_ಖಂಡ_begin(TCCState *s1)
{
    SValue sv;
    ಶೂನ್ಯ *ptr;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಕೊನೆಯ_ಸ್ಥಾನಾಂತರ = tcov_ದತ್ತಾಂಶ.ಸ್ಥಾನಾಂತರ;

    tcc_tcov_ಖಂಡ_ಕೊನೆ (tcc_state, 0);
    ಆದರೆ (s1->test_coverage == 0 || nocode_wanted)
	ಹಿಂತಿರುಗಿ;

    ಆದರೆ (tcov_ದತ್ತಾಂಶ.ಕೊನೆಯ_file_name == 0 ||
	strcmp ((ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *)(tcov_section->ದತ್ತಾಂಶ + tcov_ದತ್ತಾಂಶ.ಕೊನೆಯ_file_name),
		file->true_filename) != 0) {
	ಅಕ್ಷರ wd[1024];
	CString cstr;

	ಆದರೆ (tcov_ದತ್ತಾಂಶ.ಕೊನೆಯ_func_name)
	    section_ptr_ಕೂಡಿಸು(tcov_section, 1);
	ಆದರೆ (tcov_ದತ್ತಾಂಶ.ಕೊನೆಯ_file_name)
	    section_ptr_ಕೂಡಿಸು(tcov_section, 1);
	tcov_ದತ್ತಾಂಶ.ಕೊನೆಯ_func_name = 0;
	cstr_new (&cstr);
	ಆದರೆ (file->true_filename[0] == '/') {
	    tcov_ದತ್ತಾಂಶ.ಕೊನೆಯ_file_name = tcov_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	ಇಲ್ಲದಿದ್ದರೆ {
	    getcwd (wd, ಗಾತ್ರ(wd));
	    tcov_ದತ್ತಾಂಶ.ಕೊನೆಯ_file_name = tcov_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ + ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_ಕೂಡಿಸು(tcov_section, cstr.ಗಾತ್ರ_2 + 1);
	strcpy((ಅಕ್ಷರ *)ptr, cstr.ದತ್ತಾಂಶ);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
        normalize_slashes((ಅಕ್ಷರ *)ptr);
#ಆದರೆ_ಅಂತ್ಯ
	cstr_free (&cstr);
    }
    ಆದರೆ (tcov_ದತ್ತಾಂಶ.ಕೊನೆಯ_func_name == 0 ||
	strcmp ((ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *)(tcov_section->ದತ್ತಾಂಶ + tcov_ದತ್ತಾಂಶ.ಕೊನೆಯ_func_name),
		funcname) != 0) {
	ಗಾತ್ರ_t len;

	ಆದರೆ (tcov_ದತ್ತಾಂಶ.ಕೊನೆಯ_func_name)
	    section_ptr_ಕೂಡಿಸು(tcov_section, 1);
	tcov_ದತ್ತಾಂಶ.ಕೊನೆಯ_func_name = tcov_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
	len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ (funcname);
	ptr = section_ptr_ಕೂಡಿಸು(tcov_section, len + 1);
	strcpy((ಅಕ್ಷರ *)ptr, funcname);
	section_ptr_ಕೂಡಿಸು(tcov_section, -tcov_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ & 7);
	ptr = section_ptr_ಕೂಡಿಸು(tcov_section, 8);
	write64le (ptr, file->ಸಾಲು_ಅಂಕೆ);
    }
    ಆದರೆ (ind == tcov_ದತ್ತಾಂಶ.ind && tcov_ದತ್ತಾಂಶ.ಸಾಲು == file->ಸಾಲು_ಅಂಕೆ)
        tcov_ದತ್ತಾಂಶ.ಸ್ಥಾನಾಂತರ = ಕೊನೆಯ_ಸ್ಥಾನಾಂತರ;
    ಇಲ್ಲದಿದ್ದರೆ {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_ಕೂಡಿಸು(tcov_section, 16);
        tcov_ದತ್ತಾಂಶ.ಸಾಲು = file->ಸಾಲು_ಅಂಕೆ;
        write64le (ptr, (tcov_ದತ್ತಾಂಶ.ಸಾಲು << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *)ptr - tcov_section->ದತ್ತಾಂಶ) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#ಆದರೆ defined TCC_ಗುರಿ_I386 || defined TCC_ಗುರಿ_X86_64 || \
    defined TCC_ಗುರಿ_ARM || defined TCC_ಗುರಿ_ARM64 || \
    defined TCC_ಗುರಿ_RISCV64
        gen_increment_tcov (&sv);
#ಇಲ್ಲದಿದ್ದರೆ
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#ಆದರೆ_ಅಂತ್ಯ
        tcov_ದತ್ತಾಂಶ.ಸ್ಥಾನಾಂತರ = (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *)ptr - tcov_section->ದತ್ತಾಂಶ;
        tcov_ದತ್ತಾಂಶ.ind = ind;
    }
}

ST_FUNC ಶೂನ್ಯ tcc_tcov_ಖಂಡ_ಕೊನೆ(TCCState *s1, ಪೂರ್ಣಾಂಕ ಸಾಲು)
{
    ಆದರೆ (s1->test_coverage == 0)
	ಹಿಂತಿರುಗಿ;
    ಆದರೆ (ಸಾಲು == -1)
        ಸಾಲು = tcov_ದತ್ತಾಂಶ.ಸಾಲು;
    ಆದರೆ (tcov_ದತ್ತಾಂಶ.ಸ್ಥಾನಾಂತರ) {
	ಶೂನ್ಯ *ptr = tcov_section->ದತ್ತಾಂಶ + tcov_ದತ್ತಾಂಶ.ಸ್ಥಾನಾಂತರ;
	ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ nline = ಸಾಲು ? ಸಾಲು : file->ಸಾಲು_ಅಂಕೆ;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_ದತ್ತಾಂಶ.ಸ್ಥಾನಾಂತರ = 0;
    }
}

ST_FUNC ಶೂನ್ಯ tcc_tcov_check_ಸಾಲು(TCCState *s1, ಪೂರ್ಣಾಂಕ ಆರಂಭ)
{
    ಆದರೆ (s1->test_coverage == 0)
	ಹಿಂತಿರುಗಿ;
    ಆದರೆ (tcov_ದತ್ತಾಂಶ.ಸಾಲು != file->ಸಾಲು_ಅಂಕೆ) {
        ಆದರೆ ((tcov_ದತ್ತಾಂಶ.ಸಾಲು + 1) != file->ಸಾಲು_ಅಂಕೆ) {
	    tcc_tcov_ಖಂಡ_ಕೊನೆ (s1, -1);
	    ಆದರೆ (ಆರಂಭ)
                tcc_tcov_ಖಂಡ_begin (s1);
	}
	ಇಲ್ಲದಿದ್ದರೆ
	    tcov_ದತ್ತಾಂಶ.ಸಾಲು = file->ಸಾಲು_ಅಂಕೆ;
    }
}

ST_FUNC ಶೂನ್ಯ tcc_tcov_ಆರಂಭ(TCCState *s1)
{
    ಆದರೆ (s1->test_coverage == 0)
	ಹಿಂತಿರುಗಿ;
    ಆದರೆ (!s1->dState)
        s1->dState = tcc_mallocz(ಗಾತ್ರ *s1->dState);
    memset (&tcov_ದತ್ತಾಂಶ, 0, ಗಾತ್ರ (tcov_ದತ್ತಾಂಶ));
    ಆದರೆ (tcov_section == ಖಾಲಿ) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_ಕೂಡಿಸು(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC ಶೂನ್ಯ tcc_tcov_ಕೊನೆ(TCCState *s1)
{
    ಆದರೆ (s1->test_coverage == 0)
	ಹಿಂತಿರುಗಿ;
    ಆದರೆ (tcov_ದತ್ತಾಂಶ.ಕೊನೆಯ_func_name)
        section_ptr_ಕೂಡಿಸು(tcov_section, 1);
    ಆದರೆ (tcov_ದತ್ತಾಂಶ.ಕೊನೆಯ_file_name)
        section_ptr_ಕೂಡಿಸು(tcov_section, 1);
}

ST_FUNC ಶೂನ್ಯ tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_ದತ್ತಾಂಶ.ind = 0;
}

/* ------------------------------------------------------------------------- */
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು new_file
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು section_sym
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು debug_ಮುಂದಿನ_type
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು debug_hash_global
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು debug_hash_local
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು n_debug_hash_global
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು n_debug_hash_local
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು debug_forw_hash_global
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು debug_forw_hash_local
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು n_debug_forw_hash_global
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು n_debug_forw_hash_local
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು debug_info
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು debug_info_ಬೇರು
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು dwarf_sym
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು dwarf_ಸಾಲು
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು dwarf_info
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು dwarf_str
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು dwarf_ಸಾಲು_str
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು tcov_ದತ್ತಾಂಶ
