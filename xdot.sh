#!/bin/bash

FILES=rules/status_*.dot
for f in $FILES
do
	dot -Tpng $f -o $f.png
done

convert rules/*.png prog.gif
rm -rf rules/