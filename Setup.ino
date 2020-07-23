
void setup() 
{
  Serial.begin(9600);
  while (!Serial); // for Leonardo/Micro/Zero

  PT_INIT(&pt1);
  PT_INIT(&pt2);

  if (! rtc.begin()) 
  {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning())
  {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  tft.begin(tft.readID());
  tft.setRotation(1);

  Serial.println(tft.readID(), HEX);
  tft.fillScreen(BLACK);
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.setCursor(20, 100);
  tft.print("Lataa...");

  for (int i = 0; i < 250; i = i + 5)
  {
    tft.fillRect(20, 180, i, 10, RED);
    delay(0.000000000000000000000000000000000000000000000000001);
  }

  tft.fillScreen(BLACK);

  drawStartScreen();
}
