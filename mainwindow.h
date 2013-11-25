#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void display();    

private slots:
    void vivod();
    void saven();
    void openfil1();
    void openfil2();
    void openkey1();
    void openkey2();
    void Inicialization(); // инициализация и генерация входных параметров
    void generate_p();
    void generate_q();
    void generate_n();
    void generate_fi();
    void generate_e();

};

#endif // MAINWINDOW_H
