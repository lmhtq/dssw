brtcl addbr br0
brtcl addif wlp0s29u1u1
brtcl setfd br0 0

ifconfig br0 set address 192.168.50.1 netmask 255.255.255.0
