#ifndef PICTURE_H
#define PICTURE_H

#include <QWidget>
#include<mainwindow.h>
namespace Ui {
class picture;
}

class picture : public QWidget
{
    Q_OBJECT


public:
    explicit picture(QWidget *parent = 0);
    ~picture();

private:
    Ui::picture *ui;
};

#endif // PICTURE_H
