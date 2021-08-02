#ifndef _AES_H
#define _AES_H

int aes_reset_term(void);
void aes_disable_input_buffering(void);
void aes_disable_input_echo(void);
int aes_apply_term_settings(void);

void aes_term_size(int *col, int *row);

void aes_save_pos(void);
void aes_undo_pos(void);

void aes_move_to(int col, int row);
void aes_move_right(unsigned int n);
void aes_move_left(unsigned int n);
void aes_print(char *s);
void aes_printf(char *fmt, ...);

void aes_clear_entire_line(void);
void aes_clear_entire_screen(void);


#endif
