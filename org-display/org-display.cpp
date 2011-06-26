#include "timer.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QHBoxLayout>
#include <stdlib.h>
#include <stdio.h>


void resize(QWidget &widget, int width=200, int height=200)
{
  int screenHeight;
  int screenWidth;

  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();
  widget.setGeometry(10, 10, width, height);

}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  if (argc < 2) {
    printf("Usage %s <filename>\n", argv[0]);
    exit(1);
  }

  Timer window(argv[1],60);
  
  //resize(window);

  window.setWindowTitle(argv[1]);
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
