#అన్తర్భావ <stdatomic.h>
#అన్తర్భావ <stdbool.h>
#అన్తర్భావ <stdio.h>

// standard assert would popup a dialog box on windows
#నిర్వచించు ప్రతిజ్ఞా(x) \
    రాయి("assert \"%s\" : %s\n", #x, (x) ? "yes" : "no");

పూర్ణాంకం ప్రధాన() {
    // Test 1: Basic functionality of __atomic_store_n and __atomic_load_n
    {
        పూర్ణాంకం atomic_var = 0;
        __atomic_store_n(&atomic_var, 42, __ATOMIC_SEQ_CST);
        పూర్ణాంకం loaded = __atomic_load_n(&atomic_var, __ATOMIC_SEQ_CST);
        ప్రతిజ్ఞా(loaded == 42);
    }

    // Test 2: Successful exchange with __atomic_compare_exchange_n
    {
        పూర్ణాంకం atomic_var = 100;
        పూర్ణాంకం expected = 100;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200, 
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        ప్రతిజ్ఞా(success);
        ప్రతిజ్ఞా(atomic_var == 200);
        ప్రతిజ్ఞా(expected == 100);  // expected remains unchanged on success
    }

    // Test 3: Failed exchange with __atomic_compare_exchange_n (update expected)
    {
        పూర్ణాంకం atomic_var = 100;
        పూర్ణాంకం expected = 99;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200,
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        ప్రతిజ్ఞా(!success);
        ప్రతిజ్ఞా(atomic_var == 100);
        ప్రతిజ్ఞా(expected == 100);  // expected updated to current value on failure
    }

    // Test 4: Weak version (spurious failure handling)
    {
        పూర్ణాంకం atomic_var = 50;
        పూర్ణాంకం expected = 50;
        కొరకు (పూర్ణాంకం i = 0; i < 10; i++) {
            ఒకవేళ (__atomic_compare_exchange_n(
                &atomic_var, &expected, 60,
                true, __ATOMIC_RELAXED, __ATOMIC_RELAXED
            )) {
                ఆపు;
            }
        }
        ప్రతిజ్ఞా(atomic_var == 60);
    }

    // Test 5: Pointer type operations
    {
        పూర్ణాంకం విలువ = 100;
        పూర్ణాంకం* atomic_ptr = &విలువ;
        పూర్ణాంకం* new_ptr = ఖాళీ;
        __atomic_store_n(&atomic_ptr, new_ptr, __ATOMIC_RELEASE);
        పూర్ణాంకం* loaded_ptr = __atomic_load_n(&atomic_ptr, __ATOMIC_ACQUIRE);
        ప్రతిజ్ఞా(loaded_ptr == ఖాళీ);
    }

    // Test 6: Relaxed memory ordering
    {
        పూర్ణాంకం atomic_var = 0;
        __atomic_store_n(&atomic_var, 10, __ATOMIC_RELAXED);
        ప్రతిజ్ఞా(__atomic_load_n(&atomic_var, __ATOMIC_RELAXED) == 10);
    }

    రాయి("All atomic tests passed!\n");
    తిరిగి 0;
}
