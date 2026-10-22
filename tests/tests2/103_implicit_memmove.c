/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
काष्ठा S { पूर्णांक a,b,c,d, e[1024];};
पूर्णांक foo (काष्ठा S *a, काष्ठा S *b)
{
  *a = *b;
  वापस 0;
}

व्योम *स_हटाओ(व्योम*,स्थिर व्योम*,__SIZE_TYPE__);
व्योम foo2 (काष्ठा S *a, काष्ठा S *b)
{
  स_हटाओ(a, b, माप *a);
}

पूर्णांक मुख्य()
{
  वापस 0;
}
