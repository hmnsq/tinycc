/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#جيڪڏهن_وصف_نه_ٿيل INC42_پهريون
صحيح have_included_42test_h;
#وصف_ڪريو INC42_پهريون
#وإلاإذا !defined INC42_ٻيو
#وصف_ڪريو INC42_ٻيو
صحيح have_included_42test_h_ٻيو;
#وإلا
#وصف_ڪريو INC42_ٽيون
صحيح have_included_42test_h_ٽيون;
#جيڪڏهن_پورو
