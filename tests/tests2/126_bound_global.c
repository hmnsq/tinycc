/* test bound checking code without -run */

পূর্ণসংখ্যা arr[10];

পূর্ণসংখ্যা
প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv)
{
  পূর্ণসংখ্যা i;

  জন্য (i = 0; i <= আকার(arr)/আকার(arr[0]); i++)
        arr[i] = 0;
  ফেরত 0;
}
