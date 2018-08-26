/*
 * input.c
 *
 *  Created on: 24 рту. 2018 у.
 *      Author: feelt
 */

#include <input.h>
#include <adc.h>
#include <util.h>

struct Input Inputs;

uint16_t ADC_Data[6];
uint16_t ADC_FData[6];
float F_CO = 0.5;

void Input_Init(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)ADC_FData, 5);
}

void Input_Read(void)
{
	/*for (int i = 0; i < 5; ++i) {
		ADC_FData[i] = ADC_Data[i] * F_CO + ADC_FData[i] * (1 - F_CO);
	}*/

	Inputs.lx = constrain((4096 - ADC_FData[1] - 2048) / 16, -128, 127);
	Inputs.ly = constrain((4096 - ADC_FData[0] - 2048) / 16, -128, 127);
	Inputs.rx = constrain((4096 - ADC_FData[3] - 2048) / 16, -128, 127);
	Inputs.ry = constrain((4096 - ADC_FData[2] - 2048) / 16, -128, 127);
	Inputs.th = constrain((ADC_FData[4]) / 16, 0, 255);

	printf("lx: %i, ly: %i, rx: %i, ry: %i, th: %u\r\n", Inputs.lx, Inputs.ly, Inputs.rx, Inputs.ry, Inputs.th);
}

