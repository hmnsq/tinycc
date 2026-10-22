/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
गणना वृक्षः_संहिता {
  SOME_संहिता = 148, /* has bit 7 set, and hence all further enum values as well */
  चरमः_AND_अप्रयुक्तम्_वृक्षः_संहिता
};
प्रकारनिर्देश सङ्घ वृक्ष_ग्रन्थिः *वृक्षः_2;
संरचना वृक्षः_common
{
  सङ्घ वृक्ष_ग्रन्थिः *chain;
  सङ्घ वृक्ष_ग्रन्थिः *type;
  गणना वृक्षः_संहिता संहिता : 8;
  अचिह्नित side_effects_flag : 1;
};
सङ्घ वृक्ष_ग्रन्थिः
{
  संरचना वृक्षः_common common;
 };
गणना c_वृक्षः_संहिता {
  C_DUMMY_वृक्षः_संहिता = चरमः_AND_अप्रयुक्तम्_वृक्षः_संहिता,
  STMT_व्यञ्जकम्,
  चरमः_C_वृक्षः_संहिता
};
गणना cplus_वृक्षः_संहिता {
  CP_DUMMY_वृक्षः_संहिता = चरमः_C_वृक्षः_संहिता,
  AMBIG_CONV,
  चरमः_CPLUS_वृक्षः_संहिता
};

बाह्य पूर्णाङ्क प्रारूप_लिख(ध्रुव वर्ण *, ...);
पूर्णाङ्क blah(){प्रत्यागम 0;}

पूर्णाङ्क convert_like_real (वृक्षः_2 convs)
{
  विकल्प (((गणना वृक्षः_संहिता) (convs)->common.संहिता))
    {
    पक्ष AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      प्रत्यागम blah();
    स्वभाव:
      भङ्ग;
    };
   प्रारूप_लिख("unsigned enum bit-fields broken\n");
   प्रत्यागम 0;
}

पूर्णाङ्क मुख्यम्()
{
  सङ्घ वृक्ष_ग्रन्थिः convs;

  convs.common.संहिता = AMBIG_CONV;
  convert_like_real (&convs);
  प्रत्यागम 0;
}
