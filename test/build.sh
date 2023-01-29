#!/bin/bash

nasm -felf64 strlen.asm
gcc main.c strlen.o -o test
