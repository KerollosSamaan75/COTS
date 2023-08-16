/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 08/08/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



void GPIO_voidSetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Mode)
{
	switch(Copy_u8PORT)
	{
		case GPIOA : 
					switch(Copy_u8Mode)
					{                                               /*Select Pin as Input*/
						case INPUT_FLOATING                       : CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2));     
																	CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
																	
																	/*Select Input Pin as Floating*/
																	CLR_BIT(GPIOA_PUPDR , (Copy_u8PIN * 2)); 
																	CLR_BIT(GPIOA_PUPDR , (Copy_u8PIN * 2 + 1));
																	break;
																	
						                                            /*Select Pin as Input*/
						case INPUT_PULL_UP                        : CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2)); 
																	CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
																	
																	/*Select Input Pin as Pullup*/
																	SET_BIT(GPIOA_PUPDR , (Copy_u8PIN * 2)); 
																	CLR_BIT(GPIOA_PUPDR , (Copy_u8PIN * 2 + 1));
																	break;
																	
																	/*Select Pin as Input*/
						case INPUT_PULL_DOWN                      : CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2)); 
																	CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
																	
																	/*Select Input Pin as Pulldown*/
																	CLR_BIT(GPIOA_PUPDR , (Copy_u8PIN * 2)); 
																	SET_BIT(GPIOA_PUPDR , (Copy_u8PIN * 2 + 1));
																	break;
						
																	/*Select Input Pin as Analog*/
						case INPUT_ANALOG                         : SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2)); 
																	SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
																	break;
																	
																	/*Select Pin as Output*/
						case OUTPUT_PUSH_PULL_LOW_SPEED           : SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2)); 
																	CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
																	
																	/*Select Output Pin as Push Pull*/
																	CLR_BIT(GPIOA_OTYPER,Copy_u8PIN);
																	
																	/*Select Output Pin with Low speed*/
																	CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2)); 
																	CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
																	break;
						
																	
																	/*Select Pin as Output*/
						case OUTPUT_PUSH_PULL_MEDIUM_SPEED        : SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2)); 
						                                            CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
						                                            
						                                            /*Select Output Pin as Push Pull*/
						                                            CLR_BIT(GPIOA_OTYPER,Copy_u8PIN);
						                                            
						                                            /*Select Output Pin with Medium speed*/
						                                            SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2)); 
						                                            CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
						                                            break;
						
						
						
						 
						                                            /*Select Pin as Output*/
						case OUTPUT_PUSH_PULL_HIGH_SPEED          : SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2)); 
						                                            CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
						                                            
						                                            /*Select Output Pin as Push Pull*/
						                                            CLR_BIT(GPIOA_OTYPER,Copy_u8PIN);
						                                            
						                                            /*Select Output Pin with High speed*/
						                                            SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2)); 
						                                            SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
						                                            break;
																	
																	
								                                    /*Select Pin as Output*/										
						case OUTPUT_OPEN_DRAIN_LOW_SPEED          : SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2)); 
						                                            CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
						                                            
						                                            /*Select Output Pin as Open Drain*/
						                                            SET_BIT(GPIOA_OTYPER,Copy_u8PIN);
						                                            
						                                            /*Select Output Pin with Low speed*/
						                                            CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2)); 
						                                            CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
						                                            break;
																	
																	
						
						                                            /*Select Pin as Output*/
						case OUTPUT_OPEN_DRAIN_MEDIUM_SPEED       : SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2)); 
						                                            CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
						                                            
						                                            /*Select Output Pin as Open Drain*/
						                                            SET_BIT(GPIOA_OTYPER,Copy_u8PIN);
						                                            
						                                            /*Select Output Pin with Low speed*/
						                                            CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2)); 
						                                            CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
						                                            break;
																	
						
						                                            /*Select Pin as Output*/
						case OUTPUT_OPEN_DRAIN_HIGH_SPEED         : SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2)); 
						                                            CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
						                                            
						                                            /*Select Output Pin as Open Drain*/
						                                            SET_BIT(GPIOA_OTYPER,Copy_u8PIN);
						                                            
						                                            /*Select Output Pin with High speed*/
						                                            SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2)); 
						                                            SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
						                                            break;
																	
																	
						                                             /*Select Pin as  Alternate function*/						
						case ALTFUNCTION_PUSH_PULL_LOW_SPEED      :  CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2));  
						                                             SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
						                                             
						                                             /*Select Output Pin as Push Pull*/
						                                             CLR_BIT(GPIOA_OTYPER,Copy_u8PIN);
						                                             
						                                             /*Select Output Pin with Low speed*/
						                                             CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2)); 
						                                             CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
																	 break;
																	 
																	 
																	 
																	/*Select Pin as Alternate function*/
						case ALTFUNCTION_PUSH_PULL_MEDIUM_SPEED   : CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2));  
						                                            SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
						                                            
						                                            /*Select Output Pin as Push Pull*/
						                                            CLR_BIT(GPIOA_OTYPER,Copy_u8PIN);
						                                            
						                                            /*Select Output Pin with Medium speed*/
						                                            SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2)); 
						                                            CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
						                                            break;
						
						
						
						                                            /*Select Pin as Alternate function*/
						case ALTFUNCTION_PUSH_PULL_HIGH_SPEED     : CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2)); 
						                                            SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
						                                            
						                                            /*Select Output Pin as Push Pull*/
						                                            CLR_BIT(GPIOA_OTYPER,Copy_u8PIN);
						                                            
						                                            /*Select Output Pin with High speed*/
						                                            SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2)); 
						                                            SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
						                                            break;
						
						
						                                            /*Select Pin as  Alternate function*/			
						case ALTFUNCTION_OPEN_DRAIN_LOW_SPEED     : CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2));  
						                                            SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
						                                            
						                                            /*Select Output Pin as Open Drain*/
						                                            SET_BIT(GPIOA_OTYPER,Copy_u8PIN);
						                                            
						                                            /*Select Output Pin with Low speed*/
						                                            CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2)); 
						                                            CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
						                                            break;
						
						
						
						                                            /*Select Pin as  Alternate function*/			
						case ALTFUNCTION_OPEN_DRAIN_MEDIUM_SPEED  : CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2));  
						                                            SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
						                                            
						                                            /*Select Output Pin as Open Drain*/
						                                            SET_BIT(GPIOA_OTYPER,Copy_u8PIN);
						                                            
						                                            /*Select Output Pin with Medium speed*/
						                                            SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2)); 
						                                            CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
						                                            break;
						
						
						
						                                           /*Select Pin as Alternate function*/
						case ALTFUNCTION_OPEN_DRAIN_HIGH_SPEED    :CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2)); 
						                                           SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
						                                           
						                                           /*Select Output Pin as Open Drain*/
						                                           SET_BIT(GPIOA_OTYPER,Copy_u8PIN);
						                                           
						                                           /*Select Output Pin with High speed*/
						                                           SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2)); 
						                                           SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
						                                           break;
					}
					break;
		
		
		case GPIOB : 
					switch(Copy_u8Mode)
        			{                                               /*Select Pin as Input*/
        				case INPUT_FLOATING                       : CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2));     
        															CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        															
        															/*Select Input Pin as Floating*/
        															CLR_BIT(GPIOB_PUPDR , (Copy_u8PIN * 2)); 
        															CLR_BIT(GPIOB_PUPDR , (Copy_u8PIN * 2 + 1));
        															break;
        															
        				                                            /*Select Pin as Input*/
        				case INPUT_PULL_UP                        : CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2)); 
        															CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        															
        															/*Select Input Pin as Pullup*/
        															SET_BIT(GPIOB_PUPDR , (Copy_u8PIN * 2)); 
        															CLR_BIT(GPIOB_PUPDR , (Copy_u8PIN * 2 + 1));
        															break;
        															
        															/*Select Pin as Input*/
        				case INPUT_PULL_DOWN                      : CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2)); 
        															CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        															
        															/*Select Input Pin as Pulldown*/
        															CLR_BIT(GPIOB_PUPDR , (Copy_u8PIN * 2)); 
        															SET_BIT(GPIOB_PUPDR , (Copy_u8PIN * 2 + 1));
        															break;
        				
        															/*Select Input Pin as Analog*/
        				case INPUT_ANALOG                         : SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2)); 
        															SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        															break;
        															
        															/*Select Pin as Output*/
        				case OUTPUT_PUSH_PULL_LOW_SPEED           : SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2)); 
        															CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        															
        															/*Select Output Pin as Push Pull*/
        															CLR_BIT(GPIOB_OTYPER,Copy_u8PIN);
        															
        															/*Select Output Pin with Low speed*/
        															CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2)); 
        															CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
        															break;
        				
        															
        															/*Select Pin as Output*/
        				case OUTPUT_PUSH_PULL_MEDIUM_SPEED        : SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Push Pull*/
        				                                            CLR_BIT(GPIOB_OTYPER,Copy_u8PIN);
        				                                            
        				                                            /*Select Output Pin with Medium speed*/
        				                                            SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        				
        				
        				                                            /*Select Pin as Output*/
        				case OUTPUT_PUSH_PULL_HIGH_SPEED          : SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Push Pull*/
        				                                            CLR_BIT(GPIOB_OTYPER,Copy_u8PIN);
        				                                            
        				                                            /*Select Output Pin with High speed*/
        				                                            SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        															
        															
        						                                    /*Select Pin as Output*/						
        				case OUTPUT_OPEN_DRAIN_LOW_SPEED          : SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Open Drain*/
        				                                            SET_BIT(GPIOB_OTYPER,Copy_u8PIN);
        				                                            
        				                                            /*Select Output Pin with Low speed*/
        				                                            CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        															
        														
        				                                            /*Select Pin as Output*/
        				case OUTPUT_OPEN_DRAIN_MEDIUM_SPEED       : SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Open Drain*/
        				                                            SET_BIT(GPIOB_OTYPER,Copy_u8PIN);
        				                                            
        				                                            /*Select Output Pin with Low speed*/
        				                                            CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        															
        				
        				                                            /*Select Pin as Output*/
        				case OUTPUT_OPEN_DRAIN_HIGH_SPEED         : SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Open Drain*/
        				                                            SET_BIT(GPIOB_OTYPER,Copy_u8PIN);
        				                                            
        				                                            /*Select Output Pin with High speed*/
        				                                            SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        															
        															
        				                                             /*Select Pin as  Alternate function*/			
        				case ALTFUNCTION_PUSH_PULL_LOW_SPEED      :  CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2));  
        				                                             SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        				                                             
        				                                             /*Select Output Pin as Push Pull*/
        				                                             CLR_BIT(GPIOB_OTYPER,Copy_u8PIN);
        				                                             
        				                                             /*Select Output Pin with Low speed*/
        				                                             CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                             CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1))
        															 break;
        															 
        															 
        															/*Select Pin as Alternate function*/
        				case ALTFUNCTION_PUSH_PULL_MEDIUM_SPEED   : CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2));  
        				                                            SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Push Pull*/
        				                                            CLR_BIT(GPIOB_OTYPER,Copy_u8PIN);
        				                                            
        				                                            /*Select Output Pin with Medium speed*/
        				                                            SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        				
      
        				                                            /*Select Pin as Alternate function*/
        				case ALTFUNCTION_PUSH_PULL_HIGH_SPEED     : CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2)); 
        				                                            SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Push Pull*/
        				                                            CLR_BIT(GPIOB_OTYPER,Copy_u8PIN);
        				                                            
        				                                            /*Select Output Pin with High speed*/
        				                                            SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        				
        				
        				                                            /*Select Pin as  Alternate function*/			
        				case ALTFUNCTION_OPEN_DRAIN_LOW_SPEED     : CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2));  
        				                                            SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Open Drain*/
        				                                            SET_BIT(GPIOB_OTYPER,Copy_u8PIN);
        				                                            
        				                                            /*Select Output Pin with Low speed*/
        				                                            CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        				
        				
        				                                            /*Select Pin as  Alternate function*/			
        				case ALTFUNCTION_OPEN_DRAIN_MEDIUM_SPEED  : CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2));  
        				                                            SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Open Drain*/
        				                                            SET_BIT(GPIOB_OTYPER,Copy_u8PIN);
        				                                            
        				                                            /*Select Output Pin with Medium speed*/
        				                                            SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        				
        				
        				
        				                                           /*Select Pin as Alternate function*/
        				case ALTFUNCTION_OPEN_DRAIN_HIGH_SPEED    :CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2)); 
        				                                           SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
        				                                           
        				                                           /*Select Output Pin as Open Drain*/
        				                                           SET_BIT(GPIOB_OTYPER,Copy_u8PIN);
        				                                           
        				                                           /*Select Output Pin with High speed*/
        				                                           SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                           SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                           break;
        			}
        			break;
					
					
		case GPIOC : 			
					switch(Copy_u8Mode)			
					{                                               /*Select Pin as Input*/			
						case INPUT_FLOATING                       : CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2));     			
																	CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));			
																				
																	/*Select Input Pin as Floating*/			
																	CLR_BIT(GPIOC_PUPDR , (Copy_u8PIN * 2)); 			
																	CLR_BIT(GPIOC_PUPDR , (Copy_u8PIN * 2 + 1));			
																	break;			
																				
						                                            /*Select Pin as Input*/			
						case INPUT_PULL_UP                        : CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2)); 			
																	CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));			
																				
																	/*Select Input Pin as Pullup*/			
																	SET_BIT(GPIOC_PUPDR , (Copy_u8PIN * 2)); 			
																	CLR_BIT(GPIOC_PUPDR , (Copy_u8PIN * 2 + 1));			
																	break;			
																				
																	/*Select Pin as Input*/			
						case INPUT_PULL_DOWN                      : CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2)); 			
																	CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));			
																				
																	/*Select Input Pin as Pulldown*/			
																	CLR_BIT(GPIOC_PUPDR , (Copy_u8PIN * 2)); 			
																	SET_BIT(GPIOC_PUPDR , (Copy_u8PIN * 2 + 1));			
																	break;			
									
																	/*Select Input Pin as Analog*/			
						case INPUT_ANALOG                         : SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2)); 			
																	SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));			
																	break;			
																				
																	/*Select Pin as Output*/			
						case OUTPUT_PUSH_PULL_LOW_SPEED           : SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2)); 			
																	CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));			
																				
																	/*Select Output Pin as Push Pull*/			
																	CLR_BIT(GPIOC_OTYPER,Copy_u8PIN);			
																				
																	/*Select Output Pin with Low speed*/			
																	CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2)); 			
																	CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));			
																	break;			
									
																				
																	/*Select Pin as Output*/			
						case OUTPUT_PUSH_PULL_MEDIUM_SPEED        : SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2)); 			
						                                            CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));			
						                                            			
						                                            /*Select Output Pin as Push Pull*/			
						                                            CLR_BIT(GPIOC_OTYPER,Copy_u8PIN);			
						                                            			
						                                            /*Select Output Pin with Medium speed*/			
						                                            SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2)); 			
						                                            CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));			
						                                            break;			
									
									
									
						 			
						                                            /*Select Pin as Output*/			
						case OUTPUT_PUSH_PULL_HIGH_SPEED          : SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2)); 			
						                                            CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));			
						                                            			
						                                            /*Select Output Pin as Push Pull*/			
						                                            CLR_BIT(GPIOC_OTYPER,Copy_u8PIN);			
						                                            			
						                                            /*Select Output Pin with High speed*/			
						                                            SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2)); 			
						                                            SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));			
						                                            break;			
																				
																				
								                                    /*Select Pin as Output*/									
						case OUTPUT_OPEN_DRAIN_LOW_SPEED          : SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2)); 			
						                                            CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));			
						                                            			
						                                            /*Select Output Pin as Open Drain*/			
						                                            SET_BIT(GPIOC_OTYPER,Copy_u8PIN);			
						                                            			
						                                            /*Select Output Pin with Low speed*/			
						                                            CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2)); 			
						                                            CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));			
						                                            break;			
																				
																				
									
						                                            /*Select Pin as Output*/			
        				case OUTPUT_OPEN_DRAIN_MEDIUM_SPEED       : SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Open Drain*/
        				                                            SET_BIT(GPIOC_OTYPER,Copy_u8PIN);
        				                                            
        				                                            /*Select Output Pin with Low speed*/
        				                                            CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        															
        				
        				                                            /*Select Pin as Output*/
        				case OUTPUT_OPEN_DRAIN_HIGH_SPEED         : SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Open Drain*/
        				                                            SET_BIT(GPIOC_OTYPER,Copy_u8PIN);
        				                                            
        				                                            /*Select Output Pin with High speed*/
        				                                            SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        															
        															
        				                                             /*Select Pin as  Alternate function*/			
        				case ALTFUNCTION_PUSH_PULL_LOW_SPEED      :  CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2));  
        				                                             SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
        				                                             
        				                                             /*Select Output Pin as Push Pull*/
        				                                             CLR_BIT(GPIOC_OTYPER,Copy_u8PIN);
        				                                             
        				                                             /*Select Output Pin with Low speed*/
        				                                             CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                             CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1))
        															 break;
        															 
        															 
        															 
        															/*Select Pin as Alternate function*/
        				case ALTFUNCTION_PUSH_PULL_MEDIUM_SPEED   : CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2));  
        				                                            SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Push Pull*/
        				                                            CLR_BIT(GPIOC_OTYPER,Copy_u8PIN);
        				                                            
        				                                            /*Select Output Pin with Medium speed*/
        				                                            SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        				
        				
        				
        				                                            /*Select Pin as Alternate function*/
        				case ALTFUNCTION_PUSH_PULL_HIGH_SPEED     : CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2)); 
        				                                            SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Push Pull*/
        				                                            CLR_BIT(GPIOC_OTYPER,Copy_u8PIN);
        				                                            
        				                                            /*Select Output Pin with High speed*/
        				                                            SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        				
        				
        				                                            /*Select Pin as  Alternate function*/			
        				case ALTFUNCTION_OPEN_DRAIN_LOW_SPEED     : CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2));  
        				                                            SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Open Drain*/
        				                                            SET_BIT(GPIOC_OTYPER,Copy_u8PIN);
        				                                            
        				                                            /*Select Output Pin with Low speed*/
        				                                            CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        				
        				
        				
        				                                            /*Select Pin as  Alternate function*/			
        				case ALTFUNCTION_OPEN_DRAIN_MEDIUM_SPEED  : CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2));  
        				                                            SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
        				                                            
        				                                            /*Select Output Pin as Open Drain*/
						                                            SET_BIT(GPIOC_OTYPER,Copy_u8PIN);
						                                            
	}   				                                            /*Select Output Pin with Medium speed*/
        				                                            SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                            CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                            break;
        				
        				
        				
        				                                           /*Select Pin as Alternate function*/
        				case ALTFUNCTION_OPEN_DRAIN_HIGH_SPEED    :CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2)); 
        				                                           SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
        				                                           
        				                                           /*Select Output Pin as Open Drain*/
        				                                           SET_BIT(GPIOC_OTYPER,Copy_u8PIN);
        				                                           
        				                                           /*Select Output Pin with High speed*/
        				                                           SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2)); 
        				                                           SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));
        				                                           break;
        			}
                    
        			break;

}


void GPIO_voidSetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Value)
{
	switch(Copy_u8PORT)
	{
		case GPIOA : 
					switch(Copy_u8Value)
					{
						case GPIO_u8_HIGH : SET_BIT(GPIOA_ODR,Copy_u8PIN); break;
						case GPIO_u8_LOW  : CLR_BIT(GPIOA_ODR,Copy_u8PIN); break;

						//case GPIO_u8_HIGH : GPIOA_BSRR = (1 << (Copy_u8PIN));  break;
						//case GPIO_u8_LOW  : GPIOA_BRR  = (1 << (Copy_u8PIN));  break;
					}
					break; 
		
		case GPIOB : 
					switch(Copy_u8Value)
					{
						case GPIO_u8_HIGH : SET_BIT(GPIOB_ODR,Copy_u8PIN); break;
						case GPIO_u8_LOW  : CLR_BIT(GPIOB_ODR,Copy_u8PIN); break;

						//case GPIO_u8_HIGH : GPIOB_BSRR = (1 << (Copy_u8PIN));  break;
						//case GPIO_u8_LOW  : GPIOB_BRR  = (1 << (Copy_u8PIN));  break;
					}
		            break; 
					
		case GPIOC : 
					switch(Copy_u8Value)
					{
						case GPIO_u8_HIGH : SET_BIT(GPIOC_ODR,Copy_u8PIN); break;
						case GPIO_u8_LOW  : CLR_BIT(GPIOC_ODR,Copy_u8PIN); break;

						//case GPIO_u8_HIGH : GPIOC_BSRR = (1 << (Copy_u8PIN));  break;
						//case GPIO_u8_LOW  : GPIOC_BRR  = (1 << (Copy_u8PIN));  break;
					}
		            break; 
	   default :break;
	}
}

u8 GPIO_u8GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	u8 Local_u8PinValue = 0 ;
	
	switch(Copy_u8PORT)
	{
		case GPIOA : Local_u8PinValue = GET_BIT(GPIOA_IDR,Copy_u8PIN); break;
		case GPIOB : Local_u8PinValue = GET_BIT(GPIOB_IDR,Copy_u8PIN); break;
		case GPIOC : Local_u8PinValue = GET_BIT(GPIOC_IDR,Copy_u8PIN); break;
		default :break;
	}
	return Local_u8PinValue;
}
