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



#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_DIGITS 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_MAIN


/* Print the top line of the digit d into buffer. 
   Does not null terminate buffer. */

ਖਾਲੀ topline(ਪੂਰਨ d, ਅੱਖਰ *p){

   *p++ = ' ';
   ਚੋਣ(d){

      /* all these have _ on top line */

      ਹਾਲਤ 0:
      ਹਾਲਤ 2:
      ਹਾਲਤ 3:
      ਹਾਲਤ 5:
      ਹਾਲਤ 7:
      ਹਾਲਤ 8:
      ਹਾਲਤ 9:
         *p++ = '_';
         ਰੋਕੋ;
      ਮੂਲ:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

ਖਾਲੀ midline(ਪੂਰਨ d, ਅੱਖਰ *p){

   ਚੋਣ(d){

      /* those that have leading | on middle line */

      ਹਾਲਤ 0:
      ਹਾਲਤ 4:
      ਹਾਲਤ 5:
      ਹਾਲਤ 6:
      ਹਾਲਤ 8:
      ਹਾਲਤ 9:
         *p++='|';
         ਰੋਕੋ;
      ਮੂਲ:
         *p++=' ';	
   }
   ਚੋਣ(d){

      /* those that have _ on middle line */

      ਹਾਲਤ 2:
      ਹਾਲਤ 3:
      ਹਾਲਤ 4:
      ਹਾਲਤ 5:
      ਹਾਲਤ 6:
      ਹਾਲਤ 8:
      ਹਾਲਤ 9:
         *p++='_';
         ਰੋਕੋ;
      ਮੂਲ:
         *p++=' ';

   }
   ਚੋਣ(d){

      /* those that have closing | on middle line */

      ਹਾਲਤ 0:
      ਹਾਲਤ 1:
      ਹਾਲਤ 2:
      ਹਾਲਤ 3:
      ਹਾਲਤ 4:
      ਹਾਲਤ 7:
      ਹਾਲਤ 8:
      ਹਾਲਤ 9:
         *p++='|';
         ਰੋਕੋ;
      ਮੂਲ:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

ਖਾਲੀ botline(ਪੂਰਨ d, ਅੱਖਰ *p){


   ਚੋਣ(d){

      /* those that have leading | on bottom line */

      ਹਾਲਤ 0:
      ਹਾਲਤ 2:
      ਹਾਲਤ 6:
      ਹਾਲਤ 8:
         *p++='|';
         ਰੋਕੋ;
      ਮੂਲ:
         *p++=' ';	
   }
   ਚੋਣ(d){

      /* those that have _ on bottom line */

      ਹਾਲਤ 0:
      ਹਾਲਤ 2:
      ਹਾਲਤ 3:
      ਹਾਲਤ 5:
      ਹਾਲਤ 6:
      ਹਾਲਤ 8:
         *p++='_';
         ਰੋਕੋ;
      ਮੂਲ:
         *p++=' ';

   }
   ਚੋਣ(d){

      /* those that have closing | on bottom line */

      ਹਾਲਤ 0:
      ਹਾਲਤ 1:
      ਹਾਲਤ 3:
      ਹਾਲਤ 4:
      ਹਾਲਤ 5:
      ਹਾਲਤ 6:
      ਹਾਲਤ 7:
      ਹਾਲਤ 8:
      ਹਾਲਤ 9:
         *p++='|';
         ਰੋਕੋ;
      ਮੂਲ:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

ਖਾਲੀ print_led(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ x, ਅੱਖਰ *buf)
{

   ਪੂਰਨ i=0,n;
   ਸਥਿਰ ਪੂਰਨ d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   ਜਦੋਂ(x){
      d[n++] = (ਪੂਰਨ)(x%10L);
      ਜੇ(n >= MAX_DIGITS)ਰੋਕੋ;
      x = x/10L;
   }

   /* print top lines of all digits */

   ਲਈ(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   ਲਈ(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   ਲਈ(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

ਪੂਰਨ ਮੁੱਖ()
{
   ਅੱਖਰ buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   ਲਿਖੋ("%s\n",buf);

   ਵਾਪਸ 0;
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NO_MAIN
ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{

   ਪੂਰਨ i=0,n;
   ਲੰਮਾ x;
   ਸਥਿਰ ਪੂਰਨ d[MAX_DIGITS];
   ਅੱਖਰ buf[5*MAX_DIGITS];

   ਜੇ(argc != 2){
      fprintf(stderr,"led: usage: led integer\n");
      ਵਾਪਸ 1;
   }

   /* fetch argument from command line */

   x = atol(argv[1]);

   /* sanity check */

   ਜੇ(x<0){
      fprintf(stderr,"led: %d must be non-negative\n",x);
      ਵਾਪਸ 1;
   }

   print_led(x,buf);
   ਲਿਖੋ("%s\n",buf);

   ਵਾਪਸ 0;

}
#ਜੇ_ਅੰਤ

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
