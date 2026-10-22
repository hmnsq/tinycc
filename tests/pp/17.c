#تعریف_کړه STR1(u) # u
#تعریف_کړه pass(a) a
#تعریف_کړه __ASM_REG(reg)         STR1(one##reg)
#تعریف_کړه _ASM_DX         __ASM_REG(tok)
X162 pass(__ASM_REG(tok))
X161 pass(_ASM_DX)
X163 pass(STR1(one##tok))

X170 pass(x ## y)
X171 pass(x pass(##) y)

#تعریف_کړه Y(x) Z(x)
#تعریف_کړه X Y
X180 أرجع X(X(1));
