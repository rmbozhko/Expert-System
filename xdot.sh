#!/bin/bash

FILES=rules/rule*.dot
for f in $FILES
do
	echo "Displaying file " $f 
	xdot $f
done