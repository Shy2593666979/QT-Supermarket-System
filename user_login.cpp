#include "user_login.h"
#include "ui_user_login.h"
#include<QtSql>
#include<QSqlError>
#include<QSqlQuery>
#include<QString>
#include<QDebug>
#include<QMessageBox>
user_login::user_login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_login)
{
    ui->setupUi(this);
}

user_login::~user_login()
{
    delete ui;
}

void user_login::on_btn_userlogin_clicked()
{
    QString str1=ui->le_user->text();
    QString str2=ui->lineEdit_2->text();
    QString s1="2228824083";
    QString s2="2128824092";
    if(str1!=s1&&str1!=s2)
    {
        QMessageBox::information(nullptr,"用户名错误","数据库中没有该用户");
        return ;
    }
    if(str1!=str2)
    {
        QMessageBox::information(nullptr,"错误信息","用户名与密码不匹配!");
        return ;
    }
    emit sendloginSuccess();
}
void user_login::on_btn_close_clicked()
{
    this->hide();
}
