#ifndef BSDVIS_H
#define BSDVIS_H

#include <sys/types.h>

/*
 * to select alternate encoding format
 */
#define	VIS_OCTAL	0x01	/* use octal \ddd format */
#define	VIS_CSTYLE	0x02	/* use \[nrft0..] where appropriate */

/*
 * to alter set of characters encoded (default is to encode all
 * non-graphic except space, tab, and newline).
 */
#define	VIS_SP		0x04	/* also encode space */
#define	VIS_TAB		0x08	/* also encode tab */
#define	VIS_NL		0x10	/* also encode newline */
#define	VIS_WHITE	(VIS_SP | VIS_TAB | VIS_NL)
#define	VIS_SAFE	0x20	/* only encode "unsafe" characters */

/*
 * other
 */
#define	VIS_NOSLASH	0x40	/* inhibit printing '\' */
#define	VIS_HTTPSTYLE	0x80	/* http-style escape % HEX HEX */
#define	VIS_GLOB	0x100	/* encode glob(3) magics */

/*
 * unvis return codes
 */
#define	UNVIS_VALID	 1	/* character valid */
#define	UNVIS_VALIDPUSH	 2	/* character valid, push back passed char */
#define	UNVIS_NOCHAR	 3	/* valid sequence, no character produced */
#define	UNVIS_SYNBAD	-1	/* unrecognized escape sequence */
#define	UNVIS_ERROR	-2	/* decoder in unknown state (unrecoverable) */

/*
 * unvis flags
 */
#define	UNVIS_END	1	/* no more characters */

char	*vis(char *, int, int, int);
int	strvis(char *, const char *, int);
int	strvisx(char *, const char *, size_t, int);
int	strnvis(char *, const char *, size_t, int);
int	strunvis(char *, const char *);
int	strunvisx(char *, const char *, int);
ssize_t strnunvis(char *, const char *, size_t);
int	unvis(char *, int, int *, int);

#endif /* !BSDVIS_H */
