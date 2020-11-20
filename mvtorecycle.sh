#!/bin/bash

if [ $# -ge 1 ]
then
	FDIRNAME=$(dirname "$1")
	NETWORKRECYCLEBIN="/bkp/btbkp/Lixeira"
	FTARGET=$(echo $FDIRNAME | sed --expression='s/\/bkp\/up//' | sed --expression='s/.file_deleted//')
	NFILETARGET=$(echo "$1" | sed --expression='s/\/bkp\/up//' | sed --expression='s/.file_deleted//')
	FTARGDIR="$NETWORKRECYCLEBIN$FTARGET"
	mkdir -p "$NETWORKRECYCLEBIN$FTARGET"
	#echo $NFILETARGET
	mv "$1" "$NETWORKRECYCLEBIN$NFILETARGET"
	#mv $1 
else
	echo "Argument required"
fi


