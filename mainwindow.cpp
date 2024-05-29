#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QString>
#include <QProcess>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnFiles->click();
    QFile file("/opt/cprocsp/bin/amd64/cryptcp");
    if (file.exists()) ui->status->setText("Установлен");
            else ui->status->setText("Не установлен");
    setAcceptDrops(true);
    ui->pushButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnDir_clicked()
{
    ui->extension->setDisabled(true);
}


void MainWindow::on_btnFiles_clicked()
{
        ui->extension->setDisabled(false);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
           event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    foreach (const QUrl &url, event->mimeData()->urls()) {
            QString fileName = url.toLocalFile();
            filelist.append(fileName);
    }
    ui->pushButton->setEnabled(true);
}


void MainWindow::sign()
{
    QString file;
    QString certificate;
    QString key_path="/var/opt/cprocsp/keys/user";
    /*QString program = "/opt/cprocsp/bin/amd64/cryptcp";
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program);*/
    Dialog *change_cert = new Dialog();
    change_cert->show();
}


void MainWindow::on_pushButton_clicked()
{
        sign();
}

