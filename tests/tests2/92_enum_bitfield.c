/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
गणना वृक्षः_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_वृक्षः_CODE
};
प्रकारनिर्देश सङ्घ वृक्ष_ग्रन्थिः *वृक्षः_2;
संरचना वृक्षः_common
{
  सङ्घ वृक्ष_ग्रन्थिः *chain;
  सङ्घ वृक्ष_ग्रन्थिः *type;
  गणना वृक्षः_code code : 8;
  unsigned side_effects_flag : 1;
};
सङ्घ वृक्ष_ग्रन्थिः
{
  संरचना वृक्षः_common common;
 };
गणना c_वृक्षः_code {
  C_DUMMY_वृक्षः_CODE = LAST_AND_UNUSED_वृक्षः_CODE,
  STMT_व्यञ्जकम्,
  LAST_C_वृक्षः_CODE
};
गणना cplus_वृक्षः_code {
  CP_DUMMY_वृक्षः_CODE = LAST_C_वृक्षः_CODE,
  AMBIG_CONV,
  LAST_CPLUS_वृक्षः_CODE
};

बाह्य पूर्णाङ्क printf(ध्रुव वर्ण *, ...);
पूर्णाङ्क blah(){पटिनिवत्त 0;}

पूर्णाङ्क convert_like_real (वृक्षः_2 convs)
{
  विकल्प (((गणना वृक्षः_code) (convs)->common.code))
    {
    पक्ष AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      पटिनिवत्त blah();
    स्वभाव:
      भङ्ग;
    };
   printf("unsigned enum bit-fields broken\n");
   पटिनिवत्त 0;
}

पूर्णाङ्क main()
{
  सङ्घ वृक्ष_ग्रन्थिः convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  पटिनिवत्त 0;
}
