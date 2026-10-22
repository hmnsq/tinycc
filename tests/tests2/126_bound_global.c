/* test bound checking code without -run */

ਪੂਰਨ arr[10];

ਪੂਰਨ
ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
  ਪੂਰਨ i;

  ਲਈ (i = 0; i <= ਆਕਾਰ(arr)/ਆਕਾਰ(arr[0]); i++)
        arr[i] = 0;
  ਵਾਪਸ 0;
}
