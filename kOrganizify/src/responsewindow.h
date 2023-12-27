#ifndef RESPONSEWINDOW_H
#define RESPONSEWINDOW_H

#include <QString>
#include <QWidget>

namespace Ui {
class ResponseWindow;
}

class ResponseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ResponseWindow(QString eventTitle, QString startTime, QWidget *parent = nullptr);
    ~ResponseWindow();

public slots:
    void onYesClicked();
    void onNoClicked();

private slots:

signals:
    void sendResponse(bool answer);

private:
    void setDate(QString foundDate);
    void setTitle(QString title);
    QString getDate();
    Ui::ResponseWindow *ui;
    QString m_date;
};

#endif // RESPONSEWINDOW_H
