#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    __init__();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::__init__()
{
    for(int i=0;i<10;i++){
        ui->item_combobox->addItem("item: "+ QString::number(i));
    }
}


void Dialog::on_which_button_clicked()
{
    // This message is not needed because the combo is already displaying the current item. But it's there for getting used to the QMessageBox as well as signals/slots.
    QMessageBox::information(this,tr("Item Selection"),ui->item_combobox->currentText());
}

