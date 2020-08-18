#ifndef BESTSCORESOBJECT_H
#define BESTSCORESOBJECT_H

#include "defs.h"
#include "bestscoresitem.h"

class BestScoresObject: public QObject
{
    Q_OBJECT

public:
    explicit BestScoresObject (QObject * parent);

    ~BestScoresObject ();

public slots:
    Q_INVOKABLE void addScore (unsigned int elapsed_time, const QDateTime & dt = QDateTime ());

    Q_INVOKABLE int getScoresCount (void) const;

    Q_INVOKABLE QString getDateTimeValueAt (int index) const;
    Q_INVOKABLE QString getScoreValueAt (int index) const;

private:
    QList<BestScoresItem> bsItems;
};

#endif // BESTSCORESOBJECT_H
