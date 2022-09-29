#include "IntCtrl.h"
#include "Port.h"
#include "Dio.h"
int main (void){
	Port_ConfigType config,config1;
	IntCrtl_Init();
	config.directionType=OUTPUT;
	config.gpioPort=Port_GPIOF;
	config.internalAttachType=PULLDOWN;
	config.modeType=DIGITAL;
	config.outputCurrentType=DRV8;
	config.pinType=PIN3;
	Port_Init(&config);
	
	config1.directionType=INPUT;
	config1.gpioPort=Port_GPIOF;
	config1.internalAttachType=PULLUP;
	config1.modeType=DIGITAL;
	config1.outputCurrentType=DRV8;
	config1.pinType=PIN4;
	Port_Init(&config1);
uint32 x=0;
	while(1){	
  	Dio_WritePort(Dio_GPIOF,255);
		Dio_WriteChannel(PF3, HIGH);
		x=Dio_ReadChannel(PF4);
		x=Dio_ReadPort(Dio_GPIOF);
	  for(int i =0;i<1000;i++);
	  Dio_WriteChannel(PF3,LOW);
		for(int i =0;i<1000;i++);
	}
}
