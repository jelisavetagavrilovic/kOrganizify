#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>

//QT_BEGIN_NAMESPACE
//namespace Ui { class AppWindow; }
//QT_END_NAMESPACE

namespace Ui {
class AppWindow;
}

class AppWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppWindow(QWidget *parent = nullptr);
    ~AppWindow();

private slots:
    void on_btnSettings_clicked();

private:
    Ui::AppWindow *ui;
};

#endif // APPWINDOW_H
