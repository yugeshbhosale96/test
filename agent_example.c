/*********************************************************************
*
* (C) Copyright Broadcom Corporation 2001-2015
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*
***********************************************************************
*
* @filename agent_example.c
*
* @purpose RESTful Web Service
* @detail  Example application that uses the OpEN API calls to query
*          VLAN and interface information, and then uses mongoose to
*          relay that information in a RESTful fashion via port 8080.
*
* @component Agent Example
*
* @note none
*
* @end
*
**********************************************************************/

#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include "rpcclt_openapi.h"
#include "mongoose.h"
#include "proc_util.h"
#include "openapi_vlan.h"
#include "openapi_stats.h"
#include "openapi_common.h"
#include "ah_hiveagent_debug.h"
#include "ah_hiveagent_types.h"
//#include "agent_example.h"

#define MAX_PORTS 48
#define CUR_MOD_NAME MOD_UTILS

ah_uint32_t mod_flag = TRACE_ALL_MOD;
ah_uint32_t debug_level = 0xFFFFFFFF;

openapiClientHandle_t client_handle;

#define LOG(level,fmt, ...)                                                                                          \
{                                                                                                                                       \
                        int d_level = level,d_size = -2;                                                                                \
                        const char * mod_str ;                                                                                          \
                        int     d_priority ;                                                                                            \
                        char d_logStr[OPENAPI_LOG_FORMAT_BUF_SIZE];                                                               	\
			memset(d_logStr,0,OPENAPI_LOG_FORMAT_BUF_SIZE);									\
                        open_buffdesc d_logBuffDesc;                                                                                    \
                        DISP_MOD_NAME                                                                                                   \
                        DISP_LOG_STR                                                                                                    \
                        d_size = snprintf(d_logStr, OPENAPI_LOG_FORMAT_BUF_SIZE-1, "%s %s:%d:  " fmt ,                                   \
                                        mod_str, __FILE__, __LINE__, ##__VA_ARGS__);                                                    \
                        d_logBuffDesc.pstart = d_logStr;                                                                                \
                        d_logBuffDesc.size =  d_size;                                                                           	\
                        openapiSysLogWrite((openapiClientHandle_t *)&client_handle,&d_logBuffDesc,d_priority);               		\
}

ah_int32_t ah_hiveagent_utils_resolve_hmng_hostname(ah_char_t* hmng_ip_address, ah_char_t *dns_hostname)
{
        open_error_t result = OPEN_E_NONE;
        ah_int32_t ret = 0;
        open_buffdesc hostname, ipaddress;
        ah_char_t hostname_str[OPENAPI_DNS_HOST_NAME_LEN_MAX];
        ah_int32_t fastpath_connect_attempt = 0;
        ah_int32_t rc = OPEN_E_NONE;

        static client_handle_dns_initialized = 0;

	if ((rc = openapiClientRegister ("hiveagent", &client_handle)) != OPEN_E_NONE) {
		return -1;
	}
	
	while (openapiConnectivityCheck (&client_handle) != OPEN_E_NONE)        {
		sleep (1);
		if( ++fastpath_connect_attempt == 10){
			break;
		}
	}

        memset(hostname_str, 0, sizeof(hostname_str));
        strncpy(hostname_str, dns_hostname, sizeof(hostname_str) - 1);

        hostname.pstart = hostname_str;
        hostname.size = OPENAPI_DNS_HOST_NAME_LEN_MAX;

        ipaddress.pstart = hmng_ip_address;
        ipaddress.size = 15;

        LOG(INFO_MAJOR,"url [%s]", "https://google.com/as%sasd");
        result = openapiDNSClientInetNameLookup(&client_handle, &hostname, &ipaddress);
        if(result != OPEN_E_NONE) {
                LOG(INFO_MAJOR,"Unable to resolve [%s] hostname. (result = %d)", dns_hostname, result);
		sleep(20);
		LOG(INFO_MAJOR,"url [%s]", "https://google.com/as%sasd");
                ret = -1;
        } else {
                LOG(INFO_MAJOR,"Resolved Ip is [%s]", hmng_ip_address);
		sleep(20);
		LOG(INFO_MAJOR,"url [%s]", "https://google.com/as%sasd");
        }
        return ret;
}

int
main (int argc, char *argv[])
{
  ah_char_t hostname[512];
  ah_char_t hmng_ip[15];

  strcpy(hostname, "google.com");
  memset (hmng_ip, 0, 15);

  ah_hiveagent_utils_resolve_hmng_hostname (hmng_ip, hostname);
}
