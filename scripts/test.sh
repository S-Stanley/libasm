#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

mkdir tests
touch tests/test-write-libasm tests/test-write-real

./scripts/build-test.sh
./a.out real > log-real
./a.out libasm > log-libasm
diff log-real log-libasm > result


if [ $? -eq 0 ]
then
	echo -e "${GREEN}SUCCESS TEST 0";
	rm log-real log-libasm result
else
	echo -e "${RED}ERROR TEST 0";
	rm log-real log-libasm result
	exit 1
fi

diff tests/test-write-libasm tests/test-write-real

if [ $? -eq 0 ]
then
        echo -e "${GREEN}SUCCESS TEST 1";
else
        echo -e "${RED}ERROR TEST 1";
        exit 1
fi

exit 0
