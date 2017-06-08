#include "vlcproj.h"
#include "ui_vlcproj.h"
#include <string.h>

Buffer b[BUFFERSIZE];

Producer* prod;
Consumer* cons[5];

bool prodActive = false;
bool consActive[5] = {false, false, false, false, false};

VLCProj::VLCProj(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VLCProj)
{
    ui->setupUi(this);
    initSync(b);
}

VLCProj::~VLCProj()
{
    delete ui;
}

void VLCProj::on_pushButton_6_clicked()
{
    if(prodActive){
            prod->deactivate();
            prodActive = false;
            //ui->pushButton_6->setChecked(false);
            QString txt("Start");
            ui->pushButton_6->setText(txt);

    }else{
        char ip[20];
        char port[7];
        const char* temp = ui->plainTextEdit_6->toPlainText().toStdString().c_str();
        strcpy(ip, temp);
        temp = ui->spinBox_6->text().toStdString().c_str();
        strcpy(port, temp);
       prod = new Producer(&prodActive, ip, port, b);
        if(!prodActive){
            //ui->pushButton_6->setChecked(false);
            delete prod;
        }else{
            //ui->pushButton_6->setChecked(true);
            QString txt("Stop");
            ui->pushButton_6->setText(txt);
        }
    }
}

void VLCProj::on_pushButton_clicked()
{
    if(consActive[0]){
            cons[0]->deactivate();
            consActive[0] = false;
            //ui->pushButton_6->setChecked(false);
            QString txt("Start");
            ui->pushButton->setText(txt);

    }else{
        char ip[20];
        char port[7];
        const char* temp = ui->plainTextEdit->toPlainText().toStdString().c_str();
        strcpy(ip, temp);
        temp = ui->spinBox->text().toStdString().c_str();
        strcpy(port, temp);
        bool itisVIP = ui->checkBox->isChecked();
        cons[0] = new Consumer(&consActive[0], ip, port, b, itisVIP);
        if(!consActive[0]){
            //ui->pushButton_6->setChecked(false);
            delete cons[0];
        }else{
            //ui->pushButton_6->setChecked(true);
            QString txt("Stop");
            ui->pushButton->setText(txt);
        }
    }
}

void VLCProj::on_pushButton_2_clicked()
{
    if(consActive[1]){
            cons[1]->deactivate();
            consActive[1] = false;
            //ui->pushButton_6->setChecked(false);
            QString txt("Start");
            ui->pushButton_2->setText(txt);

    }else{
        char ip[20];
        char port[7];
        const char* temp = ui->plainTextEdit_2->toPlainText().toStdString().c_str();
        strcpy(ip, temp);
        temp = ui->spinBox_2->text().toStdString().c_str();
        strcpy(port, temp);
        bool itisVIP = ui->checkBox_2->isChecked();
        cons[1] = new Consumer(&consActive[1], ip, port, b, itisVIP);
        if(!consActive[1]){
            //ui->pushButton_6->setChecked(false);
            delete cons[1];
        }else{
            //ui->pushButton_6->setChecked(true);
            QString txt("Stop");
            ui->pushButton_2->setText(txt);
        }
    }
}

void VLCProj::on_pushButton_3_clicked()
{
    if(consActive[2]){
            cons[2]->deactivate();
            consActive[2] = false;
            //ui->pushButton_6->setChecked(false);
            QString txt("Start");
            ui->pushButton_3->setText(txt);

    }else{
        char ip[20];
        char port[7];
        const char* temp = ui->plainTextEdit_3->toPlainText().toStdString().c_str();
        strcpy(ip, temp);
        temp = ui->spinBox_3->text().toStdString().c_str();
        strcpy(port, temp);
        bool itisVIP = ui->checkBox_3->isChecked();
        cons[2] = new Consumer(&consActive[2], ip, port, b, itisVIP);
        if(!consActive[2]){
            //ui->pushButton_6->setChecked(false);
            delete cons[2];
        }else{
            //ui->pushButton_6->setChecked(true);
            QString txt("Stop");
            ui->pushButton_3->setText(txt);
        }
    }
}

void VLCProj::on_pushButton_4_clicked()
{
    if(consActive[3]){
            cons[3]->deactivate();
            consActive[3] = false;
            //ui->pushButton_6->setChecked(false);
            QString txt("Start");
            ui->pushButton_4->setText(txt);

    }else{
        char ip[20];
        char port[7];
        const char* temp = ui->plainTextEdit_4->toPlainText().toStdString().c_str();
        strcpy(ip, temp);
        temp = ui->spinBox_4->text().toStdString().c_str();
        strcpy(port, temp);
        bool itisVIP = ui->checkBox_4->isChecked();
        cons[3] = new Consumer(&consActive[3], ip, port, b, itisVIP);
        if(!consActive[3]){
            //ui->pushButton_6->setChecked(false);
            delete cons[3];
        }else{
            //ui->pushButton_6->setChecked(true);
            QString txt("Stop");
            ui->pushButton_4->setText(txt);
        }
    }
}

void VLCProj::on_pushButton_5_clicked()
{
    if(consActive[4]){
            cons[4]->deactivate();
            consActive[4] = false;
            //ui->pushButton_6->setChecked(false);
            QString txt("Start");
            ui->pushButton_5->setText(txt);

    }else{
        char ip[20];
        char port[7];
        const char* temp = ui->plainTextEdit_5->toPlainText().toStdString().c_str();
        strcpy(ip, temp);
        temp = ui->spinBox_5->text().toStdString().c_str();
        strcpy(port, temp);
        bool itisVIP = ui->checkBox_5->isChecked();
        cons[4] = new Consumer(&consActive[4], ip, port, b, itisVIP);
        if(!consActive[4]){
            //ui->pushButton_6->setChecked(false);
            delete cons[4];
        }else{
            //ui->pushButton_6->setChecked(true);
            QString txt("Stop");
            ui->pushButton_5->setText(txt);
        }
    }
}
