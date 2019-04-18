#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "interactmembervariable.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<InteractMemberVariable>("myTest.interactMemberVariable",1,0,"InteractMemberVariable"); // 在qml中注册类

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
