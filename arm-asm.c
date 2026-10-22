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

ST_FUNC शून्य g(पूर्णाङ्क c);
ST_FUNC शून्य gen_le16(पूर्णाङ्क c);
ST_FUNC शून्य gen_le32(पूर्णाङ्क c);

/*************************************************************/
#अञ्ञथा
/*************************************************************/

#define USING_GLOBALS
#अन्तर्भाव "tcc.h"

गणना {
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

प्रकारनिर्देश संरचना Operand {
    uint32_t type;
    सङ्घ {
        uint8_t reg;
        uint16_t regset;
        व्यञ्जकम्_मानम् e;
    };
} Operand;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
स्थिर पूर्णाङ्क asm_parse_vfp_regvar(पूर्णाङ्क t, पूर्णाङ्क double_precision)
{
    सचे (double_precision) {
        सचे (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            पटिनिवत्त t - TOK_ASM_d0;
    } अञ्ञथा {
        सचे (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            पटिनिवत्त t - TOK_ASM_s0;
    }
    पटिनिवत्त -1;
}

/* Parse a text containing operand and store the result in OP */
स्थिर शून्य parse_operand(TCCState *s1, Operand *op)
{
    व्यञ्जकम्_मानम् e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    सचे (tok == '{') { // regset literal
        next(); // skip '{'
        याव (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            सचे (reg == -1) {
                expect("register");
            } अञ्ञथा
                next(); // skip register name

            सचे ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            सचे (tok != ',')
                भङ्ग;
            next(); // skip ','
        }
        skip('}');
        सचे (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } अञ्ञथा {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        पटिनिवत्त;
    } अञ्ञथा सचे ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        पटिनिवत्त;
    } अञ्ञथा सचे ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        next(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        पटिनिवत्त;
    } अञ्ञथा सचे ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        next(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        पटिनिवत्त;
    } अञ्ञथा सचे (tok == '#' || tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    }
    asm_व्यञ्जकम्(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    सचे (!op->e.sym) {
        सचे ((पूर्णाङ्क) op->e.v < 0 && (पूर्णाङ्क) op->e.v >= -255)
            op->type = OP_IM8N;
        अञ्ञथा सचे (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } अञ्ञथा
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC शून्य g(पूर्णाङ्क c)
{
    पूर्णाङ्क ind1;
    सचे (nocode_wanted)
        पटिनिवत्त;
    ind1 = ind + 1;
    सचे (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC शून्य gen_le16 (पूर्णाङ्क i)
{
    g(i);
    g(i>>8);
}

ST_FUNC शून्य gen_le32 (पूर्णाङ्क i)
{
    पूर्णाङ्क ind1;
    सचे (nocode_wanted)
        पटिनिवत्त;
    ind1 = ind + 4;
    सचे (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC शून्य gen_expr32(व्यञ्जकम्_मानम् *pe)
{
    gen_le32(pe->v);
}

स्थिर uint32_t condition_code_of_token(पूर्णाङ्क token) {
    सचे (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } अञ्ञथा
        पटिनिवत्त (token - TOK_ASM_nopeq) & 15;
}

स्थिर शून्य asm_emit_opcode(पूर्णाङ्क token, uint32_t opcode) {
    gen_le32((condition_code_of_token(token) << 28) | opcode);
}

स्थिर शून्य asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

स्थिर शून्य asm_emit_coprocessor_opcode(uint32_t उच्चः_nibble, uint8_t cp_सङ्ख्या, uint8_t cp_opcode, uint8_t cp_destination_register, uint8_t cp_n_operand_register, uint8_t cp_m_operand_register, uint8_t cp_opcode2, पूर्णाङ्क inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    सचे (inter_processor_transfer)
        opcode |= 1 << 4;
    //assert(cp_opcode < 16);
    opcode |= cp_opcode << 20;
    //assert(cp_n_operand_register < 16);
    opcode |= cp_n_operand_register << 16;
    //assert(cp_destination_register < 16);
    opcode |= cp_destination_register << 12;
    //assert(cp_number < 16);
    opcode |= cp_सङ्ख्या << 8;
    //assert(cp_information < 8);
    opcode |= cp_opcode2 << 5;
    //assert(cp_m_operand_register < 16);
    opcode |= cp_m_operand_register;
    asm_emit_unconditional_opcode((उच्चः_nibble << 28) | opcode);
}

स्थिर शून्य asm_nullary_opcode(पूर्णाङ्क token)
{
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        भङ्ग;
    पक्ष TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    पक्ष TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        भङ्ग;
    स्वभाव:
        expect("nullary instruction");
    }
}

स्थिर शून्य asm_unary_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand op;
    parse_operand(s1, &op);

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_swieq:
    पक्ष TOK_ASM_svceq:
        सचे (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        अञ्ञथा {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        भङ्ग;
    स्वभाव:
        expect("unary instruction");
    }
}

स्थिर शून्य asm_द्विमान_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[2];
    Operand rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);
    सचे (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    सचे (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
    }

    सचे (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, रिक्त));

    सचे (ops[1].type != OP_REG32) {
        विकल्प (ARM_INSTRUCTION_GROUP(token)) {
        पक्ष TOK_ASM_movteq:
        पक्ष TOK_ASM_movweq:
            सचे (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                सचे (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t immediate_मानम् = ops[1].e.v;
                    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
                    पक्ष TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (immediate_मानम् & 0xF000) << 4 | (immediate_मानम् & 0xFFF));
                        भङ्ग;
                    पक्ष TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (immediate_मानम् & 0xF000) << 4 | (immediate_मानम् & 0xFFF));
                        भङ्ग;
                    }
                } अञ्ञथा
                    expect("(source operand) immediate 16 bit value");
            } अञ्ञथा
                expect("(source operand) immediate");
            भङ्ग;
        स्वभाव:
            expect("(source operand) register");
        }
        पटिनिवत्त;
    }

    सचे (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
    }

    सचे (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, रिक्त));

    सचे (tok == ',') {
        next(); // skip ','
        सचे (tok == TOK_ASM_ror) {
            next(); // skip 'ror'
            parse_operand(s1, &rotation);
            सचे (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } अञ्ञथा {
                amount = rotation.e.v;
                विकल्प (amount) {
                पक्ष 8:
                    encoded_rotation = 1 << 10;
                    भङ्ग;
                पक्ष 16:
                    encoded_rotation = 2 << 10;
                    भङ्ग;
                पक्ष 24:
                    encoded_rotation = 3 << 10;
                    भङ्ग;
                स्वभाव:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_clzeq:
        सचे (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        भङ्ग;
    पक्ष TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        भङ्ग;
    पक्ष TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        भङ्ग;
    पक्ष TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        भङ्ग;
    पक्ष TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        भङ्ग;
    स्वभाव:
        expect("binary instruction");
    }
}

स्थिर शून्य asm_coprocessor_opcode(TCCState *s1, पूर्णाङ्क token) {
    uint8_t coprocessor;
    Operand opcode1;
    Operand opcode2;
    uint8_t registers[3];
    unsigned पूर्णाङ्क i;
    uint8_t उच्चः_nibble;
    uint8_t mrc = 0;

    सचे (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } अञ्ञथा {
        expect("'p<number>'");
    }
    skip(',');
    parse_operand(s1, &opcode1);
    सचे (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, रिक्त));
    }

    अत्थाय (i = 0; i < 3; ++i) {
        skip(',');
        सचे (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mcreq)) {
            सचे (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                next();
            } अञ्ञथा {
                expect("'r<number>'");
            }
        } अञ्ञथा {
            सचे (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                next();
            } अञ्ञथा {
                expect("'c<number>'");
            }
        }
    }
    सचे (tok == ',') {
        next();
        parse_operand(s1, &opcode2);
    } अञ्ञथा {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    सचे (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, रिक्त));
    }

    सचे (token == TOK_ASM_cdp2) {
        उच्चः_nibble = 0xF;
        asm_emit_coprocessor_opcode(उच्चः_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        पटिनिवत्त;
    } अञ्ञथा
        उच्चः_nibble = condition_code_of_token(token);

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(उच्चः_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        भङ्ग;
    पक्ष TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    पक्ष TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        सचे (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, रिक्त));
        }
        asm_emit_coprocessor_opcode(उच्चः_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        भङ्ग;
    स्वभाव:
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
#define ENCODE_BARREL_SHIFTER_IMMEDIATE(मानम्) ((मानम्) << 7)

स्थिर शून्य asm_block_data_transfer_opcode(TCCState *s1, पूर्णाङ्क token)
{
    uint32_t opcode;
    पूर्णाङ्क op0_exclam = 0;
    Operand ops[2];
    पूर्णाङ्क nb_ops = 1;
    parse_operand(s1, &ops[0]);
    सचे (tok == '!') {
        op0_exclam = 1;
        next(); // skip '!'
    }
    सचे (tok == ',') {
        next(); // skip comma
        parse_operand(s1, &ops[1]);
        ++nb_ops;
    }
    सचे (nb_ops < 1) {
        expect("at least one operand");
    } अञ्ञथा सचे (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        सचे (nb_ops != 1)
            expect("exactly one operand");
        अञ्ञथा
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        भङ्ग;
    पक्ष TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        सचे (nb_ops != 1)
            expect("exactly one operand");
        अञ्ञथा
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        भङ्ग;
    पक्ष TOK_ASM_stmdaeq:
    पक्ष TOK_ASM_ldmdaeq:
    पक्ष TOK_ASM_stmeq:
    पक्ष TOK_ASM_ldmeq:
    पक्ष TOK_ASM_stmiaeq:
    पक्ष TOK_ASM_ldmiaeq:
    पक्ष TOK_ASM_stmdbeq:
    पक्ष TOK_ASM_ldmdbeq:
    पक्ष TOK_ASM_stmibeq:
    पक्ष TOK_ASM_ldmibeq:
        विकल्प (ARM_INSTRUCTION_GROUP(token)) {
        पक्ष TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            भङ्ग;
        पक्ष TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            भङ्ग;
        पक्ष TOK_ASM_stmeq: // post-increment store
        पक्ष TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            भङ्ग;
        पक्ष TOK_ASM_ldmeq: // post-increment load
        पक्ष TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            भङ्ग;
        पक्ष TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            भङ्ग;
        पक्ष TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            भङ्ग;
        पक्ष TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            भङ्ग;
        पक्ष TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            भङ्ग;
        स्वभाव:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        सचे (nb_ops != 2)
            expect("exactly two operands");
        अञ्ञथा सचे (ops[0].type != OP_REG32)
            expect("(first operand) register");
        अञ्ञथा {
            सचे (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        भङ्ग;
    स्वभाव:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
स्थिर uint32_t asm_parse_optional_shift(TCCState* s1, पूर्णाङ्क* nb_shift, Operand* shift)
{
    uint32_t opcode = 0;
    *nb_shift = 0;
    विकल्प (tok) {
    पक्ष TOK_ASM_asl:
    पक्ष TOK_ASM_lsl:
    पक्ष TOK_ASM_asr:
    पक्ष TOK_ASM_lsr:
    पक्ष TOK_ASM_ror:
        विकल्प (tok) {
        पक्ष TOK_ASM_asl:
            /* fallthrough */
        पक्ष TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSL;
            भङ्ग;
        पक्ष TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ASR;
            भङ्ग;
        पक्ष TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSR;
            भङ्ग;
        पक्ष TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
            भङ्ग;
        }
        next();
        parse_operand(s1, shift);
        *nb_shift = 1;
        भङ्ग;
    पक्ष TOK_ASM_rrx:
        next();
        opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
        भङ्ग;
    }
    पटिनिवत्त opcode;
}

स्थिर uint32_t asm_encode_shift(Operand* shift)
{
    uint64_t amount;
    uint32_t operands = 0;
    विकल्प (shift->type) {
    पक्ष OP_REG32:
        सचे (shift->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        अञ्ञथा {
            operands = ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER;
            operands |= ENCODE_BARREL_SHIFTER_REGISTER(shift->reg);
        }
        भङ्ग;
    पक्ष OP_IM8:
        amount = shift->e.v;
        सचे (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_IMMEDIATE(amount);
        अञ्ञथा
            tcc_error("shift count out of range");
        भङ्ग;
    स्वभाव:
        tcc_error("unknown shift amount");
    }
    पटिनिवत्त operands;
}

स्थिर शून्य asm_data_processing_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[3];
    पूर्णाङ्क nb_ops;
    Operand shift = {0};
    पूर्णाङ्क nb_shift = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_GROUP(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    अत्थाय (nb_ops = 0; nb_ops < परिमाण(ops)/परिमाण(ops[0]); ) {
        सचे (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            भङ्ग;
        parse_operand(s1, &ops[nb_ops]);
        ++nb_ops;
        सचे (tok != ',')
            भङ्ग;
        next(); // skip ','
    }
    सचे (tok == ',')
        next();
    operands |= asm_parse_optional_shift(s1, &nb_shift, &shift);
    सचे (nb_ops < 2)
        expect("at least two operands");
    अञ्ञथा सचे (nb_ops == 2) {
        memcpy(&ops[2], &ops[1], परिमाण(ops[1])); // move ops[2]
        memcpy(&ops[1], &ops[0], परिमाण(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } अञ्ञथा सचे (nb_ops == 3) {
        सचे (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, रिक्त));
        }
    }
    सचे (nb_ops != 3) {
        expect("two or three operands");
    } अञ्ञथा {
        uint32_t opcode = 0;
        uint32_t immediate_मानम्;
        uint8_t half_immediate_rotation;
        सचे (nb_shift && shift.type == OP_REG32) {
            सचे ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
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
        सचे (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        अञ्ञथा सचे (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_SET_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        अञ्ञथा
            operands |= ENCODE_RD(ops[0].reg);
        सचे (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        अञ्ञथा सचे (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        विकल्प (ops[2].type) {
        पक्ष OP_REG32:
            operands |= ops[2].reg;
            भङ्ग;
        पक्ष OP_IM8:
        पक्ष OP_IM32:
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_मानम् = ops[2].e.v;
            अत्थाय (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                सचे (immediate_मानम् >= 0x00 && immediate_मानम् < 0x100)
                    भङ्ग;
                // rotate left by two
                immediate_मानम् = ((immediate_मानम् & 0x3FFFFFFF) << 2) | ((immediate_मानम् & 0xC0000000) >> 30);
            }
            सचे (half_immediate_rotation >= 16) {
                /* fallthrough */
            } अञ्ञथा {
                operands |= immediate_मानम्;
                operands |= half_immediate_rotation << 8;
                भङ्ग;
            }
        पक्ष OP_IM8N: // immediate negative value
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_मानम् = ops[2].e.v;
            /* Instruction swapping:
               0001 = EOR - Rd:= Op1 EOR Op2     -> difficult
               0011 = RSB - Rd:= Op2 - Op1       -> difficult
               0111 = RSC - Rd:= Op2 - Op1 + C   -> difficult
               1000 = TST - CC on: Op1 AND Op2   -> difficult
               1001 = TEQ - CC on: Op1 EOR Op2   -> difficult
               1100 = ORR - Rd:= Op1 OR Op2      -> difficult
            */
            विकल्प (opcode_nos) {
            पक्ष 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                immediate_मानम् = ~immediate_मानम्;
                भङ्ग;
            पक्ष 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; // ADD
                immediate_मानम् = -immediate_मानम्;
                भङ्ग;
            पक्ष 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                immediate_मानम् = -immediate_मानम्;
                भङ्ग;
            पक्ष 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                immediate_मानम् = ~immediate_मानम्;
                भङ्ग;
            पक्ष 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                immediate_मानम् = ~immediate_मानम्;
                भङ्ग;
            पक्ष 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                immediate_मानम् = -immediate_मानम्;
                भङ्ग;
            पक्ष 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                immediate_मानम् = -immediate_मानम्;
                भङ्ग;
            पक्ष 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                immediate_मानम् = ~immediate_मानम्;
                भङ्ग;
            पक्ष 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                immediate_मानम् = ~immediate_मानम्;
                भङ्ग;
            पक्ष 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                immediate_मानम् = ~immediate_मानम्;
                भङ्ग;
            स्वभाव:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, रिक्त));
            }
            अत्थाय (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                सचे (immediate_मानम् >= 0x00 && immediate_मानम् < 0x100)
                    भङ्ग;
                // rotate left by two
                immediate_मानम् = ((immediate_मानम् & 0x3FFFFFFF) << 2) | ((immediate_मानम् & 0xC0000000) >> 30);
            }
            सचे (half_immediate_rotation >= 16) {
                immediate_मानम् = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (unsigned) immediate_मानम्);
            }
            operands |= immediate_मानम्;
            operands |= half_immediate_rotation << 8;
            भङ्ग;
        स्वभाव:
            expect("(second source operand) register or immediate value");
        }

        सचे (nb_shift) {
            सचे (operands & ENCODE_IMMEDIATE_FLAG)
                tcc_error("immediate rotation not implemented");
            अञ्ञथा
                operands |= asm_encode_shift(&shift);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_SET_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

स्थिर शून्य asm_shift_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[3];
    पूर्णाङ्क nb_ops;
    पूर्णाङ्क definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    अत्थाय (nb_ops = 0; nb_ops < परिमाण(ops)/परिमाण(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        सचे (tok != ',') {
            ++nb_ops;
            भङ्ग;
        }
        next(); // skip ','
    }
    सचे (nb_ops < 2) {
        expect("at least two operands");
    }

    सचे (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } अञ्ञथा
        operands |= ENCODE_RD(ops[0].reg);

    सचे (nb_ops == 2) {
        विकल्प (ARM_INSTRUCTION_GROUP(token)) {
        पक्ष TOK_ASM_rrxseq:
            opcode |= ENCODE_SET_CONDITION_CODES;
            /* fallthrough */
        पक्ष TOK_ASM_rrxeq:
            सचे (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
                asm_emit_opcode(token, opcode | operands);
            } अञ्ञथा
                tcc_error("(first source operand) register");
            पटिनिवत्त;
        स्वभाव:
            memcpy(&ops[2], &ops[1], परिमाण(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], परिमाण(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    सचे (nb_ops != 3) {
        expect("two or three operands");
    }

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_lslseq:
    पक्ष TOK_ASM_lsrseq:
    पक्ष TOK_ASM_asrseq:
    पक्ष TOK_ASM_rorseq:
        opcode |= ENCODE_SET_CONDITION_CODES;
        भङ्ग;
    }

    विकल्प (ops[1].type) {
    पक्ष OP_REG32:
        operands |= ops[1].reg;
        भङ्ग;
    पक्ष OP_IM8:
        operands |= ENCODE_IMMEDIATE_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, रिक्त));
    }

    विकल्प (ops[2].type) {
    पक्ष OP_REG32:
        सचे ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_shift(&ops[2]);
        भङ्ग;
    पक्ष OP_IM8:
        सचे (ops[2].e.v)
            operands |= asm_encode_shift(&ops[2]);
        अञ्ञथा
            definitely_neutral = 1;
        भङ्ग;
    }

    सचे (!definitely_neutral) विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_lslseq:
    पक्ष TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSL;
        भङ्ग;
    पक्ष TOK_ASM_lsrseq:
    पक्ष TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSR;
        भङ्ग;
    पक्ष TOK_ASM_asrseq:
    पक्ष TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ASR;
        भङ्ग;
    पक्ष TOK_ASM_rorseq:
    पक्ष TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
        भङ्ग;
    स्वभाव:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

स्थिर शून्य asm_multiplication_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[4];
    पूर्णाङ्क nb_ops = 0;
    uint32_t opcode = 0x90;

    अत्थाय (nb_ops = 0; nb_ops < परिमाण(ops)/परिमाण(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        सचे (tok != ',') {
            ++nb_ops;
            भङ्ग;
        }
        next(); // skip ','
    }
    सचे (nb_ops < 2)
        expect("at least two operands");
    अञ्ञथा सचे (nb_ops == 2) {
        विकल्प (ARM_INSTRUCTION_GROUP(token)) {
        पक्ष TOK_ASM_mulseq:
        पक्ष TOK_ASM_muleq:
            memcpy(&ops[2], &ops[0], परिमाण(ops[1])); // ARM is actually like this!
            भङ्ग;
        स्वभाव:
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

    सचे (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    अञ्ञथा
        expect("(destination operand) register");
    सचे (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    अञ्ञथा
        expect("(first source operand) register");
    सचे (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    अञ्ञथा
        expect("(second source operand) register");
    सचे (nb_ops > 3) {
        सचे (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        अञ्ञथा
            expect("(third source operand) register");
    }

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_mulseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    पक्ष TOK_ASM_muleq:
        सचे (nb_ops != 3)
            expect("three operands");
        अञ्ञथा {
            asm_emit_opcode(token, opcode);
        }
        भङ्ग;
    पक्ष TOK_ASM_mlaseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    पक्ष TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        सचे (nb_ops != 4)
            expect("four operands");
        अञ्ञथा {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        भङ्ग;
    पक्ष TOK_ASM_mlseq:
        opcode |= 0x00400000;
        गच्छ case_TOK_ASM_mlaeq;
    पक्ष TOK_ASM_udiveq:
        opcode |= 0x00200000;
    पक्ष TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        भङ्ग;
    स्वभाव:
        expect("known multiplication instruction");
    }
}

स्थिर शून्य asm_long_multiplication_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[4];
    पूर्णाङ्क nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    अत्थाय (nb_ops = 0; nb_ops < परिमाण(ops)/परिमाण(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        सचे (tok != ',') {
            ++nb_ops;
            भङ्ग;
        }
        next(); // skip ','
    }
    सचे (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    सचे (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    अञ्ञथा
        expect("(destination lo accumulator) register");
    सचे (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    अञ्ञथा
        expect("(destination hi accumulator) register");
    सचे (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    अञ्ञथा
        expect("(first source operand) register");
    सचे (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    अञ्ञथा
        expect("(second source operand) register");

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_smullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    पक्ष TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_umullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    पक्ष TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_smlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    पक्ष TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_umlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    पक्ष TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        भङ्ग;
    स्वभाव:
        expect("known long multiplication instruction");
    }
}

स्थिर शून्य asm_single_data_transfer_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[3];
    Operand strex_operand;
    Operand shift;
    पूर्णाङ्क nb_shift = 0;
    पूर्णाङ्क exclam = 0;
    पूर्णाङ्क closed_bracket = 0;
    पूर्णाङ्क op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    सचे (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    अञ्ञथा {
        expect("(destination operand) register");
    }
    सचे (tok != ',')
        expect("at least two arguments");
    next(); // skip ','

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_strexheq:
    पक्ष TOK_ASM_strexbeq:
    पक्ष TOK_ASM_strexeq:
        parse_operand(s1, &strex_operand);
        सचे (strex_operand.type != OP_REG32) {
            expect("register");
        }
        सचे (tok != ',')
            expect("at least three arguments");
        अञ्ञथा
            next(); // skip ','
        भङ्ग;
    }

    skip('[');
    parse_operand(s1, &ops[1]);
    सचे (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    अञ्ञथा {
        expect("(first source operand) register");
    }
    सचे (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    सचे (tok == ',') {
        next(); // skip ','
        सचे (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        सचे (ops[2].type == OP_REG32) {
            सचे (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, रिक्त));
            }
            सचे (tok == ',') {
                next();
                opcode |= asm_parse_optional_shift(s1, &nb_shift, &shift);
                सचे (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } अञ्ञथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    सचे (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        सचे (tok == '!') {
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
    सचे (exclam)
        opcode |= 1 << 21; // write offset back into register

    सचे (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        पूर्णाङ्क v = ops[2].e.v;
        सचे (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        सचे (v >= 0) {
            opcode |= 1 << 23; // up
            सचे (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, रिक्त));
            अञ्ञथा
                opcode |= v;
        } अञ्ञथा { // down
            सचे (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, रिक्त));
            अञ्ञथा
                opcode |= -v;
        }
    } अञ्ञथा सचे (ops[2].type == OP_REG32) {
        सचे (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } अञ्ञथा
        expect("register");

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    पक्ष TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        सचे (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    पक्ष TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        सचे (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_strexheq:
        opcode |= 1 << 21;
    पक्ष TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    पक्ष TOK_ASM_strexeq:
        सचे ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } अञ्ञथा सचे (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        सचे ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_operand.reg;
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    पक्ष TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    पक्ष TOK_ASM_ldrexeq:
        सचे ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } अञ्ञथा सचे (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        सचे ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        भङ्ग;
    स्वभाव:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
स्थिर शून्य asm_emit_coprocessor_data_transfer(uint32_t उच्चः_nibble, uint8_t cp_सङ्ख्या, uint8_t CRd, ध्रुव Operand* Rn, ध्रुव Operand* offset, पूर्णाङ्क offset_minus, पूर्णाङ्क preincrement, पूर्णाङ्क writeback, पूर्णाङ्क long_transfer, पूर्णाङ्क load) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    सचे (long_transfer)
        opcode |= 1 << 22; // long transfer

    सचे (load)
        opcode |= 1 << 20; // L

    opcode |= cp_सङ्ख्या << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    सचे (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    सचे (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    सचे (writeback)
        opcode |= 1 << 21; // write offset back into register

    सचे (offset->type == OP_IM8 || offset->type == OP_IM8N || offset->type == OP_IM32) {
        पूर्णाङ्क v = offset->e.v;
        सचे (offset_minus)
            tcc_error("minus before '#' not supported for immediate values");
        सचे (offset->type == OP_IM8N || v < 0)
            v = -v;
        अञ्ञथा
            opcode |= 1 << 23; // up
        सचे (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        सचे (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } अञ्ञथा सचे (offset->type == OP_REG32) {
        सचे (!offset_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= offset->reg;
        tcc_error("Using register offset to register address is not possible here");
    } अञ्ञथा सचे (offset->type == OP_VREG64) {
        opcode |= 16;
        opcode |= offset->reg;
    } अञ्ञथा
        expect("immediate or register");

    asm_emit_unconditional_opcode((उच्चः_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
स्थिर शून्य asm_coprocessor_data_transfer_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_register;
    पूर्णाङ्क preincrement = 0;
    पूर्णाङ्क exclam = 0;
    पूर्णाङ्क closed_bracket = 0;
    पूर्णाङ्क op2_minus = 0;
    पूर्णाङ्क long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    सचे (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } अञ्ञथा {
        expect("'c<number>'");
    }

    skip(',');

    सचे (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_register = tok - TOK_ASM_c0;
        next();
    } अञ्ञथा {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    सचे (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    सचे (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    सचे (tok == ',') {
        next(); // skip ','
        सचे (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        सचे (ops[2].type == OP_REG32) {
            सचे (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, रिक्त));
            }
        } अञ्ञथा सचे (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, रिक्त));
        }
    } अञ्ञथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    सचे (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        सचे (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    // TODO: Support options.

    सचे (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        विकल्प (token) {
        पक्ष TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        पक्ष TOK_ASM_ldc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            भङ्ग;
        पक्ष TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        पक्ष TOK_ASM_stc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            भङ्ग;
        }
    } अञ्ञथा विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    पक्ष TOK_ASM_stceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        भङ्ग;
    पक्ष TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    पक्ष TOK_ASM_ldceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        भङ्ग;
    स्वभाव:
        expect("coprocessor data transfer instruction");
    }
}

#सचे defined(TCC_ARM_VFP)
#define CP_SINGLE_PRECISION_FLOAT 10
#define CP_DOUBLE_PRECISION_FLOAT 11

स्थिर शून्य asm_floating_point_single_data_transfer_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_register = 0;
    पूर्णाङ्क long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    सचे (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        long_transfer = coprocessor_destination_register & 1;
        coprocessor_destination_register >>= 1;
    } अञ्ञथा सचे (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        next();
    } अञ्ञथा {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    सचे (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    सचे (tok == ',') {
        next(); // skip ','
        parse_operand(s1, &ops[2]);
        सचे (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } अञ्ञथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vldreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        भङ्ग;
    पक्ष TOK_ASM_vstreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        भङ्ग;
    स्वभाव:
        expect("floating point data transfer instruction");
    }
}

स्थिर शून्य asm_floating_point_block_data_transfer_opcode(TCCState *s1, पूर्णाङ्क token)
{
    uint8_t coprocessor = 0;
    पूर्णाङ्क first_regset_register;
    पूर्णाङ्क last_regset_register;
    uint8_t regset_item_गणनम्;
    uint8_t extra_register_bit = 0;
    पूर्णाङ्क op0_exclam = 0;
    पूर्णाङ्क load = 0;
    पूर्णाङ्क preincrement = 0;
    Operand ops[1];
    Operand offset;
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vpusheq:
    पक्ष TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        भङ्ग;
    स्वभाव:
        parse_operand(s1, &ops[0]);
        सचे (tok == '!') {
            op0_exclam = 1;
            next(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    first_regset_register = asm_parse_vfp_regvar(tok, 1);
    सचे ((first_regset_register = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        next();
    } अञ्ञथा सचे ((first_regset_register = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        next();
    } अञ्ञथा {
        expect("floating-point register");
    }

    सचे (tok == '-') {
        next();
        सचे ((last_regset_register = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            next();
        अञ्ञथा {
            expect("floating-point register");
        }
    } अञ्ञथा
        last_regset_register = first_regset_register;

    सचे (last_regset_register < first_regset_register) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_item_गणनम् = last_regset_register - first_regset_register + 1;
    सचे (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_item_गणनम् <<= 1;
    अञ्ञथा {
        extra_register_bit = first_regset_register & 1;
        first_regset_register >>= 1;
    }
    offset.type = OP_IM8;
    offset.e.v = regset_item_गणनम् << 2;
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vstmeq: // post-increment store
    पक्ष TOK_ASM_vstmiaeq: // post-increment store
        भङ्ग;
    पक्ष TOK_ASM_vpopeq:
    पक्ष TOK_ASM_vldmeq: // post-increment load
    पक्ष TOK_ASM_vldmiaeq: // post-increment load
        load = 1;
        भङ्ग;
    पक्ष TOK_ASM_vldmdbeq: // pre-decrement load
        load = 1;
        /* fallthrough */
    पक्ष TOK_ASM_vpusheq:
    पक्ष TOK_ASM_vstmdbeq: // pre-decrement store
        offset.type = OP_IM8N;
        offset.e.v = -offset.e.v;
        preincrement = 1;
        भङ्ग;
    स्वभाव:
        expect("floating point block data transfer instruction");
    }
    सचे (ops[0].type != OP_REG32)
        expect("(first operand) register");
    अञ्ञथा सचे (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
    अञ्ञथा सचे (!op0_exclam && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, रिक्त));
    अञ्ञथा
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, first_regset_register, &ops[0], &offset, 0, preincrement, op0_exclam, extra_register_bit, load);
}

#define VMOV_FRACTIONAL_DIGITS 7
#define VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

स्थिर uint32_t vmov_parse_fractional_part(ध्रुव वर्ण* s)
{
    uint32_t result = 0;
    पूर्णाङ्क i;
    अत्थाय (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        वर्ण c = *s;
        result *= 10;
        सचे (c >= '0' && c <= '9') {
            result += (c - '0');
            ++s;
        }
    }
    सचे (*s)
        expect("decimal numeral");
    पटिनिवत्त result;
}

स्थिर पूर्णाङ्क vmov_linear_approx_index(uint32_t beginning, uint32_t end, uint32_t मानम्)
{
    पूर्णाङ्क i;
    uint32_t k;
    uint32_t xvalue;

    k = (end - beginning)/16;
    अत्थाय (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        सचे (मानम् == xvalue)
            पटिनिवत्त i;
    }
    //assert(0);
    पटिनिवत्त -1;
}

स्थिर uint32_t vmov_parse_immediate_मानम्() {
    uint32_t मानम्;
    unsigned long integral_मानम्;
    ध्रुव वर्ण *p;

    सचे (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.data;
    errno = 0;
    integral_मानम् = strtoul(p, (वर्ण **)&p, 0);

    सचे (errno || integral_मानम् >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    मानम् = (uint32_t) integral_मानम् * VMOV_ONE;
    सचे (*p == '.') {
        ++p;
        मानम् += vmov_parse_fractional_part(p);
    }
    next();
    पटिनिवत्त मानम्;
}

स्थिर uint8_t vmov_encode_immediate_मानम्(uint32_t मानम्)
{
    uint32_t limit;
    uint32_t end = 0;
    uint32_t beginning = 0;
    पूर्णाङ्क r = -1;
    पूर्णाङ्क n;
    पूर्णाङ्क i;

    limit = 32 * VMOV_ONE;
    अत्थाय (i = 0; i < 8; ++i) {
        सचे (मानम् < limit) {
            end = limit;
            limit >>= 1;
            beginning = limit;
            r = i;
        } अञ्ञथा
            limit >>= 1;
    }
    सचे (r == -1 || मानम् < beginning || मानम् > end) {
        tcc_error("invalid decimal number for vmov: %d", मानम्);
    }
    n = vmov_linear_approx_index(beginning, end, मानम्);
    पटिनिवत्त n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
स्थिर शून्य asm_floating_point_immediate_data_processing_opcode_tail(TCCState *s1, पूर्णाङ्क token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t immediate_मानम् = 0;
    पूर्णाङ्क op_minus = 0;
    uint8_t code;

    operands[0] = CRd;

    सचे (tok == '#' || tok == '$') {
        next();
    }
    सचे (tok == '-') {
        op_minus = 1;
        next();
    }
    immediate_मानम् = vmov_parse_immediate_मानम्();

    opcode1 = 11; // "Other" instruction
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vcmpeq_f32:
    पक्ष TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        सचे (immediate_मानम्) {
            expect("Immediate value 0");
        }
        भङ्ग;
    पक्ष TOK_ASM_vcmpeeq_f32:
    पक्ष TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        सचे (immediate_मानम्) {
            expect("Immediate value 0");
        }
        भङ्ग;
    पक्ष TOK_ASM_vmoveq_f32:
    पक्ष TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        सचे (op_minus)
            operands[1] = 0x8;
        अञ्ञथा
            operands[1] = 0x0;
        code = vmov_encode_immediate_मानम्(immediate_मानम्);
        operands[1] |= code >> 4;
        operands[2] = code & 0xF;
        भङ्ग;
    स्वभाव:
        expect("known floating point with immediate instruction");
    }

    सचे (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        सचे (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

स्थिर शून्य asm_floating_point_reg_arm_reg_transfer_opcode_tail(TCCState *s1, पूर्णाङ्क token, पूर्णाङ्क coprocessor, पूर्णाङ्क nb_arm_regs, पूर्णाङ्क nb_ops, Operand ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    विकल्प (coprocessor) {
    पक्ष CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        सचे (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        सचे (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            memcpy(&ops[2], &ops[1], परिमाण(ops[2]));
            memcpy(&ops[1], &ops[0], परिमाण(ops[1]));
            memcpy(&ops[0], &ops[2], परिमाण(ops[0]));
        } अञ्ञथा
            opcode1 |= 1;

        सचे (ops[1].type == OP_VREG32) {
            सचे (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        सचे (ops[0].type == OP_VREG32) {
            सचे (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        भङ्ग;
    पक्ष CP_DOUBLE_PRECISION_FLOAT:
        सचे (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        सचे (ops[0].type == OP_VREG64) {
            सचे (ops[2].type == OP_REG32) {
                Operand temp;
                // need to rotate operand list to the left
                memcpy(&temp, &ops[0], परिमाण(temp));
                memcpy(&ops[0], &ops[1], परिमाण(ops[0]));
                memcpy(&ops[1], &ops[2], परिमाण(ops[1]));
                memcpy(&ops[2], &temp, परिमाण(ops[2]));
            } अञ्ञथा {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } अञ्ञथा सचे (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } अञ्ञथा {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        भङ्ग;
    स्वभाव:
        tcc_internal_error("unknown coprocessor");
    }
}

स्थिर शून्य asm_floating_point_vcvt_data_processing_opcode(TCCState *s1, पूर्णाङ्क token) {
    uint8_t coprocessor = 0;
    Operand ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vcvtreq_s32_f64:
    पक्ष TOK_ASM_vcvtreq_u32_f64:
    पक्ष TOK_ASM_vcvteq_s32_f64:
    पक्ष TOK_ASM_vcvteq_u32_f64:
    पक्ष TOK_ASM_vcvteq_f64_s32:
    पक्ष TOK_ASM_vcvteq_f64_u32:
    पक्ष TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       भङ्ग;
    पक्ष TOK_ASM_vcvtreq_s32_f32:
    पक्ष TOK_ASM_vcvtreq_u32_f32:
    पक्ष TOK_ASM_vcvteq_s32_f32:
    पक्ष TOK_ASM_vcvteq_u32_f32:
    पक्ष TOK_ASM_vcvteq_f32_s32:
    पक्ष TOK_ASM_vcvteq_f32_u32:
    पक्ष TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       भङ्ग;
    स्वभाव:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, रिक्त));
    }

    parse_operand(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vcvtreq_s32_f32:
    पक्ष TOK_ASM_vcvtreq_s32_f64:
    पक्ष TOK_ASM_vcvteq_s32_f32:
    पक्ष TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    पक्ष TOK_ASM_vcvteq_u32_f32:
    पक्ष TOK_ASM_vcvteq_u32_f64:
    पक्ष TOK_ASM_vcvtreq_u32_f32:
    पक्ष TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        भङ्ग;
    /* floating-point size conversion */
    पक्ष TOK_ASM_vcvteq_f64_f32:
    पक्ष TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        भङ्ग;
    }

    skip(',');
    parse_operand(s1, &ops[2]);

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    /* floating-point -> integer */
    पक्ष TOK_ASM_vcvteq_s32_f32:
    पक्ष TOK_ASM_vcvteq_s32_f64:
    पक्ष TOK_ASM_vcvteq_u32_f32:
    पक्ष TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        भङ्ग;

    /* integer -> floating-point */
    पक्ष TOK_ASM_vcvteq_f64_s32:
    पक्ष TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        भङ्ग;

    /* floating-point size conversion */
    पक्ष TOK_ASM_vcvteq_f64_f32:
    पक्ष TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        भङ्ग;
    }

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vcvteq_f64_u32:
    पक्ष TOK_ASM_vcvteq_f64_s32:
    पक्ष TOK_ASM_vcvteq_f64_f32:
        सचे (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } अञ्ञथा {
            expect("d<number>, s<number>");
        }
        भङ्ग;
    स्वभाव:
        सचे (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            सचे (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } अञ्ञथा {
                expect("s<number>, s<number>");
            }
        } अञ्ञथा सचे (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            सचे (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } अञ्ञथा {
                expect("s<number>, d<number>");
            }
        }
    }

    सचे (ops[2].type == OP_VREG32) {
        सचे (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    सचे (ops[0].type == OP_VREG32) {
        सचे (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

स्थिर शून्य asm_floating_point_data_processing_opcode(TCCState *s1, पूर्णाङ्क token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    Operand ops[3];
    uint8_t nb_ops = 0;
    पूर्णाङ्क vmov = 0;
    पूर्णाङ्क nb_arm_regs = 0;

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

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vmlaeq_f64:
    पक्ष TOK_ASM_vmlseq_f64:
    पक्ष TOK_ASM_vnmlseq_f64:
    पक्ष TOK_ASM_vnmlaeq_f64:
    पक्ष TOK_ASM_vmuleq_f64:
    पक्ष TOK_ASM_vnmuleq_f64:
    पक्ष TOK_ASM_vaddeq_f64:
    पक्ष TOK_ASM_vsubeq_f64:
    पक्ष TOK_ASM_vdiveq_f64:
    पक्ष TOK_ASM_vnegeq_f64:
    पक्ष TOK_ASM_vabseq_f64:
    पक्ष TOK_ASM_vsqrteq_f64:
    पक्ष TOK_ASM_vcmpeq_f64:
    पक्ष TOK_ASM_vcmpeeq_f64:
    पक्ष TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vmoveq_f32:
    पक्ष TOK_ASM_vmoveq_f64:
        vmov = 1;
        भङ्ग;
    }

    अत्थाय (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        सचे (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_point_immediate_data_processing_opcode_tail(s1, token, coprocessor, ops[0].reg);
            पटिनिवत्त;
        }
        parse_operand(s1, &ops[nb_ops]);
        सचे (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } अञ्ञथा सचे (ops[nb_ops].type == OP_VREG32) {
            सचे (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } अञ्ञथा सचे (ops[nb_ops].type == OP_VREG64) {
            सचे (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } अञ्ञथा {
            expect("floating point register");
        }
        ++nb_ops;
        सचे (tok == ',')
            next();
        अञ्ञथा
            भङ्ग;
    }

    सचे (nb_arm_regs == 0) {
        सचे (nb_ops == 2) { // implicit
            memcpy(&ops[2], &ops[1], परिमाण(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], परिमाण(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        सचे (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, रिक्त), nb_ops);
        }
    }

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vmlaeq_f32:
    पक्ष TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        भङ्ग;
    पक्ष TOK_ASM_vmlseq_f32:
    पक्ष TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        भङ्ग;
    पक्ष TOK_ASM_vnmlseq_f32:
    पक्ष TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        भङ्ग;
    पक्ष TOK_ASM_vnmlaeq_f32:
    पक्ष TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        भङ्ग;
    पक्ष TOK_ASM_vmuleq_f32:
    पक्ष TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        भङ्ग;
    पक्ष TOK_ASM_vnmuleq_f32:
    पक्ष TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        भङ्ग;
    पक्ष TOK_ASM_vaddeq_f32:
    पक्ष TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        भङ्ग;
    पक्ष TOK_ASM_vsubeq_f32:
    पक्ष TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        भङ्ग;
    पक्ष TOK_ASM_vdiveq_f32:
    पक्ष TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        भङ्ग;
    पक्ष TOK_ASM_vnegeq_f32:
    पक्ष TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        भङ्ग;
    पक्ष TOK_ASM_vabseq_f32:
    पक्ष TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        भङ्ग;
    पक्ष TOK_ASM_vsqrteq_f32:
    पक्ष TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        भङ्ग;
    पक्ष TOK_ASM_vcmpeq_f32:
    पक्ष TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        भङ्ग;
    पक्ष TOK_ASM_vcmpeeq_f32:
    पक्ष TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        भङ्ग;
    पक्ष TOK_ASM_vmoveq_f32:
    पक्ष TOK_ASM_vmoveq_f64:
        सचे (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_point_reg_arm_reg_transfer_opcode_tail(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            पटिनिवत्त;
        } अञ्ञथा {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        भङ्ग;
    स्वभाव:
        expect("known floating point instruction");
    }

    सचे (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        सचे (ops[2].type == OP_VREG32) {
            सचे (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        सचे (ops[1].type == OP_VREG32) {
            सचे (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        सचे (ops[0].type == OP_VREG32) {
            सचे (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

स्थिर पूर्णाङ्क asm_parse_vfp_status_regvar(पूर्णाङ्क t)
{
    विकल्प (t) {
    पक्ष TOK_ASM_fpsid:
        पटिनिवत्त 0;
    पक्ष TOK_ASM_fpscr:
        पटिनिवत्त 1;
    पक्ष TOK_ASM_fpexc:
        पटिनिवत्त 8;
    स्वभाव:
        पटिनिवत्त -1;
    }
}

स्थिर शून्य asm_floating_point_status_register_opcode(TCCState* s1, पूर्णाङ्क token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    पूर्णाङ्क vfp_sys_reg = -1;
    Operand arm_operand;
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vmrseq:
        opcode = 0xf;
        सचे (tok == TOK_ASM_apsr_nzcv) {
            arm_operand.type = OP_REG32;
            arm_operand.reg = 15; // not PC
            next(); // skip apsr_nzcv
        } अञ्ञथा {
            parse_operand(s1, &arm_operand);
            सचे (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        सचे (arm_operand.type == OP_REG32 && arm_operand.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, रिक्त));
        }
        भङ्ग;
    पक्ष TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        skip(',');
        parse_operand(s1, &arm_operand);
        सचे (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
        }
        भङ्ग;
    स्वभाव:
        expect("floating point status register instruction");
    }
    सचे (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    सचे (arm_operand.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode, arm_operand.reg, vfp_sys_reg, 0x10, 0, 0);
}

#endif

स्थिर शून्य asm_misc_single_data_transfer_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[3];
    पूर्णाङ्क exclam = 0;
    पूर्णाङ्क closed_bracket = 0;
    पूर्णाङ्क op2_minus = 0;
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
    सचे (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    अञ्ञथा {
        expect("(destination operand) register");
    }
    सचे (tok != ',')
        expect("at least two arguments");
    अञ्ञथा
        next(); // skip ','
    skip('[');
    parse_operand(s1, &ops[1]);
    सचे (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    अञ्ञथा {
        expect("(first source operand) register");
    }
    सचे (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    सचे (tok == ',') {
        next(); // skip ','
        सचे (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
    } अञ्ञथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    सचे (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        सचे (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    सचे (exclam) {
        सचे ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, रिक्त));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    सचे (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        पूर्णाङ्क v = ops[2].e.v;
        सचे (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        सचे (v >= 0) {
            opcode |= 1 << 23; // up
            सचे (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, रिक्त));
            अञ्ञथा {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } अञ्ञथा { // down
            सचे (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, रिक्त));
            अञ्ञथा {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } अञ्ञथा सचे (ops[2].type == OP_REG32) {
        सचे (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ops[2].reg;
    } अञ्ञथा
        expect("register");

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    पक्ष TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        भङ्ग;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
स्थिर uint32_t encbranchoffset(पूर्णाङ्क pos, पूर्णाङ्क addr, पूर्णाङ्क fail)
{
  addr-=pos+8;
  addr/=4;
  सचे(addr>=0x7fffff || addr<-0x800000) {
    सचे(fail)
      tcc_error("branch offset is too far");
    पटिनिवत्त 0;
  }
  पटिनिवत्त /*not 0x0A000000|*/(addr&0xffffff);
}

स्थिर शून्य asm_branch_opcode(TCCState *s1, पूर्णाङ्क token)
{
    पूर्णाङ्क jmp_disp = 0;
    Operand op;
    व्यञ्जकम्_मानम् e;
    ElfSym *esym;

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_beq:
    पक्ष TOK_ASM_bleq:
        asm_व्यञ्जकम्(s1, &e);
        सचे (e.sym) {
            esym = elfsym(e.sym);
            सचे (esym && esym->st_shndx == cur_text_section->sh_अङ्कः) {
                jmp_disp = esym->st_मानम्;
            } अञ्ञथा {
                greloca(cur_text_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        भङ्ग;
    स्वभाव:
        parse_operand(s1, &op);
        भङ्ग;
    }
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        भङ्ग;
    पक्ष TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        भङ्ग;
    पक्ष TOK_ASM_bxeq:
        सचे (op.type != OP_REG32)
            expect("register");
        अञ्ञथा
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        भङ्ग;
    पक्ष TOK_ASM_blxeq:
        सचे (op.type != OP_REG32)
            expect("register");
        अञ्ञथा
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        भङ्ग;
    स्वभाव:
        expect("branch instruction");
    }
}

ST_FUNC शून्य asm_opcode(TCCState *s1, पूर्णाङ्क token)
{
    याव (token == TOK_LINEFEED) {
        next();
        token = tok;
    }
    सचे (token == TOK_EOF)
        पटिनिवत्त;
    सचे (token < TOK_ASM_nopeq) { // no condition code
        विकल्प (token) {
        पक्ष TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            पटिनिवत्त;
        पक्ष TOK_ASM_ldc2:
        पक्ष TOK_ASM_ldc2l:
        पक्ष TOK_ASM_stc2:
        पक्ष TOK_ASM_stc2l:
            asm_coprocessor_data_transfer_opcode(s1, token);
            पटिनिवत्त;
        स्वभाव:
            expect("instruction");
        }
    }

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_pusheq:
    पक्ष TOK_ASM_popeq:
    पक्ष TOK_ASM_stmdaeq:
    पक्ष TOK_ASM_ldmdaeq:
    पक्ष TOK_ASM_stmeq:
    पक्ष TOK_ASM_ldmeq:
    पक्ष TOK_ASM_stmiaeq:
    पक्ष TOK_ASM_ldmiaeq:
    पक्ष TOK_ASM_stmdbeq:
    पक्ष TOK_ASM_ldmdbeq:
    पक्ष TOK_ASM_stmibeq:
    पक्ष TOK_ASM_ldmibeq:
        asm_block_data_transfer_opcode(s1, token);
        पटिनिवत्त;
    पक्ष TOK_ASM_nopeq:
    पक्ष TOK_ASM_wfeeq:
    पक्ष TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        पटिनिवत्त;
    पक्ष TOK_ASM_swieq:
    पक्ष TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        पटिनिवत्त;
    पक्ष TOK_ASM_beq:
    पक्ष TOK_ASM_bleq:
    पक्ष TOK_ASM_bxeq:
    पक्ष TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        पटिनिवत्त;
    पक्ष TOK_ASM_clzeq:
    पक्ष TOK_ASM_sxtbeq:
    पक्ष TOK_ASM_sxtheq:
    पक्ष TOK_ASM_uxtbeq:
    पक्ष TOK_ASM_uxtheq:
    पक्ष TOK_ASM_movteq:
    पक्ष TOK_ASM_movweq:
        asm_द्विमान_opcode(s1, token);
        पटिनिवत्त;

    पक्ष TOK_ASM_ldreq:
    पक्ष TOK_ASM_ldrbeq:
    पक्ष TOK_ASM_streq:
    पक्ष TOK_ASM_strbeq:
    पक्ष TOK_ASM_ldrexeq:
    पक्ष TOK_ASM_ldrexbeq:
    पक्ष TOK_ASM_ldrexheq:
    पक्ष TOK_ASM_strexeq:
    पक्ष TOK_ASM_strexbeq:
    पक्ष TOK_ASM_strexheq:
        asm_single_data_transfer_opcode(s1, token);
        पटिनिवत्त;

    पक्ष TOK_ASM_ldrheq:
    पक्ष TOK_ASM_ldrsheq:
    पक्ष TOK_ASM_ldrsbeq:
    पक्ष TOK_ASM_strheq:
       asm_misc_single_data_transfer_opcode(s1, token);
       पटिनिवत्त;

    पक्ष TOK_ASM_andeq:
    पक्ष TOK_ASM_eoreq:
    पक्ष TOK_ASM_subeq:
    पक्ष TOK_ASM_rsbeq:
    पक्ष TOK_ASM_addeq:
    पक्ष TOK_ASM_adceq:
    पक्ष TOK_ASM_sbceq:
    पक्ष TOK_ASM_rsceq:
    पक्ष TOK_ASM_tsteq:
    पक्ष TOK_ASM_teqeq:
    पक्ष TOK_ASM_cmpeq:
    पक्ष TOK_ASM_cmneq:
    पक्ष TOK_ASM_orreq:
    पक्ष TOK_ASM_moveq:
    पक्ष TOK_ASM_biceq:
    पक्ष TOK_ASM_mvneq:
    पक्ष TOK_ASM_andseq:
    पक्ष TOK_ASM_eorseq:
    पक्ष TOK_ASM_subseq:
    पक्ष TOK_ASM_rsbseq:
    पक्ष TOK_ASM_addseq:
    पक्ष TOK_ASM_adcseq:
    पक्ष TOK_ASM_sbcseq:
    पक्ष TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    पक्ष TOK_ASM_orrseq:
    पक्ष TOK_ASM_movseq:
    पक्ष TOK_ASM_bicseq:
    पक्ष TOK_ASM_mvnseq:
        asm_data_processing_opcode(s1, token);
        पटिनिवत्त;

    पक्ष TOK_ASM_lsleq:
    पक्ष TOK_ASM_lslseq:
    पक्ष TOK_ASM_lsreq:
    पक्ष TOK_ASM_lsrseq:
    पक्ष TOK_ASM_asreq:
    पक्ष TOK_ASM_asrseq:
    पक्ष TOK_ASM_roreq:
    पक्ष TOK_ASM_rorseq:
    पक्ष TOK_ASM_rrxseq:
    पक्ष TOK_ASM_rrxeq:
        asm_shift_opcode(s1, token);
        पटिनिवत्त;

    पक्ष TOK_ASM_muleq:
    पक्ष TOK_ASM_mulseq:
    पक्ष TOK_ASM_mlaeq:
    पक्ष TOK_ASM_mlaseq:
    पक्ष TOK_ASM_mlseq:
    पक्ष TOK_ASM_udiveq:
    पक्ष TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        पटिनिवत्त;

    पक्ष TOK_ASM_smulleq:
    पक्ष TOK_ASM_smullseq:
    पक्ष TOK_ASM_umulleq:
    पक्ष TOK_ASM_umullseq:
    पक्ष TOK_ASM_smlaleq:
    पक्ष TOK_ASM_smlalseq:
    पक्ष TOK_ASM_umlaleq:
    पक्ष TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        पटिनिवत्त;

    पक्ष TOK_ASM_cdpeq:
    पक्ष TOK_ASM_mcreq:
    पक्ष TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        पटिनिवत्त;

    पक्ष TOK_ASM_ldceq:
    पक्ष TOK_ASM_ldcleq:
    पक्ष TOK_ASM_stceq:
    पक्ष TOK_ASM_stcleq:
        asm_coprocessor_data_transfer_opcode(s1, token);
        पटिनिवत्त;

#सचे defined(TCC_ARM_VFP)
    पक्ष TOK_ASM_vldreq:
    पक्ष TOK_ASM_vstreq:
        asm_floating_point_single_data_transfer_opcode(s1, token);
        पटिनिवत्त;

    पक्ष TOK_ASM_vmlaeq_f32:
    पक्ष TOK_ASM_vmlseq_f32:
    पक्ष TOK_ASM_vnmlseq_f32:
    पक्ष TOK_ASM_vnmlaeq_f32:
    पक्ष TOK_ASM_vmuleq_f32:
    पक्ष TOK_ASM_vnmuleq_f32:
    पक्ष TOK_ASM_vaddeq_f32:
    पक्ष TOK_ASM_vsubeq_f32:
    पक्ष TOK_ASM_vdiveq_f32:
    पक्ष TOK_ASM_vnegeq_f32:
    पक्ष TOK_ASM_vabseq_f32:
    पक्ष TOK_ASM_vsqrteq_f32:
    पक्ष TOK_ASM_vcmpeq_f32:
    पक्ष TOK_ASM_vcmpeeq_f32:
    पक्ष TOK_ASM_vmoveq_f32:
    पक्ष TOK_ASM_vmlaeq_f64:
    पक्ष TOK_ASM_vmlseq_f64:
    पक्ष TOK_ASM_vnmlseq_f64:
    पक्ष TOK_ASM_vnmlaeq_f64:
    पक्ष TOK_ASM_vmuleq_f64:
    पक्ष TOK_ASM_vnmuleq_f64:
    पक्ष TOK_ASM_vaddeq_f64:
    पक्ष TOK_ASM_vsubeq_f64:
    पक्ष TOK_ASM_vdiveq_f64:
    पक्ष TOK_ASM_vnegeq_f64:
    पक्ष TOK_ASM_vabseq_f64:
    पक्ष TOK_ASM_vsqrteq_f64:
    पक्ष TOK_ASM_vcmpeq_f64:
    पक्ष TOK_ASM_vcmpeeq_f64:
    पक्ष TOK_ASM_vmoveq_f64:
        asm_floating_point_data_processing_opcode(s1, token);
        पटिनिवत्त;

    पक्ष TOK_ASM_vcvtreq_s32_f32:
    पक्ष TOK_ASM_vcvtreq_s32_f64:
    पक्ष TOK_ASM_vcvteq_s32_f32:
    पक्ष TOK_ASM_vcvteq_s32_f64:
    पक्ष TOK_ASM_vcvtreq_u32_f32:
    पक्ष TOK_ASM_vcvtreq_u32_f64:
    पक्ष TOK_ASM_vcvteq_u32_f32:
    पक्ष TOK_ASM_vcvteq_u32_f64:
    पक्ष TOK_ASM_vcvteq_f64_s32:
    पक्ष TOK_ASM_vcvteq_f32_s32:
    पक्ष TOK_ASM_vcvteq_f64_u32:
    पक्ष TOK_ASM_vcvteq_f32_u32:
    पक्ष TOK_ASM_vcvteq_f64_f32:
    पक्ष TOK_ASM_vcvteq_f32_f64:
        asm_floating_point_vcvt_data_processing_opcode(s1, token);
        पटिनिवत्त;

    पक्ष TOK_ASM_vpusheq:
    पक्ष TOK_ASM_vpopeq:
    पक्ष TOK_ASM_vldmeq:
    पक्ष TOK_ASM_vldmiaeq:
    पक्ष TOK_ASM_vldmdbeq:
    पक्ष TOK_ASM_vstmeq:
    पक्ष TOK_ASM_vstmiaeq:
    पक्ष TOK_ASM_vstmdbeq:
        asm_floating_point_block_data_transfer_opcode(s1, token);
        पटिनिवत्त;

    पक्ष TOK_ASM_vmsreq:
    पक्ष TOK_ASM_vmrseq:
        asm_floating_point_status_register_opcode(s1, token);
        पटिनिवत्त;
#endif

    स्वभाव:
        expect("known instruction");
    }
}

ST_FUNC शून्य subst_asm_operand(CString *add_str, SValue *sv, पूर्णाङ्क modifier)
{
    पूर्णाङ्क r, reg, size, val;

    r = sv->r;
    सचे ((r & VT_VALMASK) == VT_CONST) {
        सचे (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        सचे (r & VT_SYM) {
            ध्रुव वर्ण *name = get_tok_str(sv->sym->v, रिक्त);
            सचे (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            सचे (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            सचे ((uint32_t) sv->c.i == 0)
                गच्छ no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        सचे (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
      no_offset:;
    } अञ्ञथा सचे ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[fp,#%d]", (पूर्णाङ्क) sv->c.i);
    } अञ्ञथा सचे (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        सचे (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, रिक्त));
    } अञ्ञथा {
        /* register case */
        reg = r & VT_VALMASK;
        सचे (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        सचे ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        अञ्ञथा सचे ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        अञ्ञथा
            size = 4;

        सचे (modifier == 'b') {
            size = 1;
        } अञ्ञथा सचे (modifier == 'w') {
            size = 2;
        } अञ्ञथा सचे (modifier == 'k') {
            size = 4;
        }

        विकल्प (size) {
        स्वभाव:
            reg = TOK_ASM_r0 + reg;
            भङ्ग;
        }
        cstr_printf(add_str, "%s", get_tok_str(reg, रिक्त));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC शून्य asm_gen_code(ASMOperand *operands, पूर्णाङ्क nb_operands,
                          पूर्णाङ्क nb_outputs, पूर्णाङ्क is_output,
                          uint8_t *clobber_regs,
                          पूर्णाङ्क out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    पूर्णाङ्क i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    स्थिर ध्रुव uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, परिमाण(regs_allocated));
    अत्थाय(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        सचे (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    अत्थाय(i = 0; i < परिमाण(reg_saved)/परिमाण(reg_saved[0]); i++) {
        reg = reg_saved[i];
        सचे (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    सचे (!is_output) { // prolog
        /* generate reg save code */
        सचे (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        अत्थाय(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            सचे (op->reg >= 0) {
                सचे ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } अञ्ञथा सचे (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    load(op->reg, op->vt);
                    सचे (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } अञ्ञथा { // epilog
        /* generate save code */
        अत्थाय(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            सचे (op->reg >= 0) {
                सचे ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    सचे (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } अञ्ञथा {
                    store(op->reg, op->vt);
                    सचे (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        सचे (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
स्थिर अन्तःस्थ पूर्णाङ्क constraint_priority(ध्रुव वर्ण *str)
{
    पूर्णाङ्क priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    अत्थाय(;;) {
        c = *str;
        सचे (c == '\0')
            भङ्ग;
        str++;
        विकल्प(c) {
        पक्ष 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        पक्ष 'r': // register [general]
        पक्ष 'p': // valid memory address for load,store [general]
            pr = 3;
            भङ्ग;
        पक्ष 'M': // integer constant for shifts [ARM]
        पक्ष 'I': // integer valid for data processing instruction immediate
        पक्ष 'J': // integer in range -4095...4095

        पक्ष 'i': // immediate integer operand, including symbolic constants [general]
        पक्ष 'm': // memory operand [general]
        पक्ष 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            भङ्ग;
        स्वभाव:
            tcc_error("unknown constraint '%c'", c);
        }
        सचे (pr > priority)
            priority = pr;
    }
    पटिनिवत्त priority;
}

स्थिर ध्रुव वर्ण *skip_constraint_modifiers(ध्रुव वर्ण *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    याव (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    पटिनिवत्त p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC शून्य asm_compute_constraints(ASMOperand *operands,
                                    पूर्णाङ्क nb_operands, पूर्णाङ्क nb_outputs,
                                    ध्रुव uint8_t *clobber_regs,
                                    पूर्णाङ्क *pout_reg)
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
    पूर्णाङ्क sorted_op[MAX_ASM_OPERANDS];
    पूर्णाङ्क i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ध्रुव वर्ण *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    अत्थाय (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->निवेशः_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    अत्थाय (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        सचे (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, रिक्त);
            सचे ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            सचे (operands[k].निवेशः_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].निवेशः_index = i;
            op->priority = 5;
        } अञ्ञथा सचे ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } अञ्ञथा {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    अत्थाय (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    अत्थाय (i = 0; i < nb_operands - 1; i++) {
        अत्थाय (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            सचे (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    अत्थाय (i = 0; i < NB_ASM_REGS; i++) {
        सचे (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        अञ्ञथा
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_IN_MASK | REG_OUT_MASK;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    अत्थाय (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        सचे (op->ref_index >= 0)
            अनुवर्त;
        /* select if register is used for output, input or both */
        सचे (op->निवेशः_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } अञ्ञथा सचे (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } अञ्ञथा {
            reg_mask = REG_IN_MASK;
        }
        सचे (op->reg >= 0) {
            सचे (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        विकल्प (c) {
        पक्ष '=': // Operand is written-to
            गच्छ try_next;
        पक्ष '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        पक्ष '&': // Operand is clobbered before the instruction is done using the input operands
            सचे (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            गच्छ try_next;
        पक्ष 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        पक्ष 'r': // general-purpose register
        पक्ष 'p': // loadable/storable address
            /* any general register */
            सचे ((reg = op->reg) >= 0)
                गच्छ reg_found;
            अञ्ञथा अत्थाय (reg = 0; reg <= 8; reg++) {
                सचे (!is_reg_allocated(reg))
                    गच्छ reg_found;
            }
            गच्छ try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            भङ्ग;
        पक्ष 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        पक्ष 'J': // integer in the range -4095 to 4095 [ARM]
        पक्ष 'K': // integer that satisfies constraint I when inverted (one's complement)
        पक्ष 'L': // integer that satisfies constraint I when inverted (two's complement)
        पक्ष 'i': // immediate integer operand, including symbolic constants
            सचे (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'M': // integer in the range 0 to 32
            सचे (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'm': // memory operand
        पक्ष 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            सचे (j < nb_outputs || c == 'm') {
                सचे ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    अत्थाय (reg = 0; reg <= 8; reg++) {
                        सचे (!(regs_allocated[reg] & REG_IN_MASK))
                            गच्छ reg_found1;
                    }
                    गच्छ try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            भङ्ग;
        स्वभाव:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            भङ्ग;
        }
        /* if a reference is present for that operand, we assign it too */
        सचे (op->निवेशः_index >= 0) {
            operands[op->निवेशः_index].reg = op->reg;
            operands[op->निवेशः_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    अत्थाय (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        सचे (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            अत्थाय (reg = 0; reg <= 8; reg++) {
                सचे (!(regs_allocated[reg] & REG_OUT_MASK))
                    गच्छ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            भङ्ग;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    अत्थाय (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, रिक्त) : "",
               op->constraint, op->vt->r, op->reg);
    }
    सचे (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC शून्य asm_clobber(uint8_t *clobber_regs, ध्रुव वर्ण *str)
{
    पूर्णाङ्क reg;
    TokenSym *ts;

    सचे (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        पटिनिवत्त;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    सचे (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC पूर्णाङ्क asm_parse_regvar (पूर्णाङ्क t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    सचे (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        पटिनिवत्त -1;

    सचे (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        पटिनिवत्त t - TOK_ASM_r0;

    सचे (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        पटिनिवत्त t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    पटिनिवत्त t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
