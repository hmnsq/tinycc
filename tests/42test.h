/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#ifndef INC42_FIRST
পূর্ণাঙ্ক have_included_42test_h;
#define INC42_FIRST
#নোচেদ্যদি !defined INC42_SECOND
#define INC42_SECOND
পূর্ণাঙ্ক have_included_42test_h_second;
#অন্যথা
#define INC42_THIRD
পূর্ণাঙ্ক have_included_42test_h_third;
#endif
