#get iface
iface=$(ifconfig -a | grep wlp | sed 's/://g' | awk '{print $1}')
#echo $iface

if [ $# -lt 4 ]; then
	echo "parameters:ssid channel hw_mode out_file"
	exit
fi

echo interface=$iface > $4
echo driver=nl80211 >> $4
echo ssid=$1 >> $4
echo channel=$2 >> $4
echo ieee80211n=1 >> $4
echo hw_mode=$3 >> $4
echo ignore_broadcast_ssid=0 >> $4
echo auth_algs=1 >> $4
echo wpa=3 >> $4
echo wpa_passphrase=87654321 >> $4
echo wpa_key_mgmt=WPA-PSK >> $4
echo wpa_pairwise=TKIP >> $4
echo rsn_pairwise=CCMP >> $4