#include "search.h"
#include "ui_search.h"
#include "taggy.h"
#include <QMessageBox>
#include <QVector>
#include <string>
#include <vector>

search::search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
}

search::~search()
{
    delete ui;
}

void search::on_pushButton_clicked()
{
    QString tag=ui->lineEdit->text();
    QMessageBox::information(this,"..",tag);
    addItemsToList(tag);
}

void search::addItemsToList(QString tag){
    Taggy t;
    std::vector<std::string> vec = t.searching(tag.toStdString());
    QVector<QString> qt;
    std::transform(vec.begin(), vec.end(), std::back_inserter(qt), [](const std::string &v){ return QString::fromStdString(v); });
    for(int i=0;i<qt.size();i++){
        ui->listWidget->addItem(qt[i]);
    }
}
