#include "appwindow.h"
#include "ui_appwindow.h"

AppWindow::AppWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AppWindow)
{
    ui->setupUi(this);
    connect(ui->leInput, &QLineEdit::returnPressed, this, &AppWindow::addTask); // for Enter button
}

void AppWindow::addTask()
{
    const auto text = ui->leInput->text();

    if(!text.isEmpty()){
        Task task(text);
        ui->leInput->clear();

        this->m_toDoList.addTask(task);

        QListWidgetItem *item = new QListWidgetItem();
        ui->lwToDoList->addItem(item);

        QCheckBox *checkBox = new QCheckBox(task.getName());
        ui->lwToDoList->setItemWidget(item, checkBox);

        connect(checkBox, &QCheckBox::stateChanged, this, &AppWindow::onCheckBoxStateChanged);
    }
}

void AppWindow::onCheckBoxStateChanged(int state)
{
    QCheckBox *checkBox = qobject_cast<QCheckBox*>(sender());
    if (checkBox && state == Qt::Checked) {
        QString taskName = checkBox->text();

        this->m_toDoList.removeTask(taskName);

        // Uklanjanje elementa iz QListWidget-a
        QListWidgetItem *item = ui->lwToDoList->itemAt(checkBox->pos());
        if (item != nullptr) {
            int row = ui->lwToDoList->row(item);
            ui->lwToDoList->takeItem(row);
            delete item;
        }
    }
}

AppWindow::~AppWindow()
{
    delete ui;
}
