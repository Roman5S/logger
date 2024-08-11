#ifndef QRZRUCALLBOOK_H
#define QRZRUCALLBOOK_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class QrzruCallbook : public QObject
{
    Q_OBJECT
public:
    explicit QrzruCallbook(QString username, QString password, QObject *parent = nullptr);
    QStringList Get(QString call);

private:
    QString username;
    QString password;
    QString session_id;
    QDateTime session_time;

    QByteArray Request(QString url);
    QString getTagValue(QByteArray data, QString tag);
    void GetApiSession();

signals:
    void error404();
    void error();
};

#endif // QRZRUCALLBOOK_H
