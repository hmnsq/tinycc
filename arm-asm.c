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

ST_FUNC void g(ཧྲིལ c);
ST_FUNC void gen_le16(ཧྲིལ c);
ST_FUNC void gen_le32(ཧྲིལ c);

/*************************************************************/
#དེ་མིན
/*************************************************************/

#define USING_GLOBALS
#include "tcc.h"

ga_nanaa {
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

typedef sa_nracanaa Operand {
    uint32_t type;
    sa_ngha {
        uint8_t reg;
        uint16_t regset;
        ExprValue e;
    };
} Operand;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
static ཧྲིལ asm_parse_vfp_regvar(ཧྲིལ t, ཧྲིལ double_precision)
{
    གལ་སྲིད (double_precision) {
        གལ་སྲིད (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            ལོག t - TOK_ASM_d0;
    } དེ་མིན {
        གལ་སྲིད (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            ལོག t - TOK_ASM_s0;
    }
    ལོག -1;
}

/* Parse a text containing operand and store the result in OP */
static void parse_operand(TCCState *s1, Operand *op)
{
    ExprValue e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    གལ་སྲིད (tok == '{') { // regset literal
        next(); // skip '{'
        སྐབས (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            གལ་སྲིད (reg == -1) {
                expect("register");
            } དེ་མིན
                next(); // skip register name

            གལ་སྲིད ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            གལ་སྲིད (tok != ',')
                bha_nga;
            next(); // skip ','
        }
        skip('}');
        གལ་སྲིད (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } དེ་མིན {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        ལོག;
    } དེ་མིན གལ་སྲིད ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        ལོག;
    } དེ་མིན གལ་སྲིད ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        next(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        ལོག;
    } དེ་མིན གལ་སྲིད ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        next(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        ལོག;
    } དེ་མིན གལ་སྲིད (tok == '#' || tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    }
    asm_expr(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    གལ་སྲིད (!op->e.sym) {
        གལ་སྲིད ((ཧྲིལ) op->e.v < 0 && (ཧྲིལ) op->e.v >= -255)
            op->type = OP_IM8N;
        དེ་མིན གལ་སྲིད (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } དེ་མིན
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC void g(ཧྲིལ c)
{
    ཧྲིལ ind1;
    གལ་སྲིད (nocode_wanted)
        ལོག;
    ind1 = ind + 1;
    གལ་སྲིད (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC void gen_le16 (ཧྲིལ i)
{
    g(i);
    g(i>>8);
}

ST_FUNC void gen_le32 (ཧྲིལ i)
{
    ཧྲིལ ind1;
    གལ་སྲིད (nocode_wanted)
        ལོག;
    ind1 = ind + 4;
    གལ་སྲིད (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC void gen_expr32(ExprValue *pe)
{
    gen_le32(pe->v);
}

static uint32_t condition_code_of_token(ཧྲིལ token) {
    གལ་སྲིད (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } དེ་མིན
        ལོག (token - TOK_ASM_nopeq) & 15;
}

static void asm_emit_opcode(ཧྲིལ token, uint32_t opcode) {
    gen_le32((condition_code_of_token(token) << 28) | opcode);
}

static void asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

static void asm_emit_coprocessor_opcode(uint32_t high_nibble, uint8_t cp_number, uint8_t cp_opcode, uint8_t cp_destination_register, uint8_t cp_n_operand_register, uint8_t cp_m_operand_register, uint8_t cp_opcode2, ཧྲིལ inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    གལ་སྲིད (inter_processor_transfer)
        opcode |= 1 << 4;
    //assert(cp_opcode < 16);
    opcode |= cp_opcode << 20;
    //assert(cp_n_operand_register < 16);
    opcode |= cp_n_operand_register << 16;
    //assert(cp_destination_register < 16);
    opcode |= cp_destination_register << 12;
    //assert(cp_number < 16);
    opcode |= cp_number << 8;
    //assert(cp_information < 8);
    opcode |= cp_opcode2 << 5;
    //assert(cp_m_operand_register < 16);
    opcode |= cp_m_operand_register;
    asm_emit_unconditional_opcode((high_nibble << 28) | opcode);
}

static void asm_nullary_opcode(ཧྲིལ token)
{
    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        bha_nga;
    pak_sa TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    pak_sa TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        bha_nga;
    default:
        expect("nullary instruction");
    }
}

static void asm_unary_opcode(TCCState *s1, ཧྲིལ token)
{
    Operand op;
    parse_operand(s1, &op);

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_swieq:
    pak_sa TOK_ASM_svceq:
        གལ་སྲིད (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        དེ་མིན {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        bha_nga;
    default:
        expect("unary instruction");
    }
}

static void asm_binary_opcode(TCCState *s1, ཧྲིལ token)
{
    Operand ops[2];
    Operand rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);
    གལ་སྲིད (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    གལ་སྲིད (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, NULL));
    }

    གལ་སྲིད (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, NULL));

    གལ་སྲིད (ops[1].type != OP_REG32) {
        switch (ARM_INSTRUCTION_GROUP(token)) {
        pak_sa TOK_ASM_movteq:
        pak_sa TOK_ASM_movweq:
            གལ་སྲིད (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                གལ་སྲིད (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t immediate_value = ops[1].e.v;
                    switch (ARM_INSTRUCTION_GROUP(token)) {
                    pak_sa TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (immediate_value & 0xF000) << 4 | (immediate_value & 0xFFF));
                        bha_nga;
                    pak_sa TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (immediate_value & 0xF000) << 4 | (immediate_value & 0xFFF));
                        bha_nga;
                    }
                } དེ་མིན
                    expect("(source operand) immediate 16 bit value");
            } དེ་མིན
                expect("(source operand) immediate");
            bha_nga;
        default:
            expect("(source operand) register");
        }
        ལོག;
    }

    གལ་སྲིད (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, NULL));
    }

    གལ་སྲིད (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, NULL));

    གལ་སྲིད (tok == ',') {
        next(); // skip ','
        གལ་སྲིད (tok == TOK_ASM_ror) {
            next(); // skip 'ror'
            parse_operand(s1, &rotation);
            གལ་སྲིད (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } དེ་མིན {
                amount = rotation.e.v;
                switch (amount) {
                pak_sa 8:
                    encoded_rotation = 1 << 10;
                    bha_nga;
                pak_sa 16:
                    encoded_rotation = 2 << 10;
                    bha_nga;
                pak_sa 24:
                    encoded_rotation = 3 << 10;
                    bha_nga;
                default:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_clzeq:
        གལ་སྲིད (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        bha_nga;
    pak_sa TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        bha_nga;
    pak_sa TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        bha_nga;
    pak_sa TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        bha_nga;
    pak_sa TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        bha_nga;
    default:
        expect("binary instruction");
    }
}

static void asm_coprocessor_opcode(TCCState *s1, ཧྲིལ token) {
    uint8_t coprocessor;
    Operand opcode1;
    Operand opcode2;
    uint8_t registers[3];
    unsigned ཧྲིལ i;
    uint8_t high_nibble;
    uint8_t mrc = 0;

    གལ་སྲིད (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } དེ་མིན {
        expect("'p<number>'");
    }
    skip(',');
    parse_operand(s1, &opcode1);
    གལ་སྲིད (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, NULL));
    }

    དོན་ལུ (i = 0; i < 3; ++i) {
        skip(',');
        གལ་སྲིད (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mcreq)) {
            གལ་སྲིད (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                next();
            } དེ་མིན {
                expect("'r<number>'");
            }
        } དེ་མིན {
            གལ་སྲིད (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                next();
            } དེ་མིན {
                expect("'c<number>'");
            }
        }
    }
    གལ་སྲིད (tok == ',') {
        next();
        parse_operand(s1, &opcode2);
    } དེ་མིན {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    གལ་སྲིད (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, NULL));
    }

    གལ་སྲིད (token == TOK_ASM_cdp2) {
        high_nibble = 0xF;
        asm_emit_coprocessor_opcode(high_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        ལོག;
    } དེ་མིན
        high_nibble = condition_code_of_token(token);

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(high_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        bha_nga;
    pak_sa TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    pak_sa TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        གལ་སྲིད (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, NULL));
        }
        asm_emit_coprocessor_opcode(high_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        bha_nga;
    default:
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
#define ENCODE_BARREL_SHIFTER_IMMEDIATE(value) ((value) << 7)

static void asm_block_data_transfer_opcode(TCCState *s1, ཧྲིལ token)
{
    uint32_t opcode;
    ཧྲིལ op0_exclam = 0;
    Operand ops[2];
    ཧྲིལ nb_ops = 1;
    parse_operand(s1, &ops[0]);
    གལ་སྲིད (tok == '!') {
        op0_exclam = 1;
        next(); // skip '!'
    }
    གལ་སྲིད (tok == ',') {
        next(); // skip comma
        parse_operand(s1, &ops[1]);
        ++nb_ops;
    }
    གལ་སྲིད (nb_ops < 1) {
        expect("at least one operand");
    } དེ་མིན གལ་སྲིད (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        གལ་སྲིད (nb_ops != 1)
            expect("exactly one operand");
        དེ་མིན
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        bha_nga;
    pak_sa TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        གལ་སྲིད (nb_ops != 1)
            expect("exactly one operand");
        དེ་མིན
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        bha_nga;
    pak_sa TOK_ASM_stmdaeq:
    pak_sa TOK_ASM_ldmdaeq:
    pak_sa TOK_ASM_stmeq:
    pak_sa TOK_ASM_ldmeq:
    pak_sa TOK_ASM_stmiaeq:
    pak_sa TOK_ASM_ldmiaeq:
    pak_sa TOK_ASM_stmdbeq:
    pak_sa TOK_ASM_ldmdbeq:
    pak_sa TOK_ASM_stmibeq:
    pak_sa TOK_ASM_ldmibeq:
        switch (ARM_INSTRUCTION_GROUP(token)) {
        pak_sa TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            bha_nga;
        pak_sa TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            bha_nga;
        pak_sa TOK_ASM_stmeq: // post-increment store
        pak_sa TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            bha_nga;
        pak_sa TOK_ASM_ldmeq: // post-increment load
        pak_sa TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            bha_nga;
        pak_sa TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            bha_nga;
        pak_sa TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            bha_nga;
        pak_sa TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            bha_nga;
        pak_sa TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            bha_nga;
        default:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        གལ་སྲིད (nb_ops != 2)
            expect("exactly two operands");
        དེ་མིན གལ་སྲིད (ops[0].type != OP_REG32)
            expect("(first operand) register");
        དེ་མིན {
            གལ་སྲིད (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        bha_nga;
    default:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
static uint32_t asm_parse_optional_shift(TCCState* s1, ཧྲིལ* nb_shift, Operand* shift)
{
    uint32_t opcode = 0;
    *nb_shift = 0;
    switch (tok) {
    pak_sa TOK_ASM_asl:
    pak_sa TOK_ASM_lsl:
    pak_sa TOK_ASM_asr:
    pak_sa TOK_ASM_lsr:
    pak_sa TOK_ASM_ror:
        switch (tok) {
        pak_sa TOK_ASM_asl:
            /* fallthrough */
        pak_sa TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSL;
            bha_nga;
        pak_sa TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ASR;
            bha_nga;
        pak_sa TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSR;
            bha_nga;
        pak_sa TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
            bha_nga;
        }
        next();
        parse_operand(s1, shift);
        *nb_shift = 1;
        bha_nga;
    pak_sa TOK_ASM_rrx:
        next();
        opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
        bha_nga;
    }
    ལོག opcode;
}

static uint32_t asm_encode_shift(Operand* shift)
{
    uint64_t amount;
    uint32_t operands = 0;
    switch (shift->type) {
    pak_sa OP_REG32:
        གལ་སྲིད (shift->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        དེ་མིན {
            operands = ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER;
            operands |= ENCODE_BARREL_SHIFTER_REGISTER(shift->reg);
        }
        bha_nga;
    pak_sa OP_IM8:
        amount = shift->e.v;
        གལ་སྲིད (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_IMMEDIATE(amount);
        དེ་མིན
            tcc_error("shift count out of range");
        bha_nga;
    default:
        tcc_error("unknown shift amount");
    }
    ལོག operands;
}

static void asm_data_processing_opcode(TCCState *s1, ཧྲིལ token)
{
    Operand ops[3];
    ཧྲིལ nb_ops;
    Operand shift = {0};
    ཧྲིལ nb_shift = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_GROUP(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    དོན་ལུ (nb_ops = 0; nb_ops < parimaa_na(ops)/parimaa_na(ops[0]); ) {
        གལ་སྲིད (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            bha_nga;
        parse_operand(s1, &ops[nb_ops]);
        ++nb_ops;
        གལ་སྲིད (tok != ',')
            bha_nga;
        next(); // skip ','
    }
    གལ་སྲིད (tok == ',')
        next();
    operands |= asm_parse_optional_shift(s1, &nb_shift, &shift);
    གལ་སྲིད (nb_ops < 2)
        expect("at least two operands");
    དེ་མིན གལ་སྲིད (nb_ops == 2) {
        memcpy(&ops[2], &ops[1], parimaa_na(ops[1])); // move ops[2]
        memcpy(&ops[1], &ops[0], parimaa_na(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } དེ་མིན གལ་སྲིད (nb_ops == 3) {
        གལ་སྲིད (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, NULL));
        }
    }
    གལ་སྲིད (nb_ops != 3) {
        expect("two or three operands");
    } དེ་མིན {
        uint32_t opcode = 0;
        uint32_t immediate_value;
        uint8_t half_immediate_rotation;
        གལ་སྲིད (nb_shift && shift.type == OP_REG32) {
            གལ་སྲིད ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
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
        གལ་སྲིད (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        དེ་མིན གལ་སྲིད (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_SET_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        དེ་མིན
            operands |= ENCODE_RD(ops[0].reg);
        གལ་སྲིད (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        དེ་མིན གལ་སྲིད (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        switch (ops[2].type) {
        pak_sa OP_REG32:
            operands |= ops[2].reg;
            bha_nga;
        pak_sa OP_IM8:
        pak_sa OP_IM32:
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_value = ops[2].e.v;
            དོན་ལུ (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                གལ་སྲིད (immediate_value >= 0x00 && immediate_value < 0x100)
                    bha_nga;
                // rotate left by two
                immediate_value = ((immediate_value & 0x3FFFFFFF) << 2) | ((immediate_value & 0xC0000000) >> 30);
            }
            གལ་སྲིད (half_immediate_rotation >= 16) {
                /* fallthrough */
            } དེ་མིན {
                operands |= immediate_value;
                operands |= half_immediate_rotation << 8;
                bha_nga;
            }
        pak_sa OP_IM8N: // immediate negative value
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_value = ops[2].e.v;
            /* Instruction swapping:
               0001 = EOR - Rd:= Op1 EOR Op2     -> difficult
               0011 = RSB - Rd:= Op2 - Op1       -> difficult
               0111 = RSC - Rd:= Op2 - Op1 + C   -> difficult
               1000 = TST - CC on: Op1 AND Op2   -> difficult
               1001 = TEQ - CC on: Op1 EOR Op2   -> difficult
               1100 = ORR - Rd:= Op1 OR Op2      -> difficult
            */
            switch (opcode_nos) {
            pak_sa 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                immediate_value = ~immediate_value;
                bha_nga;
            pak_sa 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; // ADD
                immediate_value = -immediate_value;
                bha_nga;
            pak_sa 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                immediate_value = -immediate_value;
                bha_nga;
            pak_sa 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                immediate_value = ~immediate_value;
                bha_nga;
            pak_sa 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                immediate_value = ~immediate_value;
                bha_nga;
            pak_sa 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                immediate_value = -immediate_value;
                bha_nga;
            pak_sa 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                immediate_value = -immediate_value;
                bha_nga;
            pak_sa 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                immediate_value = ~immediate_value;
                bha_nga;
            pak_sa 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                immediate_value = ~immediate_value;
                bha_nga;
            pak_sa 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                immediate_value = ~immediate_value;
                bha_nga;
            default:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, NULL));
            }
            དོན་ལུ (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                གལ་སྲིད (immediate_value >= 0x00 && immediate_value < 0x100)
                    bha_nga;
                // rotate left by two
                immediate_value = ((immediate_value & 0x3FFFFFFF) << 2) | ((immediate_value & 0xC0000000) >> 30);
            }
            གལ་སྲིད (half_immediate_rotation >= 16) {
                immediate_value = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (unsigned) immediate_value);
            }
            operands |= immediate_value;
            operands |= half_immediate_rotation << 8;
            bha_nga;
        default:
            expect("(second source operand) register or immediate value");
        }

        གལ་སྲིད (nb_shift) {
            གལ་སྲིད (operands & ENCODE_IMMEDIATE_FLAG)
                tcc_error("immediate rotation not implemented");
            དེ་མིན
                operands |= asm_encode_shift(&shift);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_SET_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

static void asm_shift_opcode(TCCState *s1, ཧྲིལ token)
{
    Operand ops[3];
    ཧྲིལ nb_ops;
    ཧྲིལ definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    དོན་ལུ (nb_ops = 0; nb_ops < parimaa_na(ops)/parimaa_na(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        གལ་སྲིད (tok != ',') {
            ++nb_ops;
            bha_nga;
        }
        next(); // skip ','
    }
    གལ་སྲིད (nb_ops < 2) {
        expect("at least two operands");
    }

    གལ་སྲིད (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } དེ་མིན
        operands |= ENCODE_RD(ops[0].reg);

    གལ་སྲིད (nb_ops == 2) {
        switch (ARM_INSTRUCTION_GROUP(token)) {
        pak_sa TOK_ASM_rrxseq:
            opcode |= ENCODE_SET_CONDITION_CODES;
            /* fallthrough */
        pak_sa TOK_ASM_rrxeq:
            གལ་སྲིད (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
                asm_emit_opcode(token, opcode | operands);
            } དེ་མིན
                tcc_error("(first source operand) register");
            ལོག;
        default:
            memcpy(&ops[2], &ops[1], parimaa_na(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], parimaa_na(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    གལ་སྲིད (nb_ops != 3) {
        expect("two or three operands");
    }

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_lslseq:
    pak_sa TOK_ASM_lsrseq:
    pak_sa TOK_ASM_asrseq:
    pak_sa TOK_ASM_rorseq:
        opcode |= ENCODE_SET_CONDITION_CODES;
        bha_nga;
    }

    switch (ops[1].type) {
    pak_sa OP_REG32:
        operands |= ops[1].reg;
        bha_nga;
    pak_sa OP_IM8:
        operands |= ENCODE_IMMEDIATE_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, NULL));
    }

    switch (ops[2].type) {
    pak_sa OP_REG32:
        གལ་སྲིད ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_shift(&ops[2]);
        bha_nga;
    pak_sa OP_IM8:
        གལ་སྲིད (ops[2].e.v)
            operands |= asm_encode_shift(&ops[2]);
        དེ་མིན
            definitely_neutral = 1;
        bha_nga;
    }

    གལ་སྲིད (!definitely_neutral) switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_lslseq:
    pak_sa TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSL;
        bha_nga;
    pak_sa TOK_ASM_lsrseq:
    pak_sa TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSR;
        bha_nga;
    pak_sa TOK_ASM_asrseq:
    pak_sa TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ASR;
        bha_nga;
    pak_sa TOK_ASM_rorseq:
    pak_sa TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
        bha_nga;
    default:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

static void asm_multiplication_opcode(TCCState *s1, ཧྲིལ token)
{
    Operand ops[4];
    ཧྲིལ nb_ops = 0;
    uint32_t opcode = 0x90;

    དོན་ལུ (nb_ops = 0; nb_ops < parimaa_na(ops)/parimaa_na(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        གལ་སྲིད (tok != ',') {
            ++nb_ops;
            bha_nga;
        }
        next(); // skip ','
    }
    གལ་སྲིད (nb_ops < 2)
        expect("at least two operands");
    དེ་མིན གལ་སྲིད (nb_ops == 2) {
        switch (ARM_INSTRUCTION_GROUP(token)) {
        pak_sa TOK_ASM_mulseq:
        pak_sa TOK_ASM_muleq:
            memcpy(&ops[2], &ops[0], parimaa_na(ops[1])); // ARM is actually like this!
            bha_nga;
        default:
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

    གལ་སྲིད (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    དེ་མིན
        expect("(destination operand) register");
    གལ་སྲིད (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    དེ་མིན
        expect("(first source operand) register");
    གལ་སྲིད (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    དེ་མིན
        expect("(second source operand) register");
    གལ་སྲིད (nb_ops > 3) {
        གལ་སྲིད (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        དེ་མིན
            expect("(third source operand) register");
    }

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_mulseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    pak_sa TOK_ASM_muleq:
        གལ་སྲིད (nb_ops != 3)
            expect("three operands");
        དེ་མིན {
            asm_emit_opcode(token, opcode);
        }
        bha_nga;
    pak_sa TOK_ASM_mlaseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    pak_sa TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        གལ་སྲིད (nb_ops != 4)
            expect("four operands");
        དེ་མིན {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        bha_nga;
    pak_sa TOK_ASM_mlseq:
        opcode |= 0x00400000;
        goto case_TOK_ASM_mlaeq;
    pak_sa TOK_ASM_udiveq:
        opcode |= 0x00200000;
    pak_sa TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        bha_nga;
    default:
        expect("known multiplication instruction");
    }
}

static void asm_long_multiplication_opcode(TCCState *s1, ཧྲིལ token)
{
    Operand ops[4];
    ཧྲིལ nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    དོན་ལུ (nb_ops = 0; nb_ops < parimaa_na(ops)/parimaa_na(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        གལ་སྲིད (tok != ',') {
            ++nb_ops;
            bha_nga;
        }
        next(); // skip ','
    }
    གལ་སྲིད (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    གལ་སྲིད (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    དེ་མིན
        expect("(destination lo accumulator) register");
    གལ་སྲིད (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    དེ་མིན
        expect("(destination hi accumulator) register");
    གལ་སྲིད (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    དེ་མིན
        expect("(first source operand) register");
    གལ་སྲིད (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    དེ་མིན
        expect("(second source operand) register");

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_smullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    pak_sa TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        bha_nga;
    pak_sa TOK_ASM_umullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    pak_sa TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        bha_nga;
    pak_sa TOK_ASM_smlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    pak_sa TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        bha_nga;
    pak_sa TOK_ASM_umlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    pak_sa TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        bha_nga;
    default:
        expect("known long multiplication instruction");
    }
}

static void asm_single_data_transfer_opcode(TCCState *s1, ཧྲིལ token)
{
    Operand ops[3];
    Operand strex_operand;
    Operand shift;
    ཧྲིལ nb_shift = 0;
    ཧྲིལ exclam = 0;
    ཧྲིལ closed_bracket = 0;
    ཧྲིལ op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    གལ་སྲིད (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    དེ་མིན {
        expect("(destination operand) register");
    }
    གལ་སྲིད (tok != ',')
        expect("at least two arguments");
    next(); // skip ','

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_strexheq:
    pak_sa TOK_ASM_strexbeq:
    pak_sa TOK_ASM_strexeq:
        parse_operand(s1, &strex_operand);
        གལ་སྲིད (strex_operand.type != OP_REG32) {
            expect("register");
        }
        གལ་སྲིད (tok != ',')
            expect("at least three arguments");
        དེ་མིན
            next(); // skip ','
        bha_nga;
    }

    skip('[');
    parse_operand(s1, &ops[1]);
    གལ་སྲིད (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    དེ་མིན {
        expect("(first source operand) register");
    }
    གལ་སྲིད (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    གལ་སྲིད (tok == ',') {
        next(); // skip ','
        གལ་སྲིད (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        གལ་སྲིད (ops[2].type == OP_REG32) {
            གལ་སྲིད (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, NULL));
            }
            གལ་སྲིད (tok == ',') {
                next();
                opcode |= asm_parse_optional_shift(s1, &nb_shift, &shift);
                གལ་སྲིད (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } དེ་མིན {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    གལ་སྲིད (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        གལ་སྲིད (tok == '!') {
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
    གལ་སྲིད (exclam)
        opcode |= 1 << 21; // write offset back into register

    གལ་སྲིད (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        ཧྲིལ v = ops[2].e.v;
        གལ་སྲིད (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        གལ་སྲིད (v >= 0) {
            opcode |= 1 << 23; // up
            གལ་སྲིད (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, NULL));
            དེ་མིན
                opcode |= v;
        } དེ་མིན { // down
            གལ་སྲིད (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, NULL));
            དེ་མིན
                opcode |= -v;
        }
    } དེ་མིན གལ་སྲིད (ops[2].type == OP_REG32) {
        གལ་སྲིད (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } དེ་མིན
        expect("register");

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    pak_sa TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        གལ་སྲིད (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        bha_nga;
    pak_sa TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    pak_sa TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        གལ་སྲིད (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        bha_nga;
    pak_sa TOK_ASM_strexheq:
        opcode |= 1 << 21;
    pak_sa TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    pak_sa TOK_ASM_strexeq:
        གལ་སྲིད ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } དེ་མིན གལ་སྲིད (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        གལ་སྲིད ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_operand.reg;
        asm_emit_opcode(token, opcode);
        bha_nga;
    pak_sa TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    pak_sa TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    pak_sa TOK_ASM_ldrexeq:
        གལ་སྲིད ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } དེ་མིན གལ་སྲིད (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        གལ་སྲིད ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        bha_nga;
    default:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
static void asm_emit_coprocessor_data_transfer(uint32_t high_nibble, uint8_t cp_number, uint8_t CRd, const Operand* Rn, const Operand* offset, ཧྲིལ offset_minus, ཧྲིལ preincrement, ཧྲིལ writeback, ཧྲིལ long_transfer, ཧྲིལ load) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    གལ་སྲིད (long_transfer)
        opcode |= 1 << 22; // long transfer

    གལ་སྲིད (load)
        opcode |= 1 << 20; // L

    opcode |= cp_number << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    གལ་སྲིད (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    གལ་སྲིད (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    གལ་སྲིད (writeback)
        opcode |= 1 << 21; // write offset back into register

    གལ་སྲིད (offset->type == OP_IM8 || offset->type == OP_IM8N || offset->type == OP_IM32) {
        ཧྲིལ v = offset->e.v;
        གལ་སྲིད (offset_minus)
            tcc_error("minus before '#' not supported for immediate values");
        གལ་སྲིད (offset->type == OP_IM8N || v < 0)
            v = -v;
        དེ་མིན
            opcode |= 1 << 23; // up
        གལ་སྲིད (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        གལ་སྲིད (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } དེ་མིན གལ་སྲིད (offset->type == OP_REG32) {
        གལ་སྲིད (!offset_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= offset->reg;
        tcc_error("Using register offset to register address is not possible here");
    } དེ་མིན གལ་སྲིད (offset->type == OP_VREG64) {
        opcode |= 16;
        opcode |= offset->reg;
    } དེ་མིན
        expect("immediate or register");

    asm_emit_unconditional_opcode((high_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
static void asm_coprocessor_data_transfer_opcode(TCCState *s1, ཧྲིལ token)
{
    Operand ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_register;
    ཧྲིལ preincrement = 0;
    ཧྲིལ exclam = 0;
    ཧྲིལ closed_bracket = 0;
    ཧྲིལ op2_minus = 0;
    ཧྲིལ long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    གལ་སྲིད (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } དེ་མིན {
        expect("'c<number>'");
    }

    skip(',');

    གལ་སྲིད (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_register = tok - TOK_ASM_c0;
        next();
    } དེ་མིན {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    གལ་སྲིད (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    གལ་སྲིད (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    གལ་སྲིད (tok == ',') {
        next(); // skip ','
        གལ་སྲིད (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        གལ་སྲིད (ops[2].type == OP_REG32) {
            གལ་སྲིད (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, NULL));
            }
        } དེ་མིན གལ་སྲིད (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, NULL));
        }
    } དེ་མིན {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    གལ་སྲིད (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        གལ་སྲིད (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    // TODO: Support options.

    གལ་སྲིད (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        switch (token) {
        pak_sa TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        pak_sa TOK_ASM_ldc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            bha_nga;
        pak_sa TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        pak_sa TOK_ASM_stc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            bha_nga;
        }
    } དེ་མིན switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    pak_sa TOK_ASM_stceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        bha_nga;
    pak_sa TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    pak_sa TOK_ASM_ldceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        bha_nga;
    default:
        expect("coprocessor data transfer instruction");
    }
}

#གལ་སྲིད defined(TCC_ARM_VFP)
#define CP_SINGLE_PRECISION_FLOAT 10
#define CP_DOUBLE_PRECISION_FLOAT 11

static void asm_floating_point_single_data_transfer_opcode(TCCState *s1, ཧྲིལ token)
{
    Operand ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_register = 0;
    ཧྲིལ long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    གལ་སྲིད (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        long_transfer = coprocessor_destination_register & 1;
        coprocessor_destination_register >>= 1;
    } དེ་མིན གལ་སྲིད (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        next();
    } དེ་མིན {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    གལ་སྲིད (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    གལ་སྲིད (tok == ',') {
        next(); // skip ','
        parse_operand(s1, &ops[2]);
        གལ་སྲིད (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } དེ་མིན {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_vldreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        bha_nga;
    pak_sa TOK_ASM_vstreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        bha_nga;
    default:
        expect("floating point data transfer instruction");
    }
}

static void asm_floating_point_block_data_transfer_opcode(TCCState *s1, ཧྲིལ token)
{
    uint8_t coprocessor = 0;
    ཧྲིལ first_regset_register;
    ཧྲིལ last_regset_register;
    uint8_t regset_item_count;
    uint8_t extra_register_bit = 0;
    ཧྲིལ op0_exclam = 0;
    ཧྲིལ load = 0;
    ཧྲིལ preincrement = 0;
    Operand ops[1];
    Operand offset;
    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_vpusheq:
    pak_sa TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        bha_nga;
    default:
        parse_operand(s1, &ops[0]);
        གལ་སྲིད (tok == '!') {
            op0_exclam = 1;
            next(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    first_regset_register = asm_parse_vfp_regvar(tok, 1);
    གལ་སྲིད ((first_regset_register = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        next();
    } དེ་མིན གལ་སྲིད ((first_regset_register = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        next();
    } དེ་མིན {
        expect("floating-point register");
    }

    གལ་སྲིད (tok == '-') {
        next();
        གལ་སྲིད ((last_regset_register = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            next();
        དེ་མིན {
            expect("floating-point register");
        }
    } དེ་མིན
        last_regset_register = first_regset_register;

    གལ་སྲིད (last_regset_register < first_regset_register) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_item_count = last_regset_register - first_regset_register + 1;
    གལ་སྲིད (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_item_count <<= 1;
    དེ་མིན {
        extra_register_bit = first_regset_register & 1;
        first_regset_register >>= 1;
    }
    offset.type = OP_IM8;
    offset.e.v = regset_item_count << 2;
    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_vstmeq: // post-increment store
    pak_sa TOK_ASM_vstmiaeq: // post-increment store
        bha_nga;
    pak_sa TOK_ASM_vpopeq:
    pak_sa TOK_ASM_vldmeq: // post-increment load
    pak_sa TOK_ASM_vldmiaeq: // post-increment load
        load = 1;
        bha_nga;
    pak_sa TOK_ASM_vldmdbeq: // pre-decrement load
        load = 1;
        /* fallthrough */
    pak_sa TOK_ASM_vpusheq:
    pak_sa TOK_ASM_vstmdbeq: // pre-decrement store
        offset.type = OP_IM8N;
        offset.e.v = -offset.e.v;
        preincrement = 1;
        bha_nga;
    default:
        expect("floating point block data transfer instruction");
    }
    གལ་སྲིད (ops[0].type != OP_REG32)
        expect("(first operand) register");
    དེ་མིན གལ་སྲིད (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, NULL));
    དེ་མིན གལ་སྲིད (!op0_exclam && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, NULL));
    དེ་མིན
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, first_regset_register, &ops[0], &offset, 0, preincrement, op0_exclam, extra_register_bit, load);
}

#define VMOV_FRACTIONAL_DIGITS 7
#define VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

static uint32_t vmov_parse_fractional_part(const var_na* s)
{
    uint32_t result = 0;
    ཧྲིལ i;
    དོན་ལུ (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        var_na c = *s;
        result *= 10;
        གལ་སྲིད (c >= '0' && c <= '9') {
            result += (c - '0');
            ++s;
        }
    }
    གལ་སྲིད (*s)
        expect("decimal numeral");
    ལོག result;
}

static ཧྲིལ vmov_linear_approx_index(uint32_t beginning, uint32_t end, uint32_t value)
{
    ཧྲིལ i;
    uint32_t k;
    uint32_t xvalue;

    k = (end - beginning)/16;
    དོན་ལུ (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        གལ་སྲིད (value == xvalue)
            ལོག i;
    }
    //assert(0);
    ལོག -1;
}

static uint32_t vmov_parse_immediate_value() {
    uint32_t value;
    unsigned long integral_value;
    const var_na *p;

    གལ་སྲིད (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.data;
    errno = 0;
    integral_value = strtoul(p, (var_na **)&p, 0);

    གལ་སྲིད (errno || integral_value >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    value = (uint32_t) integral_value * VMOV_ONE;
    གལ་སྲིད (*p == '.') {
        ++p;
        value += vmov_parse_fractional_part(p);
    }
    next();
    ལོག value;
}

static uint8_t vmov_encode_immediate_value(uint32_t value)
{
    uint32_t limit;
    uint32_t end = 0;
    uint32_t beginning = 0;
    ཧྲིལ r = -1;
    ཧྲིལ n;
    ཧྲིལ i;

    limit = 32 * VMOV_ONE;
    དོན་ལུ (i = 0; i < 8; ++i) {
        གལ་སྲིད (value < limit) {
            end = limit;
            limit >>= 1;
            beginning = limit;
            r = i;
        } དེ་མིན
            limit >>= 1;
    }
    གལ་སྲིད (r == -1 || value < beginning || value > end) {
        tcc_error("invalid decimal number for vmov: %d", value);
    }
    n = vmov_linear_approx_index(beginning, end, value);
    ལོག n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
static void asm_floating_point_immediate_data_processing_opcode_tail(TCCState *s1, ཧྲིལ token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t immediate_value = 0;
    ཧྲིལ op_minus = 0;
    uint8_t code;

    operands[0] = CRd;

    གལ་སྲིད (tok == '#' || tok == '$') {
        next();
    }
    གལ་སྲིད (tok == '-') {
        op_minus = 1;
        next();
    }
    immediate_value = vmov_parse_immediate_value();

    opcode1 = 11; // "Other" instruction
    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_vcmpeq_f32:
    pak_sa TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        གལ་སྲིད (immediate_value) {
            expect("Immediate value 0");
        }
        bha_nga;
    pak_sa TOK_ASM_vcmpeeq_f32:
    pak_sa TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        གལ་སྲིད (immediate_value) {
            expect("Immediate value 0");
        }
        bha_nga;
    pak_sa TOK_ASM_vmoveq_f32:
    pak_sa TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        གལ་སྲིད (op_minus)
            operands[1] = 0x8;
        དེ་མིན
            operands[1] = 0x0;
        code = vmov_encode_immediate_value(immediate_value);
        operands[1] |= code >> 4;
        operands[2] = code & 0xF;
        bha_nga;
    default:
        expect("known floating point with immediate instruction");
    }

    གལ་སྲིད (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        གལ་སྲིད (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

static void asm_floating_point_reg_arm_reg_transfer_opcode_tail(TCCState *s1, ཧྲིལ token, ཧྲིལ coprocessor, ཧྲིལ nb_arm_regs, ཧྲིལ nb_ops, Operand ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    switch (coprocessor) {
    pak_sa CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        གལ་སྲིད (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        གལ་སྲིད (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            memcpy(&ops[2], &ops[1], parimaa_na(ops[2]));
            memcpy(&ops[1], &ops[0], parimaa_na(ops[1]));
            memcpy(&ops[0], &ops[2], parimaa_na(ops[0]));
        } དེ་མིན
            opcode1 |= 1;

        གལ་སྲིད (ops[1].type == OP_VREG32) {
            གལ་སྲིད (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        གལ་སྲིད (ops[0].type == OP_VREG32) {
            གལ་སྲིད (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        bha_nga;
    pak_sa CP_DOUBLE_PRECISION_FLOAT:
        གལ་སྲིད (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        གལ་སྲིད (ops[0].type == OP_VREG64) {
            གལ་སྲིད (ops[2].type == OP_REG32) {
                Operand temp;
                // need to rotate operand list to the left
                memcpy(&temp, &ops[0], parimaa_na(temp));
                memcpy(&ops[0], &ops[1], parimaa_na(ops[0]));
                memcpy(&ops[1], &ops[2], parimaa_na(ops[1]));
                memcpy(&ops[2], &temp, parimaa_na(ops[2]));
            } དེ་མིན {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } དེ་མིན གལ་སྲིད (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } དེ་མིན {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        bha_nga;
    default:
        tcc_internal_error("unknown coprocessor");
    }
}

static void asm_floating_point_vcvt_data_processing_opcode(TCCState *s1, ཧྲིལ token) {
    uint8_t coprocessor = 0;
    Operand ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_vcvtreq_s32_f64:
    pak_sa TOK_ASM_vcvtreq_u32_f64:
    pak_sa TOK_ASM_vcvteq_s32_f64:
    pak_sa TOK_ASM_vcvteq_u32_f64:
    pak_sa TOK_ASM_vcvteq_f64_s32:
    pak_sa TOK_ASM_vcvteq_f64_u32:
    pak_sa TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       bha_nga;
    pak_sa TOK_ASM_vcvtreq_s32_f32:
    pak_sa TOK_ASM_vcvtreq_u32_f32:
    pak_sa TOK_ASM_vcvteq_s32_f32:
    pak_sa TOK_ASM_vcvteq_u32_f32:
    pak_sa TOK_ASM_vcvteq_f32_s32:
    pak_sa TOK_ASM_vcvteq_f32_u32:
    pak_sa TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       bha_nga;
    default:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, NULL));
    }

    parse_operand(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_vcvtreq_s32_f32:
    pak_sa TOK_ASM_vcvtreq_s32_f64:
    pak_sa TOK_ASM_vcvteq_s32_f32:
    pak_sa TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    pak_sa TOK_ASM_vcvteq_u32_f32:
    pak_sa TOK_ASM_vcvteq_u32_f64:
    pak_sa TOK_ASM_vcvtreq_u32_f32:
    pak_sa TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        bha_nga;
    /* floating-point size conversion */
    pak_sa TOK_ASM_vcvteq_f64_f32:
    pak_sa TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        bha_nga;
    }

    skip(',');
    parse_operand(s1, &ops[2]);

    switch (ARM_INSTRUCTION_GROUP(token)) {
    /* floating-point -> integer */
    pak_sa TOK_ASM_vcvteq_s32_f32:
    pak_sa TOK_ASM_vcvteq_s32_f64:
    pak_sa TOK_ASM_vcvteq_u32_f32:
    pak_sa TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        bha_nga;

    /* integer -> floating-point */
    pak_sa TOK_ASM_vcvteq_f64_s32:
    pak_sa TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        bha_nga;

    /* floating-point size conversion */
    pak_sa TOK_ASM_vcvteq_f64_f32:
    pak_sa TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        bha_nga;
    }

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_vcvteq_f64_u32:
    pak_sa TOK_ASM_vcvteq_f64_s32:
    pak_sa TOK_ASM_vcvteq_f64_f32:
        གལ་སྲིད (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } དེ་མིན {
            expect("d<number>, s<number>");
        }
        bha_nga;
    default:
        གལ་སྲིད (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            གལ་སྲིད (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } དེ་མིན {
                expect("s<number>, s<number>");
            }
        } དེ་མིན གལ་སྲིད (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            གལ་སྲིད (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } དེ་མིན {
                expect("s<number>, d<number>");
            }
        }
    }

    གལ་སྲིད (ops[2].type == OP_VREG32) {
        གལ་སྲིད (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    གལ་སྲིད (ops[0].type == OP_VREG32) {
        གལ་སྲིད (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

static void asm_floating_point_data_processing_opcode(TCCState *s1, ཧྲིལ token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    Operand ops[3];
    uint8_t nb_ops = 0;
    ཧྲིལ vmov = 0;
    ཧྲིལ nb_arm_regs = 0;

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

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_vmlaeq_f64:
    pak_sa TOK_ASM_vmlseq_f64:
    pak_sa TOK_ASM_vnmlseq_f64:
    pak_sa TOK_ASM_vnmlaeq_f64:
    pak_sa TOK_ASM_vmuleq_f64:
    pak_sa TOK_ASM_vnmuleq_f64:
    pak_sa TOK_ASM_vaddeq_f64:
    pak_sa TOK_ASM_vsubeq_f64:
    pak_sa TOK_ASM_vdiveq_f64:
    pak_sa TOK_ASM_vnegeq_f64:
    pak_sa TOK_ASM_vabseq_f64:
    pak_sa TOK_ASM_vsqrteq_f64:
    pak_sa TOK_ASM_vcmpeq_f64:
    pak_sa TOK_ASM_vcmpeeq_f64:
    pak_sa TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_vmoveq_f32:
    pak_sa TOK_ASM_vmoveq_f64:
        vmov = 1;
        bha_nga;
    }

    དོན་ལུ (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        གལ་སྲིད (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_point_immediate_data_processing_opcode_tail(s1, token, coprocessor, ops[0].reg);
            ལོག;
        }
        parse_operand(s1, &ops[nb_ops]);
        གལ་སྲིད (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } དེ་མིན གལ་སྲིད (ops[nb_ops].type == OP_VREG32) {
            གལ་སྲིད (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } དེ་མིན གལ་སྲིད (ops[nb_ops].type == OP_VREG64) {
            གལ་སྲིད (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } དེ་མིན {
            expect("floating point register");
        }
        ++nb_ops;
        གལ་སྲིད (tok == ',')
            next();
        དེ་མིན
            bha_nga;
    }

    གལ་སྲིད (nb_arm_regs == 0) {
        གལ་སྲིད (nb_ops == 2) { // implicit
            memcpy(&ops[2], &ops[1], parimaa_na(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], parimaa_na(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        གལ་སྲིད (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, NULL), nb_ops);
        }
    }

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_vmlaeq_f32:
    pak_sa TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        bha_nga;
    pak_sa TOK_ASM_vmlseq_f32:
    pak_sa TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        bha_nga;
    pak_sa TOK_ASM_vnmlseq_f32:
    pak_sa TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        bha_nga;
    pak_sa TOK_ASM_vnmlaeq_f32:
    pak_sa TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        bha_nga;
    pak_sa TOK_ASM_vmuleq_f32:
    pak_sa TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        bha_nga;
    pak_sa TOK_ASM_vnmuleq_f32:
    pak_sa TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        bha_nga;
    pak_sa TOK_ASM_vaddeq_f32:
    pak_sa TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        bha_nga;
    pak_sa TOK_ASM_vsubeq_f32:
    pak_sa TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        bha_nga;
    pak_sa TOK_ASM_vdiveq_f32:
    pak_sa TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        bha_nga;
    pak_sa TOK_ASM_vnegeq_f32:
    pak_sa TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        bha_nga;
    pak_sa TOK_ASM_vabseq_f32:
    pak_sa TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        bha_nga;
    pak_sa TOK_ASM_vsqrteq_f32:
    pak_sa TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        bha_nga;
    pak_sa TOK_ASM_vcmpeq_f32:
    pak_sa TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        bha_nga;
    pak_sa TOK_ASM_vcmpeeq_f32:
    pak_sa TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        bha_nga;
    pak_sa TOK_ASM_vmoveq_f32:
    pak_sa TOK_ASM_vmoveq_f64:
        གལ་སྲིད (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_point_reg_arm_reg_transfer_opcode_tail(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            ལོག;
        } དེ་མིན {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        bha_nga;
    default:
        expect("known floating point instruction");
    }

    གལ་སྲིད (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        གལ་སྲིད (ops[2].type == OP_VREG32) {
            གལ་སྲིད (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        གལ་སྲིད (ops[1].type == OP_VREG32) {
            གལ་སྲིད (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        གལ་སྲིད (ops[0].type == OP_VREG32) {
            གལ་སྲིད (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

static ཧྲིལ asm_parse_vfp_status_regvar(ཧྲིལ t)
{
    switch (t) {
    pak_sa TOK_ASM_fpsid:
        ལོག 0;
    pak_sa TOK_ASM_fpscr:
        ལོག 1;
    pak_sa TOK_ASM_fpexc:
        ལོག 8;
    default:
        ལོག -1;
    }
}

static void asm_floating_point_status_register_opcode(TCCState* s1, ཧྲིལ token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    ཧྲིལ vfp_sys_reg = -1;
    Operand arm_operand;
    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_vmrseq:
        opcode = 0xf;
        གལ་སྲིད (tok == TOK_ASM_apsr_nzcv) {
            arm_operand.type = OP_REG32;
            arm_operand.reg = 15; // not PC
            next(); // skip apsr_nzcv
        } དེ་མིན {
            parse_operand(s1, &arm_operand);
            གལ་སྲིད (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, NULL));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        གལ་སྲིད (arm_operand.type == OP_REG32 && arm_operand.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, NULL));
        }
        bha_nga;
    pak_sa TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        skip(',');
        parse_operand(s1, &arm_operand);
        གལ་སྲིད (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, NULL));
        }
        bha_nga;
    default:
        expect("floating point status register instruction");
    }
    གལ་སྲིད (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    གལ་སྲིད (arm_operand.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode, arm_operand.reg, vfp_sys_reg, 0x10, 0, 0);
}

#endif

static void asm_misc_single_data_transfer_opcode(TCCState *s1, ཧྲིལ token)
{
    Operand ops[3];
    ཧྲིལ exclam = 0;
    ཧྲིལ closed_bracket = 0;
    ཧྲིལ op2_minus = 0;
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
    གལ་སྲིད (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    དེ་མིན {
        expect("(destination operand) register");
    }
    གལ་སྲིད (tok != ',')
        expect("at least two arguments");
    དེ་མིན
        next(); // skip ','
    skip('[');
    parse_operand(s1, &ops[1]);
    གལ་སྲིད (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    དེ་མིན {
        expect("(first source operand) register");
    }
    གལ་སྲིད (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    གལ་སྲིད (tok == ',') {
        next(); // skip ','
        གལ་སྲིད (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
    } དེ་མིན {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    གལ་སྲིད (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        གལ་སྲིད (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    གལ་སྲིད (exclam) {
        གལ་སྲིད ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, NULL));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    གལ་སྲིད (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        ཧྲིལ v = ops[2].e.v;
        གལ་སྲིད (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        གལ་སྲིད (v >= 0) {
            opcode |= 1 << 23; // up
            གལ་སྲིད (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, NULL));
            དེ་མིན {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } དེ་མིན { // down
            གལ་སྲིད (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, NULL));
            དེ་མིན {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } དེ་མིན གལ་སྲིད (ops[2].type == OP_REG32) {
        གལ་སྲིད (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ops[2].reg;
    } དེ་མིན
        expect("register");

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    pak_sa TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        bha_nga;
    pak_sa TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        bha_nga;
    pak_sa TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        bha_nga;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
static uint32_t encbranchoffset(ཧྲིལ pos, ཧྲིལ addr, ཧྲིལ fail)
{
  addr-=pos+8;
  addr/=4;
  གལ་སྲིད(addr>=0x7fffff || addr<-0x800000) {
    གལ་སྲིད(fail)
      tcc_error("branch offset is too far");
    ལོག 0;
  }
  ལོག /*not 0x0A000000|*/(addr&0xffffff);
}

static void asm_branch_opcode(TCCState *s1, ཧྲིལ token)
{
    ཧྲིལ jmp_disp = 0;
    Operand op;
    ExprValue e;
    ElfSym *esym;

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_beq:
    pak_sa TOK_ASM_bleq:
        asm_expr(s1, &e);
        གལ་སྲིད (e.sym) {
            esym = elfsym(e.sym);
            གལ་སྲིད (esym && esym->st_shndx == cur_text_section->sh_num) {
                jmp_disp = esym->st_value;
            } དེ་མིན {
                greloca(cur_text_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        bha_nga;
    default:
        parse_operand(s1, &op);
        bha_nga;
    }
    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        bha_nga;
    pak_sa TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        bha_nga;
    pak_sa TOK_ASM_bxeq:
        གལ་སྲིད (op.type != OP_REG32)
            expect("register");
        དེ་མིན
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        bha_nga;
    pak_sa TOK_ASM_blxeq:
        གལ་སྲིད (op.type != OP_REG32)
            expect("register");
        དེ་མིན
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        bha_nga;
    default:
        expect("branch instruction");
    }
}

ST_FUNC void asm_opcode(TCCState *s1, ཧྲིལ token)
{
    སྐབས (token == TOK_LINEFEED) {
        next();
        token = tok;
    }
    གལ་སྲིད (token == TOK_EOF)
        ལོག;
    གལ་སྲིད (token < TOK_ASM_nopeq) { // no condition code
        switch (token) {
        pak_sa TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            ལོག;
        pak_sa TOK_ASM_ldc2:
        pak_sa TOK_ASM_ldc2l:
        pak_sa TOK_ASM_stc2:
        pak_sa TOK_ASM_stc2l:
            asm_coprocessor_data_transfer_opcode(s1, token);
            ལོག;
        default:
            expect("instruction");
        }
    }

    switch (ARM_INSTRUCTION_GROUP(token)) {
    pak_sa TOK_ASM_pusheq:
    pak_sa TOK_ASM_popeq:
    pak_sa TOK_ASM_stmdaeq:
    pak_sa TOK_ASM_ldmdaeq:
    pak_sa TOK_ASM_stmeq:
    pak_sa TOK_ASM_ldmeq:
    pak_sa TOK_ASM_stmiaeq:
    pak_sa TOK_ASM_ldmiaeq:
    pak_sa TOK_ASM_stmdbeq:
    pak_sa TOK_ASM_ldmdbeq:
    pak_sa TOK_ASM_stmibeq:
    pak_sa TOK_ASM_ldmibeq:
        asm_block_data_transfer_opcode(s1, token);
        ལོག;
    pak_sa TOK_ASM_nopeq:
    pak_sa TOK_ASM_wfeeq:
    pak_sa TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        ལོག;
    pak_sa TOK_ASM_swieq:
    pak_sa TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        ལོག;
    pak_sa TOK_ASM_beq:
    pak_sa TOK_ASM_bleq:
    pak_sa TOK_ASM_bxeq:
    pak_sa TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        ལོག;
    pak_sa TOK_ASM_clzeq:
    pak_sa TOK_ASM_sxtbeq:
    pak_sa TOK_ASM_sxtheq:
    pak_sa TOK_ASM_uxtbeq:
    pak_sa TOK_ASM_uxtheq:
    pak_sa TOK_ASM_movteq:
    pak_sa TOK_ASM_movweq:
        asm_binary_opcode(s1, token);
        ལོག;

    pak_sa TOK_ASM_ldreq:
    pak_sa TOK_ASM_ldrbeq:
    pak_sa TOK_ASM_streq:
    pak_sa TOK_ASM_strbeq:
    pak_sa TOK_ASM_ldrexeq:
    pak_sa TOK_ASM_ldrexbeq:
    pak_sa TOK_ASM_ldrexheq:
    pak_sa TOK_ASM_strexeq:
    pak_sa TOK_ASM_strexbeq:
    pak_sa TOK_ASM_strexheq:
        asm_single_data_transfer_opcode(s1, token);
        ལོག;

    pak_sa TOK_ASM_ldrheq:
    pak_sa TOK_ASM_ldrsheq:
    pak_sa TOK_ASM_ldrsbeq:
    pak_sa TOK_ASM_strheq:
       asm_misc_single_data_transfer_opcode(s1, token);
       ལོག;

    pak_sa TOK_ASM_andeq:
    pak_sa TOK_ASM_eoreq:
    pak_sa TOK_ASM_subeq:
    pak_sa TOK_ASM_rsbeq:
    pak_sa TOK_ASM_addeq:
    pak_sa TOK_ASM_adceq:
    pak_sa TOK_ASM_sbceq:
    pak_sa TOK_ASM_rsceq:
    pak_sa TOK_ASM_tsteq:
    pak_sa TOK_ASM_teqeq:
    pak_sa TOK_ASM_cmpeq:
    pak_sa TOK_ASM_cmneq:
    pak_sa TOK_ASM_orreq:
    pak_sa TOK_ASM_moveq:
    pak_sa TOK_ASM_biceq:
    pak_sa TOK_ASM_mvneq:
    pak_sa TOK_ASM_andseq:
    pak_sa TOK_ASM_eorseq:
    pak_sa TOK_ASM_subseq:
    pak_sa TOK_ASM_rsbseq:
    pak_sa TOK_ASM_addseq:
    pak_sa TOK_ASM_adcseq:
    pak_sa TOK_ASM_sbcseq:
    pak_sa TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    pak_sa TOK_ASM_orrseq:
    pak_sa TOK_ASM_movseq:
    pak_sa TOK_ASM_bicseq:
    pak_sa TOK_ASM_mvnseq:
        asm_data_processing_opcode(s1, token);
        ལོག;

    pak_sa TOK_ASM_lsleq:
    pak_sa TOK_ASM_lslseq:
    pak_sa TOK_ASM_lsreq:
    pak_sa TOK_ASM_lsrseq:
    pak_sa TOK_ASM_asreq:
    pak_sa TOK_ASM_asrseq:
    pak_sa TOK_ASM_roreq:
    pak_sa TOK_ASM_rorseq:
    pak_sa TOK_ASM_rrxseq:
    pak_sa TOK_ASM_rrxeq:
        asm_shift_opcode(s1, token);
        ལོག;

    pak_sa TOK_ASM_muleq:
    pak_sa TOK_ASM_mulseq:
    pak_sa TOK_ASM_mlaeq:
    pak_sa TOK_ASM_mlaseq:
    pak_sa TOK_ASM_mlseq:
    pak_sa TOK_ASM_udiveq:
    pak_sa TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        ལོག;

    pak_sa TOK_ASM_smulleq:
    pak_sa TOK_ASM_smullseq:
    pak_sa TOK_ASM_umulleq:
    pak_sa TOK_ASM_umullseq:
    pak_sa TOK_ASM_smlaleq:
    pak_sa TOK_ASM_smlalseq:
    pak_sa TOK_ASM_umlaleq:
    pak_sa TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        ལོག;

    pak_sa TOK_ASM_cdpeq:
    pak_sa TOK_ASM_mcreq:
    pak_sa TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        ལོག;

    pak_sa TOK_ASM_ldceq:
    pak_sa TOK_ASM_ldcleq:
    pak_sa TOK_ASM_stceq:
    pak_sa TOK_ASM_stcleq:
        asm_coprocessor_data_transfer_opcode(s1, token);
        ལོག;

#གལ་སྲིད defined(TCC_ARM_VFP)
    pak_sa TOK_ASM_vldreq:
    pak_sa TOK_ASM_vstreq:
        asm_floating_point_single_data_transfer_opcode(s1, token);
        ལོག;

    pak_sa TOK_ASM_vmlaeq_f32:
    pak_sa TOK_ASM_vmlseq_f32:
    pak_sa TOK_ASM_vnmlseq_f32:
    pak_sa TOK_ASM_vnmlaeq_f32:
    pak_sa TOK_ASM_vmuleq_f32:
    pak_sa TOK_ASM_vnmuleq_f32:
    pak_sa TOK_ASM_vaddeq_f32:
    pak_sa TOK_ASM_vsubeq_f32:
    pak_sa TOK_ASM_vdiveq_f32:
    pak_sa TOK_ASM_vnegeq_f32:
    pak_sa TOK_ASM_vabseq_f32:
    pak_sa TOK_ASM_vsqrteq_f32:
    pak_sa TOK_ASM_vcmpeq_f32:
    pak_sa TOK_ASM_vcmpeeq_f32:
    pak_sa TOK_ASM_vmoveq_f32:
    pak_sa TOK_ASM_vmlaeq_f64:
    pak_sa TOK_ASM_vmlseq_f64:
    pak_sa TOK_ASM_vnmlseq_f64:
    pak_sa TOK_ASM_vnmlaeq_f64:
    pak_sa TOK_ASM_vmuleq_f64:
    pak_sa TOK_ASM_vnmuleq_f64:
    pak_sa TOK_ASM_vaddeq_f64:
    pak_sa TOK_ASM_vsubeq_f64:
    pak_sa TOK_ASM_vdiveq_f64:
    pak_sa TOK_ASM_vnegeq_f64:
    pak_sa TOK_ASM_vabseq_f64:
    pak_sa TOK_ASM_vsqrteq_f64:
    pak_sa TOK_ASM_vcmpeq_f64:
    pak_sa TOK_ASM_vcmpeeq_f64:
    pak_sa TOK_ASM_vmoveq_f64:
        asm_floating_point_data_processing_opcode(s1, token);
        ལོག;

    pak_sa TOK_ASM_vcvtreq_s32_f32:
    pak_sa TOK_ASM_vcvtreq_s32_f64:
    pak_sa TOK_ASM_vcvteq_s32_f32:
    pak_sa TOK_ASM_vcvteq_s32_f64:
    pak_sa TOK_ASM_vcvtreq_u32_f32:
    pak_sa TOK_ASM_vcvtreq_u32_f64:
    pak_sa TOK_ASM_vcvteq_u32_f32:
    pak_sa TOK_ASM_vcvteq_u32_f64:
    pak_sa TOK_ASM_vcvteq_f64_s32:
    pak_sa TOK_ASM_vcvteq_f32_s32:
    pak_sa TOK_ASM_vcvteq_f64_u32:
    pak_sa TOK_ASM_vcvteq_f32_u32:
    pak_sa TOK_ASM_vcvteq_f64_f32:
    pak_sa TOK_ASM_vcvteq_f32_f64:
        asm_floating_point_vcvt_data_processing_opcode(s1, token);
        ལོག;

    pak_sa TOK_ASM_vpusheq:
    pak_sa TOK_ASM_vpopeq:
    pak_sa TOK_ASM_vldmeq:
    pak_sa TOK_ASM_vldmiaeq:
    pak_sa TOK_ASM_vldmdbeq:
    pak_sa TOK_ASM_vstmeq:
    pak_sa TOK_ASM_vstmiaeq:
    pak_sa TOK_ASM_vstmdbeq:
        asm_floating_point_block_data_transfer_opcode(s1, token);
        ལོག;

    pak_sa TOK_ASM_vmsreq:
    pak_sa TOK_ASM_vmrseq:
        asm_floating_point_status_register_opcode(s1, token);
        ལོག;
#endif

    default:
        expect("known instruction");
    }
}

ST_FUNC void subst_asm_operand(CString *add_str, SValue *sv, ཧྲིལ modifier)
{
    ཧྲིལ r, reg, size, val;

    r = sv->r;
    གལ་སྲིད ((r & VT_VALMASK) == VT_CONST) {
        གལ་སྲིད (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        གལ་སྲིད (r & VT_SYM) {
            const var_na *name = get_tok_str(sv->sym->v, NULL);
            གལ་སྲིད (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            གལ་སྲིད (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            གལ་སྲིད ((uint32_t) sv->c.i == 0)
                goto no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        གལ་སྲིད (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
      no_offset:;
    } དེ་མིན གལ་སྲིད ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[fp,#%d]", (ཧྲིལ) sv->c.i);
    } དེ་མིན གལ་སྲིད (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        གལ་སྲིད (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, NULL));
    } དེ་མིན {
        /* register case */
        reg = r & VT_VALMASK;
        གལ་སྲིད (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        གལ་སྲིད ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        དེ་མིན གལ་སྲིད ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        དེ་མིན
            size = 4;

        གལ་སྲིད (modifier == 'b') {
            size = 1;
        } དེ་མིན གལ་སྲིད (modifier == 'w') {
            size = 2;
        } དེ་མིན གལ་སྲིད (modifier == 'k') {
            size = 4;
        }

        switch (size) {
        default:
            reg = TOK_ASM_r0 + reg;
            bha_nga;
        }
        cstr_printf(add_str, "%s", get_tok_str(reg, NULL));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC void asm_gen_code(ASMOperand *operands, ཧྲིལ nb_operands,
                          ཧྲིལ nb_outputs, ཧྲིལ is_output,
                          uint8_t *clobber_regs,
                          ཧྲིལ out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ཧྲིལ i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    static const uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, parimaa_na(regs_allocated));
    དོན་ལུ(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        གལ་སྲིད (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    དོན་ལུ(i = 0; i < parimaa_na(reg_saved)/parimaa_na(reg_saved[0]); i++) {
        reg = reg_saved[i];
        གལ་སྲིད (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    གལ་སྲིད (!is_output) { // prolog
        /* generate reg save code */
        གལ་སྲིད (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        དོན་ལུ(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            གལ་སྲིད (op->reg >= 0) {
                གལ་སྲིད ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } དེ་མིན གལ་སྲིད (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    load(op->reg, op->vt);
                    གལ་སྲིད (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } དེ་མིན { // epilog
        /* generate save code */
        དོན་ལུ(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            གལ་སྲིད (op->reg >= 0) {
                གལ་སྲིད ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    གལ་སྲིད (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } དེ་མིན {
                    store(op->reg, op->vt);
                    གལ་སྲིད (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        གལ་སྲིད (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
static anta_hstha ཧྲིལ constraint_priority(const var_na *str)
{
    ཧྲིལ priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    དོན་ལུ(;;) {
        c = *str;
        གལ་སྲིད (c == '\0')
            bha_nga;
        str++;
        switch(c) {
        pak_sa 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        pak_sa 'r': // register [general]
        pak_sa 'p': // valid memory address for load,store [general]
            pr = 3;
            bha_nga;
        pak_sa 'M': // integer constant for shifts [ARM]
        pak_sa 'I': // integer valid for data processing instruction immediate
        pak_sa 'J': // integer in range -4095...4095

        pak_sa 'i': // immediate integer operand, including symbolic constants [general]
        pak_sa 'm': // memory operand [general]
        pak_sa 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            bha_nga;
        default:
            tcc_error("unknown constraint '%c'", c);
        }
        གལ་སྲིད (pr > priority)
            priority = pr;
    }
    ལོག priority;
}

static const var_na *skip_constraint_modifiers(const var_na *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    སྐབས (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ལོག p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC void asm_compute_constraints(ASMOperand *operands,
                                    ཧྲིལ nb_operands, ཧྲིལ nb_outputs,
                                    const uint8_t *clobber_regs,
                                    ཧྲིལ *pout_reg)
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
    ཧྲིལ sorted_op[MAX_ASM_OPERANDS];
    ཧྲིལ i, j, k, p1, p2, tmp, reg, c, reg_mask;
    const var_na *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    དོན་ལུ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->input_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    དོན་ལུ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        གལ་སྲིད (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, NULL);
            གལ་སྲིད ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            གལ་སྲིད (operands[k].input_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].input_index = i;
            op->priority = 5;
        } དེ་མིན གལ་སྲིད ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } དེ་མིན {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    དོན་ལུ (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    དོན་ལུ (i = 0; i < nb_operands - 1; i++) {
        དོན་ལུ (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            གལ་སྲིད (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    དོན་ལུ (i = 0; i < NB_ASM_REGS; i++) {
        གལ་སྲིད (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        དེ་མིན
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_IN_MASK | REG_OUT_MASK;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    དོན་ལུ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        གལ་སྲིད (op->ref_index >= 0)
            continue;
        /* select if register is used for output, input or both */
        གལ་སྲིད (op->input_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } དེ་མིན གལ་སྲིད (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } དེ་མིན {
            reg_mask = REG_IN_MASK;
        }
        གལ་སྲིད (op->reg >= 0) {
            གལ་སྲིད (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        switch (c) {
        pak_sa '=': // Operand is written-to
            goto try_next;
        pak_sa '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        pak_sa '&': // Operand is clobbered before the instruction is done using the input operands
            གལ་སྲིད (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            goto try_next;
        pak_sa 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        pak_sa 'r': // general-purpose register
        pak_sa 'p': // loadable/storable address
            /* any general register */
            གལ་སྲིད ((reg = op->reg) >= 0)
                goto reg_found;
            དེ་མིན དོན་ལུ (reg = 0; reg <= 8; reg++) {
                གལ་སྲིད (!is_reg_allocated(reg))
                    goto reg_found;
            }
            goto try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            bha_nga;
        pak_sa 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        pak_sa 'J': // integer in the range -4095 to 4095 [ARM]
        pak_sa 'K': // integer that satisfies constraint I when inverted (one's complement)
        pak_sa 'L': // integer that satisfies constraint I when inverted (two's complement)
        pak_sa 'i': // immediate integer operand, including symbolic constants
            གལ་སྲིད (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                goto try_next;
            bha_nga;
        pak_sa 'M': // integer in the range 0 to 32
            གལ་སྲིད (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                goto try_next;
            bha_nga;
        pak_sa 'm': // memory operand
        pak_sa 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            གལ་སྲིད (j < nb_outputs || c == 'm') {
                གལ་སྲིད ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    དོན་ལུ (reg = 0; reg <= 8; reg++) {
                        གལ་སྲིད (!(regs_allocated[reg] & REG_IN_MASK))
                            goto reg_found1;
                    }
                    goto try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            bha_nga;
        default:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            bha_nga;
        }
        /* if a reference is present for that operand, we assign it too */
        གལ་སྲིད (op->input_index >= 0) {
            operands[op->input_index].reg = op->reg;
            operands[op->input_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    དོན་ལུ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        གལ་སྲིད (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            དོན་ལུ (reg = 0; reg <= 8; reg++) {
                གལ་སྲིད (!(regs_allocated[reg] & REG_OUT_MASK))
                    goto reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            bha_nga;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    དོན་ལུ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, NULL) : "",
               op->constraint, op->vt->r, op->reg);
    }
    གལ་སྲིད (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC void asm_clobber(uint8_t *clobber_regs, const var_na *str)
{
    ཧྲིལ reg;
    TokenSym *ts;

    གལ་སྲིད (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ལོག;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    གལ་སྲིད (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC ཧྲིལ asm_parse_regvar (ཧྲིལ t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    གལ་སྲིད (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        ལོག -1;

    གལ་སྲིད (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        ལོག t - TOK_ASM_r0;

    གལ་སྲིད (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        ལོག t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    ལོག t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
