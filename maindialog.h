#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainDialog; }
QT_END_NAMESPACE

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    MainDialog(QWidget *parent = nullptr);
    ~MainDialog();


private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonSubstract_clicked();

    void on_pushButtonCalculate_clicked();

    void on_comboBoxOperator_currentIndexChanged(int index);

    void on_pushButtonCalculateBMI_clicked();

private:
    Ui::MainDialog *ui;
};
#endif // MAINDIALOG_H
