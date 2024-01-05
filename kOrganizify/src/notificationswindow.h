#ifndef NOTIFICATIONSWINDOW_H
#define NOTIFICATIONSWINDOW_H

#include <QDateTime>
#include <QTimer>
#include <QWidget>

#include <QtMultimedia/QSoundEffect>

namespace Ui {
class NotificationsWindow;
}

class NotificationsWindow : public QWidget {
    Q_OBJECT

  public:
    explicit NotificationsWindow(QWidget *parent = nullptr);
    ~NotificationsWindow();

  public slots:
    void updateWindow(const QString &name, const QString &time, const QString &location);

  private:
    Ui::NotificationsWindow *ui;
    QSoundEffect *m_mediaPlayer;
};

#endif // NOTIFICATIONSWINDOW_H
