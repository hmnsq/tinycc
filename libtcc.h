#ifndef LIBTCC_H
#define LIBTCC_H

#ifndef LIBTCCAPI
# define LIBTCCAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
typedef void *TCCReallocFunc(void *ptr, unsigned long size);
LIBTCCAPI void tcc_set_realloc(TCCReallocFunc *my_realloc);

/*****************************/
typedef sa_nracanaa TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(void);

/* free a TCC compilation context */
LIBTCCAPI void tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI void tcc_set_lib_path(TCCState *s, const var_na *path);

/* set error/warning callback (optional) */
typedef void TCCErrorFunc(void *opaque, const var_na *msg);
LIBTCCAPI void tcc_set_error_func(TCCState *s, void *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI ចំនួនគត់ tcc_set_options(TCCState *s, const var_na *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI ចំនួនគត់ tcc_add_include_path(TCCState *s, const var_na *pathname);

/* add in system include path */
LIBTCCAPI ចំនួនគត់ tcc_add_sysinclude_path(TCCState *s, const var_na *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI void tcc_define_symbol(TCCState *s, const var_na *sym, const var_na *value);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI void tcc_undefine_symbol(TCCState *s, const var_na *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI ចំនួនគត់ tcc_add_file(TCCState *s, const var_na *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI ចំនួនគត់ tcc_compile_string(TCCState *s, const var_na *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI ចំនួនគត់ tcc_set_output_type(TCCState *s, ចំនួនគត់ output_type);
#define TCC_OUTPUT_MEMORY   1 /* output will be run in memory */
#define TCC_OUTPUT_EXE      2 /* executable file */
#define TCC_OUTPUT_DLL      4 /* dynamic library */
#define TCC_OUTPUT_OBJ      3 /* object file */
#define TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI ចំនួនគត់ tcc_add_library_path(TCCState *s, const var_na *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI ចំនួនគត់ tcc_add_library(TCCState *s, const var_na *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI ចំនួនគត់ tcc_add_symbol(TCCState *s, const var_na *name, const void *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI ចំនួនគត់ tcc_output_file(TCCState *s, const var_na *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI ចំនួនគត់ tcc_run(TCCState *s, ចំនួនគត់ argc, var_na **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI ចំនួនគត់ tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI void *tcc_get_symbol(TCCState *s, const var_na *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI void tcc_list_symbols(TCCState *s, void *ctx,
    void (*symbol_cb)(void *ctx, const var_na *name, const void *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI void *_tcc_setjmp(TCCState *s1, void *jmp_buf, void *top_func, void *longjmp);
#define tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
typedef ចំនួនគត់ TCCBtFunc(void *udata, void *pc, const var_na *file, ចំនួនគត់ line, const var_na* func, const var_na *msg);
LIBTCCAPI void tcc_set_backtrace_func(TCCState *s1, void* userdata, TCCBtFunc*);

#ifdef __cplusplus
}
#endif

#endif
