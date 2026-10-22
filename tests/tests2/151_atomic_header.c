#अन्तर्भाव <stdatomic.h>
#अन्तर्भाव <stdio.h>

स्थिर पूर्णाङ्क मानम्_calls;
स्थिर पूर्णाङ्क क्रमः_calls;

स्थिर पूर्णाङ्क अग्र_मानम्(शून्य)
{
    ++मानम्_calls;
    प्रत्यागम 42;
}

स्थिर पूर्णाङ्क अग्र_क्रमः(शून्य)
{
    ++क्रमः_calls;
    प्रत्यागम __ATOMIC_SEQ_CST;
}

पूर्णाङ्क मुख्यम्(शून्य)
{
    पूर्णाङ्क मानानि[2] = {7, 8};
    पूर्णाङ्क सूचकांक = 0;
    पूर्णाङ्क मानम् = 1;
    चञ्चल पूर्णाङ्क vol = 0;
    पूर्णाङ्क *pointer = &मानम्;
    शून्य (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&मानानि[सूचकांक++], अग्र_मानम्(), अग्र_क्रमः());
    प्रारूप_लिख("%d %d %d %d %d\n", सूचकांक, मानम्_calls, क्रमः_calls,
           मानानि[0], मानानि[1]);
    __atomic_store_n(&मानम्, मानम् + 1, __ATOMIC_RELAXED);
    प्रारूप_लिख("%d\n", मानम्);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    प्रारूप_लिख("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &मानानि[0], __ATOMIC_RELEASE);
    प्रारूप_लिख("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(स्मृतिः_क्रमः_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(स्मृतिः_क्रमः_seq_cst);
    atomic_thread_fence(स्मृतिः_क्रमः_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    पङ्क्तिं_लिख("ok");
    प्रत्यागम 0;
}
