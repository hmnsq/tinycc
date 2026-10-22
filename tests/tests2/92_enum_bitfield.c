/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
എണ്ണൽ വൃക്ഷം_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_വൃക്ഷം_CODE
};
തരനിർവചനം സംഘം വൃക്ഷ_കണ്ണി *വൃക്ഷം_2;
ഘടന വൃക്ഷം_common
{
  സംഘം വൃക്ഷ_കണ്ണി *chain;
  സംഘം വൃക്ഷ_കണ്ണി *type;
  എണ്ണൽ വൃക്ഷം_code code : 8;
  unsigned side_effects_flag : 1;
};
സംഘം വൃക്ഷ_കണ്ണി
{
  ഘടന വൃക്ഷം_common common;
 };
എണ്ണൽ c_വൃക്ഷം_code {
  C_DUMMY_വൃക്ഷം_CODE = LAST_AND_UNUSED_വൃക്ഷം_CODE,
  STMT_വ്യഞ്ജകം,
  LAST_C_വൃക്ഷം_CODE
};
എണ്ണൽ cplus_വൃക്ഷം_code {
  CP_DUMMY_വൃക്ഷം_CODE = LAST_C_വൃക്ഷം_CODE,
  AMBIG_CONV,
  LAST_CPLUS_വൃക്ഷം_CODE
};

ബാഹ്യ പൂർണ്ണസംഖ്യ printf(സ്ഥിരം അക്ഷരം *, ...);
പൂർണ്ണസംഖ്യ blah(){തിരികെ 0;}

പൂർണ്ണസംഖ്യ convert_like_real (വൃക്ഷം_2 convs)
{
  തിരഞ്ഞെടുപ്പ് (((എണ്ണൽ വൃക്ഷം_code) (convs)->common.code))
    {
    അവസ്ഥ AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      തിരികെ blah();
    സ്ഥിരസ്ഥിതി:
      നിർത്തുക;
    };
   printf("unsigned enum bit-fields broken\n");
   തിരികെ 0;
}

പൂർണ്ണസംഖ്യ പ്രധാന()
{
  സംഘം വൃക്ഷ_കണ്ണി convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  തിരികെ 0;
}
