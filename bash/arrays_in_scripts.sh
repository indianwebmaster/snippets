#!/usr/bin/env bash

arr[1]="arr1"
arr[2]="arr2"
arr[3]="arr3"
arr[4]="arr4"
arr[5]="arr5"

i=1
while [ $i -le 5 ]; do
        echo "${arr[$i]}"
        garr[$i]="garr${i}"
        i=`expr $i + 1`
done

i=1
while [ $i -le 5 ]; do
        echo "${garr[$i]}"
        i=`expr $i + 1`
done

