/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
تعداد درخت_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_درخت_CODE
};
تعريفنوع اتحاد درخت_گرہ *درخت_2;
بنية درخت_common
{
  اتحاد درخت_گرہ *chain;
  اتحاد درخت_گرہ *type;
  تعداد درخت_code code : 8;
  unsigned side_effects_flag : 1;
};
اتحاد درخت_گرہ
{
  بنية درخت_common common;
 };
تعداد c_درخت_code {
  C_DUMMY_درخت_CODE = LAST_AND_UNUSED_درخت_CODE,
  STMT_اظہاریہ,
  LAST_C_درخت_CODE
};
تعداد cplus_درخت_code {
  CP_DUMMY_درخت_CODE = LAST_C_درخت_CODE,
  AMBIG_CONV,
  LAST_CPLUS_درخت_CODE
};

خارجي صحيح printf(ثابت حرف *, ...);
صحيح blah(){أرجع 0;}

صحيح convert_like_real (درخت_2 convs)
{
  بدل (((تعداد درخت_code) (convs)->common.code))
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
  اتحاد درخت_گرہ convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  أرجع 0;
}
