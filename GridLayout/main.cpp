#include <QApplication>
#include <QtCore>
#include <QtGui>
#include <QPushButton>
#include <QGridLayout>
/*
 *
If the GridLayout is resized, all items in the layout will be rearranged. It is similar to the widget-based QGridLayout.
All children of the GridLayout element will belong to the layout. If you want a layout with just one row or one column,
you can use the RowLayout or ColumnLayout. These offers a bit more convenient API, and improves readability.

By default items will be arranged according to the flow property. The default value of the flow property is GridLayout.LeftToRight.

If the columns property is specified, it will be treated as a maximum limit of how many columns the layout can have,
before the auto-positioning wraps back to the beginning of the next row. The columns property is only used when flow is GridLayout.LeftToRight.
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGridLayout *objGridLayout = new QGridLayout;

    //six button definitions
    QPushButton *b1 = new QPushButton;
    b1->setText("A");
    QPushButton *b2 = new QPushButton;
    b2->setText("B");
    QPushButton *b3 = new QPushButton;
    b3->setText("C");
    QPushButton *b4 = new QPushButton;
    b4->setText("D");
    QPushButton *b5 = new QPushButton;
    b5->setText("E");
    QPushButton *b6 = new QPushButton;
    b6->setText("F");
    //span represents the button lenght
    //0st row
    objGridLayout->addWidget(b1,0,0,1,1);
    objGridLayout->addWidget(b2,0,1,1,1);
    objGridLayout->addWidget(b3,0,2,1,1);

    //1st row
    objGridLayout->addWidget(b4,1,0,1,1);

    //2st row
    objGridLayout->addWidget(b5,2,0,1,2);

    //3st row
    objGridLayout->addWidget(b6,3,0,1,3);

    //Create main widget
    QWidget *mainWidget = new QWidget;

    //Set the grid layout as a mainLayout
    mainWidget->setLayout(objGridLayout);

    //Window title
    mainWidget->setWindowTitle("Grid Layout(3*4)");

    //Display
    mainWidget->show();

    //Event loop
    return a.exec();
}
