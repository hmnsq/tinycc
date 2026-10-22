/* test bound checking code without -run */

पूर्णाङ्क arr[10];

पूर्णाङ्क
main(पूर्णाङ्क argc, वर्ण **argv)
{
  पूर्णाङ्क i;

  अत्थाय (i = 0; i <= परिमाण(arr)/परिमाण(arr[0]); i++)
        arr[i] = 0;
  पटिनिवत्त 0;
}
