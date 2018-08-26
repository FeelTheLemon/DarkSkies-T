/*
 * input.h
 *
 *  Created on: 24 ���. 2018 �.
 *      Author: feelt
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdint.h>

void Input_Init(void);
void Input_Read(void);

struct Input
{
	int8_t lx;
	int8_t ly;
	int8_t rx;
	int8_t ry;
	uint8_t th;
};

extern struct Input Inputs;

#endif /* INPUT_H_ */
