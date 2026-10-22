/* test bound checking code without -run */

صحیح arr[10];

صحیح
اصلی(صحیح argc, نویسه **argv)
{
  صحیح i;

  برای (i = 0; i <= اندازه(arr)/اندازه(arr[0]); i++)
        arr[i] = 0;
  بازگشت 0;
}
