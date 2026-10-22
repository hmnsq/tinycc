/* test bound checking code without -run */

ପୂର୍ଣ୍ଣସଂଖ୍ୟା arr[10];

ପୂର୍ଣ୍ଣସଂଖ୍ୟା
ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

  ପାଇଁ (i = 0; i <= ଆକାର(arr)/ଆକାର(arr[0]); i++)
        arr[i] = 0;
  ଫେରନ୍ତୁ 0;
}
