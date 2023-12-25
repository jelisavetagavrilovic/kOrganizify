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
    explicit ResponseWindow(QWidget *parent = nullptr);
    ~ResponseWindow();

public slots:
    void onYesClicked();
    void onNoClicked();

private slots:
    void setDate(QString& foundDate);
    QString getDate();

private:
    Ui::ResponseWindow *ui;
    QString m_date;
};

#endif // RESPONSEWINDOW_H
