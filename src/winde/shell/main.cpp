#include <QApplication>
#include <QCommandLineParser>
#include <KAboutData>
#include <KLocalizedString>
#include "windeshell.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    KLocalizedString::setApplicationDomain("winde");
    
    KAboutData aboutData(
        QStringLiteral("winde"),
        i18n("WinDE"),
        QStringLiteral("0.1"),
        i18n("Windows-like Desktop Environment"),
        KAboutLicense::GPL_V3,
        i18n("(c) 2024 WinDE Team"),
        QString(),
        QStringLiteral("https://github.com/yourusername/WinDE"),
        QStringLiteral("your@email.com")
    );
    
    KAboutData::setApplicationData(aboutData);
    
    QCommandLineParser parser;
    aboutData.setupCommandLine(&parser);
    parser.process(app);
    aboutData.processCommandLine(&parser);
    
    // Create and initialize the shell
    WinDEShell shell;
    shell.initialize();
    
    return app.exec();
} 