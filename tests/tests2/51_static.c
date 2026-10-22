#समावेश <stdio.h>

अटल पूर्णांक fred = 1234;
अटल पूर्णांक joe;

व्योम henry()
{
   अटल पूर्णांक fred = 4567;

   म_लिखो("%d\n", fred);
   fred++;
}

पूर्णांक मुख्य()
{
   म_लिखो("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   म_लिखो("%d\n", fred);
   fred = 8901;
   joe = 2345;
   म_लिखो("%d\n", fred);
   म_लिखो("%d\n", joe);

   वापस 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
