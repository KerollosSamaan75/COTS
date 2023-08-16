/*
 * main.c

 *
 *  Created on: Jul 22, 2023
 *      Author: Kerollos
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*MCAL*/
#include "DIO_interface.h"

#include <util/delay.h>
/*HAL*/
#include "MUXSEVENSEG_interface.h"

int main(void)
{

	DIO_voidInit();
	while(1)
	{

		MUXSEVENSEG_voidWriteDigit(SEV_SEGM_1,9);
		MUXSEVENSEG_voidWriteDigit(SEV_SEGM_2,8);
		MUXSEVENSEG_voidWriteDigit(SEV_SEGM_3,7);
		MUXSEVENSEG_voidWriteDigit(SEV_SEGM_4,5);
		//MUXSEVENSEG_voidWriteNumber(12);
	}

	return 0;
}
