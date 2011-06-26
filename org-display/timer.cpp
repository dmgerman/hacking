#include "timer.h"
#include <stdio.h>

#include <QTime>



Timer::Timer(char *filename = NULL,int seconds, QWidget *parent)
    : QTextBrowser(parent)
{
  QFont font("Helvetica", 8);
  setFont(font);
  url = QUrl::fromUserInput(filename);
  setSource(url);
  setGeometry(1, 1, 800, 400);
  updateGeometry() ;
  startTimer(seconds * 1000); // 1 minute later

}

void Timer::timerEvent(QTimerEvent *event)
{
  reload();
  updateGeometry() ;
}
