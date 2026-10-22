#تعریف_کرو STR1(u) # u
#تعریف_کرو pass(a) a
#تعریف_کرو __ASM_REG(reg)         STR1(one##reg)
#تعریف_کرو _ASM_DX         __ASM_REG(tok)
X162 pass(__ASM_REG(tok))
X161 pass(_ASM_DX)
X163 pass(STR1(one##tok))

X170 pass(x ## y)
X171 pass(x pass(##) y)

#تعریف_کرو Y(x) Z(x)
#تعریف_کرو X Y
X180 واپس X(X(1));
