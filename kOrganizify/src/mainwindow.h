#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// #include <QGroupBox>
// #include <QLineEdit>
// #include <QPushButton>
// #include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool userExists(const QString &username);

private slots:
    void login();
    void registerUser();
};

#endif // MAINWINDOW_H
