
void handleHomePageButtons(bool touched)
{
  menuButton.press(touched && menuButton.contains(pixel_x, pixel_y));

  if (menuButton.justReleased())
  {
    menuButton.drawButton();
  }

  if (menuButton.justPressed())
  {
    menuButton.drawButton(true);
  }

  if (menuButton.justReleased())
  {
    drawMenuPage();
  }
}

void drawHeader()
{
  tft.drawRect(0, 0, 319, 240, CYAN);
  tft.setCursor(100, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Super kello");
  tft.drawLine(4, 30, 315, 30, RED);
}

void drawMenuButton()
{
  menuButton.initButton(&tft, 250, 210, 100, 40, WHITE, CYAN, BLACK, "Valikko", 2);
  menuButton.drawButton(false);
}

void drawClock()
{
  tft.setCursor(18, 100); // X, Y
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(6);

  int hour = now.hour();
  if (hour < 10)
  {
    tft.print("0");
  }

  tft.print(hour);
  tft.print(":");

  int minutes = now.minute();
  if (minutes < 10)
  {
    tft.print("0");
  }

  tft.print(minutes);
  tft.print(":");

  int seconds = now.second();
  if (seconds < 10)
  {
    tft.print("0");
  }

  tft.print(seconds);
}

void drawAlarmUntil()
{
  if (alarm.on)
  {
    int startHour = now.hour();
    int startMinute = now.minute();
    long endHour = alarm.h;
    long endMinute = alarm.m;

    if (startHour > endHour || (startHour == endHour && startMinute > endMinute))
    {
      endHour += 24;
    }

    if (startMinute > endMinute)
    {
      endHour -= 1;
      endMinute += 60;
    }

    endMinute -= startMinute;
    endHour -= startHour;
    
    tft.setTextSize(1);
    tft.setCursor(100, 150);
    tft.print("Soi: ");
    tft.print(endHour);
    tft.print(" h ");
    tft.print(endMinute);
    tft.print(" min kuluttua");
  }
}

static void drawStartScreen() 
{
  currentPage = 0;
  tft.fillScreen(BLACK);

  drawHeader();
  drawMenuButton();
  drawClock();
  drawAlarmUntil();
}
