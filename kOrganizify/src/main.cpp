#include "basiceventwindow.h"
#include "mainwindow.h"

#include <QApplication>

auto main(int argc, char *argv[]) -> int {
  QApplication a(argc, argv);

  // Registracija CustomEventPriority za korišćenje u QVariant
  qRegisterMetaType<CustomEventPriority>("CustomEventPriority");

  MainWindow w;
  w.show();

  return a.exec();
}
