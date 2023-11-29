/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "rcc.h"
#include "dio.h"
#include "Task.h"

void func1(void)
{
	DIO_writePin( PORTA_ID , PIN5_ID , LOGIC_HIGH );
}
void func2(void)
{
	DIO_writePin( PORTA_ID , PIN5_ID , LOGIC_LOW );
}

int main(void)
{
	rcc_setSystemClk(HSI);
	rcc_enablePeriClk(AHB,IOPA_EN);
	DIO_setupPinMode( PORTA_ID , PIN5_ID , PIN_OUTPUT ); // Internal Led
	DIO_writePin( PORTA_ID , PIN5_ID , LOGIC_LOW );

	Task_t task1;
	task1.offset = 0 ;
	task1.periodicity = 1000;
	task1.periority = 0;
	task1.state = Ready;
	task1.f_ptr = func1;

	Task_t task2;
	task2.offset = 500 ;
	task2.periodicity = 1000;
	task2.periority = 1;
	task2.state = Ready;
	task2.f_ptr = func2;




	Task_t * temp1 = Create_Task(task1);
	Task_t * temp2 = Create_Task(task2);


	Os_Start();

    /* Loop forever */
	for(;;);
}