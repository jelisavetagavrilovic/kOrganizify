#ifndef NOTIFICATIONSWINDOW_H
#define NOTIFICATIONSWINDOW_H

#include <QWidget>
#include <QDateTime>
#include <QTimer>

namespace Ui {
class NotificationsWindow;
}

class NotificationsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NotificationsWindow(QWidget *parent = nullptr);
    ~NotificationsWindow();

public slots:
    void updateWindow(const QString &name, const QString &time);

private:
    Ui::NotificationsWindow *ui;
};

#endif // NOTIFICATIONSWINDOW_H
