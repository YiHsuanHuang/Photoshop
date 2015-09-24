/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Load;
    QSlider *Brightness;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSlider *R_bar;
    QSlider *G_bar;
    QSlider *B_bar;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *Grayscale;
    QPushButton *Blur;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(465, 384);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Load = new QPushButton(centralWidget);
        Load->setObjectName(QStringLiteral("Load"));
        Load->setGeometry(QRect(20, 20, 93, 28));
        Brightness = new QSlider(centralWidget);
        Brightness->setObjectName(QStringLiteral("Brightness"));
        Brightness->setGeometry(QRect(20, 90, 181, 22));
        Brightness->setMinimum(-255);
        Brightness->setMaximum(255);
        Brightness->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 81, 16));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 180, 161, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        R_bar = new QSlider(verticalLayoutWidget);
        R_bar->setObjectName(QStringLiteral("R_bar"));
        R_bar->setMinimum(-255);
        R_bar->setMaximum(255);
        R_bar->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(R_bar);

        G_bar = new QSlider(verticalLayoutWidget);
        G_bar->setObjectName(QStringLiteral("G_bar"));
        G_bar->setMinimum(-255);
        G_bar->setMaximum(255);
        G_bar->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(G_bar);

        B_bar = new QSlider(verticalLayoutWidget);
        B_bar->setObjectName(QStringLiteral("B_bar"));
        B_bar->setMinimum(-255);
        B_bar->setMaximum(255);
        B_bar->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(B_bar);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 150, 81, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 190, 16, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 230, 16, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 270, 16, 16));
        Grayscale = new QPushButton(centralWidget);
        Grayscale->setObjectName(QStringLiteral("Grayscale"));
        Grayscale->setGeometry(QRect(220, 20, 93, 28));
        Blur = new QPushButton(centralWidget);
        Blur->setObjectName(QStringLiteral("Blur"));
        Blur->setGeometry(QRect(220, 60, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 465, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Load->setText(QApplication::translate("MainWindow", "Load Image", 0));
        label->setText(QApplication::translate("MainWindow", "Brightness bar", 0));
        label_2->setText(QApplication::translate("MainWindow", "RGB bar", 0));
        label_3->setText(QApplication::translate("MainWindow", "R", 0));
        label_4->setText(QApplication::translate("MainWindow", "G", 0));
        label_5->setText(QApplication::translate("MainWindow", "B", 0));
        Grayscale->setText(QApplication::translate("MainWindow", "Grayscale", 0));
        Blur->setText(QApplication::translate("MainWindow", "Blur", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
