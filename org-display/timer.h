#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QLabel>
#include <qtextbrowser.h>

class Timer : public QTextBrowser
{
  public:
  Timer(char *filename,int seconds = 60, QWidget *parent =0);

  protected:
    void timerEvent(QTimerEvent *event);
  private:
    QUrl url;
};

#endif
