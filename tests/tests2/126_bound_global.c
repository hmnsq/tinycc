/* test bound checking code without -run */

പൂർണ്ണസംഖ്യ arr[10];

പൂർണ്ണസംഖ്യ
പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
  പൂർണ്ണസംഖ്യ i;

  വേണ്ടി (i = 0; i <= വലുപ്പം(arr)/വലുപ്പം(arr[0]); i++)
        arr[i] = 0;
  തിരികെ 0;
}
