#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aware.h"
#include "interact.h"


/* init a sap */
void init_sap(void)
{
	char cmd1[100] = "wpa_supplicant -Dnl80211 -i";
	char *cmd1_1 = " -c../netgear.conf -B";
	strcat(cmd1, iface);
	strcat(cmd1, cmd1_1);
	system(cmd1);

	char cmd2[100] = "dhclient -r ";
	strcat(cmd2, iface);
	system(cmd2);
	
	char cmd3[100] = "dhclient ";
	strcat(cmd3, iface);
	system(cmd3);
}

/* local control actions */
void handle_local_cmd(char *argv);

/* response fo the ac control actions */
void handle_ac_cmd(char *cmds)
{
	char mac[6];
	memcpy(mac, cmds, 6);
	if (strcmp(mac, self_mac) == 0) {
		switch cmds[6]
		{
			case 's' :
				set_sap_channel(cmds + 7);
			default :
				return;
		}

	}
}

/* set subnet's channel */
void set_sap_channel(char *cmds)
{
	char chan_num[4];
	memcpy(chan_num, cmds, 3);
	char cmdlines = "asaasffasfasfvasvgagv";
	system("");
}

/* upsend a sap's number of clients */
void upsend_clients_num(void);

/* upsend a sap's clients' info */
void upsend_clients_info(char *mac_client);

/* change a certain client's channel */
void change_client_channel(char *mac_client, int to_channel);

/* change subnet's channel */
void change_sap_channel(int to_channel);


/* AC */

/* init the ac */
void init_ac(void)
{
	/* to be implemented more */
	system("hostapd ap.conf");
}

/* local control actions */
void handle_local_cmd_ac(char *argv);

/* downsend a command */
void downsend_cmd(char *mac_sap, char *cmd);
{
	memcpy(buf, mac_sap, 6);
	strcat(buf, cmd);
	printf("%s\n", buf);

	send_to_server(buf);
}

/* process the recv info from sap */
void handle_sap_info(char *info);

/* command: set initial channel */
void cmd_set_channel(char *mac_sap, int to_channel);

/* command: change the channel of a sap and its subnet */
void cmd_change_sap_channel(char *mac_sap, int to_channel);

/* command: change a client to another channel */
void cmd_change_client_channel(char *mac_sap, int to_channel);



/* init Socket Client*/
void user_udp_init(void)
{
	bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("192.168.1.1");
	address.sin_port = htons(SERVERPORT);
	socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
	memset(buf, 0, sizeof(BUFFLEN));
}

/* init Socket Server*/
void server_udp_init()
{
	bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(SERVERPORT);
	socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
	bind(socket_descriptor, (struct sockaddr *)&address,
    		sizeof(address) );
	memset(buf, 0, sizeof(BUFFLEN));
}


/* destroy Socket Client/Server */
void user_udp_de_init()
{
    close(socket_descriptor);
}

/* send message to server */
void send_to_server(char *msg)
{
	sendto(socket_descriptor, msg, sizeof(msg), 0, 
           (struct sockaddr *)&address, sizeof(address));
}

/* receive from client */
void recv_from_client(char *msg)
{
	unsigned int len = sizeof(address);
	recvfrom(socket_descriptor, msg, 
		sizeof(msg), 0, (struct sockaddr *)&address,&len);
}