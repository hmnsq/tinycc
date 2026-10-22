बाह्य पूर्णाङ्क लिख (पूर्णाङ्क fd, शून्य *buf, पूर्णाङ्क len);

स्थिर शून्य __attribute__ ((constructor))
testc (शून्य)
{
  लिख (1, "constructor\n", 12);
}

स्थिर शून्य __attribute__ ((destructor))
testd (शून्य)
{
  लिख (1, "destructor\n", 11);
}

पूर्णाङ्क
main (शून्य)
{
  लिख (1, "main\n", 5);
  पटिनिवत्त 0;
}
