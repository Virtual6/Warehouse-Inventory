//#ifndef MAINWINDOW_H
//#define MAINWINDOW_H

//#include <QMainWindow>

//namespace Ui {
//class MainWindow;
//}

//class MainWindow : public QMainWindow
//{
//    Q_OBJECT

//public:
//    explicit MainWindow(QWidget *parent = 0);
//    ~MainWindow();

//private:
//    Ui::MainWindow *ui;
//};

//#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_login_3_clicked();

    void on_checkBox_robot_stateChanged(int arg1);

    void on_actionExit_triggered();

    void on_actionInfo_triggered();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_9_clicked();

    int SearchMemberName(QString SearchMemberName);

    int SearchMemberId(QString searchId);

    void on_read_days_button_clicked();

    void on_print_receipt_btn_clicked();

    bool Search_Index_Days_Items(int index, int dayChosen, QString  searchIdPrint,
                                 double &totalPurchase, int &totalQuantity);

    void on_total_sales_button_clicked();

    QString CalculateSales(int begin, int end);

    void on_Find_Qunatity_Sold_Items_button_clicked();

    void SearchNameQuantity(int begin, int end, QString searchItemName, int &indexFound,
                            double &totalSoldQuantity, int &totalQuantity);

    void UpdateWareHouseFiles();

    void on_Add_items_Button_clicked();

    void AddToTheDaysItemsList(int extendDaysList, QString itemName,
                               QString memberId, QString itemPrice,
                               QString itemQuantity, QString dateOfThePurchase);

    void UpdateDaysList(QString txtFile, int beginWrite, int endWrite);

    void on_pushButton_delete_item_clicked();

    int SearchItemName(QString itemName);

    bool ItemHasBeenDeleted(QString itemName);

    void on_button_change_members_membership1_clicked();

    void on_actionInformation_triggered();

private:

    const int CHANGE_ACCOUNT_PRICE = 350;
    const int TAB_COUNT = 13;
    Ui::MainWindow *ui;
    QVector<QString>members;
    QVector<QString>type;
    QVector<QString>date;
    QVector<QString>ids;

    QVector<QString>purchaseDate;
    QVector<QString>purchaseMemberId;
    QVector<QString>purchaseItemName;
    QVector<QString>purchasePrice;
    QVector<QString>purchaseQuantity;
    QVector<QString>deletedItems;

    int cpd1 = 0;  // purchaseCountDay1
    int cpd2 = 0;
    int cpd3 = 0;
    int cpd4 = 0;
    int cpd5 = 0;

};

#endif // MAINWINDOW_H
