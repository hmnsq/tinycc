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

ST_FUNC ശൂന്യം g(പൂർണ്ണസംഖ്യ c);
ST_FUNC ശൂന്യം gen_le16(പൂർണ്ണസംഖ്യ c);
ST_FUNC ശൂന്യം gen_le32(പൂർണ്ണസംഖ്യ c);

/*************************************************************/
#അല്ലെങ്കിൽ
/*************************************************************/

#define USING_GLOBALS
#അന്തര്ഭാവ "tcc.h"

എണ്ണൽ {
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

തരനിർവചനം ഘടന Operand {
    uint32_t type;
    സംഘം {
        uint8_t reg;
        uint16_t regset;
        വ്യഞ്ജകം_മൂല്യം e;
    };
} Operand;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
സ്ഥിതം പൂർണ്ണസംഖ്യ asm_parse_vfp_regvar(പൂർണ്ണസംഖ്യ t, പൂർണ്ണസംഖ്യ double_precision)
{
    എങ്കിൽ (double_precision) {
        എങ്കിൽ (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            തിരികെ t - TOK_ASM_d0;
    } അല്ലെങ്കിൽ {
        എങ്കിൽ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            തിരികെ t - TOK_ASM_s0;
    }
    തിരികെ -1;
}

/* Parse a text containing operand and store the result in OP */
സ്ഥിതം ശൂന്യം parse_operand(TCCState *s1, Operand *op)
{
    വ്യഞ്ജകം_മൂല്യം e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    എങ്കിൽ (tok == '{') { // regset literal
        next(); // skip '{'
        ആകുമ്പോൾ (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            എങ്കിൽ (reg == -1) {
                expect("register");
            } അല്ലെങ്കിൽ
                next(); // skip register name

            എങ്കിൽ ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            എങ്കിൽ (tok != ',')
                നിർത്തുക;
            next(); // skip ','
        }
        skip('}');
        എങ്കിൽ (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } അല്ലെങ്കിൽ {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        തിരികെ;
    } അല്ലെങ്കിൽ എങ്കിൽ ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        തിരികെ;
    } അല്ലെങ്കിൽ എങ്കിൽ ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        next(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        തിരികെ;
    } അല്ലെങ്കിൽ എങ്കിൽ ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        next(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        തിരികെ;
    } അല്ലെങ്കിൽ എങ്കിൽ (tok == '#' || tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    }
    asm_വ്യഞ്ജകം(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    എങ്കിൽ (!op->e.sym) {
        എങ്കിൽ ((പൂർണ്ണസംഖ്യ) op->e.v < 0 && (പൂർണ്ണസംഖ്യ) op->e.v >= -255)
            op->type = OP_IM8N;
        അല്ലെങ്കിൽ എങ്കിൽ (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } അല്ലെങ്കിൽ
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC ശൂന്യം g(പൂർണ്ണസംഖ്യ c)
{
    പൂർണ്ണസംഖ്യ ind1;
    എങ്കിൽ (nocode_wanted)
        തിരികെ;
    ind1 = ind + 1;
    എങ്കിൽ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC ശൂന്യം gen_le16 (പൂർണ്ണസംഖ്യ i)
{
    g(i);
    g(i>>8);
}

ST_FUNC ശൂന്യം gen_le32 (പൂർണ്ണസംഖ്യ i)
{
    പൂർണ്ണസംഖ്യ ind1;
    എങ്കിൽ (nocode_wanted)
        തിരികെ;
    ind1 = ind + 4;
    എങ്കിൽ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC ശൂന്യം gen_expr32(വ്യഞ്ജകം_മൂല്യം *pe)
{
    gen_le32(pe->v);
}

സ്ഥിതം uint32_t condition_code_of_token(പൂർണ്ണസംഖ്യ token) {
    എങ്കിൽ (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } അല്ലെങ്കിൽ
        തിരികെ (token - TOK_ASM_nopeq) & 15;
}

സ്ഥിതം ശൂന്യം asm_emit_opcode(പൂർണ്ണസംഖ്യ token, uint32_t opcode) {
    gen_le32((condition_code_of_token(token) << 28) | opcode);
}

സ്ഥിതം ശൂന്യം asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

സ്ഥിതം ശൂന്യം asm_emit_coprocessor_opcode(uint32_t മുകളിലെ_nibble, uint8_t cp_സംഖ്യ, uint8_t cp_opcode, uint8_t cp_destination_register, uint8_t cp_n_operand_register, uint8_t cp_m_operand_register, uint8_t cp_opcode2, പൂർണ്ണസംഖ്യ inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    എങ്കിൽ (inter_processor_transfer)
        opcode |= 1 << 4;
    //assert(cp_opcode < 16);
    opcode |= cp_opcode << 20;
    //assert(cp_n_operand_register < 16);
    opcode |= cp_n_operand_register << 16;
    //assert(cp_destination_register < 16);
    opcode |= cp_destination_register << 12;
    //assert(cp_number < 16);
    opcode |= cp_സംഖ്യ << 8;
    //assert(cp_information < 8);
    opcode |= cp_opcode2 << 5;
    //assert(cp_m_operand_register < 16);
    opcode |= cp_m_operand_register;
    asm_emit_unconditional_opcode((മുകളിലെ_nibble << 28) | opcode);
}

സ്ഥിതം ശൂന്യം asm_nullary_opcode(പൂർണ്ണസംഖ്യ token)
{
    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    അവസ്ഥ TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("nullary instruction");
    }
}

സ്ഥിതം ശൂന്യം asm_unary_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand op;
    parse_operand(s1, &op);

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_swieq:
    അവസ്ഥ TOK_ASM_svceq:
        എങ്കിൽ (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        അല്ലെങ്കിൽ {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("unary instruction");
    }
}

സ്ഥിതം ശൂന്യം asm_ദ്വിമാന_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand ops[2];
    Operand rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);
    എങ്കിൽ (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    എങ്കിൽ (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ശൂന്യ));

    എങ്കിൽ (ops[1].type != OP_REG32) {
        തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
        അവസ്ഥ TOK_ASM_movteq:
        അവസ്ഥ TOK_ASM_movweq:
            എങ്കിൽ (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                എങ്കിൽ (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t immediate_മൂല്യം = ops[1].e.v;
                    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
                    അവസ്ഥ TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (immediate_മൂല്യം & 0xF000) << 4 | (immediate_മൂല്യം & 0xFFF));
                        നിർത്തുക;
                    അവസ്ഥ TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (immediate_മൂല്യം & 0xF000) << 4 | (immediate_മൂല്യം & 0xFFF));
                        നിർത്തുക;
                    }
                } അല്ലെങ്കിൽ
                    expect("(source operand) immediate 16 bit value");
            } അല്ലെങ്കിൽ
                expect("(source operand) immediate");
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            expect("(source operand) register");
        }
        തിരികെ;
    }

    എങ്കിൽ (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ശൂന്യ));

    എങ്കിൽ (tok == ',') {
        next(); // skip ','
        എങ്കിൽ (tok == TOK_ASM_ror) {
            next(); // skip 'ror'
            parse_operand(s1, &rotation);
            എങ്കിൽ (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } അല്ലെങ്കിൽ {
                amount = rotation.e.v;
                തിരഞ്ഞെടുപ്പ് (amount) {
                അവസ്ഥ 8:
                    encoded_rotation = 1 << 10;
                    നിർത്തുക;
                അവസ്ഥ 16:
                    encoded_rotation = 2 << 10;
                    നിർത്തുക;
                അവസ്ഥ 24:
                    encoded_rotation = 3 << 10;
                    നിർത്തുക;
                സ്ഥിരസ്ഥിതി:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_clzeq:
        എങ്കിൽ (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("binary instruction");
    }
}

സ്ഥിതം ശൂന്യം asm_coprocessor_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token) {
    uint8_t coprocessor;
    Operand opcode1;
    Operand opcode2;
    uint8_t registers[3];
    unsigned പൂർണ്ണസംഖ്യ i;
    uint8_t മുകളിലെ_nibble;
    uint8_t mrc = 0;

    എങ്കിൽ (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } അല്ലെങ്കിൽ {
        expect("'p<number>'");
    }
    skip(',');
    parse_operand(s1, &opcode1);
    എങ്കിൽ (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ശൂന്യ));
    }

    വേണ്ടി (i = 0; i < 3; ++i) {
        skip(',');
        എങ്കിൽ (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mcreq)) {
            എങ്കിൽ (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                next();
            } അല്ലെങ്കിൽ {
                expect("'r<number>'");
            }
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                next();
            } അല്ലെങ്കിൽ {
                expect("'c<number>'");
            }
        }
    }
    എങ്കിൽ (tok == ',') {
        next();
        parse_operand(s1, &opcode2);
    } അല്ലെങ്കിൽ {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    എങ്കിൽ (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (token == TOK_ASM_cdp2) {
        മുകളിലെ_nibble = 0xF;
        asm_emit_coprocessor_opcode(മുകളിലെ_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        തിരികെ;
    } അല്ലെങ്കിൽ
        മുകളിലെ_nibble = condition_code_of_token(token);

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(മുകളിലെ_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    അവസ്ഥ TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        എങ്കിൽ (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, ശൂന്യ));
        }
        asm_emit_coprocessor_opcode(മുകളിലെ_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
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
#define ENCODE_BARREL_SHIFTER_IMMEDIATE(മൂല്യം) ((മൂല്യം) << 7)

സ്ഥിതം ശൂന്യം asm_block_data_transfer_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    uint32_t opcode;
    പൂർണ്ണസംഖ്യ op0_exclam = 0;
    Operand ops[2];
    പൂർണ്ണസംഖ്യ nb_ops = 1;
    parse_operand(s1, &ops[0]);
    എങ്കിൽ (tok == '!') {
        op0_exclam = 1;
        next(); // skip '!'
    }
    എങ്കിൽ (tok == ',') {
        next(); // skip comma
        parse_operand(s1, &ops[1]);
        ++nb_ops;
    }
    എങ്കിൽ (nb_ops < 1) {
        expect("at least one operand");
    } അല്ലെങ്കിൽ എങ്കിൽ (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        എങ്കിൽ (nb_ops != 1)
            expect("exactly one operand");
        അല്ലെങ്കിൽ
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        എങ്കിൽ (nb_ops != 1)
            expect("exactly one operand");
        അല്ലെങ്കിൽ
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_stmdaeq:
    അവസ്ഥ TOK_ASM_ldmdaeq:
    അവസ്ഥ TOK_ASM_stmeq:
    അവസ്ഥ TOK_ASM_ldmeq:
    അവസ്ഥ TOK_ASM_stmiaeq:
    അവസ്ഥ TOK_ASM_ldmiaeq:
    അവസ്ഥ TOK_ASM_stmdbeq:
    അവസ്ഥ TOK_ASM_ldmdbeq:
    അവസ്ഥ TOK_ASM_stmibeq:
    അവസ്ഥ TOK_ASM_ldmibeq:
        തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
        അവസ്ഥ TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_stmeq: // post-increment store
        അവസ്ഥ TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_ldmeq: // post-increment load
        അവസ്ഥ TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        എങ്കിൽ (nb_ops != 2)
            expect("exactly two operands");
        അല്ലെങ്കിൽ എങ്കിൽ (ops[0].type != OP_REG32)
            expect("(first operand) register");
        അല്ലെങ്കിൽ {
            എങ്കിൽ (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
സ്ഥിതം uint32_t asm_parse_optional_shift(TCCState* s1, പൂർണ്ണസംഖ്യ* nb_shift, Operand* shift)
{
    uint32_t opcode = 0;
    *nb_shift = 0;
    തിരഞ്ഞെടുപ്പ് (tok) {
    അവസ്ഥ TOK_ASM_asl:
    അവസ്ഥ TOK_ASM_lsl:
    അവസ്ഥ TOK_ASM_asr:
    അവസ്ഥ TOK_ASM_lsr:
    അവസ്ഥ TOK_ASM_ror:
        തിരഞ്ഞെടുപ്പ് (tok) {
        അവസ്ഥ TOK_ASM_asl:
            /* fallthrough */
        അവസ്ഥ TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSL;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ASR;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSR;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
            നിർത്തുക;
        }
        next();
        parse_operand(s1, shift);
        *nb_shift = 1;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_rrx:
        next();
        opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
        നിർത്തുക;
    }
    തിരികെ opcode;
}

സ്ഥിതം uint32_t asm_encode_shift(Operand* shift)
{
    uint64_t amount;
    uint32_t operands = 0;
    തിരഞ്ഞെടുപ്പ് (shift->type) {
    അവസ്ഥ OP_REG32:
        എങ്കിൽ (shift->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        അല്ലെങ്കിൽ {
            operands = ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER;
            operands |= ENCODE_BARREL_SHIFTER_REGISTER(shift->reg);
        }
        നിർത്തുക;
    അവസ്ഥ OP_IM8:
        amount = shift->e.v;
        എങ്കിൽ (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_IMMEDIATE(amount);
        അല്ലെങ്കിൽ
            tcc_error("shift count out of range");
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        tcc_error("unknown shift amount");
    }
    തിരികെ operands;
}

സ്ഥിതം ശൂന്യം asm_data_processing_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand ops[3];
    പൂർണ്ണസംഖ്യ nb_ops;
    Operand shift = {0};
    പൂർണ്ണസംഖ്യ nb_shift = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_GROUP(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    വേണ്ടി (nb_ops = 0; nb_ops < വലുപ്പം(ops)/വലുപ്പം(ops[0]); ) {
        എങ്കിൽ (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            നിർത്തുക;
        parse_operand(s1, &ops[nb_ops]);
        ++nb_ops;
        എങ്കിൽ (tok != ',')
            നിർത്തുക;
        next(); // skip ','
    }
    എങ്കിൽ (tok == ',')
        next();
    operands |= asm_parse_optional_shift(s1, &nb_shift, &shift);
    എങ്കിൽ (nb_ops < 2)
        expect("at least two operands");
    അല്ലെങ്കിൽ എങ്കിൽ (nb_ops == 2) {
        memcpy(&ops[2], &ops[1], വലുപ്പം(ops[1])); // move ops[2]
        memcpy(&ops[1], &ops[0], വലുപ്പം(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } അല്ലെങ്കിൽ എങ്കിൽ (nb_ops == 3) {
        എങ്കിൽ (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, ശൂന്യ));
        }
    }
    എങ്കിൽ (nb_ops != 3) {
        expect("two or three operands");
    } അല്ലെങ്കിൽ {
        uint32_t opcode = 0;
        uint32_t immediate_മൂല്യം;
        uint8_t half_immediate_rotation;
        എങ്കിൽ (nb_shift && shift.type == OP_REG32) {
            എങ്കിൽ ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
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
        എങ്കിൽ (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        അല്ലെങ്കിൽ എങ്കിൽ (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_SET_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        അല്ലെങ്കിൽ
            operands |= ENCODE_RD(ops[0].reg);
        എങ്കിൽ (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        അല്ലെങ്കിൽ എങ്കിൽ (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        തിരഞ്ഞെടുപ്പ് (ops[2].type) {
        അവസ്ഥ OP_REG32:
            operands |= ops[2].reg;
            നിർത്തുക;
        അവസ്ഥ OP_IM8:
        അവസ്ഥ OP_IM32:
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_മൂല്യം = ops[2].e.v;
            വേണ്ടി (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                എങ്കിൽ (immediate_മൂല്യം >= 0x00 && immediate_മൂല്യം < 0x100)
                    നിർത്തുക;
                // rotate left by two
                immediate_മൂല്യം = ((immediate_മൂല്യം & 0x3FFFFFFF) << 2) | ((immediate_മൂല്യം & 0xC0000000) >> 30);
            }
            എങ്കിൽ (half_immediate_rotation >= 16) {
                /* fallthrough */
            } അല്ലെങ്കിൽ {
                operands |= immediate_മൂല്യം;
                operands |= half_immediate_rotation << 8;
                നിർത്തുക;
            }
        അവസ്ഥ OP_IM8N: // immediate negative value
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_മൂല്യം = ops[2].e.v;
            /* Instruction swapping:
               0001 = EOR - Rd:= Op1 EOR Op2     -> difficult
               0011 = RSB - Rd:= Op2 - Op1       -> difficult
               0111 = RSC - Rd:= Op2 - Op1 + C   -> difficult
               1000 = TST - CC on: Op1 AND Op2   -> difficult
               1001 = TEQ - CC on: Op1 EOR Op2   -> difficult
               1100 = ORR - Rd:= Op1 OR Op2      -> difficult
            */
            തിരഞ്ഞെടുപ്പ് (opcode_nos) {
            അവസ്ഥ 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                immediate_മൂല്യം = ~immediate_മൂല്യം;
                നിർത്തുക;
            അവസ്ഥ 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; // ADD
                immediate_മൂല്യം = -immediate_മൂല്യം;
                നിർത്തുക;
            അവസ്ഥ 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                immediate_മൂല്യം = -immediate_മൂല്യം;
                നിർത്തുക;
            അവസ്ഥ 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                immediate_മൂല്യം = ~immediate_മൂല്യം;
                നിർത്തുക;
            അവസ്ഥ 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                immediate_മൂല്യം = ~immediate_മൂല്യം;
                നിർത്തുക;
            അവസ്ഥ 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                immediate_മൂല്യം = -immediate_മൂല്യം;
                നിർത്തുക;
            അവസ്ഥ 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                immediate_മൂല്യം = -immediate_മൂല്യം;
                നിർത്തുക;
            അവസ്ഥ 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                immediate_മൂല്യം = ~immediate_മൂല്യം;
                നിർത്തുക;
            അവസ്ഥ 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                immediate_മൂല്യം = ~immediate_മൂല്യം;
                നിർത്തുക;
            അവസ്ഥ 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                immediate_മൂല്യം = ~immediate_മൂല്യം;
                നിർത്തുക;
            സ്ഥിരസ്ഥിതി:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, ശൂന്യ));
            }
            വേണ്ടി (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                എങ്കിൽ (immediate_മൂല്യം >= 0x00 && immediate_മൂല്യം < 0x100)
                    നിർത്തുക;
                // rotate left by two
                immediate_മൂല്യം = ((immediate_മൂല്യം & 0x3FFFFFFF) << 2) | ((immediate_മൂല്യം & 0xC0000000) >> 30);
            }
            എങ്കിൽ (half_immediate_rotation >= 16) {
                immediate_മൂല്യം = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (unsigned) immediate_മൂല്യം);
            }
            operands |= immediate_മൂല്യം;
            operands |= half_immediate_rotation << 8;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            expect("(second source operand) register or immediate value");
        }

        എങ്കിൽ (nb_shift) {
            എങ്കിൽ (operands & ENCODE_IMMEDIATE_FLAG)
                tcc_error("immediate rotation not implemented");
            അല്ലെങ്കിൽ
                operands |= asm_encode_shift(&shift);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_SET_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

സ്ഥിതം ശൂന്യം asm_shift_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand ops[3];
    പൂർണ്ണസംഖ്യ nb_ops;
    പൂർണ്ണസംഖ്യ definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    വേണ്ടി (nb_ops = 0; nb_ops < വലുപ്പം(ops)/വലുപ്പം(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        എങ്കിൽ (tok != ',') {
            ++nb_ops;
            നിർത്തുക;
        }
        next(); // skip ','
    }
    എങ്കിൽ (nb_ops < 2) {
        expect("at least two operands");
    }

    എങ്കിൽ (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } അല്ലെങ്കിൽ
        operands |= ENCODE_RD(ops[0].reg);

    എങ്കിൽ (nb_ops == 2) {
        തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
        അവസ്ഥ TOK_ASM_rrxseq:
            opcode |= ENCODE_SET_CONDITION_CODES;
            /* fallthrough */
        അവസ്ഥ TOK_ASM_rrxeq:
            എങ്കിൽ (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
                asm_emit_opcode(token, opcode | operands);
            } അല്ലെങ്കിൽ
                tcc_error("(first source operand) register");
            തിരികെ;
        സ്ഥിരസ്ഥിതി:
            memcpy(&ops[2], &ops[1], വലുപ്പം(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], വലുപ്പം(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    എങ്കിൽ (nb_ops != 3) {
        expect("two or three operands");
    }

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_lslseq:
    അവസ്ഥ TOK_ASM_lsrseq:
    അവസ്ഥ TOK_ASM_asrseq:
    അവസ്ഥ TOK_ASM_rorseq:
        opcode |= ENCODE_SET_CONDITION_CODES;
        നിർത്തുക;
    }

    തിരഞ്ഞെടുപ്പ് (ops[1].type) {
    അവസ്ഥ OP_REG32:
        operands |= ops[1].reg;
        നിർത്തുക;
    അവസ്ഥ OP_IM8:
        operands |= ENCODE_IMMEDIATE_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, ശൂന്യ));
    }

    തിരഞ്ഞെടുപ്പ് (ops[2].type) {
    അവസ്ഥ OP_REG32:
        എങ്കിൽ ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_shift(&ops[2]);
        നിർത്തുക;
    അവസ്ഥ OP_IM8:
        എങ്കിൽ (ops[2].e.v)
            operands |= asm_encode_shift(&ops[2]);
        അല്ലെങ്കിൽ
            definitely_neutral = 1;
        നിർത്തുക;
    }

    എങ്കിൽ (!definitely_neutral) തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_lslseq:
    അവസ്ഥ TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSL;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_lsrseq:
    അവസ്ഥ TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSR;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_asrseq:
    അവസ്ഥ TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ASR;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_rorseq:
    അവസ്ഥ TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

സ്ഥിതം ശൂന്യം asm_multiplication_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand ops[4];
    പൂർണ്ണസംഖ്യ nb_ops = 0;
    uint32_t opcode = 0x90;

    വേണ്ടി (nb_ops = 0; nb_ops < വലുപ്പം(ops)/വലുപ്പം(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        എങ്കിൽ (tok != ',') {
            ++nb_ops;
            നിർത്തുക;
        }
        next(); // skip ','
    }
    എങ്കിൽ (nb_ops < 2)
        expect("at least two operands");
    അല്ലെങ്കിൽ എങ്കിൽ (nb_ops == 2) {
        തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
        അവസ്ഥ TOK_ASM_mulseq:
        അവസ്ഥ TOK_ASM_muleq:
            memcpy(&ops[2], &ops[0], വലുപ്പം(ops[1])); // ARM is actually like this!
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
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

    എങ്കിൽ (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    അല്ലെങ്കിൽ
        expect("(destination operand) register");
    എങ്കിൽ (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    അല്ലെങ്കിൽ
        expect("(first source operand) register");
    എങ്കിൽ (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    അല്ലെങ്കിൽ
        expect("(second source operand) register");
    എങ്കിൽ (nb_ops > 3) {
        എങ്കിൽ (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        അല്ലെങ്കിൽ
            expect("(third source operand) register");
    }

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_mulseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    അവസ്ഥ TOK_ASM_muleq:
        എങ്കിൽ (nb_ops != 3)
            expect("three operands");
        അല്ലെങ്കിൽ {
            asm_emit_opcode(token, opcode);
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_mlaseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    അവസ്ഥ TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        എങ്കിൽ (nb_ops != 4)
            expect("four operands");
        അല്ലെങ്കിൽ {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_mlseq:
        opcode |= 0x00400000;
        പോകുക case_TOK_ASM_mlaeq;
    അവസ്ഥ TOK_ASM_udiveq:
        opcode |= 0x00200000;
    അവസ്ഥ TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("known multiplication instruction");
    }
}

സ്ഥിതം ശൂന്യം asm_long_multiplication_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand ops[4];
    പൂർണ്ണസംഖ്യ nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    വേണ്ടി (nb_ops = 0; nb_ops < വലുപ്പം(ops)/വലുപ്പം(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        എങ്കിൽ (tok != ',') {
            ++nb_ops;
            നിർത്തുക;
        }
        next(); // skip ','
    }
    എങ്കിൽ (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    എങ്കിൽ (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    അല്ലെങ്കിൽ
        expect("(destination lo accumulator) register");
    എങ്കിൽ (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    അല്ലെങ്കിൽ
        expect("(destination hi accumulator) register");
    എങ്കിൽ (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    അല്ലെങ്കിൽ
        expect("(first source operand) register");
    എങ്കിൽ (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    അല്ലെങ്കിൽ
        expect("(second source operand) register");

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_smullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    അവസ്ഥ TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_umullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    അവസ്ഥ TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_smlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    അവസ്ഥ TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_umlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    അവസ്ഥ TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("known long multiplication instruction");
    }
}

സ്ഥിതം ശൂന്യം asm_single_data_transfer_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand ops[3];
    Operand strex_operand;
    Operand shift;
    പൂർണ്ണസംഖ്യ nb_shift = 0;
    പൂർണ്ണസംഖ്യ exclam = 0;
    പൂർണ്ണസംഖ്യ closed_bracket = 0;
    പൂർണ്ണസംഖ്യ op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    എങ്കിൽ (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    അല്ലെങ്കിൽ {
        expect("(destination operand) register");
    }
    എങ്കിൽ (tok != ',')
        expect("at least two arguments");
    next(); // skip ','

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_strexheq:
    അവസ്ഥ TOK_ASM_strexbeq:
    അവസ്ഥ TOK_ASM_strexeq:
        parse_operand(s1, &strex_operand);
        എങ്കിൽ (strex_operand.type != OP_REG32) {
            expect("register");
        }
        എങ്കിൽ (tok != ',')
            expect("at least three arguments");
        അല്ലെങ്കിൽ
            next(); // skip ','
        നിർത്തുക;
    }

    skip('[');
    parse_operand(s1, &ops[1]);
    എങ്കിൽ (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    അല്ലെങ്കിൽ {
        expect("(first source operand) register");
    }
    എങ്കിൽ (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    എങ്കിൽ (tok == ',') {
        next(); // skip ','
        എങ്കിൽ (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        എങ്കിൽ (ops[2].type == OP_REG32) {
            എങ്കിൽ (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ശൂന്യ));
            }
            എങ്കിൽ (tok == ',') {
                next();
                opcode |= asm_parse_optional_shift(s1, &nb_shift, &shift);
                എങ്കിൽ (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } അല്ലെങ്കിൽ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    എങ്കിൽ (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        എങ്കിൽ (tok == '!') {
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
    എങ്കിൽ (exclam)
        opcode |= 1 << 21; // write offset back into register

    എങ്കിൽ (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        പൂർണ്ണസംഖ്യ v = ops[2].e.v;
        എങ്കിൽ (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        എങ്കിൽ (v >= 0) {
            opcode |= 1 << 23; // up
            എങ്കിൽ (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ശൂന്യ));
            അല്ലെങ്കിൽ
                opcode |= v;
        } അല്ലെങ്കിൽ { // down
            എങ്കിൽ (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ശൂന്യ));
            അല്ലെങ്കിൽ
                opcode |= -v;
        }
    } അല്ലെങ്കിൽ എങ്കിൽ (ops[2].type == OP_REG32) {
        എങ്കിൽ (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } അല്ലെങ്കിൽ
        expect("register");

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    അവസ്ഥ TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        എങ്കിൽ (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    അവസ്ഥ TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        എങ്കിൽ (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_strexheq:
        opcode |= 1 << 21;
    അവസ്ഥ TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    അവസ്ഥ TOK_ASM_strexeq:
        എങ്കിൽ ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } അല്ലെങ്കിൽ എങ്കിൽ (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        എങ്കിൽ ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_operand.reg;
        asm_emit_opcode(token, opcode);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    അവസ്ഥ TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    അവസ്ഥ TOK_ASM_ldrexeq:
        എങ്കിൽ ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } അല്ലെങ്കിൽ എങ്കിൽ (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        എങ്കിൽ ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
സ്ഥിതം ശൂന്യം asm_emit_coprocessor_data_transfer(uint32_t മുകളിലെ_nibble, uint8_t cp_സംഖ്യ, uint8_t CRd, സ്ഥിരം Operand* Rn, സ്ഥിരം Operand* offset, പൂർണ്ണസംഖ്യ offset_minus, പൂർണ്ണസംഖ്യ preincrement, പൂർണ്ണസംഖ്യ writeback, പൂർണ്ണസംഖ്യ long_transfer, പൂർണ്ണസംഖ്യ load) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    എങ്കിൽ (long_transfer)
        opcode |= 1 << 22; // long transfer

    എങ്കിൽ (load)
        opcode |= 1 << 20; // L

    opcode |= cp_സംഖ്യ << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    എങ്കിൽ (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    എങ്കിൽ (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    എങ്കിൽ (writeback)
        opcode |= 1 << 21; // write offset back into register

    എങ്കിൽ (offset->type == OP_IM8 || offset->type == OP_IM8N || offset->type == OP_IM32) {
        പൂർണ്ണസംഖ്യ v = offset->e.v;
        എങ്കിൽ (offset_minus)
            tcc_error("minus before '#' not supported for immediate values");
        എങ്കിൽ (offset->type == OP_IM8N || v < 0)
            v = -v;
        അല്ലെങ്കിൽ
            opcode |= 1 << 23; // up
        എങ്കിൽ (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        എങ്കിൽ (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } അല്ലെങ്കിൽ എങ്കിൽ (offset->type == OP_REG32) {
        എങ്കിൽ (!offset_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= offset->reg;
        tcc_error("Using register offset to register address is not possible here");
    } അല്ലെങ്കിൽ എങ്കിൽ (offset->type == OP_VREG64) {
        opcode |= 16;
        opcode |= offset->reg;
    } അല്ലെങ്കിൽ
        expect("immediate or register");

    asm_emit_unconditional_opcode((മുകളിലെ_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
സ്ഥിതം ശൂന്യം asm_coprocessor_data_transfer_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_register;
    പൂർണ്ണസംഖ്യ preincrement = 0;
    പൂർണ്ണസംഖ്യ exclam = 0;
    പൂർണ്ണസംഖ്യ closed_bracket = 0;
    പൂർണ്ണസംഖ്യ op2_minus = 0;
    പൂർണ്ണസംഖ്യ long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    എങ്കിൽ (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } അല്ലെങ്കിൽ {
        expect("'c<number>'");
    }

    skip(',');

    എങ്കിൽ (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_register = tok - TOK_ASM_c0;
        next();
    } അല്ലെങ്കിൽ {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    എങ്കിൽ (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    എങ്കിൽ (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    എങ്കിൽ (tok == ',') {
        next(); // skip ','
        എങ്കിൽ (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        എങ്കിൽ (ops[2].type == OP_REG32) {
            എങ്കിൽ (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ശൂന്യ));
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, ശൂന്യ));
        }
    } അല്ലെങ്കിൽ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    എങ്കിൽ (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        എങ്കിൽ (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    // TODO: Support options.

    എങ്കിൽ (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        തിരഞ്ഞെടുപ്പ് (token) {
        അവസ്ഥ TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        അവസ്ഥ TOK_ASM_ldc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        അവസ്ഥ TOK_ASM_stc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            നിർത്തുക;
        }
    } അല്ലെങ്കിൽ തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    അവസ്ഥ TOK_ASM_stceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    അവസ്ഥ TOK_ASM_ldceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("coprocessor data transfer instruction");
    }
}

#എങ്കിൽ defined(TCC_ARM_VFP)
#define CP_SINGLE_PRECISION_FLOAT 10
#define CP_DOUBLE_PRECISION_FLOAT 11

സ്ഥിതം ശൂന്യം asm_floating_point_single_data_transfer_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_register = 0;
    പൂർണ്ണസംഖ്യ long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    എങ്കിൽ (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        long_transfer = coprocessor_destination_register & 1;
        coprocessor_destination_register >>= 1;
    } അല്ലെങ്കിൽ എങ്കിൽ (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        next();
    } അല്ലെങ്കിൽ {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    എങ്കിൽ (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    എങ്കിൽ (tok == ',') {
        next(); // skip ','
        parse_operand(s1, &ops[2]);
        എങ്കിൽ (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } അല്ലെങ്കിൽ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_vldreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vstreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("floating point data transfer instruction");
    }
}

സ്ഥിതം ശൂന്യം asm_floating_point_block_data_transfer_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    uint8_t coprocessor = 0;
    പൂർണ്ണസംഖ്യ first_regset_register;
    പൂർണ്ണസംഖ്യ last_regset_register;
    uint8_t regset_item_എണ്ണം;
    uint8_t extra_register_bit = 0;
    പൂർണ്ണസംഖ്യ op0_exclam = 0;
    പൂർണ്ണസംഖ്യ load = 0;
    പൂർണ്ണസംഖ്യ preincrement = 0;
    Operand ops[1];
    Operand offset;
    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_vpusheq:
    അവസ്ഥ TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        parse_operand(s1, &ops[0]);
        എങ്കിൽ (tok == '!') {
            op0_exclam = 1;
            next(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    first_regset_register = asm_parse_vfp_regvar(tok, 1);
    എങ്കിൽ ((first_regset_register = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        next();
    } അല്ലെങ്കിൽ എങ്കിൽ ((first_regset_register = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        next();
    } അല്ലെങ്കിൽ {
        expect("floating-point register");
    }

    എങ്കിൽ (tok == '-') {
        next();
        എങ്കിൽ ((last_regset_register = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            next();
        അല്ലെങ്കിൽ {
            expect("floating-point register");
        }
    } അല്ലെങ്കിൽ
        last_regset_register = first_regset_register;

    എങ്കിൽ (last_regset_register < first_regset_register) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_item_എണ്ണം = last_regset_register - first_regset_register + 1;
    എങ്കിൽ (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_item_എണ്ണം <<= 1;
    അല്ലെങ്കിൽ {
        extra_register_bit = first_regset_register & 1;
        first_regset_register >>= 1;
    }
    offset.type = OP_IM8;
    offset.e.v = regset_item_എണ്ണം << 2;
    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_vstmeq: // post-increment store
    അവസ്ഥ TOK_ASM_vstmiaeq: // post-increment store
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vpopeq:
    അവസ്ഥ TOK_ASM_vldmeq: // post-increment load
    അവസ്ഥ TOK_ASM_vldmiaeq: // post-increment load
        load = 1;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vldmdbeq: // pre-decrement load
        load = 1;
        /* fallthrough */
    അവസ്ഥ TOK_ASM_vpusheq:
    അവസ്ഥ TOK_ASM_vstmdbeq: // pre-decrement store
        offset.type = OP_IM8N;
        offset.e.v = -offset.e.v;
        preincrement = 1;
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("floating point block data transfer instruction");
    }
    എങ്കിൽ (ops[0].type != OP_REG32)
        expect("(first operand) register");
    അല്ലെങ്കിൽ എങ്കിൽ (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ശൂന്യ));
    അല്ലെങ്കിൽ എങ്കിൽ (!op0_exclam && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, ശൂന്യ));
    അല്ലെങ്കിൽ
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, first_regset_register, &ops[0], &offset, 0, preincrement, op0_exclam, extra_register_bit, load);
}

#define VMOV_FRACTIONAL_DIGITS 7
#define VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

സ്ഥിതം uint32_t vmov_parse_fractional_part(സ്ഥിരം അക്ഷരം* s)
{
    uint32_t result = 0;
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        അക്ഷരം c = *s;
        result *= 10;
        എങ്കിൽ (c >= '0' && c <= '9') {
            result += (c - '0');
            ++s;
        }
    }
    എങ്കിൽ (*s)
        expect("decimal numeral");
    തിരികെ result;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ vmov_linear_approx_index(uint32_t beginning, uint32_t end, uint32_t മൂല്യം)
{
    പൂർണ്ണസംഖ്യ i;
    uint32_t k;
    uint32_t xvalue;

    k = (end - beginning)/16;
    വേണ്ടി (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        എങ്കിൽ (മൂല്യം == xvalue)
            തിരികെ i;
    }
    //assert(0);
    തിരികെ -1;
}

സ്ഥിതം uint32_t vmov_parse_immediate_മൂല്യം() {
    uint32_t മൂല്യം;
    unsigned long integral_മൂല്യം;
    സ്ഥിരം അക്ഷരം *p;

    എങ്കിൽ (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.data;
    errno = 0;
    integral_മൂല്യം = strtoul(p, (അക്ഷരം **)&p, 0);

    എങ്കിൽ (errno || integral_മൂല്യം >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    മൂല്യം = (uint32_t) integral_മൂല്യം * VMOV_ONE;
    എങ്കിൽ (*p == '.') {
        ++p;
        മൂല്യം += vmov_parse_fractional_part(p);
    }
    next();
    തിരികെ മൂല്യം;
}

സ്ഥിതം uint8_t vmov_encode_immediate_മൂല്യം(uint32_t മൂല്യം)
{
    uint32_t limit;
    uint32_t end = 0;
    uint32_t beginning = 0;
    പൂർണ്ണസംഖ്യ r = -1;
    പൂർണ്ണസംഖ്യ n;
    പൂർണ്ണസംഖ്യ i;

    limit = 32 * VMOV_ONE;
    വേണ്ടി (i = 0; i < 8; ++i) {
        എങ്കിൽ (മൂല്യം < limit) {
            end = limit;
            limit >>= 1;
            beginning = limit;
            r = i;
        } അല്ലെങ്കിൽ
            limit >>= 1;
    }
    എങ്കിൽ (r == -1 || മൂല്യം < beginning || മൂല്യം > end) {
        tcc_error("invalid decimal number for vmov: %d", മൂല്യം);
    }
    n = vmov_linear_approx_index(beginning, end, മൂല്യം);
    തിരികെ n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
സ്ഥിതം ശൂന്യം asm_floating_point_immediate_data_processing_opcode_tail(TCCState *s1, പൂർണ്ണസംഖ്യ token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t immediate_മൂല്യം = 0;
    പൂർണ്ണസംഖ്യ op_minus = 0;
    uint8_t code;

    operands[0] = CRd;

    എങ്കിൽ (tok == '#' || tok == '$') {
        next();
    }
    എങ്കിൽ (tok == '-') {
        op_minus = 1;
        next();
    }
    immediate_മൂല്യം = vmov_parse_immediate_മൂല്യം();

    opcode1 = 11; // "Other" instruction
    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_vcmpeq_f32:
    അവസ്ഥ TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        എങ്കിൽ (immediate_മൂല്യം) {
            expect("Immediate value 0");
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vcmpeeq_f32:
    അവസ്ഥ TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        എങ്കിൽ (immediate_മൂല്യം) {
            expect("Immediate value 0");
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vmoveq_f32:
    അവസ്ഥ TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        എങ്കിൽ (op_minus)
            operands[1] = 0x8;
        അല്ലെങ്കിൽ
            operands[1] = 0x0;
        code = vmov_encode_immediate_മൂല്യം(immediate_മൂല്യം);
        operands[1] |= code >> 4;
        operands[2] = code & 0xF;
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("known floating point with immediate instruction");
    }

    എങ്കിൽ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        എങ്കിൽ (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

സ്ഥിതം ശൂന്യം asm_floating_point_reg_arm_reg_transfer_opcode_tail(TCCState *s1, പൂർണ്ണസംഖ്യ token, പൂർണ്ണസംഖ്യ coprocessor, പൂർണ്ണസംഖ്യ nb_arm_regs, പൂർണ്ണസംഖ്യ nb_ops, Operand ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    തിരഞ്ഞെടുപ്പ് (coprocessor) {
    അവസ്ഥ CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        എങ്കിൽ (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        എങ്കിൽ (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            memcpy(&ops[2], &ops[1], വലുപ്പം(ops[2]));
            memcpy(&ops[1], &ops[0], വലുപ്പം(ops[1]));
            memcpy(&ops[0], &ops[2], വലുപ്പം(ops[0]));
        } അല്ലെങ്കിൽ
            opcode1 |= 1;

        എങ്കിൽ (ops[1].type == OP_VREG32) {
            എങ്കിൽ (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        എങ്കിൽ (ops[0].type == OP_VREG32) {
            എങ്കിൽ (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        നിർത്തുക;
    അവസ്ഥ CP_DOUBLE_PRECISION_FLOAT:
        എങ്കിൽ (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        എങ്കിൽ (ops[0].type == OP_VREG64) {
            എങ്കിൽ (ops[2].type == OP_REG32) {
                Operand temp;
                // need to rotate operand list to the left
                memcpy(&temp, &ops[0], വലുപ്പം(temp));
                memcpy(&ops[0], &ops[1], വലുപ്പം(ops[0]));
                memcpy(&ops[1], &ops[2], വലുപ്പം(ops[1]));
                memcpy(&ops[2], &temp, വലുപ്പം(ops[2]));
            } അല്ലെങ്കിൽ {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } അല്ലെങ്കിൽ {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        tcc_internal_error("unknown coprocessor");
    }
}

സ്ഥിതം ശൂന്യം asm_floating_point_vcvt_data_processing_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token) {
    uint8_t coprocessor = 0;
    Operand ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_vcvtreq_s32_f64:
    അവസ്ഥ TOK_ASM_vcvtreq_u32_f64:
    അവസ്ഥ TOK_ASM_vcvteq_s32_f64:
    അവസ്ഥ TOK_ASM_vcvteq_u32_f64:
    അവസ്ഥ TOK_ASM_vcvteq_f64_s32:
    അവസ്ഥ TOK_ASM_vcvteq_f64_u32:
    അവസ്ഥ TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       നിർത്തുക;
    അവസ്ഥ TOK_ASM_vcvtreq_s32_f32:
    അവസ്ഥ TOK_ASM_vcvtreq_u32_f32:
    അവസ്ഥ TOK_ASM_vcvteq_s32_f32:
    അവസ്ഥ TOK_ASM_vcvteq_u32_f32:
    അവസ്ഥ TOK_ASM_vcvteq_f32_s32:
    അവസ്ഥ TOK_ASM_vcvteq_f32_u32:
    അവസ്ഥ TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, ശൂന്യ));
    }

    parse_operand(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_vcvtreq_s32_f32:
    അവസ്ഥ TOK_ASM_vcvtreq_s32_f64:
    അവസ്ഥ TOK_ASM_vcvteq_s32_f32:
    അവസ്ഥ TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    അവസ്ഥ TOK_ASM_vcvteq_u32_f32:
    അവസ്ഥ TOK_ASM_vcvteq_u32_f64:
    അവസ്ഥ TOK_ASM_vcvtreq_u32_f32:
    അവസ്ഥ TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        നിർത്തുക;
    /* floating-point size conversion */
    അവസ്ഥ TOK_ASM_vcvteq_f64_f32:
    അവസ്ഥ TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        നിർത്തുക;
    }

    skip(',');
    parse_operand(s1, &ops[2]);

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    /* floating-point -> integer */
    അവസ്ഥ TOK_ASM_vcvteq_s32_f32:
    അവസ്ഥ TOK_ASM_vcvteq_s32_f64:
    അവസ്ഥ TOK_ASM_vcvteq_u32_f32:
    അവസ്ഥ TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        നിർത്തുക;

    /* integer -> floating-point */
    അവസ്ഥ TOK_ASM_vcvteq_f64_s32:
    അവസ്ഥ TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        നിർത്തുക;

    /* floating-point size conversion */
    അവസ്ഥ TOK_ASM_vcvteq_f64_f32:
    അവസ്ഥ TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        നിർത്തുക;
    }

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_vcvteq_f64_u32:
    അവസ്ഥ TOK_ASM_vcvteq_f64_s32:
    അവസ്ഥ TOK_ASM_vcvteq_f64_f32:
        എങ്കിൽ (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } അല്ലെങ്കിൽ {
            expect("d<number>, s<number>");
        }
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        എങ്കിൽ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            എങ്കിൽ (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } അല്ലെങ്കിൽ {
                expect("s<number>, s<number>");
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            എങ്കിൽ (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } അല്ലെങ്കിൽ {
                expect("s<number>, d<number>");
            }
        }
    }

    എങ്കിൽ (ops[2].type == OP_VREG32) {
        എങ്കിൽ (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    എങ്കിൽ (ops[0].type == OP_VREG32) {
        എങ്കിൽ (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

സ്ഥിതം ശൂന്യം asm_floating_point_data_processing_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    Operand ops[3];
    uint8_t nb_ops = 0;
    പൂർണ്ണസംഖ്യ vmov = 0;
    പൂർണ്ണസംഖ്യ nb_arm_regs = 0;

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

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_vmlaeq_f64:
    അവസ്ഥ TOK_ASM_vmlseq_f64:
    അവസ്ഥ TOK_ASM_vnmlseq_f64:
    അവസ്ഥ TOK_ASM_vnmlaeq_f64:
    അവസ്ഥ TOK_ASM_vmuleq_f64:
    അവസ്ഥ TOK_ASM_vnmuleq_f64:
    അവസ്ഥ TOK_ASM_vaddeq_f64:
    അവസ്ഥ TOK_ASM_vsubeq_f64:
    അവസ്ഥ TOK_ASM_vdiveq_f64:
    അവസ്ഥ TOK_ASM_vnegeq_f64:
    അവസ്ഥ TOK_ASM_vabseq_f64:
    അവസ്ഥ TOK_ASM_vsqrteq_f64:
    അവസ്ഥ TOK_ASM_vcmpeq_f64:
    അവസ്ഥ TOK_ASM_vcmpeeq_f64:
    അവസ്ഥ TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_vmoveq_f32:
    അവസ്ഥ TOK_ASM_vmoveq_f64:
        vmov = 1;
        നിർത്തുക;
    }

    വേണ്ടി (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        എങ്കിൽ (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_point_immediate_data_processing_opcode_tail(s1, token, coprocessor, ops[0].reg);
            തിരികെ;
        }
        parse_operand(s1, &ops[nb_ops]);
        എങ്കിൽ (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } അല്ലെങ്കിൽ എങ്കിൽ (ops[nb_ops].type == OP_VREG32) {
            എങ്കിൽ (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (ops[nb_ops].type == OP_VREG64) {
            എങ്കിൽ (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } അല്ലെങ്കിൽ {
            expect("floating point register");
        }
        ++nb_ops;
        എങ്കിൽ (tok == ',')
            next();
        അല്ലെങ്കിൽ
            നിർത്തുക;
    }

    എങ്കിൽ (nb_arm_regs == 0) {
        എങ്കിൽ (nb_ops == 2) { // implicit
            memcpy(&ops[2], &ops[1], വലുപ്പം(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], വലുപ്പം(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        എങ്കിൽ (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, ശൂന്യ), nb_ops);
        }
    }

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_vmlaeq_f32:
    അവസ്ഥ TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vmlseq_f32:
    അവസ്ഥ TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vnmlseq_f32:
    അവസ്ഥ TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vnmlaeq_f32:
    അവസ്ഥ TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vmuleq_f32:
    അവസ്ഥ TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vnmuleq_f32:
    അവസ്ഥ TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vaddeq_f32:
    അവസ്ഥ TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vsubeq_f32:
    അവസ്ഥ TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vdiveq_f32:
    അവസ്ഥ TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vnegeq_f32:
    അവസ്ഥ TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vabseq_f32:
    അവസ്ഥ TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vsqrteq_f32:
    അവസ്ഥ TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vcmpeq_f32:
    അവസ്ഥ TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vcmpeeq_f32:
    അവസ്ഥ TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vmoveq_f32:
    അവസ്ഥ TOK_ASM_vmoveq_f64:
        എങ്കിൽ (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_point_reg_arm_reg_transfer_opcode_tail(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            തിരികെ;
        } അല്ലെങ്കിൽ {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("known floating point instruction");
    }

    എങ്കിൽ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        എങ്കിൽ (ops[2].type == OP_VREG32) {
            എങ്കിൽ (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        എങ്കിൽ (ops[1].type == OP_VREG32) {
            എങ്കിൽ (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        എങ്കിൽ (ops[0].type == OP_VREG32) {
            എങ്കിൽ (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

സ്ഥിതം പൂർണ്ണസംഖ്യ asm_parse_vfp_status_regvar(പൂർണ്ണസംഖ്യ t)
{
    തിരഞ്ഞെടുപ്പ് (t) {
    അവസ്ഥ TOK_ASM_fpsid:
        തിരികെ 0;
    അവസ്ഥ TOK_ASM_fpscr:
        തിരികെ 1;
    അവസ്ഥ TOK_ASM_fpexc:
        തിരികെ 8;
    സ്ഥിരസ്ഥിതി:
        തിരികെ -1;
    }
}

സ്ഥിതം ശൂന്യം asm_floating_point_status_register_opcode(TCCState* s1, പൂർണ്ണസംഖ്യ token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    പൂർണ്ണസംഖ്യ vfp_sys_reg = -1;
    Operand arm_operand;
    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_vmrseq:
        opcode = 0xf;
        എങ്കിൽ (tok == TOK_ASM_apsr_nzcv) {
            arm_operand.type = OP_REG32;
            arm_operand.reg = 15; // not PC
            next(); // skip apsr_nzcv
        } അല്ലെങ്കിൽ {
            parse_operand(s1, &arm_operand);
            എങ്കിൽ (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ശൂന്യ));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        എങ്കിൽ (arm_operand.type == OP_REG32 && arm_operand.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, ശൂന്യ));
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        skip(',');
        parse_operand(s1, &arm_operand);
        എങ്കിൽ (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ശൂന്യ));
        }
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("floating point status register instruction");
    }
    എങ്കിൽ (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    എങ്കിൽ (arm_operand.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode, arm_operand.reg, vfp_sys_reg, 0x10, 0, 0);
}

#endif

സ്ഥിതം ശൂന്യം asm_misc_single_data_transfer_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand ops[3];
    പൂർണ്ണസംഖ്യ exclam = 0;
    പൂർണ്ണസംഖ്യ closed_bracket = 0;
    പൂർണ്ണസംഖ്യ op2_minus = 0;
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
    എങ്കിൽ (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    അല്ലെങ്കിൽ {
        expect("(destination operand) register");
    }
    എങ്കിൽ (tok != ',')
        expect("at least two arguments");
    അല്ലെങ്കിൽ
        next(); // skip ','
    skip('[');
    parse_operand(s1, &ops[1]);
    എങ്കിൽ (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    അല്ലെങ്കിൽ {
        expect("(first source operand) register");
    }
    എങ്കിൽ (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    എങ്കിൽ (tok == ',') {
        next(); // skip ','
        എങ്കിൽ (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
    } അല്ലെങ്കിൽ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    എങ്കിൽ (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        എങ്കിൽ (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    എങ്കിൽ (exclam) {
        എങ്കിൽ ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, ശൂന്യ));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    എങ്കിൽ (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        പൂർണ്ണസംഖ്യ v = ops[2].e.v;
        എങ്കിൽ (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        എങ്കിൽ (v >= 0) {
            opcode |= 1 << 23; // up
            എങ്കിൽ (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ശൂന്യ));
            അല്ലെങ്കിൽ {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } അല്ലെങ്കിൽ { // down
            എങ്കിൽ (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ശൂന്യ));
            അല്ലെങ്കിൽ {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } അല്ലെങ്കിൽ എങ്കിൽ (ops[2].type == OP_REG32) {
        എങ്കിൽ (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ops[2].reg;
    } അല്ലെങ്കിൽ
        expect("register");

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    അവസ്ഥ TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        നിർത്തുക;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
സ്ഥിതം uint32_t encbranchoffset(പൂർണ്ണസംഖ്യ pos, പൂർണ്ണസംഖ്യ addr, പൂർണ്ണസംഖ്യ fail)
{
  addr-=pos+8;
  addr/=4;
  എങ്കിൽ(addr>=0x7fffff || addr<-0x800000) {
    എങ്കിൽ(fail)
      tcc_error("branch offset is too far");
    തിരികെ 0;
  }
  തിരികെ /*not 0x0A000000|*/(addr&0xffffff);
}

സ്ഥിതം ശൂന്യം asm_branch_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    പൂർണ്ണസംഖ്യ jmp_disp = 0;
    Operand op;
    വ്യഞ്ജകം_മൂല്യം e;
    ElfSym *esym;

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_beq:
    അവസ്ഥ TOK_ASM_bleq:
        asm_വ്യഞ്ജകം(s1, &e);
        എങ്കിൽ (e.sym) {
            esym = elfsym(e.sym);
            എങ്കിൽ (esym && esym->st_shndx == cur_text_section->sh_അക്കം) {
                jmp_disp = esym->st_മൂല്യം;
            } അല്ലെങ്കിൽ {
                greloca(cur_text_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        parse_operand(s1, &op);
        നിർത്തുക;
    }
    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_bxeq:
        എങ്കിൽ (op.type != OP_REG32)
            expect("register");
        അല്ലെങ്കിൽ
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_blxeq:
        എങ്കിൽ (op.type != OP_REG32)
            expect("register");
        അല്ലെങ്കിൽ
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("branch instruction");
    }
}

ST_FUNC ശൂന്യം asm_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    ആകുമ്പോൾ (token == TOK_LINEFEED) {
        next();
        token = tok;
    }
    എങ്കിൽ (token == TOK_EOF)
        തിരികെ;
    എങ്കിൽ (token < TOK_ASM_nopeq) { // no condition code
        തിരഞ്ഞെടുപ്പ് (token) {
        അവസ്ഥ TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            തിരികെ;
        അവസ്ഥ TOK_ASM_ldc2:
        അവസ്ഥ TOK_ASM_ldc2l:
        അവസ്ഥ TOK_ASM_stc2:
        അവസ്ഥ TOK_ASM_stc2l:
            asm_coprocessor_data_transfer_opcode(s1, token);
            തിരികെ;
        സ്ഥിരസ്ഥിതി:
            expect("instruction");
        }
    }

    തിരഞ്ഞെടുപ്പ് (ARM_INSTRUCTION_GROUP(token)) {
    അവസ്ഥ TOK_ASM_pusheq:
    അവസ്ഥ TOK_ASM_popeq:
    അവസ്ഥ TOK_ASM_stmdaeq:
    അവസ്ഥ TOK_ASM_ldmdaeq:
    അവസ്ഥ TOK_ASM_stmeq:
    അവസ്ഥ TOK_ASM_ldmeq:
    അവസ്ഥ TOK_ASM_stmiaeq:
    അവസ്ഥ TOK_ASM_ldmiaeq:
    അവസ്ഥ TOK_ASM_stmdbeq:
    അവസ്ഥ TOK_ASM_ldmdbeq:
    അവസ്ഥ TOK_ASM_stmibeq:
    അവസ്ഥ TOK_ASM_ldmibeq:
        asm_block_data_transfer_opcode(s1, token);
        തിരികെ;
    അവസ്ഥ TOK_ASM_nopeq:
    അവസ്ഥ TOK_ASM_wfeeq:
    അവസ്ഥ TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        തിരികെ;
    അവസ്ഥ TOK_ASM_swieq:
    അവസ്ഥ TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        തിരികെ;
    അവസ്ഥ TOK_ASM_beq:
    അവസ്ഥ TOK_ASM_bleq:
    അവസ്ഥ TOK_ASM_bxeq:
    അവസ്ഥ TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        തിരികെ;
    അവസ്ഥ TOK_ASM_clzeq:
    അവസ്ഥ TOK_ASM_sxtbeq:
    അവസ്ഥ TOK_ASM_sxtheq:
    അവസ്ഥ TOK_ASM_uxtbeq:
    അവസ്ഥ TOK_ASM_uxtheq:
    അവസ്ഥ TOK_ASM_movteq:
    അവസ്ഥ TOK_ASM_movweq:
        asm_ദ്വിമാന_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_ldreq:
    അവസ്ഥ TOK_ASM_ldrbeq:
    അവസ്ഥ TOK_ASM_streq:
    അവസ്ഥ TOK_ASM_strbeq:
    അവസ്ഥ TOK_ASM_ldrexeq:
    അവസ്ഥ TOK_ASM_ldrexbeq:
    അവസ്ഥ TOK_ASM_ldrexheq:
    അവസ്ഥ TOK_ASM_strexeq:
    അവസ്ഥ TOK_ASM_strexbeq:
    അവസ്ഥ TOK_ASM_strexheq:
        asm_single_data_transfer_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_ldrheq:
    അവസ്ഥ TOK_ASM_ldrsheq:
    അവസ്ഥ TOK_ASM_ldrsbeq:
    അവസ്ഥ TOK_ASM_strheq:
       asm_misc_single_data_transfer_opcode(s1, token);
       തിരികെ;

    അവസ്ഥ TOK_ASM_andeq:
    അവസ്ഥ TOK_ASM_eoreq:
    അവസ്ഥ TOK_ASM_subeq:
    അവസ്ഥ TOK_ASM_rsbeq:
    അവസ്ഥ TOK_ASM_addeq:
    അവസ്ഥ TOK_ASM_adceq:
    അവസ്ഥ TOK_ASM_sbceq:
    അവസ്ഥ TOK_ASM_rsceq:
    അവസ്ഥ TOK_ASM_tsteq:
    അവസ്ഥ TOK_ASM_teqeq:
    അവസ്ഥ TOK_ASM_cmpeq:
    അവസ്ഥ TOK_ASM_cmneq:
    അവസ്ഥ TOK_ASM_orreq:
    അവസ്ഥ TOK_ASM_moveq:
    അവസ്ഥ TOK_ASM_biceq:
    അവസ്ഥ TOK_ASM_mvneq:
    അവസ്ഥ TOK_ASM_andseq:
    അവസ്ഥ TOK_ASM_eorseq:
    അവസ്ഥ TOK_ASM_subseq:
    അവസ്ഥ TOK_ASM_rsbseq:
    അവസ്ഥ TOK_ASM_addseq:
    അവസ്ഥ TOK_ASM_adcseq:
    അവസ്ഥ TOK_ASM_sbcseq:
    അവസ്ഥ TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    അവസ്ഥ TOK_ASM_orrseq:
    അവസ്ഥ TOK_ASM_movseq:
    അവസ്ഥ TOK_ASM_bicseq:
    അവസ്ഥ TOK_ASM_mvnseq:
        asm_data_processing_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_lsleq:
    അവസ്ഥ TOK_ASM_lslseq:
    അവസ്ഥ TOK_ASM_lsreq:
    അവസ്ഥ TOK_ASM_lsrseq:
    അവസ്ഥ TOK_ASM_asreq:
    അവസ്ഥ TOK_ASM_asrseq:
    അവസ്ഥ TOK_ASM_roreq:
    അവസ്ഥ TOK_ASM_rorseq:
    അവസ്ഥ TOK_ASM_rrxseq:
    അവസ്ഥ TOK_ASM_rrxeq:
        asm_shift_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_muleq:
    അവസ്ഥ TOK_ASM_mulseq:
    അവസ്ഥ TOK_ASM_mlaeq:
    അവസ്ഥ TOK_ASM_mlaseq:
    അവസ്ഥ TOK_ASM_mlseq:
    അവസ്ഥ TOK_ASM_udiveq:
    അവസ്ഥ TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_smulleq:
    അവസ്ഥ TOK_ASM_smullseq:
    അവസ്ഥ TOK_ASM_umulleq:
    അവസ്ഥ TOK_ASM_umullseq:
    അവസ്ഥ TOK_ASM_smlaleq:
    അവസ്ഥ TOK_ASM_smlalseq:
    അവസ്ഥ TOK_ASM_umlaleq:
    അവസ്ഥ TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_cdpeq:
    അവസ്ഥ TOK_ASM_mcreq:
    അവസ്ഥ TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_ldceq:
    അവസ്ഥ TOK_ASM_ldcleq:
    അവസ്ഥ TOK_ASM_stceq:
    അവസ്ഥ TOK_ASM_stcleq:
        asm_coprocessor_data_transfer_opcode(s1, token);
        തിരികെ;

#എങ്കിൽ defined(TCC_ARM_VFP)
    അവസ്ഥ TOK_ASM_vldreq:
    അവസ്ഥ TOK_ASM_vstreq:
        asm_floating_point_single_data_transfer_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_vmlaeq_f32:
    അവസ്ഥ TOK_ASM_vmlseq_f32:
    അവസ്ഥ TOK_ASM_vnmlseq_f32:
    അവസ്ഥ TOK_ASM_vnmlaeq_f32:
    അവസ്ഥ TOK_ASM_vmuleq_f32:
    അവസ്ഥ TOK_ASM_vnmuleq_f32:
    അവസ്ഥ TOK_ASM_vaddeq_f32:
    അവസ്ഥ TOK_ASM_vsubeq_f32:
    അവസ്ഥ TOK_ASM_vdiveq_f32:
    അവസ്ഥ TOK_ASM_vnegeq_f32:
    അവസ്ഥ TOK_ASM_vabseq_f32:
    അവസ്ഥ TOK_ASM_vsqrteq_f32:
    അവസ്ഥ TOK_ASM_vcmpeq_f32:
    അവസ്ഥ TOK_ASM_vcmpeeq_f32:
    അവസ്ഥ TOK_ASM_vmoveq_f32:
    അവസ്ഥ TOK_ASM_vmlaeq_f64:
    അവസ്ഥ TOK_ASM_vmlseq_f64:
    അവസ്ഥ TOK_ASM_vnmlseq_f64:
    അവസ്ഥ TOK_ASM_vnmlaeq_f64:
    അവസ്ഥ TOK_ASM_vmuleq_f64:
    അവസ്ഥ TOK_ASM_vnmuleq_f64:
    അവസ്ഥ TOK_ASM_vaddeq_f64:
    അവസ്ഥ TOK_ASM_vsubeq_f64:
    അവസ്ഥ TOK_ASM_vdiveq_f64:
    അവസ്ഥ TOK_ASM_vnegeq_f64:
    അവസ്ഥ TOK_ASM_vabseq_f64:
    അവസ്ഥ TOK_ASM_vsqrteq_f64:
    അവസ്ഥ TOK_ASM_vcmpeq_f64:
    അവസ്ഥ TOK_ASM_vcmpeeq_f64:
    അവസ്ഥ TOK_ASM_vmoveq_f64:
        asm_floating_point_data_processing_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_vcvtreq_s32_f32:
    അവസ്ഥ TOK_ASM_vcvtreq_s32_f64:
    അവസ്ഥ TOK_ASM_vcvteq_s32_f32:
    അവസ്ഥ TOK_ASM_vcvteq_s32_f64:
    അവസ്ഥ TOK_ASM_vcvtreq_u32_f32:
    അവസ്ഥ TOK_ASM_vcvtreq_u32_f64:
    അവസ്ഥ TOK_ASM_vcvteq_u32_f32:
    അവസ്ഥ TOK_ASM_vcvteq_u32_f64:
    അവസ്ഥ TOK_ASM_vcvteq_f64_s32:
    അവസ്ഥ TOK_ASM_vcvteq_f32_s32:
    അവസ്ഥ TOK_ASM_vcvteq_f64_u32:
    അവസ്ഥ TOK_ASM_vcvteq_f32_u32:
    അവസ്ഥ TOK_ASM_vcvteq_f64_f32:
    അവസ്ഥ TOK_ASM_vcvteq_f32_f64:
        asm_floating_point_vcvt_data_processing_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_vpusheq:
    അവസ്ഥ TOK_ASM_vpopeq:
    അവസ്ഥ TOK_ASM_vldmeq:
    അവസ്ഥ TOK_ASM_vldmiaeq:
    അവസ്ഥ TOK_ASM_vldmdbeq:
    അവസ്ഥ TOK_ASM_vstmeq:
    അവസ്ഥ TOK_ASM_vstmiaeq:
    അവസ്ഥ TOK_ASM_vstmdbeq:
        asm_floating_point_block_data_transfer_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_vmsreq:
    അവസ്ഥ TOK_ASM_vmrseq:
        asm_floating_point_status_register_opcode(s1, token);
        തിരികെ;
#endif

    സ്ഥിരസ്ഥിതി:
        expect("known instruction");
    }
}

ST_FUNC ശൂന്യം subst_asm_operand(CString *add_str, SValue *sv, പൂർണ്ണസംഖ്യ modifier)
{
    പൂർണ്ണസംഖ്യ r, reg, size, val;

    r = sv->r;
    എങ്കിൽ ((r & VT_VALMASK) == VT_CONST) {
        എങ്കിൽ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        എങ്കിൽ (r & VT_SYM) {
            സ്ഥിരം അക്ഷരം *name = get_tok_str(sv->sym->v, ശൂന്യ);
            എങ്കിൽ (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            എങ്കിൽ (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            എങ്കിൽ ((uint32_t) sv->c.i == 0)
                പോകുക no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        എങ്കിൽ (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
      no_offset:;
    } അല്ലെങ്കിൽ എങ്കിൽ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[fp,#%d]", (പൂർണ്ണസംഖ്യ) sv->c.i);
    } അല്ലെങ്കിൽ എങ്കിൽ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        എങ്കിൽ (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, ശൂന്യ));
    } അല്ലെങ്കിൽ {
        /* register case */
        reg = r & VT_VALMASK;
        എങ്കിൽ (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        എങ്കിൽ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        അല്ലെങ്കിൽ എങ്കിൽ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        അല്ലെങ്കിൽ
            size = 4;

        എങ്കിൽ (modifier == 'b') {
            size = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (modifier == 'w') {
            size = 2;
        } അല്ലെങ്കിൽ എങ്കിൽ (modifier == 'k') {
            size = 4;
        }

        തിരഞ്ഞെടുപ്പ് (size) {
        സ്ഥിരസ്ഥിതി:
            reg = TOK_ASM_r0 + reg;
            നിർത്തുക;
        }
        cstr_printf(add_str, "%s", get_tok_str(reg, ശൂന്യ));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC ശൂന്യം asm_gen_code(ASMOperand *operands, പൂർണ്ണസംഖ്യ nb_operands,
                          പൂർണ്ണസംഖ്യ nb_outputs, പൂർണ്ണസംഖ്യ is_output,
                          uint8_t *clobber_regs,
                          പൂർണ്ണസംഖ്യ out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    പൂർണ്ണസംഖ്യ i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    സ്ഥിതം സ്ഥിരം uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, വലുപ്പം(regs_allocated));
    വേണ്ടി(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        എങ്കിൽ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    വേണ്ടി(i = 0; i < വലുപ്പം(reg_saved)/വലുപ്പം(reg_saved[0]); i++) {
        reg = reg_saved[i];
        എങ്കിൽ (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    എങ്കിൽ (!is_output) { // prolog
        /* generate reg save code */
        എങ്കിൽ (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        വേണ്ടി(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            എങ്കിൽ (op->reg >= 0) {
                എങ്കിൽ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } അല്ലെങ്കിൽ എങ്കിൽ (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    load(op->reg, op->vt);
                    എങ്കിൽ (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } അല്ലെങ്കിൽ { // epilog
        /* generate save code */
        വേണ്ടി(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            എങ്കിൽ (op->reg >= 0) {
                എങ്കിൽ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    എങ്കിൽ (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } അല്ലെങ്കിൽ {
                    store(op->reg, op->vt);
                    എങ്കിൽ (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        എങ്കിൽ (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ constraint_priority(സ്ഥിരം അക്ഷരം *str)
{
    പൂർണ്ണസംഖ്യ priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    വേണ്ടി(;;) {
        c = *str;
        എങ്കിൽ (c == '\0')
            നിർത്തുക;
        str++;
        തിരഞ്ഞെടുപ്പ്(c) {
        അവസ്ഥ 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        അവസ്ഥ 'r': // register [general]
        അവസ്ഥ 'p': // valid memory address for load,store [general]
            pr = 3;
            നിർത്തുക;
        അവസ്ഥ 'M': // integer constant for shifts [ARM]
        അവസ്ഥ 'I': // integer valid for data processing instruction immediate
        അവസ്ഥ 'J': // integer in range -4095...4095

        അവസ്ഥ 'i': // immediate integer operand, including symbolic constants [general]
        അവസ്ഥ 'm': // memory operand [general]
        അവസ്ഥ 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("unknown constraint '%c'", c);
        }
        എങ്കിൽ (pr > priority)
            priority = pr;
    }
    തിരികെ priority;
}

സ്ഥിതം സ്ഥിരം അക്ഷരം *skip_constraint_modifiers(സ്ഥിരം അക്ഷരം *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    ആകുമ്പോൾ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    തിരികെ p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC ശൂന്യം asm_compute_constraints(ASMOperand *operands,
                                    പൂർണ്ണസംഖ്യ nb_operands, പൂർണ്ണസംഖ്യ nb_outputs,
                                    സ്ഥിരം uint8_t *clobber_regs,
                                    പൂർണ്ണസംഖ്യ *pout_reg)
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
    പൂർണ്ണസംഖ്യ sorted_op[MAX_ASM_OPERANDS];
    പൂർണ്ണസംഖ്യ i, j, k, p1, p2, tmp, reg, c, reg_mask;
    സ്ഥിരം അക്ഷരം *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    വേണ്ടി (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->നിവേശം_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    വേണ്ടി (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        എങ്കിൽ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, ശൂന്യ);
            എങ്കിൽ ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            എങ്കിൽ (operands[k].നിവേശം_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].നിവേശം_index = i;
            op->priority = 5;
        } അല്ലെങ്കിൽ എങ്കിൽ ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } അല്ലെങ്കിൽ {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    വേണ്ടി (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    വേണ്ടി (i = 0; i < nb_operands - 1; i++) {
        വേണ്ടി (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            എങ്കിൽ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    വേണ്ടി (i = 0; i < NB_ASM_REGS; i++) {
        എങ്കിൽ (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        അല്ലെങ്കിൽ
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_IN_MASK | REG_OUT_MASK;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    വേണ്ടി (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        എങ്കിൽ (op->ref_index >= 0)
            തുടരുക;
        /* select if register is used for output, input or both */
        എങ്കിൽ (op->നിവേശം_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } അല്ലെങ്കിൽ എങ്കിൽ (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } അല്ലെങ്കിൽ {
            reg_mask = REG_IN_MASK;
        }
        എങ്കിൽ (op->reg >= 0) {
            എങ്കിൽ (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        തിരഞ്ഞെടുപ്പ് (c) {
        അവസ്ഥ '=': // Operand is written-to
            പോകുക try_next;
        അവസ്ഥ '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        അവസ്ഥ '&': // Operand is clobbered before the instruction is done using the input operands
            എങ്കിൽ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            പോകുക try_next;
        അവസ്ഥ 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        അവസ്ഥ 'r': // general-purpose register
        അവസ്ഥ 'p': // loadable/storable address
            /* any general register */
            എങ്കിൽ ((reg = op->reg) >= 0)
                പോകുക reg_found;
            അല്ലെങ്കിൽ വേണ്ടി (reg = 0; reg <= 8; reg++) {
                എങ്കിൽ (!is_reg_allocated(reg))
                    പോകുക reg_found;
            }
            പോകുക try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            നിർത്തുക;
        അവസ്ഥ 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        അവസ്ഥ 'J': // integer in the range -4095 to 4095 [ARM]
        അവസ്ഥ 'K': // integer that satisfies constraint I when inverted (one's complement)
        അവസ്ഥ 'L': // integer that satisfies constraint I when inverted (two's complement)
        അവസ്ഥ 'i': // immediate integer operand, including symbolic constants
            എങ്കിൽ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'M': // integer in the range 0 to 32
            എങ്കിൽ (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'm': // memory operand
        അവസ്ഥ 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            എങ്കിൽ (j < nb_outputs || c == 'm') {
                എങ്കിൽ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    വേണ്ടി (reg = 0; reg <= 8; reg++) {
                        എങ്കിൽ (!(regs_allocated[reg] & REG_IN_MASK))
                            പോകുക reg_found1;
                    }
                    പോകുക try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            നിർത്തുക;
        }
        /* if a reference is present for that operand, we assign it too */
        എങ്കിൽ (op->നിവേശം_index >= 0) {
            operands[op->നിവേശം_index].reg = op->reg;
            operands[op->നിവേശം_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    വേണ്ടി (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        എങ്കിൽ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            വേണ്ടി (reg = 0; reg <= 8; reg++) {
                എങ്കിൽ (!(regs_allocated[reg] & REG_OUT_MASK))
                    പോകുക reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            നിർത്തുക;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    വേണ്ടി (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ശൂന്യ) : "",
               op->constraint, op->vt->r, op->reg);
    }
    എങ്കിൽ (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC ശൂന്യം asm_clobber(uint8_t *clobber_regs, സ്ഥിരം അക്ഷരം *str)
{
    പൂർണ്ണസംഖ്യ reg;
    TokenSym *ts;

    എങ്കിൽ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        തിരികെ;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    എങ്കിൽ (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC പൂർണ്ണസംഖ്യ asm_parse_regvar (പൂർണ്ണസംഖ്യ t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    എങ്കിൽ (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        തിരികെ -1;

    എങ്കിൽ (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        തിരികെ t - TOK_ASM_r0;

    എങ്കിൽ (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        തിരികെ t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    തിരികെ t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
