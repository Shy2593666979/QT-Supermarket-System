#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSqlError>
#include<QSqlQuery>
#include<QString>
#include<QDebug>
#include<QMessageBox>
#include<maketsql.h>
#include<user_login.h>
#include<dlg_addmak.h>
#include<QVector>
#include<picture.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_ptrMaketSql(nullptr)
{
    ui->setupUi(this);


    user.show();    //打开商家窗口
    auto f=[&](){
        this->show();
    };
    connect(&user,&user_login::sendloginSuccess,this,f);
    ui->treeWidget->clear();


    QStringList l;
    l<<"超市管理界面";
    QTreeWidgetItem *pf=new QTreeWidgetItem(ui->treeWidget,l);
    ui->treeWidget->addTopLevelItem(pf);
    l.clear();
    l<<"用户界面";
    QTreeWidgetItem *p1=new QTreeWidgetItem(pf,l);
    l.clear();
    l<<"商家界面";
    QTreeWidgetItem *p2=new QTreeWidgetItem(pf,l);
    pf->addChild(p1);
    pf->addChild(p2);
    ui->line_userName->setText("      ACMer");
    ui->treeWidget->expandAll();
    ui->stackedWidget->setCurrentIndex(0);
    m_ptrMaketSql = maketsql::getinstance();
    m_ptrMaketSql->init();

    m_lName<<"乐事薯片";
    m_lName<<"百事可乐";
    m_lName<<"可口可乐";
    m_lName<<"速溶咖啡";
    m_lName<<"芒果干干";
    m_lName<<"草莓布丁";
    m_lName<<"字母饼干";
    m_lName<<"西湖蜜梨";
    m_lName<<"辣条豆皮";
    m_lName<<"蜜汁肉脯";
    m_lName<<"酸奶果粒";
    m_lName<<"盐焗大虾";
    m_lName<<"辣条烤肠";
    m_lName<<"裹个凉皮";
    m_lName<<"濮阳壮馍";
    m_lName<<"林州皮渣";
    ui->tableWidget->clear();
    auto cnt= m_ptrMaketSql->getMaketCnt();
    QList<MaketInfo> lMaket=m_ptrMaketSql->getPageMa(0,cnt);
     //ui->tableWidget->clear();
    ui->tableWidget->setRowCount(cnt);
    for(int i=0;i<lMaket.size();i++)
    {
        //ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number((i))));
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(lMaket[i].id)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(lMaket[i].name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(lMaket[i].address));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(lMaket[i].quality));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(lMaket[i].price)));
    }
    updateTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    exit(0);
}

void MainWindow::on_btn_sln_clicked()
{
            MaketInfo info;
    for(int i=0;i<m_lName.size();i++)
    {

        info.name=m_lName[i];
        info.id=i+1;
        info.quality="12";
        if(i%3)
        {
            info.price=i*2;
            info.address="河南濮阳";
        }
        else if(i%2)
        {
            info.address="河南新乡";
            info.price=i*2/3;
        }
        else
        {
            info.address="河南郑州";
            info.price=i+2;
        }
        if(i==15)
        {
            info.address="河南林州";
        }
        m_ptrMaketSql ->addMaket(info);

    }
    auto cnt= m_ptrMaketSql->getMaketCnt();
    QList<MaketInfo> lMaket=m_ptrMaketSql->getPageMa(0,cnt);
     //ui->tableWidget->clear();
    ui->tableWidget->setRowCount(cnt);
    for(int i=0;i<lMaket.size();i++)
    {
        //ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number((i))));
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(lMaket[i].id)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(lMaket[i].name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(lMaket[i].address));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(lMaket[i].quality));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(lMaket[i].price)));
    }
}

void MainWindow::on_btn_add_clicked()
{
    m_DlgAddMak.show();
    auto cnt= m_ptrMaketSql->getMaketCnt();
    QList<MaketInfo> lMaket=m_ptrMaketSql->getPageMa(0,cnt);
     //ui->tableWidget->clear();
    ui->tableWidget->setRowCount(cnt);
    for(int i=0;i<lMaket.size();i++)
    {
        //ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number((i))));
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(lMaket[i].id)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(lMaket[i].name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(lMaket[i].address));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(lMaket[i].quality));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(lMaket[i].price)));
    }
}

void MainWindow::on_btn_clear_clicked()
{
   m_ptrMaketSql->clearMaket();
   auto cnt= m_ptrMaketSql->getMaketCnt();
   QList<MaketInfo> lMaket=m_ptrMaketSql->getPageMa(0,cnt);
    //ui->tableWidget->clear();
   ui->tableWidget->setColumnCount(5);
   QStringList l;
   l<<"商品编号"<<"商品名称"<<"生产地址"<<"保质期(月)"<<"价格(元)";
   ui->tableWidget->setRowCount(cnt);
   for(int i=0;i<lMaket.size();i++)
   {
       //ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number((i))));
       ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(lMaket[i].id)));
       ui->tableWidget->setItem(i,1,new QTableWidgetItem(lMaket[i].name));
       ui->tableWidget->setItem(i,2,new QTableWidgetItem(lMaket[i].address));
       ui->tableWidget->setItem(i,3,new QTableWidgetItem(lMaket[i].quality));
       ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(lMaket[i].price)));
   }
}

void MainWindow::on_btn_update_clicked()
{
    /*ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(5);
    QStringList l;
    l<<"商品编号"<<"商品名称"<<"生产地址"<<"保质期(月)"<<"价格(元)";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    auto cnt= m_ptrMaketSql->getMaketCnt();
    QList<MaketInfo> lMaket=m_ptrMaketSql->getPageMa(0,cnt);
    ui->tableWidget->setRowCount(cnt);
    for(int i=0;i<lMaket.size();i++)
    {
        //ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number((i))));
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(lMaket[i].id)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(lMaket[i].name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(lMaket[i].address));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(lMaket[i].quality));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(lMaket[i].price)));
    }*/
    MaketInfo info;
    int i=ui->tableWidget->currentRow();
    if(i>=0)
    {
        info.id=ui->tableWidget->item(i,0)->text().toUInt();
        info.name=ui->tableWidget->item(i,1)->text();
        info.address=ui->tableWidget->item(i,2)->text();
        info.quality=ui->tableWidget->item(i,3)->text();
        info.price=ui->tableWidget->item(i,4)->text().toUInt();
        m_DlgAddMak.setType(false,info);
        m_DlgAddMak.exec();
    }
    updateTable();
}

void MainWindow::on_btn_del_clicked()
{
    int i=ui->tableWidget->currentRow();
    if(i>=0)
    {
        quint32 id=ui->tableWidget->item(i,0)->text().toUInt();
        m_ptrMaketSql->delMaket(id);
          updateTable();
        /*auto cnt= m_ptrMaketSql->getMaketCnt();
        QList<MaketInfo> lMaket=m_ptrMaketSql->getPageMa(0,cnt);
        ui->tableWidget->setRowCount(cnt);
        for(int i=0;i<lMaket.size();i++)
        {
            //ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number((i))));
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(lMaket[i].id)));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(lMaket[i].name));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(lMaket[i].address));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(lMaket[i].quality));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(lMaket[i].price)));
        }*/
        QMessageBox::information(nullptr,"信息","删除成功");
    }

}
void MainWindow::updateTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(5);
    QStringList l;
    l<<"商品编号"<<"商品名称"<<"生产地址"<<"保质期(月)"<<"价格(元)";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    auto cnt= m_ptrMaketSql->getMaketCnt();
    QList<MaketInfo> lMaket=m_ptrMaketSql->getPageMa(0,cnt);
    ui->tableWidget->setRowCount(cnt);
    for(int i=0;i<lMaket.size();i++)
    {
        //ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number((i))));
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(lMaket[i].id)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(lMaket[i].name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(lMaket[i].address));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(lMaket[i].quality));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(lMaket[i].price)));
    }
}

void MainWindow::on_btn_select_clicked()
{
     QString strFill=ui->le_select->text();
     if(strFill.isEmpty())
     {
         QMessageBox::information(nullptr,"信息","搜索为空");
         return ;
     }
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(5);
    QStringList l;
    l<<"商品编号"<<"商品名称"<<"生产地址"<<"保质期(月)"<<"价格(元)";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    auto cnt= m_ptrMaketSql->getMaketCnt();
    QList<MaketInfo> lMaket=m_ptrMaketSql->getPageMa(0,cnt);



    int index=0;
    QVector<int>res;
    for(int i=0;i<lMaket.size();i++)
    {
        if(!lMaket[i].name.contains(strFill))
        {
            continue;
        }
         res.push_back(i);
        ui->tableWidget->setItem(index,0,new QTableWidgetItem(QString::number(lMaket[i].id)));
        ui->tableWidget->setItem(index,1,new QTableWidgetItem(lMaket[i].name));
        ui->tableWidget->setItem(index,2,new QTableWidgetItem(lMaket[i].address));
        ui->tableWidget->setItem(index,3,new QTableWidgetItem(lMaket[i].quality));
        ui->tableWidget->setItem(index,4,new QTableWidgetItem(QString::number(lMaket[i].price)));
                 index++;
    }
        ui->tableWidget->setRowCount(index);
    /*for(int i=0;i<res.size();i++)
    {
        //ui->tableWidget->setRowCount(index);
        ui->tableWidget->setItem(res[i],0,new QTableWidgetItem(QString::number(lMaket[res[i]].id)));
        ui->tableWidget->setItem(res[i],1,new QTableWidgetItem(lMaket[res[i]].name));
        ui->tableWidget->setItem(res[i],2,new QTableWidgetItem(lMaket[res[i]].address));
        ui->tableWidget->setItem(res[i],3,new QTableWidgetItem(lMaket[res[i]].quality));
        ui->tableWidget->setItem(res[i],4,new QTableWidgetItem(QString::number(lMaket[res[i]].price)));
    }*/
}

void MainWindow::on_btn_over_clicked()
{
    picture * sk=new picture;
    sk->show();
    //emit load_picture();
}

void MainWindow::on_btn_maket_clicked()
{
    QMessageBox::information(nullptr,"提示信息","商家页面暂不对外开放,敬请期待！");
    return ;
}
