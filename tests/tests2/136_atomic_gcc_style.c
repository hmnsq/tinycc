#અન્તર્ભાવ <stdatomic.h>
#અન્તર્ભાવ <stdbool.h>
#અન્તર્ભાવ <stdio.h>

// standard assert would popup a dialog box on windows
#define પ્રતિજ્ઞા(x) \
    printf("assert \"%s\" : %s\n", #x, (x) ? "yes" : "no");

પૂર્ણાંક મુખ્ય() {
    // Test 1: Basic functionality of __atomic_store_n and __atomic_load_n
    {
        પૂર્ણાંક atomic_var = 0;
        __atomic_store_n(&atomic_var, 42, __ATOMIC_SEQ_CST);
        પૂર્ણાંક loaded = __atomic_load_n(&atomic_var, __ATOMIC_SEQ_CST);
        પ્રતિજ્ઞા(loaded == 42);
    }

    // Test 2: Successful exchange with __atomic_compare_exchange_n
    {
        પૂર્ણાંક atomic_var = 100;
        પૂર્ણાંક expected = 100;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200, 
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        પ્રતિજ્ઞા(success);
        પ્રતિજ્ઞા(atomic_var == 200);
        પ્રતિજ્ઞા(expected == 100);  // expected remains unchanged on success
    }

    // Test 3: Failed exchange with __atomic_compare_exchange_n (update expected)
    {
        પૂર્ણાંક atomic_var = 100;
        પૂર્ણાંક expected = 99;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200,
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        પ્રતિજ્ઞા(!success);
        પ્રતિજ્ઞા(atomic_var == 100);
        પ્રતિજ્ઞા(expected == 100);  // expected updated to current value on failure
    }

    // Test 4: Weak version (spurious failure handling)
    {
        પૂર્ણાંક atomic_var = 50;
        પૂર્ણાંક expected = 50;
        માટે (પૂર્ણાંક i = 0; i < 10; i++) {
            જો (__atomic_compare_exchange_n(
                &atomic_var, &expected, 60,
                true, __ATOMIC_RELAXED, __ATOMIC_RELAXED
            )) {
                તોડો;
            }
        }
        પ્રતિજ્ઞા(atomic_var == 60);
    }

    // Test 5: Pointer type operations
    {
        પૂર્ણાંક કિંમત = 100;
        પૂર્ણાંક* atomic_ptr = &કિંમત;
        પૂર્ણાંક* new_ptr = ખાલી;
        __atomic_store_n(&atomic_ptr, new_ptr, __ATOMIC_RELEASE);
        પૂર્ણાંક* loaded_ptr = __atomic_load_n(&atomic_ptr, __ATOMIC_ACQUIRE);
        પ્રતિજ્ઞા(loaded_ptr == ખાલી);
    }

    // Test 6: Relaxed memory ordering
    {
        પૂર્ણાંક atomic_var = 0;
        __atomic_store_n(&atomic_var, 10, __ATOMIC_RELAXED);
        પ્રતિજ્ઞા(__atomic_load_n(&atomic_var, __ATOMIC_RELAXED) == 10);
    }

    printf("All atomic tests passed!\n");
    પાછા 0;
}
