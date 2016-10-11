#ifndef STRING_42_H
# define STRING_42_H

# include <stdlib.h>
# include "ctype_42.h"
# include "memory_42.h"

#define ASCII_TABLE_LEN 127

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, size_t n);

size_t	ft_strlen(const char *s);
size_t	ft_strnlen(const char *s, size_t maxlen);

char	*ft_strchr(const char *s, int c);
char	*ft_strnchr(const char *s, int c, size_t n);

char	*ft_strrchr(const char *s, int c);
char	*ft_strrnchr(const char *s, int c, size_t n);

int		ft_strchrpos(const char *s, int c);
int		ft_strnchrpos(const char *s, int c, size_t n);

int		ft_strrchrpos(const char *s, int c);
int		ft_strrnchrpos(const char *s, int c, size_t n);

char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strrev(char *str);

char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strrstr(const char *big, const char *little);
char	*ft_strrnstr(const char *big, const char *little, size_t len);

char	*ft_strtoupper(char *str);
char	*ft_strtolower(char *str);

#endif
