/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#که_نه_تعریف_شوی INC42_لومړی
صحيح have_included_42test_h;
#تعریف_کړه INC42_لومړی
#وإلاإذا !defined INC42_دوهم
#تعریف_کړه INC42_دوهم
صحيح have_included_42test_h_دوهم;
#وإلا
#تعریف_کړه INC42_دریم
صحيح have_included_42test_h_دریم;
#د_که_پای
