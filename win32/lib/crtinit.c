//+---------------------------------------------------------------------------

#جيڪڏهن_وصف_ٿيل __leading_underscore
# define _(s) s
#وإلا
# define _(s) _##s
#جيڪڏهن_پورو

خارجي فراغ (*_(init_array_شروعات)[]) (صحيح argc, _TCHAR **argv, _TCHAR **envp);
خارجي فراغ (*_(init_array_پڇاڙي)[]) (صحيح argc, _TCHAR **argv, _TCHAR **envp);
خارجي فراغ (*_(fini_array_شروعات)[]) (فراغ);
خارجي فراغ (*_(fini_array_پڇاڙي)[]) (فراغ);

ساكن فراغ لاڳيتو_ctors(صحيح argc, _TCHAR **argv, _TCHAR **env)
{
    صحيح i = 0;
    طالما (&_(init_array_شروعات)[i] != _(init_array_پڇاڙي))
        (*_(init_array_شروعات)[i++])(argc, argv, env);
}

ساكن فراغ لاڳيتو_dtors(فراغ)
{
    صحيح i = 0;
    طالما (&_(fini_array_پڇاڙي)[i] != _(fini_array_شروعات))
        (*_(fini_array_پڇاڙي)[--i])();
}
