#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QThread>
#include <QTcpSocket>

class SocketThread : public QThread
{
public:
    SocketThread(qintptr handle);

    QTcpSocket *socket;

    void run() override;

    void messageHandler();
};

#endif // SOCKETTHREAD_H
