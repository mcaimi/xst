/*
 *  Xst
 *  Main profram #defines
 *
 */

#define Glyph Glyph_
#define Font Font_

#define _NET_WM_STATE_REMOVE  0
#define _NET_WM_STATE_ADD     1
#define _NET_WM_STATE_TOGGLE  2
#define GET_WINDOW_PROPERTY_SIZE 65535

#if   defined(__linux)
 #include <pty.h>
#elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 #include <util.h>
#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #include <libutil.h>
#endif

/* XEMBED messages */
#define XEMBED_FOCUS_IN  4
#define XEMBED_FOCUS_OUT 5

/* Arbitrary sizes */
#define UTF_INVALID   0xFFFD
#define UTF_SIZ       4
#define ESC_BUF_SIZ   (128*UTF_SIZ)
#define ESC_ARG_SIZ   16
#define STR_BUF_SIZ   ESC_BUF_SIZ
#define STR_ARG_SIZ   ESC_ARG_SIZ
#define XK_ANY_MOD    UINT_MAX
#define XK_NO_MOD     0
#define XK_SWITCH_MOD (1<<13)
#define OPAQUE 0Xff

/* macros */
#define MIN(a, b)		((a) < (b) ? (a) : (b))
#define MAX(a, b)		((a) < (b) ? (b) : (a))
#define LEN(a)			(sizeof(a) / sizeof(a)[0])
#define NUMMAXLEN(x)		((int)(sizeof(x) * 2.56 + 0.5) + 1)
#define DEFAULT(a, b)		(a) = (a) ? (a) : (b)
#define BETWEEN(x, a, b)	((a) <= (x) && (x) <= (b))
#define DIVCEIL(n, d)		(((n) + ((d) - 1)) / (d))
#define ISCONTROLC0(c)		(BETWEEN(c, 0, 0x1f) || (c) == '\177')
#define ISCONTROLC1(c)		(BETWEEN(c, 0x80, 0x9f))
#define ISCONTROL(c)		(ISCONTROLC0(c) || ISCONTROLC1(c))
#define ISDELIM(u)		(utf8strchr(worddelimiters, u) != NULL)
#define LIMIT(x, a, b)		(x) = (x) < (a) ? (a) : (x) > (b) ? (b) : (x)
#define ATTRCMP(a, b)		((a).mode != (b).mode || (a).fg != (b).fg || \
				(a).bg != (b).bg)
#define IS_SET(flag)		((term.mode & (flag)) != 0)
#define TIMEDIFF(t1, t2)	((t1.tv_sec-t2.tv_sec)*1000 + \
				(t1.tv_nsec-t2.tv_nsec)/1E6)
#define MODBIT(x, set, bit)	((set) ? ((x) |= (bit)) : ((x) &= ~(bit)))

#define USE_ARGB (alpha != OPAQUE && opt_embed == NULL)

#define TRUECOLOR(r,g,b)	(1 << 24 | (r) << 16 | (g) << 8 | (b))
#define IS_TRUECOL(x)		(1 << 24 & (x))
#define TRUERED(x)		(((x) & 0xff0000) >> 8)
#define TRUEGREEN(x)		(((x) & 0xff00))
#define TRUEBLUE(x)		(((x) & 0xff) << 8)
#define TLINE(y)		((y) < term.scr ? term.hist[((y) + term.histi - term.scr \
				+ histsize + 1) % histsize] : term.line[(y) - term.scr])

#define TRUE 1
#define FALSE 0

#define XRESOURCE_LOAD_META(NAME)                                  \
	if(!XrmGetResource(xrdb, "st." NAME, "st." NAME, &type, &ret)) \
		XrmGetResource(xrdb, "*." NAME, "*." NAME, &type, &ret);   \
	if (ret.addr != NULL && !strncmp("String", type, 64))

#define XRESOURCE_LOAD_STRING(NAME, DST) \
	XRESOURCE_LOAD_META(NAME)            \
		DST = ret.addr;

#define XRESOURCE_LOAD_CHAR(NAME, DST) \
	XRESOURCE_LOAD_META(NAME)            \
		DST = ret.addr[0];

#define XRESOURCE_LOAD_INTEGER(NAME, DST)  \
	XRESOURCE_LOAD_META(NAME)              \
		DST = strtoul(ret.addr, NULL, 10);

#define XRESOURCE_LOAD_FLOAT(NAME, DST) \
	XRESOURCE_LOAD_META(NAME)           \
		DST = strtof(ret.addr, NULL);

#define ISO14755CMD		"dmenu -w %lu -p codepoint: </dev/null"
