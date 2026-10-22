/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ INC42_ಮೊದಲ
ಪೂರ್ಣಾಂಕ have_included_42test_h;
#ವ್ಯಾಖ್ಯಾನಿಸು INC42_ಮೊದಲ
#ಅಥವಾಆದರೆ !defined INC42_ಎರಡನೇ
#ವ್ಯಾಖ್ಯಾನಿಸು INC42_ಎರಡನೇ
ಪೂರ್ಣಾಂಕ have_included_42test_h_ಎರಡನೇ;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು INC42_ಮೂರನೇ
ಪೂರ್ಣಾಂಕ have_included_42test_h_ಮೂರನೇ;
#ಆದರೆ_ಅಂತ್ಯ
