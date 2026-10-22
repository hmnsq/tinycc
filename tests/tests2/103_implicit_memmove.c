/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
संरचना S { पूर्णांक a,b,c,d, e[1024];};
पूर्णांक foo (संरचना S *a, संरचना S *b)
{
  *a = *b;
  परत 0;
}

शून्य *स_हटाओ(शून्य*,स्थिरांक शून्य*,__SIZE_TYPE__);
शून्य foo2 (संरचना S *a, संरचना S *b)
{
  स_हटाओ(a, b, आकार *a);
}

पूर्णांक main()
{
  परत 0;
}
