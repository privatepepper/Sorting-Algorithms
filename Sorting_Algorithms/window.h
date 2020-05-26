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

    void reset_board();

    QtMaterialRaisedButton *clear_button;
    QtMaterialIconButton *generate_button;

    bool one_time = true;

private slots:
    void on_generate_button_clicked();
    void on_clear_button_clicked();
};
#endif // WINDOW_H
