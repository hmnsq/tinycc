#அந்தர்பாவ <stdatomic.h>
#அந்தர்பாவ <stdbool.h>
#அந்தர்பாவ <stdio.h>

// standard assert would popup a dialog box on windows
#define ப்ரதிஜ்ஞா(x) \
    printf("assert \"%s\" : %s\n", #x, (x) ? "yes" : "no");

முழு முதன்மை() {
    // Test 1: Basic functionality of __atomic_store_n and __atomic_load_n
    {
        முழு atomic_var = 0;
        __atomic_store_n(&atomic_var, 42, __ATOMIC_SEQ_CST);
        முழு loaded = __atomic_load_n(&atomic_var, __ATOMIC_SEQ_CST);
        ப்ரதிஜ்ஞா(loaded == 42);
    }

    // Test 2: Successful exchange with __atomic_compare_exchange_n
    {
        முழு atomic_var = 100;
        முழு expected = 100;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200, 
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        ப்ரதிஜ்ஞா(success);
        ப்ரதிஜ்ஞா(atomic_var == 200);
        ப்ரதிஜ்ஞா(expected == 100);  // expected remains unchanged on success
    }

    // Test 3: Failed exchange with __atomic_compare_exchange_n (update expected)
    {
        முழு atomic_var = 100;
        முழு expected = 99;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200,
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        ப்ரதிஜ்ஞா(!success);
        ப்ரதிஜ்ஞா(atomic_var == 100);
        ப்ரதிஜ்ஞா(expected == 100);  // expected updated to current value on failure
    }

    // Test 4: Weak version (spurious failure handling)
    {
        முழு atomic_var = 50;
        முழு expected = 50;
        க்கு (முழு i = 0; i < 10; i++) {
            எனில் (__atomic_compare_exchange_n(
                &atomic_var, &expected, 60,
                true, __ATOMIC_RELAXED, __ATOMIC_RELAXED
            )) {
                நிறுத்து;
            }
        }
        ப்ரதிஜ்ஞா(atomic_var == 60);
    }

    // Test 5: Pointer type operations
    {
        முழு மதிப்பு = 100;
        முழு* atomic_ptr = &மதிப்பு;
        முழு* new_ptr = வெற்று;
        __atomic_store_n(&atomic_ptr, new_ptr, __ATOMIC_RELEASE);
        முழு* loaded_ptr = __atomic_load_n(&atomic_ptr, __ATOMIC_ACQUIRE);
        ப்ரதிஜ்ஞா(loaded_ptr == வெற்று);
    }

    // Test 6: Relaxed memory ordering
    {
        முழு atomic_var = 0;
        __atomic_store_n(&atomic_var, 10, __ATOMIC_RELAXED);
        ப்ரதிஜ்ஞா(__atomic_load_n(&atomic_var, __ATOMIC_RELAXED) == 10);
    }

    printf("All atomic tests passed!\n");
    திரும்பு 0;
}
