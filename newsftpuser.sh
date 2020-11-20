#!/bin/bash

if [ $# -ge 1 ]
then
	mkdir /bkp/up/$1
	useradd -m $1 -g sftp
	passwd $1
	mkdir /bkp/up/$1/upload
	chown $1:sftp /bkp/up/$1/upload
else
	echo "User name required as argument"
fi

