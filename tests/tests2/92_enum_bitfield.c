/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
क्रमागत वृक्ष_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_वृक्ष_CODE
};
प्रकार जोड़ वृक्ष_गाँठ *वृक्ष_2;
काष्ठा वृक्ष_common
{
  जोड़ वृक्ष_गाँठ *chain;
  जोड़ वृक्ष_गाँठ *type;
  क्रमागत वृक्ष_code code : 8;
  अचिन्हित side_effects_flag : 1;
};
जोड़ वृक्ष_गाँठ
{
  काष्ठा वृक्ष_common common;
 };
क्रमागत c_वृक्ष_code {
  C_DUMMY_वृक्ष_CODE = LAST_AND_UNUSED_वृक्ष_CODE,
  STMT_व्यंजक,
  LAST_C_वृक्ष_CODE
};
क्रमागत cplus_वृक्ष_code {
  CP_DUMMY_वृक्ष_CODE = LAST_C_वृक्ष_CODE,
  AMBIG_CONV,
  LAST_CPLUS_वृक्ष_CODE
};

बाह्य पूर्णांक म_लिखो(स्थिर अक्षर *, ...);
पूर्णांक blah(){वापस 0;}

पूर्णांक convert_like_real (वृक्ष_2 convs)
{
  चयन (((क्रमागत वृक्ष_code) (convs)->common.code))
    {
    हाल AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      वापस blah();
    शेष:
      अवरोध;
    };
   म_लिखो("unsigned enum bit-fields broken\n");
   वापस 0;
}

पूर्णांक मुख्य()
{
  जोड़ वृक्ष_गाँठ convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  वापस 0;
}
