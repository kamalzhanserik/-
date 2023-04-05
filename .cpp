#define  REMOTEXY_MODE__HARDSERIAL
#include <RemoteXY.h>
#include <Adafruit_GFX.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include "DHT_NEW.h"
#include <SPI.h>
#include <Adafruit_SSD1306.h>
#include <DFPlayerMega.h>
DHT _dht1;
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = {255, 2, 0, 0, 0, 12, 0, 16, 13, 1, 5, 32, 9, 26, 46, 46, 31, 26, 31};
struct 
{
    signed char joystick_1_x;
    signed char joystick_1_y;
    unsigned char connect_flag;
}
 RemoteXY;
#pragma pack(pop)
SoftwareSerial mySerial(10 ,  11); // RX, TX
int _volsetup= 25;
int _eqsetup= 0;
DFPlayerMega dfPlayerMega= DFPlayerMega ();
bool StartTrack_246847042_1;
bool _dfstart1_246847042_1= 0;
bool _dfstart1I_246847042_1= 0;
bool StartTrack_246847042_2;
bool _dfstart1_246847042_2= 0;
bool _dfstart1I_246847042_2= 0;
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
bool EN_213304912_1;
String in_213304912_1;
byte size_213304912_1;
byte X_213304912_1;
byte Y_213304912_1;
bool invert_213304912_1;
bool EN_213304912_2;
String in_213304912_2;
byte size_213304912_2;
byte X_213304912_2;
byte Y_213304912_2;
bool invert_213304912_2;
int _gtv1;
int _gtv2;
bool _tim2I = 0;
bool _tim2O = 0;
unsigned long _tim2P = 0UL;
bool _trgrt1 = 0;
bool _trgrt1I = 0;
bool _bounseInputD5S = 0;
bool _bounseInputD5O = 0;
unsigned long _bounseInputD5P = 0UL;
bool _trgr1 = 0;
bool _tim3I = 0;
bool _tim3O = 0;
unsigned long _tim3P = 0UL;
bool _trgrt2 = 0;
bool _trgrt2I = 0;
bool _tim1I = 0;
bool _tim1O = 0;
unsigned long _tim1P = 0UL;
bool _bounseInputD4S = 0;
bool _bounseInputD4O = 0;
unsigned long _bounseInputD4P = 0UL;
unsigned long _dht1LRT = 0UL;
unsigned long _dht1Tti = 0UL;
void setup()
{
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(2, OUTPUT);
    digitalWrite(2, 0);
    pinMode(3, OUTPUT);
    digitalWrite(3, 0);
    pinMode(6, OUTPUT);
    digitalWrite(6, 0);
    pinMode(8, OUTPUT);
    digitalWrite(8, 0);
    pinMode(9, OUTPUT);
    digitalWrite(9, 0);
    pinMode(12, OUTPUT);
    digitalWrite(12, 0);
    pinMode(13, OUTPUT);
    digitalWrite(13, 0);
    RemoteXY_Init ();
    _bounseInputD5O =  digitalRead(5);
    _bounseInputD4O =  digitalRead(4);
    _dht1.setup(7);
    _dht1LRT = millis();
    _dht1Tti = millis();
    Serial.begin (9600);
    mySerial.begin (9600);
    dfPlayerMega.set_serial (mySerial);
    delay(500);
    dfPlayerMega.normal_mode();
    delay(500);
    dfPlayerMega.set_volume(_volsetup);
    delay(500);
    dfPlayerMega.set_EQ(_eqsetup);
    delay(500);
    display.begin(SSD1306_SWITCHCAPVCC, 60); // initialize with the I2C addr 0x3D (for the 128x64)
    display.display();
    display.clearDisplay();
}
void loop()
{
    RemoteXY_Handler  ();
    bool  _bounceInputTmpD5 =  (digitalRead (5));
    if (_bounseInputD5S)
    {
        if (millis() >= (_bounseInputD5P + 40))
        {
            _bounseInputD5O= _bounceInputTmpD5;
            _bounseInputD5S=0;
        }
    }
    else
    {
        if (_bounceInputTmpD5 != _bounseInputD5O)
        {
            _bounseInputD5S=1;
            _bounseInputD5P = millis();
        }
    }
    bool  _bounceInputTmpD4 =  (digitalRead (4));
    if (_bounseInputD4S)
    {
        if (millis() >= (_bounseInputD4P + 40))
        {
            _bounseInputD4O= _bounceInputTmpD4;
            _bounseInputD4S=0;
        }
    }
    else
    {
        if (_bounceInputTmpD4 != _bounseInputD4O)
        {
            _bounseInputD4S=1;
            _bounseInputD4P = millis();
        }
    }
    //Плата:1
    display.display();
    display.clearDisplay(); // Очищаем дисплей
    if (!(_bounseInputD4O)) 
    {
         if (_trgrt1I) 
        {
             _trgrt1 = 0;
        }
         else 
        {
            _trgrt1 = 1;
            _trgrt1I = 1;
        }
    }
     else 
    {
        _trgrt1 = 0;
        _trgrt1I = 0;
    }
    ;
    StartTrack_246847042_1 = _trgrt1;
    if (StartTrack_246847042_1) 
    {
         if (_dfstart1I_246847042_1) 
        {
             _dfstart1_246847042_1 = 0;
        }
         else 
        {
            _dfstart1_246847042_1 = 1;
            _dfstart1I_246847042_1 = 1;
        }
    }
     else 
    {
        _dfstart1_246847042_1 = 0;
        _dfstart1I_246847042_1 = 0;
    }
    ;
    if(_dfstart1_246847042_1 == true) 
    {
        dfPlayerMega.start_track (1, 1);
    }
    ;
    if(!(_bounseInputD4O)) 
    {
        _tim2O = 1;
        _tim2I = 1;
    }
     else 
    {
         if(_tim2I) 
        {
            _tim2I = 0;
            _tim2P = millis();
        }
         else 
        {
             if (_tim2O) 
            {
                if (_isTimer(_tim2P, 200)) _tim2O = 0;
            }
        }
    }
    digitalWrite(2, _tim2O);
    if (!(_bounseInputD5O)) 
    {
         if (_trgrt2I) 
        {
             _trgrt2 = 0;
        }
         else 
        {
            _trgrt2 = 1;
            _trgrt2I = 1;
        }
    }
     else 
    {
        _trgrt2 = 0;
        _trgrt2I = 0;
    }
    ;
    StartTrack_246847042_2 = _trgrt2;
    if (StartTrack_246847042_2) 
    {
         if (_dfstart1I_246847042_2) 
        {
             _dfstart1_246847042_2 = 0;
        }
         else 
        {
            _dfstart1_246847042_2 = 1;
            _dfstart1I_246847042_2 = 1;
        }
    }
     else 
    {
        _dfstart1_246847042_2 = 0;
        _dfstart1I_246847042_2 = 0;
    }
    ;
    if(_dfstart1_246847042_2 == true) 
    {
        dfPlayerMega.start_track (1, 2);
    }
    ;
    if(!(_bounseInputD5O)) 
    {
        _tim3O = 1;
        _tim3I = 1;
    }
     else 
    {
         if(_tim3I) 
        {
            _tim3I = 0;
            _tim3P = millis();
        }
         else 
        {
             if (_tim3O) 
            {
                if (_isTimer(_tim3P, 200)) _tim3O = 0;
            }
        }
    }
    digitalWrite(3, _tim3O);
    if(!(_bounseInputD5O)) _trgr1 = 0;
    if(!(_bounseInputD4O)) _trgr1 = 1;
    if (_trgr1)
    {
         if (_tim1I) 
        {
             if (_isTimer(_tim1P, 3000)) 
            {
                _tim1O = 1;
            }
        }
         else 
        {
            _tim1I =1;
            _tim1P = millis();
        }
    }
     else 
    {
        _tim1O = 0;
        _tim1I = 0;
    }
    digitalWrite(6, _tim1O);
    if(_isTimer(_dht1Tti, 1000)) 
    {
        if(_isTimer(_dht1LRT,(_dht1.getMinimumSamplingPeriod()))) 
        {
            _dht1.readSensor();
            _dht1LRT = millis();
            _dht1Tti = millis();
        }
    }
    EN_213304912_1 = !(0);
    in_213304912_1 = (_convertNumbeToTime((int(_dht1.temperature))));
    size_213304912_1 = 5;
    X_213304912_1 = 34;
    Y_213304912_1 = 23;
    invert_213304912_1 = !(0);
    if (EN_213304912_1==1)
    {
        if (invert_213304912_1==1)
        	
        {
            display.setTextColor(WHITE, BLACK);
        }
        	else
        	 
        {
            display.setTextColor(BLACK, WHITE);
        }
        display.setCursor(X_213304912_1,Y_213304912_1);
        display.setTextSize(size_213304912_1);
        //display.setTextColor(WHITE);  
        display.print(in_213304912_1);
    }
    EN_213304912_2 = !(0);
    in_213304912_2 = String("Temp");
    size_213304912_2 = 2;
    X_213304912_2 = 35;
    Y_213304912_2 = 0;
    invert_213304912_2 = !(0);
    if (EN_213304912_2==1)
    {
        if (invert_213304912_2==1)
        	
        {
            display.setTextColor(WHITE, BLACK);
        }
        	else
        	 
        {
            display.setTextColor(BLACK, WHITE);
        }
        display.setCursor(X_213304912_2,Y_213304912_2);
        display.setTextSize(size_213304912_2);
        //display.setTextColor(WHITE);  
        display.print(in_213304912_2);
    }
    //Плата:2
    _gtv1 = (RemoteXY.joystick_1_y);
    _gtv2 = (RemoteXY.joystick_1_x);
    digitalWrite(13, (((_gtv1) < (-10)) && (!((_gtv2) > (20)))));
    digitalWrite(12, (((_gtv1) > (10)) && (!((_gtv2) < (-20)))));
    digitalWrite(8, (((_gtv1) > (10)) && (!((_gtv2) > (20)))));
    digitalWrite(9, (((_gtv1) < (-10)) && (!((_gtv2) < (-20)))));
}
bool _isTimer(unsigned long startTime, unsigned long period)
{
    unsigned long currentTime;
    currentTime = millis();
    if (currentTime>= startTime) 
    {
        return (currentTime>=(startTime + period));
    }
     else 
    {
        return (currentTime >=(4294967295-startTime+period));
    }
}
String _convertNumbeToTime(long value)
{
    if (value > 9) 
    {
        return String(value, DEC);
    }
    return (String("0") + String(value, DEC));
}
