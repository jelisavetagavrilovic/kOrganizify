#include "saveload.h"
#include <QDir>
#include <QFile>
#include <QIODevice>
#include <QJsonDocument>
#include <QTextStream>
#include <QCoreApplication>

SaveLoad::SaveLoad(QObject *parent)
    : QObject(parent)
{}

QString SaveLoad::getFilePath(const QString &username) {
    // getting  the absolute path to the source code
    QString sourceDir = QCoreApplication::applicationDirPath();
    // adding "user_data" to the end of the path
    QString userDataDir = QDir(sourceDir).filePath("../kOrganizify/user_data");
    qDebug() << "Path:" << userDataDir << ".";

    QDir dir(userDataDir);
    if (!dir.exists())
        dir.mkpath(".");

    return QDir(userDataDir).filePath(QString("%1_data.json").arg(username));
}

void SaveLoad::saveData(const QString &username, const QJsonObject &data) {
    QString filePath = getFilePath(username);

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << QJsonDocument(data).toJson();
        file.close();
    }
}

void SaveLoad::loadData(const QString &username) {
    m_jsonObject = {};

    QString filePath = getFilePath(username);
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString jsonString = stream.readAll();
        file.close();

        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());
        m_jsonObject = jsonDoc.object();

    }
}
