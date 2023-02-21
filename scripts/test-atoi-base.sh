#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'

gcc -Wall -Wextra -Werror -fsanitize=address -g3 srcs/test-atoi-base.c srcs/ft_atoi_base.c

if [ $? -eq 1 ]
then
	echo -e "${RED}COMPILATION ERROR";
    exit 1
fi

./a.out

if [ $? -eq 0 ]
then
    echo -e "${GREEN}ALL TESTS OK"
    exit 0
else
	echo -e "${RED}KO TEST $?";
    exit 1
fi