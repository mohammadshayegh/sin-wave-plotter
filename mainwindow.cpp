#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmath.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    this->A = 1;
    this->phi = 0;
    this->F = 0.01;
    this->graphs = 4;
    sinPlotter();
}

void MainWindow::sinPlotter()
{
    double xLength = 100;
    QVector<double> x(xLength+10),y(xLength+10);

    coordination(x, y);

    ui->customPlot->xAxis->setRange(0, xLength + 0.1);
    ui->customPlot->yAxis->setRange(-1.5*A , 1.5*A);
    ui->customPlot->replot();
}

void MainWindow::coordination(QVector<double> &x, QVector<double> &y)
{
    double xLength =100;
    for(int k=3, j=0; j<graphs; j++, k+=2)
    {
        ui->customPlot->addGraph();
        x_y_setter(x,y,xLength,k);
        ui->customPlot->graph(j)->addData(x,y);

        QColor color(rand()%256,rand()%200,rand()%156) ;
        ui->customPlot->graph(j)->setPen(QPen(color));
    }
}

double MainWindow::oddSigma(double end,float t)
{
    double sum = 0, pi = 3.141592;

    for(double k=1; k<end; k+=2)
    {
        sum += (1.0/k) * qSin(2*k*pi*F*(t)+phi) ;
    }
    return sum;
}

void MainWindow::x_y_setter(QVector<double> &x, QVector<double> &y, int xLength,double k)
{
    for(int i=0; i<xLength+10; i++)
    {
        x[i] = i;
        y[i] = float(4)/3.14 * A * oddSigma(k,i);
    }
}

void MainWindow::widgetCleaner()
{
    for(int i=0; i < this->graphs; i++)
        ui->customPlot->graph(i)->data().data()->clear();

    this->graphs = 0;
    sinPlotter();

    ui->customPlot->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    A   = ui->domain->text().toDouble();
    phi = ui->phi->text().toDouble()   ;
    F   = ui->freq->text().toDouble()  ;
    this->graphs = ui->spinBox->text().toInt();

    ui->customPlot->clearGraphs();
    sinPlotter();
    ui->customPlot->update();
}

void MainWindow::on_setter_clicked()
{
    for(int i=0; i<2; i++)
    {
        widgetCleaner();
        int k = ui->spinBox->text().toInt()*2+1;

        double xLength = 100;
        QVector<double> x(xLength+10),y(xLength+10);

        x_y_setter(x,y,xLength,k);

        ui->customPlot->graph(0)->addData(x,y);

        QColor color(rand()%256,rand()%200,rand()%156) ;
        ui->customPlot->graph(0)->setPen(QPen(color));

        ui->customPlot->update();
    }
}

void MainWindow::on_spinBox_valueChanged(int val)
{
    widgetCleaner();

    this->graphs = val;
    sinPlotter();

    ui->customPlot->update();
}

void MainWindow::on_setter_2_clicked()
{
    widgetCleaner();

    int bandwidth = ui->bandwidthVal->text().toInt();
    int val = bandwidth%2 ? bandwidth : bandwidth-1;
    ui->spinBox->setValue(val);
    on_setter_clicked();
}
