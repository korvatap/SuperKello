#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include <Wire.h>
#include <RTClib.h>
#include <pt.h>

MCUFRIEND_kbv tft;
RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunnuntai", "Maanantai", "Tiistai", "Keskiviikko", "Torstai", "Perjantai", "Lauantai"};

const int XP = 8, XM = A2, YP = A3, YM = 9; //240x320 ID=0x9341
const int TS_LEFT = 80, TS_RT = 903, TS_TOP = 134, TS_BOT = 909, TS_WIDTH = 320, TS_HEIGHT = 240;
const int interval = 1000, buttonInterval = 20;

#define MINPRESSURE 200
#define MAXPRESSURE 1000
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
byte currentPage = 0;
long previousMillis = 0;
DateTime now; // getDateTimeNow() updates global var
int pixel_x, pixel_y; //Touch_getXY() updates global vars
long buttonLastPressedMillis = 0;

// RTC_DS1307
int sensorInput;    //The variable we will use to store the sensor input
double temp;        //The variable we will use to store temperature in degrees. 

bool inverted = false; // alarm on/off toggle boolean

// Protothreads
static struct pt pt1, pt2;

typedef struct Alarm 
{
    bool on, playing;
    byte h, m;
};

Alarm alarm = { false, false,  8,  00 };

Adafruit_GFX_Button menuButton;
Adafruit_GFX_Button menuPageTempButton, menuPageWakeUpButton, homePageButton;
Adafruit_GFX_Button menuPageBackButton;
Adafruit_GFX_Button wakeUpPageButtonHp, wakeUpPageButtonHm, wakeUpPageButtonMp, wakeUpPageButtonMm, wakeUpPageBackButton, wakeUpPageToggleButton;
Adafruit_GFX_Button alarmPageButtonStop;
