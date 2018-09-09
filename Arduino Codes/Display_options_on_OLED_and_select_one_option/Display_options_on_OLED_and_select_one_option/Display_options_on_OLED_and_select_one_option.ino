#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keypad.h>
  
#define OLED_DC    11
#define OLED_CS    12
#define OLED_CLK   10
#define OLED_MOSI   9
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

 // Below are the options that are shown on the OLED, which can be changed as per the requirement
 
    char q[] = "Madhukar Navik";
    char w[] = "I am Mtech Student at MSRIT ECE Department";
    char e[] = "I am intern at GEEKSYNERGY";
    char r[] = "I love non-veg";
    int  minw,minx,miny,minz,a=0,b=0,c=0,d=0;

const byte ROWS = 2; //In this code i have used only 2 buttons while i have declared 6 of them.
const byte COLS = 1; //You can skip the rest declaration as they are not needed in this code.
char keys[ROWS][COLS] = {
    {'1'},//'3','5'},
    {'2'}//,'4','6'}
};
  byte rowPins[ROWS] = {6,5}; //connect to the row pinouts of the keypad
  byte colPins[COLS] = {3};//,4,2}; //connect to the column pinouts of the keypad
  
  Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
  int x=0;


void setup() {
  start();
  }

void loop() {

ifKeyPresssed();
scrollIfNeeded();

}

void ifKeyPresssed(){
  
  char key = keypad.getKey();
  if(key=='1'){                                              //move up by 1 line
                   a=0;
                    b=0;
                    c=0;
                    d=0;
                   display.setCursor(0,x);   
                   display.setTextColor(WHITE, BLACK); 
                   if(x==0){display.print(q);}
                   if(x==8){display.print(w);}
                   if(x==16){display.print(e);}
                   if(x==24){display.print(r);}               
                   display.display();
                   if(x>7){
                    x=x-8;}
                   display.setCursor(0,x);
                   display.setTextColor(BLACK,WHITE);
                   if(x==0)display.print(q);
                   if(x==8)display.print(w);
                   if(x==16)display.print(e);
                   if(x==24)display.print(r);
                   display.display();}
               
        
  if(key=='2'){                                            // Go down by 1 line
                    a=0;
                    b=0;
                    c=0;
                    d=0;
                  display.setCursor(0,x);  
                  display.setTextColor(WHITE, BLACK);
                   if(x==0)display.print(q);
                   if(x==8)display.print(w);
                   if(x==16)display.print(e);
                   if(x==24)display.print(r);
                  display.display();
                    if(x<17){
                      x=x+8;}
                  display.setCursor(0,x);
                  display.setTextColor(BLACK,WHITE);
                  if(x==0)display.print(q);
                  if(x==8)display.print(w);
                  if(x==16)display.print(e);
                  if(x==24)display.print(r);
                  display.display();}
}

     
void scrollIfNeeded(){
    
                  if(x==0){ 
                            display.setCursor(a,0);
                            display.print(q);
                            display.display();
                            if(strlen(q)>15){
                                if(--a < minw) a = display.width();
                                }
                           }
                   if(x==8){
                            display.setCursor(b,8);
                            display.print(w);
                            display.display();
                            if(strlen(w)>15){
                                if(--b < minx) b = display.width();
                                }                               
                           }
                   if(x==16){
                            display.setCursor(c,16);
                            display.print(e);
                            display.display();
                            if(strlen(e)>15){
                                if(--c < miny) c = display.width();
                                }                                
                            }
                   if(x==24){
                            display.setCursor(d,24);
                            display.print(r);
                            display.display();
                            if(strlen(r)>15){
                                if(--d < minz) d = display.width();
                                }                                
                            }
}

void start(){
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setTextWrap(false);
  display.clearDisplay();
  minw = -6 * strlen(q); // 12 = 6 pixels/character * text size 2
  minx = -6 * strlen(w); // 12 = 6 pixels/character * text size 2
  miny = -6 * strlen(e); // 12 = 6 pixels/character * text size 2
  minz = -6 * strlen(r); // 12 = 6 pixels/character * text size 2

 display.setCursor(0,0);
 display.println(q);
 display.println(w);
 display.println(e);
 display.println(r);
 display.display();
}
