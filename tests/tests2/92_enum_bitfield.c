/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
تعداد دەرەخ_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_دەرەخ_CODE
};
تعريفنوع اتحاد دەرەخ_تۈگۈنى *دەرەخ_2;
بنية دەرەخ_common
{
  اتحاد دەرەخ_تۈگۈنى *chain;
  اتحاد دەرەخ_تۈگۈنى *type;
  تعداد دەرەخ_code code : 8;
  unsigned side_effects_flag : 1;
};
اتحاد دەرەخ_تۈگۈنى
{
  بنية دەرەخ_common common;
 };
تعداد c_دەرەخ_code {
  C_DUMMY_دەرەخ_CODE = LAST_AND_UNUSED_دەرەخ_CODE,
  STMT_ئىپادە,
  LAST_C_دەرەخ_CODE
};
تعداد cplus_دەرەخ_code {
  CP_DUMMY_دەرەخ_CODE = LAST_C_دەرەخ_CODE,
  AMBIG_CONV,
  LAST_CPLUS_دەرەخ_CODE
};

خارجي صحيح printf(ثابت حرف *, ...);
صحيح blah(){أرجع 0;}

صحيح convert_like_real (دەرەخ_2 convs)
{
  بدل (((تعداد دەرەخ_code) (convs)->common.code))
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
  اتحاد دەرەخ_تۈگۈنى convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  أرجع 0;
}
