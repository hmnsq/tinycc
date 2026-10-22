//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#아니면
# define _(s) _##s
#endif

extern void (*_(_init_array_start)[]) (정수 argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_init_array_end)[]) (정수 argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);

static void run_ctors(정수 argc, _TCHAR **argv, _TCHAR **env)
{
    정수 i = 0;
    동안 (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

static void run_dtors(void)
{
    정수 i = 0;
    동안 (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
