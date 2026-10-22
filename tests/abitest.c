#ಅನ್ತರ್ಭಾವ <libtcc.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ <stdarg.h>

// MinGW has 80-bit rather than 64-bit long double which isn't compatible with TCC or MSVC
#ಯದಿ defined(_WIN32) && defined(__GNUC__)
#define LONG_DOUBLE ದ್ವಿಗುಣ
#define LONG_DOUBLE_LITERAL(x) x
#ಅನ್ಯಥಾ
#define LONG_DOUBLE long ದ್ವಿಗುಣ
#define LONG_DOUBLE_LITERAL(x) x ## L
#endif

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ g_argc;
ಸ್ಥಿರ ವರ್ಣ **g_argv;

ಸ್ಥಿರ ಶೂನ್ಯ set_options(TCCState *s, ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ (i = 1; i < argc; ++i) {
        ವರ್ಣ *a = argv[i];
        ಯದಿ (a[0] == '-') {
            ಯದಿ (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            ಅನ್ಯಥಾ ಯದಿ (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            ಅನ್ಯಥಾ ಯದಿ (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ (*callback_type) (ಶೂನ್ಯ*);

/*
 * Compile source code and call a callback with a pointer to the symbol "f".
 */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ run_callback(ಧ್ರುವ ವರ್ಣ *src, callback_type callback) {
  TCCState *s;
  ಪೂರ್ಣಾಙ್ಕ result;
  ಶೂನ್ಯ *ptr;
  
  s = tcc_new();
  ಯದಿ (!s)
    ಪ್ರತ್ಯಾಗಮ -1;

  set_options(s, g_argc, g_argv);

  ಯದಿ (tcc_set_output_type(s, TCC_OUTPUT_MEMORY) == -1)
    ಪ್ರತ್ಯಾಗಮ -1;
  ಯದಿ (tcc_compile_string(s, src) == -1)
    ಪ್ರತ್ಯಾಗಮ -1;
  ಯದಿ (tcc_relocate(s) == -1)
    ಪ್ರತ್ಯಾಗಮ -1;
  
  ptr = tcc_get_ಚಿಹ್ನೆ(s, "f");
  ಯದಿ (!ptr)
    ಪ್ರತ್ಯಾಗಮ -1;
  result = callback(ptr);
  
  tcc_delete(s);
  
  ಪ್ರತ್ಯಾಗಮ result;
}

#define STR2(x) #x
#define STR(x) STR2(x)

#define RET_PRIMITIVE_TEST(name, type, val) \
  ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_ ## name ## _test_callback(ಶೂನ್ಯ *ptr) { \
    type (*callback) (type) = (type(*)(type))ptr; \
    type x = val; \
    type y = callback(x); \
    ಪ್ರತ್ಯಾಗಮ (y == x+x) ? 0 : -1; \
  } \
  \
  ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_ ## name ## _test(ಶೂನ್ಯ) { \
    ಧ್ರುವ ವರ್ಣ *src = STR(type) " f(" STR(type) " x) {return x+x;}"; \
    ಪ್ರತ್ಯಾಗಮ run_callback(src, ret_ ## name ## _test_callback); \
  }

RET_PRIMITIVE_TEST(ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ, 70000)
RET_PRIMITIVE_TEST(longlong, long long, 4333369356528LL)
RET_PRIMITIVE_TEST(ಭಿನ್ನ, ಭಿನ್ನ, 63.0)
RET_PRIMITIVE_TEST(ದ್ವಿಗುಣ, ದ್ವಿಗುಣ, 14789798.0)
RET_PRIMITIVE_TEST(longdouble, LONG_DOUBLE, LONG_DOUBLE_LITERAL(378943892.0))

/*
 * ret_2float_test:
 * 
 * On x86-64, a struct with 2 floats should be packed into a single
 * SSE register (VT_DOUBLE is used for this purpose).
 */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ ret_2float_test_type_s {ಭಿನ್ನ x, y;} ret_2float_test_type;
ಪ್ರಕಾರನಿರ್ದೇಶ ret_2float_test_type (*ret_2float_test_function_type) (ret_2float_test_type);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_2float_test_callback(ಶೂನ್ಯ *ptr) {
  ret_2float_test_function_type f = (ret_2float_test_function_type)ptr;
  ret_2float_test_type a = {10, 35};
  ret_2float_test_type r;
  r = f(a);
  ಪ್ರತ್ಯಾಗಮ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_2float_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef struct ret_2float_test_type_s {float x, y;} ret_2float_test_type;"
  "ret_2float_test_type f(ret_2float_test_type a) {\n"
  "  ret_2float_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  ಪ್ರತ್ಯಾಗಮ run_callback(src, ret_2float_test_callback);
}

/*
 * ret_2double_test:
 * 
 * On x86-64, a struct with 2 doubles should be passed in two SSE
 * registers.
 */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ ret_2double_test_type_s {ದ್ವಿಗುಣ x, y;} ret_2double_test_type;
ಪ್ರಕಾರನಿರ್ದೇಶ ret_2double_test_type (*ret_2double_test_function_type) (ret_2double_test_type);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_2double_test_callback(ಶೂನ್ಯ *ptr) {
  ret_2double_test_function_type f = (ret_2double_test_function_type)ptr;
  ret_2double_test_type a = {10, 35};
  ret_2double_test_type r;
  r = f(a);
  ಪ್ರತ್ಯಾಗಮ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_2double_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef struct ret_2double_test_type_s {double x, y;} ret_2double_test_type;"
  "ret_2double_test_type f(ret_2double_test_type a) {\n"
  "  ret_2double_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  ಪ್ರತ್ಯಾಗಮ run_callback(src, ret_2double_test_callback);
}

/*
 * ret_8plus2double_test:
 *
 * This catches a corner case in the x86_64 ABI code: the first 7
 * arguments fit into registers, the 8th doesn't, but the 9th argument
 * fits into the 8th XMM register.
 *
 * Note that the purpose of the 10th argument is to avoid a situation
 * in which gcc would accidentally put the double at the right
 * address, thus causing a success message even though TCC actually
 * generated incorrect code.
 */
ಪ್ರಕಾರನಿರ್ದೇಶ ret_2double_test_type (*ret_8plus2double_test_function_type) (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ, ದ್ವಿಗುಣ, ದ್ವಿಗುಣ, ದ್ವಿಗುಣ, ದ್ವಿಗುಣ, ದ್ವಿಗುಣ, ret_2double_test_type, ದ್ವಿಗುಣ, ದ್ವಿಗುಣ);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_8plus2double_test_callback(ಶೂನ್ಯ *ptr) {
  ret_8plus2double_test_function_type f = (ret_8plus2double_test_function_type)ptr;
  ret_2double_test_type a = {10, 35};
  ret_2double_test_type r;
  r = f(0, 0, 0, 0, 0, 0, 0, a, 37, 38);
  ಪ್ರತ್ಯಾಗಮ ((r.x == 37) && (r.y == 37)) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_8plus2double_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef struct ret_2double_test_type_s {double x, y;} ret_2double_test_type;"
  "ret_2double_test_type f(double x1, double x2, double x3, double x4, double x5, double x6, double x7, ret_2double_test_type a, double x8, double x9) {\n"
  "  ret_2double_test_type r = { x8, x8 };\n"
  "  return r;\n"
  "}\n";

  ಪ್ರತ್ಯಾಗಮ run_callback(src, ret_8plus2double_test_callback);
}

/*
 * ret_mixed_test:
 *
 * On x86-64, a struct with a double and a 64-bit integer should be
 * passed in one SSE register and one integer register.
 */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ ret_mixed_test_type_s {ದ್ವಿಗುಣ x; long long y;} ret_mixed_test_type;
ಪ್ರಕಾರನಿರ್ದೇಶ ret_mixed_test_type (*ret_mixed_test_function_type) (ret_mixed_test_type);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_mixed_test_callback(ಶೂನ್ಯ *ptr) {
  ret_mixed_test_function_type f = (ret_mixed_test_function_type)ptr;
  ret_mixed_test_type a = {10, 35};
  ret_mixed_test_type r;
  r = f(a);
  ಪ್ರತ್ಯಾಗಮ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_mixed_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef struct ret_mixed_test_type_s {double x; long long y;} ret_mixed_test_type;"
  "ret_mixed_test_type f(ret_mixed_test_type a) {\n"
  "  ret_mixed_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  ಪ್ರತ್ಯಾಗಮ run_callback(src, ret_mixed_test_callback);
}

/*
 * ret_mixed2_test:
 *
 * On x86-64, a struct with two floats and two 32-bit integers should
 * be passed in one SSE register and one integer register.
 */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ ret_mixed2_test_type_s {ಭಿನ್ನ x,x2; ಪೂರ್ಣಾಙ್ಕ y,y2;} ret_mixed2_test_type;
ಪ್ರಕಾರನಿರ್ದೇಶ ret_mixed2_test_type (*ret_mixed2_test_function_type) (ret_mixed2_test_type);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_mixed2_test_callback(ಶೂನ್ಯ *ptr) {
  ret_mixed2_test_function_type f = (ret_mixed2_test_function_type)ptr;
  ret_mixed2_test_type a = {10, 5, 35, 7 };
  ret_mixed2_test_type r;
  r = f(a);
  ಪ್ರತ್ಯಾಗಮ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_mixed2_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef struct ret_mixed2_test_type_s {float x, x2; int y,y2;} ret_mixed2_test_type;"
  "ret_mixed2_test_type f(ret_mixed2_test_type a) {\n"
  "  ret_mixed2_test_type r = {a.x*5, 0, a.y*3, 0};\n"
  "  return r;\n"
  "}\n";

  ಪ್ರತ್ಯಾಗಮ run_callback(src, ret_mixed2_test_callback);
}

/*
 * ret_mixed3_test:
 *
 * On x86-64, this struct should be passed in two integer registers.
 */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ ret_mixed3_test_type_s {ಭಿನ್ನ x; ಪೂರ್ಣಾಙ್ಕ y; ಭಿನ್ನ x2; ಪೂರ್ಣಾಙ್ಕ y2;} ret_mixed3_test_type;
ಪ್ರಕಾರನಿರ್ದೇಶ ret_mixed3_test_type (*ret_mixed3_test_function_type) (ret_mixed3_test_type);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_mixed3_test_callback(ಶೂನ್ಯ *ptr) {
  ret_mixed3_test_function_type f = (ret_mixed3_test_function_type)ptr;
  ret_mixed3_test_type a = {10, 5, 35, 7 };
  ret_mixed3_test_type r;
  r = f(a);
  ಪ್ರತ್ಯಾಗಮ ((r.x == a.x*5) && (r.y2 == a.y*3)) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_mixed3_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef struct ret_mixed3_test_type_s {float x; int y; float x2; int y2;} ret_mixed3_test_type;"
  "ret_mixed3_test_type f(ret_mixed3_test_type a) {\n"
  "  ret_mixed3_test_type r = {a.x*5, 0, 0, a.y*3};\n"
  "  return r;\n"
  "}\n";

  ಪ್ರತ್ಯಾಗಮ run_callback(src, ret_mixed3_test_callback);
}

/*
 * reg_pack_test: return a small struct which should be packed into
 * registers (Win32) during return.
 */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ reg_pack_test_type_s {ಪೂರ್ಣಾಙ್ಕ x, y;} reg_pack_test_type;
ಪ್ರಕಾರನಿರ್ದೇಶ reg_pack_test_type (*reg_pack_test_function_type) (reg_pack_test_type);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ reg_pack_test_callback(ಶೂನ್ಯ *ptr) {
  reg_pack_test_function_type f = (reg_pack_test_function_type)ptr;
  reg_pack_test_type a = {10, 35};
  reg_pack_test_type r;
  r = f(a);
  ಪ್ರತ್ಯಾಗಮ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ reg_pack_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef struct reg_pack_test_type_s {int x, y;} reg_pack_test_type;"
  "reg_pack_test_type f(reg_pack_test_type a) {\n"
  "  reg_pack_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";
  
  ಪ್ರತ್ಯಾಗಮ run_callback(src, reg_pack_test_callback);
}

/*
 * reg_pack_longlong_test: return a small struct which should be packed into
 * registers (x86-64) during return.
 */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;
ಪ್ರಕಾರನಿರ್ದೇಶ reg_pack_longlong_test_type (*reg_pack_longlong_test_function_type) (reg_pack_longlong_test_type);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ reg_pack_longlong_test_callback(ಶೂನ್ಯ *ptr) {
  reg_pack_longlong_test_function_type f = (reg_pack_longlong_test_function_type)ptr;
  reg_pack_longlong_test_type a = {10, 35};
  reg_pack_longlong_test_type r;
  r = f(a);
  ಪ್ರತ್ಯಾಗಮ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ reg_pack_longlong_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef struct reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;"
  "reg_pack_longlong_test_type f(reg_pack_longlong_test_type a) {\n"
  "  reg_pack_longlong_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";
  
  ಪ್ರತ್ಯಾಗಮ run_callback(src, reg_pack_longlong_test_callback);
}

/*
 * ret_6plus2longlong_test:
 *
 * This catches a corner case in the x86_64 ABI code: the first 5
 * arguments fit into registers, the 6th doesn't, but the 7th argument
 * fits into the 6th argument integer register, %r9.
 *
 * Note that the purpose of the 10th argument is to avoid a situation
 * in which gcc would accidentally put the longlong at the right
 * address, thus causing a success message even though TCC actually
 * generated incorrect code.
 */
ಪ್ರಕಾರನಿರ್ದೇಶ reg_pack_longlong_test_type (*ret_6plus2longlong_test_function_type) (long long, long long, long long, long long, long long, reg_pack_longlong_test_type, long long, long long);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_6plus2longlong_test_callback(ಶೂನ್ಯ *ptr) {
  ret_6plus2longlong_test_function_type f = (ret_6plus2longlong_test_function_type)ptr;
  reg_pack_longlong_test_type a = {10, 35};
  reg_pack_longlong_test_type r;
  r = f(0, 0, 0, 0, 0, a, 37, 38);
  ಪ್ರತ್ಯಾಗಮ ((r.x == 37) && (r.y == 37)) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ret_6plus2longlong_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef struct reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;"
  "reg_pack_longlong_test_type f(long long x1, long long x2, long long x3, long long x4, long long x5, reg_pack_longlong_test_type a, long long x8, long long x9) {\n"
  "  reg_pack_longlong_test_type r = { x8, x8 };\n"
  "  return r;\n"
  "}\n";

  ಪ್ರತ್ಯಾಗಮ run_callback(src, ret_6plus2longlong_test_callback);
}

/*
 * sret_test: Create a struct large enough to be returned via sret
 * (hidden pointer as first function argument)
 */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ sret_test_type_s {long long a, b, c;} sret_test_type;
ಪ್ರಕಾರನಿರ್ದೇಶ sret_test_type (*sret_test_function_type) (sret_test_type);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ sret_test_callback(ಶೂನ್ಯ *ptr) {
  sret_test_function_type f = (sret_test_function_type)(ptr);
  sret_test_type x = {5436LL, 658277698LL, 43878957LL};
  sret_test_type r = f(x);
  ಪ್ರತ್ಯಾಗಮ ((r.a==x.a*35)&&(r.b==x.b*19)&&(r.c==x.c*21)) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ sret_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef struct sret_test_type_s {long long a, b, c;} sret_test_type;\n"
  "sret_test_type f(sret_test_type x) {\n"
  "  sret_test_type r = {x.a*35, x.b*19, x.c*21};\n"
  "  return r;\n"
  "}\n";
  
  ಪ್ರತ್ಯಾಗಮ run_callback(src, sret_test_callback);
}

/*
 * one_member_union_test:
 * 
 * In the x86-64 ABI a union should always be passed on the stack. However
 * it appears that a single member union is treated by GCC as its member.
 */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಙ್ಘ one_member_union_test_type_u {ಪೂರ್ಣಾಙ್ಕ x;} one_member_union_test_type;
ಪ್ರಕಾರನಿರ್ದೇಶ one_member_union_test_type (*one_member_union_test_function_type) (one_member_union_test_type);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ one_member_union_test_callback(ಶೂನ್ಯ *ptr) {
  one_member_union_test_function_type f = (one_member_union_test_function_type)ptr;
  one_member_union_test_type a, b;
  a.x = 34;
  b = f(a);
  ಪ್ರತ್ಯಾಗಮ (b.x == a.x*2) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ one_member_union_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef union one_member_union_test_type_u {int x;} one_member_union_test_type;\n"
  "one_member_union_test_type f(one_member_union_test_type a) {\n"
  "  one_member_union_test_type b;\n"
  "  b.x = a.x * 2;\n"
  "  return b;\n"
  "}\n";
  ಪ್ರತ್ಯಾಗಮ run_callback(src, one_member_union_test_callback);
}

/*
 * two_member_union_test:
 * 
 * In the x86-64 ABI a union should always be passed on the stack.
 */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಙ್ಘ two_member_union_test_type_u {ಪೂರ್ಣಾಙ್ಕ x; long y;} two_member_union_test_type;
ಪ್ರಕಾರನಿರ್ದೇಶ two_member_union_test_type (*two_member_union_test_function_type) (two_member_union_test_type);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ two_member_union_test_callback(ಶೂನ್ಯ *ptr) {
  two_member_union_test_function_type f = (two_member_union_test_function_type)ptr;
  two_member_union_test_type a, b;
  a.x = 34;
  b = f(a);
  ಪ್ರತ್ಯಾಗಮ (b.x == a.x*2) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ two_member_union_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef union two_member_union_test_type_u {int x; long y;} two_member_union_test_type;\n"
  "two_member_union_test_type f(two_member_union_test_type a) {\n"
  "  two_member_union_test_type b;\n"
  "  b.x = a.x * 2;\n"
  "  return b;\n"
  "}\n";
  ಪ್ರತ್ಯಾಗಮ run_callback(src, two_member_union_test_callback);
}

/*
 * Win64 calling convention test.
 */

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ many_struct_test_type_s {long long a, b, c;} many_struct_test_type;
ಪ್ರಕಾರನಿರ್ದೇಶ many_struct_test_type (*many_struct_test_function_type) (many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type);
 
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ many_struct_test_callback(ಶೂನ್ಯ *ptr) {
  many_struct_test_function_type f = (many_struct_test_function_type)ptr;
  many_struct_test_type v = {1, 2, 3};
  many_struct_test_type r = f(v,v,v,v,v,v);
  ಪ್ರತ್ಯಾಗಮ ((r.a == 6) && (r.b == 12) && (r.c == 18))?0:-1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ many_struct_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef struct many_struct_test_type_s {long long a, b, c;} many_struct_test_type;\n"
  "many_struct_test_type f(many_struct_test_type x1, many_struct_test_type x2, many_struct_test_type x3, many_struct_test_type x4, many_struct_test_type x5, many_struct_test_type x6) {\n"
  "  many_struct_test_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  y.c = x1.c + x2.c + x3.c + x4.c + x5.c + x6.c;\n"
  "  return y;\n"
  "}\n";
  ಪ್ರತ್ಯಾಗಮ run_callback(src, many_struct_test_callback);
}

/*
 * Win64 calling convention test.
 */

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ many_struct_test_2_type_s {ಪೂರ್ಣಾಙ್ಕ a, b;} many_struct_test_2_type;
ಪ್ರಕಾರನಿರ್ದೇಶ many_struct_test_2_type (*many_struct_test_2_function_type) (many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type);
 
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ many_struct_test_2_callback(ಶೂನ್ಯ *ptr) {
  many_struct_test_2_function_type f = (many_struct_test_2_function_type)ptr;
  many_struct_test_2_type v = {1,2};
  many_struct_test_2_type r = f(v,v,v,v,v,v);
  ಪ್ರತ್ಯಾಗಮ ((r.a == 6) && (r.b == 12))?0:-1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ many_struct_test_2(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef struct many_struct_test_2_type_s {int a, b;} many_struct_test_2_type;\n"
  "many_struct_test_2_type f(many_struct_test_2_type x1, many_struct_test_2_type x2, many_struct_test_2_type x3, many_struct_test_2_type x4, many_struct_test_2_type x5, many_struct_test_2_type x6) {\n"
  "  many_struct_test_2_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  return y;\n"
  "}\n";
  ಪ್ರತ್ಯಾಗಮ run_callback(src, many_struct_test_2_callback);
}

/*
 * Win64 calling convention test.
 */

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ many_struct_test_3_type_s {ಪೂರ್ಣಾಙ್ಕ a, b;} many_struct_test_3_type;
ಪ್ರಕಾರನಿರ್ದೇಶ many_struct_test_3_type (*many_struct_test_3_function_type) (many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type, ...);
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ many_struct_test_3_struct_type { many_struct_test_3_function_type f; many_struct_test_3_function_type *f2; } many_struct_test_3_struct_type;

ಸ್ಥಿರ ಶೂನ್ಯ many_struct_test_3_dummy(ದ್ವಿಗುಣ d, ...)
{
  ಚಞ್ಚಲ ದ್ವಿಗುಣ x = d;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ many_struct_test_3_callback(ಶೂನ್ಯ *ptr) {
  many_struct_test_3_struct_type s = { ptr, };
  many_struct_test_3_struct_type *s2 = &s;
  s2->f2 = &s2->f;
  many_struct_test_3_dummy(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, &s2);
  many_struct_test_3_function_type f = *(s2->f2);
  many_struct_test_3_type v = {1,2};
  many_struct_test_3_type r = (*((s2->f2=&f)+0))(v,v,v,v,v,v,1.0);
  ಪ್ರತ್ಯಾಗಮ ((r.a == 6) && (r.b == 12))?0:-1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ many_struct_test_3(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "typedef struct many_struct_test_3_type_s {int a, b;} many_struct_test_3_type;\n"
  "many_struct_test_3_type f(many_struct_test_3_type x1, many_struct_test_3_type x2, many_struct_test_3_type x3, many_struct_test_3_type x4, many_struct_test_3_type x5, many_struct_test_3_type x6, ...) {\n"
  "  many_struct_test_3_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  return y;\n"
  "}\n";
  ಪ್ರತ್ಯಾಗಮ run_callback(src, many_struct_test_3_callback);
}

/*
 * stdarg_test: Test variable argument list ABI
 */

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {long long a, b, c;} stdarg_test_struct_type;
ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ (*stdarg_test_function_type) (ಪೂರ್ಣಾಙ್ಕ,ಪೂರ್ಣಾಙ್ಕ,ಪೂರ್ಣಾಙ್ಕ,...);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ stdarg_test_callback(ಶೂನ್ಯ *ptr) {
  stdarg_test_function_type f = (stdarg_test_function_type)ptr;
  ಪೂರ್ಣಾಙ್ಕ x;
  ದ್ವಿಗುಣ y;
  stdarg_test_struct_type z = {1, 2, 3}, w;
  f(10, 10, 5,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, &x,
    1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, &y,
    z, z, z, z, z, &w);
  ಪ್ರತ್ಯಾಗಮ ((x == 55) && (y == 55) && (w.a == 5) && (w.b == 10) && (w.c == 15)) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ stdarg_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "#include <stdarg.h>\n"
  "typedef struct {long long a, b, c;} stdarg_test_struct_type;\n"
  "void f(int n_int, int n_float, int n_struct, ...) {\n"
  "  int i, ti = 0;\n"
  "  double td = 0.0;\n"
  "  stdarg_test_struct_type ts = {0,0,0}, tmp;\n"
  "  va_list ap;\n"
  "  va_start(ap, n_struct);\n"
  "  for (i = 0, ti = 0; i < n_int; ++i)\n"
  "    ti += va_arg(ap, int);\n"
  "  *va_arg(ap, int*) = ti;\n"
  "  for (i = 0, td = 0; i < n_float; ++i)\n"
  "    td += va_arg(ap, double);\n"
  "  *va_arg(ap, double*) = td;\n"
  "  for (i = 0; i < n_struct; ++i) {\n"
  "    tmp = va_arg(ap, stdarg_test_struct_type);\n"
  "    ts.a += tmp.a; ts.b += tmp.b; ts.c += tmp.c;"
  "  }\n"
  "  *va_arg(ap, stdarg_test_struct_type*) = ts;\n"
  "  va_end(ap);"
  "}\n";
  ಪ್ರತ್ಯಾಗಮ run_callback(src, stdarg_test_callback);
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {long long a, b;} stdarg_many_test_struct_type;
ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ (*stdarg_many_test_function_type) (ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ,
						stdarg_many_test_struct_type,
						ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ, ...);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ stdarg_many_test_callback(ಶೂನ್ಯ *ptr)
{
  stdarg_many_test_function_type f = (stdarg_many_test_function_type)ptr;
  ಪೂರ್ಣಾಙ್ಕ x;
  stdarg_many_test_struct_type l = {10, 11};
  f(1, 2, 3, 4, 5, l, 6, 7, &x, 44);
  ಪ್ರತ್ಯಾಗಮ x == 44 ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ stdarg_many_test(ಶೂನ್ಯ)
{
  ಧ್ರುವ ವರ್ಣ *src =
  "#include <stdarg.h>\n"
  "typedef struct {long long a, b;} stdarg_many_test_struct_type;\n"
  "void f (int a, int b, int c, int d, int e, stdarg_many_test_struct_type l, int f, int g, ...){\n"
  "  va_list ap;\n"
  "  int *p;\n"
  "  va_start (ap, g);\n"
  "  p = va_arg(ap, int*);\n"
  "  *p = va_arg(ap, int);\n"
  "  va_end (ap);\n"
  "}\n";
  ಪ್ರತ್ಯಾಗಮ run_callback(src, stdarg_many_test_callback);
}

/*
 * Test Win32 stdarg handling, since the calling convention will pass a pointer
 * to the struct and the stdarg pointer must point to that pointer initially.
 */

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {long long a, b, c;} stdarg_struct_test_struct_type;
ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ (*stdarg_struct_test_function_type) (stdarg_struct_test_struct_type a, ...);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ stdarg_struct_test_callback(ಶೂನ್ಯ *ptr) {
  stdarg_struct_test_function_type f = (stdarg_struct_test_function_type)ptr;
  stdarg_struct_test_struct_type v = {10, 35, 99};
  ಪೂರ್ಣಾಙ್ಕ x = f(v, 234);
  ಪ್ರತ್ಯಾಗಮ (x == 378) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ stdarg_struct_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src =
  "#include <stdarg.h>\n"
  "typedef struct {long long a, b, c;} stdarg_struct_test_struct_type;\n"
  "int f(stdarg_struct_test_struct_type a, ...) {\n"
  "  va_list ap;\n"
  "  va_start(ap, a);\n"
  "  int z = va_arg(ap, int);\n"
  "  va_end(ap);\n"
  "  return z + a.a + a.b + a.c;\n"
  "}\n";
  ಪ್ರತ್ಯಾಗಮ run_callback(src, stdarg_struct_test_callback);
}

/* Test that x86-64 arranges the stack correctly for arguments with alignment >8 bytes */

ಪ್ರಕಾರನಿರ್ದೇಶ LONG_DOUBLE (*arg_align_test_callback_type) (LONG_DOUBLE,ಪೂರ್ಣಾಙ್ಕ,LONG_DOUBLE,ಪೂರ್ಣಾಙ್ಕ,LONG_DOUBLE);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arg_align_test_callback(ಶೂನ್ಯ *ptr) {
  arg_align_test_callback_type f = (arg_align_test_callback_type)ptr;
  long ದ್ವಿಗುಣ x = f(12, 0, 25, 0, 37);
  ಪ್ರತ್ಯಾಗಮ (x == 74) ? 0 : -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arg_align_test(ಶೂನ್ಯ) {
  ಧ್ರುವ ವರ್ಣ *src = 
  "long double f(long double a, int b, long double c, int d, long double e) {\n"
  "  return a + c + e;\n"
  "}\n";
  ಪ್ರತ್ಯಾಗಮ run_callback(src, arg_align_test_callback);
}

#define RUN_TEST(t) \
  ಯದಿ (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    ಯದಿ (t() == 0) { \
      fputs("success\n", stdout); \
    } ಅನ್ಯಥಾ { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv) {
  ಪೂರ್ಣಾಙ್ಕ i;
  ಧ್ರುವ ವರ್ಣ *testname = ರಿಕ್ತ;
  ಪೂರ್ಣಾಙ್ಕ retval = EXIT_SUCCESS;
  
  /* if tcclib.h and libtcc1.a are not installed, where can we find them */
  ಪ್ರತಿ (i = 1; i < argc; ++i) {
    ಯದಿ (!memcmp(argv[i], "run_test=", 9))
      testname = argv[i] + 9;
  }

  g_argv = argv, g_argc = argc;

  RUN_TEST(ret_int_test);
  RUN_TEST(ret_longlong_test);
  RUN_TEST(ret_float_test);
  RUN_TEST(ret_double_test);
  RUN_TEST(ret_longdouble_test);
  RUN_TEST(ret_2float_test);
  RUN_TEST(ret_2double_test);
  RUN_TEST(ret_8plus2double_test);
  RUN_TEST(ret_6plus2longlong_test);
#ಯದಿ !defined __x86_64__ || defined _WIN32
  /* currently broken on x86_64 linux */
  RUN_TEST(ret_mixed_test);
  RUN_TEST(ret_mixed2_test);
#endif
  RUN_TEST(ret_mixed3_test);
  RUN_TEST(reg_pack_test);
  RUN_TEST(reg_pack_longlong_test);
  RUN_TEST(sret_test);
  RUN_TEST(one_member_union_test);
  RUN_TEST(two_member_union_test);
  RUN_TEST(many_struct_test);
  RUN_TEST(many_struct_test_2);
  RUN_TEST(many_struct_test_3);
  RUN_TEST(stdarg_test);
  RUN_TEST(stdarg_many_test);
  RUN_TEST(stdarg_struct_test);
  RUN_TEST(arg_align_test);
  ಪ್ರತ್ಯಾಗಮ retval;
}
