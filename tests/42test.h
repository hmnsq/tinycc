/* This file is to test compute #include directives.  It's named so
   that it starts with a pre-processing number which isn't a valid
   number (42test.h).  Including this must work.  */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ INC42_ਪਹਿਲਾ
ਪੂਰਨ have_included_42test_h;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INC42_ਪਹਿਲਾ
#ਜਾਂਜੇ !defined INC42_ਦੂਜਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INC42_ਦੂਜਾ
ਪੂਰਨ have_included_42test_h_ਦੂਜਾ;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INC42_ਤੀਜਾ
ਪੂਰਨ have_included_42test_h_ਤੀਜਾ;
#ਜੇ_ਅੰਤ
