/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
গণনা বৃক্ষ_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_বৃক্ষ_CODE
};
প্রকারনির্দেশ সঙ্ঘ বৃক্ষ_গ্ৰন্থি *বৃক্ষ_2;
সংরচনা বৃক্ষ_common
{
  সঙ্ঘ বৃক্ষ_গ্ৰন্থি *chain;
  সঙ্ঘ বৃক্ষ_গ্ৰন্থি *type;
  গণনা বৃক্ষ_code code : 8;
  unsigned side_effects_flag : 1;
};
সঙ্ঘ বৃক্ষ_গ্ৰন্থি
{
  সংরচনা বৃক্ষ_common common;
 };
গণনা c_বৃক্ষ_code {
  C_DUMMY_বৃক্ষ_CODE = LAST_AND_UNUSED_বৃক্ষ_CODE,
  STMT_ৰাশিমালা,
  LAST_C_বৃক্ষ_CODE
};
গণনা cplus_বৃক্ষ_code {
  CP_DUMMY_বৃক্ষ_CODE = LAST_C_বৃক্ষ_CODE,
  AMBIG_CONV,
  LAST_CPLUS_বৃক্ষ_CODE
};

বাহ্য পূর্ণাঙ্ক printf(ধ্রুৱ ৱর্ণ *, ...);
পূর্ণাঙ্ক blah(){ঘূৰাই 0;}

পূর্ণাঙ্ক convert_like_real (বৃক্ষ_2 convs)
{
  ৱিকল্প (((গণনা বৃক্ষ_code) (convs)->common.code))
    {
    পক্ষ AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      ঘূৰাই blah();
    স্ৱভাৱ:
      ভঙ্গ;
    };
   printf("unsigned enum bit-fields broken\n");
   ঘূৰাই 0;
}

পূর্ণাঙ্ক main()
{
  সঙ্ঘ বৃক্ষ_গ্ৰন্থি convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  ঘূৰাই 0;
}
