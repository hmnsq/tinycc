/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#اگر_غیر_تعریف_شدہ INC42_پہلا
صحیح have_included_42test_h;
#تعریف_کرو INC42_پہلا
#وگرنہ_اگر !defined INC42_دوسرا
#تعریف_کرو INC42_دوسرا
صحیح have_included_42test_h_دوسرا;
#ورنہ
#تعریف_کرو INC42_تیسرا
صحیح have_included_42test_h_تیسرا;
#اگر_ختم
