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

#include "tcc.h"

/* stab debug support */

static const sa_nracanaa {
  ចំនួនគត់ type;
  ចំនួនគត់ size;
  ចំនួនគត់ encoding;
  const var_na *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#ប្រសិនបើ LONG_SIZE == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#បើមិនដូច្នេះ
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#endif
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#ប្រសិនបើ LONG_SIZE == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#បើមិនដូច្នេះ
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
#បើមិនដូច្នេះ
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
#ប្រសិនបើ LONG_SIZE == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#បើមិនដូច្នេះ
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#endif
};

#define	N_DEFAULT_DEBUG	(parimaa_na (default_debug) / parimaa_na (default_debug[0]))

/* dwarf debug */

#define	DWARF_LINE_BASE				-5
#define	DWARF_LINE_RANGE			14
#define	DWARF_OPCODE_BASE			13

#ប្រសិនបើ defined TCC_TARGET_ARM64
#define	DWARF_MIN_INSTR_LEN			4
#elif defined TCC_TARGET_ARM
#define	DWARF_MIN_INSTR_LEN			2
#បើមិនដូច្នេះ
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
static const unsigned var_na dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_TAG_compile_unit, 1,
          DW_AT_producer, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_line_strp,
          DW_AT_comp_dir, DW_FORM_line_strp,
          DW_AT_low_pc, DW_FORM_addr,
#ប្រសិនបើ PTR_SIZE == 4
          DW_AT_high_pc, DW_FORM_data4,
#បើមិនដូច្នេះ
          DW_AT_high_pc, DW_FORM_data8,
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
          DW_AT_decl_line, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_TAG_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_line, DW_FORM_udata,
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
          DW_AT_decl_line, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_SIGNED, DW_TAG_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_value, DW_FORM_sdata,
          0, 0,
    DWARF_ABBREV_ENUMERATOR_UNSIGNED, DW_TAG_enumerator, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_const_value, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_ENUMERATION_TYPE, DW_TAG_enumeration_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_encoding, DW_FORM_data1,
          DW_AT_byte_size, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_line, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_line, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_data_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_line, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_bit_size, DW_FORM_udata,
          DW_AT_data_bit_offset, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_TAG_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_line, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_EMPTY_TYPE, DW_TAG_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_line, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_TAG_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_line, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_EMPTY_TYPE, DW_TAG_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_line, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_TAG_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_line, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_low_pc, DW_FORM_addr,
#ប្រសិនបើ PTR_SIZE == 4
          DW_AT_high_pc, DW_FORM_data4,
#បើមិនដូច្នេះ
          DW_AT_high_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_TAG_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_line, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_low_pc, DW_FORM_addr,
#ប្រសិនបើ PTR_SIZE == 4
          DW_AT_high_pc, DW_FORM_data4,
#បើមិនដូច្នេះ
          DW_AT_high_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_BLOCK, DW_TAG_lexical_block, 1,
          DW_AT_low_pc, DW_FORM_addr,
#ប្រសិនបើ PTR_SIZE == 4
          DW_AT_high_pc, DW_FORM_data4,
#បើមិនដូច្នេះ
          DW_AT_high_pc, DW_FORM_data8,
#endif
          0, 0,
    DWARF_ABBREV_LEXICAL_EMPTY_BLOCK, DW_TAG_lexical_block, 0,
          DW_AT_low_pc, DW_FORM_addr,
#ប្រសិនបើ PTR_SIZE == 4
          DW_AT_high_pc, DW_FORM_data4,
#បើមិនដូច្នេះ
          DW_AT_high_pc, DW_FORM_data8,
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

static const unsigned var_na dwarf_line_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#define N_STR_HASH (251)

sa_nracanaa dwarf_str_hash {
    ចំនួនគត់ len;
    unsigned long data_offset;
    sa_nracanaa dwarf_str_hash *next;
};

sa_nracanaa _tccdbg {

    ចំនួនគត់ last_line_num, new_file;
    ចំនួនគត់ section_sym;

    ចំនួនគត់ debug_next_type;

    sa_nracanaa _debug_hash {
        ចំនួនគត់ debug_type;
        Sym *type;
    } *debug_hash_global, *debug_hash_local;

    /* store forward structure/unions types */
    sa_nracanaa _debug_forw_hash {
        Sym *type;
        ចំនួនគត់ n_debug_type;
        ចំនួនគត់ *debug_type;
    } *debug_forw_hash_global, *debug_forw_hash_local;

    ចំនួនគត់ n_debug_hash_global;
    ចំនួនគត់ n_debug_hash_local;
    ចំនួនគត់ n_debug_forw_hash_global;
    ចំនួនគត់ n_debug_forw_hash_local;

    sa_nracanaa _debug_info {
        ចំនួនគត់ start;
        ចំនួនគត់ end;
        ចំនួនគត់ last_debug_hash;
        ចំនួនគត់ last_debug_forw_hash;
        ចំនួនគត់ n_sym;
        sa_nracanaa debug_sym {
            ចំនួនគត់ type;
            unsigned long value;
            var_na *str;
            Section *sec;
            ចំនួនគត់ sym_index;
            ចំនួនគត់ info;
            ចំនួនគត់ file;
            ចំនួនគត់ line;
        } *sym;
        sa_nracanaa _debug_info *child, *next, *last, *parent;
    } *debug_info, *debug_info_root;

    sa_nracanaa {
        ចំនួនគត់ info;
        ចំនួនគត់ abbrev;
        ចំនួនគត់ line;
        ចំនួនគត់ str;
        ចំនួនគត់ line_str;
    } dwarf_sym;

    sa_nracanaa {
        ចំនួនគត់ start;
        ចំនួនគត់ dir_size;
        var_na **dir_table;
        ចំនួនគត់ filename_size;
        sa_nracanaa dwarf_filename_struct {
            ចំនួនគត់ dir_entry;
            var_na *name;
        } *filename_table;
        ចំនួនគត់ line_size;
        ចំនួនគត់ line_max_size;
        unsigned var_na *line_data;
        ចំនួនគត់ cur_file;
        ចំនួនគត់ last_file;
        ចំនួនគត់ last_pc;
        ចំនួនគត់ last_line;
    } dwarf_line;

    sa_nracanaa {
        ចំនួនគត់ start;
        Sym *func;
        ចំនួនគត់ line;
        ចំនួនគត់ base_type_used[N_DEFAULT_DEBUG];
    } dwarf_info;

    sa_nracanaa dwarf_str_hash *dwarf_str[N_STR_HASH];
    sa_nracanaa dwarf_str_hash *dwarf_line_str[N_STR_HASH];

    /* test coverage */
    sa_nracanaa {
        unsigned long offset;
        unsigned long last_file_name;
        unsigned long last_func_name;
        ចំនួនគត់ ind;
        ចំនួនគត់ line;
    } tcov_data;
};

#define last_line_num             s1->dState->last_line_num
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
#define debug_info_root           s1->dState->debug_info_root
#define dwarf_sym                 s1->dState->dwarf_sym
#define dwarf_line                s1->dState->dwarf_line
#define dwarf_info                s1->dState->dwarf_info
#define dwarf_str                 s1->dState->dwarf_str
#define dwarf_line_str            s1->dState->dwarf_line_str
#define tcov_data                 s1->dState->tcov_data

#define	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
static ចំនួនគត់ put_stabs(TCCState *s1, const var_na *str, ចំនួនគត់ type, ចំនួនគត់ other,
    ចំនួនគត់ desc, unsigned long value);

ST_FUNC void tcc_debug_new(TCCState *s1)
{
    ចំនួនគត់ shf = 0;
    ប្រសិនបើ (!s1->dState)
        s1->dState = tcc_mallocz(parimaa_na *s1->dState);

#ifdef CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    ប្រសិនបើ (s1->do_debug && s1->output_type == TCC_OUTPUT_MEMORY)
        s1->do_backtrace = 1;
    ប្រសិនបើ (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#endif

    ប្រសិនបើ (s1->dwarf) {
	ចំនួនគត់ i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	static const var_na *const debug[] = {
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
        dwarf_line_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	សម្រាប់ (i = 0; i < parimaa_na(debug)/parimaa_na(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_MERGE | SHF_STRINGS;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_line_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	ប្រសិនបើ (s1->dwarf >= 5) {
            dwarf_line_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_line_str_section->sh_entsize = 1;
	    dwarf_line_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    បើមិនដូច្នេះ
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = parimaa_na(Stab_Sym);
        stab_section->sh_addralign = parimaa_na ((Stab_Sym*)0)->n_value;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
static ចំនួនគត់ put_stabs(TCCState *s1, const var_na *str, ចំនួនគត់ type, ចំនួនគត់ other, ចំនួនគត់ desc,
                      unsigned long value)
{
    Stab_Sym *sym;

    unsigned offset;
    ប្រសិនបើ (type == N_SLINE
        && (offset = stab_section->data_offset)
        && (sym = (Stab_Sym*)(stab_section->data + offset) - 1)
        && sym->n_type == type
        && sym->n_value == value) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        ត្រឡប់ 0;
    }

    sym = section_ptr_add(stab_section, parimaa_na(Stab_Sym));
    ប្រសិនបើ (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } បើមិនដូច្នេះ {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_value = value;
    ត្រឡប់ 1;
}

static void put_stabs_r(TCCState *s1, const var_na *str, ចំនួនគត់ type, ចំនួនគត់ other, ចំនួនគត់ desc,
                        unsigned long value, Section *sec, ចំនួនគត់ sym_index)
{
    ប្រសិនបើ (put_stabs(s1, str, type, other, desc, value))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->data_offset - 4,
                      parimaa_na ((Stab_Sym*)0)->n_value == PTR_SIZE ? R_DATA_PTR : R_DATA_32,
                      sym_index);
}

static void put_stabn(TCCState *s1, ចំនួនគត់ type, ចំនួនគត់ other, ចំនួនគត់ desc, ចំនួនគត់ value)
{
    put_stabs(s1, NULL, type, other, desc, value);
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

static ចំនួនគត់ dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    ត្រឡប់ put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_num, NULL);
}

static void dwarf_reloc(Section *s, ចំនួនគត់ sym, ចំនួនគត់ rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->data_offset, rel, sym, 0);
}

static void free_str(sa_nracanaa dwarf_str_hash **str)
{
    ចំនួនគត់ i;

    សម្រាប់ (i = 0; i < N_STR_HASH; i++) {
       ខណៈពេល (str[i]) {
           sa_nracanaa dwarf_str_hash *next = str[i]->next;

           tcc_free(str[i]);
           str[i] = next;
       }
    }
}

static unsigned str_hash(const var_na *s)
{
    unsigned h = 5381;

    ខណៈពេល (*s)
       h += (*s++ & 0xffu) + h * 31;
    ត្រឡប់ h;
}

static void dwarf_string(Section *s, Section *dw, ចំនួនគត់ sym, const var_na *str)
{
    TCCState *s1 = s->s1;
    ចំនួនគត់ len, hash = str_hash(str) % N_STR_HASH;
    var_na *ptr;
    sa_nracanaa dwarf_str_hash *new_hash;
    sa_nracanaa dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_line_str;

    len = strlen(str) + 1;
    new_hash = dw_hash[hash];
    ខណៈពេល (new_hash) {
	ប្រសិនបើ (new_hash->len == len &&
	    !memcmp(str, dw->data + new_hash->data_offset, len))
	    bha_nga;
	new_hash = new_hash->next;
    }
    ប្រសិនបើ (new_hash == NULL) {
	unsigned long offset = dw->data_offset;

        new_hash = dw_hash[hash];
        ខណៈពេល (new_hash) {
	    unsigned long n = new_hash->data_offset + new_hash->len - len;

	    ប្រសិនបើ (new_hash->len > len &&
	        !memcmp(str, dw->data + n, len)) {
		offset = n;
		bha_nga;
	    }
	    new_hash = new_hash->next;
        }
	ប្រសិនបើ (new_hash == NULL) {
	    ptr = section_ptr_add(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (sa_nracanaa dwarf_str_hash *)
	    tcc_malloc(parimaa_na(sa_nracanaa dwarf_str_hash));
	new_hash->len = len;
	new_hash->data_offset = offset;
	new_hash->next = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->data_offset, R_DATA_32DW, sym,
                   PTR_SIZE == 4 ? 0 : new_hash->data_offset);
    dwarf_data4(s, PTR_SIZE == 4 ? new_hash->data_offset : 0);
}

static void dwarf_strp(Section *s, const var_na *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

static void dwarf_line_strp(Section *s, const var_na *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_line_str_section, dwarf_sym.line_str, str);
}

static void dwarf_line_op(TCCState *s1, unsigned var_na op)
{
    ប្រសិនបើ (dwarf_line.line_size >= dwarf_line.line_max_size) {
	dwarf_line.line_max_size += 1024;
	dwarf_line.line_data =
	    (unsigned var_na *)tcc_realloc(dwarf_line.line_data,
					 dwarf_line.line_max_size);
    }
    dwarf_line.line_data[dwarf_line.line_size++] = op;
}

static void dwarf_file(TCCState *s1)
{
    ចំនួនគត់ i, j;
    var_na *filename;
    ចំនួនគត់ index_offset = s1->dwarf < 5;

    ប្រសិនបើ (!strcmp(file->filename, "<command line>")) {
        dwarf_line.cur_file = 1;
	ត្រឡប់;
    }
    filename = strrchr(file->filename, '/');
    ប្រសិនបើ (filename == NULL) {
        សម្រាប់ (i = 1; i < dwarf_line.filename_size; i++)
            ប្រសិនបើ (dwarf_line.filename_table[i].dir_entry == 0 &&
		strcmp(dwarf_line.filename_table[i].name,
		       file->filename) == 0) {
		    dwarf_line.cur_file = i + index_offset;
	            ត្រឡប់;
		}
	i = -index_offset;
	filename = file->filename;
    }
    បើមិនដូច្នេះ {
	var_na *undo = filename;
	var_na *dir = file->filename;

	*filename++ = '\0';
        សម្រាប់ (i = 0; i < dwarf_line.dir_size; i++)
	    ប្រសិនបើ (strcmp(dwarf_line.dir_table[i], dir) == 0) {
		សម្រាប់ (j = 1; j < dwarf_line.filename_size; j++)
		    ប្រសិនបើ (dwarf_line.filename_table[j].dir_entry - index_offset
			== i &&
			strcmp(dwarf_line.filename_table[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_line.cur_file = j + index_offset;
			ត្រឡប់;
		    }
		bha_nga;
	    }
	ប្រសិនបើ (i == dwarf_line.dir_size) {
	    dwarf_line.dir_size++;
	    dwarf_line.dir_table =
                (var_na **) tcc_realloc(dwarf_line.dir_table,
                                      dwarf_line.dir_size *
                                      parimaa_na (var_na *));
            dwarf_line.dir_table[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_line.filename_table =
        (sa_nracanaa dwarf_filename_struct *)
        tcc_realloc(dwarf_line.filename_table,
                    (dwarf_line.filename_size + 1) *
                    parimaa_na (sa_nracanaa dwarf_filename_struct));
    dwarf_line.filename_table[dwarf_line.filename_size].dir_entry =
	i + index_offset;
    dwarf_line.filename_table[dwarf_line.filename_size].name =
        tcc_strdup(filename);
    dwarf_line.cur_file = dwarf_line.filename_size++ + index_offset;
    ត្រឡប់;
}

#ប្រសិនបើ 0
static ចំនួនគត់ dwarf_uleb128_size (unsigned long long value)
{
    ចំនួនគត់ size =  0;

    do {
        value >>= 7;
        size++;
    } ខណៈពេល (value != 0);
    ត្រឡប់ size;
}
#endif

static ចំនួនគត់ dwarf_sleb128_size (long long value)
{
    ចំនួនគត់ size =  0;
    long long end = value >> 63;
    unsigned var_na last = end & 0x40;
    unsigned var_na byte;

    do {
        byte = value & 0x7f;
        value >>= 7;
        size++;
    } ខណៈពេល (value != end || (byte & 0x40) != last);
    ត្រឡប់ size;
}

static void dwarf_uleb128 (Section *s, unsigned long long value)
{
    do {
        unsigned var_na byte = value & 0x7f;

        value >>= 7;
        dwarf_data1(s, byte | (value ? 0x80 : 0));
    } ខណៈពេល (value != 0);
}

static void dwarf_sleb128 (Section *s, long long value)
{
    ចំនួនគត់ more;
    long long end = value >> 63;
    unsigned var_na last = end & 0x40;

    do {
        unsigned var_na byte = value & 0x7f;

        value >>= 7;
	more = value != end || (byte & 0x40) != last;
        dwarf_data1(s, byte | (0x80 * more));
    } ខណៈពេល (more);
}

static void dwarf_uleb128_op (TCCState *s1, unsigned long long value)
{
    do {
        unsigned var_na byte = value & 0x7f;

        value >>= 7;
        dwarf_line_op(s1, byte | (value ? 0x80 : 0));
    } ខណៈពេល (value != 0);
}

static void dwarf_sleb128_op (TCCState *s1, long long value)
{
    ចំនួនគត់ more;
    long long end = value >> 63;
    unsigned var_na last = end & 0x40;

    do {
        unsigned var_na byte = value & 0x7f;

        value >>= 7;
        more = value != end || (byte & 0x40) != last;
        dwarf_line_op(s1, byte | (0x80 * more));
    } ខណៈពេល (more);
}

#ប្រសិនបើ TCC_EH_FRAME
ST_FUNC void tcc_eh_frame_start(TCCState *s1)
{
    ប្រសិនបើ (!s1->unwind_tables)
        ត្រឡប់;
    eh_frame_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section, 0); // CIE ID
    dwarf_data1(eh_frame_section, 1); // Version
    dwarf_data1(eh_frame_section, 'z'); // Augmentation String
    dwarf_data1(eh_frame_section, 'R');
    dwarf_data1(eh_frame_section, 0);
#ប្រសិនបើ defined TCC_TARGET_I386
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
#elif defined TCC_TARGET_X86_64
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
#elif defined TCC_TARGET_ARM
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
#elif defined TCC_TARGET_ARM64
    dwarf_uleb128(eh_frame_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 30); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 31); // x31 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#elif defined TCC_TARGET_RISCV64
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
    ខណៈពេល ((eh_frame_section->data_offset - s1->eh_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + s1->eh_start, // length
	      eh_frame_section->data_offset - s1->eh_start - 4);
}

static void tcc_debug_frame_end(TCCState *s1, ចំនួនគត់ size)
{
    ចំនួនគត់ eh_section_sym;
    unsigned long fde_start;

    ប្រសិនបើ (!eh_frame_section)
	ត្រឡប់;
    eh_section_sym = dwarf_get_section_sym(text_section);
    fde_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section,
		fde_start - s1->eh_start + 4); // CIE Pointer
#ប្រសិនបើ defined TCC_TARGET_I386
    dwarf_reloc(eh_frame_section, eh_section_sym, R_386_PC32);
#elif defined TCC_TARGET_X86_64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_X86_64_PC32);
#elif defined TCC_TARGET_ARM
    dwarf_reloc(eh_frame_section, eh_section_sym, R_ARM_REL32);
#elif defined TCC_TARGET_ARM64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_AARCH64_PREL32);
#elif defined TCC_TARGET_RISCV64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_RISCV_32_PCREL);
#endif
    dwarf_data4(eh_frame_section, func_ind); // PC Begin
    dwarf_data4(eh_frame_section, size); // PC Range
    dwarf_data1(eh_frame_section, 0); // Augmentation Length
#ប្រសិនបើ defined TCC_TARGET_I386
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
#elif defined TCC_TARGET_X86_64
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
#elif defined TCC_TARGET_ARM
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
#elif defined TCC_TARGET_ARM64
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
#elif defined TCC_TARGET_RISCV64
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
    ខណៈពេល (size >= 4 &&
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
    ខណៈពេល ((eh_frame_section->data_offset - fde_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + fde_start, // length
	      eh_frame_section->data_offset - fde_start - 4);
}

ST_FUNC void tcc_eh_frame_end(TCCState *s1)
{
    ប្រសិនបើ (!eh_frame_section)
	ត្រឡប់;
    dwarf_data4(eh_frame_section, 0);
}

sa_nracanaa eh_search_table {
    uint32_t pc_offset;
    uint32_t fde_offset;
};

static ចំនួនគត់ sort_eh_table(const void *a, const void *b)
{
    uint32_t pc1 = ((const sa_nracanaa eh_search_table *)a)->pc_offset;
    uint32_t pc2 = ((const sa_nracanaa eh_search_table *)b)->pc_offset;

    ត្រឡប់ pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC void tcc_eh_frame_hdr(TCCState *s1, ចំនួនគត់ final)
{
    ចំនួនគត់ count = 0, offset;
    unsigned long count_offset, tab_offset;
    unsigned var_na *ln, *end;
    unsigned ចំនួនគត់ last_cie_offset = 0xffffffff;

    ប្រសិនបើ (!eh_frame_section || !eh_frame_section->data_offset)
	ត្រឡប់;
    ប្រសិនបើ (final && !eh_frame_hdr_section)
	ត្រឡប់;
    ប្រសិនបើ (final == 0)
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
    // Count
    count_offset = eh_frame_hdr_section->data_offset;
    dwarf_data4(eh_frame_hdr_section, 0);
    tab_offset = eh_frame_hdr_section->data_offset;
    ln = eh_frame_section->data;
    end = eh_frame_section->data + eh_frame_section->data_offset;
    ខណៈពេល (ln < end) {
	unsigned var_na *fde = ln, *rd = ln;
	unsigned ចំនួនគត់ cie_offset, version, length = dwarf_read_4(rd, end);
	unsigned ចំនួនគត់ pc_offset, fde_offset;

	ប្រសិនបើ (length == 0)
	    goto next;
        cie_offset = dwarf_read_4(rd, end);
	ប្រសិនបើ (cie_offset == 0)
	    goto next;
	ប្រសិនបើ (cie_offset != last_cie_offset) {
	    unsigned var_na *cie = rd - cie_offset + 4;

	    ប្រសិនបើ (cie < eh_frame_section->data)
		goto next;
	    version = dwarf_read_1(cie, end);
	    ប្រសិនបើ ((version == 1 || version == 3) &&
	        dwarf_read_1(cie, end) == 'z' && // Augmentation String
		dwarf_read_1(cie, end) == 'R' &&
		dwarf_read_1(cie, end) == 0) {
	        dwarf_read_uleb128(&cie, end); // code_alignment_factor
	        dwarf_read_sleb128(&cie, end); // data_alignment_factor
		dwarf_read_1(cie, end); // return address column
		ប្រសិនបើ (dwarf_read_uleb128(&cie, end) == 1 &&
		    dwarf_read_1(cie, end) == FDE_ENCODING) {
		    last_cie_offset = cie_offset;
		}
		បើមិនដូច្នេះ
		    goto next;
	    }
	    បើមិនដូច្នេះ
		goto next;
	}
	count++;
	fde_offset = eh_frame_section->sh_addr +
		     (fde - eh_frame_section->data) -
		     eh_frame_hdr_section->sh_addr;
	pc_offset = dwarf_read_4(rd, end) + fde_offset + 8;
	dwarf_data4(eh_frame_hdr_section, pc_offset);
	dwarf_data4(eh_frame_hdr_section, fde_offset);
next:
	ln += length + 4;
    }
    add32le(eh_frame_hdr_section->data + count_offset, count);
    qsort(eh_frame_hdr_section->data + tab_offset, count,
	  parimaa_na(sa_nracanaa eh_search_table), sort_eh_table);
}
#endif

/* start of translation unit info */
ST_FUNC void tcc_debug_start(TCCState *s1)
{
    ចំនួនគត់ i;
    var_na buf[512];
    var_na *filename;

    /* we might currently #include the <command-line> */
    filename = file->prev ? file->prev->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    ប្រសិនបើ (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, text_section->data_offset, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            text_section->sh_num, "$a");

        new_file = last_line_num = 0;
        debug_next_type = N_DEFAULT_DEBUG;
        debug_hash_global = NULL;
        debug_hash_local = NULL;
        debug_forw_hash_global = NULL;
        debug_forw_hash_local = NULL;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, parimaa_na(buf));
#ifdef _WIN32
        normalize_slashes(buf);
#endif

        ប្រសិនបើ (s1->dwarf) {
            ចំនួនគត់ start_abbrev;
            unsigned var_na *ptr;
	    var_na *undo;

            /* dwarf_abbrev */
            start_abbrev = dwarf_abbrev_section->data_offset;
            ptr = section_ptr_add(dwarf_abbrev_section, parimaa_na(dwarf_abbrev_init));
            memcpy(ptr, dwarf_abbrev_init, parimaa_na(dwarf_abbrev_init));

            ប្រសិនបើ (s1->dwarf < 5) {
    	        ខណៈពេល (*ptr) {
    	            ptr += 3;
    	            ខណៈពេល (*ptr) {
    	                ប្រសិនបើ (ptr[1] == DW_FORM_line_strp)
    		            ptr[1] = DW_FORM_strp;
		        ប្រសិនបើ (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    ប្រសិនបើ  (ptr[1] == DW_FORM_sec_offset)
			         ptr[1] = DW_FORM_data4;
			    /* This code uses only size < 0x80 so these are
			       compatible. */
			    ប្រសិនបើ  (ptr[1] == DW_FORM_exprloc)
			         ptr[1] = DW_FORM_block1;
			}
    	                ptr += 2;
    	            }
		    ptr += 2;
    	        }
            }

            dwarf_sym.info = dwarf_get_section_sym(dwarf_info_section);
            dwarf_sym.abbrev = dwarf_get_section_sym(dwarf_abbrev_section);
            dwarf_sym.line = dwarf_get_section_sym(dwarf_line_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            ប្រសិនបើ (tcc_state->dwarf >= 5)
    	        dwarf_sym.line_str = dwarf_get_section_sym(dwarf_line_str_section);
            បើមិនដូច្នេះ {
    	        dwarf_line_str_section = dwarf_str_section;
                dwarf_sym.line_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(text_section);

            /* dwarf_info */
            dwarf_info.start = dwarf_info_section->data_offset;
            dwarf_data4(dwarf_info_section, 0); // size
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            ប្រសិនបើ (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_SIZE);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_DATA_32DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
            }
            បើមិនដូច្នេះ {
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_DATA_32DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
                dwarf_data1(dwarf_info_section, PTR_SIZE);
            }

            dwarf_data1(dwarf_info_section, DWARF_ABBREV_COMPILE_UNIT);
            dwarf_strp(dwarf_info_section, "tcc " TCC_VERSION);
            dwarf_data1(dwarf_info_section, s1->cversion == 201112 ? DW_LANG_C11 : DW_LANG_C99);
            dwarf_line_strp(dwarf_info_section, filename);
            dwarf_line_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#ប្រសិនបើ PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#បើមិនដូច្នេះ
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#endif
            dwarf_reloc(dwarf_info_section, dwarf_sym.line, R_DATA_32DW);
            dwarf_data4(dwarf_info_section, dwarf_line_section->data_offset); // stmt_list

            /* dwarf_line */
            dwarf_line.start = dwarf_line_section->data_offset;
            dwarf_data4(dwarf_line_section, 0); // length
            dwarf_data2(dwarf_line_section, s1->dwarf); // version
            ប្រសិនបើ (s1->dwarf >= 5) {
                dwarf_data1(dwarf_line_section, PTR_SIZE); // address size
                dwarf_data1(dwarf_line_section, 0); // segment selector
            }
            dwarf_data4(dwarf_line_section, 0); // prologue Length
            dwarf_data1(dwarf_line_section, DWARF_MIN_INSTR_LEN);
            ប្រសិនបើ (s1->dwarf >= 4)
                dwarf_data1(dwarf_line_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_line_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_line_section, DWARF_LINE_BASE);
            dwarf_data1(dwarf_line_section, DWARF_LINE_RANGE);
            dwarf_data1(dwarf_line_section, DWARF_OPCODE_BASE);
            ptr = section_ptr_add(dwarf_line_section, parimaa_na(dwarf_line_opcodes));
            memcpy(ptr, dwarf_line_opcodes, parimaa_na(dwarf_line_opcodes));
	    undo = strrchr(filename, '/');
	    ប្រសិនបើ (undo)
		*undo = 0;
            dwarf_line.dir_size = 1 + (undo != NULL);
            dwarf_line.dir_table = (var_na **) tcc_malloc(parimaa_na (var_na *) *
							dwarf_line.dir_size);
            dwarf_line.dir_table[0] = tcc_strdup(buf);
	    ប្រសិនបើ (undo)
                dwarf_line.dir_table[1] = tcc_strdup(filename);
            dwarf_line.filename_size = 2;
            dwarf_line.filename_table =
    	        (sa_nracanaa dwarf_filename_struct *)
    	        tcc_malloc(2*parimaa_na (sa_nracanaa dwarf_filename_struct));
            dwarf_line.filename_table[0].dir_entry = 0;
	    ប្រសិនបើ (undo) {
                dwarf_line.filename_table[0].name = tcc_strdup(undo + 1);
                dwarf_line.filename_table[1].dir_entry = 1;
                dwarf_line.filename_table[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    បើមិនដូច្នេះ {
                dwarf_line.filename_table[0].name = tcc_strdup(filename);
                dwarf_line.filename_table[1].dir_entry = 0;
                dwarf_line.filename_table[1].name = tcc_strdup(filename);
	    }
            dwarf_line.line_size = dwarf_line.line_max_size = 0;
            dwarf_line.line_data = NULL;
            dwarf_line.cur_file = 1;
            dwarf_line.last_file = 0;
            dwarf_line.last_pc = 0;
            dwarf_line.last_line = 1;
            dwarf_line_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_SIZE); // extended size
            dwarf_line_op(s1, DW_LNE_set_address);
            សម្រាប់ (i = 0; i < PTR_SIZE; i++)
    	        dwarf_line_op(s1, 0);
            memset(&dwarf_info.base_type_used, 0, parimaa_na(dwarf_info.base_type_used));
        }
        បើមិនដូច្នេះ
        {
            /* file info: full path + filename */
            pstrcat(buf, parimaa_na(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      text_section->sh_num, NULL);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            សម្រាប់ (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

static void fix_debug_forw_hash(TCCState *s1, ចំនួនគត់ global, ចំនួនគត់ start);

/* put end of translation unit info */
ST_FUNC void tcc_debug_end(TCCState *s1)
{

    ប្រសិនបើ (!s1->do_debug || debug_next_type == 0)
        ត្រឡប់;

    ប្រសិនបើ (debug_info_root)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    ប្រសិនបើ (s1->dwarf) {
	ចំនួនគត់ i;
	ចំនួនគត់ start_aranges;
	unsigned var_na *ptr;
	ចំនួនគត់ text_size = text_section->data_offset;

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
#ប្រសិនបើ PTR_SIZE == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#បើមិនដូច្នេះ
	dwarf_data1(dwarf_aranges_section, 8); // address size
#endif
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_DATA_PTR);
#ប្រសិនបើ PTR_SIZE == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, text_size); // End
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#បើមិនដូច្នេះ
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, text_size); // End
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#endif
	ptr = dwarf_aranges_section->data + start_aranges;
	write32le(ptr, dwarf_aranges_section->data_offset - start_aranges - 4);

	/* dwarf_line */
	ប្រសិនបើ (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_line_section, 1); /* col */
	    dwarf_uleb128(dwarf_line_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_line_section, DW_FORM_line_strp);
	    dwarf_uleb128(dwarf_line_section, dwarf_line.dir_size);
	    សម្រាប់ (i = 0; i < dwarf_line.dir_size; i++)
	        dwarf_line_strp(dwarf_line_section, dwarf_line.dir_table[i]);
	    dwarf_data1(dwarf_line_section, 2); /* col */
	    dwarf_uleb128(dwarf_line_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_line_section, DW_FORM_line_strp);
	    dwarf_uleb128(dwarf_line_section, DW_LNCT_directory_index);
	    dwarf_uleb128(dwarf_line_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_line_section, dwarf_line.filename_size);
	    សម្រាប់ (i = 0; i < dwarf_line.filename_size; i++) {
	        dwarf_line_strp(dwarf_line_section,
				dwarf_line.filename_table[i].name);
	        dwarf_uleb128(dwarf_line_section,
			      dwarf_line.filename_table[i].dir_entry);
	    }
	}
	បើមិនដូច្នេះ {
	    ចំនួនគត់ len;

	    សម្រាប់ (i = 0; i < dwarf_line.dir_size; i++) {
	        len = strlen(dwarf_line.dir_table[i]) + 1;
	        ptr = section_ptr_add(dwarf_line_section, len);
	        memmove(ptr, dwarf_line.dir_table[i], len);
	    }
	    dwarf_data1(dwarf_line_section, 0); /* end dir */
	    សម្រាប់ (i = 0; i < dwarf_line.filename_size; i++) {
	        len = strlen(dwarf_line.filename_table[i].name) + 1;
	        ptr = section_ptr_add(dwarf_line_section, len);
	        memmove(ptr, dwarf_line.filename_table[i].name, len);
	        dwarf_uleb128(dwarf_line_section,
			      dwarf_line.filename_table[i].dir_entry);
	        dwarf_uleb128(dwarf_line_section, 0); /* time */
	        dwarf_uleb128(dwarf_line_section, 0); /* size */
	    }
	    dwarf_data1(dwarf_line_section, 0); /* end file */
	}
	សម្រាប់ (i = 0; i < dwarf_line.dir_size; i++)
	    tcc_free(dwarf_line.dir_table[i]);
	tcc_free(dwarf_line.dir_table);
	សម្រាប់ (i = 0; i < dwarf_line.filename_size; i++)
	    tcc_free(dwarf_line.filename_table[i].name);
	tcc_free(dwarf_line.filename_table);

	dwarf_line_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_line_op(s1, DW_LNE_end_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_line_section->data[dwarf_line.start + 6 + i],
		  dwarf_line_section->data_offset - dwarf_line.start - (10 + i));
	section_ptr_add(dwarf_line_section, 3);
	dwarf_reloc(dwarf_line_section, section_sym, R_DATA_PTR);
	ptr = section_ptr_add(dwarf_line_section, dwarf_line.line_size - 3);
	memmove(ptr - 3, dwarf_line.line_data, dwarf_line.line_size);
	tcc_free(dwarf_line.line_data);
	write32le(dwarf_line_section->data + dwarf_line.start,
		  dwarf_line_section->data_offset - dwarf_line.start - 4);
    }
    បើមិនដូច្នេះ
    {
        put_stabs_r(s1, NULL, N_SO, 0, 0,
                    text_section->data_offset, text_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_line_str);
    tcc_free (debug_forw_hash_global);
    tcc_free (debug_forw_hash_local);
    tcc_free(debug_hash_global);
    tcc_free(debug_hash_local);
    debug_next_type = 0;
}

static BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    ប្រសិនបើ (f->filename[0] == ':')
        f = f->prev;
    ប្រសិនបើ (f && new_file) {
        new_file = last_line_num = 0;
        ប្រសិនបើ (s1->dwarf)
            dwarf_file(s1);
        បើមិនដូច្នេះ
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, text_section, section_sym);
    }
    ត្រឡប់ f;
}

/* put alternative filename */
ST_FUNC void tcc_debug_newfile(TCCState *s1)
{
    ប្រសិនបើ (!s1->do_debug)
        ត្រឡប់;
    ប្រសិនបើ (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC void tcc_debug_bincl(TCCState *s1)
{
    ប្រសិនបើ (!s1->do_debug)
        ត្រឡប់;
    ប្រសិនបើ (s1->dwarf)
        dwarf_file(s1);
    បើមិនដូច្នេះ
        put_stabs(s1, file->filename, N_BINCL, 0, 0, 0);
    new_file = 1;
}

/* end of #include */
ST_FUNC void tcc_debug_eincl(TCCState *s1)
{
    ប្រសិនបើ (!s1->do_debug)
        ត្រឡប់;
    ប្រសិនបើ (s1->dwarf)
        dwarf_file(s1);
    បើមិនដូច្នេះ
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC void tcc_debug_line(TCCState *s1)
{
    BufferedFile *f;

    ប្រសិនបើ (!s1->do_debug)
        ត្រឡប់;
    ប្រសិនបើ (cur_text_section != text_section || nocode_wanted)
        ត្រឡប់;
    f = put_new_file(s1);
    ប្រសិនបើ (!f)
        ត្រឡប់;
    ប្រសិនបើ (last_line_num == f->line_num)
        ត្រឡប់;
    last_line_num = f->line_num;

    ប្រសិនបើ (s1->dwarf) {
	ចំនួនគត់ len_pc = (ind - dwarf_line.last_pc) / DWARF_MIN_INSTR_LEN;
	ចំនួនគត់ len_line = f->line_num - dwarf_line.last_line;
	ចំនួនគត់ n = len_pc * DWARF_LINE_RANGE + len_line + DWARF_OPCODE_BASE - DWARF_LINE_BASE;

	ប្រសិនបើ (dwarf_line.cur_file != dwarf_line.last_file) {
	    dwarf_line.last_file = dwarf_line.cur_file;
	    dwarf_line_op(s1, DW_LNS_set_file);
	    dwarf_uleb128_op(s1, dwarf_line.cur_file);
	}
	ប្រសិនបើ (len_pc &&
	    len_line >= DWARF_LINE_BASE && len_line <= (DWARF_OPCODE_BASE + DWARF_LINE_BASE) &&
	    n >= DWARF_OPCODE_BASE && n <= 255)
            dwarf_line_op(s1, n);
	បើមិនដូច្នេះ {
	    ប្រសិនបើ (len_pc) {
	        n = len_pc * DWARF_LINE_RANGE + 0 + DWARF_OPCODE_BASE - DWARF_LINE_BASE;
	        ប្រសិនបើ (n >= DWARF_OPCODE_BASE && n <= 255)
                    dwarf_line_op(s1, n);
		បើមិនដូច្នេះ {
	            dwarf_line_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    ប្រសិនបើ (len_line) {
	        n = 0 * DWARF_LINE_RANGE + len_line + DWARF_OPCODE_BASE - DWARF_LINE_BASE;
	        ប្រសិនបើ (len_line >= DWARF_LINE_BASE && len_line <= (DWARF_OPCODE_BASE + DWARF_LINE_BASE) &&
		    n >= DWARF_OPCODE_BASE && n <= 255)
	            dwarf_line_op(s1, n);
		បើមិនដូច្នេះ {
	            dwarf_line_op(s1, DW_LNS_advance_line);
		    dwarf_sleb128_op(s1, len_line);
                    /* advance by nothing */
	            dwarf_line_op(s1, DWARF_OPCODE_BASE - DWARF_LINE_BASE);
		}
	    }
	}
	dwarf_line.last_pc = ind;
	dwarf_line.last_line = f->line_num;
    }
    បើមិនដូច្នេះ
    {
	ប្រសិនបើ (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->line_num, ind - func_ind);
        } បើមិនដូច្នេះ {
            /* from tcc_assemble */
            put_stabs_r(s1, NULL, N_SLINE, 0, f->line_num, ind, text_section, section_sym);
        }
    }
}

static void tcc_debug_stabs (TCCState *s1, const var_na *str, ចំនួនគត់ type, unsigned long value,
                             Section *sec, ចំនួនគត់ sym_index, ចំនួនគត់ info)
{
    sa_nracanaa debug_sym *s;

    ប្រសិនបើ (debug_info) {
        debug_info->sym =
            (sa_nracanaa debug_sym *)tcc_realloc (debug_info->sym,
                                             parimaa_na(sa_nracanaa debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->value = value;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_index = sym_index;
        s->info = info;
        s->file = dwarf_line.cur_file;
        s->line = file->line_num;
    }
    បើមិនដូច្នេះ ប្រសិនបើ (sec)
        put_stabs_r (s1, str, type, 0, 0, value, sec, sym_index);
    បើមិនដូច្នេះ
        put_stabs (s1, str, type, 0, 0, value);
}

static void fix_debug_forw_hash(TCCState *s1, ចំនួនគត់ global, ចំនួនគត់ start)
{
    ប្រសិនបើ (s1->dwarf) {
        ចំនួនគត់ i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	sa_nracanaa _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	សម្រាប់ (i = start; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    ចំនួនគត់ pos = dwarf_info_section->data_offset;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_EMPTY_TYPE
                                             : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, NULL));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_line.cur_file);
            dwarf_uleb128(dwarf_info_section, file->line_num);
	    សម្រាប់ (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->data +
			  hash[i].debug_type[j],
			  pos - dwarf_info.start);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC void tcc_debug_stabn(TCCState *s1, ចំនួនគត់ type, ចំនួនគត់ value)
{
    ប្រសិនបើ (!s1->do_debug)
        ត្រឡប់;
    ប្រសិនបើ (type == N_LBRAC) {
        sa_nracanaa _debug_info *info =
            (sa_nracanaa _debug_info *) tcc_mallocz(parimaa_na (*info));

        info->start = value;
        info->last_debug_hash = n_debug_hash_local;
        info->last_debug_forw_hash = n_debug_forw_hash_local;
        info->parent = debug_info;
        ប្រសិនបើ (debug_info) {
            ប្រសិនបើ (debug_info->child) {
                ប្រសិនបើ (debug_info->child->last)
                    debug_info->child->last->next = info;
                បើមិនដូច្នេះ
                    debug_info->child->next = info;
                debug_info->child->last = info;
            }
            បើមិនដូច្នេះ
                debug_info->child = info;
        }
        បើមិនដូច្នេះ
            debug_info_root = info;
        debug_info = info;
    }
    បើមិនដូច្នេះ {
	fix_debug_forw_hash(s1, 0, debug_info->last_debug_forw_hash);
        n_debug_hash_local = debug_info->last_debug_hash;
        n_debug_forw_hash_local = debug_info->last_debug_forw_hash;
        debug_info->end = value;
        debug_info = debug_info->parent;
    }
}

static ចំនួនគត់ check_global(Sym *t)
{
    Sym *g = local_stack;

    ខណៈពេល (g) {
	ប្រសិនបើ (t == g)
	    ត្រឡប់ 0;
	g = g->prev;
    }
    ត្រឡប់ 1;
}

static ចំនួនគត់ tcc_debug_find(TCCState *s1, Sym *t, ចំនួនគត់ dwarf)
{
    ចំនួនគត់ i , g = check_global(t);
    ចំនួនគត់ n_hash, *n_forw_hash;
    sa_nracanaa _debug_hash *hash;
    sa_nracanaa _debug_forw_hash **forw_hash;

    ប្រសិនបើ ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	សម្រាប់ (i = 0; i < *n_forw_hash; i++)
            ប្រសិនបើ (t == (*forw_hash)[i].type)
		ត្រឡប់ 0;
	*forw_hash = (sa_nracanaa _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * parimaa_na(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = NULL;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	ត្រឡប់ 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    សម្រាប់ (i = 0; i < n_hash; i++)
        ប្រសិនបើ (t == hash[i].type)
	    ត្រឡប់ hash[i].debug_type;
    ត្រឡប់ -1;
}

static ចំនួនគត់ tcc_get_dwarf_info(TCCState *s1, Sym *s);

static void tcc_debug_check_forw(TCCState *s1, Sym *t, ចំនួនគត់ debug_type)
{
    ប្រសិនបើ ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        ចំនួនគត់ i, j, g = check_global(t);
        ចំនួនគត់ n_forw_hash;
        sa_nracanaa _debug_forw_hash **forw_hash;

	សម្រាប់ (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    សម្រាប់ (j = 0; j < n_forw_hash; j++)
                ប្រសិនបើ (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * parimaa_na(ចំនួនគត់));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    ត្រឡប់;
                }
	}
    }
}

static void stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC void tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    ប្រសិនបើ (!(s1->do_debug & 2))
	ត្រឡប់;
    ប្រសិនបើ (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        ត្រឡប់;
    }
    ប្រសិនបើ ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        ចំនួនគត់ i, j, debug_type, g = check_global(t->ref);
        ចំនួនគត់ *n_forw_hash;
        sa_nracanaa _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	សម្រាប់ (i = 0; i < *n_forw_hash; i++)
	    ប្រសិនបើ (t->ref == (*forw_hash)[i].type) {
		ប្រសិនបើ (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    សម្រាប់ (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->data +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.start);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		សម្រាប់ (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

static ចំនួនគត់ tcc_debug_add(TCCState *s1, Sym *t, ចំនួនគត់ dwarf)
{
    ចំនួនគត់ offset = dwarf ? dwarf_info_section->data_offset : ++debug_next_type;
    ចំនួនគត់ *n_hash, g = check_global(t);
    sa_nracanaa _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (sa_nracanaa _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * parimaa_na(**hash));
    (*hash)[*n_hash].debug_type = offset;
    (*hash)[(*n_hash)++].type = t;
    ត្រឡប់ offset;
}

static ចំនួនគត់ STRUCT_NODEBUG(Sym *s)
{
    ត្រឡប់
    (s->a.nodebug ||
     ((s->v & ~SYM_FIELD) >= SYM_FIRST_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

static ចំនួនគត់ stabs_struct_find(TCCState *s1, Sym *t, ចំនួនគត់ *p_id)
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
    ប្រសិនបើ (NULL == p_id)
        ត្រឡប់ s && !s->r && t->c >= 0;
    ប្រសិនបើ (NULL == s) {
        /* just use global_stack always */
        s = sym_push2(&global_stack, SYM_FIELD|0x00DEBBED, 0, ++debug_next_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    ប្រសិនបើ (s->r || t->c < 0) /* already defined or still incomplete */
        ត្រឡប់ 0;
    s->r = 1;
    ត្រឡប់ 1;
}

static ចំនួនគត់ remove_type_info(ចំនួនគត់ type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        ប្រសិនបើ ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        ប្រសិនបើ (!(type & VT_BITFIELD) && (type & VT_STRUCT_MASK) > VT_ENUM)
	    type &= ~VT_STRUCT_MASK;
	ត្រឡប់ type;
}

static void tcc_get_debug_info(TCCState *s1, Sym *s, CString *result)
{
    ចំនួនគត់ type;
    ចំនួនគត់ n = 0;
    ចំនួនគត់ debug_type = -1;
    Sym *t = s;
    CString str;

    សម្រាប់ (;;) {
        type = remove_type_info (t->type.t);
        ប្រសិនបើ (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        បើមិនដូច្នេះ
            bha_nga;
    }
    ប្រសិនបើ ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        ប្រសិនបើ (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, NULL),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            ខណៈពេល (t->next) {
                ចំនួនគត់ pos, size, align;
                t = t->next;
		ប្រសិនបើ (STRUCT_NODEBUG(t))
		    continue;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, NULL)
                             );
                tcc_get_debug_info (s1, t, &str);
                ប្រសិនបើ (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + BIT_POS(t->type.t);
                    size = BIT_SIZE(t->type.t);
                }
                បើមិនដូច្នេះ {
                    pos = t->c * 8;
                    size = type_size(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, size);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, NULL, 0, 0);
            cstr_free (&str);
        }
    }
    បើមិនដូច្នេះ ប្រសិនបើ (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        ប្រសិនបើ (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, NULL),
                         debug_type);
            ខណៈពេល (t->next) {
                t = t->next;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, NULL));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (ចំនួនគត់)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, NULL, 0, 0);
            cstr_free (&str);
	}
    }
    បើមិនដូច្នេះ ប្រសិនបើ ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        សម្រាប់ (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            ប្រសិនបើ (default_debug[debug_type - 1].type == type)
                bha_nga;
        ប្រសិនបើ (debug_type > N_DEFAULT_DEBUG)
            ត្រឡប់;
    }

    ប្រសិនបើ (NULL == result) /* from stabs_struct_complete() */
        ត្រឡប់;

    ប្រសិនបើ (n > 0)
        cstr_printf (result, "%d=", ++debug_next_type);
    t = s;
    សម្រាប់ (;;) {
        type = remove_type_info (t->type.t);
        ប្រសិនបើ (type == VT_PTR)
            cstr_printf (result, "%d=*", ++debug_next_type);
        បើមិនដូច្នេះ ប្រសិនបើ (type == (VT_PTR | VT_ARRAY))
            cstr_printf (result, "%d=ar1;0;%d;",
                         ++debug_next_type, t->type.ref->c - 1);
        បើមិនដូច្នេះ ប្រសិនបើ (type == VT_FUNC) {
            cstr_printf (result, "%d=f", ++debug_next_type);
            tcc_get_debug_info (s1, t->type.ref, result);
            ត្រឡប់;
        }
        បើមិនដូច្នេះ
            bha_nga;
        t = t->type.ref;
    }
    cstr_printf (result, "%d", debug_type);
}

static void stabs_struct_complete(TCCState *s1, CType *t)
{
    ប្រសិនបើ (stabs_struct_find(s1, t->ref, NULL)) {
        Sym s = {0}; s.type = *t;
        tcc_get_debug_info(s1, &s, NULL);
    }
}

static ចំនួនគត់ tcc_get_dwarf_info(TCCState *s1, Sym *s)
{
    ចំនួនគត់ type;
    ចំនួនគត់ debug_type = -1;
    Sym *e, *t = s;
    ចំនួនគត់ i;
    ចំនួនគត់ last_pos = -1;
    ចំនួនគត់ retval;

    ប្រសិនបើ (new_file)
        put_new_file(s1);
    សម្រាប់ (;;) {
        type = remove_type_info (t->type.t);
        ប្រសិនបើ (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        បើមិនដូច្នេះ
            bha_nga;
    }
    ប្រសិនបើ ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	ប្រសិនបើ (debug_type == -1) {
	    ចំនួនគត់ pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_add(s1, t, 1);
	    e = t;
	    i = 0;
	    ខណៈពេល (e->next) {
		e = e->next;
		ប្រសិនបើ (STRUCT_NODEBUG(e))
		    continue;
		i++;
	    }
	    pos_type = (ចំនួនគត់ *) tcc_malloc(i * parimaa_na(ចំនួនគត់));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->next ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_EMPTY_TYPE
		        : t->next ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, NULL));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_line.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->line_num);
	    ប្រសិនបើ (t->next) {
	        pos_sib = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            ខណៈពេល (e->next) {
                e = e->next;
		ប្រសិនបើ (STRUCT_NODEBUG(e))
		    continue;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, NULL));
		dwarf_uleb128(dwarf_info_section, dwarf_line.cur_file);
		dwarf_uleb128(dwarf_info_section, file->line_num);
		pos_type[i++] = dwarf_info_section->data_offset;
		dwarf_data4(dwarf_info_section, 0);
                ប្រសិនបើ (e->type.t & VT_BITFIELD) {
                    ចំនួនគត់ pos = e->c * 8 + BIT_POS(e->type.t);
                    ចំនួនគត់ size = BIT_SIZE(e->type.t);

		    dwarf_uleb128(dwarf_info_section, size);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		បើមិនដូច្នេះ
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    ប្រសិនបើ (t->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + pos_sib,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    e = t;
	    i = 0;
	    ខណៈពេល (e->next) {
		e = e->next;
		ប្រសិនបើ (STRUCT_NODEBUG(e))
		    continue;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->data + pos_type[i++],
			  type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
    }
    បើមិនដូច្នេះ ប្រសិនបើ (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	ប្រសិនបើ (debug_type == -1) {
	    ចំនួនគត់ pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_add(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, NULL));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.start);
	    dwarf_uleb128(dwarf_info_section, dwarf_line.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->line_num);
	    pos_sib = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            ខណៈពេល (e->next) {
                e = e->next;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                           ? "" : get_tok_str(e->v, NULL));
		ប្រសិនបើ (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		បើមិនដូច្នេះ
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + pos_sib,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
    }
    បើមិនដូច្នេះ ប្រសិនបើ ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        សម្រាប់ (i = 1; i <= N_DEFAULT_DEBUG; i++)
            ប្រសិនបើ (default_debug[i - 1].type == type)
                bha_nga;
        ប្រសិនបើ (i > N_DEFAULT_DEBUG)
            ត្រឡប់ 0;
	debug_type = dwarf_info.base_type_used[i - 1];
	ប្រសិនបើ (debug_type == 0) {
	    var_na name[100];

	    debug_type = dwarf_info_section->data_offset;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_BASE_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].size);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, parimaa_na name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.base_type_used[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = NULL;
    t = s;
    សម្រាប់ (;;) {
        type = remove_type_info (t->type.t);
        ប្រសិនបើ (type == VT_PTR) {
	    i = dwarf_info_section->data_offset;
	    ប្រសិនបើ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_POINTER);
	    dwarf_data1(dwarf_info_section, PTR_SIZE);
	    ប្រសិនបើ (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        បើមិនដូច្នេះ ប្រសិនបើ (type == (VT_PTR | VT_ARRAY)) {
	    ចំនួនគត់ sib_pos, sub_type;
#ប្រសិនបើ LONG_SIZE == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#បើមិនដូច្នេះ
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#endif

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->data_offset;
	    ប្រសិនបើ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    ប្រសិនបើ (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    សម្រាប់ (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.start);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		ប្រសិនបើ (type != (VT_PTR | VT_ARRAY))
		    bha_nga;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + sib_pos,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
        បើមិនដូច្នេះ ប្រសិនបើ (type == VT_FUNC) {
	    ចំនួនគត់ sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->data_offset;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    ប្រសិនបើ (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->next ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_EMPTY_TYPE);
	    ប្រសិនបើ (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    ប្រសិនបើ (t->type.ref->next) {
	        sib_pos = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    ខណៈពេល (f->next) {
		f = f->next;
		i++;
	    }
	    pos_type = (ចំនួនគត់ *) tcc_malloc(i * parimaa_na(ចំនួនគត់));
	    f = t->type.ref;
	    i = 0;
	    ខណៈពេល (f->next) {
		f = f->next;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    ប្រសិនបើ (t->type.ref->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + sib_pos,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    f = t->type.ref;
	    i = 0;
	    ខណៈពេល (f->next) {
		f = f->next;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->data + pos_type[i++],
                          type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
        បើមិនដូច្នេះ {
	    ប្រសិនបើ (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  debug_type - dwarf_info.start);
	    }
            bha_nga;
	}
        t = t->type.ref;
    }
    ត្រឡប់ retval;
}

static void tcc_debug_finish (TCCState *s1, sa_nracanaa _debug_info *cur)
{
    ខណៈពេល (cur) {
        sa_nracanaa _debug_info *next = cur->next;
        ចំនួនគត់ i;

        ប្រសិនបើ (s1->dwarf) {

            សម្រាប់ (i = cur->n_sym - 1; i >= 0; i--) {
                sa_nracanaa debug_sym *s = &cur->sym[i];

		dwarf_data1(dwarf_info_section,
                            s->type == N_PSYM
			    ? DWARF_ABBREV_FORMAL_PARAMETER
			    : s->type == N_GSYM
                            ? DWARF_ABBREV_VARIABLE_EXTERNAL
                            : s->type == N_STSYM
			    ? DWARF_ABBREV_VARIABLE_STATIC
			    : DWARF_ABBREV_VARIABLE_LOCAL);
                dwarf_strp(dwarf_info_section, s->str);
		ប្រសិនបើ (s->type == N_GSYM || s->type == N_STSYM) {
                    dwarf_uleb128(dwarf_info_section, s->file);
                    dwarf_uleb128(dwarf_info_section, s->line);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.start);
		ប្រសិនបើ (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    ប្រសិនបើ (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    ប្រសិនបើ (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#ប្រសិនបើ PTR_SIZE == 4
                    dwarf_data4(dwarf_info_section, s->value);
#បើមិនដូច្នេះ
                    dwarf_data8(dwarf_info_section, s->value);
#endif
		}
		បើមិនដូច្នេះ {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_size((long)s->value) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (long)s->value);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->child ? DWARF_ABBREV_LEXICAL_BLOCK
			           : DWARF_ABBREV_LEXICAL_EMPTY_BLOCK);
            dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#ប្រសិនបើ PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->start);
            dwarf_data4(dwarf_info_section, cur->end - cur->start);
#បើមិនដូច្នេះ
            dwarf_data8(dwarf_info_section, func_ind + cur->start);
            dwarf_data8(dwarf_info_section, cur->end - cur->start);
#endif
            tcc_debug_finish (s1, cur->child);
	    ប្រសិនបើ (cur->child)
                dwarf_data1(dwarf_info_section, 0);
        }
        បើមិនដូច្នេះ
        {
            សម្រាប់ (i = 0; i < cur->n_sym; i++) {
                sa_nracanaa debug_sym *s = &cur->sym[i];

                ប្រសិនបើ (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->value,
                                s->sec, s->sym_index);
                បើមិនដូច្នេះ
                    put_stabs(s1, s->str, s->type, 0, 0, s->value);
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

ST_FUNC void tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    ចំនួនគត់ param;

    ប្រសិនបើ (!(s1->do_debug & 2))
        ត្រឡប់;

    cstr_new (&debug_str);
    param = !e;
    សម្រាប់ (; s != e; s = s->prev) {
        ប្រសិនបើ (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            continue;
	ប្រសិនបើ (s1->dwarf) {
	    tcc_debug_stabs(s1, get_tok_str(s->v, NULL),
			    param ? N_PSYM : N_LSYM, s->c, NULL, 0,
			    tcc_get_dwarf_info(s1, s));
	}
	បើមិនដូច្នេះ
        {
            cstr_reset (&debug_str);
            cstr_printf (&debug_str, "%s:%s", get_tok_str(s->v, NULL),
			 param ? "p" : "");
            tcc_get_debug_info(s1, s, &debug_str);
            tcc_debug_stabs(s1, debug_str.data, param ? N_PSYM : N_LSYM,
			    s->c, NULL, 0, 0);
	}
    }
    cstr_free (&debug_str);
}

/* put function symbol */
ST_FUNC void tcc_debug_funcstart(TCCState *s1, Sym *sym)
{
    CString debug_str;
    BufferedFile *f;

    ប្រសិនបើ (!s1->do_debug)
        ត្រឡប់;
    debug_info_root = NULL;
    debug_info = NULL;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    ប្រសិនបើ (!f)
	ត្រឡប់;

    ប្រសិនបើ (s1->dwarf) {
        tcc_debug_line(s1);
        dwarf_info.func = sym;
        dwarf_info.line = file->line_num;
	ប្រសិនបើ (s1->do_backtrace) {
	    ចំនួនគត់ i, len;

	    dwarf_line_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, strlen(funcname) + 2);
	    dwarf_line_op(s1, DW_LNE_hi_user - 1);
	    len = strlen(funcname) + 1;
	    សម្រាប់ (i = 0; i < len; i++)
		dwarf_line_op(s1, funcname[i]);
	}
    }
    បើមិនដូច្នេះ
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.data, N_FUN, 0, f->line_num, 0, cur_text_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_line(s1);
    }
}

ST_FUNC void tcc_debug_prolog_epilog(TCCState *s1, ចំនួនគត់ value)
{
    ប្រសិនបើ (!s1->do_debug)
        ត្រឡប់;
    ប្រសិនបើ (s1->dwarf) {
	dwarf_line_op(s1, value == 0 ? DW_LNS_set_prologue_end
				     : DW_LNS_set_epilogue_begin);
    }
}

/* put function size */
ST_FUNC void tcc_debug_funcend(TCCState *s1, ចំនួនគត់ size)
{
    /* lldb does not like function end and next function start at same pc */
    ចំនួនគត់ min_instr_len;

#ប្រសិនបើ TCC_EH_FRAME
    tcc_debug_frame_end(s1, size);
#endif
    ប្រសិនបើ (!s1->do_debug)
        ត្រឡប់;
    min_instr_len = dwarf_line.last_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_line(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, size);
    ប្រសិនបើ (s1->dwarf) {
        ចំនួនគត់ func_sib = 0;
	Sym *sym = dwarf_info.func;
	ចំនួនគត់ n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        ប្រសិនបើ ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_line.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.line);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->data_offset);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.start);
        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#ប្រសិនបើ PTR_SIZE == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, size); // high_pc
#បើមិនដូច្នេះ
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, size); // high_pc
#endif
        func_sib = dwarf_info_section->data_offset;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#ប្រសិនបើ defined(TCC_TARGET_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#elif defined(TCC_TARGET_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#elif defined TCC_TARGET_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#elif defined TCC_TARGET_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#elif defined TCC_TARGET_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#បើមិនដូច្នេះ
        dwarf_data1(dwarf_info_section, DW_OP_call_frame_cfa);
#endif
        tcc_debug_finish (s1, debug_info_root);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->data + func_sib,
                  dwarf_info_section->data_offset - dwarf_info.start);
    }
    បើមិនដូច្នេះ
    {
        tcc_debug_finish (s1, debug_info_root);
    }
    debug_info_root = 0;
}


ST_FUNC void tcc_debug_extern_sym(TCCState *s1, Sym *sym, ចំនួនគត់ sh_num, ចំនួនគត់ sym_bind, ចំនួនគត់ sym_type)
{
    ប្រសិនបើ (!(s1->do_debug & 2))
        ត្រឡប់;

    ប្រសិនបើ (sym_type == STT_FUNC || sym->v >= SYM_FIRST_ANOM)
        ត្រឡប់;
    ប្រសិនបើ (s1->dwarf) {
        ចំនួនគត់ debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, NULL));
	dwarf_uleb128(dwarf_info_section, dwarf_line.cur_file);
	dwarf_uleb128(dwarf_info_section, file->line_num);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	ប្រសិនបើ (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->data_offset,
		R_DATA_PTR, 0);
#ប្រសិនបើ PTR_SIZE == 4
	dwarf_data4(dwarf_info_section, 0);
#បើមិនដូច្នេះ
	dwarf_data8(dwarf_info_section, 0);
#endif
    }
    បើមិនដូច្នេះ
    {
        Section *s = sh_num == SHN_COMMON ? common_section
					  : s1->sections[sh_num];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, NULL),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        ប្រសិនបើ (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.data, N_GSYM, 0, NULL, 0, 0);
        បើមិនដូច្នេះ
            tcc_debug_stabs(s1, str.data,
                (sym->type.t & VT_STATIC) && data_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC void tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    ប្រសិនបើ (!(s1->do_debug & 2))
        ត្រឡប់;

    ប្រសិនបើ (s1->dwarf) {
	ចំនួនគត់ debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	ប្រសិនបើ (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, NULL));
	    dwarf_uleb128(dwarf_info_section, dwarf_line.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->line_num);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	}
    }
    បើមិនដូច្នេះ
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, NULL));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.data, N_LSYM, 0, NULL, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC void tcc_tcov_block_end(TCCState *s1, ចំនួនគត់ line);

ST_FUNC void tcc_tcov_block_begin(TCCState *s1)
{
    SValue sv;
    void *ptr;
    unsigned long last_offset = tcov_data.offset;

    tcc_tcov_block_end (tcc_state, 0);
    ប្រសិនបើ (s1->test_coverage == 0 || nocode_wanted)
	ត្រឡប់;

    ប្រសិនបើ (tcov_data.last_file_name == 0 ||
	strcmp ((const var_na *)(tcov_section->data + tcov_data.last_file_name),
		file->true_filename) != 0) {
	var_na wd[1024];
	CString cstr;

	ប្រសិនបើ (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	ប្រសិនបើ (tcov_data.last_file_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = 0;
	cstr_new (&cstr);
	ប្រសិនបើ (file->true_filename[0] == '/') {
	    tcov_data.last_file_name = tcov_section->data_offset;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	បើមិនដូច្នេះ {
	    getcwd (wd, parimaa_na(wd));
	    tcov_data.last_file_name = tcov_section->data_offset + strlen(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_add(tcov_section, cstr.size + 1);
	strcpy((var_na *)ptr, cstr.data);
#ifdef _WIN32
        normalize_slashes((var_na *)ptr);
#endif
	cstr_free (&cstr);
    }
    ប្រសិនបើ (tcov_data.last_func_name == 0 ||
	strcmp ((const var_na *)(tcov_section->data + tcov_data.last_func_name),
		funcname) != 0) {
	size_t len;

	ប្រសិនបើ (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = tcov_section->data_offset;
	len = strlen (funcname);
	ptr = section_ptr_add(tcov_section, len + 1);
	strcpy((var_na *)ptr, funcname);
	section_ptr_add(tcov_section, -tcov_section->data_offset & 7);
	ptr = section_ptr_add(tcov_section, 8);
	write64le (ptr, file->line_num);
    }
    ប្រសិនបើ (ind == tcov_data.ind && tcov_data.line == file->line_num)
        tcov_data.offset = last_offset;
    បើមិនដូច្នេះ {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_add(tcov_section, 16);
        tcov_data.line = file->line_num;
        write64le (ptr, (tcov_data.line << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((unsigned var_na *)ptr - tcov_section->data) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#ប្រសិនបើ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || \
    defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || \
    defined TCC_TARGET_RISCV64
        gen_increment_tcov (&sv);
#បើមិនដូច្នេះ
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#endif
        tcov_data.offset = (unsigned var_na *)ptr - tcov_section->data;
        tcov_data.ind = ind;
    }
}

ST_FUNC void tcc_tcov_block_end(TCCState *s1, ចំនួនគត់ line)
{
    ប្រសិនបើ (s1->test_coverage == 0)
	ត្រឡប់;
    ប្រសិនបើ (line == -1)
        line = tcov_data.line;
    ប្រសិនបើ (tcov_data.offset) {
	void *ptr = tcov_section->data + tcov_data.offset;
	unsigned long long nline = line ? line : file->line_num;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_data.offset = 0;
    }
}

ST_FUNC void tcc_tcov_check_line(TCCState *s1, ចំនួនគត់ start)
{
    ប្រសិនបើ (s1->test_coverage == 0)
	ត្រឡប់;
    ប្រសិនបើ (tcov_data.line != file->line_num) {
        ប្រសិនបើ ((tcov_data.line + 1) != file->line_num) {
	    tcc_tcov_block_end (s1, -1);
	    ប្រសិនបើ (start)
                tcc_tcov_block_begin (s1);
	}
	បើមិនដូច្នេះ
	    tcov_data.line = file->line_num;
    }
}

ST_FUNC void tcc_tcov_start(TCCState *s1)
{
    ប្រសិនបើ (s1->test_coverage == 0)
	ត្រឡប់;
    ប្រសិនបើ (!s1->dState)
        s1->dState = tcc_mallocz(parimaa_na *s1->dState);
    memset (&tcov_data, 0, parimaa_na (tcov_data));
    ប្រសិនបើ (tcov_section == NULL) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_add(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC void tcc_tcov_end(TCCState *s1)
{
    ប្រសិនបើ (s1->test_coverage == 0)
	ត្រឡប់;
    ប្រសិនបើ (tcov_data.last_func_name)
        section_ptr_add(tcov_section, 1);
    ប្រសិនបើ (tcov_data.last_file_name)
        section_ptr_add(tcov_section, 1);
}

ST_FUNC void tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_data.ind = 0;
}

/* ------------------------------------------------------------------------- */
#undef last_line_num
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
#undef debug_info_root
#undef dwarf_sym
#undef dwarf_line
#undef dwarf_info
#undef dwarf_str
#undef dwarf_line_str
#undef tcov_data
