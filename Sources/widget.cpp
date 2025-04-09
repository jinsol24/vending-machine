#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    money = 0;  // 돈 초기화
    updateButtons();  // 초기 버튼 상태 설정
}

Widget::~Widget()
{
    delete ui;
}

// 버튼 상태 업데이트
void Widget::updateButtons() {
    ui->pbTea->setEnabled(money >= 150);
    ui->pbJuice->setEnabled(money >= 200);
    ui->pbCoffee->setEnabled(money >= 100);
}

// 돈 변경 + 화면 표시 + 버튼 상태 업데이트
void Widget::changeMoney(int diff) {
    money += diff;
    ui->lcdNumber->display(money);
    updateButtons();
}



// 잔돈 반환 멘트 생성
QString Widget::calculateChange(int money) {
    int coin500 = money / 500;
    money %= 500;
    int coin100 = money / 100;
    money %= 100;
    int coin50 = money / 50;
    money %= 50;
    int coin10 = money / 10;
    money %= 10;

    return QString("500원 %4개, 100원 %1개, 50원 %2개, 10원 %3개 반환됩니다.")
        .arg(coin100)
        .arg(coin50)
        .arg(coin10)
        .arg(coin500);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox::information(this, "잔돈 반환", calculateChange(money));
    changeMoney(-money);
    // money = 0;
    // ui->lcdNumber->display(money);
    // updateButtons();
}

void Widget::on_pbTea_clicked()
{
    assert(money >= 150) ;
    changeMoney(-150);
}

void Widget::on_pbJuice_clicked()
{
    assert(money >= 200);
    changeMoney(-200);
}

void Widget::on_pbCoffee_clicked()
{
    assert(money >= 100);
    changeMoney(-100);
}
