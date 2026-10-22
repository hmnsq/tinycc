बाह्य पूर्णांक लिख (पूर्णांक fd, शून्य *buf, पूर्णांक len);

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

पूर्णांक
main (शून्य)
{
  लिख (1, "main\n", 5);
  परत 0;
}
