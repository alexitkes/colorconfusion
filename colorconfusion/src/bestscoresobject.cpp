#include "bestscoresobject.h"

BestScoresObject::BestScoresObject (QObject *parent):
    QObject (parent),
    bsItems ()
{
    QSettings prefs (QDir::homePath () + QString ("/.colorconfusion/config.ini"), QSettings::IniFormat);

    prefs.beginGroup ("BestScores");
    {
        int count = prefs.beginReadArray ("Items");
        {
            for (int i = 0; i < count; i++) {
                prefs.setArrayIndex (i);

                BestScoresItem item (prefs.value ("Timestamp").toString (), prefs.value ("Score").toString ());

                addScore (item.elapsedTime (), item.dateTime ());
            }
        }
        prefs.endArray ();
    }
    prefs.endGroup ();
}

BestScoresObject::~BestScoresObject ()
{
    QSettings prefs (QDir::homePath () + QString ("/.colorconfusion/config.ini"), QSettings::IniFormat);

    prefs.beginGroup ("BestScores");
    {
        prefs.beginWriteArray ("Items", bsItems.count ());
        {
            for (int i = 0; i < bsItems.count (); i++) {
                BestScoresItem item = bsItems.at (i);
                prefs.setArrayIndex (i);
                prefs.setValue ("Timestamp", item.dateTimeString ());
                prefs.setValue ("Score", item.elapsedTimeString ());
            }
        }
        prefs.endArray ();
    }
    prefs.endGroup ();
    prefs.sync ();
}

void BestScoresObject::addScore (unsigned int elapsed_time, const QDateTime &dt)
{
    QDateTime new_dt = dt;
    int i;

    if (dt.isNull ()) {
        new_dt = QDateTime::currentDateTime ();
    }

    BestScoresItem new_item (new_dt, elapsed_time);

    for (i = 0; i < bsItems.count () && elapsed_time > bsItems.at (i).elapsedTime (); i++);
    bsItems.insert (i, new_item);
}

int BestScoresObject::getScoresCount (void) const
{
    return (bsItems.count ());
}

QString BestScoresObject::getDateTimeValueAt (int index) const
{
    return (bsItems.at (index).dateTimeString ());
}

QString BestScoresObject::getScoreValueAt (int index) const
{
    return (bsItems.at (index).elapsedTimeString ());
}
