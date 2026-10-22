#تعریف_کن STR1(u) # u
#تعریف_کن pass(a) a
#تعریف_کن __ASM_REG(reg)         STR1(one##reg)
#تعریف_کن _ASM_DX         __ASM_REG(tok)
X162 pass(__ASM_REG(tok))
X161 pass(_ASM_DX)
X163 pass(STR1(one##tok))

X170 pass(x ## y)
X171 pass(x pass(##) y)

#تعریف_کن Y(x) Z(x)
#تعریف_کن X Y
X180 أرجع X(X(1));
