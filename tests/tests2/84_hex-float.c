extern puur_naa_nka printf(const var_na *format, ...);

#define ACPI_TYPE_INVALID       0x1E
#define NUM_NS_TYPES            ACPI_TYPE_INVALID+1
puur_naa_nka array[NUM_NS_TYPES];

#define n 0xe
puur_naa_nka main()
{
    printf("n+1 = %d\n", n+1);
//    printf("n+1 = %d\n", 0xe+1);
}
