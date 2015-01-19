// Do not remove the include below
#include "mbe_http_client.h"

#include"EthernetInterface.h"
#include"HTTPClient.h"
EthernetInterface eth;
HTTPClient http;
char str[512];
int main()
{
    eth.init(); //Use DHCP
    eth.connect();
    printf("\nTrying to fetch page...\n");
    int ret = http.get("http://mbed.org/", str, sizeof(str));
    if (!ret)
    {
      printf("Page fetched successfully - read %d characters\n", strlen(str));
      printf("Result: %s\n", str);
    }
    else
    {
      printf("Error - ret = %d - HTTP return code = %d\n", ret, http.getHTTPResponseCode());
}
    eth.disconnect();
    while(1) {
    }
}
