/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#अगर_अघोषित INC42_FIRST
पूर्णांक have_included_42test_h;
#घोषणा INC42_FIRST
#या_अगर !defined INC42_SECOND
#घोषणा INC42_SECOND
पूर्णांक have_included_42test_h_second;
#अन्यथा
#घोषणा INC42_THIRD
पूर्णांक have_included_42test_h_third;
#पूर्ण_अगर
