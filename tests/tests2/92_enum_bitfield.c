/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
ಎಣಿಕೆ ವೃಕ್ಷ_ಸಂಕೇತ {
  SOME_ಸಂಕೇತ = 148, /* has bit 7 set, and hence all further enum values as well */
  ಕೊನೆಯ_AND_ಬಳಸದ_ವೃಕ್ಷ_ಸಂಕೇತ
};
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ ವೃಕ್ಷ_ಗಂಟು *ವೃಕ್ಷ_2;
ರಚನೆ ವೃಕ್ಷ_common
{
  ಒಕ್ಕೂಟ ವೃಕ್ಷ_ಗಂಟು *chain;
  ಒಕ್ಕೂಟ ವೃಕ್ಷ_ಗಂಟು *type;
  ಎಣಿಕೆ ವೃಕ್ಷ_ಸಂಕೇತ ಸಂಕೇತ_2 : 8;
  ಚಿಹ್ನೆರಹಿತ side_effects_flag : 1;
};
ಒಕ್ಕೂಟ ವೃಕ್ಷ_ಗಂಟು
{
  ರಚನೆ ವೃಕ್ಷ_common common;
 };
ಎಣಿಕೆ c_ವೃಕ್ಷ_ಸಂಕೇತ {
  C_DUMMY_ವೃಕ್ಷ_ಸಂಕೇತ = ಕೊನೆಯ_AND_ಬಳಸದ_ವೃಕ್ಷ_ಸಂಕೇತ,
  STMT_ಅಭಿವ್ಯಕ್ತಿ,
  ಕೊನೆಯ_C_ವೃಕ್ಷ_ಸಂಕೇತ
};
ಎಣಿಕೆ cplus_ವೃಕ್ಷ_ಸಂಕೇತ {
  CP_DUMMY_ವೃಕ್ಷ_ಸಂಕೇತ = ಕೊನೆಯ_C_ವೃಕ್ಷ_ಸಂಕೇತ,
  AMBIG_CONV,
  ಕೊನೆಯ_CPLUS_ವೃಕ್ಷ_ಸಂಕೇತ
};

ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ ಬರೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *, ...);
ಪೂರ್ಣಾಂಕ blah(){ಹಿಂತಿರುಗಿ 0;}

ಪೂರ್ಣಾಂಕ convert_like_real (ವೃಕ್ಷ_2 convs)
{
  ಆಯ್ಕೆ (((ಎಣಿಕೆ ವೃಕ್ಷ_ಸಂಕೇತ) (convs)->common.ಸಂಕೇತ_2))
    {
    ಸ್ಥಿತಿ AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      ಹಿಂತಿರುಗಿ blah();
    ಪೂರ್ವನಿಯೋಜಿತ:
      ನಿಲ್ಲಿಸು;
    };
   ಬರೆ("unsigned enum bit-fields broken\n");
   ಹಿಂತಿರುಗಿ 0;
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
  ಒಕ್ಕೂಟ ವೃಕ್ಷ_ಗಂಟು convs;

  convs.common.ಸಂಕೇತ_2 = AMBIG_CONV;
  convert_like_real (&convs);
  ಹಿಂತಿರುಗಿ 0;
}
