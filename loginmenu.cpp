#include "loginmenu.h"
#include "userManager.h"
#include "user.h"
#include "ui_loginmenu.h"
#include <QtDebug>
#include <QDir>

// A way to store the current user who is logged in


loginMenu::loginMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginMenu)
{
    ui->setupUi(this);
    ui->ErrorMessageHandler->setAlignment(Qt::AlignCenter);
    ui->viewOrderDockWidget->hide();
    m_mydb = QSqlDatabase::addDatabase("QSQLITE");
    m_mydb.setDatabaseName(QDir::currentPath() + "/pos.db");
    updateViewOrders(ui->viewOrdersDisplayOrders);
}

loginMenu::~loginMenu()
{
    delete ui;
}
QSqlDatabase& loginMenu::getDatabase(){
    return m_mydb;
}

// utility functions
void loginMenu::updateViewOrders(QListWidget* item){
    QSqlDatabase mydb = loginMenu::getDatabase();
    if (mydb.open()){
        QSqlQuery qry(mydb);
        item->clear();

        qry.prepare("SELECT * FROM orders");
        qry.exec();
        while(qry.next()){
            item->addItem(qry.value("id").toString());
        }
    }

}


// buttons being clicked

void loginMenu::on_login_clicked()
{
    //setup the database connections
    QSqlDatabase mydb = loginMenu::getDatabase();
    if (mydb.open()){
        //setup the querying object
        QSqlQuery qry(mydb);

        //take user input for password and username
        QString enteredPassword = ui->passwordEntry->text();
        QString enteredUsername = ui->usernameEntry->text();
        ui->passwordEntry->setText("");
        ui->usernameEntry->setText("");
        ui->ErrorMessageHandler->setText("");

        //query if the details are correct or incorrect
        bool validLoginDetails = false; //variable to store if it is correct
        qry.prepare("SELECT userAuth, username, id FROM users WHERE username=:username and password=:password");
        qry.bindValue(":username", enteredUsername);
        qry.bindValue(":password", enteredPassword);
        qry.exec();

        while(qry.next()){
            //setting the validity of login details
            validLoginDetails = true;

            //getting the details of the account
            QString username = qry.value("username").toString();
            user::AuthenticationLevel authL = (user::AuthenticationLevel)qry.value("userAuth").toInt();
            int uID = qry.value("id").toInt();

            //creating a user out of the account details and assigning it as the primary account to a usermanager singelton
            user newCurrentUser(authL, uID, username);
            usermanager::instance().setCurrentUser(newCurrentUser);

            break;
        }

        //handle what happends if correct/incorrect details are entered
        if (validLoginDetails){
            //TODO send to next page and set user auth to the auth level of the user chosen
            qDebug("Valid login details");
            ui->superwidget->setCurrentIndex(1);
            ui->userIDLabel->setText(enteredUsername);

        }
        else{
            //ask for resubmission of data
            ui->ErrorMessageHandler->setText("Invalid login details please re-submit!");
            qDebug("Invalid login details");
        }
        mydb.close();
        }


}


void loginMenu::on_backFromOption1_clicked()
{
    user newCurrentUser(user::clerk, 0, "");
    usermanager::instance().setCurrentUser(newCurrentUser);

    ui->superwidget->setCurrentIndex(0);
}

void loginMenu::on_viewOrderOptionButton_clicked()
{
    if (ui->viewOrderDockWidget->isVisible())
        ui->viewOrderDockWidget->hide();
    else if(usermanager::instance().getCurrentUser().getAuLevel() > 0)
        ui->viewOrderDockWidget->show();
}


void loginMenu::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}

