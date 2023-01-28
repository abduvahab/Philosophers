# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: areheman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 15:26:02 by areheman          #+#    #+#              #
#    Updated: 2022/06/25 17:11:56 by areheman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

GCC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -lpthread

SRCS = philo.c check_error.c ft_init.c philo_utils.c ft_launch.c check_exit.c 

OBJS = ${SRCS:.c=.o}

%.o : %.c
		@$(GCC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
		@$(GCC) $(CFLAGS) $(INCLUDE) -o $@ $^


clean : 
		@rm -rf $(OBJS)

fclean : clean
		@rm -rf $(NAME)

re : clean fclean all 

.PHONEY : all clean fclean re 
