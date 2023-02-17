#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

./scripts/build-test.sh
./a.out real > log-real
./a.out libasm > log-libasm
diff log-real log-libasm > result


if [ $? -eq 0 ]
then
	echo -e "${GREEN} SUCCESS";
	rm log-real log-libasm result
	exit 0;
else
	echo -e "${RED} ERROR";
	rm log-real log-libasm result
	exit 1
fi
