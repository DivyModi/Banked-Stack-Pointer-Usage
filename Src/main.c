/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int fun_add(int a, int b, int c, int d)
{
	return a+b+c+d;
}

__attribute((naked)) void change_sp_to_psp(void)
{
	__asm(".equ Stack_start,(0x20000000 + (96 * 1024))");
	__asm(".equ Stack_PSP_Start,(Stack_start - 512)");
	__asm("LDR R0,=Stack_PSP_Start");
	__asm("MSR PSP, R0");
	__asm("MOV R0, #0x02");
	__asm("MSR CONTROL, R0");
	__asm("BX LR");
}

void generate_exception()
{
	__asm("SVC #0x02");
}

int main(void)
{
	printf("Hello World\n");
	change_sp_to_psp();

	int ret;

	ret = fun_add(1,2,3,4);
	printf("result = %d\r\n", ret);
	generate_exception();
    /* Loop forever */
	for(;;);
}

void SVC_Handler(void)
{
	printf("inside SVC_handler");
}
