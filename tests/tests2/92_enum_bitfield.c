/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
గణన వృక్షం_సంకేతం {
  SOME_సంకేతం = 148, /* has bit 7 set, and hence all further enum values as well */
  చివరి_AND_వాడని_వృక్షం_సంకేతం
};
రకనిర్వచనం సంఘం వృక్ష_కణుపు *వృక్షం_2;
నిర్మాణం వృక్షం_common
{
  సంఘం వృక్ష_కణుపు *chain;
  సంఘం వృక్ష_కణుపు *type;
  గణన వృక్షం_సంకేతం సంకేతం_2 : 8;
  గుర్తులేని side_effects_flag : 1;
};
సంఘం వృక్ష_కణుపు
{
  నిర్మాణం వృక్షం_common common;
 };
గణన c_వృక్షం_సంకేతం {
  C_DUMMY_వృక్షం_సంకేతం = చివరి_AND_వాడని_వృక్షం_సంకేతం,
  STMT_సమాసం,
  చివరి_C_వృక్షం_సంకేతం
};
గణన cplus_వృక్షం_సంకేతం {
  CP_DUMMY_వృక్షం_సంకేతం = చివరి_C_వృక్షం_సంకేతం,
  AMBIG_CONV,
  చివరి_CPLUS_వృక్షం_సంకేతం
};

బాహ్య పూర్ణాంకం రాయి(స్థిరరాశి అక్షరం *, ...);
పూర్ణాంకం blah(){తిరిగి 0;}

పూర్ణాంకం convert_like_real (వృక్షం_2 convs)
{
  ఎంపిక (((గణన వృక్షం_సంకేతం) (convs)->common.సంకేతం_2))
    {
    స్థితి AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      తిరిగి blah();
    అప్రమేయ:
      ఆపు;
    };
   రాయి("unsigned enum bit-fields broken\n");
   తిరిగి 0;
}

పూర్ణాంకం ప్రధాన()
{
  సంఘం వృక్ష_కణుపు convs;

  convs.common.సంకేతం_2 = AMBIG_CONV;
  convert_like_real (&convs);
  తిరిగి 0;
}
