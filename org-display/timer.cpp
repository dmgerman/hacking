#include "timer.h"
#include <stdio.h>

#include <QTime>



Timer::Timer(QWidget *parent,  char *filename = NULL)
    : QWidget(parent)
{

  browser = new QTextBrowser(this);
  //  browser = new QTextEdit(this);
  //browser->setMinimumSize(100,100);
  //  browser->resize(1000,200);

  browser->setSizePolicy(QSizePolicy::Expanding, 
      QSizePolicy::Expanding);
  browser->updateGeometry() ;

  url = QUrl::fromUserInput(filename);
  browser->setSource(url);
  printf("Hello world\n");
  updateGeometry() ;
  startTimer(1000);

}

void resizeEvent(QTimerEvent *event)
{
  printf("To resize\n");
}

void Timer::timerEvent(QTimerEvent *event)
{
  browser->reload();
  updateGeometry() ;
}
