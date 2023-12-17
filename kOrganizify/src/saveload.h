#ifndef SAVELOAD_H
#define SAVELOAD_H

#include <QObject>
#include <QJsonObject>

class SaveLoad : public QObject
{
    Q_OBJECT
public:
    explicit SaveLoad(QObject *parent = nullptr);

public slots:
    void saveData(const QString &username, const QJsonObject &data);
    QJsonObject loadData(const QString &username);
    bool userExists(const QString &username);

private:
    QString getFilePath(const QString &username);
};

#endif // SAVELOAD_H
