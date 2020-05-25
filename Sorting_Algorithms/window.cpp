#include "window.h"
#include "ui_window.h"
#include "column_graph.h"
#include <QGraphicsView>
#include <QLayout>
#include <QFormLayout>



Window::Window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);

    QGraphicsView *view = new QGraphicsView();

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(view);




}

Window::~Window()
{
    delete ui;
}

