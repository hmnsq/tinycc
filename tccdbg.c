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
  صحيح size;
  صحيح encoding;
  ثابت حرف *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#𐤀𐤌 LONG_SIZE == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#وإلا
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#endif
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#𐤀𐤌 LONG_SIZE == 4
    {   VT_LONG | VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "long unsigned int:t5=r5;0;037777777777;" },
#وإلا
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
#وإلا
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
#𐤀𐤌 LONG_SIZE == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#وإلا
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#endif
};

#define	N_DEFAULT_DEBUG	(حجم (default_debug) / حجم (default_debug[0]))

/* dwarf debug */

#define	DWARF_LINE_BASE				-5
#define	DWARF_LINE_RANGE			14
#define	DWARF_OPCODE_BASE			13

#𐤀𐤌 defined TCC_TARGET_ARM64
#define	DWARF_MIN_INSTR_LEN			4
#وإلاإذا defined TCC_TARGET_ARM
#define	DWARF_MIN_INSTR_LEN			2
#وإلا
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
ساكن ثابت unsigned حرف dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_TAG_compile_unit, 1,
          DW_AT_producer, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_line_strp,
          DW_AT_comp_dir, DW_FORM_line_strp,
          DW_AT_low_pc, DW_FORM_addr,
#𐤀𐤌 PTR_SIZE == 4
          DW_AT_high_pc, DW_FORM_data4,
#وإلا
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
#𐤀𐤌 PTR_SIZE == 4
          DW_AT_high_pc, DW_FORM_data4,
#وإلا
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
#𐤀𐤌 PTR_SIZE == 4
          DW_AT_high_pc, DW_FORM_data4,
#وإلا
          DW_AT_high_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_BLOCK, DW_TAG_lexical_block, 1,
          DW_AT_low_pc, DW_FORM_addr,
#𐤀𐤌 PTR_SIZE == 4
          DW_AT_high_pc, DW_FORM_data4,
#وإلا
          DW_AT_high_pc, DW_FORM_data8,
#endif
          0, 0,
    DWARF_ABBREV_LEXICAL_EMPTY_BLOCK, DW_TAG_lexical_block, 0,
          DW_AT_low_pc, DW_FORM_addr,
#𐤀𐤌 PTR_SIZE == 4
          DW_AT_high_pc, DW_FORM_data4,
#وإلا
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

ساكن ثابت unsigned حرف dwarf_line_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#define N_STR_HASH (251)

بنية dwarf_str_hash {
    صحيح len;
    unsigned long data_offset;
    بنية dwarf_str_hash *next;
};

بنية _tccdbg {

    صحيح last_line_num, new_file;
    صحيح section_sym;

    صحيح debug_next_type;

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
        صحيح start;
        صحيح end;
        صحيح last_debug_hash;
        صحيح last_debug_forw_hash;
        صحيح n_sym;
        بنية debug_sym {
            صحيح type;
            unsigned long value;
            حرف *str;
            Section *sec;
            صحيح sym_index;
            صحيح info;
            صحيح file;
            صحيح line;
        } *sym;
        بنية _debug_info *child, *next, *last, *parent;
    } *debug_info, *debug_info_root;

    بنية {
        صحيح info;
        صحيح abbrev;
        صحيح line;
        صحيح str;
        صحيح line_str;
    } dwarf_sym;

    بنية {
        صحيح start;
        صحيح dir_size;
        حرف **dir_table;
        صحيح filename_size;
        بنية dwarf_filename_struct {
            صحيح dir_entry;
            حرف *name;
        } *filename_table;
        صحيح line_size;
        صحيح line_max_size;
        unsigned حرف *line_data;
        صحيح cur_file;
        صحيح last_file;
        صحيح last_pc;
        صحيح last_line;
    } dwarf_line;

    بنية {
        صحيح start;
        Sym *func;
        صحيح line;
        صحيح base_type_used[N_DEFAULT_DEBUG];
    } dwarf_info;

    بنية dwarf_str_hash *dwarf_str[N_STR_HASH];
    بنية dwarf_str_hash *dwarf_line_str[N_STR_HASH];

    /* test coverage */
    بنية {
        unsigned long offset;
        unsigned long last_file_name;
        unsigned long last_func_name;
        صحيح ind;
        صحيح line;
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
ساكن صحيح put_stabs(TCCState *s1, ثابت حرف *str, صحيح type, صحيح other,
    صحيح desc, unsigned long value);

ST_FUNC فراغ tcc_debug_new(TCCState *s1)
{
    صحيح shf = 0;
    𐤀𐤌 (!s1->dState)
        s1->dState = tcc_mallocz(حجم *s1->dState);

#ifdef CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    𐤀𐤌 (s1->do_debug && s1->output_type == TCC_OUTPUT_MEMORY)
        s1->do_backtrace = 1;
    𐤀𐤌 (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#endif

    𐤀𐤌 (s1->dwarf) {
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
        dwarf_line_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	لكل (i = 0; i < حجم(debug)/حجم(debug[0]); i++)
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
	𐤀𐤌 (s1->dwarf >= 5) {
            dwarf_line_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_line_str_section->sh_entsize = 1;
	    dwarf_line_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    وإلا
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = حجم(Stab_Sym);
        stab_section->sh_addralign = حجم ((Stab_Sym*)0)->n_value;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
ساكن صحيح put_stabs(TCCState *s1, ثابت حرف *str, صحيح type, صحيح other, صحيح desc,
                      unsigned long value)
{
    Stab_Sym *sym;

    unsigned offset;
    𐤀𐤌 (type == N_SLINE
        && (offset = stab_section->data_offset)
        && (sym = (Stab_Sym*)(stab_section->data + offset) - 1)
        && sym->n_type == type
        && sym->n_value == value) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        أرجع 0;
    }

    sym = section_ptr_add(stab_section, حجم(Stab_Sym));
    𐤀𐤌 (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } وإلا {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_value = value;
    أرجع 1;
}

ساكن فراغ put_stabs_r(TCCState *s1, ثابت حرف *str, صحيح type, صحيح other, صحيح desc,
                        unsigned long value, Section *sec, صحيح sym_index)
{
    𐤀𐤌 (put_stabs(s1, str, type, other, desc, value))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->data_offset - 4,
                      حجم ((Stab_Sym*)0)->n_value == PTR_SIZE ? R_DATA_PTR : R_DATA_32,
                      sym_index);
}

ساكن فراغ put_stabn(TCCState *s1, صحيح type, صحيح other, صحيح desc, صحيح value)
{
    put_stabs(s1, عدم, type, other, desc, value);
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

ساكن صحيح dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    أرجع put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_num, عدم);
}

ساكن فراغ dwarf_reloc(Section *s, صحيح sym, صحيح rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->data_offset, rel, sym, 0);
}

ساكن فراغ free_str(بنية dwarf_str_hash **str)
{
    صحيح i;

    لكل (i = 0; i < N_STR_HASH; i++) {
       طالما (str[i]) {
           بنية dwarf_str_hash *next = str[i]->next;

           tcc_free(str[i]);
           str[i] = next;
       }
    }
}

ساكن unsigned str_hash(ثابت حرف *s)
{
    unsigned h = 5381;

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
	dw == dwarf_str_section ? dwarf_str : dwarf_line_str;

    len = strlen(str) + 1;
    new_hash = dw_hash[hash];
    طالما (new_hash) {
	𐤀𐤌 (new_hash->len == len &&
	    !memcmp(str, dw->data + new_hash->data_offset, len))
	    اكسر;
	new_hash = new_hash->next;
    }
    𐤀𐤌 (new_hash == عدم) {
	unsigned long offset = dw->data_offset;

        new_hash = dw_hash[hash];
        طالما (new_hash) {
	    unsigned long n = new_hash->data_offset + new_hash->len - len;

	    𐤀𐤌 (new_hash->len > len &&
	        !memcmp(str, dw->data + n, len)) {
		offset = n;
		اكسر;
	    }
	    new_hash = new_hash->next;
        }
	𐤀𐤌 (new_hash == عدم) {
	    ptr = section_ptr_add(dw, len);
	    memmove(ptr, str, len);
	}
	new_hash = (بنية dwarf_str_hash *)
	    tcc_malloc(حجم(بنية dwarf_str_hash));
	new_hash->len = len;
	new_hash->data_offset = offset;
	new_hash->next = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->data_offset, R_DATA_32DW, sym,
                   PTR_SIZE == 4 ? 0 : new_hash->data_offset);
    dwarf_data4(s, PTR_SIZE == 4 ? new_hash->data_offset : 0);
}

ساكن فراغ dwarf_strp(Section *s, ثابت حرف *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

ساكن فراغ dwarf_line_strp(Section *s, ثابت حرف *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_line_str_section, dwarf_sym.line_str, str);
}

ساكن فراغ dwarf_line_op(TCCState *s1, unsigned حرف op)
{
    𐤀𐤌 (dwarf_line.line_size >= dwarf_line.line_max_size) {
	dwarf_line.line_max_size += 1024;
	dwarf_line.line_data =
	    (unsigned حرف *)tcc_realloc(dwarf_line.line_data,
					 dwarf_line.line_max_size);
    }
    dwarf_line.line_data[dwarf_line.line_size++] = op;
}

ساكن فراغ dwarf_file(TCCState *s1)
{
    صحيح i, j;
    حرف *filename;
    صحيح index_offset = s1->dwarf < 5;

    𐤀𐤌 (!strcmp(file->filename, "<command line>")) {
        dwarf_line.cur_file = 1;
	أرجع;
    }
    filename = strrchr(file->filename, '/');
    𐤀𐤌 (filename == عدم) {
        لكل (i = 1; i < dwarf_line.filename_size; i++)
            𐤀𐤌 (dwarf_line.filename_table[i].dir_entry == 0 &&
		strcmp(dwarf_line.filename_table[i].name,
		       file->filename) == 0) {
		    dwarf_line.cur_file = i + index_offset;
	            أرجع;
		}
	i = -index_offset;
	filename = file->filename;
    }
    وإلا {
	حرف *undo = filename;
	حرف *dir = file->filename;

	*filename++ = '\0';
        لكل (i = 0; i < dwarf_line.dir_size; i++)
	    𐤀𐤌 (strcmp(dwarf_line.dir_table[i], dir) == 0) {
		لكل (j = 1; j < dwarf_line.filename_size; j++)
		    𐤀𐤌 (dwarf_line.filename_table[j].dir_entry - index_offset
			== i &&
			strcmp(dwarf_line.filename_table[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_line.cur_file = j + index_offset;
			أرجع;
		    }
		اكسر;
	    }
	𐤀𐤌 (i == dwarf_line.dir_size) {
	    dwarf_line.dir_size++;
	    dwarf_line.dir_table =
                (حرف **) tcc_realloc(dwarf_line.dir_table,
                                      dwarf_line.dir_size *
                                      حجم (حرف *));
            dwarf_line.dir_table[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_line.filename_table =
        (بنية dwarf_filename_struct *)
        tcc_realloc(dwarf_line.filename_table,
                    (dwarf_line.filename_size + 1) *
                    حجم (بنية dwarf_filename_struct));
    dwarf_line.filename_table[dwarf_line.filename_size].dir_entry =
	i + index_offset;
    dwarf_line.filename_table[dwarf_line.filename_size].name =
        tcc_strdup(filename);
    dwarf_line.cur_file = dwarf_line.filename_size++ + index_offset;
    أرجع;
}

#𐤀𐤌 0
ساكن صحيح dwarf_uleb128_size (unsigned long long value)
{
    صحيح size =  0;

    𐤐𐤏𐤋 {
        value >>= 7;
        size++;
    } طالما (value != 0);
    أرجع size;
}
#endif

ساكن صحيح dwarf_sleb128_size (long long value)
{
    صحيح size =  0;
    long long end = value >> 63;
    unsigned حرف last = end & 0x40;
    unsigned حرف byte;

    𐤐𐤏𐤋 {
        byte = value & 0x7f;
        value >>= 7;
        size++;
    } طالما (value != end || (byte & 0x40) != last);
    أرجع size;
}

ساكن فراغ dwarf_uleb128 (Section *s, unsigned long long value)
{
    𐤐𐤏𐤋 {
        unsigned حرف byte = value & 0x7f;

        value >>= 7;
        dwarf_data1(s, byte | (value ? 0x80 : 0));
    } طالما (value != 0);
}

ساكن فراغ dwarf_sleb128 (Section *s, long long value)
{
    صحيح more;
    long long end = value >> 63;
    unsigned حرف last = end & 0x40;

    𐤐𐤏𐤋 {
        unsigned حرف byte = value & 0x7f;

        value >>= 7;
	more = value != end || (byte & 0x40) != last;
        dwarf_data1(s, byte | (0x80 * more));
    } طالما (more);
}

ساكن فراغ dwarf_uleb128_op (TCCState *s1, unsigned long long value)
{
    𐤐𐤏𐤋 {
        unsigned حرف byte = value & 0x7f;

        value >>= 7;
        dwarf_line_op(s1, byte | (value ? 0x80 : 0));
    } طالما (value != 0);
}

ساكن فراغ dwarf_sleb128_op (TCCState *s1, long long value)
{
    صحيح more;
    long long end = value >> 63;
    unsigned حرف last = end & 0x40;

    𐤐𐤏𐤋 {
        unsigned حرف byte = value & 0x7f;

        value >>= 7;
        more = value != end || (byte & 0x40) != last;
        dwarf_line_op(s1, byte | (0x80 * more));
    } طالما (more);
}

#𐤀𐤌 TCC_EH_FRAME
ST_FUNC فراغ tcc_eh_frame_start(TCCState *s1)
{
    𐤀𐤌 (!s1->unwind_tables)
        أرجع;
    eh_frame_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section, 0); // CIE ID
    dwarf_data1(eh_frame_section, 1); // Version
    dwarf_data1(eh_frame_section, 'z'); // Augmentation String
    dwarf_data1(eh_frame_section, 'R');
    dwarf_data1(eh_frame_section, 0);
#𐤀𐤌 defined TCC_TARGET_I386
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
#وإلاإذا defined TCC_TARGET_X86_64
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
#وإلاإذا defined TCC_TARGET_ARM
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
#وإلاإذا defined TCC_TARGET_ARM64
    dwarf_uleb128(eh_frame_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 30); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 31); // x31 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#وإلاإذا defined TCC_TARGET_RISCV64
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
    طالما ((eh_frame_section->data_offset - s1->eh_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + s1->eh_start, // length
	      eh_frame_section->data_offset - s1->eh_start - 4);
}

ساكن فراغ tcc_debug_frame_end(TCCState *s1, صحيح size)
{
    صحيح eh_section_sym;
    unsigned long fde_start;

    𐤀𐤌 (!eh_frame_section)
	أرجع;
    eh_section_sym = dwarf_get_section_sym(text_section);
    fde_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section,
		fde_start - s1->eh_start + 4); // CIE Pointer
#𐤀𐤌 defined TCC_TARGET_I386
    dwarf_reloc(eh_frame_section, eh_section_sym, R_386_PC32);
#وإلاإذا defined TCC_TARGET_X86_64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_X86_64_PC32);
#وإلاإذا defined TCC_TARGET_ARM
    dwarf_reloc(eh_frame_section, eh_section_sym, R_ARM_REL32);
#وإلاإذا defined TCC_TARGET_ARM64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_AARCH64_PREL32);
#وإلاإذا defined TCC_TARGET_RISCV64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_RISCV_32_PCREL);
#endif
    dwarf_data4(eh_frame_section, func_ind); // PC Begin
    dwarf_data4(eh_frame_section, size); // PC Range
    dwarf_data1(eh_frame_section, 0); // Augmentation Length
#𐤀𐤌 defined TCC_TARGET_I386
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
#وإلاإذا defined TCC_TARGET_X86_64
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
#وإلاإذا defined TCC_TARGET_ARM
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
#وإلاإذا defined TCC_TARGET_ARM64
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
#وإلاإذا defined TCC_TARGET_RISCV64
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
    طالما (size >= 4 &&
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
    طالما ((eh_frame_section->data_offset - fde_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + fde_start, // length
	      eh_frame_section->data_offset - fde_start - 4);
}

ST_FUNC فراغ tcc_eh_frame_end(TCCState *s1)
{
    𐤀𐤌 (!eh_frame_section)
	أرجع;
    dwarf_data4(eh_frame_section, 0);
}

بنية eh_search_table {
    uint32_t pc_offset;
    uint32_t fde_offset;
};

ساكن صحيح sort_eh_table(ثابت فراغ *a, ثابت فراغ *b)
{
    uint32_t pc1 = ((ثابت بنية eh_search_table *)a)->pc_offset;
    uint32_t pc2 = ((ثابت بنية eh_search_table *)b)->pc_offset;

    أرجع pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC فراغ tcc_eh_frame_hdr(TCCState *s1, صحيح final)
{
    صحيح count = 0, offset;
    unsigned long count_offset, tab_offset;
    unsigned حرف *ln, *end;
    unsigned صحيح last_cie_offset = 0xffffffff;

    𐤀𐤌 (!eh_frame_section || !eh_frame_section->data_offset)
	أرجع;
    𐤀𐤌 (final && !eh_frame_hdr_section)
	أرجع;
    𐤀𐤌 (final == 0)
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
    طالما (ln < end) {
	unsigned حرف *fde = ln, *rd = ln;
	unsigned صحيح cie_offset, version, length = dwarf_read_4(rd, end);
	unsigned صحيح pc_offset, fde_offset;

	𐤀𐤌 (length == 0)
	    اذهب next;
        cie_offset = dwarf_read_4(rd, end);
	𐤀𐤌 (cie_offset == 0)
	    اذهب next;
	𐤀𐤌 (cie_offset != last_cie_offset) {
	    unsigned حرف *cie = rd - cie_offset + 4;

	    𐤀𐤌 (cie < eh_frame_section->data)
		اذهب next;
	    version = dwarf_read_1(cie, end);
	    𐤀𐤌 ((version == 1 || version == 3) &&
	        dwarf_read_1(cie, end) == 'z' && // Augmentation String
		dwarf_read_1(cie, end) == 'R' &&
		dwarf_read_1(cie, end) == 0) {
	        dwarf_read_uleb128(&cie, end); // code_alignment_factor
	        dwarf_read_sleb128(&cie, end); // data_alignment_factor
		dwarf_read_1(cie, end); // return address column
		𐤀𐤌 (dwarf_read_uleb128(&cie, end) == 1 &&
		    dwarf_read_1(cie, end) == FDE_ENCODING) {
		    last_cie_offset = cie_offset;
		}
		وإلا
		    اذهب next;
	    }
	    وإلا
		اذهب next;
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
	  حجم(بنية eh_search_table), sort_eh_table);
}
#endif

/* start of translation unit info */
ST_FUNC فراغ tcc_debug_start(TCCState *s1)
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

    𐤀𐤌 (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, text_section->data_offset, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            text_section->sh_num, "$a");

        new_file = last_line_num = 0;
        debug_next_type = N_DEFAULT_DEBUG;
        debug_hash_global = عدم;
        debug_hash_local = عدم;
        debug_forw_hash_global = عدم;
        debug_forw_hash_local = عدم;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, حجم(buf));
#ifdef _WIN32
        normalize_slashes(buf);
#endif

        𐤀𐤌 (s1->dwarf) {
            صحيح start_abbrev;
            unsigned حرف *ptr;
	    حرف *undo;

            /* dwarf_abbrev */
            start_abbrev = dwarf_abbrev_section->data_offset;
            ptr = section_ptr_add(dwarf_abbrev_section, حجم(dwarf_abbrev_init));
            memcpy(ptr, dwarf_abbrev_init, حجم(dwarf_abbrev_init));

            𐤀𐤌 (s1->dwarf < 5) {
    	        طالما (*ptr) {
    	            ptr += 3;
    	            طالما (*ptr) {
    	                𐤀𐤌 (ptr[1] == DW_FORM_line_strp)
    		            ptr[1] = DW_FORM_strp;
		        𐤀𐤌 (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    𐤀𐤌  (ptr[1] == DW_FORM_sec_offset)
			         ptr[1] = DW_FORM_data4;
			    /* This code uses only size < 0x80 so these are
			       compatible. */
			    𐤀𐤌  (ptr[1] == DW_FORM_exprloc)
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
            𐤀𐤌 (tcc_state->dwarf >= 5)
    	        dwarf_sym.line_str = dwarf_get_section_sym(dwarf_line_str_section);
            وإلا {
    	        dwarf_line_str_section = dwarf_str_section;
                dwarf_sym.line_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(text_section);

            /* dwarf_info */
            dwarf_info.start = dwarf_info_section->data_offset;
            dwarf_data4(dwarf_info_section, 0); // size
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            𐤀𐤌 (s1->dwarf >= 5) {
                dwarf_data1(dwarf_info_section, DW_UT_compile); // unit type
                dwarf_data1(dwarf_info_section, PTR_SIZE);
                dwarf_reloc(dwarf_info_section, dwarf_sym.abbrev, R_DATA_32DW);
                dwarf_data4(dwarf_info_section, start_abbrev);
            }
            وإلا {
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
#𐤀𐤌 PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#وإلا
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#endif
            dwarf_reloc(dwarf_info_section, dwarf_sym.line, R_DATA_32DW);
            dwarf_data4(dwarf_info_section, dwarf_line_section->data_offset); // stmt_list

            /* dwarf_line */
            dwarf_line.start = dwarf_line_section->data_offset;
            dwarf_data4(dwarf_line_section, 0); // length
            dwarf_data2(dwarf_line_section, s1->dwarf); // version
            𐤀𐤌 (s1->dwarf >= 5) {
                dwarf_data1(dwarf_line_section, PTR_SIZE); // address size
                dwarf_data1(dwarf_line_section, 0); // segment selector
            }
            dwarf_data4(dwarf_line_section, 0); // prologue Length
            dwarf_data1(dwarf_line_section, DWARF_MIN_INSTR_LEN);
            𐤀𐤌 (s1->dwarf >= 4)
                dwarf_data1(dwarf_line_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_line_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_line_section, DWARF_LINE_BASE);
            dwarf_data1(dwarf_line_section, DWARF_LINE_RANGE);
            dwarf_data1(dwarf_line_section, DWARF_OPCODE_BASE);
            ptr = section_ptr_add(dwarf_line_section, حجم(dwarf_line_opcodes));
            memcpy(ptr, dwarf_line_opcodes, حجم(dwarf_line_opcodes));
	    undo = strrchr(filename, '/');
	    𐤀𐤌 (undo)
		*undo = 0;
            dwarf_line.dir_size = 1 + (undo != عدم);
            dwarf_line.dir_table = (حرف **) tcc_malloc(حجم (حرف *) *
							dwarf_line.dir_size);
            dwarf_line.dir_table[0] = tcc_strdup(buf);
	    𐤀𐤌 (undo)
                dwarf_line.dir_table[1] = tcc_strdup(filename);
            dwarf_line.filename_size = 2;
            dwarf_line.filename_table =
    	        (بنية dwarf_filename_struct *)
    	        tcc_malloc(2*حجم (بنية dwarf_filename_struct));
            dwarf_line.filename_table[0].dir_entry = 0;
	    𐤀𐤌 (undo) {
                dwarf_line.filename_table[0].name = tcc_strdup(undo + 1);
                dwarf_line.filename_table[1].dir_entry = 1;
                dwarf_line.filename_table[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    وإلا {
                dwarf_line.filename_table[0].name = tcc_strdup(filename);
                dwarf_line.filename_table[1].dir_entry = 0;
                dwarf_line.filename_table[1].name = tcc_strdup(filename);
	    }
            dwarf_line.line_size = dwarf_line.line_max_size = 0;
            dwarf_line.line_data = عدم;
            dwarf_line.cur_file = 1;
            dwarf_line.last_file = 0;
            dwarf_line.last_pc = 0;
            dwarf_line.last_line = 1;
            dwarf_line_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_SIZE); // extended size
            dwarf_line_op(s1, DW_LNE_set_address);
            لكل (i = 0; i < PTR_SIZE; i++)
    	        dwarf_line_op(s1, 0);
            memset(&dwarf_info.base_type_used, 0, حجم(dwarf_info.base_type_used));
        }
        وإلا
        {
            /* file info: full path + filename */
            pstrcat(buf, حجم(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      text_section->sh_num, عدم);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            لكل (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

ساكن فراغ fix_debug_forw_hash(TCCState *s1, صحيح global, صحيح start);

/* put end of translation unit info */
ST_FUNC فراغ tcc_debug_end(TCCState *s1)
{

    𐤀𐤌 (!s1->do_debug || debug_next_type == 0)
        أرجع;

    𐤀𐤌 (debug_info_root)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    𐤀𐤌 (s1->dwarf) {
	صحيح i;
	صحيح start_aranges;
	unsigned حرف *ptr;
	صحيح text_size = text_section->data_offset;

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
#𐤀𐤌 PTR_SIZE == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#وإلا
	dwarf_data1(dwarf_aranges_section, 8); // address size
#endif
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_DATA_PTR);
#𐤀𐤌 PTR_SIZE == 4
	dwarf_data4(dwarf_aranges_section, 0); // Begin
	dwarf_data4(dwarf_aranges_section, text_size); // End
	dwarf_data4(dwarf_aranges_section, 0); // End list
	dwarf_data4(dwarf_aranges_section, 0); // End list
#وإلا
	dwarf_data8(dwarf_aranges_section, 0); // Begin
	dwarf_data8(dwarf_aranges_section, text_size); // End
	dwarf_data8(dwarf_aranges_section, 0); // End list
	dwarf_data8(dwarf_aranges_section, 0); // End list
#endif
	ptr = dwarf_aranges_section->data + start_aranges;
	write32le(ptr, dwarf_aranges_section->data_offset - start_aranges - 4);

	/* dwarf_line */
	𐤀𐤌 (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_line_section, 1); /* col */
	    dwarf_uleb128(dwarf_line_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_line_section, DW_FORM_line_strp);
	    dwarf_uleb128(dwarf_line_section, dwarf_line.dir_size);
	    لكل (i = 0; i < dwarf_line.dir_size; i++)
	        dwarf_line_strp(dwarf_line_section, dwarf_line.dir_table[i]);
	    dwarf_data1(dwarf_line_section, 2); /* col */
	    dwarf_uleb128(dwarf_line_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_line_section, DW_FORM_line_strp);
	    dwarf_uleb128(dwarf_line_section, DW_LNCT_directory_index);
	    dwarf_uleb128(dwarf_line_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_line_section, dwarf_line.filename_size);
	    لكل (i = 0; i < dwarf_line.filename_size; i++) {
	        dwarf_line_strp(dwarf_line_section,
				dwarf_line.filename_table[i].name);
	        dwarf_uleb128(dwarf_line_section,
			      dwarf_line.filename_table[i].dir_entry);
	    }
	}
	وإلا {
	    صحيح len;

	    لكل (i = 0; i < dwarf_line.dir_size; i++) {
	        len = strlen(dwarf_line.dir_table[i]) + 1;
	        ptr = section_ptr_add(dwarf_line_section, len);
	        memmove(ptr, dwarf_line.dir_table[i], len);
	    }
	    dwarf_data1(dwarf_line_section, 0); /* end dir */
	    لكل (i = 0; i < dwarf_line.filename_size; i++) {
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
	لكل (i = 0; i < dwarf_line.dir_size; i++)
	    tcc_free(dwarf_line.dir_table[i]);
	tcc_free(dwarf_line.dir_table);
	لكل (i = 0; i < dwarf_line.filename_size; i++)
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
    وإلا
    {
        put_stabs_r(s1, عدم, N_SO, 0, 0,
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

ساكن BufferedFile* put_new_file(TCCState *s1)
{
    BufferedFile *f = file;
    /* use upper file if from inline ":asm:" */
    𐤀𐤌 (f->filename[0] == ':')
        f = f->prev;
    𐤀𐤌 (f && new_file) {
        new_file = last_line_num = 0;
        𐤀𐤌 (s1->dwarf)
            dwarf_file(s1);
        وإلا
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, text_section, section_sym);
    }
    أرجع f;
}

/* put alternative filename */
ST_FUNC فراغ tcc_debug_newfile(TCCState *s1)
{
    𐤀𐤌 (!s1->do_debug)
        أرجع;
    𐤀𐤌 (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC فراغ tcc_debug_bincl(TCCState *s1)
{
    𐤀𐤌 (!s1->do_debug)
        أرجع;
    𐤀𐤌 (s1->dwarf)
        dwarf_file(s1);
    وإلا
        put_stabs(s1, file->filename, N_BINCL, 0, 0, 0);
    new_file = 1;
}

/* end of #include */
ST_FUNC فراغ tcc_debug_eincl(TCCState *s1)
{
    𐤀𐤌 (!s1->do_debug)
        أرجع;
    𐤀𐤌 (s1->dwarf)
        dwarf_file(s1);
    وإلا
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC فراغ tcc_debug_line(TCCState *s1)
{
    BufferedFile *f;

    𐤀𐤌 (!s1->do_debug)
        أرجع;
    𐤀𐤌 (cur_text_section != text_section || nocode_wanted)
        أرجع;
    f = put_new_file(s1);
    𐤀𐤌 (!f)
        أرجع;
    𐤀𐤌 (last_line_num == f->line_num)
        أرجع;
    last_line_num = f->line_num;

    𐤀𐤌 (s1->dwarf) {
	صحيح len_pc = (ind - dwarf_line.last_pc) / DWARF_MIN_INSTR_LEN;
	صحيح len_line = f->line_num - dwarf_line.last_line;
	صحيح n = len_pc * DWARF_LINE_RANGE + len_line + DWARF_OPCODE_BASE - DWARF_LINE_BASE;

	𐤀𐤌 (dwarf_line.cur_file != dwarf_line.last_file) {
	    dwarf_line.last_file = dwarf_line.cur_file;
	    dwarf_line_op(s1, DW_LNS_set_file);
	    dwarf_uleb128_op(s1, dwarf_line.cur_file);
	}
	𐤀𐤌 (len_pc &&
	    len_line >= DWARF_LINE_BASE && len_line <= (DWARF_OPCODE_BASE + DWARF_LINE_BASE) &&
	    n >= DWARF_OPCODE_BASE && n <= 255)
            dwarf_line_op(s1, n);
	وإلا {
	    𐤀𐤌 (len_pc) {
	        n = len_pc * DWARF_LINE_RANGE + 0 + DWARF_OPCODE_BASE - DWARF_LINE_BASE;
	        𐤀𐤌 (n >= DWARF_OPCODE_BASE && n <= 255)
                    dwarf_line_op(s1, n);
		وإلا {
	            dwarf_line_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    𐤀𐤌 (len_line) {
	        n = 0 * DWARF_LINE_RANGE + len_line + DWARF_OPCODE_BASE - DWARF_LINE_BASE;
	        𐤀𐤌 (len_line >= DWARF_LINE_BASE && len_line <= (DWARF_OPCODE_BASE + DWARF_LINE_BASE) &&
		    n >= DWARF_OPCODE_BASE && n <= 255)
	            dwarf_line_op(s1, n);
		وإلا {
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
    وإلا
    {
	𐤀𐤌 (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->line_num, ind - func_ind);
        } وإلا {
            /* from tcc_assemble */
            put_stabs_r(s1, عدم, N_SLINE, 0, f->line_num, ind, text_section, section_sym);
        }
    }
}

ساكن فراغ tcc_debug_stabs (TCCState *s1, ثابت حرف *str, صحيح type, unsigned long value,
                             Section *sec, صحيح sym_index, صحيح info)
{
    بنية debug_sym *s;

    𐤀𐤌 (debug_info) {
        debug_info->sym =
            (بنية debug_sym *)tcc_realloc (debug_info->sym,
                                             حجم(بنية debug_sym) *
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
    وإلا 𐤀𐤌 (sec)
        put_stabs_r (s1, str, type, 0, 0, value, sec, sym_index);
    وإلا
        put_stabs (s1, str, type, 0, 0, value);
}

ساكن فراغ fix_debug_forw_hash(TCCState *s1, صحيح global, صحيح start)
{
    𐤀𐤌 (s1->dwarf) {
        صحيح i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	بنية _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	لكل (i = start; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    صحيح pos = dwarf_info_section->data_offset;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_EMPTY_TYPE
                                             : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, عدم));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_line.cur_file);
            dwarf_uleb128(dwarf_info_section, file->line_num);
	    لكل (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->data +
			  hash[i].debug_type[j],
			  pos - dwarf_info.start);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC فراغ tcc_debug_stabn(TCCState *s1, صحيح type, صحيح value)
{
    𐤀𐤌 (!s1->do_debug)
        أرجع;
    𐤀𐤌 (type == N_LBRAC) {
        بنية _debug_info *info =
            (بنية _debug_info *) tcc_mallocz(حجم (*info));

        info->start = value;
        info->last_debug_hash = n_debug_hash_local;
        info->last_debug_forw_hash = n_debug_forw_hash_local;
        info->parent = debug_info;
        𐤀𐤌 (debug_info) {
            𐤀𐤌 (debug_info->child) {
                𐤀𐤌 (debug_info->child->last)
                    debug_info->child->last->next = info;
                وإلا
                    debug_info->child->next = info;
                debug_info->child->last = info;
            }
            وإلا
                debug_info->child = info;
        }
        وإلا
            debug_info_root = info;
        debug_info = info;
    }
    وإلا {
	fix_debug_forw_hash(s1, 0, debug_info->last_debug_forw_hash);
        n_debug_hash_local = debug_info->last_debug_hash;
        n_debug_forw_hash_local = debug_info->last_debug_forw_hash;
        debug_info->end = value;
        debug_info = debug_info->parent;
    }
}

ساكن صحيح check_global(Sym *t)
{
    Sym *g = local_stack;

    طالما (g) {
	𐤀𐤌 (t == g)
	    أرجع 0;
	g = g->prev;
    }
    أرجع 1;
}

ساكن صحيح tcc_debug_find(TCCState *s1, Sym *t, صحيح dwarf)
{
    صحيح i , g = check_global(t);
    صحيح n_hash, *n_forw_hash;
    بنية _debug_hash *hash;
    بنية _debug_forw_hash **forw_hash;

    𐤀𐤌 ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	لكل (i = 0; i < *n_forw_hash; i++)
            𐤀𐤌 (t == (*forw_hash)[i].type)
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
        𐤀𐤌 (t == hash[i].type)
	    أرجع hash[i].debug_type;
    أرجع -1;
}

ساكن صحيح tcc_get_dwarf_info(TCCState *s1, Sym *s);

ساكن فراغ tcc_debug_check_forw(TCCState *s1, Sym *t, صحيح debug_type)
{
    𐤀𐤌 ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        صحيح i, j, g = check_global(t);
        صحيح n_forw_hash;
        بنية _debug_forw_hash **forw_hash;

	لكل (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    لكل (j = 0; j < n_forw_hash; j++)
                𐤀𐤌 (t->type.ref == (*forw_hash)[j].type) {
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
    𐤀𐤌 (!(s1->do_debug & 2))
	أرجع;
    𐤀𐤌 (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        أرجع;
    }
    𐤀𐤌 ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        صحيح i, j, debug_type, g = check_global(t->ref);
        صحيح *n_forw_hash;
        بنية _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	لكل (i = 0; i < *n_forw_hash; i++)
	    𐤀𐤌 (t->ref == (*forw_hash)[i].type) {
		𐤀𐤌 (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    لكل (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->data +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.start);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		لكل (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

ساكن صحيح tcc_debug_add(TCCState *s1, Sym *t, صحيح dwarf)
{
    صحيح offset = dwarf ? dwarf_info_section->data_offset : ++debug_next_type;
    صحيح *n_hash, g = check_global(t);
    بنية _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (بنية _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * حجم(**hash));
    (*hash)[*n_hash].debug_type = offset;
    (*hash)[(*n_hash)++].type = t;
    أرجع offset;
}

ساكن صحيح STRUCT_NODEBUG(Sym *s)
{
    أرجع
    (s->a.nodebug ||
     ((s->v & ~SYM_FIELD) >= SYM_FIRST_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

ساكن صحيح stabs_struct_find(TCCState *s1, Sym *t, صحيح *p_id)
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
    𐤀𐤌 (عدم == p_id)
        أرجع s && !s->r && t->c >= 0;
    𐤀𐤌 (عدم == s) {
        /* just use global_stack always */
        s = sym_push2(&global_stack, SYM_FIELD|0x00DEBBED, 0, ++debug_next_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    𐤀𐤌 (s->r || t->c < 0) /* already defined or still incomplete */
        أرجع 0;
    s->r = 1;
    أرجع 1;
}

ساكن صحيح remove_type_info(صحيح type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        𐤀𐤌 ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        𐤀𐤌 (!(type & VT_BITFIELD) && (type & VT_STRUCT_MASK) > VT_ENUM)
	    type &= ~VT_STRUCT_MASK;
	أرجع type;
}

ساكن فراغ tcc_get_debug_info(TCCState *s1, Sym *s, CString *result)
{
    صحيح type;
    صحيح n = 0;
    صحيح debug_type = -1;
    Sym *t = s;
    CString str;

    لكل (;;) {
        type = remove_type_info (t->type.t);
        𐤀𐤌 (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        وإلا
            اكسر;
    }
    𐤀𐤌 ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        𐤀𐤌 (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, عدم),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            طالما (t->next) {
                صحيح pos, size, align;
                t = t->next;
		𐤀𐤌 (STRUCT_NODEBUG(t))
		    استمر;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, عدم)
                             );
                tcc_get_debug_info (s1, t, &str);
                𐤀𐤌 (t->type.t & VT_BITFIELD) {
                    pos = t->c * 8 + BIT_POS(t->type.t);
                    size = BIT_SIZE(t->type.t);
                }
                وإلا {
                    pos = t->c * 8;
                    size = type_size(&t->type, &align) * 8;
                }
                cstr_printf (&str, ",%d,%d;", pos, size);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, عدم, 0, 0);
            cstr_free (&str);
        }
    }
    وإلا 𐤀𐤌 (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        𐤀𐤌 (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, عدم),
                         debug_type);
            طالما (t->next) {
                t = t->next;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, عدم));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (صحيح)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, عدم, 0, 0);
            cstr_free (&str);
	}
    }
    وإلا 𐤀𐤌 ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        لكل (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            𐤀𐤌 (default_debug[debug_type - 1].type == type)
                اكسر;
        𐤀𐤌 (debug_type > N_DEFAULT_DEBUG)
            أرجع;
    }

    𐤀𐤌 (عدم == result) /* from stabs_struct_complete() */
        أرجع;

    𐤀𐤌 (n > 0)
        cstr_printf (result, "%d=", ++debug_next_type);
    t = s;
    لكل (;;) {
        type = remove_type_info (t->type.t);
        𐤀𐤌 (type == VT_PTR)
            cstr_printf (result, "%d=*", ++debug_next_type);
        وإلا 𐤀𐤌 (type == (VT_PTR | VT_ARRAY))
            cstr_printf (result, "%d=ar1;0;%d;",
                         ++debug_next_type, t->type.ref->c - 1);
        وإلا 𐤀𐤌 (type == VT_FUNC) {
            cstr_printf (result, "%d=f", ++debug_next_type);
            tcc_get_debug_info (s1, t->type.ref, result);
            أرجع;
        }
        وإلا
            اكسر;
        t = t->type.ref;
    }
    cstr_printf (result, "%d", debug_type);
}

ساكن فراغ stabs_struct_complete(TCCState *s1, CType *t)
{
    𐤀𐤌 (stabs_struct_find(s1, t->ref, عدم)) {
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
    صحيح last_pos = -1;
    صحيح retval;

    𐤀𐤌 (new_file)
        put_new_file(s1);
    لكل (;;) {
        type = remove_type_info (t->type.t);
        𐤀𐤌 (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        وإلا
            اكسر;
    }
    𐤀𐤌 ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	𐤀𐤌 (debug_type == -1) {
	    صحيح pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_add(s1, t, 1);
	    e = t;
	    i = 0;
	    طالما (e->next) {
		e = e->next;
		𐤀𐤌 (STRUCT_NODEBUG(e))
		    استمر;
		i++;
	    }
	    pos_type = (صحيح *) tcc_malloc(i * حجم(صحيح));
	    dwarf_data1(dwarf_info_section,
			IS_UNION (t->type.t)
		        ? t->next ? DWARF_ABBREV_UNION_TYPE
				  : DWARF_ABBREV_UNION_EMPTY_TYPE
		        : t->next ? DWARF_ABBREV_STRUCTURE_TYPE
				  : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, عدم));
	    dwarf_uleb128(dwarf_info_section, t->c);
	    dwarf_uleb128(dwarf_info_section, dwarf_line.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->line_num);
	    𐤀𐤌 (t->next) {
	        pos_sib = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            طالما (e->next) {
                e = e->next;
		𐤀𐤌 (STRUCT_NODEBUG(e))
		    استمر;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, عدم));
		dwarf_uleb128(dwarf_info_section, dwarf_line.cur_file);
		dwarf_uleb128(dwarf_info_section, file->line_num);
		pos_type[i++] = dwarf_info_section->data_offset;
		dwarf_data4(dwarf_info_section, 0);
                𐤀𐤌 (e->type.t & VT_BITFIELD) {
                    صحيح pos = e->c * 8 + BIT_POS(e->type.t);
                    صحيح size = BIT_SIZE(e->type.t);

		    dwarf_uleb128(dwarf_info_section, size);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		وإلا
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    𐤀𐤌 (t->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + pos_sib,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    e = t;
	    i = 0;
	    طالما (e->next) {
		e = e->next;
		𐤀𐤌 (STRUCT_NODEBUG(e))
		    استمر;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->data + pos_type[i++],
			  type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
    }
    وإلا 𐤀𐤌 (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	𐤀𐤌 (debug_type == -1) {
	    صحيح pos_sib, pos_type;
	    Sym sym = {0}; sym.type.t = VT_INT | (type & VT_UNSIGNED);

	    pos_type = tcc_get_dwarf_info(s1, &sym);
	    debug_type = tcc_debug_add(s1, t, 1);
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ENUMERATION_TYPE);
	    dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, عدم));
	    dwarf_data1(dwarf_info_section,
		        type & VT_UNSIGNED ? DW_ATE_unsigned : DW_ATE_signed );
	    dwarf_data1(dwarf_info_section, 4);
	    dwarf_data4(dwarf_info_section, pos_type - dwarf_info.start);
	    dwarf_uleb128(dwarf_info_section, dwarf_line.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->line_num);
	    pos_sib = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            طالما (e->next) {
                e = e->next;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                           ? "" : get_tok_str(e->v, عدم));
		𐤀𐤌 (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		وإلا
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + pos_sib,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
    }
    وإلا 𐤀𐤌 ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        لكل (i = 1; i <= N_DEFAULT_DEBUG; i++)
            𐤀𐤌 (default_debug[i - 1].type == type)
                اكسر;
        𐤀𐤌 (i > N_DEFAULT_DEBUG)
            أرجع 0;
	debug_type = dwarf_info.base_type_used[i - 1];
	𐤀𐤌 (debug_type == 0) {
	    حرف name[100];

	    debug_type = dwarf_info_section->data_offset;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_BASE_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].size);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, حجم name, default_debug[i - 1].name);
	    *strchr(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.base_type_used[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = عدم;
    t = s;
    لكل (;;) {
        type = remove_type_info (t->type.t);
        𐤀𐤌 (type == VT_PTR) {
	    i = dwarf_info_section->data_offset;
	    𐤀𐤌 (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_POINTER);
	    dwarf_data1(dwarf_info_section, PTR_SIZE);
	    𐤀𐤌 (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        وإلا 𐤀𐤌 (type == (VT_PTR | VT_ARRAY)) {
	    صحيح sib_pos, sub_type;
#𐤀𐤌 LONG_SIZE == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#وإلا
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#endif

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->data_offset;
	    𐤀𐤌 (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    𐤀𐤌 (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    لكل (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.start);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		𐤀𐤌 (type != (VT_PTR | VT_ARRAY))
		    اكسر;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + sib_pos,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
        وإلا 𐤀𐤌 (type == VT_FUNC) {
	    صحيح sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->data_offset;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    𐤀𐤌 (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->next ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_EMPTY_TYPE);
	    𐤀𐤌 (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    𐤀𐤌 (t->type.ref->next) {
	        sib_pos = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    طالما (f->next) {
		f = f->next;
		i++;
	    }
	    pos_type = (صحيح *) tcc_malloc(i * حجم(صحيح));
	    f = t->type.ref;
	    i = 0;
	    طالما (f->next) {
		f = f->next;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    𐤀𐤌 (t->type.ref->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + sib_pos,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    f = t->type.ref;
	    i = 0;
	    طالما (f->next) {
		f = f->next;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->data + pos_type[i++],
                          type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
        وإلا {
	    𐤀𐤌 (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  debug_type - dwarf_info.start);
	    }
            اكسر;
	}
        t = t->type.ref;
    }
    أرجع retval;
}

ساكن فراغ tcc_debug_finish (TCCState *s1, بنية _debug_info *cur)
{
    طالما (cur) {
        بنية _debug_info *next = cur->next;
        صحيح i;

        𐤀𐤌 (s1->dwarf) {

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
		𐤀𐤌 (s->type == N_GSYM || s->type == N_STSYM) {
                    dwarf_uleb128(dwarf_info_section, s->file);
                    dwarf_uleb128(dwarf_info_section, s->line);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.start);
		𐤀𐤌 (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    𐤀𐤌 (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    𐤀𐤌 (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#𐤀𐤌 PTR_SIZE == 4
                    dwarf_data4(dwarf_info_section, s->value);
#وإلا
                    dwarf_data8(dwarf_info_section, s->value);
#endif
		}
		وإلا {
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
#𐤀𐤌 PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->start);
            dwarf_data4(dwarf_info_section, cur->end - cur->start);
#وإلا
            dwarf_data8(dwarf_info_section, func_ind + cur->start);
            dwarf_data8(dwarf_info_section, cur->end - cur->start);
#endif
            tcc_debug_finish (s1, cur->child);
	    𐤀𐤌 (cur->child)
                dwarf_data1(dwarf_info_section, 0);
        }
        وإلا
        {
            لكل (i = 0; i < cur->n_sym; i++) {
                بنية debug_sym *s = &cur->sym[i];

                𐤀𐤌 (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->value,
                                s->sec, s->sym_index);
                وإلا
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

ST_FUNC فراغ tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    صحيح param;

    𐤀𐤌 (!(s1->do_debug & 2))
        أرجع;

    cstr_new (&debug_str);
    param = !e;
    لكل (; s != e; s = s->prev) {
        𐤀𐤌 (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            استمر;
	𐤀𐤌 (s1->dwarf) {
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
            tcc_debug_stabs(s1, debug_str.data, param ? N_PSYM : N_LSYM,
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

    𐤀𐤌 (!s1->do_debug)
        أرجع;
    debug_info_root = عدم;
    debug_info = عدم;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    𐤀𐤌 (!f)
	أرجع;

    𐤀𐤌 (s1->dwarf) {
        tcc_debug_line(s1);
        dwarf_info.func = sym;
        dwarf_info.line = file->line_num;
	𐤀𐤌 (s1->do_backtrace) {
	    صحيح i, len;

	    dwarf_line_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, strlen(funcname) + 2);
	    dwarf_line_op(s1, DW_LNE_hi_user - 1);
	    len = strlen(funcname) + 1;
	    لكل (i = 0; i < len; i++)
		dwarf_line_op(s1, funcname[i]);
	}
    }
    وإلا
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.data, N_FUN, 0, f->line_num, 0, cur_text_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_line(s1);
    }
}

ST_FUNC فراغ tcc_debug_prolog_epilog(TCCState *s1, صحيح value)
{
    𐤀𐤌 (!s1->do_debug)
        أرجع;
    𐤀𐤌 (s1->dwarf) {
	dwarf_line_op(s1, value == 0 ? DW_LNS_set_prologue_end
				     : DW_LNS_set_epilogue_begin);
    }
}

/* put function size */
ST_FUNC فراغ tcc_debug_funcend(TCCState *s1, صحيح size)
{
    /* lldb does not like function end and next function start at same pc */
    صحيح min_instr_len;

#𐤀𐤌 TCC_EH_FRAME
    tcc_debug_frame_end(s1, size);
#endif
    𐤀𐤌 (!s1->do_debug)
        أرجع;
    min_instr_len = dwarf_line.last_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_line(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, size);
    𐤀𐤌 (s1->dwarf) {
        صحيح func_sib = 0;
	Sym *sym = dwarf_info.func;
	صحيح n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        𐤀𐤌 ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_line.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.line);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->data_offset);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.start);
        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#𐤀𐤌 PTR_SIZE == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, size); // high_pc
#وإلا
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, size); // high_pc
#endif
        func_sib = dwarf_info_section->data_offset;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#𐤀𐤌 defined(TCC_TARGET_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#وإلاإذا defined(TCC_TARGET_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#وإلاإذا defined TCC_TARGET_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#وإلاإذا defined TCC_TARGET_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#وإلاإذا defined TCC_TARGET_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#وإلا
        dwarf_data1(dwarf_info_section, DW_OP_call_frame_cfa);
#endif
        tcc_debug_finish (s1, debug_info_root);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->data + func_sib,
                  dwarf_info_section->data_offset - dwarf_info.start);
    }
    وإلا
    {
        tcc_debug_finish (s1, debug_info_root);
    }
    debug_info_root = 0;
}


ST_FUNC فراغ tcc_debug_extern_sym(TCCState *s1, Sym *sym, صحيح sh_num, صحيح sym_bind, صحيح sym_type)
{
    𐤀𐤌 (!(s1->do_debug & 2))
        أرجع;

    𐤀𐤌 (sym_type == STT_FUNC || sym->v >= SYM_FIRST_ANOM)
        أرجع;
    𐤀𐤌 (s1->dwarf) {
        صحيح debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, عدم));
	dwarf_uleb128(dwarf_info_section, dwarf_line.cur_file);
	dwarf_uleb128(dwarf_info_section, file->line_num);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	𐤀𐤌 (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->data_offset,
		R_DATA_PTR, 0);
#𐤀𐤌 PTR_SIZE == 4
	dwarf_data4(dwarf_info_section, 0);
#وإلا
	dwarf_data8(dwarf_info_section, 0);
#endif
    }
    وإلا
    {
        Section *s = sh_num == SHN_COMMON ? common_section
					  : s1->sections[sh_num];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, عدم),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        𐤀𐤌 (sym_bind == STB_GLOBAL)
            tcc_debug_stabs(s1, str.data, N_GSYM, 0, عدم, 0, 0);
        وإلا
            tcc_debug_stabs(s1, str.data,
                (sym->type.t & VT_STATIC) && data_section == s
                ? N_STSYM : N_LCSYM, 0, s, sym->c, 0);
        cstr_free (&str);
    }
}

ST_FUNC فراغ tcc_debug_typedef(TCCState *s1, Sym *sym)
{
    𐤀𐤌 (!(s1->do_debug & 2))
        أرجع;

    𐤀𐤌 (s1->dwarf) {
	صحيح debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	𐤀𐤌 (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, عدم));
	    dwarf_uleb128(dwarf_info_section, dwarf_line.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->line_num);
	    tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	    dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	}
    }
    وإلا
    {
        CString str;
        cstr_new (&str);
        cstr_printf (&str, "%s:t", get_tok_str(sym->v, عدم));
        tcc_get_debug_info(s1, sym, &str);
        tcc_debug_stabs(s1, str.data, N_LSYM, 0, عدم, 0, 0);
        cstr_free (&str);
    }
}

/* ------------------------------------------------------------------------- */
/* for section layout see lib/tcov.c */

ST_FUNC فراغ tcc_tcov_block_end(TCCState *s1, صحيح line);

ST_FUNC فراغ tcc_tcov_block_begin(TCCState *s1)
{
    SValue sv;
    فراغ *ptr;
    unsigned long last_offset = tcov_data.offset;

    tcc_tcov_block_end (tcc_state, 0);
    𐤀𐤌 (s1->test_coverage == 0 || nocode_wanted)
	أرجع;

    𐤀𐤌 (tcov_data.last_file_name == 0 ||
	strcmp ((ثابت حرف *)(tcov_section->data + tcov_data.last_file_name),
		file->true_filename) != 0) {
	حرف wd[1024];
	CString cstr;

	𐤀𐤌 (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	𐤀𐤌 (tcov_data.last_file_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = 0;
	cstr_new (&cstr);
	𐤀𐤌 (file->true_filename[0] == '/') {
	    tcov_data.last_file_name = tcov_section->data_offset;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	وإلا {
	    getcwd (wd, حجم(wd));
	    tcov_data.last_file_name = tcov_section->data_offset + strlen(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_add(tcov_section, cstr.size + 1);
	strcpy((حرف *)ptr, cstr.data);
#ifdef _WIN32
        normalize_slashes((حرف *)ptr);
#endif
	cstr_free (&cstr);
    }
    𐤀𐤌 (tcov_data.last_func_name == 0 ||
	strcmp ((ثابت حرف *)(tcov_section->data + tcov_data.last_func_name),
		funcname) != 0) {
	size_t len;

	𐤀𐤌 (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = tcov_section->data_offset;
	len = strlen (funcname);
	ptr = section_ptr_add(tcov_section, len + 1);
	strcpy((حرف *)ptr, funcname);
	section_ptr_add(tcov_section, -tcov_section->data_offset & 7);
	ptr = section_ptr_add(tcov_section, 8);
	write64le (ptr, file->line_num);
    }
    𐤀𐤌 (ind == tcov_data.ind && tcov_data.line == file->line_num)
        tcov_data.offset = last_offset;
    وإلا {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_add(tcov_section, 16);
        tcov_data.line = file->line_num;
        write64le (ptr, (tcov_data.line << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((unsigned حرف *)ptr - tcov_section->data) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#𐤀𐤌 defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || \
    defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || \
    defined TCC_TARGET_RISCV64
        gen_increment_tcov (&sv);
#وإلا
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#endif
        tcov_data.offset = (unsigned حرف *)ptr - tcov_section->data;
        tcov_data.ind = ind;
    }
}

ST_FUNC فراغ tcc_tcov_block_end(TCCState *s1, صحيح line)
{
    𐤀𐤌 (s1->test_coverage == 0)
	أرجع;
    𐤀𐤌 (line == -1)
        line = tcov_data.line;
    𐤀𐤌 (tcov_data.offset) {
	فراغ *ptr = tcov_section->data + tcov_data.offset;
	unsigned long long nline = line ? line : file->line_num;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_data.offset = 0;
    }
}

ST_FUNC فراغ tcc_tcov_check_line(TCCState *s1, صحيح start)
{
    𐤀𐤌 (s1->test_coverage == 0)
	أرجع;
    𐤀𐤌 (tcov_data.line != file->line_num) {
        𐤀𐤌 ((tcov_data.line + 1) != file->line_num) {
	    tcc_tcov_block_end (s1, -1);
	    𐤀𐤌 (start)
                tcc_tcov_block_begin (s1);
	}
	وإلا
	    tcov_data.line = file->line_num;
    }
}

ST_FUNC فراغ tcc_tcov_start(TCCState *s1)
{
    𐤀𐤌 (s1->test_coverage == 0)
	أرجع;
    𐤀𐤌 (!s1->dState)
        s1->dState = tcc_mallocz(حجم *s1->dState);
    memset (&tcov_data, 0, حجم (tcov_data));
    𐤀𐤌 (tcov_section == عدم) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_add(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC فراغ tcc_tcov_end(TCCState *s1)
{
    𐤀𐤌 (s1->test_coverage == 0)
	أرجع;
    𐤀𐤌 (tcov_data.last_func_name)
        section_ptr_add(tcov_section, 1);
    𐤀𐤌 (tcov_data.last_file_name)
        section_ptr_add(tcov_section, 1);
}

ST_FUNC فراغ tcc_tcov_reset_ind(TCCState *s1)
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
