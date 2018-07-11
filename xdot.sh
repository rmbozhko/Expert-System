#!/bin/bash

FILES=rule*.dot
for f in $FILES
do
	echo "Displaying file " $f 
	xdot $f
done