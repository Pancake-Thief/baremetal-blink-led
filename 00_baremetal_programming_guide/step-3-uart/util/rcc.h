#ifndef _RCC_H
#define _RCC_H

#include <stdint.h>

#define RCC ((rcc_reg_map_t *) 0x40023800)

typedef volatile struct rcc_reg_map_t
{
    uint32_t CR;
    uint32_t PLLCFGR;
    uint32_t CFGR;
    uint32_t CIR;
    uint32_t AHB1RSTR;
    uint32_t AHB2RSTR;
    uint32_t padding_1[2];
    uint32_t APB1RSTR;
    uint32_t APB2RSTR;
    uint32_t padding_2[2];
    uint32_t AHB1ENR;
    uint32_t AHB2ENR;
    uint32_t padding_3[2];
    uint32_t APB1ENR;
    uint32_t APB2ENR;
    uint32_t padding_4[2];
    uint32_t AHB1LPENR;
    uint32_t AHB2LPENR;
    uint32_t padding_5[2];
    uint32_t APB1LPENR;
    uint32_t APB2LPENR;    
    uint32_t padding_6[2];
    uint32_t BDCR;
    uint32_t CSR;
    uint32_t padding_7[2];
    uint32_t SSCGR;
    uint32_t PLLI2SCFGR;
    uint32_t DCKCFGR;
} rcc_reg_map_t;

#endif