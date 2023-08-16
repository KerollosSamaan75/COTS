/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 22/11/2022      *****/
/********** SWC     : SPI             *****/
/********** verison : v-1             *****/
/******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void SPI_voidInit(void)
{
	#if   (SPI_u8_Mood == SPI_u8_MASTE_MOOD)
		
		  /*Select Master Mood*/
	      SET_BIT(SPI_u8_SPCR_REG , 4);
		  
		  /*Data Order-->MSB First*/
	      CLR_BIT(SPI_u8_SPCR_REG , 5);
		  
		  /*Select Clock = F\64*/
	      SET_BIT(SPI_u8_SPCR_REG , 1);
	      CLR_BIT(SPI_u8_SPCR_REG , 0);
		  
		  /*Choose Clock Polarity And Clock Phase -->Falling Edge,Raising Edge,Setup,Sampling*/
	      SET_BIT(SPI_u8_SPCR_REG , 3);
	      SET_BIT(SPI_u8_SPCR_REG , 2);
		  
		  /*Enable SPI*/
	      SET_BIT(SPI_u8_SPCR_REG , 6);
		  
	#elif (SPI_u8_Mood == SPI_u8_SLAVE_MOOD)
		   /*Select Slave Mood*/
	       CLR_BIT(SPI_u8_SPCR_REG , 4);
		   
		   /*Data Order-->MSB First*/
	       CLR_BIT(SPI_u8_SPCR_REG , 5);
		   
		   /*Choose Clock Polarity And Clock Phase -->Falling Edge,Raising Edge,Setup,Sampling*/
	       SET_BIT(SPI_u8_SPCR_REG , 3);
	       SET_BIT(SPI_u8_SPCR_REG , 2);
		   
		   /*Enable SPI*/
	       SET_BIT(SPI_u8_SPCR_REG , 6);
		   
	#endif
}

u8   SPI_u8TransRecieve(u8 Copy_u8TransByte , u8*Copy_pu8RecieveByte)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if( Copy_pu8RecieveByte != NULL)
	{
		/*Send Byte*/
		SPI_u8_SPDR_REG = Copy_u8TransByte;
		/*Check If The Transmission is Completed*/
		while((GET_BIT(SPI_u8_SPSR_REG,7)) == 0);
		/*Read Data*/
		*Copy_pu8RecieveByte = SPI_u8_SPDR_REG;
		 
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;	
}

void SPI_voidSendSlaveByte  (u8 Copy_u8TransByte)
{
	SPI_u8_SPDR_REG = Copy_u8TransByte;
}

u8 SPI_u8RecieveByte   (u8*Copy_pu8RecieveByte)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if( Copy_pu8RecieveByte != NULL)
	{
		/*Check If The Transmission is Completed*/
		while((GET_BIT(SPI_u8_SPSR_REG,7)) == 0);
		/*Read Data*/
		*Copy_pu8RecieveByte = SPI_u8_SPDR_REG;
		 
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}