#ifndef EVENTWINDOW_H
#define EVENTWINDOW_H

#include <QWidget>

namespace Ui {
class EventWindow;
}

class EventWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EventWindow(QWidget *parent = nullptr);
    ~EventWindow();

private:
    Ui::EventWindow *ui;

private slots:
    // void on_btnGenerate_clicked();
    void on_btnSave_clicked();
};

#endif // EVENTWINDOW_H
