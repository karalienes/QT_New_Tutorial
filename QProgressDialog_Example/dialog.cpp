#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_Modal_button_clicked()
{
    int numTasks = 10000000;

    QProgressDialog progress("Task in progress...","Cancel",0,numTasks,this);
    progress.setWindowModality(Qt::WindowModal);

    for(int i=0; i<numTasks;i++)
    {
        progress.setValue(i);

        if(progress.wasCanceled()){
            break;
        }
    }
    progress.setValue(numTasks);
}


void Dialog::on_Modeless_buttn_clicked()
{
    myTask = new MyTask;
}

