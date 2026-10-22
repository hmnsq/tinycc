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



#ضمن <stdlib.h>
#ضمن <stdio.h>

#تعریف_کړه MAX_DIGITS 32
#تعریف_کړه NO_MAIN


/* Print the top line of the digit d into buffer. 
   Does not null terminate buffer. */

فراغ topline(صحيح d, حرف *p){

   *p++ = ' ';
   بدل(d){

      /* all these have _ on top line */

      حالة 0:
      حالة 2:
      حالة 3:
      حالة 5:
      حالة 7:
      حالة 8:
      حالة 9:
         *p++ = '_';
         اكسر;
      افتراضي:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

فراغ midline(صحيح d, حرف *p){

   بدل(d){

      /* those that have leading | on middle line */

      حالة 0:
      حالة 4:
      حالة 5:
      حالة 6:
      حالة 8:
      حالة 9:
         *p++='|';
         اكسر;
      افتراضي:
         *p++=' ';	
   }
   بدل(d){

      /* those that have _ on middle line */

      حالة 2:
      حالة 3:
      حالة 4:
      حالة 5:
      حالة 6:
      حالة 8:
      حالة 9:
         *p++='_';
         اكسر;
      افتراضي:
         *p++=' ';

   }
   بدل(d){

      /* those that have closing | on middle line */

      حالة 0:
      حالة 1:
      حالة 2:
      حالة 3:
      حالة 4:
      حالة 7:
      حالة 8:
      حالة 9:
         *p++='|';
         اكسر;
      افتراضي:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

فراغ botline(صحيح d, حرف *p){


   بدل(d){

      /* those that have leading | on bottom line */

      حالة 0:
      حالة 2:
      حالة 6:
      حالة 8:
         *p++='|';
         اكسر;
      افتراضي:
         *p++=' ';	
   }
   بدل(d){

      /* those that have _ on bottom line */

      حالة 0:
      حالة 2:
      حالة 3:
      حالة 5:
      حالة 6:
      حالة 8:
         *p++='_';
         اكسر;
      افتراضي:
         *p++=' ';

   }
   بدل(d){

      /* those that have closing | on bottom line */

      حالة 0:
      حالة 1:
      حالة 3:
      حالة 4:
      حالة 5:
      حالة 6:
      حالة 7:
      حالة 8:
      حالة 9:
         *p++='|';
         اكسر;
      افتراضي:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

فراغ print_led(بینښه اوږد x, حرف *buf)
{

   صحيح i=0,n;
   ساكن صحيح d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   طالما(x){
      d[n++] = (صحيح)(x%10L);
      إذا(n >= MAX_DIGITS)اكسر;
      x = x/10L;
   }

   /* print top lines of all digits */

   لكل(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   لكل(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   لكل(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

صحيح اصلي()
{
   حرف buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   چاپ_کړه("%s\n",buf);

   أرجع 0;
}

#که_نه_تعریف_شوی NO_MAIN
صحيح اصلي(صحيح argc, حرف **argv)
{

   صحيح i=0,n;
   اوږد x;
   ساكن صحيح d[MAX_DIGITS];
   حرف buf[5*MAX_DIGITS];

   إذا(argc != 2){
      fprintf(stderr,"led: usage: led integer\n");
      أرجع 1;
   }

   /* fetch argument from command line */

   x = atol(argv[1]);

   /* sanity check */

   إذا(x<0){
      fprintf(stderr,"led: %d must be non-negative\n",x);
      أرجع 1;
   }

   print_led(x,buf);
   چاپ_کړه("%s\n",buf);

   أرجع 0;

}
#د_که_پای

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
