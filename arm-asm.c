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

ST_FUNC تهی g(صحیح c);
ST_FUNC تهی gen_le16(صحیح c);
ST_FUNC تهی gen_le32(صحیح c);

/*************************************************************/
#وگرنه
/*************************************************************/

#define USING_GLOBALS
#شامل "tcc.h"

شمارش {
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

تعریفنوع ساختار Operand {
    uint32_t type;
    اجتماع {
        uint8_t reg;
        uint16_t regset;
        عبارت_مقدار e;
    };
} Operand;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
ایستا صحیح asm_parse_vfp_regvar(صحیح t, صحیح double_precision)
{
    اگر (double_precision) {
        اگر (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            بازگشت t - TOK_ASM_d0;
    } وگرنه {
        اگر (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            بازگشت t - TOK_ASM_s0;
    }
    بازگشت -1;
}

/* Parse a text containing operand and store the result in OP */
ایستا تهی parse_operand(TCCState *s1, Operand *op)
{
    عبارت_مقدار e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    اگر (tok == '{') { // regset literal
        next(); // skip '{'
        وقتی (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            اگر (reg == -1) {
                expect("register");
            } وگرنه
                next(); // skip register name

            اگر ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            اگر (tok != ',')
                بشکن;
            next(); // skip ','
        }
        skip('}');
        اگر (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } وگرنه {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        بازگشت;
    } وگرنه اگر ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        بازگشت;
    } وگرنه اگر ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        next(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        بازگشت;
    } وگرنه اگر ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        next(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        بازگشت;
    } وگرنه اگر (tok == '#' || tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    }
    asm_عبارت(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    اگر (!op->e.sym) {
        اگر ((صحیح) op->e.v < 0 && (صحیح) op->e.v >= -255)
            op->type = OP_IM8N;
        وگرنه اگر (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } وگرنه
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC تهی g(صحیح c)
{
    صحیح ind1;
    اگر (nocode_wanted)
        بازگشت;
    ind1 = ind + 1;
    اگر (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC تهی gen_le16 (صحیح i)
{
    g(i);
    g(i>>8);
}

ST_FUNC تهی gen_le32 (صحیح i)
{
    صحیح ind1;
    اگر (nocode_wanted)
        بازگشت;
    ind1 = ind + 4;
    اگر (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC تهی gen_expr32(عبارت_مقدار *pe)
{
    gen_le32(pe->v);
}

ایستا uint32_t condition_code_of_token(صحیح token) {
    اگر (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } وگرنه
        بازگشت (token - TOK_ASM_nopeq) & 15;
}

ایستا تهی asm_emit_opcode(صحیح token, uint32_t opcode) {
    gen_le32((condition_code_of_token(token) << 28) | opcode);
}

ایستا تهی asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

ایستا تهی asm_emit_coprocessor_opcode(uint32_t بالا_nibble, uint8_t cp_عدد, uint8_t cp_opcode, uint8_t cp_destination_register, uint8_t cp_n_operand_register, uint8_t cp_m_operand_register, uint8_t cp_opcode2, صحیح inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    اگر (inter_processor_transfer)
        opcode |= 1 << 4;
    //assert(cp_opcode < 16);
    opcode |= cp_opcode << 20;
    //assert(cp_n_operand_register < 16);
    opcode |= cp_n_operand_register << 16;
    //assert(cp_destination_register < 16);
    opcode |= cp_destination_register << 12;
    //assert(cp_number < 16);
    opcode |= cp_عدد << 8;
    //assert(cp_information < 8);
    opcode |= cp_opcode2 << 5;
    //assert(cp_m_operand_register < 16);
    opcode |= cp_m_operand_register;
    asm_emit_unconditional_opcode((بالا_nibble << 28) | opcode);
}

ایستا تهی asm_nullary_opcode(صحیح token)
{
    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        بشکن;
    حالت TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    حالت TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        بشکن;
    پیشفرض:
        expect("nullary instruction");
    }
}

ایستا تهی asm_unary_opcode(TCCState *s1, صحیح token)
{
    Operand op;
    parse_operand(s1, &op);

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_swieq:
    حالت TOK_ASM_svceq:
        اگر (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        وگرنه {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        بشکن;
    پیشفرض:
        expect("unary instruction");
    }
}

ایستا تهی asm_دودویی_opcode(TCCState *s1, صحیح token)
{
    Operand ops[2];
    Operand rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);
    اگر (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    اگر (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, پوچ));
    }

    اگر (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, پوچ));

    اگر (ops[1].type != OP_REG32) {
        انتخاب (ARM_INSTRUCTION_GROUP(token)) {
        حالت TOK_ASM_movteq:
        حالت TOK_ASM_movweq:
            اگر (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                اگر (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t immediate_مقدار = ops[1].e.v;
                    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
                    حالت TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (immediate_مقدار & 0xF000) << 4 | (immediate_مقدار & 0xFFF));
                        بشکن;
                    حالت TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (immediate_مقدار & 0xF000) << 4 | (immediate_مقدار & 0xFFF));
                        بشکن;
                    }
                } وگرنه
                    expect("(source operand) immediate 16 bit value");
            } وگرنه
                expect("(source operand) immediate");
            بشکن;
        پیشفرض:
            expect("(source operand) register");
        }
        بازگشت;
    }

    اگر (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, پوچ));
    }

    اگر (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, پوچ));

    اگر (tok == ',') {
        next(); // skip ','
        اگر (tok == TOK_ASM_ror) {
            next(); // skip 'ror'
            parse_operand(s1, &rotation);
            اگر (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } وگرنه {
                amount = rotation.e.v;
                انتخاب (amount) {
                حالت 8:
                    encoded_rotation = 1 << 10;
                    بشکن;
                حالت 16:
                    encoded_rotation = 2 << 10;
                    بشکن;
                حالت 24:
                    encoded_rotation = 3 << 10;
                    بشکن;
                پیشفرض:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_clzeq:
        اگر (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        بشکن;
    حالت TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        بشکن;
    حالت TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        بشکن;
    حالت TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        بشکن;
    حالت TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        بشکن;
    پیشفرض:
        expect("binary instruction");
    }
}

ایستا تهی asm_coprocessor_opcode(TCCState *s1, صحیح token) {
    uint8_t coprocessor;
    Operand opcode1;
    Operand opcode2;
    uint8_t registers[3];
    unsigned صحیح i;
    uint8_t بالا_nibble;
    uint8_t mrc = 0;

    اگر (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } وگرنه {
        expect("'p<number>'");
    }
    skip(',');
    parse_operand(s1, &opcode1);
    اگر (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, پوچ));
    }

    برای (i = 0; i < 3; ++i) {
        skip(',');
        اگر (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mcreq)) {
            اگر (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                next();
            } وگرنه {
                expect("'r<number>'");
            }
        } وگرنه {
            اگر (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                next();
            } وگرنه {
                expect("'c<number>'");
            }
        }
    }
    اگر (tok == ',') {
        next();
        parse_operand(s1, &opcode2);
    } وگرنه {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    اگر (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, پوچ));
    }

    اگر (token == TOK_ASM_cdp2) {
        بالا_nibble = 0xF;
        asm_emit_coprocessor_opcode(بالا_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        بازگشت;
    } وگرنه
        بالا_nibble = condition_code_of_token(token);

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(بالا_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        بشکن;
    حالت TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    حالت TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        اگر (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, پوچ));
        }
        asm_emit_coprocessor_opcode(بالا_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        بشکن;
    پیشفرض:
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
#define ENCODE_BARREL_SHIFTER_IMMEDIATE(مقدار) ((مقدار) << 7)

ایستا تهی asm_block_data_transfer_opcode(TCCState *s1, صحیح token)
{
    uint32_t opcode;
    صحیح op0_exclam = 0;
    Operand ops[2];
    صحیح nb_ops = 1;
    parse_operand(s1, &ops[0]);
    اگر (tok == '!') {
        op0_exclam = 1;
        next(); // skip '!'
    }
    اگر (tok == ',') {
        next(); // skip comma
        parse_operand(s1, &ops[1]);
        ++nb_ops;
    }
    اگر (nb_ops < 1) {
        expect("at least one operand");
    } وگرنه اگر (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        اگر (nb_ops != 1)
            expect("exactly one operand");
        وگرنه
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        بشکن;
    حالت TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        اگر (nb_ops != 1)
            expect("exactly one operand");
        وگرنه
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        بشکن;
    حالت TOK_ASM_stmdaeq:
    حالت TOK_ASM_ldmdaeq:
    حالت TOK_ASM_stmeq:
    حالت TOK_ASM_ldmeq:
    حالت TOK_ASM_stmiaeq:
    حالت TOK_ASM_ldmiaeq:
    حالت TOK_ASM_stmdbeq:
    حالت TOK_ASM_ldmdbeq:
    حالت TOK_ASM_stmibeq:
    حالت TOK_ASM_ldmibeq:
        انتخاب (ARM_INSTRUCTION_GROUP(token)) {
        حالت TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            بشکن;
        حالت TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            بشکن;
        حالت TOK_ASM_stmeq: // post-increment store
        حالت TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            بشکن;
        حالت TOK_ASM_ldmeq: // post-increment load
        حالت TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            بشکن;
        حالت TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            بشکن;
        حالت TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            بشکن;
        حالت TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            بشکن;
        حالت TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            بشکن;
        پیشفرض:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        اگر (nb_ops != 2)
            expect("exactly two operands");
        وگرنه اگر (ops[0].type != OP_REG32)
            expect("(first operand) register");
        وگرنه {
            اگر (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        بشکن;
    پیشفرض:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
ایستا uint32_t asm_parse_optional_shift(TCCState* s1, صحیح* nb_shift, Operand* shift)
{
    uint32_t opcode = 0;
    *nb_shift = 0;
    انتخاب (tok) {
    حالت TOK_ASM_asl:
    حالت TOK_ASM_lsl:
    حالت TOK_ASM_asr:
    حالت TOK_ASM_lsr:
    حالت TOK_ASM_ror:
        انتخاب (tok) {
        حالت TOK_ASM_asl:
            /* fallthrough */
        حالت TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSL;
            بشکن;
        حالت TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ASR;
            بشکن;
        حالت TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSR;
            بشکن;
        حالت TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
            بشکن;
        }
        next();
        parse_operand(s1, shift);
        *nb_shift = 1;
        بشکن;
    حالت TOK_ASM_rrx:
        next();
        opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
        بشکن;
    }
    بازگشت opcode;
}

ایستا uint32_t asm_encode_shift(Operand* shift)
{
    uint64_t amount;
    uint32_t operands = 0;
    انتخاب (shift->type) {
    حالت OP_REG32:
        اگر (shift->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        وگرنه {
            operands = ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER;
            operands |= ENCODE_BARREL_SHIFTER_REGISTER(shift->reg);
        }
        بشکن;
    حالت OP_IM8:
        amount = shift->e.v;
        اگر (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_IMMEDIATE(amount);
        وگرنه
            tcc_error("shift count out of range");
        بشکن;
    پیشفرض:
        tcc_error("unknown shift amount");
    }
    بازگشت operands;
}

ایستا تهی asm_data_processing_opcode(TCCState *s1, صحیح token)
{
    Operand ops[3];
    صحیح nb_ops;
    Operand shift = {0};
    صحیح nb_shift = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_GROUP(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    برای (nb_ops = 0; nb_ops < اندازه(ops)/اندازه(ops[0]); ) {
        اگر (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            بشکن;
        parse_operand(s1, &ops[nb_ops]);
        ++nb_ops;
        اگر (tok != ',')
            بشکن;
        next(); // skip ','
    }
    اگر (tok == ',')
        next();
    operands |= asm_parse_optional_shift(s1, &nb_shift, &shift);
    اگر (nb_ops < 2)
        expect("at least two operands");
    وگرنه اگر (nb_ops == 2) {
        memcpy(&ops[2], &ops[1], اندازه(ops[1])); // move ops[2]
        memcpy(&ops[1], &ops[0], اندازه(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } وگرنه اگر (nb_ops == 3) {
        اگر (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, پوچ));
        }
    }
    اگر (nb_ops != 3) {
        expect("two or three operands");
    } وگرنه {
        uint32_t opcode = 0;
        uint32_t immediate_مقدار;
        uint8_t half_immediate_rotation;
        اگر (nb_shift && shift.type == OP_REG32) {
            اگر ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
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
        اگر (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        وگرنه اگر (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_SET_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        وگرنه
            operands |= ENCODE_RD(ops[0].reg);
        اگر (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        وگرنه اگر (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        انتخاب (ops[2].type) {
        حالت OP_REG32:
            operands |= ops[2].reg;
            بشکن;
        حالت OP_IM8:
        حالت OP_IM32:
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_مقدار = ops[2].e.v;
            برای (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                اگر (immediate_مقدار >= 0x00 && immediate_مقدار < 0x100)
                    بشکن;
                // rotate left by two
                immediate_مقدار = ((immediate_مقدار & 0x3FFFFFFF) << 2) | ((immediate_مقدار & 0xC0000000) >> 30);
            }
            اگر (half_immediate_rotation >= 16) {
                /* fallthrough */
            } وگرنه {
                operands |= immediate_مقدار;
                operands |= half_immediate_rotation << 8;
                بشکن;
            }
        حالت OP_IM8N: // immediate negative value
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_مقدار = ops[2].e.v;
            /* Instruction swapping:
               0001 = EOR - Rd:= Op1 EOR Op2     -> difficult
               0011 = RSB - Rd:= Op2 - Op1       -> difficult
               0111 = RSC - Rd:= Op2 - Op1 + C   -> difficult
               1000 = TST - CC on: Op1 AND Op2   -> difficult
               1001 = TEQ - CC on: Op1 EOR Op2   -> difficult
               1100 = ORR - Rd:= Op1 OR Op2      -> difficult
            */
            انتخاب (opcode_nos) {
            حالت 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                immediate_مقدار = ~immediate_مقدار;
                بشکن;
            حالت 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; // ADD
                immediate_مقدار = -immediate_مقدار;
                بشکن;
            حالت 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                immediate_مقدار = -immediate_مقدار;
                بشکن;
            حالت 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                immediate_مقدار = ~immediate_مقدار;
                بشکن;
            حالت 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                immediate_مقدار = ~immediate_مقدار;
                بشکن;
            حالت 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                immediate_مقدار = -immediate_مقدار;
                بشکن;
            حالت 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                immediate_مقدار = -immediate_مقدار;
                بشکن;
            حالت 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                immediate_مقدار = ~immediate_مقدار;
                بشکن;
            حالت 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                immediate_مقدار = ~immediate_مقدار;
                بشکن;
            حالت 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                immediate_مقدار = ~immediate_مقدار;
                بشکن;
            پیشفرض:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, پوچ));
            }
            برای (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                اگر (immediate_مقدار >= 0x00 && immediate_مقدار < 0x100)
                    بشکن;
                // rotate left by two
                immediate_مقدار = ((immediate_مقدار & 0x3FFFFFFF) << 2) | ((immediate_مقدار & 0xC0000000) >> 30);
            }
            اگر (half_immediate_rotation >= 16) {
                immediate_مقدار = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (unsigned) immediate_مقدار);
            }
            operands |= immediate_مقدار;
            operands |= half_immediate_rotation << 8;
            بشکن;
        پیشفرض:
            expect("(second source operand) register or immediate value");
        }

        اگر (nb_shift) {
            اگر (operands & ENCODE_IMMEDIATE_FLAG)
                tcc_error("immediate rotation not implemented");
            وگرنه
                operands |= asm_encode_shift(&shift);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_SET_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

ایستا تهی asm_shift_opcode(TCCState *s1, صحیح token)
{
    Operand ops[3];
    صحیح nb_ops;
    صحیح definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    برای (nb_ops = 0; nb_ops < اندازه(ops)/اندازه(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        اگر (tok != ',') {
            ++nb_ops;
            بشکن;
        }
        next(); // skip ','
    }
    اگر (nb_ops < 2) {
        expect("at least two operands");
    }

    اگر (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } وگرنه
        operands |= ENCODE_RD(ops[0].reg);

    اگر (nb_ops == 2) {
        انتخاب (ARM_INSTRUCTION_GROUP(token)) {
        حالت TOK_ASM_rrxseq:
            opcode |= ENCODE_SET_CONDITION_CODES;
            /* fallthrough */
        حالت TOK_ASM_rrxeq:
            اگر (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
                asm_emit_opcode(token, opcode | operands);
            } وگرنه
                tcc_error("(first source operand) register");
            بازگشت;
        پیشفرض:
            memcpy(&ops[2], &ops[1], اندازه(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], اندازه(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    اگر (nb_ops != 3) {
        expect("two or three operands");
    }

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_lslseq:
    حالت TOK_ASM_lsrseq:
    حالت TOK_ASM_asrseq:
    حالت TOK_ASM_rorseq:
        opcode |= ENCODE_SET_CONDITION_CODES;
        بشکن;
    }

    انتخاب (ops[1].type) {
    حالت OP_REG32:
        operands |= ops[1].reg;
        بشکن;
    حالت OP_IM8:
        operands |= ENCODE_IMMEDIATE_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, پوچ));
    }

    انتخاب (ops[2].type) {
    حالت OP_REG32:
        اگر ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_shift(&ops[2]);
        بشکن;
    حالت OP_IM8:
        اگر (ops[2].e.v)
            operands |= asm_encode_shift(&ops[2]);
        وگرنه
            definitely_neutral = 1;
        بشکن;
    }

    اگر (!definitely_neutral) انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_lslseq:
    حالت TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSL;
        بشکن;
    حالت TOK_ASM_lsrseq:
    حالت TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSR;
        بشکن;
    حالت TOK_ASM_asrseq:
    حالت TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ASR;
        بشکن;
    حالت TOK_ASM_rorseq:
    حالت TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
        بشکن;
    پیشفرض:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

ایستا تهی asm_multiplication_opcode(TCCState *s1, صحیح token)
{
    Operand ops[4];
    صحیح nb_ops = 0;
    uint32_t opcode = 0x90;

    برای (nb_ops = 0; nb_ops < اندازه(ops)/اندازه(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        اگر (tok != ',') {
            ++nb_ops;
            بشکن;
        }
        next(); // skip ','
    }
    اگر (nb_ops < 2)
        expect("at least two operands");
    وگرنه اگر (nb_ops == 2) {
        انتخاب (ARM_INSTRUCTION_GROUP(token)) {
        حالت TOK_ASM_mulseq:
        حالت TOK_ASM_muleq:
            memcpy(&ops[2], &ops[0], اندازه(ops[1])); // ARM is actually like this!
            بشکن;
        پیشفرض:
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

    اگر (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    وگرنه
        expect("(destination operand) register");
    اگر (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    وگرنه
        expect("(first source operand) register");
    اگر (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    وگرنه
        expect("(second source operand) register");
    اگر (nb_ops > 3) {
        اگر (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        وگرنه
            expect("(third source operand) register");
    }

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_mulseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    حالت TOK_ASM_muleq:
        اگر (nb_ops != 3)
            expect("three operands");
        وگرنه {
            asm_emit_opcode(token, opcode);
        }
        بشکن;
    حالت TOK_ASM_mlaseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    حالت TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        اگر (nb_ops != 4)
            expect("four operands");
        وگرنه {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        بشکن;
    حالت TOK_ASM_mlseq:
        opcode |= 0x00400000;
        برو case_TOK_ASM_mlaeq;
    حالت TOK_ASM_udiveq:
        opcode |= 0x00200000;
    حالت TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        بشکن;
    پیشفرض:
        expect("known multiplication instruction");
    }
}

ایستا تهی asm_long_multiplication_opcode(TCCState *s1, صحیح token)
{
    Operand ops[4];
    صحیح nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    برای (nb_ops = 0; nb_ops < اندازه(ops)/اندازه(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        اگر (tok != ',') {
            ++nb_ops;
            بشکن;
        }
        next(); // skip ','
    }
    اگر (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    اگر (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    وگرنه
        expect("(destination lo accumulator) register");
    اگر (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    وگرنه
        expect("(destination hi accumulator) register");
    اگر (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    وگرنه
        expect("(first source operand) register");
    اگر (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    وگرنه
        expect("(second source operand) register");

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_smullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    حالت TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        بشکن;
    حالت TOK_ASM_umullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    حالت TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        بشکن;
    حالت TOK_ASM_smlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    حالت TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        بشکن;
    حالت TOK_ASM_umlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    حالت TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        بشکن;
    پیشفرض:
        expect("known long multiplication instruction");
    }
}

ایستا تهی asm_single_data_transfer_opcode(TCCState *s1, صحیح token)
{
    Operand ops[3];
    Operand strex_operand;
    Operand shift;
    صحیح nb_shift = 0;
    صحیح exclam = 0;
    صحیح closed_bracket = 0;
    صحیح op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    اگر (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    وگرنه {
        expect("(destination operand) register");
    }
    اگر (tok != ',')
        expect("at least two arguments");
    next(); // skip ','

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_strexheq:
    حالت TOK_ASM_strexbeq:
    حالت TOK_ASM_strexeq:
        parse_operand(s1, &strex_operand);
        اگر (strex_operand.type != OP_REG32) {
            expect("register");
        }
        اگر (tok != ',')
            expect("at least three arguments");
        وگرنه
            next(); // skip ','
        بشکن;
    }

    skip('[');
    parse_operand(s1, &ops[1]);
    اگر (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    وگرنه {
        expect("(first source operand) register");
    }
    اگر (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    اگر (tok == ',') {
        next(); // skip ','
        اگر (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        اگر (ops[2].type == OP_REG32) {
            اگر (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, پوچ));
            }
            اگر (tok == ',') {
                next();
                opcode |= asm_parse_optional_shift(s1, &nb_shift, &shift);
                اگر (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } وگرنه {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    اگر (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        اگر (tok == '!') {
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
    اگر (exclam)
        opcode |= 1 << 21; // write offset back into register

    اگر (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        صحیح v = ops[2].e.v;
        اگر (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        اگر (v >= 0) {
            opcode |= 1 << 23; // up
            اگر (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, پوچ));
            وگرنه
                opcode |= v;
        } وگرنه { // down
            اگر (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, پوچ));
            وگرنه
                opcode |= -v;
        }
    } وگرنه اگر (ops[2].type == OP_REG32) {
        اگر (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } وگرنه
        expect("register");

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    حالت TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        اگر (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        بشکن;
    حالت TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    حالت TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        اگر (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        بشکن;
    حالت TOK_ASM_strexheq:
        opcode |= 1 << 21;
    حالت TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    حالت TOK_ASM_strexeq:
        اگر ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } وگرنه اگر (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        اگر ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_operand.reg;
        asm_emit_opcode(token, opcode);
        بشکن;
    حالت TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    حالت TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    حالت TOK_ASM_ldrexeq:
        اگر ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } وگرنه اگر (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        اگر ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        بشکن;
    پیشفرض:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
ایستا تهی asm_emit_coprocessor_data_transfer(uint32_t بالا_nibble, uint8_t cp_عدد, uint8_t CRd, ثابت Operand* Rn, ثابت Operand* offset, صحیح offset_minus, صحیح preincrement, صحیح writeback, صحیح long_transfer, صحیح load) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    اگر (long_transfer)
        opcode |= 1 << 22; // long transfer

    اگر (load)
        opcode |= 1 << 20; // L

    opcode |= cp_عدد << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    اگر (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    اگر (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    اگر (writeback)
        opcode |= 1 << 21; // write offset back into register

    اگر (offset->type == OP_IM8 || offset->type == OP_IM8N || offset->type == OP_IM32) {
        صحیح v = offset->e.v;
        اگر (offset_minus)
            tcc_error("minus before '#' not supported for immediate values");
        اگر (offset->type == OP_IM8N || v < 0)
            v = -v;
        وگرنه
            opcode |= 1 << 23; // up
        اگر (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        اگر (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } وگرنه اگر (offset->type == OP_REG32) {
        اگر (!offset_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= offset->reg;
        tcc_error("Using register offset to register address is not possible here");
    } وگرنه اگر (offset->type == OP_VREG64) {
        opcode |= 16;
        opcode |= offset->reg;
    } وگرنه
        expect("immediate or register");

    asm_emit_unconditional_opcode((بالا_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
ایستا تهی asm_coprocessor_data_transfer_opcode(TCCState *s1, صحیح token)
{
    Operand ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_register;
    صحیح preincrement = 0;
    صحیح exclam = 0;
    صحیح closed_bracket = 0;
    صحیح op2_minus = 0;
    صحیح long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    اگر (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } وگرنه {
        expect("'c<number>'");
    }

    skip(',');

    اگر (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_register = tok - TOK_ASM_c0;
        next();
    } وگرنه {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    اگر (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    اگر (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    اگر (tok == ',') {
        next(); // skip ','
        اگر (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        اگر (ops[2].type == OP_REG32) {
            اگر (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, پوچ));
            }
        } وگرنه اگر (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, پوچ));
        }
    } وگرنه {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    اگر (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        اگر (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    // TODO: Support options.

    اگر (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        انتخاب (token) {
        حالت TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        حالت TOK_ASM_ldc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            بشکن;
        حالت TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        حالت TOK_ASM_stc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            بشکن;
        }
    } وگرنه انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    حالت TOK_ASM_stceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        بشکن;
    حالت TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    حالت TOK_ASM_ldceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        بشکن;
    پیشفرض:
        expect("coprocessor data transfer instruction");
    }
}

#اگر defined(TCC_ARM_VFP)
#define CP_SINGLE_PRECISION_FLOAT 10
#define CP_DOUBLE_PRECISION_FLOAT 11

ایستا تهی asm_floating_point_single_data_transfer_opcode(TCCState *s1, صحیح token)
{
    Operand ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_register = 0;
    صحیح long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    اگر (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        long_transfer = coprocessor_destination_register & 1;
        coprocessor_destination_register >>= 1;
    } وگرنه اگر (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        next();
    } وگرنه {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    اگر (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    اگر (tok == ',') {
        next(); // skip ','
        parse_operand(s1, &ops[2]);
        اگر (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } وگرنه {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_vldreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        بشکن;
    حالت TOK_ASM_vstreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        بشکن;
    پیشفرض:
        expect("floating point data transfer instruction");
    }
}

ایستا تهی asm_floating_point_block_data_transfer_opcode(TCCState *s1, صحیح token)
{
    uint8_t coprocessor = 0;
    صحیح first_regset_register;
    صحیح last_regset_register;
    uint8_t regset_item_شمار;
    uint8_t extra_register_bit = 0;
    صحیح op0_exclam = 0;
    صحیح load = 0;
    صحیح preincrement = 0;
    Operand ops[1];
    Operand offset;
    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_vpusheq:
    حالت TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        بشکن;
    پیشفرض:
        parse_operand(s1, &ops[0]);
        اگر (tok == '!') {
            op0_exclam = 1;
            next(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    first_regset_register = asm_parse_vfp_regvar(tok, 1);
    اگر ((first_regset_register = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        next();
    } وگرنه اگر ((first_regset_register = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        next();
    } وگرنه {
        expect("floating-point register");
    }

    اگر (tok == '-') {
        next();
        اگر ((last_regset_register = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            next();
        وگرنه {
            expect("floating-point register");
        }
    } وگرنه
        last_regset_register = first_regset_register;

    اگر (last_regset_register < first_regset_register) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_item_شمار = last_regset_register - first_regset_register + 1;
    اگر (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_item_شمار <<= 1;
    وگرنه {
        extra_register_bit = first_regset_register & 1;
        first_regset_register >>= 1;
    }
    offset.type = OP_IM8;
    offset.e.v = regset_item_شمار << 2;
    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_vstmeq: // post-increment store
    حالت TOK_ASM_vstmiaeq: // post-increment store
        بشکن;
    حالت TOK_ASM_vpopeq:
    حالت TOK_ASM_vldmeq: // post-increment load
    حالت TOK_ASM_vldmiaeq: // post-increment load
        load = 1;
        بشکن;
    حالت TOK_ASM_vldmdbeq: // pre-decrement load
        load = 1;
        /* fallthrough */
    حالت TOK_ASM_vpusheq:
    حالت TOK_ASM_vstmdbeq: // pre-decrement store
        offset.type = OP_IM8N;
        offset.e.v = -offset.e.v;
        preincrement = 1;
        بشکن;
    پیشفرض:
        expect("floating point block data transfer instruction");
    }
    اگر (ops[0].type != OP_REG32)
        expect("(first operand) register");
    وگرنه اگر (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, پوچ));
    وگرنه اگر (!op0_exclam && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, پوچ));
    وگرنه
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, first_regset_register, &ops[0], &offset, 0, preincrement, op0_exclam, extra_register_bit, load);
}

#define VMOV_FRACTIONAL_DIGITS 7
#define VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

ایستا uint32_t vmov_parse_fractional_part(ثابت نویسه* s)
{
    uint32_t result = 0;
    صحیح i;
    برای (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        نویسه c = *s;
        result *= 10;
        اگر (c >= '0' && c <= '9') {
            result += (c - '0');
            ++s;
        }
    }
    اگر (*s)
        expect("decimal numeral");
    بازگشت result;
}

ایستا صحیح vmov_linear_approx_index(uint32_t beginning, uint32_t end, uint32_t مقدار)
{
    صحیح i;
    uint32_t k;
    uint32_t xvalue;

    k = (end - beginning)/16;
    برای (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        اگر (مقدار == xvalue)
            بازگشت i;
    }
    //assert(0);
    بازگشت -1;
}

ایستا uint32_t vmov_parse_immediate_مقدار() {
    uint32_t مقدار;
    unsigned long integral_مقدار;
    ثابت نویسه *p;

    اگر (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.data;
    errno = 0;
    integral_مقدار = strtoul(p, (نویسه **)&p, 0);

    اگر (errno || integral_مقدار >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    مقدار = (uint32_t) integral_مقدار * VMOV_ONE;
    اگر (*p == '.') {
        ++p;
        مقدار += vmov_parse_fractional_part(p);
    }
    next();
    بازگشت مقدار;
}

ایستا uint8_t vmov_encode_immediate_مقدار(uint32_t مقدار)
{
    uint32_t limit;
    uint32_t end = 0;
    uint32_t beginning = 0;
    صحیح r = -1;
    صحیح n;
    صحیح i;

    limit = 32 * VMOV_ONE;
    برای (i = 0; i < 8; ++i) {
        اگر (مقدار < limit) {
            end = limit;
            limit >>= 1;
            beginning = limit;
            r = i;
        } وگرنه
            limit >>= 1;
    }
    اگر (r == -1 || مقدار < beginning || مقدار > end) {
        tcc_error("invalid decimal number for vmov: %d", مقدار);
    }
    n = vmov_linear_approx_index(beginning, end, مقدار);
    بازگشت n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
ایستا تهی asm_floating_point_immediate_data_processing_opcode_tail(TCCState *s1, صحیح token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t immediate_مقدار = 0;
    صحیح op_minus = 0;
    uint8_t code;

    operands[0] = CRd;

    اگر (tok == '#' || tok == '$') {
        next();
    }
    اگر (tok == '-') {
        op_minus = 1;
        next();
    }
    immediate_مقدار = vmov_parse_immediate_مقدار();

    opcode1 = 11; // "Other" instruction
    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_vcmpeq_f32:
    حالت TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        اگر (immediate_مقدار) {
            expect("Immediate value 0");
        }
        بشکن;
    حالت TOK_ASM_vcmpeeq_f32:
    حالت TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        اگر (immediate_مقدار) {
            expect("Immediate value 0");
        }
        بشکن;
    حالت TOK_ASM_vmoveq_f32:
    حالت TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        اگر (op_minus)
            operands[1] = 0x8;
        وگرنه
            operands[1] = 0x0;
        code = vmov_encode_immediate_مقدار(immediate_مقدار);
        operands[1] |= code >> 4;
        operands[2] = code & 0xF;
        بشکن;
    پیشفرض:
        expect("known floating point with immediate instruction");
    }

    اگر (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        اگر (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

ایستا تهی asm_floating_point_reg_arm_reg_transfer_opcode_tail(TCCState *s1, صحیح token, صحیح coprocessor, صحیح nb_arm_regs, صحیح nb_ops, Operand ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    انتخاب (coprocessor) {
    حالت CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        اگر (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        اگر (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            memcpy(&ops[2], &ops[1], اندازه(ops[2]));
            memcpy(&ops[1], &ops[0], اندازه(ops[1]));
            memcpy(&ops[0], &ops[2], اندازه(ops[0]));
        } وگرنه
            opcode1 |= 1;

        اگر (ops[1].type == OP_VREG32) {
            اگر (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        اگر (ops[0].type == OP_VREG32) {
            اگر (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        بشکن;
    حالت CP_DOUBLE_PRECISION_FLOAT:
        اگر (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        اگر (ops[0].type == OP_VREG64) {
            اگر (ops[2].type == OP_REG32) {
                Operand temp;
                // need to rotate operand list to the left
                memcpy(&temp, &ops[0], اندازه(temp));
                memcpy(&ops[0], &ops[1], اندازه(ops[0]));
                memcpy(&ops[1], &ops[2], اندازه(ops[1]));
                memcpy(&ops[2], &temp, اندازه(ops[2]));
            } وگرنه {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } وگرنه اگر (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } وگرنه {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        بشکن;
    پیشفرض:
        tcc_internal_error("unknown coprocessor");
    }
}

ایستا تهی asm_floating_point_vcvt_data_processing_opcode(TCCState *s1, صحیح token) {
    uint8_t coprocessor = 0;
    Operand ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_vcvtreq_s32_f64:
    حالت TOK_ASM_vcvtreq_u32_f64:
    حالت TOK_ASM_vcvteq_s32_f64:
    حالت TOK_ASM_vcvteq_u32_f64:
    حالت TOK_ASM_vcvteq_f64_s32:
    حالت TOK_ASM_vcvteq_f64_u32:
    حالت TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       بشکن;
    حالت TOK_ASM_vcvtreq_s32_f32:
    حالت TOK_ASM_vcvtreq_u32_f32:
    حالت TOK_ASM_vcvteq_s32_f32:
    حالت TOK_ASM_vcvteq_u32_f32:
    حالت TOK_ASM_vcvteq_f32_s32:
    حالت TOK_ASM_vcvteq_f32_u32:
    حالت TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       بشکن;
    پیشفرض:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, پوچ));
    }

    parse_operand(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_vcvtreq_s32_f32:
    حالت TOK_ASM_vcvtreq_s32_f64:
    حالت TOK_ASM_vcvteq_s32_f32:
    حالت TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    حالت TOK_ASM_vcvteq_u32_f32:
    حالت TOK_ASM_vcvteq_u32_f64:
    حالت TOK_ASM_vcvtreq_u32_f32:
    حالت TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        بشکن;
    /* floating-point size conversion */
    حالت TOK_ASM_vcvteq_f64_f32:
    حالت TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        بشکن;
    }

    skip(',');
    parse_operand(s1, &ops[2]);

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    /* floating-point -> integer */
    حالت TOK_ASM_vcvteq_s32_f32:
    حالت TOK_ASM_vcvteq_s32_f64:
    حالت TOK_ASM_vcvteq_u32_f32:
    حالت TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        بشکن;

    /* integer -> floating-point */
    حالت TOK_ASM_vcvteq_f64_s32:
    حالت TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        بشکن;

    /* floating-point size conversion */
    حالت TOK_ASM_vcvteq_f64_f32:
    حالت TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        بشکن;
    }

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_vcvteq_f64_u32:
    حالت TOK_ASM_vcvteq_f64_s32:
    حالت TOK_ASM_vcvteq_f64_f32:
        اگر (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } وگرنه {
            expect("d<number>, s<number>");
        }
        بشکن;
    پیشفرض:
        اگر (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            اگر (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } وگرنه {
                expect("s<number>, s<number>");
            }
        } وگرنه اگر (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            اگر (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } وگرنه {
                expect("s<number>, d<number>");
            }
        }
    }

    اگر (ops[2].type == OP_VREG32) {
        اگر (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    اگر (ops[0].type == OP_VREG32) {
        اگر (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

ایستا تهی asm_floating_point_data_processing_opcode(TCCState *s1, صحیح token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    Operand ops[3];
    uint8_t nb_ops = 0;
    صحیح vmov = 0;
    صحیح nb_arm_regs = 0;

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

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_vmlaeq_f64:
    حالت TOK_ASM_vmlseq_f64:
    حالت TOK_ASM_vnmlseq_f64:
    حالت TOK_ASM_vnmlaeq_f64:
    حالت TOK_ASM_vmuleq_f64:
    حالت TOK_ASM_vnmuleq_f64:
    حالت TOK_ASM_vaddeq_f64:
    حالت TOK_ASM_vsubeq_f64:
    حالت TOK_ASM_vdiveq_f64:
    حالت TOK_ASM_vnegeq_f64:
    حالت TOK_ASM_vabseq_f64:
    حالت TOK_ASM_vsqrteq_f64:
    حالت TOK_ASM_vcmpeq_f64:
    حالت TOK_ASM_vcmpeeq_f64:
    حالت TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_vmoveq_f32:
    حالت TOK_ASM_vmoveq_f64:
        vmov = 1;
        بشکن;
    }

    برای (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        اگر (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_point_immediate_data_processing_opcode_tail(s1, token, coprocessor, ops[0].reg);
            بازگشت;
        }
        parse_operand(s1, &ops[nb_ops]);
        اگر (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } وگرنه اگر (ops[nb_ops].type == OP_VREG32) {
            اگر (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } وگرنه اگر (ops[nb_ops].type == OP_VREG64) {
            اگر (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } وگرنه {
            expect("floating point register");
        }
        ++nb_ops;
        اگر (tok == ',')
            next();
        وگرنه
            بشکن;
    }

    اگر (nb_arm_regs == 0) {
        اگر (nb_ops == 2) { // implicit
            memcpy(&ops[2], &ops[1], اندازه(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], اندازه(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        اگر (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, پوچ), nb_ops);
        }
    }

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_vmlaeq_f32:
    حالت TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        بشکن;
    حالت TOK_ASM_vmlseq_f32:
    حالت TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        بشکن;
    حالت TOK_ASM_vnmlseq_f32:
    حالت TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        بشکن;
    حالت TOK_ASM_vnmlaeq_f32:
    حالت TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        بشکن;
    حالت TOK_ASM_vmuleq_f32:
    حالت TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        بشکن;
    حالت TOK_ASM_vnmuleq_f32:
    حالت TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        بشکن;
    حالت TOK_ASM_vaddeq_f32:
    حالت TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        بشکن;
    حالت TOK_ASM_vsubeq_f32:
    حالت TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        بشکن;
    حالت TOK_ASM_vdiveq_f32:
    حالت TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        بشکن;
    حالت TOK_ASM_vnegeq_f32:
    حالت TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        بشکن;
    حالت TOK_ASM_vabseq_f32:
    حالت TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        بشکن;
    حالت TOK_ASM_vsqrteq_f32:
    حالت TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        بشکن;
    حالت TOK_ASM_vcmpeq_f32:
    حالت TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        بشکن;
    حالت TOK_ASM_vcmpeeq_f32:
    حالت TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        بشکن;
    حالت TOK_ASM_vmoveq_f32:
    حالت TOK_ASM_vmoveq_f64:
        اگر (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_point_reg_arm_reg_transfer_opcode_tail(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            بازگشت;
        } وگرنه {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        بشکن;
    پیشفرض:
        expect("known floating point instruction");
    }

    اگر (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        اگر (ops[2].type == OP_VREG32) {
            اگر (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        اگر (ops[1].type == OP_VREG32) {
            اگر (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        اگر (ops[0].type == OP_VREG32) {
            اگر (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

ایستا صحیح asm_parse_vfp_status_regvar(صحیح t)
{
    انتخاب (t) {
    حالت TOK_ASM_fpsid:
        بازگشت 0;
    حالت TOK_ASM_fpscr:
        بازگشت 1;
    حالت TOK_ASM_fpexc:
        بازگشت 8;
    پیشفرض:
        بازگشت -1;
    }
}

ایستا تهی asm_floating_point_status_register_opcode(TCCState* s1, صحیح token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    صحیح vfp_sys_reg = -1;
    Operand arm_operand;
    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_vmrseq:
        opcode = 0xf;
        اگر (tok == TOK_ASM_apsr_nzcv) {
            arm_operand.type = OP_REG32;
            arm_operand.reg = 15; // not PC
            next(); // skip apsr_nzcv
        } وگرنه {
            parse_operand(s1, &arm_operand);
            اگر (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, پوچ));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        اگر (arm_operand.type == OP_REG32 && arm_operand.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, پوچ));
        }
        بشکن;
    حالت TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        skip(',');
        parse_operand(s1, &arm_operand);
        اگر (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, پوچ));
        }
        بشکن;
    پیشفرض:
        expect("floating point status register instruction");
    }
    اگر (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    اگر (arm_operand.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode, arm_operand.reg, vfp_sys_reg, 0x10, 0, 0);
}

#endif

ایستا تهی asm_misc_single_data_transfer_opcode(TCCState *s1, صحیح token)
{
    Operand ops[3];
    صحیح exclam = 0;
    صحیح closed_bracket = 0;
    صحیح op2_minus = 0;
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
    اگر (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    وگرنه {
        expect("(destination operand) register");
    }
    اگر (tok != ',')
        expect("at least two arguments");
    وگرنه
        next(); // skip ','
    skip('[');
    parse_operand(s1, &ops[1]);
    اگر (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    وگرنه {
        expect("(first source operand) register");
    }
    اگر (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    اگر (tok == ',') {
        next(); // skip ','
        اگر (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
    } وگرنه {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    اگر (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        اگر (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    اگر (exclam) {
        اگر ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, پوچ));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    اگر (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        صحیح v = ops[2].e.v;
        اگر (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        اگر (v >= 0) {
            opcode |= 1 << 23; // up
            اگر (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, پوچ));
            وگرنه {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } وگرنه { // down
            اگر (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, پوچ));
            وگرنه {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } وگرنه اگر (ops[2].type == OP_REG32) {
        اگر (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ops[2].reg;
    } وگرنه
        expect("register");

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    حالت TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        بشکن;
    حالت TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        بشکن;
    حالت TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        بشکن;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
ایستا uint32_t encbranchoffset(صحیح pos, صحیح addr, صحیح fail)
{
  addr-=pos+8;
  addr/=4;
  اگر(addr>=0x7fffff || addr<-0x800000) {
    اگر(fail)
      tcc_error("branch offset is too far");
    بازگشت 0;
  }
  بازگشت /*not 0x0A000000|*/(addr&0xffffff);
}

ایستا تهی asm_branch_opcode(TCCState *s1, صحیح token)
{
    صحیح jmp_disp = 0;
    Operand op;
    عبارت_مقدار e;
    ElfSym *esym;

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_beq:
    حالت TOK_ASM_bleq:
        asm_عبارت(s1, &e);
        اگر (e.sym) {
            esym = elfsym(e.sym);
            اگر (esym && esym->st_shndx == cur_text_section->sh_رقم) {
                jmp_disp = esym->st_مقدار;
            } وگرنه {
                greloca(cur_text_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        بشکن;
    پیشفرض:
        parse_operand(s1, &op);
        بشکن;
    }
    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        بشکن;
    حالت TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        بشکن;
    حالت TOK_ASM_bxeq:
        اگر (op.type != OP_REG32)
            expect("register");
        وگرنه
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        بشکن;
    حالت TOK_ASM_blxeq:
        اگر (op.type != OP_REG32)
            expect("register");
        وگرنه
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        بشکن;
    پیشفرض:
        expect("branch instruction");
    }
}

ST_FUNC تهی asm_opcode(TCCState *s1, صحیح token)
{
    وقتی (token == TOK_LINEFEED) {
        next();
        token = tok;
    }
    اگر (token == TOK_EOF)
        بازگشت;
    اگر (token < TOK_ASM_nopeq) { // no condition code
        انتخاب (token) {
        حالت TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            بازگشت;
        حالت TOK_ASM_ldc2:
        حالت TOK_ASM_ldc2l:
        حالت TOK_ASM_stc2:
        حالت TOK_ASM_stc2l:
            asm_coprocessor_data_transfer_opcode(s1, token);
            بازگشت;
        پیشفرض:
            expect("instruction");
        }
    }

    انتخاب (ARM_INSTRUCTION_GROUP(token)) {
    حالت TOK_ASM_pusheq:
    حالت TOK_ASM_popeq:
    حالت TOK_ASM_stmdaeq:
    حالت TOK_ASM_ldmdaeq:
    حالت TOK_ASM_stmeq:
    حالت TOK_ASM_ldmeq:
    حالت TOK_ASM_stmiaeq:
    حالت TOK_ASM_ldmiaeq:
    حالت TOK_ASM_stmdbeq:
    حالت TOK_ASM_ldmdbeq:
    حالت TOK_ASM_stmibeq:
    حالت TOK_ASM_ldmibeq:
        asm_block_data_transfer_opcode(s1, token);
        بازگشت;
    حالت TOK_ASM_nopeq:
    حالت TOK_ASM_wfeeq:
    حالت TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        بازگشت;
    حالت TOK_ASM_swieq:
    حالت TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        بازگشت;
    حالت TOK_ASM_beq:
    حالت TOK_ASM_bleq:
    حالت TOK_ASM_bxeq:
    حالت TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        بازگشت;
    حالت TOK_ASM_clzeq:
    حالت TOK_ASM_sxtbeq:
    حالت TOK_ASM_sxtheq:
    حالت TOK_ASM_uxtbeq:
    حالت TOK_ASM_uxtheq:
    حالت TOK_ASM_movteq:
    حالت TOK_ASM_movweq:
        asm_دودویی_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_ldreq:
    حالت TOK_ASM_ldrbeq:
    حالت TOK_ASM_streq:
    حالت TOK_ASM_strbeq:
    حالت TOK_ASM_ldrexeq:
    حالت TOK_ASM_ldrexbeq:
    حالت TOK_ASM_ldrexheq:
    حالت TOK_ASM_strexeq:
    حالت TOK_ASM_strexbeq:
    حالت TOK_ASM_strexheq:
        asm_single_data_transfer_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_ldrheq:
    حالت TOK_ASM_ldrsheq:
    حالت TOK_ASM_ldrsbeq:
    حالت TOK_ASM_strheq:
       asm_misc_single_data_transfer_opcode(s1, token);
       بازگشت;

    حالت TOK_ASM_andeq:
    حالت TOK_ASM_eoreq:
    حالت TOK_ASM_subeq:
    حالت TOK_ASM_rsbeq:
    حالت TOK_ASM_addeq:
    حالت TOK_ASM_adceq:
    حالت TOK_ASM_sbceq:
    حالت TOK_ASM_rsceq:
    حالت TOK_ASM_tsteq:
    حالت TOK_ASM_teqeq:
    حالت TOK_ASM_cmpeq:
    حالت TOK_ASM_cmneq:
    حالت TOK_ASM_orreq:
    حالت TOK_ASM_moveq:
    حالت TOK_ASM_biceq:
    حالت TOK_ASM_mvneq:
    حالت TOK_ASM_andseq:
    حالت TOK_ASM_eorseq:
    حالت TOK_ASM_subseq:
    حالت TOK_ASM_rsbseq:
    حالت TOK_ASM_addseq:
    حالت TOK_ASM_adcseq:
    حالت TOK_ASM_sbcseq:
    حالت TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    حالت TOK_ASM_orrseq:
    حالت TOK_ASM_movseq:
    حالت TOK_ASM_bicseq:
    حالت TOK_ASM_mvnseq:
        asm_data_processing_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_lsleq:
    حالت TOK_ASM_lslseq:
    حالت TOK_ASM_lsreq:
    حالت TOK_ASM_lsrseq:
    حالت TOK_ASM_asreq:
    حالت TOK_ASM_asrseq:
    حالت TOK_ASM_roreq:
    حالت TOK_ASM_rorseq:
    حالت TOK_ASM_rrxseq:
    حالت TOK_ASM_rrxeq:
        asm_shift_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_muleq:
    حالت TOK_ASM_mulseq:
    حالت TOK_ASM_mlaeq:
    حالت TOK_ASM_mlaseq:
    حالت TOK_ASM_mlseq:
    حالت TOK_ASM_udiveq:
    حالت TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_smulleq:
    حالت TOK_ASM_smullseq:
    حالت TOK_ASM_umulleq:
    حالت TOK_ASM_umullseq:
    حالت TOK_ASM_smlaleq:
    حالت TOK_ASM_smlalseq:
    حالت TOK_ASM_umlaleq:
    حالت TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_cdpeq:
    حالت TOK_ASM_mcreq:
    حالت TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_ldceq:
    حالت TOK_ASM_ldcleq:
    حالت TOK_ASM_stceq:
    حالت TOK_ASM_stcleq:
        asm_coprocessor_data_transfer_opcode(s1, token);
        بازگشت;

#اگر defined(TCC_ARM_VFP)
    حالت TOK_ASM_vldreq:
    حالت TOK_ASM_vstreq:
        asm_floating_point_single_data_transfer_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_vmlaeq_f32:
    حالت TOK_ASM_vmlseq_f32:
    حالت TOK_ASM_vnmlseq_f32:
    حالت TOK_ASM_vnmlaeq_f32:
    حالت TOK_ASM_vmuleq_f32:
    حالت TOK_ASM_vnmuleq_f32:
    حالت TOK_ASM_vaddeq_f32:
    حالت TOK_ASM_vsubeq_f32:
    حالت TOK_ASM_vdiveq_f32:
    حالت TOK_ASM_vnegeq_f32:
    حالت TOK_ASM_vabseq_f32:
    حالت TOK_ASM_vsqrteq_f32:
    حالت TOK_ASM_vcmpeq_f32:
    حالت TOK_ASM_vcmpeeq_f32:
    حالت TOK_ASM_vmoveq_f32:
    حالت TOK_ASM_vmlaeq_f64:
    حالت TOK_ASM_vmlseq_f64:
    حالت TOK_ASM_vnmlseq_f64:
    حالت TOK_ASM_vnmlaeq_f64:
    حالت TOK_ASM_vmuleq_f64:
    حالت TOK_ASM_vnmuleq_f64:
    حالت TOK_ASM_vaddeq_f64:
    حالت TOK_ASM_vsubeq_f64:
    حالت TOK_ASM_vdiveq_f64:
    حالت TOK_ASM_vnegeq_f64:
    حالت TOK_ASM_vabseq_f64:
    حالت TOK_ASM_vsqrteq_f64:
    حالت TOK_ASM_vcmpeq_f64:
    حالت TOK_ASM_vcmpeeq_f64:
    حالت TOK_ASM_vmoveq_f64:
        asm_floating_point_data_processing_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_vcvtreq_s32_f32:
    حالت TOK_ASM_vcvtreq_s32_f64:
    حالت TOK_ASM_vcvteq_s32_f32:
    حالت TOK_ASM_vcvteq_s32_f64:
    حالت TOK_ASM_vcvtreq_u32_f32:
    حالت TOK_ASM_vcvtreq_u32_f64:
    حالت TOK_ASM_vcvteq_u32_f32:
    حالت TOK_ASM_vcvteq_u32_f64:
    حالت TOK_ASM_vcvteq_f64_s32:
    حالت TOK_ASM_vcvteq_f32_s32:
    حالت TOK_ASM_vcvteq_f64_u32:
    حالت TOK_ASM_vcvteq_f32_u32:
    حالت TOK_ASM_vcvteq_f64_f32:
    حالت TOK_ASM_vcvteq_f32_f64:
        asm_floating_point_vcvt_data_processing_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_vpusheq:
    حالت TOK_ASM_vpopeq:
    حالت TOK_ASM_vldmeq:
    حالت TOK_ASM_vldmiaeq:
    حالت TOK_ASM_vldmdbeq:
    حالت TOK_ASM_vstmeq:
    حالت TOK_ASM_vstmiaeq:
    حالت TOK_ASM_vstmdbeq:
        asm_floating_point_block_data_transfer_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_vmsreq:
    حالت TOK_ASM_vmrseq:
        asm_floating_point_status_register_opcode(s1, token);
        بازگشت;
#endif

    پیشفرض:
        expect("known instruction");
    }
}

ST_FUNC تهی subst_asm_operand(CString *add_str, SValue *sv, صحیح modifier)
{
    صحیح r, reg, size, val;

    r = sv->r;
    اگر ((r & VT_VALMASK) == VT_CONST) {
        اگر (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        اگر (r & VT_SYM) {
            ثابت نویسه *name = get_tok_str(sv->sym->v, پوچ);
            اگر (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            اگر (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            اگر ((uint32_t) sv->c.i == 0)
                برو no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        اگر (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
      no_offset:;
    } وگرنه اگر ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[fp,#%d]", (صحیح) sv->c.i);
    } وگرنه اگر (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        اگر (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, پوچ));
    } وگرنه {
        /* register case */
        reg = r & VT_VALMASK;
        اگر (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        اگر ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        وگرنه اگر ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        وگرنه
            size = 4;

        اگر (modifier == 'b') {
            size = 1;
        } وگرنه اگر (modifier == 'w') {
            size = 2;
        } وگرنه اگر (modifier == 'k') {
            size = 4;
        }

        انتخاب (size) {
        پیشفرض:
            reg = TOK_ASM_r0 + reg;
            بشکن;
        }
        cstr_printf(add_str, "%s", get_tok_str(reg, پوچ));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC تهی asm_gen_code(ASMOperand *operands, صحیح nb_operands,
                          صحیح nb_outputs, صحیح is_output,
                          uint8_t *clobber_regs,
                          صحیح out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    صحیح i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    ایستا ثابت uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, اندازه(regs_allocated));
    برای(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        اگر (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    برای(i = 0; i < اندازه(reg_saved)/اندازه(reg_saved[0]); i++) {
        reg = reg_saved[i];
        اگر (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    اگر (!is_output) { // prolog
        /* generate reg save code */
        اگر (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        برای(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            اگر (op->reg >= 0) {
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } وگرنه اگر (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    load(op->reg, op->vt);
                    اگر (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } وگرنه { // epilog
        /* generate save code */
        برای(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            اگر (op->reg >= 0) {
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    اگر (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } وگرنه {
                    store(op->reg, op->vt);
                    اگر (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        اگر (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
ایستا درونخطی صحیح constraint_priority(ثابت نویسه *str)
{
    صحیح priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    برای(;;) {
        c = *str;
        اگر (c == '\0')
            بشکن;
        str++;
        انتخاب(c) {
        حالت 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        حالت 'r': // register [general]
        حالت 'p': // valid memory address for load,store [general]
            pr = 3;
            بشکن;
        حالت 'M': // integer constant for shifts [ARM]
        حالت 'I': // integer valid for data processing instruction immediate
        حالت 'J': // integer in range -4095...4095

        حالت 'i': // immediate integer operand, including symbolic constants [general]
        حالت 'm': // memory operand [general]
        حالت 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            بشکن;
        پیشفرض:
            tcc_error("unknown constraint '%c'", c);
        }
        اگر (pr > priority)
            priority = pr;
    }
    بازگشت priority;
}

ایستا ثابت نویسه *skip_constraint_modifiers(ثابت نویسه *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    وقتی (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    بازگشت p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC تهی asm_compute_constraints(ASMOperand *operands,
                                    صحیح nb_operands, صحیح nb_outputs,
                                    ثابت uint8_t *clobber_regs,
                                    صحیح *pout_reg)
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
    صحیح sorted_op[MAX_ASM_OPERANDS];
    صحیح i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ثابت نویسه *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    برای (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->درون_داد_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    برای (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        اگر (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, پوچ);
            اگر ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            اگر (operands[k].درون_داد_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].درون_داد_index = i;
            op->priority = 5;
        } وگرنه اگر ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } وگرنه {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    برای (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    برای (i = 0; i < nb_operands - 1; i++) {
        برای (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            اگر (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    برای (i = 0; i < NB_ASM_REGS; i++) {
        اگر (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        وگرنه
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_IN_MASK | REG_OUT_MASK;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    برای (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        اگر (op->ref_index >= 0)
            ادامه;
        /* select if register is used for output, input or both */
        اگر (op->درون_داد_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } وگرنه اگر (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } وگرنه {
            reg_mask = REG_IN_MASK;
        }
        اگر (op->reg >= 0) {
            اگر (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        انتخاب (c) {
        حالت '=': // Operand is written-to
            برو try_next;
        حالت '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        حالت '&': // Operand is clobbered before the instruction is done using the input operands
            اگر (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            برو try_next;
        حالت 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        حالت 'r': // general-purpose register
        حالت 'p': // loadable/storable address
            /* any general register */
            اگر ((reg = op->reg) >= 0)
                برو reg_found;
            وگرنه برای (reg = 0; reg <= 8; reg++) {
                اگر (!is_reg_allocated(reg))
                    برو reg_found;
            }
            برو try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            بشکن;
        حالت 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        حالت 'J': // integer in the range -4095 to 4095 [ARM]
        حالت 'K': // integer that satisfies constraint I when inverted (one's complement)
        حالت 'L': // integer that satisfies constraint I when inverted (two's complement)
        حالت 'i': // immediate integer operand, including symbolic constants
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                برو try_next;
            بشکن;
        حالت 'M': // integer in the range 0 to 32
            اگر (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                برو try_next;
            بشکن;
        حالت 'm': // memory operand
        حالت 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            اگر (j < nb_outputs || c == 'm') {
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    برای (reg = 0; reg <= 8; reg++) {
                        اگر (!(regs_allocated[reg] & REG_IN_MASK))
                            برو reg_found1;
                    }
                    برو try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            بشکن;
        پیشفرض:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            بشکن;
        }
        /* if a reference is present for that operand, we assign it too */
        اگر (op->درون_داد_index >= 0) {
            operands[op->درون_داد_index].reg = op->reg;
            operands[op->درون_داد_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    برای (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        اگر (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            برای (reg = 0; reg <= 8; reg++) {
                اگر (!(regs_allocated[reg] & REG_OUT_MASK))
                    برو reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            بشکن;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    برای (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, پوچ) : "",
               op->constraint, op->vt->r, op->reg);
    }
    اگر (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC تهی asm_clobber(uint8_t *clobber_regs, ثابت نویسه *str)
{
    صحیح reg;
    TokenSym *ts;

    اگر (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        بازگشت;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    اگر (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC صحیح asm_parse_regvar (صحیح t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    اگر (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        بازگشت -1;

    اگر (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        بازگشت t - TOK_ASM_r0;

    اگر (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        بازگشت t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    بازگشت t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
