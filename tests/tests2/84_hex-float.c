extern int printf(const char *format, ...);

#define ACPI_TYPE_INVALID       0x1E
#define नुमेरो_NS_TYPES            ACPI_TYPE_INVALID+1
int array[नुमेरो_NS_TYPES];

#define n 0xe
int main()
{
    printf("n+1 = %d\n", n+1);
//    printf("n+1 = %d\n", 0xe+1);
}
