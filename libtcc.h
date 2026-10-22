#ifndef LIBTCC_H
#define LIBTCC_H

#ifndef LIBTCCAPI
# define LIBTCCAPI
#endif

#ifdef __cplusplus
बाह्य "C" {
#endif

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
प्रकारव्याख्या शून्य *TCCReallocFunc(शून्य *ptr, अचिन्हित दीर्घ size);
LIBTCCAPI शून्य tcc_set_realloc(TCCReallocFunc *my_realloc);

/*****************************/
प्रकारव्याख्या संरचना TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(शून्य);

/* free a TCC compilation context */
LIBTCCAPI शून्य tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI शून्य tcc_set_lib_path(TCCState *s, स्थिरांक अक्षर *path);

/* set error/warning callback (optional) */
प्रकारव्याख्या शून्य TCCErrorFunc(शून्य *opaque, स्थिरांक अक्षर *संदेश);
LIBTCCAPI शून्य tcc_set_error_func(TCCState *s, शून्य *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI पूर्णांक tcc_set_options(TCCState *s, स्थिरांक अक्षर *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI पूर्णांक tcc_add_include_path(TCCState *s, स्थिरांक अक्षर *pathname);

/* add in system include path */
LIBTCCAPI पूर्णांक tcc_add_sysinclude_path(TCCState *s, स्थिरांक अक्षर *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI शून्य tcc_define_चिन्ह(TCCState *s, स्थिरांक अक्षर *sym, स्थिरांक अक्षर *मूल्य);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI शून्य tcc_undefine_चिन्ह(TCCState *s, स्थिरांक अक्षर *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI पूर्णांक tcc_add_file(TCCState *s, स्थिरांक अक्षर *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI पूर्णांक tcc_compile_string(TCCState *s, स्थिरांक अक्षर *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI पूर्णांक tcc_set_output_type(TCCState *s, पूर्णांक output_type);
#define TCC_OUTPUT_MEMORY   1 /* output will be run in memory */
#define TCC_OUTPUT_EXE      2 /* executable file */
#define TCC_OUTPUT_DLL      4 /* dynamic library */
#define TCC_OUTPUT_OBJ      3 /* object file */
#define TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI पूर्णांक tcc_add_library_path(TCCState *s, स्थिरांक अक्षर *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI पूर्णांक tcc_add_library(TCCState *s, स्थिरांक अक्षर *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI पूर्णांक tcc_add_चिन्ह(TCCState *s, स्थिरांक अक्षर *name, स्थिरांक शून्य *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI पूर्णांक tcc_output_file(TCCState *s, स्थिरांक अक्षर *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI पूर्णांक tcc_run(TCCState *s, पूर्णांक argc, अक्षर **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI पूर्णांक tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI शून्य *tcc_get_चिन्ह(TCCState *s, स्थिरांक अक्षर *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI शून्य tcc_list_symbols(TCCState *s, शून्य *ctx,
    शून्य (*चिन्ह_cb)(शून्य *ctx, स्थिरांक अक्षर *name, स्थिरांक शून्य *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI शून्य *_tcc_setjmp(TCCState *s1, शून्य *लाँघ_बफ, शून्य *शीर्ष_func, शून्य *दीर्घ_लाँघ);
#define tcc_setjmp(s1,jb,f) बनाओ_लाँघ(_tcc_setjmp(s1, jb, f, दीर्घ_लाँघ))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
प्रकारव्याख्या पूर्णांक TCCBtFunc(शून्य *udata, शून्य *pc, स्थिरांक अक्षर *file, पूर्णांक ओळ, स्थिरांक अक्षर* func, स्थिरांक अक्षर *संदेश);
LIBTCCAPI शून्य tcc_set_backtrace_func(TCCState *s1, शून्य* userdata, TCCBtFunc*);

#ifdef __cplusplus
}
#endif

#endif
