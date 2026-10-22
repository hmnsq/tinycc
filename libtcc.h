#నిర్వచితం_కాకపోతే LIBTCC_H
#నిర్వచించు LIBTCC_H

#నిర్వచితం_కాకపోతే LIBTCCAPI
# define LIBTCCAPI
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
రకనిర్వచనం శూన్య *TCCReallocFunc(శూన్య *ptr, గుర్తులేని దీర్ఘ కొలత);
LIBTCCAPI శూన్య tcc_సమితి_realloc(TCCReallocFunc *my_realloc);

/*****************************/
రకనిర్వచనం నిర్మాణం TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(శూన్య);

/* free a TCC compilation context */
LIBTCCAPI శూన్య tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI శూన్య tcc_సమితి_lib_మార్గం(TCCState *s, స్థిరరాశి అక్షరం *మార్గం);

/* set error/warning callback (optional) */
రకనిర్వచనం శూన్య TCCErrorFunc(శూన్య *opaque, స్థిరరాశి అక్షరం *సందేశం);
LIBTCCAPI శూన్య tcc_సమితి_error_func(TCCState *s, శూన్య *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI పూర్ణాంకం tcc_సమితి_options(TCCState *s, స్థిరరాశి అక్షరం *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI పూర్ణాంకం tcc_కూడు_include_మార్గం(TCCState *s, స్థిరరాశి అక్షరం *pathname);

/* add in system include path */
LIBTCCAPI పూర్ణాంకం tcc_కూడు_sysinclude_మార్గం(TCCState *s, స్థిరరాశి అక్షరం *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI శూన్య tcc_define_చిహ్నం(TCCState *s, స్థిరరాశి అక్షరం *sym, స్థిరరాశి అక్షరం *విలువ);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI శూన్య tcc_undefine_చిహ్నం(TCCState *s, స్థిరరాశి అక్షరం *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI పూర్ణాంకం tcc_కూడు_file(TCCState *s, స్థిరరాశి అక్షరం *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI పూర్ణాంకం tcc_compile_string(TCCState *s, స్థిరరాశి అక్షరం *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI పూర్ణాంకం tcc_సమితి_output_type(TCCState *s, పూర్ణాంకం output_type);
#నిర్వచించు TCC_OUTPUT_జ్ఞాపకం   1 /* output will be run in memory */
#నిర్వచించు TCC_OUTPUT_EXE      2 /* executable file */
#నిర్వచించు TCC_OUTPUT_DLL      4 /* dynamic library */
#నిర్వచించు TCC_OUTPUT_OBJ      3 /* object file */
#నిర్వచించు TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI పూర్ణాంకం tcc_కూడు_library_మార్గం(TCCState *s, స్థిరరాశి అక్షరం *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI పూర్ణాంకం tcc_కూడు_library(TCCState *s, స్థిరరాశి అక్షరం *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI పూర్ణాంకం tcc_కూడు_చిహ్నం(TCCState *s, స్థిరరాశి అక్షరం *name, స్థిరరాశి శూన్య *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI పూర్ణాంకం tcc_output_file(TCCState *s, స్థిరరాశి అక్షరం *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI పూర్ణాంకం tcc_నిరంతరం(TCCState *s, పూర్ణాంకం argc, అక్షరం **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI పూర్ణాంకం tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI శూన్య *tcc_get_చిహ్నం(TCCState *s, స్థిరరాశి అక్షరం *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI శూన్య tcc_list_symbols(TCCState *s, శూన్య *ctx,
    శూన్య (*చిహ్నం_cb)(శూన్య *ctx, స్థిరరాశి అక్షరం *name, స్థిరరాశి శూన్య *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI శూన్య *_tcc_setjmp(TCCState *s1, శూన్య *jmp_buf, శూన్య *శిఖరం_func, శూన్య *longjmp);
#నిర్వచించు tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
రకనిర్వచనం పూర్ణాంకం TCCBtFunc(శూన్య *udata, శూన్య *pc, స్థిరరాశి అక్షరం *file, పూర్ణాంకం పంక్తి, స్థిరరాశి అక్షరం* func, స్థిరరాశి అక్షరం *సందేశం);
LIBTCCAPI శూన్య tcc_సమితి_backtrace_func(TCCState *s1, శూన్య* userdata, TCCBtFunc*);

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అయితే_ముగింపు
