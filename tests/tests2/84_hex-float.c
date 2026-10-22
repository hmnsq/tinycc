बाह्य पूर्णांक म_लिखो(स्थिर अक्षर *format, ...);

#घोषणा ACPI_TYPE_INVALID       0x1E
#घोषणा अंक_NS_TYPES            ACPI_TYPE_INVALID+1
पूर्णांक array[अंक_NS_TYPES];

#घोषणा n 0xe
पूर्णांक मुख्य()
{
    म_लिखो("n+1 = %d\n", n+1);
//    printf("n+1 = %d\n", 0xe+1);
}
