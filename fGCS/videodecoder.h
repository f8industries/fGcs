#ifndef VIDEODECODER_H
#define VIDEODECODER_H

#include <QThread>
#include <QUdpSocket>

class videoDecoder : public QThread
{
    Q_OBJECT
public:
    explicit videoDecoder(QObject *parent = 0);

signals:
    void frameRecieved(int i);

public slots:
    void readyRead();

private:
    QUdpSocket *socket;



};

#endif // VIDEODECODER_H
