#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();
    void setColor(QString color);
    QString getColor();

private slots:
    void on_btnSave_clicked();
signals:
    void colorChanged(const QString& color);
private:
    Ui::SettingsWindow *ui;
    QString color;
};

#endif // SETTINGSWINDOW_H
