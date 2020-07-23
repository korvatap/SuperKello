/***** HomePage *****/
void handleHomePageButtons(bool touched);
void drawHeader();
void drawMenuButton();
void drawClock();
void drawAlarmUntil();
void drawStartScreen();

/***** MenuPage *****/
void handleMenuPageButtons(bool touched);
void drawMenuPageButtons();
void drawMenuPage();

/***** TempPage *****/
void handleTempPageButtons(bool touched);
void drawTempPage();
void drawTempPageButtons();

/***** Utils *****/
bool Touch_getXY(void);
void getDateTimeNow();
bool buttonsAreOpen();
void alarmIfNeeded();
void getTemp();

/***** WakeUpPage *****/
void drawWakeupPage();
void drawAlarmClock();
void toggleWakeUpStatus();
void drawWakeUpPageStatusButton();
void handleWakeUpPageButtons(bool touched);
void drawWakeUpPageButtons();
void increaseHours();
void increaseMinutes();
void decreaseHours();
void decreaseMinutes();

/***** AlarmPage *****/
//void drawAlarmPage();
