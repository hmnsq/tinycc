//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#không_thì
# define _(s) _##s
#endif

extern void (*_(_init_array_start)[]) (số_nguyên argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_init_array_end)[]) (số_nguyên argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);

static void run_ctors(số_nguyên argc, _TCHAR **argv, _TCHAR **env)
{
    số_nguyên i = 0;
    trong_khi (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

static void run_dtors(void)
{
    số_nguyên i = 0;
    trong_khi (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
