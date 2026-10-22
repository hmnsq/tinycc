#यदि_अपरिभाषितम् LIBTCC_H
#परिभाषय LIBTCC_H

#यदि_अपरिभाषितम् LIBTCCAPI
# define LIBTCCAPI
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
प्रकारनिर्देश शून्य *TCCReallocFunc(शून्य *ptr, अचिह्नित दीर्घ आकार);
LIBTCCAPI शून्य tcc_समुच्चयः_realloc(TCCReallocFunc *my_realloc);

/*****************************/
प्रकारनिर्देश संरचना TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(शून्य);

/* free a TCC compilation context */
LIBTCCAPI शून्य tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI शून्य tcc_समुच्चयः_lib_मार्गः(TCCState *s, ध्रुव वर्ण *मार्गः);

/* set error/warning callback (optional) */
प्रकारनिर्देश शून्य TCCErrorFunc(शून्य *opaque, ध्रुव वर्ण *सन्देशः);
LIBTCCAPI शून्य tcc_समुच्चयः_error_func(TCCState *s, शून्य *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI पूर्णाङ्क tcc_समुच्चयः_options(TCCState *s, ध्रुव वर्ण *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI पूर्णाङ्क tcc_सङ्कलय_include_मार्गः(TCCState *s, ध्रुव वर्ण *pathname);

/* add in system include path */
LIBTCCAPI पूर्णाङ्क tcc_सङ्कलय_sysinclude_मार्गः(TCCState *s, ध्रुव वर्ण *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI शून्य tcc_define_चिह्नम्(TCCState *s, ध्रुव वर्ण *sym, ध्रुव वर्ण *मानम्);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI शून्य tcc_undefine_चिह्नम्(TCCState *s, ध्रुव वर्ण *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI पूर्णाङ्क tcc_सङ्कलय_file(TCCState *s, ध्रुव वर्ण *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI पूर्णाङ्क tcc_compile_string(TCCState *s, ध्रुव वर्ण *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI पूर्णाङ्क tcc_समुच्चयः_output_type(TCCState *s, पूर्णाङ्क output_type);
#परिभाषय TCC_OUTPUT_स्मृतिः   1 /* output will be run in memory */
#परिभाषय TCC_OUTPUT_EXE      2 /* executable file */
#परिभाषय TCC_OUTPUT_DLL      4 /* dynamic library */
#परिभाषय TCC_OUTPUT_OBJ      3 /* object file */
#परिभाषय TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI पूर्णाङ्क tcc_सङ्कलय_library_मार्गः(TCCState *s, ध्रुव वर्ण *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI पूर्णाङ्क tcc_सङ्कलय_library(TCCState *s, ध्रुव वर्ण *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI पूर्णाङ्क tcc_सङ्कलय_चिह्नम्(TCCState *s, ध्रुव वर्ण *name, ध्रुव शून्य *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI पूर्णाङ्क tcc_output_file(TCCState *s, ध्रुव वर्ण *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI पूर्णाङ्क tcc_सततम्(TCCState *s, पूर्णाङ्क argc, वर्ण **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI पूर्णाङ्क tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI शून्य *tcc_get_चिह्नम्(TCCState *s, ध्रुव वर्ण *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI शून्य tcc_list_symbols(TCCState *s, शून्य *ctx,
    शून्य (*चिह्नम्_cb)(शून्य *ctx, ध्रुव वर्ण *name, ध्रुव शून्य *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI शून्य *_tcc_setjmp(TCCState *s1, शून्य *jmp_buf, शून्य *शिखरम्_func, शून्य *longjmp);
#परिभाषय tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
प्रकारनिर्देश पूर्णाङ्क TCCBtFunc(शून्य *udata, शून्य *pc, ध्रुव वर्ण *file, पूर्णाङ्क पङ्क्तिः, ध्रुव वर्ण* func, ध्रुव वर्ण *सन्देशः);
LIBTCCAPI शून्य tcc_समुच्चयः_backtrace_func(TCCState *s1, शून्य* userdata, TCCBtFunc*);

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#यदि_अन्तः
