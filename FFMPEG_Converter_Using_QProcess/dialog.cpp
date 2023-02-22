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
    //Play button for output- initially disabled
    ui->play_output_button->setEnabled(false);

    // Create three processes
    // 1.transcoding 2. input play 3.output play
    mTranscodingProcess = new QProcess(this);
    mInputPlayProcess = new QProcess(this);
    mOutputPlayProcess = new QProcess(this);

    connect(mTranscodingProcess, SIGNAL(started()), this, SLOT(processStarted()));
    connect(mTranscodingProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(readyReadStandardOutput()));
    connect(mTranscodingProcess, SIGNAL(finished(int)), this, SLOT(encodingFinished()));
    connect(ui->close_button, SIGNAL(clicked()), qApp, SLOT(quit()));
}


void Dialog::on_play_input_button_clicked()
{
    QString program = "ffplay";
    QStringList arguments;
    QString input = ui->from_lineEdit->text();

    arguments<< input;

    mInputPlayProcess->start(program,arguments);

}


void Dialog::on_play_output_button_clicked()
{
    QString program = "ffplay";
    QStringList arguments;
    QString output = ui->to_lineEdit->text();

    arguments <<output;
    mInputPlayProcess->start(program, arguments);

}
void Dialog::on_convert_button_clicked()
{
    QString program = "ffmpeg";

    QStringList arguments;
    QString input = ui->from_lineEdit->text();

    if(input.isEmpty())
    {
        qDebug()<< "No input";
        QMessageBox::information(this,
                                 tr("ffmpeg"),tr("Input file not specified"));
        return;
    }

    QString output = ui->to_lineEdit->text();
    if(output.isEmpty())
    {
        qDebug()<< "No output";
        QMessageBox::information(this,
                                 tr("ffmpeg"),tr("Output file not specified"));
        return;

    }

    QString fileName = ui->to_lineEdit->text();
    qDebug() <<"output file check"<< fileName;
    qDebug()<< "QFile::exits(filename) " << QFile::exists(fileName);

    if(QFile::exists(fileName))
    {
        if(QMessageBox::question(this, tr("ffmpeg"),
                                 tr("There already exists a file called %1 in"
                                    "the current directory.Overwrite?").arg(fileName),
                                 QMessageBox::Yes|QMessageBox::No, QMessageBox::No) == QMessageBox::No)
        {
            return;
        }
        QFile::remove(fileName);
        while(QFile::exists(fileName)){
            qDebug()<< "output file still there";
        }
    }
    arguments <<"-i" << input << output;

    qDebug()<<arguments;

    mTranscodingProcess->setProcessChannelMode(QProcess::MergedChannels);
    mTranscodingProcess->start(program,arguments);
}


void Dialog::on_browse_button_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    "/home/karali",
                                                    tr("video (*.mp4 *.mov *.avi)"));

    if (!fileName.isEmpty())
    {
        ui->from_lineEdit->setText(fileName);
    }
}

void Dialog::readyReadStandardOutput()
{
    mOutputString.append(mTranscodingProcess->readAllStandardOutput());
    ui->textEdit->setText(mOutputString);

    //put the slider at the bottom
    ui->textEdit->verticalScrollBar()
            ->setSliderPosition(
                ui->textEdit->verticalScrollBar()->maximum());
}

void Dialog::processStarted()
{
    qDebug() << "processStarted()";
}

void Dialog::encodingFinished()
{
    //Set the encoding status by checking output file's existence

    QString fileName = ui->to_lineEdit->text();

    if(QFile::exists(fileName)){
        ui->transcoding_status_label->setText(ui->transcoding_status_label->text()+ "Successful!");
        ui->play_output_button->setEnabled(true);
    }
    else
    {
        ui->transcoding_status_label->setText(ui->transcoding_status_label->text()+" Failed!");
    }
}

