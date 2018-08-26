/*
 * radio.cpp
 *
 *  Created on: 16 èþë. 2018 ã.
 *      Author: feelt
 */


#include <radio.h>
#include "spi.h"
#include "RF24/RF24.h"
#include <input.h>

RF24 radio(&hspi2);

const uint64_t pipes[2] = { 0xABCDABCD71LL, 0x544d52687CLL };

void Radio_Init(void)
{

	radio.begin();



	radio.setChannel(0x66);

	radio.setPALevel(RF24_PA_MAX);
	radio.setDataRate(RF24_250KBPS);
	radio.setCRCLength(RF24_CRC_8);

	radio.setAutoAck(false);
	//radio.enableAckPayload();                         // We will be using the Ack Payload feature, so please enable it
	//radio.setRetries(0,1);								 // Smallest time between retries, max no. of retries
	radio.setPayloadSize(5);
	//radio.enableDynamicPayloads();

	radio.openWritingPipe(pipes[0]);			//TX
	radio.openReadingPipe(1,pipes[1]);

	printf("RF channel: 0x%x\r\n", radio.getChannel());

	radio.powerUp();

	radio.startListening();
	radio.stopListening();



	printf("Radio Init Done!\r\n");

	HAL_Delay(1000);

	//radio.printDetails();														 // Dump the configuration of the rf unit for debugging

}

void Radio_Send(void)
{
	uint8_t data[5];
	data[0] = Inputs.lx;
	data[1] = Inputs.ly;
	data[2] = Inputs.rx;
	data[3] = Inputs.ry;
	data[4] = Inputs.th;



	if (!radio.write(data, sizeof(data)))
		printf("failed\r\n");

	HAL_Delay(5);
}



