/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *openFileButton;
    QPushButton *calculateButton;
    QTextBrowser *textBrowser;
    QTableWidget *operatorTable;
    QTableWidget *operandTable;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1053, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        openFileButton = new QPushButton(centralwidget);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));
        openFileButton->setGeometry(QRect(960, 10, 81, 51));
        calculateButton = new QPushButton(centralwidget);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setGeometry(QRect(960, 70, 81, 51));
        calculateButton->setMaximumSize(QSize(111, 16777215));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 381, 571));
        operatorTable = new QTableWidget(centralwidget);
        if (operatorTable->columnCount() < 3)
            operatorTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        operatorTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        operatorTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        operatorTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        operatorTable->setObjectName(QString::fromUtf8("operatorTable"));
        operatorTable->setGeometry(QRect(400, 10, 251, 571));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(operatorTable->sizePolicy().hasHeightForWidth());
        operatorTable->setSizePolicy(sizePolicy);
        operandTable = new QTableWidget(centralwidget);
        if (operandTable->columnCount() < 3)
            operandTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        operandTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        operandTable->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        operandTable->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        operandTable->setObjectName(QString::fromUtf8("operandTable"));
        operandTable->setGeometry(QRect(660, 10, 291, 571));
        sizePolicy.setHeightForWidth(operandTable->sizePolicy().hasHeightForWidth());
        operandTable->setSizePolicy(sizePolicy);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openFileButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214\n"
"\321\204\320\260\320\271\320\273", nullptr));
        calculateButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\207\320\270\321\202\320\260\321\202\321\214\n"
"\320\274\320\265\321\202\321\200\320\270\320\272\321\203", nullptr));
        QTableWidgetItem *___qtablewidgetitem = operatorTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "j", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = operatorTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\265\321\200\320\260\321\202\320\276\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = operatorTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "f\342\202\201j", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = operandTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "i", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = operandTable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\265\321\200\320\260\320\275\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = operandTable->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "f\342\202\202i", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
