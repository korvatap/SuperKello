void loop() 
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > interval) 
  {

    getDateTimeNow();
    if (currentPage == 0) 
    {
      drawClock();
    }

    //alarmIfNeeded();
    previousMillis = currentMillis;
    getTemp();
  }

  bool touched = Touch_getXY();

  // Home page
  if (currentPage == 0) 
  {
    handleHomePageButtons(touched);
  }

  // Menu page
  if (currentPage == 1) 
  {
    handleMenuPageButtons(touched);
  }

  // Temp page
  if (currentPage == 2) 
  {
    handleTempPageButtons(touched);
  }

  // WakeUp page
  if (currentPage == 3) 
  {
    handleWakeUpPageButtons(touched);
  }

  if (alarm.on && now.hour() == alarm.h && now.minute() == alarm.m) 
  {
    alarm.playing = true;
  }

  if (alarm.on && alarm.playing) 
  {
    ptDrawAlarmPage(&pt2, touched);
    ptPlayDoom(&pt1);
  }
}
