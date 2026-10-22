//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#وإلا
# define _(s) _##s
#endif

خارجي فراغ (*_(_init_array_start)[]) (صحيح argc, _TCHAR **argv, _TCHAR **envp);
خارجي فراغ (*_(_init_array_end)[]) (صحيح argc, _TCHAR **argv, _TCHAR **envp);
خارجي فراغ (*_(_fini_array_start)[]) (فراغ);
خارجي فراغ (*_(_fini_array_end)[]) (فراغ);

ساكن فراغ run_ctors(صحيح argc, _TCHAR **argv, _TCHAR **env)
{
    صحيح i = 0;
    طالما (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

ساكن فراغ run_dtors(فراغ)
{
    صحيح i = 0;
    طالما (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
