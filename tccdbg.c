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

#അന്തര്ഭാവ "tcc.h"

/* stab debug support */

സ്ഥിതം സ്ഥിരം ഘടന {
  പൂർണ്ണസംഖ്യ type;
  പൂർണ്ണസംഖ്യ size;
  പൂർണ്ണസംഖ്യ encoding;
  സ്ഥിരം അക്ഷരം *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#എങ്കിൽ LONG_SIZE == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#അല്ലെങ്കിൽ
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#endif
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#എങ്കിൽ LONG_SIZE == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#അല്ലെങ്കിൽ
    /* use octal instead of -1 so size_t works (-gstabs+ in gcc) */
    {   VT_LLONG | VT_LONG | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t5=r5;0;01777777777777777777777;" },
#endif
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
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
    {   VT_DOUBLE | VT_LONG, 8, DW_ATE_float, "long double:t16=r1;8;0;" },
#അല്ലെങ്കിൽ
    {   VT_LDOUBLE, 16, DW_ATE_float, "long double:t16=r1;16;0;" },
#endif
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
#എങ്കിൽ LONG_SIZE == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#അല്ലെങ്കിൽ
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#endif
};

#define	N_DEFAULT_DEBUG	(വലുപ്പം (default_debug) / വലുപ്പം (default_debug[0]))

/* dwarf debug */

#define	DWARF_വരി_BASE				-5
#define	DWARF_വരി_RANGE			14
#define	DWARF_OPCODE_BASE			13

#എങ്കിൽ defined TCC_TARGET_ARM64
#define	DWARF_MIN_INSTR_LEN			4
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM
#define	DWARF_MIN_INSTR_LEN			2
#അല്ലെങ്കിൽ
#define	DWARF_MIN_INSTR_LEN			1
#endif

#define	DWARF_ABBREV_COMPILE_UNIT		1
#define	DWARF_ABBREV_BASE_TYPE			2
#define	DWARF_ABBREV_VARIABLE_EXTERNAL		3
#define	DWARF_ABBREV_VARIABLE_STATIC		4
#define	DWARF_ABBREV_VARIABLE_LOCAL		5
#define	DWARF_ABBREV_FORMAL_PARAMETER		6
#define	DWARF_ABBREV_POINTER			7
#define	DWARF_ABBREV_ARRAY_TYPE			8
#define	DWARF_ABBREV_SUBRANGE_TYPE		9
#define	DWARF_ABBREV_TYPEDEF			10
#define	DWARF_ABBREV_ENUMERATOR_SIGNED		11
#define	DWARF_ABBREV_ENUMERATOR_UNSIGNED	12
#define	DWARF_ABBREV_ENUMERATION_TYPE		13
#define	DWARF_ABBREV_MEMBER			14
#define	DWARF_ABBREV_MEMBER_BF			15
#define	DWARF_ABBREV_STRUCTURE_TYPE		16
#define	DWARF_ABBREV_STRUCTURE_EMPTY_TYPE	17
#define	DWARF_ABBREV_UNION_TYPE			18
#define	DWARF_ABBREV_UNION_EMPTY_TYPE		19
#define	DWARF_ABBREV_SUBPROGRAM_EXTERNAL	20
#define	DWARF_ABBREV_SUBPROGRAM_STATIC		21
#define	DWARF_ABBREV_LEXICAL_BLOCK		22
#define	DWARF_ABBREV_LEXICAL_EMPTY_BLOCK	23
#define	DWARF_ABBREV_SUBROUTINE_TYPE		24
#define	DWARF_ABBREV_SUBROUTINE_EMPTY_TYPE	25
#define	DWARF_ABBREV_FORMAL_PARAMETER2		26

/* all entries should have been generated with dwarf_uleb128 except
   has_children. All values are currently below 128 so this currently
   works.  */
സ്ഥിതം സ്ഥിരം unsigned അക്ഷരം dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_TAG_compile_unit, 1,
          DW_AT_producer, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_വരി_strp,
          DW_AT_comp_dir, DW_FORM_വരി_strp,
          DW_AT_താഴെയുള്ള_pc, DW_FORM_addr,
#എങ്കിൽ PTR_SIZE == 4
          DW_AT_മുകളിലെ_pc, DW_FORM_data4,
#അല്ലെങ്കിൽ
          DW_AT_മുകളിലെ_pc, DW_FORM_data8,
#endif
          DW_AT_stmt_list, DW_FORM_sec_offset,
          0, 0,
    DWARF_ABBREV_BASE_TYPE, DW_TAG_base_type, 0,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_name, DW_FORM_strp,
          0, 0,
    DWARF_ABBREV_VARIABLE_EXTERNAL, DW_TAG_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_വരി, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_TAG_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_വരി, DW_FORM_udata,
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
          DW_AT_byte_size, DW_FORM_data1,
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
          DW_AT_decl_വരി, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_TAG_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_മൂല്യം, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_TAG_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_മൂല്യം, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_TAG_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_size, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_വരി, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_വരി, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_data_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_വരി, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_bit_size, DW_FORM_udata,
          DW_AT_data_bit_offset, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_TAG_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_വരി, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_EMPTY_TYPE, DW_TAG_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_വരി, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_TAG_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_വരി, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_EMPTY_TYPE, DW_TAG_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_വരി, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_TAG_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_വരി, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_താഴെയുള്ള_pc, DW_FORM_addr,
#എങ്കിൽ PTR_SIZE == 4
          DW_AT_മുകളിലെ_pc, DW_FORM_data4,
#അല്ലെങ്കിൽ
          DW_AT_മുകളിലെ_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_TAG_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_വരി, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_താഴെയുള്ള_pc, DW_FORM_addr,
#എങ്കിൽ PTR_SIZE == 4
          DW_AT_മുകളിലെ_pc, DW_FORM_data4,
#അല്ലെങ്കിൽ
          DW_AT_മുകളിലെ_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_BLOCK, DW_TAG_lexical_block, 1,
          DW_AT_താഴെയുള്ള_pc, DW_FORM_addr,
#എങ്കിൽ PTR_SIZE == 4
          DW_AT_മുകളിലെ_pc, DW_FORM_data4,
#അല്ലെങ്കിൽ
          DW_AT_മുകളിലെ_pc, DW_FORM_data8,
#endif
          0, 0,
    DWARF_ABBREV_LEXICAL_EMPTY_BLOCK, DW_TAG_lexical_block, 0,
          DW_AT_താഴെയുള്ള_pc, DW_FORM_addr,
#എങ്കിൽ PTR_SIZE == 4
          DW_AT_മുകളിലെ_pc, DW_FORM_data4,
#അല്ലെങ്കിൽ
          DW_AT_മുകളിലെ_pc, DW_FORM_data8,
#endif
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

സ്ഥിതം സ്ഥിരം unsigned അക്ഷരം dwarf_വരി_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#define N_STR_HASH (251)

ഘടന dwarf_str_hash {
    പൂർണ്ണസംഖ്യ len;
    unsigned long data_offset;
    ഘടന dwarf_str_hash *next;
};

ഘടന _tccdbg {

    പൂർണ്ണസംഖ്യ last_വരി_അക്കം, new_file;
    പൂർണ്ണസംഖ്യ section_sym;

    പൂർണ്ണസംഖ്യ debug_next_type;

    ഘടന _debug_hash {
        പൂർണ്ണസംഖ്യ debug_type;
        Sym *type;
    } *debug_hash_global, *debug_hash_local;

    /* store forward structure/unions types */
    ഘടന _debug_forw_hash {
        Sym *type;
        പൂർണ്ണസംഖ്യ n_debug_type;
        പൂർണ്ണസംഖ്യ *debug_type;
    } *debug_forw_hash_global, *debug_forw_hash_local;

    പൂർണ്ണസംഖ്യ n_debug_hash_global;
    പൂർണ്ണസംഖ്യ n_debug_hash_local;
    പൂർണ്ണസംഖ്യ n_debug_forw_hash_global;
    പൂർണ്ണസംഖ്യ n_debug_forw_hash_local;

    ഘടന _debug_info {
        പൂർണ്ണസംഖ്യ start;
        പൂർണ്ണസംഖ്യ end;
        പൂർണ്ണസംഖ്യ last_debug_hash;
        പൂർണ്ണസംഖ്യ last_debug_forw_hash;
        പൂർണ്ണസംഖ്യ n_sym;
        ഘടന debug_sym {
            പൂർണ്ണസംഖ്യ type;
            unsigned long മൂല്യം;
            അക്ഷരം *str;
            Section *sec;
            പൂർണ്ണസംഖ്യ sym_index;
            പൂർണ്ണസംഖ്യ info;
            പൂർണ്ണസംഖ്യ file;
            പൂർണ്ണസംഖ്യ വരി;
        } *sym;
        ഘടന _debug_info *child, *next, *last, *parent;
    } *debug_info, *debug_info_വേര്;

    ഘടന {
        പൂർണ്ണസംഖ്യ info;
        പൂർണ്ണസംഖ്യ abbrev;
        പൂർണ്ണസംഖ്യ വരി;
        പൂർണ്ണസംഖ്യ str;
        പൂർണ്ണസംഖ്യ വരി_str;
    } dwarf_sym;

    ഘടന {
        പൂർണ്ണസംഖ്യ start;
        പൂർണ്ണസംഖ്യ dir_size;
        അക്ഷരം **dir_table;
        പൂർണ്ണസംഖ്യ filename_size;
        ഘടന dwarf_filename_struct {
            പൂർണ്ണസംഖ്യ dir_entry;
            അക്ഷരം *name;
        } *filename_table;
        പൂർണ്ണസംഖ്യ വരി_size;
        പൂർണ്ണസംഖ്യ വരി_max_size;
        unsigned അക്ഷരം *വരി_data;
        പൂർണ്ണസംഖ്യ cur_file;
        പൂർണ്ണസംഖ്യ last_file;
        പൂർണ്ണസംഖ്യ last_pc;
        പൂർണ്ണസംഖ്യ last_വരി;
    } dwarf_വരി;

    ഘടന {
        പൂർണ്ണസംഖ്യ start;
        Sym *func;
        പൂർണ്ണസംഖ്യ വരി;
        പൂർണ്ണസംഖ്യ base_type_used[N_DEFAULT_DEBUG];
    } dwarf_info;

    ഘടന dwarf_str_hash *dwarf_str[N_STR_HASH];
    ഘടന dwarf_str_hash *dwarf_വരി_str[N_STR_HASH];

    /* test coverage */
    ഘടന {
        unsigned long offset;
        unsigned long last_file_name;
        unsigned long last_func_name;
        പൂർണ്ണസംഖ്യ ind;
        പൂർണ്ണസംഖ്യ വരി;
    } tcov_data;
};

#define last_വരി_അക്കം             s1->dState->last_വരി_അക്കം
#define new_file                  s1->dState->new_file
#define section_sym               s1->dState->section_sym
#define debug_next_type           s1->dState->debug_next_type
#define debug_hash_global         s1->dState->debug_hash_global
#define debug_hash_local          s1->dState->debug_hash_local
#define debug_forw_hash_global    s1->dState->debug_forw_hash_global
#define debug_forw_hash_local     s1->dState->debug_forw_hash_local
#define n_debug_hash_global       s1->dState->n_debug_hash_global
#define n_debug_hash_local        s1->dState->n_debug_hash_local
#define n_debug_forw_hash_global  s1->dState->n_debug_forw_hash_global
#define n_debug_forw_hash_local   s1->dState->n_debug_forw_hash_local
#define debug_info                s1->dState->debug_info
#define debug_info_വേര്           s1->dState->debug_info_വേര്
#define dwarf_sym                 s1->dState->dwarf_sym
#define dwarf_വരി                s1->dState->dwarf_വരി
#define dwarf_info                s1->dState->dwarf_info
#define dwarf_str                 s1->dState->dwarf_str
#define dwarf_വരി_str            s1->dState->dwarf_വരി_str
#define tcov_data                 s1->dState->tcov_data

#define	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
സ്ഥിതം പൂർണ്ണസംഖ്യ put_stabs(TCCState *s1, സ്ഥിരം അക്ഷരം *str, പൂർണ്ണസംഖ്യ type, പൂർണ്ണസംഖ്യ other,
    പൂർണ്ണസംഖ്യ desc, unsigned long മൂല്യം);

ST_FUNC ശൂന്യം tcc_debug_new(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ shf = 0;
    എങ്കിൽ (!s1->dState)
        s1->dState = tcc_mallocz(വലുപ്പം *s1->dState);

#ifdef CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    എങ്കിൽ (s1->do_debug && s1->output_type == TCC_OUTPUT_MEMORY)
        s1->do_backtrace = 1;
    എങ്കിൽ (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#endif

    എങ്കിൽ (s1->dwarf) {
	പൂർണ്ണസംഖ്യ i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	സ്ഥിതം സ്ഥിരം അക്ഷരം *സ്ഥിരം debug[] = {
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
        dwarf_വരി_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	വേണ്ടി (i = 0; i < വലുപ്പം(debug)/വലുപ്പം(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_MERGE | SHF_STRINGS;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_വരി_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	എങ്കിൽ (s1->dwarf >= 5) {
            dwarf_വരി_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_വരി_str_section->sh_entsize = 1;
	    dwarf_വരി_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    അല്ലെങ്കിൽ
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = വലുപ്പം(Stab_Sym);
        stab_section->sh_addralign = വലുപ്പം ((Stab_Sym*)0)->n_മൂല്യം;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
സ്ഥിതം പൂർണ്ണസംഖ്യ put_stabs(TCCState *s1, സ്ഥിരം അക്ഷരം *str, പൂർണ്ണസംഖ്യ type, പൂർണ്ണസംഖ്യ other, പൂർണ്ണസംഖ്യ desc,
                      unsigned long മൂല്യം)
{
    Stab_Sym *sym;

    unsigned offset;
    എങ്കിൽ (type == N_SLINE
        && (offset = stab_section->data_offset)
        && (sym = (Stab_Sym*)(stab_section->data + offset) - 1)
        && sym->n_type == type
        && sym->n_മൂല്യം == മൂല്യം) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        തിരികെ 0;
    }

    sym = section_ptr_add(stab_section, വലുപ്പം(Stab_Sym));
    എങ്കിൽ (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } അല്ലെങ്കിൽ {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_മൂല്യം = മൂല്യം;
    തിരികെ 1;
}

സ്ഥിതം ശൂന്യം put_stabs_r(TCCState *s1, സ്ഥിരം അക്ഷരം *str, പൂർണ്ണസംഖ്യ type, പൂർണ്ണസംഖ്യ other, പൂർണ്ണസംഖ്യ desc,
                        unsigned long മൂല്യം, Section *sec, പൂർണ്ണസംഖ്യ sym_index)
{
    എങ്കിൽ (put_stabs(s1, str, type, other, desc, മൂല്യം))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->data_offset - 4,
                      വലുപ്പം ((Stab_Sym*)0)->n_മൂല്യം == PTR_SIZE ? R_DATA_PTR : R_DATA_32,
                      sym_index);
}

സ്ഥിതം ശൂന്യം put_stabn(TCCState *s1, പൂർണ്ണസംഖ്യ type, പൂർണ്ണസംഖ്യ other, പൂർണ്ണസംഖ്യ desc, പൂർണ്ണസംഖ്യ മൂല്യം)
{
    put_stabs(s1, ശൂന്യ, type, other, desc, മൂല്യം);
}

/* ------------------------------------------------------------------------- */
#define	dwarf_data1(s,data) \
	(*(uint8_t*)section_ptr_add((s), 1) = (data))
#define	dwarf_data2(s,data) \
	write16le(section_ptr_add((s), 2), (data))
#define	dwarf_data4(s,data) \
	write32le(section_ptr_add((s), 4), (data))
#define	dwarf_data8(s,data) \
	write64le(section_ptr_add((s), 8), (data))

സ്ഥിതം പൂർണ്ണസംഖ്യ dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    തിരികെ put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_അക്കം, ശൂന്യ);
}

സ്ഥിതം ശൂന്യം dwarf_reloc(Section *s, പൂർണ്ണസംഖ്യ sym, പൂർണ്ണസംഖ്യ rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->data_offset, rel, sym, 0);
}

സ്ഥിതം ശൂന്യം free_str(ഘടന dwarf_str_hash **str)
{
    പൂർണ്ണസംഖ്യ i;

    വേണ്ടി (i = 0; i < N_STR_HASH; i++) {
       ആകുമ്പോൾ (str[i]) {
           ഘടന dwarf_str_hash *next = str[i]->next;

           tcc_free(str[i]);
           str[i] = next;
       }
    }
}

സ്ഥിതം unsigned str_hash(സ്ഥിരം അക്ഷരം *s)
{
    unsigned h = 5381;

    ആകുമ്പോൾ (*s)
       h += (*s++ & 0xffu) + h * 31;
    തിരികെ h;
}

സ്ഥിതം ശൂന്യം dwarf_string(Section *s, Section *dw, പൂർണ്ണസംഖ്യ sym, സ്ഥിരം അക്ഷരം *str)
{
    TCCState *s1 = s->s1;
    പൂർണ്ണസംഖ്യ len, hash = str_hash(str) % N_STR_HASH;
    അക്ഷരം *ptr;
    ഘടന dwarf_str_hash *new_hash;
    ഘടന dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_വരി_str;

    len = strlen(str) + 1;
    new_hash = dw_hash[hash];
    ആകുമ്പോൾ (new_hash) {
	എങ്കിൽ (new_hash->len == len &&
	    !memcmp(str, dw->data + new_hash->data_offset, len))
	    നിർത്തുക;
	new_hash = new_hash->next;
    }
    എങ്കിൽ (new_hash == ശൂന്യ) {
	unsigned long offset = dw->data_offset;

        new_hash = dw_hash[hash];
        ആകുമ്പോൾ (new_hash) {
	    unsigned long n = new_hash->data_offset + new_hash->len - len;

	    എങ്കിൽ (new_hash->len > len &&
	        !memcmp(str, dw->data + n, len)) {
		offset = n;
		നിർത്തുക;
	    }
	    new_hash = new_hash->next;
        }
	എങ്കിൽ (new_hash == ശൂന്യ) {
	    ptr = section_ptr_add(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (ഘടന dwarf_str_hash *)
	    tcc_malloc(വലുപ്പം(ഘടന dwarf_str_hash));
	new_hash->len = len;
	new_hash->data_offset = offset;
	new_hash->next = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->data_offset, R_DATA_32DW, sym,
                   PTR_SIZE == 4 ? 0 : new_hash->data_offset);
    dwarf_data4(s, PTR_SIZE == 4 ? new_hash->data_offset : 0);
}

സ്ഥിതം ശൂന്യം dwarf_strp(Section *s, സ്ഥിരം അക്ഷരം *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

സ്ഥിതം ശൂന്യം dwarf_വരി_strp(Section *s, സ്ഥിരം അക്ഷരം *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_വരി_str_section, dwarf_sym.വരി_str, str);
}

സ്ഥിതം ശൂന്യം dwarf_വരി_op(TCCState *s1, unsigned അക്ഷരം op)
{
    എങ്കിൽ (dwarf_വരി.വരി_size >= dwarf_വരി.വരി_max_size) {
	dwarf_വരി.വരി_max_size += 1024;
	dwarf_വരി.വരി_data =
	    (unsigned അക്ഷരം *)tcc_realloc(dwarf_വരി.വരി_data,
					 dwarf_വരി.വരി_max_size);
    }
    dwarf_വരി.വരി_data[dwarf_വരി.വരി_size++] = op;
}

സ്ഥിതം ശൂന്യം dwarf_file(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ i, j;
    അക്ഷരം *filename;
    പൂർണ്ണസംഖ്യ index_offset = s1->dwarf < 5;

    എങ്കിൽ (!strcmp(file->filename, "<command line>")) {
        dwarf_വരി.cur_file = 1;
	തിരികെ;
    }
    filename = strrchr(file->filename, '/');
    എങ്കിൽ (filename == ശൂന്യ) {
        വേണ്ടി (i = 1; i < dwarf_വരി.filename_size; i++)
            എങ്കിൽ (dwarf_വരി.filename_table[i].dir_entry == 0 &&
		strcmp(dwarf_വരി.filename_table[i].name,
		       file->filename) == 0) {
		    dwarf_വരി.cur_file = i + index_offset;
	            തിരികെ;
		}
	i = -index_offset;
	filename = file->filename;
    }
    അല്ലെങ്കിൽ {
	അക്ഷരം *undo = filename;
	അക്ഷരം *dir = file->filename;

	*filename++ = '\0';
        വേണ്ടി (i = 0; i < dwarf_വരി.dir_size; i++)
	    എങ്കിൽ (strcmp(dwarf_വരി.dir_table[i], dir) == 0) {
		വേണ്ടി (j = 1; j < dwarf_വരി.filename_size; j++)
		    എങ്കിൽ (dwarf_വരി.filename_table[j].dir_entry - index_offset
			== i &&
			strcmp(dwarf_വരി.filename_table[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_വരി.cur_file = j + index_offset;
			തിരികെ;
		    }
		നിർത്തുക;
	    }
	എങ്കിൽ (i == dwarf_വരി.dir_size) {
	    dwarf_വരി.dir_size++;
	    dwarf_വരി.dir_table =
                (അക്ഷരം **) tcc_realloc(dwarf_വരി.dir_table,
                                      dwarf_വരി.dir_size *
                                      വലുപ്പം (അക്ഷരം *));
            dwarf_വരി.dir_table[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_വരി.filename_table =
        (ഘടന dwarf_filename_struct *)
        tcc_realloc(dwarf_വരി.filename_table,
                    (dwarf_വരി.filename_size + 1) *
                    വലുപ്പം (ഘടന dwarf_filename_struct));
    dwarf_വരി.filename_table[dwarf_വരി.filename_size].dir_entry =
	i + index_offset;
    dwarf_വരി.filename_table[dwarf_വരി.filename_size].name =
        tcc_strdup(filename);
    dwarf_വരി.cur_file = dwarf_വരി.filename_size++ + index_offset;
    തിരികെ;
}

#എങ്കിൽ 0
സ്ഥിതം പൂർണ്ണസംഖ്യ dwarf_uleb128_size (unsigned long long മൂല്യം)
{
    പൂർണ്ണസംഖ്യ size =  0;

    ചെയ്യുക {
        മൂല്യം >>= 7;
        size++;
    } ആകുമ്പോൾ (മൂല്യം != 0);
    തിരികെ size;
}
#endif

സ്ഥിതം പൂർണ്ണസംഖ്യ dwarf_sleb128_size (long long മൂല്യം)
{
    പൂർണ്ണസംഖ്യ size =  0;
    long long end = മൂല്യം >> 63;
    unsigned അക്ഷരം last = end & 0x40;
    unsigned അക്ഷരം byte;

    ചെയ്യുക {
        byte = മൂല്യം & 0x7f;
        മൂല്യം >>= 7;
        size++;
    } ആകുമ്പോൾ (മൂല്യം != end || (byte & 0x40) != last);
    തിരികെ size;
}

സ്ഥിതം ശൂന്യം dwarf_uleb128 (Section *s, unsigned long long മൂല്യം)
{
    ചെയ്യുക {
        unsigned അക്ഷരം byte = മൂല്യം & 0x7f;

        മൂല്യം >>= 7;
        dwarf_data1(s, byte | (മൂല്യം ? 0x80 : 0));
    } ആകുമ്പോൾ (മൂല്യം != 0);
}

സ്ഥിതം ശൂന്യം dwarf_sleb128 (Section *s, long long മൂല്യം)
{
    പൂർണ്ണസംഖ്യ more;
    long long end = മൂല്യം >> 63;
    unsigned അക്ഷരം last = end & 0x40;

    ചെയ്യുക {
        unsigned അക്ഷരം byte = മൂല്യം & 0x7f;

        മൂല്യം >>= 7;
	more = മൂല്യം != end || (byte & 0x40) != last;
        dwarf_data1(s, byte | (0x80 * more));
    } ആകുമ്പോൾ (more);
}

സ്ഥിതം ശൂന്യം dwarf_uleb128_op (TCCState *s1, unsigned long long മൂല്യം)
{
    ചെയ്യുക {
        unsigned അക്ഷരം byte = മൂല്യം & 0x7f;

        മൂല്യം >>= 7;
        dwarf_വരി_op(s1, byte | (മൂല്യം ? 0x80 : 0));
    } ആകുമ്പോൾ (മൂല്യം != 0);
}

സ്ഥിതം ശൂന്യം dwarf_sleb128_op (TCCState *s1, long long മൂല്യം)
{
    പൂർണ്ണസംഖ്യ more;
    long long end = മൂല്യം >> 63;
    unsigned അക്ഷരം last = end & 0x40;

    ചെയ്യുക {
        unsigned അക്ഷരം byte = മൂല്യം & 0x7f;

        മൂല്യം >>= 7;
        more = മൂല്യം != end || (byte & 0x40) != last;
        dwarf_വരി_op(s1, byte | (0x80 * more));
    } ആകുമ്പോൾ (more);
}

#എങ്കിൽ TCC_EH_FRAME
ST_FUNC ശൂന്യം tcc_eh_frame_start(TCCState *s1)
{
    എങ്കിൽ (!s1->unwind_tables)
        തിരികെ;
    eh_frame_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section, 0); // CIE ID
    dwarf_data1(eh_frame_section, 1); // Version
    dwarf_data1(eh_frame_section, 'z'); // Augmentation String
    dwarf_data1(eh_frame_section, 'R');
    dwarf_data1(eh_frame_section, 0);
#എങ്കിൽ defined TCC_TARGET_I386
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
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_X86_64
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
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM
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
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
    dwarf_uleb128(eh_frame_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 30); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 31); // x31 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_RISCV64
    eh_frame_section->data[s1->eh_start + 8] = 3; // version = 3
    dwarf_uleb128(eh_frame_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 1); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 2); // r2 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#endif
    ആകുമ്പോൾ ((eh_frame_section->data_offset - s1->eh_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + s1->eh_start, // length
	      eh_frame_section->data_offset - s1->eh_start - 4);
}

സ്ഥിതം ശൂന്യം tcc_debug_frame_end(TCCState *s1, പൂർണ്ണസംഖ്യ size)
{
    പൂർണ്ണസംഖ്യ eh_section_sym;
    unsigned long fde_start;

    എങ്കിൽ (!eh_frame_section)
	തിരികെ;
    eh_section_sym = dwarf_get_section_sym(text_section);
    fde_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section,
		fde_start - s1->eh_start + 4); // CIE Pointer
#എങ്കിൽ defined TCC_TARGET_I386
    dwarf_reloc(eh_frame_section, eh_section_sym, R_386_PC32);
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_X86_64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_X86_64_PC32);
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM
    dwarf_reloc(eh_frame_section, eh_section_sym, R_ARM_REL32);
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_AARCH64_PREL32);
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_RISCV64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_RISCV_32_PCREL);
#endif
    dwarf_data4(eh_frame_section, func_ind); // PC Begin
    dwarf_data4(eh_frame_section, size); // PC Range
    dwarf_data1(eh_frame_section, 0); // Augmentation Length
#എങ്കിൽ defined TCC_TARGET_I386
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 8);
    dwarf_data1(eh_frame_section, DW_CFA_offset + 5); // r5 (ebp)
    dwarf_uleb128(eh_frame_section, 2); // cfa-8
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_register);
    dwarf_uleb128(eh_frame_section, 5); // r5 (ebp)
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_frame_section, size - 5);
    dwarf_data1(eh_frame_section, DW_CFA_restore + 5); // r5 (ebp)
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 4); // r4 (esp)
    dwarf_uleb128(eh_frame_section, 4); // ofs 4
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_X86_64
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 16);
    dwarf_data1(eh_frame_section, DW_CFA_offset + 6); // r6 (rbp)
    dwarf_uleb128(eh_frame_section, 2); // cfa-16
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_register);
    dwarf_uleb128(eh_frame_section, 6); // r6 (rbp)
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_frame_section, size - 5);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_frame_section, 8); // ofs 8
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM
    /* TODO */
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 8);
    dwarf_data1(eh_frame_section, DW_CFA_offset + 14); // r14 (lr)
    dwarf_uleb128(eh_frame_section, 1);
    dwarf_data1(eh_frame_section, DW_CFA_offset + 11); // r11 (fp)
    dwarf_uleb128(eh_frame_section, 2);
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_frame_section, size / 2 - 5);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_register);
    dwarf_uleb128(eh_frame_section, 11); // r11 (fp)
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
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
    dwarf_data4(eh_frame_section, size / 4 - 5);
    dwarf_data1(eh_frame_section, DW_CFA_restore + 30); // x30 (lr)
    dwarf_data1(eh_frame_section, DW_CFA_restore + 29); // x29 (fp)
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 0);
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_RISCV64
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
    ആകുമ്പോൾ (size >= 4 &&
	   read32le(cur_text_section->data + func_ind + size - 4) != 0x00008067)
	size -= 4;
    dwarf_data4(eh_frame_section, size - 36);
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
#endif
    ആകുമ്പോൾ ((eh_frame_section->data_offset - fde_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + fde_start, // length
	      eh_frame_section->data_offset - fde_start - 4);
}

ST_FUNC ശൂന്യം tcc_eh_frame_end(TCCState *s1)
{
    എങ്കിൽ (!eh_frame_section)
	തിരികെ;
    dwarf_data4(eh_frame_section, 0);
}

ഘടന eh_തിരയൽ_table {
    uint32_t pc_offset;
    uint32_t fde_offset;
};

സ്ഥിതം പൂർണ്ണസംഖ്യ sort_eh_table(സ്ഥിരം ശൂന്യം *a, സ്ഥിരം ശൂന്യം *b)
{
    uint32_t pc1 = ((സ്ഥിരം ഘടന eh_തിരയൽ_table *)a)->pc_offset;
    uint32_t pc2 = ((സ്ഥിരം ഘടന eh_തിരയൽ_table *)b)->pc_offset;

    തിരികെ pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC ശൂന്യം tcc_eh_frame_hdr(TCCState *s1, പൂർണ്ണസംഖ്യ final)
{
    പൂർണ്ണസംഖ്യ എണ്ണം_2 = 0, offset;
    unsigned long എണ്ണം_offset, tab_offset;
    unsigned അക്ഷരം *ln, *end;
    unsigned പൂർണ്ണസംഖ്യ last_cie_offset = 0xffffffff;

    എങ്കിൽ (!eh_frame_section || !eh_frame_section->data_offset)
	തിരികെ;
    എങ്കിൽ (final && !eh_frame_hdr_section)
	തിരികെ;
    എങ്കിൽ (final == 0)
        eh_frame_hdr_section =
	    new_section(s1, ".eh_frame_hdr", SHT_PROGBITS, SHF_ALLOC);
    eh_frame_hdr_section->data_offset = 0;
    dwarf_data1(eh_frame_hdr_section, 1); // Version
    // Pointer Encoding Format
    dwarf_data1(eh_frame_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_pcrel);
    // Count Encoding Format
    dwarf_data1(eh_frame_hdr_section, DW_EH_PE_udata4 | DW_EH_PE_absptr);
    // Table Encoding Format
    dwarf_data1(eh_frame_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_datarel);
    offset = eh_frame_section->sh_addr -
             eh_frame_hdr_section->sh_addr -
             eh_frame_hdr_section->data_offset;
    dwarf_data4(eh_frame_hdr_section, offset); // eh_frame_ptr
    //എണ്ണം
    എണ്ണം_offset = eh_frame_hdr_section->data_offset;
    dwarf_data4(eh_frame_hdr_section, 0);
    tab_offset = eh_frame_hdr_section->data_offset;
    ln = eh_frame_section->data;
    end = eh_frame_section->data + eh_frame_section->data_offset;
    ആകുമ്പോൾ (ln < end) {
	unsigned അക്ഷരം *fde = ln, *rd = ln;
	unsigned പൂർണ്ണസംഖ്യ cie_offset, version, length = dwarf_read_4(rd, end);
	unsigned പൂർണ്ണസംഖ്യ pc_offset, fde_offset;

	എങ്കിൽ (length == 0)
	    പോകുക next;
        cie_offset = dwarf_read_4(rd, end);
	എങ്കിൽ (cie_offset == 0)
	    പോകുക next;
	എങ്കിൽ (cie_offset != last_cie_offset) {
	    unsigned അക്ഷരം *cie = rd - cie_offset + 4;

	    എങ്കിൽ (cie < eh_frame_section->data)
		പോകുക next;
	    version = dwarf_read_1(cie, end);
	    എങ്കിൽ ((version == 1 || version == 3) &&
	        dwarf_read_1(cie, end) == 'z' && // Augmentation String
		dwarf_read_1(cie, end) == 'R' &&
		dwarf_read_1(cie, end) == 0) {
	        dwarf_read_uleb128(&cie, end); // code_alignment_factor
	        dwarf_read_sleb128(&cie, end); // data_alignment_factor
		dwarf_read_1(cie, end); // return address column
		എങ്കിൽ (dwarf_read_uleb128(&cie, end) == 1 &&
		    dwarf_read_1(cie, end) == FDE_ENCODING) {
		    last_cie_offset = cie_offset;
		}
		അല്ലെങ്കിൽ
		    പോകുക next;
	    }
	    അല്ലെങ്കിൽ
		പോകുക next;
	}
	എണ്ണം_2++;
	fde_offset = eh_frame_section->sh_addr +
		     (fde - eh_frame_section->data) -
		     eh_frame_hdr_section->sh_addr;
	pc_offset = dwarf_read_4(rd, end) + fde_offset + 8;
	dwarf_data4(eh_frame_hdr_section, pc_offset);
	dwarf_data4(eh_frame_hdr_section, fde_offset);
next:
	ln += length + 4;
    }
    add32le(eh_frame_hdr_section->data + എണ്ണം_offset, എണ്ണം_2);
    qsort(eh_frame_hdr_section->data + tab_offset, എണ്ണം_2,
	  വലുപ്പം(ഘടന eh_തിരയൽ_table), sort_eh_table);
}
#endif

/* start of translation unit info */
ST_FUNC ശൂന്യം tcc_debug_start(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ i;
    അക്ഷരം buf[512];
    അക്ഷരം *filename;

    /* we might currently #include the <command-line> */
    filename = file->prev ? file->prev->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    എങ്കിൽ (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, text_section->data_offset, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            text_section->sh_അക്കം, "$a");

        new_file = last_വരി_അക്കം = 0;
        debug_next_type = N_DEFAULT_DEBUG;
        debug_hash_global = ശൂന്യ;
        debug_hash_local = ശൂന്യ;
        debug_forw_hash_global = ശൂന്യ;
        debug_forw_hash_local = ശൂന്യ;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, വലുപ്പം(buf));
#ifdef _WIN32
        normalize_slashes(buf);
#endif

        എങ്കിൽ (s1->dwarf) {
            പൂർണ്ണസംഖ്യ start_abbrev;
            unsigned അക്ഷരം *ptr;
	    അക്ഷരം *undo;

            /* dwarf_abbrev */
            start_abbrev = dwarf_abbrev_section->data_offset;
            ptr = section_ptr_add(dwarf_abbrev_section, വലുപ്പം(dwarf_abbrev_init));
            memcpy(ptr, dwarf_abbrev_init, വലുപ്പം(dwarf_abbrev_init));

            എങ്കിൽ (s1->dwarf < 5) {
    	        ആകുമ്പോൾ (*ptr) {
    	            ptr += 3;
    	            ആകുമ്പോൾ (*ptr) {
    	                എങ്കിൽ (ptr[1] == DW_FORM_വരി_strp)
    		            ptr[1] = DW_FORM_strp;
		        എങ്കിൽ (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    എങ്കിൽ  (ptr[1] == DW_FORM_sec_offset)
			         ptr[1] = DW_FORM_data4;
			    /* This code uses only size < 0x80 so these are
			       compatible. */
			    എങ്കിൽ  (ptr[1] == DW_FORM_exprloc)
			         ptr[1] = DW_FORM_block1;
			}
    	                ptr += 2;
    	            }
		    ptr += 2;
    	        }
            }

            dwarf_sym.info = dwarf_get_section_sym(dwarf_info_section);
            dwarf_sym.abbrev = dwarf_get_section_sym(dwarf_abbrev_section);
            dwarf_sym.വരി = dwarf_get_section_sym(dwarf_വരി_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            എങ്കിൽ (tcc_state->dwarf >= 5)
    	        dwarf_sym.വരി_str = dwarf_get_section_sym(dwarf_വരി_str_section);
            അല്ലെങ്കിൽ {
    	        dwarf_വരി_str_section = dwarf_str_section;
                dwarf_sym.വരി_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(text_section);

            /* dwarf_info */
            dwarf_info.start = dwarf_info_section->data_offset;
            dwarf_data4(dwarf_info_section, 0); // size
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            എങ്കിൽ (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_SIZE);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_DATA_32DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
            }
            അല്ലെങ്കിൽ {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_DATA_32DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
                dwarf_data1(dwarf_info_section, PTR_SIZE);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_VERSION);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_വരി_strp(dwarf_info_section, filename);
            dwarf_വരി_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#എങ്കിൽ PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#അല്ലെങ്കിൽ
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#endif
            dwarf_reloc(dwarf_info_section, dwarf_sym.വരി, R_DATA_32DW);
            dwarf_data4(dwarf_info_section, dwarf_വരി_section->data_offset); // stmt_list

            /* dwarf_line */
            dwarf_വരി.start = dwarf_വരി_section->data_offset;
            dwarf_data4(dwarf_വരി_section, 0); // length
            dwarf_data2(dwarf_വരി_section, s1->dwarf); // version
            എങ്കിൽ (s1->dwarf >= 5) {
                dwarf_data1(dwarf_വരി_section, PTR_SIZE); // address size
                dwarf_data1(dwarf_വരി_section, 0); // segment selector
            }
            dwarf_data4(dwarf_വരി_section, 0); // prologue Length
            dwarf_data1(dwarf_വരി_section, DWARF_MIN_INSTR_LEN);
            എങ്കിൽ (s1->dwarf >= 4)
                dwarf_data1(dwarf_വരി_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_വരി_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_വരി_section, DWARF_വരി_BASE);
            dwarf_data1(dwarf_വരി_section, DWARF_വരി_RANGE);
            dwarf_data1(dwarf_വരി_section, DWARF_OPCODE_BASE);
            ptr = section_ptr_add(dwarf_വരി_section, വലുപ്പം(dwarf_വരി_opcodes));
            memcpy(ptr, dwarf_വരി_opcodes, വലുപ്പം(dwarf_വരി_opcodes));
	    undo = strrchr(filename, '/');
	    എങ്കിൽ (undo)
		*undo = 0;
            dwarf_വരി.dir_size = 1 + (undo != ശൂന്യ);
            dwarf_വരി.dir_table = (അക്ഷരം **) tcc_malloc(വലുപ്പം (അക്ഷരം *) *
							dwarf_വരി.dir_size);
            dwarf_വരി.dir_table[0] = tcc_strdup(buf);
	    എങ്കിൽ (undo)
                dwarf_വരി.dir_table[1] = tcc_strdup(filename);
            dwarf_വരി.filename_size = 2;
            dwarf_വരി.filename_table =
    	        (ഘടന dwarf_filename_struct *)
    	        tcc_malloc(2*വലുപ്പം (ഘടന dwarf_filename_struct));
            dwarf_വരി.filename_table[0].dir_entry = 0;
	    എങ്കിൽ (undo) {
                dwarf_വരി.filename_table[0].name = tcc_strdup(undo + 1);
                dwarf_വരി.filename_table[1].dir_entry = 1;
                dwarf_വരി.filename_table[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    അല്ലെങ്കിൽ {
                dwarf_വരി.filename_table[0].name = tcc_strdup(filename);
                dwarf_വരി.filename_table[1].dir_entry = 0;
                dwarf_വരി.filename_table[1].name = tcc_strdup(filename);
	    }
            dwarf_വരി.വരി_size = dwarf_വരി.വരി_max_size = 0;
            dwarf_വരി.വരി_data = ശൂന്യ;
            dwarf_വരി.cur_file = 1;
            dwarf_വരി.last_file = 0;
            dwarf_വരി.last_pc = 0;
            dwarf_വരി.last_വരി = 1;
            dwarf_വരി_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_SIZE); // extended size
            dwarf_വരി_op(s1, DW_LNE_set_address);
            വേണ്ടി (i = 0; i < PTR_SIZE; i++)
    	        dwarf_വരി_op(s1, 0);
            memset(&dwarf_info.base_type_used, 0, വലുപ്പം(dwarf_info.base_type_used));
        }
        അല്ലെങ്കിൽ
        {
            /* file info: full path + filename */
            pstrcat(buf, വലുപ്പം(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      text_section->sh_അക്കം, ശൂന്യ);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            വേണ്ടി (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

സ്ഥിതം ശൂന്യം fix_debug_forw_hash(TCCState *s1, പൂർണ്ണസംഖ്യ global, പൂർണ്ണസംഖ്യ start);

/* put end of translation unit info */
ST_FUNC ശൂന്യം tcc_debug_end(TCCState *s1)
{

    എങ്കിൽ (!s1->do_debug || debug_next_type == 0)
        തിരികെ;

    എങ്കിൽ (debug_info_വേര്)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    എങ്കിൽ (s1->dwarf) {
	പൂർണ്ണസംഖ്യ i;
	പൂർണ്ണസംഖ്യ start_aranges;
	unsigned അക്ഷരം *ptr;
	പൂർണ്ണസംഖ്യ text_size = text_section->data_offset;

	/* dwarf_info */
	fix_debug_forw_hash(s1, 0, 0);
	fix_debug_forw_hash(s1, 1, 0);
	dwarf_data1(dwarf_info_section, 0);
	ptr = dwarf_info_section->data + dwarf_info.start;
	write32le(ptr, dwarf_info_section->data_offset - dwarf_info.start - 4);
	write32le(ptr + 25 + (s1->dwarf >= 5) + PTR_SIZE, text_size);

	/* dwarf_aranges */
	start_aranges = dwarf_aranges_section->data_offset;
	dwarf_data4(dwarf_aranges_section, 0); // size
	dwarf_data2(dwarf_aranges_section, 2); // version
	dwarf_reloc(dwarf_aranges_section, dwarf_sym.info, R_DATA_32DW);
	dwarf_data4(dwarf_aranges_section, 0); // dwarf_info
#എങ്കിൽ PTR_SIZE == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#അല്ലെങ്കിൽ
	dwarf_data1(dwarf_aranges_section, 8); // address size
#endif
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_DATA_PTR);
#എങ്കിൽ PTR_SIZE == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, text_size); // End
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#അല്ലെങ്കിൽ
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, text_size); // End
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#endif
	ptr = dwarf_aranges_section->data + start_aranges;
	write32le(ptr, dwarf_aranges_section->data_offset - start_aranges - 4);

	/* dwarf_line */
	എങ്കിൽ (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_വരി_section, 1); /* col */
	    dwarf_uleb128(dwarf_വരി_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_വരി_section, DW_FORM_വരി_strp);
	    dwarf_uleb128(dwarf_വരി_section, dwarf_വരി.dir_size);
	    വേണ്ടി (i = 0; i < dwarf_വരി.dir_size; i++)
	        dwarf_വരി_strp(dwarf_വരി_section, dwarf_വരി.dir_table[i]);
	    dwarf_data1(dwarf_വരി_section, 2); /* col */
	    dwarf_uleb128(dwarf_വരി_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_വരി_section, DW_FORM_വരി_strp);
	    dwarf_uleb128(dwarf_വരി_section, DW_LNCT_directory_index);
	    dwarf_uleb128(dwarf_വരി_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_വരി_section, dwarf_വരി.filename_size);
	    വേണ്ടി (i = 0; i < dwarf_വരി.filename_size; i++) {
	        dwarf_വരി_strp(dwarf_വരി_section,
				dwarf_വരി.filename_table[i].name);
	        dwarf_uleb128(dwarf_വരി_section,
			      dwarf_വരി.filename_table[i].dir_entry);
	    }
	}
	അല്ലെങ്കിൽ {
	    പൂർണ്ണസംഖ്യ len;

	    വേണ്ടി (i = 0; i < dwarf_വരി.dir_size; i++) {
	        len = strlen(dwarf_വരി.dir_table[i]) + 1;
	        ptr = section_ptr_add(dwarf_വരി_section, len);
	        memmove(ptr, dwarf_വരി.dir_table[i], len);
	    }
	    dwarf_data1(dwarf_വരി_section, 0); /* end dir */
	    വേണ്ടി (i = 0; i < dwarf_വരി.filename_size; i++) {
	        len = strlen(dwarf_വരി.filename_table[i].name) + 1;
	        ptr = section_ptr_add(dwarf_വരി_section, len);
	        memmove(ptr, dwarf_വരി.filename_table[i].name, len);
	        dwarf_uleb128(dwarf_വരി_section,
			      dwarf_വരി.filename_table[i].dir_entry);
	        dwarf_uleb128(dwarf_വരി_section, 0); /* time */
	        dwarf_uleb128(dwarf_വരി_section, 0); /* size */
	    }
	    dwarf_data1(dwarf_വരി_section, 0); /* end file */
	}
	വേണ്ടി (i = 0; i < dwarf_വരി.dir_size; i++)
	    tcc_free(dwarf_വരി.dir_table[i]);
	tcc_free(dwarf_വരി.dir_table);
	വേണ്ടി (i = 0; i < dwarf_വരി.filename_size; i++)
	    tcc_free(dwarf_വരി.filename_table[i].name);
	tcc_free(dwarf_വരി.filename_table);

	dwarf_വരി_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_വരി_op(s1, DW_LNE_end_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_വരി_section->data[dwarf_വരി.start + 6 + i],
		  dwarf_വരി_section->data_offset - dwarf_വരി.start - (10 + i));
	section_ptr_add(dwarf_വരി_section, 3);
	dwarf_reloc(dwarf_വരി_section, section_sym, R_DATA_PTR);
	ptr = section_ptr_add(dwarf_വരി_section, dwarf_വരി.വരി_size - 3);
	memmove(ptr - 3, dwarf_വരി.വരി_data, dwarf_വരി.വരി_size);
	tcc_free(dwarf_വരി.വരി_data);
	write32le(dwarf_വരി_section->data + dwarf_വരി.start,
		  dwarf_വരി_section->data_offset - dwarf_വരി.start - 4);
    }
    അല്ലെങ്കിൽ
    {
        put_stabs_r(s1, ശൂന്യ, N_SO, 0, 0,
                    text_section->data_offset, text_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_വരി_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_next_type = 0;
}

സ്ഥിതം BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    എങ്കിൽ (f->filename[0] == ':')
        f = f->prev;
    എങ്കിൽ (f && new_file) {
        new_file = last_വരി_അക്കം = 0;
        എങ്കിൽ (s1->dwarf)
            dwarf_file(s1);
        അല്ലെങ്കിൽ
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, text_section, section_sym);
    }
    തിരികെ f;
}

/* put alternative filename */
ST_FUNC ശൂന്യം tcc_debug_newfile(TCCState *s1)
{
    എങ്കിൽ (!s1->do_debug)
        തിരികെ;
    എങ്കിൽ (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC ശൂന്യം tcc_debug_bincl(TCCState *s1)
{
    എങ്കിൽ (!s1->do_debug)
        തിരികെ;
    എങ്കിൽ (s1->dwarf)
        dwarf_file(s1);
    അല്ലെങ്കിൽ
        put_stabs(s1, file->filename, N_BINCL, 0, 0, 0);
    new_file = 1;
}

/* end of #include */
ST_FUNC ശൂന്യം tcc_debug_eincl(TCCState *s1)
{
    എങ്കിൽ (!s1->do_debug)
        തിരികെ;
    എങ്കിൽ (s1->dwarf)
        dwarf_file(s1);
    അല്ലെങ്കിൽ
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC ശൂന്യം tcc_debug_വരി(TCCState *s1)
{
    BufferedFile *f;

    എങ്കിൽ (!s1->do_debug)
        തിരികെ;
    എങ്കിൽ (cur_text_section != text_section || nocode_wanted)
        തിരികെ;
    f = put_new_file(s1);
    എങ്കിൽ (!f)
        തിരികെ;
    എങ്കിൽ (last_വരി_അക്കം == f->വരി_അക്കം)
        തിരികെ;
    last_വരി_അക്കം = f->വരി_അക്കം;

    എങ്കിൽ (s1->dwarf) {
	പൂർണ്ണസംഖ്യ len_pc = (ind - dwarf_വരി.last_pc) / DWARF_MIN_INSTR_LEN;
	പൂർണ്ണസംഖ്യ len_വരി = f->വരി_അക്കം - dwarf_വരി.last_വരി;
	പൂർണ്ണസംഖ്യ n = len_pc * DWARF_വരി_RANGE + len_വരി + DWARF_OPCODE_BASE - DWARF_വരി_BASE;

	എങ്കിൽ (dwarf_വരി.cur_file != dwarf_വരി.last_file) {
	    dwarf_വരി.last_file = dwarf_വരി.cur_file;
	    dwarf_വരി_op(s1, DW_LNS_set_file);
	    dwarf_uleb128_op(s1, dwarf_വരി.cur_file);
	}
	എങ്കിൽ (len_pc &&
	    len_വരി >= DWARF_വരി_BASE && len_വരി <= (DWARF_OPCODE_BASE + DWARF_വരി_BASE) &&
	    n >= DWARF_OPCODE_BASE && n <= 255)
            dwarf_വരി_op(s1, n);
	അല്ലെങ്കിൽ {
	    എങ്കിൽ (len_pc) {
	        n = len_pc * DWARF_വരി_RANGE + 0 + DWARF_OPCODE_BASE - DWARF_വരി_BASE;
	        എങ്കിൽ (n >= DWARF_OPCODE_BASE && n <= 255)
                    dwarf_വരി_op(s1, n);
		അല്ലെങ്കിൽ {
	            dwarf_വരി_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    എങ്കിൽ (len_വരി) {
	        n = 0 * DWARF_വരി_RANGE + len_വരി + DWARF_OPCODE_BASE - DWARF_വരി_BASE;
	        എങ്കിൽ (len_വരി >= DWARF_വരി_BASE && len_വരി <= (DWARF_OPCODE_BASE + DWARF_വരി_BASE) &&
		    n >= DWARF_OPCODE_BASE && n <= 255)
	            dwarf_വരി_op(s1, n);
		അല്ലെങ്കിൽ {
	            dwarf_വരി_op(s1, DW_LNS_advance_വരി);
		    dwarf_sleb128_op(s1, len_വരി);
                    /* advance by nothing */
	            dwarf_വരി_op(s1, DWARF_OPCODE_BASE - DWARF_വരി_BASE);
		}
	    }
	}
	dwarf_വരി.last_pc = ind;
	dwarf_വരി.last_വരി = f->വരി_അക്കം;
    }
    അല്ലെങ്കിൽ
    {
	എങ്കിൽ (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->വരി_അക്കം, ind - func_ind);
        } അല്ലെങ്കിൽ {
            /* from tcc_assemble */
            put_stabs_r(s1, ശൂന്യ, N_SLINE, 0, f->വരി_അക്കം, ind, text_section, section_sym);
        }
    }
}

സ്ഥിതം ശൂന്യം tcc_debug_stabs (TCCState *s1, സ്ഥിരം അക്ഷരം *str, പൂർണ്ണസംഖ്യ type, unsigned long മൂല്യം,
                             Section *sec, പൂർണ്ണസംഖ്യ sym_index, പൂർണ്ണസംഖ്യ info)
{
    ഘടന debug_sym *s;

    എങ്കിൽ (debug_info) {
        debug_info->sym =
            (ഘടന debug_sym *)tcc_realloc (debug_info->sym,
                                             വലുപ്പം(ഘടന debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->മൂല്യം = മൂല്യം;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_index = sym_index;
        s->info = info;
        s->file = dwarf_വരി.cur_file;
        s->വരി = file->വരി_അക്കം;
    }
    അല്ലെങ്കിൽ എങ്കിൽ (sec)
        put_stabs_r (s1, str, type, 0, 0, മൂല്യം, sec, sym_index);
    അല്ലെങ്കിൽ
        put_stabs (s1, str, type, 0, 0, മൂല്യം);
}

സ്ഥിതം ശൂന്യം fix_debug_forw_hash(TCCState *s1, പൂർണ്ണസംഖ്യ global, പൂർണ്ണസംഖ്യ start)
{
    എങ്കിൽ (s1->dwarf) {
        പൂർണ്ണസംഖ്യ i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	ഘടന _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	വേണ്ടി (i = start; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    പൂർണ്ണസംഖ്യ pos = dwarf_info_section->data_offset;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_EMPTY_TYPE
                                             : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, ശൂന്യ));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_വരി.cur_file);
            dwarf_uleb128(dwarf_info_section, file->വരി_അക്കം);
	    വേണ്ടി (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->data +
			  hash[i].debug_type[j],
			  pos - dwarf_info.start);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC ശൂന്യം tcc_debug_stabn(TCCState *s1, പൂർണ്ണസംഖ്യ type, പൂർണ്ണസംഖ്യ മൂല്യം)
{
    എങ്കിൽ (!s1->do_debug)
        തിരികെ;
    എങ്കിൽ (type == N_LBRAC) {
        ഘടന _debug_info *info =
            (ഘടന _debug_info *) tcc_mallocz(വലുപ്പം (*info));

        info->start = മൂല്യം;
        info->last_debug_hash = n_debug_hash_local;
        info->last_debug_forw_hash = n_debug_forw_hash_local;
        info->parent = debug_info;
        എങ്കിൽ (debug_info) {
            എങ്കിൽ (debug_info->child) {
                എങ്കിൽ (debug_info->child->last)
                    debug_info->child->last->next = info;
                അല്ലെങ്കിൽ
                    debug_info->child->next = info;
                debug_info->child->last = info;
            }
            അല്ലെങ്കിൽ
                debug_info->child = info;
        }
        അല്ലെങ്കിൽ
            debug_info_വേര് = info;
        debug_info = info;
    }
    അല്ലെങ്കിൽ {
	fix_debug_forw_hash(s1, 0, debug_info->last_debug_forw_hash);
        n_debug_hash_local = debug_info->last_debug_hash;
        n_debug_forw_hash_local = debug_info->last_debug_forw_hash;
        debug_info->end = മൂല്യം;
        debug_info = debug_info->parent;
    }
}

സ്ഥിതം പൂർണ്ണസംഖ്യ check_global(Sym *t)
{
    Sym *g = local_അട്ടി;

    ആകുമ്പോൾ (g) {
	എങ്കിൽ (t == g)
	    തിരികെ 0;
	g = g->prev;
    }
    തിരികെ 1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_debug_find(TCCState *s1, Sym *t, പൂർണ്ണസംഖ്യ dwarf)
{
    പൂർണ്ണസംഖ്യ i , g = check_global(t);
    പൂർണ്ണസംഖ്യ n_hash, *n_forw_hash;
    ഘടന _debug_hash *hash;
    ഘടന _debug_forw_hash **forw_hash;

    എങ്കിൽ ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	വേണ്ടി (i = 0; i < *n_forw_hash; i++)
            എങ്കിൽ (t == (*forw_hash)[i].type)
		തിരികെ 0;
	*forw_hash = (ഘടന _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * വലുപ്പം(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = ശൂന്യ;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	തിരികെ 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    വേണ്ടി (i = 0; i < n_hash; i++)
        എങ്കിൽ (t == hash[i].type)
	    തിരികെ hash[i].debug_type;
    തിരികെ -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_get_dwarf_info(TCCState *s1, Sym *s);

സ്ഥിതം ശൂന്യം tcc_debug_check_forw(TCCState *s1, Sym *t, പൂർണ്ണസംഖ്യ debug_type)
{
    എങ്കിൽ ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        പൂർണ്ണസംഖ്യ i, j, g = check_global(t);
        പൂർണ്ണസംഖ്യ n_forw_hash;
        ഘടന _debug_forw_hash **forw_hash;

	വേണ്ടി (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    വേണ്ടി (j = 0; j < n_forw_hash; j++)
                എങ്കിൽ (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * വലുപ്പം(പൂർണ്ണസംഖ്യ));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    തിരികെ;
                }
	}
    }
}

സ്ഥിതം ശൂന്യം stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC ശൂന്യം tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    എങ്കിൽ (!(s1->do_debug & 2))
	തിരികെ;
    എങ്കിൽ (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        തിരികെ;
    }
    എങ്കിൽ ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        പൂർണ്ണസംഖ്യ i, j, debug_type, g = check_global(t->ref);
        പൂർണ്ണസംഖ്യ *n_forw_hash;
        ഘടന _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	വേണ്ടി (i = 0; i < *n_forw_hash; i++)
	    എങ്കിൽ (t->ref == (*forw_hash)[i].type) {
		എങ്കിൽ (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    വേണ്ടി (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->data +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.start);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		വേണ്ടി (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_debug_add(TCCState *s1, Sym *t, പൂർണ്ണസംഖ്യ dwarf)
{
    പൂർണ്ണസംഖ്യ offset = dwarf ? dwarf_info_section->data_offset : ++debug_next_type;
    പൂർണ്ണസംഖ്യ *n_hash, g = check_global(t);
    ഘടന _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (ഘടന _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * വലുപ്പം(**hash));
    (*hash)[*n_hash].debug_type = offset;
    (*hash)[(*n_hash)++].type = t;
    തിരികെ offset;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ STRUCT_NODEBUG(Sym *s)
{
    തിരികെ
    (s->a.nodebug ||
     ((s->v & ~SYM_FIELD) >= SYM_FIRST_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

സ്ഥിതം പൂർണ്ണസംഖ്യ stabs_struct_find(TCCState *s1, Sym *t, പൂർണ്ണസംഖ്യ *p_id)
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
    എങ്കിൽ (ശൂന്യ == p_id)
        തിരികെ s && !s->r && t->c >= 0;
    എങ്കിൽ (ശൂന്യ == s) {
        /* just use global_stack always */
        s = sym_push2(&global_അട്ടി, SYM_FIELD|0x00DEBBED, 0, ++debug_next_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    എങ്കിൽ (s->r || t->c < 0) /* already defined or still incomplete */
        തിരികെ 0;
    s->r = 1;
    തിരികെ 1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ remove_type_info(പൂർണ്ണസംഖ്യ type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        എങ്കിൽ ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        എങ്കിൽ (!(type & VT_BITFIELD) && (type & VT_STRUCT_MASK) > VT_ENUM)
	    type &= ~VT_STRUCT_MASK;
	തിരികെ type;
}

സ്ഥിതം ശൂന്യം tcc_get_debug_info(TCCState *s1, Sym *s, CString *result)
{
    പൂർണ്ണസംഖ്യ type;
    പൂർണ്ണസംഖ്യ n = 0;
    പൂർണ്ണസംഖ്യ debug_type = -1;
    Sym *t = s;
    CString str;

    വേണ്ടി (;;) {
        type = remove_type_info (t->type.t);
        എങ്കിൽ (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        അല്ലെങ്കിൽ
            നിർത്തുക;
    }
    എങ്കിൽ ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        എങ്കിൽ (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, ശൂന്യ),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            ആകുമ്പോൾ (t->next) {
                പൂർണ്ണസംഖ്യ pos, size, align;
                t = t->next;
		എങ്കിൽ (STRUCT_NODEBUG(t))
		    തുടരുക;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, ശൂന്യ)
                             );
                tcc_get_debug_info (s1, t, &str);
                എങ്കിൽ (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + BIT_POS(t->type.t);
                    size = BIT_SIZE(t->type.t);
                }
                അല്ലെങ്കിൽ {
                    pos = t->c * 8;
                    size = type_size(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, size);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, ശൂന്യ, 0, 0);
            cstr_free (&str);
        }
    }
    അല്ലെങ്കിൽ എങ്കിൽ (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        എങ്കിൽ (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, ശൂന്യ),
                         debug_type);
            ആകുമ്പോൾ (t->next) {
                t = t->next;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, ശൂന്യ));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (പൂർണ്ണസംഖ്യ)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, ശൂന്യ, 0, 0);
            cstr_free (&str);
	}
    }
    അല്ലെങ്കിൽ എങ്കിൽ ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        വേണ്ടി (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            എങ്കിൽ (default_debug[debug_type - 1].type == type)
                നിർത്തുക;
        എങ്കിൽ (debug_type > N_DEFAULT_DEBUG)
            തിരികെ;
    }

    എങ്കിൽ (ശൂന്യ == result) /* from stabs_struct_complete() */
        തിരികെ;

    എങ്കിൽ (n > 0)
        cstr_printf (result, "%d=", ++debug_next_type);
    t = s;
    വേണ്ടി (;;) {
        type = remove_type_info (t->type.t);
        എങ്കിൽ (type == VT_PTR)
            cstr_printf (result, "%d=*", ++debug_next_type);
        അല്ലെങ്കിൽ എങ്കിൽ (type == (VT_PTR | VT_ARRAY))
            cstr_printf (result, "%d=ar1;0;%d;",
                         ++debug_next_type, t->type.ref->c - 1);
        അല്ലെങ്കിൽ എങ്കിൽ (type == VT_FUNC) {
            cstr_printf (result, "%d=f", ++debug_next_type);
            tcc_get_debug_info (s1, t->type.ref, result);
            തിരികെ;
        }
        അല്ലെങ്കിൽ
            നിർത്തുക;
        t = t->type.ref;
    }
    cstr_printf (result, "%d", debug_type);
}

സ്ഥിതം ശൂന്യം stabs_struct_complete(TCCState *s1, CType *t)
{
    എങ്കിൽ (stabs_struct_find(s1, t->ref, ശൂന്യ)) {
        Sym s = {0}; s.type = *t;
        tcc_get_debug_info(s1, &s, ശൂന്യ);
    }
}

സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_get_dwarf_info(TCCState *s1, Sym *s)
{
    പൂർണ്ണസംഖ്യ type;
    പൂർണ്ണസംഖ്യ debug_type = -1;
    Sym *e, *t = s;
    പൂർണ്ണസംഖ്യ i;
    പൂർണ്ണസംഖ്യ last_pos = -1;
    പൂർണ്ണസംഖ്യ retval;

    എങ്കിൽ (new_file)
        put_new_file(s1);
    വേണ്ടി (;;) {
        type = remove_type_info (t->type.t);
        എങ്കിൽ (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        അല്ലെങ്കിൽ
            നിർത്തുക;
    }
    എങ്കിൽ ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	എങ്കിൽ (debug_type == -1) {
	    പൂർണ്ണസംഖ്യ pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_add(s1, t, 1);
	    e = t;
	    i = 0;
	    ആകുമ്പോൾ (e->next) {
		e = e->next;
		എങ്കിൽ (STRUCT_NODEBUG(e))
		    തുടരുക;
		i++;
	    }
	    pos_type = (പൂർണ്ണസംഖ്യ *) tcc_malloc(i * വലുപ്പം(പൂർണ്ണസംഖ്യ));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->next ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_EMPTY_TYPE
		        : t->next ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, ശൂന്യ));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_വരി.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->വരി_അക്കം);
	    എങ്കിൽ (t->next) {
	        pos_sib = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            ആകുമ്പോൾ (e->next) {
                e = e->next;
		എങ്കിൽ (STRUCT_NODEBUG(e))
		    തുടരുക;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, ശൂന്യ));
		dwarf_uleb128(dwarf_info_section, dwarf_വരി.cur_file);
		dwarf_uleb128(dwarf_info_section, file->വരി_അക്കം);
		pos_type[i++] = dwarf_info_section->data_offset;
		dwarf_data4(dwarf_info_section, 0);
                എങ്കിൽ (e->type.t & VT_BITFIELD) {
                    പൂർണ്ണസംഖ്യ pos = e->c * 8 + BIT_POS(e->type.t);
                    പൂർണ്ണസംഖ്യ size = BIT_SIZE(e->type.t);

		    dwarf_uleb128(dwarf_info_section, size);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		അല്ലെങ്കിൽ
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    എങ്കിൽ (t->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + pos_sib,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    e = t;
	    i = 0;
	    ആകുമ്പോൾ (e->next) {
		e = e->next;
		എങ്കിൽ (STRUCT_NODEBUG(e))
		    തുടരുക;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->data + pos_type[i++],
			  type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
    }
    അല്ലെങ്കിൽ എങ്കിൽ (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	എങ്കിൽ (debug_type == -1) {
	    പൂർണ്ണസംഖ്യ pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_add(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, ശൂന്യ));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.start);
	    dwarf_uleb128(dwarf_info_section, dwarf_വരി.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->വരി_അക്കം);
	    pos_sib = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            ആകുമ്പോൾ (e->next) {
                e = e->next;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                           ? "" : get_tok_str(e->v, ശൂന്യ));
		എങ്കിൽ (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		അല്ലെങ്കിൽ
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + pos_sib,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
    }
    അല്ലെങ്കിൽ എങ്കിൽ ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        വേണ്ടി (i = 1; i <= N_DEFAULT_DEBUG; i++)
            എങ്കിൽ (default_debug[i - 1].type == type)
                നിർത്തുക;
        എങ്കിൽ (i > N_DEFAULT_DEBUG)
            തിരികെ 0;
	debug_type = dwarf_info.base_type_used[i - 1];
	എങ്കിൽ (debug_type == 0) {
	    അക്ഷരം name[100];

	    debug_type = dwarf_info_section->data_offset;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_BASE_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].size);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, വലുപ്പം name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.base_type_used[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = ശൂന്യ;
    t = s;
    വേണ്ടി (;;) {
        type = remove_type_info (t->type.t);
        എങ്കിൽ (type == VT_PTR) {
	    i = dwarf_info_section->data_offset;
	    എങ്കിൽ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_POINTER);
	    dwarf_data1(dwarf_info_section, PTR_SIZE);
	    എങ്കിൽ (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        അല്ലെങ്കിൽ എങ്കിൽ (type == (VT_PTR | VT_ARRAY)) {
	    പൂർണ്ണസംഖ്യ sib_pos, sub_type;
#എങ്കിൽ LONG_SIZE == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#അല്ലെങ്കിൽ
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#endif

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->data_offset;
	    എങ്കിൽ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    എങ്കിൽ (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    വേണ്ടി (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.start);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		എങ്കിൽ (type != (VT_PTR | VT_ARRAY))
		    നിർത്തുക;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + sib_pos,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
        അല്ലെങ്കിൽ എങ്കിൽ (type == VT_FUNC) {
	    പൂർണ്ണസംഖ്യ sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->data_offset;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    എങ്കിൽ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->next ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_EMPTY_TYPE);
	    എങ്കിൽ (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    എങ്കിൽ (t->type.ref->next) {
	        sib_pos = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    ആകുമ്പോൾ (f->next) {
		f = f->next;
		i++;
	    }
	    pos_type = (പൂർണ്ണസംഖ്യ *) tcc_malloc(i * വലുപ്പം(പൂർണ്ണസംഖ്യ));
	    f = t->type.ref;
	    i = 0;
	    ആകുമ്പോൾ (f->next) {
		f = f->next;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    എങ്കിൽ (t->type.ref->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + sib_pos,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    f = t->type.ref;
	    i = 0;
	    ആകുമ്പോൾ (f->next) {
		f = f->next;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->data + pos_type[i++],
                          type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
        അല്ലെങ്കിൽ {
	    എങ്കിൽ (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  debug_type - dwarf_info.start);
	    }
            നിർത്തുക;
	}
        t = t->type.ref;
    }
    തിരികെ retval;
}

സ്ഥിതം ശൂന്യം tcc_debug_finish (TCCState *s1, ഘടന _debug_info *cur)
{
    ആകുമ്പോൾ (cur) {
        ഘടന _debug_info *next = cur->next;
        പൂർണ്ണസംഖ്യ i;

        എങ്കിൽ (s1->dwarf) {

            വേണ്ടി (i = cur->n_sym - 1; i >= 0; i--) {
                ഘടന debug_sym *s = &cur->sym[i];

		dwarf_data1(dwarf_info_section,
                            s->type == N_PSYM
			    ? DWARF_ABBREV_FORMAL_PARAMETER
			    : s->type == N_GSYM
                            ? DWARF_ABBREV_VARIABLE_EXTERNAL
                            : s->type == N_STSYM
			    ? DWARF_ABBREV_VARIABLE_STATIC
			    : DWARF_ABBREV_VARIABLE_LOCAL);
                dwarf_strp(dwarf_info_section, s->str);
		എങ്കിൽ (s->type == N_GSYM || s->type == N_STSYM) {
                    dwarf_uleb128(dwarf_info_section, s->file);
                    dwarf_uleb128(dwarf_info_section, s->വരി);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.start);
		എങ്കിൽ (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    എങ്കിൽ (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    എങ്കിൽ (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#എങ്കിൽ PTR_SIZE == 4
                    dwarf_data4(dwarf_info_section, s->മൂല്യം);
#അല്ലെങ്കിൽ
                    dwarf_data8(dwarf_info_section, s->മൂല്യം);
#endif
		}
		അല്ലെങ്കിൽ {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_size((long)s->മൂല്യം) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (long)s->മൂല്യം);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->child ? DWARF_ABBREV_LEXICAL_BLOCK
			           : DWARF_ABBREV_LEXICAL_EMPTY_BLOCK);
            dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#എങ്കിൽ PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->start);
            dwarf_data4(dwarf_info_section, cur->end - cur->start);
#അല്ലെങ്കിൽ
            dwarf_data8(dwarf_info_section, func_ind + cur->start);
            dwarf_data8(dwarf_info_section, cur->end - cur->start);
#endif
            tcc_debug_finish (s1, cur->child);
	    എങ്കിൽ (cur->child)
                dwarf_data1(dwarf_info_section, 0);
        }
        അല്ലെങ്കിൽ
        {
            വേണ്ടി (i = 0; i < cur->n_sym; i++) {
                ഘടന debug_sym *s = &cur->sym[i];

                എങ്കിൽ (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->മൂല്യം,
                                s->sec, s->sym_index);
                അല്ലെങ്കിൽ
                    put_stabs(s1, s->str, s->type, 0, 0, s->മൂല്യം);
                tcc_free (s->str);
            }
            tcc_free (cur->sym);
            put_stabn(s1, N_LBRAC, 0, 0, cur->start);
            tcc_debug_finish (s1, cur->child);
            put_stabn(s1, N_RBRAC, 0, 0, cur->end);
        }
        tcc_free (cur);
        cur = next;
    }
}

ST_FUNC ശൂന്യം tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    പൂർണ്ണസംഖ്യ param;

    എങ്കിൽ (!(s1->do_debug & 2))
        തിരികെ;

    cstr_new (&debug_str);
    param = !e;
    വേണ്ടി (; s != e; s = s->prev) {
        എങ്കിൽ (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            തുടരുക;
	എങ്കിൽ (s1->dwarf) {
	    tcc_debug_stabs(s1, get_tok_str(s->v, ശൂന്യ),
			    param ? N_PSYM : N_LSYM, s->c, ശൂന്യ, 0,
			    tcc_get_dwarf_info(s1, s));
	}
	അല്ലെങ്കിൽ
        {
            cstr_reset (&debug_str);
            cstr_printf (&debug_str, "%s:%s", get_tok_str(s->v, ശൂന്യ),
			 param ? "p" : "");
            tcc_get_debug_info(s1, s, &debug_str);
            tcc_debug_stabs(s1, debug_str.data, param ? N_PSYM : N_LSYM,
			    s->c, ശൂന്യ, 0, 0);
	}
    }
    cstr_free (&debug_str);
}

/* put function symbol */
ST_FUNC ശൂന്യം tcc_debug_funcstart(TCCState *s1, Sym *sym)
{
    CString debug_str;
    BufferedFile *f;

    എങ്കിൽ (!s1->do_debug)
        തിരികെ;
    debug_info_വേര് = ശൂന്യ;
    debug_info = ശൂന്യ;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    എങ്കിൽ (!f)
	തിരികെ;

    എങ്കിൽ (s1->dwarf) {
        tcc_debug_വരി(s1);
        dwarf_info.func = sym;
        dwarf_info.വരി = file->വരി_അക്കം;
	എങ്കിൽ (s1->do_backtrace) {
	    പൂർണ്ണസംഖ്യ i, len;

	    dwarf_വരി_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, strlen(funcname) + 2);
	    dwarf_വരി_op(s1, DW_LNE_hi_user - 1);
	    len = strlen(funcname) + 1;
	    വേണ്ടി (i = 0; i < len; i++)
		dwarf_വരി_op(s1, funcname[i]);
	}
    }
    അല്ലെങ്കിൽ
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.data, N_FUN, 0, f->വരി_അക്കം, 0, cur_text_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_വരി(s1);
    }
}

ST_FUNC ശൂന്യം tcc_debug_prolog_epilog(TCCState *s1, പൂർണ്ണസംഖ്യ മൂല്യം)
{
    എങ്കിൽ (!s1->do_debug)
        തിരികെ;
    എങ്കിൽ (s1->dwarf) {
	dwarf_വരി_op(s1, മൂല്യം == 0 ? DW_LNS_set_prologue_end
				     : DW_LNS_set_epilogue_begin);
    }
}

/* put function size */
ST_FUNC ശൂന്യം tcc_debug_funcend(TCCState *s1, പൂർണ്ണസംഖ്യ size)
{
    /* lldb does not like function end and next function start at same pc */
    പൂർണ്ണസംഖ്യ min_instr_len;

#എങ്കിൽ TCC_EH_FRAME
    tcc_debug_frame_end(s1, size);
#endif
    എങ്കിൽ (!s1->do_debug)
        തിരികെ;
    min_instr_len = dwarf_വരി.last_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_വരി(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, size);
    എങ്കിൽ (s1->dwarf) {
        പൂർണ്ണസംഖ്യ func_sib = 0;
	Sym *sym = dwarf_info.func;
	പൂർണ്ണസംഖ്യ n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        എങ്കിൽ ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_വരി.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.വരി);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->data_offset);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.start);
        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#എങ്കിൽ PTR_SIZE == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, size); // high_pc
#അല്ലെങ്കിൽ
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, size); // high_pc
#endif
        func_sib = dwarf_info_section->data_offset;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#എങ്കിൽ defined(TCC_TARGET_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#അല്ലെങ്കിൽ
        dwarf_data1(dwarf_info_section, DW_OP_call_frame_cfa);
#endif
        tcc_debug_finish (s1, debug_info_വേര്);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->data + func_sib,
                  dwarf_info_section->data_offset - dwarf_info.start);
    }
    അല്ലെങ്കിൽ
    {
        tcc_debug_finish (s1, debug_info_വേര്);
    }
    debug_info_വേര് = 0;
}


ST_FUNC ശൂന്യം tcc_debug_extern_sym(TCCState *s1, Sym *sym, പൂർണ്ണസംഖ്യ sh_അക്കം, പൂർണ്ണസംഖ്യ sym_bind, പൂർണ്ണസംഖ്യ sym_type)
{
    എങ്കിൽ (!(s1->do_debug & 2))
        തിരികെ;

    എങ്കിൽ (sym_type == STT_FUNC || sym->v >= SYM_FIRST_ANOM)
        തിരികെ;
    എങ്കിൽ (s1->dwarf) {
        പൂർണ്ണസംഖ്യ debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, ശൂന്യ));
	dwarf_uleb128(dwarf_info_section, dwarf_വരി.cur_file);
	dwarf_uleb128(dwarf_info_section, file->വരി_അക്കം);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	എങ്കിൽ (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->data_offset,
		R_DATA_PTR, 0);
#എങ്കിൽ PTR_SIZE == 4
	dwarf_data4(dwarf_info_section, 0);
#അല്ലെങ്കിൽ
	dwarf_data8(dwarf_info_section, 0);
#endif
    }
    അല്ലെങ്കിൽ
    {
        Section *s = sh_അക്കം == SHN_COMMON ? common_section
					  : s1->sections[sh_അക്കം];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, ശൂന്യ),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        എങ്കിൽ (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.data, N_GSYM, 0, ശൂന്യ, 0, 0);
        അല്ലെങ്കിൽ
            tcc_debug_stabs(s1, str.data,
                (sym->type.t & VT_STATIC) && data_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC ശൂന്യം tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    എങ്കിൽ (!(s1->do_debug & 2))
        തിരികെ;

    എങ്കിൽ (s1->dwarf) {
	പൂർണ്ണസംഖ്യ debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	എങ്കിൽ (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, ശൂന്യ));
	    dwarf_uleb128(dwarf_info_section, dwarf_വരി.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->വരി_അക്കം);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	}
    }
    അല്ലെങ്കിൽ
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, ശൂന്യ));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.data, N_LSYM, 0, ശൂന്യ, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC ശൂന്യം tcc_tcov_block_end(TCCState *s1, പൂർണ്ണസംഖ്യ വരി);

ST_FUNC ശൂന്യം tcc_tcov_block_begin(TCCState *s1)
{
    SValue sv;
    ശൂന്യം *ptr;
    unsigned long last_offset = tcov_data.offset;

    tcc_tcov_block_end (tcc_state, 0);
    എങ്കിൽ (s1->test_coverage == 0 || nocode_wanted)
	തിരികെ;

    എങ്കിൽ (tcov_data.last_file_name == 0 ||
	strcmp ((സ്ഥിരം അക്ഷരം *)(tcov_section->data + tcov_data.last_file_name),
		file->true_filename) != 0) {
	അക്ഷരം wd[1024];
	CString cstr;

	എങ്കിൽ (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	എങ്കിൽ (tcov_data.last_file_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = 0;
	cstr_new (&cstr);
	എങ്കിൽ (file->true_filename[0] == '/') {
	    tcov_data.last_file_name = tcov_section->data_offset;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	അല്ലെങ്കിൽ {
	    getcwd (wd, വലുപ്പം(wd));
	    tcov_data.last_file_name = tcov_section->data_offset + strlen(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_add(tcov_section, cstr.size + 1);
	strcpy((അക്ഷരം *)ptr, cstr.data);
#ifdef _WIN32
        normalize_slashes((അക്ഷരം *)ptr);
#endif
	cstr_free (&cstr);
    }
    എങ്കിൽ (tcov_data.last_func_name == 0 ||
	strcmp ((സ്ഥിരം അക്ഷരം *)(tcov_section->data + tcov_data.last_func_name),
		funcname) != 0) {
	size_t len;

	എങ്കിൽ (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = tcov_section->data_offset;
	len = strlen (funcname);
	ptr = section_ptr_add(tcov_section, len + 1);
	strcpy((അക്ഷരം *)ptr, funcname);
	section_ptr_add(tcov_section, -tcov_section->data_offset & 7);
	ptr = section_ptr_add(tcov_section, 8);
	write64le (ptr, file->വരി_അക്കം);
    }
    എങ്കിൽ (ind == tcov_data.ind && tcov_data.വരി == file->വരി_അക്കം)
        tcov_data.offset = last_offset;
    അല്ലെങ്കിൽ {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_add(tcov_section, 16);
        tcov_data.വരി = file->വരി_അക്കം;
        write64le (ptr, (tcov_data.വരി << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((unsigned അക്ഷരം *)ptr - tcov_section->data) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#എങ്കിൽ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || \
    defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || \
    defined TCC_TARGET_RISCV64
        gen_increment_tcov (&sv);
#അല്ലെങ്കിൽ
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#endif
        tcov_data.offset = (unsigned അക്ഷരം *)ptr - tcov_section->data;
        tcov_data.ind = ind;
    }
}

ST_FUNC ശൂന്യം tcc_tcov_block_end(TCCState *s1, പൂർണ്ണസംഖ്യ വരി)
{
    എങ്കിൽ (s1->test_coverage == 0)
	തിരികെ;
    എങ്കിൽ (വരി == -1)
        വരി = tcov_data.വരി;
    എങ്കിൽ (tcov_data.offset) {
	ശൂന്യം *ptr = tcov_section->data + tcov_data.offset;
	unsigned long long nline = വരി ? വരി : file->വരി_അക്കം;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_data.offset = 0;
    }
}

ST_FUNC ശൂന്യം tcc_tcov_check_വരി(TCCState *s1, പൂർണ്ണസംഖ്യ start)
{
    എങ്കിൽ (s1->test_coverage == 0)
	തിരികെ;
    എങ്കിൽ (tcov_data.വരി != file->വരി_അക്കം) {
        എങ്കിൽ ((tcov_data.വരി + 1) != file->വരി_അക്കം) {
	    tcc_tcov_block_end (s1, -1);
	    എങ്കിൽ (start)
                tcc_tcov_block_begin (s1);
	}
	അല്ലെങ്കിൽ
	    tcov_data.വരി = file->വരി_അക്കം;
    }
}

ST_FUNC ശൂന്യം tcc_tcov_start(TCCState *s1)
{
    എങ്കിൽ (s1->test_coverage == 0)
	തിരികെ;
    എങ്കിൽ (!s1->dState)
        s1->dState = tcc_mallocz(വലുപ്പം *s1->dState);
    memset (&tcov_data, 0, വലുപ്പം (tcov_data));
    എങ്കിൽ (tcov_section == ശൂന്യ) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_add(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC ശൂന്യം tcc_tcov_end(TCCState *s1)
{
    എങ്കിൽ (s1->test_coverage == 0)
	തിരികെ;
    എങ്കിൽ (tcov_data.last_func_name)
        section_ptr_add(tcov_section, 1);
    എങ്കിൽ (tcov_data.last_file_name)
        section_ptr_add(tcov_section, 1);
}

ST_FUNC ശൂന്യം tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_data.ind = 0;
}

/* ------------------------------------------------------------------------- */
#undef last_വരി_അക്കം
#undef new_file
#undef section_sym
#undef debug_next_type
#undef debug_hash_global
#undef debug_hash_local
#undef n_debug_hash_global
#undef n_debug_hash_local
#undef debug_forw_hash_global
#undef debug_forw_hash_local
#undef n_debug_forw_hash_global
#undef n_debug_forw_hash_local
#undef debug_info
#undef debug_info_വേര്
#undef dwarf_sym
#undef dwarf_വരി
#undef dwarf_info
#undef dwarf_str
#undef dwarf_വരി_str
#undef tcov_data
