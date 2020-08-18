#include "defs.h"
#include "bestscoresobject.h"
#include "configobject.h"

int main (int argc, char *argv[])
{
    QApplication app (argc, argv);
    QDeclarativeView view;

    BestScoresObject * bs = new BestScoresObject (&view);
    ConfigObject * config = new ConfigObject (&view);

    QObject::connect (view.engine (), SIGNAL (quit ()), qApp, SLOT (quit ()));

    view.rootContext ()->setContextProperty ("bestScores", bs);
    view.rootContext ()->setContextProperty ("config", config);

    view.setWindowTitle (QString ("ColorConfusion v%1").arg (VERSION_STRING));
    view.setSource (QUrl ("qrc:/qml/ColorConfusion.qml"));
    view.show ();

    return app.exec();
}
