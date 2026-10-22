/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
تعداد درخت_کوڈ {
  SOME_کوڈ = 148, /* has bit 7 set, and hence all further enum values as well */
  آخری_AND_بن_ورتیا_درخت_کوڈ
};
تعريفنوع اتحاد درخت_گرہ *درخت_2;
بنية درخت_common
{
  اتحاد درخت_گرہ *chain;
  اتحاد درخت_گرہ *type;
  تعداد درخت_کوڈ کوڈ : 8;
  بنانشانی side_effects_flag : 1;
};
اتحاد درخت_گرہ
{
  بنية درخت_common common;
 };
تعداد c_درخت_کوڈ {
  C_DUMMY_درخت_کوڈ = آخری_AND_بن_ورتیا_درخت_کوڈ,
  STMT_اظہاریہ,
  آخری_C_درخت_کوڈ
};
تعداد cplus_درخت_کوڈ {
  CP_DUMMY_درخت_کوڈ = آخری_C_درخت_کوڈ,
  AMBIG_CONV,
  آخری_CPLUS_درخت_کوڈ
};

خارجي صحيح لکھو(ثابت حرف *, ...);
صحيح blah(){أرجع 0;}

صحيح convert_like_real (درخت_2 convs)
{
  بدل (((تعداد درخت_کوڈ) (convs)->common.کوڈ))
    {
    حالة AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      أرجع blah();
    افتراضي:
      اكسر;
    };
   لکھو("unsigned enum bit-fields broken\n");
   أرجع 0;
}

صحيح مکھ()
{
  اتحاد درخت_گرہ convs;

  convs.common.کوڈ = AMBIG_CONV;
  convert_like_real (&convs);
  أرجع 0;
}
