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

শূন্য topline(পূর্ণাঙ্ক d, বর্ণ *p){

   *p++ = ' ';
   বিকল্প(d){

      /* all these have _ on top line */

      পক্ষ 0:
      পক্ষ 2:
      পক্ষ 3:
      পক্ষ 5:
      পক্ষ 7:
      পক্ষ 8:
      পক্ষ 9:
         *p++ = '_';
         ভঙ্গ;
      স্বভাব:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

শূন্য midline(পূর্ণাঙ্ক d, বর্ণ *p){

   বিকল্প(d){

      /* those that have leading | on middle line */

      পক্ষ 0:
      পক্ষ 4:
      পক্ষ 5:
      পক্ষ 6:
      পক্ষ 8:
      পক্ষ 9:
         *p++='|';
         ভঙ্গ;
      স্বভাব:
         *p++=' ';	
   }
   বিকল্প(d){

      /* those that have _ on middle line */

      পক্ষ 2:
      পক্ষ 3:
      পক্ষ 4:
      পক্ষ 5:
      পক্ষ 6:
      পক্ষ 8:
      পক্ষ 9:
         *p++='_';
         ভঙ্গ;
      স্বভাব:
         *p++=' ';

   }
   বিকল্প(d){

      /* those that have closing | on middle line */

      পক্ষ 0:
      পক্ষ 1:
      পক্ষ 2:
      পক্ষ 3:
      পক্ষ 4:
      পক্ষ 7:
      পক্ষ 8:
      পক্ষ 9:
         *p++='|';
         ভঙ্গ;
      স্বভাব:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

শূন্য botline(পূর্ণাঙ্ক d, বর্ণ *p){


   বিকল্প(d){

      /* those that have leading | on bottom line */

      পক্ষ 0:
      পক্ষ 2:
      পক্ষ 6:
      পক্ষ 8:
         *p++='|';
         ভঙ্গ;
      স্বভাব:
         *p++=' ';	
   }
   বিকল্প(d){

      /* those that have _ on bottom line */

      পক্ষ 0:
      পক্ষ 2:
      পক্ষ 3:
      পক্ষ 5:
      পক্ষ 6:
      পক্ষ 8:
         *p++='_';
         ভঙ্গ;
      স্বভাব:
         *p++=' ';

   }
   বিকল্প(d){

      /* those that have closing | on bottom line */

      পক্ষ 0:
      পক্ষ 1:
      পক্ষ 3:
      পক্ষ 4:
      পক্ষ 5:
      পক্ষ 6:
      পক্ষ 7:
      পক্ষ 8:
      পক্ষ 9:
         *p++='|';
         ভঙ্গ;
      স্বভাব:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

শূন্য print_led(unsigned long x, বর্ণ *buf)
{

   পূর্ণাঙ্ক i=0,n;
   স্থির পূর্ণাঙ্ক d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   যাবত্(x){
      d[n++] = (পূর্ণাঙ্ক)(x%10L);
      যদি(n >= MAX_DIGITS)ভঙ্গ;
      x = x/10L;
   }

   /* print top lines of all digits */

   প্রতি(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   প্রতি(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   প্রতি(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

পূর্ণাঙ্ক main()
{
   বর্ণ buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   printf("%s\n",buf);

   প্রত্যাগম 0;
}

#ifndef NO_MAIN
পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, বর্ণ **argv)
{

   পূর্ণাঙ্ক i=0,n;
   long x;
   স্থির পূর্ণাঙ্ক d[MAX_DIGITS];
   বর্ণ buf[5*MAX_DIGITS];

   যদি(argc != 2){
      fprintf(stderr,"led: usage: led integer\n");
      প্রত্যাগম 1;
   }

   /* fetch argument from command line */

   x = atol(argv[1]);

   /* sanity check */

   যদি(x<0){
      fprintf(stderr,"led: %d must be non-negative\n",x);
      প্রত্যাগম 1;
   }

   print_led(x,buf);
   printf("%s\n",buf);

   প্রত্যাগম 0;

}
#endif

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
