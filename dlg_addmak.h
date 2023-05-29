#ifndef DLG_ADDMAK_H
#define DLG_ADDMAK_H

#include <QDialog>
#include<maketsql.h>
namespace Ui {
class Dlg_AddMak;
}

class Dlg_AddMak : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_AddMak(QWidget *parent = 0);
    ~Dlg_AddMak();
    void setType(bool isAdd,MaketInfo info);
private slots:

    void on_btn_save_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dlg_AddMak *ui;
    int m_id;
    bool is_mAdd;
    MaketInfo m_info;
};

#endif // DLG_ADDMAK_H
