#include "widget.h"
#include "ui_widget.h"
#include <string>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pbConnect->setEnabled(false);
    ui->pbDisconnect->setEnabled(false);

    QObject::connect(&tcp_socket_, &QAbstractSocket::connected, this, &Widget::tcp_doConnected);
    //in tcp_socket_ connected signal event -> in now class event doConnected
    QObject::connect(&tcp_socket_, &QAbstractSocket::disconnected, this, &Widget::tcp_doDisconnected);
    QObject::connect(&tcp_socket_, &QAbstractSocket::readyRead, this, &Widget::tcp_doReadyread);

    QObject::connect(&ssl_socket_, &QAbstractSocket::connected, this, &Widget::ssl_doConnected);
    QObject::connect(&ssl_socket_, &QAbstractSocket::disconnected, this, &Widget::ssl_doDisconnected);
    QObject::connect(&ssl_socket_, &QAbstractSocket::readyRead, this, &Widget::ssl_doReadyread);

    QObject::connect(&tcp_socket_, &QAbstractSocket::stateChanged, this, &Widget::tcp_doButtonON);
    QObject::connect(&ssl_socket_, &QAbstractSocket::stateChanged, this, &Widget::ssl_doButtonON);
}


Widget::~Widget()
{
    delete ui;
}


void Widget::tcp_doButtonON()
{
    ui->pbDisconnect->setEnabled(true);
}


void Widget::ssl_doButtonON()
{
    ui->pbDisconnect->setEnabled(true);
}


void Widget::tcp_doConnected()
{
    QString msg = "Connected to " + tcp_socket_.peerAddress().toString() + "\r\r\n";
    ui->pteMessage->insertPlainText(msg);
}


void Widget::tcp_doDisconnected()
{
    QString msg = "Disconnected to " + tcp_socket_.peerAddress().toString() + "\r\r\n";
    ui->pteMessage->insertPlainText(msg);
}


void Widget::tcp_doReadyread()
{
    QByteArray ba = tcp_socket_.readAll();
    ui->pteMessage->insertPlainText(ba);
}


void Widget::ssl_doConnected()
{
    QString msg = "Connected to " + ssl_socket_.peerAddress().toString() + "\r\r\n";
    ui->pteMessage->insertPlainText(msg);
}


void Widget::ssl_doDisconnected()
{
    QString msg = "Disconnected to " + ssl_socket_.peerAddress().toString() + "\r\r\n";
    ui->pteMessage->insertPlainText(msg);
}


void Widget::ssl_doReadyread()
{
    QByteArray ba = ssl_socket_.readAll();
    ui->pteMessage->insertPlainText(ba);
}


void Widget::on_pbConnect_clicked()
{
    if (tcp_ssl_mod == 1){
        tcp_socket_.connectToHost(ui->leHost->text(), ui->lePort->text().toUShort());
    }else if (tcp_ssl_mod == 2){
        ssl_socket_.connectToHostEncrypted(ui->leHost->text(), ui->lePort->text().toUShort());
    }
    ui->pbConnect->setEnabled(false);
}


void Widget::on_pbDisconnect_clicked()
{
    tcp_socket_.close();
    ssl_socket_.close();

    ui->pbDisconnect->setEnabled(false);
}


void Widget::on_pbSend_clicked()
{
    if (tcp_ssl_mod == 1){
        tcp_socket_.write(ui->pteSend->toPlainText().toUtf8());
    }else if (tcp_ssl_mod == 2){
        ssl_socket_.write(ui->pteSend->toPlainText().toUtf8());
    }else{
        ui->pteMessage->insertPlainText("on_pbSend_clicked_Error\r\n");
    }
}


void Widget::on_pbClear_clicked()
{
    ui->pteMessage->clear();
}


void Widget::on_pbSSL_clicked()
{
    ui->lePort->clear();
    ui->lePort->setText("443");
    tcp_ssl_mod = 2;
    ui->pbConnect->setEnabled(true);
}


void Widget::on_pbTCP_clicked()
{
    ui->lePort->clear();
    ui->lePort->setText("80");
    tcp_ssl_mod = 1;
    ui->pbConnect->setEnabled(true);
}

