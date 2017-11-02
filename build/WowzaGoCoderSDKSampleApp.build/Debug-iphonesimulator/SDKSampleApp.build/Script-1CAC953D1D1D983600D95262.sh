#!/bin/sh
my_script="./validatesdk.sh"
if [ ! -f "$my_script" ]
then
    exit 0
fi

chmod +x $my_script

./$my_script
