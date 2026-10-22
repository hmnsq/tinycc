#अन्तर्भाव <stdio.h>

#define $(x) x
#define $fred 10
#define joe$ 20
#define hen$y 30

#define $10(x) x*10
#define _$10(x) x/10

पूर्णांक main()
{
   म_लिखो("fred=%d\n", $fred);
   म_लिखो("joe=%d\n", joe$);
   म_लिखो("henry=%d\n", hen$y);

   म_लिखो("fred2=%d\n", $($fred));
   म_लिखो("joe2=%d\n", $(joe$));
   म_लिखो("henry2=%d\n", $(hen$y));

   म_लिखो("fred10=%d\n", $10($fred));
   म_लिखो("joe_10=%d\n", _$10(joe$));

   पूर्णांक $ = 10;
   पूर्णांक a100$ = 100;
   पूर्णांक a$$ = 1000;
   पूर्णांक a$c$b = 2121;
   पूर्णांक $100 = 10000;
   स्थिरांक अक्षर *$$$ = "money";

   म_लिखो("local=%d\n", $);
   म_लिखो("a100$=%d\n", a100$);
   म_लिखो("a$$=%d\n", a$$);
   म_लिखो("a$c$b=%d\n", a$c$b);
   म_लिखो("$100=%d\n", $100);
   म_लिखो("$$$=%s", $$$);

   परत 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
