/********************************************************************************
** Form generated from reading UI file 'demo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMO_H
#define UI_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Demo
{
public:
    QWidget *centralwidget;
    QPushButton *PBLoad;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *te_threshold;
    QTextEdit *textEditMax;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QTextEdit *textEditTHR1;
    QTextEdit *textEdit_THR2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Demo)
    {
        if (Demo->objectName().isEmpty())
            Demo->setObjectName(QString::fromUtf8("Demo"));
        Demo->resize(800, 600);
        centralwidget = new QWidget(Demo);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PBLoad = new QPushButton(centralwidget);
        PBLoad->setObjectName(QString::fromUtf8("PBLoad"));
        PBLoad->setGeometry(QRect(300, 280, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 70, 101, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 170, 91, 31));
        te_threshold = new QTextEdit(centralwidget);
        te_threshold->setObjectName(QString::fromUtf8("te_threshold"));
        te_threshold->setGeometry(QRect(200, 70, 104, 31));
        textEditMax = new QTextEdit(centralwidget);
        textEditMax->setObjectName(QString::fromUtf8("textEditMax"));
        textEditMax->setGeometry(QRect(360, 70, 104, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 40, 47, 13));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(390, 40, 47, 13));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(230, 150, 61, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(390, 150, 61, 16));
        textEditTHR1 = new QTextEdit(centralwidget);
        textEditTHR1->setObjectName(QString::fromUtf8("textEditTHR1"));
        textEditTHR1->setGeometry(QRect(200, 180, 104, 31));
        textEdit_THR2 = new QTextEdit(centralwidget);
        textEdit_THR2->setObjectName(QString::fromUtf8("textEdit_THR2"));
        textEdit_THR2->setGeometry(QRect(360, 180, 104, 31));
        Demo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Demo);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Demo->setMenuBar(menubar);
        statusbar = new QStatusBar(Demo);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Demo->setStatusBar(statusbar);

        retranslateUi(Demo);

        QMetaObject::connectSlotsByName(Demo);
    } // setupUi

    void retranslateUi(QMainWindow *Demo)
    {
        Demo->setWindowTitle(QCoreApplication::translate("Demo", "Demo", nullptr));
        PBLoad->setText(QCoreApplication::translate("Demo", "Load Image", nullptr));
        label->setText(QCoreApplication::translate("Demo", "<html><head/><body><p>Thresholding :</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Demo", "<html><head/><body><p>Edge Detection :</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Demo", "Threshold", nullptr));
        label_4->setText(QCoreApplication::translate("Demo", "MaxVal", nullptr));
        label_5->setText(QCoreApplication::translate("Demo", "Threshold 1", nullptr));
        label_6->setText(QCoreApplication::translate("Demo", "Threshold 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Demo: public Ui_Demo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMO_H
