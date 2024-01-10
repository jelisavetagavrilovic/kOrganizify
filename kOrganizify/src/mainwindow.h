// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "appwindow.h"
#include "user.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void loginUser();
  void registerUser();
  void appear();

private:
  Ui::MainWindow *ui;
  User *m_user;
};

#endif // MAINWINDOW_H
