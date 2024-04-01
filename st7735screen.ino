
#include <Adafruit_GFX.h> // core graphics library
#include <Adafruit_ST7735.h> // hardware-specific library
#include <SPI.h>

#define sclk 13
#define mosi 11
#define cs 10
#define dc 9
#define rst 8

// Option 1: use any pins but a little slower
Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, rst);
int pressedButton=0; //pressed input button
void setup() {
pinMode(5, INPUT_PULLUP);
pinMode(3,INPUT_PULLUP);
pinMode(4,OUTPUT);

tft.initR(INITR_BLACKTAB); // initialize a ST7735S chip, black tab
tft.fillScreen(ST7735_BLACK);
tft.setCursor(30,60);
tft.setTextColor(ST7735_WHITE);
tft.setTextSize(1);
tft.print("Loading..");
delay(500);
tft.fillScreen(ST7735_WHITE);
Serial.begin(9600);

}

void loop() {
//blinkled();
delay(100);
tft.fillScreen(ST7735_WHITE);
tft.fillRect(0,0,320,180,ST7735_BLUE);
tft.setTextColor(ST7735_BLACK);
tft.setCursor(5,11);
tft.setTextSize(1);
tft.print("APP TITLE");
int butt=digitalRead(5);
if(butt==LOW){
  pressedButton=24;
  delay(30);
  Serial.println("finya");
  }

int button=digitalRead(3);
if(button==LOW){
  pressedButton=2;
  delay(50);
  Serial.println("pressed");
  }

tft.drawLine(0,21,280,21,ST7735_BLACK);

tft.drawLine(0,140,280,140,ST7735_BLACK);

  
Serial.println(pressedButton);

  if(pressedButton==2){ //button press logic
        drawHomeMenu();
        
  }else if(pressedButton==20){
        drawCall();
        
  }else if(pressedButton==24){
        String msg="Hello,Naitwa Nekesa from Busia..";
        readMessages(msg);
      }else{
        clearScreen();

}


for(int i=0; i<20; i++){
  blinkled();
  delay(100);
  }
delay(1000);
}


void readMessages(String msg){
  tft.fillRect(0,22,280,120,ST7735_WHITE);
  tft.setCursor(5,27);
  tft.setTextColor(ST7735_RED);
  tft.setTextSize(1);
  tft.print("Date: 12/12/2024");

  tft.setCursor(5,37);
  tft.setTextColor(ST7735_RED);
  tft.setTextSize(1);
  tft.print("To: +254718265708");
  clearScreenMenu();

  tft.setCursor(0,47);
  tft.setTextColor(ST7735_BLACK);
  tft.setTextSize(1);
  tft.print(msg);
  clearScreenMenu();
  
  
  }
  

void clearScreen(){
  tft.fillRect(0,22,280,120,ST7735_WHITE);
  clearScreenMenu();
  }
void drawCall(){
  tft.fillRect(0,22,280,120,ST7735_BLACK);
  tft.setCursor(25,47);
  tft.setTextColor(ST7735_RED);
  tft.setTextSize(1.8);
  tft.print("Calling..");

  tft.setCursor(25,78);
  tft.setTextColor(ST7735_YELLOW);
  tft.setTextSize(0.89);
  tft.print("James- 07123747..");
  
  }

void clearScreenMenu(){
  tft.setCursor(90,144);
  tft.setTextSize(1);
  tft.print("Back");

}
void drawHomeMenu(){
  tft.fillRect(0,22,280,120,ST7735_BLACK);
  tft.setCursor(25,47);
  tft.setTextColor(ST7735_RED);
  tft.setTextSize(1.3);
  tft.print("Safaricom");
  
  tft.setCursor(25,64);
  tft.setTextColor(ST7735_YELLOW);
  tft.setTextSize(1);
  tft.print("14.03.2024");
  tft.setCursor(25,78);
  tft.setTextColor(ST7735_YELLOW);
  tft.setTextSize(0.89);
  tft.print("10:13 pm EAT");
  bottomMenu_Home();
  }

void bottomMenu_Home(){
  tft.setCursor(5,144);
  tft.setTextSize(1);
  tft.print("Menu");
  
  tft.setCursor(90,144);
  tft.setTextSize(1);
  tft.print("Back");
  }

void bottomMenu_Menu(){
  tft.setCursor(5,146);
  tft.setTextSize(1);
  tft.print("<<");

   tft.setCursor(58,146);
  tft.setTextSize(1);
  tft.print("Ok");
  
  tft.setCursor(100,146);
  tft.setTextSize(1);
  tft.print(">>");
 }

void blinkled(){
  digitalWrite(4,HIGH);
delay(100);
digitalWrite(4,LOW);
delay(30);
  
  }
