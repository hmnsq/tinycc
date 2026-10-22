/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
تعداد ونه_کوډ {
  SOME_کوډ = 148, /* has bit 7 set, and hence all further enum values as well */
  وروستی_AND_ناکارول_شوی_ونه_کوډ
};
تعريفنوع اتحاد ونې_غوټه *ونه_2;
بنية ونه_common
{
  اتحاد ونې_غوټه *chain;
  اتحاد ونې_غوټه *type;
  تعداد ونه_کوډ کوډ : 8;
  بینښه side_effects_flag : 1;
};
اتحاد ونې_غوټه
{
  بنية ونه_common common;
 };
تعداد c_ونه_کوډ {
  C_DUMMY_ونه_کوډ = وروستی_AND_ناکارول_شوی_ونه_کوډ,
  STMT_بیان,
  وروستی_C_ونه_کوډ
};
تعداد cplus_ونه_کوډ {
  CP_DUMMY_ونه_کوډ = وروستی_C_ونه_کوډ,
  AMBIG_CONV,
  وروستی_CPLUS_ونه_کوډ
};

خارجي صحيح چاپ_کړه(ثابت حرف *, ...);
صحيح blah(){أرجع 0;}

صحيح convert_like_real (ونه_2 convs)
{
  بدل (((تعداد ونه_کوډ) (convs)->common.کوډ))
    {
    حالة AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      أرجع blah();
    افتراضي:
      اكسر;
    };
   چاپ_کړه("unsigned enum bit-fields broken\n");
   أرجع 0;
}

صحيح اصلي()
{
  اتحاد ونې_غوټه convs;

  convs.common.کوډ = AMBIG_CONV;
  convert_like_real (&convs);
  أرجع 0;
}
