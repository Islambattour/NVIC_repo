/**********************************************************************/
/********            Author  : Islam Battour                   ********/
/********            Layer   : MCAL                           ********/
/********            Version : V01                            *******/
/********            Date    : 28/6/2022                      *******/
/********************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"


#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"



/* for configure the group and priorities */
void MNVIC_void_Init(void)
{
	/* define the register here because i will delete the whole function when i develop the SCB driver later*/
#define  SCB_AIRCR  *((u32*)0xE000ED0C)   //0xE000ED00(base address)+0C(offset address)

	SCB_AIRCR= MNVIC_GROUP_SUB_DISTRIBUTION;
}


/*function to set priority*/

void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx, u8 Copy_u8Priority)
{
	if (Copy_u8PeripheralIdx < 60)
	{
		/*setting the priority (group and sub ) in the EXTIREG*/
		NVIC_IPR[Copy_u8PeripheralIdx] = Copy_u8Priority; 
	}
	else
	{
		/*Report error*/
	}
	/*enhancement:user input group priority and subpriority*/
}



void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber<=31) /*Note u8 always >= 0 */

	{
		NVIC_ISER0 = (1<<Copy_u8IntNumber);
	}


	else if (Copy_u8IntNumber<=59)/*when start executing always Copy_u8IntNumber here is >= 32*/

	{
		Copy_u8IntNumber-=32; /*bit number0 in NVIC_ISER1 register represent EXTI number32 */
		NVIC_ISER1 = (1<<Copy_u8IntNumber);
	}

	else
	{
		/*return error   OK/Succssed =0;  NOK/Failed =1 ;*/
	}


}






void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber<=31) /*Note u8 always >= 0 */

	{
		NVIC_ICER0 = (1<<Copy_u8IntNumber);
	}


	else if (Copy_u8IntNumber<=59)/*when start executing always Copy_u8IntNumber here is >= 32*/

	{
		Copy_u8IntNumber-=32; /*bit number0 in NVIC_ISER1 register represent EXTI number32 */
		NVIC_ICER1 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*return error   OK/Succssed =0;  NOK/Failed =1 ;*/
	}
}


void MNVIC_voidSetPendingFlag (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber<=31) /*Note u8 always >= 0 */

	{
		NVIC_ISPR0 = (1<<Copy_u8IntNumber);
	}


	else if (Copy_u8IntNumber<=59)/*when start executing always Copy_u8IntNumber here is >= 32*/

	{
		Copy_u8IntNumber-=32; /*bit number0 in NVIC_ISER1 register represent EXTI number32 */
		NVIC_ISPR1 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*return error   OK/Succssed =0;  NOK/Failed =1 ;*/
	}
}





void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber<=31) /*Note u8 always >= 0 */

	{
		NVIC_ICPR0 = (1<<Copy_u8IntNumber);
	}


	else if (Copy_u8IntNumber<=59)/*when start executing always Copy_u8IntNumber here is >= 32*/

	{
		Copy_u8IntNumber-=32; /*bit number0 in NVIC_ISER1 register represent EXTI number32 */
		NVIC_ICPR1 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*return error   OK/Succssed =0;  NOK/Failed =1 ;*/
	}

}



u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result;

	if ( Copy_u8IntNumber<=31) /*Note u8 always >= 0 */

	{
		Local_u8Result = GET_BIT(NVIC_IABR0 , Copy_u8IntNumber);
	}


	else if (Copy_u8IntNumber<=59)/*when start executing always Copy_u8IntNumber here is >= 32*/

	{
		Copy_u8IntNumber-=32; /*bit number0 in NVIC_ISER1 register represent EXTI number32 */
		Local_u8Result = GET_BIT(NVIC_IABR1 , Copy_u8IntNumber);
	}

	else
	{
		/*return error   OK/Succssed =0;  NOK/Failed =1 ;*/
	}

	return Local_u8Result;


}










