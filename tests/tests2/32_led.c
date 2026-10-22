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

#ವ್ಯಾಖ್ಯಾನಿಸು MAX_DIGITS 32
#ವ್ಯಾಖ್ಯಾನಿಸು NO_MAIN


/* Print the top line of the digit d into buffer. 
   Does not null terminate buffer. */

ಶೂನ್ಯ topline(ಪೂರ್ಣಾಂಕ d, ಅಕ್ಷರ *p){

   *p++ = ' ';
   ಆಯ್ಕೆ(d){

      /* all these have _ on top line */

      ಸ್ಥಿತಿ 0:
      ಸ್ಥಿತಿ 2:
      ಸ್ಥಿತಿ 3:
      ಸ್ಥಿತಿ 5:
      ಸ್ಥಿತಿ 7:
      ಸ್ಥಿತಿ 8:
      ಸ್ಥಿತಿ 9:
         *p++ = '_';
         ನಿಲ್ಲಿಸು;
      ಪೂರ್ವನಿಯೋಜಿತ:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

ಶೂನ್ಯ midline(ಪೂರ್ಣಾಂಕ d, ಅಕ್ಷರ *p){

   ಆಯ್ಕೆ(d){

      /* those that have leading | on middle line */

      ಸ್ಥಿತಿ 0:
      ಸ್ಥಿತಿ 4:
      ಸ್ಥಿತಿ 5:
      ಸ್ಥಿತಿ 6:
      ಸ್ಥಿತಿ 8:
      ಸ್ಥಿತಿ 9:
         *p++='|';
         ನಿಲ್ಲಿಸು;
      ಪೂರ್ವನಿಯೋಜಿತ:
         *p++=' ';	
   }
   ಆಯ್ಕೆ(d){

      /* those that have _ on middle line */

      ಸ್ಥಿತಿ 2:
      ಸ್ಥಿತಿ 3:
      ಸ್ಥಿತಿ 4:
      ಸ್ಥಿತಿ 5:
      ಸ್ಥಿತಿ 6:
      ಸ್ಥಿತಿ 8:
      ಸ್ಥಿತಿ 9:
         *p++='_';
         ನಿಲ್ಲಿಸು;
      ಪೂರ್ವನಿಯೋಜಿತ:
         *p++=' ';

   }
   ಆಯ್ಕೆ(d){

      /* those that have closing | on middle line */

      ಸ್ಥಿತಿ 0:
      ಸ್ಥಿತಿ 1:
      ಸ್ಥಿತಿ 2:
      ಸ್ಥಿತಿ 3:
      ಸ್ಥಿತಿ 4:
      ಸ್ಥಿತಿ 7:
      ಸ್ಥಿತಿ 8:
      ಸ್ಥಿತಿ 9:
         *p++='|';
         ನಿಲ್ಲಿಸು;
      ಪೂರ್ವನಿಯೋಜಿತ:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

ಶೂನ್ಯ botline(ಪೂರ್ಣಾಂಕ d, ಅಕ್ಷರ *p){


   ಆಯ್ಕೆ(d){

      /* those that have leading | on bottom line */

      ಸ್ಥಿತಿ 0:
      ಸ್ಥಿತಿ 2:
      ಸ್ಥಿತಿ 6:
      ಸ್ಥಿತಿ 8:
         *p++='|';
         ನಿಲ್ಲಿಸು;
      ಪೂರ್ವನಿಯೋಜಿತ:
         *p++=' ';	
   }
   ಆಯ್ಕೆ(d){

      /* those that have _ on bottom line */

      ಸ್ಥಿತಿ 0:
      ಸ್ಥಿತಿ 2:
      ಸ್ಥಿತಿ 3:
      ಸ್ಥಿತಿ 5:
      ಸ್ಥಿತಿ 6:
      ಸ್ಥಿತಿ 8:
         *p++='_';
         ನಿಲ್ಲಿಸು;
      ಪೂರ್ವನಿಯೋಜಿತ:
         *p++=' ';

   }
   ಆಯ್ಕೆ(d){

      /* those that have closing | on bottom line */

      ಸ್ಥಿತಿ 0:
      ಸ್ಥಿತಿ 1:
      ಸ್ಥಿತಿ 3:
      ಸ್ಥಿತಿ 4:
      ಸ್ಥಿತಿ 5:
      ಸ್ಥಿತಿ 6:
      ಸ್ಥಿತಿ 7:
      ಸ್ಥಿತಿ 8:
      ಸ್ಥಿತಿ 9:
         *p++='|';
         ನಿಲ್ಲಿಸು;
      ಪೂರ್ವನಿಯೋಜಿತ:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

ಶೂನ್ಯ print_led(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ x, ಅಕ್ಷರ *buf)
{

   ಪೂರ್ಣಾಂಕ i=0,n;
   ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   ಆಗ(x){
      d[n++] = (ಪೂರ್ಣಾಂಕ)(x%10L);
      ಆದರೆ(n >= MAX_DIGITS)ನಿಲ್ಲಿಸು;
      x = x/10L;
   }

   /* print top lines of all digits */

   ಗಾಗಿ(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   ಗಾಗಿ(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   ಗಾಗಿ(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   ಅಕ್ಷರ buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   ಬರೆ("%s\n",buf);

   ಹಿಂತಿರುಗಿ 0;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NO_MAIN
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{

   ಪೂರ್ಣಾಂಕ i=0,n;
   ದೀರ್ಘ x;
   ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ d[MAX_DIGITS];
   ಅಕ್ಷರ buf[5*MAX_DIGITS];

   ಆದರೆ(argc != 2){
      fprintf(stderr,"led: usage: led integer\n");
      ಹಿಂತಿರುಗಿ 1;
   }

   /* fetch argument from command line */

   x = atol(argv[1]);

   /* sanity check */

   ಆದರೆ(x<0){
      fprintf(stderr,"led: %d must be non-negative\n",x);
      ಹಿಂತಿರುಗಿ 1;
   }

   print_led(x,buf);
   ಬರೆ("%s\n",buf);

   ಹಿಂತಿರುಗಿ 0;

}
#ಆದರೆ_ಅಂತ್ಯ

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
