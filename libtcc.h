#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ LIBTCC_H
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LIBTCC_H

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ LIBTCCAPI
# define LIBTCCAPI
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ *TCCReallocFunc(ਖਾਲੀ *ptr, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ);
LIBTCCAPI ਖਾਲੀ tcc_ਸੈੱਟ_realloc(TCCReallocFunc *my_realloc);

/*****************************/
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(ਖਾਲੀ);

/* free a TCC compilation context */
LIBTCCAPI ਖਾਲੀ tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI ਖਾਲੀ tcc_ਸੈੱਟ_lib_ਰਸਤਾ(TCCState *s, ਅਚਲ ਅੱਖਰ *ਰਸਤਾ);

/* set error/warning callback (optional) */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ TCCErrorFunc(ਖਾਲੀ *opaque, ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ);
LIBTCCAPI ਖਾਲੀ tcc_ਸੈੱਟ_error_func(TCCState *s, ਖਾਲੀ *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI ਪੂਰਨ tcc_ਸੈੱਟ_options(TCCState *s, ਅਚਲ ਅੱਖਰ *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI ਪੂਰਨ tcc_ਜੋੜੋ_include_ਰਸਤਾ(TCCState *s, ਅਚਲ ਅੱਖਰ *pathname);

/* add in system include path */
LIBTCCAPI ਪੂਰਨ tcc_ਜੋੜੋ_sysinclude_ਰਸਤਾ(TCCState *s, ਅਚਲ ਅੱਖਰ *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI ਖਾਲੀ tcc_define_ਚਿੰਨ੍ਹ(TCCState *s, ਅਚਲ ਅੱਖਰ *sym, ਅਚਲ ਅੱਖਰ *ਮੁੱਲ);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI ਖਾਲੀ tcc_undefine_ਚਿੰਨ੍ਹ(TCCState *s, ਅਚਲ ਅੱਖਰ *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI ਪੂਰਨ tcc_ਜੋੜੋ_file(TCCState *s, ਅਚਲ ਅੱਖਰ *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI ਪੂਰਨ tcc_compile_string(TCCState *s, ਅਚਲ ਅੱਖਰ *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI ਪੂਰਨ tcc_ਸੈੱਟ_output_type(TCCState *s, ਪੂਰਨ output_type);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_OUTPUT_ਸਮ੍ਰਿਤੀ   1 /* output will be run in memory */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_OUTPUT_EXE      2 /* executable file */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_OUTPUT_DLL      4 /* dynamic library */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_OUTPUT_OBJ      3 /* object file */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI ਪੂਰਨ tcc_ਜੋੜੋ_library_ਰਸਤਾ(TCCState *s, ਅਚਲ ਅੱਖਰ *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI ਪੂਰਨ tcc_ਜੋੜੋ_library(TCCState *s, ਅਚਲ ਅੱਖਰ *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI ਪੂਰਨ tcc_ਜੋੜੋ_ਚਿੰਨ੍ਹ(TCCState *s, ਅਚਲ ਅੱਖਰ *name, ਅਚਲ ਖਾਲੀ *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI ਪੂਰਨ tcc_output_file(TCCState *s, ਅਚਲ ਅੱਖਰ *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI ਪੂਰਨ tcc_ਲੜੀਵਾਰ(TCCState *s, ਪੂਰਨ argc, ਅੱਖਰ **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI ਪੂਰਨ tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI ਖਾਲੀ *tcc_get_ਚਿੰਨ੍ਹ(TCCState *s, ਅਚਲ ਅੱਖਰ *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI ਖਾਲੀ tcc_list_symbols(TCCState *s, ਖਾਲੀ *ctx,
    ਖਾਲੀ (*ਚਿੰਨ੍ਹ_cb)(ਖਾਲੀ *ctx, ਅਚਲ ਅੱਖਰ *name, ਅਚਲ ਖਾਲੀ *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI ਖਾਲੀ *_tcc_setjmp(TCCState *s1, ਖਾਲੀ *jmp_buf, ਖਾਲੀ *ਸਿਖਰ_func, ਖਾਲੀ *longjmp);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ TCCBtFunc(ਖਾਲੀ *udata, ਖਾਲੀ *pc, ਅਚਲ ਅੱਖਰ *file, ਪੂਰਨ ਸਤਰ, ਅਚਲ ਅੱਖਰ* func, ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ);
LIBTCCAPI ਖਾਲੀ tcc_ਸੈੱਟ_backtrace_func(TCCState *s1, ਖਾਲੀ* userdata, TCCBtFunc*);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
