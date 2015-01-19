// Do not remove the include below
#include "mbed_httpclient_post_put.h"

#include"EthernetInterface.h"
#include"HTTPClient.h"
EthernetInterface eth;
HTTPClient http;
char str[512];
int ret = 0;
int main() 
{
    eth.init(); //Use DHCP
    eth.connect();
    //POST data
    HTTPMap map;
    HTTPText inText(str, 512);
   // map.put("temperature", "27.4");
    map.put("PRICE", "50");
    printf("\nTrying to post data...\n");
    //ret = http.post("http://www.thomas-bayer.com/sqlrest/PRODUCT/50/", map, &inText);
    ret = http.post("http://192.168.1.122/", map, &inText);
    if (!ret)
    {
        printf("Executed POST successfully - read %d characters\n", strlen(str));
        printf("Result: %s\n", str);
    }
    else
    {
        printf("Error - ret = %d - HTTP return code = %d\n", ret, http.getHTTPResponseCode());
    }
    //get data
    HTTPText outText(str);
    printf("\nTrying to fetch page...\n");
    ret = http.get("http://www.thomas-bayer.com/sqlrest/PRODUCT/50/", str, sizeof(str));
    if (!ret)
    {
      printf("Page fetched successfully - read %d characters\n", strlen(str));
      printf("Result: %s\n", str);
    }
    else
    {
      printf("Error - ret = %d - HTTP return code = %d\n", ret, http.getHTTPResponseCode());
    }

    //DELETE data

    eth.disconnect();
    while(1) {

    }

}
