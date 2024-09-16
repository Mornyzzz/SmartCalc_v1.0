#include "mainwindow.h"

#include <QDoubleValidator>

#include "ui_mainwindow.h"

extern "C" {
#include "../smartcalc.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->input_x->setText("0");

  //<дизайн
  ui->centralwidget->setStyleSheet("background-color: #252932;");
  // ui->pushButton_4->setStyleSheet("QPushButton { color : white;
  // background-color: #A9C3D0;}");

  ui->pushButton_0->setStyleSheet(
      "QPushButton { border-bottom-left-radius: 10px; background-color: "
      "#A9C3D0}");
  ui->pushButton_1->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_2->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_3->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_4->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_5->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_6->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_7->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_8->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_9->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_point->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");

  ui->pushButton_pow->setStyleSheet(
      "QPushButton { border: none; background-color: #6DA6B9}");
  ui->pushButton_div->setStyleSheet(
      "QPushButton { border-top-right-radius: 10px; background-color: "
      "#6DA6B9}");
  ui->pushButton_mult->setStyleSheet(
      "QPushButton { border: none; background-color: #6DA6B9}");
  ui->pushButton_add->setStyleSheet(
      "QPushButton { border: none; background-color: #6DA6B9}");
  ui->pushButton_sub->setStyleSheet(
      "QPushButton { border: none; background-color: #6DA6B9}");

  ui->pushButton_mod->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_brackets->setStyleSheet(
      "QPushButton { border-top-right-radius: 10px; background-color: "
      "#A9C3D0}");
  ui->pushButton_cos->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_sin->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_acos->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_asin->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_tg->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_atan->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_sqrt->setStyleSheet(
      "QPushButton { border-top-left-radius: 10px; background-color: #A9C3D0}");
  ui->pushButton_log->setStyleSheet(
      "QPushButton { border: none; background-color: #A9C3D0}");
  ui->pushButton_ln->setStyleSheet(
      "QPushButton { border-bottom-right-radius: 10px; background-color: "
      "#A9C3D0}");
  ui->pushButton_pi->setStyleSheet(
      "QPushButton { border-bottom-left-radius: 10px; background-color: "
      "#A9C3D0}");

  ui->pushButton_AC->setStyleSheet(
      "QPushButton { border-top-left-radius: 10px; background-color: #326B7E}");
  ui->pushButton_calc->setStyleSheet(
      "QPushButton { border-bottom-right-radius: 10px; background-color: "
      "#326B7E}");
  ui->pushButton_plot->setStyleSheet(
      "QPushButton { border-radius: 10px; background-color: #326B7E}");
  ui->pushButton_x->setStyleSheet(
      "QPushButton { border-radius: 10px; background-color: #326B7E}");

  ui->input_x->setStyleSheet(
      "QLineEdit { border-radius: 10px; background-color: #FFFFFF}");
  ui->result->setStyleSheet(
      "QLineEdit { border-bottom-left-radius: 10px; "
      "border-bottom-right-radius: 10px; background-color: #FFFFFF}");
  ui->expression->setStyleSheet(
      "QLineEdit { border-top-left-radius: 10px; border-top-right-radius: "
      "10px; background-color: #FFFFFF}");
  ui->x_min->setStyleSheet(
      "QLineEdit { border-radius: 10px; background-color: #FFFFFF}");
  ui->x_max->setStyleSheet(
      "QLineEdit { border-radius: 10px; background-color: #FFFFFF}");
  ui->y_min->setStyleSheet(
      "QLineEdit { border-radius: 10px; background-color: #FFFFFF}");
  ui->y_max->setStyleSheet(
      "QLineEdit { border-radius: 10px; background-color: #FFFFFF}");

  //дизайн>

  ui->expression->setAlignment(Qt::AlignRight);
  ui->result->setAlignment(Qt::AlignRight);

  ui->x_min->setText("-50");
  ui->x_max->setText("50");
  ui->y_min->setText("-50");
  ui->y_max->setText("50");
  chrt = new QChart;
  ui->vchrt->setChart(chrt);

  xAxis = new QValueAxis;
  xAxis->setRange(-50, 50);
  yAxis = new QValueAxis;
  yAxis->setRange(-50, 50);

  QLineSeries *series = new QLineSeries();

  chrt->addSeries(series);
  chrt->setAxisX(xAxis, series);
  chrt->setAxisY(yAxis, series);
  chrt->legend()->setVisible(false);

  ui->input_x->setValidator(new QIntValidator);

  ui->x_min->setValidator(new QIntValidator);
  ui->x_max->setValidator(new QIntValidator);
  ui->y_min->setValidator(new QIntValidator);
  ui->y_max->setValidator(new QIntValidator);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_brackets, SIGNAL(clicked()), this,
          SLOT(calc_input_brackets()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(calc_input_funcs()));
  connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(calc_input_funcs()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(calc_input_funcs()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(calc_input_funcs()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(calc_input_funcs()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(calc_input_funcs()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(calc_input_mod()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(calc_input_funcs()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(calc_input_funcs()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(calc_input()));
  connect(ui->pushButton_tg, SIGNAL(clicked()), this, SLOT(calc_input_funcs()));
  connect(ui->pushButton_pi, SIGNAL(clicked()), this, SLOT(calc_input_pi()));

  connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(calc_clear()));
  connect(ui->pushButton_plot, SIGNAL(clicked()), this, SLOT(change_color()));
  // connect(ui->pushButton_plot,SIGNAL(clicked()),this,SLOT(plot()));
  connect(ui->pushButton_calc, SIGNAL(clicked()), this, SLOT(calc_result()));
}

MainWindow::~MainWindow() { delete ui; }
void MainWindow::change_color() {
  ui->pushButton_plot->setStyleSheet(
      "QPushButton { border-radius: 10px; background-color: #FF7400}");
  QTimer::singleShot(100, this, SLOT(plot()));
}

void MainWindow::plot() {
  QLineSeries *series = new QLineSeries();
  int xMin, xMax, yMin, yMax;

  xMin = ui->x_min->text().toInt();
  xMax = ui->x_max->text().toInt();
  yMin = ui->y_min->text().toInt();
  yMax = ui->y_max->text().toInt();
  double maxDelta = (xMax - xMin) > (yMax - yMin) ? xMax - xMin : yMax - yMin;

  if ((maxDelta <= 0) || (xMin >= xMax) || (yMin >= yMax) ||
      (xMin < -1000000) || (xMax > 1000000) || (yMin < -1000000) ||
      (yMax > 1000000)) {
    return;
  }

  chrt = new QChart;
  ui->vchrt->setChart(chrt);
  chrt->legend()->setVisible(false);
  xAxis = new QValueAxis;
  xAxis->setRange(xMin, xMax);
  yAxis = new QValueAxis;
  yAxis->setRange(yMin, yMax);

  QPen pen = series->pen();
  pen.setWidth(2);
  pen.setBrush(QBrush("orange"));

  double h = maxDelta / 20000;

  for (double i = xMin; i < xMax; i = i + h) {
    if (ui->expression->text() != "") {
      QString expr = '(' + ui->expression->text() + ')';
      double output = atof(calc(expr.toStdString().c_str(), i));
      if (strcmp(calc(expr.toStdString().c_str(), i), "nan") != 0 &&
          strcmp(calc(expr.toStdString().c_str(), i), "inf") != 0 &&
          strcmp(calc(expr.toStdString().c_str(), i), "-inf") != 0) {
        if (output > yMax || output < yMin) {
          series->setPen(pen);

          chrt->addSeries(series);
          chrt->setAxisX(xAxis, series);
          chrt->setAxisY(yAxis, series);
          series = new QLineSeries();
        }
        series->append(i, output);
      }
    }
  }
  series->setPen(pen);

  chrt->addSeries(series);
  chrt->setAxisX(xAxis, series);
  chrt->setAxisY(yAxis, series);
  ui->pushButton_plot->setStyleSheet(
      "QPushButton { border-radius: 10px; background-color: #326B7E}");
}

void MainWindow::calc_result() {
  if (ui->expression->text() != "") {
    double x = ui->input_x->text().toDouble();
    QString expr = '(' + ui->expression->text() + ')';
    QString output =
        QString::fromStdString(calc(expr.toStdString().c_str(), x));
    ui->result->setText(output);
  }
}

void MainWindow::calc_input() {
  QPushButton *button = (QPushButton *)sender();
  QString left, right, expr;
  int pos = ui->expression->cursorPosition();
  left = ui->expression->text().mid(0, pos);
  right = ui->expression->text().mid(pos);
  expr = left + button->text() + right;
  ui->expression->setText(expr);
  ui->expression->setCursorPosition(pos + button->text().capacity());
}

void MainWindow::calc_input_brackets() {
  QString left, right, expr;
  int pos = ui->expression->cursorPosition();
  left = ui->expression->text().mid(0, pos);
  right = ui->expression->text().mid(pos);
  expr = left + "()" + right;
  ui->expression->setText(expr);
  ui->expression->setCursorPosition(pos + 1);
}

void MainWindow::calc_input_mod() {
  QString left, right, expr;
  int pos = ui->expression->cursorPosition();
  left = ui->expression->text().mid(0, pos);
  right = ui->expression->text().mid(pos);
  expr = left + "%" + right;
  ui->expression->setText(expr);
  ui->expression->setCursorPosition(pos + 1);
}

void MainWindow::calc_input_pi() {
  QString left, right, expr;
  int pos = ui->expression->cursorPosition();
  left = ui->expression->text().mid(0, pos);
  right = ui->expression->text().mid(pos);
  expr = left + "3.14159265358980" + right;
  ui->expression->setText(expr);
  ui->expression->setCursorPosition(pos + 16);
}

void MainWindow::calc_input_funcs() {
  QPushButton *button = (QPushButton *)sender();
  QString left, right, expr;
  int pos = ui->expression->cursorPosition();
  left = ui->expression->text().mid(0, pos);
  right = ui->expression->text().mid(pos);
  expr = left + button->text() + "()" + right;
  ui->expression->setText(expr);
  ui->expression->setCursorPosition(1 + pos + button->text().capacity());
}

void MainWindow::calc_clear() {
  ui->expression->setText("");
  ui->result->setText("");
}
