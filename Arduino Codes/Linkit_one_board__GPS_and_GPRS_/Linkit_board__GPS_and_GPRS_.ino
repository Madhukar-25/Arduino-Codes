
#include <LGPS.h>
#include <LGPRS.h>
#include <LGPRSClient.h>
#include <LGPRSServer.h>

unsigned long previous = 0;
const long interval = 60000;// give the desired interval in ms 

int key1 = 7;
int key2 = 6;
int key3 = 5;
int key4 = 4;

char server[] = "Your_website";
char path[] = "Your_path";
int port = 80; // HTTPS

LGPRSClient client;

gpsSentenceInfoStruct info;
char buff[256];
String a1;
String a2;

void chkloc()
{
  LGPS.getData(&info);
  parseGPGGA((const char*)info.GPGGA);
  while(client.available())
  {
    char  c = client.read();
    Serial.print(c);
  }
  
}

static unsigned char getComma(unsigned char num,const char *str)
{
  unsigned char i,j = 0;
  int len=strlen(str);
  for(i = 0;i < len;i ++)
  {
     if(str[i] == ',')
      j++;
     if(j == num)
      return i + 1; 
  }
  return 0; 
}

static double getDoubleNumber(const char *s)
{
  char buf[10];
  unsigned char i;
  double rev;
  
  i=getComma(1, s);
  i = i - 1;
  strncpy(buf, s, i);
  buf[i] = 0;
  rev=atof(buf);
  return rev; 
}

void parseGPGGA(const char* GPGGAstr)
{
  Serial.println(" inside PARSE GPGGA");
  double latitude;
  double longitude;
  int tmp, hour, minute, second, num ;
  Serial.println(GPGGAstr);
  if(GPGGAstr[0] == '$')
  {
    tmp = getComma(1, GPGGAstr);
    tmp = getComma(2, GPGGAstr);
    latitude = getDoubleNumber(&GPGGAstr[tmp]);
    tmp = getComma(4, GPGGAstr);
    longitude = getDoubleNumber(&GPGGAstr[tmp]);
    Serial.println("PARSE GPGGA");


    Serial.println(latitude);
    Serial.println(longitude);

   double da1 = int(latitude/100) ;
   double da2 = int(longitude/100) ;

   // The below maths is done because my gps was not showing correct values. You can skip this step if your values are shown correct without these
    a1 = String((da1 + 100*((latitude/100.00f-da1))/60.00f),6) ;
    a2 = String((da2 + 100*((longitude/100.00f-da2))/60.00f),6) ;


   Serial.println(a1);
   Serial.println(a2);
  }
  
  else
  {
    Serial.println("Not get data"); 
  }
  
}

void runn()
{
  // setup Serial po
  Serial.begin(115200);


  Serial.println("Attach to GPRS network by auto-detect APN setting");
  while (!LGPRS.attachGPRS())
  {
    delay(500);
  }
 
  // if you get a connection, report back via serial:
  Serial.print("Connect to ");
  Serial.println(server);
  
  if (client.connect(server, port))
  {
    Serial.println("connected"); 
  
    // Make a HTTP request:
    client.print("Your_website Your_path");
    client.print(a1);
    client.print("&lng=");
    client.print(a2);
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
     
    client.println("Connection: close");
    client.println();
    
  }
  else
  {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
  LGPS.powerOn();
  delay(3000);
}


void setup()
{
  runn();
  previous = millis() - interval;
}

void test()
{
  Serial.println("Attach to GPRS network by auto-detect APN setting");
  while (!LGPRS.attachGPRS())
  {
    delay(500);
  }
 
  // if you get a connection, report back via serial:
  Serial.print("Connect to ");
  Serial.println(server);
  
  if (client.connect(server, port))
  {
    Serial.println("connected"); 
  
    // Make a HTTP request:
    client.print("Your_website Your_path");
    client.print(a1);
    client.print("&lng=");
    client.print(a2);
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
     
    client.println("Connection: close");
    client.println();
    
  }
  else
  {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
  LGPS.powerOn();
  delay(3000);
}



void loop()
{ 
   unsigned long current = millis(); 
   if(current - previous >= interval)   
   {     
        previous = current;
        test();
        chkloc();
        
         Serial.println("");              
    }
 }
   


