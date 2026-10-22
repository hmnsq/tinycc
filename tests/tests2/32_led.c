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



#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <stdio.h>

#నిర్వచించు MAX_DIGITS 32
#నిర్వచించు NO_MAIN


/* Print the top line of the digit d into buffer. 
   Does not null terminate buffer. */

శూన్య topline(పూర్ణాంకం d, అక్షరం *p){

   *p++ = ' ';
   ఎంపిక(d){

      /* all these have _ on top line */

      స్థితి 0:
      స్థితి 2:
      స్థితి 3:
      స్థితి 5:
      స్థితి 7:
      స్థితి 8:
      స్థితి 9:
         *p++ = '_';
         ఆపు;
      అప్రమేయ:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

శూన్య midline(పూర్ణాంకం d, అక్షరం *p){

   ఎంపిక(d){

      /* those that have leading | on middle line */

      స్థితి 0:
      స్థితి 4:
      స్థితి 5:
      స్థితి 6:
      స్థితి 8:
      స్థితి 9:
         *p++='|';
         ఆపు;
      అప్రమేయ:
         *p++=' ';	
   }
   ఎంపిక(d){

      /* those that have _ on middle line */

      స్థితి 2:
      స్థితి 3:
      స్థితి 4:
      స్థితి 5:
      స్థితి 6:
      స్థితి 8:
      స్థితి 9:
         *p++='_';
         ఆపు;
      అప్రమేయ:
         *p++=' ';

   }
   ఎంపిక(d){

      /* those that have closing | on middle line */

      స్థితి 0:
      స్థితి 1:
      స్థితి 2:
      స్థితి 3:
      స్థితి 4:
      స్థితి 7:
      స్థితి 8:
      స్థితి 9:
         *p++='|';
         ఆపు;
      అప్రమేయ:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

శూన్య botline(పూర్ణాంకం d, అక్షరం *p){


   ఎంపిక(d){

      /* those that have leading | on bottom line */

      స్థితి 0:
      స్థితి 2:
      స్థితి 6:
      స్థితి 8:
         *p++='|';
         ఆపు;
      అప్రమేయ:
         *p++=' ';	
   }
   ఎంపిక(d){

      /* those that have _ on bottom line */

      స్థితి 0:
      స్థితి 2:
      స్థితి 3:
      స్థితి 5:
      స్థితి 6:
      స్థితి 8:
         *p++='_';
         ఆపు;
      అప్రమేయ:
         *p++=' ';

   }
   ఎంపిక(d){

      /* those that have closing | on bottom line */

      స్థితి 0:
      స్థితి 1:
      స్థితి 3:
      స్థితి 4:
      స్థితి 5:
      స్థితి 6:
      స్థితి 7:
      స్థితి 8:
      స్థితి 9:
         *p++='|';
         ఆపు;
      అప్రమేయ:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

శూన్య print_led(గుర్తులేని దీర్ఘ x, అక్షరం *buf)
{

   పూర్ణాంకం i=0,n;
   స్థిర పూర్ణాంకం d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   అయితే(x){
      d[n++] = (పూర్ణాంకం)(x%10L);
      ఒకవేళ(n >= MAX_DIGITS)ఆపు;
      x = x/10L;
   }

   /* print top lines of all digits */

   కొరకు(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   కొరకు(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   కొరకు(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

పూర్ణాంకం ప్రధాన()
{
   అక్షరం buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   రాయి("%s\n",buf);

   తిరిగి 0;
}

#నిర్వచితం_కాకపోతే NO_MAIN
పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{

   పూర్ణాంకం i=0,n;
   దీర్ఘ x;
   స్థిర పూర్ణాంకం d[MAX_DIGITS];
   అక్షరం buf[5*MAX_DIGITS];

   ఒకవేళ(argc != 2){
      fprintf(stderr,"led: usage: led integer\n");
      తిరిగి 1;
   }

   /* fetch argument from command line */

   x = atol(argv[1]);

   /* sanity check */

   ఒకవేళ(x<0){
      fprintf(stderr,"led: %d must be non-negative\n",x);
      తిరిగి 1;
   }

   print_led(x,buf);
   రాయి("%s\n",buf);

   తిరిగి 0;

}
#అయితే_ముగింపు

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
