/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
ಗಣನಾ ವೃಕ್ಷ_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_ವೃಕ್ಷ_CODE
};
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಙ್ಘ ವೃಕ್ಷ_ಗಂಟು *ವೃಕ್ಷ_2;
ಸಂರಚನಾ ವೃಕ್ಷ_common
{
  ಸಙ್ಘ ವೃಕ್ಷ_ಗಂಟು *chain;
  ಸಙ್ಘ ವೃಕ್ಷ_ಗಂಟು *type;
  ಗಣನಾ ವೃಕ್ಷ_code code : 8;
  unsigned side_effects_flag : 1;
};
ಸಙ್ಘ ವೃಕ್ಷ_ಗಂಟು
{
  ಸಂರಚನಾ ವೃಕ್ಷ_common common;
 };
ಗಣನಾ c_ವೃಕ್ಷ_code {
  C_DUMMY_ವೃಕ್ಷ_CODE = LAST_AND_UNUSED_ವೃಕ್ಷ_CODE,
  STMT_ಅಭಿವ್ಯಕ್ತಿ,
  LAST_C_ವೃಕ್ಷ_CODE
};
ಗಣನಾ cplus_ವೃಕ್ಷ_code {
  CP_DUMMY_ವೃಕ್ಷ_CODE = LAST_C_ವೃಕ್ಷ_CODE,
  AMBIG_CONV,
  LAST_CPLUS_ವೃಕ್ಷ_CODE
};

ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ printf(ಧ್ರುವ ವರ್ಣ *, ...);
ಪೂರ್ಣಾಙ್ಕ blah(){ಪ್ರತ್ಯಾಗಮ 0;}

ಪೂರ್ಣಾಙ್ಕ convert_like_real (ವೃಕ್ಷ_2 convs)
{
  ವಿಕಲ್ಪ (((ಗಣನಾ ವೃಕ್ಷ_code) (convs)->common.code))
    {
    ಪಕ್ಷ AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      ಪ್ರತ್ಯಾಗಮ blah();
    ಸ್ವಭಾವ:
      ಭಙ್ಗ;
    };
   printf("unsigned enum bit-fields broken\n");
   ಪ್ರತ್ಯಾಗಮ 0;
}

ಪೂರ್ಣಾಙ್ಕ main()
{
  ಸಙ್ಘ ವೃಕ್ಷ_ಗಂಟು convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  ಪ್ರತ್ಯಾಗಮ 0;
}
