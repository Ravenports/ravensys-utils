#ifndef FORSUNOS_H
#define FORSUNOS_H

#if defined(__sun__)
char	 *fgetln(FILE *, size_t *);
mode_t  getmode(const void *set, mode_t mode);
void   *setmode(const char *mode_str);
#endif

#endif
