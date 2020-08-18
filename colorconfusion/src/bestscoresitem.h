#ifndef BESTSCORESITEM_H
#define BESTSCORESITEM_H

#include "defs.h"

class BestScoresItem
{
public:
    BestScoresItem (void);
    BestScoresItem (const QDateTime & datetime, int elapsedtime);
    BestScoresItem (const QString & timestamp_string, const QString & score_string);
    BestScoresItem (const BestScoresItem & src);

    ~BestScoresItem ();

public:
    unsigned int elapsedTime (void) const;

    QDateTime dateTime (void) const;
    QString elapsedTimeString (void) const;
    QString dateTimeString (void) const;

public:
    const BestScoresItem & operator= (const BestScoresItem & src);

private:
    QDateTime timestamp;
    unsigned int elapsed_time;
};

#endif // BESTSCORESITEM_H
