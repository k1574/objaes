#include <aes/aes.h>

int
main(int argc, char *argv[])
{
	int w, h;
	aes_clear_entire_screen();
	aes_move_to(10, 3);
	aes_printf("Hello, Motherfucker!");
	aes_term_size(&w, &h);
	aes_move_to(10, 1);
	aes_printf("Size of terminal is %dx%d", w, h);

	return 0 ;
}

