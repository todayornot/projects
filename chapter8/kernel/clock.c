#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"

/*======================================================================*
                           milli_delay
 *======================================================================*/
PUBLIC void milli_delay(int milli_sec)
{
	int t = get_ticks();
	
	while(( (get_ticks() - t) * 1000 / HZ) < milli_sec){}
}

/*======================================================================*
                           clock_handler
 *======================================================================*/

PUBLIC	void	clock_handler(int irq)
{
	ticks++;
	p_proc_ready->ticks--;

	if(k_reenter != 0){
		return;
	}

	if(p_proc_ready->ticks > 0){
		return;
	}

	schedule();
}
/*=====================================================================*
                           init_clock
 *======================================================================*/
PUBLIC void init_clock()
{
	/* 初始化8253 PIT */
	out_byte(TIMER_MODE, RATE_GENERATOR);
	out_byte(TIMER0, (u8)(TIMER_FREQ/HZ) );
	out_byte(TIMER0, (u8)((TIMER_FREQ/HZ) >> 8) );

	put_irq_handler(CLOCK_IRQ, clock_handler);
	enable_irq(CLOCK_IRQ);
}

