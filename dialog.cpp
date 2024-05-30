#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    QString cont_list;
    QStringList list;
    QStringList list2;
    ui->setupUi(this);
    app_path="/opt/cprocsp/bin/amd64/csptest";
    QProcess *app=new QProcess();
    app->setProgram(app_path);
    app->setArguments({"-keys","-enum", "-verifyc" ,"-fqcn"});
    app->start();
    app->waitForFinished();
    cont_list.append(app->readAllStandardOutput());
    app->close();
    cont_list.replace("\n","?");
    list=cont_list.split('?');
    for (int i=2;i<=list.size()-5;i++)
    {
        ui->textEdit->append(list[i]);
        list2.append(list[i]);
    }
    int pos_y=-30;
    QVBoxLayout *vbox = new QVBoxLayout();
    for (int i=0;i<=list2.size()-1;i++)
    {
        QPushButton *cert = new QPushButton ();
        cert->setText(list2[i]);
        cert->setGeometry(0,pos_y+30,20,ui->scrollArea->width()-50);
        connect(cert,SIGNAL(clicked),this,SLOT(select_cert(list2[i])));
        vbox->addWidget(cert);
    }
    ui->scrollArea->setLayout(vbox);
    this->setFixedSize(400,305);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::select_cert(QString s)
{
    ui->textEdit->append(s);
}
