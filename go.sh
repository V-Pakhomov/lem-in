#!/bin/sh

make -s
./lem-in < $1 | python3 visualisation/vis.py
