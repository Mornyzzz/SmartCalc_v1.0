#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  QString res_expr;
  Ui::MainWindow *ui;
  QString res;
  QChart *chrt;
  QValueAxis *xAxis;
  QValueAxis *yAxis;

 private slots:
  void calc_input();
  void calc_input_funcs();
  void calc_clear();
  void calc_result();
  void plot();
  void calc_input_brackets();
  void calc_input_mod();
  void calc_input_pi();
  void change_color();
};
#endif  // MAINWINDOW_H
