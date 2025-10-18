#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <qtextedit.h>
#include <QTabWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QWidget *central = new QWidget;
    QTabWidget *tabBar = new QTabWidget;
    QPushButton *backBtn = new QPushButton("\u2190");
    QPushButton *forwardBtn = new QPushButton("\u2192");
    QPushButton *addBtn = new QPushButton("+");
    QHBoxLayout *btnLayout = new QHBoxLayout;
    QHBoxLayout *btnLayout2 = new QHBoxLayout;
    QWidget *btnContainer = new QWidget;
    QWidget *btnContainer2 = new QWidget;
    QPushButton *closeBtn = new QPushButton("✕");

    tabBar->addTab(new QTextEdit, "main.cpp");

    tabBar->setTabsClosable(true);
    connect(tabBar, &QTabWidget::tabCloseRequested, this, [tabBar](int index) {
        tabBar->removeTab(index);
    });

    menuBar()->setStyleSheet(R"(QMenuBar{
                                    background-color: #1E2030;
                                    color:white;
                                    font-size: 16px;
                                }
                                QMenuBar::tab{
                                    background-color: #24293D;
                                    color:white;
                                }
                                QMenu{
                                    color:white;
                                    background-color: #1E2030;
                                }
                                QMenu::separator{
                                    background:white;
                                    height: 2px;
                                    margin-left: 10px;
                                    margin-right: 10px;
                                }
)");
    tabBar->setStyleSheet(R"(
    QTabBar::tab {
        color: white;
        background: #1E2030;
        padding: 6px 10px;
        font-size: 16px;
    }
    QTabBar::tab:selected {
        background: #24293D;
        color: #00BCD4;
    }
    QTextEdit {
        color: white;
        background-color: #24293D;
        font-size: 18px;
}
    QTabBar{
        background-color: #131420;
}
    QPushButton{
        padding:4px;
}
)");

    backBtn->setStyleSheet(R"(
    color:white;
    font-size:16px;
)");

    forwardBtn->setStyleSheet(R"(
    color:white;
    font-size:16px;
)");

    addBtn->setStyleSheet(R"(
                color:white;
                font-size:16px;
)");

    backBtn->setFixedSize(35, 35);
    forwardBtn->setFixedSize(35, 35);
    addBtn->setFixedSize(35, 35);

    connect(addBtn, &QPushButton::clicked, this, [this, tabBar, backBtn]() {
        actionAdd(tabBar, backBtn);
    });


    btnLayout->addWidget(backBtn);
    btnLayout->addWidget(forwardBtn);

    btnLayout2->addWidget(addBtn);

    btnContainer->setLayout(btnLayout);

    btnContainer2->setLayout(btnLayout2);

    btnContainer->setStyleSheet(R"(
                    margin-bottom: 16px;
)");

    btnContainer2->setStyleSheet(R"(
                    margin-bottom: 16px;
)");

    tabBar->setCornerWidget(btnContainer, Qt::TopLeftCorner);
    tabBar->setCornerWidget(btnContainer2, Qt::TopRightCorner);
    connect(ui->actionNew, &QAction::triggered, this, [this,tabBar,backBtn](){
        actionAdd(tabBar,backBtn);
    });


    mainLayout->addWidget(menuBar());
    mainLayout->addWidget(tabBar);

    central->setLayout(mainLayout);

    setCentralWidget(central);
}

void MainWindow::actionAdd(QTabWidget *tabBar, QPushButton *btn)
{
    tabBar->addTab(new QTextEdit, "new.cpp");
};

MainWindow::~MainWindow()
{
    delete ui;
}
