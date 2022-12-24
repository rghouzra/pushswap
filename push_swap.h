/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:01:55 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/22 18:43:50 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include  <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_parsing
{
	int		i;
	char	**s;
	char	*full_arg;
	int		size;
}t_parsing;

typedef struct s_list
{
	bool			keep;
	int				value;
	int				index;
	struct s_list	*next;
}t_list;

typedef struct s_isvalid
{
	int	i;
	int	j;
	int	flag;
	int	scnd_flag;
	int	third_flag;
}t_isvalid;

typedef struct s_instruction
{
	char					*move;
	struct s_instruction	*next;
}t_instruction;

typedef struct s_x
{
	int	x_r;
	int	x_rr;
}t_x;
typedef struct s_sorting
{
	t_list	*b;
	int		pv1;
	int		pv2;
	int		c;
	int		s;
	int		keep;
	int		size_b;
}t_sorting;
typedef struct s_algo
{
	int				size;
	t_list			*copy;
	t_instruction	*tmp;
}t_algo;
void				sort_5(t_list **stack_a, t_instruction **move);
void				go_to_instruction(char *s1, t_list **a, t_list **b);
void				sort_struct_init(t_sorting *p, int size);
void				increment(int *c, int *sizeb, int *size);
int					ft_check_args(char **av, int ac);
void				sorting_3(t_list **stack_a, t_instruction **move);
void				sec_sorting_3(t_list **stack_a, t_instruction **move);
void				second_sort(t_list **a, t_list**b, t_instruction **move);
void				ft_init(t_list **s, int size);
int					get_stack_size(t_list *s);
int					index_in_stack(t_list *s, int needle);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					str_counter(char **s);
int					check_dup(char **s);
bool				issorted(t_list *s, int size);
char				**ft_split(char const *s, char c);
void				which_algo(t_list **a, int *size, t_instruction **move);
void				ft_moveadd_back(t_instruction **lst, t_instruction *new);
t_instruction		*ft_newmove(char *content);
bool				push(t_list **p, int value);
int					pop(t_list **p, int *checker);
void				ft_lstclear(t_list **lst, t_instruction **move);
void				ft_putmove(t_instruction *move);
void				strings_cleaner(char **s);
int					peek(t_list *s);
int	read_moves(t_instruction *move);
t_list				*dup_list(t_list *a);
t_instruction		*dup_move(t_instruction *move);
void				exit_with_cleaner(char *s, t_list **lst, t_list **lst2);
char				*get_next_line(int fd);
void				second_go_to(char *s, t_list **a, t_list **b);
void				read_instruction(t_list **a, t_list **b);
int					ft_strlen(char *s);
int					second_try(t_list **a, int s, t_instruction **move);
void				exit_with_clean(char **s);
void				ft_lstdellast(t_list **a);
t_instruction		*rotate_a(t_list **a, int option);
int					ft_isvalid(char **s, int ac);
t_instruction		*push_ab(t_list **a, t_list **b, int option);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_instruction		*swap_ab(t_list **s, int option);
void				ft_putstr(char *s, int fd);
long				ft_atoi(const char *nptr);
char				*ft_strcollect(char *s1, char *s2);
t_list				*ft_lstnew(int content);
void				indexing(t_list *stack_a, int size);
int					parsing(t_list **stack, int ac, char **av);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				sort_stack(t_list **stack_a, int *size, \
t_instruction **moves, int div);
int					ft_lstsize(t_instruction *lst);
t_instruction		*revers_rotat_a(t_list **a, int option);
#endif
