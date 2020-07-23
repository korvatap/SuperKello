
void handleMenuPageButtons(bool touched) 
{
  menuPageTempButton.press(touched && menuPageTempButton.contains(pixel_x, pixel_y));
  menuPageWakeUpButton.press(touched && menuPageWakeUpButton.contains(pixel_x, pixel_y));
  homePageButton.press(touched && homePageButton.contains(pixel_x, pixel_y));

  if (homePageButton.justReleased())
  {
    homePageButton.drawButton();
  }

  if (homePageButton.justPressed()) 
  {
    homePageButton.drawButton(true);
  }

  if (homePageButton.justReleased()) 
  {
    drawStartScreen();
  }

  if (menuPageTempButton.justReleased()) 
  {
    menuPageTempButton.drawButton();
  }

  if (menuPageTempButton.justPressed()) 
  {
    menuPageTempButton.drawButton(true);
  }

  if (menuPageTempButton.justReleased()) 
  {
    drawTempPage();
  }

  if (menuPageWakeUpButton.justReleased()) 
  {
    menuPageWakeUpButton.drawButton();
  }

  if (menuPageWakeUpButton.justPressed()) 
  {
    menuPageWakeUpButton.drawButton(true);
  }

  if (menuPageWakeUpButton.justReleased()) 
  {
    drawWakeupPage();
  }
}


void drawMenuPageButtons() 
{
  menuPageTempButton.initButton(&tft, 150, 50, 120, 40, WHITE, CYAN, BLACK, "Lampotila", 2);
  menuPageWakeUpButton.initButton(&tft, 150, 120, 100, 40, WHITE, CYAN, BLACK, "Heratys", 2);
  homePageButton.initButton(&tft, 250, 200, 120, 40, WHITE, CYAN, BLACK, "Takaisin", 2);

  menuPageTempButton.drawButton(false);
  menuPageWakeUpButton.drawButton(false);
  homePageButton.drawButton(false);
}

void drawMenuPage() 
{
  currentPage = 1;
  tft.fillScreen(BLACK);

  drawMenuPageButtons();
}
