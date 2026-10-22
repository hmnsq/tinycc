/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
ગણના વૃક્ષ_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_વૃક્ષ_CODE
};
પ્રકારવ્યાખ્યા સંઘ વૃક્ષ_ગાંઠ *વૃક્ષ_2;
સંરચના વૃક્ષ_common
{
  સંઘ વૃક્ષ_ગાંઠ *chain;
  સંઘ વૃક્ષ_ગાંઠ *type;
  ગણના વૃક્ષ_code code : 8;
  unsigned side_effects_flag : 1;
};
સંઘ વૃક્ષ_ગાંઠ
{
  સંરચના વૃક્ષ_common common;
 };
ગણના c_વૃક્ષ_code {
  C_DUMMY_વૃક્ષ_CODE = LAST_AND_UNUSED_વૃક્ષ_CODE,
  STMT_પદાવલિ,
  LAST_C_વૃક્ષ_CODE
};
ગણના cplus_વૃક્ષ_code {
  CP_DUMMY_વૃક્ષ_CODE = LAST_C_વૃક્ષ_CODE,
  AMBIG_CONV,
  LAST_CPLUS_વૃક્ષ_CODE
};

બાહ્ય પૂર્ણાંક printf(અચલ અક્ષર *, ...);
પૂર્ણાંક blah(){પાછા 0;}

પૂર્ણાંક convert_like_real (વૃક્ષ_2 convs)
{
  પસંદગી (((ગણના વૃક્ષ_code) (convs)->common.code))
    {
    સ્થિતિ AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      પાછા blah();
    મૂળભૂત:
      તોડો;
    };
   printf("unsigned enum bit-fields broken\n");
   પાછા 0;
}

પૂર્ણાંક મુખ્ય()
{
  સંઘ વૃક્ષ_ગાંઠ convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  પાછા 0;
}
