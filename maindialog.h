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


    void on_inputEdit1_inputRejected();

private:
    Ui::MainDialog *ui;
};
#endif // MAINDIALOG_H
