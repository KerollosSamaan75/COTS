/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 03/10/2022      *****/
/********** SWC     : GI              *****/
/********** verison : v-1             *****/
/******************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GI_interface.h"
#include"GI_private.h"
#include"GI_config.h"

void GI_voidEnable(void)
{
	SET_BIT(SREG,7); 
}

void GI_voidDisable(void)
{
	CLR_BIT(SREG,7); 
}