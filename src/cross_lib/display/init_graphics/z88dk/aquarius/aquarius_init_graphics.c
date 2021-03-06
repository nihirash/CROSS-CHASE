/* --------------------------------------------------------------------------------------- */ 
// 
// CROSS CHASE by Fabrizio Caruso
//
// Fabrizio_Caruso@hotmail.com
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from
// the use of this software.

// Permission is granted to anyone to use this software for non-commercial applications, 
// subject to the following restrictions:

// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software in
// a product, an acknowledgment in the product documentation would be
// appreciated but is not required.

// 2. Altered source versions must be plainly marked as such, and must not
// be misrepresented as being the original software.

// 3. This notice may not be removed or altered from any source distribution.
/* --------------------------------------------------------------------------------------- */ 

#define _AQUARIUS_RED 16
#define _AQUARIUS_WHITE (16+32+64)
#define _AQUARIUS_CYAN (16+128)

#include "../../../graphics_mode/memory_mapped_graphics.h"

#define POKE(addr,val)     (*(unsigned char*) (addr) = (val))
#define POKEW(addr,val)    (*(unsigned*) (addr) = (val))
#define PEEK(addr)         (*(unsigned char*) (addr))
#define PEEKW(addr) (*(unsigned*) (addr))


void INIT_GRAPHICS(void)
{
	unsigned char i;
	
	POKE(COLOR_ADDR,7);
	
	for(i=0;i<251;++i)
	{
		POKE(COLOR_ADDR+1+i,0+128);
		POKE(COLOR_ADDR+250+i,0+128);
		POKE(COLOR_ADDR+500+i,0+128);
		POKE(COLOR_ADDR+749+i,0+128);
	}	
}

