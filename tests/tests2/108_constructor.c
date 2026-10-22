બાહ્ય પૂર્ણાંક લિખ (પૂર્ણાંક fd, શૂન્ય *buf, પૂર્ણાંક len);

સ્થિર શૂન્ય __attribute__ ((constructor))
testc (શૂન્ય)
{
  લિખ (1, "constructor\n", 12);
}

સ્થિર શૂન્ય __attribute__ ((destructor))
testd (શૂન્ય)
{
  લિખ (1, "destructor\n", 11);
}

પૂર્ણાંક
મુખ્ય (શૂન્ય)
{
  લિખ (1, "main\n", 5);
  પાછા 0;
}
