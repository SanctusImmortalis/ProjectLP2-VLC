#include "vlcproj.h"
#include "ui_vlcproj.h"

VLCProj::VLCProj(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VLCProj)
{
    ui->setupUi(this);
}

VLCProj::~VLCProj()
{
    delete ui;
}
