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


#define erase 99



Window::Window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);

    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setStyleSheet(" background-color: black;");

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

    tabs = new QtMaterialTabs(frame);
    tabs->addTab("Merge Sort");
    tabs->addTab("Quick Sort");
    tabs->addTab("Heap Sort");
    tabs->addTab("Bubble Sort");
    tabs->setBackgroundColor(Qt::black);
    bottom_layout->addWidget(tabs);

    auto Left_spacer = new QSpacerItem(250, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    bottom_layout->addItem(Left_spacer);

    auto Icons_Layout = new QHBoxLayout();
    Icons_Layout->setSpacing(1);

    QPixmap icon("/Users/L/Documents/Programming files/Icons/dice.png");
    generateButton = new QtMaterialIconButton(icon, frame);
    generateButton->setColor(Qt::white);
    generateButton->setIconSize(QSize(32,32));
    Icons_Layout->addWidget(generateButton);

    QPixmap icon1("/Users/L/Documents/Programming files/Icons/connection.png");
    startButton = new QtMaterialIconButton(icon1, frame);
    startButton->setColor(Qt::white);
    startButton->setIconSize(QSize(32,32));
    Icons_Layout->addWidget(startButton);

    bottom_layout->addLayout(Icons_Layout);

    auto Right_Spacer = new QSpacerItem(400, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    bottom_layout->addItem(Right_Spacer);

    clearButton = new QtMaterialRaisedButton("Clear", frame);
    clearButton->setFontSize(11);
    clearButton->setFixedWidth(150);
    bottom_layout->addWidget(clearButton);
    horizontalLayout_2->addLayout(bottom_layout);

    Main_Layout->addWidget(frame);

    verticalLayout_3->addLayout(Main_Layout);

    dialog = new QtMaterialDialog(this);
    dialog->setObjectName("dialog");
    dialog->setStyleSheet("#dialog { background: grey;}");

    QWidget *dialogWidget = new QWidget;
    dialogWidget->setObjectName("dialogWidget");
    dialogWidget->setStyleSheet("#dialogWidget { background: grey;}");
    auto dialogWidgetLayout = new QVBoxLayout;
    dialogWidgetLayout->setMargin(10);
    dialogWidgetLayout->setSpacing(10);
    dialogWidget->setLayout(dialogWidgetLayout);

    auto title_label = new QLabel("Sorting Algorithms");
    QFont serifFont("Helvetica [Cronyx]", 20, QFont::Bold);
    title_label->setFont(serifFont);
    title_label->setObjectName("label");
    title_label->setStyleSheet("#label{background: grey;}");
    dialogWidgetLayout->addWidget(title_label);
    dialogWidgetLayout->setAlignment(title_label, Qt::AlignTop | Qt::AlignCenter);

    auto gif_label = new QLabel();
    auto mv = new QMovie("/Users/L/Documents/Programming files/Icons/giphy.gif");
    mv->start();
    gif_label->setAttribute(Qt::WA_NoSystemBackground);
    gif_label->setMovie(mv);
    dialogWidgetLayout->addWidget(gif_label);
    dialogWidgetLayout->setAlignment(gif_label, Qt::AlignTop | Qt::AlignLeft);

    auto closeButton = new QtMaterialFlatButton("Close");
    closeButton->setFontSize(12);
    dialogWidgetLayout->addWidget(closeButton);
    dialogWidgetLayout->setAlignment(closeButton, Qt::AlignBottom | Qt::AlignCenter);
    closeButton->setFixedWidth(100);
    closeButton->setFixedHeight(25);


    QVBoxLayout *dialogLayout = new QVBoxLayout;
    dialogLayout->setMargin(0);
    dialogLayout->setSpacing(0);
    dialog->setWindowLayout(dialogLayout);
    dialogWidget->setMinimumHeight(300);
    dialogLayout->addWidget(dialogWidget);
    dialog->showDialog();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_cells()));

    connect(generateButton, SIGNAL(clicked()), this, SLOT(generateButton_clicked()));
    connect(clearButton, SIGNAL(clicked()), this, SLOT(clearButton_clicked()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(closeButton_clicked()));
    connect(startButton, SIGNAL(clicked()), this, SLOT(startButton_clicked()));

}

Window::~Window() {

    delete ui;
}

void Window::initialize_cells() {

    if (cells.size() == 0){
        height = (view->height() / cell_size);
        width = (view->width() / cell_size) - 1;
        cells.resize(width * height);

        for (int y = 0; y < height; y++){
            for (int x = 0; x < width; x++){
                auto *cell = new QGraphicsRectItem(x * cell_size, y * cell_size, cell_size, cell_size);
                cell->setBrush(Qt::black);
                cells[y].push_back(cell);
                scene->addItem(cell);
            }
        }
    }
}

void Window::reset_board(int x) {

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            cells[y][x]->setBrush(Qt::black);
        }
    }

    if (x == erase){
        if (cells.size() != 0)
            cells.clear();
    }
}

void Window::repaint(int start, int end, QColor color) {

    for (int x = start; x <= end; x++){
        int y = height - 1;
        int square_counter = 0;
        while (square_counter != graph.columns[x]){
            cells[y][x]->setBrush(color);
            cells[y][x]->setPen(Qt::NoPen);
            square_counter++;
            y--;
        }
    }
}

void Window::generateButton_clicked() {

    if (one_time){

        one_time = false;
        initialize_cells();
        graph.generate_random_columns(height, width);
        repaint(0, graph.columns.size() - 1, Qt::blue);
    }

}

void Window::clearButton_clicked() {

    one_time = true;
    graph.reset();
    graph.current_index = 0;
    graph.checking_right_now = 1;
    timer->stop();
    reset_board(erase);
}

void Window::closeButton_clicked() {

    dialog->hideDialog();
    dialog->deleteLater();

}

void Window::startButton_clicked() {

    timer->start(0);
}

void Window::update_cells() {

    // Bubble Sort
    if (tabs->currentIndex() == 3) {

        reset_board(0);
        repaint(0, graph.columns.size() - 1, Qt::blue);

        for (int y = height - 1; y > 0; y--){

            if (cells[y][graph.current_index]->brush() != Qt::blue)
                break;
            cells[y][graph.current_index]->setBrush(Qt::green);
        }

        for (int y = height - 1; y > 0; y--){

            if (cells[y][graph.checking_right_now]->brush() != Qt::blue)
                break;
            cells[y][graph.checking_right_now]->setBrush(Qt::red);
        }

        if (graph.bubble_sort()){
            timer->stop();
            repaint(0, graph.columns.size() - 1, Qt::blue);
        }
    }

    // Quick Sort
    if (tabs->currentIndex() == 1){

        reset_board(0);
        repaint(0, graph.columns.size() - 1, Qt::blue);
        repaint(graph.recursive_saver[0].first, graph.recursive_saver[0].second, Qt::yellow);

        if (graph.left_index != -1){
            for (int y = height - 1; y > 0; y--){

                if (cells[y][graph.left_index]->brush() == Qt::black)
                    break;
                cells[y][graph.left_index]->setBrush(Qt::green);
            }
        }

        for (int y = height - 1; y > 0; y--){

            if (cells[y][graph.right_index]->brush() == Qt::black)
                break;
            cells[y][graph.right_index]->setBrush(Qt::green);
        }

        if (graph.quick_sort(graph.recursive_saver[0].first, graph.recursive_saver[0].second) == -1){

            if (graph.recursive_saver.size() == 0 || graph.recursive_saver.size() == 1){

                timer->stop();
                repaint(0, graph.columns.size() - 1, Qt::blue);
            } else {

                graph.recursive_saver.pop_front();
                graph.quick_sort(graph.recursive_saver[0].first, graph.recursive_saver[0].second);
            }

        }
    }
}
