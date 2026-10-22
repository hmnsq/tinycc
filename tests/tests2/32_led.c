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



#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <stdio.h>

#define MAX_DIGITS 32
#define NO_MAIN


/* Print the top line of the digit d into buffer. 
   Does not null terminate buffer. */

শূন্য topline(পূর্ণসংখ্যা d, অক্ষর *p){

   *p++ = ' ';
   নির্বাচন(d){

      /* all these have _ on top line */

      ক্ষেত্র 0:
      ক্ষেত্র 2:
      ক্ষেত্র 3:
      ক্ষেত্র 5:
      ক্ষেত্র 7:
      ক্ষেত্র 8:
      ক্ষেত্র 9:
         *p++ = '_';
         বিরতি;
      পূর্বনির্ধারিত:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

শূন্য midline(পূর্ণসংখ্যা d, অক্ষর *p){

   নির্বাচন(d){

      /* those that have leading | on middle line */

      ক্ষেত্র 0:
      ক্ষেত্র 4:
      ক্ষেত্র 5:
      ক্ষেত্র 6:
      ক্ষেত্র 8:
      ক্ষেত্র 9:
         *p++='|';
         বিরতি;
      পূর্বনির্ধারিত:
         *p++=' ';	
   }
   নির্বাচন(d){

      /* those that have _ on middle line */

      ক্ষেত্র 2:
      ক্ষেত্র 3:
      ক্ষেত্র 4:
      ক্ষেত্র 5:
      ক্ষেত্র 6:
      ক্ষেত্র 8:
      ক্ষেত্র 9:
         *p++='_';
         বিরতি;
      পূর্বনির্ধারিত:
         *p++=' ';

   }
   নির্বাচন(d){

      /* those that have closing | on middle line */

      ক্ষেত্র 0:
      ক্ষেত্র 1:
      ক্ষেত্র 2:
      ক্ষেত্র 3:
      ক্ষেত্র 4:
      ক্ষেত্র 7:
      ক্ষেত্র 8:
      ক্ষেত্র 9:
         *p++='|';
         বিরতি;
      পূর্বনির্ধারিত:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

শূন্য botline(পূর্ণসংখ্যা d, অক্ষর *p){


   নির্বাচন(d){

      /* those that have leading | on bottom line */

      ক্ষেত্র 0:
      ক্ষেত্র 2:
      ক্ষেত্র 6:
      ক্ষেত্র 8:
         *p++='|';
         বিরতি;
      পূর্বনির্ধারিত:
         *p++=' ';	
   }
   নির্বাচন(d){

      /* those that have _ on bottom line */

      ক্ষেত্র 0:
      ক্ষেত্র 2:
      ক্ষেত্র 3:
      ক্ষেত্র 5:
      ক্ষেত্র 6:
      ক্ষেত্র 8:
         *p++='_';
         বিরতি;
      পূর্বনির্ধারিত:
         *p++=' ';

   }
   নির্বাচন(d){

      /* those that have closing | on bottom line */

      ক্ষেত্র 0:
      ক্ষেত্র 1:
      ক্ষেত্র 3:
      ক্ষেত্র 4:
      ক্ষেত্র 5:
      ক্ষেত্র 6:
      ক্ষেত্র 7:
      ক্ষেত্র 8:
      ক্ষেত্র 9:
         *p++='|';
         বিরতি;
      পূর্বনির্ধারিত:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

শূন্য print_led(unsigned long x, অক্ষর *buf)
{

   পূর্ণসংখ্যা i=0,n;
   স্থির পূর্ণসংখ্যা d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   যখন(x){
      d[n++] = (পূর্ণসংখ্যা)(x%10L);
      যদি(n >= MAX_DIGITS)বিরতি;
      x = x/10L;
   }

   /* print top lines of all digits */

   জন্য(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   জন্য(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   জন্য(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

পূর্ণসংখ্যা প্রধান()
{
   অক্ষর buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   printf("%s\n",buf);

   ফেরত 0;
}

#ifndef NO_MAIN
পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv)
{

   পূর্ণসংখ্যা i=0,n;
   long x;
   স্থির পূর্ণসংখ্যা d[MAX_DIGITS];
   অক্ষর buf[5*MAX_DIGITS];

   যদি(argc != 2){
      fprintf(stderr,"led: usage: led integer\n");
      ফেরত 1;
   }

   /* fetch argument from command line */

   x = atol(argv[1]);

   /* sanity check */

   যদি(x<0){
      fprintf(stderr,"led: %d must be non-negative\n",x);
      ফেরত 1;
   }

   print_led(x,buf);
   printf("%s\n",buf);

   ফেরত 0;

}
#endif

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
