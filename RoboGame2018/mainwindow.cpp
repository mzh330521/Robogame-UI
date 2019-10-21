#include "mainwindow.h"
#include "ui_mainwindow.h"

//class PersonalDataPrivate{

//};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->TimeUp->setVisible (false);
    m_pTimer = new QTimer();
    m_pTimer->setInterval(1000);
    isDoneL = false;
    isDoneR = false;
    scoreL = 0;
    scoreR = 0;
    colorL = "蓝";
    colorR = "红";
    qsrand(static_cast<unsigned>(QTime(0,0,0).secsTo(QTime::currentTime())));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Escape://退出
        QApplication::exit();
        break;

    case Qt::Key_Return:
    case Qt::Key_Enter://恢复对联
        init();
        break;

    case Qt::Key_7:
    case Qt::Key_A://左队停止计时
        on_LStop_clicked();
        break;
    case Qt::Key_4:
    case Qt::Key_W://左队加一分
        on_LScorePlus_clicked();
        break;
    case Qt::Key_1:
    case Qt::Key_S://左队减一分
        on_LScoreMinus_clicked();
        break;

    case Qt::Key_9:
    case Qt::Key_L://右队停止计时
        on_RStop_clicked();
        break;
    case Qt::Key_6:
    case Qt::Key_I://右队加一分
        on_RScorePlus_clicked();
        break;
    case Qt::Key_3:
    case Qt::Key_K://右队减一分
        on_RScoreMinus_clicked();
        break;


    case Qt::Key_8://开始计时
        on_Start_clicked();
        break;

    case Qt::Key_5://随机序列
        on_Random_clicked();
        break;

    case Qt::Key_2://一分钟倒计时
        on_Countdown_clicked();
        break;

    case Qt::Key_0://复位
        on_Reset_clicked();
        break;

    case Qt::Key_Plus:
        Countdown_Extra(8);
        break;
    case Qt::Key_Minus:
        Countdown_Extra(3);
        break;
    }
}

void MainWindow::Countdown_Extra(const int time)
{
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(CTime_update()));
    m_Time.setHMS(0, time, 0, 0);
    m_pTimer->start();
}

void MainWindow::on_Countdown_clicked()
{
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(CTime_update()));
    m_Time.setHMS(0, 1, 0, 0);
    //m_Time.setHMS(0, 0, 8, 0);//@@@@@@@@@@@@@@@@@@@@
    m_pTimer->start();
    ui->TimeUp->setVisible (false);
}

void MainWindow::on_Start_clicked()
{
    isDoneL = false;
    isDoneR = false;
    scoreL = 0;
    scoreR = 0;
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(LRTime_update()));
    m_Time.setHMS(0, 5, 6, 0);
    //m_Time.setHMS(0, 0, 12, 0);//@@@@@@@@@@@@@@@@@@@@
    ui->LComment->setText(colorL + "队正在比赛...");
    ui->RComment->setText(colorR + "队正在比赛...");
    m_pTimer->start();
    ui->TimeUp->setVisible (false);
}

void MainWindow::on_LStop_clicked()
{
    QString content;
    QTime begin_time;
    begin_time.setHMS(0, 5, 0, 0);
    timeL.setHMS(0, 0, 0, 0);
    timeL = timeL.addSecs(-begin_time.secsTo(m_Time));
    content = colorL + "队比赛结束！\n耗时 "+ timeL.toString("mm:ss");
    ui->LComment->setText(content);
    ui->LScore->setText(QString::number(scoreL));
    isDoneL=true;
}

void MainWindow::on_RStop_clicked()
{
    QString content;
    QTime begin_time;
    begin_time.setHMS(0, 5, 0, 0);
    timeR.setHMS(0, 0, 0, 0);
    timeR = timeR.addSecs(-begin_time.secsTo(m_Time));
    content = colorR + "队比赛结束！\n耗时 "+ timeR.toString("mm:ss");
    ui->RComment->setText(content);
    ui->RScore->setText(QString::number(scoreR));
    isDoneR=true;
}

void MainWindow::on_Reset_clicked()
{
    m_pTimer->stop();
    m_pTimer->disconnect();
    scoreL = 0;
    scoreR = 0;
    ui->LTime->setText("05:00");
    ui->RTime->setText("05:00");
    ui->CTime->setText("01:00");
    ui->LComment->setText(colorL + "队准备中...");
    ui->RComment->setText(colorR + "队准备中...");
    ui->LScore->setText("0");
    ui->RScore->setText("0");

    ui->TimeUp->setVisible (false);
}

void MainWindow::init()
{
    QPixmap pixmap[8];
    pixmap[0].load(":/character/红.JPG");
    pixmap[1].load(":/character/专.JPG");
    pixmap[2].load(":/character/并.JPG");
    pixmap[3].load(":/character/进.JPG");
    pixmap[4].load(":/character/理.JPG");
    pixmap[5].load(":/character/实.JPG");
    pixmap[6].load(":/character/交.JPG");
    pixmap[7].load(":/character/融.JPG");
    ui->L1->setPixmap(pixmap[0]);
    ui->L2->setPixmap(pixmap[1]);
    ui->L3->setPixmap(pixmap[2]);
    ui->L4->setPixmap(pixmap[3]);
    ui->L5->setPixmap(pixmap[4]);
    ui->L6->setPixmap(pixmap[5]);
    ui->L7->setPixmap(pixmap[6]);
    ui->L8->setPixmap(pixmap[7]);
    ui->R1->setPixmap(pixmap[0]);
    ui->R2->setPixmap(pixmap[1]);
    ui->R3->setPixmap(pixmap[2]);
    ui->R4->setPixmap(pixmap[3]);
    ui->R5->setPixmap(pixmap[4]);
    ui->R6->setPixmap(pixmap[5]);
    ui->R7->setPixmap(pixmap[6]);
    ui->R8->setPixmap(pixmap[7]);
    ui->TimeUp->setVisible (false);
}

void MainWindow::LRTime_update()
{
    QString content;
    QTime temp,temp_5s,begin_time;
    temp.setHMS(0,0,0,0);
    temp_5s.setHMS(0,0,5,0);
    begin_time.setHMS(0,5,0,0);
    m_Time=m_Time.addSecs(-1);
    if(m_Time > begin_time)
    {
        ui->TimeUp->setVisible (true);
        ui->TimeUp->setText(QString::number(begin_time.secsTo(m_Time)));
    }
    else
    {
        ui->TimeUp->setVisible (false);

        if(!isDoneL)
        {
            content = colorL +"队正在比赛...";
            ui->LTime->setText(m_Time.toString("mm:ss"));
            ui->LComment->setText(content);
            ui->LScore->setText(QString::number(scoreL));
        }
        if(!isDoneR)
        {
            content = colorR + "队正在比赛...";
            ui->RTime->setText(m_Time.toString("mm:ss"));
            ui->RComment->setText(content);
            ui->RScore->setText(QString::number(scoreR));
        }
    }
    if(m_Time <= temp_5s)
    {
        ui->TimeUp->setVisible (true);
        ui->TimeUp->setText(m_Time.toString("s"));
    }
    if(m_Time == temp)
    {
        m_pTimer->stop();
        m_pTimer->disconnect();
        if(!isDoneL)
        {    
            ui->LComment->setText("5分钟已到！\n比赛结束!");
            ui->RScore->setText(QString::number(scoreR));
            isDoneL = true;
        }
        if(!isDoneR)
        {
            ui->RComment->setText("5分钟已到！\n比赛结束!");
            ui->RScore->setText(QString::number(scoreR));
            isDoneR = true;
        }
    }
}

void MainWindow::CTime_update()
{
    QTime temp;
    QTime temp_5;
    temp.setHMS(0,0,0,0);
    temp_5.setHMS(0,0,5,0);
    m_Time=m_Time.addSecs(-1);
//    if(m_Time <= temp_5)
//    {
//        ui->TimeUp->setVisible (true);
//        ui->TimeUp->setText(m_Time.toString("s"));
//    }
    if(m_Time <= temp)
    {
        ui->LComment->setText("Time's up!");
        ui->RComment->setText("Time's up!");
        m_pTimer->stop();
        m_pTimer->disconnect();
    }
    ui->CTime->setText(m_Time.toString("mm:ss"));
}


void MainWindow::on_Random_clicked()
{
    QPixmap pixmap[8];
    int index[8];
    int randomNum[4];
    bool isFirst[4];
    int m = 0, temp = 0;
    pixmap[0].load(":/character/红.JPG");
    pixmap[1].load(":/character/专.JPG");
    pixmap[2].load(":/character/并.JPG");
    pixmap[3].load(":/character/进.JPG");
    pixmap[4].load(":/character/理.JPG");
    pixmap[5].load(":/character/实.JPG");
    pixmap[6].load(":/character/交.JPG");
    pixmap[7].load(":/character/融.JPG");
    for(int i = 0; i < 4; i++)
    {
        isFirst[i] = qrand()%2;
        randomNum[i] = i;
    }
    for(int i = 0; i < 3; i++)
    {
        m = qrand()%(4-i)+i;
        if(m!=i)
        {
            temp = randomNum[i];
            randomNum[i] = randomNum[m];
            randomNum[m] = temp;
        }
    }
    for(int i = 0; i < 4; i++)
        index[i]=randomNum[i]*2+isFirst[randomNum[i]];
    for(int i = 0; i < 4; i++)
        randomNum[i] = i;
    for(int i = 0; i < 3; i++)
    {
        m = qrand()%(4-i)+i;
        if(m!=i)
        {
            temp = randomNum[i];
            randomNum[i] = randomNum[m];
            randomNum[m] = temp;
        }
    }

    for(int i = 0; i < 4; i++)
        index[i+4]=randomNum[i]*2+1-isFirst[randomNum[i]];


    ui->L1->setPixmap(pixmap[index[0]]);
    ui->L2->setPixmap(pixmap[index[1]]);
    ui->L3->setPixmap(pixmap[index[2]]);
    ui->L4->setPixmap(pixmap[index[3]]);
    ui->L5->setPixmap(pixmap[index[4]]);
    ui->L6->setPixmap(pixmap[index[5]]);
    ui->L7->setPixmap(pixmap[index[6]]);
    ui->L8->setPixmap(pixmap[index[7]]);
    ui->R1->setPixmap(pixmap[7-index[0]]);
    ui->R2->setPixmap(pixmap[7-index[1]]);
    ui->R3->setPixmap(pixmap[7-index[2]]);
    ui->R4->setPixmap(pixmap[7-index[3]]);
    ui->R5->setPixmap(pixmap[7-index[4]]);
    ui->R6->setPixmap(pixmap[7-index[5]]);
    ui->R7->setPixmap(pixmap[7-index[6]]);
    ui->R8->setPixmap(pixmap[7-index[7]]);
}

void MainWindow::on_LScorePlus_clicked()
{
    scoreL++;
    if(isDoneL)
    {
        ui->LScore->setText(QString::number(scoreL));
    }
}

void MainWindow::on_RScorePlus_clicked()
{
    scoreR++;
    if(isDoneR)
    {
        ui->RScore->setText(QString::number(scoreR));
    }
}

void MainWindow::on_LScoreMinus_clicked()
{
    scoreL--;
    if(isDoneL)
    {
        ui->LScore->setText(QString::number(scoreL));
    }
}

void MainWindow::on_RScoreMinus_clicked()
{
    scoreR--;
    if(isDoneR)
    {
        ui->RScore->setText(QString::number(scoreR));
    }
}

void MainWindow::on_Swap_clicked(bool checked)
{
    if(checked)
    {
        colorL = "蓝";
        colorR = "红";
        ui->LStop->setText("蓝队停止计时");
        ui->RStop->setText("红队停止计时");
        ui->LComment->setText("蓝队准备中...");
        ui->RComment->setText("红队准备中...");
        ui->LStop->setStyleSheet("color:rgb(40, 64, 121);\
            background-color:qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, \
            stop:0 rgba(17, 117, 192, 255), stop:1 rgba(255, 255, 255, 255));\
            border:none;");
        ui->RStop->setStyleSheet("color:rgb(121, 31, 34);\
            background-color:qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:1, \
            stop:0 rgba(255, 111, 111, 255), stop:1 rgba(255, 255, 255, 255));\
            border:none;");
        ui->LComment->setStyleSheet("color:blue");
        ui->RComment->setStyleSheet("color:red");
        ui->LTime->setStyleSheet("color:rgb(40, 64, 121);");
        ui->RTime->setStyleSheet("color:rgb(121, 31, 34);");
        ui->LScore->setStyleSheet("color:rgb(230, 231, 235);background-color:rgb(17, 117, 192)");
        ui->RScore->setStyleSheet("color:rgb(230, 231, 235);background-color:rgb(255, 111, 111)");
    }
    else
    {
        colorL = "红";
        colorR = "蓝";
        ui->LStop->setText("红队停止计时");
        ui->RStop->setText("蓝队停止计时");
        ui->LComment->setText("红队准备中...");
        ui->RComment->setText("蓝队准备中...");
        ui->LStop->setStyleSheet("color:rgb(121, 31, 34);\
            background-color:qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:1, \
            stop:0 rgba(255, 111, 111, 255), stop:1 rgba(255, 255, 255, 255));\
            border:none;");
        ui->RStop->setStyleSheet("color:rgb(40, 64, 121);\
            background-color:qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, \
            stop:0 rgba(17, 117, 192, 255), stop:1 rgba(255, 255, 255, 255));\
            border:none;");
        ui->LComment->setStyleSheet("color:red");
        ui->RComment->setStyleSheet("color:blue");
        ui->LTime->setStyleSheet("color:rgb(121, 31, 34);");
        ui->RTime->setStyleSheet("color:rgb(40, 64, 121);");
        ui->LScore->setStyleSheet("color:rgb(230, 231, 235);background-color:rgb(255, 111, 111)");
        ui->RScore->setStyleSheet("color:rgb(230, 231, 235);background-color:rgb(17, 117, 192)");
    }
}





