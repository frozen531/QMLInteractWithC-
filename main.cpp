#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQuickView> // QQuickView
#include <QQmlContext>  // rootContext()

#include "interactmembervariable.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    /************************************/
    QQuickView view;
    InteractMemberVariable interactMemberVariable;   // 提前建立类对象
    view.rootContext()->setContextProperty("interactMemberVariable", &interactMemberVariable); // 设置上下文属性
    view.setSource(QUrl(QStringLiteral("qrc:///main.qml")));
    view.show();
    /************************************/

    return app.exec();
}
