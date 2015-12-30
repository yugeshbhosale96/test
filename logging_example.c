/*********************************************************************
*
* (C) Copyright Broadcom Corporation 2003-2015
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
**********************************************************************
*
* @filename  logging_example.c
*
* @purpose   Logging OpEN APIs Example 
*
* @component OpEN
*
* @comments
*
* @create    04/15/2013
*
* @end
*
**********************************************************************/
#include <stdlib.h>
#include <unistd.h>

#include "rpcclt_openapi.h"
#include "proc_util.h"
#include "openapi_common.h"
#include "openapi_logging.h"

/* 
   OpEN API set functions are processed asynchronously.  There may be some
   delay between when the set function call returns and when the system
   state is updated to reflect the change.  These parameters control how
   long the test code retries the get functions to retrieve a change.
*/


/*******************************************************************
*
* @brief  This function prints the Logging Example Application Menu.
*
* @param  none
*
* @returns  none
*
* @end
*********************************************************************/
void printLoggingAppMenu()
{
  printf("Usage: logging_example <test#> <arg1> <arg2> ... \n");
  printf("Test 1: Set CLI command logging mode:  logging_example 1 <mode> \n");
  printf("Test 2: Get CLI command logging mode: logging_example 2 \n");
  printf("Test 3: Set console logging mode: logging_example 3 <mode> \n");
  printf("Test 4: Get console logging mode: logging_example 4 \n");
  printf("Test 5: Set console logging severity level: logging_example 5 <severity-level> \n");
  printf("Test 6: Get console logging severity level: logging_example 6 \n");
  printf("Test 7: Set persistent logging mode: logging_example 7 <mode> \n");
  printf("Test 8: Get persistent logging mode: logging_example 8 \n");
  printf("Test 9: Set persistent logging severity level: logging_example 9 <severity-level>\n");
  printf("Test 10: Get persistent logging severity level: logging_example 10 \n");
  printf("Test 11: Set syslog mode: logging_example 11 <mode> \n");
  printf("Test 12: Get syslog mode: logging_example 12 \n");
  printf("Test 13: Set syslog port: logging_example 13 <syslog port> \n");
  printf("Test 14: Get syslog port: logging_example 14 \n");
  printf("Test 15: Add logging host: logging_example 15 <host address> \n");
  printf("Test 16: Set logging host port: logging_example 16 <host address> <port> \n");
  printf("Test 17: Set logging host severity level: logging_example 17 <host address> <severity-level> \n");
  printf("Test 18: Delete logging host: logging_example 18 <host address> \n");
  printf("Test 19: Show logging host details: logging_example 19 \n");
  printf("Test 20: Logging OpEN APIs Sanity: logging_example 20 \n");
  printf("Test 21: Logging openapiSysLogWrite API test: logging_example 21 \n");

  return;
}

/*******************************************************************
* @purpose Set CLI Command Logging Mode.
*
* @param  clientHandle     @{(input)} client handle from registration API
* @param  mode             @{(input)} CLI Command Logging Mode
*
* @returns  none
* 
* @notes  Calling this API will change the running configuration of the switch
* 
* @end
*********************************************************************/

void cliCommandLoggingModeSet(openapiClientHandle_t *clientHandle, OPEN_CONTROL_t mode)
{
  open_error_t result;

  if ((result = openapiCliCmdLoggingModeSet(clientHandle, mode)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to set CLI command Logging mode. (result = %d)\n", result);
  }
  else
  {
    printf("CLI command Logging mode is set successfully. (result = %d)\n", result);
  }

  return;
}

/*******************************************************************
* @purpose Get CLI Command Logging Mode.
*
* @param  clientHandle     @{(input)} client handle from registration API
*
* @returns  none
* 
* @notes
* 
* @end
*********************************************************************/
void cliCommandLoggingModeGet(openapiClientHandle_t *clientHandle)
{
  open_error_t result;
  OPEN_CONTROL_t mode;

  if ((result = openapiCliCmdLoggingModeGet(clientHandle, &mode)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to get CLI command Logging mode. (result = %d)\n", result);
  }
  else
  {
    printf("CLI command Logging Mode: ");
    if (mode == OPEN_ENABLE)
    {
      printf("Enable\n");
    }
    else
    {
      printf("Disable\n");
    }
  }

  return;
}

/*******************************************************************
* @purpose Set Console Logging Mode.
*
* @param  clientHandle     @{(input)} client handle from registration API
* @param  mode             @{(input)} Console Logging Mode
*
* @returns  none
* 
* @notes  Calling this API will change the running configuration of the switch
* 
* @end
*********************************************************************/
void consoleLoggingModeSet(openapiClientHandle_t *clientHandle, OPEN_CONTROL_t mode)
{
  open_error_t result;

  if ((result = openapiConsoleLoggingModeSet(clientHandle, mode)) != OPEN_E_NONE)
  {
    if (result == OPEN_E_EXISTS)
    {
      printf("Console Logging mode is already set to mode %d. (result = %d)\n", mode, result);
    }
    else
    {
      printf("Bad return code trying to set Console Logging mode. (result = %d)\n", result);
    }
  }
  else
  {
    printf("Console Logging mode is set successfully. (result = %d)\n", result);
  }

  return;
}

/*******************************************************************
* @purpose Get Console Logging Mode.
*
* @param  clientHandle     @{(input)} client handle from registration API
*
* @returns  none
* 
* @notes
* 
* @end
*********************************************************************/
void consoleLoggingModeGet(openapiClientHandle_t *clientHandle)
{
  open_error_t result;
  OPEN_CONTROL_t mode;

  if ((result = openapiConsoleLoggingModeGet(clientHandle, &mode)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to get Console Logging mode. (result = %d)\n", result);
  }
  else
  {
    printf("Console Logging Mode: ");
    if (mode == OPEN_ENABLE)
    {
      printf("Enable\n");
    }
    else
    {
      printf("Disable\n");
    }
  }

  return;
}

/*******************************************************************
* @purpose Set Console Logging Severity Level.
*
* @param  clientHandle     @{(input)} client handle from registration API
* @param  severity         @{(input)} Console Logging Severity Level
*
* @returns  none
* 
* @notes  Calling this API will change the running configuration of the switch
* 
* @end
*********************************************************************/
void consoleLoggingSeverityLevelSet(openapiClientHandle_t *clientHandle, OPEN_LOG_SEVERITY_t severity)
{
  open_error_t result;

  if ((result = openapiConsoleLoggingSeveritySet(clientHandle, severity)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to set Console Logging severity level. (result = %d)\n", result);
  }
  else
  {
    printf("Console Logging severity level is set successfully. (result = %d)\n", result);
  }

  return;
}

/*******************************************************************
* @purpose Get Console Logging Severity Level.
*
* @param  clientHandle     @{(input)} client handle from registration API
*
* @returns  none
* 
* @notes 
* 
* @end
*********************************************************************/
void consoleLoggingSeverityLevelGet(openapiClientHandle_t *clientHandle)
{
  open_error_t result;
  OPEN_LOG_SEVERITY_t severity;

  if ((result = openapiConsoleLoggingSeverityGet(clientHandle, &severity)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to get Console Logging severity level. (result = %d)\n", result);
  }
  else
  {
    printf("Console Logging severity level: %d\n", severity);
  }

  return;
}

/*******************************************************************
* @purpose Set Persistent Logging Mode.
*
* @param  clientHandle     @{(input)} client handle from registration API
* @param  mode             @{(input)} Persistent Logging Mode.
*
* @returns  none
* 
* @notes  Calling this API will change the running configuration of the switch
* 
* @end
*********************************************************************/
void persistentLoggingModeSet(openapiClientHandle_t *clientHandle, OPEN_CONTROL_t mode)
{
  open_error_t result;

  if ((result = openapiPersistentLoggingModeSet(clientHandle, mode)) != OPEN_E_NONE)
  {
    if (result == OPEN_E_EXISTS)
    {
      printf("Persistent Logging mode is already set to mode %d. (result = %d)\n", mode, result);
    }
    else if (result == OPEN_E_UNAVAIL)
    {
      printf("Persistent Logging Feature is not supported. (result = %d)\n", result);
    }
    else
    {
      printf("Bad return code trying to set Persistent Logging mode. (result = %d)\n", result);
    }
  }
  else
  {
    printf("Persistent Logging mode is set successfully. (result = %d)\n", result);
  }

  return;
}

/*******************************************************************
* @purpose Set Persistent Logging Severity Level
*
* @param  clientHandle     @{(input)} client handle from registration API
* @param  severity         @{(input)} Persistent Logging Severity Level
*
* @returns  none
* 
* @notes Calling this API will change the running configuration of the switch
* 
* @end
*********************************************************************/
void persistentLoggingSeverityLevelSet(openapiClientHandle_t *clientHandle, OPEN_LOG_SEVERITY_t severity)
{
  open_error_t result;

  if ((result = openapiPersistentLoggingSeverityLevelSet(clientHandle, severity)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to set Persistent Logging severity level. (result = %d)\n", result);
  }
  else
  {
    printf("Persistent Logging severity level is set successfully. (result = %d)\n", result);
  }

  return;
}

/*******************************************************************
* @purpose Get Persistent Logging Mode
*
* @param  clientHandle     @{(input)} client handle from registration API
*
* @returns  none
* 
* @notes
* 
* @end
*********************************************************************/
void persistentLoggingModeGet(openapiClientHandle_t *clientHandle)
{
  open_error_t result;
  OPEN_CONTROL_t mode;

  if ((result = openapiPersistentLoggingModeGet(clientHandle, &mode)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to get Persistent Logging mode. (result = %d)\n", result);
  }
  else
  {
    printf("Persistent Logging Mode: ");
    if (mode == OPEN_ENABLE)
    {
      printf("Enable\n");
    }
    else
    {
      printf("Disable\n");
    }
  }

  return;
}

/*******************************************************************
* @purpose Get Persistent Logging Severity Level
*
* @param  clientHandle     @{(input)} client handle from registration API
*
* @returns  none
* 
* @notes
* 
* @end
*********************************************************************/
void persistentLoggingSeverityLevelGet(openapiClientHandle_t *clientHandle)
{
  open_error_t result;
  OPEN_LOG_SEVERITY_t severity;

  if ((result = openapiPersistentLoggingSeverityLevelGet(clientHandle, &severity)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to get Persistent Logging severity level. (result = %d)\n", result);
  }
  else
  {
    printf("Persistent Logging severity level: %d\n", severity);
  }

  return;
}

/*******************************************************************
* @purpose Set Syslog Mode.
*
* @param  clientHandle     @{(input)} client handle from registration API
* @param  mode             @{(input)} Syslog Mode
*
* @returns  none
* 
* @notes  Calling this API will change the running configuration of the switch
* 
* @end
*********************************************************************/
void syslogModeSet(openapiClientHandle_t *clientHandle, OPEN_CONTROL_t mode)
{
  open_error_t result;

  if ((result = openapiSysLogModeSet(clientHandle, mode)) != OPEN_E_NONE)
  {
    if (result == OPEN_E_EXISTS)
    {
      printf("Syslog mode is already set to mode %d. (result = %d)\n", mode, result);
    }
    else
    {
      printf("Bad return code trying to set Syslog mode. (result = %d)\n", result);
    }
  }
  else
  {
    printf("Syslog mode is set successfully. (result = %d)\n", result);
  }
    
  return;
}

/*******************************************************************
* @purpose Get Syslog Mode.
*
* @param  clientHandle     @{(input)} client handle from registration API
*
* @returns  none
* 
* @notes 
* 
* @end
*********************************************************************/
void syslogModeGet(openapiClientHandle_t *clientHandle)
{
  open_error_t result;
  OPEN_CONTROL_t mode;

  if ((result = openapiSysLogModeGet(clientHandle, &mode)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to get Syslog mode. (result = %d)\n", result);
  }
  else
  {
    printf("Syslog Mode: ");
    if (mode == OPEN_ENABLE)
    {
      printf("Enable\n");
    }
    else
    {
      printf("Disable\n");
    }
  }

  return;
}

/*******************************************************************
* @purpose Set Syslog Port.
*
* @param  clientHandle     @{(input)} client handle from registration API
* param   port             @{(input)} Syslog Port
*
* @returns  none
* 
* @notes  Calling this API will change the running configuration of the switch
* 
* @end
*********************************************************************/
void syslogPortSet(openapiClientHandle_t *clientHandle, uint32_t port)
{
  open_error_t result;

  if ((result = openapiSysLogPortSet(clientHandle, port)) != OPEN_E_NONE)
  {
    if (result == OPEN_E_EXISTS)
    {
      if (port == 0)
      {
        printf("Syslog port is already set to default port . (result = %d)\n", result);
      }
      else
      {
        printf("Syslog port is already set to port %d. (result = %d)\n", port, result);
      }
    }
    else
    {
      printf("Bad return code trying to set Syslog port. (result = %d)\n", result);
    }
  }
  else
  {
    printf("Syslog port is set successfully. (result = %d)\n", result);
  }

  return;
}

/*******************************************************************
* @purpose Get Syslog Port.
*
* @param  clientHandle     @{(input)} client handle from registration API
*
* @returns  none
* 
* @notes 
* 
* @end
*********************************************************************/
void syslogPortGet(openapiClientHandle_t *clientHandle)
{
  open_error_t result;
  uint16_t port;

  if ((result = openapiSysLogPortGet(clientHandle, &port)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to get Syslog port. (result = %d)\n", result);
  }
  else
  {
    printf("Syslog port: %d.\n", port);
  }

  return;
}

/*********************************************************************
* @purpose  Add Logging Host.
*
* @param    clientHandle     @b{(input)}   client handle from registration API
* @param    hostAddress      @b{(input)}   Logging Host address
*
* @returns  none
* 
* @notes  Calling this API will change the running configuration of the switch
* 
* @end
*********************************************************************/
void loggingHostAdd(openapiClientHandle_t *clientHandle, char *hostAddress)
{
  open_error_t result;
  open_buffdesc buffdesc;
  char str[100];

  memset(str, 0, sizeof(str));
  strncpy(str, hostAddress, sizeof(str));
  buffdesc.pstart = str;
  buffdesc.size = strlen(str)+1;

  if ((result = openapiLoggingHostAdd(clientHandle, &buffdesc))  != OPEN_E_NONE)
  {
    printf("Bad return code trying to add Logging Host. (result = %d)\n", result);
  }
  else
  {
    printf("Logging host added successfully.(result = %d) \n", result);
  }

  return;
}

/*********************************************************************
* @purpose  Set Logging Host Port.
*
* @param    clientHandle     @b{(input)}   client handle from registration API
* @param    hostAddress      @b{(input)}   Logging Host address
* @param    port             @b{(input)}   Logging Host Port
*
* @returns  none
* 
* @notes  Calling this API will change the running configuration of the switch
* 
* @end
*********************************************************************/
void loggingHostPortSet(openapiClientHandle_t *clientHandle, char *hostAddress, uint32_t port)
{
  open_error_t result;
  open_buffdesc buffdesc;
  char str[100];

  memset(str, 0, sizeof(str));
  strncpy(str, hostAddress, sizeof(str));
  buffdesc.pstart = str;
  buffdesc.size = strlen(str)+1;

  if ((result = openapiLoggingHostPortSet(clientHandle, &buffdesc, port))  != OPEN_E_NONE)
  {
    printf("Bad return code trying to set logging host port. (result = %d)\n", result);
  }
  else
  {
    printf("Logging host port is set successfully.(result = %d) \n", result);
  }

  return;
}

/*********************************************************************
* @purpose  Set Logging Host Severity Level.
*
* @param    clientHandle     @b{(input)}   client handle from registration API
* @param    hostAddress      @b{(input)}   Logging Host address
* @param    severity         @b{(input)}   Logging Host Severity Level
*
* @returns  none
* 
* @notes  Calling this API will change the running configuration of the switch
* 
* @end
*********************************************************************/
void loggingHostSeveritySet(openapiClientHandle_t *clientHandle, char *hostAddress, OPEN_LOG_SEVERITY_t severity)
{
  open_error_t result;
  open_buffdesc buffdesc;
  char str[100];

  memset(str, 0, sizeof(str));
  strncpy(str, hostAddress, sizeof(str));
  buffdesc.pstart = str;
  buffdesc.size = strlen(str)+1;

  if ((result = openapiLoggingHostSeveritySet(clientHandle, &buffdesc, severity)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to set logging host severity level. (result = %d)\n", result);
  }
  else
  {
    printf("Logging host severity level is set successfully.(result = %d) \n", result);
  }

  return;
}

/*********************************************************************
* @purpose  Delete Logging Host.
*
* @param    clientHandle     @b{(input)}   client handle from registration API
* @param    hostAddress      @b{(input)}   Logging Host address
*
* @returns  none
* 
* @notes  Calling this API will change the running configuration of the switch
* 
* @end
*********************************************************************/
void loggingHostDelete(openapiClientHandle_t *clientHandle, char *hostAddress)
{
  open_error_t result;
  open_buffdesc buffdesc;
  char str[100];

  memset(str, 0, sizeof(str));
  strncpy(str, hostAddress, sizeof(str));
  buffdesc.pstart = str;
  buffdesc.size = strlen(str)+1;
  
  if ((result = openapiLoggingHostRemove(clientHandle, &buffdesc)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to delete logging host. (result = %d)\n", result);
  }
  else
  { 
    printf("Logging host is deleted successfully.(result = %d) \n", result);
  } 
    
  return;
}

/*********************************************************************
* @purpose  Get Logging information
* 
* @param    clientHandle     @b{(input)}   client handle from registration API
* 
* @returns  none
* 
* @notes 
* 
* @end
*********************************************************************/
void loggingHostInfoGet(openapiClientHandle_t *clientHandle)
{
  open_error_t result;
  open_buffdesc buffdesc;
  char *str;
  uint32_t loggingHostMaxAddrLen = 0;
  uint32_t maxLoggingHosts = 0;
  uint16_t port;
  OPEN_LOG_SEVERITY_t severity;
  

  if ((result = openapiLoggingHostMaxAddrLenGet(clientHandle, &loggingHostMaxAddrLen)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to get logging host maximum address length. (result = %d)\n", result);
    return;
  }

  if ((str = malloc(loggingHostMaxAddrLen)) == NULL)
  {
    printf("Could not allocate memory.\n");
    return;
  }

  memset(str, 0, sizeof(str));
  buffdesc.pstart = str;
  buffdesc.size = loggingHostMaxAddrLen;

  if ((result = openapiLoggingHostIpAddrNextGet(clientHandle, &buffdesc)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to get first logging host. (result = %d)\n", result);
    free(str);
    return;
  }

  if ((result = openapiMaxLoggingHostsSupportedGet(clientHandle, &maxLoggingHosts)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to get maximum Logging Hosts supported. (result = %d)\n", result);
  }
  else
  {
    printf("Maximum Logging Hosts supported: %d\n", maxLoggingHosts);
  }

  printf("\n");
  do
  {
    printf("Logging Host Address: %s\n", (char *) buffdesc.pstart);

    printf("Port: ");
    if ((result = openapiLoggingHostPortGet(clientHandle, &buffdesc, &port)) != OPEN_E_NONE)
    {
      printf("Bad return code trying to get logging host port. (result = %d)\n", result);
    }
    else
    {
      printf("%d\n", port);
    }

    printf("Severity Level: ");
    if ((result = openapiLoggingHostSeverityGet(clientHandle, &buffdesc, &severity)) != OPEN_E_NONE)
    {
      printf("Bad return code trying to get logging host severity. (result = %d)\n", result);
    }
    else
    {
      printf("%d\n", severity);
    }

    printf("\n");
    buffdesc.size = loggingHostMaxAddrLen;
  }while(openapiLoggingHostIpAddrNextGet(clientHandle, &buffdesc) == OPEN_E_NONE);

  free(str);
  return;  
}

/*********************************************************************
* @purpose  Logging Host OpEN API Sanity.
*
* @param    clientHandle     @b{(input)}   client handle from registration API
*
* @returns  none
* 
* @notes
* 
* @end
*********************************************************************/
void loggingOpENAPIsSanity(openapiClientHandle_t *clientHandle)
{
  open_error_t result;
  open_buffdesc buffdesc;
  char *str;
  uint32_t loggingHostMaxAddrLen = 0;
  uint32_t maxLoggingHosts = 0;
  uint16_t port = 0;
  OPEN_CONTROL_t mode = OPEN_DISABLE;
  OPEN_LOG_SEVERITY_t severity = OPEN_LOG_SEVERITY_UNDEFINED; 

  if ((result = openapiLoggingHostMaxAddrLenGet(clientHandle, &loggingHostMaxAddrLen)) != OPEN_E_NONE)
  {
    printf("Bad return code trying to get logging host maximum address length. (result = %d)\n", result);
    return;
  }

  if ((str = malloc(loggingHostMaxAddrLen)) == NULL)
  {
    printf("Could not allocate memory.\n");
    return;
  }

  memset(str, 0, sizeof(str));
  buffdesc.pstart = str;
  buffdesc.size = loggingHostMaxAddrLen;

  /* openapiCliCmdLoggingModeSet() */
  printf("\nTesting openapiCliCmdLoggingModeSet(): \n");

  result = openapiCliCmdLoggingModeSet(NULL, mode);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiCliCmdLoggingModeSet(clientHandle, 10);
  printf("Invalid CLI command Logging mode. (result = %d)\n", result);

  printf("openapiCliCmdLoggingModeSet() sanity successful.\n");

  /* openapiCliCmdLoggingModeGet() */
  printf("\nTesting openapiCliCmdLoggingModeGet(): \n");

  result = openapiCliCmdLoggingModeGet(NULL, &mode);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiCliCmdLoggingModeGet(clientHandle, NULL);
  printf("NULL CLI command Logging mode. (result = %d)\n", result);

  printf("openapiCliCmdLoggingModeGet() sanity successful.\n");

  /* openapiConsoleLoggingModeSet() */ 
  printf("\nTesting openapiConsoleLoggingModeSet(): \n");

  result = openapiConsoleLoggingModeSet(NULL, mode);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiConsoleLoggingModeSet(clientHandle, 4);
  printf("Invalid Command Logging mode. (result = %d)\n", result);

  printf("openapiConsoleLoggingModeSet() sanity successful.\n");

  /* openapiConsoleLoggingModeGet() */
  printf("\nTesting openapiConsoleLoggingModeGet(): \n");

  result = openapiConsoleLoggingModeGet(NULL, &mode);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiConsoleLoggingModeGet(clientHandle, NULL);
  printf("NULL Command Logging mode. (result = %d)\n", result);

  printf("openapiConsoleLoggingModeGet() sanity successful.\n");

  /* openapiConsoleLoggingSeveritySet() */
  printf("\nTesting openapiConsoleLoggingSeveritySet(): \n");

  result = openapiConsoleLoggingSeveritySet(NULL, severity);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiConsoleLoggingSeveritySet(clientHandle, 10);
  printf("Invalid Console Logging Severity Level . (result = %d)\n", result);

  printf("openapiConsoleLoggingSeveritySet() sanity successful.\n");

  /* openapiConsoleLoggingSeverityGet() */
  printf("\nTesting openapiConsoleLoggingSeverityGet(): \n");

  result = openapiConsoleLoggingSeverityGet(NULL, &severity);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiConsoleLoggingSeverityGet(clientHandle, NULL);
  printf("NULL Console Logging Severity Level . (result = %d)\n", result);

  printf("openapiConsoleLoggingSeverityGet() sanity successful.\n"); 

  /* openapiPersistentLoggingModeSet() */
  printf("\nTesting openapiPersistentLoggingModeSet(): \n");

  result = openapiPersistentLoggingModeSet(NULL, mode);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiPersistentLoggingModeSet(clientHandle, 10);
  printf("Invalid Persistent Logging mode. (result = %d)\n", result);

  printf("openapiPersistentLoggingModeSet() sanity successful.\n");

  /* openapiPersistentLoggingSeverityLevelSet() */
  printf("\nTesting openapiPersistentLoggingSeverityLevelSet(): \n");

  result = openapiPersistentLoggingSeverityLevelSet(NULL, severity); 
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiPersistentLoggingSeverityLevelSet(clientHandle, 20);
  printf("Invalid Persistent Logging Severity Level . (result = %d)\n", result);

  printf("openapiPersistentLoggingSeverityLevelSet() sanity successful.\n");
 
  /* openapiPersistentLoggingModeGet() */
  printf("\nTesting openapiPersistentLoggingModeGet(): \n");

  result = openapiPersistentLoggingModeGet(NULL, &mode);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiPersistentLoggingModeGet(clientHandle, NULL);
  printf("NULL Persistent Logging Mode. (result = %d)\n", result);

  printf("openapiPersistentLoggingModeGet() sanity successful.\n");

  /* openapiPersistentLoggingSeverityLevelGet() */
  printf("\nTesting openapiPersistentLoggingSeverityLevelGet(): \n");

  result = openapiPersistentLoggingSeverityLevelGet(NULL, &severity);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiPersistentLoggingSeverityLevelGet(clientHandle, NULL);
  printf("NULL Persistent LoggingSeverity Level. (result = %d)\n", result);

  printf("openapiPersistentLoggingSeverityLevelGet() sanity successful.\n");

  /* openapiSysLogModeSet() */ 
  printf("\nTesting openapiSysLogModeSet(): \n");

  result = openapiSysLogModeSet(NULL, mode);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiSysLogModeSet(clientHandle, 5);
  printf("Invalid syslog mode. (result = %d)\n", result);

  printf("openapiSysLogModeSet() sanity successful.\n");

  /* openapiSysLogModeGet() */ 
  printf("\nTesting openapiSysLogModeGet(): \n");

  result = openapiSysLogModeGet(NULL, &mode);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiSysLogModeGet(clientHandle, NULL);
  printf("NULL syslog mode. (result = %d)\n", result);

  printf("openapiSysLogModeGet() sanity successful.\n");

  /* openapiSysLogPortSet() */
  printf("\nTesting openapiSysLogPortSet(): \n");

  result = openapiSysLogPortSet(NULL, port);
  printf("NULL Client Handle. (result = %d)\n", result);

  printf("openapiSysLogPortSet() sanity successful.\n");

  /* openapiSysLogPortGet() */
  printf("\nTesting openapiSysLogPortGet(): \n");

  result = openapiSysLogPortGet(NULL, &port);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiSysLogPortGet(clientHandle, NULL);
  printf("NULL syslog port. (result = %d)\n", result);

  printf("openapiSysLogPortGet() sanity successful.\n");

  /* openapiLoggingHostAdd() */ 
  printf("\nTesting openapiLoggingHostAdd(): \n");

  result = openapiLoggingHostAdd(NULL, &buffdesc);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiLoggingHostAdd(clientHandle, NULL);
  printf("NULL buff descriptor. (result = %d)\n", result);

  printf("openapiLoggingHostAdd() sanity successful.\n");

  /* openapiLoggingHostPortSet() */ 
  printf("\nTesting openapiLoggingHostPortSet(): \n");

  result = openapiLoggingHostPortSet(NULL, &buffdesc, port);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiLoggingHostPortSet(clientHandle, NULL, port);
  printf("NULL buff descriptor. (result = %d)\n", result);

  printf("openapiLoggingHostPortSet() sanity successful.\n");

  /* openapiLoggingHostSeveritySet() */
  printf("\nTesting openapiLoggingHostSeveritySet(): \n");

  result = openapiLoggingHostSeveritySet(NULL, &buffdesc, severity);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiLoggingHostSeveritySet(clientHandle, NULL, severity);
  printf("NULL buff descriptor. (result = %d)\n", result);

  result = openapiLoggingHostSeveritySet(clientHandle, &buffdesc, 10);
  printf("Invalid logging host severity level. (result = %d)\n", result);

  printf("openapiLoggingHostSeveritySet() sanity successful.\n");  
 
  /* openapiLoggingHostIpAddrNextGet() */
  printf("\nTesting openapiLoggingHostIpAddrNextGet(): \n");

  result = openapiLoggingHostIpAddrNextGet(NULL, &buffdesc);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiLoggingHostIpAddrNextGet(clientHandle, NULL);
  printf("NULL buff descriptor. (result = %d)\n", result);

  /* openapiLoggingHostSeverityGet() */
  printf("\nTesting openapiLoggingHostSeverityGet(): \n");

  result = openapiLoggingHostSeverityGet(NULL, &buffdesc, &severity);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiLoggingHostSeverityGet(clientHandle, NULL, &severity);
  printf("NULL buff descriptor. (result = %d)\n", result);

  result = openapiLoggingHostSeverityGet(clientHandle, &buffdesc, NULL);
  printf("NULL Logging host severity level. (result = %d)\n", result);

  printf("openapiLoggingHostSeverityGet() sanity successful.\n");

  /* openapiLoggingHostPortGet() */
  printf("\nTesting openapiLoggingHostPortGet(): \n");
  result = openapiLoggingHostPortGet(NULL, &buffdesc, &port);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiLoggingHostPortGet(clientHandle, NULL, &port);
  printf("NULL buff descriptor. (result = %d)\n", result);
  
  result = openapiLoggingHostPortGet(clientHandle, &buffdesc, NULL);
  printf("NULL Logging host port. (result = %d)\n", result);

  printf("openapiLoggingHostPortGet() sanity successful.\n");

  /* openapiLoggingHostRemove() */
  printf("\nTesting openapiLoggingHostRemove(): \n");
  result = openapiLoggingHostRemove(NULL, &buffdesc);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiLoggingHostRemove(clientHandle, NULL);
  printf("NULL buff descriptor. (result = %d)\n", result);

  printf("openapiLoggingHostRemove() sanity successful.\n");

  /* openapiMaxLoggingHostsSupportedGet() */
  printf("\nTesting openapiMaxLoggingHostsSupportedGet(): \n");

  result = openapiMaxLoggingHostsSupportedGet(NULL, &maxLoggingHosts);
  printf("NULL Client Handle. (result = %d)\n", result);

  result = openapiMaxLoggingHostsSupportedGet(clientHandle, NULL);
  printf("NULL maximum logging hosts. (result = %d)\n", result);

  printf("openapiMaxLoggingHostsSupportedGet() sanity successful.\n");

  /* openapiLoggingHostMaxAddrLenGet() */
  printf("\nTesting openapiLoggingHostMaxAddrLenGet(): \n");

  result = openapiLoggingHostMaxAddrLenGet(NULL, &loggingHostMaxAddrLen);
  printf("NULL Client Handle. (result = %d)\n", result);
  
  result = openapiLoggingHostMaxAddrLenGet(clientHandle, NULL);
  printf("NULL logging host maximum address length. (result = %d)\n", result);

  printf("openapiLoggingHostMaxAddrLenGet() sanity successful.\n");

  free(str);
  return;
}

#define LOG(fmt, ...)                                                                                          \
{                                                                                                                                       \
                        int d_size = -2;                                                                                \
                        char d_logStr[OPENAPI_LOG_FORMAT_BUF_SIZE];                                                                     \
                        memset(d_logStr,0,OPENAPI_LOG_FORMAT_BUF_SIZE);                                                                 \
                        open_buffdesc d_logBuffDesc;                                                                                    \
                        d_size = snprintf(d_logStr, OPENAPI_LOG_FORMAT_BUF_SIZE-1, "%s %s:%d:  " fmt ,                                   \
                                        "MOD_UTIL", __FILE__, __LINE__, ##__VA_ARGS__);                                                    \
                        d_logBuffDesc.pstart = d_logStr;                                                                                \
                        d_logBuffDesc.size =  d_size;                                                                                   \
                        openapiSysLogWrite((openapiClientHandle_t *)&clientHandle,&d_logBuffDesc,OPEN_LOG_SEVERITY_ERROR);             \
}


/*******************************************************************
*
* @brief  This is the main() function of the example application that
*         demonstrates OpEN APIs for user configuration.
*
* @returns  0: Success
* @returns  1: Failure if the number of arguments are incorrect
* @returns  2: Other internal failure
*
*********************************************************************/
int main(int argc, char **argv)
{
  openapiClientHandle_t clientHandle;
  open_error_t result;
  uint32_t testNum, arg1;
  open_buffdesc switch_os_revision;
  char switch_os_revision_string[100];
  
  if (argc < 2)
  {
    printLoggingAppMenu();
    exit(1);
  }

  testNum = atoi(argv[1]);

  l7proc_crashlog_register();

  /* Register with OpEN */
  if ((result = openapiClientRegister("logging_example", &clientHandle)) != OPEN_E_NONE)
  {
    printf("\nFailed to initialize RPC to OpEN. Exiting (result = %d)\n", result);
    exit(2);
  }

  /* RPC call can fail until server starts. Keep trying */
  while (openapiConnectivityCheck(&clientHandle) != OPEN_E_NONE)
  {
    sleep(1);
  }

  L7PROC_LOGF(L7PROC_LOG_SEVERITY_INFO, 0, "Starting logging API example application");

  printf("\n");
  switch_os_revision.pstart = switch_os_revision_string;
  switch_os_revision.size = sizeof(switch_os_revision_string);
  if (openapiNetworkOSVersionGet(&clientHandle, &switch_os_revision) == OPEN_E_NONE)
    printf("ICOS version = %s\n", switch_os_revision_string);
  else
    printf("Network OS Version retrieve error\n");

  printf("\n");

  switch (testNum)
  {
    case 1:
      if (argc != 3)
      {
        printLoggingAppMenu();
        exit(1);
      }
      arg1 = atoi(argv[2]);
      cliCommandLoggingModeSet(&clientHandle, arg1);
      break;
    case 2:
      if (argc != 2)
      {
        printLoggingAppMenu();
        exit(1);
      }
      cliCommandLoggingModeGet(&clientHandle);
      break;
    case 3:
      if (argc != 3)
      {
        printLoggingAppMenu();
        exit(1);
      }
      arg1 = atoi(argv[2]);
      consoleLoggingModeSet(&clientHandle, arg1);
      break;
    case 4:
      if (argc != 2)
      {
        printLoggingAppMenu();
        exit(1);
      }
      consoleLoggingModeGet(&clientHandle);
      break;
    case 5:
      if (argc != 3)
      {
        printLoggingAppMenu();
        exit(1);
      }
      arg1 = atoi(argv[2]);
      consoleLoggingSeverityLevelSet(&clientHandle, arg1);
      break;
    case 6:
      if (argc != 2)
      {
        printLoggingAppMenu();
        exit(1);
      }
      consoleLoggingSeverityLevelGet(&clientHandle);
      break;
    case 7:
      if (argc != 3)
      {
        printLoggingAppMenu();
        exit(1);
      }
      arg1 = atoi(argv[2]);
      persistentLoggingModeSet(&clientHandle, arg1);
      break;      
    case 8:
      if (argc != 2)
      {
        printLoggingAppMenu();
        exit(1);
      }
      persistentLoggingModeGet(&clientHandle);
      break;
    case 9:
      if (argc != 3)
      {
        printLoggingAppMenu();
        exit(1);
      }
      arg1 = atoi(argv[2]);
      persistentLoggingSeverityLevelSet(&clientHandle, arg1);
      break;
    case 10:
      if (argc != 2)
      {
        printLoggingAppMenu();
        exit(1);
      }
      persistentLoggingSeverityLevelGet(&clientHandle);
      break;
    case 11:
      if (argc != 3)
      {
        printLoggingAppMenu();
        exit(1);
      }
      arg1 = atoi(argv[2]); 
      syslogModeSet(&clientHandle, arg1);
      break;
    case 12:
      if (argc != 2)
      {
        printLoggingAppMenu();
        exit(1);
      }
      syslogModeGet(&clientHandle);
      break;
    case 13:
      if (argc != 3)
      {
        printLoggingAppMenu();
        exit(1);
      }
      arg1 = atoi(argv[2]);
      syslogPortSet(&clientHandle, arg1);
      break;
    case 14:
      if (argc != 2)
      {
        printLoggingAppMenu();
        exit(1);
      }
      syslogPortGet(&clientHandle);
      break;
    case 15:
      if (argc != 3)
      {
        printLoggingAppMenu();
        exit(1);
      }
      loggingHostAdd(&clientHandle, argv[2]);
      break;
    case 16:
      if (argc != 4)
      {
        printLoggingAppMenu();
        exit(1);
      }
      arg1 = atoi(argv[3]);
      loggingHostPortSet(&clientHandle, argv[2], arg1);
      break;
    case 17:
      if (argc != 4)
      {
        printLoggingAppMenu();
        exit(1);
      }
      arg1 = atoi(argv[3]);
      loggingHostSeveritySet(&clientHandle, argv[2], arg1);
      break;
    case 18:
      if (argc != 3)
      {
        printLoggingAppMenu();
        exit(1);
      }
      loggingHostDelete(&clientHandle, argv[2]);
      break;
    case 19:
      if (argc != 2)
      {
        printLoggingAppMenu();
        exit(1);
      }
      loggingHostInfoGet(&clientHandle);
      break;
    case 20:
      if (argc != 2)
      {
        printLoggingAppMenu();
        exit(1);
      }
      loggingOpENAPIsSanity(&clientHandle);
      break;
    case 21:
      if (argc != 2)
      {
        printLoggingAppMenu();
        exit(1);
      }
        open_error_t result = OPEN_E_NONE;
        open_buffdesc hostname, ipaddress;
        char hostname_str[OPENAPI_DNS_HOST_NAME_LEN_MAX];
	char hmng_ip[15];
        int rc = OPEN_E_NONE;


        memset(hostname_str, 0, sizeof(hostname_str));
        strncpy(hostname_str, "google.com", sizeof(hostname_str) - 1);

        hostname.pstart = hostname_str;
        hostname.size = OPENAPI_DNS_HOST_NAME_LEN_MAX;
	memset (hmng_ip, 0, 15);
        ipaddress.pstart = hmng_ip;
        ipaddress.size = 15;

        LOG("url [%s]", "https://google.com/as%sasd");
        result = openapiDNSClientInetNameLookup(&clientHandle, &hostname, &ipaddress);
        if(result != OPEN_E_NONE) {
                LOG("Unable to resolve [%s] hostname. (result = %d)", "google.com", result);
                sleep(20);
                LOG("url [%s]", "https://google.com/as%sasd");
        } else {
                LOG("Resolved Ip is [%s]", ipaddress);
                sleep(20);
                LOG("url [%s]", "https://google.com/as%sasd");
        }
      break;
    default:
      printLoggingAppMenu();
      break;
  }

  /* Log goodbye message with OpEN */
  L7PROC_LOGF(L7PROC_LOG_SEVERITY_INFO, 0, "Stopping logging API example application");

  return 0;
}
