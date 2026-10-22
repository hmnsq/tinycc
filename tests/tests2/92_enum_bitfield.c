/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
গণনা বৃক্ষ_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_বৃক্ষ_CODE
};
প্রকারলেখ সংঘ বৃক্ষ_গ্রন্থি *বৃক্ষ_2;
কাঠামো বৃক্ষ_common
{
  সংঘ বৃক্ষ_গ্রন্থি *chain;
  সংঘ বৃক্ষ_গ্রন্থি *type;
  গণনা বৃক্ষ_code code : 8;
  unsigned side_effects_flag : 1;
};
সংঘ বৃক্ষ_গ্রন্থি
{
  কাঠামো বৃক্ষ_common common;
 };
গণনা c_বৃক্ষ_code {
  C_DUMMY_বৃক্ষ_CODE = LAST_AND_UNUSED_বৃক্ষ_CODE,
  STMT_রাশিমালা,
  LAST_C_বৃক্ষ_CODE
};
গণনা cplus_বৃক্ষ_code {
  CP_DUMMY_বৃক্ষ_CODE = LAST_C_বৃক্ষ_CODE,
  AMBIG_CONV,
  LAST_CPLUS_বৃক্ষ_CODE
};

বাহ্যিক পূর্ণসংখ্যা printf(ধ্রুবক অক্ষর *, ...);
পূর্ণসংখ্যা blah(){ফেরত 0;}

পূর্ণসংখ্যা convert_like_real (বৃক্ষ_2 convs)
{
  নির্বাচন (((গণনা বৃক্ষ_code) (convs)->common.code))
    {
    ক্ষেত্র AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      ফেরত blah();
    পূর্বনির্ধারিত:
      বিরতি;
    };
   printf("unsigned enum bit-fields broken\n");
   ফেরত 0;
}

পূর্ণসংখ্যা প্রধান()
{
  সংঘ বৃক্ষ_গ্রন্থি convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  ফেরত 0;
}
