/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#ifndef INC42_FIRST
ကိန်းပြည့် have_included_42test_h;
#define INC42_FIRST
#elif !defined INC42_SECOND
#define INC42_SECOND
ကိန်းပြည့် have_included_42test_h_second;
#မဟုတ်ပါက
#define INC42_THIRD
ကိန်းပြည့် have_included_42test_h_third;
#endif
