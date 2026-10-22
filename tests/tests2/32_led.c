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



#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <stdio.h>

#define MAX_DIGITS 32
#define NO_MAIN


/* Print the top line of the digit d into buffer. 
   Does not null terminate buffer. */

શૂન્ય topline(પૂર્ણાંક d, અક્ષર *p){

   *p++ = ' ';
   પસંદગી(d){

      /* all these have _ on top line */

      સ્થિતિ 0:
      સ્થિતિ 2:
      સ્થિતિ 3:
      સ્થિતિ 5:
      સ્થિતિ 7:
      સ્થિતિ 8:
      સ્થિતિ 9:
         *p++ = '_';
         તોડો;
      મૂળભૂત:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

શૂન્ય midline(પૂર્ણાંક d, અક્ષર *p){

   પસંદગી(d){

      /* those that have leading | on middle line */

      સ્થિતિ 0:
      સ્થિતિ 4:
      સ્થિતિ 5:
      સ્થિતિ 6:
      સ્થિતિ 8:
      સ્થિતિ 9:
         *p++='|';
         તોડો;
      મૂળભૂત:
         *p++=' ';	
   }
   પસંદગી(d){

      /* those that have _ on middle line */

      સ્થિતિ 2:
      સ્થિતિ 3:
      સ્થિતિ 4:
      સ્થિતિ 5:
      સ્થિતિ 6:
      સ્થિતિ 8:
      સ્થિતિ 9:
         *p++='_';
         તોડો;
      મૂળભૂત:
         *p++=' ';

   }
   પસંદગી(d){

      /* those that have closing | on middle line */

      સ્થિતિ 0:
      સ્થિતિ 1:
      સ્થિતિ 2:
      સ્થિતિ 3:
      સ્થિતિ 4:
      સ્થિતિ 7:
      સ્થિતિ 8:
      સ્થિતિ 9:
         *p++='|';
         તોડો;
      મૂળભૂત:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

શૂન્ય botline(પૂર્ણાંક d, અક્ષર *p){


   પસંદગી(d){

      /* those that have leading | on bottom line */

      સ્થિતિ 0:
      સ્થિતિ 2:
      સ્થિતિ 6:
      સ્થિતિ 8:
         *p++='|';
         તોડો;
      મૂળભૂત:
         *p++=' ';	
   }
   પસંદગી(d){

      /* those that have _ on bottom line */

      સ્થિતિ 0:
      સ્થિતિ 2:
      સ્થિતિ 3:
      સ્થિતિ 5:
      સ્થિતિ 6:
      સ્થિતિ 8:
         *p++='_';
         તોડો;
      મૂળભૂત:
         *p++=' ';

   }
   પસંદગી(d){

      /* those that have closing | on bottom line */

      સ્થિતિ 0:
      સ્થિતિ 1:
      સ્થિતિ 3:
      સ્થિતિ 4:
      સ્થિતિ 5:
      સ્થિતિ 6:
      સ્થિતિ 7:
      સ્થિતિ 8:
      સ્થિતિ 9:
         *p++='|';
         તોડો;
      મૂળભૂત:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

શૂન્ય print_led(unsigned long x, અક્ષર *buf)
{

   પૂર્ણાંક i=0,n;
   સ્થિર પૂર્ણાંક d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   જ્યારે(x){
      d[n++] = (પૂર્ણાંક)(x%10L);
      જો(n >= MAX_DIGITS)તોડો;
      x = x/10L;
   }

   /* print top lines of all digits */

   માટે(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   માટે(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   માટે(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

પૂર્ણાંક મુખ્ય()
{
   અક્ષર buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   printf("%s\n",buf);

   પાછા 0;
}

#ifndef NO_MAIN
પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{

   પૂર્ણાંક i=0,n;
   long x;
   સ્થિર પૂર્ણાંક d[MAX_DIGITS];
   અક્ષર buf[5*MAX_DIGITS];

   જો(argc != 2){
      fprintf(stderr,"led: usage: led integer\n");
      પાછા 1;
   }

   /* fetch argument from command line */

   x = atol(argv[1]);

   /* sanity check */

   જો(x<0){
      fprintf(stderr,"led: %d must be non-negative\n",x);
      પાછા 1;
   }

   print_led(x,buf);
   printf("%s\n",buf);

   પાછા 0;

}
#endif

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
