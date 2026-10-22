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

ST_FUNC શૂન્ય g(પૂર્ણાંક c);
ST_FUNC શૂન્ય gen_le16(પૂર્ણાંક c);
ST_FUNC શૂન્ય gen_le32(પૂર્ણાંક c);

/*************************************************************/
#નહીંતર
/*************************************************************/

#define USING_GLOBALS
#અન્તર્ભાવ "tcc.h"

ગણના {
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

પ્રકારવ્યાખ્યા સંરચના Operand {
    uint32_t type;
    સંઘ {
        uint8_t reg;
        uint16_t regset;
        પદાવલિ_કિંમત e;
    };
} Operand;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
સ્થિર પૂર્ણાંક asm_parse_vfp_regvar(પૂર્ણાંક t, પૂર્ણાંક double_precision)
{
    જો (double_precision) {
        જો (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            પાછા t - TOK_ASM_d0;
    } નહીંતર {
        જો (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            પાછા t - TOK_ASM_s0;
    }
    પાછા -1;
}

/* Parse a text containing operand and store the result in OP */
સ્થિર શૂન્ય parse_operand(TCCState *s1, Operand *op)
{
    પદાવલિ_કિંમત e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    જો (tok == '{') { // regset literal
        next(); // skip '{'
        જ્યારે (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            જો (reg == -1) {
                expect("register");
            } નહીંતર
                next(); // skip register name

            જો ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            જો (tok != ',')
                તોડો;
            next(); // skip ','
        }
        skip('}');
        જો (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } નહીંતર {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        પાછા;
    } નહીંતર જો ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        પાછા;
    } નહીંતર જો ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        next(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        પાછા;
    } નહીંતર જો ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        next(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        પાછા;
    } નહીંતર જો (tok == '#' || tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    }
    asm_પદાવલિ(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    જો (!op->e.sym) {
        જો ((પૂર્ણાંક) op->e.v < 0 && (પૂર્ણાંક) op->e.v >= -255)
            op->type = OP_IM8N;
        નહીંતર જો (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } નહીંતર
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC શૂન્ય g(પૂર્ણાંક c)
{
    પૂર્ણાંક ind1;
    જો (nocode_wanted)
        પાછા;
    ind1 = ind + 1;
    જો (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC શૂન્ય gen_le16 (પૂર્ણાંક i)
{
    g(i);
    g(i>>8);
}

ST_FUNC શૂન્ય gen_le32 (પૂર્ણાંક i)
{
    પૂર્ણાંક ind1;
    જો (nocode_wanted)
        પાછા;
    ind1 = ind + 4;
    જો (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC શૂન્ય gen_expr32(પદાવલિ_કિંમત *pe)
{
    gen_le32(pe->v);
}

સ્થિર uint32_t condition_code_of_token(પૂર્ણાંક token) {
    જો (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } નહીંતર
        પાછા (token - TOK_ASM_nopeq) & 15;
}

સ્થિર શૂન્ય asm_emit_opcode(પૂર્ણાંક token, uint32_t opcode) {
    gen_le32((condition_code_of_token(token) << 28) | opcode);
}

સ્થિર શૂન્ય asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

સ્થિર શૂન્ય asm_emit_coprocessor_opcode(uint32_t ઉપલું_nibble, uint8_t cp_સંખ્યા, uint8_t cp_opcode, uint8_t cp_destination_register, uint8_t cp_n_operand_register, uint8_t cp_m_operand_register, uint8_t cp_opcode2, પૂર્ણાંક inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    જો (inter_processor_transfer)
        opcode |= 1 << 4;
    //assert(cp_opcode < 16);
    opcode |= cp_opcode << 20;
    //assert(cp_n_operand_register < 16);
    opcode |= cp_n_operand_register << 16;
    //assert(cp_destination_register < 16);
    opcode |= cp_destination_register << 12;
    //assert(cp_number < 16);
    opcode |= cp_સંખ્યા << 8;
    //assert(cp_information < 8);
    opcode |= cp_opcode2 << 5;
    //assert(cp_m_operand_register < 16);
    opcode |= cp_m_operand_register;
    asm_emit_unconditional_opcode((ઉપલું_nibble << 28) | opcode);
}

સ્થિર શૂન્ય asm_nullary_opcode(પૂર્ણાંક token)
{
    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        તોડો;
    સ્થિતિ TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    સ્થિતિ TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        તોડો;
    મૂળભૂત:
        expect("nullary instruction");
    }
}

સ્થિર શૂન્ય asm_unary_opcode(TCCState *s1, પૂર્ણાંક token)
{
    Operand op;
    parse_operand(s1, &op);

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_swieq:
    સ્થિતિ TOK_ASM_svceq:
        જો (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        નહીંતર {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        તોડો;
    મૂળભૂત:
        expect("unary instruction");
    }
}

સ્થિર શૂન્ય asm_દ્વિઅંકી_opcode(TCCState *s1, પૂર્ણાંક token)
{
    Operand ops[2];
    Operand rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);
    જો (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    જો (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ખાલી));
    }

    જો (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ખાલી));

    જો (ops[1].type != OP_REG32) {
        પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
        સ્થિતિ TOK_ASM_movteq:
        સ્થિતિ TOK_ASM_movweq:
            જો (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                જો (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t immediate_કિંમત = ops[1].e.v;
                    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
                    સ્થિતિ TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (immediate_કિંમત & 0xF000) << 4 | (immediate_કિંમત & 0xFFF));
                        તોડો;
                    સ્થિતિ TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (immediate_કિંમત & 0xF000) << 4 | (immediate_કિંમત & 0xFFF));
                        તોડો;
                    }
                } નહીંતર
                    expect("(source operand) immediate 16 bit value");
            } નહીંતર
                expect("(source operand) immediate");
            તોડો;
        મૂળભૂત:
            expect("(source operand) register");
        }
        પાછા;
    }

    જો (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ખાલી));
    }

    જો (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ખાલી));

    જો (tok == ',') {
        next(); // skip ','
        જો (tok == TOK_ASM_ror) {
            next(); // skip 'ror'
            parse_operand(s1, &rotation);
            જો (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } નહીંતર {
                amount = rotation.e.v;
                પસંદગી (amount) {
                સ્થિતિ 8:
                    encoded_rotation = 1 << 10;
                    તોડો;
                સ્થિતિ 16:
                    encoded_rotation = 2 << 10;
                    તોડો;
                સ્થિતિ 24:
                    encoded_rotation = 3 << 10;
                    તોડો;
                મૂળભૂત:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_clzeq:
        જો (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        તોડો;
    સ્થિતિ TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        તોડો;
    સ્થિતિ TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        તોડો;
    સ્થિતિ TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        તોડો;
    સ્થિતિ TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        તોડો;
    મૂળભૂત:
        expect("binary instruction");
    }
}

સ્થિર શૂન્ય asm_coprocessor_opcode(TCCState *s1, પૂર્ણાંક token) {
    uint8_t coprocessor;
    Operand opcode1;
    Operand opcode2;
    uint8_t registers[3];
    unsigned પૂર્ણાંક i;
    uint8_t ઉપલું_nibble;
    uint8_t mrc = 0;

    જો (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } નહીંતર {
        expect("'p<number>'");
    }
    skip(',');
    parse_operand(s1, &opcode1);
    જો (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ખાલી));
    }

    માટે (i = 0; i < 3; ++i) {
        skip(',');
        જો (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mcreq)) {
            જો (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                next();
            } નહીંતર {
                expect("'r<number>'");
            }
        } નહીંતર {
            જો (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                next();
            } નહીંતર {
                expect("'c<number>'");
            }
        }
    }
    જો (tok == ',') {
        next();
        parse_operand(s1, &opcode2);
    } નહીંતર {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    જો (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ખાલી));
    }

    જો (token == TOK_ASM_cdp2) {
        ઉપલું_nibble = 0xF;
        asm_emit_coprocessor_opcode(ઉપલું_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        પાછા;
    } નહીંતર
        ઉપલું_nibble = condition_code_of_token(token);

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(ઉપલું_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        તોડો;
    સ્થિતિ TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    સ્થિતિ TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        જો (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, ખાલી));
        }
        asm_emit_coprocessor_opcode(ઉપલું_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        તોડો;
    મૂળભૂત:
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
#define ENCODE_BARREL_SHIFTER_IMMEDIATE(કિંમત) ((કિંમત) << 7)

સ્થિર શૂન્ય asm_block_data_transfer_opcode(TCCState *s1, પૂર્ણાંક token)
{
    uint32_t opcode;
    પૂર્ણાંક op0_exclam = 0;
    Operand ops[2];
    પૂર્ણાંક nb_ops = 1;
    parse_operand(s1, &ops[0]);
    જો (tok == '!') {
        op0_exclam = 1;
        next(); // skip '!'
    }
    જો (tok == ',') {
        next(); // skip comma
        parse_operand(s1, &ops[1]);
        ++nb_ops;
    }
    જો (nb_ops < 1) {
        expect("at least one operand");
    } નહીંતર જો (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        જો (nb_ops != 1)
            expect("exactly one operand");
        નહીંતર
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        તોડો;
    સ્થિતિ TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        જો (nb_ops != 1)
            expect("exactly one operand");
        નહીંતર
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        તોડો;
    સ્થિતિ TOK_ASM_stmdaeq:
    સ્થિતિ TOK_ASM_ldmdaeq:
    સ્થિતિ TOK_ASM_stmeq:
    સ્થિતિ TOK_ASM_ldmeq:
    સ્થિતિ TOK_ASM_stmiaeq:
    સ્થિતિ TOK_ASM_ldmiaeq:
    સ્થિતિ TOK_ASM_stmdbeq:
    સ્થિતિ TOK_ASM_ldmdbeq:
    સ્થિતિ TOK_ASM_stmibeq:
    સ્થિતિ TOK_ASM_ldmibeq:
        પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
        સ્થિતિ TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            તોડો;
        સ્થિતિ TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            તોડો;
        સ્થિતિ TOK_ASM_stmeq: // post-increment store
        સ્થિતિ TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            તોડો;
        સ્થિતિ TOK_ASM_ldmeq: // post-increment load
        સ્થિતિ TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            તોડો;
        સ્થિતિ TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            તોડો;
        સ્થિતિ TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            તોડો;
        સ્થિતિ TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            તોડો;
        સ્થિતિ TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            તોડો;
        મૂળભૂત:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        જો (nb_ops != 2)
            expect("exactly two operands");
        નહીંતર જો (ops[0].type != OP_REG32)
            expect("(first operand) register");
        નહીંતર {
            જો (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        તોડો;
    મૂળભૂત:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
સ્થિર uint32_t asm_parse_optional_shift(TCCState* s1, પૂર્ણાંક* nb_shift, Operand* shift)
{
    uint32_t opcode = 0;
    *nb_shift = 0;
    પસંદગી (tok) {
    સ્થિતિ TOK_ASM_asl:
    સ્થિતિ TOK_ASM_lsl:
    સ્થિતિ TOK_ASM_asr:
    સ્થિતિ TOK_ASM_lsr:
    સ્થિતિ TOK_ASM_ror:
        પસંદગી (tok) {
        સ્થિતિ TOK_ASM_asl:
            /* fallthrough */
        સ્થિતિ TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSL;
            તોડો;
        સ્થિતિ TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ASR;
            તોડો;
        સ્થિતિ TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSR;
            તોડો;
        સ્થિતિ TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
            તોડો;
        }
        next();
        parse_operand(s1, shift);
        *nb_shift = 1;
        તોડો;
    સ્થિતિ TOK_ASM_rrx:
        next();
        opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
        તોડો;
    }
    પાછા opcode;
}

સ્થિર uint32_t asm_encode_shift(Operand* shift)
{
    uint64_t amount;
    uint32_t operands = 0;
    પસંદગી (shift->type) {
    સ્થિતિ OP_REG32:
        જો (shift->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        નહીંતર {
            operands = ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER;
            operands |= ENCODE_BARREL_SHIFTER_REGISTER(shift->reg);
        }
        તોડો;
    સ્થિતિ OP_IM8:
        amount = shift->e.v;
        જો (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_IMMEDIATE(amount);
        નહીંતર
            tcc_error("shift count out of range");
        તોડો;
    મૂળભૂત:
        tcc_error("unknown shift amount");
    }
    પાછા operands;
}

સ્થિર શૂન્ય asm_data_processing_opcode(TCCState *s1, પૂર્ણાંક token)
{
    Operand ops[3];
    પૂર્ણાંક nb_ops;
    Operand shift = {0};
    પૂર્ણાંક nb_shift = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_GROUP(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    માટે (nb_ops = 0; nb_ops < કદ(ops)/કદ(ops[0]); ) {
        જો (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            તોડો;
        parse_operand(s1, &ops[nb_ops]);
        ++nb_ops;
        જો (tok != ',')
            તોડો;
        next(); // skip ','
    }
    જો (tok == ',')
        next();
    operands |= asm_parse_optional_shift(s1, &nb_shift, &shift);
    જો (nb_ops < 2)
        expect("at least two operands");
    નહીંતર જો (nb_ops == 2) {
        memcpy(&ops[2], &ops[1], કદ(ops[1])); // move ops[2]
        memcpy(&ops[1], &ops[0], કદ(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } નહીંતર જો (nb_ops == 3) {
        જો (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, ખાલી));
        }
    }
    જો (nb_ops != 3) {
        expect("two or three operands");
    } નહીંતર {
        uint32_t opcode = 0;
        uint32_t immediate_કિંમત;
        uint8_t half_immediate_rotation;
        જો (nb_shift && shift.type == OP_REG32) {
            જો ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
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
        જો (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        નહીંતર જો (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_SET_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        નહીંતર
            operands |= ENCODE_RD(ops[0].reg);
        જો (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        નહીંતર જો (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        પસંદગી (ops[2].type) {
        સ્થિતિ OP_REG32:
            operands |= ops[2].reg;
            તોડો;
        સ્થિતિ OP_IM8:
        સ્થિતિ OP_IM32:
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_કિંમત = ops[2].e.v;
            માટે (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                જો (immediate_કિંમત >= 0x00 && immediate_કિંમત < 0x100)
                    તોડો;
                // rotate left by two
                immediate_કિંમત = ((immediate_કિંમત & 0x3FFFFFFF) << 2) | ((immediate_કિંમત & 0xC0000000) >> 30);
            }
            જો (half_immediate_rotation >= 16) {
                /* fallthrough */
            } નહીંતર {
                operands |= immediate_કિંમત;
                operands |= half_immediate_rotation << 8;
                તોડો;
            }
        સ્થિતિ OP_IM8N: // immediate negative value
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_કિંમત = ops[2].e.v;
            /* Instruction swapping:
               0001 = EOR - Rd:= Op1 EOR Op2     -> difficult
               0011 = RSB - Rd:= Op2 - Op1       -> difficult
               0111 = RSC - Rd:= Op2 - Op1 + C   -> difficult
               1000 = TST - CC on: Op1 AND Op2   -> difficult
               1001 = TEQ - CC on: Op1 EOR Op2   -> difficult
               1100 = ORR - Rd:= Op1 OR Op2      -> difficult
            */
            પસંદગી (opcode_nos) {
            સ્થિતિ 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                immediate_કિંમત = ~immediate_કિંમત;
                તોડો;
            સ્થિતિ 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; // ADD
                immediate_કિંમત = -immediate_કિંમત;
                તોડો;
            સ્થિતિ 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                immediate_કિંમત = -immediate_કિંમત;
                તોડો;
            સ્થિતિ 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                immediate_કિંમત = ~immediate_કિંમત;
                તોડો;
            સ્થિતિ 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                immediate_કિંમત = ~immediate_કિંમત;
                તોડો;
            સ્થિતિ 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                immediate_કિંમત = -immediate_કિંમત;
                તોડો;
            સ્થિતિ 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                immediate_કિંમત = -immediate_કિંમત;
                તોડો;
            સ્થિતિ 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                immediate_કિંમત = ~immediate_કિંમત;
                તોડો;
            સ્થિતિ 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                immediate_કિંમત = ~immediate_કિંમત;
                તોડો;
            સ્થિતિ 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                immediate_કિંમત = ~immediate_કિંમત;
                તોડો;
            મૂળભૂત:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, ખાલી));
            }
            માટે (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                જો (immediate_કિંમત >= 0x00 && immediate_કિંમત < 0x100)
                    તોડો;
                // rotate left by two
                immediate_કિંમત = ((immediate_કિંમત & 0x3FFFFFFF) << 2) | ((immediate_કિંમત & 0xC0000000) >> 30);
            }
            જો (half_immediate_rotation >= 16) {
                immediate_કિંમત = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (unsigned) immediate_કિંમત);
            }
            operands |= immediate_કિંમત;
            operands |= half_immediate_rotation << 8;
            તોડો;
        મૂળભૂત:
            expect("(second source operand) register or immediate value");
        }

        જો (nb_shift) {
            જો (operands & ENCODE_IMMEDIATE_FLAG)
                tcc_error("immediate rotation not implemented");
            નહીંતર
                operands |= asm_encode_shift(&shift);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_SET_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

સ્થિર શૂન્ય asm_shift_opcode(TCCState *s1, પૂર્ણાંક token)
{
    Operand ops[3];
    પૂર્ણાંક nb_ops;
    પૂર્ણાંક definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    માટે (nb_ops = 0; nb_ops < કદ(ops)/કદ(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        જો (tok != ',') {
            ++nb_ops;
            તોડો;
        }
        next(); // skip ','
    }
    જો (nb_ops < 2) {
        expect("at least two operands");
    }

    જો (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } નહીંતર
        operands |= ENCODE_RD(ops[0].reg);

    જો (nb_ops == 2) {
        પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
        સ્થિતિ TOK_ASM_rrxseq:
            opcode |= ENCODE_SET_CONDITION_CODES;
            /* fallthrough */
        સ્થિતિ TOK_ASM_rrxeq:
            જો (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
                asm_emit_opcode(token, opcode | operands);
            } નહીંતર
                tcc_error("(first source operand) register");
            પાછા;
        મૂળભૂત:
            memcpy(&ops[2], &ops[1], કદ(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], કદ(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    જો (nb_ops != 3) {
        expect("two or three operands");
    }

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_lslseq:
    સ્થિતિ TOK_ASM_lsrseq:
    સ્થિતિ TOK_ASM_asrseq:
    સ્થિતિ TOK_ASM_rorseq:
        opcode |= ENCODE_SET_CONDITION_CODES;
        તોડો;
    }

    પસંદગી (ops[1].type) {
    સ્થિતિ OP_REG32:
        operands |= ops[1].reg;
        તોડો;
    સ્થિતિ OP_IM8:
        operands |= ENCODE_IMMEDIATE_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, ખાલી));
    }

    પસંદગી (ops[2].type) {
    સ્થિતિ OP_REG32:
        જો ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_shift(&ops[2]);
        તોડો;
    સ્થિતિ OP_IM8:
        જો (ops[2].e.v)
            operands |= asm_encode_shift(&ops[2]);
        નહીંતર
            definitely_neutral = 1;
        તોડો;
    }

    જો (!definitely_neutral) પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_lslseq:
    સ્થિતિ TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSL;
        તોડો;
    સ્થિતિ TOK_ASM_lsrseq:
    સ્થિતિ TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSR;
        તોડો;
    સ્થિતિ TOK_ASM_asrseq:
    સ્થિતિ TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ASR;
        તોડો;
    સ્થિતિ TOK_ASM_rorseq:
    સ્થિતિ TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
        તોડો;
    મૂળભૂત:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

સ્થિર શૂન્ય asm_multiplication_opcode(TCCState *s1, પૂર્ણાંક token)
{
    Operand ops[4];
    પૂર્ણાંક nb_ops = 0;
    uint32_t opcode = 0x90;

    માટે (nb_ops = 0; nb_ops < કદ(ops)/કદ(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        જો (tok != ',') {
            ++nb_ops;
            તોડો;
        }
        next(); // skip ','
    }
    જો (nb_ops < 2)
        expect("at least two operands");
    નહીંતર જો (nb_ops == 2) {
        પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
        સ્થિતિ TOK_ASM_mulseq:
        સ્થિતિ TOK_ASM_muleq:
            memcpy(&ops[2], &ops[0], કદ(ops[1])); // ARM is actually like this!
            તોડો;
        મૂળભૂત:
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

    જો (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    નહીંતર
        expect("(destination operand) register");
    જો (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    નહીંતર
        expect("(first source operand) register");
    જો (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    નહીંતર
        expect("(second source operand) register");
    જો (nb_ops > 3) {
        જો (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        નહીંતર
            expect("(third source operand) register");
    }

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_mulseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    સ્થિતિ TOK_ASM_muleq:
        જો (nb_ops != 3)
            expect("three operands");
        નહીંતર {
            asm_emit_opcode(token, opcode);
        }
        તોડો;
    સ્થિતિ TOK_ASM_mlaseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    સ્થિતિ TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        જો (nb_ops != 4)
            expect("four operands");
        નહીંતર {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        તોડો;
    સ્થિતિ TOK_ASM_mlseq:
        opcode |= 0x00400000;
        જાઓ case_TOK_ASM_mlaeq;
    સ્થિતિ TOK_ASM_udiveq:
        opcode |= 0x00200000;
    સ્થિતિ TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        તોડો;
    મૂળભૂત:
        expect("known multiplication instruction");
    }
}

સ્થિર શૂન્ય asm_long_multiplication_opcode(TCCState *s1, પૂર્ણાંક token)
{
    Operand ops[4];
    પૂર્ણાંક nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    માટે (nb_ops = 0; nb_ops < કદ(ops)/કદ(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        જો (tok != ',') {
            ++nb_ops;
            તોડો;
        }
        next(); // skip ','
    }
    જો (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    જો (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    નહીંતર
        expect("(destination lo accumulator) register");
    જો (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    નહીંતર
        expect("(destination hi accumulator) register");
    જો (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    નહીંતર
        expect("(first source operand) register");
    જો (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    નહીંતર
        expect("(second source operand) register");

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_smullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    સ્થિતિ TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        તોડો;
    સ્થિતિ TOK_ASM_umullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    સ્થિતિ TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        તોડો;
    સ્થિતિ TOK_ASM_smlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    સ્થિતિ TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        તોડો;
    સ્થિતિ TOK_ASM_umlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    સ્થિતિ TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        તોડો;
    મૂળભૂત:
        expect("known long multiplication instruction");
    }
}

સ્થિર શૂન્ય asm_single_data_transfer_opcode(TCCState *s1, પૂર્ણાંક token)
{
    Operand ops[3];
    Operand strex_operand;
    Operand shift;
    પૂર્ણાંક nb_shift = 0;
    પૂર્ણાંક exclam = 0;
    પૂર્ણાંક closed_bracket = 0;
    પૂર્ણાંક op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    જો (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    નહીંતર {
        expect("(destination operand) register");
    }
    જો (tok != ',')
        expect("at least two arguments");
    next(); // skip ','

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_strexheq:
    સ્થિતિ TOK_ASM_strexbeq:
    સ્થિતિ TOK_ASM_strexeq:
        parse_operand(s1, &strex_operand);
        જો (strex_operand.type != OP_REG32) {
            expect("register");
        }
        જો (tok != ',')
            expect("at least three arguments");
        નહીંતર
            next(); // skip ','
        તોડો;
    }

    skip('[');
    parse_operand(s1, &ops[1]);
    જો (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    નહીંતર {
        expect("(first source operand) register");
    }
    જો (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    જો (tok == ',') {
        next(); // skip ','
        જો (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        જો (ops[2].type == OP_REG32) {
            જો (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ખાલી));
            }
            જો (tok == ',') {
                next();
                opcode |= asm_parse_optional_shift(s1, &nb_shift, &shift);
                જો (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } નહીંતર {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    જો (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        જો (tok == '!') {
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
    જો (exclam)
        opcode |= 1 << 21; // write offset back into register

    જો (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        પૂર્ણાંક v = ops[2].e.v;
        જો (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        જો (v >= 0) {
            opcode |= 1 << 23; // up
            જો (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ખાલી));
            નહીંતર
                opcode |= v;
        } નહીંતર { // down
            જો (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ખાલી));
            નહીંતર
                opcode |= -v;
        }
    } નહીંતર જો (ops[2].type == OP_REG32) {
        જો (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } નહીંતર
        expect("register");

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    સ્થિતિ TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        જો (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        તોડો;
    સ્થિતિ TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    સ્થિતિ TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        જો (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        તોડો;
    સ્થિતિ TOK_ASM_strexheq:
        opcode |= 1 << 21;
    સ્થિતિ TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    સ્થિતિ TOK_ASM_strexeq:
        જો ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } નહીંતર જો (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        જો ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_operand.reg;
        asm_emit_opcode(token, opcode);
        તોડો;
    સ્થિતિ TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    સ્થિતિ TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    સ્થિતિ TOK_ASM_ldrexeq:
        જો ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } નહીંતર જો (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        જો ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        તોડો;
    મૂળભૂત:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
સ્થિર શૂન્ય asm_emit_coprocessor_data_transfer(uint32_t ઉપલું_nibble, uint8_t cp_સંખ્યા, uint8_t CRd, અચલ Operand* Rn, અચલ Operand* offset, પૂર્ણાંક offset_minus, પૂર્ણાંક preincrement, પૂર્ણાંક writeback, પૂર્ણાંક long_transfer, પૂર્ણાંક load) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    જો (long_transfer)
        opcode |= 1 << 22; // long transfer

    જો (load)
        opcode |= 1 << 20; // L

    opcode |= cp_સંખ્યા << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    જો (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    જો (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    જો (writeback)
        opcode |= 1 << 21; // write offset back into register

    જો (offset->type == OP_IM8 || offset->type == OP_IM8N || offset->type == OP_IM32) {
        પૂર્ણાંક v = offset->e.v;
        જો (offset_minus)
            tcc_error("minus before '#' not supported for immediate values");
        જો (offset->type == OP_IM8N || v < 0)
            v = -v;
        નહીંતર
            opcode |= 1 << 23; // up
        જો (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        જો (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } નહીંતર જો (offset->type == OP_REG32) {
        જો (!offset_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= offset->reg;
        tcc_error("Using register offset to register address is not possible here");
    } નહીંતર જો (offset->type == OP_VREG64) {
        opcode |= 16;
        opcode |= offset->reg;
    } નહીંતર
        expect("immediate or register");

    asm_emit_unconditional_opcode((ઉપલું_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
સ્થિર શૂન્ય asm_coprocessor_data_transfer_opcode(TCCState *s1, પૂર્ણાંક token)
{
    Operand ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_register;
    પૂર્ણાંક preincrement = 0;
    પૂર્ણાંક exclam = 0;
    પૂર્ણાંક closed_bracket = 0;
    પૂર્ણાંક op2_minus = 0;
    પૂર્ણાંક long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    જો (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } નહીંતર {
        expect("'c<number>'");
    }

    skip(',');

    જો (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_register = tok - TOK_ASM_c0;
        next();
    } નહીંતર {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    જો (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    જો (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    જો (tok == ',') {
        next(); // skip ','
        જો (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        જો (ops[2].type == OP_REG32) {
            જો (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ખાલી));
            }
        } નહીંતર જો (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, ખાલી));
        }
    } નહીંતર {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    જો (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        જો (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    // TODO: Support options.

    જો (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        પસંદગી (token) {
        સ્થિતિ TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        સ્થિતિ TOK_ASM_ldc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            તોડો;
        સ્થિતિ TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        સ્થિતિ TOK_ASM_stc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            તોડો;
        }
    } નહીંતર પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    સ્થિતિ TOK_ASM_stceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        તોડો;
    સ્થિતિ TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    સ્થિતિ TOK_ASM_ldceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        તોડો;
    મૂળભૂત:
        expect("coprocessor data transfer instruction");
    }
}

#જો defined(TCC_ARM_VFP)
#define CP_SINGLE_PRECISION_FLOAT 10
#define CP_DOUBLE_PRECISION_FLOAT 11

સ્થિર શૂન્ય asm_floating_point_single_data_transfer_opcode(TCCState *s1, પૂર્ણાંક token)
{
    Operand ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_register = 0;
    પૂર્ણાંક long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    જો (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        long_transfer = coprocessor_destination_register & 1;
        coprocessor_destination_register >>= 1;
    } નહીંતર જો (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        next();
    } નહીંતર {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    જો (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    જો (tok == ',') {
        next(); // skip ','
        parse_operand(s1, &ops[2]);
        જો (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } નહીંતર {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_vldreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        તોડો;
    સ્થિતિ TOK_ASM_vstreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        તોડો;
    મૂળભૂત:
        expect("floating point data transfer instruction");
    }
}

સ્થિર શૂન્ય asm_floating_point_block_data_transfer_opcode(TCCState *s1, પૂર્ણાંક token)
{
    uint8_t coprocessor = 0;
    પૂર્ણાંક first_regset_register;
    પૂર્ણાંક last_regset_register;
    uint8_t regset_item_ગણતરી;
    uint8_t extra_register_bit = 0;
    પૂર્ણાંક op0_exclam = 0;
    પૂર્ણાંક load = 0;
    પૂર્ણાંક preincrement = 0;
    Operand ops[1];
    Operand offset;
    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_vpusheq:
    સ્થિતિ TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        તોડો;
    મૂળભૂત:
        parse_operand(s1, &ops[0]);
        જો (tok == '!') {
            op0_exclam = 1;
            next(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    first_regset_register = asm_parse_vfp_regvar(tok, 1);
    જો ((first_regset_register = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        next();
    } નહીંતર જો ((first_regset_register = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        next();
    } નહીંતર {
        expect("floating-point register");
    }

    જો (tok == '-') {
        next();
        જો ((last_regset_register = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            next();
        નહીંતર {
            expect("floating-point register");
        }
    } નહીંતર
        last_regset_register = first_regset_register;

    જો (last_regset_register < first_regset_register) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_item_ગણતરી = last_regset_register - first_regset_register + 1;
    જો (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_item_ગણતરી <<= 1;
    નહીંતર {
        extra_register_bit = first_regset_register & 1;
        first_regset_register >>= 1;
    }
    offset.type = OP_IM8;
    offset.e.v = regset_item_ગણતરી << 2;
    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_vstmeq: // post-increment store
    સ્થિતિ TOK_ASM_vstmiaeq: // post-increment store
        તોડો;
    સ્થિતિ TOK_ASM_vpopeq:
    સ્થિતિ TOK_ASM_vldmeq: // post-increment load
    સ્થિતિ TOK_ASM_vldmiaeq: // post-increment load
        load = 1;
        તોડો;
    સ્થિતિ TOK_ASM_vldmdbeq: // pre-decrement load
        load = 1;
        /* fallthrough */
    સ્થિતિ TOK_ASM_vpusheq:
    સ્થિતિ TOK_ASM_vstmdbeq: // pre-decrement store
        offset.type = OP_IM8N;
        offset.e.v = -offset.e.v;
        preincrement = 1;
        તોડો;
    મૂળભૂત:
        expect("floating point block data transfer instruction");
    }
    જો (ops[0].type != OP_REG32)
        expect("(first operand) register");
    નહીંતર જો (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ખાલી));
    નહીંતર જો (!op0_exclam && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, ખાલી));
    નહીંતર
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, first_regset_register, &ops[0], &offset, 0, preincrement, op0_exclam, extra_register_bit, load);
}

#define VMOV_FRACTIONAL_DIGITS 7
#define VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

સ્થિર uint32_t vmov_parse_fractional_part(અચલ અક્ષર* s)
{
    uint32_t result = 0;
    પૂર્ણાંક i;
    માટે (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        અક્ષર c = *s;
        result *= 10;
        જો (c >= '0' && c <= '9') {
            result += (c - '0');
            ++s;
        }
    }
    જો (*s)
        expect("decimal numeral");
    પાછા result;
}

સ્થિર પૂર્ણાંક vmov_linear_approx_index(uint32_t beginning, uint32_t end, uint32_t કિંમત)
{
    પૂર્ણાંક i;
    uint32_t k;
    uint32_t xvalue;

    k = (end - beginning)/16;
    માટે (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        જો (કિંમત == xvalue)
            પાછા i;
    }
    //assert(0);
    પાછા -1;
}

સ્થિર uint32_t vmov_parse_immediate_કિંમત() {
    uint32_t કિંમત;
    unsigned long integral_કિંમત;
    અચલ અક્ષર *p;

    જો (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.data;
    errno = 0;
    integral_કિંમત = strtoul(p, (અક્ષર **)&p, 0);

    જો (errno || integral_કિંમત >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    કિંમત = (uint32_t) integral_કિંમત * VMOV_ONE;
    જો (*p == '.') {
        ++p;
        કિંમત += vmov_parse_fractional_part(p);
    }
    next();
    પાછા કિંમત;
}

સ્થિર uint8_t vmov_encode_immediate_કિંમત(uint32_t કિંમત)
{
    uint32_t limit;
    uint32_t end = 0;
    uint32_t beginning = 0;
    પૂર્ણાંક r = -1;
    પૂર્ણાંક n;
    પૂર્ણાંક i;

    limit = 32 * VMOV_ONE;
    માટે (i = 0; i < 8; ++i) {
        જો (કિંમત < limit) {
            end = limit;
            limit >>= 1;
            beginning = limit;
            r = i;
        } નહીંતર
            limit >>= 1;
    }
    જો (r == -1 || કિંમત < beginning || કિંમત > end) {
        tcc_error("invalid decimal number for vmov: %d", કિંમત);
    }
    n = vmov_linear_approx_index(beginning, end, કિંમત);
    પાછા n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
સ્થિર શૂન્ય asm_floating_point_immediate_data_processing_opcode_tail(TCCState *s1, પૂર્ણાંક token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t immediate_કિંમત = 0;
    પૂર્ણાંક op_minus = 0;
    uint8_t code;

    operands[0] = CRd;

    જો (tok == '#' || tok == '$') {
        next();
    }
    જો (tok == '-') {
        op_minus = 1;
        next();
    }
    immediate_કિંમત = vmov_parse_immediate_કિંમત();

    opcode1 = 11; // "Other" instruction
    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_vcmpeq_f32:
    સ્થિતિ TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        જો (immediate_કિંમત) {
            expect("Immediate value 0");
        }
        તોડો;
    સ્થિતિ TOK_ASM_vcmpeeq_f32:
    સ્થિતિ TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        જો (immediate_કિંમત) {
            expect("Immediate value 0");
        }
        તોડો;
    સ્થિતિ TOK_ASM_vmoveq_f32:
    સ્થિતિ TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        જો (op_minus)
            operands[1] = 0x8;
        નહીંતર
            operands[1] = 0x0;
        code = vmov_encode_immediate_કિંમત(immediate_કિંમત);
        operands[1] |= code >> 4;
        operands[2] = code & 0xF;
        તોડો;
    મૂળભૂત:
        expect("known floating point with immediate instruction");
    }

    જો (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        જો (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

સ્થિર શૂન્ય asm_floating_point_reg_arm_reg_transfer_opcode_tail(TCCState *s1, પૂર્ણાંક token, પૂર્ણાંક coprocessor, પૂર્ણાંક nb_arm_regs, પૂર્ણાંક nb_ops, Operand ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    પસંદગી (coprocessor) {
    સ્થિતિ CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        જો (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        જો (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            memcpy(&ops[2], &ops[1], કદ(ops[2]));
            memcpy(&ops[1], &ops[0], કદ(ops[1]));
            memcpy(&ops[0], &ops[2], કદ(ops[0]));
        } નહીંતર
            opcode1 |= 1;

        જો (ops[1].type == OP_VREG32) {
            જો (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        જો (ops[0].type == OP_VREG32) {
            જો (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        તોડો;
    સ્થિતિ CP_DOUBLE_PRECISION_FLOAT:
        જો (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        જો (ops[0].type == OP_VREG64) {
            જો (ops[2].type == OP_REG32) {
                Operand temp;
                // need to rotate operand list to the left
                memcpy(&temp, &ops[0], કદ(temp));
                memcpy(&ops[0], &ops[1], કદ(ops[0]));
                memcpy(&ops[1], &ops[2], કદ(ops[1]));
                memcpy(&ops[2], &temp, કદ(ops[2]));
            } નહીંતર {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } નહીંતર જો (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } નહીંતર {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        તોડો;
    મૂળભૂત:
        tcc_internal_error("unknown coprocessor");
    }
}

સ્થિર શૂન્ય asm_floating_point_vcvt_data_processing_opcode(TCCState *s1, પૂર્ણાંક token) {
    uint8_t coprocessor = 0;
    Operand ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_vcvtreq_s32_f64:
    સ્થિતિ TOK_ASM_vcvtreq_u32_f64:
    સ્થિતિ TOK_ASM_vcvteq_s32_f64:
    સ્થિતિ TOK_ASM_vcvteq_u32_f64:
    સ્થિતિ TOK_ASM_vcvteq_f64_s32:
    સ્થિતિ TOK_ASM_vcvteq_f64_u32:
    સ્થિતિ TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       તોડો;
    સ્થિતિ TOK_ASM_vcvtreq_s32_f32:
    સ્થિતિ TOK_ASM_vcvtreq_u32_f32:
    સ્થિતિ TOK_ASM_vcvteq_s32_f32:
    સ્થિતિ TOK_ASM_vcvteq_u32_f32:
    સ્થિતિ TOK_ASM_vcvteq_f32_s32:
    સ્થિતિ TOK_ASM_vcvteq_f32_u32:
    સ્થિતિ TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       તોડો;
    મૂળભૂત:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, ખાલી));
    }

    parse_operand(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_vcvtreq_s32_f32:
    સ્થિતિ TOK_ASM_vcvtreq_s32_f64:
    સ્થિતિ TOK_ASM_vcvteq_s32_f32:
    સ્થિતિ TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    સ્થિતિ TOK_ASM_vcvteq_u32_f32:
    સ્થિતિ TOK_ASM_vcvteq_u32_f64:
    સ્થિતિ TOK_ASM_vcvtreq_u32_f32:
    સ્થિતિ TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        તોડો;
    /* floating-point size conversion */
    સ્થિતિ TOK_ASM_vcvteq_f64_f32:
    સ્થિતિ TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        તોડો;
    }

    skip(',');
    parse_operand(s1, &ops[2]);

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    /* floating-point -> integer */
    સ્થિતિ TOK_ASM_vcvteq_s32_f32:
    સ્થિતિ TOK_ASM_vcvteq_s32_f64:
    સ્થિતિ TOK_ASM_vcvteq_u32_f32:
    સ્થિતિ TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        તોડો;

    /* integer -> floating-point */
    સ્થિતિ TOK_ASM_vcvteq_f64_s32:
    સ્થિતિ TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        તોડો;

    /* floating-point size conversion */
    સ્થિતિ TOK_ASM_vcvteq_f64_f32:
    સ્થિતિ TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        તોડો;
    }

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_vcvteq_f64_u32:
    સ્થિતિ TOK_ASM_vcvteq_f64_s32:
    સ્થિતિ TOK_ASM_vcvteq_f64_f32:
        જો (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } નહીંતર {
            expect("d<number>, s<number>");
        }
        તોડો;
    મૂળભૂત:
        જો (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            જો (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } નહીંતર {
                expect("s<number>, s<number>");
            }
        } નહીંતર જો (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            જો (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } નહીંતર {
                expect("s<number>, d<number>");
            }
        }
    }

    જો (ops[2].type == OP_VREG32) {
        જો (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    જો (ops[0].type == OP_VREG32) {
        જો (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

સ્થિર શૂન્ય asm_floating_point_data_processing_opcode(TCCState *s1, પૂર્ણાંક token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    Operand ops[3];
    uint8_t nb_ops = 0;
    પૂર્ણાંક vmov = 0;
    પૂર્ણાંક nb_arm_regs = 0;

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

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_vmlaeq_f64:
    સ્થિતિ TOK_ASM_vmlseq_f64:
    સ્થિતિ TOK_ASM_vnmlseq_f64:
    સ્થિતિ TOK_ASM_vnmlaeq_f64:
    સ્થિતિ TOK_ASM_vmuleq_f64:
    સ્થિતિ TOK_ASM_vnmuleq_f64:
    સ્થિતિ TOK_ASM_vaddeq_f64:
    સ્થિતિ TOK_ASM_vsubeq_f64:
    સ્થિતિ TOK_ASM_vdiveq_f64:
    સ્થિતિ TOK_ASM_vnegeq_f64:
    સ્થિતિ TOK_ASM_vabseq_f64:
    સ્થિતિ TOK_ASM_vsqrteq_f64:
    સ્થિતિ TOK_ASM_vcmpeq_f64:
    સ્થિતિ TOK_ASM_vcmpeeq_f64:
    સ્થિતિ TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_vmoveq_f32:
    સ્થિતિ TOK_ASM_vmoveq_f64:
        vmov = 1;
        તોડો;
    }

    માટે (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        જો (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_point_immediate_data_processing_opcode_tail(s1, token, coprocessor, ops[0].reg);
            પાછા;
        }
        parse_operand(s1, &ops[nb_ops]);
        જો (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } નહીંતર જો (ops[nb_ops].type == OP_VREG32) {
            જો (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } નહીંતર જો (ops[nb_ops].type == OP_VREG64) {
            જો (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } નહીંતર {
            expect("floating point register");
        }
        ++nb_ops;
        જો (tok == ',')
            next();
        નહીંતર
            તોડો;
    }

    જો (nb_arm_regs == 0) {
        જો (nb_ops == 2) { // implicit
            memcpy(&ops[2], &ops[1], કદ(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], કદ(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        જો (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, ખાલી), nb_ops);
        }
    }

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_vmlaeq_f32:
    સ્થિતિ TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        તોડો;
    સ્થિતિ TOK_ASM_vmlseq_f32:
    સ્થિતિ TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        તોડો;
    સ્થિતિ TOK_ASM_vnmlseq_f32:
    સ્થિતિ TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        તોડો;
    સ્થિતિ TOK_ASM_vnmlaeq_f32:
    સ્થિતિ TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        તોડો;
    સ્થિતિ TOK_ASM_vmuleq_f32:
    સ્થિતિ TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        તોડો;
    સ્થિતિ TOK_ASM_vnmuleq_f32:
    સ્થિતિ TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        તોડો;
    સ્થિતિ TOK_ASM_vaddeq_f32:
    સ્થિતિ TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        તોડો;
    સ્થિતિ TOK_ASM_vsubeq_f32:
    સ્થિતિ TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        તોડો;
    સ્થિતિ TOK_ASM_vdiveq_f32:
    સ્થિતિ TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        તોડો;
    સ્થિતિ TOK_ASM_vnegeq_f32:
    સ્થિતિ TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        તોડો;
    સ્થિતિ TOK_ASM_vabseq_f32:
    સ્થિતિ TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        તોડો;
    સ્થિતિ TOK_ASM_vsqrteq_f32:
    સ્થિતિ TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        તોડો;
    સ્થિતિ TOK_ASM_vcmpeq_f32:
    સ્થિતિ TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        તોડો;
    સ્થિતિ TOK_ASM_vcmpeeq_f32:
    સ્થિતિ TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        તોડો;
    સ્થિતિ TOK_ASM_vmoveq_f32:
    સ્થિતિ TOK_ASM_vmoveq_f64:
        જો (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_point_reg_arm_reg_transfer_opcode_tail(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            પાછા;
        } નહીંતર {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        તોડો;
    મૂળભૂત:
        expect("known floating point instruction");
    }

    જો (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        જો (ops[2].type == OP_VREG32) {
            જો (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        જો (ops[1].type == OP_VREG32) {
            જો (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        જો (ops[0].type == OP_VREG32) {
            જો (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

સ્થિર પૂર્ણાંક asm_parse_vfp_status_regvar(પૂર્ણાંક t)
{
    પસંદગી (t) {
    સ્થિતિ TOK_ASM_fpsid:
        પાછા 0;
    સ્થિતિ TOK_ASM_fpscr:
        પાછા 1;
    સ્થિતિ TOK_ASM_fpexc:
        પાછા 8;
    મૂળભૂત:
        પાછા -1;
    }
}

સ્થિર શૂન્ય asm_floating_point_status_register_opcode(TCCState* s1, પૂર્ણાંક token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    પૂર્ણાંક vfp_sys_reg = -1;
    Operand arm_operand;
    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_vmrseq:
        opcode = 0xf;
        જો (tok == TOK_ASM_apsr_nzcv) {
            arm_operand.type = OP_REG32;
            arm_operand.reg = 15; // not PC
            next(); // skip apsr_nzcv
        } નહીંતર {
            parse_operand(s1, &arm_operand);
            જો (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ખાલી));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        જો (arm_operand.type == OP_REG32 && arm_operand.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, ખાલી));
        }
        તોડો;
    સ્થિતિ TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        skip(',');
        parse_operand(s1, &arm_operand);
        જો (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ખાલી));
        }
        તોડો;
    મૂળભૂત:
        expect("floating point status register instruction");
    }
    જો (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    જો (arm_operand.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode, arm_operand.reg, vfp_sys_reg, 0x10, 0, 0);
}

#endif

સ્થિર શૂન્ય asm_misc_single_data_transfer_opcode(TCCState *s1, પૂર્ણાંક token)
{
    Operand ops[3];
    પૂર્ણાંક exclam = 0;
    પૂર્ણાંક closed_bracket = 0;
    પૂર્ણાંક op2_minus = 0;
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
    જો (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    નહીંતર {
        expect("(destination operand) register");
    }
    જો (tok != ',')
        expect("at least two arguments");
    નહીંતર
        next(); // skip ','
    skip('[');
    parse_operand(s1, &ops[1]);
    જો (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    નહીંતર {
        expect("(first source operand) register");
    }
    જો (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    જો (tok == ',') {
        next(); // skip ','
        જો (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
    } નહીંતર {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    જો (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        જો (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    જો (exclam) {
        જો ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, ખાલી));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    જો (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        પૂર્ણાંક v = ops[2].e.v;
        જો (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        જો (v >= 0) {
            opcode |= 1 << 23; // up
            જો (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ખાલી));
            નહીંતર {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } નહીંતર { // down
            જો (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ખાલી));
            નહીંતર {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } નહીંતર જો (ops[2].type == OP_REG32) {
        જો (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ops[2].reg;
    } નહીંતર
        expect("register");

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    સ્થિતિ TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        તોડો;
    સ્થિતિ TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        તોડો;
    સ્થિતિ TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        તોડો;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
સ્થિર uint32_t encbranchoffset(પૂર્ણાંક pos, પૂર્ણાંક addr, પૂર્ણાંક fail)
{
  addr-=pos+8;
  addr/=4;
  જો(addr>=0x7fffff || addr<-0x800000) {
    જો(fail)
      tcc_error("branch offset is too far");
    પાછા 0;
  }
  પાછા /*not 0x0A000000|*/(addr&0xffffff);
}

સ્થિર શૂન્ય asm_branch_opcode(TCCState *s1, પૂર્ણાંક token)
{
    પૂર્ણાંક jmp_disp = 0;
    Operand op;
    પદાવલિ_કિંમત e;
    ElfSym *esym;

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_beq:
    સ્થિતિ TOK_ASM_bleq:
        asm_પદાવલિ(s1, &e);
        જો (e.sym) {
            esym = elfsym(e.sym);
            જો (esym && esym->st_shndx == cur_text_section->sh_અંક) {
                jmp_disp = esym->st_કિંમત;
            } નહીંતર {
                greloca(cur_text_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        તોડો;
    મૂળભૂત:
        parse_operand(s1, &op);
        તોડો;
    }
    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        તોડો;
    સ્થિતિ TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        તોડો;
    સ્થિતિ TOK_ASM_bxeq:
        જો (op.type != OP_REG32)
            expect("register");
        નહીંતર
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        તોડો;
    સ્થિતિ TOK_ASM_blxeq:
        જો (op.type != OP_REG32)
            expect("register");
        નહીંતર
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        તોડો;
    મૂળભૂત:
        expect("branch instruction");
    }
}

ST_FUNC શૂન્ય asm_opcode(TCCState *s1, પૂર્ણાંક token)
{
    જ્યારે (token == TOK_LINEFEED) {
        next();
        token = tok;
    }
    જો (token == TOK_EOF)
        પાછા;
    જો (token < TOK_ASM_nopeq) { // no condition code
        પસંદગી (token) {
        સ્થિતિ TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            પાછા;
        સ્થિતિ TOK_ASM_ldc2:
        સ્થિતિ TOK_ASM_ldc2l:
        સ્થિતિ TOK_ASM_stc2:
        સ્થિતિ TOK_ASM_stc2l:
            asm_coprocessor_data_transfer_opcode(s1, token);
            પાછા;
        મૂળભૂત:
            expect("instruction");
        }
    }

    પસંદગી (ARM_INSTRUCTION_GROUP(token)) {
    સ્થિતિ TOK_ASM_pusheq:
    સ્થિતિ TOK_ASM_popeq:
    સ્થિતિ TOK_ASM_stmdaeq:
    સ્થિતિ TOK_ASM_ldmdaeq:
    સ્થિતિ TOK_ASM_stmeq:
    સ્થિતિ TOK_ASM_ldmeq:
    સ્થિતિ TOK_ASM_stmiaeq:
    સ્થિતિ TOK_ASM_ldmiaeq:
    સ્થિતિ TOK_ASM_stmdbeq:
    સ્થિતિ TOK_ASM_ldmdbeq:
    સ્થિતિ TOK_ASM_stmibeq:
    સ્થિતિ TOK_ASM_ldmibeq:
        asm_block_data_transfer_opcode(s1, token);
        પાછા;
    સ્થિતિ TOK_ASM_nopeq:
    સ્થિતિ TOK_ASM_wfeeq:
    સ્થિતિ TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        પાછા;
    સ્થિતિ TOK_ASM_swieq:
    સ્થિતિ TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        પાછા;
    સ્થિતિ TOK_ASM_beq:
    સ્થિતિ TOK_ASM_bleq:
    સ્થિતિ TOK_ASM_bxeq:
    સ્થિતિ TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        પાછા;
    સ્થિતિ TOK_ASM_clzeq:
    સ્થિતિ TOK_ASM_sxtbeq:
    સ્થિતિ TOK_ASM_sxtheq:
    સ્થિતિ TOK_ASM_uxtbeq:
    સ્થિતિ TOK_ASM_uxtheq:
    સ્થિતિ TOK_ASM_movteq:
    સ્થિતિ TOK_ASM_movweq:
        asm_દ્વિઅંકી_opcode(s1, token);
        પાછા;

    સ્થિતિ TOK_ASM_ldreq:
    સ્થિતિ TOK_ASM_ldrbeq:
    સ્થિતિ TOK_ASM_streq:
    સ્થિતિ TOK_ASM_strbeq:
    સ્થિતિ TOK_ASM_ldrexeq:
    સ્થિતિ TOK_ASM_ldrexbeq:
    સ્થિતિ TOK_ASM_ldrexheq:
    સ્થિતિ TOK_ASM_strexeq:
    સ્થિતિ TOK_ASM_strexbeq:
    સ્થિતિ TOK_ASM_strexheq:
        asm_single_data_transfer_opcode(s1, token);
        પાછા;

    સ્થિતિ TOK_ASM_ldrheq:
    સ્થિતિ TOK_ASM_ldrsheq:
    સ્થિતિ TOK_ASM_ldrsbeq:
    સ્થિતિ TOK_ASM_strheq:
       asm_misc_single_data_transfer_opcode(s1, token);
       પાછા;

    સ્થિતિ TOK_ASM_andeq:
    સ્થિતિ TOK_ASM_eoreq:
    સ્થિતિ TOK_ASM_subeq:
    સ્થિતિ TOK_ASM_rsbeq:
    સ્થિતિ TOK_ASM_addeq:
    સ્થિતિ TOK_ASM_adceq:
    સ્થિતિ TOK_ASM_sbceq:
    સ્થિતિ TOK_ASM_rsceq:
    સ્થિતિ TOK_ASM_tsteq:
    સ્થિતિ TOK_ASM_teqeq:
    સ્થિતિ TOK_ASM_cmpeq:
    સ્થિતિ TOK_ASM_cmneq:
    સ્થિતિ TOK_ASM_orreq:
    સ્થિતિ TOK_ASM_moveq:
    સ્થિતિ TOK_ASM_biceq:
    સ્થિતિ TOK_ASM_mvneq:
    સ્થિતિ TOK_ASM_andseq:
    સ્થિતિ TOK_ASM_eorseq:
    સ્થિતિ TOK_ASM_subseq:
    સ્થિતિ TOK_ASM_rsbseq:
    સ્થિતિ TOK_ASM_addseq:
    સ્થિતિ TOK_ASM_adcseq:
    સ્થિતિ TOK_ASM_sbcseq:
    સ્થિતિ TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    સ્થિતિ TOK_ASM_orrseq:
    સ્થિતિ TOK_ASM_movseq:
    સ્થિતિ TOK_ASM_bicseq:
    સ્થિતિ TOK_ASM_mvnseq:
        asm_data_processing_opcode(s1, token);
        પાછા;

    સ્થિતિ TOK_ASM_lsleq:
    સ્થિતિ TOK_ASM_lslseq:
    સ્થિતિ TOK_ASM_lsreq:
    સ્થિતિ TOK_ASM_lsrseq:
    સ્થિતિ TOK_ASM_asreq:
    સ્થિતિ TOK_ASM_asrseq:
    સ્થિતિ TOK_ASM_roreq:
    સ્થિતિ TOK_ASM_rorseq:
    સ્થિતિ TOK_ASM_rrxseq:
    સ્થિતિ TOK_ASM_rrxeq:
        asm_shift_opcode(s1, token);
        પાછા;

    સ્થિતિ TOK_ASM_muleq:
    સ્થિતિ TOK_ASM_mulseq:
    સ્થિતિ TOK_ASM_mlaeq:
    સ્થિતિ TOK_ASM_mlaseq:
    સ્થિતિ TOK_ASM_mlseq:
    સ્થિતિ TOK_ASM_udiveq:
    સ્થિતિ TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        પાછા;

    સ્થિતિ TOK_ASM_smulleq:
    સ્થિતિ TOK_ASM_smullseq:
    સ્થિતિ TOK_ASM_umulleq:
    સ્થિતિ TOK_ASM_umullseq:
    સ્થિતિ TOK_ASM_smlaleq:
    સ્થિતિ TOK_ASM_smlalseq:
    સ્થિતિ TOK_ASM_umlaleq:
    સ્થિતિ TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        પાછા;

    સ્થિતિ TOK_ASM_cdpeq:
    સ્થિતિ TOK_ASM_mcreq:
    સ્થિતિ TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        પાછા;

    સ્થિતિ TOK_ASM_ldceq:
    સ્થિતિ TOK_ASM_ldcleq:
    સ્થિતિ TOK_ASM_stceq:
    સ્થિતિ TOK_ASM_stcleq:
        asm_coprocessor_data_transfer_opcode(s1, token);
        પાછા;

#જો defined(TCC_ARM_VFP)
    સ્થિતિ TOK_ASM_vldreq:
    સ્થિતિ TOK_ASM_vstreq:
        asm_floating_point_single_data_transfer_opcode(s1, token);
        પાછા;

    સ્થિતિ TOK_ASM_vmlaeq_f32:
    સ્થિતિ TOK_ASM_vmlseq_f32:
    સ્થિતિ TOK_ASM_vnmlseq_f32:
    સ્થિતિ TOK_ASM_vnmlaeq_f32:
    સ્થિતિ TOK_ASM_vmuleq_f32:
    સ્થિતિ TOK_ASM_vnmuleq_f32:
    સ્થિતિ TOK_ASM_vaddeq_f32:
    સ્થિતિ TOK_ASM_vsubeq_f32:
    સ્થિતિ TOK_ASM_vdiveq_f32:
    સ્થિતિ TOK_ASM_vnegeq_f32:
    સ્થિતિ TOK_ASM_vabseq_f32:
    સ્થિતિ TOK_ASM_vsqrteq_f32:
    સ્થિતિ TOK_ASM_vcmpeq_f32:
    સ્થિતિ TOK_ASM_vcmpeeq_f32:
    સ્થિતિ TOK_ASM_vmoveq_f32:
    સ્થિતિ TOK_ASM_vmlaeq_f64:
    સ્થિતિ TOK_ASM_vmlseq_f64:
    સ્થિતિ TOK_ASM_vnmlseq_f64:
    સ્થિતિ TOK_ASM_vnmlaeq_f64:
    સ્થિતિ TOK_ASM_vmuleq_f64:
    સ્થિતિ TOK_ASM_vnmuleq_f64:
    સ્થિતિ TOK_ASM_vaddeq_f64:
    સ્થિતિ TOK_ASM_vsubeq_f64:
    સ્થિતિ TOK_ASM_vdiveq_f64:
    સ્થિતિ TOK_ASM_vnegeq_f64:
    સ્થિતિ TOK_ASM_vabseq_f64:
    સ્થિતિ TOK_ASM_vsqrteq_f64:
    સ્થિતિ TOK_ASM_vcmpeq_f64:
    સ્થિતિ TOK_ASM_vcmpeeq_f64:
    સ્થિતિ TOK_ASM_vmoveq_f64:
        asm_floating_point_data_processing_opcode(s1, token);
        પાછા;

    સ્થિતિ TOK_ASM_vcvtreq_s32_f32:
    સ્થિતિ TOK_ASM_vcvtreq_s32_f64:
    સ્થિતિ TOK_ASM_vcvteq_s32_f32:
    સ્થિતિ TOK_ASM_vcvteq_s32_f64:
    સ્થિતિ TOK_ASM_vcvtreq_u32_f32:
    સ્થિતિ TOK_ASM_vcvtreq_u32_f64:
    સ્થિતિ TOK_ASM_vcvteq_u32_f32:
    સ્થિતિ TOK_ASM_vcvteq_u32_f64:
    સ્થિતિ TOK_ASM_vcvteq_f64_s32:
    સ્થિતિ TOK_ASM_vcvteq_f32_s32:
    સ્થિતિ TOK_ASM_vcvteq_f64_u32:
    સ્થિતિ TOK_ASM_vcvteq_f32_u32:
    સ્થિતિ TOK_ASM_vcvteq_f64_f32:
    સ્થિતિ TOK_ASM_vcvteq_f32_f64:
        asm_floating_point_vcvt_data_processing_opcode(s1, token);
        પાછા;

    સ્થિતિ TOK_ASM_vpusheq:
    સ્થિતિ TOK_ASM_vpopeq:
    સ્થિતિ TOK_ASM_vldmeq:
    સ્થિતિ TOK_ASM_vldmiaeq:
    સ્થિતિ TOK_ASM_vldmdbeq:
    સ્થિતિ TOK_ASM_vstmeq:
    સ્થિતિ TOK_ASM_vstmiaeq:
    સ્થિતિ TOK_ASM_vstmdbeq:
        asm_floating_point_block_data_transfer_opcode(s1, token);
        પાછા;

    સ્થિતિ TOK_ASM_vmsreq:
    સ્થિતિ TOK_ASM_vmrseq:
        asm_floating_point_status_register_opcode(s1, token);
        પાછા;
#endif

    મૂળભૂત:
        expect("known instruction");
    }
}

ST_FUNC શૂન્ય subst_asm_operand(CString *add_str, SValue *sv, પૂર્ણાંક modifier)
{
    પૂર્ણાંક r, reg, size, val;

    r = sv->r;
    જો ((r & VT_VALMASK) == VT_CONST) {
        જો (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        જો (r & VT_SYM) {
            અચલ અક્ષર *name = get_tok_str(sv->sym->v, ખાલી);
            જો (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            જો (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            જો ((uint32_t) sv->c.i == 0)
                જાઓ no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        જો (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
      no_offset:;
    } નહીંતર જો ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[fp,#%d]", (પૂર્ણાંક) sv->c.i);
    } નહીંતર જો (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        જો (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, ખાલી));
    } નહીંતર {
        /* register case */
        reg = r & VT_VALMASK;
        જો (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        જો ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        નહીંતર જો ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        નહીંતર
            size = 4;

        જો (modifier == 'b') {
            size = 1;
        } નહીંતર જો (modifier == 'w') {
            size = 2;
        } નહીંતર જો (modifier == 'k') {
            size = 4;
        }

        પસંદગી (size) {
        મૂળભૂત:
            reg = TOK_ASM_r0 + reg;
            તોડો;
        }
        cstr_printf(add_str, "%s", get_tok_str(reg, ખાલી));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC શૂન્ય asm_gen_code(ASMOperand *operands, પૂર્ણાંક nb_operands,
                          પૂર્ણાંક nb_outputs, પૂર્ણાંક is_output,
                          uint8_t *clobber_regs,
                          પૂર્ણાંક out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    પૂર્ણાંક i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    સ્થિર અચલ uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, કદ(regs_allocated));
    માટે(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        જો (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    માટે(i = 0; i < કદ(reg_saved)/કદ(reg_saved[0]); i++) {
        reg = reg_saved[i];
        જો (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    જો (!is_output) { // prolog
        /* generate reg save code */
        જો (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        માટે(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            જો (op->reg >= 0) {
                જો ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } નહીંતર જો (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    load(op->reg, op->vt);
                    જો (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } નહીંતર { // epilog
        /* generate save code */
        માટે(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            જો (op->reg >= 0) {
                જો ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    જો (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } નહીંતર {
                    store(op->reg, op->vt);
                    જો (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        જો (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
સ્થિર અંતઃરેખ પૂર્ણાંક constraint_priority(અચલ અક્ષર *str)
{
    પૂર્ણાંક priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    માટે(;;) {
        c = *str;
        જો (c == '\0')
            તોડો;
        str++;
        પસંદગી(c) {
        સ્થિતિ 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        સ્થિતિ 'r': // register [general]
        સ્થિતિ 'p': // valid memory address for load,store [general]
            pr = 3;
            તોડો;
        સ્થિતિ 'M': // integer constant for shifts [ARM]
        સ્થિતિ 'I': // integer valid for data processing instruction immediate
        સ્થિતિ 'J': // integer in range -4095...4095

        સ્થિતિ 'i': // immediate integer operand, including symbolic constants [general]
        સ્થિતિ 'm': // memory operand [general]
        સ્થિતિ 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            તોડો;
        મૂળભૂત:
            tcc_error("unknown constraint '%c'", c);
        }
        જો (pr > priority)
            priority = pr;
    }
    પાછા priority;
}

સ્થિર અચલ અક્ષર *skip_constraint_modifiers(અચલ અક્ષર *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    જ્યારે (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    પાછા p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC શૂન્ય asm_compute_constraints(ASMOperand *operands,
                                    પૂર્ણાંક nb_operands, પૂર્ણાંક nb_outputs,
                                    અચલ uint8_t *clobber_regs,
                                    પૂર્ણાંક *pout_reg)
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
    પૂર્ણાંક sorted_op[MAX_ASM_OPERANDS];
    પૂર્ણાંક i, j, k, p1, p2, tmp, reg, c, reg_mask;
    અચલ અક્ષર *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    માટે (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->આગત_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    માટે (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        જો (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, ખાલી);
            જો ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            જો (operands[k].આગત_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].આગત_index = i;
            op->priority = 5;
        } નહીંતર જો ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } નહીંતર {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    માટે (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    માટે (i = 0; i < nb_operands - 1; i++) {
        માટે (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            જો (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    માટે (i = 0; i < NB_ASM_REGS; i++) {
        જો (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        નહીંતર
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_IN_MASK | REG_OUT_MASK;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    માટે (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        જો (op->ref_index >= 0)
            ચાલુ;
        /* select if register is used for output, input or both */
        જો (op->આગત_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } નહીંતર જો (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } નહીંતર {
            reg_mask = REG_IN_MASK;
        }
        જો (op->reg >= 0) {
            જો (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        પસંદગી (c) {
        સ્થિતિ '=': // Operand is written-to
            જાઓ try_next;
        સ્થિતિ '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        સ્થિતિ '&': // Operand is clobbered before the instruction is done using the input operands
            જો (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            જાઓ try_next;
        સ્થિતિ 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        સ્થિતિ 'r': // general-purpose register
        સ્થિતિ 'p': // loadable/storable address
            /* any general register */
            જો ((reg = op->reg) >= 0)
                જાઓ reg_found;
            નહીંતર માટે (reg = 0; reg <= 8; reg++) {
                જો (!is_reg_allocated(reg))
                    જાઓ reg_found;
            }
            જાઓ try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            તોડો;
        સ્થિતિ 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        સ્થિતિ 'J': // integer in the range -4095 to 4095 [ARM]
        સ્થિતિ 'K': // integer that satisfies constraint I when inverted (one's complement)
        સ્થિતિ 'L': // integer that satisfies constraint I when inverted (two's complement)
        સ્થિતિ 'i': // immediate integer operand, including symbolic constants
            જો (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                જાઓ try_next;
            તોડો;
        સ્થિતિ 'M': // integer in the range 0 to 32
            જો (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                જાઓ try_next;
            તોડો;
        સ્થિતિ 'm': // memory operand
        સ્થિતિ 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            જો (j < nb_outputs || c == 'm') {
                જો ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    માટે (reg = 0; reg <= 8; reg++) {
                        જો (!(regs_allocated[reg] & REG_IN_MASK))
                            જાઓ reg_found1;
                    }
                    જાઓ try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            તોડો;
        મૂળભૂત:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            તોડો;
        }
        /* if a reference is present for that operand, we assign it too */
        જો (op->આગત_index >= 0) {
            operands[op->આગત_index].reg = op->reg;
            operands[op->આગત_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    માટે (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        જો (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            માટે (reg = 0; reg <= 8; reg++) {
                જો (!(regs_allocated[reg] & REG_OUT_MASK))
                    જાઓ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            તોડો;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    માટે (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ખાલી) : "",
               op->constraint, op->vt->r, op->reg);
    }
    જો (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC શૂન્ય asm_clobber(uint8_t *clobber_regs, અચલ અક્ષર *str)
{
    પૂર્ણાંક reg;
    TokenSym *ts;

    જો (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        પાછા;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    જો (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC પૂર્ણાંક asm_parse_regvar (પૂર્ણાંક t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    જો (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        પાછા -1;

    જો (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        પાછા t - TOK_ASM_r0;

    જો (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        પાછા t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    પાછા t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
