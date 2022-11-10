/**********************************************************************/
/********            Author  : Islam Battour                   ********/
/********            Layer   : MCAL                           ********/
/********            Version : V01                            *******/
/********            Date    : 28/6/2022                      *******/
/********************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


/*configuratios Macros for group and sub priorities using SCB peripheral (SCB_AIRCR) register*/

#define MNVIC_GROUP_4_SUB_0           0X05FA0300        /*4 group periority 0 sub periority */
#define MNVIC_GROUP_3_SUB_1           0X05FA0400        /*3 group periority 1 sub periority */
#define MNVIC_GROUP_2_SUB_2           0X05FA0500        /*2 group periority 2 sub periority */
#define MNVIC_GROUP_1_SUB_3           0X05FA0600        /*1 group periority 3 sub periority */
#define MNVIC_GROUP_0_SUB_4           0X05FA0700        /*0 group periority 4 sub periority (no nesting)*/





/* 0XE000E100 Base Address for NVIC Peripheral*/

#define NVIC_ISER0         *((u32*)0XE000E100)/*Enable EXternal Interrupts from 0 to 31*/
#define NVIC_ISER1         *((u32*)0XE000E104)/*Enable EXternal Interrupts from 32 to 63*/



#define NVIC_ICER0         *((u32*)0XE000E180)/*Disable EXternal Interrupts from 0 to 31*/
#define NVIC_ICER1         *((u32*)0XE000E184)/*Disable EXternal Interrupts from 32 to 63*/


#define NVIC_ISPR0         *((u32*)0XE000E200)/*Set pendig flag to External Interrupts from 0 to 31*/
#define NVIC_ISPR1         *((u32*)0XE000E204)/*Set pendig flag to External Interrupts from 32 to 63*/



#define NVIC_ICPR0         *((u32*)0XE000E280)/*Clear pendig flag to External Interrupts from 0 to 31*/
#define NVIC_ICPR1         *((u32*)0XE000E284)/*Clear pendig flag to External Interrupts from 32 to 63*/


#define NVIC_IABR0         *((volatile u32*)0XE000E300)/*Read only register contain the Active flag(1=Active 0=InActive) to External Interrupts from 0 to 31*/
#define NVIC_IABR1         *((volatile u32*)0XE000E304)/*Read only register contain the Active flag(1=Active 0=InActive) to External Interrupts from 32 to 63*/

/* 
periority registers from NVIC_IABR0(32bit) to 
NVIC_IABR20(32bit)---> each one contain four 
8bit registers(priority register for EXTI) 
*/

#define NVIC_IPR           ((u8*)0XE000E400)  // in this case NVIC_IPR is a pointer points to this address so we can access any 8 bit register (priority reg for each EXTI) inside the NVIC_IPR from 0 to 80 

/*
casting to u8* pointer because we need the step u8 not u32 so we can access the priority reg for each EXTI

ex:

NVIC_IPR [0]   ----> first U8 register (EXTI0)  OR *(NVIC_IPR)
NVIC_IPR [1]   ----> first U8 register (EXTI1)  or *(NVIC_IPR+1)

*/




#endif
