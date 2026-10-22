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

#అన్తర్భావ "tcc.h"

/* stab debug support */

స్థిర స్థిరరాశి నిర్మాణం {
  పూర్ణాంకం type;
  పూర్ణాంకం కొలత;
  పూర్ణాంకం encoding;
  స్థిరరాశి అక్షరం *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#ఒకవేళ LONG_కొలత == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#లేకపోతే
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#అయితే_ముగింపు
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#ఒకవేళ LONG_కొలత == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#లేకపోతే
    /* use octal instead of -1 so size_t works (-gstabs+ in gcc) */
    {   VT_LLONG | VT_LONG | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t5=r5;0;01777777777777777777777;" },
#అయితే_ముగింపు
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
#నిర్వచితమైతే TCC_USING_DOUBLE_FOR_LDOUBLE
    {   VT_DOUBLE | VT_LONG, 8, DW_ATE_float, "long double:t16=r1;8;0;" },
#లేకపోతే
    {   VT_LDOUBLE, 16, DW_ATE_float, "long double:t16=r1;16;0;" },
#అయితే_ముగింపు
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
#ఒకవేళ LONG_కొలత == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#లేకపోతే
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#అయితే_ముగింపు
};

#నిర్వచించు	N_DEFAULT_DEBUG	(పరిమాణం (default_debug) / పరిమాణం (default_debug[0]))

/* dwarf debug */

#నిర్వచించు	DWARF_పంక్తి_పునాది				-5
#నిర్వచించు	DWARF_పంక్తి_RANGE			14
#నిర్వచించు	DWARF_OPCODE_పునాది			13

#ఒకవేళ defined TCC_లక్ష్యం_ARM64
#నిర్వచించు	DWARF_MIN_INSTR_LEN			4
#లేదావేళ defined TCC_లక్ష్యం_ARM
#నిర్వచించు	DWARF_MIN_INSTR_LEN			2
#లేకపోతే
#నిర్వచించు	DWARF_MIN_INSTR_LEN			1
#అయితే_ముగింపు

#నిర్వచించు	DWARF_ABBREV_COMPILE_UNIT		1
#నిర్వచించు	DWARF_ABBREV_పునాది_TYPE			2
#నిర్వచించు	DWARF_ABBREV_VARIABLE_EXTERNAL		3
#నిర్వచించు	DWARF_ABBREV_VARIABLE_STATIC		4
#నిర్వచించు	DWARF_ABBREV_VARIABLE_LOCAL		5
#నిర్వచించు	DWARF_ABBREV_FORMAL_PARAMETER		6
#నిర్వచించు	DWARF_ABBREV_సూచిక			7
#నిర్వచించు	DWARF_ABBREV_ARRAY_TYPE			8
#నిర్వచించు	DWARF_ABBREV_SUBRANGE_TYPE		9
#నిర్వచించు	DWARF_ABBREV_TYPEDEF			10
#నిర్వచించు	DWARF_ABBREV_ENUMERATOR_SIGNED		11
#నిర్వచించు	DWARF_ABBREV_ENUMERATOR_UNSIGNED	12
#నిర్వచించు	DWARF_ABBREV_ENUMERATION_TYPE		13
#నిర్వచించు	DWARF_ABBREV_MEMBER			14
#నిర్వచించు	DWARF_ABBREV_MEMBER_BF			15
#నిర్వచించు	DWARF_ABBREV_STRUCTURE_TYPE		16
#నిర్వచించు	DWARF_ABBREV_STRUCTURE_ఖాళీలు_TYPE	17
#నిర్వచించు	DWARF_ABBREV_UNION_TYPE			18
#నిర్వచించు	DWARF_ABBREV_UNION_ఖాళీలు_TYPE		19
#నిర్వచించు	DWARF_ABBREV_SUBPROGRAM_EXTERNAL	20
#నిర్వచించు	DWARF_ABBREV_SUBPROGRAM_STATIC		21
#నిర్వచించు	DWARF_ABBREV_LEXICAL_ఖండం		22
#నిర్వచించు	DWARF_ABBREV_LEXICAL_ఖాళీలు_ఖండం	23
#నిర్వచించు	DWARF_ABBREV_SUBROUTINE_TYPE		24
#నిర్వచించు	DWARF_ABBREV_SUBROUTINE_ఖాళీలు_TYPE	25
#నిర్వచించు	DWARF_ABBREV_FORMAL_PARAMETER2		26

/* all entries should have been generated with dwarf_uleb128 except
   has_children. All values are currently below 128 so this currently
   works.  */
స్థిర స్థిరరాశి గుర్తులేని అక్షరం dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_ట్యాగ్_compile_unit, 1,
          DW_AT_ఉత్పాదకుడు, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_పంక్తి_strp,
          DW_AT_comp_dir, DW_FORM_పంక్తి_strp,
          DW_AT_దిగువ_pc, DW_FORM_addr,
#ఒకవేళ PTR_కొలత == 4
          DW_AT_ఎగువ_pc, DW_FORM_data4,
#లేకపోతే
          DW_AT_ఎగువ_pc, DW_FORM_data8,
#అయితే_ముగింపు
          DW_AT_stmt_list, DW_FORM_sec_స్థానభ్రంశం,
          0, 0,
    DWARF_ABBREV_పునాది_TYPE, DW_ట్యాగ్_పునాది_type, 0,
          DW_AT_byte_కొలత, DW_FORM_udata,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_name, DW_FORM_strp,
          0, 0,
    DWARF_ABBREV_VARIABLE_EXTERNAL, DW_ట్యాగ్_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_పంక్తి, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_ట్యాగ్_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_పంక్తి, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_LOCAL, DW_ట్యాగ్_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER, DW_ట్యాగ్_formal_parameter, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_సూచిక, DW_ట్యాగ్_సూచిక_type, 0,
          DW_AT_byte_కొలత, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ARRAY_TYPE, DW_ట్యాగ్_array_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBRANGE_TYPE, DW_ట్యాగ్_subrange_type, 0,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_పై_bound, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_TYPEDEF, DW_ట్యాగ్_typedef, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_పంక్తి, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_ట్యాగ్_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_విలువ, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_ట్యాగ్_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_విలువ, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_ట్యాగ్_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_కొలత, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_పంక్తి, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_ట్యాగ్_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_పంక్తి, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_దత్తాంశం_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_ట్యాగ్_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_పంక్తి, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_బిట్టు_కొలత, DW_FORM_udata,
          DW_AT_దత్తాంశం_బిట్టు_స్థానభ్రంశం, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_ట్యాగ్_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_కొలత, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_పంక్తి, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_ఖాళీలు_TYPE, DW_ట్యాగ్_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_కొలత, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_పంక్తి, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_ట్యాగ్_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_కొలత, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_పంక్తి, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_ఖాళీలు_TYPE, DW_ట్యాగ్_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_కొలత, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_పంక్తి, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_ట్యాగ్_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_పంక్తి, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_దిగువ_pc, DW_FORM_addr,
#ఒకవేళ PTR_కొలత == 4
          DW_AT_ఎగువ_pc, DW_FORM_data4,
#లేకపోతే
          DW_AT_ఎగువ_pc, DW_FORM_data8,
#అయితే_ముగింపు
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_చట్రం_పునాది, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_ట్యాగ్_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_పంక్తి, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_దిగువ_pc, DW_FORM_addr,
#ఒకవేళ PTR_కొలత == 4
          DW_AT_ఎగువ_pc, DW_FORM_data4,
#లేకపోతే
          DW_AT_ఎగువ_pc, DW_FORM_data8,
#అయితే_ముగింపు
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_చట్రం_పునాది, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_ఖండం, DW_ట్యాగ్_lexical_ఖండం, 1,
          DW_AT_దిగువ_pc, DW_FORM_addr,
#ఒకవేళ PTR_కొలత == 4
          DW_AT_ఎగువ_pc, DW_FORM_data4,
#లేకపోతే
          DW_AT_ఎగువ_pc, DW_FORM_data8,
#అయితే_ముగింపు
          0, 0,
    DWARF_ABBREV_LEXICAL_ఖాళీలు_ఖండం, DW_ట్యాగ్_lexical_ఖండం, 0,
          DW_AT_దిగువ_pc, DW_FORM_addr,
#ఒకవేళ PTR_కొలత == 4
          DW_AT_ఎగువ_pc, DW_FORM_data4,
#లేకపోతే
          DW_AT_ఎగువ_pc, DW_FORM_data8,
#అయితే_ముగింపు
          0, 0,
    DWARF_ABBREV_SUBROUTINE_TYPE, DW_ట్యాగ్_subroutine_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBROUTINE_ఖాళీలు_TYPE, DW_ట్యాగ్_subroutine_type, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER2, DW_ట్యాగ్_formal_parameter, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
  0
};

స్థిర స్థిరరాశి గుర్తులేని అక్షరం dwarf_పంక్తి_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#నిర్వచించు N_STR_HASH (251)

నిర్మాణం dwarf_str_hash {
    పూర్ణాంకం len;
    గుర్తులేని దీర్ఘ దత్తాంశం_స్థానభ్రంశం;
    నిర్మాణం dwarf_str_hash *తదుపరి;
};

నిర్మాణం _tccdbg {

    పూర్ణాంకం చివరి_పంక్తి_అంకె, new_file;
    పూర్ణాంకం section_sym;

    పూర్ణాంకం debug_తదుపరి_type;

    నిర్మాణం _debug_hash {
        పూర్ణాంకం debug_type;
        Sym *type;
    } *debug_hash_global, *debug_hash_local;

    /* store forward structure/unions types */
    నిర్మాణం _debug_forw_hash {
        Sym *type;
        పూర్ణాంకం n_debug_type;
        పూర్ణాంకం *debug_type;
    } *debug_forw_hash_global, *debug_forw_hash_local;

    పూర్ణాంకం n_debug_hash_global;
    పూర్ణాంకం n_debug_hash_local;
    పూర్ణాంకం n_debug_forw_hash_global;
    పూర్ణాంకం n_debug_forw_hash_local;

    నిర్మాణం _debug_info {
        పూర్ణాంకం ప్రారంభం;
        పూర్ణాంకం చివర;
        పూర్ణాంకం చివరి_debug_hash;
        పూర్ణాంకం చివరి_debug_forw_hash;
        పూర్ణాంకం n_sym;
        నిర్మాణం debug_sym {
            పూర్ణాంకం type;
            గుర్తులేని దీర్ఘ విలువ;
            అక్షరం *str;
            Section *sec;
            పూర్ణాంకం sym_సూచీ;
            పూర్ణాంకం info;
            పూర్ణాంకం file;
            పూర్ణాంకం పంక్తి;
        } *sym;
        నిర్మాణం _debug_info *బిడ్డ, *తదుపరి, *చివరి, *మాతృ;
    } *debug_info, *debug_info_మూలం;

    నిర్మాణం {
        పూర్ణాంకం info;
        పూర్ణాంకం abbrev;
        పూర్ణాంకం పంక్తి;
        పూర్ణాంకం str;
        పూర్ణాంకం పంక్తి_str;
    } dwarf_sym;

    నిర్మాణం {
        పూర్ణాంకం ప్రారంభం;
        పూర్ణాంకం dir_కొలత;
        అక్షరం **dir_పట్టిక;
        పూర్ణాంకం filename_కొలత;
        నిర్మాణం dwarf_filename_struct {
            పూర్ణాంకం dir_నమోదు;
            అక్షరం *name;
        } *filename_పట్టిక;
        పూర్ణాంకం పంక్తి_కొలత;
        పూర్ణాంకం పంక్తి_max_కొలత;
        గుర్తులేని అక్షరం *పంక్తి_దత్తాంశం;
        పూర్ణాంకం cur_file;
        పూర్ణాంకం చివరి_file;
        పూర్ణాంకం చివరి_pc;
        పూర్ణాంకం చివరి_పంక్తి;
    } dwarf_పంక్తి;

    నిర్మాణం {
        పూర్ణాంకం ప్రారంభం;
        Sym *func;
        పూర్ణాంకం పంక్తి;
        పూర్ణాంకం పునాది_type_వాడిన[N_DEFAULT_DEBUG];
    } dwarf_info;

    నిర్మాణం dwarf_str_hash *dwarf_str[N_STR_HASH];
    నిర్మాణం dwarf_str_hash *dwarf_పంక్తి_str[N_STR_HASH];

    /* test coverage */
    నిర్మాణం {
        గుర్తులేని దీర్ఘ స్థానభ్రంశం;
        గుర్తులేని దీర్ఘ చివరి_file_name;
        గుర్తులేని దీర్ఘ చివరి_func_name;
        పూర్ణాంకం ind;
        పూర్ణాంకం పంక్తి;
    } tcov_దత్తాంశం;
};

#నిర్వచించు చివరి_పంక్తి_అంకె             s1->dState->చివరి_పంక్తి_అంకె
#నిర్వచించు new_file                  s1->dState->new_file
#నిర్వచించు section_sym               s1->dState->section_sym
#నిర్వచించు debug_తదుపరి_type           s1->dState->debug_తదుపరి_type
#నిర్వచించు debug_hash_global         s1->dState->debug_hash_global
#నిర్వచించు debug_hash_local          s1->dState->debug_hash_local
#నిర్వచించు debug_forw_hash_global    s1->dState->debug_forw_hash_global
#నిర్వచించు debug_forw_hash_local     s1->dState->debug_forw_hash_local
#నిర్వచించు n_debug_hash_global       s1->dState->n_debug_hash_global
#నిర్వచించు n_debug_hash_local        s1->dState->n_debug_hash_local
#నిర్వచించు n_debug_forw_hash_global  s1->dState->n_debug_forw_hash_global
#నిర్వచించు n_debug_forw_hash_local   s1->dState->n_debug_forw_hash_local
#నిర్వచించు debug_info                s1->dState->debug_info
#నిర్వచించు debug_info_మూలం           s1->dState->debug_info_మూలం
#నిర్వచించు dwarf_sym                 s1->dState->dwarf_sym
#నిర్వచించు dwarf_పంక్తి                s1->dState->dwarf_పంక్తి
#నిర్వచించు dwarf_info                s1->dState->dwarf_info
#నిర్వచించు dwarf_str                 s1->dState->dwarf_str
#నిర్వచించు dwarf_పంక్తి_str            s1->dState->dwarf_పంక్తి_str
#నిర్వచించు tcov_దత్తాంశం                 s1->dState->tcov_దత్తాంశం

#నిర్వచించు	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
స్థిర పూర్ణాంకం put_stabs(TCCState *s1, స్థిరరాశి అక్షరం *str, పూర్ణాంకం type, పూర్ణాంకం other,
    పూర్ణాంకం desc, గుర్తులేని దీర్ఘ విలువ);

ST_FUNC శూన్య tcc_debug_new(TCCState *s1)
{
    పూర్ణాంకం shf = 0;
    ఒకవేళ (!s1->dState)
        s1->dState = tcc_mallocz(పరిమాణం *s1->dState);

#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    ఒకవేళ (s1->do_debug && s1->output_type == TCC_OUTPUT_జ్ఞాపకం)
        s1->do_backtrace = 1;
    ఒకవేళ (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#అయితే_ముగింపు

    ఒకవేళ (s1->dwarf) {
	పూర్ణాంకం i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	స్థిర స్థిరరాశి అక్షరం *స్థిరరాశి debug[] = {
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
        dwarf_పంక్తి_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	కొరకు (i = 0; i < పరిమాణం(debug)/పరిమాణం(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_విలీనం | SHF_అక్షరశ్రేణులు;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_పంక్తి_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	ఒకవేళ (s1->dwarf >= 5) {
            dwarf_పంక్తి_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_పంక్తి_str_section->sh_entsize = 1;
	    dwarf_పంక్తి_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    లేకపోతే
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = పరిమాణం(Stab_Sym);
        stab_section->sh_addralign = పరిమాణం ((Stab_Sym*)0)->n_విలువ;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
స్థిర పూర్ణాంకం put_stabs(TCCState *s1, స్థిరరాశి అక్షరం *str, పూర్ణాంకం type, పూర్ణాంకం other, పూర్ణాంకం desc,
                      గుర్తులేని దీర్ఘ విలువ)
{
    Stab_Sym *sym;

    గుర్తులేని స్థానభ్రంశం;
    ఒకవేళ (type == N_SLINE
        && (స్థానభ్రంశం = stab_section->దత్తాంశం_స్థానభ్రంశం)
        && (sym = (Stab_Sym*)(stab_section->దత్తాంశం + స్థానభ్రంశం) - 1)
        && sym->n_type == type
        && sym->n_విలువ == విలువ) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        తిరిగి 0;
    }

    sym = section_ptr_కూడు(stab_section, పరిమాణం(Stab_Sym));
    ఒకవేళ (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } లేకపోతే {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_విలువ = విలువ;
    తిరిగి 1;
}

స్థిర శూన్య put_stabs_r(TCCState *s1, స్థిరరాశి అక్షరం *str, పూర్ణాంకం type, పూర్ణాంకం other, పూర్ణాంకం desc,
                        గుర్తులేని దీర్ఘ విలువ, Section *sec, పూర్ణాంకం sym_సూచీ)
{
    ఒకవేళ (put_stabs(s1, str, type, other, desc, విలువ))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->దత్తాంశం_స్థానభ్రంశం - 4,
                      పరిమాణం ((Stab_Sym*)0)->n_విలువ == PTR_కొలత ? R_దత్తాంశం_PTR : R_దత్తాంశం_32,
                      sym_సూచీ);
}

స్థిర శూన్య put_stabn(TCCState *s1, పూర్ణాంకం type, పూర్ణాంకం other, పూర్ణాంకం desc, పూర్ణాంకం విలువ)
{
    put_stabs(s1, ఖాళీ, type, other, desc, విలువ);
}

/* ------------------------------------------------------------------------- */
#నిర్వచించు	dwarf_data1(s,దత్తాంశం) \
	(*(uint8_t*)section_ptr_కూడు((s), 1) = (దత్తాంశం))
#నిర్వచించు	dwarf_data2(s,దత్తాంశం) \
	write16le(section_ptr_కూడు((s), 2), (దత్తాంశం))
#నిర్వచించు	dwarf_data4(s,దత్తాంశం) \
	write32le(section_ptr_కూడు((s), 4), (దత్తాంశం))
#నిర్వచించు	dwarf_data8(s,దత్తాంశం) \
	write64le(section_ptr_కూడు((s), 8), (దత్తాంశం))

స్థిర పూర్ణాంకం dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    తిరిగి put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_అంకె, ఖాళీ);
}

స్థిర శూన్య dwarf_reloc(Section *s, పూర్ణాంకం sym, పూర్ణాంకం rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->దత్తాంశం_స్థానభ్రంశం, rel, sym, 0);
}

స్థిర శూన్య free_str(నిర్మాణం dwarf_str_hash **str)
{
    పూర్ణాంకం i;

    కొరకు (i = 0; i < N_STR_HASH; i++) {
       అయితే (str[i]) {
           నిర్మాణం dwarf_str_hash *తదుపరి = str[i]->తదుపరి;

           tcc_free(str[i]);
           str[i] = తదుపరి;
       }
    }
}

స్థిర గుర్తులేని str_hash(స్థిరరాశి అక్షరం *s)
{
    గుర్తులేని h = 5381;

    అయితే (*s)
       h += (*s++ & 0xffu) + h * 31;
    తిరిగి h;
}

స్థిర శూన్య dwarf_string(Section *s, Section *dw, పూర్ణాంకం sym, స్థిరరాశి అక్షరం *str)
{
    TCCState *s1 = s->s1;
    పూర్ణాంకం len, hash = str_hash(str) % N_STR_HASH;
    అక్షరం *ptr;
    నిర్మాణం dwarf_str_hash *new_hash;
    నిర్మాణం dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_పంక్తి_str;

    len = అక్షరశ్రేణి_పొడవు(str) + 1;
    new_hash = dw_hash[hash];
    అయితే (new_hash) {
	ఒకవేళ (new_hash->len == len &&
	    !memcmp(str, dw->దత్తాంశం + new_hash->దత్తాంశం_స్థానభ్రంశం, len))
	    ఆపు;
	new_hash = new_hash->తదుపరి;
    }
    ఒకవేళ (new_hash == ఖాళీ) {
	గుర్తులేని దీర్ఘ స్థానభ్రంశం = dw->దత్తాంశం_స్థానభ్రంశం;

        new_hash = dw_hash[hash];
        అయితే (new_hash) {
	    గుర్తులేని దీర్ఘ n = new_hash->దత్తాంశం_స్థానభ్రంశం + new_hash->len - len;

	    ఒకవేళ (new_hash->len > len &&
	        !memcmp(str, dw->దత్తాంశం + n, len)) {
		స్థానభ్రంశం = n;
		ఆపు;
	    }
	    new_hash = new_hash->తదుపరి;
        }
	ఒకవేళ (new_hash == ఖాళీ) {
	    ptr = section_ptr_కూడు(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (నిర్మాణం dwarf_str_hash *)
	    tcc_malloc(పరిమాణం(నిర్మాణం dwarf_str_hash));
	new_hash->len = len;
	new_hash->దత్తాంశం_స్థానభ్రంశం = స్థానభ్రంశం;
	new_hash->తదుపరి = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->దత్తాంశం_స్థానభ్రంశం, R_దత్తాంశం_32_DW, sym,
                   PTR_కొలత == 4 ? 0 : new_hash->దత్తాంశం_స్థానభ్రంశం);
    dwarf_data4(s, PTR_కొలత == 4 ? new_hash->దత్తాంశం_స్థానభ్రంశం : 0);
}

స్థిర శూన్య dwarf_strp(Section *s, స్థిరరాశి అక్షరం *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

స్థిర శూన్య dwarf_పంక్తి_strp(Section *s, స్థిరరాశి అక్షరం *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_పంక్తి_str_section, dwarf_sym.పంక్తి_str, str);
}

స్థిర శూన్య dwarf_పంక్తి_op(TCCState *s1, గుర్తులేని అక్షరం op)
{
    ఒకవేళ (dwarf_పంక్తి.పంక్తి_కొలత >= dwarf_పంక్తి.పంక్తి_max_కొలత) {
	dwarf_పంక్తి.పంక్తి_max_కొలత += 1024;
	dwarf_పంక్తి.పంక్తి_దత్తాంశం =
	    (గుర్తులేని అక్షరం *)tcc_realloc(dwarf_పంక్తి.పంక్తి_దత్తాంశం,
					 dwarf_పంక్తి.పంక్తి_max_కొలత);
    }
    dwarf_పంక్తి.పంక్తి_దత్తాంశం[dwarf_పంక్తి.పంక్తి_కొలత++] = op;
}

స్థిర శూన్య dwarf_file(TCCState *s1)
{
    పూర్ణాంకం i, j;
    అక్షరం *filename;
    పూర్ణాంకం సూచీ_స్థానభ్రంశం = s1->dwarf < 5;

    ఒకవేళ (!strcmp(file->filename, "<command line>")) {
        dwarf_పంక్తి.cur_file = 1;
	తిరిగి;
    }
    filename = strrchr(file->filename, '/');
    ఒకవేళ (filename == ఖాళీ) {
        కొరకు (i = 1; i < dwarf_పంక్తి.filename_కొలత; i++)
            ఒకవేళ (dwarf_పంక్తి.filename_పట్టిక[i].dir_నమోదు == 0 &&
		strcmp(dwarf_పంక్తి.filename_పట్టిక[i].name,
		       file->filename) == 0) {
		    dwarf_పంక్తి.cur_file = i + సూచీ_స్థానభ్రంశం;
	            తిరిగి;
		}
	i = -సూచీ_స్థానభ్రంశం;
	filename = file->filename;
    }
    లేకపోతే {
	అక్షరం *undo = filename;
	అక్షరం *dir = file->filename;

	*filename++ = '\0';
        కొరకు (i = 0; i < dwarf_పంక్తి.dir_కొలత; i++)
	    ఒకవేళ (strcmp(dwarf_పంక్తి.dir_పట్టిక[i], dir) == 0) {
		కొరకు (j = 1; j < dwarf_పంక్తి.filename_కొలత; j++)
		    ఒకవేళ (dwarf_పంక్తి.filename_పట్టిక[j].dir_నమోదు - సూచీ_స్థానభ్రంశం
			== i &&
			strcmp(dwarf_పంక్తి.filename_పట్టిక[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_పంక్తి.cur_file = j + సూచీ_స్థానభ్రంశం;
			తిరిగి;
		    }
		ఆపు;
	    }
	ఒకవేళ (i == dwarf_పంక్తి.dir_కొలత) {
	    dwarf_పంక్తి.dir_కొలత++;
	    dwarf_పంక్తి.dir_పట్టిక =
                (అక్షరం **) tcc_realloc(dwarf_పంక్తి.dir_పట్టిక,
                                      dwarf_పంక్తి.dir_కొలత *
                                      పరిమాణం (అక్షరం *));
            dwarf_పంక్తి.dir_పట్టిక[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_పంక్తి.filename_పట్టిక =
        (నిర్మాణం dwarf_filename_struct *)
        tcc_realloc(dwarf_పంక్తి.filename_పట్టిక,
                    (dwarf_పంక్తి.filename_కొలత + 1) *
                    పరిమాణం (నిర్మాణం dwarf_filename_struct));
    dwarf_పంక్తి.filename_పట్టిక[dwarf_పంక్తి.filename_కొలత].dir_నమోదు =
	i + సూచీ_స్థానభ్రంశం;
    dwarf_పంక్తి.filename_పట్టిక[dwarf_పంక్తి.filename_కొలత].name =
        tcc_strdup(filename);
    dwarf_పంక్తి.cur_file = dwarf_పంక్తి.filename_కొలత++ + సూచీ_స్థానభ్రంశం;
    తిరిగి;
}

#ఒకవేళ 0
స్థిర పూర్ణాంకం dwarf_uleb128_కొలత (గుర్తులేని దీర్ఘ దీర్ఘ విలువ)
{
    పూర్ణాంకం కొలత =  0;

    చేయి {
        విలువ >>= 7;
        కొలత++;
    } అయితే (విలువ != 0);
    తిరిగి కొలత;
}
#అయితే_ముగింపు

స్థిర పూర్ణాంకం dwarf_sleb128_కొలత (దీర్ఘ దీర్ఘ విలువ)
{
    పూర్ణాంకం కొలత =  0;
    దీర్ఘ దీర్ఘ చివర = విలువ >> 63;
    గుర్తులేని అక్షరం చివరి = చివర & 0x40;
    గుర్తులేని అక్షరం byte;

    చేయి {
        byte = విలువ & 0x7f;
        విలువ >>= 7;
        కొలత++;
    } అయితే (విలువ != చివర || (byte & 0x40) != చివరి);
    తిరిగి కొలత;
}

స్థిర శూన్య dwarf_uleb128 (Section *s, గుర్తులేని దీర్ఘ దీర్ఘ విలువ)
{
    చేయి {
        గుర్తులేని అక్షరం byte = విలువ & 0x7f;

        విలువ >>= 7;
        dwarf_data1(s, byte | (విలువ ? 0x80 : 0));
    } అయితే (విలువ != 0);
}

స్థిర శూన్య dwarf_sleb128 (Section *s, దీర్ఘ దీర్ఘ విలువ)
{
    పూర్ణాంకం మరిన్ని;
    దీర్ఘ దీర్ఘ చివర = విలువ >> 63;
    గుర్తులేని అక్షరం చివరి = చివర & 0x40;

    చేయి {
        గుర్తులేని అక్షరం byte = విలువ & 0x7f;

        విలువ >>= 7;
	మరిన్ని = విలువ != చివర || (byte & 0x40) != చివరి;
        dwarf_data1(s, byte | (0x80 * మరిన్ని));
    } అయితే (మరిన్ని);
}

స్థిర శూన్య dwarf_uleb128_op (TCCState *s1, గుర్తులేని దీర్ఘ దీర్ఘ విలువ)
{
    చేయి {
        గుర్తులేని అక్షరం byte = విలువ & 0x7f;

        విలువ >>= 7;
        dwarf_పంక్తి_op(s1, byte | (విలువ ? 0x80 : 0));
    } అయితే (విలువ != 0);
}

స్థిర శూన్య dwarf_sleb128_op (TCCState *s1, దీర్ఘ దీర్ఘ విలువ)
{
    పూర్ణాంకం మరిన్ని;
    దీర్ఘ దీర్ఘ చివర = విలువ >> 63;
    గుర్తులేని అక్షరం చివరి = చివర & 0x40;

    చేయి {
        గుర్తులేని అక్షరం byte = విలువ & 0x7f;

        విలువ >>= 7;
        మరిన్ని = విలువ != చివర || (byte & 0x40) != చివరి;
        dwarf_పంక్తి_op(s1, byte | (0x80 * మరిన్ని));
    } అయితే (మరిన్ని);
}

#ఒకవేళ TCC_EH_చట్రం
ST_FUNC శూన్య tcc_eh_చట్రం_ప్రారంభం(TCCState *s1)
{
    ఒకవేళ (!s1->unwind_tables)
        తిరిగి;
    eh_చట్రం_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_ప్రారంభం = eh_చట్రం_section->దత్తాంశం_స్థానభ్రంశం;
    dwarf_data4(eh_చట్రం_section, 0); //నిడివి
    dwarf_data4(eh_చట్రం_section, 0); // CIE ID
    dwarf_data1(eh_చట్రం_section, 1); //సంస్కరణ
    dwarf_data1(eh_చట్రం_section, 'z'); // Augmentation String
    dwarf_data1(eh_చట్రం_section, 'R');
    dwarf_data1(eh_చట్రం_section, 0);
#ఒకవేళ defined TCC_లక్ష్యం_I386
    dwarf_uleb128(eh_చట్రం_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_చట్రం_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_చట్రం_section, 8); // return address column
    dwarf_uleb128(eh_చట్రం_section, 1); // Augmentation len
    dwarf_data1(eh_చట్రం_section, FDE_ENCODING);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_చట్రం_section, 4); // r4 (esp)
    dwarf_uleb128(eh_చట్రం_section, 4); // ofs 4
    dwarf_data1(eh_చట్రం_section, DW_CFA_స్థానభ్రంశం + 8); // r8 (eip)
    dwarf_uleb128(eh_చట్రం_section, 1); // cfa-4
#లేదావేళ defined TCC_లక్ష్యం_X86_64
    dwarf_uleb128(eh_చట్రం_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_చట్రం_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_చట్రం_section, 16); // return address column
    dwarf_uleb128(eh_చట్రం_section, 1); // Augmentation len
    dwarf_data1(eh_చట్రం_section, FDE_ENCODING);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_చట్రం_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_చట్రం_section, 8); // ofs 8
    dwarf_data1(eh_చట్రం_section, DW_CFA_స్థానభ్రంశం + 16); // r16 (rip)
    dwarf_uleb128(eh_చట్రం_section, 1); // cfa-8
#లేదావేళ defined TCC_లక్ష్యం_ARM
    /* TODO: arm must be compiled with: -funwind-tables */
    /* arm also uses .ARM.extab and .ARM.exidx sections */
    dwarf_uleb128(eh_చట్రం_section, 2); // code_alignment_factor
    dwarf_sleb128(eh_చట్రం_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_చట్రం_section, 14); // return address column
    dwarf_uleb128(eh_చట్రం_section, 1); // Augmentation len
    dwarf_data1(eh_చట్రం_section, FDE_ENCODING);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_చట్రం_section, 13); // r13 (sp)
    dwarf_uleb128(eh_చట్రం_section, 0); // ofs 0
#లేదావేళ defined TCC_లక్ష్యం_ARM64
    dwarf_uleb128(eh_చట్రం_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_చట్రం_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_చట్రం_section, 30); // return address column
    dwarf_uleb128(eh_చట్రం_section, 1); // Augmentation len
    dwarf_data1(eh_చట్రం_section, FDE_ENCODING);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_చట్రం_section, 31); // x31 (sp)
    dwarf_uleb128(eh_చట్రం_section, 0); // ofs 0
#లేదావేళ defined TCC_లక్ష్యం_RISCV64
    eh_చట్రం_section->దత్తాంశం[s1->eh_ప్రారంభం + 8] = 3; // version = 3
    dwarf_uleb128(eh_చట్రం_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_చట్రం_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_చట్రం_section, 1); // return address column
    dwarf_uleb128(eh_చట్రం_section, 1); // Augmentation len
    dwarf_data1(eh_చట్రం_section, FDE_ENCODING);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_చట్రం_section, 2); // r2 (sp)
    dwarf_uleb128(eh_చట్రం_section, 0); // ofs 0
#అయితే_ముగింపు
    అయితే ((eh_చట్రం_section->దత్తాంశం_స్థానభ్రంశం - s1->eh_ప్రారంభం) & 3)
	dwarf_data1(eh_చట్రం_section, DW_CFA_nop);
    write32le(eh_చట్రం_section->దత్తాంశం + s1->eh_ప్రారంభం, //నిడివి
	      eh_చట్రం_section->దత్తాంశం_స్థానభ్రంశం - s1->eh_ప్రారంభం - 4);
}

స్థిర శూన్య tcc_debug_చట్రం_చివర(TCCState *s1, పూర్ణాంకం కొలత)
{
    పూర్ణాంకం eh_section_sym;
    గుర్తులేని దీర్ఘ fde_ప్రారంభం;

    ఒకవేళ (!eh_చట్రం_section)
	తిరిగి;
    eh_section_sym = dwarf_get_section_sym(పాఠ్యం_section);
    fde_ప్రారంభం = eh_చట్రం_section->దత్తాంశం_స్థానభ్రంశం;
    dwarf_data4(eh_చట్రం_section, 0); //నిడివి
    dwarf_data4(eh_చట్రం_section,
		fde_ప్రారంభం - s1->eh_ప్రారంభం + 4); // CIE Pointer
#ఒకవేళ defined TCC_లక్ష్యం_I386
    dwarf_reloc(eh_చట్రం_section, eh_section_sym, R_386_PC32);
#లేదావేళ defined TCC_లక్ష్యం_X86_64
    dwarf_reloc(eh_చట్రం_section, eh_section_sym, R_X86_64_PC32);
#లేదావేళ defined TCC_లక్ష్యం_ARM
    dwarf_reloc(eh_చట్రం_section, eh_section_sym, R_ARM_REL32);
#లేదావేళ defined TCC_లక్ష్యం_ARM64
    dwarf_reloc(eh_చట్రం_section, eh_section_sym, R_AARCH64_PREL32);
#లేదావేళ defined TCC_లక్ష్యం_RISCV64
    dwarf_reloc(eh_చట్రం_section, eh_section_sym, R_RISCV_32_PCREL);
#అయితే_ముగింపు
    dwarf_data4(eh_చట్రం_section, func_ind); // PC Begin
    dwarf_data4(eh_చట్రం_section, కొలత); // PC Range
    dwarf_data1(eh_చట్రం_section, 0); // Augmentation Length
#ఒకవేళ defined TCC_లక్ష్యం_I386
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa_స్థానభ్రంశం);
    dwarf_uleb128(eh_చట్రం_section, 8);
    dwarf_data1(eh_చట్రం_section, DW_CFA_స్థానభ్రంశం + 5); // r5 (ebp)
    dwarf_uleb128(eh_చట్రం_section, 2); // cfa-8
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa_రిజిస్టరు);
    dwarf_uleb128(eh_చట్రం_section, 5); // r5 (ebp)
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_చట్రం_section, కొలత - 5);
    dwarf_data1(eh_చట్రం_section, DW_CFA_restore + 5); // r5 (ebp)
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_చట్రం_section, 4); // r4 (esp)
    dwarf_uleb128(eh_చట్రం_section, 4); // ofs 4
#లేదావేళ defined TCC_లక్ష్యం_X86_64
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa_స్థానభ్రంశం);
    dwarf_uleb128(eh_చట్రం_section, 16);
    dwarf_data1(eh_చట్రం_section, DW_CFA_స్థానభ్రంశం + 6); // r6 (rbp)
    dwarf_uleb128(eh_చట్రం_section, 2); // cfa-16
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa_రిజిస్టరు);
    dwarf_uleb128(eh_చట్రం_section, 6); // r6 (rbp)
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_చట్రం_section, కొలత - 5);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_చట్రం_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_చట్రం_section, 8); // ofs 8
#లేదావేళ defined TCC_లక్ష్యం_ARM
    /* TODO */
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa_స్థానభ్రంశం);
    dwarf_uleb128(eh_చట్రం_section, 8);
    dwarf_data1(eh_చట్రం_section, DW_CFA_స్థానభ్రంశం + 14); // r14 (lr)
    dwarf_uleb128(eh_చట్రం_section, 1);
    dwarf_data1(eh_చట్రం_section, DW_CFA_స్థానభ్రంశం + 11); // r11 (fp)
    dwarf_uleb128(eh_చట్రం_section, 2);
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_చట్రం_section, కొలత / 2 - 5);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa_రిజిస్టరు);
    dwarf_uleb128(eh_చట్రం_section, 11); // r11 (fp)
#లేదావేళ defined TCC_లక్ష్యం_ARM64
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa_స్థానభ్రంశం);
    dwarf_uleb128(eh_చట్రం_section, 224);
    dwarf_data1(eh_చట్రం_section, DW_CFA_స్థానభ్రంశం + 29); // x29 (fp)
    dwarf_uleb128(eh_చట్రం_section, 28); // cfa-224
    dwarf_data1(eh_చట్రం_section, DW_CFA_స్థానభ్రంశం + 30); // x30 (lr)
    dwarf_uleb128(eh_చట్రం_section, 27); // cfa-216
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa_స్థానభ్రంశం);
    dwarf_uleb128(eh_చట్రం_section, 224 + ((-loc + 15) & ~15));
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_చట్రం_section, కొలత / 4 - 5);
    dwarf_data1(eh_చట్రం_section, DW_CFA_restore + 30); // x30 (lr)
    dwarf_data1(eh_చట్రం_section, DW_CFA_restore + 29); // x29 (fp)
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa_స్థానభ్రంశం);
    dwarf_uleb128(eh_చట్రం_section, 0);
#లేదావేళ defined TCC_లక్ష్యం_RISCV64
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa_స్థానభ్రంశం);
    dwarf_uleb128(eh_చట్రం_section, 16); // ofs 16
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_చట్రం_section, DW_CFA_స్థానభ్రంశం + 1); // r1 (ra, lr)
    dwarf_uleb128(eh_చట్రం_section, 2); // cfa-8
    dwarf_data1(eh_చట్రం_section, DW_CFA_స్థానభ్రంశం + 8); // r8 (s0, fp)
    dwarf_uleb128(eh_చట్రం_section, 4); // cfa-16
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_చట్రం_section, 8); // r8 (s0, fp)
    dwarf_uleb128(eh_చట్రం_section, 0); // ofs 0
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc4);
    అయితే (కొలత >= 4 &&
	   read32le(cur_పాఠ్యం_section->దత్తాంశం + func_ind + కొలత - 4) != 0x00008067)
	కొలత -= 4;
    dwarf_data4(eh_చట్రం_section, కొలత - 36);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_చట్రం_section, 2); // r2 (r2, sp)
    dwarf_uleb128(eh_చట్రం_section, 16); // ofs 16
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_చట్రం_section, DW_CFA_restore + 1); // r1 (lr)
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_చట్రం_section, DW_CFA_restore + 8); // r8 (s0, fp)
    dwarf_data1(eh_చట్రం_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_చట్రం_section, DW_CFA_def_cfa_స్థానభ్రంశం);
    dwarf_uleb128(eh_చట్రం_section, 0); // ofs 0
#అయితే_ముగింపు
    అయితే ((eh_చట్రం_section->దత్తాంశం_స్థానభ్రంశం - fde_ప్రారంభం) & 3)
	dwarf_data1(eh_చట్రం_section, DW_CFA_nop);
    write32le(eh_చట్రం_section->దత్తాంశం + fde_ప్రారంభం, //నిడివి
	      eh_చట్రం_section->దత్తాంశం_స్థానభ్రంశం - fde_ప్రారంభం - 4);
}

ST_FUNC శూన్య tcc_eh_చట్రం_చివర(TCCState *s1)
{
    ఒకవేళ (!eh_చట్రం_section)
	తిరిగి;
    dwarf_data4(eh_చట్రం_section, 0);
}

నిర్మాణం eh_శోధన_పట్టిక {
    uint32_t pc_స్థానభ్రంశం;
    uint32_t fde_స్థానభ్రంశం;
};

స్థిర పూర్ణాంకం క్రమీకరించు_eh_పట్టిక(స్థిరరాశి శూన్య *a, స్థిరరాశి శూన్య *b)
{
    uint32_t pc1 = ((స్థిరరాశి నిర్మాణం eh_శోధన_పట్టిక *)a)->pc_స్థానభ్రంశం;
    uint32_t pc2 = ((స్థిరరాశి నిర్మాణం eh_శోధన_పట్టిక *)b)->pc_స్థానభ్రంశం;

    తిరిగి pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC శూన్య tcc_eh_చట్రం_hdr(TCCState *s1, పూర్ణాంకం final)
{
    పూర్ణాంకం లెక్క_2 = 0, స్థానభ్రంశం;
    గుర్తులేని దీర్ఘ లెక్క_స్థానభ్రంశం, tab_స్థానభ్రంశం;
    గుర్తులేని అక్షరం *ln, *చివర;
    గుర్తులేని పూర్ణాంకం చివరి_cie_స్థానభ్రంశం = 0xffffffff;

    ఒకవేళ (!eh_చట్రం_section || !eh_చట్రం_section->దత్తాంశం_స్థానభ్రంశం)
	తిరిగి;
    ఒకవేళ (final && !eh_చట్రం_hdr_section)
	తిరిగి;
    ఒకవేళ (final == 0)
        eh_చట్రం_hdr_section =
	    new_section(s1, ".eh_frame_hdr", SHT_PROGBITS, SHF_ALLOC);
    eh_చట్రం_hdr_section->దత్తాంశం_స్థానభ్రంశం = 0;
    dwarf_data1(eh_చట్రం_hdr_section, 1); //సంస్కరణ
    // Pointer Encoding Format
    dwarf_data1(eh_చట్రం_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_pcrel);
    // Count Encoding Format
    dwarf_data1(eh_చట్రం_hdr_section, DW_EH_PE_udata4 | DW_EH_PE_absptr);
    // Table Encoding Format
    dwarf_data1(eh_చట్రం_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_datarel);
    స్థానభ్రంశం = eh_చట్రం_section->sh_addr -
             eh_చట్రం_hdr_section->sh_addr -
             eh_చట్రం_hdr_section->దత్తాంశం_స్థానభ్రంశం;
    dwarf_data4(eh_చట్రం_hdr_section, స్థానభ్రంశం); // eh_frame_ptr
    //లెక్క
    లెక్క_స్థానభ్రంశం = eh_చట్రం_hdr_section->దత్తాంశం_స్థానభ్రంశం;
    dwarf_data4(eh_చట్రం_hdr_section, 0);
    tab_స్థానభ్రంశం = eh_చట్రం_hdr_section->దత్తాంశం_స్థానభ్రంశం;
    ln = eh_చట్రం_section->దత్తాంశం;
    చివర = eh_చట్రం_section->దత్తాంశం + eh_చట్రం_section->దత్తాంశం_స్థానభ్రంశం;
    అయితే (ln < చివర) {
	గుర్తులేని అక్షరం *fde = ln, *rd = ln;
	గుర్తులేని పూర్ణాంకం cie_స్థానభ్రంశం, సంస్కరణ, నిడివి = dwarf_read_4(rd, చివర);
	గుర్తులేని పూర్ణాంకం pc_స్థానభ్రంశం, fde_స్థానభ్రంశం;

	ఒకవేళ (నిడివి == 0)
	    వెళ్ళు తదుపరి;
        cie_స్థానభ్రంశం = dwarf_read_4(rd, చివర);
	ఒకవేళ (cie_స్థానభ్రంశం == 0)
	    వెళ్ళు తదుపరి;
	ఒకవేళ (cie_స్థానభ్రంశం != చివరి_cie_స్థానభ్రంశం) {
	    గుర్తులేని అక్షరం *cie = rd - cie_స్థానభ్రంశం + 4;

	    ఒకవేళ (cie < eh_చట్రం_section->దత్తాంశం)
		వెళ్ళు తదుపరి;
	    సంస్కరణ = dwarf_read_1(cie, చివర);
	    ఒకవేళ ((సంస్కరణ == 1 || సంస్కరణ == 3) &&
	        dwarf_read_1(cie, చివర) == 'z' && // Augmentation String
		dwarf_read_1(cie, చివర) == 'R' &&
		dwarf_read_1(cie, చివర) == 0) {
	        dwarf_read_uleb128(&cie, చివర); // code_alignment_factor
	        dwarf_read_sleb128(&cie, చివర); // data_alignment_factor
		dwarf_read_1(cie, చివర); // return address column
		ఒకవేళ (dwarf_read_uleb128(&cie, చివర) == 1 &&
		    dwarf_read_1(cie, చివర) == FDE_ENCODING) {
		    చివరి_cie_స్థానభ్రంశం = cie_స్థానభ్రంశం;
		}
		లేకపోతే
		    వెళ్ళు తదుపరి;
	    }
	    లేకపోతే
		వెళ్ళు తదుపరి;
	}
	లెక్క_2++;
	fde_స్థానభ్రంశం = eh_చట్రం_section->sh_addr +
		     (fde - eh_చట్రం_section->దత్తాంశం) -
		     eh_చట్రం_hdr_section->sh_addr;
	pc_స్థానభ్రంశం = dwarf_read_4(rd, చివర) + fde_స్థానభ్రంశం + 8;
	dwarf_data4(eh_చట్రం_hdr_section, pc_స్థానభ్రంశం);
	dwarf_data4(eh_చట్రం_hdr_section, fde_స్థానభ్రంశం);
తదుపరి:
	ln += నిడివి + 4;
    }
    add32le(eh_చట్రం_hdr_section->దత్తాంశం + లెక్క_స్థానభ్రంశం, లెక్క_2);
    qsort(eh_చట్రం_hdr_section->దత్తాంశం + tab_స్థానభ్రంశం, లెక్క_2,
	  పరిమాణం(నిర్మాణం eh_శోధన_పట్టిక), క్రమీకరించు_eh_పట్టిక);
}
#అయితే_ముగింపు

/* start of translation unit info */
ST_FUNC శూన్య tcc_debug_ప్రారంభం(TCCState *s1)
{
    పూర్ణాంకం i;
    అక్షరం buf[512];
    అక్షరం *filename;

    /* we might currently #include the <command-line> */
    filename = file->prev ? file->prev->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    ఒకవేళ (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            పాఠ్యం_section->sh_అంకె, "$a");

        new_file = చివరి_పంక్తి_అంకె = 0;
        debug_తదుపరి_type = N_DEFAULT_DEBUG;
        debug_hash_global = ఖాళీ;
        debug_hash_local = ఖాళీ;
        debug_forw_hash_global = ఖాళీ;
        debug_forw_hash_local = ఖాళీ;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, పరిమాణం(buf));
#నిర్వచితమైతే _WIN32
        normalize_slashes(buf);
#అయితే_ముగింపు

        ఒకవేళ (s1->dwarf) {
            పూర్ణాంకం ప్రారంభం_abbrev;
            గుర్తులేని అక్షరం *ptr;
	    అక్షరం *undo;

            /* dwarf_abbrev */
            ప్రారంభం_abbrev = dwarf_abbrev_section->దత్తాంశం_స్థానభ్రంశం;
            ptr = section_ptr_కూడు(dwarf_abbrev_section, పరిమాణం(dwarf_abbrev_init));
            జ్ఞాపకం_నకలు(ptr, dwarf_abbrev_init, పరిమాణం(dwarf_abbrev_init));

            ఒకవేళ (s1->dwarf < 5) {
    	        అయితే (*ptr) {
    	            ptr += 3;
    	            అయితే (*ptr) {
    	                ఒకవేళ (ptr[1] == DW_FORM_పంక్తి_strp)
    		            ptr[1] = DW_FORM_strp;
		        ఒకవేళ (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    ఒకవేళ  (ptr[1] == DW_FORM_sec_స్థానభ్రంశం)
			         ptr[1] = DW_FORM_data4;
			    /* This code uses only size < 0x80 so these are
			       compatible. */
			    ఒకవేళ  (ptr[1] == DW_FORM_exprloc)
			         ptr[1] = DW_FORM_block1;
			}
    	                ptr += 2;
    	            }
		    ptr += 2;
    	        }
            }

            dwarf_sym.info = dwarf_get_section_sym(dwarf_info_section);
            dwarf_sym.abbrev = dwarf_get_section_sym(dwarf_abbrev_section);
            dwarf_sym.పంక్తి = dwarf_get_section_sym(dwarf_పంక్తి_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            ఒకవేళ (tcc_state->dwarf >= 5)
    	        dwarf_sym.పంక్తి_str = dwarf_get_section_sym(dwarf_పంక్తి_str_section);
            లేకపోతే {
    	        dwarf_పంక్తి_str_section = dwarf_str_section;
                dwarf_sym.పంక్తి_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(పాఠ్యం_section);

            /* dwarf_info */
            dwarf_info.ప్రారంభం = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
            dwarf_data4(dwarf_info_section, 0); //కొలత
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            ఒకవేళ (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_కొలత);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_దత్తాంశం_32_DW);
                dwarf_data4(dwarf_info_section, ప్రారంభం_abbrev);
            }
            లేకపోతే {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_దత్తాంశం_32_DW);
                dwarf_data4(dwarf_info_section, ప్రారంభం_abbrev);
                dwarf_data1(dwarf_info_section, PTR_కొలత);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_సంస్కరణ);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_పంక్తి_strp(dwarf_info_section, filename);
            dwarf_పంక్తి_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_దత్తాంశం_PTR);
#ఒకవేళ PTR_కొలత == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#లేకపోతే
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#అయితే_ముగింపు
            dwarf_reloc(dwarf_info_section, dwarf_sym.పంక్తి, R_దత్తాంశం_32_DW);
            dwarf_data4(dwarf_info_section, dwarf_పంక్తి_section->దత్తాంశం_స్థానభ్రంశం); // stmt_list

            /* dwarf_line */
            dwarf_పంక్తి.ప్రారంభం = dwarf_పంక్తి_section->దత్తాంశం_స్థానభ్రంశం;
            dwarf_data4(dwarf_పంక్తి_section, 0); //నిడివి
            dwarf_data2(dwarf_పంక్తి_section, s1->dwarf); // version
            ఒకవేళ (s1->dwarf >= 5) {
                dwarf_data1(dwarf_పంక్తి_section, PTR_కొలత); // address size
                dwarf_data1(dwarf_పంక్తి_section, 0); // segment selector
            }
            dwarf_data4(dwarf_పంక్తి_section, 0); // prologue Length
            dwarf_data1(dwarf_పంక్తి_section, DWARF_MIN_INSTR_LEN);
            ఒకవేళ (s1->dwarf >= 4)
                dwarf_data1(dwarf_పంక్తి_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_పంక్తి_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_పంక్తి_section, DWARF_పంక్తి_పునాది);
            dwarf_data1(dwarf_పంక్తి_section, DWARF_పంక్తి_RANGE);
            dwarf_data1(dwarf_పంక్తి_section, DWARF_OPCODE_పునాది);
            ptr = section_ptr_కూడు(dwarf_పంక్తి_section, పరిమాణం(dwarf_పంక్తి_opcodes));
            జ్ఞాపకం_నకలు(ptr, dwarf_పంక్తి_opcodes, పరిమాణం(dwarf_పంక్తి_opcodes));
	    undo = strrchr(filename, '/');
	    ఒకవేళ (undo)
		*undo = 0;
            dwarf_పంక్తి.dir_కొలత = 1 + (undo != ఖాళీ);
            dwarf_పంక్తి.dir_పట్టిక = (అక్షరం **) tcc_malloc(పరిమాణం (అక్షరం *) *
							dwarf_పంక్తి.dir_కొలత);
            dwarf_పంక్తి.dir_పట్టిక[0] = tcc_strdup(buf);
	    ఒకవేళ (undo)
                dwarf_పంక్తి.dir_పట్టిక[1] = tcc_strdup(filename);
            dwarf_పంక్తి.filename_కొలత = 2;
            dwarf_పంక్తి.filename_పట్టిక =
    	        (నిర్మాణం dwarf_filename_struct *)
    	        tcc_malloc(2*పరిమాణం (నిర్మాణం dwarf_filename_struct));
            dwarf_పంక్తి.filename_పట్టిక[0].dir_నమోదు = 0;
	    ఒకవేళ (undo) {
                dwarf_పంక్తి.filename_పట్టిక[0].name = tcc_strdup(undo + 1);
                dwarf_పంక్తి.filename_పట్టిక[1].dir_నమోదు = 1;
                dwarf_పంక్తి.filename_పట్టిక[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    లేకపోతే {
                dwarf_పంక్తి.filename_పట్టిక[0].name = tcc_strdup(filename);
                dwarf_పంక్తి.filename_పట్టిక[1].dir_నమోదు = 0;
                dwarf_పంక్తి.filename_పట్టిక[1].name = tcc_strdup(filename);
	    }
            dwarf_పంక్తి.పంక్తి_కొలత = dwarf_పంక్తి.పంక్తి_max_కొలత = 0;
            dwarf_పంక్తి.పంక్తి_దత్తాంశం = ఖాళీ;
            dwarf_పంక్తి.cur_file = 1;
            dwarf_పంక్తి.చివరి_file = 0;
            dwarf_పంక్తి.చివరి_pc = 0;
            dwarf_పంక్తి.చివరి_పంక్తి = 1;
            dwarf_పంక్తి_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_కొలత); // extended size
            dwarf_పంక్తి_op(s1, DW_LNE_సమితి_చిరునామా);
            కొరకు (i = 0; i < PTR_కొలత; i++)
    	        dwarf_పంక్తి_op(s1, 0);
            memset(&dwarf_info.పునాది_type_వాడిన, 0, పరిమాణం(dwarf_info.పునాది_type_వాడిన));
        }
        లేకపోతే
        {
            /* file info: full path + filename */
            pstrcat(buf, పరిమాణం(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      పాఠ్యం_section->sh_అంకె, ఖాళీ);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం, పాఠ్యం_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం, పాఠ్యం_section, section_sym);
            కొరకు (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

స్థిర శూన్య fix_debug_forw_hash(TCCState *s1, పూర్ణాంకం global, పూర్ణాంకం ప్రారంభం);

/* put end of translation unit info */
ST_FUNC శూన్య tcc_debug_చివర(TCCState *s1)
{

    ఒకవేళ (!s1->do_debug || debug_తదుపరి_type == 0)
        తిరిగి;

    ఒకవేళ (debug_info_మూలం)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    ఒకవేళ (s1->dwarf) {
	పూర్ణాంకం i;
	పూర్ణాంకం ప్రారంభం_aranges;
	గుర్తులేని అక్షరం *ptr;
	పూర్ణాంకం పాఠ్యం_కొలత = పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం;

	/* dwarf_info */
	fix_debug_forw_hash(s1, 0, 0);
	fix_debug_forw_hash(s1, 1, 0);
	dwarf_data1(dwarf_info_section, 0);
	ptr = dwarf_info_section->దత్తాంశం + dwarf_info.ప్రారంభం;
	write32le(ptr, dwarf_info_section->దత్తాంశం_స్థానభ్రంశం - dwarf_info.ప్రారంభం - 4);
	write32le(ptr + 25 + (s1->dwarf >= 5) + PTR_కొలత, పాఠ్యం_కొలత);

	/* dwarf_aranges */
	ప్రారంభం_aranges = dwarf_aranges_section->దత్తాంశం_స్థానభ్రంశం;
	dwarf_data4(dwarf_aranges_section, 0); //కొలత
	dwarf_data2(dwarf_aranges_section, 2); // version
	dwarf_reloc(dwarf_aranges_section, dwarf_sym.info, R_దత్తాంశం_32_DW);
	dwarf_data4(dwarf_aranges_section, 0); // dwarf_info
#ఒకవేళ PTR_కొలత == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#లేకపోతే
	dwarf_data1(dwarf_aranges_section, 8); // address size
#అయితే_ముగింపు
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_దత్తాంశం_PTR);
#ఒకవేళ PTR_కొలత == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, పాఠ్యం_కొలత); //చివర
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#లేకపోతే
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, పాఠ్యం_కొలత); //చివర
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#అయితే_ముగింపు
	ptr = dwarf_aranges_section->దత్తాంశం + ప్రారంభం_aranges;
	write32le(ptr, dwarf_aranges_section->దత్తాంశం_స్థానభ్రంశం - ప్రారంభం_aranges - 4);

	/* dwarf_line */
	ఒకవేళ (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_పంక్తి_section, 1); /*నిలువు*/
	    dwarf_uleb128(dwarf_పంక్తి_section, DW_LNCT_మార్గం);
	    dwarf_uleb128(dwarf_పంక్తి_section, DW_FORM_పంక్తి_strp);
	    dwarf_uleb128(dwarf_పంక్తి_section, dwarf_పంక్తి.dir_కొలత);
	    కొరకు (i = 0; i < dwarf_పంక్తి.dir_కొలత; i++)
	        dwarf_పంక్తి_strp(dwarf_పంక్తి_section, dwarf_పంక్తి.dir_పట్టిక[i]);
	    dwarf_data1(dwarf_పంక్తి_section, 2); /*నిలువు*/
	    dwarf_uleb128(dwarf_పంక్తి_section, DW_LNCT_మార్గం);
	    dwarf_uleb128(dwarf_పంక్తి_section, DW_FORM_పంక్తి_strp);
	    dwarf_uleb128(dwarf_పంక్తి_section, DW_LNCT_directory_సూచీ);
	    dwarf_uleb128(dwarf_పంక్తి_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_పంక్తి_section, dwarf_పంక్తి.filename_కొలత);
	    కొరకు (i = 0; i < dwarf_పంక్తి.filename_కొలత; i++) {
	        dwarf_పంక్తి_strp(dwarf_పంక్తి_section,
				dwarf_పంక్తి.filename_పట్టిక[i].name);
	        dwarf_uleb128(dwarf_పంక్తి_section,
			      dwarf_పంక్తి.filename_పట్టిక[i].dir_నమోదు);
	    }
	}
	లేకపోతే {
	    పూర్ణాంకం len;

	    కొరకు (i = 0; i < dwarf_పంక్తి.dir_కొలత; i++) {
	        len = అక్షరశ్రేణి_పొడవు(dwarf_పంక్తి.dir_పట్టిక[i]) + 1;
	        ptr = section_ptr_కూడు(dwarf_పంక్తి_section, len);
	        memmove(ptr, dwarf_పంక్తి.dir_పట్టిక[i], len);
	    }
	    dwarf_data1(dwarf_పంక్తి_section, 0); /* end dir */
	    కొరకు (i = 0; i < dwarf_పంక్తి.filename_కొలత; i++) {
	        len = అక్షరశ్రేణి_పొడవు(dwarf_పంక్తి.filename_పట్టిక[i].name) + 1;
	        ptr = section_ptr_కూడు(dwarf_పంక్తి_section, len);
	        memmove(ptr, dwarf_పంక్తి.filename_పట్టిక[i].name, len);
	        dwarf_uleb128(dwarf_పంక్తి_section,
			      dwarf_పంక్తి.filename_పట్టిక[i].dir_నమోదు);
	        dwarf_uleb128(dwarf_పంక్తి_section, 0); /*సమయం*/
	        dwarf_uleb128(dwarf_పంక్తి_section, 0); /*కొలత*/
	    }
	    dwarf_data1(dwarf_పంక్తి_section, 0); /* end file */
	}
	కొరకు (i = 0; i < dwarf_పంక్తి.dir_కొలత; i++)
	    tcc_free(dwarf_పంక్తి.dir_పట్టిక[i]);
	tcc_free(dwarf_పంక్తి.dir_పట్టిక);
	కొరకు (i = 0; i < dwarf_పంక్తి.filename_కొలత; i++)
	    tcc_free(dwarf_పంక్తి.filename_పట్టిక[i].name);
	tcc_free(dwarf_పంక్తి.filename_పట్టిక);

	dwarf_పంక్తి_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_పంక్తి_op(s1, DW_LNE_చివర_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_పంక్తి_section->దత్తాంశం[dwarf_పంక్తి.ప్రారంభం + 6 + i],
		  dwarf_పంక్తి_section->దత్తాంశం_స్థానభ్రంశం - dwarf_పంక్తి.ప్రారంభం - (10 + i));
	section_ptr_కూడు(dwarf_పంక్తి_section, 3);
	dwarf_reloc(dwarf_పంక్తి_section, section_sym, R_దత్తాంశం_PTR);
	ptr = section_ptr_కూడు(dwarf_పంక్తి_section, dwarf_పంక్తి.పంక్తి_కొలత - 3);
	memmove(ptr - 3, dwarf_పంక్తి.పంక్తి_దత్తాంశం, dwarf_పంక్తి.పంక్తి_కొలత);
	tcc_free(dwarf_పంక్తి.పంక్తి_దత్తాంశం);
	write32le(dwarf_పంక్తి_section->దత్తాంశం + dwarf_పంక్తి.ప్రారంభం,
		  dwarf_పంక్తి_section->దత్తాంశం_స్థానభ్రంశం - dwarf_పంక్తి.ప్రారంభం - 4);
    }
    లేకపోతే
    {
        put_stabs_r(s1, ఖాళీ, N_SO, 0, 0,
                    పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం, పాఠ్యం_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_పంక్తి_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_తదుపరి_type = 0;
}

స్థిర BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    ఒకవేళ (f->filename[0] == ':')
        f = f->prev;
    ఒకవేళ (f && new_file) {
        new_file = చివరి_పంక్తి_అంకె = 0;
        ఒకవేళ (s1->dwarf)
            dwarf_file(s1);
        లేకపోతే
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, పాఠ్యం_section, section_sym);
    }
    తిరిగి f;
}

/* put alternative filename */
ST_FUNC శూన్య tcc_debug_newfile(TCCState *s1)
{
    ఒకవేళ (!s1->do_debug)
        తిరిగి;
    ఒకవేళ (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC శూన్య tcc_debug_bincl(TCCState *s1)
{
    ఒకవేళ (!s1->do_debug)
        తిరిగి;
    ఒకవేళ (s1->dwarf)
        dwarf_file(s1);
    లేకపోతే
        put_stabs(s1, file->filename, N_BINCL, 0, 0, 0);
    new_file = 1;
}

/* end of #include */
ST_FUNC శూన్య tcc_debug_eincl(TCCState *s1)
{
    ఒకవేళ (!s1->do_debug)
        తిరిగి;
    ఒకవేళ (s1->dwarf)
        dwarf_file(s1);
    లేకపోతే
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC శూన్య tcc_debug_పంక్తి(TCCState *s1)
{
    BufferedFile *f;

    ఒకవేళ (!s1->do_debug)
        తిరిగి;
    ఒకవేళ (cur_పాఠ్యం_section != పాఠ్యం_section || nocode_wanted)
        తిరిగి;
    f = put_new_file(s1);
    ఒకవేళ (!f)
        తిరిగి;
    ఒకవేళ (చివరి_పంక్తి_అంకె == f->పంక్తి_అంకె)
        తిరిగి;
    చివరి_పంక్తి_అంకె = f->పంక్తి_అంకె;

    ఒకవేళ (s1->dwarf) {
	పూర్ణాంకం len_pc = (ind - dwarf_పంక్తి.చివరి_pc) / DWARF_MIN_INSTR_LEN;
	పూర్ణాంకం len_పంక్తి = f->పంక్తి_అంకె - dwarf_పంక్తి.చివరి_పంక్తి;
	పూర్ణాంకం n = len_pc * DWARF_పంక్తి_RANGE + len_పంక్తి + DWARF_OPCODE_పునాది - DWARF_పంక్తి_పునాది;

	ఒకవేళ (dwarf_పంక్తి.cur_file != dwarf_పంక్తి.చివరి_file) {
	    dwarf_పంక్తి.చివరి_file = dwarf_పంక్తి.cur_file;
	    dwarf_పంక్తి_op(s1, DW_LNS_సమితి_file);
	    dwarf_uleb128_op(s1, dwarf_పంక్తి.cur_file);
	}
	ఒకవేళ (len_pc &&
	    len_పంక్తి >= DWARF_పంక్తి_పునాది && len_పంక్తి <= (DWARF_OPCODE_పునాది + DWARF_పంక్తి_పునాది) &&
	    n >= DWARF_OPCODE_పునాది && n <= 255)
            dwarf_పంక్తి_op(s1, n);
	లేకపోతే {
	    ఒకవేళ (len_pc) {
	        n = len_pc * DWARF_పంక్తి_RANGE + 0 + DWARF_OPCODE_పునాది - DWARF_పంక్తి_పునాది;
	        ఒకవేళ (n >= DWARF_OPCODE_పునాది && n <= 255)
                    dwarf_పంక్తి_op(s1, n);
		లేకపోతే {
	            dwarf_పంక్తి_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    ఒకవేళ (len_పంక్తి) {
	        n = 0 * DWARF_పంక్తి_RANGE + len_పంక్తి + DWARF_OPCODE_పునాది - DWARF_పంక్తి_పునాది;
	        ఒకవేళ (len_పంక్తి >= DWARF_పంక్తి_పునాది && len_పంక్తి <= (DWARF_OPCODE_పునాది + DWARF_పంక్తి_పునాది) &&
		    n >= DWARF_OPCODE_పునాది && n <= 255)
	            dwarf_పంక్తి_op(s1, n);
		లేకపోతే {
	            dwarf_పంక్తి_op(s1, DW_LNS_advance_పంక్తి);
		    dwarf_sleb128_op(s1, len_పంక్తి);
                    /* advance by nothing */
	            dwarf_పంక్తి_op(s1, DWARF_OPCODE_పునాది - DWARF_పంక్తి_పునాది);
		}
	    }
	}
	dwarf_పంక్తి.చివరి_pc = ind;
	dwarf_పంక్తి.చివరి_పంక్తి = f->పంక్తి_అంకె;
    }
    లేకపోతే
    {
	ఒకవేళ (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->పంక్తి_అంకె, ind - func_ind);
        } లేకపోతే {
            /* from tcc_assemble */
            put_stabs_r(s1, ఖాళీ, N_SLINE, 0, f->పంక్తి_అంకె, ind, పాఠ్యం_section, section_sym);
        }
    }
}

స్థిర శూన్య tcc_debug_stabs (TCCState *s1, స్థిరరాశి అక్షరం *str, పూర్ణాంకం type, గుర్తులేని దీర్ఘ విలువ,
                             Section *sec, పూర్ణాంకం sym_సూచీ, పూర్ణాంకం info)
{
    నిర్మాణం debug_sym *s;

    ఒకవేళ (debug_info) {
        debug_info->sym =
            (నిర్మాణం debug_sym *)tcc_realloc (debug_info->sym,
                                             పరిమాణం(నిర్మాణం debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->విలువ = విలువ;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_సూచీ = sym_సూచీ;
        s->info = info;
        s->file = dwarf_పంక్తి.cur_file;
        s->పంక్తి = file->పంక్తి_అంకె;
    }
    లేకపోతే ఒకవేళ (sec)
        put_stabs_r (s1, str, type, 0, 0, విలువ, sec, sym_సూచీ);
    లేకపోతే
        put_stabs (s1, str, type, 0, 0, విలువ);
}

స్థిర శూన్య fix_debug_forw_hash(TCCState *s1, పూర్ణాంకం global, పూర్ణాంకం ప్రారంభం)
{
    ఒకవేళ (s1->dwarf) {
        పూర్ణాంకం i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	నిర్మాణం _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	కొరకు (i = ప్రారంభం; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    పూర్ణాంకం pos = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_ఖాళీలు_TYPE
                                             : DWARF_ABBREV_STRUCTURE_ఖాళీలు_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_మొదటి_ANOM
                       ? "" : get_tok_str(t->v, ఖాళీ));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_పంక్తి.cur_file);
            dwarf_uleb128(dwarf_info_section, file->పంక్తి_అంకె);
	    కొరకు (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->దత్తాంశం +
			  hash[i].debug_type[j],
			  pos - dwarf_info.ప్రారంభం);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC శూన్య tcc_debug_stabn(TCCState *s1, పూర్ణాంకం type, పూర్ణాంకం విలువ)
{
    ఒకవేళ (!s1->do_debug)
        తిరిగి;
    ఒకవేళ (type == N_LBRAC) {
        నిర్మాణం _debug_info *info =
            (నిర్మాణం _debug_info *) tcc_mallocz(పరిమాణం (*info));

        info->ప్రారంభం = విలువ;
        info->చివరి_debug_hash = n_debug_hash_local;
        info->చివరి_debug_forw_hash = n_debug_forw_hash_local;
        info->మాతృ = debug_info;
        ఒకవేళ (debug_info) {
            ఒకవేళ (debug_info->బిడ్డ) {
                ఒకవేళ (debug_info->బిడ్డ->చివరి)
                    debug_info->బిడ్డ->చివరి->తదుపరి = info;
                లేకపోతే
                    debug_info->బిడ్డ->తదుపరి = info;
                debug_info->బిడ్డ->చివరి = info;
            }
            లేకపోతే
                debug_info->బిడ్డ = info;
        }
        లేకపోతే
            debug_info_మూలం = info;
        debug_info = info;
    }
    లేకపోతే {
	fix_debug_forw_hash(s1, 0, debug_info->చివరి_debug_forw_hash);
        n_debug_hash_local = debug_info->చివరి_debug_hash;
        n_debug_forw_hash_local = debug_info->చివరి_debug_forw_hash;
        debug_info->చివర = విలువ;
        debug_info = debug_info->మాతృ;
    }
}

స్థిర పూర్ణాంకం check_global(Sym *t)
{
    Sym *g = local_దొంతర;

    అయితే (g) {
	ఒకవేళ (t == g)
	    తిరిగి 0;
	g = g->prev;
    }
    తిరిగి 1;
}

స్థిర పూర్ణాంకం tcc_debug_కనుగొను(TCCState *s1, Sym *t, పూర్ణాంకం dwarf)
{
    పూర్ణాంకం i , g = check_global(t);
    పూర్ణాంకం n_hash, *n_forw_hash;
    నిర్మాణం _debug_hash *hash;
    నిర్మాణం _debug_forw_hash **forw_hash;

    ఒకవేళ ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	కొరకు (i = 0; i < *n_forw_hash; i++)
            ఒకవేళ (t == (*forw_hash)[i].type)
		తిరిగి 0;
	*forw_hash = (నిర్మాణం _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * పరిమాణం(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = ఖాళీ;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	తిరిగి 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    కొరకు (i = 0; i < n_hash; i++)
        ఒకవేళ (t == hash[i].type)
	    తిరిగి hash[i].debug_type;
    తిరిగి -1;
}

స్థిర పూర్ణాంకం tcc_get_dwarf_info(TCCState *s1, Sym *s);

స్థిర శూన్య tcc_debug_check_forw(TCCState *s1, Sym *t, పూర్ణాంకం debug_type)
{
    ఒకవేళ ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        పూర్ణాంకం i, j, g = check_global(t);
        పూర్ణాంకం n_forw_hash;
        నిర్మాణం _debug_forw_hash **forw_hash;

	కొరకు (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    కొరకు (j = 0; j < n_forw_hash; j++)
                ఒకవేళ (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * పరిమాణం(పూర్ణాంకం));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    తిరిగి;
                }
	}
    }
}

స్థిర శూన్య stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC శూన్య tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    ఒకవేళ (!(s1->do_debug & 2))
	తిరిగి;
    ఒకవేళ (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        తిరిగి;
    }
    ఒకవేళ ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        పూర్ణాంకం i, j, debug_type, g = check_global(t->ref);
        పూర్ణాంకం *n_forw_hash;
        నిర్మాణం _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	కొరకు (i = 0; i < *n_forw_hash; i++)
	    ఒకవేళ (t->ref == (*forw_hash)[i].type) {
		ఒకవేళ (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    కొరకు (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->దత్తాంశం +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.ప్రారంభం);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		కొరకు (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

స్థిర పూర్ణాంకం tcc_debug_కూడు(TCCState *s1, Sym *t, పూర్ణాంకం dwarf)
{
    పూర్ణాంకం స్థానభ్రంశం = dwarf ? dwarf_info_section->దత్తాంశం_స్థానభ్రంశం : ++debug_తదుపరి_type;
    పూర్ణాంకం *n_hash, g = check_global(t);
    నిర్మాణం _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (నిర్మాణం _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * పరిమాణం(**hash));
    (*hash)[*n_hash].debug_type = స్థానభ్రంశం;
    (*hash)[(*n_hash)++].type = t;
    తిరిగి స్థానభ్రంశం;
}

స్థిర పూర్ణాంకం STRUCT_NODEBUG(Sym *s)
{
    తిరిగి
    (s->a.nodebug ||
     ((s->v & ~SYM_క్షేత్రం) >= SYM_మొదటి_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

స్థిర పూర్ణాంకం stabs_struct_కనుగొను(TCCState *s1, Sym *t, పూర్ణాంకం *p_id)
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
    ఒకవేళ (ఖాళీ == p_id)
        తిరిగి s && !s->r && t->c >= 0;
    ఒకవేళ (ఖాళీ == s) {
        /* just use global_stack always */
        s = sym_push2(&global_దొంతర, SYM_క్షేత్రం|0x00DEBBED, 0, ++debug_తదుపరి_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    ఒకవేళ (s->r || t->c < 0) /* already defined or still incomplete */
        తిరిగి 0;
    s->r = 1;
    తిరిగి 1;
}

స్థిర పూర్ణాంకం remove_type_info(పూర్ణాంకం type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        ఒకవేళ ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        ఒకవేళ (!(type & VT_BITFIELD) && (type & VT_STRUCT_ముసుగు) > VT_ENUM)
	    type &= ~VT_STRUCT_ముసుగు;
	తిరిగి type;
}

స్థిర శూన్య tcc_get_debug_info(TCCState *s1, Sym *s, CString *ఫలితం)
{
    పూర్ణాంకం type;
    పూర్ణాంకం n = 0;
    పూర్ణాంకం debug_type = -1;
    Sym *t = s;
    CString str;

    కొరకు (;;) {
        type = remove_type_info (t->type.t);
        ఒకవేళ (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        లేకపోతే
            ఆపు;
    }
    ఒకవేళ ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        ఒకవేళ (stabs_struct_కనుగొను(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_మొదటి_ANOM
                         ? "" : get_tok_str(t->v, ఖాళీ),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            అయితే (t->తదుపరి) {
                పూర్ణాంకం pos, కొలత, align;
                t = t->తదుపరి;
		ఒకవేళ (STRUCT_NODEBUG(t))
		    కొనసాగు;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_క్షేత్రం) >= SYM_మొదటి_ANOM
                             ? "" : get_tok_str(t->v, ఖాళీ)
                             );
                tcc_get_debug_info (s1, t, &str);
                ఒకవేళ (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + బిట్టు_POS(t->type.t);
                    కొలత = బిట్టు_కొలత(t->type.t);
                }
                లేకపోతే {
                    pos = t->c * 8;
                    కొలత = type_కొలత(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, కొలత);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.దత్తాంశం, N_LSYM, 0, ఖాళీ, 0, 0);
            cstr_free (&str);
        }
    }
    లేకపోతే ఒకవేళ (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        ఒకవేళ (stabs_struct_కనుగొను(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_మొదటి_ANOM
                         ? "" : get_tok_str(t->v, ఖాళీ),
                         debug_type);
            అయితే (t->తదుపరి) {
                t = t->తదుపరి;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_క్షేత్రం) >= SYM_మొదటి_ANOM
                             ? "" : get_tok_str(t->v, ఖాళీ));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (పూర్ణాంకం)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.దత్తాంశం, N_LSYM, 0, ఖాళీ, 0, 0);
            cstr_free (&str);
	}
    }
    లేకపోతే ఒకవేళ ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_ముసుగు;
        కొరకు (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            ఒకవేళ (default_debug[debug_type - 1].type == type)
                ఆపు;
        ఒకవేళ (debug_type > N_DEFAULT_DEBUG)
            తిరిగి;
    }

    ఒకవేళ (ఖాళీ == ఫలితం) /* from stabs_struct_complete() */
        తిరిగి;

    ఒకవేళ (n > 0)
        cstr_printf (ఫలితం, "%d=", ++debug_తదుపరి_type);
    t = s;
    కొరకు (;;) {
        type = remove_type_info (t->type.t);
        ఒకవేళ (type == VT_PTR)
            cstr_printf (ఫలితం, "%d=*", ++debug_తదుపరి_type);
        లేకపోతే ఒకవేళ (type == (VT_PTR | VT_ARRAY))
            cstr_printf (ఫలితం, "%d=ar1;0;%d;",
                         ++debug_తదుపరి_type, t->type.ref->c - 1);
        లేకపోతే ఒకవేళ (type == VT_FUNC) {
            cstr_printf (ఫలితం, "%d=f", ++debug_తదుపరి_type);
            tcc_get_debug_info (s1, t->type.ref, ఫలితం);
            తిరిగి;
        }
        లేకపోతే
            ఆపు;
        t = t->type.ref;
    }
    cstr_printf (ఫలితం, "%d", debug_type);
}

స్థిర శూన్య stabs_struct_complete(TCCState *s1, CType *t)
{
    ఒకవేళ (stabs_struct_కనుగొను(s1, t->ref, ఖాళీ)) {
        Sym s = {0}; s.type = *t;
        tcc_get_debug_info(s1, &s, ఖాళీ);
    }
}

స్థిర పూర్ణాంకం tcc_get_dwarf_info(TCCState *s1, Sym *s)
{
    పూర్ణాంకం type;
    పూర్ణాంకం debug_type = -1;
    Sym *e, *t = s;
    పూర్ణాంకం i;
    పూర్ణాంకం చివరి_pos = -1;
    పూర్ణాంకం retval;

    ఒకవేళ (new_file)
        put_new_file(s1);
    కొరకు (;;) {
        type = remove_type_info (t->type.t);
        ఒకవేళ (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        లేకపోతే
            ఆపు;
    }
    ఒకవేళ ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_కనుగొను(s1, t, 1);
	ఒకవేళ (debug_type == -1) {
	    పూర్ణాంకం pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_కూడు(s1, t, 1);
	    e = t;
	    i = 0;
	    అయితే (e->తదుపరి) {
		e = e->తదుపరి;
		ఒకవేళ (STRUCT_NODEBUG(e))
		    కొనసాగు;
		i++;
	    }
	    pos_type = (పూర్ణాంకం *) tcc_malloc(i * పరిమాణం(పూర్ణాంకం));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->తదుపరి ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_ఖాళీలు_TYPE
		        : t->తదుపరి ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_ఖాళీలు_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_మొదటి_ANOM
                       ? "" : get_tok_str(t->v, ఖాళీ));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_పంక్తి.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->పంక్తి_అంకె);
	    ఒకవేళ (t->తదుపరి) {
	        pos_sib = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            అయితే (e->తదుపరి) {
                e = e->తదుపరి;
		ఒకవేళ (STRUCT_NODEBUG(e))
		    కొనసాగు;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, ఖాళీ));
		dwarf_uleb128(dwarf_info_section, dwarf_పంక్తి.cur_file);
		dwarf_uleb128(dwarf_info_section, file->పంక్తి_అంకె);
		pos_type[i++] = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
		dwarf_data4(dwarf_info_section, 0);
                ఒకవేళ (e->type.t & VT_BITFIELD) {
                    పూర్ణాంకం pos = e->c * 8 + బిట్టు_POS(e->type.t);
                    పూర్ణాంకం కొలత = బిట్టు_కొలత(e->type.t);

		    dwarf_uleb128(dwarf_info_section, కొలత);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		లేకపోతే
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    ఒకవేళ (t->తదుపరి) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->దత్తాంశం + pos_sib,
		          dwarf_info_section->దత్తాంశం_స్థానభ్రంశం - dwarf_info.ప్రారంభం);
	    }
	    e = t;
	    i = 0;
	    అయితే (e->తదుపరి) {
		e = e->తదుపరి;
		ఒకవేళ (STRUCT_NODEBUG(e))
		    కొనసాగు;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->దత్తాంశం + pos_type[i++],
			  type - dwarf_info.ప్రారంభం);
	    }
	    tcc_free(pos_type);
        }
    }
    లేకపోతే ఒకవేళ (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_కనుగొను(s1, t, 1);
	ఒకవేళ (debug_type == -1) {
	    పూర్ణాంకం pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_కూడు(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_మొదటి_ANOM
                       ? "" : get_tok_str(t->v, ఖాళీ));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.ప్రారంభం);
	    dwarf_uleb128(dwarf_info_section, dwarf_పంక్తి.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->పంక్తి_అంకె);
	    pos_sib = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            అయితే (e->తదుపరి) {
                e = e->తదుపరి;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_క్షేత్రం) >= SYM_మొదటి_ANOM
                           ? "" : get_tok_str(e->v, ఖాళీ));
		ఒకవేళ (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		లేకపోతే
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->దత్తాంశం + pos_sib,
		      dwarf_info_section->దత్తాంశం_స్థానభ్రంశం - dwarf_info.ప్రారంభం);
	}
    }
    లేకపోతే ఒకవేళ ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_ముసుగు;
        కొరకు (i = 1; i <= N_DEFAULT_DEBUG; i++)
            ఒకవేళ (default_debug[i - 1].type == type)
                ఆపు;
        ఒకవేళ (i > N_DEFAULT_DEBUG)
            తిరిగి 0;
	debug_type = dwarf_info.పునాది_type_వాడిన[i - 1];
	ఒకవేళ (debug_type == 0) {
	    అక్షరం name[100];

	    debug_type = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_పునాది_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].కొలత);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, పరిమాణం name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.పునాది_type_వాడిన[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = ఖాళీ;
    t = s;
    కొరకు (;;) {
        type = remove_type_info (t->type.t);
        ఒకవేళ (type == VT_PTR) {
	    i = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
	    ఒకవేళ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_సూచిక);
	    dwarf_data1(dwarf_info_section, PTR_కొలత);
	    ఒకవేళ (చివరి_pos != -1) {
		tcc_debug_check_forw(s1, e, చివరి_pos);
		write32le(dwarf_info_section->దత్తాంశం + చివరి_pos,
			  i - dwarf_info.ప్రారంభం);
	    }
	    చివరి_pos = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        లేకపోతే ఒకవేళ (type == (VT_PTR | VT_ARRAY)) {
	    పూర్ణాంకం sib_pos, sub_type;
#ఒకవేళ LONG_కొలత == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#లేకపోతే
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#అయితే_ముగింపు

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
	    ఒకవేళ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    ఒకవేళ (చివరి_pos != -1) {
		tcc_debug_check_forw(s1, e, చివరి_pos);
		write32le(dwarf_info_section->దత్తాంశం + చివరి_pos,
			  i - dwarf_info.ప్రారంభం);
	    }
	    చివరి_pos = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
	    dwarf_data4(dwarf_info_section, 0);
	    కొరకు (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.ప్రారంభం);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		ఒకవేళ (type != (VT_PTR | VT_ARRAY))
		    ఆపు;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->దత్తాంశం + sib_pos,
		      dwarf_info_section->దత్తాంశం_స్థానభ్రంశం - dwarf_info.ప్రారంభం);
	}
        లేకపోతే ఒకవేళ (type == VT_FUNC) {
	    పూర్ణాంకం sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    ఒకవేళ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->తదుపరి ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_ఖాళీలు_TYPE);
	    ఒకవేళ (చివరి_pos != -1) {
		tcc_debug_check_forw(s1, e, చివరి_pos);
		write32le(dwarf_info_section->దత్తాంశం + చివరి_pos,
			  i - dwarf_info.ప్రారంభం);
	    }
	    చివరి_pos = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    ఒకవేళ (t->type.ref->తదుపరి) {
	        sib_pos = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    అయితే (f->తదుపరి) {
		f = f->తదుపరి;
		i++;
	    }
	    pos_type = (పూర్ణాంకం *) tcc_malloc(i * పరిమాణం(పూర్ణాంకం));
	    f = t->type.ref;
	    i = 0;
	    అయితే (f->తదుపరి) {
		f = f->తదుపరి;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    ఒకవేళ (t->type.ref->తదుపరి) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->దత్తాంశం + sib_pos,
		          dwarf_info_section->దత్తాంశం_స్థానభ్రంశం - dwarf_info.ప్రారంభం);
	    }
	    f = t->type.ref;
	    i = 0;
	    అయితే (f->తదుపరి) {
		f = f->తదుపరి;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->దత్తాంశం + pos_type[i++],
                          type - dwarf_info.ప్రారంభం);
	    }
	    tcc_free(pos_type);
        }
        లేకపోతే {
	    ఒకవేళ (చివరి_pos != -1) {
		tcc_debug_check_forw(s1, e, చివరి_pos);
		write32le(dwarf_info_section->దత్తాంశం + చివరి_pos,
			  debug_type - dwarf_info.ప్రారంభం);
	    }
            ఆపు;
	}
        t = t->type.ref;
    }
    తిరిగి retval;
}

స్థిర శూన్య tcc_debug_ముగింపు (TCCState *s1, నిర్మాణం _debug_info *cur)
{
    అయితే (cur) {
        నిర్మాణం _debug_info *తదుపరి = cur->తదుపరి;
        పూర్ణాంకం i;

        ఒకవేళ (s1->dwarf) {

            కొరకు (i = cur->n_sym - 1; i >= 0; i--) {
                నిర్మాణం debug_sym *s = &cur->sym[i];

		dwarf_data1(dwarf_info_section,
                            s->type == N_PSYM
			    ? DWARF_ABBREV_FORMAL_PARAMETER
			    : s->type == N_GSYM
                            ? DWARF_ABBREV_VARIABLE_EXTERNAL
                            : s->type == N_STSYM
			    ? DWARF_ABBREV_VARIABLE_STATIC
			    : DWARF_ABBREV_VARIABLE_LOCAL);
                dwarf_strp(dwarf_info_section, s->str);
		ఒకవేళ (s->type == N_GSYM || s->type == N_STSYM) {
                    dwarf_uleb128(dwarf_info_section, s->file);
                    dwarf_uleb128(dwarf_info_section, s->పంక్తి);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.ప్రారంభం);
		ఒకవేళ (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    ఒకవేళ (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_కొలత + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    ఒకవేళ (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_దత్తాంశం_PTR);
#ఒకవేళ PTR_కొలత == 4
                    dwarf_data4(dwarf_info_section, s->విలువ);
#లేకపోతే
                    dwarf_data8(dwarf_info_section, s->విలువ);
#అయితే_ముగింపు
		}
		లేకపోతే {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_కొలత((దీర్ఘ)s->విలువ) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (దీర్ఘ)s->విలువ);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->బిడ్డ ? DWARF_ABBREV_LEXICAL_ఖండం
			           : DWARF_ABBREV_LEXICAL_ఖాళీలు_ఖండం);
            dwarf_reloc(dwarf_info_section, section_sym, R_దత్తాంశం_PTR);
#ఒకవేళ PTR_కొలత == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->ప్రారంభం);
            dwarf_data4(dwarf_info_section, cur->చివర - cur->ప్రారంభం);
#లేకపోతే
            dwarf_data8(dwarf_info_section, func_ind + cur->ప్రారంభం);
            dwarf_data8(dwarf_info_section, cur->చివర - cur->ప్రారంభం);
#అయితే_ముగింపు
            tcc_debug_ముగింపు (s1, cur->బిడ్డ);
	    ఒకవేళ (cur->బిడ్డ)
                dwarf_data1(dwarf_info_section, 0);
        }
        లేకపోతే
        {
            కొరకు (i = 0; i < cur->n_sym; i++) {
                నిర్మాణం debug_sym *s = &cur->sym[i];

                ఒకవేళ (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->విలువ,
                                s->sec, s->sym_సూచీ);
                లేకపోతే
                    put_stabs(s1, s->str, s->type, 0, 0, s->విలువ);
                tcc_free (s->str);
            }
            tcc_free (cur->sym);
            put_stabn(s1, N_LBRAC, 0, 0, cur->ప్రారంభం);
            tcc_debug_ముగింపు (s1, cur->బిడ్డ);
            put_stabn(s1, N_RBRAC, 0, 0, cur->చివర);
        }
        tcc_free (cur);
        cur = తదుపరి;
    }
}

ST_FUNC శూన్య tcc_కూడు_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    పూర్ణాంకం param;

    ఒకవేళ (!(s1->do_debug & 2))
        తిరిగి;

    cstr_new (&debug_str);
    param = !e;
    కొరకు (; s != e; s = s->prev) {
        ఒకవేళ (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            కొనసాగు;
	ఒకవేళ (s1->dwarf) {
	    tcc_debug_stabs(s1, get_tok_str(s->v, ఖాళీ),
			    param ? N_PSYM : N_LSYM, s->c, ఖాళీ, 0,
			    tcc_get_dwarf_info(s1, s));
	}
	లేకపోతే
        {
            cstr_reset (&debug_str);
            cstr_printf (&debug_str, "%s:%s", get_tok_str(s->v, ఖాళీ),
			 param ? "p" : "");
            tcc_get_debug_info(s1, s, &debug_str);
            tcc_debug_stabs(s1, debug_str.దత్తాంశం, param ? N_PSYM : N_LSYM,
			    s->c, ఖాళీ, 0, 0);
	}
    }
    cstr_free (&debug_str);
}

/* put function symbol */
ST_FUNC శూన్య tcc_debug_funcstart(TCCState *s1, Sym *sym)
{
    CString debug_str;
    BufferedFile *f;

    ఒకవేళ (!s1->do_debug)
        తిరిగి;
    debug_info_మూలం = ఖాళీ;
    debug_info = ఖాళీ;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    ఒకవేళ (!f)
	తిరిగి;

    ఒకవేళ (s1->dwarf) {
        tcc_debug_పంక్తి(s1);
        dwarf_info.func = sym;
        dwarf_info.పంక్తి = file->పంక్తి_అంకె;
	ఒకవేళ (s1->do_backtrace) {
	    పూర్ణాంకం i, len;

	    dwarf_పంక్తి_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, అక్షరశ్రేణి_పొడవు(funcname) + 2);
	    dwarf_పంక్తి_op(s1, DW_LNE_hi_user - 1);
	    len = అక్షరశ్రేణి_పొడవు(funcname) + 1;
	    కొరకు (i = 0; i < len; i++)
		dwarf_పంక్తి_op(s1, funcname[i]);
	}
    }
    లేకపోతే
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.దత్తాంశం, N_FUN, 0, f->పంక్తి_అంకె, 0, cur_పాఠ్యం_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_పంక్తి(s1);
    }
}

ST_FUNC శూన్య tcc_debug_prolog_epilog(TCCState *s1, పూర్ణాంకం విలువ)
{
    ఒకవేళ (!s1->do_debug)
        తిరిగి;
    ఒకవేళ (s1->dwarf) {
	dwarf_పంక్తి_op(s1, విలువ == 0 ? DW_LNS_సమితి_prologue_చివర
				     : DW_LNS_సమితి_epilogue_begin);
    }
}

/* put function size */
ST_FUNC శూన్య tcc_debug_funcend(TCCState *s1, పూర్ణాంకం కొలత)
{
    /* lldb does not like function end and next function start at same pc */
    పూర్ణాంకం min_instr_len;

#ఒకవేళ TCC_EH_చట్రం
    tcc_debug_చట్రం_చివర(s1, కొలత);
#అయితే_ముగింపు
    ఒకవేళ (!s1->do_debug)
        తిరిగి;
    min_instr_len = dwarf_పంక్తి.చివరి_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_పంక్తి(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, కొలత);
    ఒకవేళ (s1->dwarf) {
        పూర్ణాంకం func_sib = 0;
	Sym *sym = dwarf_info.func;
	పూర్ణాంకం n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        ఒకవేళ ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_పంక్తి.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.పంక్తి);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->దత్తాంశం_స్థానభ్రంశం);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.ప్రారంభం);
        dwarf_reloc(dwarf_info_section, section_sym, R_దత్తాంశం_PTR);
#ఒకవేళ PTR_కొలత == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, కొలత); // high_pc
#లేకపోతే
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, కొలత); // high_pc
#అయితే_ముగింపు
        func_sib = dwarf_info_section->దత్తాంశం_స్థానభ్రంశం;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#ఒకవేళ defined(TCC_లక్ష్యం_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#లేదావేళ defined(TCC_లక్ష్యం_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#లేదావేళ defined TCC_లక్ష్యం_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#లేదావేళ defined TCC_లక్ష్యం_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#లేదావేళ defined TCC_లక్ష్యం_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#లేకపోతే
        dwarf_data1(dwarf_info_section, DW_OP_call_చట్రం_cfa);
#అయితే_ముగింపు
        tcc_debug_ముగింపు (s1, debug_info_మూలం);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->దత్తాంశం + func_sib,
                  dwarf_info_section->దత్తాంశం_స్థానభ్రంశం - dwarf_info.ప్రారంభం);
    }
    లేకపోతే
    {
        tcc_debug_ముగింపు (s1, debug_info_మూలం);
    }
    debug_info_మూలం = 0;
}


ST_FUNC శూన్య tcc_debug_extern_sym(TCCState *s1, Sym *sym, పూర్ణాంకం sh_అంకె, పూర్ణాంకం sym_bind, పూర్ణాంకం sym_type)
{
    ఒకవేళ (!(s1->do_debug & 2))
        తిరిగి;

    ఒకవేళ (sym_type == STT_FUNC || sym->v >= SYM_మొదటి_ANOM)
        తిరిగి;
    ఒకవేళ (s1->dwarf) {
        పూర్ణాంకం debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, ఖాళీ));
	dwarf_uleb128(dwarf_info_section, dwarf_పంక్తి.cur_file);
	dwarf_uleb128(dwarf_info_section, file->పంక్తి_అంకె);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->దత్తాంశం_స్థానభ్రంశం);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.ప్రారంభం);
	ఒకవేళ (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_కొలత + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->దత్తాంశం_స్థానభ్రంశం,
		R_దత్తాంశం_PTR, 0);
#ఒకవేళ PTR_కొలత == 4
	dwarf_data4(dwarf_info_section, 0);
#లేకపోతే
	dwarf_data8(dwarf_info_section, 0);
#అయితే_ముగింపు
    }
    లేకపోతే
    {
        Section *s = sh_అంకె == SHN_COMMON ? common_section
					  : s1->sections[sh_అంకె];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, ఖాళీ),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        ఒకవేళ (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.దత్తాంశం, N_GSYM, 0, ఖాళీ, 0, 0);
        లేకపోతే
            tcc_debug_stabs(s1, str.దత్తాంశం,
                (sym->type.t & VT_STATIC) && దత్తాంశం_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC శూన్య tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    ఒకవేళ (!(s1->do_debug & 2))
        తిరిగి;

    ఒకవేళ (s1->dwarf) {
	పూర్ణాంకం debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	ఒకవేళ (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, ఖాళీ));
	    dwarf_uleb128(dwarf_info_section, dwarf_పంక్తి.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->పంక్తి_అంకె);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->దత్తాంశం_స్థానభ్రంశం);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.ప్రారంభం);
	}
    }
    లేకపోతే
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, ఖాళీ));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.దత్తాంశం, N_LSYM, 0, ఖాళీ, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC శూన్య tcc_tcov_ఖండం_చివర(TCCState *s1, పూర్ణాంకం పంక్తి);

ST_FUNC శూన్య tcc_tcov_ఖండం_begin(TCCState *s1)
{
    SValue sv;
    శూన్య *ptr;
    గుర్తులేని దీర్ఘ చివరి_స్థానభ్రంశం = tcov_దత్తాంశం.స్థానభ్రంశం;

    tcc_tcov_ఖండం_చివర (tcc_state, 0);
    ఒకవేళ (s1->test_coverage == 0 || nocode_wanted)
	తిరిగి;

    ఒకవేళ (tcov_దత్తాంశం.చివరి_file_name == 0 ||
	strcmp ((స్థిరరాశి అక్షరం *)(tcov_section->దత్తాంశం + tcov_దత్తాంశం.చివరి_file_name),
		file->true_filename) != 0) {
	అక్షరం wd[1024];
	CString cstr;

	ఒకవేళ (tcov_దత్తాంశం.చివరి_func_name)
	    section_ptr_కూడు(tcov_section, 1);
	ఒకవేళ (tcov_దత్తాంశం.చివరి_file_name)
	    section_ptr_కూడు(tcov_section, 1);
	tcov_దత్తాంశం.చివరి_func_name = 0;
	cstr_new (&cstr);
	ఒకవేళ (file->true_filename[0] == '/') {
	    tcov_దత్తాంశం.చివరి_file_name = tcov_section->దత్తాంశం_స్థానభ్రంశం;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	లేకపోతే {
	    getcwd (wd, పరిమాణం(wd));
	    tcov_దత్తాంశం.చివరి_file_name = tcov_section->దత్తాంశం_స్థానభ్రంశం + అక్షరశ్రేణి_పొడవు(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_కూడు(tcov_section, cstr.కొలత + 1);
	strcpy((అక్షరం *)ptr, cstr.దత్తాంశం);
#నిర్వచితమైతే _WIN32
        normalize_slashes((అక్షరం *)ptr);
#అయితే_ముగింపు
	cstr_free (&cstr);
    }
    ఒకవేళ (tcov_దత్తాంశం.చివరి_func_name == 0 ||
	strcmp ((స్థిరరాశి అక్షరం *)(tcov_section->దత్తాంశం + tcov_దత్తాంశం.చివరి_func_name),
		funcname) != 0) {
	కొలత_t len;

	ఒకవేళ (tcov_దత్తాంశం.చివరి_func_name)
	    section_ptr_కూడు(tcov_section, 1);
	tcov_దత్తాంశం.చివరి_func_name = tcov_section->దత్తాంశం_స్థానభ్రంశం;
	len = అక్షరశ్రేణి_పొడవు (funcname);
	ptr = section_ptr_కూడు(tcov_section, len + 1);
	strcpy((అక్షరం *)ptr, funcname);
	section_ptr_కూడు(tcov_section, -tcov_section->దత్తాంశం_స్థానభ్రంశం & 7);
	ptr = section_ptr_కూడు(tcov_section, 8);
	write64le (ptr, file->పంక్తి_అంకె);
    }
    ఒకవేళ (ind == tcov_దత్తాంశం.ind && tcov_దత్తాంశం.పంక్తి == file->పంక్తి_అంకె)
        tcov_దత్తాంశం.స్థానభ్రంశం = చివరి_స్థానభ్రంశం;
    లేకపోతే {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_కూడు(tcov_section, 16);
        tcov_దత్తాంశం.పంక్తి = file->పంక్తి_అంకె;
        write64le (ptr, (tcov_దత్తాంశం.పంక్తి << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((గుర్తులేని అక్షరం *)ptr - tcov_section->దత్తాంశం) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#ఒకవేళ defined TCC_లక్ష్యం_I386 || defined TCC_లక్ష్యం_X86_64 || \
    defined TCC_లక్ష్యం_ARM || defined TCC_లక్ష్యం_ARM64 || \
    defined TCC_లక్ష్యం_RISCV64
        gen_increment_tcov (&sv);
#లేకపోతే
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#అయితే_ముగింపు
        tcov_దత్తాంశం.స్థానభ్రంశం = (గుర్తులేని అక్షరం *)ptr - tcov_section->దత్తాంశం;
        tcov_దత్తాంశం.ind = ind;
    }
}

ST_FUNC శూన్య tcc_tcov_ఖండం_చివర(TCCState *s1, పూర్ణాంకం పంక్తి)
{
    ఒకవేళ (s1->test_coverage == 0)
	తిరిగి;
    ఒకవేళ (పంక్తి == -1)
        పంక్తి = tcov_దత్తాంశం.పంక్తి;
    ఒకవేళ (tcov_దత్తాంశం.స్థానభ్రంశం) {
	శూన్య *ptr = tcov_section->దత్తాంశం + tcov_దత్తాంశం.స్థానభ్రంశం;
	గుర్తులేని దీర్ఘ దీర్ఘ nline = పంక్తి ? పంక్తి : file->పంక్తి_అంకె;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_దత్తాంశం.స్థానభ్రంశం = 0;
    }
}

ST_FUNC శూన్య tcc_tcov_check_పంక్తి(TCCState *s1, పూర్ణాంకం ప్రారంభం)
{
    ఒకవేళ (s1->test_coverage == 0)
	తిరిగి;
    ఒకవేళ (tcov_దత్తాంశం.పంక్తి != file->పంక్తి_అంకె) {
        ఒకవేళ ((tcov_దత్తాంశం.పంక్తి + 1) != file->పంక్తి_అంకె) {
	    tcc_tcov_ఖండం_చివర (s1, -1);
	    ఒకవేళ (ప్రారంభం)
                tcc_tcov_ఖండం_begin (s1);
	}
	లేకపోతే
	    tcov_దత్తాంశం.పంక్తి = file->పంక్తి_అంకె;
    }
}

ST_FUNC శూన్య tcc_tcov_ప్రారంభం(TCCState *s1)
{
    ఒకవేళ (s1->test_coverage == 0)
	తిరిగి;
    ఒకవేళ (!s1->dState)
        s1->dState = tcc_mallocz(పరిమాణం *s1->dState);
    memset (&tcov_దత్తాంశం, 0, పరిమాణం (tcov_దత్తాంశం));
    ఒకవేళ (tcov_section == ఖాళీ) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_కూడు(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC శూన్య tcc_tcov_చివర(TCCState *s1)
{
    ఒకవేళ (s1->test_coverage == 0)
	తిరిగి;
    ఒకవేళ (tcov_దత్తాంశం.చివరి_func_name)
        section_ptr_కూడు(tcov_section, 1);
    ఒకవేళ (tcov_దత్తాంశం.చివరి_file_name)
        section_ptr_కూడు(tcov_section, 1);
}

ST_FUNC శూన్య tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_దత్తాంశం.ind = 0;
}

/* ------------------------------------------------------------------------- */
#నిర్వచనం_రద్దు చివరి_పంక్తి_అంకె
#నిర్వచనం_రద్దు new_file
#నిర్వచనం_రద్దు section_sym
#నిర్వచనం_రద్దు debug_తదుపరి_type
#నిర్వచనం_రద్దు debug_hash_global
#నిర్వచనం_రద్దు debug_hash_local
#నిర్వచనం_రద్దు n_debug_hash_global
#నిర్వచనం_రద్దు n_debug_hash_local
#నిర్వచనం_రద్దు debug_forw_hash_global
#నిర్వచనం_రద్దు debug_forw_hash_local
#నిర్వచనం_రద్దు n_debug_forw_hash_global
#నిర్వచనం_రద్దు n_debug_forw_hash_local
#నిర్వచనం_రద్దు debug_info
#నిర్వచనం_రద్దు debug_info_మూలం
#నిర్వచనం_రద్దు dwarf_sym
#నిర్వచనం_రద్దు dwarf_పంక్తి
#నిర్వచనం_రద్దు dwarf_info
#నిర్వచనం_రద్దు dwarf_str
#నిర్వచనం_రద్దు dwarf_పంక్తి_str
#నిర్వచనం_రద్దు tcov_దత్తాంశం
