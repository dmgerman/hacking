#include "vbox.h"
#include "timer.h"
#include <QVBoxLayout>
#include <QPushButton>

VerticalBox::VerticalBox(char *filename, QWidget *parent)
    : QWidget(parent)
{

  QVBoxLayout *vbox = new QVBoxLayout(this);
  vbox->setSpacing(1);

  //  Timer *orgWidget = new Timer(this, filename);
  QTextBrowser *orgWidget = new QTextBrowser(this);


  orgWidget->setSizePolicy(QSizePolicy::Expanding, 
      QSizePolicy::Expanding);

  QPushButton *ok = new QPushButton("OK", this);
  ok->setSizePolicy(QSizePolicy::Expanding, 
      QSizePolicy::Expanding);

  vbox->addWidget(orgWidget);
  vbox->addWidget(ok);

  setLayout(vbox);
}
