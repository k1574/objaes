#include "shr/inc/aes/raw_aes.h"
#include "shr/inc/aes/aes.h"

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

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
