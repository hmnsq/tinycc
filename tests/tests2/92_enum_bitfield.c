/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
تعداد شجرة_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_شجرة_CODE
};
تعريفنوع اتحاد شجرة_عقدة *شجرة_2;
بنية شجرة_common
{
  اتحاد شجرة_عقدة *chain;
  اتحاد شجرة_عقدة *type;
  تعداد شجرة_code code : 8;
  unsigned side_effects_flag : 1;
};
اتحاد شجرة_عقدة
{
  بنية شجرة_common common;
 };
تعداد c_شجرة_code {
  C_DUMMY_شجرة_CODE = LAST_AND_UNUSED_شجرة_CODE,
  STMT_تعبير,
  LAST_C_شجرة_CODE
};
تعداد cplus_شجرة_code {
  CP_DUMMY_شجرة_CODE = LAST_C_شجرة_CODE,
  AMBIG_CONV,
  LAST_CPLUS_شجرة_CODE
};

خارجي صحيح printf(ثابت حرف *, ...);
صحيح blah(){أرجع 0;}

صحيح convert_like_real (شجرة_2 convs)
{
  بدل (((تعداد شجرة_code) (convs)->common.code))
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
  اتحاد شجرة_عقدة convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  أرجع 0;
}
