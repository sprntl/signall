#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QString>
#include <QProcess>

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
    if (event->mimeData()->hasFormat("text/plain"))
           event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    foreach (const QUrl &url, event->mimeData()->urls()) {
            QString fileName = url.toLocalFile();
            qDebug() << "Dropped file:" << fileName;
    }
}



void MainWindow::sign()
{
    QString file;
    QString certificate;
    QString program = "/opt/cprocsp/bin/amd64/cryptcp";
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program);
}

