//Código para proyectar mensajes enviados por consola de comandos en pantalla LCD usando puerto serial

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //Pines de comunicación con el shield LCD
#define DEBUG(a) Serial.println(a); 

void setup()
{
    Serial.begin(9600);             //Inicializar puerto serial
    lcd.begin(16, 2);              // Inicializar el LCD
    lcd.setCursor(0, 0);           // Cursor a linea 0, posicion 0  
}


void loop()
{

      lcd.setCursor(0,0);              // Cursor a linea 0, posicion 0  
      lcd.print("Waiting cmd");     // Mensaje que espera comandos
      
   if (Serial.available())
   {
      lcd.setCursor(0,0);              // Cursor a linea o, posicion 0  
      lcd.print("Cmd recieved! :D");     // Imprime que recibió un comando
      lcd.setCursor(0,1);              // Cursor a linea 0, posicion 1
      lcd.print(Serial.readStringUntil('\n'));   // Imprime comando en pantalla enviado por el monitor serial 
      String data = Serial.readStringUntil('\n');  // Imprime comando enviado por el monitor serial 
      DEBUG(data);
       
   }
   delay(1700); // Tiempo que el mensaje permanece en pantalla (1.7 seg)
   lcd.clear(); // Borrado de pantalla para repetir el ciclo    
}