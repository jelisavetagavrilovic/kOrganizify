#ifndef SYNCRESPONSEWINDOW_H
#define SYNCRESPONSEWINDOW_H

#include <QWidget>

namespace Ui {
class SyncResponseWindow;
}

class SyncResponseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SyncResponseWindow(QString friendName, QString title, int duration, QWidget *parent = nullptr);
    ~SyncResponseWindow();

signals:
    void yesResponse(QString friendName);
    void noResponse(QString friendName);

private:
    Ui::SyncResponseWindow *ui;
    void sendNo();
    void sendYes();
    QString m_friendName;
};

#endif // SYNCRESPONSEWINDOW_H
