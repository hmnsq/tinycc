/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
تعداد درخت_کد {
  SOME_کد = 148, /* has bit 7 set, and hence all further enum values as well */
  آخرین_AND_استفادهنشده_درخت_کد
};
تعريفنوع اتحاد گره_درخت *درخت_2;
بنية درخت_common
{
  اتحاد گره_درخت *chain;
  اتحاد گره_درخت *type;
  تعداد درخت_کد کد : 8;
  بیعلامت side_effects_flag : 1;
};
اتحاد گره_درخت
{
  بنية درخت_common common;
 };
تعداد c_درخت_کد {
  C_DUMMY_درخت_کد = آخرین_AND_استفادهنشده_درخت_کد,
  STMT_عبارت,
  آخرین_C_درخت_کد
};
تعداد cplus_درخت_کد {
  CP_DUMMY_درخت_کد = آخرین_C_درخت_کد,
  AMBIG_CONV,
  آخرین_CPLUS_درخت_کد
};

خارجي صحيح چاپ_کن(ثابت حرف *, ...);
صحيح blah(){أرجع 0;}

صحيح convert_like_real (درخت_2 convs)
{
  بدل (((تعداد درخت_کد) (convs)->common.کد))
    {
    حالة AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      أرجع blah();
    افتراضي:
      اكسر;
    };
   چاپ_کن("unsigned enum bit-fields broken\n");
   أرجع 0;
}

صحيح اصلی()
{
  اتحاد گره_درخت convs;

  convs.common.کد = AMBIG_CONV;
  convert_like_real (&convs);
  أرجع 0;
}
