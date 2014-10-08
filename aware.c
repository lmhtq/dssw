#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aware.h"

/* SAP functions */
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

int main()
{
	printf("Hello Test!\n");
	return 0;
}