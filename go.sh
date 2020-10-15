#!/bin/sh

function usage {
echo "usage: ./go.sh [-d] map_file"
exit 1
}

if [ $# -gt 2 ]
then
usage
fi

if [ -n "$2" ]
then
case "$1" in
-d) make -s && ./lem-in -d < $2 | python3 visualisation/vis.py $1 ;;
-h) usage ;;
*) echo "./go.sh: illegal option -- $1" && usage ;;
esac
else
if [ $1 = "-h" ]
then
usage
fi
make -s
./lem-in < $1 | python3 visualisation/vis.py
fi
