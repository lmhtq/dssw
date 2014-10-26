if [ $# -lt 3 ]; then
	echo "parameters:net dnsmasqfile"
	exit
fi
#get iface
iface=$(ifconfig -a | grep wlp | sed 's/://g' | awk '{print $1}')
echo listen-address=$1.1 > $2
echo interface=$iface >> $2
echo 'bind-interfaces' >> $2
echo dhcp-range $1.100,$1.200,12h >> $2
echo dhcp-option=6,114.114.114.114,8.8.8.8 >> $2

ifconfig $iface $1.1 netmask 255.255.255.0

iptables -t -nat -A POSTROUTING -o $iface -j MASQUERADE
iptables-save > /etc/iptables/iptables.rules

cp ./$2 /etc/dnsmasq.conf
dnsmasq
echo 1 > /proc/sys/net/ipv4/ip_forward
