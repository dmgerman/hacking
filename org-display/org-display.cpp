#include "vbox.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QHBoxLayout>
#include <stdlib.h>

void resize(QWidget &widget, int width=1000, int height=300)
{
  int screenHeight;
  int screenWidth;

  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  widget.setGeometry(1, 1, width, height);

}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QWidget *rip = NULL;
  int sizeX = 0;
  int sizeY = 0;
  int i;

  VerticalBox window(argv[1]);
  
  resize(window);

  window.setWindowTitle("XXX");
  window.show();
   return app.exec();
}

#ifdef adsfasdf 


  layout->addWidget(orgWindow);
  window->setLayout(layout);


  if (argv[2] != NULL && (i = atoi(argv[2])) != 0) {
    sizeX = i;
  }
  if (argv[3] != NULL && (i = atoi(argv[3])) != 0) {
    sizeY = i;
  }

  window->setWindowTitle("Agenda org");
  window->show();

  return app.exec();
}
#endif
