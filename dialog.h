#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <QPushButton>
#include <QSize>
#include <QVBoxLayout>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    QString params;
    QString app_path;
    QString selected;
    ~Dialog();
public slots:
    void select_cert(QString);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
