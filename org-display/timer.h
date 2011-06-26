#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QLabel>
#include <qtextbrowser.h>

class Timer : public QWidget
{
  public:
  Timer(QWidget *parent, char *filename);
  virtual QSize sizeHint() const { return QSize(10, 25); }
  void resizeEvent(QTimerEvent *event);

  protected:
    void timerEvent(QTimerEvent *event);
  private:
    QTextBrowser *browser;
    //QTextEdit *browser;
    QLabel *label;
    QUrl url;
};

#endif
