#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aware.h"

/* SAP functions */

//below no use
/* alloc a node */
void sap_sta_node_alloc(sap_sta_node *p_ssn)
{
	p_ssn = (sap_sta_node*)malloc(sizeof(sap_sta_node));
}

/* init a list */
void sap_sta_node_init(sap_sta_node *p_ssn)
{
	sap_sta_node_alloc(pHead);
	pHead->next = NULL;
}

/* insert a node */
void sap_sta_node_insert(sap_sta_node *p_ssn)
{
	sap_sta_node *node;
	sap_sta_node_alloc(node);
	node->next = pHead->next;
	pHead->next = node;
}

/* delete a node with a certaion mac address*/
void sap_sta_node_delete(char *s)
{
	sap_sta_node *p = pHead->next;
	while(strcmp(s,p->mac_addr) != 0 && p != NULL)
	{
		p = p->next;
	}
}

//above no use


/* get numbers of nodes */
int get_number_of_nodes(void)
{
	int numbers;
	FILE *fp = popen("iw dev wlp2s0 station dump | head -1 | awk \'{print $1}\'" ,"r");
	char tmp[10];
	int len = 32;
	fgets(tmp, len, fp);
	pclose(fp);
	sscanf(tmp, "%d", &numbers);
	//printf("%s\n", tmp);
	return numbers;
}

/* alloc n nodes */
void sap_sta_node_alloc_n(sap_sta_node *p_ssn, int n_node)
{
	p_ssn = (sap_sta_node*)malloc(n_node * sizeof(sap_sta_node));
}

/* free n nodes */
void sap_sta_node_free_n(sap_sta_node *p_ssn)
{
	free(p_ssn);
	p_ssn = NULL;
}


/* set n nodes a certain parameter */
void sap_sta_node_n_set_parameter(int numbers)
{
	FILE *fp = popen("iw dev wlp2s0 station dump | sed \'s/://g\' " ,"r");
	/*
	Station d0aeec9987e8 (on wlp2s0)
	inactive time	15196 ms
	rx bytes	18869519
	rx packets	180974
	tx bytes	41526
	tx packets	1629
	tx retries	1870
	tx failed	10
	signal  	-50 [-61, -51] dBm
	signal avg	-51 [-65, -51] dBm
	tx bitrate	1.0 MBit/s
	rx bitrate	130.0 MBit/s MCS 15
	authorized	yes
	authenticated	yes
	preamble	long
	WMM/WME	yes
	MFP		no
	TDLS peer	no
	*/
	char tmp[100];
	char tmp1[50], tmp2[50];
	int len = 100;
	int i;
	for(i = 0; i < numbers; i++)
	{
		fgets(tmp, len, fp);//Station d0aeec9987e8 (on wlp2s0)
		sscanf(tmp, "%s %x", tmp1, &pHead[i].mac_addr);

		fgets(tmp, len, fp);//inactive time	15196 ms
		
		fgets(tmp, len, fp);//rx bytes	18869519
		sscanf(tmp, "%s %s %d", tmp1, tmp2, &pHead[i].rx_bytes);
		
		fgets(tmp, len, fp);//rx packets	180974
		sscanf(tmp, "%s %s %d", tmp1, tmp2, &pHead[i].rx_packets);
		
		fgets(tmp, len, fp);//tx bytes	41526
		sscanf(tmp, "%s %s %d", tmp1, tmp2, &pHead[i].tx_bytes);

		fgets(tmp, len, fp);//tx packets	1629
		sscanf(tmp, "%s %s %d", tmp1, tmp2, &pHead[i].tx_packets);

		fgets(tmp, len, fp);//tx retries	1870
		
		fgets(tmp, len, fp);//tx failed	10
		
		fgets(tmp, len, fp);//signal  	-50 [-61, -51] dBm
		sscanf(tmp, "%s %d", tmp1, &pHead[i].signal);
		
		fgets(tmp, len, fp);//signal avg	-51 [-65, -51] dBm
		
		fgets(tmp, len, fp);//tx bitrate	1.0 MBit/s
		sscanf(tmp, "%s %s %f", tmp1, tmp2, &pHead[i].tx_bitrate);

		fgets(tmp, len, fp);//rx bitrate	130.0 MBit/s MCS 15
		sscanf(tmp, "%s %s %f", tmp1, tmp2, &pHead[i].rx_bitrate);


		fgets(tmp, len, fp);//authorized	yes
		fgets(tmp, len, fp);//authenticated	yes
		fgets(tmp, len, fp);//preamble	long
		fgets(tmp, len, fp);//WMM/WME	yes
		fgets(tmp, len, fp);//MFP		no
		fgets(tmp, len, fp);//TDLS peer	no
	}
	pclose(fp);
	//printf("%s\n", tmp);
}


/* AC */

/* get numbers of SAP */
int get_number_of_sap(void)
{
	int numbers;
	FILE *fp = popen("iw dev wlp2s0 station dump | head -1 | awk \'{print $1}\'" ,"r");
	char tmp[10];
	int len = 32;
	fgets(tmp, len, fp);
	pclose(fp);
	sscanf(tmp, "%d", &numbers);
	//printf("%s\n", tmp);
	return numbers;
}

/* allocate n SAPs */
void sap_node_alloc_n(sap_node *p_sn, int n_sap)
{
	p_sn = (sap_node*)malloc(n_sap * sizeof(sap_node));
}

/* free n SAPs */
void sap_node_free_n(sap_node *p_sn)
{
	free(p_sn);
	p_sn = NULL;
}

/* set n nodes with certain parameters */
void sap_node_n_set_parameter(int numbers)
{
	FILE *fp = popen("iw dev wlp2s0 station dump | sed \'s/://g\' " ,"r");
	/*
	Station d0aeec9987e8 (on wlp2s0)
	inactive time	15196 ms
	rx bytes	18869519
	rx packets	180974
	tx bytes	41526
	tx packets	1629
	tx retries	1870
	tx failed	10
	signal  	-50 [-61, -51] dBm
	signal avg	-51 [-65, -51] dBm
	tx bitrate	1.0 MBit/s
	rx bitrate	130.0 MBit/s MCS 15
	authorized	yes
	authenticated	yes
	preamble	long
	WMM/WME	yes
	MFP		no
	TDLS peer	no
	*/
	char tmp[100];
	char tmp1[50], tmp2[50];
	int len = 100;
	int i;
	for(i = 0; i < numbers; i++)
	{
		fgets(tmp, len, fp);//Station d0aeec9987e8 (on wlp2s0)
		sscanf(tmp, "%s %x", tmp1, &p_saphead[i].mac_addr);

		fgets(tmp, len, fp);//inactive time	15196 ms
		
		fgets(tmp, len, fp);//rx bytes	18869519
		sscanf(tmp, "%s %s %d", tmp1, tmp2, &p_saphead[i].rx_bytes);
		
		fgets(tmp, len, fp);//rx packets	180974
		sscanf(tmp, "%s %s %d", tmp1, tmp2, &p_saphead[i].rx_packets);
		
		fgets(tmp, len, fp);//tx bytes	41526
		sscanf(tmp, "%s %s %d", tmp1, tmp2, &p_saphead[i].tx_bytes);

		fgets(tmp, len, fp);//tx packets	1629
		sscanf(tmp, "%s %s %d", tmp1, tmp2, &p_saphead[i].tx_packets);

		fgets(tmp, len, fp);//tx retries	1870
		
		fgets(tmp, len, fp);//tx failed	10
		
		fgets(tmp, len, fp);//signal  	-50 [-61, -51] dBm
		sscanf(tmp, "%s %d", tmp1, &p_saphead[i].signal);
		
		fgets(tmp, len, fp);//signal avg	-51 [-65, -51] dBm
		
		fgets(tmp, len, fp);//tx bitrate	1.0 MBit/s
		sscanf(tmp, "%s %s %f", tmp1, tmp2, &p_saphead[i].tx_bitrate);

		fgets(tmp, len, fp);//rx bitrate	130.0 MBit/s MCS 15
		sscanf(tmp, "%s %s %f", tmp1, tmp2, &p_saphead[i].rx_bitrate);


		fgets(tmp, len, fp);//authorized	yes
		fgets(tmp, len, fp);//authenticated	yes
		fgets(tmp, len, fp);//preamble	long
		fgets(tmp, len, fp);//WMM/WME	yes
		fgets(tmp, len, fp);//MFP		no
		fgets(tmp, len, fp);//TDLS peer	no
	}
	pclose(fp);
	//printf("%s\n", tmp);
}

/* get the number of clients of a SAP */
void get_number_of_sap_clients(sap_node *p_saphead);


/* channel table */

/* allocate n channel table */
void channel_table_alloc_n(int numbers)
{
	p_channel_table = (channel_info*)malloc(numbers * sizeof(channel_info));
}

/* free n channel table */
void channel_table_free_n(channel_info *p_ct)
{
	free(p_ct);
	p_ct = NULL;
}


/* mapping table */

/* get sum number of clients */
int get_sum_of_clients(void);

/* generate a mapping table */
void generate_mapping_table(mapping_info *p_mt);

/* update a mapping table */
void update_mapping_table(mapping_info *p_mt);

int main()
{
	printf("Hello Test!\n");
	return 0;
}