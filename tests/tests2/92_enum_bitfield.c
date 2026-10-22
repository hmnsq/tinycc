/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
تعداد ڤوکوق_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_ڤوکوق_CODE
};
تعريفنوع اتحاد نود_ڤوکوق *ڤوکوق_2;
بنية ڤوکوق_common
{
  اتحاد نود_ڤوکوق *chain;
  اتحاد نود_ڤوکوق *type;
  تعداد ڤوکوق_code code : 8;
  unsigned side_effects_flag : 1;
};
اتحاد نود_ڤوکوق
{
  بنية ڤوکوق_common common;
 };
تعداد c_ڤوکوق_code {
  C_DUMMY_ڤوکوق_CODE = LAST_AND_UNUSED_ڤوکوق_CODE,
  STMT_اوڠکاڤن,
  LAST_C_ڤوکوق_CODE
};
تعداد cplus_ڤوکوق_code {
  CP_DUMMY_ڤوکوق_CODE = LAST_C_ڤوکوق_CODE,
  AMBIG_CONV,
  LAST_CPLUS_ڤوکوق_CODE
};

خارجي صحيح printf(ثابت حرف *, ...);
صحيح blah(){أرجع 0;}

صحيح convert_like_real (ڤوکوق_2 convs)
{
  بدل (((تعداد ڤوکوق_code) (convs)->common.code))
    {
    حالة AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      أرجع blah();
    افتراضي:
      اكسر;
    };
   printf("unsigned enum bit-fields broken\n");
   أرجع 0;
}

صحيح main()
{
  اتحاد نود_ڤوکوق convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  أرجع 0;
}
