#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QPixmap>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // This will lock the tabs in the widget bar
    // till the right username and password has been entered
    for(int i = 1; i < TAB_COUNT; i++)
    {
        ui->tabWidget->setTabEnabled(i, false);
    }
    // Sets the background window image

     QPixmap bkgnd("D:/Qt Project1/Project1/User Selection/p170vftkpc10an1fj11qc8283qo9-details.jpg");
    // QPixmap bkgnd("D:/Qt Project1/Project1/User Selection/p170vftkpc10an1fj11qc8283qo9-details.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    // Sets the login page image
    QPixmap pix(":/rec/User Selection/user-login-icon-14.png");

    int width  = ui->label_pic->width();
    int length = ui->label_pic->height();

    ui->label_pic->setPixmap(pix.scaled(width, length, Qt::KeepAspectRatio));

    QFile myFile("D:/Qt Project1/Project1/warehouse.txt");

    // Chekcs if the file has been opened
    if(!myFile.open(QFile::ReadWrite | QFile::Text))
    {
        // following message will be diplayed if the file did not open
        QMessageBox::warning(this, "Error File", "Can\'t open the file");
        return;
    }

    QTextStream input(&myFile);

    int index = 0;

    // Checks if it is not at the end of the input file and
    // in keep reading the members info into the vector
    while(!input.atEnd())
    {
        members.push_back(input.readLine());
        ids.push_back(input.readLine());
        type.push_back(input.readLine());
        date.push_back(input.readLine());

        index++;
    }

    myFile.close();

    // Opens the files for 5 days that the customers did their shopping
    // the files have been opened from the recourse file
    QFile dayOne("D:/Qt Project1/Project1/day1.txt");
    QFile dayTwo("D:/Qt Project1/Project1/day2.txt");
    QFile dayThree("D:/Qt Project1/Project1/day3.txt");
    QFile dayFour("D:/Qt Project1/Project1/day4.txt");
    QFile dayFive("D:/Qt Project1/Project1/day5.txt");

    // Opens the files for deleted items to add
    QFile deleteList("D:/Qt Project1/Project1/deletedItems.txt");

    // Declares the objects for the days to read the data from the files
    QTextStream inputOne(&dayOne);
    QTextStream inputTwo(&dayTwo);
    QTextStream inputThree(&dayThree);
    QTextStream inputFour(&dayFour);
    QTextStream inputFive(&dayFive);

    // Declares the objects for the days to read the data from the files
    QTextStream deleteFile(&deleteList);

    // Chekcs if the file has been opened
    if(!dayOne.open(QFile::ReadWrite | QFile::Text))
    {
        // following message will be diplayed if the file did not open
        QMessageBox::warning(this, "Error File", "2Can\'t open the file");
        return;
    }

    // Reads all the data from day1 file and stores their valuers
    // in the follwing vectores which are the purchase date,
    // item name, item price, and quantity of the items

    int purchaseDayCount = 0;

    while(!inputOne.atEnd())
    {
        purchaseDate.push_back(inputOne.readLine());
        purchaseMemberId.push_back(inputOne.readLine());
        purchaseItemName.push_back(inputOne.readLine());
        purchasePrice.push_back(inputOne.readLine());
        purchaseQuantity.push_back(inputOne.readLine());

        qDebug() << purchaseQuantity[purchaseDayCount];

        purchaseDayCount++;
        cpd1++;
    }

    // Chekcs if the file has been opened
    if(!dayTwo.open(QFile::ReadWrite | QFile::Text))
    {
        // following message will be diplayed if the file did not open
        QMessageBox::warning(this, "Error File", "3Can\'t open the file");
        return;
    }

    // Reads all the data from day2 file and stores their valuers
    // in the follwing vectores which are the purchase date,
    // item name, item price, and quantity of the items

    while(!inputTwo.atEnd())
    {
        purchaseDate.push_back(inputTwo.readLine());
        purchaseMemberId.push_back(inputTwo.readLine());
        purchaseItemName.push_back(inputTwo.readLine());
        purchasePrice.push_back(inputTwo.readLine());
        purchaseQuantity.push_back(inputTwo.readLine());
        qDebug() << purchaseQuantity[purchaseDayCount];

        cpd2++;
        purchaseDayCount++;
    }

    // Chekcs if the file has been opened
    if(!dayThree.open(QFile::ReadWrite | QFile::Text))
    {
        // following message will be diplayed if the file did not open
        QMessageBox::warning(this, "Error File", "4Can\'t open the file");
        return;
    }

    // Reads all the data from day3 file and stores their valuers
    // in the follwing vectores which are the purchase date,
    // item name, item price, and quantity of the items

    while(!inputThree.atEnd())
    {
        purchaseDate.push_back(inputThree.readLine());
        purchaseMemberId.push_back(inputThree.readLine());
        purchaseItemName.push_back(inputThree.readLine());
        purchasePrice.push_back(inputThree.readLine());
        purchaseQuantity.push_back(inputThree.readLine());

        qDebug() << purchaseQuantity[purchaseDayCount];

        cpd3++;
        purchaseDayCount++;
    }

    // Chekcs if the file has been opened
    if(!dayFour.open(QFile::ReadWrite | QFile::Text))
    {
        // following message will be diplayed if the file did not open
        QMessageBox::warning(this, "Error File", "5Can\'t open the file");
        return;
    }

    // Reads all the data from day4 file and stores their valuers
    // in the follwing vectores which are the purchase date,
    // item name, item price, and quantity of the items

    while(!inputFour.atEnd())
    {
        purchaseDate.push_back(inputFour.readLine());
        purchaseMemberId.push_back(inputFour.readLine());
        purchaseItemName.push_back(inputFour.readLine());
        purchasePrice.push_back(inputFour.readLine());
        purchaseQuantity.push_back(inputFour.readLine());
        qDebug() << purchaseQuantity[purchaseDayCount];

        cpd4++;
        purchaseDayCount++;
    }

    // Chekcs if the file has been opened
    if(!dayFive.open(QFile::ReadWrite | QFile::Text))
    {
        // following message will be diplayed if the file did not open
        QMessageBox::warning(this, "Error File", "6Can\'t open the file");
        return;
    }

    // Reads all the data from day5 file and stores their valuers
    // in the follwing vectores which are the purchase date,
    // item name, item price, and quantity of the items

    while(!inputFive.atEnd())
    {
        purchaseDate.push_back(inputFive.readLine());
        purchaseMemberId.push_back(inputFive.readLine());
        purchaseItemName.push_back(inputFive.readLine());
        purchasePrice.push_back(inputFive.readLine());
        purchaseQuantity.push_back(inputFive.readLine());
        qDebug() << purchaseQuantity[purchaseDayCount];

        cpd5++;
        purchaseDayCount++;
    }

    // Chekcs if the file has been opened
    if(!deleteList.open(QFile::ReadWrite | QFile::Text))
    {
        // following message will be diplayed if the file did not open
        QMessageBox::warning(this, "Error File", "7Can\'t open the file");
        return;
    }

    while(!deleteFile.atEnd())
    {
        deletedItems.push_back(deleteFile.readLine());
    }

    qDebug() << purchaseQuantity.capacity();

    // Closes the files opened for the days
    dayOne.close();
    dayTwo.close();
    dayThree.close();
    dayFour.close();
    dayFive.close();

}

MainWindow::~MainWindow()
{
    delete ui;
}

/***************************************************
 * Function : Login Window
 * ************************************************/
// This function asks the user to enter the correct username and password
// to be able to use the application ---- Login Button
void MainWindow::on_pushButton_login_3_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    // Check if the security box has been checked
    if(ui->checkBox_robot->isChecked())
    {
        // Checks if the user and password are correct or not
        if(username != "username" && password != "password")
        {
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();

            ui->statusBar->showMessage("Username and Password are NOT correct", 5000);
        }
        else
        {
            ui->statusBar->showMessage("Username and Password are correct", 5000);

            // Unlock the tabs if the username and password are correct
            for(int i = 1; i < TAB_COUNT; i++)
            {
                ui->tabWidget->setTabEnabled(i, true);
            }
        }
    }
    else
    {
        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();

        QMessageBox::warning(this, "Security Check", "Check the box");
    }
}

/***************************************************
 * Function : Security Check - Not a Robot
 * ************************************************/
// Checks if the user unchecked the security box and it will a warning message
void MainWindow::on_checkBox_robot_stateChanged(int arg1)
{
    if(!arg1)
    {
        QMessageBox::warning(this, "Security Check", "Check the box");
    }
}

/***************************************************
 * Function : Exit Program
 * ************************************************/
// Quits the application is the exit tab has been selected
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

// Shows the program information if the information tab has been selected
void MainWindow::on_actionInformation_triggered()
{
    QMessageBox::information(this, "Program Info", "Bulk club Program");
}
/***************************************************
 * Function : Read Memeber Information
 * ************************************************/
// Read into file button
// It will read the file into text edit if the button has been selected
void MainWindow::on_pushButton_7_clicked()
{
    ui->textEdit->clear();

    // Opens the file from the recource folder
    QFile myFile("D:/Qt Project1/Project1/warehouse.txt");

    // Chekcs if the file has been opened
    if(!myFile.open(QFile::ReadWrite | QFile::Text))
    {
        // following message will be diplayed if the file did not open
        QMessageBox::warning(this, "Error File", "8Can\'t open the file");
        return;
    }

    // reads the entire input file into the text edit widget
    QTextStream input(&myFile);
    QString text = input.readAll();
    ui->textEdit->setPlainText(text);
    input >> text;

    myFile.close();
}

/***************************************************
 * Function : Search Memeber
 * ************************************************/
void MainWindow::on_pushButton_clicked()
{
    // Saves the text entered by the user to search in the line text
    QString searchName = ui->search_Name->text();

    int index = SearchMemberName(searchName);

    if(index < members.size())
    {
        ui->label_22->setText("Member Name");
        ui->label_23->setText("Member Id");
        ui->label_24->setText("Member Date");
        ui->label_25->setText("Member Type");

        ui->search_memberName_result->setText(members[index]);
        ui->search_memberId_result->setText(ids[index]);
        ui->search_memberType_result->setText(date[index]);
        ui->search_memberDate_result->setText(type[index]);
    }
    else
    {
       QMessageBox::warning(this, "Member Search", "Member Not Found!");
    }
}


/***************************************************
 * Function : Change Member's membership
 * ************************************************/
void MainWindow::on_button_change_members_membership1_clicked()
{
    ui->change_membership_search_name_label->setText("Search Name");
    QString searchName = ui->change_membership_search_name_lineEdit->text();

    int indexFound = SearchMemberName(searchName);

    if(indexFound < members.size())
    {
        if(ui->radioButton_change_to_regular)
        {
            type[indexFound] == "Regular";
        }
        else if(ui->radioButton_change_to_executive)
        {
            type[indexFound] == "Executive";
        }
    }
    else if(indexFound > members.size())
    {
        QMessageBox::warning(this, "Input Error", "Memeber was NOT Found.");
    }
}
/***************************************************
 * Function : Adding Members
 * ************************************************/
void MainWindow::on_pushButton_3_clicked()
{
    // Reads the following information to the designated variables
    QString newMember = ui->lineEdit_3->text();
    QString newId     = ui->lineEdit_4->text();
    QString newDate   = ui->lineEdit_14->text();

    int indexNameFound = SearchMemberName(newMember);
    int indexIdFound   = SearchMemberId(newId);

    if(indexNameFound < members.length())
    {
        QMessageBox::warning(this, "Input Error", "Name Entered Already exists in the List!");
    }
    else if(indexIdFound < ids.length())
    {
        QMessageBox::warning(this, "Input Error", "ID Entered Already exists in the List!");
    }
    else
    {
        // Checks if the user chooses the Excutive membership
        // or the regular
        if(ui->radioButton->isChecked())
        {
            type.push_back("Executive");

            ui->added_member_type_lineEdit->setText("Execuive");

        }
        else if(ui->radioButton_2->isChecked())
        {
            type.push_back("Regular");

            ui->added_member_type_lineEdit->setText("Regular");

        }
        members.push_back(newMember);
        ids.push_back(newId);
        date.push_back(newDate);

        ui->added_member_name_label->setText("Member Name");
        ui->added_member_id_label->setText("Member Id");
        ui->added_member_date_label->setText("Member Date");
        ui->added_member_type_label->setText("Member Type");

        ui->added_member_name_lineEdit->setText(newMember);
        ui->added_member_id_lineEdit->setText(newId);
        ui->added_member_date_lineEdit_2->setText(newDate);

        ui->member_added_label->setText("Memeber has been Added.");

        UpdateWareHouseFiles();
    }
}

/***************************************************
 * Function : Update warehouse files
 * ************************************************/
void MainWindow::UpdateWareHouseFiles()
{
    QFile myFile("D:/Qt Project1/Project1/warehouse.txt");

    // Chekcs if the file has been opened
    if(!myFile.open(QFile::ReadWrite | QFile::Text))
    {
        // following message will be diplayed if the file did not open
        QMessageBox::warning(this, "Error File", "9Can\'t open the file");
        return;
    }

    QTextStream out(&myFile);

    for(int index = 0; index < members.length(); index++)
    {
        out << members[index] << '\n';
        out << ids[index]     << '\n';
        out << date[index]    << '\n';
        out << type[index]    << '\n';
    }

    int size = members.size();
    for(int i = 0; i < size; i++)
    {
        qDebug() << members[i] << type[i];
    }

    myFile.close();
}

/***************************************************
 * Function : Deleting Members
 * ************************************************/
void MainWindow::on_pushButton_9_clicked()
{
    // CLears all the label the next time that a name is entered
    // to remove the information of the previous members that
    // were deleted from the list
    ui->delete_label_1->clear();
    ui->delete_label_2->clear();
    ui->delete_label_3->clear();
    ui->delete_label_4->clear();

    ui->delete_1->clear();
    ui->delete_2->clear();
    ui->delete_3->clear();
    ui->delete_4->clear();
    ui->delete_result->clear();

    QString deleteName = ui->lineEdit_5->text();

    int index = SearchMemberName(deleteName);

    if(index < members.size())
    {
        ui->delete_label_1->setText("Member Name");
        ui->delete_label_2->setText("Member Id");
        ui->delete_label_3->setText("Member Date");
        ui->delete_label_4->setText("Member Type");

        ui->delete_1->setText(members[index]);
        ui->delete_2->setText(ids[index]);
        ui->delete_3->setText(date[index]);
        ui->delete_4->setText(type[index]);

        members.erase(members.begin()+index);
        ids.erase(ids.begin() +index);
        type.erase(type.begin()+index);
        date.erase(date.begin()+index);

        ui->delete_result->setText("Member has been Deleted");

        UpdateWareHouseFiles();
    }
    else
    {
        QMessageBox::warning(this, "Delete Memeber", "Member NOT Found!");
    }
}

/***************************************************
 * Function : Search Memeber Name index Found
 * ************************************************/
// This function searches for the name of the member and
// returns the index of the member found
int MainWindow::SearchMemberName(QString searchName)
{
    int index = 0;
    bool found = false;
    int memberListSize = members.size();

    // This loop searches for the name entered by the user in the vector and
    // returns the index if found and shows a warning message if not found
    while(!found && index < memberListSize)
    {
        if(searchName == members[index])
        {
            found = true;
        }
        else
        {
            index++;
        }
    }
    return index;
}

/***************************************************
 * Function : Search Memeber Id index Found
 * ************************************************/
// This function searches for the ID of the member and
// returns the index of the member found
int MainWindow::SearchMemberId(QString searchId)
{
    int index = 0;
    bool found = false;
    int memberListSize = ids.size();

    // This loop searches for the ID entered by the user in the vector and
    // returns the index if found and shows a warning message if not found
    while(!found && index < memberListSize)
    {
        if(searchId == ids[index])
        {
            found = true;
        }
        else
        {
            index++;
        }
    }
    return index;
}


/***************************************************
 * Function : Read Inventory --- Purchased Items
 * ************************************************/
// This Function reads the inventory for the members
// to a file according to the day they select
void MainWindow::on_read_days_button_clicked()
{
    if(ui->day_One_radion_btn->isChecked())
    {
        // Opens the file from the recource folder
        QFile dayOne("D:/Qt Project1/Project1/day1.txt");

        // Chekcs if the file has been opened
        if(!dayOne.open(QFile::ReadWrite | QFile::Text))
        {
            // following message will be diplayed if the file did not open
            QMessageBox::warning(this, "Error File", "10Can\'t open the file");
            return;
        }
        // reads the entire input file into the text edit widget
        QTextStream inputOne(&dayOne);
        QString text = inputOne.readAll();
        ui->read_days_Inventory_text->setPlainText(text);
        inputOne >> text;
        dayOne.close();
    }
    else if(ui->day_Two_radion_btn->isChecked())
    {
        // Opens the file from the recource folder
        QFile dayTwo("D:/Qt Project1/Project1/day2.txt");

        // Chekcs if the file has been opened
        if(!dayTwo.open(QFile::ReadWrite | QFile::Text))
        {
            // following message will be diplayed if the file did not open
            QMessageBox::warning(this, "Error File", "11Can\'t open the file");
            return;
        }
        // reads the entire input file into the text edit widget
        QTextStream inputTwo(&dayTwo);
        QString text = inputTwo.readAll();
        ui->read_days_Inventory_text->setPlainText(text);
        inputTwo >> text;
        dayTwo.close();
    }
    else if(ui->day_Three_radion_btn->isChecked())
    {
        // Opens the file from the recource folder
        QFile dayThree("D:/Qt Project1/Project1/day3.txt");

        // Chekcs if the file has been opened
        if(!dayThree.open(QFile::ReadWrite | QFile::Text))
        {
            // following message will be diplayed if the file did not open
            QMessageBox::warning(this, "Error File", "12Can\'t open the file");
            return;
        }
        // reads the entire input file into the text edit widget
        QTextStream inputThree(&dayThree);
        QString text = inputThree.readAll();
        ui->read_days_Inventory_text->setPlainText(text);
        inputThree >> text;
        dayThree.close();
    }
    else if(ui->day_Four_radion_btn_->isChecked())
    {
        // Opens the file from the recource folder
        QFile dayFour("D:/Qt Project1/Project1/day4.txt");

        // Chekcs if the file has been opened
        if(!dayFour.open(QFile::ReadWrite | QFile::Text))
        {
            // following message will be diplayed if the file did not open
            QMessageBox::warning(this, "Error File", "13Can\'t open the file");
            return;
        }
        // reads the entire input file into the text edit widget
        QTextStream inputFour(&dayFour);
        QString text = inputFour.readAll();
        ui->read_days_Inventory_text->setPlainText(text);
        inputFour >> text;
        dayFour.close();
    }
    else if(ui->day_Five_radion_btn->isChecked())
    {
        // Opens the file from the recource folder
        QFile dayFive("D:/Qt Project1/Project1/day5.txt");

        // Chekcs if the file has been opened
        if(!dayFive.open(QFile::ReadWrite | QFile::Text))
        {
            // following message will be diplayed if the file did not open
            QMessageBox::warning(this, "Error File", "14Can\'t open the file");
            return;
        }
        // reads the entire input file into the text edit widget
        QTextStream inputFive(&dayFive);
        QString text = inputFive.readAll();
        ui->read_days_Inventory_text->setPlainText(text);
        inputFive >> text;
        dayFive.close();
    }
    else if(ui->radioButton_deleted_list->isChecked())
    {
        // Opens the file from the recource folder
        QFile deletedList("D:/Qt Project1/Project1/deletedItems.txt");

        // Chekcs if the file has been opened
        if(!deletedList.open(QFile::ReadWrite | QFile::Text))
        {
            // following message will be diplayed if the file did not open
            QMessageBox::warning(this, "Error File", "15Can\'t open the file");
            return;
        }
        // reads the entire input file into the text edit widget
        QTextStream inputDeleted(&deletedList);
        QString text = inputDeleted.readAll();
        ui->read_days_Inventory_text->setPlainText(text);
        inputDeleted >> text;
        deletedList.close();
    }
    else
    {
        QMessageBox::warning(this, "Select File", "Choose the File you would like to output");
    }
}


/***************************************************
 * Function : Search Index Days Items
 * ************************************************/
bool MainWindow::Search_Index_Days_Items(int index, int dayChosen, QString  searchIdPrint,
                                         double &totalPurchase, int &totalQuantity)
{

    ui->print_receipt->clear();

    ui->reciept_member_name->clear();
    ui->receipt_member_id->clear();
    ui->receipt_member_date->clear();
    ui->receipt_member_type->clear();

    ui->receipt_lineEdit_name->clear();
    ui->receipt_lineEdit_Id->clear();
    ui->receipt_lineEdit_date->clear();
    ui->receipt_lineEdit_type->clear();

    ui->total_Items_bought_label->clear();
    ui->total_quantity_items_label->clear();
    ui->total_Items_bought_lineEdit->clear();
    ui->total_quantity_items_lineEdit->clear();

    ui->change_membership_line_edit->clear();
    ui->change_membership_line_edit_2->clear();

    ui->rebate_label->clear();
    ui->rebate_lineEdit->clear();
    bool found = false;

    while(index < dayChosen)
    {
        if(searchIdPrint == purchaseMemberId[index])
        {
            totalPurchase += (purchasePrice[index].toDouble() * purchaseQuantity[index].toInt());
            totalQuantity += purchaseQuantity[index].toInt();

            ui->print_receipt->appendPlainText(purchaseItemName[index]);
            ui->print_receipt->appendPlainText(purchaseDate[index]);
            ui->print_receipt->appendPlainText(purchasePrice[index]);
            ui->print_receipt->appendPlainText(purchaseQuantity[index]);
            found = true;
        }
        index++;
    }
    return found;
}

/***************************************************
 * Function : Print Receipt
 * ************************************************/
void MainWindow::on_print_receipt_btn_clicked()
{
    ui->print_receipt->clear();

    ui->reciept_member_name->clear();
    ui->receipt_member_id->clear();
    ui->receipt_member_date->clear();
    ui->receipt_member_type->clear();

    ui->receipt_lineEdit_name->clear();
    ui->receipt_lineEdit_Id->clear();
    ui->receipt_lineEdit_date->clear();
    ui->receipt_lineEdit_type->clear();

    ui->total_Items_bought_label->clear();
    ui->total_quantity_items_label->clear();
    ui->total_Items_bought_lineEdit->clear();
    ui->total_quantity_items_lineEdit->clear();

    ui->change_membership_line_edit->clear();
    ui->change_membership_line_edit_2->clear();

    ui->rebate_label->clear();
    ui->rebate_lineEdit->clear();
    ui->print_receipt->clear();

    QString searchIdPrint = ui->search_id_lineEdit->text();

    double totalPurchase = 0;
    int    totalQuantity = 0;
    bool   allDaysPurchase = false;
    bool   found;
    int    index = 0;

    if(ui->print_day_one_receipt_btn->isChecked())
    {
        qDebug() << "purchase day1 is: " << cpd1;

        found  = Search_Index_Days_Items(index, cpd1, searchIdPrint,
                                         totalPurchase, totalQuantity);
    }
    else if(ui->print_day_Two_receipt_btn_2->isChecked())
    {
        qDebug() << "purchase day2 is: " << cpd2;

        found  = Search_Index_Days_Items(cpd2, cpd2 + cpd1, searchIdPrint,
                                         totalPurchase, totalQuantity);
    }
    else if(ui->print_day_Three_receipt_btn->isChecked())
    {
        qDebug() << "purchase day3 is: " << cpd3;

        found  = Search_Index_Days_Items(cpd2 + cpd3, cpd3 + cpd2 + cpd1, searchIdPrint,
                                         totalPurchase, totalQuantity);
    }
    else if(ui->print_day_Four_receipt_btn->isChecked())
    {
        qDebug() << "purchase day4 is: " << cpd4;

        found  = Search_Index_Days_Items(cpd3 + cpd2 + cpd1 ,
                                         cpd4 + cpd3 + cpd2 + cpd1, searchIdPrint,
                                         totalPurchase, totalQuantity);
    }
    else if(ui->print_day_Five_receipt_btn->isChecked())
    {
        qDebug() << "purchase day5 is: " << cpd5;

        found  = Search_Index_Days_Items(cpd4 + cpd3 + cpd2 + cpd1,
                                         purchaseMemberId.size(), searchIdPrint,
                                         totalPurchase, totalQuantity);
    }
    else if(ui->total_Purchse_Rbtn->isChecked())
    {
        int memberListSize = purchaseMemberId.size();

        qDebug() << "MemeberListSize is: " << memberListSize;

        // This loop searches for the id entered by the user in the vector and
        // returns the index if found and shows a warning message if not found
        found  = Search_Index_Days_Items(index, memberListSize, searchIdPrint,
                                         totalPurchase, totalQuantity);
        allDaysPurchase = true;
    }
    else
    {
        QMessageBox::warning(this, "Select Day", "Choose the day");
    }
    if(!found)
    {
        QMessageBox::warning(this, "Search Id", "ID entered was NOT Found!");
    }
    else
    {
        index = 0;
        found = false;

        while(index < ids.size() && !found)
        {
            if(searchIdPrint == ids[index])
            {
                found = true;
            }
            else
            {
                index++;
            }
        }

        if(found)
        {
            if(allDaysPurchase)
            {
                if(type[index] == "Executive")
                {
                    if(totalPurchase < CHANGE_ACCOUNT_PRICE)
                    {
                        ui->change_membership_line_edit->setText("Suggestion: Since your purchase is below $350");
                        ui->change_membership_line_edit_2->setText("You could change your membeship to Regular");
                    }
                    double rebate = totalPurchase * 0.035;
                    ui->rebate_label->setText("Rebate: ");
                    ui->rebate_lineEdit->setText('$' + QString::number(rebate, 'f', 2));
                }
                else
                {
                    if(totalPurchase > CHANGE_ACCOUNT_PRICE)
                    {
                        ui->change_membership_line_edit->setText("Suggestion: Since your purchase is above $350");
                        ui->change_membership_line_edit_2->setText("You could change your membeship to Executive");
                    }
                }
            }

            if(found)

            ui->reciept_member_name->setText("Member Name");
            ui->receipt_member_id->setText("Member Id");
            ui->receipt_member_date->setText("Member Date");
            ui->receipt_member_type->setText("Member Type");

            ui->total_Items_bought_label->setText("Total Amount");
            ui->total_quantity_items_label->setText("Items Bought");

            ui->receipt_lineEdit_name->setText(members[index]);
            ui->receipt_lineEdit_Id->setText(ids[index]);
            ui->receipt_lineEdit_date->setText(date[index]);
            ui->receipt_lineEdit_type->setText(type[index]);

            ui->total_Items_bought_lineEdit->setText('$' + QString::number(totalPurchase, 'f', 2));
            ui->total_quantity_items_lineEdit->setText(QString::number(totalQuantity));
        }
    }
}


/***************************************************
 * Function : Calculate Sales
 * ************************************************/
// Calculates the sales for according to the option
// chosen by the user
QString MainWindow::CalculateSales(int begin, int end)
{
    double totalSale = 0;

    while(begin < end)
    {
       totalSale += (purchasePrice[begin].toDouble() * purchaseQuantity[begin].toInt());

       begin++;
    }
    return QString::number(totalSale);
}

/***************************************************
 * Function : Displays Total Sale
 * ************************************************/
void MainWindow::on_total_sales_button_clicked()
{
    QString totalSale;
    // Checks which of the radio button has been checked
    // and outputs the sales for that category
    if(ui->radioButton_day1_sales->isChecked())
    {
        totalSale  = CalculateSales(0, cpd1);

        ui->day1_sales_label->setText("Day1 Total Sale");
        ui->day1_sales_line_edit->setText('$' + totalSale);
    }
    else if(ui->radioButton_day2_sales->isChecked())
    {
        totalSale  = CalculateSales(cpd2, cpd2 + cpd1);

        ui->day2_sales_label->setText("Day2 Total Sale");
        ui->day2_sales_line_edit->setText('$' + totalSale);
    }
    else if(ui->radioButton_day3_sales->isChecked())
    {
        totalSale  = CalculateSales(cpd2 + cpd3, cpd3 + cpd2 + cpd1);

        ui->day3_sales_label->setText("Day3 Total Sale");
        ui->day3_sales_line_edit->setText('$' + totalSale);
    }
    else if(ui->radioButton_day4_sales->isChecked())
    {
        totalSale  = CalculateSales(cpd3 + cpd2 + cpd1 , cpd4 + cpd3 + cpd2 + cpd1);

        ui->day4_sales_label->setText("Day4 Total Sale");
        ui->day4_sales_line_edit->setText('$' + totalSale);
    }
    else if(ui->radioButton_day5_sales->isChecked())
    {
        totalSale  = CalculateSales(cpd4 + cpd3 + cpd2 + cpd1,
                                    purchaseMemberId.size());

        ui->day5_sales_label->setText("Day5 Total Sale");
        ui->day5_sales_line_edit->setText('$' + totalSale);
    }
    else if(ui->radioButton_total_sale->isChecked())
    {
        totalSale = CalculateSales(0, purchaseMemberId.size());

        ui->sales_total_label->setText("Total Sales");
        ui->sales_total_line_edit->setText('$' + totalSale);
    }
    else
    {
        QMessageBox::warning(this, "Select Option", "Select an option from the Menu!");
    }
}

/***************************************************
 * Function : Search Item Name for Quantity
 * ************************************************/
void MainWindow::SearchNameQuantity(int begin, int end,
                                   QString searchItemName, int &indexFound,
                                   double &totalSoldQuantity, int &totalQuantity)
{
    while(begin < end)
    {
        if(searchItemName == purchaseItemName[begin])
        {
            totalQuantity += purchaseQuantity[begin].toInt();
            totalSoldQuantity += purchasePrice[begin].toDouble() * purchaseQuantity[begin].toInt();

            indexFound = begin;
        }
        begin++;
    }
}


/***************************************************
 * Function : Displays Quantity Items Sold
 * ************************************************/
void MainWindow::on_Find_Qunatity_Sold_Items_button_clicked()
{

    double totalSoldQuantity = 0;
    int    totalQuantity     = 0;
    QString searchItemName = ui->search_name_item_quantity->text();
    int indexFound;

    if(ui->radioButton_quantity_sold_day1->isChecked())
    {
        SearchNameQuantity(0, cpd1, searchItemName, indexFound,
                           totalSoldQuantity, totalQuantity);

        ui->quantity_sold_day1_label->setText("Day1 Total Quantity");
        ui->quantity_sold_day1_lineEdit->setText(QString::number(totalQuantity));
        ui->quantity_day_one_amount_label->setText('$' + QString::number(totalSoldQuantity, 'f', 2));
    }
    else if(ui->radioButton_quantity_sold_day2->isChecked())
    {
         SearchNameQuantity(cpd2, cpd2 + cpd1, searchItemName, indexFound,
                            totalSoldQuantity, totalQuantity);

        ui->quantity_sold_day2_label->setText("Day2 Total Quantity");
        ui->quantity_sold_day2_lineEdit->setText(QString::number(totalQuantity));
        ui->quantity_day_two_amount_label->setText('$' + QString::number(totalSoldQuantity, 'f', 2));
    }
    else if(ui->radioButton_quantity_sold_day3->isChecked())
    {
         SearchNameQuantity(cpd2 + cpd3, cpd3 + cpd2 + cpd1, searchItemName,
                            indexFound, totalSoldQuantity, totalQuantity);

        ui->quantity_sold_day3_label->setText("Day3 Total Quantity");
        ui->quantity_sold_day3_lineEdit->setText(QString::number(totalQuantity));
        ui->quantity_day_three_amount_label->setText('$' + QString::number(totalSoldQuantity, 'f', 2));
    }
    else if(ui->radioButton_quantity_sold_day4->isChecked())
    {
        SearchNameQuantity(cpd3 + cpd2 + cpd1 , cpd4 + cpd3 + cpd2 + cpd1,
                                            searchItemName, indexFound, totalSoldQuantity,
                                            totalQuantity);

        ui->quantity_sold_day4_label->setText("Day4 Total Quantity");
        ui->quantity_sold_day4_lineEdit->setText(QString::number(totalQuantity));
        ui->quantity_day_four_amount_label->setText('$' + QString::number(totalSoldQuantity, 'f', 2));
    }
    else if(ui->radioButton_quantity_sold_day5->isChecked())
    {
        SearchNameQuantity(cpd4 + cpd3 + cpd2 + cpd1, purchaseMemberId.size(),
                           searchItemName, indexFound, totalSoldQuantity, totalQuantity);

        ui->quantity_sold_day5_label->setText("Day5 Total Quantity");
        ui->quantity_sold_day5_lineEdit->setText(QString::number(totalQuantity));
        ui->quantity_day_five_amount_label->setText('$' + QString::number(totalSoldQuantity, 'f', 2));
    }
    else if(ui->radioButton_total_quantity_sold->isChecked())
    {
        SearchNameQuantity(0, purchaseMemberId.size(), searchItemName, indexFound,
                           totalSoldQuantity, totalQuantity);

        ui->total_quantity_sold_label->setText("Total Quantity");
        ui->total_quantity_sold_lineEdit->setText(QString::number(totalQuantity));
        ui->quantity_total_amount_label_2->setText('$' + QString::number(totalSoldQuantity, 'f', 2));

        if(totalQuantity == 0)
        {
            ui->item_price_label->clear();
            ui->item_price_lineEdit->clear();

            ui->quantity_sold_day1_label->clear();
            ui->quantity_sold_day1_lineEdit->clear();
            ui->quantity_sold_day2_label->clear();
            ui->quantity_sold_day2_lineEdit->clear();
            ui->quantity_sold_day3_label->clear();
            ui->quantity_sold_day3_lineEdit->clear();
            ui->quantity_sold_day4_label->clear();
            ui->quantity_sold_day4_lineEdit->clear();
            ui->quantity_sold_day5_label->clear();
            ui->quantity_sold_day5_lineEdit->clear();
            ui->total_quantity_sold_label->clear();
            ui->total_quantity_sold_lineEdit->clear();

            QMessageBox::warning(this, "Incorrect Input", "Item entered was NOT Found!");
        }
    }
    else
    {
        QMessageBox::warning(this, "Select Option", "Select an option from the Menu!");
    }

    if(totalQuantity != 0)
    {
        ui->item_price_label->setText("Price of the Item");
        ui->item_price_lineEdit->setText('$' + purchasePrice[indexFound]);
    }
}

/******************************
 * Function ItemHasBeenDeleted
 ******************************/
// Checks if an item has already been deleted from the
// inventory so the if the user later tried to add the
// same item the inventory a message will pop up that
// item has been deleted.
bool MainWindow::ItemHasBeenDeleted(QString itemName)
{
    bool found = false;
    int index = 0;

    while(index < deletedItems.length() && !found)
    {
        if(itemName == deletedItems[index])
        {
            found = true;
        }
        else
        {
            index++;
        }
    }
    return found;
}

/***************************************************
 * Function : Add Items to the list
 * ************************************************/
void MainWindow::on_Add_items_Button_clicked()
{
    QString itemName     = ui->add_item_item_name_lineEdit->text();
    QString memberId     = ui->add_item_member_id_lineEdit->text();
    QString itemPrice    = ui->add_item_item_price_lineEdit->text();
    QString itemQuantity = ui->add_item_item_quantity_lineEdit->text();
    QString dateOfThePurchase;

    if(!ItemHasBeenDeleted(itemName))
    {
        int indexIdFound = SearchMemberId(memberId);

        if(indexIdFound < ids.length())
        {
            if(ui->radioButton_add_item_day1->isChecked())
            {
                qDebug() << "Cpd1 is: " << cpd1 << '\n';

                dateOfThePurchase = "08/06/2015";
                AddToTheDaysItemsList(cpd1, itemName, memberId, itemPrice,
                                      itemQuantity, dateOfThePurchase);
                cpd1++;
                qDebug() << "Cpd1 is: " << cpd1 << '\n';

                UpdateDaysList("D:/Qt Project1/Project1/day1.txt", 0, cpd1);
            }
            else if(ui->radioButton_add_item_day2->isChecked())
            {
                dateOfThePurchase = "08/04/2015";
                AddToTheDaysItemsList(cpd2 + cpd1, itemName, memberId, itemPrice,
                                      itemQuantity, dateOfThePurchase);
                qDebug() << "Cpd2 is: " << cpd2 << '\n';

                cpd2++;
                UpdateDaysList("D:/Qt Project1/Project1/day2.txt",
                               cpd1, cpd2 + cpd1);

                qDebug() << "Cpd2 is: " << cpd2 << '\n';

            }
            else if(ui->radioButton_add_item_day3->isChecked())
            {
                dateOfThePurchase = "08/03/2015";
                AddToTheDaysItemsList(cpd3 + cpd2 + cpd1, itemName, memberId, itemPrice,
                                      itemQuantity, dateOfThePurchase);

                qDebug() << "Cpd3 is: " << cpd3 << '\n';

                cpd3++;
                UpdateDaysList("D:/Qt Project1/Project1/day3.txt",
                               cpd2 + cpd1, cpd3 + cpd2 + cpd1);

                qDebug() << "Cpd3 is: " << cpd3 << '\n';

            }
            else if(ui->radioButton_add_item_day4->isChecked())
            {
                dateOfThePurchase = "08/02/2015";
                AddToTheDaysItemsList(cpd4 + cpd3 + cpd2 + cpd1, itemName, memberId, itemPrice,
                                      itemQuantity, dateOfThePurchase);

                qDebug() << "Cpd4 is: " << cpd4 << '\n';

                cpd4++;
                UpdateDaysList("D:/Qt Project1/Project1/day4.txt",
                               cpd3 + cpd2 + cpd1 , cpd4 + cpd3 + cpd2 + cpd1);
            }
            else if(ui->radioButton_add_item_day5->isChecked())
            {
                dateOfThePurchase = "08/01/2015";
                qDebug() << "Cpd5 is: " << cpd5 << '\n';
                qDebug() << "Size of the list is: " << purchaseItemName.length() << '\n';

                AddToTheDaysItemsList(purchaseItemName.length(), itemName, memberId, itemPrice,
                                      itemQuantity, dateOfThePurchase);

                qDebug() << "Cpd5 is: " << cpd5 << '\n';

                cpd5++;
                UpdateDaysList("D:/Qt Project1/Project1/day5.txt",
                               cpd4 + cpd3 + cpd2 + cpd1, purchaseMemberId.size());
            }

            ui->confirmation_add_item_label->setText("Item has been Added.");
        }
        else
        {
            QMessageBox::warning(this, "Incorrect Input", "The ID Entered was NOT Found!");
        }
    }
    else
    {
        QMessageBox::warning(this, "Incorrect Input", "Item has been Deleted from the Inventory!");
    }
}

/***************************************************
 * Function : AddToTheDaysItemsList
 * ************************************************/
void MainWindow::AddToTheDaysItemsList(int extendDaysList, QString itemName,
                                       QString memberId, QString itemPrice,
                                       QString itemQuantity, QString dateOfThePurchase)
{
    purchaseItemName.insert(extendDaysList, itemName);
    purchaseMemberId.insert(extendDaysList, memberId);
    purchasePrice.insert(extendDaysList, itemPrice);
    purchaseDate.insert(extendDaysList, dateOfThePurchase);
    purchaseQuantity.insert(extendDaysList, itemQuantity);
}

/***************************************************
 * Function : UpdateDaysList
 * ************************************************/
void MainWindow::UpdateDaysList(QString txtFile, int beginWrite, int endWrite)
{
    // Opens the files for 5 days that the customers did their shopping
    // the files have been opened from the recourse file
    QFile day(txtFile);

    // Chekcs if the file has been opened
    if(!day.open(QFile::ReadWrite | QFile::Text))
    {
        // following message will be diplayed if the file did not open
        QMessageBox::warning(this, "Error File", "16Can\'t open the file");
        return;
    }

    // Declares the objects for the days to read the data from the files
    QTextStream out(&day);

    for(int index = beginWrite; index < endWrite; index++)
    {
        out << purchaseDate[index]     << '\n';
        out << purchaseItemName[index] << '\n';
        out << purchaseMemberId[index] << '\n';
        out << purchasePrice[index]    << '\n';
        out << purchaseQuantity[index] << '\n';
    }

    day.close();
}


/***************************************************
 * Function : Delete Items from the list
 * ************************************************/
void MainWindow::on_pushButton_delete_item_clicked()
{
    QString deleteItem = ui->lineEdit_delete_item->text();

    int indexFound = SearchItemName(deleteItem);

    if(indexFound < purchaseItemName.length())
    {
        deletedItems.push_back(purchaseItemName[indexFound]);

        // Opens the files for deleted items to add
        QFile deleteList("D:/Qt Project1/Project1/deletedItems.txt");

        // Chekcs if the file has been opened
        if(!deleteList.open(QFile::ReadWrite | QFile::Text))
        {
            // following message will be diplayed if the file did not open
            QMessageBox::warning(this, "Error File", "17Can\'t open the file");
            return;
        }

        // Declares the objects for the days to read the data from the files
        QTextStream out(&deleteList);

        for(int index = 0; index < deletedItems.length(); index++)
        {
            out << deletedItems[index]     << '\n';
        }

        deleteList.close();

        ui->Item_deleted_name_label->setText(purchaseItemName[indexFound]);
        ui->Item_deleted_price_label->setText("$" + purchasePrice[indexFound]);
        ui->item_deleted_info->setText("Item Found has been Deleted.");
    }
    else
    {
        QMessageBox::warning(this, "Incorrect Input", "Item name Entered was NOT Found!");
    }
}


/***************************************************
 * Function : Search Item Name
 * ************************************************/
int MainWindow::SearchItemName(QString itemName)
{
    int index= 0;
    bool found = false;

    while(index < purchaseItemName.length() && !found)
    {
        if(itemName == purchaseItemName[index])
        {
            found = true;
        }
        else
        {
            index++;
        }
    }

    return index;
}



