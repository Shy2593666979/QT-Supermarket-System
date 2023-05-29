#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<user_login.h>
#include<QSqlError>
#include<QSqlQuery>
#include<QString>
#include<QDebug>
#include<QMessageBox>
#include<maketsql.h>
#include<QStringList>
#include<dlg_addmak.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateTable();
private slots:
    void on_pushButton_clicked();

    void on_btn_sln_clicked();

    void on_btn_add_clicked();

    void on_btn_clear_clicked();

    void on_btn_update_clicked();

    void on_btn_del_clicked();

    void on_btn_select_clicked();

    void on_btn_over_clicked();

    void on_btn_maket_clicked();

private:
    Ui::MainWindow *ui;
    user_login user;
    maketsql *m_ptrMaketSql;
    QStringList m_lName;
    Dlg_AddMak m_DlgAddMak;
};

#endif // MAINWINDOW_H
