/*
 * main.c
 *
 *  Created on: May 20, 2023
 *      Author: Kero
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include"LCD_interface.h"
#include"KPD_interface.h"

void helper(void);

u32 num[20];
u8 oper[20];
u8 flag = 0;
u8 number_counter = 0;

int main(void)
{
	u8 Local_u8KeyValue = KPD_u8_KEY_NOT_PRESSED;
	DIO_voidInit();
	LCD_voidInit();

	while(1)
	{
		u8 static operation_counter = 0;
		KPD_u8GetKeyState(&Local_u8KeyValue);
		u8 static flag = 0;
		if(Local_u8KeyValue != KPD_u8_KEY_NOT_PRESSED)
		{
			if(Local_u8KeyValue >= '0' && Local_u8KeyValue <='9')
			{
				num[number_counter] = (num[number_counter]*10 +  (Local_u8KeyValue-'0'));
			}
			else if((Local_u8KeyValue =='+'||Local_u8KeyValue =='-'||Local_u8KeyValue =='*'||Local_u8KeyValue =='/'))
			{
				oper[operation_counter] = Local_u8KeyValue;
				operation_counter++;
				number_counter++;
			}

			else if(Local_u8KeyValue=='=')
			{
				flag = 1;
				helper();
				LCD_u8GoToXY(2,1);
				LCD_voidSendNum(num[0]);

			}

			if(flag!=1)
			{
				LCD_u8GoToXY(1,1);

				for(int i = 0; i<=number_counter;i++)
				{

					LCD_voidSendNum(num[i]);
					LCD_voidSendChar(oper[i]);
				}
			}
		}
	}
	return 0;
}


void helper(void)
{
		s8 index = -1;
		u8 flagg = 0;

		while(number_counter!=0)
		{
			if(flagg==0)
			{
				flagg=1;
				for(int i = 0; i<number_counter;i++)
				{

					if(oper[i]=='/'){
						num[i]=num[i]/num[i+1];
						index = i;

						number_counter--;
						flagg=0;
						break;
					}
					else if(oper[i]=='*')
					{
						num[i]=num[i]*num[i+1];

						index = i;
						number_counter--;
						flagg = 0;
						break;
					}


				}


			}
			else if(flagg==1){
				for(int i = 0; i<number_counter;i++)
				{

					if(oper[i]=='+'){
						num[i]=num[i]+num[i+1];
						index = i;

						number_counter--;

						break;
					}
					else if(oper[i]=='-')
					{
						num[i]=num[i]-num[i+1];

						index = i;
						number_counter--;

						break;
					}


				}

			}

			if(index!= -1 )
			{
				for(int i = index+1; i<=number_counter;i++)
				{
					num[i]= num[i+1];
				}

				for(int j = index; j<number_counter;j++ )
				{
					oper[j]= oper[j+1];
				}

				index = -1;
			}

		}
	}

