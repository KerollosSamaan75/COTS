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
		  SET_BIT(SPI_u8_SPCR_REG , MASTR);

		  /*Data Order-->MSB First*/
		  CLR_BIT(SPI_u8_SPCR_REG , DORD);

		  /*Select Clock = F\64*/
		  SET_BIT(SPI_u8_SPCR_REG , SPR1);
		  CLR_BIT(SPI_u8_SPCR_REG , SPR0);

		  /*Choose Clock Polarity And Clock Phase --> Raising Edge,Falling Edge,Sampling,Setup*/
		  CLR_BIT(SPI_u8_SPCR_REG , CPOL);
		  CLR_BIT(SPI_u8_SPCR_REG , CPHA);

		  /*Enable SPI*/
		  SET_BIT(SPI_u8_SPCR_REG , SPE);

	#elif (SPI_u8_Mood == SPI_u8_SLAVE_MOOD)
		   /*Select Slave Mood*/
		   CLR_BIT(SPI_u8_SPCR_REG , MASTR);

		   /*Data Order-->MSB First*/
		   CLR_BIT(SPI_u8_SPCR_REG , DORD);

		   /*Choose Clock Polarity And Clock Phase --> Raising Edge,Falling Edge,Sampling,Setup*/
		   CLR_BIT(SPI_u8_SPCR_REG , CPOL);
		   CLR_BIT(SPI_u8_SPCR_REG , CPHA);

		   /*Enable SPI*/
		   SET_BIT(SPI_u8_SPCR_REG , SPE);

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
		while((GET_BIT(SPI_u8_SPSR_REG,SPIF)) == 0);
		
		/*Read Data*/
		*Copy_pu8RecieveByte = SPI_u8_SPDR_REG;
		 
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;	
}

void SPI_voidSendSlaveByte  (u8 Copy_u8TransByte)
{
	SPI_u8_SPDR_REG = Copy_u8TransByte;
	while((GET_BIT(SPI_u8_SPSR_REG,SPIF)) == 0);
}

u8 SPI_u8RecieveByte   (u8*Copy_pu8RecieveByte)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if( Copy_pu8RecieveByte != NULL)
	{
		/*Check If The Transmission is Completed*/
		while((GET_BIT(SPI_u8_SPSR_REG,SPIF)) == 0);

		/*Read Data*/
		*Copy_pu8RecieveByte = SPI_u8_SPDR_REG;
		 
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}
