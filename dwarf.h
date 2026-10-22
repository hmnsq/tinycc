/* This file defines standard DWARF types, structures, and macros.
   Copyright (C) 2000-2011, 2014, 2016, 2017, 2018 Red Hat, Inc.
   This file is part of elfutils.

   This file is free software; you can redistribute it and/or modify
   it under the terms of either

     * the GNU Lesser General Public License as published by the Free
       Software Foundation; either version 3 of the License, or (at
       your option) any later version

   or

     * the GNU General Public License as published by the Free
       Software Foundation; either version 2 of the License, or (at
       your option) any later version

   or both in parallel, as here.

   elfutils is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received copies of the GNU General Public License and
   the GNU Lesser General Public License along with this program.  If
   not, see <http://www.gnu.org/licenses/>.  */

#که_نه_تعریف_شوی _DWARF_H
#تعریف_کړه	_DWARF_H 1

/* DWARF Unit Header Types.  */
تعداد
  {
    DW_UT_compile = 0x01,
    DW_UT_type = 0x02,
    DW_UT_partial = 0x03,
    DW_UT_skeleton = 0x04,
    DW_UT_وېشل_compile = 0x05,
    DW_UT_وېشل_type = 0x06,

    DW_UT_lo_user = 0x80,
    DW_UT_hi_user = 0xff
  };

/* DWARF tags.  */
تعداد
  {
    DW_نښان_array_type = 0x01,
    DW_نښان_class_type = 0x02,
    DW_نښان_ثبت_ټکی = 0x03,
    DW_نښان_enumeration_type = 0x04,
    DW_نښان_formal_parameter = 0x05,
    /* 0x06 reserved.  */
    /* 0x07 reserved.  */
    DW_نښان_imported_declaration = 0x08,
    /* 0x09 reserved.  */
    DW_نښان_label = 0x0a,
    DW_نښان_lexical_بلاک = 0x0b,
    /* 0x0c reserved.  */
    DW_نښان_member = 0x0d,
    /* 0x0e reserved.  */
    DW_نښان_اشاره_ګر_type = 0x0f,
    DW_نښان_reference_type = 0x10,
    DW_نښان_compile_unit = 0x11,
    DW_نښان_string_type = 0x12,
    DW_نښان_structure_type = 0x13,
    /* 0x14 reserved.  */
    DW_نښان_subroutine_type = 0x15,
    DW_نښان_typedef = 0x16,
    DW_نښان_union_type = 0x17,
    DW_نښان_unspecified_parameters = 0x18,
    DW_نښان_variant = 0x19,
    DW_نښان_common_بلاک = 0x1a,
    DW_نښان_common_inclusion = 0x1b,
    DW_نښان_inheritance = 0x1c,
    DW_نښان_inlined_subroutine = 0x1d,
    DW_نښان_module = 0x1e,
    DW_نښان_ptr_منزل_member_type = 0x1f,
    DW_نښان_سېټ_type = 0x20,
    DW_نښان_subrange_type = 0x21,
    DW_نښان_with_stmt = 0x22,
    DW_نښان_access_declaration = 0x23,
    DW_نښان_بنسټ_type = 0x24,
    DW_نښان_catch_بلاک = 0x25,
    DW_نښان_const_type = 0x26,
    DW_نښان_constant = 0x27,
    DW_نښان_enumerator = 0x28,
    DW_نښان_file_type = 0x29,
    DW_نښان_friend = 0x2a,
    DW_نښان_namelist = 0x2b,
    DW_نښان_namelist_توکی = 0x2c,
    DW_نښان_packed_type = 0x2d,
    DW_نښان_subprogram = 0x2e,
    DW_نښان_template_type_parameter = 0x2f,
    DW_نښان_template_ارزښت_parameter = 0x30,
    DW_نښان_thrown_type = 0x31,
    DW_نښان_try_بلاک = 0x32,
    DW_نښان_variant_part = 0x33,
    DW_نښان_variable = 0x34,
    DW_نښان_volatile_type = 0x35,
    DW_نښان_dwarf_procedure = 0x36,
    DW_نښان_restrict_type = 0x37,
    DW_نښان_interface_type = 0x38,
    DW_نښان_namespace = 0x39,
    DW_نښان_imported_module = 0x3a,
    DW_نښان_unspecified_type = 0x3b,
    DW_نښان_partial_unit = 0x3c,
    DW_نښان_imported_unit = 0x3d,
    /* 0x3e reserved.  Was DW_TAG_mutable_type.  */
    DW_نښان_condition = 0x3f,
    DW_نښان_shared_type = 0x40,
    DW_نښان_type_unit = 0x41,
    DW_نښان_rvalue_reference_type = 0x42,
    DW_نښان_template_alias = 0x43,
    DW_نښان_coarray_type = 0x44,
    DW_نښان_generic_subrange = 0x45,
    DW_نښان_dynamic_type = 0x46,
    DW_نښان_atomic_type = 0x47,
    DW_نښان_call_site = 0x48,
    DW_نښان_call_site_parameter = 0x49,
    DW_نښان_skeleton_unit = 0x4a,
    DW_نښان_immutable_type = 0x4b,

    DW_نښان_lo_user = 0x4080,

    DW_نښان_MIPS_loop = 0x4081,
    DW_نښان_format_label = 0x4101,
    DW_نښان_function_template = 0x4102,
    DW_نښان_class_template = 0x4103,

    DW_نښان_GNU_BINCL = 0x4104,
    DW_نښان_GNU_EINCL = 0x4105,

    DW_نښان_GNU_template_template_param = 0x4106,
    DW_نښان_GNU_template_parameter_pack = 0x4107,
    DW_نښان_GNU_formal_parameter_pack = 0x4108,
    DW_نښان_GNU_call_site = 0x4109,
    DW_نښان_GNU_call_site_parameter = 0x410a,

    DW_نښان_hi_user = 0xffff
  };


/* Children determination encodings.  */
تعداد
  {
    DW_CHILDREN_no = 0,
    DW_CHILDREN_yes = 1
  };


/* DWARF attributes encodings.  */
تعداد
  {
    DW_AT_sibling = 0x01,
    DW_AT_location = 0x02,
    DW_AT_name = 0x03,
    /* 0x04 reserved.  */
    /* 0x05 reserved.  */
    /* 0x06 reserved.  */
    /* 0x07 reserved.  */
    /* 0x08 reserved.  */
    DW_AT_ordering = 0x09,
    /* 0x0a reserved.  */
    DW_AT_byte_اندازه = 0x0b,
    DW_AT_بټ_دننه_واټن = 0x0c,  /* Deprecated in DWARF4.  */
    DW_AT_بټ_اندازه = 0x0d,
    /* 0x0e reserved.  */
    /* 0x0f reserved.  */
    DW_AT_stmt_list = 0x10,
    DW_AT_ټیټ_pc = 0x11,
    DW_AT_لوړ_pc = 0x12,
    DW_AT_language = 0x13,
    /* 0x14 reserved.  */
    DW_AT_discr = 0x15,
    DW_AT_discr_ارزښت = 0x16,
    DW_AT_visibility = 0x17,
    DW_AT_import = 0x18,
    DW_AT_string_اوږدتیا = 0x19,
    DW_AT_common_reference = 0x1a,
    DW_AT_comp_dir = 0x1b,
    DW_AT_const_ارزښت = 0x1c,
    DW_AT_containing_type = 0x1d,
    DW_AT_default_ارزښت = 0x1e,
    /* 0x1f reserved.  */
    DW_AT_inline = 0x20,
    DW_AT_is_optional = 0x21,
    DW_AT_ښکتنی_bound = 0x22,
    /* 0x23 reserved.  */
    /* 0x24 reserved.  */
    DW_AT_تولیدوونکی = 0x25,
    /* 0x26 reserved.  */
    DW_AT_prototyped = 0x27,
    /* 0x28 reserved.  */
    /* 0x29 reserved.  */
    DW_AT_return_addr = 0x2a,
    /* 0x2b reserved.  */
    DW_AT_پیل_scope = 0x2c,
    /* 0x2d reserved.  */
    DW_AT_بټ_stride = 0x2e,
    DW_AT_پاسنی_bound = 0x2f,
    /* 0x30 reserved.  */
    DW_AT_abstract_origin = 0x31,
    DW_AT_accessibility = 0x32,
    DW_AT_پته_class = 0x33,
    DW_AT_artificial = 0x34,
    DW_AT_بنسټ_types = 0x35,
    DW_AT_calling_convention = 0x36,
    DW_AT_شمېر = 0x37,
    DW_AT_معلومات_member_location = 0x38,
    DW_AT_decl_ستنه = 0x39,
    DW_AT_decl_file = 0x3a,
    DW_AT_decl_کرښه = 0x3b,
    DW_AT_declaration = 0x3c,
    DW_AT_discr_list = 0x3d,
    DW_AT_encoding = 0x3e,
    DW_AT_external = 0x3f,
    DW_AT_چوکاټ_بنسټ = 0x40,
    DW_AT_friend = 0x41,
    DW_AT_identifier_case = 0x42,
    DW_AT_macro_info = 0x43, /* Deprecated in DWARF5.  */
    DW_AT_namelist_توکی = 0x44,
    DW_AT_لومړیتوب = 0x45,
    DW_AT_segment = 0x46,
    DW_AT_specification = 0x47,
    DW_AT_static_link = 0x48,
    DW_AT_type = 0x49,
    DW_AT_use_location = 0x4a,
    DW_AT_variable_parameter = 0x4b,
    DW_AT_virtuality = 0x4c,
    DW_AT_vtable_elem_location = 0x4d,
    DW_AT_allocated = 0x4e,
    DW_AT_associated = 0x4f,
    DW_AT_معلومات_location = 0x50,
    DW_AT_byte_stride = 0x51,
    DW_AT_ثبت_pc = 0x52,
    DW_AT_use_UTF8 = 0x53,
    DW_AT_extension = 0x54,
    DW_AT_ranges = 0x55,
    DW_AT_trampoline = 0x56,
    DW_AT_call_ستنه = 0x57,
    DW_AT_call_file = 0x58,
    DW_AT_call_کرښه = 0x59,
    DW_AT_description = 0x5a,
    DW_AT_دوګونی_scale = 0x5b,
    DW_AT_decimal_scale = 0x5c,
    DW_AT_small = 0x5d,
    DW_AT_decimal_sign = 0x5e,
    DW_AT_digit_شمېر = 0x5f,
    DW_AT_picture_string = 0x60,
    DW_AT_mutable = 0x61,
    DW_AT_تارونه_scaled = 0x62,
    DW_AT_explicit = 0x63,
    DW_AT_object_اشاره_ګر = 0x64,
    DW_AT_endianity = 0x65,
    DW_AT_elemental = 0x66,
    DW_AT_خالص = 0x67,
    DW_AT_recursive = 0x68,
    DW_AT_signature = 0x69,
    DW_AT_main_subprogram = 0x6a,
    DW_AT_معلومات_بټ_دننه_واټن = 0x6b,
    DW_AT_const_بیان = 0x6c,
    DW_AT_enum_class = 0x6d,
    DW_AT_linkage_name = 0x6e,
    DW_AT_string_اوږدتیا_بټ_اندازه = 0x6f,
    DW_AT_string_اوږدتیا_byte_اندازه = 0x70,
    DW_AT_rank = 0x71,
    DW_AT_str_offsets_بنسټ = 0x72,
    DW_AT_addr_بنسټ = 0x73,
    DW_AT_rnglists_بنسټ = 0x74,
    /* 0x75 reserved.  */
    DW_AT_dwo_name = 0x76,
    DW_AT_reference = 0x77,
    DW_AT_rvalue_reference = 0x78,
    DW_AT_macros = 0x79,
    DW_AT_call_all_calls = 0x7a,
    DW_AT_call_all_سرچینه_calls = 0x7b,
    DW_AT_call_all_لکۍ_calls = 0x7c,
    DW_AT_call_return_pc = 0x7d,
    DW_AT_call_ارزښت = 0x7e,
    DW_AT_call_origin = 0x7f,
    DW_AT_call_parameter = 0x80,
    DW_AT_call_pc = 0x81,
    DW_AT_call_لکۍ_call = 0x82,
    DW_AT_call_موخه = 0x83,
    DW_AT_call_موخه_clobbered = 0x84,
    DW_AT_call_معلومات_location = 0x85,
    DW_AT_call_معلومات_ارزښت = 0x86,
    DW_AT_noreturn = 0x87,
    DW_AT_alignment = 0x88,
    DW_AT_export_symbols = 0x89,
    DW_AT_deleted = 0x8a,
    DW_AT_defaulted = 0x8b,
    DW_AT_loclists_بنسټ = 0x8c,

    DW_AT_lo_user = 0x2000,

    DW_AT_MIPS_fde = 0x2001,
    DW_AT_MIPS_loop_begin = 0x2002,
    DW_AT_MIPS_لکۍ_loop_begin = 0x2003,
    DW_AT_MIPS_epilog_begin = 0x2004,
    DW_AT_MIPS_loop_unroll_ضریب = 0x2005,
    DW_AT_MIPS_software_pipeline_ژوروالی = 0x2006,
    DW_AT_MIPS_linkage_name = 0x2007,
    DW_AT_MIPS_stride = 0x2008,
    DW_AT_MIPS_abstract_name = 0x2009,
    DW_AT_MIPS_clone_origin = 0x200a,
    DW_AT_MIPS_has_inlines = 0x200b,
    DW_AT_MIPS_stride_byte = 0x200c,
    DW_AT_MIPS_stride_elem = 0x200d,
    DW_AT_MIPS_ptr_dopetype = 0x200e,
    DW_AT_MIPS_allocatable_dopetype = 0x200f,
    DW_AT_MIPS_assumed_shape_dopetype = 0x2010,
    DW_AT_MIPS_assumed_اندازه = 0x2011,

    /* GNU extensions.  */
    DW_AT_sf_نومونه = 0x2101,
    DW_AT_src_info = 0x2102,
    DW_AT_mac_info = 0x2103,
    DW_AT_src_coords = 0x2104,
    DW_AT_body_begin = 0x2105,
    DW_AT_body_پای_ټکی = 0x2106,
    DW_AT_GNU_ویکټور = 0x2107,
    DW_AT_GNU_guarded_by = 0x2108,
    DW_AT_GNU_pt_guarded_by = 0x2109,
    DW_AT_GNU_guarded = 0x210a,
    DW_AT_GNU_pt_guarded = 0x210b,
    DW_AT_GNU_locks_excluded = 0x210c,
    DW_AT_GNU_exclusive_locks_required = 0x210d,
    DW_AT_GNU_shared_locks_required = 0x210e,
    DW_AT_GNU_odr_signature = 0x210f,
    DW_AT_GNU_template_name = 0x2110,
    DW_AT_GNU_call_site_ارزښت = 0x2111,
    DW_AT_GNU_call_site_معلومات_ارزښت = 0x2112,
    DW_AT_GNU_call_site_موخه = 0x2113,
    DW_AT_GNU_call_site_موخه_clobbered = 0x2114,
    DW_AT_GNU_لکۍ_call = 0x2115,
    DW_AT_GNU_all_لکۍ_call_sites = 0x2116,
    DW_AT_GNU_all_call_sites = 0x2117,
    DW_AT_GNU_all_سرچینه_call_sites = 0x2118,
    DW_AT_GNU_locviews = 0x2137,
    DW_AT_GNU_ثبت_view = 0x2138,
    DW_AT_GNU_macros = 0x2119,
    DW_AT_GNU_deleted = 0x211a,
    /* GNU Debug Fission extensions.  */
    DW_AT_GNU_dwo_name = 0x2130,
    DW_AT_GNU_dwo_id = 0x2131,
    DW_AT_GNU_ranges_بنسټ = 0x2132,
    DW_AT_GNU_addr_بنسټ = 0x2133,
    DW_AT_GNU_pubnames = 0x2134,
    DW_AT_GNU_pubtypes = 0x2135,

    /* https://gcc.gnu.org/wiki/DW_AT_GNU_numerator_denominator  */
    DW_AT_GNU_numerator = 0x2303,
    DW_AT_GNU_denominator = 0x2304,
    /* https://gcc.gnu.org/wiki/DW_AT_GNU_bias  */
    DW_AT_GNU_bias = 0x2305,

    DW_AT_hi_user = 0x3fff
  };

/* Old unofficially attribute names.  Should not be used.
   Will not appear in known-dwarf.h  */

/* DWARF1 array subscripts and element data types.  */
#تعریف_کړه DW_AT_subscr_معلومات	0x0a
/* DWARF1 enumeration literals.  */
#تعریف_کړه DW_AT_element_list	0x0f
/* DWARF1 reference for variable to member structure, class or union.  */
#تعریف_کړه DW_AT_member		0x14

/* DWARF form encodings.  */
تعداد
  {
    DW_FORM_addr = 0x01,
    DW_FORM_block2 = 0x03,
    DW_FORM_block4 = 0x04,
    DW_FORM_data2 = 0x05,
    DW_FORM_data4 = 0x06,
    DW_FORM_data8 = 0x07,
    DW_FORM_string = 0x08,
    DW_FORM_بلاک = 0x09,
    DW_FORM_block1 = 0x0a,
    DW_FORM_data1 = 0x0b,
    DW_FORM_flag = 0x0c,
    DW_FORM_sdata = 0x0d,
    DW_FORM_strp = 0x0e,
    DW_FORM_udata = 0x0f,
    DW_FORM_ref_addr = 0x10,
    DW_FORM_ref1 = 0x11,
    DW_FORM_ref2 = 0x12,
    DW_FORM_ref4 = 0x13,
    DW_FORM_ref8 = 0x14,
    DW_FORM_ref_udata = 0x15,
    DW_FORM_غیرمستقیم = 0x16,
    DW_FORM_sec_دننه_واټن = 0x17,
    DW_FORM_exprloc = 0x18,
    DW_FORM_flag_present = 0x19,
    DW_FORM_strx = 0x1a,
    DW_FORM_addrx = 0x1b,
    DW_FORM_ref_sup4 = 0x1c,
    DW_FORM_strp_sup = 0x1d,
    DW_FORM_data16 = 0x1e,
    DW_FORM_کرښه_strp = 0x1f,
    DW_FORM_ref_sig8 = 0x20,
    DW_FORM_implicit_const = 0x21,
    DW_FORM_loclistx = 0x22,
    DW_FORM_rnglistx = 0x23,
    DW_FORM_ref_sup8 = 0x24,
    DW_FORM_strx1 = 0x25,
    DW_FORM_strx2 = 0x26,
    DW_FORM_strx3 = 0x27,
    DW_FORM_strx4 = 0x28,
    DW_FORM_addrx1 = 0x29,
    DW_FORM_addrx2 = 0x2a,
    DW_FORM_addrx3 = 0x2b,
    DW_FORM_addrx4 = 0x2c,

    /* GNU Debug Fission extensions.  */
    DW_FORM_GNU_addr_شاخص = 0x1f01,
    DW_FORM_GNU_str_شاخص = 0x1f02,

    DW_FORM_GNU_ref_alt = 0x1f20, /* offset in alternate .debuginfo.  */
    DW_FORM_GNU_strp_alt = 0x1f21 /* offset in alternate .debug_str. */
  };


/* DWARF location operation encodings.  */
تعداد
  {
    DW_OP_addr = 0x03,		/* Constant address.  */
    DW_OP_deref = 0x06,
    DW_OP_const1u = 0x08,	/* Unsigned 1-byte constant.  */
    DW_OP_const1s = 0x09,	/* Signed 1-byte constant.  */
    DW_OP_const2u = 0x0a,	/* Unsigned 2-byte constant.  */
    DW_OP_const2s = 0x0b,	/* Signed 2-byte constant.  */
    DW_OP_const4u = 0x0c,	/* Unsigned 4-byte constant.  */
    DW_OP_const4s = 0x0d,	/* Signed 4-byte constant.  */
    DW_OP_const8u = 0x0e,	/* Unsigned 8-byte constant.  */
    DW_OP_const8s = 0x0f,	/* Signed 8-byte constant.  */
    DW_OP_constu = 0x10,	/* Unsigned LEB128 constant.  */
    DW_OP_consts = 0x11,	/* Signed LEB128 constant.  */
    DW_OP_dup = 0x12,
    DW_OP_drop = 0x13,
    DW_OP_over = 0x14,
    DW_OP_pick = 0x15,		/* 1-byte stack index.  */
    DW_OP_بدلون = 0x16,
    DW_OP_rot = 0x17,
    DW_OP_xderef = 0x18,
    DW_OP_abs = 0x19,
    DW_OP_and = 0x1a,
    DW_OP_div = 0x1b,
    DW_OP_minus = 0x1c,
    DW_OP_mod = 0x1d,
    DW_OP_mul = 0x1e,
    DW_OP_neg = 0x1f,
    DW_OP_not = 0x20,
    DW_OP_or = 0x21,
    DW_OP_plus = 0x22,
    DW_OP_plus_uconst = 0x23,	/* Unsigned LEB128 addend.  */
    DW_OP_shl = 0x24,
    DW_OP_shr = 0x25,
    DW_OP_shra = 0x26,
    DW_OP_xor = 0x27,
    DW_OP_bra = 0x28,		/* Signed 2-byte constant.  */
    DW_OP_eq = 0x29,
    DW_OP_ge = 0x2a,
    DW_OP_gt = 0x2b,
    DW_OP_le = 0x2c,
    DW_OP_lt = 0x2d,
    DW_OP_ne = 0x2e,
    DW_OP_skip = 0x2f,		/* Signed 2-byte constant.  */
    DW_OP_lit0 = 0x30,		/* Literal 0.  */
    DW_OP_lit1 = 0x31,		/* Literal 1.  */
    DW_OP_lit2 = 0x32,		/* Literal 2.  */
    DW_OP_lit3 = 0x33,		/* Literal 3.  */
    DW_OP_lit4 = 0x34,		/* Literal 4.  */
    DW_OP_lit5 = 0x35,		/* Literal 5.  */
    DW_OP_lit6 = 0x36,		/* Literal 6.  */
    DW_OP_lit7 = 0x37,		/* Literal 7.  */
    DW_OP_lit8 = 0x38,		/* Literal 8.  */
    DW_OP_lit9 = 0x39,		/* Literal 9.  */
    DW_OP_lit10 = 0x3a,		/* Literal 10.  */
    DW_OP_lit11 = 0x3b,		/* Literal 11.  */
    DW_OP_lit12 = 0x3c,		/* Literal 12.  */
    DW_OP_lit13 = 0x3d,		/* Literal 13.  */
    DW_OP_lit14 = 0x3e,		/* Literal 14.  */
    DW_OP_lit15 = 0x3f,		/* Literal 15.  */
    DW_OP_lit16 = 0x40,		/* Literal 16.  */
    DW_OP_lit17 = 0x41,		/* Literal 17.  */
    DW_OP_lit18 = 0x42,		/* Literal 18.  */
    DW_OP_lit19 = 0x43,		/* Literal 19.  */
    DW_OP_lit20 = 0x44,		/* Literal 20.  */
    DW_OP_lit21 = 0x45,		/* Literal 21.  */
    DW_OP_lit22 = 0x46,		/* Literal 22.  */
    DW_OP_lit23 = 0x47,		/* Literal 23.  */
    DW_OP_lit24 = 0x48,		/* Literal 24.  */
    DW_OP_lit25 = 0x49,		/* Literal 25.  */
    DW_OP_lit26 = 0x4a,		/* Literal 26.  */
    DW_OP_lit27 = 0x4b,		/* Literal 27.  */
    DW_OP_lit28 = 0x4c,		/* Literal 28.  */
    DW_OP_lit29 = 0x4d,		/* Literal 29.  */
    DW_OP_lit30 = 0x4e,		/* Literal 30.  */
    DW_OP_lit31 = 0x4f,		/* Literal 31.  */
    DW_OP_reg0 = 0x50,		/* Register 0.  */
    DW_OP_reg1 = 0x51,		/* Register 1.  */
    DW_OP_reg2 = 0x52,		/* Register 2.  */
    DW_OP_reg3 = 0x53,		/* Register 3.  */
    DW_OP_reg4 = 0x54,		/* Register 4.  */
    DW_OP_reg5 = 0x55,		/* Register 5.  */
    DW_OP_reg6 = 0x56,		/* Register 6.  */
    DW_OP_reg7 = 0x57,		/* Register 7.  */
    DW_OP_reg8 = 0x58,		/* Register 8.  */
    DW_OP_reg9 = 0x59,		/* Register 9.  */
    DW_OP_reg10 = 0x5a,		/* Register 10.  */
    DW_OP_reg11 = 0x5b,		/* Register 11.  */
    DW_OP_reg12 = 0x5c,		/* Register 12.  */
    DW_OP_reg13 = 0x5d,		/* Register 13.  */
    DW_OP_reg14 = 0x5e,		/* Register 14.  */
    DW_OP_reg15 = 0x5f,		/* Register 15.  */
    DW_OP_reg16 = 0x60,		/* Register 16.  */
    DW_OP_reg17 = 0x61,		/* Register 17.  */
    DW_OP_reg18 = 0x62,		/* Register 18.  */
    DW_OP_reg19 = 0x63,		/* Register 19.  */
    DW_OP_reg20 = 0x64,		/* Register 20.  */
    DW_OP_reg21 = 0x65,		/* Register 21.  */
    DW_OP_reg22 = 0x66,		/* Register 22.  */
    DW_OP_reg23 = 0x67,		/* Register 24.  */
    DW_OP_reg24 = 0x68,		/* Register 24.  */
    DW_OP_reg25 = 0x69,		/* Register 25.  */
    DW_OP_reg26 = 0x6a,		/* Register 26.  */
    DW_OP_reg27 = 0x6b,		/* Register 27.  */
    DW_OP_reg28 = 0x6c,		/* Register 28.  */
    DW_OP_reg29 = 0x6d,		/* Register 29.  */
    DW_OP_reg30 = 0x6e,		/* Register 30.  */
    DW_OP_reg31 = 0x6f,		/* Register 31.  */
    DW_OP_breg0 = 0x70,		/* Base register 0.  */
    DW_OP_breg1 = 0x71,		/* Base register 1.  */
    DW_OP_breg2 = 0x72,		/* Base register 2.  */
    DW_OP_breg3 = 0x73,		/* Base register 3.  */
    DW_OP_breg4 = 0x74,		/* Base register 4.  */
    DW_OP_breg5 = 0x75,		/* Base register 5.  */
    DW_OP_breg6 = 0x76,		/* Base register 6.  */
    DW_OP_breg7 = 0x77,		/* Base register 7.  */
    DW_OP_breg8 = 0x78,		/* Base register 8.  */
    DW_OP_breg9 = 0x79,		/* Base register 9.  */
    DW_OP_breg10 = 0x7a,	/* Base register 10.  */
    DW_OP_breg11 = 0x7b,	/* Base register 11.  */
    DW_OP_breg12 = 0x7c,	/* Base register 12.  */
    DW_OP_breg13 = 0x7d,	/* Base register 13.  */
    DW_OP_breg14 = 0x7e,	/* Base register 14.  */
    DW_OP_breg15 = 0x7f,	/* Base register 15.  */
    DW_OP_breg16 = 0x80,	/* Base register 16.  */
    DW_OP_breg17 = 0x81,	/* Base register 17.  */
    DW_OP_breg18 = 0x82,	/* Base register 18.  */
    DW_OP_breg19 = 0x83,	/* Base register 19.  */
    DW_OP_breg20 = 0x84,	/* Base register 20.  */
    DW_OP_breg21 = 0x85,	/* Base register 21.  */
    DW_OP_breg22 = 0x86,	/* Base register 22.  */
    DW_OP_breg23 = 0x87,	/* Base register 23.  */
    DW_OP_breg24 = 0x88,	/* Base register 24.  */
    DW_OP_breg25 = 0x89,	/* Base register 25.  */
    DW_OP_breg26 = 0x8a,	/* Base register 26.  */
    DW_OP_breg27 = 0x8b,	/* Base register 27.  */
    DW_OP_breg28 = 0x8c,	/* Base register 28.  */
    DW_OP_breg29 = 0x8d,	/* Base register 29.  */
    DW_OP_breg30 = 0x8e,	/* Base register 30.  */
    DW_OP_breg31 = 0x8f,	/* Base register 31.  */
    DW_OP_regx = 0x90,		/* Unsigned LEB128 register.  */
    DW_OP_fbreg = 0x91,		/* Signed LEB128 offset.  */
    DW_OP_bregx = 0x92,		/* ULEB128 register followed by SLEB128 off. */
    DW_OP_piece = 0x93,		/* ULEB128 size of piece addressed. */
    DW_OP_deref_اندازه = 0x94,	/* 1-byte size of data retrieved.  */
    DW_OP_xderef_اندازه = 0x95,	/* 1-byte size of data retrieved.  */
    DW_OP_nop = 0x96,
    DW_OP_ټېل_object_پته = 0x97,
    DW_OP_call2 = 0x98,
    DW_OP_call4 = 0x99,
    DW_OP_call_ref = 0x9a,
    DW_OP_form_tls_پته = 0x9b,/* TLS offset to address in current thread */
    DW_OP_call_چوکاټ_cfa = 0x9c,/* CFA as determined by CFI.  */
    DW_OP_بټ_piece = 0x9d,	/* ULEB128 size and ULEB128 offset in bits.  */
    DW_OP_implicit_ارزښت = 0x9e, /* DW_FORM_block follows opcode.  */
    DW_OP_ډېری_ارزښت = 0x9f,	 /* No operands, special like DW_OP_piece.  */

    DW_OP_implicit_اشاره_ګر = 0xa0,
    DW_OP_addrx = 0xa1,
    DW_OP_constx = 0xa2,
    DW_OP_ثبت_ارزښت = 0xa3,
    DW_OP_const_type = 0xa4,
    DW_OP_regval_type = 0xa5,
    DW_OP_deref_type = 0xa6,
    DW_OP_xderef_type = 0xa7,
    DW_OP_convert = 0xa8,
    DW_OP_reinterpret = 0xa9,

    /* GNU extensions.  */
    DW_OP_GNU_ټېل_tls_پته = 0xe0,
    DW_OP_GNU_uninit = 0xf0,
    DW_OP_GNU_encoded_addr = 0xf1,
    DW_OP_GNU_implicit_اشاره_ګر = 0xf2,
    DW_OP_GNU_ثبت_ارزښت = 0xf3,
    DW_OP_GNU_const_type = 0xf4,
    DW_OP_GNU_regval_type = 0xf5,
    DW_OP_GNU_deref_type = 0xf6,
    DW_OP_GNU_convert = 0xf7,
    DW_OP_GNU_reinterpret = 0xf9,
    DW_OP_GNU_parameter_ref = 0xfa,

    /* GNU Debug Fission extensions.  */
    DW_OP_GNU_addr_شاخص = 0xfb,
    DW_OP_GNU_const_شاخص = 0xfc,

    DW_OP_GNU_variable_ارزښت = 0xfd,

    DW_OP_lo_user = 0xe0,	/* Implementation-defined range start.  */
    DW_OP_hi_user = 0xff	/* Implementation-defined range end.  */
  };


/* DWARF base type encodings.  */
تعداد
  {
    DW_ATE_void = 0x0,
    DW_ATE_پته = 0x1,
    DW_ATE_boolean = 0x2,
    DW_ATE_complex_float = 0x3,
    DW_ATE_float = 0x4,
    DW_ATE_signed = 0x5,
    DW_ATE_signed_char = 0x6,
    DW_ATE_unsigned = 0x7,
    DW_ATE_unsigned_char = 0x8,
    DW_ATE_imaginary_float = 0x9,
    DW_ATE_packed_decimal = 0xa,
    DW_ATE_numeric_string = 0xb,
    DW_ATE_edited = 0xc,
    DW_ATE_signed_fixed = 0xd,
    DW_ATE_unsigned_fixed = 0xe,
    DW_ATE_decimal_float = 0xf,
    DW_ATE_UTF = 0x10,
    DW_ATE_UCS = 0x11,
    DW_ATE_ASCII = 0x12,

    DW_ATE_lo_user = 0x80,
    DW_ATE_hi_user = 0xff
  };


/* DWARF decimal sign encodings.  */
تعداد
  {
    DW_DS_unsigned = 1,
    DW_DS_leading_overpunch = 2,
    DW_DS_trailing_overpunch = 3,
    DW_DS_leading_separate = 4,
    DW_DS_trailing_separate = 5,
  };


/* DWARF endianity encodings.  */
تعداد
  {
    DW_پای_ټکی_default = 0,
    DW_پای_ټکی_big = 1,
    DW_پای_ټکی_little = 2,

    DW_پای_ټکی_lo_user = 0x40,
    DW_پای_ټکی_hi_user = 0xff
  };


/* DWARF accessibility encodings.  */
تعداد
  {
    DW_ACCESS_عامه = 1,
    DW_ACCESS_protected = 2,
    DW_ACCESS_شخصي = 3
  };


/* DWARF visibility encodings.  */
تعداد
  {
    DW_VIS_local = 1,
    DW_VIS_exported = 2,
    DW_VIS_qualified = 3
  };


/* DWARF virtuality encodings.  */
تعداد
  {
    DW_VIRTUALITY_none = 0,
    DW_VIRTUALITY_virtual = 1,
    DW_VIRTUALITY_خالص_virtual = 2
  };


/* DWARF language encodings.  */
تعداد
  {
    DW_LANG_C89 = 0x0001,	     /* ISO C:1989 */
    DW_LANG_C = 0x0002,		     /* C */
    DW_LANG_Ada83 = 0x0003,	     /* ISO Ada:1983 */
    DW_LANG_C_plus_plus	= 0x0004,    /* ISO C++:1998 */
    DW_LANG_Cobol74 = 0x0005,	     /* ISO Cobol:1974 */
    DW_LANG_Cobol85 = 0x0006,	     /* ISO Cobol:1985 */
    DW_LANG_Fortran77 = 0x0007,	     /* ISO FORTRAN 77 */
    DW_LANG_Fortran90 = 0x0008,	     /* ISO Fortran 90 */
    DW_LANG_Pascal83 = 0x0009,	     /* ISO Pascal:1983 */
    DW_LANG_Modula2 = 0x000a,	     /* ISO Modula-2:1996 */
    DW_LANG_Java = 0x000b,	     /* Java */
    DW_LANG_C99 = 0x000c,	     /* ISO C:1999 */
    DW_LANG_Ada95 = 0x000d,	     /* ISO Ada:1995 */
    DW_LANG_Fortran95 = 0x000e,	     /* ISO Fortran 95 */
    DW_LANG_PLI = 0x000f,	     /* ISO PL/1:1976 */
    DW_LANG_ObjC = 0x0010,	     /* Objective-C */
    DW_LANG_ObjC_plus_plus = 0x0011, /* Objective-C++ */
    DW_LANG_UPC = 0x0012,	     /* Unified Parallel C */
    DW_LANG_D = 0x0013,		     /* D */
    DW_LANG_Python = 0x0014,	     /* Python */
    DW_LANG_OpenCL = 0x0015,	     /* OpenCL */
    DW_LANG_Go = 0x0016,	     /* Go */
    DW_LANG_Modula3 = 0x0017,	     /* Modula-3 */
    DW_LANG_Haskell = 0x0018,	     /* Haskell */
    DW_LANG_C_plus_plus_03 = 0x0019, /* ISO C++:2003 */
    DW_LANG_C_plus_plus_11 = 0x001a, /* ISO C++:2011 */
    DW_LANG_OCaml = 0x001b,	     /* OCaml */
    DW_LANG_Rust = 0x001c,	     /* Rust */
    DW_LANG_C11 = 0x001d,	     /* ISO C:2011 */
    DW_LANG_Swift = 0x001e,	     /* Swift */
    DW_LANG_Julia = 0x001f,	     /* Julia */
    DW_LANG_Dylan = 0x0020,	     /* Dylan */
    DW_LANG_C_plus_plus_14 = 0x0021, /* ISO C++:2014 */
    DW_LANG_Fortran03 = 0x0022,	     /* ISO/IEC 1539-1:2004 */
    DW_LANG_Fortran08 = 0x0023,	     /* ISO/IEC 1539-1:2010 */
    DW_LANG_RenderScript = 0x0024,   /* RenderScript Kernal Language */
    DW_LANG_BLISS = 0x0025,	     /* BLISS */

    DW_LANG_lo_user = 0x8000,
    DW_LANG_Mips_Assembler = 0x8001, /* Assembler */
    DW_LANG_hi_user = 0xffff
  };

/* Old (typo) '1' != 'I'.  */
#تعریف_کړه DW_LANG_PL1 DW_LANG_PLI

/* DWARF identifier case encodings.  */
تعداد
  {
    DW_ID_case_sensitive = 0,
    DW_ID_پورته_case = 1,
    DW_ID_ښکته_case = 2,
    DW_ID_case_insensitive = 3
  };


/* DWARF calling conventions encodings.
   Used as values of DW_AT_calling_convention for subroutines
   (normal, program or nocall) or structures, unions and class types
   (normal, reference or value).  */
تعداد
  {
    DW_CC_نورمال = 0x1,
    DW_CC_پروګرام = 0x2,
    DW_CC_nocall = 0x3,
    DW_CC_pass_by_reference = 0x4,
    DW_CC_pass_by_ارزښت = 0x5,
    DW_CC_lo_user = 0x40,
    DW_CC_hi_user = 0xff
  };


/* DWARF inline encodings.  */
تعداد
  {
    DW_INL_not_inlined = 0,
    DW_INL_inlined = 1,
    DW_INL_declared_not_inlined = 2,
    DW_INL_declared_inlined = 3
  };


/* DWARF ordering encodings.  */
تعداد
  {
    DW_ORD_لیکه_major = 0,
    DW_ORD_ستون_major = 1
  };


/* DWARF discriminant descriptor encodings.  */
تعداد
  {
    DW_DSC_label = 0,
    DW_DSC_range = 1
  };

/* DWARF defaulted member function encodings.  */
تعداد
  {
    DW_DEFAULTED_no = 0,
    DW_DEFAULTED_دننه_class = 1,
    DW_DEFAULTED_بهر_د_class = 2
  };

/* DWARF line content descriptions.  */
تعداد
  {
    DW_LNCT_لار = 0x1,
    DW_LNCT_directory_شاخص = 0x2,
    DW_LNCT_timestamp = 0x3,
    DW_LNCT_اندازه = 0x4,
    DW_LNCT_MD5 = 0x5,
    DW_LNCT_lo_user = 0x2000,
    DW_LNCT_hi_user = 0x3fff
  };

/* DWARF standard opcode encodings.  */
تعداد
  {
    DW_LNS_copy = 1,
    DW_LNS_advance_pc = 2,
    DW_LNS_advance_کرښه = 3,
    DW_LNS_سېټ_file = 4,
    DW_LNS_سېټ_ستنه = 5,
    DW_LNS_negate_stmt = 6,
    DW_LNS_سېټ_basic_بلاک = 7,
    DW_LNS_const_جمع_کړه_pc = 8,
    DW_LNS_fixed_advance_pc = 9,
    DW_LNS_سېټ_prologue_پای_ټکی = 10,
    DW_LNS_سېټ_epilogue_begin = 11,
    DW_LNS_سېټ_isa = 12
  };


/* DWARF extended opcode encodings.  */
تعداد
  {
    DW_LNE_پای_ټکی_sequence = 1,
    DW_LNE_سېټ_پته = 2,
    DW_LNE_define_file = 3,
    DW_LNE_سېټ_discriminator = 4,

    DW_LNE_lo_user = 128,

    DW_LNE_NVIDIA_inlined_call = 144,
    DW_LNE_NVIDIA_سېټ_function_name = 145,

    DW_LNE_hi_user = 255
  };


/* DWARF macinfo type encodings.  */
تعداد
  {
    DW_MACINFO_define = 1,
    DW_MACINFO_undef = 2,
    DW_MACINFO_پیل_file = 3,
    DW_MACINFO_پای_ټکی_file = 4,
    DW_MACINFO_vendor_ext = 255
  };


/* DWARF debug_macro type encodings.  */
تعداد
  {
    DW_MACRO_define = 0x01,
    DW_MACRO_undef = 0x02,
    DW_MACRO_پیل_file = 0x03,
    DW_MACRO_پای_ټکی_file = 0x04,
    DW_MACRO_define_strp = 0x05,
    DW_MACRO_undef_strp = 0x06,
    DW_MACRO_import = 0x07,
    DW_MACRO_define_sup = 0x08,
    DW_MACRO_undef_sup = 0x09,
    DW_MACRO_import_sup = 0x0a,
    DW_MACRO_define_strx = 0x0b,
    DW_MACRO_undef_strx = 0x0c,
    DW_MACRO_lo_user = 0xe0,
    DW_MACRO_hi_user = 0xff
  };

/* Old GNU extension names for DWARF5 debug_macro type encodings.
   There are no equivalents for the supplementary object file (sup)
   and indirect string references (strx).  */
#تعریف_کړه DW_MACRO_GNU_define		 DW_MACRO_define
#تعریف_کړه DW_MACRO_GNU_undef		 DW_MACRO_undef
#تعریف_کړه DW_MACRO_GNU_پیل_file		 DW_MACRO_پیل_file
#تعریف_کړه DW_MACRO_GNU_پای_ټکی_file		 DW_MACRO_پای_ټکی_file
#تعریف_کړه DW_MACRO_GNU_define_غیرمستقیم	 DW_MACRO_define_strp
#تعریف_کړه DW_MACRO_GNU_undef_غیرمستقیم	 DW_MACRO_undef_strp
#تعریف_کړه DW_MACRO_GNU_transparent_include DW_MACRO_import
#تعریف_کړه DW_MACRO_GNU_lo_user		 DW_MACRO_lo_user
#تعریف_کړه DW_MACRO_GNU_hi_user		 DW_MACRO_hi_user


/* Range list entry encoding.  */
تعداد
  {
    DW_RLE_پای_ټکی_د_list = 0x0,
    DW_RLE_بنسټ_addressx = 0x1,
    DW_RLE_startx_endx = 0x2,
    DW_RLE_startx_اوږدتیا = 0x3,
    DW_RLE_دننه_واټن_pair = 0x4,
    DW_RLE_بنسټ_پته = 0x5,
    DW_RLE_پیل_پای_ټکی = 0x6,
    DW_RLE_پیل_اوږدتیا = 0x7
  };


/* Location list entry encoding.  */
تعداد
  {
    DW_LLE_پای_ټکی_د_list = 0x0,
    DW_LLE_بنسټ_addressx = 0x1,
    DW_LLE_startx_endx = 0x2,
    DW_LLE_startx_اوږدتیا = 0x3,
    DW_LLE_دننه_واټن_pair = 0x4,
    DW_LLE_default_location = 0x5,
    DW_LLE_بنسټ_پته = 0x6,
    DW_LLE_پیل_پای_ټکی = 0x7,
    DW_LLE_پیل_اوږدتیا = 0x8
  };


/* GNU DebugFission list entry encodings (.debug_loc.dwo).  */
تعداد
  {
    DW_LLE_GNU_پای_ټکی_د_list_ثبت = 0x0,
    DW_LLE_GNU_بنسټ_پته_selection_ثبت = 0x1,
    DW_LLE_GNU_پیل_پای_ټکی_ثبت = 0x2,
    DW_LLE_GNU_پیل_اوږدتیا_ثبت = 0x3
  };

/* DWARF5 package file section identifiers.  */
تعداد
  {
    DW_SECT_INFO = 1,
    /* Reserved = 2, */
    DW_SECT_ABBREV = 3,
    DW_SECT_کرښه = 4,
    DW_SECT_LOCLISTS = 5,
    DW_SECT_STR_OFFSETS = 6,
    DW_SECT_MACRO = 7,
    DW_SECT_RNGLISTS = 8,
  };


/* DWARF call frame instruction encodings.  */
تعداد
  {
    DW_CFA_advance_loc = 0x40,
    DW_CFA_دننه_واټن = 0x80,
    DW_CFA_restore = 0xc0,
    DW_CFA_extended = 0,

    DW_CFA_nop = 0x00,
    DW_CFA_سېټ_loc = 0x01,
    DW_CFA_advance_loc1 = 0x02,
    DW_CFA_advance_loc2 = 0x03,
    DW_CFA_advance_loc4 = 0x04,
    DW_CFA_دننه_واټن_extended = 0x05,
    DW_CFA_restore_extended = 0x06,
    DW_CFA_undefined = 0x07,
    DW_CFA_same_ارزښت = 0x08,
    DW_CFA_ثبتوونکی = 0x09,
    DW_CFA_remember_state = 0x0a,
    DW_CFA_restore_state = 0x0b,
    DW_CFA_def_cfa = 0x0c,
    DW_CFA_def_cfa_ثبتوونکی = 0x0d,
    DW_CFA_def_cfa_دننه_واټن = 0x0e,
    DW_CFA_def_cfa_افاده = 0x0f,
    DW_CFA_افاده = 0x10,
    DW_CFA_دننه_واټن_extended_sf = 0x11,
    DW_CFA_def_cfa_sf = 0x12,
    DW_CFA_def_cfa_دننه_واټن_sf = 0x13,
    DW_CFA_val_دننه_واټن = 0x14,
    DW_CFA_val_دننه_واټن_sf = 0x15,
    DW_CFA_val_افاده = 0x16,

    DW_CFA_ټیټ_user = 0x1c,
    DW_CFA_MIPS_advance_loc8 = 0x1d,
    DW_CFA_GNU_کړکۍ_save = 0x2d,
    DW_CFA_AARCH64_negate_ra_state = 0x2d,
    DW_CFA_GNU_دلیلونه_اندازه = 0x2e,
    DW_CFA_GNU_negative_دننه_واټن_extended = 0x2f,
    DW_CFA_لوړ_user = 0x3f
  };

/* ID indicating CIE as opposed to FDE in .debug_frame.  */
تعداد
  {
    DW_CIE_ID_32 = 0xffffffffU,		 /* In 32-bit format CIE header.  */
    DW_CIE_ID_64 = 0xffffffffffffffffULL /* In 64-bit format CIE header.  */
  };


/* Information for GNU unwind information.  */
تعداد
  {
    DW_EH_PE_absptr = 0x00,
    DW_EH_PE_omit = 0xff,

    /* FDE data encoding.  */
    DW_EH_PE_uleb128 = 0x01,
    DW_EH_PE_udata2 = 0x02,
    DW_EH_PE_udata4 = 0x03,
    DW_EH_PE_udata8 = 0x04,
    DW_EH_PE_sleb128 = 0x09,
    DW_EH_PE_sdata2 = 0x0a,
    DW_EH_PE_sdata4 = 0x0b,
    DW_EH_PE_sdata8 = 0x0c,
    DW_EH_PE_signed = 0x08,

    /* FDE flags.  */
    DW_EH_PE_pcrel = 0x10,
    DW_EH_PE_textrel = 0x20,
    DW_EH_PE_datarel = 0x30,
    DW_EH_PE_funcrel = 0x40,
    DW_EH_PE_aligned = 0x50,

    DW_EH_PE_غیرمستقیم = 0x80
  };


/* DWARF XXX.  */
#تعریف_کړه DW_ADDR_none	0

/* Section 7.2.2 of the DWARF3 specification defines a range of escape
   codes that can appear in the length field of certain DWARF structures.

   These defines enumerate the minimum and maximum values of this range.
   Currently only the maximum value is used (to indicate that 64-bit
   values are going to be used in the dwarf data that accompanies the
   structure).  The other values are reserved.

   Note: There is a typo in DWARF3 spec (published Dec 20, 2005).  In
   sections 7.4, 7.5.1, 7.19, 7.20 the minimum escape code is referred to
   as 0xffffff00 whereas in fact it should be 0xfffffff0.  */
#تعریف_کړه DWARF3_اوږدتیا_MIN_ESCAPE_کوډ 0xfffffff0u
#تعریف_کړه DWARF3_اوږدتیا_MAX_ESCAPE_کوډ 0xffffffffu
#تعریف_کړه DWARF3_اوږدتیا_64_بټ          DWARF3_اوږدتیا_MAX_ESCAPE_کوډ

#د_که_پای	/* dwarf.h */
