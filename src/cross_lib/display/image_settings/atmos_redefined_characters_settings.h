
#define _INVERTED 128u

#if !defined(ANIMATE_PLAYER)
	#define _PLAYER_OFFSET 0x5c
	#define _PLAYER  0x5c
#else		
	#define _PLAYER_LEFT_OFFSET '*'
	#define _PLAYER_RIGHT_OFFSET ','
	#define _PLAYER_UP_OFFSET '.'
	#define _PLAYER_DOWN_OFFSET '/'	
	
	#define _PLAYER_LEFT '*'
	#define _PLAYER_RIGHT ','
	#define _PLAYER_UP '.'
	#define _PLAYER_DOWN '/'		
#endif
	
#define _GHOST_OFFSET 0x60
#define _SKULL_OFFSET 0x7b
#define _BOMB_OFFSET 0x5b
#define _POWERUP_OFFSET 0x5d
#define _GUN_OFFSET 0x5e
#define _BULLET_OFFSET 0x5f	
	
#define _GHOST _GHOST_OFFSET
#define _SKULL _SKULL_OFFSET
#define _BOMB (_BOMB_OFFSET + _INVERTED)
#define _POWERUP ( _POWERUP_OFFSET + _INVERTED)
#define _GUN (_GUN_OFFSET + _INVERTED)
#define _EXTRA_POINTS '$'
	
#define _BULLET _BULLET_OFFSET

#if !defined(NO_DEAD_GHOST)
	#define _DEAD_GHOST_OFFSET 0x5a
	#define _DEAD_GHOST (_DEAD_GHOST_OFFSET + _INVERTED)
#endif

#if !defined(TINY_GAME)
	#define _VERTICAL_BRICK_OFFSET '|'
	#define _HORIZONTAL_BRICK_OFFSET '-'
	
	#define _VERTICAL_BRICK _VERTICAL_BRICK_OFFSET
	#define _HORIZONTAL_BRICK _HORIZONTAL_BRICK_OFFSET	
#endif

#if defined(FULL_GAME)
	#define _FREEZE_OFFSET 'F'
	#define _EXTRA_LIFE_OFFSET _PLAYER_DOWN
	#define _INVINCIBILITY_OFFSET 0x3B  
	#define _CONFUSE_OFFSET 'C'
	#define _SUPER_OFFSET 'H'		
	#define _ZOMBIE_OFFSET 'Z' 

	#define _FREEZE (_FREEZE_OFFSET+_INVERTED)
	#define _EXTRA_LIFE (_PLAYER_DOWN + _INVERTED)
	#define _INVINCIBILITY (_INVINCIBILITY_OFFSET + _INVERTED) 
	#define _CONFUSE (_CONFUSE_OFFSET + _INVERTED)
	#define _SUPER (_SUPER_OFFSET+ _INVERTED)		
	#define _ZOMBIE (_ZOMBIE_OFFSET + _INVERTED)

	#define _CHASE_OFFSET _BULLET
	#define _LEFT_HORIZONTAL_MISSILE_OFFSET '>'
	#define _RIGHT_HORIZONTAL_MISSILE_OFFSET '<'
	#define _ROCKET_OFFSET 0x23	
	
	#define _BROKEN_BRICK _BOMB
	
	#define _CHASE _BULLET
	#define _LEFT_HORIZONTAL_MISSILE _LEFT_HORIZONTAL_MISSILE_OFFSET
	#define _RIGHT_HORIZONTAL_MISSILE _RIGHT_HORIZONTAL_MISSILE_OFFSET
	#define _ROCKET 0x23		
#endif

#define _SPACE ' '
	
	