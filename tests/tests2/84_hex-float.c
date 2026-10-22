बाह्य पूर्णाङ्क प्रारूप_लिख(ध्रुव वर्ण *format, ...);

#परिभाषय ACPI_TYPE_INVALID       0x1E
#परिभाषय अङ्कः_NS_TYPES            ACPI_TYPE_INVALID+1
पूर्णाङ्क array[अङ्कः_NS_TYPES];

#परिभाषय n 0xe
पूर्णाङ्क मुख्यम्()
{
    प्रारूप_लिख("n+1 = %d\n", n+1);
//    printf("n+1 = %d\n", 0xe+1);
}
