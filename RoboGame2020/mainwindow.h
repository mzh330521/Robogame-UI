#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QKeyEvent>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
    virtual void keyPressEvent(QKeyEvent *event);

private slots:

    void on_Countdown_clicked();

    void on_LStop_clicked();

    void on_RStop_clicked();

    void on_Random_clicked();

    void on_Reset_clicked();

    void on_Start_clicked();

    void on_LScorePlus_clicked();

    void on_LScoreMinus_clicked();

    void on_RScorePlus_clicked();

    void on_RScoreMinus_clicked();

    void LRTime_update();

    void CTime_update();

    void init();

private:
    Ui::MainWindow *ui;
    int TotalTime; // min
    int isDoneL,isDoneR;
    int scoreL,scoreR;
    QString colorL,colorR;
    QTime m_Time,timeL,timeR;
    QTimer* m_pTimer;   // 计时器
    QLabel *man[6];     // man指针数组，便于批量操作ui中的Man
    QLabel *bed[3];   // 类上
    QPixmap pixmap[4];  // 右 绿黄红 & 左黄
};

#endif // MAINWINDOW_H
