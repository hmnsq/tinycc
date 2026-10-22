ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ ಲಿಖ (ಪೂರ್ಣಾಂಕ fd, ಶೂನ್ಯ *buf, ಪೂರ್ಣಾಂಕ len);

ಸ್ಥಿರ ಶೂನ್ಯ __attribute__ ((constructor))
testc (ಶೂನ್ಯ)
{
  ಲಿಖ (1, "constructor\n", 12);
}

ಸ್ಥಿರ ಶೂನ್ಯ __attribute__ ((destructor))
testd (ಶೂನ್ಯ)
{
  ಲಿಖ (1, "destructor\n", 11);
}

ಪೂರ್ಣಾಂಕ
ಮುಖ್ಯ (ಶೂನ್ಯ)
{
  ಲಿಖ (1, "main\n", 5);
  ಹಿಂತಿರುಗಿ 0;
}
