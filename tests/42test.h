/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#यदि_अपरिभाषितम् INC42_FIRST
पूर्णाङ्क have_included_42test_h;
#परिभाषय INC42_FIRST
#नोचेद्यदि !defined INC42_SECOND
#परिभाषय INC42_SECOND
पूर्णाङ्क have_included_42test_h_second;
#अन्यथा
#परिभाषय INC42_THIRD
पूर्णाङ्क have_included_42test_h_third;
#यदि_अन्तः
