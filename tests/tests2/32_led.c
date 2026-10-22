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



#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>

#define MAX_DIGITS 32
#define NO_MAIN


/* Print the top line of the digit d into buffer. 
   Does not null terminate buffer. */

ಶೂನ್ಯ topline(ಪೂರ್ಣಾಙ್ಕ d, ವರ್ಣ *p){

   *p++ = ' ';
   ವಿಕಲ್ಪ(d){

      /* all these have _ on top line */

      ಪಕ್ಷ 0:
      ಪಕ್ಷ 2:
      ಪಕ್ಷ 3:
      ಪಕ್ಷ 5:
      ಪಕ್ಷ 7:
      ಪಕ್ಷ 8:
      ಪಕ್ಷ 9:
         *p++ = '_';
         ಭಙ್ಗ;
      ಸ್ವಭಾವ:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

ಶೂನ್ಯ midline(ಪೂರ್ಣಾಙ್ಕ d, ವರ್ಣ *p){

   ವಿಕಲ್ಪ(d){

      /* those that have leading | on middle line */

      ಪಕ್ಷ 0:
      ಪಕ್ಷ 4:
      ಪಕ್ಷ 5:
      ಪಕ್ಷ 6:
      ಪಕ್ಷ 8:
      ಪಕ್ಷ 9:
         *p++='|';
         ಭಙ್ಗ;
      ಸ್ವಭಾವ:
         *p++=' ';	
   }
   ವಿಕಲ್ಪ(d){

      /* those that have _ on middle line */

      ಪಕ್ಷ 2:
      ಪಕ್ಷ 3:
      ಪಕ್ಷ 4:
      ಪಕ್ಷ 5:
      ಪಕ್ಷ 6:
      ಪಕ್ಷ 8:
      ಪಕ್ಷ 9:
         *p++='_';
         ಭಙ್ಗ;
      ಸ್ವಭಾವ:
         *p++=' ';

   }
   ವಿಕಲ್ಪ(d){

      /* those that have closing | on middle line */

      ಪಕ್ಷ 0:
      ಪಕ್ಷ 1:
      ಪಕ್ಷ 2:
      ಪಕ್ಷ 3:
      ಪಕ್ಷ 4:
      ಪಕ್ಷ 7:
      ಪಕ್ಷ 8:
      ಪಕ್ಷ 9:
         *p++='|';
         ಭಙ್ಗ;
      ಸ್ವಭಾವ:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

ಶೂನ್ಯ botline(ಪೂರ್ಣಾಙ್ಕ d, ವರ್ಣ *p){


   ವಿಕಲ್ಪ(d){

      /* those that have leading | on bottom line */

      ಪಕ್ಷ 0:
      ಪಕ್ಷ 2:
      ಪಕ್ಷ 6:
      ಪಕ್ಷ 8:
         *p++='|';
         ಭಙ್ಗ;
      ಸ್ವಭಾವ:
         *p++=' ';	
   }
   ವಿಕಲ್ಪ(d){

      /* those that have _ on bottom line */

      ಪಕ್ಷ 0:
      ಪಕ್ಷ 2:
      ಪಕ್ಷ 3:
      ಪಕ್ಷ 5:
      ಪಕ್ಷ 6:
      ಪಕ್ಷ 8:
         *p++='_';
         ಭಙ್ಗ;
      ಸ್ವಭಾವ:
         *p++=' ';

   }
   ವಿಕಲ್ಪ(d){

      /* those that have closing | on bottom line */

      ಪಕ್ಷ 0:
      ಪಕ್ಷ 1:
      ಪಕ್ಷ 3:
      ಪಕ್ಷ 4:
      ಪಕ್ಷ 5:
      ಪಕ್ಷ 6:
      ಪಕ್ಷ 7:
      ಪಕ್ಷ 8:
      ಪಕ್ಷ 9:
         *p++='|';
         ಭಙ್ಗ;
      ಸ್ವಭಾವ:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

ಶೂನ್ಯ print_led(unsigned long x, ವರ್ಣ *buf)
{

   ಪೂರ್ಣಾಙ್ಕ i=0,n;
   ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   ಯಾವತ್(x){
      d[n++] = (ಪೂರ್ಣಾಙ್ಕ)(x%10L);
      ಯದಿ(n >= MAX_DIGITS)ಭಙ್ಗ;
      x = x/10L;
   }

   /* print top lines of all digits */

   ಪ್ರತಿ(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   ಪ್ರತಿ(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   ಪ್ರತಿ(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

ಪೂರ್ಣಾಙ್ಕ main()
{
   ವರ್ಣ buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   printf("%s\n",buf);

   ಪ್ರತ್ಯಾಗಮ 0;
}

#ifndef NO_MAIN
ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{

   ಪೂರ್ಣಾಙ್ಕ i=0,n;
   long x;
   ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ d[MAX_DIGITS];
   ವರ್ಣ buf[5*MAX_DIGITS];

   ಯದಿ(argc != 2){
      fprintf(stderr,"led: usage: led integer\n");
      ಪ್ರತ್ಯಾಗಮ 1;
   }

   /* fetch argument from command line */

   x = atol(argv[1]);

   /* sanity check */

   ಯದಿ(x<0){
      fprintf(stderr,"led: %d must be non-negative\n",x);
      ಪ್ರತ್ಯಾಗಮ 1;
   }

   print_led(x,buf);
   printf("%s\n",buf);

   ಪ್ರತ್ಯಾಗಮ 0;

}
#endif

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
