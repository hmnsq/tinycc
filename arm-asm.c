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

#నిర్వచితమైతే లక్ష్యం_DEFS_ONLY

#నిర్వచించు CONFIG_TCC_ASM
#నిర్వచించు NB_ASM_REGS 16

ST_FUNC శూన్య g(పూర్ణాంకం c);
ST_FUNC శూన్య gen_le16(పూర్ణాంకం c);
ST_FUNC శూన్య gen_le32(పూర్ణాంకం c);

/*************************************************************/
#లేకపోతే
/*************************************************************/

#నిర్వచించు USING_GLOBALS
#అన్తర్భావ "tcc.h"

గణన {
    OPT_REG32,
    OPT_REGSET32,
    OPT_IM8,
    OPT_IM8N,
    OPT_IM32,
    OPT_VREG32,
    OPT_VREG64,
};
#నిర్వచించు OP_REG32  (1 << OPT_REG32)
#నిర్వచించు OP_VREG32 (1 << OPT_VREG32)
#నిర్వచించు OP_VREG64 (1 << OPT_VREG64)
#నిర్వచించు OP_REG    (OP_REG32 | OP_VREG32 | OP_VREG64)
#నిర్వచించు OP_IM32   (1 << OPT_IM32)
#నిర్వచించు OP_IM8   (1 << OPT_IM8)
#నిర్వచించు OP_IM8N   (1 << OPT_IM8N)
#నిర్వచించు OP_REGSET32  (1 << OPT_REGSET32)

రకనిర్వచనం నిర్మాణం నిర్వాహ్యం {
    uint32_t type;
    సంఘం {
        uint8_t reg;
        uint16_t regset;
        సమాసం_విలువ e;
    };
} నిర్వాహ్యం;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
స్థిర పూర్ణాంకం asm_parse_vfp_regvar(పూర్ణాంకం t, పూర్ణాంకం double_precision)
{
    ఒకవేళ (double_precision) {
        ఒకవేళ (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            తిరిగి t - TOK_ASM_d0;
    } లేకపోతే {
        ఒకవేళ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            తిరిగి t - TOK_ASM_s0;
    }
    తిరిగి -1;
}

/* Parse a text containing operand and store the result in OP */
స్థిర శూన్య parse_నిర్వాహ్యం(TCCState *s1, నిర్వాహ్యం *op)
{
    సమాసం_విలువ e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    ఒకవేళ (tok == '{') { // regset literal
        తదుపరి(); // skip '{'
        అయితే (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            ఒకవేళ (reg == -1) {
                expect("register");
            } లేకపోతే
                తదుపరి(); // skip register name

            ఒకవేళ ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            ఒకవేళ (tok != ',')
                ఆపు;
            తదుపరి(); // skip ','
        }
        skip('}');
        ఒకవేళ (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } లేకపోతే {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        తిరిగి;
    } లేకపోతే ఒకవేళ ((reg = asm_parse_regvar(tok)) != -1) {
        తదుపరి(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        తిరిగి;
    } లేకపోతే ఒకవేళ ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        తదుపరి(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        తిరిగి;
    } లేకపోతే ఒకవేళ ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        తదుపరి(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        తిరిగి;
    } లేకపోతే ఒకవేళ (tok == '#' || tok == '$') {
        /* constant value */
        తదుపరి(); // skip '#' or '$'
    }
    asm_సమాసం(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    ఒకవేళ (!op->e.sym) {
        ఒకవేళ ((పూర్ణాంకం) op->e.v < 0 && (పూర్ణాంకం) op->e.v >= -255)
            op->type = OP_IM8N;
        లేకపోతే ఒకవేళ (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } లేకపోతే
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC శూన్య g(పూర్ణాంకం c)
{
    పూర్ణాంకం ind1;
    ఒకవేళ (nocode_wanted)
        తిరిగి;
    ind1 = ind + 1;
    ఒకవేళ (ind1 > cur_పాఠ్యం_section->దత్తాంశం_allocated)
        section_realloc(cur_పాఠ్యం_section, ind1);
    cur_పాఠ్యం_section->దత్తాంశం[ind] = c;
    ind = ind1;
}

ST_FUNC శూన్య gen_le16 (పూర్ణాంకం i)
{
    g(i);
    g(i>>8);
}

ST_FUNC శూన్య gen_le32 (పూర్ణాంకం i)
{
    పూర్ణాంకం ind1;
    ఒకవేళ (nocode_wanted)
        తిరిగి;
    ind1 = ind + 4;
    ఒకవేళ (ind1 > cur_పాఠ్యం_section->దత్తాంశం_allocated)
        section_realloc(cur_పాఠ్యం_section, ind1);
    cur_పాఠ్యం_section->దత్తాంశం[ind++] = i & 0xFF;
    cur_పాఠ్యం_section->దత్తాంశం[ind++] = (i >> 8) & 0xFF;
    cur_పాఠ్యం_section->దత్తాంశం[ind++] = (i >> 16) & 0xFF;
    cur_పాఠ్యం_section->దత్తాంశం[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC శూన్య gen_expr32(సమాసం_విలువ *pe)
{
    gen_le32(pe->v);
}

స్థిర uint32_t condition_సంకేతం_యొక్క_token(పూర్ణాంకం token) {
    ఒకవేళ (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } లేకపోతే
        తిరిగి (token - TOK_ASM_nopeq) & 15;
}

స్థిర శూన్య asm_emit_opcode(పూర్ణాంకం token, uint32_t opcode) {
    gen_le32((condition_సంకేతం_యొక్క_token(token) << 28) | opcode);
}

స్థిర శూన్య asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

స్థిర శూన్య asm_emit_coprocessor_opcode(uint32_t ఎగువ_nibble, uint8_t cp_సంఖ్య, uint8_t cp_opcode, uint8_t cp_destination_రిజిస్టరు, uint8_t cp_n_నిర్వాహ్యం_రిజిస్టరు, uint8_t cp_m_నిర్వాహ్యం_రిజిస్టరు, uint8_t cp_opcode2, పూర్ణాంకం inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    ఒకవేళ (inter_processor_transfer)
        opcode |= 1 << 4;
    //assert(cp_opcode < 16);
    opcode |= cp_opcode << 20;
    //assert(cp_n_operand_register < 16);
    opcode |= cp_n_నిర్వాహ్యం_రిజిస్టరు << 16;
    //assert(cp_destination_register < 16);
    opcode |= cp_destination_రిజిస్టరు << 12;
    //assert(cp_number < 16);
    opcode |= cp_సంఖ్య << 8;
    //assert(cp_information < 8);
    opcode |= cp_opcode2 << 5;
    //assert(cp_m_operand_register < 16);
    opcode |= cp_m_నిర్వాహ్యం_రిజిస్టరు;
    asm_emit_unconditional_opcode((ఎగువ_nibble << 28) | opcode);
}

స్థిర శూన్య asm_nullary_opcode(పూర్ణాంకం token)
{
    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        ఆపు;
    స్థితి TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    స్థితి TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        ఆపు;
    అప్రమేయ:
        expect("nullary instruction");
    }
}

స్థిర శూన్య asm_unary_opcode(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం op;
    parse_నిర్వాహ్యం(s1, &op);

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_swieq:
    స్థితి TOK_ASM_svceq:
        ఒకవేళ (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        లేకపోతే {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        ఆపు;
    అప్రమేయ:
        expect("unary instruction");
    }
}

స్థిర శూన్య asm_ద్విమాన_opcode(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం ops[2];
    నిర్వాహ్యం rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_నిర్వాహ్యం(s1, &ops[0]);
    skip(',');
    parse_నిర్వాహ్యం(s1, &ops[1]);
    ఒకవేళ (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    ఒకవేళ (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ఖాళీ));

    ఒకవేళ (ops[1].type != OP_REG32) {
        ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
        స్థితి TOK_ASM_movteq:
        స్థితి TOK_ASM_movweq:
            ఒకవేళ (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                ఒకవేళ (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t తక్షణ_విలువ = ops[1].e.v;
                    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
                    స్థితి TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (తక్షణ_విలువ & 0xF000) << 4 | (తక్షణ_విలువ & 0xFFF));
                        ఆపు;
                    స్థితి TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (తక్షణ_విలువ & 0xF000) << 4 | (తక్షణ_విలువ & 0xFFF));
                        ఆపు;
                    }
                } లేకపోతే
                    expect("(source operand) immediate 16 bit value");
            } లేకపోతే
                expect("(source operand) immediate");
            ఆపు;
        అప్రమేయ:
            expect("(source operand) register");
        }
        తిరిగి;
    }

    ఒకవేళ (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ఖాళీ));

    ఒకవేళ (tok == ',') {
        తదుపరి(); // skip ','
        ఒకవేళ (tok == TOK_ASM_ror) {
            తదుపరి(); // skip 'ror'
            parse_నిర్వాహ్యం(s1, &rotation);
            ఒకవేళ (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } లేకపోతే {
                amount = rotation.e.v;
                ఎంపిక (amount) {
                స్థితి 8:
                    encoded_rotation = 1 << 10;
                    ఆపు;
                స్థితి 16:
                    encoded_rotation = 2 << 10;
                    ఆపు;
                స్థితి 24:
                    encoded_rotation = 3 << 10;
                    ఆపు;
                అప్రమేయ:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_clzeq:
        ఒకవేళ (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        ఆపు;
    స్థితి TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ఆపు;
    స్థితి TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ఆపు;
    స్థితి TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ఆపు;
    స్థితి TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ఆపు;
    అప్రమేయ:
        expect("binary instruction");
    }
}

స్థిర శూన్య asm_coprocessor_opcode(TCCState *s1, పూర్ణాంకం token) {
    uint8_t coprocessor;
    నిర్వాహ్యం opcode1;
    నిర్వాహ్యం opcode2;
    uint8_t registers[3];
    గుర్తులేని పూర్ణాంకం i;
    uint8_t ఎగువ_nibble;
    uint8_t mrc = 0;

    ఒకవేళ (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        తదుపరి();
    } లేకపోతే {
        expect("'p<number>'");
    }
    skip(',');
    parse_నిర్వాహ్యం(s1, &opcode1);
    ఒకవేళ (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ఖాళీ));
    }

    కొరకు (i = 0; i < 3; ++i) {
        skip(',');
        ఒకవేళ (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_సమూహం(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_సమూహం(token) == TOK_ASM_mcreq)) {
            ఒకవేళ (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                తదుపరి();
            } లేకపోతే {
                expect("'r<number>'");
            }
        } లేకపోతే {
            ఒకవేళ (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                తదుపరి();
            } లేకపోతే {
                expect("'c<number>'");
            }
        }
    }
    ఒకవేళ (tok == ',') {
        తదుపరి();
        parse_నిర్వాహ్యం(s1, &opcode2);
    } లేకపోతే {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    ఒకవేళ (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (token == TOK_ASM_cdp2) {
        ఎగువ_nibble = 0xF;
        asm_emit_coprocessor_opcode(ఎగువ_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        తిరిగి;
    } లేకపోతే
        ఎగువ_nibble = condition_సంకేతం_యొక్క_token(token);

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(ఎగువ_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        ఆపు;
    స్థితి TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    స్థితి TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        ఒకవేళ (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, ఖాళీ));
        }
        asm_emit_coprocessor_opcode(ఎగువ_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        ఆపు;
    అప్రమేయ:
        expect("known instruction");
    }
}

/* data processing and single data transfer instructions only */
#నిర్వచించు ENCODE_RN(రిజిస్టరు_సూచీ) ((రిజిస్టరు_సూచీ) << 16)
#నిర్వచించు ENCODE_RD(రిజిస్టరు_సూచీ) ((రిజిస్టరు_సూచీ) << 12)
#నిర్వచించు ENCODE_సమితి_CONDITION_CODES (1 << 20)

/* Note: For data processing instructions, "1" means immediate.
   Note: For single data transfer instructions, "0" means immediate. */
#నిర్వచించు ENCODE_తక్షణ_FLAG (1 << 25)

#నిర్వచించు ENCODE_BARREL_SHIFTER_జరుపు_BY_రిజిస్టరు (1 << 4)
#నిర్వచించు ENCODE_BARREL_SHIFTER_బహుళకం_LSL (0 << 5)
#నిర్వచించు ENCODE_BARREL_SHIFTER_బహుళకం_LSR (1 << 5)
#నిర్వచించు ENCODE_BARREL_SHIFTER_బహుళకం_ASR (2 << 5)
#నిర్వచించు ENCODE_BARREL_SHIFTER_బహుళకం_ROR (3 << 5)
#నిర్వచించు ENCODE_BARREL_SHIFTER_రిజిస్టరు(రిజిస్టరు_సూచీ) ((రిజిస్టరు_సూచీ) << 8)
#నిర్వచించు ENCODE_BARREL_SHIFTER_తక్షణ(విలువ) ((విలువ) << 7)

స్థిర శూన్య asm_ఖండం_దత్తాంశం_transfer_opcode(TCCState *s1, పూర్ణాంకం token)
{
    uint32_t opcode;
    పూర్ణాంకం op0_exclam = 0;
    నిర్వాహ్యం ops[2];
    పూర్ణాంకం nb_ops = 1;
    parse_నిర్వాహ్యం(s1, &ops[0]);
    ఒకవేళ (tok == '!') {
        op0_exclam = 1;
        తదుపరి(); // skip '!'
    }
    ఒకవేళ (tok == ',') {
        తదుపరి(); // skip comma
        parse_నిర్వాహ్యం(s1, &ops[1]);
        ++nb_ops;
    }
    ఒకవేళ (nb_ops < 1) {
        expect("at least one operand");
    } లేకపోతే ఒకవేళ (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        ఒకవేళ (nb_ops != 1)
            expect("exactly one operand");
        లేకపోతే
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        ఆపు;
    స్థితి TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        ఒకవేళ (nb_ops != 1)
            expect("exactly one operand");
        లేకపోతే
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        ఆపు;
    స్థితి TOK_ASM_stmdaeq:
    స్థితి TOK_ASM_ldmdaeq:
    స్థితి TOK_ASM_stmeq:
    స్థితి TOK_ASM_ldmeq:
    స్థితి TOK_ASM_stmiaeq:
    స్థితి TOK_ASM_ldmiaeq:
    స్థితి TOK_ASM_stmdbeq:
    స్థితి TOK_ASM_ldmdbeq:
    స్థితి TOK_ASM_stmibeq:
    స్థితి TOK_ASM_ldmibeq:
        ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
        స్థితి TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            ఆపు;
        స్థితి TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            ఆపు;
        స్థితి TOK_ASM_stmeq: // post-increment store
        స్థితి TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            ఆపు;
        స్థితి TOK_ASM_ldmeq: // post-increment load
        స్థితి TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            ఆపు;
        స్థితి TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            ఆపు;
        స్థితి TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            ఆపు;
        స్థితి TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            ఆపు;
        స్థితి TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            ఆపు;
        అప్రమేయ:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        ఒకవేళ (nb_ops != 2)
            expect("exactly two operands");
        లేకపోతే ఒకవేళ (ops[0].type != OP_REG32)
            expect("(first operand) register");
        లేకపోతే {
            ఒకవేళ (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        ఆపు;
    అప్రమేయ:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
స్థిర uint32_t asm_parse_optional_జరుపు(TCCState* s1, పూర్ణాంకం* nb_జరుపు, నిర్వాహ్యం* జరుపు)
{
    uint32_t opcode = 0;
    *nb_జరుపు = 0;
    ఎంపిక (tok) {
    స్థితి TOK_ASM_asl:
    స్థితి TOK_ASM_lsl:
    స్థితి TOK_ASM_asr:
    స్థితి TOK_ASM_lsr:
    స్థితి TOK_ASM_ror:
        ఎంపిక (tok) {
        స్థితి TOK_ASM_asl:
            /* fallthrough */
        స్థితి TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_బహుళకం_LSL;
            ఆపు;
        స్థితి TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_బహుళకం_ASR;
            ఆపు;
        స్థితి TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_బహుళకం_LSR;
            ఆపు;
        స్థితి TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_బహుళకం_ROR;
            ఆపు;
        }
        తదుపరి();
        parse_నిర్వాహ్యం(s1, జరుపు);
        *nb_జరుపు = 1;
        ఆపు;
    స్థితి TOK_ASM_rrx:
        తదుపరి();
        opcode = ENCODE_BARREL_SHIFTER_బహుళకం_ROR;
        ఆపు;
    }
    తిరిగి opcode;
}

స్థిర uint32_t asm_encode_జరుపు(నిర్వాహ్యం* జరుపు)
{
    uint64_t amount;
    uint32_t operands = 0;
    ఎంపిక (జరుపు->type) {
    స్థితి OP_REG32:
        ఒకవేళ (జరుపు->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        లేకపోతే {
            operands = ENCODE_BARREL_SHIFTER_జరుపు_BY_రిజిస్టరు;
            operands |= ENCODE_BARREL_SHIFTER_రిజిస్టరు(జరుపు->reg);
        }
        ఆపు;
    స్థితి OP_IM8:
        amount = జరుపు->e.v;
        ఒకవేళ (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_తక్షణ(amount);
        లేకపోతే
            tcc_error("shift count out of range");
        ఆపు;
    అప్రమేయ:
        tcc_error("unknown shift amount");
    }
    తిరిగి operands;
}

స్థిర శూన్య asm_దత్తాంశం_processing_opcode(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం ops[3];
    పూర్ణాంకం nb_ops;
    నిర్వాహ్యం జరుపు = {0};
    పూర్ణాంకం nb_జరుపు = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_సమూహం(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    కొరకు (nb_ops = 0; nb_ops < పరిమాణం(ops)/పరిమాణం(ops[0]); ) {
        ఒకవేళ (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            ఆపు;
        parse_నిర్వాహ్యం(s1, &ops[nb_ops]);
        ++nb_ops;
        ఒకవేళ (tok != ',')
            ఆపు;
        తదుపరి(); // skip ','
    }
    ఒకవేళ (tok == ',')
        తదుపరి();
    operands |= asm_parse_optional_జరుపు(s1, &nb_జరుపు, &జరుపు);
    ఒకవేళ (nb_ops < 2)
        expect("at least two operands");
    లేకపోతే ఒకవేళ (nb_ops == 2) {
        జ్ఞాపకం_నకలు(&ops[2], &ops[1], పరిమాణం(ops[1])); // move ops[2]
        జ్ఞాపకం_నకలు(&ops[1], &ops[0], పరిమాణం(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } లేకపోతే ఒకవేళ (nb_ops == 3) {
        ఒకవేళ (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, ఖాళీ));
        }
    }
    ఒకవేళ (nb_ops != 3) {
        expect("two or three operands");
    } లేకపోతే {
        uint32_t opcode = 0;
        uint32_t తక్షణ_విలువ;
        uint8_t half_తక్షణ_rotation;
        ఒకవేళ (nb_జరుపు && జరుపు.type == OP_REG32) {
            ఒకవేళ ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
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
        ఒకవేళ (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        లేకపోతే ఒకవేళ (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_సమితి_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        లేకపోతే
            operands |= ENCODE_RD(ops[0].reg);
        ఒకవేళ (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        లేకపోతే ఒకవేళ (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        ఎంపిక (ops[2].type) {
        స్థితి OP_REG32:
            operands |= ops[2].reg;
            ఆపు;
        స్థితి OP_IM8:
        స్థితి OP_IM32:
            operands |= ENCODE_తక్షణ_FLAG;
            తక్షణ_విలువ = ops[2].e.v;
            కొరకు (half_తక్షణ_rotation = 0; half_తక్షణ_rotation < 16; ++half_తక్షణ_rotation) {
                ఒకవేళ (తక్షణ_విలువ >= 0x00 && తక్షణ_విలువ < 0x100)
                    ఆపు;
                // rotate left by two
                తక్షణ_విలువ = ((తక్షణ_విలువ & 0x3FFFFFFF) << 2) | ((తక్షణ_విలువ & 0xC0000000) >> 30);
            }
            ఒకవేళ (half_తక్షణ_rotation >= 16) {
                /* fallthrough */
            } లేకపోతే {
                operands |= తక్షణ_విలువ;
                operands |= half_తక్షణ_rotation << 8;
                ఆపు;
            }
        స్థితి OP_IM8N: // immediate negative value
            operands |= ENCODE_తక్షణ_FLAG;
            తక్షణ_విలువ = ops[2].e.v;
            /* Instruction swapping:
               0001 = EOR - Rd:= Op1 EOR Op2     -> difficult
               0011 = RSB - Rd:= Op2 - Op1       -> difficult
               0111 = RSC - Rd:= Op2 - Op1 + C   -> difficult
               1000 = TST - CC on: Op1 AND Op2   -> difficult
               1001 = TEQ - CC on: Op1 EOR Op2   -> difficult
               1100 = ORR - Rd:= Op1 OR Op2      -> difficult
            */
            ఎంపిక (opcode_nos) {
            స్థితి 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                తక్షణ_విలువ = ~తక్షణ_విలువ;
                ఆపు;
            స్థితి 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; //కూడు
                తక్షణ_విలువ = -తక్షణ_విలువ;
                ఆపు;
            స్థితి 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                తక్షణ_విలువ = -తక్షణ_విలువ;
                ఆపు;
            స్థితి 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                తక్షణ_విలువ = ~తక్షణ_విలువ;
                ఆపు;
            స్థితి 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                తక్షణ_విలువ = ~తక్షణ_విలువ;
                ఆపు;
            స్థితి 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                తక్షణ_విలువ = -తక్షణ_విలువ;
                ఆపు;
            స్థితి 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                తక్షణ_విలువ = -తక్షణ_విలువ;
                ఆపు;
            స్థితి 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                తక్షణ_విలువ = ~తక్షణ_విలువ;
                ఆపు;
            స్థితి 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                తక్షణ_విలువ = ~తక్షణ_విలువ;
                ఆపు;
            స్థితి 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                తక్షణ_విలువ = ~తక్షణ_విలువ;
                ఆపు;
            అప్రమేయ:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, ఖాళీ));
            }
            కొరకు (half_తక్షణ_rotation = 0; half_తక్షణ_rotation < 16; ++half_తక్షణ_rotation) {
                ఒకవేళ (తక్షణ_విలువ >= 0x00 && తక్షణ_విలువ < 0x100)
                    ఆపు;
                // rotate left by two
                తక్షణ_విలువ = ((తక్షణ_విలువ & 0x3FFFFFFF) << 2) | ((తక్షణ_విలువ & 0xC0000000) >> 30);
            }
            ఒకవేళ (half_తక్షణ_rotation >= 16) {
                తక్షణ_విలువ = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (గుర్తులేని) తక్షణ_విలువ);
            }
            operands |= తక్షణ_విలువ;
            operands |= half_తక్షణ_rotation << 8;
            ఆపు;
        అప్రమేయ:
            expect("(second source operand) register or immediate value");
        }

        ఒకవేళ (nb_జరుపు) {
            ఒకవేళ (operands & ENCODE_తక్షణ_FLAG)
                tcc_error("immediate rotation not implemented");
            లేకపోతే
                operands |= asm_encode_జరుపు(&జరుపు);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_సమితి_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

స్థిర శూన్య asm_జరుపు_opcode(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం ops[3];
    పూర్ణాంకం nb_ops;
    పూర్ణాంకం definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    కొరకు (nb_ops = 0; nb_ops < పరిమాణం(ops)/పరిమాణం(ops[0]); ++nb_ops) {
        parse_నిర్వాహ్యం(s1, &ops[nb_ops]);
        ఒకవేళ (tok != ',') {
            ++nb_ops;
            ఆపు;
        }
        తదుపరి(); // skip ','
    }
    ఒకవేళ (nb_ops < 2) {
        expect("at least two operands");
    }

    ఒకవేళ (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } లేకపోతే
        operands |= ENCODE_RD(ops[0].reg);

    ఒకవేళ (nb_ops == 2) {
        ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
        స్థితి TOK_ASM_rrxseq:
            opcode |= ENCODE_సమితి_CONDITION_CODES;
            /* fallthrough */
        స్థితి TOK_ASM_rrxeq:
            ఒకవేళ (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_బహుళకం_ROR;
                asm_emit_opcode(token, opcode | operands);
            } లేకపోతే
                tcc_error("(first source operand) register");
            తిరిగి;
        అప్రమేయ:
            జ్ఞాపకం_నకలు(&ops[2], &ops[1], పరిమాణం(ops[1])); // move ops[2]
            జ్ఞాపకం_నకలు(&ops[1], &ops[0], పరిమాణం(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    ఒకవేళ (nb_ops != 3) {
        expect("two or three operands");
    }

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_lslseq:
    స్థితి TOK_ASM_lsrseq:
    స్థితి TOK_ASM_asrseq:
    స్థితి TOK_ASM_rorseq:
        opcode |= ENCODE_సమితి_CONDITION_CODES;
        ఆపు;
    }

    ఎంపిక (ops[1].type) {
    స్థితి OP_REG32:
        operands |= ops[1].reg;
        ఆపు;
    స్థితి OP_IM8:
        operands |= ENCODE_తక్షణ_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, ఖాళీ));
    }

    ఎంపిక (ops[2].type) {
    స్థితి OP_REG32:
        ఒకవేళ ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_జరుపు(&ops[2]);
        ఆపు;
    స్థితి OP_IM8:
        ఒకవేళ (ops[2].e.v)
            operands |= asm_encode_జరుపు(&ops[2]);
        లేకపోతే
            definitely_neutral = 1;
        ఆపు;
    }

    ఒకవేళ (!definitely_neutral) ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_lslseq:
    స్థితి TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_బహుళకం_LSL;
        ఆపు;
    స్థితి TOK_ASM_lsrseq:
    స్థితి TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_బహుళకం_LSR;
        ఆపు;
    స్థితి TOK_ASM_asrseq:
    స్థితి TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_బహుళకం_ASR;
        ఆపు;
    స్థితి TOK_ASM_rorseq:
    స్థితి TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_బహుళకం_ROR;
        ఆపు;
    అప్రమేయ:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

స్థిర శూన్య asm_multiplication_opcode(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం ops[4];
    పూర్ణాంకం nb_ops = 0;
    uint32_t opcode = 0x90;

    కొరకు (nb_ops = 0; nb_ops < పరిమాణం(ops)/పరిమాణం(ops[0]); ++nb_ops) {
        parse_నిర్వాహ్యం(s1, &ops[nb_ops]);
        ఒకవేళ (tok != ',') {
            ++nb_ops;
            ఆపు;
        }
        తదుపరి(); // skip ','
    }
    ఒకవేళ (nb_ops < 2)
        expect("at least two operands");
    లేకపోతే ఒకవేళ (nb_ops == 2) {
        ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
        స్థితి TOK_ASM_mulseq:
        స్థితి TOK_ASM_muleq:
            జ్ఞాపకం_నకలు(&ops[2], &ops[0], పరిమాణం(ops[1])); // ARM is actually like this!
            ఆపు;
        అప్రమేయ:
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

    ఒకవేళ (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    లేకపోతే
        expect("(destination operand) register");
    ఒకవేళ (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    లేకపోతే
        expect("(first source operand) register");
    ఒకవేళ (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    లేకపోతే
        expect("(second source operand) register");
    ఒకవేళ (nb_ops > 3) {
        ఒకవేళ (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        లేకపోతే
            expect("(third source operand) register");
    }

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_mulseq:
        opcode |= 1 << 20; //స్థితి
        /* fallthrough */
    స్థితి TOK_ASM_muleq:
        ఒకవేళ (nb_ops != 3)
            expect("three operands");
        లేకపోతే {
            asm_emit_opcode(token, opcode);
        }
        ఆపు;
    స్థితి TOK_ASM_mlaseq:
        opcode |= 1 << 20; //స్థితి
        /* fallthrough */
    స్థితి TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        ఒకవేళ (nb_ops != 4)
            expect("four operands");
        లేకపోతే {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        ఆపు;
    స్థితి TOK_ASM_mlseq:
        opcode |= 0x00400000;
        వెళ్ళు case_TOK_ASM_mlaeq;
    స్థితి TOK_ASM_udiveq:
        opcode |= 0x00200000;
    స్థితి TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        ఆపు;
    అప్రమేయ:
        expect("known multiplication instruction");
    }
}

స్థిర శూన్య asm_long_multiplication_opcode(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం ops[4];
    పూర్ణాంకం nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    కొరకు (nb_ops = 0; nb_ops < పరిమాణం(ops)/పరిమాణం(ops[0]); ++nb_ops) {
        parse_నిర్వాహ్యం(s1, &ops[nb_ops]);
        ఒకవేళ (tok != ',') {
            ++nb_ops;
            ఆపు;
        }
        తదుపరి(); // skip ','
    }
    ఒకవేళ (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    ఒకవేళ (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    లేకపోతే
        expect("(destination lo accumulator) register");
    ఒకవేళ (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    లేకపోతే
        expect("(destination hi accumulator) register");
    ఒకవేళ (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    లేకపోతే
        expect("(first source operand) register");
    ఒకవేళ (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    లేకపోతే
        expect("(second source operand) register");

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_smullseq:
        opcode |= 1 << 20; //స్థితి
        /* fallthrough */
    స్థితి TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        ఆపు;
    స్థితి TOK_ASM_umullseq:
        opcode |= 1 << 20; //స్థితి
        /* fallthrough */
    స్థితి TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        ఆపు;
    స్థితి TOK_ASM_smlalseq:
        opcode |= 1 << 20; //స్థితి
        /* fallthrough */
    స్థితి TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        ఆపు;
    స్థితి TOK_ASM_umlalseq:
        opcode |= 1 << 20; //స్థితి
        /* fallthrough */
    స్థితి TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        ఆపు;
    అప్రమేయ:
        expect("known long multiplication instruction");
    }
}

స్థిర శూన్య asm_single_దత్తాంశం_transfer_opcode(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం ops[3];
    నిర్వాహ్యం strex_నిర్వాహ్యం;
    నిర్వాహ్యం జరుపు;
    పూర్ణాంకం nb_జరుపు = 0;
    పూర్ణాంకం exclam = 0;
    పూర్ణాంకం closed_bracket = 0;
    పూర్ణాంకం op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_నిర్వాహ్యం(s1, &ops[0]);
    ఒకవేళ (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    లేకపోతే {
        expect("(destination operand) register");
    }
    ఒకవేళ (tok != ',')
        expect("at least two arguments");
    తదుపరి(); // skip ','

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_strexheq:
    స్థితి TOK_ASM_strexbeq:
    స్థితి TOK_ASM_strexeq:
        parse_నిర్వాహ్యం(s1, &strex_నిర్వాహ్యం);
        ఒకవేళ (strex_నిర్వాహ్యం.type != OP_REG32) {
            expect("register");
        }
        ఒకవేళ (tok != ',')
            expect("at least three arguments");
        లేకపోతే
            తదుపరి(); // skip ','
        ఆపు;
    }

    skip('[');
    parse_నిర్వాహ్యం(s1, &ops[1]);
    ఒకవేళ (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    లేకపోతే {
        expect("(first source operand) register");
    }
    ఒకవేళ (tok == ']') {
        తదుపరి();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ఒకవేళ (tok == ',') {
        తదుపరి(); // skip ','
        ఒకవేళ (tok == '-') {
            op2_minus = 1;
            తదుపరి();
        }
        parse_నిర్వాహ్యం(s1, &ops[2]);
        ఒకవేళ (ops[2].type == OP_REG32) {
            ఒకవేళ (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ఖాళీ));
            }
            ఒకవేళ (tok == ',') {
                తదుపరి();
                opcode |= asm_parse_optional_జరుపు(s1, &nb_జరుపు, &జరుపు);
                ఒకవేళ (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } లేకపోతే {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    ఒకవేళ (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        ఒకవేళ (tok == '!') {
            exclam = 1;
            తదుపరి(); // skip '!'
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
    ఒకవేళ (exclam)
        opcode |= 1 << 21; // write offset back into register

    ఒకవేళ (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        పూర్ణాంకం v = ops[2].e.v;
        ఒకవేళ (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ఒకవేళ (v >= 0) {
            opcode |= 1 << 23; //పైకి
            ఒకవేళ (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ఖాళీ));
            లేకపోతే
                opcode |= v;
        } లేకపోతే { //కిందికి
            ఒకవేళ (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ఖాళీ));
            లేకపోతే
                opcode |= -v;
        }
    } లేకపోతే ఒకవేళ (ops[2].type == OP_REG32) {
        ఒకవేళ (!op2_minus)
            opcode |= 1 << 23; //పైకి
        opcode |= ENCODE_తక్షణ_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } లేకపోతే
        expect("register");

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    స్థితి TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        ఒకవేళ (nb_జరుపు)
            opcode |= asm_encode_జరుపు(&జరుపు);
        asm_emit_opcode(token, opcode);
        ఆపు;
    స్థితి TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    స్థితి TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        ఒకవేళ (nb_జరుపు)
            opcode |= asm_encode_జరుపు(&జరుపు);
        asm_emit_opcode(token, opcode);
        ఆపు;
    స్థితి TOK_ASM_strexheq:
        opcode |= 1 << 21;
    స్థితి TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    స్థితి TOK_ASM_strexeq:
        ఒకవేళ ((opcode & 0xFFF) || nb_జరుపు) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } లేకపోతే ఒకవేళ (opcode & ENCODE_తక్షణ_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        ఒకవేళ ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_నిర్వాహ్యం.reg;
        asm_emit_opcode(token, opcode);
        ఆపు;
    స్థితి TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    స్థితి TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    స్థితి TOK_ASM_ldrexeq:
        ఒకవేళ ((opcode & 0xFFF) || nb_జరుపు) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } లేకపోతే ఒకవేళ (opcode & ENCODE_తక్షణ_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        ఒకవేళ ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        ఆపు;
    అప్రమేయ:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
స్థిర శూన్య asm_emit_coprocessor_దత్తాంశం_transfer(uint32_t ఎగువ_nibble, uint8_t cp_సంఖ్య, uint8_t CRd, స్థిరరాశి నిర్వాహ్యం* Rn, స్థిరరాశి నిర్వాహ్యం* స్థానభ్రంశం, పూర్ణాంకం స్థానభ్రంశం_minus, పూర్ణాంకం preincrement, పూర్ణాంకం writeback, పూర్ణాంకం long_transfer, పూర్ణాంకం ఎక్కించు) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    ఒకవేళ (long_transfer)
        opcode |= 1 << 22; // long transfer

    ఒకవేళ (ఎక్కించు)
        opcode |= 1 << 20; // L

    opcode |= cp_సంఖ్య << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    ఒకవేళ (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    ఒకవేళ (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    ఒకవేళ (writeback)
        opcode |= 1 << 21; // write offset back into register

    ఒకవేళ (స్థానభ్రంశం->type == OP_IM8 || స్థానభ్రంశం->type == OP_IM8N || స్థానభ్రంశం->type == OP_IM32) {
        పూర్ణాంకం v = స్థానభ్రంశం->e.v;
        ఒకవేళ (స్థానభ్రంశం_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ఒకవేళ (స్థానభ్రంశం->type == OP_IM8N || v < 0)
            v = -v;
        లేకపోతే
            opcode |= 1 << 23; //పైకి
        ఒకవేళ (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        ఒకవేళ (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } లేకపోతే ఒకవేళ (స్థానభ్రంశం->type == OP_REG32) {
        ఒకవేళ (!స్థానభ్రంశం_minus)
            opcode |= 1 << 23; //పైకి
        opcode |= ENCODE_తక్షణ_FLAG; /* if set, it means it's NOT immediate */
        opcode |= స్థానభ్రంశం->reg;
        tcc_error("Using register offset to register address is not possible here");
    } లేకపోతే ఒకవేళ (స్థానభ్రంశం->type == OP_VREG64) {
        opcode |= 16;
        opcode |= స్థానభ్రంశం->reg;
    } లేకపోతే
        expect("immediate or register");

    asm_emit_unconditional_opcode((ఎగువ_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
స్థిర శూన్య asm_coprocessor_దత్తాంశం_transfer_opcode(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_రిజిస్టరు;
    పూర్ణాంకం preincrement = 0;
    పూర్ణాంకం exclam = 0;
    పూర్ణాంకం closed_bracket = 0;
    పూర్ణాంకం op2_minus = 0;
    పూర్ణాంకం long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    ఒకవేళ (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        తదుపరి();
    } లేకపోతే {
        expect("'c<number>'");
    }

    skip(',');

    ఒకవేళ (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_రిజిస్టరు = tok - TOK_ASM_c0;
        తదుపరి();
    } లేకపోతే {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_నిర్వాహ్యం(s1, &ops[1]);
    ఒకవేళ (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    ఒకవేళ (tok == ']') {
        తదుపరి();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ఒకవేళ (tok == ',') {
        తదుపరి(); // skip ','
        ఒకవేళ (tok == '-') {
            op2_minus = 1;
            తదుపరి();
        }
        parse_నిర్వాహ్యం(s1, &ops[2]);
        ఒకవేళ (ops[2].type == OP_REG32) {
            ఒకవేళ (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ఖాళీ));
            }
        } లేకపోతే ఒకవేళ (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, ఖాళీ));
        }
    } లేకపోతే {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    ఒకవేళ (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        ఒకవేళ (tok == '!') {
            exclam = 1;
            తదుపరి(); // skip '!'
        }
    }

    // TODO: Support options.

    ఒకవేళ (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        ఎంపిక (token) {
        స్థితి TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        స్థితి TOK_ASM_ldc2:
            asm_emit_coprocessor_దత్తాంశం_transfer(0xF, coprocessor, coprocessor_destination_రిజిస్టరు, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            ఆపు;
        స్థితి TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        స్థితి TOK_ASM_stc2:
            asm_emit_coprocessor_దత్తాంశం_transfer(0xF, coprocessor, coprocessor_destination_రిజిస్టరు, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            ఆపు;
        }
    } లేకపోతే ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    స్థితి TOK_ASM_stceq:
        asm_emit_coprocessor_దత్తాంశం_transfer(condition_సంకేతం_యొక్క_token(token), coprocessor, coprocessor_destination_రిజిస్టరు, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        ఆపు;
    స్థితి TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    స్థితి TOK_ASM_ldceq:
        asm_emit_coprocessor_దత్తాంశం_transfer(condition_సంకేతం_యొక్క_token(token), coprocessor, coprocessor_destination_రిజిస్టరు, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        ఆపు;
    అప్రమేయ:
        expect("coprocessor data transfer instruction");
    }
}

#ఒకవేళ defined(TCC_ARM_VFP)
#నిర్వచించు CP_SINGLE_PRECISION_FLOAT 10
#నిర్వచించు CP_DOUBLE_PRECISION_FLOAT 11

స్థిర శూన్య asm_floating_బిందువు_single_దత్తాంశం_transfer_opcode(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_రిజిస్టరు = 0;
    పూర్ణాంకం long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_నిర్వాహ్యం(s1, &ops[0]);
    ఒకవేళ (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_రిజిస్టరు = ops[0].reg;
        long_transfer = coprocessor_destination_రిజిస్టరు & 1;
        coprocessor_destination_రిజిస్టరు >>= 1;
    } లేకపోతే ఒకవేళ (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_రిజిస్టరు = ops[0].reg;
        తదుపరి();
    } లేకపోతే {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_నిర్వాహ్యం(s1, &ops[1]);
    ఒకవేళ (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    ఒకవేళ (tok == ',') {
        తదుపరి(); // skip ','
        parse_నిర్వాహ్యం(s1, &ops[2]);
        ఒకవేళ (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } లేకపోతే {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_vldreq:
        asm_emit_coprocessor_దత్తాంశం_transfer(condition_సంకేతం_యొక్క_token(token), coprocessor, coprocessor_destination_రిజిస్టరు, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        ఆపు;
    స్థితి TOK_ASM_vstreq:
        asm_emit_coprocessor_దత్తాంశం_transfer(condition_సంకేతం_యొక్క_token(token), coprocessor, coprocessor_destination_రిజిస్టరు, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        ఆపు;
    అప్రమేయ:
        expect("floating point data transfer instruction");
    }
}

స్థిర శూన్య asm_floating_బిందువు_ఖండం_దత్తాంశం_transfer_opcode(TCCState *s1, పూర్ణాంకం token)
{
    uint8_t coprocessor = 0;
    పూర్ణాంకం మొదటి_regset_రిజిస్టరు;
    పూర్ణాంకం చివరి_regset_రిజిస్టరు;
    uint8_t regset_అంశం_లెక్క;
    uint8_t extra_రిజిస్టరు_బిట్టు = 0;
    పూర్ణాంకం op0_exclam = 0;
    పూర్ణాంకం ఎక్కించు = 0;
    పూర్ణాంకం preincrement = 0;
    నిర్వాహ్యం ops[1];
    నిర్వాహ్యం స్థానభ్రంశం;
    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_vpusheq:
    స్థితి TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        ఆపు;
    అప్రమేయ:
        parse_నిర్వాహ్యం(s1, &ops[0]);
        ఒకవేళ (tok == '!') {
            op0_exclam = 1;
            తదుపరి(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    మొదటి_regset_రిజిస్టరు = asm_parse_vfp_regvar(tok, 1);
    ఒకవేళ ((మొదటి_regset_రిజిస్టరు = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        తదుపరి();
    } లేకపోతే ఒకవేళ ((మొదటి_regset_రిజిస్టరు = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        తదుపరి();
    } లేకపోతే {
        expect("floating-point register");
    }

    ఒకవేళ (tok == '-') {
        తదుపరి();
        ఒకవేళ ((చివరి_regset_రిజిస్టరు = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            తదుపరి();
        లేకపోతే {
            expect("floating-point register");
        }
    } లేకపోతే
        చివరి_regset_రిజిస్టరు = మొదటి_regset_రిజిస్టరు;

    ఒకవేళ (చివరి_regset_రిజిస్టరు < మొదటి_regset_రిజిస్టరు) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_అంశం_లెక్క = చివరి_regset_రిజిస్టరు - మొదటి_regset_రిజిస్టరు + 1;
    ఒకవేళ (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_అంశం_లెక్క <<= 1;
    లేకపోతే {
        extra_రిజిస్టరు_బిట్టు = మొదటి_regset_రిజిస్టరు & 1;
        మొదటి_regset_రిజిస్టరు >>= 1;
    }
    స్థానభ్రంశం.type = OP_IM8;
    స్థానభ్రంశం.e.v = regset_అంశం_లెక్క << 2;
    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_vstmeq: // post-increment store
    స్థితి TOK_ASM_vstmiaeq: // post-increment store
        ఆపు;
    స్థితి TOK_ASM_vpopeq:
    స్థితి TOK_ASM_vldmeq: // post-increment load
    స్థితి TOK_ASM_vldmiaeq: // post-increment load
        ఎక్కించు = 1;
        ఆపు;
    స్థితి TOK_ASM_vldmdbeq: // pre-decrement load
        ఎక్కించు = 1;
        /* fallthrough */
    స్థితి TOK_ASM_vpusheq:
    స్థితి TOK_ASM_vstmdbeq: // pre-decrement store
        స్థానభ్రంశం.type = OP_IM8N;
        స్థానభ్రంశం.e.v = -స్థానభ్రంశం.e.v;
        preincrement = 1;
        ఆపు;
    అప్రమేయ:
        expect("floating point block data transfer instruction");
    }
    ఒకవేళ (ops[0].type != OP_REG32)
        expect("(first operand) register");
    లేకపోతే ఒకవేళ (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ఖాళీ));
    లేకపోతే ఒకవేళ (!op0_exclam && ARM_INSTRUCTION_సమూహం(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_సమూహం(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_సమూహం(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_సమూహం(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, ఖాళీ));
    లేకపోతే
        asm_emit_coprocessor_దత్తాంశం_transfer(condition_సంకేతం_యొక్క_token(token), coprocessor, మొదటి_regset_రిజిస్టరు, &ops[0], &స్థానభ్రంశం, 0, preincrement, op0_exclam, extra_రిజిస్టరు_బిట్టు, ఎక్కించు);
}

#నిర్వచించు VMOV_FRACTIONAL_DIGITS 7
#నిర్వచించు VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

స్థిర uint32_t vmov_parse_fractional_part(స్థిరరాశి అక్షరం* s)
{
    uint32_t ఫలితం = 0;
    పూర్ణాంకం i;
    కొరకు (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        అక్షరం c = *s;
        ఫలితం *= 10;
        ఒకవేళ (c >= '0' && c <= '9') {
            ఫలితం += (c - '0');
            ++s;
        }
    }
    ఒకవేళ (*s)
        expect("decimal numeral");
    తిరిగి ఫలితం;
}

స్థిర పూర్ణాంకం vmov_రేఖీయ_approx_సూచీ(uint32_t beginning, uint32_t చివర, uint32_t విలువ)
{
    పూర్ణాంకం i;
    uint32_t k;
    uint32_t xvalue;

    k = (చివర - beginning)/16;
    కొరకు (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        ఒకవేళ (విలువ == xvalue)
            తిరిగి i;
    }
    //assert(0);
    తిరిగి -1;
}

స్థిర uint32_t vmov_parse_తక్షణ_విలువ() {
    uint32_t విలువ;
    గుర్తులేని దీర్ఘ integral_విలువ;
    స్థిరరాశి అక్షరం *p;

    ఒకవేళ (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.దత్తాంశం;
    errno = 0;
    integral_విలువ = strtoul(p, (అక్షరం **)&p, 0);

    ఒకవేళ (errno || integral_విలువ >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    విలువ = (uint32_t) integral_విలువ * VMOV_ONE;
    ఒకవేళ (*p == '.') {
        ++p;
        విలువ += vmov_parse_fractional_part(p);
    }
    తదుపరి();
    తిరిగి విలువ;
}

స్థిర uint8_t vmov_encode_తక్షణ_విలువ(uint32_t విలువ)
{
    uint32_t హద్దు;
    uint32_t చివర = 0;
    uint32_t beginning = 0;
    పూర్ణాంకం r = -1;
    పూర్ణాంకం n;
    పూర్ణాంకం i;

    హద్దు = 32 * VMOV_ONE;
    కొరకు (i = 0; i < 8; ++i) {
        ఒకవేళ (విలువ < హద్దు) {
            చివర = హద్దు;
            హద్దు >>= 1;
            beginning = హద్దు;
            r = i;
        } లేకపోతే
            హద్దు >>= 1;
    }
    ఒకవేళ (r == -1 || విలువ < beginning || విలువ > చివర) {
        tcc_error("invalid decimal number for vmov: %d", విలువ);
    }
    n = vmov_రేఖీయ_approx_సూచీ(beginning, చివర, విలువ);
    తిరిగి n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
స్థిర శూన్య asm_floating_బిందువు_తక్షణ_దత్తాంశం_processing_opcode_తోక(TCCState *s1, పూర్ణాంకం token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t తక్షణ_విలువ = 0;
    పూర్ణాంకం op_minus = 0;
    uint8_t సంకేతం_2;

    operands[0] = CRd;

    ఒకవేళ (tok == '#' || tok == '$') {
        తదుపరి();
    }
    ఒకవేళ (tok == '-') {
        op_minus = 1;
        తదుపరి();
    }
    తక్షణ_విలువ = vmov_parse_తక్షణ_విలువ();

    opcode1 = 11; // "Other" instruction
    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_vcmpeq_f32:
    స్థితి TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        ఒకవేళ (తక్షణ_విలువ) {
            expect("Immediate value 0");
        }
        ఆపు;
    స్థితి TOK_ASM_vcmpeeq_f32:
    స్థితి TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        ఒకవేళ (తక్షణ_విలువ) {
            expect("Immediate value 0");
        }
        ఆపు;
    స్థితి TOK_ASM_vmoveq_f32:
    స్థితి TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        ఒకవేళ (op_minus)
            operands[1] = 0x8;
        లేకపోతే
            operands[1] = 0x0;
        సంకేతం_2 = vmov_encode_తక్షణ_విలువ(తక్షణ_విలువ);
        operands[1] |= సంకేతం_2 >> 4;
        operands[2] = సంకేతం_2 & 0xF;
        ఆపు;
    అప్రమేయ:
        expect("known floating point with immediate instruction");
    }

    ఒకవేళ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        ఒకవేళ (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_సంకేతం_యొక్క_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

స్థిర శూన్య asm_floating_బిందువు_reg_arm_reg_transfer_opcode_తోక(TCCState *s1, పూర్ణాంకం token, పూర్ణాంకం coprocessor, పూర్ణాంకం nb_arm_regs, పూర్ణాంకం nb_ops, నిర్వాహ్యం ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    ఎంపిక (coprocessor) {
    స్థితి CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        ఒకవేళ (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        ఒకవేళ (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            జ్ఞాపకం_నకలు(&ops[2], &ops[1], పరిమాణం(ops[2]));
            జ్ఞాపకం_నకలు(&ops[1], &ops[0], పరిమాణం(ops[1]));
            జ్ఞాపకం_నకలు(&ops[0], &ops[2], పరిమాణం(ops[0]));
        } లేకపోతే
            opcode1 |= 1;

        ఒకవేళ (ops[1].type == OP_VREG32) {
            ఒకవేళ (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        ఒకవేళ (ops[0].type == OP_VREG32) {
            ఒకవేళ (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_సంకేతం_యొక్క_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        ఆపు;
    స్థితి CP_DOUBLE_PRECISION_FLOAT:
        ఒకవేళ (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        ఒకవేళ (ops[0].type == OP_VREG64) {
            ఒకవేళ (ops[2].type == OP_REG32) {
                నిర్వాహ్యం తాత్కాలిక;
                // need to rotate operand list to the left
                జ్ఞాపకం_నకలు(&తాత్కాలిక, &ops[0], పరిమాణం(తాత్కాలిక));
                జ్ఞాపకం_నకలు(&ops[0], &ops[1], పరిమాణం(ops[0]));
                జ్ఞాపకం_నకలు(&ops[1], &ops[2], పరిమాణం(ops[1]));
                జ్ఞాపకం_నకలు(&ops[2], &తాత్కాలిక, పరిమాణం(ops[2]));
            } లేకపోతే {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } లేకపోతే ఒకవేళ (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } లేకపోతే {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_దత్తాంశం_transfer(condition_సంకేతం_యొక్క_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        ఆపు;
    అప్రమేయ:
        tcc_అంతర్గత_error("unknown coprocessor");
    }
}

స్థిర శూన్య asm_floating_బిందువు_vcvt_దత్తాంశం_processing_opcode(TCCState *s1, పూర్ణాంకం token) {
    uint8_t coprocessor = 0;
    నిర్వాహ్యం ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_vcvtreq_s32_f64:
    స్థితి TOK_ASM_vcvtreq_u32_f64:
    స్థితి TOK_ASM_vcvteq_s32_f64:
    స్థితి TOK_ASM_vcvteq_u32_f64:
    స్థితి TOK_ASM_vcvteq_f64_s32:
    స్థితి TOK_ASM_vcvteq_f64_u32:
    స్థితి TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       ఆపు;
    స్థితి TOK_ASM_vcvtreq_s32_f32:
    స్థితి TOK_ASM_vcvtreq_u32_f32:
    స్థితి TOK_ASM_vcvteq_s32_f32:
    స్థితి TOK_ASM_vcvteq_u32_f32:
    స్థితి TOK_ASM_vcvteq_f32_s32:
    స్థితి TOK_ASM_vcvteq_f32_u32:
    స్థితి TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       ఆపు;
    అప్రమేయ:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, ఖాళీ));
    }

    parse_నిర్వాహ్యం(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_vcvtreq_s32_f32:
    స్థితి TOK_ASM_vcvtreq_s32_f64:
    స్థితి TOK_ASM_vcvteq_s32_f32:
    స్థితి TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    స్థితి TOK_ASM_vcvteq_u32_f32:
    స్థితి TOK_ASM_vcvteq_u32_f64:
    స్థితి TOK_ASM_vcvtreq_u32_f32:
    స్థితి TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        ఆపు;
    /* floating-point size conversion */
    స్థితి TOK_ASM_vcvteq_f64_f32:
    స్థితి TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        ఆపు;
    }

    skip(',');
    parse_నిర్వాహ్యం(s1, &ops[2]);

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    /* floating-point -> integer */
    స్థితి TOK_ASM_vcvteq_s32_f32:
    స్థితి TOK_ASM_vcvteq_s32_f64:
    స్థితి TOK_ASM_vcvteq_u32_f32:
    స్థితి TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        ఆపు;

    /* integer -> floating-point */
    స్థితి TOK_ASM_vcvteq_f64_s32:
    స్థితి TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        ఆపు;

    /* floating-point size conversion */
    స్థితి TOK_ASM_vcvteq_f64_f32:
    స్థితి TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        ఆపు;
    }

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_vcvteq_f64_u32:
    స్థితి TOK_ASM_vcvteq_f64_s32:
    స్థితి TOK_ASM_vcvteq_f64_f32:
        ఒకవేళ (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } లేకపోతే {
            expect("d<number>, s<number>");
        }
        ఆపు;
    అప్రమేయ:
        ఒకవేళ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            ఒకవేళ (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } లేకపోతే {
                expect("s<number>, s<number>");
            }
        } లేకపోతే ఒకవేళ (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            ఒకవేళ (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } లేకపోతే {
                expect("s<number>, d<number>");
            }
        }
    }

    ఒకవేళ (ops[2].type == OP_VREG32) {
        ఒకవేళ (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    ఒకవేళ (ops[0].type == OP_VREG32) {
        ఒకవేళ (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_సంకేతం_యొక్క_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

స్థిర శూన్య asm_floating_బిందువు_దత్తాంశం_processing_opcode(TCCState *s1, పూర్ణాంకం token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    నిర్వాహ్యం ops[3];
    uint8_t nb_ops = 0;
    పూర్ణాంకం vmov = 0;
    పూర్ణాంకం nb_arm_regs = 0;

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

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_vmlaeq_f64:
    స్థితి TOK_ASM_vmlseq_f64:
    స్థితి TOK_ASM_vnmlseq_f64:
    స్థితి TOK_ASM_vnmlaeq_f64:
    స్థితి TOK_ASM_vmuleq_f64:
    స్థితి TOK_ASM_vnmuleq_f64:
    స్థితి TOK_ASM_vaddeq_f64:
    స్థితి TOK_ASM_vsubeq_f64:
    స్థితి TOK_ASM_vdiveq_f64:
    స్థితి TOK_ASM_vnegeq_f64:
    స్థితి TOK_ASM_vabseq_f64:
    స్థితి TOK_ASM_vsqrteq_f64:
    స్థితి TOK_ASM_vcmpeq_f64:
    స్థితి TOK_ASM_vcmpeeq_f64:
    స్థితి TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_vmoveq_f32:
    స్థితి TOK_ASM_vmoveq_f64:
        vmov = 1;
        ఆపు;
    }

    కొరకు (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        ఒకవేళ (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_బిందువు_తక్షణ_దత్తాంశం_processing_opcode_తోక(s1, token, coprocessor, ops[0].reg);
            తిరిగి;
        }
        parse_నిర్వాహ్యం(s1, &ops[nb_ops]);
        ఒకవేళ (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } లేకపోతే ఒకవేళ (ops[nb_ops].type == OP_VREG32) {
            ఒకవేళ (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } లేకపోతే ఒకవేళ (ops[nb_ops].type == OP_VREG64) {
            ఒకవేళ (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } లేకపోతే {
            expect("floating point register");
        }
        ++nb_ops;
        ఒకవేళ (tok == ',')
            తదుపరి();
        లేకపోతే
            ఆపు;
    }

    ఒకవేళ (nb_arm_regs == 0) {
        ఒకవేళ (nb_ops == 2) { // implicit
            జ్ఞాపకం_నకలు(&ops[2], &ops[1], పరిమాణం(ops[1])); // move ops[2]
            జ్ఞాపకం_నకలు(&ops[1], &ops[0], పరిమాణం(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        ఒకవేళ (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, ఖాళీ), nb_ops);
        }
    }

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_vmlaeq_f32:
    స్థితి TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        ఆపు;
    స్థితి TOK_ASM_vmlseq_f32:
    స్థితి TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        ఆపు;
    స్థితి TOK_ASM_vnmlseq_f32:
    స్థితి TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        ఆపు;
    స్థితి TOK_ASM_vnmlaeq_f32:
    స్థితి TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        ఆపు;
    స్థితి TOK_ASM_vmuleq_f32:
    స్థితి TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        ఆపు;
    స్థితి TOK_ASM_vnmuleq_f32:
    స్థితి TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        ఆపు;
    స్థితి TOK_ASM_vaddeq_f32:
    స్థితి TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        ఆపు;
    స్థితి TOK_ASM_vsubeq_f32:
    స్థితి TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        ఆపు;
    స్థితి TOK_ASM_vdiveq_f32:
    స్థితి TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        ఆపు;
    స్థితి TOK_ASM_vnegeq_f32:
    స్థితి TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        ఆపు;
    స్థితి TOK_ASM_vabseq_f32:
    స్థితి TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        ఆపు;
    స్థితి TOK_ASM_vsqrteq_f32:
    స్థితి TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        ఆపు;
    స్థితి TOK_ASM_vcmpeq_f32:
    స్థితి TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        ఆపు;
    స్థితి TOK_ASM_vcmpeeq_f32:
    స్థితి TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        ఆపు;
    స్థితి TOK_ASM_vmoveq_f32:
    స్థితి TOK_ASM_vmoveq_f64:
        ఒకవేళ (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_బిందువు_reg_arm_reg_transfer_opcode_తోక(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            తిరిగి;
        } లేకపోతే {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        ఆపు;
    అప్రమేయ:
        expect("known floating point instruction");
    }

    ఒకవేళ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        ఒకవేళ (ops[2].type == OP_VREG32) {
            ఒకవేళ (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        ఒకవేళ (ops[1].type == OP_VREG32) {
            ఒకవేళ (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        ఒకవేళ (ops[0].type == OP_VREG32) {
            ఒకవేళ (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_సంకేతం_యొక్క_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

స్థిర పూర్ణాంకం asm_parse_vfp_స్థితి_regvar(పూర్ణాంకం t)
{
    ఎంపిక (t) {
    స్థితి TOK_ASM_fpsid:
        తిరిగి 0;
    స్థితి TOK_ASM_fpscr:
        తిరిగి 1;
    స్థితి TOK_ASM_fpexc:
        తిరిగి 8;
    అప్రమేయ:
        తిరిగి -1;
    }
}

స్థిర శూన్య asm_floating_బిందువు_స్థితి_రిజిస్టరు_opcode(TCCState* s1, పూర్ణాంకం token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    పూర్ణాంకం vfp_sys_reg = -1;
    నిర్వాహ్యం arm_నిర్వాహ్యం;
    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_vmrseq:
        opcode = 0xf;
        ఒకవేళ (tok == TOK_ASM_apsr_nzcv) {
            arm_నిర్వాహ్యం.type = OP_REG32;
            arm_నిర్వాహ్యం.reg = 15; // not PC
            తదుపరి(); // skip apsr_nzcv
        } లేకపోతే {
            parse_నిర్వాహ్యం(s1, &arm_నిర్వాహ్యం);
            ఒకవేళ (arm_నిర్వాహ్యం.type == OP_REG32 && arm_నిర్వాహ్యం.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ఖాళీ));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_స్థితి_regvar(tok);
        తదుపరి(); // skip vfp sys reg
        ఒకవేళ (arm_నిర్వాహ్యం.type == OP_REG32 && arm_నిర్వాహ్యం.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, ఖాళీ));
        }
        ఆపు;
    స్థితి TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_స్థితి_regvar(tok);
        తదుపరి(); // skip vfp sys reg
        skip(',');
        parse_నిర్వాహ్యం(s1, &arm_నిర్వాహ్యం);
        ఒకవేళ (arm_నిర్వాహ్యం.type == OP_REG32 && arm_నిర్వాహ్యం.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ఖాళీ));
        }
        ఆపు;
    అప్రమేయ:
        expect("floating point status register instruction");
    }
    ఒకవేళ (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    ఒకవేళ (arm_నిర్వాహ్యం.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_సంకేతం_యొక్క_token(token), coprocessor, opcode, arm_నిర్వాహ్యం.reg, vfp_sys_reg, 0x10, 0, 0);
}

#అయితే_ముగింపు

స్థిర శూన్య asm_misc_single_దత్తాంశం_transfer_opcode(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం ops[3];
    పూర్ణాంకం exclam = 0;
    పూర్ణాంకం closed_bracket = 0;
    పూర్ణాంకం op2_minus = 0;
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

    parse_నిర్వాహ్యం(s1, &ops[0]);
    ఒకవేళ (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    లేకపోతే {
        expect("(destination operand) register");
    }
    ఒకవేళ (tok != ',')
        expect("at least two arguments");
    లేకపోతే
        తదుపరి(); // skip ','
    skip('[');
    parse_నిర్వాహ్యం(s1, &ops[1]);
    ఒకవేళ (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    లేకపోతే {
        expect("(first source operand) register");
    }
    ఒకవేళ (tok == ']') {
        తదుపరి();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ఒకవేళ (tok == ',') {
        తదుపరి(); // skip ','
        ఒకవేళ (tok == '-') {
            op2_minus = 1;
            తదుపరి();
        }
        parse_నిర్వాహ్యం(s1, &ops[2]);
    } లేకపోతే {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    ఒకవేళ (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        ఒకవేళ (tok == '!') {
            exclam = 1;
            తదుపరి(); // skip '!'
        }
    }

    ఒకవేళ (exclam) {
        ఒకవేళ ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, ఖాళీ));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    ఒకవేళ (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        పూర్ణాంకం v = ops[2].e.v;
        ఒకవేళ (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ఒకవేళ (v >= 0) {
            opcode |= 1 << 23; //పైకి
            ఒకవేళ (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ఖాళీ));
            లేకపోతే {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } లేకపోతే { //కిందికి
            ఒకవేళ (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ఖాళీ));
            లేకపోతే {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } లేకపోతే ఒకవేళ (ops[2].type == OP_REG32) {
        ఒకవేళ (!op2_minus)
            opcode |= 1 << 23; //పైకి
        opcode |= ops[2].reg;
    } లేకపోతే
        expect("register");

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    స్థితి TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        ఆపు;
    స్థితి TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        ఆపు;
    స్థితి TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        ఆపు;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
స్థిర uint32_t encbranchoffset(పూర్ణాంకం pos, పూర్ణాంకం addr, పూర్ణాంకం fail)
{
  addr-=pos+8;
  addr/=4;
  ఒకవేళ(addr>=0x7fffff || addr<-0x800000) {
    ఒకవేళ(fail)
      tcc_error("branch offset is too far");
    తిరిగి 0;
  }
  తిరిగి /*not 0x0A000000|*/(addr&0xffffff);
}

స్థిర శూన్య asm_branch_opcode(TCCState *s1, పూర్ణాంకం token)
{
    పూర్ణాంకం jmp_disp = 0;
    నిర్వాహ్యం op;
    సమాసం_విలువ e;
    ElfSym *esym;

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_beq:
    స్థితి TOK_ASM_bleq:
        asm_సమాసం(s1, &e);
        ఒకవేళ (e.sym) {
            esym = elfsym(e.sym);
            ఒకవేళ (esym && esym->st_shndx == cur_పాఠ్యం_section->sh_అంకె) {
                jmp_disp = esym->st_విలువ;
            } లేకపోతే {
                greloca(cur_పాఠ్యం_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        ఆపు;
    అప్రమేయ:
        parse_నిర్వాహ్యం(s1, &op);
        ఆపు;
    }
    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        ఆపు;
    స్థితి TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        ఆపు;
    స్థితి TOK_ASM_bxeq:
        ఒకవేళ (op.type != OP_REG32)
            expect("register");
        లేకపోతే
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        ఆపు;
    స్థితి TOK_ASM_blxeq:
        ఒకవేళ (op.type != OP_REG32)
            expect("register");
        లేకపోతే
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        ఆపు;
    అప్రమేయ:
        expect("branch instruction");
    }
}

ST_FUNC శూన్య asm_opcode(TCCState *s1, పూర్ణాంకం token)
{
    అయితే (token == TOK_LINEFEED) {
        తదుపరి();
        token = tok;
    }
    ఒకవేళ (token == TOK_EOF)
        తిరిగి;
    ఒకవేళ (token < TOK_ASM_nopeq) { // no condition code
        ఎంపిక (token) {
        స్థితి TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            తిరిగి;
        స్థితి TOK_ASM_ldc2:
        స్థితి TOK_ASM_ldc2l:
        స్థితి TOK_ASM_stc2:
        స్థితి TOK_ASM_stc2l:
            asm_coprocessor_దత్తాంశం_transfer_opcode(s1, token);
            తిరిగి;
        అప్రమేయ:
            expect("instruction");
        }
    }

    ఎంపిక (ARM_INSTRUCTION_సమూహం(token)) {
    స్థితి TOK_ASM_pusheq:
    స్థితి TOK_ASM_popeq:
    స్థితి TOK_ASM_stmdaeq:
    స్థితి TOK_ASM_ldmdaeq:
    స్థితి TOK_ASM_stmeq:
    స్థితి TOK_ASM_ldmeq:
    స్థితి TOK_ASM_stmiaeq:
    స్థితి TOK_ASM_ldmiaeq:
    స్థితి TOK_ASM_stmdbeq:
    స్థితి TOK_ASM_ldmdbeq:
    స్థితి TOK_ASM_stmibeq:
    స్థితి TOK_ASM_ldmibeq:
        asm_ఖండం_దత్తాంశం_transfer_opcode(s1, token);
        తిరిగి;
    స్థితి TOK_ASM_nopeq:
    స్థితి TOK_ASM_wfeeq:
    స్థితి TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        తిరిగి;
    స్థితి TOK_ASM_swieq:
    స్థితి TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        తిరిగి;
    స్థితి TOK_ASM_beq:
    స్థితి TOK_ASM_bleq:
    స్థితి TOK_ASM_bxeq:
    స్థితి TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        తిరిగి;
    స్థితి TOK_ASM_clzeq:
    స్థితి TOK_ASM_sxtbeq:
    స్థితి TOK_ASM_sxtheq:
    స్థితి TOK_ASM_uxtbeq:
    స్థితి TOK_ASM_uxtheq:
    స్థితి TOK_ASM_movteq:
    స్థితి TOK_ASM_movweq:
        asm_ద్విమాన_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_ldreq:
    స్థితి TOK_ASM_ldrbeq:
    స్థితి TOK_ASM_streq:
    స్థితి TOK_ASM_strbeq:
    స్థితి TOK_ASM_ldrexeq:
    స్థితి TOK_ASM_ldrexbeq:
    స్థితి TOK_ASM_ldrexheq:
    స్థితి TOK_ASM_strexeq:
    స్థితి TOK_ASM_strexbeq:
    స్థితి TOK_ASM_strexheq:
        asm_single_దత్తాంశం_transfer_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_ldrheq:
    స్థితి TOK_ASM_ldrsheq:
    స్థితి TOK_ASM_ldrsbeq:
    స్థితి TOK_ASM_strheq:
       asm_misc_single_దత్తాంశం_transfer_opcode(s1, token);
       తిరిగి;

    స్థితి TOK_ASM_andeq:
    స్థితి TOK_ASM_eoreq:
    స్థితి TOK_ASM_subeq:
    స్థితి TOK_ASM_rsbeq:
    స్థితి TOK_ASM_addeq:
    స్థితి TOK_ASM_adceq:
    స్థితి TOK_ASM_sbceq:
    స్థితి TOK_ASM_rsceq:
    స్థితి TOK_ASM_tsteq:
    స్థితి TOK_ASM_teqeq:
    స్థితి TOK_ASM_cmpeq:
    స్థితి TOK_ASM_cmneq:
    స్థితి TOK_ASM_orreq:
    స్థితి TOK_ASM_moveq:
    స్థితి TOK_ASM_biceq:
    స్థితి TOK_ASM_mvneq:
    స్థితి TOK_ASM_andseq:
    స్థితి TOK_ASM_eorseq:
    స్థితి TOK_ASM_subseq:
    స్థితి TOK_ASM_rsbseq:
    స్థితి TOK_ASM_addseq:
    స్థితి TOK_ASM_adcseq:
    స్థితి TOK_ASM_sbcseq:
    స్థితి TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    స్థితి TOK_ASM_orrseq:
    స్థితి TOK_ASM_movseq:
    స్థితి TOK_ASM_bicseq:
    స్థితి TOK_ASM_mvnseq:
        asm_దత్తాంశం_processing_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_lsleq:
    స్థితి TOK_ASM_lslseq:
    స్థితి TOK_ASM_lsreq:
    స్థితి TOK_ASM_lsrseq:
    స్థితి TOK_ASM_asreq:
    స్థితి TOK_ASM_asrseq:
    స్థితి TOK_ASM_roreq:
    స్థితి TOK_ASM_rorseq:
    స్థితి TOK_ASM_rrxseq:
    స్థితి TOK_ASM_rrxeq:
        asm_జరుపు_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_muleq:
    స్థితి TOK_ASM_mulseq:
    స్థితి TOK_ASM_mlaeq:
    స్థితి TOK_ASM_mlaseq:
    స్థితి TOK_ASM_mlseq:
    స్థితి TOK_ASM_udiveq:
    స్థితి TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_smulleq:
    స్థితి TOK_ASM_smullseq:
    స్థితి TOK_ASM_umulleq:
    స్థితి TOK_ASM_umullseq:
    స్థితి TOK_ASM_smlaleq:
    స్థితి TOK_ASM_smlalseq:
    స్థితి TOK_ASM_umlaleq:
    స్థితి TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_cdpeq:
    స్థితి TOK_ASM_mcreq:
    స్థితి TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_ldceq:
    స్థితి TOK_ASM_ldcleq:
    స్థితి TOK_ASM_stceq:
    స్థితి TOK_ASM_stcleq:
        asm_coprocessor_దత్తాంశం_transfer_opcode(s1, token);
        తిరిగి;

#ఒకవేళ defined(TCC_ARM_VFP)
    స్థితి TOK_ASM_vldreq:
    స్థితి TOK_ASM_vstreq:
        asm_floating_బిందువు_single_దత్తాంశం_transfer_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_vmlaeq_f32:
    స్థితి TOK_ASM_vmlseq_f32:
    స్థితి TOK_ASM_vnmlseq_f32:
    స్థితి TOK_ASM_vnmlaeq_f32:
    స్థితి TOK_ASM_vmuleq_f32:
    స్థితి TOK_ASM_vnmuleq_f32:
    స్థితి TOK_ASM_vaddeq_f32:
    స్థితి TOK_ASM_vsubeq_f32:
    స్థితి TOK_ASM_vdiveq_f32:
    స్థితి TOK_ASM_vnegeq_f32:
    స్థితి TOK_ASM_vabseq_f32:
    స్థితి TOK_ASM_vsqrteq_f32:
    స్థితి TOK_ASM_vcmpeq_f32:
    స్థితి TOK_ASM_vcmpeeq_f32:
    స్థితి TOK_ASM_vmoveq_f32:
    స్థితి TOK_ASM_vmlaeq_f64:
    స్థితి TOK_ASM_vmlseq_f64:
    స్థితి TOK_ASM_vnmlseq_f64:
    స్థితి TOK_ASM_vnmlaeq_f64:
    స్థితి TOK_ASM_vmuleq_f64:
    స్థితి TOK_ASM_vnmuleq_f64:
    స్థితి TOK_ASM_vaddeq_f64:
    స్థితి TOK_ASM_vsubeq_f64:
    స్థితి TOK_ASM_vdiveq_f64:
    స్థితి TOK_ASM_vnegeq_f64:
    స్థితి TOK_ASM_vabseq_f64:
    స్థితి TOK_ASM_vsqrteq_f64:
    స్థితి TOK_ASM_vcmpeq_f64:
    స్థితి TOK_ASM_vcmpeeq_f64:
    స్థితి TOK_ASM_vmoveq_f64:
        asm_floating_బిందువు_దత్తాంశం_processing_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_vcvtreq_s32_f32:
    స్థితి TOK_ASM_vcvtreq_s32_f64:
    స్థితి TOK_ASM_vcvteq_s32_f32:
    స్థితి TOK_ASM_vcvteq_s32_f64:
    స్థితి TOK_ASM_vcvtreq_u32_f32:
    స్థితి TOK_ASM_vcvtreq_u32_f64:
    స్థితి TOK_ASM_vcvteq_u32_f32:
    స్థితి TOK_ASM_vcvteq_u32_f64:
    స్థితి TOK_ASM_vcvteq_f64_s32:
    స్థితి TOK_ASM_vcvteq_f32_s32:
    స్థితి TOK_ASM_vcvteq_f64_u32:
    స్థితి TOK_ASM_vcvteq_f32_u32:
    స్థితి TOK_ASM_vcvteq_f64_f32:
    స్థితి TOK_ASM_vcvteq_f32_f64:
        asm_floating_బిందువు_vcvt_దత్తాంశం_processing_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_vpusheq:
    స్థితి TOK_ASM_vpopeq:
    స్థితి TOK_ASM_vldmeq:
    స్థితి TOK_ASM_vldmiaeq:
    స్థితి TOK_ASM_vldmdbeq:
    స్థితి TOK_ASM_vstmeq:
    స్థితి TOK_ASM_vstmiaeq:
    స్థితి TOK_ASM_vstmdbeq:
        asm_floating_బిందువు_ఖండం_దత్తాంశం_transfer_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_vmsreq:
    స్థితి TOK_ASM_vmrseq:
        asm_floating_బిందువు_స్థితి_రిజిస్టరు_opcode(s1, token);
        తిరిగి;
#అయితే_ముగింపు

    అప్రమేయ:
        expect("known instruction");
    }
}

ST_FUNC శూన్య subst_asm_నిర్వాహ్యం(CString *కూడు_str, SValue *sv, పూర్ణాంకం modifier)
{
    పూర్ణాంకం r, reg, కొలత, val;

    r = sv->r;
    ఒకవేళ ((r & VT_VALMASK) == VT_CONST) {
        ఒకవేళ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(కూడు_str, '#');
        ఒకవేళ (r & VT_SYM) {
            స్థిరరాశి అక్షరం *name = get_tok_str(sv->sym->v, ఖాళీ);
            ఒకవేళ (sv->sym->v >= SYM_మొదటి_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, అక్షరశ్రేణి_పొడవు(name))->tok, sv->sym);
            }
            ఒకవేళ (tcc_state->leading_underscore)
                cstr_ccat(కూడు_str, '_');
            cstr_cat(కూడు_str, name, -1);
            ఒకవేళ ((uint32_t) sv->c.i == 0)
                వెళ్ళు no_స్థానభ్రంశం;
            cstr_ccat(కూడు_str, '+');
        }
        val = sv->c.i;
        ఒకవేళ (modifier == 'n')
            val = -val;
        cstr_printf(కూడు_str, "%d", val);
      no_స్థానభ్రంశం:;
    } లేకపోతే ఒకవేళ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(కూడు_str, "[fp,#%d]", (పూర్ణాంకం) sv->c.i);
    } లేకపోతే ఒకవేళ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ఒకవేళ (reg >= VT_CONST)
            tcc_అంతర్గత_error("");
        cstr_printf(కూడు_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, ఖాళీ));
    } లేకపోతే {
        /* register case */
        reg = r & VT_VALMASK;
        ఒకవేళ (reg >= VT_CONST)
            tcc_అంతర్గత_error("");

        /* choose register operand size */
        ఒకవేళ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            కొలత = 1;
        లేకపోతే ఒకవేళ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            కొలత = 2;
        లేకపోతే
            కొలత = 4;

        ఒకవేళ (modifier == 'b') {
            కొలత = 1;
        } లేకపోతే ఒకవేళ (modifier == 'w') {
            కొలత = 2;
        } లేకపోతే ఒకవేళ (modifier == 'k') {
            కొలత = 4;
        }

        ఎంపిక (కొలత) {
        అప్రమేయ:
            reg = TOK_ASM_r0 + reg;
            ఆపు;
        }
        cstr_printf(కూడు_str, "%s", get_tok_str(reg, ఖాళీ));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC శూన్య asm_gen_సంకేతం(ASMOperand *operands, పూర్ణాంకం nb_operands,
                          పూర్ణాంకం nb_outputs, పూర్ణాంకం is_output,
                          uint8_t *clobber_regs,
                          పూర్ణాంకం బహిర్గతం_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    పూర్ణాంకం i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    స్థిర స్థిరరాశి uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    జ్ఞాపకం_నకలు(regs_allocated, clobber_regs, పరిమాణం(regs_allocated));
    కొరకు(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        ఒకవేళ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    కొరకు(i = 0; i < పరిమాణం(reg_saved)/పరిమాణం(reg_saved[0]); i++) {
        reg = reg_saved[i];
        ఒకవేళ (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    ఒకవేళ (!is_output) { // prolog
        /* generate reg save code */
        ఒకవేళ (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        కొరకు(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ఒకవేళ (op->reg >= 0) {
                ఒకవేళ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_జ్ఞాపకం) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    ఎక్కించు(op->reg, &sv);
                } లేకపోతే ఒకవేళ (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    ఎక్కించు(op->reg, op->vt);
                    ఒకవేళ (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } లేకపోతే { // epilog
        /* generate save code */
        కొరకు(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ఒకవేళ (op->reg >= 0) {
                ఒకవేళ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ఒకవేళ (!op->is_జ్ఞాపకం) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        ఎక్కించు(బహిర్గతం_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | బహిర్గతం_reg;
                        store(op->reg, &sv);
                    }
                } లేకపోతే {
                    store(op->reg, op->vt);
                    ఒకవేళ (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        ఒకవేళ (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
స్థిర అంతఃవరుస పూర్ణాంకం constraint_ప్రాధాన్యత(స్థిరరాశి అక్షరం *str)
{
    పూర్ణాంకం ప్రాధాన్యత, c, pr;

    /* we take the lowest priority */
    ప్రాధాన్యత = 0;
    కొరకు(;;) {
        c = *str;
        ఒకవేళ (c == '\0')
            ఆపు;
        str++;
        ఎంపిక(c) {
        స్థితి 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        స్థితి 'r': // register [general]
        స్థితి 'p': // valid memory address for load,store [general]
            pr = 3;
            ఆపు;
        స్థితి 'M': // integer constant for shifts [ARM]
        స్థితి 'I': // integer valid for data processing instruction immediate
        స్థితి 'J': // integer in range -4095...4095

        స్థితి 'i': // immediate integer operand, including symbolic constants [general]
        స్థితి 'm': // memory operand [general]
        స్థితి 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            ఆపు;
        అప్రమేయ:
            tcc_error("unknown constraint '%c'", c);
        }
        ఒకవేళ (pr > ప్రాధాన్యత)
            ప్రాధాన్యత = pr;
    }
    తిరిగి ప్రాధాన్యత;
}

స్థిర స్థిరరాశి అక్షరం *skip_constraint_modifiers(స్థిరరాశి అక్షరం *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    అయితే (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    తిరిగి p;
}

#నిర్వచించు REG_బహిర్గతం_ముసుగు 0x01
#నిర్వచించు REG_లోపల_ముసుగు  0x02

#నిర్వచించు is_reg_allocated(reg) (regs_allocated[reg] & reg_ముసుగు)

ST_FUNC శూన్య asm_compute_constraints(ASMOperand *operands,
                                    పూర్ణాంకం nb_operands, పూర్ణాంకం nb_outputs,
                                    స్థిరరాశి uint8_t *clobber_regs,
                                    పూర్ణాంకం *pout_reg)
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
    పూర్ణాంకం sorted_op[MAX_ASM_OPERANDS];
    పూర్ణాంకం i, j, k, p1, p2, tmp, reg, c, reg_ముసుగు;
    స్థిరరాశి అక్షరం *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    కొరకు (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->ఆదానం_సూచీ = -1;
        op->ref_సూచీ = -1;
        op->reg = -1;
        op->is_జ్ఞాపకం = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    కొరకు (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ఒకవేళ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = కనుగొను_constraint(operands, nb_operands, str, ఖాళీ);
            ఒకవేళ ((గుర్తులేని) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_సూచీ = k;
            ఒకవేళ (operands[k].ఆదానం_సూచీ >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ఆదానం_సూచీ = i;
            op->ప్రాధాన్యత = 5;
        } లేకపోతే ఒకవేళ ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->ప్రాధాన్యత = 1;
            op->reg = reg;
        } లేకపోతే {
            op->ప్రాధాన్యత = constraint_ప్రాధాన్యత(str);
        }
    }

    /* sort operands according to their priority */
    కొరకు (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    కొరకు (i = 0; i < nb_operands - 1; i++) {
        కొరకు (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].ప్రాధాన్యత;
            p2 = operands[sorted_op[j]].ప్రాధాన్యత;
            ఒకవేళ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    కొరకు (i = 0; i < NB_ASM_REGS; i++) {
        ఒకవేళ (clobber_regs[i])
            regs_allocated[i] = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;
        లేకపోతే
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;

    /* allocate registers and generate corresponding asm moves */
    కొరకు (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ఒకవేళ (op->ref_సూచీ >= 0)
            కొనసాగు;
        /* select if register is used for output, input or both */
        ఒకవేళ (op->ఆదానం_సూచీ >= 0) {
            reg_ముసుగు = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;
        } లేకపోతే ఒకవేళ (j < nb_outputs) {
            reg_ముసుగు = REG_బహిర్గతం_ముసుగు;
        } లేకపోతే {
            reg_ముసుగు = REG_లోపల_ముసుగు;
        }
        ఒకవేళ (op->reg >= 0) {
            ఒకవేళ (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_తదుపరి:
        c = *str++;
        ఎంపిక (c) {
        స్థితి '=': // Operand is written-to
            వెళ్ళు try_తదుపరి;
        స్థితి '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        స్థితి '&': // Operand is clobbered before the instruction is done using the input operands
            ఒకవేళ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_ముసుగు = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;
            వెళ్ళు try_తదుపరి;
        స్థితి 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        స్థితి 'r': // general-purpose register
        స్థితి 'p': // loadable/storable address
            /* any general register */
            ఒకవేళ ((reg = op->reg) >= 0)
                వెళ్ళు reg_దొరికింది;
            లేకపోతే కొరకు (reg = 0; reg <= 8; reg++) {
                ఒకవేళ (!is_reg_allocated(reg))
                    వెళ్ళు reg_దొరికింది;
            }
            వెళ్ళు try_తదుపరి;
          reg_దొరికింది:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_ముసుగు;
            ఆపు;
        స్థితి 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        స్థితి 'J': // integer in the range -4095 to 4095 [ARM]
        స్థితి 'K': // integer that satisfies constraint I when inverted (one's complement)
        స్థితి 'L': // integer that satisfies constraint I when inverted (two's complement)
        స్థితి 'i': // immediate integer operand, including symbolic constants
            ఒకవేళ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'M': // integer in the range 0 to 32
            ఒకవేళ (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'm': // memory operand
        స్థితి 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ఒకవేళ (j < nb_outputs || c == 'm') {
                ఒకవేళ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    కొరకు (reg = 0; reg <= 8; reg++) {
                        ఒకవేళ (!(regs_allocated[reg] & REG_లోపల_ముసుగు))
                            వెళ్ళు reg_found1;
                    }
                    వెళ్ళు try_తదుపరి;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_లోపల_ముసుగు;
                    op->reg = reg;
                    op->is_జ్ఞాపకం = 1;
                }
            }
            ఆపు;
        అప్రమేయ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            ఆపు;
        }
        /* if a reference is present for that operand, we assign it too */
        ఒకవేళ (op->ఆదానం_సూచీ >= 0) {
            operands[op->ఆదానం_సూచీ].reg = op->reg;
            operands[op->ఆదానం_సూచీ].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    కొరకు (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ఒకవేళ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_జ్ఞాపకం) {
            కొరకు (reg = 0; reg <= 8; reg++) {
                ఒకవేళ (!(regs_allocated[reg] & REG_బహిర్గతం_ముసుగు))
                    వెళ్ళు reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            ఆపు;
        }
    }

    /* print sorted constraints */
#నిర్వచితమైతే ASM_DEBUG
    కొరకు (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        రాయి("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ఖాళీ) : "",
               op->constraint, op->vt->r, op->reg);
    }
    ఒకవేళ (*pout_reg >= 0)
        రాయి("out_reg=%d\n", *pout_reg);
#అయితే_ముగింపు
}

ST_FUNC శూన్య asm_clobber(uint8_t *clobber_regs, స్థిరరాశి అక్షరం *str)
{
    పూర్ణాంకం reg;
    TokenSym *ts;

    ఒకవేళ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        తిరిగి;
    ts = tok_alloc(str, అక్షరశ్రేణి_పొడవు(str));
    reg = asm_parse_regvar(ts->tok);
    ఒకవేళ (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC పూర్ణాంకం asm_parse_regvar (పూర్ణాంకం t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    ఒకవేళ (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        తిరిగి -1;

    ఒకవేళ (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        తిరిగి t - TOK_ASM_r0;

    ఒకవేళ (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        తిరిగి t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    తిరిగి t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#అయితే_ముగింపు /* ndef TARGET_DEFS_ONLY */
