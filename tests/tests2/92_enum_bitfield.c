/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
تعداد وڻ_ڪوڊ {
  SOME_ڪوڊ = 148, /* has bit 7 set, and hence all further enum values as well */
  آخري_AND_اڻ_استعمال_ٿيل_وڻ_ڪوڊ
};
تعريفنوع اتحاد وڻ_ڳنڍ *وڻ_2;
بنية وڻ_common
{
  اتحاد وڻ_ڳنڍ *chain;
  اتحاد وڻ_ڳنڍ *type;
  تعداد وڻ_ڪوڊ ڪوڊ : 8;
  بنانشان side_effects_flag : 1;
};
اتحاد وڻ_ڳنڍ
{
  بنية وڻ_common common;
 };
تعداد c_وڻ_ڪوڊ {
  C_DUMMY_وڻ_ڪوڊ = آخري_AND_اڻ_استعمال_ٿيل_وڻ_ڪوڊ,
  STMT_اظهار,
  آخري_C_وڻ_ڪوڊ
};
تعداد cplus_وڻ_ڪوڊ {
  CP_DUMMY_وڻ_ڪوڊ = آخري_C_وڻ_ڪوڊ,
  AMBIG_CONV,
  آخري_CPLUS_وڻ_ڪوڊ
};

خارجي صحيح لکو(ثابت حرف *, ...);
صحيح blah(){أرجع 0;}

صحيح convert_like_real (وڻ_2 convs)
{
  بدل (((تعداد وڻ_ڪوڊ) (convs)->common.ڪوڊ))
    {
    حالة AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      أرجع blah();
    افتراضي:
      اكسر;
    };
   لکو("unsigned enum bit-fields broken\n");
   أرجع 0;
}

صحيح مکيه()
{
  اتحاد وڻ_ڳنڍ convs;

  convs.common.ڪوڊ = AMBIG_CONV;
  convert_like_real (&convs);
  أرجع 0;
}
