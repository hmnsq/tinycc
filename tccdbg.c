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

#অন্তর্ভাৱ "tcc.h"

/* stab debug support */

স্থির ধ্রুৱ সংরচনা {
  পূর্ণাঙ্ক type;
  পূর্ণাঙ্ক size;
  পূর্ণাঙ্ক encoding;
  ধ্রুৱ ৱর্ণ *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#যদি LONG_SIZE == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#অন্যথা
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#endif
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#যদি LONG_SIZE == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#অন্যথা
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
#অন্যথা
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
#যদি LONG_SIZE == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#অন্যথা
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#endif
};

#define	N_DEFAULT_DEBUG	(পরিমাণ (default_debug) / পরিমাণ (default_debug[0]))

/* dwarf debug */

#define	DWARF_সাৰি_BASE				-5
#define	DWARF_সাৰি_RANGE			14
#define	DWARF_OPCODE_BASE			13

#যদি defined TCC_TARGET_ARM64
#define	DWARF_MIN_INSTR_LEN			4
#নোচেদ্যদি defined TCC_TARGET_ARM
#define	DWARF_MIN_INSTR_LEN			2
#অন্যথা
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
স্থির ধ্রুৱ unsigned ৱর্ণ dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_TAG_compile_unit, 1,
          DW_AT_producer, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_সাৰি_strp,
          DW_AT_comp_dir, DW_FORM_সাৰি_strp,
          DW_AT_নিচেৰ_pc, DW_FORM_addr,
#যদি PTR_SIZE == 4
          DW_AT_উপৰেৰ_pc, DW_FORM_data4,
#অন্যথা
          DW_AT_উপৰেৰ_pc, DW_FORM_data8,
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
          DW_AT_decl_সাৰি, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_TAG_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সাৰি, DW_FORM_udata,
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
          DW_AT_decl_সাৰি, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_TAG_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_মান, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_TAG_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_মান, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_TAG_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_size, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সাৰি, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সাৰি, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_data_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সাৰি, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_bit_size, DW_FORM_udata,
          DW_AT_data_bit_offset, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_TAG_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সাৰি, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_EMPTY_TYPE, DW_TAG_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সাৰি, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_TAG_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সাৰি, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_EMPTY_TYPE, DW_TAG_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সাৰি, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_TAG_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সাৰি, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_নিচেৰ_pc, DW_FORM_addr,
#যদি PTR_SIZE == 4
          DW_AT_উপৰেৰ_pc, DW_FORM_data4,
#অন্যথা
          DW_AT_উপৰেৰ_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_TAG_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সাৰি, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_নিচেৰ_pc, DW_FORM_addr,
#যদি PTR_SIZE == 4
          DW_AT_উপৰেৰ_pc, DW_FORM_data4,
#অন্যথা
          DW_AT_উপৰেৰ_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_BLOCK, DW_TAG_lexical_block, 1,
          DW_AT_নিচেৰ_pc, DW_FORM_addr,
#যদি PTR_SIZE == 4
          DW_AT_উপৰেৰ_pc, DW_FORM_data4,
#অন্যথা
          DW_AT_উপৰেৰ_pc, DW_FORM_data8,
#endif
          0, 0,
    DWARF_ABBREV_LEXICAL_EMPTY_BLOCK, DW_TAG_lexical_block, 0,
          DW_AT_নিচেৰ_pc, DW_FORM_addr,
#যদি PTR_SIZE == 4
          DW_AT_উপৰেৰ_pc, DW_FORM_data4,
#অন্যথা
          DW_AT_উপৰেৰ_pc, DW_FORM_data8,
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

স্থির ধ্রুৱ unsigned ৱর্ণ dwarf_সাৰি_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#define N_STR_HASH (251)

সংরচনা dwarf_str_hash {
    পূর্ণাঙ্ক len;
    unsigned long data_offset;
    সংরচনা dwarf_str_hash *next;
};

সংরচনা _tccdbg {

    পূর্ণাঙ্ক last_সাৰি_অঙ্ক, new_file;
    পূর্ণাঙ্ক section_sym;

    পূর্ণাঙ্ক debug_next_type;

    সংরচনা _debug_hash {
        পূর্ণাঙ্ক debug_type;
        Sym *type;
    } *debug_hash_global, *debug_hash_local;

    /* store forward structure/unions types */
    সংরচনা _debug_forw_hash {
        Sym *type;
        পূর্ণাঙ্ক n_debug_type;
        পূর্ণাঙ্ক *debug_type;
    } *debug_forw_hash_global, *debug_forw_hash_local;

    পূর্ণাঙ্ক n_debug_hash_global;
    পূর্ণাঙ্ক n_debug_hash_local;
    পূর্ণাঙ্ক n_debug_forw_hash_global;
    পূর্ণাঙ্ক n_debug_forw_hash_local;

    সংরচনা _debug_info {
        পূর্ণাঙ্ক start;
        পূর্ণাঙ্ক end;
        পূর্ণাঙ্ক last_debug_hash;
        পূর্ণাঙ্ক last_debug_forw_hash;
        পূর্ণাঙ্ক n_sym;
        সংরচনা debug_sym {
            পূর্ণাঙ্ক type;
            unsigned long মান;
            ৱর্ণ *str;
            Section *sec;
            পূর্ণাঙ্ক sym_index;
            পূর্ণাঙ্ক info;
            পূর্ণাঙ্ক file;
            পূর্ণাঙ্ক সাৰি;
        } *sym;
        সংরচনা _debug_info *child, *next, *last, *parent;
    } *debug_info, *debug_info_মূল;

    সংরচনা {
        পূর্ণাঙ্ক info;
        পূর্ণাঙ্ক abbrev;
        পূর্ণাঙ্ক সাৰি;
        পূর্ণাঙ্ক str;
        পূর্ণাঙ্ক সাৰি_str;
    } dwarf_sym;

    সংরচনা {
        পূর্ণাঙ্ক start;
        পূর্ণাঙ্ক dir_size;
        ৱর্ণ **dir_table;
        পূর্ণাঙ্ক filename_size;
        সংরচনা dwarf_filename_struct {
            পূর্ণাঙ্ক dir_entry;
            ৱর্ণ *name;
        } *filename_table;
        পূর্ণাঙ্ক সাৰি_size;
        পূর্ণাঙ্ক সাৰি_max_size;
        unsigned ৱর্ণ *সাৰি_data;
        পূর্ণাঙ্ক cur_file;
        পূর্ণাঙ্ক last_file;
        পূর্ণাঙ্ক last_pc;
        পূর্ণাঙ্ক last_সাৰি;
    } dwarf_সাৰি;

    সংরচনা {
        পূর্ণাঙ্ক start;
        Sym *func;
        পূর্ণাঙ্ক সাৰি;
        পূর্ণাঙ্ক base_type_used[N_DEFAULT_DEBUG];
    } dwarf_info;

    সংরচনা dwarf_str_hash *dwarf_str[N_STR_HASH];
    সংরচনা dwarf_str_hash *dwarf_সাৰি_str[N_STR_HASH];

    /* test coverage */
    সংরচনা {
        unsigned long offset;
        unsigned long last_file_name;
        unsigned long last_func_name;
        পূর্ণাঙ্ক ind;
        পূর্ণাঙ্ক সাৰি;
    } tcov_data;
};

#define last_সাৰি_অঙ্ক             s1->dState->last_সাৰি_অঙ্ক
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
#define debug_info_মূল           s1->dState->debug_info_মূল
#define dwarf_sym                 s1->dState->dwarf_sym
#define dwarf_সাৰি                s1->dState->dwarf_সাৰি
#define dwarf_info                s1->dState->dwarf_info
#define dwarf_str                 s1->dState->dwarf_str
#define dwarf_সাৰি_str            s1->dState->dwarf_সাৰি_str
#define tcov_data                 s1->dState->tcov_data

#define	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
স্থির পূর্ণাঙ্ক put_stabs(TCCState *s1, ধ্রুৱ ৱর্ণ *str, পূর্ণাঙ্ক type, পূর্ণাঙ্ক other,
    পূর্ণাঙ্ক desc, unsigned long মান);

ST_FUNC শূন্য tcc_debug_new(TCCState *s1)
{
    পূর্ণাঙ্ক shf = 0;
    যদি (!s1->dState)
        s1->dState = tcc_mallocz(পরিমাণ *s1->dState);

#ifdef CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    যদি (s1->do_debug && s1->output_type == TCC_OUTPUT_MEMORY)
        s1->do_backtrace = 1;
    যদি (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#endif

    যদি (s1->dwarf) {
	পূর্ণাঙ্ক i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	স্থির ধ্রুৱ ৱর্ণ *ধ্রুৱ debug[] = {
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
        dwarf_সাৰি_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	বাবে (i = 0; i < পরিমাণ(debug)/পরিমাণ(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_MERGE | SHF_STRINGS;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_সাৰি_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	যদি (s1->dwarf >= 5) {
            dwarf_সাৰি_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_সাৰি_str_section->sh_entsize = 1;
	    dwarf_সাৰি_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    অন্যথা
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = পরিমাণ(Stab_Sym);
        stab_section->sh_addralign = পরিমাণ ((Stab_Sym*)0)->n_মান;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
স্থির পূর্ণাঙ্ক put_stabs(TCCState *s1, ধ্রুৱ ৱর্ণ *str, পূর্ণাঙ্ক type, পূর্ণাঙ্ক other, পূর্ণাঙ্ক desc,
                      unsigned long মান)
{
    Stab_Sym *sym;

    unsigned offset;
    যদি (type == N_SLINE
        && (offset = stab_section->data_offset)
        && (sym = (Stab_Sym*)(stab_section->data + offset) - 1)
        && sym->n_type == type
        && sym->n_মান == মান) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        ঘূৰাই 0;
    }

    sym = section_ptr_add(stab_section, পরিমাণ(Stab_Sym));
    যদি (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } অন্যথা {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_মান = মান;
    ঘূৰাই 1;
}

স্থির শূন্য put_stabs_r(TCCState *s1, ধ্রুৱ ৱর্ণ *str, পূর্ণাঙ্ক type, পূর্ণাঙ্ক other, পূর্ণাঙ্ক desc,
                        unsigned long মান, Section *sec, পূর্ণাঙ্ক sym_index)
{
    যদি (put_stabs(s1, str, type, other, desc, মান))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->data_offset - 4,
                      পরিমাণ ((Stab_Sym*)0)->n_মান == PTR_SIZE ? R_DATA_PTR : R_DATA_32,
                      sym_index);
}

স্থির শূন্য put_stabn(TCCState *s1, পূর্ণাঙ্ক type, পূর্ণাঙ্ক other, পূর্ণাঙ্ক desc, পূর্ণাঙ্ক মান)
{
    put_stabs(s1, রিক্ত, type, other, desc, মান);
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

স্থির পূর্ণাঙ্ক dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    ঘূৰাই put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_অঙ্ক, রিক্ত);
}

স্থির শূন্য dwarf_reloc(Section *s, পূর্ণাঙ্ক sym, পূর্ণাঙ্ক rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->data_offset, rel, sym, 0);
}

স্থির শূন্য free_str(সংরচনা dwarf_str_hash **str)
{
    পূর্ণাঙ্ক i;

    বাবে (i = 0; i < N_STR_HASH; i++) {
       যেতিয়ালৈ (str[i]) {
           সংরচনা dwarf_str_hash *next = str[i]->next;

           tcc_free(str[i]);
           str[i] = next;
       }
    }
}

স্থির unsigned str_hash(ধ্রুৱ ৱর্ণ *s)
{
    unsigned h = 5381;

    যেতিয়ালৈ (*s)
       h += (*s++ & 0xffu) + h * 31;
    ঘূৰাই h;
}

স্থির শূন্য dwarf_string(Section *s, Section *dw, পূর্ণাঙ্ক sym, ধ্রুৱ ৱর্ণ *str)
{
    TCCState *s1 = s->s1;
    পূর্ণাঙ্ক len, hash = str_hash(str) % N_STR_HASH;
    ৱর্ণ *ptr;
    সংরচনা dwarf_str_hash *new_hash;
    সংরচনা dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_সাৰি_str;

    len = strlen(str) + 1;
    new_hash = dw_hash[hash];
    যেতিয়ালৈ (new_hash) {
	যদি (new_hash->len == len &&
	    !memcmp(str, dw->data + new_hash->data_offset, len))
	    ভঙ্গ;
	new_hash = new_hash->next;
    }
    যদি (new_hash == রিক্ত) {
	unsigned long offset = dw->data_offset;

        new_hash = dw_hash[hash];
        যেতিয়ালৈ (new_hash) {
	    unsigned long n = new_hash->data_offset + new_hash->len - len;

	    যদি (new_hash->len > len &&
	        !memcmp(str, dw->data + n, len)) {
		offset = n;
		ভঙ্গ;
	    }
	    new_hash = new_hash->next;
        }
	যদি (new_hash == রিক্ত) {
	    ptr = section_ptr_add(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (সংরচনা dwarf_str_hash *)
	    tcc_malloc(পরিমাণ(সংরচনা dwarf_str_hash));
	new_hash->len = len;
	new_hash->data_offset = offset;
	new_hash->next = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->data_offset, R_DATA_32DW, sym,
                   PTR_SIZE == 4 ? 0 : new_hash->data_offset);
    dwarf_data4(s, PTR_SIZE == 4 ? new_hash->data_offset : 0);
}

স্থির শূন্য dwarf_strp(Section *s, ধ্রুৱ ৱর্ণ *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

স্থির শূন্য dwarf_সাৰি_strp(Section *s, ধ্রুৱ ৱর্ণ *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_সাৰি_str_section, dwarf_sym.সাৰি_str, str);
}

স্থির শূন্য dwarf_সাৰি_op(TCCState *s1, unsigned ৱর্ণ op)
{
    যদি (dwarf_সাৰি.সাৰি_size >= dwarf_সাৰি.সাৰি_max_size) {
	dwarf_সাৰি.সাৰি_max_size += 1024;
	dwarf_সাৰি.সাৰি_data =
	    (unsigned ৱর্ণ *)tcc_realloc(dwarf_সাৰি.সাৰি_data,
					 dwarf_সাৰি.সাৰি_max_size);
    }
    dwarf_সাৰি.সাৰি_data[dwarf_সাৰি.সাৰি_size++] = op;
}

স্থির শূন্য dwarf_file(TCCState *s1)
{
    পূর্ণাঙ্ক i, j;
    ৱর্ণ *filename;
    পূর্ণাঙ্ক index_offset = s1->dwarf < 5;

    যদি (!strcmp(file->filename, "<command line>")) {
        dwarf_সাৰি.cur_file = 1;
	ঘূৰাই;
    }
    filename = strrchr(file->filename, '/');
    যদি (filename == রিক্ত) {
        বাবে (i = 1; i < dwarf_সাৰি.filename_size; i++)
            যদি (dwarf_সাৰি.filename_table[i].dir_entry == 0 &&
		strcmp(dwarf_সাৰি.filename_table[i].name,
		       file->filename) == 0) {
		    dwarf_সাৰি.cur_file = i + index_offset;
	            ঘূৰাই;
		}
	i = -index_offset;
	filename = file->filename;
    }
    অন্যথা {
	ৱর্ণ *undo = filename;
	ৱর্ণ *dir = file->filename;

	*filename++ = '\0';
        বাবে (i = 0; i < dwarf_সাৰি.dir_size; i++)
	    যদি (strcmp(dwarf_সাৰি.dir_table[i], dir) == 0) {
		বাবে (j = 1; j < dwarf_সাৰি.filename_size; j++)
		    যদি (dwarf_সাৰি.filename_table[j].dir_entry - index_offset
			== i &&
			strcmp(dwarf_সাৰি.filename_table[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_সাৰি.cur_file = j + index_offset;
			ঘূৰাই;
		    }
		ভঙ্গ;
	    }
	যদি (i == dwarf_সাৰি.dir_size) {
	    dwarf_সাৰি.dir_size++;
	    dwarf_সাৰি.dir_table =
                (ৱর্ণ **) tcc_realloc(dwarf_সাৰি.dir_table,
                                      dwarf_সাৰি.dir_size *
                                      পরিমাণ (ৱর্ণ *));
            dwarf_সাৰি.dir_table[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_সাৰি.filename_table =
        (সংরচনা dwarf_filename_struct *)
        tcc_realloc(dwarf_সাৰি.filename_table,
                    (dwarf_সাৰি.filename_size + 1) *
                    পরিমাণ (সংরচনা dwarf_filename_struct));
    dwarf_সাৰি.filename_table[dwarf_সাৰি.filename_size].dir_entry =
	i + index_offset;
    dwarf_সাৰি.filename_table[dwarf_সাৰি.filename_size].name =
        tcc_strdup(filename);
    dwarf_সাৰি.cur_file = dwarf_সাৰি.filename_size++ + index_offset;
    ঘূৰাই;
}

#যদি 0
স্থির পূর্ণাঙ্ক dwarf_uleb128_size (unsigned long long মান)
{
    পূর্ণাঙ্ক size =  0;

    কৰা {
        মান >>= 7;
        size++;
    } যেতিয়ালৈ (মান != 0);
    ঘূৰাই size;
}
#endif

স্থির পূর্ণাঙ্ক dwarf_sleb128_size (long long মান)
{
    পূর্ণাঙ্ক size =  0;
    long long end = মান >> 63;
    unsigned ৱর্ণ last = end & 0x40;
    unsigned ৱর্ণ byte;

    কৰা {
        byte = মান & 0x7f;
        মান >>= 7;
        size++;
    } যেতিয়ালৈ (মান != end || (byte & 0x40) != last);
    ঘূৰাই size;
}

স্থির শূন্য dwarf_uleb128 (Section *s, unsigned long long মান)
{
    কৰা {
        unsigned ৱর্ণ byte = মান & 0x7f;

        মান >>= 7;
        dwarf_data1(s, byte | (মান ? 0x80 : 0));
    } যেতিয়ালৈ (মান != 0);
}

স্থির শূন্য dwarf_sleb128 (Section *s, long long মান)
{
    পূর্ণাঙ্ক more;
    long long end = মান >> 63;
    unsigned ৱর্ণ last = end & 0x40;

    কৰা {
        unsigned ৱর্ণ byte = মান & 0x7f;

        মান >>= 7;
	more = মান != end || (byte & 0x40) != last;
        dwarf_data1(s, byte | (0x80 * more));
    } যেতিয়ালৈ (more);
}

স্থির শূন্য dwarf_uleb128_op (TCCState *s1, unsigned long long মান)
{
    কৰা {
        unsigned ৱর্ণ byte = মান & 0x7f;

        মান >>= 7;
        dwarf_সাৰি_op(s1, byte | (মান ? 0x80 : 0));
    } যেতিয়ালৈ (মান != 0);
}

স্থির শূন্য dwarf_sleb128_op (TCCState *s1, long long মান)
{
    পূর্ণাঙ্ক more;
    long long end = মান >> 63;
    unsigned ৱর্ণ last = end & 0x40;

    কৰা {
        unsigned ৱর্ণ byte = মান & 0x7f;

        মান >>= 7;
        more = মান != end || (byte & 0x40) != last;
        dwarf_সাৰি_op(s1, byte | (0x80 * more));
    } যেতিয়ালৈ (more);
}

#যদি TCC_EH_FRAME
ST_FUNC শূন্য tcc_eh_frame_start(TCCState *s1)
{
    যদি (!s1->unwind_tables)
        ঘূৰাই;
    eh_frame_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section, 0); // CIE ID
    dwarf_data1(eh_frame_section, 1); // Version
    dwarf_data1(eh_frame_section, 'z'); // Augmentation String
    dwarf_data1(eh_frame_section, 'R');
    dwarf_data1(eh_frame_section, 0);
#যদি defined TCC_TARGET_I386
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
#নোচেদ্যদি defined TCC_TARGET_X86_64
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
#নোচেদ্যদি defined TCC_TARGET_ARM
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
#নোচেদ্যদি defined TCC_TARGET_ARM64
    dwarf_uleb128(eh_frame_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 30); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 31); // x31 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#নোচেদ্যদি defined TCC_TARGET_RISCV64
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
    যেতিয়ালৈ ((eh_frame_section->data_offset - s1->eh_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + s1->eh_start, // length
	      eh_frame_section->data_offset - s1->eh_start - 4);
}

স্থির শূন্য tcc_debug_frame_end(TCCState *s1, পূর্ণাঙ্ক size)
{
    পূর্ণাঙ্ক eh_section_sym;
    unsigned long fde_start;

    যদি (!eh_frame_section)
	ঘূৰাই;
    eh_section_sym = dwarf_get_section_sym(text_section);
    fde_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section,
		fde_start - s1->eh_start + 4); // CIE Pointer
#যদি defined TCC_TARGET_I386
    dwarf_reloc(eh_frame_section, eh_section_sym, R_386_PC32);
#নোচেদ্যদি defined TCC_TARGET_X86_64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_X86_64_PC32);
#নোচেদ্যদি defined TCC_TARGET_ARM
    dwarf_reloc(eh_frame_section, eh_section_sym, R_ARM_REL32);
#নোচেদ্যদি defined TCC_TARGET_ARM64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_AARCH64_PREL32);
#নোচেদ্যদি defined TCC_TARGET_RISCV64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_RISCV_32_PCREL);
#endif
    dwarf_data4(eh_frame_section, func_ind); // PC Begin
    dwarf_data4(eh_frame_section, size); // PC Range
    dwarf_data1(eh_frame_section, 0); // Augmentation Length
#যদি defined TCC_TARGET_I386
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
#নোচেদ্যদি defined TCC_TARGET_X86_64
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
#নোচেদ্যদি defined TCC_TARGET_ARM
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
#নোচেদ্যদি defined TCC_TARGET_ARM64
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
#নোচেদ্যদি defined TCC_TARGET_RISCV64
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
    যেতিয়ালৈ (size >= 4 &&
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
    যেতিয়ালৈ ((eh_frame_section->data_offset - fde_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + fde_start, // length
	      eh_frame_section->data_offset - fde_start - 4);
}

ST_FUNC শূন্য tcc_eh_frame_end(TCCState *s1)
{
    যদি (!eh_frame_section)
	ঘূৰাই;
    dwarf_data4(eh_frame_section, 0);
}

সংরচনা eh_অনুসন্ধান_table {
    uint32_t pc_offset;
    uint32_t fde_offset;
};

স্থির পূর্ণাঙ্ক sort_eh_table(ধ্রুৱ শূন্য *a, ধ্রুৱ শূন্য *b)
{
    uint32_t pc1 = ((ধ্রুৱ সংরচনা eh_অনুসন্ধান_table *)a)->pc_offset;
    uint32_t pc2 = ((ধ্রুৱ সংরচনা eh_অনুসন্ধান_table *)b)->pc_offset;

    ঘূৰাই pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC শূন্য tcc_eh_frame_hdr(TCCState *s1, পূর্ণাঙ্ক final)
{
    পূর্ণাঙ্ক গুনতি_2 = 0, offset;
    unsigned long গুনতি_offset, tab_offset;
    unsigned ৱর্ণ *ln, *end;
    unsigned পূর্ণাঙ্ক last_cie_offset = 0xffffffff;

    যদি (!eh_frame_section || !eh_frame_section->data_offset)
	ঘূৰাই;
    যদি (final && !eh_frame_hdr_section)
	ঘূৰাই;
    যদি (final == 0)
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
    //গুনতি
    গুনতি_offset = eh_frame_hdr_section->data_offset;
    dwarf_data4(eh_frame_hdr_section, 0);
    tab_offset = eh_frame_hdr_section->data_offset;
    ln = eh_frame_section->data;
    end = eh_frame_section->data + eh_frame_section->data_offset;
    যেতিয়ালৈ (ln < end) {
	unsigned ৱর্ণ *fde = ln, *rd = ln;
	unsigned পূর্ণাঙ্ক cie_offset, version, length = dwarf_read_4(rd, end);
	unsigned পূর্ণাঙ্ক pc_offset, fde_offset;

	যদি (length == 0)
	    গচ্ছ next;
        cie_offset = dwarf_read_4(rd, end);
	যদি (cie_offset == 0)
	    গচ্ছ next;
	যদি (cie_offset != last_cie_offset) {
	    unsigned ৱর্ণ *cie = rd - cie_offset + 4;

	    যদি (cie < eh_frame_section->data)
		গচ্ছ next;
	    version = dwarf_read_1(cie, end);
	    যদি ((version == 1 || version == 3) &&
	        dwarf_read_1(cie, end) == 'z' && // Augmentation String
		dwarf_read_1(cie, end) == 'R' &&
		dwarf_read_1(cie, end) == 0) {
	        dwarf_read_uleb128(&cie, end); // code_alignment_factor
	        dwarf_read_sleb128(&cie, end); // data_alignment_factor
		dwarf_read_1(cie, end); // return address column
		যদি (dwarf_read_uleb128(&cie, end) == 1 &&
		    dwarf_read_1(cie, end) == FDE_ENCODING) {
		    last_cie_offset = cie_offset;
		}
		অন্যথা
		    গচ্ছ next;
	    }
	    অন্যথা
		গচ্ছ next;
	}
	গুনতি_2++;
	fde_offset = eh_frame_section->sh_addr +
		     (fde - eh_frame_section->data) -
		     eh_frame_hdr_section->sh_addr;
	pc_offset = dwarf_read_4(rd, end) + fde_offset + 8;
	dwarf_data4(eh_frame_hdr_section, pc_offset);
	dwarf_data4(eh_frame_hdr_section, fde_offset);
next:
	ln += length + 4;
    }
    add32le(eh_frame_hdr_section->data + গুনতি_offset, গুনতি_2);
    qsort(eh_frame_hdr_section->data + tab_offset, গুনতি_2,
	  পরিমাণ(সংরচনা eh_অনুসন্ধান_table), sort_eh_table);
}
#endif

/* start of translation unit info */
ST_FUNC শূন্য tcc_debug_start(TCCState *s1)
{
    পূর্ণাঙ্ক i;
    ৱর্ণ buf[512];
    ৱর্ণ *filename;

    /* we might currently #include the <command-line> */
    filename = file->prev ? file->prev->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    যদি (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, text_section->data_offset, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            text_section->sh_অঙ্ক, "$a");

        new_file = last_সাৰি_অঙ্ক = 0;
        debug_next_type = N_DEFAULT_DEBUG;
        debug_hash_global = রিক্ত;
        debug_hash_local = রিক্ত;
        debug_forw_hash_global = রিক্ত;
        debug_forw_hash_local = রিক্ত;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, পরিমাণ(buf));
#ifdef _WIN32
        normalize_slashes(buf);
#endif

        যদি (s1->dwarf) {
            পূর্ণাঙ্ক start_abbrev;
            unsigned ৱর্ণ *ptr;
	    ৱর্ণ *undo;

            /* dwarf_abbrev */
            start_abbrev = dwarf_abbrev_section->data_offset;
            ptr = section_ptr_add(dwarf_abbrev_section, পরিমাণ(dwarf_abbrev_init));
            memcpy(ptr, dwarf_abbrev_init, পরিমাণ(dwarf_abbrev_init));

            যদি (s1->dwarf < 5) {
    	        যেতিয়ালৈ (*ptr) {
    	            ptr += 3;
    	            যেতিয়ালৈ (*ptr) {
    	                যদি (ptr[1] == DW_FORM_সাৰি_strp)
    		            ptr[1] = DW_FORM_strp;
		        যদি (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    যদি  (ptr[1] == DW_FORM_sec_offset)
			         ptr[1] = DW_FORM_data4;
			    /* This code uses only size < 0x80 so these are
			       compatible. */
			    যদি  (ptr[1] == DW_FORM_exprloc)
			         ptr[1] = DW_FORM_block1;
			}
    	                ptr += 2;
    	            }
		    ptr += 2;
    	        }
            }

            dwarf_sym.info = dwarf_get_section_sym(dwarf_info_section);
            dwarf_sym.abbrev = dwarf_get_section_sym(dwarf_abbrev_section);
            dwarf_sym.সাৰি = dwarf_get_section_sym(dwarf_সাৰি_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            যদি (tcc_state->dwarf >= 5)
    	        dwarf_sym.সাৰি_str = dwarf_get_section_sym(dwarf_সাৰি_str_section);
            অন্যথা {
    	        dwarf_সাৰি_str_section = dwarf_str_section;
                dwarf_sym.সাৰি_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(text_section);

            /* dwarf_info */
            dwarf_info.start = dwarf_info_section->data_offset;
            dwarf_data4(dwarf_info_section, 0); // size
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            যদি (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_SIZE);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_DATA_32DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
            }
            অন্যথা {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_DATA_32DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
                dwarf_data1(dwarf_info_section, PTR_SIZE);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_VERSION);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_সাৰি_strp(dwarf_info_section, filename);
            dwarf_সাৰি_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#যদি PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#অন্যথা
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#endif
            dwarf_reloc(dwarf_info_section, dwarf_sym.সাৰি, R_DATA_32DW);
            dwarf_data4(dwarf_info_section, dwarf_সাৰি_section->data_offset); // stmt_list

            /* dwarf_line */
            dwarf_সাৰি.start = dwarf_সাৰি_section->data_offset;
            dwarf_data4(dwarf_সাৰি_section, 0); // length
            dwarf_data2(dwarf_সাৰি_section, s1->dwarf); // version
            যদি (s1->dwarf >= 5) {
                dwarf_data1(dwarf_সাৰি_section, PTR_SIZE); // address size
                dwarf_data1(dwarf_সাৰি_section, 0); // segment selector
            }
            dwarf_data4(dwarf_সাৰি_section, 0); // prologue Length
            dwarf_data1(dwarf_সাৰি_section, DWARF_MIN_INSTR_LEN);
            যদি (s1->dwarf >= 4)
                dwarf_data1(dwarf_সাৰি_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_সাৰি_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_সাৰি_section, DWARF_সাৰি_BASE);
            dwarf_data1(dwarf_সাৰি_section, DWARF_সাৰি_RANGE);
            dwarf_data1(dwarf_সাৰি_section, DWARF_OPCODE_BASE);
            ptr = section_ptr_add(dwarf_সাৰি_section, পরিমাণ(dwarf_সাৰি_opcodes));
            memcpy(ptr, dwarf_সাৰি_opcodes, পরিমাণ(dwarf_সাৰি_opcodes));
	    undo = strrchr(filename, '/');
	    যদি (undo)
		*undo = 0;
            dwarf_সাৰি.dir_size = 1 + (undo != রিক্ত);
            dwarf_সাৰি.dir_table = (ৱর্ণ **) tcc_malloc(পরিমাণ (ৱর্ণ *) *
							dwarf_সাৰি.dir_size);
            dwarf_সাৰি.dir_table[0] = tcc_strdup(buf);
	    যদি (undo)
                dwarf_সাৰি.dir_table[1] = tcc_strdup(filename);
            dwarf_সাৰি.filename_size = 2;
            dwarf_সাৰি.filename_table =
    	        (সংরচনা dwarf_filename_struct *)
    	        tcc_malloc(2*পরিমাণ (সংরচনা dwarf_filename_struct));
            dwarf_সাৰি.filename_table[0].dir_entry = 0;
	    যদি (undo) {
                dwarf_সাৰি.filename_table[0].name = tcc_strdup(undo + 1);
                dwarf_সাৰি.filename_table[1].dir_entry = 1;
                dwarf_সাৰি.filename_table[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    অন্যথা {
                dwarf_সাৰি.filename_table[0].name = tcc_strdup(filename);
                dwarf_সাৰি.filename_table[1].dir_entry = 0;
                dwarf_সাৰি.filename_table[1].name = tcc_strdup(filename);
	    }
            dwarf_সাৰি.সাৰি_size = dwarf_সাৰি.সাৰি_max_size = 0;
            dwarf_সাৰি.সাৰি_data = রিক্ত;
            dwarf_সাৰি.cur_file = 1;
            dwarf_সাৰি.last_file = 0;
            dwarf_সাৰি.last_pc = 0;
            dwarf_সাৰি.last_সাৰি = 1;
            dwarf_সাৰি_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_SIZE); // extended size
            dwarf_সাৰি_op(s1, DW_LNE_set_address);
            বাবে (i = 0; i < PTR_SIZE; i++)
    	        dwarf_সাৰি_op(s1, 0);
            memset(&dwarf_info.base_type_used, 0, পরিমাণ(dwarf_info.base_type_used));
        }
        অন্যথা
        {
            /* file info: full path + filename */
            pstrcat(buf, পরিমাণ(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      text_section->sh_অঙ্ক, রিক্ত);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            বাবে (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

স্থির শূন্য fix_debug_forw_hash(TCCState *s1, পূর্ণাঙ্ক global, পূর্ণাঙ্ক start);

/* put end of translation unit info */
ST_FUNC শূন্য tcc_debug_end(TCCState *s1)
{

    যদি (!s1->do_debug || debug_next_type == 0)
        ঘূৰাই;

    যদি (debug_info_মূল)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    যদি (s1->dwarf) {
	পূর্ণাঙ্ক i;
	পূর্ণাঙ্ক start_aranges;
	unsigned ৱর্ণ *ptr;
	পূর্ণাঙ্ক text_size = text_section->data_offset;

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
#যদি PTR_SIZE == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#অন্যথা
	dwarf_data1(dwarf_aranges_section, 8); // address size
#endif
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_DATA_PTR);
#যদি PTR_SIZE == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, text_size); // End
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#অন্যথা
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, text_size); // End
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#endif
	ptr = dwarf_aranges_section->data + start_aranges;
	write32le(ptr, dwarf_aranges_section->data_offset - start_aranges - 4);

	/* dwarf_line */
	যদি (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_সাৰি_section, 1); /* col */
	    dwarf_uleb128(dwarf_সাৰি_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_সাৰি_section, DW_FORM_সাৰি_strp);
	    dwarf_uleb128(dwarf_সাৰি_section, dwarf_সাৰি.dir_size);
	    বাবে (i = 0; i < dwarf_সাৰি.dir_size; i++)
	        dwarf_সাৰি_strp(dwarf_সাৰি_section, dwarf_সাৰি.dir_table[i]);
	    dwarf_data1(dwarf_সাৰি_section, 2); /* col */
	    dwarf_uleb128(dwarf_সাৰি_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_সাৰি_section, DW_FORM_সাৰি_strp);
	    dwarf_uleb128(dwarf_সাৰি_section, DW_LNCT_directory_index);
	    dwarf_uleb128(dwarf_সাৰি_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_সাৰি_section, dwarf_সাৰি.filename_size);
	    বাবে (i = 0; i < dwarf_সাৰি.filename_size; i++) {
	        dwarf_সাৰি_strp(dwarf_সাৰি_section,
				dwarf_সাৰি.filename_table[i].name);
	        dwarf_uleb128(dwarf_সাৰি_section,
			      dwarf_সাৰি.filename_table[i].dir_entry);
	    }
	}
	অন্যথা {
	    পূর্ণাঙ্ক len;

	    বাবে (i = 0; i < dwarf_সাৰি.dir_size; i++) {
	        len = strlen(dwarf_সাৰি.dir_table[i]) + 1;
	        ptr = section_ptr_add(dwarf_সাৰি_section, len);
	        memmove(ptr, dwarf_সাৰি.dir_table[i], len);
	    }
	    dwarf_data1(dwarf_সাৰি_section, 0); /* end dir */
	    বাবে (i = 0; i < dwarf_সাৰি.filename_size; i++) {
	        len = strlen(dwarf_সাৰি.filename_table[i].name) + 1;
	        ptr = section_ptr_add(dwarf_সাৰি_section, len);
	        memmove(ptr, dwarf_সাৰি.filename_table[i].name, len);
	        dwarf_uleb128(dwarf_সাৰি_section,
			      dwarf_সাৰি.filename_table[i].dir_entry);
	        dwarf_uleb128(dwarf_সাৰি_section, 0); /* time */
	        dwarf_uleb128(dwarf_সাৰি_section, 0); /* size */
	    }
	    dwarf_data1(dwarf_সাৰি_section, 0); /* end file */
	}
	বাবে (i = 0; i < dwarf_সাৰি.dir_size; i++)
	    tcc_free(dwarf_সাৰি.dir_table[i]);
	tcc_free(dwarf_সাৰি.dir_table);
	বাবে (i = 0; i < dwarf_সাৰি.filename_size; i++)
	    tcc_free(dwarf_সাৰি.filename_table[i].name);
	tcc_free(dwarf_সাৰি.filename_table);

	dwarf_সাৰি_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_সাৰি_op(s1, DW_LNE_end_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_সাৰি_section->data[dwarf_সাৰি.start + 6 + i],
		  dwarf_সাৰি_section->data_offset - dwarf_সাৰি.start - (10 + i));
	section_ptr_add(dwarf_সাৰি_section, 3);
	dwarf_reloc(dwarf_সাৰি_section, section_sym, R_DATA_PTR);
	ptr = section_ptr_add(dwarf_সাৰি_section, dwarf_সাৰি.সাৰি_size - 3);
	memmove(ptr - 3, dwarf_সাৰি.সাৰি_data, dwarf_সাৰি.সাৰি_size);
	tcc_free(dwarf_সাৰি.সাৰি_data);
	write32le(dwarf_সাৰি_section->data + dwarf_সাৰি.start,
		  dwarf_সাৰি_section->data_offset - dwarf_সাৰি.start - 4);
    }
    অন্যথা
    {
        put_stabs_r(s1, রিক্ত, N_SO, 0, 0,
                    text_section->data_offset, text_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_সাৰি_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_next_type = 0;
}

স্থির BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    যদি (f->filename[0] == ':')
        f = f->prev;
    যদি (f && new_file) {
        new_file = last_সাৰি_অঙ্ক = 0;
        যদি (s1->dwarf)
            dwarf_file(s1);
        অন্যথা
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, text_section, section_sym);
    }
    ঘূৰাই f;
}

/* put alternative filename */
ST_FUNC শূন্য tcc_debug_newfile(TCCState *s1)
{
    যদি (!s1->do_debug)
        ঘূৰাই;
    যদি (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC শূন্য tcc_debug_bincl(TCCState *s1)
{
    যদি (!s1->do_debug)
        ঘূৰাই;
    যদি (s1->dwarf)
        dwarf_file(s1);
    অন্যথা
        put_stabs(s1, file->filename, N_BINCL, 0, 0, 0);
    new_file = 1;
}

/* end of #include */
ST_FUNC শূন্য tcc_debug_eincl(TCCState *s1)
{
    যদি (!s1->do_debug)
        ঘূৰাই;
    যদি (s1->dwarf)
        dwarf_file(s1);
    অন্যথা
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC শূন্য tcc_debug_সাৰি(TCCState *s1)
{
    BufferedFile *f;

    যদি (!s1->do_debug)
        ঘূৰাই;
    যদি (cur_text_section != text_section || nocode_wanted)
        ঘূৰাই;
    f = put_new_file(s1);
    যদি (!f)
        ঘূৰাই;
    যদি (last_সাৰি_অঙ্ক == f->সাৰি_অঙ্ক)
        ঘূৰাই;
    last_সাৰি_অঙ্ক = f->সাৰি_অঙ্ক;

    যদি (s1->dwarf) {
	পূর্ণাঙ্ক len_pc = (ind - dwarf_সাৰি.last_pc) / DWARF_MIN_INSTR_LEN;
	পূর্ণাঙ্ক len_সাৰি = f->সাৰি_অঙ্ক - dwarf_সাৰি.last_সাৰি;
	পূর্ণাঙ্ক n = len_pc * DWARF_সাৰি_RANGE + len_সাৰি + DWARF_OPCODE_BASE - DWARF_সাৰি_BASE;

	যদি (dwarf_সাৰি.cur_file != dwarf_সাৰি.last_file) {
	    dwarf_সাৰি.last_file = dwarf_সাৰি.cur_file;
	    dwarf_সাৰি_op(s1, DW_LNS_set_file);
	    dwarf_uleb128_op(s1, dwarf_সাৰি.cur_file);
	}
	যদি (len_pc &&
	    len_সাৰি >= DWARF_সাৰি_BASE && len_সাৰি <= (DWARF_OPCODE_BASE + DWARF_সাৰি_BASE) &&
	    n >= DWARF_OPCODE_BASE && n <= 255)
            dwarf_সাৰি_op(s1, n);
	অন্যথা {
	    যদি (len_pc) {
	        n = len_pc * DWARF_সাৰি_RANGE + 0 + DWARF_OPCODE_BASE - DWARF_সাৰি_BASE;
	        যদি (n >= DWARF_OPCODE_BASE && n <= 255)
                    dwarf_সাৰি_op(s1, n);
		অন্যথা {
	            dwarf_সাৰি_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    যদি (len_সাৰি) {
	        n = 0 * DWARF_সাৰি_RANGE + len_সাৰি + DWARF_OPCODE_BASE - DWARF_সাৰি_BASE;
	        যদি (len_সাৰি >= DWARF_সাৰি_BASE && len_সাৰি <= (DWARF_OPCODE_BASE + DWARF_সাৰি_BASE) &&
		    n >= DWARF_OPCODE_BASE && n <= 255)
	            dwarf_সাৰি_op(s1, n);
		অন্যথা {
	            dwarf_সাৰি_op(s1, DW_LNS_advance_সাৰি);
		    dwarf_sleb128_op(s1, len_সাৰি);
                    /* advance by nothing */
	            dwarf_সাৰি_op(s1, DWARF_OPCODE_BASE - DWARF_সাৰি_BASE);
		}
	    }
	}
	dwarf_সাৰি.last_pc = ind;
	dwarf_সাৰি.last_সাৰি = f->সাৰি_অঙ্ক;
    }
    অন্যথা
    {
	যদি (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->সাৰি_অঙ্ক, ind - func_ind);
        } অন্যথা {
            /* from tcc_assemble */
            put_stabs_r(s1, রিক্ত, N_SLINE, 0, f->সাৰি_অঙ্ক, ind, text_section, section_sym);
        }
    }
}

স্থির শূন্য tcc_debug_stabs (TCCState *s1, ধ্রুৱ ৱর্ণ *str, পূর্ণাঙ্ক type, unsigned long মান,
                             Section *sec, পূর্ণাঙ্ক sym_index, পূর্ণাঙ্ক info)
{
    সংরচনা debug_sym *s;

    যদি (debug_info) {
        debug_info->sym =
            (সংরচনা debug_sym *)tcc_realloc (debug_info->sym,
                                             পরিমাণ(সংরচনা debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->মান = মান;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_index = sym_index;
        s->info = info;
        s->file = dwarf_সাৰি.cur_file;
        s->সাৰি = file->সাৰি_অঙ্ক;
    }
    অন্যথা যদি (sec)
        put_stabs_r (s1, str, type, 0, 0, মান, sec, sym_index);
    অন্যথা
        put_stabs (s1, str, type, 0, 0, মান);
}

স্থির শূন্য fix_debug_forw_hash(TCCState *s1, পূর্ণাঙ্ক global, পূর্ণাঙ্ক start)
{
    যদি (s1->dwarf) {
        পূর্ণাঙ্ক i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	সংরচনা _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	বাবে (i = start; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    পূর্ণাঙ্ক pos = dwarf_info_section->data_offset;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_EMPTY_TYPE
                                             : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, রিক্ত));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_সাৰি.cur_file);
            dwarf_uleb128(dwarf_info_section, file->সাৰি_অঙ্ক);
	    বাবে (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->data +
			  hash[i].debug_type[j],
			  pos - dwarf_info.start);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC শূন্য tcc_debug_stabn(TCCState *s1, পূর্ণাঙ্ক type, পূর্ণাঙ্ক মান)
{
    যদি (!s1->do_debug)
        ঘূৰাই;
    যদি (type == N_LBRAC) {
        সংরচনা _debug_info *info =
            (সংরচনা _debug_info *) tcc_mallocz(পরিমাণ (*info));

        info->start = মান;
        info->last_debug_hash = n_debug_hash_local;
        info->last_debug_forw_hash = n_debug_forw_hash_local;
        info->parent = debug_info;
        যদি (debug_info) {
            যদি (debug_info->child) {
                যদি (debug_info->child->last)
                    debug_info->child->last->next = info;
                অন্যথা
                    debug_info->child->next = info;
                debug_info->child->last = info;
            }
            অন্যথা
                debug_info->child = info;
        }
        অন্যথা
            debug_info_মূল = info;
        debug_info = info;
    }
    অন্যথা {
	fix_debug_forw_hash(s1, 0, debug_info->last_debug_forw_hash);
        n_debug_hash_local = debug_info->last_debug_hash;
        n_debug_forw_hash_local = debug_info->last_debug_forw_hash;
        debug_info->end = মান;
        debug_info = debug_info->parent;
    }
}

স্থির পূর্ণাঙ্ক check_global(Sym *t)
{
    Sym *g = local_স্তূপ;

    যেতিয়ালৈ (g) {
	যদি (t == g)
	    ঘূৰাই 0;
	g = g->prev;
    }
    ঘূৰাই 1;
}

স্থির পূর্ণাঙ্ক tcc_debug_find(TCCState *s1, Sym *t, পূর্ণাঙ্ক dwarf)
{
    পূর্ণাঙ্ক i , g = check_global(t);
    পূর্ণাঙ্ক n_hash, *n_forw_hash;
    সংরচনা _debug_hash *hash;
    সংরচনা _debug_forw_hash **forw_hash;

    যদি ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	বাবে (i = 0; i < *n_forw_hash; i++)
            যদি (t == (*forw_hash)[i].type)
		ঘূৰাই 0;
	*forw_hash = (সংরচনা _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * পরিমাণ(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = রিক্ত;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	ঘূৰাই 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    বাবে (i = 0; i < n_hash; i++)
        যদি (t == hash[i].type)
	    ঘূৰাই hash[i].debug_type;
    ঘূৰাই -1;
}

স্থির পূর্ণাঙ্ক tcc_get_dwarf_info(TCCState *s1, Sym *s);

স্থির শূন্য tcc_debug_check_forw(TCCState *s1, Sym *t, পূর্ণাঙ্ক debug_type)
{
    যদি ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        পূর্ণাঙ্ক i, j, g = check_global(t);
        পূর্ণাঙ্ক n_forw_hash;
        সংরচনা _debug_forw_hash **forw_hash;

	বাবে (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    বাবে (j = 0; j < n_forw_hash; j++)
                যদি (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * পরিমাণ(পূর্ণাঙ্ক));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    ঘূৰাই;
                }
	}
    }
}

স্থির শূন্য stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC শূন্য tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    যদি (!(s1->do_debug & 2))
	ঘূৰাই;
    যদি (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        ঘূৰাই;
    }
    যদি ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        পূর্ণাঙ্ক i, j, debug_type, g = check_global(t->ref);
        পূর্ণাঙ্ক *n_forw_hash;
        সংরচনা _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	বাবে (i = 0; i < *n_forw_hash; i++)
	    যদি (t->ref == (*forw_hash)[i].type) {
		যদি (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    বাবে (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->data +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.start);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		বাবে (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

স্থির পূর্ণাঙ্ক tcc_debug_add(TCCState *s1, Sym *t, পূর্ণাঙ্ক dwarf)
{
    পূর্ণাঙ্ক offset = dwarf ? dwarf_info_section->data_offset : ++debug_next_type;
    পূর্ণাঙ্ক *n_hash, g = check_global(t);
    সংরচনা _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (সংরচনা _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * পরিমাণ(**hash));
    (*hash)[*n_hash].debug_type = offset;
    (*hash)[(*n_hash)++].type = t;
    ঘূৰাই offset;
}

স্থির পূর্ণাঙ্ক STRUCT_NODEBUG(Sym *s)
{
    ঘূৰাই
    (s->a.nodebug ||
     ((s->v & ~SYM_FIELD) >= SYM_FIRST_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

স্থির পূর্ণাঙ্ক stabs_struct_find(TCCState *s1, Sym *t, পূর্ণাঙ্ক *p_id)
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
    যদি (রিক্ত == p_id)
        ঘূৰাই s && !s->r && t->c >= 0;
    যদি (রিক্ত == s) {
        /* just use global_stack always */
        s = sym_push2(&global_স্তূপ, SYM_FIELD|0x00DEBBED, 0, ++debug_next_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    যদি (s->r || t->c < 0) /* already defined or still incomplete */
        ঘূৰাই 0;
    s->r = 1;
    ঘূৰাই 1;
}

স্থির পূর্ণাঙ্ক remove_type_info(পূর্ণাঙ্ক type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        যদি ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        যদি (!(type & VT_BITFIELD) && (type & VT_STRUCT_MASK) > VT_ENUM)
	    type &= ~VT_STRUCT_MASK;
	ঘূৰাই type;
}

স্থির শূন্য tcc_get_debug_info(TCCState *s1, Sym *s, CString *result)
{
    পূর্ণাঙ্ক type;
    পূর্ণাঙ্ক n = 0;
    পূর্ণাঙ্ক debug_type = -1;
    Sym *t = s;
    CString str;

    বাবে (;;) {
        type = remove_type_info (t->type.t);
        যদি (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        অন্যথা
            ভঙ্গ;
    }
    যদি ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        যদি (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, রিক্ত),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            যেতিয়ালৈ (t->next) {
                পূর্ণাঙ্ক pos, size, align;
                t = t->next;
		যদি (STRUCT_NODEBUG(t))
		    অনুৱর্ত;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, রিক্ত)
                             );
                tcc_get_debug_info (s1, t, &str);
                যদি (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + BIT_POS(t->type.t);
                    size = BIT_SIZE(t->type.t);
                }
                অন্যথা {
                    pos = t->c * 8;
                    size = type_size(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, size);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, রিক্ত, 0, 0);
            cstr_free (&str);
        }
    }
    অন্যথা যদি (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        যদি (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, রিক্ত),
                         debug_type);
            যেতিয়ালৈ (t->next) {
                t = t->next;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, রিক্ত));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (পূর্ণাঙ্ক)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, রিক্ত, 0, 0);
            cstr_free (&str);
	}
    }
    অন্যথা যদি ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        বাবে (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            যদি (default_debug[debug_type - 1].type == type)
                ভঙ্গ;
        যদি (debug_type > N_DEFAULT_DEBUG)
            ঘূৰাই;
    }

    যদি (রিক্ত == result) /* from stabs_struct_complete() */
        ঘূৰাই;

    যদি (n > 0)
        cstr_printf (result, "%d=", ++debug_next_type);
    t = s;
    বাবে (;;) {
        type = remove_type_info (t->type.t);
        যদি (type == VT_PTR)
            cstr_printf (result, "%d=*", ++debug_next_type);
        অন্যথা যদি (type == (VT_PTR | VT_ARRAY))
            cstr_printf (result, "%d=ar1;0;%d;",
                         ++debug_next_type, t->type.ref->c - 1);
        অন্যথা যদি (type == VT_FUNC) {
            cstr_printf (result, "%d=f", ++debug_next_type);
            tcc_get_debug_info (s1, t->type.ref, result);
            ঘূৰাই;
        }
        অন্যথা
            ভঙ্গ;
        t = t->type.ref;
    }
    cstr_printf (result, "%d", debug_type);
}

স্থির শূন্য stabs_struct_complete(TCCState *s1, CType *t)
{
    যদি (stabs_struct_find(s1, t->ref, রিক্ত)) {
        Sym s = {0}; s.type = *t;
        tcc_get_debug_info(s1, &s, রিক্ত);
    }
}

স্থির পূর্ণাঙ্ক tcc_get_dwarf_info(TCCState *s1, Sym *s)
{
    পূর্ণাঙ্ক type;
    পূর্ণাঙ্ক debug_type = -1;
    Sym *e, *t = s;
    পূর্ণাঙ্ক i;
    পূর্ণাঙ্ক last_pos = -1;
    পূর্ণাঙ্ক retval;

    যদি (new_file)
        put_new_file(s1);
    বাবে (;;) {
        type = remove_type_info (t->type.t);
        যদি (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        অন্যথা
            ভঙ্গ;
    }
    যদি ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	যদি (debug_type == -1) {
	    পূর্ণাঙ্ক pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_add(s1, t, 1);
	    e = t;
	    i = 0;
	    যেতিয়ালৈ (e->next) {
		e = e->next;
		যদি (STRUCT_NODEBUG(e))
		    অনুৱর্ত;
		i++;
	    }
	    pos_type = (পূর্ণাঙ্ক *) tcc_malloc(i * পরিমাণ(পূর্ণাঙ্ক));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->next ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_EMPTY_TYPE
		        : t->next ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, রিক্ত));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_সাৰি.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->সাৰি_অঙ্ক);
	    যদি (t->next) {
	        pos_sib = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            যেতিয়ালৈ (e->next) {
                e = e->next;
		যদি (STRUCT_NODEBUG(e))
		    অনুৱর্ত;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, রিক্ত));
		dwarf_uleb128(dwarf_info_section, dwarf_সাৰি.cur_file);
		dwarf_uleb128(dwarf_info_section, file->সাৰি_অঙ্ক);
		pos_type[i++] = dwarf_info_section->data_offset;
		dwarf_data4(dwarf_info_section, 0);
                যদি (e->type.t & VT_BITFIELD) {
                    পূর্ণাঙ্ক pos = e->c * 8 + BIT_POS(e->type.t);
                    পূর্ণাঙ্ক size = BIT_SIZE(e->type.t);

		    dwarf_uleb128(dwarf_info_section, size);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		অন্যথা
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    যদি (t->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + pos_sib,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    e = t;
	    i = 0;
	    যেতিয়ালৈ (e->next) {
		e = e->next;
		যদি (STRUCT_NODEBUG(e))
		    অনুৱর্ত;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->data + pos_type[i++],
			  type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
    }
    অন্যথা যদি (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	যদি (debug_type == -1) {
	    পূর্ণাঙ্ক pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_add(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, রিক্ত));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.start);
	    dwarf_uleb128(dwarf_info_section, dwarf_সাৰি.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->সাৰি_অঙ্ক);
	    pos_sib = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            যেতিয়ালৈ (e->next) {
                e = e->next;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                           ? "" : get_tok_str(e->v, রিক্ত));
		যদি (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		অন্যথা
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + pos_sib,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
    }
    অন্যথা যদি ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        বাবে (i = 1; i <= N_DEFAULT_DEBUG; i++)
            যদি (default_debug[i - 1].type == type)
                ভঙ্গ;
        যদি (i > N_DEFAULT_DEBUG)
            ঘূৰাই 0;
	debug_type = dwarf_info.base_type_used[i - 1];
	যদি (debug_type == 0) {
	    ৱর্ণ name[100];

	    debug_type = dwarf_info_section->data_offset;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_BASE_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].size);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, পরিমাণ name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.base_type_used[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = রিক্ত;
    t = s;
    বাবে (;;) {
        type = remove_type_info (t->type.t);
        যদি (type == VT_PTR) {
	    i = dwarf_info_section->data_offset;
	    যদি (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_POINTER);
	    dwarf_data1(dwarf_info_section, PTR_SIZE);
	    যদি (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        অন্যথা যদি (type == (VT_PTR | VT_ARRAY)) {
	    পূর্ণাঙ্ক sib_pos, sub_type;
#যদি LONG_SIZE == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#অন্যথা
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#endif

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->data_offset;
	    যদি (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    যদি (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    বাবে (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.start);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		যদি (type != (VT_PTR | VT_ARRAY))
		    ভঙ্গ;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + sib_pos,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
        অন্যথা যদি (type == VT_FUNC) {
	    পূর্ণাঙ্ক sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->data_offset;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    যদি (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->next ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_EMPTY_TYPE);
	    যদি (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    যদি (t->type.ref->next) {
	        sib_pos = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    যেতিয়ালৈ (f->next) {
		f = f->next;
		i++;
	    }
	    pos_type = (পূর্ণাঙ্ক *) tcc_malloc(i * পরিমাণ(পূর্ণাঙ্ক));
	    f = t->type.ref;
	    i = 0;
	    যেতিয়ালৈ (f->next) {
		f = f->next;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    যদি (t->type.ref->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + sib_pos,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    f = t->type.ref;
	    i = 0;
	    যেতিয়ালৈ (f->next) {
		f = f->next;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->data + pos_type[i++],
                          type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
        অন্যথা {
	    যদি (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  debug_type - dwarf_info.start);
	    }
            ভঙ্গ;
	}
        t = t->type.ref;
    }
    ঘূৰাই retval;
}

স্থির শূন্য tcc_debug_finish (TCCState *s1, সংরচনা _debug_info *cur)
{
    যেতিয়ালৈ (cur) {
        সংরচনা _debug_info *next = cur->next;
        পূর্ণাঙ্ক i;

        যদি (s1->dwarf) {

            বাবে (i = cur->n_sym - 1; i >= 0; i--) {
                সংরচনা debug_sym *s = &cur->sym[i];

		dwarf_data1(dwarf_info_section,
                            s->type == N_PSYM
			    ? DWARF_ABBREV_FORMAL_PARAMETER
			    : s->type == N_GSYM
                            ? DWARF_ABBREV_VARIABLE_EXTERNAL
                            : s->type == N_STSYM
			    ? DWARF_ABBREV_VARIABLE_STATIC
			    : DWARF_ABBREV_VARIABLE_LOCAL);
                dwarf_strp(dwarf_info_section, s->str);
		যদি (s->type == N_GSYM || s->type == N_STSYM) {
                    dwarf_uleb128(dwarf_info_section, s->file);
                    dwarf_uleb128(dwarf_info_section, s->সাৰি);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.start);
		যদি (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    যদি (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    যদি (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#যদি PTR_SIZE == 4
                    dwarf_data4(dwarf_info_section, s->মান);
#অন্যথা
                    dwarf_data8(dwarf_info_section, s->মান);
#endif
		}
		অন্যথা {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_size((long)s->মান) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (long)s->মান);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->child ? DWARF_ABBREV_LEXICAL_BLOCK
			           : DWARF_ABBREV_LEXICAL_EMPTY_BLOCK);
            dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#যদি PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->start);
            dwarf_data4(dwarf_info_section, cur->end - cur->start);
#অন্যথা
            dwarf_data8(dwarf_info_section, func_ind + cur->start);
            dwarf_data8(dwarf_info_section, cur->end - cur->start);
#endif
            tcc_debug_finish (s1, cur->child);
	    যদি (cur->child)
                dwarf_data1(dwarf_info_section, 0);
        }
        অন্যথা
        {
            বাবে (i = 0; i < cur->n_sym; i++) {
                সংরচনা debug_sym *s = &cur->sym[i];

                যদি (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->মান,
                                s->sec, s->sym_index);
                অন্যথা
                    put_stabs(s1, s->str, s->type, 0, 0, s->মান);
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

ST_FUNC শূন্য tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    পূর্ণাঙ্ক param;

    যদি (!(s1->do_debug & 2))
        ঘূৰাই;

    cstr_new (&debug_str);
    param = !e;
    বাবে (; s != e; s = s->prev) {
        যদি (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            অনুৱর্ত;
	যদি (s1->dwarf) {
	    tcc_debug_stabs(s1, get_tok_str(s->v, রিক্ত),
			    param ? N_PSYM : N_LSYM, s->c, রিক্ত, 0,
			    tcc_get_dwarf_info(s1, s));
	}
	অন্যথা
        {
            cstr_reset (&debug_str);
            cstr_printf (&debug_str, "%s:%s", get_tok_str(s->v, রিক্ত),
			 param ? "p" : "");
            tcc_get_debug_info(s1, s, &debug_str);
            tcc_debug_stabs(s1, debug_str.data, param ? N_PSYM : N_LSYM,
			    s->c, রিক্ত, 0, 0);
	}
    }
    cstr_free (&debug_str);
}

/* put function symbol */
ST_FUNC শূন্য tcc_debug_funcstart(TCCState *s1, Sym *sym)
{
    CString debug_str;
    BufferedFile *f;

    যদি (!s1->do_debug)
        ঘূৰাই;
    debug_info_মূল = রিক্ত;
    debug_info = রিক্ত;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    যদি (!f)
	ঘূৰাই;

    যদি (s1->dwarf) {
        tcc_debug_সাৰি(s1);
        dwarf_info.func = sym;
        dwarf_info.সাৰি = file->সাৰি_অঙ্ক;
	যদি (s1->do_backtrace) {
	    পূর্ণাঙ্ক i, len;

	    dwarf_সাৰি_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, strlen(funcname) + 2);
	    dwarf_সাৰি_op(s1, DW_LNE_hi_user - 1);
	    len = strlen(funcname) + 1;
	    বাবে (i = 0; i < len; i++)
		dwarf_সাৰি_op(s1, funcname[i]);
	}
    }
    অন্যথা
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.data, N_FUN, 0, f->সাৰি_অঙ্ক, 0, cur_text_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_সাৰি(s1);
    }
}

ST_FUNC শূন্য tcc_debug_prolog_epilog(TCCState *s1, পূর্ণাঙ্ক মান)
{
    যদি (!s1->do_debug)
        ঘূৰাই;
    যদি (s1->dwarf) {
	dwarf_সাৰি_op(s1, মান == 0 ? DW_LNS_set_prologue_end
				     : DW_LNS_set_epilogue_begin);
    }
}

/* put function size */
ST_FUNC শূন্য tcc_debug_funcend(TCCState *s1, পূর্ণাঙ্ক size)
{
    /* lldb does not like function end and next function start at same pc */
    পূর্ণাঙ্ক min_instr_len;

#যদি TCC_EH_FRAME
    tcc_debug_frame_end(s1, size);
#endif
    যদি (!s1->do_debug)
        ঘূৰাই;
    min_instr_len = dwarf_সাৰি.last_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_সাৰি(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, size);
    যদি (s1->dwarf) {
        পূর্ণাঙ্ক func_sib = 0;
	Sym *sym = dwarf_info.func;
	পূর্ণাঙ্ক n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        যদি ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_সাৰি.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.সাৰি);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->data_offset);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.start);
        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#যদি PTR_SIZE == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, size); // high_pc
#অন্যথা
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, size); // high_pc
#endif
        func_sib = dwarf_info_section->data_offset;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#যদি defined(TCC_TARGET_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#নোচেদ্যদি defined(TCC_TARGET_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#নোচেদ্যদি defined TCC_TARGET_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#নোচেদ্যদি defined TCC_TARGET_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#নোচেদ্যদি defined TCC_TARGET_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#অন্যথা
        dwarf_data1(dwarf_info_section, DW_OP_call_frame_cfa);
#endif
        tcc_debug_finish (s1, debug_info_মূল);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->data + func_sib,
                  dwarf_info_section->data_offset - dwarf_info.start);
    }
    অন্যথা
    {
        tcc_debug_finish (s1, debug_info_মূল);
    }
    debug_info_মূল = 0;
}


ST_FUNC শূন্য tcc_debug_extern_sym(TCCState *s1, Sym *sym, পূর্ণাঙ্ক sh_অঙ্ক, পূর্ণাঙ্ক sym_bind, পূর্ণাঙ্ক sym_type)
{
    যদি (!(s1->do_debug & 2))
        ঘূৰাই;

    যদি (sym_type == STT_FUNC || sym->v >= SYM_FIRST_ANOM)
        ঘূৰাই;
    যদি (s1->dwarf) {
        পূর্ণাঙ্ক debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, রিক্ত));
	dwarf_uleb128(dwarf_info_section, dwarf_সাৰি.cur_file);
	dwarf_uleb128(dwarf_info_section, file->সাৰি_অঙ্ক);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	যদি (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->data_offset,
		R_DATA_PTR, 0);
#যদি PTR_SIZE == 4
	dwarf_data4(dwarf_info_section, 0);
#অন্যথা
	dwarf_data8(dwarf_info_section, 0);
#endif
    }
    অন্যথা
    {
        Section *s = sh_অঙ্ক == SHN_COMMON ? common_section
					  : s1->sections[sh_অঙ্ক];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, রিক্ত),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        যদি (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.data, N_GSYM, 0, রিক্ত, 0, 0);
        অন্যথা
            tcc_debug_stabs(s1, str.data,
                (sym->type.t & VT_STATIC) && data_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC শূন্য tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    যদি (!(s1->do_debug & 2))
        ঘূৰাই;

    যদি (s1->dwarf) {
	পূর্ণাঙ্ক debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	যদি (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, রিক্ত));
	    dwarf_uleb128(dwarf_info_section, dwarf_সাৰি.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->সাৰি_অঙ্ক);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	}
    }
    অন্যথা
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, রিক্ত));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.data, N_LSYM, 0, রিক্ত, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC শূন্য tcc_tcov_block_end(TCCState *s1, পূর্ণাঙ্ক সাৰি);

ST_FUNC শূন্য tcc_tcov_block_begin(TCCState *s1)
{
    SValue sv;
    শূন্য *ptr;
    unsigned long last_offset = tcov_data.offset;

    tcc_tcov_block_end (tcc_state, 0);
    যদি (s1->test_coverage == 0 || nocode_wanted)
	ঘূৰাই;

    যদি (tcov_data.last_file_name == 0 ||
	strcmp ((ধ্রুৱ ৱর্ণ *)(tcov_section->data + tcov_data.last_file_name),
		file->true_filename) != 0) {
	ৱর্ণ wd[1024];
	CString cstr;

	যদি (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	যদি (tcov_data.last_file_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = 0;
	cstr_new (&cstr);
	যদি (file->true_filename[0] == '/') {
	    tcov_data.last_file_name = tcov_section->data_offset;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	অন্যথা {
	    getcwd (wd, পরিমাণ(wd));
	    tcov_data.last_file_name = tcov_section->data_offset + strlen(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_add(tcov_section, cstr.size + 1);
	strcpy((ৱর্ণ *)ptr, cstr.data);
#ifdef _WIN32
        normalize_slashes((ৱর্ণ *)ptr);
#endif
	cstr_free (&cstr);
    }
    যদি (tcov_data.last_func_name == 0 ||
	strcmp ((ধ্রুৱ ৱর্ণ *)(tcov_section->data + tcov_data.last_func_name),
		funcname) != 0) {
	size_t len;

	যদি (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = tcov_section->data_offset;
	len = strlen (funcname);
	ptr = section_ptr_add(tcov_section, len + 1);
	strcpy((ৱর্ণ *)ptr, funcname);
	section_ptr_add(tcov_section, -tcov_section->data_offset & 7);
	ptr = section_ptr_add(tcov_section, 8);
	write64le (ptr, file->সাৰি_অঙ্ক);
    }
    যদি (ind == tcov_data.ind && tcov_data.সাৰি == file->সাৰি_অঙ্ক)
        tcov_data.offset = last_offset;
    অন্যথা {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_add(tcov_section, 16);
        tcov_data.সাৰি = file->সাৰি_অঙ্ক;
        write64le (ptr, (tcov_data.সাৰি << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((unsigned ৱর্ণ *)ptr - tcov_section->data) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#যদি defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || \
    defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || \
    defined TCC_TARGET_RISCV64
        gen_increment_tcov (&sv);
#অন্যথা
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#endif
        tcov_data.offset = (unsigned ৱর্ণ *)ptr - tcov_section->data;
        tcov_data.ind = ind;
    }
}

ST_FUNC শূন্য tcc_tcov_block_end(TCCState *s1, পূর্ণাঙ্ক সাৰি)
{
    যদি (s1->test_coverage == 0)
	ঘূৰাই;
    যদি (সাৰি == -1)
        সাৰি = tcov_data.সাৰি;
    যদি (tcov_data.offset) {
	শূন্য *ptr = tcov_section->data + tcov_data.offset;
	unsigned long long nline = সাৰি ? সাৰি : file->সাৰি_অঙ্ক;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_data.offset = 0;
    }
}

ST_FUNC শূন্য tcc_tcov_check_সাৰি(TCCState *s1, পূর্ণাঙ্ক start)
{
    যদি (s1->test_coverage == 0)
	ঘূৰাই;
    যদি (tcov_data.সাৰি != file->সাৰি_অঙ্ক) {
        যদি ((tcov_data.সাৰি + 1) != file->সাৰি_অঙ্ক) {
	    tcc_tcov_block_end (s1, -1);
	    যদি (start)
                tcc_tcov_block_begin (s1);
	}
	অন্যথা
	    tcov_data.সাৰি = file->সাৰি_অঙ্ক;
    }
}

ST_FUNC শূন্য tcc_tcov_start(TCCState *s1)
{
    যদি (s1->test_coverage == 0)
	ঘূৰাই;
    যদি (!s1->dState)
        s1->dState = tcc_mallocz(পরিমাণ *s1->dState);
    memset (&tcov_data, 0, পরিমাণ (tcov_data));
    যদি (tcov_section == রিক্ত) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_add(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC শূন্য tcc_tcov_end(TCCState *s1)
{
    যদি (s1->test_coverage == 0)
	ঘূৰাই;
    যদি (tcov_data.last_func_name)
        section_ptr_add(tcov_section, 1);
    যদি (tcov_data.last_file_name)
        section_ptr_add(tcov_section, 1);
}

ST_FUNC শূন্য tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_data.ind = 0;
}

/* ------------------------------------------------------------------------- */
#undef last_সাৰি_অঙ্ক
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
#undef debug_info_মূল
#undef dwarf_sym
#undef dwarf_সাৰি
#undef dwarf_info
#undef dwarf_str
#undef dwarf_সাৰি_str
#undef tcov_data
