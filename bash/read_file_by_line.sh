#!/usr/bin/env bash

# Read this script itself

i=0
cat $0 | while read oneLine; do
	echo "${i}:--${oneLine}--"
	i=`expr $i + 1`
done
