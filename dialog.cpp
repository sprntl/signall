#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    QStringList cont_list;
    ui->setupUi(this);
    app_path="/opt/cprocsp/bin/amd64/csptest";
    QProcess *app=new QProcess();
    app->setProgram(app_path);
    app->setArguments({"-keys","-enum", "-verifyc" ,"-fqcn"});
    app->start();
    app->waitForFinished();
    cont_list.append(app->readAllStandardOutput());
    app->close();
    for (int i=0;i<=cont_list.count()-1;i++)
    {
        ui->textEdit->append(cont_list[i]);
    }
    ui->label->setText(cont_list.at(3));


}

Dialog::~Dialog()
{
    delete ui;
}
