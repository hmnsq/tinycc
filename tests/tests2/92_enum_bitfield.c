/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
ga_nanaa tree_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_TREE_CODE
};
typedef sa_ngha tree_node *tree;
sa_nracanaa tree_common
{
  sa_ngha tree_node *chain;
  sa_ngha tree_node *type;
  ga_nanaa tree_code code : 8;
  unsigned side_effects_flag : 1;
};
sa_ngha tree_node
{
  sa_nracanaa tree_common common;
 };
ga_nanaa c_tree_code {
  C_DUMMY_TREE_CODE = LAST_AND_UNUSED_TREE_CODE,
  STMT_EXPR,
  LAST_C_TREE_CODE
};
ga_nanaa cplus_tree_code {
  CP_DUMMY_TREE_CODE = LAST_C_TREE_CODE,
  AMBIG_CONV,
  LAST_CPLUS_TREE_CODE
};

extern puur_naa_nka printf(const var_na *, ...);
puur_naa_nka blah(){ပွၵ်ႈ 0;}

puur_naa_nka convert_like_real (tree convs)
{
  switch (((ga_nanaa tree_code) (convs)->common.code))
    {
    pak_sa AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      ပွၵ်ႈ blah();
    default:
      bha_nga;
    };
   printf("unsigned enum bit-fields broken\n");
   ပွၵ်ႈ 0;
}

puur_naa_nka main()
{
  sa_ngha tree_node convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  ပွၵ်ႈ 0;
}
