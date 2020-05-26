#include "window.h"
#include "ui_window.h"
#include "column_graph.h"
#include <QGraphicsView>
#include <QLayout>
#include <QFormLayout>
#include <qtmaterialiconbutton.h>
#include <QMessageBox>
#include <qtmaterialraisedbutton.h>
#include <qtmaterialflatbutton.h>
#include <qtmaterialfab.h>
#include <QtCore>
#include <QtGui>
#include <QSpacerItem>
#include <qtmaterialtabs.h>
#include <QFrame>
#include <qtmaterialdialog.h>


Window::Window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);

    this->setFixedSize(924, 650);
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setStyleSheet("QWidget {background: black;}");

    auto verticalLayout_3 = new QVBoxLayout(this);

    auto Main_Layout = new QVBoxLayout();
    Main_Layout->setSpacing(0);

    view = new QGraphicsView(this);
    scene = new QGraphicsScene();
    view->setScene(scene);
    Main_Layout->addWidget(view);

    auto frame = new QFrame(this);
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);
    frame->setStyleSheet("QFrame {border-top: 1; border-style: solid; border-color: grey grey grey grey; background: black; }");

    auto horizontalLayout_2 = new QHBoxLayout(frame);
    horizontalLayout_2->setSpacing(0);
    horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

    auto bottom_layout = new QHBoxLayout();
    bottom_layout->setSpacing(0);

    auto tabs = new QtMaterialTabs(frame);
    tabs->addTab("Merge Sort");
    tabs->addTab("Quick Sort");
    tabs->addTab("Heap Sort");
    tabs->addTab("Bubble Sort");
    tabs->setBackgroundColor(Qt::black);
    bottom_layout->addWidget(tabs);

    auto Left_spacer = new QSpacerItem(250, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    bottom_layout->addItem(Left_spacer);

    auto Label_Icon_Layout = new QVBoxLayout();
    Label_Icon_Layout->setSpacing(0);

    QPixmap icon("/Users/L/Documents/Programming files/Icons/dice.png");
    generate_button = new QtMaterialIconButton(icon, frame);
    generate_button->setColor(Qt::white);
    generate_button->setIconSize(QSize(32,32));
    Label_Icon_Layout->addWidget(generate_button);
    bottom_layout->addLayout(Label_Icon_Layout);

    auto Right_Spacer = new QSpacerItem(400, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    bottom_layout->addItem(Right_Spacer);

    clear_button = new QtMaterialRaisedButton("Clear", frame);
    clear_button->setFontSize(11);
    clear_button->setFixedWidth(150);
    bottom_layout->addWidget(clear_button);
    horizontalLayout_2->addLayout(bottom_layout);

    Main_Layout->addWidget(frame);

    verticalLayout_3->addLayout(Main_Layout);

  //  auto dialog = new QtMaterialDialog(this);
  //  dialog->showDialog();


    connect(generate_button, SIGNAL(clicked()), this, SLOT(on_generate_button_clicked()));

    connect(clear_button, SIGNAL(clicked()), this, SLOT(on_clear_button_clicked()));
}

Window::~Window() {

    delete ui;
}

void Window::initialize_cells() {

    if (cells.size() == 0){
        height = view->height() / cell_size;
        width = view->width() / cell_size;
        cells.resize(width * height);

        for (int y = 0; y < height; y++){
            for (int x = 0; x < width; x++){
                auto *cell = new QGraphicsRectItem(x * cell_size, y * cell_size, cell_size, cell_size);
                cells[y].push_back(cell);
                scene->addItem(cell);
            }
        }
    }
}

void Window::reset_board() {

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            cells[y][x]->setBrush(Qt::black);
        }
    }

    if (cells.size() != 0)
        cells.clear();
}

void Window::on_generate_button_clicked() {

    if (one_time){

        one_time = false;

        initialize_cells();
        graph.generate_random_columns(height, width);

        for (int x = 1; x < width - 1; x++){
            int y = height - 1;
            while (y != graph.columns[x]){
                cells[y][x]->setBrush(Qt::blue);
                cells[y][x]->setPen(Qt::NoPen);
                y--;
            }
        }
    }
}

void Window::on_clear_button_clicked() {

    one_time = true;
    reset_board();
}



