#ifndef SYNCRESPONSEWINDOW_H
#define SYNCRESPONSEWINDOW_H

#include <QWidget>

namespace Ui {
class SyncResponseWindow;
}

class SyncResponseWindow : public QWidget {
    Q_OBJECT

  public:
    explicit SyncResponseWindow(QString friendName, QString title, int duration, QWidget *parent = nullptr);
    ~SyncResponseWindow();
    void changeColor(QString color);

  signals:
    void yesResponse(QString friendName, int duration);
    void noResponse(QString friendName);

  private:
    QString m_friendName;
    void sendNo();
    void sendYes();
    int m_duration;
    Ui::SyncResponseWindow *ui;
};

#endif // SYNCRESPONSEWINDOW_H
