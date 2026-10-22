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

ST_FUNC فراغ g(صحيح c);
ST_FUNC فراغ gen_le16(صحيح c);
ST_FUNC فراغ gen_le32(صحيح c);

/*************************************************************/
#وإلا
/*************************************************************/

#define USING_GLOBALS
#ضمن "tcc.h"

تعداد {
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

تعريفنوع بنية Operand {
    uint32_t type;
    اتحاد {
        uint8_t reg;
        uint16_t regset;
        فرچ_درج e;
    };
} Operand;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
ساكن صحيح asm_parse_vfp_regvar(صحيح t, صحيح double_precision)
{
    إذا (double_precision) {
        إذا (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            أرجع t - TOK_ASM_d0;
    } وإلا {
        إذا (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            أرجع t - TOK_ASM_s0;
    }
    أرجع -1;
}

/* Parse a text containing operand and store the result in OP */
ساكن فراغ parse_operand(TCCState *s1, Operand *op)
{
    فرچ_درج e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    إذا (tok == '{') { // regset literal
        next(); // skip '{'
        طالما (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            إذا (reg == -1) {
                expect("register");
            } وإلا
                next(); // skip register name

            إذا ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            إذا (tok != ',')
                اكسر;
            next(); // skip ','
        }
        skip('}');
        إذا (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } وإلا {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        أرجع;
    } وإلا إذا ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        أرجع;
    } وإلا إذا ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        next(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        أرجع;
    } وإلا إذا ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        next(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        أرجع;
    } وإلا إذا (tok == '#' || tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    }
    asm_فرچ(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    إذا (!op->e.sym) {
        إذا ((صحيح) op->e.v < 0 && (صحيح) op->e.v >= -255)
            op->type = OP_IM8N;
        وإلا إذا (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } وإلا
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC فراغ g(صحيح c)
{
    صحيح ind1;
    إذا (nocode_wanted)
        أرجع;
    ind1 = ind + 1;
    إذا (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC فراغ gen_le16 (صحيح i)
{
    g(i);
    g(i>>8);
}

ST_FUNC فراغ gen_le32 (صحيح i)
{
    صحيح ind1;
    إذا (nocode_wanted)
        أرجع;
    ind1 = ind + 4;
    إذا (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC فراغ gen_expr32(فرچ_درج *pe)
{
    gen_le32(pe->v);
}

ساكن uint32_t condition_code_of_token(صحيح token) {
    إذا (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } وإلا
        أرجع (token - TOK_ASM_nopeq) & 15;
}

ساكن فراغ asm_emit_opcode(صحيح token, uint32_t opcode) {
    gen_le32((condition_code_of_token(token) << 28) | opcode);
}

ساكن فراغ asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

ساكن فراغ asm_emit_coprocessor_opcode(uint32_t سم_nibble, uint8_t cp_لمب, uint8_t cp_opcode, uint8_t cp_destination_register, uint8_t cp_n_operand_register, uint8_t cp_m_operand_register, uint8_t cp_opcode2, صحيح inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    إذا (inter_processor_transfer)
        opcode |= 1 << 4;
    //assert(cp_opcode < 16);
    opcode |= cp_opcode << 20;
    //assert(cp_n_operand_register < 16);
    opcode |= cp_n_operand_register << 16;
    //assert(cp_destination_register < 16);
    opcode |= cp_destination_register << 12;
    //assert(cp_number < 16);
    opcode |= cp_لمب << 8;
    //assert(cp_information < 8);
    opcode |= cp_opcode2 << 5;
    //assert(cp_m_operand_register < 16);
    opcode |= cp_m_operand_register;
    asm_emit_unconditional_opcode((سم_nibble << 28) | opcode);
}

ساكن فراغ asm_nullary_opcode(صحيح token)
{
    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        اكسر;
    حالة TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    حالة TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        اكسر;
    افتراضي:
        expect("nullary instruction");
    }
}

ساكن فراغ asm_unary_opcode(TCCState *s1, صحيح token)
{
    Operand op;
    parse_operand(s1, &op);

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_swieq:
    حالة TOK_ASM_svceq:
        إذا (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        وإلا {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        اكسر;
    افتراضي:
        expect("unary instruction");
    }
}

ساكن فراغ asm_نبيو_opcode(TCCState *s1, صحيح token)
{
    Operand ops[2];
    Operand rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);
    إذا (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    إذا (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, عدم));
    }

    إذا (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, عدم));

    إذا (ops[1].type != OP_REG32) {
        بدل (ARM_INSTRUCTION_GROUP(token)) {
        حالة TOK_ASM_movteq:
        حالة TOK_ASM_movweq:
            إذا (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                إذا (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t immediate_درج = ops[1].e.v;
                    بدل (ARM_INSTRUCTION_GROUP(token)) {
                    حالة TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (immediate_درج & 0xF000) << 4 | (immediate_درج & 0xFFF));
                        اكسر;
                    حالة TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (immediate_درج & 0xF000) << 4 | (immediate_درج & 0xFFF));
                        اكسر;
                    }
                } وإلا
                    expect("(source operand) immediate 16 bit value");
            } وإلا
                expect("(source operand) immediate");
            اكسر;
        افتراضي:
            expect("(source operand) register");
        }
        أرجع;
    }

    إذا (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, عدم));
    }

    إذا (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, عدم));

    إذا (tok == ',') {
        next(); // skip ','
        إذا (tok == TOK_ASM_ror) {
            next(); // skip 'ror'
            parse_operand(s1, &rotation);
            إذا (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } وإلا {
                amount = rotation.e.v;
                بدل (amount) {
                حالة 8:
                    encoded_rotation = 1 << 10;
                    اكسر;
                حالة 16:
                    encoded_rotation = 2 << 10;
                    اكسر;
                حالة 24:
                    encoded_rotation = 3 << 10;
                    اكسر;
                افتراضي:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_clzeq:
        إذا (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        اكسر;
    حالة TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        اكسر;
    حالة TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        اكسر;
    حالة TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        اكسر;
    حالة TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        اكسر;
    افتراضي:
        expect("binary instruction");
    }
}

ساكن فراغ asm_coprocessor_opcode(TCCState *s1, صحيح token) {
    uint8_t coprocessor;
    Operand opcode1;
    Operand opcode2;
    uint8_t registers[3];
    unsigned صحيح i;
    uint8_t سم_nibble;
    uint8_t mrc = 0;

    إذا (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } وإلا {
        expect("'p<number>'");
    }
    skip(',');
    parse_operand(s1, &opcode1);
    إذا (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, عدم));
    }

    لكل (i = 0; i < 3; ++i) {
        skip(',');
        إذا (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mcreq)) {
            إذا (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                next();
            } وإلا {
                expect("'r<number>'");
            }
        } وإلا {
            إذا (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                next();
            } وإلا {
                expect("'c<number>'");
            }
        }
    }
    إذا (tok == ',') {
        next();
        parse_operand(s1, &opcode2);
    } وإلا {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    إذا (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, عدم));
    }

    إذا (token == TOK_ASM_cdp2) {
        سم_nibble = 0xF;
        asm_emit_coprocessor_opcode(سم_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        أرجع;
    } وإلا
        سم_nibble = condition_code_of_token(token);

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(سم_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        اكسر;
    حالة TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    حالة TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        إذا (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, عدم));
        }
        asm_emit_coprocessor_opcode(سم_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        اكسر;
    افتراضي:
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
#define ENCODE_BARREL_SHIFTER_IMMEDIATE(درج) ((درج) << 7)

ساكن فراغ asm_block_data_transfer_opcode(TCCState *s1, صحيح token)
{
    uint32_t opcode;
    صحيح op0_exclam = 0;
    Operand ops[2];
    صحيح nb_ops = 1;
    parse_operand(s1, &ops[0]);
    إذا (tok == '!') {
        op0_exclam = 1;
        next(); // skip '!'
    }
    إذا (tok == ',') {
        next(); // skip comma
        parse_operand(s1, &ops[1]);
        ++nb_ops;
    }
    إذا (nb_ops < 1) {
        expect("at least one operand");
    } وإلا إذا (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        إذا (nb_ops != 1)
            expect("exactly one operand");
        وإلا
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        اكسر;
    حالة TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        إذا (nb_ops != 1)
            expect("exactly one operand");
        وإلا
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        اكسر;
    حالة TOK_ASM_stmdaeq:
    حالة TOK_ASM_ldmdaeq:
    حالة TOK_ASM_stmeq:
    حالة TOK_ASM_ldmeq:
    حالة TOK_ASM_stmiaeq:
    حالة TOK_ASM_ldmiaeq:
    حالة TOK_ASM_stmdbeq:
    حالة TOK_ASM_ldmdbeq:
    حالة TOK_ASM_stmibeq:
    حالة TOK_ASM_ldmibeq:
        بدل (ARM_INSTRUCTION_GROUP(token)) {
        حالة TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            اكسر;
        حالة TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            اكسر;
        حالة TOK_ASM_stmeq: // post-increment store
        حالة TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            اكسر;
        حالة TOK_ASM_ldmeq: // post-increment load
        حالة TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            اكسر;
        حالة TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            اكسر;
        حالة TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            اكسر;
        حالة TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            اكسر;
        حالة TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            اكسر;
        افتراضي:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        إذا (nb_ops != 2)
            expect("exactly two operands");
        وإلا إذا (ops[0].type != OP_REG32)
            expect("(first operand) register");
        وإلا {
            إذا (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        اكسر;
    افتراضي:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
ساكن uint32_t asm_parse_optional_shift(TCCState* s1, صحيح* nb_shift, Operand* shift)
{
    uint32_t opcode = 0;
    *nb_shift = 0;
    بدل (tok) {
    حالة TOK_ASM_asl:
    حالة TOK_ASM_lsl:
    حالة TOK_ASM_asr:
    حالة TOK_ASM_lsr:
    حالة TOK_ASM_ror:
        بدل (tok) {
        حالة TOK_ASM_asl:
            /* fallthrough */
        حالة TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSL;
            اكسر;
        حالة TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ASR;
            اكسر;
        حالة TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSR;
            اكسر;
        حالة TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
            اكسر;
        }
        next();
        parse_operand(s1, shift);
        *nb_shift = 1;
        اكسر;
    حالة TOK_ASM_rrx:
        next();
        opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
        اكسر;
    }
    أرجع opcode;
}

ساكن uint32_t asm_encode_shift(Operand* shift)
{
    uint64_t amount;
    uint32_t operands = 0;
    بدل (shift->type) {
    حالة OP_REG32:
        إذا (shift->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        وإلا {
            operands = ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER;
            operands |= ENCODE_BARREL_SHIFTER_REGISTER(shift->reg);
        }
        اكسر;
    حالة OP_IM8:
        amount = shift->e.v;
        إذا (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_IMMEDIATE(amount);
        وإلا
            tcc_error("shift count out of range");
        اكسر;
    افتراضي:
        tcc_error("unknown shift amount");
    }
    أرجع operands;
}

ساكن فراغ asm_data_processing_opcode(TCCState *s1, صحيح token)
{
    Operand ops[3];
    صحيح nb_ops;
    Operand shift = {0};
    صحيح nb_shift = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_GROUP(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    لكل (nb_ops = 0; nb_ops < حجم(ops)/حجم(ops[0]); ) {
        إذا (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            اكسر;
        parse_operand(s1, &ops[nb_ops]);
        ++nb_ops;
        إذا (tok != ',')
            اكسر;
        next(); // skip ','
    }
    إذا (tok == ',')
        next();
    operands |= asm_parse_optional_shift(s1, &nb_shift, &shift);
    إذا (nb_ops < 2)
        expect("at least two operands");
    وإلا إذا (nb_ops == 2) {
        memcpy(&ops[2], &ops[1], حجم(ops[1])); // move ops[2]
        memcpy(&ops[1], &ops[0], حجم(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } وإلا إذا (nb_ops == 3) {
        إذا (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, عدم));
        }
    }
    إذا (nb_ops != 3) {
        expect("two or three operands");
    } وإلا {
        uint32_t opcode = 0;
        uint32_t immediate_درج;
        uint8_t half_immediate_rotation;
        إذا (nb_shift && shift.type == OP_REG32) {
            إذا ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
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
        إذا (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        وإلا إذا (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_SET_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        وإلا
            operands |= ENCODE_RD(ops[0].reg);
        إذا (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        وإلا إذا (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        بدل (ops[2].type) {
        حالة OP_REG32:
            operands |= ops[2].reg;
            اكسر;
        حالة OP_IM8:
        حالة OP_IM32:
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_درج = ops[2].e.v;
            لكل (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                إذا (immediate_درج >= 0x00 && immediate_درج < 0x100)
                    اكسر;
                // rotate left by two
                immediate_درج = ((immediate_درج & 0x3FFFFFFF) << 2) | ((immediate_درج & 0xC0000000) >> 30);
            }
            إذا (half_immediate_rotation >= 16) {
                /* fallthrough */
            } وإلا {
                operands |= immediate_درج;
                operands |= half_immediate_rotation << 8;
                اكسر;
            }
        حالة OP_IM8N: // immediate negative value
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_درج = ops[2].e.v;
            /* Instruction swapping:
               0001 = EOR - Rd:= Op1 EOR Op2     -> difficult
               0011 = RSB - Rd:= Op2 - Op1       -> difficult
               0111 = RSC - Rd:= Op2 - Op1 + C   -> difficult
               1000 = TST - CC on: Op1 AND Op2   -> difficult
               1001 = TEQ - CC on: Op1 EOR Op2   -> difficult
               1100 = ORR - Rd:= Op1 OR Op2      -> difficult
            */
            بدل (opcode_nos) {
            حالة 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                immediate_درج = ~immediate_درج;
                اكسر;
            حالة 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; // ADD
                immediate_درج = -immediate_درج;
                اكسر;
            حالة 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                immediate_درج = -immediate_درج;
                اكسر;
            حالة 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                immediate_درج = ~immediate_درج;
                اكسر;
            حالة 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                immediate_درج = ~immediate_درج;
                اكسر;
            حالة 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                immediate_درج = -immediate_درج;
                اكسر;
            حالة 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                immediate_درج = -immediate_درج;
                اكسر;
            حالة 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                immediate_درج = ~immediate_درج;
                اكسر;
            حالة 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                immediate_درج = ~immediate_درج;
                اكسر;
            حالة 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                immediate_درج = ~immediate_درج;
                اكسر;
            افتراضي:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, عدم));
            }
            لكل (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                إذا (immediate_درج >= 0x00 && immediate_درج < 0x100)
                    اكسر;
                // rotate left by two
                immediate_درج = ((immediate_درج & 0x3FFFFFFF) << 2) | ((immediate_درج & 0xC0000000) >> 30);
            }
            إذا (half_immediate_rotation >= 16) {
                immediate_درج = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (unsigned) immediate_درج);
            }
            operands |= immediate_درج;
            operands |= half_immediate_rotation << 8;
            اكسر;
        افتراضي:
            expect("(second source operand) register or immediate value");
        }

        إذا (nb_shift) {
            إذا (operands & ENCODE_IMMEDIATE_FLAG)
                tcc_error("immediate rotation not implemented");
            وإلا
                operands |= asm_encode_shift(&shift);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_SET_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

ساكن فراغ asm_shift_opcode(TCCState *s1, صحيح token)
{
    Operand ops[3];
    صحيح nb_ops;
    صحيح definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    لكل (nb_ops = 0; nb_ops < حجم(ops)/حجم(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        إذا (tok != ',') {
            ++nb_ops;
            اكسر;
        }
        next(); // skip ','
    }
    إذا (nb_ops < 2) {
        expect("at least two operands");
    }

    إذا (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } وإلا
        operands |= ENCODE_RD(ops[0].reg);

    إذا (nb_ops == 2) {
        بدل (ARM_INSTRUCTION_GROUP(token)) {
        حالة TOK_ASM_rrxseq:
            opcode |= ENCODE_SET_CONDITION_CODES;
            /* fallthrough */
        حالة TOK_ASM_rrxeq:
            إذا (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
                asm_emit_opcode(token, opcode | operands);
            } وإلا
                tcc_error("(first source operand) register");
            أرجع;
        افتراضي:
            memcpy(&ops[2], &ops[1], حجم(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], حجم(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    إذا (nb_ops != 3) {
        expect("two or three operands");
    }

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_lslseq:
    حالة TOK_ASM_lsrseq:
    حالة TOK_ASM_asrseq:
    حالة TOK_ASM_rorseq:
        opcode |= ENCODE_SET_CONDITION_CODES;
        اكسر;
    }

    بدل (ops[1].type) {
    حالة OP_REG32:
        operands |= ops[1].reg;
        اكسر;
    حالة OP_IM8:
        operands |= ENCODE_IMMEDIATE_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, عدم));
    }

    بدل (ops[2].type) {
    حالة OP_REG32:
        إذا ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_shift(&ops[2]);
        اكسر;
    حالة OP_IM8:
        إذا (ops[2].e.v)
            operands |= asm_encode_shift(&ops[2]);
        وإلا
            definitely_neutral = 1;
        اكسر;
    }

    إذا (!definitely_neutral) بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_lslseq:
    حالة TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSL;
        اكسر;
    حالة TOK_ASM_lsrseq:
    حالة TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSR;
        اكسر;
    حالة TOK_ASM_asrseq:
    حالة TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ASR;
        اكسر;
    حالة TOK_ASM_rorseq:
    حالة TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
        اكسر;
    افتراضي:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

ساكن فراغ asm_multiplication_opcode(TCCState *s1, صحيح token)
{
    Operand ops[4];
    صحيح nb_ops = 0;
    uint32_t opcode = 0x90;

    لكل (nb_ops = 0; nb_ops < حجم(ops)/حجم(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        إذا (tok != ',') {
            ++nb_ops;
            اكسر;
        }
        next(); // skip ','
    }
    إذا (nb_ops < 2)
        expect("at least two operands");
    وإلا إذا (nb_ops == 2) {
        بدل (ARM_INSTRUCTION_GROUP(token)) {
        حالة TOK_ASM_mulseq:
        حالة TOK_ASM_muleq:
            memcpy(&ops[2], &ops[0], حجم(ops[1])); // ARM is actually like this!
            اكسر;
        افتراضي:
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

    إذا (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    وإلا
        expect("(destination operand) register");
    إذا (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    وإلا
        expect("(first source operand) register");
    إذا (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    وإلا
        expect("(second source operand) register");
    إذا (nb_ops > 3) {
        إذا (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        وإلا
            expect("(third source operand) register");
    }

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_mulseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    حالة TOK_ASM_muleq:
        إذا (nb_ops != 3)
            expect("three operands");
        وإلا {
            asm_emit_opcode(token, opcode);
        }
        اكسر;
    حالة TOK_ASM_mlaseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    حالة TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        إذا (nb_ops != 4)
            expect("four operands");
        وإلا {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        اكسر;
    حالة TOK_ASM_mlseq:
        opcode |= 0x00400000;
        اذهب case_TOK_ASM_mlaeq;
    حالة TOK_ASM_udiveq:
        opcode |= 0x00200000;
    حالة TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        اكسر;
    افتراضي:
        expect("known multiplication instruction");
    }
}

ساكن فراغ asm_long_multiplication_opcode(TCCState *s1, صحيح token)
{
    Operand ops[4];
    صحيح nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    لكل (nb_ops = 0; nb_ops < حجم(ops)/حجم(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        إذا (tok != ',') {
            ++nb_ops;
            اكسر;
        }
        next(); // skip ','
    }
    إذا (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    إذا (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    وإلا
        expect("(destination lo accumulator) register");
    إذا (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    وإلا
        expect("(destination hi accumulator) register");
    إذا (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    وإلا
        expect("(first source operand) register");
    إذا (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    وإلا
        expect("(second source operand) register");

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_smullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    حالة TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        اكسر;
    حالة TOK_ASM_umullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    حالة TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        اكسر;
    حالة TOK_ASM_smlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    حالة TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        اكسر;
    حالة TOK_ASM_umlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    حالة TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        اكسر;
    افتراضي:
        expect("known long multiplication instruction");
    }
}

ساكن فراغ asm_single_data_transfer_opcode(TCCState *s1, صحيح token)
{
    Operand ops[3];
    Operand strex_operand;
    Operand shift;
    صحيح nb_shift = 0;
    صحيح exclam = 0;
    صحيح closed_bracket = 0;
    صحيح op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    إذا (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    وإلا {
        expect("(destination operand) register");
    }
    إذا (tok != ',')
        expect("at least two arguments");
    next(); // skip ','

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_strexheq:
    حالة TOK_ASM_strexbeq:
    حالة TOK_ASM_strexeq:
        parse_operand(s1, &strex_operand);
        إذا (strex_operand.type != OP_REG32) {
            expect("register");
        }
        إذا (tok != ',')
            expect("at least three arguments");
        وإلا
            next(); // skip ','
        اكسر;
    }

    skip('[');
    parse_operand(s1, &ops[1]);
    إذا (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    وإلا {
        expect("(first source operand) register");
    }
    إذا (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    إذا (tok == ',') {
        next(); // skip ','
        إذا (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        إذا (ops[2].type == OP_REG32) {
            إذا (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, عدم));
            }
            إذا (tok == ',') {
                next();
                opcode |= asm_parse_optional_shift(s1, &nb_shift, &shift);
                إذا (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } وإلا {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    إذا (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        إذا (tok == '!') {
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
    إذا (exclam)
        opcode |= 1 << 21; // write offset back into register

    إذا (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        صحيح v = ops[2].e.v;
        إذا (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        إذا (v >= 0) {
            opcode |= 1 << 23; // up
            إذا (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, عدم));
            وإلا
                opcode |= v;
        } وإلا { // down
            إذا (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, عدم));
            وإلا
                opcode |= -v;
        }
    } وإلا إذا (ops[2].type == OP_REG32) {
        إذا (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } وإلا
        expect("register");

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    حالة TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        إذا (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        اكسر;
    حالة TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    حالة TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        إذا (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        اكسر;
    حالة TOK_ASM_strexheq:
        opcode |= 1 << 21;
    حالة TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    حالة TOK_ASM_strexeq:
        إذا ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } وإلا إذا (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        إذا ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_operand.reg;
        asm_emit_opcode(token, opcode);
        اكسر;
    حالة TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    حالة TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    حالة TOK_ASM_ldrexeq:
        إذا ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } وإلا إذا (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        إذا ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        اكسر;
    افتراضي:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
ساكن فراغ asm_emit_coprocessor_data_transfer(uint32_t سم_nibble, uint8_t cp_لمب, uint8_t CRd, ثابت Operand* Rn, ثابت Operand* offset, صحيح offset_minus, صحيح preincrement, صحيح writeback, صحيح long_transfer, صحيح load) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    إذا (long_transfer)
        opcode |= 1 << 22; // long transfer

    إذا (load)
        opcode |= 1 << 20; // L

    opcode |= cp_لمب << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    إذا (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    إذا (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    إذا (writeback)
        opcode |= 1 << 21; // write offset back into register

    إذا (offset->type == OP_IM8 || offset->type == OP_IM8N || offset->type == OP_IM32) {
        صحيح v = offset->e.v;
        إذا (offset_minus)
            tcc_error("minus before '#' not supported for immediate values");
        إذا (offset->type == OP_IM8N || v < 0)
            v = -v;
        وإلا
            opcode |= 1 << 23; // up
        إذا (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        إذا (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } وإلا إذا (offset->type == OP_REG32) {
        إذا (!offset_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= offset->reg;
        tcc_error("Using register offset to register address is not possible here");
    } وإلا إذا (offset->type == OP_VREG64) {
        opcode |= 16;
        opcode |= offset->reg;
    } وإلا
        expect("immediate or register");

    asm_emit_unconditional_opcode((سم_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
ساكن فراغ asm_coprocessor_data_transfer_opcode(TCCState *s1, صحيح token)
{
    Operand ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_register;
    صحيح preincrement = 0;
    صحيح exclam = 0;
    صحيح closed_bracket = 0;
    صحيح op2_minus = 0;
    صحيح long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    إذا (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } وإلا {
        expect("'c<number>'");
    }

    skip(',');

    إذا (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_register = tok - TOK_ASM_c0;
        next();
    } وإلا {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    إذا (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    إذا (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    إذا (tok == ',') {
        next(); // skip ','
        إذا (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        إذا (ops[2].type == OP_REG32) {
            إذا (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, عدم));
            }
        } وإلا إذا (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, عدم));
        }
    } وإلا {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    إذا (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        إذا (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    // TODO: Support options.

    إذا (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        بدل (token) {
        حالة TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        حالة TOK_ASM_ldc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            اكسر;
        حالة TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        حالة TOK_ASM_stc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            اكسر;
        }
    } وإلا بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    حالة TOK_ASM_stceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        اكسر;
    حالة TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    حالة TOK_ASM_ldceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        اكسر;
    افتراضي:
        expect("coprocessor data transfer instruction");
    }
}

#إذا defined(TCC_ARM_VFP)
#define CP_SINGLE_PRECISION_FLOAT 10
#define CP_DOUBLE_PRECISION_FLOAT 11

ساكن فراغ asm_floating_point_single_data_transfer_opcode(TCCState *s1, صحيح token)
{
    Operand ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_register = 0;
    صحيح long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    إذا (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        long_transfer = coprocessor_destination_register & 1;
        coprocessor_destination_register >>= 1;
    } وإلا إذا (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        next();
    } وإلا {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    إذا (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    إذا (tok == ',') {
        next(); // skip ','
        parse_operand(s1, &ops[2]);
        إذا (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } وإلا {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_vldreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        اكسر;
    حالة TOK_ASM_vstreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        اكسر;
    افتراضي:
        expect("floating point data transfer instruction");
    }
}

ساكن فراغ asm_floating_point_block_data_transfer_opcode(TCCState *s1, صحيح token)
{
    uint8_t coprocessor = 0;
    صحيح first_regset_register;
    صحيح last_regset_register;
    uint8_t regset_item_كدي;
    uint8_t extra_register_bit = 0;
    صحيح op0_exclam = 0;
    صحيح load = 0;
    صحيح preincrement = 0;
    Operand ops[1];
    Operand offset;
    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_vpusheq:
    حالة TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        اكسر;
    افتراضي:
        parse_operand(s1, &ops[0]);
        إذا (tok == '!') {
            op0_exclam = 1;
            next(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    first_regset_register = asm_parse_vfp_regvar(tok, 1);
    إذا ((first_regset_register = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        next();
    } وإلا إذا ((first_regset_register = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        next();
    } وإلا {
        expect("floating-point register");
    }

    إذا (tok == '-') {
        next();
        إذا ((last_regset_register = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            next();
        وإلا {
            expect("floating-point register");
        }
    } وإلا
        last_regset_register = first_regset_register;

    إذا (last_regset_register < first_regset_register) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_item_كدي = last_regset_register - first_regset_register + 1;
    إذا (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_item_كدي <<= 1;
    وإلا {
        extra_register_bit = first_regset_register & 1;
        first_regset_register >>= 1;
    }
    offset.type = OP_IM8;
    offset.e.v = regset_item_كدي << 2;
    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_vstmeq: // post-increment store
    حالة TOK_ASM_vstmiaeq: // post-increment store
        اكسر;
    حالة TOK_ASM_vpopeq:
    حالة TOK_ASM_vldmeq: // post-increment load
    حالة TOK_ASM_vldmiaeq: // post-increment load
        load = 1;
        اكسر;
    حالة TOK_ASM_vldmdbeq: // pre-decrement load
        load = 1;
        /* fallthrough */
    حالة TOK_ASM_vpusheq:
    حالة TOK_ASM_vstmdbeq: // pre-decrement store
        offset.type = OP_IM8N;
        offset.e.v = -offset.e.v;
        preincrement = 1;
        اكسر;
    افتراضي:
        expect("floating point block data transfer instruction");
    }
    إذا (ops[0].type != OP_REG32)
        expect("(first operand) register");
    وإلا إذا (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, عدم));
    وإلا إذا (!op0_exclam && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, عدم));
    وإلا
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, first_regset_register, &ops[0], &offset, 0, preincrement, op0_exclam, extra_register_bit, load);
}

#define VMOV_FRACTIONAL_DIGITS 7
#define VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

ساكن uint32_t vmov_parse_fractional_part(ثابت حرف* s)
{
    uint32_t result = 0;
    صحيح i;
    لكل (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        حرف c = *s;
        result *= 10;
        إذا (c >= '0' && c <= '9') {
            result += (c - '0');
            ++s;
        }
    }
    إذا (*s)
        expect("decimal numeral");
    أرجع result;
}

ساكن صحيح vmov_linear_approx_index(uint32_t beginning, uint32_t end, uint32_t درج)
{
    صحيح i;
    uint32_t k;
    uint32_t xvalue;

    k = (end - beginning)/16;
    لكل (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        إذا (درج == xvalue)
            أرجع i;
    }
    //assert(0);
    أرجع -1;
}

ساكن uint32_t vmov_parse_immediate_درج() {
    uint32_t درج;
    unsigned long integral_درج;
    ثابت حرف *p;

    إذا (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.data;
    errno = 0;
    integral_درج = strtoul(p, (حرف **)&p, 0);

    إذا (errno || integral_درج >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    درج = (uint32_t) integral_درج * VMOV_ONE;
    إذا (*p == '.') {
        ++p;
        درج += vmov_parse_fractional_part(p);
    }
    next();
    أرجع درج;
}

ساكن uint8_t vmov_encode_immediate_درج(uint32_t درج)
{
    uint32_t limit;
    uint32_t end = 0;
    uint32_t beginning = 0;
    صحيح r = -1;
    صحيح n;
    صحيح i;

    limit = 32 * VMOV_ONE;
    لكل (i = 0; i < 8; ++i) {
        إذا (درج < limit) {
            end = limit;
            limit >>= 1;
            beginning = limit;
            r = i;
        } وإلا
            limit >>= 1;
    }
    إذا (r == -1 || درج < beginning || درج > end) {
        tcc_error("invalid decimal number for vmov: %d", درج);
    }
    n = vmov_linear_approx_index(beginning, end, درج);
    أرجع n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
ساكن فراغ asm_floating_point_immediate_data_processing_opcode_tail(TCCState *s1, صحيح token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t immediate_درج = 0;
    صحيح op_minus = 0;
    uint8_t code;

    operands[0] = CRd;

    إذا (tok == '#' || tok == '$') {
        next();
    }
    إذا (tok == '-') {
        op_minus = 1;
        next();
    }
    immediate_درج = vmov_parse_immediate_درج();

    opcode1 = 11; // "Other" instruction
    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_vcmpeq_f32:
    حالة TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        إذا (immediate_درج) {
            expect("Immediate value 0");
        }
        اكسر;
    حالة TOK_ASM_vcmpeeq_f32:
    حالة TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        إذا (immediate_درج) {
            expect("Immediate value 0");
        }
        اكسر;
    حالة TOK_ASM_vmoveq_f32:
    حالة TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        إذا (op_minus)
            operands[1] = 0x8;
        وإلا
            operands[1] = 0x0;
        code = vmov_encode_immediate_درج(immediate_درج);
        operands[1] |= code >> 4;
        operands[2] = code & 0xF;
        اكسر;
    افتراضي:
        expect("known floating point with immediate instruction");
    }

    إذا (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        إذا (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

ساكن فراغ asm_floating_point_reg_arm_reg_transfer_opcode_tail(TCCState *s1, صحيح token, صحيح coprocessor, صحيح nb_arm_regs, صحيح nb_ops, Operand ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    بدل (coprocessor) {
    حالة CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        إذا (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        إذا (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            memcpy(&ops[2], &ops[1], حجم(ops[2]));
            memcpy(&ops[1], &ops[0], حجم(ops[1]));
            memcpy(&ops[0], &ops[2], حجم(ops[0]));
        } وإلا
            opcode1 |= 1;

        إذا (ops[1].type == OP_VREG32) {
            إذا (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        إذا (ops[0].type == OP_VREG32) {
            إذا (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        اكسر;
    حالة CP_DOUBLE_PRECISION_FLOAT:
        إذا (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        إذا (ops[0].type == OP_VREG64) {
            إذا (ops[2].type == OP_REG32) {
                Operand temp;
                // need to rotate operand list to the left
                memcpy(&temp, &ops[0], حجم(temp));
                memcpy(&ops[0], &ops[1], حجم(ops[0]));
                memcpy(&ops[1], &ops[2], حجم(ops[1]));
                memcpy(&ops[2], &temp, حجم(ops[2]));
            } وإلا {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } وإلا إذا (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } وإلا {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        اكسر;
    افتراضي:
        tcc_internal_error("unknown coprocessor");
    }
}

ساكن فراغ asm_floating_point_vcvt_data_processing_opcode(TCCState *s1, صحيح token) {
    uint8_t coprocessor = 0;
    Operand ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_vcvtreq_s32_f64:
    حالة TOK_ASM_vcvtreq_u32_f64:
    حالة TOK_ASM_vcvteq_s32_f64:
    حالة TOK_ASM_vcvteq_u32_f64:
    حالة TOK_ASM_vcvteq_f64_s32:
    حالة TOK_ASM_vcvteq_f64_u32:
    حالة TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       اكسر;
    حالة TOK_ASM_vcvtreq_s32_f32:
    حالة TOK_ASM_vcvtreq_u32_f32:
    حالة TOK_ASM_vcvteq_s32_f32:
    حالة TOK_ASM_vcvteq_u32_f32:
    حالة TOK_ASM_vcvteq_f32_s32:
    حالة TOK_ASM_vcvteq_f32_u32:
    حالة TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       اكسر;
    افتراضي:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, عدم));
    }

    parse_operand(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_vcvtreq_s32_f32:
    حالة TOK_ASM_vcvtreq_s32_f64:
    حالة TOK_ASM_vcvteq_s32_f32:
    حالة TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    حالة TOK_ASM_vcvteq_u32_f32:
    حالة TOK_ASM_vcvteq_u32_f64:
    حالة TOK_ASM_vcvtreq_u32_f32:
    حالة TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        اكسر;
    /* floating-point size conversion */
    حالة TOK_ASM_vcvteq_f64_f32:
    حالة TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        اكسر;
    }

    skip(',');
    parse_operand(s1, &ops[2]);

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    /* floating-point -> integer */
    حالة TOK_ASM_vcvteq_s32_f32:
    حالة TOK_ASM_vcvteq_s32_f64:
    حالة TOK_ASM_vcvteq_u32_f32:
    حالة TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        اكسر;

    /* integer -> floating-point */
    حالة TOK_ASM_vcvteq_f64_s32:
    حالة TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        اكسر;

    /* floating-point size conversion */
    حالة TOK_ASM_vcvteq_f64_f32:
    حالة TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        اكسر;
    }

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_vcvteq_f64_u32:
    حالة TOK_ASM_vcvteq_f64_s32:
    حالة TOK_ASM_vcvteq_f64_f32:
        إذا (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } وإلا {
            expect("d<number>, s<number>");
        }
        اكسر;
    افتراضي:
        إذا (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            إذا (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } وإلا {
                expect("s<number>, s<number>");
            }
        } وإلا إذا (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            إذا (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } وإلا {
                expect("s<number>, d<number>");
            }
        }
    }

    إذا (ops[2].type == OP_VREG32) {
        إذا (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    إذا (ops[0].type == OP_VREG32) {
        إذا (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

ساكن فراغ asm_floating_point_data_processing_opcode(TCCState *s1, صحيح token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    Operand ops[3];
    uint8_t nb_ops = 0;
    صحيح vmov = 0;
    صحيح nb_arm_regs = 0;

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

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_vmlaeq_f64:
    حالة TOK_ASM_vmlseq_f64:
    حالة TOK_ASM_vnmlseq_f64:
    حالة TOK_ASM_vnmlaeq_f64:
    حالة TOK_ASM_vmuleq_f64:
    حالة TOK_ASM_vnmuleq_f64:
    حالة TOK_ASM_vaddeq_f64:
    حالة TOK_ASM_vsubeq_f64:
    حالة TOK_ASM_vdiveq_f64:
    حالة TOK_ASM_vnegeq_f64:
    حالة TOK_ASM_vabseq_f64:
    حالة TOK_ASM_vsqrteq_f64:
    حالة TOK_ASM_vcmpeq_f64:
    حالة TOK_ASM_vcmpeeq_f64:
    حالة TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_vmoveq_f32:
    حالة TOK_ASM_vmoveq_f64:
        vmov = 1;
        اكسر;
    }

    لكل (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        إذا (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_point_immediate_data_processing_opcode_tail(s1, token, coprocessor, ops[0].reg);
            أرجع;
        }
        parse_operand(s1, &ops[nb_ops]);
        إذا (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } وإلا إذا (ops[nb_ops].type == OP_VREG32) {
            إذا (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } وإلا إذا (ops[nb_ops].type == OP_VREG64) {
            إذا (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } وإلا {
            expect("floating point register");
        }
        ++nb_ops;
        إذا (tok == ',')
            next();
        وإلا
            اكسر;
    }

    إذا (nb_arm_regs == 0) {
        إذا (nb_ops == 2) { // implicit
            memcpy(&ops[2], &ops[1], حجم(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], حجم(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        إذا (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, عدم), nb_ops);
        }
    }

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_vmlaeq_f32:
    حالة TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        اكسر;
    حالة TOK_ASM_vmlseq_f32:
    حالة TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        اكسر;
    حالة TOK_ASM_vnmlseq_f32:
    حالة TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        اكسر;
    حالة TOK_ASM_vnmlaeq_f32:
    حالة TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        اكسر;
    حالة TOK_ASM_vmuleq_f32:
    حالة TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        اكسر;
    حالة TOK_ASM_vnmuleq_f32:
    حالة TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        اكسر;
    حالة TOK_ASM_vaddeq_f32:
    حالة TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        اكسر;
    حالة TOK_ASM_vsubeq_f32:
    حالة TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        اكسر;
    حالة TOK_ASM_vdiveq_f32:
    حالة TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        اكسر;
    حالة TOK_ASM_vnegeq_f32:
    حالة TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        اكسر;
    حالة TOK_ASM_vabseq_f32:
    حالة TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        اكسر;
    حالة TOK_ASM_vsqrteq_f32:
    حالة TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        اكسر;
    حالة TOK_ASM_vcmpeq_f32:
    حالة TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        اكسر;
    حالة TOK_ASM_vcmpeeq_f32:
    حالة TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        اكسر;
    حالة TOK_ASM_vmoveq_f32:
    حالة TOK_ASM_vmoveq_f64:
        إذا (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_point_reg_arm_reg_transfer_opcode_tail(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            أرجع;
        } وإلا {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        اكسر;
    افتراضي:
        expect("known floating point instruction");
    }

    إذا (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        إذا (ops[2].type == OP_VREG32) {
            إذا (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        إذا (ops[1].type == OP_VREG32) {
            إذا (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        إذا (ops[0].type == OP_VREG32) {
            إذا (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

ساكن صحيح asm_parse_vfp_status_regvar(صحيح t)
{
    بدل (t) {
    حالة TOK_ASM_fpsid:
        أرجع 0;
    حالة TOK_ASM_fpscr:
        أرجع 1;
    حالة TOK_ASM_fpexc:
        أرجع 8;
    افتراضي:
        أرجع -1;
    }
}

ساكن فراغ asm_floating_point_status_register_opcode(TCCState* s1, صحيح token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    صحيح vfp_sys_reg = -1;
    Operand arm_operand;
    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_vmrseq:
        opcode = 0xf;
        إذا (tok == TOK_ASM_apsr_nzcv) {
            arm_operand.type = OP_REG32;
            arm_operand.reg = 15; // not PC
            next(); // skip apsr_nzcv
        } وإلا {
            parse_operand(s1, &arm_operand);
            إذا (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, عدم));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        إذا (arm_operand.type == OP_REG32 && arm_operand.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, عدم));
        }
        اكسر;
    حالة TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        skip(',');
        parse_operand(s1, &arm_operand);
        إذا (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, عدم));
        }
        اكسر;
    افتراضي:
        expect("floating point status register instruction");
    }
    إذا (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    إذا (arm_operand.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode, arm_operand.reg, vfp_sys_reg, 0x10, 0, 0);
}

#endif

ساكن فراغ asm_misc_single_data_transfer_opcode(TCCState *s1, صحيح token)
{
    Operand ops[3];
    صحيح exclam = 0;
    صحيح closed_bracket = 0;
    صحيح op2_minus = 0;
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
    إذا (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    وإلا {
        expect("(destination operand) register");
    }
    إذا (tok != ',')
        expect("at least two arguments");
    وإلا
        next(); // skip ','
    skip('[');
    parse_operand(s1, &ops[1]);
    إذا (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    وإلا {
        expect("(first source operand) register");
    }
    إذا (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    إذا (tok == ',') {
        next(); // skip ','
        إذا (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
    } وإلا {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    إذا (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        إذا (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    إذا (exclam) {
        إذا ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, عدم));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    إذا (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        صحيح v = ops[2].e.v;
        إذا (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        إذا (v >= 0) {
            opcode |= 1 << 23; // up
            إذا (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, عدم));
            وإلا {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } وإلا { // down
            إذا (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, عدم));
            وإلا {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } وإلا إذا (ops[2].type == OP_REG32) {
        إذا (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ops[2].reg;
    } وإلا
        expect("register");

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    حالة TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        اكسر;
    حالة TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        اكسر;
    حالة TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        اكسر;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
ساكن uint32_t encbranchoffset(صحيح pos, صحيح addr, صحيح fail)
{
  addr-=pos+8;
  addr/=4;
  إذا(addr>=0x7fffff || addr<-0x800000) {
    إذا(fail)
      tcc_error("branch offset is too far");
    أرجع 0;
  }
  أرجع /*not 0x0A000000|*/(addr&0xffffff);
}

ساكن فراغ asm_branch_opcode(TCCState *s1, صحيح token)
{
    صحيح jmp_disp = 0;
    Operand op;
    فرچ_درج e;
    ElfSym *esym;

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_beq:
    حالة TOK_ASM_bleq:
        asm_فرچ(s1, &e);
        إذا (e.sym) {
            esym = elfsym(e.sym);
            إذا (esym && esym->st_shndx == cur_text_section->sh_لمب) {
                jmp_disp = esym->st_درج;
            } وإلا {
                greloca(cur_text_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        اكسر;
    افتراضي:
        parse_operand(s1, &op);
        اكسر;
    }
    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        اكسر;
    حالة TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        اكسر;
    حالة TOK_ASM_bxeq:
        إذا (op.type != OP_REG32)
            expect("register");
        وإلا
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        اكسر;
    حالة TOK_ASM_blxeq:
        إذا (op.type != OP_REG32)
            expect("register");
        وإلا
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        اكسر;
    افتراضي:
        expect("branch instruction");
    }
}

ST_FUNC فراغ asm_opcode(TCCState *s1, صحيح token)
{
    طالما (token == TOK_LINEFEED) {
        next();
        token = tok;
    }
    إذا (token == TOK_EOF)
        أرجع;
    إذا (token < TOK_ASM_nopeq) { // no condition code
        بدل (token) {
        حالة TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            أرجع;
        حالة TOK_ASM_ldc2:
        حالة TOK_ASM_ldc2l:
        حالة TOK_ASM_stc2:
        حالة TOK_ASM_stc2l:
            asm_coprocessor_data_transfer_opcode(s1, token);
            أرجع;
        افتراضي:
            expect("instruction");
        }
    }

    بدل (ARM_INSTRUCTION_GROUP(token)) {
    حالة TOK_ASM_pusheq:
    حالة TOK_ASM_popeq:
    حالة TOK_ASM_stmdaeq:
    حالة TOK_ASM_ldmdaeq:
    حالة TOK_ASM_stmeq:
    حالة TOK_ASM_ldmeq:
    حالة TOK_ASM_stmiaeq:
    حالة TOK_ASM_ldmiaeq:
    حالة TOK_ASM_stmdbeq:
    حالة TOK_ASM_ldmdbeq:
    حالة TOK_ASM_stmibeq:
    حالة TOK_ASM_ldmibeq:
        asm_block_data_transfer_opcode(s1, token);
        أرجع;
    حالة TOK_ASM_nopeq:
    حالة TOK_ASM_wfeeq:
    حالة TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        أرجع;
    حالة TOK_ASM_swieq:
    حالة TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        أرجع;
    حالة TOK_ASM_beq:
    حالة TOK_ASM_bleq:
    حالة TOK_ASM_bxeq:
    حالة TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        أرجع;
    حالة TOK_ASM_clzeq:
    حالة TOK_ASM_sxtbeq:
    حالة TOK_ASM_sxtheq:
    حالة TOK_ASM_uxtbeq:
    حالة TOK_ASM_uxtheq:
    حالة TOK_ASM_movteq:
    حالة TOK_ASM_movweq:
        asm_نبيو_opcode(s1, token);
        أرجع;

    حالة TOK_ASM_ldreq:
    حالة TOK_ASM_ldrbeq:
    حالة TOK_ASM_streq:
    حالة TOK_ASM_strbeq:
    حالة TOK_ASM_ldrexeq:
    حالة TOK_ASM_ldrexbeq:
    حالة TOK_ASM_ldrexheq:
    حالة TOK_ASM_strexeq:
    حالة TOK_ASM_strexbeq:
    حالة TOK_ASM_strexheq:
        asm_single_data_transfer_opcode(s1, token);
        أرجع;

    حالة TOK_ASM_ldrheq:
    حالة TOK_ASM_ldrsheq:
    حالة TOK_ASM_ldrsbeq:
    حالة TOK_ASM_strheq:
       asm_misc_single_data_transfer_opcode(s1, token);
       أرجع;

    حالة TOK_ASM_andeq:
    حالة TOK_ASM_eoreq:
    حالة TOK_ASM_subeq:
    حالة TOK_ASM_rsbeq:
    حالة TOK_ASM_addeq:
    حالة TOK_ASM_adceq:
    حالة TOK_ASM_sbceq:
    حالة TOK_ASM_rsceq:
    حالة TOK_ASM_tsteq:
    حالة TOK_ASM_teqeq:
    حالة TOK_ASM_cmpeq:
    حالة TOK_ASM_cmneq:
    حالة TOK_ASM_orreq:
    حالة TOK_ASM_moveq:
    حالة TOK_ASM_biceq:
    حالة TOK_ASM_mvneq:
    حالة TOK_ASM_andseq:
    حالة TOK_ASM_eorseq:
    حالة TOK_ASM_subseq:
    حالة TOK_ASM_rsbseq:
    حالة TOK_ASM_addseq:
    حالة TOK_ASM_adcseq:
    حالة TOK_ASM_sbcseq:
    حالة TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    حالة TOK_ASM_orrseq:
    حالة TOK_ASM_movseq:
    حالة TOK_ASM_bicseq:
    حالة TOK_ASM_mvnseq:
        asm_data_processing_opcode(s1, token);
        أرجع;

    حالة TOK_ASM_lsleq:
    حالة TOK_ASM_lslseq:
    حالة TOK_ASM_lsreq:
    حالة TOK_ASM_lsrseq:
    حالة TOK_ASM_asreq:
    حالة TOK_ASM_asrseq:
    حالة TOK_ASM_roreq:
    حالة TOK_ASM_rorseq:
    حالة TOK_ASM_rrxseq:
    حالة TOK_ASM_rrxeq:
        asm_shift_opcode(s1, token);
        أرجع;

    حالة TOK_ASM_muleq:
    حالة TOK_ASM_mulseq:
    حالة TOK_ASM_mlaeq:
    حالة TOK_ASM_mlaseq:
    حالة TOK_ASM_mlseq:
    حالة TOK_ASM_udiveq:
    حالة TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        أرجع;

    حالة TOK_ASM_smulleq:
    حالة TOK_ASM_smullseq:
    حالة TOK_ASM_umulleq:
    حالة TOK_ASM_umullseq:
    حالة TOK_ASM_smlaleq:
    حالة TOK_ASM_smlalseq:
    حالة TOK_ASM_umlaleq:
    حالة TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        أرجع;

    حالة TOK_ASM_cdpeq:
    حالة TOK_ASM_mcreq:
    حالة TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        أرجع;

    حالة TOK_ASM_ldceq:
    حالة TOK_ASM_ldcleq:
    حالة TOK_ASM_stceq:
    حالة TOK_ASM_stcleq:
        asm_coprocessor_data_transfer_opcode(s1, token);
        أرجع;

#إذا defined(TCC_ARM_VFP)
    حالة TOK_ASM_vldreq:
    حالة TOK_ASM_vstreq:
        asm_floating_point_single_data_transfer_opcode(s1, token);
        أرجع;

    حالة TOK_ASM_vmlaeq_f32:
    حالة TOK_ASM_vmlseq_f32:
    حالة TOK_ASM_vnmlseq_f32:
    حالة TOK_ASM_vnmlaeq_f32:
    حالة TOK_ASM_vmuleq_f32:
    حالة TOK_ASM_vnmuleq_f32:
    حالة TOK_ASM_vaddeq_f32:
    حالة TOK_ASM_vsubeq_f32:
    حالة TOK_ASM_vdiveq_f32:
    حالة TOK_ASM_vnegeq_f32:
    حالة TOK_ASM_vabseq_f32:
    حالة TOK_ASM_vsqrteq_f32:
    حالة TOK_ASM_vcmpeq_f32:
    حالة TOK_ASM_vcmpeeq_f32:
    حالة TOK_ASM_vmoveq_f32:
    حالة TOK_ASM_vmlaeq_f64:
    حالة TOK_ASM_vmlseq_f64:
    حالة TOK_ASM_vnmlseq_f64:
    حالة TOK_ASM_vnmlaeq_f64:
    حالة TOK_ASM_vmuleq_f64:
    حالة TOK_ASM_vnmuleq_f64:
    حالة TOK_ASM_vaddeq_f64:
    حالة TOK_ASM_vsubeq_f64:
    حالة TOK_ASM_vdiveq_f64:
    حالة TOK_ASM_vnegeq_f64:
    حالة TOK_ASM_vabseq_f64:
    حالة TOK_ASM_vsqrteq_f64:
    حالة TOK_ASM_vcmpeq_f64:
    حالة TOK_ASM_vcmpeeq_f64:
    حالة TOK_ASM_vmoveq_f64:
        asm_floating_point_data_processing_opcode(s1, token);
        أرجع;

    حالة TOK_ASM_vcvtreq_s32_f32:
    حالة TOK_ASM_vcvtreq_s32_f64:
    حالة TOK_ASM_vcvteq_s32_f32:
    حالة TOK_ASM_vcvteq_s32_f64:
    حالة TOK_ASM_vcvtreq_u32_f32:
    حالة TOK_ASM_vcvtreq_u32_f64:
    حالة TOK_ASM_vcvteq_u32_f32:
    حالة TOK_ASM_vcvteq_u32_f64:
    حالة TOK_ASM_vcvteq_f64_s32:
    حالة TOK_ASM_vcvteq_f32_s32:
    حالة TOK_ASM_vcvteq_f64_u32:
    حالة TOK_ASM_vcvteq_f32_u32:
    حالة TOK_ASM_vcvteq_f64_f32:
    حالة TOK_ASM_vcvteq_f32_f64:
        asm_floating_point_vcvt_data_processing_opcode(s1, token);
        أرجع;

    حالة TOK_ASM_vpusheq:
    حالة TOK_ASM_vpopeq:
    حالة TOK_ASM_vldmeq:
    حالة TOK_ASM_vldmiaeq:
    حالة TOK_ASM_vldmdbeq:
    حالة TOK_ASM_vstmeq:
    حالة TOK_ASM_vstmiaeq:
    حالة TOK_ASM_vstmdbeq:
        asm_floating_point_block_data_transfer_opcode(s1, token);
        أرجع;

    حالة TOK_ASM_vmsreq:
    حالة TOK_ASM_vmrseq:
        asm_floating_point_status_register_opcode(s1, token);
        أرجع;
#endif

    افتراضي:
        expect("known instruction");
    }
}

ST_FUNC فراغ subst_asm_operand(CString *add_str, SValue *sv, صحيح modifier)
{
    صحيح r, reg, size, val;

    r = sv->r;
    إذا ((r & VT_VALMASK) == VT_CONST) {
        إذا (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        إذا (r & VT_SYM) {
            ثابت حرف *name = get_tok_str(sv->sym->v, عدم);
            إذا (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            إذا (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            إذا ((uint32_t) sv->c.i == 0)
                اذهب no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        إذا (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
      no_offset:;
    } وإلا إذا ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[fp,#%d]", (صحيح) sv->c.i);
    } وإلا إذا (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        إذا (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, عدم));
    } وإلا {
        /* register case */
        reg = r & VT_VALMASK;
        إذا (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        إذا ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        وإلا إذا ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        وإلا
            size = 4;

        إذا (modifier == 'b') {
            size = 1;
        } وإلا إذا (modifier == 'w') {
            size = 2;
        } وإلا إذا (modifier == 'k') {
            size = 4;
        }

        بدل (size) {
        افتراضي:
            reg = TOK_ASM_r0 + reg;
            اكسر;
        }
        cstr_printf(add_str, "%s", get_tok_str(reg, عدم));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC فراغ asm_gen_code(ASMOperand *operands, صحيح nb_operands,
                          صحيح nb_outputs, صحيح is_output,
                          uint8_t *clobber_regs,
                          صحيح out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    صحيح i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    ساكن ثابت uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, حجم(regs_allocated));
    لكل(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        إذا (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    لكل(i = 0; i < حجم(reg_saved)/حجم(reg_saved[0]); i++) {
        reg = reg_saved[i];
        إذا (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    إذا (!is_output) { // prolog
        /* generate reg save code */
        إذا (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        لكل(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            إذا (op->reg >= 0) {
                إذا ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } وإلا إذا (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    load(op->reg, op->vt);
                    إذا (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } وإلا { // epilog
        /* generate save code */
        لكل(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            إذا (op->reg >= 0) {
                إذا ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    إذا (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } وإلا {
                    store(op->reg, op->vt);
                    إذا (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        إذا (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
ساكن مضمن صحيح constraint_priority(ثابت حرف *str)
{
    صحيح priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    لكل(;;) {
        c = *str;
        إذا (c == '\0')
            اكسر;
        str++;
        بدل(c) {
        حالة 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        حالة 'r': // register [general]
        حالة 'p': // valid memory address for load,store [general]
            pr = 3;
            اكسر;
        حالة 'M': // integer constant for shifts [ARM]
        حالة 'I': // integer valid for data processing instruction immediate
        حالة 'J': // integer in range -4095...4095

        حالة 'i': // immediate integer operand, including symbolic constants [general]
        حالة 'm': // memory operand [general]
        حالة 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            اكسر;
        افتراضي:
            tcc_error("unknown constraint '%c'", c);
        }
        إذا (pr > priority)
            priority = pr;
    }
    أرجع priority;
}

ساكن ثابت حرف *skip_constraint_modifiers(ثابت حرف *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    طالما (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    أرجع p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC فراغ asm_compute_constraints(ASMOperand *operands,
                                    صحيح nb_operands, صحيح nb_outputs,
                                    ثابت uint8_t *clobber_regs,
                                    صحيح *pout_reg)
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
    صحيح sorted_op[MAX_ASM_OPERANDS];
    صحيح i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ثابت حرف *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    لكل (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->شغرو_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    لكل (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        إذا (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, عدم);
            إذا ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            إذا (operands[k].شغرو_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].شغرو_index = i;
            op->priority = 5;
        } وإلا إذا ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } وإلا {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    لكل (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    لكل (i = 0; i < nb_operands - 1; i++) {
        لكل (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            إذا (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    لكل (i = 0; i < NB_ASM_REGS; i++) {
        إذا (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        وإلا
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_IN_MASK | REG_OUT_MASK;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    لكل (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        إذا (op->ref_index >= 0)
            استمر;
        /* select if register is used for output, input or both */
        إذا (op->شغرو_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } وإلا إذا (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } وإلا {
            reg_mask = REG_IN_MASK;
        }
        إذا (op->reg >= 0) {
            إذا (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        بدل (c) {
        حالة '=': // Operand is written-to
            اذهب try_next;
        حالة '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        حالة '&': // Operand is clobbered before the instruction is done using the input operands
            إذا (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            اذهب try_next;
        حالة 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        حالة 'r': // general-purpose register
        حالة 'p': // loadable/storable address
            /* any general register */
            إذا ((reg = op->reg) >= 0)
                اذهب reg_found;
            وإلا لكل (reg = 0; reg <= 8; reg++) {
                إذا (!is_reg_allocated(reg))
                    اذهب reg_found;
            }
            اذهب try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            اكسر;
        حالة 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        حالة 'J': // integer in the range -4095 to 4095 [ARM]
        حالة 'K': // integer that satisfies constraint I when inverted (one's complement)
        حالة 'L': // integer that satisfies constraint I when inverted (two's complement)
        حالة 'i': // immediate integer operand, including symbolic constants
            إذا (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                اذهب try_next;
            اكسر;
        حالة 'M': // integer in the range 0 to 32
            إذا (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                اذهب try_next;
            اكسر;
        حالة 'm': // memory operand
        حالة 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            إذا (j < nb_outputs || c == 'm') {
                إذا ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    لكل (reg = 0; reg <= 8; reg++) {
                        إذا (!(regs_allocated[reg] & REG_IN_MASK))
                            اذهب reg_found1;
                    }
                    اذهب try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            اكسر;
        افتراضي:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            اكسر;
        }
        /* if a reference is present for that operand, we assign it too */
        إذا (op->شغرو_index >= 0) {
            operands[op->شغرو_index].reg = op->reg;
            operands[op->شغرو_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    لكل (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        إذا (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            لكل (reg = 0; reg <= 8; reg++) {
                إذا (!(regs_allocated[reg] & REG_OUT_MASK))
                    اذهب reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            اكسر;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    لكل (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, عدم) : "",
               op->constraint, op->vt->r, op->reg);
    }
    إذا (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC فراغ asm_clobber(uint8_t *clobber_regs, ثابت حرف *str)
{
    صحيح reg;
    TokenSym *ts;

    إذا (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        أرجع;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    إذا (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC صحيح asm_parse_regvar (صحيح t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    إذا (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        أرجع -1;

    إذا (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        أرجع t - TOK_ASM_r0;

    إذا (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        أرجع t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    أرجع t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
