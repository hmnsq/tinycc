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

#समावेश "tcc.h"

/* stab debug support */

अटल स्थिर काष्ठा {
  पूर्णांक type;
  पूर्णांक आकार;
  पूर्णांक encoding;
  स्थिर अक्षर *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#अगर LONG_आकार == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#अन्यथा
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#पूर्ण_अगर
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#अगर LONG_आकार == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#अन्यथा
    /* use octal instead of -1 so size_t works (-gstabs+ in gcc) */
    {   VT_LLONG | VT_LONG | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t5=r5;0;01777777777777777777777;" },
#पूर्ण_अगर
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
#अगर_घोषित TCC_USING_DOUBLE_FOR_LDOUBLE
    {   VT_DOUBLE | VT_LONG, 8, DW_ATE_float, "long double:t16=r1;8;0;" },
#अन्यथा
    {   VT_LDOUBLE, 16, DW_ATE_float, "long double:t16=r1;16;0;" },
#पूर्ण_अगर
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
#अगर LONG_आकार == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#अन्यथा
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#पूर्ण_अगर
};

#घोषणा	N_DEFAULT_DEBUG	(माप (default_debug) / माप (default_debug[0]))

/* dwarf debug */

#घोषणा	DWARF_पंक्ति_BASE				-5
#घोषणा	DWARF_पंक्ति_RANGE			14
#घोषणा	DWARF_OPCODE_BASE			13

#अगर defined TCC_TARGET_ARM64
#घोषणा	DWARF_MIN_INSTR_LEN			4
#या_अगर defined TCC_TARGET_ARM
#घोषणा	DWARF_MIN_INSTR_LEN			2
#अन्यथा
#घोषणा	DWARF_MIN_INSTR_LEN			1
#पूर्ण_अगर

#घोषणा	DWARF_ABBREV_COMPILE_UNIT		1
#घोषणा	DWARF_ABBREV_BASE_TYPE			2
#घोषणा	DWARF_ABBREV_VARIABLE_EXTERNAL		3
#घोषणा	DWARF_ABBREV_VARIABLE_STATIC		4
#घोषणा	DWARF_ABBREV_VARIABLE_LOCAL		5
#घोषणा	DWARF_ABBREV_FORMAL_PARAMETER		6
#घोषणा	DWARF_ABBREV_POINTER			7
#घोषणा	DWARF_ABBREV_ARRAY_TYPE			8
#घोषणा	DWARF_ABBREV_SUBRANGE_TYPE		9
#घोषणा	DWARF_ABBREV_TYPEDEF			10
#घोषणा	DWARF_ABBREV_ENUMERATOR_SIGNED		11
#घोषणा	DWARF_ABBREV_ENUMERATOR_UNSIGNED	12
#घोषणा	DWARF_ABBREV_ENUMERATION_TYPE		13
#घोषणा	DWARF_ABBREV_MEMBER			14
#घोषणा	DWARF_ABBREV_MEMBER_BF			15
#घोषणा	DWARF_ABBREV_STRUCTURE_TYPE		16
#घोषणा	DWARF_ABBREV_STRUCTURE_EMPTY_TYPE	17
#घोषणा	DWARF_ABBREV_UNION_TYPE			18
#घोषणा	DWARF_ABBREV_UNION_EMPTY_TYPE		19
#घोषणा	DWARF_ABBREV_SUBPROGRAM_EXTERNAL	20
#घोषणा	DWARF_ABBREV_SUBPROGRAM_STATIC		21
#घोषणा	DWARF_ABBREV_LEXICAL_BLOCK		22
#घोषणा	DWARF_ABBREV_LEXICAL_EMPTY_BLOCK	23
#घोषणा	DWARF_ABBREV_SUBROUTINE_TYPE		24
#घोषणा	DWARF_ABBREV_SUBROUTINE_EMPTY_TYPE	25
#घोषणा	DWARF_ABBREV_FORMAL_PARAMETER2		26

/* all entries should have been generated with dwarf_uleb128 except
   has_children. All values are currently below 128 so this currently
   works.  */
अटल स्थिर अचिन्हित अक्षर dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_TAG_compile_unit, 1,
          DW_AT_producer, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_पंक्ति_strp,
          DW_AT_comp_dir, DW_FORM_पंक्ति_strp,
          DW_AT_निचला_pc, DW_FORM_addr,
#अगर PTR_आकार == 4
          DW_AT_ऊपरी_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_ऊपरी_pc, DW_FORM_data8,
#पूर्ण_अगर
          DW_AT_stmt_list, DW_FORM_sec_offset,
          0, 0,
    DWARF_ABBREV_BASE_TYPE, DW_TAG_base_type, 0,
          DW_AT_byte_आकार, DW_FORM_udata,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_name, DW_FORM_strp,
          0, 0,
    DWARF_ABBREV_VARIABLE_EXTERNAL, DW_TAG_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पंक्ति, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_TAG_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पंक्ति, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_LOCAL, DW_TAG_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER, DW_TAG_formal_parameter, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_POINTER, DW_TAG_pointer_type, 0,
          DW_AT_byte_आकार, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ARRAY_TYPE, DW_TAG_array_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBRANGE_TYPE, DW_TAG_subrange_type, 0,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_upper_bound, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_TYPEDEF, DW_TAG_typedef, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पंक्ति, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_TAG_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_मूल्य, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_TAG_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_मूल्य, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_TAG_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_आकार, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पंक्ति, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पंक्ति, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_तथ्य_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पंक्ति, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_bit_आकार, DW_FORM_udata,
          DW_AT_तथ्य_bit_offset, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_TAG_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_आकार, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पंक्ति, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_EMPTY_TYPE, DW_TAG_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_आकार, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पंक्ति, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_TAG_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_आकार, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पंक्ति, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_EMPTY_TYPE, DW_TAG_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_आकार, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पंक्ति, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_TAG_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पंक्ति, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_निचला_pc, DW_FORM_addr,
#अगर PTR_आकार == 4
          DW_AT_ऊपरी_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_ऊपरी_pc, DW_FORM_data8,
#पूर्ण_अगर
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_TAG_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पंक्ति, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_निचला_pc, DW_FORM_addr,
#अगर PTR_आकार == 4
          DW_AT_ऊपरी_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_ऊपरी_pc, DW_FORM_data8,
#पूर्ण_अगर
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_BLOCK, DW_TAG_lexical_block, 1,
          DW_AT_निचला_pc, DW_FORM_addr,
#अगर PTR_आकार == 4
          DW_AT_ऊपरी_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_ऊपरी_pc, DW_FORM_data8,
#पूर्ण_अगर
          0, 0,
    DWARF_ABBREV_LEXICAL_EMPTY_BLOCK, DW_TAG_lexical_block, 0,
          DW_AT_निचला_pc, DW_FORM_addr,
#अगर PTR_आकार == 4
          DW_AT_ऊपरी_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_ऊपरी_pc, DW_FORM_data8,
#पूर्ण_अगर
          0, 0,
    DWARF_ABBREV_SUBROUTINE_TYPE, DW_TAG_subroutine_type, 1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_SUBROUTINE_EMPTY_TYPE, DW_TAG_subroutine_type, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_FORMAL_PARAMETER2, DW_TAG_formal_parameter, 0,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
  0
};

अटल स्थिर अचिन्हित अक्षर dwarf_पंक्ति_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#घोषणा N_STR_HASH (251)

काष्ठा dwarf_str_hash {
    पूर्णांक len;
    अचिन्हित दीर्घ तथ्य_offset;
    काष्ठा dwarf_str_hash *अग्र;
};

काष्ठा _tccdbg {

    पूर्णांक last_पंक्ति_अंक, new_file;
    पूर्णांक section_sym;

    पूर्णांक debug_अग्र_type;

    काष्ठा _debug_hash {
        पूर्णांक debug_type;
        Sym *type;
    } *debug_hash_global, *debug_hash_local;

    /* store forward structure/unions types */
    काष्ठा _debug_forw_hash {
        Sym *type;
        पूर्णांक n_debug_type;
        पूर्णांक *debug_type;
    } *debug_forw_hash_global, *debug_forw_hash_local;

    पूर्णांक n_debug_hash_global;
    पूर्णांक n_debug_hash_local;
    पूर्णांक n_debug_forw_hash_global;
    पूर्णांक n_debug_forw_hash_local;

    काष्ठा _debug_info {
        पूर्णांक start;
        पूर्णांक end;
        पूर्णांक last_debug_hash;
        पूर्णांक last_debug_forw_hash;
        पूर्णांक n_sym;
        काष्ठा debug_sym {
            पूर्णांक type;
            अचिन्हित दीर्घ मूल्य;
            अक्षर *str;
            Section *sec;
            पूर्णांक sym_सूचकांक;
            पूर्णांक info;
            पूर्णांक file;
            पूर्णांक पंक्ति_2;
        } *sym;
        काष्ठा _debug_info *child, *अग्र, *last, *parent;
    } *debug_info, *debug_info_मूल;

    काष्ठा {
        पूर्णांक info;
        पूर्णांक abbrev;
        पूर्णांक पंक्ति_2;
        पूर्णांक str;
        पूर्णांक पंक्ति_str;
    } dwarf_sym;

    काष्ठा {
        पूर्णांक start;
        पूर्णांक dir_आकार;
        अक्षर **dir_table;
        पूर्णांक filename_आकार;
        काष्ठा dwarf_filename_struct {
            पूर्णांक dir_entry;
            अक्षर *name;
        } *filename_table;
        पूर्णांक पंक्ति_आकार;
        पूर्णांक पंक्ति_max_आकार;
        अचिन्हित अक्षर *पंक्ति_तथ्य;
        पूर्णांक cur_file;
        पूर्णांक last_file;
        पूर्णांक last_pc;
        पूर्णांक last_पंक्ति;
    } dwarf_पंक्ति;

    काष्ठा {
        पूर्णांक start;
        Sym *func;
        पूर्णांक पंक्ति_2;
        पूर्णांक base_type_used[N_DEFAULT_DEBUG];
    } dwarf_info;

    काष्ठा dwarf_str_hash *dwarf_str[N_STR_HASH];
    काष्ठा dwarf_str_hash *dwarf_पंक्ति_str[N_STR_HASH];

    /* test coverage */
    काष्ठा {
        अचिन्हित दीर्घ offset;
        अचिन्हित दीर्घ last_file_name;
        अचिन्हित दीर्घ last_func_name;
        पूर्णांक ind;
        पूर्णांक पंक्ति_2;
    } tcov_तथ्य;
};

#घोषणा last_पंक्ति_अंक             s1->dState->last_पंक्ति_अंक
#घोषणा new_file                  s1->dState->new_file
#घोषणा section_sym               s1->dState->section_sym
#घोषणा debug_अग्र_type           s1->dState->debug_अग्र_type
#घोषणा debug_hash_global         s1->dState->debug_hash_global
#घोषणा debug_hash_local          s1->dState->debug_hash_local
#घोषणा debug_forw_hash_global    s1->dState->debug_forw_hash_global
#घोषणा debug_forw_hash_local     s1->dState->debug_forw_hash_local
#घोषणा n_debug_hash_global       s1->dState->n_debug_hash_global
#घोषणा n_debug_hash_local        s1->dState->n_debug_hash_local
#घोषणा n_debug_forw_hash_global  s1->dState->n_debug_forw_hash_global
#घोषणा n_debug_forw_hash_local   s1->dState->n_debug_forw_hash_local
#घोषणा debug_info                s1->dState->debug_info
#घोषणा debug_info_मूल           s1->dState->debug_info_मूल
#घोषणा dwarf_sym                 s1->dState->dwarf_sym
#घोषणा dwarf_पंक्ति                s1->dState->dwarf_पंक्ति
#घोषणा dwarf_info                s1->dState->dwarf_info
#घोषणा dwarf_str                 s1->dState->dwarf_str
#घोषणा dwarf_पंक्ति_str            s1->dState->dwarf_पंक्ति_str
#घोषणा tcov_तथ्य                 s1->dState->tcov_तथ्य

#घोषणा	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
अटल पूर्णांक put_stabs(TCCState *s1, स्थिर अक्षर *str, पूर्णांक type, पूर्णांक other,
    पूर्णांक desc, अचिन्हित दीर्घ मूल्य);

ST_FUNC व्योम tcc_debug_new(TCCState *s1)
{
    पूर्णांक shf = 0;
    अगर (!s1->dState)
        s1->dState = tcc_mallocz(माप *s1->dState);

#अगर_घोषित CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    अगर (s1->do_debug && s1->output_type == TCC_OUTPUT_MEMORY)
        s1->do_backtrace = 1;
    अगर (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#पूर्ण_अगर

    अगर (s1->dwarf) {
	पूर्णांक i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	अटल स्थिर अक्षर *स्थिर debug[] = {
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
        dwarf_पंक्ति_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	क्रम (i = 0; i < माप(debug)/माप(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_MERGE | SHF_STRINGS;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_पंक्ति_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	अगर (s1->dwarf >= 5) {
            dwarf_पंक्ति_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_पंक्ति_str_section->sh_entsize = 1;
	    dwarf_पंक्ति_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    अन्यथा
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = माप(Stab_Sym);
        stab_section->sh_addralign = माप ((Stab_Sym*)0)->n_मूल्य;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
अटल पूर्णांक put_stabs(TCCState *s1, स्थिर अक्षर *str, पूर्णांक type, पूर्णांक other, पूर्णांक desc,
                      अचिन्हित दीर्घ मूल्य)
{
    Stab_Sym *sym;

    अचिन्हित offset;
    अगर (type == N_SLINE
        && (offset = stab_section->तथ्य_offset)
        && (sym = (Stab_Sym*)(stab_section->तथ्य + offset) - 1)
        && sym->n_type == type
        && sym->n_मूल्य == मूल्य) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        वापस 0;
    }

    sym = section_ptr_add(stab_section, माप(Stab_Sym));
    अगर (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } अन्यथा {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_मूल्य = मूल्य;
    वापस 1;
}

अटल व्योम put_stabs_r(TCCState *s1, स्थिर अक्षर *str, पूर्णांक type, पूर्णांक other, पूर्णांक desc,
                        अचिन्हित दीर्घ मूल्य, Section *sec, पूर्णांक sym_सूचकांक)
{
    अगर (put_stabs(s1, str, type, other, desc, मूल्य))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->तथ्य_offset - 4,
                      माप ((Stab_Sym*)0)->n_मूल्य == PTR_आकार ? R_तथ्य_PTR : R_तथ्य_32,
                      sym_सूचकांक);
}

अटल व्योम put_stabn(TCCState *s1, पूर्णांक type, पूर्णांक other, पूर्णांक desc, पूर्णांक मूल्य)
{
    put_stabs(s1, शून्य, type, other, desc, मूल्य);
}

/* ------------------------------------------------------------------------- */
#घोषणा	dwarf_data1(s,तथ्य) \
	(*(uint8_t*)section_ptr_add((s), 1) = (तथ्य))
#घोषणा	dwarf_data2(s,तथ्य) \
	write16le(section_ptr_add((s), 2), (तथ्य))
#घोषणा	dwarf_data4(s,तथ्य) \
	write32le(section_ptr_add((s), 4), (तथ्य))
#घोषणा	dwarf_data8(s,तथ्य) \
	write64le(section_ptr_add((s), 8), (तथ्य))

अटल पूर्णांक dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    वापस put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_अंक, शून्य);
}

अटल व्योम dwarf_reloc(Section *s, पूर्णांक sym, पूर्णांक rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->तथ्य_offset, rel, sym, 0);
}

अटल व्योम free_str(काष्ठा dwarf_str_hash **str)
{
    पूर्णांक i;

    क्रम (i = 0; i < N_STR_HASH; i++) {
       जबतक (str[i]) {
           काष्ठा dwarf_str_hash *अग्र = str[i]->अग्र;

           tcc_free(str[i]);
           str[i] = अग्र;
       }
    }
}

अटल अचिन्हित str_hash(स्थिर अक्षर *s)
{
    अचिन्हित h = 5381;

    जबतक (*s)
       h += (*s++ & 0xffu) + h * 31;
    वापस h;
}

अटल व्योम dwarf_string(Section *s, Section *dw, पूर्णांक sym, स्थिर अक्षर *str)
{
    TCCState *s1 = s->s1;
    पूर्णांक len, hash = str_hash(str) % N_STR_HASH;
    अक्षर *ptr;
    काष्ठा dwarf_str_hash *new_hash;
    काष्ठा dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_पंक्ति_str;

    len = म_माप(str) + 1;
    new_hash = dw_hash[hash];
    जबतक (new_hash) {
	अगर (new_hash->len == len &&
	    !स_भेद(str, dw->तथ्य + new_hash->तथ्य_offset, len))
	    अवरोध;
	new_hash = new_hash->अग्र;
    }
    अगर (new_hash == शून्य) {
	अचिन्हित दीर्घ offset = dw->तथ्य_offset;

        new_hash = dw_hash[hash];
        जबतक (new_hash) {
	    अचिन्हित दीर्घ n = new_hash->तथ्य_offset + new_hash->len - len;

	    अगर (new_hash->len > len &&
	        !स_भेद(str, dw->तथ्य + n, len)) {
		offset = n;
		अवरोध;
	    }
	    new_hash = new_hash->अग्र;
        }
	अगर (new_hash == शून्य) {
	    ptr = section_ptr_add(dw, len);
	    स_हटाओ(ptr, str, len);
	}
	new_hash = (काष्ठा dwarf_str_hash *)
	    tcc_malloc(माप(काष्ठा dwarf_str_hash));
	new_hash->len = len;
	new_hash->तथ्य_offset = offset;
	new_hash->अग्र = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->तथ्य_offset, R_तथ्य_32_DW, sym,
                   PTR_आकार == 4 ? 0 : new_hash->तथ्य_offset);
    dwarf_data4(s, PTR_आकार == 4 ? new_hash->तथ्य_offset : 0);
}

अटल व्योम dwarf_strp(Section *s, स्थिर अक्षर *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

अटल व्योम dwarf_पंक्ति_strp(Section *s, स्थिर अक्षर *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_पंक्ति_str_section, dwarf_sym.पंक्ति_str, str);
}

अटल व्योम dwarf_पंक्ति_op(TCCState *s1, अचिन्हित अक्षर op)
{
    अगर (dwarf_पंक्ति.पंक्ति_आकार >= dwarf_पंक्ति.पंक्ति_max_आकार) {
	dwarf_पंक्ति.पंक्ति_max_आकार += 1024;
	dwarf_पंक्ति.पंक्ति_तथ्य =
	    (अचिन्हित अक्षर *)tcc_realloc(dwarf_पंक्ति.पंक्ति_तथ्य,
					 dwarf_पंक्ति.पंक्ति_max_आकार);
    }
    dwarf_पंक्ति.पंक्ति_तथ्य[dwarf_पंक्ति.पंक्ति_आकार++] = op;
}

अटल व्योम dwarf_file(TCCState *s1)
{
    पूर्णांक i, j;
    अक्षर *filename;
    पूर्णांक सूचकांक_offset = s1->dwarf < 5;

    अगर (!म_भेद(file->filename, "<command line>")) {
        dwarf_पंक्ति.cur_file = 1;
	वापस;
    }
    filename = म_खोजप(file->filename, '/');
    अगर (filename == शून्य) {
        क्रम (i = 1; i < dwarf_पंक्ति.filename_आकार; i++)
            अगर (dwarf_पंक्ति.filename_table[i].dir_entry == 0 &&
		म_भेद(dwarf_पंक्ति.filename_table[i].name,
		       file->filename) == 0) {
		    dwarf_पंक्ति.cur_file = i + सूचकांक_offset;
	            वापस;
		}
	i = -सूचकांक_offset;
	filename = file->filename;
    }
    अन्यथा {
	अक्षर *undo = filename;
	अक्षर *dir = file->filename;

	*filename++ = '\0';
        क्रम (i = 0; i < dwarf_पंक्ति.dir_आकार; i++)
	    अगर (म_भेद(dwarf_पंक्ति.dir_table[i], dir) == 0) {
		क्रम (j = 1; j < dwarf_पंक्ति.filename_आकार; j++)
		    अगर (dwarf_पंक्ति.filename_table[j].dir_entry - सूचकांक_offset
			== i &&
			म_भेद(dwarf_पंक्ति.filename_table[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_पंक्ति.cur_file = j + सूचकांक_offset;
			वापस;
		    }
		अवरोध;
	    }
	अगर (i == dwarf_पंक्ति.dir_आकार) {
	    dwarf_पंक्ति.dir_आकार++;
	    dwarf_पंक्ति.dir_table =
                (अक्षर **) tcc_realloc(dwarf_पंक्ति.dir_table,
                                      dwarf_पंक्ति.dir_आकार *
                                      माप (अक्षर *));
            dwarf_पंक्ति.dir_table[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_पंक्ति.filename_table =
        (काष्ठा dwarf_filename_struct *)
        tcc_realloc(dwarf_पंक्ति.filename_table,
                    (dwarf_पंक्ति.filename_आकार + 1) *
                    माप (काष्ठा dwarf_filename_struct));
    dwarf_पंक्ति.filename_table[dwarf_पंक्ति.filename_आकार].dir_entry =
	i + सूचकांक_offset;
    dwarf_पंक्ति.filename_table[dwarf_पंक्ति.filename_आकार].name =
        tcc_strdup(filename);
    dwarf_पंक्ति.cur_file = dwarf_पंक्ति.filename_आकार++ + सूचकांक_offset;
    वापस;
}

#अगर 0
अटल पूर्णांक dwarf_uleb128_आकार (अचिन्हित दीर्घ दीर्घ मूल्य)
{
    पूर्णांक आकार =  0;

    करो {
        मूल्य >>= 7;
        आकार++;
    } जबतक (मूल्य != 0);
    वापस आकार;
}
#पूर्ण_अगर

अटल पूर्णांक dwarf_sleb128_आकार (दीर्घ दीर्घ मूल्य)
{
    पूर्णांक आकार =  0;
    दीर्घ दीर्घ end = मूल्य >> 63;
    अचिन्हित अक्षर last = end & 0x40;
    अचिन्हित अक्षर byte;

    करो {
        byte = मूल्य & 0x7f;
        मूल्य >>= 7;
        आकार++;
    } जबतक (मूल्य != end || (byte & 0x40) != last);
    वापस आकार;
}

अटल व्योम dwarf_uleb128 (Section *s, अचिन्हित दीर्घ दीर्घ मूल्य)
{
    करो {
        अचिन्हित अक्षर byte = मूल्य & 0x7f;

        मूल्य >>= 7;
        dwarf_data1(s, byte | (मूल्य ? 0x80 : 0));
    } जबतक (मूल्य != 0);
}

अटल व्योम dwarf_sleb128 (Section *s, दीर्घ दीर्घ मूल्य)
{
    पूर्णांक more;
    दीर्घ दीर्घ end = मूल्य >> 63;
    अचिन्हित अक्षर last = end & 0x40;

    करो {
        अचिन्हित अक्षर byte = मूल्य & 0x7f;

        मूल्य >>= 7;
	more = मूल्य != end || (byte & 0x40) != last;
        dwarf_data1(s, byte | (0x80 * more));
    } जबतक (more);
}

अटल व्योम dwarf_uleb128_op (TCCState *s1, अचिन्हित दीर्घ दीर्घ मूल्य)
{
    करो {
        अचिन्हित अक्षर byte = मूल्य & 0x7f;

        मूल्य >>= 7;
        dwarf_पंक्ति_op(s1, byte | (मूल्य ? 0x80 : 0));
    } जबतक (मूल्य != 0);
}

अटल व्योम dwarf_sleb128_op (TCCState *s1, दीर्घ दीर्घ मूल्य)
{
    पूर्णांक more;
    दीर्घ दीर्घ end = मूल्य >> 63;
    अचिन्हित अक्षर last = end & 0x40;

    करो {
        अचिन्हित अक्षर byte = मूल्य & 0x7f;

        मूल्य >>= 7;
        more = मूल्य != end || (byte & 0x40) != last;
        dwarf_पंक्ति_op(s1, byte | (0x80 * more));
    } जबतक (more);
}

#अगर TCC_EH_FRAME
ST_FUNC व्योम tcc_eh_frame_start(TCCState *s1)
{
    अगर (!s1->unwind_tables)
        वापस;
    eh_frame_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_start = eh_frame_section->तथ्य_offset;
    dwarf_data4(eh_frame_section, 0); //लंबाई
    dwarf_data4(eh_frame_section, 0); // CIE ID
    dwarf_data1(eh_frame_section, 1); // Version
    dwarf_data1(eh_frame_section, 'z'); // Augmentation String
    dwarf_data1(eh_frame_section, 'R');
    dwarf_data1(eh_frame_section, 0);
#अगर defined TCC_TARGET_I386
    dwarf_uleb128(eh_frame_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 8); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 4); // r4 (esp)
    dwarf_uleb128(eh_frame_section, 4); // ofs 4
    dwarf_data1(eh_frame_section, DW_CFA_offset + 8); // r8 (eip)
    dwarf_uleb128(eh_frame_section, 1); // cfa-4
#या_अगर defined TCC_TARGET_X86_64
    dwarf_uleb128(eh_frame_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 16); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_frame_section, 8); // ofs 8
    dwarf_data1(eh_frame_section, DW_CFA_offset + 16); // r16 (rip)
    dwarf_uleb128(eh_frame_section, 1); // cfa-8
#या_अगर defined TCC_TARGET_ARM
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
#या_अगर defined TCC_TARGET_ARM64
    dwarf_uleb128(eh_frame_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 30); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 31); // x31 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#या_अगर defined TCC_TARGET_RISCV64
    eh_frame_section->तथ्य[s1->eh_start + 8] = 3; // version = 3
    dwarf_uleb128(eh_frame_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 1); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 2); // r2 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#पूर्ण_अगर
    जबतक ((eh_frame_section->तथ्य_offset - s1->eh_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->तथ्य + s1->eh_start, //लंबाई
	      eh_frame_section->तथ्य_offset - s1->eh_start - 4);
}

अटल व्योम tcc_debug_frame_end(TCCState *s1, पूर्णांक आकार)
{
    पूर्णांक eh_section_sym;
    अचिन्हित दीर्घ fde_start;

    अगर (!eh_frame_section)
	वापस;
    eh_section_sym = dwarf_get_section_sym(text_section);
    fde_start = eh_frame_section->तथ्य_offset;
    dwarf_data4(eh_frame_section, 0); //लंबाई
    dwarf_data4(eh_frame_section,
		fde_start - s1->eh_start + 4); // CIE Pointer
#अगर defined TCC_TARGET_I386
    dwarf_reloc(eh_frame_section, eh_section_sym, R_386_PC32);
#या_अगर defined TCC_TARGET_X86_64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_X86_64_PC32);
#या_अगर defined TCC_TARGET_ARM
    dwarf_reloc(eh_frame_section, eh_section_sym, R_ARM_REL32);
#या_अगर defined TCC_TARGET_ARM64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_AARCH64_PREL32);
#या_अगर defined TCC_TARGET_RISCV64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_RISCV_32_PCREL);
#पूर्ण_अगर
    dwarf_data4(eh_frame_section, func_ind); // PC Begin
    dwarf_data4(eh_frame_section, आकार); // PC Range
    dwarf_data1(eh_frame_section, 0); // Augmentation Length
#अगर defined TCC_TARGET_I386
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 8);
    dwarf_data1(eh_frame_section, DW_CFA_offset + 5); // r5 (ebp)
    dwarf_uleb128(eh_frame_section, 2); // cfa-8
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_register);
    dwarf_uleb128(eh_frame_section, 5); // r5 (ebp)
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_frame_section, आकार - 5);
    dwarf_data1(eh_frame_section, DW_CFA_restore + 5); // r5 (ebp)
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 4); // r4 (esp)
    dwarf_uleb128(eh_frame_section, 4); // ofs 4
#या_अगर defined TCC_TARGET_X86_64
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 16);
    dwarf_data1(eh_frame_section, DW_CFA_offset + 6); // r6 (rbp)
    dwarf_uleb128(eh_frame_section, 2); // cfa-16
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_register);
    dwarf_uleb128(eh_frame_section, 6); // r6 (rbp)
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_frame_section, आकार - 5);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_frame_section, 8); // ofs 8
#या_अगर defined TCC_TARGET_ARM
    /* TODO */
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 8);
    dwarf_data1(eh_frame_section, DW_CFA_offset + 14); // r14 (lr)
    dwarf_uleb128(eh_frame_section, 1);
    dwarf_data1(eh_frame_section, DW_CFA_offset + 11); // r11 (fp)
    dwarf_uleb128(eh_frame_section, 2);
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_frame_section, आकार / 2 - 5);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_register);
    dwarf_uleb128(eh_frame_section, 11); // r11 (fp)
#या_अगर defined TCC_TARGET_ARM64
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 224);
    dwarf_data1(eh_frame_section, DW_CFA_offset + 29); // x29 (fp)
    dwarf_uleb128(eh_frame_section, 28); // cfa-224
    dwarf_data1(eh_frame_section, DW_CFA_offset + 30); // x30 (lr)
    dwarf_uleb128(eh_frame_section, 27); // cfa-216
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 224 + ((-loc + 15) & ~15));
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_frame_section, आकार / 4 - 5);
    dwarf_data1(eh_frame_section, DW_CFA_restore + 30); // x30 (lr)
    dwarf_data1(eh_frame_section, DW_CFA_restore + 29); // x29 (fp)
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 0);
#या_अगर defined TCC_TARGET_RISCV64
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 4);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 16); // ofs 16
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_frame_section, DW_CFA_offset + 1); // r1 (ra, lr)
    dwarf_uleb128(eh_frame_section, 2); // cfa-8
    dwarf_data1(eh_frame_section, DW_CFA_offset + 8); // r8 (s0, fp)
    dwarf_uleb128(eh_frame_section, 4); // cfa-16
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 8);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 8); // r8 (s0, fp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    जबतक (आकार >= 4 &&
	   read32le(cur_text_section->तथ्य + func_ind + आकार - 4) != 0x00008067)
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
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#पूर्ण_अगर
    जबतक ((eh_frame_section->तथ्य_offset - fde_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->तथ्य + fde_start, //लंबाई
	      eh_frame_section->तथ्य_offset - fde_start - 4);
}

ST_FUNC व्योम tcc_eh_frame_end(TCCState *s1)
{
    अगर (!eh_frame_section)
	वापस;
    dwarf_data4(eh_frame_section, 0);
}

काष्ठा eh_खोज_table {
    uint32_t pc_offset;
    uint32_t fde_offset;
};

अटल पूर्णांक sort_eh_table(स्थिर व्योम *a, स्थिर व्योम *b)
{
    uint32_t pc1 = ((स्थिर काष्ठा eh_खोज_table *)a)->pc_offset;
    uint32_t pc2 = ((स्थिर काष्ठा eh_खोज_table *)b)->pc_offset;

    वापस pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC व्योम tcc_eh_frame_hdr(TCCState *s1, पूर्णांक final)
{
    पूर्णांक गिनती_2 = 0, offset;
    अचिन्हित दीर्घ गिनती_offset, tab_offset;
    अचिन्हित अक्षर *ln, *end;
    अचिन्हित पूर्णांक last_cie_offset = 0xffffffff;

    अगर (!eh_frame_section || !eh_frame_section->तथ्य_offset)
	वापस;
    अगर (final && !eh_frame_hdr_section)
	वापस;
    अगर (final == 0)
        eh_frame_hdr_section =
	    new_section(s1, ".eh_frame_hdr", SHT_PROGBITS, SHF_ALLOC);
    eh_frame_hdr_section->तथ्य_offset = 0;
    dwarf_data1(eh_frame_hdr_section, 1); // Version
    // Pointer Encoding Format
    dwarf_data1(eh_frame_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_pcrel);
    // Count Encoding Format
    dwarf_data1(eh_frame_hdr_section, DW_EH_PE_udata4 | DW_EH_PE_absptr);
    // Table Encoding Format
    dwarf_data1(eh_frame_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_datarel);
    offset = eh_frame_section->sh_addr -
             eh_frame_hdr_section->sh_addr -
             eh_frame_hdr_section->तथ्य_offset;
    dwarf_data4(eh_frame_hdr_section, offset); // eh_frame_ptr
    //गिनती
    गिनती_offset = eh_frame_hdr_section->तथ्य_offset;
    dwarf_data4(eh_frame_hdr_section, 0);
    tab_offset = eh_frame_hdr_section->तथ्य_offset;
    ln = eh_frame_section->तथ्य;
    end = eh_frame_section->तथ्य + eh_frame_section->तथ्य_offset;
    जबतक (ln < end) {
	अचिन्हित अक्षर *fde = ln, *rd = ln;
	अचिन्हित पूर्णांक cie_offset, version, लंबाई = dwarf_read_4(rd, end);
	अचिन्हित पूर्णांक pc_offset, fde_offset;

	अगर (लंबाई == 0)
	    जाओ अग्र;
        cie_offset = dwarf_read_4(rd, end);
	अगर (cie_offset == 0)
	    जाओ अग्र;
	अगर (cie_offset != last_cie_offset) {
	    अचिन्हित अक्षर *cie = rd - cie_offset + 4;

	    अगर (cie < eh_frame_section->तथ्य)
		जाओ अग्र;
	    version = dwarf_read_1(cie, end);
	    अगर ((version == 1 || version == 3) &&
	        dwarf_read_1(cie, end) == 'z' && // Augmentation String
		dwarf_read_1(cie, end) == 'R' &&
		dwarf_read_1(cie, end) == 0) {
	        dwarf_read_uleb128(&cie, end); // code_alignment_factor
	        dwarf_read_sleb128(&cie, end); // data_alignment_factor
		dwarf_read_1(cie, end); // return address column
		अगर (dwarf_read_uleb128(&cie, end) == 1 &&
		    dwarf_read_1(cie, end) == FDE_ENCODING) {
		    last_cie_offset = cie_offset;
		}
		अन्यथा
		    जाओ अग्र;
	    }
	    अन्यथा
		जाओ अग्र;
	}
	गिनती_2++;
	fde_offset = eh_frame_section->sh_addr +
		     (fde - eh_frame_section->तथ्य) -
		     eh_frame_hdr_section->sh_addr;
	pc_offset = dwarf_read_4(rd, end) + fde_offset + 8;
	dwarf_data4(eh_frame_hdr_section, pc_offset);
	dwarf_data4(eh_frame_hdr_section, fde_offset);
अग्र:
	ln += लंबाई + 4;
    }
    add32le(eh_frame_hdr_section->तथ्य + गिनती_offset, गिनती_2);
    क्विक(eh_frame_hdr_section->तथ्य + tab_offset, गिनती_2,
	  माप(काष्ठा eh_खोज_table), sort_eh_table);
}
#पूर्ण_अगर

/* start of translation unit info */
ST_FUNC व्योम tcc_debug_start(TCCState *s1)
{
    पूर्णांक i;
    अक्षर buf[512];
    अक्षर *filename;

    /* we might currently #include the <command-line> */
    filename = file->पूर्व ? file->पूर्व->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    अगर (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, text_section->तथ्य_offset, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            text_section->sh_अंक, "$a");

        new_file = last_पंक्ति_अंक = 0;
        debug_अग्र_type = N_DEFAULT_DEBUG;
        debug_hash_global = शून्य;
        debug_hash_local = शून्य;
        debug_forw_hash_global = शून्य;
        debug_forw_hash_local = शून्य;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, माप(buf));
#अगर_घोषित _WIN32
        normalize_slashes(buf);
#पूर्ण_अगर

        अगर (s1->dwarf) {
            पूर्णांक start_abbrev;
            अचिन्हित अक्षर *ptr;
	    अक्षर *undo;

            /* dwarf_abbrev */
            start_abbrev = dwarf_abbrev_section->तथ्य_offset;
            ptr = section_ptr_add(dwarf_abbrev_section, माप(dwarf_abbrev_init));
            स_नकल(ptr, dwarf_abbrev_init, माप(dwarf_abbrev_init));

            अगर (s1->dwarf < 5) {
    	        जबतक (*ptr) {
    	            ptr += 3;
    	            जबतक (*ptr) {
    	                अगर (ptr[1] == DW_FORM_पंक्ति_strp)
    		            ptr[1] = DW_FORM_strp;
		        अगर (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    अगर  (ptr[1] == DW_FORM_sec_offset)
			         ptr[1] = DW_FORM_data4;
			    /* This code uses only size < 0x80 so these are
			       compatible. */
			    अगर  (ptr[1] == DW_FORM_exprloc)
			         ptr[1] = DW_FORM_block1;
			}
    	                ptr += 2;
    	            }
		    ptr += 2;
    	        }
            }

            dwarf_sym.info = dwarf_get_section_sym(dwarf_info_section);
            dwarf_sym.abbrev = dwarf_get_section_sym(dwarf_abbrev_section);
            dwarf_sym.पंक्ति_2 = dwarf_get_section_sym(dwarf_पंक्ति_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            अगर (tcc_state->dwarf >= 5)
    	        dwarf_sym.पंक्ति_str = dwarf_get_section_sym(dwarf_पंक्ति_str_section);
            अन्यथा {
    	        dwarf_पंक्ति_str_section = dwarf_str_section;
                dwarf_sym.पंक्ति_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(text_section);

            /* dwarf_info */
            dwarf_info.start = dwarf_info_section->तथ्य_offset;
            dwarf_data4(dwarf_info_section, 0); //आकार
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            अगर (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_आकार);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_तथ्य_32_DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
            }
            अन्यथा {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_तथ्य_32_DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
                dwarf_data1(dwarf_info_section, PTR_आकार);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_VERSION);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_पंक्ति_strp(dwarf_info_section, filename);
            dwarf_पंक्ति_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_तथ्य_PTR);
#अगर PTR_आकार == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#अन्यथा
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#पूर्ण_अगर
            dwarf_reloc(dwarf_info_section, dwarf_sym.पंक्ति_2, R_तथ्य_32_DW);
            dwarf_data4(dwarf_info_section, dwarf_पंक्ति_section->तथ्य_offset); // stmt_list

            /* dwarf_line */
            dwarf_पंक्ति.start = dwarf_पंक्ति_section->तथ्य_offset;
            dwarf_data4(dwarf_पंक्ति_section, 0); //लंबाई
            dwarf_data2(dwarf_पंक्ति_section, s1->dwarf); // version
            अगर (s1->dwarf >= 5) {
                dwarf_data1(dwarf_पंक्ति_section, PTR_आकार); // address size
                dwarf_data1(dwarf_पंक्ति_section, 0); // segment selector
            }
            dwarf_data4(dwarf_पंक्ति_section, 0); // prologue Length
            dwarf_data1(dwarf_पंक्ति_section, DWARF_MIN_INSTR_LEN);
            अगर (s1->dwarf >= 4)
                dwarf_data1(dwarf_पंक्ति_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_पंक्ति_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_पंक्ति_section, DWARF_पंक्ति_BASE);
            dwarf_data1(dwarf_पंक्ति_section, DWARF_पंक्ति_RANGE);
            dwarf_data1(dwarf_पंक्ति_section, DWARF_OPCODE_BASE);
            ptr = section_ptr_add(dwarf_पंक्ति_section, माप(dwarf_पंक्ति_opcodes));
            स_नकल(ptr, dwarf_पंक्ति_opcodes, माप(dwarf_पंक्ति_opcodes));
	    undo = म_खोजप(filename, '/');
	    अगर (undo)
		*undo = 0;
            dwarf_पंक्ति.dir_आकार = 1 + (undo != शून्य);
            dwarf_पंक्ति.dir_table = (अक्षर **) tcc_malloc(माप (अक्षर *) *
							dwarf_पंक्ति.dir_आकार);
            dwarf_पंक्ति.dir_table[0] = tcc_strdup(buf);
	    अगर (undo)
                dwarf_पंक्ति.dir_table[1] = tcc_strdup(filename);
            dwarf_पंक्ति.filename_आकार = 2;
            dwarf_पंक्ति.filename_table =
    	        (काष्ठा dwarf_filename_struct *)
    	        tcc_malloc(2*माप (काष्ठा dwarf_filename_struct));
            dwarf_पंक्ति.filename_table[0].dir_entry = 0;
	    अगर (undo) {
                dwarf_पंक्ति.filename_table[0].name = tcc_strdup(undo + 1);
                dwarf_पंक्ति.filename_table[1].dir_entry = 1;
                dwarf_पंक्ति.filename_table[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    अन्यथा {
                dwarf_पंक्ति.filename_table[0].name = tcc_strdup(filename);
                dwarf_पंक्ति.filename_table[1].dir_entry = 0;
                dwarf_पंक्ति.filename_table[1].name = tcc_strdup(filename);
	    }
            dwarf_पंक्ति.पंक्ति_आकार = dwarf_पंक्ति.पंक्ति_max_आकार = 0;
            dwarf_पंक्ति.पंक्ति_तथ्य = शून्य;
            dwarf_पंक्ति.cur_file = 1;
            dwarf_पंक्ति.last_file = 0;
            dwarf_पंक्ति.last_pc = 0;
            dwarf_पंक्ति.last_पंक्ति = 1;
            dwarf_पंक्ति_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_आकार); // extended size
            dwarf_पंक्ति_op(s1, DW_LNE_set_address);
            क्रम (i = 0; i < PTR_आकार; i++)
    	        dwarf_पंक्ति_op(s1, 0);
            स_रखो(&dwarf_info.base_type_used, 0, माप(dwarf_info.base_type_used));
        }
        अन्यथा
        {
            /* file info: full path + filename */
            pstrcat(buf, माप(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      text_section->sh_अंक, शून्य);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        text_section->तथ्य_offset, text_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        text_section->तथ्य_offset, text_section, section_sym);
            क्रम (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

अटल व्योम fix_debug_forw_hash(TCCState *s1, पूर्णांक global, पूर्णांक start);

/* put end of translation unit info */
ST_FUNC व्योम tcc_debug_end(TCCState *s1)
{

    अगर (!s1->do_debug || debug_अग्र_type == 0)
        वापस;

    अगर (debug_info_मूल)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    अगर (s1->dwarf) {
	पूर्णांक i;
	पूर्णांक start_aranges;
	अचिन्हित अक्षर *ptr;
	पूर्णांक text_आकार = text_section->तथ्य_offset;

	/* dwarf_info */
	fix_debug_forw_hash(s1, 0, 0);
	fix_debug_forw_hash(s1, 1, 0);
	dwarf_data1(dwarf_info_section, 0);
	ptr = dwarf_info_section->तथ्य + dwarf_info.start;
	write32le(ptr, dwarf_info_section->तथ्य_offset - dwarf_info.start - 4);
	write32le(ptr + 25 + (s1->dwarf >= 5) + PTR_आकार, text_आकार);

	/* dwarf_aranges */
	start_aranges = dwarf_aranges_section->तथ्य_offset;
	dwarf_data4(dwarf_aranges_section, 0); //आकार
	dwarf_data2(dwarf_aranges_section, 2); // version
	dwarf_reloc(dwarf_aranges_section, dwarf_sym.info, R_तथ्य_32_DW);
	dwarf_data4(dwarf_aranges_section, 0); // dwarf_info
#अगर PTR_आकार == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#अन्यथा
	dwarf_data1(dwarf_aranges_section, 8); // address size
#पूर्ण_अगर
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_तथ्य_PTR);
#अगर PTR_आकार == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, text_आकार); // End
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#अन्यथा
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, text_आकार); // End
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#पूर्ण_अगर
	ptr = dwarf_aranges_section->तथ्य + start_aranges;
	write32le(ptr, dwarf_aranges_section->तथ्य_offset - start_aranges - 4);

	/* dwarf_line */
	अगर (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_पंक्ति_section, 1); /* col */
	    dwarf_uleb128(dwarf_पंक्ति_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_पंक्ति_section, DW_FORM_पंक्ति_strp);
	    dwarf_uleb128(dwarf_पंक्ति_section, dwarf_पंक्ति.dir_आकार);
	    क्रम (i = 0; i < dwarf_पंक्ति.dir_आकार; i++)
	        dwarf_पंक्ति_strp(dwarf_पंक्ति_section, dwarf_पंक्ति.dir_table[i]);
	    dwarf_data1(dwarf_पंक्ति_section, 2); /* col */
	    dwarf_uleb128(dwarf_पंक्ति_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_पंक्ति_section, DW_FORM_पंक्ति_strp);
	    dwarf_uleb128(dwarf_पंक्ति_section, DW_LNCT_directory_सूचकांक);
	    dwarf_uleb128(dwarf_पंक्ति_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_पंक्ति_section, dwarf_पंक्ति.filename_आकार);
	    क्रम (i = 0; i < dwarf_पंक्ति.filename_आकार; i++) {
	        dwarf_पंक्ति_strp(dwarf_पंक्ति_section,
				dwarf_पंक्ति.filename_table[i].name);
	        dwarf_uleb128(dwarf_पंक्ति_section,
			      dwarf_पंक्ति.filename_table[i].dir_entry);
	    }
	}
	अन्यथा {
	    पूर्णांक len;

	    क्रम (i = 0; i < dwarf_पंक्ति.dir_आकार; i++) {
	        len = म_माप(dwarf_पंक्ति.dir_table[i]) + 1;
	        ptr = section_ptr_add(dwarf_पंक्ति_section, len);
	        स_हटाओ(ptr, dwarf_पंक्ति.dir_table[i], len);
	    }
	    dwarf_data1(dwarf_पंक्ति_section, 0); /* end dir */
	    क्रम (i = 0; i < dwarf_पंक्ति.filename_आकार; i++) {
	        len = म_माप(dwarf_पंक्ति.filename_table[i].name) + 1;
	        ptr = section_ptr_add(dwarf_पंक्ति_section, len);
	        स_हटाओ(ptr, dwarf_पंक्ति.filename_table[i].name, len);
	        dwarf_uleb128(dwarf_पंक्ति_section,
			      dwarf_पंक्ति.filename_table[i].dir_entry);
	        dwarf_uleb128(dwarf_पंक्ति_section, 0); /* time */
	        dwarf_uleb128(dwarf_पंक्ति_section, 0); /*आकार*/
	    }
	    dwarf_data1(dwarf_पंक्ति_section, 0); /* end file */
	}
	क्रम (i = 0; i < dwarf_पंक्ति.dir_आकार; i++)
	    tcc_free(dwarf_पंक्ति.dir_table[i]);
	tcc_free(dwarf_पंक्ति.dir_table);
	क्रम (i = 0; i < dwarf_पंक्ति.filename_आकार; i++)
	    tcc_free(dwarf_पंक्ति.filename_table[i].name);
	tcc_free(dwarf_पंक्ति.filename_table);

	dwarf_पंक्ति_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_पंक्ति_op(s1, DW_LNE_end_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_पंक्ति_section->तथ्य[dwarf_पंक्ति.start + 6 + i],
		  dwarf_पंक्ति_section->तथ्य_offset - dwarf_पंक्ति.start - (10 + i));
	section_ptr_add(dwarf_पंक्ति_section, 3);
	dwarf_reloc(dwarf_पंक्ति_section, section_sym, R_तथ्य_PTR);
	ptr = section_ptr_add(dwarf_पंक्ति_section, dwarf_पंक्ति.पंक्ति_आकार - 3);
	स_हटाओ(ptr - 3, dwarf_पंक्ति.पंक्ति_तथ्य, dwarf_पंक्ति.पंक्ति_आकार);
	tcc_free(dwarf_पंक्ति.पंक्ति_तथ्य);
	write32le(dwarf_पंक्ति_section->तथ्य + dwarf_पंक्ति.start,
		  dwarf_पंक्ति_section->तथ्य_offset - dwarf_पंक्ति.start - 4);
    }
    अन्यथा
    {
        put_stabs_r(s1, शून्य, N_SO, 0, 0,
                    text_section->तथ्य_offset, text_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_पंक्ति_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_अग्र_type = 0;
}

अटल BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    अगर (f->filename[0] == ':')
        f = f->पूर्व;
    अगर (f && new_file) {
        new_file = last_पंक्ति_अंक = 0;
        अगर (s1->dwarf)
            dwarf_file(s1);
        अन्यथा
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, text_section, section_sym);
    }
    वापस f;
}

/* put alternative filename */
ST_FUNC व्योम tcc_debug_newfile(TCCState *s1)
{
    अगर (!s1->do_debug)
        वापस;
    अगर (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC व्योम tcc_debug_bincl(TCCState *s1)
{
    अगर (!s1->do_debug)
        वापस;
    अगर (s1->dwarf)
        dwarf_file(s1);
    अन्यथा
        put_stabs(s1, file->filename, N_BINCL, 0, 0, 0);
    new_file = 1;
}

/* end of #include */
ST_FUNC व्योम tcc_debug_eincl(TCCState *s1)
{
    अगर (!s1->do_debug)
        वापस;
    अगर (s1->dwarf)
        dwarf_file(s1);
    अन्यथा
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC व्योम tcc_debug_पंक्ति(TCCState *s1)
{
    BufferedFile *f;

    अगर (!s1->do_debug)
        वापस;
    अगर (cur_text_section != text_section || nocode_wanted)
        वापस;
    f = put_new_file(s1);
    अगर (!f)
        वापस;
    अगर (last_पंक्ति_अंक == f->पंक्ति_अंक)
        वापस;
    last_पंक्ति_अंक = f->पंक्ति_अंक;

    अगर (s1->dwarf) {
	पूर्णांक len_pc = (ind - dwarf_पंक्ति.last_pc) / DWARF_MIN_INSTR_LEN;
	पूर्णांक len_पंक्ति = f->पंक्ति_अंक - dwarf_पंक्ति.last_पंक्ति;
	पूर्णांक n = len_pc * DWARF_पंक्ति_RANGE + len_पंक्ति + DWARF_OPCODE_BASE - DWARF_पंक्ति_BASE;

	अगर (dwarf_पंक्ति.cur_file != dwarf_पंक्ति.last_file) {
	    dwarf_पंक्ति.last_file = dwarf_पंक्ति.cur_file;
	    dwarf_पंक्ति_op(s1, DW_LNS_set_file);
	    dwarf_uleb128_op(s1, dwarf_पंक्ति.cur_file);
	}
	अगर (len_pc &&
	    len_पंक्ति >= DWARF_पंक्ति_BASE && len_पंक्ति <= (DWARF_OPCODE_BASE + DWARF_पंक्ति_BASE) &&
	    n >= DWARF_OPCODE_BASE && n <= 255)
            dwarf_पंक्ति_op(s1, n);
	अन्यथा {
	    अगर (len_pc) {
	        n = len_pc * DWARF_पंक्ति_RANGE + 0 + DWARF_OPCODE_BASE - DWARF_पंक्ति_BASE;
	        अगर (n >= DWARF_OPCODE_BASE && n <= 255)
                    dwarf_पंक्ति_op(s1, n);
		अन्यथा {
	            dwarf_पंक्ति_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    अगर (len_पंक्ति) {
	        n = 0 * DWARF_पंक्ति_RANGE + len_पंक्ति + DWARF_OPCODE_BASE - DWARF_पंक्ति_BASE;
	        अगर (len_पंक्ति >= DWARF_पंक्ति_BASE && len_पंक्ति <= (DWARF_OPCODE_BASE + DWARF_पंक्ति_BASE) &&
		    n >= DWARF_OPCODE_BASE && n <= 255)
	            dwarf_पंक्ति_op(s1, n);
		अन्यथा {
	            dwarf_पंक्ति_op(s1, DW_LNS_advance_पंक्ति);
		    dwarf_sleb128_op(s1, len_पंक्ति);
                    /* advance by nothing */
	            dwarf_पंक्ति_op(s1, DWARF_OPCODE_BASE - DWARF_पंक्ति_BASE);
		}
	    }
	}
	dwarf_पंक्ति.last_pc = ind;
	dwarf_पंक्ति.last_पंक्ति = f->पंक्ति_अंक;
    }
    अन्यथा
    {
	अगर (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->पंक्ति_अंक, ind - func_ind);
        } अन्यथा {
            /* from tcc_assemble */
            put_stabs_r(s1, शून्य, N_SLINE, 0, f->पंक्ति_अंक, ind, text_section, section_sym);
        }
    }
}

अटल व्योम tcc_debug_stabs (TCCState *s1, स्थिर अक्षर *str, पूर्णांक type, अचिन्हित दीर्घ मूल्य,
                             Section *sec, पूर्णांक sym_सूचकांक, पूर्णांक info)
{
    काष्ठा debug_sym *s;

    अगर (debug_info) {
        debug_info->sym =
            (काष्ठा debug_sym *)tcc_realloc (debug_info->sym,
                                             माप(काष्ठा debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->मूल्य = मूल्य;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_सूचकांक = sym_सूचकांक;
        s->info = info;
        s->file = dwarf_पंक्ति.cur_file;
        s->पंक्ति_2 = file->पंक्ति_अंक;
    }
    अन्यथा अगर (sec)
        put_stabs_r (s1, str, type, 0, 0, मूल्य, sec, sym_सूचकांक);
    अन्यथा
        put_stabs (s1, str, type, 0, 0, मूल्य);
}

अटल व्योम fix_debug_forw_hash(TCCState *s1, पूर्णांक global, पूर्णांक start)
{
    अगर (s1->dwarf) {
        पूर्णांक i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	काष्ठा _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	क्रम (i = start; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    पूर्णांक pos = dwarf_info_section->तथ्य_offset;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_EMPTY_TYPE
                                             : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, शून्य));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_पंक्ति.cur_file);
            dwarf_uleb128(dwarf_info_section, file->पंक्ति_अंक);
	    क्रम (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->तथ्य +
			  hash[i].debug_type[j],
			  pos - dwarf_info.start);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC व्योम tcc_debug_stabn(TCCState *s1, पूर्णांक type, पूर्णांक मूल्य)
{
    अगर (!s1->do_debug)
        वापस;
    अगर (type == N_LBRAC) {
        काष्ठा _debug_info *info =
            (काष्ठा _debug_info *) tcc_mallocz(माप (*info));

        info->start = मूल्य;
        info->last_debug_hash = n_debug_hash_local;
        info->last_debug_forw_hash = n_debug_forw_hash_local;
        info->parent = debug_info;
        अगर (debug_info) {
            अगर (debug_info->child) {
                अगर (debug_info->child->last)
                    debug_info->child->last->अग्र = info;
                अन्यथा
                    debug_info->child->अग्र = info;
                debug_info->child->last = info;
            }
            अन्यथा
                debug_info->child = info;
        }
        अन्यथा
            debug_info_मूल = info;
        debug_info = info;
    }
    अन्यथा {
	fix_debug_forw_hash(s1, 0, debug_info->last_debug_forw_hash);
        n_debug_hash_local = debug_info->last_debug_hash;
        n_debug_forw_hash_local = debug_info->last_debug_forw_hash;
        debug_info->end = मूल्य;
        debug_info = debug_info->parent;
    }
}

अटल पूर्णांक check_global(Sym *t)
{
    Sym *g = local_ढेर;

    जबतक (g) {
	अगर (t == g)
	    वापस 0;
	g = g->पूर्व;
    }
    वापस 1;
}

अटल पूर्णांक tcc_debug_find(TCCState *s1, Sym *t, पूर्णांक dwarf)
{
    पूर्णांक i , g = check_global(t);
    पूर्णांक n_hash, *n_forw_hash;
    काष्ठा _debug_hash *hash;
    काष्ठा _debug_forw_hash **forw_hash;

    अगर ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	क्रम (i = 0; i < *n_forw_hash; i++)
            अगर (t == (*forw_hash)[i].type)
		वापस 0;
	*forw_hash = (काष्ठा _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * माप(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = शून्य;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	वापस 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    क्रम (i = 0; i < n_hash; i++)
        अगर (t == hash[i].type)
	    वापस hash[i].debug_type;
    वापस -1;
}

अटल पूर्णांक tcc_get_dwarf_info(TCCState *s1, Sym *s);

अटल व्योम tcc_debug_check_forw(TCCState *s1, Sym *t, पूर्णांक debug_type)
{
    अगर ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        पूर्णांक i, j, g = check_global(t);
        पूर्णांक n_forw_hash;
        काष्ठा _debug_forw_hash **forw_hash;

	क्रम (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    क्रम (j = 0; j < n_forw_hash; j++)
                अगर (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * माप(पूर्णांक));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    वापस;
                }
	}
    }
}

अटल व्योम stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC व्योम tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    अगर (!(s1->do_debug & 2))
	वापस;
    अगर (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        वापस;
    }
    अगर ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        पूर्णांक i, j, debug_type, g = check_global(t->ref);
        पूर्णांक *n_forw_hash;
        काष्ठा _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	क्रम (i = 0; i < *n_forw_hash; i++)
	    अगर (t->ref == (*forw_hash)[i].type) {
		अगर (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    क्रम (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->तथ्य +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.start);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		क्रम (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

अटल पूर्णांक tcc_debug_add(TCCState *s1, Sym *t, पूर्णांक dwarf)
{
    पूर्णांक offset = dwarf ? dwarf_info_section->तथ्य_offset : ++debug_अग्र_type;
    पूर्णांक *n_hash, g = check_global(t);
    काष्ठा _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (काष्ठा _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * माप(**hash));
    (*hash)[*n_hash].debug_type = offset;
    (*hash)[(*n_hash)++].type = t;
    वापस offset;
}

अटल पूर्णांक STRUCT_NODEBUG(Sym *s)
{
    वापस
    (s->a.nodebug ||
     ((s->v & ~SYM_FIELD) >= SYM_FIRST_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

अटल पूर्णांक stabs_struct_find(TCCState *s1, Sym *t, पूर्णांक *p_id)
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
    अगर (शून्य == p_id)
        वापस s && !s->r && t->c >= 0;
    अगर (शून्य == s) {
        /* just use global_stack always */
        s = sym_push2(&global_ढेर, SYM_FIELD|0x00DEBBED, 0, ++debug_अग्र_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    अगर (s->r || t->c < 0) /* already defined or still incomplete */
        वापस 0;
    s->r = 1;
    वापस 1;
}

अटल पूर्णांक remove_type_info(पूर्णांक type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        अगर ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        अगर (!(type & VT_BITFIELD) && (type & VT_STRUCT_MASK) > VT_ENUM)
	    type &= ~VT_STRUCT_MASK;
	वापस type;
}

अटल व्योम tcc_get_debug_info(TCCState *s1, Sym *s, CString *परिणाम)
{
    पूर्णांक type;
    पूर्णांक n = 0;
    पूर्णांक debug_type = -1;
    Sym *t = s;
    CString str;

    क्रम (;;) {
        type = remove_type_info (t->type.t);
        अगर (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        अन्यथा
            अवरोध;
    }
    अगर ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        अगर (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, शून्य),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            जबतक (t->अग्र) {
                पूर्णांक pos, आकार, align;
                t = t->अग्र;
		अगर (STRUCT_NODEBUG(t))
		    जारी;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, शून्य)
                             );
                tcc_get_debug_info (s1, t, &str);
                अगर (t->type.t & VT_BITFIELD) {
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
            tcc_debug_stabs(s1, str.तथ्य, N_LSYM, 0, शून्य, 0, 0);
            cstr_free (&str);
        }
    }
    अन्यथा अगर (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        अगर (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, शून्य),
                         debug_type);
            जबतक (t->अग्र) {
                t = t->अग्र;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, शून्य));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (पूर्णांक)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.तथ्य, N_LSYM, 0, शून्य, 0, 0);
            cstr_free (&str);
	}
    }
    अन्यथा अगर ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        क्रम (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            अगर (default_debug[debug_type - 1].type == type)
                अवरोध;
        अगर (debug_type > N_DEFAULT_DEBUG)
            वापस;
    }

    अगर (शून्य == परिणाम) /* from stabs_struct_complete() */
        वापस;

    अगर (n > 0)
        cstr_printf (परिणाम, "%d=", ++debug_अग्र_type);
    t = s;
    क्रम (;;) {
        type = remove_type_info (t->type.t);
        अगर (type == VT_PTR)
            cstr_printf (परिणाम, "%d=*", ++debug_अग्र_type);
        अन्यथा अगर (type == (VT_PTR | VT_ARRAY))
            cstr_printf (परिणाम, "%d=ar1;0;%d;",
                         ++debug_अग्र_type, t->type.ref->c - 1);
        अन्यथा अगर (type == VT_FUNC) {
            cstr_printf (परिणाम, "%d=f", ++debug_अग्र_type);
            tcc_get_debug_info (s1, t->type.ref, परिणाम);
            वापस;
        }
        अन्यथा
            अवरोध;
        t = t->type.ref;
    }
    cstr_printf (परिणाम, "%d", debug_type);
}

अटल व्योम stabs_struct_complete(TCCState *s1, CType *t)
{
    अगर (stabs_struct_find(s1, t->ref, शून्य)) {
        Sym s = {0}; s.type = *t;
        tcc_get_debug_info(s1, &s, शून्य);
    }
}

अटल पूर्णांक tcc_get_dwarf_info(TCCState *s1, Sym *s)
{
    पूर्णांक type;
    पूर्णांक debug_type = -1;
    Sym *e, *t = s;
    पूर्णांक i;
    पूर्णांक last_pos = -1;
    पूर्णांक retval;

    अगर (new_file)
        put_new_file(s1);
    क्रम (;;) {
        type = remove_type_info (t->type.t);
        अगर (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        अन्यथा
            अवरोध;
    }
    अगर ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	अगर (debug_type == -1) {
	    पूर्णांक pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_add(s1, t, 1);
	    e = t;
	    i = 0;
	    जबतक (e->अग्र) {
		e = e->अग्र;
		अगर (STRUCT_NODEBUG(e))
		    जारी;
		i++;
	    }
	    pos_type = (पूर्णांक *) tcc_malloc(i * माप(पूर्णांक));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->अग्र ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_EMPTY_TYPE
		        : t->अग्र ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, शून्य));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_पंक्ति.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->पंक्ति_अंक);
	    अगर (t->अग्र) {
	        pos_sib = dwarf_info_section->तथ्य_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            जबतक (e->अग्र) {
                e = e->अग्र;
		अगर (STRUCT_NODEBUG(e))
		    जारी;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, शून्य));
		dwarf_uleb128(dwarf_info_section, dwarf_पंक्ति.cur_file);
		dwarf_uleb128(dwarf_info_section, file->पंक्ति_अंक);
		pos_type[i++] = dwarf_info_section->तथ्य_offset;
		dwarf_data4(dwarf_info_section, 0);
                अगर (e->type.t & VT_BITFIELD) {
                    पूर्णांक pos = e->c * 8 + BIT_POS(e->type.t);
                    पूर्णांक आकार = BIT_आकार(e->type.t);

		    dwarf_uleb128(dwarf_info_section, आकार);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		अन्यथा
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    अगर (t->अग्र) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->तथ्य + pos_sib,
		          dwarf_info_section->तथ्य_offset - dwarf_info.start);
	    }
	    e = t;
	    i = 0;
	    जबतक (e->अग्र) {
		e = e->अग्र;
		अगर (STRUCT_NODEBUG(e))
		    जारी;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->तथ्य + pos_type[i++],
			  type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
    }
    अन्यथा अगर (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	अगर (debug_type == -1) {
	    पूर्णांक pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_add(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, शून्य));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.start);
	    dwarf_uleb128(dwarf_info_section, dwarf_पंक्ति.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->पंक्ति_अंक);
	    pos_sib = dwarf_info_section->तथ्य_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            जबतक (e->अग्र) {
                e = e->अग्र;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                           ? "" : get_tok_str(e->v, शून्य));
		अगर (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		अन्यथा
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->तथ्य + pos_sib,
		      dwarf_info_section->तथ्य_offset - dwarf_info.start);
	}
    }
    अन्यथा अगर ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        क्रम (i = 1; i <= N_DEFAULT_DEBUG; i++)
            अगर (default_debug[i - 1].type == type)
                अवरोध;
        अगर (i > N_DEFAULT_DEBUG)
            वापस 0;
	debug_type = dwarf_info.base_type_used[i - 1];
	अगर (debug_type == 0) {
	    अक्षर name[100];

	    debug_type = dwarf_info_section->तथ्य_offset;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_BASE_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].आकार);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, माप name, default_debug[i - 1].name);
	    *म_अक्षर(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.base_type_used[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = शून्य;
    t = s;
    क्रम (;;) {
        type = remove_type_info (t->type.t);
        अगर (type == VT_PTR) {
	    i = dwarf_info_section->तथ्य_offset;
	    अगर (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_POINTER);
	    dwarf_data1(dwarf_info_section, PTR_आकार);
	    अगर (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->तथ्य + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->तथ्य_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        अन्यथा अगर (type == (VT_PTR | VT_ARRAY)) {
	    पूर्णांक sib_pos, sub_type;
#अगर LONG_आकार == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#अन्यथा
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#पूर्ण_अगर

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->तथ्य_offset;
	    अगर (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    अगर (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->तथ्य + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->तथ्य_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->तथ्य_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    क्रम (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.start);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		अगर (type != (VT_PTR | VT_ARRAY))
		    अवरोध;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->तथ्य + sib_pos,
		      dwarf_info_section->तथ्य_offset - dwarf_info.start);
	}
        अन्यथा अगर (type == VT_FUNC) {
	    पूर्णांक sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->तथ्य_offset;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    अगर (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->अग्र ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_EMPTY_TYPE);
	    अगर (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->तथ्य + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->तथ्य_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    अगर (t->type.ref->अग्र) {
	        sib_pos = dwarf_info_section->तथ्य_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    जबतक (f->अग्र) {
		f = f->अग्र;
		i++;
	    }
	    pos_type = (पूर्णांक *) tcc_malloc(i * माप(पूर्णांक));
	    f = t->type.ref;
	    i = 0;
	    जबतक (f->अग्र) {
		f = f->अग्र;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->तथ्य_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    अगर (t->type.ref->अग्र) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->तथ्य + sib_pos,
		          dwarf_info_section->तथ्य_offset - dwarf_info.start);
	    }
	    f = t->type.ref;
	    i = 0;
	    जबतक (f->अग्र) {
		f = f->अग्र;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->तथ्य + pos_type[i++],
                          type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
        अन्यथा {
	    अगर (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->तथ्य + last_pos,
			  debug_type - dwarf_info.start);
	    }
            अवरोध;
	}
        t = t->type.ref;
    }
    वापस retval;
}

अटल व्योम tcc_debug_finish (TCCState *s1, काष्ठा _debug_info *cur)
{
    जबतक (cur) {
        काष्ठा _debug_info *अग्र = cur->अग्र;
        पूर्णांक i;

        अगर (s1->dwarf) {

            क्रम (i = cur->n_sym - 1; i >= 0; i--) {
                काष्ठा debug_sym *s = &cur->sym[i];

		dwarf_data1(dwarf_info_section,
                            s->type == N_PSYM
			    ? DWARF_ABBREV_FORMAL_PARAMETER
			    : s->type == N_GSYM
                            ? DWARF_ABBREV_VARIABLE_EXTERNAL
                            : s->type == N_STSYM
			    ? DWARF_ABBREV_VARIABLE_STATIC
			    : DWARF_ABBREV_VARIABLE_LOCAL);
                dwarf_strp(dwarf_info_section, s->str);
		अगर (s->type == N_GSYM || s->type == N_STSYM) {
                    dwarf_uleb128(dwarf_info_section, s->file);
                    dwarf_uleb128(dwarf_info_section, s->पंक्ति_2);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.start);
		अगर (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    अगर (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_आकार + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    अगर (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_तथ्य_PTR);
#अगर PTR_आकार == 4
                    dwarf_data4(dwarf_info_section, s->मूल्य);
#अन्यथा
                    dwarf_data8(dwarf_info_section, s->मूल्य);
#पूर्ण_अगर
		}
		अन्यथा {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_आकार((दीर्घ)s->मूल्य) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (दीर्घ)s->मूल्य);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->child ? DWARF_ABBREV_LEXICAL_BLOCK
			           : DWARF_ABBREV_LEXICAL_EMPTY_BLOCK);
            dwarf_reloc(dwarf_info_section, section_sym, R_तथ्य_PTR);
#अगर PTR_आकार == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->start);
            dwarf_data4(dwarf_info_section, cur->end - cur->start);
#अन्यथा
            dwarf_data8(dwarf_info_section, func_ind + cur->start);
            dwarf_data8(dwarf_info_section, cur->end - cur->start);
#पूर्ण_अगर
            tcc_debug_finish (s1, cur->child);
	    अगर (cur->child)
                dwarf_data1(dwarf_info_section, 0);
        }
        अन्यथा
        {
            क्रम (i = 0; i < cur->n_sym; i++) {
                काष्ठा debug_sym *s = &cur->sym[i];

                अगर (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->मूल्य,
                                s->sec, s->sym_सूचकांक);
                अन्यथा
                    put_stabs(s1, s->str, s->type, 0, 0, s->मूल्य);
                tcc_free (s->str);
            }
            tcc_free (cur->sym);
            put_stabn(s1, N_LBRAC, 0, 0, cur->start);
            tcc_debug_finish (s1, cur->child);
            put_stabn(s1, N_RBRAC, 0, 0, cur->end);
        }
        tcc_free (cur);
        cur = अग्र;
    }
}

ST_FUNC व्योम tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    पूर्णांक param;

    अगर (!(s1->do_debug & 2))
        वापस;

    cstr_new (&debug_str);
    param = !e;
    क्रम (; s != e; s = s->पूर्व) {
        अगर (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            जारी;
	अगर (s1->dwarf) {
	    tcc_debug_stabs(s1, get_tok_str(s->v, शून्य),
			    param ? N_PSYM : N_LSYM, s->c, शून्य, 0,
			    tcc_get_dwarf_info(s1, s));
	}
	अन्यथा
        {
            cstr_reset (&debug_str);
            cstr_printf (&debug_str, "%s:%s", get_tok_str(s->v, शून्य),
			 param ? "p" : "");
            tcc_get_debug_info(s1, s, &debug_str);
            tcc_debug_stabs(s1, debug_str.तथ्य, param ? N_PSYM : N_LSYM,
			    s->c, शून्य, 0, 0);
	}
    }
    cstr_free (&debug_str);
}

/* put function symbol */
ST_FUNC व्योम tcc_debug_funcstart(TCCState *s1, Sym *sym)
{
    CString debug_str;
    BufferedFile *f;

    अगर (!s1->do_debug)
        वापस;
    debug_info_मूल = शून्य;
    debug_info = शून्य;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    अगर (!f)
	वापस;

    अगर (s1->dwarf) {
        tcc_debug_पंक्ति(s1);
        dwarf_info.func = sym;
        dwarf_info.पंक्ति_2 = file->पंक्ति_अंक;
	अगर (s1->do_backtrace) {
	    पूर्णांक i, len;

	    dwarf_पंक्ति_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, म_माप(funcname) + 2);
	    dwarf_पंक्ति_op(s1, DW_LNE_hi_user - 1);
	    len = म_माप(funcname) + 1;
	    क्रम (i = 0; i < len; i++)
		dwarf_पंक्ति_op(s1, funcname[i]);
	}
    }
    अन्यथा
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.तथ्य, N_FUN, 0, f->पंक्ति_अंक, 0, cur_text_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_पंक्ति(s1);
    }
}

ST_FUNC व्योम tcc_debug_prolog_epilog(TCCState *s1, पूर्णांक मूल्य)
{
    अगर (!s1->do_debug)
        वापस;
    अगर (s1->dwarf) {
	dwarf_पंक्ति_op(s1, मूल्य == 0 ? DW_LNS_set_prologue_end
				     : DW_LNS_set_epilogue_begin);
    }
}

/* put function size */
ST_FUNC व्योम tcc_debug_funcend(TCCState *s1, पूर्णांक आकार)
{
    /* lldb does not like function end and next function start at same pc */
    पूर्णांक min_instr_len;

#अगर TCC_EH_FRAME
    tcc_debug_frame_end(s1, आकार);
#पूर्ण_अगर
    अगर (!s1->do_debug)
        वापस;
    min_instr_len = dwarf_पंक्ति.last_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_पंक्ति(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, आकार);
    अगर (s1->dwarf) {
        पूर्णांक func_sib = 0;
	Sym *sym = dwarf_info.func;
	पूर्णांक n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        अगर ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_पंक्ति.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.पंक्ति_2);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->तथ्य_offset);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.start);
        dwarf_reloc(dwarf_info_section, section_sym, R_तथ्य_PTR);
#अगर PTR_आकार == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, आकार); // high_pc
#अन्यथा
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, आकार); // high_pc
#पूर्ण_अगर
        func_sib = dwarf_info_section->तथ्य_offset;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#अगर defined(TCC_TARGET_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#या_अगर defined(TCC_TARGET_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#या_अगर defined TCC_TARGET_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#या_अगर defined TCC_TARGET_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#या_अगर defined TCC_TARGET_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#अन्यथा
        dwarf_data1(dwarf_info_section, DW_OP_call_frame_cfa);
#पूर्ण_अगर
        tcc_debug_finish (s1, debug_info_मूल);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->तथ्य + func_sib,
                  dwarf_info_section->तथ्य_offset - dwarf_info.start);
    }
    अन्यथा
    {
        tcc_debug_finish (s1, debug_info_मूल);
    }
    debug_info_मूल = 0;
}


ST_FUNC व्योम tcc_debug_extern_sym(TCCState *s1, Sym *sym, पूर्णांक sh_अंक, पूर्णांक sym_bind, पूर्णांक sym_type)
{
    अगर (!(s1->do_debug & 2))
        वापस;

    अगर (sym_type == STT_FUNC || sym->v >= SYM_FIRST_ANOM)
        वापस;
    अगर (s1->dwarf) {
        पूर्णांक debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, शून्य));
	dwarf_uleb128(dwarf_info_section, dwarf_पंक्ति.cur_file);
	dwarf_uleb128(dwarf_info_section, file->पंक्ति_अंक);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->तथ्य_offset);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	अगर (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_आकार + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->तथ्य_offset,
		R_तथ्य_PTR, 0);
#अगर PTR_आकार == 4
	dwarf_data4(dwarf_info_section, 0);
#अन्यथा
	dwarf_data8(dwarf_info_section, 0);
#पूर्ण_अगर
    }
    अन्यथा
    {
        Section *s = sh_अंक == SHN_COMMON ? common_section
					  : s1->sections[sh_अंक];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, शून्य),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        अगर (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.तथ्य, N_GSYM, 0, शून्य, 0, 0);
        अन्यथा
            tcc_debug_stabs(s1, str.तथ्य,
                (sym->type.t & VT_STATIC) && तथ्य_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC व्योम tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    अगर (!(s1->do_debug & 2))
        वापस;

    अगर (s1->dwarf) {
	पूर्णांक debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	अगर (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, शून्य));
	    dwarf_uleb128(dwarf_info_section, dwarf_पंक्ति.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->पंक्ति_अंक);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->तथ्य_offset);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	}
    }
    अन्यथा
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, शून्य));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.तथ्य, N_LSYM, 0, शून्य, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC व्योम tcc_tcov_block_end(TCCState *s1, पूर्णांक पंक्ति_2);

ST_FUNC व्योम tcc_tcov_block_begin(TCCState *s1)
{
    SValue sv;
    व्योम *ptr;
    अचिन्हित दीर्घ last_offset = tcov_तथ्य.offset;

    tcc_tcov_block_end (tcc_state, 0);
    अगर (s1->test_coverage == 0 || nocode_wanted)
	वापस;

    अगर (tcov_तथ्य.last_file_name == 0 ||
	म_भेद ((स्थिर अक्षर *)(tcov_section->तथ्य + tcov_तथ्य.last_file_name),
		file->true_filename) != 0) {
	अक्षर wd[1024];
	CString cstr;

	अगर (tcov_तथ्य.last_func_name)
	    section_ptr_add(tcov_section, 1);
	अगर (tcov_तथ्य.last_file_name)
	    section_ptr_add(tcov_section, 1);
	tcov_तथ्य.last_func_name = 0;
	cstr_new (&cstr);
	अगर (file->true_filename[0] == '/') {
	    tcov_तथ्य.last_file_name = tcov_section->तथ्य_offset;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	अन्यथा {
	    getcwd (wd, माप(wd));
	    tcov_तथ्य.last_file_name = tcov_section->तथ्य_offset + म_माप(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_add(tcov_section, cstr.आकार + 1);
	म_नकल((अक्षर *)ptr, cstr.तथ्य);
#अगर_घोषित _WIN32
        normalize_slashes((अक्षर *)ptr);
#पूर्ण_अगर
	cstr_free (&cstr);
    }
    अगर (tcov_तथ्य.last_func_name == 0 ||
	म_भेद ((स्थिर अक्षर *)(tcov_section->तथ्य + tcov_तथ्य.last_func_name),
		funcname) != 0) {
	माप_प्रकार len;

	अगर (tcov_तथ्य.last_func_name)
	    section_ptr_add(tcov_section, 1);
	tcov_तथ्य.last_func_name = tcov_section->तथ्य_offset;
	len = म_माप (funcname);
	ptr = section_ptr_add(tcov_section, len + 1);
	म_नकल((अक्षर *)ptr, funcname);
	section_ptr_add(tcov_section, -tcov_section->तथ्य_offset & 7);
	ptr = section_ptr_add(tcov_section, 8);
	write64le (ptr, file->पंक्ति_अंक);
    }
    अगर (ind == tcov_तथ्य.ind && tcov_तथ्य.पंक्ति_2 == file->पंक्ति_अंक)
        tcov_तथ्य.offset = last_offset;
    अन्यथा {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_add(tcov_section, 16);
        tcov_तथ्य.पंक्ति_2 = file->पंक्ति_अंक;
        write64le (ptr, (tcov_तथ्य.पंक्ति_2 << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((अचिन्हित अक्षर *)ptr - tcov_section->तथ्य) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#अगर defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || \
    defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || \
    defined TCC_TARGET_RISCV64
        gen_increment_tcov (&sv);
#अन्यथा
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#पूर्ण_अगर
        tcov_तथ्य.offset = (अचिन्हित अक्षर *)ptr - tcov_section->तथ्य;
        tcov_तथ्य.ind = ind;
    }
}

ST_FUNC व्योम tcc_tcov_block_end(TCCState *s1, पूर्णांक पंक्ति_2)
{
    अगर (s1->test_coverage == 0)
	वापस;
    अगर (पंक्ति_2 == -1)
        पंक्ति_2 = tcov_तथ्य.पंक्ति_2;
    अगर (tcov_तथ्य.offset) {
	व्योम *ptr = tcov_section->तथ्य + tcov_तथ्य.offset;
	अचिन्हित दीर्घ दीर्घ nline = पंक्ति_2 ? पंक्ति_2 : file->पंक्ति_अंक;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_तथ्य.offset = 0;
    }
}

ST_FUNC व्योम tcc_tcov_check_पंक्ति(TCCState *s1, पूर्णांक start)
{
    अगर (s1->test_coverage == 0)
	वापस;
    अगर (tcov_तथ्य.पंक्ति_2 != file->पंक्ति_अंक) {
        अगर ((tcov_तथ्य.पंक्ति_2 + 1) != file->पंक्ति_अंक) {
	    tcc_tcov_block_end (s1, -1);
	    अगर (start)
                tcc_tcov_block_begin (s1);
	}
	अन्यथा
	    tcov_तथ्य.पंक्ति_2 = file->पंक्ति_अंक;
    }
}

ST_FUNC व्योम tcc_tcov_start(TCCState *s1)
{
    अगर (s1->test_coverage == 0)
	वापस;
    अगर (!s1->dState)
        s1->dState = tcc_mallocz(माप *s1->dState);
    स_रखो (&tcov_तथ्य, 0, माप (tcov_तथ्य));
    अगर (tcov_section == शून्य) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_add(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC व्योम tcc_tcov_end(TCCState *s1)
{
    अगर (s1->test_coverage == 0)
	वापस;
    अगर (tcov_तथ्य.last_func_name)
        section_ptr_add(tcov_section, 1);
    अगर (tcov_तथ्य.last_file_name)
        section_ptr_add(tcov_section, 1);
}

ST_FUNC व्योम tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_तथ्य.ind = 0;
}

/* ------------------------------------------------------------------------- */
#अघोषित last_पंक्ति_अंक
#अघोषित new_file
#अघोषित section_sym
#अघोषित debug_अग्र_type
#अघोषित debug_hash_global
#अघोषित debug_hash_local
#अघोषित n_debug_hash_global
#अघोषित n_debug_hash_local
#अघोषित debug_forw_hash_global
#अघोषित debug_forw_hash_local
#अघोषित n_debug_forw_hash_global
#अघोषित n_debug_forw_hash_local
#अघोषित debug_info
#अघोषित debug_info_मूल
#अघोषित dwarf_sym
#अघोषित dwarf_पंक्ति
#अघोषित dwarf_info
#अघोषित dwarf_str
#अघोषित dwarf_पंक्ति_str
#अघोषित tcov_तथ्य
