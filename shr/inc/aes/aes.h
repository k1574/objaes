#ifndef _AES_H
#define _AES_H

void aes_term_size(int *col, int *row);

void aes_save_pos(void);
void aes_undo_pos(void);

void aes_move_to(int col, int row);
void aes_print(char *s);
void aes_printf(char *fmt, ...);

#endif
