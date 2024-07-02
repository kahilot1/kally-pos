#ifndef LOGINMENU_H
#define LOGINMENU_H

#include "qlistwidget.h"
#include <QMainWindow>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui {
class loginMenu;
struct CurrentUser;
}
QT_END_NAMESPACE



class loginMenu : public QMainWindow
{

    Q_OBJECT

public:

    loginMenu(QWidget *parent = nullptr);
    ~loginMenu();
public:
    QSqlDatabase& getDatabase();
    void updateViewOrders(QListWidget* item);
private slots:
    void on_login_clicked();

    void on_backFromOption1_clicked();

    void on_viewOrderOptionButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    QSqlDatabase m_mydb;
    Ui::loginMenu *ui;
};

#endif // LOGINMENU_H
