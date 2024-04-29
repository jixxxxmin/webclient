/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pbConnect;
    QPushButton *pbDisconnect;
    QPushButton *pbClear;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *leHost;
    QLineEdit *lePort;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbTCP;
    QPushButton *pbSSL;
    QPlainTextEdit *pteMessage;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *pteSend;
    QPushButton *pbSend;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pbConnect = new QPushButton(Widget);
        pbConnect->setObjectName("pbConnect");

        horizontalLayout_4->addWidget(pbConnect);

        pbDisconnect = new QPushButton(Widget);
        pbDisconnect->setObjectName("pbDisconnect");

        horizontalLayout_4->addWidget(pbDisconnect);

        pbClear = new QPushButton(Widget);
        pbClear->setObjectName("pbClear");

        horizontalLayout_4->addWidget(pbClear);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        leHost = new QLineEdit(Widget);
        leHost->setObjectName("leHost");

        horizontalLayout_3->addWidget(leHost);

        lePort = new QLineEdit(Widget);
        lePort->setObjectName("lePort");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lePort->sizePolicy().hasHeightForWidth());
        lePort->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lePort);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pbTCP = new QPushButton(Widget);
        pbTCP->setObjectName("pbTCP");

        horizontalLayout_2->addWidget(pbTCP);

        pbSSL = new QPushButton(Widget);
        pbSSL->setObjectName("pbSSL");

        horizontalLayout_2->addWidget(pbSSL);


        verticalLayout->addLayout(horizontalLayout_2);

        pteMessage = new QPlainTextEdit(Widget);
        pteMessage->setObjectName("pteMessage");

        verticalLayout->addWidget(pteMessage);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pteSend = new QPlainTextEdit(Widget);
        pteSend->setObjectName("pteSend");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pteSend->sizePolicy().hasHeightForWidth());
        pteSend->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pteSend);

        pbSend = new QPushButton(Widget);
        pbSend->setObjectName("pbSend");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pbSend->sizePolicy().hasHeightForWidth());
        pbSend->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(pbSend);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Webclient", nullptr));
        pbConnect->setText(QCoreApplication::translate("Widget", "Connect", nullptr));
        pbDisconnect->setText(QCoreApplication::translate("Widget", "DIsconnect", nullptr));
        pbClear->setText(QCoreApplication::translate("Widget", "Clear", nullptr));
        leHost->setText(QCoreApplication::translate("Widget", "www.youtube.com", nullptr));
        lePort->setText(QCoreApplication::translate("Widget", "80", nullptr));
        pbTCP->setText(QCoreApplication::translate("Widget", "TCP", nullptr));
        pbSSL->setText(QCoreApplication::translate("Widget", "SSL", nullptr));
        pteSend->setPlainText(QCoreApplication::translate("Widget", "GET / HTTP/1.1\n"
"Host:www.youtube.com\n"
"\n"
"", nullptr));
        pbSend->setText(QCoreApplication::translate("Widget", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
