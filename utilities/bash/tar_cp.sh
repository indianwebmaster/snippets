#!/usr/bin/env bash

src=$1
dest=$2

if [ "x$1" = "x-h" -o "x$1" = "x" -o "x$2" = "x" ]; then
        echo "Usage: tar_cp.sh <src_dir> <dest_dir>"
        echo ""
        echo "  Will copy all files and symlinks from src_dir/* to dest_dir/*"
        echo "  Both src_dir and dest_dir must pre-exist"
        exit 0
fi

if [ ! -r $src ]; then echo "Source ($src) does not exist"; exit; fi
if [ ! -r $dest ]; then echo "Destination ($dest) does not exist"; exit; fi

srcParent=`dirname $src`
srcName=`basename $src`
set -x
cd $srcParent
tar cf - $srcName | (cd $dest; tar xf -)
