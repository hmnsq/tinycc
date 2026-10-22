/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
गणना वृक्ष_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_वृक्ष_CODE
};
प्रकारव्याख्या संघ वृक्ष_गाठ *वृक्ष_2;
संरचना वृक्ष_common
{
  संघ वृक्ष_गाठ *chain;
  संघ वृक्ष_गाठ *type;
  गणना वृक्ष_code code : 8;
  अचिन्हित side_effects_flag : 1;
};
संघ वृक्ष_गाठ
{
  संरचना वृक्ष_common common;
 };
गणना c_वृक्ष_code {
  C_DUMMY_वृक्ष_CODE = LAST_AND_UNUSED_वृक्ष_CODE,
  STMT_अभिव्यक्ती,
  LAST_C_वृक्ष_CODE
};
गणना cplus_वृक्ष_code {
  CP_DUMMY_वृक्ष_CODE = LAST_C_वृक्ष_CODE,
  AMBIG_CONV,
  LAST_CPLUS_वृक्ष_CODE
};

बाह्य पूर्णांक म_लिखो(स्थिरांक अक्षर *, ...);
पूर्णांक blah(){परत 0;}

पूर्णांक convert_like_real (वृक्ष_2 convs)
{
  निवड (((गणना वृक्ष_code) (convs)->common.code))
    {
    स्थिती AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      परत blah();
    पूर्वनिर्धारित:
      थांबा;
    };
   म_लिखो("unsigned enum bit-fields broken\n");
   परत 0;
}

पूर्णांक main()
{
  संघ वृक्ष_गाठ convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  परत 0;
}
