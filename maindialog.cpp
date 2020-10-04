#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}


void MainDialog::on_pushButtonAdd_clicked()
{
    int input1 = ui->inputEdit1->text().toDouble();
    int input2 = ui->inputEdit2->text().toDouble();
    int result = input1 + input2 ;
    if(ui->resultEdit->text().isEmpty()){
        ui->resultEdit->setText(QString::number(result));
        ui->inputEdit1->clear();
        ui->inputEdit2->clear();
    }
}

void MainDialog::on_pushButtonSubstract_clicked()
{
    int input1 = ui->inputEdit1->text().toDouble();
    int input2 = ui->inputEdit2->text().toDouble();
    int result = input1 - input2 ;
    if(ui->resultEdit->text().isEmpty()){
        ui->resultEdit->setText(QString::number(result));
        ui->inputEdit1->clear();
        ui->inputEdit2->clear();
    }
}


