#include <WiFi.h>    
#include <esp_wifi.h>
#include <esp_now.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <Adafruit_GFX.h>

#define TFT_CS  5
#define TFT_DC  2
#define TFT_RST 4

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

typedef struct struct_message  {
  float falltime1;
  float height1;
  float maxG1;
  float gForce1; 

} struct_message;

struct_message dropdat;

void setup(){
  Serial.begin(115200);

  tft.initR(INITR_BLACKTAB);
  tft.setRotation(3);
  tft.fillScreen(ST77XX_BLACK);

  WiFi.mode(WIFI_STA);

  if(esp_now_init() != ESP_OK){
    Serial.println("Error initializing ESP_NOW");
    return;
  }

  esp_now_register_recv_cb(recievedata);
}
 
void loop(){
}

void recievedata(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len){
  memcpy(&dropdat, incomingData, sizeof(dropdat));

  Serial.print("bytes recieved");
  Serial.println(len);
  Serial.print("falltime ");
  Serial.println(dropdat.falltime1);
  Serial.print("height");
  Serial.println(dropdat.height1);
  Serial.print("maxGforce");
  Serial.println(dropdat.maxG1);

  tft.fillScreen(ST77XX_BLACK);

  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(2);
  tft.setCursor(10, 5);
  tft.println("IMPACT!!!!");

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(1);

  tft.setCursor(0, 35);
  tft.print("Time: ");

  tft.setTextColor(ST77XX_YELLOW);
  tft.setTextSize(2);
  tft.println(dropdat.falltime1);

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(1);
  tft.setCursor(0, 65);
  tft.print("Height: ");

  tft.setTextColor(ST77XX_CYAN);
  tft.setTextSize(2);
  tft.println(dropdat.height1);

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(1);
  tft.setCursor(0, 95);
  tft.print("Peak G: ");

  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(2);
  tft.println(dropdat.maxG1);

  delay(100);
}