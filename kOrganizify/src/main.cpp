

#include "mainwindow.h"
#include "basiceventwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

   // MainWindow w;
   // w.show();

   BasicEventWindow bw;
   bw.show();

   return a.exec();
}


// #include <QCoreApplication>
// #include <QDebug>
// #include <z3.h>
// #include <z3++.h>

// int main(int argc, char *argv[]) {

//     qDebug() << "stagod";

//     QCoreApplication a(argc, argv);

//     // Create a Z3 context
//     z3::context ctx;

//     // Variables
//     z3::expr x = ctx.int_const("x");
//     z3::expr y = ctx.int_const("y");

//     // Equation: x + y = 10
//     z3::solver solver(ctx);
//     solver.add(x + y == 10);

//     // Solve the equation
//     auto result = solver.check();

//     if (result == z3::sat) {
//         z3::model model = solver.get_model();

//         // Initialize x_value and y_value with default values
//         int x_value = 0;
//         int y_value = 0;

//         // Retrieve values from the model
//         model.eval(x, x_value);
//         model.eval(y, y_value);

//         qDebug() << "Solution found:";
//         qDebug() << "x =" << x_value;
//         qDebug() << "y =" << y_value;
//     } else {
//         qDebug() << "No solution found.";
//     }

//     return a.exec();
// }
