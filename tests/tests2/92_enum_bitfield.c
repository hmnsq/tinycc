/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
شمار درخت_رمز {
  SOME_رمز = 148, /* has bit 7 set, and hence all further enum values as well */
  آخری_AND_غیر_مستعمل_درخت_رمز
};
قسمتعریف اتحاد درخت_گرہ *درخت_2;
ساخت درخت_common
{
  اتحاد درخت_گرہ *chain;
  اتحاد درخت_گرہ *type;
  شمار درخت_رمز رمز : 8;
  غیرعلامتی side_effects_flag : 1;
};
اتحاد درخت_گرہ
{
  ساخت درخت_common common;
 };
شمار c_درخت_رمز {
  C_DUMMY_درخت_رمز = آخری_AND_غیر_مستعمل_درخت_رمز,
  STMT_اظہاریہ,
  آخری_C_درخت_رمز
};
شمار cplus_درخت_رمز {
  CP_DUMMY_درخت_رمز = آخری_C_درخت_رمز,
  AMBIG_CONV,
  آخری_CPLUS_درخت_رمز
};

خارجی صحیح لکھو(ثابت حرف *, ...);
صحیح blah(){واپس 0;}

صحیح convert_like_real (درخت_2 convs)
{
  انتخاب (((شمار درخت_رمز) (convs)->common.رمز))
    {
    حالت AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      واپس blah();
    طےشدہ:
      توڑو;
    };
   لکھو("unsigned enum bit-fields broken\n");
   واپس 0;
}

صحیح مین()
{
  اتحاد درخت_گرہ convs;

  convs.common.رمز = AMBIG_CONV;
  convert_like_real (&convs);
  واپس 0;
}
