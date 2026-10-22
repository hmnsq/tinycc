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



#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>

#define MAX_DIGITS 32
#define NO_MAIN


/* Print the top line of the digit d into buffer. 
   Does not null terminate buffer. */

शून्य topline(पूर्णांक d, अक्षर *p){

   *p++ = ' ';
   निवड(d){

      /* all these have _ on top line */

      स्थिती 0:
      स्थिती 2:
      स्थिती 3:
      स्थिती 5:
      स्थिती 7:
      स्थिती 8:
      स्थिती 9:
         *p++ = '_';
         थांबा;
      पूर्वनिर्धारित:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

शून्य midline(पूर्णांक d, अक्षर *p){

   निवड(d){

      /* those that have leading | on middle line */

      स्थिती 0:
      स्थिती 4:
      स्थिती 5:
      स्थिती 6:
      स्थिती 8:
      स्थिती 9:
         *p++='|';
         थांबा;
      पूर्वनिर्धारित:
         *p++=' ';	
   }
   निवड(d){

      /* those that have _ on middle line */

      स्थिती 2:
      स्थिती 3:
      स्थिती 4:
      स्थिती 5:
      स्थिती 6:
      स्थिती 8:
      स्थिती 9:
         *p++='_';
         थांबा;
      पूर्वनिर्धारित:
         *p++=' ';

   }
   निवड(d){

      /* those that have closing | on middle line */

      स्थिती 0:
      स्थिती 1:
      स्थिती 2:
      स्थिती 3:
      स्थिती 4:
      स्थिती 7:
      स्थिती 8:
      स्थिती 9:
         *p++='|';
         थांबा;
      पूर्वनिर्धारित:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

शून्य botline(पूर्णांक d, अक्षर *p){


   निवड(d){

      /* those that have leading | on bottom line */

      स्थिती 0:
      स्थिती 2:
      स्थिती 6:
      स्थिती 8:
         *p++='|';
         थांबा;
      पूर्वनिर्धारित:
         *p++=' ';	
   }
   निवड(d){

      /* those that have _ on bottom line */

      स्थिती 0:
      स्थिती 2:
      स्थिती 3:
      स्थिती 5:
      स्थिती 6:
      स्थिती 8:
         *p++='_';
         थांबा;
      पूर्वनिर्धारित:
         *p++=' ';

   }
   निवड(d){

      /* those that have closing | on bottom line */

      स्थिती 0:
      स्थिती 1:
      स्थिती 3:
      स्थिती 4:
      स्थिती 5:
      स्थिती 6:
      स्थिती 7:
      स्थिती 8:
      स्थिती 9:
         *p++='|';
         थांबा;
      पूर्वनिर्धारित:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

शून्य print_led(अचिन्हित दीर्घ x, अक्षर *buf)
{

   पूर्णांक i=0,n;
   स्थिर पूर्णांक d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   पर्यंत(x){
      d[n++] = (पूर्णांक)(x%10L);
      जर(n >= MAX_DIGITS)थांबा;
      x = x/10L;
   }

   /* print top lines of all digits */

   साठी(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   साठी(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   साठी(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

पूर्णांक main()
{
   अक्षर buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   म_लिखो("%s\n",buf);

   परत 0;
}

#ifndef NO_MAIN
पूर्णांक main(पूर्णांक argc, अक्षर **argv)
{

   पूर्णांक i=0,n;
   दीर्घ x;
   स्थिर पूर्णांक d[MAX_DIGITS];
   अक्षर buf[5*MAX_DIGITS];

   जर(argc != 2){
      ख_लिखो(मानक_त्रुटि,"led: usage: led integer\n");
      परत 1;
   }

   /* fetch argument from command line */

   x = म_से_द(argv[1]);

   /* sanity check */

   जर(x<0){
      ख_लिखो(मानक_त्रुटि,"led: %d must be non-negative\n",x);
      परत 1;
   }

   print_led(x,buf);
   म_लिखो("%s\n",buf);

   परत 0;

}
#endif

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
