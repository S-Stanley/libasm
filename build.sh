#!/bin/bash
nasm -felf64 app.asm
ld app.o -o app
