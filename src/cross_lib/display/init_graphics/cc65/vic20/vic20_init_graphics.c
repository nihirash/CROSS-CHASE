#include <peekpoke.h>
#include <vic20.h>

void INIT_GRAPHICS(void)
{
	#if defined(REDEFINED_CHARS)
		#if defined(VIC20_EXP_8K) || defined(VIC20_EXP_16K)
			unsigned char tmp;
		
			tmp = ~0x0F & PEEK(&(VIC.addr));
			POKE(&(VIC.addr), tmp | 0x0F);
		#elif defined(VIC20_EXP_3K)
			POKE(0x9005,0xFF);		
		#endif
	#endif
	
	POKE(646,1);
	POKE(36879L,9);
}

