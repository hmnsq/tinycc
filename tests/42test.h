/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#ifndef INC42_FIRST
പൂർണ്ണസംഖ്യ have_included_42test_h;
#define INC42_FIRST
#അല്ലെങ്കിലെങ്കിൽ !defined INC42_SECOND
#define INC42_SECOND
പൂർണ്ണസംഖ്യ have_included_42test_h_second;
#അല്ലെങ്കിൽ
#define INC42_THIRD
പൂർണ്ണസംഖ്യ have_included_42test_h_third;
#endif
