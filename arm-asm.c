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

ST_FUNC ଶୂନ୍ୟ g(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ST_FUNC ଶୂନ୍ୟ gen_le16(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ST_FUNC ଶୂନ୍ୟ gen_le32(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);

/*************************************************************/
#ଅନ୍ୟଥା
/*************************************************************/

#define USING_GLOBALS
#ଅନ୍ତର୍ଭାଵ "tcc.h"

ଗଣନା {
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

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା Operand {
    uint32_t type;
    ସଂଘ {
        uint8_t reg;
        uint16_t regset;
        ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e;
    };
} Operand;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_parse_vfp_regvar(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, ପୂର୍ଣ୍ଣସଂଖ୍ୟା double_precision)
{
    ଯଦି (double_precision) {
        ଯଦି (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            ଫେରନ୍ତୁ t - TOK_ASM_d0;
    } ଅନ୍ୟଥା {
        ଯଦି (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            ଫେରନ୍ତୁ t - TOK_ASM_s0;
    }
    ଫେରନ୍ତୁ -1;
}

/* Parse a text containing operand and store the result in OP */
ସ୍ଥିର ଶୂନ୍ୟ parse_operand(TCCState *s1, Operand *op)
{
    ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    ଯଦି (tok == '{') { // regset literal
        next(); // skip '{'
        ଯେତେବେଳେ (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            ଯଦି (reg == -1) {
                expect("register");
            } ଅନ୍ୟଥା
                next(); // skip register name

            ଯଦି ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            ଯଦି (tok != ',')
                ଭାଙ୍ଗ;
            next(); // skip ','
        }
        skip('}');
        ଯଦି (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } ଅନ୍ୟଥା {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        ଫେରନ୍ତୁ;
    } ଅନ୍ୟଥା ଯଦି ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        ଫେରନ୍ତୁ;
    } ଅନ୍ୟଥା ଯଦି ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        next(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        ଫେରନ୍ତୁ;
    } ଅନ୍ୟଥା ଯଦି ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        next(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        ଫେରନ୍ତୁ;
    } ଅନ୍ୟଥା ଯଦି (tok == '#' || tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    }
    asm_ପଦସମଷ୍ଟି(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    ଯଦି (!op->e.sym) {
        ଯଦି ((ପୂର୍ଣ୍ଣସଂଖ୍ୟା) op->e.v < 0 && (ପୂର୍ଣ୍ଣସଂଖ୍ୟା) op->e.v >= -255)
            op->type = OP_IM8N;
        ଅନ୍ୟଥା ଯଦି (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } ଅନ୍ୟଥା
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC ଶୂନ୍ୟ g(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ind1;
    ଯଦି (nocode_wanted)
        ଫେରନ୍ତୁ;
    ind1 = ind + 1;
    ଯଦି (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC ଶୂନ୍ୟ gen_le16 (ପୂର୍ଣ୍ଣସଂଖ୍ୟା i)
{
    g(i);
    g(i>>8);
}

ST_FUNC ଶୂନ୍ୟ gen_le32 (ପୂର୍ଣ୍ଣସଂଖ୍ୟା i)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ind1;
    ଯଦି (nocode_wanted)
        ଫେରନ୍ତୁ;
    ind1 = ind + 4;
    ଯଦି (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC ଶୂନ୍ୟ gen_expr32(ପଦସମଷ୍ଟି_ମୂଲ୍ୟ *pe)
{
    gen_le32(pe->v);
}

ସ୍ଥିର uint32_t condition_code_of_token(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token) {
    ଯଦି (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } ଅନ୍ୟଥା
        ଫେରନ୍ତୁ (token - TOK_ASM_nopeq) & 15;
}

ସ୍ଥିର ଶୂନ୍ୟ asm_emit_opcode(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode) {
    gen_le32((condition_code_of_token(token) << 28) | opcode);
}

ସ୍ଥିର ଶୂନ୍ୟ asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

ସ୍ଥିର ଶୂନ୍ୟ asm_emit_coprocessor_opcode(uint32_t ଉପର_nibble, uint8_t cp_ସଂଖ୍ୟା, uint8_t cp_opcode, uint8_t cp_destination_register, uint8_t cp_n_operand_register, uint8_t cp_m_operand_register, uint8_t cp_opcode2, ପୂର୍ଣ୍ଣସଂଖ୍ୟା inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    ଯଦି (inter_processor_transfer)
        opcode |= 1 << 4;
    //assert(cp_opcode < 16);
    opcode |= cp_opcode << 20;
    //assert(cp_n_operand_register < 16);
    opcode |= cp_n_operand_register << 16;
    //assert(cp_destination_register < 16);
    opcode |= cp_destination_register << 12;
    //assert(cp_number < 16);
    opcode |= cp_ସଂଖ୍ୟା << 8;
    //assert(cp_information < 8);
    opcode |= cp_opcode2 << 5;
    //assert(cp_m_operand_register < 16);
    opcode |= cp_m_operand_register;
    asm_emit_unconditional_opcode((ଉପର_nibble << 28) | opcode);
}

ସ୍ଥିର ଶୂନ୍ୟ asm_nullary_opcode(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    ସ୍ଥିତି TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("nullary instruction");
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_unary_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand op;
    parse_operand(s1, &op);

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_swieq:
    ସ୍ଥିତି TOK_ASM_svceq:
        ଯଦି (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        ଅନ୍ୟଥା {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("unary instruction");
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_ଦ୍ୱିମିକ_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand ops[2];
    Operand rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);
    ଯଦି (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    ଯଦି (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ଖାଲି));

    ଯଦି (ops[1].type != OP_REG32) {
        ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
        ସ୍ଥିତି TOK_ASM_movteq:
        ସ୍ଥିତି TOK_ASM_movweq:
            ଯଦି (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                ଯଦି (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t immediate_ମୂଲ୍ୟ = ops[1].e.v;
                    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
                    ସ୍ଥିତି TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (immediate_ମୂଲ୍ୟ & 0xF000) << 4 | (immediate_ମୂଲ୍ୟ & 0xFFF));
                        ଭାଙ୍ଗ;
                    ସ୍ଥିତି TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (immediate_ମୂଲ୍ୟ & 0xF000) << 4 | (immediate_ମୂଲ୍ୟ & 0xFFF));
                        ଭାଙ୍ଗ;
                    }
                } ଅନ୍ୟଥା
                    expect("(source operand) immediate 16 bit value");
            } ଅନ୍ୟଥା
                expect("(source operand) immediate");
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            expect("(source operand) register");
        }
        ଫେରନ୍ତୁ;
    }

    ଯଦି (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ଖାଲି));

    ଯଦି (tok == ',') {
        next(); // skip ','
        ଯଦି (tok == TOK_ASM_ror) {
            next(); // skip 'ror'
            parse_operand(s1, &rotation);
            ଯଦି (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } ଅନ୍ୟଥା {
                amount = rotation.e.v;
                ବାଛ (amount) {
                ସ୍ଥିତି 8:
                    encoded_rotation = 1 << 10;
                    ଭାଙ୍ଗ;
                ସ୍ଥିତି 16:
                    encoded_rotation = 2 << 10;
                    ଭାଙ୍ଗ;
                ସ୍ଥିତି 24:
                    encoded_rotation = 3 << 10;
                    ଭାଙ୍ଗ;
                ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_clzeq:
        ଯଦି (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("binary instruction");
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_coprocessor_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token) {
    uint8_t coprocessor;
    Operand opcode1;
    Operand opcode2;
    uint8_t registers[3];
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    uint8_t ଉପର_nibble;
    uint8_t mrc = 0;

    ଯଦି (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } ଅନ୍ୟଥା {
        expect("'p<number>'");
    }
    skip(',');
    parse_operand(s1, &opcode1);
    ଯଦି (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ଖାଲି));
    }

    ପାଇଁ (i = 0; i < 3; ++i) {
        skip(',');
        ଯଦି (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mcreq)) {
            ଯଦି (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                next();
            } ଅନ୍ୟଥା {
                expect("'r<number>'");
            }
        } ଅନ୍ୟଥା {
            ଯଦି (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                next();
            } ଅନ୍ୟଥା {
                expect("'c<number>'");
            }
        }
    }
    ଯଦି (tok == ',') {
        next();
        parse_operand(s1, &opcode2);
    } ଅନ୍ୟଥା {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    ଯଦି (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (token == TOK_ASM_cdp2) {
        ଉପର_nibble = 0xF;
        asm_emit_coprocessor_opcode(ଉପର_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        ଫେରନ୍ତୁ;
    } ଅନ୍ୟଥା
        ଉପର_nibble = condition_code_of_token(token);

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(ଉପର_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        ଯଦି (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, ଖାଲି));
        }
        asm_emit_coprocessor_opcode(ଉପର_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
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
#define ENCODE_BARREL_SHIFTER_IMMEDIATE(ମୂଲ୍ୟ) ((ମୂଲ୍ୟ) << 7)

ସ୍ଥିର ଶୂନ୍ୟ asm_block_data_transfer_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    uint32_t opcode;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op0_exclam = 0;
    Operand ops[2];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_ops = 1;
    parse_operand(s1, &ops[0]);
    ଯଦି (tok == '!') {
        op0_exclam = 1;
        next(); // skip '!'
    }
    ଯଦି (tok == ',') {
        next(); // skip comma
        parse_operand(s1, &ops[1]);
        ++nb_ops;
    }
    ଯଦି (nb_ops < 1) {
        expect("at least one operand");
    } ଅନ୍ୟଥା ଯଦି (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        ଯଦି (nb_ops != 1)
            expect("exactly one operand");
        ଅନ୍ୟଥା
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        ଯଦି (nb_ops != 1)
            expect("exactly one operand");
        ଅନ୍ୟଥା
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_stmdaeq:
    ସ୍ଥିତି TOK_ASM_ldmdaeq:
    ସ୍ଥିତି TOK_ASM_stmeq:
    ସ୍ଥିତି TOK_ASM_ldmeq:
    ସ୍ଥିତି TOK_ASM_stmiaeq:
    ସ୍ଥିତି TOK_ASM_ldmiaeq:
    ସ୍ଥିତି TOK_ASM_stmdbeq:
    ସ୍ଥିତି TOK_ASM_ldmdbeq:
    ସ୍ଥିତି TOK_ASM_stmibeq:
    ସ୍ଥିତି TOK_ASM_ldmibeq:
        ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
        ସ୍ଥିତି TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_stmeq: // post-increment store
        ସ୍ଥିତି TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_ldmeq: // post-increment load
        ସ୍ଥିତି TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        ଯଦି (nb_ops != 2)
            expect("exactly two operands");
        ଅନ୍ୟଥା ଯଦି (ops[0].type != OP_REG32)
            expect("(first operand) register");
        ଅନ୍ୟଥା {
            ଯଦି (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
ସ୍ଥିର uint32_t asm_parse_optional_shift(TCCState* s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା* nb_shift, Operand* shift)
{
    uint32_t opcode = 0;
    *nb_shift = 0;
    ବାଛ (tok) {
    ସ୍ଥିତି TOK_ASM_asl:
    ସ୍ଥିତି TOK_ASM_lsl:
    ସ୍ଥିତି TOK_ASM_asr:
    ସ୍ଥିତି TOK_ASM_lsr:
    ସ୍ଥିତି TOK_ASM_ror:
        ବାଛ (tok) {
        ସ୍ଥିତି TOK_ASM_asl:
            /* fallthrough */
        ସ୍ଥିତି TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSL;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ASR;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSR;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
            ଭାଙ୍ଗ;
        }
        next();
        parse_operand(s1, shift);
        *nb_shift = 1;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_rrx:
        next();
        opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
        ଭାଙ୍ଗ;
    }
    ଫେରନ୍ତୁ opcode;
}

ସ୍ଥିର uint32_t asm_encode_shift(Operand* shift)
{
    uint64_t amount;
    uint32_t operands = 0;
    ବାଛ (shift->type) {
    ସ୍ଥିତି OP_REG32:
        ଯଦି (shift->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        ଅନ୍ୟଥା {
            operands = ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER;
            operands |= ENCODE_BARREL_SHIFTER_REGISTER(shift->reg);
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି OP_IM8:
        amount = shift->e.v;
        ଯଦି (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_IMMEDIATE(amount);
        ଅନ୍ୟଥା
            tcc_error("shift count out of range");
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        tcc_error("unknown shift amount");
    }
    ଫେରନ୍ତୁ operands;
}

ସ୍ଥିର ଶୂନ୍ୟ asm_data_processing_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand ops[3];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_ops;
    Operand shift = {0};
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_shift = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_GROUP(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    ପାଇଁ (nb_ops = 0; nb_ops < ଆକାର(ops)/ଆକାର(ops[0]); ) {
        ଯଦି (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            ଭାଙ୍ଗ;
        parse_operand(s1, &ops[nb_ops]);
        ++nb_ops;
        ଯଦି (tok != ',')
            ଭାଙ୍ଗ;
        next(); // skip ','
    }
    ଯଦି (tok == ',')
        next();
    operands |= asm_parse_optional_shift(s1, &nb_shift, &shift);
    ଯଦି (nb_ops < 2)
        expect("at least two operands");
    ଅନ୍ୟଥା ଯଦି (nb_ops == 2) {
        memcpy(&ops[2], &ops[1], ଆକାର(ops[1])); // move ops[2]
        memcpy(&ops[1], &ops[0], ଆକାର(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } ଅନ୍ୟଥା ଯଦି (nb_ops == 3) {
        ଯଦି (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, ଖାଲି));
        }
    }
    ଯଦି (nb_ops != 3) {
        expect("two or three operands");
    } ଅନ୍ୟଥା {
        uint32_t opcode = 0;
        uint32_t immediate_ମୂଲ୍ୟ;
        uint8_t half_immediate_rotation;
        ଯଦି (nb_shift && shift.type == OP_REG32) {
            ଯଦି ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
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
        ଯଦି (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        ଅନ୍ୟଥା ଯଦି (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_SET_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        ଅନ୍ୟଥା
            operands |= ENCODE_RD(ops[0].reg);
        ଯଦି (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        ଅନ୍ୟଥା ଯଦି (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        ବାଛ (ops[2].type) {
        ସ୍ଥିତି OP_REG32:
            operands |= ops[2].reg;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି OP_IM8:
        ସ୍ଥିତି OP_IM32:
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_ମୂଲ୍ୟ = ops[2].e.v;
            ପାଇଁ (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                ଯଦି (immediate_ମୂଲ୍ୟ >= 0x00 && immediate_ମୂଲ୍ୟ < 0x100)
                    ଭାଙ୍ଗ;
                // rotate left by two
                immediate_ମୂଲ୍ୟ = ((immediate_ମୂଲ୍ୟ & 0x3FFFFFFF) << 2) | ((immediate_ମୂଲ୍ୟ & 0xC0000000) >> 30);
            }
            ଯଦି (half_immediate_rotation >= 16) {
                /* fallthrough */
            } ଅନ୍ୟଥା {
                operands |= immediate_ମୂଲ୍ୟ;
                operands |= half_immediate_rotation << 8;
                ଭାଙ୍ଗ;
            }
        ସ୍ଥିତି OP_IM8N: // immediate negative value
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_ମୂଲ୍ୟ = ops[2].e.v;
            /* Instruction swapping:
               0001 = EOR - Rd:= Op1 EOR Op2     -> difficult
               0011 = RSB - Rd:= Op2 - Op1       -> difficult
               0111 = RSC - Rd:= Op2 - Op1 + C   -> difficult
               1000 = TST - CC on: Op1 AND Op2   -> difficult
               1001 = TEQ - CC on: Op1 EOR Op2   -> difficult
               1100 = ORR - Rd:= Op1 OR Op2      -> difficult
            */
            ବାଛ (opcode_nos) {
            ସ୍ଥିତି 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                immediate_ମୂଲ୍ୟ = ~immediate_ମୂଲ୍ୟ;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; // ADD
                immediate_ମୂଲ୍ୟ = -immediate_ମୂଲ୍ୟ;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                immediate_ମୂଲ୍ୟ = -immediate_ମୂଲ୍ୟ;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                immediate_ମୂଲ୍ୟ = ~immediate_ମୂଲ୍ୟ;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                immediate_ମୂଲ୍ୟ = ~immediate_ମୂଲ୍ୟ;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                immediate_ମୂଲ୍ୟ = -immediate_ମୂଲ୍ୟ;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                immediate_ମୂଲ୍ୟ = -immediate_ମୂଲ୍ୟ;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                immediate_ମୂଲ୍ୟ = ~immediate_ମୂଲ୍ୟ;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                immediate_ମୂଲ୍ୟ = ~immediate_ମୂଲ୍ୟ;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                immediate_ମୂଲ୍ୟ = ~immediate_ମୂଲ୍ୟ;
                ଭାଙ୍ଗ;
            ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, ଖାଲି));
            }
            ପାଇଁ (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                ଯଦି (immediate_ମୂଲ୍ୟ >= 0x00 && immediate_ମୂଲ୍ୟ < 0x100)
                    ଭାଙ୍ଗ;
                // rotate left by two
                immediate_ମୂଲ୍ୟ = ((immediate_ମୂଲ୍ୟ & 0x3FFFFFFF) << 2) | ((immediate_ମୂଲ୍ୟ & 0xC0000000) >> 30);
            }
            ଯଦି (half_immediate_rotation >= 16) {
                immediate_ମୂଲ୍ୟ = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (unsigned) immediate_ମୂଲ୍ୟ);
            }
            operands |= immediate_ମୂଲ୍ୟ;
            operands |= half_immediate_rotation << 8;
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            expect("(second source operand) register or immediate value");
        }

        ଯଦି (nb_shift) {
            ଯଦି (operands & ENCODE_IMMEDIATE_FLAG)
                tcc_error("immediate rotation not implemented");
            ଅନ୍ୟଥା
                operands |= asm_encode_shift(&shift);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_SET_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_shift_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand ops[3];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_ops;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    ପାଇଁ (nb_ops = 0; nb_ops < ଆକାର(ops)/ଆକାର(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        ଯଦି (tok != ',') {
            ++nb_ops;
            ଭାଙ୍ଗ;
        }
        next(); // skip ','
    }
    ଯଦି (nb_ops < 2) {
        expect("at least two operands");
    }

    ଯଦି (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } ଅନ୍ୟଥା
        operands |= ENCODE_RD(ops[0].reg);

    ଯଦି (nb_ops == 2) {
        ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
        ସ୍ଥିତି TOK_ASM_rrxseq:
            opcode |= ENCODE_SET_CONDITION_CODES;
            /* fallthrough */
        ସ୍ଥିତି TOK_ASM_rrxeq:
            ଯଦି (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
                asm_emit_opcode(token, opcode | operands);
            } ଅନ୍ୟଥା
                tcc_error("(first source operand) register");
            ଫେରନ୍ତୁ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            memcpy(&ops[2], &ops[1], ଆକାର(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], ଆକାର(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    ଯଦି (nb_ops != 3) {
        expect("two or three operands");
    }

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_lslseq:
    ସ୍ଥିତି TOK_ASM_lsrseq:
    ସ୍ଥିତି TOK_ASM_asrseq:
    ସ୍ଥିତି TOK_ASM_rorseq:
        opcode |= ENCODE_SET_CONDITION_CODES;
        ଭାଙ୍ଗ;
    }

    ବାଛ (ops[1].type) {
    ସ୍ଥିତି OP_REG32:
        operands |= ops[1].reg;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି OP_IM8:
        operands |= ENCODE_IMMEDIATE_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, ଖାଲି));
    }

    ବାଛ (ops[2].type) {
    ସ୍ଥିତି OP_REG32:
        ଯଦି ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_shift(&ops[2]);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି OP_IM8:
        ଯଦି (ops[2].e.v)
            operands |= asm_encode_shift(&ops[2]);
        ଅନ୍ୟଥା
            definitely_neutral = 1;
        ଭାଙ୍ଗ;
    }

    ଯଦି (!definitely_neutral) ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_lslseq:
    ସ୍ଥିତି TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSL;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_lsrseq:
    ସ୍ଥିତି TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSR;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_asrseq:
    ସ୍ଥିତି TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ASR;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_rorseq:
    ସ୍ଥିତି TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

ସ୍ଥିର ଶୂନ୍ୟ asm_multiplication_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand ops[4];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_ops = 0;
    uint32_t opcode = 0x90;

    ପାଇଁ (nb_ops = 0; nb_ops < ଆକାର(ops)/ଆକାର(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        ଯଦି (tok != ',') {
            ++nb_ops;
            ଭାଙ୍ଗ;
        }
        next(); // skip ','
    }
    ଯଦି (nb_ops < 2)
        expect("at least two operands");
    ଅନ୍ୟଥା ଯଦି (nb_ops == 2) {
        ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
        ସ୍ଥିତି TOK_ASM_mulseq:
        ସ୍ଥିତି TOK_ASM_muleq:
            memcpy(&ops[2], &ops[0], ଆକାର(ops[1])); // ARM is actually like this!
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
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

    ଯଦି (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    ଅନ୍ୟଥା
        expect("(destination operand) register");
    ଯଦି (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    ଅନ୍ୟଥା
        expect("(first source operand) register");
    ଯଦି (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    ଅନ୍ୟଥା
        expect("(second source operand) register");
    ଯଦି (nb_ops > 3) {
        ଯଦି (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        ଅନ୍ୟଥା
            expect("(third source operand) register");
    }

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_mulseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_muleq:
        ଯଦି (nb_ops != 3)
            expect("three operands");
        ଅନ୍ୟଥା {
            asm_emit_opcode(token, opcode);
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_mlaseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        ଯଦି (nb_ops != 4)
            expect("four operands");
        ଅନ୍ୟଥା {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_mlseq:
        opcode |= 0x00400000;
        ଯାଅ case_TOK_ASM_mlaeq;
    ସ୍ଥିତି TOK_ASM_udiveq:
        opcode |= 0x00200000;
    ସ୍ଥିତି TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("known multiplication instruction");
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_long_multiplication_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand ops[4];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    ପାଇଁ (nb_ops = 0; nb_ops < ଆକାର(ops)/ଆକାର(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        ଯଦି (tok != ',') {
            ++nb_ops;
            ଭାଙ୍ଗ;
        }
        next(); // skip ','
    }
    ଯଦି (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    ଯଦି (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    ଅନ୍ୟଥା
        expect("(destination lo accumulator) register");
    ଯଦି (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    ଅନ୍ୟଥା
        expect("(destination hi accumulator) register");
    ଯଦି (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    ଅନ୍ୟଥା
        expect("(first source operand) register");
    ଯଦି (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    ଅନ୍ୟଥା
        expect("(second source operand) register");

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_smullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_umullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_smlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_umlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("known long multiplication instruction");
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_single_data_transfer_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand ops[3];
    Operand strex_operand;
    Operand shift;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_shift = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା exclam = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା closed_bracket = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    ଯଦି (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    ଅନ୍ୟଥା {
        expect("(destination operand) register");
    }
    ଯଦି (tok != ',')
        expect("at least two arguments");
    next(); // skip ','

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_strexheq:
    ସ୍ଥିତି TOK_ASM_strexbeq:
    ସ୍ଥିତି TOK_ASM_strexeq:
        parse_operand(s1, &strex_operand);
        ଯଦି (strex_operand.type != OP_REG32) {
            expect("register");
        }
        ଯଦି (tok != ',')
            expect("at least three arguments");
        ଅନ୍ୟଥା
            next(); // skip ','
        ଭାଙ୍ଗ;
    }

    skip('[');
    parse_operand(s1, &ops[1]);
    ଯଦି (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    ଅନ୍ୟଥା {
        expect("(first source operand) register");
    }
    ଯଦି (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ଯଦି (tok == ',') {
        next(); // skip ','
        ଯଦି (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        ଯଦି (ops[2].type == OP_REG32) {
            ଯଦି (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ଖାଲି));
            }
            ଯଦି (tok == ',') {
                next();
                opcode |= asm_parse_optional_shift(s1, &nb_shift, &shift);
                ଯଦି (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } ଅନ୍ୟଥା {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    ଯଦି (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        ଯଦି (tok == '!') {
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
    ଯଦି (exclam)
        opcode |= 1 << 21; // write offset back into register

    ଯଦି (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା v = ops[2].e.v;
        ଯଦି (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ଯଦି (v >= 0) {
            opcode |= 1 << 23; // up
            ଯଦି (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ଖାଲି));
            ଅନ୍ୟଥା
                opcode |= v;
        } ଅନ୍ୟଥା { // down
            ଯଦି (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ଖାଲି));
            ଅନ୍ୟଥା
                opcode |= -v;
        }
    } ଅନ୍ୟଥା ଯଦି (ops[2].type == OP_REG32) {
        ଯଦି (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } ଅନ୍ୟଥା
        expect("register");

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        ଯଦି (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        ଯଦି (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_strexheq:
        opcode |= 1 << 21;
    ସ୍ଥିତି TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_strexeq:
        ଯଦି ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } ଅନ୍ୟଥା ଯଦି (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        ଯଦି ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_operand.reg;
        asm_emit_opcode(token, opcode);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    ସ୍ଥିତି TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_ldrexeq:
        ଯଦି ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } ଅନ୍ୟଥା ଯଦି (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        ଯଦି ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_coprocessor_data_transfer(uint32_t ଉପର_nibble, uint8_t cp_ସଂଖ୍ୟା, uint8_t CRd, ଅଚଳ Operand* Rn, ଅଚଳ Operand* offset, ପୂର୍ଣ୍ଣସଂଖ୍ୟା offset_minus, ପୂର୍ଣ୍ଣସଂଖ୍ୟା preincrement, ପୂର୍ଣ୍ଣସଂଖ୍ୟା writeback, ପୂର୍ଣ୍ଣସଂଖ୍ୟା long_transfer, ପୂର୍ଣ୍ଣସଂଖ୍ୟା load) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    ଯଦି (long_transfer)
        opcode |= 1 << 22; // long transfer

    ଯଦି (load)
        opcode |= 1 << 20; // L

    opcode |= cp_ସଂଖ୍ୟା << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    ଯଦି (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    ଯଦି (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    ଯଦି (writeback)
        opcode |= 1 << 21; // write offset back into register

    ଯଦି (offset->type == OP_IM8 || offset->type == OP_IM8N || offset->type == OP_IM32) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା v = offset->e.v;
        ଯଦି (offset_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ଯଦି (offset->type == OP_IM8N || v < 0)
            v = -v;
        ଅନ୍ୟଥା
            opcode |= 1 << 23; // up
        ଯଦି (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        ଯଦି (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } ଅନ୍ୟଥା ଯଦି (offset->type == OP_REG32) {
        ଯଦି (!offset_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= offset->reg;
        tcc_error("Using register offset to register address is not possible here");
    } ଅନ୍ୟଥା ଯଦି (offset->type == OP_VREG64) {
        opcode |= 16;
        opcode |= offset->reg;
    } ଅନ୍ୟଥା
        expect("immediate or register");

    asm_emit_unconditional_opcode((ଉପର_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
ସ୍ଥିର ଶୂନ୍ୟ asm_coprocessor_data_transfer_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_register;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା preincrement = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା exclam = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା closed_bracket = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op2_minus = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    ଯଦି (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } ଅନ୍ୟଥା {
        expect("'c<number>'");
    }

    skip(',');

    ଯଦି (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_register = tok - TOK_ASM_c0;
        next();
    } ଅନ୍ୟଥା {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    ଯଦି (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    ଯଦି (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ଯଦି (tok == ',') {
        next(); // skip ','
        ଯଦି (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        ଯଦି (ops[2].type == OP_REG32) {
            ଯଦି (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ଖାଲି));
            }
        } ଅନ୍ୟଥା ଯଦି (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, ଖାଲି));
        }
    } ଅନ୍ୟଥା {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    ଯଦି (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        ଯଦି (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    // TODO: Support options.

    ଯଦି (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        ବାଛ (token) {
        ସ୍ଥିତି TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        ସ୍ଥିତି TOK_ASM_ldc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        ସ୍ଥିତି TOK_ASM_stc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            ଭାଙ୍ଗ;
        }
    } ଅନ୍ୟଥା ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_stceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_ldceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("coprocessor data transfer instruction");
    }
}

#ଯଦି defined(TCC_ARM_VFP)
#define CP_SINGLE_PRECISION_FLOAT 10
#define CP_DOUBLE_PRECISION_FLOAT 11

ସ୍ଥିର ଶୂନ୍ୟ asm_floating_point_single_data_transfer_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_register = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    ଯଦି (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        long_transfer = coprocessor_destination_register & 1;
        coprocessor_destination_register >>= 1;
    } ଅନ୍ୟଥା ଯଦି (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        next();
    } ଅନ୍ୟଥା {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    ଯଦି (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    ଯଦି (tok == ',') {
        next(); // skip ','
        parse_operand(s1, &ops[2]);
        ଯଦି (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } ଅନ୍ୟଥା {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_vldreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vstreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("floating point data transfer instruction");
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_floating_point_block_data_transfer_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    uint8_t coprocessor = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା first_regset_register;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_regset_register;
    uint8_t regset_item_ଗଣନା;
    uint8_t extra_register_bit = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op0_exclam = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା load = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା preincrement = 0;
    Operand ops[1];
    Operand offset;
    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_vpusheq:
    ସ୍ଥିତି TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        parse_operand(s1, &ops[0]);
        ଯଦି (tok == '!') {
            op0_exclam = 1;
            next(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    first_regset_register = asm_parse_vfp_regvar(tok, 1);
    ଯଦି ((first_regset_register = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        next();
    } ଅନ୍ୟଥା ଯଦି ((first_regset_register = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        next();
    } ଅନ୍ୟଥା {
        expect("floating-point register");
    }

    ଯଦି (tok == '-') {
        next();
        ଯଦି ((last_regset_register = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            next();
        ଅନ୍ୟଥା {
            expect("floating-point register");
        }
    } ଅନ୍ୟଥା
        last_regset_register = first_regset_register;

    ଯଦି (last_regset_register < first_regset_register) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_item_ଗଣନା = last_regset_register - first_regset_register + 1;
    ଯଦି (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_item_ଗଣନା <<= 1;
    ଅନ୍ୟଥା {
        extra_register_bit = first_regset_register & 1;
        first_regset_register >>= 1;
    }
    offset.type = OP_IM8;
    offset.e.v = regset_item_ଗଣନା << 2;
    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_vstmeq: // post-increment store
    ସ୍ଥିତି TOK_ASM_vstmiaeq: // post-increment store
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vpopeq:
    ସ୍ଥିତି TOK_ASM_vldmeq: // post-increment load
    ସ୍ଥିତି TOK_ASM_vldmiaeq: // post-increment load
        load = 1;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vldmdbeq: // pre-decrement load
        load = 1;
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_vpusheq:
    ସ୍ଥିତି TOK_ASM_vstmdbeq: // pre-decrement store
        offset.type = OP_IM8N;
        offset.e.v = -offset.e.v;
        preincrement = 1;
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("floating point block data transfer instruction");
    }
    ଯଦି (ops[0].type != OP_REG32)
        expect("(first operand) register");
    ଅନ୍ୟଥା ଯଦି (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ଖାଲି));
    ଅନ୍ୟଥା ଯଦି (!op0_exclam && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, ଖାଲି));
    ଅନ୍ୟଥା
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, first_regset_register, &ops[0], &offset, 0, preincrement, op0_exclam, extra_register_bit, load);
}

#define VMOV_FRACTIONAL_DIGITS 7
#define VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

ସ୍ଥିର uint32_t vmov_parse_fractional_part(ଅଚଳ ଅକ୍ଷର* s)
{
    uint32_t result = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପାଇଁ (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        ଅକ୍ଷର c = *s;
        result *= 10;
        ଯଦି (c >= '0' && c <= '9') {
            result += (c - '0');
            ++s;
        }
    }
    ଯଦି (*s)
        expect("decimal numeral");
    ଫେରନ୍ତୁ result;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା vmov_linear_approx_index(uint32_t beginning, uint32_t end, uint32_t ମୂଲ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    uint32_t k;
    uint32_t xvalue;

    k = (end - beginning)/16;
    ପାଇଁ (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        ଯଦି (ମୂଲ୍ୟ == xvalue)
            ଫେରନ୍ତୁ i;
    }
    //assert(0);
    ଫେରନ୍ତୁ -1;
}

ସ୍ଥିର uint32_t vmov_parse_immediate_ମୂଲ୍ୟ() {
    uint32_t ମୂଲ୍ୟ;
    unsigned long integral_ମୂଲ୍ୟ;
    ଅଚଳ ଅକ୍ଷର *p;

    ଯଦି (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.data;
    errno = 0;
    integral_ମୂଲ୍ୟ = strtoul(p, (ଅକ୍ଷର **)&p, 0);

    ଯଦି (errno || integral_ମୂଲ୍ୟ >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    ମୂଲ୍ୟ = (uint32_t) integral_ମୂଲ୍ୟ * VMOV_ONE;
    ଯଦି (*p == '.') {
        ++p;
        ମୂଲ୍ୟ += vmov_parse_fractional_part(p);
    }
    next();
    ଫେରନ୍ତୁ ମୂଲ୍ୟ;
}

ସ୍ଥିର uint8_t vmov_encode_immediate_ମୂଲ୍ୟ(uint32_t ମୂଲ୍ୟ)
{
    uint32_t limit;
    uint32_t end = 0;
    uint32_t beginning = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r = -1;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

    limit = 32 * VMOV_ONE;
    ପାଇଁ (i = 0; i < 8; ++i) {
        ଯଦି (ମୂଲ୍ୟ < limit) {
            end = limit;
            limit >>= 1;
            beginning = limit;
            r = i;
        } ଅନ୍ୟଥା
            limit >>= 1;
    }
    ଯଦି (r == -1 || ମୂଲ୍ୟ < beginning || ମୂଲ୍ୟ > end) {
        tcc_error("invalid decimal number for vmov: %d", ମୂଲ୍ୟ);
    }
    n = vmov_linear_approx_index(beginning, end, ମୂଲ୍ୟ);
    ଫେରନ୍ତୁ n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
ସ୍ଥିର ଶୂନ୍ୟ asm_floating_point_immediate_data_processing_opcode_tail(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t immediate_ମୂଲ୍ୟ = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op_minus = 0;
    uint8_t code;

    operands[0] = CRd;

    ଯଦି (tok == '#' || tok == '$') {
        next();
    }
    ଯଦି (tok == '-') {
        op_minus = 1;
        next();
    }
    immediate_ମୂଲ୍ୟ = vmov_parse_immediate_ମୂଲ୍ୟ();

    opcode1 = 11; // "Other" instruction
    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_vcmpeq_f32:
    ସ୍ଥିତି TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        ଯଦି (immediate_ମୂଲ୍ୟ) {
            expect("Immediate value 0");
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vcmpeeq_f32:
    ସ୍ଥିତି TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        ଯଦି (immediate_ମୂଲ୍ୟ) {
            expect("Immediate value 0");
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vmoveq_f32:
    ସ୍ଥିତି TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        ଯଦି (op_minus)
            operands[1] = 0x8;
        ଅନ୍ୟଥା
            operands[1] = 0x0;
        code = vmov_encode_immediate_ମୂଲ୍ୟ(immediate_ମୂଲ୍ୟ);
        operands[1] |= code >> 4;
        operands[2] = code & 0xF;
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("known floating point with immediate instruction");
    }

    ଯଦି (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        ଯଦି (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

ସ୍ଥିର ଶୂନ୍ୟ asm_floating_point_reg_arm_reg_transfer_opcode_tail(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, ପୂର୍ଣ୍ଣସଂଖ୍ୟା coprocessor, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_arm_regs, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_ops, Operand ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    ବାଛ (coprocessor) {
    ସ୍ଥିତି CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        ଯଦି (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        ଯଦି (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            memcpy(&ops[2], &ops[1], ଆକାର(ops[2]));
            memcpy(&ops[1], &ops[0], ଆକାର(ops[1]));
            memcpy(&ops[0], &ops[2], ଆକାର(ops[0]));
        } ଅନ୍ୟଥା
            opcode1 |= 1;

        ଯଦି (ops[1].type == OP_VREG32) {
            ଯଦି (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        ଯଦି (ops[0].type == OP_VREG32) {
            ଯଦି (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି CP_DOUBLE_PRECISION_FLOAT:
        ଯଦି (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        ଯଦି (ops[0].type == OP_VREG64) {
            ଯଦି (ops[2].type == OP_REG32) {
                Operand temp;
                // need to rotate operand list to the left
                memcpy(&temp, &ops[0], ଆକାର(temp));
                memcpy(&ops[0], &ops[1], ଆକାର(ops[0]));
                memcpy(&ops[1], &ops[2], ଆକାର(ops[1]));
                memcpy(&ops[2], &temp, ଆକାର(ops[2]));
            } ଅନ୍ୟଥା {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } ଅନ୍ୟଥା ଯଦି (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } ଅନ୍ୟଥା {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        tcc_internal_error("unknown coprocessor");
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_floating_point_vcvt_data_processing_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token) {
    uint8_t coprocessor = 0;
    Operand ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_vcvtreq_s32_f64:
    ସ୍ଥିତି TOK_ASM_vcvtreq_u32_f64:
    ସ୍ଥିତି TOK_ASM_vcvteq_s32_f64:
    ସ୍ଥିତି TOK_ASM_vcvteq_u32_f64:
    ସ୍ଥିତି TOK_ASM_vcvteq_f64_s32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f64_u32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vcvtreq_s32_f32:
    ସ୍ଥିତି TOK_ASM_vcvtreq_u32_f32:
    ସ୍ଥିତି TOK_ASM_vcvteq_s32_f32:
    ସ୍ଥିତି TOK_ASM_vcvteq_u32_f32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f32_s32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f32_u32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, ଖାଲି));
    }

    parse_operand(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_vcvtreq_s32_f32:
    ସ୍ଥିତି TOK_ASM_vcvtreq_s32_f64:
    ସ୍ଥିତି TOK_ASM_vcvteq_s32_f32:
    ସ୍ଥିତି TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    ସ୍ଥିତି TOK_ASM_vcvteq_u32_f32:
    ସ୍ଥିତି TOK_ASM_vcvteq_u32_f64:
    ସ୍ଥିତି TOK_ASM_vcvtreq_u32_f32:
    ସ୍ଥିତି TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        ଭାଙ୍ଗ;
    /* floating-point size conversion */
    ସ୍ଥିତି TOK_ASM_vcvteq_f64_f32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        ଭାଙ୍ଗ;
    }

    skip(',');
    parse_operand(s1, &ops[2]);

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    /* floating-point -> integer */
    ସ୍ଥିତି TOK_ASM_vcvteq_s32_f32:
    ସ୍ଥିତି TOK_ASM_vcvteq_s32_f64:
    ସ୍ଥିତି TOK_ASM_vcvteq_u32_f32:
    ସ୍ଥିତି TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        ଭାଙ୍ଗ;

    /* integer -> floating-point */
    ସ୍ଥିତି TOK_ASM_vcvteq_f64_s32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        ଭାଙ୍ଗ;

    /* floating-point size conversion */
    ସ୍ଥିତି TOK_ASM_vcvteq_f64_f32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        ଭାଙ୍ଗ;
    }

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_vcvteq_f64_u32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f64_s32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f64_f32:
        ଯଦି (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } ଅନ୍ୟଥା {
            expect("d<number>, s<number>");
        }
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        ଯଦି (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            ଯଦି (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } ଅନ୍ୟଥା {
                expect("s<number>, s<number>");
            }
        } ଅନ୍ୟଥା ଯଦି (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            ଯଦି (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } ଅନ୍ୟଥା {
                expect("s<number>, d<number>");
            }
        }
    }

    ଯଦି (ops[2].type == OP_VREG32) {
        ଯଦି (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    ଯଦି (ops[0].type == OP_VREG32) {
        ଯଦି (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

ସ୍ଥିର ଶୂନ୍ୟ asm_floating_point_data_processing_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    Operand ops[3];
    uint8_t nb_ops = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା vmov = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_arm_regs = 0;

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

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_vmlaeq_f64:
    ସ୍ଥିତି TOK_ASM_vmlseq_f64:
    ସ୍ଥିତି TOK_ASM_vnmlseq_f64:
    ସ୍ଥିତି TOK_ASM_vnmlaeq_f64:
    ସ୍ଥିତି TOK_ASM_vmuleq_f64:
    ସ୍ଥିତି TOK_ASM_vnmuleq_f64:
    ସ୍ଥିତି TOK_ASM_vaddeq_f64:
    ସ୍ଥିତି TOK_ASM_vsubeq_f64:
    ସ୍ଥିତି TOK_ASM_vdiveq_f64:
    ସ୍ଥିତି TOK_ASM_vnegeq_f64:
    ସ୍ଥିତି TOK_ASM_vabseq_f64:
    ସ୍ଥିତି TOK_ASM_vsqrteq_f64:
    ସ୍ଥିତି TOK_ASM_vcmpeq_f64:
    ସ୍ଥିତି TOK_ASM_vcmpeeq_f64:
    ସ୍ଥିତି TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_vmoveq_f32:
    ସ୍ଥିତି TOK_ASM_vmoveq_f64:
        vmov = 1;
        ଭାଙ୍ଗ;
    }

    ପାଇଁ (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        ଯଦି (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_point_immediate_data_processing_opcode_tail(s1, token, coprocessor, ops[0].reg);
            ଫେରନ୍ତୁ;
        }
        parse_operand(s1, &ops[nb_ops]);
        ଯଦି (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } ଅନ୍ୟଥା ଯଦି (ops[nb_ops].type == OP_VREG32) {
            ଯଦି (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } ଅନ୍ୟଥା ଯଦି (ops[nb_ops].type == OP_VREG64) {
            ଯଦି (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } ଅନ୍ୟଥା {
            expect("floating point register");
        }
        ++nb_ops;
        ଯଦି (tok == ',')
            next();
        ଅନ୍ୟଥା
            ଭାଙ୍ଗ;
    }

    ଯଦି (nb_arm_regs == 0) {
        ଯଦି (nb_ops == 2) { // implicit
            memcpy(&ops[2], &ops[1], ଆକାର(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], ଆକାର(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        ଯଦି (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, ଖାଲି), nb_ops);
        }
    }

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_vmlaeq_f32:
    ସ୍ଥିତି TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vmlseq_f32:
    ସ୍ଥିତି TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vnmlseq_f32:
    ସ୍ଥିତି TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vnmlaeq_f32:
    ସ୍ଥିତି TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vmuleq_f32:
    ସ୍ଥିତି TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vnmuleq_f32:
    ସ୍ଥିତି TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vaddeq_f32:
    ସ୍ଥିତି TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vsubeq_f32:
    ସ୍ଥିତି TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vdiveq_f32:
    ସ୍ଥିତି TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vnegeq_f32:
    ସ୍ଥିତି TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vabseq_f32:
    ସ୍ଥିତି TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vsqrteq_f32:
    ସ୍ଥିତି TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vcmpeq_f32:
    ସ୍ଥିତି TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vcmpeeq_f32:
    ସ୍ଥିତି TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vmoveq_f32:
    ସ୍ଥିତି TOK_ASM_vmoveq_f64:
        ଯଦି (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_point_reg_arm_reg_transfer_opcode_tail(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            ଫେରନ୍ତୁ;
        } ଅନ୍ୟଥା {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("known floating point instruction");
    }

    ଯଦି (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        ଯଦି (ops[2].type == OP_VREG32) {
            ଯଦି (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        ଯଦି (ops[1].type == OP_VREG32) {
            ଯଦି (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        ଯଦି (ops[0].type == OP_VREG32) {
            ଯଦି (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_parse_vfp_status_regvar(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ବାଛ (t) {
    ସ୍ଥିତି TOK_ASM_fpsid:
        ଫେରନ୍ତୁ 0;
    ସ୍ଥିତି TOK_ASM_fpscr:
        ଫେରନ୍ତୁ 1;
    ସ୍ଥିତି TOK_ASM_fpexc:
        ଫେରନ୍ତୁ 8;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        ଫେରନ୍ତୁ -1;
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_floating_point_status_register_opcode(TCCState* s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା vfp_sys_reg = -1;
    Operand arm_operand;
    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_vmrseq:
        opcode = 0xf;
        ଯଦି (tok == TOK_ASM_apsr_nzcv) {
            arm_operand.type = OP_REG32;
            arm_operand.reg = 15; // not PC
            next(); // skip apsr_nzcv
        } ଅନ୍ୟଥା {
            parse_operand(s1, &arm_operand);
            ଯଦି (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ଖାଲି));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        ଯଦି (arm_operand.type == OP_REG32 && arm_operand.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, ଖାଲି));
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        skip(',');
        parse_operand(s1, &arm_operand);
        ଯଦି (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ଖାଲି));
        }
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("floating point status register instruction");
    }
    ଯଦି (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    ଯଦି (arm_operand.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode, arm_operand.reg, vfp_sys_reg, 0x10, 0, 0);
}

#endif

ସ୍ଥିର ଶୂନ୍ୟ asm_misc_single_data_transfer_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand ops[3];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା exclam = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା closed_bracket = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op2_minus = 0;
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
    ଯଦି (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    ଅନ୍ୟଥା {
        expect("(destination operand) register");
    }
    ଯଦି (tok != ',')
        expect("at least two arguments");
    ଅନ୍ୟଥା
        next(); // skip ','
    skip('[');
    parse_operand(s1, &ops[1]);
    ଯଦି (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    ଅନ୍ୟଥା {
        expect("(first source operand) register");
    }
    ଯଦି (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ଯଦି (tok == ',') {
        next(); // skip ','
        ଯଦି (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
    } ଅନ୍ୟଥା {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    ଯଦି (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        ଯଦି (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    ଯଦି (exclam) {
        ଯଦି ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, ଖାଲି));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    ଯଦି (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା v = ops[2].e.v;
        ଯଦି (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ଯଦି (v >= 0) {
            opcode |= 1 << 23; // up
            ଯଦି (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ଖାଲି));
            ଅନ୍ୟଥା {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } ଅନ୍ୟଥା { // down
            ଯଦି (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ଖାଲି));
            ଅନ୍ୟଥା {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } ଅନ୍ୟଥା ଯଦି (ops[2].type == OP_REG32) {
        ଯଦି (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ops[2].reg;
    } ଅନ୍ୟଥା
        expect("register");

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    ସ୍ଥିତି TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        ଭାଙ୍ଗ;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
ସ୍ଥିର uint32_t encbranchoffset(ପୂର୍ଣ୍ଣସଂଖ୍ୟା pos, ପୂର୍ଣ୍ଣସଂଖ୍ୟା addr, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fail)
{
  addr-=pos+8;
  addr/=4;
  ଯଦି(addr>=0x7fffff || addr<-0x800000) {
    ଯଦି(fail)
      tcc_error("branch offset is too far");
    ଫେରନ୍ତୁ 0;
  }
  ଫେରନ୍ତୁ /*not 0x0A000000|*/(addr&0xffffff);
}

ସ୍ଥିର ଶୂନ୍ୟ asm_branch_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା jmp_disp = 0;
    Operand op;
    ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e;
    ElfSym *esym;

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_beq:
    ସ୍ଥିତି TOK_ASM_bleq:
        asm_ପଦସମଷ୍ଟି(s1, &e);
        ଯଦି (e.sym) {
            esym = elfsym(e.sym);
            ଯଦି (esym && esym->st_shndx == cur_text_section->sh_ଅଙ୍କ) {
                jmp_disp = esym->st_ମୂଲ୍ୟ;
            } ଅନ୍ୟଥା {
                greloca(cur_text_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        parse_operand(s1, &op);
        ଭାଙ୍ଗ;
    }
    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_bxeq:
        ଯଦି (op.type != OP_REG32)
            expect("register");
        ଅନ୍ୟଥା
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_blxeq:
        ଯଦି (op.type != OP_REG32)
            expect("register");
        ଅନ୍ୟଥା
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("branch instruction");
    }
}

ST_FUNC ଶୂନ୍ୟ asm_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    ଯେତେବେଳେ (token == TOK_LINEFEED) {
        next();
        token = tok;
    }
    ଯଦି (token == TOK_EOF)
        ଫେରନ୍ତୁ;
    ଯଦି (token < TOK_ASM_nopeq) { // no condition code
        ବାଛ (token) {
        ସ୍ଥିତି TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି TOK_ASM_ldc2:
        ସ୍ଥିତି TOK_ASM_ldc2l:
        ସ୍ଥିତି TOK_ASM_stc2:
        ସ୍ଥିତି TOK_ASM_stc2l:
            asm_coprocessor_data_transfer_opcode(s1, token);
            ଫେରନ୍ତୁ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            expect("instruction");
        }
    }

    ବାଛ (ARM_INSTRUCTION_GROUP(token)) {
    ସ୍ଥିତି TOK_ASM_pusheq:
    ସ୍ଥିତି TOK_ASM_popeq:
    ସ୍ଥିତି TOK_ASM_stmdaeq:
    ସ୍ଥିତି TOK_ASM_ldmdaeq:
    ସ୍ଥିତି TOK_ASM_stmeq:
    ସ୍ଥିତି TOK_ASM_ldmeq:
    ସ୍ଥିତି TOK_ASM_stmiaeq:
    ସ୍ଥିତି TOK_ASM_ldmiaeq:
    ସ୍ଥିତି TOK_ASM_stmdbeq:
    ସ୍ଥିତି TOK_ASM_ldmdbeq:
    ସ୍ଥିତି TOK_ASM_stmibeq:
    ସ୍ଥିତି TOK_ASM_ldmibeq:
        asm_block_data_transfer_opcode(s1, token);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_nopeq:
    ସ୍ଥିତି TOK_ASM_wfeeq:
    ସ୍ଥିତି TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_swieq:
    ସ୍ଥିତି TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_beq:
    ସ୍ଥିତି TOK_ASM_bleq:
    ସ୍ଥିତି TOK_ASM_bxeq:
    ସ୍ଥିତି TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_clzeq:
    ସ୍ଥିତି TOK_ASM_sxtbeq:
    ସ୍ଥିତି TOK_ASM_sxtheq:
    ସ୍ଥିତି TOK_ASM_uxtbeq:
    ସ୍ଥିତି TOK_ASM_uxtheq:
    ସ୍ଥିତି TOK_ASM_movteq:
    ସ୍ଥିତି TOK_ASM_movweq:
        asm_ଦ୍ୱିମିକ_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_ldreq:
    ସ୍ଥିତି TOK_ASM_ldrbeq:
    ସ୍ଥିତି TOK_ASM_streq:
    ସ୍ଥିତି TOK_ASM_strbeq:
    ସ୍ଥିତି TOK_ASM_ldrexeq:
    ସ୍ଥିତି TOK_ASM_ldrexbeq:
    ସ୍ଥିତି TOK_ASM_ldrexheq:
    ସ୍ଥିତି TOK_ASM_strexeq:
    ସ୍ଥିତି TOK_ASM_strexbeq:
    ସ୍ଥିତି TOK_ASM_strexheq:
        asm_single_data_transfer_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_ldrheq:
    ସ୍ଥିତି TOK_ASM_ldrsheq:
    ସ୍ଥିତି TOK_ASM_ldrsbeq:
    ସ୍ଥିତି TOK_ASM_strheq:
       asm_misc_single_data_transfer_opcode(s1, token);
       ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_andeq:
    ସ୍ଥିତି TOK_ASM_eoreq:
    ସ୍ଥିତି TOK_ASM_subeq:
    ସ୍ଥିତି TOK_ASM_rsbeq:
    ସ୍ଥିତି TOK_ASM_addeq:
    ସ୍ଥିତି TOK_ASM_adceq:
    ସ୍ଥିତି TOK_ASM_sbceq:
    ସ୍ଥିତି TOK_ASM_rsceq:
    ସ୍ଥିତି TOK_ASM_tsteq:
    ସ୍ଥିତି TOK_ASM_teqeq:
    ସ୍ଥିତି TOK_ASM_cmpeq:
    ସ୍ଥିତି TOK_ASM_cmneq:
    ସ୍ଥିତି TOK_ASM_orreq:
    ସ୍ଥିତି TOK_ASM_moveq:
    ସ୍ଥିତି TOK_ASM_biceq:
    ସ୍ଥିତି TOK_ASM_mvneq:
    ସ୍ଥିତି TOK_ASM_andseq:
    ସ୍ଥିତି TOK_ASM_eorseq:
    ସ୍ଥିତି TOK_ASM_subseq:
    ସ୍ଥିତି TOK_ASM_rsbseq:
    ସ୍ଥିତି TOK_ASM_addseq:
    ସ୍ଥିତି TOK_ASM_adcseq:
    ସ୍ଥିତି TOK_ASM_sbcseq:
    ସ୍ଥିତି TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    ସ୍ଥିତି TOK_ASM_orrseq:
    ସ୍ଥିତି TOK_ASM_movseq:
    ସ୍ଥିତି TOK_ASM_bicseq:
    ସ୍ଥିତି TOK_ASM_mvnseq:
        asm_data_processing_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_lsleq:
    ସ୍ଥିତି TOK_ASM_lslseq:
    ସ୍ଥିତି TOK_ASM_lsreq:
    ସ୍ଥିତି TOK_ASM_lsrseq:
    ସ୍ଥିତି TOK_ASM_asreq:
    ସ୍ଥିତି TOK_ASM_asrseq:
    ସ୍ଥିତି TOK_ASM_roreq:
    ସ୍ଥିତି TOK_ASM_rorseq:
    ସ୍ଥିତି TOK_ASM_rrxseq:
    ସ୍ଥିତି TOK_ASM_rrxeq:
        asm_shift_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_muleq:
    ସ୍ଥିତି TOK_ASM_mulseq:
    ସ୍ଥିତି TOK_ASM_mlaeq:
    ସ୍ଥିତି TOK_ASM_mlaseq:
    ସ୍ଥିତି TOK_ASM_mlseq:
    ସ୍ଥିତି TOK_ASM_udiveq:
    ସ୍ଥିତି TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_smulleq:
    ସ୍ଥିତି TOK_ASM_smullseq:
    ସ୍ଥିତି TOK_ASM_umulleq:
    ସ୍ଥିତି TOK_ASM_umullseq:
    ସ୍ଥିତି TOK_ASM_smlaleq:
    ସ୍ଥିତି TOK_ASM_smlalseq:
    ସ୍ଥିତି TOK_ASM_umlaleq:
    ସ୍ଥିତି TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_cdpeq:
    ସ୍ଥିତି TOK_ASM_mcreq:
    ସ୍ଥିତି TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_ldceq:
    ସ୍ଥିତି TOK_ASM_ldcleq:
    ସ୍ଥିତି TOK_ASM_stceq:
    ସ୍ଥିତି TOK_ASM_stcleq:
        asm_coprocessor_data_transfer_opcode(s1, token);
        ଫେରନ୍ତୁ;

#ଯଦି defined(TCC_ARM_VFP)
    ସ୍ଥିତି TOK_ASM_vldreq:
    ସ୍ଥିତି TOK_ASM_vstreq:
        asm_floating_point_single_data_transfer_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_vmlaeq_f32:
    ସ୍ଥିତି TOK_ASM_vmlseq_f32:
    ସ୍ଥିତି TOK_ASM_vnmlseq_f32:
    ସ୍ଥିତି TOK_ASM_vnmlaeq_f32:
    ସ୍ଥିତି TOK_ASM_vmuleq_f32:
    ସ୍ଥିତି TOK_ASM_vnmuleq_f32:
    ସ୍ଥିତି TOK_ASM_vaddeq_f32:
    ସ୍ଥିତି TOK_ASM_vsubeq_f32:
    ସ୍ଥିତି TOK_ASM_vdiveq_f32:
    ସ୍ଥିତି TOK_ASM_vnegeq_f32:
    ସ୍ଥିତି TOK_ASM_vabseq_f32:
    ସ୍ଥିତି TOK_ASM_vsqrteq_f32:
    ସ୍ଥିତି TOK_ASM_vcmpeq_f32:
    ସ୍ଥିତି TOK_ASM_vcmpeeq_f32:
    ସ୍ଥିତି TOK_ASM_vmoveq_f32:
    ସ୍ଥିତି TOK_ASM_vmlaeq_f64:
    ସ୍ଥିତି TOK_ASM_vmlseq_f64:
    ସ୍ଥିତି TOK_ASM_vnmlseq_f64:
    ସ୍ଥିତି TOK_ASM_vnmlaeq_f64:
    ସ୍ଥିତି TOK_ASM_vmuleq_f64:
    ସ୍ଥିତି TOK_ASM_vnmuleq_f64:
    ସ୍ଥିତି TOK_ASM_vaddeq_f64:
    ସ୍ଥିତି TOK_ASM_vsubeq_f64:
    ସ୍ଥିତି TOK_ASM_vdiveq_f64:
    ସ୍ଥିତି TOK_ASM_vnegeq_f64:
    ସ୍ଥିତି TOK_ASM_vabseq_f64:
    ସ୍ଥିତି TOK_ASM_vsqrteq_f64:
    ସ୍ଥିତି TOK_ASM_vcmpeq_f64:
    ସ୍ଥିତି TOK_ASM_vcmpeeq_f64:
    ସ୍ଥିତି TOK_ASM_vmoveq_f64:
        asm_floating_point_data_processing_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_vcvtreq_s32_f32:
    ସ୍ଥିତି TOK_ASM_vcvtreq_s32_f64:
    ସ୍ଥିତି TOK_ASM_vcvteq_s32_f32:
    ସ୍ଥିତି TOK_ASM_vcvteq_s32_f64:
    ସ୍ଥିତି TOK_ASM_vcvtreq_u32_f32:
    ସ୍ଥିତି TOK_ASM_vcvtreq_u32_f64:
    ସ୍ଥିତି TOK_ASM_vcvteq_u32_f32:
    ସ୍ଥିତି TOK_ASM_vcvteq_u32_f64:
    ସ୍ଥିତି TOK_ASM_vcvteq_f64_s32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f32_s32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f64_u32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f32_u32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f64_f32:
    ସ୍ଥିତି TOK_ASM_vcvteq_f32_f64:
        asm_floating_point_vcvt_data_processing_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_vpusheq:
    ସ୍ଥିତି TOK_ASM_vpopeq:
    ସ୍ଥିତି TOK_ASM_vldmeq:
    ସ୍ଥିତି TOK_ASM_vldmiaeq:
    ସ୍ଥିତି TOK_ASM_vldmdbeq:
    ସ୍ଥିତି TOK_ASM_vstmeq:
    ସ୍ଥିତି TOK_ASM_vstmiaeq:
    ସ୍ଥିତି TOK_ASM_vstmdbeq:
        asm_floating_point_block_data_transfer_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_vmsreq:
    ସ୍ଥିତି TOK_ASM_vmrseq:
        asm_floating_point_status_register_opcode(s1, token);
        ଫେରନ୍ତୁ;
#endif

    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("known instruction");
    }
}

ST_FUNC ଶୂନ୍ୟ subst_asm_operand(CString *add_str, SValue *sv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା modifier)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, reg, size, val;

    r = sv->r;
    ଯଦି ((r & VT_VALMASK) == VT_CONST) {
        ଯଦି (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        ଯଦି (r & VT_SYM) {
            ଅଚଳ ଅକ୍ଷର *name = get_tok_str(sv->sym->v, ଖାଲି);
            ଯଦି (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            ଯଦି (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            ଯଦି ((uint32_t) sv->c.i == 0)
                ଯାଅ no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        ଯଦି (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
      no_offset:;
    } ଅନ୍ୟଥା ଯଦି ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[fp,#%d]", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା) sv->c.i);
    } ଅନ୍ୟଥା ଯଦି (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ଯଦି (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, ଖାଲି));
    } ଅନ୍ୟଥା {
        /* register case */
        reg = r & VT_VALMASK;
        ଯଦି (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        ଯଦି ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        ଅନ୍ୟଥା ଯଦି ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        ଅନ୍ୟଥା
            size = 4;

        ଯଦି (modifier == 'b') {
            size = 1;
        } ଅନ୍ୟଥା ଯଦି (modifier == 'w') {
            size = 2;
        } ଅନ୍ୟଥା ଯଦି (modifier == 'k') {
            size = 4;
        }

        ବାଛ (size) {
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            reg = TOK_ASM_r0 + reg;
            ଭାଙ୍ଗ;
        }
        cstr_printf(add_str, "%s", get_tok_str(reg, ଖାଲି));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC ଶୂନ୍ୟ asm_gen_code(ASMOperand *operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_operands,
                          ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_outputs, ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_output,
                          uint8_t *clobber_regs,
                          ପୂର୍ଣ୍ଣସଂଖ୍ୟା out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    ସ୍ଥିର ଅଚଳ uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, ଆକାର(regs_allocated));
    ପାଇଁ(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        ଯଦି (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    ପାଇଁ(i = 0; i < ଆକାର(reg_saved)/ଆକାର(reg_saved[0]); i++) {
        reg = reg_saved[i];
        ଯଦି (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    ଯଦି (!is_output) { // prolog
        /* generate reg save code */
        ଯଦି (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        ପାଇଁ(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ଯଦି (op->reg >= 0) {
                ଯଦି ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } ଅନ୍ୟଥା ଯଦି (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    load(op->reg, op->vt);
                    ଯଦି (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } ଅନ୍ୟଥା { // epilog
        /* generate save code */
        ପାଇଁ(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ଯଦି (op->reg >= 0) {
                ଯଦି ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ଯଦି (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } ଅନ୍ୟଥା {
                    store(op->reg, op->vt);
                    ଯଦି (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        ଯଦି (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ପୂର୍ଣ୍ଣସଂଖ୍ୟା constraint_priority(ଅଚଳ ଅକ୍ଷର *str)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    ପାଇଁ(;;) {
        c = *str;
        ଯଦି (c == '\0')
            ଭାଙ୍ଗ;
        str++;
        ବାଛ(c) {
        ସ୍ଥିତି 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        ସ୍ଥିତି 'r': // register [general]
        ସ୍ଥିତି 'p': // valid memory address for load,store [general]
            pr = 3;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 'M': // integer constant for shifts [ARM]
        ସ୍ଥିତି 'I': // integer valid for data processing instruction immediate
        ସ୍ଥିତି 'J': // integer in range -4095...4095

        ସ୍ଥିତି 'i': // immediate integer operand, including symbolic constants [general]
        ସ୍ଥିତି 'm': // memory operand [general]
        ସ୍ଥିତି 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            tcc_error("unknown constraint '%c'", c);
        }
        ଯଦି (pr > priority)
            priority = pr;
    }
    ଫେରନ୍ତୁ priority;
}

ସ୍ଥିର ଅଚଳ ଅକ୍ଷର *skip_constraint_modifiers(ଅଚଳ ଅକ୍ଷର *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    ଯେତେବେଳେ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ଫେରନ୍ତୁ p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC ଶୂନ୍ୟ asm_compute_constraints(ASMOperand *operands,
                                    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_outputs,
                                    ଅଚଳ uint8_t *clobber_regs,
                                    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pout_reg)
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
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sorted_op[MAX_ASM_OPERANDS];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ଅଚଳ ଅକ୍ଷର *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    ପାଇଁ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->ନିବେଶ_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    ପାଇଁ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ଯଦି (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, ଖାଲି);
            ଯଦି ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            ଯଦି (operands[k].ନିବେଶ_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ନିବେଶ_index = i;
            op->priority = 5;
        } ଅନ୍ୟଥା ଯଦି ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } ଅନ୍ୟଥା {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    ପାଇଁ (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    ପାଇଁ (i = 0; i < nb_operands - 1; i++) {
        ପାଇଁ (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            ଯଦି (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    ପାଇଁ (i = 0; i < NB_ASM_REGS; i++) {
        ଯଦି (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        ଅନ୍ୟଥା
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_IN_MASK | REG_OUT_MASK;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    ପାଇଁ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ଯଦି (op->ref_index >= 0)
            ଜାରି;
        /* select if register is used for output, input or both */
        ଯଦି (op->ନିବେଶ_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } ଅନ୍ୟଥା ଯଦି (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } ଅନ୍ୟଥା {
            reg_mask = REG_IN_MASK;
        }
        ଯଦି (op->reg >= 0) {
            ଯଦି (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        ବାଛ (c) {
        ସ୍ଥିତି '=': // Operand is written-to
            ଯାଅ try_next;
        ସ୍ଥିତି '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        ସ୍ଥିତି '&': // Operand is clobbered before the instruction is done using the input operands
            ଯଦି (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            ଯାଅ try_next;
        ସ୍ଥିତି 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        ସ୍ଥିତି 'r': // general-purpose register
        ସ୍ଥିତି 'p': // loadable/storable address
            /* any general register */
            ଯଦି ((reg = op->reg) >= 0)
                ଯାଅ reg_found;
            ଅନ୍ୟଥା ପାଇଁ (reg = 0; reg <= 8; reg++) {
                ଯଦି (!is_reg_allocated(reg))
                    ଯାଅ reg_found;
            }
            ଯାଅ try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        ସ୍ଥିତି 'J': // integer in the range -4095 to 4095 [ARM]
        ସ୍ଥିତି 'K': // integer that satisfies constraint I when inverted (one's complement)
        ସ୍ଥିତି 'L': // integer that satisfies constraint I when inverted (two's complement)
        ସ୍ଥିତି 'i': // immediate integer operand, including symbolic constants
            ଯଦି (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ଯାଅ try_next;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 'M': // integer in the range 0 to 32
            ଯଦି (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                ଯାଅ try_next;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 'm': // memory operand
        ସ୍ଥିତି 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ଯଦି (j < nb_outputs || c == 'm') {
                ଯଦି ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    ପାଇଁ (reg = 0; reg <= 8; reg++) {
                        ଯଦି (!(regs_allocated[reg] & REG_IN_MASK))
                            ଯାଅ reg_found1;
                    }
                    ଯାଅ try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            ଭାଙ୍ଗ;
        }
        /* if a reference is present for that operand, we assign it too */
        ଯଦି (op->ନିବେଶ_index >= 0) {
            operands[op->ନିବେଶ_index].reg = op->reg;
            operands[op->ନିବେଶ_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    ପାଇଁ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ଯଦି (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            ପାଇଁ (reg = 0; reg <= 8; reg++) {
                ଯଦି (!(regs_allocated[reg] & REG_OUT_MASK))
                    ଯାଅ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            ଭାଙ୍ଗ;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    ପାଇଁ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ଖାଲି) : "",
               op->constraint, op->vt->r, op->reg);
    }
    ଯଦି (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC ଶୂନ୍ୟ asm_clobber(uint8_t *clobber_regs, ଅଚଳ ଅକ୍ଷର *str)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା reg;
    TokenSym *ts;

    ଯଦି (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ଫେରନ୍ତୁ;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    ଯଦି (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_parse_regvar (ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    ଯଦି (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        ଫେରନ୍ତୁ -1;

    ଯଦି (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        ଫେରନ୍ତୁ t - TOK_ASM_r0;

    ଯଦି (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        ଫେରନ୍ତୁ t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    ଫେରନ୍ତୁ t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
