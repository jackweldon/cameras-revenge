#ifndef SMTP_H
#define SMTP_H

#include <QWidget>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QtWidgets/QMessageBox>
#include <QString>
#include <QFile>
#include <QFileDialog>
namespace Ui {
class smtp;
}

class smtp : public QWidget
{
    Q_OBJECT

public:
    explicit smtp(QWidget *parent = 0);
    ~smtp();

    void sendMail( const QString &from, const QString &to,
                       const QString &subject, const QString &body, QStringList files = QStringList());

    signals:
        void status( const QString &);
        void complete(bool);

    private slots:
        void buttonSend();
        void getAttachment();
        void stateChanged(QAbstractSocket::SocketState socketState);
        void errorReceived(QAbstractSocket::SocketError socketError);
        void disconnected();
        void connected();
        void readyRead();

    private:
        Ui::smtp *ui;
        int timeout;
        QString message;
        QTextStream *t;
        QSslSocket *socket;
        QString from;
        QString rcpt;
        QString response;
        QString user;
        QString pass;
        QStringList files;
        QString host;
        int port;
        enum states{Tls, HandShake ,Auth,User,Pass,Rcpt,Mail,Data,Init,Body,Quit,Close};
        int state;

    };
#endif // SMTP_H
