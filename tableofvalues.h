#ifndef TABLEOFVALUES_H
#define TABLEOFVALUES_H

#include <QDialog>
#include "parse_str.h"
#include "calculate.h"
#include "deque.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QMessageBox>
#include <iostream>
namespace Ui {
class TableOfValues;
}

class TableOfValues : public QDialog
{
    Q_OBJECT

public:
    explicit TableOfValues(QWidget *parent = nullptr);
    ~TableOfValues();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    void calculateTable(int count, bool options); // строит таблицу
    void clearWindow(); // очищает окно и поля ввода
    void SetAtributes(); // устанавливает аттрибуты

    Ui::TableOfValues *ui;

    QStandardItemModel *model;

    char str[50];

    bool ok_lg, // ставится в 1, если вернулось корректное значение левой границы
         ok_rg, // ставится в 1, если вернулось корректное значение правой границы
         ok_count, // ставится в 1, если вернулось корректное количества записей
         radioButtonChecked_1, // ставится в 1, если нажат radio_button_1
         radioButtonChecked_2; // ставится в 1, если нажат radio_button_2

    Deque *head,
          *tail;

    double xmin, // левая граница
           xmax; // правая граница

    int count;
};

#endif // TABLEOFVALUES_H
