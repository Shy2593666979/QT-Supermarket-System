#include "dlg_addmak.h"
#include "ui_dlg_addmak.h"
#include<maketsql.h>
#include<QMessageBox>
Dlg_AddMak::Dlg_AddMak(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_AddMak)
{
    ui->setupUi(this);
}

Dlg_AddMak::~Dlg_AddMak()
{
    delete ui;
}

void Dlg_AddMak::setType(bool isAdd, MaketInfo info)
{

    is_mAdd=isAdd;
    m_info=info;
    ui->le_id->setText(QString::number(info.id));
    ui->le_name->setText(info.name);
    ui->le_address->setText(info.address);
    ui->le_quality->setText(info.quality);
    ui->le_price->setText(QString::number(info.price));
}


void Dlg_AddMak::on_btn_save_clicked()
{
    MaketInfo info;
    auto ptr=maketsql::getinstance();
    info.id=ui->le_id->text().toUInt();
    info.name=ui->le_name->text();
    info.address=ui->le_address->text();
    info.quality=ui->le_quality->text();
    info.price=ui->le_price->text().toUInt();
    if(is_mAdd)
    {
        info.id=m_info.id;
        ptr->addMaket(info);
    }
    else
     {
        info.id=m_info.id;
        ptr->updateMaket(info);
    }
    QMessageBox::information(nullptr,"商品","增加成功！");
    this->hide();
}

void Dlg_AddMak::on_pushButton_2_clicked()
{
    this->hide();
}
