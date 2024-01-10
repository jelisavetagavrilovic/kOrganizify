#include "settingswindow.h"
#include "ui_settingswindow.h"
#include <QDir>
#include <QMap>

SettingsWindow::SettingsWindow(Settings *settings, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SettingsWindow), m_settings(settings) {
  ui->setupUi(this);
  setWindowTitle("Settings");
  setFixedSize(size());

  if (getNotifications()) {
    ui->lblNotificationsOn->setVisible(true);
    ui->lblNotificationsOff->setVisible(false);
  } else {
    ui->lblNotificationsOn->setVisible(false);
    ui->lblNotificationsOff->setVisible(true);
  }

  ui->cbxDropTheme->setCurrentText(colorToText(getColor()));

  connect(ui->cbNotifications, &QCheckBox::stateChanged, this,
          &SettingsWindow::updateNotificationIcon);
  connect(ui->cbxDropTheme,
          QOverload<const QString &>::of(&QComboBox::currentTextChanged),
          [=](const QString &text) {
            QString color = textToColor(text);

            QString path = colorToPath(color);

            setColor(color);
            setBackgroundPath(path);

            QString styleSheet = QString("background-color: %1; ").arg(color);
            QString btnStyleSheet =
                QString("QPushButton{" + styleSheet +
                        "border-radius: 10px; color:black;}");
            ui->btnSave->setStyleSheet(btnStyleSheet);
            ui->cbxDropTheme->setStyleSheet(
                QString("QComboBox{color: black; border-radius:10px; "
                        "background-color: %1; }")
                    .arg(color));
          });

  connect(ui->btnSave, &QPushButton::clicked, this, &SettingsWindow::save);
}

void SettingsWindow::changeColor(QString color) {
  QString styleSheet = QString("background-color: %1; ").arg(color);
  QString btnStyleSheet = QString("QPushButton{" + styleSheet +
                                  "border-radius: 10px; color:black;}");
  ui->btnSave->setStyleSheet(btnStyleSheet);
  ui->cbxDropTheme->setStyleSheet(
      QString(
          "QComboBox{color: black; border-radius:10px; background-color: %1; }")
          .arg(color));
}

void SettingsWindow::setBackgroundPath(QString backgroundPath) {
  m_settings->setBackgroundPath(backgroundPath);
}

QString SettingsWindow::getBackgroundPath() {
  return m_settings->backgroundPath();
}

QString SettingsWindow::textToColor(QString text) {
  return m_themeColors.value(text);
}

QString SettingsWindow::textToPath(QString text) {
  QString sourceDir = QCoreApplication::applicationDirPath();
  QString pathBlue =
      QDir(sourceDir).filePath(":/resources/images/backgroundBlue.png");
  QString pathGreen =
      QDir(sourceDir).filePath(":/resources/images/backgroundGreen.png");
  QString pathOrange =
      QDir(sourceDir).filePath(":/resources/images/backgroundOrange.png");
  QString pathPink =
      QDir(sourceDir).filePath(":/resources/images/backgroundPink.png");
  QString pathPurple =
      QDir(sourceDir).filePath(":/resources/images/backgroundPurple.png");
  QString pathDefault =
      QDir(sourceDir).filePath(":/resources/images/backgroundDefault.png");

  QMap<QString, QString> themeBackgrounds{
      {"Blue", pathBlue}, {"Green", pathGreen},   {"Orange", pathOrange},
      {"Pink", pathPink}, {"Purple", pathPurple}, {"Default", pathDefault}};

  return themeBackgrounds.value(text, themeBackgrounds["Default"]);
}

QString SettingsWindow::colorToPath(QString color) {
  return textToPath(colorToText(color));
}

QString SettingsWindow::colorToText(QString color) {
  return m_themeColors.key(color);
}

void SettingsWindow::save() {
  emit colorChanged(m_settings->getColor());
  emit enabledNotifications(ui->cbNotifications->isChecked());
  close();
}

void SettingsWindow::setColor(const QString color) {
  m_settings->setColor(color);
}

QString SettingsWindow::getColor() { return m_settings->getColor(); }

QString
SettingsWindow::getColorNameFromValue(const QMap<QString, QString> &colorMap,
                                      const QString &value) {
  for (auto it = colorMap.begin(); it != colorMap.end(); ++it) {
    if (it.value() == value) {
      return it.key();
    }
  }
  return "";
}

void SettingsWindow::setNotifications(const bool notification) {
  m_settings->setNotifications(notification);
}

bool SettingsWindow::getNotifications() const {
  return m_settings->getNotifications();
}

void SettingsWindow::updateNotificationIcon(bool state) {
  if (state) {
    ui->lblNotificationsOn->setVisible(true);
    ui->lblNotificationsOff->setVisible(false);
  } else {
    ui->lblNotificationsOn->setVisible(false);
    ui->lblNotificationsOff->setVisible(true);
  }
}

SettingsWindow::~SettingsWindow() { delete ui; }
