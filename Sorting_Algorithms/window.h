#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QWidget>
#include "column_graph.h"
#include <qtmaterialraisedbutton.h>
#include <qtmaterialiconbutton.h>
#include <qtmaterialdialog.h>
#include <qtmaterialtabs.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    column_graph graph;
    ~Window();

private:
    Ui::Window *ui;

    QGraphicsScene *scene;
    QGraphicsView *view;

    int cell_size = 10;
    int height = 100;
    int width = 100;


    QVector < QVector <QGraphicsRectItem*>> cells;
    void initialize_cells();

    void reset_board(int);
    void repaint();

    QtMaterialRaisedButton *clearButton;
    QtMaterialIconButton *generateButton;
    QtMaterialIconButton *startButton;
    QtMaterialDialog *dialog;
    QtMaterialTabs *tabs;

    bool one_time = true;

    QTimer *timer;

private slots:
    void generateButton_clicked();
    void clearButton_clicked();
    void closeButton_clicked();
    void startButton_clicked();
    void update_cells();
};
#endif // WINDOW_H
