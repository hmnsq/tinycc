/* This checks if enums needing 8 bit but only having positive
   values are correctly zero extended (instead of sign extended)
   when stored into/loaded from a 8 bit bit-field of enum type (which
   itself is implementation defined, so isn't necessarily supported by all
   other compilers).  */
enum पुनो_code {
  SOME_CODE = 148, /* has bit 7 set, and hence all further enum values as well */
  LAST_AND_UNUSED_पुनो_CODE
};
typedef union पुनो_बुहोल *पुनो_2;
struct पुनो_common
{
  union पुनो_बुहोल *chain;
  union पुनो_बुहोल *type;
  enum पुनो_code code : 8;
  unsigned side_effects_flag : 1;
};
union पुनो_बुहोल
{
  struct पुनो_common common;
 };
enum c_पुनो_code {
  C_DUMMY_पुनो_CODE = LAST_AND_UNUSED_पुनो_CODE,
  STMT_पाहायाग,
  LAST_C_पुनो_CODE
};
enum cplus_पुनो_code {
  CP_DUMMY_पुनो_CODE = LAST_C_पुनो_CODE,
  AMBIG_CONV,
  LAST_CPLUS_पुनो_CODE
};

extern int printf(const char *, ...);
int blah(){return 0;}

int convert_like_real (पुनो_2 convs)
{
  switch (((enum पुनो_code) (convs)->common.code))
    {
    case AMBIG_CONV: /* This has bit 7 set, which must not be the sign
			bit in tree_common.code, i.e. the bitfield must
			be somehow marked unsigned.  */
      return blah();
    default:
      break;
    };
   printf("unsigned enum bit-fields broken\n");
   return 0;
}

int main()
{
  union पुनो_बुहोल convs;

  convs.common.code = AMBIG_CONV;
  convert_like_real (&convs);
  return 0;
}
