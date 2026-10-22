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

स्थिर स्थिरांक संरचना {
  पूर्णांक type;
  पूर्णांक size;
  पूर्णांक encoding;
  स्थिरांक अक्षर *name;
} default_debug[] = {
    {   VT_INT, 4, DW_ATE_signed, "int:t1=r1;-2147483648;2147483647;" },
    {   VT_BYTE, 1, DW_ATE_signed_char, "char:t2=r2;0;127;" },
#जर LONG_SIZE == 4
    {   VT_LONG | VT_INT, 4, DW_ATE_signed, "long int:t3=r3;-2147483648;2147483647;" },
#अन्यथा
    {   VT_LLONG | VT_LONG, 8, DW_ATE_signed, "long int:t3=r3;-9223372036854775808;9223372036854775807;" },
#endif
    {   VT_INT | VT_UNSIGNED, 4, DW_ATE_unsigned, "unsigned int:t4=r4;0;037777777777;" },
#जर LONG_SIZE == 4
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
#जर LONG_SIZE == 4
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t27=27" },
#अन्यथा
    /* bitfields use these */
    {   VT_LONG | VT_INT, 8, DW_ATE_signed, "long int:t27=r27;-9223372036854775808;9223372036854775807;" },
    {   VT_LONG | VT_INT | VT_UNSIGNED, 8, DW_ATE_unsigned, "long unsigned int:t28=r28;0;01777777777777777777777;" },
    {   VT_VOID, 1, DW_ATE_unsigned_char, "void:t29=29" },
#endif
};

#define	N_DEFAULT_DEBUG	(आकार (default_debug) / आकार (default_debug[0]))

/* dwarf debug */

#define	DWARF_ओळ_BASE				-5
#define	DWARF_ओळ_RANGE			14
#define	DWARF_OPCODE_BASE			13

#जर defined TCC_TARGET_ARM64
#define	DWARF_MIN_INSTR_LEN			4
#किंवाजर defined TCC_TARGET_ARM
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
स्थिर स्थिरांक अचिन्हित अक्षर dwarf_abbrev_init[] = {
    DWARF_ABBREV_COMPILE_UNIT, DW_TAG_compile_unit, 1,
          DW_AT_producer, DW_FORM_strp,
          DW_AT_language, DW_FORM_data1,
          DW_AT_name, DW_FORM_ओळ_strp,
          DW_AT_comp_dir, DW_FORM_ओळ_strp,
          DW_AT_खालचा_pc, DW_FORM_addr,
#जर PTR_SIZE == 4
          DW_AT_वरचा_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_वरचा_pc, DW_FORM_data8,
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
          DW_AT_decl_ओळ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_external, DW_FORM_flag,
          DW_AT_location, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_VARIABLE_STATIC, DW_TAG_variable, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ओळ, DW_FORM_udata,
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
          DW_AT_decl_ओळ, DW_FORM_udata,
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
          DW_AT_byte_size, DW_FORM_data1,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ओळ, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_MEMBER, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ओळ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_data_member_location, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_MEMBER_BF, DW_TAG_member, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ओळ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_bit_size, DW_FORM_udata,
          DW_AT_data_bit_offset, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_STRUCTURE_TYPE, DW_TAG_structure_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ओळ, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_STRUCTURE_EMPTY_TYPE, DW_TAG_structure_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ओळ, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_UNION_TYPE, DW_TAG_union_type, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ओळ, DW_FORM_udata,
          DW_AT_sibling, DW_FORM_ref4,
          0, 0,
    DWARF_ABBREV_UNION_EMPTY_TYPE, DW_TAG_union_type, 0,
          DW_AT_name, DW_FORM_strp,
          DW_AT_byte_size, DW_FORM_udata,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ओळ, DW_FORM_udata,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_EXTERNAL, DW_TAG_subprogram, 1,
          DW_AT_external, DW_FORM_flag,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ओळ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_खालचा_pc, DW_FORM_addr,
#जर PTR_SIZE == 4
          DW_AT_वरचा_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_वरचा_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_SUBPROGRAM_STATIC, DW_TAG_subprogram, 1,
          DW_AT_name, DW_FORM_strp,
          DW_AT_decl_file, DW_FORM_udata,
          DW_AT_decl_ओळ, DW_FORM_udata,
          DW_AT_type, DW_FORM_ref4,
          DW_AT_खालचा_pc, DW_FORM_addr,
#जर PTR_SIZE == 4
          DW_AT_वरचा_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_वरचा_pc, DW_FORM_data8,
#endif
          DW_AT_sibling, DW_FORM_ref4,
	  DW_AT_frame_base, DW_FORM_exprloc,
          0, 0,
    DWARF_ABBREV_LEXICAL_BLOCK, DW_TAG_lexical_block, 1,
          DW_AT_खालचा_pc, DW_FORM_addr,
#जर PTR_SIZE == 4
          DW_AT_वरचा_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_वरचा_pc, DW_FORM_data8,
#endif
          0, 0,
    DWARF_ABBREV_LEXICAL_EMPTY_BLOCK, DW_TAG_lexical_block, 0,
          DW_AT_खालचा_pc, DW_FORM_addr,
#जर PTR_SIZE == 4
          DW_AT_वरचा_pc, DW_FORM_data4,
#अन्यथा
          DW_AT_वरचा_pc, DW_FORM_data8,
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

स्थिर स्थिरांक अचिन्हित अक्षर dwarf_ओळ_opcodes[] = {
    0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1
};

/* ------------------------------------------------------------------------- */
/* debug state */

#define N_STR_HASH (251)

संरचना dwarf_str_hash {
    पूर्णांक len;
    अचिन्हित दीर्घ data_offset;
    संरचना dwarf_str_hash *next;
};

संरचना _tccdbg {

    पूर्णांक last_ओळ_अंक, new_file;
    पूर्णांक section_sym;

    पूर्णांक debug_next_type;

    संरचना _debug_hash {
        पूर्णांक debug_type;
        Sym *type;
    } *debug_hash_global, *debug_hash_local;

    /* store forward structure/unions types */
    संरचना _debug_forw_hash {
        Sym *type;
        पूर्णांक n_debug_type;
        पूर्णांक *debug_type;
    } *debug_forw_hash_global, *debug_forw_hash_local;

    पूर्णांक n_debug_hash_global;
    पूर्णांक n_debug_hash_local;
    पूर्णांक n_debug_forw_hash_global;
    पूर्णांक n_debug_forw_hash_local;

    संरचना _debug_info {
        पूर्णांक start;
        पूर्णांक end;
        पूर्णांक last_debug_hash;
        पूर्णांक last_debug_forw_hash;
        पूर्णांक n_sym;
        संरचना debug_sym {
            पूर्णांक type;
            अचिन्हित दीर्घ मूल्य;
            अक्षर *str;
            Section *sec;
            पूर्णांक sym_index;
            पूर्णांक info;
            पूर्णांक file;
            पूर्णांक ओळ;
        } *sym;
        संरचना _debug_info *child, *next, *last, *parent;
    } *debug_info, *debug_info_मूळ;

    संरचना {
        पूर्णांक info;
        पूर्णांक abbrev;
        पूर्णांक ओळ;
        पूर्णांक str;
        पूर्णांक ओळ_str;
    } dwarf_sym;

    संरचना {
        पूर्णांक start;
        पूर्णांक dir_size;
        अक्षर **dir_table;
        पूर्णांक filename_size;
        संरचना dwarf_filename_struct {
            पूर्णांक dir_entry;
            अक्षर *name;
        } *filename_table;
        पूर्णांक ओळ_size;
        पूर्णांक ओळ_max_size;
        अचिन्हित अक्षर *ओळ_data;
        पूर्णांक cur_file;
        पूर्णांक last_file;
        पूर्णांक last_pc;
        पूर्णांक last_ओळ;
    } dwarf_ओळ;

    संरचना {
        पूर्णांक start;
        Sym *func;
        पूर्णांक ओळ;
        पूर्णांक base_type_used[N_DEFAULT_DEBUG];
    } dwarf_info;

    संरचना dwarf_str_hash *dwarf_str[N_STR_HASH];
    संरचना dwarf_str_hash *dwarf_ओळ_str[N_STR_HASH];

    /* test coverage */
    संरचना {
        अचिन्हित दीर्घ offset;
        अचिन्हित दीर्घ last_file_name;
        अचिन्हित दीर्घ last_func_name;
        पूर्णांक ind;
        पूर्णांक ओळ;
    } tcov_data;
};

#define last_ओळ_अंक             s1->dState->last_ओळ_अंक
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
#define debug_info_मूळ           s1->dState->debug_info_मूळ
#define dwarf_sym                 s1->dState->dwarf_sym
#define dwarf_ओळ                s1->dState->dwarf_ओळ
#define dwarf_info                s1->dState->dwarf_info
#define dwarf_str                 s1->dState->dwarf_str
#define dwarf_ओळ_str            s1->dState->dwarf_ओळ_str
#define tcov_data                 s1->dState->tcov_data

#define	FDE_ENCODING        (DW_EH_PE_udata4 | DW_EH_PE_signed | DW_EH_PE_pcrel)

/* ------------------------------------------------------------------------- */
स्थिर पूर्णांक put_stabs(TCCState *s1, स्थिरांक अक्षर *str, पूर्णांक type, पूर्णांक other,
    पूर्णांक desc, अचिन्हित दीर्घ मूल्य);

ST_FUNC शून्य tcc_debug_new(TCCState *s1)
{
    पूर्णांक shf = 0;
    जर (!s1->dState)
        s1->dState = tcc_mallocz(आकार *s1->dState);

#ifdef CONFIG_TCC_BACKTRACE
    /* include stab info with standalone backtrace support */
    जर (s1->do_debug && s1->output_type == TCC_OUTPUT_MEMORY)
        s1->do_backtrace = 1;
    जर (s1->do_backtrace)
        shf = SHF_ALLOC; /* have debug data available at runtime */
#endif

    जर (s1->dwarf) {
	पूर्णांक i;
	/* The sections below are just to make reloctions with
	   R_DATA_32DW work correctly. See tccelf.c */
	स्थिर स्थिरांक अक्षर *स्थिरांक debug[] = {
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
        dwarf_ओळ_section =
	    new_section(s1, ".debug_line", SHT_PROGBITS, shf);
        dwarf_aranges_section =
	    new_section(s1, ".debug_aranges", SHT_PROGBITS, shf);
	साठी (i = 0; i < आकार(debug)/आकार(debug[0]); i++)
	    new_section(s1, debug[i], SHT_PROGBITS, 0)->sh_addralign = 1;
	shf |= SHF_MERGE | SHF_STRINGS;
        dwarf_str_section =
	    new_section(s1, ".debug_str", SHT_PROGBITS, shf);
	dwarf_str_section->sh_entsize = 1;
	dwarf_info_section->sh_addralign =
	dwarf_abbrev_section->sh_addralign =
	dwarf_ओळ_section->sh_addralign =
	dwarf_aranges_section->sh_addralign =
	dwarf_str_section->sh_addralign = 1;
	जर (s1->dwarf >= 5) {
            dwarf_ओळ_str_section =
	        new_section(s1, ".debug_line_str", SHT_PROGBITS, shf);
	    dwarf_ओळ_str_section->sh_entsize = 1;
	    dwarf_ओळ_str_section->sh_addralign = 1;
	}
        s1->dwhi = s1->nb_sections;
    }
    अन्यथा
    {
        stab_section = new_section(s1, ".stab", SHT_PROGBITS, shf);
        stab_section->sh_entsize = आकार(Stab_Sym);
        stab_section->sh_addralign = आकार ((Stab_Sym*)0)->n_मूल्य;
        stab_section->link = new_section(s1, ".stabstr", SHT_STRTAB, shf);
        /* put first entry */
        put_stabs(s1, "", 0, 0, 0, 0);
    }
}

/* put stab debug information */
स्थिर पूर्णांक put_stabs(TCCState *s1, स्थिरांक अक्षर *str, पूर्णांक type, पूर्णांक other, पूर्णांक desc,
                      अचिन्हित दीर्घ मूल्य)
{
    Stab_Sym *sym;

    अचिन्हित offset;
    जर (type == N_SLINE
        && (offset = stab_section->data_offset)
        && (sym = (Stab_Sym*)(stab_section->data + offset) - 1)
        && sym->n_type == type
        && sym->n_मूल्य == मूल्य) {
        /* just update line_number in previous entry */
        sym->n_desc = desc;
        परत 0;
    }

    sym = section_ptr_add(stab_section, आकार(Stab_Sym));
    जर (str) {
        sym->n_strx = put_elf_str(stab_section->link, str);
    } अन्यथा {
        sym->n_strx = 0;
    }
    sym->n_type = type;
    sym->n_other = other;
    sym->n_desc = desc;
    sym->n_मूल्य = मूल्य;
    परत 1;
}

स्थिर शून्य put_stabs_r(TCCState *s1, स्थिरांक अक्षर *str, पूर्णांक type, पूर्णांक other, पूर्णांक desc,
                        अचिन्हित दीर्घ मूल्य, Section *sec, पूर्णांक sym_index)
{
    जर (put_stabs(s1, str, type, other, desc, मूल्य))
        put_elf_reloc(symtab_section, stab_section,
                      stab_section->data_offset - 4,
                      आकार ((Stab_Sym*)0)->n_मूल्य == PTR_SIZE ? R_DATA_PTR : R_DATA_32,
                      sym_index);
}

स्थिर शून्य put_stabn(TCCState *s1, पूर्णांक type, पूर्णांक other, पूर्णांक desc, पूर्णांक मूल्य)
{
    put_stabs(s1, रिक्त, type, other, desc, मूल्य);
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

स्थिर पूर्णांक dwarf_get_section_sym(Section *s)
{
    TCCState *s1 = s->s1;
    परत put_elf_sym(symtab_section, 0, 0,
                       ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                       s->sh_अंक, रिक्त);
}

स्थिर शून्य dwarf_reloc(Section *s, पूर्णांक sym, पूर्णांक rel)
{
    TCCState *s1 = s->s1;
    put_elf_reloca(symtab_section, s, s->data_offset, rel, sym, 0);
}

स्थिर शून्य free_str(संरचना dwarf_str_hash **str)
{
    पूर्णांक i;

    साठी (i = 0; i < N_STR_HASH; i++) {
       पर्यंत (str[i]) {
           संरचना dwarf_str_hash *next = str[i]->next;

           tcc_free(str[i]);
           str[i] = next;
       }
    }
}

स्थिर अचिन्हित str_hash(स्थिरांक अक्षर *s)
{
    अचिन्हित h = 5381;

    पर्यंत (*s)
       h += (*s++ & 0xffu) + h * 31;
    परत h;
}

स्थिर शून्य dwarf_string(Section *s, Section *dw, पूर्णांक sym, स्थिरांक अक्षर *str)
{
    TCCState *s1 = s->s1;
    पूर्णांक len, hash = str_hash(str) % N_STR_HASH;
    अक्षर *ptr;
    संरचना dwarf_str_hash *new_hash;
    संरचना dwarf_str_hash **dw_hash =
	dw == dwarf_str_section ? dwarf_str : dwarf_ओळ_str;

    len = म_माप(str) + 1;
    new_hash = dw_hash[hash];
    पर्यंत (new_hash) {
	जर (new_hash->len == len &&
	    !स_भेद(str, dw->data + new_hash->data_offset, len))
	    थांबा;
	new_hash = new_hash->next;
    }
    जर (new_hash == रिक्त) {
	अचिन्हित दीर्घ offset = dw->data_offset;

        new_hash = dw_hash[hash];
        पर्यंत (new_hash) {
	    अचिन्हित दीर्घ n = new_hash->data_offset + new_hash->len - len;

	    जर (new_hash->len > len &&
	        !स_भेद(str, dw->data + n, len)) {
		offset = n;
		थांबा;
	    }
	    new_hash = new_hash->next;
        }
	जर (new_hash == रिक्त) {
	    ptr = section_ptr_add(dw, len);
	    स_हटाओ(ptr, str, len);
	}
	new_hash = (संरचना dwarf_str_hash *)
	    tcc_malloc(आकार(संरचना dwarf_str_hash));
	new_hash->len = len;
	new_hash->data_offset = offset;
	new_hash->next = dw_hash[hash];
	dw_hash[hash] = new_hash;
    }
    put_elf_reloca(symtab_section, s, s->data_offset, R_DATA_32DW, sym,
                   PTR_SIZE == 4 ? 0 : new_hash->data_offset);
    dwarf_data4(s, PTR_SIZE == 4 ? new_hash->data_offset : 0);
}

स्थिर शून्य dwarf_strp(Section *s, स्थिरांक अक्षर *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_str_section, dwarf_sym.str, str);
}

स्थिर शून्य dwarf_ओळ_strp(Section *s, स्थिरांक अक्षर *str)
{
    TCCState *s1 = s->s1;
    dwarf_string(s, dwarf_ओळ_str_section, dwarf_sym.ओळ_str, str);
}

स्थिर शून्य dwarf_ओळ_op(TCCState *s1, अचिन्हित अक्षर op)
{
    जर (dwarf_ओळ.ओळ_size >= dwarf_ओळ.ओळ_max_size) {
	dwarf_ओळ.ओळ_max_size += 1024;
	dwarf_ओळ.ओळ_data =
	    (अचिन्हित अक्षर *)tcc_realloc(dwarf_ओळ.ओळ_data,
					 dwarf_ओळ.ओळ_max_size);
    }
    dwarf_ओळ.ओळ_data[dwarf_ओळ.ओळ_size++] = op;
}

स्थिर शून्य dwarf_file(TCCState *s1)
{
    पूर्णांक i, j;
    अक्षर *filename;
    पूर्णांक index_offset = s1->dwarf < 5;

    जर (!म_भेद(file->filename, "<command line>")) {
        dwarf_ओळ.cur_file = 1;
	परत;
    }
    filename = म_खोजप(file->filename, '/');
    जर (filename == रिक्त) {
        साठी (i = 1; i < dwarf_ओळ.filename_size; i++)
            जर (dwarf_ओळ.filename_table[i].dir_entry == 0 &&
		म_भेद(dwarf_ओळ.filename_table[i].name,
		       file->filename) == 0) {
		    dwarf_ओळ.cur_file = i + index_offset;
	            परत;
		}
	i = -index_offset;
	filename = file->filename;
    }
    अन्यथा {
	अक्षर *undo = filename;
	अक्षर *dir = file->filename;

	*filename++ = '\0';
        साठी (i = 0; i < dwarf_ओळ.dir_size; i++)
	    जर (म_भेद(dwarf_ओळ.dir_table[i], dir) == 0) {
		साठी (j = 1; j < dwarf_ओळ.filename_size; j++)
		    जर (dwarf_ओळ.filename_table[j].dir_entry - index_offset
			== i &&
			म_भेद(dwarf_ओळ.filename_table[j].name,
			       filename) == 0) {
			*undo = '/';
		        dwarf_ओळ.cur_file = j + index_offset;
			परत;
		    }
		थांबा;
	    }
	जर (i == dwarf_ओळ.dir_size) {
	    dwarf_ओळ.dir_size++;
	    dwarf_ओळ.dir_table =
                (अक्षर **) tcc_realloc(dwarf_ओळ.dir_table,
                                      dwarf_ओळ.dir_size *
                                      आकार (अक्षर *));
            dwarf_ओळ.dir_table[i] = tcc_strdup(dir);
	}
	*undo = '/';
    }
    dwarf_ओळ.filename_table =
        (संरचना dwarf_filename_struct *)
        tcc_realloc(dwarf_ओळ.filename_table,
                    (dwarf_ओळ.filename_size + 1) *
                    आकार (संरचना dwarf_filename_struct));
    dwarf_ओळ.filename_table[dwarf_ओळ.filename_size].dir_entry =
	i + index_offset;
    dwarf_ओळ.filename_table[dwarf_ओळ.filename_size].name =
        tcc_strdup(filename);
    dwarf_ओळ.cur_file = dwarf_ओळ.filename_size++ + index_offset;
    परत;
}

#जर 0
स्थिर पूर्णांक dwarf_uleb128_size (अचिन्हित दीर्घ दीर्घ मूल्य)
{
    पूर्णांक size =  0;

    करा {
        मूल्य >>= 7;
        size++;
    } पर्यंत (मूल्य != 0);
    परत size;
}
#endif

स्थिर पूर्णांक dwarf_sleb128_size (दीर्घ दीर्घ मूल्य)
{
    पूर्णांक size =  0;
    दीर्घ दीर्घ end = मूल्य >> 63;
    अचिन्हित अक्षर last = end & 0x40;
    अचिन्हित अक्षर byte;

    करा {
        byte = मूल्य & 0x7f;
        मूल्य >>= 7;
        size++;
    } पर्यंत (मूल्य != end || (byte & 0x40) != last);
    परत size;
}

स्थिर शून्य dwarf_uleb128 (Section *s, अचिन्हित दीर्घ दीर्घ मूल्य)
{
    करा {
        अचिन्हित अक्षर byte = मूल्य & 0x7f;

        मूल्य >>= 7;
        dwarf_data1(s, byte | (मूल्य ? 0x80 : 0));
    } पर्यंत (मूल्य != 0);
}

स्थिर शून्य dwarf_sleb128 (Section *s, दीर्घ दीर्घ मूल्य)
{
    पूर्णांक more;
    दीर्घ दीर्घ end = मूल्य >> 63;
    अचिन्हित अक्षर last = end & 0x40;

    करा {
        अचिन्हित अक्षर byte = मूल्य & 0x7f;

        मूल्य >>= 7;
	more = मूल्य != end || (byte & 0x40) != last;
        dwarf_data1(s, byte | (0x80 * more));
    } पर्यंत (more);
}

स्थिर शून्य dwarf_uleb128_op (TCCState *s1, अचिन्हित दीर्घ दीर्घ मूल्य)
{
    करा {
        अचिन्हित अक्षर byte = मूल्य & 0x7f;

        मूल्य >>= 7;
        dwarf_ओळ_op(s1, byte | (मूल्य ? 0x80 : 0));
    } पर्यंत (मूल्य != 0);
}

स्थिर शून्य dwarf_sleb128_op (TCCState *s1, दीर्घ दीर्घ मूल्य)
{
    पूर्णांक more;
    दीर्घ दीर्घ end = मूल्य >> 63;
    अचिन्हित अक्षर last = end & 0x40;

    करा {
        अचिन्हित अक्षर byte = मूल्य & 0x7f;

        मूल्य >>= 7;
        more = मूल्य != end || (byte & 0x40) != last;
        dwarf_ओळ_op(s1, byte | (0x80 * more));
    } पर्यंत (more);
}

#जर TCC_EH_FRAME
ST_FUNC शून्य tcc_eh_frame_start(TCCState *s1)
{
    जर (!s1->unwind_tables)
        परत;
    eh_frame_section = new_section(s1, ".eh_frame", SHT_PROGBITS, SHF_ALLOC);

    s1->eh_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section, 0); // CIE ID
    dwarf_data1(eh_frame_section, 1); // Version
    dwarf_data1(eh_frame_section, 'z'); // Augmentation String
    dwarf_data1(eh_frame_section, 'R');
    dwarf_data1(eh_frame_section, 0);
#जर defined TCC_TARGET_I386
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
#किंवाजर defined TCC_TARGET_X86_64
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
#किंवाजर defined TCC_TARGET_ARM
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
#किंवाजर defined TCC_TARGET_ARM64
    dwarf_uleb128(eh_frame_section, 4); // code_alignment_factor
    dwarf_sleb128(eh_frame_section, -8); // data_alignment_factor
    dwarf_uleb128(eh_frame_section, 30); // return address column
    dwarf_uleb128(eh_frame_section, 1); // Augmentation len
    dwarf_data1(eh_frame_section, FDE_ENCODING);
    dwarf_data1(eh_frame_section, DW_CFA_def_cfa);
    dwarf_uleb128(eh_frame_section, 31); // x31 (sp)
    dwarf_uleb128(eh_frame_section, 0); // ofs 0
#किंवाजर defined TCC_TARGET_RISCV64
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
    पर्यंत ((eh_frame_section->data_offset - s1->eh_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + s1->eh_start, // length
	      eh_frame_section->data_offset - s1->eh_start - 4);
}

स्थिर शून्य tcc_debug_frame_end(TCCState *s1, पूर्णांक size)
{
    पूर्णांक eh_section_sym;
    अचिन्हित दीर्घ fde_start;

    जर (!eh_frame_section)
	परत;
    eh_section_sym = dwarf_get_section_sym(text_section);
    fde_start = eh_frame_section->data_offset;
    dwarf_data4(eh_frame_section, 0); // length
    dwarf_data4(eh_frame_section,
		fde_start - s1->eh_start + 4); // CIE Pointer
#जर defined TCC_TARGET_I386
    dwarf_reloc(eh_frame_section, eh_section_sym, R_386_PC32);
#किंवाजर defined TCC_TARGET_X86_64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_X86_64_PC32);
#किंवाजर defined TCC_TARGET_ARM
    dwarf_reloc(eh_frame_section, eh_section_sym, R_ARM_REL32);
#किंवाजर defined TCC_TARGET_ARM64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_AARCH64_PREL32);
#किंवाजर defined TCC_TARGET_RISCV64
    dwarf_reloc(eh_frame_section, eh_section_sym, R_RISCV_32_PCREL);
#endif
    dwarf_data4(eh_frame_section, func_ind); // PC Begin
    dwarf_data4(eh_frame_section, size); // PC Range
    dwarf_data1(eh_frame_section, 0); // Augmentation Length
#जर defined TCC_TARGET_I386
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
#किंवाजर defined TCC_TARGET_X86_64
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
#किंवाजर defined TCC_TARGET_ARM
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
#किंवाजर defined TCC_TARGET_ARM64
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
#किंवाजर defined TCC_TARGET_RISCV64
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
    पर्यंत (size >= 4 &&
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
    पर्यंत ((eh_frame_section->data_offset - fde_start) & 3)
	dwarf_data1(eh_frame_section, DW_CFA_nop);
    write32le(eh_frame_section->data + fde_start, // length
	      eh_frame_section->data_offset - fde_start - 4);
}

ST_FUNC शून्य tcc_eh_frame_end(TCCState *s1)
{
    जर (!eh_frame_section)
	परत;
    dwarf_data4(eh_frame_section, 0);
}

संरचना eh_शोध_table {
    uint32_t pc_offset;
    uint32_t fde_offset;
};

स्थिर पूर्णांक sort_eh_table(स्थिरांक शून्य *a, स्थिरांक शून्य *b)
{
    uint32_t pc1 = ((स्थिरांक संरचना eh_शोध_table *)a)->pc_offset;
    uint32_t pc2 = ((स्थिरांक संरचना eh_शोध_table *)b)->pc_offset;

    परत pc1 < pc2 ? -1 : pc1 > pc2 ? 1 : 0;
}

ST_FUNC शून्य tcc_eh_frame_hdr(TCCState *s1, पूर्णांक final)
{
    पूर्णांक मोजणी_2 = 0, offset;
    अचिन्हित दीर्घ मोजणी_offset, tab_offset;
    अचिन्हित अक्षर *ln, *end;
    अचिन्हित पूर्णांक last_cie_offset = 0xffffffff;

    जर (!eh_frame_section || !eh_frame_section->data_offset)
	परत;
    जर (final && !eh_frame_hdr_section)
	परत;
    जर (final == 0)
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
    //मोजणी
    मोजणी_offset = eh_frame_hdr_section->data_offset;
    dwarf_data4(eh_frame_hdr_section, 0);
    tab_offset = eh_frame_hdr_section->data_offset;
    ln = eh_frame_section->data;
    end = eh_frame_section->data + eh_frame_section->data_offset;
    पर्यंत (ln < end) {
	अचिन्हित अक्षर *fde = ln, *rd = ln;
	अचिन्हित पूर्णांक cie_offset, version, length = dwarf_read_4(rd, end);
	अचिन्हित पूर्णांक pc_offset, fde_offset;

	जर (length == 0)
	    जा next;
        cie_offset = dwarf_read_4(rd, end);
	जर (cie_offset == 0)
	    जा next;
	जर (cie_offset != last_cie_offset) {
	    अचिन्हित अक्षर *cie = rd - cie_offset + 4;

	    जर (cie < eh_frame_section->data)
		जा next;
	    version = dwarf_read_1(cie, end);
	    जर ((version == 1 || version == 3) &&
	        dwarf_read_1(cie, end) == 'z' && // Augmentation String
		dwarf_read_1(cie, end) == 'R' &&
		dwarf_read_1(cie, end) == 0) {
	        dwarf_read_uleb128(&cie, end); // code_alignment_factor
	        dwarf_read_sleb128(&cie, end); // data_alignment_factor
		dwarf_read_1(cie, end); // return address column
		जर (dwarf_read_uleb128(&cie, end) == 1 &&
		    dwarf_read_1(cie, end) == FDE_ENCODING) {
		    last_cie_offset = cie_offset;
		}
		अन्यथा
		    जा next;
	    }
	    अन्यथा
		जा next;
	}
	मोजणी_2++;
	fde_offset = eh_frame_section->sh_addr +
		     (fde - eh_frame_section->data) -
		     eh_frame_hdr_section->sh_addr;
	pc_offset = dwarf_read_4(rd, end) + fde_offset + 8;
	dwarf_data4(eh_frame_hdr_section, pc_offset);
	dwarf_data4(eh_frame_hdr_section, fde_offset);
next:
	ln += length + 4;
    }
    add32le(eh_frame_hdr_section->data + मोजणी_offset, मोजणी_2);
    क्विक(eh_frame_hdr_section->data + tab_offset, मोजणी_2,
	  आकार(संरचना eh_शोध_table), sort_eh_table);
}
#endif

/* start of translation unit info */
ST_FUNC शून्य tcc_debug_start(TCCState *s1)
{
    पूर्णांक i;
    अक्षर buf[512];
    अक्षर *filename;

    /* we might currently #include the <command-line> */
    filename = file->prev ? file->prev->filename : file->filename;

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, filename);

    जर (s1->do_debug) {
        /* put a "mapping symbol" '$a' for llvm-objdump etc. tools needed
           to make them disassemble again when crt1.o had a '$d' before */
        put_elf_sym(symtab_section, text_section->data_offset, 0,
            ELFW(ST_INFO)(STB_LOCAL, STT_NOTYPE), 0,
            text_section->sh_अंक, "$a");

        new_file = last_ओळ_अंक = 0;
        debug_next_type = N_DEFAULT_DEBUG;
        debug_hash_global = रिक्त;
        debug_hash_local = रिक्त;
        debug_forw_hash_global = रिक्त;
        debug_forw_hash_local = रिक्त;
        n_debug_hash_global = 0;
        n_debug_hash_local = 0;
        n_debug_forw_hash_global = 0;
        n_debug_forw_hash_local = 0;

        getcwd(buf, आकार(buf));
#ifdef _WIN32
        normalize_slashes(buf);
#endif

        जर (s1->dwarf) {
            पूर्णांक start_abbrev;
            अचिन्हित अक्षर *ptr;
	    अक्षर *undo;

            /* dwarf_abbrev */
            start_abbrev = dwarf_abbrev_section->data_offset;
            ptr = section_ptr_add(dwarf_abbrev_section, आकार(dwarf_abbrev_init));
            स_नकल(ptr, dwarf_abbrev_init, आकार(dwarf_abbrev_init));

            जर (s1->dwarf < 5) {
    	        पर्यंत (*ptr) {
    	            ptr += 3;
    	            पर्यंत (*ptr) {
    	                जर (ptr[1] == DW_FORM_ओळ_strp)
    		            ptr[1] = DW_FORM_strp;
		        जर (s1->dwarf < 4) {
			    /* These are compatable for DW_TAG_compile_unit
			       DW_AT_stmt_list. */
			    जर  (ptr[1] == DW_FORM_sec_offset)
			         ptr[1] = DW_FORM_data4;
			    /* This code uses only size < 0x80 so these are
			       compatible. */
			    जर  (ptr[1] == DW_FORM_exprloc)
			         ptr[1] = DW_FORM_block1;
			}
    	                ptr += 2;
    	            }
		    ptr += 2;
    	        }
            }

            dwarf_sym.info = dwarf_get_section_sym(dwarf_info_section);
            dwarf_sym.abbrev = dwarf_get_section_sym(dwarf_abbrev_section);
            dwarf_sym.ओळ = dwarf_get_section_sym(dwarf_ओळ_section);
            dwarf_sym.str = dwarf_get_section_sym(dwarf_str_section);
            जर (tcc_state->dwarf >= 5)
    	        dwarf_sym.ओळ_str = dwarf_get_section_sym(dwarf_ओळ_str_section);
            अन्यथा {
    	        dwarf_ओळ_str_section = dwarf_str_section;
                dwarf_sym.ओळ_str = dwarf_sym.str;
            }
            section_sym = dwarf_get_section_sym(text_section);

            /* dwarf_info */
            dwarf_info.start = dwarf_info_section->data_offset;
            dwarf_data4(dwarf_info_section, 0); // size
            dwarf_data2(dwarf_info_section, s1->dwarf); // version
            जर (s1->dwarf >= 5) {
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
            dwarf_ओळ_strp(dwarf_info_section, filename);
            dwarf_ओळ_strp(dwarf_info_section, buf);
            dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#जर PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, ind); // low pc
            dwarf_data4(dwarf_info_section, 0); // high pc
#अन्यथा
            dwarf_data8(dwarf_info_section, ind); // low pc
            dwarf_data8(dwarf_info_section, 0); // high pc
#endif
            dwarf_reloc(dwarf_info_section, dwarf_sym.ओळ, R_DATA_32DW);
            dwarf_data4(dwarf_info_section, dwarf_ओळ_section->data_offset); // stmt_list

            /* dwarf_line */
            dwarf_ओळ.start = dwarf_ओळ_section->data_offset;
            dwarf_data4(dwarf_ओळ_section, 0); // length
            dwarf_data2(dwarf_ओळ_section, s1->dwarf); // version
            जर (s1->dwarf >= 5) {
                dwarf_data1(dwarf_ओळ_section, PTR_SIZE); // address size
                dwarf_data1(dwarf_ओळ_section, 0); // segment selector
            }
            dwarf_data4(dwarf_ओळ_section, 0); // prologue Length
            dwarf_data1(dwarf_ओळ_section, DWARF_MIN_INSTR_LEN);
            जर (s1->dwarf >= 4)
                dwarf_data1(dwarf_ओळ_section, 1); // maximum ops per instruction
            dwarf_data1(dwarf_ओळ_section, 1); // Initial value of 'is_stmt'
            dwarf_data1(dwarf_ओळ_section, DWARF_ओळ_BASE);
            dwarf_data1(dwarf_ओळ_section, DWARF_ओळ_RANGE);
            dwarf_data1(dwarf_ओळ_section, DWARF_OPCODE_BASE);
            ptr = section_ptr_add(dwarf_ओळ_section, आकार(dwarf_ओळ_opcodes));
            स_नकल(ptr, dwarf_ओळ_opcodes, आकार(dwarf_ओळ_opcodes));
	    undo = म_खोजप(filename, '/');
	    जर (undo)
		*undo = 0;
            dwarf_ओळ.dir_size = 1 + (undo != रिक्त);
            dwarf_ओळ.dir_table = (अक्षर **) tcc_malloc(आकार (अक्षर *) *
							dwarf_ओळ.dir_size);
            dwarf_ओळ.dir_table[0] = tcc_strdup(buf);
	    जर (undo)
                dwarf_ओळ.dir_table[1] = tcc_strdup(filename);
            dwarf_ओळ.filename_size = 2;
            dwarf_ओळ.filename_table =
    	        (संरचना dwarf_filename_struct *)
    	        tcc_malloc(2*आकार (संरचना dwarf_filename_struct));
            dwarf_ओळ.filename_table[0].dir_entry = 0;
	    जर (undo) {
                dwarf_ओळ.filename_table[0].name = tcc_strdup(undo + 1);
                dwarf_ओळ.filename_table[1].dir_entry = 1;
                dwarf_ओळ.filename_table[1].name = tcc_strdup(undo + 1);
		*undo = '/';
	    }
	    अन्यथा {
                dwarf_ओळ.filename_table[0].name = tcc_strdup(filename);
                dwarf_ओळ.filename_table[1].dir_entry = 0;
                dwarf_ओळ.filename_table[1].name = tcc_strdup(filename);
	    }
            dwarf_ओळ.ओळ_size = dwarf_ओळ.ओळ_max_size = 0;
            dwarf_ओळ.ओळ_data = रिक्त;
            dwarf_ओळ.cur_file = 1;
            dwarf_ओळ.last_file = 0;
            dwarf_ओळ.last_pc = 0;
            dwarf_ओळ.last_ओळ = 1;
            dwarf_ओळ_op(s1, 0); // extended
            dwarf_uleb128_op(s1, 1 + PTR_SIZE); // extended size
            dwarf_ओळ_op(s1, DW_LNE_set_address);
            साठी (i = 0; i < PTR_SIZE; i++)
    	        dwarf_ओळ_op(s1, 0);
            स_रखो(&dwarf_info.base_type_used, 0, आकार(dwarf_info.base_type_used));
        }
        अन्यथा
        {
            /* file info: full path + filename */
            pstrcat(buf, आकार(buf), "/");
            section_sym = put_elf_sym(symtab_section, 0, 0,
                                      ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                      text_section->sh_अंक, रिक्त);
            put_stabs_r(s1, buf, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            put_stabs_r(s1, filename, N_SO, 0, 0,
                        text_section->data_offset, text_section, section_sym);
            साठी (i = 0; i < N_DEFAULT_DEBUG; i++)
                put_stabs(s1, default_debug[i].name, N_LSYM, 0, 0, 0);
        }
        /* we're currently 'including' the <command line> */
        tcc_debug_bincl(s1);
    }
}

स्थिर शून्य fix_debug_forw_hash(TCCState *s1, पूर्णांक global, पूर्णांक start);

/* put end of translation unit info */
ST_FUNC शून्य tcc_debug_end(TCCState *s1)
{

    जर (!s1->do_debug || debug_next_type == 0)
        परत;

    जर (debug_info_मूळ)
        tcc_debug_funcend(s1, 0); /* free stuff in case of errors */

    जर (s1->dwarf) {
	पूर्णांक i;
	पूर्णांक start_aranges;
	अचिन्हित अक्षर *ptr;
	पूर्णांक text_size = text_section->data_offset;

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
#जर PTR_SIZE == 4
	dwarf_data1(dwarf_aranges_section, 4); // address size
#अन्यथा
	dwarf_data1(dwarf_aranges_section, 8); // address size
#endif
	dwarf_data1(dwarf_aranges_section, 0); // segment selector size
	dwarf_data4(dwarf_aranges_section, 0); // padding
	dwarf_reloc(dwarf_aranges_section, section_sym, R_DATA_PTR);
#जर PTR_SIZE == 4
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
	जर (s1->dwarf >= 5) {
	    dwarf_data1(dwarf_ओळ_section, 1); /* col */
	    dwarf_uleb128(dwarf_ओळ_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_ओळ_section, DW_FORM_ओळ_strp);
	    dwarf_uleb128(dwarf_ओळ_section, dwarf_ओळ.dir_size);
	    साठी (i = 0; i < dwarf_ओळ.dir_size; i++)
	        dwarf_ओळ_strp(dwarf_ओळ_section, dwarf_ओळ.dir_table[i]);
	    dwarf_data1(dwarf_ओळ_section, 2); /* col */
	    dwarf_uleb128(dwarf_ओळ_section, DW_LNCT_path);
	    dwarf_uleb128(dwarf_ओळ_section, DW_FORM_ओळ_strp);
	    dwarf_uleb128(dwarf_ओळ_section, DW_LNCT_directory_index);
	    dwarf_uleb128(dwarf_ओळ_section, DW_FORM_udata);
	    dwarf_uleb128(dwarf_ओळ_section, dwarf_ओळ.filename_size);
	    साठी (i = 0; i < dwarf_ओळ.filename_size; i++) {
	        dwarf_ओळ_strp(dwarf_ओळ_section,
				dwarf_ओळ.filename_table[i].name);
	        dwarf_uleb128(dwarf_ओळ_section,
			      dwarf_ओळ.filename_table[i].dir_entry);
	    }
	}
	अन्यथा {
	    पूर्णांक len;

	    साठी (i = 0; i < dwarf_ओळ.dir_size; i++) {
	        len = म_माप(dwarf_ओळ.dir_table[i]) + 1;
	        ptr = section_ptr_add(dwarf_ओळ_section, len);
	        स_हटाओ(ptr, dwarf_ओळ.dir_table[i], len);
	    }
	    dwarf_data1(dwarf_ओळ_section, 0); /* end dir */
	    साठी (i = 0; i < dwarf_ओळ.filename_size; i++) {
	        len = म_माप(dwarf_ओळ.filename_table[i].name) + 1;
	        ptr = section_ptr_add(dwarf_ओळ_section, len);
	        स_हटाओ(ptr, dwarf_ओळ.filename_table[i].name, len);
	        dwarf_uleb128(dwarf_ओळ_section,
			      dwarf_ओळ.filename_table[i].dir_entry);
	        dwarf_uleb128(dwarf_ओळ_section, 0); /* time */
	        dwarf_uleb128(dwarf_ओळ_section, 0); /* size */
	    }
	    dwarf_data1(dwarf_ओळ_section, 0); /* end file */
	}
	साठी (i = 0; i < dwarf_ओळ.dir_size; i++)
	    tcc_free(dwarf_ओळ.dir_table[i]);
	tcc_free(dwarf_ओळ.dir_table);
	साठी (i = 0; i < dwarf_ओळ.filename_size; i++)
	    tcc_free(dwarf_ओळ.filename_table[i].name);
	tcc_free(dwarf_ओळ.filename_table);

	dwarf_ओळ_op(s1, 0); // extended
	dwarf_uleb128_op(s1, 1); // extended size
	dwarf_ओळ_op(s1, DW_LNE_end_sequence);
	i = (s1->dwarf >= 5) * 2;
	write32le(&dwarf_ओळ_section->data[dwarf_ओळ.start + 6 + i],
		  dwarf_ओळ_section->data_offset - dwarf_ओळ.start - (10 + i));
	section_ptr_add(dwarf_ओळ_section, 3);
	dwarf_reloc(dwarf_ओळ_section, section_sym, R_DATA_PTR);
	ptr = section_ptr_add(dwarf_ओळ_section, dwarf_ओळ.ओळ_size - 3);
	स_हटाओ(ptr - 3, dwarf_ओळ.ओळ_data, dwarf_ओळ.ओळ_size);
	tcc_free(dwarf_ओळ.ओळ_data);
	write32le(dwarf_ओळ_section->data + dwarf_ओळ.start,
		  dwarf_ओळ_section->data_offset - dwarf_ओळ.start - 4);
    }
    अन्यथा
    {
        put_stabs_r(s1, रिक्त, N_SO, 0, 0,
                    text_section->data_offset, text_section, section_sym);
    }
    free_str (dwarf_str);
    free_str (dwarf_ओळ_str);
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
    जर (f->filename[0] == ':')
        f = f->prev;
    जर (f && new_file) {
        new_file = last_ओळ_अंक = 0;
        जर (s1->dwarf)
            dwarf_file(s1);
        अन्यथा
            put_stabs_r(s1, f->filename, N_SOL, 0, 0, ind, text_section, section_sym);
    }
    परत f;
}

/* put alternative filename */
ST_FUNC शून्य tcc_debug_newfile(TCCState *s1)
{
    जर (!s1->do_debug)
        परत;
    जर (s1->dwarf)
        dwarf_file(s1);
    new_file = 1;
}

/* begin of #include */
ST_FUNC शून्य tcc_debug_bincl(TCCState *s1)
{
    जर (!s1->do_debug)
        परत;
    जर (s1->dwarf)
        dwarf_file(s1);
    अन्यथा
        put_stabs(s1, file->filename, N_BINCL, 0, 0, 0);
    new_file = 1;
}

/* end of #include */
ST_FUNC शून्य tcc_debug_eincl(TCCState *s1)
{
    जर (!s1->do_debug)
        परत;
    जर (s1->dwarf)
        dwarf_file(s1);
    अन्यथा
        put_stabn(s1, N_EINCL, 0, 0, 0);
    new_file = 1;
}

/* generate line number info */
ST_FUNC शून्य tcc_debug_ओळ(TCCState *s1)
{
    BufferedFile *f;

    जर (!s1->do_debug)
        परत;
    जर (cur_text_section != text_section || nocode_wanted)
        परत;
    f = put_new_file(s1);
    जर (!f)
        परत;
    जर (last_ओळ_अंक == f->ओळ_अंक)
        परत;
    last_ओळ_अंक = f->ओळ_अंक;

    जर (s1->dwarf) {
	पूर्णांक len_pc = (ind - dwarf_ओळ.last_pc) / DWARF_MIN_INSTR_LEN;
	पूर्णांक len_ओळ = f->ओळ_अंक - dwarf_ओळ.last_ओळ;
	पूर्णांक n = len_pc * DWARF_ओळ_RANGE + len_ओळ + DWARF_OPCODE_BASE - DWARF_ओळ_BASE;

	जर (dwarf_ओळ.cur_file != dwarf_ओळ.last_file) {
	    dwarf_ओळ.last_file = dwarf_ओळ.cur_file;
	    dwarf_ओळ_op(s1, DW_LNS_set_file);
	    dwarf_uleb128_op(s1, dwarf_ओळ.cur_file);
	}
	जर (len_pc &&
	    len_ओळ >= DWARF_ओळ_BASE && len_ओळ <= (DWARF_OPCODE_BASE + DWARF_ओळ_BASE) &&
	    n >= DWARF_OPCODE_BASE && n <= 255)
            dwarf_ओळ_op(s1, n);
	अन्यथा {
	    जर (len_pc) {
	        n = len_pc * DWARF_ओळ_RANGE + 0 + DWARF_OPCODE_BASE - DWARF_ओळ_BASE;
	        जर (n >= DWARF_OPCODE_BASE && n <= 255)
                    dwarf_ओळ_op(s1, n);
		अन्यथा {
	            dwarf_ओळ_op(s1, DW_LNS_advance_pc);
		    dwarf_uleb128_op(s1, len_pc);
		}
	    }
	    जर (len_ओळ) {
	        n = 0 * DWARF_ओळ_RANGE + len_ओळ + DWARF_OPCODE_BASE - DWARF_ओळ_BASE;
	        जर (len_ओळ >= DWARF_ओळ_BASE && len_ओळ <= (DWARF_OPCODE_BASE + DWARF_ओळ_BASE) &&
		    n >= DWARF_OPCODE_BASE && n <= 255)
	            dwarf_ओळ_op(s1, n);
		अन्यथा {
	            dwarf_ओळ_op(s1, DW_LNS_advance_ओळ);
		    dwarf_sleb128_op(s1, len_ओळ);
                    /* advance by nothing */
	            dwarf_ओळ_op(s1, DWARF_OPCODE_BASE - DWARF_ओळ_BASE);
		}
	    }
	}
	dwarf_ओळ.last_pc = ind;
	dwarf_ओळ.last_ओळ = f->ओळ_अंक;
    }
    अन्यथा
    {
	जर (func_ind != -1) {
            put_stabn(s1, N_SLINE, 0, f->ओळ_अंक, ind - func_ind);
        } अन्यथा {
            /* from tcc_assemble */
            put_stabs_r(s1, रिक्त, N_SLINE, 0, f->ओळ_अंक, ind, text_section, section_sym);
        }
    }
}

स्थिर शून्य tcc_debug_stabs (TCCState *s1, स्थिरांक अक्षर *str, पूर्णांक type, अचिन्हित दीर्घ मूल्य,
                             Section *sec, पूर्णांक sym_index, पूर्णांक info)
{
    संरचना debug_sym *s;

    जर (debug_info) {
        debug_info->sym =
            (संरचना debug_sym *)tcc_realloc (debug_info->sym,
                                             आकार(संरचना debug_sym) *
                                             (debug_info->n_sym + 1));
        s = debug_info->sym + debug_info->n_sym++;
        s->type = type;
        s->मूल्य = मूल्य;
        s->str = tcc_strdup(str);
        s->sec = sec;
        s->sym_index = sym_index;
        s->info = info;
        s->file = dwarf_ओळ.cur_file;
        s->ओळ = file->ओळ_अंक;
    }
    अन्यथा जर (sec)
        put_stabs_r (s1, str, type, 0, 0, मूल्य, sec, sym_index);
    अन्यथा
        put_stabs (s1, str, type, 0, 0, मूल्य);
}

स्थिर शून्य fix_debug_forw_hash(TCCState *s1, पूर्णांक global, पूर्णांक start)
{
    जर (s1->dwarf) {
        पूर्णांक i, j, n_hash = global
		    ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	संरचना _debug_forw_hash *hash = global
	  ? debug_forw_hash_global : debug_forw_hash_local;

	साठी (i = start; i < n_hash; i++) {
	    Sym *t = hash[i].type;
	    पूर्णांक pos = dwarf_info_section->data_offset;

	    dwarf_data1(dwarf_info_section,
                        IS_UNION (t->type.t) ? DWARF_ABBREV_UNION_EMPTY_TYPE
                                             : DWARF_ABBREV_STRUCTURE_EMPTY_TYPE);
            dwarf_strp(dwarf_info_section,
                       (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                       ? "" : get_tok_str(t->v, रिक्त));
            dwarf_uleb128(dwarf_info_section, 0);
            dwarf_uleb128(dwarf_info_section, dwarf_ओळ.cur_file);
            dwarf_uleb128(dwarf_info_section, file->ओळ_अंक);
	    साठी (j = 0; j < hash[i].n_debug_type; j++)
		write32le(dwarf_info_section->data +
			  hash[i].debug_type[j],
			  pos - dwarf_info.start);
	    tcc_free (hash[i].debug_type);
	}
    }
}

ST_FUNC शून्य tcc_debug_stabn(TCCState *s1, पूर्णांक type, पूर्णांक मूल्य)
{
    जर (!s1->do_debug)
        परत;
    जर (type == N_LBRAC) {
        संरचना _debug_info *info =
            (संरचना _debug_info *) tcc_mallocz(आकार (*info));

        info->start = मूल्य;
        info->last_debug_hash = n_debug_hash_local;
        info->last_debug_forw_hash = n_debug_forw_hash_local;
        info->parent = debug_info;
        जर (debug_info) {
            जर (debug_info->child) {
                जर (debug_info->child->last)
                    debug_info->child->last->next = info;
                अन्यथा
                    debug_info->child->next = info;
                debug_info->child->last = info;
            }
            अन्यथा
                debug_info->child = info;
        }
        अन्यथा
            debug_info_मूळ = info;
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

स्थिर पूर्णांक check_global(Sym *t)
{
    Sym *g = local_चळत;

    पर्यंत (g) {
	जर (t == g)
	    परत 0;
	g = g->prev;
    }
    परत 1;
}

स्थिर पूर्णांक tcc_debug_find(TCCState *s1, Sym *t, पूर्णांक dwarf)
{
    पूर्णांक i , g = check_global(t);
    पूर्णांक n_hash, *n_forw_hash;
    संरचना _debug_hash *hash;
    संरचना _debug_forw_hash **forw_hash;

    जर ((t->type.t & VT_BTYPE) == VT_STRUCT && t->c == -1) {
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	साठी (i = 0; i < *n_forw_hash; i++)
            जर (t == (*forw_hash)[i].type)
		परत 0;
	*forw_hash = (संरचना _debug_forw_hash *)
            tcc_realloc (*forw_hash,
                         (*n_forw_hash + 1) * आकार(**forw_hash));
        (*forw_hash)[*n_forw_hash].n_debug_type = 0;
        (*forw_hash)[*n_forw_hash].debug_type = रिक्त;
        (*forw_hash)[(*n_forw_hash)++].type = t;
	परत 0;
    }
    hash = g ? debug_hash_global : debug_hash_local;
    n_hash = g ? n_debug_hash_global : n_debug_hash_local;
    साठी (i = 0; i < n_hash; i++)
        जर (t == hash[i].type)
	    परत hash[i].debug_type;
    परत -1;
}

स्थिर पूर्णांक tcc_get_dwarf_info(TCCState *s1, Sym *s);

स्थिर शून्य tcc_debug_check_forw(TCCState *s1, Sym *t, पूर्णांक debug_type)
{
    जर ((t->type.t & VT_BTYPE) == VT_STRUCT && t->type.ref->c == -1) {
        पूर्णांक i, j, g = check_global(t);
        पूर्णांक n_forw_hash;
        संरचना _debug_forw_hash **forw_hash;

	साठी (i = g; i <= 1; i++) {
            forw_hash = i ? &debug_forw_hash_global : &debug_forw_hash_local;
            n_forw_hash = i ? n_debug_forw_hash_global : n_debug_forw_hash_local;
	    साठी (j = 0; j < n_forw_hash; j++)
                जर (t->type.ref == (*forw_hash)[j].type) {
		    (*forw_hash)[j].debug_type =
		        tcc_realloc((*forw_hash)[j].debug_type,
				    ((*forw_hash)[j].n_debug_type + 1) * आकार(पूर्णांक));
		    (*forw_hash)[j].debug_type[(*forw_hash)[j].n_debug_type++] =
		        debug_type;
		    परत;
                }
	}
    }
}

स्थिर शून्य stabs_struct_complete(TCCState *s1, CType *t);

ST_FUNC शून्य tcc_debug_fix_forw(TCCState *s1, CType *t)
{
    जर (!(s1->do_debug & 2))
	परत;
    जर (0 == s1->dwarf) {
        stabs_struct_complete(s1, t);
        परत;
    }
    जर ((t->t & VT_BTYPE) == VT_STRUCT && t->ref->c != -1) {
        पूर्णांक i, j, debug_type, g = check_global(t->ref);
        पूर्णांक *n_forw_hash;
        संरचना _debug_forw_hash **forw_hash;
        forw_hash = g ? &debug_forw_hash_global : &debug_forw_hash_local;
        n_forw_hash = g ? &n_debug_forw_hash_global : &n_debug_forw_hash_local;
	साठी (i = 0; i < *n_forw_hash; i++)
	    जर (t->ref == (*forw_hash)[i].type) {
		जर (s1->dwarf) {
		    Sym sym = {0}; sym .type = *t ;

		    debug_type = tcc_get_dwarf_info(s1, &sym);
		    साठी (j = 0; j < (*forw_hash)[i].n_debug_type; j++)
		        write32le(dwarf_info_section->data +
			          (*forw_hash)[i].debug_type[j],
			          debug_type - dwarf_info.start);
		    tcc_free((*forw_hash)[i].debug_type);
		}
		(*n_forw_hash)--;
		साठी (; i < *n_forw_hash; i++)
		    (*forw_hash)[i] = (*forw_hash)[i + 1];
	    }
    }
}

स्थिर पूर्णांक tcc_debug_add(TCCState *s1, Sym *t, पूर्णांक dwarf)
{
    पूर्णांक offset = dwarf ? dwarf_info_section->data_offset : ++debug_next_type;
    पूर्णांक *n_hash, g = check_global(t);
    संरचना _debug_hash **hash;

    hash = g ? &debug_hash_global : &debug_hash_local;
    n_hash = g ? &n_debug_hash_global : &n_debug_hash_local;
    *hash = (संरचना _debug_hash *)
	tcc_realloc (*hash,
		     (*n_hash + 1) * आकार(**hash));
    (*hash)[*n_hash].debug_type = offset;
    (*hash)[(*n_hash)++].type = t;
    परत offset;
}

स्थिर पूर्णांक STRUCT_NODEBUG(Sym *s)
{
    परत
    (s->a.nodebug ||
     ((s->v & ~SYM_FIELD) >= SYM_FIRST_ANOM &&
      ((s->type.t & VT_BTYPE) == VT_BYTE ||
       (s->type.t & VT_BTYPE) == VT_BOOL ||
       (s->type.t & VT_BTYPE) == VT_SHORT ||
       (s->type.t & VT_BTYPE) == VT_INT ||
       (s->type.t & VT_BTYPE) == VT_LLONG)));
}

स्थिर पूर्णांक stabs_struct_find(TCCState *s1, Sym *t, पूर्णांक *p_id)
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
    जर (रिक्त == p_id)
        परत s && !s->r && t->c >= 0;
    जर (रिक्त == s) {
        /* just use global_stack always */
        s = sym_push2(&global_चळत, SYM_FIELD|0x00DEBBED, 0, ++debug_next_type);
        t->type.ref = s;
    }
    *p_id = s->c;
    जर (s->r || t->c < 0) /* already defined or still incomplete */
        परत 0;
    s->r = 1;
    परत 1;
}

स्थिर पूर्णांक remove_type_info(पूर्णांक type)
{
        type &= ~(VT_STORAGE | VT_QUAL | VT_VLA);
        जर ((type & VT_BTYPE) != VT_BYTE)
            type &= ~VT_DEFSIGN;
        जर (!(type & VT_BITFIELD) && (type & VT_STRUCT_MASK) > VT_ENUM)
	    type &= ~VT_STRUCT_MASK;
	परत type;
}

स्थिर शून्य tcc_get_debug_info(TCCState *s1, Sym *s, CString *result)
{
    पूर्णांक type;
    पूर्णांक n = 0;
    पूर्णांक debug_type = -1;
    Sym *t = s;
    CString str;

    साठी (;;) {
        type = remove_type_info (t->type.t);
        जर (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            n++, t = t->type.ref;
        अन्यथा
            थांबा;
    }
    जर ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
        जर (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=%c%d",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, रिक्त),
                         debug_type,
                         IS_UNION (t->type.t) ? 'u' : 's',
                         t->c);

            पर्यंत (t->next) {
                पूर्णांक pos, size, align;
                t = t->next;
		जर (STRUCT_NODEBUG(t))
		    सुरूठेवा;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, रिक्त)
                             );
                tcc_get_debug_info (s1, t, &str);
                जर (t->type.t & VT_BITFIELD) {
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
    अन्यथा जर (IS_ENUM(type)) {
        Sym *e = t = t->type.ref;
        जर (stabs_struct_find(s1, t, &debug_type)) {
            cstr_new (&str);
            cstr_printf (&str, "%s:T%d=e",
                         (t->v & ~SYM_STRUCT) >= SYM_FIRST_ANOM
                         ? "" : get_tok_str(t->v, रिक्त),
                         debug_type);
            पर्यंत (t->next) {
                t = t->next;
                cstr_printf (&str, "%s:",
                             (t->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                             ? "" : get_tok_str(t->v, रिक्त));
                cstr_printf (&str, e->type.t & VT_UNSIGNED ? "%u," : "%d,",
                             (पूर्णांक)t->enum_val);
            }
            cstr_printf (&str, ";");
            tcc_debug_stabs(s1, str.data, N_LSYM, 0, रिक्त, 0, 0);
            cstr_free (&str);
	}
    }
    अन्यथा जर ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        साठी (debug_type = 1; debug_type <= N_DEFAULT_DEBUG; debug_type++)
            जर (default_debug[debug_type - 1].type == type)
                थांबा;
        जर (debug_type > N_DEFAULT_DEBUG)
            परत;
    }

    जर (रिक्त == result) /* from stabs_struct_complete() */
        परत;

    जर (n > 0)
        cstr_printf (result, "%d=", ++debug_next_type);
    t = s;
    साठी (;;) {
        type = remove_type_info (t->type.t);
        जर (type == VT_PTR)
            cstr_printf (result, "%d=*", ++debug_next_type);
        अन्यथा जर (type == (VT_PTR | VT_ARRAY))
            cstr_printf (result, "%d=ar1;0;%d;",
                         ++debug_next_type, t->type.ref->c - 1);
        अन्यथा जर (type == VT_FUNC) {
            cstr_printf (result, "%d=f", ++debug_next_type);
            tcc_get_debug_info (s1, t->type.ref, result);
            परत;
        }
        अन्यथा
            थांबा;
        t = t->type.ref;
    }
    cstr_printf (result, "%d", debug_type);
}

स्थिर शून्य stabs_struct_complete(TCCState *s1, CType *t)
{
    जर (stabs_struct_find(s1, t->ref, रिक्त)) {
        Sym s = {0}; s.type = *t;
        tcc_get_debug_info(s1, &s, रिक्त);
    }
}

स्थिर पूर्णांक tcc_get_dwarf_info(TCCState *s1, Sym *s)
{
    पूर्णांक type;
    पूर्णांक debug_type = -1;
    Sym *e, *t = s;
    पूर्णांक i;
    पूर्णांक last_pos = -1;
    पूर्णांक retval;

    जर (new_file)
        put_new_file(s1);
    साठी (;;) {
        type = remove_type_info (t->type.t);
        जर (type == VT_PTR || type == (VT_PTR | VT_ARRAY))
            t = t->type.ref;
        अन्यथा
            थांबा;
    }
    जर ((type & VT_BTYPE) == VT_STRUCT) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	जर (debug_type == -1) {
	    पूर्णांक pos_sib = 0, i, *pos_type;

	    debug_type = tcc_debug_add(s1, t, 1);
	    e = t;
	    i = 0;
	    पर्यंत (e->next) {
		e = e->next;
		जर (STRUCT_NODEBUG(e))
		    सुरूठेवा;
		i++;
	    }
	    pos_type = (पूर्णांक *) tcc_malloc(i * आकार(पूर्णांक));
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
	    dwarf_uleb128(dwarf_info_section, dwarf_ओळ.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ओळ_अंक);
	    जर (t->next) {
	        pos_sib = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    e = t;
	    i = 0;
            पर्यंत (e->next) {
                e = e->next;
		जर (STRUCT_NODEBUG(e))
		    सुरूठेवा;
	        dwarf_data1(dwarf_info_section,
			    e->type.t & VT_BITFIELD ? DWARF_ABBREV_MEMBER_BF
						    : DWARF_ABBREV_MEMBER);
		dwarf_strp(dwarf_info_section,
			   get_tok_str(e->v, रिक्त));
		dwarf_uleb128(dwarf_info_section, dwarf_ओळ.cur_file);
		dwarf_uleb128(dwarf_info_section, file->ओळ_अंक);
		pos_type[i++] = dwarf_info_section->data_offset;
		dwarf_data4(dwarf_info_section, 0);
                जर (e->type.t & VT_BITFIELD) {
                    पूर्णांक pos = e->c * 8 + BIT_POS(e->type.t);
                    पूर्णांक size = BIT_SIZE(e->type.t);

		    dwarf_uleb128(dwarf_info_section, size);
		    dwarf_uleb128(dwarf_info_section, pos);
		}
		अन्यथा
		    dwarf_uleb128(dwarf_info_section, e->c);
	    }
	    जर (t->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + pos_sib,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    e = t;
	    i = 0;
	    पर्यंत (e->next) {
		e = e->next;
		जर (STRUCT_NODEBUG(e))
		    सुरूठेवा;
		type = tcc_get_dwarf_info(s1, e);
		tcc_debug_check_forw(s1, e, pos_type[i]);
		write32le(dwarf_info_section->data + pos_type[i++],
			  type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
    }
    अन्यथा जर (IS_ENUM(type)) {
        t = t->type.ref;
	debug_type = tcc_debug_find(s1, t, 1);
	जर (debug_type == -1) {
	    पूर्णांक pos_sib, pos_type;
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
	    dwarf_uleb128(dwarf_info_section, dwarf_ओळ.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ओळ_अंक);
	    pos_sib = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    e = t;
            पर्यंत (e->next) {
                e = e->next;
	        dwarf_data1(dwarf_info_section,
			type & VT_UNSIGNED ? DWARF_ABBREV_ENUMERATOR_UNSIGNED
					   : DWARF_ABBREV_ENUMERATOR_SIGNED);
	        dwarf_strp(dwarf_info_section,
                           (e->v & ~SYM_FIELD) >= SYM_FIRST_ANOM
                           ? "" : get_tok_str(e->v, रिक्त));
		जर (type & VT_UNSIGNED)
	            dwarf_uleb128(dwarf_info_section, e->enum_val);
		अन्यथा
	            dwarf_sleb128(dwarf_info_section, e->enum_val);
            }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + pos_sib,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
    }
    अन्यथा जर ((type & VT_BTYPE) != VT_FUNC) {
        type &= ~VT_STRUCT_MASK;
        साठी (i = 1; i <= N_DEFAULT_DEBUG; i++)
            जर (default_debug[i - 1].type == type)
                थांबा;
        जर (i > N_DEFAULT_DEBUG)
            परत 0;
	debug_type = dwarf_info.base_type_used[i - 1];
	जर (debug_type == 0) {
	    अक्षर name[100];

	    debug_type = dwarf_info_section->data_offset;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_BASE_TYPE);
	    dwarf_uleb128(dwarf_info_section, default_debug[i - 1].size);
	    dwarf_data1(dwarf_info_section, default_debug[i - 1].encoding);
	    pstrcpy(name, आकार name, default_debug[i - 1].name);
	    *म_अक्षर(name, ':') = 0;
	    dwarf_strp(dwarf_info_section, name);
	    dwarf_info.base_type_used[i - 1] = debug_type;
	}
    }
    retval = debug_type;
    e = रिक्त;
    t = s;
    साठी (;;) {
        type = remove_type_info (t->type.t);
        जर (type == VT_PTR) {
	    i = dwarf_info_section->data_offset;
	    जर (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_POINTER);
	    dwarf_data1(dwarf_info_section, PTR_SIZE);
	    जर (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	}
        अन्यथा जर (type == (VT_PTR | VT_ARRAY)) {
	    पूर्णांक sib_pos, sub_type;
#जर LONG_SIZE == 4
	    Sym sym = {0}; sym.type.t = VT_LONG | VT_INT | VT_UNSIGNED;
#अन्यथा
	    Sym sym = {0}; sym.type.t = VT_LLONG | VT_LONG | VT_UNSIGNED;
#endif

	    sub_type = tcc_get_dwarf_info(s1, &sym);
	    i = dwarf_info_section->data_offset;
	    जर (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_ARRAY_TYPE);
	    जर (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    sib_pos = dwarf_info_section->data_offset;
	    dwarf_data4(dwarf_info_section, 0);
	    साठी (;;) {
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_SUBRANGE_TYPE);
	        dwarf_data4(dwarf_info_section, sub_type - dwarf_info.start);
	        dwarf_uleb128(dwarf_info_section, t->type.ref->c - 1);
		s = t->type.ref;
		type = s->type.t & ~(VT_STORAGE | VT_QUAL);
		जर (type != (VT_PTR | VT_ARRAY))
		    थांबा;
		t = s;
	    }
	    dwarf_data1(dwarf_info_section, 0);
	    write32le(dwarf_info_section->data + sib_pos,
		      dwarf_info_section->data_offset - dwarf_info.start);
	}
        अन्यथा जर (type == VT_FUNC) {
	    पूर्णांक sib_pos = 0, *pos_type;
	    Sym *f;

	    i = dwarf_info_section->data_offset;
	    debug_type = tcc_get_dwarf_info(s1, t->type.ref);
	    जर (retval == debug_type)
		retval = i;
	    dwarf_data1(dwarf_info_section,
			t->type.ref->next ? DWARF_ABBREV_SUBROUTINE_TYPE
					  : DWARF_ABBREV_SUBROUTINE_EMPTY_TYPE);
	    जर (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  i - dwarf_info.start);
	    }
	    last_pos = dwarf_info_section->data_offset;
	    e = t->type.ref;
	    dwarf_data4(dwarf_info_section, 0);
	    जर (t->type.ref->next) {
	        sib_pos = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    f = t->type.ref;
	    i = 0;
	    पर्यंत (f->next) {
		f = f->next;
		i++;
	    }
	    pos_type = (पूर्णांक *) tcc_malloc(i * आकार(पूर्णांक));
	    f = t->type.ref;
	    i = 0;
	    पर्यंत (f->next) {
		f = f->next;
	        dwarf_data1(dwarf_info_section, DWARF_ABBREV_FORMAL_PARAMETER2);
		pos_type[i++] = dwarf_info_section->data_offset;
	        dwarf_data4(dwarf_info_section, 0);
	    }
	    जर (t->type.ref->next) {
	        dwarf_data1(dwarf_info_section, 0);
	        write32le(dwarf_info_section->data + sib_pos,
		          dwarf_info_section->data_offset - dwarf_info.start);
	    }
	    f = t->type.ref;
	    i = 0;
	    पर्यंत (f->next) {
		f = f->next;
		type = tcc_get_dwarf_info(s1, f);
		tcc_debug_check_forw(s1, f, pos_type[i]);
	        write32le(dwarf_info_section->data + pos_type[i++],
                          type - dwarf_info.start);
	    }
	    tcc_free(pos_type);
        }
        अन्यथा {
	    जर (last_pos != -1) {
		tcc_debug_check_forw(s1, e, last_pos);
		write32le(dwarf_info_section->data + last_pos,
			  debug_type - dwarf_info.start);
	    }
            थांबा;
	}
        t = t->type.ref;
    }
    परत retval;
}

स्थिर शून्य tcc_debug_finish (TCCState *s1, संरचना _debug_info *cur)
{
    पर्यंत (cur) {
        संरचना _debug_info *next = cur->next;
        पूर्णांक i;

        जर (s1->dwarf) {

            साठी (i = cur->n_sym - 1; i >= 0; i--) {
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
		जर (s->type == N_GSYM || s->type == N_STSYM) {
                    dwarf_uleb128(dwarf_info_section, s->file);
                    dwarf_uleb128(dwarf_info_section, s->ओळ);
		}
                dwarf_data4(dwarf_info_section, s->info - dwarf_info.start);
		जर (s->type == N_GSYM || s->type == N_STSYM) {
		    /* global/static */
		    जर (s->type == N_GSYM)
                        dwarf_data1(dwarf_info_section, 1);
                    dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_addr);
		    जर (s->type == N_STSYM)
		        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#जर PTR_SIZE == 4
                    dwarf_data4(dwarf_info_section, s->मूल्य);
#अन्यथा
                    dwarf_data8(dwarf_info_section, s->मूल्य);
#endif
		}
		अन्यथा {
		    /* param/local */
                    dwarf_data1(dwarf_info_section, dwarf_sleb128_size((दीर्घ)s->मूल्य) + 1);
                    dwarf_data1(dwarf_info_section, DW_OP_fbreg);
                    dwarf_sleb128(dwarf_info_section, (दीर्घ)s->मूल्य);
		}
		tcc_free (s->str);
            }
            tcc_free (cur->sym);
            dwarf_data1(dwarf_info_section,
			cur->child ? DWARF_ABBREV_LEXICAL_BLOCK
			           : DWARF_ABBREV_LEXICAL_EMPTY_BLOCK);
            dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#जर PTR_SIZE == 4
            dwarf_data4(dwarf_info_section, func_ind + cur->start);
            dwarf_data4(dwarf_info_section, cur->end - cur->start);
#अन्यथा
            dwarf_data8(dwarf_info_section, func_ind + cur->start);
            dwarf_data8(dwarf_info_section, cur->end - cur->start);
#endif
            tcc_debug_finish (s1, cur->child);
	    जर (cur->child)
                dwarf_data1(dwarf_info_section, 0);
        }
        अन्यथा
        {
            साठी (i = 0; i < cur->n_sym; i++) {
                संरचना debug_sym *s = &cur->sym[i];

                जर (s->sec)
                    put_stabs_r(s1, s->str, s->type, 0, 0, s->मूल्य,
                                s->sec, s->sym_index);
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
        cur = next;
    }
}

ST_FUNC शून्य tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e)
{
    CString debug_str;
    पूर्णांक param;

    जर (!(s1->do_debug & 2))
        परत;

    cstr_new (&debug_str);
    param = !e;
    साठी (; s != e; s = s->prev) {
        जर (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
            सुरूठेवा;
	जर (s1->dwarf) {
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

    जर (!s1->do_debug)
        परत;
    debug_info_मूळ = रिक्त;
    debug_info = रिक्त;
    tcc_debug_stabn(s1, N_LBRAC, ind - func_ind);
    f = put_new_file(s1);
    जर (!f)
	परत;

    जर (s1->dwarf) {
        tcc_debug_ओळ(s1);
        dwarf_info.func = sym;
        dwarf_info.ओळ = file->ओळ_अंक;
	जर (s1->do_backtrace) {
	    पूर्णांक i, len;

	    dwarf_ओळ_op(s1, 0); // extended
	    dwarf_uleb128_op(s1, म_माप(funcname) + 2);
	    dwarf_ओळ_op(s1, DW_LNE_hi_user - 1);
	    len = म_माप(funcname) + 1;
	    साठी (i = 0; i < len; i++)
		dwarf_ओळ_op(s1, funcname[i]);
	}
    }
    अन्यथा
    {
        cstr_new (&debug_str);
        cstr_printf(&debug_str, "%s:%c", funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
        tcc_get_debug_info(s1, sym->type.ref, &debug_str);
        put_stabs_r(s1, debug_str.data, N_FUN, 0, f->ओळ_अंक, 0, cur_text_section, sym->c);
        cstr_free (&debug_str);
        tcc_debug_ओळ(s1);
    }
}

ST_FUNC शून्य tcc_debug_prolog_epilog(TCCState *s1, पूर्णांक मूल्य)
{
    जर (!s1->do_debug)
        परत;
    जर (s1->dwarf) {
	dwarf_ओळ_op(s1, मूल्य == 0 ? DW_LNS_set_prologue_end
				     : DW_LNS_set_epilogue_begin);
    }
}

/* put function size */
ST_FUNC शून्य tcc_debug_funcend(TCCState *s1, पूर्णांक size)
{
    /* lldb does not like function end and next function start at same pc */
    पूर्णांक min_instr_len;

#जर TCC_EH_FRAME
    tcc_debug_frame_end(s1, size);
#endif
    जर (!s1->do_debug)
        परत;
    min_instr_len = dwarf_ओळ.last_pc == ind ? 0 : DWARF_MIN_INSTR_LEN;
    ind -= min_instr_len;
    tcc_debug_ओळ(s1);
    ind += min_instr_len;
    tcc_debug_stabn(s1, N_RBRAC, size);
    जर (s1->dwarf) {
        पूर्णांक func_sib = 0;
	Sym *sym = dwarf_info.func;
	पूर्णांक n_debug_info = tcc_get_dwarf_info(s1, sym->type.ref);

        dwarf_data1(dwarf_info_section,
	    sym->type.t & VT_STATIC ? DWARF_ABBREV_SUBPROGRAM_STATIC
				    : DWARF_ABBREV_SUBPROGRAM_EXTERNAL);
        जर ((sym->type.t & VT_STATIC) == 0)
            dwarf_data1(dwarf_info_section, 1);
        dwarf_strp(dwarf_info_section, funcname);
        dwarf_uleb128(dwarf_info_section, dwarf_ओळ.cur_file);
        dwarf_uleb128(dwarf_info_section, dwarf_info.ओळ);
	tcc_debug_check_forw(s1, sym->type.ref, dwarf_info_section->data_offset);
        dwarf_data4(dwarf_info_section, n_debug_info - dwarf_info.start);
        dwarf_reloc(dwarf_info_section, section_sym, R_DATA_PTR);
#जर PTR_SIZE == 4
        dwarf_data4(dwarf_info_section, func_ind); // low_pc
        dwarf_data4(dwarf_info_section, size); // high_pc
#अन्यथा
        dwarf_data8(dwarf_info_section, func_ind); // low_pc
        dwarf_data8(dwarf_info_section, size); // high_pc
#endif
        func_sib = dwarf_info_section->data_offset;
        dwarf_data4(dwarf_info_section, 0); // sibling
        dwarf_data1(dwarf_info_section, 1);
#जर defined(TCC_TARGET_I386)
        dwarf_data1(dwarf_info_section, DW_OP_reg5); // ebp
#किंवाजर defined(TCC_TARGET_X86_64)
        dwarf_data1(dwarf_info_section, DW_OP_reg6); // rbp
#किंवाजर defined TCC_TARGET_ARM
        dwarf_data1(dwarf_info_section, DW_OP_reg13); // sp
#किंवाजर defined TCC_TARGET_ARM64
        dwarf_data1(dwarf_info_section, DW_OP_reg29); // reg 29
#किंवाजर defined TCC_TARGET_RISCV64
        dwarf_data1(dwarf_info_section, DW_OP_reg8); // r8(s0)
#अन्यथा
        dwarf_data1(dwarf_info_section, DW_OP_call_frame_cfa);
#endif
        tcc_debug_finish (s1, debug_info_मूळ);
	dwarf_data1(dwarf_info_section, 0);
        write32le(dwarf_info_section->data + func_sib,
                  dwarf_info_section->data_offset - dwarf_info.start);
    }
    अन्यथा
    {
        tcc_debug_finish (s1, debug_info_मूळ);
    }
    debug_info_मूळ = 0;
}


ST_FUNC शून्य tcc_debug_extern_sym(TCCState *s1, Sym *sym, पूर्णांक sh_अंक, पूर्णांक sym_bind, पूर्णांक sym_type)
{
    जर (!(s1->do_debug & 2))
        परत;

    जर (sym_type == STT_FUNC || sym->v >= SYM_FIRST_ANOM)
        परत;
    जर (s1->dwarf) {
        पूर्णांक debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	dwarf_data1(dwarf_info_section,
		    sym_bind == STB_GLOBAL
		    ? DWARF_ABBREV_VARIABLE_EXTERNAL
		    : DWARF_ABBREV_VARIABLE_STATIC);
	dwarf_strp(dwarf_info_section, get_tok_str(sym->v, रिक्त));
	dwarf_uleb128(dwarf_info_section, dwarf_ओळ.cur_file);
	dwarf_uleb128(dwarf_info_section, file->ओळ_अंक);
	tcc_debug_check_forw(s1, sym, dwarf_info_section->data_offset);
	dwarf_data4(dwarf_info_section, debug_type - dwarf_info.start);
	जर (sym_bind == STB_GLOBAL)
	    dwarf_data1(dwarf_info_section, 1);
	dwarf_data1(dwarf_info_section, PTR_SIZE + 1);
	dwarf_data1(dwarf_info_section, DW_OP_addr);
	greloca(dwarf_info_section, sym, dwarf_info_section->data_offset,
		R_DATA_PTR, 0);
#जर PTR_SIZE == 4
	dwarf_data4(dwarf_info_section, 0);
#अन्यथा
	dwarf_data8(dwarf_info_section, 0);
#endif
    }
    अन्यथा
    {
        Section *s = sh_अंक == SHN_COMMON ? common_section
					  : s1->sections[sh_अंक];
        CString str;

        cstr_new (&str);
        cstr_printf (&str, "%s:%c",
                get_tok_str(sym->v, रिक्त),
                sym_bind == STB_GLOBAL ? 'G' : func_ind != -1 ? 'V' : 'S'
                );
        tcc_get_debug_info(s1, sym, &str);
        जर (sym_bind == STB_GLOBAL)
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
    जर (!(s1->do_debug & 2))
        परत;

    जर (s1->dwarf) {
	पूर्णांक debug_type;

        debug_type = tcc_get_dwarf_info(s1, sym);
	जर (debug_type != -1) {
	    dwarf_data1(dwarf_info_section, DWARF_ABBREV_TYPEDEF);
	    dwarf_strp(dwarf_info_section, get_tok_str(sym->v, रिक्त));
	    dwarf_uleb128(dwarf_info_section, dwarf_ओळ.cur_file);
	    dwarf_uleb128(dwarf_info_section, file->ओळ_अंक);
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

ST_FUNC शून्य tcc_tcov_block_end(TCCState *s1, पूर्णांक ओळ);

ST_FUNC शून्य tcc_tcov_block_begin(TCCState *s1)
{
    SValue sv;
    शून्य *ptr;
    अचिन्हित दीर्घ last_offset = tcov_data.offset;

    tcc_tcov_block_end (tcc_state, 0);
    जर (s1->test_coverage == 0 || nocode_wanted)
	परत;

    जर (tcov_data.last_file_name == 0 ||
	म_भेद ((स्थिरांक अक्षर *)(tcov_section->data + tcov_data.last_file_name),
		file->true_filename) != 0) {
	अक्षर wd[1024];
	CString cstr;

	जर (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	जर (tcov_data.last_file_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = 0;
	cstr_new (&cstr);
	जर (file->true_filename[0] == '/') {
	    tcov_data.last_file_name = tcov_section->data_offset;
	    cstr_printf (&cstr, "%s", file->true_filename);
	}
	अन्यथा {
	    getcwd (wd, आकार(wd));
	    tcov_data.last_file_name = tcov_section->data_offset + म_माप(wd) + 1;
	    cstr_printf (&cstr, "%s/%s", wd, file->true_filename);
	}
	ptr = section_ptr_add(tcov_section, cstr.size + 1);
	म_नकल((अक्षर *)ptr, cstr.data);
#ifdef _WIN32
        normalize_slashes((अक्षर *)ptr);
#endif
	cstr_free (&cstr);
    }
    जर (tcov_data.last_func_name == 0 ||
	म_भेद ((स्थिरांक अक्षर *)(tcov_section->data + tcov_data.last_func_name),
		funcname) != 0) {
	माप_प्रकार len;

	जर (tcov_data.last_func_name)
	    section_ptr_add(tcov_section, 1);
	tcov_data.last_func_name = tcov_section->data_offset;
	len = म_माप (funcname);
	ptr = section_ptr_add(tcov_section, len + 1);
	म_नकल((अक्षर *)ptr, funcname);
	section_ptr_add(tcov_section, -tcov_section->data_offset & 7);
	ptr = section_ptr_add(tcov_section, 8);
	write64le (ptr, file->ओळ_अंक);
    }
    जर (ind == tcov_data.ind && tcov_data.ओळ == file->ओळ_अंक)
        tcov_data.offset = last_offset;
    अन्यथा {
        Sym label = {0};
        label.type.t = VT_LLONG | VT_STATIC;

        ptr = section_ptr_add(tcov_section, 16);
        tcov_data.ओळ = file->ओळ_अंक;
        write64le (ptr, (tcov_data.ओळ << 8) | 0xff);
        put_extern_sym(&label, tcov_section,
		       ((अचिन्हित अक्षर *)ptr - tcov_section->data) + 8, 0);
        sv.type = label.type;
        sv.r = VT_SYM | VT_LVAL | VT_CONST;
        sv.r2 = VT_CONST;
        sv.c.i = 0;
        sv.sym = &label;
#जर defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || \
    defined TCC_TARGET_ARM || defined TCC_TARGET_ARM64 || \
    defined TCC_TARGET_RISCV64
        gen_increment_tcov (&sv);
#अन्यथा
        vpushv(&sv);
        inc(0, TOK_INC);
        vpop();
#endif
        tcov_data.offset = (अचिन्हित अक्षर *)ptr - tcov_section->data;
        tcov_data.ind = ind;
    }
}

ST_FUNC शून्य tcc_tcov_block_end(TCCState *s1, पूर्णांक ओळ)
{
    जर (s1->test_coverage == 0)
	परत;
    जर (ओळ == -1)
        ओळ = tcov_data.ओळ;
    जर (tcov_data.offset) {
	शून्य *ptr = tcov_section->data + tcov_data.offset;
	अचिन्हित दीर्घ दीर्घ nline = ओळ ? ओळ : file->ओळ_अंक;

	write64le (ptr, (read64le (ptr) & 0xfffffffffull) | (nline << 36));
	tcov_data.offset = 0;
    }
}

ST_FUNC शून्य tcc_tcov_check_ओळ(TCCState *s1, पूर्णांक start)
{
    जर (s1->test_coverage == 0)
	परत;
    जर (tcov_data.ओळ != file->ओळ_अंक) {
        जर ((tcov_data.ओळ + 1) != file->ओळ_अंक) {
	    tcc_tcov_block_end (s1, -1);
	    जर (start)
                tcc_tcov_block_begin (s1);
	}
	अन्यथा
	    tcov_data.ओळ = file->ओळ_अंक;
    }
}

ST_FUNC शून्य tcc_tcov_start(TCCState *s1)
{
    जर (s1->test_coverage == 0)
	परत;
    जर (!s1->dState)
        s1->dState = tcc_mallocz(आकार *s1->dState);
    स_रखो (&tcov_data, 0, आकार (tcov_data));
    जर (tcov_section == रिक्त) {
        tcov_section = new_section(tcc_state, ".tcov", SHT_PROGBITS,
				   SHF_ALLOC | SHF_WRITE);
	section_ptr_add(tcov_section, 4); // pointer to executable name
    }
}

ST_FUNC शून्य tcc_tcov_end(TCCState *s1)
{
    जर (s1->test_coverage == 0)
	परत;
    जर (tcov_data.last_func_name)
        section_ptr_add(tcov_section, 1);
    जर (tcov_data.last_file_name)
        section_ptr_add(tcov_section, 1);
}

ST_FUNC शून्य tcc_tcov_reset_ind(TCCState *s1)
{
    tcov_data.ind = 0;
}

/* ------------------------------------------------------------------------- */
#undef last_ओळ_अंक
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
#undef debug_info_मूळ
#undef dwarf_sym
#undef dwarf_ओळ
#undef dwarf_info
#undef dwarf_str
#undef dwarf_ओळ_str
#undef tcov_data
