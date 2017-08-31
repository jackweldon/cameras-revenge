#include "smtp.h"
#include "ui_smtp.h"
#include <QFileInfo>

smtp::smtp(QWidget *parent):
    QWidget(parent),
    ui(new Ui::smtp)
{
    ui->setupUi(this);

    //delete from memory
    setAttribute(Qt::WA_DeleteOnClose);
    socket = new QSslSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected() ) );
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this,SLOT(errorReceived(QAbstractSocket::SocketError)));
    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));
    connect(socket, SIGNAL(disconnected()), this,SLOT(disconnected()));

    connect(ui->btnSend,SIGNAL(clicked()),this,SLOT(buttonSend()));
    connect(ui->btnAttach,SIGNAL(clicked()),this,SLOT(getAttachment()));
    connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(close()));

    this->user = "tempqtemail@gmail.com"; //senders email address
    this->pass = "creator12"; //add your password for the email account
    this->host = "smtp.gmail.com"; //change the host if not using gmail
    this->port = 465; //port for smtp
    this->timeout = 40000; //timeout in milliseconds

}

smtp::~smtp()
{
    delete t;
    delete socket;
    delete ui;
}
void smtp::buttonSend(){
    if(ui->editReciepient->text().isEmpty()){
        QMessageBox::information(this,"Error","Please provide a recipient",QMessageBox::Ok);
        return;
    }
    if(ui->editSubject->text().isEmpty()){
        QMessageBox::information(this,"Error","Please provide a subject",QMessageBox::Ok);
        return;
    }
    if(ui->textBody->toPlainText().isEmpty()){
        QMessageBox::information(this,"Error","Please provide a body",QMessageBox::Ok);

    }
    else{
       if(!files.empty())
       sendMail(user,ui->editReciepient->text(),
                       ui->editSubject->text(),ui->textBody->toPlainText(),files);
       else
       sendMail(user,ui->editReciepient->text(),
                           ui->editSubject->text(),ui->textBody->toPlainText());

    emit complete(true);
     //smtp::~smtp();
    }
}
void smtp::getAttachment(){
    QString fileName =
            QFileDialog::getOpenFileName(this, tr("Open File"),QDir::currentPath(),"Image Files (*.png *.jpg *.bmp)");

    if(fileName!= NULL){
        files.push_front(fileName);
        ui->editAtttach->setText(fileName);
    }
    else{
        //nada
    }
}


void smtp::sendMail(const QString &from, const QString &to, const QString &subject, const QString &body, QStringList files)
{
    message = "To: " + to + "\n";
    message.append("From: " + from + "\n");
    message.append("Subject: " + subject + "\n");

    //Let's intitiate multipart MIME with cutting boundary "frontier"
    message.append("MIME-Version: 1.0\n");
    message.append("Content-Type: multipart/mixed; boundary=frontier\n\n");



    message.append( "--frontier\n" );
    //message.append( "Content-Type: text/html\n\n" );  //Uncomment this for HTML formating, coment the line below
    message.append( "Content-Type: text/plain\n\n" );
    message.append(body);
    message.append("\n\n");

    if(!files.isEmpty())
    {
        qDebug() << "Files to be sent: " << files.size();
        foreach(QString filePath, files)
        {
            QFile file(filePath);
            if(file.exists())
            {
                if (!file.open(QIODevice::ReadOnly))
                {
                    qDebug("Couldn't open the file");
                    QMessageBox::warning( 0, tr( "Qt Simple smtp client" ), tr( "Couldn't open the file\n\n" )  );
                        return ;
                }
                QByteArray bytes = file.readAll();
                message.append( "--frontier\n" );
                message.append( "Content-Type: application/octet-stream\nContent-Disposition: attachment; filename="+ QFileInfo(file.fileName()).fileName() +";\nContent-Transfer-Encoding: base64\n\n" );
                message.append(bytes.toBase64());
                message.append("\n");
            }
        }
    }
    else
        qDebug() << "No attachments found";


    message.append( "--frontier--\n" );

    message.replace( QString::fromLatin1( "\n" ), QString::fromLatin1( "\r\n" ) );
    message.replace( QString::fromLatin1( "\r\n.\r\n" ),QString::fromLatin1( "\r\n..\r\n" ) );


    this->from = from;
    rcpt = to;
    state = Init;
    socket->connectToHostEncrypted(host, port); //"smtp.gmail.com" and 465 for gmail TLS
    if (!socket->waitForConnected(timeout)) {
         qDebug() << socket->errorString();
     }

    t = new QTextStream( socket );

}

void smtp::stateChanged(QAbstractSocket::SocketState socketState)
{

    qDebug() <<"stateChanged " << socketState;
}

void smtp::errorReceived(QAbstractSocket::SocketError socketError)
{
    qDebug() << "error " <<socketError;
}

void smtp::disconnected()
{

    qDebug() <<"disconneted";
    qDebug() << "error "  << socket->errorString();
}

void smtp::connected()
{
    qDebug() << "Connected ";
}

void smtp::readyRead()
{

     qDebug() <<"readyRead";
    // smtp is line-oriented

    QString responseLine;
    do
    {
        responseLine = socket->readLine();
        response += responseLine;
    }
    while ( socket->canReadLine() && responseLine[3] != ' ' );

    responseLine.truncate( 3 );

    qDebug() << "Server response code:" <<  responseLine;
    qDebug() << "Server response: " << response;

    if ( state == Init && responseLine == "220" )
    {
        // banner was okay, let's go on
        *t << "EHLO localhost" <<"\r\n";
        t->flush();

        state = HandShake;
    }

    else if (state == HandShake && responseLine == "250")
    {
        socket->startClientEncryption();
        if(!socket->waitForEncrypted(timeout))
        {
            qDebug() << socket->errorString();
            state = Close;
        }

        *t << "EHLO localhost" << "\r\n";
        t->flush();
        state = Auth;
    }
    else if (state == Auth && responseLine == "250")
    {
        // Trying AUTH
        qDebug() << "Auth";
        *t << "AUTH LOGIN" << "\r\n";
        t->flush();
        state = User;
    }
    else if (state == User && responseLine == "334")
    {
        //Trying User
        qDebug() << "Username";
        //GMAIL is using XOAUTH2 protocol, which basically means that password and username has to be sent in base64 coding
        //https://developers.google.com/gmail/xoauth2_protocol
        *t << QByteArray().append(user).toBase64()  << "\r\n";
        t->flush();

        state = Pass;
    }
    else if (state == Pass && responseLine == "334")
    {
        //Trying pass
        qDebug() << "Pass";
        *t << QByteArray().append(pass).toBase64() << "\r\n";
        t->flush();

        state = Mail;
    }
    else if ( state == Mail && responseLine == "235" )
    {
        // HELO response was okay (well, it has to be)

        //Apperantly for Google it is mandatory to have MAIL FROM and RCPT email formated the following way -> <email@gmail.com>
        qDebug() << "MAIL FROM:<" << from << ">";
        *t << "MAIL FROM:<" << from << ">\r\n";
        t->flush();
        state = Rcpt;
    }
    else if ( state == Rcpt && responseLine == "250" )
    {
        //Apperantly for Google it is mandatory to have MAIL FROM and RCPT email formated the following way -> <email@gmail.com>
        *t << "RCPT TO:<" << rcpt << ">\r\n"; //r
        t->flush();
        state = Data;
    }
    else if ( state == Data && responseLine == "250" )
    {

        *t << "DATA\r\n";
        t->flush();
        state = Body;
    }
    else if ( state == Body && responseLine == "354" )
    {

        *t << message << "\r\n.\r\n";
        t->flush();
        state = Quit;
    }
    else if ( state == Quit && responseLine == "250" )
    {

        *t << "QUIT\r\n";
        t->flush();
        // here, we just close.
        state = Close;
        emit status( tr( "Message sent" ) );
    }
    else if ( state == Close )
    {
        deleteLater();
        return;
    }
    else
    {
        // something broke.
        QMessageBox::warning( 0, tr( "Qt Simple smtp client" ), tr( "Unexpected reply from smtp server:\n\n" ) + response );
        state = Close;
        emit status( tr( "Failed to send message" ) );
    }
    response = "";
}
