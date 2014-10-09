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
void set_sap_channel(void);

/* change a certain client's channel */
void change_client_channel(char *mac_client, int to_channel);

/* change subnet's channel */
void change_sap_channel(int to_channel);
