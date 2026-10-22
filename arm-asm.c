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

#ifdef TARGET_DEFS_ONLY

#define CONFIG_TCC_ASM
#define NB_ASM_REGS 16

ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC ಶೂನ್ಯ gen_le16(ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC ಶೂನ್ಯ gen_le32(ಪೂರ್ಣಾಙ್ಕ c);

/*************************************************************/
#ಅನ್ಯಥಾ
/*************************************************************/

#define USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"

ಗಣನಾ {
    OPT_REG32,
    OPT_REGSET32,
    OPT_IM8,
    OPT_IM8N,
    OPT_IM32,
    OPT_VREG32,
    OPT_VREG64,
};
#define OP_REG32  (1 << OPT_REG32)
#define OP_VREG32 (1 << OPT_VREG32)
#define OP_VREG64 (1 << OPT_VREG64)
#define OP_REG    (OP_REG32 | OP_VREG32 | OP_VREG64)
#define OP_IM32   (1 << OPT_IM32)
#define OP_IM8   (1 << OPT_IM8)
#define OP_IM8N   (1 << OPT_IM8N)
#define OP_REGSET32  (1 << OPT_REGSET32)

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ Operand {
    uint32_t type;
    ಸಙ್ಘ {
        uint8_t reg;
        uint16_t regset;
        ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
    };
} Operand;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ asm_parse_vfp_regvar(ಪೂರ್ಣಾಙ್ಕ t, ಪೂರ್ಣಾಙ್ಕ double_precision)
{
    ಯದಿ (double_precision) {
        ಯದಿ (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            ಪ್ರತ್ಯಾಗಮ t - TOK_ASM_d0;
    } ಅನ್ಯಥಾ {
        ಯದಿ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            ಪ್ರತ್ಯಾಗಮ t - TOK_ASM_s0;
    }
    ಪ್ರತ್ಯಾಗಮ -1;
}

/* Parse a text containing operand and store the result in OP */
ಸ್ಥಿರ ಶೂನ್ಯ parse_operand(TCCState *s1, Operand *op)
{
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    ಯದಿ (tok == '{') { // regset literal
        next(); // skip '{'
        ಯಾವತ್ (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            ಯದಿ (reg == -1) {
                expect("register");
            } ಅನ್ಯಥಾ
                next(); // skip register name

            ಯದಿ ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            ಯದಿ (tok != ',')
                ಭಙ್ಗ;
            next(); // skip ','
        }
        skip('}');
        ಯದಿ (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } ಅನ್ಯಥಾ {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        ಪ್ರತ್ಯಾಗಮ;
    } ಅನ್ಯಥಾ ಯದಿ ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        ಪ್ರತ್ಯಾಗಮ;
    } ಅನ್ಯಥಾ ಯದಿ ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        next(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        ಪ್ರತ್ಯಾಗಮ;
    } ಅನ್ಯಥಾ ಯದಿ ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        next(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        ಪ್ರತ್ಯಾಗಮ;
    } ಅನ್ಯಥಾ ಯದಿ (tok == '#' || tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    }
    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    ಯದಿ (!op->e.sym) {
        ಯದಿ ((ಪೂರ್ಣಾಙ್ಕ) op->e.v < 0 && (ಪೂರ್ಣಾಙ್ಕ) op->e.v >= -255)
            op->type = OP_IM8N;
        ಅನ್ಯಥಾ ಯದಿ (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } ಅನ್ಯಥಾ
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಙ್ಕ c)
{
    ಪೂರ್ಣಾಙ್ಕ ind1;
    ಯದಿ (nocode_wanted)
        ಪ್ರತ್ಯಾಗಮ;
    ind1 = ind + 1;
    ಯದಿ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC ಶೂನ್ಯ gen_le16 (ಪೂರ್ಣಾಙ್ಕ i)
{
    g(i);
    g(i>>8);
}

ST_FUNC ಶೂನ್ಯ gen_le32 (ಪೂರ್ಣಾಙ್ಕ i)
{
    ಪೂರ್ಣಾಙ್ಕ ind1;
    ಯದಿ (nocode_wanted)
        ಪ್ರತ್ಯಾಗಮ;
    ind1 = ind + 4;
    ಯದಿ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC ಶೂನ್ಯ gen_expr32(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    gen_le32(pe->v);
}

ಸ್ಥಿರ uint32_t condition_code_of_token(ಪೂರ್ಣಾಙ್ಕ token) {
    ಯದಿ (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } ಅನ್ಯಥಾ
        ಪ್ರತ್ಯಾಗಮ (token - TOK_ASM_nopeq) & 15;
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_opcode(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode) {
    gen_le32((condition_code_of_token(token) << 28) | opcode);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_coprocessor_opcode(uint32_t ಮೇಲಿನ_nibble, uint8_t cp_ಸಂಖ್ಯೆ, uint8_t cp_opcode, uint8_t cp_destination_register, uint8_t cp_n_operand_register, uint8_t cp_m_operand_register, uint8_t cp_opcode2, ಪೂರ್ಣಾಙ್ಕ inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    ಯದಿ (inter_processor_transfer)
        opcode |= 1 << 4;
    //assert(cp_opcode < 16);
    opcode |= cp_opcode << 20;
    //assert(cp_n_operand_register < 16);
    opcode |= cp_n_operand_register << 16;
    //assert(cp_destination_register < 16);
    opcode |= cp_destination_register << 12;
    //assert(cp_number < 16);
    opcode |= cp_ಸಂಖ್ಯೆ << 8;
    //assert(cp_information < 8);
    opcode |= cp_opcode2 << 5;
    //assert(cp_m_operand_register < 16);
    opcode |= cp_m_operand_register;
    asm_emit_unconditional_opcode((ಮೇಲಿನ_nibble << 28) | opcode);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_nullary_opcode(ಪೂರ್ಣಾಙ್ಕ token)
{
    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    ಪಕ್ಷ TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("nullary instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_unary_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand op;
    parse_operand(s1, &op);

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_swieq:
    ಪಕ್ಷ TOK_ASM_svceq:
        ಯದಿ (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        ಅನ್ಯಥಾ {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("unary instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_ದ್ವಿಮಾನ_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand ops[2];
    Operand rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);
    ಯದಿ (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    ಯದಿ (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ರಿಕ್ತ));

    ಯದಿ (ops[1].type != OP_REG32) {
        ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
        ಪಕ್ಷ TOK_ASM_movteq:
        ಪಕ್ಷ TOK_ASM_movweq:
            ಯದಿ (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                ಯದಿ (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t immediate_ಮೌಲ್ಯ = ops[1].e.v;
                    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
                    ಪಕ್ಷ TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (immediate_ಮೌಲ್ಯ & 0xF000) << 4 | (immediate_ಮೌಲ್ಯ & 0xFFF));
                        ಭಙ್ಗ;
                    ಪಕ್ಷ TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (immediate_ಮೌಲ್ಯ & 0xF000) << 4 | (immediate_ಮೌಲ್ಯ & 0xFFF));
                        ಭಙ್ಗ;
                    }
                } ಅನ್ಯಥಾ
                    expect("(source operand) immediate 16 bit value");
            } ಅನ್ಯಥಾ
                expect("(source operand) immediate");
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            expect("(source operand) register");
        }
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ರಿಕ್ತ));

    ಯದಿ (tok == ',') {
        next(); // skip ','
        ಯದಿ (tok == TOK_ASM_ror) {
            next(); // skip 'ror'
            parse_operand(s1, &rotation);
            ಯದಿ (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } ಅನ್ಯಥಾ {
                amount = rotation.e.v;
                ವಿಕಲ್ಪ (amount) {
                ಪಕ್ಷ 8:
                    encoded_rotation = 1 << 10;
                    ಭಙ್ಗ;
                ಪಕ್ಷ 16:
                    encoded_rotation = 2 << 10;
                    ಭಙ್ಗ;
                ಪಕ್ಷ 24:
                    encoded_rotation = 3 << 10;
                    ಭಙ್ಗ;
                ಸ್ವಭಾವ:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_clzeq:
        ಯದಿ (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("binary instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_coprocessor_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token) {
    uint8_t coprocessor;
    Operand opcode1;
    Operand opcode2;
    uint8_t registers[3];
    unsigned ಪೂರ್ಣಾಙ್ಕ i;
    uint8_t ಮೇಲಿನ_nibble;
    uint8_t mrc = 0;

    ಯದಿ (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } ಅನ್ಯಥಾ {
        expect("'p<number>'");
    }
    skip(',');
    parse_operand(s1, &opcode1);
    ಯದಿ (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ರಿಕ್ತ));
    }

    ಪ್ರತಿ (i = 0; i < 3; ++i) {
        skip(',');
        ಯದಿ (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mcreq)) {
            ಯದಿ (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                next();
            } ಅನ್ಯಥಾ {
                expect("'r<number>'");
            }
        } ಅನ್ಯಥಾ {
            ಯದಿ (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                next();
            } ಅನ್ಯಥಾ {
                expect("'c<number>'");
            }
        }
    }
    ಯದಿ (tok == ',') {
        next();
        parse_operand(s1, &opcode2);
    } ಅನ್ಯಥಾ {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    ಯದಿ (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (token == TOK_ASM_cdp2) {
        ಮೇಲಿನ_nibble = 0xF;
        asm_emit_coprocessor_opcode(ಮೇಲಿನ_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        ಪ್ರತ್ಯಾಗಮ;
    } ಅನ್ಯಥಾ
        ಮೇಲಿನ_nibble = condition_code_of_token(token);

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(ಮೇಲಿನ_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        ಯದಿ (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, ರಿಕ್ತ));
        }
        asm_emit_coprocessor_opcode(ಮೇಲಿನ_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("known instruction");
    }
}

/* data processing and single data transfer instructions only */
#define ENCODE_RN(register_index) ((register_index) << 16)
#define ENCODE_RD(register_index) ((register_index) << 12)
#define ENCODE_SET_CONDITION_CODES (1 << 20)

/* Note: For data processing instructions, "1" means immediate.
   Note: For single data transfer instructions, "0" means immediate. */
#define ENCODE_IMMEDIATE_FLAG (1 << 25)

#define ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER (1 << 4)
#define ENCODE_BARREL_SHIFTER_MODE_LSL (0 << 5)
#define ENCODE_BARREL_SHIFTER_MODE_LSR (1 << 5)
#define ENCODE_BARREL_SHIFTER_MODE_ASR (2 << 5)
#define ENCODE_BARREL_SHIFTER_MODE_ROR (3 << 5)
#define ENCODE_BARREL_SHIFTER_REGISTER(register_index) ((register_index) << 8)
#define ENCODE_BARREL_SHIFTER_IMMEDIATE(ಮೌಲ್ಯ) ((ಮೌಲ್ಯ) << 7)

ಸ್ಥಿರ ಶೂನ್ಯ asm_block_data_transfer_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    uint32_t opcode;
    ಪೂರ್ಣಾಙ್ಕ op0_exclam = 0;
    Operand ops[2];
    ಪೂರ್ಣಾಙ್ಕ nb_ops = 1;
    parse_operand(s1, &ops[0]);
    ಯದಿ (tok == '!') {
        op0_exclam = 1;
        next(); // skip '!'
    }
    ಯದಿ (tok == ',') {
        next(); // skip comma
        parse_operand(s1, &ops[1]);
        ++nb_ops;
    }
    ಯದಿ (nb_ops < 1) {
        expect("at least one operand");
    } ಅನ್ಯಥಾ ಯದಿ (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        ಯದಿ (nb_ops != 1)
            expect("exactly one operand");
        ಅನ್ಯಥಾ
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        ಯದಿ (nb_ops != 1)
            expect("exactly one operand");
        ಅನ್ಯಥಾ
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_stmdaeq:
    ಪಕ್ಷ TOK_ASM_ldmdaeq:
    ಪಕ್ಷ TOK_ASM_stmeq:
    ಪಕ್ಷ TOK_ASM_ldmeq:
    ಪಕ್ಷ TOK_ASM_stmiaeq:
    ಪಕ್ಷ TOK_ASM_ldmiaeq:
    ಪಕ್ಷ TOK_ASM_stmdbeq:
    ಪಕ್ಷ TOK_ASM_ldmdbeq:
    ಪಕ್ಷ TOK_ASM_stmibeq:
    ಪಕ್ಷ TOK_ASM_ldmibeq:
        ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
        ಪಕ್ಷ TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_stmeq: // post-increment store
        ಪಕ್ಷ TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_ldmeq: // post-increment load
        ಪಕ್ಷ TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        ಯದಿ (nb_ops != 2)
            expect("exactly two operands");
        ಅನ್ಯಥಾ ಯದಿ (ops[0].type != OP_REG32)
            expect("(first operand) register");
        ಅನ್ಯಥಾ {
            ಯದಿ (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
ಸ್ಥಿರ uint32_t asm_parse_optional_shift(TCCState* s1, ಪೂರ್ಣಾಙ್ಕ* nb_shift, Operand* shift)
{
    uint32_t opcode = 0;
    *nb_shift = 0;
    ವಿಕಲ್ಪ (tok) {
    ಪಕ್ಷ TOK_ASM_asl:
    ಪಕ್ಷ TOK_ASM_lsl:
    ಪಕ್ಷ TOK_ASM_asr:
    ಪಕ್ಷ TOK_ASM_lsr:
    ಪಕ್ಷ TOK_ASM_ror:
        ವಿಕಲ್ಪ (tok) {
        ಪಕ್ಷ TOK_ASM_asl:
            /* fallthrough */
        ಪಕ್ಷ TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSL;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ASR;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSR;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
            ಭಙ್ಗ;
        }
        next();
        parse_operand(s1, shift);
        *nb_shift = 1;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_rrx:
        next();
        opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
        ಭಙ್ಗ;
    }
    ಪ್ರತ್ಯಾಗಮ opcode;
}

ಸ್ಥಿರ uint32_t asm_encode_shift(Operand* shift)
{
    uint64_t amount;
    uint32_t operands = 0;
    ವಿಕಲ್ಪ (shift->type) {
    ಪಕ್ಷ OP_REG32:
        ಯದಿ (shift->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        ಅನ್ಯಥಾ {
            operands = ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER;
            operands |= ENCODE_BARREL_SHIFTER_REGISTER(shift->reg);
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ OP_IM8:
        amount = shift->e.v;
        ಯದಿ (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_IMMEDIATE(amount);
        ಅನ್ಯಥಾ
            tcc_error("shift count out of range");
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        tcc_error("unknown shift amount");
    }
    ಪ್ರತ್ಯಾಗಮ operands;
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_data_processing_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand ops[3];
    ಪೂರ್ಣಾಙ್ಕ nb_ops;
    Operand shift = {0};
    ಪೂರ್ಣಾಙ್ಕ nb_shift = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_GROUP(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    ಪ್ರತಿ (nb_ops = 0; nb_ops < ಪರಿಮಾಣ(ops)/ಪರಿಮಾಣ(ops[0]); ) {
        ಯದಿ (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            ಭಙ್ಗ;
        parse_operand(s1, &ops[nb_ops]);
        ++nb_ops;
        ಯದಿ (tok != ',')
            ಭಙ್ಗ;
        next(); // skip ','
    }
    ಯದಿ (tok == ',')
        next();
    operands |= asm_parse_optional_shift(s1, &nb_shift, &shift);
    ಯದಿ (nb_ops < 2)
        expect("at least two operands");
    ಅನ್ಯಥಾ ಯದಿ (nb_ops == 2) {
        memcpy(&ops[2], &ops[1], ಪರಿಮಾಣ(ops[1])); // move ops[2]
        memcpy(&ops[1], &ops[0], ಪರಿಮಾಣ(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } ಅನ್ಯಥಾ ಯದಿ (nb_ops == 3) {
        ಯದಿ (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, ರಿಕ್ತ));
        }
    }
    ಯದಿ (nb_ops != 3) {
        expect("two or three operands");
    } ಅನ್ಯಥಾ {
        uint32_t opcode = 0;
        uint32_t immediate_ಮೌಲ್ಯ;
        uint8_t half_immediate_rotation;
        ಯದಿ (nb_shift && shift.type == OP_REG32) {
            ಯದಿ ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
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
        ಯದಿ (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        ಅನ್ಯಥಾ ಯದಿ (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_SET_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        ಅನ್ಯಥಾ
            operands |= ENCODE_RD(ops[0].reg);
        ಯದಿ (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        ಅನ್ಯಥಾ ಯದಿ (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        ವಿಕಲ್ಪ (ops[2].type) {
        ಪಕ್ಷ OP_REG32:
            operands |= ops[2].reg;
            ಭಙ್ಗ;
        ಪಕ್ಷ OP_IM8:
        ಪಕ್ಷ OP_IM32:
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_ಮೌಲ್ಯ = ops[2].e.v;
            ಪ್ರತಿ (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                ಯದಿ (immediate_ಮೌಲ್ಯ >= 0x00 && immediate_ಮೌಲ್ಯ < 0x100)
                    ಭಙ್ಗ;
                // rotate left by two
                immediate_ಮೌಲ್ಯ = ((immediate_ಮೌಲ್ಯ & 0x3FFFFFFF) << 2) | ((immediate_ಮೌಲ್ಯ & 0xC0000000) >> 30);
            }
            ಯದಿ (half_immediate_rotation >= 16) {
                /* fallthrough */
            } ಅನ್ಯಥಾ {
                operands |= immediate_ಮೌಲ್ಯ;
                operands |= half_immediate_rotation << 8;
                ಭಙ್ಗ;
            }
        ಪಕ್ಷ OP_IM8N: // immediate negative value
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_ಮೌಲ್ಯ = ops[2].e.v;
            /* Instruction swapping:
               0001 = EOR - Rd:= Op1 EOR Op2     -> difficult
               0011 = RSB - Rd:= Op2 - Op1       -> difficult
               0111 = RSC - Rd:= Op2 - Op1 + C   -> difficult
               1000 = TST - CC on: Op1 AND Op2   -> difficult
               1001 = TEQ - CC on: Op1 EOR Op2   -> difficult
               1100 = ORR - Rd:= Op1 OR Op2      -> difficult
            */
            ವಿಕಲ್ಪ (opcode_nos) {
            ಪಕ್ಷ 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                immediate_ಮೌಲ್ಯ = ~immediate_ಮೌಲ್ಯ;
                ಭಙ್ಗ;
            ಪಕ್ಷ 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; // ADD
                immediate_ಮೌಲ್ಯ = -immediate_ಮೌಲ್ಯ;
                ಭಙ್ಗ;
            ಪಕ್ಷ 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                immediate_ಮೌಲ್ಯ = -immediate_ಮೌಲ್ಯ;
                ಭಙ್ಗ;
            ಪಕ್ಷ 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                immediate_ಮೌಲ್ಯ = ~immediate_ಮೌಲ್ಯ;
                ಭಙ್ಗ;
            ಪಕ್ಷ 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                immediate_ಮೌಲ್ಯ = ~immediate_ಮೌಲ್ಯ;
                ಭಙ್ಗ;
            ಪಕ್ಷ 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                immediate_ಮೌಲ್ಯ = -immediate_ಮೌಲ್ಯ;
                ಭಙ್ಗ;
            ಪಕ್ಷ 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                immediate_ಮೌಲ್ಯ = -immediate_ಮೌಲ್ಯ;
                ಭಙ್ಗ;
            ಪಕ್ಷ 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                immediate_ಮೌಲ್ಯ = ~immediate_ಮೌಲ್ಯ;
                ಭಙ್ಗ;
            ಪಕ್ಷ 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                immediate_ಮೌಲ್ಯ = ~immediate_ಮೌಲ್ಯ;
                ಭಙ್ಗ;
            ಪಕ್ಷ 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                immediate_ಮೌಲ್ಯ = ~immediate_ಮೌಲ್ಯ;
                ಭಙ್ಗ;
            ಸ್ವಭಾವ:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, ರಿಕ್ತ));
            }
            ಪ್ರತಿ (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                ಯದಿ (immediate_ಮೌಲ್ಯ >= 0x00 && immediate_ಮೌಲ್ಯ < 0x100)
                    ಭಙ್ಗ;
                // rotate left by two
                immediate_ಮೌಲ್ಯ = ((immediate_ಮೌಲ್ಯ & 0x3FFFFFFF) << 2) | ((immediate_ಮೌಲ್ಯ & 0xC0000000) >> 30);
            }
            ಯದಿ (half_immediate_rotation >= 16) {
                immediate_ಮೌಲ್ಯ = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (unsigned) immediate_ಮೌಲ್ಯ);
            }
            operands |= immediate_ಮೌಲ್ಯ;
            operands |= half_immediate_rotation << 8;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            expect("(second source operand) register or immediate value");
        }

        ಯದಿ (nb_shift) {
            ಯದಿ (operands & ENCODE_IMMEDIATE_FLAG)
                tcc_error("immediate rotation not implemented");
            ಅನ್ಯಥಾ
                operands |= asm_encode_shift(&shift);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_SET_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_shift_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand ops[3];
    ಪೂರ್ಣಾಙ್ಕ nb_ops;
    ಪೂರ್ಣಾಙ್ಕ definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    ಪ್ರತಿ (nb_ops = 0; nb_ops < ಪರಿಮಾಣ(ops)/ಪರಿಮಾಣ(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        ಯದಿ (tok != ',') {
            ++nb_ops;
            ಭಙ್ಗ;
        }
        next(); // skip ','
    }
    ಯದಿ (nb_ops < 2) {
        expect("at least two operands");
    }

    ಯದಿ (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } ಅನ್ಯಥಾ
        operands |= ENCODE_RD(ops[0].reg);

    ಯದಿ (nb_ops == 2) {
        ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
        ಪಕ್ಷ TOK_ASM_rrxseq:
            opcode |= ENCODE_SET_CONDITION_CODES;
            /* fallthrough */
        ಪಕ್ಷ TOK_ASM_rrxeq:
            ಯದಿ (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
                asm_emit_opcode(token, opcode | operands);
            } ಅನ್ಯಥಾ
                tcc_error("(first source operand) register");
            ಪ್ರತ್ಯಾಗಮ;
        ಸ್ವಭಾವ:
            memcpy(&ops[2], &ops[1], ಪರಿಮಾಣ(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], ಪರಿಮಾಣ(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    ಯದಿ (nb_ops != 3) {
        expect("two or three operands");
    }

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_lslseq:
    ಪಕ್ಷ TOK_ASM_lsrseq:
    ಪಕ್ಷ TOK_ASM_asrseq:
    ಪಕ್ಷ TOK_ASM_rorseq:
        opcode |= ENCODE_SET_CONDITION_CODES;
        ಭಙ್ಗ;
    }

    ವಿಕಲ್ಪ (ops[1].type) {
    ಪಕ್ಷ OP_REG32:
        operands |= ops[1].reg;
        ಭಙ್ಗ;
    ಪಕ್ಷ OP_IM8:
        operands |= ENCODE_IMMEDIATE_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, ರಿಕ್ತ));
    }

    ವಿಕಲ್ಪ (ops[2].type) {
    ಪಕ್ಷ OP_REG32:
        ಯದಿ ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_shift(&ops[2]);
        ಭಙ್ಗ;
    ಪಕ್ಷ OP_IM8:
        ಯದಿ (ops[2].e.v)
            operands |= asm_encode_shift(&ops[2]);
        ಅನ್ಯಥಾ
            definitely_neutral = 1;
        ಭಙ್ಗ;
    }

    ಯದಿ (!definitely_neutral) ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_lslseq:
    ಪಕ್ಷ TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSL;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_lsrseq:
    ಪಕ್ಷ TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSR;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_asrseq:
    ಪಕ್ಷ TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ASR;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_rorseq:
    ಪಕ್ಷ TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_multiplication_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand ops[4];
    ಪೂರ್ಣಾಙ್ಕ nb_ops = 0;
    uint32_t opcode = 0x90;

    ಪ್ರತಿ (nb_ops = 0; nb_ops < ಪರಿಮಾಣ(ops)/ಪರಿಮಾಣ(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        ಯದಿ (tok != ',') {
            ++nb_ops;
            ಭಙ್ಗ;
        }
        next(); // skip ','
    }
    ಯದಿ (nb_ops < 2)
        expect("at least two operands");
    ಅನ್ಯಥಾ ಯದಿ (nb_ops == 2) {
        ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
        ಪಕ್ಷ TOK_ASM_mulseq:
        ಪಕ್ಷ TOK_ASM_muleq:
            memcpy(&ops[2], &ops[0], ಪರಿಮಾಣ(ops[1])); // ARM is actually like this!
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
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

    ಯದಿ (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    ಅನ್ಯಥಾ
        expect("(destination operand) register");
    ಯದಿ (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    ಅನ್ಯಥಾ
        expect("(first source operand) register");
    ಯದಿ (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    ಅನ್ಯಥಾ
        expect("(second source operand) register");
    ಯದಿ (nb_ops > 3) {
        ಯದಿ (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        ಅನ್ಯಥಾ
            expect("(third source operand) register");
    }

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_mulseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_muleq:
        ಯದಿ (nb_ops != 3)
            expect("three operands");
        ಅನ್ಯಥಾ {
            asm_emit_opcode(token, opcode);
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_mlaseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        ಯದಿ (nb_ops != 4)
            expect("four operands");
        ಅನ್ಯಥಾ {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_mlseq:
        opcode |= 0x00400000;
        ಗಚ್ಛ case_TOK_ASM_mlaeq;
    ಪಕ್ಷ TOK_ASM_udiveq:
        opcode |= 0x00200000;
    ಪಕ್ಷ TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("known multiplication instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_long_multiplication_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand ops[4];
    ಪೂರ್ಣಾಙ್ಕ nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    ಪ್ರತಿ (nb_ops = 0; nb_ops < ಪರಿಮಾಣ(ops)/ಪರಿಮಾಣ(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        ಯದಿ (tok != ',') {
            ++nb_ops;
            ಭಙ್ಗ;
        }
        next(); // skip ','
    }
    ಯದಿ (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    ಯದಿ (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    ಅನ್ಯಥಾ
        expect("(destination lo accumulator) register");
    ಯದಿ (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    ಅನ್ಯಥಾ
        expect("(destination hi accumulator) register");
    ಯದಿ (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    ಅನ್ಯಥಾ
        expect("(first source operand) register");
    ಯದಿ (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    ಅನ್ಯಥಾ
        expect("(second source operand) register");

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_smullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_umullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_smlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_umlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("known long multiplication instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_single_data_transfer_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand ops[3];
    Operand strex_operand;
    Operand shift;
    ಪೂರ್ಣಾಙ್ಕ nb_shift = 0;
    ಪೂರ್ಣಾಙ್ಕ exclam = 0;
    ಪೂರ್ಣಾಙ್ಕ closed_bracket = 0;
    ಪೂರ್ಣಾಙ್ಕ op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    ಯದಿ (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    ಅನ್ಯಥಾ {
        expect("(destination operand) register");
    }
    ಯದಿ (tok != ',')
        expect("at least two arguments");
    next(); // skip ','

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_strexheq:
    ಪಕ್ಷ TOK_ASM_strexbeq:
    ಪಕ್ಷ TOK_ASM_strexeq:
        parse_operand(s1, &strex_operand);
        ಯದಿ (strex_operand.type != OP_REG32) {
            expect("register");
        }
        ಯದಿ (tok != ',')
            expect("at least three arguments");
        ಅನ್ಯಥಾ
            next(); // skip ','
        ಭಙ್ಗ;
    }

    skip('[');
    parse_operand(s1, &ops[1]);
    ಯದಿ (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    ಅನ್ಯಥಾ {
        expect("(first source operand) register");
    }
    ಯದಿ (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ಯದಿ (tok == ',') {
        next(); // skip ','
        ಯದಿ (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        ಯದಿ (ops[2].type == OP_REG32) {
            ಯದಿ (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ರಿಕ್ತ));
            }
            ಯದಿ (tok == ',') {
                next();
                opcode |= asm_parse_optional_shift(s1, &nb_shift, &shift);
                ಯದಿ (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } ಅನ್ಯಥಾ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    ಯದಿ (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        ಯದಿ (tok == '!') {
            exclam = 1;
            next(); // skip '!'
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
    ಯದಿ (exclam)
        opcode |= 1 << 21; // write offset back into register

    ಯದಿ (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        ಪೂರ್ಣಾಙ್ಕ v = ops[2].e.v;
        ಯದಿ (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ಯದಿ (v >= 0) {
            opcode |= 1 << 23; // up
            ಯದಿ (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ರಿಕ್ತ));
            ಅನ್ಯಥಾ
                opcode |= v;
        } ಅನ್ಯಥಾ { // down
            ಯದಿ (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ರಿಕ್ತ));
            ಅನ್ಯಥಾ
                opcode |= -v;
        }
    } ಅನ್ಯಥಾ ಯದಿ (ops[2].type == OP_REG32) {
        ಯದಿ (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } ಅನ್ಯಥಾ
        expect("register");

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        ಯದಿ (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        ಯದಿ (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_strexheq:
        opcode |= 1 << 21;
    ಪಕ್ಷ TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_strexeq:
        ಯದಿ ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } ಅನ್ಯಥಾ ಯದಿ (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        ಯದಿ ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_operand.reg;
        asm_emit_opcode(token, opcode);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    ಪಕ್ಷ TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_ldrexeq:
        ಯದಿ ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } ಅನ್ಯಥಾ ಯದಿ (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        ಯದಿ ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_coprocessor_data_transfer(uint32_t ಮೇಲಿನ_nibble, uint8_t cp_ಸಂಖ್ಯೆ, uint8_t CRd, ಧ್ರುವ Operand* Rn, ಧ್ರುವ Operand* offset, ಪೂರ್ಣಾಙ್ಕ offset_minus, ಪೂರ್ಣಾಙ್ಕ preincrement, ಪೂರ್ಣಾಙ್ಕ writeback, ಪೂರ್ಣಾಙ್ಕ long_transfer, ಪೂರ್ಣಾಙ್ಕ load) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    ಯದಿ (long_transfer)
        opcode |= 1 << 22; // long transfer

    ಯದಿ (load)
        opcode |= 1 << 20; // L

    opcode |= cp_ಸಂಖ್ಯೆ << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    ಯದಿ (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    ಯದಿ (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    ಯದಿ (writeback)
        opcode |= 1 << 21; // write offset back into register

    ಯದಿ (offset->type == OP_IM8 || offset->type == OP_IM8N || offset->type == OP_IM32) {
        ಪೂರ್ಣಾಙ್ಕ v = offset->e.v;
        ಯದಿ (offset_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ಯದಿ (offset->type == OP_IM8N || v < 0)
            v = -v;
        ಅನ್ಯಥಾ
            opcode |= 1 << 23; // up
        ಯದಿ (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        ಯದಿ (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } ಅನ್ಯಥಾ ಯದಿ (offset->type == OP_REG32) {
        ಯದಿ (!offset_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= offset->reg;
        tcc_error("Using register offset to register address is not possible here");
    } ಅನ್ಯಥಾ ಯದಿ (offset->type == OP_VREG64) {
        opcode |= 16;
        opcode |= offset->reg;
    } ಅನ್ಯಥಾ
        expect("immediate or register");

    asm_emit_unconditional_opcode((ಮೇಲಿನ_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
ಸ್ಥಿರ ಶೂನ್ಯ asm_coprocessor_data_transfer_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_register;
    ಪೂರ್ಣಾಙ್ಕ preincrement = 0;
    ಪೂರ್ಣಾಙ್ಕ exclam = 0;
    ಪೂರ್ಣಾಙ್ಕ closed_bracket = 0;
    ಪೂರ್ಣಾಙ್ಕ op2_minus = 0;
    ಪೂರ್ಣಾಙ್ಕ long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    ಯದಿ (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } ಅನ್ಯಥಾ {
        expect("'c<number>'");
    }

    skip(',');

    ಯದಿ (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_register = tok - TOK_ASM_c0;
        next();
    } ಅನ್ಯಥಾ {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    ಯದಿ (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    ಯದಿ (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ಯದಿ (tok == ',') {
        next(); // skip ','
        ಯದಿ (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        ಯದಿ (ops[2].type == OP_REG32) {
            ಯದಿ (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ರಿಕ್ತ));
            }
        } ಅನ್ಯಥಾ ಯದಿ (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, ರಿಕ್ತ));
        }
    } ಅನ್ಯಥಾ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    ಯದಿ (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        ಯದಿ (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    // TODO: Support options.

    ಯದಿ (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        ವಿಕಲ್ಪ (token) {
        ಪಕ್ಷ TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        ಪಕ್ಷ TOK_ASM_ldc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        ಪಕ್ಷ TOK_ASM_stc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            ಭಙ್ಗ;
        }
    } ಅನ್ಯಥಾ ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_stceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_ldceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("coprocessor data transfer instruction");
    }
}

#ಯದಿ defined(TCC_ARM_VFP)
#define CP_SINGLE_PRECISION_FLOAT 10
#define CP_DOUBLE_PRECISION_FLOAT 11

ಸ್ಥಿರ ಶೂನ್ಯ asm_floating_point_single_data_transfer_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_register = 0;
    ಪೂರ್ಣಾಙ್ಕ long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    ಯದಿ (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        long_transfer = coprocessor_destination_register & 1;
        coprocessor_destination_register >>= 1;
    } ಅನ್ಯಥಾ ಯದಿ (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        next();
    } ಅನ್ಯಥಾ {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    ಯದಿ (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    ಯದಿ (tok == ',') {
        next(); // skip ','
        parse_operand(s1, &ops[2]);
        ಯದಿ (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } ಅನ್ಯಥಾ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_vldreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vstreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("floating point data transfer instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_floating_point_block_data_transfer_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    uint8_t coprocessor = 0;
    ಪೂರ್ಣಾಙ್ಕ first_regset_register;
    ಪೂರ್ಣಾಙ್ಕ last_regset_register;
    uint8_t regset_item_ಎಣಿಕೆ;
    uint8_t extra_register_bit = 0;
    ಪೂರ್ಣಾಙ್ಕ op0_exclam = 0;
    ಪೂರ್ಣಾಙ್ಕ load = 0;
    ಪೂರ್ಣಾಙ್ಕ preincrement = 0;
    Operand ops[1];
    Operand offset;
    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_vpusheq:
    ಪಕ್ಷ TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        parse_operand(s1, &ops[0]);
        ಯದಿ (tok == '!') {
            op0_exclam = 1;
            next(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    first_regset_register = asm_parse_vfp_regvar(tok, 1);
    ಯದಿ ((first_regset_register = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        next();
    } ಅನ್ಯಥಾ ಯದಿ ((first_regset_register = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        next();
    } ಅನ್ಯಥಾ {
        expect("floating-point register");
    }

    ಯದಿ (tok == '-') {
        next();
        ಯದಿ ((last_regset_register = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            next();
        ಅನ್ಯಥಾ {
            expect("floating-point register");
        }
    } ಅನ್ಯಥಾ
        last_regset_register = first_regset_register;

    ಯದಿ (last_regset_register < first_regset_register) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_item_ಎಣಿಕೆ = last_regset_register - first_regset_register + 1;
    ಯದಿ (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_item_ಎಣಿಕೆ <<= 1;
    ಅನ್ಯಥಾ {
        extra_register_bit = first_regset_register & 1;
        first_regset_register >>= 1;
    }
    offset.type = OP_IM8;
    offset.e.v = regset_item_ಎಣಿಕೆ << 2;
    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_vstmeq: // post-increment store
    ಪಕ್ಷ TOK_ASM_vstmiaeq: // post-increment store
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vpopeq:
    ಪಕ್ಷ TOK_ASM_vldmeq: // post-increment load
    ಪಕ್ಷ TOK_ASM_vldmiaeq: // post-increment load
        load = 1;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vldmdbeq: // pre-decrement load
        load = 1;
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_vpusheq:
    ಪಕ್ಷ TOK_ASM_vstmdbeq: // pre-decrement store
        offset.type = OP_IM8N;
        offset.e.v = -offset.e.v;
        preincrement = 1;
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("floating point block data transfer instruction");
    }
    ಯದಿ (ops[0].type != OP_REG32)
        expect("(first operand) register");
    ಅನ್ಯಥಾ ಯದಿ (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ರಿಕ್ತ));
    ಅನ್ಯಥಾ ಯದಿ (!op0_exclam && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, ರಿಕ್ತ));
    ಅನ್ಯಥಾ
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, first_regset_register, &ops[0], &offset, 0, preincrement, op0_exclam, extra_register_bit, load);
}

#define VMOV_FRACTIONAL_DIGITS 7
#define VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

ಸ್ಥಿರ uint32_t vmov_parse_fractional_part(ಧ್ರುವ ವರ್ಣ* s)
{
    uint32_t result = 0;
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        ವರ್ಣ c = *s;
        result *= 10;
        ಯದಿ (c >= '0' && c <= '9') {
            result += (c - '0');
            ++s;
        }
    }
    ಯದಿ (*s)
        expect("decimal numeral");
    ಪ್ರತ್ಯಾಗಮ result;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ vmov_linear_approx_index(uint32_t beginning, uint32_t end, uint32_t ಮೌಲ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    uint32_t k;
    uint32_t xvalue;

    k = (end - beginning)/16;
    ಪ್ರತಿ (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        ಯದಿ (ಮೌಲ್ಯ == xvalue)
            ಪ್ರತ್ಯಾಗಮ i;
    }
    //assert(0);
    ಪ್ರತ್ಯಾಗಮ -1;
}

ಸ್ಥಿರ uint32_t vmov_parse_immediate_ಮೌಲ್ಯ() {
    uint32_t ಮೌಲ್ಯ;
    unsigned long integral_ಮೌಲ್ಯ;
    ಧ್ರುವ ವರ್ಣ *p;

    ಯದಿ (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.data;
    errno = 0;
    integral_ಮೌಲ್ಯ = strtoul(p, (ವರ್ಣ **)&p, 0);

    ಯದಿ (errno || integral_ಮೌಲ್ಯ >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    ಮೌಲ್ಯ = (uint32_t) integral_ಮೌಲ್ಯ * VMOV_ONE;
    ಯದಿ (*p == '.') {
        ++p;
        ಮೌಲ್ಯ += vmov_parse_fractional_part(p);
    }
    next();
    ಪ್ರತ್ಯಾಗಮ ಮೌಲ್ಯ;
}

ಸ್ಥಿರ uint8_t vmov_encode_immediate_ಮೌಲ್ಯ(uint32_t ಮೌಲ್ಯ)
{
    uint32_t limit;
    uint32_t end = 0;
    uint32_t beginning = 0;
    ಪೂರ್ಣಾಙ್ಕ r = -1;
    ಪೂರ್ಣಾಙ್ಕ n;
    ಪೂರ್ಣಾಙ್ಕ i;

    limit = 32 * VMOV_ONE;
    ಪ್ರತಿ (i = 0; i < 8; ++i) {
        ಯದಿ (ಮೌಲ್ಯ < limit) {
            end = limit;
            limit >>= 1;
            beginning = limit;
            r = i;
        } ಅನ್ಯಥಾ
            limit >>= 1;
    }
    ಯದಿ (r == -1 || ಮೌಲ್ಯ < beginning || ಮೌಲ್ಯ > end) {
        tcc_error("invalid decimal number for vmov: %d", ಮೌಲ್ಯ);
    }
    n = vmov_linear_approx_index(beginning, end, ಮೌಲ್ಯ);
    ಪ್ರತ್ಯಾಗಮ n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
ಸ್ಥಿರ ಶೂನ್ಯ asm_floating_point_immediate_data_processing_opcode_tail(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t immediate_ಮೌಲ್ಯ = 0;
    ಪೂರ್ಣಾಙ್ಕ op_minus = 0;
    uint8_t code;

    operands[0] = CRd;

    ಯದಿ (tok == '#' || tok == '$') {
        next();
    }
    ಯದಿ (tok == '-') {
        op_minus = 1;
        next();
    }
    immediate_ಮೌಲ್ಯ = vmov_parse_immediate_ಮೌಲ್ಯ();

    opcode1 = 11; // "Other" instruction
    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_vcmpeq_f32:
    ಪಕ್ಷ TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        ಯದಿ (immediate_ಮೌಲ್ಯ) {
            expect("Immediate value 0");
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vcmpeeq_f32:
    ಪಕ್ಷ TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        ಯದಿ (immediate_ಮೌಲ್ಯ) {
            expect("Immediate value 0");
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vmoveq_f32:
    ಪಕ್ಷ TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        ಯದಿ (op_minus)
            operands[1] = 0x8;
        ಅನ್ಯಥಾ
            operands[1] = 0x0;
        code = vmov_encode_immediate_ಮೌಲ್ಯ(immediate_ಮೌಲ್ಯ);
        operands[1] |= code >> 4;
        operands[2] = code & 0xF;
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("known floating point with immediate instruction");
    }

    ಯದಿ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        ಯದಿ (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_floating_point_reg_arm_reg_transfer_opcode_tail(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token, ಪೂರ್ಣಾಙ್ಕ coprocessor, ಪೂರ್ಣಾಙ್ಕ nb_arm_regs, ಪೂರ್ಣಾಙ್ಕ nb_ops, Operand ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    ವಿಕಲ್ಪ (coprocessor) {
    ಪಕ್ಷ CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        ಯದಿ (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        ಯದಿ (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            memcpy(&ops[2], &ops[1], ಪರಿಮಾಣ(ops[2]));
            memcpy(&ops[1], &ops[0], ಪರಿಮಾಣ(ops[1]));
            memcpy(&ops[0], &ops[2], ಪರಿಮಾಣ(ops[0]));
        } ಅನ್ಯಥಾ
            opcode1 |= 1;

        ಯದಿ (ops[1].type == OP_VREG32) {
            ಯದಿ (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        ಯದಿ (ops[0].type == OP_VREG32) {
            ಯದಿ (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ CP_DOUBLE_PRECISION_FLOAT:
        ಯದಿ (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        ಯದಿ (ops[0].type == OP_VREG64) {
            ಯದಿ (ops[2].type == OP_REG32) {
                Operand temp;
                // need to rotate operand list to the left
                memcpy(&temp, &ops[0], ಪರಿಮಾಣ(temp));
                memcpy(&ops[0], &ops[1], ಪರಿಮಾಣ(ops[0]));
                memcpy(&ops[1], &ops[2], ಪರಿಮಾಣ(ops[1]));
                memcpy(&ops[2], &temp, ಪರಿಮಾಣ(ops[2]));
            } ಅನ್ಯಥಾ {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } ಅನ್ಯಥಾ ಯದಿ (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } ಅನ್ಯಥಾ {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        tcc_internal_error("unknown coprocessor");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_floating_point_vcvt_data_processing_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token) {
    uint8_t coprocessor = 0;
    Operand ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_vcvtreq_s32_f64:
    ಪಕ್ಷ TOK_ASM_vcvtreq_u32_f64:
    ಪಕ್ಷ TOK_ASM_vcvteq_s32_f64:
    ಪಕ್ಷ TOK_ASM_vcvteq_u32_f64:
    ಪಕ್ಷ TOK_ASM_vcvteq_f64_s32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f64_u32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vcvtreq_s32_f32:
    ಪಕ್ಷ TOK_ASM_vcvtreq_u32_f32:
    ಪಕ್ಷ TOK_ASM_vcvteq_s32_f32:
    ಪಕ್ಷ TOK_ASM_vcvteq_u32_f32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f32_s32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f32_u32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       ಭಙ್ಗ;
    ಸ್ವಭಾವ:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, ರಿಕ್ತ));
    }

    parse_operand(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_vcvtreq_s32_f32:
    ಪಕ್ಷ TOK_ASM_vcvtreq_s32_f64:
    ಪಕ್ಷ TOK_ASM_vcvteq_s32_f32:
    ಪಕ್ಷ TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    ಪಕ್ಷ TOK_ASM_vcvteq_u32_f32:
    ಪಕ್ಷ TOK_ASM_vcvteq_u32_f64:
    ಪಕ್ಷ TOK_ASM_vcvtreq_u32_f32:
    ಪಕ್ಷ TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        ಭಙ್ಗ;
    /* floating-point size conversion */
    ಪಕ್ಷ TOK_ASM_vcvteq_f64_f32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        ಭಙ್ಗ;
    }

    skip(',');
    parse_operand(s1, &ops[2]);

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    /* floating-point -> integer */
    ಪಕ್ಷ TOK_ASM_vcvteq_s32_f32:
    ಪಕ್ಷ TOK_ASM_vcvteq_s32_f64:
    ಪಕ್ಷ TOK_ASM_vcvteq_u32_f32:
    ಪಕ್ಷ TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        ಭಙ್ಗ;

    /* integer -> floating-point */
    ಪಕ್ಷ TOK_ASM_vcvteq_f64_s32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        ಭಙ್ಗ;

    /* floating-point size conversion */
    ಪಕ್ಷ TOK_ASM_vcvteq_f64_f32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        ಭಙ್ಗ;
    }

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_vcvteq_f64_u32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f64_s32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f64_f32:
        ಯದಿ (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } ಅನ್ಯಥಾ {
            expect("d<number>, s<number>");
        }
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        ಯದಿ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            ಯದಿ (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } ಅನ್ಯಥಾ {
                expect("s<number>, s<number>");
            }
        } ಅನ್ಯಥಾ ಯದಿ (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            ಯದಿ (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } ಅನ್ಯಥಾ {
                expect("s<number>, d<number>");
            }
        }
    }

    ಯದಿ (ops[2].type == OP_VREG32) {
        ಯದಿ (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    ಯದಿ (ops[0].type == OP_VREG32) {
        ಯದಿ (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_floating_point_data_processing_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    Operand ops[3];
    uint8_t nb_ops = 0;
    ಪೂರ್ಣಾಙ್ಕ vmov = 0;
    ಪೂರ್ಣಾಙ್ಕ nb_arm_regs = 0;

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

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_vmlaeq_f64:
    ಪಕ್ಷ TOK_ASM_vmlseq_f64:
    ಪಕ್ಷ TOK_ASM_vnmlseq_f64:
    ಪಕ್ಷ TOK_ASM_vnmlaeq_f64:
    ಪಕ್ಷ TOK_ASM_vmuleq_f64:
    ಪಕ್ಷ TOK_ASM_vnmuleq_f64:
    ಪಕ್ಷ TOK_ASM_vaddeq_f64:
    ಪಕ್ಷ TOK_ASM_vsubeq_f64:
    ಪಕ್ಷ TOK_ASM_vdiveq_f64:
    ಪಕ್ಷ TOK_ASM_vnegeq_f64:
    ಪಕ್ಷ TOK_ASM_vabseq_f64:
    ಪಕ್ಷ TOK_ASM_vsqrteq_f64:
    ಪಕ್ಷ TOK_ASM_vcmpeq_f64:
    ಪಕ್ಷ TOK_ASM_vcmpeeq_f64:
    ಪಕ್ಷ TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_vmoveq_f32:
    ಪಕ್ಷ TOK_ASM_vmoveq_f64:
        vmov = 1;
        ಭಙ್ಗ;
    }

    ಪ್ರತಿ (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        ಯದಿ (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_point_immediate_data_processing_opcode_tail(s1, token, coprocessor, ops[0].reg);
            ಪ್ರತ್ಯಾಗಮ;
        }
        parse_operand(s1, &ops[nb_ops]);
        ಯದಿ (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } ಅನ್ಯಥಾ ಯದಿ (ops[nb_ops].type == OP_VREG32) {
            ಯದಿ (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } ಅನ್ಯಥಾ ಯದಿ (ops[nb_ops].type == OP_VREG64) {
            ಯದಿ (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } ಅನ್ಯಥಾ {
            expect("floating point register");
        }
        ++nb_ops;
        ಯದಿ (tok == ',')
            next();
        ಅನ್ಯಥಾ
            ಭಙ್ಗ;
    }

    ಯದಿ (nb_arm_regs == 0) {
        ಯದಿ (nb_ops == 2) { // implicit
            memcpy(&ops[2], &ops[1], ಪರಿಮಾಣ(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], ಪರಿಮಾಣ(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        ಯದಿ (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, ರಿಕ್ತ), nb_ops);
        }
    }

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_vmlaeq_f32:
    ಪಕ್ಷ TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vmlseq_f32:
    ಪಕ್ಷ TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vnmlseq_f32:
    ಪಕ್ಷ TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vnmlaeq_f32:
    ಪಕ್ಷ TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vmuleq_f32:
    ಪಕ್ಷ TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vnmuleq_f32:
    ಪಕ್ಷ TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vaddeq_f32:
    ಪಕ್ಷ TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vsubeq_f32:
    ಪಕ್ಷ TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vdiveq_f32:
    ಪಕ್ಷ TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vnegeq_f32:
    ಪಕ್ಷ TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vabseq_f32:
    ಪಕ್ಷ TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vsqrteq_f32:
    ಪಕ್ಷ TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vcmpeq_f32:
    ಪಕ್ಷ TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vcmpeeq_f32:
    ಪಕ್ಷ TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vmoveq_f32:
    ಪಕ್ಷ TOK_ASM_vmoveq_f64:
        ಯದಿ (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_point_reg_arm_reg_transfer_opcode_tail(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            ಪ್ರತ್ಯಾಗಮ;
        } ಅನ್ಯಥಾ {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("known floating point instruction");
    }

    ಯದಿ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        ಯದಿ (ops[2].type == OP_VREG32) {
            ಯದಿ (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        ಯದಿ (ops[1].type == OP_VREG32) {
            ಯದಿ (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        ಯದಿ (ops[0].type == OP_VREG32) {
            ಯದಿ (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ asm_parse_vfp_status_regvar(ಪೂರ್ಣಾಙ್ಕ t)
{
    ವಿಕಲ್ಪ (t) {
    ಪಕ್ಷ TOK_ASM_fpsid:
        ಪ್ರತ್ಯಾಗಮ 0;
    ಪಕ್ಷ TOK_ASM_fpscr:
        ಪ್ರತ್ಯಾಗಮ 1;
    ಪಕ್ಷ TOK_ASM_fpexc:
        ಪ್ರತ್ಯಾಗಮ 8;
    ಸ್ವಭಾವ:
        ಪ್ರತ್ಯಾಗಮ -1;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_floating_point_status_register_opcode(TCCState* s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    ಪೂರ್ಣಾಙ್ಕ vfp_sys_reg = -1;
    Operand arm_operand;
    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_vmrseq:
        opcode = 0xf;
        ಯದಿ (tok == TOK_ASM_apsr_nzcv) {
            arm_operand.type = OP_REG32;
            arm_operand.reg = 15; // not PC
            next(); // skip apsr_nzcv
        } ಅನ್ಯಥಾ {
            parse_operand(s1, &arm_operand);
            ಯದಿ (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ರಿಕ್ತ));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        ಯದಿ (arm_operand.type == OP_REG32 && arm_operand.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, ರಿಕ್ತ));
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        skip(',');
        parse_operand(s1, &arm_operand);
        ಯದಿ (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ರಿಕ್ತ));
        }
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("floating point status register instruction");
    }
    ಯದಿ (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    ಯದಿ (arm_operand.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode, arm_operand.reg, vfp_sys_reg, 0x10, 0, 0);
}

#endif

ಸ್ಥಿರ ಶೂನ್ಯ asm_misc_single_data_transfer_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand ops[3];
    ಪೂರ್ಣಾಙ್ಕ exclam = 0;
    ಪೂರ್ಣಾಙ್ಕ closed_bracket = 0;
    ಪೂರ್ಣಾಙ್ಕ op2_minus = 0;
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

    parse_operand(s1, &ops[0]);
    ಯದಿ (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    ಅನ್ಯಥಾ {
        expect("(destination operand) register");
    }
    ಯದಿ (tok != ',')
        expect("at least two arguments");
    ಅನ್ಯಥಾ
        next(); // skip ','
    skip('[');
    parse_operand(s1, &ops[1]);
    ಯದಿ (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    ಅನ್ಯಥಾ {
        expect("(first source operand) register");
    }
    ಯದಿ (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ಯದಿ (tok == ',') {
        next(); // skip ','
        ಯದಿ (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
    } ಅನ್ಯಥಾ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    ಯದಿ (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        ಯದಿ (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    ಯದಿ (exclam) {
        ಯದಿ ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, ರಿಕ್ತ));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    ಯದಿ (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        ಪೂರ್ಣಾಙ್ಕ v = ops[2].e.v;
        ಯದಿ (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ಯದಿ (v >= 0) {
            opcode |= 1 << 23; // up
            ಯದಿ (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ರಿಕ್ತ));
            ಅನ್ಯಥಾ {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } ಅನ್ಯಥಾ { // down
            ಯದಿ (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ರಿಕ್ತ));
            ಅನ್ಯಥಾ {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } ಅನ್ಯಥಾ ಯದಿ (ops[2].type == OP_REG32) {
        ಯದಿ (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ops[2].reg;
    } ಅನ್ಯಥಾ
        expect("register");

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    ಪಕ್ಷ TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        ಭಙ್ಗ;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
ಸ್ಥಿರ uint32_t encbranchoffset(ಪೂರ್ಣಾಙ್ಕ pos, ಪೂರ್ಣಾಙ್ಕ addr, ಪೂರ್ಣಾಙ್ಕ fail)
{
  addr-=pos+8;
  addr/=4;
  ಯದಿ(addr>=0x7fffff || addr<-0x800000) {
    ಯದಿ(fail)
      tcc_error("branch offset is too far");
    ಪ್ರತ್ಯಾಗಮ 0;
  }
  ಪ್ರತ್ಯಾಗಮ /*not 0x0A000000|*/(addr&0xffffff);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_branch_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    ಪೂರ್ಣಾಙ್ಕ jmp_disp = 0;
    Operand op;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
    ElfSym *esym;

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_beq:
    ಪಕ್ಷ TOK_ASM_bleq:
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
        ಯದಿ (e.sym) {
            esym = elfsym(e.sym);
            ಯದಿ (esym && esym->st_shndx == cur_text_section->sh_ಅಂಕೆ) {
                jmp_disp = esym->st_ಮೌಲ್ಯ;
            } ಅನ್ಯಥಾ {
                greloca(cur_text_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        parse_operand(s1, &op);
        ಭಙ್ಗ;
    }
    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_bxeq:
        ಯದಿ (op.type != OP_REG32)
            expect("register");
        ಅನ್ಯಥಾ
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_blxeq:
        ಯದಿ (op.type != OP_REG32)
            expect("register");
        ಅನ್ಯಥಾ
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("branch instruction");
    }
}

ST_FUNC ಶೂನ್ಯ asm_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    ಯಾವತ್ (token == TOK_LINEFEED) {
        next();
        token = tok;
    }
    ಯದಿ (token == TOK_EOF)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (token < TOK_ASM_nopeq) { // no condition code
        ವಿಕಲ್ಪ (token) {
        ಪಕ್ಷ TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            ಪ್ರತ್ಯಾಗಮ;
        ಪಕ್ಷ TOK_ASM_ldc2:
        ಪಕ್ಷ TOK_ASM_ldc2l:
        ಪಕ್ಷ TOK_ASM_stc2:
        ಪಕ್ಷ TOK_ASM_stc2l:
            asm_coprocessor_data_transfer_opcode(s1, token);
            ಪ್ರತ್ಯಾಗಮ;
        ಸ್ವಭಾವ:
            expect("instruction");
        }
    }

    ವಿಕಲ್ಪ (ARM_INSTRUCTION_GROUP(token)) {
    ಪಕ್ಷ TOK_ASM_pusheq:
    ಪಕ್ಷ TOK_ASM_popeq:
    ಪಕ್ಷ TOK_ASM_stmdaeq:
    ಪಕ್ಷ TOK_ASM_ldmdaeq:
    ಪಕ್ಷ TOK_ASM_stmeq:
    ಪಕ್ಷ TOK_ASM_ldmeq:
    ಪಕ್ಷ TOK_ASM_stmiaeq:
    ಪಕ್ಷ TOK_ASM_ldmiaeq:
    ಪಕ್ಷ TOK_ASM_stmdbeq:
    ಪಕ್ಷ TOK_ASM_ldmdbeq:
    ಪಕ್ಷ TOK_ASM_stmibeq:
    ಪಕ್ಷ TOK_ASM_ldmibeq:
        asm_block_data_transfer_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_nopeq:
    ಪಕ್ಷ TOK_ASM_wfeeq:
    ಪಕ್ಷ TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_swieq:
    ಪಕ್ಷ TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_beq:
    ಪಕ್ಷ TOK_ASM_bleq:
    ಪಕ್ಷ TOK_ASM_bxeq:
    ಪಕ್ಷ TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_clzeq:
    ಪಕ್ಷ TOK_ASM_sxtbeq:
    ಪಕ್ಷ TOK_ASM_sxtheq:
    ಪಕ್ಷ TOK_ASM_uxtbeq:
    ಪಕ್ಷ TOK_ASM_uxtheq:
    ಪಕ್ಷ TOK_ASM_movteq:
    ಪಕ್ಷ TOK_ASM_movweq:
        asm_ದ್ವಿಮಾನ_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_ldreq:
    ಪಕ್ಷ TOK_ASM_ldrbeq:
    ಪಕ್ಷ TOK_ASM_streq:
    ಪಕ್ಷ TOK_ASM_strbeq:
    ಪಕ್ಷ TOK_ASM_ldrexeq:
    ಪಕ್ಷ TOK_ASM_ldrexbeq:
    ಪಕ್ಷ TOK_ASM_ldrexheq:
    ಪಕ್ಷ TOK_ASM_strexeq:
    ಪಕ್ಷ TOK_ASM_strexbeq:
    ಪಕ್ಷ TOK_ASM_strexheq:
        asm_single_data_transfer_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_ldrheq:
    ಪಕ್ಷ TOK_ASM_ldrsheq:
    ಪಕ್ಷ TOK_ASM_ldrsbeq:
    ಪಕ್ಷ TOK_ASM_strheq:
       asm_misc_single_data_transfer_opcode(s1, token);
       ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_andeq:
    ಪಕ್ಷ TOK_ASM_eoreq:
    ಪಕ್ಷ TOK_ASM_subeq:
    ಪಕ್ಷ TOK_ASM_rsbeq:
    ಪಕ್ಷ TOK_ASM_addeq:
    ಪಕ್ಷ TOK_ASM_adceq:
    ಪಕ್ಷ TOK_ASM_sbceq:
    ಪಕ್ಷ TOK_ASM_rsceq:
    ಪಕ್ಷ TOK_ASM_tsteq:
    ಪಕ್ಷ TOK_ASM_teqeq:
    ಪಕ್ಷ TOK_ASM_cmpeq:
    ಪಕ್ಷ TOK_ASM_cmneq:
    ಪಕ್ಷ TOK_ASM_orreq:
    ಪಕ್ಷ TOK_ASM_moveq:
    ಪಕ್ಷ TOK_ASM_biceq:
    ಪಕ್ಷ TOK_ASM_mvneq:
    ಪಕ್ಷ TOK_ASM_andseq:
    ಪಕ್ಷ TOK_ASM_eorseq:
    ಪಕ್ಷ TOK_ASM_subseq:
    ಪಕ್ಷ TOK_ASM_rsbseq:
    ಪಕ್ಷ TOK_ASM_addseq:
    ಪಕ್ಷ TOK_ASM_adcseq:
    ಪಕ್ಷ TOK_ASM_sbcseq:
    ಪಕ್ಷ TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    ಪಕ್ಷ TOK_ASM_orrseq:
    ಪಕ್ಷ TOK_ASM_movseq:
    ಪಕ್ಷ TOK_ASM_bicseq:
    ಪಕ್ಷ TOK_ASM_mvnseq:
        asm_data_processing_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_lsleq:
    ಪಕ್ಷ TOK_ASM_lslseq:
    ಪಕ್ಷ TOK_ASM_lsreq:
    ಪಕ್ಷ TOK_ASM_lsrseq:
    ಪಕ್ಷ TOK_ASM_asreq:
    ಪಕ್ಷ TOK_ASM_asrseq:
    ಪಕ್ಷ TOK_ASM_roreq:
    ಪಕ್ಷ TOK_ASM_rorseq:
    ಪಕ್ಷ TOK_ASM_rrxseq:
    ಪಕ್ಷ TOK_ASM_rrxeq:
        asm_shift_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_muleq:
    ಪಕ್ಷ TOK_ASM_mulseq:
    ಪಕ್ಷ TOK_ASM_mlaeq:
    ಪಕ್ಷ TOK_ASM_mlaseq:
    ಪಕ್ಷ TOK_ASM_mlseq:
    ಪಕ್ಷ TOK_ASM_udiveq:
    ಪಕ್ಷ TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_smulleq:
    ಪಕ್ಷ TOK_ASM_smullseq:
    ಪಕ್ಷ TOK_ASM_umulleq:
    ಪಕ್ಷ TOK_ASM_umullseq:
    ಪಕ್ಷ TOK_ASM_smlaleq:
    ಪಕ್ಷ TOK_ASM_smlalseq:
    ಪಕ್ಷ TOK_ASM_umlaleq:
    ಪಕ್ಷ TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_cdpeq:
    ಪಕ್ಷ TOK_ASM_mcreq:
    ಪಕ್ಷ TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_ldceq:
    ಪಕ್ಷ TOK_ASM_ldcleq:
    ಪಕ್ಷ TOK_ASM_stceq:
    ಪಕ್ಷ TOK_ASM_stcleq:
        asm_coprocessor_data_transfer_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

#ಯದಿ defined(TCC_ARM_VFP)
    ಪಕ್ಷ TOK_ASM_vldreq:
    ಪಕ್ಷ TOK_ASM_vstreq:
        asm_floating_point_single_data_transfer_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_vmlaeq_f32:
    ಪಕ್ಷ TOK_ASM_vmlseq_f32:
    ಪಕ್ಷ TOK_ASM_vnmlseq_f32:
    ಪಕ್ಷ TOK_ASM_vnmlaeq_f32:
    ಪಕ್ಷ TOK_ASM_vmuleq_f32:
    ಪಕ್ಷ TOK_ASM_vnmuleq_f32:
    ಪಕ್ಷ TOK_ASM_vaddeq_f32:
    ಪಕ್ಷ TOK_ASM_vsubeq_f32:
    ಪಕ್ಷ TOK_ASM_vdiveq_f32:
    ಪಕ್ಷ TOK_ASM_vnegeq_f32:
    ಪಕ್ಷ TOK_ASM_vabseq_f32:
    ಪಕ್ಷ TOK_ASM_vsqrteq_f32:
    ಪಕ್ಷ TOK_ASM_vcmpeq_f32:
    ಪಕ್ಷ TOK_ASM_vcmpeeq_f32:
    ಪಕ್ಷ TOK_ASM_vmoveq_f32:
    ಪಕ್ಷ TOK_ASM_vmlaeq_f64:
    ಪಕ್ಷ TOK_ASM_vmlseq_f64:
    ಪಕ್ಷ TOK_ASM_vnmlseq_f64:
    ಪಕ್ಷ TOK_ASM_vnmlaeq_f64:
    ಪಕ್ಷ TOK_ASM_vmuleq_f64:
    ಪಕ್ಷ TOK_ASM_vnmuleq_f64:
    ಪಕ್ಷ TOK_ASM_vaddeq_f64:
    ಪಕ್ಷ TOK_ASM_vsubeq_f64:
    ಪಕ್ಷ TOK_ASM_vdiveq_f64:
    ಪಕ್ಷ TOK_ASM_vnegeq_f64:
    ಪಕ್ಷ TOK_ASM_vabseq_f64:
    ಪಕ್ಷ TOK_ASM_vsqrteq_f64:
    ಪಕ್ಷ TOK_ASM_vcmpeq_f64:
    ಪಕ್ಷ TOK_ASM_vcmpeeq_f64:
    ಪಕ್ಷ TOK_ASM_vmoveq_f64:
        asm_floating_point_data_processing_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_vcvtreq_s32_f32:
    ಪಕ್ಷ TOK_ASM_vcvtreq_s32_f64:
    ಪಕ್ಷ TOK_ASM_vcvteq_s32_f32:
    ಪಕ್ಷ TOK_ASM_vcvteq_s32_f64:
    ಪಕ್ಷ TOK_ASM_vcvtreq_u32_f32:
    ಪಕ್ಷ TOK_ASM_vcvtreq_u32_f64:
    ಪಕ್ಷ TOK_ASM_vcvteq_u32_f32:
    ಪಕ್ಷ TOK_ASM_vcvteq_u32_f64:
    ಪಕ್ಷ TOK_ASM_vcvteq_f64_s32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f32_s32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f64_u32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f32_u32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f64_f32:
    ಪಕ್ಷ TOK_ASM_vcvteq_f32_f64:
        asm_floating_point_vcvt_data_processing_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_vpusheq:
    ಪಕ್ಷ TOK_ASM_vpopeq:
    ಪಕ್ಷ TOK_ASM_vldmeq:
    ಪಕ್ಷ TOK_ASM_vldmiaeq:
    ಪಕ್ಷ TOK_ASM_vldmdbeq:
    ಪಕ್ಷ TOK_ASM_vstmeq:
    ಪಕ್ಷ TOK_ASM_vstmiaeq:
    ಪಕ್ಷ TOK_ASM_vstmdbeq:
        asm_floating_point_block_data_transfer_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_vmsreq:
    ಪಕ್ಷ TOK_ASM_vmrseq:
        asm_floating_point_status_register_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;
#endif

    ಸ್ವಭಾವ:
        expect("known instruction");
    }
}

ST_FUNC ಶೂನ್ಯ subst_asm_operand(CString *add_str, SValue *sv, ಪೂರ್ಣಾಙ್ಕ modifier)
{
    ಪೂರ್ಣಾಙ್ಕ r, reg, size, val;

    r = sv->r;
    ಯದಿ ((r & VT_VALMASK) == VT_CONST) {
        ಯದಿ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        ಯದಿ (r & VT_SYM) {
            ಧ್ರುವ ವರ್ಣ *name = get_tok_str(sv->sym->v, ರಿಕ್ತ);
            ಯದಿ (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            ಯದಿ (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            ಯದಿ ((uint32_t) sv->c.i == 0)
                ಗಚ್ಛ no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        ಯದಿ (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
      no_offset:;
    } ಅನ್ಯಥಾ ಯದಿ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[fp,#%d]", (ಪೂರ್ಣಾಙ್ಕ) sv->c.i);
    } ಅನ್ಯಥಾ ಯದಿ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ಯದಿ (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, ರಿಕ್ತ));
    } ಅನ್ಯಥಾ {
        /* register case */
        reg = r & VT_VALMASK;
        ಯದಿ (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        ಯದಿ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        ಅನ್ಯಥಾ ಯದಿ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        ಅನ್ಯಥಾ
            size = 4;

        ಯದಿ (modifier == 'b') {
            size = 1;
        } ಅನ್ಯಥಾ ಯದಿ (modifier == 'w') {
            size = 2;
        } ಅನ್ಯಥಾ ಯದಿ (modifier == 'k') {
            size = 4;
        }

        ವಿಕಲ್ಪ (size) {
        ಸ್ವಭಾವ:
            reg = TOK_ASM_r0 + reg;
            ಭಙ್ಗ;
        }
        cstr_printf(add_str, "%s", get_tok_str(reg, ರಿಕ್ತ));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC ಶೂನ್ಯ asm_gen_code(ASMOperand *operands, ಪೂರ್ಣಾಙ್ಕ nb_operands,
                          ಪೂರ್ಣಾಙ್ಕ nb_outputs, ಪೂರ್ಣಾಙ್ಕ is_output,
                          uint8_t *clobber_regs,
                          ಪೂರ್ಣಾಙ್ಕ out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ಪೂರ್ಣಾಙ್ಕ i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    ಸ್ಥಿರ ಧ್ರುವ uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, ಪರಿಮಾಣ(regs_allocated));
    ಪ್ರತಿ(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        ಯದಿ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    ಪ್ರತಿ(i = 0; i < ಪರಿಮಾಣ(reg_saved)/ಪರಿಮಾಣ(reg_saved[0]); i++) {
        reg = reg_saved[i];
        ಯದಿ (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    ಯದಿ (!is_output) { // prolog
        /* generate reg save code */
        ಯದಿ (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        ಪ್ರತಿ(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ಯದಿ (op->reg >= 0) {
                ಯದಿ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } ಅನ್ಯಥಾ ಯದಿ (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    load(op->reg, op->vt);
                    ಯದಿ (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } ಅನ್ಯಥಾ { // epilog
        /* generate save code */
        ಪ್ರತಿ(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ಯದಿ (op->reg >= 0) {
                ಯದಿ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ಯದಿ (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } ಅನ್ಯಥಾ {
                    store(op->reg, op->vt);
                    ಯದಿ (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        ಯದಿ (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ constraint_priority(ಧ್ರುವ ವರ್ಣ *str)
{
    ಪೂರ್ಣಾಙ್ಕ priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    ಪ್ರತಿ(;;) {
        c = *str;
        ಯದಿ (c == '\0')
            ಭಙ್ಗ;
        str++;
        ವಿಕಲ್ಪ(c) {
        ಪಕ್ಷ 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        ಪಕ್ಷ 'r': // register [general]
        ಪಕ್ಷ 'p': // valid memory address for load,store [general]
            pr = 3;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'M': // integer constant for shifts [ARM]
        ಪಕ್ಷ 'I': // integer valid for data processing instruction immediate
        ಪಕ್ಷ 'J': // integer in range -4095...4095

        ಪಕ್ಷ 'i': // immediate integer operand, including symbolic constants [general]
        ಪಕ್ಷ 'm': // memory operand [general]
        ಪಕ್ಷ 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("unknown constraint '%c'", c);
        }
        ಯದಿ (pr > priority)
            priority = pr;
    }
    ಪ್ರತ್ಯಾಗಮ priority;
}

ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ *skip_constraint_modifiers(ಧ್ರುವ ವರ್ಣ *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    ಯಾವತ್ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ಪ್ರತ್ಯಾಗಮ p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC ಶೂನ್ಯ asm_compute_constraints(ASMOperand *operands,
                                    ಪೂರ್ಣಾಙ್ಕ nb_operands, ಪೂರ್ಣಾಙ್ಕ nb_outputs,
                                    ಧ್ರುವ uint8_t *clobber_regs,
                                    ಪೂರ್ಣಾಙ್ಕ *pout_reg)
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
    ಪೂರ್ಣಾಙ್ಕ sorted_op[MAX_ASM_OPERANDS];
    ಪೂರ್ಣಾಙ್ಕ i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ಧ್ರುವ ವರ್ಣ *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->ಒಳಹರಿವು_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ಯದಿ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, ರಿಕ್ತ);
            ಯದಿ ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            ಯದಿ (operands[k].ಒಳಹರಿವು_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ಒಳಹರಿವು_index = i;
            op->priority = 5;
        } ಅನ್ಯಥಾ ಯದಿ ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } ಅನ್ಯಥಾ {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    ಪ್ರತಿ (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    ಪ್ರತಿ (i = 0; i < nb_operands - 1; i++) {
        ಪ್ರತಿ (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            ಯದಿ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    ಪ್ರತಿ (i = 0; i < NB_ASM_REGS; i++) {
        ಯದಿ (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        ಅನ್ಯಥಾ
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_IN_MASK | REG_OUT_MASK;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ಯದಿ (op->ref_index >= 0)
            ಅನುವರ್ತ;
        /* select if register is used for output, input or both */
        ಯದಿ (op->ಒಳಹರಿವು_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } ಅನ್ಯಥಾ ಯದಿ (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } ಅನ್ಯಥಾ {
            reg_mask = REG_IN_MASK;
        }
        ಯದಿ (op->reg >= 0) {
            ಯದಿ (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        ವಿಕಲ್ಪ (c) {
        ಪಕ್ಷ '=': // Operand is written-to
            ಗಚ್ಛ try_next;
        ಪಕ್ಷ '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        ಪಕ್ಷ '&': // Operand is clobbered before the instruction is done using the input operands
            ಯದಿ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            ಗಚ್ಛ try_next;
        ಪಕ್ಷ 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        ಪಕ್ಷ 'r': // general-purpose register
        ಪಕ್ಷ 'p': // loadable/storable address
            /* any general register */
            ಯದಿ ((reg = op->reg) >= 0)
                ಗಚ್ಛ reg_found;
            ಅನ್ಯಥಾ ಪ್ರತಿ (reg = 0; reg <= 8; reg++) {
                ಯದಿ (!is_reg_allocated(reg))
                    ಗಚ್ಛ reg_found;
            }
            ಗಚ್ಛ try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        ಪಕ್ಷ 'J': // integer in the range -4095 to 4095 [ARM]
        ಪಕ್ಷ 'K': // integer that satisfies constraint I when inverted (one's complement)
        ಪಕ್ಷ 'L': // integer that satisfies constraint I when inverted (two's complement)
        ಪಕ್ಷ 'i': // immediate integer operand, including symbolic constants
            ಯದಿ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'M': // integer in the range 0 to 32
            ಯದಿ (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'm': // memory operand
        ಪಕ್ಷ 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ಯದಿ (j < nb_outputs || c == 'm') {
                ಯದಿ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    ಪ್ರತಿ (reg = 0; reg <= 8; reg++) {
                        ಯದಿ (!(regs_allocated[reg] & REG_IN_MASK))
                            ಗಚ್ಛ reg_found1;
                    }
                    ಗಚ್ಛ try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            ಭಙ್ಗ;
        }
        /* if a reference is present for that operand, we assign it too */
        ಯದಿ (op->ಒಳಹರಿವು_index >= 0) {
            operands[op->ಒಳಹರಿವು_index].reg = op->reg;
            operands[op->ಒಳಹರಿವು_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ಯದಿ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            ಪ್ರತಿ (reg = 0; reg <= 8; reg++) {
                ಯದಿ (!(regs_allocated[reg] & REG_OUT_MASK))
                    ಗಚ್ಛ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            ಭಙ್ಗ;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ರಿಕ್ತ) : "",
               op->constraint, op->vt->r, op->reg);
    }
    ಯದಿ (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC ಶೂನ್ಯ asm_clobber(uint8_t *clobber_regs, ಧ್ರುವ ವರ್ಣ *str)
{
    ಪೂರ್ಣಾಙ್ಕ reg;
    TokenSym *ts;

    ಯದಿ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ಪ್ರತ್ಯಾಗಮ;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    ಯದಿ (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ asm_parse_regvar (ಪೂರ್ಣಾಙ್ಕ t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    ಯದಿ (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        ಪ್ರತ್ಯಾಗಮ -1;

    ಯದಿ (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        ಪ್ರತ್ಯಾಗಮ t - TOK_ASM_r0;

    ಯದಿ (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        ಪ್ರತ್ಯಾಗಮ t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    ಪ್ರತ್ಯಾಗಮ t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
