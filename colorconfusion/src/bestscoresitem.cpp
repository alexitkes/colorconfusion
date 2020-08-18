#include "bestscoresitem.h"

BestScoresItem::BestScoresItem (void):
    timestamp ()
{
    elapsed_time = (unsigned int) (-1);
}

BestScoresItem::BestScoresItem (const QDateTime &datetime, int elapsedtime):
    timestamp (datetime)
{
    elapsed_time = elapsedtime;
}

BestScoresItem::BestScoresItem (const BestScoresItem &src):
    timestamp (src.timestamp)
{
    elapsed_time = src.elapsed_time;
}

BestScoresItem::BestScoresItem (const QString &timestamp_string, const QString &score_string):
    timestamp ()
{
    QStringList parts = score_string.split (":");

    if (parts.count () != 3) {
        qFatal ("Invalid high score encountered");

        exit (1);
    }

    elapsed_time = parts.at (0).toInt () * 6000 + parts.at (1).toInt () * 100 + parts.at (2).toInt ();
    timestamp = QDateTime::fromString (timestamp_string, "yyyy-MM-dd/hh:mm:ss");
}

BestScoresItem::~BestScoresItem ()
{
}

unsigned int BestScoresItem::elapsedTime (void) const
{
    return (elapsed_time);
}

QDateTime BestScoresItem::dateTime (void) const
{
    return (timestamp);
}

QString BestScoresItem::elapsedTimeString (void) const
{
    int min = elapsed_time / 6000;
    int sec = (elapsed_time % 6000) / 100;
    int hund = elapsed_time % 100;

    return (QString ("%1:%2:%3").arg (QString ("%1").arg (min, 2, 10, QChar ('0'))).arg (QString ("%1").arg (sec, 2, 10, QChar ('0'))).arg (QString ("%1").arg (hund, 2, 10, QChar ('0'))));
}

QString BestScoresItem::dateTimeString (void) const
{
    return (timestamp.toString ("yyyy-MM-dd/hh:mm:ss"));
}

const BestScoresItem & BestScoresItem::operator= (const BestScoresItem & src)
{
    timestamp = src.timestamp;
    elapsed_time = src.elapsed_time;

    return (*this);
}
