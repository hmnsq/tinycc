ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ simple_jump(ಶೂನ್ಯ)
{
  asm ಗಚ್ಛ ("jmp %l[label]" : : : : label);
  ಪ್ರತ್ಯಾಗಮ 0;
label:
  ಪ್ರತ್ಯಾಗಮ 1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ three_way_jump(ಪೂರ್ಣಾಙ್ಕ val, ಪೂರ್ಣಾಙ್ಕ *addr)
{
  *addr = 42;
  asm ಗಚ್ಛ ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  ಪ್ರತ್ಯಾಗಮ 1;
smaller:
  ಪ್ರತ್ಯಾಗಮ 2;
larger:
  ಪ್ರತ್ಯಾಗಮ 3;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ another_jump(ಶೂನ್ಯ)
{
  asm ಗಚ್ಛ ("jmp %l[label]" : : : : label);
  ಪ್ರತ್ಯಾಗಮ 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ಪ್ರತ್ಯಾಗಮ 71;
}

ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ printf (ಧ್ರುವ ವರ್ಣ *, ...);
ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಙ್ಕ i;
  ಯದಿ (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  ಅನ್ಯಥಾ
    printf ("simple_jump: wrong\n");
  ಯದಿ (another_jump () == 71)
    printf ("another_jump: okay\n");
  ಅನ್ಯಥಾ
    printf ("another_jump: wrong\n");
  ಯದಿ (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  ಅನ್ಯಥಾ
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  ಯದಿ (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  ಅನ್ಯಥಾ
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  ಯದಿ (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  ಅನ್ಯಥಾ
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  ಪ್ರತ್ಯಾಗಮ 0;
}
