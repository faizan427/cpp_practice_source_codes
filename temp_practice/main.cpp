#include "mainwindow.h"
#include "QVBoxLayout"
#include "QDebug"
#include "QString"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ui->setupUi(this);
    QHBoxLayout *box_1 = new QHBoxLayout;
    QPushButton *button_1 = new QPushButton("Enter");
    QPushButton *button_2 = new QPushButton("Clear");
    box_1->addWidget(button_1);
    box_1->addSpacerItem(new QSpacerItem(10,5));
    box_1->addWidget(button_2);
    QVBoxLayout *v_box_1 = new QVBoxLayout;
    v_box_1->addWidget(new QLabel("Label"));
    v_box_1->addLayout(box_1);
    ui->centralwidget->setLayout(v_box_1);
    MainWindow::setFixedHeight(150);
    MainWindow::setFixedWidth(500);
   // qDebug() << ui->centralwidget->layout()->itemAt(0)->widget();
   QLabel *label= qobject_cast<QLabel*>(ui->centralwidget->layout()->itemAt(0)->widget());
   // qDebug() << x << Qt::endl;
    bool turn =true;
   connect(button_1, &QPushButton::clicked, label,[label, turn,button_1]() mutable{
       label->setText(QString(button_1->text()));
       if(turn)
       {
           button_1->setFixedHeight(button_1->height()+5);
           turn = !turn;
       }
       else
       {
           button_1->setFixedHeight(button_1->height()-5);
           turn = true;
       }

   });
    button_2->setCheckable(true);
   connect(button_2, &QPushButton::toggled, label, [label,button_2](bool val){
       qDebug() << val << Qt::endl;
       label->setText(QString(button_2->text()));
       if(val)
       {
           button_2->setFixedHeight(button_2->height()+5);
       }
       else
       {
           button_2->setFixedHeight(button_2->height());
       }

   });

}

MainWindow::~MainWindow()
{
    delete ui;
}

