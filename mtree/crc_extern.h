#ifndef CRC_EXTERN_H
#define CRC_EXTERN_H

int	crc(int, uint32_t *, off_t *);
void	pcrc(char *, uint32_t, off_t);
void	psum1(char *, uint32_t, off_t);
void	psum2(char *, uint32_t, off_t);
int	csum1(int, uint32_t *, off_t *);
int	csum2(int, uint32_t *, off_t *);
int	crc32(int, uint32_t *, off_t *);

#endif
