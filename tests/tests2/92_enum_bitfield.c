/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
गणना वृक्ष_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_वृक्ष_CODE
};
प्रकारनिर्देश सङ्घ वृक्ष_गाँठ *वृक्ष_2;
संरचना वृक्ष_common
{
  सङ्घ वृक्ष_गाँठ *chain;
  सङ्घ वृक्ष_गाँठ *type;
  गणना वृक्ष_code code : 8;
  unsigned side_effects_flag : 1;
};
सङ्घ वृक्ष_गाँठ
{
  संरचना वृक्ष_common common;
 };
गणना c_वृक्ष_code {
  C_DUMMY_वृक्ष_CODE = LAST_AND_UNUSED_वृक्ष_CODE,
  STMT_व्यंजक,
  LAST_C_वृक्ष_CODE
};
गणना cplus_वृक्ष_code {
  CP_DUMMY_वृक्ष_CODE = LAST_C_वृक्ष_CODE,
  AMBIG_CONV,
  LAST_CPLUS_वृक्ष_CODE
};

बाह्य पूर्णाङ्क printf(ध्रुव वर्ण *, ...);
पूर्णाङ्क blah(){प्रत्यागम 0;}

पूर्णाङ्क convert_like_real (वृक्ष_2 convs)
{
  विकल्प (((गणना वृक्ष_code) (convs)->common.code))
    {
    पक्ष AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      प्रत्यागम blah();
    स्वभाव:
      भङ्ग;
    };
   printf("unsigned enum bit-fields broken\n");
   प्रत्यागम 0;
}

पूर्णाङ्क main()
{
  सङ्घ वृक्ष_गाँठ convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  प्रत्यागम 0;
}
