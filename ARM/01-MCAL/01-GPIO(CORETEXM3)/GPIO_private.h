/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 08/08/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS          0x40010800
#define GPIOB_BASE_ADDRESS          0x40010C00
#define GPIOC_BASE_ADDRESS          0x40011000

/*RIGISTER ADDRESSES FOR PORTA*/
#define  GPIOA_CRL          *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x00))
#define  GPIOA_CRH          *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x04))
#define  GPIOA_IDR          *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x08))
#define  GPIOA_ODR          *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x0C))
#define  GPIOA_BSR          *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x10))
#define  GPIOA_BRR          *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x14))
#define  GPIOA_LCK          *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x18))


/*RIGISTER ADDRESSES FOR PORTB*/
#define  GPIOB_CRL          *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x00))
#define  GPIOB_CRH          *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x04))
#define  GPIOB_IDR          *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x08))
#define  GPIOB_ODR          *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x0C))
#define  GPIOB_BSR          *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x10))
#define  GPIOB_BRR          *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x14))
#define  GPIOB_LCK          *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x18))


/*RIGISTER ADDRESSES FOR PORTC*/
#define  GPIOC_CRL          *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x00))
#define  GPIOC_CRH          *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x04))
#define  GPIOC_IDR          *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x08))
#define  GPIOC_ODR          *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x0C))
#define  GPIOC_BSR          *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x10))
#define  GPIOC_BRR          *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x14))
#define  GPIOC_LCK          *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x18))


#define  INTIAL_INPUT_ANALOG                           0000
#define  INTIAL_INPUT_FLOATING                         0100
#define  INTIAL_INPUT_PULL_UP_DOWN                     1000


#define  INTIAL_OUTPUT_SPEED_10MHZ_PUSH_PULL           0001
#define  INTIAL_OUTPUT_SPEED_10MHZ_OPEN_DRAIN          0101
#define  INTIAL_OUTPUT_SPEED_10MHZ_AF_PUSH_PULL        1001
#define  INTIAL_OUTPUT_SPEED_10MHZ_AF_OPEN_DRAIN       1101


#define  INTIAL_OUTPUT_SPEED_2MHZ_PUSH_PULL            0010
#define  INTIAL_OUTPUT_SPEED_2MHZ_OPEN_DRAIN           0110
#define  INTIAL_OUTPUT_SPEED_2MHZ_AF_PUSH_PULL         1010
#define  INTIAL_OUTPUT_SPEED_2MHZ_AF_OPEN_DRAIN        1110
		
		
#define  INTIAL_OUTPUT_SPEED_50MHZ_PUSH_PULL           0011
#define  INTIAL_OUTPUT_SPEED_50MHZ_OPEN_DRAIN          0111
#define  INTIAL_OUTPUT_SPEED_50MHZ_AF_PUSH_PULL        1011
#define  INTIAL_OUTPUT_SPEED_50MHZ_AF_OPEN_DRAIN       1111

#define  CONC(B7,B6,B5,B4,B3,B2,B1,B0)               HELP_CONC(B7,B6,B5,B4,B3,B2,B1,B0)
#define  HELP_CONC(B7,B6,B5,B4,B3,B2,B1,B0)          0b##B7##B6##B5##B4##B3##B2##B1##B0 

#endif 
