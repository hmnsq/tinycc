#अन्तर्भाव <stdio.h>	// printf()

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define AB(x) CAT(x,y)

पूर्णाङ्क main(शून्य)
{
  पूर्णाङ्क xy = 42;
  म_लिखो("%d\n", CAT(A,B)(x));
  प्रत्यागम 0;
}
