#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("SignalLab");

    auto *layout = new QVBoxLayout(&window);

    QLabel *label = new QLabel("Idle");
    QPushButton *button = new QPushButton("Start");

    layout->addWidget(label);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [&](){
        label->setText("Button pressed");
    });

    window.resize(300,150);
    window.show();

    return app.exec();
}
