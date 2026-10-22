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
  صحيح سائيز;
  صحيح encoding;
  ثابت حرف *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#إذا LONG_سائيز == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#وإلا
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#جيڪڏهن_پورو
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#إذا LONG_سائيز == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#وإلا
    /* use octal instead of -1 so size_t works (-gstabs+ in gcc) */
    {   VT_LLONG | VT_LONG | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t5=r5;0;01777777777777777777777;" },
#جيڪڏهن_پورو
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
#جيڪڏهن_وصف_ٿيل TCC_USING_DOUBLE_FOR_LDOUBLE
    {   VT_DOUBLE | VT_LONG, 8, DW_ATE_float, "long double:t16=r1;8;0;" },
#وإلا
    {   VT_LDOUBLE, 16, DW_ATE_float, "long double:t16=r1;16;0;" },
#جيڪڏهن_پورو
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
#إذا LONG_سائيز == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#وإلا
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#جيڪڏهن_پورو
};

#وصف_ڪريو	N_DEFAULT_DEBUG	(حجم (default_debug) / حجم (default_debug[0]))

/* dwarf debug */

#وصف_ڪريو	DWARF_سٽ_بنياد				-5
#وصف_ڪريو	DWARF_سٽ_RANGE			14
#وصف_ڪريو	DWARF_OPCODE_بنياد			13

#إذا defined TCC_هدف_ARM64
#وصف_ڪريو	DWARF_MIN_INSTR_LEN			4
#وإلاإذا defined TCC_هدف_ARM
#وصف_ڪريو	DWARF_MIN_INSTR_LEN			2
#وإلا
#وصف_ڪريو	DWARF_MIN_INSTR_LEN			1
#جيڪڏهن_پورو

#وصف_ڪريو	DWARF_ABBREV_COMPILE_UNIT		1
#وصف_ڪريو	DWARF_ABBREV_بنياد_TYPE			2
#وصف_ڪريو	DWARF_ABBREV_VARIABLE_EXTERNAL		3
#وصف_ڪريو	DWARF_ABBREV_VARIABLE_STATIC		4
#وصف_ڪريو	DWARF_ABBREV_VARIABLE_LOCAL		5
#وصف_ڪريو	DWARF_ABBREV_FORMAL_PARAMETER		6
#وصف_ڪريو	DWARF_ABBREV_اشارو			7
#وصف_ڪريو	DWARF_ABBREV_ARRAY_TYPE			8
#وصف_ڪريو	DWARF_ABBREV_SUBRANGE_TYPE		9
#وصف_ڪريو	DWARF_ABBREV_TYPEDEF			10
#وصف_ڪريو	DWARF_ABBREV_ENUMERATOR_SIGNED		11
#وصف_ڪريو	DWARF_ABBREV_ENUMERATOR_UNSIGNED	12
#وصف_ڪريو	DWARF_ABBREV_ENUMERATION_TYPE		13
#وصف_ڪريو	DWARF_ABBREV_MEMBER			14
#وصف_ڪريو	DWARF_ABBREV_MEMBER_BF			15
#وصف_ڪريو	DWARF_ABBREV_STRUCTURE_TYPE		16
#وصف_ڪريو	DWARF_ABBREV_STRUCTURE_خالي_جايون_TYPE	17
#وصف_ڪريو	DWARF_ABBREV_UNION_TYPE			18
#وصف_ڪريو	DWARF_ABBREV_UNION_خالي_جايون_TYPE		19
#وصف_ڪريو	DWARF_ABBREV_SUBPROGRAM_EXTERNAL	20
#وصف_ڪريو	DWARF_ABBREV_SUBPROGRAM_STATIC		21
#وصف_ڪريو	DWARF_ABBREV_LEXICAL_بلاڪ		22
#وصف_ڪريو	DWARF_ABBREV_LEXICAL_خالي_جايون_بلاڪ	23
#وصف_ڪريو	DWARF_ABBREV_SUBROUTINE_TYPE		24
#وصف_ڪريو	DWARF_ABBREV_SUBROUTINE_خالي_جايون_TYPE	25
#وصف_ڪريو	DWARF_ABBREV_FORMAL_PARAMETER2		26

/* all entries should have been generated with dwarf_uleb128 except
   has_children. All values are currently below 128 so this currently
   works.  */
ساكن ثابت بنانشان حرف dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_ٽيگ_compile_unit, 1,
          DW_AT_پيداوار_ڪندڙ, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_سٽ_strp,
          DW_AT_comp_dir, DW_FORM_سٽ_strp,
          DW_AT_هيٺيون_pc, DW_FORM_addr,
#إذا PTR_سائيز == 4
          DW_AT_مٿاهون_pc, DW_FORM_data4,
#وإلا
          DW_AT_مٿاهون_pc, DW_FORM_data8,
#جيڪڏهن_پورو
          DW_AT_stmt_list, DW_FORM_sec_وٿي,
          0, 0,
    DWARF_ABBREV_بنياد_TYPE, DW_ٽيگ_بنياد_type, 0,
          DW_AT_byte_سائيز, DW_FORM_udata,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_name, DW_FORM_strp,
          0, 0,
    DWARF_ABBREV_VARIABLE_EXTERNAL, DW_ٽيگ_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سٽ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_ٽيگ_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سٽ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_LOCAL, DW_ٽيگ_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER, DW_ٽيگ_formal_parameter, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_اشارو, DW_ٽيگ_اشارو_type, 0,
          DW_AT_byte_سائيز, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ARRAY_TYPE, DW_ٽيگ_array_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBRANGE_TYPE, DW_ٽيگ_subrange_type, 0,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_مٿانهون_bound, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_TYPEDEF, DW_ٽيگ_typedef, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سٽ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_ٽيگ_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_قدر, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_ٽيگ_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_قدر, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_ٽيگ_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_سائيز, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سٽ, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_ٽيگ_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سٽ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_معلومات_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_ٽيگ_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سٽ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ٻٽو_انگ_سائيز, DW_FORM_udata,
          DW_AT_معلومات_ٻٽو_انگ_وٿي, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_ٽيگ_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_سائيز, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سٽ, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_خالي_جايون_TYPE, DW_ٽيگ_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_سائيز, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سٽ, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_ٽيگ_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_سائيز, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سٽ, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_خالي_جايون_TYPE, DW_ٽيگ_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_سائيز, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سٽ, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_ٽيگ_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سٽ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_هيٺيون_pc, DW_FORM_addr,
#إذا PTR_سائيز == 4
          DW_AT_مٿاهون_pc, DW_FORM_data4,
#وإلا
          DW_AT_مٿاهون_pc, DW_FORM_data8,
#جيڪڏهن_پورو
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_چوکٺو_بنياد, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_ٽيگ_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_سٽ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_هيٺيون_pc, DW_FORM_addr,
#إذا PTR_سائيز == 4
          DW_AT_مٿاهون_pc, DW_FORM_data4,
#وإلا
          DW_AT_مٿاهون_pc, DW_FORM_data8,
#جيڪڏهن_پورو
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_چوکٺو_بنياد, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_بلاڪ, DW_ٽيگ_lexical_بلاڪ, 1,
          DW_AT_هيٺيون_pc, DW_FORM_addr,
#إذا PTR_سائيز == 4
          DW_AT_مٿاهون_pc, DW_FORM_data4,
#وإلا
          DW_AT_مٿاهون_pc, DW_FORM_data8,
#جيڪڏهن_پورو
          0, 0,
    DWARF_ABBREV_LEXICAL_خالي_جايون_بلاڪ, DW_ٽيگ_lexical_بلاڪ, 0,
          DW_AT_هيٺيون_pc, DW_FORM_addr,
#إذا PTR_سائيز == 4
          DW_AT_مٿاهون_pc, DW_FORM_data4,
#وإلا
          DW_AT_مٿاهون_pc, DW_FORM_data8,
#جيڪڏهن_پورو
          0, 0,
    DWARF_ABBREV_SUBROUTINE_TYPE, DW_ٽيگ_subroutine_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBROUTINE_خالي_جايون_TYPE, DW_ٽيگ_subroutine_type, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER2, DW_ٽيگ_formal_parameter, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
  0
};

ساكن ثابت بنانشان حرف dwarf_سٽ_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#وصف_ڪريو N_STR_HASH (251)

بنية dwarf_str_hash {
    صحيح len;
    بنانشان ڊگهو معلومات_وٿي;
    بنية dwarf_str_hash *ايندڙ;
};

بنية _tccdbg {

    صحيح آخري_سٽ_انگ, new_file;
    صحيح section_sym;

    صحيح debug_ايندڙ_type;

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
        صحيح شروعات;
        صحيح پڇاڙي;
        صحيح آخري_debug_hash;
        صحيح آخري_debug_forw_hash;
        صحيح n_sym;
        بنية debug_sym {
            صحيح type;
            بنانشان ڊگهو قدر;
            حرف *str;
            Section *sec;
            صحيح sym_اشاريو;
            صحيح info;
            صحيح file;
            صحيح سٽ;
        } *sym;
        بنية _debug_info *ٻار, *ايندڙ, *آخري, *والد;
    } *debug_info, *debug_info_پاڙ;

    بنية {
        صحيح info;
        صحيح abbrev;
        صحيح سٽ;
        صحيح str;
        صحيح سٽ_str;
    } dwarf_sym;

    بنية {
        صحيح شروعات;
        صحيح dir_سائيز;
        حرف **dir_جدول;
        صحيح filename_سائيز;
        بنية dwarf_filename_struct {
            صحيح dir_داخلا;
            حرف *name;
        } *filename_جدول;
        صحيح سٽ_سائيز;
        صحيح سٽ_max_سائيز;
        بنانشان حرف *سٽ_معلومات;
        صحيح cur_file;
        صحيح آخري_file;
        صحيح آخري_pc;
        صحيح آخري_سٽ;
    } dwarf_سٽ;

    بنية {
        صحيح شروعات;
        Sym *func;
        صحيح سٽ;
        صحيح بنياد_type_استعمال_ٿيل[N_DEFAULT_DEBUG];
    } dwarf_info;

    بنية dwarf_str_hash *dwarf_str[N_STR_HASH];
    بنية dwarf_str_hash *dwarf_سٽ_str[N_STR_HASH];

    /* test coverage */
    بنية {
        بنانشان ڊگهو وٿي;
        بنانشان ڊگهو آخري_file_name;
        بنانشان ڊگهو آخري_func_name;
        صحيح ind;
        صحيح سٽ;
    } tcov_معلومات;
};

#وصف_ڪريو آخري_سٽ_انگ             s1->dState->آخري_سٽ_انگ
#وصف_ڪريو new_file                  s1->dState->new_file
#وصف_ڪريو section_sym               s1->dState->section_sym
#وصف_ڪريو debug_ايندڙ_type           s1->dState->debug_ايندڙ_type
#وصف_ڪريو debug_hash_global         s1->dState->debug_hash_global
#وصف_ڪريو debug_hash_local          s1->dState->debug_hash_local
#وصف_ڪريو debug_forw_hash_global    s1->dState->debug_forw_hash_global
#وصف_ڪريو debug_forw_hash_local     s1->dState->debug_forw_hash_local
#وصف_ڪريو n_debug_hash_global       s1->dState->n_debug_hash_global
#وصف_ڪريو n_debug_hash_local        s1->dState->n_debug_hash_local
#وصف_ڪريو n_debug_forw_hash_global  s1->dState->n_debug_forw_hash_global
#وصف_ڪريو n_debug_forw_hash_local   s1->dState->n_debug_forw_hash_local
#وصف_ڪريو debug_info                s1->dState->debug_info
#وصف_ڪريو debug_info_پاڙ           s1->dState->debug_info_پاڙ
#وصف_ڪريو dwarf_sym                 s1->dState->dwarf_sym
#وصف_ڪريو dwarf_سٽ                s1->dState->dwarf_سٽ
#وصف_ڪريو dwarf_info                s1->dState->dwarf_info
#وصف_ڪريو dwarf_str                 s1->dState->dwarf_str
#وصف_ڪريو dwarf_سٽ_str            s1->dState->dwarf_سٽ_str
#وصف_ڪريو tcov_معلومات                 s1->dState->tcov_معلومات

#وصف_ڪريو	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
ساكن صحيح put_stabs(TCCState *s1, ثابت حرف *str, صحيح type, صحيح other,
    صحيح desc, بنانشان ڊگهو قدر);

ST_FUNC فراغ tcc_debug_new(TCCState *s1)
{
    صحيح shf = 0;
    إذا (!s1->dState)
        s1->dState = tcc_mallocz(حجم *s1->dState);

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    إذا (s1->do_debug && s1->output_type == TCC_OUTPUT_يادگيري)
        s1->do_backtrace = 1;
    إذا (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#جيڪڏهن_پورو

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
        dwarf_سٽ_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	لكل (i = 0; i < حجم(debug)/حجم(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_ملايو | SHF_لڙيون;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_سٽ_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	إذا (s1->dwarf >= 5) {
            dwarf_سٽ_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_سٽ_str_section->sh_entsize = 1;
	    dwarf_سٽ_str_section->sh_addralign = 1;
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
                      بنانشان ڊگهو قدر)
{
    Stab_Sym *sym;

    بنانشان وٿي;
    إذا (type == N_SLINE
        && (وٿي = stab_section->معلومات_وٿي)
        && (sym = (Stab_Sym*)(stab_section->معلومات + وٿي) - 1)
        && sym->n_type == type
        && sym->n_قدر == قدر) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        أرجع 0;
    }

    sym = section_ptr_جوڙيو(stab_section, حجم(Stab_Sym));
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
                        بنانشان ڊگهو قدر, Section *sec, صحيح sym_اشاريو)
{
    إذا (put_stabs(s1, str, type, other, desc, قدر))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->معلومات_وٿي - 4,
                      حجم ((Stab_Sym*)0)->n_قدر == PTR_سائيز ? R_معلومات_PTR : R_معلومات_32,
                      sym_اشاريو);
}

ساكن فراغ put_stabn(TCCState *s1, صحيح type, صحيح other, صحيح desc, صحيح قدر)
{
    put_stabs(s1, عدم, type, other, desc, قدر);
}

/* ------------------------------------------------------------------------- */
#وصف_ڪريو	dwarf_data1(s,معلومات) \
	(*(uint8_t*)section_ptr_جوڙيو((s), 1) = (معلومات))
#وصف_ڪريو	dwarf_data2(s,معلومات) \
	write16le(section_ptr_جوڙيو((s), 2), (معلومات))
#وصف_ڪريو	dwarf_data4(s,معلومات) \
	write32le(section_ptr_جوڙيو((s), 4), (معلومات))
#وصف_ڪريو	dwarf_data8(s,معلومات) \
	write64le(section_ptr_جوڙيو((s), 8), (معلومات))

ساكن صحيح dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    أرجع put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_انگ, عدم);
}

ساكن فراغ dwarf_reloc(Section *s, صحيح sym, صحيح rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->معلومات_وٿي, rel, sym, 0);
}

ساكن فراغ free_str(بنية dwarf_str_hash **str)
{
    صحيح i;

    لكل (i = 0; i < N_STR_HASH; i++) {
       طالما (str[i]) {
           بنية dwarf_str_hash *ايندڙ = str[i]->ايندڙ;

           tcc_free(str[i]);
           str[i] = ايندڙ;
       }
    }
}

ساكن بنانشان str_hash(ثابت حرف *s)
{
    بنانشان h = 5381;

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
	dw == dwarf_str_section ? dwarf_str : dwarf_سٽ_str;

    len = لڙي_ڊيگهه(str) + 1;
    new_hash = dw_hash[hash];
    طالما (new_hash) {
	إذا (new_hash->len == len &&
	    !memcmp(str, dw->معلومات + new_hash->معلومات_وٿي, len))
	    اكسر;
	new_hash = new_hash->ايندڙ;
    }
    إذا (new_hash == عدم) {
	بنانشان ڊگهو وٿي = dw->معلومات_وٿي;

        new_hash = dw_hash[hash];
        طالما (new_hash) {
	    بنانشان ڊگهو n = new_hash->معلومات_وٿي + new_hash->len - len;

	    إذا (new_hash->len > len &&
	        !memcmp(str, dw->معلومات + n, len)) {
		وٿي = n;
		اكسر;
	    }
	    new_hash = new_hash->ايندڙ;
        }
	إذا (new_hash == عدم) {
	    ptr = section_ptr_جوڙيو(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (بنية dwarf_str_hash *)
	    tcc_malloc(حجم(بنية dwarf_str_hash));
	new_hash->len = len;
	new_hash->معلومات_وٿي = وٿي;
	new_hash->ايندڙ = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->معلومات_وٿي, R_معلومات_32_DW, sym,
                   PTR_سائيز == 4 ? 0 : new_hash->معلومات_وٿي);
    dwarf_data4(s, PTR_سائيز == 4 ? new_hash->معلومات_وٿي : 0);
}

ساكن فراغ dwarf_strp(Section *s, ثابت حرف *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

ساكن فراغ dwarf_سٽ_strp(Section *s, ثابت حرف *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_سٽ_str_section, dwarf_sym.سٽ_str, str);
}

ساكن فراغ dwarf_سٽ_op(TCCState *s1, بنانشان حرف op)
{
    إذا (dwarf_سٽ.سٽ_سائيز >= dwarf_سٽ.سٽ_max_سائيز) {
	dwarf_سٽ.سٽ_max_سائيز += 1024;
	dwarf_سٽ.سٽ_معلومات =
	    (بنانشان حرف *)tcc_realloc(dwarf_سٽ.سٽ_معلومات,
					 dwarf_سٽ.سٽ_max_سائيز);
    }
    dwarf_سٽ.سٽ_معلومات[dwarf_سٽ.سٽ_سائيز++] = op;
}

ساكن فراغ dwarf_file(TCCState *s1)
{
    صحيح i, j;
    حرف *filename;
    صحيح اشاريو_وٿي = s1->dwarf < 5;

    إذا (!strcmp(file->filename, "<command line>")) {
        dwarf_سٽ.cur_file = 1;
	أرجع;
    }
    filename = strrchr(file->filename, '/');
    إذا (filename == عدم) {
        لكل (i = 1; i < dwarf_سٽ.filename_سائيز; i++)
            إذا (dwarf_سٽ.filename_جدول[i].dir_داخلا == 0 &&
		strcmp(dwarf_سٽ.filename_جدول[i].name,
		       file->filename) == 0) {
		    dwarf_سٽ.cur_file = i + اشاريو_وٿي;
	            أرجع;
		}
	i = -اشاريو_وٿي;
	filename = file->filename;
    }
    وإلا {
	حرف *undo = filename;
	حرف *dir = file->filename;

	*filename++ = '\0';
        لكل (i = 0; i < dwarf_سٽ.dir_سائيز; i++)
	    إذا (strcmp(dwarf_سٽ.dir_جدول[i], dir) == 0) {
		لكل (j = 1; j < dwarf_سٽ.filename_سائيز; j++)
		    إذا (dwarf_سٽ.filename_جدول[j].dir_داخلا - اشاريو_وٿي
			== i &&
			strcmp(dwarf_سٽ.filename_جدول[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_سٽ.cur_file = j + اشاريو_وٿي;
			أرجع;
		    }
		اكسر;
	    }
	إذا (i == dwarf_سٽ.dir_سائيز) {
	    dwarf_سٽ.dir_سائيز++;
	    dwarf_سٽ.dir_جدول =
                (حرف **) tcc_realloc(dwarf_سٽ.dir_جدول,
                                      dwarf_سٽ.dir_سائيز *
                                      حجم (حرف *));
            dwarf_سٽ.dir_جدول[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_سٽ.filename_جدول =
        (بنية dwarf_filename_struct *)
        tcc_realloc(dwarf_سٽ.filename_جدول,
                    (dwarf_سٽ.filename_سائيز + 1) *
                    حجم (بنية dwarf_filename_struct));
    dwarf_سٽ.filename_جدول[dwarf_سٽ.filename_سائيز].dir_داخلا =
	i + اشاريو_وٿي;
    dwarf_سٽ.filename_جدول[dwarf_سٽ.filename_سائيز].name =
        tcc_strdup(filename);
    dwarf_سٽ.cur_file = dwarf_سٽ.filename_سائيز++ + اشاريو_وٿي;
    أرجع;
}

#إذا 0
ساكن صحيح dwarf_uleb128_سائيز (بنانشان ڊگهو ڊگهو قدر)
{
    صحيح سائيز =  0;

    افعل {
        قدر >>= 7;
        سائيز++;
    } طالما (قدر != 0);
    أرجع سائيز;
}
#جيڪڏهن_پورو

ساكن صحيح dwarf_sleb128_سائيز (ڊگهو ڊگهو قدر)
{
    صحيح سائيز =  0;
    ڊگهو ڊگهو پڇاڙي = قدر >> 63;
    بنانشان حرف آخري = پڇاڙي & 0x40;
    بنانشان حرف byte;

    افعل {
        byte = قدر & 0x7f;
        قدر >>= 7;
        سائيز++;
    } طالما (قدر != پڇاڙي || (byte & 0x40) != آخري);
    أرجع سائيز;
}

ساكن فراغ dwarf_uleb128 (Section *s, بنانشان ڊگهو ڊگهو قدر)
{
    افعل {
        بنانشان حرف byte = قدر & 0x7f;

        قدر >>= 7;
        dwarf_data1(s, byte | (قدر ? 0x80 : 0));
    } طالما (قدر != 0);
}

ساكن فراغ dwarf_sleb128 (Section *s, ڊگهو ڊگهو قدر)
{
    صحيح وڌيڪ;
    ڊگهو ڊگهو پڇاڙي = قدر >> 63;
    بنانشان حرف آخري = پڇاڙي & 0x40;

    افعل {
        بنانشان حرف byte = قدر & 0x7f;

        قدر >>= 7;
	وڌيڪ = قدر != پڇاڙي || (byte & 0x40) != آخري;
        dwarf_data1(s, byte | (0x80 * وڌيڪ));
    } طالما (وڌيڪ);
}

ساكن فراغ dwarf_uleb128_op (TCCState *s1, بنانشان ڊگهو ڊگهو قدر)
{
    افعل {
        بنانشان حرف byte = قدر & 0x7f;

        قدر >>= 7;
        dwarf_سٽ_op(s1, byte | (قدر ? 0x80 : 0));
    } طالما (قدر != 0);
}

ساكن فراغ dwarf_sleb128_op (TCCState *s1, ڊگهو ڊگهو قدر)
{
    صحيح وڌيڪ;
    ڊگهو ڊگهو پڇاڙي = قدر >> 63;
    بنانشان حرف آخري = پڇاڙي & 0x40;

    افعل {
        بنانشان حرف byte = قدر & 0x7f;

        قدر >>= 7;
        وڌيڪ = قدر != پڇاڙي || (byte & 0x40) != آخري;
        dwarf_سٽ_op(s1, byte | (0x80 * وڌيڪ));
    } طالما (وڌيڪ);
}

#إذا TCC_EH_چوکٺو
ST_FUNC فراغ tcc_eh_چوکٺو_شروعات(TCCState *s1)
{
    إذا (!s1->unwind_tables)
        أرجع;
    eh_چوکٺو_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_شروعات = eh_چوکٺو_section->معلومات_وٿي;
    dwarf_data4(eh_چوکٺو_section, 0); //ڊيگهائي
    dwarf_data4(eh_چوکٺو_section, 0); // CIE ID
    dwarf_data1(eh_چوکٺو_section, 1); //نسخو
    dwarf_data1(eh_چوکٺو_section, 'z'); // Augmentation String
    dwarf_data1(eh_چوکٺو_section, 'R');
    dwarf_data1(eh_چوکٺو_section, 0);
#إذا defined TCC_هدف_I386
    dwarf_uleb128(eh_چوکٺو_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_چوکٺو_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_چوکٺو_section, 8); // return address column
    dwarf_uleb128(eh_چوکٺو_section, 1); // Augmentation len
    dwarf_data1(eh_چوکٺو_section, FDE_ENCODING);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکٺو_section, 4); // r4 (esp)
    dwarf_uleb128(eh_چوکٺو_section, 4); // ofs 4
    dwarf_data1(eh_چوکٺو_section, DW_CFA_وٿي + 8); // r8 (eip)
    dwarf_uleb128(eh_چوکٺو_section, 1); // cfa-4
#وإلاإذا defined TCC_هدف_X86_64
    dwarf_uleb128(eh_چوکٺو_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_چوکٺو_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_چوکٺو_section, 16); // return address column
    dwarf_uleb128(eh_چوکٺو_section, 1); // Augmentation len
    dwarf_data1(eh_چوکٺو_section, FDE_ENCODING);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکٺو_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_چوکٺو_section, 8); // ofs 8
    dwarf_data1(eh_چوکٺو_section, DW_CFA_وٿي + 16); // r16 (rip)
    dwarf_uleb128(eh_چوکٺو_section, 1); // cfa-8
#وإلاإذا defined TCC_هدف_ARM
    /* TODO: arm must be compiled with: -funwind-tables */
    /* arm also uses .ARM.extab and .ARM.exidx sections */
    dwarf_uleb128(eh_چوکٺو_section, 2); // code_alignment_factor
    dwarf_sleb128(eh_چوکٺو_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_چوکٺو_section, 14); // return address column
    dwarf_uleb128(eh_چوکٺو_section, 1); // Augmentation len
    dwarf_data1(eh_چوکٺو_section, FDE_ENCODING);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکٺو_section, 13); // r13 (sp)
    dwarf_uleb128(eh_چوکٺو_section, 0); // ofs 0
#وإلاإذا defined TCC_هدف_ARM64
    dwarf_uleb128(eh_چوکٺو_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_چوکٺو_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_چوکٺو_section, 30); // return address column
    dwarf_uleb128(eh_چوکٺو_section, 1); // Augmentation len
    dwarf_data1(eh_چوکٺو_section, FDE_ENCODING);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکٺو_section, 31); // x31 (sp)
    dwarf_uleb128(eh_چوکٺو_section, 0); // ofs 0
#وإلاإذا defined TCC_هدف_RISCV64
    eh_چوکٺو_section->معلومات[s1->eh_شروعات + 8] = 3; // version = 3
    dwarf_uleb128(eh_چوکٺو_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_چوکٺو_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_چوکٺو_section, 1); // return address column
    dwarf_uleb128(eh_چوکٺو_section, 1); // Augmentation len
    dwarf_data1(eh_چوکٺو_section, FDE_ENCODING);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکٺو_section, 2); // r2 (sp)
    dwarf_uleb128(eh_چوکٺو_section, 0); // ofs 0
#جيڪڏهن_پورو
    طالما ((eh_چوکٺو_section->معلومات_وٿي - s1->eh_شروعات) & 3)
	dwarf_data1(eh_چوکٺو_section, DW_CFA_nop);
    write32le(eh_چوکٺو_section->معلومات + s1->eh_شروعات, //ڊيگهائي
	      eh_چوکٺو_section->معلومات_وٿي - s1->eh_شروعات - 4);
}

ساكن فراغ tcc_debug_چوکٺو_پڇاڙي(TCCState *s1, صحيح سائيز)
{
    صحيح eh_section_sym;
    بنانشان ڊگهو fde_شروعات;

    إذا (!eh_چوکٺو_section)
	أرجع;
    eh_section_sym = dwarf_get_section_sym(متن_section);
    fde_شروعات = eh_چوکٺو_section->معلومات_وٿي;
    dwarf_data4(eh_چوکٺو_section, 0); //ڊيگهائي
    dwarf_data4(eh_چوکٺو_section,
		fde_شروعات - s1->eh_شروعات + 4); // CIE Pointer
#إذا defined TCC_هدف_I386
    dwarf_reloc(eh_چوکٺو_section, eh_section_sym, R_386_PC32);
#وإلاإذا defined TCC_هدف_X86_64
    dwarf_reloc(eh_چوکٺو_section, eh_section_sym, R_X86_64_PC32);
#وإلاإذا defined TCC_هدف_ARM
    dwarf_reloc(eh_چوکٺو_section, eh_section_sym, R_ARM_REL32);
#وإلاإذا defined TCC_هدف_ARM64
    dwarf_reloc(eh_چوکٺو_section, eh_section_sym, R_AARCH64_PREL32);
#وإلاإذا defined TCC_هدف_RISCV64
    dwarf_reloc(eh_چوکٺو_section, eh_section_sym, R_RISCV_32_PCREL);
#جيڪڏهن_پورو
    dwarf_data4(eh_چوکٺو_section, func_ind); // PC Begin
    dwarf_data4(eh_چوکٺو_section, سائيز); // PC Range
    dwarf_data1(eh_چوکٺو_section, 0); // Augmentation Length
#إذا defined TCC_هدف_I386
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa_وٿي);
    dwarf_uleb128(eh_چوکٺو_section, 8);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_وٿي + 5); // r5 (ebp)
    dwarf_uleb128(eh_چوکٺو_section, 2); // cfa-8
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa_رجسٽر);
    dwarf_uleb128(eh_چوکٺو_section, 5); // r5 (ebp)
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکٺو_section, سائيز - 5);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_restore + 5); // r5 (ebp)
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکٺو_section, 4); // r4 (esp)
    dwarf_uleb128(eh_چوکٺو_section, 4); // ofs 4
#وإلاإذا defined TCC_هدف_X86_64
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa_وٿي);
    dwarf_uleb128(eh_چوکٺو_section, 16);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_وٿي + 6); // r6 (rbp)
    dwarf_uleb128(eh_چوکٺو_section, 2); // cfa-16
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa_رجسٽر);
    dwarf_uleb128(eh_چوکٺو_section, 6); // r6 (rbp)
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکٺو_section, سائيز - 5);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکٺو_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_چوکٺو_section, 8); // ofs 8
#وإلاإذا defined TCC_هدف_ARM
    /* TODO */
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa_وٿي);
    dwarf_uleb128(eh_چوکٺو_section, 8);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_وٿي + 14); // r14 (lr)
    dwarf_uleb128(eh_چوکٺو_section, 1);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_وٿي + 11); // r11 (fp)
    dwarf_uleb128(eh_چوکٺو_section, 2);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکٺو_section, سائيز / 2 - 5);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa_رجسٽر);
    dwarf_uleb128(eh_چوکٺو_section, 11); // r11 (fp)
#وإلاإذا defined TCC_هدف_ARM64
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa_وٿي);
    dwarf_uleb128(eh_چوکٺو_section, 224);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_وٿي + 29); // x29 (fp)
    dwarf_uleb128(eh_چوکٺو_section, 28); // cfa-224
    dwarf_data1(eh_چوکٺو_section, DW_CFA_وٿي + 30); // x30 (lr)
    dwarf_uleb128(eh_چوکٺو_section, 27); // cfa-216
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa_وٿي);
    dwarf_uleb128(eh_چوکٺو_section, 224 + ((-loc + 15) & ~15));
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_چوکٺو_section, سائيز / 4 - 5);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_restore + 30); // x30 (lr)
    dwarf_data1(eh_چوکٺو_section, DW_CFA_restore + 29); // x29 (fp)
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa_وٿي);
    dwarf_uleb128(eh_چوکٺو_section, 0);
#وإلاإذا defined TCC_هدف_RISCV64
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa_وٿي);
    dwarf_uleb128(eh_چوکٺو_section, 16); // ofs 16
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_وٿي + 1); // r1 (ra, lr)
    dwarf_uleb128(eh_چوکٺو_section, 2); // cfa-8
    dwarf_data1(eh_چوکٺو_section, DW_CFA_وٿي + 8); // r8 (s0, fp)
    dwarf_uleb128(eh_چوکٺو_section, 4); // cfa-16
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکٺو_section, 8); // r8 (s0, fp)
    dwarf_uleb128(eh_چوکٺو_section, 0); // ofs 0
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc4);
    طالما (سائيز >= 4 &&
	   read32le(cur_متن_section->معلومات + func_ind + سائيز - 4) != 0x00008067)
	سائيز -= 4;
    dwarf_data4(eh_چوکٺو_section, سائيز - 36);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_چوکٺو_section, 2); // r2 (r2, sp)
    dwarf_uleb128(eh_چوکٺو_section, 16); // ofs 16
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_restore + 1); // r1 (lr)
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_restore + 8); // r8 (s0, fp)
    dwarf_data1(eh_چوکٺو_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_چوکٺو_section, DW_CFA_def_cfa_وٿي);
    dwarf_uleb128(eh_چوکٺو_section, 0); // ofs 0
#جيڪڏهن_پورو
    طالما ((eh_چوکٺو_section->معلومات_وٿي - fde_شروعات) & 3)
	dwarf_data1(eh_چوکٺو_section, DW_CFA_nop);
    write32le(eh_چوکٺو_section->معلومات + fde_شروعات, //ڊيگهائي
	      eh_چوکٺو_section->معلومات_وٿي - fde_شروعات - 4);
}

ST_FUNC فراغ tcc_eh_چوکٺو_پڇاڙي(TCCState *s1)
{
    إذا (!eh_چوکٺو_section)
	أرجع;
    dwarf_data4(eh_چوکٺو_section, 0);
}

بنية eh_ڳولا_جدول {
    uint32_t pc_وٿي;
    uint32_t fde_وٿي;
};

ساكن صحيح ترتيب_ڏيو_eh_جدول(ثابت فراغ *a, ثابت فراغ *b)
{
    uint32_t pc1 = ((ثابت بنية eh_ڳولا_جدول *)a)->pc_وٿي;
    uint32_t pc2 = ((ثابت بنية eh_ڳولا_جدول *)b)->pc_وٿي;

    أرجع pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC فراغ tcc_eh_چوکٺو_hdr(TCCState *s1, صحيح final)
{
    صحيح ڳڻپ_2 = 0, وٿي;
    بنانشان ڊگهو ڳڻپ_وٿي, tab_وٿي;
    بنانشان حرف *ln, *پڇاڙي;
    بنانشان صحيح آخري_cie_وٿي = 0xffffffff;

    إذا (!eh_چوکٺو_section || !eh_چوکٺو_section->معلومات_وٿي)
	أرجع;
    إذا (final && !eh_چوکٺو_hdr_section)
	أرجع;
    إذا (final == 0)
        eh_چوکٺو_hdr_section =
	    new_section(s1, ".eh_frame_hdr", SHT_PROGBITS, SHF_ALLOC);
    eh_چوکٺو_hdr_section->معلومات_وٿي = 0;
    dwarf_data1(eh_چوکٺو_hdr_section, 1); //نسخو
    // Pointer Encoding Format
    dwarf_data1(eh_چوکٺو_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_pcrel);
    // Count Encoding Format
    dwarf_data1(eh_چوکٺو_hdr_section, DW_EH_PE_udata4 | DW_EH_PE_absptr);
    // Table Encoding Format
    dwarf_data1(eh_چوکٺو_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_datarel);
    وٿي = eh_چوکٺو_section->sh_addr -
             eh_چوکٺو_hdr_section->sh_addr -
             eh_چوکٺو_hdr_section->معلومات_وٿي;
    dwarf_data4(eh_چوکٺو_hdr_section, وٿي); // eh_frame_ptr
    //ڳڻپ
    ڳڻپ_وٿي = eh_چوکٺو_hdr_section->معلومات_وٿي;
    dwarf_data4(eh_چوکٺو_hdr_section, 0);
    tab_وٿي = eh_چوکٺو_hdr_section->معلومات_وٿي;
    ln = eh_چوکٺو_section->معلومات;
    پڇاڙي = eh_چوکٺو_section->معلومات + eh_چوکٺو_section->معلومات_وٿي;
    طالما (ln < پڇاڙي) {
	بنانشان حرف *fde = ln, *rd = ln;
	بنانشان صحيح cie_وٿي, نسخو, ڊيگهائي = dwarf_read_4(rd, پڇاڙي);
	بنانشان صحيح pc_وٿي, fde_وٿي;

	إذا (ڊيگهائي == 0)
	    اذهب ايندڙ;
        cie_وٿي = dwarf_read_4(rd, پڇاڙي);
	إذا (cie_وٿي == 0)
	    اذهب ايندڙ;
	إذا (cie_وٿي != آخري_cie_وٿي) {
	    بنانشان حرف *cie = rd - cie_وٿي + 4;

	    إذا (cie < eh_چوکٺو_section->معلومات)
		اذهب ايندڙ;
	    نسخو = dwarf_read_1(cie, پڇاڙي);
	    إذا ((نسخو == 1 || نسخو == 3) &&
	        dwarf_read_1(cie, پڇاڙي) == 'z' && // Augmentation String
		dwarf_read_1(cie, پڇاڙي) == 'R' &&
		dwarf_read_1(cie, پڇاڙي) == 0) {
	        dwarf_read_uleb128(&cie, پڇاڙي); // code_alignment_factor
	        dwarf_read_sleb128(&cie, پڇاڙي); // data_alignment_factor
		dwarf_read_1(cie, پڇاڙي); // return address column
		إذا (dwarf_read_uleb128(&cie, پڇاڙي) == 1 &&
		    dwarf_read_1(cie, پڇاڙي) == FDE_ENCODING) {
		    آخري_cie_وٿي = cie_وٿي;
		}
		وإلا
		    اذهب ايندڙ;
	    }
	    وإلا
		اذهب ايندڙ;
	}
	ڳڻپ_2++;
	fde_وٿي = eh_چوکٺو_section->sh_addr +
		     (fde - eh_چوکٺو_section->معلومات) -
		     eh_چوکٺو_hdr_section->sh_addr;
	pc_وٿي = dwarf_read_4(rd, پڇاڙي) + fde_وٿي + 8;
	dwarf_data4(eh_چوکٺو_hdr_section, pc_وٿي);
	dwarf_data4(eh_چوکٺو_hdr_section, fde_وٿي);
ايندڙ:
	ln += ڊيگهائي + 4;
    }
    add32le(eh_چوکٺو_hdr_section->معلومات + ڳڻپ_وٿي, ڳڻپ_2);
    qsort(eh_چوکٺو_hdr_section->معلومات + tab_وٿي, ڳڻپ_2,
	  حجم(بنية eh_ڳولا_جدول), ترتيب_ڏيو_eh_جدول);
}
#جيڪڏهن_پورو

/* start of translation unit info */
ST_FUNC فراغ tcc_debug_شروعات(TCCState *s1)
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
        put_elf_sym(symtab_section, متن_section->معلومات_وٿي, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            متن_section->sh_انگ, "$a");

        new_file = آخري_سٽ_انگ = 0;
        debug_ايندڙ_type = N_DEFAULT_DEBUG;
        debug_hash_global = عدم;
        debug_hash_local = عدم;
        debug_forw_hash_global = عدم;
        debug_forw_hash_local = عدم;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, حجم(buf));
#جيڪڏهن_وصف_ٿيل _WIN32
        normalize_slashes(buf);
#جيڪڏهن_پورو

        إذا (s1->dwarf) {
            صحيح شروعات_abbrev;
            بنانشان حرف *ptr;
	    حرف *undo;

            /* dwarf_abbrev */
            شروعات_abbrev = dwarf_abbrev_section->معلومات_وٿي;
            ptr = section_ptr_جوڙيو(dwarf_abbrev_section, حجم(dwarf_abbrev_init));
            يادگيري_نقل(ptr, dwarf_abbrev_init, حجم(dwarf_abbrev_init));

            إذا (s1->dwarf < 5) {
    	        طالما (*ptr) {
    	            ptr += 3;
    	            طالما (*ptr) {
    	                إذا (ptr[1] == DW_FORM_سٽ_strp)
    		            ptr[1] = DW_FORM_strp;
		        إذا (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    إذا  (ptr[1] == DW_FORM_sec_وٿي)
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
            dwarf_sym.سٽ = dwarf_get_section_sym(dwarf_سٽ_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            إذا (tcc_state->dwarf >= 5)
    	        dwarf_sym.سٽ_str = dwarf_get_section_sym(dwarf_سٽ_str_section);
            وإلا {
    	        dwarf_سٽ_str_section = dwarf_str_section;
                dwarf_sym.سٽ_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(متن_section);

            /* dwarf_info */
            dwarf_info.شروعات = dwarf_info_section->معلومات_وٿي;
            dwarf_data4(dwarf_info_section, 0); //سائيز
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            إذا (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_سائيز);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_معلومات_32_DW);
                dwarf_data4(dwarf_info_section, شروعات_abbrev);
            }
            وإلا {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_معلومات_32_DW);
                dwarf_data4(dwarf_info_section, شروعات_abbrev);
                dwarf_data1(dwarf_info_section, PTR_سائيز);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_نسخو);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_سٽ_strp(dwarf_info_section, filename);
            dwarf_سٽ_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_معلومات_PTR);
#إذا PTR_سائيز == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#وإلا
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#جيڪڏهن_پورو
            dwarf_reloc(dwarf_info_section, dwarf_sym.سٽ, R_معلومات_32_DW);
            dwarf_data4(dwarf_info_section, dwarf_سٽ_section->معلومات_وٿي); // stmt_list

            /* dwarf_line */
            dwarf_سٽ.شروعات = dwarf_سٽ_section->معلومات_وٿي;
            dwarf_data4(dwarf_سٽ_section, 0); //ڊيگهائي
            dwarf_data2(dwarf_سٽ_section, s1->dwarf); // version
            إذا (s1->dwarf >= 5) {
                dwarf_data1(dwarf_سٽ_section, PTR_سائيز); // address size
                dwarf_data1(dwarf_سٽ_section, 0); // segment selector
            }
            dwarf_data4(dwarf_سٽ_section, 0); // prologue Length
            dwarf_data1(dwarf_سٽ_section, DWARF_MIN_INSTR_LEN);
            إذا (s1->dwarf >= 4)
                dwarf_data1(dwarf_سٽ_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_سٽ_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_سٽ_section, DWARF_سٽ_بنياد);
            dwarf_data1(dwarf_سٽ_section, DWARF_سٽ_RANGE);
            dwarf_data1(dwarf_سٽ_section, DWARF_OPCODE_بنياد);
            ptr = section_ptr_جوڙيو(dwarf_سٽ_section, حجم(dwarf_سٽ_opcodes));
            يادگيري_نقل(ptr, dwarf_سٽ_opcodes, حجم(dwarf_سٽ_opcodes));
	    undo = strrchr(filename, '/');
	    إذا (undo)
		*undo = 0;
            dwarf_سٽ.dir_سائيز = 1 + (undo != عدم);
            dwarf_سٽ.dir_جدول = (حرف **) tcc_malloc(حجم (حرف *) *
							dwarf_سٽ.dir_سائيز);
            dwarf_سٽ.dir_جدول[0] = tcc_strdup(buf);
	    إذا (undo)
                dwarf_سٽ.dir_جدول[1] = tcc_strdup(filename);
            dwarf_سٽ.filename_سائيز = 2;
            dwarf_سٽ.filename_جدول =
    	        (بنية dwarf_filename_struct *)
    	        tcc_malloc(2*حجم (بنية dwarf_filename_struct));
            dwarf_سٽ.filename_جدول[0].dir_داخلا = 0;
	    إذا (undo) {
                dwarf_سٽ.filename_جدول[0].name = tcc_strdup(undo + 1);
                dwarf_سٽ.filename_جدول[1].dir_داخلا = 1;
                dwarf_سٽ.filename_جدول[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    وإلا {
                dwarf_سٽ.filename_جدول[0].name = tcc_strdup(filename);
                dwarf_سٽ.filename_جدول[1].dir_داخلا = 0;
                dwarf_سٽ.filename_جدول[1].name = tcc_strdup(filename);
	    }
            dwarf_سٽ.سٽ_سائيز = dwarf_سٽ.سٽ_max_سائيز = 0;
            dwarf_سٽ.سٽ_معلومات = عدم;
            dwarf_سٽ.cur_file = 1;
            dwarf_سٽ.آخري_file = 0;
            dwarf_سٽ.آخري_pc = 0;
            dwarf_سٽ.آخري_سٽ = 1;
            dwarf_سٽ_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_سائيز); // extended size
            dwarf_سٽ_op(s1, DW_LNE_سيٽ_پتو);
            لكل (i = 0; i < PTR_سائيز; i++)
    	        dwarf_سٽ_op(s1, 0);
            memset(&dwarf_info.بنياد_type_استعمال_ٿيل, 0, حجم(dwarf_info.بنياد_type_استعمال_ٿيل));
        }
        وإلا
        {
            /* file info: full path + filename */
            pstrcat(buf, حجم(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      متن_section->sh_انگ, عدم);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        متن_section->معلومات_وٿي, متن_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        متن_section->معلومات_وٿي, متن_section, section_sym);
            لكل (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

ساكن فراغ fix_debug_forw_hash(TCCState *s1, صحيح global, صحيح شروعات);

/* put end of translation unit info */
ST_FUNC فراغ tcc_debug_پڇاڙي(TCCState *s1)
{

    إذا (!s1->do_debug || debug_ايندڙ_type == 0)
        أرجع;

    إذا (debug_info_پاڙ)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    إذا (s1->dwarf) {
	صحيح i;
	صحيح شروعات_aranges;
	بنانشان حرف *ptr;
	صحيح متن_سائيز = متن_section->معلومات_وٿي;

	/* dwarf_info */
	fix_debug_forw_hash(s1, 0, 0);
	fix_debug_forw_hash(s1, 1, 0);
	dwarf_data1(dwarf_info_section, 0);
	ptr = dwarf_info_section->معلومات + dwarf_info.شروعات;
	write32le(ptr, dwarf_info_section->معلومات_وٿي - dwarf_info.شروعات - 4);
	write32le(ptr + 25 + (s1->dwarf >= 5) + PTR_سائيز, متن_سائيز);

	/* dwarf_aranges */
	شروعات_aranges = dwarf_aranges_section->معلومات_وٿي;
	dwarf_data4(dwarf_aranges_section, 0); //سائيز
	dwarf_data2(dwarf_aranges_section, 2); // version
	dwarf_reloc(dwarf_aranges_section, dwarf_sym.info, R_معلومات_32_DW);
	dwarf_data4(dwarf_aranges_section, 0); // dwarf_info
#إذا PTR_سائيز == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#وإلا
	dwarf_data1(dwarf_aranges_section, 8); // address size
#جيڪڏهن_پورو
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_معلومات_PTR);
#إذا PTR_سائيز == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, متن_سائيز); //پڇاڙي
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#وإلا
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, متن_سائيز); //پڇاڙي
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#جيڪڏهن_پورو
	ptr = dwarf_aranges_section->معلومات + شروعات_aranges;
	write32le(ptr, dwarf_aranges_section->معلومات_وٿي - شروعات_aranges - 4);

	/* dwarf_line */
	إذا (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_سٽ_section, 1); /*کانو*/
	    dwarf_uleb128(dwarf_سٽ_section, DW_LNCT_رستو);
	    dwarf_uleb128(dwarf_سٽ_section, DW_FORM_سٽ_strp);
	    dwarf_uleb128(dwarf_سٽ_section, dwarf_سٽ.dir_سائيز);
	    لكل (i = 0; i < dwarf_سٽ.dir_سائيز; i++)
	        dwarf_سٽ_strp(dwarf_سٽ_section, dwarf_سٽ.dir_جدول[i]);
	    dwarf_data1(dwarf_سٽ_section, 2); /*کانو*/
	    dwarf_uleb128(dwarf_سٽ_section, DW_LNCT_رستو);
	    dwarf_uleb128(dwarf_سٽ_section, DW_FORM_سٽ_strp);
	    dwarf_uleb128(dwarf_سٽ_section, DW_LNCT_directory_اشاريو);
	    dwarf_uleb128(dwarf_سٽ_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_سٽ_section, dwarf_سٽ.filename_سائيز);
	    لكل (i = 0; i < dwarf_سٽ.filename_سائيز; i++) {
	        dwarf_سٽ_strp(dwarf_سٽ_section,
				dwarf_سٽ.filename_جدول[i].name);
	        dwarf_uleb128(dwarf_سٽ_section,
			      dwarf_سٽ.filename_جدول[i].dir_داخلا);
	    }
	}
	وإلا {
	    صحيح len;

	    لكل (i = 0; i < dwarf_سٽ.dir_سائيز; i++) {
	        len = لڙي_ڊيگهه(dwarf_سٽ.dir_جدول[i]) + 1;
	        ptr = section_ptr_جوڙيو(dwarf_سٽ_section, len);
	        memmove(ptr, dwarf_سٽ.dir_جدول[i], len);
	    }
	    dwarf_data1(dwarf_سٽ_section, 0); /* end dir */
	    لكل (i = 0; i < dwarf_سٽ.filename_سائيز; i++) {
	        len = لڙي_ڊيگهه(dwarf_سٽ.filename_جدول[i].name) + 1;
	        ptr = section_ptr_جوڙيو(dwarf_سٽ_section, len);
	        memmove(ptr, dwarf_سٽ.filename_جدول[i].name, len);
	        dwarf_uleb128(dwarf_سٽ_section,
			      dwarf_سٽ.filename_جدول[i].dir_داخلا);
	        dwarf_uleb128(dwarf_سٽ_section, 0); /*وقت*/
	        dwarf_uleb128(dwarf_سٽ_section, 0); /*سائيز*/
	    }
	    dwarf_data1(dwarf_سٽ_section, 0); /* end file */
	}
	لكل (i = 0; i < dwarf_سٽ.dir_سائيز; i++)
	    tcc_free(dwarf_سٽ.dir_جدول[i]);
	tcc_free(dwarf_سٽ.dir_جدول);
	لكل (i = 0; i < dwarf_سٽ.filename_سائيز; i++)
	    tcc_free(dwarf_سٽ.filename_جدول[i].name);
	tcc_free(dwarf_سٽ.filename_جدول);

	dwarf_سٽ_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_سٽ_op(s1, DW_LNE_پڇاڙي_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_سٽ_section->معلومات[dwarf_سٽ.شروعات + 6 + i],
		  dwarf_سٽ_section->معلومات_وٿي - dwarf_سٽ.شروعات - (10 + i));
	section_ptr_جوڙيو(dwarf_سٽ_section, 3);
	dwarf_reloc(dwarf_سٽ_section, section_sym, R_معلومات_PTR);
	ptr = section_ptr_جوڙيو(dwarf_سٽ_section, dwarf_سٽ.سٽ_سائيز - 3);
	memmove(ptr - 3, dwarf_سٽ.سٽ_معلومات, dwarf_سٽ.سٽ_سائيز);
	tcc_free(dwarf_سٽ.سٽ_معلومات);
	write32le(dwarf_سٽ_section->معلومات + dwarf_سٽ.شروعات,
		  dwarf_سٽ_section->معلومات_وٿي - dwarf_سٽ.شروعات - 4);
    }
    وإلا
    {
        put_stabs_r(s1, عدم, N_SO, 0, 0,
                    متن_section->معلومات_وٿي, متن_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_سٽ_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_ايندڙ_type = 0;
}

ساكن BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    إذا (f->filename[0] == ':')
        f = f->prev;
    إذا (f && new_file) {
        new_file = آخري_سٽ_انگ = 0;
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
ST_FUNC فراغ tcc_debug_سٽ(TCCState *s1)
{
    BufferedFile *f;

    إذا (!s1->do_debug)
        أرجع;
    إذا (cur_متن_section != متن_section || nocode_wanted)
        أرجع;
    f = put_new_file(s1);
    إذا (!f)
        أرجع;
    إذا (آخري_سٽ_انگ == f->سٽ_انگ)
        أرجع;
    آخري_سٽ_انگ = f->سٽ_انگ;

    إذا (s1->dwarf) {
	صحيح len_pc = (ind - dwarf_سٽ.آخري_pc) / DWARF_MIN_INSTR_LEN;
	صحيح len_سٽ = f->سٽ_انگ - dwarf_سٽ.آخري_سٽ;
	صحيح n = len_pc * DWARF_سٽ_RANGE + len_سٽ + DWARF_OPCODE_بنياد - DWARF_سٽ_بنياد;

	إذا (dwarf_سٽ.cur_file != dwarf_سٽ.آخري_file) {
	    dwarf_سٽ.آخري_file = dwarf_سٽ.cur_file;
	    dwarf_سٽ_op(s1, DW_LNS_سيٽ_file);
	    dwarf_uleb128_op(s1, dwarf_سٽ.cur_file);
	}
	إذا (len_pc &&
	    len_سٽ >= DWARF_سٽ_بنياد && len_سٽ <= (DWARF_OPCODE_بنياد + DWARF_سٽ_بنياد) &&
	    n >= DWARF_OPCODE_بنياد && n <= 255)
            dwarf_سٽ_op(s1, n);
	وإلا {
	    إذا (len_pc) {
	        n = len_pc * DWARF_سٽ_RANGE + 0 + DWARF_OPCODE_بنياد - DWARF_سٽ_بنياد;
	        إذا (n >= DWARF_OPCODE_بنياد && n <= 255)
                    dwarf_سٽ_op(s1, n);
		وإلا {
	            dwarf_سٽ_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    إذا (len_سٽ) {
	        n = 0 * DWARF_سٽ_RANGE + len_سٽ + DWARF_OPCODE_بنياد - DWARF_سٽ_بنياد;
	        إذا (len_سٽ >= DWARF_سٽ_بنياد && len_سٽ <= (DWARF_OPCODE_بنياد + DWARF_سٽ_بنياد) &&
		    n >= DWARF_OPCODE_بنياد && n <= 255)
	            dwarf_سٽ_op(s1, n);
		وإلا {
	            dwarf_سٽ_op(s1, DW_LNS_advance_سٽ);
		    dwarf_sleb128_op(s1, len_سٽ);
                    /* advance by nothing */
	            dwarf_سٽ_op(s1, DWARF_OPCODE_بنياد - DWARF_سٽ_بنياد);
		}
	    }
	}
	dwarf_سٽ.آخري_pc = ind;
	dwarf_سٽ.آخري_سٽ = f->سٽ_انگ;
    }
    وإلا
    {
	إذا (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->سٽ_انگ, ind - func_ind);
        } وإلا {
            /* from tcc_assemble */
            put_stabs_r(s1, عدم, N_SLINE, 0, f->سٽ_انگ, ind, متن_section, section_sym);
        }
    }
}

ساكن فراغ tcc_debug_stabs (TCCState *s1, ثابت حرف *str, صحيح type, بنانشان ڊگهو قدر,
                             Section *sec, صحيح sym_اشاريو, صحيح info)
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
        s->sym_اشاريو = sym_اشاريو;
        s->info = info;
        s->file = dwarf_سٽ.cur_file;
        s->سٽ = file->سٽ_انگ;
    }
    وإلا إذا (sec)
        put_stabs_r (s1, str, type, 0, 0, قدر, sec, sym_اشاريو);
    وإلا
        put_stabs (s1, str, type, 0, 0, قدر);
}

ساكن فراغ fix_debug_forw_hash(TCCState *s1, صحيح global, صحيح شروعات)
{
    إذا (s1->dwarf) {
        صحيح i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	بنية _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	لكل (i = شروعات; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    صحيح pos = dwarf_info_section->معلومات_وٿي;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_خالي_جايون_TYPE
                                             : DWARF_ABBREV_STRUCTURE_خالي_جايون_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_پهريون_ANOM
                       ? "" : get_tok_str(t->v, عدم));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_سٽ.cur_file);
            dwarf_uleb128(dwarf_info_section, file->سٽ_انگ);
	    لكل (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->معلومات +
			  hash[i].debug_type[j],
			  pos - dwarf_info.شروعات);
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

        info->شروعات = قدر;
        info->آخري_debug_hash = n_debug_hash_local;
        info->آخري_debug_forw_hash = n_debug_forw_hash_local;
        info->والد = debug_info;
        إذا (debug_info) {
            إذا (debug_info->ٻار) {
                إذا (debug_info->ٻار->آخري)
                    debug_info->ٻار->آخري->ايندڙ = info;
                وإلا
                    debug_info->ٻار->ايندڙ = info;
                debug_info->ٻار->آخري = info;
            }
            وإلا
                debug_info->ٻار = info;
        }
        وإلا
            debug_info_پاڙ = info;
        debug_info = info;
    }
    وإلا {
	fix_debug_forw_hash(s1, 0, debug_info->آخري_debug_forw_hash);
        n_debug_hash_local = debug_info->آخري_debug_hash;
        n_debug_forw_hash_local = debug_info->آخري_debug_forw_hash;
        debug_info->پڇاڙي = قدر;
        debug_info = debug_info->والد;
    }
}

ساكن صحيح check_global(Sym *t)
{
    Sym *g = local_ڍير;

    طالما (g) {
	إذا (t == g)
	    أرجع 0;
	g = g->prev;
    }
    أرجع 1;
}

ساكن صحيح tcc_debug_ڳوليو(TCCState *s1, Sym *t, صحيح dwarf)
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
			          debug_type - dwarf_info.شروعات);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		لكل (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

ساكن صحيح tcc_debug_جوڙيو(TCCState *s1, Sym *t, صحيح dwarf)
{
    صحيح وٿي = dwarf ? dwarf_info_section->معلومات_وٿي : ++debug_ايندڙ_type;
    صحيح *n_hash, g = check_global(t);
    بنية _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (بنية _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * حجم(**hash));
    (*hash)[*n_hash].debug_type = وٿي;
    (*hash)[(*n_hash)++].type = t;
    أرجع وٿي;
}

ساكن صحيح STRUCT_NODEBUG(Sym *s)
{
    أرجع
    (s->a.nodebug ||
     ((s->v & ~SYM_ميدان) >= SYM_پهريون_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

ساكن صحيح stabs_struct_ڳوليو(TCCState *s1, Sym *t, صحيح *p_id)
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
        s = sym_push2(&global_ڍير, SYM_ميدان|0x00DEBBED, 0, ++debug_ايندڙ_type);
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

ساكن فراغ tcc_get_debug_info(TCCState *s1, Sym *s, CString *نتيجو)
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
        إذا (stabs_struct_ڳوليو(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_پهريون_ANOM
                         ? "" : get_tok_str(t->v, عدم),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            طالما (t->ايندڙ) {
                صحيح pos, سائيز, align;
                t = t->ايندڙ;
		إذا (STRUCT_NODEBUG(t))
		    استمر;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_ميدان) >= SYM_پهريون_ANOM
                             ? "" : get_tok_str(t->v, عدم)
                             );
                tcc_get_debug_info (s1, t, &str);
                إذا (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + ٻٽو_انگ_POS(t->type.t);
                    سائيز = ٻٽو_انگ_سائيز(t->type.t);
                }
                وإلا {
                    pos = t->c * 8;
                    سائيز = type_سائيز(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, سائيز);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.معلومات, N_LSYM, 0, عدم, 0, 0);
            cstr_free (&str);
        }
    }
    وإلا إذا (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        إذا (stabs_struct_ڳوليو(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_پهريون_ANOM
                         ? "" : get_tok_str(t->v, عدم),
                         debug_type);
            طالما (t->ايندڙ) {
                t = t->ايندڙ;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_ميدان) >= SYM_پهريون_ANOM
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
        type &= ~VT_STRUCT_نقاب;
        لكل (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            إذا (default_debug[debug_type - 1].type == type)
                اكسر;
        إذا (debug_type > N_DEFAULT_DEBUG)
            أرجع;
    }

    إذا (عدم == نتيجو) /* from stabs_struct_complete() */
        أرجع;

    إذا (n > 0)
        cstr_printf (نتيجو, "%d=", ++debug_ايندڙ_type);
    t = s;
    لكل (;;) {
        type = remove_type_info (t->type.t);
        إذا (type == VT_PTR)
            cstr_printf (نتيجو, "%d=*", ++debug_ايندڙ_type);
        وإلا إذا (type == (VT_PTR | VT_ARRAY))
            cstr_printf (نتيجو, "%d=ar1;0;%d;",
                         ++debug_ايندڙ_type, t->type.ref->c - 1);
        وإلا إذا (type == VT_FUNC) {
            cstr_printf (نتيجو, "%d=f", ++debug_ايندڙ_type);
            tcc_get_debug_info (s1, t->type.ref, نتيجو);
            أرجع;
        }
        وإلا
            اكسر;
        t = t->type.ref;
    }
    cstr_printf (نتيجو, "%d", debug_type);
}

ساكن فراغ stabs_struct_complete(TCCState *s1, CType *t)
{
    إذا (stabs_struct_ڳوليو(s1, t->ref, عدم)) {
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
    صحيح آخري_pos = -1;
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
	debug_type = tcc_debug_ڳوليو(s1, t, 1);
	إذا (debug_type == -1) {
	    صحيح pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_جوڙيو(s1, t, 1);
	    e = t;
	    i = 0;
	    طالما (e->ايندڙ) {
		e = e->ايندڙ;
		إذا (STRUCT_NODEBUG(e))
		    استمر;
		i++;
	    }
	    pos_type = (صحيح *) tcc_malloc(i * حجم(صحيح));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->ايندڙ ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_خالي_جايون_TYPE
		        : t->ايندڙ ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_خالي_جايون_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_پهريون_ANOM
                       ? "" : get_tok_str(t->v, عدم));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_سٽ.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->سٽ_انگ);
	    إذا (t->ايندڙ) {
	        pos_sib = dwarf_info_section->معلومات_وٿي;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            طالما (e->ايندڙ) {
                e = e->ايندڙ;
		إذا (STRUCT_NODEBUG(e))
		    استمر;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, عدم));
		dwarf_uleb128(dwarf_info_section, dwarf_سٽ.cur_file);
		dwarf_uleb128(dwarf_info_section, file->سٽ_انگ);
		pos_type[i++] = dwarf_info_section->معلومات_وٿي;
		dwarf_data4(dwarf_info_section, 0);
                إذا (e->type.t & VT_BITFIELD) {
                    صحيح pos = e->c * 8 + ٻٽو_انگ_POS(e->type.t);
                    صحيح سائيز = ٻٽو_انگ_سائيز(e->type.t);

		    dwarf_uleb128(dwarf_info_section, سائيز);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		وإلا
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    إذا (t->ايندڙ) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->معلومات + pos_sib,
		          dwarf_info_section->معلومات_وٿي - dwarf_info.شروعات);
	    }
	    e = t;
	    i = 0;
	    طالما (e->ايندڙ) {
		e = e->ايندڙ;
		إذا (STRUCT_NODEBUG(e))
		    استمر;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->معلومات + pos_type[i++],
			  type - dwarf_info.شروعات);
	    }
	    tcc_free(pos_type);
        }
    }
    وإلا إذا (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_ڳوليو(s1, t, 1);
	إذا (debug_type == -1) {
	    صحيح pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_جوڙيو(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_پهريون_ANOM
                       ? "" : get_tok_str(t->v, عدم));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.شروعات);
	    dwarf_uleb128(dwarf_info_section, dwarf_سٽ.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->سٽ_انگ);
	    pos_sib = dwarf_info_section->معلومات_وٿي;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            طالما (e->ايندڙ) {
                e = e->ايندڙ;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_ميدان) >= SYM_پهريون_ANOM
                           ? "" : get_tok_str(e->v, عدم));
		إذا (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		وإلا
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->معلومات + pos_sib,
		      dwarf_info_section->معلومات_وٿي - dwarf_info.شروعات);
	}
    }
    وإلا إذا ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_نقاب;
        لكل (i = 1; i <= N_DEFAULT_DEBUG; i++)
            إذا (default_debug[i - 1].type == type)
                اكسر;
        إذا (i > N_DEFAULT_DEBUG)
            أرجع 0;
	debug_type = dwarf_info.بنياد_type_استعمال_ٿيل[i - 1];
	إذا (debug_type == 0) {
	    حرف name[100];

	    debug_type = dwarf_info_section->معلومات_وٿي;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_بنياد_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].سائيز);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, حجم name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.بنياد_type_استعمال_ٿيل[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = عدم;
    t = s;
    لكل (;;) {
        type = remove_type_info (t->type.t);
        إذا (type == VT_PTR) {
	    i = dwarf_info_section->معلومات_وٿي;
	    إذا (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_اشارو);
	    dwarf_data1(dwarf_info_section, PTR_سائيز);
	    إذا (آخري_pos != -1) {
		tcc_debug_check_forw(s1, e, آخري_pos);
		write32le(dwarf_info_section->معلومات + آخري_pos,
			  i - dwarf_info.شروعات);
	    }
	    آخري_pos = dwarf_info_section->معلومات_وٿي;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        وإلا إذا (type == (VT_PTR | VT_ARRAY)) {
	    صحيح sib_pos, sub_type;
#إذا LONG_سائيز == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#وإلا
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#جيڪڏهن_پورو

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->معلومات_وٿي;
	    إذا (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    إذا (آخري_pos != -1) {
		tcc_debug_check_forw(s1, e, آخري_pos);
		write32le(dwarf_info_section->معلومات + آخري_pos,
			  i - dwarf_info.شروعات);
	    }
	    آخري_pos = dwarf_info_section->معلومات_وٿي;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->معلومات_وٿي;
	    dwarf_data4(dwarf_info_section, 0);
	    لكل (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.شروعات);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		إذا (type != (VT_PTR | VT_ARRAY))
		    اكسر;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->معلومات + sib_pos,
		      dwarf_info_section->معلومات_وٿي - dwarf_info.شروعات);
	}
        وإلا إذا (type == VT_FUNC) {
	    صحيح sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->معلومات_وٿي;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    إذا (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->ايندڙ ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_خالي_جايون_TYPE);
	    إذا (آخري_pos != -1) {
		tcc_debug_check_forw(s1, e, آخري_pos);
		write32le(dwarf_info_section->معلومات + آخري_pos,
			  i - dwarf_info.شروعات);
	    }
	    آخري_pos = dwarf_info_section->معلومات_وٿي;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    إذا (t->type.ref->ايندڙ) {
	        sib_pos = dwarf_info_section->معلومات_وٿي;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    طالما (f->ايندڙ) {
		f = f->ايندڙ;
		i++;
	    }
	    pos_type = (صحيح *) tcc_malloc(i * حجم(صحيح));
	    f = t->type.ref;
	    i = 0;
	    طالما (f->ايندڙ) {
		f = f->ايندڙ;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->معلومات_وٿي;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    إذا (t->type.ref->ايندڙ) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->معلومات + sib_pos,
		          dwarf_info_section->معلومات_وٿي - dwarf_info.شروعات);
	    }
	    f = t->type.ref;
	    i = 0;
	    طالما (f->ايندڙ) {
		f = f->ايندڙ;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->معلومات + pos_type[i++],
                          type - dwarf_info.شروعات);
	    }
	    tcc_free(pos_type);
        }
        وإلا {
	    إذا (آخري_pos != -1) {
		tcc_debug_check_forw(s1, e, آخري_pos);
		write32le(dwarf_info_section->معلومات + آخري_pos,
			  debug_type - dwarf_info.شروعات);
	    }
            اكسر;
	}
        t = t->type.ref;
    }
    أرجع retval;
}

ساكن فراغ tcc_debug_پڄاڻي (TCCState *s1, بنية _debug_info *cur)
{
    طالما (cur) {
        بنية _debug_info *ايندڙ = cur->ايندڙ;
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
                    dwarf_uleb128(dwarf_info_section, s->سٽ);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.شروعات);
		إذا (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    إذا (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_سائيز + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    إذا (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_معلومات_PTR);
#إذا PTR_سائيز == 4
                    dwarf_data4(dwarf_info_section, s->قدر);
#وإلا
                    dwarf_data8(dwarf_info_section, s->قدر);
#جيڪڏهن_پورو
		}
		وإلا {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_سائيز((ڊگهو)s->قدر) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (ڊگهو)s->قدر);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->ٻار ? DWARF_ABBREV_LEXICAL_بلاڪ
			           : DWARF_ABBREV_LEXICAL_خالي_جايون_بلاڪ);
            dwarf_reloc(dwarf_info_section, section_sym, R_معلومات_PTR);
#إذا PTR_سائيز == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->شروعات);
            dwarf_data4(dwarf_info_section, cur->پڇاڙي - cur->شروعات);
#وإلا
            dwarf_data8(dwarf_info_section, func_ind + cur->شروعات);
            dwarf_data8(dwarf_info_section, cur->پڇاڙي - cur->شروعات);
#جيڪڏهن_پورو
            tcc_debug_پڄاڻي (s1, cur->ٻار);
	    إذا (cur->ٻار)
                dwarf_data1(dwarf_info_section, 0);
        }
        وإلا
        {
            لكل (i = 0; i < cur->n_sym; i++) {
                بنية debug_sym *s = &cur->sym[i];

                إذا (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->قدر,
                                s->sec, s->sym_اشاريو);
                وإلا
                    put_stabs(s1, s->str, s->type, 0, 0, s->قدر);
                tcc_free (s->str);
            }
            tcc_free (cur->sym);
            put_stabn(s1, N_LBRAC, 0, 0, cur->شروعات);
            tcc_debug_پڄاڻي (s1, cur->ٻار);
            put_stabn(s1, N_RBRAC, 0, 0, cur->پڇاڙي);
        }
        tcc_free (cur);
        cur = ايندڙ;
    }
}

ST_FUNC فراغ tcc_جوڙيو_debug_info(TCCState *s1, Sym *s, Sym *e)
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
    debug_info_پاڙ = عدم;
    debug_info = عدم;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    إذا (!f)
	أرجع;

    إذا (s1->dwarf) {
        tcc_debug_سٽ(s1);
        dwarf_info.func = sym;
        dwarf_info.سٽ = file->سٽ_انگ;
	إذا (s1->do_backtrace) {
	    صحيح i, len;

	    dwarf_سٽ_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, لڙي_ڊيگهه(funcname) + 2);
	    dwarf_سٽ_op(s1, DW_LNE_hi_user - 1);
	    len = لڙي_ڊيگهه(funcname) + 1;
	    لكل (i = 0; i < len; i++)
		dwarf_سٽ_op(s1, funcname[i]);
	}
    }
    وإلا
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.معلومات, N_FUN, 0, f->سٽ_انگ, 0, cur_متن_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_سٽ(s1);
    }
}

ST_FUNC فراغ tcc_debug_prolog_epilog(TCCState *s1, صحيح قدر)
{
    إذا (!s1->do_debug)
        أرجع;
    إذا (s1->dwarf) {
	dwarf_سٽ_op(s1, قدر == 0 ? DW_LNS_سيٽ_prologue_پڇاڙي
				     : DW_LNS_سيٽ_epilogue_begin);
    }
}

/* put function size */
ST_FUNC فراغ tcc_debug_funcend(TCCState *s1, صحيح سائيز)
{
    /* lldb does not like function end and next function start at same pc */
    صحيح min_instr_len;

#إذا TCC_EH_چوکٺو
    tcc_debug_چوکٺو_پڇاڙي(s1, سائيز);
#جيڪڏهن_پورو
    إذا (!s1->do_debug)
        أرجع;
    min_instr_len = dwarf_سٽ.آخري_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_سٽ(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, سائيز);
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
        dwarf_uleb128(dwarf_info_section, dwarf_سٽ.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.سٽ);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->معلومات_وٿي);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.شروعات);
        dwarf_reloc(dwarf_info_section, section_sym, R_معلومات_PTR);
#إذا PTR_سائيز == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, سائيز); // high_pc
#وإلا
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, سائيز); // high_pc
#جيڪڏهن_پورو
        func_sib = dwarf_info_section->معلومات_وٿي;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#إذا defined(TCC_هدف_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#وإلاإذا defined(TCC_هدف_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#وإلاإذا defined TCC_هدف_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#وإلاإذا defined TCC_هدف_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#وإلاإذا defined TCC_هدف_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#وإلا
        dwarf_data1(dwarf_info_section, DW_OP_call_چوکٺو_cfa);
#جيڪڏهن_پورو
        tcc_debug_پڄاڻي (s1, debug_info_پاڙ);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->معلومات + func_sib,
                  dwarf_info_section->معلومات_وٿي - dwarf_info.شروعات);
    }
    وإلا
    {
        tcc_debug_پڄاڻي (s1, debug_info_پاڙ);
    }
    debug_info_پاڙ = 0;
}


ST_FUNC فراغ tcc_debug_extern_sym(TCCState *s1, Sym *sym, صحيح sh_انگ, صحيح sym_bind, صحيح sym_type)
{
    إذا (!(s1->do_debug & 2))
        أرجع;

    إذا (sym_type == STT_FUNC || sym->v >= SYM_پهريون_ANOM)
        أرجع;
    إذا (s1->dwarf) {
        صحيح debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, عدم));
	dwarf_uleb128(dwarf_info_section, dwarf_سٽ.cur_file);
	dwarf_uleb128(dwarf_info_section, file->سٽ_انگ);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->معلومات_وٿي);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.شروعات);
	إذا (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_سائيز + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->معلومات_وٿي,
		R_معلومات_PTR, 0);
#إذا PTR_سائيز == 4
	dwarf_data4(dwarf_info_section, 0);
#وإلا
	dwarf_data8(dwarf_info_section, 0);
#جيڪڏهن_پورو
    }
    وإلا
    {
        Section *s = sh_انگ == SHN_COMMON ? common_section
					  : s1->sections[sh_انگ];
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
	    dwarf_uleb128(dwarf_info_section, dwarf_سٽ.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->سٽ_انگ);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->معلومات_وٿي);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.شروعات);
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

ST_FUNC فراغ tcc_tcov_بلاڪ_پڇاڙي(TCCState *s1, صحيح سٽ);

ST_FUNC فراغ tcc_tcov_بلاڪ_begin(TCCState *s1)
{
    SValue sv;
    فراغ *ptr;
    بنانشان ڊگهو آخري_وٿي = tcov_معلومات.وٿي;

    tcc_tcov_بلاڪ_پڇاڙي (tcc_state, 0);
    إذا (s1->test_coverage == 0 || nocode_wanted)
	أرجع;

    إذا (tcov_معلومات.آخري_file_name == 0 ||
	strcmp ((ثابت حرف *)(tcov_section->معلومات + tcov_معلومات.آخري_file_name),
		file->true_filename) != 0) {
	حرف wd[1024];
	CString cstr;

	إذا (tcov_معلومات.آخري_func_name)
	    section_ptr_جوڙيو(tcov_section, 1);
	إذا (tcov_معلومات.آخري_file_name)
	    section_ptr_جوڙيو(tcov_section, 1);
	tcov_معلومات.آخري_func_name = 0;
	cstr_new (&cstr);
	إذا (file->true_filename[0] == '/') {
	    tcov_معلومات.آخري_file_name = tcov_section->معلومات_وٿي;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	وإلا {
	    getcwd (wd, حجم(wd));
	    tcov_معلومات.آخري_file_name = tcov_section->معلومات_وٿي + لڙي_ڊيگهه(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_جوڙيو(tcov_section, cstr.سائيز + 1);
	strcpy((حرف *)ptr, cstr.معلومات);
#جيڪڏهن_وصف_ٿيل _WIN32
        normalize_slashes((حرف *)ptr);
#جيڪڏهن_پورو
	cstr_free (&cstr);
    }
    إذا (tcov_معلومات.آخري_func_name == 0 ||
	strcmp ((ثابت حرف *)(tcov_section->معلومات + tcov_معلومات.آخري_func_name),
		funcname) != 0) {
	سائيز_t len;

	إذا (tcov_معلومات.آخري_func_name)
	    section_ptr_جوڙيو(tcov_section, 1);
	tcov_معلومات.آخري_func_name = tcov_section->معلومات_وٿي;
	len = لڙي_ڊيگهه (funcname);
	ptr = section_ptr_جوڙيو(tcov_section, len + 1);
	strcpy((حرف *)ptr, funcname);
	section_ptr_جوڙيو(tcov_section, -tcov_section->معلومات_وٿي & 7);
	ptr = section_ptr_جوڙيو(tcov_section, 8);
	write64le (ptr, file->سٽ_انگ);
    }
    إذا (ind == tcov_معلومات.ind && tcov_معلومات.سٽ == file->سٽ_انگ)
        tcov_معلومات.وٿي = آخري_وٿي;
    وإلا {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_جوڙيو(tcov_section, 16);
        tcov_معلومات.سٽ = file->سٽ_انگ;
        write64le (ptr, (tcov_معلومات.سٽ << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((بنانشان حرف *)ptr - tcov_section->معلومات) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#إذا defined TCC_هدف_I386 || defined TCC_هدف_X86_64 || \
    defined TCC_هدف_ARM || defined TCC_هدف_ARM64 || \
    defined TCC_هدف_RISCV64
        gen_increment_tcov (&sv);
#وإلا
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#جيڪڏهن_پورو
        tcov_معلومات.وٿي = (بنانشان حرف *)ptr - tcov_section->معلومات;
        tcov_معلومات.ind = ind;
    }
}

ST_FUNC فراغ tcc_tcov_بلاڪ_پڇاڙي(TCCState *s1, صحيح سٽ)
{
    إذا (s1->test_coverage == 0)
	أرجع;
    إذا (سٽ == -1)
        سٽ = tcov_معلومات.سٽ;
    إذا (tcov_معلومات.وٿي) {
	فراغ *ptr = tcov_section->معلومات + tcov_معلومات.وٿي;
	بنانشان ڊگهو ڊگهو nline = سٽ ? سٽ : file->سٽ_انگ;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_معلومات.وٿي = 0;
    }
}

ST_FUNC فراغ tcc_tcov_check_سٽ(TCCState *s1, صحيح شروعات)
{
    إذا (s1->test_coverage == 0)
	أرجع;
    إذا (tcov_معلومات.سٽ != file->سٽ_انگ) {
        إذا ((tcov_معلومات.سٽ + 1) != file->سٽ_انگ) {
	    tcc_tcov_بلاڪ_پڇاڙي (s1, -1);
	    إذا (شروعات)
                tcc_tcov_بلاڪ_begin (s1);
	}
	وإلا
	    tcov_معلومات.سٽ = file->سٽ_انگ;
    }
}

ST_FUNC فراغ tcc_tcov_شروعات(TCCState *s1)
{
    إذا (s1->test_coverage == 0)
	أرجع;
    إذا (!s1->dState)
        s1->dState = tcc_mallocz(حجم *s1->dState);
    memset (&tcov_معلومات, 0, حجم (tcov_معلومات));
    إذا (tcov_section == عدم) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_جوڙيو(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC فراغ tcc_tcov_پڇاڙي(TCCState *s1)
{
    إذا (s1->test_coverage == 0)
	أرجع;
    إذا (tcov_معلومات.آخري_func_name)
        section_ptr_جوڙيو(tcov_section, 1);
    إذا (tcov_معلومات.آخري_file_name)
        section_ptr_جوڙيو(tcov_section, 1);
}

ST_FUNC فراغ tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_معلومات.ind = 0;
}

/* ------------------------------------------------------------------------- */
#وصف_رد آخري_سٽ_انگ
#وصف_رد new_file
#وصف_رد section_sym
#وصف_رد debug_ايندڙ_type
#وصف_رد debug_hash_global
#وصف_رد debug_hash_local
#وصف_رد n_debug_hash_global
#وصف_رد n_debug_hash_local
#وصف_رد debug_forw_hash_global
#وصف_رد debug_forw_hash_local
#وصف_رد n_debug_forw_hash_global
#وصف_رد n_debug_forw_hash_local
#وصف_رد debug_info
#وصف_رد debug_info_پاڙ
#وصف_رد dwarf_sym
#وصف_رد dwarf_سٽ
#وصف_رد dwarf_info
#وصف_رد dwarf_str
#وصف_رد dwarf_سٽ_str
#وصف_رد tcov_معلومات
