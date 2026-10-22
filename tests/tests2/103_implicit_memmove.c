/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
संरचना S { पूर्णाङ्क a,b,c,d, e[1024];};
पूर्णाङ्क foo (संरचना S *a, संरचना S *b)
{
  *a = *b;
  प्रत्यागम 0;
}

शून्य *memmove(शून्य*,ध्रुव शून्य*,__SIZE_TYPE__);
शून्य foo2 (संरचना S *a, संरचना S *b)
{
  memmove(a, b, परिमाण *a);
}

पूर्णाङ्क मुख्यम्()
{
  प्रत्यागम 0;
}
