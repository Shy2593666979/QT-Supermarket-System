#include "picture.h"
#include "ui_picture.h"
#include<mainwindow.h>
picture::picture(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::picture)
{
    ui->setupUi(this);

   /* QPixmap image;
    image.load("code.jpg");
    ui->label->clear();
    ui->label->setPixmap(image);
    ui->label->show();
    auto p=[&](){
        this->show();
    };
    connect(&minw,&MainWindow::load_picture,this,p);*/
}
picture::~picture()
{
    delete ui;
}
