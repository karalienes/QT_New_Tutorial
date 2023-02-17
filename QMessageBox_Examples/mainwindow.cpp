#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int ret;

    //property->based API
    /*
    To use the property-based API, construct an instance of QMessageBox, set the desired properties, and call exec() to show the message.
    The simplest configuration is to set only the message text property.

    The user must click the OK button to dismiss the message box. The rest of the GUI is blocked until the message box is dismissed.
    */
    if(ui->radioButton->isChecked()){
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.exec();
    }
    //A better approach
    /*
     * A better approach than just alerting the user to an event is to also ask the user what to do about it.
     * Store the question in the informative text property, and set the standard buttons property to the set of buttons you want as the set of user responses.
     * The buttons are specified by combining values from StandardButtons using the bitwise OR operator. The display order for the buttons is platform-dependent.
     Mark one of your standard buttons to be your default button.
     */
    else if(ui->radioButton_2->isChecked()){
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save |
                                  QMessageBox::Discard |
                                  QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        ret = msgBox.exec();
    }
    //Warning
    /*
     * Building message boxes with the static functions API, although convenient, is less flexible than using the property-based API,
     * because the static function signatures lack parameters for setting the informative text and detailed text properties.
     * One work-around for this has been to use the title parameter as the message box main text and the text parameter as the message box informative text.
     * Because this has the obvious drawback of making a less readable message box, platform guidelines do not recommend it.
     * The Microsoft Windows User Interface Guidelines recommend using the application name as the window's title,
     * which means that if you have an informative text in addition to your main text, you must concatenate it to the text parameter.

      Note that the static function signatures have changed with respect to their button parameters,
      which are now used to set the standard buttons and the default button.

      Static functions are available for creating information(), question(), warning(), and critical() message boxes.
      */
    else {
        ret= QMessageBox::warning(this,tr("My Application"),
                                  tr("The document has been modified. \n"
                                     "Do you want to save your changes?"),
                                  QMessageBox::Save |
                                  QMessageBox::Discard |
                                  QMessageBox::Cancel,
                                  QMessageBox::Save);
    }

    switch (ret) {
    case QMessageBox::Save:
        break;
    case QMessageBox::Discard:
        break;
    case QMessageBox::Cancel:
        break;
    default:
        break;
    }
}

