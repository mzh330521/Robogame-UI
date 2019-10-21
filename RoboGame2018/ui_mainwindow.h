/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *logo;
    QLabel *Title;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *LStop;
    QPushButton *Start;
    QPushButton *RStop;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LTime;
    QLabel *CTime;
    QLabel *RTime;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QPushButton *Random;
    QPushButton *Countdown;
    QPushButton *Reset;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QLabel *L1;
    QLabel *L2;
    QLabel *L3;
    QLabel *L4;
    QLabel *L5;
    QLabel *L6;
    QLabel *L7;
    QLabel *L8;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_3;
    QLabel *R1;
    QLabel *R2;
    QLabel *R3;
    QLabel *R4;
    QLabel *R5;
    QLabel *R6;
    QLabel *R7;
    QLabel *R8;
    QLabel *LComment;
    QLabel *RComment;
    QPushButton *LScorePlus;
    QPushButton *LScoreMinus;
    QPushButton *RScorePlus;
    QPushButton *RScoreMinus;
    QPushButton *Swap;
    QLabel *LScore;
    QLabel *RScore;
    QLabel *TimeUp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1920, 1080);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        MainWindow->setFocusPolicy(Qt::NoFocus);
        MainWindow->setStyleSheet(QStringLiteral("background-color:rgb(230, 231, 235)"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        logo = new QLabel(centralWidget);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(1750, 950, 160, 120));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/logo.png")));
        logo->setScaledContents(true);
        Title = new QLabel(centralWidget);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(329, 0, 1271, 151));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(52);
        font1.setBold(true);
        font1.setWeight(75);
        Title->setFont(font1);
        Title->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(350, 470, 1221, 121));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        LStop = new QPushButton(layoutWidget);
        LStop->setObjectName(QStringLiteral("LStop"));
        LStop->setMaximumSize(QSize(360, 120));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(32);
        font2.setBold(true);
        font2.setUnderline(false);
        font2.setWeight(75);
        LStop->setFont(font2);
        LStop->setCursor(QCursor(Qt::OpenHandCursor));
        LStop->setMouseTracking(false);
        LStop->setFocusPolicy(Qt::StrongFocus);
        LStop->setStyleSheet(QLatin1String("color:rgb(40, 64, 121);\n"
"background-color:qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(17, 117, 192, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border:none;"));
        LStop->setCheckable(false);
        LStop->setAutoDefault(false);

        horizontalLayout->addWidget(LStop);

        Start = new QPushButton(layoutWidget);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setMaximumSize(QSize(360, 120));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(32);
        font3.setBold(true);
        font3.setWeight(75);
        Start->setFont(font3);
        Start->setCursor(QCursor(Qt::OpenHandCursor));
        Start->setFocusPolicy(Qt::StrongFocus);
        Start->setStyleSheet(QLatin1String("color:rgb(97, 106, 88);\n"
"background-color:qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(149, 164, 141, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border:none;\n"
""));

        horizontalLayout->addWidget(Start);

        RStop = new QPushButton(layoutWidget);
        RStop->setObjectName(QStringLiteral("RStop"));
        RStop->setMaximumSize(QSize(360, 120));
        RStop->setFont(font3);
        RStop->setCursor(QCursor(Qt::OpenHandCursor));
        RStop->setFocusPolicy(Qt::StrongFocus);
        RStop->setStyleSheet(QLatin1String("color:rgb(121, 31, 34);\n"
"background-color:qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 111, 111, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border:none;"));

        horizontalLayout->addWidget(RStop);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(320, 240, 1281, 141));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        LTime = new QLabel(layoutWidget1);
        LTime->setObjectName(QStringLiteral("LTime"));
        LTime->setMaximumSize(QSize(250, 100));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font4.setPointSize(64);
        LTime->setFont(font4);
        LTime->setStyleSheet(QStringLiteral("color:rgb(40, 64, 121);"));

        horizontalLayout_2->addWidget(LTime);

        CTime = new QLabel(layoutWidget1);
        CTime->setObjectName(QStringLiteral("CTime"));
        CTime->setMaximumSize(QSize(250, 100));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font5.setPointSize(64);
        font5.setBold(false);
        font5.setWeight(50);
        CTime->setFont(font5);

        horizontalLayout_2->addWidget(CTime);

        RTime = new QLabel(layoutWidget1);
        RTime->setObjectName(QStringLiteral("RTime"));
        RTime->setMaximumSize(QSize(250, 100));
        RTime->setFont(font5);
        RTime->setStyleSheet(QStringLiteral("color:rgb(121, 31, 34);"));

        horizontalLayout_2->addWidget(RTime);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(780, 590, 362, 491));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Random = new QPushButton(layoutWidget2);
        Random->setObjectName(QStringLiteral("Random"));
        Random->setMaximumSize(QSize(360, 120));
        Random->setFont(font3);
        Random->setCursor(QCursor(Qt::OpenHandCursor));
        Random->setFocusPolicy(Qt::StrongFocus);
        Random->setStyleSheet(QLatin1String("color:rgb(97, 106, 88);\n"
"background-color:qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(149, 164, 141, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border:none;"));

        verticalLayout->addWidget(Random);

        Countdown = new QPushButton(layoutWidget2);
        Countdown->setObjectName(QStringLiteral("Countdown"));
        Countdown->setMaximumSize(QSize(360, 120));
        Countdown->setFont(font3);
        Countdown->setCursor(QCursor(Qt::OpenHandCursor));
        Countdown->setFocusPolicy(Qt::StrongFocus);
        Countdown->setStyleSheet(QLatin1String("color:rgb(97, 106, 88);\n"
"background-color:qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(149, 164, 141, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border:none;"));

        verticalLayout->addWidget(Countdown);

        Reset = new QPushButton(layoutWidget2);
        Reset->setObjectName(QStringLiteral("Reset"));
        Reset->setMaximumSize(QSize(360, 120));
        Reset->setFont(font3);
        Reset->setCursor(QCursor(Qt::OpenHandCursor));
        Reset->setFocusPolicy(Qt::StrongFocus);
        Reset->setStyleSheet(QLatin1String("color:rgb(97, 106, 88);\n"
"background-color:qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(149, 164, 141, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border:none;"));

        verticalLayout->addWidget(Reset);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(200, 133, 122, 951));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        L1 = new QLabel(layoutWidget3);
        L1->setObjectName(QStringLiteral("L1"));
        L1->setMinimumSize(QSize(100, 100));
        L1->setMaximumSize(QSize(120, 100));
        L1->setPixmap(QPixmap(QString::fromUtf8(":/character/\347\272\242.JPG")));
        L1->setScaledContents(true);

        verticalLayout_2->addWidget(L1);

        L2 = new QLabel(layoutWidget3);
        L2->setObjectName(QStringLiteral("L2"));
        L2->setMaximumSize(QSize(120, 100));
        L2->setPixmap(QPixmap(QString::fromUtf8(":/character/\344\270\223.JPG")));
        L2->setScaledContents(true);

        verticalLayout_2->addWidget(L2);

        L3 = new QLabel(layoutWidget3);
        L3->setObjectName(QStringLiteral("L3"));
        L3->setMaximumSize(QSize(120, 100));
        L3->setPixmap(QPixmap(QString::fromUtf8(":/character/\345\271\266.JPG")));
        L3->setScaledContents(true);

        verticalLayout_2->addWidget(L3);

        L4 = new QLabel(layoutWidget3);
        L4->setObjectName(QStringLiteral("L4"));
        L4->setMaximumSize(QSize(120, 100));
        L4->setPixmap(QPixmap(QString::fromUtf8(":/character/\350\277\233.JPG")));
        L4->setScaledContents(true);

        verticalLayout_2->addWidget(L4);

        L5 = new QLabel(layoutWidget3);
        L5->setObjectName(QStringLiteral("L5"));
        L5->setMaximumSize(QSize(120, 100));
        L5->setPixmap(QPixmap(QString::fromUtf8(":/character/\347\220\206.JPG")));
        L5->setScaledContents(true);

        verticalLayout_2->addWidget(L5);

        L6 = new QLabel(layoutWidget3);
        L6->setObjectName(QStringLiteral("L6"));
        L6->setMaximumSize(QSize(120, 100));
        L6->setPixmap(QPixmap(QString::fromUtf8(":/character/\345\256\236.JPG")));
        L6->setScaledContents(true);

        verticalLayout_2->addWidget(L6);

        L7 = new QLabel(layoutWidget3);
        L7->setObjectName(QStringLiteral("L7"));
        L7->setMaximumSize(QSize(120, 100));
        L7->setPixmap(QPixmap(QString::fromUtf8(":/character/\344\272\244.JPG")));
        L7->setScaledContents(true);

        verticalLayout_2->addWidget(L7);

        L8 = new QLabel(layoutWidget3);
        L8->setObjectName(QStringLiteral("L8"));
        L8->setMaximumSize(QSize(120, 100));
        L8->setPixmap(QPixmap(QString::fromUtf8(":/character/\350\236\215.JPG")));
        L8->setScaledContents(true);

        verticalLayout_2->addWidget(L8);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(1600, 132, 122, 951));
        verticalLayout_3 = new QVBoxLayout(layoutWidget4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        R1 = new QLabel(layoutWidget4);
        R1->setObjectName(QStringLiteral("R1"));
        R1->setMinimumSize(QSize(100, 100));
        R1->setMaximumSize(QSize(120, 100));
        R1->setPixmap(QPixmap(QString::fromUtf8(":/character/\347\272\242.JPG")));
        R1->setScaledContents(true);

        verticalLayout_3->addWidget(R1);

        R2 = new QLabel(layoutWidget4);
        R2->setObjectName(QStringLiteral("R2"));
        R2->setMaximumSize(QSize(120, 100));
        R2->setPixmap(QPixmap(QString::fromUtf8(":/character/\344\270\223.JPG")));
        R2->setScaledContents(true);

        verticalLayout_3->addWidget(R2);

        R3 = new QLabel(layoutWidget4);
        R3->setObjectName(QStringLiteral("R3"));
        R3->setMaximumSize(QSize(120, 100));
        R3->setPixmap(QPixmap(QString::fromUtf8(":/character/\345\271\266.JPG")));
        R3->setScaledContents(true);

        verticalLayout_3->addWidget(R3);

        R4 = new QLabel(layoutWidget4);
        R4->setObjectName(QStringLiteral("R4"));
        R4->setMaximumSize(QSize(120, 100));
        R4->setPixmap(QPixmap(QString::fromUtf8(":/character/\350\277\233.JPG")));
        R4->setScaledContents(true);

        verticalLayout_3->addWidget(R4);

        R5 = new QLabel(layoutWidget4);
        R5->setObjectName(QStringLiteral("R5"));
        R5->setMaximumSize(QSize(120, 100));
        R5->setPixmap(QPixmap(QString::fromUtf8(":/character/\347\220\206.JPG")));
        R5->setScaledContents(true);

        verticalLayout_3->addWidget(R5);

        R6 = new QLabel(layoutWidget4);
        R6->setObjectName(QStringLiteral("R6"));
        R6->setMaximumSize(QSize(120, 100));
        R6->setPixmap(QPixmap(QString::fromUtf8(":/character/\345\256\236.JPG")));
        R6->setScaledContents(true);

        verticalLayout_3->addWidget(R6);

        R7 = new QLabel(layoutWidget4);
        R7->setObjectName(QStringLiteral("R7"));
        R7->setMaximumSize(QSize(120, 100));
        R7->setPixmap(QPixmap(QString::fromUtf8(":/character/\344\272\244.JPG")));
        R7->setScaledContents(true);

        verticalLayout_3->addWidget(R7);

        R8 = new QLabel(layoutWidget4);
        R8->setObjectName(QStringLiteral("R8"));
        R8->setMaximumSize(QSize(120, 100));
        R8->setPixmap(QPixmap(QString::fromUtf8(":/character/\350\236\215.JPG")));
        R8->setScaledContents(true);

        verticalLayout_3->addWidget(R8);

        LComment = new QLabel(centralWidget);
        LComment->setObjectName(QStringLiteral("LComment"));
        LComment->setGeometry(QRect(370, 600, 400, 200));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font6.setPointSize(26);
        font6.setBold(true);
        font6.setWeight(75);
        LComment->setFont(font6);
        LComment->setStyleSheet(QLatin1String("color:blue\n"
"\n"
""));
        LComment->setAlignment(Qt::AlignCenter);
        RComment = new QLabel(centralWidget);
        RComment->setObjectName(QStringLiteral("RComment"));
        RComment->setGeometry(QRect(1150, 600, 400, 200));
        RComment->setFont(font6);
        RComment->setStyleSheet(QStringLiteral("color:red"));
        RComment->setAlignment(Qt::AlignCenter);
        LScorePlus = new QPushButton(centralWidget);
        LScorePlus->setObjectName(QStringLiteral("LScorePlus"));
        LScorePlus->setGeometry(QRect(0, 580, 200, 500));
        LScorePlus->setCursor(QCursor(Qt::OpenHandCursor));
        LScorePlus->setStyleSheet(QLatin1String("background-color:rgb(230, 231, 235);\n"
"border:none"));
        LScoreMinus = new QPushButton(centralWidget);
        LScoreMinus->setObjectName(QStringLiteral("LScoreMinus"));
        LScoreMinus->setGeometry(QRect(0, 0, 200, 500));
        LScoreMinus->setCursor(QCursor(Qt::OpenHandCursor));
        LScoreMinus->setStyleSheet(QLatin1String("background-color:rgb(230, 231, 235);\n"
"border:none"));
        RScorePlus = new QPushButton(centralWidget);
        RScorePlus->setObjectName(QStringLiteral("RScorePlus"));
        RScorePlus->setGeometry(QRect(1720, 580, 200, 500));
        RScorePlus->setCursor(QCursor(Qt::OpenHandCursor));
        RScorePlus->setStyleSheet(QLatin1String("background-color:rgb(230, 231, 235);\n"
"border:none"));
        RScoreMinus = new QPushButton(centralWidget);
        RScoreMinus->setObjectName(QStringLiteral("RScoreMinus"));
        RScoreMinus->setGeometry(QRect(1720, 0, 200, 500));
        RScoreMinus->setCursor(QCursor(Qt::OpenHandCursor));
        RScoreMinus->setStyleSheet(QLatin1String("background-color:rgb(230, 231, 235);\n"
"border:none"));
        Swap = new QPushButton(centralWidget);
        Swap->setObjectName(QStringLiteral("Swap"));
        Swap->setGeometry(QRect(330, 160, 1271, 81));
        Swap->setCursor(QCursor(Qt::OpenHandCursor));
        Swap->setStyleSheet(QLatin1String("background-color:rgb(230, 231, 235);\n"
"border:none"));
        Swap->setCheckable(true);
        LScore = new QLabel(centralWidget);
        LScore->setObjectName(QStringLiteral("LScore"));
        LScore->setGeometry(QRect(430, 800, 280, 180));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font7.setPointSize(96);
        font7.setBold(false);
        font7.setWeight(50);
        LScore->setFont(font7);
        LScore->setStyleSheet(QLatin1String("color:rgb(230, 231, 235);\n"
"background-color:rgb(17, 117, 192);"));
        LScore->setAlignment(Qt::AlignCenter);
        RScore = new QLabel(centralWidget);
        RScore->setObjectName(QStringLiteral("RScore"));
        RScore->setGeometry(QRect(1210, 800, 280, 180));
        RScore->setFont(font7);
        RScore->setStyleSheet(QLatin1String("color:rgb(230, 231, 235);\n"
"background-color:rgb(255, 111, 111);\n"
""));
        RScore->setAlignment(Qt::AlignCenter);
        TimeUp = new QLabel(centralWidget);
        TimeUp->setObjectName(QStringLiteral("TimeUp"));
        TimeUp->setGeometry(QRect(0, 0, 1920, 1080));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font8.setPointSize(640);
        font8.setBold(true);
        font8.setWeight(75);
        TimeUp->setFont(font8);
        TimeUp->setStyleSheet(QLatin1String("color:rgba(255,0,0,150);\n"
"background-color:rgb(255,255,255,200);"));
        TimeUp->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        Title->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        LComment->raise();
        RComment->raise();
        LScorePlus->raise();
        LScoreMinus->raise();
        RScorePlus->raise();
        RScoreMinus->raise();
        logo->raise();
        Swap->raise();
        LScore->raise();
        RScore->raise();
        TimeUp->raise();

        retranslateUi(MainWindow);

        Swap->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        logo->setText(QString());
        Title->setText(QApplication::translate("MainWindow", "RoboGame 2018 \342\200\234\345\213\207\346\224\200\351\253\230\345\263\260\342\200\235\346\257\224\350\265\233", nullptr));
        LStop->setText(QApplication::translate("MainWindow", "\350\223\235\351\230\237\345\201\234\346\255\242\350\256\241\346\227\266", nullptr));
        Start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\350\256\241\346\227\266", nullptr));
        RStop->setText(QApplication::translate("MainWindow", "\347\272\242\351\230\237\345\201\234\346\255\242\350\256\241\346\227\266", nullptr));
        LTime->setText(QApplication::translate("MainWindow", "05:00", nullptr));
        CTime->setText(QApplication::translate("MainWindow", "01:00", nullptr));
        RTime->setText(QApplication::translate("MainWindow", "05:00", nullptr));
        Random->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\351\232\217\346\234\272\345\272\217\345\210\227", nullptr));
        Countdown->setText(QApplication::translate("MainWindow", "1\345\210\206\351\222\237\345\200\222\350\256\241\346\227\266", nullptr));
        Reset->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        L1->setText(QString());
        L2->setText(QString());
        L3->setText(QString());
        L4->setText(QString());
        L5->setText(QString());
        L6->setText(QString());
        L7->setText(QString());
        L8->setText(QString());
        R1->setText(QString());
        R2->setText(QString());
        R3->setText(QString());
        R4->setText(QString());
        R5->setText(QString());
        R6->setText(QString());
        R7->setText(QString());
        R8->setText(QString());
        LComment->setText(QApplication::translate("MainWindow", "\350\223\235\351\230\237\345\207\206\345\244\207\344\270\255...", nullptr));
        RComment->setText(QApplication::translate("MainWindow", "\347\272\242\351\230\237\345\207\206\345\244\207\344\270\255...", nullptr));
        LScorePlus->setText(QString());
        LScoreMinus->setText(QString());
        RScorePlus->setText(QString());
        RScoreMinus->setText(QString());
        Swap->setText(QString());
        LScore->setText(QApplication::translate("MainWindow", "0", nullptr));
        RScore->setText(QApplication::translate("MainWindow", "0", nullptr));
        TimeUp->setText(QApplication::translate("MainWindow", "5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
