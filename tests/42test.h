/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#ifndef INC42_FIRST
पूर्णाङ्क have_included_42test_h;
#define INC42_FIRST
#नोचेद्यदि !defined INC42_SECOND
#define INC42_SECOND
पूर्णाङ्क have_included_42test_h_second;
#अन्यथा
#define INC42_THIRD
पूर्णाङ्क have_included_42test_h_third;
#endif
