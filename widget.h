#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QSslSocket>


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QTcpSocket tcp_socket_;
    QSslSocket ssl_socket_;

    int tcp_ssl_mod{1};

public slots:
    void tcp_doConnected();     //in socket connected event -> doConnected event
    void tcp_doDisconnected();
    void tcp_doReadyread();

    void ssl_doConnected();
    void ssl_doDisconnected();
    void ssl_doReadyread();

    void tcp_doButtonON();
    void ssl_doButtonON();

private slots:
    void on_pbConnect_clicked();

    void on_pbDisconnect_clicked();

    void on_pbSend_clicked();

    void on_pbClear_clicked();

    void on_pbSSL_clicked();

    void on_pbTCP_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
