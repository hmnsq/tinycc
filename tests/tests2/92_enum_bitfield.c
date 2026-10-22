/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
எண்ணிக்கை மரம்_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_மரம்_CODE
};
வகைவரை ஒன்றிப்பு மர_முனை *மரம்_2;
கட்டமைப்பு மரம்_common
{
  ஒன்றிப்பு மர_முனை *chain;
  ஒன்றிப்பு மர_முனை *type;
  எண்ணிக்கை மரம்_code code : 8;
  unsigned side_effects_flag : 1;
};
ஒன்றிப்பு மர_முனை
{
  கட்டமைப்பு மரம்_common common;
 };
எண்ணிக்கை c_மரம்_code {
  C_DUMMY_மரம்_CODE = LAST_AND_UNUSED_மரம்_CODE,
  STMT_கோவை,
  LAST_C_மரம்_CODE
};
எண்ணிக்கை cplus_மரம்_code {
  CP_DUMMY_மரம்_CODE = LAST_C_மரம்_CODE,
  AMBIG_CONV,
  LAST_CPLUS_மரம்_CODE
};

வெளி முழு printf(மாறிலி எழுத்து *, ...);
முழு blah(){திரும்பு 0;}

முழு convert_like_real (மரம்_2 convs)
{
  தேர்வு (((எண்ணிக்கை மரம்_code) (convs)->common.code))
    {
    நிலை AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      திரும்பு blah();
    இயல்பு:
      நிறுத்து;
    };
   printf("unsigned enum bit-fields broken\n");
   திரும்பு 0;
}

முழு முதன்மை()
{
  ஒன்றிப்பு மர_முனை convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  திரும்பு 0;
}
