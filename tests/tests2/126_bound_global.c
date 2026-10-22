/* test bound checking code without -run */

पूर्णाङ्क arr[10];

पूर्णाङ्क
मुख्यम्(पूर्णाङ्क argc, वर्ण **argv)
{
  पूर्णाङ्क i;

  प्रति (i = 0; i <= परिमाण(arr)/परिमाण(arr[0]); i++)
        arr[i] = 0;
  प्रत्यागम 0;
}
