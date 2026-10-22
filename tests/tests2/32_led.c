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



#include <stdlib.h>
#include <stdio.h>

#define MAX_DIGITS 32
#define NO_MAIN


/* Print the top line of the digit d into buffer. 
   Does not null terminate buffer. */

void topline(puur_naa_nka d, var_na *p){

   *p++ = ' ';
   switch(d){

      /* all these have _ on top line */

      pak_sa 0:
      pak_sa 2:
      pak_sa 3:
      pak_sa 5:
      pak_sa 7:
      pak_sa 8:
      pak_sa 9:
         *p++ = '_';
         bha_nga;
      default:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

void midline(puur_naa_nka d, var_na *p){

   switch(d){

      /* those that have leading | on middle line */

      pak_sa 0:
      pak_sa 4:
      pak_sa 5:
      pak_sa 6:
      pak_sa 8:
      pak_sa 9:
         *p++='|';
         bha_nga;
      default:
         *p++=' ';	
   }
   switch(d){

      /* those that have _ on middle line */

      pak_sa 2:
      pak_sa 3:
      pak_sa 4:
      pak_sa 5:
      pak_sa 6:
      pak_sa 8:
      pak_sa 9:
         *p++='_';
         bha_nga;
      default:
         *p++=' ';

   }
   switch(d){

      /* those that have closing | on middle line */

      pak_sa 0:
      pak_sa 1:
      pak_sa 2:
      pak_sa 3:
      pak_sa 4:
      pak_sa 7:
      pak_sa 8:
      pak_sa 9:
         *p++='|';
         bha_nga;
      default:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

void botline(puur_naa_nka d, var_na *p){


   switch(d){

      /* those that have leading | on bottom line */

      pak_sa 0:
      pak_sa 2:
      pak_sa 6:
      pak_sa 8:
         *p++='|';
         bha_nga;
      default:
         *p++=' ';	
   }
   switch(d){

      /* those that have _ on bottom line */

      pak_sa 0:
      pak_sa 2:
      pak_sa 3:
      pak_sa 5:
      pak_sa 6:
      pak_sa 8:
         *p++='_';
         bha_nga;
      default:
         *p++=' ';

   }
   switch(d){

      /* those that have closing | on bottom line */

      pak_sa 0:
      pak_sa 1:
      pak_sa 3:
      pak_sa 4:
      pak_sa 5:
      pak_sa 6:
      pak_sa 7:
      pak_sa 8:
      pak_sa 9:
         *p++='|';
         bha_nga;
      default:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

void print_led(unsigned long x, var_na *buf)
{

   puur_naa_nka i=0,n;
   static puur_naa_nka d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   ᱡᱚᱠᱷᱚᱱ(x){
      d[n++] = (puur_naa_nka)(x%10L);
      ᱡᱩᱫᱤ(n >= MAX_DIGITS)bha_nga;
      x = x/10L;
   }

   /* print top lines of all digits */

   for(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   for(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   for(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

puur_naa_nka main()
{
   var_na buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   printf("%s\n",buf);

   ᱨᱩᱣᱟᱹᱲ 0;
}

#ifndef NO_MAIN
puur_naa_nka main(puur_naa_nka argc, var_na **argv)
{

   puur_naa_nka i=0,n;
   long x;
   static puur_naa_nka d[MAX_DIGITS];
   var_na buf[5*MAX_DIGITS];

   ᱡᱩᱫᱤ(argc != 2){
      fprintf(stderr,"led: usage: led integer\n");
      ᱨᱩᱣᱟᱹᱲ 1;
   }

   /* fetch argument from command line */

   x = atol(argv[1]);

   /* sanity check */

   ᱡᱩᱫᱤ(x<0){
      fprintf(stderr,"led: %d must be non-negative\n",x);
      ᱨᱩᱣᱟᱹᱲ 1;
   }

   print_led(x,buf);
   printf("%s\n",buf);

   ᱨᱩᱣᱟᱹᱲ 0;

}
#endif

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
