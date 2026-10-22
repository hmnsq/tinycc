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



#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <stdio.h>

#define MAX_DIGITS 32
#define NO_MAIN


/* Print the top line of the digit d into buffer. 
   Does not null terminate buffer. */

ശൂന്യം topline(പൂർണ്ണസംഖ്യ d, അക്ഷരം *p){

   *p++ = ' ';
   തിരഞ്ഞെടുപ്പ്(d){

      /* all these have _ on top line */

      അവസ്ഥ 0:
      അവസ്ഥ 2:
      അവസ്ഥ 3:
      അവസ്ഥ 5:
      അവസ്ഥ 7:
      അവസ്ഥ 8:
      അവസ്ഥ 9:
         *p++ = '_';
         നിർത്തുക;
      സ്ഥിരസ്ഥിതി:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

ശൂന്യം midline(പൂർണ്ണസംഖ്യ d, അക്ഷരം *p){

   തിരഞ്ഞെടുപ്പ്(d){

      /* those that have leading | on middle line */

      അവസ്ഥ 0:
      അവസ്ഥ 4:
      അവസ്ഥ 5:
      അവസ്ഥ 6:
      അവസ്ഥ 8:
      അവസ്ഥ 9:
         *p++='|';
         നിർത്തുക;
      സ്ഥിരസ്ഥിതി:
         *p++=' ';	
   }
   തിരഞ്ഞെടുപ്പ്(d){

      /* those that have _ on middle line */

      അവസ്ഥ 2:
      അവസ്ഥ 3:
      അവസ്ഥ 4:
      അവസ്ഥ 5:
      അവസ്ഥ 6:
      അവസ്ഥ 8:
      അവസ്ഥ 9:
         *p++='_';
         നിർത്തുക;
      സ്ഥിരസ്ഥിതി:
         *p++=' ';

   }
   തിരഞ്ഞെടുപ്പ്(d){

      /* those that have closing | on middle line */

      അവസ്ഥ 0:
      അവസ്ഥ 1:
      അവസ്ഥ 2:
      അവസ്ഥ 3:
      അവസ്ഥ 4:
      അവസ്ഥ 7:
      അവസ്ഥ 8:
      അവസ്ഥ 9:
         *p++='|';
         നിർത്തുക;
      സ്ഥിരസ്ഥിതി:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

ശൂന്യം botline(പൂർണ്ണസംഖ്യ d, അക്ഷരം *p){


   തിരഞ്ഞെടുപ്പ്(d){

      /* those that have leading | on bottom line */

      അവസ്ഥ 0:
      അവസ്ഥ 2:
      അവസ്ഥ 6:
      അവസ്ഥ 8:
         *p++='|';
         നിർത്തുക;
      സ്ഥിരസ്ഥിതി:
         *p++=' ';	
   }
   തിരഞ്ഞെടുപ്പ്(d){

      /* those that have _ on bottom line */

      അവസ്ഥ 0:
      അവസ്ഥ 2:
      അവസ്ഥ 3:
      അവസ്ഥ 5:
      അവസ്ഥ 6:
      അവസ്ഥ 8:
         *p++='_';
         നിർത്തുക;
      സ്ഥിരസ്ഥിതി:
         *p++=' ';

   }
   തിരഞ്ഞെടുപ്പ്(d){

      /* those that have closing | on bottom line */

      അവസ്ഥ 0:
      അവസ്ഥ 1:
      അവസ്ഥ 3:
      അവസ്ഥ 4:
      അവസ്ഥ 5:
      അവസ്ഥ 6:
      അവസ്ഥ 7:
      അവസ്ഥ 8:
      അവസ്ഥ 9:
         *p++='|';
         നിർത്തുക;
      സ്ഥിരസ്ഥിതി:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

ശൂന്യം print_led(unsigned long x, അക്ഷരം *buf)
{

   പൂർണ്ണസംഖ്യ i=0,n;
   സ്ഥിതം പൂർണ്ണസംഖ്യ d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   ആകുമ്പോൾ(x){
      d[n++] = (പൂർണ്ണസംഖ്യ)(x%10L);
      എങ്കിൽ(n >= MAX_DIGITS)നിർത്തുക;
      x = x/10L;
   }

   /* print top lines of all digits */

   വേണ്ടി(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   വേണ്ടി(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   വേണ്ടി(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   അക്ഷരം buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   printf("%s\n",buf);

   തിരികെ 0;
}

#ifndef NO_MAIN
പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{

   പൂർണ്ണസംഖ്യ i=0,n;
   long x;
   സ്ഥിതം പൂർണ്ണസംഖ്യ d[MAX_DIGITS];
   അക്ഷരം buf[5*MAX_DIGITS];

   എങ്കിൽ(argc != 2){
      fprintf(stderr,"led: usage: led integer\n");
      തിരികെ 1;
   }

   /* fetch argument from command line */

   x = atol(argv[1]);

   /* sanity check */

   എങ്കിൽ(x<0){
      fprintf(stderr,"led: %d must be non-negative\n",x);
      തിരികെ 1;
   }

   print_led(x,buf);
   printf("%s\n",buf);

   തിരികെ 0;

}
#endif

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
