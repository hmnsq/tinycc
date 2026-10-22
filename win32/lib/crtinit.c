//+---------------------------------------------------------------------------

#جے_تعریف_شدہ __leading_underscore
# define _(s) s
#وإلا
# define _(s) _##s
#جے_انت

خارجي فراغ (*_(init_array_شروع)[]) (صحيح argc, _TCHAR **argv, _TCHAR **envp);
خارجي فراغ (*_(init_array_سرا)[]) (صحيح argc, _TCHAR **argv, _TCHAR **envp);
خارجي فراغ (*_(fini_array_شروع)[]) (فراغ);
خارجي فراغ (*_(fini_array_سرا)[]) (فراغ);

ساكن فراغ لگاتار_ctors(صحيح argc, _TCHAR **argv, _TCHAR **env)
{
    صحيح i = 0;
    طالما (&_(init_array_شروع)[i] != _(init_array_سرا))
        (*_(init_array_شروع)[i++])(argc, argv, env);
}

ساكن فراغ لگاتار_dtors(فراغ)
{
    صحيح i = 0;
    طالما (&_(fini_array_سرا)[i] != _(fini_array_شروع))
        (*_(fini_array_سرا)[--i])();
}
