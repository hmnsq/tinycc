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



#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <stdio.h>

#define MAX_DIGITS 32
#define NO_MAIN


/* Print the top line of the digit d into buffer. 
   Does not null terminate buffer. */

வெறுமை topline(முழு d, எழுத்து *p){

   *p++ = ' ';
   தேர்வு(d){

      /* all these have _ on top line */

      நிலை 0:
      நிலை 2:
      நிலை 3:
      நிலை 5:
      நிலை 7:
      நிலை 8:
      நிலை 9:
         *p++ = '_';
         நிறுத்து;
      இயல்பு:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

வெறுமை midline(முழு d, எழுத்து *p){

   தேர்வு(d){

      /* those that have leading | on middle line */

      நிலை 0:
      நிலை 4:
      நிலை 5:
      நிலை 6:
      நிலை 8:
      நிலை 9:
         *p++='|';
         நிறுத்து;
      இயல்பு:
         *p++=' ';	
   }
   தேர்வு(d){

      /* those that have _ on middle line */

      நிலை 2:
      நிலை 3:
      நிலை 4:
      நிலை 5:
      நிலை 6:
      நிலை 8:
      நிலை 9:
         *p++='_';
         நிறுத்து;
      இயல்பு:
         *p++=' ';

   }
   தேர்வு(d){

      /* those that have closing | on middle line */

      நிலை 0:
      நிலை 1:
      நிலை 2:
      நிலை 3:
      நிலை 4:
      நிலை 7:
      நிலை 8:
      நிலை 9:
         *p++='|';
         நிறுத்து;
      இயல்பு:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

வெறுமை botline(முழு d, எழுத்து *p){


   தேர்வு(d){

      /* those that have leading | on bottom line */

      நிலை 0:
      நிலை 2:
      நிலை 6:
      நிலை 8:
         *p++='|';
         நிறுத்து;
      இயல்பு:
         *p++=' ';	
   }
   தேர்வு(d){

      /* those that have _ on bottom line */

      நிலை 0:
      நிலை 2:
      நிலை 3:
      நிலை 5:
      நிலை 6:
      நிலை 8:
         *p++='_';
         நிறுத்து;
      இயல்பு:
         *p++=' ';

   }
   தேர்வு(d){

      /* those that have closing | on bottom line */

      நிலை 0:
      நிலை 1:
      நிலை 3:
      நிலை 4:
      நிலை 5:
      நிலை 6:
      நிலை 7:
      நிலை 8:
      நிலை 9:
         *p++='|';
         நிறுத்து;
      இயல்பு:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

வெறுமை print_led(unsigned long x, எழுத்து *buf)
{

   முழு i=0,n;
   நிலையான முழு d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   போது(x){
      d[n++] = (முழு)(x%10L);
      எனில்(n >= MAX_DIGITS)நிறுத்து;
      x = x/10L;
   }

   /* print top lines of all digits */

   க்கு(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   க்கு(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   க்கு(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

முழு முதன்மை()
{
   எழுத்து buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   printf("%s\n",buf);

   திரும்பு 0;
}

#ifndef NO_MAIN
முழு முதன்மை(முழு argc, எழுத்து **argv)
{

   முழு i=0,n;
   long x;
   நிலையான முழு d[MAX_DIGITS];
   எழுத்து buf[5*MAX_DIGITS];

   எனில்(argc != 2){
      fprintf(stderr,"led: usage: led integer\n");
      திரும்பு 1;
   }

   /* fetch argument from command line */

   x = atol(argv[1]);

   /* sanity check */

   எனில்(x<0){
      fprintf(stderr,"led: %d must be non-negative\n",x);
      திரும்பு 1;
   }

   print_led(x,buf);
   printf("%s\n",buf);

   திரும்பு 0;

}
#endif

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
