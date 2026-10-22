/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
ଗଣନା ବୃକ୍ଷ_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_ବୃକ୍ଷ_CODE
};
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂଘ ବୃକ୍ଷ_ଗଣ୍ଠି *ବୃକ୍ଷ_2;
ସଂରଚନା ବୃକ୍ଷ_common
{
  ସଂଘ ବୃକ୍ଷ_ଗଣ୍ଠି *chain;
  ସଂଘ ବୃକ୍ଷ_ଗଣ୍ଠି *type;
  ଗଣନା ବୃକ୍ଷ_code code : 8;
  unsigned side_effects_flag : 1;
};
ସଂଘ ବୃକ୍ଷ_ଗଣ୍ଠି
{
  ସଂରଚନା ବୃକ୍ଷ_common common;
 };
ଗଣନା c_ବୃକ୍ଷ_code {
  C_DUMMY_ବୃକ୍ଷ_CODE = LAST_AND_UNUSED_ବୃକ୍ଷ_CODE,
  STMT_ପଦସମଷ୍ଟି,
  LAST_C_ବୃକ୍ଷ_CODE
};
ଗଣନା cplus_ବୃକ୍ଷ_code {
  CP_DUMMY_ବୃକ୍ଷ_CODE = LAST_C_ବୃକ୍ଷ_CODE,
  AMBIG_CONV,
  LAST_CPLUS_ବୃକ୍ଷ_CODE
};

ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf(ଅଚଳ ଅକ୍ଷର *, ...);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା blah(){ଫେରନ୍ତୁ 0;}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା convert_like_real (ବୃକ୍ଷ_2 convs)
{
  ବାଛ (((ଗଣନା ବୃକ୍ଷ_code) (convs)->common.code))
    {
    ସ୍ଥିତି AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      ଫେରନ୍ତୁ blah();
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
      ଭାଙ୍ଗ;
    };
   printf("unsigned enum bit-fields broken\n");
   ଫେରନ୍ତୁ 0;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
  ସଂଘ ବୃକ୍ଷ_ଗଣ୍ଠି convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  ଫେରନ୍ତୁ 0;
}
