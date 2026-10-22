ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ ಲಿಖ (ಪೂರ್ಣಾಙ್ಕ fd, ಶೂನ್ಯ *buf, ಪೂರ್ಣಾಙ್ಕ len);

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

ಪೂರ್ಣಾಙ್ಕ
main (ಶೂನ್ಯ)
{
  ಲಿಖ (1, "main\n", 5);
  ಪ್ರತ್ಯಾಗಮ 0;
}
