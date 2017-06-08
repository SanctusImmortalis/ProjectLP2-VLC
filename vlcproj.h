#ifndef VLCPROJ_H
#define VLCPROJ_H

#include <QMainWindow>
#include "Buffer.h"
#include "Consumer.h"
#include "Producer.h"
#include "Sync.h"

namespace Ui {
class VLCProj;
}

class VLCProj : public QMainWindow
{
    Q_OBJECT

public:
    explicit VLCProj(QWidget *parent = 0);
    ~VLCProj();

private slots:

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::VLCProj *ui;
};

#endif // VLCPROJ_H
