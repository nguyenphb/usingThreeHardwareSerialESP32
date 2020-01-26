/*
 * File: ThreeHardwareSerial.ino
 * Project: ESP32Ex/ThreeHardwareSerial
 * Created Date: Sunday, January 26th 2020, 11:06:20 pm
 * Author: Invoker
 * -----
 * Last Modified: Sun Jan 26 2020
 * Modified By: Invoker
 * -----
 * 
 * Copyright (c) 2020 Phan Bảo Nguyên
 * 
 * We learn, We Share, We Drink !
 * -----
 * HISTORY:
 * Date      	        By	        Comments
 * Sun Jan 26 2020    Invoker     Create Ex: ESP32 - How to using three hardware Serial
 * ----------	---	----------------------------------------------------------
 */
 // Define for mapping pin Serial 1
#define RX1 18
#define TX1 19

void setup() {
  // put your setup code here, to run once:
  // Note the format for setting a serial port is as follows: Serialx.begin(baud-rate, protocol, RX pin, TX pin);
  Serial.begin(115200);
  //Wait for Hardware Serial 0 is opened
  while(!Serial);
  Serial1.begin(115200,SERIAL_8N1,RX1,TX1);
  //Wait for Hardware Serial 1 is opened
  while(!Serial1);
  Serial2.begin(115200);
  //Wait for Hardware Serial 2 is opened
  while(!Serial2);
}

uint32_t timeNow = 0;
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
      uint8_t len = Serial.available();
      char arr[len+1];
      Serial.readBytes(arr,len);
      arr[len] = 0;
      Serial.print("Data from Serial 0: ");
      Serial.println(arr);
  }
  if (Serial1.available()){
      uint8_t len = Serial1.available();
      char arr[len+1];
      Serial1.readBytes(arr,len);
      arr[len] = 0;
      Serial.print("Data from Serial 1: ");
      Serial.println(arr);
  }
  if (Serial2.available()){
      uint8_t len = Serial2.available();
      char arr[len+1];
      Serial2.readBytes(arr,len);
      arr[len] = 0;
      Serial.print("Data from Serial 2: ");
      Serial.println(arr);
  }
  //Print every 5s
  if (uint32_t(millis() - timeNow) > 5000){
      Serial.println("Hello from Serial 0");
      Serial1.println("Hello from Serial 1");
      Serial2.println("Hello from Serial 2");
      timeNow = millis();
   }
}

/* Baud-rates available: 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, or 115200, 256000, 512000, 962100
 *  
 *  Protocols available:
 * SERIAL_5N1   5-bit No parity 1 stop bit
 * SERIAL_6N1   6-bit No parity 1 stop bit
 * SERIAL_7N1   7-bit No parity 1 stop bit
 * SERIAL_8N1 (the default) 8-bit No parity 1 stop bit
 * SERIAL_5N2   5-bit No parity 2 stop bits 
 * SERIAL_6N2   6-bit No parity 2 stop bits
 * SERIAL_7N2   7-bit No parity 2 stop bits
 * SERIAL_8N2   8-bit No parity 2 stop bits 
 * SERIAL_5E1   5-bit Even parity 1 stop bit
 * SERIAL_6E1   6-bit Even parity 1 stop bit
 * SERIAL_7E1   7-bit Even parity 1 stop bit 
 * SERIAL_8E1   8-bit Even parity 1 stop bit 
 * SERIAL_5E2   5-bit Even parity 2 stop bit 
 * SERIAL_6E2   6-bit Even parity 2 stop bit 
 * SERIAL_7E2   7-bit Even parity 2 stop bit  
 * SERIAL_8E2   8-bit Even parity 2 stop bit  
 * SERIAL_5O1   5-bit Odd  parity 1 stop bit  
 * SERIAL_6O1   6-bit Odd  parity 1 stop bit   
 * SERIAL_7O1   7-bit Odd  parity 1 stop bit  
 * SERIAL_8O1   8-bit Odd  parity 1 stop bit   
 * SERIAL_5O2   5-bit Odd  parity 2 stop bit   
 * SERIAL_6O2   6-bit Odd  parity 2 stop bit    
 * SERIAL_7O2   7-bit Odd  parity 2 stop bit    
 * SERIAL_8O2   8-bit Odd  parity 2 stop bit    
*/
