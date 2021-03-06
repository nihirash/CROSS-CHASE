
#include "sid_sounds.h"

void _set_noise(void)
{
	SID.v3.ad    = 0x00; 
	SID.v3.sr    = 0xA8; 
	SID.flt_ctrl = 0x44; 
	SID.amp      = 0x1F; 
	SID.v3.ctrl  = 0x81; 	
}

void _short_sound(void)
{
	unsigned short i;
	
	SID.v3.freq  = 0x2000; 
	SID.v3.ad    = 0x00; 
	SID.v3.sr    = 0xC8; 
	SID.flt_ctrl = 0x44; 
	SID.amp      = 0x1F; 
	SID.v3.ctrl  = 0x21; 	

	for(i=0;i<200;++i) {} 
	SID.amp      = 0x00; 
	SID.v3.ctrl  = 0x08; 	
}

void SHOOT_SOUND(void) 
{ 
	unsigned short i; 
	
	SID.v3.freq  = 0x3000; 
	SID.flt_freq = 0x9000; 

	_set_noise();
	
	for(i=0;i<800;++i) {} 
	SID.amp      = 0x00; 
	SID.v3.ctrl  = 0x08; 
};	
	

void EXPLOSION_SOUND(void)
{ 
	unsigned short i; 
	unsigned short j; 
	
	SID.v3.freq  = 0x1200; 
	SID.flt_freq = 0x2000; 

	_set_noise();
	
	for(i=0;i<300;++i) 
		{ 
		} 
	for(j=0;j<15;++j) 
	{ 
		SID.amp      = 0x1F - j; 
		for(i=0;i<100;++i) 
		{ 
		} 
	} 
	SID.amp      = 0x00; 
	SID.v3.ctrl  = 0x08; 
};


void PING_SOUND(void)
{ 
	SID.flt_freq = 0x3500; 
	_short_sound();
};


void TICK_SOUND(void) 
{ 
	SID.flt_freq = 0x2000; 
	_short_sound();
};

void TOCK_SOUND(void) 
{
	SID.flt_freq = 0x1000; 
	_short_sound();
};

void ZAP_SOUND(void) 
{ 
	unsigned char i;
	unsigned char j;
	
	SID.v3.freq  = 0x6800; 
	SID.v3.ad    = 0x88; 
	SID.v3.sr    = 0xC8; 
	SID.flt_freq = 0x5000; 
	SID.flt_ctrl = 0x44; 
	SID.amp      = 0x1F; 
	SID.v3.ctrl  = 0x21; 
	
	for(i=0;i<253;++i) 
	{ 
		SID.v3.freq+=8;
		for(j=0;j<25;++j){};
	}; 

	SID.amp      = 0x00; 
	SID.v3.ctrl  = 0x08; 
};

