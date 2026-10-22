/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#اگر_تعریف_نشده INC42_اولی
صحيح have_included_42test_h;
#تعریف_کن INC42_اولی
#وإلاإذا !defined INC42_دومی
#تعریف_کن INC42_دومی
صحيح have_included_42test_h_دومی;
#وإلا
#تعریف_کن INC42_سوم
صحيح have_included_42test_h_سوم;
#پایان_اگر
