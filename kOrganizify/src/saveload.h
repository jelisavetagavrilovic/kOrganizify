#ifndef SAVELOAD_H
#define SAVELOAD_H

#include <QObject>
#include <QJsonObject>

class SaveLoad : public QObject
{
    Q_OBJECT

public:
    explicit SaveLoad(QObject *parent = nullptr);
    QString getFilePath(const QString &username);
    QJsonObject m_jsonObject;

public slots:
    void saveData(const QString &username);
    void loadData(const QString &username);
};

#endif // SAVELOAD_H
