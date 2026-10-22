/*
 *  ARM specific functions for TCC assembler
 *
 *  Copyright (c) 2001, 2002 Fabrice Bellard
 *  Copyright (c) 2020 Danny Milosavljevic
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ಗುರಿ_DEFS_ONLY

#ವ್ಯಾಖ್ಯಾನಿಸು CONFIG_TCC_ASM
#ವ್ಯಾಖ್ಯಾನಿಸು NB_ASM_REGS 16

ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಂಕ c);
ST_FUNC ಶೂನ್ಯ gen_le16(ಪೂರ್ಣಾಂಕ c);
ST_FUNC ಶೂನ್ಯ gen_le32(ಪೂರ್ಣಾಂಕ c);

/*************************************************************/
#ಇಲ್ಲದಿದ್ದರೆ
/*************************************************************/

#ವ್ಯಾಖ್ಯಾನಿಸು USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"

ಎಣಿಕೆ {
    OPT_REG32,
    OPT_REGSET32,
    OPT_IM8,
    OPT_IM8N,
    OPT_IM32,
    OPT_VREG32,
    OPT_VREG64,
};
#ವ್ಯಾಖ್ಯಾನಿಸು OP_REG32  (1 << OPT_REG32)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_VREG32 (1 << OPT_VREG32)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_VREG64 (1 << OPT_VREG64)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_REG    (OP_REG32 | OP_VREG32 | OP_VREG64)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_IM32   (1 << OPT_IM32)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_IM8   (1 << OPT_IM8)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_IM8N   (1 << OPT_IM8N)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_REGSET32  (1 << OPT_REGSET32)

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಕಾರ್ಯಾಂಶ {
    uint32_t type;
    ಒಕ್ಕೂಟ {
        uint8_t reg;
        uint16_t regset;
        ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
    };
} ಕಾರ್ಯಾಂಶ;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ asm_parse_vfp_regvar(ಪೂರ್ಣಾಂಕ t, ಪೂರ್ಣಾಂಕ double_precision)
{
    ಆದರೆ (double_precision) {
        ಆದರೆ (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            ಹಿಂತಿರುಗಿ t - TOK_ASM_d0;
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            ಹಿಂತಿರುಗಿ t - TOK_ASM_s0;
    }
    ಹಿಂತಿರುಗಿ -1;
}

/* Parse a text containing operand and store the result in OP */
ಸ್ಥಿರ ಶೂನ್ಯ parse_ಕಾರ್ಯಾಂಶ(TCCState *s1, ಕಾರ್ಯಾಂಶ *op)
{
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    ಆದರೆ (tok == '{') { // regset literal
        ಮುಂದಿನ(); // skip '{'
        ಆಗ (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            ಆದರೆ (reg == -1) {
                expect("register");
            } ಇಲ್ಲದಿದ್ದರೆ
                ಮುಂದಿನ(); // skip register name

            ಆದರೆ ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            ಆದರೆ (tok != ',')
                ನಿಲ್ಲಿಸು;
            ಮುಂದಿನ(); // skip ','
        }
        skip('}');
        ಆದರೆ (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } ಇಲ್ಲದಿದ್ದರೆ {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        ಹಿಂತಿರುಗಿ;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((reg = asm_parse_regvar(tok)) != -1) {
        ಮುಂದಿನ(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        ಹಿಂತಿರುಗಿ;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        ಮುಂದಿನ(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        ಹಿಂತಿರುಗಿ;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        ಮುಂದಿನ(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        ಹಿಂತಿರುಗಿ;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == '#' || tok == '$') {
        /* constant value */
        ಮುಂದಿನ(); // skip '#' or '$'
    }
    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    ಆದರೆ (!op->e.sym) {
        ಆದರೆ ((ಪೂರ್ಣಾಂಕ) op->e.v < 0 && (ಪೂರ್ಣಾಂಕ) op->e.v >= -255)
            op->type = OP_IM8N;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } ಇಲ್ಲದಿದ್ದರೆ
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಂಕ c)
{
    ಪೂರ್ಣಾಂಕ ind1;
    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ;
    ind1 = ind + 1;
    ಆದರೆ (ind1 > cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_allocated)
        section_realloc(cur_ಪಠ್ಯ_section, ind1);
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind] = c;
    ind = ind1;
}

ST_FUNC ಶೂನ್ಯ gen_le16 (ಪೂರ್ಣಾಂಕ i)
{
    g(i);
    g(i>>8);
}

ST_FUNC ಶೂನ್ಯ gen_le32 (ಪೂರ್ಣಾಂಕ i)
{
    ಪೂರ್ಣಾಂಕ ind1;
    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ;
    ind1 = ind + 4;
    ಆದರೆ (ind1 > cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_allocated)
        section_realloc(cur_ಪಠ್ಯ_section, ind1);
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind++] = i & 0xFF;
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind++] = (i >> 8) & 0xFF;
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind++] = (i >> 16) & 0xFF;
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC ಶೂನ್ಯ gen_expr32(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    gen_le32(pe->v);
}

ಸ್ಥಿರ uint32_t condition_ಸಂಕೇತ_ದ_token(ಪೂರ್ಣಾಂಕ token) {
    ಆದರೆ (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } ಇಲ್ಲದಿದ್ದರೆ
        ಹಿಂತಿರುಗಿ (token - TOK_ASM_nopeq) & 15;
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_opcode(ಪೂರ್ಣಾಂಕ token, uint32_t opcode) {
    gen_le32((condition_ಸಂಕೇತ_ದ_token(token) << 28) | opcode);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_coprocessor_opcode(uint32_t ಮೇಲಿನ_nibble, uint8_t cp_ಸಂಖ್ಯೆ, uint8_t cp_opcode, uint8_t cp_destination_ರಿಜಿಸ್ಟರ್, uint8_t cp_n_ಕಾರ್ಯಾಂಶ_ರಿಜಿಸ್ಟರ್, uint8_t cp_m_ಕಾರ್ಯಾಂಶ_ರಿಜಿಸ್ಟರ್, uint8_t cp_opcode2, ಪೂರ್ಣಾಂಕ inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    ಆದರೆ (inter_processor_transfer)
        opcode |= 1 << 4;
    //assert(cp_opcode < 16);
    opcode |= cp_opcode << 20;
    //assert(cp_n_operand_register < 16);
    opcode |= cp_n_ಕಾರ್ಯಾಂಶ_ರಿಜಿಸ್ಟರ್ << 16;
    //assert(cp_destination_register < 16);
    opcode |= cp_destination_ರಿಜಿಸ್ಟರ್ << 12;
    //assert(cp_number < 16);
    opcode |= cp_ಸಂಖ್ಯೆ << 8;
    //assert(cp_information < 8);
    opcode |= cp_opcode2 << 5;
    //assert(cp_m_operand_register < 16);
    opcode |= cp_m_ಕಾರ್ಯಾಂಶ_ರಿಜಿಸ್ಟರ್;
    asm_emit_unconditional_opcode((ಮೇಲಿನ_nibble << 28) | opcode);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_nullary_opcode(ಪೂರ್ಣಾಂಕ token)
{
    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    ಸ್ಥಿತಿ TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("nullary instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_unary_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ op;
    parse_ಕಾರ್ಯಾಂಶ(s1, &op);

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_swieq:
    ಸ್ಥಿತಿ TOK_ASM_svceq:
        ಆದರೆ (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        ಇಲ್ಲದಿದ್ದರೆ {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("unary instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_ದ್ವಿಮಾನ_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ ops[2];
    ಕಾರ್ಯಾಂಶ rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[0]);
    skip(',');
    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[1]);
    ಆದರೆ (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    ಆದರೆ (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ಖಾಲಿ));

    ಆದರೆ (ops[1].type != OP_REG32) {
        ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
        ಸ್ಥಿತಿ TOK_ASM_movteq:
        ಸ್ಥಿತಿ TOK_ASM_movweq:
            ಆದರೆ (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                ಆದರೆ (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t ತಕ್ಷಣ_ಮೌಲ್ಯ = ops[1].e.v;
                    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
                    ಸ್ಥಿತಿ TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (ತಕ್ಷಣ_ಮೌಲ್ಯ & 0xF000) << 4 | (ತಕ್ಷಣ_ಮೌಲ್ಯ & 0xFFF));
                        ನಿಲ್ಲಿಸು;
                    ಸ್ಥಿತಿ TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (ತಕ್ಷಣ_ಮೌಲ್ಯ & 0xF000) << 4 | (ತಕ್ಷಣ_ಮೌಲ್ಯ & 0xFFF));
                        ನಿಲ್ಲಿಸು;
                    }
                } ಇಲ್ಲದಿದ್ದರೆ
                    expect("(source operand) immediate 16 bit value");
            } ಇಲ್ಲದಿದ್ದರೆ
                expect("(source operand) immediate");
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            expect("(source operand) register");
        }
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ಖಾಲಿ));

    ಆದರೆ (tok == ',') {
        ಮುಂದಿನ(); // skip ','
        ಆದರೆ (tok == TOK_ASM_ror) {
            ಮುಂದಿನ(); // skip 'ror'
            parse_ಕಾರ್ಯಾಂಶ(s1, &rotation);
            ಆದರೆ (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } ಇಲ್ಲದಿದ್ದರೆ {
                amount = rotation.e.v;
                ಆಯ್ಕೆ (amount) {
                ಸ್ಥಿತಿ 8:
                    encoded_rotation = 1 << 10;
                    ನಿಲ್ಲಿಸು;
                ಸ್ಥಿತಿ 16:
                    encoded_rotation = 2 << 10;
                    ನಿಲ್ಲಿಸು;
                ಸ್ಥಿತಿ 24:
                    encoded_rotation = 3 << 10;
                    ನಿಲ್ಲಿಸು;
                ಪೂರ್ವನಿಯೋಜಿತ:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_clzeq:
        ಆದರೆ (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("binary instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_coprocessor_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token) {
    uint8_t coprocessor;
    ಕಾರ್ಯಾಂಶ opcode1;
    ಕಾರ್ಯಾಂಶ opcode2;
    uint8_t registers[3];
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ i;
    uint8_t ಮೇಲಿನ_nibble;
    uint8_t mrc = 0;

    ಆದರೆ (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        ಮುಂದಿನ();
    } ಇಲ್ಲದಿದ್ದರೆ {
        expect("'p<number>'");
    }
    skip(',');
    parse_ಕಾರ್ಯಾಂಶ(s1, &opcode1);
    ಆದರೆ (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ಖಾಲಿ));
    }

    ಗಾಗಿ (i = 0; i < 3; ++i) {
        skip(',');
        ಆದರೆ (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_ಗುಂಪು(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_ಗುಂಪು(token) == TOK_ASM_mcreq)) {
            ಆದರೆ (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                ಮುಂದಿನ();
            } ಇಲ್ಲದಿದ್ದರೆ {
                expect("'r<number>'");
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                ಮುಂದಿನ();
            } ಇಲ್ಲದಿದ್ದರೆ {
                expect("'c<number>'");
            }
        }
    }
    ಆದರೆ (tok == ',') {
        ಮುಂದಿನ();
        parse_ಕಾರ್ಯಾಂಶ(s1, &opcode2);
    } ಇಲ್ಲದಿದ್ದರೆ {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    ಆದರೆ (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (token == TOK_ASM_cdp2) {
        ಮೇಲಿನ_nibble = 0xF;
        asm_emit_coprocessor_opcode(ಮೇಲಿನ_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        ಹಿಂತಿರುಗಿ;
    } ಇಲ್ಲದಿದ್ದರೆ
        ಮೇಲಿನ_nibble = condition_ಸಂಕೇತ_ದ_token(token);

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(ಮೇಲಿನ_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        ಆದರೆ (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, ಖಾಲಿ));
        }
        asm_emit_coprocessor_opcode(ಮೇಲಿನ_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("known instruction");
    }
}

/* data processing and single data transfer instructions only */
#ವ್ಯಾಖ್ಯಾನಿಸು ENCODE_RN(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) ((ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) << 16)
#ವ್ಯಾಖ್ಯಾನಿಸು ENCODE_RD(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) ((ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) << 12)
#ವ್ಯಾಖ್ಯಾನಿಸು ENCODE_ಗಣ_CONDITION_CODES (1 << 20)

/* Note: For data processing instructions, "1" means immediate.
   Note: For single data transfer instructions, "0" means immediate. */
#ವ್ಯಾಖ್ಯಾನಿಸು ENCODE_ತಕ್ಷಣ_FLAG (1 << 25)

#ವ್ಯಾಖ್ಯಾನಿಸು ENCODE_BARREL_SHIFTER_ಸರಿಸು_BY_ರಿಜಿಸ್ಟರ್ (1 << 4)
#ವ್ಯಾಖ್ಯಾನಿಸು ENCODE_BARREL_SHIFTER_ಬಹುಲಕ_LSL (0 << 5)
#ವ್ಯಾಖ್ಯಾನಿಸು ENCODE_BARREL_SHIFTER_ಬಹುಲಕ_LSR (1 << 5)
#ವ್ಯಾಖ್ಯಾನಿಸು ENCODE_BARREL_SHIFTER_ಬಹುಲಕ_ASR (2 << 5)
#ವ್ಯಾಖ್ಯಾನಿಸು ENCODE_BARREL_SHIFTER_ಬಹುಲಕ_ROR (3 << 5)
#ವ್ಯಾಖ್ಯಾನಿಸು ENCODE_BARREL_SHIFTER_ರಿಜಿಸ್ಟರ್(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) ((ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) << 8)
#ವ್ಯಾಖ್ಯಾನಿಸು ENCODE_BARREL_SHIFTER_ತಕ್ಷಣ(ಮೌಲ್ಯ) ((ಮೌಲ್ಯ) << 7)

ಸ್ಥಿರ ಶೂನ್ಯ asm_ಖಂಡ_ದತ್ತಾಂಶ_transfer_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    uint32_t opcode;
    ಪೂರ್ಣಾಂಕ op0_exclam = 0;
    ಕಾರ್ಯಾಂಶ ops[2];
    ಪೂರ್ಣಾಂಕ nb_ops = 1;
    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[0]);
    ಆದರೆ (tok == '!') {
        op0_exclam = 1;
        ಮುಂದಿನ(); // skip '!'
    }
    ಆದರೆ (tok == ',') {
        ಮುಂದಿನ(); // skip comma
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[1]);
        ++nb_ops;
    }
    ಆದರೆ (nb_ops < 1) {
        expect("at least one operand");
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        ಆದರೆ (nb_ops != 1)
            expect("exactly one operand");
        ಇಲ್ಲದಿದ್ದರೆ
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        ಆದರೆ (nb_ops != 1)
            expect("exactly one operand");
        ಇಲ್ಲದಿದ್ದರೆ
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_stmdaeq:
    ಸ್ಥಿತಿ TOK_ASM_ldmdaeq:
    ಸ್ಥಿತಿ TOK_ASM_stmeq:
    ಸ್ಥಿತಿ TOK_ASM_ldmeq:
    ಸ್ಥಿತಿ TOK_ASM_stmiaeq:
    ಸ್ಥಿತಿ TOK_ASM_ldmiaeq:
    ಸ್ಥಿತಿ TOK_ASM_stmdbeq:
    ಸ್ಥಿತಿ TOK_ASM_ldmdbeq:
    ಸ್ಥಿತಿ TOK_ASM_stmibeq:
    ಸ್ಥಿತಿ TOK_ASM_ldmibeq:
        ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
        ಸ್ಥಿತಿ TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_stmeq: // post-increment store
        ಸ್ಥಿತಿ TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_ldmeq: // post-increment load
        ಸ್ಥಿತಿ TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        ಆದರೆ (nb_ops != 2)
            expect("exactly two operands");
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[0].type != OP_REG32)
            expect("(first operand) register");
        ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
ಸ್ಥಿರ uint32_t asm_parse_optional_ಸರಿಸು(TCCState* s1, ಪೂರ್ಣಾಂಕ* nb_ಸರಿಸು, ಕಾರ್ಯಾಂಶ* ಸರಿಸು)
{
    uint32_t opcode = 0;
    *nb_ಸರಿಸು = 0;
    ಆಯ್ಕೆ (tok) {
    ಸ್ಥಿತಿ TOK_ASM_asl:
    ಸ್ಥಿತಿ TOK_ASM_lsl:
    ಸ್ಥಿತಿ TOK_ASM_asr:
    ಸ್ಥಿತಿ TOK_ASM_lsr:
    ಸ್ಥಿತಿ TOK_ASM_ror:
        ಆಯ್ಕೆ (tok) {
        ಸ್ಥಿತಿ TOK_ASM_asl:
            /* fallthrough */
        ಸ್ಥಿತಿ TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_ಬಹುಲಕ_LSL;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_ಬಹುಲಕ_ASR;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_ಬಹುಲಕ_LSR;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_ಬಹುಲಕ_ROR;
            ನಿಲ್ಲಿಸು;
        }
        ಮುಂದಿನ();
        parse_ಕಾರ್ಯಾಂಶ(s1, ಸರಿಸು);
        *nb_ಸರಿಸು = 1;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_rrx:
        ಮುಂದಿನ();
        opcode = ENCODE_BARREL_SHIFTER_ಬಹುಲಕ_ROR;
        ನಿಲ್ಲಿಸು;
    }
    ಹಿಂತಿರುಗಿ opcode;
}

ಸ್ಥಿರ uint32_t asm_encode_ಸರಿಸು(ಕಾರ್ಯಾಂಶ* ಸರಿಸು)
{
    uint64_t amount;
    uint32_t operands = 0;
    ಆಯ್ಕೆ (ಸರಿಸು->type) {
    ಸ್ಥಿತಿ OP_REG32:
        ಆದರೆ (ಸರಿಸು->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        ಇಲ್ಲದಿದ್ದರೆ {
            operands = ENCODE_BARREL_SHIFTER_ಸರಿಸು_BY_ರಿಜಿಸ್ಟರ್;
            operands |= ENCODE_BARREL_SHIFTER_ರಿಜಿಸ್ಟರ್(ಸರಿಸು->reg);
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ OP_IM8:
        amount = ಸರಿಸು->e.v;
        ಆದರೆ (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_ತಕ್ಷಣ(amount);
        ಇಲ್ಲದಿದ್ದರೆ
            tcc_error("shift count out of range");
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        tcc_error("unknown shift amount");
    }
    ಹಿಂತಿರುಗಿ operands;
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_ದತ್ತಾಂಶ_processing_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ ops[3];
    ಪೂರ್ಣಾಂಕ nb_ops;
    ಕಾರ್ಯಾಂಶ ಸರಿಸು = {0};
    ಪೂರ್ಣಾಂಕ nb_ಸರಿಸು = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_ಗುಂಪು(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    ಗಾಗಿ (nb_ops = 0; nb_ops < ಗಾತ್ರ(ops)/ಗಾತ್ರ(ops[0]); ) {
        ಆದರೆ (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            ನಿಲ್ಲಿಸು;
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[nb_ops]);
        ++nb_ops;
        ಆದರೆ (tok != ',')
            ನಿಲ್ಲಿಸು;
        ಮುಂದಿನ(); // skip ','
    }
    ಆದರೆ (tok == ',')
        ಮುಂದಿನ();
    operands |= asm_parse_optional_ಸರಿಸು(s1, &nb_ಸರಿಸು, &ಸರಿಸು);
    ಆದರೆ (nb_ops < 2)
        expect("at least two operands");
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (nb_ops == 2) {
        ಸ್ಮರಣೆ_ನಕಲು(&ops[2], &ops[1], ಗಾತ್ರ(ops[1])); // move ops[2]
        ಸ್ಮರಣೆ_ನಕಲು(&ops[1], &ops[0], ಗಾತ್ರ(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (nb_ops == 3) {
        ಆದರೆ (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, ಖಾಲಿ));
        }
    }
    ಆದರೆ (nb_ops != 3) {
        expect("two or three operands");
    } ಇಲ್ಲದಿದ್ದರೆ {
        uint32_t opcode = 0;
        uint32_t ತಕ್ಷಣ_ಮೌಲ್ಯ;
        uint8_t half_ತಕ್ಷಣ_rotation;
        ಆದರೆ (nb_ಸರಿಸು && ಸರಿಸು.type == OP_REG32) {
            ಆದರೆ ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
                (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
                tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
            }
        }

        // data processing (general case):
        // operands:
        //   Rn: bits 19...16 (first operand)
        //   Rd: bits 15...12 (destination)
        //   Operand2: bits 11...0 (second operand);  depending on I that's either a register or an immediate
        // operator:
        //   bits 24...21: "OpCode"--see below

        /* operations in the token list are ordered by opcode */
        opcode = opcode_nos << 21; // drop "s"
        ಆದರೆ (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_ಗಣ_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        ಇಲ್ಲದಿದ್ದರೆ
            operands |= ENCODE_RD(ops[0].reg);
        ಆದರೆ (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        ಆಯ್ಕೆ (ops[2].type) {
        ಸ್ಥಿತಿ OP_REG32:
            operands |= ops[2].reg;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ OP_IM8:
        ಸ್ಥಿತಿ OP_IM32:
            operands |= ENCODE_ತಕ್ಷಣ_FLAG;
            ತಕ್ಷಣ_ಮೌಲ್ಯ = ops[2].e.v;
            ಗಾಗಿ (half_ತಕ್ಷಣ_rotation = 0; half_ತಕ್ಷಣ_rotation < 16; ++half_ತಕ್ಷಣ_rotation) {
                ಆದರೆ (ತಕ್ಷಣ_ಮೌಲ್ಯ >= 0x00 && ತಕ್ಷಣ_ಮೌಲ್ಯ < 0x100)
                    ನಿಲ್ಲಿಸು;
                // rotate left by two
                ತಕ್ಷಣ_ಮೌಲ್ಯ = ((ತಕ್ಷಣ_ಮೌಲ್ಯ & 0x3FFFFFFF) << 2) | ((ತಕ್ಷಣ_ಮೌಲ್ಯ & 0xC0000000) >> 30);
            }
            ಆದರೆ (half_ತಕ್ಷಣ_rotation >= 16) {
                /* fallthrough */
            } ಇಲ್ಲದಿದ್ದರೆ {
                operands |= ತಕ್ಷಣ_ಮೌಲ್ಯ;
                operands |= half_ತಕ್ಷಣ_rotation << 8;
                ನಿಲ್ಲಿಸು;
            }
        ಸ್ಥಿತಿ OP_IM8N: // immediate negative value
            operands |= ENCODE_ತಕ್ಷಣ_FLAG;
            ತಕ್ಷಣ_ಮೌಲ್ಯ = ops[2].e.v;
            /* Instruction swapping:
               0001 = EOR - Rd:= Op1 EOR Op2     -> difficult
               0011 = RSB - Rd:= Op2 - Op1       -> difficult
               0111 = RSC - Rd:= Op2 - Op1 + C   -> difficult
               1000 = TST - CC on: Op1 AND Op2   -> difficult
               1001 = TEQ - CC on: Op1 EOR Op2   -> difficult
               1100 = ORR - Rd:= Op1 OR Op2      -> difficult
            */
            ಆಯ್ಕೆ (opcode_nos) {
            ಸ್ಥಿತಿ 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                ತಕ್ಷಣ_ಮೌಲ್ಯ = ~ತಕ್ಷಣ_ಮೌಲ್ಯ;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; //ಕೂಡಿಸು
                ತಕ್ಷಣ_ಮೌಲ್ಯ = -ತಕ್ಷಣ_ಮೌಲ್ಯ;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                ತಕ್ಷಣ_ಮೌಲ್ಯ = -ತಕ್ಷಣ_ಮೌಲ್ಯ;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                ತಕ್ಷಣ_ಮೌಲ್ಯ = ~ತಕ್ಷಣ_ಮೌಲ್ಯ;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                ತಕ್ಷಣ_ಮೌಲ್ಯ = ~ತಕ್ಷಣ_ಮೌಲ್ಯ;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                ತಕ್ಷಣ_ಮೌಲ್ಯ = -ತಕ್ಷಣ_ಮೌಲ್ಯ;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                ತಕ್ಷಣ_ಮೌಲ್ಯ = -ತಕ್ಷಣ_ಮೌಲ್ಯ;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                ತಕ್ಷಣ_ಮೌಲ್ಯ = ~ತಕ್ಷಣ_ಮೌಲ್ಯ;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                ತಕ್ಷಣ_ಮೌಲ್ಯ = ~ತಕ್ಷಣ_ಮೌಲ್ಯ;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                ತಕ್ಷಣ_ಮೌಲ್ಯ = ~ತಕ್ಷಣ_ಮೌಲ್ಯ;
                ನಿಲ್ಲಿಸು;
            ಪೂರ್ವನಿಯೋಜಿತ:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, ಖಾಲಿ));
            }
            ಗಾಗಿ (half_ತಕ್ಷಣ_rotation = 0; half_ತಕ್ಷಣ_rotation < 16; ++half_ತಕ್ಷಣ_rotation) {
                ಆದರೆ (ತಕ್ಷಣ_ಮೌಲ್ಯ >= 0x00 && ತಕ್ಷಣ_ಮೌಲ್ಯ < 0x100)
                    ನಿಲ್ಲಿಸು;
                // rotate left by two
                ತಕ್ಷಣ_ಮೌಲ್ಯ = ((ತಕ್ಷಣ_ಮೌಲ್ಯ & 0x3FFFFFFF) << 2) | ((ತಕ್ಷಣ_ಮೌಲ್ಯ & 0xC0000000) >> 30);
            }
            ಆದರೆ (half_ತಕ್ಷಣ_rotation >= 16) {
                ತಕ್ಷಣ_ಮೌಲ್ಯ = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (ಚಿಹ್ನೆರಹಿತ) ತಕ್ಷಣ_ಮೌಲ್ಯ);
            }
            operands |= ತಕ್ಷಣ_ಮೌಲ್ಯ;
            operands |= half_ತಕ್ಷಣ_rotation << 8;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            expect("(second source operand) register or immediate value");
        }

        ಆದರೆ (nb_ಸರಿಸು) {
            ಆದರೆ (operands & ENCODE_ತಕ್ಷಣ_FLAG)
                tcc_error("immediate rotation not implemented");
            ಇಲ್ಲದಿದ್ದರೆ
                operands |= asm_encode_ಸರಿಸು(&ಸರಿಸು);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_ಗಣ_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_ಸರಿಸು_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ ops[3];
    ಪೂರ್ಣಾಂಕ nb_ops;
    ಪೂರ್ಣಾಂಕ definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    ಗಾಗಿ (nb_ops = 0; nb_ops < ಗಾತ್ರ(ops)/ಗಾತ್ರ(ops[0]); ++nb_ops) {
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[nb_ops]);
        ಆದರೆ (tok != ',') {
            ++nb_ops;
            ನಿಲ್ಲಿಸು;
        }
        ಮುಂದಿನ(); // skip ','
    }
    ಆದರೆ (nb_ops < 2) {
        expect("at least two operands");
    }

    ಆದರೆ (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } ಇಲ್ಲದಿದ್ದರೆ
        operands |= ENCODE_RD(ops[0].reg);

    ಆದರೆ (nb_ops == 2) {
        ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
        ಸ್ಥಿತಿ TOK_ASM_rrxseq:
            opcode |= ENCODE_ಗಣ_CONDITION_CODES;
            /* fallthrough */
        ಸ್ಥಿತಿ TOK_ASM_rrxeq:
            ಆದರೆ (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_ಬಹುಲಕ_ROR;
                asm_emit_opcode(token, opcode | operands);
            } ಇಲ್ಲದಿದ್ದರೆ
                tcc_error("(first source operand) register");
            ಹಿಂತಿರುಗಿ;
        ಪೂರ್ವನಿಯೋಜಿತ:
            ಸ್ಮರಣೆ_ನಕಲು(&ops[2], &ops[1], ಗಾತ್ರ(ops[1])); // move ops[2]
            ಸ್ಮರಣೆ_ನಕಲು(&ops[1], &ops[0], ಗಾತ್ರ(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    ಆದರೆ (nb_ops != 3) {
        expect("two or three operands");
    }

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_lslseq:
    ಸ್ಥಿತಿ TOK_ASM_lsrseq:
    ಸ್ಥಿತಿ TOK_ASM_asrseq:
    ಸ್ಥಿತಿ TOK_ASM_rorseq:
        opcode |= ENCODE_ಗಣ_CONDITION_CODES;
        ನಿಲ್ಲಿಸು;
    }

    ಆಯ್ಕೆ (ops[1].type) {
    ಸ್ಥಿತಿ OP_REG32:
        operands |= ops[1].reg;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ OP_IM8:
        operands |= ENCODE_ತಕ್ಷಣ_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, ಖಾಲಿ));
    }

    ಆಯ್ಕೆ (ops[2].type) {
    ಸ್ಥಿತಿ OP_REG32:
        ಆದರೆ ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_ಸರಿಸು(&ops[2]);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ OP_IM8:
        ಆದರೆ (ops[2].e.v)
            operands |= asm_encode_ಸರಿಸು(&ops[2]);
        ಇಲ್ಲದಿದ್ದರೆ
            definitely_neutral = 1;
        ನಿಲ್ಲಿಸು;
    }

    ಆದರೆ (!definitely_neutral) ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_lslseq:
    ಸ್ಥಿತಿ TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_ಬಹುಲಕ_LSL;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_lsrseq:
    ಸ್ಥಿತಿ TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_ಬಹುಲಕ_LSR;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_asrseq:
    ಸ್ಥಿತಿ TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_ಬಹುಲಕ_ASR;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_rorseq:
    ಸ್ಥಿತಿ TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_ಬಹುಲಕ_ROR;
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_multiplication_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ ops[4];
    ಪೂರ್ಣಾಂಕ nb_ops = 0;
    uint32_t opcode = 0x90;

    ಗಾಗಿ (nb_ops = 0; nb_ops < ಗಾತ್ರ(ops)/ಗಾತ್ರ(ops[0]); ++nb_ops) {
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[nb_ops]);
        ಆದರೆ (tok != ',') {
            ++nb_ops;
            ನಿಲ್ಲಿಸು;
        }
        ಮುಂದಿನ(); // skip ','
    }
    ಆದರೆ (nb_ops < 2)
        expect("at least two operands");
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (nb_ops == 2) {
        ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
        ಸ್ಥಿತಿ TOK_ASM_mulseq:
        ಸ್ಥಿತಿ TOK_ASM_muleq:
            ಸ್ಮರಣೆ_ನಕಲು(&ops[2], &ops[0], ಗಾತ್ರ(ops[1])); // ARM is actually like this!
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            expect("at least three operands");
        }
        nb_ops = 3;
    }

    // multiply (special case):
    // operands:
    //   Rd: bits 19...16
    //   Rm: bits 3...0
    //   Rs: bits 11...8
    //   Rn: bits 15...12

    ಆದರೆ (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    ಇಲ್ಲದಿದ್ದರೆ
        expect("(destination operand) register");
    ಆದರೆ (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    ಇಲ್ಲದಿದ್ದರೆ
        expect("(first source operand) register");
    ಆದರೆ (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    ಇಲ್ಲದಿದ್ದರೆ
        expect("(second source operand) register");
    ಆದರೆ (nb_ops > 3) {
        ಆದರೆ (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        ಇಲ್ಲದಿದ್ದರೆ
            expect("(third source operand) register");
    }

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_mulseq:
        opcode |= 1 << 20; //ಸ್ಥಿತಿ
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_muleq:
        ಆದರೆ (nb_ops != 3)
            expect("three operands");
        ಇಲ್ಲದಿದ್ದರೆ {
            asm_emit_opcode(token, opcode);
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_mlaseq:
        opcode |= 1 << 20; //ಸ್ಥಿತಿ
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        ಆದರೆ (nb_ops != 4)
            expect("four operands");
        ಇಲ್ಲದಿದ್ದರೆ {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_mlseq:
        opcode |= 0x00400000;
        ಹೋಗು case_TOK_ASM_mlaeq;
    ಸ್ಥಿತಿ TOK_ASM_udiveq:
        opcode |= 0x00200000;
    ಸ್ಥಿತಿ TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("known multiplication instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_long_multiplication_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ ops[4];
    ಪೂರ್ಣಾಂಕ nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    ಗಾಗಿ (nb_ops = 0; nb_ops < ಗಾತ್ರ(ops)/ಗಾತ್ರ(ops[0]); ++nb_ops) {
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[nb_ops]);
        ಆದರೆ (tok != ',') {
            ++nb_ops;
            ನಿಲ್ಲಿಸು;
        }
        ಮುಂದಿನ(); // skip ','
    }
    ಆದರೆ (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    ಆದರೆ (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    ಇಲ್ಲದಿದ್ದರೆ
        expect("(destination lo accumulator) register");
    ಆದರೆ (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    ಇಲ್ಲದಿದ್ದರೆ
        expect("(destination hi accumulator) register");
    ಆದರೆ (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    ಇಲ್ಲದಿದ್ದರೆ
        expect("(first source operand) register");
    ಆದರೆ (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    ಇಲ್ಲದಿದ್ದರೆ
        expect("(second source operand) register");

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_smullseq:
        opcode |= 1 << 20; //ಸ್ಥಿತಿ
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_umullseq:
        opcode |= 1 << 20; //ಸ್ಥಿತಿ
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_smlalseq:
        opcode |= 1 << 20; //ಸ್ಥಿತಿ
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_umlalseq:
        opcode |= 1 << 20; //ಸ್ಥಿತಿ
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("known long multiplication instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_single_ದತ್ತಾಂಶ_transfer_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ ops[3];
    ಕಾರ್ಯಾಂಶ strex_ಕಾರ್ಯಾಂಶ;
    ಕಾರ್ಯಾಂಶ ಸರಿಸು;
    ಪೂರ್ಣಾಂಕ nb_ಸರಿಸು = 0;
    ಪೂರ್ಣಾಂಕ exclam = 0;
    ಪೂರ್ಣಾಂಕ closed_bracket = 0;
    ಪೂರ್ಣಾಂಕ op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[0]);
    ಆದರೆ (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    ಇಲ್ಲದಿದ್ದರೆ {
        expect("(destination operand) register");
    }
    ಆದರೆ (tok != ',')
        expect("at least two arguments");
    ಮುಂದಿನ(); // skip ','

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_strexheq:
    ಸ್ಥಿತಿ TOK_ASM_strexbeq:
    ಸ್ಥಿತಿ TOK_ASM_strexeq:
        parse_ಕಾರ್ಯಾಂಶ(s1, &strex_ಕಾರ್ಯಾಂಶ);
        ಆದರೆ (strex_ಕಾರ್ಯಾಂಶ.type != OP_REG32) {
            expect("register");
        }
        ಆದರೆ (tok != ',')
            expect("at least three arguments");
        ಇಲ್ಲದಿದ್ದರೆ
            ಮುಂದಿನ(); // skip ','
        ನಿಲ್ಲಿಸು;
    }

    skip('[');
    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[1]);
    ಆದರೆ (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    ಇಲ್ಲದಿದ್ದರೆ {
        expect("(first source operand) register");
    }
    ಆದರೆ (tok == ']') {
        ಮುಂದಿನ();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ಆದರೆ (tok == ',') {
        ಮುಂದಿನ(); // skip ','
        ಆದರೆ (tok == '-') {
            op2_minus = 1;
            ಮುಂದಿನ();
        }
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[2]);
        ಆದರೆ (ops[2].type == OP_REG32) {
            ಆದರೆ (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ಖಾಲಿ));
            }
            ಆದರೆ (tok == ',') {
                ಮುಂದಿನ();
                opcode |= asm_parse_optional_ಸರಿಸು(s1, &nb_ಸರಿಸು, &ಸರಿಸು);
                ಆದರೆ (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    ಆದರೆ (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        ಆದರೆ (tok == '!') {
            exclam = 1;
            ಮುಂದಿನ(); // skip '!'
        }
    }

    // single data transfer: 0 1 I P U B W L << 20 (general case):
    // operands:
    //    Rd: destination operand [ok]
    //    Rn: first source operand [ok]
    //    Operand2: bits 11...0 [ok]
    // I: immediate operand? [ok]
    // P: Pre/post indexing is PRE: Add offset before transfer [ok]
    // U: Up/down is up? (*adds* offset to base) [ok]
    // B: Byte/word is byte?  [ok]
    // W: Write address back into base? [ok]
    // L: Load/store is load? [ok]
    ಆದರೆ (exclam)
        opcode |= 1 << 21; // write offset back into register

    ಆದರೆ (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        ಪೂರ್ಣಾಂಕ v = ops[2].e.v;
        ಆದರೆ (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ಆದರೆ (v >= 0) {
            opcode |= 1 << 23; //ಮೇಲೆ
            ಆದರೆ (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ಖಾಲಿ));
            ಇಲ್ಲದಿದ್ದರೆ
                opcode |= v;
        } ಇಲ್ಲದಿದ್ದರೆ { //ಕೆಳಕ್ಕೆ
            ಆದರೆ (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ಖಾಲಿ));
            ಇಲ್ಲದಿದ್ದರೆ
                opcode |= -v;
        }
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[2].type == OP_REG32) {
        ಆದರೆ (!op2_minus)
            opcode |= 1 << 23; //ಮೇಲೆ
        opcode |= ENCODE_ತಕ್ಷಣ_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } ಇಲ್ಲದಿದ್ದರೆ
        expect("register");

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        ಆದರೆ (nb_ಸರಿಸು)
            opcode |= asm_encode_ಸರಿಸು(&ಸರಿಸು);
        asm_emit_opcode(token, opcode);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        ಆದರೆ (nb_ಸರಿಸು)
            opcode |= asm_encode_ಸರಿಸು(&ಸರಿಸು);
        asm_emit_opcode(token, opcode);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_strexheq:
        opcode |= 1 << 21;
    ಸ್ಥಿತಿ TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_strexeq:
        ಆದರೆ ((opcode & 0xFFF) || nb_ಸರಿಸು) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (opcode & ENCODE_ತಕ್ಷಣ_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        ಆದರೆ ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_ಕಾರ್ಯಾಂಶ.reg;
        asm_emit_opcode(token, opcode);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    ಸ್ಥಿತಿ TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_ldrexeq:
        ಆದರೆ ((opcode & 0xFFF) || nb_ಸರಿಸು) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (opcode & ENCODE_ತಕ್ಷಣ_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        ಆದರೆ ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_coprocessor_ದತ್ತಾಂಶ_transfer(uint32_t ಮೇಲಿನ_nibble, uint8_t cp_ಸಂಖ್ಯೆ, uint8_t CRd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* Rn, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ ಸ್ಥಾನಾಂತರ_minus, ಪೂರ್ಣಾಂಕ preincrement, ಪೂರ್ಣಾಂಕ writeback, ಪೂರ್ಣಾಂಕ long_transfer, ಪೂರ್ಣಾಂಕ ತುಂಬು) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    ಆದರೆ (long_transfer)
        opcode |= 1 << 22; // long transfer

    ಆದರೆ (ತುಂಬು)
        opcode |= 1 << 20; // L

    opcode |= cp_ಸಂಖ್ಯೆ << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    ಆದರೆ (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    ಆದರೆ (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    ಆದರೆ (writeback)
        opcode |= 1 << 21; // write offset back into register

    ಆದರೆ (ಸ್ಥಾನಾಂತರ->type == OP_IM8 || ಸ್ಥಾನಾಂತರ->type == OP_IM8N || ಸ್ಥಾನಾಂತರ->type == OP_IM32) {
        ಪೂರ್ಣಾಂಕ v = ಸ್ಥಾನಾಂತರ->e.v;
        ಆದರೆ (ಸ್ಥಾನಾಂತರ_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ಆದರೆ (ಸ್ಥಾನಾಂತರ->type == OP_IM8N || v < 0)
            v = -v;
        ಇಲ್ಲದಿದ್ದರೆ
            opcode |= 1 << 23; //ಮೇಲೆ
        ಆದರೆ (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        ಆದರೆ (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಸ್ಥಾನಾಂತರ->type == OP_REG32) {
        ಆದರೆ (!ಸ್ಥಾನಾಂತರ_minus)
            opcode |= 1 << 23; //ಮೇಲೆ
        opcode |= ENCODE_ತಕ್ಷಣ_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ಸ್ಥಾನಾಂತರ->reg;
        tcc_error("Using register offset to register address is not possible here");
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಸ್ಥಾನಾಂತರ->type == OP_VREG64) {
        opcode |= 16;
        opcode |= ಸ್ಥಾನಾಂತರ->reg;
    } ಇಲ್ಲದಿದ್ದರೆ
        expect("immediate or register");

    asm_emit_unconditional_opcode((ಮೇಲಿನ_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
ಸ್ಥಿರ ಶೂನ್ಯ asm_coprocessor_ದತ್ತಾಂಶ_transfer_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_ರಿಜಿಸ್ಟರ್;
    ಪೂರ್ಣಾಂಕ preincrement = 0;
    ಪೂರ್ಣಾಂಕ exclam = 0;
    ಪೂರ್ಣಾಂಕ closed_bracket = 0;
    ಪೂರ್ಣಾಂಕ op2_minus = 0;
    ಪೂರ್ಣಾಂಕ long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    ಆದರೆ (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        ಮುಂದಿನ();
    } ಇಲ್ಲದಿದ್ದರೆ {
        expect("'c<number>'");
    }

    skip(',');

    ಆದರೆ (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_ರಿಜಿಸ್ಟರ್ = tok - TOK_ASM_c0;
        ಮುಂದಿನ();
    } ಇಲ್ಲದಿದ್ದರೆ {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[1]);
    ಆದರೆ (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    ಆದರೆ (tok == ']') {
        ಮುಂದಿನ();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ಆದರೆ (tok == ',') {
        ಮುಂದಿನ(); // skip ','
        ಆದರೆ (tok == '-') {
            op2_minus = 1;
            ಮುಂದಿನ();
        }
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[2]);
        ಆದರೆ (ops[2].type == OP_REG32) {
            ಆದರೆ (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ಖಾಲಿ));
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, ಖಾಲಿ));
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    ಆದರೆ (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        ಆದರೆ (tok == '!') {
            exclam = 1;
            ಮುಂದಿನ(); // skip '!'
        }
    }

    // TODO: Support options.

    ಆದರೆ (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        ಆಯ್ಕೆ (token) {
        ಸ್ಥಿತಿ TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        ಸ್ಥಿತಿ TOK_ASM_ldc2:
            asm_emit_coprocessor_ದತ್ತಾಂಶ_transfer(0xF, coprocessor, coprocessor_destination_ರಿಜಿಸ್ಟರ್, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        ಸ್ಥಿತಿ TOK_ASM_stc2:
            asm_emit_coprocessor_ದತ್ತಾಂಶ_transfer(0xF, coprocessor, coprocessor_destination_ರಿಜಿಸ್ಟರ್, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            ನಿಲ್ಲಿಸು;
        }
    } ಇಲ್ಲದಿದ್ದರೆ ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_stceq:
        asm_emit_coprocessor_ದತ್ತಾಂಶ_transfer(condition_ಸಂಕೇತ_ದ_token(token), coprocessor, coprocessor_destination_ರಿಜಿಸ್ಟರ್, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_ldceq:
        asm_emit_coprocessor_ದತ್ತಾಂಶ_transfer(condition_ಸಂಕೇತ_ದ_token(token), coprocessor, coprocessor_destination_ರಿಜಿಸ್ಟರ್, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("coprocessor data transfer instruction");
    }
}

#ಆದರೆ defined(TCC_ARM_VFP)
#ವ್ಯಾಖ್ಯಾನಿಸು CP_SINGLE_PRECISION_FLOAT 10
#ವ್ಯಾಖ್ಯಾನಿಸು CP_DOUBLE_PRECISION_FLOAT 11

ಸ್ಥಿರ ಶೂನ್ಯ asm_floating_ಬಿಂದು_single_ದತ್ತಾಂಶ_transfer_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_ರಿಜಿಸ್ಟರ್ = 0;
    ಪೂರ್ಣಾಂಕ long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[0]);
    ಆದರೆ (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_ರಿಜಿಸ್ಟರ್ = ops[0].reg;
        long_transfer = coprocessor_destination_ರಿಜಿಸ್ಟರ್ & 1;
        coprocessor_destination_ರಿಜಿಸ್ಟರ್ >>= 1;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_ರಿಜಿಸ್ಟರ್ = ops[0].reg;
        ಮುಂದಿನ();
    } ಇಲ್ಲದಿದ್ದರೆ {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[1]);
    ಆದರೆ (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    ಆದರೆ (tok == ',') {
        ಮುಂದಿನ(); // skip ','
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[2]);
        ಆದರೆ (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_vldreq:
        asm_emit_coprocessor_ದತ್ತಾಂಶ_transfer(condition_ಸಂಕೇತ_ದ_token(token), coprocessor, coprocessor_destination_ರಿಜಿಸ್ಟರ್, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vstreq:
        asm_emit_coprocessor_ದತ್ತಾಂಶ_transfer(condition_ಸಂಕೇತ_ದ_token(token), coprocessor, coprocessor_destination_ರಿಜಿಸ್ಟರ್, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("floating point data transfer instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_floating_ಬಿಂದು_ಖಂಡ_ದತ್ತಾಂಶ_transfer_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    uint8_t coprocessor = 0;
    ಪೂರ್ಣಾಂಕ ಮೊದಲ_regset_ರಿಜಿಸ್ಟರ್;
    ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_regset_ರಿಜಿಸ್ಟರ್;
    uint8_t regset_ಅಂಶ_ಎಣಿಕೆ;
    uint8_t extra_ರಿಜಿಸ್ಟರ್_ಬಿಟ್ = 0;
    ಪೂರ್ಣಾಂಕ op0_exclam = 0;
    ಪೂರ್ಣಾಂಕ ತುಂಬು = 0;
    ಪೂರ್ಣಾಂಕ preincrement = 0;
    ಕಾರ್ಯಾಂಶ ops[1];
    ಕಾರ್ಯಾಂಶ ಸ್ಥಾನಾಂತರ;
    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_vpusheq:
    ಸ್ಥಿತಿ TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[0]);
        ಆದರೆ (tok == '!') {
            op0_exclam = 1;
            ಮುಂದಿನ(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    ಮೊದಲ_regset_ರಿಜಿಸ್ಟರ್ = asm_parse_vfp_regvar(tok, 1);
    ಆದರೆ ((ಮೊದಲ_regset_ರಿಜಿಸ್ಟರ್ = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        ಮುಂದಿನ();
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ಮೊದಲ_regset_ರಿಜಿಸ್ಟರ್ = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        ಮುಂದಿನ();
    } ಇಲ್ಲದಿದ್ದರೆ {
        expect("floating-point register");
    }

    ಆದರೆ (tok == '-') {
        ಮುಂದಿನ();
        ಆದರೆ ((ಕೊನೆಯ_regset_ರಿಜಿಸ್ಟರ್ = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            ಮುಂದಿನ();
        ಇಲ್ಲದಿದ್ದರೆ {
            expect("floating-point register");
        }
    } ಇಲ್ಲದಿದ್ದರೆ
        ಕೊನೆಯ_regset_ರಿಜಿಸ್ಟರ್ = ಮೊದಲ_regset_ರಿಜಿಸ್ಟರ್;

    ಆದರೆ (ಕೊನೆಯ_regset_ರಿಜಿಸ್ಟರ್ < ಮೊದಲ_regset_ರಿಜಿಸ್ಟರ್) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_ಅಂಶ_ಎಣಿಕೆ = ಕೊನೆಯ_regset_ರಿಜಿಸ್ಟರ್ - ಮೊದಲ_regset_ರಿಜಿಸ್ಟರ್ + 1;
    ಆದರೆ (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_ಅಂಶ_ಎಣಿಕೆ <<= 1;
    ಇಲ್ಲದಿದ್ದರೆ {
        extra_ರಿಜಿಸ್ಟರ್_ಬಿಟ್ = ಮೊದಲ_regset_ರಿಜಿಸ್ಟರ್ & 1;
        ಮೊದಲ_regset_ರಿಜಿಸ್ಟರ್ >>= 1;
    }
    ಸ್ಥಾನಾಂತರ.type = OP_IM8;
    ಸ್ಥಾನಾಂತರ.e.v = regset_ಅಂಶ_ಎಣಿಕೆ << 2;
    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_vstmeq: // post-increment store
    ಸ್ಥಿತಿ TOK_ASM_vstmiaeq: // post-increment store
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vpopeq:
    ಸ್ಥಿತಿ TOK_ASM_vldmeq: // post-increment load
    ಸ್ಥಿತಿ TOK_ASM_vldmiaeq: // post-increment load
        ತುಂಬು = 1;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vldmdbeq: // pre-decrement load
        ತುಂಬು = 1;
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_vpusheq:
    ಸ್ಥಿತಿ TOK_ASM_vstmdbeq: // pre-decrement store
        ಸ್ಥಾನಾಂತರ.type = OP_IM8N;
        ಸ್ಥಾನಾಂತರ.e.v = -ಸ್ಥಾನಾಂತರ.e.v;
        preincrement = 1;
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("floating point block data transfer instruction");
    }
    ಆದರೆ (ops[0].type != OP_REG32)
        expect("(first operand) register");
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ಖಾಲಿ));
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!op0_exclam && ARM_INSTRUCTION_ಗುಂಪು(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_ಗುಂಪು(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_ಗುಂಪು(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_ಗುಂಪು(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, ಖಾಲಿ));
    ಇಲ್ಲದಿದ್ದರೆ
        asm_emit_coprocessor_ದತ್ತಾಂಶ_transfer(condition_ಸಂಕೇತ_ದ_token(token), coprocessor, ಮೊದಲ_regset_ರಿಜಿಸ್ಟರ್, &ops[0], &ಸ್ಥಾನಾಂತರ, 0, preincrement, op0_exclam, extra_ರಿಜಿಸ್ಟರ್_ಬಿಟ್, ತುಂಬು);
}

#ವ್ಯಾಖ್ಯಾನಿಸು VMOV_FRACTIONAL_DIGITS 7
#ವ್ಯಾಖ್ಯಾನಿಸು VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

ಸ್ಥಿರ uint32_t vmov_parse_fractional_part(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* s)
{
    uint32_t ಫಲಿತಾಂಶ = 0;
    ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        ಅಕ್ಷರ c = *s;
        ಫಲಿತಾಂಶ *= 10;
        ಆದರೆ (c >= '0' && c <= '9') {
            ಫಲಿತಾಂಶ += (c - '0');
            ++s;
        }
    }
    ಆದರೆ (*s)
        expect("decimal numeral");
    ಹಿಂತಿರುಗಿ ಫಲಿತಾಂಶ;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ vmov_ರೇಖೀಯ_approx_ಸೂಚ್ಯಂಕ(uint32_t beginning, uint32_t ಕೊನೆ, uint32_t ಮೌಲ್ಯ)
{
    ಪೂರ್ಣಾಂಕ i;
    uint32_t k;
    uint32_t xvalue;

    k = (ಕೊನೆ - beginning)/16;
    ಗಾಗಿ (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        ಆದರೆ (ಮೌಲ್ಯ == xvalue)
            ಹಿಂತಿರುಗಿ i;
    }
    //assert(0);
    ಹಿಂತಿರುಗಿ -1;
}

ಸ್ಥಿರ uint32_t vmov_parse_ತಕ್ಷಣ_ಮೌಲ್ಯ() {
    uint32_t ಮೌಲ್ಯ;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ integral_ಮೌಲ್ಯ;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p;

    ಆದರೆ (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.ದತ್ತಾಂಶ;
    errno = 0;
    integral_ಮೌಲ್ಯ = strtoul(p, (ಅಕ್ಷರ **)&p, 0);

    ಆದರೆ (errno || integral_ಮೌಲ್ಯ >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    ಮೌಲ್ಯ = (uint32_t) integral_ಮೌಲ್ಯ * VMOV_ONE;
    ಆದರೆ (*p == '.') {
        ++p;
        ಮೌಲ್ಯ += vmov_parse_fractional_part(p);
    }
    ಮುಂದಿನ();
    ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ;
}

ಸ್ಥಿರ uint8_t vmov_encode_ತಕ್ಷಣ_ಮೌಲ್ಯ(uint32_t ಮೌಲ್ಯ)
{
    uint32_t ಎಲ್ಲೆ;
    uint32_t ಕೊನೆ = 0;
    uint32_t beginning = 0;
    ಪೂರ್ಣಾಂಕ r = -1;
    ಪೂರ್ಣಾಂಕ n;
    ಪೂರ್ಣಾಂಕ i;

    ಎಲ್ಲೆ = 32 * VMOV_ONE;
    ಗಾಗಿ (i = 0; i < 8; ++i) {
        ಆದರೆ (ಮೌಲ್ಯ < ಎಲ್ಲೆ) {
            ಕೊನೆ = ಎಲ್ಲೆ;
            ಎಲ್ಲೆ >>= 1;
            beginning = ಎಲ್ಲೆ;
            r = i;
        } ಇಲ್ಲದಿದ್ದರೆ
            ಎಲ್ಲೆ >>= 1;
    }
    ಆದರೆ (r == -1 || ಮೌಲ್ಯ < beginning || ಮೌಲ್ಯ > ಕೊನೆ) {
        tcc_error("invalid decimal number for vmov: %d", ಮೌಲ್ಯ);
    }
    n = vmov_ರೇಖೀಯ_approx_ಸೂಚ್ಯಂಕ(beginning, ಕೊನೆ, ಮೌಲ್ಯ);
    ಹಿಂತಿರುಗಿ n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
ಸ್ಥಿರ ಶೂನ್ಯ asm_floating_ಬಿಂದು_ತಕ್ಷಣ_ದತ್ತಾಂಶ_processing_opcode_ಬಾಲ(TCCState *s1, ಪೂರ್ಣಾಂಕ token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t ತಕ್ಷಣ_ಮೌಲ್ಯ = 0;
    ಪೂರ್ಣಾಂಕ op_minus = 0;
    uint8_t ಸಂಕೇತ_2;

    operands[0] = CRd;

    ಆದರೆ (tok == '#' || tok == '$') {
        ಮುಂದಿನ();
    }
    ಆದರೆ (tok == '-') {
        op_minus = 1;
        ಮುಂದಿನ();
    }
    ತಕ್ಷಣ_ಮೌಲ್ಯ = vmov_parse_ತಕ್ಷಣ_ಮೌಲ್ಯ();

    opcode1 = 11; // "Other" instruction
    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_vcmpeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        ಆದರೆ (ತಕ್ಷಣ_ಮೌಲ್ಯ) {
            expect("Immediate value 0");
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vcmpeeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        ಆದರೆ (ತಕ್ಷಣ_ಮೌಲ್ಯ) {
            expect("Immediate value 0");
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vmoveq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        ಆದರೆ (op_minus)
            operands[1] = 0x8;
        ಇಲ್ಲದಿದ್ದರೆ
            operands[1] = 0x0;
        ಸಂಕೇತ_2 = vmov_encode_ತಕ್ಷಣ_ಮೌಲ್ಯ(ತಕ್ಷಣ_ಮೌಲ್ಯ);
        operands[1] |= ಸಂಕೇತ_2 >> 4;
        operands[2] = ಸಂಕೇತ_2 & 0xF;
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("known floating point with immediate instruction");
    }

    ಆದರೆ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        ಆದರೆ (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_ಸಂಕೇತ_ದ_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_floating_ಬಿಂದು_reg_arm_reg_transfer_opcode_ಬಾಲ(TCCState *s1, ಪೂರ್ಣಾಂಕ token, ಪೂರ್ಣಾಂಕ coprocessor, ಪೂರ್ಣಾಂಕ nb_arm_regs, ಪೂರ್ಣಾಂಕ nb_ops, ಕಾರ್ಯಾಂಶ ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    ಆಯ್ಕೆ (coprocessor) {
    ಸ್ಥಿತಿ CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        ಆದರೆ (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        ಆದರೆ (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            ಸ್ಮರಣೆ_ನಕಲು(&ops[2], &ops[1], ಗಾತ್ರ(ops[2]));
            ಸ್ಮರಣೆ_ನಕಲು(&ops[1], &ops[0], ಗಾತ್ರ(ops[1]));
            ಸ್ಮರಣೆ_ನಕಲು(&ops[0], &ops[2], ಗಾತ್ರ(ops[0]));
        } ಇಲ್ಲದಿದ್ದರೆ
            opcode1 |= 1;

        ಆದರೆ (ops[1].type == OP_VREG32) {
            ಆದರೆ (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        ಆದರೆ (ops[0].type == OP_VREG32) {
            ಆದರೆ (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_ಸಂಕೇತ_ದ_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ CP_DOUBLE_PRECISION_FLOAT:
        ಆದರೆ (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        ಆದರೆ (ops[0].type == OP_VREG64) {
            ಆದರೆ (ops[2].type == OP_REG32) {
                ಕಾರ್ಯಾಂಶ ತಾತ್ಕಾಲಿಕ;
                // need to rotate operand list to the left
                ಸ್ಮರಣೆ_ನಕಲು(&ತಾತ್ಕಾಲಿಕ, &ops[0], ಗಾತ್ರ(ತಾತ್ಕಾಲಿಕ));
                ಸ್ಮರಣೆ_ನಕಲು(&ops[0], &ops[1], ಗಾತ್ರ(ops[0]));
                ಸ್ಮರಣೆ_ನಕಲು(&ops[1], &ops[2], ಗಾತ್ರ(ops[1]));
                ಸ್ಮರಣೆ_ನಕಲು(&ops[2], &ತಾತ್ಕಾಲಿಕ, ಗಾತ್ರ(ops[2]));
            } ಇಲ್ಲದಿದ್ದರೆ {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } ಇಲ್ಲದಿದ್ದರೆ {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_ದತ್ತಾಂಶ_transfer(condition_ಸಂಕೇತ_ದ_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        tcc_ಆಂತರಿಕ_error("unknown coprocessor");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_floating_ಬಿಂದು_vcvt_ದತ್ತಾಂಶ_processing_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token) {
    uint8_t coprocessor = 0;
    ಕಾರ್ಯಾಂಶ ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_vcvtreq_s32_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcvtreq_u32_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_s32_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_u32_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f64_s32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f64_u32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vcvtreq_s32_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvtreq_u32_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_s32_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_u32_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f32_s32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f32_u32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, ಖಾಲಿ));
    }

    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_vcvtreq_s32_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvtreq_s32_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_s32_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_u32_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_u32_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcvtreq_u32_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        ನಿಲ್ಲಿಸು;
    /* floating-point size conversion */
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f64_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        ನಿಲ್ಲಿಸು;
    }

    skip(',');
    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[2]);

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    /* floating-point -> integer */
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_s32_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_s32_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_u32_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        ನಿಲ್ಲಿಸು;

    /* integer -> floating-point */
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f64_s32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        ನಿಲ್ಲಿಸು;

    /* floating-point size conversion */
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f64_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        ನಿಲ್ಲಿಸು;
    }

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f64_u32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f64_s32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f64_f32:
        ಆದರೆ (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } ಇಲ್ಲದಿದ್ದರೆ {
            expect("d<number>, s<number>");
        }
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        ಆದರೆ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            ಆದರೆ (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } ಇಲ್ಲದಿದ್ದರೆ {
                expect("s<number>, s<number>");
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            ಆದರೆ (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } ಇಲ್ಲದಿದ್ದರೆ {
                expect("s<number>, d<number>");
            }
        }
    }

    ಆದರೆ (ops[2].type == OP_VREG32) {
        ಆದರೆ (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    ಆದರೆ (ops[0].type == OP_VREG32) {
        ಆದರೆ (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_ಸಂಕೇತ_ದ_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_floating_ಬಿಂದು_ದತ್ತಾಂಶ_processing_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    ಕಾರ್ಯಾಂಶ ops[3];
    uint8_t nb_ops = 0;
    ಪೂರ್ಣಾಂಕ vmov = 0;
    ಪೂರ್ಣಾಂಕ nb_arm_regs = 0;

/* TODO:
   Instruction    opcode opcode2  Reason
   =============================================================
   -              1?00   ?1?      Undefined
   VFNMS          1?01   ?0?      Must be unconditional
   VFNMA          1?01   ?1?      Must be unconditional
   VFMA           1?10   ?0?      Must be unconditional
   VFMS           1?10   ?1?      Must be unconditional

   VMOV Fd, Fm
   VMOV Sn, Sm, Rd, Rn
   VMOV Rd, Rn, Sn, Sm
   VMOV Dn[0], Rd
   VMOV Rd, Dn[0]
   VMOV Dn[1], Rd
   VMOV Rd, Dn[1]
*/

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_vmlaeq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vmlseq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vnmlseq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vnmlaeq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vmuleq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vnmuleq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vaddeq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vsubeq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vdiveq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vnegeq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vabseq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vsqrteq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcmpeq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcmpeeq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_vmoveq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vmoveq_f64:
        vmov = 1;
        ನಿಲ್ಲಿಸು;
    }

    ಗಾಗಿ (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        ಆದರೆ (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_ಬಿಂದು_ತಕ್ಷಣ_ದತ್ತಾಂಶ_processing_opcode_ಬಾಲ(s1, token, coprocessor, ops[0].reg);
            ಹಿಂತಿರುಗಿ;
        }
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[nb_ops]);
        ಆದರೆ (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[nb_ops].type == OP_VREG32) {
            ಆದರೆ (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[nb_ops].type == OP_VREG64) {
            ಆದರೆ (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            expect("floating point register");
        }
        ++nb_ops;
        ಆದರೆ (tok == ',')
            ಮುಂದಿನ();
        ಇಲ್ಲದಿದ್ದರೆ
            ನಿಲ್ಲಿಸು;
    }

    ಆದರೆ (nb_arm_regs == 0) {
        ಆದರೆ (nb_ops == 2) { // implicit
            ಸ್ಮರಣೆ_ನಕಲು(&ops[2], &ops[1], ಗಾತ್ರ(ops[1])); // move ops[2]
            ಸ್ಮರಣೆ_ನಕಲು(&ops[1], &ops[0], ಗಾತ್ರ(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        ಆದರೆ (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, ಖಾಲಿ), nb_ops);
        }
    }

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_vmlaeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vmlseq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vnmlseq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vnmlaeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vmuleq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vnmuleq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vaddeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vsubeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vdiveq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vnegeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vabseq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vsqrteq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vcmpeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vcmpeeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vmoveq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vmoveq_f64:
        ಆದರೆ (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_ಬಿಂದು_reg_arm_reg_transfer_opcode_ಬಾಲ(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            ಹಿಂತಿರುಗಿ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("known floating point instruction");
    }

    ಆದರೆ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        ಆದರೆ (ops[2].type == OP_VREG32) {
            ಆದರೆ (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        ಆದರೆ (ops[1].type == OP_VREG32) {
            ಆದರೆ (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        ಆದರೆ (ops[0].type == OP_VREG32) {
            ಆದರೆ (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_ಸಂಕೇತ_ದ_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ asm_parse_vfp_ಸ್ಥಿತಿ_regvar(ಪೂರ್ಣಾಂಕ t)
{
    ಆಯ್ಕೆ (t) {
    ಸ್ಥಿತಿ TOK_ASM_fpsid:
        ಹಿಂತಿರುಗಿ 0;
    ಸ್ಥಿತಿ TOK_ASM_fpscr:
        ಹಿಂತಿರುಗಿ 1;
    ಸ್ಥಿತಿ TOK_ASM_fpexc:
        ಹಿಂತಿರುಗಿ 8;
    ಪೂರ್ವನಿಯೋಜಿತ:
        ಹಿಂತಿರುಗಿ -1;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_floating_ಬಿಂದು_ಸ್ಥಿತಿ_ರಿಜಿಸ್ಟರ್_opcode(TCCState* s1, ಪೂರ್ಣಾಂಕ token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    ಪೂರ್ಣಾಂಕ vfp_sys_reg = -1;
    ಕಾರ್ಯಾಂಶ arm_ಕಾರ್ಯಾಂಶ;
    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_vmrseq:
        opcode = 0xf;
        ಆದರೆ (tok == TOK_ASM_apsr_nzcv) {
            arm_ಕಾರ್ಯಾಂಶ.type = OP_REG32;
            arm_ಕಾರ್ಯಾಂಶ.reg = 15; // not PC
            ಮುಂದಿನ(); // skip apsr_nzcv
        } ಇಲ್ಲದಿದ್ದರೆ {
            parse_ಕಾರ್ಯಾಂಶ(s1, &arm_ಕಾರ್ಯಾಂಶ);
            ಆದರೆ (arm_ಕಾರ್ಯಾಂಶ.type == OP_REG32 && arm_ಕಾರ್ಯಾಂಶ.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ಖಾಲಿ));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_ಸ್ಥಿತಿ_regvar(tok);
        ಮುಂದಿನ(); // skip vfp sys reg
        ಆದರೆ (arm_ಕಾರ್ಯಾಂಶ.type == OP_REG32 && arm_ಕಾರ್ಯಾಂಶ.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, ಖಾಲಿ));
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_ಸ್ಥಿತಿ_regvar(tok);
        ಮುಂದಿನ(); // skip vfp sys reg
        skip(',');
        parse_ಕಾರ್ಯಾಂಶ(s1, &arm_ಕಾರ್ಯಾಂಶ);
        ಆದರೆ (arm_ಕಾರ್ಯಾಂಶ.type == OP_REG32 && arm_ಕಾರ್ಯಾಂಶ.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ಖಾಲಿ));
        }
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("floating point status register instruction");
    }
    ಆದರೆ (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    ಆದರೆ (arm_ಕಾರ್ಯಾಂಶ.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_ಸಂಕೇತ_ದ_token(token), coprocessor, opcode, arm_ಕಾರ್ಯಾಂಶ.reg, vfp_sys_reg, 0x10, 0, 0);
}

#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಶೂನ್ಯ asm_misc_single_ದತ್ತಾಂಶ_transfer_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ ops[3];
    ಪೂರ್ಣಾಂಕ exclam = 0;
    ಪೂರ್ಣಾಂಕ closed_bracket = 0;
    ಪೂರ್ಣಾಂಕ op2_minus = 0;
    uint32_t opcode = (1 << 7) | (1 << 4);

    /* Note:
       The argument syntax is exactly the same as in arm_single_data_transfer_opcode, except that there's no STREX argument form.
       The main difference between this function and asm_misc_single_data_transfer_opcode is that the immediate values here must be smaller.
       Also, the combination (P=0, W=1) is unpredictable here.
       The immediate flag has moved to bit index 22--and its meaning has flipped.
       The immediate value itself has been split into two parts: one at bits 11...8, one at bits 3...0
       bit 26 (Load/Store instruction) is unset here.
       bits 7 and 4 are set here. */

    // Here: 0 0 0 P U I W L << 20
    // [compare single data transfer: 0 1 I P U B W L << 20]

    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[0]);
    ಆದರೆ (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    ಇಲ್ಲದಿದ್ದರೆ {
        expect("(destination operand) register");
    }
    ಆದರೆ (tok != ',')
        expect("at least two arguments");
    ಇಲ್ಲದಿದ್ದರೆ
        ಮುಂದಿನ(); // skip ','
    skip('[');
    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[1]);
    ಆದರೆ (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    ಇಲ್ಲದಿದ್ದರೆ {
        expect("(first source operand) register");
    }
    ಆದರೆ (tok == ']') {
        ಮುಂದಿನ();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ಆದರೆ (tok == ',') {
        ಮುಂದಿನ(); // skip ','
        ಆದರೆ (tok == '-') {
            op2_minus = 1;
            ಮುಂದಿನ();
        }
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[2]);
    } ಇಲ್ಲದಿದ್ದರೆ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    ಆದರೆ (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        ಆದರೆ (tok == '!') {
            exclam = 1;
            ಮುಂದಿನ(); // skip '!'
        }
    }

    ಆದರೆ (exclam) {
        ಆದರೆ ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, ಖಾಲಿ));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    ಆದರೆ (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        ಪೂರ್ಣಾಂಕ v = ops[2].e.v;
        ಆದರೆ (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ಆದರೆ (v >= 0) {
            opcode |= 1 << 23; //ಮೇಲೆ
            ಆದರೆ (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ಖಾಲಿ));
            ಇಲ್ಲದಿದ್ದರೆ {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } ಇಲ್ಲದಿದ್ದರೆ { //ಕೆಳಕ್ಕೆ
            ಆದರೆ (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ಖಾಲಿ));
            ಇಲ್ಲದಿದ್ದರೆ {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[2].type == OP_REG32) {
        ಆದರೆ (!op2_minus)
            opcode |= 1 << 23; //ಮೇಲೆ
        opcode |= ops[2].reg;
    } ಇಲ್ಲದಿದ್ದರೆ
        expect("register");

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    ಸ್ಥಿತಿ TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        ನಿಲ್ಲಿಸು;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
ಸ್ಥಿರ uint32_t encbranchoffset(ಪೂರ್ಣಾಂಕ pos, ಪೂರ್ಣಾಂಕ addr, ಪೂರ್ಣಾಂಕ fail)
{
  addr-=pos+8;
  addr/=4;
  ಆದರೆ(addr>=0x7fffff || addr<-0x800000) {
    ಆದರೆ(fail)
      tcc_error("branch offset is too far");
    ಹಿಂತಿರುಗಿ 0;
  }
  ಹಿಂತಿರುಗಿ /*not 0x0A000000|*/(addr&0xffffff);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_branch_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಪೂರ್ಣಾಂಕ jmp_disp = 0;
    ಕಾರ್ಯಾಂಶ op;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
    ElfSym *esym;

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_beq:
    ಸ್ಥಿತಿ TOK_ASM_bleq:
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
        ಆದರೆ (e.sym) {
            esym = elfsym(e.sym);
            ಆದರೆ (esym && esym->st_shndx == cur_ಪಠ್ಯ_section->sh_ಅಂಕೆ) {
                jmp_disp = esym->st_ಮೌಲ್ಯ;
            } ಇಲ್ಲದಿದ್ದರೆ {
                greloca(cur_ಪಠ್ಯ_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        parse_ಕಾರ್ಯಾಂಶ(s1, &op);
        ನಿಲ್ಲಿಸು;
    }
    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_bxeq:
        ಆದರೆ (op.type != OP_REG32)
            expect("register");
        ಇಲ್ಲದಿದ್ದರೆ
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_blxeq:
        ಆದರೆ (op.type != OP_REG32)
            expect("register");
        ಇಲ್ಲದಿದ್ದರೆ
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("branch instruction");
    }
}

ST_FUNC ಶೂನ್ಯ asm_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಆಗ (token == TOK_LINEFEED) {
        ಮುಂದಿನ();
        token = tok;
    }
    ಆದರೆ (token == TOK_EOF)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (token < TOK_ASM_nopeq) { // no condition code
        ಆಯ್ಕೆ (token) {
        ಸ್ಥಿತಿ TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ TOK_ASM_ldc2:
        ಸ್ಥಿತಿ TOK_ASM_ldc2l:
        ಸ್ಥಿತಿ TOK_ASM_stc2:
        ಸ್ಥಿತಿ TOK_ASM_stc2l:
            asm_coprocessor_ದತ್ತಾಂಶ_transfer_opcode(s1, token);
            ಹಿಂತಿರುಗಿ;
        ಪೂರ್ವನಿಯೋಜಿತ:
            expect("instruction");
        }
    }

    ಆಯ್ಕೆ (ARM_INSTRUCTION_ಗುಂಪು(token)) {
    ಸ್ಥಿತಿ TOK_ASM_pusheq:
    ಸ್ಥಿತಿ TOK_ASM_popeq:
    ಸ್ಥಿತಿ TOK_ASM_stmdaeq:
    ಸ್ಥಿತಿ TOK_ASM_ldmdaeq:
    ಸ್ಥಿತಿ TOK_ASM_stmeq:
    ಸ್ಥಿತಿ TOK_ASM_ldmeq:
    ಸ್ಥಿತಿ TOK_ASM_stmiaeq:
    ಸ್ಥಿತಿ TOK_ASM_ldmiaeq:
    ಸ್ಥಿತಿ TOK_ASM_stmdbeq:
    ಸ್ಥಿತಿ TOK_ASM_ldmdbeq:
    ಸ್ಥಿತಿ TOK_ASM_stmibeq:
    ಸ್ಥಿತಿ TOK_ASM_ldmibeq:
        asm_ಖಂಡ_ದತ್ತಾಂಶ_transfer_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_nopeq:
    ಸ್ಥಿತಿ TOK_ASM_wfeeq:
    ಸ್ಥಿತಿ TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_swieq:
    ಸ್ಥಿತಿ TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_beq:
    ಸ್ಥಿತಿ TOK_ASM_bleq:
    ಸ್ಥಿತಿ TOK_ASM_bxeq:
    ಸ್ಥಿತಿ TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_clzeq:
    ಸ್ಥಿತಿ TOK_ASM_sxtbeq:
    ಸ್ಥಿತಿ TOK_ASM_sxtheq:
    ಸ್ಥಿತಿ TOK_ASM_uxtbeq:
    ಸ್ಥಿತಿ TOK_ASM_uxtheq:
    ಸ್ಥಿತಿ TOK_ASM_movteq:
    ಸ್ಥಿತಿ TOK_ASM_movweq:
        asm_ದ್ವಿಮಾನ_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_ldreq:
    ಸ್ಥಿತಿ TOK_ASM_ldrbeq:
    ಸ್ಥಿತಿ TOK_ASM_streq:
    ಸ್ಥಿತಿ TOK_ASM_strbeq:
    ಸ್ಥಿತಿ TOK_ASM_ldrexeq:
    ಸ್ಥಿತಿ TOK_ASM_ldrexbeq:
    ಸ್ಥಿತಿ TOK_ASM_ldrexheq:
    ಸ್ಥಿತಿ TOK_ASM_strexeq:
    ಸ್ಥಿತಿ TOK_ASM_strexbeq:
    ಸ್ಥಿತಿ TOK_ASM_strexheq:
        asm_single_ದತ್ತಾಂಶ_transfer_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_ldrheq:
    ಸ್ಥಿತಿ TOK_ASM_ldrsheq:
    ಸ್ಥಿತಿ TOK_ASM_ldrsbeq:
    ಸ್ಥಿತಿ TOK_ASM_strheq:
       asm_misc_single_ದತ್ತಾಂಶ_transfer_opcode(s1, token);
       ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_andeq:
    ಸ್ಥಿತಿ TOK_ASM_eoreq:
    ಸ್ಥಿತಿ TOK_ASM_subeq:
    ಸ್ಥಿತಿ TOK_ASM_rsbeq:
    ಸ್ಥಿತಿ TOK_ASM_addeq:
    ಸ್ಥಿತಿ TOK_ASM_adceq:
    ಸ್ಥಿತಿ TOK_ASM_sbceq:
    ಸ್ಥಿತಿ TOK_ASM_rsceq:
    ಸ್ಥಿತಿ TOK_ASM_tsteq:
    ಸ್ಥಿತಿ TOK_ASM_teqeq:
    ಸ್ಥಿತಿ TOK_ASM_cmpeq:
    ಸ್ಥಿತಿ TOK_ASM_cmneq:
    ಸ್ಥಿತಿ TOK_ASM_orreq:
    ಸ್ಥಿತಿ TOK_ASM_moveq:
    ಸ್ಥಿತಿ TOK_ASM_biceq:
    ಸ್ಥಿತಿ TOK_ASM_mvneq:
    ಸ್ಥಿತಿ TOK_ASM_andseq:
    ಸ್ಥಿತಿ TOK_ASM_eorseq:
    ಸ್ಥಿತಿ TOK_ASM_subseq:
    ಸ್ಥಿತಿ TOK_ASM_rsbseq:
    ಸ್ಥಿತಿ TOK_ASM_addseq:
    ಸ್ಥಿತಿ TOK_ASM_adcseq:
    ಸ್ಥಿತಿ TOK_ASM_sbcseq:
    ಸ್ಥಿತಿ TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    ಸ್ಥಿತಿ TOK_ASM_orrseq:
    ಸ್ಥಿತಿ TOK_ASM_movseq:
    ಸ್ಥಿತಿ TOK_ASM_bicseq:
    ಸ್ಥಿತಿ TOK_ASM_mvnseq:
        asm_ದತ್ತಾಂಶ_processing_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_lsleq:
    ಸ್ಥಿತಿ TOK_ASM_lslseq:
    ಸ್ಥಿತಿ TOK_ASM_lsreq:
    ಸ್ಥಿತಿ TOK_ASM_lsrseq:
    ಸ್ಥಿತಿ TOK_ASM_asreq:
    ಸ್ಥಿತಿ TOK_ASM_asrseq:
    ಸ್ಥಿತಿ TOK_ASM_roreq:
    ಸ್ಥಿತಿ TOK_ASM_rorseq:
    ಸ್ಥಿತಿ TOK_ASM_rrxseq:
    ಸ್ಥಿತಿ TOK_ASM_rrxeq:
        asm_ಸರಿಸು_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_muleq:
    ಸ್ಥಿತಿ TOK_ASM_mulseq:
    ಸ್ಥಿತಿ TOK_ASM_mlaeq:
    ಸ್ಥಿತಿ TOK_ASM_mlaseq:
    ಸ್ಥಿತಿ TOK_ASM_mlseq:
    ಸ್ಥಿತಿ TOK_ASM_udiveq:
    ಸ್ಥಿತಿ TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_smulleq:
    ಸ್ಥಿತಿ TOK_ASM_smullseq:
    ಸ್ಥಿತಿ TOK_ASM_umulleq:
    ಸ್ಥಿತಿ TOK_ASM_umullseq:
    ಸ್ಥಿತಿ TOK_ASM_smlaleq:
    ಸ್ಥಿತಿ TOK_ASM_smlalseq:
    ಸ್ಥಿತಿ TOK_ASM_umlaleq:
    ಸ್ಥಿತಿ TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_cdpeq:
    ಸ್ಥಿತಿ TOK_ASM_mcreq:
    ಸ್ಥಿತಿ TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_ldceq:
    ಸ್ಥಿತಿ TOK_ASM_ldcleq:
    ಸ್ಥಿತಿ TOK_ASM_stceq:
    ಸ್ಥಿತಿ TOK_ASM_stcleq:
        asm_coprocessor_ದತ್ತಾಂಶ_transfer_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

#ಆದರೆ defined(TCC_ARM_VFP)
    ಸ್ಥಿತಿ TOK_ASM_vldreq:
    ಸ್ಥಿತಿ TOK_ASM_vstreq:
        asm_floating_ಬಿಂದು_single_ದತ್ತಾಂಶ_transfer_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_vmlaeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vmlseq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vnmlseq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vnmlaeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vmuleq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vnmuleq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vaddeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vsubeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vdiveq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vnegeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vabseq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vsqrteq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcmpeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcmpeeq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vmoveq_f32:
    ಸ್ಥಿತಿ TOK_ASM_vmlaeq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vmlseq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vnmlseq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vnmlaeq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vmuleq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vnmuleq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vaddeq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vsubeq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vdiveq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vnegeq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vabseq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vsqrteq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcmpeq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcmpeeq_f64:
    ಸ್ಥಿತಿ TOK_ASM_vmoveq_f64:
        asm_floating_ಬಿಂದು_ದತ್ತಾಂಶ_processing_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_vcvtreq_s32_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvtreq_s32_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_s32_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_s32_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcvtreq_u32_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvtreq_u32_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_u32_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_u32_f64:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f64_s32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f32_s32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f64_u32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f32_u32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f64_f32:
    ಸ್ಥಿತಿ TOK_ASM_vcvteq_f32_f64:
        asm_floating_ಬಿಂದು_vcvt_ದತ್ತಾಂಶ_processing_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_vpusheq:
    ಸ್ಥಿತಿ TOK_ASM_vpopeq:
    ಸ್ಥಿತಿ TOK_ASM_vldmeq:
    ಸ್ಥಿತಿ TOK_ASM_vldmiaeq:
    ಸ್ಥಿತಿ TOK_ASM_vldmdbeq:
    ಸ್ಥಿತಿ TOK_ASM_vstmeq:
    ಸ್ಥಿತಿ TOK_ASM_vstmiaeq:
    ಸ್ಥಿತಿ TOK_ASM_vstmdbeq:
        asm_floating_ಬಿಂದು_ಖಂಡ_ದತ್ತಾಂಶ_transfer_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_vmsreq:
    ಸ್ಥಿತಿ TOK_ASM_vmrseq:
        asm_floating_ಬಿಂದು_ಸ್ಥಿತಿ_ರಿಜಿಸ್ಟರ್_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;
#ಆದರೆ_ಅಂತ್ಯ

    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("known instruction");
    }
}

ST_FUNC ಶೂನ್ಯ subst_asm_ಕಾರ್ಯಾಂಶ(CString *ಕೂಡಿಸು_str, SValue *sv, ಪೂರ್ಣಾಂಕ modifier)
{
    ಪೂರ್ಣಾಂಕ r, reg, ಗಾತ್ರ_2, val;

    r = sv->r;
    ಆದರೆ ((r & VT_VALMASK) == VT_CONST) {
        ಆದರೆ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(ಕೂಡಿಸು_str, '#');
        ಆದರೆ (r & VT_SYM) {
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = get_tok_str(sv->sym->v, ಖಾಲಿ);
            ಆದರೆ (sv->sym->v >= SYM_ಮೊದಲ_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name))->tok, sv->sym);
            }
            ಆದರೆ (tcc_state->leading_underscore)
                cstr_ccat(ಕೂಡಿಸು_str, '_');
            cstr_cat(ಕೂಡಿಸು_str, name, -1);
            ಆದರೆ ((uint32_t) sv->c.i == 0)
                ಹೋಗು no_ಸ್ಥಾನಾಂತರ;
            cstr_ccat(ಕೂಡಿಸು_str, '+');
        }
        val = sv->c.i;
        ಆದರೆ (modifier == 'n')
            val = -val;
        cstr_printf(ಕೂಡಿಸು_str, "%d", val);
      no_ಸ್ಥಾನಾಂತರ:;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(ಕೂಡಿಸು_str, "[fp,#%d]", (ಪೂರ್ಣಾಂಕ) sv->c.i);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ಆದರೆ (reg >= VT_CONST)
            tcc_ಆಂತರಿಕ_error("");
        cstr_printf(ಕೂಡಿಸು_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, ಖಾಲಿ));
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* register case */
        reg = r & VT_VALMASK;
        ಆದರೆ (reg >= VT_CONST)
            tcc_ಆಂತರಿಕ_error("");

        /* choose register operand size */
        ಆದರೆ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            ಗಾತ್ರ_2 = 1;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            ಗಾತ್ರ_2 = 2;
        ಇಲ್ಲದಿದ್ದರೆ
            ಗಾತ್ರ_2 = 4;

        ಆದರೆ (modifier == 'b') {
            ಗಾತ್ರ_2 = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (modifier == 'w') {
            ಗಾತ್ರ_2 = 2;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (modifier == 'k') {
            ಗಾತ್ರ_2 = 4;
        }

        ಆಯ್ಕೆ (ಗಾತ್ರ_2) {
        ಪೂರ್ವನಿಯೋಜಿತ:
            reg = TOK_ASM_r0 + reg;
            ನಿಲ್ಲಿಸು;
        }
        cstr_printf(ಕೂಡಿಸು_str, "%s", get_tok_str(reg, ಖಾಲಿ));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC ಶೂನ್ಯ asm_gen_ಸಂಕೇತ(ASMOperand *operands, ಪೂರ್ಣಾಂಕ nb_operands,
                          ಪೂರ್ಣಾಂಕ nb_outputs, ಪೂರ್ಣಾಂಕ is_output,
                          uint8_t *clobber_regs,
                          ಪೂರ್ಣಾಂಕ ಹೊರಹೋಗು_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ಪೂರ್ಣಾಂಕ i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    ಸ್ಮರಣೆ_ನಕಲು(regs_allocated, clobber_regs, ಗಾತ್ರ(regs_allocated));
    ಗಾಗಿ(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        ಆದರೆ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    ಗಾಗಿ(i = 0; i < ಗಾತ್ರ(reg_saved)/ಗಾತ್ರ(reg_saved[0]); i++) {
        reg = reg_saved[i];
        ಆದರೆ (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    ಆದರೆ (!is_output) { // prolog
        /* generate reg save code */
        ಆದರೆ (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        ಗಾಗಿ(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ಆದರೆ (op->reg >= 0) {
                ಆದರೆ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_ಸ್ಮರಣೆ) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    ತುಂಬು(op->reg, &sv);
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    ತುಂಬು(op->reg, op->vt);
                    ಆದರೆ (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } ಇಲ್ಲದಿದ್ದರೆ { // epilog
        /* generate save code */
        ಗಾಗಿ(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ಆದರೆ (op->reg >= 0) {
                ಆದರೆ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ಆದರೆ (!op->is_ಸ್ಮರಣೆ) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        ತುಂಬು(ಹೊರಹೋಗು_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | ಹೊರಹೋಗು_reg;
                        store(op->reg, &sv);
                    }
                } ಇಲ್ಲದಿದ್ದರೆ {
                    store(op->reg, op->vt);
                    ಆದರೆ (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        ಆದರೆ (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ constraint_ಆದ್ಯತೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    ಪೂರ್ಣಾಂಕ ಆದ್ಯತೆ, c, pr;

    /* we take the lowest priority */
    ಆದ್ಯತೆ = 0;
    ಗಾಗಿ(;;) {
        c = *str;
        ಆದರೆ (c == '\0')
            ನಿಲ್ಲಿಸು;
        str++;
        ಆಯ್ಕೆ(c) {
        ಸ್ಥಿತಿ 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        ಸ್ಥಿತಿ 'r': // register [general]
        ಸ್ಥಿತಿ 'p': // valid memory address for load,store [general]
            pr = 3;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'M': // integer constant for shifts [ARM]
        ಸ್ಥಿತಿ 'I': // integer valid for data processing instruction immediate
        ಸ್ಥಿತಿ 'J': // integer in range -4095...4095

        ಸ್ಥಿತಿ 'i': // immediate integer operand, including symbolic constants [general]
        ಸ್ಥಿತಿ 'm': // memory operand [general]
        ಸ್ಥಿತಿ 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("unknown constraint '%c'", c);
        }
        ಆದರೆ (pr > ಆದ್ಯತೆ)
            ಆದ್ಯತೆ = pr;
    }
    ಹಿಂತಿರುಗಿ ಆದ್ಯತೆ;
}

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *skip_constraint_modifiers(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    ಆಗ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ಹಿಂತಿರುಗಿ p;
}

#ವ್ಯಾಖ್ಯಾನಿಸು REG_ಹೊರಹೋಗು_ಮುಖವಾಡ 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು REG_ಒಳ_ಮುಖವಾಡ  0x02

#ವ್ಯಾಖ್ಯಾನಿಸು is_reg_allocated(reg) (regs_allocated[reg] & reg_ಮುಖವಾಡ)

ST_FUNC ಶೂನ್ಯ asm_compute_constraints(ASMOperand *operands,
                                    ಪೂರ್ಣಾಂಕ nb_operands, ಪೂರ್ಣಾಂಕ nb_outputs,
                                    ಸ್ಥಿರಾಂಕ uint8_t *clobber_regs,
                                    ಪೂರ್ಣಾಂಕ *pout_reg)
{
    /* overall format: modifier, then ,-seperated list of alternatives; all operands for a single instruction must have the same number of alternatives */
    /* TODO: Simple constraints
        whitespace  ignored
        o  memory operand that is offsetable
        V  memory but not offsetable
        <  memory operand with autodecrement addressing is allowed.  Restrictions apply.
        >  memory operand with autoincrement addressing is allowed.  Restrictions apply.
        n  immediate integer operand with a known numeric value
        E  immediate floating operand (const_double) is allowed, but only if target=host
        F  immediate floating operand (const_double or const_vector) is allowed
        s  immediate integer operand whose value is not an explicit integer
        X  any operand whatsoever
        0...9 (postfix); (can also be more than 1 digit number);  an operand that matches the specified operand number is allowed
    */

    /* TODO: ARM constraints:
        k the stack pointer register
        G the floating-point constant 0.0
        Q memory reference where the exact address is in a single register ("m" is preferable for asm statements)
        R an item in the constant pool
        S symbol in the text segment of the current file
[       Uv memory reference suitable for VFP load/store insns (reg+constant offset)]
[       Uy memory reference suitable for iWMMXt load/store instructions]
        Uq memory reference suitable for the ARMv4 ldrsb instruction
    */
    ASMOperand *op;
    ಪೂರ್ಣಾಂಕ sorted_op[MAX_ASM_OPERANDS];
    ಪೂರ್ಣಾಂಕ i, j, k, p1, p2, tmp, reg, c, reg_ಮುಖವಾಡ;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ = -1;
        op->ref_ಸೂಚ್ಯಂಕ = -1;
        op->reg = -1;
        op->is_ಸ್ಮರಣೆ = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ಆದರೆ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = ಕಂಡುಹಿಡಿ_constraint(operands, nb_operands, str, ಖಾಲಿ);
            ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_ಸೂಚ್ಯಂಕ = k;
            ಆದರೆ (operands[k].ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ = i;
            op->ಆದ್ಯತೆ = 5;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->ಆದ್ಯತೆ = 1;
            op->reg = reg;
        } ಇಲ್ಲದಿದ್ದರೆ {
            op->ಆದ್ಯತೆ = constraint_ಆದ್ಯತೆ(str);
        }
    }

    /* sort operands according to their priority */
    ಗಾಗಿ (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    ಗಾಗಿ (i = 0; i < nb_operands - 1; i++) {
        ಗಾಗಿ (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].ಆದ್ಯತೆ;
            p2 = operands[sorted_op[j]].ಆದ್ಯತೆ;
            ಆದರೆ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    ಗಾಗಿ (i = 0; i < NB_ASM_REGS; i++) {
        ಆದರೆ (clobber_regs[i])
            regs_allocated[i] = REG_ಒಳ_ಮುಖವಾಡ | REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
        ಇಲ್ಲದಿದ್ದರೆ
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_ಒಳ_ಮುಖವಾಡ | REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_ಒಳ_ಮುಖವಾಡ | REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;

    /* allocate registers and generate corresponding asm moves */
    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ಆದರೆ (op->ref_ಸೂಚ್ಯಂಕ >= 0)
            ಮುಂದುವರಿ;
        /* select if register is used for output, input or both */
        ಆದರೆ (op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ >= 0) {
            reg_ಮುಖವಾಡ = REG_ಒಳ_ಮುಖವಾಡ | REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (j < nb_outputs) {
            reg_ಮುಖವಾಡ = REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            reg_ಮುಖವಾಡ = REG_ಒಳ_ಮುಖವಾಡ;
        }
        ಆದರೆ (op->reg >= 0) {
            ಆದರೆ (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_ಮುಂದಿನ:
        c = *str++;
        ಆಯ್ಕೆ (c) {
        ಸ್ಥಿತಿ '=': // Operand is written-to
            ಹೋಗು try_ಮುಂದಿನ;
        ಸ್ಥಿತಿ '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        ಸ್ಥಿತಿ '&': // Operand is clobbered before the instruction is done using the input operands
            ಆದರೆ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_ಮುಖವಾಡ = REG_ಒಳ_ಮುಖವಾಡ | REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
            ಹೋಗು try_ಮುಂದಿನ;
        ಸ್ಥಿತಿ 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        ಸ್ಥಿತಿ 'r': // general-purpose register
        ಸ್ಥಿತಿ 'p': // loadable/storable address
            /* any general register */
            ಆದರೆ ((reg = op->reg) >= 0)
                ಹೋಗು reg_ಸಿಕ್ಕಿತು;
            ಇಲ್ಲದಿದ್ದರೆ ಗಾಗಿ (reg = 0; reg <= 8; reg++) {
                ಆದರೆ (!is_reg_allocated(reg))
                    ಹೋಗು reg_ಸಿಕ್ಕಿತು;
            }
            ಹೋಗು try_ಮುಂದಿನ;
          reg_ಸಿಕ್ಕಿತು:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_ಮುಖವಾಡ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        ಸ್ಥಿತಿ 'J': // integer in the range -4095 to 4095 [ARM]
        ಸ್ಥಿತಿ 'K': // integer that satisfies constraint I when inverted (one's complement)
        ಸ್ಥಿತಿ 'L': // integer that satisfies constraint I when inverted (two's complement)
        ಸ್ಥಿತಿ 'i': // immediate integer operand, including symbolic constants
            ಆದರೆ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'M': // integer in the range 0 to 32
            ಆದರೆ (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'm': // memory operand
        ಸ್ಥಿತಿ 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ಆದರೆ (j < nb_outputs || c == 'm') {
                ಆದರೆ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    ಗಾಗಿ (reg = 0; reg <= 8; reg++) {
                        ಆದರೆ (!(regs_allocated[reg] & REG_ಒಳ_ಮುಖವಾಡ))
                            ಹೋಗು reg_found1;
                    }
                    ಹೋಗು try_ಮುಂದಿನ;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_ಒಳ_ಮುಖವಾಡ;
                    op->reg = reg;
                    op->is_ಸ್ಮರಣೆ = 1;
                }
            }
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            ನಿಲ್ಲಿಸು;
        }
        /* if a reference is present for that operand, we assign it too */
        ಆದರೆ (op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ >= 0) {
            operands[op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ].reg = op->reg;
            operands[op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ಆದರೆ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_ಸ್ಮರಣೆ) {
            ಗಾಗಿ (reg = 0; reg <= 8; reg++) {
                ಆದರೆ (!(regs_allocated[reg] & REG_ಹೊರಹೋಗು_ಮುಖವಾಡ))
                    ಹೋಗು reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            ನಿಲ್ಲಿಸು;
        }
    }

    /* print sorted constraints */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ASM_DEBUG
    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        ಬರೆ("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ಖಾಲಿ) : "",
               op->constraint, op->vt->r, op->reg);
    }
    ಆದರೆ (*pout_reg >= 0)
        ಬರೆ("out_reg=%d\n", *pout_reg);
#ಆದರೆ_ಅಂತ್ಯ
}

ST_FUNC ಶೂನ್ಯ asm_clobber(uint8_t *clobber_regs, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    ಪೂರ್ಣಾಂಕ reg;
    TokenSym *ts;

    ಆದರೆ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ಹಿಂತಿರುಗಿ;
    ts = tok_alloc(str, ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(str));
    reg = asm_parse_regvar(ts->tok);
    ಆದರೆ (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC ಪೂರ್ಣಾಂಕ asm_parse_regvar (ಪೂರ್ಣಾಂಕ t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    ಆದರೆ (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        ಹಿಂತಿರುಗಿ -1;

    ಆದರೆ (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        ಹಿಂತಿರುಗಿ t - TOK_ASM_r0;

    ಆದರೆ (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        ಹಿಂತಿರುಗಿ t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    ಹಿಂತಿರುಗಿ t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#ಆದರೆ_ಅಂತ್ಯ /* ndef TARGET_DEFS_ONLY */
