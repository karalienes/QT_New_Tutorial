#ifndef LAYOUTDIALOG_H
#define LAYOUTDIALOG_H

#include <QDialog>

namespace Ui {
class LayoutDialog;
}

class LayoutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LayoutDialog(QWidget *parent = nullptr);
    ~LayoutDialog();

private:
    Ui::LayoutDialog *ui;
};

#endif // LAYOUTDIALOG_H
