#समावेश <stdatomic.h>
#समावेश <stdbool.h>
#समावेश <stdio.h>

// standard assert would popup a dialog box on windows
#घोषणा निश्चित(x) \
    म_लिखो("assert \"%s\" : %s\n", #x, (x) ? "yes" : "no");

पूर्णांक मुख्य() {
    // Test 1: Basic functionality of __atomic_store_n and __atomic_load_n
    {
        पूर्णांक atomic_var = 0;
        __atomic_store_n(&atomic_var, 42, __ATOMIC_SEQ_CST);
        पूर्णांक loaded = __atomic_load_n(&atomic_var, __ATOMIC_SEQ_CST);
        निश्चित(loaded == 42);
    }

    // Test 2: Successful exchange with __atomic_compare_exchange_n
    {
        पूर्णांक atomic_var = 100;
        पूर्णांक expected = 100;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200, 
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        निश्चित(success);
        निश्चित(atomic_var == 200);
        निश्चित(expected == 100);  // expected remains unchanged on success
    }

    // Test 3: Failed exchange with __atomic_compare_exchange_n (update expected)
    {
        पूर्णांक atomic_var = 100;
        पूर्णांक expected = 99;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200,
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        निश्चित(!success);
        निश्चित(atomic_var == 100);
        निश्चित(expected == 100);  // expected updated to current value on failure
    }

    // Test 4: Weak version (spurious failure handling)
    {
        पूर्णांक atomic_var = 50;
        पूर्णांक expected = 50;
        क्रम (पूर्णांक i = 0; i < 10; i++) {
            अगर (__atomic_compare_exchange_n(
                &atomic_var, &expected, 60,
                true, __ATOMIC_RELAXED, __ATOMIC_RELAXED
            )) {
                अवरोध;
            }
        }
        निश्चित(atomic_var == 60);
    }

    // Test 5: Pointer type operations
    {
        पूर्णांक मूल्य = 100;
        पूर्णांक* atomic_ptr = &मूल्य;
        पूर्णांक* new_ptr = शून्य;
        __atomic_store_n(&atomic_ptr, new_ptr, __ATOMIC_RELEASE);
        पूर्णांक* loaded_ptr = __atomic_load_n(&atomic_ptr, __ATOMIC_ACQUIRE);
        निश्चित(loaded_ptr == शून्य);
    }

    // Test 6: Relaxed memory ordering
    {
        पूर्णांक atomic_var = 0;
        __atomic_store_n(&atomic_var, 10, __ATOMIC_RELAXED);
        निश्चित(__atomic_load_n(&atomic_var, __ATOMIC_RELAXED) == 10);
    }

    म_लिखो("All atomic tests passed!\n");
    वापस 0;
}
