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

// [조언] 500원 추가가
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
 기
    // if(money >= 150) {
    //     changeMoney(-150);
    // } else {
    //     QMessageBox::warning(this, "경고", "잔액이 부족합니다.");
    // }
}

void Widget::on_pbJuice_clicked()
{
    if(money >= 200) {
        changeMoney(-200);
    } else {
        QMessageBox::warning(this, "경고", "잔액이 부족합니다.");
    }
}

void Widget::on_pbCoffee_clicked()
{
    if(money >= 100) {
        changeMoney(-100);
    } else {
        QMessageBox::warning(this, "경고", "잔액이 부족합니다.");
    }
}
