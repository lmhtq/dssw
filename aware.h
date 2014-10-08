#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;
#define RATENUM 128

/* client's info of a SAP */
typedef struct station_node
{
	/* supported rates */
	uchar rate[RATENUM];

	/* mac address */
	char mac_addr[6];

	/* tx,rx */
	int rx_bytes;
	int tx_bytes;
	int rx_packets;
	int tx_packets;
	float rx_bitrate;
	float tx_bitrate;

	/* signal */
	int signal;
	int signal_avg;

	/* frame length */


	/* last node */
	struct station_node* next;
} sap_sta_node;

sap_sta_node *pHead;

/* alloc a node */
void sap_sta_node_alloc(sap_sta_node *p_ssn);

/* init a list */
void sap_sta_node_init(sap_sta_node *p_ssn);

/* insert a node */
void sap_sta_node_insert(sap_sta_node *p_ssn);

/* delete a node with a certaion mac address*/
void sap_sta_node_delete(char *s);

/* get numbers of nodes */
int get_number_of_nodes(void);

/* alloc n nodes */
void sap_sta_node_alloc_n(sap_sta_node *p_ssn, int n_node);

/* free n nodes */
void sap_sta_node_free_n(sap_sta_node *p_ssn);

/* set n nodes a certain parameter */
void sap_sta_node_n_set_parameter(int numbers);



/* SAP's info of a AC */
typedef struct sap_node
{
	/* supported rates */
	uchar rate[RATENUM];

	/* mac address */
	char mac_addr[6];

	/* tx,rx */
	int rx_bytes;
	int tx_bytes;
	int rx_packets;
	int tx_packets;
	float rx_bitrate;
	float tx_bitrate;

	/* signal */
	int signal;
	int signal_avg;

	/* frame length */


	/* client of a SAP*/
	struct station_node *pclient;
} sap_node;

/* head pointer*/
sap_node *p_saphead;

/* number of SAP */
int numbers_of_sap;

/* get numbers of SAP */
int get_number_of_sap(void);

/* allocate n SAPs */
void sap_node_alloc_n(sap_node *p_sn);

/* free n SAPs */
void sap_node_free_n(sap_node *p_sn);

/* set n nodes with certain parameters */
void sap_node_n_set_parameter(int numbers);


/* channel table */
typedef struct chan_info
{
	char mac_sap[6]; //sap's mac address
	int channel;		//sap's current channel
} channel_info;

channel_info *p_channel_table;

/* allocate n channel table */
void channel_table_alloc_n(int numbers);

/* free n channel table */
void channel_table_free_n(channel_info *p_ct);

/* mapping table */
typedef struct map
{
	char mac_master[6];
	char mac_client[6];	
} mapping_info;

mapping_info *p_mapping_table;

/* get sum number of clients */
int get_sum_of_clients()