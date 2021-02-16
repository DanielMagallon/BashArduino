#!/bin/bash
#this a serial port
exec 3<>/dev/ttyACM0
stty -F /dev/ttyACM0 9600 cs8 cread clocal
#-cstopb -parenb
#echo "1" >&3                 # send data
cat <&3
