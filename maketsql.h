#ifndef MAKETSQL_H
#define MAKETSQL_H

#include <QObject>
#include<QSqlDatabase>
struct MaketInfo
{
    quint32 id;
    QString name;
    QString address;
    QString quality;
    quint32 price;
};

class maketsql : public QObject
{
    Q_OBJECT
public:
    static maketsql *ptrMaketSql;
    static maketsql *getinstance()
    {
        if(ptrMaketSql == nullptr)
        {
            ptrMaketSql =new maketsql;
        }
        return ptrMaketSql;
    }

    explicit maketsql(QObject *parent = nullptr);
    //打开数据库
    void init();
    
    //查询数量
    quint32 getMaketCnt();
    
    //查询在几页
    QList<MaketInfo>getPageMa(quint32 page,quint32 uiCnt);

    //增加商品
    bool addMaket(MaketInfo info);

    //修改商品
    void updateMaket(MaketInfo info);

    //删除商品
    bool delMaket(quint32 id);

    //清空商品
    bool clearMaket();
private:
    QSqlDatabase m_db;
signals:

public slots:
};

#endif // MAKETSQL_H
