/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
ਗਿਣਤੀ ਰੁੱਖ_ਕੋਡ {
  SOME_ਕੋਡ = 148, /* has bit 7 set, and hence all further enum values as well */
  ਆਖਰੀ_AND_ਅਣਵਰਤਿਆ_ਰੁੱਖ_ਕੋਡ
};
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ ਰੁੱਖ_ਗੰਢ *ਰੁੱਖ_2;
ਬਣਤਰ ਰੁੱਖ_common
{
  ਸੰਘ ਰੁੱਖ_ਗੰਢ *chain;
  ਸੰਘ ਰੁੱਖ_ਗੰਢ *type;
  ਗਿਣਤੀ ਰੁੱਖ_ਕੋਡ ਕੋਡ : 8;
  ਬਿਨਾਨਿਸ਼ਾਨੀ side_effects_flag : 1;
};
ਸੰਘ ਰੁੱਖ_ਗੰਢ
{
  ਬਣਤਰ ਰੁੱਖ_common common;
 };
ਗਿਣਤੀ c_ਰੁੱਖ_ਕੋਡ {
  C_DUMMY_ਰੁੱਖ_ਕੋਡ = ਆਖਰੀ_AND_ਅਣਵਰਤਿਆ_ਰੁੱਖ_ਕੋਡ,
  STMT_ਵਿਅੰਜਕ,
  ਆਖਰੀ_C_ਰੁੱਖ_ਕੋਡ
};
ਗਿਣਤੀ cplus_ਰੁੱਖ_ਕੋਡ {
  CP_DUMMY_ਰੁੱਖ_ਕੋਡ = ਆਖਰੀ_C_ਰੁੱਖ_ਕੋਡ,
  AMBIG_CONV,
  ਆਖਰੀ_CPLUS_ਰੁੱਖ_ਕੋਡ
};

ਬਾਹਰੀ ਪੂਰਨ ਲਿਖੋ(ਅਚਲ ਅੱਖਰ *, ...);
ਪੂਰਨ blah(){ਵਾਪਸ 0;}

ਪੂਰਨ convert_like_real (ਰੁੱਖ_2 convs)
{
  ਚੋਣ (((ਗਿਣਤੀ ਰੁੱਖ_ਕੋਡ) (convs)->common.ਕੋਡ))
    {
    ਹਾਲਤ AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      ਵਾਪਸ blah();
    ਮੂਲ:
      ਰੋਕੋ;
    };
   ਲਿਖੋ("unsigned enum bit-fields broken\n");
   ਵਾਪਸ 0;
}

ਪੂਰਨ ਮੁੱਖ()
{
  ਸੰਘ ਰੁੱਖ_ਗੰਢ convs;

  convs.common.ਕੋਡ = AMBIG_CONV;
  convert_like_real (&convs);
  ਵਾਪਸ 0;
}
