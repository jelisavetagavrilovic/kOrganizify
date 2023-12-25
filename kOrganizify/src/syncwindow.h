#ifndef SYNCWINDOW_H
#define SYNCWINDOW_H

#include <QWidget>

namespace Ui {
class SyncWindow;
}

class SyncWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SyncWindow(QWidget *parent = nullptr);
    ~SyncWindow();

    QString getEnteredText() const;
    int getSelectedNumber() const;

private slots:
    void onTextEntered(const QString &m_text);
    void onNumberSelected(int m_index);
    void onSyncButtonClicked();

private:
    Ui::SyncWindow *ui;

    QString m_enteredText;
    int m_selectedNumber;
};

#endif // SYNCWINDOW_H
