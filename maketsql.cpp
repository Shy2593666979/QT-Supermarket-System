#include "maketsql.h"
#include<QtSql>
#include<QSqlError>
#include<QSqlQuery>
#include<QString>
#include<QDebug>
#include<QMessageBox>
#include<mainwindow.h>
#include<user_login.h>
maketsql *maketsql::ptrMaketSql =nullptr;
maketsql::maketsql(QObject *parent) : QObject(parent)
{
        init();
            /*QSqlQuery query;
            QString sql="insert into maket(id ,name,address,quality,price) values(212882,'光','濮阳','6',12)";
            query.exec(sql);*/
        getMaketCnt();
        getPageMa(2,3);

}

void maketsql::init()
{
            m_db=QSqlDatabase::addDatabase("QMYSQL");    //括号内要写出数据库的类型
            //设置数据库
            m_db.setHostName("localhost"); //设置数据库的主机ip
            //设置数据库的用户名
            m_db.setPort(3307);
            m_db.setUserName("root");
            //设置数据库的密码
            m_db.setPassword("mingguang0703");    //这个就是安装MySQL时设置的密码
            //设置数据库的名字
            m_db.setDatabaseName("qmaket");
            //打开数据库（已经安装过mysql驱动了）
            if(m_db.open()==false)
             {
                    qDebug() << "No Open DataBase !";
             }
            else qDebug()<<"Success Open DataBase !";
}

quint32 maketsql::getMaketCnt()
{
    QSqlQuery sql(m_db);
    sql.exec("select count(id) from maket;" );
    quint32 uiCnt=0;
    while(sql.next())
    {
        uiCnt = sql.value(0).toUInt();
    }
    return uiCnt;
}

QList<MaketInfo> maketsql::getPageMa(quint32 page, quint32 uiCnt)
{
    QList<MaketInfo> l;
    QSqlQuery sql(m_db);
    QString strsql=QString("select * from maket order by id limit %1 offset %2 ").arg(uiCnt).arg(page * uiCnt);
    sql.exec(strsql);
    MaketInfo info;
    while(sql.next())
    {
        info.id=sql.value(0).toUInt();
        info.name=sql.value(1).toString();
        info.address=sql.value(2).toString();
        info.quality=sql.value(3).toString();
        info.price=sql.value(4).toUInt();
        l.push_back(info);
    }
    return l;
}

bool maketsql::addMaket(MaketInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql=QString("insert into maket(id ,name,address,quality,price) values(%1,'%2','%3','%4',%5)").arg(info.id).arg(info.name).arg(info.address).arg(info.quality).arg(info.price);
    return sql.exec(strSql);
}

void maketsql::updateMaket(MaketInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql=QString("update  maket set id = %1 name ='%2' address = '%3' quality ='%4' price= %5  where id = %6").arg(info.id).arg(info.name).arg(info.address).arg(info.quality).arg(info.price).arg(info.id);
    sql.exec(strSql);
}

bool maketsql::delMaket(quint32 id)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from maket where id = %1").arg(id));
}

bool maketsql::clearMaket()
{
    QSqlQuery sql(m_db);
    return sql.exec("delete from maket");
}
