#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTime m_Time,timeL,timeR;
    QTimer* m_pTimer;

protected:
    virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void Countdown_Extra(int);

    void on_Countdown_clicked();

    void on_Reset_clicked();

    void on_Start_clicked();

    void on_LStop_clicked();

    void on_RStop_clicked();

    void on_Random_clicked();

    void LRTime_update();

    void CTime_update();

    void on_LScorePlus_clicked();

    void on_RScorePlus_clicked();

    void on_Swap_clicked(bool checked);

    void on_LScoreMinus_clicked();

    void on_RScoreMinus_clicked();

    void init();

private:
    Ui::MainWindow *ui;
    int isDoneL,isDoneR;
    int scoreL,scoreR;
    QString colorL,colorR;
};



#endif // MAINWINDOW_H
