#include <stdio.h>
#include <windows.h>
#include <iphlpapi.h> // for GetAdaptersInfo

#pragma comment(lib, "ihplpapi.lib")
#pragma comment(lib, "ws2_32.lib")

// compile with
// gcc getNetworkInfo.c -o getNetworkInfo.exe -liphlpapi -lws2_32

int main() {

    IP_ADAPTER_INFO adapterInfo[16]; //room for 16 adapters
    DWORD buflen = sizeof(adapterInfo);

    DWORD status = GetAdaptersInfo(adapterInfo, &buflen);
    if (status != ERROR_SUCCESS) {
        printf("GetAdaptersInfo failed: %lu\n", status);
        return 1;
    }

    PIP_ADAPTER_INFO adapter = adapterInfo; //pointer to IP_ADAPTER_INFO
    //loop through each adapter one by one
    while (adapter) {

        printf("Adapter: %s\n", adapter->Description);

        //IpAddressList struct contains one or more IP addresses
        //this just prints the first ipv4 for adapter
        printf("IP Address: %s\n", adapter->IpAddressList.IpAddress.String);

        //Prints MAC address
        printf("MAC Address: ");
        for (UINT i = 0; i < adapter->AddressLength; i++) {
            printf("%02X", adapter->Address[i]);
            if (i < adapter->AddressLength - 1) {
                printf("-");
            }
        }
        printf("\n\n");

        //move to next adapter
        adapter = adapter->Next; //each adaper points to the next one
    }

    return 0;
}