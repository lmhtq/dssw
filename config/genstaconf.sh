if [ $# -lt 3 ]; then
	echo "parameters:ssid psk out_file"
	exit
fi
echo 'network={' > $3
echo "    ssid=$1"	>> $3
if [ $2 = none ]; then
	echo "    key_mgmt=NONE" >> $3
else
	echo "    psk='$2'" >> $3
fi
echo '}' >> $3