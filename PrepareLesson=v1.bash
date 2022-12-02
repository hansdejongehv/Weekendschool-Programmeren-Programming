#!/bin/bash
# ResultsDirThisSystemOnUSB

Desktop=/home/pi/Desktop
LocalResultsBackup=$Desktop/ScratchPgms-Backup

echo 00 = Remove previous files

echo 1x = Dutch
echo 2x = English
echo 3x = German

echo x1 = Weekendschool Les 1B - Red de prinses
echo x2 = Weekendschool Les 2A
echo x3 = Scratchclient Tutorials

read selection

case "$selection" in
00)
	for f in $Desktop/*
	do
		#notify-send "$f"
		if [ ! -d "$f" ] && [ -e "$f" ] 
		then
			case "$f" in 
			*.sbx|*.sb2|*.ods|*.txt)
				cp "$f" $ResultsDirThisSystemOnUSB
				mv "$f" $LocalResultsBackup
				;;
			*.pdf)
				mv "$f" $LocalResultsBackup
				;;
			esac
		fi
		
		if [ -d "$f" ] 
		then
			# echo "$f"
			case "$f" in
			*Geluiden*)
				mv "$f" $LocalResultsBackup
				;;
			*ScratchPgms-Backup)
				;;
			*)Begeleider
				;;
			*)
				mv "$f" $LocalResultsBackup
				;;
			esac
		fi
	done
	
	;;
	
11) cp /home/pi/Weekendschool-Programming $Desktop
	;;
	
	

cp "/home/pi/Weekendschool-Programming/Weekendschool-Programmeerlessen/Les_1B_Red_de_prinses/Originelen/Wie en waar les 1B.ods" "$Desktop/Wie en waar les 2A.ods"


		

