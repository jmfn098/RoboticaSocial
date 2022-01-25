#include <Adafruit_GFX.h>    // Librería graficos
#include <Adafruit_ST7735.h> // Librería Hardware
#include <SPI.h>
#define TFT_CS     10
#define TFT_RST    9  // Reset
#define TFT_DC     8

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST); // Comandos utilizados

#define TFT_SCLK 13   // SCLK
#define TFT_MOSI 11   // MOST
void setup(void) {
  Serial.begin(9600);
  Serial.println("Tutorial TFT 1.8 HETPRO");

 
  tft.initR(INITR_BLACKTAB);   // Iniciando chip

  Serial.println("INICIANDO");

  tft.fillScreen(ST7735_GREEN);//PRIMER COLOR EN PANTALLA PARA INICIAR

  delay(500);
  Serial.println("Hecho");
  delay(1000);
}

void loop()
{
  // secuencia de texto que muestra
  tft.setTextWrap(false);
  tft.fillScreen(ST7735_BLACK);  // Fondo negro
  tft.setRotation(2);            // Rotación orientación
  tft.setCursor(10, 0);          // Escribe en la posicion del cursor
 
  tft.setTextColor(ST7735_RED); //Color de texto
  tft.setTextSize(3.5);         // Tamaño texto
  tft.println("HETPRO");        // Texto a mostrar
 
  tft.setTextColor(ST7735_YELLOW);
  tft.setTextSize(2);
  tft.println("HETPRO");
 
  tft.setTextColor(ST7735_GREEN);
  tft.setTextSize(3);
  tft.println("HETPRO");
 
  tft.setTextColor(ST7735_BLUE);
  tft.setTextSize(3.5);
  tft.println("HETPRO");

 
  delay(1500);
 
  tft.setTextWrap(false);
  tft.fillScreen(ST7735_GREEN);  // Fondo negro
  tft.setRotation(3);            // Rotación orientación
  tft.setCursor(30, 0);          // Escribe en la posicion del cursor

  tft.setTextColor(ST7735_GREEN);
  tft.setTextSize(3);
  tft.println("HETPRO");
 
  tft.setTextColor(ST7735_BLUE);
  tft.setTextSize(4);
  tft.println("HETPRO");

 
  delay(1500);

 
  tft.setTextWrap(false);
  tft.fillScreen(ST7735_WHITE);
  tft.setCursor(3, 8);  
  tft.setTextColor(ST7735_GREEN);
  tft.setRotation(4); // Rotación orientación
  tft.setTextSize(3); // Tamaño texto
  tft.print("HETPRO");     
          
  delay(1500);
 
}
