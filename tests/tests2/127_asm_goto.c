ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ simple_jump(ಶೂನ್ಯ)
{
  asm ಹೋಗು ("jmp %l[label]" : : : : label);
  ಹಿಂತಿರುಗಿ 0;
label:
  ಹಿಂತಿರುಗಿ 1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ three_way_jump(ಪೂರ್ಣಾಂಕ val, ಪೂರ್ಣಾಂಕ *addr)
{
  *addr = 42;
  asm ಹೋಗು ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  ಹಿಂತಿರುಗಿ 1;
smaller:
  ಹಿಂತಿರುಗಿ 2;
larger:
  ಹಿಂತಿರುಗಿ 3;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ another_jump(ಶೂನ್ಯ)
{
  asm ಹೋಗು ("jmp %l[label]" : : : : label);
  ಹಿಂತಿರುಗಿ 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ಹಿಂತಿರುಗಿ 71;
}

ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ ಬರೆ (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *, ...);
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಂಕ i;
  ಆದರೆ (simple_jump () == 1)
    ಬರೆ ("simple_jump: okay\n");
  ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ ("simple_jump: wrong\n");
  ಆದರೆ (another_jump () == 71)
    ಬರೆ ("another_jump: okay\n");
  ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ ("another_jump: wrong\n");
  ಆದರೆ (three_way_jump(0, &i) == 1 && i == 43)
    ಬರೆ ("three_way_jump(0): okay\n");
  ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ ("three_way_jump(0): wrong (i=%d)\n", i);
  ಆದರೆ (three_way_jump(1, &i) == 3 && i == 42)
    ಬರೆ ("three_way_jump(1): okay\n");
  ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ ("three_way_jump(1): wrong (i=%d)\n", i);
  ಆದರೆ (three_way_jump(-1, &i) == 2 && i == 42)
    ಬರೆ ("three_way_jump(-1): okay\n");
  ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ ("three_way_jump(-1): wrong (i=%d)\n", i);
  ಹಿಂತಿರುಗಿ 0;
}
