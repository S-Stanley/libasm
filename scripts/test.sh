#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'

rm -rf tests
mkdir tests
touch tests/test-write-libasm tests/test-write-real

make
./scripts/build-test.sh

./a.out real > log-real
./a.out libasm > log-libasm
diff log-real log-libasm > result


if [ $? -eq 0 ]
then
	echo -e "${GREEN}SUCCESS TEST";
	rm log-real log-libasm result
else
	echo -e "${RED}ERROR TEST";
	rm log-real log-libasm result
	exit 1
fi

exit 0
