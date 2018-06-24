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

#include <string.h>

#include "../../cross_lib.h"

#include "../../../display/display_macros.h"

#if !defined(CLIB_ANSI)
	#include<arch/zx.h>
#endif

extern Image PLAYER_IMAGE;
extern Image GHOST_IMAGE;
extern Image DEAD_GHOST_IMAGE;
extern Image BOMB_IMAGE;
extern Image FREEZE_IMAGE;

#if !defined(TINY_GAME)
	extern Image SKULL_IMAGE;
	extern Image POWERUP_IMAGE;
	extern Image BULLET_IMAGE;
	extern Image GUN_IMAGE;
#endif

#if defined(REDEFINED_CHARS)
	extern char udg[];
#endif
	
#if defined(FULL_GAME)
	extern Image LEFT_HORIZONTAL_MISSILE_IMAGE;
	extern Image RIGHT_HORIZONTAL_MISSILE_IMAGE;

	extern Image ROCKET_IMAGE;

	extern Image EXTRA_POINTS_IMAGE;
	extern Image EXTRA_LIFE_IMAGE;
	extern Image INVINCIBILITY_IMAGE;
	extern Image CHASE_IMAGE;
	extern Image SUPER_IMAGE;
	extern Image CONFUSE_IMAGE;
	extern Image ZOMBIE_IMAGE;
	
	extern Image BROKEN_WALL_IMAGE;
#endif

	
#if defined(REDEFINED_CHARS)
	Image PLAYER_DOWN;
	Image PLAYER_UP;
	Image PLAYER_RIGHT;
	Image PLAYER_LEFT;
#endif

#include <stdio.h>

#if defined(CLIB_ANSI)
	#include <graphics.h>

	#include <spectrum.h>
#endif
	

#define POKE(addr,val)     (*(unsigned char*) (addr) = (val))
#define POKEW(addr,val)    (*(unsigned*) (addr) = (val))
#define PEEK(addr)         (*(unsigned char*) (addr))
#define PEEKW(addr) (*(unsigned*) (addr))

#if defined(REDEFINED_CHARS)
struct redefine_struct
{
   unsigned char ascii;
   unsigned char bitmap[8];
} ;
#endif

// BLUE
#define _PLAYER 0x3B
#define _PLAYER_DOWN 0x3B
#define _PLAYER_UP 0x3C
#define _PLAYER_RIGHT 0x3D 
#define _PLAYER_LEFT 0x3E

#define _GUN 0x3F

// YELLOW
#define _SKULL 0x27
#define _VERTICAL_BRICK 0x26
#define _HORIZONTAL_BRICK 0x2B
#define _EXTRA_LIFE 0x25
#define _EXTRA_POINTS 0x24

// GREEN
#define _POWERUP  0x2C

// RED
#define _BOMB 0x5E
#define _DEAD_GHOST 0x5B
// #define _BULLET 0x5F

// CYAN
#define _INVINCIBILITY 0x21
#define _BULLET 0x23

// WHITE
#define _GHOST 0x7E

#define _LEFT_HORIZONTAL_MISSILE ((unsigned char)0x7B)
#define _RIGHT_HORIZONTAL_MISSILE ((unsigned char)0x7D)
#define _ROCKET ((unsigned char)0x60)

#if defined(REDEFINED_CHARS)
struct redefine_struct redefine_map[] =
{
	{_PLAYER_DOWN, { 24, 36, 24,102,153, 24, 36,102}},
	{_PLAYER_UP, { 24, 60, 24,102,153, 24, 36,102}},
	{_PLAYER_RIGHT, { 24, 52, 25,118,152, 24, 20, 20}},	
	{_PLAYER_LEFT, { 24, 44,152,110, 25, 24, 40, 40}},
	{_GHOST, {129,126,165,129,129,189,129,126}},
	{_BOMB, { 60, 66,165,153,153,165, 66, 60}},
	
	#if defined(FULL_GAME)
	{_RIGHT_HORIZONTAL_MISSILE, {  0,  0, 15,252,252, 15,  0,  0}},
	{_LEFT_HORIZONTAL_MISSILE, {  0,  0,240, 63, 63,240,  0,  0}},
	#endif
	
	#if !defined(TINY_GAME)
	{_SKULL, { 60, 66,165,129, 90, 36, 36, 60}},
	{_GUN, {  0,128,126,200,248,192,128,  0}},
	{_POWERUP, {  0, 60, 54,223,231,122, 36, 24}},
	{_BULLET, {  0,  0,  8, 56, 28, 16,  0,  0}},
	{_ROCKET, { 24, 60, 60, 60,126, 90, 66, 66}},
	{_INVINCIBILITY, { 24, 36, 24,  0,153,  0, 36,102}},
	{_VERTICAL_BRICK, { 24, 24, 24, 48, 24, 12, 24, 24}},
	{_HORIZONTAL_BRICK, {  0,  0,  0,255,  0,  0,  0,  0}}		
	#endif
};
#endif

#if !defined(TINY_GAME)
	void INIT_GRAPHICS(void)
	{
		#if defined(REDEFINED_CHARS)
			unsigned char i;
			for (i = 0; i < sizeof(redefine_map) / sizeof(*redefine_map); ++i)
			{
			   memcpy(udg + (redefine_map[i].ascii - 32)*8, redefine_map[i].bitmap, 8);
			}
		#endif

		#if defined(CLIB_ANSI)
			clg();
			zx_border(0);
			zx_colour(PAPER_BLACK|INK_WHITE);
			textbackground(COLOR_BLACK);
		#else
			zx_border(INK_BLACK);
		#endif
	}
#else
	void INIT_GRAPHICS(void)
	{
		printf("\x11%c",COLOR_BLACK);		
	}	
#endif

void INIT_IMAGES(void)
{		

	#if defined(COLOR)
		#if !defined(REDEFINED_CHARS)
		PLAYER_IMAGE._color = COLOR_CYAN;
		#endif
		BOMB_IMAGE._color = COLOR_RED;
		#if !defined(NO_DEAD_GHOST)
		DEAD_GHOST_IMAGE._color = COLOR_RED;
		#endif
		
		#if !defined(TINY_GAME)
			SKULL_IMAGE._color = COLOR_YELLOW;
			POWERUP_IMAGE._color = COLOR_GREEN;
			FREEZE_IMAGE._color = COLOR_CYAN;			
			GUN_IMAGE._color = COLOR_MAGENTA;
		#endif
	#endif
	
	#if defined(FULL_GAME)
		EXTRA_POINTS_IMAGE._color = COLOR_YELLOW;
		EXTRA_LIFE_IMAGE._color = COLOR_YELLOW;
		INVINCIBILITY_IMAGE._color = COLOR_RED;	
		SUPER_IMAGE._color = COLOR_RED;
		CHASE_IMAGE._color = COLOR_WHITE;
		CONFUSE_IMAGE._color = COLOR_RED;
		ZOMBIE_IMAGE._color = COLOR_YELLOW;
	#endif
		
	#if defined(REDEFINED_CHARS)	
		PLAYER_DOWN._imageData = _PLAYER_DOWN;
		PLAYER_UP._imageData = _PLAYER_UP;		
		PLAYER_RIGHT._imageData = _PLAYER_RIGHT;
		PLAYER_LEFT._imageData = _PLAYER_LEFT;	
		
		GHOST_IMAGE._imageData = _GHOST;
		BOMB_IMAGE._imageData = _BOMB;		

		#if !defined(TINY_GAME)
		SKULL_IMAGE._imageData = _SKULL;
		POWERUP_IMAGE._imageData = _POWERUP;
		FREEZE_IMAGE._imageData = _POWERUP; 		
		GUN_IMAGE._imageData = _GUN;
		BULLET_IMAGE._imageData = _BULLET;
		#endif
		
		#if defined(FULL_GAME)
			LEFT_HORIZONTAL_MISSILE_IMAGE._imageData = _LEFT_HORIZONTAL_MISSILE;
			RIGHT_HORIZONTAL_MISSILE_IMAGE._imageData = _RIGHT_HORIZONTAL_MISSILE;		
			ROCKET_IMAGE._imageData = _ROCKET;
			INVINCIBILITY_IMAGE._imageData = _INVINCIBILITY;
			CHASE_IMAGE._imageData = _BULLET;
			SUPER_IMAGE._imageData = _POWERUP;
			CONFUSE_IMAGE._imageData = _SKULL;
			ZOMBIE_IMAGE._imageData = _GHOST;
		#endif
	#else
		GHOST_IMAGE._imageData = 'o';
		BOMB_IMAGE._imageData = 'X';
		PLAYER_IMAGE._imageData = '*';
		
		#if !defined(TINY_GAME)
			SKULL_IMAGE._imageData = '+';
			POWERUP_IMAGE._imageData = 'S';
			GUN_IMAGE._imageData = '!';
			BULLET_IMAGE._imageData = '.';
		#endif
		#if defined(FULL_GAME)
			LEFT_HORIZONTAL_MISSILE_IMAGE._imageData = '>';
			RIGHT_HORIZONTAL_MISSILE_IMAGE._imageData = '<';
			ROCKET_IMAGE._imageData = '^';
		#endif	
	#endif
	
	#if !defined(NO_DEAD_GHOST)
	DEAD_GHOST_IMAGE._imageData = GHOST_IMAGE._imageData;
	#endif
	
	#if defined(COLOR)
		GHOST_IMAGE._color = COLOR_WHITE;
		
		#if !defined(TINY_GAME)
			BULLET_IMAGE._color = COLOR_WHITE;
		#endif
	#endif
	
	#if defined(FULL_GAME)
		LEFT_HORIZONTAL_MISSILE_IMAGE._color = COLOR_WHITE;
		RIGHT_HORIZONTAL_MISSILE_IMAGE._color = COLOR_WHITE;	
		
		ROCKET_IMAGE._color = COLOR_WHITE;
		EXTRA_POINTS_IMAGE._imageData = '$';
		#if !defined(REDEFINED_CHARS)
		EXTRA_LIFE_IMAGE._imageData = PLAYER_IMAGE._imageData;
		#else
		EXTRA_LIFE_IMAGE._imageData = PLAYER_DOWN._imageData;
		#endif
		INVINCIBILITY_IMAGE._imageData = '!';
	#endif
	
	#if defined(REDEFINED_CHARS)
		PLAYER_DOWN._color = COLOR_CYAN;
		PLAYER_UP._color = COLOR_CYAN;		
		PLAYER_RIGHT._color = COLOR_CYAN;
		PLAYER_LEFT._color = COLOR_CYAN;
	#endif
}

#if defined(FULL_GAME)	
	void DRAW_BROKEN_WALL(unsigned char x, unsigned char y)
	{
		_draw(x,y,&BOMB_IMAGE);
	}
#endif

void _draw(unsigned char x, unsigned char y, Image * image) 
{
	gotoxy((x+X_OFFSET),(y+Y_OFFSET)); 
	#if defined(COLOR)
		SET_TEXT_COLOR(image->_color);
	#else
		SET_TEXT_COLOR(COLOR_WHITE);		
	#endif
	cputc(image->_imageData); 
}

void _delete(unsigned char x, unsigned char y)
{
	gotoxy(x+X_OFFSET,y+Y_OFFSET);
	cputc(' ');
}

#if !defined(NO_BLINKING)
void _blink_draw(unsigned char x, unsigned char y, Image * image, unsigned char *blinkCounter) 
{
	gotoxy((x+X_OFFSET),(y+Y_OFFSET)); 
	#if defined(COLOR)
		SET_TEXT_COLOR(image->_color);
	#endif
	if(*blinkCounter) 
	{
		cputc(image->_imageData); 
		*blinkCounter=0;
	} 
	else 
	{
		cputc(' '); 
		*blinkCounter=1;
	}	
}
#endif

#if !defined(TINY_GAME)
	void DRAW_HORIZONTAL_LINE(unsigned char x, unsigned char y, unsigned char length) 
	{ 
		unsigned char i; 
		
		SET_TEXT_COLOR(COLOR_YELLOW);
		for(i=0;i<length;++i) 
		{ 
			gotoxy(x+X_OFFSET+i,y+Y_OFFSET);  putchar(_HORIZONTAL_BRICK); 
		} 
	}


	void DRAW_VERTICAL_LINE(unsigned char x, unsigned char y, unsigned char length) 
	{ 
		unsigned char i; 
		
		SET_TEXT_COLOR(COLOR_YELLOW);
		for(i=0;i<length;++i) 
		{ 
			gotoxy(x+X_OFFSET,y+Y_OFFSET+i);  putchar(_VERTICAL_BRICK); 
		} 
	}
#endif


