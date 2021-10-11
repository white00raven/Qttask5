#include <QApplication>
#include <QQmlApplicationEngine>
#include "tablemodel.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
qmlRegisterType<Tablemodel>("TableModel",1,0,"Tablemodel");
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
