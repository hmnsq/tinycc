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

#अन्तर्भाव "tcc.h"

/* stab debug support */

स्थिर ध्रुव संरचना {
  पूर्णाङ्क type;
  पूर्णाङ्क आकार;
  पूर्णाङ्क encoding;
  ध्रुव वर्ण *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#यदि LONG_आकार == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#अन्यथा
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#यदि_अन्तः
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#यदि LONG_आकार == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#अन्यथा
    /* use octal instead of -1 so size_t works (-gstabs+ in gcc) */
    {   VT_LLONG | VT_LONG | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t5=r5;0;01777777777777777777777;" },
#यदि_अन्तः
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
#यदि_परिभाषितम् TCC_USING_DOUBLE_FOR_LDOUBLE
    {   VT_DOUBLE | VT_LONG, 8, DW_ATE_float, "long double:t16=r1;8;0;" },
#अन्यथा
    {   VT_LDOUBLE, 16, DW_ATE_float, "long double:t16=r1;16;0;" },
#यदि_अन्तः
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
#यदि LONG_आकार == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#अन्यथा
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#यदि_अन्तः
};

#परिभाषय	N_DEFAULT_DEBUG	(परिमाण (default_debug) / परिमाण (default_debug[0]))

/* dwarf debug */

#परिभाषय	DWARF_पङ्क्तिः_आधारः				-5
#परिभाषय	DWARF_पङ्क्तिः_RANGE			14
#परिभाषय	DWARF_OPCODE_आधारः			13

#यदि defined TCC_TARGET_ARM64
#परिभाषय	DWARF_MIN_INSTR_LEN			4
#नोचेद्यदि defined TCC_TARGET_ARM
#परिभाषय	DWARF_MIN_INSTR_LEN			2
#अन्यथा
#परिभाषय	DWARF_MIN_INSTR_LEN			1
#यदि_अन्तः

#परिभाषय	DWARF_ABBREV_COMPILE_UNIT		1
#परिभाषय	DWARF_ABBREV_आधारः_TYPE			2
#परिभाषय	DWARF_ABBREV_VARIABLE_EXTERNAL		3
#परिभाषय	DWARF_ABBREV_VARIABLE_STATIC		4
#परिभाषय	DWARF_ABBREV_VARIABLE_LOCAL		5
#परिभाषय	DWARF_ABBREV_FORMAL_PARAMETER		6
#परिभाषय	DWARF_ABBREV_POINTER			7
#परिभाषय	DWARF_ABBREV_ARRAY_TYPE			8
#परिभाषय	DWARF_ABBREV_SUBRANGE_TYPE		9
#परिभाषय	DWARF_ABBREV_TYPEDEF			10
#परिभाषय	DWARF_ABBREV_ENUMERATOR_SIGNED		11
#परिभाषय	DWARF_ABBREV_ENUMERATOR_UNSIGNED	12
#परिभाषय	DWARF_ABBREV_ENUMERATION_TYPE		13
#परिभाषय	DWARF_ABBREV_MEMBER			14
#परिभाषय	DWARF_ABBREV_MEMBER_BF			15
#परिभाषय	DWARF_ABBREV_STRUCTURE_TYPE		16
#परिभाषय	DWARF_ABBREV_STRUCTURE_रिक्तानि_TYPE	17
#परिभाषय	DWARF_ABBREV_UNION_TYPE			18
#परिभाषय	DWARF_ABBREV_UNION_रिक्तानि_TYPE		19
#परिभाषय	DWARF_ABBREV_SUBPROGRAM_EXTERNAL	20
#परिभाषय	DWARF_ABBREV_SUBPROGRAM_STATIC		21
#परिभाषय	DWARF_ABBREV_LEXICAL_खण्डम्		22
#परिभाषय	DWARF_ABBREV_LEXICAL_रिक्तानि_खण्डम्	23
#परिभाषय	DWARF_ABBREV_SUBROUTINE_TYPE		24
#परिभाषय	DWARF_ABBREV_SUBROUTINE_रिक्तानि_TYPE	25
#परिभाषय	DWARF_ABBREV_FORMAL_PARAMETER2		26

/* all entries should have been generated with dwarf_uleb128 except
   has_children. All values are currently below 128 so this currently
   works.  */
स्थिर ध्रुव अचिह्नित वर्ण dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_चिह्नकम्_compile_unit, 1,
          DW_AT_उत्पादकः, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_पङ्क्तिः_strp,
          DW_AT_comp_dir, DW_FORM_पङ्क्तिः_strp,
          DW_AT_नीचः_pc, DW_FORM_addr,
#यदि PTR_आकार == 4
          DW_AT_उच्चः_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_उच्चः_pc, DW_FORM_data8,
#यदि_अन्तः
          DW_AT_stmt_list, DW_FORM_sec_विस्थापनम्,
          0, 0,
    DWARF_ABBREV_आधारः_TYPE, DW_चिह्नकम्_आधारः_type, 0,
          DW_AT_byte_आकार, DW_FORM_udata,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_name, DW_FORM_strp,
          0, 0,
    DWARF_ABBREV_VARIABLE_EXTERNAL, DW_चिह्नकम्_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्तिः, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_चिह्नकम्_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्तिः, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_LOCAL, DW_चिह्नकम्_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER, DW_चिह्नकम्_formal_parameter, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_POINTER, DW_चिह्नकम्_pointer_type, 0,
          DW_AT_byte_आकार, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ARRAY_TYPE, DW_चिह्नकम्_array_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBRANGE_TYPE, DW_चिह्नकम्_subrange_type, 0,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ऊर्ध्वस्थम्_bound, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_TYPEDEF, DW_चिह्नकम्_typedef, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्तिः, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_चिह्नकम्_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_मानम्, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_चिह्नकम्_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_मानम्, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_चिह्नकम्_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_आकार, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्तिः, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_चिह्नकम्_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्तिः, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_दत्त_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_चिह्नकम्_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्तिः, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_bit_आकार, DW_FORM_udata,
          DW_AT_दत्त_bit_विस्थापनम्, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_चिह्नकम्_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_आकार, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्तिः, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_रिक्तानि_TYPE, DW_चिह्नकम्_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_आकार, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्तिः, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_चिह्नकम्_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_आकार, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्तिः, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_रिक्तानि_TYPE, DW_चिह्नकम्_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_आकार, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्तिः, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_चिह्नकम्_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्तिः, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_नीचः_pc, DW_FORM_addr,
#यदि PTR_आकार == 4
          DW_AT_उच्चः_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_उच्चः_pc, DW_FORM_data8,
#यदि_अन्तः
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_आधारः, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_चिह्नकम्_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्तिः, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_नीचः_pc, DW_FORM_addr,
#यदि PTR_आकार == 4
          DW_AT_उच्चः_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_उच्चः_pc, DW_FORM_data8,
#यदि_अन्तः
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_आधारः, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_खण्डम्, DW_चिह्नकम्_lexical_खण्डम्, 1,
          DW_AT_नीचः_pc, DW_FORM_addr,
#यदि PTR_आकार == 4
          DW_AT_उच्चः_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_उच्चः_pc, DW_FORM_data8,
#यदि_अन्तः
          0, 0,
    DWARF_ABBREV_LEXICAL_रिक्तानि_खण्डम्, DW_चिह्नकम्_lexical_खण्डम्, 0,
          DW_AT_नीचः_pc, DW_FORM_addr,
#यदि PTR_आकार == 4
          DW_AT_उच्चः_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_उच्चः_pc, DW_FORM_data8,
#यदि_अन्तः
          0, 0,
    DWARF_ABBREV_SUBROUTINE_TYPE, DW_चिह्नकम्_subroutine_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBROUTINE_रिक्तानि_TYPE, DW_चिह्नकम्_subroutine_type, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER2, DW_चिह्नकम्_formal_parameter, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
  0
};

स्थिर ध्रुव अचिह्नित वर्ण dwarf_पङ्क्तिः_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#परिभाषय N_STR_HASH (251)

संरचना dwarf_str_hash {
    पूर्णाङ्क len;
    अचिह्नित दीर्घ दत्त_विस्थापनम्;
    संरचना dwarf_str_hash *अग्र;
};

संरचना _tccdbg {

    पूर्णाङ्क चरमः_पङ्क्तिः_अङ्कः, new_file;
    पूर्णाङ्क section_sym;

    पूर्णाङ्क debug_अग्र_type;

    संरचना _debug_hash {
        पूर्णाङ्क debug_type;
        Sym *type;
    } *debug_hash_global, *debug_hash_local;

    /* store forward structure/unions types */
    संरचना _debug_forw_hash {
        Sym *type;
        पूर्णाङ्क n_debug_type;
        पूर्णाङ्क *debug_type;
    } *debug_forw_hash_global, *debug_forw_hash_local;

    पूर्णाङ्क n_debug_hash_global;
    पूर्णाङ्क n_debug_hash_local;
    पूर्णाङ्क n_debug_forw_hash_global;
    पूर्णाङ्क n_debug_forw_hash_local;

    संरचना _debug_info {
        पूर्णाङ्क start;
        पूर्णाङ्क अन्तः;
        पूर्णाङ्क चरमः_debug_hash;
        पूर्णाङ्क चरमः_debug_forw_hash;
        पूर्णाङ्क n_sym;
        संरचना debug_sym {
            पूर्णाङ्क type;
            अचिह्नित दीर्घ मानम्;
            वर्ण *str;
            Section *sec;
            पूर्णाङ्क sym_सूचकांक;
            पूर्णाङ्क info;
            पूर्णाङ्क file;
            पूर्णाङ्क पङ्क्तिः;
        } *sym;
        संरचना _debug_info *child, *अग्र, *चरमः, *parent;
    } *debug_info, *debug_info_मूलम्;

    संरचना {
        पूर्णाङ्क info;
        पूर्णाङ्क abbrev;
        पूर्णाङ्क पङ्क्तिः;
        पूर्णाङ्क str;
        पूर्णाङ्क पङ्क्तिः_str;
    } dwarf_sym;

    संरचना {
        पूर्णाङ्क start;
        पूर्णाङ्क dir_आकार;
        वर्ण **dir_सारणी;
        पूर्णाङ्क filename_आकार;
        संरचना dwarf_filename_struct {
            पूर्णाङ्क dir_प्रविष्टिः;
            वर्ण *name;
        } *filename_सारणी;
        पूर्णाङ्क पङ्क्तिः_आकार;
        पूर्णाङ्क पङ्क्तिः_max_आकार;
        अचिह्नित वर्ण *पङ्क्तिः_दत्त;
        पूर्णाङ्क cur_file;
        पूर्णाङ्क चरमः_file;
        पूर्णाङ्क चरमः_pc;
        पूर्णाङ्क चरमः_पङ्क्तिः;
    } dwarf_पङ्क्तिः;

    संरचना {
        पूर्णाङ्क start;
        Sym *func;
        पूर्णाङ्क पङ्क्तिः;
        पूर्णाङ्क आधारः_type_प्रयुक्तम्[N_DEFAULT_DEBUG];
    } dwarf_info;

    संरचना dwarf_str_hash *dwarf_str[N_STR_HASH];
    संरचना dwarf_str_hash *dwarf_पङ्क्तिः_str[N_STR_HASH];

    /* test coverage */
    संरचना {
        अचिह्नित दीर्घ विस्थापनम्;
        अचिह्नित दीर्घ चरमः_file_name;
        अचिह्नित दीर्घ चरमः_func_name;
        पूर्णाङ्क ind;
        पूर्णाङ्क पङ्क्तिः;
    } tcov_दत्त;
};

#परिभाषय चरमः_पङ्क्तिः_अङ्कः             s1->dState->चरमः_पङ्क्तिः_अङ्कः
#परिभाषय new_file                  s1->dState->new_file
#परिभाषय section_sym               s1->dState->section_sym
#परिभाषय debug_अग्र_type           s1->dState->debug_अग्र_type
#परिभाषय debug_hash_global         s1->dState->debug_hash_global
#परिभाषय debug_hash_local          s1->dState->debug_hash_local
#परिभाषय debug_forw_hash_global    s1->dState->debug_forw_hash_global
#परिभाषय debug_forw_hash_local     s1->dState->debug_forw_hash_local
#परिभाषय n_debug_hash_global       s1->dState->n_debug_hash_global
#परिभाषय n_debug_hash_local        s1->dState->n_debug_hash_local
#परिभाषय n_debug_forw_hash_global  s1->dState->n_debug_forw_hash_global
#परिभाषय n_debug_forw_hash_local   s1->dState->n_debug_forw_hash_local
#परिभाषय debug_info                s1->dState->debug_info
#परिभाषय debug_info_मूलम्           s1->dState->debug_info_मूलम्
#परिभाषय dwarf_sym                 s1->dState->dwarf_sym
#परिभाषय dwarf_पङ्क्तिः                s1->dState->dwarf_पङ्क्तिः
#परिभाषय dwarf_info                s1->dState->dwarf_info
#परिभाषय dwarf_str                 s1->dState->dwarf_str
#परिभाषय dwarf_पङ्क्तिः_str            s1->dState->dwarf_पङ्क्तिः_str
#परिभाषय tcov_दत्त                 s1->dState->tcov_दत्त

#परिभाषय	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
स्थिर पूर्णाङ्क put_stabs(TCCState *s1, ध्रुव वर्ण *str, पूर्णाङ्क type, पूर्णाङ्क other,
    पूर्णाङ्क desc, अचिह्नित दीर्घ मानम्);

ST_FUNC शून्य tcc_debug_new(TCCState *s1)
{
    पूर्णाङ्क shf = 0;
    यदि (!s1->dState)
        s1->dState = tcc_mallocz(परिमाण *s1->dState);

#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    यदि (s1->do_debug && s1->output_type == TCC_OUTPUT_स्मृतिः)
        s1->do_backtrace = 1;
    यदि (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#यदि_अन्तः

    यदि (s1->dwarf) {
	पूर्णाङ्क i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	स्थिर ध्रुव वर्ण *ध्रुव debug[] = {
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
        dwarf_पङ्क्तिः_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	प्रति (i = 0; i < परिमाण(debug)/परिमाण(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_MERGE | SHF_वाक्यानि;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_पङ्क्तिः_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	यदि (s1->dwarf >= 5) {
            dwarf_पङ्क्तिः_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_पङ्क्तिः_str_section->sh_entsize = 1;
	    dwarf_पङ्क्तिः_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    अन्यथा
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = परिमाण(Stab_Sym);
        stab_section->sh_addralign = परिमाण ((Stab_Sym*)0)->n_मानम्;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
स्थिर पूर्णाङ्क put_stabs(TCCState *s1, ध्रुव वर्ण *str, पूर्णाङ्क type, पूर्णाङ्क other, पूर्णाङ्क desc,
                      अचिह्नित दीर्घ मानम्)
{
    Stab_Sym *sym;

    अचिह्नित विस्थापनम्;
    यदि (type == N_SLINE
        && (विस्थापनम् = stab_section->दत्त_विस्थापनम्)
        && (sym = (Stab_Sym*)(stab_section->दत्त + विस्थापनम्) - 1)
        && sym->n_type == type
        && sym->n_मानम् == मानम्) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        प्रत्यागम 0;
    }

    sym = section_ptr_सङ्कलय(stab_section, परिमाण(Stab_Sym));
    यदि (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } अन्यथा {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_मानम् = मानम्;
    प्रत्यागम 1;
}

स्थिर शून्य put_stabs_r(TCCState *s1, ध्रुव वर्ण *str, पूर्णाङ्क type, पूर्णाङ्क other, पूर्णाङ्क desc,
                        अचिह्नित दीर्घ मानम्, Section *sec, पूर्णाङ्क sym_सूचकांक)
{
    यदि (put_stabs(s1, str, type, other, desc, मानम्))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->दत्त_विस्थापनम् - 4,
                      परिमाण ((Stab_Sym*)0)->n_मानम् == PTR_आकार ? R_दत्त_PTR : R_दत्त_32,
                      sym_सूचकांक);
}

स्थिर शून्य put_stabn(TCCState *s1, पूर्णाङ्क type, पूर्णाङ्क other, पूर्णाङ्क desc, पूर्णाङ्क मानम्)
{
    put_stabs(s1, रिक्त, type, other, desc, मानम्);
}

/* ------------------------------------------------------------------------- */
#परिभाषय	dwarf_data1(s,दत्त) \
	(*(uint8_t*)section_ptr_सङ्कलय((s), 1) = (दत्त))
#परिभाषय	dwarf_data2(s,दत्त) \
	write16le(section_ptr_सङ्कलय((s), 2), (दत्त))
#परिभाषय	dwarf_data4(s,दत्त) \
	write32le(section_ptr_सङ्कलय((s), 4), (दत्त))
#परिभाषय	dwarf_data8(s,दत्त) \
	write64le(section_ptr_सङ्कलय((s), 8), (दत्त))

स्थिर पूर्णाङ्क dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    प्रत्यागम put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_अङ्कः, रिक्त);
}

स्थिर शून्य dwarf_reloc(Section *s, पूर्णाङ्क sym, पूर्णाङ्क rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->दत्त_विस्थापनम्, rel, sym, 0);
}

स्थिर शून्य free_str(संरचना dwarf_str_hash **str)
{
    पूर्णाङ्क i;

    प्रति (i = 0; i < N_STR_HASH; i++) {
       यावत् (str[i]) {
           संरचना dwarf_str_hash *अग्र = str[i]->अग्र;

           tcc_free(str[i]);
           str[i] = अग्र;
       }
    }
}

स्थिर अचिह्नित str_hash(ध्रुव वर्ण *s)
{
    अचिह्नित h = 5381;

    यावत् (*s)
       h += (*s++ & 0xffu) + h * 31;
    प्रत्यागम h;
}

स्थिर शून्य dwarf_string(Section *s, Section *dw, पूर्णाङ्क sym, ध्रुव वर्ण *str)
{
    TCCState *s1 = s->s1;
    पूर्णाङ्क len, hash = str_hash(str) % N_STR_HASH;
    वर्ण *ptr;
    संरचना dwarf_str_hash *new_hash;
    संरचना dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_पङ्क्तिः_str;

    len = वाक्यदैर्घ्यम्(str) + 1;
    new_hash = dw_hash[hash];
    यावत् (new_hash) {
	यदि (new_hash->len == len &&
	    !memcmp(str, dw->दत्त + new_hash->दत्त_विस्थापनम्, len))
	    भङ्ग;
	new_hash = new_hash->अग्र;
    }
    यदि (new_hash == रिक्त) {
	अचिह्नित दीर्घ विस्थापनम् = dw->दत्त_विस्थापनम्;

        new_hash = dw_hash[hash];
        यावत् (new_hash) {
	    अचिह्नित दीर्घ n = new_hash->दत्त_विस्थापनम् + new_hash->len - len;

	    यदि (new_hash->len > len &&
	        !memcmp(str, dw->दत्त + n, len)) {
		विस्थापनम् = n;
		भङ्ग;
	    }
	    new_hash = new_hash->अग्र;
        }
	यदि (new_hash == रिक्त) {
	    ptr = section_ptr_सङ्कलय(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (संरचना dwarf_str_hash *)
	    tcc_malloc(परिमाण(संरचना dwarf_str_hash));
	new_hash->len = len;
	new_hash->दत्त_विस्थापनम् = विस्थापनम्;
	new_hash->अग्र = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->दत्त_विस्थापनम्, R_दत्त_32_DW, sym,
                   PTR_आकार == 4 ? 0 : new_hash->दत्त_विस्थापनम्);
    dwarf_data4(s, PTR_आकार == 4 ? new_hash->दत्त_विस्थापनम् : 0);
}

स्थिर शून्य dwarf_strp(Section *s, ध्रुव वर्ण *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

स्थिर शून्य dwarf_पङ्क्तिः_strp(Section *s, ध्रुव वर्ण *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_पङ्क्तिः_str_section, dwarf_sym.पङ्क्तिः_str, str);
}

स्थिर शून्य dwarf_पङ्क्तिः_op(TCCState *s1, अचिह्नित वर्ण op)
{
    यदि (dwarf_पङ्क्तिः.पङ्क्तिः_आकार >= dwarf_पङ्क्तिः.पङ्क्तिः_max_आकार) {
	dwarf_पङ्क्तिः.पङ्क्तिः_max_आकार += 1024;
	dwarf_पङ्क्तिः.पङ्क्तिः_दत्त =
	    (अचिह्नित वर्ण *)tcc_realloc(dwarf_पङ्क्तिः.पङ्क्तिः_दत्त,
					 dwarf_पङ्क्तिः.पङ्क्तिः_max_आकार);
    }
    dwarf_पङ्क्तिः.पङ्क्तिः_दत्त[dwarf_पङ्क्तिः.पङ्क्तिः_आकार++] = op;
}

स्थिर शून्य dwarf_file(TCCState *s1)
{
    पूर्णाङ्क i, j;
    वर्ण *filename;
    पूर्णाङ्क सूचकांक_विस्थापनम् = s1->dwarf < 5;

    यदि (!वाक्यं_तुलय(file->filename, "<command line>")) {
        dwarf_पङ्क्तिः.cur_file = 1;
	प्रत्यागम;
    }
    filename = strrchr(file->filename, '/');
    यदि (filename == रिक्त) {
        प्रति (i = 1; i < dwarf_पङ्क्तिः.filename_आकार; i++)
            यदि (dwarf_पङ्क्तिः.filename_सारणी[i].dir_प्रविष्टिः == 0 &&
		वाक्यं_तुलय(dwarf_पङ्क्तिः.filename_सारणी[i].name,
		       file->filename) == 0) {
		    dwarf_पङ्क्तिः.cur_file = i + सूचकांक_विस्थापनम्;
	            प्रत्यागम;
		}
	i = -सूचकांक_विस्थापनम्;
	filename = file->filename;
    }
    अन्यथा {
	वर्ण *undo = filename;
	वर्ण *dir = file->filename;

	*filename++ = '\0';
        प्रति (i = 0; i < dwarf_पङ्क्तिः.dir_आकार; i++)
	    यदि (वाक्यं_तुलय(dwarf_पङ्क्तिः.dir_सारणी[i], dir) == 0) {
		प्रति (j = 1; j < dwarf_पङ्क्तिः.filename_आकार; j++)
		    यदि (dwarf_पङ्क्तिः.filename_सारणी[j].dir_प्रविष्टिः - सूचकांक_विस्थापनम्
			== i &&
			वाक्यं_तुलय(dwarf_पङ्क्तिः.filename_सारणी[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_पङ्क्तिः.cur_file = j + सूचकांक_विस्थापनम्;
			प्रत्यागम;
		    }
		भङ्ग;
	    }
	यदि (i == dwarf_पङ्क्तिः.dir_आकार) {
	    dwarf_पङ्क्तिः.dir_आकार++;
	    dwarf_पङ्क्तिः.dir_सारणी =
                (वर्ण **) tcc_realloc(dwarf_पङ्क्तिः.dir_सारणी,
                                      dwarf_पङ्क्तिः.dir_आकार *
                                      परिमाण (वर्ण *));
            dwarf_पङ्क्तिः.dir_सारणी[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_पङ्क्तिः.filename_सारणी =
        (संरचना dwarf_filename_struct *)
        tcc_realloc(dwarf_पङ्क्तिः.filename_सारणी,
                    (dwarf_पङ्क्तिः.filename_आकार + 1) *
                    परिमाण (संरचना dwarf_filename_struct));
    dwarf_पङ्क्तिः.filename_सारणी[dwarf_पङ्क्तिः.filename_आकार].dir_प्रविष्टिः =
	i + सूचकांक_विस्थापनम्;
    dwarf_पङ्क्तिः.filename_सारणी[dwarf_पङ्क्तिः.filename_आकार].name =
        tcc_strdup(filename);
    dwarf_पङ्क्तिः.cur_file = dwarf_पङ्क्तिः.filename_आकार++ + सूचकांक_विस्थापनम्;
    प्रत्यागम;
}

#यदि 0
स्थिर पूर्णाङ्क dwarf_uleb128_आकार (अचिह्नित दीर्घ दीर्घ मानम्)
{
    पूर्णाङ्क आकार =  0;

    कुरु {
        मानम् >>= 7;
        आकार++;
    } यावत् (मानम् != 0);
    प्रत्यागम आकार;
}
#यदि_अन्तः

स्थिर पूर्णाङ्क dwarf_sleb128_आकार (दीर्घ दीर्घ मानम्)
{
    पूर्णाङ्क आकार =  0;
    दीर्घ दीर्घ अन्तः = मानम् >> 63;
    अचिह्नित वर्ण चरमः = अन्तः & 0x40;
    अचिह्नित वर्ण byte;

    कुरु {
        byte = मानम् & 0x7f;
        मानम् >>= 7;
        आकार++;
    } यावत् (मानम् != अन्तः || (byte & 0x40) != चरमः);
    प्रत्यागम आकार;
}

स्थिर शून्य dwarf_uleb128 (Section *s, अचिह्नित दीर्घ दीर्घ मानम्)
{
    कुरु {
        अचिह्नित वर्ण byte = मानम् & 0x7f;

        मानम् >>= 7;
        dwarf_data1(s, byte | (मानम् ? 0x80 : 0));
    } यावत् (मानम् != 0);
}

स्थिर शून्य dwarf_sleb128 (Section *s, दीर्घ दीर्घ मानम्)
{
    पूर्णाङ्क अधिकम्;
    दीर्घ दीर्घ अन्तः = मानम् >> 63;
    अचिह्नित वर्ण चरमः = अन्तः & 0x40;

    कुरु {
        अचिह्नित वर्ण byte = मानम् & 0x7f;

        मानम् >>= 7;
	अधिकम् = मानम् != अन्तः || (byte & 0x40) != चरमः;
        dwarf_data1(s, byte | (0x80 * अधिकम्));
    } यावत् (अधिकम्);
}

स्थिर शून्य dwarf_uleb128_op (TCCState *s1, अचिह्नित दीर्घ दीर्घ मानम्)
{
    कुरु {
        अचिह्नित वर्ण byte = मानम् & 0x7f;

        मानम् >>= 7;
        dwarf_पङ्क्तिः_op(s1, byte | (मानम् ? 0x80 : 0));
    } यावत् (मानम् != 0);
}

स्थिर शून्य dwarf_sleb128_op (TCCState *s1, दीर्घ दीर्घ मानम्)
{
    पूर्णाङ्क अधिकम्;
    दीर्घ दीर्घ अन्तः = मानम् >> 63;
    अचिह्नित वर्ण चरमः = अन्तः & 0x40;

    कुरु {
        अचिह्नित वर्ण byte = मानम् & 0x7f;

        मानम् >>= 7;
        अधिकम् = मानम् != अन्तः || (byte & 0x40) != चरमः;
        dwarf_पङ्क्तिः_op(s1, byte | (0x80 * अधिकम्));
    } यावत् (अधिकम्);
}

#यदि TCC_EH_FRAME
ST_FUNC शून्य tcc_eh_frame_start(TCCState *s1)
{
    यदि (!s1->unwind_tables)
        प्रत्यागम;
    eh_frame_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_start = eh_frame_section->दत्त_विस्थापनम्;
    dwarf_data4(eh_frame_section, 0); //दीर्घता
    dwarf_data4(eh_frame_section, 0); // CIE ID
    dwarf_data1(eh_frame_section, 1); //संस्करणम्
    dwarf_data1(eh_frame_section, 'z'); // Augmentation String
    dwarf_data1(eh_frame_section, 'R');
    dwarf_data1(eh_frame_section, 0);
#यदि defined TCC_TARGET_I386
    dwarf_uleb128(eh_frame_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 8); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 4); // r4 (esp)
    dwarf_uleb128(eh_frame_section, 4); // ofs 4
    dwarf_data1(eh_frame_section, DW_CFA_विस्थापनम् + 8); // r8 (eip)
    dwarf_uleb128(eh_frame_section, 1); // cfa-4
#नोचेद्यदि defined TCC_TARGET_X86_64
    dwarf_uleb128(eh_frame_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 16); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_frame_section, 8); // ofs 8
    dwarf_data1(eh_frame_section, DW_CFA_विस्थापनम् + 16); // r16 (rip)
    dwarf_uleb128(eh_frame_section, 1); // cfa-8
#नोचेद्यदि defined TCC_TARGET_ARM
    /* TODO: arm must be compiled with: -funwind-tables */
    /* arm also uses .ARM.extab and .ARM.exidx sections */
    dwarf_uleb128(eh_frame_section, 2); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 14); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 13); // r13 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#नोचेद्यदि defined TCC_TARGET_ARM64
    dwarf_uleb128(eh_frame_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 30); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 31); // x31 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#नोचेद्यदि defined TCC_TARGET_RISCV64
    eh_frame_section->दत्त[s1->eh_start + 8] = 3; // version = 3
    dwarf_uleb128(eh_frame_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 1); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 2); // r2 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#यदि_अन्तः
    यावत् ((eh_frame_section->दत्त_विस्थापनम् - s1->eh_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->दत्त + s1->eh_start, //दीर्घता
	      eh_frame_section->दत्त_विस्थापनम् - s1->eh_start - 4);
}

स्थिर शून्य tcc_debug_frame_अन्तः(TCCState *s1, पूर्णाङ्क आकार)
{
    पूर्णाङ्क eh_section_sym;
    अचिह्नित दीर्घ fde_start;

    यदि (!eh_frame_section)
	प्रत्यागम;
    eh_section_sym = dwarf_get_section_sym(text_section);
    fde_start = eh_frame_section->दत्त_विस्थापनम्;
    dwarf_data4(eh_frame_section, 0); //दीर्घता
    dwarf_data4(eh_frame_section,
		fde_start - s1->eh_start + 4); // CIE Pointer
#यदि defined TCC_TARGET_I386
    dwarf_reloc(eh_frame_section, eh_section_sym, R_386_PC32);
#नोचेद्यदि defined TCC_TARGET_X86_64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_X86_64_PC32);
#नोचेद्यदि defined TCC_TARGET_ARM
    dwarf_reloc(eh_frame_section, eh_section_sym, R_ARM_REL32);
#नोचेद्यदि defined TCC_TARGET_ARM64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_AARCH64_PREL32);
#नोचेद्यदि defined TCC_TARGET_RISCV64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_RISCV_32_PCREL);
#यदि_अन्तः
    dwarf_data4(eh_frame_section, func_ind); // PC Begin
    dwarf_data4(eh_frame_section, आकार); // PC Range
    dwarf_data1(eh_frame_section, 0); // Augmentation Length
#यदि defined TCC_TARGET_I386
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_विस्थापनम्);
    dwarf_uleb128(eh_frame_section, 8);
    dwarf_data1(eh_frame_section, DW_CFA_विस्थापनम् + 5); // r5 (ebp)
    dwarf_uleb128(eh_frame_section, 2); // cfa-8
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_पञ्जिकाकोशः);
    dwarf_uleb128(eh_frame_section, 5); // r5 (ebp)
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_frame_section, आकार - 5);
    dwarf_data1(eh_frame_section, DW_CFA_restore + 5); // r5 (ebp)
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 4); // r4 (esp)
    dwarf_uleb128(eh_frame_section, 4); // ofs 4
#नोचेद्यदि defined TCC_TARGET_X86_64
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_विस्थापनम्);
    dwarf_uleb128(eh_frame_section, 16);
    dwarf_data1(eh_frame_section, DW_CFA_विस्थापनम् + 6); // r6 (rbp)
    dwarf_uleb128(eh_frame_section, 2); // cfa-16
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_पञ्जिकाकोशः);
    dwarf_uleb128(eh_frame_section, 6); // r6 (rbp)
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_frame_section, आकार - 5);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_frame_section, 8); // ofs 8
#नोचेद्यदि defined TCC_TARGET_ARM
    /* TODO */
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_विस्थापनम्);
    dwarf_uleb128(eh_frame_section, 8);
    dwarf_data1(eh_frame_section, DW_CFA_विस्थापनम् + 14); // r14 (lr)
    dwarf_uleb128(eh_frame_section, 1);
    dwarf_data1(eh_frame_section, DW_CFA_विस्थापनम् + 11); // r11 (fp)
    dwarf_uleb128(eh_frame_section, 2);
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_frame_section, आकार / 2 - 5);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_पञ्जिकाकोशः);
    dwarf_uleb128(eh_frame_section, 11); // r11 (fp)
#नोचेद्यदि defined TCC_TARGET_ARM64
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_विस्थापनम्);
    dwarf_uleb128(eh_frame_section, 224);
    dwarf_data1(eh_frame_section, DW_CFA_विस्थापनम् + 29); // x29 (fp)
    dwarf_uleb128(eh_frame_section, 28); // cfa-224
    dwarf_data1(eh_frame_section, DW_CFA_विस्थापनम् + 30); // x30 (lr)
    dwarf_uleb128(eh_frame_section, 27); // cfa-216
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_विस्थापनम्);
    dwarf_uleb128(eh_frame_section, 224 + ((-loc + 15) & ~15));
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_frame_section, आकार / 4 - 5);
    dwarf_data1(eh_frame_section, DW_CFA_restore + 30); // x30 (lr)
    dwarf_data1(eh_frame_section, DW_CFA_restore + 29); // x29 (fp)
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_विस्थापनम्);
    dwarf_uleb128(eh_frame_section, 0);
#नोचेद्यदि defined TCC_TARGET_RISCV64
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_विस्थापनम्);
    dwarf_uleb128(eh_frame_section, 16); // ofs 16
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_frame_section, DW_CFA_विस्थापनम् + 1); // r1 (ra, lr)
    dwarf_uleb128(eh_frame_section, 2); // cfa-8
    dwarf_data1(eh_frame_section, DW_CFA_विस्थापनम् + 8); // r8 (s0, fp)
    dwarf_uleb128(eh_frame_section, 4); // cfa-16
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 8); // r8 (s0, fp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    यावत् (आकार >= 4 &&
	   read32le(cur_text_section->दत्त + func_ind + आकार - 4) != 0x00008067)
	आकार -= 4;
    dwarf_data4(eh_frame_section, आकार - 36);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 2); // r2 (r2, sp)
    dwarf_uleb128(eh_frame_section, 16); // ofs 16
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_frame_section, DW_CFA_restore + 1); // r1 (lr)
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_frame_section, DW_CFA_restore + 8); // r8 (s0, fp)
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_विस्थापनम्);
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#यदि_अन्तः
    यावत् ((eh_frame_section->दत्त_विस्थापनम् - fde_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->दत्त + fde_start, //दीर्घता
	      eh_frame_section->दत्त_विस्थापनम् - fde_start - 4);
}

ST_FUNC शून्य tcc_eh_frame_अन्तः(TCCState *s1)
{
    यदि (!eh_frame_section)
	प्रत्यागम;
    dwarf_data4(eh_frame_section, 0);
}

संरचना eh_अन्वेषणम्_सारणी {
    uint32_t pc_विस्थापनम्;
    uint32_t fde_विस्थापनम्;
};

स्थिर पूर्णाङ्क क्रमय_eh_सारणी(ध्रुव शून्य *a, ध्रुव शून्य *b)
{
    uint32_t pc1 = ((ध्रुव संरचना eh_अन्वेषणम्_सारणी *)a)->pc_विस्थापनम्;
    uint32_t pc2 = ((ध्रुव संरचना eh_अन्वेषणम्_सारणी *)b)->pc_विस्थापनम्;

    प्रत्यागम pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC शून्य tcc_eh_frame_hdr(TCCState *s1, पूर्णाङ्क final)
{
    पूर्णाङ्क गणनम्_2 = 0, विस्थापनम्;
    अचिह्नित दीर्घ गणनम्_विस्थापनम्, tab_विस्थापनम्;
    अचिह्नित वर्ण *ln, *अन्तः;
    अचिह्नित पूर्णाङ्क चरमः_cie_विस्थापनम् = 0xffffffff;

    यदि (!eh_frame_section || !eh_frame_section->दत्त_विस्थापनम्)
	प्रत्यागम;
    यदि (final && !eh_frame_hdr_section)
	प्रत्यागम;
    यदि (final == 0)
        eh_frame_hdr_section =
	    new_section(s1, ".eh_frame_hdr", SHT_PROGBITS, SHF_ALLOC);
    eh_frame_hdr_section->दत्त_विस्थापनम् = 0;
    dwarf_data1(eh_frame_hdr_section, 1); //संस्करणम्
    // Pointer Encoding Format
    dwarf_data1(eh_frame_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_pcrel);
    // Count Encoding Format
    dwarf_data1(eh_frame_hdr_section, DW_EH_PE_udata4 | DW_EH_PE_absptr);
    // Table Encoding Format
    dwarf_data1(eh_frame_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_datarel);
    विस्थापनम् = eh_frame_section->sh_addr -
             eh_frame_hdr_section->sh_addr -
             eh_frame_hdr_section->दत्त_विस्थापनम्;
    dwarf_data4(eh_frame_hdr_section, विस्थापनम्); // eh_frame_ptr
    //गणनम्
    गणनम्_विस्थापनम् = eh_frame_hdr_section->दत्त_विस्थापनम्;
    dwarf_data4(eh_frame_hdr_section, 0);
    tab_विस्थापनम् = eh_frame_hdr_section->दत्त_विस्थापनम्;
    ln = eh_frame_section->दत्त;
    अन्तः = eh_frame_section->दत्त + eh_frame_section->दत्त_विस्थापनम्;
    यावत् (ln < अन्तः) {
	अचिह्नित वर्ण *fde = ln, *rd = ln;
	अचिह्नित पूर्णाङ्क cie_विस्थापनम्, संस्करणम्, दीर्घता = dwarf_read_4(rd, अन्तः);
	अचिह्नित पूर्णाङ्क pc_विस्थापनम्, fde_विस्थापनम्;

	यदि (दीर्घता == 0)
	    गच्छ अग्र;
        cie_विस्थापनम् = dwarf_read_4(rd, अन्तः);
	यदि (cie_विस्थापनम् == 0)
	    गच्छ अग्र;
	यदि (cie_विस्थापनम् != चरमः_cie_विस्थापनम्) {
	    अचिह्नित वर्ण *cie = rd - cie_विस्थापनम् + 4;

	    यदि (cie < eh_frame_section->दत्त)
		गच्छ अग्र;
	    संस्करणम् = dwarf_read_1(cie, अन्तः);
	    यदि ((संस्करणम् == 1 || संस्करणम् == 3) &&
	        dwarf_read_1(cie, अन्तः) == 'z' && // Augmentation String
		dwarf_read_1(cie, अन्तः) == 'R' &&
		dwarf_read_1(cie, अन्तः) == 0) {
	        dwarf_read_uleb128(&cie, अन्तः); // code_alignment_factor
	        dwarf_read_sleb128(&cie, अन्तः); // data_alignment_factor
		dwarf_read_1(cie, अन्तः); // return address column
		यदि (dwarf_read_uleb128(&cie, अन्तः) == 1 &&
		    dwarf_read_1(cie, अन्तः) == FDE_ENCODING) {
		    चरमः_cie_विस्थापनम् = cie_विस्थापनम्;
		}
		अन्यथा
		    गच्छ अग्र;
	    }
	    अन्यथा
		गच्छ अग्र;
	}
	गणनम्_2++;
	fde_विस्थापनम् = eh_frame_section->sh_addr +
		     (fde - eh_frame_section->दत्त) -
		     eh_frame_hdr_section->sh_addr;
	pc_विस्थापनम् = dwarf_read_4(rd, अन्तः) + fde_विस्थापनम् + 8;
	dwarf_data4(eh_frame_hdr_section, pc_विस्थापनम्);
	dwarf_data4(eh_frame_hdr_section, fde_विस्थापनम्);
अग्र:
	ln += दीर्घता + 4;
    }
    add32le(eh_frame_hdr_section->दत्त + गणनम्_विस्थापनम्, गणनम्_2);
    शीघ्रं_क्रमय(eh_frame_hdr_section->दत्त + tab_विस्थापनम्, गणनम्_2,
	  परिमाण(संरचना eh_अन्वेषणम्_सारणी), क्रमय_eh_सारणी);
}
#यदि_अन्तः

/* start of translation unit info */
ST_FUNC शून्य tcc_debug_start(TCCState *s1)
{
    पूर्णाङ्क i;
    वर्ण buf[512];
    वर्ण *filename;

    /* we might currently #include the <command-line> */
    filename = file->पूर्व ? file->पूर्व->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    यदि (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, text_section->दत्त_विस्थापनम्, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            text_section->sh_अङ्कः, "$a");

        new_file = चरमः_पङ्क्तिः_अङ्कः = 0;
        debug_अग्र_type = N_DEFAULT_DEBUG;
        debug_hash_global = रिक्त;
        debug_hash_local = रिक्त;
        debug_forw_hash_global = रिक्त;
        debug_forw_hash_local = रिक्त;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, परिमाण(buf));
#यदि_परिभाषितम् _WIN32
        normalize_slashes(buf);
#यदि_अन्तः

        यदि (s1->dwarf) {
            पूर्णाङ्क start_abbrev;
            अचिह्नित वर्ण *ptr;
	    वर्ण *undo;

            /* dwarf_abbrev */
            start_abbrev = dwarf_abbrev_section->दत्त_विस्थापनम्;
            ptr = section_ptr_सङ्कलय(dwarf_abbrev_section, परिमाण(dwarf_abbrev_init));
            स्मृतिं_प्रतिलिख(ptr, dwarf_abbrev_init, परिमाण(dwarf_abbrev_init));

            यदि (s1->dwarf < 5) {
    	        यावत् (*ptr) {
    	            ptr += 3;
    	            यावत् (*ptr) {
    	                यदि (ptr[1] == DW_FORM_पङ्क्तिः_strp)
    		            ptr[1] = DW_FORM_strp;
		        यदि (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    यदि  (ptr[1] == DW_FORM_sec_विस्थापनम्)
			         ptr[1] = DW_FORM_data4;
			    /* This code uses only size < 0x80 so these are
			       compatible. */
			    यदि  (ptr[1] == DW_FORM_exprloc)
			         ptr[1] = DW_FORM_block1;
			}
    	                ptr += 2;
    	            }
		    ptr += 2;
    	        }
            }

            dwarf_sym.info = dwarf_get_section_sym(dwarf_info_section);
            dwarf_sym.abbrev = dwarf_get_section_sym(dwarf_abbrev_section);
            dwarf_sym.पङ्क्तिः = dwarf_get_section_sym(dwarf_पङ्क्तिः_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            यदि (tcc_state->dwarf >= 5)
    	        dwarf_sym.पङ्क्तिः_str = dwarf_get_section_sym(dwarf_पङ्क्तिः_str_section);
            अन्यथा {
    	        dwarf_पङ्क्तिः_str_section = dwarf_str_section;
                dwarf_sym.पङ्क्तिः_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(text_section);

            /* dwarf_info */
            dwarf_info.start = dwarf_info_section->दत्त_विस्थापनम्;
            dwarf_data4(dwarf_info_section, 0); //आकार
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            यदि (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_आकार);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_दत्त_32_DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
            }
            अन्यथा {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_दत्त_32_DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
                dwarf_data1(dwarf_info_section, PTR_आकार);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_संस्करणम्);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_पङ्क्तिः_strp(dwarf_info_section, filename);
            dwarf_पङ्क्तिः_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_दत्त_PTR);
#यदि PTR_आकार == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#अन्यथा
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#यदि_अन्तः
            dwarf_reloc(dwarf_info_section, dwarf_sym.पङ्क्तिः, R_दत्त_32_DW);
            dwarf_data4(dwarf_info_section, dwarf_पङ्क्तिः_section->दत्त_विस्थापनम्); // stmt_list

            /* dwarf_line */
            dwarf_पङ्क्तिः.start = dwarf_पङ्क्तिः_section->दत्त_विस्थापनम्;
            dwarf_data4(dwarf_पङ्क्तिः_section, 0); //दीर्घता
            dwarf_data2(dwarf_पङ्क्तिः_section, s1->dwarf); // version
            यदि (s1->dwarf >= 5) {
                dwarf_data1(dwarf_पङ्क्तिः_section, PTR_आकार); // address size
                dwarf_data1(dwarf_पङ्क्तिः_section, 0); // segment selector
            }
            dwarf_data4(dwarf_पङ्क्तिः_section, 0); // prologue Length
            dwarf_data1(dwarf_पङ्क्तिः_section, DWARF_MIN_INSTR_LEN);
            यदि (s1->dwarf >= 4)
                dwarf_data1(dwarf_पङ्क्तिः_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_पङ्क्तिः_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_पङ्क्तिः_section, DWARF_पङ्क्तिः_आधारः);
            dwarf_data1(dwarf_पङ्क्तिः_section, DWARF_पङ्क्तिः_RANGE);
            dwarf_data1(dwarf_पङ्क्तिः_section, DWARF_OPCODE_आधारः);
            ptr = section_ptr_सङ्कलय(dwarf_पङ्क्तिः_section, परिमाण(dwarf_पङ्क्तिः_opcodes));
            स्मृतिं_प्रतिलिख(ptr, dwarf_पङ्क्तिः_opcodes, परिमाण(dwarf_पङ्क्तिः_opcodes));
	    undo = strrchr(filename, '/');
	    यदि (undo)
		*undo = 0;
            dwarf_पङ्क्तिः.dir_आकार = 1 + (undo != रिक्त);
            dwarf_पङ्क्तिः.dir_सारणी = (वर्ण **) tcc_malloc(परिमाण (वर्ण *) *
							dwarf_पङ्क्तिः.dir_आकार);
            dwarf_पङ्क्तिः.dir_सारणी[0] = tcc_strdup(buf);
	    यदि (undo)
                dwarf_पङ्क्तिः.dir_सारणी[1] = tcc_strdup(filename);
            dwarf_पङ्क्तिः.filename_आकार = 2;
            dwarf_पङ्क्तिः.filename_सारणी =
    	        (संरचना dwarf_filename_struct *)
    	        tcc_malloc(2*परिमाण (संरचना dwarf_filename_struct));
            dwarf_पङ्क्तिः.filename_सारणी[0].dir_प्रविष्टिः = 0;
	    यदि (undo) {
                dwarf_पङ्क्तिः.filename_सारणी[0].name = tcc_strdup(undo + 1);
                dwarf_पङ्क्तिः.filename_सारणी[1].dir_प्रविष्टिः = 1;
                dwarf_पङ्क्तिः.filename_सारणी[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    अन्यथा {
                dwarf_पङ्क्तिः.filename_सारणी[0].name = tcc_strdup(filename);
                dwarf_पङ्क्तिः.filename_सारणी[1].dir_प्रविष्टिः = 0;
                dwarf_पङ्क्तिः.filename_सारणी[1].name = tcc_strdup(filename);
	    }
            dwarf_पङ्क्तिः.पङ्क्तिः_आकार = dwarf_पङ्क्तिः.पङ्क्तिः_max_आकार = 0;
            dwarf_पङ्क्तिः.पङ्क्तिः_दत्त = रिक्त;
            dwarf_पङ्क्तिः.cur_file = 1;
            dwarf_पङ्क्तिः.चरमः_file = 0;
            dwarf_पङ्क्तिः.चरमः_pc = 0;
            dwarf_पङ्क्तिः.चरमः_पङ्क्तिः = 1;
            dwarf_पङ्क्तिः_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_आकार); // extended size
            dwarf_पङ्क्तिः_op(s1, DW_LNE_समुच्चयः_स्थानाङ्कः);
            प्रति (i = 0; i < PTR_आकार; i++)
    	        dwarf_पङ्क्तिः_op(s1, 0);
            स्मृतिं_पूरय(&dwarf_info.आधारः_type_प्रयुक्तम्, 0, परिमाण(dwarf_info.आधारः_type_प्रयुक्तम्));
        }
        अन्यथा
        {
            /* file info: full path + filename */
            pstrcat(buf, परिमाण(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      text_section->sh_अङ्कः, रिक्त);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        text_section->दत्त_विस्थापनम्, text_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        text_section->दत्त_विस्थापनम्, text_section, section_sym);
            प्रति (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

स्थिर शून्य fix_debug_forw_hash(TCCState *s1, पूर्णाङ्क global, पूर्णाङ्क start);

/* put end of translation unit info */
ST_FUNC शून्य tcc_debug_अन्तः(TCCState *s1)
{

    यदि (!s1->do_debug || debug_अग्र_type == 0)
        प्रत्यागम;

    यदि (debug_info_मूलम्)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    यदि (s1->dwarf) {
	पूर्णाङ्क i;
	पूर्णाङ्क start_aranges;
	अचिह्नित वर्ण *ptr;
	पूर्णाङ्क text_आकार = text_section->दत्त_विस्थापनम्;

	/* dwarf_info */
	fix_debug_forw_hash(s1, 0, 0);
	fix_debug_forw_hash(s1, 1, 0);
	dwarf_data1(dwarf_info_section, 0);
	ptr = dwarf_info_section->दत्त + dwarf_info.start;
	write32le(ptr, dwarf_info_section->दत्त_विस्थापनम् - dwarf_info.start - 4);
	write32le(ptr + 25 + (s1->dwarf >= 5) + PTR_आकार, text_आकार);

	/* dwarf_aranges */
	start_aranges = dwarf_aranges_section->दत्त_विस्थापनम्;
	dwarf_data4(dwarf_aranges_section, 0); //आकार
	dwarf_data2(dwarf_aranges_section, 2); // version
	dwarf_reloc(dwarf_aranges_section, dwarf_sym.info, R_दत्त_32_DW);
	dwarf_data4(dwarf_aranges_section, 0); // dwarf_info
#यदि PTR_आकार == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#अन्यथा
	dwarf_data1(dwarf_aranges_section, 8); // address size
#यदि_अन्तः
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_दत्त_PTR);
#यदि PTR_आकार == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, text_आकार); //अन्तः
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#अन्यथा
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, text_आकार); //अन्तः
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#यदि_अन्तः
	ptr = dwarf_aranges_section->दत्त + start_aranges;
	write32le(ptr, dwarf_aranges_section->दत्त_विस्थापनम् - start_aranges - 4);

	/* dwarf_line */
	यदि (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_पङ्क्तिः_section, 1); /* col */
	    dwarf_uleb128(dwarf_पङ्क्तिः_section, DW_LNCT_मार्गः);
	    dwarf_uleb128(dwarf_पङ्क्तिः_section, DW_FORM_पङ्क्तिः_strp);
	    dwarf_uleb128(dwarf_पङ्क्तिः_section, dwarf_पङ्क्तिः.dir_आकार);
	    प्रति (i = 0; i < dwarf_पङ्क्तिः.dir_आकार; i++)
	        dwarf_पङ्क्तिः_strp(dwarf_पङ्क्तिः_section, dwarf_पङ्क्तिः.dir_सारणी[i]);
	    dwarf_data1(dwarf_पङ्क्तिः_section, 2); /* col */
	    dwarf_uleb128(dwarf_पङ्क्तिः_section, DW_LNCT_मार्गः);
	    dwarf_uleb128(dwarf_पङ्क्तिः_section, DW_FORM_पङ्क्तिः_strp);
	    dwarf_uleb128(dwarf_पङ्क्तिः_section, DW_LNCT_directory_सूचकांक);
	    dwarf_uleb128(dwarf_पङ्क्तिः_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_पङ्क्तिः_section, dwarf_पङ्क्तिः.filename_आकार);
	    प्रति (i = 0; i < dwarf_पङ्क्तिः.filename_आकार; i++) {
	        dwarf_पङ्क्तिः_strp(dwarf_पङ्क्तिः_section,
				dwarf_पङ्क्तिः.filename_सारणी[i].name);
	        dwarf_uleb128(dwarf_पङ्क्तिः_section,
			      dwarf_पङ्क्तिः.filename_सारणी[i].dir_प्रविष्टिः);
	    }
	}
	अन्यथा {
	    पूर्णाङ्क len;

	    प्रति (i = 0; i < dwarf_पङ्क्तिः.dir_आकार; i++) {
	        len = वाक्यदैर्घ्यम्(dwarf_पङ्क्तिः.dir_सारणी[i]) + 1;
	        ptr = section_ptr_सङ्कलय(dwarf_पङ्क्तिः_section, len);
	        memmove(ptr, dwarf_पङ्क्तिः.dir_सारणी[i], len);
	    }
	    dwarf_data1(dwarf_पङ्क्तिः_section, 0); /* end dir */
	    प्रति (i = 0; i < dwarf_पङ्क्तिः.filename_आकार; i++) {
	        len = वाक्यदैर्घ्यम्(dwarf_पङ्क्तिः.filename_सारणी[i].name) + 1;
	        ptr = section_ptr_सङ्कलय(dwarf_पङ्क्तिः_section, len);
	        memmove(ptr, dwarf_पङ्क्तिः.filename_सारणी[i].name, len);
	        dwarf_uleb128(dwarf_पङ्क्तिः_section,
			      dwarf_पङ्क्तिः.filename_सारणी[i].dir_प्रविष्टिः);
	        dwarf_uleb128(dwarf_पङ्क्तिः_section, 0); /* time */
	        dwarf_uleb128(dwarf_पङ्क्तिः_section, 0); /*आकार*/
	    }
	    dwarf_data1(dwarf_पङ्क्तिः_section, 0); /* end file */
	}
	प्रति (i = 0; i < dwarf_पङ्क्तिः.dir_आकार; i++)
	    tcc_free(dwarf_पङ्क्तिः.dir_सारणी[i]);
	tcc_free(dwarf_पङ्क्तिः.dir_सारणी);
	प्रति (i = 0; i < dwarf_पङ्क्तिः.filename_आकार; i++)
	    tcc_free(dwarf_पङ्क्तिः.filename_सारणी[i].name);
	tcc_free(dwarf_पङ्क्तिः.filename_सारणी);

	dwarf_पङ्क्तिः_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_पङ्क्तिः_op(s1, DW_LNE_अन्तः_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_पङ्क्तिः_section->दत्त[dwarf_पङ्क्तिः.start + 6 + i],
		  dwarf_पङ्क्तिः_section->दत्त_विस्थापनम् - dwarf_पङ्क्तिः.start - (10 + i));
	section_ptr_सङ्कलय(dwarf_पङ्क्तिः_section, 3);
	dwarf_reloc(dwarf_पङ्क्तिः_section, section_sym, R_दत्त_PTR);
	ptr = section_ptr_सङ्कलय(dwarf_पङ्क्तिः_section, dwarf_पङ्क्तिः.पङ्क्तिः_आकार - 3);
	memmove(ptr - 3, dwarf_पङ्क्तिः.पङ्क्तिः_दत्त, dwarf_पङ्क्तिः.पङ्क्तिः_आकार);
	tcc_free(dwarf_पङ्क्तिः.पङ्क्तिः_दत्त);
	write32le(dwarf_पङ्क्तिः_section->दत्त + dwarf_पङ्क्तिः.start,
		  dwarf_पङ्क्तिः_section->दत्त_विस्थापनम् - dwarf_पङ्क्तिः.start - 4);
    }
    अन्यथा
    {
        put_stabs_r(s1, रिक्त, N_SO, 0, 0,
                    text_section->दत्त_विस्थापनम्, text_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_पङ्क्तिः_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_अग्र_type = 0;
}

स्थिर BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    यदि (f->filename[0] == ':')
        f = f->पूर्व;
    यदि (f && new_file) {
        new_file = चरमः_पङ्क्तिः_अङ्कः = 0;
        यदि (s1->dwarf)
            dwarf_file(s1);
        अन्यथा
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, text_section, section_sym);
    }
    प्रत्यागम f;
}

/* put alternative filename */
ST_FUNC शून्य tcc_debug_newfile(TCCState *s1)
{
    यदि (!s1->do_debug)
        प्रत्यागम;
    यदि (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC शून्य tcc_debug_bincl(TCCState *s1)
{
    यदि (!s1->do_debug)
        प्रत्यागम;
    यदि (s1->dwarf)
        dwarf_file(s1);
    अन्यथा
        put_stabs(s1, file->filename, N_BINCL, 0, 0, 0);
    new_file = 1;
}

/* end of #include */
ST_FUNC शून्य tcc_debug_eincl(TCCState *s1)
{
    यदि (!s1->do_debug)
        प्रत्यागम;
    यदि (s1->dwarf)
        dwarf_file(s1);
    अन्यथा
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC शून्य tcc_debug_पङ्क्तिः(TCCState *s1)
{
    BufferedFile *f;

    यदि (!s1->do_debug)
        प्रत्यागम;
    यदि (cur_text_section != text_section || nocode_wanted)
        प्रत्यागम;
    f = put_new_file(s1);
    यदि (!f)
        प्रत्यागम;
    यदि (चरमः_पङ्क्तिः_अङ्कः == f->पङ्क्तिः_अङ्कः)
        प्रत्यागम;
    चरमः_पङ्क्तिः_अङ्कः = f->पङ्क्तिः_अङ्कः;

    यदि (s1->dwarf) {
	पूर्णाङ्क len_pc = (ind - dwarf_पङ्क्तिः.चरमः_pc) / DWARF_MIN_INSTR_LEN;
	पूर्णाङ्क len_पङ्क्तिः = f->पङ्क्तिः_अङ्कः - dwarf_पङ्क्तिः.चरमः_पङ्क्तिः;
	पूर्णाङ्क n = len_pc * DWARF_पङ्क्तिः_RANGE + len_पङ्क्तिः + DWARF_OPCODE_आधारः - DWARF_पङ्क्तिः_आधारः;

	यदि (dwarf_पङ्क्तिः.cur_file != dwarf_पङ्क्तिः.चरमः_file) {
	    dwarf_पङ्क्तिः.चरमः_file = dwarf_पङ्क्तिः.cur_file;
	    dwarf_पङ्क्तिः_op(s1, DW_LNS_समुच्चयः_file);
	    dwarf_uleb128_op(s1, dwarf_पङ्क्तिः.cur_file);
	}
	यदि (len_pc &&
	    len_पङ्क्तिः >= DWARF_पङ्क्तिः_आधारः && len_पङ्क्तिः <= (DWARF_OPCODE_आधारः + DWARF_पङ्क्तिः_आधारः) &&
	    n >= DWARF_OPCODE_आधारः && n <= 255)
            dwarf_पङ्क्तिः_op(s1, n);
	अन्यथा {
	    यदि (len_pc) {
	        n = len_pc * DWARF_पङ्क्तिः_RANGE + 0 + DWARF_OPCODE_आधारः - DWARF_पङ्क्तिः_आधारः;
	        यदि (n >= DWARF_OPCODE_आधारः && n <= 255)
                    dwarf_पङ्क्तिः_op(s1, n);
		अन्यथा {
	            dwarf_पङ्क्तिः_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    यदि (len_पङ्क्तिः) {
	        n = 0 * DWARF_पङ्क्तिः_RANGE + len_पङ्क्तिः + DWARF_OPCODE_आधारः - DWARF_पङ्क्तिः_आधारः;
	        यदि (len_पङ्क्तिः >= DWARF_पङ्क्तिः_आधारः && len_पङ्क्तिः <= (DWARF_OPCODE_आधारः + DWARF_पङ्क्तिः_आधारः) &&
		    n >= DWARF_OPCODE_आधारः && n <= 255)
	            dwarf_पङ्क्तिः_op(s1, n);
		अन्यथा {
	            dwarf_पङ्क्तिः_op(s1, DW_LNS_advance_पङ्क्तिः);
		    dwarf_sleb128_op(s1, len_पङ्क्तिः);
                    /* advance by nothing */
	            dwarf_पङ्क्तिः_op(s1, DWARF_OPCODE_आधारः - DWARF_पङ्क्तिः_आधारः);
		}
	    }
	}
	dwarf_पङ्क्तिः.चरमः_pc = ind;
	dwarf_पङ्क्तिः.चरमः_पङ्क्तिः = f->पङ्क्तिः_अङ्कः;
    }
    अन्यथा
    {
	यदि (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->पङ्क्तिः_अङ्कः, ind - func_ind);
        } अन्यथा {
            /* from tcc_assemble */
            put_stabs_r(s1, रिक्त, N_SLINE, 0, f->पङ्क्तिः_अङ्कः, ind, text_section, section_sym);
        }
    }
}

स्थिर शून्य tcc_debug_stabs (TCCState *s1, ध्रुव वर्ण *str, पूर्णाङ्क type, अचिह्नित दीर्घ मानम्,
                             Section *sec, पूर्णाङ्क sym_सूचकांक, पूर्णाङ्क info)
{
    संरचना debug_sym *s;

    यदि (debug_info) {
        debug_info->sym =
            (संरचना debug_sym *)tcc_realloc (debug_info->sym,
                                             परिमाण(संरचना debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->मानम् = मानम्;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_सूचकांक = sym_सूचकांक;
        s->info = info;
        s->file = dwarf_पङ्क्तिः.cur_file;
        s->पङ्क्तिः = file->पङ्क्तिः_अङ्कः;
    }
    अन्यथा यदि (sec)
        put_stabs_r (s1, str, type, 0, 0, मानम्, sec, sym_सूचकांक);
    अन्यथा
        put_stabs (s1, str, type, 0, 0, मानम्);
}

स्थिर शून्य fix_debug_forw_hash(TCCState *s1, पूर्णाङ्क global, पूर्णाङ्क start)
{
    यदि (s1->dwarf) {
        पूर्णाङ्क i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	संरचना _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	प्रति (i = start; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    पूर्णाङ्क pos = dwarf_info_section->दत्त_विस्थापनम्;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_रिक्तानि_TYPE
                                             : DWARF_ABBREV_STRUCTURE_रिक्तानि_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, रिक्त));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_पङ्क्तिः.cur_file);
            dwarf_uleb128(dwarf_info_section, file->पङ्क्तिः_अङ्कः);
	    प्रति (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->दत्त +
			  hash[i].debug_type[j],
			  pos - dwarf_info.start);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC शून्य tcc_debug_stabn(TCCState *s1, पूर्णाङ्क type, पूर्णाङ्क मानम्)
{
    यदि (!s1->do_debug)
        प्रत्यागम;
    यदि (type == N_LBRAC) {
        संरचना _debug_info *info =
            (संरचना _debug_info *) tcc_mallocz(परिमाण (*info));

        info->start = मानम्;
        info->चरमः_debug_hash = n_debug_hash_local;
        info->चरमः_debug_forw_hash = n_debug_forw_hash_local;
        info->parent = debug_info;
        यदि (debug_info) {
            यदि (debug_info->child) {
                यदि (debug_info->child->चरमः)
                    debug_info->child->चरमः->अग्र = info;
                अन्यथा
                    debug_info->child->अग्र = info;
                debug_info->child->चरमः = info;
            }
            अन्यथा
                debug_info->child = info;
        }
        अन्यथा
            debug_info_मूलम् = info;
        debug_info = info;
    }
    अन्यथा {
	fix_debug_forw_hash(s1, 0, debug_info->चरमः_debug_forw_hash);
        n_debug_hash_local = debug_info->चरमः_debug_hash;
        n_debug_forw_hash_local = debug_info->चरमः_debug_forw_hash;
        debug_info->अन्तः = मानम्;
        debug_info = debug_info->parent;
    }
}

स्थिर पूर्णाङ्क check_global(Sym *t)
{
    Sym *g = local_राशिः;

    यावत् (g) {
	यदि (t == g)
	    प्रत्यागम 0;
	g = g->पूर्व;
    }
    प्रत्यागम 1;
}

स्थिर पूर्णाङ्क tcc_debug_find(TCCState *s1, Sym *t, पूर्णाङ्क dwarf)
{
    पूर्णाङ्क i , g = check_global(t);
    पूर्णाङ्क n_hash, *n_forw_hash;
    संरचना _debug_hash *hash;
    संरचना _debug_forw_hash **forw_hash;

    यदि ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	प्रति (i = 0; i < *n_forw_hash; i++)
            यदि (t == (*forw_hash)[i].type)
		प्रत्यागम 0;
	*forw_hash = (संरचना _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * परिमाण(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = रिक्त;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	प्रत्यागम 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    प्रति (i = 0; i < n_hash; i++)
        यदि (t == hash[i].type)
	    प्रत्यागम hash[i].debug_type;
    प्रत्यागम -1;
}

स्थिर पूर्णाङ्क tcc_get_dwarf_info(TCCState *s1, Sym *s);

स्थिर शून्य tcc_debug_check_forw(TCCState *s1, Sym *t, पूर्णाङ्क debug_type)
{
    यदि ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        पूर्णाङ्क i, j, g = check_global(t);
        पूर्णाङ्क n_forw_hash;
        संरचना _debug_forw_hash **forw_hash;

	प्रति (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    प्रति (j = 0; j < n_forw_hash; j++)
                यदि (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * परिमाण(पूर्णाङ्क));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    प्रत्यागम;
                }
	}
    }
}

स्थिर शून्य stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC शून्य tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    यदि (!(s1->do_debug & 2))
	प्रत्यागम;
    यदि (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        प्रत्यागम;
    }
    यदि ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        पूर्णाङ्क i, j, debug_type, g = check_global(t->ref);
        पूर्णाङ्क *n_forw_hash;
        संरचना _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	प्रति (i = 0; i < *n_forw_hash; i++)
	    यदि (t->ref == (*forw_hash)[i].type) {
		यदि (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    प्रति (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->दत्त +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.start);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		प्रति (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

स्थिर पूर्णाङ्क tcc_debug_सङ्कलय(TCCState *s1, Sym *t, पूर्णाङ्क dwarf)
{
    पूर्णाङ्क विस्थापनम् = dwarf ? dwarf_info_section->दत्त_विस्थापनम् : ++debug_अग्र_type;
    पूर्णाङ्क *n_hash, g = check_global(t);
    संरचना _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (संरचना _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * परिमाण(**hash));
    (*hash)[*n_hash].debug_type = विस्थापनम्;
    (*hash)[(*n_hash)++].type = t;
    प्रत्यागम विस्थापनम्;
}

स्थिर पूर्णाङ्क STRUCT_NODEBUG(Sym *s)
{
    प्रत्यागम
    (s->a.nodebug ||
     ((s->v & ~SYM_क्षेत्रम्) >= SYM_FIRST_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

स्थिर पूर्णाङ्क stabs_struct_find(TCCState *s1, Sym *t, पूर्णाङ्क *p_id)
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
    यदि (रिक्त == p_id)
        प्रत्यागम s && !s->r && t->c >= 0;
    यदि (रिक्त == s) {
        /* just use global_stack always */
        s = sym_push2(&global_राशिः, SYM_क्षेत्रम्|0x00DEBBED, 0, ++debug_अग्र_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    यदि (s->r || t->c < 0) /* already defined or still incomplete */
        प्रत्यागम 0;
    s->r = 1;
    प्रत्यागम 1;
}

स्थिर पूर्णाङ्क remove_type_info(पूर्णाङ्क type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        यदि ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        यदि (!(type & VT_BITFIELD) && (type & VT_STRUCT_आवरणम्) > VT_ENUM)
	    type &= ~VT_STRUCT_आवरणम्;
	प्रत्यागम type;
}

स्थिर शून्य tcc_get_debug_info(TCCState *s1, Sym *s, CString *परिणाम)
{
    पूर्णाङ्क type;
    पूर्णाङ्क n = 0;
    पूर्णाङ्क debug_type = -1;
    Sym *t = s;
    CString str;

    प्रति (;;) {
        type = remove_type_info (t->type.t);
        यदि (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        अन्यथा
            भङ्ग;
    }
    यदि ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        यदि (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, रिक्त),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            यावत् (t->अग्र) {
                पूर्णाङ्क pos, आकार, align;
                t = t->अग्र;
		यदि (STRUCT_NODEBUG(t))
		    अनुवर्त;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_क्षेत्रम्) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, रिक्त)
                             );
                tcc_get_debug_info (s1, t, &str);
                यदि (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + BIT_POS(t->type.t);
                    आकार = BIT_आकार(t->type.t);
                }
                अन्यथा {
                    pos = t->c * 8;
                    आकार = type_आकार(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, आकार);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.दत्त, N_LSYM, 0, रिक्त, 0, 0);
            cstr_free (&str);
        }
    }
    अन्यथा यदि (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        यदि (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, रिक्त),
                         debug_type);
            यावत् (t->अग्र) {
                t = t->अग्र;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_क्षेत्रम्) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, रिक्त));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (पूर्णाङ्क)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.दत्त, N_LSYM, 0, रिक्त, 0, 0);
            cstr_free (&str);
	}
    }
    अन्यथा यदि ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_आवरणम्;
        प्रति (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            यदि (default_debug[debug_type - 1].type == type)
                भङ्ग;
        यदि (debug_type > N_DEFAULT_DEBUG)
            प्रत्यागम;
    }

    यदि (रिक्त == परिणाम) /* from stabs_struct_complete() */
        प्रत्यागम;

    यदि (n > 0)
        cstr_printf (परिणाम, "%d=", ++debug_अग्र_type);
    t = s;
    प्रति (;;) {
        type = remove_type_info (t->type.t);
        यदि (type == VT_PTR)
            cstr_printf (परिणाम, "%d=*", ++debug_अग्र_type);
        अन्यथा यदि (type == (VT_PTR | VT_ARRAY))
            cstr_printf (परिणाम, "%d=ar1;0;%d;",
                         ++debug_अग्र_type, t->type.ref->c - 1);
        अन्यथा यदि (type == VT_FUNC) {
            cstr_printf (परिणाम, "%d=f", ++debug_अग्र_type);
            tcc_get_debug_info (s1, t->type.ref, परिणाम);
            प्रत्यागम;
        }
        अन्यथा
            भङ्ग;
        t = t->type.ref;
    }
    cstr_printf (परिणाम, "%d", debug_type);
}

स्थिर शून्य stabs_struct_complete(TCCState *s1, CType *t)
{
    यदि (stabs_struct_find(s1, t->ref, रिक्त)) {
        Sym s = {0}; s.type = *t;
        tcc_get_debug_info(s1, &s, रिक्त);
    }
}

स्थिर पूर्णाङ्क tcc_get_dwarf_info(TCCState *s1, Sym *s)
{
    पूर्णाङ्क type;
    पूर्णाङ्क debug_type = -1;
    Sym *e, *t = s;
    पूर्णाङ्क i;
    पूर्णाङ्क चरमः_pos = -1;
    पूर्णाङ्क retval;

    यदि (new_file)
        put_new_file(s1);
    प्रति (;;) {
        type = remove_type_info (t->type.t);
        यदि (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        अन्यथा
            भङ्ग;
    }
    यदि ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	यदि (debug_type == -1) {
	    पूर्णाङ्क pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_सङ्कलय(s1, t, 1);
	    e = t;
	    i = 0;
	    यावत् (e->अग्र) {
		e = e->अग्र;
		यदि (STRUCT_NODEBUG(e))
		    अनुवर्त;
		i++;
	    }
	    pos_type = (पूर्णाङ्क *) tcc_malloc(i * परिमाण(पूर्णाङ्क));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->अग्र ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_रिक्तानि_TYPE
		        : t->अग्र ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_रिक्तानि_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, रिक्त));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_पङ्क्तिः.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->पङ्क्तिः_अङ्कः);
	    यदि (t->अग्र) {
	        pos_sib = dwarf_info_section->दत्त_विस्थापनम्;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            यावत् (e->अग्र) {
                e = e->अग्र;
		यदि (STRUCT_NODEBUG(e))
		    अनुवर्त;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, रिक्त));
		dwarf_uleb128(dwarf_info_section, dwarf_पङ्क्तिः.cur_file);
		dwarf_uleb128(dwarf_info_section, file->पङ्क्तिः_अङ्कः);
		pos_type[i++] = dwarf_info_section->दत्त_विस्थापनम्;
		dwarf_data4(dwarf_info_section, 0);
                यदि (e->type.t & VT_BITFIELD) {
                    पूर्णाङ्क pos = e->c * 8 + BIT_POS(e->type.t);
                    पूर्णाङ्क आकार = BIT_आकार(e->type.t);

		    dwarf_uleb128(dwarf_info_section, आकार);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		अन्यथा
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    यदि (t->अग्र) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->दत्त + pos_sib,
		          dwarf_info_section->दत्त_विस्थापनम् - dwarf_info.start);
	    }
	    e = t;
	    i = 0;
	    यावत् (e->अग्र) {
		e = e->अग्र;
		यदि (STRUCT_NODEBUG(e))
		    अनुवर्त;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->दत्त + pos_type[i++],
			  type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
    }
    अन्यथा यदि (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	यदि (debug_type == -1) {
	    पूर्णाङ्क pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_सङ्कलय(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, रिक्त));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.start);
	    dwarf_uleb128(dwarf_info_section, dwarf_पङ्क्तिः.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->पङ्क्तिः_अङ्कः);
	    pos_sib = dwarf_info_section->दत्त_विस्थापनम्;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            यावत् (e->अग्र) {
                e = e->अग्र;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_क्षेत्रम्) >= SYM_FIRST_ANOM
                           ? "" : get_tok_str(e->v, रिक्त));
		यदि (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		अन्यथा
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->दत्त + pos_sib,
		      dwarf_info_section->दत्त_विस्थापनम् - dwarf_info.start);
	}
    }
    अन्यथा यदि ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_आवरणम्;
        प्रति (i = 1; i <= N_DEFAULT_DEBUG; i++)
            यदि (default_debug[i - 1].type == type)
                भङ्ग;
        यदि (i > N_DEFAULT_DEBUG)
            प्रत्यागम 0;
	debug_type = dwarf_info.आधारः_type_प्रयुक्तम्[i - 1];
	यदि (debug_type == 0) {
	    वर्ण name[100];

	    debug_type = dwarf_info_section->दत्त_विस्थापनम्;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_आधारः_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].आकार);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, परिमाण name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.आधारः_type_प्रयुक्तम्[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = रिक्त;
    t = s;
    प्रति (;;) {
        type = remove_type_info (t->type.t);
        यदि (type == VT_PTR) {
	    i = dwarf_info_section->दत्त_विस्थापनम्;
	    यदि (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_POINTER);
	    dwarf_data1(dwarf_info_section, PTR_आकार);
	    यदि (चरमः_pos != -1) {
		tcc_debug_check_forw(s1, e, चरमः_pos);
		write32le(dwarf_info_section->दत्त + चरमः_pos,
			  i - dwarf_info.start);
	    }
	    चरमः_pos = dwarf_info_section->दत्त_विस्थापनम्;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        अन्यथा यदि (type == (VT_PTR | VT_ARRAY)) {
	    पूर्णाङ्क sib_pos, sub_type;
#यदि LONG_आकार == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#अन्यथा
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#यदि_अन्तः

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->दत्त_विस्थापनम्;
	    यदि (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    यदि (चरमः_pos != -1) {
		tcc_debug_check_forw(s1, e, चरमः_pos);
		write32le(dwarf_info_section->दत्त + चरमः_pos,
			  i - dwarf_info.start);
	    }
	    चरमः_pos = dwarf_info_section->दत्त_विस्थापनम्;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->दत्त_विस्थापनम्;
	    dwarf_data4(dwarf_info_section, 0);
	    प्रति (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.start);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		यदि (type != (VT_PTR | VT_ARRAY))
		    भङ्ग;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->दत्त + sib_pos,
		      dwarf_info_section->दत्त_विस्थापनम् - dwarf_info.start);
	}
        अन्यथा यदि (type == VT_FUNC) {
	    पूर्णाङ्क sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->दत्त_विस्थापनम्;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    यदि (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->अग्र ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_रिक्तानि_TYPE);
	    यदि (चरमः_pos != -1) {
		tcc_debug_check_forw(s1, e, चरमः_pos);
		write32le(dwarf_info_section->दत्त + चरमः_pos,
			  i - dwarf_info.start);
	    }
	    चरमः_pos = dwarf_info_section->दत्त_विस्थापनम्;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    यदि (t->type.ref->अग्र) {
	        sib_pos = dwarf_info_section->दत्त_विस्थापनम्;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    यावत् (f->अग्र) {
		f = f->अग्र;
		i++;
	    }
	    pos_type = (पूर्णाङ्क *) tcc_malloc(i * परिमाण(पूर्णाङ्क));
	    f = t->type.ref;
	    i = 0;
	    यावत् (f->अग्र) {
		f = f->अग्र;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->दत्त_विस्थापनम्;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    यदि (t->type.ref->अग्र) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->दत्त + sib_pos,
		          dwarf_info_section->दत्त_विस्थापनम् - dwarf_info.start);
	    }
	    f = t->type.ref;
	    i = 0;
	    यावत् (f->अग्र) {
		f = f->अग्र;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->दत्त + pos_type[i++],
                          type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
        अन्यथा {
	    यदि (चरमः_pos != -1) {
		tcc_debug_check_forw(s1, e, चरमः_pos);
		write32le(dwarf_info_section->दत्त + चरमः_pos,
			  debug_type - dwarf_info.start);
	    }
            भङ्ग;
	}
        t = t->type.ref;
    }
    प्रत्यागम retval;
}

स्थिर शून्य tcc_debug_finish (TCCState *s1, संरचना _debug_info *cur)
{
    यावत् (cur) {
        संरचना _debug_info *अग्र = cur->अग्र;
        पूर्णाङ्क i;

        यदि (s1->dwarf) {

            प्रति (i = cur->n_sym - 1; i >= 0; i--) {
                संरचना debug_sym *s = &cur->sym[i];

		dwarf_data1(dwarf_info_section,
                            s->type == N_PSYM
			    ? DWARF_ABBREV_FORMAL_PARAMETER
			    : s->type == N_GSYM
                            ? DWARF_ABBREV_VARIABLE_EXTERNAL
                            : s->type == N_STSYM
			    ? DWARF_ABBREV_VARIABLE_STATIC
			    : DWARF_ABBREV_VARIABLE_LOCAL);
                dwarf_strp(dwarf_info_section, s->str);
		यदि (s->type == N_GSYM || s->type == N_STSYM) {
                    dwarf_uleb128(dwarf_info_section, s->file);
                    dwarf_uleb128(dwarf_info_section, s->पङ्क्तिः);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.start);
		यदि (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    यदि (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_आकार + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    यदि (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_दत्त_PTR);
#यदि PTR_आकार == 4
                    dwarf_data4(dwarf_info_section, s->मानम्);
#अन्यथा
                    dwarf_data8(dwarf_info_section, s->मानम्);
#यदि_अन्तः
		}
		अन्यथा {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_आकार((दीर्घ)s->मानम्) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (दीर्घ)s->मानम्);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->child ? DWARF_ABBREV_LEXICAL_खण्डम्
			           : DWARF_ABBREV_LEXICAL_रिक्तानि_खण्डम्);
            dwarf_reloc(dwarf_info_section, section_sym, R_दत्त_PTR);
#यदि PTR_आकार == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->start);
            dwarf_data4(dwarf_info_section, cur->अन्तः - cur->start);
#अन्यथा
            dwarf_data8(dwarf_info_section, func_ind + cur->start);
            dwarf_data8(dwarf_info_section, cur->अन्तः - cur->start);
#यदि_अन्तः
            tcc_debug_finish (s1, cur->child);
	    यदि (cur->child)
                dwarf_data1(dwarf_info_section, 0);
        }
        अन्यथा
        {
            प्रति (i = 0; i < cur->n_sym; i++) {
                संरचना debug_sym *s = &cur->sym[i];

                यदि (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->मानम्,
                                s->sec, s->sym_सूचकांक);
                अन्यथा
                    put_stabs(s1, s->str, s->type, 0, 0, s->मानम्);
                tcc_free (s->str);
            }
            tcc_free (cur->sym);
            put_stabn(s1, N_LBRAC, 0, 0, cur->start);
            tcc_debug_finish (s1, cur->child);
            put_stabn(s1, N_RBRAC, 0, 0, cur->अन्तः);
        }
        tcc_free (cur);
        cur = अग्र;
    }
}

ST_FUNC शून्य tcc_सङ्कलय_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    पूर्णाङ्क param;

    यदि (!(s1->do_debug & 2))
        प्रत्यागम;

    cstr_new (&debug_str);
    param = !e;
    प्रति (; s != e; s = s->पूर्व) {
        यदि (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            अनुवर्त;
	यदि (s1->dwarf) {
	    tcc_debug_stabs(s1, get_tok_str(s->v, रिक्त),
			    param ? N_PSYM : N_LSYM, s->c, रिक्त, 0,
			    tcc_get_dwarf_info(s1, s));
	}
	अन्यथा
        {
            cstr_reset (&debug_str);
            cstr_printf (&debug_str, "%s:%s", get_tok_str(s->v, रिक्त),
			 param ? "p" : "");
            tcc_get_debug_info(s1, s, &debug_str);
            tcc_debug_stabs(s1, debug_str.दत्त, param ? N_PSYM : N_LSYM,
			    s->c, रिक्त, 0, 0);
	}
    }
    cstr_free (&debug_str);
}

/* put function symbol */
ST_FUNC शून्य tcc_debug_funcstart(TCCState *s1, Sym *sym)
{
    CString debug_str;
    BufferedFile *f;

    यदि (!s1->do_debug)
        प्रत्यागम;
    debug_info_मूलम् = रिक्त;
    debug_info = रिक्त;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    यदि (!f)
	प्रत्यागम;

    यदि (s1->dwarf) {
        tcc_debug_पङ्क्तिः(s1);
        dwarf_info.func = sym;
        dwarf_info.पङ्क्तिः = file->पङ्क्तिः_अङ्कः;
	यदि (s1->do_backtrace) {
	    पूर्णाङ्क i, len;

	    dwarf_पङ्क्तिः_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, वाक्यदैर्घ्यम्(funcname) + 2);
	    dwarf_पङ्क्तिः_op(s1, DW_LNE_hi_user - 1);
	    len = वाक्यदैर्घ्यम्(funcname) + 1;
	    प्रति (i = 0; i < len; i++)
		dwarf_पङ्क्तिः_op(s1, funcname[i]);
	}
    }
    अन्यथा
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.दत्त, N_FUN, 0, f->पङ्क्तिः_अङ्कः, 0, cur_text_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_पङ्क्तिः(s1);
    }
}

ST_FUNC शून्य tcc_debug_prolog_epilog(TCCState *s1, पूर्णाङ्क मानम्)
{
    यदि (!s1->do_debug)
        प्रत्यागम;
    यदि (s1->dwarf) {
	dwarf_पङ्क्तिः_op(s1, मानम् == 0 ? DW_LNS_समुच्चयः_prologue_अन्तः
				     : DW_LNS_समुच्चयः_epilogue_begin);
    }
}

/* put function size */
ST_FUNC शून्य tcc_debug_funcend(TCCState *s1, पूर्णाङ्क आकार)
{
    /* lldb does not like function end and next function start at same pc */
    पूर्णाङ्क min_instr_len;

#यदि TCC_EH_FRAME
    tcc_debug_frame_अन्तः(s1, आकार);
#यदि_अन्तः
    यदि (!s1->do_debug)
        प्रत्यागम;
    min_instr_len = dwarf_पङ्क्तिः.चरमः_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_पङ्क्तिः(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, आकार);
    यदि (s1->dwarf) {
        पूर्णाङ्क func_sib = 0;
	Sym *sym = dwarf_info.func;
	पूर्णाङ्क n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        यदि ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_पङ्क्तिः.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.पङ्क्तिः);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->दत्त_विस्थापनम्);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.start);
        dwarf_reloc(dwarf_info_section, section_sym, R_दत्त_PTR);
#यदि PTR_आकार == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, आकार); // high_pc
#अन्यथा
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, आकार); // high_pc
#यदि_अन्तः
        func_sib = dwarf_info_section->दत्त_विस्थापनम्;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#यदि defined(TCC_TARGET_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#नोचेद्यदि defined(TCC_TARGET_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#नोचेद्यदि defined TCC_TARGET_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#नोचेद्यदि defined TCC_TARGET_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#नोचेद्यदि defined TCC_TARGET_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#अन्यथा
        dwarf_data1(dwarf_info_section, DW_OP_call_frame_cfa);
#यदि_अन्तः
        tcc_debug_finish (s1, debug_info_मूलम्);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->दत्त + func_sib,
                  dwarf_info_section->दत्त_विस्थापनम् - dwarf_info.start);
    }
    अन्यथा
    {
        tcc_debug_finish (s1, debug_info_मूलम्);
    }
    debug_info_मूलम् = 0;
}


ST_FUNC शून्य tcc_debug_extern_sym(TCCState *s1, Sym *sym, पूर्णाङ्क sh_अङ्कः, पूर्णाङ्क sym_bind, पूर्णाङ्क sym_type)
{
    यदि (!(s1->do_debug & 2))
        प्रत्यागम;

    यदि (sym_type == STT_FUNC || sym->v >= SYM_FIRST_ANOM)
        प्रत्यागम;
    यदि (s1->dwarf) {
        पूर्णाङ्क debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, रिक्त));
	dwarf_uleb128(dwarf_info_section, dwarf_पङ्क्तिः.cur_file);
	dwarf_uleb128(dwarf_info_section, file->पङ्क्तिः_अङ्कः);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->दत्त_विस्थापनम्);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	यदि (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_आकार + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->दत्त_विस्थापनम्,
		R_दत्त_PTR, 0);
#यदि PTR_आकार == 4
	dwarf_data4(dwarf_info_section, 0);
#अन्यथा
	dwarf_data8(dwarf_info_section, 0);
#यदि_अन्तः
    }
    अन्यथा
    {
        Section *s = sh_अङ्कः == SHN_COMMON ? common_section
					  : s1->sections[sh_अङ्कः];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, रिक्त),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        यदि (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.दत्त, N_GSYM, 0, रिक्त, 0, 0);
        अन्यथा
            tcc_debug_stabs(s1, str.दत्त,
                (sym->type.t & VT_STATIC) && दत्त_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC शून्य tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    यदि (!(s1->do_debug & 2))
        प्रत्यागम;

    यदि (s1->dwarf) {
	पूर्णाङ्क debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	यदि (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, रिक्त));
	    dwarf_uleb128(dwarf_info_section, dwarf_पङ्क्तिः.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->पङ्क्तिः_अङ्कः);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->दत्त_विस्थापनम्);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	}
    }
    अन्यथा
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, रिक्त));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.दत्त, N_LSYM, 0, रिक्त, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC शून्य tcc_tcov_खण्डम्_अन्तः(TCCState *s1, पूर्णाङ्क पङ्क्तिः);

ST_FUNC शून्य tcc_tcov_खण्डम्_begin(TCCState *s1)
{
    SValue sv;
    शून्य *ptr;
    अचिह्नित दीर्घ चरमः_विस्थापनम् = tcov_दत्त.विस्थापनम्;

    tcc_tcov_खण्डम्_अन्तः (tcc_state, 0);
    यदि (s1->test_coverage == 0 || nocode_wanted)
	प्रत्यागम;

    यदि (tcov_दत्त.चरमः_file_name == 0 ||
	वाक्यं_तुलय ((ध्रुव वर्ण *)(tcov_section->दत्त + tcov_दत्त.चरमः_file_name),
		file->true_filename) != 0) {
	वर्ण wd[1024];
	CString cstr;

	यदि (tcov_दत्त.चरमः_func_name)
	    section_ptr_सङ्कलय(tcov_section, 1);
	यदि (tcov_दत्त.चरमः_file_name)
	    section_ptr_सङ्कलय(tcov_section, 1);
	tcov_दत्त.चरमः_func_name = 0;
	cstr_new (&cstr);
	यदि (file->true_filename[0] == '/') {
	    tcov_दत्त.चरमः_file_name = tcov_section->दत्त_विस्थापनम्;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	अन्यथा {
	    getcwd (wd, परिमाण(wd));
	    tcov_दत्त.चरमः_file_name = tcov_section->दत्त_विस्थापनम् + वाक्यदैर्घ्यम्(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_सङ्कलय(tcov_section, cstr.आकार + 1);
	वाक्यं_प्रतिलिख((वर्ण *)ptr, cstr.दत्त);
#यदि_परिभाषितम् _WIN32
        normalize_slashes((वर्ण *)ptr);
#यदि_अन्तः
	cstr_free (&cstr);
    }
    यदि (tcov_दत्त.चरमः_func_name == 0 ||
	वाक्यं_तुलय ((ध्रुव वर्ण *)(tcov_section->दत्त + tcov_दत्त.चरमः_func_name),
		funcname) != 0) {
	आकार_t len;

	यदि (tcov_दत्त.चरमः_func_name)
	    section_ptr_सङ्कलय(tcov_section, 1);
	tcov_दत्त.चरमः_func_name = tcov_section->दत्त_विस्थापनम्;
	len = वाक्यदैर्घ्यम् (funcname);
	ptr = section_ptr_सङ्कलय(tcov_section, len + 1);
	वाक्यं_प्रतिलिख((वर्ण *)ptr, funcname);
	section_ptr_सङ्कलय(tcov_section, -tcov_section->दत्त_विस्थापनम् & 7);
	ptr = section_ptr_सङ्कलय(tcov_section, 8);
	write64le (ptr, file->पङ्क्तिः_अङ्कः);
    }
    यदि (ind == tcov_दत्त.ind && tcov_दत्त.पङ्क्तिः == file->पङ्क्तिः_अङ्कः)
        tcov_दत्त.विस्थापनम् = चरमः_विस्थापनम्;
    अन्यथा {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_सङ्कलय(tcov_section, 16);
        tcov_दत्त.पङ्क्तिः = file->पङ्क्तिः_अङ्कः;
        write64le (ptr, (tcov_दत्त.पङ्क्तिः << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((अचिह्नित वर्ण *)ptr - tcov_section->दत्त) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#यदि defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || \
    defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || \
    defined TCC_TARGET_RISCV64
        gen_increment_tcov (&sv);
#अन्यथा
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#यदि_अन्तः
        tcov_दत्त.विस्थापनम् = (अचिह्नित वर्ण *)ptr - tcov_section->दत्त;
        tcov_दत्त.ind = ind;
    }
}

ST_FUNC शून्य tcc_tcov_खण्डम्_अन्तः(TCCState *s1, पूर्णाङ्क पङ्क्तिः)
{
    यदि (s1->test_coverage == 0)
	प्रत्यागम;
    यदि (पङ्क्तिः == -1)
        पङ्क्तिः = tcov_दत्त.पङ्क्तिः;
    यदि (tcov_दत्त.विस्थापनम्) {
	शून्य *ptr = tcov_section->दत्त + tcov_दत्त.विस्थापनम्;
	अचिह्नित दीर्घ दीर्घ nline = पङ्क्तिः ? पङ्क्तिः : file->पङ्क्तिः_अङ्कः;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_दत्त.विस्थापनम् = 0;
    }
}

ST_FUNC शून्य tcc_tcov_check_पङ्क्तिः(TCCState *s1, पूर्णाङ्क start)
{
    यदि (s1->test_coverage == 0)
	प्रत्यागम;
    यदि (tcov_दत्त.पङ्क्तिः != file->पङ्क्तिः_अङ्कः) {
        यदि ((tcov_दत्त.पङ्क्तिः + 1) != file->पङ्क्तिः_अङ्कः) {
	    tcc_tcov_खण्डम्_अन्तः (s1, -1);
	    यदि (start)
                tcc_tcov_खण्डम्_begin (s1);
	}
	अन्यथा
	    tcov_दत्त.पङ्क्तिः = file->पङ्क्तिः_अङ्कः;
    }
}

ST_FUNC शून्य tcc_tcov_start(TCCState *s1)
{
    यदि (s1->test_coverage == 0)
	प्रत्यागम;
    यदि (!s1->dState)
        s1->dState = tcc_mallocz(परिमाण *s1->dState);
    स्मृतिं_पूरय (&tcov_दत्त, 0, परिमाण (tcov_दत्त));
    यदि (tcov_section == रिक्त) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_सङ्कलय(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC शून्य tcc_tcov_अन्तः(TCCState *s1)
{
    यदि (s1->test_coverage == 0)
	प्रत्यागम;
    यदि (tcov_दत्त.चरमः_func_name)
        section_ptr_सङ्कलय(tcov_section, 1);
    यदि (tcov_दत्त.चरमः_file_name)
        section_ptr_सङ्कलय(tcov_section, 1);
}

ST_FUNC शून्य tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_दत्त.ind = 0;
}

/* ------------------------------------------------------------------------- */
#अपरिभाषय चरमः_पङ्क्तिः_अङ्कः
#अपरिभाषय new_file
#अपरिभाषय section_sym
#अपरिभाषय debug_अग्र_type
#अपरिभाषय debug_hash_global
#अपरिभाषय debug_hash_local
#अपरिभाषय n_debug_hash_global
#अपरिभाषय n_debug_hash_local
#अपरिभाषय debug_forw_hash_global
#अपरिभाषय debug_forw_hash_local
#अपरिभाषय n_debug_forw_hash_global
#अपरिभाषय n_debug_forw_hash_local
#अपरिभाषय debug_info
#अपरिभाषय debug_info_मूलम्
#अपरिभाषय dwarf_sym
#अपरिभाषय dwarf_पङ्क्तिः
#अपरिभाषय dwarf_info
#अपरिभाषय dwarf_str
#अपरिभाषय dwarf_पङ्क्तिः_str
#अपरिभाषय tcov_दत्त
