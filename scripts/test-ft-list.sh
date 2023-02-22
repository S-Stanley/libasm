#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'

gcc -Wall -Wextra -Werror -fsanitize=address -g3 srcs/ft_list.c srcs/test-ft-list.c

if [ $? -eq 1 ]
then
	echo -e "${RED}COMPILATION ERROR";
    exit 1
fi

./a.out

if [ $? -eq 0 ]
then
    echo -e "${GREEN}\nALL TESTS OK"
    exit 0
else
	echo -e "${RED}\nKO TEST $?";
    exit 1
fi