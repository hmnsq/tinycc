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

शून्य topline(पूर्णाङ्क d, वर्ण *p){

   *p++ = ' ';
   विकल्प(d){

      /* all these have _ on top line */

      पक्ष 0:
      पक्ष 2:
      पक्ष 3:
      पक्ष 5:
      पक्ष 7:
      पक्ष 8:
      पक्ष 9:
         *p++ = '_';
         भङ्ग;
      स्वभाव:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

शून्य midline(पूर्णाङ्क d, वर्ण *p){

   विकल्प(d){

      /* those that have leading | on middle line */

      पक्ष 0:
      पक्ष 4:
      पक्ष 5:
      पक्ष 6:
      पक्ष 8:
      पक्ष 9:
         *p++='|';
         भङ्ग;
      स्वभाव:
         *p++=' ';	
   }
   विकल्प(d){

      /* those that have _ on middle line */

      पक्ष 2:
      पक्ष 3:
      पक्ष 4:
      पक्ष 5:
      पक्ष 6:
      पक्ष 8:
      पक्ष 9:
         *p++='_';
         भङ्ग;
      स्वभाव:
         *p++=' ';

   }
   विकल्प(d){

      /* those that have closing | on middle line */

      पक्ष 0:
      पक्ष 1:
      पक्ष 2:
      पक्ष 3:
      पक्ष 4:
      पक्ष 7:
      पक्ष 8:
      पक्ष 9:
         *p++='|';
         भङ्ग;
      स्वभाव:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

शून्य botline(पूर्णाङ्क d, वर्ण *p){


   विकल्प(d){

      /* those that have leading | on bottom line */

      पक्ष 0:
      पक्ष 2:
      पक्ष 6:
      पक्ष 8:
         *p++='|';
         भङ्ग;
      स्वभाव:
         *p++=' ';	
   }
   विकल्प(d){

      /* those that have _ on bottom line */

      पक्ष 0:
      पक्ष 2:
      पक्ष 3:
      पक्ष 5:
      पक्ष 6:
      पक्ष 8:
         *p++='_';
         भङ्ग;
      स्वभाव:
         *p++=' ';

   }
   विकल्प(d){

      /* those that have closing | on bottom line */

      पक्ष 0:
      पक्ष 1:
      पक्ष 3:
      पक्ष 4:
      पक्ष 5:
      पक्ष 6:
      पक्ष 7:
      पक्ष 8:
      पक्ष 9:
         *p++='|';
         भङ्ग;
      स्वभाव:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

शून्य print_led(unsigned long x, वर्ण *buf)
{

   पूर्णाङ्क i=0,n;
   स्थिर पूर्णाङ्क d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   यावत्(x){
      d[n++] = (पूर्णाङ्क)(x%10L);
      यदि(n >= MAX_DIGITS)भङ्ग;
      x = x/10L;
   }

   /* print top lines of all digits */

   प्रति(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   प्रति(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   प्रति(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

पूर्णाङ्क main()
{
   वर्ण buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   printf("%s\n",buf);

   प्रत्यागम 0;
}

#ifndef NO_MAIN
पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{

   पूर्णाङ्क i=0,n;
   long x;
   स्थिर पूर्णाङ्क d[MAX_DIGITS];
   वर्ण buf[5*MAX_DIGITS];

   यदि(argc != 2){
      fprintf(stderr,"led: usage: led integer\n");
      प्रत्यागम 1;
   }

   /* fetch argument from command line */

   x = atol(argv[1]);

   /* sanity check */

   यदि(x<0){
      fprintf(stderr,"led: %d must be non-negative\n",x);
      प्रत्यागम 1;
   }

   print_led(x,buf);
   printf("%s\n",buf);

   प्रत्यागम 0;

}
#endif

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
