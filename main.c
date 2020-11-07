/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndeana <ndeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 22:05:31 by ndeana            #+#    #+#             */
/*   Updated: 2020/10/25 03:51:28 by ndeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int		ft_strlen(char const *str);
int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strcpy(char *dst, char const *src);
char	*ft_strdup(char const *s1);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);

void    clear_buff(char *buff, int size)
{
	int i = 0;
	while (i < size)
		buff[i++] = 0;
}

int     main(void)
{
    char    buff[1024];
    char    buffa[1024];
    char    *s1;
    char    *s2;
    char    *s3;
    char    *s4;
    char    *s5;
    char    *s6;
    int     fd;
    ssize_t read_s;
    ssize_t read_a;

    s1 = "";
    s2 = "Hello libasm";
    s3 = "asdfasdf''///##!!@";
    s4 = "the\0hidden";
    s5 = "\n\t\r\\\\";
    s6 = "Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.";

    printf("%s\n", "****** TEST STRLEN ******");
    printf("%c", '\n');
    printf("%s\n", "Test 1:");
    printf("%s %lu %s\n", " \x1b[33m>> std:\x1b[0m", strlen(s1), "\x1b[33m<<\x1b[0m");
    printf("%s %d %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strlen(s1), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 2:");
    printf("%s %lu %s\n", " \x1b[33m>> std:\x1b[0m", strlen(s2), "\x1b[33m<<\x1b[0m");
    printf("%s %d %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strlen(s2), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 3:");
    printf("%s %lu %s\n", " \x1b[33m>> std:\x1b[0m", strlen(s3), "\x1b[33m<<\x1b[0m");
    printf("%s %d %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strlen(s3), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 4:");
    printf("%s %lu %s\n", " \x1b[33m>> std:\x1b[0m", strlen(s4), "\x1b[33m<<\x1b[0m");
    printf("%s %d %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strlen(s4), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 5:");
    printf("%s %lu %s\n", " \x1b[33m>> std:\x1b[0m", strlen(s5), "\x1b[33m<<\x1b[0m");
    printf("%s %d %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strlen(s5), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 6:");
    printf("%s %lu %s\n", " \x1b[33m>> std:\x1b[0m", strlen(s6), "\x1b[33m<<\x1b[0m");
    printf("%s %d %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strlen(s6), "\x1b[36m<<\x1b[0m");
    printf("%c", '\n');

    printf("%s\n", "****** TEST STRCMP ******");
    printf("%c", '\n');
    printf("%s\n", "Test 1:");
    printf("%s %d %s\n", " \x1b[33m>> std:\x1b[0m", strcmp(s1, s1), "\x1b[33m<<\x1b[0m");
    printf("%s %d %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strcmp(s1, s1), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 2:");
    printf("%s %d %s\n", " \x1b[33m>> std:\x1b[0m", strcmp(s6, s6), "\x1b[33m<<\x1b[0m");
    printf("%s %d %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strcmp(s6, s6), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 3:");
    printf("%s %d %s\n", " \x1b[33m>> std:\x1b[0m", strcmp(s5, s5), "\x1b[33m<<\x1b[0m");
    printf("%s %d %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strcmp(s5, s5), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 4:");
    printf("%s %d %s\n", " \x1b[33m>> std:\x1b[0m", strcmp(s2, s3), "\x1b[33m<<\x1b[0m");
    printf("%s %d %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strcmp(s2, s3), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 5:");
    printf("%s %d %s\n", " \x1b[33m>> std:\x1b[0m", strcmp(s1, s6), "\x1b[33m<<\x1b[0m");
    printf("%s %d %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strcmp(s1, s6), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 6:");
    printf("%s %d %s\n", " \x1b[33m>> std:\x1b[0m", strcmp(s6, s1), "\x1b[33m<<\x1b[0m");
    printf("%s %d %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strcmp(s6, s1), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 7:");
    printf("%s %d %s\n", " \x1b[33m>> std:\x1b[0m", strcmp(s5, s1), "\x1b[33m<<\x1b[0m");
    printf("%s %d %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strcmp(s5, s1), "\x1b[36m<<\x1b[0m");
    printf("%c", '\n');

    printf("%s\n", "****** TEST STRCPY ******");
    printf("%c", '\n');
    printf("%s\n", "Test 1:");
    printf("%s %s %s\n", " \x1b[33m>> std:\x1b[0m", strcpy(buff, s1), "\x1b[33m<<\x1b[0m");
    printf("%s %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strcpy(buff, s1), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 2:");
    printf("%s %s %s\n", " \x1b[33m>> std:\x1b[0m", strcpy(buff, s2), "\x1b[33m<<\x1b[0m");
    printf("%s %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strcpy(buff, s2), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 3:");
    printf("%s %s %s\n", " \x1b[33m>> std:\x1b[0m", strcpy(buff, s3), "\x1b[33m<<\x1b[0m");
    printf("%s %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strcpy(buff, s3), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 4:");
    printf("%s %s %s\n", " \x1b[33m>> std:\x1b[0m", strcpy(buff, s4), "\x1b[33m<<\x1b[0m");
    printf("%s %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strcpy(buff, s4), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 5:");
    printf("%s %s %s\n", " \x1b[33m>> std:\x1b[0m", strcpy(buff, s5), "\x1b[33m<<\x1b[0m");
    printf("%s %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strcpy(buff, s5), "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 6:");
    printf("%s %s %s\n", " \x1b[33m>> std:\x1b[0m", strcpy(buff, s6), "\x1b[33m<<\x1b[0m");
    printf("%s %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strcpy(buff, s6), "\x1b[36m<<\x1b[0m");
    printf("%c", '\n');

    printf("%s\n", "****** TEST STRDUP ******");
    printf("%c", '\n');
    printf("%s\n", "Test 1:");
    errno = 0;
    printf("%s %s %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", strdup(s1), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %s %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strdup(s1), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 2:");
    errno = 0;
    printf("%s %s %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", strdup(s2), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %s %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strdup(s2), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 3:");
    errno = 0;
    printf("%s %s %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", strdup(s3), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %s %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strdup(s3), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 4:");
    errno = 0;
    printf("%s %s %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", strdup(s4), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %s %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strdup(s4), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 5:");
    errno = 0;
    printf("%s %s %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", strdup(s5), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %s %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strdup(s5), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 6:");
    errno = 0;
    printf("%s %s %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", strdup(s6), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %s %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_strdup(s6), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    printf("%c", '\n');

    printf("%s\n", "****** TEST WRITE ******");
    printf("%c", '\n');
    printf("%s\n", "Test 1:");
    errno = 0;
    printf("%s %zd %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", write(1, "", 0), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %zd %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_write(1, "", 0), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 2:");
    errno = 0;
    printf("%s %zd %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", write(1, "Hello", 5), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %zd %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_write(1, "Hello", 5), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 3:");
    errno = 0;
    printf("%s %zd %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", write(1, "Hello", 2), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %zd %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_write(1, "Hello", 2), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 4:");
    errno = 0;
    printf("%s %zd %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", write(1, NULL, 6), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %zd %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_write(1, NULL, 6), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 5:");
    errno = 0;
    printf("%s %zd %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", write(0, "Hello", 5), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %zd %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_write(0, "Hello", 5), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 6:");
    errno = 0;
    printf("%s %zd %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", write(42, "Hello", 5), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m",  "\x1b[33m<<\x1b[0m");
    printf("%s %zd %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_write(42, "Hello", 5), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test 7:");
    errno = 0;
    printf("%s %zd %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", write(-1, "Hello", 5), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %zd %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", ft_write(-1, "Hello", 5), "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    printf("%s\n", "Test8:");
    fd = open("test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0777);
    write(fd, "<string.h> hello\n", 17);
	ft_write(fd, "<libasm.h> hello\n", 17);
	close(fd);
    errno = 0;
    fd = open("test.txt", O_RDONLY);
    clear_buff(buff, 1024);
    clear_buff(buffa, 1024);
    read_s = read(fd, buff, 17);
    read_a = read(fd, buffa, 17);
    printf("%s %zd %s %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", read_s, buff, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %zd %s %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", read_a, buffa, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    close(fd);
    clear_buff(buff, 1024);
    clear_buff(buffa, 1024);
    remove("test.txt");
    printf("%c", '\n');

    printf("%s\n", "****** TEST READ ******");
    printf("%c", '\n');
    
	printf("%s\n", "Test 1:");
    clear_buff(buff, 1024);
    clear_buff(buffa, 1024);
    errno = 0;
    fd = open("Makefile", O_RDONLY);
    read_s = read(fd, buff, 20);
    close(fd);
    fd = open("Makefile", O_RDONLY);
    read_a = ft_read(fd, buffa, 20);
    close(fd);
    printf("%s %zd %s %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", read_s, buff, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %zd %s %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", read_a, buffa, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    
	printf("%s\n", "Test 2:");
    clear_buff(buff, 1024);
    clear_buff(buffa, 1024);
    errno = 0;
    fd = open("Makefile", O_RDONLY);
    read_s = read(fd, buff, 150);
    close(fd);
    fd = open("Makefile", O_RDONLY);
    read_a = ft_read(fd, buffa, 150);
    close(fd);
    printf("%s %zd %s %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", read_s, buff, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %zd %s %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", read_a, buffa, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    
	printf("%s\n", "Test 3:");
    clear_buff(buff, 1024);
    clear_buff(buffa, 1024);
    errno = 0;
    read_s = read(42, buff, 20);
    read_a = ft_read(42, buffa, 20);
    printf("%s %zd %s %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", read_s, buff, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %zd %s %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", read_a, buffa, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    close(fd);
    
	printf("%s\n", "Test 4:");
    clear_buff(buff, 1024);
    clear_buff(buffa, 1024);
    errno = 0;
    fd = open("Makefile", O_RDONLY);
    read_s = read(fd, NULL, 20);
    close(fd);
    fd = open("Makefile", O_RDONLY);
    read_a = ft_read(fd, NULL, 20);
    close(fd);
    printf("%s %zd %s %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", read_s, buff, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %zd %s %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", read_a, buffa, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    
	printf("%s\n", "Test 5:");
    clear_buff(buff, 1024);
    clear_buff(buffa, 1024);
    errno = 0;
    fd = open("Makefile", O_RDONLY);
    read_s = read(fd, buff, 0);
    close(fd);
    fd = open("Makefile", O_RDONLY);
    read_a = ft_read(fd, buffa, 0);
    close(fd);
    printf("%s %zd %s %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", read_s, buff, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %zd %s %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", read_a, buffa, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
   
    printf("%s\n", "Test 6:");
    clear_buff(buff, 1024);
    clear_buff(buffa, 1024);
    errno = 0;
    read_s = read(-1, buff, 6);
    read_a = ft_read(-1, buffa, 6);
    printf("%s %zd %s %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", read_s, buff, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    printf("%s %zd %s %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", read_a, buffa, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    clear_buff(buff, 1024);
    clear_buff(buffa, 1024);
    errno = 0;
    
	// printf("%s\n", "Test 7:");
    // clear_buff(buff, 1024);
    // clear_buff(buffa, 1024);
    // errno = 0;
    // read_s = read(0, buff, 300);
    // read_a = ft_read(0, buffa, 300);
    // printf("%s %zd %s %s %d %s %s\n", " \x1b[33m>> std:\x1b[0m", read_s, buff, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[33m<<\x1b[0m");
    // printf("%s %zd %s %s %d %s %s\n", " \x1b[36m>> asm:\x1b[0m", read_a, buffa, "\x1b[31m>errno\x1b[0m", errno, "\x1b[31m<\x1b[0m", "\x1b[36m<<\x1b[0m");
    // clear_buff(buff, 1024);
    // clear_buff(buffa, 1024);
    // errno = 0;
    printf("%c", '\n');
    return (0);
}