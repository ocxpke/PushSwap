/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:00:54 by jose-ara          #+#    #+#             */
/*   Updated: 2024/09/28 19:55:31 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/**
 * All includes we need for other functions
 */
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/**
 * Structure used for bonus part
 * 1º field is for content
 * 2º field for linking next list
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief Returns if c is an alphanumeric character or not
 *
 * @param c the ascii value of the character
 * @return if it is an alphanumeric character or not
 */
int					ft_isalnum(int c);

/**
 * @brief Returns if c is an alphabethic character or not
 *
 * @param c the ascii value of the character
 * @return if it is an alphabethic character or not
 */
int					ft_isalpha(int c);

/**
 * @brief Returns if c is an ascii character or not
 *
 * @param c the ascii value of the character
 * @return if it is an ascii character or not
 */
int					ft_isascii(int c);

/**
 * @brief Returns if c is a numeric digit character or not
 *
 * @param c the ascii value of the character
 * @return if it is a numeric digit character or not
 */
int					ft_isdigit(int c);

/**
 * @brief Returns if c is an printable character or not
 *
 * @param c the ascii value of the character
 * @return if it is an printable character or not
 */
int					ft_isprint(int c);

/**
 * @brief If the parameter passed is an upper case it changes it to lower case
 *
 * @param c the ascii value of the character
 * @return the new value
 */
int					ft_tolower(int c);

/**
 * @brief If the parameter passed is an lower case it changes it to upper case
 *
 * @param c the ascii value of the character
 * @return the new value
 */
int					ft_toupper(int c);

/**
 * @brief Transformrs the ascii recived to integer
 *
 * @param nptr pointer to the string where the number is
 * @return the integer value
 */
int					ft_atoi(const char *nptr);

/**
 * @brief Compers s1 and s2 and returns the difference
 *
 * @param s1 first void pointer
 * @param s2 second void pointer
 * @param n numer of bytes to check
 * @return (1 is s1>s2); -1 if s1<s2; 0 if s1==s2
 */
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Compers s1 and s2 and returns the difference
 *
 * @param s1 first const char pointer
 * @param s2 second const char pointer
 * @param n numer of bytes to check
 * @return (1 is s1>s2); -1 if s1<s2; 0 if s1==s2
 */
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Set first n-positions to 0
 *
 * @param s void pointer
 * @param n numer of bytes to check
 * @return void
 */
void				ft_bzero(void *s, size_t n);

/**
 * @brief Iterates the pointer s and applies function f on each element
 *
 * @param s char pointer
 * @param f variable func which has as parameters and unsigned int and
 * 			a pointer to char
 * @return void
 */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief Write c into the fd passed through parameters
 *
 * @param c char to write
 * @param fd file descriptor
 * @return void
 */
void				ft_putchar_fd(char c, int fd);

/**
 * @brief Write string s into the fd passed through parameters
 *
 * @param s string to write
 * @param fd file descriptor
 * @return void
 */
void				ft_putstr_fd(char *s, int fd);

/**
 * @brief Write string s into the fd passed through parameters,
 * and ands a new line
 *
 * @param s string to write
 * @param fd file descriptor
 * @return void
 */
void				ft_putendl_fd(char *s, int fd);

/**
 * @brief Write integer n into the fd passed trhough parameters
 *
 * @param n integer to write
 * @param fd file descriptor
 * @return void
 */
void				ft_putnbr_fd(int n, int fd);

/**
 * @brief Allocates nmeb * size bytes of memory and set them all to 0
 *
 * @param nmeb number of memory blocks
 * @param size size fo each block (in bytes)
 * @return pointer to the memory allocated or null
 */
void				*ft_calloc(size_t nmeb, size_t size);

/**
 * @brief Looks for c in the first n-possitions of s
 *
 * @param s const void pointer
 * @param c char to find
 * @param n number of bytes to look
 * @return pointer to c location or null
 */
void				*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Writes the first n-posstions of src into dst
 *
 * @param dst pointer of destination
 * @param src pointer of source
 * @param n the number of bytes to read
 * @return pointer to dst or null
 */
void				*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Same as ft_memcpy but this one takes place when
 * memory position overlaps
 *
 * @param dst pointer of destination
 * @param src pointer of source
 * @param n the number of bytes to read
 * @return pointer to dst or null
 */
void				*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Set the first n-posstions of s equal to c
 *
 * @param s pointer of memory
 * @param c value to copy
 * @param n the number of bytes to read
 * @return pointer to s or null
 */
void				*ft_memset(void *s, int c, size_t n);

/**
 * @brief Looks for the first position of c in s
 *
 * @param s string were we will look
 * @param c value to find
 * @return pointer to positon of scor null
 */
char				*ft_strchr(const char *s, int c);

/**
 * @brief Take s and makes a call to malloc to reserve memory
 *
 * @param s pointer of the string
 * @return pointer to the memory reserved or null
 */
char				*ft_strdup(const char *s);

/**
 * @brief Tries to find little inside of big
 *
 * @param big string were we will look
 * @param little string to find
 * @param len length
 * @return pointer to positon of little or null
 */
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

/**
 * @brief Looks for the last position of c in s
 *
 * @param s string were we will look
 * @param c value to find
 * @return pointer to positon of c or null
 */
char				*ft_strrchr(const char *s, int c);

/**
 * @brief Tries to take a substr from s
 *
 * @param s string we will make a substr from
 * @param start postion of the first character
 * @param len length of the substr
 * @return pointer to positon of substr or null
 */
char				*ft_substr(const char *s, unsigned int start, size_t len);

/**
 * @brief Concatenates s2 behind s1
 *
 * @param s1 string were we will look
 * @param s2 value to find
 * @return pointer to positon of s1 or null
 */
char				*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Tries to delete, from front and back parts,
	the characters included in set
 *
 * @param s1 string from we will take chars
 * @param set values to delete
 * @return pointer to positon of the new string or null
 */
char				*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Takes and integer and casts it to ascii
 *
 * @param n number to cast to ascii
 * @return pointer to positon of the new string or null
 */
char				*ft_itoa(int n);

/**
 * @brief Creates a new string from apliying f to all s characters
 *
 * @param s string from were we will create new string
 * @param f function to apply to characters
 * @return pointer to positon of the new word or null
 */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Splits the string s in x-words eliminating the c char
 *
 * @param s string to split
 * @param c value to delete
 * @return pointer to positon of the first word or null
 */
char				**ft_split(char const *s, char c);

/**
 * @brief Concatenates dst and src in the buffer of length size
 *
 * @param dst first string
 * @param src second string
 * @param size total lentgh of buffer
 * @return size of the string that tried to/has create
 */
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Copies the first n-bytes of src into dst
 *
 * @param dst where will be copied src
 * @param src source of teh string
 * @param size number of bytes to copy
 * @return size of the new word created
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Gives you the length of s
 *
 * @param s string we will measure
 * @return size of s
 */
size_t				ft_strlen(const char *s);

/**
 * <------------------------------BONUS PART----------------------------->
 */

/**
 * @brief Gives you the length of the list
 *
 * @param lst list we will measure
 * @return size of the list
 */
int					ft_lstsize(t_list *lst);

/**
 * @brief Gives you the postion of the last node
 *
 * @param lst list we will look into
 * @return the last node or null
 */
t_list				*ft_lstlast(t_list *lst);

/**
 * @brief Iterates and creates a new list feom lst applying f to all content,
 * del use in case of need to delete
 *
 * @param lst list we will look into
 * @param f function to aply to list content
 * @param del funtion to use in case of necesity of delete
 * @return the memory position of new list or null
 */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/**
 * @brief Creates a new list
 *
 * @param content content for the new node
 * @return memory position if the new node or null
 */
t_list				*ft_lstnew(void *content);

/**
 * @brief Add new to the back part of lst
 *
 * @param lst list we will look into
 * @param new node we have to add
 * @return void
 */
void				ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Add new to the front part of lst
 *
 * @param lst list we will look into
 * @param new node we have to add
 * @return void
 */
void				ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Deletes and frees all the list
 *
 * @param lst list we will delete
 * @param del function to delete the nodes
 * @return void
 */
void				ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Deletes and frees one node
 *
 * @param lst node to delete
 * @param del function to delete the node
 * @return void
 */
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Iterates the list and applies f to all content of list
 *
 * @param lst list we will iterate
 * @param f function to apply to content
 * @return void
 */
void				ft_lstiter(t_list *lst, void (*f)(void *));

#endif
