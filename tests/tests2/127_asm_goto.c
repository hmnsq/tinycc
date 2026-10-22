ساکن صحیح simple_jump(خالی)
{
  asm جاؤ ("jmp %l[label]" : : : : label);
  واپس 0;
label:
  واپس 1;
}

ساکن صحیح three_way_jump(صحیح val, صحیح *addr)
{
  *addr = 42;
  asm جاؤ ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  واپس 1;
smaller:
  واپس 2;
larger:
  واپس 3;
}

ساکن صحیح another_jump(خالی)
{
  asm جاؤ ("jmp %l[label]" : : : : label);
  واپس 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  واپس 71;
}

خارجی صحیح لکھو (ثابت حرف *, ...);
صحیح مین(خالی)
{
  صحیح i;
  اگر (simple_jump () == 1)
    لکھو ("simple_jump: okay\n");
  ورنہ
    لکھو ("simple_jump: wrong\n");
  اگر (another_jump () == 71)
    لکھو ("another_jump: okay\n");
  ورنہ
    لکھو ("another_jump: wrong\n");
  اگر (three_way_jump(0, &i) == 1 && i == 43)
    لکھو ("three_way_jump(0): okay\n");
  ورنہ
    لکھو ("three_way_jump(0): wrong (i=%d)\n", i);
  اگر (three_way_jump(1, &i) == 3 && i == 42)
    لکھو ("three_way_jump(1): okay\n");
  ورنہ
    لکھو ("three_way_jump(1): wrong (i=%d)\n", i);
  اگر (three_way_jump(-1, &i) == 2 && i == 42)
    لکھو ("three_way_jump(-1): okay\n");
  ورنہ
    لکھو ("three_way_jump(-1): wrong (i=%d)\n", i);
  واپس 0;
}
