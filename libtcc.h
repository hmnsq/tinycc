#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ LIBTCC_H
#ವ್ಯಾಖ್ಯಾನಿಸು LIBTCC_H

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ LIBTCCAPI
# define LIBTCCAPI
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ *TCCReallocFunc(ಶೂನ್ಯ *ptr, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2);
LIBTCCAPI ಶೂನ್ಯ tcc_ಗಣ_realloc(TCCReallocFunc *my_realloc);

/*****************************/
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(ಶೂನ್ಯ);

/* free a TCC compilation context */
LIBTCCAPI ಶೂನ್ಯ tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI ಶೂನ್ಯ tcc_ಗಣ_lib_ಮಾರ್ಗ(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮಾರ್ಗ);

/* set error/warning callback (optional) */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ TCCErrorFunc(ಶೂನ್ಯ *opaque, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ);
LIBTCCAPI ಶೂನ್ಯ tcc_ಗಣ_error_func(TCCState *s, ಶೂನ್ಯ *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಗಣ_options(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_include_ಮಾರ್ಗ(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *pathname);

/* add in system include path */
LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_sysinclude_ಮಾರ್ಗ(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI ಶೂನ್ಯ tcc_define_ಚಿಹ್ನೆ(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *sym, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮೌಲ್ಯ);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI ಶೂನ್ಯ tcc_undefine_ಚಿಹ್ನೆ(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_file(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_compile_string(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಗಣ_output_type(TCCState *s, ಪೂರ್ಣಾಂಕ output_type);
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_OUTPUT_ಸ್ಮರಣೆ   1 /* output will be run in memory */
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_OUTPUT_EXE      2 /* executable file */
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_OUTPUT_DLL      4 /* dynamic library */
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_OUTPUT_OBJ      3 /* object file */
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_library_ಮಾರ್ಗ(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_library(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_ಚಿಹ್ನೆ(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_output_file(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಸತತ(TCCState *s, ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI ಶೂನ್ಯ *tcc_get_ಚಿಹ್ನೆ(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI ಶೂನ್ಯ tcc_list_symbols(TCCState *s, ಶೂನ್ಯ *ctx,
    ಶೂನ್ಯ (*ಚಿಹ್ನೆ_cb)(ಶೂನ್ಯ *ctx, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI ಶೂನ್ಯ *_tcc_setjmp(TCCState *s1, ಶೂನ್ಯ *jmp_buf, ಶೂನ್ಯ *ತುದಿ_func, ಶೂನ್ಯ *longjmp);
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ TCCBtFunc(ಶೂನ್ಯ *udata, ಶೂನ್ಯ *pc, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *file, ಪೂರ್ಣಾಂಕ ಸಾಲು, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* func, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ);
LIBTCCAPI ಶೂನ್ಯ tcc_ಗಣ_backtrace_func(TCCState *s1, ಶೂನ್ಯ* userdata, TCCBtFunc*);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ
