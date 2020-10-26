#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainDialog)
{
    ui->setupUi(this);

    ui->groupBoxBMI->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);
}

MainDialog::~MainDialog()
{
    delete ui;
}


void MainDialog::on_pushButtonAdd_clicked()
{
    double input1 = ui->inputEdit1->text().toDouble();
    double input2 = ui->inputEdit2->text().toDouble();
    double result = input1 + input2 ;
    if(ui->resultEdit->text().isEmpty()){
        ui->resultEdit->setText(QString::number(result));
        ui->inputEdit1->clear();
        ui->inputEdit2->clear();
    }
}

void MainDialog::on_pushButtonSubstract_clicked()
{
    double input1 = ui->inputEdit1->text().toDouble();
    double input2 = ui->inputEdit2->text().toDouble();
    double result = input1 - input2 ;
    if(ui->resultEdit->text().isEmpty()){
        ui->resultEdit->setText(QString::number(result));
        ui->inputEdit1->clear();
        ui->inputEdit2->clear();
    }
}

void MainDialog::on_pushButtonCalculate_clicked()
{
    double result = 0;
    int comboOperatorIndex = ui->comboBoxOperator->currentIndex();
    double input1 = ui->inputEdit1->text().toDouble();
    double input2 = ui->inputEdit2->text().toDouble();
    switch(comboOperatorIndex){
            case 0:
                ui->resultEdit->setText("Choose your Operator");
            break;
            case 1:
                result = input1 + input2;
            break;
            case 2:
                result = input1 - input2;
            break;
            case 3:
                result = input1 * input2;
            break;
            case 4:
                result = input1 / input2;
            break;
        }
    if(ui->resultEdit->text().isEmpty()){
        ui->resultEdit->setText(QString::number(result));
        ui->inputEdit1->clear();
        ui->inputEdit2->clear();
        ui->comboBoxOperator->clear();
    }
}

void MainDialog::on_comboBoxOperator_currentIndexChanged(int index)
{
    if(index != 0){
       ui->pushButtonCalculate->setDisabled(false);
       ui->pushButtonAdd->setDisabled(true);
       ui->pushButtonSubstract->setDisabled(true);
    }
    if(index== 0){
        ui->pushButtonCalculate->setDisabled(true);
        ui->pushButtonAdd->setDisabled(false);
        ui->pushButtonSubstract->setDisabled(false);
    }
}

void MainDialog::on_pushButtonCalculateBMI_clicked()
{
    double weight = ui->inputEditWeight->text().toDouble();
    double height = ui->inputEditHeight->text().toDouble()/100;
    double result = weight/(height*height);
    if(result<18.5){
        ui->LineEditResultBMI->setText(QString::number(result,'f', 2)+"Underweight");
    }else if(result<25.0 && result >= 18.5){
        ui->LineEditResultBMI->setText(QString::number(result,'f', 2)+"Normal");
    }else if(result<30.0 && result >= 25.0){
        ui->LineEditResultBMI->setText(QString::number(result,'f', 2)+"Overweight");
    }else if(result<35.0 && result >= 30.0){
        ui->LineEditResultBMI->setText(QString::number(result,'f', 2)+"Obesity Class I");
    }else if(result<40.0 && result >= 35.0){
        ui->LineEditResultBMI->setText(QString::number(result,'f', 2)+"Obesity Class II");
    }else if(result >= 40.0){
        ui->LineEditResultBMI->setText(QString::number(result,'f', 2)+"Obesity Class III");
    }
}
