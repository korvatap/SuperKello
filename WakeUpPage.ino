
void drawWakeupPage() 
{
  currentPage = 3;
  tft.fillScreen(BLACK);

  drawAlarmClock();

  drawWakeUpPageButtons();
}

void drawAlarmClock() 
{
  tft.setCursor(75, 25); // X, Y
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(6);

  if (alarm.h < 10) 
  {
    tft.print("0");
  }

  tft.print(alarm.h);
  tft.print(":");

  if (alarm.m < 10) 
  {
    tft.print("0");
  }

  tft.print(alarm.m);
}

void toggleWakeUpStatus() 
{
  alarm.on = !alarm.on;
}

void drawWakeUpPageStatusButton() 
{
  if (alarm.on) 
  {
      wakeUpPageToggleButton.initButton(&tft, 70, 210, 120, 40, GREEN, GREEN, RED, "On/Off", 2);
  }
  else 
  {
      wakeUpPageToggleButton.initButton(&tft, 70, 210, 120, 40, RED, RED, GREEN, "On/Off", 2);
  }
  wakeUpPageToggleButton.drawButton(false);
}

void increaseHours() 
{
  if (alarm.h == 23) 
  {
    alarm.h = 0;
  } 
  else 
  {
    alarm.h++;
  }
  drawAlarmClock();
}

void increaseMinutes() 
{
  if (alarm.m == 59) 
  {
    alarm.m = 0;
  }
  else 
  {
    alarm.m++;
  }
  drawAlarmClock();
}

void decreaseHours() 
{
  if (alarm.h == 0) 
  {
    alarm.h = 23;
  } 
  else 
  {
    alarm.h--;
  }
  drawAlarmClock();
}


void decreaseMinutes() 
{
  if (alarm.m == 0) 
  {
    alarm.m = 59;
  }
  else 
  {
    alarm.m--;
  }
  drawAlarmClock();
}

void handleWakeUpPageButtons(bool touched) 
{
  if (buttonsAreOpen()) 
  {
    wakeUpPageButtonHp.press(touched && wakeUpPageButtonHp.contains(pixel_x, pixel_y));
    if (wakeUpPageButtonHp.justReleased()) 
    {
    }

    if (wakeUpPageButtonHp.justPressed()) 
    {
      wakeUpPageButtonHp.drawButton(true);
      wakeUpPageButtonHp.drawButton();
    }

    if (wakeUpPageButtonHp.justReleased()) 
    {
      increaseHours();
      return;
    }

    wakeUpPageButtonHm.press(touched && wakeUpPageButtonHm.contains(pixel_x, pixel_y));
    if (wakeUpPageButtonHm.justReleased()) 
    {
      wakeUpPageButtonHm.drawButton();
    }

    if (wakeUpPageButtonHm.justPressed()) 
    {
      wakeUpPageButtonHm.drawButton(true);
    }

    if (wakeUpPageButtonHm.justReleased()) 
    {
      decreaseHours();
      return;
    }

    wakeUpPageButtonMp.press(touched && wakeUpPageButtonMp.contains(pixel_x, pixel_y));
    if (wakeUpPageButtonMp.justReleased()) 
    {
      wakeUpPageButtonMp.drawButton();
    }

    if (wakeUpPageButtonMp.justPressed()) 
    {
      wakeUpPageButtonMp.drawButton(true);
    }

    if (wakeUpPageButtonMp.justReleased()) 
    {
      increaseMinutes();
      return;
    }

    wakeUpPageButtonMm.press(touched && wakeUpPageButtonMm.contains(pixel_x, pixel_y));
    if (wakeUpPageButtonMm.justReleased()) 
    {
      wakeUpPageButtonMm.drawButton();
    }

    if (wakeUpPageButtonMm.justPressed()) 
    {
      wakeUpPageButtonMm.drawButton(true);
    }

    if (wakeUpPageButtonMm.justReleased()) 
    {
      decreaseMinutes();
      return;
    }

    wakeUpPageBackButton.press(touched && wakeUpPageBackButton.contains(pixel_x, pixel_y));
    if (wakeUpPageBackButton.justReleased()) 
    {
      drawMenuPage();
      wakeUpPageBackButton.drawButton();
    }

    if (wakeUpPageBackButton.justPressed()) 
    {
      wakeUpPageBackButton.drawButton(true);
    }

    wakeUpPageToggleButton.press(touched && wakeUpPageToggleButton.contains(pixel_x, pixel_y));
    if (wakeUpPageToggleButton.justReleased()) 
    {
      inverted = !inverted;
      wakeUpPageToggleButton.drawButton(inverted);
      toggleWakeUpStatus();
      return;
    }
  }
}

void drawWakeUpPageButtons() 
{
  wakeUpPageButtonHp.initButton(&tft, 85, 90, 20, 20, WHITE, CYAN, BLACK, "+", 2); // x, y, w, h
  wakeUpPageButtonHm.initButton(&tft, 125, 90, 20, 20, WHITE, CYAN, BLACK, "-", 2);
  wakeUpPageButtonMp.initButton(&tft, 195, 90, 20, 20, WHITE, CYAN, BLACK, "+", 2);
  wakeUpPageButtonMm.initButton(&tft, 235, 90, 20, 20, WHITE, CYAN, BLACK, "-", 2);
  wakeUpPageBackButton.initButton(&tft, 250, 210, 120, 40, WHITE, CYAN, BLACK, "Takaisin", 2);
  drawWakeUpPageStatusButton();
  wakeUpPageButtonHp.drawButton(false);
  wakeUpPageButtonHm.drawButton(false);
  wakeUpPageButtonMp.drawButton(false);
  wakeUpPageButtonMm.drawButton(false);
  wakeUpPageBackButton.drawButton(false);
}
