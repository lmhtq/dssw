#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SAP */

/* init a sap */
void init_sap(void);

/* local control actions */
void handle_local_cmd(char *argv);

/* response fo the ac control actions */
void handle_ac_cmd(char *cmds);

/* set subnet's channel */
void set_sap_channel(char *cmds);

/* upsend a sap's number of clients */
void upsend_clients_num(char *cmds);

/* upsend a sap's clients' info */
void upsend_clients_info(char *mac_client);

/* change a certain client's channel */
void change_client_channel(char *mac_client, int to_channel);

/* change subnet's channel */
void change_sap_channel(int to_channel);


/* AC */

/* init the ac */
void init_ac(void);

/* local control actions */
void handle_local_cmd_ac(char *argv);

/* downsend a command */
void downsend_cmd(char *mac_sap, char *cmd);

/* process the recv info from sap */
void handle_sap_info(char *info);

/* command: set initial channel*/
void cmd_set_channel(char *mac_sap, int to_channel);

/* command: change the channel of a sap and its subnet */
void cmd_change_sap_channel(char *mac_sap, int to_channel);

/* command: change a client to another channel */
void cmd_change_client_channel(char *mac_sap, int to_channel);


/* UDP */
#define BUFFLEN 1024
#define SERVERIP "192.168.1.1"
#define SERVERPORT 9091

/*Socket*/
char buf[BUFFLEN];
int socket_descriptor;
struct sockaddr_in address;

/* init Socket Client*/
void user_udp_init(void);

/*init Socket Server*/
void server_udp_init();

/*destroy Socket Client/Server */
void user_udp_de_init();
