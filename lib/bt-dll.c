/* ------------------------------------------------------------- */
/* stubs for calling bcheck functions from a dll. */

#ਅਨ੍ਤਰ੍ਭਾਵ <windows.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REDIR_ALL \
  REDIR(__bt_init) \
  REDIR(__bt_exit) \
  REDIR(tcc_backtrace) \
  \
  REDIR(__bound_ptr_add) \
  REDIR(__bound_ptr_indir1) \
  REDIR(__bound_ptr_indir2) \
  REDIR(__bound_ptr_indir4) \
  REDIR(__bound_ptr_indir8) \
  REDIR(__bound_ptr_indir12) \
  REDIR(__bound_ptr_indir16) \
  REDIR(__bound_local_new) \
  REDIR(__bound_local_delete) \
  REDIR(__bound_new_region) \
  \
  REDIR(__bound_free) \
  REDIR(__bound_malloc) \
  REDIR(__bound_realloc) \
  REDIR(__bound_memcpy) \
  REDIR(__bound_memcmp) \
  REDIR(__bound_memmove) \
  REDIR(__bound_memset) \
  REDIR(__bound_strlen) \
  REDIR(__bound_strcpy) \
  REDIR(__bound_strncpy) \
  REDIR(__bound_strcmp) \
  REDIR(__bound_strncmp) \
  REDIR(__bound_strcat) \
  REDIR(__bound_strchr) \
  REDIR(__bound_strdup) \
  REDIR(__bound_strncat) \
  REDIR(__bound_strrchr) \
  REDIR(__bound_setjmp) \
  REDIR(__bound_longjmp)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __leading_underscore
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _(s) "_"#s
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _(s) #s
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REDIR(s) ਖਾਲੀ *s;
ਸਥਿਰ ਬਣਤਰ { REDIR_ALL } all_ptrs;
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ REDIR

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REDIR(s) #s"\0"
ਸਥਿਰ ਅਚਲ ਅੱਖਰ all_ਨਾਂ[] = REDIR_ALL;
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ REDIR

#ਜੇ __aarch64__
# define REDIR(s) \
    __asm__(".global "_(s)";"_(s)":"); \
    __asm__(".int 0x58000090"); /* ldr x16, [pc, #16] */ \
    __asm__(".int 0xf9400210"); /* ldr x16, [x16] */ \
    __asm__(".int 0xd61f0200"); /* br x16 */ \
    __asm__(".int 0xd503201f"); /* nop for alignment */ \
    __asm__(".quad all_ptrs + (. - all_jmps - 16) / 24 * 8"); \
    __asm__(".type "_(s)",function\n.size "_(s)",.-"_(s));

    __asm__(".text\n.align 8\nall_jmps:");
    REDIR_ALL
#ਨਹੀਂਤਾਂ
# define REDIR(s) \
    __asm__(".global "_(s)";"_(s)":"); ਜਾਓ *all_ptrs.s;
    ਸਥਿਰ ਖਾਲੀ all_jmps() { REDIR_ALL }
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ REDIR

ਖਾਲੀ __bt_init_dll(ਪੂਰਨ bcheck)
{
    ਅਚਲ ਅੱਖਰ *s = all_ਨਾਂ;
    ਖਾਲੀ **p = (ਖਾਲੀ**)&all_ptrs;
    ਕਰੋ {
        *p = (ਖਾਲੀ*)Get_Proc_ਪਤਾ(GetModuleHandle(ਨਿਰਾ), (ਅੱਖਰ*)s);
        ਜੇ (ਨਿਰਾ == *p) {
            ਅੱਖਰ buf[100];
            sprintf(buf,
                "Error: function '%s()' not found in executable. "
                "(Need -bt or -b for linking the exe.)", s);
            ਜੇ (GetStdHandle(STD_ERROR_HANDLE))
                fprintf(stderr, "TCC/BCHECK: %s\n", buf), fflush(stderr);
            ਨਹੀਂਤਾਂ
                ਸੁਨੇਹਾ_Box(ਨਿਰਾ, buf, "TCC/BCHECK", MB_ICONERROR);
            ExitProcess(1);
        }
        s = strchr(s,'\0') + 1, ++p;
    } ਜਦੋਂ (*s && (bcheck || p < &all_ptrs.__bound_ptr_add));
}
