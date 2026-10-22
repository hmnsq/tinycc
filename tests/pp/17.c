#घोषणा STR1(u) # u
#घोषणा pass(a) a
#घोषणा __ASM_REG(reg)         STR1(one##reg)
#घोषणा _ASM_DX         __ASM_REG(tok)
X162 pass(__ASM_REG(tok))
X161 pass(_ASM_DX)
X163 pass(STR1(one##tok))

X170 pass(x ## y)
X171 pass(x pass(##) y)

#घोषणा Y(x) Z(x)
#घोषणा X Y
X180 वापस X(X(1));
