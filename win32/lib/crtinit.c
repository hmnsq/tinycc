//+---------------------------------------------------------------------------

#اگر_تعریف_شدہ __leading_underscore
# define _(s) s
#ورنہ
# define _(s) _##s
#اگر_ختم

خارجی خالی (*_(init_array_آغاز)[]) (صحیح argc, _TCHAR **argv, _TCHAR **envp);
خارجی خالی (*_(init_array_انتہا)[]) (صحیح argc, _TCHAR **argv, _TCHAR **envp);
خارجی خالی (*_(fini_array_آغاز)[]) (خالی);
خارجی خالی (*_(fini_array_انتہا)[]) (خالی);

ساکن خالی تسلسل_ctors(صحیح argc, _TCHAR **argv, _TCHAR **env)
{
    صحیح i = 0;
    جب (&_(init_array_آغاز)[i] != _(init_array_انتہا))
        (*_(init_array_آغاز)[i++])(argc, argv, env);
}

ساکن خالی تسلسل_dtors(خالی)
{
    صحیح i = 0;
    جب (&_(fini_array_انتہا)[i] != _(fini_array_آغاز))
        (*_(fini_array_انتہا)[--i])();
}
