#अगर_अघोषित LIBTCC_H
#घोषणा LIBTCC_H

#अगर_अघोषित LIBTCCAPI
# define LIBTCCAPI
#पूर्ण_अगर

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
प्रकार व्योम *TCCReallocFunc(व्योम *ptr, अचिन्हित दीर्घ आकार);
LIBTCCAPI व्योम tcc_set_realloc(TCCReallocFunc *my_realloc);

/*****************************/
प्रकार काष्ठा TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(व्योम);

/* free a TCC compilation context */
LIBTCCAPI व्योम tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI व्योम tcc_set_lib_path(TCCState *s, स्थिर अक्षर *path);

/* set error/warning callback (optional) */
प्रकार व्योम TCCErrorFunc(व्योम *opaque, स्थिर अक्षर *संदेश);
LIBTCCAPI व्योम tcc_set_error_func(TCCState *s, व्योम *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI पूर्णांक tcc_set_options(TCCState *s, स्थिर अक्षर *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI पूर्णांक tcc_add_include_path(TCCState *s, स्थिर अक्षर *pathname);

/* add in system include path */
LIBTCCAPI पूर्णांक tcc_add_sysinclude_path(TCCState *s, स्थिर अक्षर *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI व्योम tcc_define_प्रतीक(TCCState *s, स्थिर अक्षर *sym, स्थिर अक्षर *मूल्य);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI व्योम tcc_undefine_प्रतीक(TCCState *s, स्थिर अक्षर *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI पूर्णांक tcc_add_file(TCCState *s, स्थिर अक्षर *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI पूर्णांक tcc_compile_string(TCCState *s, स्थिर अक्षर *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI पूर्णांक tcc_set_output_type(TCCState *s, पूर्णांक output_type);
#घोषणा TCC_OUTPUT_MEMORY   1 /* output will be run in memory */
#घोषणा TCC_OUTPUT_EXE      2 /* executable file */
#घोषणा TCC_OUTPUT_DLL      4 /* dynamic library */
#घोषणा TCC_OUTPUT_OBJ      3 /* object file */
#घोषणा TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI पूर्णांक tcc_add_library_path(TCCState *s, स्थिर अक्षर *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI पूर्णांक tcc_add_library(TCCState *s, स्थिर अक्षर *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI पूर्णांक tcc_add_प्रतीक(TCCState *s, स्थिर अक्षर *name, स्थिर व्योम *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI पूर्णांक tcc_output_file(TCCState *s, स्थिर अक्षर *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI पूर्णांक tcc_run(TCCState *s, पूर्णांक argc, अक्षर **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI पूर्णांक tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI व्योम *tcc_get_प्रतीक(TCCState *s, स्थिर अक्षर *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI व्योम tcc_list_symbols(TCCState *s, व्योम *ctx,
    व्योम (*प्रतीक_cb)(व्योम *ctx, स्थिर अक्षर *name, स्थिर व्योम *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI व्योम *_tcc_setjmp(TCCState *s1, व्योम *लाँघ_बफ, व्योम *शीर्ष_func, व्योम *दीर्घ_लाँघ);
#घोषणा tcc_setjmp(s1,jb,f) बनाओ_लाँघ(_tcc_setjmp(s1, jb, f, दीर्घ_लाँघ))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
प्रकार पूर्णांक TCCBtFunc(व्योम *udata, व्योम *pc, स्थिर अक्षर *file, पूर्णांक पंक्ति_2, स्थिर अक्षर* func, स्थिर अक्षर *संदेश);
LIBTCCAPI व्योम tcc_set_backtrace_func(TCCState *s1, व्योम* userdata, TCCBtFunc*);

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#पूर्ण_अगर
