//+---------------------------------------------------------------------------

#اگر_تعریف_شده __leading_underscore
# define _(s) s
#وإلا
# define _(s) _##s
#پایان_اگر

خارجي فراغ (*_(init_array_شروع)[]) (صحيح argc, _TCHAR **argv, _TCHAR **envp);
خارجي فراغ (*_(init_array_انتها)[]) (صحيح argc, _TCHAR **argv, _TCHAR **envp);
خارجي فراغ (*_(fini_array_شروع)[]) (فراغ);
خارجي فراغ (*_(fini_array_انتها)[]) (فراغ);

ساكن فراغ پیاپی_ctors(صحيح argc, _TCHAR **argv, _TCHAR **env)
{
    صحيح i = 0;
    طالما (&_(init_array_شروع)[i] != _(init_array_انتها))
        (*_(init_array_شروع)[i++])(argc, argv, env);
}

ساكن فراغ پیاپی_dtors(فراغ)
{
    صحيح i = 0;
    طالما (&_(fini_array_انتها)[i] != _(fini_array_شروع))
        (*_(fini_array_انتها)[--i])();
}
