#!/bin/bash

FILES=rules/status_*.dot
for f in $FILES
do
	dot -Tpng $f -o $f.png
done

rm -rf rules/*.dot