#ifndef BASICEVENTWINDOW_H
#define BASICEVENTWINDOW_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "basicevent.h"
#include "calendar.h"

namespace Ui {
class BasicEventWindow;
}

class BasicEventWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BasicEventWindow(QWidget *parent = nullptr);
    ~BasicEventWindow();

private slots:
    // void addEvents();
    void removeEvent();
    void generate();
    void nextEvent();
    void previousEvent();


private:
    Ui::BasicEventWindow *ui;
};

#endif // BASICEVENTWINDOW_H
