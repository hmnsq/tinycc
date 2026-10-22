/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#నిర్వచితం_కాకపోతే INC42_మొదటి
పూర్ణాంకం have_included_42test_h;
#నిర్వచించు INC42_మొదటి
#లేదావేళ !defined INC42_రెండవ
#నిర్వచించు INC42_రెండవ
పూర్ణాంకం have_included_42test_h_రెండవ;
#లేకపోతే
#నిర్వచించు INC42_మూడవ
పూర్ణాంకం have_included_42test_h_మూడవ;
#అయితే_ముగింపు
