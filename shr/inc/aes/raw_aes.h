#ifndef _RAW_Aes_H
#define _RAW_Aes_H

/* Defines of raw ANSI escape sequences. */

#define ESC "\033["

enum {

	AesHome,
	AesMoveTo,
	AesMoveUp,
	AesMoveDown,
	AesMoveRight,
	AesMoveLeft,
	AesNextLine,
	AesPrevLine,
	AesMoveToCol,
	AesReportPos,
	AesSavePos,
	AesUndoPos,

	AesFgBlack,
	AesFgRed,
	AesFgGreen,
	AesFgYellow,
	AesFgBlue,
	AesFgMagenta,
	AesFgCyan,
	AesFgWhite,

	AesFgBrBlack,
	AesFgBrRed,
	AesFgBrGreen,
	AesFgBrYellow,
	AesFgBrBlue,
	AesFgBrMagenta,
	AesFgBrCyan,
	AesFgBrWhite,

	AesBgBlack,
	AesBgRed,
	AesBgGreen,
	AesBgYellow,
	AesBgBlue,
	AesBgMagenta,
	AesBgCyan,
	AesBgWhite,

	AesBgBrBlack,
	AesBgBrRed,
	AesBgBrGreen,
	AesBgBrYellow,
	AesBgBrBlue,
	AesBgBrMagenta,
	AesBgBrCyan,
	AesBgBrWhite,

	AesEnd,
	AesBold,
	AesUnderline,
	AesReversed,

	AesClearScreen,
	AesClearTilEndOfScreen,
	AesClearTilBegOfScreen,
	AesClearEntScreen,
	AesClearCurLine,
	AesClearTilEndOfLine,
	AesClearTilBegOfLine,
	AesClearEntLine,

	AesMakeCurInvisible,
	AesMakeCurVisible,
	AesRestoreScreen,
	AesSaveScreen,
	AesEnableAltBuf,
	AesDisableAltBuf,

	AesLen
} ;

struct AnsiEscSeq {
	char *fmt;	
	int  narg;
} ;
typedef struct AnsiEscSeq EscSeq; 

EscSeq aes_raw_esc_seqs[AesLen] = {
	[AesHome] = {ESC "H", 0} ,
	[AesMoveTo] = {ESC "%d;%dH", 2},
	[AesMoveUp] = {ESC "%dA", 1},
	[AesMoveDown] = {ESC "%dB", 1},
	[AesMoveRight] = {ESC "%dC", 1},
	[AesMoveLeft] = {ESC "%dD", 1},
	[AesNextLine] = {ESC "%dE", 1},
	[AesPrevLine] = {ESC "%dF", 1},
	[AesMoveToCol] = {ESC "%dG", 1},
	[AesReportPos] = {ESC "6n", 0},
	[AesSavePos] = {ESC "s", 0},
	[AesUndoPos] = {ESC "u", 0},

	[AesFgBlack] = {ESC "30m", 0},
	[AesFgRed] = {ESC "31m", 0},
	[AesFgGreen] = {ESC "32m", 0},
	[AesFgYellow] = {ESC "33m", 0},
	[AesFgBlue] = {ESC "34m", 0},
	[AesFgMagenta] = {ESC "35m", 0},
	[AesFgCyan] = {ESC "36m", 0},
	[AesFgWhite] = {ESC "37m", 0},

	[AesFgBrBlack] = {ESC "90m", 0},
	[AesFgBrRed] = {ESC "91m", 0},
	[AesFgBrGreen] = {ESC "92m", 0},
	[AesFgBrYellow] = {ESC "93m", 0},
	[AesFgBrBlue] = {ESC "94m", 0},
	[AesFgBrMagenta] = {ESC "95m", 0},
	[AesFgBrCyan] = {ESC "96m", 0},
	[AesFgBrWhite] = {ESC "97m", 0},

	[AesBgBlack] = {ESC "40m", 0},
	[AesBgRed] = {ESC "41m", 0},
	[AesBgGreen] = {ESC "42m", 0},
	[AesBgYellow] = {ESC "43m", 0},
	[AesBgBlue] = {ESC "44m", 0},
	[AesBgMagenta] = {ESC "45m", 0},
	[AesBgCyan] = {ESC "46m", 0},
	[AesBgWhite] = {ESC "47m", 0},

	[AesBgBrBlack] = {ESC "100m", 0},
	[AesBgBrRed] = {ESC "101m", 0},
	[AesBgBrGreen] = {ESC "102m", 0},
	[AesBgBrYellow] = {ESC "103m", 0},
	[AesBgBrBlue] = {ESC "104m", 0},
	[AesBgBrMagenta] = {ESC "105m", 0},
	[AesBgBrCyan] = {ESC "106", 0},
	[AesBgBrWhite] = {ESC "107m", 0},
	
	[AesEnd] = {ESC "0m", 0},
	[AesBold] = {ESC "1m", 0},
	[AesUnderline] = {ESC "4m", 0},
	[AesReversed] = {ESC "7m", 0},
	
	[AesClearScreen] = {ESC "J", 0},
	[AesClearTilEndOfScreen] = {ESC "0J", 0},
	[AesClearTilBegOfScreen] = {ESC "1J", 0},
	[AesClearEntScreen] = {ESC "2J", 0},
	[AesClearCurLine] = {ESC "K", 0},
	[AesClearTilEndOfLine] = {ESC "0K", 0},
	[AesClearTilBegOfLine] = {ESC "1K", 0},
	[AesClearEntLine] = {ESC "2K", 0},

	[AesMakeCurInvisible] = {ESC "?25l", 0},
	[AesMakeCurVisible] = {ESC "?25h"},
	[AesRestoreScreen] = {ESC "?47l", 0},
	[AesSaveScreen] = {ESC "?47h", 0},
	[AesEnableAltBuf] = {ESC "?1049h", 0},
	[AesDisableAltBuf] = {ESC "?1049l", 0},
} ;

#endif
