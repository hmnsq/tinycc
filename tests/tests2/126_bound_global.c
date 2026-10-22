/* test bound checking code without -run */

পূর্ণাঙ্ক arr[10];

পূর্ণাঙ্ক
main(পূর্ণাঙ্ক argc, বর্ণ **argv)
{
  পূর্ণাঙ্ক i;

  প্রতি (i = 0; i <= পরিমাণ(arr)/পরিমাণ(arr[0]); i++)
        arr[i] = 0;
  প্রত্যাগম 0;
}
