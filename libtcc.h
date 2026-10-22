#ifndef LIBTCC_H
#define LIBTCC_H

#ifndef LIBTCCAPI
# define LIBTCCAPI
#endif

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ *TCCReallocFunc(ಶೂನ್ಯ *ptr, unsigned long size);
LIBTCCAPI ಶೂನ್ಯ tcc_set_realloc(TCCReallocFunc *my_realloc);

/*****************************/
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(ಶೂನ್ಯ);

/* free a TCC compilation context */
LIBTCCAPI ಶೂನ್ಯ tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI ಶೂನ್ಯ tcc_set_lib_path(TCCState *s, ಧ್ರುವ ವರ್ಣ *path);

/* set error/warning callback (optional) */
ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ TCCErrorFunc(ಶೂನ್ಯ *opaque, ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ);
LIBTCCAPI ಶೂನ್ಯ tcc_set_error_func(TCCState *s, ಶೂನ್ಯ *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_set_options(TCCState *s, ಧ್ರುವ ವರ್ಣ *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_add_include_path(TCCState *s, ಧ್ರುವ ವರ್ಣ *pathname);

/* add in system include path */
LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_add_sysinclude_path(TCCState *s, ಧ್ರುವ ವರ್ಣ *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI ಶೂನ್ಯ tcc_define_ಚಿಹ್ನೆ(TCCState *s, ಧ್ರುವ ವರ್ಣ *sym, ಧ್ರುವ ವರ್ಣ *ಮೌಲ್ಯ);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI ಶೂನ್ಯ tcc_undefine_ಚಿಹ್ನೆ(TCCState *s, ಧ್ರುವ ವರ್ಣ *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_add_file(TCCState *s, ಧ್ರುವ ವರ್ಣ *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_compile_string(TCCState *s, ಧ್ರುವ ವರ್ಣ *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_set_output_type(TCCState *s, ಪೂರ್ಣಾಙ್ಕ output_type);
#define TCC_OUTPUT_MEMORY   1 /* output will be run in memory */
#define TCC_OUTPUT_EXE      2 /* executable file */
#define TCC_OUTPUT_DLL      4 /* dynamic library */
#define TCC_OUTPUT_OBJ      3 /* object file */
#define TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_add_library_path(TCCState *s, ಧ್ರುವ ವರ್ಣ *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_add_library(TCCState *s, ಧ್ರುವ ವರ್ಣ *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_add_ಚಿಹ್ನೆ(TCCState *s, ಧ್ರುವ ವರ್ಣ *name, ಧ್ರುವ ಶೂನ್ಯ *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_output_file(TCCState *s, ಧ್ರುವ ವರ್ಣ *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_run(TCCState *s, ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI ಶೂನ್ಯ *tcc_get_ಚಿಹ್ನೆ(TCCState *s, ಧ್ರುವ ವರ್ಣ *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI ಶೂನ್ಯ tcc_list_symbols(TCCState *s, ಶೂನ್ಯ *ctx,
    ಶೂನ್ಯ (*ಚಿಹ್ನೆ_cb)(ಶೂನ್ಯ *ctx, ಧ್ರುವ ವರ್ಣ *name, ಧ್ರುವ ಶೂನ್ಯ *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI ಶೂನ್ಯ *_tcc_setjmp(TCCState *s1, ಶೂನ್ಯ *jmp_buf, ಶೂನ್ಯ *ತುದಿ_func, ಶೂನ್ಯ *longjmp);
#define tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ TCCBtFunc(ಶೂನ್ಯ *udata, ಶೂನ್ಯ *pc, ಧ್ರುವ ವರ್ಣ *file, ಪೂರ್ಣಾಙ್ಕ ಸಾಲು, ಧ್ರುವ ವರ್ಣ* func, ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ);
LIBTCCAPI ಶೂನ್ಯ tcc_set_backtrace_func(TCCState *s1, ಶೂನ್ಯ* userdata, TCCBtFunc*);

#ifdef __cplusplus
}
#endif

#endif
