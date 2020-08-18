#ifndef CONFIGOBJECT_H
#define CONFIGOBJECT_H

#include "defs.h"

class ConfigObject :public QObject
{
    Q_OBJECT

public:
    explicit ConfigObject(QObject *parent = 0);

    ~ConfigObject ();

public slots:
    Q_INVOKABLE QStringList getColorValues (void) const;
    Q_INVOKABLE QStringList getColorAliases (void) const;
    Q_INVOKABLE QString getBackgroundColor (void) const;
    Q_INVOKABLE QString getDisabledColor (void) const;
    Q_INVOKABLE QString getWinIntermissionColor (void) const;
    Q_INVOKABLE QString getLoseIntermissionColor (void) const;
    Q_INVOKABLE bool getUseAnimation (void) const;
    Q_INVOKABLE int getWindowWidth (void) const;
    Q_INVOKABLE int getWindowHeight (void) const;
    Q_INVOKABLE int getNumTries (void) const;

    Q_INVOKABLE void setDefaultColorsEnglish (void);
//    Q_INVOKABLE void setDefaultColorsGerman (void);
//    Q_INVOKABLE void setDefaultColorsFrench (void);
//    Q_INVOKABLE void setDefaultColorsDutch (void);
//    Q_INVOKABLE void setDefaultColorsItalian (void);
//    Q_INVOKABLE void setDefaultColorsSpanish (void);
//    Q_INVOKABLE void setDefaultColorsPortuguese (void);
    Q_INVOKABLE void setDefaultColorsRussian (void);

    Q_INVOKABLE void setFirstSetColorsEnglish (void);
    Q_INVOKABLE void setFirstSetColorsGerman (void);
    Q_INVOKABLE void setFirstSetColorsFrench (void);
    Q_INVOKABLE void setFirstSetColorsDutch (void);
    Q_INVOKABLE void setFirstSetColorsItalian (void);
    Q_INVOKABLE void setFirstSetColorsSpanish (void);
    Q_INVOKABLE void setFirstSetColorsPortuguese (void);
    Q_INVOKABLE void setFirstSetColorsRussian (void);

    Q_INVOKABLE QStringList listColorSets (void) const;
    Q_INVOKABLE void chooseColorSet (const QString & set);
    Q_INVOKABLE QStringListModel * getColorsetsModel (void);

public:
    Q_PROPERTY (QStringList colorValues READ getColorValues NOTIFY colorValuesChanged)
    Q_PROPERTY (QStringList colorAliases READ getColorAliases NOTIFY colorAliasesChanged)
    Q_PROPERTY (QString backgroundColor READ getBackgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY (QString disabledColor READ getDisabledColor NOTIFY disabledColorChanged)
    Q_PROPERTY (QString winIntermissionColor READ getWinIntermissionColor NOTIFY winIntermissionColorChanged)
    Q_PROPERTY (QString loseIntermissionColor READ getLoseIntermissionColor NOTIFY loseIntermissionColorChanged)
    Q_PROPERTY (bool useAnimation READ getUseAnimation)
    Q_PROPERTY (int windowWidth READ getWindowWidth NOTIFY windowWidthChanged)
    Q_PROPERTY (int windowHeight READ getWindowHeight NOTIFY windowHeightChanged)
    Q_PROPERTY (int numTries READ getNumTries NOTIFY numTriesChanged)

signals:
    void colorValuesChanged (void);
    void colorAliasesChanged (void);
    void backgroundColorChanged (void);
    void disabledColorChanged (void);
    void winIntermissionColorChanged (void);
    void loseIntermissionColorChanged (void);
    void windowWidthChanged (void);
    void windowHeightChanged (void);
    void numTriesChanged (void);

    void colorsetsModelChanged (void);

private:
    void initDefault (void);
    void setDefaultBackgroundColors (void);
    void setFirstSetBackgroundColors (void);

private:
    QStringList colorValues;
    QStringList colorAliases;
    QString backgroundColor;
    QString disabledColor;
    QString winIntermissionColor;
    QString loseIntermissionColor;
    bool useAnimation;
    int windowWidth;
    int windowHeight;
    int numTries;

    QStringListModel * colorsetsModel;
};

#endif // CONFIGOBJECT_H
