#include "mainwindow.h"
#include <QApplication>
#include<user_login.h>
#include<maketsql.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    maketsql sql;
    return a.exec();
}
