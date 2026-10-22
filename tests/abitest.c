#ਅਨ੍ਤਰ੍ਭਾਵ <libtcc.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdarg.h>

// MinGW has 80-bit rather than 64-bit long double which isn't compatible with TCC or MSVC
#ਜੇ defined(_WIN32) && defined(__GNUC__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_DOUBLE ਦੁੱਗਣਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_DOUBLE_LITERAL(x) x
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_DOUBLE ਲੰਮਾ ਦੁੱਗਣਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_DOUBLE_LITERAL(x) x ## L
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਪੂਰਨ g_argc;
ਸਥਿਰ ਅੱਖਰ **g_argv;

ਸਥਿਰ ਖਾਲੀ ਸੈੱਟ_options(TCCState *s, ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    ਪੂਰਨ i;
    ਲਈ (i = 1; i < argc; ++i) {
        ਅੱਖਰ *a = argv[i];
        ਜੇ (a[0] == '-') {
            ਜੇ (a[1] == 'B')
                tcc_ਸੈੱਟ_lib_ਰਸਤਾ(s, a+2);
            ਨਹੀਂਤਾਂ ਜੇ (a[1] == 'I')
                tcc_ਜੋੜੋ_include_ਰਸਤਾ(s, a+2);
            ਨਹੀਂਤਾਂ ਜੇ (a[1] == 'L')
                tcc_ਜੋੜੋ_library_ਰਸਤਾ(s, a+2);
        }
    }
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (*callback_type) (ਖਾਲੀ*);

/*
 * Compile source code and call a callback with a pointer to the symbol "f".
 */
ਸਥਿਰ ਪੂਰਨ ਲੜੀਵਾਰ_callback(ਅਚਲ ਅੱਖਰ *src, callback_type callback) {
  TCCState *s;
  ਪੂਰਨ ਨਤੀਜਾ;
  ਖਾਲੀ *ptr;
  
  s = tcc_new();
  ਜੇ (!s)
    ਵਾਪਸ -1;

  ਸੈੱਟ_options(s, g_argc, g_argv);

  ਜੇ (tcc_ਸੈੱਟ_output_type(s, TCC_OUTPUT_ਸਮ੍ਰਿਤੀ) == -1)
    ਵਾਪਸ -1;
  ਜੇ (tcc_compile_string(s, src) == -1)
    ਵਾਪਸ -1;
  ਜੇ (tcc_relocate(s) == -1)
    ਵਾਪਸ -1;
  
  ptr = tcc_get_ਚਿੰਨ੍ਹ(s, "f");
  ਜੇ (!ptr)
    ਵਾਪਸ -1;
  ਨਤੀਜਾ = callback(ptr);
  
  tcc_delete(s);
  
  ਵਾਪਸ ਨਤੀਜਾ;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STR2(x) #x
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STR(x) STR2(x)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RET_PRIMITIVE_TEST(name, type, val) \
  ਸਥਿਰ ਪੂਰਨ ret_ ## name ## _test_callback(ਖਾਲੀ *ptr) { \
    type (*callback) (type) = (type(*)(type))ptr; \
    type x = val; \
    type y = callback(x); \
    ਵਾਪਸ (y == x+x) ? 0 : -1; \
  } \
  \
  ਸਥਿਰ ਪੂਰਨ ret_ ## name ## _test(ਖਾਲੀ) { \
    ਅਚਲ ਅੱਖਰ *src = STR(type) " f(" STR(type) " x) {return x+x;}"; \
    ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, ret_ ## name ## _test_callback); \
  }

RET_PRIMITIVE_TEST(ਪੂਰਨ, ਪੂਰਨ, 70000)
RET_PRIMITIVE_TEST(longlong, ਲੰਮਾ ਲੰਮਾ, 4333369356528LL)
RET_PRIMITIVE_TEST(ਦਸ਼ਮਲਵ, ਦਸ਼ਮਲਵ, 63.0)
RET_PRIMITIVE_TEST(ਦੁੱਗਣਾ, ਦੁੱਗਣਾ, 14789798.0)
RET_PRIMITIVE_TEST(longdouble, LONG_DOUBLE, LONG_DOUBLE_LITERAL(378943892.0))

/*
 * ret_2float_test:
 * 
 * On x86-64, a struct with 2 floats should be packed into a single
 * SSE register (VT_DOUBLE is used for this purpose).
 */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ret_2float_test_type_s {ਦਸ਼ਮਲਵ x, y;} ret_2float_test_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ret_2float_test_type (*ret_2float_test_function_type) (ret_2float_test_type);

ਸਥਿਰ ਪੂਰਨ ret_2float_test_callback(ਖਾਲੀ *ptr) {
  ret_2float_test_function_type f = (ret_2float_test_function_type)ptr;
  ret_2float_test_type a = {10, 35};
  ret_2float_test_type r;
  r = f(a);
  ਵਾਪਸ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ ret_2float_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef struct ret_2float_test_type_s {float x, y;} ret_2float_test_type;"
  "ret_2float_test_type f(ret_2float_test_type a) {\n"
  "  ret_2float_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, ret_2float_test_callback);
}

/*
 * ret_2double_test:
 * 
 * On x86-64, a struct with 2 doubles should be passed in two SSE
 * registers.
 */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ret_2double_test_type_s {ਦੁੱਗਣਾ x, y;} ret_2double_test_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ret_2double_test_type (*ret_2double_test_function_type) (ret_2double_test_type);

ਸਥਿਰ ਪੂਰਨ ret_2double_test_callback(ਖਾਲੀ *ptr) {
  ret_2double_test_function_type f = (ret_2double_test_function_type)ptr;
  ret_2double_test_type a = {10, 35};
  ret_2double_test_type r;
  r = f(a);
  ਵਾਪਸ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ ret_2double_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef struct ret_2double_test_type_s {double x, y;} ret_2double_test_type;"
  "ret_2double_test_type f(ret_2double_test_type a) {\n"
  "  ret_2double_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, ret_2double_test_callback);
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
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ret_2double_test_type (*ret_8plus2double_test_function_type) (ਦੁੱਗਣਾ, ਦੁੱਗਣਾ, ਦੁੱਗਣਾ, ਦੁੱਗਣਾ, ਦੁੱਗਣਾ, ਦੁੱਗਣਾ, ਦੁੱਗਣਾ, ret_2double_test_type, ਦੁੱਗਣਾ, ਦੁੱਗਣਾ);

ਸਥਿਰ ਪੂਰਨ ret_8plus2double_test_callback(ਖਾਲੀ *ptr) {
  ret_8plus2double_test_function_type f = (ret_8plus2double_test_function_type)ptr;
  ret_2double_test_type a = {10, 35};
  ret_2double_test_type r;
  r = f(0, 0, 0, 0, 0, 0, 0, a, 37, 38);
  ਵਾਪਸ ((r.x == 37) && (r.y == 37)) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ ret_8plus2double_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef struct ret_2double_test_type_s {double x, y;} ret_2double_test_type;"
  "ret_2double_test_type f(double x1, double x2, double x3, double x4, double x5, double x6, double x7, ret_2double_test_type a, double x8, double x9) {\n"
  "  ret_2double_test_type r = { x8, x8 };\n"
  "  return r;\n"
  "}\n";

  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, ret_8plus2double_test_callback);
}

/*
 * ret_mixed_test:
 *
 * On x86-64, a struct with a double and a 64-bit integer should be
 * passed in one SSE register and one integer register.
 */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ret_mixed_test_type_s {ਦੁੱਗਣਾ x; ਲੰਮਾ ਲੰਮਾ y;} ret_mixed_test_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ret_mixed_test_type (*ret_mixed_test_function_type) (ret_mixed_test_type);

ਸਥਿਰ ਪੂਰਨ ret_mixed_test_callback(ਖਾਲੀ *ptr) {
  ret_mixed_test_function_type f = (ret_mixed_test_function_type)ptr;
  ret_mixed_test_type a = {10, 35};
  ret_mixed_test_type r;
  r = f(a);
  ਵਾਪਸ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ ret_mixed_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef struct ret_mixed_test_type_s {double x; long long y;} ret_mixed_test_type;"
  "ret_mixed_test_type f(ret_mixed_test_type a) {\n"
  "  ret_mixed_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, ret_mixed_test_callback);
}

/*
 * ret_mixed2_test:
 *
 * On x86-64, a struct with two floats and two 32-bit integers should
 * be passed in one SSE register and one integer register.
 */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ret_mixed2_test_type_s {ਦਸ਼ਮਲਵ x,x2; ਪੂਰਨ y,y2;} ret_mixed2_test_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ret_mixed2_test_type (*ret_mixed2_test_function_type) (ret_mixed2_test_type);

ਸਥਿਰ ਪੂਰਨ ret_mixed2_test_callback(ਖਾਲੀ *ptr) {
  ret_mixed2_test_function_type f = (ret_mixed2_test_function_type)ptr;
  ret_mixed2_test_type a = {10, 5, 35, 7 };
  ret_mixed2_test_type r;
  r = f(a);
  ਵਾਪਸ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ ret_mixed2_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef struct ret_mixed2_test_type_s {float x, x2; int y,y2;} ret_mixed2_test_type;"
  "ret_mixed2_test_type f(ret_mixed2_test_type a) {\n"
  "  ret_mixed2_test_type r = {a.x*5, 0, a.y*3, 0};\n"
  "  return r;\n"
  "}\n";

  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, ret_mixed2_test_callback);
}

/*
 * ret_mixed3_test:
 *
 * On x86-64, this struct should be passed in two integer registers.
 */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ret_mixed3_test_type_s {ਦਸ਼ਮਲਵ x; ਪੂਰਨ y; ਦਸ਼ਮਲਵ x2; ਪੂਰਨ y2;} ret_mixed3_test_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ret_mixed3_test_type (*ret_mixed3_test_function_type) (ret_mixed3_test_type);

ਸਥਿਰ ਪੂਰਨ ret_mixed3_test_callback(ਖਾਲੀ *ptr) {
  ret_mixed3_test_function_type f = (ret_mixed3_test_function_type)ptr;
  ret_mixed3_test_type a = {10, 5, 35, 7 };
  ret_mixed3_test_type r;
  r = f(a);
  ਵਾਪਸ ((r.x == a.x*5) && (r.y2 == a.y*3)) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ ret_mixed3_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef struct ret_mixed3_test_type_s {float x; int y; float x2; int y2;} ret_mixed3_test_type;"
  "ret_mixed3_test_type f(ret_mixed3_test_type a) {\n"
  "  ret_mixed3_test_type r = {a.x*5, 0, 0, a.y*3};\n"
  "  return r;\n"
  "}\n";

  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, ret_mixed3_test_callback);
}

/*
 * reg_pack_test: return a small struct which should be packed into
 * registers (Win32) during return.
 */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ reg_pack_test_type_s {ਪੂਰਨ x, y;} reg_pack_test_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ reg_pack_test_type (*reg_pack_test_function_type) (reg_pack_test_type);

ਸਥਿਰ ਪੂਰਨ reg_pack_test_callback(ਖਾਲੀ *ptr) {
  reg_pack_test_function_type f = (reg_pack_test_function_type)ptr;
  reg_pack_test_type a = {10, 35};
  reg_pack_test_type r;
  r = f(a);
  ਵਾਪਸ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ reg_pack_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef struct reg_pack_test_type_s {int x, y;} reg_pack_test_type;"
  "reg_pack_test_type f(reg_pack_test_type a) {\n"
  "  reg_pack_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";
  
  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, reg_pack_test_callback);
}

/*
 * reg_pack_longlong_test: return a small struct which should be packed into
 * registers (x86-64) during return.
 */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ reg_pack_longlong_test_type_s {ਲੰਮਾ ਲੰਮਾ x, y;} reg_pack_longlong_test_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ reg_pack_longlong_test_type (*reg_pack_longlong_test_function_type) (reg_pack_longlong_test_type);

ਸਥਿਰ ਪੂਰਨ reg_pack_longlong_test_callback(ਖਾਲੀ *ptr) {
  reg_pack_longlong_test_function_type f = (reg_pack_longlong_test_function_type)ptr;
  reg_pack_longlong_test_type a = {10, 35};
  reg_pack_longlong_test_type r;
  r = f(a);
  ਵਾਪਸ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ reg_pack_longlong_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef struct reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;"
  "reg_pack_longlong_test_type f(reg_pack_longlong_test_type a) {\n"
  "  reg_pack_longlong_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";
  
  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, reg_pack_longlong_test_callback);
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
ਕਿਸਮਪਰਿਭਾਸ਼ਾ reg_pack_longlong_test_type (*ret_6plus2longlong_test_function_type) (ਲੰਮਾ ਲੰਮਾ, ਲੰਮਾ ਲੰਮਾ, ਲੰਮਾ ਲੰਮਾ, ਲੰਮਾ ਲੰਮਾ, ਲੰਮਾ ਲੰਮਾ, reg_pack_longlong_test_type, ਲੰਮਾ ਲੰਮਾ, ਲੰਮਾ ਲੰਮਾ);

ਸਥਿਰ ਪੂਰਨ ret_6plus2longlong_test_callback(ਖਾਲੀ *ptr) {
  ret_6plus2longlong_test_function_type f = (ret_6plus2longlong_test_function_type)ptr;
  reg_pack_longlong_test_type a = {10, 35};
  reg_pack_longlong_test_type r;
  r = f(0, 0, 0, 0, 0, a, 37, 38);
  ਵਾਪਸ ((r.x == 37) && (r.y == 37)) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ ret_6plus2longlong_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef struct reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;"
  "reg_pack_longlong_test_type f(long long x1, long long x2, long long x3, long long x4, long long x5, reg_pack_longlong_test_type a, long long x8, long long x9) {\n"
  "  reg_pack_longlong_test_type r = { x8, x8 };\n"
  "  return r;\n"
  "}\n";

  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, ret_6plus2longlong_test_callback);
}

/*
 * sret_test: Create a struct large enough to be returned via sret
 * (hidden pointer as first function argument)
 */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ sret_test_type_s {ਲੰਮਾ ਲੰਮਾ a, b, c;} sret_test_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ sret_test_type (*sret_test_function_type) (sret_test_type);

ਸਥਿਰ ਪੂਰਨ sret_test_callback(ਖਾਲੀ *ptr) {
  sret_test_function_type f = (sret_test_function_type)(ptr);
  sret_test_type x = {5436LL, 658277698LL, 43878957LL};
  sret_test_type r = f(x);
  ਵਾਪਸ ((r.a==x.a*35)&&(r.b==x.b*19)&&(r.c==x.c*21)) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ sret_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef struct sret_test_type_s {long long a, b, c;} sret_test_type;\n"
  "sret_test_type f(sret_test_type x) {\n"
  "  sret_test_type r = {x.a*35, x.b*19, x.c*21};\n"
  "  return r;\n"
  "}\n";
  
  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, sret_test_callback);
}

/*
 * one_member_union_test:
 * 
 * In the x86-64 ABI a union should always be passed on the stack. However
 * it appears that a single member union is treated by GCC as its member.
 */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ one_member_union_test_type_u {ਪੂਰਨ x;} one_member_union_test_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ one_member_union_test_type (*one_member_union_test_function_type) (one_member_union_test_type);

ਸਥਿਰ ਪੂਰਨ one_member_union_test_callback(ਖਾਲੀ *ptr) {
  one_member_union_test_function_type f = (one_member_union_test_function_type)ptr;
  one_member_union_test_type a, b;
  a.x = 34;
  b = f(a);
  ਵਾਪਸ (b.x == a.x*2) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ one_member_union_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef union one_member_union_test_type_u {int x;} one_member_union_test_type;\n"
  "one_member_union_test_type f(one_member_union_test_type a) {\n"
  "  one_member_union_test_type b;\n"
  "  b.x = a.x * 2;\n"
  "  return b;\n"
  "}\n";
  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, one_member_union_test_callback);
}

/*
 * two_member_union_test:
 * 
 * In the x86-64 ABI a union should always be passed on the stack.
 */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ two_member_union_test_type_u {ਪੂਰਨ x; ਲੰਮਾ y;} two_member_union_test_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ two_member_union_test_type (*two_member_union_test_function_type) (two_member_union_test_type);

ਸਥਿਰ ਪੂਰਨ two_member_union_test_callback(ਖਾਲੀ *ptr) {
  two_member_union_test_function_type f = (two_member_union_test_function_type)ptr;
  two_member_union_test_type a, b;
  a.x = 34;
  b = f(a);
  ਵਾਪਸ (b.x == a.x*2) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ two_member_union_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef union two_member_union_test_type_u {int x; long y;} two_member_union_test_type;\n"
  "two_member_union_test_type f(two_member_union_test_type a) {\n"
  "  two_member_union_test_type b;\n"
  "  b.x = a.x * 2;\n"
  "  return b;\n"
  "}\n";
  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, two_member_union_test_callback);
}

/*
 * Win64 calling convention test.
 */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ many_struct_test_type_s {ਲੰਮਾ ਲੰਮਾ a, b, c;} many_struct_test_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ many_struct_test_type (*many_struct_test_function_type) (many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type);
 
ਸਥਿਰ ਪੂਰਨ many_struct_test_callback(ਖਾਲੀ *ptr) {
  many_struct_test_function_type f = (many_struct_test_function_type)ptr;
  many_struct_test_type v = {1, 2, 3};
  many_struct_test_type r = f(v,v,v,v,v,v);
  ਵਾਪਸ ((r.a == 6) && (r.b == 12) && (r.c == 18))?0:-1;
}

ਸਥਿਰ ਪੂਰਨ many_struct_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef struct many_struct_test_type_s {long long a, b, c;} many_struct_test_type;\n"
  "many_struct_test_type f(many_struct_test_type x1, many_struct_test_type x2, many_struct_test_type x3, many_struct_test_type x4, many_struct_test_type x5, many_struct_test_type x6) {\n"
  "  many_struct_test_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  y.c = x1.c + x2.c + x3.c + x4.c + x5.c + x6.c;\n"
  "  return y;\n"
  "}\n";
  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, many_struct_test_callback);
}

/*
 * Win64 calling convention test.
 */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ many_struct_test_2_type_s {ਪੂਰਨ a, b;} many_struct_test_2_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ many_struct_test_2_type (*many_struct_test_2_function_type) (many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type);
 
ਸਥਿਰ ਪੂਰਨ many_struct_test_2_callback(ਖਾਲੀ *ptr) {
  many_struct_test_2_function_type f = (many_struct_test_2_function_type)ptr;
  many_struct_test_2_type v = {1,2};
  many_struct_test_2_type r = f(v,v,v,v,v,v);
  ਵਾਪਸ ((r.a == 6) && (r.b == 12))?0:-1;
}

ਸਥਿਰ ਪੂਰਨ many_struct_test_2(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef struct many_struct_test_2_type_s {int a, b;} many_struct_test_2_type;\n"
  "many_struct_test_2_type f(many_struct_test_2_type x1, many_struct_test_2_type x2, many_struct_test_2_type x3, many_struct_test_2_type x4, many_struct_test_2_type x5, many_struct_test_2_type x6) {\n"
  "  many_struct_test_2_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  return y;\n"
  "}\n";
  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, many_struct_test_2_callback);
}

/*
 * Win64 calling convention test.
 */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ many_struct_test_3_type_s {ਪੂਰਨ a, b;} many_struct_test_3_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ many_struct_test_3_type (*many_struct_test_3_function_type) (many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type, ...);
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ many_struct_test_3_struct_type { many_struct_test_3_function_type f; many_struct_test_3_function_type *f2; } many_struct_test_3_struct_type;

ਸਥਿਰ ਖਾਲੀ many_struct_test_3_dummy(ਦੁੱਗਣਾ d, ...)
{
  ਅਸਥਿਰ ਦੁੱਗਣਾ x = d;
}

ਸਥਿਰ ਪੂਰਨ many_struct_test_3_callback(ਖਾਲੀ *ptr) {
  many_struct_test_3_struct_type s = { ptr, };
  many_struct_test_3_struct_type *s2 = &s;
  s2->f2 = &s2->f;
  many_struct_test_3_dummy(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, &s2);
  many_struct_test_3_function_type f = *(s2->f2);
  many_struct_test_3_type v = {1,2};
  many_struct_test_3_type r = (*((s2->f2=&f)+0))(v,v,v,v,v,v,1.0);
  ਵਾਪਸ ((r.a == 6) && (r.b == 12))?0:-1;
}

ਸਥਿਰ ਪੂਰਨ many_struct_test_3(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "typedef struct many_struct_test_3_type_s {int a, b;} many_struct_test_3_type;\n"
  "many_struct_test_3_type f(many_struct_test_3_type x1, many_struct_test_3_type x2, many_struct_test_3_type x3, many_struct_test_3_type x4, many_struct_test_3_type x5, many_struct_test_3_type x6, ...) {\n"
  "  many_struct_test_3_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  return y;\n"
  "}\n";
  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, many_struct_test_3_callback);
}

/*
 * stdarg_test: Test variable argument list ABI
 */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {ਲੰਮਾ ਲੰਮਾ a, b, c;} stdarg_test_struct_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ (*stdarg_test_function_type) (ਪੂਰਨ,ਪੂਰਨ,ਪੂਰਨ,...);

ਸਥਿਰ ਪੂਰਨ stdarg_test_callback(ਖਾਲੀ *ptr) {
  stdarg_test_function_type f = (stdarg_test_function_type)ptr;
  ਪੂਰਨ x;
  ਦੁੱਗਣਾ y;
  stdarg_test_struct_type z = {1, 2, 3}, w;
  f(10, 10, 5,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, &x,
    1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, &y,
    z, z, z, z, z, &w);
  ਵਾਪਸ ((x == 55) && (y == 55) && (w.a == 5) && (w.b == 10) && (w.c == 15)) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ stdarg_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
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
  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, stdarg_test_callback);
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {ਲੰਮਾ ਲੰਮਾ a, b;} stdarg_many_test_struct_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ (*stdarg_many_test_function_type) (ਪੂਰਨ, ਪੂਰਨ, ਪੂਰਨ, ਪੂਰਨ, ਪੂਰਨ,
						stdarg_many_test_struct_type,
						ਪੂਰਨ, ਪੂਰਨ, ...);

ਸਥਿਰ ਪੂਰਨ stdarg_many_test_callback(ਖਾਲੀ *ptr)
{
  stdarg_many_test_function_type f = (stdarg_many_test_function_type)ptr;
  ਪੂਰਨ x;
  stdarg_many_test_struct_type l = {10, 11};
  f(1, 2, 3, 4, 5, l, 6, 7, &x, 44);
  ਵਾਪਸ x == 44 ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ stdarg_many_test(ਖਾਲੀ)
{
  ਅਚਲ ਅੱਖਰ *src =
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
  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, stdarg_many_test_callback);
}

/*
 * Test Win32 stdarg handling, since the calling convention will pass a pointer
 * to the struct and the stdarg pointer must point to that pointer initially.
 */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {ਲੰਮਾ ਲੰਮਾ a, b, c;} stdarg_struct_test_struct_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (*stdarg_struct_test_function_type) (stdarg_struct_test_struct_type a, ...);

ਸਥਿਰ ਪੂਰਨ stdarg_struct_test_callback(ਖਾਲੀ *ptr) {
  stdarg_struct_test_function_type f = (stdarg_struct_test_function_type)ptr;
  stdarg_struct_test_struct_type v = {10, 35, 99};
  ਪੂਰਨ x = f(v, 234);
  ਵਾਪਸ (x == 378) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ stdarg_struct_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src =
  "#include <stdarg.h>\n"
  "typedef struct {long long a, b, c;} stdarg_struct_test_struct_type;\n"
  "int f(stdarg_struct_test_struct_type a, ...) {\n"
  "  va_list ap;\n"
  "  va_start(ap, a);\n"
  "  int z = va_arg(ap, int);\n"
  "  va_end(ap);\n"
  "  return z + a.a + a.b + a.c;\n"
  "}\n";
  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, stdarg_struct_test_callback);
}

/* Test that x86-64 arranges the stack correctly for arguments with alignment >8 bytes */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ LONG_DOUBLE (*arg_align_test_callback_type) (LONG_DOUBLE,ਪੂਰਨ,LONG_DOUBLE,ਪੂਰਨ,LONG_DOUBLE);

ਸਥਿਰ ਪੂਰਨ arg_align_test_callback(ਖਾਲੀ *ptr) {
  arg_align_test_callback_type f = (arg_align_test_callback_type)ptr;
  ਲੰਮਾ ਦੁੱਗਣਾ x = f(12, 0, 25, 0, 37);
  ਵਾਪਸ (x == 74) ? 0 : -1;
}

ਸਥਿਰ ਪੂਰਨ arg_align_test(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *src = 
  "long double f(long double a, int b, long double c, int d, long double e) {\n"
  "  return a + c + e;\n"
  "}\n";
  ਵਾਪਸ ਲੜੀਵਾਰ_callback(src, arg_align_test_callback);
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੜੀਵਾਰ_TEST(t) \
  ਜੇ (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    ਜੇ (t() == 0) { \
      fputs("success\n", stdout); \
    } ਨਹੀਂਤਾਂ { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv) {
  ਪੂਰਨ i;
  ਅਚਲ ਅੱਖਰ *testname = ਨਿਰਾ;
  ਪੂਰਨ retval = EXIT_SUCCESS;
  
  /* if tcclib.h and libtcc1.a are not installed, where can we find them */
  ਲਈ (i = 1; i < argc; ++i) {
    ਜੇ (!memcmp(argv[i], "run_test=", 9))
      testname = argv[i] + 9;
  }

  g_argv = argv, g_argc = argc;

  ਲੜੀਵਾਰ_TEST(ret_int_test);
  ਲੜੀਵਾਰ_TEST(ret_longlong_test);
  ਲੜੀਵਾਰ_TEST(ret_float_test);
  ਲੜੀਵਾਰ_TEST(ret_double_test);
  ਲੜੀਵਾਰ_TEST(ret_longdouble_test);
  ਲੜੀਵਾਰ_TEST(ret_2float_test);
  ਲੜੀਵਾਰ_TEST(ret_2double_test);
  ਲੜੀਵਾਰ_TEST(ret_8plus2double_test);
  ਲੜੀਵਾਰ_TEST(ret_6plus2longlong_test);
#ਜੇ !defined __x86_64__ || defined _WIN32
  /* currently broken on x86_64 linux */
  ਲੜੀਵਾਰ_TEST(ret_mixed_test);
  ਲੜੀਵਾਰ_TEST(ret_mixed2_test);
#ਜੇ_ਅੰਤ
  ਲੜੀਵਾਰ_TEST(ret_mixed3_test);
  ਲੜੀਵਾਰ_TEST(reg_pack_test);
  ਲੜੀਵਾਰ_TEST(reg_pack_longlong_test);
  ਲੜੀਵਾਰ_TEST(sret_test);
  ਲੜੀਵਾਰ_TEST(one_member_union_test);
  ਲੜੀਵਾਰ_TEST(two_member_union_test);
  ਲੜੀਵਾਰ_TEST(many_struct_test);
  ਲੜੀਵਾਰ_TEST(many_struct_test_2);
  ਲੜੀਵਾਰ_TEST(many_struct_test_3);
  ਲੜੀਵਾਰ_TEST(stdarg_test);
  ਲੜੀਵਾਰ_TEST(stdarg_many_test);
  ਲੜੀਵਾਰ_TEST(stdarg_struct_test);
  ਲੜੀਵਾਰ_TEST(arg_align_test);
  ਵਾਪਸ retval;
}
