
static int ptDrawAlarmPage(struct pt *pt, bool touched) 
{
  static bool drawn = false;

  PT_BEGIN(pt);

  if (!drawn) 
  {
    currentPage = 4;
    tft.fillScreen(BLACK);
  
    tft.setCursor(20, 25); // X, Y
    tft.setTextColor(WHITE, BLACK);
    tft.setTextSize(6);
  
    tft.print("HERATYYYS!"); 

    alarmPageButtonStop.initButton(&tft, 70, 210, 120, 40, RED, RED, GREEN, "Lopeta", 2);
    alarmPageButtonStop.drawButton(false);
    
    drawn = true;
  }

  alarmPageButtonStop.press(touched && alarmPageButtonStop.contains(pixel_x, pixel_y));

  if (alarmPageButtonStop.justReleased()) 
  {
     alarm.on = false;
     drawn = false;
     drawStartScreen();
  }

  PT_END(pt);
}
