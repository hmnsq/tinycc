static ຈຳນວນເຕັມ simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ສົ່ງຄືນ 0;
label:
  ສົ່ງຄືນ 1;
}

static ຈຳນວນເຕັມ three_way_jump(ຈຳນວນເຕັມ val, ຈຳນວນເຕັມ *addr)
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
  ສົ່ງຄືນ 1;
smaller:
  ສົ່ງຄືນ 2;
larger:
  ສົ່ງຄືນ 3;
}

static ຈຳນວນເຕັມ another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ສົ່ງຄືນ 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ສົ່ງຄືນ 71;
}

extern ຈຳນວນເຕັມ printf (const var_na *, ...);
ຈຳນວນເຕັມ main(void)
{
  ຈຳນວນເຕັມ i;
  ຖ້າ (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  ບໍ່ດັ່ງນັ້ນ
    printf ("simple_jump: wrong\n");
  ຖ້າ (another_jump () == 71)
    printf ("another_jump: okay\n");
  ບໍ່ດັ່ງນັ້ນ
    printf ("another_jump: wrong\n");
  ຖ້າ (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  ບໍ່ດັ່ງນັ້ນ
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  ຖ້າ (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  ບໍ່ດັ່ງນັ້ນ
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  ຖ້າ (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  ບໍ່ດັ່ງນັ້ນ
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  ສົ່ງຄືນ 0;
}
