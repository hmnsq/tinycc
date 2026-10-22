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

#অন্তর্ভাব "tcc.h"

/* stab debug support */

স্থির ধ্রুবক কাঠামো {
  পূর্ণসংখ্যা type;
  পূর্ণসংখ্যা আকার_2;
  পূর্ণসংখ্যা encoding;
  ধ্রুবক অক্ষর *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#যদি LONG_আকার == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#অন্যথা
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#endif
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#যদি LONG_আকার == 4
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
#যদি LONG_আকার == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#অন্যথা
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#endif
};

#define	N_DEFAULT_DEBUG	(আকার (default_debug) / আকার (default_debug[0]))

/* dwarf debug */

#define	DWARF_সারি_BASE				-5
#define	DWARF_সারি_RANGE			14
#define	DWARF_OPCODE_BASE			13

#যদি defined TCC_TARGET_ARM64
#define	DWARF_MIN_INSTR_LEN			4
#নতুবা_যদি defined TCC_TARGET_ARM
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
স্থির ধ্রুবক unsigned অক্ষর dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_TAG_compile_unit, 1,
          DW_AT_producer, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_সারি_strp,
          DW_AT_comp_dir, DW_FORM_সারি_strp,
          DW_AT_নিচের_pc, DW_FORM_addr,
#যদি PTR_আকার == 4
          DW_AT_উপরের_pc, DW_FORM_data4,
#অন্যথা
          DW_AT_উপরের_pc, DW_FORM_data8,
#endif
          DW_AT_stmt_list, DW_FORM_sec_offset,
          0, 0,
    DWARF_ABBREV_BASE_TYPE, DW_TAG_base_type, 0,
          DW_AT_byte_আকার, DW_FORM_udata,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_name, DW_FORM_strp,
          0, 0,
    DWARF_ABBREV_VARIABLE_EXTERNAL, DW_TAG_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সারি, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_TAG_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সারি, DW_FORM_udata,
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
          DW_AT_byte_আকার, DW_FORM_data1,
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
          DW_AT_decl_সারি, DW_FORM_udata,
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
          DW_AT_byte_আকার, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সারি, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সারি, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_তথ্য_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সারি, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_bit_আকার, DW_FORM_udata,
          DW_AT_তথ্য_bit_offset, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_TAG_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_আকার, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সারি, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_EMPTY_TYPE, DW_TAG_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_আকার, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সারি, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_TAG_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_আকার, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সারি, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_EMPTY_TYPE, DW_TAG_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_আকার, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সারি, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_TAG_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সারি, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_নিচের_pc, DW_FORM_addr,
#যদি PTR_আকার == 4
          DW_AT_উপরের_pc, DW_FORM_data4,
#অন্যথা
          DW_AT_উপরের_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_TAG_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_সারি, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_নিচের_pc, DW_FORM_addr,
#যদি PTR_আকার == 4
          DW_AT_উপরের_pc, DW_FORM_data4,
#অন্যথা
          DW_AT_উপরের_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_BLOCK, DW_TAG_lexical_block, 1,
          DW_AT_নিচের_pc, DW_FORM_addr,
#যদি PTR_আকার == 4
          DW_AT_উপরের_pc, DW_FORM_data4,
#অন্যথা
          DW_AT_উপরের_pc, DW_FORM_data8,
#endif
          0, 0,
    DWARF_ABBREV_LEXICAL_EMPTY_BLOCK, DW_TAG_lexical_block, 0,
          DW_AT_নিচের_pc, DW_FORM_addr,
#যদি PTR_আকার == 4
          DW_AT_উপরের_pc, DW_FORM_data4,
#অন্যথা
          DW_AT_উপরের_pc, DW_FORM_data8,
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

স্থির ধ্রুবক unsigned অক্ষর dwarf_সারি_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#define N_STR_HASH (251)

কাঠামো dwarf_str_hash {
    পূর্ণসংখ্যা len;
    unsigned long তথ্য_offset;
    কাঠামো dwarf_str_hash *পরবর্তী;
};

কাঠামো _tccdbg {

    পূর্ণসংখ্যা last_সারি_অঙ্ক, new_file;
    পূর্ণসংখ্যা section_sym;

    পূর্ণসংখ্যা debug_পরবর্তী_type;

    কাঠামো _debug_hash {
        পূর্ণসংখ্যা debug_type;
        Sym *type;
    } *debug_hash_global, *debug_hash_local;

    /* store forward structure/unions types */
    কাঠামো _debug_forw_hash {
        Sym *type;
        পূর্ণসংখ্যা n_debug_type;
        পূর্ণসংখ্যা *debug_type;
    } *debug_forw_hash_global, *debug_forw_hash_local;

    পূর্ণসংখ্যা n_debug_hash_global;
    পূর্ণসংখ্যা n_debug_hash_local;
    পূর্ণসংখ্যা n_debug_forw_hash_global;
    পূর্ণসংখ্যা n_debug_forw_hash_local;

    কাঠামো _debug_info {
        পূর্ণসংখ্যা start;
        পূর্ণসংখ্যা end;
        পূর্ণসংখ্যা last_debug_hash;
        পূর্ণসংখ্যা last_debug_forw_hash;
        পূর্ণসংখ্যা n_sym;
        কাঠামো debug_sym {
            পূর্ণসংখ্যা type;
            unsigned long মান;
            অক্ষর *str;
            Section *sec;
            পূর্ণসংখ্যা sym_সূচক;
            পূর্ণসংখ্যা info;
            পূর্ণসংখ্যা file;
            পূর্ণসংখ্যা সারি;
        } *sym;
        কাঠামো _debug_info *child, *পরবর্তী, *last, *parent;
    } *debug_info, *debug_info_মূল;

    কাঠামো {
        পূর্ণসংখ্যা info;
        পূর্ণসংখ্যা abbrev;
        পূর্ণসংখ্যা সারি;
        পূর্ণসংখ্যা str;
        পূর্ণসংখ্যা সারি_str;
    } dwarf_sym;

    কাঠামো {
        পূর্ণসংখ্যা start;
        পূর্ণসংখ্যা dir_আকার;
        অক্ষর **dir_table;
        পূর্ণসংখ্যা filename_আকার;
        কাঠামো dwarf_filename_struct {
            পূর্ণসংখ্যা dir_entry;
            অক্ষর *name;
        } *filename_table;
        পূর্ণসংখ্যা সারি_আকার;
        পূর্ণসংখ্যা সারি_max_আকার;
        unsigned অক্ষর *সারি_তথ্য;
        পূর্ণসংখ্যা cur_file;
        পূর্ণসংখ্যা last_file;
        পূর্ণসংখ্যা last_pc;
        পূর্ণসংখ্যা last_সারি;
    } dwarf_সারি;

    কাঠামো {
        পূর্ণসংখ্যা start;
        Sym *func;
        পূর্ণসংখ্যা সারি;
        পূর্ণসংখ্যা base_type_used[N_DEFAULT_DEBUG];
    } dwarf_info;

    কাঠামো dwarf_str_hash *dwarf_str[N_STR_HASH];
    কাঠামো dwarf_str_hash *dwarf_সারি_str[N_STR_HASH];

    /* test coverage */
    কাঠামো {
        unsigned long offset;
        unsigned long last_file_name;
        unsigned long last_func_name;
        পূর্ণসংখ্যা ind;
        পূর্ণসংখ্যা সারি;
    } tcov_তথ্য;
};

#define last_সারি_অঙ্ক             s1->dState->last_সারি_অঙ্ক
#define new_file                  s1->dState->new_file
#define section_sym               s1->dState->section_sym
#define debug_পরবর্তী_type           s1->dState->debug_পরবর্তী_type
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
#define dwarf_সারি                s1->dState->dwarf_সারি
#define dwarf_info                s1->dState->dwarf_info
#define dwarf_str                 s1->dState->dwarf_str
#define dwarf_সারি_str            s1->dState->dwarf_সারি_str
#define tcov_তথ্য                 s1->dState->tcov_তথ্য

#define	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
স্থির পূর্ণসংখ্যা put_stabs(TCCState *s1, ধ্রুবক অক্ষর *str, পূর্ণসংখ্যা type, পূর্ণসংখ্যা other,
    পূর্ণসংখ্যা desc, unsigned long মান);

ST_FUNC শূন্য tcc_debug_new(TCCState *s1)
{
    পূর্ণসংখ্যা shf = 0;
    যদি (!s1->dState)
        s1->dState = tcc_mallocz(আকার *s1->dState);

#ifdef CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    যদি (s1->do_debug && s1->output_type == TCC_OUTPUT_MEMORY)
        s1->do_backtrace = 1;
    যদি (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#endif

    যদি (s1->dwarf) {
	পূর্ণসংখ্যা i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	স্থির ধ্রুবক অক্ষর *ধ্রুবক debug[] = {
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
        dwarf_সারি_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	জন্য (i = 0; i < আকার(debug)/আকার(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_MERGE | SHF_STRINGS;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_সারি_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	যদি (s1->dwarf >= 5) {
            dwarf_সারি_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_সারি_str_section->sh_entsize = 1;
	    dwarf_সারি_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    অন্যথা
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = আকার(Stab_Sym);
        stab_section->sh_addralign = আকার ((Stab_Sym*)0)->n_মান;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
স্থির পূর্ণসংখ্যা put_stabs(TCCState *s1, ধ্রুবক অক্ষর *str, পূর্ণসংখ্যা type, পূর্ণসংখ্যা other, পূর্ণসংখ্যা desc,
                      unsigned long মান)
{
    Stab_Sym *sym;

    unsigned offset;
    যদি (type == N_SLINE
        && (offset = stab_section->তথ্য_offset)
        && (sym = (Stab_Sym*)(stab_section->তথ্য + offset) - 1)
        && sym->n_type == type
        && sym->n_মান == মান) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        ফেরত 0;
    }

    sym = section_ptr_add(stab_section, আকার(Stab_Sym));
    যদি (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } অন্যথা {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_মান = মান;
    ফেরত 1;
}

স্থির শূন্য put_stabs_r(TCCState *s1, ধ্রুবক অক্ষর *str, পূর্ণসংখ্যা type, পূর্ণসংখ্যা other, পূর্ণসংখ্যা desc,
                        unsigned long মান, Section *sec, পূর্ণসংখ্যা sym_সূচক)
{
    যদি (put_stabs(s1, str, type, other, desc, মান))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->তথ্য_offset - 4,
                      আকার ((Stab_Sym*)0)->n_মান == PTR_আকার ? R_তথ্য_PTR : R_তথ্য_32,
                      sym_সূচক);
}

স্থির শূন্য put_stabn(TCCState *s1, পূর্ণসংখ্যা type, পূর্ণসংখ্যা other, পূর্ণসংখ্যা desc, পূর্ণসংখ্যা মান)
{
    put_stabs(s1, ফাঁকা, type, other, desc, মান);
}

/* ------------------------------------------------------------------------- */
#define	dwarf_data1(s,তথ্য) \
	(*(uint8_t*)section_ptr_add((s), 1) = (তথ্য))
#define	dwarf_data2(s,তথ্য) \
	write16le(section_ptr_add((s), 2), (তথ্য))
#define	dwarf_data4(s,তথ্য) \
	write32le(section_ptr_add((s), 4), (তথ্য))
#define	dwarf_data8(s,তথ্য) \
	write64le(section_ptr_add((s), 8), (তথ্য))

স্থির পূর্ণসংখ্যা dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    ফেরত put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_অঙ্ক, ফাঁকা);
}

স্থির শূন্য dwarf_reloc(Section *s, পূর্ণসংখ্যা sym, পূর্ণসংখ্যা rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->তথ্য_offset, rel, sym, 0);
}

স্থির শূন্য free_str(কাঠামো dwarf_str_hash **str)
{
    পূর্ণসংখ্যা i;

    জন্য (i = 0; i < N_STR_HASH; i++) {
       যখন (str[i]) {
           কাঠামো dwarf_str_hash *পরবর্তী = str[i]->পরবর্তী;

           tcc_free(str[i]);
           str[i] = পরবর্তী;
       }
    }
}

স্থির unsigned str_hash(ধ্রুবক অক্ষর *s)
{
    unsigned h = 5381;

    যখন (*s)
       h += (*s++ & 0xffu) + h * 31;
    ফেরত h;
}

স্থির শূন্য dwarf_string(Section *s, Section *dw, পূর্ণসংখ্যা sym, ধ্রুবক অক্ষর *str)
{
    TCCState *s1 = s->s1;
    পূর্ণসংখ্যা len, hash = str_hash(str) % N_STR_HASH;
    অক্ষর *ptr;
    কাঠামো dwarf_str_hash *new_hash;
    কাঠামো dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_সারি_str;

    len = strlen(str) + 1;
    new_hash = dw_hash[hash];
    যখন (new_hash) {
	যদি (new_hash->len == len &&
	    !memcmp(str, dw->তথ্য + new_hash->তথ্য_offset, len))
	    বিরতি;
	new_hash = new_hash->পরবর্তী;
    }
    যদি (new_hash == ফাঁকা) {
	unsigned long offset = dw->তথ্য_offset;

        new_hash = dw_hash[hash];
        যখন (new_hash) {
	    unsigned long n = new_hash->তথ্য_offset + new_hash->len - len;

	    যদি (new_hash->len > len &&
	        !memcmp(str, dw->তথ্য + n, len)) {
		offset = n;
		বিরতি;
	    }
	    new_hash = new_hash->পরবর্তী;
        }
	যদি (new_hash == ফাঁকা) {
	    ptr = section_ptr_add(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (কাঠামো dwarf_str_hash *)
	    tcc_malloc(আকার(কাঠামো dwarf_str_hash));
	new_hash->len = len;
	new_hash->তথ্য_offset = offset;
	new_hash->পরবর্তী = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->তথ্য_offset, R_তথ্য_32_DW, sym,
                   PTR_আকার == 4 ? 0 : new_hash->তথ্য_offset);
    dwarf_data4(s, PTR_আকার == 4 ? new_hash->তথ্য_offset : 0);
}

স্থির শূন্য dwarf_strp(Section *s, ধ্রুবক অক্ষর *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

স্থির শূন্য dwarf_সারি_strp(Section *s, ধ্রুবক অক্ষর *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_সারি_str_section, dwarf_sym.সারি_str, str);
}

স্থির শূন্য dwarf_সারি_op(TCCState *s1, unsigned অক্ষর op)
{
    যদি (dwarf_সারি.সারি_আকার >= dwarf_সারি.সারি_max_আকার) {
	dwarf_সারি.সারি_max_আকার += 1024;
	dwarf_সারি.সারি_তথ্য =
	    (unsigned অক্ষর *)tcc_realloc(dwarf_সারি.সারি_তথ্য,
					 dwarf_সারি.সারি_max_আকার);
    }
    dwarf_সারি.সারি_তথ্য[dwarf_সারি.সারি_আকার++] = op;
}

স্থির শূন্য dwarf_file(TCCState *s1)
{
    পূর্ণসংখ্যা i, j;
    অক্ষর *filename;
    পূর্ণসংখ্যা সূচক_offset = s1->dwarf < 5;

    যদি (!strcmp(file->filename, "<command line>")) {
        dwarf_সারি.cur_file = 1;
	ফেরত;
    }
    filename = strrchr(file->filename, '/');
    যদি (filename == ফাঁকা) {
        জন্য (i = 1; i < dwarf_সারি.filename_আকার; i++)
            যদি (dwarf_সারি.filename_table[i].dir_entry == 0 &&
		strcmp(dwarf_সারি.filename_table[i].name,
		       file->filename) == 0) {
		    dwarf_সারি.cur_file = i + সূচক_offset;
	            ফেরত;
		}
	i = -সূচক_offset;
	filename = file->filename;
    }
    অন্যথা {
	অক্ষর *undo = filename;
	অক্ষর *dir = file->filename;

	*filename++ = '\0';
        জন্য (i = 0; i < dwarf_সারি.dir_আকার; i++)
	    যদি (strcmp(dwarf_সারি.dir_table[i], dir) == 0) {
		জন্য (j = 1; j < dwarf_সারি.filename_আকার; j++)
		    যদি (dwarf_সারি.filename_table[j].dir_entry - সূচক_offset
			== i &&
			strcmp(dwarf_সারি.filename_table[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_সারি.cur_file = j + সূচক_offset;
			ফেরত;
		    }
		বিরতি;
	    }
	যদি (i == dwarf_সারি.dir_আকার) {
	    dwarf_সারি.dir_আকার++;
	    dwarf_সারি.dir_table =
                (অক্ষর **) tcc_realloc(dwarf_সারি.dir_table,
                                      dwarf_সারি.dir_আকার *
                                      আকার (অক্ষর *));
            dwarf_সারি.dir_table[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_সারি.filename_table =
        (কাঠামো dwarf_filename_struct *)
        tcc_realloc(dwarf_সারি.filename_table,
                    (dwarf_সারি.filename_আকার + 1) *
                    আকার (কাঠামো dwarf_filename_struct));
    dwarf_সারি.filename_table[dwarf_সারি.filename_আকার].dir_entry =
	i + সূচক_offset;
    dwarf_সারি.filename_table[dwarf_সারি.filename_আকার].name =
        tcc_strdup(filename);
    dwarf_সারি.cur_file = dwarf_সারি.filename_আকার++ + সূচক_offset;
    ফেরত;
}

#যদি 0
স্থির পূর্ণসংখ্যা dwarf_uleb128_আকার (unsigned long long মান)
{
    পূর্ণসংখ্যা আকার_2 =  0;

    করো {
        মান >>= 7;
        আকার_2++;
    } যখন (মান != 0);
    ফেরত আকার_2;
}
#endif

স্থির পূর্ণসংখ্যা dwarf_sleb128_আকার (long long মান)
{
    পূর্ণসংখ্যা আকার_2 =  0;
    long long end = মান >> 63;
    unsigned অক্ষর last = end & 0x40;
    unsigned অক্ষর byte;

    করো {
        byte = মান & 0x7f;
        মান >>= 7;
        আকার_2++;
    } যখন (মান != end || (byte & 0x40) != last);
    ফেরত আকার_2;
}

স্থির শূন্য dwarf_uleb128 (Section *s, unsigned long long মান)
{
    করো {
        unsigned অক্ষর byte = মান & 0x7f;

        মান >>= 7;
        dwarf_data1(s, byte | (মান ? 0x80 : 0));
    } যখন (মান != 0);
}

স্থির শূন্য dwarf_sleb128 (Section *s, long long মান)
{
    পূর্ণসংখ্যা more;
    long long end = মান >> 63;
    unsigned অক্ষর last = end & 0x40;

    করো {
        unsigned অক্ষর byte = মান & 0x7f;

        মান >>= 7;
	more = মান != end || (byte & 0x40) != last;
        dwarf_data1(s, byte | (0x80 * more));
    } যখন (more);
}

স্থির শূন্য dwarf_uleb128_op (TCCState *s1, unsigned long long মান)
{
    করো {
        unsigned অক্ষর byte = মান & 0x7f;

        মান >>= 7;
        dwarf_সারি_op(s1, byte | (মান ? 0x80 : 0));
    } যখন (মান != 0);
}

স্থির শূন্য dwarf_sleb128_op (TCCState *s1, long long মান)
{
    পূর্ণসংখ্যা more;
    long long end = মান >> 63;
    unsigned অক্ষর last = end & 0x40;

    করো {
        unsigned অক্ষর byte = মান & 0x7f;

        মান >>= 7;
        more = মান != end || (byte & 0x40) != last;
        dwarf_সারি_op(s1, byte | (0x80 * more));
    } যখন (more);
}

#যদি TCC_EH_FRAME
ST_FUNC শূন্য tcc_eh_frame_start(TCCState *s1)
{
    যদি (!s1->unwind_tables)
        ফেরত;
    eh_frame_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_start = eh_frame_section->তথ্য_offset;
    dwarf_data4(eh_frame_section, 0); //দৈর্ঘ্য
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
#নতুবা_যদি defined TCC_TARGET_X86_64
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
#নতুবা_যদি defined TCC_TARGET_ARM
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
#নতুবা_যদি defined TCC_TARGET_ARM64
    dwarf_uleb128(eh_frame_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 30); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 31); // x31 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#নতুবা_যদি defined TCC_TARGET_RISCV64
    eh_frame_section->তথ্য[s1->eh_start + 8] = 3; // version = 3
    dwarf_uleb128(eh_frame_section, 1); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -4); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 1); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 2); // r2 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#endif
    যখন ((eh_frame_section->তথ্য_offset - s1->eh_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->তথ্য + s1->eh_start, //দৈর্ঘ্য
	      eh_frame_section->তথ্য_offset - s1->eh_start - 4);
}

স্থির শূন্য tcc_debug_frame_end(TCCState *s1, পূর্ণসংখ্যা আকার_2)
{
    পূর্ণসংখ্যা eh_section_sym;
    unsigned long fde_start;

    যদি (!eh_frame_section)
	ফেরত;
    eh_section_sym = dwarf_get_section_sym(text_section);
    fde_start = eh_frame_section->তথ্য_offset;
    dwarf_data4(eh_frame_section, 0); //দৈর্ঘ্য
    dwarf_data4(eh_frame_section,
		fde_start - s1->eh_start + 4); // CIE Pointer
#যদি defined TCC_TARGET_I386
    dwarf_reloc(eh_frame_section, eh_section_sym, R_386_PC32);
#নতুবা_যদি defined TCC_TARGET_X86_64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_X86_64_PC32);
#নতুবা_যদি defined TCC_TARGET_ARM
    dwarf_reloc(eh_frame_section, eh_section_sym, R_ARM_REL32);
#নতুবা_যদি defined TCC_TARGET_ARM64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_AARCH64_PREL32);
#নতুবা_যদি defined TCC_TARGET_RISCV64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_RISCV_32_PCREL);
#endif
    dwarf_data4(eh_frame_section, func_ind); // PC Begin
    dwarf_data4(eh_frame_section, আকার_2); // PC Range
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
    dwarf_data4(eh_frame_section, আকার_2 - 5);
    dwarf_data1(eh_frame_section, DW_CFA_restore + 5); // r5 (ebp)
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 4); // r4 (esp)
    dwarf_uleb128(eh_frame_section, 4); // ofs 4
#নতুবা_যদি defined TCC_TARGET_X86_64
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 1);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 16);
    dwarf_data1(eh_frame_section, DW_CFA_offset + 6); // r6 (rbp)
    dwarf_uleb128(eh_frame_section, 2); // cfa-16
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 3);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_register);
    dwarf_uleb128(eh_frame_section, 6); // r6 (rbp)
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_frame_section, আকার_2 - 5);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 7); // r7 (rsp)
    dwarf_uleb128(eh_frame_section, 8); // ofs 8
#নতুবা_যদি defined TCC_TARGET_ARM
    /* TODO */
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc + 2);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 8);
    dwarf_data1(eh_frame_section, DW_CFA_offset + 14); // r14 (lr)
    dwarf_uleb128(eh_frame_section, 1);
    dwarf_data1(eh_frame_section, DW_CFA_offset + 11); // r11 (fp)
    dwarf_uleb128(eh_frame_section, 2);
    dwarf_data1(eh_frame_section, DW_CFA_advance_loc4);
    dwarf_data4(eh_frame_section, আকার_2 / 2 - 5);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_register);
    dwarf_uleb128(eh_frame_section, 11); // r11 (fp)
#নতুবা_যদি defined TCC_TARGET_ARM64
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
    dwarf_data4(eh_frame_section, আকার_2 / 4 - 5);
    dwarf_data1(eh_frame_section, DW_CFA_restore + 30); // x30 (lr)
    dwarf_data1(eh_frame_section, DW_CFA_restore + 29); // x29 (fp)
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa_offset);
    dwarf_uleb128(eh_frame_section, 0);
#নতুবা_যদি defined TCC_TARGET_RISCV64
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
    যখন (আকার_2 >= 4 &&
	   read32le(cur_text_section->তথ্য + func_ind + আকার_2 - 4) != 0x00008067)
	আকার_2 -= 4;
    dwarf_data4(eh_frame_section, আকার_2 - 36);
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
    যখন ((eh_frame_section->তথ্য_offset - fde_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->তথ্য + fde_start, //দৈর্ঘ্য
	      eh_frame_section->তথ্য_offset - fde_start - 4);
}

ST_FUNC শূন্য tcc_eh_frame_end(TCCState *s1)
{
    যদি (!eh_frame_section)
	ফেরত;
    dwarf_data4(eh_frame_section, 0);
}

কাঠামো eh_অনুসন্ধান_table {
    uint32_t pc_offset;
    uint32_t fde_offset;
};

স্থির পূর্ণসংখ্যা sort_eh_table(ধ্রুবক শূন্য *a, ধ্রুবক শূন্য *b)
{
    uint32_t pc1 = ((ধ্রুবক কাঠামো eh_অনুসন্ধান_table *)a)->pc_offset;
    uint32_t pc2 = ((ধ্রুবক কাঠামো eh_অনুসন্ধান_table *)b)->pc_offset;

    ফেরত pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC শূন্য tcc_eh_frame_hdr(TCCState *s1, পূর্ণসংখ্যা final)
{
    পূর্ণসংখ্যা গুনতি_2 = 0, offset;
    unsigned long গুনতি_offset, tab_offset;
    unsigned অক্ষর *ln, *end;
    unsigned পূর্ণসংখ্যা last_cie_offset = 0xffffffff;

    যদি (!eh_frame_section || !eh_frame_section->তথ্য_offset)
	ফেরত;
    যদি (final && !eh_frame_hdr_section)
	ফেরত;
    যদি (final == 0)
        eh_frame_hdr_section =
	    new_section(s1, ".eh_frame_hdr", SHT_PROGBITS, SHF_ALLOC);
    eh_frame_hdr_section->তথ্য_offset = 0;
    dwarf_data1(eh_frame_hdr_section, 1); // Version
    // Pointer Encoding Format
    dwarf_data1(eh_frame_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_pcrel);
    // Count Encoding Format
    dwarf_data1(eh_frame_hdr_section, DW_EH_PE_udata4 | DW_EH_PE_absptr);
    // Table Encoding Format
    dwarf_data1(eh_frame_hdr_section, DW_EH_PE_sdata4 | DW_EH_PE_datarel);
    offset = eh_frame_section->sh_addr -
             eh_frame_hdr_section->sh_addr -
             eh_frame_hdr_section->তথ্য_offset;
    dwarf_data4(eh_frame_hdr_section, offset); // eh_frame_ptr
    //গুনতি
    গুনতি_offset = eh_frame_hdr_section->তথ্য_offset;
    dwarf_data4(eh_frame_hdr_section, 0);
    tab_offset = eh_frame_hdr_section->তথ্য_offset;
    ln = eh_frame_section->তথ্য;
    end = eh_frame_section->তথ্য + eh_frame_section->তথ্য_offset;
    যখন (ln < end) {
	unsigned অক্ষর *fde = ln, *rd = ln;
	unsigned পূর্ণসংখ্যা cie_offset, version, দৈর্ঘ্য = dwarf_read_4(rd, end);
	unsigned পূর্ণসংখ্যা pc_offset, fde_offset;

	যদি (দৈর্ঘ্য == 0)
	    যাও পরবর্তী;
        cie_offset = dwarf_read_4(rd, end);
	যদি (cie_offset == 0)
	    যাও পরবর্তী;
	যদি (cie_offset != last_cie_offset) {
	    unsigned অক্ষর *cie = rd - cie_offset + 4;

	    যদি (cie < eh_frame_section->তথ্য)
		যাও পরবর্তী;
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
		    যাও পরবর্তী;
	    }
	    অন্যথা
		যাও পরবর্তী;
	}
	গুনতি_2++;
	fde_offset = eh_frame_section->sh_addr +
		     (fde - eh_frame_section->তথ্য) -
		     eh_frame_hdr_section->sh_addr;
	pc_offset = dwarf_read_4(rd, end) + fde_offset + 8;
	dwarf_data4(eh_frame_hdr_section, pc_offset);
	dwarf_data4(eh_frame_hdr_section, fde_offset);
পরবর্তী:
	ln += দৈর্ঘ্য + 4;
    }
    add32le(eh_frame_hdr_section->তথ্য + গুনতি_offset, গুনতি_2);
    qsort(eh_frame_hdr_section->তথ্য + tab_offset, গুনতি_2,
	  আকার(কাঠামো eh_অনুসন্ধান_table), sort_eh_table);
}
#endif

/* start of translation unit info */
ST_FUNC শূন্য tcc_debug_start(TCCState *s1)
{
    পূর্ণসংখ্যা i;
    অক্ষর buf[512];
    অক্ষর *filename;

    /* we might currently #include the <command-line> */
    filename = file->পূর্ব ? file->পূর্ব->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    যদি (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, text_section->তথ্য_offset, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            text_section->sh_অঙ্ক, "$a");

        new_file = last_সারি_অঙ্ক = 0;
        debug_পরবর্তী_type = N_DEFAULT_DEBUG;
        debug_hash_global = ফাঁকা;
        debug_hash_local = ফাঁকা;
        debug_forw_hash_global = ফাঁকা;
        debug_forw_hash_local = ফাঁকা;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, আকার(buf));
#ifdef _WIN32
        normalize_slashes(buf);
#endif

        যদি (s1->dwarf) {
            পূর্ণসংখ্যা start_abbrev;
            unsigned অক্ষর *ptr;
	    অক্ষর *undo;

            /* dwarf_abbrev */
            start_abbrev = dwarf_abbrev_section->তথ্য_offset;
            ptr = section_ptr_add(dwarf_abbrev_section, আকার(dwarf_abbrev_init));
            memcpy(ptr, dwarf_abbrev_init, আকার(dwarf_abbrev_init));

            যদি (s1->dwarf < 5) {
    	        যখন (*ptr) {
    	            ptr += 3;
    	            যখন (*ptr) {
    	                যদি (ptr[1] == DW_FORM_সারি_strp)
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
            dwarf_sym.সারি = dwarf_get_section_sym(dwarf_সারি_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            যদি (tcc_state->dwarf >= 5)
    	        dwarf_sym.সারি_str = dwarf_get_section_sym(dwarf_সারি_str_section);
            অন্যথা {
    	        dwarf_সারি_str_section = dwarf_str_section;
                dwarf_sym.সারি_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(text_section);

            /* dwarf_info */
            dwarf_info.start = dwarf_info_section->তথ্য_offset;
            dwarf_data4(dwarf_info_section, 0); //আকার
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            যদি (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_আকার);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_তথ্য_32_DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
            }
            অন্যথা {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_তথ্য_32_DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
                dwarf_data1(dwarf_info_section, PTR_আকার);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_VERSION);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_সারি_strp(dwarf_info_section, filename);
            dwarf_সারি_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_তথ্য_PTR);
#যদি PTR_আকার == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#অন্যথা
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#endif
            dwarf_reloc(dwarf_info_section, dwarf_sym.সারি, R_তথ্য_32_DW);
            dwarf_data4(dwarf_info_section, dwarf_সারি_section->তথ্য_offset); // stmt_list

            /* dwarf_line */
            dwarf_সারি.start = dwarf_সারি_section->তথ্য_offset;
            dwarf_data4(dwarf_সারি_section, 0); //দৈর্ঘ্য
            dwarf_data2(dwarf_সারি_section, s1->dwarf); // version
            যদি (s1->dwarf >= 5) {
                dwarf_data1(dwarf_সারি_section, PTR_আকার); // address size
                dwarf_data1(dwarf_সারি_section, 0); // segment selector
            }
            dwarf_data4(dwarf_সারি_section, 0); // prologue Length
            dwarf_data1(dwarf_সারি_section, DWARF_MIN_INSTR_LEN);
            যদি (s1->dwarf >= 4)
                dwarf_data1(dwarf_সারি_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_সারি_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_সারি_section, DWARF_সারি_BASE);
            dwarf_data1(dwarf_সারি_section, DWARF_সারি_RANGE);
            dwarf_data1(dwarf_সারি_section, DWARF_OPCODE_BASE);
            ptr = section_ptr_add(dwarf_সারি_section, আকার(dwarf_সারি_opcodes));
            memcpy(ptr, dwarf_সারি_opcodes, আকার(dwarf_সারি_opcodes));
	    undo = strrchr(filename, '/');
	    যদি (undo)
		*undo = 0;
            dwarf_সারি.dir_আকার = 1 + (undo != ফাঁকা);
            dwarf_সারি.dir_table = (অক্ষর **) tcc_malloc(আকার (অক্ষর *) *
							dwarf_সারি.dir_আকার);
            dwarf_সারি.dir_table[0] = tcc_strdup(buf);
	    যদি (undo)
                dwarf_সারি.dir_table[1] = tcc_strdup(filename);
            dwarf_সারি.filename_আকার = 2;
            dwarf_সারি.filename_table =
    	        (কাঠামো dwarf_filename_struct *)
    	        tcc_malloc(2*আকার (কাঠামো dwarf_filename_struct));
            dwarf_সারি.filename_table[0].dir_entry = 0;
	    যদি (undo) {
                dwarf_সারি.filename_table[0].name = tcc_strdup(undo + 1);
                dwarf_সারি.filename_table[1].dir_entry = 1;
                dwarf_সারি.filename_table[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    অন্যথা {
                dwarf_সারি.filename_table[0].name = tcc_strdup(filename);
                dwarf_সারি.filename_table[1].dir_entry = 0;
                dwarf_সারি.filename_table[1].name = tcc_strdup(filename);
	    }
            dwarf_সারি.সারি_আকার = dwarf_সারি.সারি_max_আকার = 0;
            dwarf_সারি.সারি_তথ্য = ফাঁকা;
            dwarf_সারি.cur_file = 1;
            dwarf_সারি.last_file = 0;
            dwarf_সারি.last_pc = 0;
            dwarf_সারি.last_সারি = 1;
            dwarf_সারি_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_আকার); // extended size
            dwarf_সারি_op(s1, DW_LNE_set_address);
            জন্য (i = 0; i < PTR_আকার; i++)
    	        dwarf_সারি_op(s1, 0);
            memset(&dwarf_info.base_type_used, 0, আকার(dwarf_info.base_type_used));
        }
        অন্যথা
        {
            /* file info: full path + filename */
            pstrcat(buf, আকার(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      text_section->sh_অঙ্ক, ফাঁকা);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        text_section->তথ্য_offset, text_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        text_section->তথ্য_offset, text_section, section_sym);
            জন্য (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

স্থির শূন্য fix_debug_forw_hash(TCCState *s1, পূর্ণসংখ্যা global, পূর্ণসংখ্যা start);

/* put end of translation unit info */
ST_FUNC শূন্য tcc_debug_end(TCCState *s1)
{

    যদি (!s1->do_debug || debug_পরবর্তী_type == 0)
        ফেরত;

    যদি (debug_info_মূল)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    যদি (s1->dwarf) {
	পূর্ণসংখ্যা i;
	পূর্ণসংখ্যা start_aranges;
	unsigned অক্ষর *ptr;
	পূর্ণসংখ্যা text_আকার = text_section->তথ্য_offset;

	/* dwarf_info */
	fix_debug_forw_hash(s1, 0, 0);
	fix_debug_forw_hash(s1, 1, 0);
	dwarf_data1(dwarf_info_section, 0);
	ptr = dwarf_info_section->তথ্য + dwarf_info.start;
	write32le(ptr, dwarf_info_section->তথ্য_offset - dwarf_info.start - 4);
	write32le(ptr + 25 + (s1->dwarf >= 5) + PTR_আকার, text_আকার);

	/* dwarf_aranges */
	start_aranges = dwarf_aranges_section->তথ্য_offset;
	dwarf_data4(dwarf_aranges_section, 0); //আকার
	dwarf_data2(dwarf_aranges_section, 2); // version
	dwarf_reloc(dwarf_aranges_section, dwarf_sym.info, R_তথ্য_32_DW);
	dwarf_data4(dwarf_aranges_section, 0); // dwarf_info
#যদি PTR_আকার == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#অন্যথা
	dwarf_data1(dwarf_aranges_section, 8); // address size
#endif
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_তথ্য_PTR);
#যদি PTR_আকার == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, text_আকার); // End
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#অন্যথা
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, text_আকার); // End
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#endif
	ptr = dwarf_aranges_section->তথ্য + start_aranges;
	write32le(ptr, dwarf_aranges_section->তথ্য_offset - start_aranges - 4);

	/* dwarf_line */
	যদি (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_সারি_section, 1); /* col */
	    dwarf_uleb128(dwarf_সারি_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_সারি_section, DW_FORM_সারি_strp);
	    dwarf_uleb128(dwarf_সারি_section, dwarf_সারি.dir_আকার);
	    জন্য (i = 0; i < dwarf_সারি.dir_আকার; i++)
	        dwarf_সারি_strp(dwarf_সারি_section, dwarf_সারি.dir_table[i]);
	    dwarf_data1(dwarf_সারি_section, 2); /* col */
	    dwarf_uleb128(dwarf_সারি_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_সারি_section, DW_FORM_সারি_strp);
	    dwarf_uleb128(dwarf_সারি_section, DW_LNCT_directory_সূচক);
	    dwarf_uleb128(dwarf_সারি_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_সারি_section, dwarf_সারি.filename_আকার);
	    জন্য (i = 0; i < dwarf_সারি.filename_আকার; i++) {
	        dwarf_সারি_strp(dwarf_সারি_section,
				dwarf_সারি.filename_table[i].name);
	        dwarf_uleb128(dwarf_সারি_section,
			      dwarf_সারি.filename_table[i].dir_entry);
	    }
	}
	অন্যথা {
	    পূর্ণসংখ্যা len;

	    জন্য (i = 0; i < dwarf_সারি.dir_আকার; i++) {
	        len = strlen(dwarf_সারি.dir_table[i]) + 1;
	        ptr = section_ptr_add(dwarf_সারি_section, len);
	        memmove(ptr, dwarf_সারি.dir_table[i], len);
	    }
	    dwarf_data1(dwarf_সারি_section, 0); /* end dir */
	    জন্য (i = 0; i < dwarf_সারি.filename_আকার; i++) {
	        len = strlen(dwarf_সারি.filename_table[i].name) + 1;
	        ptr = section_ptr_add(dwarf_সারি_section, len);
	        memmove(ptr, dwarf_সারি.filename_table[i].name, len);
	        dwarf_uleb128(dwarf_সারি_section,
			      dwarf_সারি.filename_table[i].dir_entry);
	        dwarf_uleb128(dwarf_সারি_section, 0); /* time */
	        dwarf_uleb128(dwarf_সারি_section, 0); /*আকার*/
	    }
	    dwarf_data1(dwarf_সারি_section, 0); /* end file */
	}
	জন্য (i = 0; i < dwarf_সারি.dir_আকার; i++)
	    tcc_free(dwarf_সারি.dir_table[i]);
	tcc_free(dwarf_সারি.dir_table);
	জন্য (i = 0; i < dwarf_সারি.filename_আকার; i++)
	    tcc_free(dwarf_সারি.filename_table[i].name);
	tcc_free(dwarf_সারি.filename_table);

	dwarf_সারি_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_সারি_op(s1, DW_LNE_end_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_সারি_section->তথ্য[dwarf_সারি.start + 6 + i],
		  dwarf_সারি_section->তথ্য_offset - dwarf_সারি.start - (10 + i));
	section_ptr_add(dwarf_সারি_section, 3);
	dwarf_reloc(dwarf_সারি_section, section_sym, R_তথ্য_PTR);
	ptr = section_ptr_add(dwarf_সারি_section, dwarf_সারি.সারি_আকার - 3);
	memmove(ptr - 3, dwarf_সারি.সারি_তথ্য, dwarf_সারি.সারি_আকার);
	tcc_free(dwarf_সারি.সারি_তথ্য);
	write32le(dwarf_সারি_section->তথ্য + dwarf_সারি.start,
		  dwarf_সারি_section->তথ্য_offset - dwarf_সারি.start - 4);
    }
    অন্যথা
    {
        put_stabs_r(s1, ফাঁকা, N_SO, 0, 0,
                    text_section->তথ্য_offset, text_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_সারি_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_পরবর্তী_type = 0;
}

স্থির BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    যদি (f->filename[0] == ':')
        f = f->পূর্ব;
    যদি (f && new_file) {
        new_file = last_সারি_অঙ্ক = 0;
        যদি (s1->dwarf)
            dwarf_file(s1);
        অন্যথা
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, text_section, section_sym);
    }
    ফেরত f;
}

/* put alternative filename */
ST_FUNC শূন্য tcc_debug_newfile(TCCState *s1)
{
    যদি (!s1->do_debug)
        ফেরত;
    যদি (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC শূন্য tcc_debug_bincl(TCCState *s1)
{
    যদি (!s1->do_debug)
        ফেরত;
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
        ফেরত;
    যদি (s1->dwarf)
        dwarf_file(s1);
    অন্যথা
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC শূন্য tcc_debug_সারি(TCCState *s1)
{
    BufferedFile *f;

    যদি (!s1->do_debug)
        ফেরত;
    যদি (cur_text_section != text_section || nocode_wanted)
        ফেরত;
    f = put_new_file(s1);
    যদি (!f)
        ফেরত;
    যদি (last_সারি_অঙ্ক == f->সারি_অঙ্ক)
        ফেরত;
    last_সারি_অঙ্ক = f->সারি_অঙ্ক;

    যদি (s1->dwarf) {
	পূর্ণসংখ্যা len_pc = (ind - dwarf_সারি.last_pc) / DWARF_MIN_INSTR_LEN;
	পূর্ণসংখ্যা len_সারি = f->সারি_অঙ্ক - dwarf_সারি.last_সারি;
	পূর্ণসংখ্যা n = len_pc * DWARF_সারি_RANGE + len_সারি + DWARF_OPCODE_BASE - DWARF_সারি_BASE;

	যদি (dwarf_সারি.cur_file != dwarf_সারি.last_file) {
	    dwarf_সারি.last_file = dwarf_সারি.cur_file;
	    dwarf_সারি_op(s1, DW_LNS_set_file);
	    dwarf_uleb128_op(s1, dwarf_সারি.cur_file);
	}
	যদি (len_pc &&
	    len_সারি >= DWARF_সারি_BASE && len_সারি <= (DWARF_OPCODE_BASE + DWARF_সারি_BASE) &&
	    n >= DWARF_OPCODE_BASE && n <= 255)
            dwarf_সারি_op(s1, n);
	অন্যথা {
	    যদি (len_pc) {
	        n = len_pc * DWARF_সারি_RANGE + 0 + DWARF_OPCODE_BASE - DWARF_সারি_BASE;
	        যদি (n >= DWARF_OPCODE_BASE && n <= 255)
                    dwarf_সারি_op(s1, n);
		অন্যথা {
	            dwarf_সারি_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    যদি (len_সারি) {
	        n = 0 * DWARF_সারি_RANGE + len_সারি + DWARF_OPCODE_BASE - DWARF_সারি_BASE;
	        যদি (len_সারি >= DWARF_সারি_BASE && len_সারি <= (DWARF_OPCODE_BASE + DWARF_সারি_BASE) &&
		    n >= DWARF_OPCODE_BASE && n <= 255)
	            dwarf_সারি_op(s1, n);
		অন্যথা {
	            dwarf_সারি_op(s1, DW_LNS_advance_সারি);
		    dwarf_sleb128_op(s1, len_সারি);
                    /* advance by nothing */
	            dwarf_সারি_op(s1, DWARF_OPCODE_BASE - DWARF_সারি_BASE);
		}
	    }
	}
	dwarf_সারি.last_pc = ind;
	dwarf_সারি.last_সারি = f->সারি_অঙ্ক;
    }
    অন্যথা
    {
	যদি (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->সারি_অঙ্ক, ind - func_ind);
        } অন্যথা {
            /* from tcc_assemble */
            put_stabs_r(s1, ফাঁকা, N_SLINE, 0, f->সারি_অঙ্ক, ind, text_section, section_sym);
        }
    }
}

স্থির শূন্য tcc_debug_stabs (TCCState *s1, ধ্রুবক অক্ষর *str, পূর্ণসংখ্যা type, unsigned long মান,
                             Section *sec, পূর্ণসংখ্যা sym_সূচক, পূর্ণসংখ্যা info)
{
    কাঠামো debug_sym *s;

    যদি (debug_info) {
        debug_info->sym =
            (কাঠামো debug_sym *)tcc_realloc (debug_info->sym,
                                             আকার(কাঠামো debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->মান = মান;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_সূচক = sym_সূচক;
        s->info = info;
        s->file = dwarf_সারি.cur_file;
        s->সারি = file->সারি_অঙ্ক;
    }
    অন্যথা যদি (sec)
        put_stabs_r (s1, str, type, 0, 0, মান, sec, sym_সূচক);
    অন্যথা
        put_stabs (s1, str, type, 0, 0, মান);
}

স্থির শূন্য fix_debug_forw_hash(TCCState *s1, পূর্ণসংখ্যা global, পূর্ণসংখ্যা start)
{
    যদি (s1->dwarf) {
        পূর্ণসংখ্যা i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	কাঠামো _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	জন্য (i = start; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    পূর্ণসংখ্যা pos = dwarf_info_section->তথ্য_offset;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_EMPTY_TYPE
                                             : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, ফাঁকা));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_সারি.cur_file);
            dwarf_uleb128(dwarf_info_section, file->সারি_অঙ্ক);
	    জন্য (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->তথ্য +
			  hash[i].debug_type[j],
			  pos - dwarf_info.start);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC শূন্য tcc_debug_stabn(TCCState *s1, পূর্ণসংখ্যা type, পূর্ণসংখ্যা মান)
{
    যদি (!s1->do_debug)
        ফেরত;
    যদি (type == N_LBRAC) {
        কাঠামো _debug_info *info =
            (কাঠামো _debug_info *) tcc_mallocz(আকার (*info));

        info->start = মান;
        info->last_debug_hash = n_debug_hash_local;
        info->last_debug_forw_hash = n_debug_forw_hash_local;
        info->parent = debug_info;
        যদি (debug_info) {
            যদি (debug_info->child) {
                যদি (debug_info->child->last)
                    debug_info->child->last->পরবর্তী = info;
                অন্যথা
                    debug_info->child->পরবর্তী = info;
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

স্থির পূর্ণসংখ্যা check_global(Sym *t)
{
    Sym *g = local_স্তূপ;

    যখন (g) {
	যদি (t == g)
	    ফেরত 0;
	g = g->পূর্ব;
    }
    ফেরত 1;
}

স্থির পূর্ণসংখ্যা tcc_debug_find(TCCState *s1, Sym *t, পূর্ণসংখ্যা dwarf)
{
    পূর্ণসংখ্যা i , g = check_global(t);
    পূর্ণসংখ্যা n_hash, *n_forw_hash;
    কাঠামো _debug_hash *hash;
    কাঠামো _debug_forw_hash **forw_hash;

    যদি ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	জন্য (i = 0; i < *n_forw_hash; i++)
            যদি (t == (*forw_hash)[i].type)
		ফেরত 0;
	*forw_hash = (কাঠামো _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * আকার(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = ফাঁকা;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	ফেরত 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    জন্য (i = 0; i < n_hash; i++)
        যদি (t == hash[i].type)
	    ফেরত hash[i].debug_type;
    ফেরত -1;
}

স্থির পূর্ণসংখ্যা tcc_get_dwarf_info(TCCState *s1, Sym *s);

স্থির শূন্য tcc_debug_check_forw(TCCState *s1, Sym *t, পূর্ণসংখ্যা debug_type)
{
    যদি ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        পূর্ণসংখ্যা i, j, g = check_global(t);
        পূর্ণসংখ্যা n_forw_hash;
        কাঠামো _debug_forw_hash **forw_hash;

	জন্য (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    জন্য (j = 0; j < n_forw_hash; j++)
                যদি (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * আকার(পূর্ণসংখ্যা));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    ফেরত;
                }
	}
    }
}

স্থির শূন্য stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC শূন্য tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    যদি (!(s1->do_debug & 2))
	ফেরত;
    যদি (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        ফেরত;
    }
    যদি ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        পূর্ণসংখ্যা i, j, debug_type, g = check_global(t->ref);
        পূর্ণসংখ্যা *n_forw_hash;
        কাঠামো _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	জন্য (i = 0; i < *n_forw_hash; i++)
	    যদি (t->ref == (*forw_hash)[i].type) {
		যদি (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    জন্য (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->তথ্য +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.start);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		জন্য (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

স্থির পূর্ণসংখ্যা tcc_debug_add(TCCState *s1, Sym *t, পূর্ণসংখ্যা dwarf)
{
    পূর্ণসংখ্যা offset = dwarf ? dwarf_info_section->তথ্য_offset : ++debug_পরবর্তী_type;
    পূর্ণসংখ্যা *n_hash, g = check_global(t);
    কাঠামো _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (কাঠামো _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * আকার(**hash));
    (*hash)[*n_hash].debug_type = offset;
    (*hash)[(*n_hash)++].type = t;
    ফেরত offset;
}

স্থির পূর্ণসংখ্যা STRUCT_NODEBUG(Sym *s)
{
    ফেরত
    (s->a.nodebug ||
     ((s->v & ~SYM_FIELD) >= SYM_FIRST_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

স্থির পূর্ণসংখ্যা stabs_struct_find(TCCState *s1, Sym *t, পূর্ণসংখ্যা *p_id)
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
    যদি (ফাঁকা == p_id)
        ফেরত s && !s->r && t->c >= 0;
    যদি (ফাঁকা == s) {
        /* just use global_stack always */
        s = sym_push2(&global_স্তূপ, SYM_FIELD|0x00DEBBED, 0, ++debug_পরবর্তী_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    যদি (s->r || t->c < 0) /* already defined or still incomplete */
        ফেরত 0;
    s->r = 1;
    ফেরত 1;
}

স্থির পূর্ণসংখ্যা remove_type_info(পূর্ণসংখ্যা type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        যদি ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        যদি (!(type & VT_BITFIELD) && (type & VT_STRUCT_MASK) > VT_ENUM)
	    type &= ~VT_STRUCT_MASK;
	ফেরত type;
}

স্থির শূন্য tcc_get_debug_info(TCCState *s1, Sym *s, CString *ফলাফল)
{
    পূর্ণসংখ্যা type;
    পূর্ণসংখ্যা n = 0;
    পূর্ণসংখ্যা debug_type = -1;
    Sym *t = s;
    CString str;

    জন্য (;;) {
        type = remove_type_info (t->type.t);
        যদি (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        অন্যথা
            বিরতি;
    }
    যদি ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        যদি (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, ফাঁকা),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            যখন (t->পরবর্তী) {
                পূর্ণসংখ্যা pos, আকার_2, align;
                t = t->পরবর্তী;
		যদি (STRUCT_NODEBUG(t))
		    চালু;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, ফাঁকা)
                             );
                tcc_get_debug_info (s1, t, &str);
                যদি (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + BIT_POS(t->type.t);
                    আকার_2 = BIT_আকার(t->type.t);
                }
                অন্যথা {
                    pos = t->c * 8;
                    আকার_2 = type_আকার(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, আকার_2);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.তথ্য, N_LSYM, 0, ফাঁকা, 0, 0);
            cstr_free (&str);
        }
    }
    অন্যথা যদি (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        যদি (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, ফাঁকা),
                         debug_type);
            যখন (t->পরবর্তী) {
                t = t->পরবর্তী;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, ফাঁকা));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (পূর্ণসংখ্যা)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.তথ্য, N_LSYM, 0, ফাঁকা, 0, 0);
            cstr_free (&str);
	}
    }
    অন্যথা যদি ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        জন্য (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            যদি (default_debug[debug_type - 1].type == type)
                বিরতি;
        যদি (debug_type > N_DEFAULT_DEBUG)
            ফেরত;
    }

    যদি (ফাঁকা == ফলাফল) /* from stabs_struct_complete() */
        ফেরত;

    যদি (n > 0)
        cstr_printf (ফলাফল, "%d=", ++debug_পরবর্তী_type);
    t = s;
    জন্য (;;) {
        type = remove_type_info (t->type.t);
        যদি (type == VT_PTR)
            cstr_printf (ফলাফল, "%d=*", ++debug_পরবর্তী_type);
        অন্যথা যদি (type == (VT_PTR | VT_ARRAY))
            cstr_printf (ফলাফল, "%d=ar1;0;%d;",
                         ++debug_পরবর্তী_type, t->type.ref->c - 1);
        অন্যথা যদি (type == VT_FUNC) {
            cstr_printf (ফলাফল, "%d=f", ++debug_পরবর্তী_type);
            tcc_get_debug_info (s1, t->type.ref, ফলাফল);
            ফেরত;
        }
        অন্যথা
            বিরতি;
        t = t->type.ref;
    }
    cstr_printf (ফলাফল, "%d", debug_type);
}

স্থির শূন্য stabs_struct_complete(TCCState *s1, CType *t)
{
    যদি (stabs_struct_find(s1, t->ref, ফাঁকা)) {
        Sym s = {0}; s.type = *t;
        tcc_get_debug_info(s1, &s, ফাঁকা);
    }
}

স্থির পূর্ণসংখ্যা tcc_get_dwarf_info(TCCState *s1, Sym *s)
{
    পূর্ণসংখ্যা type;
    পূর্ণসংখ্যা debug_type = -1;
    Sym *e, *t = s;
    পূর্ণসংখ্যা i;
    পূর্ণসংখ্যা last_pos = -1;
    পূর্ণসংখ্যা retval;

    যদি (new_file)
        put_new_file(s1);
    জন্য (;;) {
        type = remove_type_info (t->type.t);
        যদি (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        অন্যথা
            বিরতি;
    }
    যদি ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	যদি (debug_type == -1) {
	    পূর্ণসংখ্যা pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_add(s1, t, 1);
	    e = t;
	    i = 0;
	    যখন (e->পরবর্তী) {
		e = e->পরবর্তী;
		যদি (STRUCT_NODEBUG(e))
		    চালু;
		i++;
	    }
	    pos_type = (পূর্ণসংখ্যা *) tcc_malloc(i * আকার(পূর্ণসংখ্যা));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->পরবর্তী ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_EMPTY_TYPE
		        : t->পরবর্তী ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, ফাঁকা));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_সারি.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->সারি_অঙ্ক);
	    যদি (t->পরবর্তী) {
	        pos_sib = dwarf_info_section->তথ্য_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            যখন (e->পরবর্তী) {
                e = e->পরবর্তী;
		যদি (STRUCT_NODEBUG(e))
		    চালু;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, ফাঁকা));
		dwarf_uleb128(dwarf_info_section, dwarf_সারি.cur_file);
		dwarf_uleb128(dwarf_info_section, file->সারি_অঙ্ক);
		pos_type[i++] = dwarf_info_section->তথ্য_offset;
		dwarf_data4(dwarf_info_section, 0);
                যদি (e->type.t & VT_BITFIELD) {
                    পূর্ণসংখ্যা pos = e->c * 8 + BIT_POS(e->type.t);
                    পূর্ণসংখ্যা আকার_2 = BIT_আকার(e->type.t);

		    dwarf_uleb128(dwarf_info_section, আকার_2);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		অন্যথা
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    যদি (t->পরবর্তী) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->তথ্য + pos_sib,
		          dwarf_info_section->তথ্য_offset - dwarf_info.start);
	    }
	    e = t;
	    i = 0;
	    যখন (e->পরবর্তী) {
		e = e->পরবর্তী;
		যদি (STRUCT_NODEBUG(e))
		    চালু;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->তথ্য + pos_type[i++],
			  type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
    }
    অন্যথা যদি (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	যদি (debug_type == -1) {
	    পূর্ণসংখ্যা pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_add(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, ফাঁকা));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.start);
	    dwarf_uleb128(dwarf_info_section, dwarf_সারি.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->সারি_অঙ্ক);
	    pos_sib = dwarf_info_section->তথ্য_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            যখন (e->পরবর্তী) {
                e = e->পরবর্তী;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                           ? "" : get_tok_str(e->v, ফাঁকা));
		যদি (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		অন্যথা
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->তথ্য + pos_sib,
		      dwarf_info_section->তথ্য_offset - dwarf_info.start);
	}
    }
    অন্যথা যদি ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        জন্য (i = 1; i <= N_DEFAULT_DEBUG; i++)
            যদি (default_debug[i - 1].type == type)
                বিরতি;
        যদি (i > N_DEFAULT_DEBUG)
            ফেরত 0;
	debug_type = dwarf_info.base_type_used[i - 1];
	যদি (debug_type == 0) {
	    অক্ষর name[100];

	    debug_type = dwarf_info_section->তথ্য_offset;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_BASE_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].আকার_2);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, আকার name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.base_type_used[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = ফাঁকা;
    t = s;
    জন্য (;;) {
        type = remove_type_info (t->type.t);
        যদি (type == VT_PTR) {
	    i = dwarf_info_section->তথ্য_offset;
	    যদি (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_POINTER);
	    dwarf_data1(dwarf_info_section, PTR_আকার);
	    যদি (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->তথ্য + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->তথ্য_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        অন্যথা যদি (type == (VT_PTR | VT_ARRAY)) {
	    পূর্ণসংখ্যা sib_pos, sub_type;
#যদি LONG_আকার == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#অন্যথা
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#endif

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->তথ্য_offset;
	    যদি (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    যদি (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->তথ্য + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->তথ্য_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->তথ্য_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    জন্য (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.start);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		যদি (type != (VT_PTR | VT_ARRAY))
		    বিরতি;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->তথ্য + sib_pos,
		      dwarf_info_section->তথ্য_offset - dwarf_info.start);
	}
        অন্যথা যদি (type == VT_FUNC) {
	    পূর্ণসংখ্যা sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->তথ্য_offset;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    যদি (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->পরবর্তী ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_EMPTY_TYPE);
	    যদি (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->তথ্য + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->তথ্য_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    যদি (t->type.ref->পরবর্তী) {
	        sib_pos = dwarf_info_section->তথ্য_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    যখন (f->পরবর্তী) {
		f = f->পরবর্তী;
		i++;
	    }
	    pos_type = (পূর্ণসংখ্যা *) tcc_malloc(i * আকার(পূর্ণসংখ্যা));
	    f = t->type.ref;
	    i = 0;
	    যখন (f->পরবর্তী) {
		f = f->পরবর্তী;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->তথ্য_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    যদি (t->type.ref->পরবর্তী) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->তথ্য + sib_pos,
		          dwarf_info_section->তথ্য_offset - dwarf_info.start);
	    }
	    f = t->type.ref;
	    i = 0;
	    যখন (f->পরবর্তী) {
		f = f->পরবর্তী;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->তথ্য + pos_type[i++],
                          type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
        অন্যথা {
	    যদি (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->তথ্য + last_pos,
			  debug_type - dwarf_info.start);
	    }
            বিরতি;
	}
        t = t->type.ref;
    }
    ফেরত retval;
}

স্থির শূন্য tcc_debug_finish (TCCState *s1, কাঠামো _debug_info *cur)
{
    যখন (cur) {
        কাঠামো _debug_info *পরবর্তী = cur->পরবর্তী;
        পূর্ণসংখ্যা i;

        যদি (s1->dwarf) {

            জন্য (i = cur->n_sym - 1; i >= 0; i--) {
                কাঠামো debug_sym *s = &cur->sym[i];

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
                    dwarf_uleb128(dwarf_info_section, s->সারি);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.start);
		যদি (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    যদি (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_আকার + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    যদি (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_তথ্য_PTR);
#যদি PTR_আকার == 4
                    dwarf_data4(dwarf_info_section, s->মান);
#অন্যথা
                    dwarf_data8(dwarf_info_section, s->মান);
#endif
		}
		অন্যথা {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_আকার((long)s->মান) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (long)s->মান);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->child ? DWARF_ABBREV_LEXICAL_BLOCK
			           : DWARF_ABBREV_LEXICAL_EMPTY_BLOCK);
            dwarf_reloc(dwarf_info_section, section_sym, R_তথ্য_PTR);
#যদি PTR_আকার == 4
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
            জন্য (i = 0; i < cur->n_sym; i++) {
                কাঠামো debug_sym *s = &cur->sym[i];

                যদি (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->মান,
                                s->sec, s->sym_সূচক);
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
        cur = পরবর্তী;
    }
}

ST_FUNC শূন্য tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    পূর্ণসংখ্যা param;

    যদি (!(s1->do_debug & 2))
        ফেরত;

    cstr_new (&debug_str);
    param = !e;
    জন্য (; s != e; s = s->পূর্ব) {
        যদি (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            চালু;
	যদি (s1->dwarf) {
	    tcc_debug_stabs(s1, get_tok_str(s->v, ফাঁকা),
			    param ? N_PSYM : N_LSYM, s->c, ফাঁকা, 0,
			    tcc_get_dwarf_info(s1, s));
	}
	অন্যথা
        {
            cstr_reset (&debug_str);
            cstr_printf (&debug_str, "%s:%s", get_tok_str(s->v, ফাঁকা),
			 param ? "p" : "");
            tcc_get_debug_info(s1, s, &debug_str);
            tcc_debug_stabs(s1, debug_str.তথ্য, param ? N_PSYM : N_LSYM,
			    s->c, ফাঁকা, 0, 0);
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
        ফেরত;
    debug_info_মূল = ফাঁকা;
    debug_info = ফাঁকা;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    যদি (!f)
	ফেরত;

    যদি (s1->dwarf) {
        tcc_debug_সারি(s1);
        dwarf_info.func = sym;
        dwarf_info.সারি = file->সারি_অঙ্ক;
	যদি (s1->do_backtrace) {
	    পূর্ণসংখ্যা i, len;

	    dwarf_সারি_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, strlen(funcname) + 2);
	    dwarf_সারি_op(s1, DW_LNE_hi_user - 1);
	    len = strlen(funcname) + 1;
	    জন্য (i = 0; i < len; i++)
		dwarf_সারি_op(s1, funcname[i]);
	}
    }
    অন্যথা
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.তথ্য, N_FUN, 0, f->সারি_অঙ্ক, 0, cur_text_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_সারি(s1);
    }
}

ST_FUNC শূন্য tcc_debug_prolog_epilog(TCCState *s1, পূর্ণসংখ্যা মান)
{
    যদি (!s1->do_debug)
        ফেরত;
    যদি (s1->dwarf) {
	dwarf_সারি_op(s1, মান == 0 ? DW_LNS_set_prologue_end
				     : DW_LNS_set_epilogue_begin);
    }
}

/* put function size */
ST_FUNC শূন্য tcc_debug_funcend(TCCState *s1, পূর্ণসংখ্যা আকার_2)
{
    /* lldb does not like function end and next function start at same pc */
    পূর্ণসংখ্যা min_instr_len;

#যদি TCC_EH_FRAME
    tcc_debug_frame_end(s1, আকার_2);
#endif
    যদি (!s1->do_debug)
        ফেরত;
    min_instr_len = dwarf_সারি.last_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_সারি(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, আকার_2);
    যদি (s1->dwarf) {
        পূর্ণসংখ্যা func_sib = 0;
	Sym *sym = dwarf_info.func;
	পূর্ণসংখ্যা n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        যদি ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_সারি.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.সারি);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->তথ্য_offset);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.start);
        dwarf_reloc(dwarf_info_section, section_sym, R_তথ্য_PTR);
#যদি PTR_আকার == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, আকার_2); // high_pc
#অন্যথা
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, আকার_2); // high_pc
#endif
        func_sib = dwarf_info_section->তথ্য_offset;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#যদি defined(TCC_TARGET_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#নতুবা_যদি defined(TCC_TARGET_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#নতুবা_যদি defined TCC_TARGET_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#নতুবা_যদি defined TCC_TARGET_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#নতুবা_যদি defined TCC_TARGET_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#অন্যথা
        dwarf_data1(dwarf_info_section, DW_OP_call_frame_cfa);
#endif
        tcc_debug_finish (s1, debug_info_মূল);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->তথ্য + func_sib,
                  dwarf_info_section->তথ্য_offset - dwarf_info.start);
    }
    অন্যথা
    {
        tcc_debug_finish (s1, debug_info_মূল);
    }
    debug_info_মূল = 0;
}


ST_FUNC শূন্য tcc_debug_extern_sym(TCCState *s1, Sym *sym, পূর্ণসংখ্যা sh_অঙ্ক, পূর্ণসংখ্যা sym_bind, পূর্ণসংখ্যা sym_type)
{
    যদি (!(s1->do_debug & 2))
        ফেরত;

    যদি (sym_type == STT_FUNC || sym->v >= SYM_FIRST_ANOM)
        ফেরত;
    যদি (s1->dwarf) {
        পূর্ণসংখ্যা debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, ফাঁকা));
	dwarf_uleb128(dwarf_info_section, dwarf_সারি.cur_file);
	dwarf_uleb128(dwarf_info_section, file->সারি_অঙ্ক);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->তথ্য_offset);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	যদি (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_আকার + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->তথ্য_offset,
		R_তথ্য_PTR, 0);
#যদি PTR_আকার == 4
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
                get_tok_str(sym->v, ফাঁকা),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        যদি (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.তথ্য, N_GSYM, 0, ফাঁকা, 0, 0);
        অন্যথা
            tcc_debug_stabs(s1, str.তথ্য,
                (sym->type.t & VT_STATIC) && তথ্য_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC শূন্য tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    যদি (!(s1->do_debug & 2))
        ফেরত;

    যদি (s1->dwarf) {
	পূর্ণসংখ্যা debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	যদি (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, ফাঁকা));
	    dwarf_uleb128(dwarf_info_section, dwarf_সারি.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->সারি_অঙ্ক);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->তথ্য_offset);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	}
    }
    অন্যথা
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, ফাঁকা));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.তথ্য, N_LSYM, 0, ফাঁকা, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC শূন্য tcc_tcov_block_end(TCCState *s1, পূর্ণসংখ্যা সারি);

ST_FUNC শূন্য tcc_tcov_block_begin(TCCState *s1)
{
    SValue sv;
    শূন্য *ptr;
    unsigned long last_offset = tcov_তথ্য.offset;

    tcc_tcov_block_end (tcc_state, 0);
    যদি (s1->test_coverage == 0 || nocode_wanted)
	ফেরত;

    যদি (tcov_তথ্য.last_file_name == 0 ||
	strcmp ((ধ্রুবক অক্ষর *)(tcov_section->তথ্য + tcov_তথ্য.last_file_name),
		file->true_filename) != 0) {
	অক্ষর wd[1024];
	CString cstr;

	যদি (tcov_তথ্য.last_func_name)
	    section_ptr_add(tcov_section, 1);
	যদি (tcov_তথ্য.last_file_name)
	    section_ptr_add(tcov_section, 1);
	tcov_তথ্য.last_func_name = 0;
	cstr_new (&cstr);
	যদি (file->true_filename[0] == '/') {
	    tcov_তথ্য.last_file_name = tcov_section->তথ্য_offset;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	অন্যথা {
	    getcwd (wd, আকার(wd));
	    tcov_তথ্য.last_file_name = tcov_section->তথ্য_offset + strlen(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_add(tcov_section, cstr.আকার_2 + 1);
	strcpy((অক্ষর *)ptr, cstr.তথ্য);
#ifdef _WIN32
        normalize_slashes((অক্ষর *)ptr);
#endif
	cstr_free (&cstr);
    }
    যদি (tcov_তথ্য.last_func_name == 0 ||
	strcmp ((ধ্রুবক অক্ষর *)(tcov_section->তথ্য + tcov_তথ্য.last_func_name),
		funcname) != 0) {
	আকার_t len;

	যদি (tcov_তথ্য.last_func_name)
	    section_ptr_add(tcov_section, 1);
	tcov_তথ্য.last_func_name = tcov_section->তথ্য_offset;
	len = strlen (funcname);
	ptr = section_ptr_add(tcov_section, len + 1);
	strcpy((অক্ষর *)ptr, funcname);
	section_ptr_add(tcov_section, -tcov_section->তথ্য_offset & 7);
	ptr = section_ptr_add(tcov_section, 8);
	write64le (ptr, file->সারি_অঙ্ক);
    }
    যদি (ind == tcov_তথ্য.ind && tcov_তথ্য.সারি == file->সারি_অঙ্ক)
        tcov_তথ্য.offset = last_offset;
    অন্যথা {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_add(tcov_section, 16);
        tcov_তথ্য.সারি = file->সারি_অঙ্ক;
        write64le (ptr, (tcov_তথ্য.সারি << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((unsigned অক্ষর *)ptr - tcov_section->তথ্য) + 8, 0);
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
        tcov_তথ্য.offset = (unsigned অক্ষর *)ptr - tcov_section->তথ্য;
        tcov_তথ্য.ind = ind;
    }
}

ST_FUNC শূন্য tcc_tcov_block_end(TCCState *s1, পূর্ণসংখ্যা সারি)
{
    যদি (s1->test_coverage == 0)
	ফেরত;
    যদি (সারি == -1)
        সারি = tcov_তথ্য.সারি;
    যদি (tcov_তথ্য.offset) {
	শূন্য *ptr = tcov_section->তথ্য + tcov_তথ্য.offset;
	unsigned long long nline = সারি ? সারি : file->সারি_অঙ্ক;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_তথ্য.offset = 0;
    }
}

ST_FUNC শূন্য tcc_tcov_check_সারি(TCCState *s1, পূর্ণসংখ্যা start)
{
    যদি (s1->test_coverage == 0)
	ফেরত;
    যদি (tcov_তথ্য.সারি != file->সারি_অঙ্ক) {
        যদি ((tcov_তথ্য.সারি + 1) != file->সারি_অঙ্ক) {
	    tcc_tcov_block_end (s1, -1);
	    যদি (start)
                tcc_tcov_block_begin (s1);
	}
	অন্যথা
	    tcov_তথ্য.সারি = file->সারি_অঙ্ক;
    }
}

ST_FUNC শূন্য tcc_tcov_start(TCCState *s1)
{
    যদি (s1->test_coverage == 0)
	ফেরত;
    যদি (!s1->dState)
        s1->dState = tcc_mallocz(আকার *s1->dState);
    memset (&tcov_তথ্য, 0, আকার (tcov_তথ্য));
    যদি (tcov_section == ফাঁকা) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_add(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC শূন্য tcc_tcov_end(TCCState *s1)
{
    যদি (s1->test_coverage == 0)
	ফেরত;
    যদি (tcov_তথ্য.last_func_name)
        section_ptr_add(tcov_section, 1);
    যদি (tcov_তথ্য.last_file_name)
        section_ptr_add(tcov_section, 1);
}

ST_FUNC শূন্য tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_তথ্য.ind = 0;
}

/* ------------------------------------------------------------------------- */
#undef last_সারি_অঙ্ক
#undef new_file
#undef section_sym
#undef debug_পরবর্তী_type
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
#undef dwarf_সারি
#undef dwarf_info
#undef dwarf_str
#undef dwarf_সারি_str
#undef tcov_তথ্য
