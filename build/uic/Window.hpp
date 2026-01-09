/********************************************************************************
** Form generated from reading UI file 'Window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WINDOW_H
#define WINDOW_H

#include <QtCore/QVariant>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QFrame *controls;
    QGridLayout *gridLayout_2;
    QGroupBox *group_loads;
    QGroupBox *group_mesh;
    QGridLayout *gridLayout_3;
    QLineEdit *edit_mesh_height;
    QLabel *label_mesh_width;
    QLabel *label_mesh_radius;
    QLabel *label_mesh_height;
    QLineEdit *edit_mesh_width;
    QLineEdit *edit_mesh_radius;
    QLabel *label_mesh_angle;
    QLineEdit *edit_mesh_angle;
    QGroupBox *group_geometry;
    QGridLayout *gridLayout;
    QLabel *label_geometry_height;
    QLineEdit *edit_geometry_width;
    QLineEdit *edit_geometry_radius;
    QLabel *label_geometry_radius;
    QLineEdit *edit_geometry_height;
    QLabel *label_geometry_width;
    QLabel *label_geometry_type;
    QComboBox *combo_geometry_type;
    QSpacerItem *verticalSpacer;
    QOpenGLWidget *canvas;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName("Window");
        Window->resize(1327, 600);
        widget = new QWidget(Window);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        controls = new QFrame(widget);
        controls->setObjectName("controls");
        controls->setMaximumSize(QSize(250, 16777215));
        controls->setFrameShape(QFrame::Shape::StyledPanel);
        controls->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(controls);
        gridLayout_2->setObjectName("gridLayout_2");
        group_loads = new QGroupBox(controls);
        group_loads->setObjectName("group_loads");

        gridLayout_2->addWidget(group_loads, 2, 0, 1, 1);

        group_mesh = new QGroupBox(controls);
        group_mesh->setObjectName("group_mesh");
        gridLayout_3 = new QGridLayout(group_mesh);
        gridLayout_3->setObjectName("gridLayout_3");
        edit_mesh_height = new QLineEdit(group_mesh);
        edit_mesh_height->setObjectName("edit_mesh_height");

        gridLayout_3->addWidget(edit_mesh_height, 1, 1, 1, 1);

        label_mesh_width = new QLabel(group_mesh);
        label_mesh_width->setObjectName("label_mesh_width");

        gridLayout_3->addWidget(label_mesh_width, 0, 0, 1, 1);

        label_mesh_radius = new QLabel(group_mesh);
        label_mesh_radius->setObjectName("label_mesh_radius");

        gridLayout_3->addWidget(label_mesh_radius, 3, 0, 1, 1);

        label_mesh_height = new QLabel(group_mesh);
        label_mesh_height->setObjectName("label_mesh_height");

        gridLayout_3->addWidget(label_mesh_height, 1, 0, 1, 1);

        edit_mesh_width = new QLineEdit(group_mesh);
        edit_mesh_width->setObjectName("edit_mesh_width");

        gridLayout_3->addWidget(edit_mesh_width, 0, 1, 1, 1);

        edit_mesh_radius = new QLineEdit(group_mesh);
        edit_mesh_radius->setObjectName("edit_mesh_radius");

        gridLayout_3->addWidget(edit_mesh_radius, 3, 1, 2, 1);

        label_mesh_angle = new QLabel(group_mesh);
        label_mesh_angle->setObjectName("label_mesh_angle");

        gridLayout_3->addWidget(label_mesh_angle, 2, 0, 1, 1);

        edit_mesh_angle = new QLineEdit(group_mesh);
        edit_mesh_angle->setObjectName("edit_mesh_angle");

        gridLayout_3->addWidget(edit_mesh_angle, 2, 1, 1, 1);


        gridLayout_2->addWidget(group_mesh, 1, 0, 1, 1);

        group_geometry = new QGroupBox(controls);
        group_geometry->setObjectName("group_geometry");
        gridLayout = new QGridLayout(group_geometry);
        gridLayout->setObjectName("gridLayout");
        label_geometry_height = new QLabel(group_geometry);
        label_geometry_height->setObjectName("label_geometry_height");

        gridLayout->addWidget(label_geometry_height, 2, 0, 1, 1);

        edit_geometry_width = new QLineEdit(group_geometry);
        edit_geometry_width->setObjectName("edit_geometry_width");

        gridLayout->addWidget(edit_geometry_width, 1, 1, 1, 1);

        edit_geometry_radius = new QLineEdit(group_geometry);
        edit_geometry_radius->setObjectName("edit_geometry_radius");

        gridLayout->addWidget(edit_geometry_radius, 3, 1, 1, 1);

        label_geometry_radius = new QLabel(group_geometry);
        label_geometry_radius->setObjectName("label_geometry_radius");

        gridLayout->addWidget(label_geometry_radius, 3, 0, 1, 1);

        edit_geometry_height = new QLineEdit(group_geometry);
        edit_geometry_height->setObjectName("edit_geometry_height");

        gridLayout->addWidget(edit_geometry_height, 2, 1, 1, 1);

        label_geometry_width = new QLabel(group_geometry);
        label_geometry_width->setObjectName("label_geometry_width");

        gridLayout->addWidget(label_geometry_width, 1, 0, 1, 1);

        label_geometry_type = new QLabel(group_geometry);
        label_geometry_type->setObjectName("label_geometry_type");

        gridLayout->addWidget(label_geometry_type, 0, 0, 1, 1);

        combo_geometry_type = new QComboBox(group_geometry);
        combo_geometry_type->addItem(QString());
        combo_geometry_type->addItem(QString());
        combo_geometry_type->setObjectName("combo_geometry_type");

        gridLayout->addWidget(combo_geometry_type, 0, 1, 1, 1);


        gridLayout_2->addWidget(group_geometry, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);


        horizontalLayout->addWidget(controls);

        canvas = new QOpenGLWidget(widget);
        canvas->setObjectName("canvas");

        horizontalLayout->addWidget(canvas);

        Window->setCentralWidget(widget);
        QWidget::setTabOrder(combo_geometry_type, edit_geometry_width);
        QWidget::setTabOrder(edit_geometry_width, edit_geometry_height);
        QWidget::setTabOrder(edit_geometry_height, edit_geometry_radius);
        QWidget::setTabOrder(edit_geometry_radius, edit_mesh_width);
        QWidget::setTabOrder(edit_mesh_width, edit_mesh_height);
        QWidget::setTabOrder(edit_mesh_height, edit_mesh_radius);
        QWidget::setTabOrder(edit_mesh_radius, edit_mesh_angle);

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "Plates", nullptr));
        group_loads->setTitle(QCoreApplication::translate("Window", "Loads", nullptr));
        group_mesh->setTitle(QCoreApplication::translate("Window", "Mesh", nullptr));
        label_mesh_width->setText(QCoreApplication::translate("Window", "Width:", nullptr));
        label_mesh_radius->setText(QCoreApplication::translate("Window", "Radius:", nullptr));
        label_mesh_height->setText(QCoreApplication::translate("Window", "Height:", nullptr));
        label_mesh_angle->setText(QCoreApplication::translate("Window", "Angle:", nullptr));
        group_geometry->setTitle(QCoreApplication::translate("Window", "Geometry", nullptr));
        label_geometry_height->setText(QCoreApplication::translate("Window", "Height:", nullptr));
        label_geometry_radius->setText(QCoreApplication::translate("Window", "Radius:", nullptr));
        label_geometry_width->setText(QCoreApplication::translate("Window", "Width:", nullptr));
        label_geometry_type->setText(QCoreApplication::translate("Window", "Type:", nullptr));
        combo_geometry_type->setItemText(0, QCoreApplication::translate("Window", "Circle", nullptr));
        combo_geometry_type->setItemText(1, QCoreApplication::translate("Window", "Rectangle", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WINDOW_H
