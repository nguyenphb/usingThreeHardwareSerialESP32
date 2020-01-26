# usingThreeHardwareSerialESP32
How to use Three Hardware Serial ports on Arduino ESP32

English below

## Cách sử dụng 3 kênh Serial của ESP32

ESP32 có 3 kênh phần cứng Serial.

```
    Serial 0: nạp code và debug hệ thống (có thể tắt debug bằng cách kéo GPIO2 xuống GND).
    Serial 1: chức năng SPI Flash
    Serial 2: không dính chức năng đặc biệt
````

Để tránh chức năng đặc biệt và sử dụng full 3 Hardware Serial mà không cần phải dùng đến thư biện Software Serial, bạn có thể mapping các chân TX,RX của Serial cần sử dụng vào chân khác.
Cú pháp trên Arduino:

```
    Serialx.begin(Baud Rate, Data Frame, RX pin, TX pin)
```

Tốc độ baud có thể thiết lập: 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, or 115200, 256000, 512000, 962100

Khung truyền có thể thiết lập:
```
    SERIAL_5N1   5-bit No parity 1 stop bit
    SERIAL_6N1   6-bit No parity 1 stop bit
    SERIAL_7N1   7-bit No parity 1 stop bit
    SERIAL_8N1 (the default) 8-bit No parity 1 stop bit
    SERIAL_5N2   5-bit No parity 2 stop bits 
    SERIAL_6N2   6-bit No parity 2 stop bits
    SERIAL_7N2   7-bit No parity 2 stop bits
    SERIAL_8N2   8-bit No parity 2 stop bits 
    SERIAL_5E1   5-bit Even parity 1 stop bit
    SERIAL_6E1   6-bit Even parity 1 stop bit
    SERIAL_7E1   7-bit Even parity 1 stop bit 
    SERIAL_8E1   8-bit Even parity 1 stop bit 
    SERIAL_5E2   5-bit Even parity 2 stop bit 
    SERIAL_6E2   6-bit Even parity 2 stop bit 
    SERIAL_7E2   7-bit Even parity 2 stop bit  
    SERIAL_8E2   8-bit Even parity 2 stop bit  
    SERIAL_5O1   5-bit Odd  parity 1 stop bit  
    SERIAL_6O1   6-bit Odd  parity 1 stop bit   
    SERIAL_7O1   7-bit Odd  parity 1 stop bit  
    SERIAL_8O1   8-bit Odd  parity 1 stop bit   
    SERIAL_5O2   5-bit Odd  parity 2 stop bit   
    SERIAL_6O2   6-bit Odd  parity 2 stop bit    
    SERIAL_7O2   7-bit Odd  parity 2 stop bit    
    SERIAL_8O2   8-bit Odd  parity 2 stop bit  
```

Tài liệu tham khảo:

https://github.com/espressif/arduino-esp32

https://randomnerdtutorials.com/esp32-pinout-reference-gpios/

ESP32 have Three Hardware Serial
```
    Serial 0: is used to communicate with the ESP32 for programming and during reset/boot.
    Serial 1: use this port for SPI Flash access though
    Serial 2: is unused.
````
To use full 3 Serial, the TX and RX pin of Serialx can maps to unused pins.
The format for setting a serial port is as follows:

```
    Serialx.begin(Baud Rate, Data Frame, RX pin, TX pin)
```
EX: RX1 (GPIO9),TX1(GPIO10) maps to GPIO18 and GPIO19 at Baud Rate 115200 and Data Frame: 8-bit No parity 1 stop bit
```
    Serial1.begin(115200, SERIAL_8N1, 18, 19)
```
Baud Rates available: 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, or 115200, 256000, 512000, 962100

Data Frame available:
```
    SERIAL_5N1   5-bit No parity 1 stop bit
    SERIAL_6N1   6-bit No parity 1 stop bit
    SERIAL_7N1   7-bit No parity 1 stop bit
    SERIAL_8N1 (the default) 8-bit No parity 1 stop bit
    SERIAL_5N2   5-bit No parity 2 stop bits 
    SERIAL_6N2   6-bit No parity 2 stop bits
    SERIAL_7N2   7-bit No parity 2 stop bits
    SERIAL_8N2   8-bit No parity 2 stop bits 
    SERIAL_5E1   5-bit Even parity 1 stop bit
    SERIAL_6E1   6-bit Even parity 1 stop bit
    SERIAL_7E1   7-bit Even parity 1 stop bit 
    SERIAL_8E1   8-bit Even parity 1 stop bit 
    SERIAL_5E2   5-bit Even parity 2 stop bit 
    SERIAL_6E2   6-bit Even parity 2 stop bit 
    SERIAL_7E2   7-bit Even parity 2 stop bit  
    SERIAL_8E2   8-bit Even parity 2 stop bit  
    SERIAL_5O1   5-bit Odd  parity 1 stop bit  
    SERIAL_6O1   6-bit Odd  parity 1 stop bit   
    SERIAL_7O1   7-bit Odd  parity 1 stop bit  
    SERIAL_8O1   8-bit Odd  parity 1 stop bit   
    SERIAL_5O2   5-bit Odd  parity 2 stop bit   
    SERIAL_6O2   6-bit Odd  parity 2 stop bit    
    SERIAL_7O2   7-bit Odd  parity 2 stop bit    
    SERIAL_8O2   8-bit Odd  parity 2 stop bit  
```
Have fun !!!

Docs:

https://github.com/espressif/arduino-esp32

https://randomnerdtutorials.com/esp32-pinout-reference-gpios/