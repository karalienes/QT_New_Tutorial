#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Horizontal layout with 3 buttons

    QHBoxLayout *hLayout = new QHBoxLayout;

    QPushButton *b1 = new QPushButton;
    b1->setText("A");
    QPushButton *b2 = new QPushButton;
    b2->setText("B");
    QPushButton *b3 = new QPushButton;
    b3->setText("C");

    hLayout->addWidget(b1);
    hLayout->addWidget(b2);
    hLayout->addWidget(b3);

    QVBoxLayout *vLayout = new QVBoxLayout;

    QPushButton *b4 = new QPushButton;
    b4->setText("D");
    QPushButton *b5 = new QPushButton;
    b5->setText("E");
    QPushButton *b6 = new QPushButton;
    b6->setText("F");

    vLayout->addWidget(b4);
    vLayout->addWidget(b5);
    vLayout->addWidget(b6);

    //Main Layout create
    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addLayout(hLayout);
    mainLayout->addLayout(vLayout);

    //Main widget create
    QWidget *w = new QWidget;

    //Set the Main Layout of the widget
    w->setLayout(mainLayout);

    //Window title
    w->setWindowTitle("Layouts");

    //Display
    w->show();

    //Event loop
    return a.exec();
}
