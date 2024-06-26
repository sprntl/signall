#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <dialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *e) override;
    void sign();
    QStringList filelist;

    ~MainWindow();

private slots:
    void on_btnDir_clicked();

    void on_btnFiles_clicked();


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
