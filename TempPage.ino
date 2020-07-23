
void handleTempPageButtons(bool touched) 
{
  menuPageBackButton.press(touched && menuPageBackButton.contains(pixel_x, pixel_y));

  if (menuPageBackButton.justReleased()) 
  {
    menuPageBackButton.drawButton();
  }

  if (menuPageBackButton.justPressed()) 
  {
    menuPageBackButton.drawButton(true);
  }

  if (menuPageBackButton.justReleased()) 
  {
    drawMenuPage();
  }
}

void drawTempPage() 
{
  currentPage = 2;
  tft.fillScreen(BLACK);

  tft.setCursor(40, 95); // X, Y
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(6);
  tft.print(temp);
  tft.print(" C");

  drawTempPageButtons();
}

void drawTempPageButtons() 
{
  menuPageBackButton.initButton(&tft, 250, 200, 120, 40, WHITE, CYAN, BLACK, "Takaisin", 2);
  menuPageBackButton.drawButton(false);
}
