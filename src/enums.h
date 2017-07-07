/*
 * Xst
 * enums definition
 */

enum glyph_attribute {
	ATTR_NULL       = 0,
	ATTR_BOLD       = 1 << 0,
	ATTR_FAINT      = 1 << 1,
	ATTR_ITALIC     = 1 << 2,
	ATTR_UNDERLINE  = 1 << 3,
	ATTR_BLINK      = 1 << 4,
	ATTR_REVERSE    = 1 << 5,
	ATTR_INVISIBLE  = 1 << 6,
	ATTR_STRUCK     = 1 << 7,
	ATTR_WRAP       = 1 << 8,
	ATTR_WIDE       = 1 << 9,
	ATTR_WDUMMY     = 1 << 10,
	ATTR_BOLD_FAINT = ATTR_BOLD | ATTR_FAINT,
};

enum cursor_movement {
	CURSOR_SAVE,
	CURSOR_LOAD
};

enum cursor_state {
	CURSOR_DEFAULT  = 0,
	CURSOR_WRAPNEXT = 1,
	CURSOR_ORIGIN   = 2
};

enum term_mode {
	MODE_WRAP        = 1 << 0,
	MODE_INSERT      = 1 << 1,
	MODE_APPKEYPAD   = 1 << 2,
	MODE_ALTSCREEN   = 1 << 3,
	MODE_CRLF        = 1 << 4,
	MODE_MOUSEBTN    = 1 << 5,
	MODE_MOUSEMOTION = 1 << 6,
	MODE_REVERSE     = 1 << 7,
	MODE_KBDLOCK     = 1 << 8,
	MODE_HIDE        = 1 << 9,
	MODE_ECHO        = 1 << 10,
	MODE_APPCURSOR   = 1 << 11,
	MODE_MOUSESGR    = 1 << 12,
	MODE_8BIT        = 1 << 13,
	MODE_BLINK       = 1 << 14,
	MODE_FBLINK      = 1 << 15,
	MODE_FOCUS       = 1 << 16,
	MODE_MOUSEX10    = 1 << 17,
	MODE_MOUSEMANY   = 1 << 18,
	MODE_BRCKTPASTE  = 1 << 19,
	MODE_PRINT       = 1 << 20,
	MODE_UTF8        = 1 << 21,
	MODE_SIXEL       = 1 << 22,
	MODE_MOUSE       = MODE_MOUSEBTN|MODE_MOUSEMOTION|MODE_MOUSEX10\
	                  |MODE_MOUSEMANY,
};

enum charset {
	CS_GRAPHIC0,
	CS_GRAPHIC1,
	CS_UK,
	CS_USA,
	CS_MULTI,
	CS_GER,
	CS_FIN
};

enum escape_state {
	ESC_START      = 1,
	ESC_CSI        = 2,
	ESC_STR        = 4,  /* OSC, PM, APC */
	ESC_ALTCHARSET = 8,
	ESC_STR_END    = 16, /* a final string was encountered */
	ESC_TEST       = 32, /* Enter in test mode */
  ESC_UTF8       = 64,
  ESC_DCS        =128,
};

enum window_state {
	WIN_VISIBLE = 1,
	WIN_FOCUSED = 2,
  WIN_FULLSCREEN = 3
};

enum selection_mode {
	SEL_IDLE = 0,
	SEL_EMPTY = 1,
	SEL_READY = 2
};

enum selection_type {
	SEL_REGULAR = 1,
	SEL_RECTANGULAR = 2
};

enum selection_snap {
	SNAP_WORD = 1,
	SNAP_LINE = 2
};

