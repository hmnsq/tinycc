/* ---------------------------------------------- */
/* get_pc_thunk.S */

#ifdef __leading_underscore
# define _(s) _##s
#else
# define _(s) s
#endif

/* ---------------------------------------------- */
        .text

        .globl _(__x86.get_pc_thunk.ax)
        .hidden _(__x86.get_pc_thunk.ax)
_(__x86.get_pc_thunk.ax):
        चालय (%esp),%eax
        प्रत्यागच्छ
        .size _(__x86.get_pc_thunk.ax), .-_(__x86.get_pc_thunk.ax)

        .globl _(__x86.get_pc_thunk.bx)
        .hidden _(__x86.get_pc_thunk.bx)
_(__x86.get_pc_thunk.bx):
        चालय (%esp),%ebx
        प्रत्यागच्छ
        .size _(__x86.get_pc_thunk.bx), .-_(__x86.get_pc_thunk.bx)

        .globl _(__x86.get_pc_thunk.cx)
        .hidden _(__x86.get_pc_thunk.cx)
_(__x86.get_pc_thunk.cx):
        चालय (%esp),%ecx
        प्रत्यागच्छ
        .size _(__x86.get_pc_thunk.cx), .-_(__x86.get_pc_thunk.cx)

        .globl _(__x86.get_pc_thunk.dx)
        .hidden _(__x86.get_pc_thunk.dx)
_(__x86.get_pc_thunk.dx):
        चालय (%esp),%edx
        प्रत्यागच्छ
        .size _(__x86.get_pc_thunk.dx), .-_(__x86.get_pc_thunk.dx)
