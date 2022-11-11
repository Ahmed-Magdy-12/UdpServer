#include "widget.h"
#include "ui_widget.h"
#include "QUdpSocket"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_send_clicked()
{
    QByteArray datagram = ui->msj->text().toLatin1();
    mSocket->writeDatagram(datagram, QHostAddress::Broadcast,
                           ui->port_2->value());
}

