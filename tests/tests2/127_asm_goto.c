ایستا صحیح simple_jump(تهی)
{
  asm برو ("jmp %l[label]" : : : : label);
  بازگشت 0;
label:
  بازگشت 1;
}

ایستا صحیح three_way_jump(صحیح val, صحیح *addr)
{
  *addr = 42;
  asm برو ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  بازگشت 1;
smaller:
  بازگشت 2;
larger:
  بازگشت 3;
}

ایستا صحیح another_jump(تهی)
{
  asm برو ("jmp %l[label]" : : : : label);
  بازگشت 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  بازگشت 71;
}

بیرونی صحیح printf (ثابت نویسه *, ...);
صحیح اصلی(تهی)
{
  صحیح i;
  اگر (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  وگرنه
    printf ("simple_jump: wrong\n");
  اگر (another_jump () == 71)
    printf ("another_jump: okay\n");
  وگرنه
    printf ("another_jump: wrong\n");
  اگر (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  وگرنه
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  اگر (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  وگرنه
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  اگر (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  وگرنه
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  بازگشت 0;
}
