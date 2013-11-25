#include "algoritm.h"
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

void Start()
{
    Inicialization(); // ������������� � ��������� ������� ����������

    generate_p();
    generate_q();
    generate_n();
    generate_fi();
    generate_e();
    string str;

    // ������������ ����������
    BigInteger n,e, nB, eB, mA, meA, me, fiB, dB, mB, pB, qB;


    // **************************************************************************

    // �������� ������� p � q
    pB = stringToBigInteger(ui->lineEdit_pBob->text().toStdString());  // ������� �����
    qB = stringToBigInteger( ui->lineEdit_qBob->text().toStdString() );  // ������� �����
    //���������
    nB = pB * qB;                   // n = p * q
    fiB = ( pB - 1) * ( qB - 1 );   // fi (������� ������)
    // �������� e (�������� ����������)
    eB = stringToBigInteger(ui->lineEdit_eBob->text().toStdString() );
    //��������� d = e^-1 (�������� ����������)
    BigInteger temp_r, temp_s, g;
    extendedEuclidean( eB, fiB, g, temp_r, temp_s);
    dB = temp_r;

    // ��������� n � e
    n = nB.getMagnitude();
    e = eB.getMagnitude();
    //  �������� ��������� m
    mA= stringToBigInteger( ui->indan->toPlainText().toStdString() );
    //  ������������� ���������
    meA = modexp(mA, e.getMagnitude(), n.getMagnitude() );
    //��������� ������������� ��������� me
    me = meA;
    QFile FN(ui->linesave->text());
    FN.open(QIODevice::WriteOnly);
QByteArray M = bigIntegerToString(me).c_str();
FN.write(M);
    // ������������� ���������
    mB = modexp( meA, dB.getMagnitude(), n.getMagnitude() );
    // ������ ������ � ����
    QFile open_key_file(ui->otkey->text());
    open_key_file.open(QIODevice::WriteOnly);
    QFile sec_key_file(ui->zakkey->text());
    sec_key_file.open(QIODevice::WriteOnly);
    QFile filen(ui->linen->text());
    filen.open(QIODevice::WriteOnly);

    open_key_file.write(QByteArray(bigIntegerToString( eB ).c_str()));

    //open_key_file.write(QByteArray(bigIntegerToString( nB ).c_str()));
    open_key_file.close();
    sec_key_file.write(QByteArray(bigIntegerToString( dB ).c_str()));

    //sec_key_file.write(QByteArray(bigIntegerToString( nB ).c_str()));
    sec_key_file.close();
    filen.write(QByteArray(bigIntegerToString( nB ).c_str()));


}
