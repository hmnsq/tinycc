ساكن صحيح simple_jump(فراغ)
{
  asm اذهب ("jmp %l[label]" : : : : label);
  החזר 0;
label:
  החזר 1;
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
  החזר 1;
smaller:
  החזר 2;
larger:
  החזר 3;
}

ساكن صحيح another_jump(فراغ)
{
  asm اذهب ("jmp %l[label]" : : : : label);
  החזר 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  החזר 71;
}

خارجي صحيح printf (ثابت حرف *, ...);
صحيح main(فراغ)
{
  صحيح i;
  אם (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  אחרת
    printf ("simple_jump: wrong\n");
  אם (another_jump () == 71)
    printf ("another_jump: okay\n");
  אחרת
    printf ("another_jump: wrong\n");
  אם (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  אחרת
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  אם (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  אחרת
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  אם (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  אחרת
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  החזר 0;
}
