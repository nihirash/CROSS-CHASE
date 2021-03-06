#include <peekpoke.h>

#include <nes.h>

#define _RED 6
#define _BROWN 24
#define _WHITE 32
#define _ORANGE 23
#define _GREEN_BROWN 25
#define _CYAN 33
#define _DARK_YELLOW 40
#define _LIGHT_YELLOW 56

/*
void put_char(uint8 x, uint8 y, uint8 c) 
{
    uint16 adr = 0x2000;
    adr = adr + 0x20 * y + x;
    ADDR(0x2006) = adr >> 8;  // high byte
    ADDR(0x2006) = (uint8)adr;   // low byte
    ADDR(0x2007) = c; 
} 
*/

void set_color(unsigned char palette_group, unsigned char color_index, unsigned char color)
{
    PPU.vram.address = 0x3f;
    PPU.vram.address = palette_group * 4 + color_index;   
    PPU.vram.data = color;   
}

//
/*
const unsigned char PALETTE[]={
0x1F, 0x00, 0x20, 0x31, // blues
0x00, 0x00, 0x00, 0x15, // red
0x00, 0x00, 0x00, 0x27, // yellow
0x00, 0x00, 0x00, 0x1a, // green
}; 
// note, 11 is the default background color = blue

const unsigned char Attrib_Table[]={
0x44, // 0100 0100, 
0xbb, // 1011 1011, 
0x44, // 0100 0100, 
0xbb}; // 1011 1011
*/

// 33221100 = 2 bits per attribute area
// 0 1		= their relative position on the screen
// 2 3
// each box is 16x16 pixels

/*
void Load_Palette(void) {
	PPU_ADDRESS = 0x3f;
	PPU_ADDRESS = 0x00;
	for( index = 0; index < sizeof(PALETTE); ++index ){
		PPU_DATA = PALETTE[index];
	}
	PPU_ADDRESS = 0x23;
	PPU_ADDRESS = 0xda;
	for( index = 0; index < sizeof(Attrib_Table); ++index ){
		PPU_DATA = Attrib_Table[index];
	}
}
*/


#define CTRL 0x2000
#define MASK 0x2001
#define SCROLL 0x2005


void All_Off(void) {
	PPU.control = 0;
	PPU.mask = 0;
}
	
void All_On(void) {
	PPU.control = 0x80;
	PPU.mask = 0x1e;
}

void Reset_Scroll(void)
{
	PPU.vram.address = 0;
	PPU.vram.address = 0;
	
	PPU.scroll = 0;
	PPU.scroll = 0;
}


//


void INIT_GRAPHICS(void)
{
	All_Off();

	set_color(0,2,_DARK_YELLOW);
	set_color(0,1,_RED);
	set_color(0,3,_WHITE);

	set_color(1,2,_DARK_YELLOW);
	set_color(1,1,_GREEN_BROWN);
	set_color(1,3,_RED);


	set_color(3,2,_DARK_YELLOW);
	set_color(3,1,_BROWN);
	set_color(3,3,_CYAN);	
	
	{
		unsigned char j;
	
		for(j=0;j<4;++j)
		{	
			PPU.vram.address = 0x23;
			PPU.vram.address = (0xC0+j);				
			PPU.vram.data = 0xFF;//0b00001111;	
		}
		
		for(j=4;j<8;++j)
		{	
			PPU.vram.address = 0x23;
			PPU.vram.address = (0xC0+j);				
			PPU.vram.data = 0x55;//0b00001111;	
		}
					
		PPU.vram.address = 0x23;
		PPU.vram.address = 0xC3;
		PPU.vram.data = 0xF0;			
		
		PPU.vram.address = 0x23;
		PPU.vram.address = 0xC4;
		PPU.vram.data = 0x00;
				
	}	
	
	
	Reset_Scroll();
	All_On();

}

