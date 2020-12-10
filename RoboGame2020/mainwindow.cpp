#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* 设置背景图片 */
    QPixmap bkgnd(":figs/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

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

    if(colorL == "蓝")
    {
        ui->LScorePlus->setStyleSheet("color:rgb(254,254,254);\
                                       border-image:url(:/figs/boards/board_blue.png);");
        ui->RScorePlus->setStyleSheet("color:rgb(254,254,254);\
                                       border-image:url(:/figs/boards/board_red.png);");
        ui->LComment->setStyleSheet("color:rgb(175,205,254);\
                                     background: transparent;\
                                     border:none;");
        ui->RComment->setStyleSheet("color:rgb(255,175,175);\
                                     background: transparent;\
                                     border:none;");
        ui->LStop->setStyleSheet("border-image:url(:/figs/buttons/stop_blue.png);");
        ui->RStop->setStyleSheet("border-image:url(:/figs/buttons/stop_red.png);");
        ui->LTime->setStyleSheet("color:rgb(175,205,254);\
                                  background: transparent;\
                                  border:none;");
        ui->RTime->setStyleSheet("color:rgb(255,175,175);\
                                  background: transparent;\
                                  border:none;");
    }
    else if(colorL == "红")
    {
        ui->RScorePlus->setStyleSheet("color:rgb(254,254,254);\
                                       border-image:url(:/figs/boards/board_blue.png);");
        ui->LScorePlus->setStyleSheet("color:rgb(254,254,254);\
                                       border-image:url(:/figs/boards/board_red.png);");
        ui->RComment->setStyleSheet("color:rgb(175,205,254);\
                                     background: transparent;\
                                     border:none;");
        ui->LComment->setStyleSheet("color:rgb(255,175,175);\
                                     background: transparent;\
                                     border:none;");
        ui->RStop->setStyleSheet("border-image:url(:/figs/buttons/stop_blue.png);");
        ui->LStop->setStyleSheet("border-image:url(:/figs/buttons/stop_red.png);");
        ui->RTime->setStyleSheet("color:rgb(175,205,254);\
                                  background: transparent;\
                                  border:none;");
        ui->LTime->setStyleSheet("color:rgb(255,175,175);\
                                  background: transparent;\
                                  border:none;");
    }
    ui->TimeUp->setVisible (false);

    man[0] = ui->Man1;
    man[1] = ui->Man2;
    man[2] = ui->Man3;
    man[3] = ui->Man4;
    man[4] = ui->Man5;
    man[5] = ui->Man6;

    bed[0] = ui->Bed1;
    bed[1] = ui->Bed2;
    bed[2] = ui->Bed3;

    pixmap[0].load(":/figs/man/man_green.png");
    pixmap[1].load(":/figs/man/man_yellow.png");
    pixmap[2].load(":/figs/man/man_red.png");

     ui->LTime->setAlignment(Qt::AlignCenter);
     ui->RTime->setAlignment(Qt::AlignCenter);
     ui->CTime->setAlignment(Qt::AlignCenter);
     ui->LTime->setFocusPolicy(Qt::NoFocus);
     ui->RTime->setFocusPolicy(Qt::NoFocus);
     ui->CTime->setFocusPolicy(Qt::NoFocus);

    /* 时间字体描边 */
    QTextCharFormat format;
    format.setTextOutline (QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)); // Color and width of outline
    ui->LTime->mergeCurrentCharFormat(format);
    ui->RTime->mergeCurrentCharFormat(format);
    ui->CTime->mergeCurrentCharFormat(format);
    ui->LTime->setText("0"+QString::number(TotalTime)+":00");
    ui->RTime->setText("0"+QString::number(TotalTime)+":00");
    ui->CTime->setText("01:00");


    ui->LComment->setAlignment(Qt::AlignCenter);
    ui->RComment->setAlignment(Qt::AlignCenter);
    ui->LComment->setFocusPolicy(Qt::NoFocus);
    ui->RComment->setFocusPolicy(Qt::NoFocus);

    /* 文字说明字体描边 */
    format.setTextOutline (QPen(Qt::black, 1.3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)); // Color and width of outline
    ui->LComment->mergeCurrentCharFormat(format);
    ui->RComment->mergeCurrentCharFormat(format);
    ui->LComment->setText(colorL + "队准备中...");
    ui->RComment->setText(colorR + "队准备中...");


    /* 初始化随机数种子 */
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
//    ui->CTime->setStyleSheet("");
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

void MainWindow::on_Random_clicked()
{
    /* 避免出现连续三个绿色 */
    int color[6] = {0,0,0,1,1,2};
    int index_green[3] = {0};
    int rd = 0, temp = 0;
    while(1)
    {
        for(int i = 0; i < 5; i++)  // 生成 0 ~ 5 的全排列
        {
            rd = qrand()%(6-i)+i;
            if(rd!=i)
            {
                temp = color[i];
                color[i] = color[rd];
                color[rd] = temp;
            }
        }
        for(int i = 0, j = 0; i < 6; i++)
            if(color[i] == 0) index_green[j++] = i;
        if(index_green[0]+index_green[2]!=index_green[1]*2) break;
    }

    for(int i = 0; i < 6; i++)  // 将排列应用到 man
    {
        man[i]->setPixmap(pixmap[color[i]]);
    }

    for(int i = 0; i < 3; i++)
    {
        bed[i]->clear();
    }

    rd = qrand() % 3;
    bed[rd]->setPixmap(pixmap[1]);
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
//    ui->CTime->setStyleSheet("");
    ui->LComment->setText(colorL + "队准备中...");
    ui->RComment->setText(colorR + "队准备中...");
    ui->LScorePlus->setText("0");
    ui->RScorePlus->setText("0");
    ui->TimeUp->setVisible (false);

}

void MainWindow::init()
{
    ui->TimeUp->setVisible (false);

    int color[6] = {0,0,0,1,1,2};
    for(int i = 0; i < 6; i++)
    {
        man[i]->setPixmap(pixmap[color[i]]);
    }

    for(int i = 0; i < 3; i++)
    {
        bed[i]->clear();
    }
     bed[0]->setPixmap(pixmap[1]);
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

//    if(m_Time == temp_5)
//    {
//        ui->CTime->setStyleSheet("color:red");
//    }

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


