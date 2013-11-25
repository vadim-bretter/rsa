#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BigIntegerLibrary.hh"
#include "BigIntegerUtils.hh"
#include <string>
#include <fstream>
#include <QTime>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include "algoritm.h"

using namespace std;

void MainWindow::openfil1()
{
    QString str = QFileDialog::getOpenFileName( this, QString::fromLocal8Bit( "������� �������� ����" ) );
   // if ( !str.isEmpty() )
    {
        ui->lineopen->setText(str);
        ui->savebut->setVisible(true);
        ui->linesave->setVisible(true);

   }
        QFile FN(str);
        FN.open(QIODevice::ReadOnly);
    qint64 L;
    L = FN.size();
    QByteArray m;
    m = FN.readAll();
    ui->indan->setText(m);
}

void MainWindow::openfil2()
{
    QString str = QFileDialog::getSaveFileName( this, QString::fromLocal8Bit( "������� �������������� ����" ) );
    if ( !str.isEmpty() )
    {
        ui->linesave->setText(str);
    }
}
void MainWindow::openkey1()
{
    QString str = QFileDialog::getOpenFileName( this, QString::fromLocal8Bit( "������� �������� ����" ) );
    if ( !str.isEmpty() )
    {
        ui->otkey->setText(str);


   }
}
void MainWindow::openkey2()
{
    QString str = QFileDialog::getOpenFileName( this, QString::fromLocal8Bit( "������� �������� ����" ) );
    if ( !str.isEmpty() )
    {
        ui->zakkey->setText(str);

   }
}
void MainWindow::saven()
{
    QString str = QFileDialog::getOpenFileName( this, QString::fromLocal8Bit( "������� �������� ����" ) );
    if ( !str.isEmpty() )
    {
        ui->linen->setText(str);


   }
}

void MainWindow::display()
{
    ui->openbut->setVisible( true );
    ui->lineopen->setVisible( true );
}


    // **************************************************************************
    void MainWindow:: vivod()
    {
        start();
    // ����� ���������� �� �����
    ui->lineEdit_nBob->setText( bigIntegerToString(nB).c_str() );
    ui->lineEdit_eBob->setText(bigIntegerToString( eB ).c_str() );
    ui->lineEdit_meAlisa->setText(bigIntegerToString(meA).c_str() );
    ui->lineEdit_fiBob->setText( bigIntegerToString(fiB).c_str() );
    ui->lineEdit_dBob->setText( bigIntegerToString(dB).c_str() );
}



 // ������������� � ��������� ������� ����������
void MainWindow::Inicialization()
{
    if ( ui->lineEdit_pBob->text().isEmpty() ) generate_p();
    if ( ui->lineEdit_qBob->text().isEmpty() ) generate_q();
    if ( ui->lineEdit_eBob->text().isEmpty() ) generate_e();

}


bool isPrimitive( BigInteger p )
{
    for (BigInteger i = 2; i <= p/2+1; i++)
        if (p % i == 0)
            return false;

    return true;
}

//BigInteger generatep( BigInteger n )
BigInteger generatep(int n)
{
 //  string str = bigIntegerToString(n);
   // unsigned int strsize = str.size();
    unsigned int strsize = n;
    BigInteger p;
    string str =  bigIntegerToString(p);


    do
    {
        str.clear();
        for ( unsigned int i = 0; i < strsize ; i++ ) {
            str += rand() % 10 + '0';
        }
        p = stringToBigInteger(str);
//        p %= n;
    }
    while ( !isPrimitive( p ) );

    return p;
}


void MainWindow::generate_p()
{
    if (ui->lineEdit_pBob->text().isEmpty()) {
        string str;
     //   BigInteger p = generatep( stringToBigInteger(ui->dlinkey->text().toStdString()) );
       BigInteger p = generatep(ui->dlinkey->text().toInt());
        ui->lineEdit_pBob->setText( bigIntegerToString(p).c_str());
    }
}

void MainWindow::generate_q()
{
    if (ui->lineEdit_qBob->text().isEmpty()) {
        string str;
    //    BigInteger q = generatep( stringToBigInteger(ui->dlinkey->text().toStdString()) );
        BigInteger q = generatep(ui->dlinkey->text().toInt());
        ui->lineEdit_qBob->setText( bigIntegerToString(q).c_str());
    }
}

void MainWindow::generate_n() {
 /*  if ( ui->lineEdit_pBob->text().isEmpty() ) generate_p();
    if ( ui->lineEdit_qBob->text().isEmpty() ) generate_q();*/
    BigInteger p, q, n;
    string str;
    p = stringToBigInteger( ui->lineEdit_pBob->text().toStdString() );
    q = stringToBigInteger( ui->lineEdit_pBob->text().toStdString() );
    n = p * q;
    ui->lineEdit_nBob->setText( bigIntegerToString(n).c_str());
}

void MainWindow::generate_fi() {
   // if ( ui->lineEdit_pBob->text().isEmpty() ) generate_p();
    //if ( ui->lineEdit_qBob->text().isEmpty() ) generate_q();
    BigInteger p, q, fi;
    string str;
    p = stringToBigInteger( ui->lineEdit_pBob->text().toStdString() );
    q = stringToBigInteger( ui->lineEdit_pBob->text().toStdString() );
    fi = ( p - 1 ) * ( q - 1 );
    ui->lineEdit_fiBob->setText( bigIntegerToString(fi).c_str());
}

void MainWindow::generate_e() {
    if ( ui->lineEdit_fiBob->text().isEmpty() ) generate_fi();
    BigInteger fi, e;
    string str;
    fi =stringToBigInteger( ui->lineEdit_pBob->text().toStdString() );
//    e = generatep( stringToBigInteger(ui->dlinkey->text().toStdString())) ;
    if (ui->lineEdit_eBob->text().isEmpty()) {
        e = generatep(ui->dlinkey->text().toInt()) ;
        ui->lineEdit_eBob->setText( bigIntegerToString(e).c_str());
    }
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    display();
    connect(ui->pushn, SIGNAL( clicked() ), SLOT( saven() ));
    connect(ui->key1, SIGNAL( clicked() ), SLOT( openkey1() ));
    connect(ui->key2, SIGNAL( clicked() ), SLOT( openkey2() ));
    connect(ui->openbut, SIGNAL( clicked() ), SLOT( openfil1() ));
    connect(ui->savebut, SIGNAL( clicked() ), SLOT( openfil2() ));
    connect(ui->pushButton_Start, SIGNAL( clicked() ), SLOT( vivod() ));
    connect(ui->pushButton_pBob, SIGNAL( clicked() ), SLOT( generate_p() ));
    connect(ui->pushButton_qBob, SIGNAL( clicked() ), SLOT( generate_q() ));
    connect(ui->pushButton_eBob, SIGNAL( clicked() ), SLOT( generate_e() ));

    // ������������� ���������� ��������� �����
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
