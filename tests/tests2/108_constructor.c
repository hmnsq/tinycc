బాహ్య పూర్ణాంకం లిఖ (పూర్ణాంకం fd, శూన్య *buf, పూర్ణాంకం len);

స్థిర శూన్య __attribute__ ((constructor))
testc (శూన్య)
{
  లిఖ (1, "constructor\n", 12);
}

స్థిర శూన్య __attribute__ ((destructor))
testd (శూన్య)
{
  లిఖ (1, "destructor\n", 11);
}

పూర్ణాంకం
ప్రధాన (శూన్య)
{
  లిఖ (1, "main\n", 5);
  తిరిగి 0;
}
