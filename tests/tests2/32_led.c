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



#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>

#define MAX_DIGITS 32
#define NO_MAIN


/* Print the top line of the digit d into buffer. 
   Does not null terminate buffer. */

ଶୂନ୍ୟ topline(ପୂର୍ଣ୍ଣସଂଖ୍ୟା d, ଅକ୍ଷର *p){

   *p++ = ' ';
   ବାଛ(d){

      /* all these have _ on top line */

      ସ୍ଥିତି 0:
      ସ୍ଥିତି 2:
      ସ୍ଥିତି 3:
      ସ୍ଥିତି 5:
      ସ୍ଥିତି 7:
      ସ୍ଥିତି 8:
      ସ୍ଥିତି 9:
         *p++ = '_';
         ଭାଙ୍ଗ;
      ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

ଶୂନ୍ୟ midline(ପୂର୍ଣ୍ଣସଂଖ୍ୟା d, ଅକ୍ଷର *p){

   ବାଛ(d){

      /* those that have leading | on middle line */

      ସ୍ଥିତି 0:
      ସ୍ଥିତି 4:
      ସ୍ଥିତି 5:
      ସ୍ଥିତି 6:
      ସ୍ଥିତି 8:
      ସ୍ଥିତି 9:
         *p++='|';
         ଭାଙ୍ଗ;
      ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
         *p++=' ';	
   }
   ବାଛ(d){

      /* those that have _ on middle line */

      ସ୍ଥିତି 2:
      ସ୍ଥିତି 3:
      ସ୍ଥିତି 4:
      ସ୍ଥିତି 5:
      ସ୍ଥିତି 6:
      ସ୍ଥିତି 8:
      ସ୍ଥିତି 9:
         *p++='_';
         ଭାଙ୍ଗ;
      ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
         *p++=' ';

   }
   ବାଛ(d){

      /* those that have closing | on middle line */

      ସ୍ଥିତି 0:
      ସ୍ଥିତି 1:
      ସ୍ଥିତି 2:
      ସ୍ଥିତି 3:
      ସ୍ଥିତି 4:
      ସ୍ଥିତି 7:
      ସ୍ଥିତି 8:
      ସ୍ଥିତି 9:
         *p++='|';
         ଭାଙ୍ଗ;
      ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

ଶୂନ୍ୟ botline(ପୂର୍ଣ୍ଣସଂଖ୍ୟା d, ଅକ୍ଷର *p){


   ବାଛ(d){

      /* those that have leading | on bottom line */

      ସ୍ଥିତି 0:
      ସ୍ଥିତି 2:
      ସ୍ଥିତି 6:
      ସ୍ଥିତି 8:
         *p++='|';
         ଭାଙ୍ଗ;
      ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
         *p++=' ';	
   }
   ବାଛ(d){

      /* those that have _ on bottom line */

      ସ୍ଥିତି 0:
      ସ୍ଥିତି 2:
      ସ୍ଥିତି 3:
      ସ୍ଥିତି 5:
      ସ୍ଥିତି 6:
      ସ୍ଥିତି 8:
         *p++='_';
         ଭାଙ୍ଗ;
      ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
         *p++=' ';

   }
   ବାଛ(d){

      /* those that have closing | on bottom line */

      ସ୍ଥିତି 0:
      ସ୍ଥିତି 1:
      ସ୍ଥିତି 3:
      ସ୍ଥିତି 4:
      ସ୍ଥିତି 5:
      ସ୍ଥିତି 6:
      ସ୍ଥିତି 7:
      ସ୍ଥିତି 8:
      ସ୍ଥିତି 9:
         *p++='|';
         ଭାଙ୍ଗ;
      ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

ଶୂନ୍ୟ print_led(unsigned long x, ଅକ୍ଷର *buf)
{

   ପୂର୍ଣ୍ଣସଂଖ୍ୟା i=0,n;
   ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   ଯେତେବେଳେ(x){
      d[n++] = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(x%10L);
      ଯଦି(n >= MAX_DIGITS)ଭାଙ୍ଗ;
      x = x/10L;
   }

   /* print top lines of all digits */

   ପାଇଁ(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   ପାଇଁ(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   ପାଇଁ(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   ଅକ୍ଷର buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   printf("%s\n",buf);

   ଫେରନ୍ତୁ 0;
}

#ifndef NO_MAIN
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{

   ପୂର୍ଣ୍ଣସଂଖ୍ୟା i=0,n;
   long x;
   ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା d[MAX_DIGITS];
   ଅକ୍ଷର buf[5*MAX_DIGITS];

   ଯଦି(argc != 2){
      fprintf(stderr,"led: usage: led integer\n");
      ଫେରନ୍ତୁ 1;
   }

   /* fetch argument from command line */

   x = atol(argv[1]);

   /* sanity check */

   ଯଦି(x<0){
      fprintf(stderr,"led: %d must be non-negative\n",x);
      ଫେରନ୍ତୁ 1;
   }

   print_led(x,buf);
   printf("%s\n",buf);

   ଫେରନ୍ତୁ 0;

}
#endif

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
