static จำนวนเต็ม simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  คืน 0;
label:
  คืน 1;
}

static จำนวนเต็ม three_way_jump(จำนวนเต็ม val, จำนวนเต็ม *addr)
{
  *addr = 42;
  asm goto ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  คืน 1;
smaller:
  คืน 2;
larger:
  คืน 3;
}

static จำนวนเต็ม another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  คืน 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  คืน 71;
}

extern จำนวนเต็ม printf (const var_na *, ...);
จำนวนเต็ม หลัก(void)
{
  จำนวนเต็ม i;
  ถ้า (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  มิฉะนั้น
    printf ("simple_jump: wrong\n");
  ถ้า (another_jump () == 71)
    printf ("another_jump: okay\n");
  มิฉะนั้น
    printf ("another_jump: wrong\n");
  ถ้า (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  มิฉะนั้น
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  ถ้า (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  มิฉะนั้น
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  ถ้า (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  มิฉะนั้น
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  คืน 0;
}
