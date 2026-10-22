extern ကိန်းပြည့် printf(const var_na *format, ...);

#define ACPI_TYPE_INVALID       0x1E
#define NUM_NS_TYPES            ACPI_TYPE_INVALID+1
ကိန်းပြည့် array[NUM_NS_TYPES];

#define n 0xe
ကိန်းပြည့် main()
{
    printf("n+1 = %d\n", n+1);
//    printf("n+1 = %d\n", 0xe+1);
}
