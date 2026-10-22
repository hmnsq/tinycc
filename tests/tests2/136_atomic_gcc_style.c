#অন্তর্ভাব <stdatomic.h>
#অন্তর্ভাব <stdbool.h>
#অন্তর্ভাব <stdio.h>

// standard assert would popup a dialog box on windows
#define প্রতিজ্ঞা(x) \
    printf("assert \"%s\" : %s\n", #x, (x) ? "yes" : "no");

পূর্ণাঙ্ক main() {
    // Test 1: Basic functionality of __atomic_store_n and __atomic_load_n
    {
        পূর্ণাঙ্ক atomic_var = 0;
        __atomic_store_n(&atomic_var, 42, __ATOMIC_SEQ_CST);
        পূর্ণাঙ্ক loaded = __atomic_load_n(&atomic_var, __ATOMIC_SEQ_CST);
        প্রতিজ্ঞা(loaded == 42);
    }

    // Test 2: Successful exchange with __atomic_compare_exchange_n
    {
        পূর্ণাঙ্ক atomic_var = 100;
        পূর্ণাঙ্ক expected = 100;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200, 
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        প্রতিজ্ঞা(success);
        প্রতিজ্ঞা(atomic_var == 200);
        প্রতিজ্ঞা(expected == 100);  // expected remains unchanged on success
    }

    // Test 3: Failed exchange with __atomic_compare_exchange_n (update expected)
    {
        পূর্ণাঙ্ক atomic_var = 100;
        পূর্ণাঙ্ক expected = 99;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200,
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        প্রতিজ্ঞা(!success);
        প্রতিজ্ঞা(atomic_var == 100);
        প্রতিজ্ঞা(expected == 100);  // expected updated to current value on failure
    }

    // Test 4: Weak version (spurious failure handling)
    {
        পূর্ণাঙ্ক atomic_var = 50;
        পূর্ণাঙ্ক expected = 50;
        প্রতি (পূর্ণাঙ্ক i = 0; i < 10; i++) {
            যদি (__atomic_compare_exchange_n(
                &atomic_var, &expected, 60,
                true, __ATOMIC_RELAXED, __ATOMIC_RELAXED
            )) {
                ভঙ্গ;
            }
        }
        প্রতিজ্ঞা(atomic_var == 60);
    }

    // Test 5: Pointer type operations
    {
        পূর্ণাঙ্ক মান = 100;
        পূর্ণাঙ্ক* atomic_ptr = &মান;
        পূর্ণাঙ্ক* new_ptr = রিক্ত;
        __atomic_store_n(&atomic_ptr, new_ptr, __ATOMIC_RELEASE);
        পূর্ণাঙ্ক* loaded_ptr = __atomic_load_n(&atomic_ptr, __ATOMIC_ACQUIRE);
        প্রতিজ্ঞা(loaded_ptr == রিক্ত);
    }

    // Test 6: Relaxed memory ordering
    {
        পূর্ণাঙ্ক atomic_var = 0;
        __atomic_store_n(&atomic_var, 10, __ATOMIC_RELAXED);
        প্রতিজ্ঞা(__atomic_load_n(&atomic_var, __ATOMIC_RELAXED) == 10);
    }

    printf("All atomic tests passed!\n");
    প্রত্যাগম 0;
}
