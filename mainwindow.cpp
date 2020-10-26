#include "mainwindow.h"
#include "ui_mainwindow.h"

double first_num;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_del->setCheckable(true);
    ui->pushButton_um->setCheckable(true);
    ui->pushButton_min->setCheckable(true);

    ui->pushButton_plus->setChecked(false);
    ui->pushButton_del->setChecked(false);
    ui->pushButton_um->setChecked(false);
    ui->pushButton_min->setChecked(false);


    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_rev, SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->pushButton_prc, SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(math_operation()));
    connect(ui->pushButton_um, SIGNAL(clicked()), this, SLOT(math_operation()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operation()));
    connect(ui->pushButton_min, SIGNAL(clicked()), this, SLOT(math_operation()));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digit_number()
{
    QPushButton *button = (QPushButton *) sender();
    double all_numbers;

    QString label;
    if((ui->result->text().contains('.')) && button->text().toDouble() == 0){
        label = ui->result->text() + button->text();
        ui->result->setText(label);
    } else {
        all_numbers = (ui->result->text()+button->text()).toDouble();
        label = QString::number(all_numbers, 'g', 12);
        ui->result->setText(label);
    }
}

void MainWindow::on_pushButton_39_clicked()
{
    if(!(ui->result->text().contains('.')))
    ui->result->setText(ui->result->text()+".");
}

void MainWindow::operation()
{
    QPushButton *button = (QPushButton *) sender();
    double all_numbers=0;
    QString label;
    if (button->text() == "+/-"){
        all_numbers = (ui->result->text()).toDouble();
        all_numbers *= -1;
        label = QString::number(all_numbers, 'g', 12);
        ui->result->setText(label);
    } else if (button->text() == "%"){
        all_numbers = (ui->result->text()).toDouble();
        all_numbers *= 0.01;
        label = QString::number(all_numbers, 'g', 12);
        ui->result->setText(label);
    }

}

void MainWindow::math_operation(){
    QPushButton *button = (QPushButton *) sender();

    ui->pushButton_plus->setChecked(false);
    ui->pushButton_del->setChecked(false);
    ui->pushButton_um->setChecked(false);
    ui->pushButton_min->setChecked(false);
    first_num = (ui->result->text()).toDouble();
    button->setChecked(true);

    ui->result->setText("");
}


void MainWindow::on_pushButton_res_clicked()
{
    double secnd=0;
    QString label;

    secnd = ui->result->text().toDouble();

    if (ui->pushButton_plus->isChecked()){
        secnd = first_num + secnd;
        label = QString::number(secnd, 'g', 12);
        ui->result->setText(label);
        ui->pushButton_plus->setChecked(false);
    }

    if (ui->pushButton_min->isChecked()){
        secnd = first_num-secnd;
        label = QString::number(secnd, 'g', 12);
        ui->result->setText(label);
        ui->pushButton_min->setChecked(false);
    }

    if (ui->pushButton_um->isChecked()){
        secnd = first_num*secnd;
        label = QString::number(secnd, 'g', 12);
        ui->result->setText(label);

        ui->pushButton_um->setChecked(false);

    }

    if (ui->pushButton_del->isChecked()){
        if (!secnd){
            ui->result->setText("Deliv By Zerr");
        } else {
            secnd = first_num/secnd;
            label = QString::number(secnd, 'g', 12);
            ui->result->setText(label);
        }
            ui->pushButton_del->setChecked(false);
    }

}

void MainWindow::on_pushButton_ac_clicked()
{
    first_num = 0;

    ui->pushButton_plus->setChecked(false);
    ui->pushButton_del->setChecked(false);
    ui->pushButton_um->setChecked(false);
    ui->pushButton_min->setChecked(false);

    ui->result->setText("0");

}
