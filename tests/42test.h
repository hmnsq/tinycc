/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#ifndef INC42_FIRST
ಪೂರ್ಣಾಙ್ಕ have_included_42test_h;
#define INC42_FIRST
#ನೋಚೇದ್ಯದಿ !defined INC42_SECOND
#define INC42_SECOND
ಪೂರ್ಣಾಙ್ಕ have_included_42test_h_second;
#ಅನ್ಯಥಾ
#define INC42_THIRD
ಪೂರ್ಣಾಙ್ಕ have_included_42test_h_third;
#endif
