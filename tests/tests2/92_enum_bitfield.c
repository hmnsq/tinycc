/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
गणना रूख_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_रूख_CODE
};
प्रकारनिर्देश सङ्घ रूख_गाँठो *रूख_2;
संरचना रूख_common
{
  सङ्घ रूख_गाँठो *chain;
  सङ्घ रूख_गाँठो *type;
  गणना रूख_code code : 8;
  अचिन्हित side_effects_flag : 1;
};
सङ्घ रूख_गाँठो
{
  संरचना रूख_common common;
 };
गणना c_रूख_code {
  C_DUMMY_रूख_CODE = LAST_AND_UNUSED_रूख_CODE,
  STMT_अभिव्यक्ति,
  LAST_C_रूख_CODE
};
गणना cplus_रूख_code {
  CP_DUMMY_रूख_CODE = LAST_C_रूख_CODE,
  AMBIG_CONV,
  LAST_CPLUS_रूख_CODE
};

बाह्य पूर्णाङ्क म_लिखो(अचर वर्ण *, ...);
पूर्णाङ्क blah(){फर्काऊ 0;}

पूर्णाङ्क convert_like_real (रूख_2 convs)
{
  विकल्प (((गणना रूख_code) (convs)->common.code))
    {
    पक्ष AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      फर्काऊ blah();
    स्वभाव:
      रोक;
    };
   म_लिखो("unsigned enum bit-fields broken\n");
   फर्काऊ 0;
}

पूर्णाङ्क main()
{
  सङ्घ रूख_गाँठो convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  फर्काऊ 0;
}
