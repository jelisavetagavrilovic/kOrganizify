#include "syncdeniedwindow.h"
#include "ui_syncdeniedwindow.h"

SyncDeniedWindow::SyncDeniedWindow(QString friendName, QWidget *parent) : QWidget(parent), ui(new Ui::SyncDeniedWindow) {
    ui->setupUi(this);
    setWindowTitle("");
    setFixedSize(size());

    ui->lblMessage->setText("Your friend " + friendName + " doesn't want to sync with you :(");
}

SyncDeniedWindow::~SyncDeniedWindow() {
    delete ui;
}
