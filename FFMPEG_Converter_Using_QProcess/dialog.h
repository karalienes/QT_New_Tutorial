#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QProcess>
#include <QFile>
#include <QTextEdit>
#include <QDebug>
#include <QString>
#include <QScrollBar>
#include <QMessageBox>
#include <QFileInfo>
#include <QFileDialog>

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
    void on_play_input_button_clicked();

    void on_play_output_button_clicked();

    void on_convert_button_clicked();

    void on_browse_button_clicked();

    void readyReadStandardOutput();
    void processStarted();
    void encodingFinished();

private:
    Ui::Dialog *ui;

    QProcess *mTranscodingProcess;
    QProcess *mInputPlayProcess;
    QProcess *mOutputPlayProcess;
    QString mOutputString;
};
#endif // DIALOG_H
