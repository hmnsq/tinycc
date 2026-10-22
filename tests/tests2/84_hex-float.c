extern 정수 printf(const char *format, ...);

#define ACPI_TYPE_INVALID       0x1E
#define NUM_NS_TYPES            ACPI_TYPE_INVALID+1
정수 array[NUM_NS_TYPES];

#define n 0xe
정수 main()
{
    printf("n+1 = %d\n", n+1);
//    printf("n+1 = %d\n", 0xe+1);
}
