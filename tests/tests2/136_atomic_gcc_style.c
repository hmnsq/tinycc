#अन्तर्भाव <stdatomic.h>
#अन्तर्भाव <stdbool.h>
#अन्तर्भाव <stdio.h>

// standard assert would popup a dialog box on windows
#define प्रतिज्ञा(x) \
    printf("assert \"%s\" : %s\n", #x, (x) ? "yes" : "no");

पूर्णाङ्क main() {
    // Test 1: Basic functionality of __atomic_store_n and __atomic_load_n
    {
        पूर्णाङ्क atomic_var = 0;
        __atomic_store_n(&atomic_var, 42, __ATOMIC_SEQ_CST);
        पूर्णाङ्क loaded = __atomic_load_n(&atomic_var, __ATOMIC_SEQ_CST);
        प्रतिज्ञा(loaded == 42);
    }

    // Test 2: Successful exchange with __atomic_compare_exchange_n
    {
        पूर्णाङ्क atomic_var = 100;
        पूर्णाङ्क expected = 100;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200, 
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        प्रतिज्ञा(success);
        प्रतिज्ञा(atomic_var == 200);
        प्रतिज्ञा(expected == 100);  // expected remains unchanged on success
    }

    // Test 3: Failed exchange with __atomic_compare_exchange_n (update expected)
    {
        पूर्णाङ्क atomic_var = 100;
        पूर्णाङ्क expected = 99;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200,
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        प्रतिज्ञा(!success);
        प्रतिज्ञा(atomic_var == 100);
        प्रतिज्ञा(expected == 100);  // expected updated to current value on failure
    }

    // Test 4: Weak version (spurious failure handling)
    {
        पूर्णाङ्क atomic_var = 50;
        पूर्णाङ्क expected = 50;
        प्रति (पूर्णाङ्क i = 0; i < 10; i++) {
            यदि (__atomic_compare_exchange_n(
                &atomic_var, &expected, 60,
                true, __ATOMIC_RELAXED, __ATOMIC_RELAXED
            )) {
                भङ्ग;
            }
        }
        प्रतिज्ञा(atomic_var == 60);
    }

    // Test 5: Pointer type operations
    {
        पूर्णाङ्क मूल्य = 100;
        पूर्णाङ्क* atomic_ptr = &मूल्य;
        पूर्णाङ्क* new_ptr = रिक्त;
        __atomic_store_n(&atomic_ptr, new_ptr, __ATOMIC_RELEASE);
        पूर्णाङ्क* loaded_ptr = __atomic_load_n(&atomic_ptr, __ATOMIC_ACQUIRE);
        प्रतिज्ञा(loaded_ptr == रिक्त);
    }

    // Test 6: Relaxed memory ordering
    {
        पूर्णाङ्क atomic_var = 0;
        __atomic_store_n(&atomic_var, 10, __ATOMIC_RELAXED);
        प्रतिज्ञा(__atomic_load_n(&atomic_var, __ATOMIC_RELAXED) == 10);
    }

    printf("All atomic tests passed!\n");
    प्रत्यागम 0;
}
