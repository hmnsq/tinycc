/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
تعداد بشيا_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_بشيا_CODE
};
تعريفنوع اتحاد بشيا_كلي *بشيا_2;
بنية بشيا_common
{
  اتحاد بشيا_كلي *chain;
  اتحاد بشيا_كلي *type;
  تعداد بشيا_code code : 8;
  unsigned side_effects_flag : 1;
};
اتحاد بشيا_كلي
{
  بنية بشيا_common common;
 };
تعداد c_بشيا_code {
  C_DUMMY_بشيا_CODE = LAST_AND_UNUSED_بشيا_CODE,
  STMT_فرچ,
  LAST_C_بشيا_CODE
};
تعداد cplus_بشيا_code {
  CP_DUMMY_بشيا_CODE = LAST_C_بشيا_CODE,
  AMBIG_CONV,
  LAST_CPLUS_بشيا_CODE
};

خارجي صحيح printf(ثابت حرف *, ...);
صحيح blah(){أرجع 0;}

صحيح convert_like_real (بشيا_2 convs)
{
  بدل (((تعداد بشيا_code) (convs)->common.code))
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
  اتحاد بشيا_كلي convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  أرجع 0;
}
