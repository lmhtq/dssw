ifconfig wlp0s29u1u1 192.168.0.1 netmask 255.255.255.0 

#iptables
iptables -t nat -A POSTROUTING -o wlp2s0 -j MASQUERADE
#iptables-save
iptables-save > /etc/iptables/iptables.rules

cp ./dnsmasq.conf /etc/dnsmasq.conf

echo 1 > /proc/sys/net/ipv4/ip_forward