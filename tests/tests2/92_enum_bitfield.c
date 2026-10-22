/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
تعداد درەخت_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_درەخت_CODE
};
تعريفنوع اتحاد گرێی_درەخت *درەخت_2;
بنية درەخت_common
{
  اتحاد گرێی_درەخت *chain;
  اتحاد گرێی_درەخت *type;
  تعداد درەخت_code code : 8;
  unsigned side_effects_flag : 1;
};
اتحاد گرێی_درەخت
{
  بنية درەخت_common common;
 };
تعداد c_درەخت_code {
  C_DUMMY_درەخت_CODE = LAST_AND_UNUSED_درەخت_CODE,
  STMT_دەربڕین,
  LAST_C_درەخت_CODE
};
تعداد cplus_درەخت_code {
  CP_DUMMY_درەخت_CODE = LAST_C_درەخت_CODE,
  AMBIG_CONV,
  LAST_CPLUS_درەخت_CODE
};

خارجي صحيح printf(ثابت حرف *, ...);
صحيح blah(){أرجع 0;}

صحيح convert_like_real (درەخت_2 convs)
{
  بدل (((تعداد درەخت_code) (convs)->common.code))
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
  اتحاد گرێی_درەخت convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  أرجع 0;
}
