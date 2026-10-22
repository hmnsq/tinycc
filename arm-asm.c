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

#اگر_تعریف_شدہ ہدف_DEFS_ONLY

#تعریف_کرو CONFIG_TCC_ASM
#تعریف_کرو NB_ASM_REGS 16

ST_FUNC خالی g(صحیح c);
ST_FUNC خالی gen_le16(صحیح c);
ST_FUNC خالی gen_le32(صحیح c);

/*************************************************************/
#ورنہ
/*************************************************************/

#تعریف_کرو USING_GLOBALS
#شامل "tcc.h"

شمار {
    OPT_REG32,
    OPT_REGSET32,
    OPT_IM8,
    OPT_IM8N,
    OPT_IM32,
    OPT_VREG32,
    OPT_VREG64,
};
#تعریف_کرو OP_REG32  (1 << OPT_REG32)
#تعریف_کرو OP_VREG32 (1 << OPT_VREG32)
#تعریف_کرو OP_VREG64 (1 << OPT_VREG64)
#تعریف_کرو OP_REG    (OP_REG32 | OP_VREG32 | OP_VREG64)
#تعریف_کرو OP_IM32   (1 << OPT_IM32)
#تعریف_کرو OP_IM8   (1 << OPT_IM8)
#تعریف_کرو OP_IM8N   (1 << OPT_IM8N)
#تعریف_کرو OP_REGSET32  (1 << OPT_REGSET32)

قسمتعریف ساخت عملیہ {
    uint32_t type;
    اتحاد {
        uint8_t reg;
        uint16_t regset;
        اظہاریہ_قدر e;
    };
} عملیہ;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
ساکن صحیح asm_parse_vfp_regvar(صحیح t, صحیح double_precision)
{
    اگر (double_precision) {
        اگر (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            واپس t - TOK_ASM_d0;
    } ورنہ {
        اگر (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            واپس t - TOK_ASM_s0;
    }
    واپس -1;
}

/* Parse a text containing operand and store the result in OP */
ساکن خالی parse_عملیہ(TCCState *s1, عملیہ *op)
{
    اظہاریہ_قدر e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    اگر (tok == '{') { // regset literal
        اگلا(); // skip '{'
        جب (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            اگر (reg == -1) {
                expect("register");
            } ورنہ
                اگلا(); // skip register name

            اگر ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            اگر (tok != ',')
                توڑو;
            اگلا(); // skip ','
        }
        skip('}');
        اگر (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } ورنہ {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        واپس;
    } ورنہ اگر ((reg = asm_parse_regvar(tok)) != -1) {
        اگلا(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        واپس;
    } ورنہ اگر ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        اگلا(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        واپس;
    } ورنہ اگر ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        اگلا(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        واپس;
    } ورنہ اگر (tok == '#' || tok == '$') {
        /* constant value */
        اگلا(); // skip '#' or '$'
    }
    asm_اظہاریہ(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    اگر (!op->e.sym) {
        اگر ((صحیح) op->e.v < 0 && (صحیح) op->e.v >= -255)
            op->type = OP_IM8N;
        ورنہ اگر (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } ورنہ
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC خالی g(صحیح c)
{
    صحیح ind1;
    اگر (nocode_wanted)
        واپس;
    ind1 = ind + 1;
    اگر (ind1 > cur_متن_section->ڈیٹا_allocated)
        section_realloc(cur_متن_section, ind1);
    cur_متن_section->ڈیٹا[ind] = c;
    ind = ind1;
}

ST_FUNC خالی gen_le16 (صحیح i)
{
    g(i);
    g(i>>8);
}

ST_FUNC خالی gen_le32 (صحیح i)
{
    صحیح ind1;
    اگر (nocode_wanted)
        واپس;
    ind1 = ind + 4;
    اگر (ind1 > cur_متن_section->ڈیٹا_allocated)
        section_realloc(cur_متن_section, ind1);
    cur_متن_section->ڈیٹا[ind++] = i & 0xFF;
    cur_متن_section->ڈیٹا[ind++] = (i >> 8) & 0xFF;
    cur_متن_section->ڈیٹا[ind++] = (i >> 16) & 0xFF;
    cur_متن_section->ڈیٹا[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC خالی gen_expr32(اظہاریہ_قدر *pe)
{
    gen_le32(pe->v);
}

ساکن uint32_t condition_رمز_کا_token(صحیح token) {
    اگر (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } ورنہ
        واپس (token - TOK_ASM_nopeq) & 15;
}

ساکن خالی asm_emit_opcode(صحیح token, uint32_t opcode) {
    gen_le32((condition_رمز_کا_token(token) << 28) | opcode);
}

ساکن خالی asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

ساکن خالی asm_emit_coprocessor_opcode(uint32_t بلند_nibble, uint8_t cp_نمبر, uint8_t cp_opcode, uint8_t cp_destination_رجسٹر, uint8_t cp_n_عملیہ_رجسٹر, uint8_t cp_m_عملیہ_رجسٹر, uint8_t cp_opcode2, صحیح inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    اگر (inter_processor_transfer)
        opcode |= 1 << 4;
    //assert(cp_opcode < 16);
    opcode |= cp_opcode << 20;
    //assert(cp_n_operand_register < 16);
    opcode |= cp_n_عملیہ_رجسٹر << 16;
    //assert(cp_destination_register < 16);
    opcode |= cp_destination_رجسٹر << 12;
    //assert(cp_number < 16);
    opcode |= cp_نمبر << 8;
    //assert(cp_information < 8);
    opcode |= cp_opcode2 << 5;
    //assert(cp_m_operand_register < 16);
    opcode |= cp_m_عملیہ_رجسٹر;
    asm_emit_unconditional_opcode((بلند_nibble << 28) | opcode);
}

ساکن خالی asm_nullary_opcode(صحیح token)
{
    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        توڑو;
    حالت TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    حالت TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        توڑو;
    طےشدہ:
        expect("nullary instruction");
    }
}

ساکن خالی asm_unary_opcode(TCCState *s1, صحیح token)
{
    عملیہ op;
    parse_عملیہ(s1, &op);

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_swieq:
    حالت TOK_ASM_svceq:
        اگر (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        ورنہ {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        توڑو;
    طےشدہ:
        expect("unary instruction");
    }
}

ساکن خالی asm_ثنائی_opcode(TCCState *s1, صحیح token)
{
    عملیہ ops[2];
    عملیہ rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_عملیہ(s1, &ops[0]);
    skip(',');
    parse_عملیہ(s1, &ops[1]);
    اگر (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    اگر (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, تہی));
    }

    اگر (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, تہی));

    اگر (ops[1].type != OP_REG32) {
        انتخاب (ARM_INSTRUCTION_گروہ(token)) {
        حالت TOK_ASM_movteq:
        حالت TOK_ASM_movweq:
            اگر (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                اگر (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t فوری_قدر = ops[1].e.v;
                    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
                    حالت TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (فوری_قدر & 0xF000) << 4 | (فوری_قدر & 0xFFF));
                        توڑو;
                    حالت TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (فوری_قدر & 0xF000) << 4 | (فوری_قدر & 0xFFF));
                        توڑو;
                    }
                } ورنہ
                    expect("(source operand) immediate 16 bit value");
            } ورنہ
                expect("(source operand) immediate");
            توڑو;
        طےشدہ:
            expect("(source operand) register");
        }
        واپس;
    }

    اگر (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, تہی));
    }

    اگر (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, تہی));

    اگر (tok == ',') {
        اگلا(); // skip ','
        اگر (tok == TOK_ASM_ror) {
            اگلا(); // skip 'ror'
            parse_عملیہ(s1, &rotation);
            اگر (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } ورنہ {
                amount = rotation.e.v;
                انتخاب (amount) {
                حالت 8:
                    encoded_rotation = 1 << 10;
                    توڑو;
                حالت 16:
                    encoded_rotation = 2 << 10;
                    توڑو;
                حالت 24:
                    encoded_rotation = 3 << 10;
                    توڑو;
                طےشدہ:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_clzeq:
        اگر (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        توڑو;
    حالت TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        توڑو;
    حالت TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        توڑو;
    حالت TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        توڑو;
    حالت TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        توڑو;
    طےشدہ:
        expect("binary instruction");
    }
}

ساکن خالی asm_coprocessor_opcode(TCCState *s1, صحیح token) {
    uint8_t coprocessor;
    عملیہ opcode1;
    عملیہ opcode2;
    uint8_t registers[3];
    غیرعلامتی صحیح i;
    uint8_t بلند_nibble;
    uint8_t mrc = 0;

    اگر (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        اگلا();
    } ورنہ {
        expect("'p<number>'");
    }
    skip(',');
    parse_عملیہ(s1, &opcode1);
    اگر (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, تہی));
    }

    برائے (i = 0; i < 3; ++i) {
        skip(',');
        اگر (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_گروہ(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_گروہ(token) == TOK_ASM_mcreq)) {
            اگر (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                اگلا();
            } ورنہ {
                expect("'r<number>'");
            }
        } ورنہ {
            اگر (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                اگلا();
            } ورنہ {
                expect("'c<number>'");
            }
        }
    }
    اگر (tok == ',') {
        اگلا();
        parse_عملیہ(s1, &opcode2);
    } ورنہ {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    اگر (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, تہی));
    }

    اگر (token == TOK_ASM_cdp2) {
        بلند_nibble = 0xF;
        asm_emit_coprocessor_opcode(بلند_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        واپس;
    } ورنہ
        بلند_nibble = condition_رمز_کا_token(token);

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(بلند_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        توڑو;
    حالت TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    حالت TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        اگر (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, تہی));
        }
        asm_emit_coprocessor_opcode(بلند_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        توڑو;
    طےشدہ:
        expect("known instruction");
    }
}

/* data processing and single data transfer instructions only */
#تعریف_کرو ENCODE_RN(رجسٹر_اشاریہ) ((رجسٹر_اشاریہ) << 16)
#تعریف_کرو ENCODE_RD(رجسٹر_اشاریہ) ((رجسٹر_اشاریہ) << 12)
#تعریف_کرو ENCODE_سیٹ_CONDITION_CODES (1 << 20)

/* Note: For data processing instructions, "1" means immediate.
   Note: For single data transfer instructions, "0" means immediate. */
#تعریف_کرو ENCODE_فوری_FLAG (1 << 25)

#تعریف_کرو ENCODE_BARREL_SHIFTER_سرکاؤ_BY_رجسٹر (1 << 4)
#تعریف_کرو ENCODE_BARREL_SHIFTER_منوال_LSL (0 << 5)
#تعریف_کرو ENCODE_BARREL_SHIFTER_منوال_LSR (1 << 5)
#تعریف_کرو ENCODE_BARREL_SHIFTER_منوال_ASR (2 << 5)
#تعریف_کرو ENCODE_BARREL_SHIFTER_منوال_ROR (3 << 5)
#تعریف_کرو ENCODE_BARREL_SHIFTER_رجسٹر(رجسٹر_اشاریہ) ((رجسٹر_اشاریہ) << 8)
#تعریف_کرو ENCODE_BARREL_SHIFTER_فوری(قدر) ((قدر) << 7)

ساکن خالی asm_بلاک_ڈیٹا_transfer_opcode(TCCState *s1, صحیح token)
{
    uint32_t opcode;
    صحیح op0_exclam = 0;
    عملیہ ops[2];
    صحیح nb_ops = 1;
    parse_عملیہ(s1, &ops[0]);
    اگر (tok == '!') {
        op0_exclam = 1;
        اگلا(); // skip '!'
    }
    اگر (tok == ',') {
        اگلا(); // skip comma
        parse_عملیہ(s1, &ops[1]);
        ++nb_ops;
    }
    اگر (nb_ops < 1) {
        expect("at least one operand");
    } ورنہ اگر (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        اگر (nb_ops != 1)
            expect("exactly one operand");
        ورنہ
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        توڑو;
    حالت TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        اگر (nb_ops != 1)
            expect("exactly one operand");
        ورنہ
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        توڑو;
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
        انتخاب (ARM_INSTRUCTION_گروہ(token)) {
        حالت TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            توڑو;
        حالت TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            توڑو;
        حالت TOK_ASM_stmeq: // post-increment store
        حالت TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            توڑو;
        حالت TOK_ASM_ldmeq: // post-increment load
        حالت TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            توڑو;
        حالت TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            توڑو;
        حالت TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            توڑو;
        حالت TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            توڑو;
        حالت TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            توڑو;
        طےشدہ:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        اگر (nb_ops != 2)
            expect("exactly two operands");
        ورنہ اگر (ops[0].type != OP_REG32)
            expect("(first operand) register");
        ورنہ {
            اگر (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        توڑو;
    طےشدہ:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
ساکن uint32_t asm_parse_optional_سرکاؤ(TCCState* s1, صحیح* nb_سرکاؤ, عملیہ* سرکاؤ)
{
    uint32_t opcode = 0;
    *nb_سرکاؤ = 0;
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
            opcode = ENCODE_BARREL_SHIFTER_منوال_LSL;
            توڑو;
        حالت TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_منوال_ASR;
            توڑو;
        حالت TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_منوال_LSR;
            توڑو;
        حالت TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_منوال_ROR;
            توڑو;
        }
        اگلا();
        parse_عملیہ(s1, سرکاؤ);
        *nb_سرکاؤ = 1;
        توڑو;
    حالت TOK_ASM_rrx:
        اگلا();
        opcode = ENCODE_BARREL_SHIFTER_منوال_ROR;
        توڑو;
    }
    واپس opcode;
}

ساکن uint32_t asm_encode_سرکاؤ(عملیہ* سرکاؤ)
{
    uint64_t amount;
    uint32_t operands = 0;
    انتخاب (سرکاؤ->type) {
    حالت OP_REG32:
        اگر (سرکاؤ->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        ورنہ {
            operands = ENCODE_BARREL_SHIFTER_سرکاؤ_BY_رجسٹر;
            operands |= ENCODE_BARREL_SHIFTER_رجسٹر(سرکاؤ->reg);
        }
        توڑو;
    حالت OP_IM8:
        amount = سرکاؤ->e.v;
        اگر (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_فوری(amount);
        ورنہ
            tcc_error("shift count out of range");
        توڑو;
    طےشدہ:
        tcc_error("unknown shift amount");
    }
    واپس operands;
}

ساکن خالی asm_ڈیٹا_processing_opcode(TCCState *s1, صحیح token)
{
    عملیہ ops[3];
    صحیح nb_ops;
    عملیہ سرکاؤ = {0};
    صحیح nb_سرکاؤ = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_گروہ(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    برائے (nb_ops = 0; nb_ops < حجم(ops)/حجم(ops[0]); ) {
        اگر (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            توڑو;
        parse_عملیہ(s1, &ops[nb_ops]);
        ++nb_ops;
        اگر (tok != ',')
            توڑو;
        اگلا(); // skip ','
    }
    اگر (tok == ',')
        اگلا();
    operands |= asm_parse_optional_سرکاؤ(s1, &nb_سرکاؤ, &سرکاؤ);
    اگر (nb_ops < 2)
        expect("at least two operands");
    ورنہ اگر (nb_ops == 2) {
        حافظہ_نقل(&ops[2], &ops[1], حجم(ops[1])); // move ops[2]
        حافظہ_نقل(&ops[1], &ops[0], حجم(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } ورنہ اگر (nb_ops == 3) {
        اگر (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, تہی));
        }
    }
    اگر (nb_ops != 3) {
        expect("two or three operands");
    } ورنہ {
        uint32_t opcode = 0;
        uint32_t فوری_قدر;
        uint8_t half_فوری_rotation;
        اگر (nb_سرکاؤ && سرکاؤ.type == OP_REG32) {
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
        ورنہ اگر (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_سیٹ_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        ورنہ
            operands |= ENCODE_RD(ops[0].reg);
        اگر (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        ورنہ اگر (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        انتخاب (ops[2].type) {
        حالت OP_REG32:
            operands |= ops[2].reg;
            توڑو;
        حالت OP_IM8:
        حالت OP_IM32:
            operands |= ENCODE_فوری_FLAG;
            فوری_قدر = ops[2].e.v;
            برائے (half_فوری_rotation = 0; half_فوری_rotation < 16; ++half_فوری_rotation) {
                اگر (فوری_قدر >= 0x00 && فوری_قدر < 0x100)
                    توڑو;
                // rotate left by two
                فوری_قدر = ((فوری_قدر & 0x3FFFFFFF) << 2) | ((فوری_قدر & 0xC0000000) >> 30);
            }
            اگر (half_فوری_rotation >= 16) {
                /* fallthrough */
            } ورنہ {
                operands |= فوری_قدر;
                operands |= half_فوری_rotation << 8;
                توڑو;
            }
        حالت OP_IM8N: // immediate negative value
            operands |= ENCODE_فوری_FLAG;
            فوری_قدر = ops[2].e.v;
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
                فوری_قدر = ~فوری_قدر;
                توڑو;
            حالت 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; //جوڑو
                فوری_قدر = -فوری_قدر;
                توڑو;
            حالت 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                فوری_قدر = -فوری_قدر;
                توڑو;
            حالت 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                فوری_قدر = ~فوری_قدر;
                توڑو;
            حالت 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                فوری_قدر = ~فوری_قدر;
                توڑو;
            حالت 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                فوری_قدر = -فوری_قدر;
                توڑو;
            حالت 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                فوری_قدر = -فوری_قدر;
                توڑو;
            حالت 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                فوری_قدر = ~فوری_قدر;
                توڑو;
            حالت 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                فوری_قدر = ~فوری_قدر;
                توڑو;
            حالت 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                فوری_قدر = ~فوری_قدر;
                توڑو;
            طےشدہ:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, تہی));
            }
            برائے (half_فوری_rotation = 0; half_فوری_rotation < 16; ++half_فوری_rotation) {
                اگر (فوری_قدر >= 0x00 && فوری_قدر < 0x100)
                    توڑو;
                // rotate left by two
                فوری_قدر = ((فوری_قدر & 0x3FFFFFFF) << 2) | ((فوری_قدر & 0xC0000000) >> 30);
            }
            اگر (half_فوری_rotation >= 16) {
                فوری_قدر = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (غیرعلامتی) فوری_قدر);
            }
            operands |= فوری_قدر;
            operands |= half_فوری_rotation << 8;
            توڑو;
        طےشدہ:
            expect("(second source operand) register or immediate value");
        }

        اگر (nb_سرکاؤ) {
            اگر (operands & ENCODE_فوری_FLAG)
                tcc_error("immediate rotation not implemented");
            ورنہ
                operands |= asm_encode_سرکاؤ(&سرکاؤ);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_سیٹ_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

ساکن خالی asm_سرکاؤ_opcode(TCCState *s1, صحیح token)
{
    عملیہ ops[3];
    صحیح nb_ops;
    صحیح definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    برائے (nb_ops = 0; nb_ops < حجم(ops)/حجم(ops[0]); ++nb_ops) {
        parse_عملیہ(s1, &ops[nb_ops]);
        اگر (tok != ',') {
            ++nb_ops;
            توڑو;
        }
        اگلا(); // skip ','
    }
    اگر (nb_ops < 2) {
        expect("at least two operands");
    }

    اگر (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } ورنہ
        operands |= ENCODE_RD(ops[0].reg);

    اگر (nb_ops == 2) {
        انتخاب (ARM_INSTRUCTION_گروہ(token)) {
        حالت TOK_ASM_rrxseq:
            opcode |= ENCODE_سیٹ_CONDITION_CODES;
            /* fallthrough */
        حالت TOK_ASM_rrxeq:
            اگر (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_منوال_ROR;
                asm_emit_opcode(token, opcode | operands);
            } ورنہ
                tcc_error("(first source operand) register");
            واپس;
        طےشدہ:
            حافظہ_نقل(&ops[2], &ops[1], حجم(ops[1])); // move ops[2]
            حافظہ_نقل(&ops[1], &ops[0], حجم(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    اگر (nb_ops != 3) {
        expect("two or three operands");
    }

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_lslseq:
    حالت TOK_ASM_lsrseq:
    حالت TOK_ASM_asrseq:
    حالت TOK_ASM_rorseq:
        opcode |= ENCODE_سیٹ_CONDITION_CODES;
        توڑو;
    }

    انتخاب (ops[1].type) {
    حالت OP_REG32:
        operands |= ops[1].reg;
        توڑو;
    حالت OP_IM8:
        operands |= ENCODE_فوری_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, تہی));
    }

    انتخاب (ops[2].type) {
    حالت OP_REG32:
        اگر ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_سرکاؤ(&ops[2]);
        توڑو;
    حالت OP_IM8:
        اگر (ops[2].e.v)
            operands |= asm_encode_سرکاؤ(&ops[2]);
        ورنہ
            definitely_neutral = 1;
        توڑو;
    }

    اگر (!definitely_neutral) انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_lslseq:
    حالت TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_منوال_LSL;
        توڑو;
    حالت TOK_ASM_lsrseq:
    حالت TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_منوال_LSR;
        توڑو;
    حالت TOK_ASM_asrseq:
    حالت TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_منوال_ASR;
        توڑو;
    حالت TOK_ASM_rorseq:
    حالت TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_منوال_ROR;
        توڑو;
    طےشدہ:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

ساکن خالی asm_multiplication_opcode(TCCState *s1, صحیح token)
{
    عملیہ ops[4];
    صحیح nb_ops = 0;
    uint32_t opcode = 0x90;

    برائے (nb_ops = 0; nb_ops < حجم(ops)/حجم(ops[0]); ++nb_ops) {
        parse_عملیہ(s1, &ops[nb_ops]);
        اگر (tok != ',') {
            ++nb_ops;
            توڑو;
        }
        اگلا(); // skip ','
    }
    اگر (nb_ops < 2)
        expect("at least two operands");
    ورنہ اگر (nb_ops == 2) {
        انتخاب (ARM_INSTRUCTION_گروہ(token)) {
        حالت TOK_ASM_mulseq:
        حالت TOK_ASM_muleq:
            حافظہ_نقل(&ops[2], &ops[0], حجم(ops[1])); // ARM is actually like this!
            توڑو;
        طےشدہ:
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
    ورنہ
        expect("(destination operand) register");
    اگر (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    ورنہ
        expect("(first source operand) register");
    اگر (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    ورنہ
        expect("(second source operand) register");
    اگر (nb_ops > 3) {
        اگر (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        ورنہ
            expect("(third source operand) register");
    }

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_mulseq:
        opcode |= 1 << 20; //حالت
        /* fallthrough */
    حالت TOK_ASM_muleq:
        اگر (nb_ops != 3)
            expect("three operands");
        ورنہ {
            asm_emit_opcode(token, opcode);
        }
        توڑو;
    حالت TOK_ASM_mlaseq:
        opcode |= 1 << 20; //حالت
        /* fallthrough */
    حالت TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        اگر (nb_ops != 4)
            expect("four operands");
        ورنہ {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        توڑو;
    حالت TOK_ASM_mlseq:
        opcode |= 0x00400000;
        جاؤ case_TOK_ASM_mlaeq;
    حالت TOK_ASM_udiveq:
        opcode |= 0x00200000;
    حالت TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        توڑو;
    طےشدہ:
        expect("known multiplication instruction");
    }
}

ساکن خالی asm_long_multiplication_opcode(TCCState *s1, صحیح token)
{
    عملیہ ops[4];
    صحیح nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    برائے (nb_ops = 0; nb_ops < حجم(ops)/حجم(ops[0]); ++nb_ops) {
        parse_عملیہ(s1, &ops[nb_ops]);
        اگر (tok != ',') {
            ++nb_ops;
            توڑو;
        }
        اگلا(); // skip ','
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
    ورنہ
        expect("(destination lo accumulator) register");
    اگر (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    ورنہ
        expect("(destination hi accumulator) register");
    اگر (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    ورنہ
        expect("(first source operand) register");
    اگر (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    ورنہ
        expect("(second source operand) register");

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_smullseq:
        opcode |= 1 << 20; //حالت
        /* fallthrough */
    حالت TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        توڑو;
    حالت TOK_ASM_umullseq:
        opcode |= 1 << 20; //حالت
        /* fallthrough */
    حالت TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        توڑو;
    حالت TOK_ASM_smlalseq:
        opcode |= 1 << 20; //حالت
        /* fallthrough */
    حالت TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        توڑو;
    حالت TOK_ASM_umlalseq:
        opcode |= 1 << 20; //حالت
        /* fallthrough */
    حالت TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        توڑو;
    طےشدہ:
        expect("known long multiplication instruction");
    }
}

ساکن خالی asm_single_ڈیٹا_transfer_opcode(TCCState *s1, صحیح token)
{
    عملیہ ops[3];
    عملیہ strex_عملیہ;
    عملیہ سرکاؤ;
    صحیح nb_سرکاؤ = 0;
    صحیح exclam = 0;
    صحیح closed_bracket = 0;
    صحیح op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_عملیہ(s1, &ops[0]);
    اگر (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    ورنہ {
        expect("(destination operand) register");
    }
    اگر (tok != ',')
        expect("at least two arguments");
    اگلا(); // skip ','

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_strexheq:
    حالت TOK_ASM_strexbeq:
    حالت TOK_ASM_strexeq:
        parse_عملیہ(s1, &strex_عملیہ);
        اگر (strex_عملیہ.type != OP_REG32) {
            expect("register");
        }
        اگر (tok != ',')
            expect("at least three arguments");
        ورنہ
            اگلا(); // skip ','
        توڑو;
    }

    skip('[');
    parse_عملیہ(s1, &ops[1]);
    اگر (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    ورنہ {
        expect("(first source operand) register");
    }
    اگر (tok == ']') {
        اگلا();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    اگر (tok == ',') {
        اگلا(); // skip ','
        اگر (tok == '-') {
            op2_minus = 1;
            اگلا();
        }
        parse_عملیہ(s1, &ops[2]);
        اگر (ops[2].type == OP_REG32) {
            اگر (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, تہی));
            }
            اگر (tok == ',') {
                اگلا();
                opcode |= asm_parse_optional_سرکاؤ(s1, &nb_سرکاؤ, &سرکاؤ);
                اگر (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } ورنہ {
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
            اگلا(); // skip '!'
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
            opcode |= 1 << 23; //اوپر
            اگر (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, تہی));
            ورنہ
                opcode |= v;
        } ورنہ { //نیچے_کو
            اگر (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, تہی));
            ورنہ
                opcode |= -v;
        }
    } ورنہ اگر (ops[2].type == OP_REG32) {
        اگر (!op2_minus)
            opcode |= 1 << 23; //اوپر
        opcode |= ENCODE_فوری_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } ورنہ
        expect("register");

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    حالت TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        اگر (nb_سرکاؤ)
            opcode |= asm_encode_سرکاؤ(&سرکاؤ);
        asm_emit_opcode(token, opcode);
        توڑو;
    حالت TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    حالت TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        اگر (nb_سرکاؤ)
            opcode |= asm_encode_سرکاؤ(&سرکاؤ);
        asm_emit_opcode(token, opcode);
        توڑو;
    حالت TOK_ASM_strexheq:
        opcode |= 1 << 21;
    حالت TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    حالت TOK_ASM_strexeq:
        اگر ((opcode & 0xFFF) || nb_سرکاؤ) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } ورنہ اگر (opcode & ENCODE_فوری_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        اگر ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_عملیہ.reg;
        asm_emit_opcode(token, opcode);
        توڑو;
    حالت TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    حالت TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    حالت TOK_ASM_ldrexeq:
        اگر ((opcode & 0xFFF) || nb_سرکاؤ) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } ورنہ اگر (opcode & ENCODE_فوری_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        اگر ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        توڑو;
    طےشدہ:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
ساکن خالی asm_emit_coprocessor_ڈیٹا_transfer(uint32_t بلند_nibble, uint8_t cp_نمبر, uint8_t CRd, ثابت عملیہ* Rn, ثابت عملیہ* انحراف, صحیح انحراف_minus, صحیح preincrement, صحیح writeback, صحیح long_transfer, صحیح بھرو) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    اگر (long_transfer)
        opcode |= 1 << 22; // long transfer

    اگر (بھرو)
        opcode |= 1 << 20; // L

    opcode |= cp_نمبر << 8;

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

    اگر (انحراف->type == OP_IM8 || انحراف->type == OP_IM8N || انحراف->type == OP_IM32) {
        صحیح v = انحراف->e.v;
        اگر (انحراف_minus)
            tcc_error("minus before '#' not supported for immediate values");
        اگر (انحراف->type == OP_IM8N || v < 0)
            v = -v;
        ورنہ
            opcode |= 1 << 23; //اوپر
        اگر (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        اگر (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } ورنہ اگر (انحراف->type == OP_REG32) {
        اگر (!انحراف_minus)
            opcode |= 1 << 23; //اوپر
        opcode |= ENCODE_فوری_FLAG; /* if set, it means it's NOT immediate */
        opcode |= انحراف->reg;
        tcc_error("Using register offset to register address is not possible here");
    } ورنہ اگر (انحراف->type == OP_VREG64) {
        opcode |= 16;
        opcode |= انحراف->reg;
    } ورنہ
        expect("immediate or register");

    asm_emit_unconditional_opcode((بلند_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
ساکن خالی asm_coprocessor_ڈیٹا_transfer_opcode(TCCState *s1, صحیح token)
{
    عملیہ ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_رجسٹر;
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
        اگلا();
    } ورنہ {
        expect("'c<number>'");
    }

    skip(',');

    اگر (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_رجسٹر = tok - TOK_ASM_c0;
        اگلا();
    } ورنہ {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_عملیہ(s1, &ops[1]);
    اگر (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    اگر (tok == ']') {
        اگلا();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    اگر (tok == ',') {
        اگلا(); // skip ','
        اگر (tok == '-') {
            op2_minus = 1;
            اگلا();
        }
        parse_عملیہ(s1, &ops[2]);
        اگر (ops[2].type == OP_REG32) {
            اگر (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, تہی));
            }
        } ورنہ اگر (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, تہی));
        }
    } ورنہ {
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
            اگلا(); // skip '!'
        }
    }

    // TODO: Support options.

    اگر (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        انتخاب (token) {
        حالت TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        حالت TOK_ASM_ldc2:
            asm_emit_coprocessor_ڈیٹا_transfer(0xF, coprocessor, coprocessor_destination_رجسٹر, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            توڑو;
        حالت TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        حالت TOK_ASM_stc2:
            asm_emit_coprocessor_ڈیٹا_transfer(0xF, coprocessor, coprocessor_destination_رجسٹر, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            توڑو;
        }
    } ورنہ انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    حالت TOK_ASM_stceq:
        asm_emit_coprocessor_ڈیٹا_transfer(condition_رمز_کا_token(token), coprocessor, coprocessor_destination_رجسٹر, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        توڑو;
    حالت TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    حالت TOK_ASM_ldceq:
        asm_emit_coprocessor_ڈیٹا_transfer(condition_رمز_کا_token(token), coprocessor, coprocessor_destination_رجسٹر, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        توڑو;
    طےشدہ:
        expect("coprocessor data transfer instruction");
    }
}

#اگر defined(TCC_ARM_VFP)
#تعریف_کرو CP_SINGLE_PRECISION_FLOAT 10
#تعریف_کرو CP_DOUBLE_PRECISION_FLOAT 11

ساکن خالی asm_floating_نقطہ_single_ڈیٹا_transfer_opcode(TCCState *s1, صحیح token)
{
    عملیہ ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_رجسٹر = 0;
    صحیح long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_عملیہ(s1, &ops[0]);
    اگر (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_رجسٹر = ops[0].reg;
        long_transfer = coprocessor_destination_رجسٹر & 1;
        coprocessor_destination_رجسٹر >>= 1;
    } ورنہ اگر (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_رجسٹر = ops[0].reg;
        اگلا();
    } ورنہ {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_عملیہ(s1, &ops[1]);
    اگر (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    اگر (tok == ',') {
        اگلا(); // skip ','
        parse_عملیہ(s1, &ops[2]);
        اگر (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } ورنہ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_vldreq:
        asm_emit_coprocessor_ڈیٹا_transfer(condition_رمز_کا_token(token), coprocessor, coprocessor_destination_رجسٹر, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        توڑو;
    حالت TOK_ASM_vstreq:
        asm_emit_coprocessor_ڈیٹا_transfer(condition_رمز_کا_token(token), coprocessor, coprocessor_destination_رجسٹر, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        توڑو;
    طےشدہ:
        expect("floating point data transfer instruction");
    }
}

ساکن خالی asm_floating_نقطہ_بلاک_ڈیٹا_transfer_opcode(TCCState *s1, صحیح token)
{
    uint8_t coprocessor = 0;
    صحیح پہلا_regset_رجسٹر;
    صحیح آخری_regset_رجسٹر;
    uint8_t regset_شے_گنتی;
    uint8_t extra_رجسٹر_ثنائی_ہندسہ = 0;
    صحیح op0_exclam = 0;
    صحیح بھرو = 0;
    صحیح preincrement = 0;
    عملیہ ops[1];
    عملیہ انحراف;
    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_vpusheq:
    حالت TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        توڑو;
    طےشدہ:
        parse_عملیہ(s1, &ops[0]);
        اگر (tok == '!') {
            op0_exclam = 1;
            اگلا(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    پہلا_regset_رجسٹر = asm_parse_vfp_regvar(tok, 1);
    اگر ((پہلا_regset_رجسٹر = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        اگلا();
    } ورنہ اگر ((پہلا_regset_رجسٹر = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        اگلا();
    } ورنہ {
        expect("floating-point register");
    }

    اگر (tok == '-') {
        اگلا();
        اگر ((آخری_regset_رجسٹر = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            اگلا();
        ورنہ {
            expect("floating-point register");
        }
    } ورنہ
        آخری_regset_رجسٹر = پہلا_regset_رجسٹر;

    اگر (آخری_regset_رجسٹر < پہلا_regset_رجسٹر) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_شے_گنتی = آخری_regset_رجسٹر - پہلا_regset_رجسٹر + 1;
    اگر (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_شے_گنتی <<= 1;
    ورنہ {
        extra_رجسٹر_ثنائی_ہندسہ = پہلا_regset_رجسٹر & 1;
        پہلا_regset_رجسٹر >>= 1;
    }
    انحراف.type = OP_IM8;
    انحراف.e.v = regset_شے_گنتی << 2;
    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_vstmeq: // post-increment store
    حالت TOK_ASM_vstmiaeq: // post-increment store
        توڑو;
    حالت TOK_ASM_vpopeq:
    حالت TOK_ASM_vldmeq: // post-increment load
    حالت TOK_ASM_vldmiaeq: // post-increment load
        بھرو = 1;
        توڑو;
    حالت TOK_ASM_vldmdbeq: // pre-decrement load
        بھرو = 1;
        /* fallthrough */
    حالت TOK_ASM_vpusheq:
    حالت TOK_ASM_vstmdbeq: // pre-decrement store
        انحراف.type = OP_IM8N;
        انحراف.e.v = -انحراف.e.v;
        preincrement = 1;
        توڑو;
    طےشدہ:
        expect("floating point block data transfer instruction");
    }
    اگر (ops[0].type != OP_REG32)
        expect("(first operand) register");
    ورنہ اگر (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, تہی));
    ورنہ اگر (!op0_exclam && ARM_INSTRUCTION_گروہ(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_گروہ(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_گروہ(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_گروہ(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, تہی));
    ورنہ
        asm_emit_coprocessor_ڈیٹا_transfer(condition_رمز_کا_token(token), coprocessor, پہلا_regset_رجسٹر, &ops[0], &انحراف, 0, preincrement, op0_exclam, extra_رجسٹر_ثنائی_ہندسہ, بھرو);
}

#تعریف_کرو VMOV_FRACTIONAL_DIGITS 7
#تعریف_کرو VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

ساکن uint32_t vmov_parse_fractional_part(ثابت حرف* s)
{
    uint32_t نتیجہ = 0;
    صحیح i;
    برائے (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        حرف c = *s;
        نتیجہ *= 10;
        اگر (c >= '0' && c <= '9') {
            نتیجہ += (c - '0');
            ++s;
        }
    }
    اگر (*s)
        expect("decimal numeral");
    واپس نتیجہ;
}

ساکن صحیح vmov_خطی_approx_اشاریہ(uint32_t beginning, uint32_t انتہا, uint32_t قدر)
{
    صحیح i;
    uint32_t k;
    uint32_t xvalue;

    k = (انتہا - beginning)/16;
    برائے (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        اگر (قدر == xvalue)
            واپس i;
    }
    //assert(0);
    واپس -1;
}

ساکن uint32_t vmov_parse_فوری_قدر() {
    uint32_t قدر;
    غیرعلامتی طویل integral_قدر;
    ثابت حرف *p;

    اگر (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.ڈیٹا;
    errno = 0;
    integral_قدر = strtoul(p, (حرف **)&p, 0);

    اگر (errno || integral_قدر >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    قدر = (uint32_t) integral_قدر * VMOV_ONE;
    اگر (*p == '.') {
        ++p;
        قدر += vmov_parse_fractional_part(p);
    }
    اگلا();
    واپس قدر;
}

ساکن uint8_t vmov_encode_فوری_قدر(uint32_t قدر)
{
    uint32_t حد_بندی;
    uint32_t انتہا = 0;
    uint32_t beginning = 0;
    صحیح r = -1;
    صحیح n;
    صحیح i;

    حد_بندی = 32 * VMOV_ONE;
    برائے (i = 0; i < 8; ++i) {
        اگر (قدر < حد_بندی) {
            انتہا = حد_بندی;
            حد_بندی >>= 1;
            beginning = حد_بندی;
            r = i;
        } ورنہ
            حد_بندی >>= 1;
    }
    اگر (r == -1 || قدر < beginning || قدر > انتہا) {
        tcc_error("invalid decimal number for vmov: %d", قدر);
    }
    n = vmov_خطی_approx_اشاریہ(beginning, انتہا, قدر);
    واپس n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
ساکن خالی asm_floating_نقطہ_فوری_ڈیٹا_processing_opcode_دم(TCCState *s1, صحیح token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t فوری_قدر = 0;
    صحیح op_minus = 0;
    uint8_t رمز;

    operands[0] = CRd;

    اگر (tok == '#' || tok == '$') {
        اگلا();
    }
    اگر (tok == '-') {
        op_minus = 1;
        اگلا();
    }
    فوری_قدر = vmov_parse_فوری_قدر();

    opcode1 = 11; // "Other" instruction
    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_vcmpeq_f32:
    حالت TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        اگر (فوری_قدر) {
            expect("Immediate value 0");
        }
        توڑو;
    حالت TOK_ASM_vcmpeeq_f32:
    حالت TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        اگر (فوری_قدر) {
            expect("Immediate value 0");
        }
        توڑو;
    حالت TOK_ASM_vmoveq_f32:
    حالت TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        اگر (op_minus)
            operands[1] = 0x8;
        ورنہ
            operands[1] = 0x0;
        رمز = vmov_encode_فوری_قدر(فوری_قدر);
        operands[1] |= رمز >> 4;
        operands[2] = رمز & 0xF;
        توڑو;
    طےشدہ:
        expect("known floating point with immediate instruction");
    }

    اگر (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        اگر (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_رمز_کا_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

ساکن خالی asm_floating_نقطہ_reg_arm_reg_transfer_opcode_دم(TCCState *s1, صحیح token, صحیح coprocessor, صحیح nb_arm_regs, صحیح nb_ops, عملیہ ops[3]) {
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
            حافظہ_نقل(&ops[2], &ops[1], حجم(ops[2]));
            حافظہ_نقل(&ops[1], &ops[0], حجم(ops[1]));
            حافظہ_نقل(&ops[0], &ops[2], حجم(ops[0]));
        } ورنہ
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

        asm_emit_coprocessor_opcode(condition_رمز_کا_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        توڑو;
    حالت CP_DOUBLE_PRECISION_FLOAT:
        اگر (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        اگر (ops[0].type == OP_VREG64) {
            اگر (ops[2].type == OP_REG32) {
                عملیہ عارضی;
                // need to rotate operand list to the left
                حافظہ_نقل(&عارضی, &ops[0], حجم(عارضی));
                حافظہ_نقل(&ops[0], &ops[1], حجم(ops[0]));
                حافظہ_نقل(&ops[1], &ops[2], حجم(ops[1]));
                حافظہ_نقل(&ops[2], &عارضی, حجم(ops[2]));
            } ورنہ {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } ورنہ اگر (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } ورنہ {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_ڈیٹا_transfer(condition_رمز_کا_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        توڑو;
    طےشدہ:
        tcc_اندرونی_error("unknown coprocessor");
    }
}

ساکن خالی asm_floating_نقطہ_vcvt_ڈیٹا_processing_opcode(TCCState *s1, صحیح token) {
    uint8_t coprocessor = 0;
    عملیہ ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_vcvtreq_s32_f64:
    حالت TOK_ASM_vcvtreq_u32_f64:
    حالت TOK_ASM_vcvteq_s32_f64:
    حالت TOK_ASM_vcvteq_u32_f64:
    حالت TOK_ASM_vcvteq_f64_s32:
    حالت TOK_ASM_vcvteq_f64_u32:
    حالت TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       توڑو;
    حالت TOK_ASM_vcvtreq_s32_f32:
    حالت TOK_ASM_vcvtreq_u32_f32:
    حالت TOK_ASM_vcvteq_s32_f32:
    حالت TOK_ASM_vcvteq_u32_f32:
    حالت TOK_ASM_vcvteq_f32_s32:
    حالت TOK_ASM_vcvteq_f32_u32:
    حالت TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       توڑو;
    طےشدہ:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, تہی));
    }

    parse_عملیہ(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
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
        توڑو;
    /* floating-point size conversion */
    حالت TOK_ASM_vcvteq_f64_f32:
    حالت TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        توڑو;
    }

    skip(',');
    parse_عملیہ(s1, &ops[2]);

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    /* floating-point -> integer */
    حالت TOK_ASM_vcvteq_s32_f32:
    حالت TOK_ASM_vcvteq_s32_f64:
    حالت TOK_ASM_vcvteq_u32_f32:
    حالت TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        توڑو;

    /* integer -> floating-point */
    حالت TOK_ASM_vcvteq_f64_s32:
    حالت TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        توڑو;

    /* floating-point size conversion */
    حالت TOK_ASM_vcvteq_f64_f32:
    حالت TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        توڑو;
    }

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_vcvteq_f64_u32:
    حالت TOK_ASM_vcvteq_f64_s32:
    حالت TOK_ASM_vcvteq_f64_f32:
        اگر (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } ورنہ {
            expect("d<number>, s<number>");
        }
        توڑو;
    طےشدہ:
        اگر (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            اگر (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } ورنہ {
                expect("s<number>, s<number>");
            }
        } ورنہ اگر (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            اگر (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } ورنہ {
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
    asm_emit_coprocessor_opcode(condition_رمز_کا_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

ساکن خالی asm_floating_نقطہ_ڈیٹا_processing_opcode(TCCState *s1, صحیح token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    عملیہ ops[3];
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

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
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

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_vmoveq_f32:
    حالت TOK_ASM_vmoveq_f64:
        vmov = 1;
        توڑو;
    }

    برائے (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        اگر (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_نقطہ_فوری_ڈیٹا_processing_opcode_دم(s1, token, coprocessor, ops[0].reg);
            واپس;
        }
        parse_عملیہ(s1, &ops[nb_ops]);
        اگر (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } ورنہ اگر (ops[nb_ops].type == OP_VREG32) {
            اگر (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } ورنہ اگر (ops[nb_ops].type == OP_VREG64) {
            اگر (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } ورنہ {
            expect("floating point register");
        }
        ++nb_ops;
        اگر (tok == ',')
            اگلا();
        ورنہ
            توڑو;
    }

    اگر (nb_arm_regs == 0) {
        اگر (nb_ops == 2) { // implicit
            حافظہ_نقل(&ops[2], &ops[1], حجم(ops[1])); // move ops[2]
            حافظہ_نقل(&ops[1], &ops[0], حجم(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        اگر (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, تہی), nb_ops);
        }
    }

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_vmlaeq_f32:
    حالت TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        توڑو;
    حالت TOK_ASM_vmlseq_f32:
    حالت TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        توڑو;
    حالت TOK_ASM_vnmlseq_f32:
    حالت TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        توڑو;
    حالت TOK_ASM_vnmlaeq_f32:
    حالت TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        توڑو;
    حالت TOK_ASM_vmuleq_f32:
    حالت TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        توڑو;
    حالت TOK_ASM_vnmuleq_f32:
    حالت TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        توڑو;
    حالت TOK_ASM_vaddeq_f32:
    حالت TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        توڑو;
    حالت TOK_ASM_vsubeq_f32:
    حالت TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        توڑو;
    حالت TOK_ASM_vdiveq_f32:
    حالت TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        توڑو;
    حالت TOK_ASM_vnegeq_f32:
    حالت TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        توڑو;
    حالت TOK_ASM_vabseq_f32:
    حالت TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        توڑو;
    حالت TOK_ASM_vsqrteq_f32:
    حالت TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        توڑو;
    حالت TOK_ASM_vcmpeq_f32:
    حالت TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        توڑو;
    حالت TOK_ASM_vcmpeeq_f32:
    حالت TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        توڑو;
    حالت TOK_ASM_vmoveq_f32:
    حالت TOK_ASM_vmoveq_f64:
        اگر (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_نقطہ_reg_arm_reg_transfer_opcode_دم(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            واپس;
        } ورنہ {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        توڑو;
    طےشدہ:
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

    asm_emit_coprocessor_opcode(condition_رمز_کا_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

ساکن صحیح asm_parse_vfp_حالت_regvar(صحیح t)
{
    انتخاب (t) {
    حالت TOK_ASM_fpsid:
        واپس 0;
    حالت TOK_ASM_fpscr:
        واپس 1;
    حالت TOK_ASM_fpexc:
        واپس 8;
    طےشدہ:
        واپس -1;
    }
}

ساکن خالی asm_floating_نقطہ_حالت_رجسٹر_opcode(TCCState* s1, صحیح token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    صحیح vfp_sys_reg = -1;
    عملیہ arm_عملیہ;
    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_vmrseq:
        opcode = 0xf;
        اگر (tok == TOK_ASM_apsr_nzcv) {
            arm_عملیہ.type = OP_REG32;
            arm_عملیہ.reg = 15; // not PC
            اگلا(); // skip apsr_nzcv
        } ورنہ {
            parse_عملیہ(s1, &arm_عملیہ);
            اگر (arm_عملیہ.type == OP_REG32 && arm_عملیہ.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, تہی));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_حالت_regvar(tok);
        اگلا(); // skip vfp sys reg
        اگر (arm_عملیہ.type == OP_REG32 && arm_عملیہ.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, تہی));
        }
        توڑو;
    حالت TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_حالت_regvar(tok);
        اگلا(); // skip vfp sys reg
        skip(',');
        parse_عملیہ(s1, &arm_عملیہ);
        اگر (arm_عملیہ.type == OP_REG32 && arm_عملیہ.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, تہی));
        }
        توڑو;
    طےشدہ:
        expect("floating point status register instruction");
    }
    اگر (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    اگر (arm_عملیہ.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_رمز_کا_token(token), coprocessor, opcode, arm_عملیہ.reg, vfp_sys_reg, 0x10, 0, 0);
}

#اگر_ختم

ساکن خالی asm_misc_single_ڈیٹا_transfer_opcode(TCCState *s1, صحیح token)
{
    عملیہ ops[3];
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

    parse_عملیہ(s1, &ops[0]);
    اگر (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    ورنہ {
        expect("(destination operand) register");
    }
    اگر (tok != ',')
        expect("at least two arguments");
    ورنہ
        اگلا(); // skip ','
    skip('[');
    parse_عملیہ(s1, &ops[1]);
    اگر (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    ورنہ {
        expect("(first source operand) register");
    }
    اگر (tok == ']') {
        اگلا();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    اگر (tok == ',') {
        اگلا(); // skip ','
        اگر (tok == '-') {
            op2_minus = 1;
            اگلا();
        }
        parse_عملیہ(s1, &ops[2]);
    } ورنہ {
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
            اگلا(); // skip '!'
        }
    }

    اگر (exclam) {
        اگر ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, تہی));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    اگر (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        صحیح v = ops[2].e.v;
        اگر (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        اگر (v >= 0) {
            opcode |= 1 << 23; //اوپر
            اگر (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, تہی));
            ورنہ {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } ورنہ { //نیچے_کو
            اگر (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, تہی));
            ورنہ {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } ورنہ اگر (ops[2].type == OP_REG32) {
        اگر (!op2_minus)
            opcode |= 1 << 23; //اوپر
        opcode |= ops[2].reg;
    } ورنہ
        expect("register");

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    حالت TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        توڑو;
    حالت TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        توڑو;
    حالت TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        توڑو;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
ساکن uint32_t encbranchoffset(صحیح pos, صحیح addr, صحیح fail)
{
  addr-=pos+8;
  addr/=4;
  اگر(addr>=0x7fffff || addr<-0x800000) {
    اگر(fail)
      tcc_error("branch offset is too far");
    واپس 0;
  }
  واپس /*not 0x0A000000|*/(addr&0xffffff);
}

ساکن خالی asm_branch_opcode(TCCState *s1, صحیح token)
{
    صحیح jmp_disp = 0;
    عملیہ op;
    اظہاریہ_قدر e;
    ElfSym *esym;

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_beq:
    حالت TOK_ASM_bleq:
        asm_اظہاریہ(s1, &e);
        اگر (e.sym) {
            esym = elfsym(e.sym);
            اگر (esym && esym->st_shndx == cur_متن_section->sh_عدد) {
                jmp_disp = esym->st_قدر;
            } ورنہ {
                greloca(cur_متن_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        توڑو;
    طےشدہ:
        parse_عملیہ(s1, &op);
        توڑو;
    }
    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
    حالت TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        توڑو;
    حالت TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        توڑو;
    حالت TOK_ASM_bxeq:
        اگر (op.type != OP_REG32)
            expect("register");
        ورنہ
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        توڑو;
    حالت TOK_ASM_blxeq:
        اگر (op.type != OP_REG32)
            expect("register");
        ورنہ
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        توڑو;
    طےشدہ:
        expect("branch instruction");
    }
}

ST_FUNC خالی asm_opcode(TCCState *s1, صحیح token)
{
    جب (token == TOK_LINEFEED) {
        اگلا();
        token = tok;
    }
    اگر (token == TOK_EOF)
        واپس;
    اگر (token < TOK_ASM_nopeq) { // no condition code
        انتخاب (token) {
        حالت TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            واپس;
        حالت TOK_ASM_ldc2:
        حالت TOK_ASM_ldc2l:
        حالت TOK_ASM_stc2:
        حالت TOK_ASM_stc2l:
            asm_coprocessor_ڈیٹا_transfer_opcode(s1, token);
            واپس;
        طےشدہ:
            expect("instruction");
        }
    }

    انتخاب (ARM_INSTRUCTION_گروہ(token)) {
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
        asm_بلاک_ڈیٹا_transfer_opcode(s1, token);
        واپس;
    حالت TOK_ASM_nopeq:
    حالت TOK_ASM_wfeeq:
    حالت TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        واپس;
    حالت TOK_ASM_swieq:
    حالت TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        واپس;
    حالت TOK_ASM_beq:
    حالت TOK_ASM_bleq:
    حالت TOK_ASM_bxeq:
    حالت TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        واپس;
    حالت TOK_ASM_clzeq:
    حالت TOK_ASM_sxtbeq:
    حالت TOK_ASM_sxtheq:
    حالت TOK_ASM_uxtbeq:
    حالت TOK_ASM_uxtheq:
    حالت TOK_ASM_movteq:
    حالت TOK_ASM_movweq:
        asm_ثنائی_opcode(s1, token);
        واپس;

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
        asm_single_ڈیٹا_transfer_opcode(s1, token);
        واپس;

    حالت TOK_ASM_ldrheq:
    حالت TOK_ASM_ldrsheq:
    حالت TOK_ASM_ldrsbeq:
    حالت TOK_ASM_strheq:
       asm_misc_single_ڈیٹا_transfer_opcode(s1, token);
       واپس;

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
        asm_ڈیٹا_processing_opcode(s1, token);
        واپس;

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
        asm_سرکاؤ_opcode(s1, token);
        واپس;

    حالت TOK_ASM_muleq:
    حالت TOK_ASM_mulseq:
    حالت TOK_ASM_mlaeq:
    حالت TOK_ASM_mlaseq:
    حالت TOK_ASM_mlseq:
    حالت TOK_ASM_udiveq:
    حالت TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        واپس;

    حالت TOK_ASM_smulleq:
    حالت TOK_ASM_smullseq:
    حالت TOK_ASM_umulleq:
    حالت TOK_ASM_umullseq:
    حالت TOK_ASM_smlaleq:
    حالت TOK_ASM_smlalseq:
    حالت TOK_ASM_umlaleq:
    حالت TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        واپس;

    حالت TOK_ASM_cdpeq:
    حالت TOK_ASM_mcreq:
    حالت TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        واپس;

    حالت TOK_ASM_ldceq:
    حالت TOK_ASM_ldcleq:
    حالت TOK_ASM_stceq:
    حالت TOK_ASM_stcleq:
        asm_coprocessor_ڈیٹا_transfer_opcode(s1, token);
        واپس;

#اگر defined(TCC_ARM_VFP)
    حالت TOK_ASM_vldreq:
    حالت TOK_ASM_vstreq:
        asm_floating_نقطہ_single_ڈیٹا_transfer_opcode(s1, token);
        واپس;

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
        asm_floating_نقطہ_ڈیٹا_processing_opcode(s1, token);
        واپس;

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
        asm_floating_نقطہ_vcvt_ڈیٹا_processing_opcode(s1, token);
        واپس;

    حالت TOK_ASM_vpusheq:
    حالت TOK_ASM_vpopeq:
    حالت TOK_ASM_vldmeq:
    حالت TOK_ASM_vldmiaeq:
    حالت TOK_ASM_vldmdbeq:
    حالت TOK_ASM_vstmeq:
    حالت TOK_ASM_vstmiaeq:
    حالت TOK_ASM_vstmdbeq:
        asm_floating_نقطہ_بلاک_ڈیٹا_transfer_opcode(s1, token);
        واپس;

    حالت TOK_ASM_vmsreq:
    حالت TOK_ASM_vmrseq:
        asm_floating_نقطہ_حالت_رجسٹر_opcode(s1, token);
        واپس;
#اگر_ختم

    طےشدہ:
        expect("known instruction");
    }
}

ST_FUNC خالی subst_asm_عملیہ(CString *جوڑو_str, SValue *sv, صحیح modifier)
{
    صحیح r, reg, سائز, val;

    r = sv->r;
    اگر ((r & VT_VALMASK) == VT_CONST) {
        اگر (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(جوڑو_str, '#');
        اگر (r & VT_SYM) {
            ثابت حرف *name = get_tok_str(sv->sym->v, تہی);
            اگر (sv->sym->v >= SYM_پہلا_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, لڑی_لمبائی(name))->tok, sv->sym);
            }
            اگر (tcc_state->leading_underscore)
                cstr_ccat(جوڑو_str, '_');
            cstr_cat(جوڑو_str, name, -1);
            اگر ((uint32_t) sv->c.i == 0)
                جاؤ no_انحراف;
            cstr_ccat(جوڑو_str, '+');
        }
        val = sv->c.i;
        اگر (modifier == 'n')
            val = -val;
        cstr_printf(جوڑو_str, "%d", val);
      no_انحراف:;
    } ورنہ اگر ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(جوڑو_str, "[fp,#%d]", (صحیح) sv->c.i);
    } ورنہ اگر (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        اگر (reg >= VT_CONST)
            tcc_اندرونی_error("");
        cstr_printf(جوڑو_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, تہی));
    } ورنہ {
        /* register case */
        reg = r & VT_VALMASK;
        اگر (reg >= VT_CONST)
            tcc_اندرونی_error("");

        /* choose register operand size */
        اگر ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            سائز = 1;
        ورنہ اگر ((sv->type.t & VT_BTYPE) == VT_SHORT)
            سائز = 2;
        ورنہ
            سائز = 4;

        اگر (modifier == 'b') {
            سائز = 1;
        } ورنہ اگر (modifier == 'w') {
            سائز = 2;
        } ورنہ اگر (modifier == 'k') {
            سائز = 4;
        }

        انتخاب (سائز) {
        طےشدہ:
            reg = TOK_ASM_r0 + reg;
            توڑو;
        }
        cstr_printf(جوڑو_str, "%s", get_tok_str(reg, تہی));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC خالی asm_gen_رمز(ASMOperand *operands, صحیح nb_operands,
                          صحیح nb_outputs, صحیح is_output,
                          uint8_t *clobber_regs,
                          صحیح برآمد_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    صحیح i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    ساکن ثابت uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    حافظہ_نقل(regs_allocated, clobber_regs, حجم(regs_allocated));
    برائے(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        اگر (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    برائے(i = 0; i < حجم(reg_saved)/حجم(reg_saved[0]); i++) {
        reg = reg_saved[i];
        اگر (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    اگر (!is_output) { // prolog
        /* generate reg save code */
        اگر (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        برائے(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            اگر (op->reg >= 0) {
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_حافظہ) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    بھرو(op->reg, &sv);
                } ورنہ اگر (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    بھرو(op->reg, op->vt);
                    اگر (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } ورنہ { // epilog
        /* generate save code */
        برائے(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            اگر (op->reg >= 0) {
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    اگر (!op->is_حافظہ) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        بھرو(برآمد_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | برآمد_reg;
                        store(op->reg, &sv);
                    }
                } ورنہ {
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
ساکن اندرونی صحیح constraint_ترجیح(ثابت حرف *str)
{
    صحیح ترجیح, c, pr;

    /* we take the lowest priority */
    ترجیح = 0;
    برائے(;;) {
        c = *str;
        اگر (c == '\0')
            توڑو;
        str++;
        انتخاب(c) {
        حالت 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        حالت 'r': // register [general]
        حالت 'p': // valid memory address for load,store [general]
            pr = 3;
            توڑو;
        حالت 'M': // integer constant for shifts [ARM]
        حالت 'I': // integer valid for data processing instruction immediate
        حالت 'J': // integer in range -4095...4095

        حالت 'i': // immediate integer operand, including symbolic constants [general]
        حالت 'm': // memory operand [general]
        حالت 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            توڑو;
        طےشدہ:
            tcc_error("unknown constraint '%c'", c);
        }
        اگر (pr > ترجیح)
            ترجیح = pr;
    }
    واپس ترجیح;
}

ساکن ثابت حرف *skip_constraint_modifiers(ثابت حرف *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    جب (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    واپس p;
}

#تعریف_کرو REG_برآمد_نقاب 0x01
#تعریف_کرو REG_اندر_نقاب  0x02

#تعریف_کرو is_reg_allocated(reg) (regs_allocated[reg] & reg_نقاب)

ST_FUNC خالی asm_compute_constraints(ASMOperand *operands,
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
    صحیح i, j, k, p1, p2, tmp, reg, c, reg_نقاب;
    ثابت حرف *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    برائے (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->داخلہ_اشاریہ = -1;
        op->ref_اشاریہ = -1;
        op->reg = -1;
        op->is_حافظہ = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    برائے (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        اگر (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = ڈھونڈو_constraint(operands, nb_operands, str, تہی);
            اگر ((غیرعلامتی) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_اشاریہ = k;
            اگر (operands[k].داخلہ_اشاریہ >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].داخلہ_اشاریہ = i;
            op->ترجیح = 5;
        } ورنہ اگر ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->ترجیح = 1;
            op->reg = reg;
        } ورنہ {
            op->ترجیح = constraint_ترجیح(str);
        }
    }

    /* sort operands according to their priority */
    برائے (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    برائے (i = 0; i < nb_operands - 1; i++) {
        برائے (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].ترجیح;
            p2 = operands[sorted_op[j]].ترجیح;
            اگر (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    برائے (i = 0; i < NB_ASM_REGS; i++) {
        اگر (clobber_regs[i])
            regs_allocated[i] = REG_اندر_نقاب | REG_برآمد_نقاب;
        ورنہ
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_اندر_نقاب | REG_برآمد_نقاب;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_اندر_نقاب | REG_برآمد_نقاب;

    /* allocate registers and generate corresponding asm moves */
    برائے (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        اگر (op->ref_اشاریہ >= 0)
            جاری;
        /* select if register is used for output, input or both */
        اگر (op->داخلہ_اشاریہ >= 0) {
            reg_نقاب = REG_اندر_نقاب | REG_برآمد_نقاب;
        } ورنہ اگر (j < nb_outputs) {
            reg_نقاب = REG_برآمد_نقاب;
        } ورنہ {
            reg_نقاب = REG_اندر_نقاب;
        }
        اگر (op->reg >= 0) {
            اگر (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_اگلا:
        c = *str++;
        انتخاب (c) {
        حالت '=': // Operand is written-to
            جاؤ try_اگلا;
        حالت '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        حالت '&': // Operand is clobbered before the instruction is done using the input operands
            اگر (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_نقاب = REG_اندر_نقاب | REG_برآمد_نقاب;
            جاؤ try_اگلا;
        حالت 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        حالت 'r': // general-purpose register
        حالت 'p': // loadable/storable address
            /* any general register */
            اگر ((reg = op->reg) >= 0)
                جاؤ reg_ملا;
            ورنہ برائے (reg = 0; reg <= 8; reg++) {
                اگر (!is_reg_allocated(reg))
                    جاؤ reg_ملا;
            }
            جاؤ try_اگلا;
          reg_ملا:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_نقاب;
            توڑو;
        حالت 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        حالت 'J': // integer in the range -4095 to 4095 [ARM]
        حالت 'K': // integer that satisfies constraint I when inverted (one's complement)
        حالت 'L': // integer that satisfies constraint I when inverted (two's complement)
        حالت 'i': // immediate integer operand, including symbolic constants
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                جاؤ try_اگلا;
            توڑو;
        حالت 'M': // integer in the range 0 to 32
            اگر (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                جاؤ try_اگلا;
            توڑو;
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
                    برائے (reg = 0; reg <= 8; reg++) {
                        اگر (!(regs_allocated[reg] & REG_اندر_نقاب))
                            جاؤ reg_found1;
                    }
                    جاؤ try_اگلا;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_اندر_نقاب;
                    op->reg = reg;
                    op->is_حافظہ = 1;
                }
            }
            توڑو;
        طےشدہ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            توڑو;
        }
        /* if a reference is present for that operand, we assign it too */
        اگر (op->داخلہ_اشاریہ >= 0) {
            operands[op->داخلہ_اشاریہ].reg = op->reg;
            operands[op->داخلہ_اشاریہ].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    برائے (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        اگر (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_حافظہ) {
            برائے (reg = 0; reg <= 8; reg++) {
                اگر (!(regs_allocated[reg] & REG_برآمد_نقاب))
                    جاؤ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            توڑو;
        }
    }

    /* print sorted constraints */
#اگر_تعریف_شدہ ASM_DEBUG
    برائے (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        لکھو("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, تہی) : "",
               op->constraint, op->vt->r, op->reg);
    }
    اگر (*pout_reg >= 0)
        لکھو("out_reg=%d\n", *pout_reg);
#اگر_ختم
}

ST_FUNC خالی asm_clobber(uint8_t *clobber_regs, ثابت حرف *str)
{
    صحیح reg;
    TokenSym *ts;

    اگر (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        واپس;
    ts = tok_alloc(str, لڑی_لمبائی(str));
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
        واپس -1;

    اگر (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        واپس t - TOK_ASM_r0;

    اگر (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        واپس t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    واپس t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#اگر_ختم /* ndef TARGET_DEFS_ONLY */
