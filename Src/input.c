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

uint16_t ADC_Data[12];
uint16_t ADC_FData[6];
float F_CO = 0.5;

void Input_Init(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)ADC_Data, 6);
}

void Input_Read(void)
{
	F_CO = map((float)(4096 - ADC_Data[5]), 0.0, 4096.0, 0.5, 0.95);

	for (int i = 0; i < 5; ++i) {
		ADC_FData[i] = ADC_FData[i] * F_CO + ADC_Data[i] * (1 - F_CO);
	}

	Inputs.lx = constrain((ADC_FData[1] - 2048) / 16, -128, 127);
	Inputs.ly = constrain((ADC_FData[0] - 2048) / 16, -128, 127);
	Inputs.rx = constrain((ADC_FData[3] - 2048) / 16, -128, 127);
	Inputs.ry = constrain((ADC_FData[2] - 2048) / 16, -128, 127);
	Inputs.th = constrain((ADC_Data[4]) / 16, 0, 255);

	//printf("lx: %i, ly: %i, rx: %i, ry: %i, th: %u\r\n", ADC_FData[1], ADC_FData[0], ADC_FData[3], ADC_FData[2], ADC_FData[4]);
	printf("lx: %i, ly: %i, rx: %i, ry: %i, th: %u, F_CO: %.2f\r\n", Inputs.lx, Inputs.ly, Inputs.rx, Inputs.ry, Inputs.th, F_CO);
}

