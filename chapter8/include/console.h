#ifndef _ORANGES_CONSOLE_H_
#define _ORANGES_CONSOLE_H_

typedef struct s_console
{
	unsigned	int	current_start_addr;		/* 当前显示到了什么位置 */
	unsigned	int	original_addr;			/* 当前控制台对应显存位置 */
	unsigned	int	v_mem_limit;			/* 当前控制台占的显存大小 */
	unsigned	int	cursor;				/* 当前光标位置 */
}CONSOLE;

#define SCR_UP	1	/* scroll forward */
#define SCR_DN	-1	/* scroll backward */

#define SCR_SIZE		(80 * 25)
#define SCR_WIDTH		80

#define DEFAULT_CHAR_COLOR	(MAKE_COLOR(BLACK, WHITE))
#define GRAY_CHAR			(MAKE_COLOR(BLACK, BLACK) | BRIGHT)
#define RED_CHAR				(MAKE_COLOR(BLUE, RED) | BRIGHT)

#define SCR_UP	1	/* scroll forward */
#define SCR_DN	-1	/* scroll backward */

#define SCREEN_SIZE		(80 * 25)
#define SCREEN_WIDTH		80


//#define DEFAULT_CHAR_COLOR	0x07	/* 0000 0111 黑底白字 */


#endif /* _ORANGES_CONSOLE_H_ */