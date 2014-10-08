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

