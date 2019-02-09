#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void coordination(QVector<double>&, QVector<double>&);
    void sinPlotter();
    double oddSigma(double end, float t);
    void x_y_setter(QVector<double> &x, QVector<double> &y, int xLength, double k);
    void widgetCleaner();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_setter_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_setter_2_clicked();

private:
    Ui::MainWindow *ui;
    double A;
    double F;
    double phi;
    int graphs;
};

#endif // MAINWINDOW_H
