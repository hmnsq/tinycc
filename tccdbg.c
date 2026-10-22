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

ಸ್ಥಿರ ಧ್ರುವ ಸಂರಚನಾ {
  ಪೂರ್ಣಾಙ್ಕ type;
  ಪೂರ್ಣಾಙ್ಕ size;
  ಪೂರ್ಣಾಙ್ಕ encoding;
  ಧ್ರುವ ವರ್ಣ *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#ಯದಿ LONG_SIZE == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#ಅನ್ಯಥಾ
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#endif
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#ಯದಿ LONG_SIZE == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#ಅನ್ಯಥಾ
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
#ಅನ್ಯಥಾ
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
#ಯದಿ LONG_SIZE == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#ಅನ್ಯಥಾ
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#endif
};

#define	N_DEFAULT_DEBUG	(ಪರಿಮಾಣ (default_debug) / ಪರಿಮಾಣ (default_debug[0]))

/* dwarf debug */

#define	DWARF_ಸಾಲು_BASE				-5
#define	DWARF_ಸಾಲು_RANGE			14
#define	DWARF_OPCODE_BASE			13

#ಯದಿ defined TCC_TARGET_ARM64
#define	DWARF_MIN_INSTR_LEN			4
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM
#define	DWARF_MIN_INSTR_LEN			2
#ಅನ್ಯಥಾ
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
ಸ್ಥಿರ ಧ್ರುವ unsigned ವರ್ಣ dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_TAG_compile_unit, 1,
          DW_AT_producer, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_ಸಾಲು_strp,
          DW_AT_comp_dir, DW_FORM_ಸಾಲು_strp,
          DW_AT_ಕೆಳಗಿನ_pc, DW_FORM_addr,
#ಯದಿ PTR_SIZE == 4
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data4,
#ಅನ್ಯಥಾ
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data8,
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
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_TAG_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
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
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_TAG_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_ಮೌಲ್ಯ, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_TAG_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_ಮೌಲ್ಯ, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_TAG_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_size, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_data_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_bit_size, DW_FORM_udata,
          DW_AT_data_bit_offset, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_TAG_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_EMPTY_TYPE, DW_TAG_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_TAG_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_EMPTY_TYPE, DW_TAG_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_TAG_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ಕೆಳಗಿನ_pc, DW_FORM_addr,
#ಯದಿ PTR_SIZE == 4
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data4,
#ಅನ್ಯಥಾ
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_TAG_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ಸಾಲು, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_ಕೆಳಗಿನ_pc, DW_FORM_addr,
#ಯದಿ PTR_SIZE == 4
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data4,
#ಅನ್ಯಥಾ
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_BLOCK, DW_TAG_lexical_block, 1,
          DW_AT_ಕೆಳಗಿನ_pc, DW_FORM_addr,
#ಯದಿ PTR_SIZE == 4
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data4,
#ಅನ್ಯಥಾ
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data8,
#endif
          0, 0,
    DWARF_ABBREV_LEXICAL_EMPTY_BLOCK, DW_TAG_lexical_block, 0,
          DW_AT_ಕೆಳಗಿನ_pc, DW_FORM_addr,
#ಯದಿ PTR_SIZE == 4
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data4,
#ಅನ್ಯಥಾ
          DW_AT_ಮೇಲಿನ_pc, DW_FORM_data8,
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

ಸ್ಥಿರ ಧ್ರುವ unsigned ವರ್ಣ dwarf_ಸಾಲು_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#define N_STR_HASH (251)

ಸಂರಚನಾ dwarf_str_hash {
    ಪೂರ್ಣಾಙ್ಕ len;
    unsigned long data_offset;
    ಸಂರಚನಾ dwarf_str_hash *next;
};

ಸಂರಚನಾ _tccdbg {

    ಪೂರ್ಣಾಙ್ಕ last_ಸಾಲು_ಅಂಕೆ, new_file;
    ಪೂರ್ಣಾಙ್ಕ section_sym;

    ಪೂರ್ಣಾಙ್ಕ debug_next_type;

    ಸಂರಚನಾ _debug_hash {
        ಪೂರ್ಣಾಙ್ಕ debug_type;
        Sym *type;
    } *debug_hash_global, *debug_hash_local;

    /* store forward structure/unions types */
    ಸಂರಚನಾ _debug_forw_hash {
        Sym *type;
        ಪೂರ್ಣಾಙ್ಕ n_debug_type;
        ಪೂರ್ಣಾಙ್ಕ *debug_type;
    } *debug_forw_hash_global, *debug_forw_hash_local;

    ಪೂರ್ಣಾಙ್ಕ n_debug_hash_global;
    ಪೂರ್ಣಾಙ್ಕ n_debug_hash_local;
    ಪೂರ್ಣಾಙ್ಕ n_debug_forw_hash_global;
    ಪೂರ್ಣಾಙ್ಕ n_debug_forw_hash_local;

    ಸಂರಚನಾ _debug_info {
        ಪೂರ್ಣಾಙ್ಕ start;
        ಪೂರ್ಣಾಙ್ಕ end;
        ಪೂರ್ಣಾಙ್ಕ last_debug_hash;
        ಪೂರ್ಣಾಙ್ಕ last_debug_forw_hash;
        ಪೂರ್ಣಾಙ್ಕ n_sym;
        ಸಂರಚನಾ debug_sym {
            ಪೂರ್ಣಾಙ್ಕ type;
            unsigned long ಮೌಲ್ಯ;
            ವರ್ಣ *str;
            Section *sec;
            ಪೂರ್ಣಾಙ್ಕ sym_index;
            ಪೂರ್ಣಾಙ್ಕ info;
            ಪೂರ್ಣಾಙ್ಕ file;
            ಪೂರ್ಣಾಙ್ಕ ಸಾಲು;
        } *sym;
        ಸಂರಚನಾ _debug_info *child, *next, *last, *parent;
    } *debug_info, *debug_info_ಬೇರು;

    ಸಂರಚನಾ {
        ಪೂರ್ಣಾಙ್ಕ info;
        ಪೂರ್ಣಾಙ್ಕ abbrev;
        ಪೂರ್ಣಾಙ್ಕ ಸಾಲು;
        ಪೂರ್ಣಾಙ್ಕ str;
        ಪೂರ್ಣಾಙ್ಕ ಸಾಲು_str;
    } dwarf_sym;

    ಸಂರಚನಾ {
        ಪೂರ್ಣಾಙ್ಕ start;
        ಪೂರ್ಣಾಙ್ಕ dir_size;
        ವರ್ಣ **dir_table;
        ಪೂರ್ಣಾಙ್ಕ filename_size;
        ಸಂರಚನಾ dwarf_filename_struct {
            ಪೂರ್ಣಾಙ್ಕ dir_entry;
            ವರ್ಣ *name;
        } *filename_table;
        ಪೂರ್ಣಾಙ್ಕ ಸಾಲು_size;
        ಪೂರ್ಣಾಙ್ಕ ಸಾಲು_max_size;
        unsigned ವರ್ಣ *ಸಾಲು_data;
        ಪೂರ್ಣಾಙ್ಕ cur_file;
        ಪೂರ್ಣಾಙ್ಕ last_file;
        ಪೂರ್ಣಾಙ್ಕ last_pc;
        ಪೂರ್ಣಾಙ್ಕ last_ಸಾಲು;
    } dwarf_ಸಾಲು;

    ಸಂರಚನಾ {
        ಪೂರ್ಣಾಙ್ಕ start;
        Sym *func;
        ಪೂರ್ಣಾಙ್ಕ ಸಾಲು;
        ಪೂರ್ಣಾಙ್ಕ base_type_used[N_DEFAULT_DEBUG];
    } dwarf_info;

    ಸಂರಚನಾ dwarf_str_hash *dwarf_str[N_STR_HASH];
    ಸಂರಚನಾ dwarf_str_hash *dwarf_ಸಾಲು_str[N_STR_HASH];

    /* test coverage */
    ಸಂರಚನಾ {
        unsigned long offset;
        unsigned long last_file_name;
        unsigned long last_func_name;
        ಪೂರ್ಣಾಙ್ಕ ind;
        ಪೂರ್ಣಾಙ್ಕ ಸಾಲು;
    } tcov_data;
};

#define last_ಸಾಲು_ಅಂಕೆ             s1->dState->last_ಸಾಲು_ಅಂಕೆ
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
#define debug_info_ಬೇರು           s1->dState->debug_info_ಬೇರು
#define dwarf_sym                 s1->dState->dwarf_sym
#define dwarf_ಸಾಲು                s1->dState->dwarf_ಸಾಲು
#define dwarf_info                s1->dState->dwarf_info
#define dwarf_str                 s1->dState->dwarf_str
#define dwarf_ಸಾಲು_str            s1->dState->dwarf_ಸಾಲು_str
#define tcov_data                 s1->dState->tcov_data

#define	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ put_stabs(TCCState *s1, ಧ್ರುವ ವರ್ಣ *str, ಪೂರ್ಣಾಙ್ಕ type, ಪೂರ್ಣಾಙ್ಕ other,
    ಪೂರ್ಣಾಙ್ಕ desc, unsigned long ಮೌಲ್ಯ);

ST_FUNC ಶೂನ್ಯ tcc_debug_new(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ shf = 0;
    ಯದಿ (!s1->dState)
        s1->dState = tcc_mallocz(ಪರಿಮಾಣ *s1->dState);

#ifdef CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    ಯದಿ (s1->do_debug && s1->output_type == TCC_OUTPUT_MEMORY)
        s1->do_backtrace = 1;
    ಯದಿ (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#endif

    ಯದಿ (s1->dwarf) {
	ಪೂರ್ಣಾಙ್ಕ i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ debug[] = {
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
	ಪ್ರತಿ (i = 0; i < ಪರಿಮಾಣ(debug)/ಪರಿಮಾಣ(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_MERGE | SHF_STRINGS;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_ಸಾಲು_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	ಯದಿ (s1->dwarf >= 5) {
            dwarf_ಸಾಲು_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_ಸಾಲು_str_section->sh_entsize = 1;
	    dwarf_ಸಾಲು_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    ಅನ್ಯಥಾ
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = ಪರಿಮಾಣ(Stab_Sym);
        stab_section->sh_addralign = ಪರಿಮಾಣ ((Stab_Sym*)0)->n_ಮೌಲ್ಯ;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ put_stabs(TCCState *s1, ಧ್ರುವ ವರ್ಣ *str, ಪೂರ್ಣಾಙ್ಕ type, ಪೂರ್ಣಾಙ್ಕ other, ಪೂರ್ಣಾಙ್ಕ desc,
                      unsigned long ಮೌಲ್ಯ)
{
    Stab_Sym *sym;

    unsigned offset;
    ಯದಿ (type == N_SLINE
        && (offset = stab_section->data_offset)
        && (sym = (Stab_Sym*)(stab_section->data + offset) - 1)
        && sym->n_type == type
        && sym->n_ಮೌಲ್ಯ == ಮೌಲ್ಯ) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        ಪ್ರತ್ಯಾಗಮ 0;
    }

    sym = section_ptr_add(stab_section, ಪರಿಮಾಣ(Stab_Sym));
    ಯದಿ (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } ಅನ್ಯಥಾ {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_ಮೌಲ್ಯ = ಮೌಲ್ಯ;
    ಪ್ರತ್ಯಾಗಮ 1;
}

ಸ್ಥಿರ ಶೂನ್ಯ put_stabs_r(TCCState *s1, ಧ್ರುವ ವರ್ಣ *str, ಪೂರ್ಣಾಙ್ಕ type, ಪೂರ್ಣಾಙ್ಕ other, ಪೂರ್ಣಾಙ್ಕ desc,
                        unsigned long ಮೌಲ್ಯ, Section *sec, ಪೂರ್ಣಾಙ್ಕ sym_index)
{
    ಯದಿ (put_stabs(s1, str, type, other, desc, ಮೌಲ್ಯ))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->data_offset - 4,
                      ಪರಿಮಾಣ ((Stab_Sym*)0)->n_ಮೌಲ್ಯ == PTR_SIZE ? R_DATA_PTR : R_DATA_32,
                      sym_index);
}

ಸ್ಥಿರ ಶೂನ್ಯ put_stabn(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ type, ಪೂರ್ಣಾಙ್ಕ other, ಪೂರ್ಣಾಙ್ಕ desc, ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ)
{
    put_stabs(s1, ರಿಕ್ತ, type, other, desc, ಮೌಲ್ಯ);
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

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    ಪ್ರತ್ಯಾಗಮ put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_ಅಂಕೆ, ರಿಕ್ತ);
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_reloc(Section *s, ಪೂರ್ಣಾಙ್ಕ sym, ಪೂರ್ಣಾಙ್ಕ rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->data_offset, rel, sym, 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ free_str(ಸಂರಚನಾ dwarf_str_hash **str)
{
    ಪೂರ್ಣಾಙ್ಕ i;

    ಪ್ರತಿ (i = 0; i < N_STR_HASH; i++) {
       ಯಾವತ್ (str[i]) {
           ಸಂರಚನಾ dwarf_str_hash *next = str[i]->next;

           tcc_free(str[i]);
           str[i] = next;
       }
    }
}

ಸ್ಥಿರ unsigned str_hash(ಧ್ರುವ ವರ್ಣ *s)
{
    unsigned h = 5381;

    ಯಾವತ್ (*s)
       h += (*s++ & 0xffu) + h * 31;
    ಪ್ರತ್ಯಾಗಮ h;
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_string(Section *s, Section *dw, ಪೂರ್ಣಾಙ್ಕ sym, ಧ್ರುವ ವರ್ಣ *str)
{
    TCCState *s1 = s->s1;
    ಪೂರ್ಣಾಙ್ಕ len, hash = str_hash(str) % N_STR_HASH;
    ವರ್ಣ *ptr;
    ಸಂರಚನಾ dwarf_str_hash *new_hash;
    ಸಂರಚನಾ dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_ಸಾಲು_str;

    len = strlen(str) + 1;
    new_hash = dw_hash[hash];
    ಯಾವತ್ (new_hash) {
	ಯದಿ (new_hash->len == len &&
	    !memcmp(str, dw->data + new_hash->data_offset, len))
	    ಭಙ್ಗ;
	new_hash = new_hash->next;
    }
    ಯದಿ (new_hash == ರಿಕ್ತ) {
	unsigned long offset = dw->data_offset;

        new_hash = dw_hash[hash];
        ಯಾವತ್ (new_hash) {
	    unsigned long n = new_hash->data_offset + new_hash->len - len;

	    ಯದಿ (new_hash->len > len &&
	        !memcmp(str, dw->data + n, len)) {
		offset = n;
		ಭಙ್ಗ;
	    }
	    new_hash = new_hash->next;
        }
	ಯದಿ (new_hash == ರಿಕ್ತ) {
	    ptr = section_ptr_add(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (ಸಂರಚನಾ dwarf_str_hash *)
	    tcc_malloc(ಪರಿಮಾಣ(ಸಂರಚನಾ dwarf_str_hash));
	new_hash->len = len;
	new_hash->data_offset = offset;
	new_hash->next = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->data_offset, R_DATA_32DW, sym,
                   PTR_SIZE == 4 ? 0 : new_hash->data_offset);
    dwarf_data4(s, PTR_SIZE == 4 ? new_hash->data_offset : 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_strp(Section *s, ಧ್ರುವ ವರ್ಣ *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_ಸಾಲು_strp(Section *s, ಧ್ರುವ ವರ್ಣ *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_ಸಾಲು_str_section, dwarf_sym.ಸಾಲು_str, str);
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_ಸಾಲು_op(TCCState *s1, unsigned ವರ್ಣ op)
{
    ಯದಿ (dwarf_ಸಾಲು.ಸಾಲು_size >= dwarf_ಸಾಲು.ಸಾಲು_max_size) {
	dwarf_ಸಾಲು.ಸಾಲು_max_size += 1024;
	dwarf_ಸಾಲು.ಸಾಲು_data =
	    (unsigned ವರ್ಣ *)tcc_realloc(dwarf_ಸಾಲು.ಸಾಲು_data,
					 dwarf_ಸಾಲು.ಸಾಲು_max_size);
    }
    dwarf_ಸಾಲು.ಸಾಲು_data[dwarf_ಸಾಲು.ಸಾಲು_size++] = op;
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_file(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ i, j;
    ವರ್ಣ *filename;
    ಪೂರ್ಣಾಙ್ಕ index_offset = s1->dwarf < 5;

    ಯದಿ (!strcmp(file->filename, "<command line>")) {
        dwarf_ಸಾಲು.cur_file = 1;
	ಪ್ರತ್ಯಾಗಮ;
    }
    filename = strrchr(file->filename, '/');
    ಯದಿ (filename == ರಿಕ್ತ) {
        ಪ್ರತಿ (i = 1; i < dwarf_ಸಾಲು.filename_size; i++)
            ಯದಿ (dwarf_ಸಾಲು.filename_table[i].dir_entry == 0 &&
		strcmp(dwarf_ಸಾಲು.filename_table[i].name,
		       file->filename) == 0) {
		    dwarf_ಸಾಲು.cur_file = i + index_offset;
	            ಪ್ರತ್ಯಾಗಮ;
		}
	i = -index_offset;
	filename = file->filename;
    }
    ಅನ್ಯಥಾ {
	ವರ್ಣ *undo = filename;
	ವರ್ಣ *dir = file->filename;

	*filename++ = '\0';
        ಪ್ರತಿ (i = 0; i < dwarf_ಸಾಲು.dir_size; i++)
	    ಯದಿ (strcmp(dwarf_ಸಾಲು.dir_table[i], dir) == 0) {
		ಪ್ರತಿ (j = 1; j < dwarf_ಸಾಲು.filename_size; j++)
		    ಯದಿ (dwarf_ಸಾಲು.filename_table[j].dir_entry - index_offset
			== i &&
			strcmp(dwarf_ಸಾಲು.filename_table[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_ಸಾಲು.cur_file = j + index_offset;
			ಪ್ರತ್ಯಾಗಮ;
		    }
		ಭಙ್ಗ;
	    }
	ಯದಿ (i == dwarf_ಸಾಲು.dir_size) {
	    dwarf_ಸಾಲು.dir_size++;
	    dwarf_ಸಾಲು.dir_table =
                (ವರ್ಣ **) tcc_realloc(dwarf_ಸಾಲು.dir_table,
                                      dwarf_ಸಾಲು.dir_size *
                                      ಪರಿಮಾಣ (ವರ್ಣ *));
            dwarf_ಸಾಲು.dir_table[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_ಸಾಲು.filename_table =
        (ಸಂರಚನಾ dwarf_filename_struct *)
        tcc_realloc(dwarf_ಸಾಲು.filename_table,
                    (dwarf_ಸಾಲು.filename_size + 1) *
                    ಪರಿಮಾಣ (ಸಂರಚನಾ dwarf_filename_struct));
    dwarf_ಸಾಲು.filename_table[dwarf_ಸಾಲು.filename_size].dir_entry =
	i + index_offset;
    dwarf_ಸಾಲು.filename_table[dwarf_ಸಾಲು.filename_size].name =
        tcc_strdup(filename);
    dwarf_ಸಾಲು.cur_file = dwarf_ಸಾಲು.filename_size++ + index_offset;
    ಪ್ರತ್ಯಾಗಮ;
}

#ಯದಿ 0
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ dwarf_uleb128_size (unsigned long long ಮೌಲ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ size =  0;

    ಕುರು {
        ಮೌಲ್ಯ >>= 7;
        size++;
    } ಯಾವತ್ (ಮೌಲ್ಯ != 0);
    ಪ್ರತ್ಯಾಗಮ size;
}
#endif

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ dwarf_sleb128_size (long long ಮೌಲ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ size =  0;
    long long end = ಮೌಲ್ಯ >> 63;
    unsigned ವರ್ಣ last = end & 0x40;
    unsigned ವರ್ಣ byte;

    ಕುರು {
        byte = ಮೌಲ್ಯ & 0x7f;
        ಮೌಲ್ಯ >>= 7;
        size++;
    } ಯಾವತ್ (ಮೌಲ್ಯ != end || (byte & 0x40) != last);
    ಪ್ರತ್ಯಾಗಮ size;
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_uleb128 (Section *s, unsigned long long ಮೌಲ್ಯ)
{
    ಕುರು {
        unsigned ವರ್ಣ byte = ಮೌಲ್ಯ & 0x7f;

        ಮೌಲ್ಯ >>= 7;
        dwarf_data1(s, byte | (ಮೌಲ್ಯ ? 0x80 : 0));
    } ಯಾವತ್ (ಮೌಲ್ಯ != 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_sleb128 (Section *s, long long ಮೌಲ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ more;
    long long end = ಮೌಲ್ಯ >> 63;
    unsigned ವರ್ಣ last = end & 0x40;

    ಕುರು {
        unsigned ವರ್ಣ byte = ಮೌಲ್ಯ & 0x7f;

        ಮೌಲ್ಯ >>= 7;
	more = ಮೌಲ್ಯ != end || (byte & 0x40) != last;
        dwarf_data1(s, byte | (0x80 * more));
    } ಯಾವತ್ (more);
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_uleb128_op (TCCState *s1, unsigned long long ಮೌಲ್ಯ)
{
    ಕುರು {
        unsigned ವರ್ಣ byte = ಮೌಲ್ಯ & 0x7f;

        ಮೌಲ್ಯ >>= 7;
        dwarf_ಸಾಲು_op(s1, byte | (ಮೌಲ್ಯ ? 0x80 : 0));
    } ಯಾವತ್ (ಮೌಲ್ಯ != 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ dwarf_sleb128_op (TCCState *s1, long long ಮೌಲ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ more;
    long long end = ಮೌಲ್ಯ >> 63;
    unsigned ವರ್ಣ last = end & 0x40;

    ಕುರು {
        unsigned ವರ್ಣ byte = ಮೌಲ್ಯ & 0x7f;

        ಮೌಲ್ಯ >>= 7;
        more = ಮೌಲ್ಯ != end || (byte & 0x40) != last;
        dwarf_ಸಾಲು_op(s1, byte | (0x80 * more));
    } ಯಾವತ್ (more);
}

#ಯದಿ TCC_EH_FRAME
ST_FUNC ಶೂನ್ಯ tcc_eh_frame_start(TCCState *s1)
{
    ಯದಿ (!s1->unwind_tables)
        ಪ್ರತ್ಯಾಗಮ;
    eh_frame_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section, 0); // CIE ID
    dwarf_data1(eh_frame_section, 1); // Version
    dwarf_data1(eh_frame_section, 'z'); // Augmentation String
    dwarf_data1(eh_frame_section, 'R');
    dwarf_data1(eh_frame_section, 0);
#ಯದಿ defined TCC_TARGET_I386
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
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_X86_64
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
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM
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
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM64
    dwarf_uleb128(eh_frame_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 30); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 31); // x31 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_RISCV64
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
    ಯಾವತ್ ((eh_frame_section->data_offset - s1->eh_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + s1->eh_start, // length
	      eh_frame_section->data_offset - s1->eh_start - 4);
}

ಸ್ಥಿರ ಶೂನ್ಯ tcc_debug_frame_end(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ size)
{
    ಪೂರ್ಣಾಙ್ಕ eh_section_sym;
    unsigned long fde_start;

    ಯದಿ (!eh_frame_section)
	ಪ್ರತ್ಯಾಗಮ;
    eh_section_sym = dwarf_get_section_sym(text_section);
    fde_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section,
		fde_start - s1->eh_start + 4); // CIE Pointer
#ಯದಿ defined TCC_TARGET_I386
    dwarf_reloc(eh_frame_section, eh_section_sym, R_386_PC32);
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_X86_64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_X86_64_PC32);
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM
    dwarf_reloc(eh_frame_section, eh_section_sym, R_ARM_REL32);
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_AARCH64_PREL32);
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_RISCV64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_RISCV_32_PCREL);
#endif
    dwarf_data4(eh_frame_section, func_ind); // PC Begin
    dwarf_data4(eh_frame_section, size); // PC Range
    dwarf_data1(eh_frame_section, 0); // Augmentation Length
#ಯದಿ defined TCC_TARGET_I386
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
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_X86_64
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
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM
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
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM64
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
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_RISCV64
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
    ಯಾವತ್ (size >= 4 &&
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
    ಯಾವತ್ ((eh_frame_section->data_offset - fde_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + fde_start, // length
	      eh_frame_section->data_offset - fde_start - 4);
}

ST_FUNC ಶೂನ್ಯ tcc_eh_frame_end(TCCState *s1)
{
    ಯದಿ (!eh_frame_section)
	ಪ್ರತ್ಯಾಗಮ;
    dwarf_data4(eh_frame_section, 0);
}

ಸಂರಚನಾ eh_ಹುಡುಕು_table {
    uint32_t pc_offset;
    uint32_t fde_offset;
};

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ sort_eh_table(ಧ್ರುವ ಶೂನ್ಯ *a, ಧ್ರುವ ಶೂನ್ಯ *b)
{
    uint32_t pc1 = ((ಧ್ರುವ ಸಂರಚನಾ eh_ಹುಡುಕು_table *)a)->pc_offset;
    uint32_t pc2 = ((ಧ್ರುವ ಸಂರಚನಾ eh_ಹುಡುಕು_table *)b)->pc_offset;

    ಪ್ರತ್ಯಾಗಮ pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC ಶೂನ್ಯ tcc_eh_frame_hdr(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ final)
{
    ಪೂರ್ಣಾಙ್ಕ ಎಣಿಕೆ_2 = 0, offset;
    unsigned long ಎಣಿಕೆ_offset, tab_offset;
    unsigned ವರ್ಣ *ln, *end;
    unsigned ಪೂರ್ಣಾಙ್ಕ last_cie_offset = 0xffffffff;

    ಯದಿ (!eh_frame_section || !eh_frame_section->data_offset)
	ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (final && !eh_frame_hdr_section)
	ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (final == 0)
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
    //ಎಣಿಕೆ
    ಎಣಿಕೆ_offset = eh_frame_hdr_section->data_offset;
    dwarf_data4(eh_frame_hdr_section, 0);
    tab_offset = eh_frame_hdr_section->data_offset;
    ln = eh_frame_section->data;
    end = eh_frame_section->data + eh_frame_section->data_offset;
    ಯಾವತ್ (ln < end) {
	unsigned ವರ್ಣ *fde = ln, *rd = ln;
	unsigned ಪೂರ್ಣಾಙ್ಕ cie_offset, version, length = dwarf_read_4(rd, end);
	unsigned ಪೂರ್ಣಾಙ್ಕ pc_offset, fde_offset;

	ಯದಿ (length == 0)
	    ಗಚ್ಛ next;
        cie_offset = dwarf_read_4(rd, end);
	ಯದಿ (cie_offset == 0)
	    ಗಚ್ಛ next;
	ಯದಿ (cie_offset != last_cie_offset) {
	    unsigned ವರ್ಣ *cie = rd - cie_offset + 4;

	    ಯದಿ (cie < eh_frame_section->data)
		ಗಚ್ಛ next;
	    version = dwarf_read_1(cie, end);
	    ಯದಿ ((version == 1 || version == 3) &&
	        dwarf_read_1(cie, end) == 'z' && // Augmentation String
		dwarf_read_1(cie, end) == 'R' &&
		dwarf_read_1(cie, end) == 0) {
	        dwarf_read_uleb128(&cie, end); // code_alignment_factor
	        dwarf_read_sleb128(&cie, end); // data_alignment_factor
		dwarf_read_1(cie, end); // return address column
		ಯದಿ (dwarf_read_uleb128(&cie, end) == 1 &&
		    dwarf_read_1(cie, end) == FDE_ENCODING) {
		    last_cie_offset = cie_offset;
		}
		ಅನ್ಯಥಾ
		    ಗಚ್ಛ next;
	    }
	    ಅನ್ಯಥಾ
		ಗಚ್ಛ next;
	}
	ಎಣಿಕೆ_2++;
	fde_offset = eh_frame_section->sh_addr +
		     (fde - eh_frame_section->data) -
		     eh_frame_hdr_section->sh_addr;
	pc_offset = dwarf_read_4(rd, end) + fde_offset + 8;
	dwarf_data4(eh_frame_hdr_section, pc_offset);
	dwarf_data4(eh_frame_hdr_section, fde_offset);
next:
	ln += length + 4;
    }
    add32le(eh_frame_hdr_section->data + ಎಣಿಕೆ_offset, ಎಣಿಕೆ_2);
    qsort(eh_frame_hdr_section->data + tab_offset, ಎಣಿಕೆ_2,
	  ಪರಿಮಾಣ(ಸಂರಚನಾ eh_ಹುಡುಕು_table), sort_eh_table);
}
#endif

/* start of translation unit info */
ST_FUNC ಶೂನ್ಯ tcc_debug_start(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ವರ್ಣ buf[512];
    ವರ್ಣ *filename;

    /* we might currently #include the <command-line> */
    filename = file->prev ? file->prev->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    ಯದಿ (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, text_section->data_offset, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            text_section->sh_ಅಂಕೆ, "$a");

        new_file = last_ಸಾಲು_ಅಂಕೆ = 0;
        debug_next_type = N_DEFAULT_DEBUG;
        debug_hash_global = ರಿಕ್ತ;
        debug_hash_local = ರಿಕ್ತ;
        debug_forw_hash_global = ರಿಕ್ತ;
        debug_forw_hash_local = ರಿಕ್ತ;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, ಪರಿಮಾಣ(buf));
#ifdef _WIN32
        normalize_slashes(buf);
#endif

        ಯದಿ (s1->dwarf) {
            ಪೂರ್ಣಾಙ್ಕ start_abbrev;
            unsigned ವರ್ಣ *ptr;
	    ವರ್ಣ *undo;

            /* dwarf_abbrev */
            start_abbrev = dwarf_abbrev_section->data_offset;
            ptr = section_ptr_add(dwarf_abbrev_section, ಪರಿಮಾಣ(dwarf_abbrev_init));
            memcpy(ptr, dwarf_abbrev_init, ಪರಿಮಾಣ(dwarf_abbrev_init));

            ಯದಿ (s1->dwarf < 5) {
    	        ಯಾವತ್ (*ptr) {
    	            ptr += 3;
    	            ಯಾವತ್ (*ptr) {
    	                ಯದಿ (ptr[1] == DW_FORM_ಸಾಲು_strp)
    		            ptr[1] = DW_FORM_strp;
		        ಯದಿ (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    ಯದಿ  (ptr[1] == DW_FORM_sec_offset)
			         ptr[1] = DW_FORM_data4;
			    /* This code uses only size < 0x80 so these are
			       compatible. */
			    ಯದಿ  (ptr[1] == DW_FORM_exprloc)
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
            ಯದಿ (tcc_state->dwarf >= 5)
    	        dwarf_sym.ಸಾಲು_str = dwarf_get_section_sym(dwarf_ಸಾಲು_str_section);
            ಅನ್ಯಥಾ {
    	        dwarf_ಸಾಲು_str_section = dwarf_str_section;
                dwarf_sym.ಸಾಲು_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(text_section);

            /* dwarf_info */
            dwarf_info.start = dwarf_info_section->data_offset;
            dwarf_data4(dwarf_info_section, 0); // size
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            ಯದಿ (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_SIZE);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_DATA_32DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
            }
            ಅನ್ಯಥಾ {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_DATA_32DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
                dwarf_data1(dwarf_info_section, PTR_SIZE);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_VERSION);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_ಸಾಲು_strp(dwarf_info_section, filename);
            dwarf_ಸಾಲು_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#ಯದಿ PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#ಅನ್ಯಥಾ
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#endif
            dwarf_reloc(dwarf_info_section, dwarf_sym.ಸಾಲು, R_DATA_32DW);
            dwarf_data4(dwarf_info_section, dwarf_ಸಾಲು_section->data_offset); // stmt_list

            /* dwarf_line */
            dwarf_ಸಾಲು.start = dwarf_ಸಾಲು_section->data_offset;
            dwarf_data4(dwarf_ಸಾಲು_section, 0); // length
            dwarf_data2(dwarf_ಸಾಲು_section, s1->dwarf); // version
            ಯದಿ (s1->dwarf >= 5) {
                dwarf_data1(dwarf_ಸಾಲು_section, PTR_SIZE); // address size
                dwarf_data1(dwarf_ಸಾಲು_section, 0); // segment selector
            }
            dwarf_data4(dwarf_ಸಾಲು_section, 0); // prologue Length
            dwarf_data1(dwarf_ಸಾಲು_section, DWARF_MIN_INSTR_LEN);
            ಯದಿ (s1->dwarf >= 4)
                dwarf_data1(dwarf_ಸಾಲು_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_ಸಾಲು_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_ಸಾಲು_section, DWARF_ಸಾಲು_BASE);
            dwarf_data1(dwarf_ಸಾಲು_section, DWARF_ಸಾಲು_RANGE);
            dwarf_data1(dwarf_ಸಾಲು_section, DWARF_OPCODE_BASE);
            ptr = section_ptr_add(dwarf_ಸಾಲು_section, ಪರಿಮಾಣ(dwarf_ಸಾಲು_opcodes));
            memcpy(ptr, dwarf_ಸಾಲು_opcodes, ಪರಿಮಾಣ(dwarf_ಸಾಲು_opcodes));
	    undo = strrchr(filename, '/');
	    ಯದಿ (undo)
		*undo = 0;
            dwarf_ಸಾಲು.dir_size = 1 + (undo != ರಿಕ್ತ);
            dwarf_ಸಾಲು.dir_table = (ವರ್ಣ **) tcc_malloc(ಪರಿಮಾಣ (ವರ್ಣ *) *
							dwarf_ಸಾಲು.dir_size);
            dwarf_ಸಾಲು.dir_table[0] = tcc_strdup(buf);
	    ಯದಿ (undo)
                dwarf_ಸಾಲು.dir_table[1] = tcc_strdup(filename);
            dwarf_ಸಾಲು.filename_size = 2;
            dwarf_ಸಾಲು.filename_table =
    	        (ಸಂರಚನಾ dwarf_filename_struct *)
    	        tcc_malloc(2*ಪರಿಮಾಣ (ಸಂರಚನಾ dwarf_filename_struct));
            dwarf_ಸಾಲು.filename_table[0].dir_entry = 0;
	    ಯದಿ (undo) {
                dwarf_ಸಾಲು.filename_table[0].name = tcc_strdup(undo + 1);
                dwarf_ಸಾಲು.filename_table[1].dir_entry = 1;
                dwarf_ಸಾಲು.filename_table[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    ಅನ್ಯಥಾ {
                dwarf_ಸಾಲು.filename_table[0].name = tcc_strdup(filename);
                dwarf_ಸಾಲು.filename_table[1].dir_entry = 0;
                dwarf_ಸಾಲು.filename_table[1].name = tcc_strdup(filename);
	    }
            dwarf_ಸಾಲು.ಸಾಲು_size = dwarf_ಸಾಲು.ಸಾಲು_max_size = 0;
            dwarf_ಸಾಲು.ಸಾಲು_data = ರಿಕ್ತ;
            dwarf_ಸಾಲು.cur_file = 1;
            dwarf_ಸಾಲು.last_file = 0;
            dwarf_ಸಾಲು.last_pc = 0;
            dwarf_ಸಾಲು.last_ಸಾಲು = 1;
            dwarf_ಸಾಲು_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_SIZE); // extended size
            dwarf_ಸಾಲು_op(s1, DW_LNE_set_address);
            ಪ್ರತಿ (i = 0; i < PTR_SIZE; i++)
    	        dwarf_ಸಾಲು_op(s1, 0);
            memset(&dwarf_info.base_type_used, 0, ಪರಿಮಾಣ(dwarf_info.base_type_used));
        }
        ಅನ್ಯಥಾ
        {
            /* file info: full path + filename */
            pstrcat(buf, ಪರಿಮಾಣ(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      text_section->sh_ಅಂಕೆ, ರಿಕ್ತ);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            ಪ್ರತಿ (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ fix_debug_forw_hash(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ global, ಪೂರ್ಣಾಙ್ಕ start);

/* put end of translation unit info */
ST_FUNC ಶೂನ್ಯ tcc_debug_end(TCCState *s1)
{

    ಯದಿ (!s1->do_debug || debug_next_type == 0)
        ಪ್ರತ್ಯಾಗಮ;

    ಯದಿ (debug_info_ಬೇರು)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    ಯದಿ (s1->dwarf) {
	ಪೂರ್ಣಾಙ್ಕ i;
	ಪೂರ್ಣಾಙ್ಕ start_aranges;
	unsigned ವರ್ಣ *ptr;
	ಪೂರ್ಣಾಙ್ಕ text_size = text_section->data_offset;

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
#ಯದಿ PTR_SIZE == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#ಅನ್ಯಥಾ
	dwarf_data1(dwarf_aranges_section, 8); // address size
#endif
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_DATA_PTR);
#ಯದಿ PTR_SIZE == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, text_size); // End
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#ಅನ್ಯಥಾ
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, text_size); // End
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#endif
	ptr = dwarf_aranges_section->data + start_aranges;
	write32le(ptr, dwarf_aranges_section->data_offset - start_aranges - 4);

	/* dwarf_line */
	ಯದಿ (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_ಸಾಲು_section, 1); /* col */
	    dwarf_uleb128(dwarf_ಸಾಲು_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_ಸಾಲು_section, DW_FORM_ಸಾಲು_strp);
	    dwarf_uleb128(dwarf_ಸಾಲು_section, dwarf_ಸಾಲು.dir_size);
	    ಪ್ರತಿ (i = 0; i < dwarf_ಸಾಲು.dir_size; i++)
	        dwarf_ಸಾಲು_strp(dwarf_ಸಾಲು_section, dwarf_ಸಾಲು.dir_table[i]);
	    dwarf_data1(dwarf_ಸಾಲು_section, 2); /* col */
	    dwarf_uleb128(dwarf_ಸಾಲು_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_ಸಾಲು_section, DW_FORM_ಸಾಲು_strp);
	    dwarf_uleb128(dwarf_ಸಾಲು_section, DW_LNCT_directory_index);
	    dwarf_uleb128(dwarf_ಸಾಲು_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_ಸಾಲು_section, dwarf_ಸಾಲು.filename_size);
	    ಪ್ರತಿ (i = 0; i < dwarf_ಸಾಲು.filename_size; i++) {
	        dwarf_ಸಾಲು_strp(dwarf_ಸಾಲು_section,
				dwarf_ಸಾಲು.filename_table[i].name);
	        dwarf_uleb128(dwarf_ಸಾಲು_section,
			      dwarf_ಸಾಲು.filename_table[i].dir_entry);
	    }
	}
	ಅನ್ಯಥಾ {
	    ಪೂರ್ಣಾಙ್ಕ len;

	    ಪ್ರತಿ (i = 0; i < dwarf_ಸಾಲು.dir_size; i++) {
	        len = strlen(dwarf_ಸಾಲು.dir_table[i]) + 1;
	        ptr = section_ptr_add(dwarf_ಸಾಲು_section, len);
	        memmove(ptr, dwarf_ಸಾಲು.dir_table[i], len);
	    }
	    dwarf_data1(dwarf_ಸಾಲು_section, 0); /* end dir */
	    ಪ್ರತಿ (i = 0; i < dwarf_ಸಾಲು.filename_size; i++) {
	        len = strlen(dwarf_ಸಾಲು.filename_table[i].name) + 1;
	        ptr = section_ptr_add(dwarf_ಸಾಲು_section, len);
	        memmove(ptr, dwarf_ಸಾಲು.filename_table[i].name, len);
	        dwarf_uleb128(dwarf_ಸಾಲು_section,
			      dwarf_ಸಾಲು.filename_table[i].dir_entry);
	        dwarf_uleb128(dwarf_ಸಾಲು_section, 0); /* time */
	        dwarf_uleb128(dwarf_ಸಾಲು_section, 0); /* size */
	    }
	    dwarf_data1(dwarf_ಸಾಲು_section, 0); /* end file */
	}
	ಪ್ರತಿ (i = 0; i < dwarf_ಸಾಲು.dir_size; i++)
	    tcc_free(dwarf_ಸಾಲು.dir_table[i]);
	tcc_free(dwarf_ಸಾಲು.dir_table);
	ಪ್ರತಿ (i = 0; i < dwarf_ಸಾಲು.filename_size; i++)
	    tcc_free(dwarf_ಸಾಲು.filename_table[i].name);
	tcc_free(dwarf_ಸಾಲು.filename_table);

	dwarf_ಸಾಲು_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_ಸಾಲು_op(s1, DW_LNE_end_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_ಸಾಲು_section->data[dwarf_ಸಾಲು.start + 6 + i],
		  dwarf_ಸಾಲು_section->data_offset - dwarf_ಸಾಲು.start - (10 + i));
	section_ptr_add(dwarf_ಸಾಲು_section, 3);
	dwarf_reloc(dwarf_ಸಾಲು_section, section_sym, R_DATA_PTR);
	ptr = section_ptr_add(dwarf_ಸಾಲು_section, dwarf_ಸಾಲು.ಸಾಲು_size - 3);
	memmove(ptr - 3, dwarf_ಸಾಲು.ಸಾಲು_data, dwarf_ಸಾಲು.ಸಾಲು_size);
	tcc_free(dwarf_ಸಾಲು.ಸಾಲು_data);
	write32le(dwarf_ಸಾಲು_section->data + dwarf_ಸಾಲು.start,
		  dwarf_ಸಾಲು_section->data_offset - dwarf_ಸಾಲು.start - 4);
    }
    ಅನ್ಯಥಾ
    {
        put_stabs_r(s1, ರಿಕ್ತ, N_SO, 0, 0,
                    text_section->data_offset, text_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_ಸಾಲು_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_next_type = 0;
}

ಸ್ಥಿರ BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    ಯದಿ (f->filename[0] == ':')
        f = f->prev;
    ಯದಿ (f && new_file) {
        new_file = last_ಸಾಲು_ಅಂಕೆ = 0;
        ಯದಿ (s1->dwarf)
            dwarf_file(s1);
        ಅನ್ಯಥಾ
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, text_section, section_sym);
    }
    ಪ್ರತ್ಯಾಗಮ f;
}

/* put alternative filename */
ST_FUNC ಶೂನ್ಯ tcc_debug_newfile(TCCState *s1)
{
    ಯದಿ (!s1->do_debug)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC ಶೂನ್ಯ tcc_debug_bincl(TCCState *s1)
{
    ಯದಿ (!s1->do_debug)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (s1->dwarf)
        dwarf_file(s1);
    ಅನ್ಯಥಾ
        put_stabs(s1, file->filename, N_BINCL, 0, 0, 0);
    new_file = 1;
}

/* end of #include */
ST_FUNC ಶೂನ್ಯ tcc_debug_eincl(TCCState *s1)
{
    ಯದಿ (!s1->do_debug)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (s1->dwarf)
        dwarf_file(s1);
    ಅನ್ಯಥಾ
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC ಶೂನ್ಯ tcc_debug_ಸಾಲು(TCCState *s1)
{
    BufferedFile *f;

    ಯದಿ (!s1->do_debug)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (cur_text_section != text_section || nocode_wanted)
        ಪ್ರತ್ಯಾಗಮ;
    f = put_new_file(s1);
    ಯದಿ (!f)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (last_ಸಾಲು_ಅಂಕೆ == f->ಸಾಲು_ಅಂಕೆ)
        ಪ್ರತ್ಯಾಗಮ;
    last_ಸಾಲು_ಅಂಕೆ = f->ಸಾಲು_ಅಂಕೆ;

    ಯದಿ (s1->dwarf) {
	ಪೂರ್ಣಾಙ್ಕ len_pc = (ind - dwarf_ಸಾಲು.last_pc) / DWARF_MIN_INSTR_LEN;
	ಪೂರ್ಣಾಙ್ಕ len_ಸಾಲು = f->ಸಾಲು_ಅಂಕೆ - dwarf_ಸಾಲು.last_ಸಾಲು;
	ಪೂರ್ಣಾಙ್ಕ n = len_pc * DWARF_ಸಾಲು_RANGE + len_ಸಾಲು + DWARF_OPCODE_BASE - DWARF_ಸಾಲು_BASE;

	ಯದಿ (dwarf_ಸಾಲು.cur_file != dwarf_ಸಾಲು.last_file) {
	    dwarf_ಸಾಲು.last_file = dwarf_ಸಾಲು.cur_file;
	    dwarf_ಸಾಲು_op(s1, DW_LNS_set_file);
	    dwarf_uleb128_op(s1, dwarf_ಸಾಲು.cur_file);
	}
	ಯದಿ (len_pc &&
	    len_ಸಾಲು >= DWARF_ಸಾಲು_BASE && len_ಸಾಲು <= (DWARF_OPCODE_BASE + DWARF_ಸಾಲು_BASE) &&
	    n >= DWARF_OPCODE_BASE && n <= 255)
            dwarf_ಸಾಲು_op(s1, n);
	ಅನ್ಯಥಾ {
	    ಯದಿ (len_pc) {
	        n = len_pc * DWARF_ಸಾಲು_RANGE + 0 + DWARF_OPCODE_BASE - DWARF_ಸಾಲು_BASE;
	        ಯದಿ (n >= DWARF_OPCODE_BASE && n <= 255)
                    dwarf_ಸಾಲು_op(s1, n);
		ಅನ್ಯಥಾ {
	            dwarf_ಸಾಲು_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    ಯದಿ (len_ಸಾಲು) {
	        n = 0 * DWARF_ಸಾಲು_RANGE + len_ಸಾಲು + DWARF_OPCODE_BASE - DWARF_ಸಾಲು_BASE;
	        ಯದಿ (len_ಸಾಲು >= DWARF_ಸಾಲು_BASE && len_ಸಾಲು <= (DWARF_OPCODE_BASE + DWARF_ಸಾಲು_BASE) &&
		    n >= DWARF_OPCODE_BASE && n <= 255)
	            dwarf_ಸಾಲು_op(s1, n);
		ಅನ್ಯಥಾ {
	            dwarf_ಸಾಲು_op(s1, DW_LNS_advance_ಸಾಲು);
		    dwarf_sleb128_op(s1, len_ಸಾಲು);
                    /* advance by nothing */
	            dwarf_ಸಾಲು_op(s1, DWARF_OPCODE_BASE - DWARF_ಸಾಲು_BASE);
		}
	    }
	}
	dwarf_ಸಾಲು.last_pc = ind;
	dwarf_ಸಾಲು.last_ಸಾಲು = f->ಸಾಲು_ಅಂಕೆ;
    }
    ಅನ್ಯಥಾ
    {
	ಯದಿ (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->ಸಾಲು_ಅಂಕೆ, ind - func_ind);
        } ಅನ್ಯಥಾ {
            /* from tcc_assemble */
            put_stabs_r(s1, ರಿಕ್ತ, N_SLINE, 0, f->ಸಾಲು_ಅಂಕೆ, ind, text_section, section_sym);
        }
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ tcc_debug_stabs (TCCState *s1, ಧ್ರುವ ವರ್ಣ *str, ಪೂರ್ಣಾಙ್ಕ type, unsigned long ಮೌಲ್ಯ,
                             Section *sec, ಪೂರ್ಣಾಙ್ಕ sym_index, ಪೂರ್ಣಾಙ್ಕ info)
{
    ಸಂರಚನಾ debug_sym *s;

    ಯದಿ (debug_info) {
        debug_info->sym =
            (ಸಂರಚನಾ debug_sym *)tcc_realloc (debug_info->sym,
                                             ಪರಿಮಾಣ(ಸಂರಚನಾ debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->ಮೌಲ್ಯ = ಮೌಲ್ಯ;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_index = sym_index;
        s->info = info;
        s->file = dwarf_ಸಾಲು.cur_file;
        s->ಸಾಲು = file->ಸಾಲು_ಅಂಕೆ;
    }
    ಅನ್ಯಥಾ ಯದಿ (sec)
        put_stabs_r (s1, str, type, 0, 0, ಮೌಲ್ಯ, sec, sym_index);
    ಅನ್ಯಥಾ
        put_stabs (s1, str, type, 0, 0, ಮೌಲ್ಯ);
}

ಸ್ಥಿರ ಶೂನ್ಯ fix_debug_forw_hash(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ global, ಪೂರ್ಣಾಙ್ಕ start)
{
    ಯದಿ (s1->dwarf) {
        ಪೂರ್ಣಾಙ್ಕ i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	ಸಂರಚನಾ _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	ಪ್ರತಿ (i = start; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    ಪೂರ್ಣಾಙ್ಕ pos = dwarf_info_section->data_offset;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_EMPTY_TYPE
                                             : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, ರಿಕ್ತ));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_ಸಾಲು.cur_file);
            dwarf_uleb128(dwarf_info_section, file->ಸಾಲು_ಅಂಕೆ);
	    ಪ್ರತಿ (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->data +
			  hash[i].debug_type[j],
			  pos - dwarf_info.start);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC ಶೂನ್ಯ tcc_debug_stabn(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ type, ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ)
{
    ಯದಿ (!s1->do_debug)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (type == N_LBRAC) {
        ಸಂರಚನಾ _debug_info *info =
            (ಸಂರಚನಾ _debug_info *) tcc_mallocz(ಪರಿಮಾಣ (*info));

        info->start = ಮೌಲ್ಯ;
        info->last_debug_hash = n_debug_hash_local;
        info->last_debug_forw_hash = n_debug_forw_hash_local;
        info->parent = debug_info;
        ಯದಿ (debug_info) {
            ಯದಿ (debug_info->child) {
                ಯದಿ (debug_info->child->last)
                    debug_info->child->last->next = info;
                ಅನ್ಯಥಾ
                    debug_info->child->next = info;
                debug_info->child->last = info;
            }
            ಅನ್ಯಥಾ
                debug_info->child = info;
        }
        ಅನ್ಯಥಾ
            debug_info_ಬೇರು = info;
        debug_info = info;
    }
    ಅನ್ಯಥಾ {
	fix_debug_forw_hash(s1, 0, debug_info->last_debug_forw_hash);
        n_debug_hash_local = debug_info->last_debug_hash;
        n_debug_forw_hash_local = debug_info->last_debug_forw_hash;
        debug_info->end = ಮೌಲ್ಯ;
        debug_info = debug_info->parent;
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ check_global(Sym *t)
{
    Sym *g = local_ರಾಶಿ;

    ಯಾವತ್ (g) {
	ಯದಿ (t == g)
	    ಪ್ರತ್ಯಾಗಮ 0;
	g = g->prev;
    }
    ಪ್ರತ್ಯಾಗಮ 1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_debug_find(TCCState *s1, Sym *t, ಪೂರ್ಣಾಙ್ಕ dwarf)
{
    ಪೂರ್ಣಾಙ್ಕ i , g = check_global(t);
    ಪೂರ್ಣಾಙ್ಕ n_hash, *n_forw_hash;
    ಸಂರಚನಾ _debug_hash *hash;
    ಸಂರಚನಾ _debug_forw_hash **forw_hash;

    ಯದಿ ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	ಪ್ರತಿ (i = 0; i < *n_forw_hash; i++)
            ಯದಿ (t == (*forw_hash)[i].type)
		ಪ್ರತ್ಯಾಗಮ 0;
	*forw_hash = (ಸಂರಚನಾ _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * ಪರಿಮಾಣ(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = ರಿಕ್ತ;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	ಪ್ರತ್ಯಾಗಮ 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    ಪ್ರತಿ (i = 0; i < n_hash; i++)
        ಯದಿ (t == hash[i].type)
	    ಪ್ರತ್ಯಾಗಮ hash[i].debug_type;
    ಪ್ರತ್ಯಾಗಮ -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_get_dwarf_info(TCCState *s1, Sym *s);

ಸ್ಥಿರ ಶೂನ್ಯ tcc_debug_check_forw(TCCState *s1, Sym *t, ಪೂರ್ಣಾಙ್ಕ debug_type)
{
    ಯದಿ ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        ಪೂರ್ಣಾಙ್ಕ i, j, g = check_global(t);
        ಪೂರ್ಣಾಙ್ಕ n_forw_hash;
        ಸಂರಚನಾ _debug_forw_hash **forw_hash;

	ಪ್ರತಿ (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    ಪ್ರತಿ (j = 0; j < n_forw_hash; j++)
                ಯದಿ (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    ಪ್ರತ್ಯಾಗಮ;
                }
	}
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC ಶೂನ್ಯ tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    ಯದಿ (!(s1->do_debug & 2))
	ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        ಪ್ರತ್ಯಾಗಮ;
    }
    ಯದಿ ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        ಪೂರ್ಣಾಙ್ಕ i, j, debug_type, g = check_global(t->ref);
        ಪೂರ್ಣಾಙ್ಕ *n_forw_hash;
        ಸಂರಚನಾ _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	ಪ್ರತಿ (i = 0; i < *n_forw_hash; i++)
	    ಯದಿ (t->ref == (*forw_hash)[i].type) {
		ಯದಿ (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    ಪ್ರತಿ (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->data +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.start);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		ಪ್ರತಿ (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_debug_add(TCCState *s1, Sym *t, ಪೂರ್ಣಾಙ್ಕ dwarf)
{
    ಪೂರ್ಣಾಙ್ಕ offset = dwarf ? dwarf_info_section->data_offset : ++debug_next_type;
    ಪೂರ್ಣಾಙ್ಕ *n_hash, g = check_global(t);
    ಸಂರಚನಾ _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (ಸಂರಚನಾ _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * ಪರಿಮಾಣ(**hash));
    (*hash)[*n_hash].debug_type = offset;
    (*hash)[(*n_hash)++].type = t;
    ಪ್ರತ್ಯಾಗಮ offset;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ STRUCT_NODEBUG(Sym *s)
{
    ಪ್ರತ್ಯಾಗಮ
    (s->a.nodebug ||
     ((s->v & ~SYM_FIELD) >= SYM_FIRST_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ stabs_struct_find(TCCState *s1, Sym *t, ಪೂರ್ಣಾಙ್ಕ *p_id)
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
    ಯದಿ (ರಿಕ್ತ == p_id)
        ಪ್ರತ್ಯಾಗಮ s && !s->r && t->c >= 0;
    ಯದಿ (ರಿಕ್ತ == s) {
        /* just use global_stack always */
        s = sym_push2(&global_ರಾಶಿ, SYM_FIELD|0x00DEBBED, 0, ++debug_next_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    ಯದಿ (s->r || t->c < 0) /* already defined or still incomplete */
        ಪ್ರತ್ಯಾಗಮ 0;
    s->r = 1;
    ಪ್ರತ್ಯಾಗಮ 1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ remove_type_info(ಪೂರ್ಣಾಙ್ಕ type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        ಯದಿ ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        ಯದಿ (!(type & VT_BITFIELD) && (type & VT_STRUCT_MASK) > VT_ENUM)
	    type &= ~VT_STRUCT_MASK;
	ಪ್ರತ್ಯಾಗಮ type;
}

ಸ್ಥಿರ ಶೂನ್ಯ tcc_get_debug_info(TCCState *s1, Sym *s, CString *result)
{
    ಪೂರ್ಣಾಙ್ಕ type;
    ಪೂರ್ಣಾಙ್ಕ n = 0;
    ಪೂರ್ಣಾಙ್ಕ debug_type = -1;
    Sym *t = s;
    CString str;

    ಪ್ರತಿ (;;) {
        type = remove_type_info (t->type.t);
        ಯದಿ (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        ಅನ್ಯಥಾ
            ಭಙ್ಗ;
    }
    ಯದಿ ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        ಯದಿ (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, ರಿಕ್ತ),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            ಯಾವತ್ (t->next) {
                ಪೂರ್ಣಾಙ್ಕ pos, size, align;
                t = t->next;
		ಯದಿ (STRUCT_NODEBUG(t))
		    ಅನುವರ್ತ;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, ರಿಕ್ತ)
                             );
                tcc_get_debug_info (s1, t, &str);
                ಯದಿ (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + BIT_POS(t->type.t);
                    size = BIT_SIZE(t->type.t);
                }
                ಅನ್ಯಥಾ {
                    pos = t->c * 8;
                    size = type_size(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, size);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, ರಿಕ್ತ, 0, 0);
            cstr_free (&str);
        }
    }
    ಅನ್ಯಥಾ ಯದಿ (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        ಯದಿ (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, ರಿಕ್ತ),
                         debug_type);
            ಯಾವತ್ (t->next) {
                t = t->next;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, ರಿಕ್ತ));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (ಪೂರ್ಣಾಙ್ಕ)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, ರಿಕ್ತ, 0, 0);
            cstr_free (&str);
	}
    }
    ಅನ್ಯಥಾ ಯದಿ ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        ಪ್ರತಿ (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            ಯದಿ (default_debug[debug_type - 1].type == type)
                ಭಙ್ಗ;
        ಯದಿ (debug_type > N_DEFAULT_DEBUG)
            ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (ರಿಕ್ತ == result) /* from stabs_struct_complete() */
        ಪ್ರತ್ಯಾಗಮ;

    ಯದಿ (n > 0)
        cstr_printf (result, "%d=", ++debug_next_type);
    t = s;
    ಪ್ರತಿ (;;) {
        type = remove_type_info (t->type.t);
        ಯದಿ (type == VT_PTR)
            cstr_printf (result, "%d=*", ++debug_next_type);
        ಅನ್ಯಥಾ ಯದಿ (type == (VT_PTR | VT_ARRAY))
            cstr_printf (result, "%d=ar1;0;%d;",
                         ++debug_next_type, t->type.ref->c - 1);
        ಅನ್ಯಥಾ ಯದಿ (type == VT_FUNC) {
            cstr_printf (result, "%d=f", ++debug_next_type);
            tcc_get_debug_info (s1, t->type.ref, result);
            ಪ್ರತ್ಯಾಗಮ;
        }
        ಅನ್ಯಥಾ
            ಭಙ್ಗ;
        t = t->type.ref;
    }
    cstr_printf (result, "%d", debug_type);
}

ಸ್ಥಿರ ಶೂನ್ಯ stabs_struct_complete(TCCState *s1, CType *t)
{
    ಯದಿ (stabs_struct_find(s1, t->ref, ರಿಕ್ತ)) {
        Sym s = {0}; s.type = *t;
        tcc_get_debug_info(s1, &s, ರಿಕ್ತ);
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_get_dwarf_info(TCCState *s1, Sym *s)
{
    ಪೂರ್ಣಾಙ್ಕ type;
    ಪೂರ್ಣಾಙ್ಕ debug_type = -1;
    Sym *e, *t = s;
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪೂರ್ಣಾಙ್ಕ last_pos = -1;
    ಪೂರ್ಣಾಙ್ಕ retval;

    ಯದಿ (new_file)
        put_new_file(s1);
    ಪ್ರತಿ (;;) {
        type = remove_type_info (t->type.t);
        ಯದಿ (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        ಅನ್ಯಥಾ
            ಭಙ್ಗ;
    }
    ಯದಿ ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	ಯದಿ (debug_type == -1) {
	    ಪೂರ್ಣಾಙ್ಕ pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_add(s1, t, 1);
	    e = t;
	    i = 0;
	    ಯಾವತ್ (e->next) {
		e = e->next;
		ಯದಿ (STRUCT_NODEBUG(e))
		    ಅನುವರ್ತ;
		i++;
	    }
	    pos_type = (ಪೂರ್ಣಾಙ್ಕ *) tcc_malloc(i * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->next ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_EMPTY_TYPE
		        : t->next ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, ರಿಕ್ತ));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_ಸಾಲು.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ಸಾಲು_ಅಂಕೆ);
	    ಯದಿ (t->next) {
	        pos_sib = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            ಯಾವತ್ (e->next) {
                e = e->next;
		ಯದಿ (STRUCT_NODEBUG(e))
		    ಅನುವರ್ತ;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, ರಿಕ್ತ));
		dwarf_uleb128(dwarf_info_section, dwarf_ಸಾಲು.cur_file);
		dwarf_uleb128(dwarf_info_section, file->ಸಾಲು_ಅಂಕೆ);
		pos_type[i++] = dwarf_info_section->data_offset;
		dwarf_data4(dwarf_info_section, 0);
                ಯದಿ (e->type.t & VT_BITFIELD) {
                    ಪೂರ್ಣಾಙ್ಕ pos = e->c * 8 + BIT_POS(e->type.t);
                    ಪೂರ್ಣಾಙ್ಕ size = BIT_SIZE(e->type.t);

		    dwarf_uleb128(dwarf_info_section, size);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		ಅನ್ಯಥಾ
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    ಯದಿ (t->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + pos_sib,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    e = t;
	    i = 0;
	    ಯಾವತ್ (e->next) {
		e = e->next;
		ಯದಿ (STRUCT_NODEBUG(e))
		    ಅನುವರ್ತ;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->data + pos_type[i++],
			  type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
    }
    ಅನ್ಯಥಾ ಯದಿ (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	ಯದಿ (debug_type == -1) {
	    ಪೂರ್ಣಾಙ್ಕ pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_add(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, ರಿಕ್ತ));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.start);
	    dwarf_uleb128(dwarf_info_section, dwarf_ಸಾಲು.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ಸಾಲು_ಅಂಕೆ);
	    pos_sib = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            ಯಾವತ್ (e->next) {
                e = e->next;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                           ? "" : get_tok_str(e->v, ರಿಕ್ತ));
		ಯದಿ (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		ಅನ್ಯಥಾ
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + pos_sib,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
    }
    ಅನ್ಯಥಾ ಯದಿ ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        ಪ್ರತಿ (i = 1; i <= N_DEFAULT_DEBUG; i++)
            ಯದಿ (default_debug[i - 1].type == type)
                ಭಙ್ಗ;
        ಯದಿ (i > N_DEFAULT_DEBUG)
            ಪ್ರತ್ಯಾಗಮ 0;
	debug_type = dwarf_info.base_type_used[i - 1];
	ಯದಿ (debug_type == 0) {
	    ವರ್ಣ name[100];

	    debug_type = dwarf_info_section->data_offset;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_BASE_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].size);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, ಪರಿಮಾಣ name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.base_type_used[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = ರಿಕ್ತ;
    t = s;
    ಪ್ರತಿ (;;) {
        type = remove_type_info (t->type.t);
        ಯದಿ (type == VT_PTR) {
	    i = dwarf_info_section->data_offset;
	    ಯದಿ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_POINTER);
	    dwarf_data1(dwarf_info_section, PTR_SIZE);
	    ಯದಿ (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        ಅನ್ಯಥಾ ಯದಿ (type == (VT_PTR | VT_ARRAY)) {
	    ಪೂರ್ಣಾಙ್ಕ sib_pos, sub_type;
#ಯದಿ LONG_SIZE == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#ಅನ್ಯಥಾ
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#endif

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->data_offset;
	    ಯದಿ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    ಯದಿ (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    ಪ್ರತಿ (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.start);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		ಯದಿ (type != (VT_PTR | VT_ARRAY))
		    ಭಙ್ಗ;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + sib_pos,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
        ಅನ್ಯಥಾ ಯದಿ (type == VT_FUNC) {
	    ಪೂರ್ಣಾಙ್ಕ sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->data_offset;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    ಯದಿ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->next ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_EMPTY_TYPE);
	    ಯದಿ (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    ಯದಿ (t->type.ref->next) {
	        sib_pos = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    ಯಾವತ್ (f->next) {
		f = f->next;
		i++;
	    }
	    pos_type = (ಪೂರ್ಣಾಙ್ಕ *) tcc_malloc(i * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
	    f = t->type.ref;
	    i = 0;
	    ಯಾವತ್ (f->next) {
		f = f->next;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    ಯದಿ (t->type.ref->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + sib_pos,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    f = t->type.ref;
	    i = 0;
	    ಯಾವತ್ (f->next) {
		f = f->next;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->data + pos_type[i++],
                          type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
        ಅನ್ಯಥಾ {
	    ಯದಿ (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  debug_type - dwarf_info.start);
	    }
            ಭಙ್ಗ;
	}
        t = t->type.ref;
    }
    ಪ್ರತ್ಯಾಗಮ retval;
}

ಸ್ಥಿರ ಶೂನ್ಯ tcc_debug_finish (TCCState *s1, ಸಂರಚನಾ _debug_info *cur)
{
    ಯಾವತ್ (cur) {
        ಸಂರಚನಾ _debug_info *next = cur->next;
        ಪೂರ್ಣಾಙ್ಕ i;

        ಯದಿ (s1->dwarf) {

            ಪ್ರತಿ (i = cur->n_sym - 1; i >= 0; i--) {
                ಸಂರಚನಾ debug_sym *s = &cur->sym[i];

		dwarf_data1(dwarf_info_section,
                            s->type == N_PSYM
			    ? DWARF_ABBREV_FORMAL_PARAMETER
			    : s->type == N_GSYM
                            ? DWARF_ABBREV_VARIABLE_EXTERNAL
                            : s->type == N_STSYM
			    ? DWARF_ABBREV_VARIABLE_STATIC
			    : DWARF_ABBREV_VARIABLE_LOCAL);
                dwarf_strp(dwarf_info_section, s->str);
		ಯದಿ (s->type == N_GSYM || s->type == N_STSYM) {
                    dwarf_uleb128(dwarf_info_section, s->file);
                    dwarf_uleb128(dwarf_info_section, s->ಸಾಲು);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.start);
		ಯದಿ (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    ಯದಿ (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    ಯದಿ (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#ಯದಿ PTR_SIZE == 4
                    dwarf_data4(dwarf_info_section, s->ಮೌಲ್ಯ);
#ಅನ್ಯಥಾ
                    dwarf_data8(dwarf_info_section, s->ಮೌಲ್ಯ);
#endif
		}
		ಅನ್ಯಥಾ {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_size((long)s->ಮೌಲ್ಯ) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (long)s->ಮೌಲ್ಯ);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->child ? DWARF_ABBREV_LEXICAL_BLOCK
			           : DWARF_ABBREV_LEXICAL_EMPTY_BLOCK);
            dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#ಯದಿ PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->start);
            dwarf_data4(dwarf_info_section, cur->end - cur->start);
#ಅನ್ಯಥಾ
            dwarf_data8(dwarf_info_section, func_ind + cur->start);
            dwarf_data8(dwarf_info_section, cur->end - cur->start);
#endif
            tcc_debug_finish (s1, cur->child);
	    ಯದಿ (cur->child)
                dwarf_data1(dwarf_info_section, 0);
        }
        ಅನ್ಯಥಾ
        {
            ಪ್ರತಿ (i = 0; i < cur->n_sym; i++) {
                ಸಂರಚನಾ debug_sym *s = &cur->sym[i];

                ಯದಿ (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->ಮೌಲ್ಯ,
                                s->sec, s->sym_index);
                ಅನ್ಯಥಾ
                    put_stabs(s1, s->str, s->type, 0, 0, s->ಮೌಲ್ಯ);
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

ST_FUNC ಶೂನ್ಯ tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    ಪೂರ್ಣಾಙ್ಕ param;

    ಯದಿ (!(s1->do_debug & 2))
        ಪ್ರತ್ಯಾಗಮ;

    cstr_new (&debug_str);
    param = !e;
    ಪ್ರತಿ (; s != e; s = s->prev) {
        ಯದಿ (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            ಅನುವರ್ತ;
	ಯದಿ (s1->dwarf) {
	    tcc_debug_stabs(s1, get_tok_str(s->v, ರಿಕ್ತ),
			    param ? N_PSYM : N_LSYM, s->c, ರಿಕ್ತ, 0,
			    tcc_get_dwarf_info(s1, s));
	}
	ಅನ್ಯಥಾ
        {
            cstr_reset (&debug_str);
            cstr_printf (&debug_str, "%s:%s", get_tok_str(s->v, ರಿಕ್ತ),
			 param ? "p" : "");
            tcc_get_debug_info(s1, s, &debug_str);
            tcc_debug_stabs(s1, debug_str.data, param ? N_PSYM : N_LSYM,
			    s->c, ರಿಕ್ತ, 0, 0);
	}
    }
    cstr_free (&debug_str);
}

/* put function symbol */
ST_FUNC ಶೂನ್ಯ tcc_debug_funcstart(TCCState *s1, Sym *sym)
{
    CString debug_str;
    BufferedFile *f;

    ಯದಿ (!s1->do_debug)
        ಪ್ರತ್ಯಾಗಮ;
    debug_info_ಬೇರು = ರಿಕ್ತ;
    debug_info = ರಿಕ್ತ;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    ಯದಿ (!f)
	ಪ್ರತ್ಯಾಗಮ;

    ಯದಿ (s1->dwarf) {
        tcc_debug_ಸಾಲು(s1);
        dwarf_info.func = sym;
        dwarf_info.ಸಾಲು = file->ಸಾಲು_ಅಂಕೆ;
	ಯದಿ (s1->do_backtrace) {
	    ಪೂರ್ಣಾಙ್ಕ i, len;

	    dwarf_ಸಾಲು_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, strlen(funcname) + 2);
	    dwarf_ಸಾಲು_op(s1, DW_LNE_hi_user - 1);
	    len = strlen(funcname) + 1;
	    ಪ್ರತಿ (i = 0; i < len; i++)
		dwarf_ಸಾಲು_op(s1, funcname[i]);
	}
    }
    ಅನ್ಯಥಾ
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.data, N_FUN, 0, f->ಸಾಲು_ಅಂಕೆ, 0, cur_text_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_ಸಾಲು(s1);
    }
}

ST_FUNC ಶೂನ್ಯ tcc_debug_prolog_epilog(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ)
{
    ಯದಿ (!s1->do_debug)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (s1->dwarf) {
	dwarf_ಸಾಲು_op(s1, ಮೌಲ್ಯ == 0 ? DW_LNS_set_prologue_end
				     : DW_LNS_set_epilogue_begin);
    }
}

/* put function size */
ST_FUNC ಶೂನ್ಯ tcc_debug_funcend(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ size)
{
    /* lldb does not like function end and next function start at same pc */
    ಪೂರ್ಣಾಙ್ಕ min_instr_len;

#ಯದಿ TCC_EH_FRAME
    tcc_debug_frame_end(s1, size);
#endif
    ಯದಿ (!s1->do_debug)
        ಪ್ರತ್ಯಾಗಮ;
    min_instr_len = dwarf_ಸಾಲು.last_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_ಸಾಲು(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, size);
    ಯದಿ (s1->dwarf) {
        ಪೂರ್ಣಾಙ್ಕ func_sib = 0;
	Sym *sym = dwarf_info.func;
	ಪೂರ್ಣಾಙ್ಕ n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        ಯದಿ ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_ಸಾಲು.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.ಸಾಲು);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->data_offset);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.start);
        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#ಯದಿ PTR_SIZE == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, size); // high_pc
#ಅನ್ಯಥಾ
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, size); // high_pc
#endif
        func_sib = dwarf_info_section->data_offset;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#ಯದಿ defined(TCC_TARGET_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#ಅನ್ಯಥಾ
        dwarf_data1(dwarf_info_section, DW_OP_call_frame_cfa);
#endif
        tcc_debug_finish (s1, debug_info_ಬೇರು);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->data + func_sib,
                  dwarf_info_section->data_offset - dwarf_info.start);
    }
    ಅನ್ಯಥಾ
    {
        tcc_debug_finish (s1, debug_info_ಬೇರು);
    }
    debug_info_ಬೇರು = 0;
}


ST_FUNC ಶೂನ್ಯ tcc_debug_extern_sym(TCCState *s1, Sym *sym, ಪೂರ್ಣಾಙ್ಕ sh_ಅಂಕೆ, ಪೂರ್ಣಾಙ್ಕ sym_bind, ಪೂರ್ಣಾಙ್ಕ sym_type)
{
    ಯದಿ (!(s1->do_debug & 2))
        ಪ್ರತ್ಯಾಗಮ;

    ಯದಿ (sym_type == STT_FUNC || sym->v >= SYM_FIRST_ANOM)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (s1->dwarf) {
        ಪೂರ್ಣಾಙ್ಕ debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, ರಿಕ್ತ));
	dwarf_uleb128(dwarf_info_section, dwarf_ಸಾಲು.cur_file);
	dwarf_uleb128(dwarf_info_section, file->ಸಾಲು_ಅಂಕೆ);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	ಯದಿ (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->data_offset,
		R_DATA_PTR, 0);
#ಯದಿ PTR_SIZE == 4
	dwarf_data4(dwarf_info_section, 0);
#ಅನ್ಯಥಾ
	dwarf_data8(dwarf_info_section, 0);
#endif
    }
    ಅನ್ಯಥಾ
    {
        Section *s = sh_ಅಂಕೆ == SHN_COMMON ? common_section
					  : s1->sections[sh_ಅಂಕೆ];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, ರಿಕ್ತ),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        ಯದಿ (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.data, N_GSYM, 0, ರಿಕ್ತ, 0, 0);
        ಅನ್ಯಥಾ
            tcc_debug_stabs(s1, str.data,
                (sym->type.t & VT_STATIC) && data_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC ಶೂನ್ಯ tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    ಯದಿ (!(s1->do_debug & 2))
        ಪ್ರತ್ಯಾಗಮ;

    ಯದಿ (s1->dwarf) {
	ಪೂರ್ಣಾಙ್ಕ debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	ಯದಿ (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, ರಿಕ್ತ));
	    dwarf_uleb128(dwarf_info_section, dwarf_ಸಾಲು.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ಸಾಲು_ಅಂಕೆ);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	}
    }
    ಅನ್ಯಥಾ
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, ರಿಕ್ತ));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.data, N_LSYM, 0, ರಿಕ್ತ, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC ಶೂನ್ಯ tcc_tcov_block_end(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ ಸಾಲು);

ST_FUNC ಶೂನ್ಯ tcc_tcov_block_begin(TCCState *s1)
{
    SValue sv;
    ಶೂನ್ಯ *ptr;
    unsigned long last_offset = tcov_data.offset;

    tcc_tcov_block_end (tcc_state, 0);
    ಯದಿ (s1->test_coverage == 0 || nocode_wanted)
	ಪ್ರತ್ಯಾಗಮ;

    ಯದಿ (tcov_data.last_file_name == 0 ||
	strcmp ((ಧ್ರುವ ವರ್ಣ *)(tcov_section->data + tcov_data.last_file_name),
		file->true_filename) != 0) {
	ವರ್ಣ wd[1024];
	CString cstr;

	ಯದಿ (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	ಯದಿ (tcov_data.last_file_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = 0;
	cstr_new (&cstr);
	ಯದಿ (file->true_filename[0] == '/') {
	    tcov_data.last_file_name = tcov_section->data_offset;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	ಅನ್ಯಥಾ {
	    getcwd (wd, ಪರಿಮಾಣ(wd));
	    tcov_data.last_file_name = tcov_section->data_offset + strlen(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_add(tcov_section, cstr.size + 1);
	strcpy((ವರ್ಣ *)ptr, cstr.data);
#ifdef _WIN32
        normalize_slashes((ವರ್ಣ *)ptr);
#endif
	cstr_free (&cstr);
    }
    ಯದಿ (tcov_data.last_func_name == 0 ||
	strcmp ((ಧ್ರುವ ವರ್ಣ *)(tcov_section->data + tcov_data.last_func_name),
		funcname) != 0) {
	size_t len;

	ಯದಿ (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = tcov_section->data_offset;
	len = strlen (funcname);
	ptr = section_ptr_add(tcov_section, len + 1);
	strcpy((ವರ್ಣ *)ptr, funcname);
	section_ptr_add(tcov_section, -tcov_section->data_offset & 7);
	ptr = section_ptr_add(tcov_section, 8);
	write64le (ptr, file->ಸಾಲು_ಅಂಕೆ);
    }
    ಯದಿ (ind == tcov_data.ind && tcov_data.ಸಾಲು == file->ಸಾಲು_ಅಂಕೆ)
        tcov_data.offset = last_offset;
    ಅನ್ಯಥಾ {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_add(tcov_section, 16);
        tcov_data.ಸಾಲು = file->ಸಾಲು_ಅಂಕೆ;
        write64le (ptr, (tcov_data.ಸಾಲು << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((unsigned ವರ್ಣ *)ptr - tcov_section->data) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#ಯದಿ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || \
    defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || \
    defined TCC_TARGET_RISCV64
        gen_increment_tcov (&sv);
#ಅನ್ಯಥಾ
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#endif
        tcov_data.offset = (unsigned ವರ್ಣ *)ptr - tcov_section->data;
        tcov_data.ind = ind;
    }
}

ST_FUNC ಶೂನ್ಯ tcc_tcov_block_end(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ ಸಾಲು)
{
    ಯದಿ (s1->test_coverage == 0)
	ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (ಸಾಲು == -1)
        ಸಾಲು = tcov_data.ಸಾಲು;
    ಯದಿ (tcov_data.offset) {
	ಶೂನ್ಯ *ptr = tcov_section->data + tcov_data.offset;
	unsigned long long nline = ಸಾಲು ? ಸಾಲು : file->ಸಾಲು_ಅಂಕೆ;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_data.offset = 0;
    }
}

ST_FUNC ಶೂನ್ಯ tcc_tcov_check_ಸಾಲು(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ start)
{
    ಯದಿ (s1->test_coverage == 0)
	ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (tcov_data.ಸಾಲು != file->ಸಾಲು_ಅಂಕೆ) {
        ಯದಿ ((tcov_data.ಸಾಲು + 1) != file->ಸಾಲು_ಅಂಕೆ) {
	    tcc_tcov_block_end (s1, -1);
	    ಯದಿ (start)
                tcc_tcov_block_begin (s1);
	}
	ಅನ್ಯಥಾ
	    tcov_data.ಸಾಲು = file->ಸಾಲು_ಅಂಕೆ;
    }
}

ST_FUNC ಶೂನ್ಯ tcc_tcov_start(TCCState *s1)
{
    ಯದಿ (s1->test_coverage == 0)
	ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (!s1->dState)
        s1->dState = tcc_mallocz(ಪರಿಮಾಣ *s1->dState);
    memset (&tcov_data, 0, ಪರಿಮಾಣ (tcov_data));
    ಯದಿ (tcov_section == ರಿಕ್ತ) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_add(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC ಶೂನ್ಯ tcc_tcov_end(TCCState *s1)
{
    ಯದಿ (s1->test_coverage == 0)
	ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (tcov_data.last_func_name)
        section_ptr_add(tcov_section, 1);
    ಯದಿ (tcov_data.last_file_name)
        section_ptr_add(tcov_section, 1);
}

ST_FUNC ಶೂನ್ಯ tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_data.ind = 0;
}

/* ------------------------------------------------------------------------- */
#undef last_ಸಾಲು_ಅಂಕೆ
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
#undef debug_info_ಬೇರು
#undef dwarf_sym
#undef dwarf_ಸಾಲು
#undef dwarf_info
#undef dwarf_str
#undef dwarf_ಸಾಲು_str
#undef tcov_data
