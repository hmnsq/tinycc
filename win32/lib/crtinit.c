//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#มิฉะนั้น
# define _(s) _##s
#endif

extern void (*_(_init_array_start)[]) (จำนวนเต็ม argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_init_array_end)[]) (จำนวนเต็ม argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);

static void run_ctors(จำนวนเต็ม argc, _TCHAR **argv, _TCHAR **env)
{
    จำนวนเต็ม i = 0;
    ขณะ (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

static void run_dtors(void)
{
    จำนวนเต็ม i = 0;
    ขณะ (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
