
bool Touch_getXY(void)
{
  TSPoint p = ts.getPoint();
  pinMode(YP, OUTPUT);      //restore shared pins
  pinMode(XM, OUTPUT);
  digitalWrite(YP, HIGH);   //because TFT control pins
  digitalWrite(XM, HIGH);
  bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
  if (pressed) 
  {
    pixel_x = map(p.y, TS_LEFT, TS_RT, 0, TS_WIDTH);
    pixel_y = map(p.x, TS_TOP, TS_BOT, 0, TS_HEIGHT);
  }
  return pressed;
}


void getDateTimeNow() 
{
  now = rtc.now();
}

bool buttonsAreOpen() 
{
  unsigned long currentMillis = millis();

  if (buttonLastPressedMillis == 0 || currentMillis - buttonLastPressedMillis > buttonInterval) 
  {
    buttonLastPressedMillis = currentMillis;
    return true;
  }
  
  return false;
}

void alarmIfNeeded() 
{
  if (alarm.on && !alarm.playing) 
  {
    if (now.hour() == alarm.h && now.minute() == alarm.m) 
    {
      alarm.playing = true;
      ptPlayDoom(&pt1);
    }
  }
}

void getTemp() 
{
    sensorInput = analogRead(A15);    //read the analog sensor and store it
    temp = (double)sensorInput / 1024;       //find percentage of input reading
    temp = temp * 5;                 //multiply by 5V to get voltage
    temp = temp - 0.5;               //Subtract the offset 
    temp = temp * 100;               //Convert to degrees 
}
