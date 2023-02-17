#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void __init__();

private slots:
    void on_which_button_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
