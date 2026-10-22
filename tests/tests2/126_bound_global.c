/* test bound checking code without -run */

整数 arr[10];

整数
メインページ(整数 argc, char **argv)
{
  整数 i;

  ために (i = 0; i <= sizeof(arr)/sizeof(arr[0]); i++)
        arr[i] = 0;
  戻る 0;
}
