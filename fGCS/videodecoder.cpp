#include "videodecoder.h"

videoDecoder::videoDecoder(QObject *parent) :
    QThread(parent)
{
    socket = new QUdpSocket(this);

    socket->bind(QHostAddress::LocalHost, 1234);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void videoDecoder::readyRead()
{
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;


    socket->readDatagram(buffer.data(), buffer.size(),
                         &sender, &senderPort);

    //qDebug() << "Message from: " << sender.toString();
    //qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer.toInt();

    emit frameRecieved(buffer.toInt());
}
