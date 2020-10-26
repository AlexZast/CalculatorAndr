#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void digit_number();
    void on_pushButton_39_clicked();
    void operation();
    void math_operation();

    void on_pushButton_res_clicked();

    void on_pushButton_ac_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
