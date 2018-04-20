/********************************************************************************
** Form generated from reading UI file 'ide_cfactorial.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDE_CFACTORIAL_H
#define UI_IDE_CFACTORIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IDE_CFactorial
{
public:
    QWidget *centralWidget;
    QTextEdit *EditorC;
    QPushButton *RunButton;
    QTableView *RamLiveView;
    QPushButton *StepButton;
    QLabel *RamLiveViewTittle;
    QTextEdit *StdOut;
    QLabel *StdOutTittle;
    QTextEdit *ApplicationLog;
    QLabel *ApplicationLogTittle;
    QLabel *TituloEditor;
    QPushButton *StopButton;
    QPushButton *ClearAppLog;
    QPushButton *ClearStdOut;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IDE_CFactorial)
    {
        if (IDE_CFactorial->objectName().isEmpty())
            IDE_CFactorial->setObjectName(QStringLiteral("IDE_CFactorial"));
        IDE_CFactorial->setEnabled(true);
        IDE_CFactorial->resize(1100, 688);
        IDE_CFactorial->setAutoFillBackground(true);
        centralWidget = new QWidget(IDE_CFactorial);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        EditorC = new QTextEdit(centralWidget);
        EditorC->setObjectName(QStringLiteral("EditorC"));
        EditorC->setGeometry(QRect(10, 40, 551, 281));
        RunButton = new QPushButton(centralWidget);
        RunButton->setObjectName(QStringLiteral("RunButton"));
        RunButton->setGeometry(QRect(80, 10, 80, 23));
        RamLiveView = new QTableView(centralWidget);
        RamLiveView->setObjectName(QStringLiteral("RamLiveView"));
        RamLiveView->setGeometry(QRect(600, 41, 491, 281));
        StepButton = new QPushButton(centralWidget);
        StepButton->setObjectName(QStringLiteral("StepButton"));
        StepButton->setEnabled(true);
        StepButton->setGeometry(QRect(180, 10, 80, 23));
        RamLiveViewTittle = new QLabel(centralWidget);
        RamLiveViewTittle->setObjectName(QStringLiteral("RamLiveViewTittle"));
        RamLiveViewTittle->setGeometry(QRect(600, 10, 361, 20));
        StdOut = new QTextEdit(centralWidget);
        StdOut->setObjectName(QStringLiteral("StdOut"));
        StdOut->setGeometry(QRect(10, 360, 1081, 131));
        StdOut->setReadOnly(true);
        StdOutTittle = new QLabel(centralWidget);
        StdOutTittle->setObjectName(QStringLiteral("StdOutTittle"));
        StdOutTittle->setGeometry(QRect(20, 340, 59, 15));
        ApplicationLog = new QTextEdit(centralWidget);
        ApplicationLog->setObjectName(QStringLiteral("ApplicationLog"));
        ApplicationLog->setGeometry(QRect(10, 530, 1081, 131));
        ApplicationLog->setReadOnly(true);
        ApplicationLogTittle = new QLabel(centralWidget);
        ApplicationLogTittle->setObjectName(QStringLiteral("ApplicationLogTittle"));
        ApplicationLogTittle->setGeometry(QRect(20, 510, 101, 16));
        TituloEditor = new QLabel(centralWidget);
        TituloEditor->setObjectName(QStringLiteral("TituloEditor"));
        TituloEditor->setGeometry(QRect(10, 20, 59, 15));
        StopButton = new QPushButton(centralWidget);
        StopButton->setObjectName(QStringLiteral("StopButton"));
        StopButton->setEnabled(true);
        StopButton->setGeometry(QRect(280, 10, 80, 23));
        ClearAppLog = new QPushButton(centralWidget);
        ClearAppLog->setObjectName(QStringLiteral("ClearAppLog"));
        ClearAppLog->setGeometry(QRect(1010, 500, 80, 23));
        ClearStdOut = new QPushButton(centralWidget);
        ClearStdOut->setObjectName(QStringLiteral("ClearStdOut"));
        ClearStdOut->setGeometry(QRect(1010, 330, 80, 23));
        IDE_CFactorial->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(IDE_CFactorial);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        IDE_CFactorial->setStatusBar(statusBar);

        retranslateUi(IDE_CFactorial);

        QMetaObject::connectSlotsByName(IDE_CFactorial);
    } // setupUi

    void retranslateUi(QMainWindow *IDE_CFactorial)
    {
        IDE_CFactorial->setWindowTitle(QApplication::translate("IDE_CFactorial", "IDE_C!", 0));
        RunButton->setText(QApplication::translate("IDE_CFactorial", "Run", 0));
        StepButton->setText(QApplication::translate("IDE_CFactorial", "Step", 0));
        RamLiveViewTittle->setText(QApplication::translate("IDE_CFactorial", "Ram Live View", 0));
        StdOutTittle->setText(QApplication::translate("IDE_CFactorial", "StdOut", 0));
        ApplicationLogTittle->setText(QApplication::translate("IDE_CFactorial", "Application log", 0));
        TituloEditor->setText(QApplication::translate("IDE_CFactorial", "Editor", 0));
        StopButton->setText(QApplication::translate("IDE_CFactorial", "Stop", 0));
        ClearAppLog->setText(QApplication::translate("IDE_CFactorial", "Clear", 0));
        ClearStdOut->setText(QApplication::translate("IDE_CFactorial", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class IDE_CFactorial: public Ui_IDE_CFactorial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDE_CFACTORIAL_H
