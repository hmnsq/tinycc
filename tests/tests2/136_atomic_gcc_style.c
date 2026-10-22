#include <stdatomic.h>
#include <stdbool.h>
#include <stdio.h>

// standard assert would popup a dialog box on windows
#define assert(x) \
    printf("assert \"%s\" : %s\n", #x, (x) ? "yes" : "no");

цео main() {
    // Test 1: Basic functionality of __atomic_store_n and __atomic_load_n
    {
        цео atomic_var = 0;
        __atomic_store_n(&atomic_var, 42, __ATOMIC_SEQ_CST);
        цео loaded = __atomic_load_n(&atomic_var, __ATOMIC_SEQ_CST);
        assert(loaded == 42);
    }

    // Test 2: Successful exchange with __atomic_compare_exchange_n
    {
        цео atomic_var = 100;
        цео expected = 100;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200, 
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        assert(success);
        assert(atomic_var == 200);
        assert(expected == 100);  // expected remains unchanged on success
    }

    // Test 3: Failed exchange with __atomic_compare_exchange_n (update expected)
    {
        цео atomic_var = 100;
        цео expected = 99;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200,
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        assert(!success);
        assert(atomic_var == 100);
        assert(expected == 100);  // expected updated to current value on failure
    }

    // Test 4: Weak version (spurious failure handling)
    {
        цео atomic_var = 50;
        цео expected = 50;
        за (цео i = 0; i < 10; i++) {
            ако (__atomic_compare_exchange_n(
                &atomic_var, &expected, 60,
                true, __ATOMIC_RELAXED, __ATOMIC_RELAXED
            )) {
                break;
            }
        }
        assert(atomic_var == 60);
    }

    // Test 5: Pointer type operations
    {
        цео value = 100;
        цео* atomic_ptr = &value;
        цео* new_ptr = NULL;
        __atomic_store_n(&atomic_ptr, new_ptr, __ATOMIC_RELEASE);
        цео* loaded_ptr = __atomic_load_n(&atomic_ptr, __ATOMIC_ACQUIRE);
        assert(loaded_ptr == NULL);
    }

    // Test 6: Relaxed memory ordering
    {
        цео atomic_var = 0;
        __atomic_store_n(&atomic_var, 10, __ATOMIC_RELAXED);
        assert(__atomic_load_n(&atomic_var, __ATOMIC_RELAXED) == 10);
    }

    printf("All atomic tests passed!\n");
    врати 0;
}
