#include "aes/raw_aes.h"
#include "aes/aes.h"

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <termios.h>

static struct termios term, term_orig;

int
aes_reset_term(void)
{
	static int first_time = 1 ;
	if(first_time){
		int ret;
		if(ret = tcgetattr(0, &term_orig))
			return ret ;
		first_time = 0 ;
	}
	term = term_orig ;
	return 0 ;
}

void
aes_disable_input_buffering(void)
{
	/* Change to non-canonical mode. */
	term.c_lflag &= ~ICANON ;

	/* Read at least one byte. */ 
	term.c_cc[VMIN] = 1 ;
	term.c_cc[VTIME] = 0 ;
}

void
aes_disable_input_echo(void)
{
	term.c_lflag &= ~ECHO ;
}

int
aes_apply_term_settings(void)
{
	return tcsetattr(0, TCSANOW, &term) ;
}

void
aes_print(char *s)
{
	write(1, s, strlen(s));
}

void
aes_printf(char *fmt, ...)
{
	va_list ap;
	char buf[256];
	int n;

	va_start(ap, fmt);
	n = vsprintf(buf, fmt, ap);
	va_end(ap);
	write(1, buf, n);
}

void
aes_term_size(int *col, int *row)
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	*col = w.ws_col ; *row = w.ws_row ;
}

void
aes_save_pos(void)
{
	aes_print(aes_raw_esc_seqs[AesSavePos].fmt);
}

void
aes_undo_pos(void)
{
	aes_print(aes_raw_esc_seqs[AesUndoPos].fmt);
}

void
aes_clear_entire_screen(void)
{
	aes_print(aes_raw_esc_seqs[AesClearEntScreen].fmt);
}

void
aes_clear_entire_line(void)
{
	aes_print(aes_raw_esc_seqs[AesClearEntLine].fmt);
}

void
aes_move_to(int col, int row)
{
	aes_printf(aes_raw_esc_seqs[AesMoveTo].fmt, row, col);
}

void
aes_move_right(unsigned int n)
{
	aes_printf(aes_raw_esc_seqs[AesMoveRight].fmt, n);
}

void
aes_move_left(unsigned int n)
{
	aes_printf(aes_raw_esc_seqs[AesMoveLeft].fmt, n);
}

