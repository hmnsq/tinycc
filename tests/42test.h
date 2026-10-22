/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#جے_بنا_تعریف INC42_پہلا
صحيح have_included_42test_h;
#تعریف_کرو INC42_پہلا
#وإلاإذا !defined INC42_دوجا
#تعریف_کرو INC42_دوجا
صحيح have_included_42test_h_دوجا;
#وإلا
#تعریف_کرو INC42_تیجا
صحيح have_included_42test_h_تیجا;
#جے_انت
