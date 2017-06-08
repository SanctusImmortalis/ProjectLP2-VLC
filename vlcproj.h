#ifndef VLCPROJ_H
#define VLCPROJ_H

#include <QMainWindow>

namespace Ui {
class VLCProj;
}

class VLCProj : public QMainWindow
{
    Q_OBJECT

public:
    explicit VLCProj(QWidget *parent = 0);
    ~VLCProj();

private:
    Ui::VLCProj *ui;
};

#endif // VLCPROJ_H
