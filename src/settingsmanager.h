#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QObject>
#include <QSettings>
#include "settingsmanagerview.h"

class SettingsManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int kiwixServerPort READ getKiwixServerPort NOTIFY portChanged)
    Q_PROPERTY(qreal zoomFactor READ getZoomFactor NOTIFY zoomChanged)

public:
    explicit SettingsManager(QObject *parent = nullptr);
    virtual ~SettingsManager() {};

    SettingsManagerView* getView();
    bool isSettingsViewdisplayed() { return m_settingsViewDisplayed; };
    void setSettings(const QString &key, const QVariant &value);
    void deleteSettings(const QString &key);
    bool settingsExists(const QString &key);
    QVariant getSettings(const QString &key);
    qreal getZoomFactorByZimId(const QString &id);

public slots:
    void setKiwixServerPort(int port);
    int getKiwixServerPort() { return m_kiwixServerPort; };
    void setZoomFactor(qreal zoomFactor);
    qreal getZoomFactor() { return m_zoomFactor; };

private:
    void initSettings();

signals:
    void portChanged(int port);
    void zoomChanged(qreal zoomFactor);

private:
    QSettings m_settings;
    bool m_settingsViewDisplayed;
    int m_kiwixServerPort;
    qreal m_zoomFactor;
};

#endif // SETTINGSMANAGER_H
