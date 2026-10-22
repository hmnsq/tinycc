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

स्थिर अचर संरचना {
  पूर्णाङ्क type;
  पूर्णाङ्क size;
  पूर्णाङ्क encoding;
  अचर वर्ण *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#यदि LONG_SIZE == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#अन्यथा
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#endif
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#यदि LONG_SIZE == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#अन्यथा
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
#अन्यथा
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
#यदि LONG_SIZE == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#अन्यथा
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#endif
};

#define	N_DEFAULT_DEBUG	(परिमाण (default_debug) / परिमाण (default_debug[0]))

/* dwarf debug */

#define	DWARF_पङ्क्ति_BASE				-5
#define	DWARF_पङ्क्ति_RANGE			14
#define	DWARF_OPCODE_BASE			13

#यदि defined TCC_TARGET_ARM64
#define	DWARF_MIN_INSTR_LEN			4
#अथवायदि defined TCC_TARGET_ARM
#define	DWARF_MIN_INSTR_LEN			2
#अन्यथा
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
स्थिर अचर अचिन्हित वर्ण dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_TAG_compile_unit, 1,
          DW_AT_producer, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_पङ्क्ति_strp,
          DW_AT_comp_dir, DW_FORM_पङ्क्ति_strp,
          DW_AT_तल्लो_pc, DW_FORM_addr,
#यदि PTR_SIZE == 4
          DW_AT_माथिल्लो_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_माथिल्लो_pc, DW_FORM_data8,
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
          DW_AT_decl_पङ्क्ति, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_TAG_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्ति, DW_FORM_udata,
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
          DW_AT_decl_पङ्क्ति, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_TAG_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_मान, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_TAG_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_मान, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_TAG_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_size, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्ति, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्ति, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_data_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्ति, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_bit_size, DW_FORM_udata,
          DW_AT_data_bit_offset, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_TAG_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्ति, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_EMPTY_TYPE, DW_TAG_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्ति, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_TAG_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्ति, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_EMPTY_TYPE, DW_TAG_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्ति, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_TAG_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्ति, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_तल्लो_pc, DW_FORM_addr,
#यदि PTR_SIZE == 4
          DW_AT_माथिल्लो_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_माथिल्लो_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_TAG_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_पङ्क्ति, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_तल्लो_pc, DW_FORM_addr,
#यदि PTR_SIZE == 4
          DW_AT_माथिल्लो_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_माथिल्लो_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_BLOCK, DW_TAG_lexical_block, 1,
          DW_AT_तल्लो_pc, DW_FORM_addr,
#यदि PTR_SIZE == 4
          DW_AT_माथिल्लो_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_माथिल्लो_pc, DW_FORM_data8,
#endif
          0, 0,
    DWARF_ABBREV_LEXICAL_EMPTY_BLOCK, DW_TAG_lexical_block, 0,
          DW_AT_तल्लो_pc, DW_FORM_addr,
#यदि PTR_SIZE == 4
          DW_AT_माथिल्लो_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_माथिल्लो_pc, DW_FORM_data8,
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

स्थिर अचर अचिन्हित वर्ण dwarf_पङ्क्ति_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#define N_STR_HASH (251)

संरचना dwarf_str_hash {
    पूर्णाङ्क len;
    अचिन्हित दीर्घ data_offset;
    संरचना dwarf_str_hash *next;
};

संरचना _tccdbg {

    पूर्णाङ्क last_पङ्क्ति_अङ्क, new_file;
    पूर्णाङ्क section_sym;

    पूर्णाङ्क debug_next_type;

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
        पूर्णाङ्क end;
        पूर्णाङ्क last_debug_hash;
        पूर्णाङ्क last_debug_forw_hash;
        पूर्णाङ्क n_sym;
        संरचना debug_sym {
            पूर्णाङ्क type;
            अचिन्हित दीर्घ मान;
            वर्ण *str;
            Section *sec;
            पूर्णाङ्क sym_index;
            पूर्णाङ्क info;
            पूर्णाङ्क file;
            पूर्णाङ्क पङ्क्ति;
        } *sym;
        संरचना _debug_info *child, *next, *last, *parent;
    } *debug_info, *debug_info_जरा;

    संरचना {
        पूर्णाङ्क info;
        पूर्णाङ्क abbrev;
        पूर्णाङ्क पङ्क्ति;
        पूर्णाङ्क str;
        पूर्णाङ्क पङ्क्ति_str;
    } dwarf_sym;

    संरचना {
        पूर्णाङ्क start;
        पूर्णाङ्क dir_size;
        वर्ण **dir_table;
        पूर्णाङ्क filename_size;
        संरचना dwarf_filename_struct {
            पूर्णाङ्क dir_entry;
            वर्ण *name;
        } *filename_table;
        पूर्णाङ्क पङ्क्ति_size;
        पूर्णाङ्क पङ्क्ति_max_size;
        अचिन्हित वर्ण *पङ्क्ति_data;
        पूर्णाङ्क cur_file;
        पूर्णाङ्क last_file;
        पूर्णाङ्क last_pc;
        पूर्णाङ्क last_पङ्क्ति;
    } dwarf_पङ्क्ति;

    संरचना {
        पूर्णाङ्क start;
        Sym *func;
        पूर्णाङ्क पङ्क्ति;
        पूर्णाङ्क base_type_used[N_DEFAULT_DEBUG];
    } dwarf_info;

    संरचना dwarf_str_hash *dwarf_str[N_STR_HASH];
    संरचना dwarf_str_hash *dwarf_पङ्क्ति_str[N_STR_HASH];

    /* test coverage */
    संरचना {
        अचिन्हित दीर्घ offset;
        अचिन्हित दीर्घ last_file_name;
        अचिन्हित दीर्घ last_func_name;
        पूर्णाङ्क ind;
        पूर्णाङ्क पङ्क्ति;
    } tcov_data;
};

#define last_पङ्क्ति_अङ्क             s1->dState->last_पङ्क्ति_अङ्क
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
#define debug_info_जरा           s1->dState->debug_info_जरा
#define dwarf_sym                 s1->dState->dwarf_sym
#define dwarf_पङ्क्ति                s1->dState->dwarf_पङ्क्ति
#define dwarf_info                s1->dState->dwarf_info
#define dwarf_str                 s1->dState->dwarf_str
#define dwarf_पङ्क्ति_str            s1->dState->dwarf_पङ्क्ति_str
#define tcov_data                 s1->dState->tcov_data

#define	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
स्थिर पूर्णाङ्क put_stabs(TCCState *s1, अचर वर्ण *str, पूर्णाङ्क type, पूर्णाङ्क other,
    पूर्णाङ्क desc, अचिन्हित दीर्घ मान);

ST_FUNC शून्य tcc_debug_new(TCCState *s1)
{
    पूर्णाङ्क shf = 0;
    यदि (!s1->dState)
        s1->dState = tcc_mallocz(परिमाण *s1->dState);

#ifdef CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    यदि (s1->do_debug && s1->output_type == TCC_OUTPUT_MEMORY)
        s1->do_backtrace = 1;
    यदि (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#endif

    यदि (s1->dwarf) {
	पूर्णाङ्क i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	स्थिर अचर वर्ण *अचर debug[] = {
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
        dwarf_पङ्क्ति_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	लागि (i = 0; i < परिमाण(debug)/परिमाण(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_MERGE | SHF_STRINGS;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_पङ्क्ति_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	यदि (s1->dwarf >= 5) {
            dwarf_पङ्क्ति_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_पङ्क्ति_str_section->sh_entsize = 1;
	    dwarf_पङ्क्ति_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    अन्यथा
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = परिमाण(Stab_Sym);
        stab_section->sh_addralign = परिमाण ((Stab_Sym*)0)->n_मान;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
स्थिर पूर्णाङ्क put_stabs(TCCState *s1, अचर वर्ण *str, पूर्णाङ्क type, पूर्णाङ्क other, पूर्णाङ्क desc,
                      अचिन्हित दीर्घ मान)
{
    Stab_Sym *sym;

    अचिन्हित offset;
    यदि (type == N_SLINE
        && (offset = stab_section->data_offset)
        && (sym = (Stab_Sym*)(stab_section->data + offset) - 1)
        && sym->n_type == type
        && sym->n_मान == मान) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        फर्काऊ 0;
    }

    sym = section_ptr_add(stab_section, परिमाण(Stab_Sym));
    यदि (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } अन्यथा {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_मान = मान;
    फर्काऊ 1;
}

स्थिर शून्य put_stabs_r(TCCState *s1, अचर वर्ण *str, पूर्णाङ्क type, पूर्णाङ्क other, पूर्णाङ्क desc,
                        अचिन्हित दीर्घ मान, Section *sec, पूर्णाङ्क sym_index)
{
    यदि (put_stabs(s1, str, type, other, desc, मान))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->data_offset - 4,
                      परिमाण ((Stab_Sym*)0)->n_मान == PTR_SIZE ? R_DATA_PTR : R_DATA_32,
                      sym_index);
}

स्थिर शून्य put_stabn(TCCState *s1, पूर्णाङ्क type, पूर्णाङ्क other, पूर्णाङ्क desc, पूर्णाङ्क मान)
{
    put_stabs(s1, रिक्त, type, other, desc, मान);
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

स्थिर पूर्णाङ्क dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    फर्काऊ put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_अङ्क, रिक्त);
}

स्थिर शून्य dwarf_reloc(Section *s, पूर्णाङ्क sym, पूर्णाङ्क rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->data_offset, rel, sym, 0);
}

स्थिर शून्य free_str(संरचना dwarf_str_hash **str)
{
    पूर्णाङ्क i;

    लागि (i = 0; i < N_STR_HASH; i++) {
       जबसम्म (str[i]) {
           संरचना dwarf_str_hash *next = str[i]->next;

           tcc_free(str[i]);
           str[i] = next;
       }
    }
}

स्थिर अचिन्हित str_hash(अचर वर्ण *s)
{
    अचिन्हित h = 5381;

    जबसम्म (*s)
       h += (*s++ & 0xffu) + h * 31;
    फर्काऊ h;
}

स्थिर शून्य dwarf_string(Section *s, Section *dw, पूर्णाङ्क sym, अचर वर्ण *str)
{
    TCCState *s1 = s->s1;
    पूर्णाङ्क len, hash = str_hash(str) % N_STR_HASH;
    वर्ण *ptr;
    संरचना dwarf_str_hash *new_hash;
    संरचना dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_पङ्क्ति_str;

    len = म_माप(str) + 1;
    new_hash = dw_hash[hash];
    जबसम्म (new_hash) {
	यदि (new_hash->len == len &&
	    !स_भेद(str, dw->data + new_hash->data_offset, len))
	    रोक;
	new_hash = new_hash->next;
    }
    यदि (new_hash == रिक्त) {
	अचिन्हित दीर्घ offset = dw->data_offset;

        new_hash = dw_hash[hash];
        जबसम्म (new_hash) {
	    अचिन्हित दीर्घ n = new_hash->data_offset + new_hash->len - len;

	    यदि (new_hash->len > len &&
	        !स_भेद(str, dw->data + n, len)) {
		offset = n;
		रोक;
	    }
	    new_hash = new_hash->next;
        }
	यदि (new_hash == रिक्त) {
	    ptr = section_ptr_add(dw, len);
	    स_हटाओ(ptr, str, len);
	}
	new_hash = (संरचना dwarf_str_hash *)
	    tcc_malloc(परिमाण(संरचना dwarf_str_hash));
	new_hash->len = len;
	new_hash->data_offset = offset;
	new_hash->next = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->data_offset, R_DATA_32DW, sym,
                   PTR_SIZE == 4 ? 0 : new_hash->data_offset);
    dwarf_data4(s, PTR_SIZE == 4 ? new_hash->data_offset : 0);
}

स्थिर शून्य dwarf_strp(Section *s, अचर वर्ण *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

स्थिर शून्य dwarf_पङ्क्ति_strp(Section *s, अचर वर्ण *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_पङ्क्ति_str_section, dwarf_sym.पङ्क्ति_str, str);
}

स्थिर शून्य dwarf_पङ्क्ति_op(TCCState *s1, अचिन्हित वर्ण op)
{
    यदि (dwarf_पङ्क्ति.पङ्क्ति_size >= dwarf_पङ्क्ति.पङ्क्ति_max_size) {
	dwarf_पङ्क्ति.पङ्क्ति_max_size += 1024;
	dwarf_पङ्क्ति.पङ्क्ति_data =
	    (अचिन्हित वर्ण *)tcc_realloc(dwarf_पङ्क्ति.पङ्क्ति_data,
					 dwarf_पङ्क्ति.पङ्क्ति_max_size);
    }
    dwarf_पङ्क्ति.पङ्क्ति_data[dwarf_पङ्क्ति.पङ्क्ति_size++] = op;
}

स्थिर शून्य dwarf_file(TCCState *s1)
{
    पूर्णाङ्क i, j;
    वर्ण *filename;
    पूर्णाङ्क index_offset = s1->dwarf < 5;

    यदि (!म_भेद(file->filename, "<command line>")) {
        dwarf_पङ्क्ति.cur_file = 1;
	फर्काऊ;
    }
    filename = म_खोजप(file->filename, '/');
    यदि (filename == रिक्त) {
        लागि (i = 1; i < dwarf_पङ्क्ति.filename_size; i++)
            यदि (dwarf_पङ्क्ति.filename_table[i].dir_entry == 0 &&
		म_भेद(dwarf_पङ्क्ति.filename_table[i].name,
		       file->filename) == 0) {
		    dwarf_पङ्क्ति.cur_file = i + index_offset;
	            फर्काऊ;
		}
	i = -index_offset;
	filename = file->filename;
    }
    अन्यथा {
	वर्ण *undo = filename;
	वर्ण *dir = file->filename;

	*filename++ = '\0';
        लागि (i = 0; i < dwarf_पङ्क्ति.dir_size; i++)
	    यदि (म_भेद(dwarf_पङ्क्ति.dir_table[i], dir) == 0) {
		लागि (j = 1; j < dwarf_पङ्क्ति.filename_size; j++)
		    यदि (dwarf_पङ्क्ति.filename_table[j].dir_entry - index_offset
			== i &&
			म_भेद(dwarf_पङ्क्ति.filename_table[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_पङ्क्ति.cur_file = j + index_offset;
			फर्काऊ;
		    }
		रोक;
	    }
	यदि (i == dwarf_पङ्क्ति.dir_size) {
	    dwarf_पङ्क्ति.dir_size++;
	    dwarf_पङ्क्ति.dir_table =
                (वर्ण **) tcc_realloc(dwarf_पङ्क्ति.dir_table,
                                      dwarf_पङ्क्ति.dir_size *
                                      परिमाण (वर्ण *));
            dwarf_पङ्क्ति.dir_table[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_पङ्क्ति.filename_table =
        (संरचना dwarf_filename_struct *)
        tcc_realloc(dwarf_पङ्क्ति.filename_table,
                    (dwarf_पङ्क्ति.filename_size + 1) *
                    परिमाण (संरचना dwarf_filename_struct));
    dwarf_पङ्क्ति.filename_table[dwarf_पङ्क्ति.filename_size].dir_entry =
	i + index_offset;
    dwarf_पङ्क्ति.filename_table[dwarf_पङ्क्ति.filename_size].name =
        tcc_strdup(filename);
    dwarf_पङ्क्ति.cur_file = dwarf_पङ्क्ति.filename_size++ + index_offset;
    फर्काऊ;
}

#यदि 0
स्थिर पूर्णाङ्क dwarf_uleb128_size (अचिन्हित दीर्घ दीर्घ मान)
{
    पूर्णाङ्क size =  0;

    गर {
        मान >>= 7;
        size++;
    } जबसम्म (मान != 0);
    फर्काऊ size;
}
#endif

स्थिर पूर्णाङ्क dwarf_sleb128_size (दीर्घ दीर्घ मान)
{
    पूर्णाङ्क size =  0;
    दीर्घ दीर्घ end = मान >> 63;
    अचिन्हित वर्ण last = end & 0x40;
    अचिन्हित वर्ण byte;

    गर {
        byte = मान & 0x7f;
        मान >>= 7;
        size++;
    } जबसम्म (मान != end || (byte & 0x40) != last);
    फर्काऊ size;
}

स्थिर शून्य dwarf_uleb128 (Section *s, अचिन्हित दीर्घ दीर्घ मान)
{
    गर {
        अचिन्हित वर्ण byte = मान & 0x7f;

        मान >>= 7;
        dwarf_data1(s, byte | (मान ? 0x80 : 0));
    } जबसम्म (मान != 0);
}

स्थिर शून्य dwarf_sleb128 (Section *s, दीर्घ दीर्घ मान)
{
    पूर्णाङ्क more;
    दीर्घ दीर्घ end = मान >> 63;
    अचिन्हित वर्ण last = end & 0x40;

    गर {
        अचिन्हित वर्ण byte = मान & 0x7f;

        मान >>= 7;
	more = मान != end || (byte & 0x40) != last;
        dwarf_data1(s, byte | (0x80 * more));
    } जबसम्म (more);
}

स्थिर शून्य dwarf_uleb128_op (TCCState *s1, अचिन्हित दीर्घ दीर्घ मान)
{
    गर {
        अचिन्हित वर्ण byte = मान & 0x7f;

        मान >>= 7;
        dwarf_पङ्क्ति_op(s1, byte | (मान ? 0x80 : 0));
    } जबसम्म (मान != 0);
}

स्थिर शून्य dwarf_sleb128_op (TCCState *s1, दीर्घ दीर्घ मान)
{
    पूर्णाङ्क more;
    दीर्घ दीर्घ end = मान >> 63;
    अचिन्हित वर्ण last = end & 0x40;

    गर {
        अचिन्हित वर्ण byte = मान & 0x7f;

        मान >>= 7;
        more = मान != end || (byte & 0x40) != last;
        dwarf_पङ्क्ति_op(s1, byte | (0x80 * more));
    } जबसम्म (more);
}

#यदि TCC_EH_FRAME
ST_FUNC शून्य tcc_eh_frame_start(TCCState *s1)
{
    यदि (!s1->unwind_tables)
        फर्काऊ;
    eh_frame_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section, 0); // CIE ID
    dwarf_data1(eh_frame_section, 1); // Version
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
    dwarf_data1(eh_frame_section, DW_CFA_offset + 8); // r8 (eip)
    dwarf_uleb128(eh_frame_section, 1); // cfa-4
#अथवायदि defined TCC_TARGET_X86_64
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
#अथवायदि defined TCC_TARGET_ARM
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
#अथवायदि defined TCC_TARGET_ARM64
    dwarf_uleb128(eh_frame_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 30); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 31); // x31 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#अथवायदि defined TCC_TARGET_RISCV64
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
    जबसम्म ((eh_frame_section->data_offset - s1->eh_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + s1->eh_start, // length
	      eh_frame_section->data_offset - s1->eh_start - 4);
}

स्थिर शून्य tcc_debug_frame_end(TCCState *s1, पूर्णाङ्क size)
{
    पूर्णाङ्क eh_section_sym;
    अचिन्हित दीर्घ fde_start;

    यदि (!eh_frame_section)
	फर्काऊ;
    eh_section_sym = dwarf_get_section_sym(text_section);
    fde_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section,
		fde_start - s1->eh_start + 4); // CIE Pointer
#यदि defined TCC_TARGET_I386
    dwarf_reloc(eh_frame_section, eh_section_sym, R_386_PC32);
#अथवायदि defined TCC_TARGET_X86_64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_X86_64_PC32);
#अथवायदि defined TCC_TARGET_ARM
    dwarf_reloc(eh_frame_section, eh_section_sym, R_ARM_REL32);
#अथवायदि defined TCC_TARGET_ARM64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_AARCH64_PREL32);
#अथवायदि defined TCC_TARGET_RISCV64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_RISCV_32_PCREL);
#endif
    dwarf_data4(eh_frame_section, func_ind); // PC Begin
    dwarf_data4(eh_frame_section, size); // PC Range
    dwarf_data1(eh_frame_section, 0); // Augmentation Length
#यदि defined TCC_TARGET_I386
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
#अथवायदि defined TCC_TARGET_X86_64
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
#अथवायदि defined TCC_TARGET_ARM
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
#अथवायदि defined TCC_TARGET_ARM64
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
#अथवायदि defined TCC_TARGET_RISCV64
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
    जबसम्म (size >= 4 &&
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
    जबसम्म ((eh_frame_section->data_offset - fde_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + fde_start, // length
	      eh_frame_section->data_offset - fde_start - 4);
}

ST_FUNC शून्य tcc_eh_frame_end(TCCState *s1)
{
    यदि (!eh_frame_section)
	फर्काऊ;
    dwarf_data4(eh_frame_section, 0);
}

संरचना eh_खोज_table {
    uint32_t pc_offset;
    uint32_t fde_offset;
};

स्थिर पूर्णाङ्क sort_eh_table(अचर शून्य *a, अचर शून्य *b)
{
    uint32_t pc1 = ((अचर संरचना eh_खोज_table *)a)->pc_offset;
    uint32_t pc2 = ((अचर संरचना eh_खोज_table *)b)->pc_offset;

    फर्काऊ pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC शून्य tcc_eh_frame_hdr(TCCState *s1, पूर्णाङ्क final)
{
    पूर्णाङ्क गन्ती_2 = 0, offset;
    अचिन्हित दीर्घ गन्ती_offset, tab_offset;
    अचिन्हित वर्ण *ln, *end;
    अचिन्हित पूर्णाङ्क last_cie_offset = 0xffffffff;

    यदि (!eh_frame_section || !eh_frame_section->data_offset)
	फर्काऊ;
    यदि (final && !eh_frame_hdr_section)
	फर्काऊ;
    यदि (final == 0)
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
    //गन्ती
    गन्ती_offset = eh_frame_hdr_section->data_offset;
    dwarf_data4(eh_frame_hdr_section, 0);
    tab_offset = eh_frame_hdr_section->data_offset;
    ln = eh_frame_section->data;
    end = eh_frame_section->data + eh_frame_section->data_offset;
    जबसम्म (ln < end) {
	अचिन्हित वर्ण *fde = ln, *rd = ln;
	अचिन्हित पूर्णाङ्क cie_offset, version, length = dwarf_read_4(rd, end);
	अचिन्हित पूर्णाङ्क pc_offset, fde_offset;

	यदि (length == 0)
	    गच्छ next;
        cie_offset = dwarf_read_4(rd, end);
	यदि (cie_offset == 0)
	    गच्छ next;
	यदि (cie_offset != last_cie_offset) {
	    अचिन्हित वर्ण *cie = rd - cie_offset + 4;

	    यदि (cie < eh_frame_section->data)
		गच्छ next;
	    version = dwarf_read_1(cie, end);
	    यदि ((version == 1 || version == 3) &&
	        dwarf_read_1(cie, end) == 'z' && // Augmentation String
		dwarf_read_1(cie, end) == 'R' &&
		dwarf_read_1(cie, end) == 0) {
	        dwarf_read_uleb128(&cie, end); // code_alignment_factor
	        dwarf_read_sleb128(&cie, end); // data_alignment_factor
		dwarf_read_1(cie, end); // return address column
		यदि (dwarf_read_uleb128(&cie, end) == 1 &&
		    dwarf_read_1(cie, end) == FDE_ENCODING) {
		    last_cie_offset = cie_offset;
		}
		अन्यथा
		    गच्छ next;
	    }
	    अन्यथा
		गच्छ next;
	}
	गन्ती_2++;
	fde_offset = eh_frame_section->sh_addr +
		     (fde - eh_frame_section->data) -
		     eh_frame_hdr_section->sh_addr;
	pc_offset = dwarf_read_4(rd, end) + fde_offset + 8;
	dwarf_data4(eh_frame_hdr_section, pc_offset);
	dwarf_data4(eh_frame_hdr_section, fde_offset);
next:
	ln += length + 4;
    }
    add32le(eh_frame_hdr_section->data + गन्ती_offset, गन्ती_2);
    क्विक(eh_frame_hdr_section->data + tab_offset, गन्ती_2,
	  परिमाण(संरचना eh_खोज_table), sort_eh_table);
}
#endif

/* start of translation unit info */
ST_FUNC शून्य tcc_debug_start(TCCState *s1)
{
    पूर्णाङ्क i;
    वर्ण buf[512];
    वर्ण *filename;

    /* we might currently #include the <command-line> */
    filename = file->prev ? file->prev->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    यदि (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, text_section->data_offset, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            text_section->sh_अङ्क, "$a");

        new_file = last_पङ्क्ति_अङ्क = 0;
        debug_next_type = N_DEFAULT_DEBUG;
        debug_hash_global = रिक्त;
        debug_hash_local = रिक्त;
        debug_forw_hash_global = रिक्त;
        debug_forw_hash_local = रिक्त;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, परिमाण(buf));
#ifdef _WIN32
        normalize_slashes(buf);
#endif

        यदि (s1->dwarf) {
            पूर्णाङ्क start_abbrev;
            अचिन्हित वर्ण *ptr;
	    वर्ण *undo;

            /* dwarf_abbrev */
            start_abbrev = dwarf_abbrev_section->data_offset;
            ptr = section_ptr_add(dwarf_abbrev_section, परिमाण(dwarf_abbrev_init));
            स_नकल(ptr, dwarf_abbrev_init, परिमाण(dwarf_abbrev_init));

            यदि (s1->dwarf < 5) {
    	        जबसम्म (*ptr) {
    	            ptr += 3;
    	            जबसम्म (*ptr) {
    	                यदि (ptr[1] == DW_FORM_पङ्क्ति_strp)
    		            ptr[1] = DW_FORM_strp;
		        यदि (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    यदि  (ptr[1] == DW_FORM_sec_offset)
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
            dwarf_sym.पङ्क्ति = dwarf_get_section_sym(dwarf_पङ्क्ति_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            यदि (tcc_state->dwarf >= 5)
    	        dwarf_sym.पङ्क्ति_str = dwarf_get_section_sym(dwarf_पङ्क्ति_str_section);
            अन्यथा {
    	        dwarf_पङ्क्ति_str_section = dwarf_str_section;
                dwarf_sym.पङ्क्ति_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(text_section);

            /* dwarf_info */
            dwarf_info.start = dwarf_info_section->data_offset;
            dwarf_data4(dwarf_info_section, 0); // size
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            यदि (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_SIZE);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_DATA_32DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
            }
            अन्यथा {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_DATA_32DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
                dwarf_data1(dwarf_info_section, PTR_SIZE);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_VERSION);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_पङ्क्ति_strp(dwarf_info_section, filename);
            dwarf_पङ्क्ति_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#यदि PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#अन्यथा
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#endif
            dwarf_reloc(dwarf_info_section, dwarf_sym.पङ्क्ति, R_DATA_32DW);
            dwarf_data4(dwarf_info_section, dwarf_पङ्क्ति_section->data_offset); // stmt_list

            /* dwarf_line */
            dwarf_पङ्क्ति.start = dwarf_पङ्क्ति_section->data_offset;
            dwarf_data4(dwarf_पङ्क्ति_section, 0); // length
            dwarf_data2(dwarf_पङ्क्ति_section, s1->dwarf); // version
            यदि (s1->dwarf >= 5) {
                dwarf_data1(dwarf_पङ्क्ति_section, PTR_SIZE); // address size
                dwarf_data1(dwarf_पङ्क्ति_section, 0); // segment selector
            }
            dwarf_data4(dwarf_पङ्क्ति_section, 0); // prologue Length
            dwarf_data1(dwarf_पङ्क्ति_section, DWARF_MIN_INSTR_LEN);
            यदि (s1->dwarf >= 4)
                dwarf_data1(dwarf_पङ्क्ति_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_पङ्क्ति_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_पङ्क्ति_section, DWARF_पङ्क्ति_BASE);
            dwarf_data1(dwarf_पङ्क्ति_section, DWARF_पङ्क्ति_RANGE);
            dwarf_data1(dwarf_पङ्क्ति_section, DWARF_OPCODE_BASE);
            ptr = section_ptr_add(dwarf_पङ्क्ति_section, परिमाण(dwarf_पङ्क्ति_opcodes));
            स_नकल(ptr, dwarf_पङ्क्ति_opcodes, परिमाण(dwarf_पङ्क्ति_opcodes));
	    undo = म_खोजप(filename, '/');
	    यदि (undo)
		*undo = 0;
            dwarf_पङ्क्ति.dir_size = 1 + (undo != रिक्त);
            dwarf_पङ्क्ति.dir_table = (वर्ण **) tcc_malloc(परिमाण (वर्ण *) *
							dwarf_पङ्क्ति.dir_size);
            dwarf_पङ्क्ति.dir_table[0] = tcc_strdup(buf);
	    यदि (undo)
                dwarf_पङ्क्ति.dir_table[1] = tcc_strdup(filename);
            dwarf_पङ्क्ति.filename_size = 2;
            dwarf_पङ्क्ति.filename_table =
    	        (संरचना dwarf_filename_struct *)
    	        tcc_malloc(2*परिमाण (संरचना dwarf_filename_struct));
            dwarf_पङ्क्ति.filename_table[0].dir_entry = 0;
	    यदि (undo) {
                dwarf_पङ्क्ति.filename_table[0].name = tcc_strdup(undo + 1);
                dwarf_पङ्क्ति.filename_table[1].dir_entry = 1;
                dwarf_पङ्क्ति.filename_table[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    अन्यथा {
                dwarf_पङ्क्ति.filename_table[0].name = tcc_strdup(filename);
                dwarf_पङ्क्ति.filename_table[1].dir_entry = 0;
                dwarf_पङ्क्ति.filename_table[1].name = tcc_strdup(filename);
	    }
            dwarf_पङ्क्ति.पङ्क्ति_size = dwarf_पङ्क्ति.पङ्क्ति_max_size = 0;
            dwarf_पङ्क्ति.पङ्क्ति_data = रिक्त;
            dwarf_पङ्क्ति.cur_file = 1;
            dwarf_पङ्क्ति.last_file = 0;
            dwarf_पङ्क्ति.last_pc = 0;
            dwarf_पङ्क्ति.last_पङ्क्ति = 1;
            dwarf_पङ्क्ति_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_SIZE); // extended size
            dwarf_पङ्क्ति_op(s1, DW_LNE_set_address);
            लागि (i = 0; i < PTR_SIZE; i++)
    	        dwarf_पङ्क्ति_op(s1, 0);
            स_रखो(&dwarf_info.base_type_used, 0, परिमाण(dwarf_info.base_type_used));
        }
        अन्यथा
        {
            /* file info: full path + filename */
            pstrcat(buf, परिमाण(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      text_section->sh_अङ्क, रिक्त);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            लागि (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

स्थिर शून्य fix_debug_forw_hash(TCCState *s1, पूर्णाङ्क global, पूर्णाङ्क start);

/* put end of translation unit info */
ST_FUNC शून्य tcc_debug_end(TCCState *s1)
{

    यदि (!s1->do_debug || debug_next_type == 0)
        फर्काऊ;

    यदि (debug_info_जरा)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    यदि (s1->dwarf) {
	पूर्णाङ्क i;
	पूर्णाङ्क start_aranges;
	अचिन्हित वर्ण *ptr;
	पूर्णाङ्क text_size = text_section->data_offset;

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
#यदि PTR_SIZE == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#अन्यथा
	dwarf_data1(dwarf_aranges_section, 8); // address size
#endif
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_DATA_PTR);
#यदि PTR_SIZE == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, text_size); // End
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#अन्यथा
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, text_size); // End
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#endif
	ptr = dwarf_aranges_section->data + start_aranges;
	write32le(ptr, dwarf_aranges_section->data_offset - start_aranges - 4);

	/* dwarf_line */
	यदि (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_पङ्क्ति_section, 1); /* col */
	    dwarf_uleb128(dwarf_पङ्क्ति_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_पङ्क्ति_section, DW_FORM_पङ्क्ति_strp);
	    dwarf_uleb128(dwarf_पङ्क्ति_section, dwarf_पङ्क्ति.dir_size);
	    लागि (i = 0; i < dwarf_पङ्क्ति.dir_size; i++)
	        dwarf_पङ्क्ति_strp(dwarf_पङ्क्ति_section, dwarf_पङ्क्ति.dir_table[i]);
	    dwarf_data1(dwarf_पङ्क्ति_section, 2); /* col */
	    dwarf_uleb128(dwarf_पङ्क्ति_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_पङ्क्ति_section, DW_FORM_पङ्क्ति_strp);
	    dwarf_uleb128(dwarf_पङ्क्ति_section, DW_LNCT_directory_index);
	    dwarf_uleb128(dwarf_पङ्क्ति_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_पङ्क्ति_section, dwarf_पङ्क्ति.filename_size);
	    लागि (i = 0; i < dwarf_पङ्क्ति.filename_size; i++) {
	        dwarf_पङ्क्ति_strp(dwarf_पङ्क्ति_section,
				dwarf_पङ्क्ति.filename_table[i].name);
	        dwarf_uleb128(dwarf_पङ्क्ति_section,
			      dwarf_पङ्क्ति.filename_table[i].dir_entry);
	    }
	}
	अन्यथा {
	    पूर्णाङ्क len;

	    लागि (i = 0; i < dwarf_पङ्क्ति.dir_size; i++) {
	        len = म_माप(dwarf_पङ्क्ति.dir_table[i]) + 1;
	        ptr = section_ptr_add(dwarf_पङ्क्ति_section, len);
	        स_हटाओ(ptr, dwarf_पङ्क्ति.dir_table[i], len);
	    }
	    dwarf_data1(dwarf_पङ्क्ति_section, 0); /* end dir */
	    लागि (i = 0; i < dwarf_पङ्क्ति.filename_size; i++) {
	        len = म_माप(dwarf_पङ्क्ति.filename_table[i].name) + 1;
	        ptr = section_ptr_add(dwarf_पङ्क्ति_section, len);
	        स_हटाओ(ptr, dwarf_पङ्क्ति.filename_table[i].name, len);
	        dwarf_uleb128(dwarf_पङ्क्ति_section,
			      dwarf_पङ्क्ति.filename_table[i].dir_entry);
	        dwarf_uleb128(dwarf_पङ्क्ति_section, 0); /* time */
	        dwarf_uleb128(dwarf_पङ्क्ति_section, 0); /* size */
	    }
	    dwarf_data1(dwarf_पङ्क्ति_section, 0); /* end file */
	}
	लागि (i = 0; i < dwarf_पङ्क्ति.dir_size; i++)
	    tcc_free(dwarf_पङ्क्ति.dir_table[i]);
	tcc_free(dwarf_पङ्क्ति.dir_table);
	लागि (i = 0; i < dwarf_पङ्क्ति.filename_size; i++)
	    tcc_free(dwarf_पङ्क्ति.filename_table[i].name);
	tcc_free(dwarf_पङ्क्ति.filename_table);

	dwarf_पङ्क्ति_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_पङ्क्ति_op(s1, DW_LNE_end_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_पङ्क्ति_section->data[dwarf_पङ्क्ति.start + 6 + i],
		  dwarf_पङ्क्ति_section->data_offset - dwarf_पङ्क्ति.start - (10 + i));
	section_ptr_add(dwarf_पङ्क्ति_section, 3);
	dwarf_reloc(dwarf_पङ्क्ति_section, section_sym, R_DATA_PTR);
	ptr = section_ptr_add(dwarf_पङ्क्ति_section, dwarf_पङ्क्ति.पङ्क्ति_size - 3);
	स_हटाओ(ptr - 3, dwarf_पङ्क्ति.पङ्क्ति_data, dwarf_पङ्क्ति.पङ्क्ति_size);
	tcc_free(dwarf_पङ्क्ति.पङ्क्ति_data);
	write32le(dwarf_पङ्क्ति_section->data + dwarf_पङ्क्ति.start,
		  dwarf_पङ्क्ति_section->data_offset - dwarf_पङ्क्ति.start - 4);
    }
    अन्यथा
    {
        put_stabs_r(s1, रिक्त, N_SO, 0, 0,
                    text_section->data_offset, text_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_पङ्क्ति_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_next_type = 0;
}

स्थिर BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    यदि (f->filename[0] == ':')
        f = f->prev;
    यदि (f && new_file) {
        new_file = last_पङ्क्ति_अङ्क = 0;
        यदि (s1->dwarf)
            dwarf_file(s1);
        अन्यथा
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, text_section, section_sym);
    }
    फर्काऊ f;
}

/* put alternative filename */
ST_FUNC शून्य tcc_debug_newfile(TCCState *s1)
{
    यदि (!s1->do_debug)
        फर्काऊ;
    यदि (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC शून्य tcc_debug_bincl(TCCState *s1)
{
    यदि (!s1->do_debug)
        फर्काऊ;
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
        फर्काऊ;
    यदि (s1->dwarf)
        dwarf_file(s1);
    अन्यथा
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC शून्य tcc_debug_पङ्क्ति(TCCState *s1)
{
    BufferedFile *f;

    यदि (!s1->do_debug)
        फर्काऊ;
    यदि (cur_text_section != text_section || nocode_wanted)
        फर्काऊ;
    f = put_new_file(s1);
    यदि (!f)
        फर्काऊ;
    यदि (last_पङ्क्ति_अङ्क == f->पङ्क्ति_अङ्क)
        फर्काऊ;
    last_पङ्क्ति_अङ्क = f->पङ्क्ति_अङ्क;

    यदि (s1->dwarf) {
	पूर्णाङ्क len_pc = (ind - dwarf_पङ्क्ति.last_pc) / DWARF_MIN_INSTR_LEN;
	पूर्णाङ्क len_पङ्क्ति = f->पङ्क्ति_अङ्क - dwarf_पङ्क्ति.last_पङ्क्ति;
	पूर्णाङ्क n = len_pc * DWARF_पङ्क्ति_RANGE + len_पङ्क्ति + DWARF_OPCODE_BASE - DWARF_पङ्क्ति_BASE;

	यदि (dwarf_पङ्क्ति.cur_file != dwarf_पङ्क्ति.last_file) {
	    dwarf_पङ्क्ति.last_file = dwarf_पङ्क्ति.cur_file;
	    dwarf_पङ्क्ति_op(s1, DW_LNS_set_file);
	    dwarf_uleb128_op(s1, dwarf_पङ्क्ति.cur_file);
	}
	यदि (len_pc &&
	    len_पङ्क्ति >= DWARF_पङ्क्ति_BASE && len_पङ्क्ति <= (DWARF_OPCODE_BASE + DWARF_पङ्क्ति_BASE) &&
	    n >= DWARF_OPCODE_BASE && n <= 255)
            dwarf_पङ्क्ति_op(s1, n);
	अन्यथा {
	    यदि (len_pc) {
	        n = len_pc * DWARF_पङ्क्ति_RANGE + 0 + DWARF_OPCODE_BASE - DWARF_पङ्क्ति_BASE;
	        यदि (n >= DWARF_OPCODE_BASE && n <= 255)
                    dwarf_पङ्क्ति_op(s1, n);
		अन्यथा {
	            dwarf_पङ्क्ति_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    यदि (len_पङ्क्ति) {
	        n = 0 * DWARF_पङ्क्ति_RANGE + len_पङ्क्ति + DWARF_OPCODE_BASE - DWARF_पङ्क्ति_BASE;
	        यदि (len_पङ्क्ति >= DWARF_पङ्क्ति_BASE && len_पङ्क्ति <= (DWARF_OPCODE_BASE + DWARF_पङ्क्ति_BASE) &&
		    n >= DWARF_OPCODE_BASE && n <= 255)
	            dwarf_पङ्क्ति_op(s1, n);
		अन्यथा {
	            dwarf_पङ्क्ति_op(s1, DW_LNS_advance_पङ्क्ति);
		    dwarf_sleb128_op(s1, len_पङ्क्ति);
                    /* advance by nothing */
	            dwarf_पङ्क्ति_op(s1, DWARF_OPCODE_BASE - DWARF_पङ्क्ति_BASE);
		}
	    }
	}
	dwarf_पङ्क्ति.last_pc = ind;
	dwarf_पङ्क्ति.last_पङ्क्ति = f->पङ्क्ति_अङ्क;
    }
    अन्यथा
    {
	यदि (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->पङ्क्ति_अङ्क, ind - func_ind);
        } अन्यथा {
            /* from tcc_assemble */
            put_stabs_r(s1, रिक्त, N_SLINE, 0, f->पङ्क्ति_अङ्क, ind, text_section, section_sym);
        }
    }
}

स्थिर शून्य tcc_debug_stabs (TCCState *s1, अचर वर्ण *str, पूर्णाङ्क type, अचिन्हित दीर्घ मान,
                             Section *sec, पूर्णाङ्क sym_index, पूर्णाङ्क info)
{
    संरचना debug_sym *s;

    यदि (debug_info) {
        debug_info->sym =
            (संरचना debug_sym *)tcc_realloc (debug_info->sym,
                                             परिमाण(संरचना debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->मान = मान;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_index = sym_index;
        s->info = info;
        s->file = dwarf_पङ्क्ति.cur_file;
        s->पङ्क्ति = file->पङ्क्ति_अङ्क;
    }
    अन्यथा यदि (sec)
        put_stabs_r (s1, str, type, 0, 0, मान, sec, sym_index);
    अन्यथा
        put_stabs (s1, str, type, 0, 0, मान);
}

स्थिर शून्य fix_debug_forw_hash(TCCState *s1, पूर्णाङ्क global, पूर्णाङ्क start)
{
    यदि (s1->dwarf) {
        पूर्णाङ्क i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	संरचना _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	लागि (i = start; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    पूर्णाङ्क pos = dwarf_info_section->data_offset;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_EMPTY_TYPE
                                             : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, रिक्त));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_पङ्क्ति.cur_file);
            dwarf_uleb128(dwarf_info_section, file->पङ्क्ति_अङ्क);
	    लागि (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->data +
			  hash[i].debug_type[j],
			  pos - dwarf_info.start);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC शून्य tcc_debug_stabn(TCCState *s1, पूर्णाङ्क type, पूर्णाङ्क मान)
{
    यदि (!s1->do_debug)
        फर्काऊ;
    यदि (type == N_LBRAC) {
        संरचना _debug_info *info =
            (संरचना _debug_info *) tcc_mallocz(परिमाण (*info));

        info->start = मान;
        info->last_debug_hash = n_debug_hash_local;
        info->last_debug_forw_hash = n_debug_forw_hash_local;
        info->parent = debug_info;
        यदि (debug_info) {
            यदि (debug_info->child) {
                यदि (debug_info->child->last)
                    debug_info->child->last->next = info;
                अन्यथा
                    debug_info->child->next = info;
                debug_info->child->last = info;
            }
            अन्यथा
                debug_info->child = info;
        }
        अन्यथा
            debug_info_जरा = info;
        debug_info = info;
    }
    अन्यथा {
	fix_debug_forw_hash(s1, 0, debug_info->last_debug_forw_hash);
        n_debug_hash_local = debug_info->last_debug_hash;
        n_debug_forw_hash_local = debug_info->last_debug_forw_hash;
        debug_info->end = मान;
        debug_info = debug_info->parent;
    }
}

स्थिर पूर्णाङ्क check_global(Sym *t)
{
    Sym *g = local_थाक;

    जबसम्म (g) {
	यदि (t == g)
	    फर्काऊ 0;
	g = g->prev;
    }
    फर्काऊ 1;
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
	लागि (i = 0; i < *n_forw_hash; i++)
            यदि (t == (*forw_hash)[i].type)
		फर्काऊ 0;
	*forw_hash = (संरचना _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * परिमाण(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = रिक्त;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	फर्काऊ 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    लागि (i = 0; i < n_hash; i++)
        यदि (t == hash[i].type)
	    फर्काऊ hash[i].debug_type;
    फर्काऊ -1;
}

स्थिर पूर्णाङ्क tcc_get_dwarf_info(TCCState *s1, Sym *s);

स्थिर शून्य tcc_debug_check_forw(TCCState *s1, Sym *t, पूर्णाङ्क debug_type)
{
    यदि ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        पूर्णाङ्क i, j, g = check_global(t);
        पूर्णाङ्क n_forw_hash;
        संरचना _debug_forw_hash **forw_hash;

	लागि (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    लागि (j = 0; j < n_forw_hash; j++)
                यदि (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * परिमाण(पूर्णाङ्क));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    फर्काऊ;
                }
	}
    }
}

स्थिर शून्य stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC शून्य tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    यदि (!(s1->do_debug & 2))
	फर्काऊ;
    यदि (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        फर्काऊ;
    }
    यदि ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        पूर्णाङ्क i, j, debug_type, g = check_global(t->ref);
        पूर्णाङ्क *n_forw_hash;
        संरचना _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	लागि (i = 0; i < *n_forw_hash; i++)
	    यदि (t->ref == (*forw_hash)[i].type) {
		यदि (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    लागि (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->data +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.start);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		लागि (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

स्थिर पूर्णाङ्क tcc_debug_add(TCCState *s1, Sym *t, पूर्णाङ्क dwarf)
{
    पूर्णाङ्क offset = dwarf ? dwarf_info_section->data_offset : ++debug_next_type;
    पूर्णाङ्क *n_hash, g = check_global(t);
    संरचना _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (संरचना _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * परिमाण(**hash));
    (*hash)[*n_hash].debug_type = offset;
    (*hash)[(*n_hash)++].type = t;
    फर्काऊ offset;
}

स्थिर पूर्णाङ्क STRUCT_NODEBUG(Sym *s)
{
    फर्काऊ
    (s->a.nodebug ||
     ((s->v & ~SYM_FIELD) >= SYM_FIRST_ANOM &&
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
        फर्काऊ s && !s->r && t->c >= 0;
    यदि (रिक्त == s) {
        /* just use global_stack always */
        s = sym_push2(&global_थाक, SYM_FIELD|0x00DEBBED, 0, ++debug_next_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    यदि (s->r || t->c < 0) /* already defined or still incomplete */
        फर्काऊ 0;
    s->r = 1;
    फर्काऊ 1;
}

स्थिर पूर्णाङ्क remove_type_info(पूर्णाङ्क type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        यदि ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        यदि (!(type & VT_BITFIELD) && (type & VT_STRUCT_MASK) > VT_ENUM)
	    type &= ~VT_STRUCT_MASK;
	फर्काऊ type;
}

स्थिर शून्य tcc_get_debug_info(TCCState *s1, Sym *s, CString *result)
{
    पूर्णाङ्क type;
    पूर्णाङ्क n = 0;
    पूर्णाङ्क debug_type = -1;
    Sym *t = s;
    CString str;

    लागि (;;) {
        type = remove_type_info (t->type.t);
        यदि (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        अन्यथा
            रोक;
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

            जबसम्म (t->next) {
                पूर्णाङ्क pos, size, align;
                t = t->next;
		यदि (STRUCT_NODEBUG(t))
		    जारी;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, रिक्त)
                             );
                tcc_get_debug_info (s1, t, &str);
                यदि (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + BIT_POS(t->type.t);
                    size = BIT_SIZE(t->type.t);
                }
                अन्यथा {
                    pos = t->c * 8;
                    size = type_size(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, size);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, रिक्त, 0, 0);
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
            जबसम्म (t->next) {
                t = t->next;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, रिक्त));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (पूर्णाङ्क)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, रिक्त, 0, 0);
            cstr_free (&str);
	}
    }
    अन्यथा यदि ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        लागि (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            यदि (default_debug[debug_type - 1].type == type)
                रोक;
        यदि (debug_type > N_DEFAULT_DEBUG)
            फर्काऊ;
    }

    यदि (रिक्त == result) /* from stabs_struct_complete() */
        फर्काऊ;

    यदि (n > 0)
        cstr_printf (result, "%d=", ++debug_next_type);
    t = s;
    लागि (;;) {
        type = remove_type_info (t->type.t);
        यदि (type == VT_PTR)
            cstr_printf (result, "%d=*", ++debug_next_type);
        अन्यथा यदि (type == (VT_PTR | VT_ARRAY))
            cstr_printf (result, "%d=ar1;0;%d;",
                         ++debug_next_type, t->type.ref->c - 1);
        अन्यथा यदि (type == VT_FUNC) {
            cstr_printf (result, "%d=f", ++debug_next_type);
            tcc_get_debug_info (s1, t->type.ref, result);
            फर्काऊ;
        }
        अन्यथा
            रोक;
        t = t->type.ref;
    }
    cstr_printf (result, "%d", debug_type);
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
    पूर्णाङ्क last_pos = -1;
    पूर्णाङ्क retval;

    यदि (new_file)
        put_new_file(s1);
    लागि (;;) {
        type = remove_type_info (t->type.t);
        यदि (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        अन्यथा
            रोक;
    }
    यदि ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	यदि (debug_type == -1) {
	    पूर्णाङ्क pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_add(s1, t, 1);
	    e = t;
	    i = 0;
	    जबसम्म (e->next) {
		e = e->next;
		यदि (STRUCT_NODEBUG(e))
		    जारी;
		i++;
	    }
	    pos_type = (पूर्णाङ्क *) tcc_malloc(i * परिमाण(पूर्णाङ्क));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->next ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_EMPTY_TYPE
		        : t->next ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, रिक्त));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_पङ्क्ति.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->पङ्क्ति_अङ्क);
	    यदि (t->next) {
	        pos_sib = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            जबसम्म (e->next) {
                e = e->next;
		यदि (STRUCT_NODEBUG(e))
		    जारी;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, रिक्त));
		dwarf_uleb128(dwarf_info_section, dwarf_पङ्क्ति.cur_file);
		dwarf_uleb128(dwarf_info_section, file->पङ्क्ति_अङ्क);
		pos_type[i++] = dwarf_info_section->data_offset;
		dwarf_data4(dwarf_info_section, 0);
                यदि (e->type.t & VT_BITFIELD) {
                    पूर्णाङ्क pos = e->c * 8 + BIT_POS(e->type.t);
                    पूर्णाङ्क size = BIT_SIZE(e->type.t);

		    dwarf_uleb128(dwarf_info_section, size);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		अन्यथा
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    यदि (t->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + pos_sib,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    e = t;
	    i = 0;
	    जबसम्म (e->next) {
		e = e->next;
		यदि (STRUCT_NODEBUG(e))
		    जारी;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->data + pos_type[i++],
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
	    debug_type = tcc_debug_add(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, रिक्त));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.start);
	    dwarf_uleb128(dwarf_info_section, dwarf_पङ्क्ति.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->पङ्क्ति_अङ्क);
	    pos_sib = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            जबसम्म (e->next) {
                e = e->next;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                           ? "" : get_tok_str(e->v, रिक्त));
		यदि (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		अन्यथा
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + pos_sib,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
    }
    अन्यथा यदि ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        लागि (i = 1; i <= N_DEFAULT_DEBUG; i++)
            यदि (default_debug[i - 1].type == type)
                रोक;
        यदि (i > N_DEFAULT_DEBUG)
            फर्काऊ 0;
	debug_type = dwarf_info.base_type_used[i - 1];
	यदि (debug_type == 0) {
	    वर्ण name[100];

	    debug_type = dwarf_info_section->data_offset;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_BASE_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].size);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, परिमाण name, default_debug[i - 1].name);
	    *म_अक्षर(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.base_type_used[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = रिक्त;
    t = s;
    लागि (;;) {
        type = remove_type_info (t->type.t);
        यदि (type == VT_PTR) {
	    i = dwarf_info_section->data_offset;
	    यदि (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_POINTER);
	    dwarf_data1(dwarf_info_section, PTR_SIZE);
	    यदि (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        अन्यथा यदि (type == (VT_PTR | VT_ARRAY)) {
	    पूर्णाङ्क sib_pos, sub_type;
#यदि LONG_SIZE == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#अन्यथा
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#endif

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->data_offset;
	    यदि (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    यदि (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    लागि (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.start);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		यदि (type != (VT_PTR | VT_ARRAY))
		    रोक;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + sib_pos,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
        अन्यथा यदि (type == VT_FUNC) {
	    पूर्णाङ्क sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->data_offset;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    यदि (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->next ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_EMPTY_TYPE);
	    यदि (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    यदि (t->type.ref->next) {
	        sib_pos = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    जबसम्म (f->next) {
		f = f->next;
		i++;
	    }
	    pos_type = (पूर्णाङ्क *) tcc_malloc(i * परिमाण(पूर्णाङ्क));
	    f = t->type.ref;
	    i = 0;
	    जबसम्म (f->next) {
		f = f->next;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    यदि (t->type.ref->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + sib_pos,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    f = t->type.ref;
	    i = 0;
	    जबसम्म (f->next) {
		f = f->next;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->data + pos_type[i++],
                          type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
        अन्यथा {
	    यदि (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  debug_type - dwarf_info.start);
	    }
            रोक;
	}
        t = t->type.ref;
    }
    फर्काऊ retval;
}

स्थिर शून्य tcc_debug_finish (TCCState *s1, संरचना _debug_info *cur)
{
    जबसम्म (cur) {
        संरचना _debug_info *next = cur->next;
        पूर्णाङ्क i;

        यदि (s1->dwarf) {

            लागि (i = cur->n_sym - 1; i >= 0; i--) {
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
                    dwarf_uleb128(dwarf_info_section, s->पङ्क्ति);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.start);
		यदि (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    यदि (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    यदि (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#यदि PTR_SIZE == 4
                    dwarf_data4(dwarf_info_section, s->मान);
#अन्यथा
                    dwarf_data8(dwarf_info_section, s->मान);
#endif
		}
		अन्यथा {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_size((दीर्घ)s->मान) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (दीर्घ)s->मान);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->child ? DWARF_ABBREV_LEXICAL_BLOCK
			           : DWARF_ABBREV_LEXICAL_EMPTY_BLOCK);
            dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#यदि PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->start);
            dwarf_data4(dwarf_info_section, cur->end - cur->start);
#अन्यथा
            dwarf_data8(dwarf_info_section, func_ind + cur->start);
            dwarf_data8(dwarf_info_section, cur->end - cur->start);
#endif
            tcc_debug_finish (s1, cur->child);
	    यदि (cur->child)
                dwarf_data1(dwarf_info_section, 0);
        }
        अन्यथा
        {
            लागि (i = 0; i < cur->n_sym; i++) {
                संरचना debug_sym *s = &cur->sym[i];

                यदि (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->मान,
                                s->sec, s->sym_index);
                अन्यथा
                    put_stabs(s1, s->str, s->type, 0, 0, s->मान);
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

ST_FUNC शून्य tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    पूर्णाङ्क param;

    यदि (!(s1->do_debug & 2))
        फर्काऊ;

    cstr_new (&debug_str);
    param = !e;
    लागि (; s != e; s = s->prev) {
        यदि (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            जारी;
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
            tcc_debug_stabs(s1, debug_str.data, param ? N_PSYM : N_LSYM,
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
        फर्काऊ;
    debug_info_जरा = रिक्त;
    debug_info = रिक्त;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    यदि (!f)
	फर्काऊ;

    यदि (s1->dwarf) {
        tcc_debug_पङ्क्ति(s1);
        dwarf_info.func = sym;
        dwarf_info.पङ्क्ति = file->पङ्क्ति_अङ्क;
	यदि (s1->do_backtrace) {
	    पूर्णाङ्क i, len;

	    dwarf_पङ्क्ति_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, म_माप(funcname) + 2);
	    dwarf_पङ्क्ति_op(s1, DW_LNE_hi_user - 1);
	    len = म_माप(funcname) + 1;
	    लागि (i = 0; i < len; i++)
		dwarf_पङ्क्ति_op(s1, funcname[i]);
	}
    }
    अन्यथा
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.data, N_FUN, 0, f->पङ्क्ति_अङ्क, 0, cur_text_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_पङ्क्ति(s1);
    }
}

ST_FUNC शून्य tcc_debug_prolog_epilog(TCCState *s1, पूर्णाङ्क मान)
{
    यदि (!s1->do_debug)
        फर्काऊ;
    यदि (s1->dwarf) {
	dwarf_पङ्क्ति_op(s1, मान == 0 ? DW_LNS_set_prologue_end
				     : DW_LNS_set_epilogue_begin);
    }
}

/* put function size */
ST_FUNC शून्य tcc_debug_funcend(TCCState *s1, पूर्णाङ्क size)
{
    /* lldb does not like function end and next function start at same pc */
    पूर्णाङ्क min_instr_len;

#यदि TCC_EH_FRAME
    tcc_debug_frame_end(s1, size);
#endif
    यदि (!s1->do_debug)
        फर्काऊ;
    min_instr_len = dwarf_पङ्क्ति.last_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_पङ्क्ति(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, size);
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
        dwarf_uleb128(dwarf_info_section, dwarf_पङ्क्ति.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.पङ्क्ति);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->data_offset);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.start);
        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#यदि PTR_SIZE == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, size); // high_pc
#अन्यथा
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, size); // high_pc
#endif
        func_sib = dwarf_info_section->data_offset;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#यदि defined(TCC_TARGET_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#अथवायदि defined(TCC_TARGET_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#अथवायदि defined TCC_TARGET_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#अथवायदि defined TCC_TARGET_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#अथवायदि defined TCC_TARGET_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#अन्यथा
        dwarf_data1(dwarf_info_section, DW_OP_call_frame_cfa);
#endif
        tcc_debug_finish (s1, debug_info_जरा);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->data + func_sib,
                  dwarf_info_section->data_offset - dwarf_info.start);
    }
    अन्यथा
    {
        tcc_debug_finish (s1, debug_info_जरा);
    }
    debug_info_जरा = 0;
}


ST_FUNC शून्य tcc_debug_extern_sym(TCCState *s1, Sym *sym, पूर्णाङ्क sh_अङ्क, पूर्णाङ्क sym_bind, पूर्णाङ्क sym_type)
{
    यदि (!(s1->do_debug & 2))
        फर्काऊ;

    यदि (sym_type == STT_FUNC || sym->v >= SYM_FIRST_ANOM)
        फर्काऊ;
    यदि (s1->dwarf) {
        पूर्णाङ्क debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, रिक्त));
	dwarf_uleb128(dwarf_info_section, dwarf_पङ्क्ति.cur_file);
	dwarf_uleb128(dwarf_info_section, file->पङ्क्ति_अङ्क);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	यदि (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->data_offset,
		R_DATA_PTR, 0);
#यदि PTR_SIZE == 4
	dwarf_data4(dwarf_info_section, 0);
#अन्यथा
	dwarf_data8(dwarf_info_section, 0);
#endif
    }
    अन्यथा
    {
        Section *s = sh_अङ्क == SHN_COMMON ? common_section
					  : s1->sections[sh_अङ्क];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, रिक्त),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        यदि (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.data, N_GSYM, 0, रिक्त, 0, 0);
        अन्यथा
            tcc_debug_stabs(s1, str.data,
                (sym->type.t & VT_STATIC) && data_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC शून्य tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    यदि (!(s1->do_debug & 2))
        फर्काऊ;

    यदि (s1->dwarf) {
	पूर्णाङ्क debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	यदि (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, रिक्त));
	    dwarf_uleb128(dwarf_info_section, dwarf_पङ्क्ति.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->पङ्क्ति_अङ्क);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	}
    }
    अन्यथा
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, रिक्त));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.data, N_LSYM, 0, रिक्त, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC शून्य tcc_tcov_block_end(TCCState *s1, पूर्णाङ्क पङ्क्ति);

ST_FUNC शून्य tcc_tcov_block_begin(TCCState *s1)
{
    SValue sv;
    शून्य *ptr;
    अचिन्हित दीर्घ last_offset = tcov_data.offset;

    tcc_tcov_block_end (tcc_state, 0);
    यदि (s1->test_coverage == 0 || nocode_wanted)
	फर्काऊ;

    यदि (tcov_data.last_file_name == 0 ||
	म_भेद ((अचर वर्ण *)(tcov_section->data + tcov_data.last_file_name),
		file->true_filename) != 0) {
	वर्ण wd[1024];
	CString cstr;

	यदि (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	यदि (tcov_data.last_file_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = 0;
	cstr_new (&cstr);
	यदि (file->true_filename[0] == '/') {
	    tcov_data.last_file_name = tcov_section->data_offset;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	अन्यथा {
	    getcwd (wd, परिमाण(wd));
	    tcov_data.last_file_name = tcov_section->data_offset + म_माप(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_add(tcov_section, cstr.size + 1);
	म_नकल((वर्ण *)ptr, cstr.data);
#ifdef _WIN32
        normalize_slashes((वर्ण *)ptr);
#endif
	cstr_free (&cstr);
    }
    यदि (tcov_data.last_func_name == 0 ||
	म_भेद ((अचर वर्ण *)(tcov_section->data + tcov_data.last_func_name),
		funcname) != 0) {
	माप_प्रकार len;

	यदि (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = tcov_section->data_offset;
	len = म_माप (funcname);
	ptr = section_ptr_add(tcov_section, len + 1);
	म_नकल((वर्ण *)ptr, funcname);
	section_ptr_add(tcov_section, -tcov_section->data_offset & 7);
	ptr = section_ptr_add(tcov_section, 8);
	write64le (ptr, file->पङ्क्ति_अङ्क);
    }
    यदि (ind == tcov_data.ind && tcov_data.पङ्क्ति == file->पङ्क्ति_अङ्क)
        tcov_data.offset = last_offset;
    अन्यथा {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_add(tcov_section, 16);
        tcov_data.पङ्क्ति = file->पङ्क्ति_अङ्क;
        write64le (ptr, (tcov_data.पङ्क्ति << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((अचिन्हित वर्ण *)ptr - tcov_section->data) + 8, 0);
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
#endif
        tcov_data.offset = (अचिन्हित वर्ण *)ptr - tcov_section->data;
        tcov_data.ind = ind;
    }
}

ST_FUNC शून्य tcc_tcov_block_end(TCCState *s1, पूर्णाङ्क पङ्क्ति)
{
    यदि (s1->test_coverage == 0)
	फर्काऊ;
    यदि (पङ्क्ति == -1)
        पङ्क्ति = tcov_data.पङ्क्ति;
    यदि (tcov_data.offset) {
	शून्य *ptr = tcov_section->data + tcov_data.offset;
	अचिन्हित दीर्घ दीर्घ nline = पङ्क्ति ? पङ्क्ति : file->पङ्क्ति_अङ्क;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_data.offset = 0;
    }
}

ST_FUNC शून्य tcc_tcov_check_पङ्क्ति(TCCState *s1, पूर्णाङ्क start)
{
    यदि (s1->test_coverage == 0)
	फर्काऊ;
    यदि (tcov_data.पङ्क्ति != file->पङ्क्ति_अङ्क) {
        यदि ((tcov_data.पङ्क्ति + 1) != file->पङ्क्ति_अङ्क) {
	    tcc_tcov_block_end (s1, -1);
	    यदि (start)
                tcc_tcov_block_begin (s1);
	}
	अन्यथा
	    tcov_data.पङ्क्ति = file->पङ्क्ति_अङ्क;
    }
}

ST_FUNC शून्य tcc_tcov_start(TCCState *s1)
{
    यदि (s1->test_coverage == 0)
	फर्काऊ;
    यदि (!s1->dState)
        s1->dState = tcc_mallocz(परिमाण *s1->dState);
    स_रखो (&tcov_data, 0, परिमाण (tcov_data));
    यदि (tcov_section == रिक्त) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_add(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC शून्य tcc_tcov_end(TCCState *s1)
{
    यदि (s1->test_coverage == 0)
	फर्काऊ;
    यदि (tcov_data.last_func_name)
        section_ptr_add(tcov_section, 1);
    यदि (tcov_data.last_file_name)
        section_ptr_add(tcov_section, 1);
}

ST_FUNC शून्य tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_data.ind = 0;
}

/* ------------------------------------------------------------------------- */
#undef last_पङ्क्ति_अङ्क
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
#undef debug_info_जरा
#undef dwarf_sym
#undef dwarf_पङ्क्ति
#undef dwarf_info
#undef dwarf_str
#undef dwarf_पङ्क्ति_str
#undef tcov_data
