#ifndef USER_LOGIN_H
#define USER_LOGIN_H

#include <QWidget>
#include<QSqlError>
#include<QSqlQuery>
#include<QString>
#include<QDebug>
#include<QMessageBox>
namespace Ui {
class user_login;
}

class user_login : public QWidget
{
    Q_OBJECT

public:
    explicit user_login(QWidget *parent = 0);
    ~user_login();

signals:
    void sendloginSuccess();
private slots:
    void on_btn_userlogin_clicked();

    //void on_btn_tuichu_clicked();

    void on_btn_close_clicked();

private:
    Ui::user_login *ui;
};

#endif // USER_LOGIN_H
