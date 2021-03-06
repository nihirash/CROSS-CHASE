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

#include <conio.h>
#include <peekpoke.h>
#include <atari5200.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "setcolor.h"

#include "../../../graphics_settings.h"

#include "../../../graphics_data/8x8_chars.h"

#define GRAPHICS_MODE (1+16)

#include "../../../redefine_characters/udg_map.h"	

// TODO: BOGUS
// #define _FONT_START__ (unsigned char *) 0xF800
// export (unsigned char *) _FONT_START__;

void set_udg(void)
{
	extern char _FONT_START__[];
	
	unsigned char *CHBASE = (unsigned char *)0xD409;

	memcpy(_FONT_START__, (void *)0xF800, 512);
	
	REDEFINE_AT(_FONT_START__);
	
	*CHBASE = ((int)_FONT_START__ >> 8);  	
}
 
void INIT_GRAPHICS(void)
{
	
	POKE(COLOR0,TGI_COLOR_RED);
	POKE(COLOR1,TGI_COLOR_WHITE);
	POKE(COLOR2,TGI_COLOR_CYAN);
	POKE(COLOR3,TGI_COLOR_BROWN);
	POKE(COLOR4,TGI_COLOR_BLACK);
	
	set_udg();
}


