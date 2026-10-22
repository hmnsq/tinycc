/* example from http://barnyard.syr.edu/quickies/led.c */

/* led.c: print out number as if on 7 line led display. I.e., write integer
   given on command line like this:  
      _   _       _  
   |  _|  _| |_| |_  
   | |_   _|   |  _| etc.

   We assume the terminal behaves like a classical teletype. So the top
   lines of all digits have to be printed first, then the middle lines of
   all digits, etc.

   By Terry R. McConnell

compile: cc -o led led.c

If you just want to link in the subroutine print_led that does all the
work, compile with -DNO_MAIN, and declare the following in any source file
that uses the call:

extern void print_led(unsigned long x, char *buf);

Bug: you cannot call repeatedly to print more than one number to a line.
That would require curses or some other terminal API that allows moving the
cursor to a previous line.

*/



#समावेश <stdlib.h>
#समावेश <stdio.h>

#घोषणा MAX_DIGITS 32
#घोषणा NO_MAIN


/* Print the top line of the digit d into buffer. 
   Does not null terminate buffer. */

व्योम topline(पूर्णांक d, अक्षर *p){

   *p++ = ' ';
   चयन(d){

      /* all these have _ on top line */

      हाल 0:
      हाल 2:
      हाल 3:
      हाल 5:
      हाल 7:
      हाल 8:
      हाल 9:
         *p++ = '_';
         अवरोध;
      शेष:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

व्योम midline(पूर्णांक d, अक्षर *p){

   चयन(d){

      /* those that have leading | on middle line */

      हाल 0:
      हाल 4:
      हाल 5:
      हाल 6:
      हाल 8:
      हाल 9:
         *p++='|';
         अवरोध;
      शेष:
         *p++=' ';	
   }
   चयन(d){

      /* those that have _ on middle line */

      हाल 2:
      हाल 3:
      हाल 4:
      हाल 5:
      हाल 6:
      हाल 8:
      हाल 9:
         *p++='_';
         अवरोध;
      शेष:
         *p++=' ';

   }
   चयन(d){

      /* those that have closing | on middle line */

      हाल 0:
      हाल 1:
      हाल 2:
      हाल 3:
      हाल 4:
      हाल 7:
      हाल 8:
      हाल 9:
         *p++='|';
         अवरोध;
      शेष:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

व्योम botline(पूर्णांक d, अक्षर *p){


   चयन(d){

      /* those that have leading | on bottom line */

      हाल 0:
      हाल 2:
      हाल 6:
      हाल 8:
         *p++='|';
         अवरोध;
      शेष:
         *p++=' ';	
   }
   चयन(d){

      /* those that have _ on bottom line */

      हाल 0:
      हाल 2:
      हाल 3:
      हाल 5:
      हाल 6:
      हाल 8:
         *p++='_';
         अवरोध;
      शेष:
         *p++=' ';

   }
   चयन(d){

      /* those that have closing | on bottom line */

      हाल 0:
      हाल 1:
      हाल 3:
      हाल 4:
      हाल 5:
      हाल 6:
      हाल 7:
      हाल 8:
      हाल 9:
         *p++='|';
         अवरोध;
      शेष:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

व्योम print_led(अचिन्हित दीर्घ x, अक्षर *buf)
{

   पूर्णांक i=0,n;
   अटल पूर्णांक d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   जबतक(x){
      d[n++] = (पूर्णांक)(x%10L);
      अगर(n >= MAX_DIGITS)अवरोध;
      x = x/10L;
   }

   /* print top lines of all digits */

   क्रम(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   क्रम(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   क्रम(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

पूर्णांक मुख्य()
{
   अक्षर buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   म_लिखो("%s\n",buf);

   वापस 0;
}

#अगर_अघोषित NO_MAIN
पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv)
{

   पूर्णांक i=0,n;
   दीर्घ x;
   अटल पूर्णांक d[MAX_DIGITS];
   अक्षर buf[5*MAX_DIGITS];

   अगर(argc != 2){
      ख_लिखो(मानक_त्रुटि,"led: usage: led integer\n");
      वापस 1;
   }

   /* fetch argument from command line */

   x = म_से_द(argv[1]);

   /* sanity check */

   अगर(x<0){
      ख_लिखो(मानक_त्रुटि,"led: %d must be non-negative\n",x);
      वापस 1;
   }

   print_led(x,buf);
   म_लिखो("%s\n",buf);

   वापस 0;

}
#पूर्ण_अगर

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
