ساكن صحيح simple_jump(فراغ)
{
  asm اذهب ("jmp %l[label]" : : : : label);
  أرجع 0;
label:
  أرجع 1;
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
  أرجع 1;
smaller:
  أرجع 2;
larger:
  أرجع 3;
}

ساكن صحيح another_jump(فراغ)
{
  asm اذهب ("jmp %l[label]" : : : : label);
  أرجع 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  أرجع 71;
}

خارجي صحيح چاپ_کړه (ثابت حرف *, ...);
صحيح اصلي(فراغ)
{
  صحيح i;
  إذا (simple_jump () == 1)
    چاپ_کړه ("simple_jump: okay\n");
  وإلا
    چاپ_کړه ("simple_jump: wrong\n");
  إذا (another_jump () == 71)
    چاپ_کړه ("another_jump: okay\n");
  وإلا
    چاپ_کړه ("another_jump: wrong\n");
  إذا (three_way_jump(0, &i) == 1 && i == 43)
    چاپ_کړه ("three_way_jump(0): okay\n");
  وإلا
    چاپ_کړه ("three_way_jump(0): wrong (i=%d)\n", i);
  إذا (three_way_jump(1, &i) == 3 && i == 42)
    چاپ_کړه ("three_way_jump(1): okay\n");
  وإلا
    چاپ_کړه ("three_way_jump(1): wrong (i=%d)\n", i);
  إذا (three_way_jump(-1, &i) == 2 && i == 42)
    چاپ_کړه ("three_way_jump(-1): okay\n");
  وإلا
    چاپ_کړه ("three_way_jump(-1): wrong (i=%d)\n", i);
  أرجع 0;
}
