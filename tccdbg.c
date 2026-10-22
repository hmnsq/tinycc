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

#ଅନ୍ତର୍ଭାଵ "tcc.h"

/* stab debug support */

ସ୍ଥିର ଅଚଳ ସଂରଚନା {
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା type;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା size;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା encoding;
  ଅଚଳ ଅକ୍ଷର *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#ଯଦି LONG_SIZE == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#ଅନ୍ୟଥା
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#endif
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#ଯଦି LONG_SIZE == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#ଅନ୍ୟଥା
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
#ଅନ୍ୟଥା
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
#ଯଦି LONG_SIZE == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#ଅନ୍ୟଥା
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#endif
};

#define	N_DEFAULT_DEBUG	(ଆକାର (default_debug) / ଆକାର (default_debug[0]))

/* dwarf debug */

#define	DWARF_ଧାଡ଼ି_BASE				-5
#define	DWARF_ଧାଡ଼ି_RANGE			14
#define	DWARF_OPCODE_BASE			13

#ଯଦି defined TCC_TARGET_ARM64
#define	DWARF_MIN_INSTR_LEN			4
#ନଚେତଯଦି defined TCC_TARGET_ARM
#define	DWARF_MIN_INSTR_LEN			2
#ଅନ୍ୟଥା
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
ସ୍ଥିର ଅଚଳ unsigned ଅକ୍ଷର dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_TAG_compile_unit, 1,
          DW_AT_producer, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_ଧାଡ଼ି_strp,
          DW_AT_comp_dir, DW_FORM_ଧାଡ଼ି_strp,
          DW_AT_ତଳ_pc, DW_FORM_addr,
#ଯଦି PTR_SIZE == 4
          DW_AT_ଉପର_pc, DW_FORM_data4,
#ଅନ୍ୟଥା
          DW_AT_ଉପର_pc, DW_FORM_data8,
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
          DW_AT_decl_ଧାଡ଼ି, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_TAG_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ଧାଡ଼ି, DW_FORM_udata,
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
          DW_AT_decl_ଧାଡ଼ି, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_TAG_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_ମୂଲ୍ୟ, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_TAG_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_ମୂଲ୍ୟ, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_TAG_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_size, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ଧାଡ଼ି, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ଧାଡ଼ି, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_data_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ଧାଡ଼ି, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_bit_size, DW_FORM_udata,
          DW_AT_data_bit_offset, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_TAG_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ଧାଡ଼ି, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_EMPTY_TYPE, DW_TAG_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ଧାଡ଼ି, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_TAG_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ଧାଡ଼ି, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_EMPTY_TYPE, DW_TAG_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ଧାଡ଼ି, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_TAG_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ଧାଡ଼ି, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ତଳ_pc, DW_FORM_addr,
#ଯଦି PTR_SIZE == 4
          DW_AT_ଉପର_pc, DW_FORM_data4,
#ଅନ୍ୟଥା
          DW_AT_ଉପର_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_TAG_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ଧାଡ଼ି, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ତଳ_pc, DW_FORM_addr,
#ଯଦି PTR_SIZE == 4
          DW_AT_ଉପର_pc, DW_FORM_data4,
#ଅନ୍ୟଥା
          DW_AT_ଉପର_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_BLOCK, DW_TAG_lexical_block, 1,
          DW_AT_ତଳ_pc, DW_FORM_addr,
#ଯଦି PTR_SIZE == 4
          DW_AT_ଉପର_pc, DW_FORM_data4,
#ଅନ୍ୟଥା
          DW_AT_ଉପର_pc, DW_FORM_data8,
#endif
          0, 0,
    DWARF_ABBREV_LEXICAL_EMPTY_BLOCK, DW_TAG_lexical_block, 0,
          DW_AT_ତଳ_pc, DW_FORM_addr,
#ଯଦି PTR_SIZE == 4
          DW_AT_ଉପର_pc, DW_FORM_data4,
#ଅନ୍ୟଥା
          DW_AT_ଉପର_pc, DW_FORM_data8,
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

ସ୍ଥିର ଅଚଳ unsigned ଅକ୍ଷର dwarf_ଧାଡ଼ି_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#define N_STR_HASH (251)

ସଂରଚନା dwarf_str_hash {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା len;
    unsigned long data_offset;
    ସଂରଚନା dwarf_str_hash *next;
};

ସଂରଚନା _tccdbg {

    ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_ଧାଡ଼ି_ଅଙ୍କ, new_file;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା section_sym;

    ପୂର୍ଣ୍ଣସଂଖ୍ୟା debug_next_type;

    ସଂରଚନା _debug_hash {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା debug_type;
        Sym *type;
    } *debug_hash_global, *debug_hash_local;

    /* store forward structure/unions types */
    ସଂରଚନା _debug_forw_hash {
        Sym *type;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_debug_type;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା *debug_type;
    } *debug_forw_hash_global, *debug_forw_hash_local;

    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_debug_hash_global;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_debug_hash_local;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_debug_forw_hash_global;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_debug_forw_hash_local;

    ସଂରଚନା _debug_info {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା start;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା end;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_debug_hash;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_debug_forw_hash;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_sym;
        ସଂରଚନା debug_sym {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା type;
            unsigned long ମୂଲ୍ୟ;
            ଅକ୍ଷର *str;
            Section *sec;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_index;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା info;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା file;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି;
        } *sym;
        ସଂରଚନା _debug_info *child, *next, *last, *parent;
    } *debug_info, *debug_info_ମୂଳ;

    ସଂରଚନା {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା info;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା abbrev;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା str;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି_str;
    } dwarf_sym;

    ସଂରଚନା {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା start;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା dir_size;
        ଅକ୍ଷର **dir_table;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା filename_size;
        ସଂରଚନା dwarf_filename_struct {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା dir_entry;
            ଅକ୍ଷର *name;
        } *filename_table;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି_size;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି_max_size;
        unsigned ଅକ୍ଷର *ଧାଡ଼ି_data;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା cur_file;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_file;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_pc;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_ଧାଡ଼ି;
    } dwarf_ଧାଡ଼ି;

    ସଂରଚନା {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା start;
        Sym *func;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା base_type_used[N_DEFAULT_DEBUG];
    } dwarf_info;

    ସଂରଚନା dwarf_str_hash *dwarf_str[N_STR_HASH];
    ସଂରଚନା dwarf_str_hash *dwarf_ଧାଡ଼ି_str[N_STR_HASH];

    /* test coverage */
    ସଂରଚନା {
        unsigned long offset;
        unsigned long last_file_name;
        unsigned long last_func_name;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ind;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି;
    } tcov_data;
};

#define last_ଧାଡ଼ି_ଅଙ୍କ             s1->dState->last_ଧାଡ଼ି_ଅଙ୍କ
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
#define debug_info_ମୂଳ           s1->dState->debug_info_ମୂଳ
#define dwarf_sym                 s1->dState->dwarf_sym
#define dwarf_ଧାଡ଼ି                s1->dState->dwarf_ଧାଡ଼ି
#define dwarf_info                s1->dState->dwarf_info
#define dwarf_str                 s1->dState->dwarf_str
#define dwarf_ଧାଡ଼ି_str            s1->dState->dwarf_ଧାଡ଼ି_str
#define tcov_data                 s1->dState->tcov_data

#define	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା put_stabs(TCCState *s1, ଅଚଳ ଅକ୍ଷର *str, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା other,
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା desc, unsigned long ମୂଲ୍ୟ);

ST_FUNC ଶୂନ୍ୟ tcc_debug_new(TCCState *s1)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା shf = 0;
    ଯଦି (!s1->dState)
        s1->dState = tcc_mallocz(ଆକାର *s1->dState);

#ifdef CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    ଯଦି (s1->do_debug && s1->output_type == TCC_OUTPUT_MEMORY)
        s1->do_backtrace = 1;
    ଯଦି (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#endif

    ଯଦି (s1->dwarf) {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	ସ୍ଥିର ଅଚଳ ଅକ୍ଷର *ଅଚଳ debug[] = {
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
        dwarf_ଧାଡ଼ି_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	ପାଇଁ (i = 0; i < ଆକାର(debug)/ଆକାର(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_MERGE | SHF_STRINGS;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_ଧାଡ଼ି_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	ଯଦି (s1->dwarf >= 5) {
            dwarf_ଧାଡ଼ି_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_ଧାଡ଼ି_str_section->sh_entsize = 1;
	    dwarf_ଧାଡ଼ି_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    ଅନ୍ୟଥା
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = ଆକାର(Stab_Sym);
        stab_section->sh_addralign = ଆକାର ((Stab_Sym*)0)->n_ମୂଲ୍ୟ;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା put_stabs(TCCState *s1, ଅଚଳ ଅକ୍ଷର *str, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା other, ପୂର୍ଣ୍ଣସଂଖ୍ୟା desc,
                      unsigned long ମୂଲ୍ୟ)
{
    Stab_Sym *sym;

    unsigned offset;
    ଯଦି (type == N_SLINE
        && (offset = stab_section->data_offset)
        && (sym = (Stab_Sym*)(stab_section->data + offset) - 1)
        && sym->n_type == type
        && sym->n_ମୂଲ୍ୟ == ମୂଲ୍ୟ) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        ଫେରନ୍ତୁ 0;
    }

    sym = section_ptr_add(stab_section, ଆକାର(Stab_Sym));
    ଯଦି (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } ଅନ୍ୟଥା {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_ମୂଲ୍ୟ = ମୂଲ୍ୟ;
    ଫେରନ୍ତୁ 1;
}

ସ୍ଥିର ଶୂନ୍ୟ put_stabs_r(TCCState *s1, ଅଚଳ ଅକ୍ଷର *str, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା other, ପୂର୍ଣ୍ଣସଂଖ୍ୟା desc,
                        unsigned long ମୂଲ୍ୟ, Section *sec, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_index)
{
    ଯଦି (put_stabs(s1, str, type, other, desc, ମୂଲ୍ୟ))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->data_offset - 4,
                      ଆକାର ((Stab_Sym*)0)->n_ମୂଲ୍ୟ == PTR_SIZE ? R_DATA_PTR : R_DATA_32,
                      sym_index);
}

ସ୍ଥିର ଶୂନ୍ୟ put_stabn(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା other, ପୂର୍ଣ୍ଣସଂଖ୍ୟା desc, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ)
{
    put_stabs(s1, ଖାଲି, type, other, desc, ମୂଲ୍ୟ);
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

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    ଫେରନ୍ତୁ put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_ଅଙ୍କ, ଖାଲି);
}

ସ୍ଥିର ଶୂନ୍ୟ dwarf_reloc(Section *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->data_offset, rel, sym, 0);
}

ସ୍ଥିର ଶୂନ୍ୟ free_str(ସଂରଚନା dwarf_str_hash **str)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

    ପାଇଁ (i = 0; i < N_STR_HASH; i++) {
       ଯେତେବେଳେ (str[i]) {
           ସଂରଚନା dwarf_str_hash *next = str[i]->next;

           tcc_free(str[i]);
           str[i] = next;
       }
    }
}

ସ୍ଥିର unsigned str_hash(ଅଚଳ ଅକ୍ଷର *s)
{
    unsigned h = 5381;

    ଯେତେବେଳେ (*s)
       h += (*s++ & 0xffu) + h * 31;
    ଫେରନ୍ତୁ h;
}

ସ୍ଥିର ଶୂନ୍ୟ dwarf_string(Section *s, Section *dw, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym, ଅଚଳ ଅକ୍ଷର *str)
{
    TCCState *s1 = s->s1;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା len, hash = str_hash(str) % N_STR_HASH;
    ଅକ୍ଷର *ptr;
    ସଂରଚନା dwarf_str_hash *new_hash;
    ସଂରଚନା dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_ଧାଡ଼ି_str;

    len = strlen(str) + 1;
    new_hash = dw_hash[hash];
    ଯେତେବେଳେ (new_hash) {
	ଯଦି (new_hash->len == len &&
	    !memcmp(str, dw->data + new_hash->data_offset, len))
	    ଭାଙ୍ଗ;
	new_hash = new_hash->next;
    }
    ଯଦି (new_hash == ଖାଲି) {
	unsigned long offset = dw->data_offset;

        new_hash = dw_hash[hash];
        ଯେତେବେଳେ (new_hash) {
	    unsigned long n = new_hash->data_offset + new_hash->len - len;

	    ଯଦି (new_hash->len > len &&
	        !memcmp(str, dw->data + n, len)) {
		offset = n;
		ଭାଙ୍ଗ;
	    }
	    new_hash = new_hash->next;
        }
	ଯଦି (new_hash == ଖାଲି) {
	    ptr = section_ptr_add(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (ସଂରଚନା dwarf_str_hash *)
	    tcc_malloc(ଆକାର(ସଂରଚନା dwarf_str_hash));
	new_hash->len = len;
	new_hash->data_offset = offset;
	new_hash->next = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->data_offset, R_DATA_32DW, sym,
                   PTR_SIZE == 4 ? 0 : new_hash->data_offset);
    dwarf_data4(s, PTR_SIZE == 4 ? new_hash->data_offset : 0);
}

ସ୍ଥିର ଶୂନ୍ୟ dwarf_strp(Section *s, ଅଚଳ ଅକ୍ଷର *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

ସ୍ଥିର ଶୂନ୍ୟ dwarf_ଧାଡ଼ି_strp(Section *s, ଅଚଳ ଅକ୍ଷର *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_ଧାଡ଼ି_str_section, dwarf_sym.ଧାଡ଼ି_str, str);
}

ସ୍ଥିର ଶୂନ୍ୟ dwarf_ଧାଡ଼ି_op(TCCState *s1, unsigned ଅକ୍ଷର op)
{
    ଯଦି (dwarf_ଧାଡ଼ି.ଧାଡ଼ି_size >= dwarf_ଧାଡ଼ି.ଧାଡ଼ି_max_size) {
	dwarf_ଧାଡ଼ି.ଧାଡ଼ି_max_size += 1024;
	dwarf_ଧାଡ଼ି.ଧାଡ଼ି_data =
	    (unsigned ଅକ୍ଷର *)tcc_realloc(dwarf_ଧାଡ଼ି.ଧାଡ଼ି_data,
					 dwarf_ଧାଡ଼ି.ଧାଡ଼ି_max_size);
    }
    dwarf_ଧାଡ଼ି.ଧାଡ଼ି_data[dwarf_ଧାଡ଼ି.ଧାଡ଼ି_size++] = op;
}

ସ୍ଥିର ଶୂନ୍ୟ dwarf_file(TCCState *s1)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j;
    ଅକ୍ଷର *filename;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା index_offset = s1->dwarf < 5;

    ଯଦି (!strcmp(file->filename, "<command line>")) {
        dwarf_ଧାଡ଼ି.cur_file = 1;
	ଫେରନ୍ତୁ;
    }
    filename = strrchr(file->filename, '/');
    ଯଦି (filename == ଖାଲି) {
        ପାଇଁ (i = 1; i < dwarf_ଧାଡ଼ି.filename_size; i++)
            ଯଦି (dwarf_ଧାଡ଼ି.filename_table[i].dir_entry == 0 &&
		strcmp(dwarf_ଧାଡ଼ି.filename_table[i].name,
		       file->filename) == 0) {
		    dwarf_ଧାଡ଼ି.cur_file = i + index_offset;
	            ଫେରନ୍ତୁ;
		}
	i = -index_offset;
	filename = file->filename;
    }
    ଅନ୍ୟଥା {
	ଅକ୍ଷର *undo = filename;
	ଅକ୍ଷର *dir = file->filename;

	*filename++ = '\0';
        ପାଇଁ (i = 0; i < dwarf_ଧାଡ଼ି.dir_size; i++)
	    ଯଦି (strcmp(dwarf_ଧାଡ଼ି.dir_table[i], dir) == 0) {
		ପାଇଁ (j = 1; j < dwarf_ଧାଡ଼ି.filename_size; j++)
		    ଯଦି (dwarf_ଧାଡ଼ି.filename_table[j].dir_entry - index_offset
			== i &&
			strcmp(dwarf_ଧାଡ଼ି.filename_table[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_ଧାଡ଼ି.cur_file = j + index_offset;
			ଫେରନ୍ତୁ;
		    }
		ଭାଙ୍ଗ;
	    }
	ଯଦି (i == dwarf_ଧାଡ଼ି.dir_size) {
	    dwarf_ଧାଡ଼ି.dir_size++;
	    dwarf_ଧାଡ଼ି.dir_table =
                (ଅକ୍ଷର **) tcc_realloc(dwarf_ଧାଡ଼ି.dir_table,
                                      dwarf_ଧାଡ଼ି.dir_size *
                                      ଆକାର (ଅକ୍ଷର *));
            dwarf_ଧାଡ଼ି.dir_table[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_ଧାଡ଼ି.filename_table =
        (ସଂରଚନା dwarf_filename_struct *)
        tcc_realloc(dwarf_ଧାଡ଼ି.filename_table,
                    (dwarf_ଧାଡ଼ି.filename_size + 1) *
                    ଆକାର (ସଂରଚନା dwarf_filename_struct));
    dwarf_ଧାଡ଼ି.filename_table[dwarf_ଧାଡ଼ି.filename_size].dir_entry =
	i + index_offset;
    dwarf_ଧାଡ଼ି.filename_table[dwarf_ଧାଡ଼ି.filename_size].name =
        tcc_strdup(filename);
    dwarf_ଧାଡ଼ି.cur_file = dwarf_ଧାଡ଼ି.filename_size++ + index_offset;
    ଫେରନ୍ତୁ;
}

#ଯଦି 0
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା dwarf_uleb128_size (unsigned long long ମୂଲ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size =  0;

    କର {
        ମୂଲ୍ୟ >>= 7;
        size++;
    } ଯେତେବେଳେ (ମୂଲ୍ୟ != 0);
    ଫେରନ୍ତୁ size;
}
#endif

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା dwarf_sleb128_size (long long ମୂଲ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size =  0;
    long long end = ମୂଲ୍ୟ >> 63;
    unsigned ଅକ୍ଷର last = end & 0x40;
    unsigned ଅକ୍ଷର byte;

    କର {
        byte = ମୂଲ୍ୟ & 0x7f;
        ମୂଲ୍ୟ >>= 7;
        size++;
    } ଯେତେବେଳେ (ମୂଲ୍ୟ != end || (byte & 0x40) != last);
    ଫେରନ୍ତୁ size;
}

ସ୍ଥିର ଶୂନ୍ୟ dwarf_uleb128 (Section *s, unsigned long long ମୂଲ୍ୟ)
{
    କର {
        unsigned ଅକ୍ଷର byte = ମୂଲ୍ୟ & 0x7f;

        ମୂଲ୍ୟ >>= 7;
        dwarf_data1(s, byte | (ମୂଲ୍ୟ ? 0x80 : 0));
    } ଯେତେବେଳେ (ମୂଲ୍ୟ != 0);
}

ସ୍ଥିର ଶୂନ୍ୟ dwarf_sleb128 (Section *s, long long ମୂଲ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା more;
    long long end = ମୂଲ୍ୟ >> 63;
    unsigned ଅକ୍ଷର last = end & 0x40;

    କର {
        unsigned ଅକ୍ଷର byte = ମୂଲ୍ୟ & 0x7f;

        ମୂଲ୍ୟ >>= 7;
	more = ମୂଲ୍ୟ != end || (byte & 0x40) != last;
        dwarf_data1(s, byte | (0x80 * more));
    } ଯେତେବେଳେ (more);
}

ସ୍ଥିର ଶୂନ୍ୟ dwarf_uleb128_op (TCCState *s1, unsigned long long ମୂଲ୍ୟ)
{
    କର {
        unsigned ଅକ୍ଷର byte = ମୂଲ୍ୟ & 0x7f;

        ମୂଲ୍ୟ >>= 7;
        dwarf_ଧାଡ଼ି_op(s1, byte | (ମୂଲ୍ୟ ? 0x80 : 0));
    } ଯେତେବେଳେ (ମୂଲ୍ୟ != 0);
}

ସ୍ଥିର ଶୂନ୍ୟ dwarf_sleb128_op (TCCState *s1, long long ମୂଲ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା more;
    long long end = ମୂଲ୍ୟ >> 63;
    unsigned ଅକ୍ଷର last = end & 0x40;

    କର {
        unsigned ଅକ୍ଷର byte = ମୂଲ୍ୟ & 0x7f;

        ମୂଲ୍ୟ >>= 7;
        more = ମୂଲ୍ୟ != end || (byte & 0x40) != last;
        dwarf_ଧାଡ଼ି_op(s1, byte | (0x80 * more));
    } ଯେତେବେଳେ (more);
}

#ଯଦି TCC_EH_FRAME
ST_FUNC ଶୂନ୍ୟ tcc_eh_frame_start(TCCState *s1)
{
    ଯଦି (!s1->unwind_tables)
        ଫେରନ୍ତୁ;
    eh_frame_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section, 0); // CIE ID
    dwarf_data1(eh_frame_section, 1); // Version
    dwarf_data1(eh_frame_section, 'z'); // Augmentation String
    dwarf_data1(eh_frame_section, 'R');
    dwarf_data1(eh_frame_section, 0);
#ଯଦି defined TCC_TARGET_I386
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
#ନଚେତଯଦି defined TCC_TARGET_X86_64
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
#ନଚେତଯଦି defined TCC_TARGET_ARM
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
#ନଚେତଯଦି defined TCC_TARGET_ARM64
    dwarf_uleb128(eh_frame_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 30); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 31); // x31 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#ନଚେତଯଦି defined TCC_TARGET_RISCV64
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
    ଯେତେବେଳେ ((eh_frame_section->data_offset - s1->eh_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + s1->eh_start, // length
	      eh_frame_section->data_offset - s1->eh_start - 4);
}

ସ୍ଥିର ଶୂନ୍ୟ tcc_debug_frame_end(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା size)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା eh_section_sym;
    unsigned long fde_start;

    ଯଦି (!eh_frame_section)
	ଫେରନ୍ତୁ;
    eh_section_sym = dwarf_get_section_sym(text_section);
    fde_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section,
		fde_start - s1->eh_start + 4); // CIE Pointer
#ଯଦି defined TCC_TARGET_I386
    dwarf_reloc(eh_frame_section, eh_section_sym, R_386_PC32);
#ନଚେତଯଦି defined TCC_TARGET_X86_64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_X86_64_PC32);
#ନଚେତଯଦି defined TCC_TARGET_ARM
    dwarf_reloc(eh_frame_section, eh_section_sym, R_ARM_REL32);
#ନଚେତଯଦି defined TCC_TARGET_ARM64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_AARCH64_PREL32);
#ନଚେତଯଦି defined TCC_TARGET_RISCV64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_RISCV_32_PCREL);
#endif
    dwarf_data4(eh_frame_section, func_ind); // PC Begin
    dwarf_data4(eh_frame_section, size); // PC Range
    dwarf_data1(eh_frame_section, 0); // Augmentation Length
#ଯଦି defined TCC_TARGET_I386
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
#ନଚେତଯଦି defined TCC_TARGET_X86_64
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
#ନଚେତଯଦି defined TCC_TARGET_ARM
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
#ନଚେତଯଦି defined TCC_TARGET_ARM64
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
#ନଚେତଯଦି defined TCC_TARGET_RISCV64
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
    ଯେତେବେଳେ (size >= 4 &&
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
    ଯେତେବେଳେ ((eh_frame_section->data_offset - fde_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + fde_start, // length
	      eh_frame_section->data_offset - fde_start - 4);
}

ST_FUNC ଶୂନ୍ୟ tcc_eh_frame_end(TCCState *s1)
{
    ଯଦି (!eh_frame_section)
	ଫେରନ୍ତୁ;
    dwarf_data4(eh_frame_section, 0);
}

ସଂରଚନା eh_ସନ୍ଧାନ_table {
    uint32_t pc_offset;
    uint32_t fde_offset;
};

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା sort_eh_table(ଅଚଳ ଶୂନ୍ୟ *a, ଅଚଳ ଶୂନ୍ୟ *b)
{
    uint32_t pc1 = ((ଅଚଳ ସଂରଚନା eh_ସନ୍ଧାନ_table *)a)->pc_offset;
    uint32_t pc2 = ((ଅଚଳ ସଂରଚନା eh_ସନ୍ଧାନ_table *)b)->pc_offset;

    ଫେରନ୍ତୁ pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC ଶୂନ୍ୟ tcc_eh_frame_hdr(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା final)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଗଣନା_3 = 0, offset;
    unsigned long ଗଣନା_offset, tab_offset;
    unsigned ଅକ୍ଷର *ln, *end;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_cie_offset = 0xffffffff;

    ଯଦି (!eh_frame_section || !eh_frame_section->data_offset)
	ଫେରନ୍ତୁ;
    ଯଦି (final && !eh_frame_hdr_section)
	ଫେରନ୍ତୁ;
    ଯଦି (final == 0)
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
    //ଗଣନା
    ଗଣନା_offset = eh_frame_hdr_section->data_offset;
    dwarf_data4(eh_frame_hdr_section, 0);
    tab_offset = eh_frame_hdr_section->data_offset;
    ln = eh_frame_section->data;
    end = eh_frame_section->data + eh_frame_section->data_offset;
    ଯେତେବେଳେ (ln < end) {
	unsigned ଅକ୍ଷର *fde = ln, *rd = ln;
	unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା cie_offset, version, length = dwarf_read_4(rd, end);
	unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା pc_offset, fde_offset;

	ଯଦି (length == 0)
	    ଯାଅ next;
        cie_offset = dwarf_read_4(rd, end);
	ଯଦି (cie_offset == 0)
	    ଯାଅ next;
	ଯଦି (cie_offset != last_cie_offset) {
	    unsigned ଅକ୍ଷର *cie = rd - cie_offset + 4;

	    ଯଦି (cie < eh_frame_section->data)
		ଯାଅ next;
	    version = dwarf_read_1(cie, end);
	    ଯଦି ((version == 1 || version == 3) &&
	        dwarf_read_1(cie, end) == 'z' && // Augmentation String
		dwarf_read_1(cie, end) == 'R' &&
		dwarf_read_1(cie, end) == 0) {
	        dwarf_read_uleb128(&cie, end); // code_alignment_factor
	        dwarf_read_sleb128(&cie, end); // data_alignment_factor
		dwarf_read_1(cie, end); // return address column
		ଯଦି (dwarf_read_uleb128(&cie, end) == 1 &&
		    dwarf_read_1(cie, end) == FDE_ENCODING) {
		    last_cie_offset = cie_offset;
		}
		ଅନ୍ୟଥା
		    ଯାଅ next;
	    }
	    ଅନ୍ୟଥା
		ଯାଅ next;
	}
	ଗଣନା_3++;
	fde_offset = eh_frame_section->sh_addr +
		     (fde - eh_frame_section->data) -
		     eh_frame_hdr_section->sh_addr;
	pc_offset = dwarf_read_4(rd, end) + fde_offset + 8;
	dwarf_data4(eh_frame_hdr_section, pc_offset);
	dwarf_data4(eh_frame_hdr_section, fde_offset);
next:
	ln += length + 4;
    }
    add32le(eh_frame_hdr_section->data + ଗଣନା_offset, ଗଣନା_3);
    qsort(eh_frame_hdr_section->data + tab_offset, ଗଣନା_3,
	  ଆକାର(ସଂରଚନା eh_ସନ୍ଧାନ_table), sort_eh_table);
}
#endif

/* start of translation unit info */
ST_FUNC ଶୂନ୍ୟ tcc_debug_start(TCCState *s1)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ଅକ୍ଷର buf[512];
    ଅକ୍ଷର *filename;

    /* we might currently #include the <command-line> */
    filename = file->prev ? file->prev->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    ଯଦି (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, text_section->data_offset, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            text_section->sh_ଅଙ୍କ, "$a");

        new_file = last_ଧାଡ଼ି_ଅଙ୍କ = 0;
        debug_next_type = N_DEFAULT_DEBUG;
        debug_hash_global = ଖାଲି;
        debug_hash_local = ଖାଲି;
        debug_forw_hash_global = ଖାଲି;
        debug_forw_hash_local = ଖାଲି;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, ଆକାର(buf));
#ifdef _WIN32
        normalize_slashes(buf);
#endif

        ଯଦି (s1->dwarf) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା start_abbrev;
            unsigned ଅକ୍ଷର *ptr;
	    ଅକ୍ଷର *undo;

            /* dwarf_abbrev */
            start_abbrev = dwarf_abbrev_section->data_offset;
            ptr = section_ptr_add(dwarf_abbrev_section, ଆକାର(dwarf_abbrev_init));
            memcpy(ptr, dwarf_abbrev_init, ଆକାର(dwarf_abbrev_init));

            ଯଦି (s1->dwarf < 5) {
    	        ଯେତେବେଳେ (*ptr) {
    	            ptr += 3;
    	            ଯେତେବେଳେ (*ptr) {
    	                ଯଦି (ptr[1] == DW_FORM_ଧାଡ଼ି_strp)
    		            ptr[1] = DW_FORM_strp;
		        ଯଦି (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    ଯଦି  (ptr[1] == DW_FORM_sec_offset)
			         ptr[1] = DW_FORM_data4;
			    /* This code uses only size < 0x80 so these are
			       compatible. */
			    ଯଦି  (ptr[1] == DW_FORM_exprloc)
			         ptr[1] = DW_FORM_block1;
			}
    	                ptr += 2;
    	            }
		    ptr += 2;
    	        }
            }

            dwarf_sym.info = dwarf_get_section_sym(dwarf_info_section);
            dwarf_sym.abbrev = dwarf_get_section_sym(dwarf_abbrev_section);
            dwarf_sym.ଧାଡ଼ି = dwarf_get_section_sym(dwarf_ଧାଡ଼ି_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            ଯଦି (tcc_state->dwarf >= 5)
    	        dwarf_sym.ଧାଡ଼ି_str = dwarf_get_section_sym(dwarf_ଧାଡ଼ି_str_section);
            ଅନ୍ୟଥା {
    	        dwarf_ଧାଡ଼ି_str_section = dwarf_str_section;
                dwarf_sym.ଧାଡ଼ି_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(text_section);

            /* dwarf_info */
            dwarf_info.start = dwarf_info_section->data_offset;
            dwarf_data4(dwarf_info_section, 0); // size
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            ଯଦି (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_SIZE);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_DATA_32DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
            }
            ଅନ୍ୟଥା {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_DATA_32DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
                dwarf_data1(dwarf_info_section, PTR_SIZE);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_VERSION);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_ଧାଡ଼ି_strp(dwarf_info_section, filename);
            dwarf_ଧାଡ଼ି_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#ଯଦି PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#ଅନ୍ୟଥା
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#endif
            dwarf_reloc(dwarf_info_section, dwarf_sym.ଧାଡ଼ି, R_DATA_32DW);
            dwarf_data4(dwarf_info_section, dwarf_ଧାଡ଼ି_section->data_offset); // stmt_list

            /* dwarf_line */
            dwarf_ଧାଡ଼ି.start = dwarf_ଧାଡ଼ି_section->data_offset;
            dwarf_data4(dwarf_ଧାଡ଼ି_section, 0); // length
            dwarf_data2(dwarf_ଧାଡ଼ି_section, s1->dwarf); // version
            ଯଦି (s1->dwarf >= 5) {
                dwarf_data1(dwarf_ଧାଡ଼ି_section, PTR_SIZE); // address size
                dwarf_data1(dwarf_ଧାଡ଼ି_section, 0); // segment selector
            }
            dwarf_data4(dwarf_ଧାଡ଼ି_section, 0); // prologue Length
            dwarf_data1(dwarf_ଧାଡ଼ି_section, DWARF_MIN_INSTR_LEN);
            ଯଦି (s1->dwarf >= 4)
                dwarf_data1(dwarf_ଧାଡ଼ି_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_ଧାଡ଼ି_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_ଧାଡ଼ି_section, DWARF_ଧାଡ଼ି_BASE);
            dwarf_data1(dwarf_ଧାଡ଼ି_section, DWARF_ଧାଡ଼ି_RANGE);
            dwarf_data1(dwarf_ଧାଡ଼ି_section, DWARF_OPCODE_BASE);
            ptr = section_ptr_add(dwarf_ଧାଡ଼ି_section, ଆକାର(dwarf_ଧାଡ଼ି_opcodes));
            memcpy(ptr, dwarf_ଧାଡ଼ି_opcodes, ଆକାର(dwarf_ଧାଡ଼ି_opcodes));
	    undo = strrchr(filename, '/');
	    ଯଦି (undo)
		*undo = 0;
            dwarf_ଧାଡ଼ି.dir_size = 1 + (undo != ଖାଲି);
            dwarf_ଧାଡ଼ି.dir_table = (ଅକ୍ଷର **) tcc_malloc(ଆକାର (ଅକ୍ଷର *) *
							dwarf_ଧାଡ଼ି.dir_size);
            dwarf_ଧାଡ଼ି.dir_table[0] = tcc_strdup(buf);
	    ଯଦି (undo)
                dwarf_ଧାଡ଼ି.dir_table[1] = tcc_strdup(filename);
            dwarf_ଧାଡ଼ି.filename_size = 2;
            dwarf_ଧାଡ଼ି.filename_table =
    	        (ସଂରଚନା dwarf_filename_struct *)
    	        tcc_malloc(2*ଆକାର (ସଂରଚନା dwarf_filename_struct));
            dwarf_ଧାଡ଼ି.filename_table[0].dir_entry = 0;
	    ଯଦି (undo) {
                dwarf_ଧାଡ଼ି.filename_table[0].name = tcc_strdup(undo + 1);
                dwarf_ଧାଡ଼ି.filename_table[1].dir_entry = 1;
                dwarf_ଧାଡ଼ି.filename_table[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    ଅନ୍ୟଥା {
                dwarf_ଧାଡ଼ି.filename_table[0].name = tcc_strdup(filename);
                dwarf_ଧାଡ଼ି.filename_table[1].dir_entry = 0;
                dwarf_ଧାଡ଼ି.filename_table[1].name = tcc_strdup(filename);
	    }
            dwarf_ଧାଡ଼ି.ଧାଡ଼ି_size = dwarf_ଧାଡ଼ି.ଧାଡ଼ି_max_size = 0;
            dwarf_ଧାଡ଼ି.ଧାଡ଼ି_data = ଖାଲି;
            dwarf_ଧାଡ଼ି.cur_file = 1;
            dwarf_ଧାଡ଼ି.last_file = 0;
            dwarf_ଧାଡ଼ି.last_pc = 0;
            dwarf_ଧାଡ଼ି.last_ଧାଡ଼ି = 1;
            dwarf_ଧାଡ଼ି_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_SIZE); // extended size
            dwarf_ଧାଡ଼ି_op(s1, DW_LNE_set_address);
            ପାଇଁ (i = 0; i < PTR_SIZE; i++)
    	        dwarf_ଧାଡ଼ି_op(s1, 0);
            memset(&dwarf_info.base_type_used, 0, ଆକାର(dwarf_info.base_type_used));
        }
        ଅନ୍ୟଥା
        {
            /* file info: full path + filename */
            pstrcat(buf, ଆକାର(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      text_section->sh_ଅଙ୍କ, ଖାଲି);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            ପାଇଁ (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

ସ୍ଥିର ଶୂନ୍ୟ fix_debug_forw_hash(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା global, ପୂର୍ଣ୍ଣସଂଖ୍ୟା start);

/* put end of translation unit info */
ST_FUNC ଶୂନ୍ୟ tcc_debug_end(TCCState *s1)
{

    ଯଦି (!s1->do_debug || debug_next_type == 0)
        ଫେରନ୍ତୁ;

    ଯଦି (debug_info_ମୂଳ)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    ଯଦି (s1->dwarf) {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା start_aranges;
	unsigned ଅକ୍ଷର *ptr;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା text_size = text_section->data_offset;

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
#ଯଦି PTR_SIZE == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#ଅନ୍ୟଥା
	dwarf_data1(dwarf_aranges_section, 8); // address size
#endif
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_DATA_PTR);
#ଯଦି PTR_SIZE == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, text_size); // End
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#ଅନ୍ୟଥା
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, text_size); // End
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#endif
	ptr = dwarf_aranges_section->data + start_aranges;
	write32le(ptr, dwarf_aranges_section->data_offset - start_aranges - 4);

	/* dwarf_line */
	ଯଦି (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_ଧାଡ଼ି_section, 1); /* col */
	    dwarf_uleb128(dwarf_ଧାଡ଼ି_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_ଧାଡ଼ି_section, DW_FORM_ଧାଡ଼ି_strp);
	    dwarf_uleb128(dwarf_ଧାଡ଼ି_section, dwarf_ଧାଡ଼ି.dir_size);
	    ପାଇଁ (i = 0; i < dwarf_ଧାଡ଼ି.dir_size; i++)
	        dwarf_ଧାଡ଼ି_strp(dwarf_ଧାଡ଼ି_section, dwarf_ଧାଡ଼ି.dir_table[i]);
	    dwarf_data1(dwarf_ଧାଡ଼ି_section, 2); /* col */
	    dwarf_uleb128(dwarf_ଧାଡ଼ି_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_ଧାଡ଼ି_section, DW_FORM_ଧାଡ଼ି_strp);
	    dwarf_uleb128(dwarf_ଧାଡ଼ି_section, DW_LNCT_directory_index);
	    dwarf_uleb128(dwarf_ଧାଡ଼ି_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_ଧାଡ଼ି_section, dwarf_ଧାଡ଼ି.filename_size);
	    ପାଇଁ (i = 0; i < dwarf_ଧାଡ଼ି.filename_size; i++) {
	        dwarf_ଧାଡ଼ି_strp(dwarf_ଧାଡ଼ି_section,
				dwarf_ଧାଡ଼ି.filename_table[i].name);
	        dwarf_uleb128(dwarf_ଧାଡ଼ି_section,
			      dwarf_ଧାଡ଼ି.filename_table[i].dir_entry);
	    }
	}
	ଅନ୍ୟଥା {
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା len;

	    ପାଇଁ (i = 0; i < dwarf_ଧାଡ଼ି.dir_size; i++) {
	        len = strlen(dwarf_ଧାଡ଼ି.dir_table[i]) + 1;
	        ptr = section_ptr_add(dwarf_ଧାଡ଼ି_section, len);
	        memmove(ptr, dwarf_ଧାଡ଼ି.dir_table[i], len);
	    }
	    dwarf_data1(dwarf_ଧାଡ଼ି_section, 0); /* end dir */
	    ପାଇଁ (i = 0; i < dwarf_ଧାଡ଼ି.filename_size; i++) {
	        len = strlen(dwarf_ଧାଡ଼ି.filename_table[i].name) + 1;
	        ptr = section_ptr_add(dwarf_ଧାଡ଼ି_section, len);
	        memmove(ptr, dwarf_ଧାଡ଼ି.filename_table[i].name, len);
	        dwarf_uleb128(dwarf_ଧାଡ଼ି_section,
			      dwarf_ଧାଡ଼ି.filename_table[i].dir_entry);
	        dwarf_uleb128(dwarf_ଧାଡ଼ି_section, 0); /* time */
	        dwarf_uleb128(dwarf_ଧାଡ଼ି_section, 0); /* size */
	    }
	    dwarf_data1(dwarf_ଧାଡ଼ି_section, 0); /* end file */
	}
	ପାଇଁ (i = 0; i < dwarf_ଧାଡ଼ି.dir_size; i++)
	    tcc_free(dwarf_ଧାଡ଼ି.dir_table[i]);
	tcc_free(dwarf_ଧାଡ଼ି.dir_table);
	ପାଇଁ (i = 0; i < dwarf_ଧାଡ଼ି.filename_size; i++)
	    tcc_free(dwarf_ଧାଡ଼ି.filename_table[i].name);
	tcc_free(dwarf_ଧାଡ଼ି.filename_table);

	dwarf_ଧାଡ଼ି_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_ଧାଡ଼ି_op(s1, DW_LNE_end_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_ଧାଡ଼ି_section->data[dwarf_ଧାଡ଼ି.start + 6 + i],
		  dwarf_ଧାଡ଼ି_section->data_offset - dwarf_ଧାଡ଼ି.start - (10 + i));
	section_ptr_add(dwarf_ଧାଡ଼ି_section, 3);
	dwarf_reloc(dwarf_ଧାଡ଼ି_section, section_sym, R_DATA_PTR);
	ptr = section_ptr_add(dwarf_ଧାଡ଼ି_section, dwarf_ଧାଡ଼ି.ଧାଡ଼ି_size - 3);
	memmove(ptr - 3, dwarf_ଧାଡ଼ି.ଧାଡ଼ି_data, dwarf_ଧାଡ଼ି.ଧାଡ଼ି_size);
	tcc_free(dwarf_ଧାଡ଼ି.ଧାଡ଼ି_data);
	write32le(dwarf_ଧାଡ଼ି_section->data + dwarf_ଧାଡ଼ି.start,
		  dwarf_ଧାଡ଼ି_section->data_offset - dwarf_ଧାଡ଼ି.start - 4);
    }
    ଅନ୍ୟଥା
    {
        put_stabs_r(s1, ଖାଲି, N_SO, 0, 0,
                    text_section->data_offset, text_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_ଧାଡ଼ି_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_next_type = 0;
}

ସ୍ଥିର BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    ଯଦି (f->filename[0] == ':')
        f = f->prev;
    ଯଦି (f && new_file) {
        new_file = last_ଧାଡ଼ି_ଅଙ୍କ = 0;
        ଯଦି (s1->dwarf)
            dwarf_file(s1);
        ଅନ୍ୟଥା
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, text_section, section_sym);
    }
    ଫେରନ୍ତୁ f;
}

/* put alternative filename */
ST_FUNC ଶୂନ୍ୟ tcc_debug_newfile(TCCState *s1)
{
    ଯଦି (!s1->do_debug)
        ଫେରନ୍ତୁ;
    ଯଦି (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC ଶୂନ୍ୟ tcc_debug_bincl(TCCState *s1)
{
    ଯଦି (!s1->do_debug)
        ଫେରନ୍ତୁ;
    ଯଦି (s1->dwarf)
        dwarf_file(s1);
    ଅନ୍ୟଥା
        put_stabs(s1, file->filename, N_BINCL, 0, 0, 0);
    new_file = 1;
}

/* end of #include */
ST_FUNC ଶୂନ୍ୟ tcc_debug_eincl(TCCState *s1)
{
    ଯଦି (!s1->do_debug)
        ଫେରନ୍ତୁ;
    ଯଦି (s1->dwarf)
        dwarf_file(s1);
    ଅନ୍ୟଥା
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC ଶୂନ୍ୟ tcc_debug_ଧାଡ଼ି(TCCState *s1)
{
    BufferedFile *f;

    ଯଦି (!s1->do_debug)
        ଫେରନ୍ତୁ;
    ଯଦି (cur_text_section != text_section || nocode_wanted)
        ଫେରନ୍ତୁ;
    f = put_new_file(s1);
    ଯଦି (!f)
        ଫେରନ୍ତୁ;
    ଯଦି (last_ଧାଡ଼ି_ଅଙ୍କ == f->ଧାଡ଼ି_ଅଙ୍କ)
        ଫେରନ୍ତୁ;
    last_ଧାଡ଼ି_ଅଙ୍କ = f->ଧାଡ଼ି_ଅଙ୍କ;

    ଯଦି (s1->dwarf) {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା len_pc = (ind - dwarf_ଧାଡ଼ି.last_pc) / DWARF_MIN_INSTR_LEN;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା len_ଧାଡ଼ି = f->ଧାଡ଼ି_ଅଙ୍କ - dwarf_ଧାଡ଼ି.last_ଧାଡ଼ି;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା n = len_pc * DWARF_ଧାଡ଼ି_RANGE + len_ଧାଡ଼ି + DWARF_OPCODE_BASE - DWARF_ଧାଡ଼ି_BASE;

	ଯଦି (dwarf_ଧାଡ଼ି.cur_file != dwarf_ଧାଡ଼ି.last_file) {
	    dwarf_ଧାଡ଼ି.last_file = dwarf_ଧାଡ଼ି.cur_file;
	    dwarf_ଧାଡ଼ି_op(s1, DW_LNS_set_file);
	    dwarf_uleb128_op(s1, dwarf_ଧାଡ଼ି.cur_file);
	}
	ଯଦି (len_pc &&
	    len_ଧାଡ଼ି >= DWARF_ଧାଡ଼ି_BASE && len_ଧାଡ଼ି <= (DWARF_OPCODE_BASE + DWARF_ଧାଡ଼ି_BASE) &&
	    n >= DWARF_OPCODE_BASE && n <= 255)
            dwarf_ଧାଡ଼ି_op(s1, n);
	ଅନ୍ୟଥା {
	    ଯଦି (len_pc) {
	        n = len_pc * DWARF_ଧାଡ଼ି_RANGE + 0 + DWARF_OPCODE_BASE - DWARF_ଧାଡ଼ି_BASE;
	        ଯଦି (n >= DWARF_OPCODE_BASE && n <= 255)
                    dwarf_ଧାଡ଼ି_op(s1, n);
		ଅନ୍ୟଥା {
	            dwarf_ଧାଡ଼ି_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    ଯଦି (len_ଧାଡ଼ି) {
	        n = 0 * DWARF_ଧାଡ଼ି_RANGE + len_ଧାଡ଼ି + DWARF_OPCODE_BASE - DWARF_ଧାଡ଼ି_BASE;
	        ଯଦି (len_ଧାଡ଼ି >= DWARF_ଧାଡ଼ି_BASE && len_ଧାଡ଼ି <= (DWARF_OPCODE_BASE + DWARF_ଧାଡ଼ି_BASE) &&
		    n >= DWARF_OPCODE_BASE && n <= 255)
	            dwarf_ଧାଡ଼ି_op(s1, n);
		ଅନ୍ୟଥା {
	            dwarf_ଧାଡ଼ି_op(s1, DW_LNS_advance_ଧାଡ଼ି);
		    dwarf_sleb128_op(s1, len_ଧାଡ଼ି);
                    /* advance by nothing */
	            dwarf_ଧାଡ଼ି_op(s1, DWARF_OPCODE_BASE - DWARF_ଧାଡ଼ି_BASE);
		}
	    }
	}
	dwarf_ଧାଡ଼ି.last_pc = ind;
	dwarf_ଧାଡ଼ି.last_ଧାଡ଼ି = f->ଧାଡ଼ି_ଅଙ୍କ;
    }
    ଅନ୍ୟଥା
    {
	ଯଦି (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->ଧାଡ଼ି_ଅଙ୍କ, ind - func_ind);
        } ଅନ୍ୟଥା {
            /* from tcc_assemble */
            put_stabs_r(s1, ଖାଲି, N_SLINE, 0, f->ଧାଡ଼ି_ଅଙ୍କ, ind, text_section, section_sym);
        }
    }
}

ସ୍ଥିର ଶୂନ୍ୟ tcc_debug_stabs (TCCState *s1, ଅଚଳ ଅକ୍ଷର *str, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, unsigned long ମୂଲ୍ୟ,
                             Section *sec, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_index, ପୂର୍ଣ୍ଣସଂଖ୍ୟା info)
{
    ସଂରଚନା debug_sym *s;

    ଯଦି (debug_info) {
        debug_info->sym =
            (ସଂରଚନା debug_sym *)tcc_realloc (debug_info->sym,
                                             ଆକାର(ସଂରଚନା debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->ମୂଲ୍ୟ = ମୂଲ୍ୟ;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_index = sym_index;
        s->info = info;
        s->file = dwarf_ଧାଡ଼ି.cur_file;
        s->ଧାଡ଼ି = file->ଧାଡ଼ି_ଅଙ୍କ;
    }
    ଅନ୍ୟଥା ଯଦି (sec)
        put_stabs_r (s1, str, type, 0, 0, ମୂଲ୍ୟ, sec, sym_index);
    ଅନ୍ୟଥା
        put_stabs (s1, str, type, 0, 0, ମୂଲ୍ୟ);
}

ସ୍ଥିର ଶୂନ୍ୟ fix_debug_forw_hash(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା global, ପୂର୍ଣ୍ଣସଂଖ୍ୟା start)
{
    ଯଦି (s1->dwarf) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	ସଂରଚନା _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	ପାଇଁ (i = start; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା pos = dwarf_info_section->data_offset;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_EMPTY_TYPE
                                             : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, ଖାଲି));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_ଧାଡ଼ି.cur_file);
            dwarf_uleb128(dwarf_info_section, file->ଧାଡ଼ି_ଅଙ୍କ);
	    ପାଇଁ (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->data +
			  hash[i].debug_type[j],
			  pos - dwarf_info.start);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC ଶୂନ୍ୟ tcc_debug_stabn(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ)
{
    ଯଦି (!s1->do_debug)
        ଫେରନ୍ତୁ;
    ଯଦି (type == N_LBRAC) {
        ସଂରଚନା _debug_info *info =
            (ସଂରଚନା _debug_info *) tcc_mallocz(ଆକାର (*info));

        info->start = ମୂଲ୍ୟ;
        info->last_debug_hash = n_debug_hash_local;
        info->last_debug_forw_hash = n_debug_forw_hash_local;
        info->parent = debug_info;
        ଯଦି (debug_info) {
            ଯଦି (debug_info->child) {
                ଯଦି (debug_info->child->last)
                    debug_info->child->last->next = info;
                ଅନ୍ୟଥା
                    debug_info->child->next = info;
                debug_info->child->last = info;
            }
            ଅନ୍ୟଥା
                debug_info->child = info;
        }
        ଅନ୍ୟଥା
            debug_info_ମୂଳ = info;
        debug_info = info;
    }
    ଅନ୍ୟଥା {
	fix_debug_forw_hash(s1, 0, debug_info->last_debug_forw_hash);
        n_debug_hash_local = debug_info->last_debug_hash;
        n_debug_forw_hash_local = debug_info->last_debug_forw_hash;
        debug_info->end = ମୂଲ୍ୟ;
        debug_info = debug_info->parent;
    }
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା check_global(Sym *t)
{
    Sym *g = local_ଗଦା;

    ଯେତେବେଳେ (g) {
	ଯଦି (t == g)
	    ଫେରନ୍ତୁ 0;
	g = g->prev;
    }
    ଫେରନ୍ତୁ 1;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_debug_find(TCCState *s1, Sym *t, ପୂର୍ଣ୍ଣସଂଖ୍ୟା dwarf)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i , g = check_global(t);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_hash, *n_forw_hash;
    ସଂରଚନା _debug_hash *hash;
    ସଂରଚନା _debug_forw_hash **forw_hash;

    ଯଦି ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	ପାଇଁ (i = 0; i < *n_forw_hash; i++)
            ଯଦି (t == (*forw_hash)[i].type)
		ଫେରନ୍ତୁ 0;
	*forw_hash = (ସଂରଚନା _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * ଆକାର(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = ଖାଲି;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	ଫେରନ୍ତୁ 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    ପାଇଁ (i = 0; i < n_hash; i++)
        ଯଦି (t == hash[i].type)
	    ଫେରନ୍ତୁ hash[i].debug_type;
    ଫେରନ୍ତୁ -1;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_get_dwarf_info(TCCState *s1, Sym *s);

ସ୍ଥିର ଶୂନ୍ୟ tcc_debug_check_forw(TCCState *s1, Sym *t, ପୂର୍ଣ୍ଣସଂଖ୍ୟା debug_type)
{
    ଯଦି ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j, g = check_global(t);
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_forw_hash;
        ସଂରଚନା _debug_forw_hash **forw_hash;

	ପାଇଁ (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    ପାଇଁ (j = 0; j < n_forw_hash; j++)
                ଯଦି (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    ଫେରନ୍ତୁ;
                }
	}
    }
}

ସ୍ଥିର ଶୂନ୍ୟ stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC ଶୂନ୍ୟ tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    ଯଦି (!(s1->do_debug & 2))
	ଫେରନ୍ତୁ;
    ଯଦି (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        ଫେରନ୍ତୁ;
    }
    ଯଦି ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j, debug_type, g = check_global(t->ref);
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା *n_forw_hash;
        ସଂରଚନା _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	ପାଇଁ (i = 0; i < *n_forw_hash; i++)
	    ଯଦି (t->ref == (*forw_hash)[i].type) {
		ଯଦି (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    ପାଇଁ (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->data +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.start);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		ପାଇଁ (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_debug_add(TCCState *s1, Sym *t, ପୂର୍ଣ୍ଣସଂଖ୍ୟା dwarf)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା offset = dwarf ? dwarf_info_section->data_offset : ++debug_next_type;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *n_hash, g = check_global(t);
    ସଂରଚନା _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (ସଂରଚନା _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * ଆକାର(**hash));
    (*hash)[*n_hash].debug_type = offset;
    (*hash)[(*n_hash)++].type = t;
    ଫେରନ୍ତୁ offset;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା STRUCT_NODEBUG(Sym *s)
{
    ଫେରନ୍ତୁ
    (s->a.nodebug ||
     ((s->v & ~SYM_FIELD) >= SYM_FIRST_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା stabs_struct_find(TCCState *s1, Sym *t, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p_id)
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
    ଯଦି (ଖାଲି == p_id)
        ଫେରନ୍ତୁ s && !s->r && t->c >= 0;
    ଯଦି (ଖାଲି == s) {
        /* just use global_stack always */
        s = sym_push2(&global_ଗଦା, SYM_FIELD|0x00DEBBED, 0, ++debug_next_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    ଯଦି (s->r || t->c < 0) /* already defined or still incomplete */
        ଫେରନ୍ତୁ 0;
    s->r = 1;
    ଫେରନ୍ତୁ 1;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା remove_type_info(ପୂର୍ଣ୍ଣସଂଖ୍ୟା type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        ଯଦି ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        ଯଦି (!(type & VT_BITFIELD) && (type & VT_STRUCT_MASK) > VT_ENUM)
	    type &= ~VT_STRUCT_MASK;
	ଫେରନ୍ତୁ type;
}

ସ୍ଥିର ଶୂନ୍ୟ tcc_get_debug_info(TCCState *s1, Sym *s, CString *result)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା type;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା debug_type = -1;
    Sym *t = s;
    CString str;

    ପାଇଁ (;;) {
        type = remove_type_info (t->type.t);
        ଯଦି (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        ଅନ୍ୟଥା
            ଭାଙ୍ଗ;
    }
    ଯଦି ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        ଯଦି (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, ଖାଲି),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            ଯେତେବେଳେ (t->next) {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା pos, size, align;
                t = t->next;
		ଯଦି (STRUCT_NODEBUG(t))
		    ଜାରି;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, ଖାଲି)
                             );
                tcc_get_debug_info (s1, t, &str);
                ଯଦି (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + BIT_POS(t->type.t);
                    size = BIT_SIZE(t->type.t);
                }
                ଅନ୍ୟଥା {
                    pos = t->c * 8;
                    size = type_size(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, size);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, ଖାଲି, 0, 0);
            cstr_free (&str);
        }
    }
    ଅନ୍ୟଥା ଯଦି (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        ଯଦି (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, ଖାଲି),
                         debug_type);
            ଯେତେବେଳେ (t->next) {
                t = t->next;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, ଖାଲି));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, ଖାଲି, 0, 0);
            cstr_free (&str);
	}
    }
    ଅନ୍ୟଥା ଯଦି ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        ପାଇଁ (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            ଯଦି (default_debug[debug_type - 1].type == type)
                ଭାଙ୍ଗ;
        ଯଦି (debug_type > N_DEFAULT_DEBUG)
            ଫେରନ୍ତୁ;
    }

    ଯଦି (ଖାଲି == result) /* from stabs_struct_complete() */
        ଫେରନ୍ତୁ;

    ଯଦି (n > 0)
        cstr_printf (result, "%d=", ++debug_next_type);
    t = s;
    ପାଇଁ (;;) {
        type = remove_type_info (t->type.t);
        ଯଦି (type == VT_PTR)
            cstr_printf (result, "%d=*", ++debug_next_type);
        ଅନ୍ୟଥା ଯଦି (type == (VT_PTR | VT_ARRAY))
            cstr_printf (result, "%d=ar1;0;%d;",
                         ++debug_next_type, t->type.ref->c - 1);
        ଅନ୍ୟଥା ଯଦି (type == VT_FUNC) {
            cstr_printf (result, "%d=f", ++debug_next_type);
            tcc_get_debug_info (s1, t->type.ref, result);
            ଫେରନ୍ତୁ;
        }
        ଅନ୍ୟଥା
            ଭାଙ୍ଗ;
        t = t->type.ref;
    }
    cstr_printf (result, "%d", debug_type);
}

ସ୍ଥିର ଶୂନ୍ୟ stabs_struct_complete(TCCState *s1, CType *t)
{
    ଯଦି (stabs_struct_find(s1, t->ref, ଖାଲି)) {
        Sym s = {0}; s.type = *t;
        tcc_get_debug_info(s1, &s, ଖାଲି);
    }
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_get_dwarf_info(TCCState *s1, Sym *s)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା type;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା debug_type = -1;
    Sym *e, *t = s;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_pos = -1;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା retval;

    ଯଦି (new_file)
        put_new_file(s1);
    ପାଇଁ (;;) {
        type = remove_type_info (t->type.t);
        ଯଦି (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        ଅନ୍ୟଥା
            ଭାଙ୍ଗ;
    }
    ଯଦି ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	ଯଦି (debug_type == -1) {
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_add(s1, t, 1);
	    e = t;
	    i = 0;
	    ଯେତେବେଳେ (e->next) {
		e = e->next;
		ଯଦି (STRUCT_NODEBUG(e))
		    ଜାରି;
		i++;
	    }
	    pos_type = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା *) tcc_malloc(i * ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->next ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_EMPTY_TYPE
		        : t->next ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, ଖାଲି));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_ଧାଡ଼ି.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ଧାଡ଼ି_ଅଙ୍କ);
	    ଯଦି (t->next) {
	        pos_sib = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            ଯେତେବେଳେ (e->next) {
                e = e->next;
		ଯଦି (STRUCT_NODEBUG(e))
		    ଜାରି;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, ଖାଲି));
		dwarf_uleb128(dwarf_info_section, dwarf_ଧାଡ଼ି.cur_file);
		dwarf_uleb128(dwarf_info_section, file->ଧାଡ଼ି_ଅଙ୍କ);
		pos_type[i++] = dwarf_info_section->data_offset;
		dwarf_data4(dwarf_info_section, 0);
                ଯଦି (e->type.t & VT_BITFIELD) {
                    ପୂର୍ଣ୍ଣସଂଖ୍ୟା pos = e->c * 8 + BIT_POS(e->type.t);
                    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size = BIT_SIZE(e->type.t);

		    dwarf_uleb128(dwarf_info_section, size);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		ଅନ୍ୟଥା
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    ଯଦି (t->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + pos_sib,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    e = t;
	    i = 0;
	    ଯେତେବେଳେ (e->next) {
		e = e->next;
		ଯଦି (STRUCT_NODEBUG(e))
		    ଜାରି;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->data + pos_type[i++],
			  type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
    }
    ଅନ୍ୟଥା ଯଦି (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	ଯଦି (debug_type == -1) {
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_add(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, ଖାଲି));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.start);
	    dwarf_uleb128(dwarf_info_section, dwarf_ଧାଡ଼ି.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ଧାଡ଼ି_ଅଙ୍କ);
	    pos_sib = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            ଯେତେବେଳେ (e->next) {
                e = e->next;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                           ? "" : get_tok_str(e->v, ଖାଲି));
		ଯଦି (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		ଅନ୍ୟଥା
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + pos_sib,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
    }
    ଅନ୍ୟଥା ଯଦି ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        ପାଇଁ (i = 1; i <= N_DEFAULT_DEBUG; i++)
            ଯଦି (default_debug[i - 1].type == type)
                ଭାଙ୍ଗ;
        ଯଦି (i > N_DEFAULT_DEBUG)
            ଫେରନ୍ତୁ 0;
	debug_type = dwarf_info.base_type_used[i - 1];
	ଯଦି (debug_type == 0) {
	    ଅକ୍ଷର name[100];

	    debug_type = dwarf_info_section->data_offset;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_BASE_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].size);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, ଆକାର name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.base_type_used[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = ଖାଲି;
    t = s;
    ପାଇଁ (;;) {
        type = remove_type_info (t->type.t);
        ଯଦି (type == VT_PTR) {
	    i = dwarf_info_section->data_offset;
	    ଯଦି (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_POINTER);
	    dwarf_data1(dwarf_info_section, PTR_SIZE);
	    ଯଦି (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        ଅନ୍ୟଥା ଯଦି (type == (VT_PTR | VT_ARRAY)) {
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sib_pos, sub_type;
#ଯଦି LONG_SIZE == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#ଅନ୍ୟଥା
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#endif

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->data_offset;
	    ଯଦି (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    ଯଦି (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    ପାଇଁ (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.start);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		ଯଦି (type != (VT_PTR | VT_ARRAY))
		    ଭାଙ୍ଗ;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + sib_pos,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
        ଅନ୍ୟଥା ଯଦି (type == VT_FUNC) {
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->data_offset;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    ଯଦି (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->next ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_EMPTY_TYPE);
	    ଯଦି (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    ଯଦି (t->type.ref->next) {
	        sib_pos = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    ଯେତେବେଳେ (f->next) {
		f = f->next;
		i++;
	    }
	    pos_type = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା *) tcc_malloc(i * ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା));
	    f = t->type.ref;
	    i = 0;
	    ଯେତେବେଳେ (f->next) {
		f = f->next;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    ଯଦି (t->type.ref->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + sib_pos,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    f = t->type.ref;
	    i = 0;
	    ଯେତେବେଳେ (f->next) {
		f = f->next;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->data + pos_type[i++],
                          type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
        ଅନ୍ୟଥା {
	    ଯଦି (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  debug_type - dwarf_info.start);
	    }
            ଭାଙ୍ଗ;
	}
        t = t->type.ref;
    }
    ଫେରନ୍ତୁ retval;
}

ସ୍ଥିର ଶୂନ୍ୟ tcc_debug_finish (TCCState *s1, ସଂରଚନା _debug_info *cur)
{
    ଯେତେବେଳେ (cur) {
        ସଂରଚନା _debug_info *next = cur->next;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

        ଯଦି (s1->dwarf) {

            ପାଇଁ (i = cur->n_sym - 1; i >= 0; i--) {
                ସଂରଚନା debug_sym *s = &cur->sym[i];

		dwarf_data1(dwarf_info_section,
                            s->type == N_PSYM
			    ? DWARF_ABBREV_FORMAL_PARAMETER
			    : s->type == N_GSYM
                            ? DWARF_ABBREV_VARIABLE_EXTERNAL
                            : s->type == N_STSYM
			    ? DWARF_ABBREV_VARIABLE_STATIC
			    : DWARF_ABBREV_VARIABLE_LOCAL);
                dwarf_strp(dwarf_info_section, s->str);
		ଯଦି (s->type == N_GSYM || s->type == N_STSYM) {
                    dwarf_uleb128(dwarf_info_section, s->file);
                    dwarf_uleb128(dwarf_info_section, s->ଧାଡ଼ି);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.start);
		ଯଦି (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    ଯଦି (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    ଯଦି (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#ଯଦି PTR_SIZE == 4
                    dwarf_data4(dwarf_info_section, s->ମୂଲ୍ୟ);
#ଅନ୍ୟଥା
                    dwarf_data8(dwarf_info_section, s->ମୂଲ୍ୟ);
#endif
		}
		ଅନ୍ୟଥା {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_size((long)s->ମୂଲ୍ୟ) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (long)s->ମୂଲ୍ୟ);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->child ? DWARF_ABBREV_LEXICAL_BLOCK
			           : DWARF_ABBREV_LEXICAL_EMPTY_BLOCK);
            dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#ଯଦି PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->start);
            dwarf_data4(dwarf_info_section, cur->end - cur->start);
#ଅନ୍ୟଥା
            dwarf_data8(dwarf_info_section, func_ind + cur->start);
            dwarf_data8(dwarf_info_section, cur->end - cur->start);
#endif
            tcc_debug_finish (s1, cur->child);
	    ଯଦି (cur->child)
                dwarf_data1(dwarf_info_section, 0);
        }
        ଅନ୍ୟଥା
        {
            ପାଇଁ (i = 0; i < cur->n_sym; i++) {
                ସଂରଚନା debug_sym *s = &cur->sym[i];

                ଯଦି (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->ମୂଲ୍ୟ,
                                s->sec, s->sym_index);
                ଅନ୍ୟଥା
                    put_stabs(s1, s->str, s->type, 0, 0, s->ମୂଲ୍ୟ);
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

ST_FUNC ଶୂନ୍ୟ tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା param;

    ଯଦି (!(s1->do_debug & 2))
        ଫେରନ୍ତୁ;

    cstr_new (&debug_str);
    param = !e;
    ପାଇଁ (; s != e; s = s->prev) {
        ଯଦି (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            ଜାରି;
	ଯଦି (s1->dwarf) {
	    tcc_debug_stabs(s1, get_tok_str(s->v, ଖାଲି),
			    param ? N_PSYM : N_LSYM, s->c, ଖାଲି, 0,
			    tcc_get_dwarf_info(s1, s));
	}
	ଅନ୍ୟଥା
        {
            cstr_reset (&debug_str);
            cstr_printf (&debug_str, "%s:%s", get_tok_str(s->v, ଖାଲି),
			 param ? "p" : "");
            tcc_get_debug_info(s1, s, &debug_str);
            tcc_debug_stabs(s1, debug_str.data, param ? N_PSYM : N_LSYM,
			    s->c, ଖାଲି, 0, 0);
	}
    }
    cstr_free (&debug_str);
}

/* put function symbol */
ST_FUNC ଶୂନ୍ୟ tcc_debug_funcstart(TCCState *s1, Sym *sym)
{
    CString debug_str;
    BufferedFile *f;

    ଯଦି (!s1->do_debug)
        ଫେରନ୍ତୁ;
    debug_info_ମୂଳ = ଖାଲି;
    debug_info = ଖାଲି;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    ଯଦି (!f)
	ଫେରନ୍ତୁ;

    ଯଦି (s1->dwarf) {
        tcc_debug_ଧାଡ଼ି(s1);
        dwarf_info.func = sym;
        dwarf_info.ଧାଡ଼ି = file->ଧାଡ଼ି_ଅଙ୍କ;
	ଯଦି (s1->do_backtrace) {
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, len;

	    dwarf_ଧାଡ଼ି_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, strlen(funcname) + 2);
	    dwarf_ଧାଡ଼ି_op(s1, DW_LNE_hi_user - 1);
	    len = strlen(funcname) + 1;
	    ପାଇଁ (i = 0; i < len; i++)
		dwarf_ଧାଡ଼ି_op(s1, funcname[i]);
	}
    }
    ଅନ୍ୟଥା
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.data, N_FUN, 0, f->ଧାଡ଼ି_ଅଙ୍କ, 0, cur_text_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_ଧାଡ଼ି(s1);
    }
}

ST_FUNC ଶୂନ୍ୟ tcc_debug_prolog_epilog(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ)
{
    ଯଦି (!s1->do_debug)
        ଫେରନ୍ତୁ;
    ଯଦି (s1->dwarf) {
	dwarf_ଧାଡ଼ି_op(s1, ମୂଲ୍ୟ == 0 ? DW_LNS_set_prologue_end
				     : DW_LNS_set_epilogue_begin);
    }
}

/* put function size */
ST_FUNC ଶୂନ୍ୟ tcc_debug_funcend(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା size)
{
    /* lldb does not like function end and next function start at same pc */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା min_instr_len;

#ଯଦି TCC_EH_FRAME
    tcc_debug_frame_end(s1, size);
#endif
    ଯଦି (!s1->do_debug)
        ଫେରନ୍ତୁ;
    min_instr_len = dwarf_ଧାଡ଼ି.last_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_ଧାଡ଼ି(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, size);
    ଯଦି (s1->dwarf) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_sib = 0;
	Sym *sym = dwarf_info.func;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        ଯଦି ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_ଧାଡ଼ି.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.ଧାଡ଼ି);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->data_offset);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.start);
        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#ଯଦି PTR_SIZE == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, size); // high_pc
#ଅନ୍ୟଥା
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, size); // high_pc
#endif
        func_sib = dwarf_info_section->data_offset;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#ଯଦି defined(TCC_TARGET_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#ନଚେତଯଦି defined(TCC_TARGET_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#ନଚେତଯଦି defined TCC_TARGET_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#ନଚେତଯଦି defined TCC_TARGET_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#ନଚେତଯଦି defined TCC_TARGET_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#ଅନ୍ୟଥା
        dwarf_data1(dwarf_info_section, DW_OP_call_frame_cfa);
#endif
        tcc_debug_finish (s1, debug_info_ମୂଳ);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->data + func_sib,
                  dwarf_info_section->data_offset - dwarf_info.start);
    }
    ଅନ୍ୟଥା
    {
        tcc_debug_finish (s1, debug_info_ମୂଳ);
    }
    debug_info_ମୂଳ = 0;
}


ST_FUNC ଶୂନ୍ୟ tcc_debug_extern_sym(TCCState *s1, Sym *sym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_ଅଙ୍କ, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_bind, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_type)
{
    ଯଦି (!(s1->do_debug & 2))
        ଫେରନ୍ତୁ;

    ଯଦି (sym_type == STT_FUNC || sym->v >= SYM_FIRST_ANOM)
        ଫେରନ୍ତୁ;
    ଯଦି (s1->dwarf) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, ଖାଲି));
	dwarf_uleb128(dwarf_info_section, dwarf_ଧାଡ଼ି.cur_file);
	dwarf_uleb128(dwarf_info_section, file->ଧାଡ଼ି_ଅଙ୍କ);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	ଯଦି (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->data_offset,
		R_DATA_PTR, 0);
#ଯଦି PTR_SIZE == 4
	dwarf_data4(dwarf_info_section, 0);
#ଅନ୍ୟଥା
	dwarf_data8(dwarf_info_section, 0);
#endif
    }
    ଅନ୍ୟଥା
    {
        Section *s = sh_ଅଙ୍କ == SHN_COMMON ? common_section
					  : s1->sections[sh_ଅଙ୍କ];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, ଖାଲି),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        ଯଦି (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.data, N_GSYM, 0, ଖାଲି, 0, 0);
        ଅନ୍ୟଥା
            tcc_debug_stabs(s1, str.data,
                (sym->type.t & VT_STATIC) && data_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC ଶୂନ୍ୟ tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    ଯଦି (!(s1->do_debug & 2))
        ଫେରନ୍ତୁ;

    ଯଦି (s1->dwarf) {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	ଯଦି (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, ଖାଲି));
	    dwarf_uleb128(dwarf_info_section, dwarf_ଧାଡ଼ି.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ଧାଡ଼ି_ଅଙ୍କ);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	}
    }
    ଅନ୍ୟଥା
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, ଖାଲି));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.data, N_LSYM, 0, ଖାଲି, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC ଶୂନ୍ୟ tcc_tcov_block_end(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି);

ST_FUNC ଶୂନ୍ୟ tcc_tcov_block_begin(TCCState *s1)
{
    SValue sv;
    ଶୂନ୍ୟ *ptr;
    unsigned long last_offset = tcov_data.offset;

    tcc_tcov_block_end (tcc_state, 0);
    ଯଦି (s1->test_coverage == 0 || nocode_wanted)
	ଫେରନ୍ତୁ;

    ଯଦି (tcov_data.last_file_name == 0 ||
	strcmp ((ଅଚଳ ଅକ୍ଷର *)(tcov_section->data + tcov_data.last_file_name),
		file->true_filename) != 0) {
	ଅକ୍ଷର wd[1024];
	CString cstr;

	ଯଦି (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	ଯଦି (tcov_data.last_file_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = 0;
	cstr_new (&cstr);
	ଯଦି (file->true_filename[0] == '/') {
	    tcov_data.last_file_name = tcov_section->data_offset;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	ଅନ୍ୟଥା {
	    getcwd (wd, ଆକାର(wd));
	    tcov_data.last_file_name = tcov_section->data_offset + strlen(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_add(tcov_section, cstr.size + 1);
	strcpy((ଅକ୍ଷର *)ptr, cstr.data);
#ifdef _WIN32
        normalize_slashes((ଅକ୍ଷର *)ptr);
#endif
	cstr_free (&cstr);
    }
    ଯଦି (tcov_data.last_func_name == 0 ||
	strcmp ((ଅଚଳ ଅକ୍ଷର *)(tcov_section->data + tcov_data.last_func_name),
		funcname) != 0) {
	size_t len;

	ଯଦି (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = tcov_section->data_offset;
	len = strlen (funcname);
	ptr = section_ptr_add(tcov_section, len + 1);
	strcpy((ଅକ୍ଷର *)ptr, funcname);
	section_ptr_add(tcov_section, -tcov_section->data_offset & 7);
	ptr = section_ptr_add(tcov_section, 8);
	write64le (ptr, file->ଧାଡ଼ି_ଅଙ୍କ);
    }
    ଯଦି (ind == tcov_data.ind && tcov_data.ଧାଡ଼ି == file->ଧାଡ଼ି_ଅଙ୍କ)
        tcov_data.offset = last_offset;
    ଅନ୍ୟଥା {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_add(tcov_section, 16);
        tcov_data.ଧାଡ଼ି = file->ଧାଡ଼ି_ଅଙ୍କ;
        write64le (ptr, (tcov_data.ଧାଡ଼ି << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((unsigned ଅକ୍ଷର *)ptr - tcov_section->data) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#ଯଦି defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || \
    defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || \
    defined TCC_TARGET_RISCV64
        gen_increment_tcov (&sv);
#ଅନ୍ୟଥା
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#endif
        tcov_data.offset = (unsigned ଅକ୍ଷର *)ptr - tcov_section->data;
        tcov_data.ind = ind;
    }
}

ST_FUNC ଶୂନ୍ୟ tcc_tcov_block_end(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି)
{
    ଯଦି (s1->test_coverage == 0)
	ଫେରନ୍ତୁ;
    ଯଦି (ଧାଡ଼ି == -1)
        ଧାଡ଼ି = tcov_data.ଧାଡ଼ି;
    ଯଦି (tcov_data.offset) {
	ଶୂନ୍ୟ *ptr = tcov_section->data + tcov_data.offset;
	unsigned long long nline = ଧାଡ଼ି ? ଧାଡ଼ି : file->ଧାଡ଼ି_ଅଙ୍କ;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_data.offset = 0;
    }
}

ST_FUNC ଶୂନ୍ୟ tcc_tcov_check_ଧାଡ଼ି(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା start)
{
    ଯଦି (s1->test_coverage == 0)
	ଫେରନ୍ତୁ;
    ଯଦି (tcov_data.ଧାଡ଼ି != file->ଧାଡ଼ି_ଅଙ୍କ) {
        ଯଦି ((tcov_data.ଧାଡ଼ି + 1) != file->ଧାଡ଼ି_ଅଙ୍କ) {
	    tcc_tcov_block_end (s1, -1);
	    ଯଦି (start)
                tcc_tcov_block_begin (s1);
	}
	ଅନ୍ୟଥା
	    tcov_data.ଧାଡ଼ି = file->ଧାଡ଼ି_ଅଙ୍କ;
    }
}

ST_FUNC ଶୂନ୍ୟ tcc_tcov_start(TCCState *s1)
{
    ଯଦି (s1->test_coverage == 0)
	ଫେରନ୍ତୁ;
    ଯଦି (!s1->dState)
        s1->dState = tcc_mallocz(ଆକାର *s1->dState);
    memset (&tcov_data, 0, ଆକାର (tcov_data));
    ଯଦି (tcov_section == ଖାଲି) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_add(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC ଶୂନ୍ୟ tcc_tcov_end(TCCState *s1)
{
    ଯଦି (s1->test_coverage == 0)
	ଫେରନ୍ତୁ;
    ଯଦି (tcov_data.last_func_name)
        section_ptr_add(tcov_section, 1);
    ଯଦି (tcov_data.last_file_name)
        section_ptr_add(tcov_section, 1);
}

ST_FUNC ଶୂନ୍ୟ tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_data.ind = 0;
}

/* ------------------------------------------------------------------------- */
#undef last_ଧାଡ଼ି_ଅଙ୍କ
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
#undef debug_info_ମୂଳ
#undef dwarf_sym
#undef dwarf_ଧାଡ଼ି
#undef dwarf_info
#undef dwarf_str
#undef dwarf_ଧାଡ଼ି_str
#undef tcov_data
