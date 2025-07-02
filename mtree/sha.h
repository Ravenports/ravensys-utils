#ifndef _SHA_H_
#define _SHA_H_

#include <sys/types.h>	/* XXX switch to machine/stdint.h and __ types */
#include <openssl/sha.h>

#define	SHA_BLOCK	16
#define	SHA_LENGTH_BLOCK 8
#define	SHA1_CTX	SHA_CTX

/* these three are not included in libressl for reasons unknown */
int SHA_Init(SHA_CTX *c);
int SHA_Update(SHA_CTX *c, const void *data, size_t len);
int SHA_Final(unsigned char *md, SHA_CTX *c);

#endif
