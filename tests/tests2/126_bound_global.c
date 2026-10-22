/* test bound checking code without -run */

целое arr[10];

целое
основной(целое argc, char **argv)
{
  целое i;

  для (i = 0; i <= sizeof(arr)/sizeof(arr[0]); i++)
        arr[i] = 0;
  вернуть 0;
}
