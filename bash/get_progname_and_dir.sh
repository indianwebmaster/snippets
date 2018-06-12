#!/usr/bin/env bash
progname=$(basename $0)
progdir=$(dirname $0)
progdir=$(cd $progdir; pwd)

echo "Program name: $progname"
echo "Program absolute path: $progdir"
