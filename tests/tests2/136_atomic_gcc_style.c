#ਅਨ੍ਤਰ੍ਭਾਵ <stdatomic.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdbool.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

// standard assert would popup a dialog box on windows
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪ੍ਰਤਿਜ੍ਞਾ(x) \
    ਲਿਖੋ("assert \"%s\" : %s\n", #x, (x) ? "yes" : "no");

ਪੂਰਨ ਮੁੱਖ() {
    // Test 1: Basic functionality of __atomic_store_n and __atomic_load_n
    {
        ਪੂਰਨ atomic_var = 0;
        __atomic_store_n(&atomic_var, 42, __ATOMIC_SEQ_CST);
        ਪੂਰਨ loaded = __atomic_load_n(&atomic_var, __ATOMIC_SEQ_CST);
        ਪ੍ਰਤਿਜ੍ਞਾ(loaded == 42);
    }

    // Test 2: Successful exchange with __atomic_compare_exchange_n
    {
        ਪੂਰਨ atomic_var = 100;
        ਪੂਰਨ expected = 100;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200, 
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        ਪ੍ਰਤਿਜ੍ਞਾ(success);
        ਪ੍ਰਤਿਜ੍ਞਾ(atomic_var == 200);
        ਪ੍ਰਤਿਜ੍ਞਾ(expected == 100);  // expected remains unchanged on success
    }

    // Test 3: Failed exchange with __atomic_compare_exchange_n (update expected)
    {
        ਪੂਰਨ atomic_var = 100;
        ਪੂਰਨ expected = 99;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200,
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        ਪ੍ਰਤਿਜ੍ਞਾ(!success);
        ਪ੍ਰਤਿਜ੍ਞਾ(atomic_var == 100);
        ਪ੍ਰਤਿਜ੍ਞਾ(expected == 100);  // expected updated to current value on failure
    }

    // Test 4: Weak version (spurious failure handling)
    {
        ਪੂਰਨ atomic_var = 50;
        ਪੂਰਨ expected = 50;
        ਲਈ (ਪੂਰਨ i = 0; i < 10; i++) {
            ਜੇ (__atomic_compare_exchange_n(
                &atomic_var, &expected, 60,
                true, __ATOMIC_RELAXED, __ATOMIC_RELAXED
            )) {
                ਰੋਕੋ;
            }
        }
        ਪ੍ਰਤਿਜ੍ਞਾ(atomic_var == 60);
    }

    // Test 5: Pointer type operations
    {
        ਪੂਰਨ ਮੁੱਲ = 100;
        ਪੂਰਨ* atomic_ptr = &ਮੁੱਲ;
        ਪੂਰਨ* new_ptr = ਨਿਰਾ;
        __atomic_store_n(&atomic_ptr, new_ptr, __ATOMIC_RELEASE);
        ਪੂਰਨ* loaded_ptr = __atomic_load_n(&atomic_ptr, __ATOMIC_ACQUIRE);
        ਪ੍ਰਤਿਜ੍ਞਾ(loaded_ptr == ਨਿਰਾ);
    }

    // Test 6: Relaxed memory ordering
    {
        ਪੂਰਨ atomic_var = 0;
        __atomic_store_n(&atomic_var, 10, __ATOMIC_RELAXED);
        ਪ੍ਰਤਿਜ੍ਞਾ(__atomic_load_n(&atomic_var, __ATOMIC_RELAXED) == 10);
    }

    ਲਿਖੋ("All atomic tests passed!\n");
    ਵਾਪਸ 0;
}
