#ಅನ್ತರ್ಭಾವ <stdatomic.h>
#ಅನ್ತರ್ಭಾವ <stdbool.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>

// standard assert would popup a dialog box on windows
#define ಪ್ರತಿಜ್ಞಾ(x) \
    printf("assert \"%s\" : %s\n", #x, (x) ? "yes" : "no");

ಪೂರ್ಣಾಙ್ಕ main() {
    // Test 1: Basic functionality of __atomic_store_n and __atomic_load_n
    {
        ಪೂರ್ಣಾಙ್ಕ atomic_var = 0;
        __atomic_store_n(&atomic_var, 42, __ATOMIC_SEQ_CST);
        ಪೂರ್ಣಾಙ್ಕ loaded = __atomic_load_n(&atomic_var, __ATOMIC_SEQ_CST);
        ಪ್ರತಿಜ್ಞಾ(loaded == 42);
    }

    // Test 2: Successful exchange with __atomic_compare_exchange_n
    {
        ಪೂರ್ಣಾಙ್ಕ atomic_var = 100;
        ಪೂರ್ಣಾಙ್ಕ expected = 100;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200, 
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        ಪ್ರತಿಜ್ಞಾ(success);
        ಪ್ರತಿಜ್ಞಾ(atomic_var == 200);
        ಪ್ರತಿಜ್ಞಾ(expected == 100);  // expected remains unchanged on success
    }

    // Test 3: Failed exchange with __atomic_compare_exchange_n (update expected)
    {
        ಪೂರ್ಣಾಙ್ಕ atomic_var = 100;
        ಪೂರ್ಣಾಙ್ಕ expected = 99;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200,
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        ಪ್ರತಿಜ್ಞಾ(!success);
        ಪ್ರತಿಜ್ಞಾ(atomic_var == 100);
        ಪ್ರತಿಜ್ಞಾ(expected == 100);  // expected updated to current value on failure
    }

    // Test 4: Weak version (spurious failure handling)
    {
        ಪೂರ್ಣಾಙ್ಕ atomic_var = 50;
        ಪೂರ್ಣಾಙ್ಕ expected = 50;
        ಪ್ರತಿ (ಪೂರ್ಣಾಙ್ಕ i = 0; i < 10; i++) {
            ಯದಿ (__atomic_compare_exchange_n(
                &atomic_var, &expected, 60,
                true, __ATOMIC_RELAXED, __ATOMIC_RELAXED
            )) {
                ಭಙ್ಗ;
            }
        }
        ಪ್ರತಿಜ್ಞಾ(atomic_var == 60);
    }

    // Test 5: Pointer type operations
    {
        ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ = 100;
        ಪೂರ್ಣಾಙ್ಕ* atomic_ptr = &ಮೌಲ್ಯ;
        ಪೂರ್ಣಾಙ್ಕ* new_ptr = ರಿಕ್ತ;
        __atomic_store_n(&atomic_ptr, new_ptr, __ATOMIC_RELEASE);
        ಪೂರ್ಣಾಙ್ಕ* loaded_ptr = __atomic_load_n(&atomic_ptr, __ATOMIC_ACQUIRE);
        ಪ್ರತಿಜ್ಞಾ(loaded_ptr == ರಿಕ್ತ);
    }

    // Test 6: Relaxed memory ordering
    {
        ಪೂರ್ಣಾಙ್ಕ atomic_var = 0;
        __atomic_store_n(&atomic_var, 10, __ATOMIC_RELAXED);
        ಪ್ರತಿಜ್ಞಾ(__atomic_load_n(&atomic_var, __ATOMIC_RELAXED) == 10);
    }

    printf("All atomic tests passed!\n");
    ಪ್ರತ್ಯಾಗಮ 0;
}
