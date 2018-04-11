#!/bin/bash
usbport="/dev/ttyUSB0"
scratchClient_configfile=~/Weekendschool/Les_2/config_weekendschool_les2_ttyUSB0.xml
ls -l $usbport > /dev/null 2>&1
ret=$?
if [ "$ret" = "0" ]; 
then
	echo "scratchClient wordt gestart op $usbport met config file: $scratchClient_configfile"
	sudo python ~/scratchClient/src/scratchClient.py -c $scratchClient_configfile
else
	echo "----> Arduino niet aangesloten op $usbport" 
	read -p "Druk op ENTER om verder te gaan ..."
fi



