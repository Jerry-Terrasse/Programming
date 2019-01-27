#include<cstdio>
#include<cstring>
//#include "curl/curl.h"
//#include
//#include
int main(void)
{
  CURL *curl;
  CURLcode res;
  curl = curl_easy_init();
    char myurl[1000] = "http://api.fanyi.baidu.com/api/trans/vip/translate?";
    char *appid = "myAppid"; //replace myAppid with your own appid
    char *q = "apple"; //replace apple with your own text to be translate, ensure that the input text is encoded with UTF-8!
    char *from = "en"; //replace en with your own language type of input text
    char *to = "zh"; //replace zh with your own language type of output text
    char salt[60];
    int a = rand();
    sprintf(salt,"%d",a);
    char *secret_key = "mySecretKey"; //replace mySecretKey with your own mySecretKey
    char sign[120] = "";
    strcat(sign,appid);
    strcat(sign,q);
    strcat(sign,salt);
    strcat(sign,secret_key);
    printf("%s\n",sign);
    unsigned char md[16];
    int i;
    char tmp[3]={'\0'},buf[33]={'\0'};
    MD5((unsigned char *)sign,strlen((unsigned char *)sign),md);
    for (i = 0; i < 16; i++)
    {
      sprintf(tmp,"%2.2x",md[i]);
      strcat(buf,tmp);
    }
    printf("%s\n",buf);
    strcat(myurl,"appid=");
    strcat(myurl,appid);
    strcat(myurl,"&q=");
    strcat(myurl,q);
    strcat(myurl,"&from=");
    strcat(myurl,from);
    strcat(myurl,"&to=");
    strcat(myurl,to);
    strcat(myurl,"&salt=");
    strcat(myurl,salt);
    strcat(myurl,"&sign=");
    strcat(myurl,buf);
    printf("%s\n",myurl);
    //设置访问的地址
    curl_easy_setopt(curl, CURLOPT_URL, myurl);
    res = curl_easy_perform(curl);
  /* Check for errors */
  if(res != CURLE_OK)
    fprintf(stderr, "curl_easy_perform() failed: %s\n",
    curl_easy_strerror(res));
  /* always cleanup */
  curl_easy_cleanup(curl);
  return 0;
}