#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TotalTime = 5; // 比赛时间为 5 min
    m_pTimer = new QTimer();
    m_pTimer->setInterval(1000);

    isDoneL = false;
    isDoneR = false;
    scoreL = 0;
    scoreR = 0;
//    colorL = "蓝";
//    colorR = "红";
    colorL = "红";
    colorR = "蓝";
    ui->LStop->setText(colorL + "队停止计时");
    ui->RStop->setText(colorR + "队停止计时");
    ui->LComment->setText(colorL + "队准备中...");
    ui->RComment->setText(colorR + "队准备中...");
    if(colorL == "蓝")
    {
        ui->LScorePlus->setStyleSheet("color:rgb(230, 231, 235);\
                                      background-color:rgb(17, 117, 192);\
                                      border:none;");
        ui->RScorePlus->setStyleSheet("color:rgb(230, 231, 235);\
                                      background-color:rgb(255, 111, 111);\
                                      border:none;");
        ui->LComment->setStyleSheet("color:blue");
        ui->RComment->setStyleSheet("color:red");
        ui->LStop->setStyleSheet("color:rgb(40, 64, 121);\
                                 background-color:qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, \
                                    stop:0 rgba(17, 117, 192, 255), stop:1 rgba(255, 255, 255, 255));\
                                 border:none;");
        ui->RStop->setStyleSheet("color:rgb(121, 31, 34);\
                                 background-color:qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:1, \
                                    stop:0 rgba(255, 111, 111, 255), stop:1 rgba(255, 255, 255, 255));\
                                 border:none;");
        ui->LTime->setStyleSheet("color:rgb(40, 64, 121);");
        ui->RTime->setStyleSheet("color:rgb(121, 31, 34);");
    }
    else if(colorL == "红")
    {
        ui->RScorePlus->setStyleSheet("color:rgb(230, 231, 235);\
                                      background-color:rgb(17, 117, 192);\
                                      border:none;");
        ui->LScorePlus->setStyleSheet("color:rgb(230, 231, 235);\
                                      background-color:rgb(255, 111, 111);\
                                      border:none;");
        ui->RComment->setStyleSheet("color:blue");
        ui->LComment->setStyleSheet("color:red");
        ui->RStop->setStyleSheet("color:rgb(40, 64, 121);\
                                 background-color:qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, \
                                    stop:0 rgba(17, 117, 192, 255), stop:1 rgba(255, 255, 255, 255));\
                                 border:none;");
        ui->LStop->setStyleSheet("color:rgb(121, 31, 34);\
                                 background-color:qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:1, \
                                    stop:0 rgba(255, 111, 111, 255), stop:1 rgba(255, 255, 255, 255));\
                                 border:none;");
        ui->RTime->setStyleSheet("color:rgb(40, 64, 121);");
        ui->LTime->setStyleSheet("color:rgb(121, 31, 34);");
    }
    ui->TimeUp->setVisible (false);

    box[0] = ui->Box1;
    box[1] = ui->Box2;
    box[2] = ui->Box3;
    box[3] = ui->Box4;
    box[4] = ui->Box5;
    box[5] = ui->Box6;

    qsrand(static_cast<unsigned>(QTime(0,0,0).secsTo(QTime::currentTime())));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    static int is_full_screen = false;
    switch (event->key())
    {
    case Qt::Key_Escape:    // 退出全屏
        showMaximized();
        is_full_screen = false;
        break;

    case Qt::Key_F11:       // 全屏/退出全屏
        if(!is_full_screen)
        {
            showFullScreen();
            is_full_screen = true;
        }
        else
        {
            showMaximized();
            is_full_screen = false;
        }
        break;

    case Qt::Key_A: // 随机序列
        on_Random_clicked();
        break;
    case Qt::Key_S: // 计时复位
        on_Reset_clicked();
        break;
    case Qt::Key_D: // 一分钟倒计时
        on_Countdown_clicked();
        break;

    case Qt::Key_W: // 开始计时
        on_Start_clicked();
        break;

    case Qt::Key_Return:
    case Qt::Key_Enter: // 初始化物块顺序
        init();
        break;

    case Qt::Key_7:
    case Qt::Key_Q: // 左队停止计时
        on_LStop_clicked();
        break;
    case Qt::Key_4: // 左队加一分
        on_LScorePlus_clicked();
        break;
    case Qt::Key_1: // 左队减一分
        on_LScoreMinus_clicked();
        break;

    case Qt::Key_9:
    case Qt::Key_E: // 右队停止计时
        on_RStop_clicked();
        break;
    case Qt::Key_6:// 右队加一分
        on_RScorePlus_clicked();
        break;
    case Qt::Key_3: // 右队减一分
        on_RScoreMinus_clicked();
        break;





    }
}

void MainWindow::on_Countdown_clicked()
{
    ui->CTime->setText("01:00");
    ui->CTime->setStyleSheet("");
    ui->LComment->setText(colorL + "队准备中...");
    ui->RComment->setText(colorR + "队准备中...");
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(CTime_update()));
    m_Time.setHMS(0, 1, 0, 0);
    //m_Time.setHMS(0, 0, 8, 0); // debug
    m_pTimer->start();
    ui->TimeUp->setVisible (false);
}

void MainWindow::on_Start_clicked()
{
    isDoneL = false;
    isDoneR = false;
    scoreL = 0;
    scoreR = 0;
    ui->LComment->setText(colorL + "队准备中...");
    ui->RComment->setText(colorR + "队准备中...");
    ui->TimeUp->setVisible (false);

    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(LRTime_update()));
    m_Time.setHMS(0, TotalTime, 5, 0);
    //m_Time.setHMS(0, 0, 12, 0); // debug
    m_pTimer->start();
}

void MainWindow::on_LStop_clicked()
{
    QString content;
    QTime begin_time;
    begin_time.setHMS(0, TotalTime - 1, 59, 0);
    timeL.setHMS(0, 0, 0, 0);
    timeL = timeL.addSecs(-begin_time.secsTo(m_Time));
    content = colorL + "队比赛结束！\n耗时 "+ timeL.toString("mm:ss");
    ui->LComment->setText(content);
    ui->LScorePlus->setText(QString::number(scoreL));
    isDoneL=true;
}

void MainWindow::on_RStop_clicked()
{
    QString content;
    QTime begin_time;
    begin_time.setHMS(0, TotalTime - 1, 59, 0);
    timeR.setHMS(0, 0, 0, 0);
    timeR = timeR.addSecs(-begin_time.secsTo(m_Time));
    content = colorR + "队比赛结束！\n耗时 "+ timeR.toString("mm:ss");
    ui->RComment->setText(content);
    ui->RScorePlus->setText(QString::number(scoreR));
    isDoneR=true;
}

static QString box_style(const int index);
void MainWindow::on_Random_clicked()
{
    QPixmap pixmap[3];
    int index[6], index_of_index[6];
    int m = 0, temp = 0, sum = 0;

    for(int i = 0; i < 6; i++)
    {
        index[i] = index_of_index[i] = i;
    }
    for(int i = 0; i < 5; i++)  // 生成 0 ~ 5 的全排列
    {
        m = qrand()%(6-i)+i;
        if(m!=i)
        {
            temp = index[i];
            index[i] = index[m];
            index[m] = temp;
        }
    }
    for(int i = 0; i < 6; i++)  // 将排列应用到 box
    {
        box[i]->setStyleSheet(box_style(index[i]));
        box[i]->setText(QString::number(index[i]+1));
    }

    do
    {
        sum = 0;
        for(int i = 0; i < 3; i++)  // 生成 0 ~ 5 中 3 个元素的排列
        {
            m = qrand()%(6-i)+i;
            sum += index_of_index[m];
            if(m!=i)
            {
                temp = index_of_index[i];
                index_of_index[i] = index_of_index[m];
                index_of_index[m] = temp;
            }
        }
    }
    while(sum <= 3);    // 排除取到012的情况

    for(int i = 0; i < 3; i++)
    {
        pixmap[i].load(":/figs/block" + QString::number(index[index_of_index[i]] + 1) + ".png");
    }

    ui->Block1->setPixmap(pixmap[0]);
    ui->Block2->setPixmap(pixmap[1]);
    ui->Block3->setPixmap(pixmap[2]);
}

void MainWindow::on_Reset_clicked()
{
    m_pTimer->stop();
    m_pTimer->disconnect();
    scoreL = 0;
    scoreR = 0;
    ui->LTime->setText("0"+QString::number(TotalTime)+":00");
    ui->RTime->setText("0"+QString::number(TotalTime)+":00");
    ui->CTime->setText("01:00");
    ui->CTime->setStyleSheet("");
    ui->LComment->setText(colorL + "队准备中...");
    ui->RComment->setText(colorR + "队准备中...");
    ui->LScorePlus->setText("0");
    ui->RScorePlus->setText("0");
    ui->TimeUp->setVisible (false);

}

void MainWindow::init()
{
    QPixmap pixmap[3];
    pixmap[0].load(":/figs/block2.png");
    pixmap[1].load(":/figs/block5.png");
    pixmap[2].load(":/figs/block6.png");
    ui->Block1->setPixmap(pixmap[0]);
    ui->Block2->setPixmap(pixmap[1]);
    ui->Block3->setPixmap(pixmap[2]);
    ui->TimeUp->setVisible (false);
    for(int i = 0; i < 6; i++)  // 将排列应用到 box
    {
        box[i]->setStyleSheet(box_style(i));
        box[i]->setText(QString::number(i+1));
    }
}

void MainWindow::LRTime_update()
{
    QString content;
    QTime temp,temp_5s,begin_time;
    temp.setHMS(0,0,0,0);
    temp_5s.setHMS(0,0,5,0);
    begin_time.setHMS(0,TotalTime,0,0);
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
            ui->LScorePlus->setText(QString::number(scoreL));
        }
        if(!isDoneR)
        {
            content = colorR + "队正在比赛...";
            ui->RTime->setText(m_Time.toString("mm:ss"));
            ui->RComment->setText(content);
            ui->RScorePlus->setText(QString::number(scoreR));
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
            ui->LComment->setText(QString::number(TotalTime)+"分钟已到！\n比赛结束！");
            ui->RScorePlus->setText(QString::number(scoreR));
            isDoneL = true;
        }
        if(!isDoneR)
        {
            ui->RComment->setText(QString::number(TotalTime)+"分钟已到！\n比赛结束！");
            ui->RScorePlus->setText(QString::number(scoreR));
            isDoneR = true;
        }
    }

    m_Time=m_Time.addSecs(-1);
}

void MainWindow::CTime_update()
{
    QTime temp;
    temp.setHMS(0,0,0,0);
    QTime temp_5;
    temp_5.setHMS(0,0,5,0);
    m_Time=m_Time.addSecs(-1);

//    if(m_Time <= temp_5)
//    {
//        ui->TimeUp->setVisible (true);
//        ui->TimeUp->setText(m_Time.toString("s"));
//    }
    if(m_Time == temp_5)
    {
        ui->CTime->setStyleSheet("color:red");
    }

    if(m_Time == temp)
    {
        ui->LComment->setText("Time's up!");
        ui->RComment->setText("Time's up!");
        m_pTimer->stop();
        m_pTimer->disconnect();
    }
    ui->CTime->setText(m_Time.toString("mm:ss"));
}

void MainWindow::on_LScorePlus_clicked()
{
    if(scoreL < 16)
        scoreL++;
    if(isDoneL)
    {
        ui->LScorePlus->setText(QString::number(scoreL));
    }
}

void MainWindow::on_RScorePlus_clicked()
{
    if(scoreR < 16)
        scoreR ++;
    if(isDoneR)
    {
        ui->RScorePlus->setText(QString::number(scoreR));
    }
}

void MainWindow::on_LScoreMinus_clicked()
{
    if(scoreL > 0)
        scoreL--;
    if(isDoneL)
    {
        ui->LScorePlus->setText(QString::number(scoreL));
    }
}

void MainWindow::on_RScoreMinus_clicked()
{
    if(scoreR > 0)
        scoreR--;
    if(isDoneR)
    {
        ui->RScorePlus->setText(QString::number(scoreR));
    }
}

static QString box_style(const int index)
{
    QString base_style = "background-image:url(:/figs/box_square.png);"
                         "border-width:15px;"
                         "border-style:solid;"
                         "border-color:";
    QString border_color[6];
    border_color[0]="hsl(0,169,190)";
    border_color[1]="hsl(45,169,190)";
    border_color[2]="hsl(135,169,190)";
    border_color[3]="hsl(180,169,190)";
    border_color[4]="hsl(225,169,190)";
    border_color[5]="hsl(270,169,190)";
    return base_style + border_color[index];
}



