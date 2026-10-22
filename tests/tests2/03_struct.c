ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ ಬರೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*, ...);

ರಚನೆ fred;

ಶೂನ್ಯ fred$(ರಚನೆ fred* this)
{
    ಬರೆ("~fred()\n");
}

ರಚನೆ __attribute__((__cleanup__(fred$))) fred
{
   ಪೂರ್ಣಾಂಕ boris;
   ಪೂರ್ಣಾಂಕ natasha;
};

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ರಚನೆ fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   ಬರೆ("%d\n", bloggs.boris);
   ಬರೆ("%d\n", bloggs.natasha);

   ರಚನೆ fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   ಬರೆ("%d\n", jones[0].boris);
   ಬರೆ("%d\n", jones[0].natasha);
   ಬರೆ("%d\n", jones[1].boris);
   ಬರೆ("%d\n", jones[1].natasha);

   ಹಿಂತಿರುಗಿ 0;
}
