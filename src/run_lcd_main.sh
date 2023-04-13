#!/usr/bin/env bash

SCRIPT=$(readlink -f "$0")
SCRIPTPATH=$(dirname "$SCRIPT")

LCD_MAIN=$SCRIPTPATH"/LCD_Main"

if [ -f $LCD_MAIN ]
then
    nohup $LCD_MAIN &> /var/tmp/lcd.log &

else
    echo "File: "$LCD_MAIN" does not exist. Did you compile the program?"
fi
