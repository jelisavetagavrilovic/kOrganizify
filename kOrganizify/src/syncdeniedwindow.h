#ifndef SYNCDENIEDWINDOW_H
#define SYNCDENIEDWINDOW_H

#include <QWidget>

namespace Ui {
class SyncDeniedWindow;
}

class SyncDeniedWindow : public QWidget {
  Q_OBJECT

public:
  explicit SyncDeniedWindow(QString friendName, QWidget *parent = nullptr);
  ~SyncDeniedWindow();

private:
  Ui::SyncDeniedWindow *ui;
};

#endif // SYNCDENIEDWINDOW_H
