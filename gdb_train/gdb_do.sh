#!/bin/bash

name=$1
prog=$1.c
gdb_test="$1_test".gdb

echo $name
echo $prog
echo $gdb_test

gcc -g $prog -o $name

IFS=$'\n'
for chunk in $(gdb -q -x $gdb_test $name)
do
	#echo "chunk = \"$chunk\""
	if [[ "$chunk" == "error" ]];then
		echo "[TEST FAILED]"
		break
	fi
	if [[ "$chunk" == "success" ]];then
		echo "[TEST PASSED]"
		break
	fi
done

rm $name

exit 0

