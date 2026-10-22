//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#иначе
# define _(s) _##s
#endif

extern void (*_(_init_array_start)[]) (целое argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_init_array_end)[]) (целое argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);

static void run_ctors(целое argc, _TCHAR **argv, _TCHAR **env)
{
    целое i = 0;
    пока (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

static void run_dtors(void)
{
    целое i = 0;
    пока (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
