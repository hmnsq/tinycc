static ကိန်းပြည့် simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ပြန်ပေး 0;
label:
  ပြန်ပေး 1;
}

static ကိန်းပြည့် three_way_jump(ကိန်းပြည့် val, ကိန်းပြည့် *addr)
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
  ပြန်ပေး 1;
smaller:
  ပြန်ပေး 2;
larger:
  ပြန်ပေး 3;
}

static ကိန်းပြည့် another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ပြန်ပေး 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ပြန်ပေး 71;
}

extern ကိန်းပြည့် printf (const var_na *, ...);
ကိန်းပြည့် main(void)
{
  ကိန်းပြည့် i;
  အကယ်၍ (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  မဟုတ်ပါက
    printf ("simple_jump: wrong\n");
  အကယ်၍ (another_jump () == 71)
    printf ("another_jump: okay\n");
  မဟုတ်ပါက
    printf ("another_jump: wrong\n");
  အကယ်၍ (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  မဟုတ်ပါက
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  အကယ်၍ (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  မဟုတ်ပါက
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  အကယ်၍ (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  မဟုတ်ပါက
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  ပြန်ပေး 0;
}
