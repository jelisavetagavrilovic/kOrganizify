#ifndef BASICEVENTWINDOW_H
#define BASICEVENTWINDOW_H

#include <QWidget>

namespace Ui {
class BasicEventWindow;
}

class BasicEventWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BasicEventWindow(QWidget *parent = nullptr);
    ~BasicEventWindow();

private:
    Ui::BasicEventWindow *ui;
};

#endif // BASICEVENTWINDOW_H
