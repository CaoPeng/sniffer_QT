#!/bin/sh

NEWDATE=`date -d -1hour +%y-%m-%d`
git add .
git commit -m $NEWDATE
git push -u origin master
