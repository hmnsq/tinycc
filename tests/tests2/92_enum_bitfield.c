/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
تعداد tree_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_TREE_CODE
};
تعريفنوع اتحاد tree_node *tree;
بنية tree_common
{
  اتحاد tree_node *chain;
  اتحاد tree_node *type;
  تعداد tree_code code : 8;
  unsigned side_effects_flag : 1;
};
اتحاد tree_node
{
  بنية tree_common common;
 };
تعداد c_tree_code {
  C_DUMMY_TREE_CODE = LAST_AND_UNUSED_TREE_CODE,
  STMT_EXPR,
  LAST_C_TREE_CODE
};
تعداد cplus_tree_code {
  CP_DUMMY_TREE_CODE = LAST_C_TREE_CODE,
  AMBIG_CONV,
  LAST_CPLUS_TREE_CODE
};

خارجي صحيح printf(ثابت حرف *, ...);
صحيح blah(){החזר 0;}

صحيح convert_like_real (tree convs)
{
  بدل (((تعداد tree_code) (convs)->common.code))
    {
    حالة AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      החזר blah();
    افتراضي:
      اكسر;
    };
   printf("unsigned enum bit-fields broken\n");
   החזר 0;
}

صحيح main()
{
  اتحاد tree_node convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  החזר 0;
}
