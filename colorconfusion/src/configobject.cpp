#include "configobject.h"

ConfigObject::ConfigObject(QObject * parent):
    QObject (parent)
{
    initDefault ();

    QSettings prefs (QDir::homePath () + QString ("/.colorconfusion/config.ini"), QSettings::IniFormat);

    prefs.beginGroup ("Options");
    {
        int count;

        count = prefs.beginReadArray ("ColorValues");
        {
            if (count == 6) {
                for (int i = 0; i < count; i++) {
                    prefs.setArrayIndex (i);
                    colorValues.replace (i, prefs.value ("Name", colorValues.at (i)).toString ());
                }
            } else {
                qWarning ("Config file does not contain exactly six color names, using defaults");
            }
        }
        prefs.endArray ();

        count = prefs.beginReadArray ("ColorAliases");
        {
            if (count == 6) {
                for (int i = 0; i < count; i++) {
                    prefs.setArrayIndex (i);
                    colorAliases.replace (i, prefs.value ("Name", colorAliases.at (i)).toString ());
                }
            } else {
                qWarning ("Config file does not contain exactly six color names, using defaults");
            }
        }
        prefs.endArray ();

        backgroundColor = prefs.value ("BackgroundColor", backgroundColor).toString ();
        disabledColor = prefs.value ("DisabledColor", disabledColor).toString ();
        winIntermissionColor = prefs.value ("SuccessfulIntermissionTextColor", winIntermissionColor).toString ();
        loseIntermissionColor = prefs.value ("FailedIntermissionTextColor", loseIntermissionColor).toString ();
        useAnimation = (bool) prefs.value ("Animation", QVariant (useAnimation ? 1 : 0)).toInt ();
        windowWidth = prefs.value ("WindowWidth", windowWidth).toInt ();
        windowHeight = prefs.value ("WindowHeight", windowHeight).toInt ();
        numTries = prefs.value ("NumTries", numTries).toInt ();
    }
    prefs.endGroup ();
}

ConfigObject::~ConfigObject ()
{
    QSettings prefs (QDir::homePath () + QString ("/.colorconfusion/config.ini"), QSettings::IniFormat);

    prefs.beginGroup ("Options");
    {
        prefs.beginWriteArray ("ColorValues", colorValues.count ());
        {
            for (int i = 0; i < colorValues.count (); i++) {
                prefs.setArrayIndex (i);
                prefs.setValue ("Name", colorValues.at (i));
            }
        }
        prefs.endArray ();

        prefs.beginWriteArray ("ColorAliases", colorAliases.count ());
        {
            for (int i = 0; i < colorAliases.count (); i++) {
                prefs.setArrayIndex (i);
                prefs.setValue ("Name", colorAliases.at (i));
            }
        }
        prefs.endArray ();

        prefs.setValue ("BackgroundColor", backgroundColor);
        prefs.setValue ("DisabledColor", disabledColor);
        prefs.setValue ("SuccessfulIntermissionTextColor", winIntermissionColor);
        prefs.setValue ("FailedIntermissionTextColor", loseIntermissionColor);
        prefs.setValue ("Animation", QVariant (useAnimation ? 1 : 0));
        prefs.setValue ("WindowWidth", windowWidth);
        prefs.setValue ("WindowHeight", windowHeight);
        prefs.setValue ("NumTries", numTries);
    }
    prefs.endGroup ();
    prefs.sync ();
}

QStringList ConfigObject::getColorValues (void) const
{
    return (colorValues);
}

QStringList ConfigObject::getColorAliases (void) const
{
    return (colorAliases);
}

QString ConfigObject::getBackgroundColor (void) const
{
    return (backgroundColor);
}

QString ConfigObject::getDisabledColor (void) const
{
    return (disabledColor);
}

QString ConfigObject::getWinIntermissionColor (void) const
{
    return (winIntermissionColor);
}

QString ConfigObject::getLoseIntermissionColor (void) const
{
    return (loseIntermissionColor);
}

bool ConfigObject::getUseAnimation (void) const
{
    return (useAnimation);
}

int ConfigObject::getWindowWidth (void) const
{
    return (windowWidth);
}

int ConfigObject::getWindowHeight (void) const
{
    return (windowHeight);
}

int ConfigObject::getNumTries (void) const
{
    return (numTries);
}

void ConfigObject::setDefaultColorsEnglish (void)
{
    colorValues = QStringList ()
            << "Red"
            << "Blue"
            << "Green"
            << "Purple"
            << "Black"
            << "Orange";
    colorAliases = QStringList ()
            << "Red"
            << "Blue"
            << "Green"
            << "Purple"
            << "Black"
            << "Orange";

    setDefaultBackgroundColors ();
}

void ConfigObject::setDefaultColorsRussian (void)
{
    colorValues = QStringList ()
            << "Red"
            << "Blue"
            << "Green"
            << "Purple"
            << "Black"
            << "Orange";
    colorAliases = QStringList ()
            << QString::fromUtf8 ("Красный")
            << QString::fromUtf8 ("Синий")
            << QString::fromUtf8 ("Зеленый")
            << QString::fromUtf8 ("Фиолетовый")
            << QString::fromUtf8 ("Черный")
            << QString::fromUtf8 ("Оранжевый");

    setDefaultBackgroundColors ();
}

void ConfigObject::setFirstSetColorsEnglish (void)
{
    colorValues = QStringList ()
            << "Red"
            << "Blue"
            << "LightGreen"
            << "Yellow"
            << "Black"
            << "White";
    colorAliases = QStringList ()
            << "Red"
            << "Blue"
            << "Green"
            << "Yellow"
            << "Black"
            << "White";

    setFirstSetBackgroundColors ();
}

void ConfigObject::setFirstSetColorsGerman (void)
{
    colorValues = QStringList ()
            << "Red"
            << "Blue"
            << "LightGreen"
            << "Yellow"
            << "Black"
            << "White";
    colorAliases = QStringList ()
            << "Rot"
            << "Blau"
            << "Gruene"
            << "Gelb"
            << "Schwarz"
            << "Weiss";

    setFirstSetBackgroundColors ();
}

void ConfigObject::setFirstSetColorsFrench (void)
{
    colorValues = QStringList ()
            << "Red"
            << "Blue"
            << "LightGreen"
            << "Yellow"
            << "Black"
            << "White";
    colorAliases = QStringList ()
            << "Rouge"
            << "Bleu"
            << "Vert"
            << "Jaune"
            << "Noir"
            << "Blanc";

    setFirstSetBackgroundColors ();
}

void ConfigObject::setFirstSetColorsDutch (void)
{
    colorValues = QStringList ()
            << "Red"
            << "Blue"
            << "LightGreen"
            << "Yellow"
            << "Black"
            << "White";
    colorAliases = QStringList ()
            << "Rood"
            << "Blauw"
            << "Groen"
            << "Geel"
            << "Zwart"
            << "Wit";

    setFirstSetBackgroundColors ();
}

void ConfigObject::setFirstSetColorsItalian (void)
{
    colorValues = QStringList ()
            << "Red"
            << "Blue"
            << "LightGreen"
            << "Yellow"
            << "Black"
            << "White";
    colorAliases = QStringList ()
            << "Rosso"
            << "Blu"
            << "Verde"
            << "Giallo"
            << "Nero"
            << "Bianco";

    setFirstSetBackgroundColors ();
}

void ConfigObject::setFirstSetColorsSpanish (void)
{
    colorValues = QStringList ()
            << "Red"
            << "Blue"
            << "LightGreen"
            << "Yellow"
            << "Black"
            << "White";
    colorAliases = QStringList ()
            << "Rojo"
            << "Azul"
            << "Verde"
            << "Amarillo"
            << "Negro"
            << "Blanco";

    setFirstSetBackgroundColors ();
}

void ConfigObject::setFirstSetColorsPortuguese (void)
{
    colorValues = QStringList ()
            << "Red"
            << "Blue"
            << "LightGreen"
            << "Yellow"
            << "Black"
            << "White";
    colorAliases = QStringList ()
            << "Vermelho"
            << "Azul"
            << "Verde"
            << "Amarelo"
            << "Preto"
            << "Branco";

    setFirstSetBackgroundColors ();
}

void ConfigObject::setFirstSetColorsRussian (void)
{
    colorValues = QStringList ()
            << "Red"
            << "Blue"
            << "LightGreen"
            << "Yellow"
            << "Black"
            << "White";
    colorAliases = QStringList ()
            << QString::fromUtf8 ("Красный")
            << QString::fromUtf8 ("Синий")
            << QString::fromUtf8 ("Зеленый")
            << QString::fromUtf8 ("Желтый")
            << QString::fromUtf8 ("Черный")
            << QString::fromUtf8 ("Белый");

    setFirstSetBackgroundColors ();
}

QStringList ConfigObject::listColorSets (void) const
{
    return (QStringList ()
            << "Default colors/English"
            << "Default colors/Russian"
            << "First extra color set/English"
            << "First extra color set/German"
            << "First extra color set/French"
            << "First extra color set/Dutch"
            << "First extra color set/Italian"
            << "First extra color set/Spanish"
            << "First extra color set/Portuguese"
            << "First extra color set/Russian"
            << "Cancel"
            );
}

void ConfigObject::chooseColorSet (const QString &set)
{
    if (set == QString ("Default colors/English")) {
        setDefaultColorsEnglish ();
    } else if (set == QString ("Default colors/Russian")) {
        setDefaultColorsRussian ();
    } else if (set == QString ("First extra color set/English")) {
        setFirstSetColorsEnglish ();
    } else if (set == QString ("First extra color set/German")) {
        setFirstSetColorsGerman ();
    } else if (set == QString ("First extra color set/French")) {
        setFirstSetColorsFrench ();
    } else if (set == QString ("First extra color set/Dutch")) {
        setFirstSetColorsDutch ();
    } else if (set == QString ("First extra color set/Italian")) {
        setFirstSetColorsItalian ();
    } else if (set == QString ("First extra color set/Spanish")) {
        setFirstSetColorsSpanish ();
    } else if (set == QString ("First extra color set/Portuguese")) {
        setFirstSetColorsPortuguese ();
    } else if (set == QString ("First extra color set/Russian")) {
        setFirstSetColorsRussian ();
    }

    emit backgroundColorChanged ();
    emit disabledColorChanged ();
    emit colorValuesChanged ();
    emit colorAliasesChanged ();
    emit winIntermissionColorChanged ();
    emit loseIntermissionColorChanged ();
}

QStringListModel * ConfigObject::getColorsetsModel (void)
{
    if (!colorsetsModel) {
        colorsetsModel = new QStringListModel (listColorSets (), this);

        connect (colorsetsModel, SIGNAL (dataChanged ()), this, SIGNAL (colorsetsModelChanged ()));
    }

    return (colorsetsModel);
}

void ConfigObject::initDefault (void)
{
    colorValues = QStringList () << "Red" << "Blue" << "Green" << "Purple" << "Black" << "Orange";
    colorAliases = QStringList () << "Red" << "Blue" << "Green" << "Purple" << "Black" << "Orange";
    backgroundColor = QString ("Lightgray");
    disabledColor = QString ("Darkgray");
    winIntermissionColor = QString ("Green");
    loseIntermissionColor = QString ("Red");
    useAnimation = true;
    windowWidth = 640;
    windowHeight = 480;
    numTries = 20;
}

void ConfigObject::setDefaultBackgroundColors (void)
{
    backgroundColor = QString ("Lightgray");
    disabledColor = QString ("Darkgray");
    winIntermissionColor = QString ("Green");
    loseIntermissionColor = QString ("Red");
}

void ConfigObject::setFirstSetBackgroundColors (void)
{
    backgroundColor = QString ("Darkgray");
    disabledColor = QString ("Lightgray");
    winIntermissionColor = QString ("Lightgreen");
    loseIntermissionColor = QString ("Red");
}
