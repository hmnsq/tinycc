ساكن صحيح simple_jump(فراغ)
{
  asm اذهب ("jmp %l[label]" : : : : label);
  إرجاع 0;
label:
  إرجاع 1;
}

ساكن صحيح three_way_jump(صحيح val, صحيح *addr)
{
  *addr = 42;
  asm اذهب ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  إرجاع 1;
smaller:
  إرجاع 2;
larger:
  إرجاع 3;
}

ساكن صحيح another_jump(فراغ)
{
  asm اذهب ("jmp %l[label]" : : : : label);
  إرجاع 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  إرجاع 71;
}

خارجي صحيح printf (ثابت حرف *, ...);
صحيح الرئيسية(فراغ)
{
  صحيح i;
  إذا (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  وإلا
    printf ("simple_jump: wrong\n");
  إذا (another_jump () == 71)
    printf ("another_jump: okay\n");
  وإلا
    printf ("another_jump: wrong\n");
  إذا (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  وإلا
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  إذا (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  وإلا
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  إذا (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  وإلا
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  إرجاع 0;
}
