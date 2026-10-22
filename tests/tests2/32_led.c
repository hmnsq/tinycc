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



#شامل <stdlib.h>
#شامل <stdio.h>

#تعریف_کرو MAX_DIGITS 32
#تعریف_کرو NO_MAIN


/* Print the top line of the digit d into buffer. 
   Does not null terminate buffer. */

خالی topline(صحیح d, حرف *p){

   *p++ = ' ';
   انتخاب(d){

      /* all these have _ on top line */

      حالت 0:
      حالت 2:
      حالت 3:
      حالت 5:
      حالت 7:
      حالت 8:
      حالت 9:
         *p++ = '_';
         توڑو;
      طےشدہ:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer. 
   Does not null terminate. */

خالی midline(صحیح d, حرف *p){

   انتخاب(d){

      /* those that have leading | on middle line */

      حالت 0:
      حالت 4:
      حالت 5:
      حالت 6:
      حالت 8:
      حالت 9:
         *p++='|';
         توڑو;
      طےشدہ:
         *p++=' ';	
   }
   انتخاب(d){

      /* those that have _ on middle line */

      حالت 2:
      حالت 3:
      حالت 4:
      حالت 5:
      حالت 6:
      حالت 8:
      حالت 9:
         *p++='_';
         توڑو;
      طےشدہ:
         *p++=' ';

   }
   انتخاب(d){

      /* those that have closing | on middle line */

      حالت 0:
      حالت 1:
      حالت 2:
      حالت 3:
      حالت 4:
      حالت 7:
      حالت 8:
      حالت 9:
         *p++='|';
         توڑو;
      طےشدہ:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

خالی botline(صحیح d, حرف *p){


   انتخاب(d){

      /* those that have leading | on bottom line */

      حالت 0:
      حالت 2:
      حالت 6:
      حالت 8:
         *p++='|';
         توڑو;
      طےشدہ:
         *p++=' ';	
   }
   انتخاب(d){

      /* those that have _ on bottom line */

      حالت 0:
      حالت 2:
      حالت 3:
      حالت 5:
      حالت 6:
      حالت 8:
         *p++='_';
         توڑو;
      طےشدہ:
         *p++=' ';

   }
   انتخاب(d){

      /* those that have closing | on bottom line */

      حالت 0:
      حالت 1:
      حالت 3:
      حالت 4:
      حالت 5:
      حالت 6:
      حالت 7:
      حالت 8:
      حالت 9:
         *p++='|';
         توڑو;
      طےشدہ:
         *p++=' ';

   }
}

/* Write the led representation of integer to string buffer. */

خالی print_led(غیرعلامتی طویل x, حرف *buf)
{

   صحیح i=0,n;
   ساکن صحیح d[MAX_DIGITS];


   /* extract digits from x */

   n = ( x == 0L ? 1 : 0 );  /* 0 is a digit, hence a special case */

   جب(x){
      d[n++] = (صحیح)(x%10L);
      اگر(n >= MAX_DIGITS)توڑو;
      x = x/10L;
   }

   /* print top lines of all digits */

   برائے(i=n-1;i>=0;i--){
      topline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n'; /* move teletype to next line */

   /* print middle lines of all digits */

   برائے(i=n-1;i>=0;i--){
      midline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';

   /* print bottom lines of all digits */

   برائے(i=n-1;i>=0;i--){
      botline(d[i],buf);
      buf += 3;
      *buf++=' ';
   }
   *buf++='\n';
   *buf='\0';
}

صحیح مین()
{
   حرف buf[5*MAX_DIGITS];
   print_led(1234567, buf);
   لکھو("%s\n",buf);

   واپس 0;
}

#اگر_غیر_تعریف_شدہ NO_MAIN
صحیح مین(صحیح argc, حرف **argv)
{

   صحیح i=0,n;
   طویل x;
   ساکن صحیح d[MAX_DIGITS];
   حرف buf[5*MAX_DIGITS];

   اگر(argc != 2){
      fprintf(stderr,"led: usage: led integer\n");
      واپس 1;
   }

   /* fetch argument from command line */

   x = atol(argv[1]);

   /* sanity check */

   اگر(x<0){
      fprintf(stderr,"led: %d must be non-negative\n",x);
      واپس 1;
   }

   print_led(x,buf);
   لکھو("%s\n",buf);

   واپس 0;

}
#اگر_ختم

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
