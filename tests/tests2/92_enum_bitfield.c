/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
شمارش درخت_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_درخت_CODE
};
تعریفنوع اجتماع گره_درخت *درخت_2;
ساختار درخت_common
{
  اجتماع گره_درخت *chain;
  اجتماع گره_درخت *type;
  شمارش درخت_code code : 8;
  unsigned side_effects_flag : 1;
};
اجتماع گره_درخت
{
  ساختار درخت_common common;
 };
شمارش c_درخت_code {
  C_DUMMY_درخت_CODE = LAST_AND_UNUSED_درخت_CODE,
  STMT_عبارت,
  LAST_C_درخت_CODE
};
شمارش cplus_درخت_code {
  CP_DUMMY_درخت_CODE = LAST_C_درخت_CODE,
  AMBIG_CONV,
  LAST_CPLUS_درخت_CODE
};

بیرونی صحیح printf(ثابت نویسه *, ...);
صحیح blah(){بازگشت 0;}

صحیح convert_like_real (درخت_2 convs)
{
  انتخاب (((شمارش درخت_code) (convs)->common.code))
    {
    حالت AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      بازگشت blah();
    پیشفرض:
      بشکن;
    };
   printf("unsigned enum bit-fields broken\n");
   بازگشت 0;
}

صحیح اصلی()
{
  اجتماع گره_درخت convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  بازگشت 0;
}
